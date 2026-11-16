#pragma once

#include <QWidget>

// KitPaneFace — 主窗口右侧/底部"面板"基类(RTTI "KitPane")。
//
// 出处:QMetaObject 0x011ab900(rev=8,class="KitPane",methods=2,**signals=2**,
// props=0,superdata=0 ⇒ 直接派生自 QWidget);
// metacast 0x0091d3e2(s_KitPane_91d3e2);metacall 0x0091d38c(86B);
// 两个信号发射器 0x0091d368(idx 0)/ 0x0091d378(idx 1)。
//
// 信号(串表实读):
//   #0 hideRequest()        — 请求隐藏本面板
//   #1 focusViewRequest()   — 请求把焦点交给面板内的视图
//
// 继承关系(由子类 QMetaObject 的 superdata 反查,权威):
//   QWidget → KitPane → ExplorerPane(metacast 0x00909b3c,strcmp "ExplorerPane")
//   QWidget → KitPane → OutlinePane  (superdata 0x011ab900)
//   QWidget → KitPane → SearchPane   (superdata 0x011ab900)
//
// 字段(两个子类 dtor 实读,均为基类成员):
//   +0x50 引用计数件指针(dtor:*p -= 1,归零 operator_delete(p))
//   +0x70 intrusive 引用计数件(dtor:两处计数各减一,vtable+0x10 析构体,
//        计数归零走 vtable+0x18 释放器 —— 与 std::_Sp_counted_base 同形)
class KitPaneFace : public QWidget {
	Q_OBJECT

public:
	explicit KitPaneFace(QWidget *parent = nullptr);
	~KitPaneFace() override;

signals:
	void hideRequest();      // 0x0091d368(activate idx 0)
	void focusViewRequest(); // 0x0091d378(activate idx 1)

protected:
	void *m_f50 = nullptr; // +0x50 引用计数件
	void *m_f70 = nullptr; // +0x70 intrusive 计数件
};
