// entry=008cb962 size=186  (decompiled by Ghidra package ghidra, Utility, version 12.1.4)

ulong FUN_008cb962(undefined8 param_1,char param_2)

{
  uint uVar1;
  long lVar2;
  long lVar3;
  ulong uVar4;
  
  if (param_2 == '\0') {
    lVar2 = FUN_008cabee();
    if ((lVar2 != 0) &&
       (lVar2 = __dynamic_cast(lVar2,&PTR_PTR_011925c8,&PTR_PTR_01197420,0xfffffffffffffffe),
       lVar2 != 0)) {
      uVar1 = FUN_005b8326(lVar2);
      return (ulong)(uVar1 | 1);
    }
  }
  else {
    FUN_0075bd66();
    for (lVar2 = QWidget::focusWidget(); lVar2 != 0; lVar2 = *(long *)(*(long *)(lVar2 + 8) + 0x10))
    {
      lVar3 = __dynamic_cast(lVar2,&QObject::typeinfo,&PTR_PTR_01197420,0);
      if (lVar3 != 0) {
        uVar4 = FUN_005b8326(lVar3);
        return uVar4;
      }
    }
  }
  return 1;
}


