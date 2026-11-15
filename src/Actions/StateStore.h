#pragma once

#include <QList>
#include <QMainWindow>
#include <QString>
#include <QVariant>
#include <QVariantList>
#include <QVariantMap>

#include "MainWindowFace.h"
#include "StartupChain.h" // startupReopenHistoryPath 缺省参路径腿(批 150)

// 批 167(M19-②)reopen.history 保存侧真身 — 写侧对称面:
//   恢复门 FUN_0075ffcc(批 150 读侧,startupRestoreGate)⇄
//   写面 FUN_0076073a(268B,0023.c:28686)+ 单窗摘除/入表
//   FUN_00760872(344B,0023.c:28740)+ 页表序列化 FUN_007669b2
//   (571B,0023.c:33468,窄面)。
// 产品挂点:s_WindTerm_75be40(590B,0023.c:25720)QCoreApplication::
//   aboutToQuit → connectImpl(FUN_00760856,28B,0023.c:28729 = 写面
//   FUN_0076073a + FUN_005d8c04 profiles 三卫 43B,0019.c:10352 配置域
//   cited)— 汇编 0x75bf6f MOV RAX,0x760856 实读。宿主 +0x50 窗表
//   (QList<0x20 节点>)槽位属 SuperApplication 批 — 表以参数承接
//   (批 163 Slots 判例;批 150 +0x48 窗表同判)。
// 数据面(铁律 1):节点 = 0x20 堆块四字段(FUN_007639a0 拷贝体
//   120B,0023.c:30860 逐 qw 直译 + 汇编 0x760924/0x76090d/0x760951 复核)。
struct SavedWindowNode {
	QMainWindow *win;    // +0x00(FUN_007639a0 *puVar2=*param_2)
	bool focusMode;      // +0x08(win+0x31 位读腿 @76090d — MainWindow
	                     //   +0x31 槽位宿主类未建模,cited 缺省 0;
	                     //   FUN_0076f4d6(win,0) 退腿 @76091f 405B
	                     //   >500B 邻档 cited — 批 150 读侧同判)
	QByteArray geometry; // +0x10(QWidget::saveGeometry @760937 0x4c1580)
	QByteArray payload;  // +0x18(FUN_007669b2(win,1) @76096b)
};

// FUN_007669b2(571B,0023.c:33468)主窗页表序列化窄面:
//   QDataStream(&blob,WriteOnly)@7669e6 + << stack.count <<
//   stack.currentIndex(@7669ef-a35)+ 逐页(@766a3c-c0d):
//   stack.widget(i) dynamic_cast KitWindow(011ab390)命中 →
//   FUN_008c9e64 面板名(collectorPaneTypeName 真身,批 159)/
//   未命中 → QObject::objectName(@766aed-f1)→ << QString;
//   << 页 payload = s_kit_startupSessions_8cf0c8(w,flags)产出
//   (2233B,0028.c:15003)— cited(>500B 邻档;KitWindow 深域),
//   空实现同相(读侧批 150 e2 空 payload 页挂闭环判例)。
//   &4 段(@766b58-bf5:isFullScreen/saveGeometry/win+0x30 onTop 位/
//   windowOpacity 子流)调用面 = FUN_007682d2(126B,0023.c:34700,
//   focusMode 缓存 +0x38/+0x40)属 0076f4d6 cited 域 → 本批不落
//   (读侧对称面 startupWindowTail 已落 WorkspaceLoader,批 154)。
QByteArray stateStoreSerializePages(MainWindowFace::Slots host,
                                    quint32 flags);

// FUN_00760872(344B,0023.c:28740)单窗摘除+入表真身:
//   FUN_00764d74(170B,0023.c:31906)窗表 removeAll 对位(@7608a1-8f2
//   表头 detach ×2 — QList 值语义承接)→ 命中直返(@7609b3 汇编
//   JZ 0x7609b3 实读);未命中保存体:node 装配(@7608fc-96c)+
//   param_3==0 → 清表腿 FUN_0076342e(49B,0023.c:30575;JZ 7609c0
//   汇编实证)+ append FUN_007639a0(@76099c)。两个调用点
//   (0x760a41 sub_7609d2 / 0x760abf sub_760a58)param_3 全传 1。
void stateStoreRemoveWindow(MainWindowFace::Slots winSlots,
                            QList<SavedWindowNode> &table,
                            QMainWindow *win, bool clearList);

// FUN_0076073a(268B,0023.c:28686)状态文件写真身:
//   QDataStream(&blob,WriteOnly)@0076076f → << 0xb9e7e626(汇编
//   0x76076f MOV ESI,0xb9e7e626 实读;反编译 -0x461819da)→
//   << 窗数(+0x50 表 end-begin @00760780-86)→ 逐窗 << +0x10
//   geometry << +0x18 payload << +8 bool(@28702-06)→
//   FUN_005dd6fc(250B,0019.c:13916)= QFile(path)open(WriteOnly)
//   + write 全量对账 bool;路径腿 = cfg_ensureProfileDir
//   "%1/profiles/%2/%3" + "global/reopen.history" — 读侧
//   startupReopenHistoryPath 同面复用(批 150 判例)。
//   historyPath 缺省 = 语料内部面;显式实参 = 测试注入缝
//   (批 150 startupRestoreGate 同判)。
bool stateStoreWriteReopenHistory(const QList<SavedWindowNode> &table,
                                  const QString &historyPath =
                                      startupReopenHistoryPath());

// ── 批 168(M19-④)三件套 text/data/session.uuid 保存侧 ──
// 探锚 FUN_0076913f(5958B,0023.c:35353)定性 = QMetaType 注册族
//   (KitWindow smeta 0x11ab660 等 registerNormalizedType ×~20;
//   pthread_once 注册腿 FUN_0076663e(114B,0023.c:33272),唯一
//   调用点 = mainWindow_connectSignals FUN_0076b9ec 第 2 步
//   @0076ba05 CALL 汇编实读)— 元类型面,非写腿本体。
// 写腿 = CTerminalConfig(DAT_011c2200)+0xe0 user.sessions 数组族
//   (读侧 = 522056 三件套解析批 154 / 810056 sessionByUuid 对偶):
//   8051f2(304B,0025.c:40618)uuid 替换;80ee76(316B,0025.c:45867)
//   uuid 摘除;80efd2(365B,0025.c:45917)组摘除(倒序);
//   805398(139B,0025.c:40687)追加(+0xe8 QHash 缓存清 cited);
//   8069b0(211B,0025.c:41501)upsert;810c4e(258B,0025.c:46974)
//   字段对等 set(FUN_00aef040 401B,0035.c:65951 同型比值)。
//   保存腿 806958(80B,0025.c:41482)+ 路径腿 806904(75B,0025.c:
//   41467 "/user.sessions")= ProfileLoader::saveSessions 现役对偶
//   (批 169);80eb6c(720B,0025.c:45772)摘除前活动视图重命名腿
//   cited(KitView 0x11a8c20 遍历域;variantmap_set 00a86184 =
//   QMap 写面已同相承载)。导入族 805b1a/816cae/80cd46/81371e/
//   815268(putty/openssh/shell 分组判定+条目生成)cited。
// 数组承载替 = QVariantList 注入面(批 154 判例);条目 = QVariantMap
//   扁平点号键(SessionManager 判例)。profilePath 缺省空 = 语料
//   内部面;显式实参 = 测试注入缝(批 150 historyPath 同判)。
namespace SessionStore {

// 8051f2 对偶:线性扫 session.uuid==uuid → 整条替换(lib[i]=session
// = json_value_swap 槽位换写同相);命中 true,否则 false。
bool replaceByUuid(QVariantList &library, const QString &uuid,
                   const QVariantMap &session);

// 80ee76 对偶:顺序首命中摘除(json_value_remove_take 同相;
// 空数组/空 uuid 卫 → false;80eb6c 重命名前置腿 cited 不落)。
bool takeByUuid(QVariantList &library, const QString &uuid);

// 80efd2 对偶:倒序逐项 value("session.group")(805a3e 195B 组腿
// 内联同相)命中摘除;removed!=nullptr 注入缝收集(语料逐项析构,
// 收集 = 测试对账缝);返回任一命中(语料 uVar6 OR 累积同相)。
bool takeByGroup(QVariantList &library, const QString &group,
                 QVariantList *removed = nullptr);

// 805398 对偶:+0xe8 QHash 缓存清 cited(注入库无缓存同相)→
// 数组尾插(FUN_00af5c40 arrayAt 尾交换插入同相)。
void append(QVariantList &library, const QVariantMap &session);

// 8069b0 对偶:uuid 空 → false(@008069bx 卫腿);8051f2 命中替换
// 否则 805398 追加;save → 806958 保存腿(ProfileLoader::saveSessions
// 现役;profilePath 空 → defaultProfilePath 内部面)。返回 = 命中/
// 保存结果(语料 param_3!=0 → 806958 结果;==0 → 1 同相)。
bool upsert(QVariantList &library, const QVariantMap &session,
            bool save, const QString &profilePath = QString());

// 810c4e 对偶:sessionByUuid 定位未中 → false;旧值(key 缺失 =
// QVariant null,DAT_00d38120 缺省同相)与新值同型比值
// (FUN_00aef040:同型才比,null==null 相等);值变 → set /
// value.isNull() → removeMember → 8069b0 收尾(save 同上)。
// 返回 = 变更与否(语料 uVar2 同相)。
bool setField(QVariantList &library, const QString &uuid,
              const QString &key, const QVariant &value, bool save,
              const QString &profilePath = QString());

} // namespace SessionStore
