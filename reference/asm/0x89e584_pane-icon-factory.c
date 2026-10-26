// entry=0089e584 size=774  (decompiled by Ghidra package ghidra, Utility, version 12.1.4)

QIcon * FUN_0089e584(QIcon *param_1,undefined8 *param_2)

{
  int iVar1;
  undefined8 uVar2;
  char cVar3;
  undefined2 uVar4;
  QArrayData *pQVar5;
  long lVar6;
  uint uVar7;
  QArrayData *local_60;
  QArrayData *local_58;
  QArrayData *local_50;
  QArrayData *local_48;
  QArrayData *local_40 [2];
  
  QIcon::QIcon(param_1);
                    /* try { // try from 0089e5a9 to 0089e5ad has its CatchHandler @ 0089e8b7 */
  local_40[0] = (QArrayData *)QString::fromAscii_helper("Pane",4);
                    /* try { // try from 0089e5c3 to 0089e5c7 has its CatchHandler @ 0089e895 */
  cVar3 = QString::endsWith(param_2,(QIcon *)local_40,1);
  if (*(int *)local_40[0] == 0) {
LAB_0089e5fd:
    QArrayData::deallocate(local_40[0],2,8);
  }
  else if (*(int *)local_40[0] != -1) {
    LOCK();
    *(int *)local_40[0] = *(int *)local_40[0] + -1;
    UNLOCK();
    if (*(int *)local_40[0] == 0) goto LAB_0089e5fd;
  }
  if (cVar3 == '\0') {
    return param_1;
  }
  local_60 = (QArrayData *)*param_2;
  if ((*(uint *)local_60 == 0) || (*(uint *)local_60 == 0xffffffff)) {
    if (*(uint *)local_60 < 2) goto LAB_0089e637;
LAB_0089e645:
                    /* try { // try from 0089e656 to 0089e6d6 has its CatchHandler @ 0089e8bf */
    QString::reallocData((uint)&local_60,(bool)((char)*(uint *)(local_60 + 4) + '\x01'));
  }
  else {
    LOCK();
    *(uint *)local_60 = *(uint *)local_60 + 1;
    UNLOCK();
    if (1 < *(uint *)local_60) goto LAB_0089e645;
LAB_0089e637:
    if (*(long *)(local_60 + 0x10) != 0x18) goto LAB_0089e645;
  }
  pQVar5 = local_60;
  if ((int)*(uint *)(local_60 + 4) < 1) {
    uVar7 = 0;
  }
  else {
    uVar7 = (uint)*(ushort *)(local_60 + *(long *)(local_60 + 0x10));
  }
  uVar4 = QChar::toLower(uVar7);
  uVar7 = (uint)&local_60;
  if ((1 < *(uint *)pQVar5) || (*(long *)(pQVar5 + 0x10) != 0x18)) {
    QString::reallocData(uVar7,(bool)((char)*(uint *)(pQVar5 + 4) + '\x01'));
    pQVar5 = local_60;
  }
  if ((int)*(uint *)(pQVar5 + 4) < 1) {
                    /* try { // try from 0089e879 to 0089e87d has its CatchHandler @ 0089e8bf */
    QString::resize(&local_60,1,0x20);
LAB_0089e6d7:
    lVar6 = *(long *)(local_60 + 0x10);
    pQVar5 = local_60;
  }
  else if ((1 < *(uint *)pQVar5) || (lVar6 = *(long *)(pQVar5 + 0x10), lVar6 != 0x18)) {
    QString::reallocData(uVar7,(bool)((char)*(uint *)(pQVar5 + 4) + '\x01'));
    goto LAB_0089e6d7;
  }
  *(undefined2 *)(pQVar5 + lVar6) = uVar4;
  uVar2 = DAT_011c1ce0;
  local_48 = (QArrayData *)&QArrayData::shared_null;
                    /* try { // try from 0089e70c to 0089e710 has its CatchHandler @ 0089e89d */
  local_58 = (QArrayData *)QString::fromAscii_helper("king::%1",8);
                    /* try { // try from 0089e731 to 0089e735 has its CatchHandler @ 0089e8aa */
  QString::arg(&local_50,&local_58,&local_60,0,0x20);
                    /* try { // try from 0089e749 to 0089e74d has its CatchHandler @ 0089e88a */
  FUN_00756cd6((QIcon *)local_40,uVar2,&local_50,&local_48);
  uVar2 = *(undefined8 *)param_1;
  *(QArrayData **)param_1 = local_40[0];
  local_40[0] = (QArrayData *)uVar2;
  QIcon::~QIcon((QIcon *)local_40);
  if (*(int *)local_50 == 0) {
LAB_0089e851:
    QArrayData::deallocate(local_50,2,8);
  }
  else if (*(int *)local_50 != -1) {
    LOCK();
    *(int *)local_50 = *(int *)local_50 + -1;
    UNLOCK();
    if (*(int *)local_50 == 0) goto LAB_0089e851;
  }
  if (*(int *)local_58 == 0) {
LAB_0089e81a:
    QArrayData::deallocate(local_58,2,8);
    iVar1 = *(int *)local_48;
  }
  else {
    if (*(int *)local_58 != -1) {
      LOCK();
      *(int *)local_58 = *(int *)local_58 + -1;
      UNLOCK();
      if (*(int *)local_58 == 0) goto LAB_0089e81a;
    }
    iVar1 = *(int *)local_48;
  }
  if (iVar1 != 0) {
    if (iVar1 == -1) goto LAB_0089e7bc;
    LOCK();
    *(int *)local_48 = *(int *)local_48 + -1;
    UNLOCK();
    if (*(int *)local_48 != 0) goto LAB_0089e7bc;
  }
  QArrayData::deallocate(local_48,2,8);
LAB_0089e7bc:
  if (*(int *)local_60 != 0) {
    if (*(int *)local_60 == -1) {
      return param_1;
    }
    LOCK();
    *(int *)local_60 = *(int *)local_60 + -1;
    UNLOCK();
    if (*(int *)local_60 != 0) {
      return param_1;
    }
  }
  QArrayData::deallocate(local_60,2,8);
  return param_1;
}


