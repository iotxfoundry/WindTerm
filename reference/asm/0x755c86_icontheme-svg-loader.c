// entry=00755c86 size=1616  (decompiled by Ghidra package ghidra, Utility, version 12.1.4)

QSvgRenderer * FUN_00755c86(long param_1,long *param_2)

{
  byte *pbVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  char *pcVar5;
  QSvgRenderer *this;
  uint uVar6;
  char *pcVar7;
  char *pcVar8;
  ulong uVar9;
  int iVar10;
  bool bVar11;
  QString *local_a0;
  QArrayData *local_90;
  QArrayData *local_88;
  QArrayData *local_80;
  QArrayData *local_78;
  QSvgRenderer *local_70;
  QArrayData *local_68;
  QSvgRenderer *local_60;
  QArrayData *local_58 [5];
  
  QString::toUtf8_helper((QString *)local_58);
  pcVar8 = *(char **)(param_1 + 0x40);
  if (pcVar8 != (char *)0x0) {
    do {
      uVar9 = (ulong)(byte)pcVar8[3];
      if (pcVar8[3] != 0) {
        iVar4 = 0;
        do {
          while( true ) {
            iVar10 = (iVar4 + (int)uVar9) / 2;
            iVar3 = qstrcmp((QByteArray *)(pcVar8 + ((long)iVar10 + 1) * 0x10),
                            (QByteArray *)local_58);
            if (-1 < iVar3) break;
            iVar4 = iVar10 + 1;
            if (iVar4 == (int)uVar9) goto LAB_00755d12;
          }
          uVar9 = (ulong)iVar10;
        } while (iVar4 != iVar10);
      }
LAB_00755d12:
      if (*pcVar8 != '\0') goto LAB_00755d23;
      pcVar8 = *(char **)(pcVar8 + uVar9 * 8 + 0x100);
    } while( true );
  }
LAB_0075609a:
  uVar9 = 0;
  goto LAB_00755d95;
LAB_00755d23:
  if ((uint)uVar9 == (uint)(byte)pcVar8[3]) {
    do {
      pbVar1 = (byte *)(pcVar8 + 1);
      uVar9 = (ulong)(uint)*pbVar1;
      pcVar8 = *(char **)(pcVar8 + 8);
      if (*pcVar8 != '\0') goto LAB_00755d49;
    } while ((uint)(byte)pcVar8[3] == (uint)*pbVar1);
  }
  iVar4 = qstrcmp((QByteArray *)local_58,(QByteArray *)(pcVar8 + ((long)(int)uVar9 + 1) * 0x10));
  if (iVar4 < 0) {
LAB_00755d49:
    pcVar8 = *(char **)(param_1 + 0x40);
    if (pcVar8 == (char *)0x0) goto LAB_0075609a;
    pcVar5 = pcVar8;
    if ((*pcVar8 == '\0') &&
       (pcVar5 = *(char **)(pcVar8 + 0x180), *(char **)(pcVar8 + 0x180) == (char *)0x0)) {
      uVar9 = 0;
      pcVar8 = (char *)0x0;
    }
    else {
      uVar9 = (ulong)(byte)pcVar5[3];
      if (*pcVar8 == '\0') {
        pcVar8 = *(char **)(pcVar8 + 0x180);
      }
    }
  }
LAB_00755d95:
  if (*(int *)local_58[0] == 0) {
LAB_00755e0d:
    QArrayData::deallocate(local_58[0],1,8);
    pcVar5 = *(char **)(param_1 + 0x40);
    if (pcVar5 != (char *)0x0) goto LAB_00755db4;
LAB_00755e25:
    uVar6 = 0;
    bVar11 = pcVar8 == (char *)0x0;
  }
  else {
    if (*(int *)local_58[0] != -1) {
      LOCK();
      *(int *)local_58[0] = *(int *)local_58[0] + -1;
      UNLOCK();
      if (*(int *)local_58[0] == 0) goto LAB_00755e0d;
    }
    pcVar5 = *(char **)(param_1 + 0x40);
    if (pcVar5 == (char *)0x0) goto LAB_00755e25;
LAB_00755db4:
    pcVar7 = pcVar5;
    if ((*pcVar5 == '\0') &&
       (pcVar7 = *(char **)(pcVar5 + 0x180), *(char **)(pcVar5 + 0x180) == (char *)0x0)) {
      uVar6 = 0;
      pcVar5 = (char *)0x0;
    }
    else {
      uVar6 = (uint)(byte)pcVar7[3];
      if (*pcVar5 == '\0') {
        pcVar5 = *(char **)(pcVar5 + 0x180);
        uVar6 = (uint)(byte)pcVar7[3];
      }
    }
    bVar11 = pcVar5 == pcVar8;
  }
  if ((!bVar11) || ((uint)uVar9 != uVar6)) {
    return *(QSvgRenderer **)(pcVar8 + (uVar9 + 1) * 0x10 + 8);
  }
  QDir::currentPath();
  local_88 = *(QArrayData **)(*param_2 + 0x10 + (long)*(int *)(*param_2 + 8) * 8);
  if ((*(int *)local_88 != 0) && (*(int *)local_88 != -1)) {
    LOCK();
    *(int *)local_88 = *(int *)local_88 + 1;
    UNLOCK();
  }
  if (*(int *)(local_88 + 4) == 0) {
    this = (QSvgRenderer *)0x0;
  }
  else {
    if (*(int *)(*(long *)(*param_2 + 0x20 + (long)*(int *)(*param_2 + 8) * 8) + 4) == 0) {
      QFileInfo::QFileInfo((QFileInfo *)&local_68,(QString *)&local_88);
                    /* try { // try from 007560d6 to 007560da has its CatchHandler @ 007562f6 */
      QFileInfo::absolutePath();
                    /* try { // try from 007560de to 007560e2 has its CatchHandler @ 0075631e */
      QDir::setCurrent((QString *)local_58);
      if (*(int *)local_58[0] == 0) {
LAB_0075627f:
        QArrayData::deallocate(local_58[0],2,8);
      }
      else if (*(int *)local_58[0] != -1) {
        LOCK();
        *(int *)local_58[0] = *(int *)local_58[0] + -1;
        UNLOCK();
        if (*(int *)local_58[0] == 0) goto LAB_0075627f;
      }
      QFileInfo::~QFileInfo((QFileInfo *)&local_68);
      goto LAB_00755f5f;
    }
                    /* try { // try from 00755e9d to 00755ea1 has its CatchHandler @ 007562ee */
    local_68 = (QArrayData *)QString::fromLatin1_helper("icon.theme",10);
                    /* try { // try from 00755eb5 to 00755eb9 has its CatchHandler @ 007562e6 */
    FUN_00752ba8((QString *)local_58,param_1,&local_68);
                    /* try { // try from 00755ec0 to 00755ec4 has its CatchHandler @ 007562fe */
    cVar2 = FUN_00755204(param_1,(QString *)local_58);
    if (*(int *)local_58[0] == 0) {
LAB_00756266:
      QArrayData::deallocate(local_58[0],2,8);
    }
    else if (*(int *)local_58[0] != -1) {
      LOCK();
      *(int *)local_58[0] = *(int *)local_58[0] + -1;
      UNLOCK();
      if (*(int *)local_58[0] == 0) goto LAB_00756266;
    }
    if (*(int *)local_68 == 0) {
LAB_0075624d:
      QArrayData::deallocate(local_68,2,8);
    }
    else if (*(int *)local_68 != -1) {
      LOCK();
      *(int *)local_68 = *(int *)local_68 + -1;
      UNLOCK();
      if (*(int *)local_68 == 0) goto LAB_0075624d;
    }
    if (cVar2 == '\0') {
      local_68 = (QArrayData *)QString::fromLatin1_helper("images/",7);
                    /* try { // try from 007561c1 to 007561c5 has its CatchHandler @ 00756316 */
      local_78 = (QArrayData *)QString::fromLatin1_helper("default",7);
                    /* try { // try from 007561dc to 007561e0 has its CatchHandler @ 0075632e */
      FUN_00752a7e((QString *)local_58,param_1,&local_78,&local_68);
                    /* try { // try from 007561e4 to 007561e8 has its CatchHandler @ 00756326 */
      QDir::setCurrent((QString *)local_58);
      if (*(int *)local_58[0] == 0) {
LAB_00756298:
        QArrayData::deallocate(local_58[0],2,8);
      }
      else if (*(int *)local_58[0] != -1) {
        LOCK();
        *(int *)local_58[0] = *(int *)local_58[0] + -1;
        UNLOCK();
        if (*(int *)local_58[0] == 0) goto LAB_00756298;
      }
      if (*(int *)local_78 == 0) {
LAB_007562b1:
        QArrayData::deallocate(local_78,2,8);
      }
      else if (*(int *)local_78 != -1) {
        LOCK();
        *(int *)local_78 = *(int *)local_78 + -1;
        UNLOCK();
        if (*(int *)local_78 == 0) goto LAB_007562b1;
      }
      iVar4 = *(int *)local_68;
      if (iVar4 != 0) goto LAB_00755f46;
LAB_00756234:
      QArrayData::deallocate(local_68,2,8);
    }
    else {
      local_68 = (QArrayData *)&QArrayData::shared_null;
                    /* try { // try from 00755f22 to 00755f26 has its CatchHandler @ 007562de */
      FUN_00752ba8((QString *)local_58,param_1,&local_68);
                    /* try { // try from 00755f2a to 00755f2e has its CatchHandler @ 007562d6 */
      QDir::setCurrent((QString *)local_58);
      FUN_005249f0((QString *)local_58);
      iVar4 = *(int *)local_68;
      if (iVar4 == 0) goto LAB_00756234;
LAB_00755f46:
      if (iVar4 != -1) {
        LOCK();
        *(int *)local_68 = *(int *)local_68 + -1;
        UNLOCK();
        if (*(int *)local_68 == 0) goto LAB_00756234;
      }
    }
LAB_00755f5f:
    local_a0 = (QString *)&local_88;
                    /* try { // try from 00755f64 to 00755f68 has its CatchHandler @ 007562ee */
    this = operator_new(0x10);
                    /* try { // try from 00755f76 to 00755f7a has its CatchHandler @ 0075630e */
    QSvgRenderer::QSvgRenderer(this,local_a0,(QObject *)0x0);
                    /* try { // try from 00755f90 to 00755f94 has its CatchHandler @ 007562ee */
    QString::toUtf8_helper((QString *)&local_80);
    local_68 = local_80;
    local_80 = (QArrayData *)&QArrayData::shared_null;
    local_78 = (QArrayData *)&QArrayData::shared_null;
    local_70 = this;
    local_60 = this;
                    /* try { // try from 00755fc7 to 00755fcb has its CatchHandler @ 00756306 */
    FUN_0075b45c((QString *)local_58,param_1 + 0x40,&local_68,&local_68);
    if (*(int *)local_68 == 0) {
LAB_0075613d:
      QArrayData::deallocate(local_68,1,8);
    }
    else if (*(int *)local_68 != -1) {
      LOCK();
      *(int *)local_68 = *(int *)local_68 + -1;
      UNLOCK();
      if (*(int *)local_68 == 0) goto LAB_0075613d;
    }
    if (*(int *)local_78 == 0) {
LAB_00756156:
      QArrayData::deallocate(local_78,1,8);
    }
    else if (*(int *)local_78 != -1) {
      LOCK();
      *(int *)local_78 = *(int *)local_78 + -1;
      UNLOCK();
      if (*(int *)local_78 == 0) goto LAB_00756156;
    }
    if (*(int *)local_80 == 0) {
LAB_0075616f:
      QArrayData::deallocate(local_80,1,8);
    }
    else if (*(int *)local_80 != -1) {
      LOCK();
      *(int *)local_80 = *(int *)local_80 + -1;
      UNLOCK();
      if (*(int *)local_80 == 0) goto LAB_0075616f;
    }
    if (*(int *)(*(long *)(param_1 + 0x50) + 0x10) < 0) {
                    /* try { // try from 00756188 to 007561af has its CatchHandler @ 007562ee */
      QTimer::start((int)*(long *)(param_1 + 0x50));
    }
                    /* try { // try from 00756038 to 007560cf has its CatchHandler @ 007562ee */
    QDir::setCurrent((QString *)&local_90);
  }
  if (*(int *)local_88 != 0) {
    if (*(int *)local_88 == -1) goto LAB_0075605b;
    LOCK();
    *(int *)local_88 = *(int *)local_88 + -1;
    UNLOCK();
    if (*(int *)local_88 != 0) goto LAB_0075605b;
  }
  QArrayData::deallocate(local_88,2,8);
LAB_0075605b:
  if (*(int *)local_90 != 0) {
    if (*(int *)local_90 == -1) {
      return this;
    }
    LOCK();
    *(int *)local_90 = *(int *)local_90 + -1;
    UNLOCK();
    if (*(int *)local_90 != 0) {
      return this;
    }
  }
  QArrayData::deallocate(local_90,2,8);
  return this;
}


