// entry=0076bffc size=466  (decompiled by Ghidra package ghidra, Utility, version 12.1.4)

void FUN_0076bffc(QMainWindow *param_1)

{
  uint *puVar1;
  QObject *pQVar2;
  uint *puVar3;
  uint *local_58;
  long *local_50;
  undefined8 *local_48;
  undefined8 local_40;
  
  *(undefined ***)param_1 = &PTR_FUN_011a69f8;
  *(undefined ***)(param_1 + 0x10) = &PTR_FUN_011a6bb0;
  local_48 = &QArrayData::shared_null;
  local_58 = (uint *)&QListData::shared_null;
                    /* try { // try from 0076c057 to 0076c05b has its CatchHandler @ 0076c1ce */
  qt_qFindChildren_helper(param_1,&local_48,&QTimer::staticMetaObject,&local_58,1);
  FUN_005249f0(&local_48);
  if (1 < *local_58) {
    FUN_00770dc0(&local_58);
  }
  puVar3 = local_58 + (long)(int)local_58[2] * 2 + 4;
  if (1 < *local_58) {
    FUN_00770dc0(&local_58);
  }
  puVar1 = local_58 + (long)(int)local_58[3] * 2 + 4;
  for (; puVar1 != puVar3; puVar3 = puVar3 + 2) {
    pQVar2 = *(QObject **)puVar3;
    QTimer::stop();
    QObject::disconnect(pQVar2,(char *)0x0,(QObject *)0x0,(char *)0x0);
  }
  FUN_00770620(&local_58);
  if (*(long **)(param_1 + 0x48) != (long *)0x0) {
    (**(code **)(**(long **)(param_1 + 0x48) + 0x20))();
  }
  *(undefined8 *)(param_1 + 0x48) = 0;
  puVar3 = *(uint **)(param_1 + 0xe0);
  if (puVar3 != (uint *)0x0) {
    local_50 = *(long **)(param_1 + 0xe8);
    if ((puVar3[1] == 0) || (local_50 == (long *)0x0)) goto LAB_0076c11f;
    (**(code **)(*local_50 + 0x20))();
    puVar3 = *(uint **)(param_1 + 0xe0);
  }
  local_50 = *(long **)(param_1 + 0xe8);
LAB_0076c11f:
  local_48 = (undefined8 *)0x0;
  local_40 = 0;
  *(undefined8 *)(param_1 + 0xe0) = 0;
  *(undefined8 *)(param_1 + 0xe8) = 0;
  local_58 = puVar3;
  FUN_00550ea0(&local_58);
  FUN_00550ea0(&local_48);
  FUN_00550ea0(param_1 + 0xe0);
  FUN_00770600(param_1 + 0xd8);
  FUN_00550ea0(param_1 + 200);
  FUN_00550ea0(param_1 + 0xb8);
  FUN_005249f0(param_1 + 0xa0);
  FUN_00550ea0(param_1 + 0x70);
  FUN_005249c0(param_1 + 0x40);
  FUN_005249c0(param_1 + 0x38);
  QMainWindow::~QMainWindow(param_1);
  return;
}


