#pragma once

#include <QByteArray>
#include <QDataStream>
#include <QMainWindow>
#include <QString>
#include <QStringList>
#include <QMap>
#include <QVariantList>

#include "Actions/KitWindowFace.h"
#include "Actions/MainWindowFace.h"

// 批 154(M16-①)— 工作区装载器分段 + 启动余量。
// 段清单(铁律 1/3/6:每行有出处;cited 段挂地址清单,不发明):
//
// 段 1  kitStartupSessions    s_kit_startupSessions_8d2f7e(3122B,
//                             decomp-part-0028.c:17278)分发腿真身
//                             (键面 LastSessions/SpecificSessions +
//                             kit.startupSession1-4 槽;splitter/tabbar
//                             深腿 cited)。
// 段 1  startupWindowTail     FUN_00766c26 &4 尾段(0023.c:33653-6f4c)
//                             + FUN_00766466(60B,33174 全屏切换)+
//                             FUN_00766364(258B,33123 X11 置顶,cited
//                             XSendEvent 面)+ setWindowOpacity 真腿。
// 段 2  workspaceLoader       s_session_uuid_522056(9063B,0016.c:16441)
//                             骨架真身:trimmed/format 门 + 三面板
//                             text/data/session.uuid 三件套解析 +
//                             session.uuid→sessions 匹配(47047 810056
//                             查面);收集器/session_defaultDir/Editor
//                             目录腿 cited。
// 段 3  startupWindowCreate   FUN_0075e0f8(765B,0023.c:27251)窄面:
//                             new MainWindow + restoreGeometry/居中缩放
//                             腿 + connectSignals 尾调(MuxWindow 宿主
//                             衔接窄面;深 UI 装配 cited)。
// 段 4  007626ce 挂点裁决:真调用链 = SuperApplication ctor
//       FUN_0075dba4(131B,0023.c:27019)→ QTimer::singleShotImpl(0,0,
//       app,thunk{1,FUN_00762925,app})@0075dc1f;thunk FUN_00762925
//       (43B,29928)case1 → s_application_lockScreenTimeout_7626ce
//       (startupChain 真身,批 149)。kuna xrefs --to 0x7626ce 唯一
//       引用 = 0x762935 JMP(case 腿);无 vtable/connectImpl 数据
//       引用(.rela.dyn 10839 项 + .data.rel.ro/.data/.rodata 8B/4B
//       全扫描零命中)。→ 接线面 = QTimer 零毫秒单发,非信号;
//       产品落点属 SuperApplication/启动链宿主批,cited 维持。

// ── 段 2:工作区装载器(s_session_uuid_522056 骨架)──
//
// 语料签名(undefined8 *s_session_uuid_522056(long pane,long panel,
// undefined8 *title)):param_1 = pane widget(可 0),param_2 = 面板
// widget,param_3 = 标题串(in/out:首句 trimmed_helper 换写)。返回
// 0x50 堆块(QHash<QHashNode>)。骨架真身面:
//   @005220c0  QString::trimmed(param_3)
//   @0052210e  operator_new(0x50) QHash 头;bucket new(0x40)/new(0x200)
//              (QHashData::allocateNode 内联面)
//   @00522172  toUtf8 → std::string → FUN_00a8ebd8(…,4)(json 值构
//              造腿,收集器根;title 空同相)
//   @00522288  param_1!=0 → FUN_008c9e64(pane) 面板类型名
//              ("TerminalWindow"→"Terminal")
//   @005222df  "Editor" 腿:FUN_008d0cf2(Editor 收集器,339B —
//              windowFilePath QList)逐项 session_defaultDir(…,2)
//              入 QHash(node flag=2)
//   @00522df8  "Terminal" 腿:FUN_008d097c(Terminal 收集器,223B —
//              mux 子件 QVariant QList)逐项 vcall+0x78(uuid 取)/
//              FUN_008c52fa/FUN_008b99f6/FUN_008b9c46/FUN_008a067e →
//              session_defaultDir(…,6) 入 QHash(flag=6);重名
//              append(" / " 0xc89068 尾 3 字符腿 @0052304b)
//   @00522495  "Terminal"/"Browser" → local_218=7 else 3(会话库腿
//              kind 位)
//   @005224c5  FUN_008caf52(48B,0028:12339 = vt+0x1f0 menu 单例 →
//              vt+0x10 vcall 收集)逐项:uuid 非重 → toUtf8 →
//              FUN_00a7e872(json 解析腿)→ json_isNullType 分叉:
//              null → session_defaultDir(pQVar25,…,local_218) 直接入
//              (flag=local_218);非 null → json_get_string_default
//              ("text" @0052330d / "data" @0052337d,DAT_00cb99b6 空缺
//              省)双串非空才 session_defaultDir(text,data,local_218)
//              入(flag=local_218)
//   @0052271e  "Editor" 腿(目录扫描):FUN_008bca9e(pane,1)→
//              KitView_vt15(windowFilePath)→ lastIndexOf(sep)→
//              QDirIterator(Files|Subdirs?2=AllDirs→toNativeSeparators
//              入,flag=1);@00523176 fromNativeSeparators 双扫描腿
//              (flag=0)— cited(目录枚举深度腿)
//   @005237e3  "Terminal" 腿(session.uuid 匹配):URL 正则
//              "://([^/]++)/"(0x52380e 字面)+ pane vt+0x78 串 match
//              captured(0);DAT_011c2200(+0xe0 会话数组)逐项
//              json_get_string_default("session.uuid",空)非空 →
//              QHash 内 Fun_00525500 收集节点链(node+0x18)线性比对
//              (== uuid);全无 → FUN_00525880 detach 后空链腿
//              s_session_protocol_810d6e(810d6e,1760B — cited)取
//              protocol → match captured(0) 比对 → session_defaultDir
//              (uuid…)(param_6 空);命中 flag==7 前扫描腿
//              (@00524025 腔)
//   @00522a48  尾:计数 = bucket 三段维数代数(≤9 截断),>9999 截
//              (0x2710 cap)— QHash 容量代数,内部面不落数值行为;
//              FUN_00632426(402B,0020.c:11259 = QList 转移构造
//              nothrow 面)收尾。
// 深度腿(session_defaultDir 2297B 0016.c:15428 自身带 bad-instruction
// 语料;收集器 008d0cf2/008d097c;Editor 目录扫描;810d6e protocol)
// >500B 或语料残缺 → cited(地址如上);本面 = 骨架分节 + 三件套解析
// + uuid 匹配,消费面经测试注入(会话库腿以 QVariantList 承载)。
//
// 端口形态:param_1/param_2 → QWidget*( QObject* 面);param_3 title
// in/out;返回 = 匹配命中的会话条目列表(session.uuid 命中腿) +
// 去重目录集(QHash key 面)。会话库源 = ProfileLoader::loadSessions
// (DAT_011c2200+0xe0 对位;CTERMINAL-CONFIG 判例同相)。
namespace Workspace {

// s_session_uuid_522056 骨架真身。title 原地 trimmed(@005220c0);
// 返回值 = QHash 键集的 QList 承载(语料 0x50 堆块 QHashData;键 =
// 三件套 data/uuid 串,值 = kind flag 2/6/7/3/1/0)。
class LoaderResult
{
public:
	QStringList keys;         // QHash key 集(去重插入序不保 — 语料 hash 序,
	                          //   测试只断言成员非序)
	QList<int> kinds;         // 每 key 的 node flag(kind 位,见上表)
	bool empty() const { return keys.isEmpty(); }
};

LoaderResult workspaceLoader(QObject *pane, QObject *panel, QString &title,
                             const QVariantList &sessionLibrary);

// ── 批 163(M18-②)strtrie_find_qv 承载面(session_defaultDir 键值域)──
//
// FUN_0052674a strtrie_find_qv(765B,0016.c:19524)承载替(kuna 全读;
// 键升序不变量 = 槽线性扫 + 右移批插直译 → QMap 承载同相;inline —
// mwctest f9 直用):
struct StrTrie
{
	QMap<quint32, QVariant> cells; // 槽线性扫+右移批插 → 键升序承载
	// 分裂触发计数门真身(00525f50 2042B,0016.c:19112;kuna 全读 —
	// 插入腿调用点 @00526836-54:strtrie_find_qv 满槽 n==cap 时
	// cap<12 → 2n 扩容(00525a82 迁移);cap≥12 → FUN_00525f50 分裂。
	// 重建体(左兄有 room → 逐槽 0x18 交换搬 i 个 + 子指针 +0x130 区
	// 迁移 + 上溢换根 0x1a8 节点;无 room → 新 0x198/0x130 节点
	// 00525c5e 前插)仅重排内存布局,产出序列恒升序 — QMap 承载无
	// 容量概念 → 门恒不触发,分裂无观测差(quirks #31 同相判例);
	// 重建体 cited)。
	static constexpr int splitGateCapacity = 12; // 0xc cap 上限
	                                             //   @00526845
	QVariant find0052674a(quint32 key, const QVariant &value,
	                      bool *inserted) // 命中槽值/新插零值
	{
		auto it = cells.constFind(key); // @0052677f 线性扫(< key 走)
		*inserted = (it == cells.cend());
		if (*inserted)
			cells.insert(key, value); // @00526804 插入腿(右移批插
			                          //   = QMap 序保持同相)
		else
			return it.value(); // 命中 {*root,i,0} 面
		return QVariant();     // 未命中返 {*root,i,1} 零值同相
	}
};
// FUN_00521702 @00521866-21ac4 trie 腔真身(×6 find + trimmed +
// push 根):返回恒 1(卫恒过 — guard 空表同相);dir 原位 trimmed
// (@00521957)。
bool sessionDefaultDirTrie(const QString &paneName, QString &dir,
                           const QVariant &value, int kind);

// ── 批 159(M17-②)收集器/defaultDir/扫描/protocol 面 ──

// FUN_008c9e64(105B,0028.c:11345):objectName 去 "Window"
// ("TerminalWindow"→"Terminal")。
QString collectorPaneTypeName(const QObject *pane);

// FUN_008d097c(223B,0028.c:15898):Terminal 收集器 — mux stack 子件
// 逐件(名过滤 toLower + show 腿)QWidget* 列表。
QList<QWidget *> collectorMuxChildren(const QObject *pane,
                                      const QString &nameFilter, bool show);

// FUN_008d0cf2(339B,0028.c:16042):Editor 收集器 — 收集子件非空
// windowFilePath 串列表。
QList<QString> collectorEditorFilePaths(const QObject *pane);

// FUN_008bca9e(193B,0028.c:810):panel 活动视图(currentWidget 槽
// 对位面 — MuxPane/KitView 上溯腿 cited)。
QWidget *collectorActiveView(const QObject *panel);



// s_session_protocol_810d6e(1760B,0025.c:47022)URL 拼面:protocol://
// [group/]target[:port](SSH:22/Telnet:23 缺省腿)+ " / " label 腿 +
// toLower 尾;掩盖腿真身 s_session_target_8061a0(237B)/
// s_session_label_8062b6(180B,批 163)。
QString sessionProtocolUrl(const QVariantMap &session);

// 810056 对位查面(uuid→条目):user.sessions 数组线性扫 session.uuid
// (s_session_uuid_810056,1408B,0025.c:46473;DAT_011c2200+0xe0 +
// +0xf0 双源腿 — 本面单源 = 注入库,QHash 缓存腿 0xe8 cited)。
QVariantMap sessionByUuid(const QVariantList &library, const QString &uuid);

// s_session_target_8061a0(237B,0025.c:41148)target 掩盖腿真身:
//   json_get_string_default("session.target",空)→ param_4!=0 且
//   lastIndexOf('@',-1,cs=1) > 1 → replace(1, idx-1, '*' 重复
//   idx-1 次)(@0080622e-f1;addr→* 脱敏)。
QString sessionTargetMasked(const QVariantMap &session, bool mask);

// s_session_label_8062b6(180B,0025.c:41185)label 腿真身:
//   json_get_string_default("session.label",空);空 → target 覆盖
//   (8061a0 mask 腿同参 @0080634b-f1)。
QString sessionLabelOrTarget(const QVariantMap &session, bool mask);

} // namespace Workspace

// ── 段 1:启动余量(StartupChain 侧)──

// s_kit_startupSessions_8d2f7e 分发腿(panel widget + payload +
// flags)。语料序:
//   @17278    param_1[6] byte!=0 → return 0(BYTE 旗标卫,pane 状态位;
//             本面经 flags 承载 — KitWindow 槽位未建模,cited 同批 150)
//   @008d2fe5 payload 空 → 0;startTransaction + >> version(int)
//   @008d35b9 version < 0xb9e7e615 → FUN_008ce8f6(1347B — cited 旧
//             格式腿,不可达于现行写侧)
//   @008d302f >> QByteArray(splitter 布局段)→ 子流:逐 splitter 页
//             (QList 遍历 FUN_00856880 detach 面)>>(int 页数)→ 逐页
//             hide/setParent + qt_qFindChildren 清理(cited
//             008d78bc/00770640 面)+ 逐 QByteArray addPage →
//             restoreState;尾 >> QByteArray → QSplitter::restoreState
//             (splitter 深腿全 cited — SplitterGroup D 域)
//   @008d3323 >> bool → pane+0xe 写(param_1+0xe — 宿主槽位 cited)
//   @008d3380 >> QByteArray 表(splitter states 列表)逐 restoreState
//   @008d3601 flags&1 腿(= startupChain 唯一调用点 flags=1 可达):
//     FUN_008d7604(+9 表前置)→ config 键 "kit.startupSessions"
//     (FUN_008cba1c = 面板名前缀化配置读:objectName 去 "Window"
//     @008c9e64 + s_text_preferThemeFonts_760b2c 1141B "^kit(?=\.)"
//     replace + "text." startsWith 插头 — 键面真身化见下
//     kitScopedConfigValue)+ 默认 "LastSessions" → toString;
//     子流循环:>>(int group)>>(int count)>>QByteArray(name)>
//     逐项:>>(byte kind);kind==2 → >>QByteArray(uuid)>>
//     "LastSessions" 比较:不等 && 首 group && menu() 名 ==
//     "Terminal"(vt+0x1f0/vt+8 指针比对 @008d399a — 串同相)&&
//     name=="SpecificSessions" → 逐槽 kit.startupSession1-4
//     (@008d39ce 栈四槽:.rodata 0xd0cc1d/cc09/cbf5/cbe1 实读)读
//     (kitScopedConfigValue,默认空)→ indexOf(',',0,cs=1)>0 腿 →
//     left(idx) → sessionByUuid(810056) 命中才 FUN_008d2e46(pane,
//     name,0,"Last",tabbar)(284B — 开会话腿:真下行 cited,Pane
//     建模域)→ 尾 addWidget(pane+9);kind==1 → new QSplitter +
//     表尾 widget addWidget + FUN_008d75b4(表 append,cited 分裂腿);
//     其他 kind → 表[i] widget addWidget + s_RenamedTitle_8bb3e6
//     (1693B — cited 重命名腿);组尾 "LastSessions" ==
//     name → restoreState + setChildrenCollapsible(表[i]);
//     atEnd 门循环(@008d387b)。
//   @008d346b flags&4 || version > 0xb9e7e621:>> QByteArray(ui 段)
//     → 子流:>>(bool)→ vt+0x1d0("MenuBar",!b)@008d34c3;>>(bool)
//     → vt+0x1d0("StatusBar",!b)@008d350e;flags&4 || version >
//     0xb9e7e622:>>(bool)→ vt+0x1d0("ToolBar",!b)@008d356c
//     (vt+0x1d0 = 窗条切换虚槽 — KitWindow 域 cited,串实读
//     0x11826a0="MenuBar"/0x1182668="StatusBar"/"ToolBar" 腿)
//   @008d3ba9 vt+0x240 != FUN_008d5bee(6B return 1 默认)→ vcall
//     (stream,flags)— 下行钩 cited(KitWindow 域)
//   尾 return 1。
//
// flags 位义(调用面实证):bit0 = startupChain 恢复腿(会话分发);
// bit2 = &4 全恢复(含窗条/窗态段)。bit1 = +9 pane 复挂腿
// (@008d3b60,flags&1==0 时 — 非 startup 链,cited)。
bool kitStartupSessions(QObject *panel, const QByteArray &payload,
                        quint32 flags);

// s_kit_startupSessions_8d2f7e 挂页宿主槽(批 163 升真身段):
//   s_tabbar_selectionBehaviorOnRemove_89f516(pageType byte)—
//   379B,0026.c? 语料:QMetaEnum("TabSelectionBehavior" 0x1180860)
//   valueToKey(2)→ config QByteArray 键 → 0075c480 global_setting_get
//   → keyToValue(缺省 2 @0089f51x);退化为配置读面(CTerminalConfig
//   "tab.selectionBehaviorOnRemove" 缺省 2 — 枚举键面 qmo_extract
//   判例;深枚举登记 cited)。
//   openSessionLegPane = FUN_008d2e46(284B)真身:
//     pane 名腿 = sub_89e8c8(panel 名 startsWith "::" 0xd99dd1)→
//     param_2 直名;否则 8c9e64(objectName 去 "Window")→
//     sub_89e8de(pane 查建:"Terminal" → operator_new(0x270)
//     sub_835f5a(cited);"Editor" → 0x140 sub_5e5bb6(cited);
//     其他 startsWith("::") → 0x138 sub_891e22(cited);未中 → 0);
//     命中 → +0x9 = panel+0x31 byte + sub_8ca77c 下行(缺省目标
//     sub_8ca6ca:focusWidget 上溯 MuxPane 动态 cast;无 → +9 stack
//     当前 0x11ab360 查;下行 addWidget+activate 8b9f04 — MuxWindow
//     域 shim 判例同相,页挂面走宿主槽)+ vt+0x60 失败腿
//     (sub_5445f2 "Error" 0xc9d1a2 + setProperty dat_11820b0
//     "Discarded"/QVariant(true))+ param_3!=0 → sub_8c69fe(cited)。
//   本面以 MainWindowFace::Slots 承接宿主(页挂 = kitWindowAttachPage
//   现役面闭环 — 语料 pane+0x50/+9 槽对位 f50/f58;pane 查建产物
//   QWidget* 承载返回,真 KitWindow 类建模域 cited)。
QWidget *kitStartupOpenSession(MainWindowFace::Slots host,
                               QMainWindow *mainWindow,
                               const QString &paneName,
                               const QString &sessionName, bool select);

// 窗条切换腿(批 163 挂页宿主槽延伸:@008d34c3 vt+0x1d0 虚槽
// "MenuBar"/"StatusBar"/"ToolBar",!b 切换 — 槽位经 setProperty 承接
// 已落 kitStartupSessions;本函数 = 89f516 配置读腿复用面)。
int tabBarSelectionBehaviorOnRemove();

// FUN_008cba1c(253B,0028.c:12847)键前缀化真身:QByteArray 键 →
// QString → FUN_008c9e64(panel)objectName 去 "Window" →
// s_text_preferThemeFonts_760b2c(app,面板名,键)前缀面:
//   @00760b86 键 toLower → utf8;
//   @00760bf1 QRegularExpression("^kit(?=\.)") replace → 键含 "kit."
//             即剥前缀;
//   @00760c68 startsWith("text.")(DAT_00c8b3cb=.rodata "text." 实读)
//             且命中 font 键哈希表(12 键 text.caretPeriod…text.zoomFactor
//             @00760d77-77 实读)→ 前插 "<面板名>."(小写,@00760d39
//             insert 0)。
// 返回后 global_setting_get(app,键,缺省)(0075c480 = DAT_011c1240
// config guard + 0090e084 发射面 — 通路 = CTerminalConfig 值面,批 150
// wind.config 默认层判例;键未命中 → 缺省直返同相)。
QString kitScopedConfigValue(const QString &panelObjectName,
                             const QByteArray &key,
                             const QVariant &defaultValue);

// &4 尾段真身(00766c26 @00766f22-66f4c + 00766466/00766364):
//   >>QByteArray(sub)→ 子流:>>(bool fullscreen)→ FUN_00766466(
//   param_1 win,fullscreen):0 腿 isFullScreen→windowState^4 /
//   1 腿 |4 → setWindowState + show;>>(QByteArray geometry)
//   fullscreen==0 → QWidget::restoreGeometry(win,geometry);>>(bool
//   onTop)→ FUN_00766364(win,onTop)(X11 _NET_WM_STATE_ABOVE/
//   STAYS_ON_TOP XSendEvent — 平台面 cited,X11 only 语料);
//   >>(double)→ setWindowOpacity。
// 宿主窗 = QMainWindow(mainWindow 面;win+0x30 onTop 位缓存 cited —
//   宿主槽位未建模,X11 腿不落,行为同相:非 X11 环境语料同缺)。
void startupWindowTail(QMainWindow *mainWindow, QDataStream &in);


// FUN_0075e0f8(765B,0023.c:27251)建窗窄面:
//   operator_new(0xf0)+MainWindow ctor(0)(MainWindow 类未建模 —
//   KitWindowFace 承接,批 133 判例)+ FUN_00763b64(50B,0023.c:30939
//   = QList append)入窗表(宿主 +0x48 — Slots 无表建模 cited,本面
//   返回不挂表)+ geometry 非空 → restoreGeometry(成功即跳居中);
//   空腿 FUN_0075d6e8(74B,26718 = screen()->availableGeometry()
//   shared_null 卫)→ 宽 = (aw.w*4+0.5)/5(4/5 比例,ceil 双向四舍
//   五入语料代数直译)+ resize;高同;居中 = (左+右)/2 - w*0.5 /
//   (上+下)/2 - h*0.5 → move;尾 mainWindow_connectSignals(win)
//   (@27327 — 宿主信号装配,109B 面 FUN_007662e6 已落 MainWindowFace;
//   深装配链 cited — 宿主批域)。返回新窗(QMainWindow 承接 — 语料
//   MainWindow 0xf0 类未建模,KitWindowFace 抽象(menu() 纯虚)不可
//   实例化;QMainWindow = 语料基面同相,铁律 6 无落点退基面)。
QMainWindow *startupWindowCreate(QMainWindow *mainWindow,
                                 const QByteArray &geometry);
