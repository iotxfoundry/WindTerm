// 批 141:注册表插入→移除往返行为门(FUN_007da228 转写面)。
// 铁律 5:断言语料行为,每条带语料锚。
// 锚:+0x40 表插入 = FUN_007da228(0025.c:7540)/ 移除 = FUN_007db8ee
// (0025.c:8363,发 loggerRemoved = 0091228e activate idx6)/
// 插入信号 = FUN_00912264 activate idx5(IMPL-ADDRESSES #5)。
// 語料五 QVariant 参形(settings.size()==5 卫 @007da25a)。
#include <QCoreApplication>
#include <QVariantList>
// QSignalSpy 需 Qt5Test:仿 kitbartest 判例(find_package 已在文件尾)
#include <QtTest/qsignalspy.h>
#include <QUuid>
#include <cstdio>
#include "SuperSession.h"
#include "SuperSessionPrivate.h"

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
		// spdlog 下行(m_sink38/40)仍为空 — cited 段未执行,如实登记
		expect(lg.m_sink38 == nullptr && lg.m_sink40 == nullptr,
		       "i: sink/logger cited 段不打真 sink(EXT-BOUNDARY)");
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

	printf(g_fail ? "FAIL(%d)\n" : "ALL PASS\n", g_fail);
	return g_fail ? 1 : 0;
}
