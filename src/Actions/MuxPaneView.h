#pragma once

#include <QString>
#include <QWidget>

// MuxPaneView —— 语料 MuxPane 面板 widget(QWidget)真身(Phase 4c,mp lane)。
// 命名避让:src/Actions/MuxPane.h(批 50 壳;批 71 勘误后为主窗口宿主语义)
//   已占 "MuxPane" 类名,本类随笔记 §5 定名 MuxPaneView(记 QUIRKS)。
// 语料落点:
//   ctor            s_MuxPane_8de0c0(202B,decomp-part-0028.c:25440)
//   setCentralView  FUN_008de1a8(124B,0028:25489)
//   布局装配        FUN_008de052(86B,0028:25410,QVBoxLayout + setLayout)
//   计数器          FUN_008de0b0(16B,0028:25425,DAT_011be6c8 −1)
//   vt 族           PTR_FUN_011abbb8(与 TextView/ScintillaEditWatcher 同族
//                   —— MuxPane 为 TextView/EditorView 等面板基类)
// Ghidra 语料中 *(this)=011abbb8 / *(this+0x10)=011abd90 为 C++ vtable
//   表示,不落成员;真实成员仅 +0x30/+0x34/+0x38/+0x40。
// bootstrap 接线:paneMeta = &MuxPaneView::staticMetaObject 持有者,
//   经 attachJsEngine(下方)转入 JsEngine::bootstrap(s_MuxPane_64b102
//   批 39/68 收编面);调用时机语料锚见 attachJsEngine 注(cited 预留,
//   不发明触发时机)。

// MuxPane::Type 枚举(QMetaObject 权威值域未提取,笔记 §未解)→ int 别名
    // Type 值域(qmo_extract QMetaObject 权威,批 73 r4 lane)
        enum MuxPaneType : int {
            TypeUnknown = 0, TypeTerminal = 1, TypeTextEditor = 2,
            TypeTextFinder = 3, TypeTextViewer = 4
        };

class JsEngine;

class MuxPaneView : public QWidget {
    Q_OBJECT

public:
    explicit MuxPaneView(QWidget *parent, MuxPaneType type); // s_MuxPane_8de0c0(param_1,param_2,param_3)
    void setCentralView(QWidget *view);                      // FUN_008de1a8
    // 标题槽只读面:语料 FUN_008de3e8(0028:25642)跨对象直读页 +0x38
    //   (MuxPaneGroup::addTab 转写消费);本体无独立 getter 函数(inline 槽)。
    const QString &title() const { return m_title; }

    // cited 预留接线(库内零调用点,不发明触发时机):
    //   语料 FUN_00766192(0023:33030,65B)创建 JsEngine(0064ab10)
    //   存宿主 +0x48 后即调 s_MuxPane_64b102(pvVar1)(0023:33040-44);
    //   真实触发 = Application 单例信号 mainWindow_connectSignals
    //   (0023:36614,connectImpl → 宿主槽;入口 FUN_007662ce 24B,
    //   guard +0x80)—— 我方无 Application 类 → 本方法仅 cited 预留。
    // kingMeta 实参形态:语料 "King" 全局 = King 枚举命名空间级
    //   QMetaObject;src/Utility/KingEnums.h 45 枚举为纯 namespace
    //   (无 Q_NAMESPACE/Q_OBJECT 承载)→ 现无对象可传,调用方置
    //   nullptr(bootstrap 已按语料面判空),承载形态待勘定
    //   (cited — wave-2)。
    // paneMeta = 本持有者:语料 newQMetaObject(muxPaneMeta->
    //   metaObject()) 的注册对象即 MuxPane widget 类元对象 → this。
    void attachJsEngine(JsEngine *engine, QObject *kingMeta,
                        QObject *appBridge, QObject *windowBridge);

    // 主题目录装配期一次调用:FUN_00753fc6(0023:19097,387B)=
    //   applicationDirPath() + "/global/themes/"(ApplicationTheme
    //   +0x18 themes 列表)。语料构造链 _INIT_90(0051fba0,0016:13889)
    //   → FUN_007538f6(0023:18668,guard 单例)→ ApplicationTheme
    //   ctor FUN_00753706;本调用的确切语料触发函数未解(mp 笔记 §4/
    //   §未解)→ cited,库内由宿主装配位显式触发一次。
    static void initThemeDir();

private:
    int m_f30;                    // 语料 +0x30:FUN_008de0b0 返回值落点(DAT_011be6c8 计数;值语义未解,cited — wave-2)
    MuxPaneType m_type;           // 语料 +0x34:param_2(MuxPane::Type)
    QString m_title;              // 语料 +0x38:shared_null 起步;setter 面 = FUN_008de224(cited — wave-2,不在本批写域)
    QWidget *m_central = nullptr; // 语料 +0x40:central 槽(ctor 置 0)
};
