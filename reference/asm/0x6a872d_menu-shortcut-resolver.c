// entry=006a872d size=420  (decompiled by Ghidra package ghidra, Utility, version 12.1.4)

void FUN_006a872d(int param_1,void *param_2)

{
  QKeySequence *pQVar1;
  undefined4 uVar2;
  long lVar3;
  long lVar4;
  long lVar5;
  char cVar6;
  undefined1 auStack_48 [8];
  QArrayData *local_40 [2];
  
  if (param_1 == 0) {
    if (param_2 != (void *)0x0) {
      operator_delete(param_2,0x30);
      return;
    }
  }
  else if (param_1 == 1) {
    lVar4 = *(long *)(*(long *)((long)param_2 + 0x20) + 0x20);
    cVar6 = *(char *)(*(long *)((long)param_2 + 0x10) + 0x10);
    if (lVar4 != 0) {
      FUN_0056672a(lVar4,cVar6,0,0);
      cVar6 = *(char *)(*(long *)((long)param_2 + 0x10) + 0x10);
    }
    if (cVar6 != '\0') {
      FUN_0075bd66();
      lVar4 = *(long *)((long)param_2 + 0x18);
      lVar5 = lVar4;
      do {
        if (lVar5 == 0) {
LAB_006a889d:
          FUN_006a8208(*(undefined8 *)((long)param_2 + 0x10),lVar4);
          return;
        }
        lVar3 = __dynamic_cast(lVar5,&QObject::typeinfo,&PTR_PTR_011a69d0,0);
        if (lVar3 != 0) {
          lVar4 = FUN_007670b4(lVar3);
          if (lVar4 != 0) {
            QByteArray::QByteArray((QByteArray *)local_40,"Terminal.ManageTunnels",-1);
                    /* try { // try from 006a8826 to 006a882a has its CatchHandler @ 006a88d1 */
            lVar5 = FUN_00767b36(lVar3,(QByteArray *)local_40);
            if (*(int *)local_40[0] == 0) {
LAB_006a88bd:
              QArrayData::deallocate(local_40[0],1,8);
            }
            else if (*(int *)local_40[0] != -1) {
              LOCK();
              *(int *)local_40[0] = *(int *)local_40[0] + -1;
              UNLOCK();
              if (*(int *)local_40[0] == 0) goto LAB_006a88bd;
            }
            if (lVar5 != 0) {
              uVar2 = FUN_008cb962(lVar4,1);
              FUN_0076bf82(auStack_48,lVar3,lVar5,uVar2);
              pQVar1 = *(QKeySequence **)((long)param_2 + 0x28);
                    /* try { // try from 006a8879 to 006a887d has its CatchHandler @ 006a88e5 */
              QKeySequence::QKeySequence((QKeySequence *)local_40,auStack_48,0);
                    /* try { // try from 006a8884 to 006a8888 has its CatchHandler @ 006a88d9 */
              QAction::setShortcut(pQVar1);
              QKeySequence::~QKeySequence((QKeySequence *)local_40);
              FUN_005249f0(auStack_48);
            }
          }
          lVar4 = *(long *)((long)param_2 + 0x18);
          goto LAB_006a889d;
        }
        lVar5 = *(long *)(*(long *)(lVar5 + 8) + 0x10);
      } while( true );
    }
  }
  return;
}


