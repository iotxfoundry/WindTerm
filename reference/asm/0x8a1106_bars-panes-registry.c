// entry=008a1106 size=12455  (decompiled by Ghidra package ghidra, Utility, version 12.1.4)

/* WARNING: Removing unreachable block (ram,0x008a3446) */
/* WARNING: Removing unreachable block (ram,0x008a345a) */
/* WARNING: Removing unreachable block (ram,0x008a346e) */
/* WARNING: Removing unreachable block (ram,0x008a3482) */
/* WARNING: Removing unreachable block (ram,0x008a3496) */
/* WARNING: Removing unreachable block (ram,0x008a34aa) */
/* WARNING: Removing unreachable block (ram,0x008a34be) */
/* WARNING: Removing unreachable block (ram,0x008a34d2) */
/* WARNING: Removing unreachable block (ram,0x008a34c8) */
/* WARNING: Removing unreachable block (ram,0x008a34b4) */
/* WARNING: Removing unreachable block (ram,0x008a34a0) */
/* WARNING: Removing unreachable block (ram,0x008a348c) */
/* WARNING: Removing unreachable block (ram,0x008a3478) */
/* WARNING: Removing unreachable block (ram,0x008a3464) */
/* WARNING: Removing unreachable block (ram,0x008a3450) */
/* WARNING: Removing unreachable block (ram,0x008a343c) */

undefined8 * FUN_008a1106(undefined8 *param_1,QString *param_2)

{
  long *plVar1;
  QMapNodeBase *pQVar2;
  long lVar3;
  long lVar4;
  long lVar5;
  long lVar6;
  char cVar7;
  int iVar8;
  size_t sVar9;
  long lVar10;
  int *piVar11;
  QMapNodeBase *pQVar12;
  ulong *puVar13;
  QString *pQVar14;
  long lVar15;
  QArrayData *pQVar16;
  QMapNodeBase *pQVar17;
  int *piVar18;
  QMapNodeBase *pQVar19;
  QMapNodeBase *pQVar20;
  undefined8 *local_1b8;
  QArrayData *local_1b0;
  QArrayData *local_1a8;
  QArrayData *local_1a0;
  QArrayData *local_198;
  QArrayData *local_190;
  QArrayData *local_188;
  QArrayData *local_180;
  undefined8 *local_178;
  undefined8 *local_170;
  undefined8 *local_168;
  undefined8 *local_160;
  undefined8 *local_158;
  undefined8 *local_150;
  undefined8 *local_148;
  undefined8 *local_140;
  QArrayData *local_138 [30];
  undefined8 local_48;
  undefined8 *local_40;
  QString local_38 [8];
  
  QMetaObject::tr((char *)&local_1b8,(char *)&QObject::staticMetaObject,0xcb9a98);
  sVar9 = strlen("AppletBar");
                    /* try { // try from 008a116c to 008a11be has its CatchHandler @ 008a41b5 */
  local_138[0] = (QArrayData *)QString::fromAscii_helper("AppletBar",(int)sVar9);
  local_138[1] = (QArrayData *)local_1b8;
  piVar18 = (int *)&QArrayData::shared_null;
  local_1b8 = &QArrayData::shared_null;
  QMetaObject::tr((char *)&local_1b0,(char *)&QObject::staticMetaObject,0xcb9aa3);
  sVar9 = strlen("KitBar");
                    /* try { // try from 008a11df to 008a122a has its CatchHandler @ 008a41ad */
  local_138[2] = (QArrayData *)QString::fromAscii_helper("KitBar",(int)sVar9);
  local_138[3] = local_1b0;
  local_1b0 = (QArrayData *)&QArrayData::shared_null;
  QMetaObject::tr((char *)&local_1a8,(char *)&QObject::staticMetaObject,0xcb9aab);
  sVar9 = strlen("MenuBar");
                    /* try { // try from 008a124b to 008a1296 has its CatchHandler @ 008a41c5 */
  local_138[4] = (QArrayData *)QString::fromAscii_helper("MenuBar",(int)sVar9);
  local_138[5] = local_1a8;
  local_1a8 = (QArrayData *)&QArrayData::shared_null;
  QMetaObject::tr((char *)&local_1a0,(char *)&QObject::staticMetaObject,0xc9f04f);
  sVar9 = strlen("QuickBar");
                    /* try { // try from 008a12b7 to 008a1305 has its CatchHandler @ 008a41bd */
  local_138[6] = (QArrayData *)QString::fromAscii_helper("QuickBar",(int)sVar9);
  local_138[7] = local_1a0;
  local_1a0 = (QArrayData *)&QArrayData::shared_null;
  QMetaObject::tr((char *)&local_198,(char *)&QObject::staticMetaObject,0xcb9ab4);
  sVar9 = strlen("StatusBar");
                    /* try { // try from 008a1326 to 008a1374 has its CatchHandler @ 008a41d5 */
  local_138[8] = (QArrayData *)QString::fromAscii_helper("StatusBar",(int)sVar9);
  local_138[9] = local_198;
  local_198 = (QArrayData *)&QArrayData::shared_null;
  QMetaObject::tr((char *)&local_190,(char *)&QObject::staticMetaObject,0xcb9abf);
  sVar9 = strlen("ToolBar");
                    /* try { // try from 008a1395 to 008a13e3 has its CatchHandler @ 008a41cd */
  local_138[10] = (QArrayData *)QString::fromAscii_helper("ToolBar",(int)sVar9);
  local_138[0xb] = local_190;
  local_190 = (QArrayData *)&QArrayData::shared_null;
  QMetaObject::tr((char *)&local_188,(char *)&QObject::staticMetaObject,0xcb9ac8);
  sVar9 = strlen("TransferBar");
                    /* try { // try from 008a1404 to 008a1452 has its CatchHandler @ 008a4255 */
  local_138[0xc] = (QArrayData *)QString::fromAscii_helper("TransferBar",(int)sVar9);
  local_138[0xd] = local_188;
  local_188 = (QArrayData *)&QArrayData::shared_null;
  QMetaObject::tr((char *)&local_180,(char *)&QObject::staticMetaObject,0xcb9ad5);
  sVar9 = strlen("ExplorerPane");
                    /* try { // try from 008a1473 to 008a14be has its CatchHandler @ 008a424d */
  local_138[0xe] = (QArrayData *)QString::fromAscii_helper("ExplorerPane",(int)sVar9);
  local_138[0xf] = local_180;
  local_180 = (QArrayData *)&QArrayData::shared_null;
  QMetaObject::tr((char *)&local_178,(char *)&QObject::staticMetaObject,0xc89afa);
  sVar9 = strlen("FilerPane");
                    /* try { // try from 008a14df to 008a152a has its CatchHandler @ 008a4265 */
  local_138[0x10] = (QArrayData *)QString::fromAscii_helper("FilerPane",(int)sVar9);
  local_138[0x11] = (QArrayData *)local_178;
  local_178 = &QArrayData::shared_null;
  QMetaObject::tr((char *)&local_170,(char *)&QObject::staticMetaObject,0xcb9ade);
  sVar9 = strlen("OutlinePane");
                    /* try { // try from 008a154b to 008a1596 has its CatchHandler @ 008a425d */
  local_138[0x12] = (QArrayData *)QString::fromAscii_helper("OutlinePane",(int)sVar9);
  local_138[0x13] = (QArrayData *)local_170;
  local_170 = &QArrayData::shared_null;
  QMetaObject::tr((char *)&local_168,(char *)&QObject::staticMetaObject,0xca044d);
  sVar9 = strlen("OutputPane");
                    /* try { // try from 008a15b7 to 008a1602 has its CatchHandler @ 008a4235 */
  local_138[0x14] = (QArrayData *)QString::fromAscii_helper("OutputPane",(int)sVar9);
  local_138[0x15] = (QArrayData *)local_168;
  local_168 = &QArrayData::shared_null;
  QMetaObject::tr((char *)&local_160,(char *)&QObject::staticMetaObject,0xcb9ae6);
  sVar9 = strlen("SenderPane");
                    /* try { // try from 008a1623 to 008a166e has its CatchHandler @ 008a422a */
  local_138[0x16] = (QArrayData *)QString::fromAscii_helper("SenderPane",(int)sVar9);
  local_138[0x17] = (QArrayData *)local_160;
  local_160 = &QArrayData::shared_null;
  QMetaObject::tr((char *)&local_158,(char *)&QObject::staticMetaObject,0xcba2c0);
  sVar9 = strlen("SessionPane");
                    /* try { // try from 008a168f to 008a16da has its CatchHandler @ 008a4245 */
  local_138[0x18] = (QArrayData *)QString::fromAscii_helper("SessionPane",(int)sVar9);
  local_138[0x19] = (QArrayData *)local_158;
  local_158 = &QArrayData::shared_null;
  QMetaObject::tr((char *)&local_150,(char *)&QObject::staticMetaObject,0xcb9aed);
  sVar9 = strlen("TransferPane");
                    /* try { // try from 008a16fb to 008a1746 has its CatchHandler @ 008a423d */
  local_138[0x1a] = (QArrayData *)QString::fromAscii_helper("TransferPane",(int)sVar9);
  local_138[0x1b] = (QArrayData *)local_150;
  local_150 = &QArrayData::shared_null;
  QMetaObject::tr((char *)&local_148,(char *)&QObject::staticMetaObject,0xc9f05f);
  sVar9 = strlen("SearchPane");
                    /* try { // try from 008a1767 to 008a17b2 has its CatchHandler @ 008a421a */
  local_138[0x1c] = (QArrayData *)QString::fromAscii_helper("SearchPane",(int)sVar9);
  local_138[0x1d] = (QArrayData *)local_148;
  local_148 = &QArrayData::shared_null;
  QMetaObject::tr((char *)&local_140,(char *)&QObject::staticMetaObject,0xcb9af6);
  sVar9 = strlen("ShellPane");
                    /* try { // try from 008a17d3 to 008a17d7 has its CatchHandler @ 008a4205 */
  local_48 = QString::fromAscii_helper("ShellPane",(int)sVar9);
  local_40 = local_140;
  local_140 = &QArrayData::shared_null;
  pQVar17 = (QMapNodeBase *)&QMapDataBase::shared_null;
  pQVar19 = (QMapNodeBase *)&QMapDataBase::shared_null;
  pQVar14 = (QString *)local_138;
  do {
    if (*(uint *)pQVar17 < 2) {
      pQVar2 = *(QMapNodeBase **)(pQVar19 + 0x10);
    }
    else {
                    /* try { // try from 008a1b73 to 008a1b77 has its CatchHandler @ 008a41ea */
      pQVar12 = (QMapNodeBase *)QMapDataBase::createData();
      if (*(long *)(pQVar19 + 0x10) != 0) {
                    /* try { // try from 008a1b87 to 008a1b8b has its CatchHandler @ 008a41e5 */
        puVar13 = (ulong *)FUN_0053d420(*(long *)(pQVar19 + 0x10),pQVar12);
        *(ulong **)(pQVar12 + 0x10) = puVar13;
        *puVar13 = (ulong)((uint)*puVar13 & 3) | (ulong)(pQVar12 + 8);
      }
      if (*(int *)pQVar17 == 0) {
LAB_008a1bf1:
        lVar10 = *(long *)(pQVar19 + 0x10);
        if (lVar10 != 0) {
          FUN_005249f0(lVar10 + 0x18);
          FUN_005249f0(lVar10 + 0x20);
          lVar3 = *(long *)(lVar10 + 8);
          if (lVar3 != 0) {
            FUN_005249f0(lVar3 + 0x18);
            FUN_005249f0(lVar3 + 0x20);
            lVar15 = *(long *)(lVar3 + 8);
            if (lVar15 != 0) {
              FUN_005249f0(lVar15 + 0x18);
              FUN_005249f0(lVar15 + 0x20);
              lVar4 = *(long *)(lVar15 + 8);
              if (lVar4 != 0) {
                FUN_005249f0(lVar4 + 0x18);
                FUN_005249f0(lVar4 + 0x20);
                lVar5 = *(long *)(lVar4 + 8);
                if (lVar5 != 0) {
                  FUN_005249f0(lVar5 + 0x18);
                  FUN_005249f0(lVar5 + 0x20);
                  lVar6 = *(long *)(lVar5 + 8);
                  if (lVar6 != 0) {
                    pQVar16 = *(QArrayData **)(lVar6 + 0x18);
                    if (*(int *)pQVar16 == 0) {
LAB_008a3d41:
                      QArrayData::deallocate(pQVar16,2,8);
                    }
                    else if (*(int *)pQVar16 != -1) {
                      LOCK();
                      *(int *)pQVar16 = *(int *)pQVar16 + -1;
                      UNLOCK();
                      if (*(int *)pQVar16 == 0) {
                        pQVar16 = *(QArrayData **)(lVar6 + 0x18);
                        goto LAB_008a3d41;
                      }
                    }
                    pQVar16 = *(QArrayData **)(lVar6 + 0x20);
                    if (*(int *)pQVar16 == 0) {
LAB_008a3cd1:
                      QArrayData::deallocate(pQVar16,2,8);
                    }
                    else if (*(int *)pQVar16 != -1) {
                      LOCK();
                      *(int *)pQVar16 = *(int *)pQVar16 + -1;
                      UNLOCK();
                      if (*(int *)pQVar16 == 0) {
                        pQVar16 = *(QArrayData **)(lVar6 + 0x20);
                        goto LAB_008a3cd1;
                      }
                    }
                    if (*(long *)(lVar6 + 8) != 0) {
                      FUN_0053b726();
                    }
                    if (*(long *)(lVar6 + 0x10) != 0) {
                      FUN_0053b726();
                    }
                  }
                  lVar5 = *(long *)(lVar5 + 0x10);
                  if (lVar5 != 0) {
                    pQVar16 = *(QArrayData **)(lVar5 + 0x18);
                    if (*(int *)pQVar16 == 0) {
LAB_008a3d89:
                      QArrayData::deallocate(pQVar16,2,8);
                    }
                    else if (*(int *)pQVar16 != -1) {
                      LOCK();
                      *(int *)pQVar16 = *(int *)pQVar16 + -1;
                      UNLOCK();
                      if (*(int *)pQVar16 == 0) {
                        pQVar16 = *(QArrayData **)(lVar5 + 0x18);
                        goto LAB_008a3d89;
                      }
                    }
                    pQVar16 = *(QArrayData **)(lVar5 + 0x20);
                    if (*(int *)pQVar16 == 0) {
LAB_008a36c1:
                      QArrayData::deallocate(pQVar16,2,8);
                    }
                    else if (*(int *)pQVar16 != -1) {
                      LOCK();
                      *(int *)pQVar16 = *(int *)pQVar16 + -1;
                      UNLOCK();
                      if (*(int *)pQVar16 == 0) {
                        pQVar16 = *(QArrayData **)(lVar5 + 0x20);
                        goto LAB_008a36c1;
                      }
                    }
                    if (*(long *)(lVar5 + 8) != 0) {
                      FUN_0053b726();
                    }
                    if (*(long *)(lVar5 + 0x10) != 0) {
                      FUN_0053b726();
                    }
                  }
                }
                lVar4 = *(long *)(lVar4 + 0x10);
                if (lVar4 != 0) {
                  FUN_005249f0(lVar4 + 0x18);
                  FUN_005249f0(lVar4 + 0x20);
                  lVar5 = *(long *)(lVar4 + 8);
                  if (lVar5 != 0) {
                    pQVar16 = *(QArrayData **)(lVar5 + 0x18);
                    if (*(int *)pQVar16 == 0) {
LAB_008a37e1:
                      QArrayData::deallocate(pQVar16,2,8);
                    }
                    else if (*(int *)pQVar16 != -1) {
                      LOCK();
                      *(int *)pQVar16 = *(int *)pQVar16 + -1;
                      UNLOCK();
                      if (*(int *)pQVar16 == 0) {
                        pQVar16 = *(QArrayData **)(lVar5 + 0x18);
                        goto LAB_008a37e1;
                      }
                    }
                    pQVar16 = *(QArrayData **)(lVar5 + 0x20);
                    if (*(int *)pQVar16 == 0) {
LAB_008a37a9:
                      QArrayData::deallocate(pQVar16,2,8);
                    }
                    else if (*(int *)pQVar16 != -1) {
                      LOCK();
                      *(int *)pQVar16 = *(int *)pQVar16 + -1;
                      UNLOCK();
                      if (*(int *)pQVar16 == 0) {
                        pQVar16 = *(QArrayData **)(lVar5 + 0x20);
                        goto LAB_008a37a9;
                      }
                    }
                    if (*(long *)(lVar5 + 8) != 0) {
                      FUN_0053b726();
                    }
                    if (*(long *)(lVar5 + 0x10) != 0) {
                      FUN_0053b726();
                    }
                  }
                  lVar4 = *(long *)(lVar4 + 0x10);
                  if (lVar4 != 0) {
                    pQVar16 = *(QArrayData **)(lVar4 + 0x18);
                    if (*(int *)pQVar16 == 0) {
LAB_008a3781:
                      QArrayData::deallocate(pQVar16,2,8);
                    }
                    else if (*(int *)pQVar16 != -1) {
                      LOCK();
                      *(int *)pQVar16 = *(int *)pQVar16 + -1;
                      UNLOCK();
                      if (*(int *)pQVar16 == 0) {
                        pQVar16 = *(QArrayData **)(lVar4 + 0x18);
                        goto LAB_008a3781;
                      }
                    }
                    pQVar16 = *(QArrayData **)(lVar4 + 0x20);
                    if (*(int *)pQVar16 == 0) {
LAB_008a3759:
                      QArrayData::deallocate(pQVar16,2,8);
                    }
                    else if (*(int *)pQVar16 != -1) {
                      LOCK();
                      *(int *)pQVar16 = *(int *)pQVar16 + -1;
                      UNLOCK();
                      if (*(int *)pQVar16 == 0) {
                        pQVar16 = *(QArrayData **)(lVar4 + 0x20);
                        goto LAB_008a3759;
                      }
                    }
                    if (*(long *)(lVar4 + 8) != 0) {
                      FUN_0053b726();
                    }
                    if (*(long *)(lVar4 + 0x10) != 0) {
                      FUN_0053b726();
                    }
                  }
                }
              }
              lVar15 = *(long *)(lVar15 + 0x10);
              if (lVar15 != 0) {
                FUN_005249f0(lVar15 + 0x18);
                FUN_005249f0(lVar15 + 0x20);
                lVar4 = *(long *)(lVar15 + 8);
                if (lVar4 != 0) {
                  FUN_005249f0(lVar4 + 0x18);
                  FUN_005249f0(lVar4 + 0x20);
                  lVar5 = *(long *)(lVar4 + 8);
                  if (lVar5 != 0) {
                    pQVar16 = *(QArrayData **)(lVar5 + 0x18);
                    if (*(int *)pQVar16 == 0) {
LAB_008a3591:
                      QArrayData::deallocate(pQVar16,2,8);
                    }
                    else if (*(int *)pQVar16 != -1) {
                      LOCK();
                      *(int *)pQVar16 = *(int *)pQVar16 + -1;
                      UNLOCK();
                      if (*(int *)pQVar16 == 0) {
                        pQVar16 = *(QArrayData **)(lVar5 + 0x18);
                        goto LAB_008a3591;
                      }
                    }
                    pQVar16 = *(QArrayData **)(lVar5 + 0x20);
                    if (*(int *)pQVar16 == 0) {
LAB_008a35d9:
                      QArrayData::deallocate(pQVar16,2,8);
                    }
                    else if (*(int *)pQVar16 != -1) {
                      LOCK();
                      *(int *)pQVar16 = *(int *)pQVar16 + -1;
                      UNLOCK();
                      if (*(int *)pQVar16 == 0) {
                        pQVar16 = *(QArrayData **)(lVar5 + 0x20);
                        goto LAB_008a35d9;
                      }
                    }
                    if (*(long *)(lVar5 + 8) != 0) {
                      FUN_0053b726();
                    }
                    if (*(long *)(lVar5 + 0x10) != 0) {
                      FUN_0053b726();
                    }
                  }
                  lVar4 = *(long *)(lVar4 + 0x10);
                  if (lVar4 != 0) {
                    pQVar16 = *(QArrayData **)(lVar4 + 0x18);
                    if (*(int *)pQVar16 == 0) {
LAB_008a3559:
                      QArrayData::deallocate(pQVar16,2,8);
                    }
                    else if (*(int *)pQVar16 != -1) {
                      LOCK();
                      *(int *)pQVar16 = *(int *)pQVar16 + -1;
                      UNLOCK();
                      if (*(int *)pQVar16 == 0) {
                        pQVar16 = *(QArrayData **)(lVar4 + 0x18);
                        goto LAB_008a3559;
                      }
                    }
                    pQVar16 = *(QArrayData **)(lVar4 + 0x20);
                    if (*(int *)pQVar16 == 0) {
LAB_008a3521:
                      QArrayData::deallocate(pQVar16,2,8);
                    }
                    else if (*(int *)pQVar16 != -1) {
                      LOCK();
                      *(int *)pQVar16 = *(int *)pQVar16 + -1;
                      UNLOCK();
                      if (*(int *)pQVar16 == 0) {
                        pQVar16 = *(QArrayData **)(lVar4 + 0x20);
                        goto LAB_008a3521;
                      }
                    }
                    if (*(long *)(lVar4 + 8) != 0) {
                      FUN_0053b726();
                    }
                    if (*(long *)(lVar4 + 0x10) != 0) {
                      FUN_0053b726();
                    }
                  }
                }
                lVar15 = *(long *)(lVar15 + 0x10);
                if (lVar15 != 0) {
                  FUN_005249f0(lVar15 + 0x18);
                  FUN_005249f0(lVar15 + 0x20);
                  lVar4 = *(long *)(lVar15 + 8);
                  if (lVar4 != 0) {
                    pQVar16 = *(QArrayData **)(lVar4 + 0x18);
                    if (*(int *)pQVar16 == 0) {
LAB_008a39e1:
                      QArrayData::deallocate(pQVar16,2,8);
                    }
                    else if (*(int *)pQVar16 != -1) {
                      LOCK();
                      *(int *)pQVar16 = *(int *)pQVar16 + -1;
                      UNLOCK();
                      if (*(int *)pQVar16 == 0) {
                        pQVar16 = *(QArrayData **)(lVar4 + 0x18);
                        goto LAB_008a39e1;
                      }
                    }
                    pQVar16 = *(QArrayData **)(lVar4 + 0x20);
                    if (*(int *)pQVar16 == 0) {
LAB_008a39a9:
                      QArrayData::deallocate(pQVar16,2,8);
                    }
                    else if (*(int *)pQVar16 != -1) {
                      LOCK();
                      *(int *)pQVar16 = *(int *)pQVar16 + -1;
                      UNLOCK();
                      if (*(int *)pQVar16 == 0) {
                        pQVar16 = *(QArrayData **)(lVar4 + 0x20);
                        goto LAB_008a39a9;
                      }
                    }
                    if (*(long *)(lVar4 + 8) != 0) {
                      FUN_0053b726();
                    }
                    if (*(long *)(lVar4 + 0x10) != 0) {
                      FUN_0053b726();
                    }
                  }
                  lVar15 = *(long *)(lVar15 + 0x10);
                  if (lVar15 != 0) {
                    pQVar16 = *(QArrayData **)(lVar15 + 0x18);
                    if (*(int *)pQVar16 == 0) {
LAB_008a3981:
                      QArrayData::deallocate(pQVar16,2,8);
                    }
                    else if (*(int *)pQVar16 != -1) {
                      LOCK();
                      *(int *)pQVar16 = *(int *)pQVar16 + -1;
                      UNLOCK();
                      if (*(int *)pQVar16 == 0) {
                        pQVar16 = *(QArrayData **)(lVar15 + 0x18);
                        goto LAB_008a3981;
                      }
                    }
                    pQVar16 = *(QArrayData **)(lVar15 + 0x20);
                    if (*(int *)pQVar16 == 0) {
LAB_008a3891:
                      QArrayData::deallocate(pQVar16,2,8);
                    }
                    else if (*(int *)pQVar16 != -1) {
                      LOCK();
                      *(int *)pQVar16 = *(int *)pQVar16 + -1;
                      UNLOCK();
                      if (*(int *)pQVar16 == 0) {
                        pQVar16 = *(QArrayData **)(lVar15 + 0x20);
                        goto LAB_008a3891;
                      }
                    }
                    if (*(long *)(lVar15 + 8) != 0) {
                      FUN_0053b726();
                    }
                    if (*(long *)(lVar15 + 0x10) != 0) {
                      FUN_0053b726();
                    }
                  }
                }
              }
            }
            lVar3 = *(long *)(lVar3 + 0x10);
            if (lVar3 != 0) {
              FUN_005249f0(lVar3 + 0x18);
              FUN_005249f0(lVar3 + 0x20);
              lVar15 = *(long *)(lVar3 + 8);
              if (lVar15 != 0) {
                FUN_005249f0(lVar15 + 0x18);
                FUN_005249f0(lVar15 + 0x20);
                lVar4 = *(long *)(lVar15 + 8);
                if (lVar4 != 0) {
                  FUN_005249f0(lVar4 + 0x18);
                  FUN_005249f0(lVar4 + 0x20);
                  lVar5 = *(long *)(lVar4 + 8);
                  if (lVar5 != 0) {
                    pQVar16 = *(QArrayData **)(lVar5 + 0x18);
                    if (*(int *)pQVar16 == 0) {
LAB_008a38f1:
                      QArrayData::deallocate(pQVar16,2,8);
                    }
                    else if (*(int *)pQVar16 != -1) {
                      LOCK();
                      *(int *)pQVar16 = *(int *)pQVar16 + -1;
                      UNLOCK();
                      if (*(int *)pQVar16 == 0) {
                        pQVar16 = *(QArrayData **)(lVar5 + 0x18);
                        goto LAB_008a38f1;
                      }
                    }
                    pQVar16 = *(QArrayData **)(lVar5 + 0x20);
                    if (*(int *)pQVar16 == 0) {
LAB_008a3939:
                      QArrayData::deallocate(pQVar16,2,8);
                    }
                    else if (*(int *)pQVar16 != -1) {
                      LOCK();
                      *(int *)pQVar16 = *(int *)pQVar16 + -1;
                      UNLOCK();
                      if (*(int *)pQVar16 == 0) {
                        pQVar16 = *(QArrayData **)(lVar5 + 0x20);
                        goto LAB_008a3939;
                      }
                    }
                    if (*(long *)(lVar5 + 8) != 0) {
                      FUN_0053b726();
                    }
                    if (*(long *)(lVar5 + 0x10) != 0) {
                      FUN_0053b726();
                    }
                  }
                  lVar4 = *(long *)(lVar4 + 0x10);
                  if (lVar4 != 0) {
                    pQVar16 = *(QArrayData **)(lVar4 + 0x18);
                    if (*(int *)pQVar16 == 0) {
LAB_008a38b9:
                      QArrayData::deallocate(pQVar16,2,8);
                    }
                    else if (*(int *)pQVar16 != -1) {
                      LOCK();
                      *(int *)pQVar16 = *(int *)pQVar16 + -1;
                      UNLOCK();
                      if (*(int *)pQVar16 == 0) {
                        pQVar16 = *(QArrayData **)(lVar4 + 0x18);
                        goto LAB_008a38b9;
                      }
                    }
                    pQVar16 = *(QArrayData **)(lVar4 + 0x20);
                    if (*(int *)pQVar16 == 0) {
LAB_008a3819:
                      QArrayData::deallocate(pQVar16,2,8);
                    }
                    else if (*(int *)pQVar16 != -1) {
                      LOCK();
                      *(int *)pQVar16 = *(int *)pQVar16 + -1;
                      UNLOCK();
                      if (*(int *)pQVar16 == 0) {
                        pQVar16 = *(QArrayData **)(lVar4 + 0x20);
                        goto LAB_008a3819;
                      }
                    }
                    if (*(long *)(lVar4 + 8) != 0) {
                      FUN_0053b726();
                    }
                    if (*(long *)(lVar4 + 0x10) != 0) {
                      FUN_0053b726();
                    }
                  }
                }
                lVar15 = *(long *)(lVar15 + 0x10);
                if (lVar15 != 0) {
                  FUN_005249f0(lVar15 + 0x18);
                  FUN_005249f0(lVar15 + 0x20);
                  lVar4 = *(long *)(lVar15 + 8);
                  if (lVar4 != 0) {
                    pQVar16 = *(QArrayData **)(lVar4 + 0x18);
                    if (*(int *)pQVar16 == 0) {
LAB_008a3ab9:
                      QArrayData::deallocate(pQVar16,2,8);
                    }
                    else if (*(int *)pQVar16 != -1) {
                      LOCK();
                      *(int *)pQVar16 = *(int *)pQVar16 + -1;
                      UNLOCK();
                      if (*(int *)pQVar16 == 0) {
                        pQVar16 = *(QArrayData **)(lVar4 + 0x18);
                        goto LAB_008a3ab9;
                      }
                    }
                    pQVar16 = *(QArrayData **)(lVar4 + 0x20);
                    if (*(int *)pQVar16 == 0) {
LAB_008a3a81:
                      QArrayData::deallocate(pQVar16,2,8);
                    }
                    else if (*(int *)pQVar16 != -1) {
                      LOCK();
                      *(int *)pQVar16 = *(int *)pQVar16 + -1;
                      UNLOCK();
                      if (*(int *)pQVar16 == 0) {
                        pQVar16 = *(QArrayData **)(lVar4 + 0x20);
                        goto LAB_008a3a81;
                      }
                    }
                    if (*(long *)(lVar4 + 8) != 0) {
                      FUN_0053b726();
                    }
                    if (*(long *)(lVar4 + 0x10) != 0) {
                      FUN_0053b726();
                    }
                  }
                  lVar15 = *(long *)(lVar15 + 0x10);
                  if (lVar15 != 0) {
                    pQVar16 = *(QArrayData **)(lVar15 + 0x18);
                    if (*(int *)pQVar16 == 0) {
LAB_008a3ca9:
                      QArrayData::deallocate(pQVar16,2,8);
                    }
                    else if (*(int *)pQVar16 != -1) {
                      LOCK();
                      *(int *)pQVar16 = *(int *)pQVar16 + -1;
                      UNLOCK();
                      if (*(int *)pQVar16 == 0) {
                        pQVar16 = *(QArrayData **)(lVar15 + 0x18);
                        goto LAB_008a3ca9;
                      }
                    }
                    pQVar16 = *(QArrayData **)(lVar15 + 0x20);
                    if (*(int *)pQVar16 == 0) {
LAB_008a3d19:
                      QArrayData::deallocate(pQVar16,2,8);
                    }
                    else if (*(int *)pQVar16 != -1) {
                      LOCK();
                      *(int *)pQVar16 = *(int *)pQVar16 + -1;
                      UNLOCK();
                      if (*(int *)pQVar16 == 0) {
                        pQVar16 = *(QArrayData **)(lVar15 + 0x20);
                        goto LAB_008a3d19;
                      }
                    }
                    if (*(long *)(lVar15 + 8) != 0) {
                      FUN_0053b726();
                    }
                    if (*(long *)(lVar15 + 0x10) != 0) {
                      FUN_0053b726();
                    }
                  }
                }
              }
              lVar3 = *(long *)(lVar3 + 0x10);
              if (lVar3 != 0) {
                FUN_005249f0(lVar3 + 0x18);
                FUN_005249f0(lVar3 + 0x20);
                lVar15 = *(long *)(lVar3 + 8);
                if (lVar15 != 0) {
                  FUN_005249f0(lVar15 + 0x18);
                  FUN_005249f0(lVar15 + 0x20);
                  lVar4 = *(long *)(lVar15 + 8);
                  if (lVar4 != 0) {
                    pQVar16 = *(QArrayData **)(lVar4 + 0x18);
                    if (*(int *)pQVar16 == 0) {
LAB_008a3b31:
                      QArrayData::deallocate(pQVar16,2,8);
                    }
                    else if (*(int *)pQVar16 != -1) {
                      LOCK();
                      *(int *)pQVar16 = *(int *)pQVar16 + -1;
                      UNLOCK();
                      if (*(int *)pQVar16 == 0) {
                        pQVar16 = *(QArrayData **)(lVar4 + 0x18);
                        goto LAB_008a3b31;
                      }
                    }
                    pQVar16 = *(QArrayData **)(lVar4 + 0x20);
                    if (*(int *)pQVar16 == 0) {
LAB_008a3af1:
                      QArrayData::deallocate(pQVar16,2,8);
                    }
                    else if (*(int *)pQVar16 != -1) {
                      LOCK();
                      *(int *)pQVar16 = *(int *)pQVar16 + -1;
                      UNLOCK();
                      if (*(int *)pQVar16 == 0) {
                        pQVar16 = *(QArrayData **)(lVar4 + 0x20);
                        goto LAB_008a3af1;
                      }
                    }
                    if (*(long *)(lVar4 + 8) != 0) {
                      FUN_0053b726();
                    }
                    if (*(long *)(lVar4 + 0x10) != 0) {
                      FUN_0053b726();
                    }
                  }
                  lVar15 = *(long *)(lVar15 + 0x10);
                  if (lVar15 != 0) {
                    pQVar16 = *(QArrayData **)(lVar15 + 0x18);
                    if (*(int *)pQVar16 == 0) {
LAB_008a3729:
                      QArrayData::deallocate(pQVar16,2,8);
                    }
                    else if (*(int *)pQVar16 != -1) {
                      LOCK();
                      *(int *)pQVar16 = *(int *)pQVar16 + -1;
                      UNLOCK();
                      if (*(int *)pQVar16 == 0) {
                        pQVar16 = *(QArrayData **)(lVar15 + 0x18);
                        goto LAB_008a3729;
                      }
                    }
                    pQVar16 = *(QArrayData **)(lVar15 + 0x20);
                    if (*(int *)pQVar16 == 0) {
LAB_008a36f9:
                      QArrayData::deallocate(pQVar16,2,8);
                    }
                    else if (*(int *)pQVar16 != -1) {
                      LOCK();
                      *(int *)pQVar16 = *(int *)pQVar16 + -1;
                      UNLOCK();
                      if (*(int *)pQVar16 == 0) {
                        pQVar16 = *(QArrayData **)(lVar15 + 0x20);
                        goto LAB_008a36f9;
                      }
                    }
                    if (*(long *)(lVar15 + 8) != 0) {
                      FUN_0053b726();
                    }
                    if (*(long *)(lVar15 + 0x10) != 0) {
                      FUN_0053b726();
                    }
                  }
                }
                lVar3 = *(long *)(lVar3 + 0x10);
                if (lVar3 != 0) {
                  FUN_005249f0(lVar3 + 0x18);
                  FUN_005249f0(lVar3 + 0x20);
                  lVar15 = *(long *)(lVar3 + 8);
                  if (lVar15 != 0) {
                    pQVar16 = *(QArrayData **)(lVar15 + 0x18);
                    if (*(int *)pQVar16 == 0) {
LAB_008a3671:
                      QArrayData::deallocate(pQVar16,2,8);
                    }
                    else if (*(int *)pQVar16 != -1) {
                      LOCK();
                      *(int *)pQVar16 = *(int *)pQVar16 + -1;
                      UNLOCK();
                      if (*(int *)pQVar16 == 0) {
                        pQVar16 = *(QArrayData **)(lVar15 + 0x18);
                        goto LAB_008a3671;
                      }
                    }
                    pQVar16 = *(QArrayData **)(lVar15 + 0x20);
                    if (*(int *)pQVar16 == 0) {
LAB_008a3641:
                      QArrayData::deallocate(pQVar16,2,8);
                    }
                    else if (*(int *)pQVar16 != -1) {
                      LOCK();
                      *(int *)pQVar16 = *(int *)pQVar16 + -1;
                      UNLOCK();
                      if (*(int *)pQVar16 == 0) {
                        pQVar16 = *(QArrayData **)(lVar15 + 0x20);
                        goto LAB_008a3641;
                      }
                    }
                    if (*(long *)(lVar15 + 8) != 0) {
                      FUN_0053b726();
                    }
                    if (*(long *)(lVar15 + 0x10) != 0) {
                      FUN_0053b726();
                    }
                  }
                  lVar3 = *(long *)(lVar3 + 0x10);
                  if (lVar3 != 0) {
                    pQVar16 = *(QArrayData **)(lVar3 + 0x18);
                    if (*(int *)pQVar16 == 0) {
LAB_008a3621:
                      QArrayData::deallocate(pQVar16,2,8);
                    }
                    else if (*(int *)pQVar16 != -1) {
                      LOCK();
                      *(int *)pQVar16 = *(int *)pQVar16 + -1;
                      UNLOCK();
                      if (*(int *)pQVar16 == 0) {
                        pQVar16 = *(QArrayData **)(lVar3 + 0x18);
                        goto LAB_008a3621;
                      }
                    }
                    pQVar16 = *(QArrayData **)(lVar3 + 0x20);
                    if (*(int *)pQVar16 == 0) {
LAB_008a36a1:
                      QArrayData::deallocate(pQVar16,2,8);
                    }
                    else if (*(int *)pQVar16 != -1) {
                      LOCK();
                      *(int *)pQVar16 = *(int *)pQVar16 + -1;
                      UNLOCK();
                      if (*(int *)pQVar16 == 0) {
                        pQVar16 = *(QArrayData **)(lVar3 + 0x20);
                        goto LAB_008a36a1;
                      }
                    }
                    if (*(long *)(lVar3 + 8) != 0) {
                      FUN_0053b726();
                    }
                    if (*(long *)(lVar3 + 0x10) != 0) {
                      FUN_0053b726();
                    }
                  }
                }
              }
            }
          }
          lVar10 = *(long *)(lVar10 + 0x10);
          if (lVar10 != 0) {
            FUN_005249f0(lVar10 + 0x18);
            FUN_005249f0(lVar10 + 0x20);
            lVar3 = *(long *)(lVar10 + 8);
            if (lVar3 != 0) {
              FUN_005249f0(lVar3 + 0x18);
              FUN_005249f0(lVar3 + 0x20);
              lVar15 = *(long *)(lVar3 + 8);
              if (lVar15 != 0) {
                FUN_005249f0(lVar15 + 0x18);
                FUN_005249f0(lVar15 + 0x20);
                lVar4 = *(long *)(lVar15 + 8);
                if (lVar4 != 0) {
                  FUN_005249f0(lVar4 + 0x18);
                  FUN_005249f0(lVar4 + 0x20);
                  lVar5 = *(long *)(lVar4 + 8);
                  if (lVar5 != 0) {
                    pQVar16 = *(QArrayData **)(lVar5 + 0x18);
                    if (*(int *)pQVar16 == 0) {
LAB_008a3c19:
                      QArrayData::deallocate(pQVar16,2,8);
                    }
                    else if (*(int *)pQVar16 != -1) {
                      LOCK();
                      *(int *)pQVar16 = *(int *)pQVar16 + -1;
                      UNLOCK();
                      if (*(int *)pQVar16 == 0) {
                        pQVar16 = *(QArrayData **)(lVar5 + 0x18);
                        goto LAB_008a3c19;
                      }
                    }
                    pQVar16 = *(QArrayData **)(lVar5 + 0x20);
                    if (*(int *)pQVar16 == 0) {
LAB_008a3c61:
                      QArrayData::deallocate(pQVar16,2,8);
                    }
                    else if (*(int *)pQVar16 != -1) {
                      LOCK();
                      *(int *)pQVar16 = *(int *)pQVar16 + -1;
                      UNLOCK();
                      if (*(int *)pQVar16 == 0) {
                        pQVar16 = *(QArrayData **)(lVar5 + 0x20);
                        goto LAB_008a3c61;
                      }
                    }
                    if (*(long *)(lVar5 + 8) != 0) {
                      FUN_0053b726();
                    }
                    if (*(long *)(lVar5 + 0x10) != 0) {
                      FUN_0053b726();
                    }
                  }
                  lVar4 = *(long *)(lVar4 + 0x10);
                  if (lVar4 != 0) {
                    pQVar16 = *(QArrayData **)(lVar4 + 0x18);
                    if (*(int *)pQVar16 == 0) {
LAB_008a3be1:
                      QArrayData::deallocate(pQVar16,2,8);
                    }
                    else if (*(int *)pQVar16 != -1) {
                      LOCK();
                      *(int *)pQVar16 = *(int *)pQVar16 + -1;
                      UNLOCK();
                      if (*(int *)pQVar16 == 0) {
                        pQVar16 = *(QArrayData **)(lVar4 + 0x18);
                        goto LAB_008a3be1;
                      }
                    }
                    pQVar16 = *(QArrayData **)(lVar4 + 0x20);
                    if (*(int *)pQVar16 == 0) {
LAB_008a3a19:
                      QArrayData::deallocate(pQVar16,2,8);
                    }
                    else if (*(int *)pQVar16 != -1) {
                      LOCK();
                      *(int *)pQVar16 = *(int *)pQVar16 + -1;
                      UNLOCK();
                      if (*(int *)pQVar16 == 0) {
                        pQVar16 = *(QArrayData **)(lVar4 + 0x20);
                        goto LAB_008a3a19;
                      }
                    }
                    if (*(long *)(lVar4 + 8) != 0) {
                      FUN_0053b726();
                    }
                    if (*(long *)(lVar4 + 0x10) != 0) {
                      FUN_0053b726();
                    }
                  }
                }
                lVar15 = *(long *)(lVar15 + 0x10);
                if (lVar15 != 0) {
                  FUN_005249f0(lVar15 + 0x18);
                  FUN_005249f0(lVar15 + 0x20);
                  lVar4 = *(long *)(lVar15 + 8);
                  if (lVar4 != 0) {
                    pQVar16 = *(QArrayData **)(lVar4 + 0x18);
                    if (*(int *)pQVar16 == 0) {
LAB_008a3f51:
                      QArrayData::deallocate(pQVar16,2,8);
                    }
                    else if (*(int *)pQVar16 != -1) {
                      LOCK();
                      *(int *)pQVar16 = *(int *)pQVar16 + -1;
                      UNLOCK();
                      if (*(int *)pQVar16 == 0) {
                        pQVar16 = *(QArrayData **)(lVar4 + 0x18);
                        goto LAB_008a3f51;
                      }
                    }
                    pQVar16 = *(QArrayData **)(lVar4 + 0x20);
                    if (*(int *)pQVar16 == 0) {
LAB_008a3f19:
                      QArrayData::deallocate(pQVar16,2,8);
                    }
                    else if (*(int *)pQVar16 != -1) {
                      LOCK();
                      *(int *)pQVar16 = *(int *)pQVar16 + -1;
                      UNLOCK();
                      if (*(int *)pQVar16 == 0) {
                        pQVar16 = *(QArrayData **)(lVar4 + 0x20);
                        goto LAB_008a3f19;
                      }
                    }
                    if (*(long *)(lVar4 + 8) != 0) {
                      FUN_0053b726();
                    }
                    if (*(long *)(lVar4 + 0x10) != 0) {
                      FUN_0053b726();
                    }
                  }
                  lVar15 = *(long *)(lVar15 + 0x10);
                  if (lVar15 != 0) {
                    pQVar16 = *(QArrayData **)(lVar15 + 0x18);
                    if (*(int *)pQVar16 == 0) {
LAB_008a4009:
                      QArrayData::deallocate(pQVar16,2,8);
                    }
                    else if (*(int *)pQVar16 != -1) {
                      LOCK();
                      *(int *)pQVar16 = *(int *)pQVar16 + -1;
                      UNLOCK();
                      if (*(int *)pQVar16 == 0) {
                        pQVar16 = *(QArrayData **)(lVar15 + 0x18);
                        goto LAB_008a4009;
                      }
                    }
                    pQVar16 = *(QArrayData **)(lVar15 + 0x20);
                    if (*(int *)pQVar16 == 0) {
LAB_008a3e61:
                      QArrayData::deallocate(pQVar16,2,8);
                    }
                    else if (*(int *)pQVar16 != -1) {
                      LOCK();
                      *(int *)pQVar16 = *(int *)pQVar16 + -1;
                      UNLOCK();
                      if (*(int *)pQVar16 == 0) {
                        pQVar16 = *(QArrayData **)(lVar15 + 0x20);
                        goto LAB_008a3e61;
                      }
                    }
                    if (*(long *)(lVar15 + 8) != 0) {
                      FUN_0053b726();
                    }
                    if (*(long *)(lVar15 + 0x10) != 0) {
                      FUN_0053b726();
                    }
                  }
                }
              }
              lVar3 = *(long *)(lVar3 + 0x10);
              if (lVar3 != 0) {
                FUN_005249f0(lVar3 + 0x18);
                FUN_005249f0(lVar3 + 0x20);
                lVar15 = *(long *)(lVar3 + 8);
                if (lVar15 != 0) {
                  FUN_005249f0(lVar15 + 0x18);
                  FUN_005249f0(lVar15 + 0x20);
                  lVar4 = *(long *)(lVar15 + 8);
                  if (lVar4 != 0) {
                    pQVar16 = *(QArrayData **)(lVar4 + 0x18);
                    if (*(int *)pQVar16 == 0) {
LAB_008a4131:
                      QArrayData::deallocate(pQVar16,2,8);
                    }
                    else if (*(int *)pQVar16 != -1) {
                      LOCK();
                      *(int *)pQVar16 = *(int *)pQVar16 + -1;
                      UNLOCK();
                      if (*(int *)pQVar16 == 0) {
                        pQVar16 = *(QArrayData **)(lVar4 + 0x18);
                        goto LAB_008a4131;
                      }
                    }
                    pQVar16 = *(QArrayData **)(lVar4 + 0x20);
                    if (*(int *)pQVar16 == 0) {
LAB_008a40f1:
                      QArrayData::deallocate(pQVar16,2,8);
                    }
                    else if (*(int *)pQVar16 != -1) {
                      LOCK();
                      *(int *)pQVar16 = *(int *)pQVar16 + -1;
                      UNLOCK();
                      if (*(int *)pQVar16 == 0) {
                        pQVar16 = *(QArrayData **)(lVar4 + 0x20);
                        goto LAB_008a40f1;
                      }
                    }
                    if (*(long *)(lVar4 + 8) != 0) {
                      FUN_0053b726();
                    }
                    if (*(long *)(lVar4 + 0x10) != 0) {
                      FUN_0053b726();
                    }
                  }
                  lVar15 = *(long *)(lVar15 + 0x10);
                  if (lVar15 != 0) {
                    pQVar16 = *(QArrayData **)(lVar15 + 0x18);
                    if (*(int *)pQVar16 == 0) {
LAB_008a4061:
                      QArrayData::deallocate(pQVar16,2,8);
                    }
                    else if (*(int *)pQVar16 != -1) {
                      LOCK();
                      *(int *)pQVar16 = *(int *)pQVar16 + -1;
                      UNLOCK();
                      if (*(int *)pQVar16 == 0) {
                        pQVar16 = *(QArrayData **)(lVar15 + 0x18);
                        goto LAB_008a4061;
                      }
                    }
                    pQVar16 = *(QArrayData **)(lVar15 + 0x20);
                    if (*(int *)pQVar16 == 0) {
LAB_008a4031:
                      QArrayData::deallocate(pQVar16,2,8);
                    }
                    else if (*(int *)pQVar16 != -1) {
                      LOCK();
                      *(int *)pQVar16 = *(int *)pQVar16 + -1;
                      UNLOCK();
                      if (*(int *)pQVar16 == 0) {
                        pQVar16 = *(QArrayData **)(lVar15 + 0x20);
                        goto LAB_008a4031;
                      }
                    }
                    if (*(long *)(lVar15 + 8) != 0) {
                      FUN_0053b726();
                    }
                    if (*(long *)(lVar15 + 0x10) != 0) {
                      FUN_0053b726();
                    }
                  }
                }
                lVar3 = *(long *)(lVar3 + 0x10);
                if (lVar3 != 0) {
                  FUN_005249f0(lVar3 + 0x18);
                  FUN_005249f0(lVar3 + 0x20);
                  lVar15 = *(long *)(lVar3 + 8);
                  if (lVar15 != 0) {
                    pQVar16 = *(QArrayData **)(lVar15 + 0x18);
                    if (*(int *)pQVar16 == 0) {
LAB_008a40c1:
                      QArrayData::deallocate(pQVar16,2,8);
                    }
                    else if (*(int *)pQVar16 != -1) {
                      LOCK();
                      *(int *)pQVar16 = *(int *)pQVar16 + -1;
                      UNLOCK();
                      if (*(int *)pQVar16 == 0) {
                        pQVar16 = *(QArrayData **)(lVar15 + 0x18);
                        goto LAB_008a40c1;
                      }
                    }
                    pQVar16 = *(QArrayData **)(lVar15 + 0x20);
                    if (*(int *)pQVar16 == 0) {
LAB_008a4091:
                      QArrayData::deallocate(pQVar16,2,8);
                    }
                    else if (*(int *)pQVar16 != -1) {
                      LOCK();
                      *(int *)pQVar16 = *(int *)pQVar16 + -1;
                      UNLOCK();
                      if (*(int *)pQVar16 == 0) {
                        pQVar16 = *(QArrayData **)(lVar15 + 0x20);
                        goto LAB_008a4091;
                      }
                    }
                    if (*(long *)(lVar15 + 8) != 0) {
                      FUN_0053b726();
                    }
                    if (*(long *)(lVar15 + 0x10) != 0) {
                      FUN_0053b726();
                    }
                  }
                  lVar3 = *(long *)(lVar3 + 0x10);
                  if (lVar3 != 0) {
                    pQVar16 = *(QArrayData **)(lVar3 + 0x18);
                    if (*(int *)pQVar16 == 0) {
LAB_008a4171:
                      QArrayData::deallocate(pQVar16,2,8);
                    }
                    else if (*(int *)pQVar16 != -1) {
                      LOCK();
                      *(int *)pQVar16 = *(int *)pQVar16 + -1;
                      UNLOCK();
                      if (*(int *)pQVar16 == 0) {
                        pQVar16 = *(QArrayData **)(lVar3 + 0x18);
                        goto LAB_008a4171;
                      }
                    }
                    pQVar16 = *(QArrayData **)(lVar3 + 0x20);
                    if (*(int *)pQVar16 == 0) {
LAB_008a4191:
                      QArrayData::deallocate(pQVar16,2,8);
                    }
                    else if (*(int *)pQVar16 != -1) {
                      LOCK();
                      *(int *)pQVar16 = *(int *)pQVar16 + -1;
                      UNLOCK();
                      if (*(int *)pQVar16 == 0) {
                        pQVar16 = *(QArrayData **)(lVar3 + 0x20);
                        goto LAB_008a4191;
                      }
                    }
                    if (*(long *)(lVar3 + 8) != 0) {
                      FUN_0053b726();
                    }
                    if (*(long *)(lVar3 + 0x10) != 0) {
                      FUN_0053b726();
                    }
                  }
                }
              }
            }
            lVar10 = *(long *)(lVar10 + 0x10);
            if (lVar10 != 0) {
              FUN_005249f0(lVar10 + 0x18);
              FUN_005249f0(lVar10 + 0x20);
              lVar3 = *(long *)(lVar10 + 8);
              if (lVar3 != 0) {
                FUN_005249f0(lVar3 + 0x18);
                FUN_005249f0(lVar3 + 0x20);
                lVar15 = *(long *)(lVar3 + 8);
                if (lVar15 != 0) {
                  FUN_005249f0(lVar15 + 0x18);
                  FUN_005249f0(lVar15 + 0x20);
                  lVar4 = *(long *)(lVar15 + 8);
                  if (lVar4 != 0) {
                    pQVar16 = *(QArrayData **)(lVar4 + 0x18);
                    if (*(int *)pQVar16 == 0) {
LAB_008a3b71:
                      QArrayData::deallocate(pQVar16,2,8);
                    }
                    else if (*(int *)pQVar16 != -1) {
                      LOCK();
                      *(int *)pQVar16 = *(int *)pQVar16 + -1;
                      UNLOCK();
                      if (*(int *)pQVar16 == 0) {
                        pQVar16 = *(QArrayData **)(lVar4 + 0x18);
                        goto LAB_008a3b71;
                      }
                    }
                    pQVar16 = *(QArrayData **)(lVar4 + 0x20);
                    if (*(int *)pQVar16 == 0) {
LAB_008a3851:
                      QArrayData::deallocate(pQVar16,2,8);
                    }
                    else if (*(int *)pQVar16 != -1) {
                      LOCK();
                      *(int *)pQVar16 = *(int *)pQVar16 + -1;
                      UNLOCK();
                      if (*(int *)pQVar16 == 0) {
                        pQVar16 = *(QArrayData **)(lVar4 + 0x20);
                        goto LAB_008a3851;
                      }
                    }
                    if (*(long *)(lVar4 + 8) != 0) {
                      FUN_0053b726();
                    }
                    if (*(long *)(lVar4 + 0x10) != 0) {
                      FUN_0053b726();
                    }
                  }
                  lVar15 = *(long *)(lVar15 + 0x10);
                  if (lVar15 != 0) {
                    pQVar16 = *(QArrayData **)(lVar15 + 0x18);
                    if (*(int *)pQVar16 == 0) {
LAB_008a3bb1:
                      QArrayData::deallocate(pQVar16,2,8);
                    }
                    else if (*(int *)pQVar16 != -1) {
                      LOCK();
                      *(int *)pQVar16 = *(int *)pQVar16 + -1;
                      UNLOCK();
                      if (*(int *)pQVar16 == 0) {
                        pQVar16 = *(QArrayData **)(lVar15 + 0x18);
                        goto LAB_008a3bb1;
                      }
                    }
                    pQVar16 = *(QArrayData **)(lVar15 + 0x20);
                    if (*(int *)pQVar16 == 0) {
LAB_008a3a51:
                      QArrayData::deallocate(pQVar16,2,8);
                    }
                    else if (*(int *)pQVar16 != -1) {
                      LOCK();
                      *(int *)pQVar16 = *(int *)pQVar16 + -1;
                      UNLOCK();
                      if (*(int *)pQVar16 == 0) {
                        pQVar16 = *(QArrayData **)(lVar15 + 0x20);
                        goto LAB_008a3a51;
                      }
                    }
                    if (*(long *)(lVar15 + 8) != 0) {
                      FUN_0053b726();
                    }
                    if (*(long *)(lVar15 + 0x10) != 0) {
                      FUN_0053b726();
                    }
                  }
                }
                lVar3 = *(long *)(lVar3 + 0x10);
                if (lVar3 != 0) {
                  FUN_005249f0(lVar3 + 0x18);
                  FUN_005249f0(lVar3 + 0x20);
                  lVar15 = *(long *)(lVar3 + 8);
                  if (lVar15 != 0) {
                    pQVar16 = *(QArrayData **)(lVar15 + 0x18);
                    if (*(int *)pQVar16 == 0) {
LAB_008a3e89:
                      QArrayData::deallocate(pQVar16,2,8);
                    }
                    else if (*(int *)pQVar16 != -1) {
                      LOCK();
                      *(int *)pQVar16 = *(int *)pQVar16 + -1;
                      UNLOCK();
                      if (*(int *)pQVar16 == 0) {
                        pQVar16 = *(QArrayData **)(lVar15 + 0x18);
                        goto LAB_008a3e89;
                      }
                    }
                    pQVar16 = *(QArrayData **)(lVar15 + 0x20);
                    if (*(int *)pQVar16 == 0) {
LAB_008a3e31:
                      QArrayData::deallocate(pQVar16,2,8);
                    }
                    else if (*(int *)pQVar16 != -1) {
                      LOCK();
                      *(int *)pQVar16 = *(int *)pQVar16 + -1;
                      UNLOCK();
                      if (*(int *)pQVar16 == 0) {
                        pQVar16 = *(QArrayData **)(lVar15 + 0x20);
                        goto LAB_008a3e31;
                      }
                    }
                    if (*(long *)(lVar15 + 8) != 0) {
                      FUN_0053b726();
                    }
                    if (*(long *)(lVar15 + 0x10) != 0) {
                      FUN_0053b726();
                    }
                  }
                  lVar3 = *(long *)(lVar3 + 0x10);
                  if (lVar3 != 0) {
                    pQVar16 = *(QArrayData **)(lVar3 + 0x18);
                    if (*(int *)pQVar16 == 0) {
LAB_008a3eb9:
                      QArrayData::deallocate(pQVar16,2,8);
                    }
                    else if (*(int *)pQVar16 != -1) {
                      LOCK();
                      *(int *)pQVar16 = *(int *)pQVar16 + -1;
                      UNLOCK();
                      if (*(int *)pQVar16 == 0) {
                        pQVar16 = *(QArrayData **)(lVar3 + 0x18);
                        goto LAB_008a3eb9;
                      }
                    }
                    pQVar16 = *(QArrayData **)(lVar3 + 0x20);
                    if (*(int *)pQVar16 == 0) {
LAB_008a3ed9:
                      QArrayData::deallocate(pQVar16,2,8);
                    }
                    else if (*(int *)pQVar16 != -1) {
                      LOCK();
                      *(int *)pQVar16 = *(int *)pQVar16 + -1;
                      UNLOCK();
                      if (*(int *)pQVar16 == 0) {
                        pQVar16 = *(QArrayData **)(lVar3 + 0x20);
                        goto LAB_008a3ed9;
                      }
                    }
                    if (*(long *)(lVar3 + 8) != 0) {
                      FUN_0053b726();
                    }
                    if (*(long *)(lVar3 + 0x10) != 0) {
                      FUN_0053b726();
                    }
                  }
                }
              }
              lVar10 = *(long *)(lVar10 + 0x10);
              if (lVar10 != 0) {
                FUN_005249f0(lVar10 + 0x18);
                FUN_005249f0(lVar10 + 0x20);
                lVar3 = *(long *)(lVar10 + 8);
                if (lVar3 != 0) {
                  FUN_005249f0(lVar3 + 0x18);
                  FUN_005249f0(lVar3 + 0x20);
                  lVar15 = *(long *)(lVar3 + 8);
                  if (lVar15 != 0) {
                    pQVar16 = *(QArrayData **)(lVar15 + 0x18);
                    if (*(int *)pQVar16 == 0) {
LAB_008a3fa9:
                      QArrayData::deallocate(pQVar16,2,8);
                    }
                    else if (*(int *)pQVar16 != -1) {
                      LOCK();
                      *(int *)pQVar16 = *(int *)pQVar16 + -1;
                      UNLOCK();
                      if (*(int *)pQVar16 == 0) {
                        pQVar16 = *(QArrayData **)(lVar15 + 0x18);
                        goto LAB_008a3fa9;
                      }
                    }
                    pQVar16 = *(QArrayData **)(lVar15 + 0x20);
                    if (*(int *)pQVar16 == 0) {
LAB_008a3fd9:
                      QArrayData::deallocate(pQVar16,2,8);
                    }
                    else if (*(int *)pQVar16 != -1) {
                      LOCK();
                      *(int *)pQVar16 = *(int *)pQVar16 + -1;
                      UNLOCK();
                      if (*(int *)pQVar16 == 0) {
                        pQVar16 = *(QArrayData **)(lVar15 + 0x20);
                        goto LAB_008a3fd9;
                      }
                    }
                    if (*(long *)(lVar15 + 8) != 0) {
                      FUN_0053b726();
                    }
                    if (*(long *)(lVar15 + 0x10) != 0) {
                      FUN_0053b726();
                    }
                  }
                  lVar3 = *(long *)(lVar3 + 0x10);
                  if (lVar3 != 0) {
                    pQVar16 = *(QArrayData **)(lVar3 + 0x18);
                    if (*(int *)pQVar16 == 0) {
LAB_008a3f89:
                      QArrayData::deallocate(pQVar16,2,8);
                    }
                    else if (*(int *)pQVar16 != -1) {
                      LOCK();
                      *(int *)pQVar16 = *(int *)pQVar16 + -1;
                      UNLOCK();
                      if (*(int *)pQVar16 == 0) {
                        pQVar16 = *(QArrayData **)(lVar3 + 0x18);
                        goto LAB_008a3f89;
                      }
                    }
                    pQVar16 = *(QArrayData **)(lVar3 + 0x20);
                    if (*(int *)pQVar16 == 0) {
LAB_008a3ef9:
                      QArrayData::deallocate(pQVar16,2,8);
                    }
                    else if (*(int *)pQVar16 != -1) {
                      LOCK();
                      *(int *)pQVar16 = *(int *)pQVar16 + -1;
                      UNLOCK();
                      if (*(int *)pQVar16 == 0) {
                        pQVar16 = *(QArrayData **)(lVar3 + 0x20);
                        goto LAB_008a3ef9;
                      }
                    }
                    if (*(long *)(lVar3 + 8) != 0) {
                      FUN_0053b726();
                    }
                    if (*(long *)(lVar3 + 0x10) != 0) {
                      FUN_0053b726();
                    }
                  }
                }
                lVar10 = *(long *)(lVar10 + 0x10);
                if (lVar10 != 0) {
                  FUN_005249f0(lVar10 + 0x18);
                  FUN_005249f0(lVar10 + 0x20);
                  lVar3 = *(long *)(lVar10 + 8);
                  if (lVar3 != 0) {
                    pQVar16 = *(QArrayData **)(lVar3 + 0x18);
                    if (*(int *)pQVar16 == 0) {
LAB_008a3e11:
                      QArrayData::deallocate(pQVar16,2,8);
                    }
                    else if (*(int *)pQVar16 != -1) {
                      LOCK();
                      *(int *)pQVar16 = *(int *)pQVar16 + -1;
                      UNLOCK();
                      if (*(int *)pQVar16 == 0) {
                        pQVar16 = *(QArrayData **)(lVar3 + 0x18);
                        goto LAB_008a3e11;
                      }
                    }
                    pQVar16 = *(QArrayData **)(lVar3 + 0x20);
                    if (*(int *)pQVar16 == 0) {
LAB_008a3df1:
                      QArrayData::deallocate(pQVar16,2,8);
                    }
                    else if (*(int *)pQVar16 != -1) {
                      LOCK();
                      *(int *)pQVar16 = *(int *)pQVar16 + -1;
                      UNLOCK();
                      if (*(int *)pQVar16 == 0) {
                        pQVar16 = *(QArrayData **)(lVar3 + 0x20);
                        goto LAB_008a3df1;
                      }
                    }
                    if (*(long *)(lVar3 + 8) != 0) {
                      FUN_0053b726();
                    }
                    if (*(long *)(lVar3 + 0x10) != 0) {
                      FUN_0053b726();
                    }
                  }
                  lVar10 = *(long *)(lVar10 + 0x10);
                  if (lVar10 != 0) {
                    pQVar16 = *(QArrayData **)(lVar10 + 0x18);
                    if (*(int *)pQVar16 == 0) {
LAB_008a3dd9:
                      QArrayData::deallocate(pQVar16,2,8);
                    }
                    else if (*(int *)pQVar16 != -1) {
                      LOCK();
                      *(int *)pQVar16 = *(int *)pQVar16 + -1;
                      UNLOCK();
                      if (*(int *)pQVar16 == 0) {
                        pQVar16 = *(QArrayData **)(lVar10 + 0x18);
                        goto LAB_008a3dd9;
                      }
                    }
                    pQVar16 = *(QArrayData **)(lVar10 + 0x20);
                    if (*(int *)pQVar16 == 0) {
LAB_008a3dc1:
                      QArrayData::deallocate(pQVar16,2,8);
                    }
                    else if (*(int *)pQVar16 != -1) {
                      LOCK();
                      *(int *)pQVar16 = *(int *)pQVar16 + -1;
                      UNLOCK();
                      if (*(int *)pQVar16 == 0) {
                        pQVar16 = *(QArrayData **)(lVar10 + 0x20);
                        goto LAB_008a3dc1;
                      }
                    }
                    if (*(long *)(lVar10 + 8) != 0) {
                      FUN_0053b726();
                    }
                    if (*(long *)(lVar10 + 0x10) != 0) {
                      FUN_0053b726();
                    }
                  }
                }
              }
            }
          }
                    /* try { // try from 008a32fa to 008a32fe has its CatchHandler @ 008a4225 */
          QMapDataBase::freeTree(pQVar17,(int)*(undefined8 *)(pQVar19 + 0x10));
        }
                    /* try { // try from 008a3302 to 008a3306 has its CatchHandler @ 008a4215 */
        QMapDataBase::freeData((QMapDataBase *)pQVar17);
      }
      else if (*(int *)pQVar17 != -1) {
        LOCK();
        *(int *)pQVar17 = *(int *)pQVar17 + -1;
        UNLOCK();
        if (*(int *)pQVar17 == 0) goto LAB_008a1bf1;
      }
                    /* try { // try from 008a1bbb to 008a1bbf has its CatchHandler @ 008a41dd */
      QMapDataBase::recalcMostLeftNode();
      pQVar2 = *(QMapNodeBase **)(pQVar12 + 0x10);
      pQVar17 = pQVar12;
      pQVar19 = pQVar12;
    }
    if (pQVar2 == (QMapNodeBase *)0x0) {
      pQVar20 = pQVar19 + 8;
LAB_008a1883:
                    /* try { // try from 008a1893 to 008a1897 has its CatchHandler @ 008a41f5 */
      lVar10 = QMapDataBase::createNode
                         ((int)pQVar17,0x28,(QMapNodeBase *)&DAT_00000008,SUB81(pQVar20,0));
      piVar11 = *(int **)pQVar14;
      *(int **)(lVar10 + 0x18) = piVar11;
      if ((*piVar11 != 0) && (*piVar11 != -1)) {
        LOCK();
        *piVar11 = *piVar11 + 1;
        UNLOCK();
      }
      piVar11 = *(int **)(pQVar14 + 8);
      *(int **)(lVar10 + 0x20) = piVar11;
      if ((*piVar11 != 0) && (*piVar11 != -1)) {
        LOCK();
        *piVar11 = *piVar11 + 1;
        UNLOCK();
      }
    }
    else {
      pQVar12 = (QMapNodeBase *)0x0;
      do {
        pQVar20 = pQVar2;
        cVar7 = operator<((QString *)(pQVar20 + 0x18),pQVar14);
        if (cVar7 == '\0') {
          pQVar2 = *(QMapNodeBase **)(pQVar20 + 8);
          pQVar12 = pQVar20;
        }
        else {
          pQVar2 = *(QMapNodeBase **)(pQVar20 + 0x10);
        }
      } while (pQVar2 != (QMapNodeBase *)0x0);
      if ((pQVar12 == (QMapNodeBase *)0x0) ||
         (cVar7 = operator<(pQVar14,(QString *)(pQVar12 + 0x18)), cVar7 != '\0')) goto LAB_008a1883;
      QString::operator=((QString *)(pQVar12 + 0x20),pQVar14 + 8);
    }
    pQVar14 = pQVar14 + 0x10;
  } while (pQVar14 != local_38);
  pQVar14 = (QString *)&local_48;
  do {
    pQVar16 = *(QArrayData **)(pQVar14 + 8);
    if (*(int *)pQVar16 == 0) {
      QArrayData::deallocate(pQVar16,2,8);
LAB_008a1944:
      piVar11 = *(int **)pQVar14;
      iVar8 = *piVar11;
      if (iVar8 == 0) goto LAB_008a194e;
LAB_008a190d:
      if (iVar8 != -1) {
        LOCK();
        iVar8 = *piVar11;
        *piVar11 = *piVar11 + -1;
        UNLOCK();
        if (iVar8 == 1) goto LAB_008a194e;
      }
    }
    else {
      if (*(int *)pQVar16 != -1) {
        LOCK();
        iVar8 = *(int *)pQVar16;
        *(int *)pQVar16 = *(int *)pQVar16 + -1;
        UNLOCK();
        if (iVar8 == 1) {
          QArrayData::deallocate(*(QArrayData **)(pQVar14 + 8),2,8);
          goto LAB_008a1944;
        }
      }
      piVar11 = *(int **)pQVar14;
      iVar8 = *piVar11;
      if (iVar8 != 0) goto LAB_008a190d;
LAB_008a194e:
      QArrayData::deallocate(*(QArrayData **)pQVar14,2,8);
    }
    if (pQVar14 == (QString *)local_138) break;
    pQVar14 = pQVar14 + -0x10;
  } while( true );
  FUN_005249f0(&local_140);
  FUN_005249f0(&local_148);
  FUN_005249f0(&local_150);
  FUN_005249f0(&local_158);
  FUN_005249f0(&local_160);
  FUN_005249f0(&local_168);
  FUN_005249f0(&local_170);
  FUN_005249f0(&local_178);
  if (*(int *)local_180 == 0) {
LAB_008a3428:
    QArrayData::deallocate(local_180,2,8);
  }
  else if (*(int *)local_180 != -1) {
    LOCK();
    *(int *)local_180 = *(int *)local_180 + -1;
    UNLOCK();
    if (*(int *)local_180 == 0) goto LAB_008a3428;
  }
  if (*(int *)local_188 == 0) {
LAB_008a3388:
    QArrayData::deallocate(local_188,2,8);
    iVar8 = *(int *)local_190;
    if (iVar8 != 0) goto LAB_008a1a0e;
LAB_008a33a9:
    QArrayData::deallocate(local_190,2,8);
    iVar8 = *(int *)local_198;
    if (iVar8 == 0) goto LAB_008a33ca;
LAB_008a1a2f:
    if (iVar8 != -1) {
      LOCK();
      *(int *)local_198 = *(int *)local_198 + -1;
      UNLOCK();
      if (*(int *)local_198 == 0) goto LAB_008a33ca;
    }
    iVar8 = *(int *)local_1a0;
    if (iVar8 != 0) goto LAB_008a1a50;
LAB_008a33eb:
    QArrayData::deallocate(local_1a0,2,8);
    iVar8 = *(int *)local_1a8;
    if (iVar8 == 0) goto LAB_008a340c;
LAB_008a1a71:
    if (iVar8 != -1) {
      LOCK();
      *(int *)local_1a8 = *(int *)local_1a8 + -1;
      UNLOCK();
      if (*(int *)local_1a8 == 0) goto LAB_008a340c;
    }
  }
  else {
    if (*(int *)local_188 != -1) {
      LOCK();
      *(int *)local_188 = *(int *)local_188 + -1;
      UNLOCK();
      if (*(int *)local_188 == 0) goto LAB_008a3388;
    }
    iVar8 = *(int *)local_190;
    if (iVar8 == 0) goto LAB_008a33a9;
LAB_008a1a0e:
    if (iVar8 != -1) {
      LOCK();
      *(int *)local_190 = *(int *)local_190 + -1;
      UNLOCK();
      if (*(int *)local_190 == 0) goto LAB_008a33a9;
    }
    iVar8 = *(int *)local_198;
    if (iVar8 != 0) goto LAB_008a1a2f;
LAB_008a33ca:
    QArrayData::deallocate(local_198,2,8);
    iVar8 = *(int *)local_1a0;
    if (iVar8 == 0) goto LAB_008a33eb;
LAB_008a1a50:
    if (iVar8 != -1) {
      LOCK();
      *(int *)local_1a0 = *(int *)local_1a0 + -1;
      UNLOCK();
      if (*(int *)local_1a0 == 0) goto LAB_008a33eb;
    }
    iVar8 = *(int *)local_1a8;
    if (iVar8 != 0) goto LAB_008a1a71;
LAB_008a340c:
    QArrayData::deallocate(local_1a8,2,8);
  }
  if (*(int *)local_1b0 == 0) {
LAB_008a336c:
    QArrayData::deallocate(local_1b0,2,8);
  }
  else if (*(int *)local_1b0 != -1) {
    LOCK();
    *(int *)local_1b0 = *(int *)local_1b0 + -1;
    UNLOCK();
    if (*(int *)local_1b0 == 0) goto LAB_008a336c;
  }
  FUN_005249f0(&local_1b8);
  local_138[0] = (QArrayData *)&QArrayData::shared_null;
  if (*(long *)(pQVar19 + 0x10) != 0) {
    lVar10 = 0;
    lVar3 = *(long *)(pQVar19 + 0x10);
    do {
      while (lVar15 = lVar3, cVar7 = operator<((QString *)(lVar15 + 0x18),param_2), cVar7 == '\0') {
        lVar10 = lVar15;
        lVar3 = *(long *)(lVar15 + 8);
        if (*(long *)(lVar15 + 8) == 0) goto LAB_008a1aea;
      }
      plVar1 = (long *)(lVar15 + 0x10);
      lVar15 = lVar10;
      lVar3 = *plVar1;
    } while (*plVar1 != 0);
LAB_008a1aea:
    if ((lVar15 != 0) && (cVar7 = operator<(param_2,(QString *)(lVar15 + 0x18)), cVar7 == '\0')) {
      piVar18 = *(int **)(lVar15 + 0x20);
    }
  }
  *param_1 = piVar18;
  if ((*piVar18 == 0) || (*piVar18 == -1)) {
    iVar8 = *(int *)local_138[0];
  }
  else {
    LOCK();
    *piVar18 = *piVar18 + 1;
    UNLOCK();
    iVar8 = *(int *)local_138[0];
  }
  if (iVar8 == 0) {
LAB_008a333c:
    QArrayData::deallocate(local_138[0],2,8);
    iVar8 = *(int *)pQVar17;
  }
  else {
    if (iVar8 != -1) {
      LOCK();
      *(int *)local_138[0] = *(int *)local_138[0] + -1;
      UNLOCK();
      if (*(int *)local_138[0] == 0) goto LAB_008a333c;
    }
    iVar8 = *(int *)pQVar17;
  }
  if (iVar8 != 0) {
    if (iVar8 == -1) {
      return param_1;
    }
    LOCK();
    *(int *)pQVar17 = *(int *)pQVar17 + -1;
    UNLOCK();
    if (*(int *)pQVar17 != 0) {
      return param_1;
    }
  }
  FUN_0053b7ce(pQVar19);
  return param_1;
}


