// entry=00756336 size=129  (decompiled by Ghidra package ghidra, Utility, version 12.1.4)

undefined4 FUN_00756336(undefined8 param_1,undefined8 param_2)

{
  char cVar1;
  undefined4 uVar2;
  QString *pQVar3;
  uint *local_20 [2];
  
  FUN_0075541e(local_20,param_1,param_2);
                    /* try { // try from 00756358 to 007563b4 has its CatchHandler @ 007563b7 */
  pQVar3 = (QString *)FUN_00755c86(param_1,local_20);
  if (pQVar3 != (QString *)0x0) {
    cVar1 = QSvgRenderer::isValid();
    if (cVar1 != '\0') {
      if (1 < *local_20[0]) {
        FUN_00525800(local_20,local_20[0][1]);
      }
      uVar2 = QSvgRenderer::elementExists(pQVar3);
      goto LAB_00756373;
    }
  }
  uVar2 = 0;
LAB_00756373:
  FUN_00525060(local_20);
  return uVar2;
}


