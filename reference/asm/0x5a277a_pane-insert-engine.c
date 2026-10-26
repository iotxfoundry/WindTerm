// entry=005a277a size=596  (decompiled by Ghidra package ghidra, Utility, version 12.1.4)

void FUN_005a277a(undefined8 param_1,long param_2,long param_3,uint param_4)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  QWidget *pQVar4;
  QSplitter *this;
  uint *puVar5;
  ulong *puVar6;
  long lVar7;
  int iVar8;
  uint *local_40 [2];
  
  if (((param_2 != 0) && (param_3 != 0)) &&
     (lVar7 = *(long *)(*(long *)(param_2 + 8) + 0x10), lVar7 != 0)) {
    pQVar4 = (QWidget *)__dynamic_cast(lVar7,&QObject::typeinfo,&QSplitter::typeinfo,0);
    if (pQVar4 != (QWidget *)0x0) {
      iVar8 = 2 - (uint)(param_4 < 2);
      iVar2 = QSplitter::count();
      if (iVar2 < 2) {
        QSplitter::setOrientation(pQVar4,iVar8);
      }
      else {
        iVar2 = QSplitter::orientation();
        if (iVar8 != iVar2) {
          uVar3 = QSplitter::indexOf(pQVar4);
          this = operator_new(0x30);
                    /* try { // try from 005a2826 to 005a282a has its CatchHandler @ 005a29ce */
          QSplitter::QSplitter(this,(QWidget *)0x0);
          QSplitter::setOrientation(this,iVar8);
          QSplitter::setChildrenCollapsible(SUB81(this,0));
          QSplitter::replaceWidget((int)pQVar4,(QWidget *)(ulong)uVar3);
          QSplitter::addWidget((QWidget *)this);
          pQVar4 = (QWidget *)this;
        }
      }
      uVar3 = QSplitter::indexOf(pQVar4);
      iVar2 = QSplitter::handleWidth();
      QSplitter::sizes();
      if ((param_4 & 0xfffffffd) == 0) {
                    /* try { // try from 005a296e to 005a29ac has its CatchHandler @ 005a29db */
        QSplitter::insertWidget((int)pQVar4,(QWidget *)(ulong)uVar3);
      }
      else {
                    /* try { // try from 005a289e to 005a293b has its CatchHandler @ 005a29db */
        QSplitter::insertWidget((int)pQVar4,(QWidget *)(ulong)(uVar3 + 1));
      }
      if (1 < *local_40[0]) {
        FUN_005a2170(local_40,local_40[0][1]);
      }
      lVar7 = (long)(int)uVar3;
      uVar1 = local_40[0][((int)local_40[0][2] + lVar7) * 2 + 4];
      if (1 < *local_40[0]) {
        FUN_005a2170(local_40,local_40[0][1]);
      }
      local_40[0][((int)local_40[0][2] + lVar7) * 2 + 4] = (int)(uVar1 - iVar2) / 2;
      if (1 < *local_40[0]) {
        FUN_005a2170(local_40,local_40[0][1]);
      }
      uVar1 = local_40[0][2];
      if (*local_40[0] < 2) {
        uVar3 = local_40[0][(lVar7 + (int)uVar1) * 2 + 4];
                    /* try { // try from 005a29c1 to 005a29c5 has its CatchHandler @ 005a29d6 */
        puVar6 = (ulong *)QListData::insert((int)local_40);
        *puVar6 = (ulong)uVar3;
      }
      else {
        puVar5 = (uint *)FUN_00550f1e(local_40,(QWidget *)(ulong)uVar3,1);
        *puVar5 = local_40[0][(lVar7 + (int)uVar1) * 2 + 4];
      }
      QSplitter::setSizes(pQVar4);
      FUN_005a236c(param_1,param_3);
      FUN_00550ec0(local_40);
    }
    return;
  }
  return;
}


