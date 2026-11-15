#pragma once

#include <QString>

class QMessageBox;
class QWidget;

// MsgBoxFace — 语料富文本消息框族(批 317)。
// msgbox_buildRich(918B,0019.c:55557):
//   new QMessageBox(0)@00615d26;
//   三行 @00615d6a/00615dc1/00615e0e:tr("File name")(0xc90200)/
//     tr(<0xc9d3fe>)/tr("Remote path")(0xc9020a) 经 FUN_00615ad0(行拼,cited);
//   watcher==0 腿 @00615e4x:文案 tr(0xc90048)+ 图标 3 + 按钮 0x400 +
//     复选 tr("Stop watching this file")(0xc90216);
//   watcher!=0 腿 @00615e5d:文案 tr(0xc900a0)+ 图标 1 + 按钮 0x1c000;
//   正文 = "<pre>%1<br><table>"(0xc90228) 拼行 +
//     QString::fromUtf8(0xc8a3c9) 尾;
//   setAttribute(0x37,1)@00615f27;setWindowFlags(|0x40000)@00615f3x;
//   setText/setWindowTitle(tr("Upload File") 0xc90241)/setIcon/
//   setStandardButtons@00615f4x-5x;setCheckBox;主屏尺寸 setMinimumSize。
//   行拼/尾串两腿以 cited 注记,其余结构照录。
QMessageBox *msgboxBuildRich(const QString &name, const QString &remotePath,
                             const QString &third, bool watcher,
                             QWidget *parent = nullptr);
