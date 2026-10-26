// entry=00639e76 size=126  (decompiled by Ghidra package ghidra, Utility, version 12.1.4)

void FUN_00639e76(long param_1,void *param_2,byte *param_3)

{
  undefined8 uVar1;
  byte bVar2;
  QPixmap aQStack_38 [24];
  undefined8 local_20;
  
  if ((int)param_2 == 3) {
    bVar2 = FUN_00756336(DAT_011c1ce0,param_1 + 8);
    *param_3 = bVar2 ^ 1;
    return;
  }
  if ((int)param_2 != 4) {
    QIconEngine::virtual_hook((int)param_1,param_2);
    return;
  }
  *(undefined8 *)(param_1 + 0x10) = *(undefined8 *)(param_3 + 0x10);
  FUN_00639652(aQStack_38,param_1,param_3,*(undefined4 *)(param_3 + 8),
               *(undefined4 *)(param_3 + 0xc));
  uVar1 = *(undefined8 *)(param_3 + 0x30);
  *(undefined8 *)(param_3 + 0x30) = local_20;
  local_20 = uVar1;
  QPixmap::~QPixmap(aQStack_38);
  return;
}


