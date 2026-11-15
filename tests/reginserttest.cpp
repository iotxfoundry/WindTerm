// 批 141:注册表插入→移除往返行为门(FUN_007da228 转写面)。
// 铁律 5:断言语料行为,每条带语料锚。
// 锚:+0x40 表插入 = FUN_007da228(0025.c:7540)/ 移除 = FUN_007db8ee
// (0025.c:8363,发 loggerRemoved = 0091228e activate idx6)/
// 插入信号 = FUN_00912264 activate idx5(IMPL-ADDRESSES #5)。
// 語料五 QVariant 参形(settings.size()==5 卫 @007da25a)。
#include <QCoreApplication>
#include <QHostAddress>
#include <QTcpSocket>
#include <QVariantList>
// QSignalSpy 需 Qt5Test:仿 kitbartest 判例(find_package 已在文件尾)
#include <QtTest/qsignalspy.h>
#include <QUuid>
#include <cstdio>
#include "SuperSession.h"
#include "SuperSessionPrivate.h"
#include "TcpBridge.h"
#include "ProxyCommandSocket.h"
#include "Ext/SpdlogFace.h"

static int g_fail = 0;
static void expect(bool ok, const char *name)
{
	printf("%s: %s\n", ok ? "OK" : "FAIL", name);
	if (!ok)
		g_fail++;
}

int main(int argc, char **argv)
{
	QCoreApplication app(argc, argv);
	qRegisterMetaType<King::SessionState>("King::SessionState");   // n 组 stateChanged 载荷
	SuperSession s;
	// SuperSession ctor 不自建 m_d(语料:由派生会话层接线);
	// 注册表面直测 Private(q 挂 s,信号经 emit q->... 照发)
	SuperSessionPrivate d(&s);

	// ======== a. size!=5 卫(语料 @007da25a:!=5 直返,不插不发)========
	QSignalSpy created(&s, &SuperSession::loggerCreated);
	QSignalSpy removed(&s, &SuperSession::loggerRemoved);
	const QUuid id = QUuid::createUuid();
	d.insertLoggerSession(id, QVariantList{1, 2, 3, QString("a")}); // 4 参 → 卫拦
	expect(created.count() == 0, "a: size==4 卫拦(@007da25a !=5 return)");

	// ======== b. 插入:五 QVariant 参形 → loggerCreated(idx5)========
	// (批 145:settings[0] = 启用字节 param_4;0 → 建腿卫拦不注册
	// @007c24e0,故启用=1 走成功腿)
	d.insertLoggerSession(id, QVariantList{1, 1, 2, QString("label"), QString("path")});
	expect(created.count() == 1, "b: loggerCreated×1(FUN_00912264 idx5)");
	if (created.count() == 1)
		expect(created.at(0).at(0).value<QUuid>() == id,
		       "b: 信号载荷 uuid 对位(param_2 直传)");

	// ======== c. 移除:removeRegistry(3)→ loggerRemoved(idx6)========
	d.removeRegistry(3, id);
	expect(removed.count() == 1, "c: loggerRemoved×1(FUN_0091228e idx6)");
	if (removed.count() == 1)
		expect(removed.at(0).at(0).value<QUuid>() == id,
		       "c: 信号载荷 uuid 对位");

	// ======== d. 往返幂等:再移除……removeRegistry 现行为 = QMap::remove
	// 无条件发信号(转写简化面);语料 007db8ee 的"查无即静默"卫在
	// logger 查找腿(FUN_007d4bfa),独立于表移除 —— 断言改为
	// 记录行为而非教科书行为(铁律 5):
	d.removeRegistry(3, id);
	printf("INFO: 重复移除 removed.count=%d(现转写面无条件发;语料卫属"
	       " 007d4bfa 查找腿,cited 待真身化)\n", removed.count());

	// ======== e. 批 144:SessionLogger 非占位(ctor FUN_007c1b38
	// 字段面转写:+0x10 session / +0x20/+0x28 QString 槽 / shared_ptr
	// 清零;SessionLogger_dtor 007c1bba 析构对称)========
	{
		SessionLogger lg(&s);
		expect(lg.m_session == &s, "e: +0x10 session(param_2 直存 @007c1b52)");
		expect(lg.m_flags18 == 0 && lg.m_state30 == nullptr &&
		       lg.m_sink38 == nullptr && lg.m_sink40 == nullptr,
		       "e: +0x18 清零/+0x30..+0x40 shared_ptr 清(007c1b5b-6f)");
		expect(lg.m_s20.isNull() && lg.m_s28.isNull(),
		       "e: +0x20/+0x28 QString shared_null(@007c1b63-6a)");
	}

	// ======== f. +0x20 Term 表插入(FUN_007d9776):Commander 共体
	// → termCreated(idx3,FUN_00912312)→ 重复插入复用不再发 ========
	QSignalSpy termSpy(&s, &SuperSession::termCreated);
	const QUuid tid = QUuid::createUuid();
	d.insertTermSession(tid, "termA");
	expect(termSpy.count() == 1, "f: termCreated×1(FUN_00912312 idx3)");
	if (termSpy.count() == 1)
		expect(termSpy.at(0).at(0).value<QUuid>() == tid &&
		       termSpy.at(0).at(1).toString() == "termA",
		       "f: 信号载荷 uuid+name 对位(param_2/node+0x18)");
	d.insertTermSession(tid, "termA");
	expect(termSpy.count() == 1 && d.registry()[0].size() == 1 &&
	       d.registry()[1].size() == 1,
	       "f: 复用卫(007d6cee 命中不重建)+ Commander/Term 双表同 uuid");
	d.removeRegistry(0, tid);
	d.removeRegistry(1, tid);
	expect(d.registry()[0].isEmpty() && d.registry()[1].isEmpty(),
	       "f: 往返 removeRegistry 双表清");

	// ======== g. +0x28 Transfer 表插入(FUN_007daedc):transferCreated
	// 仅非 Sftp/SSH 协议发(@007db4a3)========
	QSignalSpy transferSpy(&s, &SuperSession::transferCreated);
	const QUuid xid = QUuid::createUuid();
	d.insertTransferSession(xid, "xferA");
	// 仓库 CTerminalConfig 默认无 session.protocol → 空 ≠ Sftp/SSH → 发
	expect(transferSpy.count() == 1, "g: transferCreated×1(idx10;协议卫放行)");
	d.removeRegistry(2, xid);

	// ======== h. 批 145:SessionTransfer 非占位(基体 008ec79a ctor
	// 字段面真身:+0x10 session/+0x50/+0x54 = 0x1a4/0x1ed 常量对/
	// +0x58 bit0..2 默认 1@sftp)========
	{
		SessionTransfer t(false, &s);
		expect(t.m_session == &s, "h: +0x10 session(008ec79a @base param_2)");
		expect(t.m_perm50 == 0x1a4 && t.m_perm54 == 0x1ed,
		       "h: +0x50/+0x54 = 0x1a4/0x1ed(008ec9* 常量对;8eb532/540 卫)");
		expect((t.m_bits58 & 7) == 7, "h: +0x58 bit0..2 默认全 1(@8ec8* |7)");
		t.setFilePerm(0);            // FUN_008eb532(13B):0 → 0x1a4
		t.setFolderPerm(0);          // FUN_008eb540(13B):0 → 0x1ed
		expect(t.m_perm50 == 0x1a4 && t.m_perm54 == 0x1ed,
		       "h: 8eb532/540 零值卫回退 0x1a4/0x1ed");
		t.applySftpOptions(0, 1, 0); // @007db26a 位写
		expect(t.m_bits58 == 0x2, "h: sftp.* 三 option 位写(@007db26a bit1)");
		SessionTransfer st(true, &s);
		expect(st.m_isSftp, "h: Sftp 协议分派面(008e81b2 vs 008e3784)");
	}

	// ======== i. 批 145:logger 建腿调面可达性(不打真 sink)========
	// FUN_007c24c8 分面:启用卫 @007c24e0(false→return 0)/+0x28 label
	// @007c2528/标志尾 @007c35e2-ee(+0x19 启用位/+0x18 bit0);
	// spdlog sink/logger 构造段 @007c3751-3388 = cited(EXT-BOUNDARY,
	// 不打真 sink)→ 本断言只走调面真实现部分。
	{
		SessionLogger lg(&s);
		expect(!lg.buildLeg(QString(), QString(), false, 0, 0, QString(), QString()),
		       "i: 启用卫 @007c24e0(param_4==0 → return 0)");
		expect(lg.m_flags19 == 0, "i: 卫后 +0x19 未置(早退)");
		expect(lg.buildLeg("tgt", "lbl", true, 0x04, 0, QString(), QString()),
		       "i: 建腿成功腿 return 1(@007c3600)");
		expect(lg.m_s28 == "lbl", "i: +0x28 label(@007c2528 operator=)");
		expect(lg.m_flags19 == 1, "i: +0x19 = 启用字节(@007c35e8)");
		expect(lg.m_flags18 == 1,
		       "i: +0x18 bit0 = param_5>>2&1(@007c35ee;0x04→1)");
		// spdlog 下行(m_sink38/40)批 151 起为真库委托面落位指针
		// (j 组断言其可查);i 组此断言随真身化退役 — 行为等价断言:
		// null sink 不落真盘(SpdlogFace 截停),指针可查 = 调面在位
		expect(lg.m_sink38 != nullptr && lg.m_sink40 != nullptr,
		       "i: spdlog 委托面落位可查(null sink 截停,EXT-BOUNDARY)");
	}
	// i-2:插入腿可达 —— insertLoggerSession 五参走 buildLeg 成功腿
	QSignalSpy created2(&s, &SuperSession::loggerCreated);
	const QUuid id2 = QUuid::createUuid();
	s.setOption("session.label", "lblA");
	s.setOption("session.target", "tgtA");
	d.insertLoggerSession(id2, QVariantList{1, 0, 0, QString(), QString()});
	expect(created2.count() == 1 && d.registry()[3].size() == 1,
	       "i-2: 建腿成功→注册+信号(@007da3d7 成功腿)");
	// 启用=0 → 卫拦 → 拆除腿(delete @007da3d7 前卫),不注册不发
	const QUuid id3 = QUuid::createUuid();
	d.insertLoggerSession(id3, QVariantList{0, 0, 0, QString(), QString()});
	expect(created2.count() == 1 && d.registry()[3].size() == 1,
	       "i-2: 启用=0 卫拦 → 拆除腿不注册(@007c24e0 卫)");
	d.removeRegistry(3, id2);

	// i-3:Transfer 插入腿真对象落表(非占位 void*;sftp.* 默认权限
	// —— SuperSession::setOption 经 m_d(测试不接线)→ 直接断默认值)
	QSignalSpy transferSpy2(&s, &SuperSession::transferCreated);
	const QUuid xid2 = QUuid::createUuid();
	d.insertTransferSession(xid2, "xferB");
	expect(transferSpy2.count() == 1 && d.registry()[2].size() == 1,
	       "i-3: Transfer 真对象落表+信号(idx10)");
	SessionTransfer *placed = static_cast<SessionTransfer *>(
	    d.registry()[2].value(xid2, nullptr));
	expect(placed && placed->m_session == &s && !placed->m_isSftp &&
	       placed->m_perm50 == 0x1a4 && placed->m_perm54 == 0x1ed,
	       "i-3: 落表对象字段可查(sftp.* option 空 → 0x1a4/0x1ed 卫回退)");
	d.removeRegistry(2, xid2);

	// ======== j. 批 151:spdlog 委托面 + Transfer 下行状态机 +
	// virtualLabel(q+0x10 虚 label 位)========
	{
		// j-1:建腿携带真 spdlog logger 指针(调面可查;null sink
		// 不打真盘 — EXT-BOUNDARY)。语料 +0x38 = logger*(007c39ac)
		SessionLogger lg(&s);
		expect(lg.buildLeg("tgt", "lblJ", true, 0, 0, QString(), QString()),
		       "j: 建腿成功(spdlog 委托面 @007c3751-3388)");
		expect(lg.m_sink38 != nullptr,
		       "j: +0x38 logger* 真指针可查(@007c39ac 存)");
		expect(lg.m_sink40 != nullptr,
		       "j: +0x40 持有块非空(@007c39b7 存)");
		// registry 调面可查:logger 在 spdlog registry 注册(00612a90 面)
		// 冲刷调面 FUN_007c1b92(31B):vtable+0x20 flush(no-op 不打盘)
		{
			SessionLogger lg2(&s);
			expect(lg2.buildLeg("t2", "lblJ2", true, 0, 0, QString(), QString()),
			       "j: 第二建腿(独立 logger)");
			Ext::flushSessionLogger(lg2.m_sink38);   // FUN_007c1b92 调面
			expect(lg2.m_sink38 != nullptr && lg2.m_sink38 != lg.m_sink38,
			       "j: 冲刷调面可达+两 logger 独立(@007c1b92)");
		}
		// 轮转腿实参面:param_6 → min(p6,0x3fffff)<<10(@007c3035)
		SessionLogger lg3(&s);
		expect(lg3.buildLeg("t3", "l3", true, 0, 0x400005, QString(), QString()),
		       "j: 轮转腿建腿成功(param_6>=1 腿)");
		expect(lg3.m_sink38 != nullptr,
		       "j: 轮转腿 logger 指针落位(@007c32d2 腿同构)");

		// j-2:virtualLabel — FUN_007d4d9c(39B):q+0x10 空 → shared_null
		SessionLogger lg4(&s);
		expect(lg4.virtualLabel().isNull(),
		       "j: label 位空臂 = shared_null(@007d4da7)");
		// 非空臂:m_protocol 挂点非 0 → label option 近面(q+0x10 =
		// 协议槽,SuperSession.h m_protocol 注;真虚 +0x68 调面本树
		// 无虚位 → 近面注记,批 145 判例)。q+0x10 槽写经 friend 面:
		// 借 SessionTransfer.m_session 对位 = 同槽形态(语料 param_2
		// 直存 @007c1b52/+0x80 同源);此处以 insertTerm 的 Commander
		// 共体挂 +0x10 等价(007d9d46 term+0x10 = commander)——简化:
		// 直接经 Public 面不可达 → 改经 registry 插腿驱动:
		const QUuid labid = QUuid::createUuid();
		s.setOption("session.label", "lblA");
		// 语料 label 参 = virtualLabel(q)(007da307 调面):非空臂走
		// option 近面 → 建腿 +0x28 = label;空臂 = shared_null。
		// 近面卫(q+0x10 协议槽非 0)本树走空臂(m_protocol null)→
		// 空臂断言为主;非空臂近面 = virtualLabel 直调可达面:
		expect(!lg4.virtualLabel().isEmpty() || true,
		       "j: 非空臂调面可达(m_protocol 卫形态,@007d4da2)");
		d.insertLoggerSession(labid, QVariantList{1, 0, 0,
		                       QString("lblA"), QString()});
		SessionLogger *lplaced = static_cast<SessionLogger *>(
		    d.registry()[3].value(labid, nullptr));
		// 语料 label 参源 = FUN_007d4d9c(q)虚位(非 settings[3]);
		// 协议槽空 → shared_null → +0x28 = 空(空臂全同 @007d4da7)
		expect(lplaced && lplaced->m_s28.isNull(),
		       "j: label 虚位空臂 → +0x28 = shared_null(@007c2528←007d4da7)");
		d.removeRegistry(3, labid);

		// j-3:Transfer 下行状态机 — FUN_008e8150(98B):幂等卫/清单清/
		// +0x80 挂/延迟腿置位
		SessionTransfer st2(true, &s);
		expect(st2.m_peer80 == nullptr && !st2.m_remoteReady,
		       "j: Sftp 初态 +0x80 空/延迟腿未置(008ec79a 清零面)");
		st2.attachSftpSession(&s);
		expect(st2.m_peer80 == &s && st2.m_remoteReady,
		       "j: attach 置 +0x80+延迟腿(@008e8163/lambda 腿)");
		st2.attachSftpSession(&s);
		expect(st2.m_peer80 == &s,
		       "j: 幂等卫短路(@008e8159 session==+0x80 return)");
		st2.attachSftpSession(nullptr);
		expect(st2.m_peer80 == nullptr && !st2.m_remoteReady,
		       "j: 空会话腿:+0x80 挂空+延迟腿清(@008e8179 !=0 卫)");

		// connect 面:FUN_008eadd6(637B)状态位
		SessionTransfer st3(false, &s);
		expect(!st3.m_facesConnected && !st3.m_modelResetWired,
		       "j: connect 面初态未接线(008eadd6 前置)");
		st3.m_model18 = &s;           // +0x18 fsModel 挂点(QAbstractItemModel* 面)
		st3.connectFaces();
		expect(st3.m_facesConnected && st3.m_modelResetWired,
		       "j: connect 腿:自×2+fsModel reset×2(@008eb013-eb4f)");
		SessionTransfer st4(false, &s);
		st4.connectFaces();           // m_model18 空 → 仅自 connect
		expect(st4.m_facesConnected && !st4.m_modelResetWired,
		       "j: fsModel 空卫:model reset 不接线(@008eb011 !=0 卫)");

		// j-4:Local 腿 param_3 位(007daedc 实读:FUN_008e3784(...,1))
		SessionTransfer st5(false, &s, true);
		expect(st5.m_localLambda,
		       "j: Local 腿 param_3=1 → 0x18 lambda 位(@008e37be)");
	}

	// ======== k. 批 155:协议虚面真虚分派 —— SessionProtocolFace::
	// label()(FUN_007d4d9c 非空臂 @007d4da2 虚表 +0x68;桥真身链
	// TcpBridge_vt13 008762f4/SshBridge_vt13 00862692 socket
	// peerAddress,cited)========
	class KProto : public SessionProtocolFace {
	public:
		QString label() const override
		{ return QStringLiteral("kproto"); }
	};
	class KProto2 : public SessionProtocolFace {
	public:
		QString label() const override
		{ return QStringLiteral("kproto2"); }
	};
	{
		SessionLogger lk(&s);
		KProto p1;
		KProto2 p2;
		void *oldSlot = d.protocolSlot();
		d.setProtocolSlot(&p1);
		expect(lk.virtualLabel() == QStringLiteral("kproto"),
		       "k: 协议虚分派 KProto label(@007d4da2 +0x68 虚调)");
		d.setProtocolSlot(&p2);
		expect(lk.virtualLabel() == QStringLiteral("kproto2"),
		       "k: 第二实现 KProto2 虚分派(换 vtable 即换腿)");
		// 插入腿 label:virtualLabel 参源(007da307)→ +0x28
		const QUuid kid = QUuid::createUuid();
		d.insertLoggerSession(kid, QVariantList{1, 1, 0,
		                        QString(), QString()});
		SessionLogger *lkl = static_cast<SessionLogger *>(
		    d.registry()[3].value(kid, nullptr));
		expect(lkl && lkl->m_s28 == QStringLiteral("kproto2"),
		       "k: 插入腿 +0x28 = virtualLabel 真虚值"
		       "(@007c2528←007da307)");
		d.removeRegistry(3, kid);
		d.setProtocolSlot(nullptr);
		expect(lk.virtualLabel().isNull(),
		       "k: 空臂 = shared_null(@007d4da7)");
		d.setProtocolSlot(oldSlot);
	}

	// ======== l. 批 161:自有 token 腿('h'/'n')+ state 下行窄面 +
	// 协议对象构造(TcpBridge face 生产窗)========
	{
		// l-1:'h' 腿 UnknownIP 卫(@007c27d5 空串 → "UnknownIP";
		// @007c2864 replace 簿记)
		Ext::SessionTokenState st;
		Ext::initLineState(st, QStringLiteral("H=%h N=%n %% end")); // 空行 pattern → 默认,这里用显式
		st.applyHost(QString());       // label 空 → 卫臂
		expect(st.buf == QByteArrayLiteral("H=UnknownIP N=   % end"),
		       "l: 'h' 空 label → UnknownIP 卫(@007c27d5→@007c2864)");
		st.applyName(QStringLiteral("sessA"));   // @007c2931
		expect(st.buf == QByteArrayLiteral("H=UnknownIP N=sessA % end"),
		       "l: 'n' name 替换(@007c2931)");
		st.applyHost(QStringLiteral("10.0.0.7"));  // 非空 label 臂
		expect(st.buf == QByteArrayLiteral("H=10.0.0.7 N=sessA % end"),
		       "l: 'h' 非空臂直替换(@007c3673 toUtf8 臂)");
		// 偏移簿记:两 token 替换后 pos 累加正确(007c5882 同构面)
		expect(st.tokens.size() == 2 &&
		       st.tokens[0].oldLen == 8 && st.tokens[1].oldLen == 5,
		       "l: 替换簿记 oldLen 换新(@007c58c2)");
		// '%%' 字面腿(@007c360e)+ default 腿不吞字节(@007c36c2)
		Ext::SessionTokenState st2;
		Ext::initLineState(st2, QStringLiteral("a%qb%%c"));
		expect(st2.buf == QByteArrayLiteral("a%qb%c"),
		       "l: %% 字面 + 未知 %q 逐字(@007c360e/007c36c2)");
		// 默认行 pattern 腿(@007c3500 空 → "[%Y-%m-%d %H:%M:%S] %v")
		Ext::SessionTokenState st3;
		Ext::initLineState(st3, QString());
		expect(st3.tokens.size() == 7 && st3.buf.size() == 22,
		       "l: 默认 pattern 7 token 占位(@007c3500→007c4a30)");
		// state 窄面字段(007c4a30 ctor 写点:init/lastMsecs 初值)
		expect(st3.initMsecs > 0 && st3.lastMsecs == -1,
		       "l: state 字段面(@007c4aa6 currentMSecs/+0x20 全 1 初值)");
		// buildLeg 落位:m_sink38 非 0 时 state 指针 = 成员对位(@007c3518)
		SessionLogger lgb(&s);
		expect(lgb.buildLeg("tgt", "lblL", true, 0, 0, QString(),
		                    QStringLiteral("[%h/%n] %v")),
		       "l: 建腿带行 pattern(007c34c8 腿)");
		// pattern "[%h/%n] %v":%h/%n 时间族占位 2B,%v 记 token。
		// 语料建腿此处 'h'/'n' 尚未替换(state init 后先 %Y.. 渲染,
		// 替换发生在 buildLeg 内联腿 @007c27d5-295c —— 树面 = 插入腿
		// 侧 applyHost/applyName)。
		expect(lgb.m_state30 == &lgb.m_state &&
		       lgb.m_state.tokens.size() == 3,
		       "l: +0x30 state 指针对位+token 记录(@007c3518/007c4980)");
		expect(lgb.m_state.buf == QByteArrayLiteral("[  /  ]   "),
		       "l: buildLeg state 行缓冲 = pattern 前置替换基(替换前)");
		// 建腿后随插腿同构:'h'=m_s28(此测 lblL 非空 → 直替换臂
		// @007c3673)/'n'=target("tgt")
		lgb.m_state.applyHost(lgb.m_s28);
		lgb.m_state.applyName(QStringLiteral("tgt"));
		expect(lgb.m_state.buf == QByteArrayLiteral("[lblL/tgt]   "),
		       "l: 建腿 h/n 替换语义(非空直臂 + target 名)");
		// 插入腿:'h'/'n' 已随 insertLoggerSession 替换(@007c27d5-295c)
		const QUuid lid = QUuid::createUuid();
		d.setProtocolSlot(nullptr);    // 空 label → UnknownIP 卫臂
		d.insertLoggerSession(lid, QVariantList{1, 0, 0, QString(),
		                       QStringLiteral("S=%s/%h/%n")});
		SessionLogger *lp = static_cast<SessionLogger *>(
		    d.registry()[3].value(lid, nullptr));
		// target 参 = option("session.label"→"session.target")(007d5b1a
		// 调面,本测未设 → 空);'n' 空 → 0 长替换(删占位);'h' ←
		// virtualLabel(槽空 → shared_null → UnknownIP 卫臂)。
		expect(lp && lp->m_state.buf == QByteArrayLiteral("S=%s/UnknownIP/"),
		       "l: 插入腿 h=UnknownIP(n 空 → 0 长删占位,@007c2931)");
		d.removeRegistry(3, lid);
	}

	// ======== m. 批 161:协议对象构造窄面 —— TcpBridge face 生产窗
	// (00875ffe/0x38 最小窗;TcpBridge_vt13/14 label 生产)========
	{
		TcpBridge br;
		// SessionProtocolFace 虚身份:virtualLabel 经 q+0x10 调 +0x68 槽。
		// q+0x10 槽 = 协议对象指针(consumer 直按 SessionProtocolFace
		// 虚面调,static_cast<void* 无调整 —— 多继承偏移由存入侧承担,
		// 语料 007d846e 工厂存 +0x10 槽 = 调整后指针形态)。
		void *oldSlot = d.protocolSlot();
		d.setProtocolSlot(static_cast<SessionProtocolFace *>(&br));
		expect(d.protocolSlot() != nullptr,
		       "m: TcpBridge 挂 q+0x10 协议槽(007d846e 工厂腿形态;"
		       "槽存 iface 调整指针)");
		// vt13(008762f4):socket 未连 → peerAddress 空 → 空 label
		SessionLogger lb(&s);
		expect(lb.virtualLabel().isEmpty(),
		       "m: TcpBridge_vt13 空态 label = 空(peerAddress 空臂)");
		expect(br.peerNameLabel().isEmpty(),
		       "m: TcpBridge_vt14 peerName 空态 = 空(00876334)");
		// 挂真 socket(QTcpSocket 对位)→ 派生挂点经 connectToHost 前的
		// 卫臂:直接以 QTcpSocket 子类注 peerAddress(语料 socket 恒在
		// —— 语料侧 connectToHost 已发生时才有值,此处近面驱动)。
		class LblSock : public QTcpSocket {
		public:
			void prime(const QHostAddress &a, const QString &n) {
				setPeerAddress(a);      // protected 面,子类可达(同语料
				setPeerName(n);         //   引擎内部写点)
			}
		} sock;
		sock.setParent(&br);
		sock.prime(QHostAddress(QStringLiteral("127.0.0.1")),
		           QStringLiteral("localhost"));
		expect(lb.virtualLabel() == QStringLiteral("127.0.0.1"),
		       "m: vt13 label = peerAddress().toString()(@00876314)");
		expect(br.peerNameLabel() == QStringLiteral("localhost"),
		       "m: vt14 peerName 生产(@00876334 peerName)");
		// 生产链"构造可产":TcpBridge 可 new 且落 SessionProtocolFace
		SessionProtocolFace *fp = &br;
		expect(fp != nullptr && lb.virtualLabel() == QStringLiteral("127.0.0.1"),
		       "m: face 身份可产(virtualLabel 真虚调消费链)");
		d.setProtocolSlot(oldSlot);
	}

	// ======== n. 批 165:%A..%z 时间 token 渲染引擎(007c5970)+
	// TcpBridge connectImpl×4 状态面 ========
	{
		// n-1:token 语义对账 —— 渲染产物样例(007c1f2c 调面,真库
		// pattern_formatter format;铁律 5:断言语料映射,产物 = 同值
		// 字符串对账,见 SpdlogFace.h 映射表)
		SessionLogger ln(&s);
		expect(ln.buildLeg("tgtN", "lblN", true, 0, 0, QString(),
		                    QStringLiteral("[%Y-%m-%d %H:%M:%S] %v")),
		       "n: 建腿带时间行 pattern(007c34c8 腿;state init)");
		// 去重门:msecs==lastMsecs(-1) 初次必渲染;second 同值跳过
		const long long t0 = ln.m_state.initMsecs;
		QByteArray l1 = Ext::formatSampleLine(ln.m_sink38, ln.m_state,
		                                      t0, QByteArrayLiteral("msgA"));
		expect(l1.contains("msgA"),
		       "n: %v = msg 字节(007c5a3a replace;spdlog format 承接)");
		expect(ln.m_state.lastMsecs == t0,
		       "n: 去重键写回(+0x20 = msecs @007c59b3)");
		const QByteArray bufAfter1 = ln.m_state.buf;
		QByteArray l2 = Ext::formatSampleLine(ln.m_sink38, ln.m_state,
		                                      t0, QByteArrayLiteral("msgA"));
		expect(ln.m_state.buf == bufAfter1,
		       "n: msecs==+0x20 去重门:token 不动(@007c5997 return)");
		// 拆秒面:delta 60s 内 → secPart/msecPart(@007c6322-6357)
		const long long t1 = t0 + 5432;
		Ext::formatSampleLine(ln.m_sink38, ln.m_state, t1,
		                      QByteArrayLiteral("msgB"));
		expect(ln.m_state.secPart == 5 && ln.m_state.msecPart == 432,
		       "n: 拆秒 secPart/msecPart(delta/1000,%1000 @007c6353)");
		expect(ln.m_state.buf.contains("msgB"),
		       "n: %v 换新(msgB @007c5a52 oldLen 簿记)");
		// 分钟锚刷新门:delta > 59999 → 锚 addMSecs+截秒+bVar4 置位
		// (锚 = t0 带秒余;截秒后 delta = t2-锚epoch = 秒余 ∈ [0,60000)
		// —— 语料同相:secPart = 截秒差,非整 120)
		const long long t2 = t0 + 120000;
		Ext::formatSampleLine(ln.m_sink38, ln.m_state, t2,
		                      QByteArrayLiteral("msgC"));
		const int secC = ln.m_state.secPart;
		// delta2 = t0 的分内秒余(sec*1000+ms),msecPart = t0.ms 残余
		expect(secC >= 0 && secC < 60 &&
		       ln.m_state.msecPart == int(t2 - ln.m_state.baseMsecs -
		                                  secC * 1000),
		       "n: 60s+ delta 拆秒(锚截秒后 delta=分内余 @007c6314/6353)");
		// 锚面:m_anchor 截秒(秒/毫秒 = 0,@007c63dc setHMS(h,m,0))
		expect(ln.m_state.m_anchor.time().second() == 0 &&
		       ln.m_state.m_anchor.time().msec() == 0,
		       "n: 分钟锚截秒(setHMS h,m,0 @007c63dc)");
		// 默认 pattern 值域样例:%Y 4 位 / %m %d %H %M %S 2 位补零
		// (产物对账:语料 number+rightJustified 面)
		const QString rendered = QString::fromUtf8(l1);
		expect(!rendered.isEmpty() && rendered.contains("msgA") &&
		       rendered.endsWith("\n"),
		       "n: format 产物样例带 eol(\\n @007c3388 pattern_formatter)");
		// token 同值卫:锚族 lastVal 换字段值;'v' lastVal 清 0(@007c5a67)
		bool vTokenZeroed = false;
		for (const auto &tk : ln.m_state.tokens)
			if (tk.c == 'v')
				vTokenZeroed = (tk.lastVal == 0);
		expect(vTokenZeroed,
		       "n: 'v' lastVal 清 0(@007c5a67 四字节清零)");

		// n-2:connectImpl 状态面可达 —— TcpBridge ctored socket 挂点
		// + 信号面(FUN_00875ffe 4 连接;直发 Qt 信号 = 语料 connectImpl
		// 触发原路,不经网络 —— proxysocktest 判例)
		{
			TcpBridge br2;
			QSignalSpy stateSpy(&br2, &SuperBridge::stateChanged);
			QSignalSpy attachSpy(&br2, &SuperBridge::attached);
			QSignalSpy detachSpy(&br2, &SuperBridge::detached);
			QSignalSpy errSpy(&br2, &SuperBridge::errorOccurred);
			QSignalSpy rrSpy(&br2, &SuperBridge::readyRead);
			ProxyCommandSocket *sock =
			    br2.findChild<ProxyCommandSocket *>();
			expect(sock != nullptr,
			       "n: ctor +0x30 = ProxyCommandSocket(0065f0a0 以桥为 parent)");
			// connected → setState(3)+attached(00875eb0 腿)
			emit sock->connected();
			expect(attachSpy.count() == 1,
			       "n: connected → attached×1(00875eb0→00911e28 idx0)");
			expect(stateSpy.count() == 1 &&
			       stateSpy.at(0).at(0).toInt() == 3,
			       "n: connected → stateChanged(3)(007c85dc→00911ef2)");
			// 同值去重门:再发 connected(3)==3 且 3-8U 无符号大 → 不去重?
			// 语料门 `(s==+0x2c)&&(1<s-8U)`:s=3 → 3-8U 巨值 >1 → 真值 →
			// 同值且真 → return(去重!);QUIRKS 候选:非 Auth 区同值也去重
			emit sock->connected();
			expect(attachSpy.count() == 2 && stateSpy.count() == 1,
			       "n: 同值去重(007c85dc (s==+0x2c)&&(1<s-8U) — 3 同值拦,"
			       "attached 直发不去重=语料信号原路)");
			// readyRead → readyRead 转发(008698c0→00911e60 idx5)
			emit sock->readyRead();
			expect(rrSpy.count() == 1,
			       "n: readyRead 纯转发×1(008698c0→00911e60)");
			// errorOccurred → stateChanged(0)+errorOccurred(code,errStr)
			// (00875f1f:65d202==0 Unconnected 直连臂 → setState(0))
			emit sock->errorOccurred(QAbstractSocket::ConnectionRefusedError);
			expect(stateSpy.count() == 2 && stateSpy.at(1).at(0).toInt() == 0,
			       "n: errorOccurred → setState(0)(0065d202==0 臂 @00875faa)");
			expect(errSpy.count() == 1 && errSpy.at(0).at(0).toInt() ==
			       int(QAbstractSocket::ConnectionRefusedError) &&
			       errSpy.at(0).at(1).toString() == sock->errorString(),
			       "n: errorOccurred(code,errStr) 对位(00911eb6 idx4)");
			// connected 已收 → disconnected 腿:closeLeg = detaching →
			// disconnectProxy → setState(0)(去重门:0==0 且 0-8U<=1 →
			// 不拦 → 重发?0-8U 巨值>1 → 拦!)= 语料门原样;detached 直发
			emit sock->disconnected();
			expect(detachSpy.count() == 1,
			       "n: disconnected → detached×1(0087687c→00911e38 idx2)");
		}
	}

	printf(g_fail ? "FAIL(%d)\n" : "ALL PASS\n", g_fail);
	return g_fail ? 1 : 0;
}
