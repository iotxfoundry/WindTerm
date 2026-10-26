// entry=0075541e size=1548  (decompiled by Ghidra package ghidra, Utility, version 12.1.4)

long * FUN_0075541e(long *param_1,undefined8 param_2,QString *param_3)

{
  QString *pQVar1;
  undefined8 *puVar2;
  uint uVar3;
  QArrayData *pQVar4;
  uint *puVar5;
  char cVar6;
  byte bVar7;
  int iVar8;
  long lVar9;
  uint *local_58;
  QArrayData *local_50;
  QArrayData *local_48;
  QArrayData *local_40 [2];
  
  *param_1 = (long)&QListData::shared_null;
  lVar9 = 3;
  do {
    local_40[0] = (QArrayData *)&QArrayData::shared_null;
                    /* try { // try from 0075545b to 0075545f has its CatchHandler @ 00755a72 */
    FUN_00544828(param_1,(QString *)local_40);
    if (*(int *)local_40[0] == 0) {
LAB_00755760:
      QArrayData::deallocate(local_40[0],2,8);
    }
    else if (*(int *)local_40[0] != -1) {
      LOCK();
      *(int *)local_40[0] = *(int *)local_40[0] + -1;
      UNLOCK();
      if (*(int *)local_40[0] == 0) goto LAB_00755760;
    }
    lVar9 = lVar9 + -1;
  } while (lVar9 != 0);
                    /* try { // try from 00755490 to 00755494 has its CatchHandler @ 00755a4a */
  local_40[0] = (QArrayData *)QString::fromAscii_helper("::",2);
                    /* try { // try from 007554a7 to 007554ab has its CatchHandler @ 00755a52 */
  iVar8 = QString::indexOf(param_3,(QString *)local_40,0,1);
  if (iVar8 == -1) {
                    /* try { // try from 00755893 to 00755897 has its CatchHandler @ 00755a52 */
    bVar7 = QDir::isRelativePath(param_3);
    bVar7 = bVar7 ^ 1;
  }
  else {
    bVar7 = 0;
  }
  if (*(int *)local_40[0] == 0) {
LAB_0075587c:
    QArrayData::deallocate(local_40[0],2,8);
  }
  else if (*(int *)local_40[0] != -1) {
    LOCK();
    *(int *)local_40[0] = *(int *)local_40[0] + -1;
    UNLOCK();
    if (*(int *)local_40[0] == 0) goto LAB_0075587c;
  }
  if (bVar7 == 0) {
                    /* try { // try from 007554ea to 007554ee has its CatchHandler @ 00755a4a */
    local_40[0] = (QArrayData *)QString::fromLatin1_helper("::",2);
                    /* try { // try from 0075550a to 0075550e has its CatchHandler @ 00755a42 */
    QString::split(&local_58,param_3,(QString *)local_40,0,1);
    if (*(int *)local_40[0] == 0) {
LAB_00755831:
      QArrayData::deallocate(local_40[0],2,8);
    }
    else if (*(int *)local_40[0] != -1) {
      LOCK();
      *(int *)local_40[0] = *(int *)local_40[0] + -1;
      UNLOCK();
      if (*(int *)local_40[0] == 0) goto LAB_00755831;
    }
    if (0 < (int)(local_58[3] - local_58[2])) {
      if (1 < *local_58) {
        FUN_00525800(&local_58,local_58[1]);
      }
      pQVar1 = (QString *)(local_58 + (long)(int)local_58[2] * 2 + 4);
      if (1 < *(uint *)*param_1) {
                    /* try { // try from 007559a3 to 007559b7 has its CatchHandler @ 00755a5a */
        FUN_00525800(param_1,((uint *)*param_1)[1]);
      }
      QString::operator=((QString *)(*param_1 + 0x18 + (long)*(int *)(*param_1 + 8) * 8),pQVar1);
      if (1 < (int)(local_58[3] - local_58[2])) {
        if (1 < *local_58) {
          FUN_00525800(&local_58,local_58[1]);
        }
        uVar3 = local_58[2];
        if (1 < *(uint *)*param_1) {
                    /* try { // try from 00755a0a to 00755a1f has its CatchHandler @ 00755a5a */
          FUN_00525800(param_1,((uint *)*param_1)[1]);
        }
        QString::operator=((QString *)(*param_1 + 0x20 + (long)*(int *)(*param_1 + 8) * 8),
                           (QString *)(local_58 + (long)(int)uVar3 * 2 + 6));
      }
    }
                    /* try { // try from 00755592 to 00755596 has its CatchHandler @ 00755a5a */
    local_40[0] = (QArrayData *)QString::fromAscii_helper("images/%1.svg",0xd);
    if (1 < *(uint *)*param_1) {
                    /* try { // try from 00755938 to 0075593c has its CatchHandler @ 00755a62 */
      FUN_00525800(param_1,((uint *)*param_1)[1]);
    }
                    /* try { // try from 007555c9 to 007555cd has its CatchHandler @ 00755a62 */
    QString::arg(&local_50,(QString *)local_40,*param_1 + 0x18 + (long)*(int *)(*param_1 + 8) * 8,0,
                 0x20);
    if (*(int *)local_40[0] == 0) {
LAB_0075591e:
      QArrayData::deallocate(local_40[0],2,8);
    }
    else if (*(int *)local_40[0] != -1) {
      LOCK();
      *(int *)local_40[0] = *(int *)local_40[0] + -1;
      UNLOCK();
      if (*(int *)local_40[0] == 0) goto LAB_0075591e;
    }
                    /* try { // try from 007555f5 to 00755677 has its CatchHandler @ 00755a6a */
    FUN_00752ba8((QString *)local_40,param_2,&local_50);
    if (1 < *(uint *)*param_1) {
                    /* try { // try from 00755948 to 0075594c has its CatchHandler @ 00755a2a */
      FUN_00525800(param_1,((uint *)*param_1)[1]);
    }
    puVar2 = (undefined8 *)(*param_1 + 0x10 + (long)*(int *)(*param_1 + 8) * 8);
    pQVar4 = (QArrayData *)*puVar2;
    *puVar2 = local_40[0];
    local_40[0] = pQVar4;
    if (*(int *)pQVar4 == 0) {
LAB_00755845:
      QArrayData::deallocate(pQVar4,2,8);
      puVar5 = (uint *)*param_1;
      uVar3 = *puVar5;
    }
    else {
      if (*(int *)pQVar4 != -1) {
        LOCK();
        *(int *)pQVar4 = *(int *)pQVar4 + -1;
        UNLOCK();
        if (*(int *)pQVar4 == 0) goto LAB_00755845;
      }
      puVar5 = (uint *)*param_1;
      uVar3 = *puVar5;
    }
    if (1 < uVar3) {
                    /* try { // try from 0075586d to 00755871 has its CatchHandler @ 00755a6a */
      FUN_00525800(param_1,puVar5[1]);
    }
    cVar6 = FUN_00755204(param_2,*param_1 + 0x10 + (long)*(int *)(*param_1 + 8) * 8);
    if (cVar6 == '\0') {
      local_48 = (QArrayData *)QString::fromAscii_helper("default",7);
                    /* try { // try from 00755693 to 00755697 has its CatchHandler @ 00755a7a */
      FUN_00752a7e((QString *)local_40,param_2,&local_48,&local_50);
      if (1 < *(uint *)*param_1) {
                    /* try { // try from 007559c8 to 007559cc has its CatchHandler @ 00755a32 */
        FUN_00525800(param_1,((uint *)*param_1)[1]);
      }
      puVar2 = (undefined8 *)(*param_1 + 0x10 + (long)*(int *)(*param_1 + 8) * 8);
      pQVar4 = (QArrayData *)*puVar2;
      *puVar2 = local_40[0];
      local_40[0] = pQVar4;
      if (*(int *)pQVar4 == 0) {
LAB_007559d2:
        QArrayData::deallocate(pQVar4,2,8);
      }
      else if (*(int *)pQVar4 != -1) {
        LOCK();
        *(int *)pQVar4 = *(int *)pQVar4 + -1;
        UNLOCK();
        if (*(int *)pQVar4 == 0) goto LAB_007559d2;
      }
      if (*(int *)local_48 == 0) {
LAB_007559f0:
        QArrayData::deallocate(local_48,2,8);
      }
      else if (*(int *)local_48 != -1) {
        LOCK();
        *(int *)local_48 = *(int *)local_48 + -1;
        UNLOCK();
        if (*(int *)local_48 == 0) goto LAB_007559f0;
      }
    }
    if (*(int *)local_50 == 0) {
LAB_007558fd:
      QArrayData::deallocate(local_50,2,8);
      FUN_00525060(&local_58);
    }
    else {
      if (*(int *)local_50 != -1) {
        LOCK();
        *(int *)local_50 = *(int *)local_50 + -1;
        UNLOCK();
        if (*(int *)local_50 == 0) goto LAB_007558fd;
      }
      FUN_00525060(&local_58);
    }
  }
  else {
    QDir::fromNativeSeparators((QString *)local_40);
    if (1 < *(uint *)*param_1) {
      FUN_00525800(param_1,((uint *)*param_1)[1]);
    }
    QString::operator=((QString *)(*param_1 + 0x10 + (long)*(int *)(*param_1 + 8) * 8),
                       (QString *)local_40);
    if (1 < *(uint *)*param_1) {
                    /* try { // try from 00755815 to 00755826 has its CatchHandler @ 00755a3a */
      FUN_00525800(param_1,((uint *)*param_1)[1]);
    }
    QString::operator=((QString *)(*param_1 + 0x18 + (long)*(int *)(*param_1 + 8) * 8),
                       (QString *)local_40);
    if (*(int *)local_40[0] == 0) {
LAB_007557e2:
      QArrayData::deallocate(local_40[0],2,8);
      puVar5 = (uint *)*param_1;
      uVar3 = *puVar5;
      goto joined_r0x007557f9;
    }
    if (*(int *)local_40[0] != -1) {
      LOCK();
      *(int *)local_40[0] = *(int *)local_40[0] + -1;
      UNLOCK();
      if (*(int *)local_40[0] == 0) goto LAB_007557e2;
    }
  }
  puVar5 = (uint *)*param_1;
  uVar3 = *puVar5;
joined_r0x007557f9:
  if (1 < uVar3) {
    FUN_00525800(param_1,puVar5[1]);
  }
                    /* try { // try from 0075573c to 00755809 has its CatchHandler @ 00755a4a */
  cVar6 = FUN_00755204(param_2,*param_1 + 0x10 + (long)*(int *)(*param_1 + 8) * 8);
  if (cVar6 == '\0') {
    if (1 < *(uint *)*param_1) {
                    /* try { // try from 00755958 to 0075595c has its CatchHandler @ 00755a4a */
      FUN_00525800(param_1,((uint *)*param_1)[1]);
    }
    puVar2 = (undefined8 *)(*param_1 + 0x10 + (long)*(int *)(*param_1 + 8) * 8);
    pQVar4 = (QArrayData *)*puVar2;
    if (pQVar4 != (QArrayData *)&QArrayData::shared_null) {
      *puVar2 = &QArrayData::shared_null;
      if (*(int *)pQVar4 != 0) {
        if (*(int *)pQVar4 == -1) {
          return param_1;
        }
        LOCK();
        *(int *)pQVar4 = *(int *)pQVar4 + -1;
        UNLOCK();
        if (*(int *)pQVar4 != 0) {
          return param_1;
        }
      }
      QArrayData::deallocate(pQVar4,2,8);
    }
  }
  return param_1;
}


