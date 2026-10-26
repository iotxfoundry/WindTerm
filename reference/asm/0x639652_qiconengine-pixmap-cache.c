// entry=00639652 size=1573  (decompiled by Ghidra package ghidra, Utility, version 12.1.4)

QPixmap * FUN_00639652(QPixmap *param_1,long param_2,int *param_3,uint param_4,uint param_5)

{
  int iVar1;
  QPixmap *pQVar2;
  int iVar3;
  QPixmap *pQVar4;
  undefined8 uVar5;
  long lVar6;
  QPixmap *pQVar7;
  QPixmap *pQVar8;
  double dVar9;
  QIcon local_80 [8];
  QPixmap local_78 [24];
  undefined8 local_60;
  undefined8 local_58 [3];
  undefined8 local_40;
  
  QPixmap::QPixmap(param_1);
  pQVar2 = *(QPixmap **)(param_2 + 0x20);
  pQVar7 = *(QPixmap **)(param_2 + 0x18);
  lVar6 = (long)pQVar2 - (long)pQVar7 >> 3;
  lVar6 = lVar6 * 0xcccccccd + (lVar6 * 0x33333333 << 0x22);
  if (0 < lVar6 >> 2) {
    pQVar4 = pQVar7 + (lVar6 >> 2) * 0xa0;
    do {
      uVar5 = QPixmap::size();
      dVar9 = (double)QPixmap::devicePixelRatio();
      if (((((double)*param_3 * dVar9 <= (double)(int)uVar5) ||
           ((double)param_3[1] * dVar9 <= (double)(int)((ulong)uVar5 >> 0x20))) &&
          (dVar9 == *(double *)(param_2 + 0x10))) &&
         ((((byte)pQVar7[0x20] & 0xf) == param_4 &&
          (pQVar8 = pQVar7, (byte)pQVar7[0x20] >> 4 == param_5)))) goto LAB_006398ef;
      pQVar8 = pQVar7 + 0x28;
                    /* try { // try from 006396ed to 006399bd has its CatchHandler @ 00639c77 */
      uVar5 = QPixmap::size();
      dVar9 = (double)QPixmap::devicePixelRatio();
      if ((((double)*param_3 * dVar9 <= (double)(int)uVar5) ||
          ((double)param_3[1] * dVar9 <= (double)(int)((ulong)uVar5 >> 0x20))) &&
         (((dVar9 == *(double *)(param_2 + 0x10) && (((byte)pQVar7[0x48] & 0xf) == param_4)) &&
          ((byte)pQVar7[0x48] >> 4 == param_5)))) {
LAB_00639983:
        if (*(QPixmap **)(param_2 + 0x20) == pQVar8) goto LAB_0063998e;
        goto LAB_006398fa;
      }
      pQVar8 = pQVar7 + 0x50;
      uVar5 = QPixmap::size();
      dVar9 = (double)QPixmap::devicePixelRatio();
      if (((((double)*param_3 * dVar9 <= (double)(int)uVar5) ||
           ((double)param_3[1] * dVar9 <= (double)(int)((ulong)uVar5 >> 0x20))) &&
          (dVar9 == *(double *)(param_2 + 0x10))) &&
         ((((byte)pQVar7[0x70] & 0xf) == param_4 && ((byte)pQVar7[0x70] >> 4 == param_5))))
      goto LAB_00639983;
      pQVar8 = pQVar7 + 0x78;
      uVar5 = QPixmap::size();
      dVar9 = (double)QPixmap::devicePixelRatio();
      if ((((double)*param_3 * dVar9 <= (double)(int)uVar5) ||
          ((double)param_3[1] * dVar9 <= (double)(int)((ulong)uVar5 >> 0x20))) &&
         (((dVar9 == *(double *)(param_2 + 0x10) && (((byte)pQVar7[0x98] & 0xf) == param_4)) &&
          ((byte)pQVar7[0x98] >> 4 == param_5)))) goto LAB_00639983;
      pQVar7 = pQVar7 + 0xa0;
    } while (pQVar4 != pQVar7);
    lVar6 = (long)pQVar2 - (long)pQVar7 >> 3;
    lVar6 = lVar6 * 0xcccccccd + (lVar6 * 0x33333333 << 0x22);
  }
  if (lVar6 == 2) {
LAB_00639b1f:
    uVar5 = QPixmap::size();
    dVar9 = (double)QPixmap::devicePixelRatio();
    if ((((double)*param_3 * dVar9 <= (double)(int)uVar5) ||
        ((double)param_3[1] * dVar9 <= (double)(int)((ulong)uVar5 >> 0x20))) &&
       ((dVar9 == *(double *)(param_2 + 0x10) &&
        ((((byte)pQVar7[0x20] & 0xf) == param_4 &&
         (pQVar8 = pQVar7, (byte)pQVar7[0x20] >> 4 == param_5)))))) goto LAB_006398ef;
    pQVar7 = pQVar7 + 0x28;
LAB_00639b82:
    uVar5 = QPixmap::size();
    dVar9 = (double)QPixmap::devicePixelRatio();
    if (((((double)*param_3 * dVar9 <= (double)(int)uVar5) ||
         ((double)param_3[1] * dVar9 <= (double)(int)((ulong)uVar5 >> 0x20))) &&
        (dVar9 == *(double *)(param_2 + 0x10))) &&
       ((((byte)pQVar7[0x20] & 0xf) == param_4 &&
        (pQVar8 = pQVar7, (byte)pQVar7[0x20] >> 4 == param_5)))) goto LAB_006398ef;
  }
  else {
    if (lVar6 == 3) {
      uVar5 = QPixmap::size();
      dVar9 = (double)QPixmap::devicePixelRatio();
      if (((((double)*param_3 * dVar9 <= (double)(int)uVar5) ||
           ((double)param_3[1] * dVar9 <= (double)(int)((ulong)uVar5 >> 0x20))) &&
          (dVar9 == *(double *)(param_2 + 0x10))) &&
         ((((byte)pQVar7[0x20] & 0xf) == param_4 &&
          (pQVar8 = pQVar7, (byte)pQVar7[0x20] >> 4 == param_5)))) goto LAB_006398ef;
      pQVar7 = pQVar7 + 0x28;
      goto LAB_00639b1f;
    }
    if (lVar6 == 1) goto LAB_00639b82;
  }
  pQVar8 = pQVar2;
LAB_006398ef:
  if (*(QPixmap **)(param_2 + 0x20) == pQVar8) {
LAB_0063998e:
    local_58[0] = 0x40000000400;
    FUN_007572ac(local_80,DAT_011c1ce0,param_2 + 8,local_58);
                    /* try { // try from 006399d5 to 00639a13 has its CatchHandler @ 00639c7f */
    QIcon::pixmap(local_78,local_80,param_3,param_4,param_5);
    uVar5 = *(undefined8 *)(param_1 + 0x18);
    *(undefined8 *)(param_1 + 0x18) = local_60;
    local_60 = uVar5;
    QPixmap::~QPixmap(local_78);
    QPixmap::setDevicePixelRatio(*(double *)(param_2 + 0x10));
    FUN_006393e6(param_2,param_1,param_4,param_5);
    QIcon::~QIcon(local_80);
  }
  else {
LAB_006398fa:
    iVar3 = QPixmap::width();
    iVar1 = *param_3;
    dVar9 = (double)QPixmap::devicePixelRatio();
    if ((double)iVar3 <= dVar9 * (double)iVar1) {
                    /* try { // try from 00639a54 to 00639b95 has its CatchHandler @ 00639c77 */
      QPixmap::operator=(param_1,pQVar8);
    }
    else {
      QPixmap::scaledToWidth((QPixmap *)local_58,pQVar8,*param_3,1);
      uVar5 = *(undefined8 *)(param_1 + 0x18);
      *(undefined8 *)(param_1 + 0x18) = local_40;
      local_40 = uVar5;
      QPixmap::~QPixmap((QPixmap *)local_58);
    }
  }
  return param_1;
}


