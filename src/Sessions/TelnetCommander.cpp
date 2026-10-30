#include "TelnetCommander.h"
#include "Screen.h"

#include <QFile>
#include <QJsonDocument>
#include <QJsonParseError>
#include <QJsonObject>

// telnet.protocol 装载:refs(IAC/SE/SB/WILL/WONT/DO/DONT)+ match
// (命名组 NegotiateOption/NegotiateSubOption/IgnoreWrongIAC)。
// (?&NAME) 引用 textual 替换为 (?:ref) 后编译;subject = Latin-1
// 字节流(0-255 ↔ U+0000-U+00FF 无损)。
TelnetCommander::TelnetCommander(QObject *parent)
	: SuperCommander(parent)
{
}

bool TelnetCommander::loadProtocol(const QString &path)
{
	QFile f(path);
	if (!f.open(QIODevice::ReadOnly))
		return false;
	const QByteArray raw = f.readAll();
	const QJsonDocument doc = QJsonDocument::fromJson(
	    QString::fromLatin1(raw)
	        .remove(QRegularExpression(QStringLiteral("^\\s*//.*$"),
	                                   QRegularExpression::MultilineOption))
	        .toLatin1(), &m_parseError);
	if (!doc.isObject()) {
		qWarning("telnet.protocol parse: %s (offset %d)",
		         qPrintable(m_parseError.errorString()),
		         m_parseError.offset);
		return false;
	}
	const QJsonObject proto = doc.object()
	                              .value(QLatin1String("protocol"))
	                              .toObject();
	const QJsonObject refs = proto.value(QLatin1String("refs")).toObject();
	QString match = proto.value(QLatin1String("match")).toString();
	if (match.isEmpty())
		return false;
	// (?x) 剥离 + 全字面空白移除:Qt/PCRE2-16 的 EXTENDED 与
	// PCRE2-8/PCRE2-16(python 验证)语义差(批 27:重命名后的
	// SubOption 分支因字面空格不匹配)——本文件空白均为排版填充
	match.remove(QLatin1String("(?x)"));
	match.remove(QChar(' '));
	match.remove(QChar('\t'));
	match.remove(QChar('\n'));
	match.remove(QChar('\r'));
	for (auto it = refs.begin(); it != refs.end(); ++it) {
		const QString token =
		    QStringLiteral("(?&") + it.key() + QLatin1Char(')');
		match.replace(token,
		    QStringLiteral("(?:") + it.value().toString() + QLatin1Char(')'));
		// refs = PCRE \xHH 形式 → 解码为状态机字节
		const QString re = it.value().toString();
		if (re.startsWith(QLatin1String("\\x")) && re.size() == 4) {
			const int b = re.mid(2).toInt(nullptr, 16);
			if (it.key() == QLatin1String("IAC"))
				m_refIAC = b;
			else if (it.key() == QLatin1String("SB"))
				m_refSB = b;
			else if (it.key() == QLatin1String("SE"))
				m_refSE = b;
		}
	}
	// PCRE2 默认禁重复命名组:command/option 跨分支复用 → 首现保名,
	// 后现加 __N(派发按分支选名,见 feed)
	static const QRegularExpression dupRe(
	    QStringLiteral("\\(\\?<([A-Za-z_][A-Za-z0-9_]*)>"));
	QHash<QString, int> seen;
	QString fixed;
	QRegularExpressionMatchIterator it = dupRe.globalMatch(match);
	int last = 0;
	while (it.hasNext()) {
		const QRegularExpressionMatch dm = it.next();
		fixed += match.mid(last, dm.capturedStart(1 - 1) - last);
		last = dm.capturedEnd(0);
		const QString name = dm.captured(1);
		const int n = ++seen[name];
		if (n == 1) {
			fixed += dm.captured(0);
			continue;
		}
		fixed += QStringLiteral("(?<") + name + QStringLiteral("_")
		         + QString::number(n) + QStringLiteral(">");
	}
	fixed += match.mid(last);
	m_re = QRegularExpression(fixed);
	fprintf(stderr, "[telnet-fixed] %s\n", qPrintable(fixed));
	if (!m_re.isValid())
		qWarning("telnet.protocol regex invalid @%d: %s",
		         m_re.patternErrorOffset(),
		         qPrintable(m_re.errorString()));
	return m_re.isValid();
}

// 协商响应表 —— 实验锚 /tmp/opencode/telnet_capture.json(原版
// 2.7.0 客户端真实字节,2026-10-30 捕获):
//   init(连接主动协商) = WILL NAWS(31) WILL TTYPE(24) DO ECHO(1)
//                          DO SGA(3) WILL SGA(3)
//   DO 24 → 重发 init;DO 31 → SB 31 0 <cols> <rows> SE;
//   SB 24,1 → SB 24,0 "xterm-256color" SE;DO 39 → WONT 39;
//   WILL 1/3 → 不应(已 DO);其余 DO/WILL → 默认拒绝(39 实证同型)
namespace {
const QByteArray kInitNegotiation =
    QByteArrayLiteral("\xff\xfb\x1f\xff\xfb\x18\xff\xfd\x01\xff\xfd"
                      "\x03\xff\xfb\x03");
constexpr unsigned char kOptEcho = 1;
constexpr unsigned char kOptSga = 3;
constexpr unsigned char kOptTtype = 24;
constexpr unsigned char kOptNaws = 31;
const char *const kTermType = "xterm-256color";   // SB TTYPE 应答实证
} // namespace

QByteArray TelnetCommander::initialNegotiation() const
{
	return kInitNegotiation;
}

QByteArray TelnetCommander::feed(const QByteArray &in)
{
	// 确定性 IAC 状态机(telnet 本质;PCRE2-Qt PARTIAL 语义与
	// python/PCRE2-8 差异深坑,regex 路线弃用——配置仍装载留证)
	QByteArray pending = m_pending + in;
	m_pending.clear();
	fprintf(stderr, "[feed-in] %s (sz=%d)\n",
	        qPrintable(QString::fromLatin1(pending.toHex())), pending.size());
	QByteArray data;   // 非协议字节(数据通道直通)
	int i = 0;
	while (i < pending.size()) {
		const unsigned char b = (unsigned char)pending[i];
		fprintf(stderr, "[sm] i=%d b=%02x (sz=%d)\n", i, b,
		        pending.size());
		if (b != m_refIAC) {
			data += b;
			i += 1;
			continue;
		}
		if (i + 1 >= pending.size()) {
			m_pending = pending.mid(i);   // 半截 IAC:留待下次
			break;
		}
		const unsigned char cmd = (unsigned char)pending[i + 1];
		if (cmd == m_refIAC) {           // IAC IAC = 字面 0xFF 数据
			data += (char)m_refIAC;
			i += 2;
			continue;
		}
		if (cmd == m_refSB) {            // SB … IAC SE 子协商
			const int sb = i + 2;
			int se = -1;
			for (int j = sb; j + 1 < pending.size(); ++j)
				if ((unsigned char)pending[j] == m_refIAC &&
				    (unsigned char)pending[j + 1] == m_refSE) {
					se = j;
					break;
				}
			if (se < 0) {
				m_pending = pending.mid(i);
				break;
			}
			fprintf(stderr, "[sm] SB se=%d sb=%d\n", se, sb);
			if (se - sb >= 1) {
				const int option = (unsigned char)pending[sb];
				const int action = (unsigned char)pending[sb + 1];
				emit subOptionReceived(option, action);
				// 实验锚:SB 24,1(TTYPE SEND)→ SB 24,0
				// "xterm-256color" SE(got=fffa1800787465
				// 726d2d323536636f6c6f72fff0)
				if (option == kOptTtype && action == 1) {
					QByteArray r;
					r += (char)m_refIAC;
					r += (char)m_refSB;
					r += (char)kOptTtype;
					r += (char)0;
					r += kTermType;
					r += (char)m_refIAC;
					r += (char)m_refSE;
					emit negotiationReply(r);
				}
			}
			i = se + 2;
			continue;
		}
		if (i + 2 >= pending.size()) {
			m_pending = pending.mid(i);   // 缺 option 字节
			break;
		}
		const int option = (unsigned char)pending[i + 2];
		QString name;
		switch (cmd) {
		case 0xFB: name = QStringLiteral("WILL"); break;
		case 0xFC: name = QStringLiteral("WONT"); break;
		case 0xFD: name = QStringLiteral("DO"); break;
		case 0xFE: name = QStringLiteral("DONT"); break;
		default: break;
		}
		optionStates[option] = name;
		emit optionNegotiated(name, option);
		// 实验锚策略(见 kInitNegotiation 注):DO 24 → 重发
		// init;DO 31 → SB NAWS(cols,rows);WILL 1/3 → 不应;
		// 其余 DO → WONT(39 实证)、其余 WILL → DONT
		QByteArray r;
		if (cmd == 0xFD) {                       // DO
			if (option == kOptTtype) {
				r = kInitNegotiation;            // 重发 init 实证
			} else if (option == kOptNaws) {
				r += (char)m_refIAC;
				r += (char)m_refSB;
				r += (char)kOptNaws;
				r += (char)0;
				r += (char)(m_screen
				                ? m_screen->m_core->columnCount()
				                : 80);
				r += (char)(m_screen ? m_screen->m_core->rowCount()
				                     : 24);
				r += (char)m_refIAC;
				r += (char)m_refSE;
			} else {
				r += (char)m_refIAC;
				r += (char)0xFC;                 // WONT
				r += (char)option;
			}
			emit negotiationReply(r);
		} else if (cmd == 0xFB) {                // WILL
			if (option != kOptEcho && option != kOptSga) {
				r += (char)m_refIAC;
				r += (char)0xFE;                 // DONT
				r += (char)option;
				emit negotiationReply(r);
			}   // ECHO/SGA:已 DO,不应(实证 got="")
		}
		i += 3;
	}
	return data;
}




void TelnetCommander::negotiateOption(const QString &command)
{
	Q_UNUSED(command);   // 槽面保留(配置驱动协商的命名派发点)
}

void TelnetCommander::negotiateSubOption(const QString &option)
{
	Q_UNUSED(option);
}
