// entry=00768f44 size=475  (decompiled by Ghidra package ghidra, Utility, version 12.1.4)

void FUN_00768f44(QMainWindow *param_1,undefined8 param_2)

{
  undefined8 uVar1;
  double dVar2;
  QByteArray local_50 [8];
  QVariant local_48 [16];
  QVariant local_38 [16];
  
  QMainWindow::QMainWindow(param_1,param_2,0);
  *(undefined ***)param_1 = &PTR_FUN_011a69f8;
  *(undefined ***)(param_1 + 0x10) = &PTR_FUN_011a6bb0;
  *(undefined2 *)(param_1 + 0x30) = 0;
  param_1[0x32] = (QMainWindow)0x0;
  *(undefined8 **)(param_1 + 0x38) = &QArrayData::shared_null;
  *(undefined8 **)(param_1 + 0x40) = &QArrayData::shared_null;
  *(undefined8 *)(param_1 + 0x48) = 0;
  *(undefined8 *)(param_1 + 0x50) = 0;
  *(undefined8 *)(param_1 + 0x58) = 0;
  *(undefined8 *)(param_1 + 0x60) = 0;
  *(undefined8 *)(param_1 + 0x68) = 0;
  *(undefined8 *)(param_1 + 0x70) = 0;
  *(undefined8 *)(param_1 + 0x78) = 0;
  *(undefined8 *)(param_1 + 0x80) = 0;
  *(undefined8 *)(param_1 + 0x88) = 0;
  *(undefined8 *)(param_1 + 0x90) = 0;
  *(undefined8 *)(param_1 + 0x98) = 0;
  *(undefined8 **)(param_1 + 0xa0) = &QArrayData::shared_null;
  *(undefined8 *)(param_1 + 0xa8) = 0;
  *(undefined8 *)(param_1 + 0xb0) = 0;
  *(undefined8 *)(param_1 + 0xb8) = 0;
  *(undefined8 *)(param_1 + 0xc0) = 0;
  *(undefined8 *)(param_1 + 200) = 0;
  *(undefined8 *)(param_1 + 0xd0) = 0;
  *(undefined8 **)(param_1 + 0xd8) = &QListData::shared_null;
  *(undefined8 *)(param_1 + 0xe0) = 0;
  *(undefined8 *)(param_1 + 0xe8) = 0;
                    /* try { // try from 0076905c to 00769075 has its CatchHandler @ 0076911f */
  uVar1 = FUN_0075bd66();
  QVariant::QVariant(local_38,1);
                    /* try { // try from 0076908d to 00769091 has its CatchHandler @ 00769137 */
  QByteArray::QByteArray(local_50,"application.windowOpacity",-1);
                    /* try { // try from 007690a3 to 007690a7 has its CatchHandler @ 0076912f */
  FUN_0075c458(local_48,uVar1,local_50,local_38);
                    /* try { // try from 007690ad to 007690b1 has its CatchHandler @ 00769127 */
  dVar2 = (double)QVariant::toDouble((bool *)local_48);
  QVariant::~QVariant(local_48);
  FUN_005249c0(local_50);
  QVariant::~QVariant(local_38);
  if ((0.0 < dVar2) && (dVar2 < 1.0)) {
    QWidget::setWindowOpacity(dVar2);
  }
                    /* try { // try from 007690fb to 0076911c has its CatchHandler @ 0076911f */
  QWidget::setAttribute(param_1,0x37,1);
  FUN_00768cb6(param_1);
  return;
}


