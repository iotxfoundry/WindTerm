#pragma once

#include <QBrush>
#include <QPointer>
#include <QString>
#include <QVariant>
#include <QWidget>

class QMenu;
class QPainterPath;
class QWidgetAction;

// SlipButtonFace — 自绘**拨动开关**(toggle switch)按钮。
//
// 出处:RTTI "SlipButton";staticMetaObject = PTR_staticMetaObject_0119d620。
// 语料里 ctor 被反编译器命名成 `overlay_makeBusyWidget`(005659d4,513B)
// —— 名不副实:它写 `&SlipButton_vtable`,是本类**构造函数**。
//
// QMetaObject 实读(rev=8,class="SlipButton",methods=2,signals=2,props=5):
//   信号 #0 clicked()      ← 发射器 008fae78(activate index 0)
//   信号 #1 toggled()      ← 发射器 008faeac(activate index 1)
//   属性 #0 checkedColor   QBrush   → 字段 +0x60
//   属性 #1 handleColor    QBrush   → 字段 +0x70
//   属性 #2 errorColor     QBrush   → 字段 +0x68
//   属性 #3 uncheckedColor QBrush   → 字段 +0x78
//   属性 #4 warningColor   QBrush   → 字段 +0x80
//   ⚠ 属性**声明序**必须按上表(0..4),因为 metacall 分发器按索引 switch
//     (008faee4),顺序错了颜色就全串位。
//
// 尺寸 sizeof(SlipButton) = 0xa0(dtor_deleting 的 operator_delete(_,0xa0))。
//
// 字段布局(ctor/dtor 双向实读;Qt5 下 QString/QVariant/QBrush 均为 8B):
//   +0x30 u8    旗标:低 3 位清后再置入 ctor 第 2 实参的最低位
//   +0x34 int   = 4
//   +0x38 QString   空
//   +0x40 QVariant  空
//   +0x48 int   = 0x80000000
//   +0x50 int   = 0 / +0x54 int = -1(语料按一个 8B 写入 0xffffffff00000000)
//   +0x58 int   = ctor 第 3 实参(开关当前值 / 变体号)
//   +0x60 QBrush checkedColor   = #007ACC
//   +0x68 QBrush errorColor     = #A52A2A
//   +0x70 QBrush handleColor    = QBrush(Qt::white)
//   +0x78 QBrush uncheckedColor = #444444
//   +0x80 QBrush warningColor   = 默认
//   +0x88 QPainterPath*         = nullptr(延后由 00565dc0 建)
//   +0x90 void*                 = nullptr
//   +0x98 void*                 = nullptr
class SlipButtonFace : public QWidget {
	Q_OBJECT

	// 顺序即属性索引(见头注 ⚠)。
	Q_PROPERTY(QBrush checkedColor MEMBER m_checkedColor)
	Q_PROPERTY(QBrush handleColor MEMBER m_handleColor)
	Q_PROPERTY(QBrush errorColor MEMBER m_errorColor)
	Q_PROPERTY(QBrush uncheckedColor MEMBER m_uncheckedColor)
	Q_PROPERTY(QBrush warningColor MEMBER m_warningColor)

public:
	// 005659d4(513B)—— 语料名 overlay_makeBusyWidget(名不副实,见头注)。
	SlipButtonFace(QWidget *parent, bool on, int variant);
	~SlipButtonFace() override; // 00565c0e(202B)

	QSize sizeHint() const override; // SlipButton_vt14(00565f64,350B)

	// 批 338:SlipButton 菜单行构建(slipButton_makeMenu,1023B)。
	static QMenu *makeMenu(QWidget *parent);

	// 008faee4(460B)—— QMetaObject 桥:按 (op, index) 分发。
	// op=0 发信号 / op=1 读属性 / op=2 写属性 / op=10 反查信号号。
	void metaDispatch(int op, int index, void **args);

	// 00565dc0(359B)—— 重建 QPainterPath(胶囊轨道 + 圆钮)。
	void updatePath();

private:
	void emitSignalAt(int index, uchar payload); // 008fae78 / 008faeac
	static int fontHeightOf(QWidget *w);         // 00565d00(146B)
	static int verticalSlack(QWidget *w);        // 00565da6(25B)

	// +0x30
	bool m_flag30 = false;
	// +0x34
	int m_f34 = 4;
	// +0x38
	QString m_f38;
	// +0x40
	QVariant m_f40;
	// +0x48
	int m_f48 = int(0x80000000);
	// +0x50 / +0x54
	int m_f50 = 0;
	int m_f54 = -1;
	// +0x58
	int m_f58 = 0;

	// +0x60..+0x80(顺序按**字段偏移**,不是属性索引)
	QBrush m_checkedColor;   // +0x60
	QBrush m_errorColor;     // +0x68
	QBrush m_handleColor;    // +0x70
	QBrush m_uncheckedColor; // +0x78
	QBrush m_warningColor;   // +0x80

	// +0x88
	QPainterPath *m_path88 = nullptr;
	// +0x90 / +0x98
	void *m_f90 = nullptr;
	void *m_f98 = nullptr;
};
