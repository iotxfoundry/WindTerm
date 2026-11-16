#pragma once

#include <QByteArray>
#include <QString>
#include <QStringList>
#include <QWidget>

// 语料两个"窗条"类(批 446/447)。二者都是裸 QWidget 子类、以 **objectName**
// 自命名并注册(King__registerBarsAndPanes),不带布局装配。
//
// QuickBar — FUN_0056e26e(402B,0017.c:44048)ctor:
//   QWidget(parent,0) → vtable **QuickBar_vtable** + 副 01195a08 →
//   **+0x30 = parent(宿主)** → **+0x60 低 2 位清**(flags)→
//   **+0x68 = QList 空**(快捷项表,写侧 stateStoreSerializeQuickBar 读的就是它)→
//   setObjectName("QuickBar")(strlen 8 实读)→ King__registerBarsAndPanes("QuickBar").
//
// TransferBar — FUN_005858fe(449B,0017.c:60357)ctor:
//   QWidget(parent,0) → vtable **TransferBar_vtable** + 副 01196748 →
//   +0x30 = 0 / +0x38 = 0 → **+0x48 低 2 位清** → +0x50 = 空 QString →
//   setObjectName("TransferBar") → King__registerBarsAndPanes("TransferBar")。
class QuickBarFace : public QWidget {
	Q_OBJECT
public:
	explicit QuickBarFace(QWidget *parent = nullptr);
	QWidget *host30() const { return m_host30; }        // +0x30
	const QStringList &items68() const { return m_items68; } // +0x68
	void setItems(const QStringList &items) { m_items68 = items; }

protected:
	QWidget *m_host30 = nullptr;   // +0x30
	quint8 m_flags60 = 0;          // +0x60(低 2 位清)
	QStringList m_items68;         // +0x68
};

class TransferBarFace : public QWidget {
	Q_OBJECT
public:
	explicit TransferBarFace(QWidget *parent = nullptr);

protected:
	QWidget *m_f30 = nullptr;      // +0x30
	QWidget *m_f38 = nullptr;      // +0x38
	quint8 m_flags48 = 0;          // +0x48(低 2 位清)
	QString m_f50;                 // +0x50
};

// ------------------------------------------------ QuickBar 配置槽(批 479)
// 语料三个同型槽(各 190B),都是"复选框 → 写配置键":
//   s_quickbar_showMultipleGroups_6cf858 → **"quickbar.showMultipleGroups"**
//   s_quickbar_showGroupTitle_6cf926     → **"quickbar.showGroupTitle"**
//   s_quickbar_showCommandsInOrder_6cf9f5→ **"quickbar.showCommandsInOrder"**
// 写法统一:`globalSettingSet(qApp, 键, QVariant(bool), 0)`。
//
// 底层 FUN_0075c480(80B)=**带门的全局写**:
//   `if (FUN_005d972a(DAT_011c1240) /*设置已启用*/ || force)`
//     `FUN_0090e084(app, key, value)`(真实写入);返回是否写入。
namespace QuickBarSettings {
bool setGlobalSetting(const QByteArray &key, const QVariant &value, bool force = false);
void setShowMultipleGroups(bool on);
void setShowGroupTitle(bool on);
void setShowCommandsInOrder(bool on);
}
