#include "SshSession.h"

#include <QSocketNotifier>
#include <QtGlobal>
#include <dlfcn.h>

#include <type_traits>

// ---------------------------------------------------------------------------
// libssh 运行库绑定（无开发头文件的折衷，风格同 widgets/KingIcons.h）
//
// 符号已用 `nm -D /lib/x86_64-linux-gnu/libssh.so.4` 核对：全部为 T 导出的
// 纯 C 符号（@@LIBSSH_4_5_0），无 C++ 修饰名，也不需要隐含 this 的成员 ABI 处理。
// 枚举值取自 libssh 0.10 的 ssh_options_e / ssh_known_hosts_e，硬编码并在下方注明。
// ---------------------------------------------------------------------------
namespace {

// enum ssh_options_e（libssh 0.10）: HOST=0, PORT=1, PORT_STR=2, FD=3, USER=4
constexpr int kOptHost = 0;
constexpr int kOptPort = 1;
constexpr int kOptUser = 4;

// enum ssh_known_hosts_e: KNOWN_OK=0, KNOWN_CHANGED=1, NOT_KNOWN=4, ERROR=-1
constexpr int kKnownOk = 0;
constexpr int kKnownChanged = 1;

constexpr int kOk = 0;
constexpr int kAuthSuccess = 0;

struct Api
{
    void *(*newSession)();
    void (*freeSession)(void *);
    int (*optionsSet)(void *, int, const void *);
    int (*connectSession)(void *);
    int (*isConnected)(void *);
    int (*knownServer)(void *);
    int (*userauthPassword)(void *, const char *, const char *);
    void *(*channelNew)(void *);
    int (*channelOpenSession)(void *);
    int (*channelRequestPtySize)(void *, const char *, int, int);
    int (*channelRequestShell)(void *);
    int (*channelReadNonblocking)(void *, void *, unsigned int, int);
    int (*channelWrite)(void *, const void *, unsigned int);
    int (*channelClose)(void *);
    int (*channelSendEof)(void *);
    void (*channelFree)(void *);
    int (*getFd)(void *);
    const char *(*getError)(void *);
    void (*disconnectSession)(void *);
    bool loaded;
};

Api &api()
{
    static Api a = [] {
        Api r{};
        void *h = dlopen("libssh.so.4", RTLD_LAZY | RTLD_LOCAL);
        if (!h)
            h = dlopen("/opt/WindTerm_2.7.0/lib/libssh.so.4", RTLD_LAZY | RTLD_LOCAL);
        if (!h)
            return r;

        auto bind = [h](auto &fn, const char *name) {
            using Fn = std::decay_t<decltype(fn)>;
            fn = reinterpret_cast<Fn>(dlsym(h, name));
        };
        bind(r.newSession, "ssh_new");
        bind(r.freeSession, "ssh_free");
        bind(r.optionsSet, "ssh_options_set");
        bind(r.connectSession, "ssh_connect");
        bind(r.isConnected, "ssh_is_connected");
        bind(r.knownServer, "ssh_session_is_known_server");
        bind(r.userauthPassword, "ssh_userauth_password");
        bind(r.channelNew, "ssh_channel_new");
        bind(r.channelOpenSession, "ssh_channel_open_session");
        bind(r.channelRequestPtySize, "ssh_channel_request_pty_size");
        bind(r.channelRequestShell, "ssh_channel_request_shell");
        bind(r.channelReadNonblocking, "ssh_channel_read_nonblocking");
        bind(r.channelWrite, "ssh_channel_write");
        bind(r.channelClose, "ssh_channel_close");
        bind(r.channelSendEof, "ssh_channel_send_eof");
        bind(r.channelFree, "ssh_channel_free");
        bind(r.getFd, "ssh_get_fd");
        bind(r.getError, "ssh_get_error");
        bind(r.disconnectSession, "ssh_disconnect");

        r.loaded = r.newSession && r.freeSession && r.optionsSet && r.connectSession
                   && r.isConnected && r.knownServer && r.userauthPassword && r.channelNew
                   && r.channelOpenSession && r.channelRequestPtySize && r.channelRequestShell
                   && r.channelReadNonblocking && r.channelWrite && r.channelClose
                   && r.channelSendEof && r.channelFree && r.getFd && r.getError
                   && r.disconnectSession;
        return r;
    }();
    return a;
}

} // namespace

SshSession::SshSession(int rows, int columns, QObject *parent)
    : Session(parent)
    , m_session(nullptr)
    , m_channel(nullptr)
    , m_notifier(nullptr)
    , m_rows(rows)
    , m_columns(columns)
    , m_finished(false)
{
}

SshSession::~SshSession()
{
    teardown();
}

bool SshSession::symbolsAvailable()
{
    return api().loaded;
}

bool SshSession::isConnected() const
{
    return m_session && api().loaded && api().isConnected(m_session) == 1 && !m_finished;
}

bool SshSession::start(const QString &host, const QString &user, const QString &password, int port)
{
    if (!api().loaded) {
        emit output(QStringLiteral("[SSH] libssh.so.4 不可用，无法建立连接\r\n").toUtf8());
        m_finished = true;
        emit finished();
        return false;
    }
    if (m_session) {
        emit output(QStringLiteral("[SSH] 会话已存在，忽略重复 start()\r\n").toUtf8());
        return false;
    }

    m_finished = false;
    m_session = api().newSession();
    if (!m_session) {
        emit output(QStringLiteral("[SSH] ssh_new 失败\r\n").toUtf8());
        m_finished = true;
        emit finished();
        return false;
    }

    const QByteArray hostUtf8 = host.toUtf8();
    const QByteArray userUtf8 = user.toUtf8();
    unsigned int portValue = static_cast<unsigned int>(port);

    if (api().optionsSet(m_session, kOptHost, hostUtf8.constData()) != kOk
        || api().optionsSet(m_session, kOptPort, &portValue) != kOk
        || (!userUtf8.isEmpty() && api().optionsSet(m_session, kOptUser, userUtf8.constData()) != kOk)) {
        fail(QStringLiteral("连接参数设置失败"));
        return false;
    }

    // shortcut: 同步阻塞连接（本机/局域网通常 <5s 返回）。需要可取消或慢速链路时改为
    //           QThread/QtConcurrent 里做 connect+auth，主线程只接收信号。
    if (api().connectSession(m_session) != kOk || api().isConnected(m_session) != 1) {
        fail(QStringLiteral("Connection failed"));
        return false;
    }

    // 主机密钥：已变更则拒绝（防 MITM）；首次连接仅提示，不写 known_hosts。
    const int known = api().knownServer(m_session);
    if (known == kKnownChanged) {
        fail(QStringLiteral("Host key changed, refusing to connect"));
        return false;
    }
    if (known != kKnownOk) {
        emit output(QStringLiteral("[SSH] 警告: 主机密钥未在 known_hosts 中验证（首次连接）\r\n").toUtf8());
    }

    const QByteArray passUtf8 = password.toUtf8();
    if (api().userauthPassword(m_session, nullptr, passUtf8.constData()) != kAuthSuccess) {
        fail(QStringLiteral("Authentication failed"));
        return false;
    }

    m_channel = api().channelNew(m_session);
    if (!m_channel) {
        fail(QStringLiteral("Channel creation failed"));
        return false;
    }
    if (api().channelOpenSession(m_channel) != kOk) {
        fail(QStringLiteral("Channel open failed"));
        return false;
    }
    if (api().channelRequestPtySize(m_channel, "xterm", m_columns, m_rows) != kOk) {
        fail(QStringLiteral("PTY request failed"));
        return false;
    }
    if (api().channelRequestShell(m_channel) != kOk) {
        fail(QStringLiteral("Shell request failed"));
        return false;
    }

    const int fd = api().getFd(m_session);
    if (fd < 0) {
        fail(QStringLiteral("Get socket fd failed"));
        return false;
    }
    m_notifier = new QSocketNotifier(fd, QSocketNotifier::Read, this);
    connect(m_notifier, &QSocketNotifier::activated, this, &SshSession::readChannel);
    return true;
}

void SshSession::readChannel()
{
    if (m_finished || !m_channel || !m_session)
        return;

    char buffer[8192];
    for (;;) {
        const int n = api().channelReadNonblocking(m_channel, buffer, sizeof(buffer), 0);
        if (n > 0) {
            emit output(QByteArray(buffer, n));
            continue;
        }
        if (n == 0)
            return; // 暂无数据
        emit output(QStringLiteral("[SSH] 连接已断开\r\n").toUtf8());
        close();
        return;
    }
}

void SshSession::write(const QByteArray &data)
{
    if (m_finished || !m_channel || data.isEmpty())
        return;
    if (api().channelWrite(m_channel, data.constData(), static_cast<unsigned int>(data.size())) < 0)
        close();
}

void SshSession::resize(int rows, int columns)
{
    m_rows = rows;
    m_columns = columns;
    if (m_channel && !m_finished)
        api().channelRequestPtySize(m_channel, nullptr, m_columns, m_rows);
}

void SshSession::close()
{
    if (m_finished)
        return;
    teardown();
    m_finished = true;
    emit finished();
}

void SshSession::fail(const QString &stage)
{
    QString message = stage;
    const char *err = m_session ? api().getError(m_session) : nullptr;
    if (err && *err)
        message += QStringLiteral(": ") + QString::fromUtf8(err);
    emit output(QStringLiteral("[SSH] %1\r\n").arg(message).toUtf8());
    teardown();
    m_finished = true;
    emit finished();
}

void SshSession::teardown()
{
    if (m_notifier) {
        m_notifier->setEnabled(false);
        m_notifier->deleteLater();
        m_notifier = nullptr;
    }
    if (m_channel) {
        if (api().loaded) {
            api().channelSendEof(m_channel);
            api().channelClose(m_channel);
            api().channelFree(m_channel);
        }
        m_channel = nullptr;
    }
    if (m_session) {
        if (api().loaded) {
            if (api().isConnected(m_session) == 1)
                api().disconnectSession(m_session);
            api().freeSession(m_session);
        }
        m_session = nullptr;
    }
}
