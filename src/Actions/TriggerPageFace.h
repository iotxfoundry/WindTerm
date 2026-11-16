#pragma once

#include <QMap>
#include <QWidget>

class QComboBox;
class QDoubleSpinBox;
class QAbstractItemView;
class QHBoxLayout;
class QTableWidget;
class QStackedLayout;
class QStackedWidget;
class QTabBar;
class QTabWidget;

// TriggerPageFace — 语料触发器页族共有面(批 341/342/343)。
//
// ctor FUN_006f1966(45B,0022.c:19227) 实测:
//   QWidget::QWidget(this,parent,0) → vptr = 0x11a47f0(vt0 ConnectionTriggerPage;
//   asm 0x6f66fe: mov $0x11a47e0 + lea 0x10 = 0x11a47f0) →
//   +0x10 副 vptr = 0x11a49b0 → +0x30 = 0。
//   各派生页 ctor 在 base 之后自写 vtable/副 vptr(见批 343 表)。
//
// 八页同族实证(批 342):8 个 dtor(FUN dtor 29B/dtor_deleting 47B,
//   006f66fe..006f6b9c) 汇编逐字节相同——均只写回同一 vptr 对
//   (0x11a47f0 / 0x11a49b0)后 jmp ~QWidget;差异仅在 operator_delete 尺寸
//   (见批 343 表,与 006f440e 的 operator_new 尺寸逐项一致)。
//
// 装配 FUN_006f1994(417B) 全量已转写 → assembleBusyOverlay。
// 遮罩信号槽 FUN_006f2be6(395B) 全量已转写 → onBusyStateChanged。
class TriggerPageFace : public QWidget {
	Q_OBJECT
public:
	explicit TriggerPageFace(QWidget *parent = nullptr); // FUN_006f1966

	// FUN_006f1994(417B):建遮罩(+0x30)+ 两路 connect + QHBoxLayout
	// (margins 全零 / addStretch(0) / addWidget(遮罩,0,0));返回布局,
	// 语料本函数**不**调 setLayout(由调用方接)。
	QHBoxLayout *assembleBusyOverlay();

	// FUN_006fde04(210B,0022.c:26743)ConnectionTriggerPage 装配:
	//   form = new QFormLayout(0x20)(父 0);
	//   +0x40 = new 0x78 + FUN_006fdcde(w, +0x38(kind), 0)(TriggerActionWidget 0x78);
	//   setContentsMargins(margins 全零);assembleBusyOverlay();
	//   form->addRow(子件);form->addRow(...);page->setLayout(form→实际接 form);
	//   page->setFocusProxy(page)。
	void assembleConnectionPage(int kind);

	// FUN_006fb180(438B,0022.c:25134)把动作件的字段绑定到文本面板:
	//   editor 空 → 返;fields = FUN_006f8c6c(actionWidget->+0x48, 空, 1);
	//   逐字段:name = field->property(...).toString();
	//     name 含 "arguments" → box = new 0x38 + FUN_006fad0a(box, editor, 0);
	//       boxlayout_insertRtlAware(field, box, 1)(插到字段布局);
	//       FUN_0058dac2(field, "${match}")(**属性值 = "${match}" 实读**);
	//   actionWidget->+0x58 非空 → 递归本函数。
	// FUN_006f8c6c(53B,0022.c:23884)取动作件字段表:
	//   qt_qFindChildren_helper(obj, name(空), smeta **01198660**, &list, flags)
	//   ⇒ findChildren<字段类*>(空名, 递归)。字段类 = smeta 01198660。
	// FUN_006f8c50(27B,0022.c:23868)释放该表:引用计数减到 0 → QListData::dispose。
	static QList<QWidget *> findActionFields(QWidget *actionWidget);
	static void releaseActionFields(QList<QWidget *> &fields);

	void bindEditorToActionWidget(TriggerActionWidgetFace *actionWidget, QWidget *editor);

	// FUN_006f1850(278B,0022.c:19193)文本面板 ↔ 页接线:
	//   connect(panel, 信号 FUN_008f0ffa, this, 闭包 FUN_006f77fd,
	//     smeta 01195800);
	//   connect(this, 信号 FUN_008ef838, this, 闭包 FUN_006f6c9e,
	//     smeta 01193440);
	//   FUN_006f7770(&this, panel->+0x50)(绑定文本目标)。
	void wireEditorDependents(QWidget *panel); // panel = TriggerActionEditPanelFace

	QWidget *busyOverlay() const { return m_busy30; }  // +0x30
	QWidget *actionWidget40() const { return m_action40; } // +0x40(0x78)

public slots:
	// FUN_006f2be6(395B) 遮罩信号(0x008faeac,单 bool 参)的槽 →
	// 遍历子件:QTableView 子类且带指定子件(0x1194e40)时
	// v ? selectRow(0) : clearSelection();其余子件(除 +0x30 遮罩)
	// 一律 setEnabled(v)。
	void onBusyStateChanged(bool v);

protected:
	QWidget *m_busy30 = nullptr; // +0x30(overlay_makeBusyWidget 0xa0)
	QWidget *m_action40 = nullptr; // +0x40(FUN_006fdcde 0x78)
};

// ---------------------------------------------------------------- 页种类表
// 006f440e(1804B) switch(param_2) 逐 case 实测:尺寸 = operator_new 实参,
// 标题 = tr 串(.rodata 实读),各页 ctor 之后自写 vtable + 副 vptr,
// 末接各自的装配腿。kind 7 **无 case**(落 default → 不建页)。
//
// kind | 类                        | new   | 副 vptr   | 标题(tr)            | 装配腿
// -----+---------------------------+-------+-----------+---------------------+--------
//  1   | ConnectionTriggerPage     | 0x48  | 0118c100  | &After connection   | FUN_006fde04
//  2   |   同上(kind 分支)          | 0x48  | 0118c100  | &After disconnection| FUN_006fde04
//  3   |   同上                     | 0x48  | 0118c100  | &Before connection  | FUN_006fde04
//  4   |   同上                     | 0x48  | 0118c100  | &Before disconnection| FUN_006fde04
//  5   | CustomLinkTriggerPage     | 0x58  | 0118c310  | &Custom Link        | FUN_00703d3e
//  6   | CustomMenuTriggerPage     | 0x60  | 0118c520  | &Custom Menu        | FUN_00703fb0
//  8   | HighlightTextTriggerPage  | 0x40  | 0118c730  | &Highlight Text     | FUN_006f7c3c
//  9   | PlaySoundTriggerPage      | 0x48  | 0118c940  | &Play Sound         | FUN_00704340
// 10   | RunCommandTriggerPage     | 0x50  | 0118cb50  | Run &Command        | FUN_006fe290
// 11   | SendTextTriggerPage       | 0x68  | 0118cd60  | &Send Text          | dialog_buildSpinForm
// 12   | ShowTooltipTriggerPage    | 0x60  | 0118cf70  | &Show Tooltip       | FUN_00703ab0
//
// 标题地址:1-4 = 0xc9fe89/0xc9fe9b/0xc9feb0/0xc9fec3(FUN_006fdf10 四 tr);
// 5-12 = 0xc9fb21/2e/3b/4b/57/64/6f(006f440e 逐 case tr)。kind 5 与 6 另接
// 第二条腿(6 多 FUN_006f79ec;9 多 FUN_006f7ea6)。kind 1-4 共用
// FUN_006fdf10(281B)= ConnectionTriggerPage ctor:+0x38 = kind。
enum class TriggerPageKind : int {
	AfterConnection = 1,
	AfterDisconnection = 2,
	BeforeConnection = 3,
	BeforeDisconnection = 4,
	CustomLink = 5,
	CustomMenu = 6,
	HighlightText = 8,
	PlaySound = 9,
	RunCommand = 10,
	SendText = 11,
	ShowTooltip = 12,
};

// TriggerPageStackFace — FUN_006f440e(1804B,0022.c:20784)页栈建页。
// **宿主已勘定为 TriggerDialogFace**(批 346:FUN_006f2dd4 ctor 实测
//   +0x30 QTabBar / +0x40 QStackedLayout / +0x88 QMap,与本文用例逐项吻合;
//   两者可视为同一类的行为面拆分)。字段由 asm 实读:
//   +0x30 QTabBar / +0x40 QStackedLayout / +0x88 QMap<int,QWidget*>
//   (节点 0x28:键 int @+0x18,值 ptr @+0x20)。
// 流程:命中 +0x88 → 复用;未命中 → 按 kind 建页 → 插表 → stack->addWidget;
// 两路合流:tabBar->setTabText(0, page->windowTitle())(asm 0x6f4550 xor esi,esi
// = 恒第 0 页)→ FUN_006f1b5a(page,状态)→ 页虚槽 +0x1a0(基类为
// __cxa_pure_virtual@0xbec350,各页覆写;cited)→ stack->setCurrentWidget(page)。
class TriggerPageStackFace {
public:
	// 返回新页/复用页;kind 无 case(7 等)→ nullptr(语料 default 直返)。
	QWidget *showPage(int kind, bool state, void *param4);

private:
	QWidget *createPage(int kind);

	QTabBar *m_tabBar30 = nullptr;          // +0x30
	QStackedLayout *m_stack40 = nullptr;    // +0x40
	QMap<int, QWidget *> m_pages88;         // +0x88
};

// TriggerActionWidgetFace — FUN_006fdcde(274B,0022.c:26700) ctor 全量实读:
//   QWidget(parent, 0) → vtable TriggerActionWidget_vtable + 副 vptr 0118bcc8 →
//   +0x30 = kind(int) → +0x50/+0x58/+0x60/+0x68/+0x70 = 0 →
//   build()(FUN_006fd6c0)→ connect(+0x38 QComboBox::currentIndexChanged →
//   +0x40 QStackedWidget::setCurrentIndex,闭包 impl FUN_006b6730,
//   smeta QComboBox)。dtor 族实测对象尺寸 0x78(与 new 0x78 一致)。
//
// 内部装配 FUN_006fd6c0(1203B,0022.c:26537) 实测:
//   form = new QFormLayout(0x20)(父 0);
//   label = new QLabel(0x30, tr("&Action:")(0xc9fe80), 0, 0);
//   +0x38 = new 0x48 + combo_makeSearchCombo(搜索下拉);
//   +0x40 = new QStackedWidget(0x30);  +0x48 = new QTabWidget(0x30);
//   三平台页签:addTab(FUN_006f8e30(this,"linux"),"&Linux"(0xc9d4aa))/
//     ("macos","&macOS"(0xc9d4cb))/("windows","&Windows"(ascii));
//   建页序 = int 表 @0xc9ff80 实读 {3, 2, 1, 4}:
//     sub=1 → new 0x70 + FUN_006f83b0(w,sub,(kind-1>3),0) → +0x58;+0x68 = w+0x40;
//     sub=2 → new QGroupBox + QVBoxLayout + new 0x50 + FUN_006cc226(w,0) → +0x50;
//             group->setLayout(vbox);(group 进 stack)
//     sub=4 → new 0x70 + FUN_006f83b0 → +0x60;+0x70 = w+0x40;
//     sub=3 → 无建件(直接入 stack);
//     每页入 stack 后 combo 追加一项(文案 = FUN_0069b57e/FUN_006f8cb4 链 tr,
//       data = sub);
//   门:kind == 10 只建 sub==3;kind ∈ 2..4 时不建 sub==4;
//   尾:@label->setBuddy(...);kind==10 → combo->findData(QVariant(3), 0x100,
//     0x10)(Qt::UserRole / Qt::MatchCaseSensitive)→ setCurrentIndex → hide();
//     form->setContentsMargins(全零);addRow ×3;setLayout(form);
//     setTabOrder(+0x38, +0x40);setFocusProxy(this)。
class TriggerActionWidgetFace : public QWidget {
	Q_OBJECT
public:
	explicit TriggerActionWidgetFace(int kind, QWidget *parent = nullptr); // FUN_006fdcde
	void build();                                                          // FUN_006fd6c0

	// FUN_006f8cb4(137B,0022.c:238xx)**整型键映射取值**(带缺省):
	//   m = 映射(map 非空 && 首节点 != end 才查);key 命中(node+0x20 == key)
	//   → 返回 node+0x18(值);否则 fallback(*param_4)。
	//   ⇒ 006fd6c0 里"每页入 combo 的文案"即 mapGetIntOr(kindNameMap, sub, 缺省)。
	static QString mapGetIntOr(const QMap<int, QString> &m, int key, const QString &fallback);

protected:
	int m_kind30 = 0;                    // +0x30
	QComboBox *m_combo38 = nullptr;      // +0x38(0x48 search combo)
	QStackedWidget *m_stack40 = nullptr; // +0x40
	QTabWidget *m_tabs48 = nullptr;      // +0x48
	QWidget *m_f50 = nullptr;            // +0x50(new 0x50 sub=2 件)
	QWidget *m_f58 = nullptr;            // +0x58(new 0x70 sub=1 件)
	QWidget *m_f60 = nullptr;            // +0x60(new 0x70 sub=4 件)
	QWidget *m_f68 = nullptr;            // +0x68(sub=1 件 +0x40)
	QWidget *m_f70 = nullptr;            // +0x70(sub=4 件 +0x40)
};

// SendTextTriggerPageFace — kind 11(new 0x68)装配 FUN_006f8590
//   (dialog_buildSpinForm,1013B,0022.c:23660) 全量实读:
//   form = QFormLayout(0x20);label1  tr("&Match:")(0xc9fd97,0x30);
//                               label2  tr("&Send:")(0xc9dafd,0x30);
//   +0x38 = new 0x68 + FUN_0056376e(w, 0xe000, 0)(文本域);+0x40 = w+0x40;
//   +0x48 = new 0x70 + FUN_006f83b0(w, 4, 1, 0);+0x50 = w+0x40;
//   +0x58 = new 0x48 combo_makeSearchCombo;+0x60 = new QDoubleSpinBox(0x30);
//   combo 三项(data 2/1/0)文案 = tr(0xc9fdd8 "Send after text match and next
//     command prompt" / 0xc9fe08 "Send after text match and next line break" /
//     0xc9fd9f "Send after text match ");
//   spin:setSuffix("s") / setDecimals / setMinimum(0.0) /
//     setMaximum(999999.9) / setSingleStep(0.1);
//   label->setBuddy ×2;+0x38 非空 → FUN_006f1850(+0x48);
//   form margins 全零;assembleBusyOverlay(FUN_006f1994);addRow ×4;
//   另两行表头 tr("Send &Condition:")(0xc9fdb6)/tr("Send &Later:")(0xc9fdc7);
//   setLayout(form);setTabOrder(+0x40,+0x50)→(+0x50,+0x58)→(+0x58,+0x60);
//   setFocusProxy(this)。
// TextMarkTablePanelFace — FUN_005675e8(69B,0017.c:39545)ctor:
//   FUN_00584e4a(this, 0x48f, parent)(上表件基类)→
//   vtable **TextMarkTablePanel_vtable** + 副 01196288 →
//   FUN_00567386(577B)/FUN_00567084(683B)(装配腿,cited)。尺寸 0x48。
//   即 HighlightText 页的 +0x38 "规则表"。
class TextMarkTablePanelFace : public TriggerTableWidgetFace {
	Q_OBJECT
public:
	explicit TextMarkTablePanelFace(QWidget *parent = nullptr);

protected:
	// FUN_00567386(577B)/FUN_00567084(683B) 装配腿 — cited
};

// TriggerTableWidgetFace — FUN_00584e4a(74B,0017.c:59880)ctor(自定义**表格**件):
//   FUN_0053397c(this, flags, 0, parent)(基类装配;语料 flags 恒 **0x48f**)→
//   vtable 0119d678 + 副 0119d828 → 三条初始化腿(FUN_00584e0a/00584cb6/
//   00584c96,均 cited)。dtor 实测尺寸 **0x48**。
//   即 PlaySound(+0x38)/CustomMenu(+0x48) 的表件,也是 TextMarkTablePanel 基类。
//   基类为表格:语料直接在其上调用 setColumnCount/setHorizontalHeaderLabels/
//   rowCount,故以 QTableWidget 承接。占位绘制见 FUN_00566d84(97B):
//   rowCount()==0 且占位串非空 → 在 viewport 上以主题绘制该串并 return;
//   否则走 QTableView::paintEvent。
class TriggerTableWidgetFace : public QTableWidget {
	Q_OBJECT
public:
	explicit TriggerTableWidgetFace(int flags = 0x48f, QWidget *parent = nullptr);

	void setPlaceholder(const QString &text);  // FUN_00566d6e(22B)

protected:
	void paintEvent(QPaintEvent *e) override;   // FUN_00566d84(97B)
	void showEvent(QShowEvent *e) override;     // FUN_00566de6(163B)

	int m_flags = 0x48f;
	QString m_placeholder;                      // +0x38(语料槽位)
	bool m_needResize30 = true;                 // +0x30(首show 后置 0)
};

// MarkStyleWidgetFace — FUN_00703a58(55B,0022.c:29996)ctor:
//   QWidget(parent, 0) → vtable **MarkStyleWidget_vtable** + 副 vptr 0118b8c8 →
//   assemble()(FUN_00703900,268B)。dtor 实测尺寸 **0x40**。
//   即 CustomLink/ShowTooltip 页的 "+0x50/+0x58 附件"(标记样式件)。
class MarkStyleWidgetFace : public QWidget {
	Q_OBJECT
public:
	explicit MarkStyleWidgetFace(QWidget *parent = nullptr);
	void assemble(); // FUN_00703900

protected:
	// FUN_00703900(268B)内部装配 — cited(见 .cpp 注)
};

// TriggerActionEditPanelFace — FUN_0056376e(90B,0017.c:36762)ctor(名不副实:
//   Ghidra 取名来自 metaObject 指针;实体是**触发器动作文本面板**,尺寸 0x68):
//   FUN_0053397c(this, flags, 0, parent)(基类装配;0xe000 = 页内文本域旗标) →
//   metaObject = TriggerActionEditPanel_metaObject(011955f8)+ 副 vptr 011957a8 →
//   **+0x48 = 0x0101**(两 bool)→ +0x50/+0x58/+0x60 = 空 QString →
//   s_king__visible_56325c(this)。
//   五个动作页的 +0x38 文本域即本类(批 377 起以本类替换裸 QWidget)。
class TriggerActionEditPanelFace : public QWidget {
	Q_OBJECT
public:
	explicit TriggerActionEditPanelFace(int flags, QWidget *parent = nullptr);

	// FUN_006f83b0(412B,0022.c:23612)**同名类的第二构造**(带 kind):
	//   FUN_0056376e(this, active ? 0x11800 : 0xFFFF1800, parent)(基类)→
	//   vtable TriggerActionEditPanel_vtable + 副 0118bac8 →
	//   **+0x68 = kind** →
	//   示例样板按 kind:1 → 提示 "%1\nhttp://www.sample.com" /
	//     脚本 "%1\n() => {\n return `https://www.sample.com`;\n}"(0x18/0x2e 实读);
	//     4 → 提示 "%1\necho command\\n" /
	//     脚本 "%1\n() => {\n return `echo command\\n`;\n}"(0x11/0x26 实读);
	//   tr("E.g.:")(0xc9fc02).arg(样板) → FUN_005631dc / FUN_0056321c 两路写入。
	//   即 SendText/CustomLink/CustomMenu/ShowTooltip 页 +0x48/+0x70 的字段件。
	TriggerActionEditPanelFace(int kind, bool active, QWidget *parent);

	bool f48a() const { return m_f48a; }  // +0x48 低字节(0x0101)
	bool f48b() const { return m_f48b; }  // +0x49 高字节

protected:
	int m_kind68 = 0;     // +0x68(仅带 kind 构造置位)
	bool m_f48a = true;   // +0x48
	bool m_f48b = true;   // +0x49
	QString m_f50;        // +0x50
	QString m_f58;        // +0x58
	QString m_f60;        // +0x60
};

// CustomLinkTriggerPageFace — kind 5(new 0x58)装配 FUN_00703d3e(379B):
//   form;label = QLabel(tr("&Match:")(0xc9fd97));
//   +0x38 = new 0x68 + FUN_0056376e(w, 0xe000, 0)(文本域);+0x40 = w+0x40;
//   +0x48 = new 0x78 + FUN_006fdcde(w, **5**, 0)(TriggerActionWidget,kind 5);
//   +0x50 = new 0x40 + FUN_00703a58(w, 0)(0x40 附件);
//   setBuddy;FUN_006fb180(+0x48, +0x38);margins 全零;assembleBusyOverlay();
//   addRow ×4;setLayout;setTabOrder(+0x40→+0x48→+0x50);setFocusProxy。
class CustomLinkTriggerPageFace : public TriggerPageFace {
	Q_OBJECT
public:
	explicit CustomLinkTriggerPageFace(QWidget *parent = nullptr);
	void assembleCustomLinkPage(); // FUN_00703d3e

protected:
	TriggerActionEditPanelFace *m_edit38 = nullptr; // +0x38(0x68 文本面板)
	QWidget *m_f40 = nullptr;                      // +0x40(文本域 +0x40)
	TriggerActionWidgetFace *m_action48 = nullptr; // +0x48(0x78,kind 5)
	QWidget *m_f50 = nullptr;                      // +0x50(0x40 附件)
};

// CustomMenuTriggerPageFace — kind 6(new 0x60)装配 FUN_00703fb0(683B):
//   form;l1 = tr("&Match:")(0xc9fd97);l2 = tr("&Actions:")(0xc9ff05);
//   src = FUN_006f7830(this)(行源/模型,cited);
//   +0x38 = new 0x68 + FUN_0056376e(0xe000)(文本域);+0x40 = w+0x40;
//   +0x48 = new 0x48 + FUN_00584e4a(w, **0x48f**, 0)(表件);
//   +0x50 = new 0x40 + FUN_00703a58(w, 0);
//   两 label setBuddy;
//   两列表头 = tr("Label")(0xd0e72f) / tr("Action")(0xc9fcf1) →
//     qlist_appendRange → FUN_00584ee8(+0x48);
//   FUN_00533a0c(+0x48, 1, src)(表 → 行源);
//   FUN_00566d6e(+0x40, tr("No action available")(0xc9ff0f))(占位);
//   margins 全零;assembleBusyOverlay();addRow ×5;setLayout;
//   setTabOrder(+0x40 → +0x50 → +0x58);setFocusProxy。
class CustomMenuTriggerPageFace : public TriggerPageFace {
	Q_OBJECT
public:
	explicit CustomMenuTriggerPageFace(QWidget *parent = nullptr);
	void assembleCustomMenuPage(); // FUN_00703fb0
	// FUN_006f7830(394B,0022.c:23219)CustomMenu 页的"新增"菜单:
	//   menu = new QMenu(0x30, this);
	//   a1 = addAction(tr("Add &Action")(0xc9fcec))
	//     → connect(triggered → 闭包 FUN_006ff6a9);
	//   a2 = addAction(tr("Add &Separator")(0xc9fcf8))
	//     → connect(triggered → 闭包 FUN_006fb146);
	//   返回 menu(供"+"钮弹出)。
	class QMenu *makeAddMenu();

protected:
	QWidget *m_edit38 = nullptr;  // +0x38(0x68 文本域)
	QWidget *m_f40 = nullptr;     // +0x40
	TriggerTableWidgetFace *m_table48 = nullptr; // +0x48(0x48 表件,0x48f)
	QWidget *m_f50 = nullptr;     // +0x50(0x40 附件)
	QWidget *m_f58 = nullptr;     // +0x58(行源件,FUN_006f7830)
};

// PlaySoundTriggerPageFace — kind 9(new 0x48)装配 FUN_00704340(470B):
//   form;label = QLabel(tr("&Rules:")(0xc9fd07));
//   +0x38 = new 0x48 + FUN_00584e4a(w, **0x48f**, 0)(表件);+0x40 = w+0x40;
//   label setBuddy;
//   三列表头 = tr("Pattern")(0xd0daab) / tr("Description")(0xc8a3a0) /
//     tr("Sound")(0xc9fb51) → qlist_appendRange → FUN_00584ee8(+0x38);
//   FUN_00566d6e(+0x40, tr("No sound available")(0xc9ff23))(占位文案);
//   margins 全零;assembleBusyOverlay();addRow ×4;setLayout;setFocusProxy。
class PlaySoundTriggerPageFace : public TriggerPageFace {
	Q_OBJECT
public:
	explicit PlaySoundTriggerPageFace(QWidget *parent = nullptr);
	void assemblePlaySoundPage(); // FUN_00704340

protected:
	TriggerTableWidgetFace *m_table38 = nullptr; // +0x38(0x48 表件,0x48f)
	QWidget *m_f40 = nullptr;     // +0x40(表内视图)
};

// ShowTooltipTriggerPageFace — kind 12(new 0x60)装配 FUN_00703ab0(489B):
//   form;l1 = tr("&Match:")(0xc9fd97);l2 = tr("&Tooltip:")(0xc9fefb);
//   +0x38 = new 0x68 + FUN_0056376e(0xe000)(文本域);+0x40 = w+0x40;
//   +0x48 = new 0x70 + FUN_006f83b0(w, **5**, 1, 0);+0x50 = w+0x40;
//   +0x58 = new 0x40 + FUN_00703a58(w, 0);
//   两 label setBuddy;+0x38 非空 → FUN_006f1850(+0x48);
//   margins 全零;assembleBusyOverlay();addRow ×5;setLayout;
//   setTabOrder(+0x40 → +0x50 → +0x58);setFocusProxy。
class ShowTooltipTriggerPageFace : public TriggerPageFace {
	Q_OBJECT
public:
	explicit ShowTooltipTriggerPageFace(QWidget *parent = nullptr);
	void assembleShowTooltipPage(); // FUN_00703ab0

protected:
	TriggerActionEditPanelFace *m_edit38 = nullptr; // +0x38(0x68 文本面板)
	QWidget *m_f40 = nullptr;    // +0x40
	QWidget *m_f48 = nullptr;    // +0x48(0x70)
	QWidget *m_f50 = nullptr;    // +0x50
	QWidget *m_f58 = nullptr;    // +0x58(0x40 附件)
};

// HighlightTextTriggerPageFace — kind 8(new 0x40)装配 FUN_006f7c3c(243B):
//   form = QFormLayout(0x20);label = QLabel(0x30, tr("&Rules:")(0xc9fd07));
//   +0x38 = new 0x48 + FUN_005675e8(w, 0)(规则表件);
//   label->setBuddy(+0x38);form margins 全零;assembleBusyOverlay();
//   addRow ×2;setLayout(form);setFocusProxy(this)。
class HighlightTextTriggerPageFace : public TriggerPageFace {
	Q_OBJECT
public:
	explicit HighlightTextTriggerPageFace(QWidget *parent = nullptr);
	void assembleHighlightPage(); // FUN_006f7c3c

protected:
	TextMarkTablePanelFace *m_rules38 = nullptr; // +0x38(0x48 规则表)
};

// RunCommandTriggerPageFace — kind 10(new 0x50)装配 FUN_006fe290(327B):
//   form;label = QLabel(0x30, tr("&Match:")(0xc9fd97));
//   +0x38 = new 0x68 + FUN_0056376e(w, 0xe000, 0)(文本域);+0x40 = w+0x40;
//   +0x48 = new 0x78 + FUN_006fdcde(w, **10**, 0)(TriggerActionWidget,kind 10);
//   label->setBuddy(+0x38);FUN_006fb180(+0x48, +0x38)(动作件 ↔ 文本域接线);
//   margins 全零;assembleBusyOverlay();addRow ×3;setLayout(form);
//   setTabOrder(+0x40, +0x48)。
class RunCommandTriggerPageFace : public TriggerPageFace {
	Q_OBJECT
public:
	explicit RunCommandTriggerPageFace(QWidget *parent = nullptr);
	void assembleRunCommandPage(); // FUN_006fe290

protected:
	TriggerActionEditPanelFace *m_edit38 = nullptr; // +0x38(0x68 文本面板)
	QWidget *m_f40 = nullptr;                 // +0x40(文本域 +0x40)
	TriggerActionWidgetFace *m_action48 = nullptr; // +0x48(0x78,kind 10)
};

class SendTextTriggerPageFace : public TriggerPageFace {
	Q_OBJECT
public:
	explicit SendTextTriggerPageFace(QWidget *parent = nullptr);
	void assembleSendTextPage(); // FUN_006f8590

protected:
	QWidget *m_edit38 = nullptr;      // +0x38(0x68 文本域;语料 +0x40 = 其内部件)
	QWidget *m_f48 = nullptr;         // +0x48(new 0x70,FUN_006f83b0(4,1);+0x50 = 其 +0x40)
	QComboBox *m_combo58 = nullptr;   // +0x58(0x48 search combo)
	QDoubleSpinBox *m_spin60 = nullptr; // +0x60(QDoubleSpinBox 0x30)
};

// ---------------------------------------------------------------- 表格助手
// FUN_00584ee8(159B,0017.c:59935)表格初始化(PlaySound/CustomMenu 页共用):
//   setColumnCount(labels.size());setHorizontalHeaderLabels(labels);
//   setSelectionMode(1 /*SingleSelection*/);
//   水平头:setHighlightSections(true)/setStretchLastSection(true)/
//     setSectionResizeMode(0 /*Interactive*/)/setDefaultAlignment(1);
//   水平头 show()/垂直头 hide()。
namespace TriggerWidgetKit {
void setupTable(QTableWidget *table, const QStringList &labels);

// FUN_00566d6e(22B,0017.c:39167)占位文案:`view->+0x38 = text;view->update()`。
//   配套绘制 FUN_00566d84(97B):rowCount()==0 且 +0x38 非空 →
//   viewport 上以主题绘制该文案(即 "No sound available"/"No action available"
//   的实际显示路径;DAT_011c1ce0 = 主题单例)。
void setPlaceholder(QAbstractItemView *view, const QString &text);
}
