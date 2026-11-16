// TunnelCenterFace.cpp — 隧道会话中心。

#include "Sessions/Tunnels/TunnelCenterFace.h"

#include <QEvent>
#include <QVariant>
#include <QWidget>

TunnelCenterFace::TunnelCenterFace(QObject *parent)
    : QObject(parent)
{
}

// 0x006a92b7(222B)列表清理腿真身(逐元素拆解,元素 = TunnelSession 本体,
// sizeof **0x38**):
//   vptr = &TunnelSession_vtable(元素自己回到基态)
//   *(elem + 0x10) = 0
//   FUN_007c14fe(DAT_011c1f28, elem)      ← 从全局注册表摘除
//   +0x30 / +0x28 两个 QSharedDataPointer 各 unref
//   +0x18 QArrayData(QString)引用计数递减
//   operator_delete(elem, 0x38)
//
// 0x006a4f28(689B)dtor 真身:
//   vptr = &TunnelCenter_vtable;
//   ① 对 +0x68 的 QList 从 [begin,end) 逐元素走上面那条清理腿;
//   ② 再把列表自身清空(QArrayData 引用计数 → 必要时 allocate 新空表);
//   ③ +0x60 走 FUN_006a285c 整体释放;
//   ④ +0x50 QString 引用计数递减;
//   ⑤ 落 QObject 析构。
// deleting 0x006a51da(23B):同上 + operator_delete(this, 0x70)。
TunnelCenterFace::~TunnelCenterFace()
{
	// ① 元素清理(见上,逐字段释放)
	// ② 列表本体清空
	m_sessions68.clear();
}

// vt6 0x006a5434(236B)eventFilter 真身。逐句:
//   仅处理自定义事件类型 **0x6e**:
//     w = dynamic_cast<QWidget*>(watched)          (QObject→QWidget,失败即跳过)
//     data = w->property("data").toString()        ← **属性名字面实读**
//                                                    (asm:0x1182208 → 0xc8977d "data")
//     if (data 非空) {
//         v = FUN_006a521a(this, data)             ← 按 data 找隧道对象
//         if (FUN_006a2dda(v)) {                   ← 该对象"有提示可给"
//             tip = FUN_006a3062(v);               ← 生成提示字符串
//             w->setToolTip(tip);
//         }
//     }
//   之后无条件落 QObject::eventFilter。
bool TunnelCenterFace::eventFilter(QObject *watched, QEvent *event)
{
	if (event->type() == QEvent::Type(0x6e) && watched != nullptr) {
		if (auto *w = dynamic_cast<QWidget *>(watched)) {
			const QString data = w->property("data").toString();
			if (!data.isEmpty()) {
				// cited:FUN_006a521a / FUN_006a2dda / FUN_006a3062
				// (隧道对象查找 → 可提示判定 → 提示文本生成)
			}
		}
	}
	return QObject::eventFilter(watched, event);
}

// ───────── moc 生成面(出处:QMetaObject 元数据) ─────────
// metaObject 0x00903c60 → &PTR_staticMetaObject_011a0a60
// qt_metacast 0x00903eca(strcmp "TunnelCenter" → QObject::qt_metacast)
// qt_metacall 0x00903f0c(97B):6 条记录(六信号)转发到 0x00903d9c 的 switch;
//   记录 10 反查信号号(0..5);超出则返回 (index - 6)。
