// SenderPaneFace.cpp — 发送器面板。

#include "Widgets/Panes/SenderPaneFace.h"

// 出处:QMetaObject 0x011a5c00(class="SenderPane",methods=16,signals=0,
// superdata=0x011ab900 KitPane);ctor 内联在调用点,仅转发基构造。
SenderPaneFace::SenderPaneFace(QWidget *parent)
    : KitPaneFace(parent)
{
}

// 0x0073591c(164B)dtor 真身 —— 字段释放面(见头文件外的说明):
//   vptr = &SenderPane_vtable;随后逐块释放自有字段(0x0075xxxx 区细节
//   未逐条转写);deleting 0x007359ca(23B) 末尾 operator_delete(_, size)。
SenderPaneFace::~SenderPaneFace() = default;

// 槽体重载链:全部转发到 0x0090a378(953B)的 switch。
// 每一组"带参 / 无参"是 moc 为**默认实参**生成的双记录,不是一个函数两个版本。
void SenderPaneFace::addSender(const QVariant &, const QVariant &, const QVariant &) { } // #0
void SenderPaneFace::addSender(const QVariant &, const QVariant &) { }                    // #1
void SenderPaneFace::addSender(const QVariant &) { }                                    // #2
void SenderPaneFace::clearSender(const QVariant &) { }                                  // #3
void SenderPaneFace::clearSender() { }                                                  // #4
bool SenderPaneFace::isSending(const QVariant &) { return false; }                       // #5
bool SenderPaneFace::isSending() { return false; }                                       // #6
void SenderPaneFace::removeSender(const QVariant &) { }                                 // #7
void SenderPaneFace::removeSender() { }                                                 // #8
QVariant SenderPaneFace::sender(const QVariant &) { return QVariant(); }                // #9
QVariant SenderPaneFace::sender() { return QVariant(); }                                // #10
int SenderPaneFace::senderCount() { return 0; }                                          // #11
void SenderPaneFace::startSender(const QVariant &) { }                                  // #12
void SenderPaneFace::startSender() { }                                                  // #13
void SenderPaneFace::stopSender(const QVariant &) { }                                   // #14
void SenderPaneFace::stopSender() { }                                                   // #15

// metasurface:metaObject 0x0090a360 → &PTR_staticMetaObject_011a5c00;
// qt_metacast 0x0090a76a;qt_metacall 0x0090a7ac(97B):16 条记录 →
//   0x0090a378;超出则返回 (index - 16)。
// vt6 0x0073558e(226B)= 事件处理(该面板的鼠标/绘制腿)。
