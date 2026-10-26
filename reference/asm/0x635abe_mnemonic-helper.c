// entry=00635abe size=1255  (decompiled by Ghidra package ghidra, Utility, version 12.1.4)

QString * FUN_00635abe(QString *param_1,long param_2,undefined8 param_3,char *param_4)

{
  long lVar1;
  char cVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  ulong uVar6;
  long *plVar7;
  uint uVar8;
  QArrayData *pQVar9;
  int iVar10;
  uint uVar11;
  char *__s;
  undefined **ppuVar12;
  QArrayData *local_58;
  QArrayData *local_50;
  QArrayData *local_48;
  QArrayData *local_40 [2];
  
  if (param_4 != (char *)0x0) {
    strlen(param_4);
  }
  QString::fromUtf8_helper((char *)param_1,(int)param_4);
                    /* try { // try from 00635af6 to 00635afa has its CatchHandler @ 00635fa5 */
  cVar2 = FUN_0063574a(param_2);
  if (cVar2 == '\0') {
    return param_1;
  }
  local_58 = *(QArrayData **)param_1;
  if ((*(uint *)local_58 != 0) && (*(uint *)local_58 != 0xffffffff)) {
    LOCK();
    *(uint *)local_58 = *(uint *)local_58 + 1;
    UNLOCK();
  }
  local_50 = (QArrayData *)&QArrayData::shared_null;
  ppuVar12 = &PTR_s___00ca0e03_0x19_0117ee10;
  __s = ":";
LAB_00635b4a:
  uVar6 = strlen(__s);
  do {
                    /* try { // try from 00635b71 to 00635bb6 has its CatchHandler @ 00635fc5 */
    cVar2 = QString::endsWith(&local_58,uVar6 & 0xffffffff,__s,1);
    if (cVar2 != '\0') {
      if (__s != (char *)0x0) {
        strlen(__s);
      }
      QString::fromUtf8_helper((char *)&local_48,(int)__s);
      pQVar9 = local_50;
      local_50 = local_48;
      local_48 = pQVar9;
      if (*(int *)pQVar9 == 0) {
LAB_00635bdc:
        QArrayData::deallocate(pQVar9,2,8);
      }
      else if (*(int *)pQVar9 != -1) {
        LOCK();
        *(int *)pQVar9 = *(int *)pQVar9 + -1;
        UNLOCK();
        if (*(int *)pQVar9 == 0) goto LAB_00635bdc;
      }
LAB_00635bf0:
      uVar8 = (uint)&local_58;
      if (*(int *)(local_50 + 4) != 0) {
                    /* try { // try from 00635e59 to 00635e5d has its CatchHandler @ 00635fc5 */
        QString::chop(uVar8);
      }
                    /* try { // try from 00635c12 to 00635ce0 has its CatchHandler @ 00635fad */
      iVar3 = QString::count(&local_58,0x26,1);
      if (iVar3 == 1) {
                    /* try { // try from 00635e92 to 00635f77 has its CatchHandler @ 00635fad */
        iVar3 = QString::indexOf(&local_58,0x26,0,1);
        iVar10 = iVar3 + 1;
        uVar5 = *(uint *)(local_58 + 4);
        if (iVar10 < (int)uVar5) {
          if ((1 < *(uint *)local_58) || (*(long *)(local_58 + 0x10) != 0x18)) {
            QString::reallocData(uVar8,(bool)((char)*(uint *)(local_58 + 4) + '\x01'));
          }
          if (iVar10 < (int)*(uint *)(local_58 + 4)) {
            uVar11 = (uint)*(ushort *)(local_58 + *(long *)(local_58 + 0x10) + (long)iVar10 * 2);
          }
          else {
            uVar11 = 0;
          }
          QString::remove(uVar8,iVar3);
          uVar5 = *(uint *)(local_58 + 4);
        }
        else {
          uVar11 = 0;
        }
      }
      else {
        uVar5 = *(uint *)(local_58 + 4);
        uVar11 = 0;
      }
      if (uVar5 != 0) {
        lVar1 = *(long *)(param_2 + 0x18);
        if (*(int *)(lVar1 + 0x14) == 0) {
LAB_00635c41:
          local_40[0] = (QArrayData *)&QArrayData::shared_null;
        }
        else {
          if (*(int *)(lVar1 + 0x20) == 0) {
            uVar4 = 0;
          }
          else {
            uVar4 = qHash((QString *)&local_58,*(uint *)(lVar1 + 0x24));
          }
          plVar7 = (long *)FUN_0061c04c(param_2 + 0x18,&local_58,uVar4);
          if (*plVar7 == *(long *)(param_2 + 0x18)) goto LAB_00635c41;
          local_40[0] = *(QArrayData **)(*plVar7 + 0x18);
          if ((*(int *)local_40[0] != 0) && (*(int *)local_40[0] != -1)) {
            LOCK();
            *(int *)local_40[0] = *(int *)local_40[0] + 1;
            UNLOCK();
          }
        }
        QString::operator=((QString *)&local_58,(QString *)local_40);
        if (*(int *)local_40[0] == 0) {
LAB_00635e6a:
          QArrayData::deallocate(local_40[0],2,8);
        }
        else if (*(int *)local_40[0] != -1) {
          LOCK();
          *(int *)local_40[0] = *(int *)local_40[0] + -1;
          UNLOCK();
          if (*(int *)local_40[0] == 0) goto LAB_00635e6a;
        }
        if (*(uint *)(local_58 + 4) != 0) {
          if (*(int *)(local_50 + 4) != 0) {
            QString::append((QString *)&local_58);
          }
          if ((short)uVar11 == 0) goto LAB_00635dd7;
          if ((uVar11 - 0x30 < 10) ||
             ((0x7f < uVar11 && (cVar2 = QChar::isNumber_helper(uVar11), cVar2 != '\0')))) {
                    /* try { // try from 00635d6c to 00635d95 has its CatchHandler @ 00635fad */
            uVar5 = QString::indexOf(&local_58,uVar11,0,1);
            if (uVar5 == 0xffffffff) goto LAB_00635ccb;
            QString::fromUtf8_helper((char *)local_40,0xcf2cc2);
                    /* try { // try from 00635da8 to 00635dac has its CatchHandler @ 00635fb5 */
            QString::insert(uVar8,(QChar *)(ulong)uVar5,
                            (int)local_40[0] + (int)*(undefined8 *)(local_40[0] + 0x10));
            pQVar9 = local_40[0];
            if (*(int *)local_40[0] != 0) {
              if (*(int *)local_40[0] == -1) goto LAB_00635dd7;
              LOCK();
              *(int *)local_40[0] = *(int *)local_40[0] + -1;
              iVar3 = *(int *)local_40[0];
              UNLOCK();
              goto joined_r0x00635dc1;
            }
LAB_00635dc8:
            QArrayData::deallocate(pQVar9,2,8);
          }
          else {
LAB_00635ccb:
            local_48 = (QArrayData *)QString::fromAscii_helper("(&%1)",5);
            uVar4 = QChar::toUpper(uVar11);
                    /* try { // try from 00635d03 to 00635d07 has its CatchHandler @ 00635fcd */
            QString::arg((QString *)local_40,&local_48,uVar4,0,0x20);
                    /* try { // try from 00635d0e to 00635d12 has its CatchHandler @ 00635fbd */
            QString::append((QString *)&local_58);
            if (*(int *)local_40[0] == 0) {
LAB_00635f82:
              QArrayData::deallocate(local_40[0],2,8);
            }
            else if (*(int *)local_40[0] != -1) {
              LOCK();
              *(int *)local_40[0] = *(int *)local_40[0] + -1;
              UNLOCK();
              if (*(int *)local_40[0] == 0) goto LAB_00635f82;
            }
            pQVar9 = local_48;
            if (*(int *)local_48 == 0) goto LAB_00635dc8;
            if (*(int *)local_48 != -1) {
              LOCK();
              *(int *)local_48 = *(int *)local_48 + -1;
              iVar3 = *(int *)local_48;
              UNLOCK();
joined_r0x00635dc1:
              if (iVar3 == 0) goto LAB_00635dc8;
            }
          }
LAB_00635dd7:
          QString::operator=(param_1,(QString *)&local_58);
        }
      }
      if (*(int *)local_50 != 0) {
        if (*(int *)local_50 == -1) goto LAB_00635df8;
        LOCK();
        *(int *)local_50 = *(int *)local_50 + -1;
        UNLOCK();
        if (*(int *)local_50 != 0) goto LAB_00635df8;
      }
      QArrayData::deallocate(local_50,2,8);
LAB_00635df8:
      if (*(int *)local_58 != 0) {
        if (*(int *)local_58 == -1) {
          return param_1;
        }
        LOCK();
        *(int *)local_58 = *(int *)local_58 + -1;
        UNLOCK();
        if (*(int *)local_58 != 0) {
          return param_1;
        }
      }
      QArrayData::deallocate(local_58,2,8);
      return param_1;
    }
    ppuVar12 = ppuVar12 + 1;
    if (ppuVar12 == (undefined **)&DAT_0117ee28) goto LAB_00635bf0;
    __s = *ppuVar12;
    if (__s != (char *)0x0) goto LAB_00635b4a;
    uVar6 = 0;
  } while( true );
}


