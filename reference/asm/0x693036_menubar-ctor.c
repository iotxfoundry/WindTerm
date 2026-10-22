// entry=00693036 size=575  (decompiled by Ghidra package ghidra, Utility, version 12.1.4)

/* WARNING: Removing unreachable block (ram,0x0069325a) */
/* WARNING: Removing unreachable block (ram,0x0069321f) */

QMenuBar * FUN_00693036(long *param_1,undefined8 param_2,QWidget *param_3)

{
  long lVar1;
  QMenuBar *this;
  size_t sVar2;
  long lVar3;
  long *plVar4;
  QArrayData *local_78;
  long *local_70;
  long local_68;
  QArrayData *local_58;
  long *local_50;
  long local_48;
  
  this = operator_new(0x30);
                    /* try { // try from 00693060 to 00693064 has its CatchHandler @ 00693285 */
  QMenuBar::QMenuBar(this,param_3);
  sVar2 = strlen("MenuBar");
  local_58 = (QArrayData *)QString::fromAscii_helper("MenuBar",(int)sVar2);
                    /* try { // try from 0069309a to 0069309e has its CatchHandler @ 0069327d */
  QObject::setObjectName((QString *)this);
  if (*(int *)local_58 == 0) {
LAB_00693207:
    QArrayData::deallocate(local_58,2,8);
  }
  else if (*(int *)local_58 != -1) {
    LOCK();
    *(int *)local_58 = *(int *)local_58 + -1;
    UNLOCK();
    if (*(int *)local_58 == 0) goto LAB_00693207;
  }
  sVar2 = strlen("MenuBar");
  local_78 = (QArrayData *)QString::fromAscii_helper("MenuBar",(int)sVar2);
                    /* try { // try from 006930e5 to 006930e9 has its CatchHandler @ 00693275 */
  FUN_008a1106(&local_58,&local_78);
                    /* try { // try from 006930f0 to 006930f4 has its CatchHandler @ 0069328d */
  QWidget::setWindowTitle((QString *)this);
  if (*(int *)local_58 == 0) {
LAB_00693246:
    QArrayData::deallocate(local_58,2,8);
  }
  else if (*(int *)local_58 != -1) {
    LOCK();
    *(int *)local_58 = *(int *)local_58 + -1;
    UNLOCK();
    if (*(int *)local_58 == 0) goto LAB_00693246;
  }
  if (*(int *)local_78 != 0) {
    if (*(int *)local_78 == -1) goto LAB_00693130;
    LOCK();
    *(int *)local_78 = *(int *)local_78 + -1;
    UNLOCK();
    if (*(int *)local_78 != 0) goto LAB_00693130;
  }
  QArrayData::deallocate(local_78,2,8);
LAB_00693130:
  if (*param_1 != 0) {
    FUN_006926c2(&local_78,param_1,*param_1 + 0x28,param_2);
    if ((local_68 != *param_1 + 0x28) || (local_70 != *(long **)(*param_1 + 0x38))) {
      lVar1 = *local_70;
      plVar4 = *(long **)(lVar1 + 0x10);
      local_48 = lVar1;
      local_68 = lVar1;
      for (local_70 = *(long **)(lVar1 + 8); (lVar1 != local_48 || (local_70 != plVar4));
          local_70 = local_70 + 1) {
        if ((*(byte *)(*(long *)(*local_70 + 0x20) + 0x10) & 0xf) == 2) {
          local_58 = (QArrayData *)&PTR_FUN_01189df0;
          local_50 = local_70;
          lVar3 = FUN_00692a70(param_1,&local_58,param_3);
          if (lVar3 != 0) {
            QMenuBar::addMenu((QMenu *)this);
          }
          plVar4 = *(long **)(lVar1 + 0x10);
          local_48 = local_68;
        }
      }
    }
  }
  return this;
}


