// entry=007572ac size=769  (decompiled by Ghidra package ghidra, Utility, version 12.1.4)

QIcon * FUN_007572ac(QIcon *param_1,undefined8 param_2,undefined8 param_3,int *param_4)

{
  undefined8 uVar1;
  char cVar2;
  QString *pQVar3;
  int iVar4;
  int iVar5;
  QColor *local_d0;
  uint *local_c8;
  QArrayData *local_c0;
  QPixmap local_b8 [24];
  undefined8 local_a0;
  QString local_98 [16];
  double local_88;
  double local_80;
  QPainter local_78 [24];
  undefined8 local_60;
  undefined8 local_58;
  undefined8 local_50;
  undefined8 local_48;
  undefined8 local_40;
  
  QPixmap::QPixmap(local_b8);
                    /* try { // try from 007572e4 to 007572e8 has its CatchHandler @ 007575ad */
  FUN_0075541e(&local_c8,param_2,param_3);
                    /* try { // try from 007572ef to 007572f3 has its CatchHandler @ 007575c5 */
  pQVar3 = (QString *)FUN_00755c86(param_2,&local_c8);
  if (1 < *local_c8) {
                    /* try { // try from 007574e8 to 007574ec has its CatchHandler @ 007575c5 */
    FUN_00525800(&local_c8,local_c8[1]);
  }
  local_c0 = *(QArrayData **)(local_c8 + (long)(int)local_c8[2] * 2 + 8);
  if ((*(int *)local_c0 != 0) && (*(int *)local_c0 != -1)) {
    LOCK();
    *(int *)local_c0 = *(int *)local_c0 + 1;
    UNLOCK();
  }
                    /* try { // try from 00757332 to 00757474 has its CatchHandler @ 007575bd */
  if ((pQVar3 != (QString *)0x0) && (cVar2 = QSvgRenderer::isValid(), cVar2 != '\0')) {
    cVar2 = QSvgRenderer::elementExists(pQVar3);
    if (cVar2 != '\0') {
      QSvgRenderer::boundsOnElement(local_98);
      local_88 = local_88 / local_80;
      iVar5 = *param_4;
      if ((iVar5 < 1) || (iVar4 = param_4[1], iVar4 < 1)) {
        iVar5 = 0x20;
        iVar4 = 0x20;
      }
      if (local_88 < 1.0) {
                    /* try { // try from 0075757a to 0075757e has its CatchHandler @ 007575bd */
        QPixmap::QPixmap((QPixmap *)local_78,(int)((double)iVar5 * local_88),iVar4);
        uVar1 = local_a0;
        local_a0 = local_60;
        local_60 = uVar1;
        QPixmap::~QPixmap((QPixmap *)local_78);
      }
      else {
        QPixmap::QPixmap((QPixmap *)&local_58,iVar5,(int)((double)iVar4 * local_88));
        uVar1 = local_a0;
        local_a0 = local_40;
        local_40 = uVar1;
        QPixmap::~QPixmap((QPixmap *)&local_58);
      }
      local_d0 = (QColor *)&local_58;
      QColor::QColor(local_d0,0x13);
      QPixmap::fill((QColor *)local_b8);
      QPainter::QPainter(local_78,(QPaintDevice *)local_b8);
                    /* try { // try from 00757482 to 007574a1 has its CatchHandler @ 007575b5 */
      QPainter::setRenderHints(local_78,5,1);
      if (*(int *)(local_c0 + 4) == 0) {
        QSvgRenderer::render((QPainter *)pQVar3);
      }
      else {
        local_58 = 0;
        local_50 = 0;
        local_48 = 0;
        local_40 = 0;
                    /* try { // try from 00757558 to 0075755c has its CatchHandler @ 007575b5 */
        QSvgRenderer::render((QPainter *)pQVar3,(QString *)local_78,(QRectF *)&local_c0);
      }
      QPainter::~QPainter(local_78);
    }
  }
  cVar2 = QPixmap::isNull();
  if (cVar2 == '\0') {
                    /* try { // try from 007574ba to 007574be has its CatchHandler @ 007575bd */
    QIcon::QIcon(param_1,local_b8);
    iVar5 = *(int *)local_c0;
  }
  else {
    QIcon::QIcon(param_1);
    iVar5 = *(int *)local_c0;
  }
  if (iVar5 == 0) {
    QArrayData::deallocate(local_c0,2,8);
  }
  else if (iVar5 != -1) {
    LOCK();
    *(int *)local_c0 = *(int *)local_c0 + -1;
    UNLOCK();
    if (*(int *)local_c0 == 0) {
      QArrayData::deallocate(local_c0,2,8);
    }
  }
  FUN_00525060(&local_c8);
  QPixmap::~QPixmap(local_b8);
  return param_1;
}


