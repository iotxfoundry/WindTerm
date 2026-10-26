// entry=008cd068 size=1010  (decompiled by Ghidra package ghidra, Utility, version 12.1.4)

void FUN_008cd068(QWidget *param_1)

{
  undefined8 uVar1;
  QSplitter *pQVar2;
  void *pvVar3;
  undefined4 *puVar4;
  undefined4 local_64;
  undefined4 local_60 [2];
  code *local_58;
  undefined8 local_50;
  undefined8 *local_48;
  undefined8 local_40;
  
  pQVar2 = operator_new(0x30);
                    /* try { // try from 008cd08b to 008cd08f has its CatchHandler @ 008cd45a */
  QSplitter::QSplitter(pQVar2,(QWidget *)0x0);
  *(QSplitter **)(param_1 + 0x38) = pQVar2;
  pQVar2 = operator_new(0x30);
                    /* try { // try from 008cd0a6 to 008cd0aa has its CatchHandler @ 008cd49a */
  QSplitter::QSplitter(pQVar2,(QWidget *)0x0);
  *(QSplitter **)(param_1 + 0x40) = pQVar2;
  pQVar2 = operator_new(0x30);
                    /* try { // try from 008cd0c1 to 008cd0c5 has its CatchHandler @ 008cd47a */
  QSplitter::QSplitter(pQVar2,(QWidget *)0x0);
  *(QSplitter **)(param_1 + 0x48) = pQVar2;
  pQVar2 = operator_new(0x30);
                    /* try { // try from 008cd0dc to 008cd0e0 has its CatchHandler @ 008cd48a */
  QSplitter::QSplitter(pQVar2,(QWidget *)0x0);
  *(QSplitter **)(param_1 + 0x50) = pQVar2;
  pvVar3 = operator_new(0x38);
                    /* try { // try from 008cd0f7 to 008cd0fb has its CatchHandler @ 008cd46a */
  FUN_005a1c00(pvVar3,0);
  *(void **)(param_1 + 0x58) = pvVar3;
  pvVar3 = operator_new(0x38);
                    /* try { // try from 008cd112 to 008cd116 has its CatchHandler @ 008cd492 */
  FUN_005a1c00(pvVar3,0);
  *(void **)(param_1 + 0x60) = pvVar3;
  pvVar3 = operator_new(0x38);
                    /* try { // try from 008cd12d to 008cd131 has its CatchHandler @ 008cd472 */
  FUN_005a1c00(pvVar3,0);
  *(void **)(param_1 + 0x68) = pvVar3;
  QSplitter::setChildrenCollapsible(SUB81(*(undefined8 *)(param_1 + 0x48),0));
  FUN_005a1c6c(*(undefined8 *)(param_1 + 0x58),1);
  uVar1 = *(undefined8 *)(param_1 + 0x58);
  local_58 = FUN_008f6af8;
  local_50 = 0;
  local_48 = (undefined8 *)0x229;
  local_40 = 0;
  puVar4 = operator_new(0x20);
  *puVar4 = 1;
  *(code **)(puVar4 + 2) = FUN_008d5e00;
  *(undefined8 **)(puVar4 + 4) = local_48;
  *(undefined8 *)(puVar4 + 6) = local_40;
  QObject::connectImpl
            ((Connection *)local_60,uVar1,&local_58,param_1,&local_48,puVar4,0,0,
             &PTR_staticMetaObject_011981a0);
  QMetaObject::Connection::~Connection((Connection *)local_60);
  uVar1 = *(undefined8 *)(param_1 + 0x60);
  local_58 = FUN_008f6af8;
  local_50 = 0;
  local_48 = (undefined8 *)0x229;
  local_40 = 0;
  puVar4 = operator_new(0x20);
  *puVar4 = 1;
  *(code **)(puVar4 + 2) = FUN_008d5e00;
  *(undefined8 **)(puVar4 + 4) = local_48;
  *(undefined8 *)(puVar4 + 6) = local_40;
  QObject::connectImpl
            ((Connection *)local_60,uVar1,&local_58,param_1,&local_48,puVar4,0,0,
             &PTR_staticMetaObject_011981a0);
  QMetaObject::Connection::~Connection((Connection *)local_60);
  uVar1 = *(undefined8 *)(param_1 + 0x68);
  local_58 = FUN_008f6af8;
  local_50 = 0;
  local_48 = (undefined8 *)0x229;
  local_40 = 0;
  puVar4 = operator_new(0x20);
  *puVar4 = 1;
  *(code **)(puVar4 + 2) = FUN_008d5e00;
  *(undefined8 **)(puVar4 + 4) = local_48;
  *(undefined8 *)(puVar4 + 6) = local_40;
  QObject::connectImpl
            ((Connection *)local_60,uVar1,&local_58,param_1,&local_48,puVar4,0,0,
             &PTR_staticMetaObject_011981a0);
  QMetaObject::Connection::~Connection((Connection *)local_60);
  QSplitter::setOrientation(*(undefined8 *)(param_1 + 0x38),2);
  QSplitter::setOrientation(*(undefined8 *)(param_1 + 0x40),2);
  QSplitter::setOrientation(*(undefined8 *)(param_1 + 0x60),2);
  QSplitter::setOrientation(*(undefined8 *)(param_1 + 0x68),2);
  QSplitter::addWidget(*(QWidget **)(param_1 + 0x60));
  QSplitter::addWidget(*(QWidget **)(param_1 + 0x58));
  QSplitter::addWidget(*(QWidget **)(param_1 + 0x58));
  QSplitter::addWidget(*(QWidget **)(param_1 + 0x58));
  QSplitter::addWidget(*(QWidget **)(param_1 + 0x68));
  QSplitter::addWidget(*(QWidget **)(param_1 + 0x68));
  local_58 = (code *)&QListData::shared_null;
  local_64 = 1000;
                    /* try { // try from 008cd3b5 to 008cd3df has its CatchHandler @ 008cd482 */
  FUN_0057e490(&local_58,&local_64);
  local_60[0] = 4000;
  FUN_0057e490(&local_58,(Connection *)local_60);
  local_48 = (undefined8 *)CONCAT44(local_48._4_4_,1000);
  FUN_0057e490(&local_58,&local_48);
  local_48 = &QListData::shared_null;
  local_64 = 4000;
                    /* try { // try from 008cd3f3 to 008cd43a has its CatchHandler @ 008cd462 */
  FUN_0057e490(&local_48,&local_64);
  local_60[0] = 2000;
  FUN_0057e490(&local_48,(Connection *)local_60);
  QSplitter::setSizes(*(QList **)(param_1 + 0x58));
  QSplitter::setSizes(*(QList **)(param_1 + 0x60));
  QSplitter::setSizes(*(QList **)(param_1 + 0x68));
  QMainWindow::setCentralWidget(param_1);
  FUN_00550ec0(&local_48);
  FUN_00550ec0(&local_58);
  return;
}


