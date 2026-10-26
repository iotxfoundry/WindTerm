// entry=00768cb6 size=315  (decompiled by Ghidra package ghidra, Utility, version 12.1.4)

void FUN_00768cb6(QObject *param_1)

{
  byte *pbVar1;
  long lVar2;
  long lVar3;
  code *pcVar4;
  QTimer *this;
  undefined8 uVar5;
  undefined4 *puVar6;
  long lVar7;
  undefined8 local_48;
  undefined8 local_40;
  code *local_38;
  undefined8 local_30;
  
  if (((*(long *)(param_1 + 0x70) != 0) && (*(int *)(*(long *)(param_1 + 0x70) + 4) != 0)) &&
     (*(long *)(param_1 + 0x78) != 0)) {
    return;
  }
  this = operator_new(0x20);
                    /* try { // try from 00768cea to 00768cee has its CatchHandler @ 00768df1 */
  QTimer::QTimer(this,param_1);
  uVar5 = QtSharedPointer::ExternalRefCountData::getAndRef((QObject *)this);
  local_38 = (code *)0x0;
  local_30 = 0;
  local_48 = *(undefined8 *)(param_1 + 0x70);
  *(undefined8 *)(param_1 + 0x70) = uVar5;
  local_40 = *(undefined8 *)(param_1 + 0x78);
  *(QTimer **)(param_1 + 0x78) = this;
  FUN_00550ea0((Connection *)&local_48);
  FUN_00550ea0(&local_38);
  lVar2 = *(long *)(param_1 + 0x70);
  if ((lVar2 != 0) && (*(int *)(lVar2 + 4) != 0)) {
    lVar3 = *(long *)(param_1 + 0x78);
    pbVar1 = (byte *)(lVar3 + 0x1c);
    *pbVar1 = *pbVar1 | 1;
    lVar7 = 0;
    if (*(int *)(lVar2 + 4) != 0) {
      lVar7 = lVar3;
    }
    local_38 = QTimer::timeout;
    local_30 = 0;
    puVar6 = operator_new(0x18);
    *puVar6 = 1;
    *(code **)(puVar6 + 2) = FUN_00767195;
    *(QObject **)(puVar6 + 4) = param_1;
    QObject::connectImpl
              ((Connection *)&local_48,lVar7,&local_38,param_1,0,puVar6,0,0,
               &QTimer::staticMetaObject);
    QMetaObject::Connection::~Connection((Connection *)&local_48);
    return;
  }
  DAT_0000001c = DAT_0000001c & 0xfe;
                    /* WARNING: Does not return */
  pcVar4 = (code *)invalidInstructionException();
  (*pcVar4)();
}


