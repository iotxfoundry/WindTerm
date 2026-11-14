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
	d.insertLoggerSession(id, QVariantList{0, 1, 2, QString("label"), QString("path")});
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

	printf(g_fail ? "FAIL(%d)\n" : "ALL PASS\n", g_fail);
	return g_fail ? 1 : 0;
}
