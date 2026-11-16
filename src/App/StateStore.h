#pragma once

#include <QList>
#include <QMainWindow>
#include <QString>
#include <QVariant>
#include <QVariantList>
#include <QVariantMap>

#include "Windows/Kit/MainWindowFace.h"
#include "App/StartupChain.h" // startupReopenHistoryPath 缺省参路径腿(批 150)

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
//   (2233B,0028.c:15003)— 批 173(M21-①)升真为骨架帧真身
//   stateStoreSerializePagePayload(深腿 cited 分段,见下)。
//   &4 段(@766b58-bf5:isFullScreen/saveGeometry/win+0x30 onTop 位/
//   windowOpacity 子流)调用面 = FUN_007682d2(126B,0023.c:34700,
//   focusMode 缓存 +0x38/+0x40)属 0076f4d6 cited 域 → 本批不落
//   (读侧对称面 startupWindowTail 已落 WorkspaceLoader,批 154)。
QByteArray stateStoreSerializePages(MainWindowFace::Slots host,
                                    quint32 flags);

class KitWindowFace;
class MuxWindow;

// 批 177(M22-①)blobA splitter/tabbar 树实体真身 — 写侧面(函数落
//   .cpp;出处在 .cpp 块注)。pane = KitWindowFace(现役树只读引用:
//   findChildren<MuxWindow*> → SplitterGroup→QSplitter 面承接 pane+0x38
//   表位;树深依赖浮停腿 cited 分段)。
QByteArray stateStoreSerializeSplitterBlob(const KitWindowFace *pane);

// FUN_008596b8(395B,0026.c:50614)QuickBar 写侧(补齐批 333 的 cited 空位)。
// 逐句实读:
//   QByteArray buf;QDataStream s(&buf, QIODevice::WriteOnly /*2*/);
//   **可见位**:名称槽(+0xd8)非空 && 宿主(+0xe0)非空 →
//     `(*(uint*)(*(*(+0xe0)+0x28)+8) >> 0xf) & 1`(QWidget 私有位 bit15);
//     否则 false。`s << vis`;
//   **快捷项名表**:同上条件成立 → detach(+0xe0 + 0x68) 得 QStringList;
//     `s << count`;逐项 `s << name`;
//   外层 `out << buf`(子流并入)。
//   ⇒ 样本尾 9B = BA(5B 00+00000000)= 可见 false + 空表,与读侧同相。
QByteArray stateStoreSerializeQuickBar(const KitWindowFace *pane);

// FUN_0085ae68(220B,0026.c:51550)QuickBar **读侧**(与上函数互为镜像):
//   `>> BA` 取子流 → 子流 `>> bool visible` → FUN_0085e0c0 取 QVariantList
//   (count + 项)→ **`(flags & 4) == 0` 时 FUN_0085ae06(this,&list) 应用条目**
//   → **`!visible` 时 FUN_008595c8(this)`(收起/隐藏 QuickBar)** → 返回 1。
//   备注(批 443 勘正):FUN_0085af56 不是 QuickBar 的懒建,而是
//   **TransferBar** 的懒建(+0xe8/+0xf0 另一对槽)—— 见 ensureTransferBar。
bool stateStoreRestoreQuickBar(KitWindowFace *pane, QDataStream &in, quint32 flags);

// FUN_0085af56(329B,0026.c:51580)TransferBar 懒建(结构段)。
void stateStoreEnsureTransferBar(KitWindowFace *pane);

// FUN_008cf0c8(2233B,0028.c:15003)s_kit_startupSessions 页 payload
// 序列化骨架真身(批 173,M21-①升真;原版 674B 实物帧实证,5c-report):
//   QDataStream(&blob)@008cf162 → << 0xb9e7e626(@008cf173,反编译
//   -0x461819da)→ << blobA @008cf37b → << blobB @008cf490 →
//   << blobC @008cf587 → 尾钩 vtable+0x248 != FUN_008d5bf4 腿
//   (@008cf960;原版样本尾 9B 00000005 00000000 00 = 钩体产物)。
// 分段面:
//   blobA(splitter/tabbar 树,样本 229B)= pane+0x38 容器槽族
//     param_2[7/8/10](FUN_008d7840 逐 splitter <<count + 逐页
//     <<FUN_008b921a tabbar serialize(306B:cur/count/逐 tab
//     objectName+会话态 BA)+ <<QSplitter::saveState)— 批 177(M22-①)
//     升真:stateStoreSerializeSplitterBlob(见 .cpp;原版 674B 实物
//     blobA 229B 段逐字段位级反推印证 — 5c/original/reopen.history
//     抽样:splitter0{count=2,tab70B(cur1+ExplorerPane/SessionPane
//     双 null 态),tab34B(cur0+FilerPane),ss31B}+splitter1{count=1,
//     tab8B(cur=-1 空表),ss27B}+splitter2{count=0,ss23B}=229B 尽);
//     面板树深腿(浮停副作用 dock_toggleFloat 8b8ce6 866B;cited)。
//   blobB(样本 417B)= (char)pane+0x70 旗标(ctor FUN_008cc692
//     +0x70 BYTE=1,KitWindowFace.h 头注;样本 B[0]=01 同相)+
//     param_2[0xb/0xc] 逐 splitter saveState(样本实序:31/35/27/0 四
//     段 — 逐段 <<BA 语法位级对账)+ flags&1
//     LastSessions 组块(@008cf62f-8ff:FUN_008cba1c 253B 设置读 +
//     逐项 kind char 2=命名页(s_RenamedTitle_8bbab6 850B BA)/
//     kind 1=splitter+句柄计数 — 外框字节序批 180 位级反推
//     byte-perfect([int][BA 根 ss][char kind][BA title],见 .cpp
//     块注 + 5c/dump_lastsessions.py);title 内层/句柄表迭代 cited)
//     → 旗标+四 saveState 帧(组块写面 cited 不落);
//   blobC(样本 3B)= MenuBar/StatusBar/ToolBar 三可见 bool
//     (FUN_008cefe4 212B,QWidgetData +0x28+8 位 0x10000 位域腿
//     未解)cited → 三 false 缺省(样本 00 00 00 同相)。
// pane+0x30 旗标门(@008cf0c8 入口 (char)param_2[6]==0 → 全序列化;
//   非零 → QObject::property 直取 BA @008cf110):置零腿 = 运行期
//   装配族 cited(ctor +0x30 WORD=0x0101 → 恒走全帧腿 = 样本同相,
//   恒态不发明)。
QByteArray stateStoreSerializePagePayload(const KitWindowFace *pane,
                                          quint32 flags);

// ── 批 180(M23-①)尾钩定性记要(vtable+0x248 = QuickBar 窗条面)──
//  vtable 实读(TerminalWindow vt 0x11a7c80 / EditorWindow 0x119ee30,
//  .data.rel.ro 槽位表):+0x240 恢复钩(两窗同 = FUN_008d1014)/
//  +0x248 保存钩(Terminal = FUN_0085ae68 读 face 220B / Editor =
//  FUN_008d5bee 默认 6B)/ +0x250(FUN_008d5bf4 空腿判别锚)。
//  写体 = FUN_008596b8(395B,0026.c:50614):BA[bool 可见位]
//  [int 表长][QString 逐项] — 样本尾 9B byte-perfect 同相(可
//  false + 空表)。QuickBar = 懒建 QWidget 子件(sub_56e26e ctor,
//  objectName "QuickBar" 0xd0e6d4 实读,QList<QString> names +0x68,
//  存宿主 +0xd8/+0xe0 QPointer 对)。出处细目见 StateStore.cpp
//  页 payload 块注;承接维持 cited(QuickBar 宿主槽未建模,铁律 6)。

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

// FUN_00760856(28B,0023.c:28729)aboutToQuit 触发接线真身(批 172,
// M20-③挂点闭环)— 产品挂点 = s_WindTerm_75be40(590B,0023.c:25720)
//   connectImpl(aboutToQuit→FUN_00760856)@0075bf6f MOV RAX,0x760856
//   汇编实读;调用序 = main FUN_0051f3ab(106B,0016.c:13422)→
//   s_WindTerm_75be40(local_78 宿主)。体两语句全读(0023.c:28731-37):
//   FUN_0076073a()写面 + FUN_005d8c04(DAT_011c1240)profiles 三卫。
// profiles 三卫 FUN_005d8c04(43B,0019.c:10352)cited 不落(铁律 6):
//   FUN_005d7b56(195B,0019.c:9539)once 锁 +0x50 文档 flush /
//   FUN_005d7c1e(9B)+0x58 flush / FUN_005d8bfe(6B)恒 1 — flush 腿
//   FUN_00a8086a jsoncpp 域(ext-boundary)+ 宿主 +0x50/+0x58 json
//   文档槽位未建模;恒 1 返回值语料丢弃同相。
// 窗表参承接:FUN_0076073a param_1+0x50 表槽位宿主侧未建模(铁律 6)
//   → 表以参数承接(批 163 Slots 判例);现役窗集装配 = 调用侧
//   stateStoreRemoveWindow(FUN_00760872;语料退出扫描 FUN_007609d2
//   134B,0023.c:28804 逐窗摘除腿对位,param_3=1)。
// historyPath 缺省 = 语料内部面(DAT_011c1240);显式实参 = 测试注入
//   缝(批 150 startupRestoreGate 同判;批 172 appboot 临时路径)。
void stateStoreAboutToQuit(const QList<SavedWindowNode> &table,
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
