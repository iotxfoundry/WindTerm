#include "SshSession.h"

#include <QDir>
#include <QElapsedTimer>
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QMutex>
#include <QSocketNotifier>
#include <QThread>
#include <QWaitCondition>
#include <QtGlobal>
#include <dlfcn.h>

#include <type_traits>

#include "Assets.h"
#include "JsonText.h"
#include "filer/FileSystemItem.h"

#include <QDateTime>
#include <QHash>
#include <QPointer>

#include <cstddef>

// ---------------------------------------------------------------------------
// libssh 运行库绑定（无开发头文件的折衷，风格同 widgets/KingIcons.h）
//
// 符号已用 `nm -D` 核对（原版 /opt/WindTerm_2.7.0/lib/libssh.so.4 与系统
// /lib/x86_64-linux-gnu/libssh.so.4）：全部为 T 导出的纯 C 符号，无 C++ 修饰名。
// 枚举值取自 libssh 0.10 的 ssh_options_e / ssh_known_hosts_e / ssh_auth_e，
// 硬编码并在下方注明。
// ---------------------------------------------------------------------------
namespace {

// ssh_options_e（libssh 0.10 头文件实证 api.libssh.org/stable）: HOST=0, PORT=1,
// PORT_STR=2, FD=3, USER=4, SSH_DIR=5, IDENTITY=6, ADD_IDENTITY=7, KNOWNHOSTS=8
constexpr int kOptHost = 0;
constexpr int kOptPort = 1;
constexpr int kOptUser = 4;

// C1（0020:4007）：known_hosts 选项号按运行时探测（原版修补版实证 8=KNOWNHOSTS 可用；
// 系统库 probe 亦为 8——任务清单"系统用 2"经 probe 证伪：opt(2,path)=-1 被拒。
// 探测序 8→2，两库通吃）
constexpr int kOptKnownHostsPrimary = 8;
constexpr int kOptKnownHostsFallback = 2;

// enum ssh_known_hosts_e（libssh 0.10 头文件实证）：ERROR=-2, NOT_FOUND=-1,
// UNKNOWN=0, OK=1, CHANGED=2, OTHER=3
constexpr int kKnownError = -2;
constexpr int kKnownNotFound = -1;
constexpr int kKnownUnknown = 0;
constexpr int kKnownOk = 1;
constexpr int kKnownChanged = 2;
constexpr int kKnownOther = 3;

constexpr int kOk = 0;
constexpr int kAuthSuccess = 0;

// 指纹链：ssh_get_server_publickey + ssh_get_publickey_hash(SSH_PUBLICKEY_HASH_MD5=0)
// → ssh_get_hexa("aa:bb:.." 冒号 hex, malloc)→ssh_string_free_char 释放。
// 签名以 libssh 0.10 头文件为准（api.libssh.org：hash 为 unsigned char**+size_t 出参）；
// 本机实测 type=0 → MD5 16 字节，与 `ssh-keygen -E md5 -lf` 一致。
constexpr int kHashMd5 = 0; // enum ssh_publickey_hash_type: MD5=0, SHA1=1, SHA256=2

struct Api
{
    void *(*newSession)();
    void (*freeSession)(void *);
    int (*optionsSet)(void *, int, const void *);
    int (*connectSession)(void *);
    int (*isConnected)(void *);
    // C1 双名探测（原版实证旧名）：ssh_is_server_known（0020:3979 FUN_006286a4）/
    // ssh_session_is_known_server（新 API），whichever resolves
    int (*knownServer)(void *);
    // C1 双名探测：ssh_write_knownhost（0020:4223 FUN_00628a24）/
    // ssh_session_update_known_hosts（新 API）
    int (*writeKnownHosts)(void *);
    // C3 认证队列符号
    int (*userauthList)(void *, const char *);
    int (*userauthNone)(void *, const char *);       // 命名 op 预置（0020:4035）
    int (*userauthPassword)(void *, const char *, const char *);
    int (*userauthAgent)(void *, const char *);      // 命名 op 预置（0020:4035 FUN_006274d6）
    int (*userauthPublickey)(void *, const char *, void *);
    int (*userauthTryPublickey)(void *, const char *, void *);
    int (*userauthKbdint)(void *, const char *, void *);
    int (*kbdintGetnprompts)(void *);
    const char *(*kbdintGetprompt)(void *, unsigned int, char *);
    int (*kbdintSetanswer)(void *, unsigned int, const char *);
    int (*pkiImportPrivkeyFile)(const char *, const char *, void *, void *, void **);
    int (*pkiExportPrivkeyToPubkey)(const void *, void **);
    // C6：ssh_agent_is_running（0020:2737 FUN_00627646，原版 4.8.1+；系统 0.10.6 无此
    // 导出符号，可选绑定缺失降级）；ssh_channel_request_auth_agent（0020:3168）
    int (*agentIsRunning)(void *);
    int (*channelRequestAuthAgent)(void *);
    // C5：显式阻塞模式（原版握手期 set_blocking(0) 属 socket 回调模型，重建直连保持阻塞）
    int (*setBlocking)(void *, int);
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
    // host key 指纹 + known_hosts 写入
    int (*getServerPublickey)(void *, void **);
    int (*getPublickeyHash)(const void *, int, unsigned char **, size_t *);
    void (*cleanPubkeyHash)(unsigned char **);
    char *(*getHexa)(const unsigned char *, size_t);
    void (*keyFree)(void *);
    void (*stringFreeChar)(char *);
    // P5 sftp 绑定表（0x627efc/0x866372/0x8638f0）：旧名优先探测——原版自带 4.8 修补版有
    // sftp_new2/sftp_init2（0020:3448 实证调用序 sftp_new2(session)→sftp_init2(h,0)），
    // 系统 0.10 无旧名回退 sftp_new/sftp_init
    void *(*sftpNew)(void *);
    int (*sftpInit1)(void *);      // sftp_init
    int (*sftpInit2)(void *, int); // sftp_init2
    void *(*sftpOpendir)(void *, const char *);
    void *(*sftpReaddir)(void *, void *);
    int (*sftpClosedir)(void *);
    int (*sftpDirEof)(void *);
    void (*sftpAttributesFree)(void *);
    void (*sftpFree)(void *);
    // P6 sftp 文件 IO（SftpTransfer 后台分块读写;阻塞版——原版 async 泵挂账见 SftpTransfer）
    void *(*sftpOpen)(void *, const char *, int, int); // (sftp,path,flags,mode)
    int (*sftpClose)(void *);
    int (*sftpRead)(void *, void *, size_t);
    int (*sftpWrite)(void *, const void *, size_t);
    int (*sftpSeek64)(void *, quint64); // 续传定位（首版断点续传挂账,绑定先行）
    void *(*sftpStat)(void *, const char *);
    bool hasSftp;
    bool hasSftpFile; // 文件 IO 绑定完整性（传输可用性）
    bool loaded;
    bool hasFingerprint;
    bool hasAgentIsRunning;
    bool fromOriginalLib; // C1：原版自带修补版加载成功（纯 C 库可加载）
    int knownHostsOpt = -1; // C1 运行时探测（8 优先，回退 2），-1=探测失败不设
};

Api &api()
{
    static Api a = [] {
        Api r{};
        // C1 差异#1：dlopen 顺序——原版自带修补版优先 → 回退系统 libssh.so.4。
        // 原版库 NEEDED libcrypto.so.1.1 随原版 lib 目录分发，先静默预载补齐依赖
        // （已加载则 no-op；LD_LIBRARY_PATH 方式需污染全局，此处按需预载）
        const char *kOriginalLib = "/opt/WindTerm_2.7.0/lib/libssh.so.4";
        dlopen("/opt/WindTerm_2.7.0/lib/libcrypto.so.1.1", RTLD_LAZY | RTLD_LOCAL);
        void *h = dlopen(kOriginalLib, RTLD_LAZY | RTLD_LOCAL);
        const char *loadedFrom = kOriginalLib;
        r.fromOriginalLib = h != nullptr;
        if (!h) {
            h = dlopen("libssh.so.4", RTLD_LAZY | RTLD_LOCAL);
            loadedFrom = "libssh.so.4 (system)";
        }
        if (!h)
            return r;

        auto bind = [h](auto &fn, const char *name) {
            using Fn = std::decay_t<decltype(fn)>;
            fn = reinterpret_cast<Fn>(dlsym(h, name));
        };
        const char *knownServerName = "ssh_is_server_known"; // 原版实证 0020:3979
        const char *writeKnownName = "ssh_write_knownhost";  // 原版实证 0020:4223
        bind(r.newSession, "ssh_new");
        bind(r.freeSession, "ssh_free");
        bind(r.optionsSet, "ssh_options_set");
        bind(r.connectSession, "ssh_connect");
        bind(r.isConnected, "ssh_is_connected");
        bind(r.knownServer, knownServerName);
        if (!r.knownServer) { // 旧名缺失→新 API 双名探测
            knownServerName = "ssh_session_is_known_server";
            bind(r.knownServer, knownServerName);
        }
        bind(r.writeKnownHosts, writeKnownName);
        if (!r.writeKnownHosts) {
            writeKnownName = "ssh_session_update_known_hosts";
            bind(r.writeKnownHosts, writeKnownName);
        }
        bind(r.userauthList, "ssh_userauth_list");
        bind(r.userauthNone, "ssh_userauth_none");
        bind(r.userauthPassword, "ssh_userauth_password");
        bind(r.userauthAgent, "ssh_userauth_agent");
        bind(r.userauthPublickey, "ssh_userauth_publickey");
        bind(r.userauthTryPublickey, "ssh_userauth_try_publickey");
        bind(r.userauthKbdint, "ssh_userauth_kbdint");
        bind(r.kbdintGetnprompts, "ssh_userauth_kbdint_getnprompts");
        bind(r.kbdintGetprompt, "ssh_userauth_kbdint_getprompt");
        bind(r.kbdintSetanswer, "ssh_userauth_kbdint_setanswer");
        bind(r.pkiImportPrivkeyFile, "ssh_pki_import_privkey_file");
        bind(r.pkiExportPrivkeyToPubkey, "ssh_pki_export_privkey_to_pubkey");
        bind(r.agentIsRunning, "ssh_agent_is_running");
        bind(r.channelRequestAuthAgent, "ssh_channel_request_auth_agent");
        bind(r.setBlocking, "ssh_set_blocking");
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
        bind(r.getServerPublickey, "ssh_get_server_publickey");
        bind(r.getPublickeyHash, "ssh_get_publickey_hash");
        bind(r.cleanPubkeyHash, "ssh_clean_pubkey_hash");
        bind(r.getHexa, "ssh_get_hexa");
        bind(r.keyFree, "ssh_key_free");
        bind(r.stringFreeChar, "ssh_string_free_char");

        // P5 sftp 绑定（旧名优先探测,原版 libssh 旧名语义）
        bind(r.sftpNew, "sftp_new2");
        if (!r.sftpNew)
            bind(r.sftpNew, "sftp_new");
        bind(r.sftpInit2, "sftp_init2");
        bind(r.sftpInit1, "sftp_init");
        bind(r.sftpOpendir, "sftp_opendir");
        bind(r.sftpReaddir, "sftp_readdir");
        bind(r.sftpClosedir, "sftp_closedir");
        bind(r.sftpDirEof, "sftp_dir_eof");
        bind(r.sftpAttributesFree, "sftp_attributes_free");
        bind(r.sftpFree, "sftp_free");
        r.hasSftp = r.sftpNew && (r.sftpInit1 || r.sftpInit2) && r.sftpOpendir
                    && r.sftpReaddir && r.sftpClosedir && r.sftpAttributesFree && r.sftpFree;
        if (!r.hasSftp)
            qWarning("SshSession: sftp 绑定不完整,Filer 远程浏览不可用");
        // P6 文件 IO 绑定（两库均 T 导出,nm 核对;open flags 语义见 SftpTransfer）
        bind(r.sftpOpen, "sftp_open");
        bind(r.sftpClose, "sftp_close");
        bind(r.sftpRead, "sftp_read");
        bind(r.sftpWrite, "sftp_write");
        bind(r.sftpSeek64, "sftp_seek64");
        bind(r.sftpStat, "sftp_stat");
        r.hasSftpFile = r.sftpOpen && r.sftpClose && r.sftpRead && r.sftpWrite && r.sftpStat;
        if (!r.hasSftpFile)
            qWarning("SshSession: sftp 文件 IO 绑定不完整,传输不可用");

        r.loaded = r.newSession && r.freeSession && r.optionsSet && r.connectSession
                   && r.isConnected && r.knownServer && r.userauthPassword && r.channelNew
                   && r.channelOpenSession && r.channelRequestPtySize && r.channelRequestShell
                   && r.channelReadNonblocking && r.channelWrite && r.channelClose
                   && r.channelSendEof && r.channelFree && r.getFd && r.getError
                   && r.disconnectSession;
        r.hasFingerprint = r.getServerPublickey && r.getPublickeyHash && r.cleanPubkeyHash
                           && r.getHexa && r.keyFree && r.stringFreeChar;
        r.hasAgentIsRunning = r.agentIsRunning != nullptr;
        if (!r.hasFingerprint)
            qWarning("SshSession: 指纹 API 缺失，host key 提示只含主机名");
        if (!r.writeKnownHosts)
            qWarning("SshSession: known_hosts 写入符号缺失，接受后不写文件");
        if (!r.hasAgentIsRunning)
            qWarning("SshSession: ssh_agent_is_running 缺失（系统 libssh 无此导出），agent 检测跳过");

        // C1：KNOWNHOSTS 选项号运行时探测（一次性 throwaway session，8 优先）
        if (r.newSession && r.optionsSet && r.freeSession) {
            if (void *s = r.newSession()) {
                if (r.optionsSet(s, kOptKnownHostsPrimary, "/tmp") == kOk)
                    r.knownHostsOpt = kOptKnownHostsPrimary;
                else if (r.optionsSet(s, kOptKnownHostsFallback, "/tmp") == kOk)
                    r.knownHostsOpt = kOptKnownHostsFallback;
                r.freeSession(s);
            }
        }
        // C1：实际解析名一次性日志
        qWarning("SshSession: libssh loaded from %s; known_server=%s write_knownhost=%s "
                 "KNOWNHOSTS opt=%d",
                 r.fromOriginalLib ? loadedFrom : loadedFrom, knownServerName, writeKnownName,
                 r.knownHostsOpt);
        return r;
    }();
    return a;
}

// ---------------------------------------------------------------------------
// C2（差异#7，FUN_00806382 0025:41618 + s_known_hosts_62aac6 0020:5922）
// ---------------------------------------------------------------------------

// profileRoot 同构拼（WindConfig::profileDir 私有；WindConfig.cpp:38 同款拼法）
inline QString sshProfileRoot()
{
    return QDir::homePath() + QStringLiteral("/.wind/profiles/default.v10");
}

inline QString sshKnownHostsPath(const QString &host, int port)
{
    // shortcut: session id 派生规则未逆,用 host_port 近似,FUN_00806382 逆明后校准
    const QString sessionId = QStringLiteral("%1_%2").arg(host).arg(port).toLower();
    // KNOWNHOSTS 选项吃的是 ssh-dir 语义：写侧在给定路径下再拼 "known_hosts"
    // （原版修补版与系统 0.10 实测一致，"%d/known_hosts" 字符串实证）。故传
    // <profileRoot>/ssh/<id>，落盘文件=<...>/ssh/<id>/known_hosts
    const QString dir = sshProfileRoot() + QStringLiteral("/ssh/") + sessionId;
    QDir().mkpath(dir); // 原版 profile 体系 cfg_ensureProfileDir mkdir -p
    return dir + QStringLiteral("/known_hosts");
}

// C3 配置读取：session.config(uiconfigs) 默认全 true（原版 s_ssh_authPassword_7d5a36 等
// 0025:4561 经 s_ssh_identityFilePath_7d5538 0025:4363 的 session→global 回退链）。
// 骨架按 user.config→wind.config 顺序取，键缺失→默认 true/空。
// shortcut: autoLogin JSON 结构未接（session.autoLogin 是加密 blob，骨架无解密面），
// 按开关+start() 密码驱动；原版 per-method autoLogin 对象逆明后接入
QVariant sshSetting(const QString &key)
{
    const QStringList files = {sshProfileRoot() + QStringLiteral("/user.config"),
                               Assets::dir() + QStringLiteral("/config/wind.config")};
    for (const QString &f : files) {
        QFile file(f);
        if (!file.open(QIODevice::ReadOnly))
            continue;
        QByteArray data = file.readAll();
        if (data.startsWith("\xEF\xBB\xBF"))
            data.remove(0, 3);
        const QJsonObject root =
            QJsonDocument::fromJson(JsonText::stripLineComments(data)).object();
        if (root.contains(key))
            return root.value(key).toVariant();
    }
    return {};
}

inline bool sshBoolSetting(const char *key)
{
    const QVariant v = sshSetting(QString::fromLatin1(key));
    return v.isValid() ? v.toBool() : true; // uiconfigs/session.config 默认
}

// C4（差异#1 后半，s_known_hosts_62aac6 0020:5922）：known_hosts 逐行 split，第 2 列
// （key 段）前 == hostKey 的行删除后回写（原版 QFile resize(0)+write 同构）
bool removeKnownHostsLine(const QString &path, const QByteArray &key)
{
    QFile f(path);
    if (!f.open(QIODevice::ReadOnly))
        return false; // 原版：打不开 → -1
    QList<QByteArray> lines = f.readAll().split('\n');
    f.close();
    QList<QByteArray> kept;
    kept.reserve(lines.size());
    for (const QByteArray &line : lines) {
        const int sp = line.indexOf(' ');
        if (sp > 0 && line.left(sp) == key)
            continue; // key 段（第 2 列前）匹配 → 删行
        kept.append(line);
    }
    if (!f.open(QIODevice::WriteOnly | QIODevice::Truncate))
        return false;
    f.write(kept.join('\n'));
    return true;
}

} // namespace

// ---------------------------------------------------------------------------
// 连接期共享状态：worker 线程写 libssh 句柄，主线程 onWorkerEstablished 接管。
// host key 回执走 mutex+QWaitCondition（worker 无事件循环推进该段，见头文件线程模型）。
// QSharedPointer 跨线程共享：worker 与 SshSession 两侧各自持引用，任一先消失
// （close/析构/线程结束）都不悬垂。
// ---------------------------------------------------------------------------
struct SshConnectState
{
    QMutex mutex;
    QWaitCondition cond;
    bool aborted = false;  // close() 置位：worker 下个检查点自清
    bool answered = false; // host key 对话框回执
    bool accepted = false;
    void *session = nullptr; // handoff 前归 worker；established 消费后归主线程
    void *channel = nullptr;
    void *sftp = nullptr; // P5：worker 线程建的 sftp_session（established 消费后主线程只读值）
};

// ---------------------------------------------------------------------------
// P5：sftp 句柄 → SshSession 注册表（sftpList 后台线程反向找到宿主,同步暂停其
// socket 泵；libssh session 非线程安全）。主线程 established 注册/teardown 注销
// ---------------------------------------------------------------------------
namespace {
QMutex g_sftpMapMutex;
QHash<void *, QPointer<SshSession>> g_sftpMap;
} // namespace

// ---------------------------------------------------------------------------
// C3（差异#2/#3，0027:0086597e/0086adc4）：认证队列 op 模型（SshAuthOperator 等效）。
// 命名 op（Agent/None，0020:4035）预置不入队，供失败重试 UI（原版 GUI 分片，未接挂账）。
// 实测注：userauth_list 需先一轮 none 探测（原版 SshBridge 0020:4035 即 none 探测——
// server 在 none 拒绝里回吐可继续方法集），connectFlow 内先 none 再 list。
// ---------------------------------------------------------------------------
struct SshAuthConfig
{
    bool authPassword = true;
    bool authPublicKey = true;
    bool authKeyboardInteractive = true;
    QString identityPath; // ssh.identityFilePath（0025:4363）
};

struct AuthOp
{
    enum Kind
    {
        Password,
        PublicKeyTry,  // 两步试探（0027:008689b7 → 0020:4092 FUN_006287f6）
        PublicKeyReal, // 真签名（0020:2636 FUN_0062752c）
        KbdInt,        // 0020:5369 kbdint 循环
        Agent,         // 命名 op 预置，不入队
        None           // 命名 op 预置，不入队
    };
    Kind kind;
    QByteArray password;      // Password op 用
    QByteArray identityPath;  // publickey 两 op 用
    QByteArray identityPass;  // 私钥口令（autoLogin 未接，恒空挂账）
};

// ---------------------------------------------------------------------------
// C5（差异#5，0027:00864972 thread_worker_start）：worker 工作对象（对齐原版 SshSocket
// moveToThread 模式），内部持 libssh 会话跑同步 connect 链；结果经 queued 信号回主线程。
// 原版 QTcpSocket 先行(代理,0086c7b2)，重建无代理配置面直连，代理支持挂账；
// 原版握手期 set_blocking(0) 属 socket 回调模型，重建直连保持阻塞。
// ---------------------------------------------------------------------------
class SshWorker : public QObject
{
    Q_OBJECT

public:
    SshWorker(QString host, int port, QString user, QString password, QByteArray knownHostsPath,
              SshAuthConfig auth, int rows, int columns, QSharedPointer<SshConnectState> state)
        : m_host(std::move(host))
        , m_port(port)
        , m_user(std::move(user))
        , m_password(std::move(password))
        , m_knownHostsPath(std::move(knownHostsPath))
        , m_auth(std::move(auth))
        , m_rows(rows)
        , m_columns(columns)
        , m_state(std::move(state))
    {
    }

public slots:
    void connectFlow();
    int runAuthOp(const AuthOp &op, void *session);

signals:
    void hostKeyNeeded(const QString &host, const QString &fingerprint, bool changed);
    void established();
    void failedSignal(const QString &reason);

private:
    QString fetchFingerprint(void *session) const;
    QByteArray hostPortKey() const;
    void emitFailure(const QString &why, void *session, void *channel);

    QString m_host;
    int m_port;
    QString m_user;
    QString m_password;
    QByteArray m_knownHostsPath;
    SshAuthConfig m_auth;
    int m_rows;
    int m_columns;
    QSharedPointer<SshConnectState> m_state;
};

QString SshWorker::fetchFingerprint(void *session) const
{
    QString fingerprint;
    if (!api().hasFingerprint)
        return fingerprint;
    void *key = nullptr;
    unsigned char *hash = nullptr;
    size_t hashLen = 0;
    if (api().getServerPublickey(session, &key) == kOk && key) {
        if (api().getPublickeyHash(key, kHashMd5, &hash, &hashLen) == kOk && hash) {
            char *hex = api().getHexa(hash, hashLen); // "aa:bb:.." 冒号串
            if (hex) {
                fingerprint = QString::fromUtf8(hex);
                api().stringFreeChar(hex);
            }
            api().cleanPubkeyHash(&hash);
        }
        api().keyFree(key);
    }
    return fingerprint;
}

// C4：known_hosts 行键（FUN_0086410a 0027:0086410a：port==22 ? host : "host:port"）
QByteArray SshWorker::hostPortKey() const
{
    const QByteArray hostUtf8 = m_host.toUtf8();
    return m_port == 22 ? hostUtf8 : hostUtf8 + ':' + QByteArray::number(m_port);
}

void SshWorker::emitFailure(const QString &why, void *session, void *channel)
{
    if (channel)
        api().channelFree(channel);
    if (session)
        api().freeSession(session);
    if (!m_state->aborted) // 中止路径静默（close 已 emit finished）
        emit failedSignal(why);
}

void SshWorker::connectFlow()
{
    void *session = api().newSession();
    if (!session) {
        emitFailure(QStringLiteral("ssh_new 失败"), nullptr, nullptr);
        return;
    }
    const QByteArray hostUtf8 = m_host.toUtf8();
    const QByteArray userUtf8 = m_user.toUtf8();
    unsigned int portValue = static_cast<unsigned int>(m_port);

    if (api().optionsSet(session, kOptHost, hostUtf8.constData()) != kOk
        || api().optionsSet(session, kOptPort, &portValue) != kOk
        || (!userUtf8.isEmpty()
            && api().optionsSet(session, kOptUser, userUtf8.constData()) != kOk)) {
        emitFailure(QStringLiteral("连接参数设置失败"), session, nullptr);
        return;
    }
    // C2：known_hosts 路径 = <profileRoot>/ssh/<id>/**known_hosts**（作为 ssh-dir 根，
    // 修补版/系统 0.10 写侧均在其下再拼 "known_hosts"，实测两库一致）；目录不存在
    // mkpath（原版 cfg_ensureProfileDir）。KNOWNHOSTS 值是 format 串，含 % 需转义，
    // 路径含 % 的现实概率≈0，挂账：出现时指纹提示错路径
    if (!m_knownHostsPath.isEmpty() && api().knownHostsOpt >= 0
        && api().optionsSet(session, api().knownHostsOpt, m_knownHostsPath.constData()) != kOk) {
        qWarning("SshSession: KNOWNHOSTS 选项设置失败（opt=%d），退回 libssh 默认路径",
                 api().knownHostsOpt);
    }

    // C5：同步 ssh_connect（见类注释差异说明）
    api().setBlocking(session, 1);
    const int cRc = api().connectSession(session);
    if (cRc != kOk || api().isConnected(session) != 1) {
        const char *err = api().getError(session);
        emitFailure(QStringLiteral("Connection failed")
                        + (err && *err ? QStringLiteral(": ") + QString::fromUtf8(err)
                                       : QString()),
                    session, nullptr);
        return;
    }

    // ---- host key 确认（MITM 防护；原版专窗未逆, Qt QMessageBox 等效）----
    const int known = api().knownServer(session);
    if (known != kKnownOk) {
        const QString fingerprint = fetchFingerprint(session);
        const bool changed = (known == kKnownChanged);
        // NOT_FOUND/OTHER 同样走人工确认（原版专窗未逆；OTHER=有他型钥在档，
        // 偏保守按首连处理）。仅 ERROR 直接失败。
        const bool needsUser = changed || known == kKnownUnknown
                               || known == kKnownNotFound || known == kKnownOther;
        if (!needsUser) {
            const char *err = api().getError(session);
            emitFailure(QStringLiteral("Host key check failed")
                            + (err && *err ? QStringLiteral(": ") + QString::fromUtf8(err)
                                           : QString()),
                        session, nullptr);
            return;
        }
        // 请求主线程弹窗（queued → SshSession::onWorkerHostKey → hostKeyUnknown）；
        // worker 无事件循环推进此段，QWaitCondition 等回执。死锁分析：主线程槽
        // （MainWindow 的 hostKeyUnknown 连接）只调 hostKeyAnswer（置答案+wakeAll）
        // 不 join 本线程；本线程阻塞期间主线程事件循环照常转。
        emit hostKeyNeeded(m_host, fingerprint, changed);
        {
            QMutexLocker lock(&m_state->mutex);
            // QWaitCondition 定时醒检 aborted（用户在弹窗前关标签）；总超时 120s
            // 兜底（人读指纹+决策的合理上限；libssh 连接已建立，无 socket 超时护航）
            QElapsedTimer waitTimer;
            waitTimer.start();
            while (!m_state->answered && !m_state->aborted && waitTimer.elapsed() < 120000)
                m_state->cond.wait(&m_state->mutex, 200);
            if (m_state->aborted) {
                emitFailure(QStringLiteral(""), session, nullptr); // 静默：close 已收尾
                return;
            }
            if (!m_state->answered || !m_state->accepted) {
                emitFailure(changed ? QStringLiteral("Host key changed, refusing to connect")
                                    : QStringLiteral("Host key rejected by user"),
                            session, nullptr);
                return;
            }
        }
        // C4（FUN_0086410a 0027:0086410a）：接受 target=1；r 与 target 不同且
        // （target==0 或 r!=0）→先手工删旧指纹行，再 target==1 时 write_knownhost。
        // 删行在 <dir>/known_hosts（写侧落盘文件同位）
        if (known != kKnownUnknown) // r∉{0,1} 才有旧行可删（UNKNOWN 无行）
            removeKnownHostsLine(m_knownHostsPath + QStringLiteral("/known_hosts"),
                                 hostPortKey());
        if (api().writeKnownHosts && api().writeKnownHosts(session) != kOk)
            qWarning("SshSession: known_hosts 写入失败（连接继续）");
    }

    // ---- C3 前置：mask 探测（none 探测轮见 op 模型注释）----
    if (api().userauthNone)
        api().userauthNone(session, nullptr);
    // ---- C3 认证队列（0027:0086597e connect 后入队；白名单序=显示名编码序 0020:5163：
    // &8 Host Based / &4 Public Key / &0x20 Gssapi With Mic / &2 Password /
    // &0x10 Keyboard Interactive。Host Based/Gssapi 仅命名 op，原版
    // s_PasswordEnabled_866e4a 0027:00866e4a 只自动入队以下三者）----
    QVector<AuthOp> ops;
    const int mask = api().userauthList ? api().userauthList(session, nullptr) : 0;
    if ((mask & 4) && m_auth.authPublicKey && !m_auth.identityPath.isEmpty()
        && api().pkiImportPrivkeyFile && api().userauthTryPublickey
        && api().userauthPublickey) {
        AuthOp op{AuthOp::PublicKeyTry};
        op.identityPath = m_auth.identityPath.toUtf8();
        ops.append(op);
        op.kind = AuthOp::PublicKeyReal;
        ops.append(op);
    }
    if ((mask & 2) && m_auth.authPassword && !m_password.isEmpty() && api().userauthPassword) {
        AuthOp op{AuthOp::Password};
        op.password = m_password.toUtf8();
        ops.append(op);
    }
    if ((mask & 0x10) && m_auth.authKeyboardInteractive && api().userauthKbdint)
        ops.append(AuthOp{AuthOp::KbdInt});

    bool authed = false;
    // 队列执行（SshBridge::onAuthResult 00869602 语义）：rc==0 成功；rc&~1==1（1|3）
    // →下一 op；Password rc==1（再次要密码）→失败终止；全部失败→failed
    for (const AuthOp &op : ops) {
        if (m_state->aborted) {
            emitFailure(QStringLiteral(""), session, nullptr);
            return;
        }
        const int rc = runAuthOp(op, session);
        if (op.kind == AuthOp::PublicKeyTry) {
            // 两步试探（0027:008689b7）：try 成功只是"server 认钥"，必须继续 real op
            // 完成签名；try rc==0/1 都推进队列，real 的 rc 才是终局
            continue;
        }
        if (rc == kAuthSuccess) {
            authed = true;
            break;
        }
        if (op.kind == AuthOp::Password && rc == 1)
            break;
    }
    if (!authed) {
        emitFailure(QStringLiteral("Authentication failed"), session, nullptr);
        return;
    }

    // ---- channel/pty/shell 仍归 worker（handoff 前主线程不碰 libssh）----
    void *channel = api().channelNew(session);
    if (!channel || api().channelOpenSession(channel) != kOk) {
        emitFailure(QStringLiteral("Channel open failed"), session, channel);
        return;
    }
    // C6（差异#8，0020:2737/0027:008636ee）：agent 在跑则 channel request auth agent。
    // 修补版 libssh 的 ssh_agent_is_running 依赖 session+0x6a8（agent socket path）
    // 非空——该值不在 ssh_new/SSH_AUTH_SOCK 自动初始化（缺省直接解引用→SIGSEGV，
    // 实测崩溃点 f9ca movzbl (%rsi)）。原版侧经 options_set agent-socket 选项填入
    //（实测 opt=44 写 0x6a8），骨架在连接前设 opt(44, $SSH_AUTH_SOCK)（未设则跳过
    // agent 检测）。shortcut: agent 本地代理转发(0086bc66)属隧道功能,F6 批
    if (api().hasAgentIsRunning) {
        const QByteArray agentSock = qgetenv("SSH_AUTH_SOCK");
        if (!agentSock.isEmpty()) {
            api().optionsSet(session, 44, agentSock.constData()); // agent socket path
            if (api().agentIsRunning(session))
                api().channelRequestAuthAgent(channel);
        }
    }
    if (api().channelRequestPtySize(channel, "xterm", m_columns, m_rows) != kOk) {
        emitFailure(QStringLiteral("PTY request failed"), session, channel);
        return;
    }
    if (api().channelRequestShell(channel) != kOk) {
        emitFailure(QStringLiteral("Shell request failed"), session, channel);
        return;
    }
    const int fd = api().getFd(session);
    if (fd < 0) {
        emitFailure(QStringLiteral("Get socket fd failed"), session, channel);
        return;
    }

    // ---- P5 sftp channel（0x627efc/0x866372/0x8638f0：认证成功后 established 链末尾建;
    // 实证调用序 0020:3448 sftp_new2(session)→sftp_init2(sftp,0)——sftp_new2 内部对 SSH
    // 连接开第二条 channel+sftp subsystem request。失败非致命：原版信号 0 语义=null+统一
    // 文案,established 后主线程 emit sftpReady/sftpFailed）----
    if (api().hasSftp) {
        if (void *sftp = api().sftpNew(session)) {
            const int sRc = api().sftpInit2 ? api().sftpInit2(sftp, 0) : api().sftpInit1(sftp);
            if (sRc == kOk)
                m_state->sftp = sftp;
            else
                api().sftpFree(sftp);
        }
    }

    // handoff：句柄进共享态，established 排主线程；此后 worker 只自然退出
    m_state->session = session;
    m_state->channel = channel;
    emit established();
}

int SshWorker::runAuthOp(const AuthOp &op, void *session)
{
    switch (op.kind) {
    case AuthOp::Password:
        return api().userauthPassword(session, nullptr, op.password.constData());
    case AuthOp::PublicKeyTry:
    case AuthOp::PublicKeyReal: {
        void *priv = nullptr;
        int rc = -1;
        if (api().pkiImportPrivkeyFile(op.identityPath.constData(),
                                       op.identityPass.isEmpty() ? nullptr
                                                                 : op.identityPass.constData(),
                                       nullptr, nullptr, &priv) == kOk
            && priv) {
            if (op.kind == AuthOp::PublicKeyTry) { // export_pubkey→try（试探）
                void *pub = nullptr;
                if (api().pkiExportPrivkeyToPubkey(priv, &pub) == kOk && pub)
                    rc = api().userauthTryPublickey(session, nullptr, pub);
                if (pub)
                    api().keyFree(pub);
            } else { // 真签名（libssh 取私钥签名）
                rc = api().userauthPublickey(session, nullptr, priv);
            }
            api().keyFree(priv);
        }
        return rc;
    }
    case AuthOp::KbdInt: { // rc==3(SSH_AUTH_INFO) 时 getnprompts/getprompt 循环
        int rc = api().userauthKbdint(session, nullptr, nullptr);
        while (rc == 3) {
            const int np = api().kbdintGetnprompts ? api().kbdintGetnprompts(session) : 0;
            for (int i = 0; i < np; ++i) {
                char echo = 0;
                if (api().kbdintGetprompt)
                    api().kbdintGetprompt(session, static_cast<unsigned int>(i), &echo);
                // shortcut: kbdint 答案 UI 未接(原版 GUI 分片缺失),首答案空重入
                if (api().kbdintSetanswer)
                    api().kbdintSetanswer(session, static_cast<unsigned int>(i), "");
            }
            rc = api().userauthKbdint(session, nullptr, nullptr);
        }
        return rc;
    }
    case AuthOp::Agent:
        return api().userauthAgent ? api().userauthAgent(session, nullptr) : -1;
    case AuthOp::None:
        return api().userauthNone ? api().userauthNone(session, nullptr) : -1;
    }
    return -1;
}

// ---------------------------------------------------------------------------
// SshSession：主线程侧。start() 装 worker+thread；I/O notifier drain（0020:4592 数据泵）
// ---------------------------------------------------------------------------
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
    close();
    stopWorkerThread(); // close 已置 aborted，worker 检查点自清后 quit/wait 即返
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

void SshSession::start(const QString &host, int port, const QString &user, const QString &password)
{
    if (!api().loaded) {
        emit output(QStringLiteral("[SSH] libssh.so.4 不可用，无法建立连接\r\n").toUtf8());
        m_finished = true;
        emit finished();
        emit failed(QStringLiteral("libssh.so.4 不可用"));
        return;
    }
    if (m_session || m_state) {
        emit output(QStringLiteral("[SSH] 会话已存在，忽略重复 start()\r\n").toUtf8());
        return;
    }

    m_finished = false;
    m_state = QSharedPointer<SshConnectState>::create();

    // C2：known_hosts 路径 <profileRoot>/ssh/<sessionId 小写>/known_hosts（HOME 为空跳过，
    // 退回 libssh 默认）；目录不存在 mkpath（原版 cfg_ensureProfileDir）
    const QByteArray knownHostsPath = qEnvironmentVariableIsEmpty("HOME")
                                          ? QByteArray()
                                          : QFile::encodeName(sshKnownHostsPath(host, port));

    // C3：认证配置（user.config→wind.config，缺省同 uiconfigs/session.config 全 true）
    SshAuthConfig auth;
    auth.authPassword = sshBoolSetting("ssh.authPassword");
    auth.authPublicKey = sshBoolSetting("ssh.authPublicKey");
    auth.authKeyboardInteractive = sshBoolSetting("ssh.authKeyboardInteractive");
    auth.identityPath = sshSetting(QStringLiteral("ssh.identityFilePath")).toString();

    // C5：worker 对象 moveToThread（0027:00864972）；started→connectFlow 槽在 worker 线程
    // 跑；结果 queued 回主线程（原版 ShellSession 信号 0x80 QueuedConnection 等效）
    m_worker = new SshWorker(host, port, user, password, knownHostsPath, auth, m_rows, m_columns,
                             m_state);
    m_thread = new QThread(this);
    m_worker->moveToThread(m_thread);
    connect(m_thread, &QThread::started, m_worker, &SshWorker::connectFlow);
    connect(m_thread, &QThread::finished, m_worker, &QObject::deleteLater);
    connect(m_worker, &SshWorker::established, this, &SshSession::onWorkerEstablished);
    connect(m_worker, &SshWorker::failedSignal, this, &SshSession::onWorkerFailed);
    connect(m_worker, &SshWorker::hostKeyNeeded, this, &SshSession::onWorkerHostKey);
    m_thread->start();
}

void SshSession::hostKeyAnswer(bool accept)
{
    if (!m_state)
        return;
    QMutexLocker lock(&m_state->mutex);
    m_state->answered = true;
    m_state->accepted = accept;
    m_state->cond.wakeAll();
}

void SshSession::stopWorkerThread()
{
    if (!m_thread)
        return;
    m_thread->quit();
    m_thread->wait(); // worker 槽已终局或被 aborted 唤醒后即返（至多 connect 超时 10s）
    delete m_thread;
    m_thread = nullptr;
    m_worker = nullptr; // finished→deleteLater 已回收
}

void SshSession::onWorkerHostKey(const QString &host, const QString &fingerprint, bool changed)
{
    emit hostKeyUnknown(host, fingerprint, changed); // MainWindow hook → hostKeyAnswer()
}

// 主线程：接管 worker 移交的 libssh 句柄，I/O（notifier）从这一刻起全回主线程
void SshSession::onWorkerEstablished()
{
    QSharedPointer<SshConnectState> state = m_state;
    m_state.clear();
    stopWorkerThread();
    if (!state)
        return;
    if (m_finished) {
        // close() 抢先：worker 已不碰 libssh，本处收编句柄清理
        if (state->session) {
            if (api().loaded) {
                if (api().isConnected(state->session) == 1)
                    api().disconnectSession(state->session);
                api().freeSession(state->session);
            }
            state->session = nullptr;
        }
        if (state->channel) {
            if (api().loaded)
                api().channelFree(state->channel);
            state->channel = nullptr;
        }
        if (state->sftp) {
            if (api().loaded && api().sftpFree)
                api().sftpFree(state->sftp);
            state->sftp = nullptr;
        }
        return;
    }
    m_session = state->session;
    m_channel = state->channel;
    m_sftp = state->sftp;
    m_notifier = new QSocketNotifier(api().getFd(m_session), QSocketNotifier::Read, this);
    connect(m_notifier, &QSocketNotifier::activated, this, &SshSession::readChannel);
    // P5：sftpList 反查注册（后台线程同步暂停泵用）
    if (m_sftp) {
        QMutexLocker lock(&g_sftpMapMutex);
        g_sftpMap.insert(m_sftp, this);
    }
    emit connected();
    // P5 信号 0 语义：成功带句柄/失败 null+统一文案（0x866372/0x8638f0）
    if (m_sftp)
        emit sftpReady();
    else
        emit sftpFailed(QStringLiteral("SFTP failed to allocate. "));
}

void SshSession::onWorkerFailed(const QString &reason)
{
    m_state.clear();
    stopWorkerThread();
    m_finished = true;
    if (!reason.isEmpty())
        emit output(QStringLiteral("[SSH] %1\r\n").arg(reason).toUtf8());
    emit failed(reason);
    emit finished();
}

// P5：主线程槽——关/开 socket 泵（notifier enabled 即可,drain 链不推进）。
// IO 线程 sftpList 入口 invokeMethod(BlockingQueued) 同步等待此处返回后才开始碰 libssh
void SshSession::ioSuspend(bool suspend)
{
    m_ioSuspended = suspend;
    if (m_notifier)
        m_notifier->setEnabled(!suspend);
    // 恢复时补一轮 drain（挂起期间积压的 shell 数据）
    if (!suspend)
        readChannel();
}

// P5（0x8e8d36 SftpFolder 后端语义）：阻塞版列目录,运行于 FileSystemModel 的后台 IO 线程。
// shortcut: 原版 async_readdir 泵(0x8e8d36)未照搬,阻塞 readdir 在独立线程等效;
// opendir 失败→空表（错误分流挂账,sftp_dir_eof 判定未用）。
// 并发护栏：libssh session 非线程安全——入口同步挂起主线程泵,出口恢复
void SshSession::readChannel()
{
    if (m_finished || m_ioSuspended || !m_channel || !m_session)
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
    // 连接期中止：置标志让 worker 在检查点自清（worker 仍持句柄，此处不碰 libssh）
    if (m_state) {
        QMutexLocker lock(&m_state->mutex);
        m_state->aborted = true;
        m_state->cond.wakeAll();
    }
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
    // P5：sftp 先于 channel/session free（sftp_free 关闭自持第二 channel）。
    // shortcut: 在途 sftpList(IO 线程)与 free 的竞态未加锁,取消机制挂账 P6 传输批
    if (m_sftp) {
        {
            QMutexLocker lock(&g_sftpMapMutex);
            g_sftpMap.remove(m_sftp);
        }
        if (api().loaded && api().sftpFree)
            api().sftpFree(m_sftp);
        m_sftp = nullptr;
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
    // 连接期竞态兜底：handoff 已发生（state 有句柄）但主线程放弃时，句柄留在 state——
    // worker 已终局（线程可收）则此处安全收编清理
    if (m_state && m_thread && m_thread->isFinished()) {
        if (m_state->session) {
            if (api().loaded) {
                if (api().isConnected(m_state->session) == 1)
                    api().disconnectSession(m_state->session);
                api().freeSession(m_state->session);
            }
            m_state->session = nullptr;
        }
        if (m_state->channel) {
            if (api().loaded)
                api().channelFree(m_state->channel);
            m_state->channel = nullptr;
        }
        if (m_state->sftp) {
            if (api().loaded && api().sftpFree)
                api().sftpFree(m_state->sftp);
            m_state->sftp = nullptr;
        }
    }
    m_state.clear();
}

// ---------------------------------------------------------------------------
// P5：sftp_attributes_struct 镜像（libssh 4.x 布局,/usr/include/libssh/sftp.h 核对;
// 原版 4.8 修补版与系统 0.10 同布局）。仅取 readdir 所需字段,偏移 static_assert 自证
// ---------------------------------------------------------------------------
namespace {

struct SftpAttrMirror
{
    char *name;                   // +0
    char *longname;               // +8
    uint32_t flags;               // +16
    uint8_t type;                 // +20
    uint64_t size;                // +24
    uint32_t uid;                 // +32
    uint32_t gid;                 // +36
    char *owner;                  // +40
    char *group;                  // +48
    uint32_t permissions;         // +56
    uint64_t atime64;             // +64
    uint32_t atime;               // +72
    uint32_t atime_nseconds;      // +76
    uint64_t createtime;          // +80
    uint32_t createtime_nseconds; // +88
    uint64_t mtime64;             // +96
    uint32_t mtime;               // +104
    uint32_t mtime_nseconds;      // +108
};

static_assert(offsetof(SftpAttrMirror, name) == 0, "sftp_attributes layout");
static_assert(offsetof(SftpAttrMirror, type) == 20, "sftp_attributes layout");
static_assert(offsetof(SftpAttrMirror, size) == 24, "sftp_attributes layout");
static_assert(offsetof(SftpAttrMirror, owner) == 40, "sftp_attributes layout");
static_assert(offsetof(SftpAttrMirror, permissions) == 56, "sftp_attributes layout");
static_assert(offsetof(SftpAttrMirror, mtime) == 104, "sftp_attributes layout");

} // namespace

// P5（0x8e8d36 SftpFolder 后端语义）：阻塞版列目录,运行于 FileSystemModel 的后台 IO 线程。
// shortcut: 原版 async_readdir 泵(0x8e8d36)未照搬,阻塞 readdir 在独立线程等效;
// opendir 失败→空表（错误分流挂账,sftp_dir_eof 判定未用）。
// 并发护栏：libssh session 非线程安全——入口同步挂起主线程泵,出口恢复
QVector<FileSystemItem *> SshSession::sftpList(void *sftpHandle, const QString &path,
                                               bool showHidden)
{
    QVector<FileSystemItem *> items;
    Api &a = api();
    if (!sftpHandle || !a.hasSftp)
        return items;
    // 反查宿主：同步请求主线程挂泵（BlockingQueued——主线程事件循环需在转,
    // 测试 waitFor/正常 UI 场景事件循环常开）
    QPointer<SshSession> host;
    {
        QMutexLocker lock(&g_sftpMapMutex);
        host = g_sftpMap.value(sftpHandle);
    }
    const bool guarded = host && host->thread() != QThread::currentThread();
    if (guarded)
        QMetaObject::invokeMethod(host, "ioSuspend", Qt::BlockingQueuedConnection,
                                  Q_ARG(bool, true));
    const QByteArray pathUtf8 = path.toUtf8();
    void *dir = a.sftpOpendir(sftpHandle, pathUtf8.constData());
    if (!dir) {
        if (guarded)
            QMetaObject::invokeMethod(host, "ioSuspend", Qt::BlockingQueuedConnection,
                                      Q_ARG(bool, false));
        return items;
    }
    for (;;) {
        auto *attr = static_cast<SftpAttrMirror *>(a.sftpReaddir(sftpHandle, dir));
        if (!attr)
            break; // EOF（错误态不分流）
        // 深拷字符串字段再 free（sftpAttributesFree 释放整块含字符串）
        QByteArray name8 = attr->name ? QByteArray(attr->name) : QByteArray();
        QByteArray owner8 = attr->owner ? QByteArray(attr->owner) : QByteArray();
        QByteArray group8 = attr->group ? QByteArray(attr->group) : QByteArray();
        const uint8_t type = attr->type;
        const qint64 size = static_cast<qint64>(attr->size);
        const uint32_t mtime = attr->mtime;
        const uint32_t permissions = attr->permissions;
        a.sftpAttributesFree(attr);
        const QString name = QString::fromUtf8(name8);
        if (name.isEmpty() || name == QLatin1String(".") || name == QLatin1String(".."))
            continue;
        if (!showHidden && name.startsWith(QLatin1Char('.')))
            continue;
        auto *item = new FileSystemItem;
        // SSH_FILEXFER_TYPE（libssh sftp.h 实证）：1=REGULAR 2=DIRECTORY 3=SYMLINK
        item->type = type == 2 ? FileSystemItem::Folder
                     : type == 3 ? FileSystemItem::Link
                                 : FileSystemItem::File;
        item->name = name;
        // 链接 size=-1（0x634ef0 语义）
        item->size = item->type == FileSystemItem::Link ? -1
                     : item->type == FileSystemItem::Folder ? 0
                                                            : size;
        item->mtime = QDateTime::fromSecsSinceEpoch(mtime);
        const QChar typeChar = item->type == FileSystemItem::Folder ? QLatin1Char('d')
                               : item->type == FileSystemItem::Link ? QLatin1Char('l')
                                                                    : QLatin1Char('-');
        item->permissions = fileModeString(typeChar, permissions & 0777u);
        item->owner = QString::fromUtf8(owner8);
        item->group = QString::fromUtf8(group8);
        items.append(item);
    }
    a.sftpClosedir(dir);
    if (guarded)
        QMetaObject::invokeMethod(host, "ioSuspend", Qt::BlockingQueuedConnection,
                                  Q_ARG(bool, false));
    return items;
}

// P6（SftpTransfer 后端）：sftp_stat 远端大小。attr 布局见上方 SftpAttrMirror（size@+24,
// static_assert 自证）。挂泵护栏同 sftpList——后台 IO 线程与主线程泵互斥（R38）
qint64 SshSession::sftpFileSize(void *sftpHandle, const QString &path)
{
    Api &a = api();
    if (!sftpHandle || !a.hasSftp || !a.sftpStat)
        return -1;
    QPointer<SshSession> host;
    {
        QMutexLocker lock(&g_sftpMapMutex);
        host = g_sftpMap.value(sftpHandle);
    }
    const bool guarded = host && host->thread() != QThread::currentThread();
    if (guarded)
        QMetaObject::invokeMethod(host, "ioSuspend", Qt::BlockingQueuedConnection,
                                  Q_ARG(bool, true));
    const QByteArray pathUtf8 = path.toUtf8();
    qint64 size = -1;
    if (auto *attr = static_cast<SftpAttrMirror *>(a.sftpStat(sftpHandle, pathUtf8.constData()))) {
        size = static_cast<qint64>(attr->size);
        a.sftpAttributesFree(attr);
    }
    if (guarded)
        QMetaObject::invokeMethod(host, "ioSuspend", Qt::BlockingQueuedConnection,
                                  Q_ARG(bool, false));
    return size;
}

bool SshSession::sftpFileIoAvailable()
{
    return api().hasSftpFile;
}

const SshSession::SftpFileApi &SshSession::fileApi()
{
    static const SftpFileApi table = { api().sftpOpen, api().sftpClose, api().sftpRead,
                                       api().sftpWrite };
    return table;
}

QObject *SshSession::hostForSftp(void *sftp)
{
    QMutexLocker lock(&g_sftpMapMutex);
    return g_sftpMap.value(sftp).data();
}

#include "SshSession.moc"
