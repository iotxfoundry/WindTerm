// Ghidra 12.1.4 decompiled — WindTerm 2.7.0 (sha256 9491b87e…) part 37
// ==== entry=00b13fa2 name=FUN_00b13fa2 size=35 ====

long FUN_00b13fa2(long *param_1)

{
  return param_1[1] - *param_1 >> 3;
}


// ==== entry=00b13fc5 name=FUN_00b13fc5 size=42 ====

void FUN_00b13fc5(undefined8 param_1,undefined8 param_2)

{
  FUN_00b1479c(param_1,param_2,0);
  return;
}


// ==== entry=00b13fef name=FUN_00b13fef size=37 ====

undefined8 FUN_00b13fef(undefined8 param_1)

{
  undefined8 local_10;
  
  FUN_00b147de(&local_10,param_1);
  return local_10;
}


// ==== entry=00b14014 name=FUN_00b14014 size=49 ====

void FUN_00b14014(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  FUN_00b147f8(param_1,param_2,param_3);
  return;
}


// ==== entry=00b14046 name=FUN_00b14046 size=31 ====

void FUN_00b14046(undefined8 param_1,undefined8 param_2)

{
  FUN_00b0f40a(param_2);
  return;
}


// ==== entry=00b14065 name=FUN_00b14065 size=26 ====

void FUN_00b14065(undefined8 param_1)

{
  FUN_00b14829(param_1);
  return;
}


// ==== entry=00b14080 name=FUN_00b14080 size=544 ====

void FUN_00b14080(long *param_1,long param_2,char param_3)

{
  long *plVar1;
  long lVar2;
  long local_58;
  long *local_50;
  long local_40;
  long local_38;
  long local_30;
  long local_28;
  ulong local_20;
  
  local_28 = (param_1[9] - param_1[5] >> 3) + 1;
  local_30 = local_28 + param_2;
  local_58 = param_2;
  local_50 = param_1;
  if ((ulong)(local_30 * 2) < (ulong)param_1[1]) {
    if (param_3 == '\0') {
      param_2 = 0;
    }
    else {
      param_2 = param_2 << 3;
    }
    local_20 = param_2 + ((ulong)(param_1[1] - local_30) >> 1) * 8 + *param_1;
    if (local_20 < (ulong)param_1[5]) {
      FUN_00b14837(param_1[5],param_1[9] + 8,local_20);
    }
    else {
      FUN_00b14883(param_1[5],param_1[9] + 8,local_28 * 8 + local_20);
    }
  }
  else {
    lVar2 = param_1[1];
    plVar1 = (long *)FUN_00b06d34(param_1 + 1,&local_58);
    local_38 = *plVar1 + lVar2 + 2;
    local_40 = FUN_00b13364(local_50,local_38);
    if (param_3 == '\0') {
      lVar2 = 0;
    }
    else {
      lVar2 = local_58 << 3;
    }
    local_20 = local_40 + ((ulong)(local_38 - local_30) >> 1) * 8 + lVar2;
    FUN_00b14837(local_50[5],local_50[9] + 8,local_20);
    FUN_00b10eb6(local_50,*local_50,local_50[1]);
    *local_50 = local_40;
    local_50[1] = local_38;
  }
  FUN_00b12bd0(local_50 + 2,local_20);
  FUN_00b12bd0(local_50 + 6,local_20 + local_28 * 8 + -8);
  return;
}


// ==== entry=00b142a0 name=FUN_00b142a0 size=42 ====

void FUN_00b142a0(undefined8 param_1,undefined8 param_2)

{
  FUN_00b148d0(param_1,param_2,0);
  return;
}


// ==== entry=00b142ca name=FUN_00b142ca size=14 ====

undefined8 FUN_00b142ca(undefined8 param_1)

{
  return param_1;
}


// ==== entry=00b142d8 name=FUN_00b142d8 size=52 ====

void FUN_00b142d8(undefined8 param_1,undefined8 param_2)

{
  undefined8 uVar1;
  
  uVar1 = FUN_00b142ca(param_2);
  FUN_00b14912(param_1,uVar1);
  return;
}


// ==== entry=00b1430c name=FUN_00b1430c size=544 ====

void FUN_00b1430c(long *param_1,long param_2,char param_3)

{
  long *plVar1;
  long lVar2;
  long local_58;
  long *local_50;
  long local_40;
  long local_38;
  long local_30;
  long local_28;
  ulong local_20;
  
  local_28 = (param_1[9] - param_1[5] >> 3) + 1;
  local_30 = local_28 + param_2;
  local_58 = param_2;
  local_50 = param_1;
  if ((ulong)(local_30 * 2) < (ulong)param_1[1]) {
    if (param_3 == '\0') {
      param_2 = 0;
    }
    else {
      param_2 = param_2 << 3;
    }
    local_20 = param_2 + ((ulong)(param_1[1] - local_30) >> 1) * 8 + *param_1;
    if (local_20 < (ulong)param_1[5]) {
      FUN_00b14961(param_1[5],param_1[9] + 8,local_20);
    }
    else {
      FUN_00b149ad(param_1[5],param_1[9] + 8,local_28 * 8 + local_20);
    }
  }
  else {
    lVar2 = param_1[1];
    plVar1 = (long *)FUN_00b06d34(param_1 + 1,&local_58);
    local_38 = *plVar1 + lVar2 + 2;
    local_40 = FUN_00b12f38(local_50,local_38);
    if (param_3 == '\0') {
      lVar2 = 0;
    }
    else {
      lVar2 = local_58 << 3;
    }
    local_20 = local_40 + ((ulong)(local_38 - local_30) >> 1) * 8 + lVar2;
    FUN_00b14961(local_50[5],local_50[9] + 8,local_20);
    FUN_00b10baa(local_50,*local_50,local_50[1]);
    *local_50 = local_40;
    local_50[1] = local_38;
  }
  FUN_00b126cc(local_50 + 2,local_20);
  FUN_00b126cc(local_50 + 6,local_20 + local_28 * 8 + -8);
  return;
}


// ==== entry=00b1452c name=FUN_00b1452c size=42 ====

void FUN_00b1452c(undefined8 param_1,undefined8 param_2)

{
  FUN_00b149fa(param_1,param_2,0);
  return;
}


// ==== entry=00b14556 name=FUN_00b14556 size=20 ====

undefined8 FUN_00b14556(void)

{
  return 0x7ffffffffffffff;
}


// ==== entry=00b1456a name=FUN_00b1456a size=66 ====

void FUN_00b1456a(undefined8 param_1,ulong param_2)

{
  ulong uVar1;
  
  uVar1 = FUN_00b14a3c(param_1);
  if (uVar1 < param_2) {
                    /* WARNING: Subroutine does not return */
    std::__throw_bad_alloc();
  }
  operator_new(param_2 << 3);
  return;
}


// ==== entry=00b145ac name=FUN_00b145ac size=27 ====

void FUN_00b145ac(undefined8 param_1)

{
  FUN_00b0eed8(param_1);
  return;
}


// ==== entry=00b145c8 name=FUN_00b145c8 size=66 ====

void FUN_00b145c8(undefined8 param_1,ulong param_2)

{
  ulong uVar1;
  
  uVar1 = FUN_00b14a50(param_1);
  if (uVar1 < param_2) {
                    /* WARNING: Subroutine does not return */
    std::__throw_bad_alloc();
  }
  operator_new(param_2 << 3);
  return;
}


// ==== entry=00b1460a name=FUN_00b1460a size=42 ====

void FUN_00b1460a(undefined8 param_1,undefined8 param_2)

{
  FUN_00b14a64(param_1,param_2,0);
  return;
}


// ==== entry=00b14634 name=FUN_00b14634 size=66 ====

void FUN_00b14634(undefined8 param_1,ulong param_2)

{
  ulong uVar1;
  
  uVar1 = FUN_00b14ab0(param_1);
  if (uVar1 < param_2) {
                    /* WARNING: Subroutine does not return */
    std::__throw_bad_alloc();
  }
  operator_new(param_2 << 3);
  return;
}


// ==== entry=00b14676 name=FUN_00b14676 size=66 ====

void FUN_00b14676(undefined8 param_1,ulong param_2)

{
  ulong uVar1;
  
  uVar1 = FUN_00b14ac4(param_1);
  if (uVar1 < param_2) {
                    /* WARNING: Subroutine does not return */
    std::__throw_bad_alloc();
  }
  operator_new(param_2 << 3);
  return;
}


// ==== entry=00b146b8 name=FUN_00b146b8 size=42 ====

void FUN_00b146b8(undefined8 param_1,undefined8 param_2)

{
  FUN_00b14ad8(param_1,param_2,0);
  return;
}


// ==== entry=00b146e2 name=FUN_00b146e2 size=14 ====

undefined8 FUN_00b146e2(undefined8 param_1)

{
  return param_1;
}


// ==== entry=00b146f0 name=FUN_00b146f0 size=53 ====

undefined8 FUN_00b146f0(undefined8 param_1)

{
  undefined8 uVar1;
  undefined8 *puVar2;
  
  uVar1 = FUN_00b102e4(param_1);
  puVar2 = (undefined8 *)FUN_00b1021e(param_1);
  *puVar2 = 0;
  return uVar1;
}


// ==== entry=00b14725 name=FUN_00b14725 size=14 ====

undefined8 FUN_00b14725(undefined8 param_1)

{
  return param_1;
}


// ==== entry=00b14734 name=FUN_00b14734 size=63 ====

void FUN_00b14734(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  undefined8 uVar1;
  undefined8 local_28;
  undefined8 local_20;
  
  local_28 = param_2;
  local_20 = param_1;
  uVar1 = FUN_00b14725(param_3);
  FUN_00b14b28(param_1,&local_28,uVar1);
  return;
}


// ==== entry=00b14773 name=FUN_00b14773 size=26 ====

void FUN_00b14773(undefined8 param_1)

{
  FUN_00b14b76(param_1);
  return;
}


// ==== entry=00b1478e name=FUN_00b1478e size=14 ====

undefined8 FUN_00b1478e(undefined8 param_1)

{
  return param_1;
}


// ==== entry=00b1479c name=FUN_00b1479c size=66 ====

void FUN_00b1479c(undefined8 param_1,ulong param_2)

{
  ulong uVar1;
  
  uVar1 = FUN_00b14b76(param_1);
  if (uVar1 < param_2) {
                    /* WARNING: Subroutine does not return */
    std::__throw_bad_alloc();
  }
  operator_new(param_2 << 3);
  return;
}


// ==== entry=00b147de name=FUN_00b147de size=26 ====

void FUN_00b147de(undefined8 *param_1,undefined8 param_2)

{
  *param_1 = param_2;
  return;
}


// ==== entry=00b147f8 name=FUN_00b147f8 size=49 ====

void FUN_00b147f8(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  FUN_00b14b8a(param_1,param_2,param_3);
  return;
}


// ==== entry=00b14829 name=FUN_00b14829 size=14 ====

undefined8 FUN_00b14829(undefined8 param_1)

{
  return param_1;
}


// ==== entry=00b14837 name=FUN_00b14837 size=76 ====

void FUN_00b14837(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  undefined8 uVar1;
  undefined8 uVar2;
  
  uVar1 = FUN_00b14c37(param_2);
  uVar2 = FUN_00b14c37(param_1);
  FUN_00b14c45(uVar2,uVar1,param_3);
  return;
}


// ==== entry=00b14883 name=FUN_00b14883 size=76 ====

void FUN_00b14883(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  undefined8 uVar1;
  undefined8 uVar2;
  
  uVar1 = FUN_00b14c37(param_2);
  uVar2 = FUN_00b14c37(param_1);
  FUN_00b14c9d(uVar2,uVar1,param_3);
  return;
}


// ==== entry=00b148d0 name=FUN_00b148d0 size=66 ====

void FUN_00b148d0(undefined8 param_1,ulong param_2)

{
  ulong uVar1;
  
  uVar1 = FUN_00b14cf6(param_1);
  if (uVar1 < param_2) {
                    /* WARNING: Subroutine does not return */
    std::__throw_bad_alloc();
  }
  operator_new(param_2 << 3);
  return;
}


// ==== entry=00b14912 name=FUN_00b14912 size=79 ====

void FUN_00b14912(undefined8 param_1,undefined8 param_2)

{
  undefined8 uVar1;
  
  uVar1 = FUN_00b0fa0e(param_2);
  uVar1 = FUN_00b14d0a(uVar1);
  FUN_00b14d18(param_1,uVar1);
  FUN_00b14d6c(param_1,param_2);
  return;
}


// ==== entry=00b14961 name=FUN_00b14961 size=76 ====

void FUN_00b14961(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  undefined8 uVar1;
  undefined8 uVar2;
  
  uVar1 = FUN_00b14dc8(param_2);
  uVar2 = FUN_00b14dc8(param_1);
  FUN_00b14dd6(uVar2,uVar1,param_3);
  return;
}


// ==== entry=00b149ad name=FUN_00b149ad size=76 ====

void FUN_00b149ad(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  undefined8 uVar1;
  undefined8 uVar2;
  
  uVar1 = FUN_00b14dc8(param_2);
  uVar2 = FUN_00b14dc8(param_1);
  FUN_00b14e2e(uVar2,uVar1,param_3);
  return;
}


// ==== entry=00b149fa name=FUN_00b149fa size=66 ====

void FUN_00b149fa(undefined8 param_1,ulong param_2)

{
  ulong uVar1;
  
  uVar1 = FUN_00b14e86(param_1);
  if (uVar1 < param_2) {
                    /* WARNING: Subroutine does not return */
    std::__throw_bad_alloc();
  }
  operator_new(param_2 << 6);
  return;
}


// ==== entry=00b14a3c name=FUN_00b14a3c size=20 ====

undefined8 FUN_00b14a3c(void)

{
  return 0x1fffffffffffffff;
}


// ==== entry=00b14a50 name=FUN_00b14a50 size=20 ====

undefined8 FUN_00b14a50(void)

{
  return 0x1fffffffffffffff;
}


// ==== entry=00b14a64 name=FUN_00b14a64 size=75 ====

void FUN_00b14a64(undefined8 param_1,ulong param_2)

{
  ulong uVar1;
  
  uVar1 = FUN_00b14e9a(param_1);
  if (uVar1 < param_2) {
                    /* WARNING: Subroutine does not return */
    std::__throw_bad_alloc();
  }
  operator_new(param_2 * 0x30);
  return;
}


// ==== entry=00b14ab0 name=FUN_00b14ab0 size=20 ====

undefined8 FUN_00b14ab0(void)

{
  return 0x1fffffffffffffff;
}


// ==== entry=00b14ac4 name=FUN_00b14ac4 size=20 ====

undefined8 FUN_00b14ac4(void)

{
  return 0x1fffffffffffffff;
}


// ==== entry=00b14ad8 name=FUN_00b14ad8 size=66 ====

void FUN_00b14ad8(undefined8 param_1,ulong param_2)

{
  ulong uVar1;
  
  uVar1 = FUN_00b14eae(param_1);
  if (uVar1 < param_2) {
                    /* WARNING: Subroutine does not return */
    std::__throw_bad_alloc();
  }
  operator_new(param_2 << 2);
  return;
}


// ==== entry=00b14b1a name=FUN_00b14b1a size=14 ====

undefined8 FUN_00b14b1a(undefined8 param_1)

{
  return param_1;
}


// ==== entry=00b14b28 name=FUN_00b14b28 size=78 ====

void FUN_00b14b28(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  undefined8 uVar1;
  undefined8 uVar2;
  
  uVar1 = FUN_00b14725(param_3);
  uVar2 = FUN_00b14b1a(param_2);
  FUN_00b14ec2(param_1,uVar2,uVar1);
  return;
}


// ==== entry=00b14b76 name=FUN_00b14b76 size=20 ====

undefined8 FUN_00b14b76(void)

{
  return 0x1fffffffffffffff;
}


// ==== entry=00b14b8a name=FUN_00b14b8a size=122 ====

long FUN_00b14b8a(undefined8 param_1,undefined8 param_2,long param_3)

{
  char cVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 local_38;
  undefined8 local_30 [2];
  long local_20;
  
  local_38 = param_2;
  local_30[0] = param_1;
  local_20 = param_3;
  while( true ) {
                    /* try { // try from 00b14bb5 to 00b14bb9 has its CatchHandler @ 00b14bfd */
    cVar1 = FUN_00b14f18(local_30,&local_38);
    if (cVar1 == '\0') break;
    uVar2 = FUN_00b14f60(local_30);
    uVar3 = FUN_00b123ad(local_20);
    FUN_00b14f71(uVar3,uVar2);
    FUN_00b14f40(local_30);
    local_20 = local_20 + 8;
  }
  return local_20;
}


// ==== entry=00b14c37 name=FUN_00b14c37 size=14 ====

undefined8 FUN_00b14c37(undefined8 param_1)

{
  return param_1;
}


// ==== entry=00b14c45 name=FUN_00b14c45 size=88 ====

void FUN_00b14c45(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  
  uVar1 = FUN_00b14fb5(param_3);
  uVar2 = FUN_00b14fb5(param_2);
  uVar3 = FUN_00b14fb5(param_1);
  FUN_00b14fc3(uVar3,uVar2,uVar1);
  return;
}


// ==== entry=00b14c9d name=FUN_00b14c9d size=88 ====

void FUN_00b14c9d(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  
  uVar1 = FUN_00b14fb5(param_3);
  uVar2 = FUN_00b14fb5(param_2);
  uVar3 = FUN_00b14fb5(param_1);
  FUN_00b14ff4(uVar3,uVar2,uVar1);
  return;
}


// ==== entry=00b14cf6 name=FUN_00b14cf6 size=20 ====

undefined8 FUN_00b14cf6(void)

{
  return 0x1fffffffffffffff;
}


// ==== entry=00b14d0a name=FUN_00b14d0a size=14 ====

undefined8 FUN_00b14d0a(undefined8 param_1)

{
  return param_1;
}


// ==== entry=00b14d18 name=FUN_00b14d18 size=84 ====

void FUN_00b14d18(undefined8 *param_1,undefined8 param_2)

{
  undefined8 uVar1;
  
  uVar1 = FUN_00b14d0a(param_2);
  FUN_00b15026(param_1,uVar1);
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  return;
}


// ==== entry=00b14d6c name=FUN_00b14d6c size=92 ====

void FUN_00b14d6c(long param_1,long param_2)

{
  FUN_00b1505a(param_1,param_2);
  FUN_00b1505a(param_1 + 8,param_2 + 8);
  FUN_00b1505a(param_1 + 0x10,param_2 + 0x10);
  return;
}


// ==== entry=00b14dc8 name=FUN_00b14dc8 size=14 ====

undefined8 FUN_00b14dc8(undefined8 param_1)

{
  return param_1;
}


// ==== entry=00b14dd6 name=FUN_00b14dd6 size=88 ====

void FUN_00b14dd6(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  
  uVar1 = FUN_00b150ac(param_3);
  uVar2 = FUN_00b150ac(param_2);
  uVar3 = FUN_00b150ac(param_1);
  FUN_00b150ba(uVar3,uVar2,uVar1);
  return;
}


// ==== entry=00b14e2e name=FUN_00b14e2e size=88 ====

void FUN_00b14e2e(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  
  uVar1 = FUN_00b150ac(param_3);
  uVar2 = FUN_00b150ac(param_2);
  uVar3 = FUN_00b150ac(param_1);
  FUN_00b150eb(uVar3,uVar2,uVar1);
  return;
}


// ==== entry=00b14e86 name=FUN_00b14e86 size=20 ====

undefined8 FUN_00b14e86(void)

{
  return 0x3ffffffffffffff;
}


// ==== entry=00b14e9a name=FUN_00b14e9a size=20 ====

undefined8 FUN_00b14e9a(void)

{
  return 0x555555555555555;
}


// ==== entry=00b14eae name=FUN_00b14eae size=20 ====

undefined8 FUN_00b14eae(void)

{
  return 0x3fffffffffffffff;
}


// ==== entry=00b14ec2 name=FUN_00b14ec2 size=86 ====

void FUN_00b14ec2(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  undefined8 uVar1;
  
  uVar1 = FUN_00b14725(param_3);
  FUN_00b1511c(param_1,uVar1);
  uVar1 = FUN_00b14b1a(param_2);
  FUN_00b1514e(param_1,uVar1);
  return;
}


// ==== entry=00b14f18 name=FUN_00b14f18 size=40 ====

uint FUN_00b14f18(undefined8 param_1,undefined8 param_2)

{
  uint uVar1;
  
  uVar1 = FUN_00b15177(param_1,param_2);
  return uVar1 ^ 1;
}


// ==== entry=00b14f40 name=FUN_00b14f40 size=32 ====

long * FUN_00b14f40(long *param_1)

{
  *param_1 = *param_1 + 8;
  return param_1;
}


// ==== entry=00b14f60 name=FUN_00b14f60 size=17 ====

undefined8 FUN_00b14f60(undefined8 *param_1)

{
  return *param_1;
}


// ==== entry=00b14f71 name=FUN_00b14f71 size=68 ====

void FUN_00b14f71(undefined8 param_1,undefined8 param_2)

{
  undefined8 uVar1;
  undefined8 uVar2;
  
  uVar1 = FUN_00b111ba(param_2);
  uVar2 = FUN_00b00efa(8,param_1);
  FUN_00b13f2e(uVar2,uVar1);
  return;
}


// ==== entry=00b14fb5 name=FUN_00b14fb5 size=14 ====

undefined8 FUN_00b14fb5(undefined8 param_1)

{
  return param_1;
}


// ==== entry=00b14fc3 name=FUN_00b14fc3 size=49 ====

void FUN_00b14fc3(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  FUN_00b151b0(param_1,param_2,param_3);
  return;
}


// ==== entry=00b14ff4 name=FUN_00b14ff4 size=49 ====

void FUN_00b14ff4(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  FUN_00b1520f(param_1,param_2,param_3);
  return;
}


// ==== entry=00b15026 name=FUN_00b15026 size=38 ====

void FUN_00b15026(undefined8 param_1,undefined8 param_2)

{
  FUN_00b15282(param_1,param_2);
  return;
}


// ==== entry=00b1504c name=FUN_00b1504c size=14 ====

undefined8 FUN_00b1504c(undefined8 param_1)

{
  return param_1;
}


// ==== entry=00b1505a name=FUN_00b1505a size=82 ====

void FUN_00b1505a(undefined8 *param_1,undefined8 *param_2)

{
  undefined8 *puVar1;
  undefined8 local_10;
  
  puVar1 = (undefined8 *)FUN_00b1504c(param_1);
  local_10 = *puVar1;
  puVar1 = (undefined8 *)FUN_00b1504c(param_2);
  *param_1 = *puVar1;
  puVar1 = (undefined8 *)FUN_00b1504c(&local_10);
  *param_2 = *puVar1;
  return;
}


// ==== entry=00b150ac name=FUN_00b150ac size=14 ====

undefined8 FUN_00b150ac(undefined8 param_1)

{
  return param_1;
}


// ==== entry=00b150ba name=FUN_00b150ba size=49 ====

void FUN_00b150ba(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  FUN_00b15291(param_1,param_2,param_3);
  return;
}


// ==== entry=00b150eb name=FUN_00b150eb size=49 ====

void FUN_00b150eb(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  FUN_00b152f0(param_1,param_2,param_3);
  return;
}


// ==== entry=00b1511c name=FUN_00b1511c size=49 ====

void FUN_00b1511c(undefined8 param_1,undefined8 param_2)

{
  undefined8 uVar1;
  
  uVar1 = FUN_00b14725(param_2);
  FUN_00b15362(param_1,uVar1);
  return;
}


// ==== entry=00b1514e name=FUN_00b1514e size=41 ====

void FUN_00b1514e(undefined8 *param_1,undefined8 param_2)

{
  undefined8 *puVar1;
  
  puVar1 = (undefined8 *)FUN_00b14b1a(param_2);
  *param_1 = *puVar1;
  return;
}


// ==== entry=00b15177 name=FUN_00b15177 size=57 ====

bool FUN_00b15177(undefined8 param_1,undefined8 param_2)

{
  long lVar1;
  long lVar2;
  
  lVar1 = FUN_00b15382(param_1);
  lVar2 = FUN_00b15382(param_2);
  return lVar1 == lVar2;
}


// ==== entry=00b151b0 name=FUN_00b151b0 size=95 ====

void * FUN_00b151b0(void *param_1,long param_2,void *param_3)

{
  long lVar1;
  
  lVar1 = param_2 - (long)param_1 >> 3;
  if (lVar1 != 0) {
    memmove(param_3,param_1,lVar1 * 8);
  }
  return (void *)((long)param_3 + lVar1 * 8);
}


// ==== entry=00b1520f name=FUN_00b1520f size=114 ====

long FUN_00b1520f(void *param_1,long param_2,long param_3)

{
  long lVar1;
  
  lVar1 = param_2 - (long)param_1 >> 3;
  if (lVar1 != 0) {
    memmove((void *)(lVar1 * -8 + param_3),param_1,lVar1 * 8);
  }
  return param_3 + lVar1 * -8;
}


// ==== entry=00b15282 name=FUN_00b15282 size=15 ====

void FUN_00b15282(void)

{
  return;
}


// ==== entry=00b15291 name=FUN_00b15291 size=95 ====

void * FUN_00b15291(void *param_1,long param_2,void *param_3)

{
  long lVar1;
  
  lVar1 = param_2 - (long)param_1 >> 3;
  if (lVar1 != 0) {
    memmove(param_3,param_1,lVar1 * 8);
  }
  return (void *)((long)param_3 + lVar1 * 8);
}


// ==== entry=00b152f0 name=FUN_00b152f0 size=114 ====

long FUN_00b152f0(void *param_1,long param_2,long param_3)

{
  long lVar1;
  
  lVar1 = param_2 - (long)param_1 >> 3;
  if (lVar1 != 0) {
    memmove((void *)(lVar1 * -8 + param_3),param_1,lVar1 * 8);
  }
  return param_3 + lVar1 * -8;
}


// ==== entry=00b15362 name=FUN_00b15362 size=31 ====

void FUN_00b15362(undefined8 param_1,undefined8 param_2)

{
  FUN_00b14725(param_2);
  return;
}


// ==== entry=00b15382 name=FUN_00b15382 size=17 ====

undefined8 FUN_00b15382(undefined8 *param_1)

{
  return *param_1;
}


// ==== entry=00b15394 name=FUN_00b15394 size=729 ====

void FUN_00b15394(long param_1)

{
  bool bVar1;
  bool bVar2;
  char cVar3;
  undefined8 uVar4;
  string local_b0 [8];
  undefined1 local_a8 [24];
  string asStack_90 [8];
  undefined1 auStack_88 [32];
  undefined1 local_68 [24];
  string local_50 [12];
  undefined1 local_44 [12];
  undefined1 local_38 [32];
  
  std::string::string(local_50);
  FUN_00b0f0d6(local_68);
                    /* try { // try from 00b153cb to 00b15430 has its CatchHandler @ 00b156a1 */
  FUN_00b0cdf6(param_1);
  FUN_00b1aade(param_1);
  *(undefined1 *)(param_1 + 0xd2) = 0;
  *(undefined1 *)(param_1 + 0xd3) = 0;
  local_44 = FUN_00b0d79a(param_1);
  FUN_00b0ed54(local_a8,0,local_44);
                    /* try { // try from 00b15440 to 00b154e3 has its CatchHandler @ 00b1568d */
  FUN_00b2174c(param_1,1);
  do {
    cVar3 = FUN_00b215d8(param_1);
    if (cVar3 == '\0') {
LAB_00b15480:
      bVar1 = false;
    }
    else {
      uVar4 = FUN_00b0dd0a();
      cVar3 = FUN_00b0d930(uVar4,param_1);
      if (cVar3 == '\x01') goto LAB_00b15480;
      bVar1 = true;
    }
    if (!bVar1) break;
    cVar3 = FUN_00b21658(param_1);
    std::string::operator+=(asStack_90,cVar3);
  } while( true );
LAB_00b154b2:
  while( true ) {
    uVar4 = FUN_00b0db18();
    cVar3 = FUN_00b0d930(uVar4,param_1);
    if (cVar3 == '\0') break;
    FUN_00b2174c(param_1,1);
  }
  bVar1 = false;
                    /* try { // try from 00b154f5 to 00b15542 has its CatchHandler @ 00b15661 */
  cVar3 = FUN_00b0d772(param_1);
  if (cVar3 == '\0') {
    uVar4 = FUN_00b0dbb2();
    cVar3 = FUN_00b0d930(uVar4,param_1);
    if (cVar3 == '\0') {
      FUN_00b0e6c4(local_38);
      bVar1 = true;
      cVar3 = FUN_00b0d930(local_38,param_1);
      if (cVar3 == '\0') {
        bVar2 = false;
        goto LAB_00b15555;
      }
    }
  }
  bVar2 = true;
LAB_00b15555:
  if (bVar1) {
    FUN_00b0d994(local_38);
  }
  if (bVar2) {
                    /* try { // try from 00b15585 to 00b1559d has its CatchHandler @ 00b1568d */
    FUN_00b18ccc(param_1 + 0x80,local_a8);
    FUN_00b0eed8(local_a8);
    FUN_0081a1e4(local_68);
    std::string::~string(local_50);
    return;
  }
  std::string::string(local_b0);
  do {
                    /* try { // try from 00b155a8 to 00b15623 has its CatchHandler @ 00b15679 */
    cVar3 = FUN_00b215d8(param_1);
    if (cVar3 == '\0') {
LAB_00b155d9:
      bVar1 = false;
    }
    else {
      uVar4 = FUN_00b0dd0a();
      cVar3 = FUN_00b0d930(uVar4,param_1);
      if (cVar3 == '\x01') goto LAB_00b155d9;
      bVar1 = true;
    }
    if (!bVar1) break;
    cVar3 = FUN_00b21658(param_1);
    std::string::operator+=(local_b0,cVar3);
  } while( true );
  FUN_00b18c50(auStack_88,local_b0);
  std::string::~string(local_b0);
  goto LAB_00b154b2;
}


// ==== entry=00b156d4 name=FUN_00b156d4 size=171 ====

void FUN_00b156d4(long param_1)

{
  undefined1 local_64 [12];
  undefined1 local_58 [72];
  
  FUN_00b0cdf6(param_1);
  FUN_00b1aade(param_1);
  *(undefined1 *)(param_1 + 0xd2) = 0;
  *(undefined1 *)(param_1 + 0xd3) = 0;
  local_64 = FUN_00b0d79a(param_1);
  FUN_00b2174c(param_1,3);
  FUN_00b0ed54(local_58,1,local_64);
                    /* try { // try from 00b15765 to 00b15769 has its CatchHandler @ 00b15778 */
  FUN_00b0f508(param_1 + 0x80,local_58);
  FUN_00b0eed8(local_58);
  return;
}


// ==== entry=00b1579a name=FUN_00b1579a size=171 ====

void FUN_00b1579a(long param_1)

{
  undefined1 local_64 [12];
  undefined1 local_58 [72];
  
  FUN_00b0cdf6(param_1);
  FUN_00b1aade(param_1);
  *(undefined1 *)(param_1 + 0xd2) = 0;
  *(undefined1 *)(param_1 + 0xd3) = 0;
  local_64 = FUN_00b0d79a(param_1);
  FUN_00b2174c(param_1,3);
  FUN_00b0ed54(local_58,2,local_64);
                    /* try { // try from 00b1582b to 00b1582f has its CatchHandler @ 00b1583e */
  FUN_00b0f508(param_1 + 0x80,local_58);
  FUN_00b0eed8(local_58);
  return;
}


// ==== entry=00b15860 name=FUN_00b15860 size=227 ====

void FUN_00b15860(long param_1)

{
  uint local_78;
  undefined1 local_74 [12];
  undefined1 local_68 [72];
  undefined4 local_20;
  char local_19;
  
  FUN_00b1a798(param_1);
  *(undefined1 *)(param_1 + 0xd2) = 1;
  *(undefined1 *)(param_1 + 0xd3) = 0;
  local_74 = FUN_00b0d79a(param_1);
  local_19 = FUN_00b21658(param_1);
  local_78 = (uint)(local_19 == '[');
  FUN_00b18cf2(param_1 + 400,&local_78);
  if (local_78 == 1) {
    local_20 = 8;
  }
  else {
    local_20 = 9;
  }
  FUN_00b0ed54(local_68,local_20,local_74);
                    /* try { // try from 00b15929 to 00b1592d has its CatchHandler @ 00b1593c */
  FUN_00b0f508(param_1 + 0x80,local_68);
  FUN_00b0eed8(local_68);
  return;
}


// ==== entry=00b1595e name=FUN_00b1595e size=820 ====

void FUN_00b1595e(long param_1)

{
  bool bVar1;
  char cVar2;
  undefined8 uVar3;
  int *piVar4;
  uint *puVar5;
  undefined1 local_ec [12];
  string local_e0 [11];
  allocator local_d5;
  undefined1 local_d4 [12];
  undefined1 local_c8 [68];
  undefined1 local_84 [12];
  string local_78 [15];
  allocator local_69;
  undefined1 local_68 [68];
  undefined4 local_24;
  uint local_20;
  char local_19;
  
  cVar2 = FUN_00b0ee1e(param_1);
  if (cVar2 != '\0') {
    uVar3 = __cxa_allocate_exception(0x28);
    std::allocator<char>::allocator();
                    /* try { // try from 00b159bc to 00b159c0 has its CatchHandler @ 00b15c9a */
    std::string::string(local_e0,"illegal flow end",&local_d5);
    local_d4 = FUN_00b0d79a(param_1);
                    /* try { // try from 00b159fc to 00b15a00 has its CatchHandler @ 00b15c86 */
    FUN_00b09fc4(uVar3,local_d4,local_e0);
    std::string::~string(local_e0);
    std::allocator<char>::~allocator((allocator<char> *)&local_d5);
                    /* WARNING: Subroutine does not return */
    __cxa_throw(uVar3,&PTR_PTR_00d39ce8,FUN_00b009e6);
  }
  cVar2 = FUN_00b0edfa(param_1);
  if (cVar2 != '\0') {
    piVar4 = (int *)FUN_00b18d18(param_1 + 400);
    if ((*piVar4 == 0) && (cVar2 = FUN_00b1a9c8(param_1), cVar2 != '\0')) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if (bVar1) {
      local_84 = FUN_00b0d79a(param_1);
      FUN_00b0ed54(local_c8,0xf,local_84);
                    /* try { // try from 00b15ad7 to 00b15adb has its CatchHandler @ 00b15cbf */
      FUN_00b0f508(param_1 + 0x80,local_c8);
      FUN_00b0eed8(local_c8);
    }
    else {
      piVar4 = (int *)FUN_00b18d18(param_1 + 400);
      if (*piVar4 == 1) {
        FUN_00b1a946(param_1);
      }
    }
  }
  *(undefined1 *)(param_1 + 0xd2) = 0;
  *(undefined1 *)(param_1 + 0xd3) = 1;
  local_ec = FUN_00b0d79a(param_1);
  local_19 = FUN_00b21658(param_1);
  local_20 = (uint)(local_19 == ']');
  puVar5 = (uint *)FUN_00b18d18(param_1 + 400);
  if (local_20 != *puVar5) {
    uVar3 = __cxa_allocate_exception(0x28);
    std::allocator<char>::allocator();
                    /* try { // try from 00b15bd1 to 00b15bd5 has its CatchHandler @ 00b15ced */
    std::string::string(local_78,"illegal flow end",&local_69);
                    /* try { // try from 00b15be7 to 00b15beb has its CatchHandler @ 00b15cdc */
    FUN_00b09fc4(uVar3,local_ec,local_78);
    std::string::~string(local_78);
    std::allocator<char>::~allocator((allocator<char> *)&local_69);
                    /* WARNING: Subroutine does not return */
    __cxa_throw(uVar3,&PTR_PTR_00d39ce8,FUN_00b009e6);
  }
  FUN_00b18d32(param_1 + 400);
  if (local_20 == 0) {
    local_24 = 0xb;
  }
  else {
    local_24 = 10;
  }
  FUN_00b0ed54(local_68,local_24,local_ec);
                    /* try { // try from 00b15c70 to 00b15c74 has its CatchHandler @ 00b15d0f */
  FUN_00b0f508(param_1 + 0x80,local_68);
  FUN_00b0eed8(local_68);
  return;
}


// ==== entry=00b15d36 name=FUN_00b15d36 size=419 ====

void FUN_00b15d36(long param_1)

{
  bool bVar1;
  char cVar2;
  int *piVar3;
  undefined1 local_b4 [12];
  undefined1 local_a8 [68];
  undefined1 local_64 [12];
  undefined1 local_58 [72];
  
  cVar2 = FUN_00b0edfa(param_1);
  if (cVar2 == '\0') goto LAB_00b15e35;
  piVar3 = (int *)FUN_00b18d18(param_1 + 400);
  if (*piVar3 == 0) {
    cVar2 = FUN_00b1a9c8(param_1);
    if (cVar2 == '\0') goto LAB_00b15d95;
    bVar1 = true;
  }
  else {
LAB_00b15d95:
    bVar1 = false;
  }
  if (bVar1) {
    local_64 = FUN_00b0d79a(param_1);
    FUN_00b0ed54(local_a8,0xf,local_64);
                    /* try { // try from 00b15def to 00b15df3 has its CatchHandler @ 00b15ecf */
    FUN_00b0f508(param_1 + 0x80,local_a8);
    FUN_00b0eed8(local_a8);
  }
  else {
    piVar3 = (int *)FUN_00b18d18(param_1 + 400);
    if (*piVar3 == 1) {
      FUN_00b1a946(param_1);
    }
  }
LAB_00b15e35:
  *(undefined1 *)(param_1 + 0xd2) = 1;
  *(undefined1 *)(param_1 + 0xd3) = 0;
  local_b4 = FUN_00b0d79a(param_1);
  FUN_00b2174c(param_1,1);
  FUN_00b0ed54(local_58,0xd,local_b4);
                    /* try { // try from 00b15ebc to 00b15ec0 has its CatchHandler @ 00b15eec */
  FUN_00b0f508(param_1 + 0x80,local_58);
  FUN_00b0eed8(local_58);
  return;
}


// ==== entry=00b15f10 name=FUN_00b15f10 size=551 ====

void FUN_00b15f10(long param_1)

{
  char cVar1;
  undefined4 uVar2;
  undefined8 uVar3;
  undefined1 local_94 [12];
  string local_88 [11];
  allocator local_7d;
  undefined1 local_7c [12];
  string local_70 [11];
  allocator local_65;
  undefined1 local_64 [12];
  undefined1 local_58 [64];
  
  cVar1 = FUN_00b0edfa(param_1);
  if (cVar1 != '\0') {
    uVar3 = __cxa_allocate_exception(0x28);
    std::allocator<char>::allocator();
                    /* try { // try from 00b15f65 to 00b15f69 has its CatchHandler @ 00b1613c */
    std::string::string(local_88,"illegal block entry",&local_7d);
    local_7c = FUN_00b0d79a(param_1);
                    /* try { // try from 00b15f96 to 00b15f9a has its CatchHandler @ 00b1612b */
    FUN_00b09fc4(uVar3,local_7c,local_88);
    std::string::~string(local_88);
    std::allocator<char>::~allocator((allocator<char> *)&local_7d);
                    /* WARNING: Subroutine does not return */
    __cxa_throw(uVar3,&PTR_PTR_00d39ce8,FUN_00b009e6);
  }
  if (*(char *)(param_1 + 0xd2) != '\x01') {
    uVar3 = __cxa_allocate_exception(0x28);
    std::allocator<char>::allocator();
                    /* try { // try from 00b16007 to 00b1600b has its CatchHandler @ 00b1616f */
    std::string::string(local_70,"illegal block entry",&local_65);
    local_64 = FUN_00b0d79a(param_1);
                    /* try { // try from 00b16038 to 00b1603c has its CatchHandler @ 00b1615e */
    FUN_00b09fc4(uVar3,local_64,local_70);
    std::string::~string(local_70);
    std::allocator<char>::~allocator((allocator<char> *)&local_65);
                    /* WARNING: Subroutine does not return */
    __cxa_throw(uVar3,&PTR_PTR_00d39ce8,FUN_00b009e6);
  }
  uVar2 = FUN_00b0d7c0(param_1);
  FUN_00b0cb42(param_1,uVar2,1);
  *(undefined1 *)(param_1 + 0xd2) = 1;
  *(undefined1 *)(param_1 + 0xd3) = 0;
  local_94 = FUN_00b0d79a(param_1);
  FUN_00b2174c(param_1,1);
  FUN_00b0ed54(local_58,7,local_94);
                    /* try { // try from 00b16115 to 00b16119 has its CatchHandler @ 00b16191 */
  FUN_00b0f508(param_1 + 0x80,local_58);
  FUN_00b0eed8(local_58);
  return;
}


// ==== entry=00b161b8 name=FUN_00b161b8 size=395 ====

void FUN_00b161b8(long param_1)

{
  char cVar1;
  undefined1 uVar2;
  undefined4 uVar3;
  undefined8 uVar4;
  undefined1 local_7c [12];
  string local_70 [11];
  allocator local_65;
  undefined1 local_64 [12];
  undefined1 local_58 [64];
  
  cVar1 = FUN_00b0ee1e(param_1);
  if (cVar1 != '\0') {
    if (*(char *)(param_1 + 0xd2) != '\x01') {
      uVar4 = __cxa_allocate_exception(0x28);
      std::allocator<char>::allocator();
                    /* try { // try from 00b16223 to 00b16227 has its CatchHandler @ 00b1634b */
      std::string::string(local_70,"illegal map key",&local_65);
      local_64 = FUN_00b0d79a(param_1);
                    /* try { // try from 00b16254 to 00b16258 has its CatchHandler @ 00b1633a */
      FUN_00b09fc4(uVar4,local_64,local_70);
      std::string::~string(local_70);
      std::allocator<char>::~allocator((allocator<char> *)&local_65);
                    /* WARNING: Subroutine does not return */
      __cxa_throw(uVar4,&PTR_PTR_00d39ce8,FUN_00b009e6);
    }
    uVar3 = FUN_00b0d7c0(param_1);
    FUN_00b0cb42(param_1,uVar3,0);
  }
  uVar2 = FUN_00b0ee1e(param_1);
  *(undefined1 *)(param_1 + 0xd2) = uVar2;
  local_7c = FUN_00b0d79a(param_1);
  FUN_00b2174c(param_1,1);
  FUN_00b0ed54(local_58,0xe,local_7c);
                    /* try { // try from 00b16327 to 00b1632b has its CatchHandler @ 00b1636d */
  FUN_00b0f508(param_1 + 0x80,local_58);
  FUN_00b0eed8(local_58);
  return;
}


// ==== entry=00b16390 name=FUN_00b16390 size=464 ====

void FUN_00b16390(long param_1)

{
  char cVar1;
  undefined1 uVar2;
  undefined4 uVar3;
  undefined8 uVar4;
  undefined1 local_8c [12];
  string local_80 [11];
  allocator local_75;
  undefined1 local_74 [12];
  undefined1 local_68 [79];
  char local_19;
  
  local_19 = FUN_00b1a9c8(param_1);
  *(undefined1 *)(param_1 + 0xd3) = 0;
  if (local_19 == '\0') {
    cVar1 = FUN_00b0ee1e(param_1);
    if (cVar1 != '\0') {
      if (*(char *)(param_1 + 0xd2) != '\x01') {
        uVar4 = __cxa_allocate_exception(0x28);
        std::allocator<char>::allocator();
                    /* try { // try from 00b16437 to 00b1643b has its CatchHandler @ 00b16565 */
        std::string::string(local_80,"illegal map value",&local_75);
        local_74 = FUN_00b0d79a(param_1);
                    /* try { // try from 00b16468 to 00b1646c has its CatchHandler @ 00b16554 */
        FUN_00b09fc4(uVar4,local_74,local_80);
        std::string::~string(local_80);
        std::allocator<char>::~allocator((allocator<char> *)&local_75);
                    /* WARNING: Subroutine does not return */
        __cxa_throw(uVar4,&PTR_PTR_00d39ce8,FUN_00b009e6);
      }
      uVar3 = FUN_00b0d7c0(param_1);
      FUN_00b0cb42(param_1,uVar3,0);
    }
    uVar2 = FUN_00b0ee1e(param_1);
    *(undefined1 *)(param_1 + 0xd2) = uVar2;
  }
  else {
    *(undefined1 *)(param_1 + 0xd2) = 0;
  }
  local_8c = FUN_00b0d79a(param_1);
  FUN_00b2174c(param_1,1);
  FUN_00b0ed54(local_68,0xf,local_8c);
                    /* try { // try from 00b16541 to 00b16545 has its CatchHandler @ 00b16587 */
  FUN_00b0f508(param_1 + 0x80,local_68);
  FUN_00b0eed8(local_68);
  return;
}


// ==== entry=00b165ae name=FUN_00b165ae size=772 ====

void FUN_00b165ae(long param_1)

{
  bool bVar1;
  char cVar2;
  undefined8 uVar3;
  char *pcVar4;
  undefined1 local_a8 [24];
  string asStack_90 [44];
  undefined1 local_64 [12];
  string local_58 [8];
  string local_50 [11];
  allocator local_45;
  undefined1 local_44 [12];
  string local_38 [15];
  allocator local_29;
  undefined1 local_28 [12];
  char local_1a;
  char local_19;
  
  std::string::string(local_58);
                    /* try { // try from 00b165d9 to 00b16694 has its CatchHandler @ 00b16914 */
  FUN_00b1a798(param_1);
  *(undefined1 *)(param_1 + 0xd2) = 0;
  *(undefined1 *)(param_1 + 0xd3) = 0;
  local_64 = FUN_00b0d79a(param_1);
  local_19 = FUN_00b21658(param_1);
  local_1a = local_19 == '*';
  do {
    cVar2 = FUN_00b215d8(param_1);
    if (cVar2 == '\0') {
LAB_00b1666c:
      bVar1 = false;
    }
    else {
      uVar3 = FUN_00b17f41();
      cVar2 = FUN_00b0d930(uVar3,param_1);
      if (cVar2 == '\0') goto LAB_00b1666c;
      bVar1 = true;
    }
    if (!bVar1) break;
    cVar2 = FUN_00b21658(param_1);
    std::string::operator+=(local_58,cVar2);
  } while( true );
  cVar2 = std::string::empty(local_58);
  if (cVar2 != '\0') {
    uVar3 = __cxa_allocate_exception(0x28);
    std::allocator<char>::allocator();
    if (local_1a == '\0') {
      pcVar4 = "anchor not found after &";
    }
    else {
      pcVar4 = "alias not found after *";
    }
                    /* try { // try from 00b166e4 to 00b166e8 has its CatchHandler @ 00b168b7 */
    std::string::string(local_50,pcVar4,&local_45);
    local_44 = FUN_00b0d79a(param_1);
                    /* try { // try from 00b16715 to 00b16719 has its CatchHandler @ 00b168a6 */
    FUN_00b09fc4(uVar3,local_44,local_50);
    std::string::~string(local_50);
    std::allocator<char>::~allocator((allocator<char> *)&local_45);
                    /* WARNING: Subroutine does not return */
                    /* try { // try from 00b1673f to 00b16770 has its CatchHandler @ 00b16914 */
    __cxa_throw(uVar3,&PTR_PTR_00d39ce8,FUN_00b009e6);
  }
  cVar2 = FUN_00b215d8(param_1);
  if (cVar2 != '\0') {
    uVar3 = FUN_00b180a7();
    cVar2 = FUN_00b0d930(uVar3,param_1);
    if (cVar2 != '\x01') {
      bVar1 = true;
      goto LAB_00b16784;
    }
  }
  bVar1 = false;
LAB_00b16784:
  if (bVar1) {
    uVar3 = __cxa_allocate_exception(0x28);
    std::allocator<char>::allocator();
    if (local_1a == '\0') {
      pcVar4 = "illegal character found while scanning anchor";
    }
    else {
      pcVar4 = "illegal character found while scanning alias";
    }
                    /* try { // try from 00b167c5 to 00b167c9 has its CatchHandler @ 00b168e4 */
    std::string::string(local_38,pcVar4,&local_29);
    local_28 = FUN_00b0d79a(param_1);
                    /* try { // try from 00b167f6 to 00b167fa has its CatchHandler @ 00b168d3 */
    FUN_00b09fc4(uVar3,local_28,local_38);
    std::string::~string(local_38);
    std::allocator<char>::~allocator((allocator<char> *)&local_29);
                    /* WARNING: Subroutine does not return */
                    /* try { // try from 00b16820 to 00b1684b has its CatchHandler @ 00b16914 */
    __cxa_throw(uVar3,&PTR_PTR_00d39ce8,FUN_00b009e6);
  }
  if (local_1a == '\0') {
    uVar3 = 0x10;
  }
  else {
    uVar3 = 0x11;
  }
  FUN_00b0ed54(local_a8,uVar3,local_64);
                    /* try { // try from 00b16861 to 00b16885 has its CatchHandler @ 00b16900 */
  std::string::operator=(asStack_90,local_58);
  FUN_00b18ccc(param_1 + 0x80,local_a8);
  FUN_00b0eed8(local_a8);
  std::string::~string(local_58);
  return;
}


// ==== entry=00b1693a name=FUN_00b1693a size=579 ====

void FUN_00b1693a(long param_1)

{
  bool bVar1;
  char cVar2;
  char local_81;
  string local_80 [8];
  undefined1 local_78 [24];
  string asStack_60 [8];
  undefined1 auStack_58 [24];
  undefined4 local_40;
  undefined1 local_34 [12];
  string local_28 [8];
  string local_20 [16];
  
  FUN_00b1a798(param_1);
  *(undefined1 *)(param_1 + 0xd2) = 0;
  *(undefined1 *)(param_1 + 0xd3) = 0;
  local_34 = FUN_00b0d79a(param_1);
  FUN_00b0ed54(local_78,0x12,local_34);
                    /* try { // try from 00b169b5 to 00b16a05 has its CatchHandler @ 00b16ba6 */
  FUN_00b21658(param_1);
  cVar2 = FUN_00b215d8(param_1);
  if (cVar2 == '\0') {
LAB_00b169e7:
    bVar1 = false;
  }
  else {
    cVar2 = FUN_00b21596(param_1);
    if (cVar2 != '<') goto LAB_00b169e7;
    bVar1 = true;
  }
  if (bVar1) {
    FUN_00b28964(local_80,param_1);
                    /* try { // try from 00b16a18 to 00b16a1c has its CatchHandler @ 00b16b73 */
    std::string::operator=(asStack_60,local_80);
    local_40 = 0;
    std::string::~string(local_80);
    goto LAB_00b16b48;
  }
                    /* try { // try from 00b16a4a to 00b16a4e has its CatchHandler @ 00b16ba6 */
  FUN_00b28b0f(local_28,param_1,&local_81);
                    /* try { // try from 00b16a61 to 00b16a65 has its CatchHandler @ 00b16b84 */
  std::string::operator=(asStack_60,local_28);
  std::string::~string(local_28);
  if (local_81 == '\x01') {
LAB_00b16a98:
    bVar1 = false;
  }
  else {
    cVar2 = std::string::empty(asStack_60);
    if (cVar2 == '\0') goto LAB_00b16a98;
    bVar1 = true;
  }
  if (bVar1) {
    local_40 = 4;
  }
  else {
    cVar2 = std::string::empty(asStack_60);
    if (cVar2 == '\0') {
      local_40 = 1;
    }
    else {
      local_40 = 2;
    }
  }
  if (local_81 == '\0') {
LAB_00b16af0:
    bVar1 = false;
  }
  else {
                    /* try { // try from 00b16ae0 to 00b16b1d has its CatchHandler @ 00b16ba6 */
    cVar2 = FUN_00b21596(param_1);
    if (cVar2 != '!') goto LAB_00b16af0;
    bVar1 = true;
  }
  if (bVar1) {
    FUN_00b21658(param_1);
    FUN_00b28d14(local_20,param_1);
                    /* try { // try from 00b16b30 to 00b16b34 has its CatchHandler @ 00b16b95 */
    FUN_00b18c50(auStack_58,local_20);
    std::string::~string(local_20);
    local_40 = 3;
  }
LAB_00b16b48:
                    /* try { // try from 00b16b60 to 00b16b64 has its CatchHandler @ 00b16ba6 */
  FUN_00b18ccc(param_1 + 0x80,local_78);
  FUN_00b0eed8(local_78);
  return;
}


// ==== entry=00b16bca name=FUN_00b16bca size=419 ====

void FUN_00b16bca(long param_1)

{
  char cVar1;
  undefined1 local_a8 [24];
  string asStack_90 [44];
  undefined1 local_64 [12];
  undefined8 local_58;
  undefined1 local_50;
  int local_4c;
  undefined1 local_47;
  undefined4 local_44;
  undefined1 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined1 local_30;
  string local_28 [8];
  string local_20 [16];
  
  std::string::string(local_28);
  FUN_00b18b8e(&local_58);
  cVar1 = FUN_00b0edfa(param_1);
  if (cVar1 == '\0') {
    local_58 = FUN_00b18708();
  }
  else {
                    /* try { // try from 00b16c08 to 00b16cb5 has its CatchHandler @ 00b16d88 */
    local_58 = FUN_00b18608();
  }
  local_50 = 0;
  cVar1 = FUN_00b0edfa(param_1);
  if (cVar1 == '\0') {
    local_4c = FUN_00b0cfec(param_1);
    local_4c = local_4c + 1;
  }
  else {
    local_4c = 0;
  }
  local_44 = 2;
  local_47 = 1;
  local_40 = 1;
  local_3c = 0xffffffff;
  local_38 = 1;
  local_34 = 2;
  FUN_00b1a798(param_1);
  local_64 = FUN_00b0d79a(param_1);
  FUN_00b279bd(local_20,param_1,&local_58);
                    /* try { // try from 00b16cc4 to 00b16cc8 has its CatchHandler @ 00b16d63 */
  std::string::operator=(local_28,local_20);
  std::string::~string(local_20);
  *(undefined1 *)(param_1 + 0xd2) = local_30;
  *(undefined1 *)(param_1 + 0xd3) = 0;
                    /* try { // try from 00b16d07 to 00b16d0b has its CatchHandler @ 00b16d88 */
  FUN_00b0ed54(local_a8,0x13,local_64);
                    /* try { // try from 00b16d21 to 00b16d45 has its CatchHandler @ 00b16d74 */
  std::string::operator=(asStack_90,local_28);
  FUN_00b18ccc(param_1 + 0x80,local_a8);
  FUN_00b0eed8(local_a8);
  std::string::~string(local_28);
  return;
}


// ==== entry=00b16dac name=FUN_00b16dac size=628 ====

void FUN_00b16dac(long param_1)

{
  undefined8 uVar1;
  undefined1 local_128 [24];
  string asStack_110 [44];
  undefined1 local_e4 [12];
  undefined1 local_d8 [32];
  undefined1 *local_b8;
  undefined1 local_b0;
  undefined4 local_ac;
  undefined1 local_a7;
  undefined1 local_a6;
  undefined4 local_a4;
  undefined1 local_a0;
  undefined4 local_9c;
  undefined4 local_98;
  string local_80 [8];
  undefined1 local_78 [32];
  undefined1 local_58 [32];
  string local_38 [14];
  char local_2a;
  char local_29;
  
  std::string::string(local_80);
                    /* try { // try from 00b16dd9 to 00b16ddd has its CatchHandler @ 00b17077 */
  local_29 = FUN_00b21596(param_1);
  local_2a = local_29 == '\'';
  FUN_00b18b8e(&local_b8);
  if (local_2a == '\0') {
    FUN_00b26bfc(local_d8,(int)local_29);
  }
  else {
                    /* try { // try from 00b16e0b to 00b16e6f has its CatchHandler @ 00b17012 */
    uVar1 = FUN_00b18808();
    FUN_00b26d2c(local_78,uVar1);
    FUN_00b26bfc(local_58,(int)local_29);
    FUN_00b26e07(local_d8,local_58,local_78);
    FUN_00b0d994(local_58);
    FUN_00b0d994(local_78);
  }
  local_b8 = local_d8;
  local_b0 = 1;
  if (local_2a == '\0') {
    local_a6 = 0x5c;
  }
  else {
    local_a6 = 0x27;
  }
  local_ac = 0;
  local_a4 = 2;
  local_a7 = 1;
  local_a0 = 0;
  local_9c = 0;
  local_98 = 2;
                    /* try { // try from 00b16efe to 00b16f55 has its CatchHandler @ 00b17063 */
  FUN_00b1a798(param_1);
  local_e4 = FUN_00b0d79a(param_1);
  FUN_00b21658(param_1);
  FUN_00b279bd(local_38,param_1,&local_b8);
                    /* try { // try from 00b16f64 to 00b16f68 has its CatchHandler @ 00b1703e */
  std::string::operator=(local_80,local_38);
  std::string::~string(local_38);
  *(undefined1 *)(param_1 + 0xd2) = 0;
  *(undefined1 *)(param_1 + 0xd3) = 1;
                    /* try { // try from 00b16fa7 to 00b16fab has its CatchHandler @ 00b17063 */
  FUN_00b0ed54(local_128,0x14,local_e4);
                    /* try { // try from 00b16fc1 to 00b16fe5 has its CatchHandler @ 00b1704f */
  std::string::operator=(asStack_110,local_80);
  FUN_00b18ccc(param_1 + 0x80,local_128);
  FUN_00b0eed8(local_128);
  FUN_00b0d994(local_d8);
  std::string::~string(local_80);
  return;
}


// ==== entry=00b170a0 name=FUN_00b170a0 size=1169 ====

void FUN_00b170a0(long param_1)

{
  bool bVar1;
  char cVar2;
  int iVar3;
  undefined8 uVar4;
  undefined1 local_108 [24];
  string asStack_f0 [44];
  undefined1 local_c4 [12];
  undefined1 local_b8 [12];
  int local_ac;
  undefined1 local_a8;
  undefined1 local_a7;
  uint local_a4;
  undefined1 local_a0;
  undefined4 local_9c;
  undefined4 local_94;
  string local_88 [8];
  string local_80 [11];
  allocator local_75;
  undefined1 local_74 [12];
  undefined1 local_68 [32];
  string local_48 [11];
  allocator local_3d;
  undefined1 local_3c [12];
  string local_30 [11];
  char local_25;
  int local_24;
  char local_1d;
  int local_1c;
  
  std::string::string(local_88);
  FUN_00b18b8e(local_b8);
  local_ac = 1;
  local_a8 = 1;
  local_c4 = FUN_00b0d79a(param_1);
                    /* try { // try from 00b17112 to 00b171bd has its CatchHandler @ 00b175b5 */
  local_1d = FUN_00b21658(param_1);
  local_a4 = (uint)(local_1d == '>');
  local_9c = 0;
  uVar4 = FUN_00b189e6();
  local_24 = FUN_00b0d95a(uVar4,param_1);
  for (local_1c = 0; local_1c < local_24; local_1c = local_1c + 1) {
    local_25 = FUN_00b21658(param_1);
    if (local_25 == '+') {
      local_9c = 1;
    }
    else if (local_25 == '-') {
      local_9c = 0xffffffff;
    }
    else {
      uVar4 = FUN_00b17eb6();
      cVar2 = FUN_00b17d56(uVar4,(int)local_25);
      if (cVar2 != '\0') {
        if (local_25 == '0') {
          uVar4 = __cxa_allocate_exception(0x28);
          std::allocator<char>::allocator();
                    /* try { // try from 00b171f9 to 00b171fd has its CatchHandler @ 00b17536 */
          std::string::string(local_80,"cannot set zero indentation for a block scalar",&local_75);
          local_74 = FUN_00b0d79a(param_1);
                    /* try { // try from 00b1722a to 00b1722e has its CatchHandler @ 00b17525 */
          FUN_00b09fc4(uVar4,local_74,local_80);
          std::string::~string(local_80);
          std::allocator<char>::~allocator((allocator<char> *)&local_75);
                    /* WARNING: Subroutine does not return */
                    /* try { // try from 00b17254 to 00b172b5 has its CatchHandler @ 00b175b5 */
          __cxa_throw(uVar4,&PTR_PTR_00d39ce8,FUN_00b009e6);
        }
        local_ac = local_25 + -0x30;
        local_a8 = 0;
      }
    }
  }
  while( true ) {
    uVar4 = FUN_00b0db18();
    cVar2 = FUN_00b0d930(uVar4,param_1);
    if (cVar2 == '\0') break;
    FUN_00b2174c(param_1,1);
  }
  FUN_00b0e6c4(local_68);
                    /* try { // try from 00b172c7 to 00b172cb has its CatchHandler @ 00b17552 */
  cVar2 = FUN_00b0d930(local_68,param_1);
  FUN_00b0d994(local_68);
  if (cVar2 != '\0') {
    do {
                    /* try { // try from 00b172e8 to 00b17364 has its CatchHandler @ 00b175b5 */
      cVar2 = FUN_00b215d8(param_1);
      if (cVar2 == '\0') {
LAB_00b17319:
        bVar1 = false;
      }
      else {
        uVar4 = FUN_00b0dbb2();
        cVar2 = FUN_00b0d930(uVar4,param_1);
        if (cVar2 == '\x01') goto LAB_00b17319;
        bVar1 = true;
      }
      if (!bVar1) break;
      FUN_00b2174c(param_1,1);
    } while( true );
  }
  cVar2 = FUN_00b215d8(param_1);
  if (cVar2 != '\0') {
    uVar4 = FUN_00b0dbb2();
    cVar2 = FUN_00b0d930(uVar4,param_1);
    if (cVar2 != '\x01') {
      bVar1 = true;
      goto LAB_00b17378;
    }
  }
  bVar1 = false;
LAB_00b17378:
  if (bVar1) {
    uVar4 = __cxa_allocate_exception(0x28);
    std::allocator<char>::allocator();
                    /* try { // try from 00b173a9 to 00b173ad has its CatchHandler @ 00b17574 */
    std::string::string(local_48,"unexpected character in block scalar",&local_3d);
    local_3c = FUN_00b0d79a(param_1);
                    /* try { // try from 00b173da to 00b173de has its CatchHandler @ 00b17563 */
    FUN_00b09fc4(uVar4,local_3c,local_48);
    std::string::~string(local_48);
    std::allocator<char>::~allocator((allocator<char> *)&local_3d);
                    /* WARNING: Subroutine does not return */
                    /* try { // try from 00b17404 to 00b17474 has its CatchHandler @ 00b175b5 */
    __cxa_throw(uVar4,&PTR_PTR_00d39ce8,FUN_00b009e6);
  }
  iVar3 = FUN_00b0cfec(param_1);
  if (-1 < iVar3) {
    iVar3 = FUN_00b0cfec(param_1);
    local_ac = local_ac + iVar3;
  }
  local_a7 = 0;
  local_a0 = 0;
  local_94 = 2;
  FUN_00b279bd(local_30,param_1,local_b8);
                    /* try { // try from 00b17483 to 00b17487 has its CatchHandler @ 00b17590 */
  std::string::operator=(local_88,local_30);
  std::string::~string(local_30);
  *(undefined1 *)(param_1 + 0xd2) = 1;
  *(undefined1 *)(param_1 + 0xd3) = 0;
                    /* try { // try from 00b174c6 to 00b174ca has its CatchHandler @ 00b175b5 */
  FUN_00b0ed54(local_108,0x14,local_c4);
                    /* try { // try from 00b174e0 to 00b17504 has its CatchHandler @ 00b175a1 */
  std::string::operator=(asStack_f0,local_88);
  FUN_00b18ccc(param_1 + 0x80,local_108);
  FUN_00b0eed8(local_108);
  std::string::~string(local_88);
  return;
}


// ==== entry=00b175db name=FUN_00b175db size=48 ====

void FUN_00b175db(void)

{
  string *this;
  
  this = (string *)&DAT_011c30e0;
  while (this != (string *)&DAT_011c3040) {
    this = this + -8;
    std::string::~string(this);
  }
  return;
}


// ==== entry=00b1760b name=FUN_00b1760b size=1151 ====

void FUN_00b1760b(int param_1,int param_2)

{
  allocator local_3c;
  allocator local_3b;
  allocator local_3a;
  allocator local_39;
  allocator local_38;
  allocator local_37;
  allocator local_36;
  allocator local_35;
  allocator local_34;
  allocator local_33;
  allocator local_32;
  allocator local_31;
  allocator local_30;
  allocator local_2f;
  allocator local_2e;
  allocator local_2d;
  allocator local_2c;
  allocator local_2b;
  allocator local_2a;
  allocator local_29 [9];
  
  if ((param_1 == 1) && (param_2 == 0xffff)) {
    std::ios_base::Init::Init((Init *)&DAT_011c3020);
    __cxa_atexit(std::ios_base::Init::~Init,&DAT_011c3020,&DAT_00c89008);
    std::allocator<char>::allocator();
                    /* try { // try from 00b17679 to 00b1767d has its CatchHandler @ 00b17a7f */
    std::string::string((string *)&DAT_011c3040,"DIRECTIVE",&local_3c);
    std::allocator<char>::~allocator((allocator<char> *)&local_3c);
    std::allocator<char>::allocator();
                    /* try { // try from 00b176ad to 00b176b1 has its CatchHandler @ 00b17a93 */
    std::string::string((string *)&DAT_011c3048,"DOC_START",&local_3b);
    std::allocator<char>::~allocator((allocator<char> *)&local_3b);
    std::allocator<char>::allocator();
                    /* try { // try from 00b176e1 to 00b176e5 has its CatchHandler @ 00b17aa7 */
    std::string::string((string *)&DAT_011c3050,"DOC_END",&local_3a);
    std::allocator<char>::~allocator((allocator<char> *)&local_3a);
    std::allocator<char>::allocator();
                    /* try { // try from 00b17715 to 00b17719 has its CatchHandler @ 00b17abb */
    std::string::string((string *)&DAT_011c3058,"BLOCK_SEQ_START",&local_39);
    std::allocator<char>::~allocator((allocator<char> *)&local_39);
    std::allocator<char>::allocator();
                    /* try { // try from 00b17749 to 00b1774d has its CatchHandler @ 00b17acf */
    std::string::string((string *)&DAT_011c3060,"BLOCK_MAP_START",&local_38);
    std::allocator<char>::~allocator((allocator<char> *)&local_38);
    std::allocator<char>::allocator();
                    /* try { // try from 00b1777d to 00b17781 has its CatchHandler @ 00b17ae3 */
    std::string::string((string *)&DAT_011c3068,"BLOCK_SEQ_END",&local_37);
    std::allocator<char>::~allocator((allocator<char> *)&local_37);
    std::allocator<char>::allocator();
                    /* try { // try from 00b177b1 to 00b177b5 has its CatchHandler @ 00b17af7 */
    std::string::string((string *)&DAT_011c3070,"BLOCK_MAP_END",&local_36);
    std::allocator<char>::~allocator((allocator<char> *)&local_36);
    std::allocator<char>::allocator();
                    /* try { // try from 00b177e5 to 00b177e9 has its CatchHandler @ 00b17b0b */
    std::string::string((string *)&DAT_011c3078,"BLOCK_ENTRY",&local_35);
    std::allocator<char>::~allocator((allocator<char> *)&local_35);
    std::allocator<char>::allocator();
                    /* try { // try from 00b17819 to 00b1781d has its CatchHandler @ 00b17b1f */
    std::string::string((string *)&DAT_011c3080,"FLOW_SEQ_START",&local_34);
    std::allocator<char>::~allocator((allocator<char> *)&local_34);
    std::allocator<char>::allocator();
                    /* try { // try from 00b1784d to 00b17851 has its CatchHandler @ 00b17b33 */
    std::string::string((string *)&DAT_011c3088,"FLOW_MAP_START",&local_33);
    std::allocator<char>::~allocator((allocator<char> *)&local_33);
    std::allocator<char>::allocator();
                    /* try { // try from 00b17881 to 00b17885 has its CatchHandler @ 00b17b47 */
    std::string::string((string *)&DAT_011c3090,"FLOW_SEQ_END",&local_32);
    std::allocator<char>::~allocator((allocator<char> *)&local_32);
    std::allocator<char>::allocator();
                    /* try { // try from 00b178b5 to 00b178b9 has its CatchHandler @ 00b17b5b */
    std::string::string((string *)&DAT_011c3098,"FLOW_MAP_END",&local_31);
    std::allocator<char>::~allocator((allocator<char> *)&local_31);
    std::allocator<char>::allocator();
                    /* try { // try from 00b178e9 to 00b178ed has its CatchHandler @ 00b17b6f */
    std::string::string((string *)&DAT_011c30a0,"FLOW_MAP_COMPACT",&local_30);
    std::allocator<char>::~allocator((allocator<char> *)&local_30);
    std::allocator<char>::allocator();
                    /* try { // try from 00b1791d to 00b17921 has its CatchHandler @ 00b17b80 */
    std::string::string((string *)&DAT_011c30a8,"FLOW_ENTRY",&local_2f);
    std::allocator<char>::~allocator((allocator<char> *)&local_2f);
    std::allocator<char>::allocator();
                    /* try { // try from 00b17951 to 00b17955 has its CatchHandler @ 00b17b91 */
    std::string::string((string *)&DAT_011c30b0,"KEY",&local_2e);
    std::allocator<char>::~allocator((allocator<char> *)&local_2e);
    std::allocator<char>::allocator();
                    /* try { // try from 00b17985 to 00b17989 has its CatchHandler @ 00b17ba2 */
    std::string::string((string *)&DAT_011c30b8,"VALUE",&local_2d);
    std::allocator<char>::~allocator((allocator<char> *)&local_2d);
    std::allocator<char>::allocator();
                    /* try { // try from 00b179b9 to 00b179bd has its CatchHandler @ 00b17bb3 */
    std::string::string((string *)&DAT_011c30c0,"ANCHOR",&local_2c);
    std::allocator<char>::~allocator((allocator<char> *)&local_2c);
    std::allocator<char>::allocator();
                    /* try { // try from 00b179ed to 00b179f1 has its CatchHandler @ 00b17bc4 */
    std::string::string((string *)&DAT_011c30c8,"ALIAS",&local_2b);
    std::allocator<char>::~allocator((allocator<char> *)&local_2b);
    std::allocator<char>::allocator();
                    /* try { // try from 00b17a21 to 00b17a25 has its CatchHandler @ 00b17bd5 */
    std::string::string((string *)&DAT_011c30d0,"TAG",&local_2a);
    std::allocator<char>::~allocator((allocator<char> *)&local_2a);
    std::allocator<char>::allocator();
                    /* try { // try from 00b17a55 to 00b17a59 has its CatchHandler @ 00b17be6 */
    std::string::string((string *)&DAT_011c30d8,"SCALAR",local_29);
    std::allocator<char>::~allocator((allocator<char> *)local_29);
    __cxa_atexit(FUN_00b175db,0,&DAT_00c89008);
  }
  return;
}


// ==== entry=00b17c34 orig=FUN_00b17c34 size=21 name=_INIT_172 ====

void _INIT_172(void)

{
  FUN_00b1760b(1,0xffff);
  return;
}


// ==== entry=00b17c4a name=FUN_00b17c4a size=54 ====

void FUN_00b17c4a(undefined8 *param_1,undefined8 param_2,undefined8 param_3)

{
  *param_1 = param_2;
  param_1[1] = param_3;
  param_1[2] = 0;
  return;
}


// ==== entry=00b17c80 name=FUN_00b17c80 size=32 ====

undefined8 FUN_00b17c80(long param_1)

{
  return CONCAT71((int7)(*(ulong *)(param_1 + 8) >> 8),
                  *(ulong *)(param_1 + 0x10) < *(ulong *)(param_1 + 8));
}


// ==== entry=00b17ca0 name=FUN_00b17ca0 size=42 ====

undefined1 FUN_00b17ca0(long *param_1,long param_2)

{
  return *(undefined1 *)(param_2 + param_1[2] + *param_1);
}


// ==== entry=00b17cca name=FUN_00b17cca size=29 ====

uint FUN_00b17cca(undefined8 param_1)

{
  uint uVar1;
  
  uVar1 = FUN_00b17c80(param_1);
  return uVar1 ^ 1;
}


// ==== entry=00b17ce8 name=FUN_00b17ce8 size=109 ====

undefined8 * FUN_00b17ce8(undefined8 *param_1,undefined8 *param_2,int param_3)

{
  undefined8 uVar1;
  
  uVar1 = param_2[1];
  *param_1 = *param_2;
  param_1[1] = uVar1;
  param_1[2] = param_2[2];
  if (param_3 + (int)param_1[2] < 0) {
    param_1[2] = 0;
  }
  else {
    param_1[2] = param_1[2] + (long)param_3;
  }
  return param_1;
}


// ==== entry=00b17d56 name=FUN_00b17d56 size=93 ====

undefined4 FUN_00b17d56(undefined8 param_1,char param_2)

{
  undefined4 uVar1;
  string local_20 [16];
  
  std::string::string(local_20);
                    /* try { // try from 00b17d81 to 00b17d98 has its CatchHandler @ 00b17dac */
  std::string::operator+=(local_20,param_2);
  uVar1 = FUN_00b17dce(param_1,local_20);
  std::string::~string(local_20);
  return uVar1;
}


// ==== entry=00b17dce name=FUN_00b17dce size=42 ====

uint FUN_00b17dce(undefined8 param_1,undefined8 param_2)

{
  uint uVar1;
  
  uVar1 = FUN_00b17df8(param_1,param_2);
  return ~uVar1 >> 0x1f;
}


// ==== entry=00b17df8 name=FUN_00b17df8 size=92 ====

void FUN_00b17df8(undefined8 param_1,string *param_2)

{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined1 local_38 [40];
  
  uVar1 = std::string::size(param_2);
  uVar2 = std::string::c_str(param_2);
  FUN_00b17c4a(local_38,uVar2,uVar1);
  FUN_00b18c0c(param_1,local_38);
  return;
}


// ==== entry=00b17e54 name=FUN_00b17e54 size=51 ====

undefined8 FUN_00b17e54(int *param_1,undefined8 param_2)

{
  undefined8 uVar1;
  
  if (*param_1 - 1U < 2) {
    uVar1 = FUN_00b17c80(param_2);
  }
  else {
    uVar1 = 1;
  }
  return uVar1;
}


// ==== entry=00b17e88 name=FUN_00b17e88 size=46 ====

undefined8 FUN_00b17e88(undefined8 param_1,undefined8 param_2)

{
  char cVar1;
  undefined8 uVar2;
  
  cVar1 = FUN_00b17cca(param_2);
  if (cVar1 == '\0') {
    uVar2 = 0xffffffff;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}


// ==== entry=00b17eb6 name=FUN_00b17eb6 size=110 ====

undefined * FUN_00b17eb6(void)

{
  int iVar1;
  
  if (DAT_011c3100 == '\0') {
    iVar1 = __cxa_guard_acquire(&DAT_011c3100);
    if (iVar1 != 0) {
                    /* try { // try from 00b17ef5 to 00b17ef9 has its CatchHandler @ 00b17f1f */
      FUN_00b26c3e(&DAT_011c30e0,0x30,0x39);
      __cxa_guard_release(&DAT_011c3100);
      __cxa_atexit(FUN_00b0d994,&DAT_011c30e0,&DAT_00c89008);
    }
  }
  return &DAT_011c30e0;
}


// ==== entry=00b17f41 name=FUN_00b17f41 size=261 ====

undefined * FUN_00b17f41(void)

{
  int iVar1;
  undefined8 uVar2;
  undefined1 local_68 [32];
  undefined1 local_48 [32];
  string local_28 [15];
  allocator local_19;
  
  if (DAT_011c3140 == '\0') {
    iVar1 = __cxa_guard_acquire(&DAT_011c3140);
    if (iVar1 != 0) {
                    /* try { // try from 00b17f7d to 00b17f81 has its CatchHandler @ 00b18081 */
      uVar2 = FUN_00b0dd0a();
      std::allocator<char>::allocator();
                    /* try { // try from 00b17fa1 to 00b17fa5 has its CatchHandler @ 00b18070 */
      std::string::string(local_28,"[]{},",&local_19);
                    /* try { // try from 00b17fb9 to 00b17fbd has its CatchHandler @ 00b1805f */
      FUN_00b26c88(local_48,local_28,3);
                    /* try { // try from 00b17fcf to 00b17fd3 has its CatchHandler @ 00b1804e */
      FUN_00b26d8c(local_68,local_48,uVar2);
                    /* try { // try from 00b17fe3 to 00b17fe7 has its CatchHandler @ 00b1803d */
      FUN_00b26d2c(&DAT_011c3120,local_68);
      __cxa_guard_release(&DAT_011c3140);
      __cxa_atexit(FUN_00b0d994,&DAT_011c3120,&DAT_00c89008);
      FUN_00b0d994(local_68);
      FUN_00b0d994(local_48);
      std::string::~string(local_28);
      std::allocator<char>::~allocator((allocator<char> *)&local_19);
    }
  }
  return &DAT_011c3120;
}


// ==== entry=00b180a7 name=FUN_00b180a7 size=230 ====

undefined * FUN_00b180a7(void)

{
  int iVar1;
  undefined8 uVar2;
  undefined1 local_48 [32];
  string local_28 [15];
  allocator local_19;
  
  if (DAT_011c3180 == '\0') {
    iVar1 = __cxa_guard_acquire(&DAT_011c3180);
    if (iVar1 != 0) {
                    /* try { // try from 00b180e3 to 00b180e7 has its CatchHandler @ 00b181b7 */
      uVar2 = FUN_00b0dd0a();
      std::allocator<char>::allocator();
                    /* try { // try from 00b18107 to 00b1810b has its CatchHandler @ 00b181a6 */
      std::string::string(local_28,"?:,]}%@`",&local_19);
                    /* try { // try from 00b1811f to 00b18123 has its CatchHandler @ 00b18195 */
      FUN_00b26c88(local_48,local_28,3);
                    /* try { // try from 00b18136 to 00b1813a has its CatchHandler @ 00b18184 */
      FUN_00b26d8c(&DAT_011c3160,local_48,uVar2);
      __cxa_guard_release(&DAT_011c3180);
      __cxa_atexit(FUN_00b0d994,&DAT_011c3160,&DAT_00c89008);
      FUN_00b0d994(local_48);
      std::string::~string(local_28);
      std::allocator<char>::~allocator((allocator<char> *)&local_19);
    }
  }
  return &DAT_011c3160;
}


// ==== entry=00b181dd name=FUN_00b181dd size=222 ====

undefined * FUN_00b181dd(void)

{
  int iVar1;
  undefined8 uVar2;
  undefined1 local_78 [32];
  undefined1 local_58 [32];
  undefined1 local_38 [32];
  
  if (DAT_011c31c0 == '\0') {
    iVar1 = __cxa_guard_acquire(&DAT_011c31c0);
    if (iVar1 != 0) {
                    /* try { // try from 00b18220 to 00b18224 has its CatchHandler @ 00b182e5 */
      FUN_00b26bdc(local_58);
                    /* try { // try from 00b18225 to 00b1823f has its CatchHandler @ 00b182d4 */
      uVar2 = FUN_00b0dd0a();
      FUN_00b26d8c(local_78,uVar2,local_58);
                    /* try { // try from 00b1824c to 00b18250 has its CatchHandler @ 00b182c3 */
      FUN_00b26bfc(local_38,0x3a);
                    /* try { // try from 00b18264 to 00b18268 has its CatchHandler @ 00b182b2 */
      FUN_00b26e82(&DAT_011c31a0,local_38,local_78);
      __cxa_guard_release(&DAT_011c31c0);
      __cxa_atexit(FUN_00b0d994,&DAT_011c31a0,&DAT_00c89008);
      FUN_00b0d994(local_38);
      FUN_00b0d994(local_78);
      FUN_00b0d994(local_58);
    }
  }
  return &DAT_011c31a0;
}


// ==== entry=00b1830b name=FUN_00b1830b size=541 ====

undefined * FUN_00b1830b(void)

{
  int iVar1;
  undefined8 uVar2;
  undefined1 local_118 [32];
  string local_f8 [15];
  allocator local_e9;
  undefined1 local_e8 [32];
  undefined1 local_c8 [32];
  undefined1 local_a8 [32];
  string local_88 [15];
  allocator local_79;
  undefined1 local_78 [32];
  undefined1 local_58 [32];
  undefined1 local_38 [32];
  
  if (DAT_011c3200 == '\0') {
    iVar1 = __cxa_guard_acquire(&DAT_011c3200);
    if (iVar1 != 0) {
      std::allocator<char>::allocator();
                    /* try { // try from 00b1836f to 00b18373 has its CatchHandler @ 00b185d0 */
      std::string::string(local_f8,",?[]{}",&local_e9);
                    /* try { // try from 00b1838d to 00b18391 has its CatchHandler @ 00b185bc */
      FUN_00b26c88(local_118,local_f8,3);
      std::allocator<char>::allocator();
                    /* try { // try from 00b183ae to 00b183b2 has its CatchHandler @ 00b1859c */
      std::string::string(local_88,",]}",&local_79);
                    /* try { // try from 00b183c9 to 00b183cd has its CatchHandler @ 00b1858b */
      FUN_00b26c88(local_a8,local_88,3);
                    /* try { // try from 00b183d5 to 00b183d9 has its CatchHandler @ 00b18577 */
      FUN_00b26bdc(local_58);
                    /* try { // try from 00b183da to 00b183f4 has its CatchHandler @ 00b18566 */
      uVar2 = FUN_00b0dd0a();
      FUN_00b26d8c(local_78,uVar2,local_58);
                    /* try { // try from 00b1840d to 00b18411 has its CatchHandler @ 00b18555 */
      FUN_00b26d8c(local_c8,local_78,local_a8);
                    /* try { // try from 00b1841e to 00b18422 has its CatchHandler @ 00b18541 */
      FUN_00b26bfc(local_38,0x3a);
                    /* try { // try from 00b1843b to 00b1843f has its CatchHandler @ 00b18530 */
      FUN_00b26e82(local_e8,local_38,local_c8);
                    /* try { // try from 00b18459 to 00b1845d has its CatchHandler @ 00b1851c */
      FUN_00b26d8c(&DAT_011c31e0,local_e8,local_118);
      __cxa_guard_release(&DAT_011c3200);
      __cxa_atexit(FUN_00b0d994,&DAT_011c31e0,&DAT_00c89008);
      FUN_00b0d994(local_e8);
      FUN_00b0d994(local_38);
      FUN_00b0d994(local_c8);
      FUN_00b0d994(local_78);
      FUN_00b0d994(local_58);
      FUN_00b0d994(local_a8);
      std::string::~string(local_88);
      std::allocator<char>::~allocator((allocator<char> *)&local_79);
      FUN_00b0d994(local_118);
      std::string::~string(local_f8);
      std::allocator<char>::~allocator((allocator<char> *)&local_e9);
    }
  }
  return &DAT_011c31e0;
}


// ==== entry=00b18608 name=FUN_00b18608 size=193 ====

undefined * FUN_00b18608(void)

{
  int iVar1;
  undefined8 uVar2;
  undefined1 local_58 [32];
  undefined1 local_38 [32];
  
  if (DAT_011c3240 == '\0') {
    iVar1 = __cxa_guard_acquire(&DAT_011c3240);
    if (iVar1 != 0) {
                    /* try { // try from 00b18647 to 00b1864b has its CatchHandler @ 00b186e2 */
      FUN_00b0e6c4(local_38);
                    /* try { // try from 00b1864c to 00b18666 has its CatchHandler @ 00b186d1 */
      uVar2 = FUN_00b0dd0a();
      FUN_00b26e82(local_58,uVar2,local_38);
                    /* try { // try from 00b18667 to 00b18682 has its CatchHandler @ 00b186c0 */
      uVar2 = FUN_00b1830b();
      FUN_00b26d8c(&DAT_011c3220,uVar2,local_58);
      __cxa_guard_release(&DAT_011c3240);
      __cxa_atexit(FUN_00b0d994,&DAT_011c3220,&DAT_00c89008);
      FUN_00b0d994(local_58);
      FUN_00b0d994(local_38);
    }
  }
  return &DAT_011c3220;
}


// ==== entry=00b18708 name=FUN_00b18708 size=193 ====

undefined * FUN_00b18708(void)

{
  int iVar1;
  undefined8 uVar2;
  undefined1 local_58 [32];
  undefined1 local_38 [32];
  
  if (DAT_011c3280 == '\0') {
    iVar1 = __cxa_guard_acquire(&DAT_011c3280);
    if (iVar1 != 0) {
                    /* try { // try from 00b18747 to 00b1874b has its CatchHandler @ 00b187e2 */
      FUN_00b0e6c4(local_38);
                    /* try { // try from 00b1874c to 00b18766 has its CatchHandler @ 00b187d1 */
      uVar2 = FUN_00b0dd0a();
      FUN_00b26e82(local_58,uVar2,local_38);
                    /* try { // try from 00b18767 to 00b18782 has its CatchHandler @ 00b187c0 */
      uVar2 = FUN_00b181dd();
      FUN_00b26d8c(&DAT_011c3260,uVar2,local_58);
      __cxa_guard_release(&DAT_011c3280);
      __cxa_atexit(FUN_00b0d994,&DAT_011c3260,&DAT_00c89008);
      FUN_00b0d994(local_58);
      FUN_00b0d994(local_38);
    }
  }
  return &DAT_011c3260;
}


// ==== entry=00b18808 name=FUN_00b18808 size=181 ====

undefined * FUN_00b18808(void)

{
  int iVar1;
  string local_28 [15];
  allocator local_19;
  
  if (DAT_011c32c0 == '\0') {
    iVar1 = __cxa_guard_acquire(&DAT_011c32c0);
    if (iVar1 != 0) {
      std::allocator<char>::allocator();
                    /* try { // try from 00b1885c to 00b18860 has its CatchHandler @ 00b188c5 */
      std::string::string(local_28,"\'\'",&local_19);
                    /* try { // try from 00b18872 to 00b18876 has its CatchHandler @ 00b188b4 */
      FUN_00b26c88(&DAT_011c32a0,local_28,6);
      __cxa_guard_release(&DAT_011c32c0);
      __cxa_atexit(FUN_00b0d994,&DAT_011c32a0,&DAT_00c89008);
      std::string::~string(local_28);
      std::allocator<char>::~allocator((allocator<char> *)&local_19);
    }
  }
  return &DAT_011c32a0;
}


// ==== entry=00b188f7 name=FUN_00b188f7 size=181 ====

undefined * FUN_00b188f7(void)

{
  int iVar1;
  string local_28 [15];
  allocator local_19;
  
  if (DAT_011c3300 == '\0') {
    iVar1 = __cxa_guard_acquire(&DAT_011c3300);
    if (iVar1 != 0) {
      std::allocator<char>::allocator();
                    /* try { // try from 00b1894b to 00b1894f has its CatchHandler @ 00b189b4 */
      std::string::string(local_28,"+-",&local_19);
                    /* try { // try from 00b18961 to 00b18965 has its CatchHandler @ 00b189a3 */
      FUN_00b26c88(&DAT_011c32e0,local_28,3);
      __cxa_guard_release(&DAT_011c3300);
      __cxa_atexit(FUN_00b0d994,&DAT_011c32e0,&DAT_00c89008);
      std::string::~string(local_28);
      std::allocator<char>::~allocator((allocator<char> *)&local_19);
    }
  }
  return &DAT_011c32e0;
}


// ==== entry=00b189e6 name=FUN_00b189e6 size=323 ====

undefined * FUN_00b189e6(void)

{
  int iVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined1 local_a8 [32];
  undefined1 local_88 [32];
  undefined1 local_68 [32];
  undefined1 local_48 [32];
  
  if (DAT_011c3340 == '\0') {
    iVar1 = __cxa_guard_acquire(&DAT_011c3340);
    if (iVar1 != 0) {
                    /* try { // try from 00b18a26 to 00b18a57 has its CatchHandler @ 00b18b63 */
      uVar2 = FUN_00b17eb6();
      uVar3 = FUN_00b188f7();
      uVar4 = FUN_00b188f7();
      uVar5 = FUN_00b17eb6();
      FUN_00b26e82(local_68,uVar5,uVar4);
                    /* try { // try from 00b18a58 to 00b18a79 has its CatchHandler @ 00b18b52 */
      uVar4 = FUN_00b17eb6();
      uVar5 = FUN_00b188f7();
      FUN_00b26e82(local_48,uVar5,uVar4);
                    /* try { // try from 00b18a8c to 00b18a90 has its CatchHandler @ 00b18b41 */
      FUN_00b26d8c(local_88,local_48,local_68);
                    /* try { // try from 00b18aa5 to 00b18aa9 has its CatchHandler @ 00b18b30 */
      FUN_00b26d8c(local_a8,local_88,uVar3);
                    /* try { // try from 00b18abf to 00b18ac3 has its CatchHandler @ 00b18b1c */
      FUN_00b26d8c(&DAT_011c3320,local_a8,uVar2);
      __cxa_guard_release(&DAT_011c3340);
      __cxa_atexit(FUN_00b0d994,&DAT_011c3320,&DAT_00c89008);
      FUN_00b0d994(local_a8);
      FUN_00b0d994(local_88);
      FUN_00b0d994(local_48);
      FUN_00b0d994(local_68);
    }
  }
  return &DAT_011c3320;
}


// ==== entry=00b18b8e name=FUN_00b18b8e size=125 ====

void FUN_00b18b8e(undefined8 *param_1)

{
  *param_1 = 0;
  *(undefined1 *)(param_1 + 1) = 0;
  *(undefined4 *)((long)param_1 + 0xc) = 0;
  *(undefined1 *)(param_1 + 2) = 0;
  *(undefined1 *)((long)param_1 + 0x11) = 0;
  *(undefined1 *)((long)param_1 + 0x12) = 0;
  *(undefined4 *)((long)param_1 + 0x14) = 0;
  *(undefined1 *)(param_1 + 3) = 0;
  *(undefined4 *)((long)param_1 + 0x1c) = 0;
  *(undefined4 *)(param_1 + 4) = 0;
  *(undefined4 *)((long)param_1 + 0x24) = 0;
  *(undefined1 *)(param_1 + 5) = 0;
  return;
}


// ==== entry=00b18c0c name=FUN_00b18c0c size=67 ====

undefined8 FUN_00b18c0c(undefined8 param_1,undefined8 param_2)

{
  char cVar1;
  undefined8 uVar2;
  
  cVar1 = FUN_00b17e54(param_1,param_2);
  if (cVar1 == '\0') {
    uVar2 = 0xffffffff;
  }
  else {
    uVar2 = FUN_00b18d4e(param_1,param_2);
  }
  return uVar2;
}


// ==== entry=00b18c50 name=FUN_00b18c50 size=123 ====

void FUN_00b18c50(long param_1,undefined8 param_2)

{
  undefined8 uVar1;
  
  if (*(long *)(param_1 + 8) == *(long *)(param_1 + 0x10)) {
    uVar1 = FUN_00b18e50(param_1);
    FUN_009e1110(param_1,uVar1,param_2);
  }
  else {
    FUN_00b18e16(param_1,*(undefined8 *)(param_1 + 8),param_2);
    *(long *)(param_1 + 8) = *(long *)(param_1 + 8) + 8;
  }
  return;
}


// ==== entry=00b18ccc name=FUN_00b18ccc size=38 ====

void FUN_00b18ccc(undefined8 param_1,undefined8 param_2)

{
  FUN_00b18e7a(param_1,param_2);
  return;
}


// ==== entry=00b18cf2 name=FUN_00b18cf2 size=38 ====

void FUN_00b18cf2(undefined8 param_1,undefined8 param_2)

{
  FUN_00b18eea(param_1,param_2);
  return;
}


// ==== entry=00b18d18 name=FUN_00b18d18 size=26 ====

void FUN_00b18d18(undefined8 param_1)

{
  FUN_00b18f5a(param_1);
  return;
}


// ==== entry=00b18d32 name=FUN_00b18d32 size=27 ====

void FUN_00b18d32(undefined8 param_1)

{
  FUN_00b18f94(param_1);
  return;
}


// ==== entry=00b18d4e name=FUN_00b18d4e size=200 ====

undefined8 FUN_00b18d4e(undefined4 *param_1,undefined8 param_2)

{
  undefined8 uVar1;
  
  switch(*param_1) {
  case 0:
    uVar1 = FUN_00b17e88(param_1,param_2);
    break;
  case 1:
    uVar1 = FUN_00b18ff2(param_1,param_2);
    break;
  case 2:
    uVar1 = FUN_00b19034(param_1,param_2);
    break;
  case 3:
    uVar1 = FUN_00b190a2(param_1,param_2);
    break;
  case 4:
    uVar1 = FUN_00b1913c(param_1,param_2);
    break;
  case 5:
    uVar1 = FUN_00b191c8(param_1,param_2);
    break;
  case 6:
    uVar1 = FUN_00b19232(param_1,param_2);
    break;
  default:
    uVar1 = 0xffffffff;
  }
  return uVar1;
}


// ==== entry=00b18e16 name=FUN_00b18e16 size=57 ====

void FUN_00b18e16(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  undefined8 uVar1;
  
  uVar1 = FUN_00b0be11(param_3);
  FUN_00b192ee(param_1,param_2,uVar1);
  return;
}


// ==== entry=00b18e50 name=FUN_00b18e50 size=41 ====

undefined8 FUN_00b18e50(long param_1)

{
  undefined8 local_10;
  
  FUN_00b1935c(&local_10,param_1 + 8);
  return local_10;
}


// ==== entry=00b18e7a name=FUN_00b18e7a size=112 ====

void FUN_00b18e7a(long param_1,undefined8 param_2)

{
  if (*(long *)(param_1 + 0x30) == *(long *)(param_1 + 0x40) + -0x40) {
    FUN_00b195ae(param_1,param_2);
  }
  else {
    FUN_00b19574(param_1,*(undefined8 *)(param_1 + 0x30),param_2);
    *(long *)(param_1 + 0x30) = *(long *)(param_1 + 0x30) + 0x40;
  }
  return;
}


// ==== entry=00b18eea name=FUN_00b18eea size=112 ====

void FUN_00b18eea(long param_1,undefined8 param_2)

{
  if (*(long *)(param_1 + 0x30) == *(long *)(param_1 + 0x40) + -4) {
    FUN_00b196ce(param_1,param_2);
  }
  else {
    FUN_00b19695(param_1,*(undefined8 *)(param_1 + 0x30),param_2);
    *(long *)(param_1 + 0x30) = *(long *)(param_1 + 0x30) + 4;
  }
  return;
}


// ==== entry=00b18f5a name=FUN_00b18f5a size=58 ====

void FUN_00b18f5a(undefined8 param_1)

{
  undefined1 local_28 [32];
  
  FUN_00b1008c(local_28,param_1);
  FUN_00b19768(local_28);
  FUN_00b197ca(local_28);
  return;
}


// ==== entry=00b18f94 name=FUN_00b18f94 size=93 ====

void FUN_00b18f94(long param_1)

{
  if (*(long *)(param_1 + 0x30) == *(long *)(param_1 + 0x38)) {
    FUN_00b19802(param_1);
  }
  else {
    *(long *)(param_1 + 0x30) = *(long *)(param_1 + 0x30) + -4;
    FUN_00b197db(param_1,*(undefined8 *)(param_1 + 0x30));
  }
  return;
}


// ==== entry=00b18ff2 name=FUN_00b18ff2 size=66 ====

undefined8 FUN_00b18ff2(long param_1,undefined8 param_2)

{
  char cVar1;
  undefined8 uVar2;
  
  cVar1 = FUN_00b17ca0(param_2,0);
  if (cVar1 == *(char *)(param_1 + 4)) {
    uVar2 = 1;
  }
  else {
    uVar2 = 0xffffffff;
  }
  return uVar2;
}


// ==== entry=00b19034 name=FUN_00b19034 size=110 ====

undefined8 FUN_00b19034(long param_1,undefined8 param_2)

{
  char cVar1;
  bool bVar2;
  char cVar3;
  undefined8 uVar4;
  
  cVar1 = *(char *)(param_1 + 4);
  cVar3 = FUN_00b17ca0(param_2,0);
  if (cVar1 <= cVar3) {
    cVar1 = *(char *)(param_1 + 5);
    cVar3 = FUN_00b17ca0(param_2,0);
    if (cVar3 <= cVar1) {
      bVar2 = false;
      goto LAB_00b1908b;
    }
  }
  bVar2 = true;
LAB_00b1908b:
  if (bVar2) {
    uVar4 = 0xffffffff;
  }
  else {
    uVar4 = 1;
  }
  return uVar4;
}


// ==== entry=00b190a2 name=FUN_00b190a2 size=153 ====

int FUN_00b190a2(long param_1,undefined8 param_2)

{
  char cVar1;
  undefined8 local_30;
  undefined8 local_28;
  int local_1c;
  undefined8 local_18;
  long local_10;
  
  local_10 = param_1 + 8;
  local_28 = FUN_00b0f8f6(local_10);
  local_30 = FUN_00b0f926(local_10);
  while( true ) {
    cVar1 = FUN_00b117ee(&local_28,&local_30);
    if (cVar1 == '\0') {
      return -1;
    }
    local_18 = FUN_00b1184a(&local_28);
    local_1c = FUN_00b18d4e(local_18,param_2);
    if (-1 < local_1c) break;
    FUN_00b1182a(&local_28);
  }
  return local_1c;
}


// ==== entry=00b1913c name=FUN_00b1913c size=140 ====

int FUN_00b1913c(long param_1,undefined8 param_2)

{
  int iVar1;
  ulong uVar2;
  undefined8 uVar3;
  ulong local_18;
  int local_c;
  
  local_c = -1;
  local_18 = 0;
  while( true ) {
    uVar2 = FUN_00b0f822(param_1 + 8);
    if (uVar2 <= local_18) {
      return local_c;
    }
    uVar3 = FUN_00b1185c(param_1 + 8,local_18);
    iVar1 = FUN_00b18d4e(uVar3,param_2);
    if (iVar1 == -1) break;
    if (local_18 == 0) {
      local_c = iVar1;
    }
    local_18 = local_18 + 1;
  }
  return -1;
}


// ==== entry=00b191c8 name=FUN_00b191c8 size=105 ====

undefined8 FUN_00b191c8(long param_1,undefined8 param_2)

{
  char cVar1;
  int iVar2;
  undefined8 uVar3;
  
  cVar1 = FUN_00b1187c(param_1 + 8);
  if (cVar1 == '\0') {
    uVar3 = FUN_00b1185c(param_1 + 8,0);
    iVar2 = FUN_00b18d4e(uVar3,param_2);
    if (iVar2 < 0) {
      uVar3 = 1;
    }
    else {
      uVar3 = 0xffffffff;
    }
  }
  else {
    uVar3 = 0xffffffff;
  }
  return uVar3;
}


// ==== entry=00b19232 name=FUN_00b19232 size=188 ====

int FUN_00b19232(long param_1,undefined8 param_2)

{
  char cVar1;
  undefined8 local_58;
  undefined8 local_50;
  undefined1 local_48 [36];
  int local_24;
  undefined8 local_20;
  long local_18;
  int local_c;
  
  local_c = 0;
  local_18 = param_1 + 8;
  local_50 = FUN_00b0f8f6(local_18);
  local_58 = FUN_00b0f926(local_18);
  while( true ) {
    cVar1 = FUN_00b117ee(&local_50,&local_58);
    if (cVar1 == '\0') {
      return local_c;
    }
    local_20 = FUN_00b1184a(&local_50);
    FUN_00b17ce8(local_48,param_2,local_c);
    local_24 = FUN_00b18c0c(local_20,local_48);
    if (local_24 == -1) break;
    local_c = local_c + local_24;
    FUN_00b1182a(&local_50);
  }
  return -1;
}


// ==== entry=00b192ee name=FUN_00b192ee size=84 ====

void FUN_00b192ee(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  string *psVar1;
  string *this;
  
  psVar1 = (string *)FUN_00b0be11(param_3);
  this = (string *)FUN_00b00efa(8,param_2);
                    /* try { // try from 00b19330 to 00b19334 has its CatchHandler @ 00b19337 */
  std::string::string(this,psVar1);
  return;
}


// ==== entry=00b1935c name=FUN_00b1935c size=29 ====

void FUN_00b1935c(undefined8 *param_1,undefined8 *param_2)

{
  *param_1 = *param_2;
  return;
}


// ==== entry=00b1937a name=FUN_00b1937a size=201 ====

ulong FUN_00b1937a(undefined8 param_1,ulong param_2,char *param_3)

{
  long lVar1;
  long lVar2;
  long *plVar3;
  ulong uVar4;
  ulong local_38;
  undefined8 local_30;
  undefined8 local_28;
  ulong local_20;
  
  local_38 = param_2;
  local_30 = param_1;
  lVar1 = FUN_00b19880(param_1);
  lVar2 = FUN_00b0a382(local_30);
  if (local_38 <= (ulong)(lVar1 - lVar2)) {
    lVar1 = FUN_00b0a382(local_30);
    local_28 = FUN_00b0a382(local_30);
    plVar3 = (long *)FUN_00b06d34(&local_28,&local_38);
    local_20 = *plVar3 + lVar1;
    uVar4 = FUN_00b0a382(local_30);
    if ((local_20 < uVar4) || (uVar4 = FUN_00b19880(local_30), uVar4 < local_20)) {
      local_20 = FUN_00b19880(local_30);
    }
    return local_20;
  }
                    /* WARNING: Subroutine does not return */
  std::__throw_length_error(param_3);
}


// ==== entry=00b19444 name=FUN_00b19444 size=37 ====

undefined8 FUN_00b19444(undefined8 param_1)

{
  undefined8 local_10;
  
  FUN_00b1935c(&local_10,param_1);
  return local_10;
}


// ==== entry=00b19469 name=FUN_00b19469 size=64 ====

long FUN_00b19469(undefined8 param_1,undefined8 param_2)

{
  long lVar1;
  long *plVar2;
  
  plVar2 = (long *)FUN_00b194de(param_1);
  lVar1 = *plVar2;
  plVar2 = (long *)FUN_00b194de(param_2);
  return lVar1 - *plVar2 >> 3;
}


// ==== entry=00b194aa name=FUN_00b194aa size=51 ====

undefined8 FUN_00b194aa(undefined8 param_1,long param_2)

{
  undefined8 uVar1;
  
  if (param_2 == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = FUN_00b198a2(param_1,param_2);
  }
  return uVar1;
}


// ==== entry=00b194de name=FUN_00b194de size=14 ====

undefined8 FUN_00b194de(undefined8 param_1)

{
  return param_1;
}


// ==== entry=00b194ec name=FUN_00b194ec size=84 ====

void FUN_00b194ec(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 uVar1;
  undefined8 uVar2;
  
  uVar1 = FUN_00b198cc(param_2);
  uVar2 = FUN_00b198cc(param_1);
  FUN_00b198f1(uVar2,uVar1,param_3,param_4);
  return;
}


// ==== entry=00b19540 name=FUN_00b19540 size=38 ====

void FUN_00b19540(undefined8 param_1,undefined8 param_2)

{
  FUN_00b19922(param_1,param_2);
  return;
}


// ==== entry=00b19566 name=FUN_00b19566 size=14 ====

undefined8 FUN_00b19566(undefined8 param_1)

{
  return param_1;
}


// ==== entry=00b19574 name=FUN_00b19574 size=57 ====

void FUN_00b19574(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  undefined8 uVar1;
  
  uVar1 = FUN_00b19566(param_3);
  FUN_00b199ee(param_1,param_2,uVar1);
  return;
}


// ==== entry=00b195ae name=FUN_00b195ae size=155 ====

void FUN_00b195ae(long param_1,undefined8 param_2)

{
  long lVar1;
  undefined8 uVar2;
  
  FUN_00b13bc0(param_1,1);
  lVar1 = *(long *)(param_1 + 0x48);
  uVar2 = FUN_00b13c20(param_1);
  *(undefined8 *)(lVar1 + 8) = uVar2;
  uVar2 = FUN_00b19566(param_2);
                    /* try { // try from 00b1960c to 00b19610 has its CatchHandler @ 00b19642 */
  FUN_00b19574(param_1,*(undefined8 *)(param_1 + 0x30),uVar2);
  FUN_00b126cc(param_1 + 0x30,*(long *)(param_1 + 0x48) + 8);
  *(undefined8 *)(param_1 + 0x30) = *(undefined8 *)(param_1 + 0x38);
  return;
}


// ==== entry=00b19687 name=FUN_00b19687 size=14 ====

undefined8 FUN_00b19687(undefined8 param_1)

{
  return param_1;
}


// ==== entry=00b19695 name=FUN_00b19695 size=57 ====

void FUN_00b19695(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  undefined8 uVar1;
  
  uVar1 = FUN_00b19687(param_3);
  FUN_00b19a5c(param_1,param_2,uVar1);
  return;
}


// ==== entry=00b196ce name=FUN_00b196ce size=154 ====

void FUN_00b196ce(long param_1,undefined8 param_2)

{
  long lVar1;
  undefined8 uVar2;
  
  FUN_00b19a9a(param_1,1);
  lVar1 = *(long *)(param_1 + 0x48);
  uVar2 = FUN_00b13ea0(param_1);
  *(undefined8 *)(lVar1 + 8) = uVar2;
  uVar2 = FUN_00b19687(param_2);
  FUN_00b19695(param_1,*(undefined8 *)(param_1 + 0x30),uVar2);
  FUN_00b13684(param_1 + 0x30,*(long *)(param_1 + 0x48) + 8);
  *(undefined8 *)(param_1 + 0x30) = *(undefined8 *)(param_1 + 0x38);
  return;
}


// ==== entry=00b19768 name=FUN_00b19768 size=98 ====

long * FUN_00b19768(long *param_1)

{
  if (*param_1 == param_1[1]) {
    FUN_00b13684(param_1,param_1[3] + -8);
    *param_1 = param_1[2];
  }
  *param_1 = *param_1 + -4;
  return param_1;
}


// ==== entry=00b197ca name=FUN_00b197ca size=17 ====

undefined8 FUN_00b197ca(undefined8 *param_1)

{
  return *param_1;
}


// ==== entry=00b197db name=FUN_00b197db size=38 ====

void FUN_00b197db(undefined8 param_1,undefined8 param_2)

{
  FUN_00b19afa(param_1,param_2);
  return;
}


// ==== entry=00b19802 name=FUN_00b19802 size=126 ====

void FUN_00b19802(long param_1)

{
  undefined8 uVar1;
  undefined8 uVar2;
  
  FUN_00b125fa(param_1,*(undefined8 *)(param_1 + 0x38));
  FUN_00b13684(param_1 + 0x30,*(long *)(param_1 + 0x48) + -8);
  *(long *)(param_1 + 0x30) = *(long *)(param_1 + 0x40) + -4;
  uVar1 = *(undefined8 *)(param_1 + 0x30);
  uVar2 = FUN_00b100ba(param_1);
  FUN_00b197db(uVar2,uVar1);
  return;
}


// ==== entry=00b19880 name=FUN_00b19880 size=34 ====

void FUN_00b19880(undefined8 param_1)

{
  undefined8 uVar1;
  
  uVar1 = FUN_00b19b24(param_1);
  FUN_00b19b09(uVar1);
  return;
}


// ==== entry=00b198a2 name=FUN_00b198a2 size=42 ====

void FUN_00b198a2(undefined8 param_1,undefined8 param_2)

{
  FUN_00b19b32(param_1,param_2,0);
  return;
}


// ==== entry=00b198cc name=FUN_00b198cc size=37 ====

undefined8 FUN_00b198cc(undefined8 param_1)

{
  undefined8 local_10;
  
  FUN_00b19b74(&local_10,param_1);
  return local_10;
}


// ==== entry=00b198f1 name=FUN_00b198f1 size=49 ====

void FUN_00b198f1(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  FUN_00b19b8e(param_1,param_2,param_3);
  return;
}


// ==== entry=00b19922 name=FUN_00b19922 size=31 ====

void FUN_00b19922(undefined8 param_1,string *param_2)

{
  std::string::~string(param_2);
  return;
}


// ==== entry=00b19942 name=FUN_00b19942 size=142 ====

void FUN_00b19942(undefined4 *param_1,undefined4 *param_2)

{
  *param_1 = *param_2;
  param_1[1] = param_2[1];
  *(undefined8 *)(param_1 + 2) = *(undefined8 *)(param_2 + 2);
  param_1[4] = param_2[4];
  std::string::string((string *)(param_1 + 6),(string *)(param_2 + 6));
                    /* try { // try from 00b199b4 to 00b199b8 has its CatchHandler @ 00b199c9 */
  FUN_00b19bc0(param_1 + 8,param_2 + 8);
  param_1[0xe] = param_2[0xe];
  return;
}


// ==== entry=00b199ee name=FUN_00b199ee size=84 ====

void FUN_00b199ee(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  undefined8 uVar1;
  undefined8 uVar2;
  
  uVar1 = FUN_00b19566(param_3);
  uVar2 = FUN_00b00efa(0x40,param_2);
                    /* try { // try from 00b19a30 to 00b19a34 has its CatchHandler @ 00b19a37 */
  FUN_00b19942(uVar2,uVar1);
  return;
}


// ==== entry=00b19a5c name=FUN_00b19a5c size=62 ====

void FUN_00b19a5c(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  
  puVar2 = (undefined4 *)FUN_00b19687(param_3);
  uVar1 = *puVar2;
  puVar2 = (undefined4 *)FUN_00b00efa(4,param_2);
  *puVar2 = uVar1;
  return;
}


// ==== entry=00b19a9a name=FUN_00b19a9a size=95 ====

void FUN_00b19a9a(long *param_1,long param_2)

{
  if ((ulong)(param_1[1] - (param_1[9] - *param_1 >> 3)) < param_2 + 1U) {
    FUN_00b19cb2(param_1,param_2,0);
  }
  return;
}


// ==== entry=00b19afa name=FUN_00b19afa size=15 ====

void FUN_00b19afa(void)

{
  return;
}


// ==== entry=00b19b09 name=FUN_00b19b09 size=26 ====

void FUN_00b19b09(undefined8 param_1)

{
  FUN_00b19ed2(param_1);
  return;
}


// ==== entry=00b19b24 name=FUN_00b19b24 size=14 ====

undefined8 FUN_00b19b24(undefined8 param_1)

{
  return param_1;
}


// ==== entry=00b19b32 name=FUN_00b19b32 size=66 ====

void FUN_00b19b32(undefined8 param_1,ulong param_2)

{
  ulong uVar1;
  
  uVar1 = FUN_00b19ed2(param_1);
  if (uVar1 < param_2) {
                    /* WARNING: Subroutine does not return */
    std::__throw_bad_alloc();
  }
  operator_new(param_2 << 3);
  return;
}


// ==== entry=00b19b74 name=FUN_00b19b74 size=26 ====

void FUN_00b19b74(undefined8 *param_1,undefined8 param_2)

{
  *param_1 = param_2;
  return;
}


// ==== entry=00b19b8e name=FUN_00b19b8e size=49 ====

void FUN_00b19b8e(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  FUN_00b19ee6(param_1,param_2,param_3);
  return;
}


// ==== entry=00b19bc0 name=FUN_00b19bc0 size=190 ====

void FUN_00b19bc0(undefined8 *param_1,undefined8 param_2)

{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined1 local_29 [9];
  
  uVar1 = FUN_00b19b24(param_2);
  FUN_00b19f93(local_29,uVar1);
  uVar1 = FUN_00b0a382(param_2);
                    /* try { // try from 00b19c13 to 00b19c17 has its CatchHandler @ 00b19c73 */
  FUN_00b19fbc(param_1,uVar1,local_29);
  FUN_00b10a60(local_29);
  uVar2 = FUN_00b0fa0e(param_1);
  uVar1 = *param_1;
  uVar3 = FUN_00b0a02e(param_2);
  uVar4 = FUN_00b09ffe(param_2);
                    /* try { // try from 00b19c61 to 00b19c65 has its CatchHandler @ 00b19c8d */
  uVar1 = FUN_00b1a01a(uVar4,uVar3,uVar1,uVar2);
  param_1[1] = uVar1;
  return;
}


// ==== entry=00b19cb2 name=FUN_00b19cb2 size=544 ====

void FUN_00b19cb2(long *param_1,long param_2,char param_3)

{
  long *plVar1;
  long lVar2;
  long local_58;
  long *local_50;
  long local_40;
  long local_38;
  long local_30;
  long local_28;
  ulong local_20;
  
  local_28 = (param_1[9] - param_1[5] >> 3) + 1;
  local_30 = local_28 + param_2;
  local_58 = param_2;
  local_50 = param_1;
  if ((ulong)(local_30 * 2) < (ulong)param_1[1]) {
    if (param_3 == '\0') {
      param_2 = 0;
    }
    else {
      param_2 = param_2 << 3;
    }
    local_20 = param_2 + ((ulong)(param_1[1] - local_30) >> 1) * 8 + *param_1;
    if (local_20 < (ulong)param_1[5]) {
      FUN_00b1a04b(param_1[5],param_1[9] + 8,local_20);
    }
    else {
      FUN_00b1a097(param_1[5],param_1[9] + 8,local_28 * 8 + local_20);
    }
  }
  else {
    lVar2 = param_1[1];
    plVar1 = (long *)FUN_00b06d34(param_1 + 1,&local_58);
    local_38 = *plVar1 + lVar2 + 2;
    local_40 = FUN_00b13592(local_50,local_38);
    if (param_3 == '\0') {
      lVar2 = 0;
    }
    else {
      lVar2 = local_58 << 3;
    }
    local_20 = local_40 + ((ulong)(local_38 - local_30) >> 1) * 8 + lVar2;
    FUN_00b1a04b(local_50[5],local_50[9] + 8,local_20);
    FUN_00b11048(local_50,*local_50,local_50[1]);
    *local_50 = local_40;
    local_50[1] = local_38;
  }
  FUN_00b13684(local_50 + 2,local_20);
  FUN_00b13684(local_50 + 6,local_20 + local_28 * 8 + -8);
  return;
}


// ==== entry=00b19ed2 name=FUN_00b19ed2 size=20 ====

undefined8 FUN_00b19ed2(void)

{
  return 0x1fffffffffffffff;
}


// ==== entry=00b19ee6 name=FUN_00b19ee6 size=122 ====

long FUN_00b19ee6(undefined8 param_1,undefined8 param_2,long param_3)

{
  char cVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 local_38;
  undefined8 local_30 [2];
  long local_20;
  
  local_38 = param_2;
  local_30[0] = param_1;
  local_20 = param_3;
  while( true ) {
                    /* try { // try from 00b19f11 to 00b19f15 has its CatchHandler @ 00b19f59 */
    cVar1 = FUN_00b1a0e3(local_30,&local_38);
    if (cVar1 == '\0') break;
    uVar2 = FUN_00b1a12c(local_30);
    uVar3 = FUN_00b11a77(local_20);
    FUN_00b1a14b(uVar3,uVar2);
    FUN_00b1a10c(local_30);
    local_20 = local_20 + 8;
  }
  return local_20;
}


// ==== entry=00b19f93 name=FUN_00b19f93 size=41 ====

undefined8 FUN_00b19f93(undefined8 param_1,undefined8 param_2)

{
  FUN_00b1a18f(param_1,param_2);
  return param_1;
}


// ==== entry=00b19fbc name=FUN_00b19fbc size=68 ====

void FUN_00b19fbc(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  FUN_00b1a1b8(param_1,param_3);
                    /* try { // try from 00b19ff2 to 00b19ff6 has its CatchHandler @ 00b19ff9 */
  FUN_00b1a202(param_1,param_2);
  return;
}


// ==== entry=00b1a01a name=FUN_00b1a01a size=49 ====

void FUN_00b1a01a(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  FUN_00b1a25b(param_1,param_2,param_3);
  return;
}


// ==== entry=00b1a04b name=FUN_00b1a04b size=76 ====

void FUN_00b1a04b(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  undefined8 uVar1;
  undefined8 uVar2;
  
  uVar1 = FUN_00b1a28c(param_2);
  uVar2 = FUN_00b1a28c(param_1);
  FUN_00b1a29a(uVar2,uVar1,param_3);
  return;
}


// ==== entry=00b1a097 name=FUN_00b1a097 size=76 ====

void FUN_00b1a097(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  undefined8 uVar1;
  undefined8 uVar2;
  
  uVar1 = FUN_00b1a28c(param_2);
  uVar2 = FUN_00b1a28c(param_1);
  FUN_00b1a2f2(uVar2,uVar1,param_3);
  return;
}


// ==== entry=00b1a0e3 name=FUN_00b1a0e3 size=40 ====

uint FUN_00b1a0e3(undefined8 param_1,undefined8 param_2)

{
  uint uVar1;
  
  uVar1 = FUN_00b1a34a(param_1,param_2);
  return uVar1 ^ 1;
}


// ==== entry=00b1a10c name=FUN_00b1a10c size=32 ====

long * FUN_00b1a10c(long *param_1)

{
  *param_1 = *param_1 + 8;
  return param_1;
}


// ==== entry=00b1a12c name=FUN_00b1a12c size=17 ====

undefined8 FUN_00b1a12c(undefined8 *param_1)

{
  return *param_1;
}


// ==== entry=00b1a13d name=FUN_00b1a13d size=14 ====

undefined8 FUN_00b1a13d(undefined8 param_1)

{
  return param_1;
}


// ==== entry=00b1a14b name=FUN_00b1a14b size=68 ====

void FUN_00b1a14b(undefined8 param_1,undefined8 param_2)

{
  string *psVar1;
  string *this;
  
  psVar1 = (string *)FUN_00b1a13d(param_2);
  this = (string *)FUN_00b00efa(8,param_1);
  std::string::string(this,psVar1);
  return;
}


// ==== entry=00b1a18f name=FUN_00b1a18f size=41 ====

undefined8 FUN_00b1a18f(undefined8 param_1,undefined8 param_2)

{
  FUN_00b15026(param_1,param_2);
  return param_1;
}


// ==== entry=00b1a1b8 name=FUN_00b1a1b8 size=73 ====

void FUN_00b1a1b8(undefined8 *param_1,undefined8 param_2)

{
  FUN_00b15026(param_1,param_2);
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  return;
}


// ==== entry=00b1a202 name=FUN_00b1a202 size=89 ====

void FUN_00b1a202(long *param_1,long param_2)

{
  long lVar1;
  
  lVar1 = FUN_00b194aa(param_1,param_2);
  *param_1 = lVar1;
  param_1[1] = *param_1;
  param_1[2] = param_2 * 8 + *param_1;
  return;
}


// ==== entry=00b1a25b name=FUN_00b1a25b size=49 ====

void FUN_00b1a25b(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  FUN_00b1a383(param_1,param_2,param_3);
  return;
}


// ==== entry=00b1a28c name=FUN_00b1a28c size=14 ====

undefined8 FUN_00b1a28c(undefined8 param_1)

{
  return param_1;
}


// ==== entry=00b1a29a name=FUN_00b1a29a size=88 ====

void FUN_00b1a29a(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  
  uVar1 = FUN_00b1a430(param_3);
  uVar2 = FUN_00b1a430(param_2);
  uVar3 = FUN_00b1a430(param_1);
  FUN_00b1a43e(uVar3,uVar2,uVar1);
  return;
}


// ==== entry=00b1a2f2 name=FUN_00b1a2f2 size=88 ====

void FUN_00b1a2f2(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  
  uVar1 = FUN_00b1a430(param_3);
  uVar2 = FUN_00b1a430(param_2);
  uVar3 = FUN_00b1a430(param_1);
  FUN_00b1a46f(uVar3,uVar2,uVar1);
  return;
}


// ==== entry=00b1a34a name=FUN_00b1a34a size=57 ====

bool FUN_00b1a34a(undefined8 param_1,undefined8 param_2)

{
  long lVar1;
  long lVar2;
  
  lVar1 = FUN_00b1a4a0(param_1);
  lVar2 = FUN_00b1a4a0(param_2);
  return lVar1 == lVar2;
}


// ==== entry=00b1a383 name=FUN_00b1a383 size=122 ====

long FUN_00b1a383(undefined8 param_1,undefined8 param_2,long param_3)

{
  char cVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 local_38;
  undefined8 local_30 [2];
  long local_20;
  
  local_38 = param_2;
  local_30[0] = param_1;
  local_20 = param_3;
  while( true ) {
    cVar1 = FUN_00b0a05f(local_30,&local_38);
    if (cVar1 == '\0') break;
    uVar2 = FUN_00b0a0bc(local_30);
    uVar3 = FUN_00b11a77(local_20);
                    /* try { // try from 00b1a3d8 to 00b1a3dc has its CatchHandler @ 00b1a3f6 */
    FUN_00b1a4b1(uVar3,uVar2);
    FUN_00b0a09c(local_30);
    local_20 = local_20 + 8;
  }
  return local_20;
}


// ==== entry=00b1a430 name=FUN_00b1a430 size=14 ====

undefined8 FUN_00b1a430(undefined8 param_1)

{
  return param_1;
}


// ==== entry=00b1a43e name=FUN_00b1a43e size=49 ====

void FUN_00b1a43e(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  FUN_00b1a51a(param_1,param_2,param_3);
  return;
}


// ==== entry=00b1a46f name=FUN_00b1a46f size=49 ====

void FUN_00b1a46f(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  FUN_00b1a579(param_1,param_2,param_3);
  return;
}


// ==== entry=00b1a4a0 name=FUN_00b1a4a0 size=17 ====

undefined8 FUN_00b1a4a0(undefined8 *param_1)

{
  return *param_1;
}


// ==== entry=00b1a4b1 name=FUN_00b1a4b1 size=80 ====

void FUN_00b1a4b1(undefined8 param_1,undefined8 param_2)

{
  string *psVar1;
  string *this;
  
  psVar1 = (string *)FUN_00b0be11(param_2);
  this = (string *)FUN_00b00efa(8,param_1);
                    /* try { // try from 00b1a4ef to 00b1a4f3 has its CatchHandler @ 00b1a4f6 */
  std::string::string(this,psVar1);
  return;
}


// ==== entry=00b1a51a name=FUN_00b1a51a size=95 ====

void * FUN_00b1a51a(void *param_1,long param_2,void *param_3)

{
  long lVar1;
  
  lVar1 = param_2 - (long)param_1 >> 3;
  if (lVar1 != 0) {
    memmove(param_3,param_1,lVar1 * 8);
  }
  return (void *)((long)param_3 + lVar1 * 8);
}


// ==== entry=00b1a579 name=FUN_00b1a579 size=114 ====

long FUN_00b1a579(void *param_1,long param_2,long param_3)

{
  long lVar1;
  
  lVar1 = param_2 - (long)param_1 >> 3;
  if (lVar1 != 0) {
    memmove((void *)(lVar1 * -8 + param_3),param_1,lVar1 * 8);
  }
  return param_3 + lVar1 * -8;
}


// ==== entry=00b1a5ec name=FUN_00b1a5ec size=87 ====

void FUN_00b1a5ec(undefined8 *param_1,undefined8 *param_2,undefined8 param_3)

{
  *param_1 = *param_2;
  *(undefined4 *)(param_1 + 1) = *(undefined4 *)(param_2 + 1);
  param_1[2] = param_3;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[5] = 0;
  return;
}


// ==== entry=00b1a644 name=FUN_00b1a644 size=93 ====

void FUN_00b1a644(long param_1)

{
  if (*(long *)(param_1 + 0x18) != 0) {
    *(undefined4 *)(*(long *)(param_1 + 0x18) + 8) = 0;
  }
  if (*(long *)(param_1 + 0x20) != 0) {
    **(undefined4 **)(param_1 + 0x20) = 0;
  }
  if (*(long *)(param_1 + 0x28) != 0) {
    **(undefined4 **)(param_1 + 0x28) = 0;
  }
  return;
}


// ==== entry=00b1a6a2 name=FUN_00b1a6a2 size=93 ====

void FUN_00b1a6a2(long param_1)

{
  if (*(long *)(param_1 + 0x18) != 0) {
    *(undefined4 *)(*(long *)(param_1 + 0x18) + 8) = 1;
  }
  if (*(long *)(param_1 + 0x20) != 0) {
    **(undefined4 **)(param_1 + 0x20) = 1;
  }
  if (*(long *)(param_1 + 0x28) != 0) {
    **(undefined4 **)(param_1 + 0x28) = 1;
  }
  return;
}


// ==== entry=00b1a700 name=FUN_00b1a700 size=54 ====

uint FUN_00b1a700(long param_1)

{
  uint uVar1;
  
  if (*(char *)(param_1 + 0xd2) == '\x01') {
    uVar1 = FUN_00b1a736(param_1);
    uVar1 = uVar1 ^ 1;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


// ==== entry=00b1a736 name=FUN_00b1a736 size=97 ====

bool FUN_00b1a736(long param_1)

{
  char cVar1;
  long lVar2;
  long lVar3;
  bool bVar4;
  
  cVar1 = FUN_00b1b1e6(param_1 + 0xd8);
  if (cVar1 == '\0') {
    lVar2 = FUN_00b1b200(param_1 + 0xd8);
    lVar2 = *(long *)(lVar2 + 0x10);
    lVar3 = FUN_00b1b1ac(param_1);
    bVar4 = lVar2 == lVar3;
  }
  else {
    bVar4 = false;
  }
  return bVar4;
}


// ==== entry=00b1a798 name=FUN_00b1a798 size=404 ====

void FUN_00b1a798(long param_1)

{
  char cVar1;
  undefined4 uVar2;
  undefined8 uVar3;
  undefined1 local_a8 [24];
  long local_90;
  undefined4 *local_88;
  undefined4 *local_80;
  undefined1 local_74 [12];
  undefined1 local_68 [68];
  undefined1 local_24 [12];
  
  cVar1 = FUN_00b1a700(param_1);
  if (cVar1 == '\x01') {
    uVar3 = FUN_00b1b1ac(param_1);
    local_74 = FUN_00b0d79a(param_1);
    FUN_00b1a5ec(local_a8,local_74,uVar3);
    cVar1 = FUN_00b0ee1e(param_1);
    if (cVar1 != '\0') {
      uVar2 = FUN_00b0d7c0(param_1);
      local_90 = FUN_00b0cb42(param_1,uVar2,0);
      if (local_90 != 0) {
        *(undefined4 *)(local_90 + 8) = 2;
        local_88 = *(undefined4 **)(local_90 + 0x10);
        *local_88 = 2;
      }
    }
    local_24 = FUN_00b0d79a(param_1);
    FUN_00b0ed54(local_68,0xe,local_24);
                    /* try { // try from 00b1a8cd to 00b1a8d1 has its CatchHandler @ 00b1a921 */
    FUN_00b0f508(param_1 + 0x80,local_68);
    FUN_00b0eed8(local_68);
    local_80 = (undefined4 *)FUN_00b0f53c(param_1 + 0x80);
    *local_80 = 2;
    FUN_00b1b21a(param_1 + 0xd8,local_a8);
  }
  return;
}


// ==== entry=00b1a946 name=FUN_00b1a946 size=130 ====

void FUN_00b1a946(long param_1)

{
  long lVar1;
  char cVar2;
  long lVar3;
  long lVar4;
  
  cVar2 = FUN_00b1b1e6(param_1 + 0xd8);
  if (cVar2 == '\0') {
    lVar3 = FUN_00b1b240(param_1 + 0xd8);
    lVar1 = *(long *)(lVar3 + 0x10);
    lVar4 = FUN_00b1b1ac(param_1);
    if (lVar1 == lVar4) {
      FUN_00b1a6a2(lVar3);
      FUN_00b1b25a(param_1 + 0xd8);
    }
  }
  return;
}


// ==== entry=00b1a9c8 name=FUN_00b1a9c8 size=277 ====

char FUN_00b1a9c8(long param_1)

{
  long lVar1;
  bool bVar2;
  char cVar3;
  int iVar4;
  undefined8 *puVar5;
  long lVar6;
  undefined8 local_58;
  undefined8 local_50;
  long local_48;
  undefined8 local_40;
  undefined8 local_38;
  undefined8 local_30;
  char local_19;
  
  cVar3 = FUN_00b1b1e6(param_1 + 0xd8);
  if (cVar3 != '\0') {
    return '\0';
  }
  puVar5 = (undefined8 *)FUN_00b1b240(param_1 + 0xd8);
  local_58 = *puVar5;
  local_50 = puVar5[1];
  lVar1 = puVar5[2];
  local_40 = puVar5[3];
  local_30 = puVar5[5];
  local_38 = puVar5[4];
  local_48 = lVar1;
  lVar6 = FUN_00b1b1ac(param_1);
  if (lVar1 != lVar6) {
    return '\0';
  }
  FUN_00b1b25a(param_1 + 0xd8);
  local_19 = '\x01';
  iVar4 = FUN_00b1b19a(param_1);
  if (iVar4 == local_58._4_4_) {
    iVar4 = FUN_00b1b188(param_1);
    if (iVar4 - (int)local_58 < 0x401) {
      bVar2 = false;
      goto LAB_00b1aaaa;
    }
  }
  bVar2 = true;
LAB_00b1aaaa:
  if (bVar2) {
    local_19 = '\0';
  }
  if (local_19 == '\0') {
    FUN_00b1a6a2(&local_58);
  }
  else {
    FUN_00b1a644(&local_58);
  }
  return local_19;
}


// ==== entry=00b1aade name=FUN_00b1aade size=60 ====

void FUN_00b1aade(long param_1)

{
  char cVar1;
  
  while( true ) {
    cVar1 = FUN_00b1b1e6(param_1 + 0xd8);
    if (cVar1 == '\x01') break;
    FUN_00b1b25a(param_1 + 0xd8);
  }
  return;
}


// ==== entry=00b1ab1a name=FUN_00b1ab1a size=48 ====

void FUN_00b1ab1a(void)

{
  string *this;
  
  this = (string *)&DAT_011c3420;
  while (this != (string *)&DAT_011c3380) {
    this = this + -8;
    std::string::~string(this);
  }
  return;
}


// ==== entry=00b1ab4a name=FUN_00b1ab4a size=1151 ====

void FUN_00b1ab4a(int param_1,int param_2)

{
  allocator local_3c;
  allocator local_3b;
  allocator local_3a;
  allocator local_39;
  allocator local_38;
  allocator local_37;
  allocator local_36;
  allocator local_35;
  allocator local_34;
  allocator local_33;
  allocator local_32;
  allocator local_31;
  allocator local_30;
  allocator local_2f;
  allocator local_2e;
  allocator local_2d;
  allocator local_2c;
  allocator local_2b;
  allocator local_2a;
  allocator local_29 [9];
  
  if ((param_1 == 1) && (param_2 == 0xffff)) {
    std::ios_base::Init::Init((Init *)&DAT_011c3360);
    __cxa_atexit(std::ios_base::Init::~Init,&DAT_011c3360,&DAT_00c89008);
    std::allocator<char>::allocator();
                    /* try { // try from 00b1abb8 to 00b1abbc has its CatchHandler @ 00b1afbe */
    std::string::string((string *)&DAT_011c3380,"DIRECTIVE",&local_3c);
    std::allocator<char>::~allocator((allocator<char> *)&local_3c);
    std::allocator<char>::allocator();
                    /* try { // try from 00b1abec to 00b1abf0 has its CatchHandler @ 00b1afd2 */
    std::string::string((string *)&DAT_011c3388,"DOC_START",&local_3b);
    std::allocator<char>::~allocator((allocator<char> *)&local_3b);
    std::allocator<char>::allocator();
                    /* try { // try from 00b1ac20 to 00b1ac24 has its CatchHandler @ 00b1afe6 */
    std::string::string((string *)&DAT_011c3390,"DOC_END",&local_3a);
    std::allocator<char>::~allocator((allocator<char> *)&local_3a);
    std::allocator<char>::allocator();
                    /* try { // try from 00b1ac54 to 00b1ac58 has its CatchHandler @ 00b1affa */
    std::string::string((string *)&DAT_011c3398,"BLOCK_SEQ_START",&local_39);
    std::allocator<char>::~allocator((allocator<char> *)&local_39);
    std::allocator<char>::allocator();
                    /* try { // try from 00b1ac88 to 00b1ac8c has its CatchHandler @ 00b1b00e */
    std::string::string((string *)&DAT_011c33a0,"BLOCK_MAP_START",&local_38);
    std::allocator<char>::~allocator((allocator<char> *)&local_38);
    std::allocator<char>::allocator();
                    /* try { // try from 00b1acbc to 00b1acc0 has its CatchHandler @ 00b1b022 */
    std::string::string((string *)&DAT_011c33a8,"BLOCK_SEQ_END",&local_37);
    std::allocator<char>::~allocator((allocator<char> *)&local_37);
    std::allocator<char>::allocator();
                    /* try { // try from 00b1acf0 to 00b1acf4 has its CatchHandler @ 00b1b036 */
    std::string::string((string *)&DAT_011c33b0,"BLOCK_MAP_END",&local_36);
    std::allocator<char>::~allocator((allocator<char> *)&local_36);
    std::allocator<char>::allocator();
                    /* try { // try from 00b1ad24 to 00b1ad28 has its CatchHandler @ 00b1b04a */
    std::string::string((string *)&DAT_011c33b8,"BLOCK_ENTRY",&local_35);
    std::allocator<char>::~allocator((allocator<char> *)&local_35);
    std::allocator<char>::allocator();
                    /* try { // try from 00b1ad58 to 00b1ad5c has its CatchHandler @ 00b1b05e */
    std::string::string((string *)&DAT_011c33c0,"FLOW_SEQ_START",&local_34);
    std::allocator<char>::~allocator((allocator<char> *)&local_34);
    std::allocator<char>::allocator();
                    /* try { // try from 00b1ad8c to 00b1ad90 has its CatchHandler @ 00b1b072 */
    std::string::string((string *)&DAT_011c33c8,"FLOW_MAP_START",&local_33);
    std::allocator<char>::~allocator((allocator<char> *)&local_33);
    std::allocator<char>::allocator();
                    /* try { // try from 00b1adc0 to 00b1adc4 has its CatchHandler @ 00b1b086 */
    std::string::string((string *)&DAT_011c33d0,"FLOW_SEQ_END",&local_32);
    std::allocator<char>::~allocator((allocator<char> *)&local_32);
    std::allocator<char>::allocator();
                    /* try { // try from 00b1adf4 to 00b1adf8 has its CatchHandler @ 00b1b09a */
    std::string::string((string *)&DAT_011c33d8,"FLOW_MAP_END",&local_31);
    std::allocator<char>::~allocator((allocator<char> *)&local_31);
    std::allocator<char>::allocator();
                    /* try { // try from 00b1ae28 to 00b1ae2c has its CatchHandler @ 00b1b0ae */
    std::string::string((string *)&DAT_011c33e0,"FLOW_MAP_COMPACT",&local_30);
    std::allocator<char>::~allocator((allocator<char> *)&local_30);
    std::allocator<char>::allocator();
                    /* try { // try from 00b1ae5c to 00b1ae60 has its CatchHandler @ 00b1b0bf */
    std::string::string((string *)&DAT_011c33e8,"FLOW_ENTRY",&local_2f);
    std::allocator<char>::~allocator((allocator<char> *)&local_2f);
    std::allocator<char>::allocator();
                    /* try { // try from 00b1ae90 to 00b1ae94 has its CatchHandler @ 00b1b0d0 */
    std::string::string((string *)&DAT_011c33f0,"KEY",&local_2e);
    std::allocator<char>::~allocator((allocator<char> *)&local_2e);
    std::allocator<char>::allocator();
                    /* try { // try from 00b1aec4 to 00b1aec8 has its CatchHandler @ 00b1b0e1 */
    std::string::string((string *)&DAT_011c33f8,"VALUE",&local_2d);
    std::allocator<char>::~allocator((allocator<char> *)&local_2d);
    std::allocator<char>::allocator();
                    /* try { // try from 00b1aef8 to 00b1aefc has its CatchHandler @ 00b1b0f2 */
    std::string::string((string *)&DAT_011c3400,"ANCHOR",&local_2c);
    std::allocator<char>::~allocator((allocator<char> *)&local_2c);
    std::allocator<char>::allocator();
                    /* try { // try from 00b1af2c to 00b1af30 has its CatchHandler @ 00b1b103 */
    std::string::string((string *)&DAT_011c3408,"ALIAS",&local_2b);
    std::allocator<char>::~allocator((allocator<char> *)&local_2b);
    std::allocator<char>::allocator();
                    /* try { // try from 00b1af60 to 00b1af64 has its CatchHandler @ 00b1b114 */
    std::string::string((string *)&DAT_011c3410,"TAG",&local_2a);
    std::allocator<char>::~allocator((allocator<char> *)&local_2a);
    std::allocator<char>::allocator();
                    /* try { // try from 00b1af94 to 00b1af98 has its CatchHandler @ 00b1b125 */
    std::string::string((string *)&DAT_011c3418,"SCALAR",local_29);
    std::allocator<char>::~allocator((allocator<char> *)local_29);
    __cxa_atexit(FUN_00b1ab1a,0,&DAT_00c89008);
  }
  return;
}


// ==== entry=00b1b173 orig=FUN_00b1b173 size=21 name=_INIT_173 ====

void _INIT_173(void)

{
  FUN_00b1ab4a(1,0xffff);
  return;
}


// ==== entry=00b1b188 name=FUN_00b1b188 size=17 ====

undefined4 FUN_00b1b188(long param_1)

{
  return *(undefined4 *)(param_1 + 8);
}


// ==== entry=00b1b19a name=FUN_00b1b19a size=17 ====

undefined4 FUN_00b1b19a(long param_1)

{
  return *(undefined4 *)(param_1 + 0xc);
}


// ==== entry=00b1b1ac name=FUN_00b1b1ac size=32 ====

void FUN_00b1b1ac(long param_1)

{
  FUN_00b1b1cc(param_1 + 400);
  return;
}


// ==== entry=00b1b1cc name=FUN_00b1b1cc size=26 ====

void FUN_00b1b1cc(undefined8 param_1)

{
  FUN_00b1b276(param_1);
  return;
}


// ==== entry=00b1b1e6 name=FUN_00b1b1e6 size=26 ====

void FUN_00b1b1e6(undefined8 param_1)

{
  FUN_00b1b2a0(param_1);
  return;
}


// ==== entry=00b1b200 name=FUN_00b1b200 size=26 ====

void FUN_00b1b200(undefined8 param_1)

{
  FUN_00b1b2ca(param_1);
  return;
}


// ==== entry=00b1b21a name=FUN_00b1b21a size=38 ====

void FUN_00b1b21a(undefined8 param_1,undefined8 param_2)

{
  FUN_00b1b304(param_1,param_2);
  return;
}


// ==== entry=00b1b240 name=FUN_00b1b240 size=26 ====

void FUN_00b1b240(undefined8 param_1)

{
  FUN_00b1b374(param_1);
  return;
}


// ==== entry=00b1b25a name=FUN_00b1b25a size=27 ====

void FUN_00b1b25a(undefined8 param_1)

{
  FUN_00b1b3ae(param_1);
  return;
}


// ==== entry=00b1b276 name=FUN_00b1b276 size=41 ====

void FUN_00b1b276(long param_1)

{
  FUN_00b1b40b(param_1 + 0x30,param_1 + 0x10);
  return;
}


// ==== entry=00b1b2a0 name=FUN_00b1b2a0 size=41 ====

void FUN_00b1b2a0(long param_1)

{
  FUN_00b1b483(param_1 + 0x30,param_1 + 0x10);
  return;
}


// ==== entry=00b1b2ca name=FUN_00b1b2ca size=58 ====

void FUN_00b1b2ca(undefined8 param_1)

{
  undefined1 local_28 [32];
  
  FUN_00b1b4a6(local_28,param_1);
  FUN_00b1b4d4(local_28);
  FUN_00b1b536(local_28);
  return;
}


// ==== entry=00b1b304 name=FUN_00b1b304 size=112 ====

void FUN_00b1b304(long param_1,undefined8 param_2)

{
  if (*(long *)(param_1 + 0x30) == *(long *)(param_1 + 0x40) + -0x30) {
    FUN_00b1b58e(param_1,param_2);
  }
  else {
    FUN_00b1b555(param_1,*(undefined8 *)(param_1 + 0x30),param_2);
    *(long *)(param_1 + 0x30) = *(long *)(param_1 + 0x30) + 0x30;
  }
  return;
}


// ==== entry=00b1b374 name=FUN_00b1b374 size=58 ====

void FUN_00b1b374(undefined8 param_1)

{
  undefined1 local_28 [32];
  
  FUN_00b0fcee(local_28,param_1);
  FUN_00b1b628(local_28);
  FUN_00b1b68a(local_28);
  return;
}


// ==== entry=00b1b3ae name=FUN_00b1b3ae size=93 ====

void FUN_00b1b3ae(long param_1)

{
  if (*(long *)(param_1 + 0x30) == *(long *)(param_1 + 0x38)) {
    FUN_00b1b6c2(param_1);
  }
  else {
    *(long *)(param_1 + 0x30) = *(long *)(param_1 + 0x30) + -0x30;
    FUN_00b1b69b(param_1,*(undefined8 *)(param_1 + 0x30));
  }
  return;
}


// ==== entry=00b1b40b name=FUN_00b1b40b size=120 ====

long FUN_00b1b40b(long *param_1,long *param_2)

{
  long lVar1;
  
  lVar1 = FUN_00b11abd();
  return (param_2[2] - *param_2 >> 2) +
         lVar1 * ((param_1[3] - param_2[3] >> 3) + -1) + (*param_1 - param_1[1] >> 2);
}


// ==== entry=00b1b483 name=FUN_00b1b483 size=34 ====

undefined8 FUN_00b1b483(long *param_1,long *param_2)

{
  return CONCAT71((int7)((ulong)*param_2 >> 8),*param_1 == *param_2);
}


// ==== entry=00b1b4a6 name=FUN_00b1b4a6 size=45 ====

undefined8 FUN_00b1b4a6(undefined8 param_1,long param_2)

{
  FUN_00b1b740(param_1,param_2 + 0x30);
  return param_1;
}


// ==== entry=00b1b4d4 name=FUN_00b1b4d4 size=98 ====

long * FUN_00b1b4d4(long *param_1)

{
  if (*param_1 == param_1[1]) {
    FUN_00b1b78e(param_1,param_1[3] + -8);
    *param_1 = param_1[2];
  }
  *param_1 = *param_1 + -0x30;
  return param_1;
}


// ==== entry=00b1b536 name=FUN_00b1b536 size=17 ====

undefined8 FUN_00b1b536(undefined8 *param_1)

{
  return *param_1;
}


// ==== entry=00b1b547 name=FUN_00b1b547 size=14 ====

undefined8 FUN_00b1b547(undefined8 param_1)

{
  return param_1;
}


// ==== entry=00b1b555 name=FUN_00b1b555 size=57 ====

void FUN_00b1b555(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  undefined8 uVar1;
  
  uVar1 = FUN_00b1b547(param_3);
  FUN_00b1b7ec(param_1,param_2,uVar1);
  return;
}


// ==== entry=00b1b58e name=FUN_00b1b58e size=154 ====

void FUN_00b1b58e(long param_1,undefined8 param_2)

{
  long lVar1;
  undefined8 uVar2;
  
  FUN_00b1b858(param_1,1);
  lVar1 = *(long *)(param_1 + 0x48);
  uVar2 = FUN_00b13d8e(param_1);
  *(undefined8 *)(lVar1 + 8) = uVar2;
  uVar2 = FUN_00b1b547(param_2);
  FUN_00b1b555(param_1,*(undefined8 *)(param_1 + 0x30),uVar2);
  FUN_00b13224(param_1 + 0x30,*(long *)(param_1 + 0x48) + 8);
  *(undefined8 *)(param_1 + 0x30) = *(undefined8 *)(param_1 + 0x38);
  return;
}


// ==== entry=00b1b628 name=FUN_00b1b628 size=98 ====

long * FUN_00b1b628(long *param_1)

{
  if (*param_1 == param_1[1]) {
    FUN_00b13224(param_1,param_1[3] + -8);
    *param_1 = param_1[2];
  }
  *param_1 = *param_1 + -0x30;
  return param_1;
}


// ==== entry=00b1b68a name=FUN_00b1b68a size=17 ====

undefined8 FUN_00b1b68a(undefined8 *param_1)

{
  return *param_1;
}


// ==== entry=00b1b69b name=FUN_00b1b69b size=38 ====

void FUN_00b1b69b(undefined8 param_1,undefined8 param_2)

{
  FUN_00b1b8b8(param_1,param_2);
  return;
}


// ==== entry=00b1b6c2 name=FUN_00b1b6c2 size=126 ====

void FUN_00b1b6c2(long param_1)

{
  undefined8 uVar1;
  undefined8 uVar2;
  
  FUN_00b11fcc(param_1,*(undefined8 *)(param_1 + 0x38));
  FUN_00b13224(param_1 + 0x30,*(long *)(param_1 + 0x48) + -8);
  *(long *)(param_1 + 0x30) = *(long *)(param_1 + 0x40) + -0x30;
  uVar1 = *(undefined8 *)(param_1 + 0x30);
  uVar2 = FUN_00b0fd1c(param_1);
  FUN_00b1b69b(uVar2,uVar1);
  return;
}


// ==== entry=00b1b740 name=FUN_00b1b740 size=77 ====

void FUN_00b1b740(undefined8 *param_1,undefined8 *param_2)

{
  *param_1 = *param_2;
  param_1[1] = param_2[1];
  param_1[2] = param_2[2];
  param_1[3] = param_2[3];
  return;
}


// ==== entry=00b1b78e name=FUN_00b1b78e size=93 ====

void FUN_00b1b78e(long param_1,undefined8 *param_2)

{
  long lVar1;
  long lVar2;
  
  *(undefined8 **)(param_1 + 0x18) = param_2;
  *(undefined8 *)(param_1 + 8) = *param_2;
  lVar1 = *(long *)(param_1 + 8);
  lVar2 = FUN_00b1b8c7();
  *(long *)(param_1 + 0x10) = lVar1 + lVar2 * 0x30;
  return;
}


// ==== entry=00b1b7ec name=FUN_00b1b7ec size=107 ====

void FUN_00b1b7ec(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  undefined8 uVar1;
  undefined8 *puVar2;
  undefined8 *puVar3;
  
  puVar2 = (undefined8 *)FUN_00b1b547(param_3);
  puVar3 = (undefined8 *)FUN_00b00efa(0x30,param_2);
  uVar1 = puVar2[1];
  *puVar3 = *puVar2;
  puVar3[1] = uVar1;
  uVar1 = puVar2[3];
  puVar3[2] = puVar2[2];
  puVar3[3] = uVar1;
  uVar1 = puVar2[5];
  puVar3[4] = puVar2[4];
  puVar3[5] = uVar1;
  return;
}


// ==== entry=00b1b858 name=FUN_00b1b858 size=95 ====

void FUN_00b1b858(long *param_1,long param_2)

{
  if ((ulong)(param_1[1] - (param_1[9] - *param_1 >> 3)) < param_2 + 1U) {
    FUN_00b1b8d8(param_1,param_2,0);
  }
  return;
}


// ==== entry=00b1b8b8 name=FUN_00b1b8b8 size=15 ====

void FUN_00b1b8b8(void)

{
  return;
}


// ==== entry=00b1b8c7 name=FUN_00b1b8c7 size=16 ====

void FUN_00b1b8c7(void)

{
  FUN_00b0d748(0x30);
  return;
}


// ==== entry=00b1b8d8 name=FUN_00b1b8d8 size=544 ====

void FUN_00b1b8d8(long *param_1,long param_2,char param_3)

{
  long *plVar1;
  long lVar2;
  long local_58;
  long *local_50;
  long local_40;
  long local_38;
  long local_30;
  long local_28;
  ulong local_20;
  
  local_28 = (param_1[9] - param_1[5] >> 3) + 1;
  local_30 = local_28 + param_2;
  local_58 = param_2;
  local_50 = param_1;
  if ((ulong)(local_30 * 2) < (ulong)param_1[1]) {
    if (param_3 == '\0') {
      param_2 = 0;
    }
    else {
      param_2 = param_2 << 3;
    }
    local_20 = param_2 + ((ulong)(param_1[1] - local_30) >> 1) * 8 + *param_1;
    if (local_20 < (ulong)param_1[5]) {
      FUN_00b1baf8(param_1[5],param_1[9] + 8,local_20);
    }
    else {
      FUN_00b1bb44(param_1[5],param_1[9] + 8,local_28 * 8 + local_20);
    }
  }
  else {
    lVar2 = param_1[1];
    plVar1 = (long *)FUN_00b06d34(param_1 + 1,&local_58);
    local_38 = *plVar1 + lVar2 + 2;
    local_40 = FUN_00b13132(local_50,local_38);
    if (param_3 == '\0') {
      lVar2 = 0;
    }
    else {
      lVar2 = local_58 << 3;
    }
    local_20 = local_40 + ((ulong)(local_38 - local_30) >> 1) * 8 + lVar2;
    FUN_00b1baf8(local_50[5],local_50[9] + 8,local_20);
    FUN_00b10db8(local_50,*local_50,local_50[1]);
    *local_50 = local_40;
    local_50[1] = local_38;
  }
  FUN_00b13224(local_50 + 2,local_20);
  FUN_00b13224(local_50 + 6,local_20 + local_28 * 8 + -8);
  return;
}


// ==== entry=00b1baf8 name=FUN_00b1baf8 size=76 ====

void FUN_00b1baf8(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  undefined8 uVar1;
  undefined8 uVar2;
  
  uVar1 = FUN_00b1bb90(param_2);
  uVar2 = FUN_00b1bb90(param_1);
  FUN_00b1bb9e(uVar2,uVar1,param_3);
  return;
}


// ==== entry=00b1bb44 name=FUN_00b1bb44 size=76 ====

void FUN_00b1bb44(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  undefined8 uVar1;
  undefined8 uVar2;
  
  uVar1 = FUN_00b1bb90(param_2);
  uVar2 = FUN_00b1bb90(param_1);
  FUN_00b1bbf6(uVar2,uVar1,param_3);
  return;
}


// ==== entry=00b1bb90 name=FUN_00b1bb90 size=14 ====

undefined8 FUN_00b1bb90(undefined8 param_1)

{
  return param_1;
}


// ==== entry=00b1bb9e name=FUN_00b1bb9e size=88 ====

void FUN_00b1bb9e(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  
  uVar1 = FUN_00b1bc4e(param_3);
  uVar2 = FUN_00b1bc4e(param_2);
  uVar3 = FUN_00b1bc4e(param_1);
  FUN_00b1bc5c(uVar3,uVar2,uVar1);
  return;
}


// ==== entry=00b1bbf6 name=FUN_00b1bbf6 size=88 ====

void FUN_00b1bbf6(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  
  uVar1 = FUN_00b1bc4e(param_3);
  uVar2 = FUN_00b1bc4e(param_2);
  uVar3 = FUN_00b1bc4e(param_1);
  FUN_00b1bc8d(uVar3,uVar2,uVar1);
  return;
}


// ==== entry=00b1bc4e name=FUN_00b1bc4e size=14 ====

undefined8 FUN_00b1bc4e(undefined8 param_1)

{
  return param_1;
}


// ==== entry=00b1bc5c name=FUN_00b1bc5c size=49 ====

void FUN_00b1bc5c(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  FUN_00b1bcbe(param_1,param_2,param_3);
  return;
}


// ==== entry=00b1bc8d name=FUN_00b1bc8d size=49 ====

void FUN_00b1bc8d(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  FUN_00b1bd1d(param_1,param_2,param_3);
  return;
}


// ==== entry=00b1bcbe name=FUN_00b1bcbe size=95 ====

void * FUN_00b1bcbe(void *param_1,long param_2,void *param_3)

{
  long lVar1;
  
  lVar1 = param_2 - (long)param_1 >> 3;
  if (lVar1 != 0) {
    memmove(param_3,param_1,lVar1 * 8);
  }
  return (void *)((long)param_3 + lVar1 * 8);
}


// ==== entry=00b1bd1d name=FUN_00b1bd1d size=114 ====

long FUN_00b1bd1d(void *param_1,long param_2,long param_3)

{
  long lVar1;
  
  lVar1 = param_2 - (long)param_1 >> 3;
  if (lVar1 != 0) {
    memmove((void *)(lVar1 * -8 + param_3),param_1,lVar1 * 8);
  }
  return param_3 + lVar1 * -8;
}


// ==== entry=00b1bd90 name=FUN_00b1bd90 size=195 ====

void FUN_00b1bd90(undefined4 *param_1,undefined8 param_2,undefined8 param_3)

{
  void *pvVar1;
  
  *param_1 = 0;
  *(undefined8 *)(param_1 + 2) = param_2;
  *(undefined8 *)(param_1 + 4) = param_3;
  pvVar1 = operator_new(0x50);
                    /* try { // try from 00b1bde1 to 00b1bde5 has its CatchHandler @ 00b1be4a */
  FUN_00b1e466(pvVar1);
  FUN_00b1e6c4(param_1 + 6,pvVar1);
  param_1[10] = 0;
  *(undefined8 *)(param_1 + 0xc) = 0;
  *(undefined8 *)(param_1 + 0xe) = 0;
  *(undefined8 *)(param_1 + 0x10) = 0;
  *(undefined8 *)(param_1 + 0x12) = 0;
  FUN_00b1e55c(param_1 + 8);
  *(undefined8 *)(param_1 + 0x14) = 0;
  return;
}


// ==== entry=00b1be6a name=FUN_00b1be6a size=47 ====

void FUN_00b1be6a(long param_1)

{
  FUN_00b1e578(param_1 + 0x20);
  FUN_00b1e6ea(param_1 + 0x18);
  return;
}


// ==== entry=00b1be9a name=FUN_00b1be9a size=325 ====

void FUN_00b1be9a(long param_1,long *param_2)

{
  code *pcVar1;
  bool bVar2;
  char cVar3;
  long lVar4;
  
  cVar3 = FUN_00b0c0ba(*(undefined8 *)(param_1 + 8));
  if (cVar3 == '\x01') {
                    /* WARNING: Subroutine does not return */
    __assert_fail("!m_scanner.empty()",
                  "/mnt/hgfs/Develop/Library/yaml-cpp-0.7.0/src/singledocparser.cpp",0x1f,
                  "void YAML::SingleDocParser::HandleDocument(YAML::EventHandler&)");
  }
  if (*(long *)(param_1 + 0x50) != 0) {
                    /* WARNING: Subroutine does not return */
    __assert_fail("!m_curAnchor","/mnt/hgfs/Develop/Library/yaml-cpp-0.7.0/src/singledocparser.cpp",
                  0x20,"void YAML::SingleDocParser::HandleDocument(YAML::EventHandler&)");
  }
  pcVar1 = *(code **)(*param_2 + 0x10);
  lVar4 = FUN_00b0c126(*(undefined8 *)(param_1 + 8));
  (*pcVar1)(param_2,lVar4 + 8);
  lVar4 = FUN_00b0c126(*(undefined8 *)(param_1 + 8));
  if (*(int *)(lVar4 + 4) == 1) {
    FUN_00b0c0e4(*(undefined8 *)(param_1 + 8));
  }
  FUN_00b1bfe0(param_1,param_2);
  (**(code **)(*param_2 + 0x18))(param_2);
  do {
    cVar3 = FUN_00b0c0ba(*(undefined8 *)(param_1 + 8));
    if (cVar3 == '\x01') {
LAB_00b1bfbc:
      bVar2 = false;
    }
    else {
      lVar4 = FUN_00b0c126(*(undefined8 *)(param_1 + 8));
      if (*(int *)(lVar4 + 4) != 2) goto LAB_00b1bfbc;
      bVar2 = true;
    }
    if (!bVar2) {
      return;
    }
    FUN_00b0c0e4(*(undefined8 *)(param_1 + 8));
  } while( true );
}


// ==== entry=00b1bfe0 name=FUN_00b1bfe0 size=2018 ====

void FUN_00b1bfe0(long param_1,long *param_2)

{
  code *pcVar1;
  bool bVar2;
  char cVar3;
  int iVar4;
  long lVar5;
  undefined8 uVar6;
  char *pcVar7;
  undefined8 local_98;
  string local_90 [8];
  string local_88 [12];
  undefined8 local_7c;
  undefined4 local_74;
  undefined1 local_70 [8];
  string local_68 [15];
  allocator local_59;
  undefined1 local_58 [12];
  undefined1 local_4c [12];
  string local_40 [15];
  allocator local_31;
  string local_30 [15];
  allocator local_21;
  long local_20;
  
  std::allocator<char>::allocator();
                    /* try { // try from 00b1c016 to 00b1c01a has its CatchHandler @ 00b1c7c9 */
  std::string::string(local_68,"bad file",&local_59);
                    /* try { // try from 00b1c029 to 00b1c057 has its CatchHandler @ 00b1c7b8 */
  local_58 = FUN_00b0c180(*(undefined8 *)(param_1 + 8));
  FUN_00b1e81e(local_70,param_1,local_58,local_68);
  std::string::~string(local_68);
  std::allocator<char>::~allocator((allocator<char> *)&local_59);
                    /* try { // try from 00b1c07e to 00b1c10f has its CatchHandler @ 00b1c84c */
  cVar3 = FUN_00b0c0ba(*(undefined8 *)(param_1 + 8));
  if (cVar3 != '\0') {
    pcVar1 = *(code **)(*param_2 + 0x20);
    local_4c = FUN_00b0c180(*(undefined8 *)(param_1 + 8));
    (*pcVar1)(param_2,local_4c,0);
    goto LAB_00b1c7a4;
  }
  lVar5 = FUN_00b0c126(*(undefined8 *)(param_1 + 8));
  local_7c = *(undefined8 *)(lVar5 + 8);
  local_74 = *(undefined4 *)(lVar5 + 0x10);
  lVar5 = FUN_00b0c126(*(undefined8 *)(param_1 + 8));
  if (*(int *)(lVar5 + 4) == 0xf) {
    pcVar1 = *(code **)(*param_2 + 0x48);
    std::allocator<char>::allocator();
                    /* try { // try from 00b1c14e to 00b1c152 has its CatchHandler @ 00b1c7f4 */
    std::string::string(local_40,"?",&local_31);
                    /* try { // try from 00b1c170 to 00b1c171 has its CatchHandler @ 00b1c7e3 */
    (*pcVar1)(param_2,&local_7c,local_40,0,0);
    std::string::~string(local_40);
    std::allocator<char>::~allocator((allocator<char> *)&local_31);
                    /* try { // try from 00b1c19e to 00b1c266 has its CatchHandler @ 00b1c84c */
    FUN_00b1cf22(param_1,param_2);
    (**(code **)(*param_2 + 0x50))(param_2);
    goto LAB_00b1c7a4;
  }
  lVar5 = FUN_00b0c126(*(undefined8 *)(param_1 + 8));
  if (*(int *)(lVar5 + 4) == 0x11) {
    pcVar1 = *(code **)(*param_2 + 0x28);
    lVar5 = FUN_00b0c126(*(undefined8 *)(param_1 + 8));
    uVar6 = FUN_00b1dcc6(param_1,&local_7c,lVar5 + 0x18);
    (*pcVar1)(param_2,&local_7c,uVar6);
    FUN_00b0c0e4(*(undefined8 *)(param_1 + 8));
    goto LAB_00b1c7a4;
  }
  std::string::string(local_88);
                    /* try { // try from 00b1c271 to 00b1c275 has its CatchHandler @ 00b1c83b */
  std::string::string(local_90);
                    /* try { // try from 00b1c292 to 00b1c6f3 has its CatchHandler @ 00b1c827 */
  FUN_00b1d914(param_1,local_88,&local_98,local_90);
  cVar3 = std::string::empty(local_90);
  if (cVar3 != '\x01') {
    (**(code **)(*param_2 + 0x58))(param_2,&local_7c,local_90);
  }
  cVar3 = FUN_00b0c0ba(*(undefined8 *)(param_1 + 8));
  if (cVar3 == '\0') {
    local_20 = FUN_00b0c126(*(undefined8 *)(param_1 + 8));
    cVar3 = std::string::empty(local_88);
    if (cVar3 != '\0') {
      if (*(int *)(local_20 + 4) == 0x14) {
        pcVar7 = "!";
      }
      else {
        pcVar7 = "?";
      }
      std::string::operator=(local_88,pcVar7);
    }
    if (*(int *)(local_20 + 4) == 0x13) {
      iVar4 = std::string::compare(local_88,"?");
      if (iVar4 != 0) goto LAB_00b1c3a8;
      cVar3 = FUN_00b26b21(local_20 + 0x18);
      if (cVar3 == '\0') goto LAB_00b1c3a8;
      bVar2 = true;
    }
    else {
LAB_00b1c3a8:
      bVar2 = false;
    }
    if (bVar2) {
      (**(code **)(*param_2 + 0x20))(param_2,&local_7c,local_98);
      FUN_00b0c0e4(*(undefined8 *)(param_1 + 8));
    }
    else {
      switch(*(undefined4 *)(local_20 + 4)) {
      case 3:
        (**(code **)(*param_2 + 0x38))(param_2,&local_7c,local_88,local_98,1);
        FUN_00b1c870(param_1,param_2);
        (**(code **)(*param_2 + 0x40))(param_2);
        break;
      case 4:
        (**(code **)(*param_2 + 0x48))(param_2,&local_7c,local_88,local_98,1);
        FUN_00b1cf22(param_1,param_2);
        (**(code **)(*param_2 + 0x50))(param_2);
        break;
      default:
LAB_00b1c6b7:
        cVar3 = FUN_00b0a358(local_88,&DAT_00d3dd61);
        if (cVar3 == '\0') {
          pcVar1 = *(code **)(*param_2 + 0x30);
          std::allocator<char>::allocator();
                    /* try { // try from 00b1c723 to 00b1c727 has its CatchHandler @ 00b1c816 */
          std::string::string(local_30,"",&local_21);
                    /* try { // try from 00b1c748 to 00b1c749 has its CatchHandler @ 00b1c805 */
          (*pcVar1)(param_2,&local_7c,local_88,local_98,local_30);
          std::string::~string(local_30);
          std::allocator<char>::~allocator((allocator<char> *)&local_21);
        }
        else {
          (**(code **)(*param_2 + 0x20))(param_2,&local_7c,local_98);
        }
        break;
      case 8:
        (**(code **)(*param_2 + 0x38))(param_2,&local_7c,local_88,local_98,2);
        FUN_00b1c870(param_1,param_2);
        (**(code **)(*param_2 + 0x40))(param_2);
        break;
      case 9:
        (**(code **)(*param_2 + 0x48))(param_2,&local_7c,local_88,local_98,2);
        FUN_00b1cf22(param_1,param_2);
        (**(code **)(*param_2 + 0x50))(param_2);
        break;
      case 0xe:
        uVar6 = FUN_00b1e8d6(param_1 + 0x18);
        iVar4 = FUN_00b1e482(uVar6);
        if (iVar4 != 4) goto LAB_00b1c6b7;
        (**(code **)(*param_2 + 0x48))(param_2,&local_7c,local_88,local_98,2);
        FUN_00b1cf22(param_1,param_2);
        (**(code **)(*param_2 + 0x50))(param_2);
        break;
      case 0x13:
      case 0x14:
        (**(code **)(*param_2 + 0x30))(param_2,&local_7c,local_88,local_98,local_20 + 0x18);
        FUN_00b0c0e4(*(undefined8 *)(param_1 + 8));
      }
    }
  }
  else {
    (**(code **)(*param_2 + 0x20))(param_2,&local_7c,local_98);
  }
  std::string::~string(local_90);
  std::string::~string(local_88);
LAB_00b1c7a4:
  FUN_00b1e8bc(local_70);
  return;
}


// ==== entry=00b1c870 name=FUN_00b1c870 size=91 ====

void FUN_00b1c870(long param_1,undefined8 param_2)

{
  long lVar1;
  
  lVar1 = FUN_00b0c126(*(undefined8 *)(param_1 + 8));
  if (*(int *)(lVar1 + 4) == 3) {
    FUN_00b1c8cc(param_1,param_2);
  }
  else if (*(int *)(lVar1 + 4) == 8) {
    FUN_00b1cbe2(param_1,param_2);
  }
  return;
}


// ==== entry=00b1c8cc name=FUN_00b1c8cc size=667 ====

void FUN_00b1c8cc(long param_1,long *param_2)

{
  char cVar1;
  undefined8 uVar2;
  int iVar3;
  undefined1 local_88 [4];
  int local_84;
  undefined1 local_80 [56];
  string local_48 [11];
  allocator local_3d;
  undefined1 local_3c [12];
  string local_30 [15];
  allocator local_21;
  long local_20;
  
  FUN_00b0c0e4(*(undefined8 *)(param_1 + 8));
  uVar2 = FUN_00b1e8d6(param_1 + 0x18);
  FUN_00b1e4b6(uVar2,2);
  while( true ) {
    cVar1 = FUN_00b0c0ba(*(undefined8 *)(param_1 + 8));
    if (cVar1 != '\0') {
      uVar2 = __cxa_allocate_exception(0x28);
      std::allocator<char>::allocator();
                    /* try { // try from 00b1c95c to 00b1c960 has its CatchHandler @ 00b1cb6f */
      std::string::string(local_48,"end of sequence not found",&local_3d);
                    /* try { // try from 00b1c96f to 00b1c995 has its CatchHandler @ 00b1cb5e */
      local_3c = FUN_00b0c180(*(undefined8 *)(param_1 + 8));
      FUN_00b09fc4(uVar2,local_3c,local_48);
      std::string::~string(local_48);
      std::allocator<char>::~allocator((allocator<char> *)&local_3d);
                    /* WARNING: Subroutine does not return */
      __cxa_throw(uVar2,&PTR_PTR_00d39ce8,FUN_00b009e6);
    }
    uVar2 = FUN_00b0c126(*(undefined8 *)(param_1 + 8));
    FUN_00b19942(local_88,uVar2);
    if ((local_84 != 7) && (local_84 != 5)) break;
    FUN_00b0c0e4(*(undefined8 *)(param_1 + 8));
    if (local_84 == 5) {
      iVar3 = 0;
    }
    else {
      cVar1 = FUN_00b0c0ba(*(undefined8 *)(param_1 + 8));
      if ((cVar1 == '\x01') ||
         ((local_20 = FUN_00b0c126(*(undefined8 *)(param_1 + 8)), *(int *)(local_20 + 4) != 7 &&
          (*(int *)(local_20 + 4) != 5)))) {
        FUN_00b1bfe0(param_1,param_2);
        iVar3 = 2;
      }
      else {
        (**(code **)(*param_2 + 0x20))(param_2,local_20 + 8,0);
        iVar3 = 1;
      }
    }
    FUN_00b0eed8(local_88);
    if (iVar3 == 0) {
      uVar2 = FUN_00b1e8d6(param_1 + 0x18);
      FUN_00b1e4dc(uVar2,2);
      return;
    }
  }
  uVar2 = __cxa_allocate_exception(0x28);
  std::allocator<char>::allocator();
                    /* try { // try from 00b1ca1e to 00b1ca22 has its CatchHandler @ 00b1cba2 */
  std::string::string(local_30,"end of sequence not found",&local_21);
                    /* try { // try from 00b1ca38 to 00b1ca3c has its CatchHandler @ 00b1cb91 */
  FUN_00b09fc4(uVar2,local_80,local_30);
  std::string::~string(local_30);
  std::allocator<char>::~allocator((allocator<char> *)&local_21);
                    /* WARNING: Subroutine does not return */
                    /* try { // try from 00b1ca62 to 00b1cb1e has its CatchHandler @ 00b1cbbe */
  __cxa_throw(uVar2,&PTR_PTR_00d39ce8,FUN_00b009e6);
}


// ==== entry=00b1cbe2 name=FUN_00b1cbe2 size=679 ====

void FUN_00b1cbe2(long param_1,undefined8 param_2)

{
  char cVar1;
  undefined8 uVar2;
  long lVar3;
  string local_60 [11];
  allocator local_55;
  undefined1 local_54 [12];
  string local_48 [11];
  allocator local_3d;
  undefined1 local_3c [12];
  string local_30 [15];
  allocator local_21;
  long local_20;
  
  FUN_00b0c0e4(*(undefined8 *)(param_1 + 8));
  uVar2 = FUN_00b1e8d6(param_1 + 0x18);
  FUN_00b1e4b6(uVar2,4);
  while( true ) {
    cVar1 = FUN_00b0c0ba(*(undefined8 *)(param_1 + 8));
    if (cVar1 != '\0') {
      uVar2 = __cxa_allocate_exception(0x28);
      std::allocator<char>::allocator();
                    /* try { // try from 00b1cc63 to 00b1cc67 has its CatchHandler @ 00b1ce91 */
      std::string::string(local_60,"end of sequence flow not found",&local_55);
                    /* try { // try from 00b1cc73 to 00b1cc99 has its CatchHandler @ 00b1ce80 */
      local_54 = FUN_00b0c180(*(undefined8 *)(param_1 + 8));
      FUN_00b09fc4(uVar2,local_54,local_60);
      std::string::~string(local_60);
      std::allocator<char>::~allocator((allocator<char> *)&local_55);
                    /* WARNING: Subroutine does not return */
      __cxa_throw(uVar2,&PTR_PTR_00d39ce8,FUN_00b009e6);
    }
    lVar3 = FUN_00b0c126(*(undefined8 *)(param_1 + 8));
    if (*(int *)(lVar3 + 4) == 10) break;
    FUN_00b1bfe0(param_1,param_2);
    cVar1 = FUN_00b0c0ba(*(undefined8 *)(param_1 + 8));
    if (cVar1 != '\0') {
      uVar2 = __cxa_allocate_exception(0x28);
      std::allocator<char>::allocator();
                    /* try { // try from 00b1cd68 to 00b1cd6c has its CatchHandler @ 00b1cec4 */
      std::string::string(local_48,"end of sequence flow not found",&local_3d);
                    /* try { // try from 00b1cd78 to 00b1cd9e has its CatchHandler @ 00b1ceb3 */
      local_3c = FUN_00b0c180(*(undefined8 *)(param_1 + 8));
      FUN_00b09fc4(uVar2,local_3c,local_48);
      std::string::~string(local_48);
      std::allocator<char>::~allocator((allocator<char> *)&local_3d);
                    /* WARNING: Subroutine does not return */
      __cxa_throw(uVar2,&PTR_PTR_00d39ce8,FUN_00b009e6);
    }
    local_20 = FUN_00b0c126(*(undefined8 *)(param_1 + 8));
    if (*(int *)(local_20 + 4) == 0xd) {
      FUN_00b0c0e4(*(undefined8 *)(param_1 + 8));
    }
    else if (*(int *)(local_20 + 4) != 10) {
      uVar2 = __cxa_allocate_exception(0x28);
      std::allocator<char>::allocator();
                    /* try { // try from 00b1ce37 to 00b1ce3b has its CatchHandler @ 00b1cef7 */
      std::string::string(local_30,"end of sequence flow not found",&local_21);
                    /* try { // try from 00b1ce51 to 00b1ce55 has its CatchHandler @ 00b1cee6 */
      FUN_00b09fc4(uVar2,local_20 + 8,local_30);
      std::string::~string(local_30);
      std::allocator<char>::~allocator((allocator<char> *)&local_21);
                    /* WARNING: Subroutine does not return */
      __cxa_throw(uVar2,&PTR_PTR_00d39ce8,FUN_00b009e6);
    }
  }
  FUN_00b0c0e4(*(undefined8 *)(param_1 + 8));
  uVar2 = FUN_00b1e8d6(param_1 + 0x18);
  FUN_00b1e4dc(uVar2,4);
  return;
}


// ==== entry=00b1cf22 name=FUN_00b1cf22 size=150 ====

void FUN_00b1cf22(long param_1,undefined8 param_2)

{
  int iVar1;
  long lVar2;
  
  lVar2 = FUN_00b0c126(*(undefined8 *)(param_1 + 8));
  iVar1 = *(int *)(lVar2 + 4);
  if (iVar1 == 9) {
    FUN_00b1d342(param_1,param_2);
  }
  else if (iVar1 < 10) {
    if (iVar1 == 4) {
      FUN_00b1cfb8(param_1,param_2);
    }
  }
  else if (iVar1 == 0xe) {
    FUN_00b1d758(param_1,param_2);
  }
  else if (iVar1 == 0xf) {
    FUN_00b1d86a(param_1,param_2);
  }
  return;
}


// ==== entry=00b1cfb8 name=FUN_00b1cfb8 size=783 ====

void FUN_00b1cfb8(long param_1,long *param_2)

{
  bool bVar1;
  char cVar2;
  undefined8 uVar3;
  long lVar4;
  undefined1 local_88 [4];
  int local_84;
  undefined1 local_80 [64];
  string local_40 [11];
  allocator local_35;
  undefined1 local_34 [12];
  string local_28 [15];
  allocator local_19;
  
  FUN_00b0c0e4(*(undefined8 *)(param_1 + 8));
  uVar3 = FUN_00b1e8d6(param_1 + 0x18);
  FUN_00b1e4b6(uVar3,1);
  while( true ) {
    cVar2 = FUN_00b0c0ba(*(undefined8 *)(param_1 + 8));
    if (cVar2 != '\0') {
      uVar3 = __cxa_allocate_exception(0x28);
      std::allocator<char>::allocator();
                    /* try { // try from 00b1d048 to 00b1d04c has its CatchHandler @ 00b1d2cf */
      std::string::string(local_40,"end of map not found",&local_35);
                    /* try { // try from 00b1d05b to 00b1d081 has its CatchHandler @ 00b1d2be */
      local_34 = FUN_00b0c180(*(undefined8 *)(param_1 + 8));
      FUN_00b09fc4(uVar3,local_34,local_40);
      std::string::~string(local_40);
      std::allocator<char>::~allocator((allocator<char> *)&local_35);
                    /* WARNING: Subroutine does not return */
      __cxa_throw(uVar3,&PTR_PTR_00d39ce8,FUN_00b009e6);
    }
    uVar3 = FUN_00b0c126(*(undefined8 *)(param_1 + 8));
    FUN_00b19942(local_88,uVar3);
    if (((local_84 != 0xe) && (local_84 != 0xf)) && (local_84 != 6)) break;
    if (local_84 == 6) {
      FUN_00b0c0e4(*(undefined8 *)(param_1 + 8));
      bVar1 = false;
    }
    else {
      if (local_84 == 0xe) {
        FUN_00b0c0e4(*(undefined8 *)(param_1 + 8));
        FUN_00b1bfe0(param_1,param_2);
      }
      else {
        (**(code **)(*param_2 + 0x20))(param_2,local_80,0);
      }
      cVar2 = FUN_00b0c0ba(*(undefined8 *)(param_1 + 8));
      if ((cVar2 == '\x01') ||
         (lVar4 = FUN_00b0c126(*(undefined8 *)(param_1 + 8)), *(int *)(lVar4 + 4) != 0xf)) {
        bVar1 = false;
      }
      else {
        bVar1 = true;
      }
      if (bVar1) {
        FUN_00b0c0e4(*(undefined8 *)(param_1 + 8));
        FUN_00b1bfe0(param_1,param_2);
      }
      else {
        (**(code **)(*param_2 + 0x20))(param_2,local_80,0);
      }
      bVar1 = true;
    }
    FUN_00b0eed8(local_88);
    if (!bVar1) {
      uVar3 = FUN_00b1e8d6(param_1 + 0x18);
      FUN_00b1e4dc(uVar3,1);
      return;
    }
  }
  uVar3 = __cxa_allocate_exception(0x28);
  std::allocator<char>::allocator();
                    /* try { // try from 00b1d116 to 00b1d11a has its CatchHandler @ 00b1d302 */
  std::string::string(local_28,"end of map not found",&local_19);
                    /* try { // try from 00b1d130 to 00b1d134 has its CatchHandler @ 00b1d2f1 */
  FUN_00b09fc4(uVar3,local_80,local_28);
  std::string::~string(local_28);
  std::allocator<char>::~allocator((allocator<char> *)&local_19);
                    /* WARNING: Subroutine does not return */
                    /* try { // try from 00b1d15a to 00b1d280 has its CatchHandler @ 00b1d31e */
  __cxa_throw(uVar3,&PTR_PTR_00d39ce8,FUN_00b009e6);
}


// ==== entry=00b1d342 name=FUN_00b1d342 size=893 ====

void FUN_00b1d342(long param_1,long *param_2)

{
  bool bVar1;
  char cVar2;
  undefined8 uVar3;
  long lVar4;
  undefined8 local_74;
  undefined4 local_6c;
  string local_68 [11];
  allocator local_5d;
  undefined1 local_5c [12];
  string local_50 [11];
  allocator local_45;
  undefined1 local_44 [12];
  string local_38 [15];
  allocator local_29;
  long local_28;
  long local_20;
  
  FUN_00b0c0e4(*(undefined8 *)(param_1 + 8));
  uVar3 = FUN_00b1e8d6(param_1 + 0x18);
  FUN_00b1e4b6(uVar3,3);
  do {
    cVar2 = FUN_00b0c0ba(*(undefined8 *)(param_1 + 8));
    if (cVar2 != '\0') {
      uVar3 = __cxa_allocate_exception(0x28);
      std::allocator<char>::allocator();
                    /* try { // try from 00b1d3c3 to 00b1d3c7 has its CatchHandler @ 00b1d6c7 */
      std::string::string(local_68,"end of map flow not found",&local_5d);
                    /* try { // try from 00b1d3d3 to 00b1d3f9 has its CatchHandler @ 00b1d6b6 */
      local_5c = FUN_00b0c180(*(undefined8 *)(param_1 + 8));
      FUN_00b09fc4(uVar3,local_5c,local_68);
      std::string::~string(local_68);
      std::allocator<char>::~allocator((allocator<char> *)&local_5d);
                    /* WARNING: Subroutine does not return */
      __cxa_throw(uVar3,&PTR_PTR_00d39ce8,FUN_00b009e6);
    }
    local_20 = FUN_00b0c126(*(undefined8 *)(param_1 + 8));
    local_74 = *(undefined8 *)(local_20 + 8);
    local_6c = *(undefined4 *)(local_20 + 0x10);
    if (*(int *)(local_20 + 4) == 0xb) {
      FUN_00b0c0e4(*(undefined8 *)(param_1 + 8));
      uVar3 = FUN_00b1e8d6(param_1 + 0x18);
      FUN_00b1e4dc(uVar3,3);
      return;
    }
    if (*(int *)(local_20 + 4) == 0xe) {
      FUN_00b0c0e4(*(undefined8 *)(param_1 + 8));
      FUN_00b1bfe0(param_1,param_2);
    }
    else {
      (**(code **)(*param_2 + 0x20))(param_2,&local_74,0);
    }
    cVar2 = FUN_00b0c0ba(*(undefined8 *)(param_1 + 8));
    if (cVar2 == '\x01') {
LAB_00b1d50f:
      bVar1 = false;
    }
    else {
      lVar4 = FUN_00b0c126(*(undefined8 *)(param_1 + 8));
      if (*(int *)(lVar4 + 4) != 0xf) goto LAB_00b1d50f;
      bVar1 = true;
    }
    if (bVar1) {
      FUN_00b0c0e4(*(undefined8 *)(param_1 + 8));
      FUN_00b1bfe0(param_1,param_2);
    }
    else {
      (**(code **)(*param_2 + 0x20))(param_2,&local_74,0);
    }
    cVar2 = FUN_00b0c0ba(*(undefined8 *)(param_1 + 8));
    if (cVar2 != '\0') {
      uVar3 = __cxa_allocate_exception(0x28);
      std::allocator<char>::allocator();
                    /* try { // try from 00b1d59e to 00b1d5a2 has its CatchHandler @ 00b1d6fa */
      std::string::string(local_50,"end of map flow not found",&local_45);
                    /* try { // try from 00b1d5ae to 00b1d5d4 has its CatchHandler @ 00b1d6e9 */
      local_44 = FUN_00b0c180(*(undefined8 *)(param_1 + 8));
      FUN_00b09fc4(uVar3,local_44,local_50);
      std::string::~string(local_50);
      std::allocator<char>::~allocator((allocator<char> *)&local_45);
                    /* WARNING: Subroutine does not return */
      __cxa_throw(uVar3,&PTR_PTR_00d39ce8,FUN_00b009e6);
    }
    local_28 = FUN_00b0c126(*(undefined8 *)(param_1 + 8));
    if (*(int *)(local_28 + 4) == 0xd) {
      FUN_00b0c0e4(*(undefined8 *)(param_1 + 8));
    }
    else if (*(int *)(local_28 + 4) != 0xb) {
      uVar3 = __cxa_allocate_exception(0x28);
      std::allocator<char>::allocator();
                    /* try { // try from 00b1d66d to 00b1d671 has its CatchHandler @ 00b1d72d */
      std::string::string(local_38,"end of map flow not found",&local_29);
                    /* try { // try from 00b1d687 to 00b1d68b has its CatchHandler @ 00b1d71c */
      FUN_00b09fc4(uVar3,local_28 + 8,local_38);
      std::string::~string(local_38);
      std::allocator<char>::~allocator((allocator<char> *)&local_29);
                    /* WARNING: Subroutine does not return */
      __cxa_throw(uVar3,&PTR_PTR_00d39ce8,FUN_00b009e6);
    }
  } while( true );
}


// ==== entry=00b1d758 name=FUN_00b1d758 size=274 ====

void FUN_00b1d758(long param_1,long *param_2)

{
  bool bVar1;
  char cVar2;
  undefined8 uVar3;
  long lVar4;
  undefined8 local_14;
  undefined4 local_c;
  
  uVar3 = FUN_00b1e8d6(param_1 + 0x18);
  FUN_00b1e4b6(uVar3,5);
  lVar4 = FUN_00b0c126(*(undefined8 *)(param_1 + 8));
  local_14 = *(undefined8 *)(lVar4 + 8);
  local_c = *(undefined4 *)(lVar4 + 0x10);
  FUN_00b0c0e4(*(undefined8 *)(param_1 + 8));
  FUN_00b1bfe0(param_1,param_2);
  cVar2 = FUN_00b0c0ba(*(undefined8 *)(param_1 + 8));
  if (cVar2 != '\x01') {
    lVar4 = FUN_00b0c126(*(undefined8 *)(param_1 + 8));
    if (*(int *)(lVar4 + 4) == 0xf) {
      bVar1 = true;
      goto LAB_00b1d801;
    }
  }
  bVar1 = false;
LAB_00b1d801:
  if (bVar1) {
    FUN_00b0c0e4(*(undefined8 *)(param_1 + 8));
    FUN_00b1bfe0(param_1,param_2);
  }
  else {
    (**(code **)(*param_2 + 0x20))(param_2,&local_14,0);
  }
  uVar3 = FUN_00b1e8d6(param_1 + 0x18);
  FUN_00b1e4dc(uVar3,5);
  return;
}


// ==== entry=00b1d86a name=FUN_00b1d86a size=169 ====

void FUN_00b1d86a(long param_1,long *param_2)

{
  code *pcVar1;
  undefined8 uVar2;
  long lVar3;
  
  uVar2 = FUN_00b1e8d6(param_1 + 0x18);
  FUN_00b1e4b6(uVar2,5);
  pcVar1 = *(code **)(*param_2 + 0x20);
  lVar3 = FUN_00b0c126(*(undefined8 *)(param_1 + 8));
  (*pcVar1)(param_2,lVar3 + 8,0);
  FUN_00b0c0e4(*(undefined8 *)(param_1 + 8));
  FUN_00b1bfe0(param_1,param_2);
  uVar2 = FUN_00b1e8d6(param_1 + 0x18);
  FUN_00b1e4dc(uVar2,5);
  return;
}


// ==== entry=00b1d914 name=FUN_00b1d914 size=161 ====

void FUN_00b1d914(long param_1,string *param_2,undefined8 *param_3,string *param_4)

{
  char cVar1;
  long lVar2;
  
  std::string::clear(param_2);
  std::string::clear(param_4);
  *param_3 = 0;
  while( true ) {
    while( true ) {
      cVar1 = FUN_00b0c0ba(*(undefined8 *)(param_1 + 8));
      if (cVar1 != '\0') {
        return;
      }
      lVar2 = FUN_00b0c126(*(undefined8 *)(param_1 + 8));
      if (*(int *)(lVar2 + 4) != 0x10) break;
      FUN_00b1db34(param_1,param_3,param_4);
    }
    if (*(int *)(lVar2 + 4) != 0x12) break;
    FUN_00b1d9b6(param_1,param_2);
  }
  return;
}


// ==== entry=00b1d9b6 name=FUN_00b1d9b6 size=288 ====

void FUN_00b1d9b6(long param_1,string *param_2)

{
  char cVar1;
  undefined8 uVar2;
  undefined1 local_58 [32];
  string local_38 [15];
  allocator local_29;
  string local_28 [8];
  long local_20;
  
  local_20 = FUN_00b0c126(*(undefined8 *)(param_1 + 8));
  cVar1 = std::string::empty(param_2);
  if (cVar1 != '\x01') {
    uVar2 = __cxa_allocate_exception(0x28);
    std::allocator<char>::allocator();
                    /* try { // try from 00b1da19 to 00b1da1d has its CatchHandler @ 00b1dade */
    std::string::string(local_38,"cannot assign multiple tags to the same node",&local_29);
                    /* try { // try from 00b1da33 to 00b1da37 has its CatchHandler @ 00b1dacd */
    FUN_00b09fc4(uVar2,local_20 + 8,local_38);
    std::string::~string(local_38);
    std::allocator<char>::~allocator((allocator<char> *)&local_29);
                    /* WARNING: Subroutine does not return */
    __cxa_throw(uVar2,&PTR_PTR_00d39ce8,FUN_00b009e6);
  }
  FUN_00b231b6(local_58,local_20);
                    /* try { // try from 00b1da8b to 00b1da8f has its CatchHandler @ 00b1db11 */
  FUN_00b2330a(local_28,local_58,*(undefined8 *)(param_1 + 0x10));
                    /* try { // try from 00b1da9e to 00b1daa2 has its CatchHandler @ 00b1db00 */
  std::string::operator=(param_2,local_28);
  std::string::~string(local_28);
                    /* try { // try from 00b1daba to 00b1dabe has its CatchHandler @ 00b1db11 */
  FUN_00b0c0e4(*(undefined8 *)(param_1 + 8));
  FUN_00b1e594(local_58);
  return;
}


// ==== entry=00b1db34 name=FUN_00b1db34 size=252 ====

void FUN_00b1db34(long param_1,long *param_2,string *param_3)

{
  undefined8 uVar1;
  long lVar2;
  string local_30 [15];
  allocator local_21;
  long local_20;
  
  local_20 = FUN_00b0c126(*(undefined8 *)(param_1 + 8));
  if (*param_2 != 0) {
    uVar1 = __cxa_allocate_exception(0x28);
    std::allocator<char>::allocator();
                    /* try { // try from 00b1db94 to 00b1db98 has its CatchHandler @ 00b1dc38 */
    std::string::string(local_30,"cannot assign multiple anchors to the same node",&local_21);
                    /* try { // try from 00b1dbae to 00b1dbb2 has its CatchHandler @ 00b1dc27 */
    FUN_00b09fc4(uVar1,local_20 + 8,local_30);
    std::string::~string(local_30);
    std::allocator<char>::~allocator((allocator<char> *)&local_21);
                    /* WARNING: Subroutine does not return */
    __cxa_throw(uVar1,&PTR_PTR_00d39ce8,FUN_00b009e6);
  }
  std::string::operator=(param_3,(string *)(local_20 + 0x18));
  lVar2 = FUN_00b1dc64(param_1,local_20 + 0x18);
  *param_2 = lVar2;
  FUN_00b0c0e4(*(undefined8 *)(param_1 + 8));
  return;
}


// ==== entry=00b1dc64 name=FUN_00b1dc64 size=98 ====

undefined8 FUN_00b1dc64(long param_1,string *param_2)

{
  char cVar1;
  undefined8 uVar2;
  undefined8 *puVar3;
  
  cVar1 = std::string::empty(param_2);
  if (cVar1 == '\0') {
    *(long *)(param_1 + 0x50) = *(long *)(param_1 + 0x50) + 1;
    puVar3 = (undefined8 *)FUN_00b1e8f0(param_1 + 0x20,param_2);
    *puVar3 = *(undefined8 *)(param_1 + 0x50);
    uVar2 = *puVar3;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}


// ==== entry=00b1dcc6 name=FUN_00b1dcc6 size=227 ====

undefined8 FUN_00b1dcc6(long param_1,undefined8 param_2,undefined8 param_3)

{
  char cVar1;
  undefined8 uVar2;
  long lVar3;
  undefined8 local_38;
  undefined8 local_30;
  string local_28 [15];
  allocator local_19;
  
  local_38 = FUN_00b1e9e8(param_1 + 0x20,param_3);
  local_30 = FUN_00b1ea0e(param_1 + 0x20);
  cVar1 = FUN_00b1ea28(&local_38,&local_30);
  if (cVar1 != '\0') {
    uVar2 = __cxa_allocate_exception(0x28);
    std::allocator<char>::allocator();
                    /* try { // try from 00b1dd4c to 00b1dd50 has its CatchHandler @ 00b1ddb1 */
    std::string::string(local_28,"the referenced anchor is not defined",&local_19);
                    /* try { // try from 00b1dd5f to 00b1dd63 has its CatchHandler @ 00b1dda0 */
    FUN_00b09fc4(uVar2,param_2,local_28);
    std::string::~string(local_28);
    std::allocator<char>::~allocator((allocator<char> *)&local_19);
                    /* WARNING: Subroutine does not return */
    __cxa_throw(uVar2,&PTR_PTR_00d39ce8,FUN_00b009e6);
  }
  lVar3 = FUN_00b1ea4a(&local_38);
  return *(undefined8 *)(lVar3 + 8);
}


// ==== entry=00b1dddc name=FUN_00b1dddc size=48 ====

void FUN_00b1dddc(void)

{
  string *this;
  
  this = (string *)&DAT_011c34e0;
  while (this != (string *)&DAT_011c3440) {
    this = this + -8;
    std::string::~string(this);
  }
  return;
}


// ==== entry=00b1de0c name=FUN_00b1de0c size=1151 ====

void FUN_00b1de0c(int param_1,int param_2)

{
  allocator local_3c;
  allocator local_3b;
  allocator local_3a;
  allocator local_39;
  allocator local_38;
  allocator local_37;
  allocator local_36;
  allocator local_35;
  allocator local_34;
  allocator local_33;
  allocator local_32;
  allocator local_31;
  allocator local_30;
  allocator local_2f;
  allocator local_2e;
  allocator local_2d;
  allocator local_2c;
  allocator local_2b;
  allocator local_2a;
  allocator local_29 [9];
  
  if ((param_1 == 1) && (param_2 == 0xffff)) {
    std::ios_base::Init::Init((Init *)&DAT_011c3420);
    __cxa_atexit(std::ios_base::Init::~Init,&DAT_011c3420,&DAT_00c89008);
    std::allocator<char>::allocator();
                    /* try { // try from 00b1de7a to 00b1de7e has its CatchHandler @ 00b1e280 */
    std::string::string((string *)&DAT_011c3440,"DIRECTIVE",&local_3c);
    std::allocator<char>::~allocator((allocator<char> *)&local_3c);
    std::allocator<char>::allocator();
                    /* try { // try from 00b1deae to 00b1deb2 has its CatchHandler @ 00b1e294 */
    std::string::string((string *)&DAT_011c3448,"DOC_START",&local_3b);
    std::allocator<char>::~allocator((allocator<char> *)&local_3b);
    std::allocator<char>::allocator();
                    /* try { // try from 00b1dee2 to 00b1dee6 has its CatchHandler @ 00b1e2a8 */
    std::string::string((string *)&DAT_011c3450,"DOC_END",&local_3a);
    std::allocator<char>::~allocator((allocator<char> *)&local_3a);
    std::allocator<char>::allocator();
                    /* try { // try from 00b1df16 to 00b1df1a has its CatchHandler @ 00b1e2bc */
    std::string::string((string *)&DAT_011c3458,"BLOCK_SEQ_START",&local_39);
    std::allocator<char>::~allocator((allocator<char> *)&local_39);
    std::allocator<char>::allocator();
                    /* try { // try from 00b1df4a to 00b1df4e has its CatchHandler @ 00b1e2d0 */
    std::string::string((string *)&DAT_011c3460,"BLOCK_MAP_START",&local_38);
    std::allocator<char>::~allocator((allocator<char> *)&local_38);
    std::allocator<char>::allocator();
                    /* try { // try from 00b1df7e to 00b1df82 has its CatchHandler @ 00b1e2e4 */
    std::string::string((string *)&DAT_011c3468,"BLOCK_SEQ_END",&local_37);
    std::allocator<char>::~allocator((allocator<char> *)&local_37);
    std::allocator<char>::allocator();
                    /* try { // try from 00b1dfb2 to 00b1dfb6 has its CatchHandler @ 00b1e2f8 */
    std::string::string((string *)&DAT_011c3470,"BLOCK_MAP_END",&local_36);
    std::allocator<char>::~allocator((allocator<char> *)&local_36);
    std::allocator<char>::allocator();
                    /* try { // try from 00b1dfe6 to 00b1dfea has its CatchHandler @ 00b1e30c */
    std::string::string((string *)&DAT_011c3478,"BLOCK_ENTRY",&local_35);
    std::allocator<char>::~allocator((allocator<char> *)&local_35);
    std::allocator<char>::allocator();
                    /* try { // try from 00b1e01a to 00b1e01e has its CatchHandler @ 00b1e320 */
    std::string::string((string *)&DAT_011c3480,"FLOW_SEQ_START",&local_34);
    std::allocator<char>::~allocator((allocator<char> *)&local_34);
    std::allocator<char>::allocator();
                    /* try { // try from 00b1e04e to 00b1e052 has its CatchHandler @ 00b1e334 */
    std::string::string((string *)&DAT_011c3488,"FLOW_MAP_START",&local_33);
    std::allocator<char>::~allocator((allocator<char> *)&local_33);
    std::allocator<char>::allocator();
                    /* try { // try from 00b1e082 to 00b1e086 has its CatchHandler @ 00b1e348 */
    std::string::string((string *)&DAT_011c3490,"FLOW_SEQ_END",&local_32);
    std::allocator<char>::~allocator((allocator<char> *)&local_32);
    std::allocator<char>::allocator();
                    /* try { // try from 00b1e0b6 to 00b1e0ba has its CatchHandler @ 00b1e35c */
    std::string::string((string *)&DAT_011c3498,"FLOW_MAP_END",&local_31);
    std::allocator<char>::~allocator((allocator<char> *)&local_31);
    std::allocator<char>::allocator();
                    /* try { // try from 00b1e0ea to 00b1e0ee has its CatchHandler @ 00b1e370 */
    std::string::string((string *)&DAT_011c34a0,"FLOW_MAP_COMPACT",&local_30);
    std::allocator<char>::~allocator((allocator<char> *)&local_30);
    std::allocator<char>::allocator();
                    /* try { // try from 00b1e11e to 00b1e122 has its CatchHandler @ 00b1e381 */
    std::string::string((string *)&DAT_011c34a8,"FLOW_ENTRY",&local_2f);
    std::allocator<char>::~allocator((allocator<char> *)&local_2f);
    std::allocator<char>::allocator();
                    /* try { // try from 00b1e152 to 00b1e156 has its CatchHandler @ 00b1e392 */
    std::string::string((string *)&DAT_011c34b0,"KEY",&local_2e);
    std::allocator<char>::~allocator((allocator<char> *)&local_2e);
    std::allocator<char>::allocator();
                    /* try { // try from 00b1e186 to 00b1e18a has its CatchHandler @ 00b1e3a3 */
    std::string::string((string *)&DAT_011c34b8,"VALUE",&local_2d);
    std::allocator<char>::~allocator((allocator<char> *)&local_2d);
    std::allocator<char>::allocator();
                    /* try { // try from 00b1e1ba to 00b1e1be has its CatchHandler @ 00b1e3b4 */
    std::string::string((string *)&DAT_011c34c0,"ANCHOR",&local_2c);
    std::allocator<char>::~allocator((allocator<char> *)&local_2c);
    std::allocator<char>::allocator();
                    /* try { // try from 00b1e1ee to 00b1e1f2 has its CatchHandler @ 00b1e3c5 */
    std::string::string((string *)&DAT_011c34c8,"ALIAS",&local_2b);
    std::allocator<char>::~allocator((allocator<char> *)&local_2b);
    std::allocator<char>::allocator();
                    /* try { // try from 00b1e222 to 00b1e226 has its CatchHandler @ 00b1e3d6 */
    std::string::string((string *)&DAT_011c34d0,"TAG",&local_2a);
    std::allocator<char>::~allocator((allocator<char> *)&local_2a);
    std::allocator<char>::allocator();
                    /* try { // try from 00b1e256 to 00b1e25a has its CatchHandler @ 00b1e3e7 */
    std::string::string((string *)&DAT_011c34d8,"SCALAR",local_29);
    std::allocator<char>::~allocator((allocator<char> *)local_29);
    __cxa_atexit(FUN_00b1dddc,0,&DAT_00c89008);
  }
  return;
}


// ==== entry=00b1e435 orig=FUN_00b1e435 size=21 name=_INIT_174 ====

void _INIT_174(void)

{
  FUN_00b1de0c(1,0xffff);
  return;
}


// ==== entry=00b1e44a name=FUN_00b1e44a size=27 ====

void FUN_00b1e44a(undefined8 param_1)

{
  FUN_00b1e5e0(param_1);
  return;
}


// ==== entry=00b1e466 name=FUN_00b1e466 size=27 ====

void FUN_00b1e466(undefined8 param_1)

{
  FUN_00b1e5c4(param_1);
  return;
}


// ==== entry=00b1e482 name=FUN_00b1e482 size=51 ====

undefined4 FUN_00b1e482(undefined8 param_1)

{
  char cVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  
  cVar1 = FUN_00b1e64e(param_1);
  if (cVar1 == '\0') {
    puVar3 = (undefined4 *)FUN_00b1e668(param_1);
    uVar2 = *puVar3;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}


// ==== entry=00b1e4b6 name=FUN_00b1e4b6 size=37 ====

void FUN_00b1e4b6(undefined8 param_1,undefined4 param_2)

{
  undefined4 local_14;
  undefined8 local_10;
  
  local_14 = param_2;
  local_10 = param_1;
  FUN_00b1e682(param_1,&local_14);
  return;
}


// ==== entry=00b1e4dc name=FUN_00b1e4dc size=72 ====

void FUN_00b1e4dc(undefined8 param_1,int param_2)

{
  int iVar1;
  
  iVar1 = FUN_00b1e482(param_1);
  if (param_2 != iVar1) {
                    /* WARNING: Subroutine does not return */
    __assert_fail("type == GetCurCollectionType()",
                  "/mnt/hgfs/Develop/Library/yaml-cpp-0.7.0/src/collectionstack.h",0x1f,
                  "void YAML::CollectionStack::PopCollectionType(YAML::CollectionType::value)");
  }
  FUN_00b1e6a8(param_1);
  return;
}


// ==== entry=00b1e524 name=FUN_00b1e524 size=27 ====

void FUN_00b1e524(undefined8 param_1)

{
  FUN_00b1e77a(param_1);
  return;
}


// ==== entry=00b1e540 name=FUN_00b1e540 size=27 ====

void FUN_00b1e540(undefined8 param_1)

{
  FUN_00b1e742(param_1);
  return;
}


// ==== entry=00b1e55c name=FUN_00b1e55c size=27 ====

void FUN_00b1e55c(undefined8 param_1)

{
  FUN_00b1e540(param_1);
  return;
}


// ==== entry=00b1e578 name=FUN_00b1e578 size=27 ====

void FUN_00b1e578(undefined8 param_1)

{
  FUN_00b1e796(param_1);
  return;
}


// ==== entry=00b1e594 name=FUN_00b1e594 size=47 ====

void FUN_00b1e594(long param_1)

{
  std::string::~string((string *)(param_1 + 0x10));
  std::string::~string((string *)(param_1 + 8));
  return;
}


// ==== entry=00b1e5c4 name=FUN_00b1e5c4 size=27 ====

void FUN_00b1e5c4(undefined8 param_1)

{
  FUN_00b1ea68(param_1);
  return;
}


// ==== entry=00b1e5e0 name=FUN_00b1e5e0 size=109 ====

void FUN_00b1e5e0(undefined8 param_1)

{
  undefined8 uVar1;
  undefined1 local_58 [32];
  undefined1 local_38 [40];
  
  uVar1 = FUN_00b1eb64(param_1);
  FUN_00b1eb36(local_58,param_1);
  FUN_00b1eb08(local_38,param_1);
  FUN_00b1ebc0(param_1,local_38,local_58,uVar1);
  FUN_00b1eaa0(param_1);
  return;
}


// ==== entry=00b1e64e name=FUN_00b1e64e size=26 ====

void FUN_00b1e64e(undefined8 param_1)

{
  FUN_00b1ebd8(param_1);
  return;
}


// ==== entry=00b1e668 name=FUN_00b1e668 size=26 ====

void FUN_00b1e668(undefined8 param_1)

{
  FUN_00b1ec02(param_1);
  return;
}


// ==== entry=00b1e682 name=FUN_00b1e682 size=38 ====

void FUN_00b1e682(undefined8 param_1,undefined8 param_2)

{
  FUN_00b1ec3c(param_1,param_2);
  return;
}


// ==== entry=00b1e6a8 name=FUN_00b1e6a8 size=27 ====

void FUN_00b1e6a8(undefined8 param_1)

{
  FUN_00b1ecac(param_1);
  return;
}


// ==== entry=00b1e6c4 name=FUN_00b1e6c4 size=38 ====

void FUN_00b1e6c4(undefined8 param_1,undefined8 param_2)

{
  FUN_00b1ed0a(param_1,param_2);
  return;
}


// ==== entry=00b1e6ea name=FUN_00b1e6ea size=87 ====

void FUN_00b1e6ea(undefined8 param_1)

{
  long *plVar1;
  undefined8 uVar2;
  
  plVar1 = (long *)FUN_00b1ed40(param_1);
  if (*plVar1 != 0) {
    uVar2 = FUN_00b1ed5a(param_1);
    FUN_00b1ed90(uVar2,*plVar1);
  }
  *plVar1 = 0;
  return;
}


// ==== entry=00b1e742 name=FUN_00b1e742 size=55 ====

void FUN_00b1e742(long param_1)

{
  FUN_00b1edc2(param_1);
  FUN_00b1edde(param_1);
  FUN_00b00f0c(param_1 + 8);
  return;
}


// ==== entry=00b1e77a name=FUN_00b1e77a size=27 ====

void FUN_00b1e77a(undefined8 param_1)

{
  FUN_00b1edea(param_1);
  return;
}


// ==== entry=00b1e796 name=FUN_00b1e796 size=57 ====

void FUN_00b1e796(undefined8 param_1)

{
  undefined8 uVar1;
  
  uVar1 = FUN_00b1ee5c(param_1);
  FUN_00b1edf6(param_1,uVar1);
  FUN_00b1e524(param_1);
  return;
}


// ==== entry=00b1e7d0 name=FUN_00b1e7d0 size=39 ====

void FUN_00b1e7d0(undefined8 *param_1)

{
  *param_1 = &PTR_FUN_00d3df80;
  FUN_00b009e6(param_1);
  return;
}


// ==== entry=00b1e7f8 name=FUN_00b1e7f8 size=38 ====

void FUN_00b1e7f8(void *param_1)

{
  FUN_00b1e7d0(param_1);
  operator_delete(param_1);
  return;
}


// ==== entry=00b1e81e name=FUN_00b1e81e size=136 ====

void FUN_00b1e81e(undefined8 *param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 uVar1;
  
  *param_1 = param_2;
  *(int *)*param_1 = *(int *)*param_1 + 1;
  if (499 < *(int *)*param_1) {
    uVar1 = __cxa_allocate_exception(0x30);
                    /* try { // try from 00b1e885 to 00b1e889 has its CatchHandler @ 00b1e89c */
    FUN_00b23cda(uVar1,*(undefined4 *)*param_1,param_3,param_4);
                    /* WARNING: Subroutine does not return */
    __cxa_throw(uVar1,&PTR_PTR_00d3df98,FUN_00b1e7d0);
  }
  return;
}


// ==== entry=00b1e8bc name=FUN_00b1e8bc size=25 ====

void FUN_00b1e8bc(undefined8 *param_1)

{
  *(int *)*param_1 = *(int *)*param_1 + -1;
  return;
}


// ==== entry=00b1e8d6 name=FUN_00b1e8d6 size=26 ====

void FUN_00b1e8d6(undefined8 param_1)

{
  FUN_00b1ee6e(param_1);
  return;
}


// ==== entry=00b1e8f0 name=FUN_00b1e8f0 size=248 ====

long FUN_00b1e8f0(undefined8 param_1,undefined8 param_2)

{
  bool bVar1;
  char cVar2;
  undefined8 uVar3;
  long lVar4;
  undefined8 local_40;
  undefined8 local_38;
  undefined1 local_2a;
  undefined1 local_29;
  undefined1 local_28 [8];
  undefined8 local_20 [2];
  
  local_40 = FUN_00b1ee88(param_1,param_2);
  local_38 = FUN_00b1eeae(param_1);
  cVar2 = FUN_00b1eec8(&local_40,&local_38);
  if (cVar2 == '\0') {
    FUN_00b1eeea(param_1);
    uVar3 = FUN_00b1ef0c(&local_40);
    cVar2 = FUN_00b0a97a(&local_2a,param_2,uVar3);
    if (cVar2 == '\0') {
      bVar1 = false;
      goto LAB_00b1e97d;
    }
  }
  bVar1 = true;
LAB_00b1e97d:
  if (bVar1) {
    FUN_00b0a442(local_28,param_2);
    FUN_00b1ef2a(local_20,&local_40);
    local_40 = FUN_00b1ef48(param_1,local_20[0],&DAT_00d3d3c0,local_28,&local_29);
  }
  lVar4 = FUN_00b1ef0c(&local_40);
  return lVar4 + 8;
}


// ==== entry=00b1e9e8 name=FUN_00b1e9e8 size=37 ====

void FUN_00b1e9e8(undefined8 param_1,undefined8 param_2)

{
  FUN_00b1f060(param_1,param_2);
  return;
}


// ==== entry=00b1ea0e name=FUN_00b1ea0e size=26 ====

void FUN_00b1ea0e(undefined8 param_1)

{
  FUN_00b1f110(param_1);
  return;
}


// ==== entry=00b1ea28 name=FUN_00b1ea28 size=34 ====

undefined8 FUN_00b1ea28(long *param_1,long *param_2)

{
  return CONCAT71((int7)((ulong)*param_2 >> 8),*param_1 == *param_2);
}


// ==== entry=00b1ea4a name=FUN_00b1ea4a size=29 ====

void FUN_00b1ea4a(undefined8 *param_1)

{
  FUN_00b1f13a(*param_1);
  return;
}


// ==== entry=00b1ea68 name=FUN_00b1ea68 size=27 ====

void FUN_00b1ea68(undefined8 param_1)

{
  FUN_00b1f158(param_1);
  return;
}


// ==== entry=00b1ea84 name=FUN_00b1ea84 size=27 ====

void FUN_00b1ea84(undefined8 param_1)

{
  FUN_00b1f1a6(param_1);
  return;
}


// ==== entry=00b1eaa0 name=FUN_00b1eaa0 size=104 ====

void FUN_00b1eaa0(long *param_1)

{
  if (*param_1 != 0) {
    FUN_00b1f1c2(param_1,param_1[5],param_1[9] + 8);
    FUN_00b1f208(param_1,*param_1,param_1[1]);
  }
  FUN_00b1ea84(param_1);
  return;
}


// ==== entry=00b1eb08 name=FUN_00b1eb08 size=45 ====

undefined8 FUN_00b1eb08(undefined8 param_1,long param_2)

{
  FUN_00b1eb72(param_1,param_2 + 0x10);
  return param_1;
}


// ==== entry=00b1eb36 name=FUN_00b1eb36 size=45 ====

undefined8 FUN_00b1eb36(undefined8 param_1,long param_2)

{
  FUN_00b1eb72(param_1,param_2 + 0x30);
  return param_1;
}


// ==== entry=00b1eb64 name=FUN_00b1eb64 size=14 ====

undefined8 FUN_00b1eb64(undefined8 param_1)

{
  return param_1;
}


// ==== entry=00b1eb72 name=FUN_00b1eb72 size=77 ====

void FUN_00b1eb72(undefined8 *param_1,undefined8 *param_2)

{
  *param_1 = *param_2;
  param_1[1] = param_2[1];
  param_1[2] = param_2[2];
  param_1[3] = param_2[3];
  return;
}


// ==== entry=00b1ebc0 name=FUN_00b1ebc0 size=23 ====

void FUN_00b1ebc0(void)

{
  return;
}


// ==== entry=00b1ebd8 name=FUN_00b1ebd8 size=41 ====

void FUN_00b1ebd8(long param_1)

{
  FUN_00b1f255(param_1 + 0x30,param_1 + 0x10);
  return;
}


// ==== entry=00b1ec02 name=FUN_00b1ec02 size=58 ====

void FUN_00b1ec02(undefined8 param_1)

{
  undefined1 local_28 [32];
  
  FUN_00b1f278(local_28,param_1);
  FUN_00b1f2a6(local_28);
  FUN_00b1f308(local_28);
  return;
}


// ==== entry=00b1ec3c name=FUN_00b1ec3c size=112 ====

void FUN_00b1ec3c(long param_1,undefined8 param_2)

{
  if (*(long *)(param_1 + 0x30) == *(long *)(param_1 + 0x40) + -4) {
    FUN_00b1f360(param_1,param_2);
  }
  else {
    FUN_00b1f327(param_1,*(undefined8 *)(param_1 + 0x30),param_2);
    *(long *)(param_1 + 0x30) = *(long *)(param_1 + 0x30) + 4;
  }
  return;
}


// ==== entry=00b1ecac name=FUN_00b1ecac size=93 ====

void FUN_00b1ecac(long param_1)

{
  if (*(long *)(param_1 + 0x30) == *(long *)(param_1 + 0x38)) {
    FUN_00b1f420(param_1);
  }
  else {
    *(long *)(param_1 + 0x30) = *(long *)(param_1 + 0x30) + -4;
    FUN_00b1f3fa(param_1,*(undefined8 *)(param_1 + 0x30));
  }
  return;
}


// ==== entry=00b1ed0a name=FUN_00b1ed0a size=53 ====

void FUN_00b1ed0a(undefined8 param_1,undefined8 param_2)

{
  undefined8 *puVar1;
  
  FUN_00b1f49e(param_1);
  puVar1 = (undefined8 *)FUN_00b1ed40(param_1);
  *puVar1 = param_2;
  return;
}


// ==== entry=00b1ed40 name=FUN_00b1ed40 size=26 ====

void FUN_00b1ed40(undefined8 param_1)

{
  FUN_00b1f4b9(param_1);
  return;
}


// ==== entry=00b1ed5a name=FUN_00b1ed5a size=26 ====

void FUN_00b1ed5a(undefined8 param_1)

{
  FUN_00b1f4d4(param_1);
  return;
}


// ==== entry=00b1ed74 name=FUN_00b1ed74 size=27 ====

void FUN_00b1ed74(undefined8 param_1)

{
  FUN_00b1e44a(param_1);
  return;
}


// ==== entry=00b1ed90 name=FUN_00b1ed90 size=50 ====

void FUN_00b1ed90(undefined8 param_1,void *param_2)

{
  if (param_2 != (void *)0x0) {
    FUN_00b1ed74(param_2);
    operator_delete(param_2);
  }
  return;
}


// ==== entry=00b1edc2 name=FUN_00b1edc2 size=27 ====

void FUN_00b1edc2(undefined8 param_1)

{
  FUN_00b1f4ee(param_1);
  return;
}


// ==== entry=00b1edde name=FUN_00b1edde size=11 ====

void FUN_00b1edde(void)

{
  return;
}


// ==== entry=00b1edea name=FUN_00b1edea size=11 ====

void FUN_00b1edea(void)

{
  return;
}


// ==== entry=00b1edf6 name=FUN_00b1edf6 size=101 ====

void FUN_00b1edf6(undefined8 param_1,long param_2)

{
  undefined8 uVar1;
  long lVar2;
  undefined8 local_28;
  
  local_28 = param_2;
  while (local_28 != 0) {
    uVar1 = FUN_00b1f4f9(local_28);
    FUN_00b1edf6(param_1,uVar1);
    lVar2 = FUN_00b1f50b(local_28);
    FUN_00b1f51e(param_1,local_28);
    local_28 = lVar2;
  }
  return;
}


// ==== entry=00b1ee5c name=FUN_00b1ee5c size=18 ====

undefined8 FUN_00b1ee5c(long param_1)

{
  return *(undefined8 *)(param_1 + 0x10);
}


// ==== entry=00b1ee6e name=FUN_00b1ee6e size=26 ====

void FUN_00b1ee6e(undefined8 param_1)

{
  FUN_00b1f558(param_1);
  return;
}


// ==== entry=00b1ee88 name=FUN_00b1ee88 size=37 ====

void FUN_00b1ee88(undefined8 param_1,undefined8 param_2)

{
  FUN_00b1f576(param_1,param_2);
  return;
}


// ==== entry=00b1eeae name=FUN_00b1eeae size=26 ====

void FUN_00b1eeae(undefined8 param_1)

{
  FUN_00b1f5c2(param_1);
  return;
}


// ==== entry=00b1eec8 name=FUN_00b1eec8 size=34 ====

undefined8 FUN_00b1eec8(long *param_1,long *param_2)

{
  return CONCAT71((int7)((ulong)*param_2 >> 8),*param_1 == *param_2);
}


// ==== entry=00b1eeea name=FUN_00b1eeea size=34 ====

undefined4 FUN_00b1eeea(undefined8 param_1)

{
  undefined4 unaff_EBX;
  
  FUN_00b1f5ec(param_1);
  return unaff_EBX;
}


// ==== entry=00b1ef0c name=FUN_00b1ef0c size=29 ====

void FUN_00b1ef0c(undefined8 *param_1)

{
  FUN_00b1f5f6(*param_1);
  return;
}


// ==== entry=00b1ef2a name=FUN_00b1ef2a size=29 ====

void FUN_00b1ef2a(undefined8 *param_1,undefined8 *param_2)

{
  *param_1 = *param_2;
  return;
}


// ==== entry=00b1ef48 name=FUN_00b1ef48 size=228 ====

undefined8
FUN_00b1ef48(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
            undefined8 param_5)

{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined1 auVar4 [16];
  undefined8 local_28;
  undefined8 local_20;
  
  uVar1 = FUN_00b0a9dd(param_5);
  uVar2 = FUN_00b0a9cf(param_4);
  uVar3 = FUN_00b0a9c1(param_3);
  local_20 = FUN_00b1f614(param_1,uVar3,uVar2,uVar1);
                    /* try { // try from 00b1efb1 to 00b1eff4 has its CatchHandler @ 00b1f023 */
  uVar1 = FUN_00b1fae2(local_20);
  auVar4 = FUN_00b1f690(param_1,param_2,uVar1);
  if (auVar4._8_8_ == 0) {
    FUN_00b1f51e(param_1,local_20);
    FUN_00b1fbd4(&local_28,auVar4._0_8_);
  }
  else {
    local_28 = FUN_00b1fb10(param_1,auVar4._0_8_,auVar4._8_8_,local_20);
  }
  return local_28;
}


// ==== entry=00b1f060 name=FUN_00b1f060 size=175 ====

undefined8 FUN_00b1f060(undefined8 param_1,undefined8 param_2)

{
  char cVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 local_28;
  undefined8 local_20 [2];
  
  uVar2 = FUN_00b1fc00(param_1);
  uVar3 = FUN_00b1fbee(param_1);
  local_28 = FUN_00b1fc12(param_1,uVar3,uVar2,param_2);
  local_20[0] = FUN_00b1f110(param_1);
  cVar1 = FUN_00b1ea28(&local_28,local_20);
  if (cVar1 == '\0') {
    uVar2 = FUN_00b1fca8(local_28);
    cVar1 = FUN_00b0a97a(param_1,param_2,uVar2);
    if (cVar1 == '\0') {
      return local_28;
    }
  }
  uVar2 = FUN_00b1f110(param_1);
  return uVar2;
}


// ==== entry=00b1f110 name=FUN_00b1f110 size=41 ====

undefined8 FUN_00b1f110(long param_1)

{
  undefined8 local_10;
  
  FUN_00b1fcd6(&local_10,param_1 + 8);
  return local_10;
}


// ==== entry=00b1f13a name=FUN_00b1f13a size=30 ====

void FUN_00b1f13a(long param_1)

{
  FUN_00b1fcf0(param_1 + 0x20);
  return;
}


// ==== entry=00b1f158 name=FUN_00b1f158 size=51 ====

void FUN_00b1f158(undefined8 param_1)

{
  FUN_00b1fd0a(param_1);
                    /* try { // try from 00b1f17d to 00b1f181 has its CatchHandler @ 00b1f184 */
  FUN_00b1fd5c(param_1,0);
  return;
}


// ==== entry=00b1f1a6 name=FUN_00b1f1a6 size=27 ====

void FUN_00b1f1a6(undefined8 param_1)

{
  FUN_00b1ff04(param_1);
  return;
}


// ==== entry=00b1f1c2 name=FUN_00b1f1c2 size=70 ====

void FUN_00b1f1c2(undefined8 param_1,undefined8 *param_2,undefined8 *param_3)

{
  undefined8 *local_10;
  
  for (local_10 = param_2; local_10 < param_3; local_10 = local_10 + 1) {
    FUN_00b1ff10(param_1,*local_10);
  }
  return;
}


// ==== entry=00b1f208 name=FUN_00b1f208 size=77 ====

void FUN_00b1f208(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  undefined1 local_9;
  
  FUN_00b1ff44(&local_9,param_1);
  FUN_00b1ff93(&local_9,param_2,param_3);
  FUN_00b1ff78(&local_9);
  return;
}


// ==== entry=00b1f255 name=FUN_00b1f255 size=34 ====

undefined8 FUN_00b1f255(long *param_1,long *param_2)

{
  return CONCAT71((int7)((ulong)*param_2 >> 8),*param_1 == *param_2);
}


// ==== entry=00b1f278 name=FUN_00b1f278 size=45 ====

undefined8 FUN_00b1f278(undefined8 param_1,long param_2)

{
  FUN_00b1ffc2(param_1,param_2 + 0x30);
  return param_1;
}


// ==== entry=00b1f2a6 name=FUN_00b1f2a6 size=98 ====

long * FUN_00b1f2a6(long *param_1)

{
  if (*param_1 == param_1[1]) {
    FUN_00b20010(param_1,param_1[3] + -8);
    *param_1 = param_1[2];
  }
  *param_1 = *param_1 + -4;
  return param_1;
}


// ==== entry=00b1f308 name=FUN_00b1f308 size=17 ====

undefined8 FUN_00b1f308(undefined8 *param_1)

{
  return *param_1;
}


// ==== entry=00b1f319 name=FUN_00b1f319 size=14 ====

undefined8 FUN_00b1f319(undefined8 param_1)

{
  return param_1;
}


// ==== entry=00b1f327 name=FUN_00b1f327 size=57 ====

void FUN_00b1f327(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  undefined8 uVar1;
  
  uVar1 = FUN_00b1f319(param_3);
  FUN_00b20062(param_1,param_2,uVar1);
  return;
}


// ==== entry=00b1f360 name=FUN_00b1f360 size=154 ====

void FUN_00b1f360(long param_1,undefined8 param_2)

{
  long lVar1;
  undefined8 uVar2;
  
  FUN_00b200a0(param_1,1);
  lVar1 = *(long *)(param_1 + 0x48);
  uVar2 = FUN_00b20100(param_1);
  *(undefined8 *)(lVar1 + 8) = uVar2;
  uVar2 = FUN_00b1f319(param_2);
  FUN_00b1f327(param_1,*(undefined8 *)(param_1 + 0x30),uVar2);
  FUN_00b2012a(param_1 + 0x30,*(long *)(param_1 + 0x48) + 8);
  *(undefined8 *)(param_1 + 0x30) = *(undefined8 *)(param_1 + 0x38);
  return;
}


// ==== entry=00b1f3fa name=FUN_00b1f3fa size=38 ====

void FUN_00b1f3fa(undefined8 param_1,undefined8 param_2)

{
  FUN_00b2017c(param_1,param_2);
  return;
}


// ==== entry=00b1f420 name=FUN_00b1f420 size=126 ====

void FUN_00b1f420(long param_1)

{
  undefined8 uVar1;
  undefined8 uVar2;
  
  FUN_00b1ff10(param_1,*(undefined8 *)(param_1 + 0x38));
  FUN_00b2012a(param_1 + 0x30,*(long *)(param_1 + 0x48) + -8);
  *(long *)(param_1 + 0x30) = *(long *)(param_1 + 0x40) + -4;
  uVar1 = *(undefined8 *)(param_1 + 0x30);
  uVar2 = FUN_00b1eb64(param_1);
  FUN_00b1f3fa(uVar2,uVar1);
  return;
}


// ==== entry=00b1f49e name=FUN_00b1f49e size=27 ====

void FUN_00b1f49e(undefined8 param_1)

{
  FUN_00b2018c(param_1);
  return;
}


// ==== entry=00b1f4b9 name=FUN_00b1f4b9 size=26 ====

void FUN_00b1f4b9(undefined8 param_1)

{
  FUN_00b201b3(param_1);
  return;
}


// ==== entry=00b1f4d4 name=FUN_00b1f4d4 size=26 ====

void FUN_00b1f4d4(undefined8 param_1)

{
  FUN_00b201cd(param_1);
  return;
}


// ==== entry=00b1f4ee name=FUN_00b1f4ee size=11 ====

void FUN_00b1f4ee(void)

{
  return;
}


// ==== entry=00b1f4f9 name=FUN_00b1f4f9 size=18 ====

undefined8 FUN_00b1f4f9(long param_1)

{
  return *(undefined8 *)(param_1 + 0x18);
}


// ==== entry=00b1f50b name=FUN_00b1f50b size=18 ====

undefined8 FUN_00b1f50b(long param_1)

{
  return *(undefined8 *)(param_1 + 0x10);
}


// ==== entry=00b1f51e name=FUN_00b1f51e size=57 ====

void FUN_00b1f51e(undefined8 param_1,undefined8 param_2)

{
  FUN_00b201e8(param_1,param_2);
  FUN_00b20228(param_1,param_2);
  return;
}


// ==== entry=00b1f558 name=FUN_00b1f558 size=29 ====

undefined8 FUN_00b1f558(undefined8 param_1)

{
  undefined8 *puVar1;
  
  puVar1 = (undefined8 *)FUN_00b2025e(param_1);
  return *puVar1;
}


// ==== entry=00b1f576 name=FUN_00b1f576 size=76 ====

void FUN_00b1f576(undefined8 param_1,undefined8 param_2)

{
  undefined8 uVar1;
  undefined8 uVar2;
  
  uVar1 = FUN_00b20278(param_1);
  uVar2 = FUN_00b1ee5c(param_1);
  FUN_00b2028a(param_1,uVar2,uVar1,param_2);
  return;
}


// ==== entry=00b1f5c2 name=FUN_00b1f5c2 size=41 ====

undefined8 FUN_00b1f5c2(long param_1)

{
  undefined8 local_10;
  
  FUN_00b1fbd4(&local_10,param_1 + 8);
  return local_10;
}


// ==== entry=00b1f5ec name=FUN_00b1f5ec size=10 ====

void FUN_00b1f5ec(void)

{
  return;
}


// ==== entry=00b1f5f6 name=FUN_00b1f5f6 size=30 ====

void FUN_00b1f5f6(long param_1)

{
  FUN_00b20320(param_1 + 0x20);
  return;
}


// ==== entry=00b1f614 name=FUN_00b1f614 size=123 ====

undefined8 FUN_00b1f614(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  
  uVar1 = FUN_00b2033a(param_1);
  uVar2 = FUN_00b0a9dd(param_4);
  uVar3 = FUN_00b0a9cf(param_3);
  uVar4 = FUN_00b0a9c1(param_2);
  FUN_00b20362(param_1,uVar1,uVar4,uVar3,uVar2);
  return uVar1;
}


// ==== entry=00b1f690 name=FUN_00b1f690 size=1106 ====

undefined8 FUN_00b1f690(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  bool bVar1;
  char cVar2;
  long lVar3;
  long lVar4;
  undefined8 *puVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  long *plVar8;
  undefined8 local_118;
  undefined8 local_110;
  long local_100;
  long local_f8;
  long local_f0;
  undefined8 local_e8 [3];
  undefined8 local_d0;
  undefined8 local_c8 [2];
  undefined8 local_b8 [3];
  undefined8 local_a0;
  undefined8 local_98 [2];
  undefined8 local_88 [3];
  undefined8 local_70;
  undefined8 local_68 [3];
  undefined8 local_50;
  undefined8 local_48 [2];
  undefined8 local_38 [3];
  undefined8 local_20 [2];
  
  local_118 = param_2;
  local_110 = param_1;
  lVar3 = FUN_00b20434(&local_118);
  local_f0 = lVar3;
  lVar4 = FUN_00b20278(local_110);
  uVar7 = local_110;
  if (lVar3 != lVar4) {
    uVar6 = FUN_00b1fca8(local_f0);
    cVar2 = FUN_00b0a97a(uVar7,param_3,uVar6);
    lVar3 = local_f0;
    uVar7 = local_110;
    if (cVar2 != '\0') {
      local_f8 = local_f0;
      plVar8 = (long *)FUN_00b20648(local_110);
      uVar7 = local_110;
      if (lVar3 == *plVar8) {
        uVar7 = FUN_00b20648(local_110);
        uVar6 = FUN_00b20648(local_110);
        FUN_00b024b8(local_c8,uVar6,uVar7);
        return local_c8[0];
      }
      puVar5 = (undefined8 *)FUN_00b2065a(&local_f8);
      uVar6 = FUN_00b1fca8(*puVar5);
      cVar2 = FUN_00b0a97a(uVar7,uVar6,param_3);
      if (cVar2 != '\0') {
        lVar3 = FUN_00b1f4f9(local_f8);
        if (lVar3 == 0) {
          local_a0 = 0;
          FUN_00b0247c(local_b8,&local_a0,&local_f8);
          return local_b8[0];
        }
        FUN_00b024b8(local_98,&local_f0,&local_f0);
        return local_98[0];
      }
      uVar7 = FUN_00b204d2(local_110,param_3);
      return uVar7;
    }
    uVar6 = FUN_00b1fca8(local_f0);
    cVar2 = FUN_00b0a97a(uVar7,uVar6,param_3);
    lVar3 = local_f0;
    if (cVar2 == '\0') {
      local_20[0] = 0;
      FUN_00b01a5a(local_38,&local_f0,local_20);
      return local_38[0];
    }
    local_100 = local_f0;
    plVar8 = (long *)FUN_00b2046e(local_110);
    uVar7 = local_110;
    if (lVar3 == *plVar8) {
      uVar7 = FUN_00b2046e(local_110);
      local_70 = 0;
      FUN_00b0247c(local_88,&local_70,uVar7);
      return local_88[0];
    }
    puVar5 = (undefined8 *)FUN_00b20686(&local_100);
    uVar6 = FUN_00b1fca8(*puVar5);
    cVar2 = FUN_00b0a97a(uVar7,param_3,uVar6);
    if (cVar2 == '\0') {
      uVar7 = FUN_00b204d2(local_110,param_3);
      return uVar7;
    }
    lVar3 = FUN_00b1f4f9(local_f0);
    if (lVar3 == 0) {
      local_50 = 0;
      FUN_00b0247c(local_68,&local_50,&local_f0);
      return local_68[0];
    }
    FUN_00b024b8(local_48,&local_100,&local_100);
    return local_48[0];
  }
  lVar3 = FUN_00b2045c(local_110);
  uVar7 = local_110;
  if (lVar3 != 0) {
    puVar5 = (undefined8 *)FUN_00b2046e(local_110);
    uVar6 = FUN_00b1fca8(*puVar5);
    cVar2 = FUN_00b0a97a(uVar7,uVar6,param_3);
    if (cVar2 != '\0') {
      bVar1 = true;
      goto LAB_00b1f748;
    }
  }
  bVar1 = false;
LAB_00b1f748:
  if (bVar1) {
    uVar7 = FUN_00b2046e(local_110);
    local_d0 = 0;
    FUN_00b0247c(local_e8,&local_d0,uVar7);
  }
  else {
    local_e8[0] = FUN_00b204d2(local_110,param_3);
  }
  return local_e8[0];
}


// ==== entry=00b1fae2 name=FUN_00b1fae2 size=45 ====

void FUN_00b1fae2(undefined8 param_1)

{
  undefined8 uVar1;
  undefined1 local_9;
  
  uVar1 = FUN_00b206b1(param_1);
  FUN_00b206cc(&local_9,uVar1);
  return;
}


// ==== entry=00b1fb10 name=FUN_00b1fb10 size=195 ====

undefined8
FUN_00b1fb10(long param_1,long param_2,_Rb_tree_node_base *param_3,_Rb_tree_node_base *param_4)

{
  char cVar1;
  _Rb_tree_node_base *p_Var2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined8 local_28;
  undefined1 local_19;
  
  if (param_2 == 0) {
    p_Var2 = (_Rb_tree_node_base *)FUN_00b20278(param_1);
    if (param_3 != p_Var2) {
      uVar3 = FUN_00b1fca8(param_3);
      uVar4 = FUN_00b1fae2(param_4);
      cVar1 = FUN_00b0a97a(param_1,uVar4,uVar3);
      if (cVar1 == '\0') {
        local_19 = false;
        goto LAB_00b1fb81;
      }
    }
  }
  local_19 = true;
LAB_00b1fb81:
  std::_Rb_tree_insert_and_rebalance
            ((bool)local_19,param_4,param_3,(_Rb_tree_node_base *)(param_1 + 8));
  *(long *)(param_1 + 0x28) = *(long *)(param_1 + 0x28) + 1;
  FUN_00b1fbd4(&local_28,param_4);
  return local_28;
}


// ==== entry=00b1fbd4 name=FUN_00b1fbd4 size=26 ====

void FUN_00b1fbd4(undefined8 *param_1,undefined8 param_2)

{
  *param_1 = param_2;
  return;
}


// ==== entry=00b1fbee name=FUN_00b1fbee size=18 ====

undefined8 FUN_00b1fbee(long param_1)

{
  return *(undefined8 *)(param_1 + 0x10);
}


// ==== entry=00b1fc00 name=FUN_00b1fc00 size=18 ====

long FUN_00b1fc00(long param_1)

{
  return param_1 + 8;
}


// ==== entry=00b1fc12 name=FUN_00b1fc12 size=150 ====

undefined8 FUN_00b1fc12(undefined8 param_1,long param_2,long param_3,undefined8 param_4)

{
  char cVar1;
  undefined8 uVar2;
  long local_40;
  long local_38;
  undefined8 local_20 [2];
  
  local_40 = param_3;
  local_38 = param_2;
  while (local_38 != 0) {
    uVar2 = FUN_00b1fae2(local_38);
    cVar1 = FUN_00b0a97a(param_1,uVar2,param_4);
    if (cVar1 == '\x01') {
      local_38 = FUN_00b206f0(local_38);
    }
    else {
      local_40 = local_38;
      local_38 = FUN_00b206de(local_38);
    }
  }
  FUN_00b1fcd6(local_20,local_40);
  return local_20[0];
}


// ==== entry=00b1fca8 name=FUN_00b1fca8 size=45 ====

void FUN_00b1fca8(undefined8 param_1)

{
  undefined8 uVar1;
  undefined1 local_9;
  
  uVar1 = FUN_00b20702(param_1);
  FUN_00b206cc(&local_9,uVar1);
  return;
}


// ==== entry=00b1fcd6 name=FUN_00b1fcd6 size=26 ====

void FUN_00b1fcd6(undefined8 *param_1,undefined8 param_2)

{
  *param_1 = param_2;
  return;
}


// ==== entry=00b1fcf0 name=FUN_00b1fcf0 size=26 ====

void FUN_00b1fcf0(undefined8 param_1)

{
  FUN_00b2071c(param_1);
  return;
}


// ==== entry=00b1fd0a name=FUN_00b1fd0a size=82 ====

void FUN_00b1fd0a(undefined8 *param_1)

{
  FUN_00b2072a(param_1);
  *param_1 = 0;
  param_1[1] = 0;
  FUN_00b20746(param_1 + 2);
  FUN_00b20746(param_1 + 6);
  return;
}


// ==== entry=00b1fd5c name=FUN_00b1fd5c size=339 ====

/* WARNING: Type propagation algorithm not settling */

void FUN_00b1fd5c(long *param_1,ulong param_2)

{
  ulong uVar1;
  long *plVar2;
  long lVar3;
  long local_40 [3];
  long local_28;
  long local_20;
  
  uVar1 = FUN_00b0d748(4);
  local_20 = param_2 / uVar1 + 1;
  local_40[0] = param_2 / uVar1 + 3;
  local_40[1] = 8;
  plVar2 = (long *)FUN_00b06d34(local_40 + 1,local_40);
  param_1[1] = *plVar2;
  lVar3 = FUN_00b20780(param_1,param_1[1]);
  *param_1 = lVar3;
  local_28 = ((ulong)(param_1[1] - local_20) >> 1) * 8 + *param_1;
  local_40[2] = local_28 + local_20 * 8;
                    /* try { // try from 00b1fe2b to 00b1fe2f has its CatchHandler @ 00b1fea8 */
  FUN_00b207ee(param_1,local_28,local_40[2]);
  FUN_00b2012a(param_1 + 2,local_28);
  FUN_00b2012a(param_1 + 6,local_40[2] + -8);
  param_1[2] = param_1[3];
  lVar3 = param_1[7];
  uVar1 = FUN_00b0d748(4);
  param_1[6] = lVar3 + (param_2 % uVar1) * 4;
  return;
}


// ==== entry=00b1ff04 name=FUN_00b1ff04 size=11 ====

void FUN_00b1ff04(void)

{
  return;
}


// ==== entry=00b1ff10 name=FUN_00b1ff10 size=51 ====

void FUN_00b1ff10(undefined8 param_1,undefined8 param_2)

{
  undefined8 uVar1;
  
  uVar1 = FUN_00b0d748(4);
  FUN_00b20871(param_1,param_2,uVar1);
  return;
}


// ==== entry=00b1ff44 name=FUN_00b1ff44 size=52 ====

undefined8 FUN_00b1ff44(undefined8 param_1,undefined8 param_2)

{
  undefined8 uVar1;
  
  uVar1 = FUN_00b208a0(param_2);
  FUN_00b208ae(param_1,uVar1);
  return param_1;
}


// ==== entry=00b1ff78 name=FUN_00b1ff78 size=27 ====

void FUN_00b1ff78(undefined8 param_1)

{
  FUN_00b208ce(param_1);
  return;
}


// ==== entry=00b1ff93 name=FUN_00b1ff93 size=46 ====

void FUN_00b1ff93(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  FUN_00b208da(param_1,param_2,param_3);
  return;
}


// ==== entry=00b1ffc2 name=FUN_00b1ffc2 size=77 ====

void FUN_00b1ffc2(undefined8 *param_1,undefined8 *param_2)

{
  *param_1 = *param_2;
  param_1[1] = param_2[1];
  param_1[2] = param_2[2];
  param_1[3] = param_2[3];
  return;
}


// ==== entry=00b20010 name=FUN_00b20010 size=81 ====

void FUN_00b20010(long param_1,undefined8 *param_2)

{
  long lVar1;
  long lVar2;
  
  *(undefined8 **)(param_1 + 0x18) = param_2;
  *(undefined8 *)(param_1 + 8) = *param_2;
  lVar1 = *(long *)(param_1 + 8);
  lVar2 = FUN_00b208fd();
  *(long *)(param_1 + 0x10) = lVar1 + lVar2 * 4;
  return;
}


// ==== entry=00b20062 name=FUN_00b20062 size=62 ====

void FUN_00b20062(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  
  puVar2 = (undefined4 *)FUN_00b1f319(param_3);
  uVar1 = *puVar2;
  puVar2 = (undefined4 *)FUN_00b00efa(4,param_2);
  *puVar2 = uVar1;
  return;
}


// ==== entry=00b200a0 name=FUN_00b200a0 size=95 ====

void FUN_00b200a0(long *param_1,long param_2)

{
  if ((ulong)(param_1[1] - (param_1[9] - *param_1 >> 3)) < param_2 + 1U) {
    FUN_00b2090e(param_1,param_2,0);
  }
  return;
}


// ==== entry=00b20100 name=FUN_00b20100 size=42 ====

void FUN_00b20100(undefined8 param_1)

{
  undefined8 uVar1;
  
  uVar1 = FUN_00b0d748(4);
  FUN_00b20b2e(param_1,uVar1);
  return;
}


// ==== entry=00b2012a name=FUN_00b2012a size=81 ====

void FUN_00b2012a(long param_1,undefined8 *param_2)

{
  long lVar1;
  long lVar2;
  
  *(undefined8 **)(param_1 + 0x18) = param_2;
  *(undefined8 *)(param_1 + 8) = *param_2;
  lVar1 = *(long *)(param_1 + 8);
  lVar2 = FUN_00b20b58();
  *(long *)(param_1 + 0x10) = lVar1 + lVar2 * 4;
  return;
}


// ==== entry=00b2017c name=FUN_00b2017c size=15 ====

void FUN_00b2017c(void)

{
  return;
}


// ==== entry=00b2018c name=FUN_00b2018c size=39 ====

void FUN_00b2018c(undefined8 param_1)

{
  FUN_00b20b68(param_1);
  FUN_00b20b84(param_1);
  return;
}


// ==== entry=00b201b3 name=FUN_00b201b3 size=26 ====

void FUN_00b201b3(undefined8 param_1)

{
  FUN_00b20b9a(param_1);
  return;
}


// ==== entry=00b201cd name=FUN_00b201cd size=26 ====

void FUN_00b201cd(undefined8 param_1)

{
  FUN_00b20bb4(param_1);
  return;
}


// ==== entry=00b201e8 name=FUN_00b201e8 size=63 ====

void FUN_00b201e8(undefined8 param_1,undefined8 param_2)

{
  undefined8 uVar1;
  undefined8 uVar2;
  
  uVar1 = FUN_00b1f5f6(param_2);
  uVar2 = FUN_00b20bce(param_1);
  FUN_00b20bdc(uVar2,uVar1);
  return;
}


// ==== entry=00b20228 name=FUN_00b20228 size=54 ====

void FUN_00b20228(undefined8 param_1,undefined8 param_2)

{
  undefined8 uVar1;
  
  uVar1 = FUN_00b20bce(param_1);
  FUN_00b20c02(uVar1,param_2,1);
  return;
}


// ==== entry=00b2025e name=FUN_00b2025e size=26 ====

void FUN_00b2025e(undefined8 param_1)

{
  FUN_00b20c30(param_1);
  return;
}


// ==== entry=00b20278 name=FUN_00b20278 size=18 ====

long FUN_00b20278(long param_1)

{
  return param_1 + 8;
}


// ==== entry=00b2028a name=FUN_00b2028a size=150 ====

undefined8 FUN_00b2028a(undefined8 param_1,long param_2,long param_3,undefined8 param_4)

{
  char cVar1;
  undefined8 uVar2;
  long local_40;
  long local_38;
  undefined8 local_20 [2];
  
  local_40 = param_3;
  local_38 = param_2;
  while (local_38 != 0) {
    uVar2 = FUN_00b1fae2(local_38);
    cVar1 = FUN_00b0a97a(param_1,uVar2,param_4);
    if (cVar1 == '\x01') {
      local_38 = FUN_00b1f4f9(local_38);
    }
    else {
      local_40 = local_38;
      local_38 = FUN_00b1f50b(local_38);
    }
  }
  FUN_00b1fbd4(local_20,local_40);
  return local_20[0];
}


// ==== entry=00b20320 name=FUN_00b20320 size=26 ====

void FUN_00b20320(undefined8 param_1)

{
  FUN_00b20c4a(param_1);
  return;
}


// ==== entry=00b2033a name=FUN_00b2033a size=39 ====

void FUN_00b2033a(undefined8 param_1)

{
  undefined8 uVar1;
  
  uVar1 = FUN_00b20bce(param_1);
  FUN_00b20c58(uVar1,1);
  return;
}


// ==== entry=00b20362 name=FUN_00b20362 size=159 ====

void FUN_00b20362(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                 undefined8 param_5)

{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  
  FUN_00b00efa(0x30,param_2);
  uVar1 = FUN_00b0a9dd(param_5);
  uVar2 = FUN_00b0a9cf(param_4);
  uVar3 = FUN_00b0a9c1(param_3);
  uVar4 = FUN_00b1f5f6(param_2);
  uVar5 = FUN_00b20bce(param_1);
                    /* try { // try from 00b203ed to 00b203f1 has its CatchHandler @ 00b203f4 */
  FUN_00b20c82(uVar5,uVar4,uVar3,uVar2,uVar1);
  return;
}


// ==== entry=00b20434 name=FUN_00b20434 size=40 ====

undefined8 FUN_00b20434(undefined8 *param_1)

{
  undefined8 local_10;
  
  FUN_00b1fbd4(&local_10,*param_1);
  return local_10;
}


// ==== entry=00b2045c name=FUN_00b2045c size=18 ====

undefined8 FUN_00b2045c(long param_1)

{
  return *(undefined8 *)(param_1 + 0x28);
}


// ==== entry=00b2046e name=FUN_00b2046e size=18 ====

long FUN_00b2046e(long param_1)

{
  return param_1 + 0x20;
}


// ==== entry=00b20480 name=FUN_00b20480 size=68 ====

void FUN_00b20480(undefined8 *param_1,undefined8 param_2,undefined8 param_3)

{
  undefined8 *puVar1;
  
  puVar1 = (undefined8 *)FUN_00b204c4(param_2);
  *param_1 = *puVar1;
  puVar1 = (undefined8 *)FUN_00b01a96(param_3);
  param_1[1] = *puVar1;
  return;
}


// ==== entry=00b204c4 name=FUN_00b204c4 size=14 ====

undefined8 FUN_00b204c4(undefined8 param_1)

{
  return param_1;
}


// ==== entry=00b204d2 name=FUN_00b204d2 size=374 ====

undefined1  [16] FUN_00b204d2(undefined8 param_1,undefined8 param_2)

{
  char cVar1;
  undefined8 uVar2;
  undefined1 auVar3 [16];
  undefined8 local_78;
  long local_70;
  long local_68;
  undefined8 local_60;
  undefined8 local_58;
  undefined8 local_50;
  undefined8 local_48;
  undefined8 local_40;
  undefined8 local_38;
  undefined8 local_30;
  undefined8 local_28;
  char local_19;
  
  local_68 = FUN_00b1ee5c(param_1);
  local_70 = FUN_00b20278(param_1);
  local_19 = '\x01';
  while (local_68 != 0) {
    local_70 = local_68;
    uVar2 = FUN_00b1fae2(local_68);
    local_19 = FUN_00b0a97a(param_1,param_2,uVar2);
    if (local_19 == '\0') {
      local_68 = FUN_00b1f4f9(local_68);
    }
    else {
      local_68 = FUN_00b1f50b(local_68);
    }
  }
  FUN_00b1fbd4(&local_78,local_70);
  if (local_19 != '\0') {
    local_60 = FUN_00b20cee(param_1);
    cVar1 = FUN_00b1eec8(&local_78,&local_60);
    if (cVar1 != '\0') {
      FUN_00b20480(&local_58,&local_68,&local_70);
      goto LAB_00b20641;
    }
    FUN_00b2065a(&local_78);
  }
  uVar2 = FUN_00b1fca8(local_78);
  cVar1 = FUN_00b0a97a(param_1,uVar2,param_2);
  if (cVar1 == '\0') {
    local_28 = 0;
    FUN_00b01a5a(&local_38,&local_78,&local_28);
    local_58 = local_38;
    local_50 = local_30;
  }
  else {
    FUN_00b20480(&local_48,&local_68,&local_70);
    local_58 = local_48;
    local_50 = local_40;
  }
LAB_00b20641:
  auVar3._8_8_ = local_50;
  auVar3._0_8_ = local_58;
  return auVar3;
}


// ==== entry=00b20648 name=FUN_00b20648 size=18 ====

long FUN_00b20648(long param_1)

{
  return param_1 + 0x18;
}


// ==== entry=00b2065a name=FUN_00b2065a size=43 ====

undefined8 * FUN_00b2065a(undefined8 *param_1)

{
  undefined8 uVar1;
  
  uVar1 = std::_Rb_tree_decrement((_Rb_tree_node_base *)*param_1);
  *param_1 = uVar1;
  return param_1;
}


// ==== entry=00b20686 name=FUN_00b20686 size=43 ====

undefined8 * FUN_00b20686(undefined8 *param_1)

{
  undefined8 uVar1;
  
  uVar1 = std::_Rb_tree_increment((_Rb_tree_node_base *)*param_1);
  *param_1 = uVar1;
  return param_1;
}


// ==== entry=00b206b1 name=FUN_00b206b1 size=26 ====

void FUN_00b206b1(undefined8 param_1)

{
  FUN_00b1f13a(param_1);
  return;
}


// ==== entry=00b206cc name=FUN_00b206cc size=18 ====

undefined8 FUN_00b206cc(undefined8 param_1,undefined8 param_2)

{
  return param_2;
}


// ==== entry=00b206de name=FUN_00b206de size=18 ====

undefined8 FUN_00b206de(long param_1)

{
  return *(undefined8 *)(param_1 + 0x10);
}


// ==== entry=00b206f0 name=FUN_00b206f0 size=18 ====

undefined8 FUN_00b206f0(long param_1)

{
  return *(undefined8 *)(param_1 + 0x18);
}


// ==== entry=00b20702 name=FUN_00b20702 size=26 ====

void FUN_00b20702(undefined8 param_1)

{
  FUN_00b1f13a(param_1);
  return;
}


// ==== entry=00b2071c name=FUN_00b2071c size=14 ====

undefined8 FUN_00b2071c(undefined8 param_1)

{
  return param_1;
}


// ==== entry=00b2072a name=FUN_00b2072a size=27 ====

void FUN_00b2072a(undefined8 param_1)

{
  FUN_00b20d18(param_1);
  return;
}


// ==== entry=00b20746 name=FUN_00b20746 size=58 ====

void FUN_00b20746(undefined8 *param_1)

{
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  return;
}


// ==== entry=00b20780 name=FUN_00b20780 size=83 ====

undefined8 FUN_00b20780(undefined8 param_1,undefined8 param_2)

{
  undefined8 uVar1;
  undefined1 local_19 [9];
  
  FUN_00b1ff44(local_19,param_1);
                    /* try { // try from 00b207b2 to 00b207b6 has its CatchHandler @ 00b207cc */
  uVar1 = FUN_00b20d23(local_19,param_2);
  FUN_00b1ff78(local_19);
  return uVar1;
}


// ==== entry=00b207ee name=FUN_00b207ee size=76 ====

void FUN_00b207ee(undefined8 param_1,undefined8 *param_2,undefined8 *param_3)

{
  undefined8 uVar1;
  undefined8 *local_20;
  
  for (local_20 = param_2; local_20 < param_3; local_20 = local_20 + 1) {
                    /* try { // try from 00b2081c to 00b20820 has its CatchHandler @ 00b20832 */
    uVar1 = FUN_00b20100(param_1);
    *local_20 = uVar1;
  }
  return;
}


// ==== entry=00b20871 name=FUN_00b20871 size=46 ====

void FUN_00b20871(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  FUN_00b20d4e(param_1,param_2,param_3);
  return;
}


// ==== entry=00b208a0 name=FUN_00b208a0 size=14 ====

undefined8 FUN_00b208a0(undefined8 param_1)

{
  return param_1;
}


// ==== entry=00b208ae name=FUN_00b208ae size=31 ====

void FUN_00b208ae(undefined8 param_1)

{
  FUN_00b20d72(param_1);
  return;
}


// ==== entry=00b208ce name=FUN_00b208ce size=11 ====

void FUN_00b208ce(void)

{
  return;
}


// ==== entry=00b208da name=FUN_00b208da size=35 ====

void FUN_00b208da(undefined8 param_1,void *param_2)

{
  operator_delete(param_2);
  return;
}


// ==== entry=00b208fd name=FUN_00b208fd size=16 ====

void FUN_00b208fd(void)

{
  FUN_00b0d748(4);
  return;
}


// ==== entry=00b2090e name=FUN_00b2090e size=544 ====

void FUN_00b2090e(long *param_1,long param_2,char param_3)

{
  long *plVar1;
  long lVar2;
  long local_58;
  long *local_50;
  long local_40;
  long local_38;
  long local_30;
  long local_28;
  ulong local_20;
  
  local_28 = (param_1[9] - param_1[5] >> 3) + 1;
  local_30 = local_28 + param_2;
  local_58 = param_2;
  local_50 = param_1;
  if ((ulong)(local_30 * 2) < (ulong)param_1[1]) {
    if (param_3 == '\0') {
      param_2 = 0;
    }
    else {
      param_2 = param_2 << 3;
    }
    local_20 = param_2 + ((ulong)(param_1[1] - local_30) >> 1) * 8 + *param_1;
    if (local_20 < (ulong)param_1[5]) {
      FUN_00b20d7d(param_1[5],param_1[9] + 8,local_20);
    }
    else {
      FUN_00b20dc9(param_1[5],param_1[9] + 8,local_28 * 8 + local_20);
    }
  }
  else {
    lVar2 = param_1[1];
    plVar1 = (long *)FUN_00b06d34(param_1 + 1,&local_58);
    local_38 = *plVar1 + lVar2 + 2;
    local_40 = FUN_00b20780(local_50,local_38);
    if (param_3 == '\0') {
      lVar2 = 0;
    }
    else {
      lVar2 = local_58 << 3;
    }
    local_20 = local_40 + ((ulong)(local_38 - local_30) >> 1) * 8 + lVar2;
    FUN_00b20d7d(local_50[5],local_50[9] + 8,local_20);
    FUN_00b1f208(local_50,*local_50,local_50[1]);
    *local_50 = local_40;
    local_50[1] = local_38;
  }
  FUN_00b2012a(local_50 + 2,local_20);
  FUN_00b2012a(local_50 + 6,local_20 + local_28 * 8 + -8);
  return;
}


// ==== entry=00b20b2e name=FUN_00b20b2e size=42 ====

void FUN_00b20b2e(undefined8 param_1,undefined8 param_2)

{
  FUN_00b20e16(param_1,param_2,0);
  return;
}


// ==== entry=00b20b58 name=FUN_00b20b58 size=16 ====

void FUN_00b20b58(void)

{
  FUN_00b0d748(4);
  return;
}


// ==== entry=00b20b68 name=FUN_00b20b68 size=27 ====

void FUN_00b20b68(undefined8 param_1)

{
  FUN_00b20e58(param_1);
  return;
}


// ==== entry=00b20b84 name=FUN_00b20b84 size=22 ====

void FUN_00b20b84(undefined8 *param_1)

{
  *param_1 = 0;
  return;
}


// ==== entry=00b20b9a name=FUN_00b20b9a size=26 ====

void FUN_00b20b9a(undefined8 param_1)

{
  FUN_00b20e63(param_1);
  return;
}


// ==== entry=00b20bb4 name=FUN_00b20bb4 size=26 ====

void FUN_00b20bb4(undefined8 param_1)

{
  FUN_00b20e71(param_1);
  return;
}


// ==== entry=00b20bce name=FUN_00b20bce size=14 ====

undefined8 FUN_00b20bce(undefined8 param_1)

{
  return param_1;
}


// ==== entry=00b20bdc name=FUN_00b20bdc size=38 ====

void FUN_00b20bdc(undefined8 param_1,undefined8 param_2)

{
  FUN_00b20ea8(param_1,param_2);
  return;
}


// ==== entry=00b20c02 name=FUN_00b20c02 size=46 ====

void FUN_00b20c02(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  FUN_00b20ec8(param_1,param_2,param_3);
  return;
}


// ==== entry=00b20c30 name=FUN_00b20c30 size=26 ====

void FUN_00b20c30(undefined8 param_1)

{
  FUN_00b20eeb(param_1);
  return;
}


// ==== entry=00b20c4a name=FUN_00b20c4a size=14 ====

undefined8 FUN_00b20c4a(undefined8 param_1)

{
  return param_1;
}


// ==== entry=00b20c58 name=FUN_00b20c58 size=42 ====

void FUN_00b20c58(undefined8 param_1,undefined8 param_2)

{
  FUN_00b20f06(param_1,param_2,0);
  return;
}


// ==== entry=00b20c82 name=FUN_00b20c82 size=108 ====

void FUN_00b20c82(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                 undefined8 param_5)

{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  
  uVar1 = FUN_00b0a9dd(param_5);
  uVar2 = FUN_00b0a9cf(param_4);
  uVar3 = FUN_00b0a9c1(param_3);
  FUN_00b20f52(param_1,param_2,uVar3,uVar2,uVar1);
  return;
}


// ==== entry=00b20cee name=FUN_00b20cee size=41 ====

undefined8 FUN_00b20cee(long param_1)

{
  undefined8 local_10;
  
  FUN_00b1fbd4(&local_10,*(undefined8 *)(param_1 + 0x18));
  return local_10;
}


// ==== entry=00b20d18 name=FUN_00b20d18 size=11 ====

void FUN_00b20d18(void)

{
  return;
}


// ==== entry=00b20d23 name=FUN_00b20d23 size=42 ====

void FUN_00b20d23(undefined8 param_1,undefined8 param_2)

{
  FUN_00b20ff2(param_1,param_2,0);
  return;
}


// ==== entry=00b20d4e name=FUN_00b20d4e size=35 ====

void FUN_00b20d4e(undefined8 param_1,void *param_2)

{
  operator_delete(param_2);
  return;
}


// ==== entry=00b20d72 name=FUN_00b20d72 size=11 ====

void FUN_00b20d72(void)

{
  return;
}


// ==== entry=00b20d7d name=FUN_00b20d7d size=76 ====

void FUN_00b20d7d(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  undefined8 uVar1;
  undefined8 uVar2;
  
  uVar1 = FUN_00b21034(param_2);
  uVar2 = FUN_00b21034(param_1);
  FUN_00b21042(uVar2,uVar1,param_3);
  return;
}


// ==== entry=00b20dc9 name=FUN_00b20dc9 size=76 ====

void FUN_00b20dc9(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  undefined8 uVar1;
  undefined8 uVar2;
  
  uVar1 = FUN_00b21034(param_2);
  uVar2 = FUN_00b21034(param_1);
  FUN_00b2109a(uVar2,uVar1,param_3);
  return;
}


// ==== entry=00b20e16 name=FUN_00b20e16 size=66 ====

void FUN_00b20e16(undefined8 param_1,ulong param_2)

{
  ulong uVar1;
  
  uVar1 = FUN_00b210f2(param_1);
  if (uVar1 < param_2) {
                    /* WARNING: Subroutine does not return */
    std::__throw_bad_alloc();
  }
  operator_new(param_2 << 2);
  return;
}


// ==== entry=00b20e58 name=FUN_00b20e58 size=11 ====

void FUN_00b20e58(void)

{
  return;
}


// ==== entry=00b20e63 name=FUN_00b20e63 size=14 ====

undefined8 FUN_00b20e63(undefined8 param_1)

{
  return param_1;
}


// ==== entry=00b20e71 name=FUN_00b20e71 size=26 ====

void FUN_00b20e71(undefined8 param_1)

{
  FUN_00b21106(param_1);
  return;
}


// ==== entry=00b20e8c name=FUN_00b20e8c size=27 ====

void FUN_00b20e8c(string *param_1)

{
  std::string::~string(param_1);
  return;
}


// ==== entry=00b20ea8 name=FUN_00b20ea8 size=31 ====

void FUN_00b20ea8(undefined8 param_1,undefined8 param_2)

{
  FUN_00b20e8c(param_2);
  return;
}


// ==== entry=00b20ec8 name=FUN_00b20ec8 size=35 ====

void FUN_00b20ec8(undefined8 param_1,void *param_2)

{
  operator_delete(param_2);
  return;
}


// ==== entry=00b20eeb name=FUN_00b20eeb size=26 ====

void FUN_00b20eeb(undefined8 param_1)

{
  FUN_00b21114(param_1);
  return;
}


// ==== entry=00b20f06 name=FUN_00b20f06 size=75 ====

void FUN_00b20f06(undefined8 param_1,ulong param_2)

{
  ulong uVar1;
  
  uVar1 = FUN_00b21122(param_1);
  if (uVar1 < param_2) {
                    /* WARNING: Subroutine does not return */
    std::__throw_bad_alloc();
  }
  operator_new(param_2 * 0x30);
  return;
}


// ==== entry=00b20f52 name=FUN_00b20f52 size=135 ====

void FUN_00b20f52(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                 undefined8 param_5)

{
  undefined8 uVar1;
  undefined1 local_38 [24];
  
  FUN_00b0a9c1(param_3);
  uVar1 = FUN_00b0a9cf(param_4);
  FUN_00b0bc82(local_38,uVar1);
  FUN_00b0a9dd(param_5);
  uVar1 = FUN_00b00efa(0x10,param_2);
                    /* try { // try from 00b20fc7 to 00b20fcb has its CatchHandler @ 00b20fce */
  FUN_00b21136(uVar1,local_38);
  return;
}


// ==== entry=00b20ff2 name=FUN_00b20ff2 size=66 ====

void FUN_00b20ff2(undefined8 param_1,ulong param_2)

{
  ulong uVar1;
  
  uVar1 = FUN_00b21160(param_1);
  if (uVar1 < param_2) {
                    /* WARNING: Subroutine does not return */
    std::__throw_bad_alloc();
  }
  operator_new(param_2 << 3);
  return;
}


// ==== entry=00b21034 name=FUN_00b21034 size=14 ====

undefined8 FUN_00b21034(undefined8 param_1)

{
  return param_1;
}


// ==== entry=00b21042 name=FUN_00b21042 size=88 ====

void FUN_00b21042(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  
  uVar1 = FUN_00b21174(param_3);
  uVar2 = FUN_00b21174(param_2);
  uVar3 = FUN_00b21174(param_1);
  FUN_00b21182(uVar3,uVar2,uVar1);
  return;
}


// ==== entry=00b2109a name=FUN_00b2109a size=88 ====

void FUN_00b2109a(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  
  uVar1 = FUN_00b21174(param_3);
  uVar2 = FUN_00b21174(param_2);
  uVar3 = FUN_00b21174(param_1);
  FUN_00b211b3(uVar3,uVar2,uVar1);
  return;
}


// ==== entry=00b210f2 name=FUN_00b210f2 size=20 ====

undefined8 FUN_00b210f2(void)

{
  return 0x3fffffffffffffff;
}


// ==== entry=00b21106 name=FUN_00b21106 size=14 ====

undefined8 FUN_00b21106(undefined8 param_1)

{
  return param_1;
}


// ==== entry=00b21114 name=FUN_00b21114 size=14 ====

undefined8 FUN_00b21114(undefined8 param_1)

{
  return param_1;
}


// ==== entry=00b21122 name=FUN_00b21122 size=20 ====

undefined8 FUN_00b21122(void)

{
  return 0x555555555555555;
}


// ==== entry=00b21136 name=FUN_00b21136 size=42 ====

void FUN_00b21136(undefined8 param_1,undefined8 param_2)

{
  FUN_00b211e4(param_1,param_2,&stack0x00000008);
  return;
}


// ==== entry=00b21160 name=FUN_00b21160 size=20 ====

undefined8 FUN_00b21160(void)

{
  return 0x1fffffffffffffff;
}


// ==== entry=00b21174 name=FUN_00b21174 size=14 ====

undefined8 FUN_00b21174(undefined8 param_1)

{
  return param_1;
}


// ==== entry=00b21182 name=FUN_00b21182 size=49 ====

void FUN_00b21182(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  FUN_00b21230(param_1,param_2,param_3);
  return;
}


// ==== entry=00b211b3 name=FUN_00b211b3 size=49 ====

void FUN_00b211b3(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  FUN_00b2128f(param_1,param_2,param_3);
  return;
}


// ==== entry=00b211e4 name=FUN_00b211e4 size=76 ====

void FUN_00b211e4(string *param_1,undefined8 param_2)

{
  undefined8 uVar1;
  string *psVar2;
  
  uVar1 = FUN_00b0be86(param_2);
  psVar2 = (string *)FUN_00b0be11(uVar1);
  std::string::string(param_1,psVar2);
  *(undefined8 *)(param_1 + 8) = 0;
  return;
}


// ==== entry=00b21230 name=FUN_00b21230 size=95 ====

void * FUN_00b21230(void *param_1,long param_2,void *param_3)

{
  long lVar1;
  
  lVar1 = param_2 - (long)param_1 >> 3;
  if (lVar1 != 0) {
    memmove(param_3,param_1,lVar1 * 8);
  }
  return (void *)((long)param_3 + lVar1 * 8);
}


// ==== entry=00b2128f name=FUN_00b2128f size=114 ====

long FUN_00b2128f(void *param_1,long param_2,long param_3)

{
  long lVar1;
  
  lVar1 = param_2 - (long)param_1 >> 3;
  if (lVar1 != 0) {
    memmove((void *)(lVar1 * -8 + param_3),param_1,lVar1 * 8);
  }
  return param_3 + lVar1 * -8;
}


// ==== entry=00b21302 name=FUN_00b21302 size=569 ====

void FUN_00b21302(undefined8 *param_1,istream *param_2)

{
  char cVar1;
  int iVar2;
  void *pvVar3;
  long lVar4;
  int local_48 [6];
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  
  *param_1 = param_2;
  FUN_00b21dd2(param_1 + 1);
  *(undefined4 *)((long)param_1 + 0x14) = 0;
  FUN_00b22172(param_1 + 3);
                    /* try { // try from 00b2134e to 00b21530 has its CatchHandler @ 00b21533 */
  pvVar3 = operator_new__(0x800);
  param_1[0xd] = pvVar3;
  param_1[0xe] = 0;
  param_1[0xf] = 0;
  cVar1 = std::ios::operator!((ios *)(param_2 + *(long *)(*(long *)param_2 + -0x18)));
  if (cVar1 == '\0') {
    local_48[0] = 0;
    local_48[1] = 0;
    local_48[2] = 0;
    local_48[3] = 0;
    local_1c = 0;
    local_20 = 0;
    while ((&DAT_011be920)[local_20] == '\0') {
      local_28 = std::istream::get(param_2);
      lVar4 = (long)local_1c;
      local_1c = local_1c + 1;
      local_48[lVar4] = local_28;
      local_2c = FUN_00b21dfd(local_28);
      local_30 = *(int *)(&DAT_011be940 + ((long)local_2c + (long)local_20 * 8) * 4);
      local_24 = (int)(char)(&DAT_011beb80)[(long)local_20 * 8 + (long)local_2c];
      if (0 < local_24) {
        std::ios::clear((ios *)(param_2 + *(long *)(*(long *)param_2 + -0x18)),0);
        for (; 0 < local_24; local_24 = local_24 + -1) {
          iVar2 = FUN_00b21dc7();
          local_1c = local_1c + -1;
          if (iVar2 != local_48[local_1c]) {
            cVar1 = FUN_00b21db7(local_48 + local_1c);
            std::istream::putback(param_2,cVar1);
          }
        }
      }
      local_20 = local_30;
    }
    switch(local_20) {
    case 4:
      *(undefined4 *)((long)param_1 + 0x14) = 4;
      break;
    case 5:
      *(undefined4 *)((long)param_1 + 0x14) = 2;
      break;
    default:
      *(undefined4 *)((long)param_1 + 0x14) = 0;
      break;
    case 10:
      *(undefined4 *)((long)param_1 + 0x14) = 1;
      break;
    case 0xb:
      *(undefined4 *)((long)param_1 + 0x14) = 3;
      break;
    case 0x11:
      *(undefined4 *)((long)param_1 + 0x14) = 0;
    }
    FUN_00b0d814(param_1,0);
  }
  return;
}


// ==== entry=00b2155a name=FUN_00b2155a size=60 ====

void FUN_00b2155a(long param_1)

{
  if (*(long *)(param_1 + 0x68) != 0) {
    operator_delete__(*(void **)(param_1 + 0x68));
  }
  FUN_00b2218e(param_1 + 0x18);
  return;
}


// ==== entry=00b21596 name=FUN_00b21596 size=65 ====

ulong FUN_00b21596(long param_1)

{
  char cVar1;
  ulong uVar2;
  byte *pbVar3;
  
  cVar1 = FUN_00b221fc(param_1 + 0x18);
  if (cVar1 == '\0') {
    pbVar3 = (byte *)FUN_00b0ef08(param_1 + 0x18,0);
    uVar2 = (ulong)*pbVar3;
  }
  else {
    uVar2 = FUN_00b0d78f();
  }
  return uVar2;
}


// ==== entry=00b215d8 name=FUN_00b215d8 size=127 ====

undefined8 FUN_00b215d8(long *param_1)

{
  char cVar1;
  char cVar2;
  char *pcVar3;
  undefined8 uVar4;
  
  cVar1 = std::ios::good((ios *)(*(long *)(*(long *)*param_1 + -0x18) + *param_1));
  if (cVar1 == '\0') {
    cVar1 = FUN_00b221fc(param_1 + 3);
    if (cVar1 != '\x01') {
      pcVar3 = (char *)FUN_00b0ef08(param_1 + 3,0);
      cVar1 = *pcVar3;
      cVar2 = FUN_00b0d78f();
      if (cVar1 != cVar2) goto LAB_00b21644;
    }
    uVar4 = 0;
  }
  else {
LAB_00b21644:
    uVar4 = 1;
  }
  return uVar4;
}


// ==== entry=00b21658 name=FUN_00b21658 size=96 ====

char FUN_00b21658(long param_1)

{
  char cVar1;
  
  cVar1 = FUN_00b21596(param_1);
  FUN_00b21780(param_1);
  *(int *)(param_1 + 0x10) = *(int *)(param_1 + 0x10) + 1;
  if (cVar1 == '\n') {
    *(undefined4 *)(param_1 + 0x10) = 0;
    *(int *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) + 1;
  }
  return cVar1;
}


// ==== entry=00b216b8 name=FUN_00b216b8 size=121 ====

string * FUN_00b216b8(string *param_1,undefined8 param_2,int param_3)

{
  char cVar1;
  undefined4 local_1c;
  
  std::string::string(param_1);
  if (0 < param_3) {
                    /* try { // try from 00b216ee to 00b2171e has its CatchHandler @ 00b21725 */
    std::string::reserve(param_1,(long)param_3);
    for (local_1c = 0; local_1c < param_3; local_1c = local_1c + 1) {
      cVar1 = FUN_00b21658(param_2);
      std::string::operator+=(param_1,cVar1);
    }
  }
  return param_1;
}


// ==== entry=00b2174c name=FUN_00b2174c size=51 ====

void FUN_00b2174c(undefined8 param_1,int param_2)

{
  undefined4 local_c;
  
  for (local_c = 0; local_c < param_2; local_c = local_c + 1) {
    FUN_00b21658(param_1);
  }
  return;
}


// ==== entry=00b21780 name=FUN_00b21780 size=88 ====

void FUN_00b21780(long param_1)

{
  char cVar1;
  
  cVar1 = FUN_00b221fc(param_1 + 0x18);
  if (cVar1 != '\x01') {
    FUN_00b22226(param_1 + 0x18);
    *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 1;
  }
  FUN_00b0d814(param_1,0);
  return;
}


// ==== entry=00b217d8 name=FUN_00b217d8 size=295 ====

bool FUN_00b217d8(long *param_1,ulong param_2)

{
  bool bVar1;
  char cVar2;
  ulong uVar3;
  undefined1 local_19 [9];
  
  while( true ) {
    cVar2 = std::ios::good((ios *)(*(long *)(*(long *)*param_1 + -0x18) + *param_1));
    if ((cVar2 == '\0') || (uVar3 = FUN_00b0ef32(param_1 + 3), param_2 < uVar3)) {
      bVar1 = false;
    }
    else {
      bVar1 = true;
    }
    if (!bVar1) break;
    switch(*(undefined4 *)((long)param_1 + 0x14)) {
    case 0:
      FUN_00b21900(param_1);
      break;
    case 1:
      FUN_00b21964(param_1);
      break;
    case 2:
      FUN_00b21964(param_1);
      break;
    case 3:
      FUN_00b21c76(param_1);
      break;
    case 4:
      FUN_00b21c76(param_1);
    }
  }
  cVar2 = std::ios::good((ios *)(*(long *)(*(long *)*param_1 + -0x18) + *param_1));
  if (cVar2 != '\x01') {
    local_19[0] = FUN_00b0d78f();
    FUN_00b22140(param_1 + 3,local_19);
  }
  uVar3 = FUN_00b0ef32(param_1 + 3);
  return param_2 < uVar3;
}


// ==== entry=00b21900 name=FUN_00b21900 size=99 ====

void FUN_00b21900(long *param_1)

{
  char cVar1;
  undefined1 local_a;
  undefined1 local_9;
  
  local_9 = FUN_00b21b7e(param_1);
  cVar1 = std::ios::good((ios *)(*(long *)(*(long *)*param_1 + -0x18) + *param_1));
  if (cVar1 != '\0') {
    local_a = local_9;
    FUN_00b22140(param_1 + 3,&local_a);
  }
  return;
}


// ==== entry=00b21964 name=FUN_00b21964 size=538 ====

void FUN_00b21964(long *param_1)

{
  char cVar1;
  undefined1 local_22 [2];
  ulong local_20;
  uint local_14;
  ulong local_10;
  
  local_10 = 0;
  local_14 = (uint)(*(int *)((long)param_1 + 0x14) != 2);
  local_22[0] = FUN_00b21b7e(param_1);
  local_22[1] = FUN_00b21b7e(param_1);
  cVar1 = std::ios::good((ios *)(*(long *)(*(long *)*param_1 + -0x18) + *param_1));
  if (cVar1 == '\x01') {
    local_10 = (ulong)CONCAT11(local_22[(int)local_14],local_22[(int)(local_14 ^ 1)]);
    if ((local_10 < 0xdc00) || (0xdfff < local_10)) {
      if ((local_10 < 0xd800) || (0xdbff < local_10)) {
LAB_00b21b62:
        FUN_00b21f0f(param_1 + 3,local_10);
      }
      else {
        while( true ) {
          local_22[0] = FUN_00b21b7e(param_1);
          local_22[1] = FUN_00b21b7e(param_1);
          cVar1 = std::ios::good((ios *)(*(long *)(*(long *)*param_1 + -0x18) + *param_1));
          if (cVar1 != '\x01') break;
          local_20 = (ulong)CONCAT11(local_22[(int)local_14],local_22[(int)(local_14 ^ 1)]);
          if ((0xdbff < local_20) && (local_20 < 0xe000)) {
            local_10 = ((local_10 & 0x3ff) << 10 |
                       (ulong)(CONCAT11(local_22[(int)local_14],local_22[(int)(local_14 ^ 1)]) &
                              0x3ff)) + 0x10000;
            goto LAB_00b21b62;
          }
          FUN_00b21f0f(param_1 + 3,0xfffd);
          if ((local_20 < 0xd800) || (0xdfff < local_20)) {
            FUN_00b21f0f(param_1 + 3,local_10);
            return;
          }
          local_10 = local_20;
        }
        FUN_00b21f0f(param_1 + 3,0xfffd);
      }
    }
    else {
      FUN_00b21f0f(param_1 + 3,0xfffd);
    }
  }
  return;
}


// ==== entry=00b21b7e name=FUN_00b21b7e size=247 ====

undefined1 FUN_00b21b7e(long *param_1)

{
  char *pcVar1;
  long lVar2;
  
  if ((ulong)param_1[0xe] <= (ulong)param_1[0xf]) {
    pcVar1 = (char *)std::ios::rdbuf((ios *)(*(long *)(*(long *)*param_1 + -0x18) + *param_1));
    lVar2 = FUN_00b22124(param_1[0xd]);
    lVar2 = std::streambuf::sgetn(pcVar1,lVar2);
    param_1[0xe] = lVar2;
    param_1[0xf] = 0;
    if (param_1[0xe] == 0) {
      std::ios::setstate((ios *)(*(long *)(*(long *)*param_1 + -0x18) + *param_1),2);
    }
    if (param_1[0xe] == 0) {
      return 0;
    }
  }
  lVar2 = param_1[0xf];
  param_1[0xf] = lVar2 + 1;
  return *(undefined1 *)(lVar2 + param_1[0xd]);
}


// ==== entry=00b21c76 name=FUN_00b21c76 size=238 ====

void FUN_00b21c76(long *param_1)

{
  char cVar1;
  byte local_24 [4];
  undefined *local_20;
  int local_14;
  ulong local_10;
  
  local_10 = 0;
  if (*(int *)((long)param_1 + 0x14) == 4) {
    local_20 = &DAT_011bec30;
  }
  else {
    local_20 = &DAT_011bec20;
  }
  local_24[0] = FUN_00b21b7e(param_1);
  local_24[1] = FUN_00b21b7e(param_1);
  local_24[2] = FUN_00b21b7e(param_1);
  local_24[3] = FUN_00b21b7e(param_1);
  cVar1 = std::ios::good((ios *)(*(long *)(*(long *)*param_1 + -0x18) + *param_1));
  if (cVar1 == '\x01') {
    for (local_14 = 0; local_14 < 4; local_14 = local_14 + 1) {
      local_10 = local_10 << 8;
      local_10 = local_10 | local_24[*(int *)(local_20 + (long)local_14 * 4)];
    }
    FUN_00b21f0f(param_1 + 3,local_10);
  }
  return;
}


// ==== entry=00b21d64 name=FUN_00b21d64 size=62 ====

void FUN_00b21d64(int param_1,int param_2)

{
  if ((param_1 == 1) && (param_2 == 0xffff)) {
    std::ios_base::Init::Init((Init *)&DAT_011c34e0);
    __cxa_atexit(std::ios_base::Init::~Init,&DAT_011c34e0,&DAT_00c89008);
  }
  return;
}


// ==== entry=00b21da2 orig=FUN_00b21da2 size=21 name=_INIT_175 ====

void _INIT_175(void)

{
  FUN_00b21d64(1,0xffff);
  return;
}


// ==== entry=00b21db7 name=FUN_00b21db7 size=16 ====

undefined4 FUN_00b21db7(undefined4 *param_1)

{
  return *param_1;
}


// ==== entry=00b21dc7 name=FUN_00b21dc7 size=11 ====

undefined8 FUN_00b21dc7(void)

{
  return 0xffffffff;
}


// ==== entry=00b21dd2 name=FUN_00b21dd2 size=43 ====

void FUN_00b21dd2(undefined4 *param_1)

{
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  return;
}


// ==== entry=00b21dfd name=FUN_00b21dfd size=171 ====

undefined8 FUN_00b21dfd(int param_1)

{
  int iVar1;
  undefined8 uVar2;
  
  iVar1 = FUN_00b21dc7();
  if (param_1 == iVar1) {
    uVar2 = 7;
  }
  else if (param_1 == 0xbf) {
    uVar2 = 2;
  }
  else {
    if (param_1 < 0xc0) {
      if (param_1 == 0) {
        return 0;
      }
      if (param_1 == 0xbb) {
        return 1;
      }
    }
    else {
      if (param_1 == 0xfe) {
        return 4;
      }
      if (param_1 == 0xff) {
        return 5;
      }
      if (param_1 == 0xef) {
        return 3;
      }
    }
    if ((param_1 < 1) || (0xfe < param_1)) {
      uVar2 = 7;
    }
    else {
      uVar2 = 6;
    }
  }
  return uVar2;
}


// ==== entry=00b21ea8 name=FUN_00b21ea8 size=103 ====

undefined8 FUN_00b21ea8(ulong param_1,byte param_2,byte param_3)

{
  param_1 = param_1 >> (param_3 & 0x3f);
  return CONCAT71((int7)(param_1 >> 8),
                  (byte)param_1 & (byte)(0xff >> (param_2 + 1 & 0x1f)) |
                  (byte)((1 << (param_2 & 0x1f)) + -1 << (8 - param_2 & 0x1f)));
}


// ==== entry=00b21f0f name=FUN_00b21f0f size=533 ====

void FUN_00b21f0f(undefined8 param_1,ulong param_2)

{
  char cVar1;
  ulong local_28;
  undefined1 local_12;
  undefined1 local_11;
  undefined1 local_10;
  undefined1 local_f;
  undefined1 local_e;
  undefined1 local_d;
  undefined1 local_c;
  undefined1 local_b;
  undefined1 local_a;
  undefined1 local_9;
  
  cVar1 = FUN_00b0d78f();
  local_28 = param_2;
  if (param_2 == (long)cVar1) {
    local_28 = 0xfffd;
  }
  if (local_28 < 0x80) {
    local_12 = FUN_00b21ea8(local_28,0,0);
    FUN_00b22140(param_1,&local_12);
  }
  else if (local_28 < 0x800) {
    local_11 = FUN_00b21ea8(local_28,2,6);
    FUN_00b22140(param_1,&local_11);
    local_10 = FUN_00b21ea8(local_28,1,0);
    FUN_00b22140(param_1,&local_10);
  }
  else if (local_28 < 0x10000) {
    local_f = FUN_00b21ea8(local_28,3,0xc);
    FUN_00b22140(param_1,&local_f);
    local_e = FUN_00b21ea8(local_28,1,6);
    FUN_00b22140(param_1,&local_e);
    local_d = FUN_00b21ea8(local_28,1,0);
    FUN_00b22140(param_1,&local_d);
  }
  else {
    local_c = FUN_00b21ea8(local_28,4,0x12);
    FUN_00b22140(param_1,&local_c);
    local_b = FUN_00b21ea8(local_28,1,0xc);
    FUN_00b22140(param_1,&local_b);
    local_a = FUN_00b21ea8(local_28,1,6);
    FUN_00b22140(param_1,&local_a);
    local_9 = FUN_00b21ea8(local_28,1,0);
    FUN_00b22140(param_1,&local_9);
  }
  return;
}


// ==== entry=00b22124 name=FUN_00b22124 size=14 ====

undefined8 FUN_00b22124(undefined8 param_1)

{
  return param_1;
}


// ==== entry=00b22132 name=FUN_00b22132 size=14 ====

undefined8 FUN_00b22132(undefined8 param_1)

{
  return param_1;
}


// ==== entry=00b22140 name=FUN_00b22140 size=49 ====

void FUN_00b22140(undefined8 param_1,undefined8 param_2)

{
  undefined8 uVar1;
  
  uVar1 = FUN_00b22132(param_2);
  FUN_00b22296(param_1,uVar1);
  return;
}


// ==== entry=00b22172 name=FUN_00b22172 size=27 ====

void FUN_00b22172(undefined8 param_1)

{
  FUN_00b22338(param_1);
  return;
}


// ==== entry=00b2218e name=FUN_00b2218e size=109 ====

void FUN_00b2218e(undefined8 param_1)

{
  undefined8 uVar1;
  undefined1 local_58 [32];
  undefined1 local_38 [40];
  
  uVar1 = FUN_00b2244a(param_1);
  FUN_00b2241c(local_58,param_1);
  FUN_00b223ee(local_38,param_1);
  FUN_00b22458(param_1,local_38,local_58,uVar1);
  FUN_00b22386(param_1);
  return;
}


// ==== entry=00b221fc name=FUN_00b221fc size=41 ====

void FUN_00b221fc(long param_1)

{
  FUN_00b2246f(param_1 + 0x30,param_1 + 0x10);
  return;
}


// ==== entry=00b22226 name=FUN_00b22226 size=97 ====

void FUN_00b22226(long param_1)

{
  if (*(long *)(param_1 + 0x10) == *(long *)(param_1 + 0x20) + -1) {
    FUN_00b224b8(param_1);
  }
  else {
    FUN_00b22491(param_1,*(undefined8 *)(param_1 + 0x10));
    *(long *)(param_1 + 0x10) = *(long *)(param_1 + 0x10) + 1;
  }
  return;
}


// ==== entry=00b22287 name=FUN_00b22287 size=14 ====

undefined8 FUN_00b22287(undefined8 param_1)

{
  return param_1;
}


// ==== entry=00b22296 name=FUN_00b22296 size=134 ====

void FUN_00b22296(long param_1,undefined8 param_2)

{
  undefined8 uVar1;
  
  if (*(long *)(param_1 + 0x30) == *(long *)(param_1 + 0x40) + -1) {
    uVar1 = FUN_00b22287(param_2);
    FUN_00b2256c(param_1,uVar1);
  }
  else {
    uVar1 = FUN_00b22287(param_2);
    FUN_00b22532(param_1,*(undefined8 *)(param_1 + 0x30),uVar1);
    *(long *)(param_1 + 0x30) = *(long *)(param_1 + 0x30) + 1;
  }
  return;
}


// ==== entry=00b2231c name=FUN_00b2231c size=27 ====

void FUN_00b2231c(allocator<char> *param_1)

{
  std::allocator<char>::~allocator(param_1);
  return;
}


// ==== entry=00b22338 name=FUN_00b22338 size=51 ====

void FUN_00b22338(undefined8 param_1)

{
  FUN_00b22606(param_1);
                    /* try { // try from 00b2235d to 00b22361 has its CatchHandler @ 00b22364 */
  FUN_00b22658(param_1,0);
  return;
}


// ==== entry=00b22386 name=FUN_00b22386 size=104 ====

void FUN_00b22386(long *param_1)

{
  if (*param_1 != 0) {
    FUN_00b227fc(param_1,param_1[5],param_1[9] + 8);
    FUN_00b22842(param_1,*param_1,param_1[1]);
  }
  FUN_00b2231c(param_1);
  return;
}


// ==== entry=00b223ee name=FUN_00b223ee size=45 ====

undefined8 FUN_00b223ee(undefined8 param_1,long param_2)

{
  FUN_00b116a4(param_1,param_2 + 0x10);
  return param_1;
}


// ==== entry=00b2241c name=FUN_00b2241c size=45 ====

undefined8 FUN_00b2241c(undefined8 param_1,long param_2)

{
  FUN_00b116a4(param_1,param_2 + 0x30);
  return param_1;
}


// ==== entry=00b2244a name=FUN_00b2244a size=14 ====

undefined8 FUN_00b2244a(undefined8 param_1)

{
  return param_1;
}


// ==== entry=00b22458 name=FUN_00b22458 size=23 ====

void FUN_00b22458(void)

{
  return;
}


// ==== entry=00b2246f name=FUN_00b2246f size=34 ====

undefined8 FUN_00b2246f(long *param_1,long *param_2)

{
  return CONCAT71((int7)((ulong)*param_2 >> 8),*param_1 == *param_2);
}


// ==== entry=00b22491 name=FUN_00b22491 size=38 ====

void FUN_00b22491(undefined8 param_1,undefined8 param_2)

{
  FUN_00b22890(param_1,param_2);
  return;
}


// ==== entry=00b224b8 name=FUN_00b224b8 size=122 ====

void FUN_00b224b8(long param_1)

{
  undefined8 uVar1;
  undefined8 uVar2;
  
  uVar1 = *(undefined8 *)(param_1 + 0x10);
  uVar2 = FUN_00b2244a(param_1);
  FUN_00b22491(uVar2,uVar1);
  FUN_00b228a0(param_1,*(undefined8 *)(param_1 + 0x18));
  FUN_00b12d20(param_1 + 0x10,*(long *)(param_1 + 0x28) + 8);
  *(undefined8 *)(param_1 + 0x10) = *(undefined8 *)(param_1 + 0x18);
  return;
}


// ==== entry=00b22532 name=FUN_00b22532 size=57 ====

void FUN_00b22532(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  undefined8 uVar1;
  
  uVar1 = FUN_00b22287(param_3);
  FUN_00b228d4(param_1,param_2,uVar1);
  return;
}


// ==== entry=00b2256c name=FUN_00b2256c size=154 ====

void FUN_00b2256c(long param_1,undefined8 param_2)

{
  long lVar1;
  undefined8 uVar2;
  
  FUN_00b22914(param_1,1);
  lVar1 = *(long *)(param_1 + 0x48);
  uVar2 = FUN_00b22974(param_1);
  *(undefined8 *)(lVar1 + 8) = uVar2;
  uVar2 = FUN_00b22287(param_2);
  FUN_00b22532(param_1,*(undefined8 *)(param_1 + 0x30),uVar2);
  FUN_00b12d20(param_1 + 0x30,*(long *)(param_1 + 0x48) + 8);
  *(undefined8 *)(param_1 + 0x30) = *(undefined8 *)(param_1 + 0x38);
  return;
}


// ==== entry=00b22606 name=FUN_00b22606 size=82 ====

void FUN_00b22606(undefined8 *param_1)

{
  std::allocator<char>::allocator();
  *param_1 = 0;
  param_1[1] = 0;
  FUN_00b2299e(param_1 + 2);
  FUN_00b2299e(param_1 + 6);
  return;
}


// ==== entry=00b22658 name=FUN_00b22658 size=335 ====

/* WARNING: Type propagation algorithm not settling */

void FUN_00b22658(long *param_1,ulong param_2)

{
  ulong uVar1;
  long *plVar2;
  long lVar3;
  long local_40 [3];
  long local_28;
  long local_20;
  
  uVar1 = FUN_00b0d748(1);
  local_20 = param_2 / uVar1 + 1;
  local_40[0] = param_2 / uVar1 + 3;
  local_40[1] = 8;
  plVar2 = (long *)FUN_00b06d34(local_40 + 1,local_40);
  param_1[1] = *plVar2;
  lVar3 = FUN_00b229d8(param_1,param_1[1]);
  *param_1 = lVar3;
  local_28 = ((ulong)(param_1[1] - local_20) >> 1) * 8 + *param_1;
  local_40[2] = local_28 + local_20 * 8;
                    /* try { // try from 00b22727 to 00b2272b has its CatchHandler @ 00b227a0 */
  FUN_00b22a46(param_1,local_28,local_40[2]);
  FUN_00b12d20(param_1 + 2,local_28);
  FUN_00b12d20(param_1 + 6,local_40[2] + -8);
  param_1[2] = param_1[3];
  lVar3 = param_1[7];
  uVar1 = FUN_00b0d748(1);
  param_1[6] = lVar3 + param_2 % uVar1;
  return;
}


// ==== entry=00b227fc name=FUN_00b227fc size=70 ====

void FUN_00b227fc(undefined8 param_1,undefined8 *param_2,undefined8 *param_3)

{
  undefined8 *local_10;
  
  for (local_10 = param_2; local_10 < param_3; local_10 = local_10 + 1) {
    FUN_00b228a0(param_1,*local_10);
  }
  return;
}


// ==== entry=00b22842 name=FUN_00b22842 size=77 ====

void FUN_00b22842(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  undefined1 local_9;
  
  FUN_00b22aca(&local_9,param_1);
  FUN_00b22b19(&local_9,param_2,param_3);
  FUN_00b22afe(&local_9);
  return;
}


// ==== entry=00b22890 name=FUN_00b22890 size=15 ====

void FUN_00b22890(void)

{
  return;
}


// ==== entry=00b228a0 name=FUN_00b228a0 size=51 ====

void FUN_00b228a0(undefined8 param_1,undefined8 param_2)

{
  undefined8 uVar1;
  
  uVar1 = FUN_00b0d748(1);
  FUN_00b22b47(param_1,param_2,uVar1);
  return;
}


// ==== entry=00b228d4 name=FUN_00b228d4 size=63 ====

void FUN_00b228d4(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  undefined1 uVar1;
  undefined1 *puVar2;
  
  puVar2 = (undefined1 *)FUN_00b22287(param_3);
  uVar1 = *puVar2;
  puVar2 = (undefined1 *)FUN_00b00efa(1,param_2);
  *puVar2 = uVar1;
  return;
}


// ==== entry=00b22914 name=FUN_00b22914 size=95 ====

void FUN_00b22914(long *param_1,long param_2)

{
  if ((ulong)(param_1[1] - (param_1[9] - *param_1 >> 3)) < param_2 + 1U) {
    FUN_00b22b76(param_1,param_2,0);
  }
  return;
}


// ==== entry=00b22974 name=FUN_00b22974 size=42 ====

void FUN_00b22974(undefined8 param_1)

{
  undefined8 uVar1;
  
  uVar1 = FUN_00b0d748(1);
  FUN_00b22d96(param_1,uVar1);
  return;
}


// ==== entry=00b2299e name=FUN_00b2299e size=58 ====

void FUN_00b2299e(undefined8 *param_1)

{
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  return;
}


// ==== entry=00b229d8 name=FUN_00b229d8 size=83 ====

undefined8 FUN_00b229d8(undefined8 param_1,undefined8 param_2)

{
  undefined8 uVar1;
  undefined1 local_19 [9];
  
  FUN_00b22aca(local_19,param_1);
                    /* try { // try from 00b22a0a to 00b22a0e has its CatchHandler @ 00b22a24 */
  uVar1 = FUN_00b22dc0(local_19,param_2);
  FUN_00b22afe(local_19);
  return uVar1;
}


// ==== entry=00b22a46 name=FUN_00b22a46 size=76 ====

void FUN_00b22a46(undefined8 param_1,undefined8 *param_2,undefined8 *param_3)

{
  undefined8 uVar1;
  undefined8 *local_20;
  
  for (local_20 = param_2; local_20 < param_3; local_20 = local_20 + 1) {
                    /* try { // try from 00b22a74 to 00b22a78 has its CatchHandler @ 00b22a8a */
    uVar1 = FUN_00b22974(param_1);
    *local_20 = uVar1;
  }
  return;
}


// ==== entry=00b22aca name=FUN_00b22aca size=52 ====

undefined8 FUN_00b22aca(undefined8 param_1,undefined8 param_2)

{
  undefined8 uVar1;
  
  uVar1 = FUN_00b22dea(param_2);
  FUN_00b22df8(param_1,uVar1);
  return param_1;
}


// ==== entry=00b22afe name=FUN_00b22afe size=27 ====

void FUN_00b22afe(undefined8 param_1)

{
  FUN_00b22e18(param_1);
  return;
}


// ==== entry=00b22b19 name=FUN_00b22b19 size=46 ====

void FUN_00b22b19(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  FUN_00b22e24(param_1,param_2,param_3);
  return;
}


// ==== entry=00b22b47 name=FUN_00b22b47 size=46 ====

void FUN_00b22b47(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  FUN_00b22e48(param_1,param_2,param_3);
  return;
}


// ==== entry=00b22b76 name=FUN_00b22b76 size=544 ====

void FUN_00b22b76(long *param_1,long param_2,char param_3)

{
  long *plVar1;
  long lVar2;
  long local_58;
  long *local_50;
  long local_40;
  long local_38;
  long local_30;
  long local_28;
  ulong local_20;
  
  local_28 = (param_1[9] - param_1[5] >> 3) + 1;
  local_30 = local_28 + param_2;
  local_58 = param_2;
  local_50 = param_1;
  if ((ulong)(local_30 * 2) < (ulong)param_1[1]) {
    if (param_3 == '\0') {
      param_2 = 0;
    }
    else {
      param_2 = param_2 << 3;
    }
    local_20 = param_2 + ((ulong)(param_1[1] - local_30) >> 1) * 8 + *param_1;
    if (local_20 < (ulong)param_1[5]) {
      FUN_00b22e6b(param_1[5],param_1[9] + 8,local_20);
    }
    else {
      FUN_00b22eb7(param_1[5],param_1[9] + 8,local_28 * 8 + local_20);
    }
  }
  else {
    lVar2 = param_1[1];
    plVar1 = (long *)FUN_00b06d34(param_1 + 1,&local_58);
    local_38 = *plVar1 + lVar2 + 2;
    local_40 = FUN_00b229d8(local_50,local_38);
    if (param_3 == '\0') {
      lVar2 = 0;
    }
    else {
      lVar2 = local_58 << 3;
    }
    local_20 = local_40 + ((ulong)(local_38 - local_30) >> 1) * 8 + lVar2;
    FUN_00b22e6b(local_50[5],local_50[9] + 8,local_20);
    FUN_00b22842(local_50,*local_50,local_50[1]);
    *local_50 = local_40;
    local_50[1] = local_38;
  }
  FUN_00b12d20(local_50 + 2,local_20);
  FUN_00b12d20(local_50 + 6,local_20 + local_28 * 8 + -8);
  return;
}


// ==== entry=00b22d96 name=FUN_00b22d96 size=42 ====

void FUN_00b22d96(undefined8 param_1,undefined8 param_2)

{
  FUN_00b22f04(param_1,param_2,0);
  return;
}


// ==== entry=00b22dc0 name=FUN_00b22dc0 size=42 ====

void FUN_00b22dc0(undefined8 param_1,undefined8 param_2)

{
  FUN_00b22f42(param_1,param_2,0);
  return;
}


// ==== entry=00b22dea name=FUN_00b22dea size=14 ====

undefined8 FUN_00b22dea(undefined8 param_1)

{
  return param_1;
}


// ==== entry=00b22df8 name=FUN_00b22df8 size=31 ====

void FUN_00b22df8(undefined8 param_1)

{
  FUN_00b22f84(param_1);
  return;
}


// ==== entry=00b22e18 name=FUN_00b22e18 size=11 ====

void FUN_00b22e18(void)

{
  return;
}


// ==== entry=00b22e24 name=FUN_00b22e24 size=35 ====

void FUN_00b22e24(undefined8 param_1,void *param_2)

{
  operator_delete(param_2);
  return;
}


// ==== entry=00b22e48 name=FUN_00b22e48 size=35 ====

void FUN_00b22e48(undefined8 param_1,void *param_2)

{
  operator_delete(param_2);
  return;
}


// ==== entry=00b22e6b name=FUN_00b22e6b size=76 ====

void FUN_00b22e6b(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  undefined8 uVar1;
  undefined8 uVar2;
  
  uVar1 = FUN_00b22f8f(param_2);
  uVar2 = FUN_00b22f8f(param_1);
  FUN_00b22f9d(uVar2,uVar1,param_3);
  return;
}


// ==== entry=00b22eb7 name=FUN_00b22eb7 size=76 ====

void FUN_00b22eb7(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  undefined8 uVar1;
  undefined8 uVar2;
  
  uVar1 = FUN_00b22f8f(param_2);
  uVar2 = FUN_00b22f8f(param_1);
  FUN_00b22ff5(uVar2,uVar1,param_3);
  return;
}


// ==== entry=00b22f04 name=FUN_00b22f04 size=62 ====

void FUN_00b22f04(undefined8 param_1,ulong param_2)

{
  ulong uVar1;
  
  uVar1 = FUN_00b2304e(param_1);
  if (uVar1 < param_2) {
                    /* WARNING: Subroutine does not return */
    std::__throw_bad_alloc();
  }
  operator_new(param_2);
  return;
}


// ==== entry=00b22f42 name=FUN_00b22f42 size=66 ====

void FUN_00b22f42(undefined8 param_1,ulong param_2)

{
  ulong uVar1;
  
  uVar1 = FUN_00b23060(param_1);
  if (uVar1 < param_2) {
                    /* WARNING: Subroutine does not return */
    std::__throw_bad_alloc();
  }
  operator_new(param_2 << 3);
  return;
}


// ==== entry=00b22f84 name=FUN_00b22f84 size=11 ====

void FUN_00b22f84(void)

{
  return;
}


// ==== entry=00b22f8f name=FUN_00b22f8f size=14 ====

undefined8 FUN_00b22f8f(undefined8 param_1)

{
  return param_1;
}


// ==== entry=00b22f9d name=FUN_00b22f9d size=88 ====

void FUN_00b22f9d(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  
  uVar1 = FUN_00b23074(param_3);
  uVar2 = FUN_00b23074(param_2);
  uVar3 = FUN_00b23074(param_1);
  FUN_00b23082(uVar3,uVar2,uVar1);
  return;
}


// ==== entry=00b22ff5 name=FUN_00b22ff5 size=88 ====

void FUN_00b22ff5(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  
  uVar1 = FUN_00b23074(param_3);
  uVar2 = FUN_00b23074(param_2);
  uVar3 = FUN_00b23074(param_1);
  FUN_00b230b3(uVar3,uVar2,uVar1);
  return;
}


// ==== entry=00b2304e name=FUN_00b2304e size=17 ====

undefined8 FUN_00b2304e(void)

{
  return 0xffffffffffffffff;
}


// ==== entry=00b23060 name=FUN_00b23060 size=20 ====

undefined8 FUN_00b23060(void)

{
  return 0x1fffffffffffffff;
}


// ==== entry=00b23074 name=FUN_00b23074 size=14 ====

undefined8 FUN_00b23074(undefined8 param_1)

{
  return param_1;
}


// ==== entry=00b23082 name=FUN_00b23082 size=49 ====

void FUN_00b23082(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  FUN_00b230e4(param_1,param_2,param_3);
  return;
}


// ==== entry=00b230b3 name=FUN_00b230b3 size=49 ====

void FUN_00b230b3(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  FUN_00b23143(param_1,param_2,param_3);
  return;
}


// ==== entry=00b230e4 name=FUN_00b230e4 size=95 ====

void * FUN_00b230e4(void *param_1,long param_2,void *param_3)

{
  long lVar1;
  
  lVar1 = param_2 - (long)param_1 >> 3;
  if (lVar1 != 0) {
    memmove(param_3,param_1,lVar1 * 8);
  }
  return (void *)((long)param_3 + lVar1 * 8);
}


// ==== entry=00b23143 name=FUN_00b23143 size=114 ====

long FUN_00b23143(void *param_1,long param_2,long param_3)

{
  long lVar1;
  
  lVar1 = param_2 - (long)param_1 >> 3;
  if (lVar1 != 0) {
    memmove((void *)(lVar1 * -8 + param_3),param_1,lVar1 * 8);
  }
  return param_3 + lVar1 * -8;
}


// ==== entry=00b231b6 name=FUN_00b231b6 size=288 ====

void FUN_00b231b6(undefined4 *param_1,long param_2)

{
  string *psVar1;
  
  *param_1 = *(undefined4 *)(param_2 + 0x38);
  std::string::string((string *)(param_1 + 2));
                    /* try { // try from 00b231f1 to 00b231f5 has its CatchHandler @ 00b232e4 */
  std::string::string((string *)(param_1 + 4));
  switch(*param_1) {
  case 0:
                    /* try { // try from 00b23227 to 00b232b0 has its CatchHandler @ 00b232cf */
    std::string::operator=((string *)(param_1 + 4),(string *)(param_2 + 0x18));
    break;
  case 1:
    std::string::operator=((string *)(param_1 + 4),(string *)(param_2 + 0x18));
    break;
  case 2:
    std::string::operator=((string *)(param_1 + 4),(string *)(param_2 + 0x18));
    break;
  case 3:
    std::string::operator=((string *)(param_1 + 2),(string *)(param_2 + 0x18));
    psVar1 = (string *)FUN_00b0a3c0(param_2 + 0x20,0);
    std::string::operator=((string *)(param_1 + 4),psVar1);
    break;
  case 4:
    break;
  default:
                    /* WARNING: Subroutine does not return */
    __assert_fail("false","/mnt/hgfs/Develop/Library/yaml-cpp-0.7.0/src/tag.cpp",0x1c,
                  "YAML::Tag::Tag(const YAML::Token&)");
  }
  return;
}


// ==== entry=00b2330a name=FUN_00b2330a size=562 ====

string * FUN_00b2330a(string *param_1,undefined4 *param_2,undefined8 param_3)

{
  string local_68 [8];
  string local_60 [15];
  allocator local_51;
  string local_50 [8];
  string local_48 [15];
  allocator local_39;
  string local_38 [8];
  string local_30 [8];
  string local_28 [15];
  allocator local_19 [9];
  
  switch(*param_2) {
  case 0:
    std::string::string(param_1,(string *)(param_2 + 4));
    break;
  case 1:
    std::allocator<char>::allocator();
                    /* try { // try from 00b2337a to 00b2337e has its CatchHandler @ 00b23553 */
    std::string::string(local_60,"!",&local_51);
                    /* try { // try from 00b23391 to 00b23395 has its CatchHandler @ 00b23542 */
    FUN_00b23d9a(local_68,param_3,local_60);
                    /* try { // try from 00b233a7 to 00b233ab has its CatchHandler @ 00b23531 */
    std::operator+(param_1,local_68);
    std::string::~string(local_68);
    std::string::~string(local_60);
    std::allocator<char>::~allocator((allocator<char> *)&local_51);
    break;
  case 2:
    std::allocator<char>::allocator();
                    /* try { // try from 00b233fa to 00b233fe has its CatchHandler @ 00b2358f */
    std::string::string(local_48,"!!",&local_39);
                    /* try { // try from 00b23411 to 00b23415 has its CatchHandler @ 00b2357e */
    FUN_00b23d9a(local_50,param_3,local_48);
                    /* try { // try from 00b23427 to 00b2342b has its CatchHandler @ 00b2356d */
    std::operator+(param_1,local_50);
    std::string::~string(local_50);
    std::string::~string(local_48);
    std::allocator<char>::~allocator((allocator<char> *)&local_39);
    break;
  case 3:
    std::operator+((char *)local_28,(string *)&DAT_00d3e0f0);
                    /* try { // try from 00b2348a to 00b2348e has its CatchHandler @ 00b235cb */
    FUN_007c4f98(local_30,local_28,&DAT_00d3e0f0);
                    /* try { // try from 00b234a1 to 00b234a5 has its CatchHandler @ 00b235ba */
    FUN_00b23d9a(local_38,param_3,local_30);
                    /* try { // try from 00b234b7 to 00b234bb has its CatchHandler @ 00b235a9 */
    std::operator+(param_1,local_38);
    std::string::~string(local_38);
    std::string::~string(local_30);
    std::string::~string(local_28);
    break;
  case 4:
    std::allocator<char>::allocator();
                    /* try { // try from 00b23502 to 00b23506 has its CatchHandler @ 00b235e5 */
    std::string::string(param_1,"!",local_19);
    std::allocator<char>::~allocator((allocator<char> *)local_19);
    break;
  default:
                    /* WARNING: Subroutine does not return */
    __assert_fail("false","/mnt/hgfs/Develop/Library/yaml-cpp-0.7.0/src/tag.cpp",0x2e,
                  "const string YAML::Tag::Translate(const YAML::Directives&)");
  }
  return param_1;
}


// ==== entry=00b2360a name=FUN_00b2360a size=48 ====

void FUN_00b2360a(void)

{
  string *this;
  
  this = (string *)&DAT_011c35c0;
  while (this != (string *)&DAT_011c3520) {
    this = this + -8;
    std::string::~string(this);
  }
  return;
}


// ==== entry=00b2363a name=FUN_00b2363a size=1151 ====

void FUN_00b2363a(int param_1,int param_2)

{
  allocator local_3c;
  allocator local_3b;
  allocator local_3a;
  allocator local_39;
  allocator local_38;
  allocator local_37;
  allocator local_36;
  allocator local_35;
  allocator local_34;
  allocator local_33;
  allocator local_32;
  allocator local_31;
  allocator local_30;
  allocator local_2f;
  allocator local_2e;
  allocator local_2d;
  allocator local_2c;
  allocator local_2b;
  allocator local_2a;
  allocator local_29 [9];
  
  if ((param_1 == 1) && (param_2 == 0xffff)) {
    std::ios_base::Init::Init((Init *)&DAT_011c3500);
    __cxa_atexit(std::ios_base::Init::~Init,&DAT_011c3500,&DAT_00c89008);
    std::allocator<char>::allocator();
                    /* try { // try from 00b236a8 to 00b236ac has its CatchHandler @ 00b23aae */
    std::string::string((string *)&DAT_011c3520,"DIRECTIVE",&local_3c);
    std::allocator<char>::~allocator((allocator<char> *)&local_3c);
    std::allocator<char>::allocator();
                    /* try { // try from 00b236dc to 00b236e0 has its CatchHandler @ 00b23ac2 */
    std::string::string((string *)&DAT_011c3528,"DOC_START",&local_3b);
    std::allocator<char>::~allocator((allocator<char> *)&local_3b);
    std::allocator<char>::allocator();
                    /* try { // try from 00b23710 to 00b23714 has its CatchHandler @ 00b23ad6 */
    std::string::string((string *)&DAT_011c3530,"DOC_END",&local_3a);
    std::allocator<char>::~allocator((allocator<char> *)&local_3a);
    std::allocator<char>::allocator();
                    /* try { // try from 00b23744 to 00b23748 has its CatchHandler @ 00b23aea */
    std::string::string((string *)&DAT_011c3538,"BLOCK_SEQ_START",&local_39);
    std::allocator<char>::~allocator((allocator<char> *)&local_39);
    std::allocator<char>::allocator();
                    /* try { // try from 00b23778 to 00b2377c has its CatchHandler @ 00b23afe */
    std::string::string((string *)&DAT_011c3540,"BLOCK_MAP_START",&local_38);
    std::allocator<char>::~allocator((allocator<char> *)&local_38);
    std::allocator<char>::allocator();
                    /* try { // try from 00b237ac to 00b237b0 has its CatchHandler @ 00b23b12 */
    std::string::string((string *)&DAT_011c3548,"BLOCK_SEQ_END",&local_37);
    std::allocator<char>::~allocator((allocator<char> *)&local_37);
    std::allocator<char>::allocator();
                    /* try { // try from 00b237e0 to 00b237e4 has its CatchHandler @ 00b23b26 */
    std::string::string((string *)&DAT_011c3550,"BLOCK_MAP_END",&local_36);
    std::allocator<char>::~allocator((allocator<char> *)&local_36);
    std::allocator<char>::allocator();
                    /* try { // try from 00b23814 to 00b23818 has its CatchHandler @ 00b23b3a */
    std::string::string((string *)&DAT_011c3558,"BLOCK_ENTRY",&local_35);
    std::allocator<char>::~allocator((allocator<char> *)&local_35);
    std::allocator<char>::allocator();
                    /* try { // try from 00b23848 to 00b2384c has its CatchHandler @ 00b23b4e */
    std::string::string((string *)&DAT_011c3560,"FLOW_SEQ_START",&local_34);
    std::allocator<char>::~allocator((allocator<char> *)&local_34);
    std::allocator<char>::allocator();
                    /* try { // try from 00b2387c to 00b23880 has its CatchHandler @ 00b23b62 */
    std::string::string((string *)&DAT_011c3568,"FLOW_MAP_START",&local_33);
    std::allocator<char>::~allocator((allocator<char> *)&local_33);
    std::allocator<char>::allocator();
                    /* try { // try from 00b238b0 to 00b238b4 has its CatchHandler @ 00b23b76 */
    std::string::string((string *)&DAT_011c3570,"FLOW_SEQ_END",&local_32);
    std::allocator<char>::~allocator((allocator<char> *)&local_32);
    std::allocator<char>::allocator();
                    /* try { // try from 00b238e4 to 00b238e8 has its CatchHandler @ 00b23b8a */
    std::string::string((string *)&DAT_011c3578,"FLOW_MAP_END",&local_31);
    std::allocator<char>::~allocator((allocator<char> *)&local_31);
    std::allocator<char>::allocator();
                    /* try { // try from 00b23918 to 00b2391c has its CatchHandler @ 00b23b9e */
    std::string::string((string *)&DAT_011c3580,"FLOW_MAP_COMPACT",&local_30);
    std::allocator<char>::~allocator((allocator<char> *)&local_30);
    std::allocator<char>::allocator();
                    /* try { // try from 00b2394c to 00b23950 has its CatchHandler @ 00b23baf */
    std::string::string((string *)&DAT_011c3588,"FLOW_ENTRY",&local_2f);
    std::allocator<char>::~allocator((allocator<char> *)&local_2f);
    std::allocator<char>::allocator();
                    /* try { // try from 00b23980 to 00b23984 has its CatchHandler @ 00b23bc0 */
    std::string::string((string *)&DAT_011c3590,"KEY",&local_2e);
    std::allocator<char>::~allocator((allocator<char> *)&local_2e);
    std::allocator<char>::allocator();
                    /* try { // try from 00b239b4 to 00b239b8 has its CatchHandler @ 00b23bd1 */
    std::string::string((string *)&DAT_011c3598,"VALUE",&local_2d);
    std::allocator<char>::~allocator((allocator<char> *)&local_2d);
    std::allocator<char>::allocator();
                    /* try { // try from 00b239e8 to 00b239ec has its CatchHandler @ 00b23be2 */
    std::string::string((string *)&DAT_011c35a0,"ANCHOR",&local_2c);
    std::allocator<char>::~allocator((allocator<char> *)&local_2c);
    std::allocator<char>::allocator();
                    /* try { // try from 00b23a1c to 00b23a20 has its CatchHandler @ 00b23bf3 */
    std::string::string((string *)&DAT_011c35a8,"ALIAS",&local_2b);
    std::allocator<char>::~allocator((allocator<char> *)&local_2b);
    std::allocator<char>::allocator();
                    /* try { // try from 00b23a50 to 00b23a54 has its CatchHandler @ 00b23c04 */
    std::string::string((string *)&DAT_011c35b0,"TAG",&local_2a);
    std::allocator<char>::~allocator((allocator<char> *)&local_2a);
    std::allocator<char>::allocator();
                    /* try { // try from 00b23a84 to 00b23a88 has its CatchHandler @ 00b23c15 */
    std::string::string((string *)&DAT_011c35b8,"SCALAR",local_29);
    std::allocator<char>::~allocator((allocator<char> *)local_29);
    __cxa_atexit(FUN_00b2360a,0,&DAT_00c89008);
  }
  return;
}


// ==== entry=00b23c63 orig=FUN_00b23c63 size=21 name=_INIT_176 ====

void _INIT_176(void)

{
  FUN_00b2363a(1,0xffff);
  return;
}


// ==== entry=00b23c78 orig=FUN_00b23c78 size=72 name=operator+ ====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* std::string std::TEMPNAMEPLACEHOLDERVALUE(std::string const&, std::string const&) */

string * std::operator+(string *param_1,string *param_2)

{
  string *in_RDX;
  
  string::string(param_1,param_2);
                    /* try { // try from 00b23cae to 00b23cb2 has its CatchHandler @ 00b23cb5 */
  string::append(param_1,in_RDX);
  return param_1;
}


// ==== entry=00b23cda name=FUN_00b23cda size=71 ====

void FUN_00b23cda(undefined8 *param_1,undefined4 param_2,undefined8 param_3,undefined8 param_4)

{
  FUN_00b09fc4(param_1,param_3,param_4);
  *param_1 = &PTR_FUN_00d3df80;
  *(undefined4 *)(param_1 + 5) = param_2;
  return;
}


// ==== entry=00b23d22 name=FUN_00b23d22 size=119 ====

void FUN_00b23d22(undefined1 *param_1)

{
  *param_1 = 1;
  *(undefined4 *)(param_1 + 4) = 1;
  *(undefined4 *)(param_1 + 8) = 2;
  *(undefined4 *)(param_1 + 0x18) = 0;
  *(undefined8 *)(param_1 + 0x20) = 0;
  *(undefined8 *)(param_1 + 0x28) = 0;
  *(undefined8 *)(param_1 + 0x30) = 0;
  *(undefined8 *)(param_1 + 0x38) = 0;
  FUN_00b23eb0(param_1 + 0x10);
  return;
}


// ==== entry=00b23d9a name=FUN_00b23d9a size=224 ====

string * FUN_00b23d9a(string *param_1,long param_2,string *param_3)

{
  char cVar1;
  long lVar2;
  undefined8 local_30;
  undefined8 local_28;
  allocator local_19 [9];
  
  local_30 = FUN_00b23f04(param_2 + 0x10,param_3);
  local_28 = FUN_00b23f2a(param_2 + 0x10);
  cVar1 = FUN_00b23f44(&local_30,&local_28);
  if (cVar1 == '\0') {
    lVar2 = FUN_00b23f66(&local_30);
    std::string::string(param_1,(string *)(lVar2 + 8));
  }
  else {
    cVar1 = FUN_00b0a358(param_3,&DAT_00d3eb51);
    if (cVar1 == '\0') {
      std::string::string(param_1,param_3);
    }
    else {
      std::allocator<char>::allocator();
                    /* try { // try from 00b23e26 to 00b23e2a has its CatchHandler @ 00b23e6f */
      std::string::string(param_1,"tag:yaml.org,2002:",local_19);
      std::allocator<char>::~allocator((allocator<char> *)local_19);
    }
  }
  return param_1;
}


// ==== entry=00b23e94 name=FUN_00b23e94 size=27 ====

void FUN_00b23e94(undefined8 param_1)

{
  FUN_00b23ecc(param_1);
  return;
}


// ==== entry=00b23eb0 name=FUN_00b23eb0 size=27 ====

void FUN_00b23eb0(undefined8 param_1)

{
  FUN_00b23e94(param_1);
  return;
}


// ==== entry=00b23ecc name=FUN_00b23ecc size=55 ====

void FUN_00b23ecc(long param_1)

{
  FUN_00b23f84(param_1);
  FUN_00b1edde(param_1);
  FUN_00b00f0c(param_1 + 8);
  return;
}


// ==== entry=00b23f04 name=FUN_00b23f04 size=37 ====

void FUN_00b23f04(undefined8 param_1,undefined8 param_2)

{
  FUN_00b23fa0(param_1,param_2);
  return;
}


// ==== entry=00b23f2a name=FUN_00b23f2a size=26 ====

void FUN_00b23f2a(undefined8 param_1)

{
  FUN_00b24050(param_1);
  return;
}


// ==== entry=00b23f44 name=FUN_00b23f44 size=34 ====

undefined8 FUN_00b23f44(long *param_1,long *param_2)

{
  return CONCAT71((int7)((ulong)*param_2 >> 8),*param_1 == *param_2);
}


// ==== entry=00b23f66 name=FUN_00b23f66 size=29 ====

void FUN_00b23f66(undefined8 *param_1)

{
  FUN_00b0ba4a(*param_1);
  return;
}


// ==== entry=00b23f84 name=FUN_00b23f84 size=27 ====

void FUN_00b23f84(undefined8 param_1)

{
  FUN_00b2407a(param_1);
  return;
}


// ==== entry=00b23fa0 name=FUN_00b23fa0 size=175 ====

undefined8 FUN_00b23fa0(undefined8 param_1,undefined8 param_2)

{
  char cVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 local_28;
  undefined8 local_20 [2];
  
  uVar2 = FUN_00b24098(param_1);
  uVar3 = FUN_00b24086(param_1);
  local_28 = FUN_00b240aa(param_1,uVar3,uVar2,param_2);
  local_20[0] = FUN_00b24050(param_1);
  cVar1 = FUN_00b23f44(&local_28,local_20);
  if (cVar1 == '\0') {
    uVar2 = FUN_00b0ad1c(local_28);
    cVar1 = FUN_00b0a97a(param_1,param_2,uVar2);
    if (cVar1 == '\0') {
      return local_28;
    }
  }
  uVar2 = FUN_00b24050(param_1);
  return uVar2;
}


// ==== entry=00b24050 name=FUN_00b24050 size=41 ====

undefined8 FUN_00b24050(long param_1)

{
  undefined8 local_10;
  
  FUN_00b24140(&local_10,param_1 + 8);
  return local_10;
}


// ==== entry=00b2407a name=FUN_00b2407a size=11 ====

void FUN_00b2407a(void)

{
  return;
}


// ==== entry=00b24086 name=FUN_00b24086 size=18 ====

undefined8 FUN_00b24086(long param_1)

{
  return *(undefined8 *)(param_1 + 0x10);
}


// ==== entry=00b24098 name=FUN_00b24098 size=18 ====

long FUN_00b24098(long param_1)

{
  return param_1 + 8;
}


// ==== entry=00b240aa name=FUN_00b240aa size=150 ====

undefined8 FUN_00b240aa(undefined8 param_1,long param_2,long param_3,undefined8 param_4)

{
  char cVar1;
  undefined8 uVar2;
  long local_40;
  long local_38;
  undefined8 local_20 [2];
  
  local_40 = param_3;
  local_38 = param_2;
  while (local_38 != 0) {
    uVar2 = FUN_00b0b2ce(local_38);
    cVar1 = FUN_00b0a97a(param_1,uVar2,param_4);
    if (cVar1 == '\x01') {
      local_38 = FUN_00b2416c(local_38);
    }
    else {
      local_40 = local_38;
      local_38 = FUN_00b2415a(local_38);
    }
  }
  FUN_00b24140(local_20,local_40);
  return local_20[0];
}


// ==== entry=00b24140 name=FUN_00b24140 size=26 ====

void FUN_00b24140(undefined8 *param_1,undefined8 param_2)

{
  *param_1 = param_2;
  return;
}


// ==== entry=00b2415a name=FUN_00b2415a size=18 ====

undefined8 FUN_00b2415a(long param_1)

{
  return *(undefined8 *)(param_1 + 0x10);
}


// ==== entry=00b2416c name=FUN_00b2416c size=18 ====

undefined8 FUN_00b2416c(long param_1)

{
  return *(undefined8 *)(param_1 + 0x18);
}


// ==== entry=00b2417e name=FUN_00b2417e size=22 ====

bool FUN_00b2417e(void)

{
  return PTR___pthread_key_create_011bec40 != (undefined *)0x0;
}


// ==== entry=00b24194 name=FUN_00b24194 size=193 ====

void FUN_00b24194(undefined8 *param_1)

{
  void *pvVar1;
  undefined8 local_20;
  
  FUN_00b24fee(param_1);
  *param_1 = &PTR_FUN_00d3f5a0;
                    /* try { // try from 00b241c8 to 00b241cc has its CatchHandler @ 00b242a1 */
  pvVar1 = operator_new(0x10);
                    /* try { // try from 00b241d3 to 00b241d7 has its CatchHandler @ 00b2424c */
  FUN_00b24f5e(pvVar1);
                    /* try { // try from 00b241de to 00b241e2 has its CatchHandler @ 00b242a1 */
  FUN_00b25156(param_1 + 1,pvVar1);
  param_1[3] = 0;
  FUN_00b04cfe(param_1 + 4);
  FUN_00b04cfe(param_1 + 7);
  FUN_00b2517c(param_1 + 10);
  param_1[0xd] = 0;
  local_20 = 0;
                    /* try { // try from 00b24245 to 00b24249 has its CatchHandler @ 00b2425c */
  FUN_00b05268(param_1 + 7,&local_20);
  return;
}


// ==== entry=00b242c4 name=FUN_00b242c4 size=103 ====

void FUN_00b242c4(undefined8 *param_1)

{
  *param_1 = &PTR_FUN_00d3f5a0;
  FUN_00b25198(param_1 + 10);
  FUN_00b029e0(param_1 + 7);
  FUN_00b029e0(param_1 + 4);
  FUN_00b07fae(param_1 + 1);
  FUN_00b25006(param_1);
  return;
}


// ==== entry=00b2432c name=FUN_00b2432c size=38 ====

void FUN_00b2432c(void *param_1)

{
  FUN_00b242c4(param_1);
  operator_delete(param_1);
  return;
}


// ==== entry=00b24352 name=FUN_00b24352 size=119 ====

undefined8 FUN_00b24352(undefined8 param_1,long param_2)

{
  undefined1 local_28 [24];
  
  if (*(long *)(param_2 + 0x18) == 0) {
    FUN_00b07fca(param_1);
  }
  else {
    FUN_00b07f88(local_28,param_2 + 8);
                    /* try { // try from 00b243ab to 00b243af has its CatchHandler @ 00b243be */
    FUN_00b24f9c(param_1,*(undefined8 *)(param_2 + 0x18),local_28);
    FUN_00b07fae(local_28);
  }
  return param_1;
}


// ==== entry=00b243e4 name=FUN_00b243e4 size=15 ====

void FUN_00b243e4(void)

{
  return;
}


// ==== entry=00b243f4 name=FUN_00b243f4 size=11 ====

void FUN_00b243f4(void)

{
  return;
}


// ==== entry=00b24400 name=FUN_00b24400 size=74 ====

void FUN_00b24400(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  undefined8 uVar1;
  
  uVar1 = FUN_00b24670(param_1,param_2,param_3);
  FUN_00b24c58(uVar1);
  FUN_00b247aa(param_1);
  return;
}


// ==== entry=00b2444a name=FUN_00b2444a size=84 ====

void FUN_00b2444a(long param_1,undefined8 param_2,undefined8 param_3)

{
  undefined8 *puVar1;
  
  puVar1 = (undefined8 *)FUN_00b0564c(param_1 + 0x38,param_3);
  FUN_00b246e4(param_1,*puVar1);
  FUN_00b247aa(param_1);
  return;
}


// ==== entry=00b2449e name=FUN_00b2449e size=108 ====

void FUN_00b2449e(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                 undefined8 param_5)

{
  undefined8 uVar1;
  
  uVar1 = FUN_00b24670(param_1,param_2,param_4);
  FUN_00b04b86(uVar1,param_5);
  FUN_00b24c88(uVar1,param_3);
  FUN_00b247aa(param_1);
  return;
}


// ==== entry=00b2450a name=FUN_00b2450a size=111 ====

void FUN_00b2450a(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                 undefined4 param_5)

{
  undefined8 uVar1;
  
  uVar1 = FUN_00b24670(param_1,param_2,param_4);
  FUN_00b24c88(uVar1,param_3);
  FUN_00b24c18(uVar1,3);
  FUN_00b24cc6(uVar1,param_5);
  return;
}


// ==== entry=00b2457a name=FUN_00b2457a size=27 ====

void FUN_00b2457a(undefined8 param_1)

{
  FUN_00b247aa(param_1);
  return;
}


// ==== entry=00b24596 name=FUN_00b24596 size=131 ====

void FUN_00b24596(long param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                 undefined4 param_5)

{
  undefined8 uVar1;
  
  uVar1 = FUN_00b24670(param_1,param_2,param_4);
  FUN_00b24c18(uVar1,4);
  FUN_00b24c88(uVar1,param_3);
  FUN_00b24cc6(uVar1,param_5);
  *(long *)(param_1 + 0x68) = *(long *)(param_1 + 0x68) + 1;
  return;
}


// ==== entry=00b2461a name=FUN_00b2461a size=85 ====

void FUN_00b2461a(long param_1)

{
  if (*(long *)(param_1 + 0x68) == 0) {
                    /* WARNING: Subroutine does not return */
    __assert_fail("m_mapDepth > 0","/mnt/hgfs/Develop/Library/yaml-cpp-0.7.0/src/nodebuilder.cpp",
                  0x4b,"virtual void YAML::NodeBuilder::OnMapEnd()");
  }
  *(long *)(param_1 + 0x68) = *(long *)(param_1 + 0x68) + -1;
  FUN_00b247aa(param_1);
  return;
}


// ==== entry=00b24670 name=FUN_00b24670 size=115 ====

undefined8 FUN_00b24670(long param_1,undefined8 param_2,undefined8 param_3)

{
  undefined8 uVar1;
  
  uVar1 = FUN_00b053f6(param_1 + 8);
  uVar1 = FUN_00b04a50(uVar1);
  FUN_00b24be6(uVar1,param_2);
  FUN_00b249e2(param_1,param_3,uVar1);
  FUN_00b246e4(param_1,uVar1);
  return uVar1;
}


// ==== entry=00b246e4 name=FUN_00b246e4 size=197 ====

void FUN_00b246e4(long param_1,undefined8 param_2)

{
  char cVar1;
  int iVar2;
  undefined8 *puVar3;
  ulong uVar4;
  undefined8 local_28;
  undefined1 local_19;
  undefined8 local_18;
  char local_9;
  
  cVar1 = FUN_00b251dc(param_1 + 0x20);
  if (cVar1 != '\x01') {
    puVar3 = (undefined8 *)FUN_00b2521e(param_1 + 0x20);
    iVar2 = FUN_00b00660(*puVar3);
    if (iVar2 == 4) {
      uVar4 = FUN_00b2525e(param_1 + 0x50);
      if (uVar4 < *(ulong *)(param_1 + 0x68)) {
        local_9 = '\x01';
        goto LAB_00b24757;
      }
    }
  }
  local_9 = '\0';
LAB_00b24757:
  local_28 = param_2;
  FUN_00b05268(param_1 + 0x20,&local_28);
  if (local_9 != '\0') {
    local_19 = 0;
    local_18 = param_2;
    FUN_00b25282(param_1 + 0x50,&local_18,&local_19);
  }
  return;
}


// ==== entry=00b247aa name=FUN_00b247aa size=516 ====

void FUN_00b247aa(long param_1)

{
  char cVar1;
  int iVar2;
  long lVar3;
  undefined8 *puVar4;
  undefined1 local_58 [16];
  undefined1 local_48 [24];
  undefined8 *local_30;
  undefined8 local_28;
  undefined8 local_20;
  
  cVar1 = FUN_00b251dc(param_1 + 0x20);
  if (cVar1 == '\x01') {
                    /* WARNING: Subroutine does not return */
    __assert_fail("!m_stack.empty()","/mnt/hgfs/Develop/Library/yaml-cpp-0.7.0/src/nodebuilder.cpp",
                  99,"void YAML::NodeBuilder::Pop()");
  }
  lVar3 = FUN_00b04d9c(param_1 + 0x20);
  if (lVar3 == 1) {
    puVar4 = (undefined8 *)FUN_00b0564c(param_1 + 0x20,0);
    *(undefined8 *)(param_1 + 0x18) = *puVar4;
    FUN_00b25342(param_1 + 0x20);
  }
  else {
    puVar4 = (undefined8 *)FUN_00b2521e(param_1 + 0x20);
    local_20 = *puVar4;
    FUN_00b25342(param_1 + 0x20);
    puVar4 = (undefined8 *)FUN_00b2521e(param_1 + 0x20);
    local_28 = *puVar4;
    iVar2 = FUN_00b00660(local_28);
    if (iVar2 == 3) {
      FUN_00b07f88(local_58,param_1 + 8);
                    /* try { // try from 00b248b4 to 00b248b8 has its CatchHandler @ 00b249a7 */
      FUN_00b24d00(local_28,local_20,local_58);
      FUN_00b07fae(local_58);
    }
    else {
      iVar2 = FUN_00b00660(local_28);
      if (iVar2 != 4) {
                    /* WARNING: Subroutine does not return */
        __assert_fail("false","/mnt/hgfs/Develop/Library/yaml-cpp-0.7.0/src/nodebuilder.cpp",0x7b,
                      "void YAML::NodeBuilder::Pop()");
      }
      cVar1 = FUN_00b2537c(param_1 + 0x50);
      if (cVar1 == '\x01') {
                    /* WARNING: Subroutine does not return */
        __assert_fail("!m_keys.empty()",
                      "/mnt/hgfs/Develop/Library/yaml-cpp-0.7.0/src/nodebuilder.cpp",0x72,
                      "void YAML::NodeBuilder::Pop()");
      }
      local_30 = (undefined8 *)FUN_00b253be(param_1 + 0x50);
      if (*(char *)(local_30 + 1) == '\0') {
        *(undefined1 *)(local_30 + 1) = 1;
      }
      else {
        FUN_00b07f88(local_48,param_1 + 8);
                    /* try { // try from 00b24961 to 00b24965 has its CatchHandler @ 00b249c1 */
        FUN_00b24db4(local_28,*local_30,local_20,local_48);
        FUN_00b07fae(local_48);
        FUN_00b253fe(param_1 + 0x50);
      }
    }
  }
  return;
}


// ==== entry=00b249e2 name=FUN_00b249e2 size=108 ====

void FUN_00b249e2(long param_1,long param_2,undefined8 param_3)

{
  long lVar1;
  undefined8 local_10;
  
  if (param_2 != 0) {
    lVar1 = FUN_00b04d9c(param_1 + 0x38);
    if (param_2 != lVar1) {
                    /* WARNING: Subroutine does not return */
      __assert_fail("anchor == m_anchors.size()",
                    "/mnt/hgfs/Develop/Library/yaml-cpp-0.7.0/src/nodebuilder.cpp",0x82,
                    "void YAML::NodeBuilder::RegisterAnchor(YAML::anchor_t, YAML::detail::node&)");
    }
    local_10 = param_3;
    FUN_00b05268(param_1 + 0x38,&local_10);
  }
  return;
}


// ==== entry=00b24a4e name=FUN_00b24a4e size=19 ====

void FUN_00b24a4e(void)

{
  return;
}


// ==== entry=00b24a62 name=FUN_00b24a62 size=49 ====

void FUN_00b24a62(undefined8 param_1,undefined8 param_2)

{
  undefined8 uVar1;
  
  uVar1 = FUN_00b00738(param_1);
  FUN_00b03854(uVar1,param_2);
  return;
}


// ==== entry=00b24a94 name=FUN_00b24a94 size=46 ====

void FUN_00b24a94(undefined8 param_1,undefined4 param_2)

{
  undefined8 uVar1;
  
  uVar1 = FUN_00b00738(param_1);
  FUN_00b03878(uVar1,param_2);
  return;
}


// ==== entry=00b24ac2 name=FUN_00b24ac2 size=49 ====

void FUN_00b24ac2(undefined8 param_1,undefined8 param_2)

{
  undefined8 uVar1;
  
  uVar1 = FUN_00b00738(param_1);
  FUN_00b03926(uVar1,param_2);
  return;
}


// ==== entry=00b24af4 name=FUN_00b24af4 size=35 ====

void FUN_00b24af4(undefined8 param_1)

{
  undefined8 uVar1;
  
  uVar1 = FUN_00b00738(param_1);
  FUN_00b03968(uVar1);
  return;
}


// ==== entry=00b24b18 name=FUN_00b24b18 size=46 ====

void FUN_00b24b18(undefined8 param_1,undefined4 param_2)

{
  undefined8 uVar1;
  
  uVar1 = FUN_00b00738(param_1);
  FUN_00b03950(uVar1,param_2);
  return;
}


// ==== entry=00b24b46 name=FUN_00b24b46 size=57 ====

void FUN_00b24b46(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  undefined8 uVar1;
  
  uVar1 = FUN_00b00738(param_1);
  FUN_00b03e96(uVar1,param_2,param_3);
  return;
}


// ==== entry=00b24b80 name=FUN_00b24b80 size=62 ====

void FUN_00b24b80(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 uVar1;
  
  uVar1 = FUN_00b00738(param_1);
  FUN_00b03f4e(uVar1,param_2,param_3,param_4);
  return;
}


// ==== entry=00b24bbe name=FUN_00b24bbe size=40 ====

undefined8 FUN_00b24bbe(undefined8 param_1,long param_2,long param_3)

{
  return CONCAT71((int7)(*(ulong *)(param_3 + 0x40) >> 8),
                  *(ulong *)(param_2 + 0x40) < *(ulong *)(param_3 + 0x40));
}


// ==== entry=00b24be6 name=FUN_00b24be6 size=49 ====

void FUN_00b24be6(undefined8 param_1,undefined8 param_2)

{
  undefined8 uVar1;
  
  uVar1 = FUN_00b00764(param_1);
  FUN_00b24a62(uVar1,param_2);
  return;
}


// ==== entry=00b24c18 name=FUN_00b24c18 size=64 ====

void FUN_00b24c18(undefined8 param_1,int param_2)

{
  undefined8 uVar1;
  
  if (param_2 != 0) {
    FUN_005289b6(param_1);
  }
  uVar1 = FUN_00b00764(param_1);
  FUN_00b24a94(uVar1,param_2);
  return;
}


// ==== entry=00b24c58 name=FUN_00b24c58 size=47 ====

void FUN_00b24c58(undefined8 param_1)

{
  undefined8 uVar1;
  
  FUN_005289b6(param_1);
  uVar1 = FUN_00b00764(param_1);
  FUN_00b24af4(uVar1);
  return;
}


// ==== entry=00b24c88 name=FUN_00b24c88 size=61 ====

void FUN_00b24c88(undefined8 param_1,undefined8 param_2)

{
  undefined8 uVar1;
  
  FUN_005289b6(param_1);
  uVar1 = FUN_00b00764(param_1);
  FUN_00b24ac2(uVar1,param_2);
  return;
}


// ==== entry=00b24cc6 name=FUN_00b24cc6 size=58 ====

void FUN_00b24cc6(undefined8 param_1,undefined4 param_2)

{
  undefined8 uVar1;
  
  FUN_005289b6(param_1);
  uVar1 = FUN_00b00764(param_1);
  FUN_00b24b18(uVar1,param_2);
  return;
}


// ==== entry=00b24d00 name=FUN_00b24d00 size=154 ====

void FUN_00b24d00(long param_1,undefined8 param_2,undefined8 param_3)

{
  long lVar1;
  undefined8 uVar2;
  undefined1 local_38 [40];
  
  uVar2 = FUN_00b00764(param_1);
  FUN_00b07f88(local_38,param_3);
                    /* try { // try from 00b24d45 to 00b24d49 has its CatchHandler @ 00b24d93 */
  FUN_00b24b46(uVar2,param_2,local_38);
  FUN_00b07fae(local_38);
  FUN_0078370c(param_2,param_1);
  LOCK();
  UNLOCK();
  lVar1 = DAT_011c2a88 + 1;
  *(long *)(param_1 + 0x40) = DAT_011c2a88;
  DAT_011c2a88 = lVar1;
  return;
}


// ==== entry=00b24db4 name=FUN_00b24db4 size=141 ====

void FUN_00b24db4(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 uVar1;
  undefined1 local_28 [24];
  
  uVar1 = FUN_00b00764(param_1);
  FUN_00b07f88(local_28,param_4);
                    /* try { // try from 00b24e01 to 00b24e05 has its CatchHandler @ 00b24e3a */
  FUN_00b24b80(uVar1,param_2,param_3,local_28);
  FUN_00b07fae(local_28);
  FUN_0078370c(param_2,param_1);
  FUN_0078370c(param_3,param_1);
  return;
}


// ==== entry=00b24e5c name=FUN_00b24e5c size=27 ====

void FUN_00b24e5c(undefined8 param_1)

{
  FUN_00b250da(param_1);
  return;
}


// ==== entry=00b24e78 name=FUN_00b24e78 size=27 ====

void FUN_00b24e78(undefined8 param_1)

{
  FUN_00b250a2(param_1);
  return;
}


// ==== entry=00b24e94 name=FUN_00b24e94 size=27 ====

void FUN_00b24e94(undefined8 param_1)

{
  FUN_00b24e78(param_1);
  return;
}


// ==== entry=00b24eb0 name=FUN_00b24eb0 size=27 ====

void FUN_00b24eb0(undefined8 param_1)

{
  FUN_00b250f6(param_1);
  return;
}


// ==== entry=00b24ecc name=FUN_00b24ecc size=86 ====

void FUN_00b24ecc(long param_1)

{
  *(undefined4 *)(param_1 + 8) = 0;
  *(undefined8 *)(param_1 + 0x10) = 0;
  *(undefined8 *)(param_1 + 0x18) = 0;
  *(undefined8 *)(param_1 + 0x20) = 0;
  *(undefined8 *)(param_1 + 0x28) = 0;
  FUN_00b24e94(param_1);
  return;
}


// ==== entry=00b24f22 name=FUN_00b24f22 size=31 ====

void FUN_00b24f22(long param_1)

{
  FUN_00b01276(param_1 + 8);
  return;
}


// ==== entry=00b24f42 name=FUN_00b24f42 size=27 ====

void FUN_00b24f42(undefined8 param_1)

{
  FUN_00b24f22(param_1);
  return;
}


// ==== entry=00b24f5e name=FUN_00b24f5e size=61 ====

void FUN_00b24f5e(undefined8 param_1)

{
  void *pvVar1;
  
  pvVar1 = operator_new(0x30);
  FUN_00b24ecc(pvVar1);
  FUN_00b25130(param_1,pvVar1);
  return;
}


// ==== entry=00b24f9c name=FUN_00b24f9c size=81 ====

void FUN_00b24f9c(undefined1 *param_1,undefined8 param_2,undefined8 param_3)

{
  *param_1 = 1;
  std::string::string((string *)(param_1 + 8));
  FUN_00b07f88(param_1 + 0x10,param_3);
  *(undefined8 *)(param_1 + 0x20) = param_2;
  return;
}


// ==== entry=00b24fee name=FUN_00b24fee size=23 ====

void FUN_00b24fee(undefined8 *param_1)

{
  *param_1 = &DAT_00d3f610;
  return;
}


// ==== entry=00b25006 name=FUN_00b25006 size=23 ====

void FUN_00b25006(undefined8 *param_1)

{
  *param_1 = &DAT_00d3f610;
  return;
}


// ==== entry=00b2501e name=FUN_00b2501e size=38 ====

void FUN_00b2501e(void *param_1)

{
  FUN_00b25006(param_1);
  operator_delete(param_1);
  return;
}


// ==== entry=00b25044 name=FUN_00b25044 size=94 ====

undefined1  [16] FUN_00b25044(undefined8 param_1,undefined8 param_2)

{
  undefined8 uVar1;
  undefined1 local_38 [16];
  undefined1 local_28 [16];
  
  uVar1 = FUN_00b04cef(param_2);
  local_38 = FUN_00528a22(param_1,uVar1);
  FUN_00b25446(local_28,local_38,local_38 + 8);
  return local_28;
}


// ==== entry=00b250a2 name=FUN_00b250a2 size=55 ====

void FUN_00b250a2(long param_1)

{
  FUN_00b25494(param_1);
  FUN_00b254b0(param_1);
  FUN_00b00f0c(param_1 + 8);
  return;
}


// ==== entry=00b250da name=FUN_00b250da size=27 ====

void FUN_00b250da(undefined8 param_1)

{
  FUN_00b254bc(param_1);
  return;
}


// ==== entry=00b250f6 name=FUN_00b250f6 size=57 ====

void FUN_00b250f6(undefined8 param_1)

{
  undefined8 uVar1;
  
  uVar1 = FUN_00b0157e(param_1);
  FUN_00528840(param_1,uVar1);
  FUN_00b24e5c(param_1);
  return;
}


// ==== entry=00b25130 name=FUN_00b25130 size=38 ====

void FUN_00b25130(undefined8 param_1,undefined8 param_2)

{
  FUN_00b254c8(param_1,param_2);
  return;
}


// ==== entry=00b25156 name=FUN_00b25156 size=38 ====

void FUN_00b25156(undefined8 param_1,undefined8 param_2)

{
  FUN_00b25510(param_1,param_2);
  return;
}


// ==== entry=00b2517c name=FUN_00b2517c size=27 ====

void FUN_00b2517c(undefined8 param_1)

{
  FUN_00b25574(param_1);
  return;
}


// ==== entry=00b25198 name=FUN_00b25198 size=68 ====

void FUN_00b25198(undefined8 *param_1)

{
  undefined8 uVar1;
  
  uVar1 = FUN_00b255de(param_1);
  FUN_00b255ec(*param_1,param_1[1],uVar1);
  FUN_00b25590(param_1);
  return;
}


// ==== entry=00b251dc name=FUN_00b251dc size=66 ====

void FUN_00b251dc(undefined8 param_1)

{
  undefined8 local_18;
  undefined8 local_10;
  
  local_18 = FUN_00b0520c(param_1);
  local_10 = FUN_00b04f4a(param_1);
  FUN_00b25616(&local_10,&local_18);
  return;
}


// ==== entry=00b2521e name=FUN_00b2521e size=64 ====

void FUN_00b2521e(undefined8 param_1)

{
  undefined8 local_18;
  undefined8 local_10;
  
  local_10 = FUN_00b0523e(param_1);
  local_18 = FUN_00b25652(&local_10,1);
  FUN_00b25694(&local_18);
  return;
}


// ==== entry=00b2525e name=FUN_00b2525e size=35 ====

long FUN_00b2525e(long *param_1)

{
  return param_1[1] - *param_1 >> 4;
}


// ==== entry=00b25282 name=FUN_00b25282 size=192 ====

void FUN_00b25282(long param_1,undefined8 param_2,undefined8 param_3)

{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  
  if (*(long *)(param_1 + 8) == *(long *)(param_1 + 0x10)) {
    uVar1 = FUN_00b0223a(param_3);
    uVar2 = FUN_00b0551d(param_2);
    uVar3 = FUN_00b256f8(param_1);
    FUN_00b25722(param_1,uVar3,uVar2,uVar1);
  }
  else {
    uVar1 = FUN_00b0223a(param_3);
    uVar2 = FUN_00b0551d(param_2);
    FUN_00b256a5(param_1,*(undefined8 *)(param_1 + 8),uVar2,uVar1);
    *(long *)(param_1 + 8) = *(long *)(param_1 + 8) + 0x10;
  }
  return;
}


// ==== entry=00b25342 name=FUN_00b25342 size=58 ====

void FUN_00b25342(long param_1)

{
  *(long *)(param_1 + 8) = *(long *)(param_1 + 8) + -8;
  FUN_00b06c16(param_1,*(undefined8 *)(param_1 + 8));
  return;
}


// ==== entry=00b2537c name=FUN_00b2537c size=66 ====

void FUN_00b2537c(undefined8 param_1)

{
  undefined8 local_18;
  undefined8 local_10;
  
  local_18 = FUN_00b259a2(param_1);
  local_10 = FUN_00b25972(param_1);
  FUN_00b259d3(&local_10,&local_18);
  return;
}


// ==== entry=00b253be name=FUN_00b253be size=64 ====

void FUN_00b253be(undefined8 param_1)

{
  undefined8 local_18;
  undefined8 local_10;
  
  local_10 = FUN_00b256f8(param_1);
  local_18 = FUN_00b25a10(&local_10,1);
  FUN_00b25a52(&local_18);
  return;
}


// ==== entry=00b253fe name=FUN_00b253fe size=58 ====

void FUN_00b253fe(long param_1)

{
  *(long *)(param_1 + 8) = *(long *)(param_1 + 8) + -0x10;
  FUN_00b25a63(param_1,*(undefined8 *)(param_1 + 8));
  return;
}


// ==== entry=00b25438 name=FUN_00b25438 size=14 ====

undefined8 FUN_00b25438(undefined8 param_1)

{
  return param_1;
}


// ==== entry=00b25446 name=FUN_00b25446 size=78 ====

void FUN_00b25446(long param_1,undefined8 param_2,undefined8 param_3)

{
  undefined8 uVar1;
  undefined1 *puVar2;
  
  uVar1 = FUN_00b25438(param_2);
  FUN_00b25dee(param_1,uVar1);
  puVar2 = (undefined1 *)FUN_00b01aa4(param_3);
  *(undefined1 *)(param_1 + 8) = *puVar2;
  return;
}


// ==== entry=00b25494 name=FUN_00b25494 size=27 ====

void FUN_00b25494(undefined8 param_1)

{
  FUN_00b25e0c(param_1);
  return;
}


// ==== entry=00b254b0 name=FUN_00b254b0 size=11 ====

void FUN_00b254b0(void)

{
  return;
}


// ==== entry=00b254bc name=FUN_00b254bc size=11 ====

void FUN_00b254bc(void)

{
  return;
}


// ==== entry=00b254c8 name=FUN_00b254c8 size=72 ====

void FUN_00b254c8(undefined8 *param_1,undefined8 param_2)

{
  *param_1 = param_2;
  FUN_00b25e52(param_1 + 1,param_2);
  FUN_00b25e78(param_1,param_2);
  return;
}


// ==== entry=00b25510 name=FUN_00b25510 size=72 ====

void FUN_00b25510(undefined8 *param_1,undefined8 param_2)

{
  *param_1 = param_2;
  FUN_00b25e88(param_1 + 1,param_2);
  FUN_00b25eae(param_1,param_2);
  return;
}


// ==== entry=00b25558 name=FUN_00b25558 size=27 ====

void FUN_00b25558(undefined8 param_1)

{
  FUN_00b25efc(param_1);
  return;
}


// ==== entry=00b25574 name=FUN_00b25574 size=27 ====

void FUN_00b25574(undefined8 param_1)

{
  FUN_00b25ebe(param_1);
  return;
}


// ==== entry=00b25590 name=FUN_00b25590 size=77 ====

void FUN_00b25590(long *param_1)

{
  FUN_00b25f18(param_1,*param_1,param_1[2] - *param_1 >> 4);
  FUN_00b25558(param_1);
  return;
}


// ==== entry=00b255de name=FUN_00b255de size=14 ====

undefined8 FUN_00b255de(undefined8 param_1)

{
  return param_1;
}


// ==== entry=00b255ec name=FUN_00b255ec size=42 ====

void FUN_00b255ec(undefined8 param_1,undefined8 param_2)

{
  FUN_00b25f4d(param_1,param_2);
  return;
}


// ==== entry=00b25616 name=FUN_00b25616 size=60 ====

undefined8 FUN_00b25616(undefined8 param_1,undefined8 param_2)

{
  long lVar1;
  long *plVar2;
  
  plVar2 = (long *)FUN_00b25f74(param_1);
  lVar1 = *plVar2;
  plVar2 = (long *)FUN_00b25f74(param_2);
  return CONCAT71((int7)((ulong)*plVar2 >> 8),lVar1 == *plVar2);
}


// ==== entry=00b25652 name=FUN_00b25652 size=66 ====

undefined8 FUN_00b25652(long *param_1,long param_2)

{
  undefined8 local_18;
  long local_10;
  
  local_10 = *param_1 + param_2 * -8;
  FUN_00b059a6(&local_18,&local_10);
  return local_18;
}


// ==== entry=00b25694 name=FUN_00b25694 size=17 ====

undefined8 FUN_00b25694(undefined8 *param_1)

{
  return *param_1;
}


// ==== entry=00b256a5 name=FUN_00b256a5 size=82 ====

void FUN_00b256a5(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 uVar1;
  undefined8 uVar2;
  
  uVar1 = FUN_00b0223a(param_4);
  uVar2 = FUN_00b0551d(param_3);
  FUN_00b25f82(param_1,param_2,uVar2,uVar1);
  return;
}


// ==== entry=00b256f8 name=FUN_00b256f8 size=41 ====

undefined8 FUN_00b256f8(long param_1)

{
  undefined8 local_10;
  
  FUN_00b25fe4(&local_10,param_1 + 8);
  return local_10;
}


// ==== entry=00b25722 name=FUN_00b25722 size=460 ====

void FUN_00b25722(long *param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined8 *puVar3;
  undefined8 local_68;
  long *local_60;
  undefined8 local_50;
  long local_48;
  long local_40;
  long local_38;
  long local_30;
  long local_28;
  long local_20;
  
  local_68 = param_2;
  local_60 = param_1;
  local_28 = FUN_00b26002(param_1,1,"vector::_M_realloc_insert");
  local_30 = *local_60;
  local_38 = local_60[1];
  local_50 = FUN_00b260cc(local_60);
  local_40 = FUN_00b260f1(&local_68,&local_50);
  local_48 = FUN_00b26132(local_60,local_28);
  local_20 = local_48;
  uVar1 = FUN_00b0223a(param_4);
  uVar2 = FUN_00b0551d(param_3);
                    /* try { // try from 00b257f0 to 00b25867 has its CatchHandler @ 00b258e7 */
  FUN_00b256a5(local_60,local_40 * 0x10 + local_48,uVar2,uVar1);
  local_20 = 0;
  uVar1 = FUN_00b255de(local_60);
  puVar3 = (undefined8 *)FUN_00b26166(&local_68);
  local_20 = FUN_00b26174(local_30,*puVar3,local_48,uVar1);
  local_20 = local_20 + 0x10;
  uVar1 = FUN_00b255de(local_60);
  puVar3 = (undefined8 *)FUN_00b26166(&local_68);
  local_20 = FUN_00b26174(*puVar3,local_38,local_20,uVar1);
  uVar1 = FUN_00b255de(local_60);
  FUN_00b255ec(local_30,local_38,uVar1);
  FUN_00b25f18(local_60,local_30,local_60[2] - local_30 >> 4);
  *local_60 = local_48;
  local_60[1] = local_20;
  local_60[2] = local_28 * 0x10 + local_48;
  return;
}


// ==== entry=00b25972 name=FUN_00b25972 size=48 ====

undefined8 FUN_00b25972(undefined8 *param_1)

{
  undefined8 local_18;
  undefined8 local_10;
  
  local_10 = *param_1;
  FUN_00b261c8(&local_18,&local_10);
  return local_18;
}


// ==== entry=00b259a2 name=FUN_00b259a2 size=49 ====

undefined8 FUN_00b259a2(long param_1)

{
  undefined8 local_18;
  undefined8 local_10;
  
  local_10 = *(undefined8 *)(param_1 + 8);
  FUN_00b261c8(&local_18,&local_10);
  return local_18;
}


// ==== entry=00b259d3 name=FUN_00b259d3 size=60 ====

undefined8 FUN_00b259d3(undefined8 param_1,undefined8 param_2)

{
  long lVar1;
  long *plVar2;
  
  plVar2 = (long *)FUN_00b261e6(param_1);
  lVar1 = *plVar2;
  plVar2 = (long *)FUN_00b261e6(param_2);
  return CONCAT71((int7)((ulong)*plVar2 >> 8),lVar1 == *plVar2);
}


// ==== entry=00b25a10 name=FUN_00b25a10 size=66 ====

undefined8 FUN_00b25a10(long *param_1,long param_2)

{
  undefined8 local_18;
  long local_10;
  
  local_10 = *param_1 + param_2 * -0x10;
  FUN_00b25fe4(&local_18,&local_10);
  return local_18;
}


// ==== entry=00b25a52 name=FUN_00b25a52 size=17 ====

undefined8 FUN_00b25a52(undefined8 *param_1)

{
  return *param_1;
}


// ==== entry=00b25a63 name=FUN_00b25a63 size=38 ====

void FUN_00b25a63(undefined8 param_1,undefined8 param_2)

{
  FUN_00b261f4(param_1,param_2);
  return;
}


// ==== entry=00b25a8a name=FUN_00b25a8a size=68 ====

void FUN_00b25a8a(undefined8 *param_1,undefined8 param_2,undefined8 param_3)

{
  undefined8 *puVar1;
  
  puVar1 = (undefined8 *)FUN_00b25ace(param_2);
  *param_1 = *puVar1;
  puVar1 = (undefined8 *)FUN_00b01a96(param_3);
  param_1[1] = *puVar1;
  return;
}


// ==== entry=00b25ace name=FUN_00b25ace size=14 ====

undefined8 FUN_00b25ace(undefined8 param_1)

{
  return param_1;
}


// ==== entry=00b25adc name=FUN_00b25adc size=387 ====

undefined1  [16] FUN_00b25adc(undefined8 param_1,undefined8 *param_2)

{
  undefined8 uVar1;
  char cVar2;
  undefined8 *puVar3;
  undefined1 auVar4 [16];
  undefined8 local_78;
  long local_70;
  long local_68;
  undefined8 local_60;
  undefined8 local_58;
  undefined8 local_50;
  undefined8 local_48;
  undefined8 local_40;
  undefined8 local_38;
  undefined8 local_30;
  undefined8 local_28;
  char local_19;
  
  local_68 = FUN_00b01692(param_1);
  local_70 = FUN_00b26204(param_1);
  local_19 = '\x01';
  while (local_68 != 0) {
    local_70 = local_68;
    puVar3 = (undefined8 *)FUN_00b26216(local_68);
    local_19 = FUN_00b24bbe(param_1,*param_2,*puVar3);
    if (local_19 == '\0') {
      local_68 = FUN_00b019fb(local_68);
    }
    else {
      local_68 = FUN_00b01a0d(local_68);
    }
  }
  FUN_00b25dd4(&local_78,local_70);
  if (local_19 != '\0') {
    local_60 = FUN_00b26244(param_1);
    cVar2 = FUN_00b2626e(&local_78,&local_60);
    if (cVar2 != '\0') {
      FUN_00b25a8a(&local_58,&local_68,&local_70);
      goto LAB_00b25c56;
    }
    FUN_00b26290(&local_78);
  }
  uVar1 = *param_2;
  puVar3 = (undefined8 *)FUN_00b262bb(local_78);
  cVar2 = FUN_00b24bbe(param_1,*puVar3,uVar1);
  if (cVar2 == '\0') {
    local_28 = 0;
    FUN_00b01a5a(&local_38,&local_78,&local_28);
    local_58 = local_38;
    local_50 = local_30;
  }
  else {
    FUN_00b25a8a(&local_48,&local_68,&local_70);
    local_58 = local_48;
    local_50 = local_40;
  }
LAB_00b25c56:
  auVar4._8_8_ = local_50;
  auVar4._0_8_ = local_58;
  return auVar4;
}


// ==== entry=00b25c60 name=FUN_00b25c60 size=18 ====

undefined8 FUN_00b25c60(undefined8 param_1,undefined8 param_2)

{
  return param_2;
}


// ==== entry=00b25c72 name=FUN_00b25c72 size=26 ====

void FUN_00b25c72(undefined8 *param_1,undefined8 param_2)

{
  *param_1 = param_2;
  return;
}


// ==== entry=00b25c8c name=FUN_00b25c8c size=243 ====

undefined8
FUN_00b25c8c(long param_1,long param_2,_Rb_tree_node_base *param_3,undefined8 param_4,
            undefined8 param_5)

{
  char cVar1;
  _Rb_tree_node_base *p_Var2;
  undefined8 *puVar3;
  undefined8 uVar4;
  undefined1 local_31;
  undefined8 local_30;
  _Rb_tree_node_base *local_28;
  bool local_19;
  
  if (param_2 == 0) {
    p_Var2 = (_Rb_tree_node_base *)FUN_00b26204(param_1);
    if (param_3 != p_Var2) {
      puVar3 = (undefined8 *)FUN_00b262bb(param_3);
      uVar4 = *puVar3;
      puVar3 = (undefined8 *)FUN_00b25c60(&local_31,param_4);
      cVar1 = FUN_00b24bbe(param_1,*puVar3,uVar4);
      if (cVar1 == '\0') {
        local_19 = false;
        goto LAB_00b25d0b;
      }
    }
  }
  local_19 = true;
LAB_00b25d0b:
  uVar4 = FUN_00b0551d(param_4);
  local_28 = (_Rb_tree_node_base *)FUN_00b262e8(param_5,uVar4);
  std::_Rb_tree_insert_and_rebalance(local_19,local_28,param_3,(_Rb_tree_node_base *)(param_1 + 8));
  *(long *)(param_1 + 0x28) = *(long *)(param_1 + 0x28) + 1;
  FUN_00b25dd4(&local_30,local_28);
  return local_30;
}


// ==== entry=00b25d7f name=FUN_00b25d7f size=14 ====

undefined8 FUN_00b25d7f(undefined8 param_1)

{
  return param_1;
}


// ==== entry=00b25d8e name=FUN_00b25d8e size=70 ====

void FUN_00b25d8e(undefined8 *param_1,undefined8 param_2,undefined8 param_3)

{
  undefined8 *puVar1;
  undefined1 *puVar2;
  
  puVar1 = (undefined8 *)FUN_00b25d7f(param_2);
  *param_1 = *puVar1;
  puVar2 = (undefined1 *)FUN_00b0223a(param_3);
  *(undefined1 *)(param_1 + 1) = *puVar2;
  return;
}


// ==== entry=00b25dd4 name=FUN_00b25dd4 size=26 ====

void FUN_00b25dd4(undefined8 *param_1,undefined8 param_2)

{
  *param_1 = param_2;
  return;
}


// ==== entry=00b25dee name=FUN_00b25dee size=29 ====

void FUN_00b25dee(undefined8 *param_1,undefined8 *param_2)

{
  *param_1 = *param_2;
  return;
}


// ==== entry=00b25e0c name=FUN_00b25e0c size=11 ====

void FUN_00b25e0c(void)

{
  return;
}


// ==== entry=00b25e18 name=FUN_00b25e18 size=57 ====

void FUN_00b25e18(undefined8 param_1,undefined8 param_2)

{
  FUN_00b2631e(param_1,param_2);
  FUN_00b01fb4(param_1,param_2);
  return;
}


// ==== entry=00b25e52 name=FUN_00b25e52 size=38 ====

void FUN_00b25e52(undefined8 param_1,undefined8 param_2)

{
  FUN_00b2637a(param_1,param_2);
  return;
}


// ==== entry=00b25e78 name=FUN_00b25e78 size=15 ====

void FUN_00b25e78(void)

{
  return;
}


// ==== entry=00b25e88 name=FUN_00b25e88 size=38 ====

void FUN_00b25e88(undefined8 param_1,undefined8 param_2)

{
  FUN_00787f8c(param_1,param_2);
  return;
}


// ==== entry=00b25eae name=FUN_00b25eae size=15 ====

void FUN_00b25eae(void)

{
  return;
}


// ==== entry=00b25ebe name=FUN_00b25ebe size=62 ====

void FUN_00b25ebe(undefined8 *param_1)

{
  FUN_00b26418(param_1);
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  return;
}


// ==== entry=00b25efc name=FUN_00b25efc size=27 ====

void FUN_00b25efc(undefined8 param_1)

{
  FUN_00b26434(param_1);
  return;
}


// ==== entry=00b25f18 name=FUN_00b25f18 size=53 ====

void FUN_00b25f18(undefined8 param_1,long param_2,undefined8 param_3)

{
  if (param_2 != 0) {
    FUN_00b2643f(param_1,param_2,param_3);
  }
  return;
}


// ==== entry=00b25f4d name=FUN_00b25f4d size=38 ====

void FUN_00b25f4d(undefined8 param_1,undefined8 param_2)

{
  FUN_00b2646d(param_1,param_2);
  return;
}


// ==== entry=00b25f74 name=FUN_00b25f74 size=14 ====

undefined8 FUN_00b25f74(undefined8 param_1)

{
  return param_1;
}


// ==== entry=00b25f82 name=FUN_00b25f82 size=98 ====

void FUN_00b25f82(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  
  uVar1 = FUN_00b0551d(param_3);
  uVar2 = FUN_00b0223a(param_4);
  uVar3 = FUN_00b00efa(0x10,param_2);
  FUN_00b2647c(uVar3,uVar1,uVar2);
  return;
}


// ==== entry=00b25fe4 name=FUN_00b25fe4 size=29 ====

void FUN_00b25fe4(undefined8 *param_1,undefined8 *param_2)

{
  *param_1 = *param_2;
  return;
}


// ==== entry=00b26002 name=FUN_00b26002 size=201 ====

ulong FUN_00b26002(undefined8 param_1,ulong param_2,char *param_3)

{
  long lVar1;
  long lVar2;
  long *plVar3;
  ulong uVar4;
  ulong local_38;
  undefined8 local_30;
  undefined8 local_28;
  ulong local_20;
  
  local_38 = param_2;
  local_30 = param_1;
  lVar1 = FUN_00b264c0(param_1);
  lVar2 = FUN_00b2525e(local_30);
  if (local_38 <= (ulong)(lVar1 - lVar2)) {
    lVar1 = FUN_00b2525e(local_30);
    local_28 = FUN_00b2525e(local_30);
    plVar3 = (long *)FUN_00b06d34(&local_28,&local_38);
    local_20 = *plVar3 + lVar1;
    uVar4 = FUN_00b2525e(local_30);
    if ((local_20 < uVar4) || (uVar4 = FUN_00b264c0(local_30), uVar4 < local_20)) {
      local_20 = FUN_00b264c0(local_30);
    }
    return local_20;
  }
                    /* WARNING: Subroutine does not return */
  std::__throw_length_error(param_3);
}


// ==== entry=00b260cc name=FUN_00b260cc size=37 ====

undefined8 FUN_00b260cc(undefined8 param_1)

{
  undefined8 local_10;
  
  FUN_00b25fe4(&local_10,param_1);
  return local_10;
}


// ==== entry=00b260f1 name=FUN_00b260f1 size=64 ====

long FUN_00b260f1(undefined8 param_1,undefined8 param_2)

{
  long lVar1;
  long *plVar2;
  
  plVar2 = (long *)FUN_00b26166(param_1);
  lVar1 = *plVar2;
  plVar2 = (long *)FUN_00b26166(param_2);
  return lVar1 - *plVar2 >> 4;
}


// ==== entry=00b26132 name=FUN_00b26132 size=51 ====

undefined8 FUN_00b26132(undefined8 param_1,long param_2)

{
  undefined8 uVar1;
  
  if (param_2 == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = FUN_00b264e2(param_1,param_2);
  }
  return uVar1;
}


// ==== entry=00b26166 name=FUN_00b26166 size=14 ====

undefined8 FUN_00b26166(undefined8 param_1)

{
  return param_1;
}


// ==== entry=00b26174 name=FUN_00b26174 size=84 ====

void FUN_00b26174(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 uVar1;
  undefined8 uVar2;
  
  uVar1 = FUN_00b2650c(param_2);
  uVar2 = FUN_00b2650c(param_1);
  FUN_00b26531(uVar2,uVar1,param_3,param_4);
  return;
}


// ==== entry=00b261c8 name=FUN_00b261c8 size=29 ====

void FUN_00b261c8(undefined8 *param_1,undefined8 *param_2)

{
  *param_1 = *param_2;
  return;
}


// ==== entry=00b261e6 name=FUN_00b261e6 size=14 ====

undefined8 FUN_00b261e6(undefined8 param_1)

{
  return param_1;
}


// ==== entry=00b261f4 name=FUN_00b261f4 size=15 ====

void FUN_00b261f4(void)

{
  return;
}


// ==== entry=00b26204 name=FUN_00b26204 size=18 ====

long FUN_00b26204(long param_1)

{
  return param_1 + 8;
}


// ==== entry=00b26216 name=FUN_00b26216 size=45 ====

void FUN_00b26216(undefined8 param_1)

{
  undefined8 uVar1;
  undefined1 local_9;
  
  uVar1 = FUN_00b26562(param_1);
  FUN_00b2657c(&local_9,uVar1);
  return;
}


// ==== entry=00b26244 name=FUN_00b26244 size=41 ====

undefined8 FUN_00b26244(long param_1)

{
  undefined8 local_10;
  
  FUN_00b25dd4(&local_10,*(undefined8 *)(param_1 + 0x18));
  return local_10;
}


// ==== entry=00b2626e name=FUN_00b2626e size=34 ====

undefined8 FUN_00b2626e(long *param_1,long *param_2)

{
  return CONCAT71((int7)((ulong)*param_2 >> 8),*param_1 == *param_2);
}


// ==== entry=00b26290 name=FUN_00b26290 size=43 ====

undefined8 * FUN_00b26290(undefined8 *param_1)

{
  undefined8 uVar1;
  
  uVar1 = std::_Rb_tree_decrement((_Rb_tree_node_base *)*param_1);
  *param_1 = uVar1;
  return param_1;
}


// ==== entry=00b262bb name=FUN_00b262bb size=45 ====

void FUN_00b262bb(undefined8 param_1)

{
  undefined8 uVar1;
  undefined1 local_9;
  
  uVar1 = FUN_00b2658e(param_1);
  FUN_00b2657c(&local_9,uVar1);
  return;
}


// ==== entry=00b262e8 name=FUN_00b262e8 size=54 ====

void FUN_00b262e8(undefined8 *param_1,undefined8 param_2)

{
  undefined8 uVar1;
  undefined8 uVar2;
  
  uVar1 = *param_1;
  uVar2 = FUN_00b0551d(param_2);
  FUN_00b265a8(uVar1,uVar2);
  return;
}


// ==== entry=00b2631e name=FUN_00b2631e size=63 ====

void FUN_00b2631e(undefined8 param_1,undefined8 param_2)

{
  undefined8 uVar1;
  undefined8 uVar2;
  
  uVar1 = FUN_00b0295c(param_2);
  uVar2 = FUN_00b0294e(param_1);
  FUN_00b265f0(uVar2,uVar1);
  return;
}


// ==== entry=00b2635e name=FUN_00b2635e size=27 ====

void FUN_00b2635e(undefined8 param_1)

{
  FUN_00b24eb0(param_1);
  return;
}


// ==== entry=00b2637a name=FUN_00b2637a size=72 ====

void FUN_00b2637a(undefined8 *param_1,undefined8 param_2)

{
  void *pvVar1;
  
  *param_1 = 0;
                    /* try { // try from 00b2639b to 00b2639f has its CatchHandler @ 00b263bb */
  pvVar1 = operator_new(0x18);
  FUN_00b26616(pvVar1,param_2);
  *param_1 = pvVar1;
  return;
}


// ==== entry=00b263fc name=FUN_00b263fc size=27 ====

void FUN_00b263fc(undefined8 param_1)

{
  FUN_00b24f42(param_1);
  return;
}


// ==== entry=00b26418 name=FUN_00b26418 size=27 ====

void FUN_00b26418(undefined8 param_1)

{
  FUN_00b26686(param_1);
  return;
}


// ==== entry=00b26434 name=FUN_00b26434 size=11 ====

void FUN_00b26434(void)

{
  return;
}


// ==== entry=00b2643f name=FUN_00b2643f size=46 ====

void FUN_00b2643f(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  FUN_00b26692(param_1,param_2,param_3);
  return;
}


// ==== entry=00b2646d name=FUN_00b2646d size=15 ====

void FUN_00b2646d(void)

{
  return;
}


// ==== entry=00b2647c name=FUN_00b2647c size=67 ====

void FUN_00b2647c(undefined8 *param_1,undefined8 param_2,undefined8 param_3)

{
  undefined8 *puVar1;
  undefined1 *puVar2;
  
  puVar1 = (undefined8 *)FUN_00b0551d(param_2);
  *param_1 = *puVar1;
  puVar2 = (undefined1 *)FUN_00b0223a(param_3);
  *(undefined1 *)(param_1 + 1) = *puVar2;
  return;
}


// ==== entry=00b264c0 name=FUN_00b264c0 size=34 ====

void FUN_00b264c0(undefined8 param_1)

{
  undefined8 uVar1;
  
  uVar1 = FUN_00b266d0(param_1);
  FUN_00b266b5(uVar1);
  return;
}


// ==== entry=00b264e2 name=FUN_00b264e2 size=42 ====

void FUN_00b264e2(undefined8 param_1,undefined8 param_2)

{
  FUN_00b266de(param_1,param_2,0);
  return;
}


// ==== entry=00b2650c name=FUN_00b2650c size=37 ====

undefined8 FUN_00b2650c(undefined8 param_1)

{
  undefined8 local_10;
  
  FUN_00b26720(&local_10,param_1);
  return local_10;
}


// ==== entry=00b26531 name=FUN_00b26531 size=49 ====

void FUN_00b26531(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  FUN_00b2673a(param_1,param_2,param_3);
  return;
}


// ==== entry=00b26562 name=FUN_00b26562 size=26 ====

void FUN_00b26562(undefined8 param_1)

{
  FUN_00b056c0(param_1);
  return;
}


// ==== entry=00b2657c name=FUN_00b2657c size=18 ====

undefined8 FUN_00b2657c(undefined8 param_1,undefined8 param_2)

{
  return param_2;
}


// ==== entry=00b2658e name=FUN_00b2658e size=26 ====

void FUN_00b2658e(undefined8 param_1)

{
  FUN_00b056c0(param_1);
  return;
}


// ==== entry=00b265a8 name=FUN_00b265a8 size=72 ====

undefined8 FUN_00b265a8(undefined8 param_1,undefined8 param_2)

{
  undefined8 uVar1;
  undefined8 uVar2;
  
  uVar1 = FUN_00b2676c(param_1);
  uVar2 = FUN_00b0551d(param_2);
  FUN_00b26794(param_1,uVar1,uVar2);
  return uVar1;
}


// ==== entry=00b265f0 name=FUN_00b265f0 size=38 ====

void FUN_00b265f0(undefined8 param_1,undefined8 param_2)

{
  FUN_00b26832(param_1,param_2);
  return;
}


// ==== entry=00b26616 name=FUN_00b26616 size=55 ====

void FUN_00b26616(undefined8 *param_1,undefined8 param_2)

{
  FUN_00b02d1a(param_1);
  *param_1 = &PTR_FUN_01183e80;
  param_1[2] = param_2;
  return;
}


// ==== entry=00b2664e name=FUN_00b2664e size=55 ====

void FUN_00b2664e(undefined8 *param_1,undefined8 param_2)

{
  FUN_00b02d1a(param_1);
  *param_1 = &PTR_FUN_01183eb8;
  param_1[2] = param_2;
  return;
}


// ==== entry=00b26686 name=FUN_00b26686 size=11 ====

void FUN_00b26686(void)

{
  return;
}


// ==== entry=00b26692 name=FUN_00b26692 size=35 ====

void FUN_00b26692(undefined8 param_1,void *param_2)

{
  operator_delete(param_2);
  return;
}


// ==== entry=00b266b5 name=FUN_00b266b5 size=26 ====

void FUN_00b266b5(undefined8 param_1)

{
  FUN_00b26852(param_1);
  return;
}


// ==== entry=00b266d0 name=FUN_00b266d0 size=14 ====

undefined8 FUN_00b266d0(undefined8 param_1)

{
  return param_1;
}


// ==== entry=00b266de name=FUN_00b266de size=66 ====

void FUN_00b266de(undefined8 param_1,ulong param_2)

{
  ulong uVar1;
  
  uVar1 = FUN_00b26852(param_1);
  if (uVar1 < param_2) {
                    /* WARNING: Subroutine does not return */
    std::__throw_bad_alloc();
  }
  operator_new(param_2 << 4);
  return;
}


// ==== entry=00b26720 name=FUN_00b26720 size=26 ====

void FUN_00b26720(undefined8 *param_1,undefined8 param_2)

{
  *param_1 = param_2;
  return;
}


// ==== entry=00b2673a name=FUN_00b2673a size=49 ====

void FUN_00b2673a(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  FUN_00b26866(param_1,param_2,param_3);
  return;
}


// ==== entry=00b2676c name=FUN_00b2676c size=39 ====

void FUN_00b2676c(undefined8 param_1)

{
  undefined8 uVar1;
  
  uVar1 = FUN_00b02ae4(param_1);
  FUN_00b26913(uVar1,1);
  return;
}


// ==== entry=00b26794 name=FUN_00b26794 size=107 ====

void FUN_00b26794(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  
  FUN_00b00efa(0x28,param_2);
  uVar1 = FUN_00b0551d(param_3);
  uVar2 = FUN_00b02af2(param_2);
  uVar3 = FUN_00b02ae4(param_1);
                    /* try { // try from 00b267ef to 00b267f3 has its CatchHandler @ 00b267f6 */
  FUN_00b2693d(uVar3,uVar2,uVar1);
  return;
}


// ==== entry=00b26832 name=FUN_00b26832 size=31 ====

void FUN_00b26832(undefined8 param_1,undefined8 param_2)

{
  FUN_00b0125a(param_2);
  return;
}


// ==== entry=00b26852 name=FUN_00b26852 size=20 ====

undefined8 FUN_00b26852(void)

{
  return 0xfffffffffffffff;
}


// ==== entry=00b26866 name=FUN_00b26866 size=122 ====

long FUN_00b26866(undefined8 param_1,undefined8 param_2,long param_3)

{
  char cVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 local_38;
  undefined8 local_30 [2];
  long local_20;
  
  local_38 = param_2;
  local_30[0] = param_1;
  local_20 = param_3;
  while( true ) {
                    /* try { // try from 00b26891 to 00b26895 has its CatchHandler @ 00b268d9 */
    cVar1 = FUN_00b26976(local_30,&local_38);
    if (cVar1 == '\0') break;
    uVar2 = FUN_00b269cc(local_30);
    uVar3 = FUN_00b269be(local_20);
    FUN_00b269eb(uVar3,uVar2);
    FUN_00b2699e(local_30);
    local_20 = local_20 + 0x10;
  }
  return local_20;
}


// ==== entry=00b26913 name=FUN_00b26913 size=42 ====

void FUN_00b26913(undefined8 param_1,undefined8 param_2)

{
  FUN_00b26a36(param_1,param_2,0);
  return;
}


// ==== entry=00b2693d name=FUN_00b2693d size=57 ====

void FUN_00b2693d(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  undefined8 uVar1;
  
  uVar1 = FUN_00b0551d(param_3);
  FUN_00b26a82(param_1,param_2,uVar1);
  return;
}


// ==== entry=00b26976 name=FUN_00b26976 size=40 ====

uint FUN_00b26976(undefined8 param_1,undefined8 param_2)

{
  uint uVar1;
  
  uVar1 = FUN_00b26ac2(param_1,param_2);
  return uVar1 ^ 1;
}


// ==== entry=00b2699e name=FUN_00b2699e size=32 ====

long * FUN_00b2699e(long *param_1)

{
  *param_1 = *param_1 + 0x10;
  return param_1;
}


// ==== entry=00b269be name=FUN_00b269be size=14 ====

undefined8 FUN_00b269be(undefined8 param_1)

{
  return param_1;
}


// ==== entry=00b269cc name=FUN_00b269cc size=17 ====

undefined8 FUN_00b269cc(undefined8 *param_1)

{
  return *param_1;
}


// ==== entry=00b269dd name=FUN_00b269dd size=14 ====

undefined8 FUN_00b269dd(undefined8 param_1)

{
  return param_1;
}


// ==== entry=00b269eb name=FUN_00b269eb size=74 ====

void FUN_00b269eb(undefined8 param_1,undefined8 param_2)

{
  undefined8 uVar1;
  undefined8 *puVar2;
  undefined8 *puVar3;
  
  puVar2 = (undefined8 *)FUN_00b269dd(param_2);
  puVar3 = (undefined8 *)FUN_00b00efa(0x10,param_1);
  uVar1 = puVar2[1];
  *puVar3 = *puVar2;
  puVar3[1] = uVar1;
  return;
}


// ==== entry=00b26a36 name=FUN_00b26a36 size=76 ====

void FUN_00b26a36(undefined8 param_1,ulong param_2)

{
  ulong uVar1;
  
  uVar1 = FUN_00b26afc(param_1);
  if (uVar1 < param_2) {
                    /* WARNING: Subroutine does not return */
    std::__throw_bad_alloc();
  }
  operator_new(param_2 * 0x28);
  return;
}


// ==== entry=00b26a82 name=FUN_00b26a82 size=64 ====

void FUN_00b26a82(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  undefined8 uVar1;
  undefined8 *puVar2;
  
  puVar2 = (undefined8 *)FUN_00b0551d(param_3);
  uVar1 = *puVar2;
  puVar2 = (undefined8 *)FUN_00b00efa(8,param_2);
  *puVar2 = uVar1;
  return;
}


// ==== entry=00b26ac2 name=FUN_00b26ac2 size=57 ====

bool FUN_00b26ac2(undefined8 param_1,undefined8 param_2)

{
  long lVar1;
  long lVar2;
  
  lVar1 = FUN_00b26b10(param_1);
  lVar2 = FUN_00b26b10(param_2);
  return lVar1 == lVar2;
}


// ==== entry=00b26afc name=FUN_00b26afc size=20 ====

undefined8 FUN_00b26afc(void)

{
  return 0x666666666666666;
}


// ==== entry=00b26b10 name=FUN_00b26b10 size=17 ====

undefined8 FUN_00b26b10(undefined8 *param_1)

{
  return *param_1;
}


// ==== entry=00b26b21 name=FUN_00b26b21 size=126 ====

undefined8 FUN_00b26b21(string *param_1)

{
  char cVar1;
  
  cVar1 = std::string::empty(param_1);
  if ((((cVar1 == '\0') && (cVar1 = FUN_00b0a358(param_1,&DAT_00d3f6d7), cVar1 == '\0')) &&
      (cVar1 = FUN_00b0a358(param_1,&DAT_00d3f6d9), cVar1 == '\0')) &&
     ((cVar1 = FUN_00b0a358(param_1,&DAT_00d3f6de), cVar1 == '\0' &&
      (cVar1 = FUN_00b0a358(param_1,&DAT_00d3f6e3), cVar1 == '\0')))) {
    return 0;
  }
  return 1;
}


// ==== entry=00b26ba0 name=FUN_00b26ba0 size=59 ====

void FUN_00b26ba0(undefined4 *param_1,undefined4 param_2)

{
  *param_1 = param_2;
  *(undefined1 *)(param_1 + 1) = 0;
  *(undefined1 *)((long)param_1 + 5) = 0;
  FUN_00b26f50(param_1 + 2);
  return;
}


// ==== entry=00b26bdc name=FUN_00b26bdc size=32 ====

void FUN_00b26bdc(undefined8 param_1)

{
  FUN_00b26ba0(param_1,0);
  return;
}


// ==== entry=00b26bfc name=FUN_00b26bfc size=65 ====

void FUN_00b26bfc(undefined4 *param_1,undefined1 param_2)

{
  *param_1 = 1;
  *(undefined1 *)(param_1 + 1) = param_2;
  *(undefined1 *)((long)param_1 + 5) = 0;
  FUN_00b26f50(param_1 + 2);
  return;
}


// ==== entry=00b26c3e name=FUN_00b26c3e size=73 ====

void FUN_00b26c3e(undefined4 *param_1,undefined1 param_2,undefined1 param_3)

{
  *param_1 = 2;
  *(undefined1 *)(param_1 + 1) = param_2;
  *(undefined1 *)((long)param_1 + 5) = param_3;
  FUN_00b26f50(param_1 + 2);
  return;
}


// ==== entry=00b26c88 name=FUN_00b26c88 size=138 ====

void FUN_00b26c88(undefined4 *param_1,string *param_2,undefined4 param_3)

{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined1 local_19;
  
  *param_1 = param_3;
  *(undefined1 *)(param_1 + 1) = 0;
  *(undefined1 *)((long)param_1 + 5) = 0;
  FUN_00b26f6c(&local_19);
  uVar1 = std::string::end(param_2);
  uVar2 = std::string::begin(param_2);
                    /* try { // try from 00b26cf6 to 00b26cfa has its CatchHandler @ 00b26d09 */
  FUN_00b26f88(param_1 + 2,uVar2,uVar1,&local_19);
  FUN_00b0f87c(&local_19);
  return;
}


// ==== entry=00b26d2c name=FUN_00b26d2c size=70 ====

long FUN_00b26d2c(long param_1,undefined8 param_2)

{
  FUN_00b26ba0(param_1,5);
                    /* try { // try from 00b26d60 to 00b26d64 has its CatchHandler @ 00b26d67 */
  FUN_00b26fee(param_1 + 8,param_2);
  return param_1;
}


// ==== entry=00b26d8c name=FUN_00b26d8c size=97 ====

long FUN_00b26d8c(long param_1,undefined8 param_2,undefined8 param_3)

{
  FUN_00b26ba0(param_1,3);
                    /* try { // try from 00b26dc4 to 00b26ddf has its CatchHandler @ 00b26de2 */
  FUN_00b26fee(param_1 + 8,param_2);
  FUN_00b26fee(param_1 + 8,param_3);
  return param_1;
}


// ==== entry=00b26e07 name=FUN_00b26e07 size=97 ====

long FUN_00b26e07(long param_1,undefined8 param_2,undefined8 param_3)

{
  FUN_00b26ba0(param_1,4);
                    /* try { // try from 00b26e3f to 00b26e5a has its CatchHandler @ 00b26e5d */
  FUN_00b26fee(param_1 + 8,param_2);
  FUN_00b26fee(param_1 + 8,param_3);
  return param_1;
}


// ==== entry=00b26e82 name=FUN_00b26e82 size=97 ====

long FUN_00b26e82(long param_1,undefined8 param_2,undefined8 param_3)

{
  FUN_00b26ba0(param_1,6);
                    /* try { // try from 00b26eba to 00b26ed5 has its CatchHandler @ 00b26ed8 */
  FUN_00b26fee(param_1 + 8,param_2);
  FUN_00b26fee(param_1 + 8,param_3);
  return param_1;
}


// ==== entry=00b26efd name=FUN_00b26efd size=62 ====

void FUN_00b26efd(int param_1,int param_2)

{
  if ((param_1 == 1) && (param_2 == 0xffff)) {
    std::ios_base::Init::Init((Init *)&DAT_011c35c1);
    __cxa_atexit(std::ios_base::Init::~Init,&DAT_011c35c1,&DAT_00c89008);
  }
  return;
}


// ==== entry=00b26f3b orig=FUN_00b26f3b size=21 name=_INIT_177 ====

void _INIT_177(void)

{
  FUN_00b26efd(1,0xffff);
  return;
}


// ==== entry=00b26f50 name=FUN_00b26f50 size=27 ====

void FUN_00b26f50(undefined8 param_1)

{
  FUN_00b2706a(param_1);
  return;
}


// ==== entry=00b26f6c name=FUN_00b26f6c size=27 ====

void FUN_00b26f6c(undefined8 param_1)

{
  FUN_00b27086(param_1);
  return;
}


// ==== entry=00b26f88 name=FUN_00b26f88 size=76 ====

void FUN_00b26f88(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  FUN_00b27092(param_1,param_4);
                    /* try { // try from 00b26fc6 to 00b26fca has its CatchHandler @ 00b26fcd */
  FUN_00b270b8(param_1,param_2,param_3);
  return;
}


// ==== entry=00b26fee name=FUN_00b26fee size=123 ====

void FUN_00b26fee(long param_1,undefined8 param_2)

{
  undefined8 uVar1;
  
  if (*(long *)(param_1 + 8) == *(long *)(param_1 + 0x10)) {
    uVar1 = FUN_00b27120(param_1);
    FUN_00b2714a(param_1,uVar1,param_2);
  }
  else {
    FUN_00b270e6(param_1,*(undefined8 *)(param_1 + 8),param_2);
    *(long *)(param_1 + 8) = *(long *)(param_1 + 8) + 0x20;
  }
  return;
}


// ==== entry=00b2706a name=FUN_00b2706a size=27 ====

void FUN_00b2706a(undefined8 param_1)

{
  FUN_00b27386(param_1);
  return;
}


// ==== entry=00b27086 name=FUN_00b27086 size=11 ====

void FUN_00b27086(void)

{
  return;
}


// ==== entry=00b27092 name=FUN_00b27092 size=38 ====

void FUN_00b27092(undefined8 param_1,undefined8 param_2)

{
  FUN_00b10930(param_1,param_2);
  return;
}


// ==== entry=00b270b8 name=FUN_00b270b8 size=46 ====

void FUN_00b270b8(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  FUN_00b273c4(param_1,param_2,param_3);
  return;
}


// ==== entry=00b270e6 name=FUN_00b270e6 size=57 ====

void FUN_00b270e6(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  undefined8 uVar1;
  
  uVar1 = FUN_00b12e20(param_3);
  FUN_00b2745a(param_1,param_2,uVar1);
  return;
}


// ==== entry=00b27120 name=FUN_00b27120 size=41 ====

undefined8 FUN_00b27120(long param_1)

{
  undefined8 local_10;
  
  FUN_00b274c8(&local_10,param_1 + 8);
  return local_10;
}


// ==== entry=00b2714a name=FUN_00b2714a size=441 ====

void FUN_00b2714a(long *param_1,undefined8 param_2,undefined8 param_3)

{
  undefined8 uVar1;
  undefined8 *puVar2;
  undefined8 local_68;
  long *local_60;
  undefined8 local_50;
  long local_48;
  long local_40;
  long local_38;
  long local_30;
  long local_28;
  long local_20;
  
  local_68 = param_2;
  local_60 = param_1;
  local_28 = FUN_00b274e6(param_1,1,"vector::_M_realloc_insert");
  local_30 = *local_60;
  local_38 = local_60[1];
  local_50 = FUN_00b275b0(local_60);
  local_40 = FUN_00b275d5(&local_68,&local_50);
  local_48 = FUN_00b11942(local_60,local_28);
  local_20 = local_48;
  uVar1 = FUN_00b12e20(param_3);
                    /* try { // try from 00b27205 to 00b2727c has its CatchHandler @ 00b272fc */
  FUN_00b270e6(local_60,local_40 * 0x20 + local_48,uVar1);
  local_20 = 0;
  uVar1 = FUN_00b0f7ea(local_60);
  puVar2 = (undefined8 *)FUN_00b27616(&local_68);
  local_20 = FUN_00b27624(local_30,*puVar2,local_48,uVar1);
  local_20 = local_20 + 0x20;
  uVar1 = FUN_00b0f7ea(local_60);
  puVar2 = (undefined8 *)FUN_00b27616(&local_68);
  local_20 = FUN_00b27624(*puVar2,local_38,local_20,uVar1);
  uVar1 = FUN_00b0f7ea(local_60);
  FUN_00b0f7f8(local_30,local_38,uVar1);
  FUN_00b1087a(local_60,local_30,local_60[2] - local_30 >> 5);
  *local_60 = local_48;
  local_60[1] = local_20;
  local_60[2] = local_28 * 0x20 + local_48;
  return;
}


// ==== entry=00b27386 name=FUN_00b27386 size=62 ====

void FUN_00b27386(undefined8 *param_1)

{
  FUN_00b26f6c(param_1);
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  return;
}


// ==== entry=00b273c4 name=FUN_00b273c4 size=150 ====

void FUN_00b273c4(long *param_1,undefined8 param_2,undefined8 param_3)

{
  long lVar1;
  long lVar2;
  undefined8 uVar3;
  
  lVar1 = FUN_00b2769e(param_2,param_3);
  lVar2 = FUN_00b11942(param_1,lVar1);
  *param_1 = lVar2;
  param_1[2] = lVar1 * 0x20 + *param_1;
  uVar3 = FUN_00b0f7ea(param_1);
  lVar1 = FUN_00b276d0(param_2,param_3,*param_1,uVar3);
  param_1[1] = lVar1;
  return;
}


// ==== entry=00b2745a name=FUN_00b2745a size=84 ====

void FUN_00b2745a(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  undefined8 uVar1;
  undefined8 uVar2;
  
  uVar1 = FUN_00b12e20(param_3);
  uVar2 = FUN_00b00efa(0x20,param_2);
                    /* try { // try from 00b2749c to 00b274a0 has its CatchHandler @ 00b274a3 */
  FUN_00b0d9b4(uVar2,uVar1);
  return;
}


// ==== entry=00b274c8 name=FUN_00b274c8 size=29 ====

void FUN_00b274c8(undefined8 *param_1,undefined8 *param_2)

{
  *param_1 = *param_2;
  return;
}


// ==== entry=00b274e6 name=FUN_00b274e6 size=201 ====

ulong FUN_00b274e6(undefined8 param_1,ulong param_2,char *param_3)

{
  long lVar1;
  long lVar2;
  long *plVar3;
  ulong uVar4;
  ulong local_38;
  undefined8 local_30;
  undefined8 local_28;
  ulong local_20;
  
  local_38 = param_2;
  local_30 = param_1;
  lVar1 = FUN_00b27702(param_1);
  lVar2 = FUN_00b0f822(local_30);
  if (local_38 <= (ulong)(lVar1 - lVar2)) {
    lVar1 = FUN_00b0f822(local_30);
    local_28 = FUN_00b0f822(local_30);
    plVar3 = (long *)FUN_00b06d34(&local_28,&local_38);
    local_20 = *plVar3 + lVar1;
    uVar4 = FUN_00b0f822(local_30);
    if ((local_20 < uVar4) || (uVar4 = FUN_00b27702(local_30), uVar4 < local_20)) {
      local_20 = FUN_00b27702(local_30);
    }
    return local_20;
  }
                    /* WARNING: Subroutine does not return */
  std::__throw_length_error(param_3);
}


// ==== entry=00b275b0 name=FUN_00b275b0 size=37 ====

undefined8 FUN_00b275b0(undefined8 param_1)

{
  undefined8 local_10;
  
  FUN_00b274c8(&local_10,param_1);
  return local_10;
}


// ==== entry=00b275d5 name=FUN_00b275d5 size=64 ====

long FUN_00b275d5(undefined8 param_1,undefined8 param_2)

{
  long lVar1;
  long *plVar2;
  
  plVar2 = (long *)FUN_00b27616(param_1);
  lVar1 = *plVar2;
  plVar2 = (long *)FUN_00b27616(param_2);
  return lVar1 - *plVar2 >> 5;
}


// ==== entry=00b27616 name=FUN_00b27616 size=14 ====

undefined8 FUN_00b27616(undefined8 param_1)

{
  return param_1;
}


// ==== entry=00b27624 name=FUN_00b27624 size=84 ====

void FUN_00b27624(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 uVar1;
  undefined8 uVar2;
  
  uVar1 = FUN_00b27724(param_2);
  uVar2 = FUN_00b27724(param_1);
  FUN_00b27732(uVar2,uVar1,param_3,param_4);
  return;
}


// ==== entry=00b27678 name=FUN_00b27678 size=38 ====

void FUN_00b27678(undefined8 param_1,undefined8 param_2)

{
  FUN_00b27764(param_1,param_2);
  return;
}


// ==== entry=00b2769e name=FUN_00b2769e size=50 ====

void FUN_00b2769e(undefined8 param_1,undefined8 param_2)

{
  undefined8 local_20 [3];
  
  local_20[0] = param_1;
  FUN_00b00902(local_20);
  FUN_00b27783(local_20[0],param_2);
  return;
}


// ==== entry=00b276d0 name=FUN_00b276d0 size=49 ====

void FUN_00b276d0(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  FUN_00b277a8(param_1,param_2,param_3);
  return;
}


// ==== entry=00b27702 name=FUN_00b27702 size=34 ====

void FUN_00b27702(undefined8 param_1)

{
  undefined8 uVar1;
  
  uVar1 = FUN_00b0f86e(param_1);
  FUN_00b277d9(uVar1);
  return;
}


// ==== entry=00b27724 name=FUN_00b27724 size=14 ====

undefined8 FUN_00b27724(undefined8 param_1)

{
  return param_1;
}


// ==== entry=00b27732 name=FUN_00b27732 size=49 ====

void FUN_00b27732(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  FUN_00b277f3(param_1,param_2,param_3);
  return;
}


// ==== entry=00b27764 name=FUN_00b27764 size=31 ====

void FUN_00b27764(undefined8 param_1,undefined8 param_2)

{
  FUN_00b0d994(param_2);
  return;
}


// ==== entry=00b27783 name=FUN_00b27783 size=37 ====

void FUN_00b27783(undefined8 param_1,undefined8 param_2)

{
  undefined8 local_18;
  undefined8 local_10;
  
  local_18 = param_2;
  local_10 = param_1;
  FUN_00b0091a(&local_18,&local_10);
  return;
}


// ==== entry=00b277a8 name=FUN_00b277a8 size=49 ====

void FUN_00b277a8(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  FUN_00b27824(param_1,param_2,param_3);
  return;
}


// ==== entry=00b277d9 name=FUN_00b277d9 size=26 ====

void FUN_00b277d9(undefined8 param_1)

{
  FUN_00b14556(param_1);
  return;
}


// ==== entry=00b277f3 name=FUN_00b277f3 size=49 ====

void FUN_00b277f3(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  FUN_00b2789c(param_1,param_2,param_3);
  return;
}


// ==== entry=00b27824 name=FUN_00b27824 size=120 ====

long FUN_00b27824(undefined8 param_1,undefined8 param_2,long param_3)

{
  char cVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 local_38;
  undefined8 local_30 [2];
  long local_20;
  
  local_38 = param_2;
  local_30[0] = param_1;
  local_20 = param_3;
  while( true ) {
    cVar1 = FUN_00b2792d(local_30,&local_38);
    if (cVar1 == '\0') break;
    uVar2 = FUN_00b00976(local_30);
    uVar3 = FUN_00b118ec(local_20);
    FUN_00b27977(uVar3,uVar2);
    FUN_00b00956(local_30);
    local_20 = local_20 + 0x20;
  }
  return local_20;
}


// ==== entry=00b2789c name=FUN_00b2789c size=94 ====

long FUN_00b2789c(long param_1,long param_2,long param_3)

{
  undefined8 uVar1;
  undefined8 local_30;
  undefined8 local_20;
  
  local_20 = param_3;
  for (local_30 = param_1; local_30 != param_2; local_30 = local_30 + 0x20) {
    uVar1 = FUN_00b118ec(local_20);
                    /* try { // try from 00b278dc to 00b278e0 has its CatchHandler @ 00b278f3 */
    FUN_00b12e2e(uVar1,local_30);
    local_20 = local_20 + 0x20;
  }
  return local_20;
}


// ==== entry=00b2792d name=FUN_00b2792d size=60 ====

undefined8 FUN_00b2792d(undefined8 param_1,undefined8 param_2)

{
  long lVar1;
  long *plVar2;
  
  plVar2 = (long *)FUN_00b0090c(param_1);
  lVar1 = *plVar2;
  plVar2 = (long *)FUN_00b0090c(param_2);
  return CONCAT71((int7)((ulong)*plVar2 >> 8),lVar1 != *plVar2);
}


// ==== entry=00b27969 name=FUN_00b27969 size=14 ====

undefined8 FUN_00b27969(undefined8 param_1)

{
  return param_1;
}


// ==== entry=00b27977 name=FUN_00b27977 size=70 ====

void FUN_00b27977(undefined8 param_1,undefined8 param_2)

{
  char cVar1;
  char *pcVar2;
  undefined8 uVar3;
  
  pcVar2 = (char *)FUN_00b27969(param_2);
  cVar1 = *pcVar2;
  uVar3 = FUN_00b00efa(0x20,param_1);
  FUN_00b26bfc(uVar3,(int)cVar1);
  return;
}


// ==== entry=00b279bd name=FUN_00b279bd size=3161 ====

string * FUN_00b279bd(string *param_1,undefined8 param_2,long *param_3)

{
  bool bVar1;
  char cVar2;
  int iVar3;
  long lVar4;
  undefined8 uVar5;
  undefined4 *puVar6;
  ulong uVar7;
  ulong uVar8;
  string local_c8 [11];
  allocator local_bd;
  undefined1 local_bc [12];
  string local_b0 [8];
  string local_a8 [15];
  allocator local_99;
  undefined1 local_98 [12];
  undefined4 local_8c;
  string local_88 [11];
  allocator local_7d;
  undefined1 local_7c [12];
  string local_70 [13];
  allocator local_63;
  char local_62;
  char local_61;
  int local_60;
  char local_59;
  ulong local_58;
  ulong local_50;
  ulong local_48;
  char local_39;
  ulong local_38;
  ulong local_30;
  char local_21;
  int local_20;
  char local_1c;
  char local_1b;
  char local_1a;
  char local_19;
  
  local_19 = '\0';
  local_1a = *(int *)((long)param_3 + 0x14) == 2;
  local_1b = '\0';
  local_1c = '\0';
  local_20 = 0;
  local_21 = '\0';
  local_30 = 0xffffffffffffffff;
  std::string::string(param_1);
  *(undefined1 *)(param_3 + 5) = 0;
  if (*param_3 == 0) {
                    /* try { // try from 00b27a3b to 00b27b16 has its CatchHandler @ 00b286d2 */
    lVar4 = FUN_00b28755();
    *param_3 = lVar4;
  }
LAB_00b27a4d:
  cVar2 = FUN_00b215d8(param_2);
  if (cVar2 != '\0') {
    local_38 = std::string::size(param_1);
    local_39 = '\0';
    do {
      cVar2 = FUN_00b0d930(*param_3,param_2);
      if (cVar2 == '\x01') {
LAB_00b27ac6:
        bVar1 = false;
      }
      else {
        uVar5 = FUN_00b0dbb2();
        cVar2 = FUN_00b0d930(uVar5,param_2);
        if (cVar2 == '\x01') goto LAB_00b27ac6;
        bVar1 = true;
      }
      if ((!bVar1) || (cVar2 = FUN_00b0d772(param_2), cVar2 != '\0')) goto LAB_00b27d64;
      iVar3 = FUN_00b0d7c0(param_2);
      if (iVar3 == 0) {
        uVar5 = FUN_00b287d6();
        cVar2 = FUN_00b0d930(uVar5,param_2);
        if (cVar2 == '\0') goto LAB_00b27b22;
        bVar1 = true;
      }
      else {
LAB_00b27b22:
        bVar1 = false;
      }
      if (bVar1) {
        if ((int)param_3[4] == 1) goto LAB_00b27d64;
        if ((int)param_3[4] == 2) {
          uVar5 = __cxa_allocate_exception(0x28);
          std::allocator<char>::allocator();
                    /* try { // try from 00b27b87 to 00b27b8b has its CatchHandler @ 00b28617 */
          std::string::string(local_c8,"illegal document indicator in scalar",&local_bd);
          local_bc = FUN_00b0d79a(param_2);
                    /* try { // try from 00b27bc7 to 00b27bcb has its CatchHandler @ 00b28603 */
          FUN_00b09fc4(uVar5,local_bc,local_c8);
          std::string::~string(local_c8);
          std::allocator<char>::~allocator((allocator<char> *)&local_bd);
                    /* WARNING: Subroutine does not return */
                    /* try { // try from 00b27bf7 to 00b27cbc has its CatchHandler @ 00b286d2 */
          __cxa_throw(uVar5,&PTR_PTR_00d39ce8,FUN_00b009e6);
        }
      }
      local_19 = '\x01';
      local_1a = '\x01';
      if (*(char *)((long)param_3 + 0x12) == '\\') {
        uVar5 = FUN_00b28870();
        cVar2 = FUN_00b0d930(uVar5,param_2);
        if (cVar2 == '\0') goto LAB_00b27c38;
        bVar1 = true;
      }
      else {
LAB_00b27c38:
        bVar1 = false;
      }
      if (bVar1) goto code_r0x00b27c41;
      cVar2 = FUN_00b21596(param_2);
      if (cVar2 == *(char *)((long)param_3 + 0x12)) {
        FUN_00b29e3b(local_b0,param_2);
                    /* try { // try from 00b27cd1 to 00b27cd5 has its CatchHandler @ 00b28639 */
        std::string::operator+=(param_1,local_b0);
        std::string::~string(local_b0);
        local_38 = std::string::size(param_1);
        local_30 = std::string::size(param_1);
      }
      else {
                    /* try { // try from 00b27d17 to 00b27d72 has its CatchHandler @ 00b286d2 */
        local_59 = FUN_00b21658(param_2);
        std::string::operator+=(param_1,local_59);
        if ((local_59 != ' ') && (local_59 != '\t')) {
          local_38 = std::string::size(param_1);
        }
      }
    } while( true );
  }
  goto LAB_00b283fc;
code_r0x00b27c41:
  FUN_00b21658(param_2);
  local_38 = std::string::size(param_1);
  local_30 = std::string::size(param_1);
  local_39 = '\x01';
LAB_00b27d64:
  cVar2 = FUN_00b0d772(param_2);
  if (cVar2 != '\0') {
    if ((char)param_3[1] != '\0') {
      uVar5 = __cxa_allocate_exception(0x28);
      std::allocator<char>::allocator();
                    /* try { // try from 00b27dc0 to 00b27dc4 has its CatchHandler @ 00b28664 */
      std::string::string(local_a8,"illegal EOF in scalar",&local_99);
      local_98 = FUN_00b0d79a(param_2);
                    /* try { // try from 00b27e00 to 00b27e04 has its CatchHandler @ 00b28650 */
      FUN_00b09fc4(uVar5,local_98,local_a8);
      std::string::~string(local_a8);
      std::allocator<char>::~allocator((allocator<char> *)&local_99);
                    /* WARNING: Subroutine does not return */
                    /* try { // try from 00b27e30 to 00b28057 has its CatchHandler @ 00b286d2 */
      __cxa_throw(uVar5,&PTR_PTR_00d39ce8,FUN_00b009e6);
    }
    goto LAB_00b283fc;
  }
  if (((int)param_3[4] == 1) && (iVar3 = FUN_00b0d7c0(param_2), iVar3 == 0)) {
    uVar5 = FUN_00b287d6();
    cVar2 = FUN_00b0d930(uVar5,param_2);
    if (cVar2 != '\0') {
      bVar1 = true;
      goto LAB_00b27e81;
    }
  }
  bVar1 = false;
LAB_00b27e81:
  if (bVar1) goto LAB_00b283fc;
  local_60 = FUN_00b0d95a(*param_3,param_2);
  if (-1 < local_60) {
    if ((char)param_3[1] != '\0') {
      FUN_00b2174c(param_2,local_60);
    }
    goto LAB_00b283fc;
  }
  if (*(int *)((long)param_3 + 0x14) == 2) {
    std::string::erase(param_1,local_38,0xffffffffffffffff);
  }
  uVar5 = FUN_00b0dbb2();
  local_60 = FUN_00b0d95a(uVar5,param_2);
  FUN_00b2174c(param_2,local_60);
  while( true ) {
    cVar2 = FUN_00b21596(param_2);
    if ((cVar2 == ' ') &&
       (((iVar3 = FUN_00b0d7c0(param_2), iVar3 < *(int *)((long)param_3 + 0xc) ||
         (((char)param_3[2] != '\0' && (local_19 != '\x01')))) &&
        (cVar2 = FUN_00b0d930(*param_3,param_2), cVar2 != '\x01')))) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if (!bVar1) break;
    FUN_00b2174c(param_2,1);
  }
  if (((char)param_3[2] != '\0') && (local_19 != '\x01')) {
    local_8c = FUN_00b0d7c0(param_2);
    puVar6 = (undefined4 *)FUN_00b2893c((long)param_3 + 0xc,&local_8c);
    *(undefined4 *)((long)param_3 + 0xc) = *puVar6;
  }
  while( true ) {
    uVar5 = FUN_00b0db18();
    cVar2 = FUN_00b0d930(uVar5,param_2);
    if (cVar2 == '\0') break;
    cVar2 = FUN_00b21596(param_2);
    if (((cVar2 == '\t') && (iVar3 = FUN_00b0d7c0(param_2), iVar3 < *(int *)((long)param_3 + 0xc)))
       && (*(int *)((long)param_3 + 0x24) == 2)) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if (bVar1) {
      uVar5 = __cxa_allocate_exception(0x28);
      std::allocator<char>::allocator();
                    /* try { // try from 00b280c7 to 00b280cb has its CatchHandler @ 00b28694 */
      std::string::string(local_88,"illegal tab when looking for indentation",&local_7d);
      local_7c = FUN_00b0d79a(param_2);
                    /* try { // try from 00b280f8 to 00b280fc has its CatchHandler @ 00b28683 */
      FUN_00b09fc4(uVar5,local_7c,local_88);
      std::string::~string(local_88);
      std::allocator<char>::~allocator((allocator<char> *)&local_7d);
                    /* WARNING: Subroutine does not return */
                    /* try { // try from 00b28122 to 00b282a5 has its CatchHandler @ 00b286d2 */
      __cxa_throw(uVar5,&PTR_PTR_00d39ce8,FUN_00b009e6);
    }
    if ((*(char *)((long)param_3 + 0x11) != '\x01') ||
       (cVar2 = FUN_00b0d930(*param_3,param_2), cVar2 != '\0')) break;
    FUN_00b2174c(param_2,1);
  }
  uVar5 = FUN_00b0dbb2();
  local_61 = FUN_00b0d930(uVar5,param_2);
  uVar5 = FUN_00b0db18();
  local_62 = FUN_00b0d930(uVar5,param_2);
  if ((*(int *)((long)param_3 + 0x14) == 1) && ((local_20 == 0 && (local_61 != '\0')))) {
    local_21 = local_1c;
  }
  if (local_1a != '\0') {
    iVar3 = *(int *)((long)param_3 + 0x14);
    if (iVar3 == 1) {
      if ((((local_1b == '\x01') || (local_61 == '\x01')) || (local_1c == '\x01')) ||
         ((local_62 == '\x01' ||
          (iVar3 = FUN_00b0d7c0(param_2), iVar3 < *(int *)((long)param_3 + 0xc))))) {
        bVar1 = false;
      }
      else {
        bVar1 = true;
      }
      if (bVar1) {
        std::string::operator+=(param_1," ");
      }
      else if (local_61 == '\0') {
        std::string::operator+=(param_1,"\n");
      }
      else {
        local_20 = local_20 + 1;
      }
      if ((local_61 != '\x01') && (0 < local_20)) {
        std::allocator<char>::allocator();
                    /* try { // try from 00b282e7 to 00b282eb has its CatchHandler @ 00b286c1 */
        std::string::string(local_70,(long)(local_20 + -1),'\n',&local_63);
                    /* try { // try from 00b282fd to 00b28301 has its CatchHandler @ 00b286b0 */
        std::string::operator+=(param_1,local_70);
        std::string::~string(local_70);
        std::allocator<char>::~allocator((allocator<char> *)&local_63);
        if ((local_21 != '\0') || (local_19 != '\x01' || local_62 != '\0')) {
                    /* try { // try from 00b2833d to 00b285ee has its CatchHandler @ 00b286d2 */
          std::string::operator+=(param_1,"\n");
        }
        local_20 = 0;
      }
    }
    else if (iVar3 == 2) {
      if (local_61 == '\0') {
        if ((local_1b != '\x01') && (local_39 != '\x01')) {
          std::string::operator+=(param_1," ");
        }
      }
      else {
        std::string::operator+=(param_1,"\n");
      }
    }
    else if (iVar3 == 0) {
      std::string::operator+=(param_1,"\n");
    }
  }
  local_1b = local_61;
  local_1c = local_62;
  local_1a = '\x01';
  if ((local_61 == '\x01') ||
     (iVar3 = FUN_00b0d7c0(param_2), *(int *)((long)param_3 + 0xc) <= iVar3)) {
    bVar1 = false;
  }
  else {
    bVar1 = true;
  }
  if (bVar1) {
    *(undefined1 *)(param_3 + 5) = 1;
LAB_00b283fc:
    if ((char)param_3[3] != '\0') {
      local_48 = std::string::find_last_not_of(param_1," \t",0xffffffffffffffff);
      if ((local_30 != 0xffffffffffffffff) &&
         ((local_48 < local_30 || (local_48 == 0xffffffffffffffff)))) {
        local_48 = local_30;
      }
      uVar7 = std::string::size(param_1);
      if (local_48 < uVar7) {
        std::string::erase(param_1,local_48 + 1,0xffffffffffffffff);
      }
    }
    if (*(int *)((long)param_3 + 0x1c) == -1) {
      local_58 = std::string::find_last_not_of(param_1,'\n',0xffffffffffffffff);
      if ((local_30 != 0xffffffffffffffff) &&
         ((local_58 < local_30 || (local_58 == 0xffffffffffffffff)))) {
        local_58 = local_30;
      }
      if (local_58 == 0xffffffffffffffff) {
        std::string::erase(param_1,0,0xffffffffffffffff);
      }
      else {
        uVar7 = std::string::size(param_1);
        if (local_58 < uVar7) {
          std::string::erase(param_1,local_58 + 1,0xffffffffffffffff);
        }
      }
    }
    else if (*(int *)((long)param_3 + 0x1c) == 0) {
      local_50 = std::string::find_last_not_of(param_1,'\n',0xffffffffffffffff);
      if ((local_30 != 0xffffffffffffffff) &&
         ((local_50 < local_30 || (local_50 == 0xffffffffffffffff)))) {
        local_50 = local_30;
      }
      if (local_50 == 0xffffffffffffffff) {
        std::string::erase(param_1,0,0xffffffffffffffff);
      }
      else {
        uVar7 = local_50 + 1;
        uVar8 = std::string::size(param_1);
        if (uVar7 < uVar8) {
          std::string::erase(param_1,local_50 + 2,0xffffffffffffffff);
        }
      }
    }
    return param_1;
  }
  goto LAB_00b27a4d;
}


// ==== entry=00b28702 name=FUN_00b28702 size=62 ====

void FUN_00b28702(int param_1,int param_2)

{
  if ((param_1 == 1) && (param_2 == 0xffff)) {
    std::ios_base::Init::Init((Init *)&DAT_011c35c2);
    __cxa_atexit(std::ios_base::Init::~Init,&DAT_011c35c2,&DAT_00c89008);
  }
  return;
}


// ==== entry=00b28740 orig=FUN_00b28740 size=21 name=_INIT_178 ====

void _INIT_178(void)

{
  FUN_00b28702(1,0xffff);
  return;
}


// ==== entry=00b28755 name=FUN_00b28755 size=100 ====

undefined * FUN_00b28755(void)

{
  int iVar1;
  
  if (DAT_011c3600 == '\0') {
    iVar1 = __cxa_guard_acquire(&DAT_011c3600);
    if (iVar1 != 0) {
                    /* try { // try from 00b2878a to 00b2878e has its CatchHandler @ 00b287b4 */
      FUN_00b26bdc(&DAT_011c35e0);
      __cxa_guard_release(&DAT_011c3600);
      __cxa_atexit(FUN_00b0d994,&DAT_011c35e0,&DAT_00c89008);
    }
  }
  return &DAT_011c35e0;
}


// ==== entry=00b287d6 name=FUN_00b287d6 size=125 ====

undefined * FUN_00b287d6(void)

{
  int iVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  
  if (DAT_011c3640 == '\0') {
    iVar1 = __cxa_guard_acquire(&DAT_011c3640);
    if (iVar1 != 0) {
                    /* try { // try from 00b28806 to 00b28828 has its CatchHandler @ 00b2884e */
      uVar2 = FUN_00b0df2f();
      uVar3 = FUN_00b0dda4();
      FUN_00b26d8c(&DAT_011c3620,uVar3,uVar2);
      __cxa_guard_release(&DAT_011c3640);
      __cxa_atexit(FUN_00b0d994,&DAT_011c3620,&DAT_00c89008);
    }
  }
  return &DAT_011c3620;
}


// ==== entry=00b28870 name=FUN_00b28870 size=158 ====

undefined * FUN_00b28870(void)

{
  int iVar1;
  undefined8 uVar2;
  undefined1 local_38 [32];
  
  if (DAT_011c3680 == '\0') {
    iVar1 = __cxa_guard_acquire(&DAT_011c3680);
    if (iVar1 != 0) {
                    /* try { // try from 00b288a4 to 00b288bc has its CatchHandler @ 00b28916 */
      uVar2 = FUN_00b0dbb2();
      FUN_00b26bfc(local_38,0x5c);
                    /* try { // try from 00b288cf to 00b288d3 has its CatchHandler @ 00b28905 */
      FUN_00b26e82(&DAT_011c3660,local_38,uVar2);
      __cxa_guard_release(&DAT_011c3680);
      __cxa_atexit(FUN_00b0d994,&DAT_011c3660,&DAT_00c89008);
      FUN_00b0d994(local_38);
    }
  }
  return &DAT_011c3660;
}


// ==== entry=00b2893c name=FUN_00b2893c size=40 ====

int * FUN_00b2893c(int *param_1,int *param_2)

{
  if (*param_1 < *param_2) {
    param_1 = param_2;
  }
  return param_1;
}


// ==== entry=00b28964 name=FUN_00b28964 size=339 ====

string * FUN_00b28964(string *param_1,undefined8 param_2)

{
  char cVar1;
  undefined8 uVar2;
  string local_40 [8];
  string local_38 [15];
  allocator local_29;
  undefined1 local_28 [12];
  int local_1c;
  
  std::string::string(param_1);
                    /* try { // try from 00b2898a to 00b289fe has its CatchHandler @ 00b28ae8 */
  FUN_00b21658(param_2);
  while( true ) {
    cVar1 = FUN_00b215d8(param_2);
    if (cVar1 == '\0') break;
    cVar1 = FUN_00b21596(param_2);
    if (cVar1 == '>') {
      FUN_00b21658(param_2);
      return param_1;
    }
    uVar2 = FUN_00b29293();
    local_1c = FUN_00b0d95a(uVar2,param_2);
    if (local_1c < 1) break;
    FUN_00b216b8(local_40,param_2,local_1c);
                    /* try { // try from 00b28a0d to 00b28a11 has its CatchHandler @ 00b28aaa */
    std::string::operator+=(param_1,local_40);
    std::string::~string(local_40);
  }
  uVar2 = __cxa_allocate_exception(0x28);
  std::allocator<char>::allocator();
                    /* try { // try from 00b28a4d to 00b28a51 has its CatchHandler @ 00b28acc */
  std::string::string(local_38,"end of verbatim tag not found",&local_29);
  local_28 = FUN_00b0d79a(param_2);
                    /* try { // try from 00b28a7b to 00b28a7f has its CatchHandler @ 00b28abb */
  FUN_00b09fc4(uVar2,local_28,local_38);
  std::string::~string(local_38);
  std::allocator<char>::~allocator((allocator<char> *)&local_29);
                    /* WARNING: Subroutine does not return */
                    /* try { // try from 00b28aa5 to 00b28aa9 has its CatchHandler @ 00b28ae8 */
  __cxa_throw(uVar2,&PTR_PTR_00d39ce8,FUN_00b009e6);
}


// ==== entry=00b28b0f name=FUN_00b28b0f size=429 ====

string * FUN_00b28b0f(string *param_1,undefined8 param_2,char *param_3)

{
  char cVar1;
  undefined8 uVar2;
  undefined1 auVar3 [12];
  undefined1 local_44 [12];
  string local_38 [15];
  allocator local_29;
  string local_28 [12];
  int local_1c;
  
  std::string::string(param_1);
  *param_3 = '\x01';
  FUN_00b21dd2(local_44);
  while( true ) {
                    /* try { // try from 00b28b4c to 00b28b64 has its CatchHandler @ 00b28cec */
    cVar1 = FUN_00b215d8(param_2);
    if (cVar1 == '\0') {
      return param_1;
    }
    cVar1 = FUN_00b21596(param_2);
    if (cVar1 == '!') break;
    local_1c = 0;
    auVar3 = local_44;
    if (*param_3 != '\0') {
      uVar2 = FUN_00b2908d();
      local_1c = FUN_00b0d95a(uVar2,param_2);
      auVar3 = local_44;
      if (local_1c < 1) {
        *param_3 = '\0';
        auVar3 = FUN_00b0d79a(param_2);
      }
    }
    local_44 = auVar3;
    if (*param_3 != '\x01') {
      uVar2 = FUN_00b294ca();
      local_1c = FUN_00b0d95a(uVar2,param_2);
    }
    if (local_1c < 1) {
      return param_1;
    }
    FUN_00b216b8(local_28,param_2,local_1c);
                    /* try { // try from 00b28c91 to 00b28c95 has its CatchHandler @ 00b28cdb */
    std::string::operator+=(param_1,local_28);
    std::string::~string(local_28);
  }
  if (*param_3 == '\x01') {
    return param_1;
  }
  uVar2 = __cxa_allocate_exception(0x28);
  std::allocator<char>::allocator();
                    /* try { // try from 00b28ba9 to 00b28bad has its CatchHandler @ 00b28cbf */
  std::string::string(local_38,"illegal character found while scanning tag handle",&local_29);
                    /* try { // try from 00b28bbc to 00b28bc0 has its CatchHandler @ 00b28cae */
  FUN_00b09fc4(uVar2,local_44,local_38);
  std::string::~string(local_38);
  std::allocator<char>::~allocator((allocator<char> *)&local_29);
                    /* WARNING: Subroutine does not return */
                    /* try { // try from 00b28be6 to 00b28c82 has its CatchHandler @ 00b28cec */
  __cxa_throw(uVar2,&PTR_PTR_00d39ce8,FUN_00b009e6);
}


// ==== entry=00b28d14 name=FUN_00b28d14 size=303 ====

string * FUN_00b28d14(string *param_1,undefined8 param_2)

{
  char cVar1;
  undefined8 uVar2;
  string local_40 [8];
  string local_38 [15];
  allocator local_29;
  undefined1 local_28 [12];
  int local_1c;
  
  std::string::string(param_1);
  while( true ) {
                    /* try { // try from 00b28d3a to 00b28d78 has its CatchHandler @ 00b28e73 */
    cVar1 = FUN_00b215d8(param_2);
    if (cVar1 == '\0') break;
    uVar2 = FUN_00b294ca();
    local_1c = FUN_00b0d95a(uVar2,param_2);
    if (local_1c < 1) break;
    FUN_00b216b8(local_40,param_2,local_1c);
                    /* try { // try from 00b28d87 to 00b28d8b has its CatchHandler @ 00b28e35 */
    std::string::operator+=(param_1,local_40);
    std::string::~string(local_40);
  }
  cVar1 = std::string::empty(param_1);
  if (cVar1 != '\0') {
    uVar2 = __cxa_allocate_exception(0x28);
    std::allocator<char>::allocator();
                    /* try { // try from 00b28dd8 to 00b28ddc has its CatchHandler @ 00b28e57 */
    std::string::string(local_38,"tag handle with no suffix",&local_29);
    local_28 = FUN_00b0d79a(param_2);
                    /* try { // try from 00b28e06 to 00b28e0a has its CatchHandler @ 00b28e46 */
    FUN_00b09fc4(uVar2,local_28,local_38);
    std::string::~string(local_38);
    std::allocator<char>::~allocator((allocator<char> *)&local_29);
                    /* WARNING: Subroutine does not return */
                    /* try { // try from 00b28e30 to 00b28e34 has its CatchHandler @ 00b28e73 */
    __cxa_throw(uVar2,&PTR_PTR_00d39ce8,FUN_00b009e6);
  }
  return param_1;
}


// ==== entry=00b28e9b name=FUN_00b28e9b size=62 ====

void FUN_00b28e9b(int param_1,int param_2)

{
  if ((param_1 == 1) && (param_2 == 0xffff)) {
    std::ios_base::Init::Init((Init *)&DAT_011c3688);
    __cxa_atexit(std::ios_base::Init::~Init,&DAT_011c3688,&DAT_00c89008);
  }
  return;
}


// ==== entry=00b28ed9 orig=FUN_00b28ed9 size=21 name=_INIT_179 ====

void _INIT_179(void)

{
  FUN_00b28e9b(1,0xffff);
  return;
}


// ==== entry=00b28eee name=FUN_00b28eee size=198 ====

undefined * FUN_00b28eee(void)

{
  int iVar1;
  undefined1 local_58 [32];
  undefined1 local_38 [32];
  
  if (DAT_011c36c0 == '\0') {
    iVar1 = __cxa_guard_acquire(&DAT_011c36c0);
    if (iVar1 != 0) {
                    /* try { // try from 00b28f3b to 00b28f3f has its CatchHandler @ 00b28fcd */
      FUN_00b26c3e(local_58,0x41,0x5a);
                    /* try { // try from 00b28f51 to 00b28f55 has its CatchHandler @ 00b28fbc */
      FUN_00b26c3e(local_38,0x61,0x7a);
                    /* try { // try from 00b28f69 to 00b28f6d has its CatchHandler @ 00b28fab */
      FUN_00b26d8c(&DAT_011c36a0,local_38,local_58);
      __cxa_guard_release(&DAT_011c36c0);
      __cxa_atexit(FUN_00b0d994,&DAT_011c36a0,&DAT_00c89008);
      FUN_00b0d994(local_38);
      FUN_00b0d994(local_58);
    }
  }
  return &DAT_011c36a0;
}


// ==== entry=00b28ff3 name=FUN_00b28ff3 size=125 ====

undefined * FUN_00b28ff3(void)

{
  int iVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  
  if (DAT_011c3700 == '\0') {
    iVar1 = __cxa_guard_acquire(&DAT_011c3700);
    if (iVar1 != 0) {
                    /* try { // try from 00b29023 to 00b29045 has its CatchHandler @ 00b2906b */
      uVar2 = FUN_00b17eb6();
      uVar3 = FUN_00b28eee();
      FUN_00b26d8c(&DAT_011c36e0,uVar3,uVar2);
      __cxa_guard_release(&DAT_011c3700);
      __cxa_atexit(FUN_00b0d994,&DAT_011c36e0,&DAT_00c89008);
    }
  }
  return &DAT_011c36e0;
}


// ==== entry=00b2908d name=FUN_00b2908d size=155 ====

undefined * FUN_00b2908d(void)

{
  int iVar1;
  undefined8 uVar2;
  undefined1 local_38 [32];
  
  if (DAT_011c3740 == '\0') {
    iVar1 = __cxa_guard_acquire(&DAT_011c3740);
    if (iVar1 != 0) {
                    /* try { // try from 00b290cd to 00b290d1 has its CatchHandler @ 00b29130 */
      FUN_00b26bfc(local_38,0x2d);
                    /* try { // try from 00b290d2 to 00b290ed has its CatchHandler @ 00b2911f */
      uVar2 = FUN_00b28ff3();
      FUN_00b26d8c(&DAT_011c3720,uVar2,local_38);
      __cxa_guard_release(&DAT_011c3740);
      __cxa_atexit(FUN_00b0d994,&DAT_011c3720,&DAT_00c89008);
      FUN_00b0d994(local_38);
    }
  }
  return &DAT_011c3720;
}


// ==== entry=00b29156 name=FUN_00b29156 size=237 ====

undefined * FUN_00b29156(void)

{
  int iVar1;
  undefined8 uVar2;
  undefined1 local_78 [32];
  undefined1 local_58 [32];
  undefined1 local_38 [32];
  
  if (DAT_011c3780 == '\0') {
    iVar1 = __cxa_guard_acquire(&DAT_011c3780);
    if (iVar1 != 0) {
                    /* try { // try from 00b291a3 to 00b291a7 has its CatchHandler @ 00b2926d */
      FUN_00b26c3e(local_78,0x61,0x66);
                    /* try { // try from 00b291b9 to 00b291bd has its CatchHandler @ 00b2925c */
      FUN_00b26c3e(local_38,0x41,0x46);
                    /* try { // try from 00b291be to 00b291d8 has its CatchHandler @ 00b2924b */
      uVar2 = FUN_00b17eb6();
      FUN_00b26d8c(local_58,uVar2,local_38);
                    /* try { // try from 00b291ec to 00b291f0 has its CatchHandler @ 00b2923a */
      FUN_00b26d8c(&DAT_011c3760,local_58,local_78);
      __cxa_guard_release(&DAT_011c3780);
      __cxa_atexit(FUN_00b0d994,&DAT_011c3760,&DAT_00c89008);
      FUN_00b0d994(local_58);
      FUN_00b0d994(local_38);
      FUN_00b0d994(local_78);
    }
  }
  return &DAT_011c3760;
}


// ==== entry=00b29293 name=FUN_00b29293 size=415 ====

undefined * FUN_00b29293(void)

{
  int iVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined1 local_d8 [32];
  undefined1 local_b8 [32];
  undefined1 local_98 [32];
  undefined1 local_78 [32];
  undefined1 local_58 [32];
  string local_38 [15];
  allocator local_29 [9];
  
  if (DAT_011c37c0 == '\0') {
    iVar1 = __cxa_guard_acquire(&DAT_011c37c0);
    if (iVar1 != 0) {
                    /* try { // try from 00b292d4 to 00b292f7 has its CatchHandler @ 00b2949f */
      uVar2 = FUN_00b29156();
      uVar3 = FUN_00b29156();
      FUN_00b26bfc(local_98,0x25);
                    /* try { // try from 00b2930f to 00b29313 has its CatchHandler @ 00b2948b */
      FUN_00b26e82(local_b8,local_98,uVar3);
                    /* try { // try from 00b2932b to 00b2932f has its CatchHandler @ 00b29477 */
      FUN_00b26e82(local_d8,local_b8,uVar2);
      std::allocator<char>::allocator();
                    /* try { // try from 00b2934c to 00b29350 has its CatchHandler @ 00b29457 */
      std::string::string(local_38,"#;/?:@&=+$,_.!~*\'()[]",local_29);
                    /* try { // try from 00b29364 to 00b29368 has its CatchHandler @ 00b29446 */
      FUN_00b26c88(local_58,local_38,3);
                    /* try { // try from 00b29369 to 00b29383 has its CatchHandler @ 00b29435 */
      uVar2 = FUN_00b2908d();
      FUN_00b26d8c(local_78,uVar2,local_58);
                    /* try { // try from 00b2939a to 00b2939e has its CatchHandler @ 00b29424 */
      FUN_00b26d8c(&DAT_011c37a0,local_78,local_d8);
      __cxa_guard_release(&DAT_011c37c0);
      __cxa_atexit(FUN_00b0d994,&DAT_011c37a0,&DAT_00c89008);
      FUN_00b0d994(local_78);
      FUN_00b0d994(local_58);
      std::string::~string(local_38);
      std::allocator<char>::~allocator((allocator<char> *)local_29);
      FUN_00b0d994(local_d8);
      FUN_00b0d994(local_b8);
      FUN_00b0d994(local_98);
    }
  }
  return &DAT_011c37a0;
}


// ==== entry=00b294ca name=FUN_00b294ca size=415 ====

undefined * FUN_00b294ca(void)

{
  int iVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined1 local_d8 [32];
  undefined1 local_b8 [32];
  undefined1 local_98 [32];
  undefined1 local_78 [32];
  undefined1 local_58 [32];
  string local_38 [15];
  allocator local_29 [9];
  
  if (DAT_011c3800 == '\0') {
    iVar1 = __cxa_guard_acquire(&DAT_011c3800);
    if (iVar1 != 0) {
                    /* try { // try from 00b2950b to 00b2952e has its CatchHandler @ 00b296d6 */
      uVar2 = FUN_00b29156();
      uVar3 = FUN_00b29156();
      FUN_00b26bfc(local_98,0x25);
                    /* try { // try from 00b29546 to 00b2954a has its CatchHandler @ 00b296c2 */
      FUN_00b26e82(local_b8,local_98,uVar3);
                    /* try { // try from 00b29562 to 00b29566 has its CatchHandler @ 00b296ae */
      FUN_00b26e82(local_d8,local_b8,uVar2);
      std::allocator<char>::allocator();
                    /* try { // try from 00b29583 to 00b29587 has its CatchHandler @ 00b2968e */
      std::string::string(local_38,"#;/?:@&=+$_.~*\'()",local_29);
                    /* try { // try from 00b2959b to 00b2959f has its CatchHandler @ 00b2967d */
      FUN_00b26c88(local_58,local_38,3);
                    /* try { // try from 00b295a0 to 00b295ba has its CatchHandler @ 00b2966c */
      uVar2 = FUN_00b2908d();
      FUN_00b26d8c(local_78,uVar2,local_58);
                    /* try { // try from 00b295d1 to 00b295d5 has its CatchHandler @ 00b2965b */
      FUN_00b26d8c(&DAT_011c37e0,local_78,local_d8);
      __cxa_guard_release(&DAT_011c3800);
      __cxa_atexit(FUN_00b0d994,&DAT_011c37e0,&DAT_00c89008);
      FUN_00b0d994(local_78);
      FUN_00b0d994(local_58);
      std::string::~string(local_38);
      std::allocator<char>::~allocator((allocator<char> *)local_29);
      FUN_00b0d994(local_d8);
      FUN_00b0d994(local_b8);
      FUN_00b0d994(local_98);
    }
  }
  return &DAT_011c37e0;
}


// ==== entry=00b29701 name=FUN_00b29701 size=350 ====

int FUN_00b29701(string *param_1,undefined8 param_2)

{
  char cVar1;
  char *pcVar2;
  undefined8 uVar3;
  undefined8 local_48;
  undefined8 local_40;
  string local_38 [14];
  allocator local_2a;
  char local_29;
  string *local_28;
  int local_20;
  int local_1c;
  
  local_1c = 0;
  local_28 = param_1;
  local_40 = std::string::begin(param_1);
  local_48 = std::string::end(local_28);
  do {
    cVar1 = FUN_00b2792d(&local_40,&local_48);
    if (cVar1 == '\0') {
      return local_1c;
    }
    pcVar2 = (char *)FUN_00b00976(&local_40);
    local_29 = *pcVar2;
    local_20 = 0;
    if ((local_29 < 'a') || ('f' < local_29)) {
      if ((local_29 < 'A') || ('F' < local_29)) {
        if ((local_29 < '0') || ('9' < local_29)) {
          uVar3 = __cxa_allocate_exception(0x28);
          std::allocator<char>::allocator();
                    /* try { // try from 00b297ee to 00b297f2 has its CatchHandler @ 00b29867 */
          std::string::string(local_38,"bad character found while scanning hex number",&local_2a);
                    /* try { // try from 00b29801 to 00b29805 has its CatchHandler @ 00b29856 */
          FUN_00b09fc4(uVar3,param_2,local_38);
          std::string::~string(local_38);
          std::allocator<char>::~allocator((allocator<char> *)&local_2a);
                    /* WARNING: Subroutine does not return */
          __cxa_throw(uVar3,&PTR_PTR_00d39ce8,FUN_00b009e6);
        }
        local_20 = local_29 + -0x30;
      }
      else {
        local_20 = local_29 + -0x37;
      }
    }
    else {
      local_20 = local_29 + -0x57;
    }
    local_1c = local_20 + local_1c * 0x10;
    FUN_00b00956(&local_40);
  } while( true );
}


// ==== entry=00b29892 name=FUN_00b29892 size=80 ====

string * FUN_00b29892(string *param_1,char param_2)

{
  allocator local_19 [9];
  
  std::allocator<char>::allocator();
                    /* try { // try from 00b298c4 to 00b298c8 has its CatchHandler @ 00b298d7 */
  std::string::string(param_1,1,param_2,local_19);
  std::allocator<char>::~allocator((allocator<char> *)local_19);
  return param_1;
}


// ==== entry=00b298fc name=FUN_00b298fc size=1048 ====

undefined8 FUN_00b298fc(undefined8 param_1,undefined8 param_2,int param_3)

{
  char cVar1;
  undefined4 uVar2;
  ostream *this;
  undefined8 uVar3;
  stringstream local_228 [16];
  ostream aoStack_218 [360];
  string local_b0 [12];
  undefined1 local_a4 [12];
  string local_98 [12];
  undefined1 local_8c [12];
  string local_80 [8];
  string local_78 [8];
  string local_70 [8];
  string local_68 [8];
  string local_60 [8];
  string local_58 [8];
  string local_50 [8];
  string local_48 [8];
  string local_40 [8];
  string local_38 [8];
  string local_30 [8];
  string local_28 [8];
  uint local_20;
  int local_1c;
  
  std::string::string(local_b0);
  for (local_1c = 0; local_1c < param_3; local_1c = local_1c + 1) {
                    /* try { // try from 00b29949 to 00b299eb has its CatchHandler @ 00b29e0b */
    cVar1 = FUN_00b21658(param_2);
    std::string::operator+=(local_b0,cVar1);
  }
  local_a4 = FUN_00b0d79a(param_2);
  local_20 = FUN_00b29701(local_b0,local_a4);
  if (((local_20 < 0xd800) || (0xdfff < local_20)) && (local_20 < 0x110000)) {
    if (local_20 < 0x80) {
                    /* try { // try from 00b29aaa to 00b29ad6 has its CatchHandler @ 00b29e0b */
      FUN_00b29892(param_1,local_20);
    }
    else if (local_20 < 0x800) {
      FUN_00b29892(local_80,(local_20 & 0x3f) + 0x80);
                    /* try { // try from 00b29aec to 00b29af0 has its CatchHandler @ 00b29d4d */
      FUN_00b29892(local_78,(local_20 >> 6) + 0xc0);
                    /* try { // try from 00b29b06 to 00b29b0a has its CatchHandler @ 00b29d3c */
      FUN_00b2a684(param_1,local_78,local_80);
      std::string::~string(local_78);
      std::string::~string(local_80);
    }
    else if (local_20 < 0x10000) {
                    /* try { // try from 00b29b4b to 00b29b4f has its CatchHandler @ 00b29e0b */
      FUN_00b29892(local_70,(local_20 & 0x3f) + 0x80);
                    /* try { // try from 00b29b68 to 00b29b6c has its CatchHandler @ 00b29d94 */
      FUN_00b29892(local_60,(local_20 >> 6 & 0x3f) + 0x80);
                    /* try { // try from 00b29b82 to 00b29b86 has its CatchHandler @ 00b29d83 */
      FUN_00b29892(local_58,(local_20 >> 0xc) + 0xe0);
                    /* try { // try from 00b29b99 to 00b29b9d has its CatchHandler @ 00b29d72 */
      FUN_00b2a684(local_68,local_58,local_60);
                    /* try { // try from 00b29bb3 to 00b29bb7 has its CatchHandler @ 00b29d61 */
      FUN_00b2a684(param_1,local_68,local_70);
      std::string::~string(local_68);
      std::string::~string(local_58);
      std::string::~string(local_60);
      std::string::~string(local_70);
    }
    else {
                    /* try { // try from 00b29c03 to 00b29c07 has its CatchHandler @ 00b29e0b */
      FUN_00b29892(local_50,(local_20 & 0x3f) + 0x80);
                    /* try { // try from 00b29c20 to 00b29c24 has its CatchHandler @ 00b29dfa */
      FUN_00b29892(local_40,(local_20 >> 6 & 0x3f) + 0x80);
                    /* try { // try from 00b29c3d to 00b29c41 has its CatchHandler @ 00b29de9 */
      FUN_00b29892(local_30,(local_20 >> 0xc & 0x3f) + 0x80);
                    /* try { // try from 00b29c57 to 00b29c5b has its CatchHandler @ 00b29dd8 */
      FUN_00b29892(local_28,(local_20 >> 0x12) + 0xf0);
                    /* try { // try from 00b29c6e to 00b29c72 has its CatchHandler @ 00b29dc7 */
      FUN_00b2a684(local_38,local_28,local_30);
                    /* try { // try from 00b29c85 to 00b29c89 has its CatchHandler @ 00b29db6 */
      FUN_00b2a684(local_48,local_38,local_40);
                    /* try { // try from 00b29c9f to 00b29ca3 has its CatchHandler @ 00b29da5 */
      FUN_00b2a684(param_1,local_48,local_50);
      std::string::~string(local_48);
      std::string::~string(local_38);
      std::string::~string(local_28);
      std::string::~string(local_30);
      std::string::~string(local_40);
      std::string::~string(local_50);
    }
    std::string::~string(local_b0);
    return param_1;
  }
  uVar2 = FUN_00b004d1(0x10,8);
  std::stringstream::stringstream(local_228,uVar2);
                    /* try { // try from 00b299ff to 00b29a13 has its CatchHandler @ 00b29d25 */
  this = std::operator<<(aoStack_218,"invalid unicode: ");
  std::ostream::operator<<(this,local_20);
  uVar3 = __cxa_allocate_exception(0x28);
                    /* try { // try from 00b29a35 to 00b29a39 has its CatchHandler @ 00b29d15 */
  std::stringstream::str();
  local_8c = FUN_00b0d79a(param_2);
                    /* try { // try from 00b29a6f to 00b29a73 has its CatchHandler @ 00b29d01 */
  FUN_00b09fc4(uVar3,local_8c,local_98);
  std::string::~string(local_98);
                    /* WARNING: Subroutine does not return */
                    /* try { // try from 00b29a90 to 00b29a94 has its CatchHandler @ 00b29d25 */
  __cxa_throw(uVar3,&PTR_PTR_00d39ce8,FUN_00b009e6);
}


// ==== entry=00b29e3b name=FUN_00b29e3b size=1453 ====

string * FUN_00b29e3b(string *param_1,undefined8 param_2)

{
  undefined4 uVar1;
  undefined8 uVar2;
  int iVar3;
  stringstream local_1c8 [373];
  allocator local_53;
  allocator local_52;
  allocator local_51;
  allocator local_50;
  allocator local_4f;
  allocator local_4e;
  allocator local_4d;
  allocator local_4c;
  allocator local_4b;
  allocator local_4a;
  allocator local_49;
  allocator local_48;
  allocator local_47;
  allocator local_46;
  allocator local_45;
  allocator local_44;
  allocator local_43;
  allocator local_42;
  allocator local_41;
  string local_40 [8];
  string local_38 [15];
  allocator local_29;
  undefined1 local_28 [12];
  char local_1a;
  char local_19;
  
  local_19 = FUN_00b21658(param_2);
  local_1a = FUN_00b21658(param_2);
  if ((local_19 == '\'') && (local_1a == '\'')) {
    std::allocator<char>::allocator();
                    /* try { // try from 00b29ea6 to 00b29eaa has its CatchHandler @ 00b2a3d5 */
    std::string::string(param_1,"\'",&local_53);
    std::allocator<char>::~allocator((allocator<char> *)&local_53);
  }
  else {
    switch(local_1a) {
    case '\t':
    case 't':
      std::allocator<char>::allocator();
                    /* try { // try from 00b29f9e to 00b29fa2 has its CatchHandler @ 00b2a43d */
      std::string::string(param_1,"\t",&local_4f);
      std::allocator<char>::~allocator((allocator<char> *)&local_4f);
      break;
    default:
      uVar1 = FUN_00b004d1(0x10,8);
      std::stringstream::stringstream(local_1c8,uVar1);
      uVar2 = __cxa_allocate_exception(0x28);
      iVar3 = (int)local_1a;
      std::allocator<char>::allocator();
                    /* try { // try from 00b2a353 to 00b2a357 has its CatchHandler @ 00b2a5e5 */
      std::string::string(local_38,"unknown escape character: ",&local_29);
                    /* try { // try from 00b2a369 to 00b2a36d has its CatchHandler @ 00b2a5d4 */
      FUN_00b2a74e(local_40,local_38,iVar3);
      local_28 = FUN_00b0d79a(param_2);
                    /* try { // try from 00b2a39a to 00b2a39e has its CatchHandler @ 00b2a5c3 */
      FUN_00b09fc4(uVar2,local_28,local_40);
      std::string::~string(local_40);
      std::string::~string(local_38);
      std::allocator<char>::~allocator((allocator<char> *)&local_29);
                    /* WARNING: Subroutine does not return */
                    /* try { // try from 00b2a3d0 to 00b2a3d4 has its CatchHandler @ 00b2a601 */
      __cxa_throw(uVar2,&PTR_PTR_00d39ce8,FUN_00b009e6);
    case ' ':
      std::allocator<char>::allocator();
                    /* try { // try from 00b2a0dc to 00b2a0e0 has its CatchHandler @ 00b2a4d9 */
      std::string::string(param_1," ",&local_49);
      std::allocator<char>::~allocator((allocator<char> *)&local_49);
      break;
    case '\"':
      std::allocator<char>::allocator();
                    /* try { // try from 00b2a111 to 00b2a115 has its CatchHandler @ 00b2a4f3 */
      std::string::string(param_1,"\"",&local_48);
      std::allocator<char>::~allocator((allocator<char> *)&local_48);
      break;
    case '\'':
      std::allocator<char>::allocator();
                    /* try { // try from 00b2a146 to 00b2a14a has its CatchHandler @ 00b2a50d */
      std::string::string(param_1,"\'",&local_47);
      std::allocator<char>::~allocator((allocator<char> *)&local_47);
      break;
    case '/':
      std::allocator<char>::allocator();
                    /* try { // try from 00b2a1b0 to 00b2a1b4 has its CatchHandler @ 00b2a541 */
      std::string::string(param_1,"/",&local_45);
      std::allocator<char>::~allocator((allocator<char> *)&local_45);
      break;
    case '0':
      std::allocator<char>::allocator();
                    /* try { // try from 00b29eff to 00b29f03 has its CatchHandler @ 00b2a3ef */
      std::string::string(param_1,1,'\0',&local_52);
      std::allocator<char>::~allocator((allocator<char> *)&local_52);
      break;
    case 'L':
      std::allocator<char>::allocator();
                    /* try { // try from 00b2a24f to 00b2a253 has its CatchHandler @ 00b2a58f */
      std::string::string(param_1,&DAT_00d411ec,&local_42);
      std::allocator<char>::~allocator((allocator<char> *)&local_42);
      break;
    case 'N':
      std::allocator<char>::allocator();
                    /* try { // try from 00b2a1e5 to 00b2a1e9 has its CatchHandler @ 00b2a55b */
      std::string::string(param_1,&DAT_00d411e8,&local_44);
      std::allocator<char>::~allocator((allocator<char> *)&local_44);
      break;
    case 'P':
      std::allocator<char>::allocator();
                    /* try { // try from 00b2a284 to 00b2a288 has its CatchHandler @ 00b2a5a9 */
      std::string::string(param_1,&DAT_00d411f0,&local_41);
      std::allocator<char>::~allocator((allocator<char> *)&local_41);
      break;
    case 'U':
      FUN_00b298fc(param_1,param_2,8);
      break;
    case '\\':
      std::allocator<char>::allocator();
                    /* try { // try from 00b2a17b to 00b2a17f has its CatchHandler @ 00b2a527 */
      std::string::string(param_1,"\\",&local_46);
      std::allocator<char>::~allocator((allocator<char> *)&local_46);
      break;
    case '_':
      std::allocator<char>::allocator();
                    /* try { // try from 00b2a21a to 00b2a21e has its CatchHandler @ 00b2a575 */
      std::string::string(param_1,&DAT_00d411ea,&local_43);
      std::allocator<char>::~allocator((allocator<char> *)&local_43);
      break;
    case 'a':
      std::allocator<char>::allocator();
                    /* try { // try from 00b29f34 to 00b29f38 has its CatchHandler @ 00b2a409 */
      std::string::string(param_1,"\a",&local_51);
      std::allocator<char>::~allocator((allocator<char> *)&local_51);
      break;
    case 'b':
      std::allocator<char>::allocator();
                    /* try { // try from 00b29f69 to 00b29f6d has its CatchHandler @ 00b2a423 */
      std::string::string(param_1,"\b",&local_50);
      std::allocator<char>::~allocator((allocator<char> *)&local_50);
      break;
    case 'e':
      std::allocator<char>::allocator();
                    /* try { // try from 00b2a0a7 to 00b2a0ab has its CatchHandler @ 00b2a4bf */
      std::string::string(param_1,"\x1b",&local_4a);
      std::allocator<char>::~allocator((allocator<char> *)&local_4a);
      break;
    case 'f':
      std::allocator<char>::allocator();
                    /* try { // try from 00b2a03d to 00b2a041 has its CatchHandler @ 00b2a48b */
      std::string::string(param_1,"\f",&local_4c);
      std::allocator<char>::~allocator((allocator<char> *)&local_4c);
      break;
    case 'n':
      std::allocator<char>::allocator();
                    /* try { // try from 00b29fd3 to 00b29fd7 has its CatchHandler @ 00b2a457 */
      std::string::string(param_1,"\n",&local_4e);
      std::allocator<char>::~allocator((allocator<char> *)&local_4e);
      break;
    case 'r':
      std::allocator<char>::allocator();
                    /* try { // try from 00b2a072 to 00b2a076 has its CatchHandler @ 00b2a4a5 */
      std::string::string(param_1,"\r",&local_4b);
      std::allocator<char>::~allocator((allocator<char> *)&local_4b);
      break;
    case 'u':
      FUN_00b298fc(param_1,param_2,4);
      break;
    case 'v':
      std::allocator<char>::allocator();
                    /* try { // try from 00b2a008 to 00b2a00c has its CatchHandler @ 00b2a471 */
      std::string::string(param_1,"\v",&local_4d);
      std::allocator<char>::~allocator((allocator<char> *)&local_4d);
      break;
    case 'x':
      FUN_00b298fc(param_1,param_2,2);
    }
  }
  return param_1;
}


// ==== entry=00b2a631 name=FUN_00b2a631 size=62 ====

void FUN_00b2a631(int param_1,int param_2)

{
  if ((param_1 == 1) && (param_2 == 0xffff)) {
    std::ios_base::Init::Init((Init *)&DAT_011c3808);
    __cxa_atexit(std::ios_base::Init::~Init,&DAT_011c3808,&DAT_00c89008);
  }
  return;
}


// ==== entry=00b2a66f orig=FUN_00b2a66f size=21 name=_INIT_180 ====

void _INIT_180(void)

{
  FUN_00b2a631(1,0xffff);
  return;
}


// ==== entry=00b2a684 name=FUN_00b2a684 size=202 ====

string * FUN_00b2a684(string *param_1,string *param_2,string *param_3)

{
  bool bVar1;
  long lVar2;
  long lVar3;
  ulong uVar4;
  undefined8 uVar5;
  string *psVar6;
  
  lVar2 = std::string::size(param_2);
  lVar3 = std::string::size(param_3);
  uVar4 = std::string::capacity(param_2);
  if (uVar4 < (ulong)(lVar3 + lVar2)) {
    uVar4 = std::string::capacity(param_3);
    if ((ulong)(lVar3 + lVar2) <= uVar4) {
      bVar1 = true;
      goto LAB_00b2a6eb;
    }
  }
  bVar1 = false;
LAB_00b2a6eb:
  if (bVar1) {
    uVar5 = std::string::insert(param_3,0,param_2);
    psVar6 = (string *)FUN_00b08141(uVar5);
  }
  else {
    uVar5 = std::string::append(param_2,param_3);
    psVar6 = (string *)FUN_00b08141(uVar5);
  }
  std::string::string(param_1,psVar6);
  return param_1;
}


// ==== entry=00b2a74e name=FUN_00b2a74e size=74 ====

string * FUN_00b2a74e(string *param_1,string *param_2,char param_3)

{
  undefined8 uVar1;
  string *psVar2;
  
  uVar1 = std::string::append(param_2,1,param_3);
  psVar2 = (string *)FUN_00b08141(uVar1);
  std::string::string(param_1,psVar2);
  return param_1;
}


// ==== entry=00b2a7a0 name=FUN_00b2a7a0 size=947 ====

char * FUN_00b2a7a0(long param_1)

{
  char *pcVar1;
  
  pcVar1 = (char *)0x0;
  if (param_1 < 0) {
    if (param_1 == -0x79) {
      return "invalid POSIX bracket type";
    }
    if (param_1 < -0x78) {
      if (param_1 == -0xd6) {
        return "group name is empty";
      }
      if (param_1 < -0xd5) {
        if (param_1 == -0xde) {
          return "group number is too big for capture history";
        }
        if (param_1 < -0xdd) {
          if (param_1 == -0x192) {
            return "not supported encoding combination";
          }
          if (param_1 < -0x191) {
            pcVar1 = "over thread pass limit count";
            if (param_1 != -0x3e9) {
              pcVar1 = "invalid combination of options";
              if (param_1 != -0x193) {
                pcVar1 = "undefined error code";
              }
              return pcVar1;
            }
          }
          else {
            pcVar1 = "invalid code point value";
            if ((param_1 != -400) && (pcVar1 = "too big wide-char value", -0x191 < param_1)) {
              pcVar1 = "invalid character property name {%n}";
              if (param_1 != -0xdf) {
                pcVar1 = "undefined error code";
              }
              return pcVar1;
            }
          }
        }
        else {
          if (param_1 == -0xda) {
            return "undefined group <%n> reference";
          }
          if (param_1 < -0xd9) {
            pcVar1 = "multiplex definition name <%n> call";
            if (param_1 != -0xdc) {
              pcVar1 = "multiplex defined name <%n>";
              if (param_1 < -0xdb) {
                pcVar1 = "never ending recursion";
              }
              return pcVar1;
            }
          }
          else {
            pcVar1 = "invalid char in group name <%n>";
            if (param_1 != -0xd8) {
              pcVar1 = "invalid group name <%n>";
              if (param_1 < -0xd7) {
                pcVar1 = "undefined name <%n> reference";
              }
              return pcVar1;
            }
          }
        }
      }
      else {
        if (param_1 == -0xcc) {
          return "mismatch multibyte code length in char-class range";
        }
        if (param_1 < -0xcb) {
          if (param_1 == -0xd0) {
            return "invalid backref number/name";
          }
          if (param_1 < -0xcf) {
            pcVar1 = "too short digits";
            if ((param_1 != -0xd2) &&
               (pcVar1 = "numbered backref/call is not allowed. (use name)", param_1 < -0xd1)) {
              pcVar1 = "too long wide-char value";
              if (param_1 != -0xd4) {
                pcVar1 = "undefined error code";
              }
              return pcVar1;
            }
          }
          else {
            pcVar1 = "too short multibyte code string";
            if (param_1 != -0xce) {
              pcVar1 = "too many multibyte code ranges are specified";
              if (param_1 < -0xcd) {
                pcVar1 = "too big backref number";
              }
              return pcVar1;
            }
          }
        }
        else {
          if (param_1 == -200) {
            return "too big number";
          }
          if (param_1 < -199) {
            pcVar1 = "upper is smaller than lower in repeat range";
            if (param_1 != -0xca) {
              pcVar1 = "too big number for repeat range";
              if (param_1 < -0xc9) {
                pcVar1 = "empty range in char class";
              }
              return pcVar1;
            }
          }
          else {
            pcVar1 = "invalid repeat range {lower,upper}";
            if ((param_1 != -0x7b) && (pcVar1 = "invalid pattern in look-behind", param_1 < -0x7a))
            {
              pcVar1 = "invalid conditional pattern";
              if (param_1 != -0x7c) {
                pcVar1 = "undefined error code";
              }
              return pcVar1;
            }
          }
        }
      }
    }
    else {
      if (param_1 == -0x67) {
        return "premature end of char-class";
      }
      if (param_1 < -0x66) {
        if (param_1 == -0x70) {
          return "unmatched range specifier in char-class";
        }
        if (param_1 < -0x6f) {
          if (param_1 == -0x74) {
            return "unmatched close parenthesis";
          }
          if (param_1 < -0x73) {
            pcVar1 = "end pattern in group";
            if ((param_1 != -0x76) &&
               (pcVar1 = "end pattern with unmatched parenthesis", param_1 < -0x75)) {
              pcVar1 = "undefined group option";
              if (param_1 != -0x77) {
                pcVar1 = "undefined error code";
              }
              return pcVar1;
            }
          }
          else {
            pcVar1 = "target of repeat operator is invalid";
            if (param_1 != -0x72) {
              pcVar1 = "target of repeat operator is not specified";
              if (param_1 < -0x71) {
                pcVar1 = "nested repeat operator";
              }
              return pcVar1;
            }
          }
        }
        else {
          if (param_1 == -0x6c) {
            return "invalid meta-code syntax";
          }
          if (param_1 < -0x6b) {
            pcVar1 = "char-class value at end of range";
            if (param_1 != -0x6e) {
              pcVar1 = "invalid control-code syntax";
              if (param_1 < -0x6d) {
                pcVar1 = "char-class value at start of range";
              }
              return pcVar1;
            }
          }
          else {
            pcVar1 = "end pattern at meta";
            if ((param_1 != -0x69) && (pcVar1 = "end pattern at escape", param_1 < -0x68)) {
              pcVar1 = "end pattern at control";
              if (param_1 != -0x6a) {
                pcVar1 = "undefined error code";
              }
              return pcVar1;
            }
          }
        }
      }
      else {
        if (param_1 == -0xe) {
          return "unexpected bytecode (bug)";
        }
        if (param_1 < -0xd) {
          if (param_1 == -0x1e) {
            return "invalid argument";
          }
          if (param_1 < -0x1d) {
            pcVar1 = "end pattern at left bracket";
            if ((param_1 != -0x65) && (pcVar1 = "empty char-class", -0x66 < param_1)) {
              pcVar1 = "end pattern at left brace";
              if (param_1 != -100) {
                pcVar1 = "undefined error code";
              }
              return pcVar1;
            }
          }
          else {
            pcVar1 = "default multibyte-encoding is not set";
            if ((param_1 != -0x15) && (pcVar1 = "match-stack limit over", param_1 != -0xf)) {
              pcVar1 = "can\'t convert to wide-char on specified multibyte-encoding";
              if (param_1 != -0x16) {
                pcVar1 = "undefined error code";
              }
              return pcVar1;
            }
          }
        }
        else if (param_1 == -6) {
          pcVar1 = "undefined type (bug)";
        }
        else if (param_1 < -5) {
          pcVar1 = "stack error (bug)";
          if ((param_1 != -0xc) && (pcVar1 = "undefined bytecode (bug)", -0xd < param_1)) {
            pcVar1 = "internal parser error (bug)";
            if (param_1 != -0xb) {
              pcVar1 = "undefined error code";
            }
            return pcVar1;
          }
        }
        else {
          pcVar1 = "no support in this configuration";
          if ((param_1 != -2) && (pcVar1 = "mismatch", param_1 != -1)) {
            pcVar1 = "failed to allocate memory";
            if (param_1 != -5) {
              pcVar1 = "undefined error code";
            }
            return pcVar1;
          }
        }
      }
    }
  }
  return pcVar1;
}


// ==== entry=00b2ac30 name=FUN_00b2ac30 size=705 ====

/* WARNING: Restarted to delay deadcode elimination for space: stack */

ulong FUN_00b2ac30(char *param_1,long param_2,long *param_3)

{
  undefined8 *puVar1;
  bool bVar2;
  byte bVar3;
  char cVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  void *pvVar8;
  char *pcVar9;
  byte bVar11;
  char *__dest;
  char *pcVar10;
  void *__src;
  ulong __n;
  long lVar12;
  size_t __n_00;
  long lVar13;
  int local_b8;
  byte local_88 [48];
  long *local_58;
  
  local_58 = param_3;
  if ((8 < param_2 + 0xdfU) || ((1L << ((byte)(param_2 + 0xdfU) & 0x3f) & 0x1f9U) == 0)) {
    pvVar8 = (void *)FUN_00b2a7a0(param_2);
    iVar5 = FUN_00b43380(&PTR_FUN_011bf020,pvVar8);
    __n = (ulong)iVar5;
    memcpy(param_1,pvVar8,__n);
    param_1[__n] = '\0';
LAB_00b2acbd:
    return __n & 0xffffffff;
  }
  puVar1 = (undefined8 *)*param_3;
  pvVar8 = (void *)param_3[2];
  __src = (void *)param_3[1];
  if (*(int *)((long)puVar1 + 0x1c) < 2) {
    lVar13 = (long)pvVar8 - (long)__src;
    lVar12 = 0x1b;
    if (lVar13 < 0x1c) {
      lVar12 = lVar13;
    }
    __n_00 = (size_t)(int)lVar12;
    memcpy(local_88,__src,__n_00);
    bVar2 = 0x1b < lVar13;
  }
  else {
    if (__src < pvVar8) {
      iVar5 = 0;
      __n_00 = 0;
      do {
        uVar7 = (*(code *)puVar1[6])(__src,pvVar8);
        bVar3 = (byte)uVar7;
        if (uVar7 < 0x80) {
          iVar5 = iVar5 + 1;
          local_88[__n_00] = bVar3;
        }
        else {
          bVar11 = (byte)(uVar7 >> 8);
          if ((uVar7 < 0x10000) || (0x11 < iVar5)) {
            if (0x15 < iVar5) goto LAB_00b2ae68;
            iVar5 = iVar5 + 6;
            sprintf((char *)(local_88 + __n_00),"\\x%02x",(ulong)bVar11);
            sprintf((char *)(local_88 + __n_00 + 4),"%02x",(ulong)bVar3);
          }
          else {
            iVar5 = iVar5 + 10;
            sprintf((char *)(local_88 + __n_00),"\\x%02x",(ulong)(uVar7 >> 0x18));
            sprintf((char *)(local_88 + __n_00 + 4),"%02x",(ulong)(uVar7 >> 0x10 & 0xff));
            sprintf((char *)(local_88 + __n_00 + 6),"%02x",(ulong)bVar11);
            sprintf((char *)(local_88 + __n_00 + 8),"%02x",(ulong)bVar3);
          }
        }
        __n_00 = (size_t)iVar5;
        iVar6 = (*(code *)*puVar1)(__src);
        __src = (void *)((long)__src + (long)iVar6);
        if ((0x1a < iVar5) || (pvVar8 <= __src)) goto LAB_00b2ae68;
      } while( true );
    }
    __n_00 = 0;
LAB_00b2ae68:
    bVar2 = __src < pvVar8;
  }
  pcVar9 = (char *)FUN_00b2a7a0(param_2);
  __dest = param_1;
LAB_00b2adf9:
  cVar4 = *pcVar9;
  if (cVar4 != '\0') {
    do {
      pcVar10 = pcVar9 + 1;
      if (cVar4 == '%') {
        cVar4 = pcVar9[1];
        pcVar10 = pcVar9 + 2;
        if (cVar4 == 'n') goto code_r0x00b2ae34;
      }
      *__dest = cVar4;
      __dest = __dest + 1;
      cVar4 = *pcVar10;
      pcVar9 = pcVar10;
      if (cVar4 == '\0') break;
    } while( true );
  }
  *__dest = '\0';
  local_b8 = (int)param_1;
  __n = (ulong)(uint)((int)__dest - local_b8);
  goto LAB_00b2acbd;
code_r0x00b2ae34:
  pvVar8 = memcpy(__dest,local_88,__n_00);
  pcVar10 = (char *)((long)pvVar8 + __n_00);
  __dest = pcVar10;
  if (bVar2) {
    pcVar10[2] = '.';
    __dest = pcVar10 + 3;
    pcVar10[0] = '.';
    pcVar10[1] = '.';
  }
  pcVar9 = pcVar9 + 2;
  goto LAB_00b2adf9;
}


// ==== entry=00b2af10 name=FUN_00b2af10 size=745 ====

void FUN_00b2af10(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                 undefined8 param_5,undefined8 param_6,undefined8 param_7,undefined8 param_8,
                 char *param_9,int param_10,undefined8 *param_11,byte *param_12,byte *param_13,
                 char *param_14)

{
  ulong uVar1;
  char in_AL;
  byte bVar2;
  int iVar3;
  int iVar4;
  size_t sVar5;
  long lVar6;
  ulong uVar7;
  int iVar8;
  byte *pbVar9;
  byte *pbVar10;
  byte *pbVar11;
  bool bVar12;
  byte local_106 [6];
  undefined4 local_100;
  undefined4 local_fc;
  undefined1 *local_f8;
  undefined1 *local_f0;
  undefined1 local_e8 [48];
  undefined8 local_b8;
  undefined8 local_a8;
  undefined8 local_98;
  undefined8 local_88;
  undefined8 local_78;
  undefined8 local_68;
  undefined8 local_58;
  undefined8 local_48;
  
  if (in_AL != '\0') {
    local_b8 = param_1;
    local_a8 = param_2;
    local_98 = param_3;
    local_88 = param_4;
    local_78 = param_5;
    local_68 = param_6;
    local_58 = param_7;
    local_48 = param_8;
  }
  local_f8 = &stack0x00000008;
  local_100 = 0x30;
  local_f0 = local_e8;
  local_fc = 0x30;
  iVar3 = vsnprintf(param_9,(long)param_10,param_14,&local_100);
  if ((ulong)((long)iVar3 + 4 + ((long)param_13 - (long)param_12) * 4) < (ulong)(long)param_10) {
    sVar5 = strlen(param_9);
    builtin_strncpy(param_9 + sVar5,": /",4);
    iVar3 = FUN_00b43380(&PTR_FUN_011bf020,param_9);
    pbVar11 = (byte *)(param_9 + iVar3);
    if (param_12 < param_13) {
LAB_00b2aff7:
      bVar2 = *param_12;
      pbVar9 = pbVar11;
      if (bVar2 == 0x5c) goto LAB_00b2b0ed;
      do {
        if (bVar2 == 0x2f) {
          *pbVar11 = 0x5c;
          pbVar10 = param_12 + 1;
          pbVar11[1] = *param_12;
          pbVar11 = pbVar11 + 2;
        }
        else {
          iVar3 = (*(code *)*param_11)(param_12);
          if (iVar3 == 1) {
            pbVar10 = param_12 + 1;
            iVar3 = (*(code *)param_11[0xf])(*param_12,7);
            if ((iVar3 == 0) && (iVar3 = (*(code *)param_11[0xf])(*param_12,9), iVar3 == 0)) {
              sprintf((char *)local_106,"\\x%02x",(ulong)*param_12);
              iVar3 = FUN_00b43380(&PTR_FUN_011bf020,local_106);
              if (0 < iVar3) {
                uVar7 = 0;
                do {
                  pbVar11[uVar7] = local_106[uVar7];
                  uVar1 = uVar7 + 1;
                  bVar12 = uVar7 != iVar3 - 1;
                  uVar7 = uVar1;
                } while (bVar12);
                pbVar11 = pbVar11 + uVar1;
              }
            }
            else {
              *pbVar11 = *param_12;
              pbVar11 = pbVar11 + 1;
            }
          }
          else {
            iVar3 = (*(code *)*param_11)(param_12);
            iVar8 = iVar3 + (int)param_12;
            pbVar9 = param_12;
            if (*(int *)((long)param_11 + 0x1c) != 1) goto LAB_00b2b039;
            pbVar10 = param_12;
            if (0 < iVar3) {
              uVar7 = 0;
              do {
                pbVar11[uVar7] = param_12[uVar7];
                uVar1 = uVar7 + 1;
                bVar12 = uVar7 != iVar3 - 1;
                uVar7 = uVar1;
              } while (bVar12);
              pbVar10 = param_12 + uVar1;
              pbVar11 = pbVar11 + uVar1;
            }
          }
        }
        while( true ) {
          if (param_13 <= pbVar10) goto LAB_00b2b0b4;
          bVar2 = *pbVar10;
          param_12 = pbVar10;
          pbVar9 = pbVar11;
          if (bVar2 != 0x5c) break;
LAB_00b2b0ed:
          pbVar10 = param_12 + 1;
          *pbVar9 = 0x5c;
          pbVar11 = pbVar9 + 1;
          iVar3 = (*(code *)*param_11)(pbVar10);
          if (0 < iVar3) {
            lVar6 = 1;
            do {
              pbVar9[lVar6] = param_12[lVar6];
              lVar6 = lVar6 + 1;
            } while (lVar6 != (ulong)(iVar3 - 1) + 2);
            lVar6 = (ulong)(iVar3 - 1) + 1;
            pbVar10 = pbVar10 + lVar6;
            pbVar11 = pbVar11 + lVar6;
          }
        }
      } while( true );
    }
LAB_00b2b0b4:
    pbVar11[0] = 0x2f;
    pbVar11[1] = 0;
  }
  return;
LAB_00b2b039:
  while (pbVar10 = pbVar9, 0 < iVar8 - (int)pbVar9) {
    while( true ) {
      pbVar9 = pbVar10 + 1;
      sprintf((char *)local_106,"\\x%02x",(ulong)*pbVar10);
      iVar4 = FUN_00b43380(&PTR_FUN_011bf020,local_106);
      if (iVar4 < 1) break;
      uVar7 = 0;
      do {
        pbVar11[uVar7] = local_106[uVar7];
        uVar1 = uVar7 + 1;
        bVar12 = uVar7 != iVar4 - 1;
        uVar7 = uVar1;
      } while (bVar12);
      pbVar11 = pbVar11 + uVar1;
      pbVar10 = pbVar9;
      if (iVar8 - (int)pbVar9 < 1) goto LAB_00b2b098;
    }
  }
LAB_00b2b098:
  lVar6 = 0;
  if (-1 < iVar3) {
    lVar6 = (long)iVar3;
  }
  param_12 = param_12 + lVar6;
  if (param_13 <= param_12) goto LAB_00b2b0b4;
  goto LAB_00b2aff7;
}


// ==== entry=00b2b210 name=FUN_00b2b210 size=1 ====

void FUN_00b2b210(void)

{
  return;
}


// ==== entry=00b2b220 name=FUN_00b2b220 size=85 ====

int FUN_00b2b220(undefined8 *param_1,undefined8 *param_2)

{
  byte *pbVar1;
  byte *pbVar2;
  byte *pbVar3;
  byte *pbVar4;
  int iVar5;
  long lVar6;
  long lVar7;
  
  pbVar3 = (byte *)*param_2;
  iVar5 = 1;
  pbVar4 = (byte *)*param_1;
  lVar7 = (long)param_1[1] - (long)pbVar4;
  if (lVar7 == param_2[1] - (long)pbVar3) {
    if ((byte *)param_1[1] <= pbVar4) {
      return 0;
    }
    iVar5 = (uint)*pbVar4 - (uint)*pbVar3;
    if (iVar5 == 0) {
      lVar6 = 1;
      do {
        if (lVar6 == lVar7) {
          return 0;
        }
        pbVar1 = pbVar4 + lVar6;
        pbVar2 = pbVar3 + lVar6;
        lVar6 = lVar6 + 1;
        iVar5 = (uint)*pbVar1 - (uint)*pbVar2;
      } while (iVar5 == 0);
    }
  }
  return iVar5;
}


// ==== entry=00b2b290 name=FUN_00b2b290 size=46 ====

int FUN_00b2b290(undefined8 *param_1)

{
  int iVar1;
  byte *pbVar2;
  byte *pbVar3;
  
  iVar1 = 0;
  pbVar2 = (byte *)*param_1;
  if ((byte *)*param_1 < (byte *)param_1[1]) {
    do {
      pbVar3 = pbVar2 + 1;
      iVar1 = iVar1 * 0x3e5 + (uint)*pbVar2;
      pbVar2 = pbVar3;
    } while (pbVar3 != (byte *)param_1[1]);
    return iVar1 + (iVar1 >> 5);
  }
  return 0;
}


// ==== entry=00b2b2d0 name=FUN_00b2b2d0 size=62 ====

undefined8 FUN_00b2b2d0(undefined8 param_1,long *param_2,undefined8 *param_3)

{
  undefined8 uVar1;
  long *plVar2;
  
  plVar2 = param_2 + 3;
  if (1 < (int)param_2[2]) {
    plVar2 = (long *)param_2[4];
  }
  uVar1 = (*(code *)*param_3)(*param_2,param_2[1] + *param_2,(int)param_2[2],plVar2,param_3[1],
                              param_3[2]);
  if ((int)uVar1 == 0) {
    return uVar1;
  }
  *(int *)(param_3 + 3) = (int)uVar1;
  return 1;
}


// ==== entry=00b2b320 name=FUN_00b2b320 size=359 ====

ulong FUN_00b2b320(ulong *param_1,ulong param_2,int param_3,int param_4,undefined8 *param_5)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  ulong uVar5;
  ulong uVar6;
  ulong uVar7;
  
  param_3 = param_4 - param_3;
  uVar7 = *param_1;
  if (uVar7 < param_2) {
    param_4 = param_4 + -1;
    uVar5 = 0;
    while( true ) {
      iVar2 = (*(code *)param_5[6])(uVar7,param_2);
      iVar3 = (*(code *)*param_5)(uVar7);
      uVar6 = (long)iVar3 + uVar7;
      iVar3 = (*(code *)param_5[0xf])(iVar2,0xb);
      if (iVar3 == 0) break;
      iVar3 = (*(code *)param_5[0xf])(iVar2,4);
      if (iVar3 == 0) {
        iVar3 = (*(code *)param_5[0xf])(iVar2,10);
        uVar1 = iVar2 - 0x37;
        if (iVar3 == 0) {
          uVar1 = iVar2 - 0x57;
        }
      }
      else {
        uVar1 = iVar2 - 0x30;
      }
      if (0x7fffffff - (ulong)uVar1 >> 4 < uVar5) {
        return 0xffffffff;
      }
      iVar3 = (*(code *)param_5[0xf])(iVar2,4);
      if (iVar3 == 0) {
        iVar4 = (*(code *)param_5[0xf])(iVar2,10);
        iVar3 = iVar2 + -0x57;
        if (iVar4 != 0) {
          iVar3 = iVar2 + -0x37;
        }
      }
      else {
        iVar3 = iVar2 + -0x30;
      }
      uVar5 = (ulong)(uint)((int)uVar5 * 0x10 + iVar3);
      uVar7 = uVar6;
      if ((param_2 <= uVar6) || (param_4 = param_4 + -1, param_4 == -1)) break;
    }
  }
  else {
    uVar5 = 0;
  }
  if (param_3 < param_4) {
    uVar5 = 0xfffffffe;
  }
  else {
    *param_1 = uVar7;
  }
  return uVar5;
}


// ==== entry=00b2b4a0 name=FUN_00b2b4a0 size=207 ====

ulong FUN_00b2b4a0(ulong *param_1,ulong param_2,int param_3,undefined8 *param_4)

{
  ulong uVar1;
  uint uVar2;
  int iVar3;
  ulong uVar4;
  ulong uVar5;
  
  uVar5 = *param_1;
  if (uVar5 < param_2) {
    param_3 = param_3 + -1;
    uVar4 = 0;
    while( true ) {
      uVar2 = (*(code *)param_4[6])(uVar5,param_2);
      iVar3 = (*(code *)*param_4)(uVar5);
      uVar1 = uVar5 + (long)iVar3;
      iVar3 = (*(code *)param_4[0xf])(uVar2,4);
      if ((0x37 < uVar2) || (iVar3 == 0)) break;
      if (0x7fffffff - (ulong)(uVar2 - 0x30) >> 3 < uVar4) {
        return 0xffffffff;
      }
      uVar4 = (ulong)((uVar2 - 0x30) + (int)uVar4 * 8);
      uVar5 = uVar1;
      if ((param_2 <= uVar1) || (param_3 = param_3 + -1, param_3 == -1)) break;
    }
  }
  else {
    uVar4 = 0;
  }
  *param_1 = uVar5;
  return uVar4;
}


// ==== entry=00b2b580 name=FUN_00b2b580 size=207 ====

undefined8 FUN_00b2b580(ulong *param_1,ulong param_2,long param_3)

{
  undefined8 *puVar1;
  int iVar2;
  int iVar3;
  undefined8 uVar4;
  ulong uVar5;
  ulong uVar6;
  ulong uVar7;
  
  uVar7 = *param_1;
  puVar1 = *(undefined8 **)(param_3 + 8);
  uVar5 = uVar7;
  if (uVar7 < param_2) {
    do {
      uVar6 = uVar5;
      iVar2 = (*(code *)puVar1[6])(uVar6,param_2);
      iVar3 = (*(code *)*puVar1)(uVar6);
      uVar5 = (long)iVar3 + uVar6;
      if (iVar2 == 0x7d) {
        uVar4 = (*(code *)puVar1[0xe])(puVar1,uVar7,uVar6);
        if (-1 < (int)uVar4) {
          *param_1 = uVar5;
          return uVar4;
        }
        uVar7 = uVar6;
        uVar5 = *param_1;
        goto LAB_00b2b61c;
      }
      if ((iVar2 - 0x28U < 2) || (iVar2 - 0x7bU < 2)) {
        uVar4 = 0xffffff21;
        uVar7 = uVar6;
        uVar5 = *param_1;
        goto LAB_00b2b61c;
      }
    } while (uVar5 < param_2);
    uVar4 = 0;
    uVar7 = uVar6;
    uVar5 = *param_1;
  }
  else {
    uVar4 = 0;
  }
LAB_00b2b61c:
  *(ulong *)(param_3 + 0x38) = uVar5;
  *(ulong *)(param_3 + 0x40) = uVar7;
  return uVar4;
}


// ==== entry=00b2b670 name=FUN_00b2b670 size=77 ====

int FUN_00b2b670(byte *param_1)

{
  int iVar1;
  byte *pbVar2;
  byte *pbVar3;
  
  iVar1 = 0;
  pbVar3 = param_1;
  do {
    pbVar2 = pbVar3 + 1;
    iVar1 = iVar1 * 0x3e5 + (uint)*pbVar3;
    pbVar3 = pbVar2;
  } while (pbVar2 != param_1 + 8);
  pbVar3 = param_1 + 0xc;
  do {
    pbVar2 = pbVar3 + 1;
    iVar1 = iVar1 * 0x3e5 + (uint)*pbVar3;
    pbVar3 = pbVar2;
  } while (pbVar2 != param_1 + 0x10);
  return iVar1 + *(int *)(param_1 + 8) + (iVar1 + *(int *)(param_1 + 8) >> 5);
}


// ==== entry=00b2b6c0 name=FUN_00b2b6c0 size=62 ====

undefined8 FUN_00b2b6c0(void *param_1,undefined8 *param_2)

{
  free((void *)*param_2);
  if ((void *)param_2[4] != (void *)0x0) {
    free((void *)param_2[4]);
  }
  free(param_1);
  free(param_2);
  return 2;
}


// ==== entry=00b2b700 name=FUN_00b2b700 size=32 ====

void FUN_00b2b700(undefined8 *param_1)

{
  if (param_1 != (undefined8 *)0x0) {
    if ((void *)*param_1 != (void *)0x0) {
      free((void *)*param_1);
    }
    free(param_1);
    return;
  }
  return;
}


// ==== entry=00b2b730 name=FUN_00b2b730 size=64 ====

undefined8 FUN_00b2b730(void *param_1,void *param_2)

{
  if (param_2 != (void *)0x0) {
    if (*(void **)((long)param_2 + 0x28) != (void *)0x0) {
      free(*(void **)((long)param_2 + 0x28));
    }
    free(param_2);
  }
  if (param_1 != (void *)0x0) {
    free(param_1);
  }
  return 2;
}


// ==== entry=00b2b770 name=FUN_00b2b770 size=208 ====

int FUN_00b2b770(long param_1)

{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  undefined8 *puVar8;
  undefined8 *puVar9;
  int iVar10;
  int iVar11;
  
  iVar10 = *(int *)(param_1 + 0x60) + 1;
  if ((7 < iVar10) && (*(int *)(param_1 + 0x68) <= iVar10)) {
    if (*(void **)(param_1 + 0xb0) == (void *)0x0) {
      iVar11 = 0x10;
      puVar8 = malloc(0x80);
      uVar1 = *(undefined8 *)(param_1 + 0x78);
      uVar2 = *(undefined8 *)(param_1 + 0x80);
      uVar3 = *(undefined8 *)(param_1 + 0x88);
      uVar4 = *(undefined8 *)(param_1 + 0x90);
      uVar5 = *(undefined8 *)(param_1 + 0x98);
      uVar6 = *(undefined8 *)(param_1 + 0xa0);
      uVar7 = *(undefined8 *)(param_1 + 0xa8);
      *puVar8 = *(undefined8 *)(param_1 + 0x70);
      puVar8[1] = uVar1;
      puVar8[2] = uVar2;
      puVar8[3] = uVar3;
      puVar8[4] = uVar4;
      puVar8[5] = uVar5;
      puVar8[6] = uVar6;
      puVar8[7] = uVar7;
    }
    else {
      iVar11 = *(int *)(param_1 + 0x68) * 2;
      puVar8 = realloc(*(void **)(param_1 + 0xb0),(long)iVar11 << 3);
      if (puVar8 == (undefined8 *)0x0) {
        return -5;
      }
      iVar10 = *(int *)(param_1 + 0x60) + 1;
    }
    if (iVar10 < iVar11) {
      puVar9 = puVar8 + iVar10;
      do {
        *puVar9 = 0;
        puVar9 = puVar9 + 1;
      } while (puVar9 != puVar8 + (ulong)(uint)((iVar11 + -1) - iVar10) + (long)iVar10 + 1);
    }
    *(undefined8 **)(param_1 + 0xb0) = puVar8;
    *(int *)(param_1 + 0x68) = iVar11;
  }
  *(int *)(param_1 + 0x60) = iVar10;
  return iVar10;
}


// ==== entry=00b2b850 name=FUN_00b2b850 size=1008 ====

undefined8 FUN_00b2b850(undefined8 *param_1,uint param_2,uint param_3)

{
  uint uVar1;
  uint uVar2;
  uint *__ptr;
  void *__ptr_00;
  uint *puVar3;
  undefined8 *puVar4;
  undefined4 *__ptr_01;
  undefined8 uVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  ulong uVar10;
  int iVar11;
  ulong uVar12;
  uint uVar13;
  int iVar14;
  uint uVar15;
  uint uVar16;
  uint uVar17;
  
  uVar16 = param_2;
  if (param_3 < param_2) {
    uVar16 = param_3;
    param_3 = param_2;
  }
  puVar4 = (undefined8 *)*param_1;
  if (puVar4 == (undefined8 *)0x0) {
    puVar4 = malloc(0x10);
    *param_1 = puVar4;
    if (puVar4 != (undefined8 *)0x0) {
      uVar5 = FUN_00b39550(puVar4,0x14);
      if ((int)uVar5 != 0) {
        return uVar5;
      }
      uVar17 = *(uint *)((long)puVar4 + 0xc);
      __ptr_01 = (undefined4 *)*puVar4;
      if (uVar17 < 4) {
        do {
          uVar17 = uVar17 * 2;
        } while (uVar17 < 4);
        *(uint *)((long)puVar4 + 0xc) = uVar17;
        __ptr_01 = realloc(__ptr_01,(ulong)uVar17);
        *puVar4 = __ptr_01;
        if (__ptr_01 == (undefined4 *)0x0) goto LAB_00b2bc4d;
      }
      *__ptr_01 = 0;
      if (*(uint *)(puVar4 + 1) < 4) {
        *(undefined4 *)(puVar4 + 1) = 4;
      }
      puVar4 = (undefined8 *)*param_1;
      uVar13 = 0;
      uVar17 = 0;
      __ptr = (uint *)*puVar4;
      puVar3 = __ptr + 1;
      if (uVar16 == 0) goto LAB_00b2bacb;
      goto LAB_00b2b8d2;
    }
LAB_00b2bc4d:
    uVar5 = 0xfffffffb;
  }
  else {
    __ptr = (uint *)*puVar4;
    uVar17 = 0;
    uVar13 = *__ptr;
    puVar3 = __ptr + 1;
    uVar9 = uVar13;
    if (uVar16 == 0) {
LAB_00b2bacb:
      uVar17 = 0;
      iVar14 = 1;
    }
    else {
      while (uVar17 < uVar9) {
        uVar6 = uVar17 + uVar9 >> 1;
        uVar1 = puVar3[uVar6 * 2 + 1];
        while (uVar15 = uVar6, uVar16 - 1 <= uVar1) {
          if (uVar15 <= uVar17) goto LAB_00b2b8d2;
          uVar6 = uVar17 + uVar15 >> 1;
          uVar1 = puVar3[uVar6 * 2 + 1];
          uVar9 = uVar15;
        }
        uVar17 = uVar15 + 1;
      }
LAB_00b2b8d2:
      iVar14 = uVar17 + 1;
    }
    uVar9 = uVar13;
    if (param_3 != 0xffffffff) {
      uVar1 = uVar13;
      uVar9 = uVar17;
      while (uVar9 < uVar1) {
        uVar15 = uVar9 + uVar1 >> 1;
        uVar6 = puVar3[uVar15 * 2];
        while (uVar2 = uVar15, param_3 + 1 < uVar6) {
          if (uVar2 <= uVar9) goto LAB_00b2b924;
          uVar15 = uVar9 + uVar2 >> 1;
          uVar6 = puVar3[uVar15 * 2];
          uVar1 = uVar2;
        }
        uVar9 = uVar2 + 1;
      }
    }
LAB_00b2b924:
    iVar8 = iVar14 - uVar9;
    if (10000 < iVar8 + uVar13) {
      return 0xffffff33;
    }
    if (iVar8 == 1) {
      iVar11 = uVar9 * 8 + 4;
      iVar7 = iVar14 * 8 + 4;
LAB_00b2baf0:
      uVar12 = (ulong)*(uint *)((long)puVar4 + 0xc);
      if (uVar9 < uVar13) {
        iVar14 = (uVar13 - uVar9) * 8;
        uVar9 = iVar14 + iVar7;
        if (*(uint *)((long)puVar4 + 0xc) < uVar9) {
          do {
            uVar1 = (int)uVar12 * 2;
            uVar12 = (ulong)uVar1;
          } while (uVar1 < uVar9);
          *(uint *)((long)puVar4 + 0xc) = uVar1;
          __ptr = realloc(__ptr,uVar12);
          *puVar4 = __ptr;
          if (__ptr == (uint *)0x0) goto LAB_00b2bc4d;
        }
        memmove((void *)((long)__ptr + (long)iVar7),(void *)((long)iVar11 + (long)__ptr),
                (long)iVar14);
        if (uVar9 <= *(uint *)(puVar4 + 1)) goto LAB_00b2bbbb;
        __ptr = (uint *)*puVar4;
        uVar12 = (ulong)*(uint *)((long)puVar4 + 0xc);
        *(uint *)(puVar4 + 1) = uVar9;
      }
    }
    else {
      if (puVar3[uVar17 * 2] < uVar16) {
        uVar16 = puVar3[uVar17 * 2];
      }
      if (param_3 < puVar3[uVar9 * 2 - 1]) {
        param_3 = puVar3[uVar9 * 2 - 1];
      }
      if (iVar8 != 0) {
        iVar11 = uVar9 * 8 + 4;
        iVar7 = iVar14 * 8 + 4;
        if (0 < iVar8) goto LAB_00b2baf0;
        memmove((void *)((long)__ptr + (long)iVar7),(void *)((long)iVar11 + (long)__ptr),
                (ulong)(uint)(*(int *)(puVar4 + 1) - iVar11));
        *(uint *)(puVar4 + 1) = *(int *)(puVar4 + 1) + (uVar9 - iVar14) * -8;
LAB_00b2bbbb:
        __ptr = (uint *)*puVar4;
      }
      uVar12 = (ulong)*(uint *)((long)puVar4 + 0xc);
    }
    iVar14 = uVar17 * 8;
    uVar17 = iVar14 + 0xc;
    uVar10 = uVar12;
    if ((uint)uVar12 < uVar17) {
      do {
        uVar9 = (int)uVar10 * 2;
        uVar10 = (ulong)uVar9;
      } while (uVar9 < uVar17);
      if (uVar9 != (uint)uVar12) {
        __ptr = realloc(__ptr,(ulong)uVar9);
        *puVar4 = __ptr;
        if (__ptr == (uint *)0x0) goto LAB_00b2bc4d;
        *(uint *)((long)puVar4 + 0xc) = uVar9;
        uVar12 = (ulong)uVar9;
      }
    }
    uVar9 = iVar14 + 8;
    if ((uint)uVar12 < uVar9) {
      do {
        uVar1 = (int)uVar12 * 2;
        uVar12 = (ulong)uVar1;
      } while (uVar1 < uVar9);
      *(uint *)((long)puVar4 + 0xc) = uVar1;
      __ptr = realloc(__ptr,uVar12);
      *puVar4 = __ptr;
      if (__ptr == (uint *)0x0) goto LAB_00b2bc4d;
    }
    *(uint *)((long)__ptr + (long)(iVar14 + 4)) = uVar16;
    if (*(uint *)(puVar4 + 1) < uVar9) {
      *(uint *)(puVar4 + 1) = uVar9;
    }
    uVar12 = (ulong)*(uint *)((long)puVar4 + 0xc);
    __ptr_00 = (void *)*puVar4;
    if (*(uint *)((long)puVar4 + 0xc) < uVar17) {
      do {
        uVar16 = (int)uVar12 * 2;
        uVar12 = (ulong)uVar16;
      } while (uVar16 < uVar17);
      *(uint *)((long)puVar4 + 0xc) = uVar16;
      __ptr_00 = realloc(__ptr_00,uVar12);
      *puVar4 = __ptr_00;
      if (__ptr_00 == (void *)0x0) goto LAB_00b2bc4d;
    }
    *(uint *)((long)__ptr_00 + (long)(iVar14 + 4) + 4) = param_3;
    if (*(uint *)(puVar4 + 1) < uVar17) {
      *(uint *)(puVar4 + 1) = uVar17;
    }
    uVar12 = (ulong)*(uint *)((long)puVar4 + 0xc);
    puVar3 = (uint *)*puVar4;
    if (*(uint *)((long)puVar4 + 0xc) < 4) {
      do {
        uVar16 = (int)uVar12 * 2;
        uVar12 = (ulong)uVar16;
      } while (uVar16 < 4);
      *(uint *)((long)puVar4 + 0xc) = uVar16;
      puVar3 = realloc(puVar3,uVar12);
      *puVar4 = puVar3;
      if (puVar3 == (uint *)0x0) goto LAB_00b2bc4d;
    }
    *puVar3 = iVar8 + uVar13;
    uVar5 = 0;
    if (*(uint *)(puVar4 + 1) < 4) {
      *(undefined4 *)(puVar4 + 1) = 4;
    }
  }
  return uVar5;
}


// ==== entry=00b2bc70 name=FUN_00b2bc70 size=85 ====

int FUN_00b2bc70(undefined8 *param_1,undefined8 *param_2)

{
  uint uVar1;
  void *__src;
  int iVar2;
  undefined8 *puVar3;
  
  puVar3 = malloc(0x10);
  *param_1 = puVar3;
  if (puVar3 == (undefined8 *)0x0) {
    iVar2 = -5;
  }
  else {
    iVar2 = FUN_00b39550(puVar3,*(undefined4 *)((long)param_2 + 0xc));
    if (iVar2 == 0) {
      uVar1 = *(uint *)(param_2 + 1);
      __src = (void *)*param_2;
      *(uint *)(puVar3 + 1) = uVar1;
      memcpy((void *)*puVar3,__src,(ulong)uVar1);
    }
  }
  return iVar2;
}


// ==== entry=00b2bcd0 name=FUN_00b2bcd0 size=53 ====

undefined8 FUN_00b2bcd0(undefined8 param_1,long param_2,long param_3)

{
  long lVar1;
  long lVar2;
  
  if (*(int *)(param_2 + 0x10) < 2) {
    if (*(int *)(param_2 + 0x10) == 1) {
      *(undefined4 *)(param_2 + 0x18) =
           *(undefined4 *)(param_3 + (long)*(int *)(param_2 + 0x18) * 4);
      return 0;
    }
  }
  else {
    lVar1 = *(long *)(param_2 + 0x20);
    lVar2 = 0;
    do {
      *(undefined4 *)(lVar1 + lVar2 * 4) =
           *(undefined4 *)(param_3 + (long)*(int *)(lVar1 + lVar2 * 4) * 4);
      lVar2 = lVar2 + 1;
    } while ((int)lVar2 < *(int *)(param_2 + 0x10));
  }
  return 0;
}


// ==== entry=00b2bd10 name=FUN_00b2bd10 size=658 ====

ulong FUN_00b2bd10(ulong *param_1,ulong param_2,long param_3)

{
  undefined8 *puVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  ulong uVar5;
  ulong local_30;
  
  local_30 = *param_1;
  puVar1 = *(undefined8 **)(param_3 + 8);
  if (param_2 <= local_30) {
    return 0xffffff98;
  }
  uVar2 = (*(code *)puVar1[6])(local_30);
  uVar5 = (ulong)uVar2;
  iVar3 = (*(code *)*puVar1)(local_30);
  local_30 = (long)iVar3 + local_30;
  if (uVar2 == 0x4d) {
    if ((*(byte *)(*(long *)(param_3 + 0x10) + 5) & 0x10) != 0) {
      if (local_30 < param_2) {
        iVar3 = (*(code *)puVar1[6])(local_30,param_2);
        iVar4 = (*(code *)*puVar1)(local_30);
        local_30 = (long)iVar4 + local_30;
        if (iVar3 != 0x2d) {
          return 0xffffff94;
        }
        if (local_30 < param_2) {
          uVar2 = (*(code *)puVar1[6])(local_30,param_2);
          uVar5 = (ulong)uVar2;
          iVar3 = (*(code *)*puVar1)(local_30);
          local_30 = (long)iVar3 + local_30;
          if (*(uint *)(*(long *)(param_3 + 0x10) + 0x10) == uVar2) {
            uVar5 = FUN_00b2bd10(&local_30,param_2,param_3);
            if ((int)uVar5 < 0) {
              return uVar5;
            }
            uVar5 = uVar5 & 0xffffffff;
          }
          uVar5 = uVar5 & 0xff | 0x80;
          goto switchD_00b2bd8e_caseD_63;
        }
      }
      return 0xffffff97;
    }
    goto switchD_00b2bd8e_caseD_63;
  }
  if (uVar2 == 99) {
    if ((**(uint **)(param_3 + 0x10) & 0x8000000) == 0) goto switchD_00b2bd8e_caseD_63;
  }
  else {
    if (uVar2 != 0x43) {
      if ((**(uint **)(param_3 + 0x10) & 0x4000000) != 0) {
        switch(uVar2) {
        case 0x61:
          uVar5 = 7;
          break;
        case 0x62:
          uVar5 = 8;
          break;
        case 0x65:
          uVar5 = 0x1b;
          break;
        case 0x66:
          uVar5 = 0xc;
          break;
        case 0x6e:
          uVar5 = 10;
          break;
        case 0x72:
          uVar5 = 0xd;
          break;
        case 0x74:
          uVar5 = 9;
          break;
        case 0x76:
          uVar5 = (ulong)((-(uint)(((*(uint **)(param_3 + 0x10))[1] & 0x2000) == 0) & 0x6b) + 0xb);
        }
      }
      goto switchD_00b2bd8e_caseD_63;
    }
    if ((*(byte *)(*(long *)(param_3 + 0x10) + 5) & 8) == 0) goto switchD_00b2bd8e_caseD_63;
    if (param_2 <= local_30) {
      return 0xffffff96;
    }
    iVar3 = (*(code *)puVar1[6])(local_30,param_2);
    iVar4 = (*(code *)*puVar1)(local_30);
    local_30 = (long)iVar4 + local_30;
    if (iVar3 != 0x2d) {
      return 0xffffff93;
    }
  }
  if (param_2 <= local_30) {
    return 0xffffff96;
  }
  uVar2 = (*(code *)puVar1[6])(local_30,param_2);
  iVar3 = (*(code *)*puVar1)(local_30);
  local_30 = (long)iVar3 + local_30;
  if (uVar2 == 0x3f) {
    uVar5 = 0x7f;
  }
  else {
    if (*(uint *)(*(long *)(param_3 + 0x10) + 0x10) == uVar2) {
      uVar5 = FUN_00b2bd10(&local_30,param_2,param_3);
      uVar2 = (uint)uVar5;
      if ((int)uVar2 < 0) {
        return uVar5;
      }
    }
    uVar5 = (ulong)(uVar2 & 0x9f);
  }
switchD_00b2bd8e_caseD_63:
  *param_1 = local_30;
  return uVar5;
}


// ==== entry=00b2bff0 name=FUN_00b2bff0 size=115 ====

int FUN_00b2bff0(long param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x10);
  if (*(int *)(param_1 + 0x18) == 0) {
    if (iVar1 == 0) {
      if (*(int *)(param_1 + 0x14) == 1) {
        return 3;
      }
      return (uint)(*(int *)(param_1 + 0x14) == -1) * 5 + -1;
    }
    if (iVar1 == 1) {
      iVar1 = -1;
      if (*(int *)(param_1 + 0x14) == -1) {
        iVar1 = 5;
      }
      return iVar1;
    }
  }
  else {
    if (iVar1 == 0) {
      iVar1 = *(int *)(param_1 + 0x14);
      if (iVar1 == 1) {
        return 0;
      }
      return ((iVar1 == -1) - 1) + (uint)(iVar1 == -1);
    }
    if (iVar1 == 1) {
      return (uint)(*(int *)(param_1 + 0x14) == -1) * 3 + -1;
    }
  }
  return -1;
}


// ==== entry=00b2c090 name=FUN_00b2c090 size=35 ====

bool FUN_00b2c090(long *param_1,long *param_2)

{
  if ((*(int *)((long)param_1 + 0xc) == *(int *)((long)param_2 + 0xc)) && (*param_1 == *param_2)) {
    return (int)param_1[1] != (int)param_2[1];
  }
  return true;
}


// ==== entry=00b2c0c0 name=FUN_00b2c0c0 size=10 ====

void FUN_00b2c0c0(void)

{
  malloc(0x40);
  return;
}


// ==== entry=00b2c0d0 name=FUN_00b2c0d0 size=67 ====

void FUN_00b2c0d0(undefined8 param_1,undefined8 param_2)

{
  undefined8 *puVar1;
  
  if (DAT_011c3818 == (undefined8 *)0x0) {
    puVar1 = (undefined8 *)FUN_00b2c0c0();
    if (puVar1 == (undefined8 *)0x0) {
      return;
    }
  }
  else {
    puVar1 = DAT_011c3818;
    DAT_011c3818 = (undefined8 *)*DAT_011c3818;
  }
  *(undefined4 *)puVar1 = 8;
  puVar1[1] = param_1;
  puVar1[2] = param_2;
  return;
}


// ==== entry=00b2c120 name=FUN_00b2c120 size=79 ====

void FUN_00b2c120(undefined4 param_1)

{
  undefined8 *puVar1;
  
  if (DAT_011c3818 == (undefined8 *)0x0) {
    puVar1 = (undefined8 *)FUN_00b2c0c0();
    if (puVar1 == (undefined8 *)0x0) {
      return;
    }
  }
  else {
    puVar1 = DAT_011c3818;
    DAT_011c3818 = (undefined8 *)*DAT_011c3818;
  }
  *(undefined4 *)(puVar1 + 1) = param_1;
  *puVar1 = 6;
  *(undefined8 *)((long)puVar1 + 0xc) = 0;
  puVar1[3] = 0;
  *(undefined4 *)(puVar1 + 4) = 0xffffffff;
  *(undefined4 *)((long)puVar1 + 0x3c) = 0;
  return;
}


// ==== entry=00b2c180 name=FUN_00b2c180 size=90 ====

void FUN_00b2c180(void)

{
  undefined8 *puVar1;
  
  if (DAT_011c3818 == (undefined8 *)0x0) {
    puVar1 = (undefined8 *)FUN_00b2c0c0();
    if (puVar1 == (undefined8 *)0x0) {
      return;
    }
  }
  else {
    puVar1 = DAT_011c3818;
    DAT_011c3818 = (undefined8 *)*DAT_011c3818;
  }
  *puVar1 = 1;
  puVar1[1] = 0;
  puVar1[2] = 0;
  puVar1[3] = 0;
  puVar1[4] = 0;
  puVar1[5] = 0;
  return;
}


// ==== entry=00b2c1e0 name=FUN_00b2c1e0 size=54 ====

void FUN_00b2c1e0(void)

{
  undefined8 uVar1;
  undefined4 *puVar2;
  
  if (DAT_011c3818 != (undefined8 *)0x0) {
    uVar1 = *DAT_011c3818;
    *(undefined4 *)DAT_011c3818 = 3;
    DAT_011c3818 = (undefined8 *)uVar1;
    return;
  }
  puVar2 = (undefined4 *)FUN_00b2c0c0();
  if (puVar2 != (undefined4 *)0x0) {
    *puVar2 = 3;
  }
  return;
}


// ==== entry=00b2c220 name=FUN_00b2c220 size=114 ====

void FUN_00b2c220(undefined4 param_1,undefined4 param_2,int param_3)

{
  undefined8 *puVar1;
  
  if (DAT_011c3818 == (undefined8 *)0x0) {
    puVar1 = (undefined8 *)FUN_00b2c0c0();
    if (puVar1 == (undefined8 *)0x0) {
      return;
    }
  }
  else {
    puVar1 = DAT_011c3818;
    DAT_011c3818 = (undefined8 *)*DAT_011c3818;
  }
  *puVar1 = 5;
  puVar1[1] = 0;
  *(undefined4 *)(puVar1 + 2) = param_1;
  *(undefined4 *)((long)puVar1 + 0x14) = param_2;
  puVar1[3] = 1;
  puVar1[4] = 0;
  puVar1[5] = 0;
  *(undefined4 *)(puVar1 + 6) = 0;
  if (param_3 != 0) {
    *(undefined4 *)((long)puVar1 + 4) = 0x4000;
  }
  return;
}


// ==== entry=00b2c2a0 name=FUN_00b2c2a0 size=95 ====

void FUN_00b2c2a0(long param_1,undefined8 param_2)

{
  undefined1 local_108 [264];
  
  if (((code *)PTR_FUN_011bec88 != FUN_00b2b210) &&
     ((*(uint *)(*(long *)(param_1 + 0x10) + 8) & 0x1200000) == 0x1200000)) {
    FUN_00b2af10(local_108,0x100,*(undefined8 *)(param_1 + 8),*(undefined8 *)(param_1 + 0x28),
                 *(undefined8 *)(param_1 + 0x30),"character class has \'%s\' without escape",param_2
                );
    (*(code *)PTR_FUN_011bec88)(local_108);
    return;
  }
  return;
}


// ==== entry=00b2c310 name=FUN_00b2c310 size=160 ====

undefined8 FUN_00b2c310(int param_1,undefined8 *param_2,undefined8 *param_3)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  undefined8 uVar4;
  int *piVar5;
  uint uVar6;
  
  *param_3 = 0;
  if (param_2 != (undefined8 *)0x0) {
    piVar3 = (int *)*param_2;
    iVar1 = *piVar3;
    piVar5 = piVar3 + 1;
    if (0 < iVar1) {
      uVar6 = (uint)(param_1 < 2) << 7;
      do {
        iVar2 = piVar5[1];
        if (uVar6 <= *piVar5 - 1U) {
          uVar4 = FUN_00b2b850(param_3);
          if ((int)uVar4 != 0) {
            return uVar4;
          }
        }
        if (iVar2 == -1) {
          return 0;
        }
        piVar5 = piVar5 + 2;
        uVar6 = iVar2 + 1;
      } while (piVar3 + (ulong)(iVar1 - 1) * 2 + 3 != piVar5);
      goto LAB_00b2c394;
    }
  }
  uVar6 = (uint)(param_1 < 2) << 7;
LAB_00b2c394:
  uVar4 = FUN_00b2b850(param_3,uVar6,0xffffffff);
  return uVar4;
}


// ==== entry=00b2c3c0 name=FUN_00b2c3c0 size=537 ====

undefined8 FUN_00b2c3c0(long param_1,int param_2,uint param_3,int *param_4)

{
  uint *puVar1;
  int iVar2;
  char cVar3;
  byte bVar4;
  long lVar5;
  uint uVar6;
  uint uVar7;
  undefined8 uVar8;
  uint uVar9;
  uint *puVar10;
  int iVar11;
  long lVar12;
  int *piVar13;
  
  iVar2 = *param_4;
  if (param_2 == 0) {
    puVar10 = (uint *)(param_4 + 1);
    iVar11 = 0;
    if (iVar2 < 1) {
      return 0;
    }
    do {
      uVar6 = *puVar10;
      if (uVar6 <= puVar10[1]) {
        if (param_3 <= uVar6) {
LAB_00b2c535:
          if (iVar2 <= iVar11) {
            return 0;
          }
          piVar13 = param_4 + (long)(iVar11 * 2) + 1;
          do {
            uVar8 = FUN_00b2b850(param_1 + 0x28,*piVar13,piVar13[1]);
            if ((int)uVar8 != 0) {
              return uVar8;
            }
            piVar13 = piVar13 + 2;
          } while (param_4 + ((long)iVar11 + (ulong)(uint)((iVar2 + -1) - iVar11)) * 2 + 3 !=
                   piVar13);
          return 0;
        }
        while( true ) {
          uVar9 = uVar6 + 0x1f;
          if (-1 < (int)uVar6) {
            uVar9 = uVar6;
          }
          uVar7 = uVar6 + 1;
          puVar1 = (uint *)(param_1 + 8 + (long)((int)uVar9 >> 5) * 4);
          *puVar1 = *puVar1 | 1 << ((byte)((int)uVar6 % 0x20) & 0x1f);
          if (puVar10[1] < uVar7) break;
          uVar6 = uVar7;
          if (param_3 == uVar7) {
            if (*puVar10 < param_3) {
              iVar11 = iVar11 + 1;
              uVar8 = FUN_00b2b850(param_1 + 0x28);
              if ((int)uVar8 != 0) {
                return uVar8;
              }
            }
            goto LAB_00b2c535;
          }
        }
      }
      iVar11 = iVar11 + 1;
      puVar10 = puVar10 + 2;
      if (iVar2 == iVar11) {
        return 0;
      }
    } while( true );
  }
  if (iVar2 < 1) {
    uVar6 = 0;
    if (param_3 == 0) goto LAB_00b2c5dc;
LAB_00b2c590:
    do {
      uVar9 = uVar6 + 0x1f;
      if (-1 < (int)uVar6) {
        uVar9 = uVar6;
      }
      cVar3 = (char)uVar6;
      bVar4 = (byte)((int)uVar6 >> 0x1f);
      uVar6 = uVar6 + 1;
      puVar10 = (uint *)(param_1 + 8 + (long)((int)uVar9 >> 5) * 4);
      *puVar10 = *puVar10 | 1 << ((cVar3 + (bVar4 >> 3) & 0x1f) - (bVar4 >> 3) & 0x1f);
    } while (uVar6 < param_3);
    if (0 < iVar2) goto LAB_00b2c460;
  }
  else {
    puVar10 = (uint *)(param_4 + 1);
    uVar6 = 0;
    do {
      if (uVar6 < *puVar10) {
        if (param_3 <= uVar6) goto LAB_00b2c460;
        while( true ) {
          uVar9 = uVar6 + 0x1f;
          if (-1 < (int)uVar6) {
            uVar9 = uVar6;
          }
          cVar3 = (char)uVar6;
          bVar4 = (byte)((int)uVar6 >> 0x1f);
          uVar6 = uVar6 + 1;
          puVar1 = (uint *)(param_1 + 8 + (long)((int)uVar9 >> 5) * 4);
          *puVar1 = *puVar1 | 1 << ((cVar3 + (bVar4 >> 3) & 0x1f) - (bVar4 >> 3) & 0x1f);
          if (*puVar10 <= uVar6) break;
          if (param_3 == uVar6) goto LAB_00b2c460;
        }
      }
      puVar1 = puVar10 + 1;
      puVar10 = puVar10 + 2;
      uVar6 = *puVar1 + 1;
    } while ((uint *)(param_4 + (ulong)(iVar2 - 1) * 2 + 3) != puVar10);
    if (uVar6 < param_3) goto LAB_00b2c590;
LAB_00b2c460:
    lVar12 = 0;
    do {
      if ((param_3 < (uint)param_4[lVar12 * 2 + 1]) &&
         (uVar8 = FUN_00b2b850(param_1 + 0x28,param_3,param_4[lVar12 * 2 + 1] - 1), (int)uVar8 != 0)
         ) {
        return uVar8;
      }
      lVar5 = lVar12 * 2;
      lVar12 = lVar12 + 1;
      param_3 = param_4[lVar5 + 2] + 1;
    } while ((int)lVar12 < iVar2);
  }
  if (0x7ffffffe < param_3) {
    return 0;
  }
LAB_00b2c5dc:
  uVar8 = FUN_00b2b850(param_1 + 0x28,param_3,0x7fffffff);
  return uVar8;
}


// ==== entry=00b2c600 name=FUN_00b2c600 size=292 ====

undefined8
FUN_00b2c600(long param_1,undefined8 *param_2,int param_3,undefined8 *param_4,int param_5,
            undefined8 *param_6)

{
  undefined8 uVar1;
  int iVar2;
  int *piVar3;
  undefined8 *puVar4;
  int iVar5;
  
  *param_6 = 0;
  if (param_2 == (undefined8 *)0x0 && param_4 == (undefined8 *)0x0) {
    if (param_3 == 0 && param_5 == 0) {
      return 0;
    }
LAB_00b2c630:
    uVar1 = FUN_00b2b850(param_6,(ulong)(*(int *)(param_1 + 0x1c) < 2) << 7,0xffffffff);
    return uVar1;
  }
  puVar4 = param_2;
  iVar5 = param_3;
  iVar2 = param_5;
  if ((param_4 == (undefined8 *)0x0) ||
     (puVar4 = param_4, iVar5 = param_5, iVar2 = param_3, param_2 == (undefined8 *)0x0)) {
    if (iVar2 == 0) {
      if (iVar5 != 0) {
        uVar1 = FUN_00b2c310(*(undefined4 *)(param_1 + 0x1c),puVar4,param_6);
        return uVar1;
      }
      uVar1 = FUN_00b2bc70(param_6);
      return uVar1;
    }
    goto LAB_00b2c630;
  }
  if (param_3 == 0) {
    iVar5 = *(int *)*param_2;
    piVar3 = (int *)*param_2 + 1;
    param_2 = param_4;
    if (param_5 != 0) goto LAB_00b2c6db;
    uVar1 = FUN_00b2bc70(param_6,param_4);
  }
  else {
    iVar5 = *(int *)*param_4;
    piVar3 = (int *)*param_4 + 1;
    if (param_5 != 0) goto LAB_00b2c68d;
LAB_00b2c6db:
    uVar1 = FUN_00b2c310(*(undefined4 *)(param_1 + 0x1c),param_2,param_6);
  }
  if ((int)uVar1 != 0) {
    return uVar1;
  }
LAB_00b2c68d:
  if (iVar5 != 0) {
    iVar2 = 0;
    do {
      uVar1 = FUN_00b2b850(param_6,piVar3[(uint)(iVar2 * 2)],piVar3[iVar2 * 2 + 1]);
      if ((int)uVar1 != 0) {
        return uVar1;
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 != iVar5);
  }
  return 0;
}


// ==== entry=00b2c740 name=FUN_00b2c740 size=577 ====

undefined8
FUN_00b2c740(undefined8 *param_1,uint param_2,undefined8 *param_3,int param_4,undefined8 *param_5)

{
  int *piVar1;
  uint uVar2;
  undefined8 uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  uint *puVar7;
  uint uVar8;
  uint uVar9;
  int iVar10;
  uint *puVar11;
  int local_58;
  int local_54;
  uint *local_50;
  
  *param_5 = 0;
  if (param_1 == (undefined8 *)0x0) {
    if ((param_3 != (undefined8 *)0x0) && ((param_2 & 1) != 0)) {
      uVar3 = FUN_00b2bc70(param_5,param_3);
      return uVar3;
    }
    return 0;
  }
  if (param_3 == (undefined8 *)0x0) {
    if (param_4 != 0) {
      uVar3 = FUN_00b2bc70(param_5,param_1);
      return uVar3;
    }
    return 0;
  }
  piVar1 = (int *)*param_3;
  iVar10 = *(int *)*param_1;
  local_54 = *piVar1;
  local_50 = (uint *)(piVar1 + 1);
  puVar7 = (uint *)((int *)*param_1 + 1);
  if (param_2 == 0) {
    puVar11 = puVar7;
    iVar6 = iVar10;
    if (param_4 == 0) {
      local_58 = 0;
      if (iVar10 == 0) {
        return 0;
      }
      do {
        uVar8 = puVar7[(uint)(local_58 * 2)];
        uVar4 = puVar7[local_58 * 2 + 1];
        if (local_54 != 0) {
          uVar9 = piVar1[1];
          uVar5 = piVar1[2];
          if (uVar9 <= uVar4) {
            iVar6 = 0;
            do {
              if (uVar8 <= uVar5) {
                if (uVar4 < uVar5) {
                  uVar5 = uVar4;
                }
                if (uVar9 <= uVar8) {
                  uVar9 = uVar8;
                }
                uVar3 = FUN_00b2b850(param_5,uVar9,uVar5);
                if ((int)uVar3 != 0) {
                  return uVar3;
                }
              }
              iVar6 = iVar6 + 1;
              if (iVar6 == local_54) break;
              uVar9 = local_50[(uint)(iVar6 * 2)];
              uVar5 = local_50[iVar6 * 2 + 1];
            } while (uVar9 <= uVar4);
          }
        }
        local_58 = local_58 + 1;
        if (local_58 == iVar10) {
          return 0;
        }
      } while( true );
    }
  }
  else {
    puVar11 = local_50;
    iVar6 = local_54;
    local_54 = iVar10;
    local_50 = puVar7;
    if (param_4 != 0) {
      return 0;
    }
  }
  if (iVar6 != 0) {
    iVar10 = 0;
    do {
      uVar8 = puVar11[(uint)(iVar10 * 2)];
      uVar4 = puVar11[iVar10 * 2 + 1];
      puVar7 = local_50;
      if (0 < local_54) {
        do {
          uVar9 = *puVar7;
          uVar5 = puVar7[1];
          if (uVar9 < uVar8) {
            if (uVar8 <= uVar5) goto LAB_00b2c7dd;
          }
          else {
            if (uVar4 < uVar9) goto LAB_00b2c804;
            uVar2 = uVar9 - 1;
            if (uVar5 < uVar4) {
              if ((uVar8 <= uVar9 - 1) && (uVar3 = FUN_00b2b850(param_5), (int)uVar3 != 0)) {
                return uVar3;
              }
LAB_00b2c7dd:
              uVar8 = uVar5 + 1;
              uVar2 = uVar4;
            }
            uVar4 = uVar2;
            if (uVar4 < uVar8) goto LAB_00b2c804;
          }
          puVar7 = puVar7 + 2;
        } while (local_50 + (ulong)(local_54 - 1) * 2 + 2 != puVar7);
      }
      if ((uVar8 <= uVar4) && (uVar3 = FUN_00b2b850(param_5,uVar8,uVar4), (int)uVar3 != 0)) {
        return uVar3;
      }
LAB_00b2c804:
      iVar10 = iVar10 + 1;
    } while (iVar10 != iVar6);
  }
  return 0;
}


// ==== entry=00b2c9b0 name=FUN_00b2c9b0 size=406 ====

int FUN_00b2c9b0(long param_1,long param_2,long param_3)

{
  uint uVar1;
  uint uVar2;
  undefined8 uVar3;
  int iVar4;
  long lVar5;
  uint *puVar6;
  uint uVar7;
  uint *puVar8;
  undefined8 uVar9;
  uint uVar10;
  uint *puVar11;
  undefined8 local_78;
  undefined8 local_70;
  uint local_68 [8];
  uint local_48 [8];
  
  puVar6 = (uint *)(param_1 + 8);
  puVar11 = (uint *)(param_2 + 8);
  uVar1 = *(uint *)(param_1 + 4);
  uVar2 = *(uint *)(param_2 + 4);
  uVar3 = *(undefined8 *)(param_1 + 0x28);
  local_78 = 0;
  uVar9 = *(undefined8 *)(param_2 + 0x28);
  uVar7 = uVar2 & 1;
  uVar10 = uVar1 & 1;
  puVar8 = puVar6;
  if (uVar10 != 0) {
    lVar5 = 0;
    do {
      *(uint *)((long)local_68 + lVar5) = ~*(uint *)(param_1 + 8 + lVar5);
      lVar5 = lVar5 + 4;
    } while (lVar5 != 0x20);
    puVar8 = local_68;
  }
  if (uVar7 != 0) {
    lVar5 = 0;
    do {
      *(uint *)((long)local_48 + lVar5) = ~*(uint *)(param_2 + 8 + lVar5);
      lVar5 = lVar5 + 4;
    } while (lVar5 != 0x20);
    puVar11 = local_48;
  }
  lVar5 = 0;
  do {
    *(uint *)((long)puVar8 + lVar5) =
         *(uint *)((long)puVar8 + lVar5) & *(uint *)((long)puVar11 + lVar5);
    lVar5 = lVar5 + 4;
  } while (lVar5 != 0x20);
  lVar5 = 0;
  if (puVar8 != puVar6) {
    do {
      *(undefined4 *)(param_1 + 8 + lVar5) = *(undefined4 *)((long)puVar8 + lVar5);
      lVar5 = lVar5 + 4;
    } while (lVar5 != 0x20);
  }
  if (uVar10 == 0) {
    if (*(int *)(param_3 + 0x18) == 1) {
      return 0;
    }
  }
  else {
    do {
      *puVar6 = ~*puVar6;
      puVar6 = puVar6 + 1;
    } while ((uint *)(param_1 + 0x28) != puVar6);
    if (*(int *)(param_3 + 0x18) == 1) {
      return 0;
    }
    if ((uVar2 & uVar1 & 1) != 0) {
      iVar4 = FUN_00b2c600(param_3,uVar3,0,uVar9,0,&local_78);
      goto LAB_00b2cab7;
    }
  }
  iVar4 = FUN_00b2c740(uVar3,uVar10,uVar9,uVar7,&local_78);
  if ((iVar4 == 0) && ((uVar1 & 1) != 0)) {
    local_70 = 0;
    iVar4 = FUN_00b2c310(*(undefined4 *)(param_3 + 0x1c),local_78,&local_70);
    FUN_00b2b700(local_78);
    local_78 = local_70;
  }
LAB_00b2cab7:
  uVar9 = local_78;
  if (iVar4 == 0) {
    *(undefined8 *)(param_1 + 0x28) = local_78;
    uVar9 = uVar3;
  }
  FUN_00b2b700(uVar9);
  return iVar4;
}


// ==== entry=00b2cb60 name=FUN_00b2cb60 size=410 ====

int FUN_00b2cb60(long param_1,long param_2,long param_3)

{
  uint uVar1;
  uint uVar2;
  undefined8 uVar3;
  int iVar4;
  long lVar5;
  uint *puVar6;
  uint *puVar7;
  undefined8 uVar8;
  uint uVar9;
  uint uVar10;
  uint *puVar11;
  undefined8 local_78;
  undefined8 local_70;
  uint local_68 [8];
  uint local_48 [8];
  
  puVar11 = (uint *)(param_2 + 8);
  puVar7 = (uint *)(param_1 + 8);
  uVar1 = *(uint *)(param_1 + 4);
  uVar2 = *(uint *)(param_2 + 4);
  uVar3 = *(undefined8 *)(param_1 + 0x28);
  uVar8 = *(undefined8 *)(param_2 + 0x28);
  local_78 = 0;
  uVar9 = uVar2 & 1;
  uVar10 = uVar1 & 1;
  puVar6 = puVar7;
  if (uVar10 != 0) {
    lVar5 = 0;
    do {
      *(uint *)((long)local_68 + lVar5) = ~*(uint *)(param_1 + 8 + lVar5);
      lVar5 = lVar5 + 4;
    } while (lVar5 != 0x20);
    puVar6 = local_68;
  }
  if (uVar9 != 0) {
    lVar5 = 0;
    do {
      *(uint *)((long)local_48 + lVar5) = ~*(uint *)(param_2 + 8 + lVar5);
      lVar5 = lVar5 + 4;
    } while (lVar5 != 0x20);
    puVar11 = local_48;
  }
  lVar5 = 0;
  do {
    *(uint *)((long)puVar6 + lVar5) =
         *(uint *)((long)puVar6 + lVar5) | *(uint *)((long)puVar11 + lVar5);
    lVar5 = lVar5 + 4;
  } while (lVar5 != 0x20);
  lVar5 = 0;
  if (puVar6 != puVar7) {
    do {
      *(undefined4 *)(param_1 + 8 + lVar5) = *(undefined4 *)((long)puVar6 + lVar5);
      lVar5 = lVar5 + 4;
    } while (lVar5 != 0x20);
  }
  if (uVar10 == 0) {
    if (*(int *)(param_3 + 0x18) == 1) {
      return 0;
    }
  }
  else {
    do {
      *puVar7 = ~*puVar7;
      puVar7 = puVar7 + 1;
    } while ((uint *)(param_1 + 0x28) != puVar7);
    if (*(int *)(param_3 + 0x18) == 1) {
      return 0;
    }
    if ((uVar2 & uVar1 & 1) != 0) {
      iVar4 = FUN_00b2c740(uVar3,0,uVar8,0,&local_78);
      goto LAB_00b2cc62;
    }
  }
  iVar4 = FUN_00b2c600(param_3,uVar3,uVar10,uVar8,uVar9,&local_78);
  if ((iVar4 == 0) && ((uVar1 & 1) != 0)) {
    local_70 = 0;
    iVar4 = FUN_00b2c310(*(undefined4 *)(param_3 + 0x1c),local_78,&local_70);
    FUN_00b2b700(local_78);
    local_78 = local_70;
  }
LAB_00b2cc62:
  uVar8 = local_78;
  if (iVar4 == 0) {
    *(undefined8 *)(param_1 + 0x28) = local_78;
    uVar8 = uVar3;
  }
  FUN_00b2b700(uVar8);
  return iVar4;
}


// ==== entry=00b2cd10 name=FUN_00b2cd10 size=1073 ====

ulong FUN_00b2cd10(long param_1,uint param_2,int param_3,int param_4,uint param_5,long *param_6)

{
  uint *puVar1;
  long lVar2;
  bool bVar3;
  int iVar4;
  int iVar5;
  ulong uVar6;
  int iVar7;
  undefined4 local_a4;
  undefined8 local_a0;
  undefined1 local_98 [4];
  undefined4 local_94;
  undefined8 local_90;
  undefined8 local_88;
  undefined8 local_80;
  undefined8 local_78;
  long local_70;
  undefined1 local_68 [4];
  undefined4 local_64;
  uint local_60 [8];
  long local_40 [2];
  
  lVar2 = *param_6;
  if (((param_5 & 0x1000) == 0) || (param_4 != 0)) {
    uVar6 = (**(code **)(lVar2 + 0x80))(param_2,&local_a4,&local_a0);
    if ((int)uVar6 == 0) {
      uVar6 = FUN_00b2c3c0(param_1,param_3,local_a4,local_a0);
      return uVar6;
    }
    if ((int)uVar6 != -2) {
      return uVar6;
    }
    bVar3 = false;
    iVar7 = 0x100;
  }
  else {
    uVar6 = (**(code **)(lVar2 + 0x80))(param_2,&local_a4,&local_a0);
    if ((int)uVar6 == 0) {
      local_94 = 0;
      local_90 = 0;
      local_88 = 0;
      local_80 = 0;
      local_78 = 0;
      local_70 = 0;
      uVar6 = FUN_00b2c3c0(local_98,param_3,local_a4,local_a0);
      if ((int)uVar6 != 0) {
        return uVar6;
      }
      if (param_3 == 0) {
        local_64 = 0;
        local_60[0] = 0;
        local_60[1] = 0;
        local_60[2] = 0;
        local_60[3] = 0;
        local_60[4] = 0;
        local_60[5] = 0;
        local_60[6] = 0;
        local_60[7] = 0;
        local_40[0] = 0;
        if (*(int *)(*param_6 + 0x1c) < 2) {
          iVar7 = 0;
          do {
            iVar4 = iVar7 + 1;
            local_60[iVar7 >> 5] = local_60[iVar7 >> 5] | 1 << ((byte)iVar7 & 0x1f);
            iVar7 = iVar4;
          } while (iVar4 != 0x80);
        }
        else {
          FUN_00b2b850(local_40,0,0x7f);
        }
        uVar6 = FUN_00b2c9b0(local_98,local_68,lVar2);
        if (local_40[0] != 0) {
          FUN_00b2b700();
          uVar6 = uVar6 & 0xffffffff;
        }
      }
      else {
        uVar6 = FUN_00b2b850(&local_70,0x80,0xffffffff);
      }
      if ((int)uVar6 == 0) {
        uVar6 = FUN_00b2cb60(param_1,local_98,lVar2);
      }
      if (local_70 != 0) {
        FUN_00b2b700();
        return uVar6 & 0xffffffff;
      }
      return uVar6;
    }
    if ((int)uVar6 != -2) {
      return uVar6;
    }
    bVar3 = true;
    iVar7 = 0x80;
  }
  if (0xe < param_2) {
    return 0xfffffff5;
  }
  uVar6 = 1L << ((byte)param_2 & 0x3f);
  if ((uVar6 & 0x6f5e) != 0) {
    iVar7 = 0;
    if (param_3 == 0) {
      do {
        iVar4 = (**(code **)(lVar2 + 0x78))(iVar7,param_2);
        if (iVar4 != 0) {
          puVar1 = (uint *)(param_1 + 8 + (long)(iVar7 >> 5) * 4);
          *puVar1 = *puVar1 | 1 << ((byte)iVar7 & 0x1f);
        }
        iVar7 = iVar7 + 1;
      } while (iVar7 != 0x100);
      return 0;
    }
    iVar7 = 0;
    do {
      iVar4 = (**(code **)(lVar2 + 0x78))(iVar7,param_2);
      if (iVar4 == 0) {
        puVar1 = (uint *)(param_1 + 8 + (long)(iVar7 >> 5) * 4);
        *puVar1 = *puVar1 | 1 << ((byte)iVar7 & 0x1f);
      }
      iVar7 = iVar7 + 1;
    } while (iVar7 != 0x100);
    goto LAB_00b2cdde;
  }
  if ((uVar6 & 0xa0) == 0) {
    if ((uVar6 & 0x1000) == 0) {
      return 0xfffffff5;
    }
    if (param_3 == 0) {
      iVar4 = 0;
      do {
        iVar5 = (**(code **)(lVar2 + 0x78))(iVar4,0xc);
        if (iVar5 != 0) {
          puVar1 = (uint *)(param_1 + 8 + (long)(iVar4 >> 5) * 4);
          *puVar1 = *puVar1 | 1 << ((byte)iVar4 & 0x1f);
        }
        iVar4 = iVar4 + 1;
      } while (iVar7 != iVar4);
LAB_00b2d09a:
      if (bVar3) {
        return 0;
      }
      goto LAB_00b2cdde;
    }
    iVar4 = 0;
    do {
      iVar5 = (**(code **)(lVar2 + 0x40))(iVar4);
      if ((0 < iVar5) &&
         ((iVar5 = (**(code **)(lVar2 + 0x78))(iVar4,0xc), iVar5 == 0 || (iVar7 <= iVar4)))) {
        puVar1 = (uint *)(param_1 + 8 + (long)(iVar4 >> 5) * 4);
        *puVar1 = *puVar1 | 1 << ((byte)iVar4 & 0x1f);
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 != 0x100);
  }
  else {
    iVar4 = 0;
    if (param_3 == 0) {
      do {
        iVar5 = (**(code **)(lVar2 + 0x78))(iVar4,param_2);
        if (iVar5 != 0) {
          puVar1 = (uint *)(param_1 + 8 + (long)(iVar4 >> 5) * 4);
          *puVar1 = *puVar1 | 1 << ((byte)iVar4 & 0x1f);
        }
        iVar4 = iVar4 + 1;
      } while (iVar7 != iVar4);
      goto LAB_00b2d09a;
    }
    iVar4 = 0;
    do {
      iVar5 = (**(code **)(lVar2 + 0x78))(iVar4,param_2);
      if ((iVar5 == 0) || (iVar7 <= iVar4)) {
        puVar1 = (uint *)(param_1 + 8 + (long)(iVar4 >> 5) * 4);
        *puVar1 = *puVar1 | 1 << ((byte)iVar4 & 0x1f);
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 != 0x100);
  }
  if (!bVar3) {
    return 0;
  }
LAB_00b2cdde:
  if (*(int *)(lVar2 + 0x18) == 1) {
    return 0;
  }
  uVar6 = FUN_00b2b850(param_1 + 0x28,(ulong)(*(int *)(lVar2 + 0x1c) < 2) << 7,0xffffffff);
  return uVar6;
}


// ==== entry=00b2d150 name=FUN_00b2d150 size=1860 ====

ulong FUN_00b2d150(uint *param_1,ulong *param_2,ulong param_3,long param_4)

{
  uint *puVar1;
  undefined8 *puVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  ulong uVar7;
  ulong uVar8;
  ulong uVar9;
  ulong local_60;
  ulong local_40 [2];
  
  local_40[0] = *param_2;
  puVar1 = *(uint **)(param_4 + 0x10);
  puVar2 = *(undefined8 **)(param_4 + 8);
  if (param_3 <= local_40[0]) {
    *param_1 = 0;
    return 0;
  }
  uVar3 = (*(code *)puVar2[6])(local_40[0],param_3);
  iVar4 = (*(code *)*puVar2)(local_40[0]);
  param_1[6] = uVar3;
  local_40[0] = (long)iVar4 + local_40[0];
  param_1[0] = 2;
  param_1[1] = 0;
  param_1[2] = 0;
  if (uVar3 == 0x5d) {
    *param_1 = 0x16;
    uVar7 = 0x16;
    goto LAB_00b2d22c;
  }
  if (uVar3 == 0x2d) {
    *param_1 = 0x17;
    uVar7 = 0x17;
    goto LAB_00b2d22c;
  }
  if (puVar1[4] != uVar3) {
    if (uVar3 == 0x5b) {
      uVar7 = local_40[0];
      if ((((*puVar1 & 0x1000000) != 0) && (local_40[0] < param_3)) &&
         (iVar4 = (*(code *)puVar2[6])(local_40[0],param_3), uVar7 = local_40[0], iVar4 == 0x3a)) {
        *(ulong *)(param_1 + 4) = local_40[0];
        iVar4 = (*(code *)*puVar2)(local_40[0]);
        local_60 = (long)iVar4 + local_40[0];
        local_40[0] = local_60;
joined_r0x00b2d33a:
        if (local_60 < param_3) {
          do {
            iVar4 = (*(code *)puVar2[6])(local_60,param_3);
            iVar5 = (*(code *)*puVar2)(local_60);
            uVar9 = (long)iVar5 + local_60;
            if (iVar4 == 0x3a) {
              if ((uVar9 < param_3) && (iVar4 = (*(code *)puVar2[6])(uVar9,param_3), iVar4 == 0x5d))
              {
                (*(code *)*puVar2)(uVar9);
                *param_1 = 0x18;
                uVar7 = 0x18;
                goto LAB_00b2d22c;
              }
              iVar4 = (*(code *)*puVar2)(local_60);
              local_60 = (long)iVar4 + local_60;
            }
            else {
              uVar3 = (*(code *)puVar2[6])(local_60,param_3);
              if (uVar3 == 0x5d) break;
              local_60 = uVar9;
              if (uVar3 == puVar1[4]) goto LAB_00b2d398;
            }
            if (param_3 <= local_60) break;
          } while( true );
        }
      }
LAB_00b2d3c0:
      local_40[0] = uVar7;
      if ((puVar1[1] & 0x40) == 0) {
        FUN_00b2c2a0(param_4,&DAT_00ca96d5);
        uVar7 = (ulong)*param_1;
      }
      else {
        *param_1 = 0x1a;
        uVar7 = 0x1a;
      }
      goto LAB_00b2d22c;
    }
    uVar7 = 2;
    if (uVar3 != 0x26) goto LAB_00b2d22c;
    if (((puVar1[1] & 0x40) != 0) && (local_40[0] < param_3)) {
      iVar4 = (*(code *)puVar2[6])(local_40[0],param_3);
      uVar9 = local_40[0];
      if (iVar4 == 0x26) {
        iVar4 = (*(code *)*puVar2)(local_40[0]);
        *param_1 = 0x19;
        uVar7 = 0x19;
        local_40[0] = (long)iVar4 + local_40[0];
        goto LAB_00b2d22c;
      }
      goto LAB_00b2d215;
    }
LAB_00b2d2d8:
    uVar7 = 2;
    goto LAB_00b2d22c;
  }
  if ((*(byte *)((long)puVar1 + 10) & 0x20) == 0) goto LAB_00b2d2d8;
  if (param_3 <= local_40[0]) {
    return 0xffffff98;
  }
  uVar3 = (*(code *)puVar2[6])(local_40[0],param_3);
  uVar7 = local_40[0];
  iVar4 = (*(code *)*puVar2)(local_40[0]);
  param_1[1] = 1;
  uVar8 = (long)iVar4 + local_40[0];
  param_1[6] = uVar3;
  local_40[0] = uVar8;
  uVar9 = uVar8;
  switch(uVar3) {
  case 0x30:
  case 0x31:
  case 0x32:
  case 0x33:
  case 0x34:
  case 0x35:
  case 0x36:
  case 0x37:
    if ((*puVar1 & 0x10000000) != 0) {
      local_40[0] = uVar7;
      uVar3 = FUN_00b2b4a0(local_40,param_3,3,puVar2);
      if ((int)uVar3 < 0) {
        return 0xffffff38;
      }
      *param_1 = 1;
      param_1[2] = 8;
      if (local_40[0] == uVar7) {
        uVar3 = 0;
      }
      param_1[6] = uVar3;
      uVar7 = 1;
      goto LAB_00b2d22c;
    }
    break;
  default:
    local_40[0] = uVar7;
    uVar7 = FUN_00b2bd10(local_40,param_3,param_4);
    uVar3 = (uint)uVar7;
    if ((int)uVar3 < 0) {
      return uVar7;
    }
    uVar9 = local_40[0];
    if (param_1[6] != uVar3) {
      param_1[6] = uVar3;
      uVar7 = 4;
      *param_1 = 4;
      goto LAB_00b2d22c;
    }
    break;
  case 0x44:
    *param_1 = 6;
    param_1[6] = 4;
    param_1[7] = 1;
    uVar7 = 6;
    goto LAB_00b2d22c;
  case 0x48:
    if ((*(byte *)((long)puVar1 + 6) & 8) != 0) {
      *param_1 = 6;
      param_1[6] = 0xb;
      param_1[7] = 1;
      uVar7 = 6;
      goto LAB_00b2d22c;
    }
    break;
  case 0x50:
  case 0x70:
    if (((uVar8 < param_3) &&
        (iVar4 = (*(code *)puVar2[6])(uVar8,param_3), uVar9 = local_40[0], iVar4 == 0x7b)) &&
       ((*(byte *)((long)puVar1 + 6) & 1) != 0)) {
      iVar4 = (*(code *)*puVar2)(local_40[0]);
      *param_1 = 0x12;
      local_40[0] = (long)iVar4 + local_40[0];
      param_1[7] = (uint)(uVar3 == 0x50);
      uVar7 = 0x12;
      if ((*(byte *)((long)puVar1 + 6) & 2) != 0) {
        iVar4 = (*(code *)puVar2[6])(local_40[0],param_3);
        uVar9 = local_40[0];
        iVar5 = (*(code *)*puVar2)(local_40[0]);
        if (iVar4 == 0x5e) {
          param_1[7] = (uint)(param_1[7] == 0);
          uVar7 = (ulong)*param_1;
          local_40[0] = (long)iVar5 + local_40[0];
        }
        else {
          uVar7 = (ulong)*param_1;
          local_40[0] = uVar9;
        }
      }
      goto LAB_00b2d22c;
    }
    break;
  case 0x53:
    *param_1 = 6;
    param_1[6] = 9;
    param_1[7] = 1;
    uVar7 = 6;
    goto LAB_00b2d22c;
  case 0x57:
    *param_1 = 6;
    param_1[6] = 0xc;
    param_1[7] = 1;
    uVar7 = 6;
    goto LAB_00b2d22c;
  case 100:
    *param_1 = 6;
    uVar7 = 6;
    param_1[6] = 4;
    param_1[7] = 0;
    goto LAB_00b2d22c;
  case 0x68:
    if ((*(byte *)((long)puVar1 + 6) & 8) != 0) {
      *param_1 = 6;
      uVar7 = 6;
      param_1[6] = 0xb;
      param_1[7] = 0;
      goto LAB_00b2d22c;
    }
    break;
  case 0x73:
    *param_1 = 6;
    uVar7 = 6;
    param_1[6] = 9;
    param_1[7] = 0;
    goto LAB_00b2d22c;
  case 0x75:
    if ((uVar8 < param_3) && ((*(byte *)((long)puVar1 + 5) & 0x40) != 0)) {
      uVar3 = FUN_00b2b320(local_40,param_3,4,4,puVar2);
      if ((int)uVar3 < -1) {
        return 0xffffff2e;
      }
      if (uVar3 == 0xffffffff) {
        return 0xffffff38;
      }
      *param_1 = 4;
      param_1[2] = 0x10;
      if (uVar8 == local_40[0]) {
        uVar3 = 0;
      }
      param_1[6] = uVar3;
      uVar7 = 4;
      goto LAB_00b2d22c;
    }
    break;
  case 0x77:
    *param_1 = 6;
    uVar7 = 6;
    param_1[6] = 0xc;
    param_1[7] = 0;
    goto LAB_00b2d22c;
  case 0x78:
    if (uVar8 < param_3) {
      iVar4 = (*(code *)puVar2[6])(uVar8,param_3);
      if ((iVar4 == 0x7b) && ((*puVar1 & 0x40000000) != 0)) {
        iVar4 = (*(code *)*puVar2)(local_40[0]);
        local_40[0] = local_40[0] + (long)iVar4;
        uVar3 = FUN_00b2b320(local_40,param_3,0,8,puVar2);
        if ((int)uVar3 < 0) {
          return 0xfffffe6f;
        }
        if (local_40[0] < param_3) {
          uVar6 = (*(code *)puVar2[6])(local_40[0],param_3);
          iVar4 = (*(code *)puVar2[0xf])(uVar6,0xb);
          if (iVar4 != 0) {
            return 0xffffff2c;
          }
        }
        iVar4 = (*(code *)*puVar2)(uVar8);
        if ((((long)iVar4 + uVar8 < local_40[0]) && (local_40[0] < param_3)) &&
           (iVar4 = (*(code *)puVar2[6])(local_40[0],param_3), iVar4 == 0x7d)) {
          iVar4 = (*(code *)*puVar2)(local_40[0]);
          *param_1 = 4;
          param_1[2] = 0x10;
          uVar7 = 4;
          param_1[6] = uVar3;
          local_40[0] = (long)iVar4 + local_40[0];
          goto LAB_00b2d22c;
        }
      }
      else {
        uVar9 = local_40[0];
        if ((*puVar1 & 0x20000000) != 0) {
          uVar3 = FUN_00b2b320(local_40,param_3,0,2,puVar2);
          if ((int)uVar3 < 0) {
            return 0xffffff38;
          }
          *param_1 = 1;
          param_1[2] = 0x10;
          if (uVar8 == local_40[0]) {
            uVar3 = 0;
          }
          param_1[6] = uVar3;
          uVar7 = 1;
          goto LAB_00b2d22c;
        }
      }
    }
  }
LAB_00b2d215:
  uVar7 = (ulong)*param_1;
  local_40[0] = uVar9;
LAB_00b2d22c:
  *param_2 = local_40[0];
  return uVar7;
LAB_00b2d398:
  if (param_3 <= uVar9) goto LAB_00b2d3c0;
  iVar4 = (*(code *)*puVar2)(uVar9);
  local_60 = (long)iVar4 + uVar9;
  goto joined_r0x00b2d33a;
}


// ==== entry=00b2d8d0 name=FUN_00b2d8d0 size=180 ====

void FUN_00b2d8d0(undefined8 *param_1)

{
  long lVar1;
  undefined8 *puVar2;
  
  if (param_1 == (undefined8 *)0x0) {
    return;
  }
LAB_00b2d8dd:
  switch(*(undefined4 *)param_1) {
  case 0:
    if (((*(int *)((long)param_1 + 0x1c) == 0) ||
        (puVar2 = (undefined8 *)param_1[1], puVar2 == (undefined8 *)0x0)) || (puVar2 == param_1 + 4)
       ) goto switchD_00b2d8e4_caseD_2;
    break;
  case 1:
    if ((*(byte *)((long)param_1 + 4) & 2) != 0) {
      return;
    }
    if (param_1[5] != 0) {
      FUN_00b2b700();
    }
  default:
    goto switchD_00b2d8e4_caseD_2;
  case 4:
    puVar2 = (undefined8 *)param_1[5];
    if (puVar2 == (undefined8 *)0x0) goto switchD_00b2d8e4_caseD_2;
    break;
  case 5:
  case 7:
    lVar1 = param_1[1];
    goto joined_r0x00b2d937;
  case 6:
    lVar1 = param_1[3];
joined_r0x00b2d937:
    if (lVar1 != 0) {
      FUN_00b2d8d0();
    }
    goto switchD_00b2d8e4_caseD_2;
  case 8:
  case 9:
    goto switchD_00b2d8e4_caseD_8;
  }
  free(puVar2);
switchD_00b2d8e4_caseD_2:
  puVar2 = param_1;
  *param_1 = DAT_011c3818;
  DAT_011c3818 = puVar2;
  return;
switchD_00b2d8e4_caseD_8:
  FUN_00b2d8d0(param_1[1]);
  puVar2 = param_1;
  *param_1 = DAT_011c3818;
  DAT_011c3818 = puVar2;
  param_1 = (undefined8 *)param_1[2];
  if (param_1 == (undefined8 *)0x0) {
    return;
  }
  goto LAB_00b2d8dd;
}


// ==== entry=00b2d9c0 name=FUN_00b2d9c0 size=512 ====

undefined8
FUN_00b2d9c0(long param_1,uint *param_2,uint param_3,undefined4 *param_4,undefined4 param_5,
            int param_6,int *param_7,uint *param_8,long param_9)

{
  uint *puVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  undefined8 uVar5;
  byte bVar6;
  uint uVar7;
  uint uVar8;
  
  uVar7 = *param_8;
  if (uVar7 != 1) {
    if (uVar7 == 0) {
      if (*param_7 == 0) {
        uVar7 = *param_2;
        uVar2 = uVar7 + 0x1f;
        if (-1 < (int)uVar7) {
          uVar2 = uVar7;
        }
        bVar6 = (byte)((int)uVar7 >> 0x1f);
        puVar1 = (uint *)(param_1 + 8 + (long)((int)uVar2 >> 5) * 4);
        *puVar1 = *puVar1 | 1 << (((char)uVar7 + (bVar6 >> 3) & 0x1f) - (bVar6 >> 3) & 0x1f);
      }
      else if ((*param_7 == 1) &&
              (uVar5 = FUN_00b2b850(param_1 + 0x28,*param_2,*param_2), (int)uVar5 < 0)) {
        return uVar5;
      }
    }
    else if (uVar7 < 4) {
      *param_8 = 0;
    }
    goto LAB_00b2d9fc;
  }
  uVar7 = *param_2;
  if (*param_7 == param_6) {
    if (param_6 == 0) {
      if ((0xff < uVar7) || (0xff < param_3)) {
        return 0xfffffe70;
      }
      if (uVar7 <= param_3) {
        if ((int)uVar7 <= (int)param_3) {
          do {
            iVar4 = (int)uVar7 >> 5;
            bVar6 = (byte)uVar7;
            uVar7 = uVar7 + 1;
            puVar1 = (uint *)(param_1 + 8 + (long)iVar4 * 4);
            *puVar1 = *puVar1 | 1 << (bVar6 & 0x1f);
          } while (param_3 + 1 != uVar7);
        }
        goto LAB_00b2daaa;
      }
    }
    else if (uVar7 <= param_3) goto LAB_00b2dba8;
LAB_00b2da97:
    if ((*(byte *)(*(long *)(param_9 + 0x10) + 10) & 0x40) == 0) {
      return 0xffffff35;
    }
  }
  else {
    if (param_3 < uVar7) goto LAB_00b2da97;
    uVar2 = 0xff;
    if (param_3 < 0xff) {
      uVar2 = param_3;
    }
    if ((int)uVar7 <= (int)uVar2) {
      do {
        uVar3 = uVar7 + 0x1f;
        if (-1 < (int)uVar7) {
          uVar3 = uVar7;
        }
        uVar8 = uVar7 + 1;
        puVar1 = (uint *)(param_1 + 8 + (long)((int)uVar3 >> 5) * 4);
        *puVar1 = *puVar1 | 1 << ((byte)((int)uVar7 % 0x20) & 0x1f);
        uVar7 = uVar8;
      } while (uVar8 != uVar2 + 1);
      uVar7 = *param_2;
      if (param_3 < uVar7) goto LAB_00b2da97;
    }
LAB_00b2dba8:
    uVar5 = FUN_00b2b850(param_1 + 0x28,uVar7,param_3);
    if ((int)uVar5 < 0) {
      return uVar5;
    }
  }
LAB_00b2daaa:
  *param_8 = 2;
LAB_00b2d9fc:
  *param_4 = param_5;
  *param_2 = param_3;
  *param_7 = param_6;
  return 0;
}


// ==== entry=00b2dbf0 name=FUN_00b2dbf0 size=2887 ====

int FUN_00b2dbf0(long *param_1,int *param_2,ulong *param_3,ulong param_4,uint *param_5)

{
  int iVar1;
  byte bVar2;
  bool bVar3;
  bool bVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  long lVar8;
  undefined8 *puVar9;
  int *piVar10;
  char *pcVar11;
  undefined8 uVar12;
  int iVar13;
  undefined **ppuVar14;
  int iVar15;
  ulong uVar16;
  ulong uVar17;
  long lVar18;
  bool bVar19;
  undefined1 *local_d0;
  undefined1 *local_b8;
  undefined8 local_a8;
  int local_88;
  int local_84;
  int local_80;
  undefined1 local_7c [4];
  ulong local_78;
  byte local_70;
  undefined1 auStack_6f [7];
  undefined1 local_68 [56];
  
  *param_1 = 0;
  iVar5 = FUN_00b2d150(param_2,param_3,param_4,param_5);
  bVar3 = false;
  if (iVar5 == 2) {
    if ((param_2[6] == 0x5e) && (param_2[1] == 0)) {
      iVar5 = FUN_00b2d150(param_2,param_3,param_4,param_5);
      bVar3 = true;
      goto LAB_00b2dc3f;
    }
  }
  else {
LAB_00b2dc3f:
    if (iVar5 < 0) {
      return iVar5;
    }
    if (iVar5 == 0x16) {
      uVar17 = *(ulong *)(param_5 + 0xc);
      puVar9 = *(undefined8 **)(param_5 + 2);
      uVar16 = *param_3;
      do {
        if (uVar17 <= uVar16) {
          return -0x66;
        }
        iVar5 = (*(code *)puVar9[6])(uVar16,uVar17);
        iVar6 = (*(code *)*puVar9)(uVar16);
        uVar16 = uVar16 + (long)iVar6;
      } while (iVar5 != 0x5d);
      iVar5 = 2;
      FUN_00b2c2a0(param_5,&DAT_00ca3c6b);
      *param_2 = 2;
    }
  }
  local_d0 = (undefined1 *)FUN_00b2c180();
  *param_1 = (long)local_d0;
  if (local_d0 == (undefined1 *)0x0) {
    return -5;
  }
  local_84 = 3;
  local_78 = *param_3;
  if (iVar5 == 0x16) goto LAB_00b2dde3;
  bVar4 = false;
  local_b8 = (undefined1 *)0x0;
LAB_00b2dd0f:
  uVar17 = local_78;
  switch(iVar5) {
  case 0:
    iVar6 = -0x67;
    goto LAB_00b2de7d;
  case 1:
    puVar9 = *(undefined8 **)(param_5 + 2);
    iVar6 = param_2[6];
    if ((*(int *)(puVar9 + 3) == 1) || (iVar1 = param_2[2], iVar1 == 0)) {
      uVar12 = 0;
      goto LAB_00b2e0c2;
    }
    local_70 = (byte)iVar6;
    if (*(int *)(puVar9 + 3) < 2) {
      iVar15 = iVar5;
      iVar13 = 0;
    }
    else {
      lVar8 = 1;
      do {
        iVar15 = (int)lVar8;
        iVar6 = FUN_00b2d150(param_2,&local_78,param_4,param_5);
        if (iVar6 < 0) goto LAB_00b2de7d;
        puVar9 = *(undefined8 **)(param_5 + 2);
        iVar13 = iVar5;
        if (iVar6 != 1) goto LAB_00b2e635;
        if (iVar1 != param_2[2]) {
          iVar13 = 1;
          goto LAB_00b2e635;
        }
        lVar18 = lVar8 + 1;
        auStack_6f[lVar8 + -1] = (char)param_2[6];
        lVar8 = lVar18;
      } while ((int)lVar18 < *(int *)(puVar9 + 3));
      iVar15 = iVar15 + 1;
      iVar13 = 0;
    }
LAB_00b2e635:
    if ((iVar15 < *(int *)((long)puVar9 + 0x1c)) ||
       (iVar6 = (*(code *)*puVar9)(&local_70), iVar15 < iVar6)) {
      iVar6 = -0xce;
      goto LAB_00b2de7d;
    }
    if (iVar6 < iVar15) {
      local_78 = uVar17;
      if (iVar6 < 2) {
        iVar13 = 0;
        goto LAB_00b2e740;
      }
      iVar13 = iVar5;
      do {
        FUN_00b2d150(param_2,&local_78,param_4,param_5);
        iVar13 = iVar13 + 1;
      } while (iVar6 != iVar13);
      iVar13 = 0;
LAB_00b2e662:
      uVar7 = (**(code **)(*(long *)(param_5 + 2) + 0x30))(&local_70,auStack_6f + 6);
      bVar19 = true;
    }
    else {
      if (iVar15 != 1) goto LAB_00b2e662;
LAB_00b2e740:
      uVar7 = (uint)local_70;
      bVar19 = false;
    }
    break;
  case 2:
    if (((uint)param_2[6] < 0x100) &&
       (iVar6 = (**(code **)(*(long *)(param_5 + 2) + 0x40))(), iVar6 < 2)) {
      if (iVar6 < 0) goto LAB_00b2de7d;
      uVar12 = 0;
    }
    else {
      uVar12 = 1;
    }
LAB_00b2e0bd:
    iVar6 = param_2[6];
    iVar5 = 0;
LAB_00b2e0c2:
    iVar6 = FUN_00b2d9c0(local_d0,&local_88,iVar6,local_7c,iVar5,uVar12,&local_80,&local_84,param_5)
    ;
    goto joined_r0x00b2e2af;
  default:
    iVar6 = -0xb;
    goto LAB_00b2de7d;
  case 4:
    uVar7 = param_2[6];
    iVar5 = 1;
    iVar13 = 0;
LAB_00b2dd34:
    iVar6 = (**(code **)(*(long *)(param_5 + 2) + 0x40))(uVar7);
    if (iVar6 < 0) goto LAB_00b2de7d;
    bVar19 = iVar6 != 1;
    break;
  case 6:
    iVar6 = param_2[7];
    iVar5 = param_2[6];
    uVar12 = 0;
    uVar7 = *param_5;
    goto LAB_00b2df89;
  case 0x12:
    iVar5 = FUN_00b2b580(&local_78,param_4,param_5);
    if (iVar5 < 0) {
      return iVar5;
    }
    iVar6 = param_2[7];
    uVar7 = *param_5;
    uVar12 = 1;
LAB_00b2df89:
    iVar5 = FUN_00b2cd10(local_d0,iVar5,iVar6,uVar12,uVar7,param_5 + 2);
    if (iVar5 != 0) {
      return iVar5;
    }
    goto LAB_00b2df9d;
  case 0x17:
    if (local_84 == 0) {
      iVar6 = FUN_00b2d150(param_2,&local_78,param_4,param_5);
      if (-1 < iVar6) {
        if (iVar6 == 0x16) {
LAB_00b2e07c:
          iVar5 = 0;
          uVar7 = 0x2d;
          iVar13 = 1;
          goto LAB_00b2dd34;
        }
        if (iVar6 == 0x19) {
LAB_00b2e06f:
          FUN_00b2c2a0(param_5,&DAT_00c9fe7e);
          goto LAB_00b2e07c;
        }
        local_84 = 1;
        goto LAB_00b2dd94;
      }
    }
    else if (local_84 == 3) {
      uVar7 = param_2[6];
      iVar6 = FUN_00b2d150(param_2,&local_78,param_4,param_5);
      if (-1 < iVar6) {
        if (iVar6 != 0x17) {
          iVar5 = 0;
          iVar13 = 1;
          if (!bVar4) goto LAB_00b2dd34;
        }
        iVar5 = 0;
        iVar13 = 1;
        FUN_00b2c2a0(param_5,&DAT_00c9fe7e);
        goto LAB_00b2dd34;
      }
    }
    else {
      if (local_84 == 1) {
        FUN_00b2c2a0(param_5,&DAT_00c9fe7e);
        uVar12 = 0;
        goto LAB_00b2e0bd;
      }
      iVar6 = FUN_00b2d150(param_2,&local_78,param_4,param_5);
      if (-1 < iVar6) {
        if (iVar6 == 0x16) goto LAB_00b2e07c;
        if ((iVar6 == 0x19) || ((*(byte *)(*(long *)(param_5 + 4) + 10) & 0x80) != 0))
        goto LAB_00b2e06f;
        iVar6 = -0x70;
      }
    }
    goto LAB_00b2de7d;
  case 0x18:
    puVar9 = *(undefined8 **)(param_5 + 2);
    if (local_78 < param_4) {
      iVar5 = (*(code *)puVar9[6])(local_78,param_4);
      if (iVar5 == 0x5e) {
        iVar5 = (*(code *)*puVar9)(uVar17);
        uVar17 = uVar17 + (long)iVar5;
        iVar5 = FUN_00b43250(puVar9,uVar17,param_4);
        if (6 < iVar5) {
          local_a8 = 1;
          goto LAB_00b2e162;
        }
LAB_00b2e508:
        if (param_4 <= uVar17) goto LAB_00b2e218;
      }
      else {
        iVar5 = FUN_00b43250(puVar9,uVar17,param_4);
        if (6 < iVar5) goto LAB_00b2e15a;
      }
      iVar5 = 0x15;
      while (iVar6 = (*(code *)puVar9[6])(uVar17,param_4), iVar6 != 0x3a) {
        if (iVar6 == 0x5d) goto LAB_00b2e218;
        iVar6 = (*(code *)*puVar9)(uVar17);
        uVar17 = uVar17 + (long)iVar6;
        iVar5 = iVar5 + -1;
        if ((iVar5 == 0) || (param_4 <= uVar17)) goto LAB_00b2e218;
      }
      iVar5 = (*(code *)*puVar9)(uVar17);
      uVar17 = uVar17 + (long)iVar5;
      if (uVar17 < param_4) {
        iVar5 = (*(code *)puVar9[6])(uVar17,param_4);
        (*(code *)*puVar9)(uVar17);
        if (iVar5 == 0x5d) goto LAB_00b2e54f;
      }
LAB_00b2e218:
      iVar5 = 0;
      iVar13 = 0;
      FUN_00b2c2a0(param_5,&DAT_00ca96d5);
      local_78 = *(ulong *)(param_2 + 4);
      uVar7 = param_2[6];
      goto LAB_00b2dd34;
    }
    iVar5 = FUN_00b43250(puVar9,local_78,param_4);
    if (iVar5 < 7) goto LAB_00b2e218;
LAB_00b2e15a:
    local_a8 = 0;
LAB_00b2e162:
    iVar5 = 5;
    pcVar11 = "alnum";
    ppuVar14 = &PTR_s_alnum_00d42da0;
    while (iVar5 = FUN_00b43d50(puVar9,uVar17,param_4,pcVar11,iVar5), iVar5 != 0) {
      pcVar11 = ppuVar14[2];
      if (pcVar11 == (char *)0x0) goto LAB_00b2e508;
      iVar5 = (int)*(short *)((long)ppuVar14 + 0x1c);
      ppuVar14 = ppuVar14 + 2;
    }
    lVar8 = FUN_00b43200(puVar9,uVar17,param_4,(int)*(short *)((long)ppuVar14 + 0xc));
    iVar5 = FUN_00b43d50(puVar9,lVar8,param_4,&DAT_00d43068,2);
    if (iVar5 != 0) {
LAB_00b2e54f:
      iVar6 = -0x79;
      goto LAB_00b2de7d;
    }
    iVar6 = FUN_00b2cd10(local_d0,*(undefined4 *)(ppuVar14 + 1),local_a8,*param_5 & 0x2000,*param_5,
                         param_5 + 2);
    if (iVar6 != 0) {
      if (-1 < iVar6) {
        if (iVar6 == 1) goto LAB_00b2e218;
        goto LAB_00b2df9d;
      }
      goto LAB_00b2de7d;
    }
    iVar5 = (*(code *)*puVar9)(lVar8);
    iVar6 = (*(code *)*puVar9)(lVar8 + iVar5);
    local_78 = lVar8 + iVar5 + (long)iVar6;
LAB_00b2df9d:
    if (local_84 != 1) {
      if ((local_84 == 0) && (local_80 != 2)) {
        if (local_80 == 0) {
          iVar5 = local_88 + 0x1f;
          if (-1 < local_88) {
            iVar5 = local_88;
          }
          bVar2 = (byte)(local_88 >> 0x1f);
          *(uint *)(local_d0 + (long)(iVar5 >> 5) * 4 + 8) =
               *(uint *)(local_d0 + (long)(iVar5 >> 5) * 4 + 8) |
               1 << (((char)local_88 + (bVar2 >> 3) & 0x1f) - (bVar2 >> 3) & 0x1f);
        }
        else if ((local_80 == 1) &&
                (iVar6 = FUN_00b2b850(local_d0 + 0x28,local_88,local_88), iVar6 < 0))
        goto LAB_00b2de7d;
      }
      local_84 = 0;
      local_80 = 2;
      goto LAB_00b2e2b5;
    }
    iVar6 = -0x6e;
    goto LAB_00b2de7d;
  case 0x19:
    if ((local_84 != 0) ||
       (iVar6 = FUN_00b2d9c0(local_d0,&local_88,0,local_7c,0,local_80,&local_80,&local_84,param_5),
       iVar6 == 0)) {
      local_84 = 3;
      if (local_b8 == (undefined1 *)0x0) {
        local_b8 = local_d0;
        local_d0 = local_68;
      }
      else {
        iVar6 = FUN_00b2c9b0(local_b8,local_d0,*(undefined8 *)(param_5 + 2));
        if (iVar6 != 0) goto LAB_00b2de7d;
        FUN_00b2b700(*(undefined8 *)(local_d0 + 0x28));
      }
      bVar4 = true;
      *(undefined4 *)(local_d0 + 4) = 0;
      *(undefined8 *)(local_d0 + 8) = 0;
      *(undefined8 *)(local_d0 + 0x10) = 0;
      *(undefined8 *)(local_d0 + 0x18) = 0;
      *(undefined8 *)(local_d0 + 0x20) = 0;
      *(undefined8 *)(local_d0 + 0x28) = 0;
      goto LAB_00b2e2b5;
    }
    goto LAB_00b2de7d;
  case 0x1a:
    iVar6 = FUN_00b2dbf0(&local_70,param_2,&local_78,param_4,param_5);
    if (iVar6 == 0) {
      iVar6 = FUN_00b2cb60(local_d0,CONCAT71(auStack_6f,local_70),*(undefined8 *)(param_5 + 2));
      FUN_00b2d8d0(CONCAT71(auStack_6f,local_70));
joined_r0x00b2e2af:
      if (iVar6 == 0) goto LAB_00b2e2b5;
    }
    else {
      FUN_00b2d8d0(CONCAT71(auStack_6f,local_70));
    }
    goto LAB_00b2de7d;
  }
  iVar6 = FUN_00b2d9c0(local_d0,&local_88,uVar7,local_7c,iVar5,bVar19,&local_80,&local_84,param_5);
  if (iVar6 != 0) goto LAB_00b2de7d;
  if (iVar13 == 0) {
LAB_00b2e2b5:
    iVar5 = FUN_00b2d150(param_2,&local_78,param_4);
    iVar6 = iVar5;
    if (iVar5 < 0) goto LAB_00b2de7d;
  }
  else {
LAB_00b2dd94:
    iVar5 = *param_2;
  }
  if (iVar5 == 0x16) goto code_r0x00b2dda0;
  goto LAB_00b2dd0f;
code_r0x00b2dda0:
  if ((local_84 == 0) &&
     (iVar6 = FUN_00b2d9c0(local_d0,&local_88,0,local_7c,0,local_80,&local_80,&local_84,param_5),
     iVar6 != 0)) {
LAB_00b2de7d:
    if ((undefined1 *)*param_1 != local_d0) {
      FUN_00b2b700(*(undefined8 *)(local_d0 + 0x28));
    }
  }
  else {
    if (local_b8 != (undefined1 *)0x0) {
      iVar6 = FUN_00b2c9b0(local_b8,local_d0,*(undefined8 *)(param_5 + 2));
      if (iVar6 != 0) goto LAB_00b2de7d;
      FUN_00b2b700(*(undefined8 *)(local_d0 + 0x28));
      local_d0 = local_b8;
    }
LAB_00b2dde3:
    if (bVar3) {
      *(uint *)(local_d0 + 4) = *(uint *)(local_d0 + 4) | 1;
      if ((*(byte *)(*(long *)(param_5 + 4) + 10) & 0x10) != 0) {
        if (*(long *)(local_d0 + 0x28) == 0) {
          piVar10 = (int *)(local_d0 + 8);
          do {
            if (*piVar10 != 0) goto LAB_00b2de18;
            piVar10 = piVar10 + 1;
          } while ((int *)(local_d0 + 0x28) != piVar10);
        }
        else {
LAB_00b2de18:
          iVar5 = (**(code **)(*(long *)(param_5 + 2) + 0x78))(10,0);
          if (iVar5 != 0) {
            iVar5 = (**(code **)(*(long *)(param_5 + 2) + 0x40))(10);
            if (iVar5 == 1) {
              *(uint *)(local_d0 + 8) = *(uint *)(local_d0 + 8) | 0x400;
            }
            else {
              iVar6 = FUN_00b2b850(local_d0 + 0x28,10,10);
              if (iVar6 < 0) goto LAB_00b2de7d;
            }
          }
        }
      }
    }
    else {
      *(uint *)(local_d0 + 4) = *(uint *)(local_d0 + 4) & 0xfffffffe;
    }
    iVar6 = 0;
    *param_3 = local_78;
  }
  return iVar6;
}


// ==== entry=00b2e7d0 name=FUN_00b2e7d0 size=8 ====

void FUN_00b2e7d0(undefined *param_1)

{
  PTR_FUN_011bec88 = param_1;
  return;
}


// ==== entry=00b2e7e0 name=FUN_00b2e7e0 size=8 ====

void FUN_00b2e7e0(undefined *param_1)

{
  PTR_FUN_011bec80 = param_1;
  return;
}


// ==== entry=00b2e7f0 name=FUN_00b2e7f0 size=33 ====

int FUN_00b2e7f0(long param_1,long param_2,int param_3)

{
  byte *pbVar1;
  byte *pbVar2;
  int iVar3;
  long lVar4;
  
  lVar4 = 0;
  do {
    if (param_3 - (int)lVar4 < 1) {
      return 0;
    }
    pbVar1 = (byte *)(param_2 + lVar4);
    pbVar2 = (byte *)(param_1 + lVar4);
    lVar4 = lVar4 + 1;
    iVar3 = (uint)*pbVar1 - (uint)*pbVar2;
  } while (iVar3 == 0);
  return iVar3;
}


// ==== entry=00b2e820 name=FUN_00b2e820 size=28 ====

void FUN_00b2e820(void *param_1,void *param_2,long param_3)

{
  void *pvVar1;
  size_t __n;
  
  __n = param_3 - (long)param_2;
  if ((long)__n < 1) {
    return;
  }
  pvVar1 = memcpy(param_1,param_2,__n);
  *(undefined1 *)((long)pvVar1 + __n) = 0;
  return;
}


// ==== entry=00b2e840 name=FUN_00b2e840 size=12 ====

void FUN_00b2e840(undefined4 param_1)

{
  FUN_00b442d0(&PTR_FUN_011bec60,param_1);
  return;
}


// ==== entry=00b2e850 name=FUN_00b2e850 size=29 ====

void FUN_00b2e850(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 local_18;
  undefined8 local_10;
  
  local_18 = param_2;
  local_10 = param_3;
  FUN_00b44420(param_1,&local_18,param_4);
  return;
}


// ==== entry=00b2e870 name=FUN_00b2e870 size=104 ====

ulong FUN_00b2e870(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 *__ptr;
  ulong uVar1;
  
  __ptr = malloc(0x10);
  *__ptr = param_2;
  __ptr[1] = param_3;
  uVar1 = FUN_00b444e0(param_1,__ptr,param_4);
  if ((int)uVar1 == 0) {
    return uVar1;
  }
  free(__ptr);
  return uVar1 & 0xffffffff;
}


// ==== entry=00b2e8e0 name=FUN_00b2e8e0 size=51 ====

undefined8 FUN_00b2e8e0(long param_1)

{
  if (*(long *)(param_1 + 0x68) != 0) {
    FUN_00b449c0(*(long *)(param_1 + 0x68),FUN_00b2b6c0,0);
    if (*(long *)(param_1 + 0x68) != 0) {
      FUN_00b443c0();
    }
  }
  *(undefined8 *)(param_1 + 0x68) = 0;
  return 0;
}


// ==== entry=00b2e920 name=FUN_00b2e920 size=71 ====

undefined4 FUN_00b2e920(long param_1,undefined8 param_2,undefined8 param_3)

{
  undefined4 uVar1;
  undefined8 local_38;
  long local_30;
  undefined8 local_28;
  undefined4 local_20;
  undefined8 local_18;
  
  local_20 = 0;
  uVar1 = 0;
  if (*(long *)(param_1 + 0x68) != 0) {
    local_18 = *(undefined8 *)(param_1 + 0x48);
    local_38 = param_2;
    local_30 = param_1;
    local_28 = param_3;
    FUN_00b449c0(*(long *)(param_1 + 0x68),FUN_00b2b2d0,&local_38);
    uVar1 = local_20;
  }
  return uVar1;
}


// ==== entry=00b2e970 name=FUN_00b2e970 size=36 ====

undefined8 FUN_00b2e970(long param_1,undefined8 param_2)

{
  if (*(long *)(param_1 + 0x68) != 0) {
    FUN_00b449c0(*(long *)(param_1 + 0x68),FUN_00b2bcd0,param_2);
    return 0;
  }
  return 0;
}


// ==== entry=00b2e9a0 name=FUN_00b2e9a0 size=15 ====

undefined4 FUN_00b2e9a0(long param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if (*(long *)(param_1 + 0x68) != 0) {
    uVar1 = *(undefined4 *)(*(long *)(param_1 + 0x68) + 0xc);
  }
  return uVar1;
}


// ==== entry=00b2e9b0 name=FUN_00b2e9b0 size=130 ====

int FUN_00b2e9b0(long param_1,undefined8 param_2,undefined8 param_3,long *param_4)

{
  int iVar1;
  long local_30;
  undefined8 local_28;
  undefined8 local_20;
  
  iVar1 = -0xd9;
  local_30 = 0;
  if (*(long *)(param_1 + 0x68) != 0) {
    local_28 = param_2;
    local_20 = param_3;
    FUN_00b44420(*(long *)(param_1 + 0x68),&local_28,&local_30);
    if (local_30 != 0) {
      iVar1 = *(int *)(local_30 + 0x10);
      if (iVar1 == 0) {
        *param_4 = 0;
        return 0;
      }
      if (iVar1 == 1) {
        *param_4 = local_30 + 0x18;
        return 1;
      }
      *param_4 = *(long *)(local_30 + 0x20);
    }
  }
  return iVar1;
}


// ==== entry=00b2ea40 name=FUN_00b2ea40 size=110 ====

ulong FUN_00b2ea40(void)

{
  int iVar1;
  ulong uVar2;
  long in_RCX;
  long lVar3;
  uint *local_10;
  
  uVar2 = FUN_00b2e9b0();
  iVar1 = (int)uVar2;
  if (-1 < iVar1) {
    if (iVar1 == 0) {
      uVar2 = 0xfffffff5;
    }
    else {
      if (iVar1 == 1) {
        return (ulong)*local_10;
      }
      if (in_RCX != 0) {
        lVar3 = (long)(iVar1 + -1);
        do {
          if (*(long *)(*(long *)(in_RCX + 8) + (long)(int)local_10[lVar3] * 8) != -1) {
            return (ulong)local_10[lVar3];
          }
          lVar3 = lVar3 + -1;
        } while (-1 < (int)lVar3);
      }
      uVar2 = (ulong)local_10[(long)iVar1 + -1];
    }
  }
  return uVar2;
}


// ==== entry=00b2eac0 name=FUN_00b2eac0 size=49 ====

uint FUN_00b2eac0(long param_1)

{
  uint uVar1;
  
  uVar1 = 0;
  if ((*(uint *)(param_1 + 0x50) & 0x80) == 0) {
    uVar1 = 1;
    if ((*(long *)(param_1 + 0x68) != 0) && (0 < *(int *)(*(long *)(param_1 + 0x68) + 0xc))) {
      uVar1 = 1;
      if ((*(byte *)(*(long *)(param_1 + 0x58) + 8) & 0x80) != 0) {
        uVar1 = *(uint *)(param_1 + 0x50) >> 8 & 1;
      }
    }
  }
  return uVar1;
}


// ==== entry=00b2eb00 orig=FUN_00b2eb00 size=5 name=thunk_FUN_00b2d8d0 ====

void thunk_FUN_00b2d8d0(undefined8 *param_1)

{
  long lVar1;
  undefined8 *puVar2;
  
  if (param_1 == (undefined8 *)0x0) {
    return;
  }
LAB_00b2d8dd:
  switch(*(undefined4 *)param_1) {
  case 0:
    if (((*(int *)((long)param_1 + 0x1c) == 0) ||
        (puVar2 = (undefined8 *)param_1[1], puVar2 == (undefined8 *)0x0)) || (puVar2 == param_1 + 4)
       ) goto switchD_00b2d8e4_caseD_2;
    break;
  case 1:
    if ((*(byte *)((long)param_1 + 4) & 2) != 0) {
      return;
    }
    if (param_1[5] != 0) {
      FUN_00b2b700();
    }
  default:
    goto switchD_00b2d8e4_caseD_2;
  case 4:
    puVar2 = (undefined8 *)param_1[5];
    if (puVar2 == (undefined8 *)0x0) goto switchD_00b2d8e4_caseD_2;
    break;
  case 5:
  case 7:
    lVar1 = param_1[1];
    goto joined_r0x00b2d937;
  case 6:
    lVar1 = param_1[3];
joined_r0x00b2d937:
    if (lVar1 != 0) {
      FUN_00b2d8d0();
    }
    goto switchD_00b2d8e4_caseD_2;
  case 8:
  case 9:
    goto switchD_00b2d8e4_caseD_8;
  }
  free(puVar2);
switchD_00b2d8e4_caseD_2:
  puVar2 = param_1;
  *param_1 = DAT_011c3818;
  DAT_011c3818 = puVar2;
  return;
switchD_00b2d8e4_caseD_8:
  FUN_00b2d8d0(param_1[1]);
  puVar2 = param_1;
  *param_1 = DAT_011c3818;
  DAT_011c3818 = puVar2;
  param_1 = (undefined8 *)param_1[2];
  if (param_1 == (undefined8 *)0x0) {
    return;
  }
  goto LAB_00b2d8dd;
}


// ==== entry=00b2eb10 name=FUN_00b2eb10 size=46 ====

undefined8 FUN_00b2eb10(void)

{
  long *plVar1;
  long *__ptr;
  
  __ptr = DAT_011c3818;
  if (DAT_011c3818 == (long *)0x0) {
    return 0;
  }
  do {
    plVar1 = (long *)*__ptr;
    DAT_011c3818 = plVar1;
    free(__ptr);
    __ptr = plVar1;
  } while (plVar1 != (long *)0x0);
  return 0;
}


// ==== entry=00b2eb50 orig=FUN_00b2eb50 size=5 name=thunk_FUN_00b2c0d0 ====

void thunk_FUN_00b2c0d0(undefined8 param_1,undefined8 param_2)

{
  undefined8 *puVar1;
  
  if (DAT_011c3818 == (undefined8 *)0x0) {
    puVar1 = (undefined8 *)FUN_00b2c0c0();
    if (puVar1 == (undefined8 *)0x0) {
      return;
    }
  }
  else {
    puVar1 = DAT_011c3818;
    DAT_011c3818 = (undefined8 *)*DAT_011c3818;
  }
  *(undefined4 *)puVar1 = 8;
  puVar1[1] = param_1;
  puVar1[2] = param_2;
  return;
}


// ==== entry=00b2eb60 name=FUN_00b2eb60 size=44 ====

void FUN_00b2eb60(long param_1,undefined8 param_2)

{
  long lVar1;
  long lVar2;
  
  lVar1 = FUN_00b2c0d0(param_2,0);
  if ((lVar1 != 0) && (param_1 != 0)) {
    do {
      lVar2 = param_1;
      param_1 = *(long *)(lVar2 + 0x10);
    } while (param_1 != 0);
    *(long *)(lVar2 + 0x10) = lVar1;
  }
  return;
}


// ==== entry=00b2eba0 name=FUN_00b2eba0 size=67 ====

void FUN_00b2eba0(undefined8 param_1,undefined8 param_2)

{
  undefined8 *puVar1;
  
  if (DAT_011c3818 == (undefined8 *)0x0) {
    puVar1 = (undefined8 *)FUN_00b2c0c0();
    if (puVar1 == (undefined8 *)0x0) {
      return;
    }
  }
  else {
    puVar1 = DAT_011c3818;
    DAT_011c3818 = (undefined8 *)*DAT_011c3818;
  }
  *(undefined4 *)puVar1 = 9;
  puVar1[1] = param_1;
  puVar1[2] = param_2;
  return;
}


// ==== entry=00b2ebf0 name=FUN_00b2ebf0 size=65 ====

void FUN_00b2ebf0(undefined4 param_1)

{
  undefined8 *puVar1;
  
  if (DAT_011c3818 == (undefined8 *)0x0) {
    puVar1 = (undefined8 *)FUN_00b2c0c0();
    if (puVar1 == (undefined8 *)0x0) {
      return;
    }
  }
  else {
    puVar1 = DAT_011c3818;
    DAT_011c3818 = (undefined8 *)*DAT_011c3818;
  }
  *(undefined4 *)puVar1 = 7;
  *(undefined4 *)((long)puVar1 + 4) = param_1;
  puVar1[1] = 0;
  puVar1[2] = 0xffffffff;
  return;
}


// ==== entry=00b2ec40 orig=FUN_00b2ec40 size=5 name=thunk_FUN_00b2c120 ====

void thunk_FUN_00b2c120(undefined4 param_1)

{
  undefined8 *puVar1;
  
  if (DAT_011c3818 == (undefined8 *)0x0) {
    puVar1 = (undefined8 *)FUN_00b2c0c0();
    if (puVar1 == (undefined8 *)0x0) {
      return;
    }
  }
  else {
    puVar1 = DAT_011c3818;
    DAT_011c3818 = (undefined8 *)*DAT_011c3818;
  }
  *(undefined4 *)(puVar1 + 1) = param_1;
  *puVar1 = 6;
  *(undefined8 *)((long)puVar1 + 0xc) = 0;
  puVar1[3] = 0;
  *(undefined4 *)(puVar1 + 4) = 0xffffffff;
  *(undefined4 *)((long)puVar1 + 0x3c) = 0;
  return;
}


// ==== entry=00b2ec50 name=FUN_00b2ec50 size=333 ====

undefined8 FUN_00b2ec50(long param_1,void *param_2,long param_3)

{
  size_t __size;
  long lVar1;
  void *__dest;
  void *pvVar2;
  size_t __n;
  size_t __n_00;
  
  __n = param_3 - (long)param_2;
  if ((long)__n < 1) {
    return 0;
  }
  pvVar2 = *(void **)(param_1 + 8);
  __n_00 = (long)*(void **)(param_1 + 0x10) - (long)pvVar2;
  lVar1 = __n + __n_00;
  if (((*(int *)(param_1 + 0x1c) < 1) && (lVar1 < 0x18)) ||
     (lVar1 + 0x10 <= (long)*(int *)(param_1 + 0x1c))) {
    pvVar2 = memcpy(*(void **)(param_1 + 0x10),param_2,__n);
    *(undefined1 *)((long)pvVar2 + __n) = 0;
    __dest = *(void **)(param_1 + 8);
  }
  else {
    __size = lVar1 + 0x11;
    if (pvVar2 == (void *)(param_1 + 0x20)) {
      __dest = malloc(__size);
      if (__dest == (void *)0x0) {
        return 0xfffffffb;
      }
      if (0 < (long)__n_00) {
        memcpy(__dest,pvVar2,__n_00);
        *(undefined1 *)((long)__dest + __n_00) = 0;
      }
      pvVar2 = memcpy((undefined1 *)((long)__dest + __n_00),param_2,__n);
      *(undefined1 *)((long)pvVar2 + __n) = 0;
    }
    else {
      if (pvVar2 == (void *)0x0) {
        __dest = malloc(__size);
      }
      else {
        __dest = realloc(pvVar2,__size);
      }
      if (__dest == (void *)0x0) {
        return 0xfffffffb;
      }
      memcpy((void *)(__n_00 + (long)__dest),param_2,__n);
      *(undefined1 *)((long)(__n_00 + (long)__dest) + __n) = 0;
    }
    *(void **)(param_1 + 8) = __dest;
    *(int *)(param_1 + 0x1c) = (int)(lVar1 + 0x10);
  }
  *(long *)(param_1 + 0x10) = (long)__dest + lVar1;
  return 0;
}


// ==== entry=00b2edc0 name=FUN_00b2edc0 size=117 ====

undefined8 * FUN_00b2edc0(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 *puVar2;
  undefined8 *puVar3;
  
  if (DAT_011c3818 == (undefined8 *)0x0) {
    puVar2 = (undefined8 *)FUN_00b2c0c0();
    if (puVar2 == (undefined8 *)0x0) {
      return (undefined8 *)0x0;
    }
  }
  else {
    puVar2 = DAT_011c3818;
    DAT_011c3818 = (undefined8 *)*DAT_011c3818;
  }
  *(undefined4 *)puVar2 = 0;
  puVar2[3] = 0;
  puVar2[1] = puVar2 + 4;
  puVar2[2] = puVar2 + 4;
  iVar1 = FUN_00b2ec50(puVar2,param_1,param_2);
  puVar3 = puVar2;
  if (iVar1 != 0) {
    puVar3 = (undefined8 *)0x0;
    FUN_00b2d8d0(puVar2);
  }
  return puVar3;
}


// ==== entry=00b2ee40 name=FUN_00b2ee40 size=52 ====

void FUN_00b2ee40(undefined8 param_1,code *param_2,undefined4 param_3)

{
  int iVar1;
  undefined1 local_f [7];
  
  iVar1 = (*param_2)(param_3,local_f);
  if (-1 < iVar1) {
    FUN_00b2ec50(param_1,local_f,local_f + iVar1);
  }
  return;
}


// ==== entry=00b2ee80 name=FUN_00b2ee80 size=374 ====

ulong FUN_00b2ee80(undefined4 param_1,uint *param_2,int param_3,long *param_4)

{
  uint *puVar1;
  long lVar2;
  undefined8 *puVar3;
  int iVar4;
  uint uVar5;
  long lVar6;
  ulong uVar7;
  undefined8 uVar8;
  long lVar9;
  undefined1 local_3f [15];
  
  lVar2 = *param_4;
  lVar6 = param_4[1];
  if (param_3 == 1) {
    uVar7 = FUN_00b39a60(*(undefined8 *)(lVar2 + 8),param_1,lVar6);
    if ((int)uVar7 == 0) {
      if ((*(byte *)(lVar6 + 4) & 1) == 0) {
        return uVar7;
      }
    }
    else if ((*(byte *)(lVar6 + 4) & 1) != 0) {
      return 0;
    }
    uVar5 = *param_2;
    if ((*(int *)(*(long *)(lVar2 + 8) + 0x1c) < 2) && (uVar5 < 0x100)) {
      puVar1 = (uint *)(lVar6 + 8 + (long)((int)uVar5 >> 5) * 4);
      *puVar1 = *puVar1 | 1 << ((byte)uVar5 & 0x1f);
      return 0;
    }
    FUN_00b2b850(lVar6 + 0x28,uVar5,uVar5);
  }
  else {
    iVar4 = FUN_00b39a60(*(undefined8 *)(lVar2 + 8),param_1,lVar6);
    if ((iVar4 != 0) && ((*(byte *)(lVar6 + 4) & 1) == 0)) {
      lVar6 = 0;
      if (0 < param_3) {
        lVar9 = 0;
        lVar6 = 0;
        do {
          iVar4 = (**(code **)(*(long *)(lVar2 + 8) + 0x48))(param_2[lVar9],local_3f);
          if (lVar9 == 0) {
            lVar6 = FUN_00b2edc0(local_3f,local_3f + iVar4);
            if (lVar6 == 0) {
              return 0xfffffffb;
            }
            *(uint *)(lVar6 + 0x18) = *(uint *)(lVar6 + 0x18) | 2;
          }
          else {
            uVar5 = FUN_00b2ec50(lVar6,local_3f,local_3f + iVar4);
            if ((int)uVar5 < 0) {
              FUN_00b2d8d0(lVar6);
              return (ulong)uVar5;
            }
            if (param_3 <= (int)lVar9 + 1) break;
          }
          lVar9 = lVar9 + 1;
        } while( true );
      }
      puVar3 = (undefined8 *)param_4[3];
      uVar8 = FUN_00b2eba0(lVar6,0);
      *puVar3 = uVar8;
      if (*(long *)param_4[3] == 0) {
        return 0xfffffffb;
      }
      param_4[3] = *(long *)param_4[3] + 0x10;
    }
  }
  return 0;
}


// ==== entry=00b2f030 name=FUN_00b2f030 size=29 ====

void FUN_00b2f030(undefined4 *param_1,undefined4 param_2)

{
  *param_1 = 0;
  param_1[6] = param_2;
  param_1[7] = 0;
  *(undefined4 **)(param_1 + 2) = param_1 + 8;
  *(undefined4 **)(param_1 + 4) = param_1 + 8;
  return;
}


// ==== entry=00b2f050 name=FUN_00b2f050 size=62 ====

void FUN_00b2f050(long param_1)

{
  void *pvVar1;
  void *__ptr;
  
  pvVar1 = (void *)(param_1 + 0x20);
  if (((*(int *)(param_1 + 0x1c) != 0) && (__ptr = *(void **)(param_1 + 8), __ptr != (void *)0x0))
     && (__ptr != pvVar1)) {
    free(__ptr);
  }
  *(void **)(param_1 + 8) = pvVar1;
  *(void **)(param_1 + 0x10) = pvVar1;
  *(undefined8 *)(param_1 + 0x18) = 0;
  return;
}


// ==== entry=00b2f090 name=FUN_00b2f090 size=36 ====

void FUN_00b2f090(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  FUN_00b2f050();
  FUN_00b2ec50(param_1,param_2,param_3);
  return;
}


// ==== entry=00b2f0c0 orig=FUN_00b2f0c0 size=5 name=thunk_FUN_00b2edc0 ====

undefined8 * thunk_FUN_00b2edc0(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 *puVar2;
  undefined8 *puVar3;
  
  if (DAT_011c3818 == (undefined8 *)0x0) {
    puVar2 = (undefined8 *)FUN_00b2c0c0();
    if (puVar2 == (undefined8 *)0x0) {
      return (undefined8 *)0x0;
    }
  }
  else {
    puVar2 = DAT_011c3818;
    DAT_011c3818 = (undefined8 *)*DAT_011c3818;
  }
  *(undefined4 *)puVar2 = 0;
  puVar2[3] = 0;
  puVar2[1] = puVar2 + 4;
  puVar2[2] = puVar2 + 4;
  iVar1 = FUN_00b2ec50(puVar2,param_1,param_2);
  puVar3 = puVar2;
  if (iVar1 != 0) {
    puVar3 = (undefined8 *)0x0;
    FUN_00b2d8d0(puVar2);
  }
  return puVar3;
}


// ==== entry=00b2f0d0 name=FUN_00b2f0d0 size=188 ====

ulong FUN_00b2f0d0(ulong *param_1,ulong param_2,undefined8 *param_3)

{
  int iVar1;
  int iVar2;
  ulong uVar3;
  ulong uVar4;
  ulong uVar5;
  
  uVar5 = *param_1;
  if (uVar5 < param_2) {
    uVar3 = 0;
    do {
      iVar1 = (*(code *)param_3[6])(uVar5,param_2);
      iVar2 = (*(code *)*param_3)(uVar5);
      uVar4 = (long)iVar2 + uVar5;
      iVar2 = (*(code *)param_3[0xf])(iVar1,4);
      if (iVar2 == 0) break;
      if ((0x7fffffff - (ulong)(iVar1 - 0x30U)) / 10 < uVar3) {
        return 0xffffffff;
      }
      uVar3 = (ulong)((iVar1 - 0x30U) + (int)uVar3 * 10);
      uVar5 = uVar4;
    } while (uVar4 < param_2);
  }
  else {
    uVar3 = 0;
  }
  *param_1 = uVar5;
  return uVar3;
}


// ==== entry=00b2f1a0 name=FUN_00b2f1a0 size=614 ====

undefined4
FUN_00b2f1a0(ulong *param_1,ulong param_2,undefined4 *param_3,long *param_4,long *param_5)

{
  undefined8 *puVar1;
  bool bVar2;
  ulong uVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  undefined8 *puVar9;
  uint uVar10;
  ulong uVar11;
  undefined4 uVar12;
  ulong local_40 [2];
  
  local_40[0] = *param_1;
  puVar1 = (undefined8 *)*param_4;
  uVar10 = *(uint *)(*param_5 + 8) & 8;
  if (param_2 <= local_40[0]) {
    if (uVar10 != 0) {
      return 1;
    }
    return 0xffffff9c;
  }
  puVar9 = puVar1;
  if (uVar10 == 0) {
    iVar4 = (*(code *)puVar1[6])(local_40[0]);
    if (iVar4 - 0x28U < 2) {
      return 0xffffff9c;
    }
    if (iVar4 == 0x7c) {
      return 0xffffff9c;
    }
    puVar9 = (undefined8 *)*param_4;
  }
  uVar5 = FUN_00b2f0d0(local_40,param_2,puVar9);
  if (100000 < uVar5) {
    return 0xffffff37;
  }
  bVar2 = false;
  if (*param_1 == local_40[0]) {
    if ((*(byte *)(*param_5 + 8) & 0x10) == 0) goto LAB_00b2f310;
    bVar2 = true;
    uVar5 = 0;
  }
  if (local_40[0] < param_2) {
    iVar4 = (*(code *)puVar1[6])(local_40[0],param_2);
    uVar3 = local_40[0];
    iVar6 = (*(code *)*puVar1)(local_40[0]);
    uVar11 = (long)iVar6 + local_40[0];
    if (iVar4 == 0x2c) {
      local_40[0] = uVar11;
      uVar8 = FUN_00b2f0d0(local_40,param_2,*param_4);
      if (100000 < uVar8) {
        return 0xffffff37;
      }
      if (uVar11 == local_40[0]) {
        uVar8 = 0xffffffff;
        uVar12 = 0;
        if (bVar2) goto LAB_00b2f310;
      }
      else {
        uVar12 = 0;
      }
    }
    else {
      if (bVar2) goto LAB_00b2f310;
      uVar12 = 2;
      uVar8 = uVar5;
      local_40[0] = uVar3;
    }
    if (local_40[0] < param_2) {
      uVar7 = (*(code *)puVar1[6])(local_40[0],param_2);
      iVar4 = (*(code *)*puVar1)(local_40[0]);
      local_40[0] = (long)iVar4 + local_40[0];
      if ((*(uint *)*param_5 & 0x200) != 0) {
        if (uVar7 != ((uint *)*param_5)[4]) goto LAB_00b2f310;
        uVar7 = (*(code *)puVar1[6])(local_40[0],param_2);
        iVar4 = (*(code *)*puVar1)(local_40[0]);
        local_40[0] = local_40[0] + (long)iVar4;
      }
      if (uVar7 == 0x7d) {
        if ((uVar8 != 0xffffffff) && ((int)uVar8 < (int)uVar5)) {
          return 0xffffff36;
        }
        *param_3 = 0xb;
        param_3[6] = uVar5;
        param_3[7] = uVar8;
        *param_1 = local_40[0];
        return uVar12;
      }
    }
  }
LAB_00b2f310:
  if (uVar10 != 0) {
    return 1;
  }
  return 0xffffff85;
}


// ==== entry=00b2f430 name=FUN_00b2f430 size=736 ====

undefined8
FUN_00b2f430(uint param_1,ulong *param_2,ulong param_3,ulong *param_4,long param_5,int *param_6,
            uint param_7)

{
  undefined8 *puVar1;
  uint uVar2;
  int iVar3;
  ulong uVar4;
  ulong uVar5;
  ulong uVar6;
  undefined8 uVar7;
  bool bVar8;
  int local_4c;
  ulong local_40 [2];
  
  puVar1 = *(undefined8 **)(param_5 + 8);
  uVar4 = *param_2;
  *param_6 = 0;
  if (param_1 == 0x28) {
    param_1 = 0x29;
  }
  else if (param_1 < 0x29) {
    if (param_1 != 0x27) {
      param_1 = 0;
    }
  }
  else if (param_1 == 0x3c) {
    param_1 = 0x3e;
  }
  else {
    bVar8 = param_1 != 0x7b;
    param_1 = 0x7d;
    if (bVar8) {
      param_1 = 0;
    }
  }
  if (param_3 <= uVar4) {
    return 0xffffff2a;
  }
  local_40[0] = uVar4;
  uVar2 = (*(code *)puVar1[6])(uVar4,param_3);
  iVar3 = (*(code *)*puVar1)(uVar4);
  uVar4 = uVar4 + (long)iVar3;
  if (param_1 == uVar2) {
    return 0xffffff2a;
  }
  iVar3 = (*(code *)puVar1[0xf])(uVar2,4);
  if (iVar3 == 0) {
    if (uVar2 == 0x2d) {
      uVar7 = 0xffffff29;
      if (param_7 != 1) goto LAB_00b2f51d;
      local_4c = -1;
      param_7 = 2;
      local_40[0] = uVar4;
    }
    else {
      iVar3 = (*(code *)puVar1[0xf])(uVar2,0xc);
      if (iVar3 == 0) {
        uVar7 = 0xffffff28;
LAB_00b2f51d:
        do {
          uVar5 = uVar4;
          uVar4 = param_3;
          if (param_3 <= uVar5) goto LAB_00b2f525;
          uVar2 = (*(code *)puVar1[6])(uVar5,param_3);
          iVar3 = (*(code *)*puVar1)(uVar5);
        } while ((param_1 != uVar2) && (uVar4 = (long)iVar3 + uVar5, uVar2 != 0x29));
        uVar4 = uVar5;
        if (param_3 <= (long)iVar3 + uVar5) {
          uVar4 = param_3;
        }
        goto LAB_00b2f525;
      }
      param_7 = 0;
      local_4c = 1;
    }
  }
  else {
    uVar7 = 0xffffff29;
    if (param_7 != 1) goto LAB_00b2f51d;
    local_4c = 1;
  }
  uVar5 = uVar4;
  uVar6 = param_3;
  if (uVar4 < param_3) {
    do {
      while( true ) {
        uVar2 = (*(code *)puVar1[6])(uVar5,param_3);
        iVar3 = (*(code *)*puVar1)(uVar5);
        uVar4 = uVar5 + (long)iVar3;
        uVar6 = uVar5;
        if ((param_1 == uVar2) || (uVar2 == 0x29)) goto LAB_00b2f6c0;
        uVar5 = uVar4;
        if (param_7 != 0) break;
        (*(code *)puVar1[0xf])(uVar2,0xc);
        if (param_3 <= uVar4) goto LAB_00b2f621;
      }
      iVar3 = (*(code *)puVar1[0xf])(uVar2,4);
      if (iVar3 == 0) {
        (*(code *)puVar1[0xf])(uVar2,0xc);
      }
      param_7 = (uint)(iVar3 != 0);
    } while (uVar4 < param_3);
  }
  else {
LAB_00b2f6c0:
    if (uVar2 == param_1) {
      param_3 = uVar6;
    }
  }
LAB_00b2f621:
  if (param_7 != 0) {
    iVar3 = FUN_00b2f0d0(local_40,param_3,puVar1);
    *param_6 = iVar3;
    if (iVar3 < 0) {
      return 0xffffff38;
    }
    if (iVar3 == 0) {
      uVar7 = 0xffffff29;
      uVar4 = param_3;
LAB_00b2f525:
      uVar5 = *param_2;
      *(ulong *)(param_5 + 0x40) = uVar4;
      *(ulong *)(param_5 + 0x38) = uVar5;
      return uVar7;
    }
    *param_6 = iVar3 * local_4c;
  }
  *param_4 = param_3;
  *param_2 = uVar4;
  return 0;
}


// ==== entry=00b2f750 name=FUN_00b2f750 size=1397 ====

int FUN_00b2f750(uint param_1,undefined4 *param_2,long *param_3,int *param_4,long param_5)

{
  undefined8 *puVar1;
  byte bVar2;
  int *piVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  undefined4 uVar8;
  int *piVar9;
  long lVar10;
  int *piVar11;
  bool bVar12;
  int *local_88;
  int local_54;
  int *local_48;
  int *local_40 [2];
  
  lVar10 = *(long *)(param_5 + 0x10);
  puVar1 = *(undefined8 **)(param_5 + 8);
  piVar11 = (int *)*param_3;
  if (param_1 == 0x28) {
    param_1 = 0x29;
  }
  else if (param_1 < 0x29) {
    if (param_1 != 0x27) {
      param_1 = 0;
    }
  }
  else if (param_1 == 0x3c) {
    param_1 = 0x3e;
  }
  else {
    bVar12 = param_1 != 0x7b;
    param_1 = 0x7d;
    if (bVar12) {
      param_1 = 0;
    }
  }
  if (param_4 <= piVar11) {
LAB_00b2fce0:
    param_2[0xb] = 0;
    return -0xd6;
  }
  local_48 = piVar11;
  local_40[0] = piVar11;
  uVar4 = (*(code *)puVar1[6])(piVar11,param_4);
  iVar5 = (*(code *)*puVar1)(local_40[0]);
  local_40[0] = (int *)((long)local_40[0] + (long)iVar5);
  if (uVar4 == param_1) goto LAB_00b2fce0;
  iVar5 = (*(code *)puVar1[0xf])(uVar4,4);
  piVar9 = param_4;
  if (iVar5 == 0) {
    iVar5 = 0;
    if (uVar4 == 0x2d) {
      local_48 = local_40[0];
      iVar6 = 2;
      local_54 = -1;
    }
    else {
      iVar6 = (*(code *)puVar1[0xf])(uVar4,0xc);
      if (iVar6 == 0) {
        local_54 = 1;
        iVar5 = -0xd8;
        iVar6 = 0;
      }
      else {
        iVar6 = 0;
        local_54 = 1;
      }
    }
  }
  else {
    local_54 = 1;
    iVar6 = 1;
    iVar5 = 0;
  }
  while (local_88 = local_40[0], local_40[0] < param_4) {
    uVar4 = (*(code *)puVar1[6])(local_40[0],param_4);
    iVar7 = (*(code *)*puVar1)(local_40[0]);
    local_40[0] = (int *)((long)local_40[0] + (long)iVar7);
    piVar9 = local_88;
    if ((((uVar4 & 0xfffffffd) == 0x29) || (param_1 == uVar4)) || (uVar4 == 0x2d)) {
      if (iVar6 == 2) goto LAB_00b2f9a0;
      break;
    }
    if (iVar6 == 0) {
      iVar7 = (*(code *)puVar1[0xf])(uVar4,0xc);
      if (iVar7 == 0) {
        iVar5 = -0xd8;
      }
    }
    else {
      iVar6 = (*(code *)puVar1[0xf])(uVar4,4);
      if (iVar6 == 0) {
        iVar5 = -0xd7;
        iVar6 = 0;
      }
      else {
        iVar6 = 1;
      }
    }
  }
  if ((iVar5 != 0) || (param_1 == uVar4)) {
    local_88 = piVar9;
    if (iVar5 != 0) goto LAB_00b2f9a6;
    bVar2 = 0;
    if (iVar6 == 0) {
      param_2[0xb] = 0;
    }
    else {
LAB_00b2fa0a:
      iVar5 = FUN_00b2f0d0(&local_48,piVar9,puVar1);
      if (iVar5 < 0) {
LAB_00b2fb08:
        param_2[0xb] = 0;
        return -200;
      }
      if (iVar5 == 0) {
        *(int **)(param_5 + 0x38) = piVar11;
        *(int **)(param_5 + 0x40) = param_4;
        param_2[0xb] = 0;
        return -0xd7;
      }
      iVar5 = iVar5 * local_54;
      param_2[0xb] = (uint)bVar2;
      if (iVar5 != 0) {
        if ((iVar5 < 0) && (iVar5 = iVar5 + 1 + *(int *)(param_5 + 0x60), iVar5 < 1)) {
          return -0xd0;
        }
        if ((*(byte *)(lVar10 + 8) & 0x20) != 0) {
          if (*(int *)(param_5 + 0x60) < iVar5) {
            return -0xd0;
          }
          lVar10 = *(long *)(param_5 + 0xb0);
          if (*(long *)(param_5 + 0xb0) == 0) {
            lVar10 = param_5 + 0x70;
          }
          if (*(long *)(lVar10 + (long)iVar5 * 8) == 0) {
            return -0xd0;
          }
        }
        *param_2 = 7;
        param_2[10] = 0;
        param_2[6] = 1;
        param_2[7] = iVar5;
        goto LAB_00b2fb8e;
      }
    }
LAB_00b2fa66:
    piVar3 = local_40[0];
    iVar5 = FUN_00b2e9b0(*(undefined8 *)(param_5 + 0x48),piVar11,piVar9,local_40);
    if (iVar5 < 1) {
      *(int **)(param_5 + 0x40) = piVar9;
      *(int **)(param_5 + 0x38) = piVar11;
      return -0xd9;
    }
    if ((*(byte *)(lVar10 + 8) & 0x20) != 0) {
      piVar11 = local_40[0];
      do {
        if (*(int *)(param_5 + 0x60) < *piVar11) {
          return -0xd0;
        }
        lVar10 = *(long *)(param_5 + 0xb0);
        if (*(long *)(param_5 + 0xb0) == 0) {
          lVar10 = param_5 + 0x70;
        }
        if (*(long *)(lVar10 + (long)*piVar11 * 8) == 0) {
          return -0xd0;
        }
        piVar11 = piVar11 + 1;
      } while (local_40[0] + (ulong)(iVar5 - 1) + 1 != piVar11);
    }
    *param_2 = 7;
    param_2[10] = 1;
    if (iVar5 == 1) {
      param_2[6] = 1;
      param_2[7] = *local_40[0];
      local_40[0] = piVar3;
    }
    else {
      param_2[6] = iVar5;
      *(int **)(param_2 + 8) = local_40[0];
      local_40[0] = piVar3;
    }
LAB_00b2fb8e:
    *param_3 = (long)local_40[0];
    return 0;
  }
  local_88 = param_4;
  if ((uVar4 - 0x2b & 0xfffffffd) == 0) {
    uVar8 = (*(code *)puVar1[6])(local_40[0],param_4);
    piVar3 = local_40[0];
    iVar5 = (*(code *)*puVar1)(local_40[0]);
    local_40[0] = (int *)((long)local_40[0] + (long)iVar5);
    iVar5 = (*(code *)puVar1[0xf])(uVar8,4);
    if (iVar5 != 0) {
      local_40[0] = piVar3;
      iVar5 = FUN_00b2f0d0(local_40,param_4,puVar1);
      if (iVar5 < 0) goto LAB_00b2fb08;
      param_2[0xc] = iVar5 * (((uVar4 != 0x2d) - 1) + (uint)(uVar4 != 0x2d));
      uVar4 = (*(code *)puVar1[6])(local_40[0],param_4);
      iVar5 = (*(code *)*puVar1)(local_40[0]);
      local_40[0] = (int *)((long)iVar5 + (long)local_40[0]);
      if (param_1 == uVar4) {
        bVar2 = 1;
        if (iVar6 != 0) goto LAB_00b2fa0a;
        param_2[0xb] = 1;
        goto LAB_00b2fa66;
      }
    }
  }
LAB_00b2f9a0:
  iVar5 = -0xd7;
LAB_00b2f9a6:
  *(int **)(param_5 + 0x38) = piVar11;
  *(int **)(param_5 + 0x40) = local_88;
  param_2[0xb] = 0;
  return iVar5;
}


// ==== entry=00b2fd20 name=FUN_00b2fd20 size=5609 ====

ulong FUN_00b2fd20(uint *param_1,ulong *param_2,ulong param_3,uint *param_4,undefined8 param_5,
                  ulong param_6)

{
  undefined8 *puVar1;
  code *pcVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  undefined4 uVar7;
  ulong uVar8;
  undefined8 uVar9;
  long lVar10;
  uint *puVar11;
  ulong uVar12;
  ulong uVar13;
  bool bVar14;
  uint local_144;
  ulong local_140;
  ulong local_138 [33];
  
  puVar1 = *(undefined8 **)(param_4 + 2);
  puVar11 = *(uint **)(param_4 + 4);
  local_140 = *param_2;
LAB_00b2fd4f:
  do {
    if (param_3 <= local_140) {
      *param_1 = 0;
      return 0;
    }
    *(ulong *)(param_1 + 4) = local_140;
    *param_1 = 3;
    param_1[2] = 0;
    uVar3 = (*(code *)puVar1[6])(local_140,param_3);
    iVar4 = (*(code *)*puVar1)(local_140);
    uVar12 = (long)iVar4 + local_140;
    local_140 = uVar12;
    if ((puVar11[4] == uVar3) &&
       (param_6 = (ulong)(puVar11[1] & 0x100000), (puVar11[1] & 0x100000) == 0)) {
      if (param_3 <= uVar12) {
        return 0xffffff98;
      }
      *(ulong *)(param_1 + 4) = uVar12;
      uVar3 = (*(code *)puVar1[6])(uVar12,param_3);
      uVar8 = local_140;
      iVar4 = (*(code *)*puVar1)(local_140);
      param_1[1] = 1;
      uVar12 = (long)iVar4 + local_140;
      param_1[6] = uVar3;
      local_140 = uVar12;
      switch(uVar3) {
      case 0x27:
        if ((*(byte *)((long)puVar11 + 5) & 0x80) != 0) goto LAB_00b30bf5;
        uVar8 = (ulong)*param_1;
        goto LAB_00b2fdac;
      case 0x28:
        if ((*puVar11 & 0x2000) == 0) {
          uVar8 = (ulong)*param_1;
        }
        else {
          *param_1 = 0xe;
          uVar8 = 0xe;
        }
        goto LAB_00b2fdac;
      case 0x29:
        if ((*puVar11 & 0x2000) == 0) {
          uVar8 = (ulong)*param_1;
        }
        else {
          *param_1 = 0xf;
          uVar8 = 0xf;
        }
        goto LAB_00b2fdac;
      case 0x2a:
        if ((*puVar11 & 8) == 0) {
          uVar8 = (ulong)*param_1;
          goto LAB_00b2fdac;
        }
LAB_00b30190:
        *param_1 = 10;
        param_1[6] = 0;
        param_1[7] = 0xffffffff;
        break;
      case 0x2b:
        if ((*puVar11 & 0x20) == 0) {
          uVar8 = (ulong)*param_1;
          goto LAB_00b2fdac;
        }
LAB_00b30220:
        *param_1 = 10;
        param_1[6] = 1;
        param_1[7] = 0xffffffff;
        break;
      default:
        local_140 = uVar8;
        uVar12 = FUN_00b2bd10(&local_140,param_3,param_4);
        uVar3 = (uint)uVar12;
        if ((int)uVar3 < 0) {
          return uVar12;
        }
        if (param_1[6] == uVar3) {
          lVar10 = *(long *)(param_1 + 4);
          iVar4 = (*(code *)*puVar1)(lVar10);
          uVar8 = (ulong)*param_1;
          uVar12 = lVar10 + iVar4;
        }
        else {
          param_1[6] = uVar3;
          uVar8 = 4;
          *param_1 = 4;
          uVar12 = local_140;
        }
        goto LAB_00b2fdac;
      case 0x30:
        goto switchD_00b2fe92_caseD_30;
      case 0x31:
      case 0x32:
      case 0x33:
      case 0x34:
      case 0x35:
      case 0x36:
      case 0x37:
      case 0x38:
      case 0x39:
        local_140 = uVar8;
        uVar5 = FUN_00b2f0d0(&local_140,param_3,puVar1);
        if (((uVar5 < 0x3e9) && ((*puVar11 & 0x10000) != 0)) &&
           (((int)uVar5 <= (int)param_4[0x18] || ((int)uVar5 < 10)))) {
          if ((puVar11[2] & 0x20) != 0) {
            if ((int)param_4[0x18] < (int)uVar5) {
              return 0xffffff30;
            }
            puVar11 = *(uint **)(param_4 + 0x2c);
            if (puVar11 == (uint *)0x0) {
              puVar11 = param_4 + 0x1c;
            }
            if (*(long *)(puVar11 + (long)(int)uVar5 * 2) == 0) {
              return 0xffffff30;
            }
          }
          param_1[7] = uVar5;
          uVar8 = 7;
          *param_1 = 7;
          param_1[6] = 1;
          param_1[10] = 0;
          param_1[0xb] = 0;
          uVar12 = local_140;
        }
        else {
          local_140 = uVar8;
          if (uVar3 - 0x38 < 2) {
            iVar4 = (*(code *)*puVar1)(uVar8);
            uVar8 = (ulong)*param_1;
            uVar12 = (long)iVar4 + local_140;
          }
          else {
switchD_00b2fe92_caseD_30:
            uVar12 = local_140;
            if ((*puVar11 & 0x10000000) == 0) {
              if (uVar3 == 0x30) {
                uVar8 = (ulong)*param_1;
              }
              else {
                iVar4 = (*(code *)*puVar1)(local_140);
                uVar8 = (ulong)*param_1;
                uVar12 = (long)iVar4 + local_140;
              }
            }
            else {
              uVar3 = FUN_00b2b4a0(&local_140,param_3,(uVar3 != 0x30) + '\x02',puVar1);
              if ((int)uVar3 < 0) {
                return 0xffffff38;
              }
              *param_1 = 1;
              param_1[2] = 8;
              if (local_140 == uVar12) {
                uVar3 = 0;
              }
              param_1[6] = uVar3;
              uVar8 = 1;
              uVar12 = local_140;
            }
          }
        }
        goto LAB_00b2fdac;
      case 0x3c:
        if ((*puVar11 & 0x80000) == 0) {
          uVar8 = (ulong)*param_1;
        }
        else {
          uVar3 = *param_4;
          *param_1 = 9;
          param_1[6] = 0x100;
          param_1[7] = uVar3 & 0x1000;
          uVar8 = 9;
        }
        goto LAB_00b2fdac;
      case 0x3e:
        if ((*puVar11 & 0x80000) == 0) {
          uVar8 = (ulong)*param_1;
        }
        else {
          uVar3 = *param_4;
          *param_1 = 9;
          param_1[6] = 0x200;
          param_1[7] = uVar3 & 0x1000;
          uVar8 = 9;
        }
        goto LAB_00b2fdac;
      case 0x3f:
        if ((*puVar11 & 0x80) == 0) {
          uVar8 = (ulong)*param_1;
          goto LAB_00b2fdac;
        }
LAB_00b30200:
        *param_1 = 10;
        param_1[6] = 0;
        param_1[7] = 1;
        break;
      case 0x41:
        if ((*puVar11 & 0x4000) != 0) goto LAB_00b30b13;
        uVar8 = (ulong)*param_1;
        goto LAB_00b2fdac;
      case 0x42:
        if ((*puVar11 & 0x100000) == 0) {
          uVar8 = (ulong)*param_1;
        }
        else {
          uVar3 = *param_4;
          *param_1 = 9;
          param_1[6] = 0x80;
          param_1[7] = (uint)((uVar3 & 0x5000) == 0x1000);
          uVar8 = 9;
        }
        goto LAB_00b2fdac;
      case 0x44:
        if ((*puVar11 & 0x400000) == 0) {
          uVar8 = (ulong)*param_1;
        }
        else {
          *param_1 = 6;
          param_1[6] = 4;
          param_1[7] = 1;
          uVar8 = 6;
        }
        goto LAB_00b2fdac;
      case 0x47:
        if ((*puVar11 & 0x8000) == 0) {
          uVar8 = (ulong)*param_1;
        }
        else {
          *param_1 = 9;
          uVar8 = 9;
          param_1[6] = 4;
        }
        goto LAB_00b2fdac;
      case 0x48:
        if ((*(byte *)((long)puVar11 + 6) & 8) == 0) {
          uVar8 = (ulong)*param_1;
        }
        else {
          *param_1 = 6;
          param_1[6] = 0xb;
          param_1[7] = 1;
          uVar8 = 6;
        }
        goto LAB_00b2fdac;
      case 0x4b:
        if ((*(byte *)((long)puVar11 + 7) & 2) == 0) {
          uVar8 = (ulong)*param_1;
        }
        else {
          *param_1 = 0x15;
          uVar8 = 0x15;
        }
        goto LAB_00b2fdac;
      case 0x50:
      case 0x70:
        if (uVar12 < param_3) {
          iVar4 = (*(code *)puVar1[6])(uVar12,param_3);
          if ((iVar4 == 0x7b) && ((*(byte *)((long)puVar11 + 6) & 1) != 0)) {
            iVar4 = (*(code *)*puVar1)(local_140);
            *param_1 = 0x12;
            local_140 = (long)iVar4 + local_140;
            param_1[7] = (uint)(uVar3 == 0x50);
            uVar8 = 0x12;
            uVar12 = local_140;
            if ((*(byte *)((long)puVar11 + 6) & 2) != 0) {
              iVar4 = (*(code *)puVar1[6])(local_140,param_3);
              uVar12 = local_140;
              iVar6 = (*(code *)*puVar1)(local_140);
              if (iVar4 == 0x5e) {
                param_1[7] = (uint)(param_1[7] == 0);
                uVar8 = (ulong)*param_1;
                uVar12 = (long)iVar6 + local_140;
              }
              else {
                uVar8 = (ulong)*param_1;
              }
            }
          }
          else {
            uVar8 = (ulong)*param_1;
            uVar12 = local_140;
          }
        }
        else {
          uVar8 = (ulong)*param_1;
        }
        goto LAB_00b2fdac;
      case 0x51:
        if ((puVar11[1] & 1) == 0) {
          uVar8 = (ulong)*param_1;
        }
        else {
          *param_1 = 0x11;
          uVar8 = 0x11;
        }
        goto LAB_00b2fdac;
      case 0x52:
        if ((*(byte *)((long)puVar11 + 6) & 0x20) == 0) {
          uVar8 = (ulong)*param_1;
        }
        else {
          *param_1 = 0x13;
          uVar8 = 0x13;
        }
        goto LAB_00b2fdac;
      case 0x53:
        if ((*puVar11 & 0x200000) == 0) {
          uVar8 = (ulong)*param_1;
        }
        else {
          *param_1 = 6;
          param_1[6] = 9;
          param_1[7] = 1;
          uVar8 = 6;
        }
        goto LAB_00b2fdac;
      case 0x57:
        if ((*puVar11 & 0x40000) == 0) {
          uVar8 = (ulong)*param_1;
        }
        else {
          *param_1 = 6;
          param_1[6] = 0xc;
          param_1[7] = 1;
          uVar8 = 6;
        }
        goto LAB_00b2fdac;
      case 0x58:
        if ((*(byte *)((long)puVar11 + 6) & 0x40) == 0) {
          uVar8 = (ulong)*param_1;
        }
        else {
          *param_1 = 0x14;
          uVar8 = 0x14;
        }
        goto LAB_00b2fdac;
      case 0x5a:
        if ((*puVar11 & 0x4000) == 0) {
          uVar8 = (ulong)*param_1;
        }
        else {
          *param_1 = 9;
          uVar8 = 9;
          param_1[6] = 0x10;
        }
        goto LAB_00b2fdac;
      case 0x60:
        if ((*(byte *)((long)puVar11 + 5) & 0x80) == 0) {
          uVar8 = (ulong)*param_1;
        }
        else {
LAB_00b30b13:
          *param_1 = 9;
          uVar8 = 9;
          param_1[6] = 1;
        }
        goto LAB_00b2fdac;
      case 0x62:
        if ((*puVar11 & 0x100000) == 0) {
          uVar8 = (ulong)*param_1;
        }
        else {
          uVar3 = *param_4;
          *param_1 = 9;
          param_1[6] = 0x40;
          param_1[7] = (uint)((uVar3 & 0x5000) == 0x1000);
          uVar8 = 9;
        }
        goto LAB_00b2fdac;
      case 100:
        if ((*puVar11 & 0x400000) == 0) {
          uVar8 = (ulong)*param_1;
        }
        else {
          *param_1 = 6;
          uVar8 = 6;
          param_1[6] = 4;
          param_1[7] = 0;
        }
        goto LAB_00b2fdac;
      case 0x67:
        uVar3 = puVar11[1];
        if ((uVar3 & 0x4000000) != 0) {
          iVar4 = (*(code *)puVar1[6])(uVar12,param_3);
          uVar12 = local_140;
          iVar6 = (*(code *)*puVar1)(local_140);
          local_140 = local_140 + (long)iVar6;
          if (iVar4 == 0x7b) {
            uVar12 = FUN_00b2f750(0x7b,param_1,&local_140,param_3,param_4);
            if ((int)uVar12 < 0) {
              return uVar12;
            }
            uVar3 = puVar11[1];
          }
          else {
            uVar3 = puVar11[1];
            local_140 = uVar12;
          }
        }
        if ((uVar3 & 0x200) == 0) {
          uVar8 = (ulong)*param_1;
          uVar12 = local_140;
        }
        else {
          uVar3 = (*(code *)puVar1[6])(local_140,param_3);
          uVar12 = local_140;
          lVar10 = (*(code *)*puVar1)(local_140);
          local_140 = (long)(int)lVar10 + local_140;
          if ((uVar3 == 0x3c) || (uVar3 == 0x27)) {
            local_144 = 0xffffffff;
            if (local_140 < param_3) {
              lVar10 = (*(code *)puVar1[6])(local_140,param_3);
              if ((int)lVar10 == 0x30) {
                iVar4 = (*(code *)*puVar1)();
                local_140 = (long)iVar4 + local_140;
                iVar4 = 0;
                if (local_140 < param_3) {
                  lVar10 = (*(code *)puVar1[6])(local_140,param_3);
                  if (uVar3 == 0x28) goto LAB_00b313a1;
                  if (uVar3 < 0x29) {
                    if (uVar3 == 0x27) {
                      iVar4 = 0x27;
                    }
                  }
                  else {
LAB_00b31342:
                    if (uVar3 == 0x3c) {
                      iVar4 = 0x3e;
                    }
                    else if (uVar3 == 0x7b) {
                      iVar4 = 0x7d;
                    }
                  }
                }
                else {
                  if (uVar3 != 0x28) {
                    if (0x28 < uVar3) {
                      lVar10 = 0;
                      goto LAB_00b31342;
                    }
                    lVar10 = 0;
                    if (uVar3 != 0x27) goto LAB_00b31354;
                    uVar5 = 0;
                    goto LAB_00b30ee2;
                  }
                  lVar10 = 0;
LAB_00b313a1:
                  iVar4 = 0x29;
                }
LAB_00b31354:
                if (iVar4 != (int)lVar10) goto LAB_00b3135e;
                iVar4 = (*(code *)*puVar1)();
                uVar5 = 0;
                local_144 = 0;
                local_140 = (long)iVar4 + local_140;
                uVar12 = local_140;
                local_138[0] = local_140;
              }
              else {
                if ((int)lVar10 == 0x2b) {
                  iVar4 = (*(code *)*puVar1)();
                  uVar5 = 1;
                  lVar10 = (long)iVar4;
                  local_140 = local_140 + lVar10;
                }
                else {
LAB_00b3135e:
                  uVar5 = 0;
                }
LAB_00b30ee2:
                uVar12 = local_140;
                if ((int)local_144 < 0) goto LAB_00b30fa1;
              }
            }
            else {
              uVar5 = 0;
LAB_00b30fa1:
              uVar12 = local_140;
              uVar8 = FUN_00b2f430(uVar3,&local_140,param_3,local_138,param_4,&local_144,1,lVar10);
              if ((int)uVar8 < 0) {
                return uVar8;
              }
            }
            param_1[0xb] = uVar5;
            *param_1 = 8;
            *(ulong *)(param_1 + 8) = local_138[0];
            *(ulong *)(param_1 + 6) = uVar12;
            param_1[10] = local_144;
            uVar8 = 8;
            uVar12 = local_140;
          }
          else {
            uVar8 = (ulong)*param_1;
          }
        }
        goto LAB_00b2fdac;
      case 0x68:
        if ((*(byte *)((long)puVar11 + 6) & 8) == 0) {
          uVar8 = (ulong)*param_1;
        }
        else {
          *param_1 = 6;
          uVar8 = 6;
          param_1[6] = 0xb;
          param_1[7] = 0;
        }
        goto LAB_00b2fdac;
      case 0x6b:
        if ((*(byte *)((long)puVar11 + 5) & 1) == 0) {
          uVar8 = (ulong)*param_1;
        }
        else {
          iVar4 = (*(code *)puVar1[6])(uVar12,param_3);
          uVar12 = local_140;
          iVar6 = (*(code *)*puVar1)(local_140);
          local_140 = local_140 + (long)iVar6;
          if ((iVar4 == 0x3c) || (iVar4 == 0x27)) {
            uVar12 = FUN_00b2f750(iVar4,param_1,&local_140,param_3,param_4);
            if ((int)uVar12 < 0) {
              return uVar12;
            }
            uVar8 = (ulong)*param_1;
            uVar12 = local_140;
          }
          else {
            uVar8 = (ulong)*param_1;
          }
        }
        goto LAB_00b2fdac;
      case 0x73:
        if ((*puVar11 & 0x200000) == 0) {
          uVar8 = (ulong)*param_1;
        }
        else {
          *param_1 = 6;
          uVar8 = 6;
          param_1[6] = 9;
          param_1[7] = 0;
        }
        goto LAB_00b2fdac;
      case 0x75:
        if (uVar12 < param_3) {
          if ((*(byte *)((long)puVar11 + 5) & 0x40) == 0) {
            uVar8 = (ulong)*param_1;
          }
          else {
            uVar3 = FUN_00b2b320(&local_140,param_3,4,4,puVar1);
            if ((int)uVar3 < -1) {
              return 0xffffff2e;
            }
            if (uVar3 == 0xffffffff) {
              return 0xffffff38;
            }
            *param_1 = 4;
            param_1[2] = 0x10;
            if (uVar12 == local_140) {
              uVar3 = 0;
            }
            param_1[6] = uVar3;
            uVar8 = 4;
            uVar12 = local_140;
          }
        }
        else {
          uVar8 = (ulong)*param_1;
        }
        goto LAB_00b2fdac;
      case 0x77:
        if ((*puVar11 & 0x40000) == 0) {
          uVar8 = (ulong)*param_1;
        }
        else {
          *param_1 = 6;
          uVar8 = 6;
          param_1[6] = 0xc;
          param_1[7] = 0;
        }
        goto LAB_00b2fdac;
      case 0x78:
        if (uVar12 < param_3) {
          iVar4 = (*(code *)puVar1[6])(uVar12,param_3);
          if ((iVar4 == 0x7b) && ((*puVar11 & 0x40000000) != 0)) {
            iVar4 = (*(code *)*puVar1)(local_140);
            local_140 = local_140 + (long)iVar4;
            uVar3 = FUN_00b2b320(&local_140,param_3,0,8,puVar1);
            if ((int)uVar3 < 0) {
              return 0xfffffe6f;
            }
            if (local_140 < param_3) {
              pcVar2 = (code *)puVar1[0xf];
              uVar7 = (*(code *)puVar1[6])(local_140,param_3);
              iVar4 = (*pcVar2)(uVar7,0xb);
              if (iVar4 != 0) {
                return 0xffffff2c;
              }
            }
            iVar4 = (*(code *)*puVar1)(uVar12);
            if ((((long)iVar4 + uVar12 < local_140) && (local_140 < param_3)) &&
               (iVar4 = (*(code *)puVar1[6])(local_140,param_3), iVar4 == 0x7d)) {
              iVar4 = (*(code *)*puVar1)(local_140);
              *param_1 = 4;
              param_1[6] = uVar3;
              uVar8 = 4;
              uVar12 = (long)iVar4 + local_140;
            }
            else {
              uVar8 = (ulong)*param_1;
            }
          }
          else if ((*puVar11 & 0x20000000) == 0) {
            uVar8 = (ulong)*param_1;
            uVar12 = local_140;
          }
          else {
            uVar3 = FUN_00b2b320(&local_140,param_3,0,2,puVar1);
            if ((int)uVar3 < 0) {
              return 0xffffff38;
            }
            *param_1 = 1;
            param_1[2] = 0x10;
            if (uVar12 == local_140) {
              uVar3 = 0;
            }
            param_1[6] = uVar3;
            uVar8 = 1;
            uVar12 = local_140;
          }
        }
        else {
          uVar8 = (ulong)*param_1;
        }
        goto LAB_00b2fdac;
      case 0x7a:
        if ((*puVar11 & 0x4000) == 0) {
          uVar8 = (ulong)*param_1;
        }
        else {
LAB_00b30bf5:
          *param_1 = 9;
          uVar8 = 9;
          param_1[6] = 8;
        }
        goto LAB_00b2fdac;
      case 0x7b:
        if ((*puVar11 & 0x200) == 0) {
          uVar8 = (ulong)*param_1;
        }
        else {
          uVar12 = FUN_00b2f1a0(&local_140,param_3,param_1,param_4 + 2,param_4 + 4);
          iVar4 = (int)uVar12;
          if (iVar4 < 0) {
            return uVar12;
          }
          if (iVar4 == 0) break;
          if (iVar4 == 2) {
LAB_00b3085e:
            if ((*(byte *)((long)puVar11 + 9) & 2) == 0) break;
            goto LAB_00b301c7;
          }
          uVar8 = (ulong)*param_1;
          uVar12 = local_140;
        }
        goto LAB_00b2fdac;
      case 0x7c:
        if ((*puVar11 & 0x800) == 0) {
          uVar8 = (ulong)*param_1;
        }
        else {
          *param_1 = 0xd;
          uVar8 = 0xd;
        }
        goto LAB_00b2fdac;
      }
LAB_00b301a5:
      if (local_140 < param_3) {
        iVar4 = (*(code *)puVar1[6])(local_140,param_3);
        if ((iVar4 == 0x3f) && ((*puVar11 & 0x2000000) != 0)) {
          (*(code *)puVar1[6])(local_140,param_3);
          iVar4 = (*(code *)*puVar1)(local_140);
          param_1[8] = 0;
          param_1[9] = 0;
          uVar8 = (ulong)*param_1;
          uVar12 = (long)iVar4 + local_140;
          goto LAB_00b2fdac;
        }
LAB_00b301c7:
        if (param_3 <= local_140) goto LAB_00b30710;
        iVar4 = (*(code *)puVar1[6])(local_140,param_3);
        if (iVar4 == 0x2b) {
          uVar3 = puVar11[1];
          uVar5 = *param_1;
          uVar8 = (ulong)uVar5;
          if ((uVar3 & 0x10) == 0) {
            if (((uVar3 & 0x20) != 0) && (uVar5 == 0xb)) goto LAB_00b3079a;
          }
          else if ((uVar5 != 0xb) || ((uVar3 & 0x20) != 0)) {
LAB_00b3079a:
            (*(code *)puVar1[6])(local_140,param_3);
            iVar4 = (*(code *)*puVar1)(local_140);
            param_1[8] = 1;
            param_1[9] = 1;
            uVar8 = (ulong)*param_1;
            uVar12 = (long)iVar4 + local_140;
            goto LAB_00b2fdac;
          }
        }
        else {
          uVar8 = (ulong)*param_1;
        }
      }
      else {
LAB_00b30710:
        uVar8 = (ulong)*param_1;
      }
      param_1[8] = 1;
      param_1[9] = 0;
      uVar12 = local_140;
      goto LAB_00b2fdac;
    }
    param_1[6] = uVar3;
    param_1[1] = 0;
    if (uVar3 == 0) {
      uVar8 = (ulong)*param_1;
      goto LAB_00b2fdac;
    }
    uVar5 = *puVar11;
    if ((uVar5 & 1) != 0) {
      if (puVar11[5] == uVar3) {
LAB_00b300e0:
        *param_1 = 5;
        uVar8 = 5;
      }
      else {
        if (puVar11[6] == uVar3) goto LAB_00b30190;
        if (puVar11[7] == uVar3) goto LAB_00b30200;
        if (puVar11[8] == uVar3) goto LAB_00b30220;
        if (puVar11[9] != uVar3) goto switchD_00b2fe16_switchD;
        *param_1 = 0xc;
        uVar8 = 0xc;
      }
      goto LAB_00b2fdac;
    }
switchD_00b2fe16_switchD:
    switch(uVar3) {
    case 9:
    case 10:
    case 0xc:
    case 0xd:
    case 0x20:
      goto switchD_00b2fe16_caseD_9;
    default:
      uVar8 = (ulong)*param_1;
      goto LAB_00b2fdac;
    case 0x23:
      if ((*param_4 & 2) == 0) {
        uVar8 = (ulong)*param_1;
        goto LAB_00b2fdac;
      }
      do {
        if (param_3 <= local_140) break;
        uVar7 = (*(code *)puVar1[6])(local_140,param_3);
        iVar4 = (*(code *)*puVar1)(local_140);
        local_140 = local_140 + (long)iVar4;
        iVar4 = (*(code *)puVar1[0xf])(uVar7,0);
      } while (iVar4 == 0);
      break;
    case 0x24:
      if ((uVar5 & 0x800000) == 0) {
        uVar8 = (ulong)*param_1;
      }
      else {
        uVar3 = *param_4;
        *param_1 = 9;
        param_1[6] = (-(uint)((uVar3 & 8) == 0) & 0x10) + 0x10;
        uVar8 = 9;
      }
      goto LAB_00b2fdac;
    case 0x28:
      if (uVar12 < param_3) {
        iVar4 = (*(code *)puVar1[6])(uVar12,param_3);
        uVar12 = local_140;
        if (iVar4 == 0x3f) {
          if ((puVar11[1] & 2) != 0) {
            iVar4 = (*(code *)*puVar1)(local_140);
            local_140 = (long)iVar4 + local_140;
            if (local_140 < param_3) {
              iVar4 = (*(code *)puVar1[6])(local_140,param_3);
              if (iVar4 == 0x23) {
                do {
                  (*(code *)puVar1[6])(local_140,param_3);
                  iVar4 = (*(code *)*puVar1)(local_140);
                  local_140 = (long)iVar4 + local_140;
                  do {
                    while( true ) {
                      if (param_3 <= local_140) {
                        return 0xffffff8a;
                      }
                      uVar3 = (*(code *)puVar1[6])(local_140,param_3);
                      iVar4 = (*(code *)*puVar1)(local_140);
                      local_140 = (long)iVar4 + local_140;
                      if (puVar11[4] == uVar3) break;
                      if (uVar3 == 0x29) goto LAB_00b2fd4f;
                    }
                  } while (param_3 <= local_140);
                } while( true );
              }
              if (param_3 <= local_140) goto LAB_00b3096a;
              iVar4 = (*(code *)puVar1[6])(local_140,param_3);
              bVar14 = iVar4 == 0x52;
              if (iVar4 == 0x26 || bVar14) {
LAB_00b308c4:
                if ((*(byte *)(*(long *)(param_4 + 4) + 7) & 8) == 0) goto LAB_00b30827;
                if ((iVar4 != 0x30) && (!bVar14)) {
                  if (iVar4 != 0x26) goto LAB_00b30994;
                  iVar4 = (*(code *)*puVar1)();
                  local_140 = local_140 + (long)iVar4;
                  uVar9 = 0;
                  goto LAB_00b30999;
                }
                iVar4 = (*(code *)*puVar1)();
                local_140 = (long)iVar4 + local_140;
                if ((param_3 <= local_140) ||
                   (iVar4 = (*(code *)puVar1[6])(local_140,param_3), iVar4 != 0x29)) {
                  return 0xffffff29;
                }
                iVar4 = (*(code *)*puVar1)(local_140);
                local_144 = 0;
                uVar12 = (long)iVar4 + local_140;
                local_140 = uVar12;
                local_138[0] = uVar12;
                goto LAB_00b30939;
              }
              iVar6 = (*(code *)puVar1[0xf])(iVar4,4);
              uVar8 = local_140;
              if (iVar6 != 0) {
                bVar14 = false;
                goto LAB_00b308c4;
              }
              if (((iVar4 - 0x2bU & 0xfffffffd) == 0) &&
                 ((*(byte *)(*(long *)(param_4 + 4) + 7) & 8) != 0)) {
                iVar6 = (*(code *)*puVar1)(local_140);
                local_140 = (long)iVar6 + local_140;
                uVar7 = 0;
                if (local_140 < param_3) {
                  uVar7 = (*(code *)puVar1[6])(local_140,param_3);
                }
                iVar6 = (*(code *)puVar1[0xf])(uVar7,4);
                if (iVar6 != 0) {
                  if (iVar4 == 0x2d) {
                    local_140 = uVar8;
                  }
                  uVar12 = local_140;
                  uVar8 = FUN_00b2f430(0x28,&local_140,param_3,local_138,param_4,&local_144,1,
                                       param_6);
                  if ((int)uVar8 < 0) {
                    return uVar8;
                  }
                  *(ulong *)(param_1 + 6) = uVar12;
                  *param_1 = 8;
                  *(ulong *)(param_1 + 8) = local_138[0];
                  param_1[0xb] = 1;
                  param_1[10] = local_144;
                  uVar8 = 8;
                  uVar12 = local_140;
                  goto LAB_00b2fdac;
                }
              }
            }
            else {
LAB_00b3096a:
              iVar4 = (*(code *)puVar1[0xf])(0,4);
              if ((iVar4 != 0) && ((*(byte *)(*(long *)(param_4 + 4) + 7) & 8) != 0)) {
LAB_00b30994:
                uVar9 = 1;
LAB_00b30999:
                uVar12 = local_140;
                uVar8 = FUN_00b2f430(0x28,&local_140,param_3,local_138,param_4,&local_144,uVar9,
                                     puVar1);
                if ((int)uVar8 < 0) {
                  return uVar8;
                }
LAB_00b30939:
                *(ulong *)(param_1 + 6) = uVar12;
                *param_1 = 8;
                *(ulong *)(param_1 + 8) = local_138[0];
                param_1[0xb] = 0;
                param_1[10] = local_144;
                uVar8 = 8;
                uVar12 = local_140;
                goto LAB_00b2fdac;
              }
            }
LAB_00b30827:
            if (((local_140 < param_3) &&
                (iVar4 = (*(code *)puVar1[6])(local_140,param_3), iVar4 == 0x50)) &&
               ((*(byte *)(*(long *)(param_4 + 4) + 7) & 0x40) != 0)) {
              iVar4 = (*(code *)*puVar1)(local_140);
              local_140 = (long)iVar4 + local_140;
              uVar8 = param_3;
              iVar4 = (*(code *)puVar1[6])();
              iVar6 = (*(code *)*puVar1)(local_140);
              uVar13 = (long)iVar6 + local_140;
              local_140 = uVar13;
              if (iVar4 == 0x3d) {
                uVar12 = FUN_00b2f750(0x28,param_1,&local_140,param_3,param_4);
                if ((int)uVar12 < 0) {
                  return uVar12;
                }
              }
              else {
                if (iVar4 != 0x3e) goto LAB_00b30845;
                uVar12 = FUN_00b2f430(0x28,&local_140,param_3,local_138,param_4,&local_144,0,uVar8);
                if ((int)uVar12 < 0) {
                  return uVar12;
                }
                *param_1 = 8;
                *(ulong *)(param_1 + 6) = uVar13;
                *(ulong *)(param_1 + 8) = local_138[0];
                param_1[0xb] = 0;
                param_1[10] = local_144;
              }
              uVar8 = (ulong)*param_1;
              uVar12 = local_140;
              goto LAB_00b2fdac;
            }
          }
LAB_00b30845:
          uVar5 = *puVar11;
        }
        else {
          uVar5 = *puVar11;
        }
      }
      if ((uVar5 & 0x1000) == 0) {
        uVar8 = (ulong)*param_1;
      }
      else {
        *param_1 = 0xe;
        uVar8 = 0xe;
      }
      goto LAB_00b2fdac;
    case 0x29:
      if ((uVar5 & 0x1000) == 0) {
        uVar8 = (ulong)*param_1;
      }
      else {
        *param_1 = 0xf;
        uVar8 = 0xf;
      }
      goto LAB_00b2fdac;
    case 0x2a:
      if ((uVar5 & 4) != 0) goto LAB_00b30190;
      uVar8 = (ulong)*param_1;
      goto LAB_00b2fdac;
    case 0x2b:
      if ((uVar5 & 0x10) != 0) goto LAB_00b30220;
      uVar8 = (ulong)*param_1;
      goto LAB_00b2fdac;
    case 0x2e:
      if ((uVar5 & 2) != 0) goto LAB_00b300e0;
      uVar8 = (ulong)*param_1;
      goto LAB_00b2fdac;
    case 0x3f:
      if ((uVar5 & 0x40) != 0) goto LAB_00b30200;
      uVar8 = (ulong)*param_1;
      goto LAB_00b2fdac;
    case 0x5b:
      if ((uVar5 & 0x20000) == 0) {
        uVar8 = (ulong)*param_1;
      }
      else {
        *param_1 = 0x10;
        uVar8 = 0x10;
      }
      goto LAB_00b2fdac;
    case 0x5d:
      if (*(ulong *)(param_4 + 10) < *param_2) {
        if ((code *)PTR_FUN_011bec88 == FUN_00b2b210) {
          uVar8 = (ulong)*param_1;
        }
        else if ((*(byte *)(*(long *)(param_4 + 4) + 0xb) & 1) == 0) {
          uVar8 = (ulong)*param_1;
        }
        else {
          FUN_00b2af10(local_138,0x100,*(undefined8 *)(param_4 + 2),*(ulong *)(param_4 + 10),
                       *(undefined8 *)(param_4 + 0xc),"regular expression has \'%s\' without escape"
                       ,&DAT_00ca3c6b);
          (*(code *)PTR_FUN_011bec88)(local_138);
          uVar8 = (ulong)*param_1;
          uVar12 = local_140;
        }
      }
      else {
        uVar8 = (ulong)*param_1;
      }
      goto LAB_00b2fdac;
    case 0x5e:
      if ((uVar5 & 0x800000) == 0) {
        uVar8 = (ulong)*param_1;
      }
      else {
        uVar3 = *param_4;
        *param_1 = 9;
        param_1[6] = ((uVar3 & 8) == 0) + 1;
        uVar8 = 9;
      }
      goto LAB_00b2fdac;
    case 0x7b:
      if ((uVar5 & 0x100) == 0) {
        uVar8 = (ulong)*param_1;
      }
      else {
        uVar12 = FUN_00b2f1a0(&local_140,param_3,param_1,param_4 + 2,param_4 + 4);
        iVar4 = (int)uVar12;
        if (iVar4 < 0) {
          return uVar12;
        }
        if (iVar4 == 0) goto LAB_00b301a5;
        if (iVar4 == 2) goto LAB_00b3085e;
        uVar8 = (ulong)*param_1;
        uVar12 = local_140;
      }
      goto LAB_00b2fdac;
    case 0x7c:
      if ((uVar5 & 0x400) == 0) {
        uVar8 = (ulong)*param_1;
      }
      else {
        *param_1 = 0xd;
        uVar8 = 0xd;
      }
      goto LAB_00b2fdac;
    }
  } while( true );
switchD_00b2fe16_caseD_9:
  if ((*param_4 & 2) == 0) {
    uVar8 = (ulong)*param_1;
LAB_00b2fdac:
    *param_2 = uVar12;
    return uVar8;
  }
  goto LAB_00b2fd4f;
}


// ==== entry=00b313d0 name=FUN_00b313d0 size=90 ====

void FUN_00b313d0(undefined8 param_1,long param_2)

{
  int iVar1;
  long lVar2;
  
  iVar1 = FUN_00b2bff0();
  lVar2 = (long)iVar1;
  iVar1 = FUN_00b2bff0(param_2);
  if ((-1 < (int)lVar2) && (-1 < iVar1)) {
    lVar2 = lVar2 + (long)iVar1 * 6;
    if (*(uint *)(&DAT_00d42f20 + lVar2 * 4) < 7) {
                    /* WARNING: Could not recover jumptable at 0x00b3140a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*(code *)(&PTR_LAB_00d42770)[*(uint *)(&DAT_00d42f20 + lVar2 * 4)])();
      return;
    }
    *(undefined8 *)(param_2 + 8) = 0;
    FUN_00b2d8d0(param_2);
    return;
  }
  return;
}


// ==== entry=00b31550 name=FUN_00b31550 size=7924 ====

/* WARNING: Type propagation algorithm not settling */

uint FUN_00b31550(long *param_1,uint *param_2,uint param_3,undefined8 *param_4,uint *param_5,
                 uint *param_6)

{
  uint uVar1;
  undefined8 uVar2;
  char cVar3;
  byte bVar4;
  bool bVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  int iVar10;
  long lVar11;
  long lVar12;
  uint *puVar13;
  void *pvVar14;
  undefined8 *puVar15;
  long lVar16;
  long lVar17;
  ulong uVar18;
  long lVar19;
  int *piVar20;
  undefined1 *puVar21;
  int *piVar22;
  uint uVar23;
  undefined8 *puVar24;
  uint *puVar25;
  uint *puVar26;
  size_t __n;
  uint *puVar27;
  undefined8 uVar28;
  long local_178;
  uint local_154;
  uint *local_150;
  uint local_148;
  undefined4 uStack_144;
  int *local_140;
  undefined8 local_138;
  undefined8 uStack_130;
  long local_128;
  long *local_120;
  
  uVar9 = *param_2;
  *param_1 = 0;
  if (uVar9 == param_3) {
switchD_00b3158a_caseD_0:
    lVar11 = FUN_00b2edc0(0,0);
    uVar9 = *param_2;
    *param_1 = lVar11;
    return uVar9;
  }
  puVar26 = param_5;
  switch(uVar9) {
  case 0:
  case 0xd:
    goto switchD_00b3158a_caseD_0;
  default:
    goto switchD_00b3158a_caseD_2;
  case 4:
    lVar11 = FUN_00b2edc0(0,0);
    *param_1 = lVar11;
    if (lVar11 == 0) {
      return 0xfffffffb;
    }
    uVar9 = param_2[6];
    uVar28 = *(undefined8 *)(*(long *)(param_6 + 2) + 0x48);
LAB_00b32019:
    uVar9 = FUN_00b2ee40(lVar11,uVar28,uVar9);
    if (uVar9 != 0) {
      return uVar9;
    }
    goto LAB_00b3162d;
  case 5:
    lVar11 = FUN_00b2c1e0();
    *param_1 = lVar11;
    break;
  case 6:
    uVar9 = param_2[6];
    if (uVar9 != 9) {
      if ((int)uVar9 < 10) {
        if (uVar9 != 4) {
          return 0xfffffff5;
        }
      }
      else if (uVar9 != 0xb) {
        if (uVar9 != 0xc) {
          return 0xfffffff5;
        }
        uVar9 = *param_6;
        uVar6 = param_2[7];
        if (DAT_011c3818 == (undefined8 *)0x0) {
          puVar15 = (undefined8 *)FUN_00b2c0c0();
          if (puVar15 == (undefined8 *)0x0) goto LAB_00b32058;
        }
        else {
          puVar15 = DAT_011c3818;
          DAT_011c3818 = (undefined8 *)*DAT_011c3818;
        }
        *(uint *)((long)puVar15 + 0xc) = uVar9 & 0x1000;
        *puVar15 = 0xc00000002;
        *(uint *)(puVar15 + 1) = uVar6;
        *param_1 = (long)puVar15;
        uVar9 = 0;
        goto LAB_00b31725;
      }
    }
    iVar10 = (**(code **)(*(long *)(param_6 + 2) + 0x80))(uVar9,&local_148,&local_140);
    if (((iVar10 != 0) || ((*param_6 & 0x1000) != 0)) || (*local_140 < 8)) {
      lVar11 = FUN_00b2c180();
      *param_1 = lVar11;
      if (lVar11 == 0) {
        return 0xfffffffb;
      }
      puVar26 = (uint *)(ulong)*param_6;
      uVar9 = FUN_00b2cd10(lVar11,param_2[6],0,0,puVar26,param_6 + 2);
      if (uVar9 != 0) {
        return uVar9;
      }
      if (param_2[7] != 0) {
        *(uint *)(lVar11 + 4) = *(uint *)(lVar11 + 4) | 1;
      }
      goto LAB_00b31722;
    }
    local_138 = *(uint **)(param_6 + 2);
    uStack_130 = CONCAT44(param_2[6],param_2[7]);
    if (DAT_011c3810 == 0) {
      DAT_011c3810 = FUN_00b442d0(&PTR_FUN_011bec70,10);
      if (DAT_011c3810 == 0) {
        return 0xfffffffb;
      }
    }
    else {
      iVar10 = FUN_00b44420(DAT_011c3810,&local_138,param_1);
      uVar9 = 0;
      if (iVar10 != 0) goto LAB_00b31725;
    }
    piVar20 = local_140;
    uVar9 = param_2[7];
    lVar11 = FUN_00b2c180();
    if (lVar11 == 0) goto LAB_00b32058;
    if (uVar9 != 0) {
      *(uint *)(lVar11 + 4) = *(uint *)(lVar11 + 4) | 1;
    }
    *(undefined8 *)(lVar11 + 8) = 0;
    *(undefined8 *)(lVar11 + 0x10) = 0;
    *(undefined8 *)(lVar11 + 0x18) = 0;
    *(undefined8 *)(lVar11 + 0x20) = 0;
    if ((local_148 == 0) || (piVar20 == (int *)0x0)) {
      if (piVar20 != (int *)0x0) goto LAB_00b321b3;
LAB_00b32f9a:
      *(undefined8 *)(lVar11 + 0x28) = 0;
    }
    else {
      iVar10 = *piVar20;
      if (0 < iVar10) {
        puVar27 = (uint *)(piVar20 + 2);
        puVar26 = (uint *)(piVar20 + (ulong)(iVar10 - 1) * 2 + 4);
        do {
          uVar9 = puVar27[-1];
          if (uVar9 <= *puVar27) {
            if (local_148 <= uVar9) break;
            while( true ) {
              uVar6 = uVar9 + 0x1f;
              if (-1 < (int)uVar9) {
                uVar6 = uVar9;
              }
              cVar3 = (char)uVar9;
              bVar4 = (byte)((int)uVar9 >> 0x1f);
              uVar9 = uVar9 + 1;
              puVar13 = (uint *)(lVar11 + 8 + (long)((int)uVar6 >> 5) * 4);
              *puVar13 = *puVar13 | 1 << ((cVar3 + (bVar4 >> 3) & 0x1f) - (bVar4 >> 3) & 0x1f);
              if (*puVar27 < uVar9) break;
              if (local_148 == uVar9) goto LAB_00b321b3;
            }
          }
          puVar27 = puVar27 + 2;
        } while (puVar26 != puVar27);
LAB_00b321b3:
        iVar10 = *piVar20;
      }
      if (iVar10 == 0) goto LAB_00b32f9a;
      puVar15 = malloc(0x10);
      if (puVar15 == (undefined8 *)0x0) goto LAB_00b32058;
      *puVar15 = piVar20;
      *(int *)((long)puVar15 + 0xc) = iVar10 + 1;
      *(int *)(puVar15 + 1) = iVar10 + 1;
      *(undefined8 **)(lVar11 + 0x28) = puVar15;
    }
    *param_1 = lVar11;
    *(uint *)(lVar11 + 4) = *(uint *)(lVar11 + 4) | 2;
    puVar15 = malloc(0x10);
    lVar12 = DAT_011c3810;
    *puVar15 = local_138;
    puVar15[1] = uStack_130;
    FUN_00b44620(lVar12,puVar15,lVar11);
    goto LAB_00b31722;
  case 7:
    uVar9 = param_2[6];
    uVar6 = param_2[0xb];
    puVar27 = param_2 + 7;
    uVar23 = param_2[0xc];
    uVar1 = param_2[10];
    if (1 < (int)uVar9) {
      puVar27 = *(uint **)(param_2 + 8);
    }
    if (DAT_011c3818 == (undefined8 *)0x0) {
      puVar15 = (undefined8 *)FUN_00b2c0c0();
      if (puVar15 == (undefined8 *)0x0) goto LAB_00b32058;
    }
    else {
      puVar15 = DAT_011c3818;
      DAT_011c3818 = (undefined8 *)*DAT_011c3818;
    }
    *puVar15 = 4;
    *(uint *)(puVar15 + 1) = uVar9;
    puVar15[5] = 0;
    if (uVar1 != 0) {
      *(undefined4 *)((long)puVar15 + 4) = 0x800;
    }
    if (uVar6 != 0) {
      *(uint *)((long)puVar15 + 4) = *(uint *)((long)puVar15 + 4) | 0x2000;
      *(uint *)(puVar15 + 6) = uVar23;
    }
    if (0 < (int)uVar9) {
      puVar26 = param_6 + 0x1c;
      puVar13 = puVar27;
      do {
        if ((int)*puVar13 <= (int)param_6[0x18]) {
          puVar25 = *(uint **)(param_6 + 0x2c);
          if (*(uint **)(param_6 + 0x2c) == (uint *)0x0) {
            puVar25 = puVar26;
          }
          if (*(long *)(puVar25 + (long)(int)*puVar13 * 2) == 0) {
            *(uint *)((long)puVar15 + 4) = *(uint *)((long)puVar15 + 4) | 0x80;
            break;
          }
        }
        puVar13 = puVar13 + 1;
      } while (puVar27 + (ulong)(uVar9 - 1) + 1 != puVar13);
      lVar11 = 0;
      if ((int)uVar9 < 7) {
        do {
          *(uint *)((long)puVar15 + lVar11 * 4 + 0xc) = puVar27[lVar11];
          lVar11 = lVar11 + 1;
        } while ((int)lVar11 < (int)uVar9);
      }
      else {
        pvVar14 = malloc((long)(int)uVar9 << 2);
        if (pvVar14 == (void *)0x0) {
          FUN_00b2d8d0(puVar15);
          goto LAB_00b32058;
        }
        puVar15[5] = pvVar14;
        lVar11 = 0;
        do {
          *(uint *)((long)pvVar14 + lVar11 * 4) = puVar27[lVar11];
          lVar11 = lVar11 + 1;
        } while ((int)lVar11 < (int)uVar9);
      }
    }
    *param_1 = (long)puVar15;
    uVar9 = 0;
    goto LAB_00b31725;
  case 8:
    uVar9 = param_2[10];
    if ((int)uVar9 < 0) {
LAB_00b31b0a:
      uVar9 = uVar9 + 1 + param_6[0x18];
      if ((int)uVar9 < 1) {
        return 0xffffff30;
      }
    }
    else if (param_2[0xb] != 0) {
      uVar9 = (uVar9 - 1) + (uint)(uVar9 == 0);
      goto LAB_00b31b0a;
    }
    uVar28 = *(undefined8 *)(param_2 + 8);
    uVar2 = *(undefined8 *)(param_2 + 6);
    if (DAT_011c3818 != (undefined8 *)0x0) {
      puVar15 = DAT_011c3818;
      DAT_011c3818 = (undefined8 *)*DAT_011c3818;
LAB_00b31b3d:
      *(uint *)(puVar15 + 1) = uVar9;
      *puVar15 = 10;
      puVar15[4] = 0;
      puVar15[2] = uVar2;
      puVar15[3] = uVar28;
      *param_1 = (long)puVar15;
      param_6[0x14] = param_6[0x14] + 1;
      uVar9 = 0;
      goto LAB_00b31725;
    }
    puVar15 = (undefined8 *)FUN_00b2c0c0();
    if (puVar15 != (undefined8 *)0x0) goto LAB_00b31b3d;
    goto LAB_00b32058;
  case 9:
    lVar11 = FUN_00b2ebf0(param_2[6]);
    *param_1 = lVar11;
    if (lVar11 == 0) {
      return 0xfffffffb;
    }
    *(uint *)(lVar11 + 0x14) = param_2[7];
    uVar9 = 0;
    goto LAB_00b31725;
  case 10:
  case 0xb:
    if ((*(uint *)(*(long *)(param_6 + 4) + 8) & 1) != 0) {
      if ((*(uint *)(*(long *)(param_6 + 4) + 8) & 2) != 0) {
        return 0xffffff8f;
      }
      lVar11 = FUN_00b2edc0(0,0);
      *param_1 = lVar11;
      goto LAB_00b31722;
    }
  case 3:
switchD_00b3158a_caseD_3:
    lVar11 = FUN_00b2edc0(*(undefined8 *)(param_2 + 4),*param_4);
    *param_1 = lVar11;
    if (lVar11 == 0) {
      return 0xfffffffb;
    }
LAB_00b3162d:
    do {
      uVar6 = FUN_00b2fd20(param_2,param_4,param_5,param_6);
      if ((int)uVar6 < 0) {
        return uVar6;
      }
      if (uVar6 == 3) {
        uVar9 = FUN_00b2ec50(*param_1,*(undefined8 *)(param_2 + 4),*param_4);
      }
      else {
        if (uVar6 != 4) {
          uVar9 = 0;
          goto LAB_00b31745;
        }
        uVar9 = FUN_00b2ee40(*param_1,*(undefined8 *)(*(long *)(param_6 + 2) + 0x48),param_2[6]);
      }
      if ((int)uVar9 < 0) {
        return uVar9;
      }
    } while( true );
  case 0xc:
    lVar11 = FUN_00b2c1e0();
    *param_1 = lVar11;
    if (lVar11 == 0) {
      return 0xfffffffb;
    }
    lVar11 = FUN_00b2c220(0,0xffffffff,0);
    if (lVar11 == 0) {
      return 0xfffffffb;
    }
    *(long *)(lVar11 + 8) = *param_1;
    *param_1 = lVar11;
    uVar9 = 0;
    goto LAB_00b31725;
  case 0xe:
    puVar15 = *(undefined8 **)(param_6 + 2);
    local_150 = (uint *)*param_4;
    if (param_5 <= local_150) {
      return 0xffffff8b;
    }
    uVar9 = *param_6;
    puVar24 = param_4;
    iVar10 = (*(code *)puVar15[6])();
    if ((iVar10 != 0x3f) || ((*(byte *)(*(long *)(param_6 + 4) + 4) & 2) == 0)) {
      uVar9 = *param_6;
      if ((uVar9 & 0x80) != 0) goto switchD_00b323bf_caseD_3a;
      lVar11 = FUN_00b2c120(1);
      if (lVar11 == 0) goto LAB_00b32058;
      *(uint *)(lVar11 + 0x10) = uVar9;
      *param_1 = lVar11;
      local_154 = FUN_00b2b770(param_6);
      if ((int)local_154 < 0) {
        return local_154;
      }
      *(uint *)(*param_1 + 0xc) = local_154;
      goto LAB_00b31bee;
    }
    iVar10 = (*(code *)*puVar15)(local_150);
    local_150 = (uint *)((long)iVar10 + (long)local_150);
    if (param_5 <= local_150) {
      return 0xffffff8a;
    }
    uVar6 = (*(code *)puVar15[6])(local_150,param_5);
    uVar18 = (ulong)uVar6;
    iVar10 = (*(code *)*puVar15)(local_150);
    local_150 = (uint *)((long)iVar10 + (long)local_150);
    switch(uVar6) {
    case 0x21:
      lVar11 = FUN_00b2ebf0(0x800);
      *param_1 = lVar11;
      break;
    default:
      goto LAB_00b315a8;
    case 0x27:
      bVar5 = false;
      if ((*(byte *)(*(long *)(param_6 + 4) + 4) & 0x80) == 0) {
        return 0xffffff89;
      }
      goto LAB_00b3278b;
    case 0x28:
      if ((*(byte *)(*(long *)(param_6 + 4) + 7) & 0x20) == 0) {
        return 0xffffff89;
      }
      iVar10 = (*(code *)puVar15[6])(local_150,param_5);
      puVar26 = local_150;
      iVar7 = (*(code *)*puVar15)(local_150);
      local_150 = (uint *)((long)local_150 + (long)iVar7);
      iVar7 = (*(code *)puVar15[0xf])(iVar10,4);
      puVar27 = local_150;
      if (iVar7 == 0) {
        if ((iVar10 != 0x3c) && (uVar18 = 0xffffff84, iVar10 != 0x27)) {
          return 0xffffff84;
        }
        uVar9 = FUN_00b2f430(iVar10,&local_150,param_5,&local_140,param_6,&local_154,0);
        if ((int)uVar9 < 0) {
          return uVar9;
        }
        iVar10 = (*(code *)puVar15[6])(local_150,param_5,uVar18);
        iVar7 = (*(code *)*puVar15)(local_150);
        local_150 = (uint *)((long)local_150 + (long)iVar7);
        if (iVar10 != 0x29) {
          return 0xffffff89;
        }
        iVar10 = FUN_00b2e9b0(*(undefined8 *)(param_6 + 0x12),puVar27,local_140);
        if (iVar10 < 1) {
          *(uint **)(param_6 + 0xe) = puVar27;
          *(int **)(param_6 + 0x10) = local_140;
          return 0xffffff27;
        }
        if ((*(byte *)(*(long *)(param_6 + 4) + 8) & 0x20) != 0) {
          lVar11 = 0;
          do {
            if ((int)param_6[0x18] < (int)local_138[lVar11]) {
              return 0xffffff30;
            }
            puVar26 = *(uint **)(param_6 + 0x2c);
            if (*(uint **)(param_6 + 0x2c) == (uint *)0x0) {
              puVar26 = param_6 + 0x1c;
            }
            if (*(long *)(puVar26 + (long)(int)local_138[lVar11] * 2) == 0) {
              return 0xffffff30;
            }
            lVar11 = lVar11 + 1;
          } while ((int)lVar11 < iVar10);
        }
        local_154 = *local_138;
        lVar11 = FUN_00b2c120(8);
        *param_1 = lVar11;
        if (lVar11 == 0) {
          return 0xfffffffb;
        }
        *(uint *)(lVar11 + 0xc) = local_154;
        if (puVar27 != (uint *)0x0) {
          *(uint *)(*param_1 + 4) = *(uint *)(*param_1 + 4) | 0x800;
        }
      }
      else {
        uVar28 = 1;
        local_150 = puVar26;
        uVar9 = FUN_00b2f430(0x28,&local_150,param_5,&local_140,param_6,&local_154,1,puVar24);
        if ((int)uVar9 < 0) {
          return uVar9;
        }
        if (((int)local_154 < 0) && (local_154 = local_154 + 1 + param_6[0x18], (int)local_154 < 1))
        {
          return 0xffffff30;
        }
        if ((*(byte *)(*(long *)(param_6 + 4) + 8) & 0x20) != 0) {
          if ((int)param_6[0x18] < (int)local_154) {
            return 0xffffff30;
          }
          puVar26 = *(uint **)(param_6 + 0x2c);
          if (puVar26 == (uint *)0x0) {
            puVar26 = param_6 + 0x1c;
          }
          if (*(long *)(puVar26 + (long)(int)local_154 * 2) == 0) {
            return 0xffffff30;
          }
        }
        lVar11 = FUN_00b2c120(8,uVar28);
        *param_1 = lVar11;
        if (lVar11 == 0) {
          return 0xfffffffb;
        }
        *(uint *)(lVar11 + 0xc) = local_154;
      }
      break;
    case 0x2d:
    case 0x61:
    case 100:
    case 0x69:
    case 0x6c:
    case 0x6d:
    case 0x73:
    case 0x75:
    case 0x78:
switchD_00b323bf_caseD_2d:
      bVar5 = false;
      do {
        iVar10 = (int)uVar18;
        switch(iVar10) {
        case 0x29:
        case 0x3a:
          if (iVar10 == 0x29) {
            lVar11 = FUN_00b2c120(2);
            if (lVar11 == 0) goto LAB_00b32058;
            *(uint *)(lVar11 + 0x10) = uVar9;
            *param_1 = lVar11;
            *param_4 = local_150;
            goto LAB_00b33323;
          }
          if (iVar10 == 0x3a) {
            uVar6 = *param_6;
            *param_6 = uVar9;
            uVar23 = FUN_00b2fd20(param_2,&local_150,param_5,param_6);
            if ((int)uVar23 < 0) {
              return uVar23;
            }
            puVar26 = param_5;
            uVar23 = FUN_00b33650(&local_138,param_2,0xf,&local_150,param_5,param_6);
            *param_6 = uVar6;
            if ((int)uVar23 < 0) {
              return uVar23;
            }
            lVar11 = FUN_00b2c120(2);
            if (lVar11 != 0) {
              *(uint *)(lVar11 + 0x10) = uVar9;
              uVar9 = 0;
              *param_1 = lVar11;
              *(uint **)(lVar11 + 0x18) = local_138;
              *param_4 = local_150;
              goto LAB_00b31725;
            }
            goto LAB_00b32058;
          }
          break;
        default:
          return 0xffffff89;
        case 0x2d:
          bVar5 = true;
          break;
        case 0x61:
          if ((*(byte *)(*(long *)(param_6 + 4) + 4) & 0xc) == 0) {
            return 0xffffff89;
          }
          if (bVar5) {
            return 0xffffff89;
          }
          uVar9 = uVar9 & 0xffff9fff | 0x1000;
          break;
        case 100:
          if (((*(uint *)(*(long *)(param_6 + 4) + 4) & 4) == 0) || (!(bool)(bVar5 ^ 1U))) {
            if ((*(uint *)(*(long *)(param_6 + 4) + 4) & 8) == 0) {
              return 0xffffff89;
            }
            if (!(bool)(bVar5 ^ 1U)) {
              return 0xffffff89;
            }
            uVar9 = uVar9 | 0x7000;
            bVar5 = false;
          }
          else {
            uVar9 = uVar9 & 0xffffefff;
            bVar5 = false;
          }
          break;
        case 0x69:
          if (bVar5) {
            uVar9 = uVar9 & 0xfffffffe;
          }
          else {
            uVar9 = uVar9 | 1;
          }
          break;
        case 0x6c:
          if ((*(byte *)(*(long *)(param_6 + 4) + 4) & 4) == 0) {
            return 0xffffff89;
          }
          if (bVar5) {
            return 0xffffff89;
          }
          uVar9 = uVar9 & 0xffffefff;
          break;
        case 0x6d:
          if ((*(uint *)(*(long *)(param_6 + 4) + 4) & 4) == 0) {
            if ((*(uint *)(*(long *)(param_6 + 4) + 4) & 8) == 0) {
              return 0xffffff89;
            }
            goto LAB_00b32553;
          }
          if (bVar5) {
            uVar9 = uVar9 | 8;
          }
          else {
            uVar9 = uVar9 & 0xfffffff7;
          }
          break;
        case 0x73:
          if ((*(byte *)(*(long *)(param_6 + 4) + 4) & 4) == 0) {
            return 0xffffff89;
          }
LAB_00b32553:
          if (bVar5) {
            uVar9 = uVar9 & 0xfffffffb;
          }
          else {
            uVar9 = uVar9 | 4;
          }
          break;
        case 0x75:
          if ((*(byte *)(*(long *)(param_6 + 4) + 4) & 0xc) == 0) {
            return 0xffffff89;
          }
          if (bVar5) {
            return 0xffffff89;
          }
          uVar9 = uVar9 & 0xffff8fff;
          break;
        case 0x78:
          if (bVar5) {
            uVar9 = uVar9 & 0xfffffffd;
          }
          else {
            uVar9 = uVar9 | 2;
          }
        }
        if (param_5 <= local_150) {
          return 0xffffff8a;
        }
        uVar6 = (*(code *)puVar15[6])(local_150,param_5);
        uVar18 = (ulong)uVar6;
        iVar10 = (*(code *)*puVar15)(local_150);
        local_150 = (uint *)((long)local_150 + (long)iVar10);
      } while( true );
    case 0x3a:
switchD_00b323bf_caseD_3a:
      uVar9 = FUN_00b2fd20(param_2,&local_150,param_5,param_6);
      if ((int)uVar9 < 0) {
        return uVar9;
      }
      puVar26 = param_5;
      uVar9 = FUN_00b33650(param_1,param_2,0xf,&local_150,param_5,param_6);
      if (-1 < (int)uVar9) {
        *param_4 = local_150;
        uVar9 = 1;
        goto LAB_00b31725;
      }
      return uVar9;
    case 0x3c:
      iVar10 = (*(code *)puVar15[6])(local_150,param_5);
      puVar26 = local_150;
      iVar7 = (*(code *)*puVar15)(local_150);
      local_150 = (uint *)((long)local_150 + (long)iVar7);
      if (iVar10 == 0x3d) {
        lVar11 = FUN_00b2ebf0(0x1000);
        *param_1 = lVar11;
      }
      else {
        if (iVar10 != 0x21) {
          if ((*(byte *)(*(long *)(param_6 + 4) + 4) & 0x80) == 0) {
            return 0xffffff89;
          }
          bVar5 = false;
          local_150 = puVar26;
          goto LAB_00b3278b;
        }
        lVar11 = FUN_00b2ebf0(0x2000);
        *param_1 = lVar11;
      }
      break;
    case 0x3d:
      lVar11 = FUN_00b2ebf0(0x400);
      *param_1 = lVar11;
      break;
    case 0x3e:
      lVar11 = FUN_00b2c120(4);
      *param_1 = lVar11;
      break;
    case 0x40:
      if ((*(uint *)(*(long *)(param_6 + 4) + 4) & 0x400) == 0) {
        return 0xffffff89;
      }
      puVar27 = local_150;
      if ((*(uint *)(*(long *)(param_6 + 4) + 4) & 0x80) != 0) {
        uVar9 = (*(code *)puVar15[6])(local_150,param_5);
        puVar27 = local_150;
        uVar18 = (ulong)uVar9;
        iVar10 = (*(code *)*puVar15)(local_150);
        if ((uVar9 == 0x3c) || (uVar9 == 0x27)) {
          bVar5 = true;
          local_150 = (uint *)((long)local_150 + (long)iVar10);
          goto LAB_00b3278b;
        }
      }
      local_150 = puVar27;
      uVar9 = *param_6;
      lVar11 = FUN_00b2c120(1);
      if (lVar11 == 0) goto LAB_00b32058;
      *(uint *)(lVar11 + 0x10) = uVar9;
      *param_1 = lVar11;
      local_154 = FUN_00b2b770(param_6);
      if ((int)local_154 < 0) {
        FUN_00b2d8d0();
        if ((int)local_154 < 0) {
          return local_154;
        }
        uVar9 = local_154;
        if (local_154 == 1) goto LAB_00b31725;
        if (local_154 == 2) {
LAB_00b33323:
          uVar9 = *param_6;
          *param_6 = *(uint *)(*param_1 + 0x10);
          uVar6 = FUN_00b2fd20(param_2,param_4,param_5,param_6);
          if ((int)uVar6 < 0) {
            return uVar6;
          }
          uVar6 = FUN_00b33650(&local_138,param_2,param_3,param_4,param_5,param_6);
          *param_6 = uVar9;
          if (-1 < (int)uVar6) {
            uVar9 = *param_2;
            *(uint **)(*param_1 + 0x18) = local_138;
            return uVar9;
          }
          goto LAB_00b32ee1;
        }
        goto LAB_00b31722;
      }
      if (0x1f < (int)local_154) {
        FUN_00b2d8d0();
        return 0xffffff22;
      }
      *(uint *)(*param_1 + 0xc) = local_154;
      param_6[6] = param_6[6] | 1 << ((byte)local_154 & 0x1f);
      break;
    case 0x50:
      if ((*(byte *)(*(long *)(param_6 + 4) + 7) & 0x40) == 0) {
        return 0xffffff89;
      }
      uVar9 = (*(code *)puVar15[6])(local_150,param_5);
      uVar18 = (ulong)uVar9;
      iVar10 = (*(code *)*puVar15)(local_150);
      bVar5 = false;
      local_150 = (uint *)((long)local_150 + (long)iVar10);
      if (uVar9 != 0x3c) {
        return 0xffffff89;
      }
LAB_00b3278b:
      puVar26 = local_150;
      uVar9 = FUN_00b2f430(uVar18,&local_150,param_5,&local_148,param_6,&local_154);
      if ((int)uVar9 < 0) {
        return uVar9;
      }
      uVar9 = FUN_00b2b770(param_6);
      if ((int)uVar9 < 0) {
        return uVar9;
      }
      if ((0x1f < (int)uVar9) && (bVar5)) {
        return 0xffffff22;
      }
      lVar11 = *(long *)(param_6 + 0x12);
      lVar12 = CONCAT44(uStack_144,local_148);
      local_178 = *(long *)(lVar11 + 0x68);
      __n = lVar12 - (long)puVar26;
      if ((long)__n < 1) {
        return 0xffffff2a;
      }
      local_140 = (int *)0x0;
      local_154 = uVar9;
      if (local_178 == 0) {
        local_178 = FUN_00b442d0(&PTR_FUN_011bec60,5);
        *(long *)(lVar11 + 0x68) = local_178;
LAB_00b33196:
        piVar20 = malloc(0x28);
        if (piVar20 == (int *)0x0) {
          return 0xfffffffb;
        }
        iVar10 = *(int *)(*(long *)(lVar11 + 0x48) + 0x1c);
        pvVar14 = malloc((long)iVar10 + __n);
        if (pvVar14 == (void *)0x0) {
          free(piVar20);
          return 0xfffffffb;
        }
        pvVar14 = memcpy(pvVar14,puVar26,__n);
        if (0 < iVar10) {
          puVar21 = (undefined1 *)((long)pvVar14 + __n);
          do {
            *puVar21 = 0;
            puVar21 = puVar21 + 1;
          } while (puVar21 != (undefined1 *)(__n + 1 + (ulong)(iVar10 - 1) + (long)pvVar14));
        }
        *(void **)piVar20 = pvVar14;
        FUN_00b2e870(local_178,pvVar14,(undefined1 *)((long)pvVar14 + __n),piVar20);
        *(size_t *)(piVar20 + 2) = __n;
        piVar20[8] = 0;
        piVar20[9] = 0;
        piVar20[4] = 1;
        piVar20[5] = 0;
LAB_00b33231:
        piVar20[6] = uVar9;
      }
      else {
        local_138 = puVar26;
        uStack_130 = lVar12;
        FUN_00b44420(local_178,&local_138,&local_140);
        piVar20 = local_140;
        if (local_140 == (int *)0x0) goto LAB_00b33196;
        iVar10 = local_140[4];
        if (iVar10 < 1) {
          local_140[4] = iVar10 + 1;
          if (iVar10 + 1 != 1) goto LAB_00b32897;
          goto LAB_00b33231;
        }
        if ((*(byte *)(*(long *)(param_6 + 4) + 9) & 1) == 0) {
          *(long *)(param_6 + 0x10) = lVar12;
          *(uint **)(param_6 + 0xe) = puVar26;
          return 0xffffff25;
        }
        local_140[4] = iVar10 + 1;
        if (iVar10 + 1 == 2) {
          piVar22 = malloc(0x20);
          *(int **)(piVar20 + 8) = piVar22;
          if (piVar22 == (int *)0x0) {
            return 0xfffffffb;
          }
          iVar10 = piVar20[6];
          piVar20[5] = 8;
          piVar22[1] = uVar9;
          *piVar22 = iVar10;
        }
        else {
LAB_00b32897:
          if (local_140[5] < iVar10 + 1) {
            iVar10 = local_140[5] * 2;
            pvVar14 = realloc(*(void **)(local_140 + 8),(long)iVar10 << 2);
            if (pvVar14 == (void *)0x0) {
              return 0xfffffffb;
            }
            *(void **)(piVar20 + 8) = pvVar14;
            piVar20[5] = iVar10;
          }
          *(uint *)(*(long *)(piVar20 + 8) + -4 + (long)piVar20[4] * 4) = uVar9;
        }
      }
      uVar9 = *param_6;
      lVar11 = FUN_00b2c120(1);
      if (lVar11 == 0) goto LAB_00b32058;
      *(uint *)(lVar11 + 4) = *(uint *)(lVar11 + 4) | 0x400;
      *(uint *)(lVar11 + 0x10) = uVar9;
      *param_1 = lVar11;
      *(uint *)(lVar11 + 0xc) = local_154;
      if (((int)local_154 < 0x20) && (bVar5)) {
        param_6[6] = param_6[6] | 1 << ((byte)local_154 & 0x1f);
      }
      param_6[0x19] = param_6[0x19] + 1;
      break;
    case 0x5e:
      if ((*(byte *)(*(long *)(param_6 + 4) + 4) & 4) != 0) {
        uVar9 = uVar9 & 0xffffeff8 | 8;
        uVar6 = (*(code *)puVar15[6])(local_150,param_5);
        uVar18 = (ulong)uVar6;
        iVar10 = (*(code *)*puVar15)(local_150);
        local_150 = (uint *)((long)local_150 + (long)iVar10);
        goto switchD_00b323bf_caseD_2d;
      }
      goto LAB_00b315a8;
    }
LAB_00b31bee:
    if (*param_1 == 0) {
      return 0xfffffffb;
    }
    uVar9 = FUN_00b2fd20(param_2,&local_150,param_5,param_6);
    if ((int)uVar9 < 0) {
      return uVar9;
    }
    puVar26 = param_5;
    uVar6 = FUN_00b33650(&local_138,param_2,0xf,&local_150,param_5,param_6);
    if ((int)uVar6 < 0) {
LAB_00b32ee1:
      FUN_00b2d8d0(local_138);
      return uVar6;
    }
    piVar20 = (int *)*param_1;
    if (*piVar20 == 7) {
      *(uint **)(piVar20 + 2) = local_138;
    }
    else {
      *(uint **)(piVar20 + 6) = local_138;
      lVar11 = *param_1;
      if (*(int *)(lVar11 + 8) == 1) {
        if ((int)param_6[0x18] < *(int *)(lVar11 + 0xc)) {
switchD_00b3158a_caseD_2:
          return 0xfffffff5;
        }
        puVar27 = *(uint **)(param_6 + 0x2c);
        if (*(uint **)(param_6 + 0x2c) == (uint *)0x0) {
          puVar27 = param_6 + 0x1c;
        }
        *(long *)(puVar27 + (long)*(int *)(lVar11 + 0xc) * 2) = lVar11;
      }
      else if ((*(int *)(lVar11 + 8) == 8) && (*local_138 != 9)) {
        lVar11 = FUN_00b2edc0(0,0);
        if (lVar11 == 0) {
          lVar12 = 0;
        }
        else {
          lVar12 = FUN_00b2eba0(lVar11,0);
          if (lVar12 != 0) {
            lVar19 = FUN_00b2eba0(local_138,lVar12);
            lVar11 = 0;
            if (lVar19 != 0) {
              *(long *)(*param_1 + 0x18) = lVar19;
              goto LAB_00b31c73;
            }
          }
        }
        FUN_00b2d8d0(lVar11);
        FUN_00b2d8d0(lVar12);
        FUN_00b2d8d0(*param_1);
        *param_1 = 0;
        return 0xfffffffb;
      }
    }
LAB_00b31c73:
    *param_4 = local_150;
    uVar9 = 0;
    goto LAB_00b31725;
  case 0xf:
    if ((*(byte *)(*(long *)(param_6 + 4) + 8) & 4) == 0) {
      return 0xffffff8c;
    }
    if (param_2[1] == 0) goto switchD_00b3158a_caseD_3;
  case 1:
    local_138 = (uint *)CONCAT71(local_138._1_7_,(char)param_2[6]);
    lVar11 = FUN_00b2edc0(&local_138,(long)&local_138 + 1);
    if (lVar11 != 0) {
      *(uint *)(lVar11 + 0x18) = *(uint *)(lVar11 + 0x18) | 1;
      *param_1 = lVar11;
      for (iVar10 = 1;
          (iVar10 < *(int *)((long)*(undefined8 **)(param_6 + 2) + 0x1c) ||
          (iVar7 = (*(code *)**(undefined8 **)(param_6 + 2))(*(undefined8 *)(*param_1 + 8)),
          iVar7 != iVar10)); iVar10 = iVar10 + 1) {
        uVar9 = FUN_00b2fd20(param_2,param_4,param_5,param_6);
        if ((int)uVar9 < 0) {
          return uVar9;
        }
        if (uVar9 != 1) {
          return 0xffffff32;
        }
        local_138 = (uint *)CONCAT71(local_138._1_7_,(char)param_2[6]);
        uVar9 = FUN_00b2ec50(*param_1,&local_138,(long)&local_138 + 1);
        if ((int)uVar9 < 0) {
          return uVar9;
        }
      }
      uVar9 = 0;
      uVar6 = FUN_00b2fd20(param_2,param_4,param_5,param_6);
      *(uint *)(*param_1 + 0x18) = *(uint *)(*param_1 + 0x18) & 0xfffffffe;
LAB_00b31745:
      do {
        if (1 < uVar6 - 10) {
          return uVar6;
        }
        lVar11 = FUN_00b2c220(param_2[6],param_2[7],uVar6 == 0xb);
        if (lVar11 == 0) {
          return 0xfffffffb;
        }
        *(uint *)(lVar11 + 0x18) = param_2[8];
        if (*(long *)(lVar11 + 0x10) == 0x100000001) {
          lVar12 = lVar11;
          if (param_2[9] != 0) {
            lVar12 = FUN_00b2c120(4);
            if (lVar12 == 0) goto LAB_00b33472;
            *(long *)(lVar12 + 0x18) = lVar11;
          }
          FUN_00b2d8d0(lVar12);
        }
        else {
          piVar20 = (int *)*param_1;
          if (*piVar20 == 0) {
            if ((uVar9 == 0) && (*(ulong *)(piVar20 + 2) < *(ulong *)(piVar20 + 4))) {
              iVar10 = (*(code *)**(undefined8 **)(param_6 + 2))();
              if (((long)iVar10 < (long)(*(ulong *)(piVar20 + 4) - *(ulong *)(piVar20 + 2))) &&
                 (((*(ulong *)(piVar20 + 2) < *(ulong *)(piVar20 + 4) &&
                   (uVar18 = FUN_00b430e0(*(undefined8 *)(param_6 + 2)), uVar18 != 0)) &&
                  (*(ulong *)(piVar20 + 2) < uVar18)))) {
                lVar12 = FUN_00b2edc0(uVar18,*(undefined8 *)(piVar20 + 4));
                if (lVar12 != 0) {
                  if ((*(byte *)(piVar20 + 6) & 1) != 0) {
                    *(uint *)(lVar12 + 0x18) = *(uint *)(lVar12 + 0x18) | 1;
                  }
                  uVar6 = param_2[9];
                  *(ulong *)(piVar20 + 4) = uVar18;
                  *(long *)(lVar11 + 8) = lVar12;
                  lVar12 = lVar11;
                  if (uVar6 != 0) {
                    lVar12 = FUN_00b2c120(4);
                    if (lVar12 == 0) goto LAB_00b33472;
                    *(long *)(lVar12 + 0x18) = lVar11;
                  }
                  lVar19 = FUN_00b2c0d0(*param_1,0);
                  *param_1 = lVar19;
                  lVar11 = lVar12;
                  if (lVar19 == 0) goto LAB_00b33472;
                  lVar12 = FUN_00b2c0d0(lVar12,0);
                  *(long *)(lVar19 + 0x10) = lVar12;
                  if (lVar12 == 0) goto LAB_00b33472;
                  param_1 = (long *)(lVar12 + 8);
                  goto LAB_00b31725;
                }
                *(ulong *)(piVar20 + 4) = uVar18;
              }
            }
LAB_00b3185b:
            *(int **)(lVar11 + 8) = piVar20;
            puVar27 = puVar26;
          }
          else {
            if (*piVar20 != 5) goto LAB_00b3185b;
            iVar7 = FUN_00b2bff0(lVar11);
            iVar10 = iVar7;
            iVar8 = FUN_00b2bff0(piVar20);
            puVar27 = puVar26;
            if ((((*(byte *)(lVar11 + 5) & 0x40) == 0) &&
                ((*(byte *)((long)piVar20 + 5) & 0x40) == 0)) &&
               ((*(byte *)(*(long *)(param_6 + 4) + 0xb) & 2) != 0)) {
              uVar6 = *(uint *)(&DAT_00d42f20 + ((long)iVar8 * 6 + (long)iVar10) * 4);
              if (uVar6 != 0) {
                if (uVar6 == 1) {
                  if ((code *)PTR_FUN_011bec80 != FUN_00b2b210) {
                    puVar27 = *(uint **)(param_6 + 0xc);
                    FUN_00b2af10(&local_138,0x100,*(undefined8 *)(param_6 + 2),
                                 *(undefined8 *)(param_6 + 10),puVar27,
                                 "redundant nested repeat operator");
                    (*(code *)PTR_FUN_011bec80)(&local_138);
                  }
                }
                else if ((code *)PTR_FUN_011bec80 != FUN_00b2b210) {
                  puVar27 = *(uint **)(param_6 + 0xc);
                  FUN_00b2af10(&local_138,0x100,*(undefined8 *)(param_6 + 2),
                               *(undefined8 *)(param_6 + 10),puVar27,
                               "nested repeat operator %s and %s was replaced with \'%s\'",
                               (&PTR_DAT_00d42ee0)[iVar8],(&PTR_DAT_00d42ee0)[iVar10],
                               (&PTR_DAT_00d42ea0)[uVar6],puVar26);
                  (*(code *)PTR_FUN_011bec80)(&local_138);
                }
              }
            }
            puVar26 = puVar27;
            if (iVar8 < 0) goto LAB_00b3185b;
            if (iVar7 < 0) {
              if (((iVar8 - 1U < 2) && (1 < *(int *)(lVar11 + 0x14))) &&
                 (*(int *)(lVar11 + 0x18) != 0)) {
                iVar10 = *(int *)(lVar11 + 0x10);
                if (iVar10 == 0) {
                  iVar10 = 1;
                }
                *(int *)(lVar11 + 0x14) = iVar10;
              }
              goto LAB_00b3185b;
            }
            FUN_00b313d0(lVar11,piVar20);
          }
          puVar26 = puVar27;
          lVar12 = lVar11;
          if (param_2[9] != 0) {
            lVar12 = FUN_00b2c120(4);
            if (lVar12 == 0) {
LAB_00b33472:
              FUN_00b2d8d0(lVar11);
              return 0xfffffffb;
            }
            *(long *)(lVar12 + 0x18) = lVar11;
            puVar26 = puVar27;
          }
          *param_1 = lVar12;
        }
LAB_00b31725:
        uVar6 = FUN_00b2fd20(param_2,param_4,param_5,param_6);
        if ((int)uVar6 < 0) {
          return uVar6;
        }
      } while( true );
    }
LAB_00b32058:
    *param_1 = 0;
    return 0xfffffffb;
  case 0x10:
    puVar26 = param_6;
    uVar9 = FUN_00b2dbf0(param_1,param_2,param_4,param_5);
    if (uVar9 != 0) {
      return uVar9;
    }
    lVar11 = *param_1;
    if ((*(byte *)(lVar11 + 4) & 1) == 0) {
      if (*(undefined8 **)(lVar11 + 0x28) == (undefined8 *)0x0) {
        uVar9 = 0xffffffff;
      }
      else {
        piVar20 = (int *)**(undefined8 **)(lVar11 + 0x28);
        if ((*piVar20 != 1) || (uVar9 = piVar20[1], uVar9 != piVar20[2])) goto LAB_00b32a78;
        if ((uVar9 < 0x100) &&
           ((*(uint *)(lVar11 + 8 + (long)((int)uVar9 >> 5) * 4) & 1 << ((byte)uVar9 & 0x1f)) != 0))
        {
          uVar9 = 0xffffffff;
        }
      }
      lVar12 = 0;
      do {
        uVar6 = *(uint *)(lVar11 + 8 + lVar12);
        if (uVar6 != 0) {
          uVar23 = uVar6 - 1;
          if (((uVar6 & uVar23) != 0) || (uVar9 != 0xffffffff)) goto LAB_00b32a78;
          uVar9 = (uVar23 >> 1 & 0x55555555) + (uVar23 & 0x55555555);
          uVar9 = (uVar9 >> 2 & 0x33333333) + (uVar9 & 0x33333333);
          uVar9 = (uVar9 >> 4 & 0xf0f0f0f) + (uVar9 & 0xf0f0f0f);
          uVar9 = (uVar9 >> 8 & 0xff00ff) + (uVar9 & 0xff00ff);
          uVar9 = (uVar9 >> 0x10) + (uVar9 & 0xffff) + (int)lVar12 * 8;
        }
        lVar12 = lVar12 + 4;
      } while (lVar12 != 0x20);
      if (uVar9 != 0xffffffff) {
        FUN_00b2d8d0();
        lVar11 = FUN_00b2edc0(0,0);
        *param_1 = lVar11;
        if (lVar11 == 0) {
          return 0xfffffffb;
        }
        uVar28 = *(undefined8 *)(*(long *)(param_6 + 2) + 0x48);
        goto LAB_00b32019;
      }
    }
LAB_00b32a78:
    if ((*param_6 & 1) != 0) {
      local_120 = &local_128;
      local_128 = 0;
      local_138 = param_6;
      uStack_130 = lVar11;
      uVar9 = (**(code **)(*(long *)(param_6 + 2) + 0x60))(param_6[1],FUN_00b2ee80,&local_138);
      if (uVar9 != 0) {
        FUN_00b2d8d0(local_128);
        return uVar9;
      }
      uVar9 = 0;
      if (local_128 == 0) goto LAB_00b31725;
      lVar11 = FUN_00b2eba0(*param_1);
      if (lVar11 == 0) {
        FUN_00b2d8d0(local_128);
        return 0xfffffffb;
      }
      *param_1 = lVar11;
      goto LAB_00b31725;
    }
    goto LAB_00b31722;
  case 0x11:
    puVar15 = *(undefined8 **)(param_6 + 2);
    iVar10 = *(int *)(*(long *)(param_6 + 4) + 0x10);
    puVar13 = (uint *)*param_4;
    puVar27 = puVar13;
    do {
      puVar25 = puVar27;
      if (param_5 <= puVar25) goto LAB_00b3197b;
      iVar7 = (*(code *)puVar15[6])(puVar25,param_5);
      iVar8 = (*(code *)*puVar15)(puVar25);
      puVar27 = (uint *)((long)puVar25 + (long)iVar8);
    } while (((iVar10 != iVar7) || (param_5 <= puVar27)) ||
            (iVar7 = (*(code *)puVar15[6])(puVar27,param_5), iVar7 != 0x45));
    iVar10 = (*(code *)*puVar15)(puVar27);
    puVar27 = (uint *)((long)iVar10 + (long)puVar27);
    if (puVar25 == (uint *)0x0) {
LAB_00b3197b:
      puVar25 = param_5;
      puVar27 = param_5;
    }
    lVar11 = FUN_00b2edc0(puVar13,puVar25);
    *param_1 = lVar11;
    if (lVar11 == 0) {
      return 0xfffffffb;
    }
    *param_4 = puVar27;
    uVar9 = 0;
    goto LAB_00b31725;
  case 0x12:
    uVar9 = FUN_00b2b580(param_4,param_5,param_6);
    if ((int)uVar9 < 0) {
      return uVar9;
    }
    lVar11 = FUN_00b2c180();
    *param_1 = lVar11;
    if (lVar11 == 0) {
      return 0xfffffffb;
    }
    puVar26 = (uint *)(ulong)*param_6;
    uVar9 = FUN_00b2cd10(lVar11,uVar9,0,1,puVar26,param_6 + 2);
    if (uVar9 != 0) {
      return uVar9;
    }
    if (param_2[7] != 0) {
      *(uint *)(lVar11 + 4) = *(uint *)(lVar11 + 4) | 1;
      uVar9 = 0;
      goto LAB_00b31725;
    }
    goto LAB_00b31722;
  case 0x13:
    uVar9 = (**(code **)(*(long *)(param_6 + 2) + 0x48))(0xd,&local_138);
    if ((int)uVar9 < 0) {
      return uVar9;
    }
    uVar6 = (**(code **)(*(long *)(param_6 + 2) + 0x48))(10,(long)&local_138 + (long)(int)uVar9);
    if ((int)uVar6 < 0) {
      return uVar6;
    }
    lVar11 = FUN_00b2edc0(&local_138,(long)(int)uVar6 + (long)(int)uVar9 + (long)&local_138);
    if (lVar11 == 0) {
      lVar16 = 0;
      lVar17 = 0;
      lVar12 = 0;
    }
    else {
      *(uint *)(lVar11 + 0x18) = *(uint *)(lVar11 + 0x18) | 1;
      lVar12 = FUN_00b2c180();
      if (lVar12 == 0) {
        lVar16 = 0;
        lVar17 = 0;
      }
      else {
        lVar19 = *(long *)(param_6 + 2);
        if (*(int *)(lVar19 + 0x1c) < 2) {
          *(uint *)(lVar12 + 8) = *(uint *)(lVar12 + 8) | 0x3c00;
        }
        else {
          FUN_00b2b850(lVar12 + 0x28,10,0xd);
          lVar19 = *(long *)(param_6 + 2);
        }
        if ((*(byte *)(lVar19 + 0xa0) & 1) != 0) {
          FUN_00b2b850(lVar12 + 0x28,0x85,0x85);
          FUN_00b2b850(lVar12 + 0x28,0x2028,0x2029);
        }
        lVar17 = FUN_00b2eba0(lVar12,0);
        if (lVar17 == 0) {
          lVar16 = 0;
        }
        else {
          lVar16 = FUN_00b2eba0(lVar11,lVar17);
          if (lVar16 != 0) {
            lVar11 = FUN_00b2c120(4);
            *param_1 = lVar11;
            if (lVar11 != 0) {
              *(long *)(lVar11 + 0x18) = lVar16;
              uVar9 = 0;
              goto LAB_00b31725;
            }
            lVar17 = 0;
            lVar11 = 0;
          }
          lVar12 = 0;
        }
      }
    }
    FUN_00b2d8d0(lVar11);
    FUN_00b2d8d0(lVar12);
    goto LAB_00b32d78;
  case 0x14:
    if ((*(byte *)(*(long *)(param_6 + 2) + 0xa0) & 1) == 0) {
LAB_00b31f71:
      lVar11 = FUN_00b2c1e0();
      if (lVar11 == 0) {
LAB_00b32d8d:
        lVar16 = 0;
        lVar17 = 0;
        lVar19 = 0;
        lVar12 = 0;
        lVar11 = 0;
      }
      else {
        uVar9 = *param_6;
        lVar12 = FUN_00b2c120(2);
        if (lVar12 != 0) {
          *(uint *)(lVar12 + 0x10) = uVar9 | 4;
          *param_1 = lVar12;
          *(long *)(lVar12 + 0x18) = lVar11;
          uVar9 = 0;
          goto LAB_00b31725;
        }
        *param_1 = 0;
        lVar16 = 0;
        lVar17 = 0;
        lVar19 = 0;
        lVar12 = 0;
      }
    }
    else {
      iVar10 = (**(code **)(*(long *)(param_6 + 2) + 0x70))
                         (&PTR_FUN_011bf020,&DAT_00d95897,&DAT_00d95898);
      if (iVar10 < 0) {
        if (*param_1 != 0) goto LAB_00b31722;
        goto LAB_00b31f71;
      }
      lVar11 = FUN_00b2c180();
      if (lVar11 == 0) goto LAB_00b32d8d;
      puVar26 = (uint *)(ulong)*param_6;
      uVar9 = FUN_00b2cd10(lVar11,iVar10,0,1,puVar26,param_6 + 2);
      lVar12 = 0;
      if (uVar9 != 0) {
LAB_00b32cd0:
        FUN_00b2d8d0(lVar11);
        FUN_00b2d8d0(lVar12);
        FUN_00b2d8d0(0);
        FUN_00b2d8d0(0);
        FUN_00b2d8d0(0);
        if ((int)uVar9 < 0) {
          return uVar9;
        }
        goto LAB_00b31722;
      }
      *(uint *)(lVar11 + 4) = *(uint *)(lVar11 + 4) | 1;
      lVar12 = FUN_00b2c180();
      if (lVar12 == 0) {
        lVar16 = 0;
        lVar17 = 0;
        lVar19 = 0;
      }
      else {
        puVar26 = (uint *)(ulong)*param_6;
        uVar9 = FUN_00b2cd10(lVar12,iVar10,0,1,puVar26,param_6 + 2);
        if (uVar9 != 0) goto LAB_00b32cd0;
        lVar19 = FUN_00b2c220(0,0xffffffff,0);
        if (lVar19 == 0) {
          lVar16 = 0;
          lVar17 = 0;
        }
        else {
          *(long *)(lVar19 + 8) = lVar12;
          lVar16 = FUN_00b2c0d0(lVar19,0);
          if (lVar16 == 0) {
            lVar17 = 0;
            lVar12 = 0;
          }
          else {
            lVar17 = FUN_00b2c0d0(lVar11,lVar16);
            if (lVar17 != 0) {
              lVar11 = FUN_00b2c120(4);
              *param_1 = lVar11;
              if (lVar11 != 0) {
                *(long *)(lVar11 + 0x18) = lVar17;
                uVar9 = 0;
                goto LAB_00b31725;
              }
              lVar16 = 0;
              lVar11 = 0;
            }
            lVar19 = 0;
            lVar12 = 0;
          }
        }
      }
    }
    FUN_00b2d8d0(lVar11);
    FUN_00b2d8d0(lVar12);
    FUN_00b2d8d0(lVar19);
LAB_00b32d78:
    FUN_00b2d8d0(lVar17);
    FUN_00b2d8d0(lVar16);
    return 0xfffffffb;
  case 0x15:
    lVar11 = FUN_00b2ebf0(0x10000);
    *param_1 = lVar11;
  }
  if (lVar11 == 0) {
    return 0xfffffffb;
  }
LAB_00b31722:
  uVar9 = 0;
  goto LAB_00b31725;
LAB_00b315a8:
  return 0xffffff89;
}


// ==== entry=00b33520 name=FUN_00b33520 size=261 ====

int FUN_00b33520(undefined8 *param_1,undefined8 param_2,int param_3,undefined8 param_4,
                undefined8 param_5,undefined8 param_6)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  int *local_40 [2];
  
  *param_1 = 0;
  iVar2 = FUN_00b31550(local_40);
  if (iVar2 < 0) {
LAB_00b33620:
    FUN_00b2d8d0(local_40[0]);
  }
  else if ((iVar2 == 0 || param_3 == iVar2) || (iVar2 == 0xd)) {
    *param_1 = local_40[0];
  }
  else {
    piVar3 = (int *)FUN_00b2c0d0(local_40[0],0);
    *param_1 = piVar3;
    do {
      piVar4 = piVar3 + 4;
      iVar2 = FUN_00b31550(local_40,param_2,param_3,param_4,param_5,param_6);
      if (iVar2 < 0) goto LAB_00b33620;
      if (*local_40[0] == 8) {
        *(int **)piVar4 = local_40[0];
        piVar4 = *(int **)(local_40[0] + 4);
        piVar3 = local_40[0];
        while (piVar1 = piVar4, local_40[0] = piVar3, piVar1 != (int *)0x0) {
          piVar3 = piVar1;
          piVar4 = *(int **)(piVar1 + 4);
        }
      }
      else {
        piVar3 = (int *)FUN_00b2c0d0(local_40[0],0);
        *(int **)piVar4 = piVar3;
      }
    } while (((iVar2 != 0) && (param_3 != iVar2)) && (iVar2 != 0xd));
  }
  return iVar2;
}


// ==== entry=00b33650 name=FUN_00b33650 size=274 ====

int FUN_00b33650(long *param_1,int *param_2,int param_3,undefined8 param_4,undefined8 param_5,
                undefined8 param_6)

{
  int iVar1;
  long lVar2;
  long *plVar3;
  long local_40 [2];
  
  *param_1 = 0;
  iVar1 = FUN_00b33520(local_40);
  if (iVar1 < 0) {
    FUN_00b2d8d0(local_40[0]);
  }
  else if (param_3 == iVar1) {
    *param_1 = local_40[0];
  }
  else {
    if (iVar1 == 0xd) {
      lVar2 = FUN_00b2eba0(local_40[0],0);
      *param_1 = lVar2;
      do {
        plVar3 = (long *)(lVar2 + 0x10);
        iVar1 = FUN_00b2fd20(param_2,param_4,param_5,param_6);
        if (iVar1 < 0) {
          return iVar1;
        }
        iVar1 = FUN_00b33520(local_40,param_2,param_3,param_4,param_5,param_6);
        if (iVar1 < 0) {
          FUN_00b2d8d0(local_40[0]);
          return iVar1;
        }
        lVar2 = FUN_00b2eba0(local_40[0],0);
        *plVar3 = lVar2;
      } while (iVar1 == 0xd);
      if (*param_2 == param_3) {
        return iVar1;
      }
    }
    else {
      FUN_00b2d8d0();
    }
    iVar1 = -0x75;
    if (param_3 != 0xf) {
      iVar1 = -0xb;
    }
  }
  return iVar1;
}


// ==== entry=00b33780 name=FUN_00b33780 size=61 ====

undefined8 FUN_00b33780(void)

{
  if (DAT_011c3810 != 0) {
    FUN_00b449c0(DAT_011c3810,FUN_00b2b730,0);
    FUN_00b443c0(DAT_011c3810);
    DAT_011c3810 = 0;
    return 0;
  }
  return 0;
}


// ==== entry=00b337d0 name=FUN_00b337d0 size=133 ====

undefined8 FUN_00b337d0(void)

{
  if (DAT_011c6958 != 0) {
    FUN_00b443c0();
    DAT_011c6958 = 0;
  }
  if (DAT_011c6940 != 0) {
    FUN_00b443c0();
    DAT_011c6940 = 0;
  }
  if (DAT_011c6950 != 0) {
    FUN_00b443c0();
    DAT_011c6950 = 0;
  }
  if (DAT_011c6948 != 0) {
    FUN_00b443c0();
    DAT_011c6948 = 0;
  }
  DAT_011c382c = 0;
  return 0;
}


// ==== entry=00b33860 name=FUN_00b33860 size=453 ====

undefined8
FUN_00b33860(long *param_1,undefined8 param_2,undefined8 param_3,long param_4,undefined4 *param_5)

{
  undefined4 uVar1;
  undefined8 uVar2;
  long lVar3;
  long *plVar4;
  int iVar5;
  undefined8 local_70;
  undefined1 local_68 [64];
  
  if (*(long *)(param_4 + 0x68) != 0) {
    FUN_00b449c0(*(long *)(param_4 + 0x68),FUN_00b2b6c0,0);
  }
  *(undefined8 *)(param_5 + 6) = 0;
  *(undefined8 *)(param_5 + 8) = 0;
  *(undefined8 *)(param_5 + 0x18) = 0;
  uVar1 = *(undefined4 *)(param_4 + 0x50);
  *(undefined8 *)(param_5 + 0xe) = 0;
  *param_5 = uVar1;
  uVar1 = *(undefined4 *)(param_4 + 0x60);
  *(undefined8 *)(param_5 + 0x10) = 0;
  param_5[1] = uVar1;
  uVar2 = *(undefined8 *)(param_4 + 0x48);
  param_5[0x14] = 0;
  *(undefined8 *)(param_5 + 2) = uVar2;
  uVar2 = *(undefined8 *)(param_4 + 0x58);
  param_5[0x1a] = 0;
  *(undefined8 *)(param_5 + 0x2c) = 0;
  *(undefined8 *)(param_5 + 0x1c) = 0;
  *(undefined8 *)(param_5 + 0x1e) = 0;
  *(undefined8 *)(param_5 + 0x20) = 0;
  *(undefined8 *)(param_5 + 0x22) = 0;
  *(undefined8 *)(param_5 + 0x24) = 0;
  *(undefined8 *)(param_5 + 0x26) = 0;
  *(undefined8 *)(param_5 + 0x28) = 0;
  *(undefined8 *)(param_5 + 0x2a) = 0;
  *(undefined8 *)(param_5 + 4) = uVar2;
  *(undefined8 *)(param_5 + 10) = param_2;
  *(undefined8 *)(param_5 + 0xc) = param_3;
  *(long *)(param_5 + 0x12) = param_4;
  *param_1 = 0;
  local_70 = param_2;
  uVar2 = FUN_00b2fd20(local_68,&local_70,param_3,param_5);
  if (-1 < (int)uVar2) {
    uVar2 = FUN_00b33650(param_1,local_68,0,&local_70,param_3,param_5);
    if (-1 < (int)uVar2) {
      if ((int)param_5[0x14] < 1) {
        *(undefined4 *)(param_4 + 0x14) = param_5[0x18];
        return 0;
      }
      uVar1 = *param_5;
      lVar3 = FUN_00b2c120(1);
      if (lVar3 == 0) {
        iVar5 = param_5[0x18];
        uVar2 = 0xfffffffb;
      }
      else {
        *(undefined4 *)(lVar3 + 0x10) = uVar1;
        *(undefined4 *)(lVar3 + 0xc) = 0;
        *(long *)(lVar3 + 0x18) = *param_1;
        iVar5 = param_5[0x18];
        if (-1 < iVar5) {
          plVar4 = *(long **)(param_5 + 0x2c);
          if (*(long **)(param_5 + 0x2c) == (long *)0x0) {
            plVar4 = (long *)(param_5 + 0x1c);
          }
          *plVar4 = lVar3;
          *param_1 = lVar3;
          *(int *)(param_4 + 0x14) = iVar5;
          return 0;
        }
        uVar2 = 0xfffffff5;
      }
      goto LAB_00b339b3;
    }
  }
  iVar5 = param_5[0x18];
LAB_00b339b3:
  *(int *)(param_4 + 0x14) = iVar5;
  return uVar2;
}


// ==== entry=00b33a30 name=FUN_00b33a30 size=9 ====

void FUN_00b33a30(long param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  *(undefined8 *)(param_1 + 0x38) = param_3;
  *(undefined8 *)(param_1 + 0x40) = param_4;
  return;
}


// ==== entry=00b33a40 name=FUN_00b33a40 size=151 ====

void FUN_00b33a40(int *param_1,int *param_2)

{
  int iVar1;
  long lVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  undefined8 uVar9;
  undefined8 uVar10;
  undefined8 uVar11;
  
  uVar3 = *(undefined8 *)(param_2 + 2);
  uVar4 = *(undefined8 *)param_1;
  uVar5 = *(undefined8 *)(param_1 + 2);
  uVar6 = *(undefined8 *)(param_1 + 4);
  uVar7 = *(undefined8 *)(param_1 + 6);
  uVar8 = *(undefined8 *)(param_1 + 8);
  uVar9 = *(undefined8 *)(param_1 + 10);
  *(undefined8 *)param_1 = *(undefined8 *)param_2;
  *(undefined8 *)(param_1 + 2) = uVar3;
  uVar3 = *(undefined8 *)(param_2 + 6);
  uVar10 = *(undefined8 *)(param_1 + 0xc);
  uVar11 = *(undefined8 *)(param_1 + 0xe);
  *(undefined8 *)(param_1 + 4) = *(undefined8 *)(param_2 + 4);
  *(undefined8 *)(param_1 + 6) = uVar3;
  uVar3 = *(undefined8 *)(param_2 + 10);
  *(undefined8 *)(param_1 + 8) = *(undefined8 *)(param_2 + 8);
  *(undefined8 *)(param_1 + 10) = uVar3;
  uVar3 = *(undefined8 *)(param_2 + 0xe);
  *(undefined8 *)(param_1 + 0xc) = *(undefined8 *)(param_2 + 0xc);
  *(undefined8 *)(param_1 + 0xe) = uVar3;
  *(undefined8 *)param_2 = uVar4;
  *(undefined8 *)(param_2 + 2) = uVar5;
  iVar1 = *param_1;
  *(undefined8 *)(param_2 + 4) = uVar6;
  *(undefined8 *)(param_2 + 6) = uVar7;
  *(undefined8 *)(param_2 + 8) = uVar8;
  *(undefined8 *)(param_2 + 10) = uVar9;
  *(undefined8 *)(param_2 + 0xc) = uVar10;
  *(undefined8 *)(param_2 + 0xe) = uVar11;
  if ((iVar1 == 0) && (param_1[7] == 0)) {
    lVar2 = *(long *)(param_1 + 2);
    *(int **)(param_1 + 2) = param_1 + 8;
    *(long *)(param_1 + 4) = (long)(param_1 + 8) + (*(long *)(param_1 + 4) - lVar2);
  }
  if ((*param_2 == 0) && (param_2[7] == 0)) {
    lVar2 = *(long *)(param_2 + 2);
    *(int **)(param_2 + 2) = param_2 + 8;
    *(long *)(param_2 + 4) = (long)(param_2 + 8) + (*(long *)(param_2 + 4) - lVar2);
  }
  return;
}


// ==== entry=00b33ae0 name=FUN_00b33ae0 size=255 ====

undefined8 FUN_00b33ae0(int *param_1,long param_2)

{
  int iVar1;
  int iVar2;
  undefined8 uVar3;
  int *piVar4;
  int iVar5;
  int *piVar6;
  long lVar7;
  
LAB_00b33aec:
  iVar1 = *param_1;
  do {
    if (5 < iVar1 - 4U) {
      return 0;
    }
    switch((&switchD_00b33af6::switchdataD_00d430a0)[iVar1 - 4U]) {
    case (undefined *)0xb33b00:
      goto switchD_00b33af6_caseD_b33b00;
    case (undefined *)0xb33b20:
      iVar1 = param_1[1];
      if (iVar1 == 0x800) goto switchD_00b33af6_caseD_b33b3e;
      if (0x800 < iVar1) {
        if ((iVar1 != 0x1000) && (iVar1 != 0x2000)) {
          return 0;
        }
        goto switchD_00b33af6_caseD_b33b3e;
      }
      if (iVar1 != 0x400) {
        return 0;
      }
      param_1 = *(int **)(param_1 + 2);
      break;
    case (undefined *)0xb33b3e:
switchD_00b33af6_caseD_b33b3e:
      param_1 = *(int **)(param_1 + 2);
      break;
    case (undefined *)0xb33b50:
      goto switchD_00b33af6_caseD_b33b50;
    case (undefined *)0xb33b70:
      if ((*(byte *)((long)param_1 + 5) & 8) == 0) {
        return 0xffffff2f;
      }
      iVar1 = param_1[2];
      piVar6 = *(int **)(param_1 + 10);
      if (*(int **)(param_1 + 10) == (int *)0x0) {
        piVar6 = param_1 + 3;
      }
      if (iVar1 < 1) {
        iVar5 = 0;
      }
      else {
        iVar5 = 0;
        piVar4 = piVar6;
        do {
          iVar2 = *(int *)(param_2 + (long)*piVar4 * 4);
          if (0 < iVar2) {
            lVar7 = (long)iVar5;
            iVar5 = iVar5 + 1;
            piVar6[lVar7] = iVar2;
          }
          piVar4 = piVar4 + 1;
        } while (piVar4 != piVar6 + (ulong)(iVar1 - 1) + 1);
      }
      param_1[2] = iVar5;
      return 0;
    }
    iVar1 = *param_1;
  } while( true );
switchD_00b33af6_caseD_b33b50:
  if (param_1[2] == 8) {
    param_1[3] = *(int *)(param_2 + (long)param_1[3] * 4);
  }
  param_1 = *(int **)(param_1 + 6);
  goto LAB_00b33aec;
switchD_00b33af6_caseD_b33b00:
  do {
    uVar3 = FUN_00b33ae0(*(undefined8 *)(param_1 + 2),param_2);
    if ((int)uVar3 != 0) {
      return uVar3;
    }
    param_1 = *(int **)(param_1 + 4);
  } while (param_1 != (int *)0x0);
  return uVar3;
}


// ==== entry=00b33c00 name=FUN_00b33c00 size=86 ====

ulong FUN_00b33c00(undefined4 *param_1)

{
  undefined4 uVar1;
  ulong uVar2;
  
LAB_00b33c04:
  uVar1 = *param_1;
  do {
    switch(uVar1) {
    case 4:
      return (ulong)-(uint)((param_1[1] & 0x800) == 0) & 0xffffffffffffff2f;
    case 5:
      goto switchD_00b33c0e_caseD_5;
    case 6:
      param_1 = *(undefined4 **)(param_1 + 6);
      uVar1 = *param_1;
      break;
    default:
      return 0;
    case 8:
    case 9:
      goto switchD_00b33c0e_caseD_8;
    }
  } while( true );
switchD_00b33c0e_caseD_5:
  param_1 = *(undefined4 **)(param_1 + 2);
  goto LAB_00b33c04;
switchD_00b33c0e_caseD_8:
  do {
    uVar2 = FUN_00b33c00(*(undefined8 *)(param_1 + 2));
    if ((int)uVar2 != 0) {
      return uVar2;
    }
    param_1 = *(undefined4 **)(param_1 + 4);
  } while (param_1 != (undefined4 *)0x0);
  return uVar2;
}


// ==== entry=00b33c70 name=FUN_00b33c70 size=167 ====

int FUN_00b33c70(undefined4 *param_1)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  
LAB_00b33c79:
  uVar1 = *param_1;
  do {
    switch(uVar1) {
    case 5:
      goto switchD_00b33c83_caseD_5;
    case 6:
      iVar3 = param_1[2];
      if (iVar3 != 2) {
        if (iVar3 < 3) {
          return (uint)(iVar3 == 1) * 2;
        }
        if ((iVar3 != 4) && (iVar3 != 8)) {
          return 0;
        }
      }
      param_1 = *(undefined4 **)(param_1 + 6);
      goto LAB_00b33c79;
    default:
      return 0;
    case 8:
    case 9:
      iVar3 = 0;
      while( true ) {
        iVar2 = FUN_00b33c70(*(undefined8 *)(param_1 + 2));
        if (iVar3 < iVar2) {
          iVar3 = iVar2;
        }
        if (iVar2 < 0) break;
        param_1 = *(undefined4 **)(param_1 + 4);
        if (param_1 == (undefined4 *)0x0) {
          return iVar3;
        }
      }
      return iVar3;
    case 10:
      if ((*(byte *)(param_1 + 1) & 0x80) != 0) {
        return 3;
      }
      param_1 = *(undefined4 **)(param_1 + 8);
      uVar1 = *param_1;
    }
  } while( true );
switchD_00b33c83_caseD_5:
  if (param_1[5] == 0) {
    return 0;
  }
  param_1 = *(undefined4 **)(param_1 + 2);
  goto LAB_00b33c79;
}


// ==== entry=00b33d30 name=FUN_00b33d30 size=665 ====

int FUN_00b33d30(int *param_1,ulong *param_2,long param_3)

{
  undefined1 auVar1 [16];
  int iVar2;
  ulong uVar3;
  long lVar4;
  int *piVar5;
  long lVar6;
  ulong local_40 [2];
  
  *param_2 = 0;
  iVar2 = *param_1;
  switch(iVar2) {
  case 0:
    *param_2 = *(long *)(param_1 + 4) - *(long *)(param_1 + 2);
    return iVar2;
  case 1:
  case 2:
  case 3:
    *param_2 = 1;
    return 0;
  case 4:
    lVar4 = *(long *)(param_3 + 0xb0);
    if (*(long *)(param_3 + 0xb0) == 0) {
      lVar4 = param_3 + 0x70;
    }
    if ((*(byte *)(param_1 + 1) & 0x80) == 0) {
      piVar5 = *(int **)(param_1 + 10);
      if (*(int **)(param_1 + 10) == (int *)0x0) {
        piVar5 = param_1 + 3;
      }
      if (*piVar5 <= *(int *)(param_3 + 0x60)) {
        iVar2 = FUN_00b33d30(*(undefined8 *)(lVar4 + (long)*piVar5 * 8));
        if (iVar2 != 0) {
          return iVar2;
        }
        if (param_1[2] < 2) {
          return 0;
        }
        iVar2 = piVar5[1];
        if (iVar2 <= *(int *)(param_3 + 0x60)) {
          lVar6 = 2;
          do {
            iVar2 = FUN_00b33d30(*(undefined8 *)(lVar4 + (long)iVar2 * 8),local_40,param_3);
            if (iVar2 != 0) {
              return iVar2;
            }
            if (local_40[0] < *param_2) {
              *param_2 = local_40[0];
            }
            if (param_1[2] <= (int)lVar6) {
              return 0;
            }
            iVar2 = piVar5[lVar6];
            lVar6 = lVar6 + 1;
          } while (iVar2 <= *(int *)(param_3 + 0x60));
        }
      }
      return -0xd0;
    }
    break;
  case 5:
    if (0 < param_1[4]) {
      iVar2 = FUN_00b33d30(*(undefined8 *)(param_1 + 2));
      if (iVar2 == 0) {
        iVar2 = param_1[4];
        uVar3 = 0;
        if (iVar2 != 0) {
          auVar1._8_8_ = 0;
          auVar1._0_8_ = (long)iVar2;
          uVar3 = 0xffffffffffffffff;
          if (*param_2 < SUB168((ZEXT816(0) << 0x40 | ZEXT816(0xffffffffffffffff)) / auVar1,0)) {
            uVar3 = *param_2 * (long)iVar2;
          }
        }
        *param_2 = uVar3;
        return 0;
      }
      return iVar2;
    }
    break;
  case 6:
    iVar2 = param_1[2];
    if (iVar2 != 2) {
      if (iVar2 < 3) {
        if (iVar2 != 1) {
          return 0;
        }
        if ((*(byte *)(param_1 + 1) & 1) == 0) {
          iVar2 = FUN_00b33d30(*(undefined8 *)(param_1 + 6));
          if (iVar2 == 0) {
            uVar3 = *param_2;
            param_1[1] = param_1[1] | 1;
            *(ulong *)(param_1 + 10) = uVar3;
            return 0;
          }
          return iVar2;
        }
        *param_2 = *(ulong *)(param_1 + 10);
        return 0;
      }
      if ((iVar2 != 4) && (iVar2 != 8)) {
        return 0;
      }
    }
    lVar4 = *(long *)(param_1 + 6);
LAB_00b33fb4:
    iVar2 = FUN_00b33d30(lVar4,param_2,param_3);
    return iVar2;
  case 7:
    break;
  case 8:
    do {
      iVar2 = FUN_00b33d30(*(undefined8 *)(param_1 + 2),local_40,param_3);
      if (iVar2 != 0) {
        return iVar2;
      }
      *param_2 = *param_2 + local_40[0];
      param_1 = *(int **)(param_1 + 4);
    } while (param_1 != (int *)0x0);
    break;
  case 9:
    piVar5 = param_1;
    do {
      iVar2 = FUN_00b33d30(*(undefined8 *)(piVar5 + 2),local_40,param_3);
      if (iVar2 != 0) {
        return iVar2;
      }
      if ((piVar5 == param_1) || (local_40[0] < *param_2)) {
        *param_2 = local_40[0];
      }
      piVar5 = *(int **)(piVar5 + 4);
    } while (piVar5 != (int *)0x0);
    break;
  case 10:
    lVar4 = *(long *)(param_1 + 8);
    if ((*(byte *)(param_1 + 1) & 0x80) == 0) goto LAB_00b33fb4;
    if ((*(byte *)(lVar4 + 4) & 1) != 0) {
      *param_2 = *(ulong *)(lVar4 + 0x28);
      return 0;
    }
    break;
  default:
    return 0;
  }
  return 0;
}


// ==== entry=00b34000 name=FUN_00b34000 size=678 ====

int FUN_00b34000(int *param_1,ulong *param_2,long param_3)

{
  ulong uVar1;
  undefined1 auVar2 [16];
  int iVar3;
  int *piVar4;
  ulong uVar5;
  long lVar6;
  long lVar7;
  ulong local_40 [2];
  
  *param_2 = 0;
  iVar3 = *param_1;
  switch(iVar3) {
  case 0:
    *param_2 = *(long *)(param_1 + 4) - *(long *)(param_1 + 2);
    return iVar3;
  case 1:
  case 2:
  case 3:
    *param_2 = (long)*(int *)(*(long *)(param_3 + 8) + 0x18);
    break;
  case 4:
    lVar6 = *(long *)(param_3 + 0xb0);
    if (*(long *)(param_3 + 0xb0) == 0) {
      lVar6 = param_3 + 0x70;
    }
    if ((*(byte *)(param_1 + 1) & 0x80) != 0) goto LAB_00b34256;
    piVar4 = param_1 + 3;
    if (*(int **)(param_1 + 10) != (int *)0x0) {
      piVar4 = *(int **)(param_1 + 10);
    }
    if (0 < param_1[2]) {
      iVar3 = *piVar4;
      lVar7 = 1;
      if (iVar3 <= *(int *)(param_3 + 0x60)) {
        do {
          iVar3 = FUN_00b34000(*(undefined8 *)(lVar6 + (long)iVar3 * 8),local_40,param_3);
          if (iVar3 != 0) {
            return iVar3;
          }
          if (*param_2 < local_40[0]) {
            *param_2 = local_40[0];
          }
          if (param_1[2] <= (int)lVar7) {
            return 0;
          }
          iVar3 = piVar4[lVar7];
          lVar7 = lVar7 + 1;
        } while (iVar3 <= *(int *)(param_3 + 0x60));
      }
      return -0xd0;
    }
    break;
  case 5:
    if (param_1[5] != 0) {
      iVar3 = FUN_00b34000(*(undefined8 *)(param_1 + 2));
      if (iVar3 != 0) {
        return iVar3;
      }
      uVar1 = *param_2;
      if (uVar1 != 0) {
        iVar3 = param_1[5];
        if (iVar3 != -1) {
          uVar5 = 0;
          if (iVar3 != 0) {
            auVar2._8_8_ = 0;
            auVar2._0_8_ = (long)iVar3;
            uVar5 = 0xffffffffffffffff;
            if (uVar1 < SUB168((ZEXT816(0) << 0x40 | ZEXT816(0xffffffffffffffff)) / auVar2,0)) {
              uVar5 = uVar1 * (long)iVar3;
            }
          }
          *param_2 = uVar5;
          return 0;
        }
        goto LAB_00b34256;
      }
    }
    break;
  case 6:
    iVar3 = param_1[2];
    if (iVar3 == 2) {
LAB_00b34276:
      iVar3 = FUN_00b34000(*(undefined8 *)(param_1 + 6),param_2,param_3);
      return iVar3;
    }
    if (iVar3 < 3) {
      if (iVar3 == 1) {
        if ((*(byte *)(param_1 + 1) & 2) == 0) {
          iVar3 = FUN_00b34000(*(undefined8 *)(param_1 + 6));
          if (iVar3 == 0) {
            uVar1 = *param_2;
            param_1[1] = param_1[1] | 2;
            *(ulong *)(param_1 + 0xc) = uVar1;
            return 0;
          }
          return iVar3;
        }
        *param_2 = *(ulong *)(param_1 + 0xc);
      }
    }
    else if ((iVar3 == 4) || (iVar3 == 8)) goto LAB_00b34276;
    break;
  case 7:
    break;
  case 8:
    do {
      iVar3 = FUN_00b34000(*(undefined8 *)(param_1 + 2),local_40,param_3);
      if (iVar3 != 0) {
        return iVar3;
      }
      uVar1 = *param_2;
      uVar5 = 0xffffffffffffffff;
      if (((local_40[0] != 0xffffffffffffffff) && (uVar1 != 0xffffffffffffffff)) &&
         (uVar5 = local_40[0] + uVar1, ~local_40[0] < uVar1)) {
        uVar5 = 0xffffffffffffffff;
      }
      *param_2 = uVar5;
      param_1 = *(int **)(param_1 + 4);
    } while (param_1 != (int *)0x0);
    break;
  case 9:
    do {
      iVar3 = FUN_00b34000(*(undefined8 *)(param_1 + 2),local_40,param_3);
      if (iVar3 != 0) {
        return iVar3;
      }
      if (*param_2 < local_40[0]) {
        *param_2 = local_40[0];
      }
      param_1 = *(int **)(param_1 + 4);
    } while (param_1 != (int *)0x0);
    break;
  case 10:
    if ((*(byte *)(param_1 + 1) & 0x80) == 0) {
      iVar3 = FUN_00b34000(*(undefined8 *)(param_1 + 8));
      return iVar3;
    }
LAB_00b34256:
    *param_2 = 0xffffffffffffffff;
    return 0;
  default:
    return 0;
  }
  return 0;
}


// ==== entry=00b342f0 name=FUN_00b342f0 size=633 ====

int FUN_00b342f0(uint *param_1,long param_2,uint *param_3,int param_4)

{
  uint uVar1;
  long lVar2;
  undefined1 auVar3 [16];
  bool bVar4;
  uint uVar5;
  int iVar6;
  undefined8 uVar7;
  ulong uVar8;
  uint local_30;
  uint local_2c;
  
  *param_3 = 0;
  if (10 < *param_1) {
    return -1;
  }
  param_4 = param_4 + 1;
  switch(*param_1) {
  case 0:
    uVar8 = *(ulong *)(param_1 + 2);
    if (uVar8 < *(ulong *)(param_1 + 4)) {
      do {
        iVar6 = (*(code *)**(undefined8 **)(param_2 + 0x48))(uVar8);
        *param_3 = *param_3 + 1;
        uVar8 = uVar8 + (long)iVar6;
      } while (uVar8 < *(ulong *)(param_1 + 4));
    }
    break;
  default:
    *param_3 = 1;
    return 0;
  case 4:
    return -1;
  case 5:
    if (param_1[4] != param_1[5]) {
      return -1;
    }
    iVar6 = FUN_00b342f0(*(undefined8 *)(param_1 + 2),param_2,&local_30,param_4);
    if (iVar6 == 0) {
      uVar1 = param_1[4];
      uVar5 = 0;
      if ((uVar1 != 0) &&
         (auVar3._8_8_ = 0, auVar3._0_8_ = (long)(int)uVar1, uVar5 = 0xffffffff,
         (ulong)(long)(int)local_30 <
         SUB168((ZEXT416(0) << 0x40 | ZEXT816(0xffffffffffffffff)) / auVar3,0))) {
        uVar5 = local_30 * uVar1;
      }
      *param_3 = uVar5;
      return 0;
    }
    return iVar6;
  case 6:
    uVar1 = param_1[2];
    if (uVar1 != 2) {
      if ((int)uVar1 < 3) {
        if (uVar1 != 1) {
          return 0;
        }
        if ((param_1[1] & 4) == 0) {
          iVar6 = FUN_00b342f0(*(undefined8 *)(param_1 + 6),param_2,param_3,param_4);
          if (iVar6 == 0) {
            uVar1 = *param_3;
            param_1[1] = param_1[1] | 4;
            param_1[0xe] = uVar1;
            return 0;
          }
          return iVar6;
        }
        *param_3 = param_1[0xe];
        return 0;
      }
      if ((uVar1 != 4) && (uVar1 != 8)) {
        return 0;
      }
    }
    uVar7 = *(undefined8 *)(param_1 + 6);
    goto LAB_00b34522;
  case 7:
    break;
  case 8:
    do {
      iVar6 = FUN_00b342f0(*(undefined8 *)(param_1 + 2),param_2,&local_30,param_4);
      if (iVar6 != 0) {
        return iVar6;
      }
      uVar1 = *param_3;
      if ((local_30 == 0xffffffff) || (uVar1 == 0xffffffff)) {
        uVar5 = 0xffffffff;
      }
      else {
        uVar5 = local_30 + uVar1;
        if (~local_30 < uVar1) {
          uVar5 = 0xffffffff;
        }
      }
      *param_3 = uVar5;
      param_1 = *(uint **)(param_1 + 4);
    } while (param_1 != (uint *)0x0);
    break;
  case 9:
    iVar6 = FUN_00b342f0(*(undefined8 *)(param_1 + 2),param_2,&local_30,param_4);
    if (iVar6 != 0) {
      return iVar6;
    }
    lVar2 = *(long *)(param_1 + 4);
    bVar4 = false;
    while (lVar2 != 0) {
      iVar6 = FUN_00b342f0(*(undefined8 *)(lVar2 + 8),param_2,&local_2c,param_4);
      if (iVar6 != 0) {
        return iVar6;
      }
      lVar2 = *(long *)(lVar2 + 0x10);
      if (local_30 != local_2c) {
        bVar4 = true;
      }
    }
    if (!bVar4) {
      *param_3 = local_30;
      return 0;
    }
    return (param_4 != 1) - 2;
  case 10:
    if ((param_1[1] & 0x80) != 0) {
      return -1;
    }
    uVar7 = *(undefined8 *)(param_1 + 8);
LAB_00b34522:
    iVar6 = FUN_00b342f0(uVar7,param_2,param_3,param_4);
    return iVar6;
  }
  return 0;
}


// ==== entry=00b345b0 name=FUN_00b345b0 size=134 ====

ulong FUN_00b345b0(undefined4 *param_1,int param_2,uint param_3,uint param_4)

{
  uint uVar1;
  ulong uVar2;
  
  do {
    uVar1 = param_2 >> ((byte)*param_1 & 0x1f) & 1;
    if (uVar1 == 0) {
      return 1;
    }
    switch(*param_1) {
    case 5:
      param_1 = *(undefined4 **)(param_1 + 2);
      break;
    case 6:
      if ((param_1[2] & param_3) == 0) {
        return (ulong)uVar1;
      }
      param_1 = *(undefined4 **)(param_1 + 6);
      break;
    case 7:
      if ((param_1[1] & param_4) == 0) {
        return (ulong)uVar1;
      }
      param_1 = *(undefined4 **)(param_1 + 2);
      if (param_1 == (undefined4 *)0x0) {
LAB_00b345fe:
        return 0;
      }
      break;
    case 8:
    case 9:
      goto switchD_00b345d9_caseD_8;
    default:
      goto LAB_00b345fe;
    }
  } while( true );
switchD_00b345d9_caseD_8:
  do {
    uVar2 = FUN_00b345b0(*(undefined8 *)(param_1 + 2),param_2,param_3,param_4);
    if ((int)uVar2 != 0) {
      return uVar2;
    }
    param_1 = *(undefined4 **)(param_1 + 4);
  } while (param_1 != (undefined4 *)0x0);
  return uVar2;
}


// ==== entry=00b34650 name=FUN_00b34650 size=384 ====

ulong FUN_00b34650(undefined4 *param_1,undefined8 param_2,int param_3)

{
  int iVar1;
  uint uVar2;
  ulong uVar3;
  uint uVar4;
  long local_30 [2];
  
  switch(*param_1) {
  case 5:
    uVar3 = FUN_00b34650(*(undefined8 *)(param_1 + 2));
    if ((int)uVar3 == 1) {
      uVar3 = (ulong)(param_1[4] != 0);
    }
    break;
  case 6:
    uVar4 = param_1[1];
    uVar3 = 0;
    if ((uVar4 & 0x10) == 0) {
      if ((uVar4 & 8) == 0) {
        param_1[1] = uVar4 | 0x10;
        uVar3 = FUN_00b34650(*(undefined8 *)(param_1 + 6),param_2,param_3);
        param_1[1] = param_1[1] & 0xffffffef;
      }
      else {
        uVar3 = (ulong)((param_3 != 0) + 1);
      }
    }
    break;
  case 7:
    iVar1 = param_1[1];
    if (iVar1 != 0x800) {
      if (iVar1 < 0x801) {
        if (iVar1 != 0x400) {
          return 0;
        }
      }
      else if ((iVar1 != 0x1000) && (iVar1 != 0x2000)) {
        return 0;
      }
    }
    uVar3 = FUN_00b34650(*(undefined8 *)(param_1 + 2),param_2,param_3);
    break;
  case 8:
    uVar4 = 0;
    do {
      uVar3 = FUN_00b34650(*(undefined8 *)(param_1 + 2),param_2,param_3);
      uVar2 = (uint)uVar3;
      if ((int)uVar2 < 0) {
        return uVar3;
      }
      if (uVar2 == 2) {
        return uVar3;
      }
      uVar4 = uVar4 | uVar2;
      if (param_3 == 0) {
LAB_00b346e6:
        param_3 = 0;
      }
      else {
        uVar3 = FUN_00b33d30(*(undefined8 *)(param_1 + 2),local_30,param_2);
        if ((int)uVar3 != 0) {
          return uVar3;
        }
        if (local_30[0] != 0) goto LAB_00b346e6;
      }
      param_1 = *(undefined4 **)(param_1 + 4);
    } while (param_1 != (undefined4 *)0x0);
    goto LAB_00b346b1;
  case 9:
    uVar4 = 1;
    do {
      uVar3 = FUN_00b34650(*(undefined8 *)(param_1 + 2),param_2,param_3);
      uVar2 = (uint)uVar3;
      if ((int)uVar2 < 0) {
        return uVar3;
      }
      if (uVar2 == 2) {
        return uVar3;
      }
      param_1 = *(undefined4 **)(param_1 + 4);
      uVar4 = uVar4 & uVar2;
    } while (param_1 != (undefined4 *)0x0);
LAB_00b346b1:
    return (ulong)uVar4;
  case 10:
    uVar3 = FUN_00b34650(*(undefined8 *)(param_1 + 8));
    return uVar3;
  default:
    return 0;
  }
  return uVar3;
}


// ==== entry=00b34810 name=FUN_00b34810 size=174 ====

undefined8 FUN_00b34810(int *param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 uVar2;
  int *piVar3;
  
LAB_00b3481c:
  iVar1 = *param_1;
  piVar3 = param_1;
  do {
    if (4 < iVar1 - 5U) {
      return 0;
    }
    switch((&switchD_00b34826::switchdataD_00d43290)[iVar1 - 5U]) {
    case (undefined *)0xb34830:
      goto switchD_00b34826_caseD_b34830;
    case (undefined *)0xb34850:
      iVar1 = piVar3[1];
      if (iVar1 == 0x800) goto switchD_00b34826_caseD_b3486a;
      if (0x800 < iVar1) {
        if ((iVar1 != 0x1000) && (iVar1 != 0x2000)) {
          return 0;
        }
        goto switchD_00b34826_caseD_b3486a;
      }
      if (iVar1 != 0x400) {
        return 0;
      }
      piVar3 = *(int **)(piVar3 + 2);
      break;
    case (undefined *)0xb3486a:
switchD_00b34826_caseD_b3486a:
      piVar3 = *(int **)(piVar3 + 2);
      break;
    case (undefined *)0xb34880:
      goto switchD_00b34826_caseD_b34880;
    }
    iVar1 = *piVar3;
  } while( true );
switchD_00b34826_caseD_b34880:
  param_1 = *(int **)(piVar3 + 6);
  if ((piVar3[1] & 0x80U) != 0) {
    piVar3[1] = piVar3[1] | 8;
    iVar1 = FUN_00b34650(param_1,param_2,1);
    if (0 < iVar1) {
      return 0xffffff23;
    }
    piVar3[1] = piVar3[1] & 0xfffffff7;
    param_1 = *(int **)(piVar3 + 6);
  }
  goto LAB_00b3481c;
switchD_00b34826_caseD_b34830:
  do {
    uVar2 = FUN_00b34810(*(undefined8 *)(piVar3 + 2),param_2);
    if ((int)uVar2 != 0) {
      return uVar2;
    }
    piVar3 = *(int **)(piVar3 + 4);
  } while (piVar3 != (int *)0x0);
  return uVar2;
}


// ==== entry=00b348d0 name=FUN_00b348d0 size=204 ====

uint FUN_00b348d0(undefined4 *param_1)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  
  uVar1 = *param_1;
  do {
    switch(uVar1) {
    case 5:
switchD_00b348e3_caseD_5:
      param_1 = *(undefined4 **)(param_1 + 2);
      break;
    case 6:
      uVar4 = param_1[1];
      uVar3 = 0;
      if (((uVar4 & 0x10) == 0) && (uVar3 = 1, (uVar4 & 8) == 0)) {
        param_1[1] = uVar4 | 0x10;
        uVar3 = FUN_00b348d0(*(undefined8 *)(param_1 + 6));
        param_1[1] = param_1[1] & 0xffffffef;
      }
      return uVar3;
    case 7:
      iVar2 = param_1[1];
      if (iVar2 == 0x800) goto switchD_00b348e3_caseD_5;
      if (0x800 < iVar2) {
        if ((iVar2 != 0x1000) && (iVar2 != 0x2000)) {
          return 0;
        }
        goto switchD_00b348e3_caseD_5;
      }
      if (iVar2 != 0x400) {
        return 0;
      }
      param_1 = *(undefined4 **)(param_1 + 2);
      break;
    case 8:
    case 9:
      uVar4 = 0;
      do {
        uVar3 = FUN_00b348d0(*(undefined8 *)(param_1 + 2));
        param_1 = *(undefined4 **)(param_1 + 4);
        uVar4 = uVar4 | uVar3;
      } while (param_1 != (undefined4 *)0x0);
      return uVar4;
    case 10:
      uVar4 = FUN_00b348d0(*(undefined8 *)(param_1 + 8));
      if (uVar4 == 0) {
        return 0;
      }
      param_1[1] = param_1[1] | 0x80;
      return uVar4;
    default:
      return 0;
    }
    uVar1 = *param_1;
  } while( true );
}


// ==== entry=00b349c0 name=FUN_00b349c0 size=246 ====

uint FUN_00b349c0(undefined4 *param_1,undefined8 param_2)

{
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  undefined8 uVar5;
  
  uVar1 = *param_1;
  do {
    switch(uVar1) {
    case 5:
      uVar3 = FUN_00b349c0(*(undefined8 *)(param_1 + 2),param_2);
      if ((param_1[5] == 0) && (uVar3 == 1)) {
        param_1[0xc] = 1;
      }
      return uVar3;
    case 6:
      uVar3 = param_1[1];
      uVar5 = *(undefined8 *)(param_1 + 6);
      if (((uVar3 & 0x80) == 0) && ((uVar3 & 0x100) != 0)) {
        param_1[1] = uVar3 | 8;
        iVar4 = FUN_00b348d0(uVar5);
        uVar3 = param_1[1];
        if (iVar4 != 0) {
          uVar3 = uVar3 | 0x80;
        }
        uVar5 = *(undefined8 *)(param_1 + 6);
        param_1[1] = uVar3 & 0xfffffff7;
      }
      uVar3 = FUN_00b349c0(uVar5,param_2);
      if ((*(byte *)((long)param_1 + 5) & 1) != 0) {
        return uVar3 | 1;
      }
      return uVar3;
    case 7:
      iVar4 = param_1[1];
      if (iVar4 != 0x800) {
        if (iVar4 < 0x801) {
          if (iVar4 != 0x400) {
            return 0;
          }
        }
        else if ((iVar4 != 0x1000) && (iVar4 != 0x2000)) {
          return 0;
        }
      }
      param_1 = *(undefined4 **)(param_1 + 2);
      uVar1 = *param_1;
      break;
    case 8:
    case 9:
      uVar3 = 0;
      do {
        uVar2 = FUN_00b349c0(*(undefined8 *)(param_1 + 2),param_2);
        if (uVar2 == 1) {
          uVar3 = 1;
        }
        else if ((int)uVar2 < 0) {
          return uVar2;
        }
        param_1 = *(undefined4 **)(param_1 + 4);
      } while (param_1 != (undefined4 *)0x0);
      return uVar3;
    default:
      return 0;
    }
  } while( true );
}


// ==== entry=00b34ae0 name=FUN_00b34ae0 size=291 ====

ulong FUN_00b34ae0(int *param_1,long param_2,int *param_3)

{
  int iVar1;
  ulong uVar2;
  int *piVar3;
  int *piVar4;
  
  piVar3 = *(int **)param_1;
LAB_00b34af6:
  iVar1 = *piVar3;
  piVar4 = piVar3;
  do {
    if (4 < iVar1 - 5U) {
      return 0;
    }
    switch((&switchD_00b34b00::switchdataD_00d43310)[iVar1 - 5U]) {
    case (undefined *)0xb34b10:
      goto switchD_00b34b00_caseD_b34b10;
    case (undefined *)0xb34b40:
      iVar1 = piVar4[1];
      if (iVar1 != 0x800) {
        if (iVar1 < 0x801) {
          if (iVar1 != 0x400) {
            return 0;
          }
        }
        else if ((iVar1 != 0x1000) && (iVar1 != 0x2000)) {
          return 0;
        }
      }
      param_1 = piVar4 + 2;
      piVar4 = *(int **)(piVar4 + 2);
      iVar1 = *piVar4;
      break;
    case (undefined *)0xb34b78:
      goto switchD_00b34b00_caseD_b34b78;
    case (undefined *)0xb34b90:
      piVar3 = *(int **)(piVar4 + 2);
      uVar2 = FUN_00b34ae0(piVar4 + 2,param_2,param_3);
      if (*(int **)(piVar4 + 2) == piVar3) {
        return uVar2;
      }
      if (**(int **)(piVar4 + 2) != 5) {
        return uVar2;
      }
      FUN_00b313d0(piVar4);
      return uVar2 & 0xffffffff;
    }
  } while( true );
switchD_00b34b00_caseD_b34b78:
  piVar3 = *(int **)(piVar4 + 6);
  if (piVar4[2] == 1) {
    if ((*(byte *)((long)piVar4 + 5) & 4) == 0) {
      *(int **)param_1 = piVar3;
      piVar4[6] = 0;
      piVar4[7] = 0;
      thunk_FUN_00b2d8d0(piVar4);
      piVar3 = *(int **)param_1;
    }
    else {
      param_1 = piVar4 + 6;
      iVar1 = *param_3 + 1;
      *param_3 = iVar1;
      *(int *)(param_2 + (long)piVar4[3] * 4) = iVar1;
      piVar4[3] = iVar1;
    }
  }
  else {
    param_1 = piVar4 + 6;
  }
  goto LAB_00b34af6;
switchD_00b34b00_caseD_b34b10:
  do {
    uVar2 = FUN_00b34ae0(piVar4 + 2,param_2,param_3);
    if ((int)uVar2 != 0) {
      return uVar2;
    }
    piVar4 = *(int **)(piVar4 + 4);
  } while (piVar4 != (int *)0x0);
  return uVar2;
}


// ==== entry=00b34c30 name=FUN_00b34c30 size=348 ====

/* WARNING: Type propagation algorithm not settling */

void FUN_00b34c30(undefined8 *param_1,long param_2,long param_3)

{
  long lVar1;
  uint uVar2;
  undefined8 uVar3;
  long lVar4;
  int iVar5;
  undefined4 *puVar6;
  long lVar7;
  int iVar8;
  long lVar9;
  long lVar10;
  undefined8 auStack_40 [2];
  int aiStack_30 [2];
  
  iVar5 = *(int *)(param_3 + 0x60);
  lVar4 = -((long)(iVar5 + 1) * 4 + 0x17U & 0xfffffffffffffff0);
  lVar1 = (long)aiStack_30 + lVar4;
  if (0 < iVar5) {
    puVar6 = (undefined4 *)((long)aiStack_30 + lVar4 + 4U);
    do {
      *puVar6 = 0;
      puVar6 = puVar6 + 1;
    } while (puVar6 != (undefined4 *)(&stack0xffffffffffffffd8 + (ulong)(iVar5 - 1) * 4 + lVar4));
  }
  aiStack_30[1] = 0;
  *(undefined8 *)((long)auStack_40 + lVar4) = 0xb34ca5;
  iVar5 = FUN_00b34ae0(param_1,lVar1,aiStack_30 + 1);
  if (iVar5 == 0) {
    uVar3 = *param_1;
    *(undefined8 *)((long)auStack_40 + lVar4) = 0xb34ccb;
    iVar5 = FUN_00b33ae0(uVar3,lVar1);
    if (iVar5 == 0) {
      iVar5 = *(int *)(param_3 + 0x60);
      if (0 < iVar5) {
        iVar8 = 1;
        lVar7 = 1;
        do {
          if (0 < *(int *)(lVar1 + lVar7 * 4)) {
            lVar9 = *(long *)(param_3 + 0xb0);
            if (*(long *)(param_3 + 0xb0) == 0) {
              lVar9 = param_3 + 0x70;
            }
            lVar10 = (long)iVar8;
            iVar8 = iVar8 + 1;
            *(undefined8 *)(lVar9 + lVar10 * 8) = *(undefined8 *)(lVar9 + lVar7 * 8);
          }
          lVar7 = lVar7 + 1;
        } while (lVar7 != (ulong)(iVar5 - 1) + 2);
      }
      uVar2 = *(uint *)(param_3 + 0x18);
      lVar7 = 1;
      *(undefined4 *)(param_3 + 0x18) = 0;
      do {
        if ((1 << ((byte)lVar7 & 0x1f) & uVar2) != 0) {
          iVar5 = *(int *)(lVar1 + lVar7 * 4);
          if (iVar5 < 0x20) {
            *(uint *)(param_3 + 0x18) = *(uint *)(param_3 + 0x18) | 1 << ((byte)iVar5 & 0x1f);
          }
        }
        lVar7 = lVar7 + 1;
      } while (lVar7 != 0x20);
      *(undefined4 *)(param_3 + 0x60) = *(undefined4 *)(param_3 + 100);
      *(undefined4 *)(param_2 + 0x14) = *(undefined4 *)(param_3 + 100);
      *(undefined8 *)((long)auStack_40 + lVar4) = 0xb34d8c;
      FUN_00b2e970(param_2,lVar1);
      return;
    }
  }
  return;
}


// ==== entry=00b34da0 name=FUN_00b34da0 size=487 ====

undefined8 FUN_00b34da0(undefined4 *param_1,uint *param_2)

{
  uint uVar1;
  int iVar2;
  long lVar3;
  undefined8 uVar4;
  uint *puVar5;
  int *local_20;
  
  switch(*param_1) {
  case 6:
    uVar4 = FUN_00b34da0(*(undefined8 *)(param_1 + 6));
    return uVar4;
  case 7:
    iVar2 = param_1[1];
    if (iVar2 != 0x800) {
      if (iVar2 < 0x801) {
        if (iVar2 != 0x400) {
          return 0;
        }
      }
      else if ((iVar2 != 0x1000) && (iVar2 != 0x2000)) {
        return 0;
      }
    }
  case 5:
    uVar4 = FUN_00b34da0(*(undefined8 *)(param_1 + 2),param_2);
    return uVar4;
  case 8:
    do {
      uVar4 = FUN_00b34da0(*(undefined8 *)(param_1 + 2),param_2);
      if ((int)uVar4 != 0) {
        return uVar4;
      }
      param_1 = *(undefined4 **)(param_1 + 4);
    } while (param_1 != (undefined4 *)0x0);
    uVar4 = 0;
    break;
  case 9:
    do {
      uVar4 = FUN_00b34da0(*(undefined8 *)(param_1 + 2),param_2);
      if ((int)uVar4 != 0) {
        return uVar4;
      }
      param_1 = *(undefined4 **)(param_1 + 4);
    } while (param_1 != (undefined4 *)0x0);
    uVar4 = 0;
    break;
  case 10:
    puVar5 = *(uint **)(param_2 + 0x2c);
    if (*(uint **)(param_2 + 0x2c) == (uint *)0x0) {
      puVar5 = param_2 + 0x1c;
    }
    iVar2 = param_1[2];
    lVar3 = (long)iVar2;
    if (iVar2 == 0) {
      if (*(long *)(param_1 + 4) == *(long *)(param_1 + 6)) goto LAB_00b34eb9;
      iVar2 = FUN_00b2e9b0(*(undefined8 *)(param_2 + 0x12),*(long *)(param_1 + 4),
                           *(long *)(param_1 + 6),&local_20);
      if (0 < iVar2) {
        if ((iVar2 != 1) && ((*(byte *)(*(long *)(param_2 + 4) + 9) & 4) == 0)) {
          FUN_00b33a30(param_2,0xffffff24,*(undefined8 *)(param_1 + 4),*(undefined8 *)(param_1 + 6))
          ;
          return 0xffffff24;
        }
        lVar3 = (long)*local_20;
        param_1[2] = *local_20;
        goto LAB_00b34eb9;
      }
    }
    else {
      if (((0 < (int)param_2[0x19]) && ((*(byte *)(*(long *)(param_2 + 4) + 8) & 0x80) != 0)) &&
         ((*param_2 & 0x100) == 0)) {
        return 0xffffff2f;
      }
      if ((int)param_2[0x18] < iVar2) {
        FUN_00b33a30(param_2,0xffffff26,*(undefined8 *)(param_1 + 4),*(undefined8 *)(param_1 + 6));
        return 0xffffff26;
      }
LAB_00b34eb9:
      lVar3 = *(long *)(puVar5 + lVar3 * 2);
      *(long *)(param_1 + 8) = lVar3;
      if (lVar3 != 0) {
        *(uint *)(lVar3 + 4) = *(uint *)(lVar3 + 4) | 0x100;
        uVar1 = param_2[7] | 1 << (param_1[2] & 0x1f);
        if (0x1f < (int)param_1[2]) {
          uVar1 = param_2[7] | 1;
        }
        param_2[7] = uVar1;
        *(undefined8 *)(param_1 + 10) = *(undefined8 *)(param_2 + 0x16);
        return 0;
      }
    }
    FUN_00b33a30(param_2,0xffffff27,*(undefined8 *)(param_1 + 4),*(undefined8 *)(param_1 + 6));
    uVar4 = 0xffffff27;
    break;
  default:
    return 0;
  }
  return uVar4;
}


// ==== entry=00b34fc0 name=FUN_00b34fc0 size=83 ====

undefined8 FUN_00b34fc0(undefined8 *param_1,undefined4 param_2)

{
  uint uVar1;
  void *__ptr;
  uint uVar2;
  ulong __size;
  
  uVar1 = *(uint *)(param_1 + 1);
  __size = (ulong)*(uint *)((long)param_1 + 0xc);
  __ptr = (void *)*param_1;
  uVar2 = uVar1 + 4;
  if (*(uint *)((long)param_1 + 0xc) < uVar2) {
    do {
      uVar1 = (int)__size * 2;
      __size = (ulong)uVar1;
    } while (uVar1 < uVar2);
    *(uint *)((long)param_1 + 0xc) = uVar1;
    __ptr = realloc(__ptr,__size);
    *param_1 = __ptr;
    if (__ptr == (void *)0x0) {
      return 0xfffffffb;
    }
    uVar1 = *(uint *)(param_1 + 1);
  }
  *(undefined4 *)((long)__ptr + (ulong)uVar1) = param_2;
  if (*(uint *)(param_1 + 1) < uVar2) {
    *(uint *)(param_1 + 1) = uVar2;
  }
  return 0;
}


// ==== entry=00b35020 name=FUN_00b35020 size=111 ====

undefined8 FUN_00b35020(undefined8 *param_1,void *param_2,size_t param_3)

{
  uint uVar1;
  void *__ptr;
  uint uVar2;
  ulong __size;
  
  uVar1 = *(uint *)(param_1 + 1);
  __size = (ulong)*(uint *)((long)param_1 + 0xc);
  __ptr = (void *)*param_1;
  uVar2 = uVar1 + (int)param_3;
  if (*(uint *)((long)param_1 + 0xc) < uVar2) {
    do {
      uVar1 = (int)__size * 2;
      __size = (ulong)uVar1;
    } while (uVar1 < uVar2);
    *(uint *)((long)param_1 + 0xc) = uVar1;
    __ptr = realloc(__ptr,__size);
    *param_1 = __ptr;
    if (__ptr == (void *)0x0) {
      return 0xfffffffb;
    }
    uVar1 = *(uint *)(param_1 + 1);
  }
  memcpy((void *)((long)__ptr + (ulong)uVar1),param_2,param_3);
  if (*(uint *)(param_1 + 1) < uVar2) {
    *(uint *)(param_1 + 1) = uVar2;
  }
  return 0;
}


// ==== entry=00b35090 name=FUN_00b35090 size=106 ====

undefined8 FUN_00b35090(undefined8 *param_1,undefined8 *param_2)

{
  uint uVar1;
  undefined8 uVar2;
  void *__ptr;
  undefined8 *puVar3;
  uint uVar4;
  ulong __size;
  
  uVar1 = *(uint *)(param_1 + 1);
  __size = (ulong)*(uint *)((long)param_1 + 0xc);
  __ptr = (void *)*param_1;
  uVar4 = uVar1 + 0x20;
  if (*(uint *)((long)param_1 + 0xc) < uVar4) {
    do {
      uVar1 = (int)__size * 2;
      __size = (ulong)uVar1;
    } while (uVar1 < uVar4);
    *(uint *)((long)param_1 + 0xc) = uVar1;
    __ptr = realloc(__ptr,__size);
    *param_1 = __ptr;
    if (__ptr == (void *)0x0) {
      return 0xfffffffb;
    }
    uVar1 = *(uint *)(param_1 + 1);
  }
  uVar2 = param_2[1];
  puVar3 = (undefined8 *)((long)__ptr + (ulong)uVar1);
  *puVar3 = *param_2;
  puVar3[1] = uVar2;
  uVar2 = param_2[3];
  puVar3[2] = param_2[2];
  puVar3[3] = uVar2;
  if (*(uint *)(param_1 + 1) < uVar4) {
    *(uint *)(param_1 + 1) = uVar4;
  }
  return 0;
}


// ==== entry=00b35100 name=FUN_00b35100 size=83 ====

undefined8 FUN_00b35100(undefined8 *param_1,undefined4 param_2)

{
  uint uVar1;
  void *__ptr;
  uint uVar2;
  ulong __size;
  
  uVar1 = *(uint *)(param_1 + 1);
  __size = (ulong)*(uint *)((long)param_1 + 0xc);
  __ptr = (void *)*param_1;
  uVar2 = uVar1 + 4;
  if (*(uint *)((long)param_1 + 0xc) < uVar2) {
    do {
      uVar1 = (int)__size * 2;
      __size = (ulong)uVar1;
    } while (uVar1 < uVar2);
    *(uint *)((long)param_1 + 0xc) = uVar1;
    __ptr = realloc(__ptr,__size);
    *param_1 = __ptr;
    if (__ptr == (void *)0x0) {
      return 0xfffffffb;
    }
    uVar1 = *(uint *)(param_1 + 1);
  }
  *(undefined4 *)((long)__ptr + (ulong)uVar1) = param_2;
  if (*(uint *)(param_1 + 1) < uVar2) {
    *(uint *)(param_1 + 1) = uVar2;
  }
  return 0;
}


// ==== entry=00b35160 name=FUN_00b35160 size=84 ====

undefined8 FUN_00b35160(undefined8 *param_1,undefined2 param_2)

{
  uint uVar1;
  void *__ptr;
  uint uVar2;
  ulong __size;
  
  uVar1 = *(uint *)(param_1 + 1);
  __size = (ulong)*(uint *)((long)param_1 + 0xc);
  __ptr = (void *)*param_1;
  uVar2 = uVar1 + 2;
  if (*(uint *)((long)param_1 + 0xc) < uVar2) {
    do {
      uVar1 = (int)__size * 2;
      __size = (ulong)uVar1;
    } while (uVar1 < uVar2);
    *(uint *)((long)param_1 + 0xc) = uVar1;
    __ptr = realloc(__ptr,__size);
    *param_1 = __ptr;
    if (__ptr == (void *)0x0) {
      return 0xfffffffb;
    }
    uVar1 = *(uint *)(param_1 + 1);
  }
  *(undefined2 *)((long)__ptr + (ulong)uVar1) = param_2;
  if (*(uint *)(param_1 + 1) < uVar2) {
    *(uint *)(param_1 + 1) = uVar2;
  }
  return 0;
}


// ==== entry=00b351c0 name=FUN_00b351c0 size=83 ====

undefined8 FUN_00b351c0(undefined8 *param_1,undefined1 param_2)

{
  uint uVar1;
  void *__ptr;
  uint uVar2;
  ulong __size;
  
  uVar1 = *(uint *)(param_1 + 1);
  __size = (ulong)*(uint *)((long)param_1 + 0xc);
  __ptr = (void *)*param_1;
  uVar2 = uVar1 + 1;
  if (*(uint *)((long)param_1 + 0xc) < uVar2) {
    do {
      uVar1 = (int)__size * 2;
      __size = (ulong)uVar1;
    } while (uVar1 < uVar2);
    *(uint *)((long)param_1 + 0xc) = uVar1;
    __ptr = realloc(__ptr,__size);
    *param_1 = __ptr;
    if (__ptr == (void *)0x0) {
      return 0xfffffffb;
    }
    uVar1 = *(uint *)(param_1 + 1);
  }
  *(undefined1 *)((long)__ptr + (ulong)uVar1) = param_2;
  if (*(uint *)(param_1 + 1) < uVar2) {
    *(uint *)(param_1 + 1) = uVar2;
  }
  return 0;
}


// ==== entry=00b35220 name=FUN_00b35220 size=43 ====

void FUN_00b35220(undefined8 param_1,undefined8 param_2,undefined4 param_3)

{
  int iVar1;
  
  iVar1 = FUN_00b351c0();
  if (iVar1 != 0) {
    return;
  }
  FUN_00b34fc0(param_1,param_3);
  return;
}


// ==== entry=00b35250 name=FUN_00b35250 size=89 ====

int FUN_00b35250(int param_1,long param_2,int param_3)

{
  int iVar1;
  
  if (param_3 != 0) {
    return (param_2 != 1) + 0xe;
  }
  if (param_1 == 2) {
    iVar1 = 0xb;
    if (param_2 - 1U < 3) {
      return *(int *)(&DAT_00d43508 + (param_2 - 1U) * 4);
    }
  }
  else {
    iVar1 = 0xc;
    if ((param_1 != 3) && (iVar1 = 0xd, param_1 == 1)) {
      iVar1 = 7;
      if (param_2 - 1U < 5) {
        return *(int *)(&DAT_00d43520 + (param_2 - 1U) * 4);
      }
    }
  }
  return iVar1;
}


// ==== entry=00b352c0 name=FUN_00b352c0 size=154 ====

undefined8
FUN_00b352c0(undefined8 param_1,int param_2,long param_3,undefined8 param_4,undefined4 param_5)

{
  uint uVar1;
  undefined8 uVar2;
  
  uVar2 = param_4;
  uVar1 = FUN_00b35250(param_2,param_3,param_5);
  FUN_00b351c0(uVar2,uVar1);
  if (uVar1 == 0xd) {
    FUN_00b35100(param_4);
    FUN_00b35100(param_4,param_3);
  }
  else if (((uVar1 & 0xfffffff7) == 7) || (uVar1 - 0xb < 3)) {
    if (uVar1 == 0xf) {
      FUN_00b35100(param_4,param_3 * param_2);
    }
    else {
      FUN_00b35100(param_4,param_3);
    }
  }
  FUN_00b35020(param_4,param_1,param_3 * param_2);
  return 0;
}


// ==== entry=00b35370 name=FUN_00b35370 size=54 ====

int FUN_00b35370(int param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = FUN_00b35250();
  iVar2 = 9;
  if ((uVar1 != 0xd) && ((uVar1 - 0xb < 3 || (iVar2 = 1, (uVar1 & 0xfffffff7) == 7)))) {
    iVar2 = 5;
  }
  return param_1 * param_2 + iVar2;
}


// ==== entry=00b353b0 name=FUN_00b353b0 size=1367 ====

ulong FUN_00b353b0(uint *param_1,long param_2)

{
  uint uVar1;
  uint uVar2;
  undefined4 uVar3;
  undefined8 *puVar4;
  int *piVar5;
  uint uVar6;
  int iVar7;
  uint *puVar8;
  uint uVar9;
  int iVar10;
  ulong uVar11;
  long lVar12;
  ulong uVar13;
  ulong uVar14;
  ulong uVar15;
  uint uVar16;
  int iVar17;
  
  uVar16 = *param_1;
  uVar11 = (ulong)uVar16;
  switch(uVar16) {
  case 0:
    uVar15 = *(ulong *)(param_1 + 2);
    uVar14 = *(ulong *)(param_1 + 4);
    if ((param_1[6] & 1) == 0) {
      if (uVar15 < uVar14) {
        puVar4 = *(undefined8 **)(param_2 + 0x48);
        uVar6 = param_1[6] >> 1 & 1;
        iVar7 = (*(code *)*puVar4)(uVar15);
        uVar14 = (ulong)iVar7;
        uVar15 = uVar14 + uVar15;
        if (uVar15 < *(ulong *)(param_1 + 4)) {
          iVar7 = 1;
          do {
            iVar10 = (*(code *)*puVar4)(uVar15);
            uVar13 = (ulong)iVar10;
            if (iVar10 == (int)uVar14) {
              iVar7 = iVar7 + 1;
            }
            else {
              lVar12 = (long)iVar7;
              iVar7 = 1;
              iVar10 = FUN_00b35370(uVar14 & 0xffffffff,lVar12,uVar6);
              uVar11 = (ulong)(uint)((int)uVar11 + iVar10);
              uVar14 = uVar13 & 0xffffffff;
            }
            uVar16 = (uint)uVar11;
            uVar15 = uVar15 + uVar13;
          } while (uVar15 < *(ulong *)(param_1 + 4));
          lVar12 = (long)iVar7;
        }
        else {
          lVar12 = 1;
        }
        iVar7 = FUN_00b35370(uVar14 & 0xffffffff,lVar12,uVar6);
        uVar11 = (ulong)(uVar16 + iVar7);
      }
    }
    else if (uVar15 < uVar14) {
      uVar11 = FUN_00b35370(1,uVar14 - uVar15,0);
      return uVar11;
    }
    break;
  case 1:
    uVar11 = 9;
    if ((param_1[1] & 2) == 0) {
      if (*(long *)(param_1 + 10) == 0) {
        uVar11 = 0x21;
      }
      else {
        iVar7 = 1;
        if (*(int *)(*(long *)(param_2 + 0x48) + 0x1c) < 2) {
          puVar8 = param_1 + 2;
          do {
            if (*puVar8 != 0) {
              iVar7 = 0x21;
              goto LAB_00b355fb;
            }
            puVar8 = puVar8 + 1;
          } while (puVar8 != param_1 + 10);
          iVar7 = 1;
        }
LAB_00b355fb:
        uVar11 = (ulong)(uint)(iVar7 + 4 + *(int *)(*(long *)(param_1 + 10) + 8));
      }
    }
    break;
  case 4:
    uVar16 = param_1[2];
    if ((*(byte *)((long)param_1 + 5) & 0x20) == 0) {
      if (uVar16 == 1) {
        if ((*(byte *)(param_2 + 0x50) & 1) == 0) {
          uVar16 = 1;
          if (2 < (int)param_1[3]) {
            uVar16 = 3;
          }
          uVar11 = (ulong)uVar16;
        }
        else {
          uVar11 = 3;
        }
      }
      else {
        uVar11 = (ulong)(uVar16 * 2 + 5);
      }
    }
    else {
      uVar11 = (ulong)(uVar16 * 2 + 0xd);
    }
    break;
  case 5:
    uVar1 = param_1[5];
    uVar2 = param_1[7];
    uVar6 = FUN_00b353b0(*(undefined8 *)(param_1 + 2));
    if ((int)uVar6 < 0) {
LAB_00b357e0:
      return (ulong)uVar6;
    }
    uVar9 = uVar6;
    if ((**(int **)(param_1 + 2) == 3) && (param_1[6] != 0)) {
      if (uVar1 == 0xffffffff) {
        if (*(long *)(param_1 + 10) != 0) {
          return (ulong)(uVar6 * param_1[4] + 2);
        }
        return (ulong)(uVar6 * param_1[4] + 1);
      }
      if (uVar2 != 0) {
LAB_00b35660:
        uVar9 = uVar6 + 6;
        goto LAB_00b354e1;
      }
      uVar16 = param_1[5];
      if (uVar16 == 0) {
LAB_00b354f6:
        if (param_1[0xc] != 0) {
LAB_00b35501:
          return (ulong)(uVar6 + 5);
        }
        if (param_1[6] != 0) {
          uVar16 = 0;
LAB_00b35968:
          return (ulong)((uVar16 - param_1[4]) * (uVar6 + 5) + uVar6 * param_1[4]);
        }
        goto LAB_00b35738;
      }
LAB_00b356d0:
      if ((uVar16 == 1) || ((int)((uVar6 + 5) * uVar16) < 0x33)) goto LAB_00b35968;
    }
    else {
      if (uVar2 != 0) goto LAB_00b35660;
LAB_00b354e1:
      if (uVar1 == 0xffffffff) {
        uVar1 = param_1[4];
        if ((int)uVar1 < 2) {
          if ((uVar1 != 1) || ((int)uVar6 < 0x33)) {
            uVar16 = uVar6 * uVar1;
          }
LAB_00b35907:
          if ((param_1[6] != 0) && ((*(long *)(param_1 + 8) != 0 || (*(long *)(param_1 + 10) != 0)))
             ) {
            return (ulong)(uVar9 + 0xb + uVar16);
          }
          return (ulong)(uVar9 + 10 + uVar16);
        }
        uVar16 = uVar1 * uVar6;
        if ((int)uVar16 < 0x33) goto LAB_00b35907;
        if ((param_1[5] == 0) && (param_1[0xc] != 0)) goto LAB_00b35501;
        if (param_1[6] == 0) goto LAB_00b35738;
      }
      else {
        uVar16 = param_1[5];
        if (uVar16 == 0) goto LAB_00b354f6;
        if (param_1[6] != 0) goto LAB_00b356d0;
LAB_00b35738:
        if (*(long *)(param_1 + 4) == 0x100000000) {
          return (ulong)(uVar6 + 10);
        }
      }
    }
    uVar11 = (ulong)(uVar9 + 10);
    break;
  case 6:
    uVar16 = param_1[2];
    if (uVar16 == 2) {
      uVar3 = *(undefined4 *)(param_2 + 0x50);
      *(uint *)(param_2 + 0x50) = param_1[4];
      uVar16 = FUN_00b353b0();
      *(undefined4 *)(param_2 + 0x50) = uVar3;
      return (ulong)uVar16;
    }
    if (*(long *)(param_1 + 6) == 0) {
      uVar6 = 0;
    }
    else {
      uVar6 = FUN_00b353b0();
      if ((int)uVar6 < 0) {
        return (ulong)uVar6;
      }
      uVar16 = param_1[2];
    }
    if (uVar16 == 4) {
      if ((param_1[1] & 0x40) == 0) {
        return (ulong)(uVar6 + 2);
      }
      lVar12 = *(long *)(param_1 + 6);
      uVar16 = FUN_00b353b0(*(undefined8 *)(lVar12 + 8),param_2);
      if ((int)uVar16 < 0) {
        return (ulong)uVar16;
      }
      return (ulong)(uVar16 + 0xb + *(int *)(lVar12 + 0x10) * uVar16);
    }
    if (uVar16 == 8) {
      piVar5 = *(int **)(param_1 + 6);
      if (*piVar5 == 9) {
        uVar16 = FUN_00b353b0(*(undefined8 *)(piVar5 + 2),param_2);
        if ((int)uVar16 < 0) {
          return (ulong)uVar16;
        }
        lVar12 = *(long *)(piVar5 + 4);
        if (lVar12 != 0) {
          uVar6 = FUN_00b353b0(*(undefined8 *)(lVar12 + 8),param_2);
          if (-1 < (int)uVar6) {
            uVar16 = uVar6 + 0xc + uVar16;
            if (*(long *)(lVar12 + 0x10) != 0) {
              uVar16 = 0xffffff84;
            }
            return (ulong)uVar16;
          }
          goto LAB_00b357e0;
        }
      }
      return 0xfffffff5;
    }
    if (uVar16 == 1) {
      uVar16 = uVar6 + 6;
      if ((*(byte *)((long)param_1 + 5) & 1) != 0) {
        uVar16 = uVar6 + 0x11;
      }
      return (ulong)uVar16;
    }
  default:
    uVar11 = 0xfffffffa;
    break;
  case 7:
    if (*(long *)(param_1 + 2) == 0) {
      uVar16 = 0;
    }
    else {
      uVar16 = FUN_00b353b0();
      if ((int)uVar16 < 0) {
        return (ulong)uVar16;
      }
    }
    uVar6 = param_1[1];
    if (uVar6 == 0x800) {
      return (ulong)(uVar16 + 6);
    }
    if ((int)uVar6 < 0x801) {
      if (uVar6 == 0x400) {
        return (ulong)(uVar16 + 2);
      }
    }
    else {
      if (uVar6 == 0x1000) {
        return (ulong)(uVar16 + 5);
      }
      if (uVar6 == 0x2000) {
        return (ulong)(uVar16 + 10);
      }
    }
  case 2:
  case 3:
    uVar11 = 1;
    break;
  case 8:
    uVar16 = 0;
    do {
      uVar6 = FUN_00b353b0(*(undefined8 *)(param_1 + 2),param_2);
      if ((int)uVar6 < 0) {
        return (ulong)uVar6;
      }
      param_1 = *(uint **)(param_1 + 4);
      uVar16 = uVar16 + uVar6;
    } while (param_1 != (uint *)0x0);
    uVar11 = (ulong)uVar16;
    break;
  case 9:
    iVar10 = 0;
    iVar7 = 0;
    do {
      iVar17 = iVar7;
      iVar7 = FUN_00b353b0(*(undefined8 *)(param_1 + 2),param_2);
      param_1 = *(uint **)(param_1 + 4);
      iVar10 = iVar10 + iVar7;
      iVar7 = iVar17 + 1;
    } while (param_1 != (uint *)0x0);
    uVar11 = (ulong)(uint)(iVar10 + iVar17 * 10);
    break;
  case 10:
    uVar11 = 5;
  }
  return uVar11;
}


// ==== entry=00b359d0 name=FUN_00b359d0 size=201 ====

uint * FUN_00b359d0(uint *param_1,int param_2,long param_3)

{
  uint uVar1;
  undefined4 uVar2;
  undefined8 uVar3;
  uint *puVar4;
  
LAB_00b359d9:
  if (8 < *param_1) {
LAB_00b35a12:
    return (uint *)0x0;
  }
  do {
    switch((&switchD_00b359e0::switchdataD_00d433c0)[*param_1]) {
    case (undefined *)0xb359f0:
      if ((int)param_1[4] < 1) {
        return (uint *)0x0;
      }
      if (*(uint **)(param_1 + 8) != (uint *)0x0) {
        return *(uint **)(param_1 + 8);
      }
    case (undefined *)0xb35a04:
      param_1 = *(uint **)(param_1 + 2);
      break;
    case (undefined *)0xb35a10:
      goto LAB_00b35a12;
    case (undefined *)0xb35a20:
      if (param_1[1] != 0x400) {
        return (uint *)0x0;
      }
      param_1 = *(uint **)(param_1 + 2);
      break;
    case (undefined *)0xb35a30:
      goto switchD_00b359e0_caseD_b35a30;
    case (undefined *)0xb35a50:
      if (*(ulong *)(param_1 + 4) <= *(ulong *)(param_1 + 2)) {
        return (uint *)0x0;
      }
      if (param_2 == 0) {
        return param_1;
      }
      if ((param_1[6] & 1) != 0) {
        return param_1;
      }
      if ((*(byte *)(param_3 + 0x50) & 1) != 0) {
        return (uint *)0x0;
      }
      return param_1;
    case (undefined *)0xb35a80:
      if (param_2 == 0) {
        return param_1;
      }
      return (uint *)0x0;
    }
    if (8 < *param_1) {
      return (uint *)0x0;
    }
  } while( true );
switchD_00b359e0_caseD_b35a30:
  uVar1 = param_1[2];
  if (uVar1 == 2) {
    uVar2 = *(undefined4 *)(param_3 + 0x50);
    uVar3 = *(undefined8 *)(param_1 + 6);
    *(uint *)(param_3 + 0x50) = param_1[4];
    puVar4 = (uint *)FUN_00b359d0(uVar3,param_2,param_3);
    *(undefined4 *)(param_3 + 0x50) = uVar2;
    return puVar4;
  }
  if ((int)uVar1 < 3) {
    if (uVar1 != 1) {
      return (uint *)0x0;
    }
  }
  else if ((uVar1 != 4) && (uVar1 != 8)) {
    return (uint *)0x0;
  }
  param_1 = *(uint **)(param_1 + 6);
  goto LAB_00b359d9;
}


// ==== entry=00b35ad0 name=FUN_00b35ad0 size=122 ====

int FUN_00b35ad0(ulong *param_1,ulong *param_2,int param_3,int param_4)

{
  ulong uVar1;
  ulong uVar2;
  ulong uVar3;
  int iVar4;
  ulong uVar5;
  
  uVar1 = *param_1;
  uVar2 = *param_2;
  uVar3 = param_2[1];
  if (param_1[1] == 0xffffffffffffffff) {
    param_3 = 0;
    if (uVar3 == 0xffffffffffffffff) goto LAB_00b35b0c;
LAB_00b35af3:
    if (uVar3 - uVar2 < 100) {
      param_4 = param_4 * *(short *)(&DAT_00d43640 + (uVar3 - uVar2) * 2);
    }
  }
  else {
    uVar5 = param_1[1] - uVar1;
    if (uVar5 < 100) {
      param_3 = param_3 * *(short *)(&DAT_00d43640 + uVar5 * 2);
    }
    if (uVar3 != 0xffffffffffffffff) goto LAB_00b35af3;
    param_4 = 0;
  }
  iVar4 = 1;
  if ((param_3 < param_4) || (iVar4 = -1, param_4 < param_3)) {
    return iVar4;
  }
LAB_00b35b0c:
  iVar4 = -(uint)(uVar1 < uVar2);
  if (uVar2 < uVar1) {
    iVar4 = 1;
  }
  return iVar4;
}


// ==== entry=00b35b60 name=FUN_00b35b60 size=235 ====

void FUN_00b35b60(long param_1,undefined8 *param_2,undefined8 *param_3)

{
  byte bVar1;
  undefined8 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  bool bVar7;
  
  iVar3 = *(int *)(param_3 + 4);
  if (iVar3 == 0) {
    return;
  }
  iVar4 = *(int *)(param_2 + 4);
  if (iVar4 != 0) {
    iVar5 = iVar3;
    if ((iVar4 < 3) && (iVar3 < 3)) {
      bVar1 = *(byte *)((long)param_2 + 0x24);
      iVar5 = 4;
      if ((bVar1 < 0x80) && ((bVar1 != 0 || (iVar5 = 0x14, *(int *)(param_1 + 0x1c) < 2)))) {
        iVar5 = (int)(short)(&DAT_00d43540)[bVar1];
      }
      bVar1 = *(byte *)((long)param_3 + 0x24);
      iVar6 = 4;
      if ((bVar1 < 0x80) && ((bVar1 != 0 || (iVar6 = 0x14, *(int *)(param_1 + 0x1c) < 2)))) {
        iVar6 = (int)(short)(&DAT_00d43540)[bVar1];
      }
      bVar7 = iVar4 == 2;
      iVar4 = iVar6;
      if (bVar7) {
        iVar4 = iVar6 + 5;
      }
      if (iVar3 == 2) {
        iVar5 = iVar5 + 5;
      }
    }
    if (*(int *)((long)param_2 + 0x1c) < 1) {
      iVar4 = iVar4 * 2;
    }
    if (*(int *)((long)param_3 + 0x1c) < 1) {
      iVar5 = iVar5 * 2;
    }
    if (iVar5 < 1) {
      return;
    }
    if ((0 < iVar4) && (iVar3 = FUN_00b35ad0(param_2,param_3), iVar3 < 1)) {
      return;
    }
  }
  uVar2 = param_3[1];
  *param_2 = *param_3;
  param_2[1] = uVar2;
  uVar2 = param_3[3];
  param_2[2] = param_3[2];
  param_2[3] = uVar2;
  uVar2 = param_3[5];
  param_2[4] = param_3[4];
  param_2[5] = uVar2;
  uVar2 = param_3[7];
  param_2[6] = param_3[6];
  param_2[7] = uVar2;
  return;
}


// ==== entry=00b35c60 name=FUN_00b35c60 size=113 ====

void FUN_00b35c60(ulong *param_1,ulong *param_2,ulong param_3,ulong param_4)

{
  ulong uVar1;
  ulong uVar2;
  
  uVar1 = *param_1;
  if ((uVar1 == 0xffffffffffffffff) || (param_3 == 0xffffffffffffffff)) {
    *param_1 = 0xffffffffffffffff;
    uVar1 = *param_2;
  }
  else {
    uVar2 = param_3 + uVar1;
    if (~param_3 < uVar1) {
      uVar2 = 0xffffffffffffffff;
    }
    *param_1 = uVar2;
    uVar1 = *param_2;
  }
  if ((uVar1 != 0xffffffffffffffff) && (param_4 != 0xffffffffffffffff)) {
    uVar2 = param_4 + uVar1;
    if (~param_4 < uVar1) {
      uVar2 = 0xffffffffffffffff;
    }
    *param_2 = uVar2;
    return;
  }
  *param_2 = 0xffffffffffffffff;
  return;
}


// ==== entry=00b35ce0 name=FUN_00b35ce0 size=235 ====

void FUN_00b35ce0(long param_1,long param_2,undefined8 *param_3)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  long lVar4;
  undefined4 uVar5;
  undefined1 *puVar6;
  int iVar8;
  undefined1 *puVar9;
  undefined1 *puVar7;
  
  if (*(int *)(param_1 + 0x1c) < 0) {
    *(int *)(param_1 + 0x1c) = *(int *)(param_2 + 0x1c);
  }
  else if (*(int *)(param_1 + 0x1c) != *(int *)(param_2 + 0x1c)) {
    return;
  }
  puVar6 = (undefined1 *)(param_2 + 0x24);
  iVar3 = *(int *)(param_1 + 0x20);
  puVar9 = puVar6 + *(int *)(param_2 + 0x20);
  do {
    if (puVar9 <= puVar6) {
      *(int *)(param_1 + 0x20) = iVar3;
      uVar5 = *(undefined4 *)(param_1 + 0x10);
      if (puVar9 == puVar6) {
        iVar3 = *(int *)(param_2 + 0x18);
        *(int *)(param_1 + 0x18) = iVar3;
        uVar2 = 0;
        if (iVar3 != 0) {
          uVar2 = *(undefined4 *)(param_2 + 0x14);
        }
      }
      else {
LAB_00b35db7:
        *(undefined4 *)(param_1 + 0x18) = 0;
        uVar2 = 0;
      }
      *(undefined4 *)(param_1 + 0x10) = uVar5;
      *(undefined4 *)(param_1 + 0x14) = uVar2;
      return;
    }
    iVar1 = (*(code *)*param_3)(puVar6);
    if (0x18 < iVar1 + iVar3) {
      *(int *)(param_1 + 0x20) = iVar3;
      uVar5 = *(undefined4 *)(param_1 + 0x10);
      goto LAB_00b35db7;
    }
    if ((puVar6 < puVar9) && (0 < iVar1)) {
      iVar8 = 0;
      lVar4 = (long)(iVar3 + 1);
      puVar7 = puVar6;
      do {
        puVar6 = puVar7 + 1;
        iVar8 = iVar8 + 1;
        iVar3 = (int)lVar4;
        *(undefined1 *)(param_1 + 0x23 + lVar4) = *puVar7;
        lVar4 = lVar4 + 1;
        if (iVar1 <= iVar8) break;
        puVar7 = puVar6;
      } while (puVar6 < puVar9);
    }
  } while( true );
}


// ==== entry=00b35dd0 name=FUN_00b35dd0 size=121 ====

void FUN_00b35dd0(long param_1,undefined1 *param_2,undefined1 *param_3,undefined8 *param_4)

{
  int iVar1;
  int iVar2;
  long lVar3;
  undefined1 *puVar4;
  int iVar5;
  
  iVar2 = *(int *)(param_1 + 0x20);
  do {
    do {
      if (((param_3 <= param_2) || (0x17 < iVar2)) ||
         (iVar1 = (*(code *)*param_4)(param_2), 0x18 < iVar1 + iVar2)) {
        *(int *)(param_1 + 0x20) = iVar2;
        return;
      }
    } while (iVar1 < 1);
    iVar5 = 0;
    lVar3 = (long)(iVar2 + 1);
    puVar4 = param_2;
    do {
      param_2 = puVar4 + 1;
      iVar5 = iVar5 + 1;
      iVar2 = (int)lVar3;
      *(undefined1 *)(param_1 + 0x23 + lVar3) = *puVar4;
      lVar3 = lVar3 + 1;
      if (iVar1 <= iVar5) break;
      puVar4 = param_2;
    } while (param_2 < param_3);
  } while( true );
}


// ==== entry=00b35e50 name=FUN_00b35e50 size=391 ====

void FUN_00b35e50(long *param_1,long *param_2,undefined8 *param_3)

{
  char *pcVar1;
  char *pcVar2;
  int iVar3;
  uint uVar4;
  long lVar5;
  long lVar6;
  int iVar7;
  
  if (((((int)param_2[4] == 0) || ((int)param_1[4] == 0)) || (*param_1 != *param_2)) ||
     (param_1[1] != param_2[1])) {
    *param_1 = 0;
    param_1[1] = 0;
    param_1[2] = 0;
    param_1[3] = -0x100000000;
    *(undefined4 *)(param_1 + 4) = 0;
    *(undefined1 *)((long)param_1 + 0x24) = 0;
    return;
  }
  if ((int)param_1[4] < 1) {
    iVar7 = 0;
LAB_00b35fa8:
    if (((int)param_2[3] == 0) || (iVar7 < (int)param_2[4])) goto LAB_00b35f64;
LAB_00b35fb8:
    if (iVar7 < (int)param_1[4]) goto LAB_00b35f64;
    iVar3 = (int)param_1[3];
  }
  else {
    if ((int)param_2[4] < 1) {
      iVar7 = 0;
LAB_00b35fd2:
      if ((int)param_2[3] != 0) goto LAB_00b35fb8;
    }
    else if (*(char *)((long)param_1 + 0x24) == *(char *)((long)param_2 + 0x24)) {
      iVar7 = 0;
      lVar6 = 0;
      do {
        iVar3 = (**(code **)*param_3)((long)param_1 + lVar6 + 0x24);
        if (1 < iVar3) {
          if (*(char *)((long)param_2 + (long)(iVar7 + 1) + 0x24) !=
              *(char *)((long)param_1 + (long)(iVar7 + 1) + 0x24)) goto LAB_00b35fa8;
          lVar5 = lVar6 + 0x26;
          while ((ulong)(iVar3 - 2) + lVar6 + 0x26 != lVar5) {
            pcVar2 = (char *)((long)param_1 + lVar5);
            pcVar1 = (char *)((long)param_2 + lVar5);
            lVar5 = lVar5 + 1;
            if (*pcVar2 != *pcVar1) goto LAB_00b35fa8;
          }
        }
        iVar7 = iVar7 + iVar3;
        if ((int)param_1[4] <= iVar7) goto LAB_00b35fa8;
        if ((int)param_2[4] <= iVar7) goto LAB_00b35fd2;
        lVar6 = (long)iVar7;
      } while (*(char *)((long)param_1 + lVar6 + 0x24) == *(char *)((long)param_2 + lVar6 + 0x24));
    }
    else {
      iVar7 = 0;
    }
LAB_00b35f64:
    *(undefined4 *)(param_1 + 3) = 0;
    iVar3 = 0;
  }
  uVar4 = *(uint *)((long)param_2 + 0x1c);
  *(int *)(param_1 + 4) = iVar7;
  if (-1 < (int)*(uint *)((long)param_1 + 0x1c)) {
    if ((int)uVar4 < 0) goto LAB_00b35f86;
    uVar4 = uVar4 | *(uint *)((long)param_1 + 0x1c);
  }
  *(uint *)((long)param_1 + 0x1c) = uVar4;
LAB_00b35f86:
  uVar4 = *(uint *)((long)param_2 + 0x14);
  *(uint *)(param_1 + 2) = *(uint *)(param_1 + 2) & *(uint *)(param_2 + 2);
  if (iVar3 == 0) {
    *(undefined4 *)((long)param_1 + 0x14) = 0;
  }
  else {
    *(uint *)((long)param_1 + 0x14) = *(uint *)((long)param_1 + 0x14) & uVar4;
  }
  return;
}


// ==== entry=00b35ff0 name=FUN_00b35ff0 size=4196 ====

int FUN_00b35ff0(int *param_1,ulong *param_2,ulong *param_3)

{
  byte *pbVar1;
  undefined8 uVar2;
  undefined1 auVar3 [16];
  undefined1 auVar4 [16];
  undefined1 auVar5 [16];
  uint uVar6;
  int iVar7;
  int iVar8;
  long lVar9;
  bool bVar10;
  uint uVar11;
  ulong uVar12;
  ulong uVar13;
  int iVar14;
  ulong *puVar15;
  ulong *puVar16;
  ulong uVar17;
  ulong *puVar18;
  ulong uVar19;
  int *piVar20;
  long lVar21;
  undefined4 uVar22;
  ulong *puVar23;
  byte bVar24;
  ulong local_278;
  ulong local_270;
  ulong local_268;
  ulong uStack_260;
  ulong local_258;
  ulong uStack_250;
  ulong local_248;
  ulong local_238;
  ulong local_230;
  uint local_228;
  uint uStack_224;
  undefined1 local_220 [8];
  ulong uStack_218;
  undefined8 local_210;
  ulong uStack_208;
  int local_200;
  uint uStack_1fc;
  ulong uStack_1f8;
  ulong local_1f0;
  ulong uStack_1e8;
  ulong local_1e0;
  ulong uStack_1d8;
  ulong local_1d0;
  ulong uStack_1c8;
  int local_1c0;
  undefined4 uStack_1bc;
  ulong uStack_1b8;
  ulong local_1b0;
  ulong uStack_1a8;
  ulong local_1a0;
  ulong uStack_198;
  ulong local_190;
  ulong uStack_188;
  int local_180;
  undefined4 uStack_17c;
  ulong uStack_178;
  ulong local_170;
  ulong uStack_168;
  ulong local_160;
  ulong local_158;
  uint local_150;
  undefined4 uStack_14c;
  int local_148;
  char local_144 [276];
  
  bVar24 = 0;
  puVar23 = param_2 + 0x1b;
  *param_2 = 0;
  param_2[1] = 0;
  param_2[3] = 0;
  param_2[4] = 0;
  *(undefined1 *)((long)param_2 + 0x3c) = 0;
  param_2[0xb] = 0;
  param_2[0xc] = 0;
  *(undefined1 *)((long)param_2 + 0x7c) = 0;
  param_2[0x13] = 0;
  param_2[0x14] = 0;
  *(undefined1 *)((long)param_2 + 0xbc) = 0;
  param_2[6] = 0xffffffff00000000;
  param_2[0xe] = 0xffffffff00000000;
  param_2[0x16] = 0xffffffff00000000;
  param_2[2] = 0;
  param_2[5] = 0;
  *(undefined4 *)(param_2 + 7) = 0;
  param_2[0xd] = 0;
  *(undefined4 *)(param_2 + 0xf) = 0;
  param_2[0x15] = 0;
  *(undefined4 *)(param_2 + 0x17) = 0;
  puVar15 = &DAT_00d43720;
  puVar16 = puVar23;
  for (lVar9 = 0x24; lVar9 != 0; lVar9 = lVar9 + -1) {
    *puVar16 = *puVar15;
    puVar15 = puVar15 + 1;
    puVar16 = puVar16 + 1;
  }
  uVar19 = param_3[1];
  param_2[3] = *param_3;
  param_2[4] = uVar19;
  uVar19 = param_3[1];
  param_2[0x13] = *param_3;
  param_2[0x14] = uVar19;
  uVar19 = param_3[1];
  param_2[0x1b] = *param_3;
  param_2[0x1c] = uVar19;
  iVar7 = *param_1;
  switch(iVar7) {
  case 0:
    uVar19 = *(long *)(param_1 + 4) - *(long *)(param_1 + 2);
    if ((param_1[6] & 2U) == 0) {
      FUN_00b35dd0(param_2 + 3);
      *(undefined4 *)((long)param_2 + 0x34) = 0;
      if (uVar19 != 0) {
        bVar24 = **(byte **)(param_1 + 2);
        uVar12 = (ulong)bVar24;
        if (*(char *)((long)param_2 + uVar12 + 0xf4) == '\0') {
          uVar17 = param_3[2];
          iVar8 = 4;
          *(undefined1 *)((long)param_2 + uVar12 + 0xf4) = 1;
          if ((bVar24 < 0x80) && ((bVar24 != 0 || (iVar8 = 0x14, *(int *)(uVar17 + 0x1c) < 2)))) {
            iVar8 = (int)(short)(&DAT_00d43540)[uVar12];
          }
          *(int *)(param_2 + 0x1e) = (int)param_2[0x1e] + iVar8;
        }
      }
      *param_2 = uVar19;
      param_2[1] = uVar19;
    }
    else {
      if ((param_1[6] & 4U) == 0) {
        FUN_00b35dd0(param_2 + 3);
        *(undefined4 *)((long)param_2 + 0x34) = 1;
        uVar12 = 0;
        if (uVar19 != 0) {
          pbVar1 = *(byte **)(param_1 + 2);
          uVar6 = *(uint *)((long)param_3 + 0x1c);
          uVar2 = *(undefined8 *)(param_1 + 4);
          uVar17 = param_3[2];
          bVar24 = *pbVar1;
          uVar12 = (ulong)bVar24;
          if (*(char *)((long)param_2 + uVar12 + 0xf4) == '\0') {
            *(undefined1 *)((long)param_2 + uVar12 + 0xf4) = 1;
            iVar8 = 4;
            if ((bVar24 < 0x80) && ((bVar24 != 0 || (iVar8 = 0x14, *(int *)(uVar17 + 0x1c) < 2)))) {
              iVar8 = (int)(short)(&DAT_00d43540)[uVar12];
            }
            *(int *)(param_2 + 0x1e) = (int)param_2[0x1e] + iVar8;
          }
          iVar8 = (**(code **)(uVar17 + 0x68))(uVar6 & 0xbfffffff,pbVar1,uVar2,&local_238);
          if (iVar8 < 0) {
            return iVar8;
          }
          uVar12 = uVar19;
          if (iVar8 != 0) {
            puVar23 = &local_230;
            do {
              (**(code **)(uVar17 + 0x48))((int)*puVar23,&local_268);
              uVar13 = local_268 & 0xff;
              if (*(char *)((long)param_2 + uVar13 + 0xf4) == '\0') {
                *(undefined1 *)((long)param_2 + uVar13 + 0xf4) = 1;
                iVar14 = 4;
                if (((byte)local_268 < 0x80) &&
                   (((byte)local_268 != 0 || (iVar14 = 0x14, *(int *)(uVar17 + 0x1c) < 2)))) {
                  iVar14 = (int)(short)(&DAT_00d43540)[uVar13];
                }
                *(int *)(param_2 + 0x1e) = (int)param_2[0x1e] + iVar14;
              }
              puVar23 = (ulong *)((long)puVar23 + 0x14);
            } while ((ulong *)(local_220 + (ulong)(iVar8 - 1) * 0x14 + 4) != puVar23);
          }
        }
      }
      else {
        iVar8 = FUN_00b43250(param_3[2]);
        uVar12 = (long)(iVar8 * *(int *)(param_3[2] + 0x18));
      }
      *param_2 = uVar19;
      param_2[1] = uVar12;
    }
    if ((long)(int)param_2[7] == uVar19) {
      *(undefined4 *)(param_2 + 6) = 1;
    }
    break;
  case 1:
    if ((*(long *)(param_1 + 10) == 0) && ((*(byte *)(param_1 + 1) & 1) == 0)) {
      uVar19 = 0;
      do {
        if (((param_1[(long)((int)uVar19 >> 5) + 2] & 1 << ((byte)uVar19 & 0x1f)) != 0) &&
           (*(char *)((long)param_2 + uVar19 + 0xf4) == '\0')) {
          uVar12 = param_3[2];
          iVar7 = 4;
          *(undefined1 *)((long)param_2 + uVar19 + 0xf4) = 1;
          if (((uVar19 & 0x80) == 0) &&
             ((uVar19 != 0 || (iVar7 = 0x14, *(int *)(uVar12 + 0x1c) < 2)))) {
            iVar7 = (int)(short)(&DAT_00d43540)[uVar19];
          }
          *(int *)(param_2 + 0x1e) = (int)param_2[0x1e] + iVar7;
        }
        uVar19 = uVar19 + 1;
      } while (uVar19 != 0x100);
      *param_2 = 1;
      param_2[1] = 1;
      return 0;
    }
  case 3:
    iVar7 = 0;
    iVar8 = *(int *)(param_3[2] + 0x1c);
    param_2[1] = (long)*(int *)(param_3[2] + 0x18);
    *param_2 = (long)iVar8;
    break;
  case 2:
    uVar19 = param_3[2];
    iVar8 = *(int *)(uVar19 + 0x18);
    if (iVar8 == 1) {
      uVar6 = -(uint)(param_1[3] == 0) & 0x80;
      if (param_1[1] == 0xc) {
        if (param_1[2] == 0) {
          uVar12 = 0;
          while( true ) {
            iVar7 = (**(code **)(uVar19 + 0x78))(uVar12 & 0xffffffff,0xc);
            if ((iVar7 != 0) && (*(char *)((long)param_2 + uVar12 + 0xf4) == '\0')) {
              uVar19 = param_3[2];
              iVar7 = 4;
              *(undefined1 *)((long)param_2 + uVar12 + 0xf4) = 1;
              if (((uVar12 & 0x80) == 0) &&
                 ((uVar12 != 0 || (iVar7 = 0x14, *(int *)(uVar19 + 0x1c) < 2)))) {
                iVar7 = (int)(short)(&DAT_00d43540)[uVar12];
              }
              *(int *)(param_2 + 0x1e) = (int)param_2[0x1e] + iVar7;
            }
            if (uVar6 + 0x7f == uVar12) break;
            uVar19 = param_3[2];
            uVar12 = uVar12 + 1;
          }
        }
        else {
          uVar12 = 0;
          while( true ) {
            iVar7 = (**(code **)(uVar19 + 0x78))(uVar12 & 0xffffffff,0xc);
            if ((((int)(uVar6 + 0x80) <= (int)uVar12) || (iVar7 == 0)) &&
               (*(char *)((long)param_2 + uVar12 + 0xf4) == '\0')) {
              uVar19 = param_3[2];
              iVar7 = 4;
              *(undefined1 *)((long)param_2 + uVar12 + 0xf4) = 1;
              if (((uVar12 & 0x80) == 0) &&
                 ((uVar12 != 0 || (iVar7 = 0x14, *(int *)(uVar19 + 0x1c) < 2)))) {
                iVar7 = (int)(short)(&DAT_00d43540)[uVar12];
              }
              *(int *)(param_2 + 0x1e) = (int)param_2[0x1e] + iVar7;
            }
            uVar12 = uVar12 + 1;
            if (uVar12 == 0x100) break;
            uVar19 = param_3[2];
          }
        }
      }
      uVar19 = 1;
    }
    else {
      uVar19 = (ulong)*(int *)(uVar19 + 0x1c);
    }
    *param_2 = uVar19;
    iVar7 = 0;
    param_2[1] = (long)iVar8;
    break;
  case 4:
    lVar9 = *(long *)(param_3[4] + 0xb0);
    if (lVar9 == 0) {
      lVar9 = param_3[4] + 0x70;
    }
    if ((*(byte *)(param_1 + 1) & 0x80) == 0) {
      piVar20 = *(int **)(param_1 + 10);
      if (*(int **)(param_1 + 10) == (int *)0x0) {
        piVar20 = param_1 + 3;
      }
      iVar7 = FUN_00b33d30(*(undefined8 *)(lVar9 + (long)*piVar20 * 8),&local_278);
      if (iVar7 != 0) {
        return iVar7;
      }
      iVar7 = FUN_00b34000(*(undefined8 *)(lVar9 + (long)*piVar20 * 8),&local_270,param_3[4]);
      if (iVar7 != 0) {
        return iVar7;
      }
      if (1 < param_1[2]) {
        lVar21 = 1;
        do {
          iVar7 = FUN_00b33d30(*(undefined8 *)(lVar9 + (long)piVar20[lVar21] * 8),&local_268,
                               param_3[4]);
          if (iVar7 != 0) {
            return iVar7;
          }
          iVar7 = FUN_00b34000(*(undefined8 *)(lVar9 + (long)piVar20[lVar21] * 8),&local_238,
                               param_3[4]);
          if (iVar7 != 0) {
            return iVar7;
          }
          if (local_268 < local_278) {
            local_278 = local_268;
          }
          if (local_270 < local_238) {
            local_270 = local_238;
          }
          lVar21 = lVar21 + 1;
        } while ((int)lVar21 < param_1[2]);
      }
      *param_2 = local_278;
      param_2[1] = local_270;
      return 0;
    }
    goto LAB_00b3672b;
  case 5:
    iVar7 = FUN_00b35ff0(*(undefined8 *)(param_1 + 2),&local_238,param_3);
    if (iVar7 != 0) {
      return iVar7;
    }
    iVar7 = param_1[5];
    uVar19 = (ulong)iVar7;
    if (iVar7 == -1) {
      if (((param_3[1] == 0) && (**(int **)(param_1 + 2) == 3)) && (param_1[6] != 0)) {
        if ((param_3[3] & 4) == 0) {
          *(uint *)(param_2 + 2) = (uint)param_2[2] | 0x4000;
          iVar8 = param_1[4];
          uVar19 = (ulong)param_1[5];
        }
        else {
          *(uint *)(param_2 + 2) = (uint)param_2[2] | 0x8000;
          iVar8 = param_1[4];
          uVar19 = (ulong)param_1[5];
        }
LAB_00b36feb:
        uVar12 = 0;
        if (iVar8 != 0) goto LAB_00b364fa;
        goto LAB_00b36518;
      }
      iVar7 = param_1[4];
      uVar12 = 0;
      if (iVar7 != 0) {
        uVar12 = 0xffffffffffffffff;
        auVar5._8_8_ = 0;
        auVar5._0_8_ = (long)iVar7;
        if (local_238 < SUB168((ZEXT816(0) << 0x40 | ZEXT816(0xffffffffffffffff)) / auVar5,0)) {
          uVar12 = (long)iVar7 * local_238;
        }
      }
LAB_00b36df9:
      uVar17 = -(ulong)(local_230 != 0);
    }
    else {
      iVar8 = param_1[4];
      if (iVar8 < 1) {
        if (iVar8 == 0) {
          uVar12 = 0;
        }
        else {
          uVar17 = (ulong)iVar8;
          uVar12 = 0xffffffffffffffff;
          if (local_238 == 0) goto LAB_00b36511;
        }
      }
      else {
        puVar23 = &local_238;
        puVar15 = param_2;
        for (lVar9 = 0x3f; lVar9 != 0; lVar9 = lVar9 + -1) {
          *puVar15 = *puVar23;
          puVar23 = puVar23 + (ulong)bVar24 * -2 + 1;
          puVar15 = puVar15 + (ulong)bVar24 * -2 + 1;
        }
        if (((local_200 < 1) || ((int)uStack_208 == 0)) || (iVar8 == 1)) {
LAB_00b36e10:
          if (iVar7 != iVar8) {
LAB_00b364d7:
            *(undefined4 *)(param_2 + 6) = 0;
            *(undefined4 *)(param_2 + 0xe) = 0;
          }
          if (iVar8 < 2) goto LAB_00b36feb;
        }
        else {
          if ((int)param_2[7] < 0x18) {
            iVar14 = 2;
            do {
              iVar14 = iVar14 + 1;
              FUN_00b35ce0(param_2 + 3,local_220,param_3[2]);
              iVar8 = param_1[4];
              if (iVar8 < iVar14) break;
            } while ((int)param_2[7] < 0x18);
            iVar7 = param_1[5];
          }
          else {
            iVar14 = 2;
          }
          uVar19 = (ulong)iVar7;
          if (iVar8 <= iVar14) goto LAB_00b36e10;
          *(undefined4 *)(param_2 + 6) = 0;
          if (iVar7 != iVar8) goto LAB_00b364d7;
        }
        *(undefined4 *)(param_2 + 0xe) = 0;
LAB_00b364fa:
        uVar12 = 0xffffffffffffffff;
        uVar17 = (ulong)iVar8;
        auVar3._8_8_ = 0;
        auVar3._0_8_ = uVar17;
        if (local_238 < SUB168((ZEXT416(0) << 0x40 | ZEXT816(0xffffffffffffffff)) / auVar3,0)) {
LAB_00b36511:
          uVar12 = uVar17 * local_238;
        }
LAB_00b36518:
        if ((int)uVar19 == -1) goto LAB_00b36df9;
      }
      uVar17 = 0;
      if (((int)uVar19 != 0) &&
         (auVar4._8_8_ = 0, auVar4._0_8_ = uVar19, uVar17 = 0xffffffffffffffff,
         local_230 < SUB168((ZEXT816(0) << 0x40 | ZEXT816(0xffffffffffffffff)) / auVar4,0))) {
        uVar17 = local_230 * uVar19;
      }
    }
    *param_2 = uVar12;
    param_2[1] = uVar17;
    iVar7 = 0;
    break;
  case 6:
    iVar7 = param_1[2];
    if (iVar7 == 2) {
      uVar22 = (undefined4)param_3[3];
      lVar9 = *(long *)(param_1 + 6);
      *(int *)(param_3 + 3) = param_1[4];
LAB_00b36ca6:
      iVar7 = FUN_00b35ff0(lVar9,param_2,param_3);
      *(undefined4 *)(param_3 + 3) = uVar22;
      return iVar7;
    }
    if (iVar7 < 3) {
      if (iVar7 == 1) {
        iVar7 = param_1[0xf];
        param_1[0xf] = iVar7 + 1;
        if (5 < iVar7 + 1) {
          uVar19 = 0;
          if ((param_1[1] & 1U) != 0) {
            uVar19 = *(ulong *)(param_1 + 10);
          }
          uVar12 = 0xffffffffffffffff;
          if ((param_1[1] & 2U) != 0) {
            uVar12 = *(ulong *)(param_1 + 0xc);
          }
          *param_2 = uVar19;
          param_2[1] = uVar12;
          return 0;
        }
        iVar7 = FUN_00b35ff0(*(undefined8 *)(param_1 + 6),param_2,param_3);
        if ((((uint)param_2[2] & 0xc000) == 0) && ((*(uint *)((long)param_2 + 0x14) & 0xc000) == 0))
        {
          return iVar7;
        }
        bVar10 = (bool)((byte)*(uint *)(param_3[4] + 0x24) & 1);
        if (param_1[3] < 0x20) {
          bVar10 = (1 << ((byte)param_1[3] & 0x1f) & *(uint *)(param_3[4] + 0x24)) != 0;
        }
        if (bVar10 == false) {
          return iVar7;
        }
        *(uint *)(param_2 + 2) = (uint)param_2[2] & 0xffff3fff;
        return iVar7;
      }
    }
    else if ((iVar7 == 4) || (iVar7 == 8)) {
      iVar7 = FUN_00b35ff0(*(undefined8 *)(param_1 + 6),param_2,param_3);
      return iVar7;
    }
    goto LAB_00b36932;
  case 7:
    iVar7 = param_1[1];
    if (iVar7 != 8) {
      if (iVar7 < 9) {
        if (iVar7 < 1) {
          return 0;
        }
        if ((2 < iVar7) && (iVar7 != 4)) {
          return 0;
        }
      }
      else if (iVar7 != 0x20) {
        if (iVar7 < 0x21) {
          if (iVar7 != 0x10) goto LAB_00b36932;
        }
        else {
          if (iVar7 == 0x400) {
            iVar7 = FUN_00b35ff0(*(undefined8 *)(param_1 + 2),&local_238,param_3);
            if (iVar7 != 0) {
              return iVar7;
            }
            if (local_200 < 1) {
              if (0 < local_1c0) {
                param_2[0x13] = local_1e0;
                param_2[0x14] = uStack_1d8;
                param_2[0x15] = local_1d0;
                param_2[0x16] = uStack_1c8;
                param_2[0x17] = CONCAT44(uStack_1bc,local_1c0);
                param_2[0x18] = uStack_1b8;
                param_2[0x19] = local_1b0;
                param_2[0x1a] = uStack_1a8;
              }
            }
            else {
              param_2[0x15] = local_210;
              param_2[0x16] = uStack_208;
              param_2[0x13] = (ulong)local_220;
              param_2[0x14] = uStack_218;
              param_2[0x19] = local_1f0;
              param_2[0x1a] = uStack_1e8;
              param_2[0x17] = CONCAT44(uStack_1fc,local_200);
              param_2[0x18] = uStack_1f8;
            }
            *(undefined4 *)(param_2 + 0x16) = 0;
            if (local_148 < 1) {
              return 0;
            }
            puVar15 = &local_160;
            for (lVar9 = 0x24; lVar9 != 0; lVar9 = lVar9 + -1) {
              *puVar23 = *puVar15;
              puVar15 = puVar15 + (ulong)bVar24 * -2 + 1;
              puVar23 = puVar23 + (ulong)bVar24 * -2 + 1;
            }
            return 0;
          }
          if (iVar7 != 0x1000) {
            return 0;
          }
        }
      }
    }
    if ((((iVar7 - 8U & 0xfffffff7) == 0) || ((iVar7 - 0x400U & 0xfffffbff) == 0)) ||
       (iVar7 == 0x20)) {
      *(int *)((long)param_2 + 0x14) = iVar7;
      return 0;
    }
    *(int *)(param_2 + 2) = iVar7;
LAB_00b36932:
    iVar7 = 0;
    break;
  case 8:
    local_248 = param_3[4];
    local_268 = *param_3;
    uStack_260 = param_3[1];
    local_258 = param_3[2];
    uStack_250 = param_3[3];
    do {
      iVar7 = FUN_00b35ff0(*(undefined8 *)(param_1 + 2),&local_238,&local_268);
      if (iVar7 != 0) {
        return iVar7;
      }
      FUN_00b35c60(&local_268,&uStack_260,local_238,local_230);
      uVar19 = param_2[1];
      uVar12 = param_3[2];
      uVar6 = (uint)param_2[2];
      if (uVar19 == 0) {
        uVar6 = uVar6 | local_228;
      }
      uVar11 = uStack_224;
      if (local_230 == 0) {
        uVar11 = uStack_224 | *(uint *)((long)param_2 + 0x14);
      }
      uVar17 = param_2[0xe];
      uVar13 = param_2[6];
      *(uint *)(param_2 + 2) = uVar6;
      *(uint *)((long)param_2 + 0x14) = uVar11;
      if (local_200 < 1) {
        if ((local_148 < 1) || (uVar19 != 0)) {
          if (local_230 != 0) goto LAB_00b36802;
        }
        else {
          if (local_158 == 0) goto LAB_00b36a4b;
LAB_00b36a52:
          if (local_230 != 0) goto LAB_00b36802;
LAB_00b36810:
          if (0 < local_200) goto LAB_00b36814;
        }
      }
      else {
        if (uVar19 == 0) {
          local_210._0_4_ = (uint)local_210 | uVar6;
          if (local_230 != 0) {
            if ((0 < local_148) && (local_158 == 0)) {
LAB_00b36a4b:
              local_150 = local_150 | uVar6;
              goto LAB_00b36a52;
            }
            goto LAB_00b36802;
          }
          local_210 = CONCAT44(uVar11 | local_210._4_4_,(uint)local_210);
          if (0 < local_148) {
            if (local_158 == 0) goto LAB_00b36a4b;
            goto LAB_00b36810;
          }
        }
        else if (local_230 != 0) {
LAB_00b36802:
          *(undefined4 *)(param_2 + 0xe) = 0;
          *(undefined4 *)(param_2 + 6) = 0;
          goto LAB_00b36810;
        }
LAB_00b36814:
        if ((int)uVar13 == 0) {
          if ((int)uVar17 == 0) goto LAB_00b36826;
          puVar15 = param_2 + 0xb;
        }
        else {
          puVar15 = param_2 + 3;
        }
        FUN_00b35ce0(puVar15,local_220,uVar12);
        uStack_1fc = uStack_1fc & 0xffffff00;
        local_220 = (undefined1  [8])0x0;
        uStack_218 = 0;
        local_210 = 0;
        uStack_208 = 0xffffffff00000000;
        local_200 = 0;
      }
LAB_00b36826:
      puVar15 = param_2 + 0xb;
      FUN_00b35b60(uVar12,puVar15,local_220);
      FUN_00b35b60(uVar12,puVar15,&local_1e0);
      if ((int)param_2[0x17] < 1) {
        if (0 < local_180) {
          param_2[0x13] = local_1a0;
          param_2[0x14] = uStack_198;
          param_2[0x15] = local_190;
          param_2[0x16] = uStack_188;
          param_2[0x17] = CONCAT44(uStack_17c,local_180);
          param_2[0x18] = uStack_178;
          param_2[0x19] = local_170;
          param_2[0x1a] = uStack_168;
        }
      }
      else if (local_230 != 0) {
        if ((int)local_230 < (int)param_2[0x17]) {
          *(int *)(param_2 + 0x17) = (int)local_230;
        }
        if (param_2[0x14] == 0) {
          FUN_00b35b60(uVar12,param_2 + 3,param_2 + 0x13);
        }
        else {
          FUN_00b35b60(uVar12,param_2 + 0xb,param_2 + 0x13);
        }
      }
      uVar19 = local_230;
      if ((local_148 != 0) &&
         (((int)param_2[0x1e] == 0 ||
          ((0 < (int)(0x8000 / (long)local_148) &&
           ((uVar12 = 0x8000 / (long)(int)param_2[0x1e], (int)uVar12 < 1 ||
            (iVar7 = FUN_00b35ad0(puVar23,&local_160,uVar12 & 0xffffffff,
                                  0x8000 / (long)local_148 & 0xffffffff), 0 < iVar7)))))))) {
        puVar15 = &local_160;
        puVar16 = puVar23;
        for (lVar9 = 0x24; lVar9 != 0; lVar9 = lVar9 + -1) {
          *puVar16 = *puVar15;
          puVar15 = puVar15 + (ulong)bVar24 * -2 + 1;
          puVar16 = puVar16 + (ulong)bVar24 * -2 + 1;
        }
      }
      FUN_00b35c60(param_2,param_2 + 1,local_238,uVar19);
      param_1 = *(int **)(param_1 + 4);
      iVar7 = 0;
    } while (param_1 != (int *)0x0);
    break;
  case 9:
    puVar15 = param_3 + 2;
    piVar20 = param_1;
    do {
      iVar7 = FUN_00b35ff0(*(undefined8 *)(piVar20 + 2),&local_238,param_3);
      if (iVar7 != 0) {
        return iVar7;
      }
      if (piVar20 == param_1) {
        puVar16 = &local_238;
        puVar18 = param_2;
        for (lVar9 = 0x3f; lVar9 != 0; lVar9 = lVar9 + -1) {
          *puVar18 = *puVar16;
          puVar16 = puVar16 + (ulong)bVar24 * -2 + 1;
          puVar18 = puVar18 + (ulong)bVar24 * -2 + 1;
        }
      }
      else {
        param_2[2] = param_2[2] & CONCAT44(uStack_224,local_228);
        FUN_00b35e50(param_2 + 3,local_220,puVar15);
        FUN_00b35e50(param_2 + 0xb,&local_1e0,puVar15);
        FUN_00b35e50(param_2 + 0x13,&local_1a0,puVar15);
        if ((int)param_2[0x1e] != 0) {
          if ((local_148 == 0) || (param_2[0x1c] < local_160)) {
            puVar16 = &DAT_00d43720;
            puVar18 = puVar23;
            for (lVar9 = 0x24; lVar9 != 0; lVar9 = lVar9 + -1) {
              *puVar18 = *puVar16;
              puVar16 = puVar16 + (ulong)bVar24 * -2 + 1;
              puVar18 = puVar18 + (ulong)bVar24 * -2 + 1;
            }
          }
          else {
            uVar19 = param_3[2];
            if (local_160 < param_2[0x1b]) {
              param_2[0x1b] = local_160;
            }
            if (param_2[0x1c] < local_158) {
              param_2[0x1c] = local_158;
            }
            iVar7 = 0;
            uVar12 = 0;
            do {
              if (local_144[uVar12] == '\0') {
                if (*(char *)((long)param_2 + uVar12 + 0xf4) != '\0') goto LAB_00b36273;
              }
              else {
                *(undefined1 *)((long)param_2 + uVar12 + 0xf4) = 1;
LAB_00b36273:
                iVar8 = 4;
                if ((uVar12 < 0x80) &&
                   (((int)uVar12 != 0 || (iVar8 = 0x14, *(int *)(uVar19 + 0x1c) < 2)))) {
                  iVar8 = (int)(short)(&DAT_00d43540)[uVar12];
                }
                iVar7 = iVar7 + iVar8;
              }
              uVar12 = uVar12 + 1;
            } while (uVar12 != 0x100);
            param_2[0x1d] = param_2[0x1d] & CONCAT44(uStack_14c,local_150);
            *(int *)(param_2 + 0x1e) = iVar7;
          }
        }
        if (local_238 < *param_2) {
          *param_2 = local_238;
        }
        if (param_2[1] < local_230) {
          param_2[1] = local_230;
        }
      }
      piVar20 = *(int **)(piVar20 + 4);
      iVar7 = 0;
    } while (piVar20 != (int *)0x0);
    break;
  case 10:
    if ((*(byte *)(param_1 + 1) & 0x80) == 0) {
      lVar9 = *(long *)(param_1 + 8);
      uVar22 = (undefined4)param_3[3];
      *(undefined4 *)(param_3 + 3) = *(undefined4 *)(lVar9 + 0x10);
      goto LAB_00b36ca6;
    }
LAB_00b3672b:
    param_2[1] = 0xffffffffffffffff;
    iVar7 = 0;
    break;
  default:
    iVar7 = -6;
  }
  return iVar7;
}


// ==== entry=00b37120 name=FUN_00b37120 size=1041 ====

undefined8
FUN_00b37120(long param_1,long param_2,undefined8 *param_3,undefined4 *param_4,char *param_5,
            long *param_6,int param_7)

{
  int *piVar1;
  byte bVar2;
  long lVar3;
  int iVar4;
  int iVar5;
  ulong uVar6;
  char *pcVar7;
  int *piVar8;
  byte *pbVar9;
  byte *pbVar10;
  char cVar11;
  long lVar12;
  byte *pbVar13;
  int iVar14;
  undefined4 *puVar15;
  byte *pbVar16;
  char local_288;
  ulong local_270;
  int local_250;
  byte local_238 [18];
  byte local_226 [222];
  int local_148;
  int local_144;
  undefined4 local_140 [68];
  
  uVar6 = param_2 - param_1;
  if (uVar6 < 0x100) {
    pcVar7 = param_5;
    do {
      *pcVar7 = (char)uVar6 + '\x01';
      pcVar7 = pcVar7 + 1;
    } while (param_5 + 0x100 != pcVar7);
    local_250 = 0;
    local_270 = 0;
    if (uVar6 != 0) {
      do {
        if (param_7 != 0) {
          local_250 = (*(code *)param_3[0xd])(*param_4,param_1 + local_270,param_2,&local_148);
        }
        iVar4 = (*(code *)*param_3)(param_1 + local_270);
        if (0 < local_250) {
          if ((local_144 != 1) || (iVar4 != local_148)) {
            return 1;
          }
          pbVar16 = local_238;
          pbVar13 = pbVar16 + (ulong)(local_250 - 1) * 0x12;
          puVar15 = local_140;
          while( true ) {
            iVar5 = (*(code *)param_3[9])(*puVar15,pbVar16);
            if (iVar4 != iVar5) {
              return 1;
            }
            if (pbVar13 == pbVar16) break;
            if (puVar15[4] != 1) {
              return 1;
            }
            pbVar16 = pbVar16 + 0x12;
            piVar8 = puVar15 + 3;
            puVar15 = puVar15 + 5;
            if (iVar4 != *piVar8) {
              return 1;
            }
          }
        }
        if (0 < iVar4) {
          pbVar16 = local_226 + (ulong)(local_250 - 1) * 0x12;
          pbVar13 = local_238;
          lVar12 = local_270 - (long)pbVar13;
          local_288 = (char)pbVar13;
          do {
            cVar11 = (((char)uVar6 - (char)local_270) + local_288) - (char)pbVar13;
            param_5[pbVar16[lVar12 + (ulong)(local_250 - 1) * -0x12 + param_1 + -0x12]] = cVar11;
            pbVar9 = pbVar13;
            if (0 < local_250) {
              do {
                pbVar10 = pbVar9 + 0x12;
                param_5[*pbVar9] = cVar11;
                pbVar9 = pbVar10;
              } while (pbVar16 != pbVar10);
            }
            pbVar13 = pbVar13 + 1;
            pbVar16 = pbVar16 + 1;
          } while (pbVar13 != local_238 + (ulong)(iVar4 - 1) + 1);
        }
        local_270 = local_270 + (long)iVar4;
        if (uVar6 <= local_270) {
          return 0;
        }
      } while( true );
    }
  }
  else {
    piVar8 = (int *)*param_6;
    if (piVar8 == (int *)0x0) {
      piVar8 = malloc(0x400);
      *param_6 = (long)piVar8;
      if (piVar8 == (int *)0x0) {
        return 0xfffffffb;
      }
    }
    piVar1 = piVar8 + 0x100;
    do {
      *piVar8 = (int)uVar6 + 1;
      piVar8 = piVar8 + 1;
    } while (piVar8 != piVar1);
    local_250 = 0;
    local_270 = 0;
    do {
      if (param_7 != 0) {
        local_250 = (*(code *)param_3[0xd])(*param_4,param_1 + local_270,param_2,&local_148);
      }
      iVar4 = (*(code *)*param_3)(param_1 + local_270);
      if (0 < local_250) {
        if (local_144 != 1) {
          return 1;
        }
        if (iVar4 != local_148) {
          return 1;
        }
        pbVar13 = local_238;
        pbVar16 = pbVar13 + (ulong)(local_250 - 1) * 0x12;
        puVar15 = local_140;
        while( true ) {
          iVar5 = (*(code *)param_3[9])(*puVar15,pbVar13);
          if (iVar4 != iVar5) {
            return 1;
          }
          if (pbVar13 == pbVar16) break;
          if (puVar15[4] != 1) {
            return 1;
          }
          pbVar13 = pbVar13 + 0x12;
          piVar8 = puVar15 + 3;
          puVar15 = puVar15 + 5;
          if (iVar4 != *piVar8) {
            return 1;
          }
        }
      }
      if (0 < iVar4) {
        lVar12 = *param_6;
        iVar5 = (int)uVar6 - (int)local_270;
        pbVar16 = local_226 + (ulong)(local_250 - 1) * 0x12;
        iVar14 = iVar5 - iVar4;
        lVar3 = (ulong)(local_250 - 1) * -0x12;
        do {
          *(int *)(lVar12 + (ulong)pbVar16[(local_270 - (long)local_238) + lVar3 + param_1 + -0x12]
                            * 4) = iVar5;
          pbVar13 = pbVar16 + lVar3 + -0x12;
          if (0 < local_250) {
            do {
              bVar2 = *pbVar13;
              pbVar13 = pbVar13 + 0x12;
              *(int *)(lVar12 + (ulong)bVar2 * 4) = iVar5;
            } while (pbVar13 != pbVar16);
          }
          iVar5 = iVar5 + -1;
          pbVar16 = pbVar16 + 1;
        } while (iVar5 != iVar14);
      }
      local_270 = local_270 + (long)iVar4;
    } while (local_270 < uVar6);
  }
  return 0;
}


// ==== entry=00b37540 name=FUN_00b37540 size=220 ====

undefined8 FUN_00b37540(undefined4 *param_1,undefined8 param_2,long *param_3)

{
  long lVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined8 uVar4;
  long lVar5;
  undefined4 local_1c;
  
  uVar4 = FUN_00b342f0(*(undefined8 *)(param_1 + 2),param_2,&local_1c,0);
  iVar3 = (int)uVar4;
  if (iVar3 == 0) {
    param_1[4] = local_1c;
    return uVar4;
  }
  if (iVar3 != -1) {
    if (iVar3 != -2) {
      return uVar4;
    }
    if ((*(byte *)(*param_3 + 8) & 0x40) != 0) {
      lVar5 = *(long *)(param_1 + 2);
      iVar3 = param_1[1];
      uVar4 = *(undefined8 *)(lVar5 + 8);
      FUN_00b33a40(param_1,lVar5);
      lVar1 = *(long *)(param_1 + 4);
      *(long *)(param_1 + 2) = lVar5;
      *(undefined8 *)(lVar5 + 8) = uVar4;
      for (; lVar1 != 0; lVar1 = *(long *)(lVar1 + 0x10)) {
        lVar5 = FUN_00b2ebf0(iVar3);
        if (lVar5 == 0) {
          return 0xfffffffb;
        }
        *(undefined8 *)(lVar5 + 8) = *(undefined8 *)(lVar1 + 8);
        *(long *)(lVar1 + 8) = lVar5;
      }
      if (iVar3 == 0x2000) {
        do {
          *param_1 = 8;
          puVar2 = *(undefined4 **)(param_1 + 4);
          if (puVar2 == (undefined4 *)0x0) {
            return 0;
          }
          *puVar2 = 8;
          param_1 = *(undefined4 **)(puVar2 + 4);
        } while (param_1 != (undefined4 *)0x0);
      }
      return 0;
    }
  }
  return 0xffffff86;
}


// ==== entry=00b37640 name=FUN_00b37640 size=331 ====

undefined4 FUN_00b37640(long *param_1,undefined4 *param_2,long param_3)

{
  undefined1 *puVar1;
  undefined1 uVar2;
  ulong uVar3;
  ulong uVar4;
  int iVar5;
  undefined4 uVar6;
  undefined1 *__ptr;
  undefined1 *puVar7;
  undefined1 *__ptr_00;
  undefined1 *puVar8;
  size_t __size;
  size_t sVar9;
  undefined1 *puVar10;
  ulong local_60;
  undefined1 local_58 [40];
  
  uVar3 = *(ulong *)(param_3 + 0x10);
  uVar4 = *(ulong *)(param_3 + 8);
  __size = (uVar3 - uVar4) * 2;
  __ptr = malloc(__size);
  if (__ptr == (undefined1 *)0x0) {
    return 0xfffffffb;
  }
  puVar10 = __ptr + __size;
  local_60 = uVar4;
  puVar1 = __ptr;
  do {
    do {
      if (uVar3 <= local_60) {
        uVar6 = FUN_00b2f090(param_3,__ptr,puVar1);
        free(__ptr);
        return uVar6;
      }
      iVar5 = (**(code **)(*param_1 + 0x50))(*param_2,&local_60,uVar3,local_58);
    } while (iVar5 < 1);
    puVar8 = local_58;
    __ptr_00 = __ptr;
    sVar9 = __size;
    puVar7 = puVar1;
    do {
      __ptr = __ptr_00;
      __size = sVar9;
      if (puVar10 <= puVar7) {
        __size = sVar9 * 2;
        __ptr = realloc(__ptr_00,__size);
        if (__ptr == (undefined1 *)0x0) {
          free(__ptr_00);
          return 0xfffffffb;
        }
        puVar7 = __ptr + sVar9;
        puVar10 = puVar7 + sVar9;
      }
      uVar2 = *puVar8;
      puVar8 = puVar8 + 1;
      puVar1 = puVar7 + 1;
      *puVar7 = uVar2;
      __ptr_00 = __ptr;
      sVar9 = __size;
      puVar7 = puVar1;
    } while (puVar8 != local_58 + (ulong)(iVar5 - 1) + 1);
  } while( true );
}


// ==== entry=00b377a0 name=FUN_00b377a0 size=102 ====

ulong FUN_00b377a0(long *param_1,undefined8 param_2,undefined8 param_3,long param_4)

{
  long lVar1;
  ulong uVar2;
  
  lVar1 = thunk_FUN_00b2edc0(param_2,param_3);
  if (lVar1 == 0) {
    uVar2 = 0xfffffffb;
  }
  else {
    uVar2 = FUN_00b37640(param_4 + 0x48,param_4 + 0x60,lVar1);
    if ((int)uVar2 != 0) {
      thunk_FUN_00b2d8d0(lVar1);
      return uVar2 & 0xffffffff;
    }
    *(uint *)(lVar1 + 0x18) = *(uint *)(lVar1 + 0x18) | 6;
    *param_1 = lVar1;
  }
  return uVar2;
}


// ==== entry=00b37810 name=FUN_00b37810 size=1695 ====

int FUN_00b37810(long param_1,long param_2)

{
  int iVar1;
  ulong uVar2;
  bool bVar3;
  bool bVar4;
  byte bVar5;
  int iVar6;
  int iVar7;
  int *piVar8;
  ulong uVar9;
  long lVar10;
  long lVar11;
  long lVar12;
  int iVar13;
  ulong uVar14;
  ulong uVar15;
  long local_1c8;
  long local_1c0;
  int local_1a4;
  long local_1a0;
  long local_198;
  long local_190;
  int local_180;
  undefined1 local_157 [7];
  long local_150;
  int local_148 [5];
  int local_134 [65];
  
  if ((*(uint *)(param_1 + 0x18) & 2) != 0) {
    return 0;
  }
  uVar2 = *(ulong *)(param_1 + 0x10);
  uVar15 = *(ulong *)(param_1 + 8);
  if (uVar2 <= uVar15) {
    return 0;
  }
  lVar10 = 0;
  local_1c0 = 0;
  local_1c8 = 0;
  local_190 = 0;
  bVar3 = false;
  local_180 = 1;
LAB_00b378bc:
  iVar6 = (**(code **)(*(long *)(param_2 + 0x48) + 0x68))
                    (*(undefined4 *)(param_2 + 0x60),uVar15,uVar2);
  if (iVar6 < 0) goto LAB_00b37a54;
  iVar7 = (*(code *)**(undefined8 **)(param_2 + 0x48))(uVar15);
  if (iVar6 == 0) {
    if (lVar10 == 0) {
      if ((local_1c8 == 0) && (local_1c0 != 0)) {
        local_1c8 = FUN_00b2eb60(0);
        local_190 = local_1c8;
        if (local_1c8 == 0) goto LAB_00b37a44;
        lVar10 = thunk_FUN_00b2edc0(0,0);
        if (lVar10 != 0) goto LAB_00b37bdc;
        goto LAB_00b37df0;
      }
      lVar10 = thunk_FUN_00b2edc0(0,0);
      if (lVar10 == 0) goto LAB_00b37df0;
      local_1c0 = lVar10;
      if (local_1c8 != 0) {
LAB_00b37bdc:
        lVar11 = FUN_00b2eb60(local_1c8,lVar10);
        local_1c0 = lVar10;
        if (lVar11 != 0) goto LAB_00b37889;
        iVar6 = -5;
        thunk_FUN_00b2d8d0(lVar10);
        goto LAB_00b37a54;
      }
    }
LAB_00b37889:
    iVar6 = FUN_00b2ec50(lVar10,uVar15,uVar15 + (long)iVar7);
    uVar15 = uVar15 + (long)iVar7;
    if (iVar6 != 0) goto LAB_00b37a54;
joined_r0x00b37b30:
    lVar11 = local_1c0;
    if (uVar2 <= uVar15) {
LAB_00b37b40:
      local_1c0 = lVar11;
      if (local_190 != 0) {
        local_1c0 = local_190;
      }
      local_190 = local_1c0;
      if (bVar3) {
        iVar6 = 0;
        FUN_00b33a40(param_1,local_1c0);
      }
      else {
        iVar6 = FUN_00b37640(param_2 + 0x48,param_2 + 0x60,param_1);
        if (iVar6 == 0) {
          *(uint *)(param_1 + 0x18) = *(uint *)(param_1 + 0x18) | 2;
        }
      }
LAB_00b37a54:
      thunk_FUN_00b2d8d0(local_190);
      return iVar6;
    }
    goto LAB_00b378bc;
  }
  local_180 = (iVar6 + 1) * local_180;
  if (local_180 < 9) {
    if (((local_1c8 == 0) && (local_1c0 != 0)) &&
       (local_1c8 = FUN_00b2eb60(0,local_1c0), local_190 = local_1c8, local_1c8 == 0)) {
      iVar6 = -5;
      thunk_FUN_00b2d8d0(local_1c0);
      local_190 = 0;
      goto LAB_00b37a54;
    }
    if (iVar7 == local_148[0]) {
      bVar5 = 0;
      iVar13 = 0;
      piVar8 = local_134;
      do {
        if (piVar8[-4] != 1) {
          bVar5 = 1;
        }
        iVar13 = iVar13 + 1;
        if (iVar6 <= iVar13) {
          local_1c0 = FUN_00b2eba0(0,0);
          if (local_1c0 == 0) goto LAB_00b37df0;
          bVar4 = false;
          local_198 = 0;
          local_1a0 = local_1c0;
          goto LAB_00b379aa;
        }
        iVar1 = *piVar8;
        piVar8 = piVar8 + 5;
      } while (iVar7 == iVar1);
    }
    else {
      bVar5 = 0;
    }
    local_1c0 = FUN_00b2eba0(0,0);
    if (local_1c0 != 0) {
      lVar10 = thunk_FUN_00b2c0d0(0,0);
      if (lVar10 != 0) {
        *(long *)(local_1c0 + 8) = lVar10;
        local_1a0 = FUN_00b2eba0(0,0);
        if (local_1a0 != 0) {
          *(long *)(lVar10 + 8) = local_1a0;
          bVar4 = true;
          local_198 = local_1c0;
LAB_00b379aa:
          uVar9 = (long)iVar7 + uVar15;
          lVar10 = thunk_FUN_00b2edc0(uVar15,uVar9);
          if (lVar10 != 0) {
            local_1a4 = 0;
            piVar8 = local_148;
            *(long *)(local_1a0 + 8) = lVar10;
            do {
              lVar10 = thunk_FUN_00b2edc0(0,0);
              if (lVar10 == 0) goto LAB_00b37a44;
              lVar11 = 0;
              if (0 < piVar8[1]) {
                do {
                  iVar13 = (**(code **)(*(long *)(param_2 + 0x48) + 0x48))
                                     (piVar8[lVar11 + 2],local_157);
                  if ((iVar13 < 0) ||
                     (iVar13 = FUN_00b2ec50(lVar10,local_157,local_157 + iVar13), iVar13 != 0))
                  goto LAB_00b37a3c;
                  lVar11 = lVar11 + 1;
                } while ((int)lVar11 < piVar8[1]);
              }
              lVar11 = FUN_00b2eba0(0,0);
              if (lVar11 == 0) goto LAB_00b37a3c;
              if (iVar7 == *piVar8) {
                *(long *)(lVar11 + 8) = lVar10;
                *(long *)(local_1a0 + 0x10) = lVar11;
                local_1a0 = lVar11;
              }
              else {
                uVar14 = (long)*piVar8 + uVar15;
                if (uVar14 < uVar2) {
                  iVar13 = FUN_00b377a0(&local_150,uVar14,uVar2,param_2);
                  if (iVar13 == 0) {
                    lVar12 = FUN_00b2eb60(0,lVar10);
                    if (lVar12 != 0) {
                      lVar10 = FUN_00b2eb60();
                      if (lVar10 != 0) {
                        *(long *)(lVar11 + 8) = lVar12;
                        goto LAB_00b37aa9;
                      }
                      thunk_FUN_00b2d8d0(lVar11);
                      thunk_FUN_00b2d8d0(lVar12);
                      thunk_FUN_00b2d8d0(local_150);
                      goto LAB_00b37a44;
                    }
                    thunk_FUN_00b2d8d0(lVar11);
                    thunk_FUN_00b2d8d0(local_150);
                  }
                  else {
                    thunk_FUN_00b2d8d0(lVar11);
                  }
LAB_00b37a3c:
                  thunk_FUN_00b2d8d0(lVar10);
                  goto LAB_00b37a44;
                }
                *(long *)(lVar11 + 8) = lVar10;
LAB_00b37aa9:
                *(long *)(local_198 + 0x10) = lVar11;
                local_198 = lVar11;
              }
              local_1a4 = local_1a4 + 1;
              piVar8 = piVar8 + 5;
            } while (local_1a4 < iVar6);
            uVar15 = uVar9;
            if ((bool)(bVar5 & (bVar4 ^ 1U))) {
              bVar3 = true;
            }
            else if (bVar4) {
              if (local_1c8 == 0) {
                local_190 = local_1c0;
              }
              else {
                lVar10 = FUN_00b2eb60(local_1c8,local_1c0);
                if (lVar10 == 0) goto LAB_00b37a44;
              }
              bVar3 = true;
              lVar10 = 0;
              local_1c8 = *(long *)(local_1c0 + 8);
              goto joined_r0x00b37b30;
            }
            if ((local_1c8 == 0) || (lVar10 = FUN_00b2eb60(local_1c8,local_1c0), lVar10 != 0)) {
              lVar10 = 0;
              goto joined_r0x00b37b30;
            }
          }
        }
      }
LAB_00b37a44:
      iVar6 = -5;
      thunk_FUN_00b2d8d0(local_1c0);
      goto LAB_00b37a54;
    }
  }
  else {
    lVar11 = local_1c0;
    if (uVar2 <= uVar15) goto LAB_00b37b40;
    iVar6 = FUN_00b377a0(&local_150,uVar15,uVar2,param_2);
    if (iVar6 == 0) {
      if (local_1c0 == 0) {
        lVar11 = local_150;
        if (local_1c8 == 0) goto LAB_00b37b40;
      }
      else if ((local_1c8 == 0) &&
              (local_1c8 = FUN_00b2eb60(0,local_1c0), local_190 = local_1c8, local_1c8 == 0)) {
        thunk_FUN_00b2d8d0(local_150);
        thunk_FUN_00b2d8d0(local_1c0);
        goto LAB_00b37df0;
      }
      lVar10 = FUN_00b2eb60(local_1c8,local_150);
      lVar11 = local_1c0;
      if (lVar10 != 0) goto LAB_00b37b40;
      thunk_FUN_00b2d8d0(local_150);
    }
  }
LAB_00b37df0:
  iVar6 = -5;
  goto LAB_00b37a54;
}


// ==== entry=00b37ee0 name=FUN_00b37ee0 size=5277 ====

int FUN_00b37ee0(undefined4 *param_1,long *param_2)

{
  undefined4 uVar1;
  ulong uVar2;
  undefined8 *puVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  undefined4 *puVar10;
  int *piVar11;
  void *pvVar12;
  long lVar13;
  char cVar14;
  undefined8 uVar15;
  ulong uVar16;
  uint uVar17;
  uint uVar18;
  int iVar19;
  ulong uVar20;
  ulong uVar21;
  bool bVar22;
  int local_3c [3];
  
  switch(*param_1) {
  case 0:
    uVar2 = *(ulong *)(param_1 + 4);
    uVar21 = *(ulong *)(param_1 + 2);
    if ((param_1[6] & 1) == 0) {
      if (uVar21 < uVar2) {
        puVar3 = (undefined8 *)param_2[9];
        iVar5 = 1;
        uVar6 = (uint)param_1[6] >> 1 & 1;
        iVar4 = (*(code *)*puVar3)(uVar21);
        uVar16 = (ulong)iVar4;
        uVar20 = uVar21 + uVar16;
        do {
          if (uVar2 <= uVar20) {
            iVar5 = FUN_00b352c0(uVar21,uVar16 & 0xffffffff,(long)iVar5,param_2,uVar6);
            return iVar5;
          }
          uVar8 = (*(code *)*puVar3)(uVar20);
          if (uVar8 == (uint)uVar16) {
            iVar5 = iVar5 + 1;
          }
          else {
            iVar5 = FUN_00b352c0(uVar21,uVar16 & 0xffffffff,(long)iVar5,param_2,uVar6);
            if (iVar5 != 0) {
              return iVar5;
            }
            iVar5 = 1;
            uVar16 = (ulong)uVar8;
            uVar21 = uVar20;
          }
          uVar20 = uVar20 + (long)(int)uVar8;
        } while( true );
      }
    }
    else if (uVar21 < uVar2) {
      iVar5 = FUN_00b352c0(uVar21,1,uVar2 - uVar21,param_2,0);
      return iVar5;
    }
    goto LAB_00b37f30;
  case 1:
    if ((param_1[1] & 2) == 0) {
      uVar6 = param_1[1] & 1;
      if (*(long *)(param_1 + 10) == 0) {
        if (uVar6 == 0) {
          FUN_00b351c0(param_2,0x10);
        }
        else {
          FUN_00b351c0(param_2,0x13);
        }
        iVar5 = FUN_00b35090(param_2,param_1 + 2);
        return iVar5;
      }
      if (*(int *)(param_2[9] + 0x1c) < 2) {
        piVar11 = param_1 + 2;
        do {
          if (*piVar11 != 0) {
            if (uVar6 == 0) {
              FUN_00b351c0(param_2,0x12);
            }
            else {
              FUN_00b351c0(param_2,0x15);
            }
            iVar5 = FUN_00b35090(param_2,param_1 + 2);
            if (iVar5 == 0) {
              puVar3 = *(undefined8 **)(param_1 + 10);
              FUN_00b35100(param_2,*(undefined4 *)(puVar3 + 1));
              iVar5 = FUN_00b35020(param_2,*puVar3,*(undefined4 *)(puVar3 + 1));
              return iVar5;
            }
            return iVar5;
          }
          piVar11 = piVar11 + 1;
        } while (piVar11 != param_1 + 10);
      }
      if (uVar6 == 0) {
        FUN_00b351c0(param_2,0x11);
      }
      else {
        FUN_00b351c0(param_2,0x14);
      }
      puVar3 = *(undefined8 **)(param_1 + 10);
      FUN_00b35100(param_2,*(undefined4 *)(puVar3 + 1));
      iVar5 = FUN_00b35020(param_2,*puVar3,*(undefined4 *)(puVar3 + 1));
      return iVar5;
    }
    FUN_00b351c0(param_2,0x16);
    uVar8 = *(uint *)(param_2 + 1);
    uVar6 = *(uint *)((long)param_2 + 0xc);
    uVar18 = uVar8 + 8;
    if (uVar6 < uVar18) {
      do {
        uVar6 = uVar6 * 2;
      } while (uVar6 < uVar18);
      *(uint *)((long)param_2 + 0xc) = uVar6;
      pvVar12 = realloc((void *)*param_2,(ulong)uVar6);
      *param_2 = (long)pvVar12;
      if (pvVar12 == (void *)0x0) {
        return -5;
      }
      uVar8 = *(uint *)(param_2 + 1);
    }
    else {
      pvVar12 = (void *)*param_2;
    }
    *(undefined4 **)((long)pvVar12 + (ulong)uVar8) = param_1;
    if (*(uint *)(param_2 + 1) < uVar18) {
      *(uint *)(param_2 + 1) = uVar18;
      return 0;
    }
    goto LAB_00b37f30;
  case 2:
    if (param_1[1] == 0xc) {
      if (param_1[3] == 0) {
        cVar14 = (param_1[2] != 0) + '\x1d';
      }
      else {
        cVar14 = (param_1[2] != 0) + '#';
      }
      iVar5 = FUN_00b351c0(param_2,cVar14);
    }
    else {
      iVar5 = -6;
    }
    break;
  case 3:
    if ((*(byte *)(param_2 + 10) & 4) == 0) {
      iVar5 = FUN_00b351c0(param_2,0x17);
    }
    else {
      iVar5 = FUN_00b351c0(param_2,0x18);
    }
    break;
  case 4:
    if ((*(byte *)((long)param_1 + 5) & 0x20) == 0) {
      if (param_1[2] == 1) {
        iVar5 = param_1[3];
        if ((*(uint *)(param_2 + 10) & 1) != 0) {
          iVar4 = FUN_00b351c0(param_2,0x33);
          if (iVar4 == 0) {
            iVar5 = FUN_00b35160(param_2,iVar5);
            return iVar5;
          }
          return iVar4;
        }
        if (iVar5 == 1) {
          iVar5 = FUN_00b351c0(param_2,0x30);
          return iVar5;
        }
        if (iVar5 == 2) {
          iVar5 = FUN_00b351c0(param_2,0x31);
          return iVar5;
        }
        iVar4 = FUN_00b351c0(param_2,0x32);
        if (iVar4 == 0) {
          iVar5 = FUN_00b35160(param_2,iVar5);
          return iVar5;
        }
        return iVar4;
      }
      if ((*(uint *)(param_2 + 10) & 1) == 0) {
        iVar5 = FUN_00b351c0(param_2,0x34);
      }
      else {
        iVar5 = FUN_00b351c0(param_2,0x35);
      }
    }
    else {
      iVar5 = FUN_00b351c0(param_2,0x36);
      if (iVar5 != 0) {
        return iVar5;
      }
      uVar18 = *(uint *)(param_2 + 1);
      uVar6 = *(uint *)(param_2 + 10);
      uVar8 = *(uint *)((long)param_2 + 0xc);
      pvVar12 = (void *)*param_2;
      uVar17 = uVar18 + 4;
      if (uVar8 < uVar17) {
        do {
          uVar8 = uVar8 * 2;
        } while (uVar8 < uVar17);
        *(uint *)((long)param_2 + 0xc) = uVar8;
        pvVar12 = realloc(pvVar12,(ulong)uVar8);
        *param_2 = (long)pvVar12;
        if (pvVar12 == (void *)0x0) {
          return -5;
        }
        uVar18 = *(uint *)(param_2 + 1);
      }
      *(uint *)((long)pvVar12 + (ulong)uVar18) = uVar6 & 1;
      if (*(uint *)(param_2 + 1) < uVar17) {
        *(uint *)(param_2 + 1) = uVar17;
      }
      iVar5 = FUN_00b35100(param_2,(long)(int)param_1[0xc]);
    }
    if (iVar5 != 0) {
      return iVar5;
    }
    iVar5 = FUN_00b35100(param_2,(long)(int)param_1[2]);
    if (iVar5 != 0) {
      return iVar5;
    }
    puVar10 = *(undefined4 **)(param_1 + 10);
    if (*(undefined4 **)(param_1 + 10) == (undefined4 *)0x0) {
      puVar10 = param_1 + 3;
    }
    if (-1 < param_1[2] + -1) {
      lVar13 = (long)(param_1[2] + -1);
      do {
        iVar5 = FUN_00b35160(param_2,puVar10[lVar13]);
        if (iVar5 != 0) {
          return iVar5;
        }
        lVar13 = lVar13 + -1;
      } while (-1 < (int)lVar13);
    }
    goto LAB_00b37f30;
  case 5:
    iVar5 = param_1[5];
    iVar4 = param_1[7];
    iVar7 = FUN_00b353b0(*(undefined8 *)(param_1 + 2));
    if (iVar7 < 0) {
      return iVar7;
    }
    iVar19 = param_1[6];
    if (((iVar19 != 0) && (param_1[5] == -1)) && (piVar11 = *(int **)(param_1 + 2), *piVar11 == 3))
    {
      iVar5 = param_1[4];
      iVar4 = 0;
      if (0 < iVar5) {
        do {
          iVar7 = FUN_00b37ee0(piVar11,param_2);
          if (iVar7 != 0) {
            return iVar7;
          }
          iVar4 = iVar4 + 1;
        } while (iVar5 != iVar4);
      }
      if (*(long *)(param_1 + 10) == 0) {
        if ((*(uint *)(param_2 + 10) & 4) == 0) {
          iVar5 = FUN_00b351c0(param_2,0x19);
          return iVar5;
        }
        iVar5 = FUN_00b351c0(param_2,0x1a);
        return iVar5;
      }
      if ((*(uint *)(param_2 + 10) & 4) == 0) {
        iVar5 = FUN_00b351c0(param_2,0x1b);
      }
      else {
        iVar5 = FUN_00b351c0(param_2,0x1c);
      }
      if (iVar5 == 0) {
        iVar5 = FUN_00b35020(param_2,*(undefined8 *)(*(long *)(param_1 + 10) + 8),1);
        return iVar5;
      }
      return iVar5;
    }
    iVar9 = iVar7 + 6;
    if (iVar4 == 0) {
      iVar9 = iVar7;
    }
    if (iVar5 == -1) {
      iVar5 = param_1[4];
      if (iVar5 < 2) {
        if ((iVar5 == 1) && (0x32 < iVar7)) {
          if ((iVar19 == 0) || ((*(long *)(param_1 + 8) == 0 && (*(long *)(param_1 + 10) == 0)))) {
            iVar5 = FUN_00b35220(param_2,0x3f,5);
          }
          else {
            iVar5 = FUN_00b35220(param_2,0x3f,6);
          }
          if (iVar5 != 0) {
            return iVar5;
          }
          goto LAB_00b3884e;
        }
        uVar15 = *(undefined8 *)(param_1 + 2);
        if (iVar5 != 1) goto LAB_00b3884e;
      }
      else {
        if (0x32 < iVar7 * iVar5) {
          if ((param_1[5] == 0) && (param_1[0xc] != 0)) goto LAB_00b38df0;
          if (iVar19 != 0) goto LAB_00b38c92;
          goto LAB_00b38b7a;
        }
        uVar15 = *(undefined8 *)(param_1 + 2);
      }
      iVar7 = 0;
      do {
        iVar19 = FUN_00b37ee0(uVar15,param_2);
        if (iVar19 != 0) {
          return iVar19;
        }
        iVar7 = iVar7 + 1;
      } while (iVar7 < iVar5);
LAB_00b3884e:
      if (param_1[6] == 0) {
        iVar5 = FUN_00b35220(param_2,0x3f,iVar9);
        if (iVar5 != 0) {
          return iVar5;
        }
        iVar5 = FUN_00b39460(*(undefined8 *)(param_1 + 2),param_2,iVar4);
        if (iVar5 == 0) {
          iVar5 = FUN_00b35220(param_2,0x40,-5 - iVar9);
          return iVar5;
        }
        return iVar5;
      }
      iVar5 = iVar9 + 5;
      if (*(long *)(param_1 + 8) != 0) {
        iVar5 = FUN_00b35220(param_2,0x42,iVar5);
        if (iVar5 != 0) {
          return iVar5;
        }
        FUN_00b35020(param_2,*(undefined8 *)(*(long *)(param_1 + 8) + 8),1);
        iVar5 = FUN_00b39460(*(undefined8 *)(param_1 + 2),param_2,iVar4);
        if (iVar5 == 0) {
          iVar5 = FUN_00b35220(param_2,0x3f,-0xb - iVar9);
          return iVar5;
        }
        return iVar5;
      }
      if (*(long *)(param_1 + 10) == 0) {
        iVar5 = FUN_00b35220(param_2,0x40,iVar5);
        if (iVar5 != 0) {
          return iVar5;
        }
        iVar5 = FUN_00b39460(*(undefined8 *)(param_1 + 2),param_2,iVar4);
        if (iVar5 == 0) {
          iVar5 = FUN_00b35220(param_2,0x3f,-10 - iVar9);
          return iVar5;
        }
        return iVar5;
      }
      iVar5 = FUN_00b35220(param_2,0x43,iVar5);
      if (iVar5 != 0) {
        return iVar5;
      }
      FUN_00b35020(param_2,*(undefined8 *)(*(long *)(param_1 + 10) + 8),1);
      iVar5 = FUN_00b39460(*(undefined8 *)(param_1 + 2),param_2,iVar4);
      if (iVar5 == 0) {
        iVar5 = FUN_00b35220(param_2,0x3f,-0xb - iVar9);
        return iVar5;
      }
      return iVar5;
    }
    iVar5 = param_1[5];
    if (iVar5 == 0) {
      if (param_1[0xc] != 0) {
LAB_00b38df0:
        iVar5 = FUN_00b35220(param_2,0x3f,iVar7);
        if (iVar5 == 0) {
          iVar5 = FUN_00b37ee0(*(undefined8 *)(param_1 + 2),param_2);
          return iVar5;
        }
        return iVar5;
      }
      iVar5 = 0;
      if (iVar19 != 0) {
LAB_00b384ab:
        iVar4 = param_1[4];
        uVar15 = *(undefined8 *)(param_1 + 2);
        iVar19 = 0;
        if (0 < iVar4) {
          do {
            iVar9 = FUN_00b37ee0(uVar15,param_2);
            if (iVar9 != 0) {
              return iVar9;
            }
            iVar19 = iVar19 + 1;
          } while (iVar4 != iVar19);
        }
        iVar5 = iVar5 - iVar4;
        if (0 < iVar5) {
          iVar19 = 0;
          iVar4 = iVar5 * 5 + -5 + iVar7 * iVar5;
          do {
            iVar9 = FUN_00b35220(param_2,0x40,iVar4);
            if (iVar9 != 0) {
              return iVar9;
            }
            iVar9 = FUN_00b37ee0(*(undefined8 *)(param_1 + 2),param_2);
            if (iVar9 != 0) {
              return iVar9;
            }
            iVar19 = iVar19 + 1;
            iVar4 = iVar4 + (-5 - iVar7);
          } while (iVar5 != iVar19);
        }
        return 0;
      }
LAB_00b38b7a:
      if (*(long *)(param_1 + 4) == 0x100000000) {
        iVar5 = FUN_00b35220(param_2,0x40,5);
        if (iVar5 != 0) {
          return iVar5;
        }
        iVar5 = FUN_00b35220(param_2,0x3f,iVar7);
        if (iVar5 == 0) {
          iVar5 = FUN_00b37ee0(*(undefined8 *)(param_1 + 2),param_2);
          return iVar5;
        }
        return iVar5;
      }
      iVar7 = (int)param_2[3];
      uVar15 = 0x45;
    }
    else {
      if (iVar19 == 0) goto LAB_00b38b7a;
      if ((iVar5 == 1) || ((iVar7 + 5) * iVar5 < 0x33)) goto LAB_00b384ab;
LAB_00b38c92:
      iVar7 = (int)param_2[3];
      uVar15 = 0x44;
    }
    iVar5 = FUN_00b351c0(param_2,uVar15);
    if (iVar5 != 0) {
      return iVar5;
    }
    iVar5 = FUN_00b35160(param_2,iVar7);
    *(int *)(param_2 + 3) = (int)param_2[3] + 1;
    if (iVar5 != 0) {
      return iVar5;
    }
    iVar5 = FUN_00b34fc0(param_2,iVar9 + 3);
    if (iVar5 != 0) {
      return iVar5;
    }
    iVar5 = (int)param_2[7];
    iVar19 = param_1[5];
    uVar1 = param_1[4];
    if (iVar5 == 0) {
      pvVar12 = malloc(0x20);
      if (pvVar12 == (void *)0x0) {
        return -5;
      }
      param_2[8] = (long)pvVar12;
      *(undefined4 *)(param_2 + 7) = 4;
    }
    else {
      pvVar12 = (void *)param_2[8];
      if (iVar5 <= iVar7) {
        pvVar12 = realloc(pvVar12,(long)(iVar5 + 4) << 3);
        if (pvVar12 == (void *)0x0) {
          return -5;
        }
        param_2[8] = (long)pvVar12;
        *(int *)(param_2 + 7) = iVar5 + 4;
      }
    }
    uVar15 = *(undefined8 *)(param_1 + 2);
    puVar10 = (undefined4 *)((long)pvVar12 + (long)iVar7 * 8);
    if (iVar19 == -1) {
      iVar19 = 0x7fffffff;
    }
    *puVar10 = uVar1;
    puVar10[1] = iVar19;
    iVar5 = FUN_00b39460(uVar15,param_2,iVar4);
    if (iVar5 == 0) {
      if ((*(int *)((long)param_2 + 0x24) < 1) && ((*(byte *)((long)param_1 + 5) & 0x10) == 0)) {
        iVar5 = FUN_00b351c0(param_2,~-(uint)(param_1[6] == 0) + 0x47);
      }
      else {
        iVar5 = FUN_00b351c0(param_2,~-(uint)(param_1[6] == 0) + 0x49);
      }
      if (iVar5 == 0) {
        iVar5 = FUN_00b35160(param_2,iVar7);
      }
    }
    break;
  case 6:
    iVar5 = param_1[2];
    if (iVar5 == 2) {
      lVar13 = param_2[10];
      uVar15 = *(undefined8 *)(param_1 + 6);
      *(undefined4 *)(param_2 + 10) = param_1[4];
      iVar5 = FUN_00b37ee0(uVar15);
      *(int *)(param_2 + 10) = (int)lVar13;
    }
    else if (iVar5 == 4) {
      if ((*(byte *)(param_1 + 1) & 0x40) == 0) {
        iVar5 = FUN_00b351c0(param_2,0x52);
        if ((iVar5 == 0) && (iVar5 = FUN_00b37ee0(*(undefined8 *)(param_1 + 6),param_2), iVar5 == 0)
           ) {
          iVar5 = FUN_00b351c0(param_2,0x53);
        }
      }
      else {
        lVar13 = *(long *)(param_1 + 6);
        iVar5 = *(int *)(lVar13 + 0x10);
        uVar15 = *(undefined8 *)(lVar13 + 8);
        if (0 < iVar5) {
          iVar4 = 0;
          do {
            iVar7 = FUN_00b37ee0(uVar15,param_2);
            if (iVar7 != 0) {
              return iVar7;
            }
            iVar4 = iVar4 + 1;
          } while (iVar5 != iVar4);
          uVar15 = *(undefined8 *)(lVar13 + 8);
        }
        iVar4 = FUN_00b353b0(uVar15,param_2);
        iVar5 = iVar4;
        if ((((-1 < iVar4) && (iVar5 = FUN_00b35220(param_2,0x40,iVar4 + 6), iVar5 == 0)) &&
            (iVar5 = FUN_00b37ee0(*(undefined8 *)(lVar13 + 8),param_2), iVar5 == 0)) &&
           (iVar5 = FUN_00b351c0(param_2,0x41), iVar5 == 0)) {
          iVar5 = FUN_00b35220(param_2,0x3f,-0xb - iVar4);
        }
      }
    }
    else if (iVar5 == 8) {
      iVar5 = FUN_00b351c0(param_2,0x59);
      if (iVar5 != 0) {
        return iVar5;
      }
      iVar5 = FUN_00b35160(param_2,param_1[3]);
      if (iVar5 != 0) {
        return iVar5;
      }
      piVar11 = *(int **)(param_1 + 6);
      if (*piVar11 == 9) {
        iVar5 = FUN_00b353b0(*(undefined8 *)(piVar11 + 2),param_2);
        if (iVar5 < 0) {
          return iVar5;
        }
        lVar13 = *(long *)(piVar11 + 4);
        if (lVar13 != 0) {
          iVar4 = FUN_00b353b0(*(undefined8 *)(lVar13 + 8),param_2);
          if (iVar4 < 0) {
            return iVar4;
          }
          if (*(long *)(lVar13 + 0x10) != 0) {
            return -0x7c;
          }
          lVar13 = *(long *)(param_1 + 6);
          iVar5 = FUN_00b34fc0(param_2,iVar5 + 5);
          if (iVar5 != 0) {
            return iVar5;
          }
          iVar5 = FUN_00b37ee0(*(undefined8 *)(lVar13 + 8),param_2);
          if (iVar5 == 0) {
            iVar5 = FUN_00b35220(param_2,0x3f,iVar4);
            if (iVar5 == 0) {
              iVar5 = FUN_00b37ee0(*(undefined8 *)(*(long *)(lVar13 + 0x10) + 8),param_2);
              return iVar5;
            }
            return iVar5;
          }
          return iVar5;
        }
      }
      iVar5 = -0xb;
    }
    else {
      if (iVar5 != 1) {
        return -6;
      }
      if ((*(byte *)((long)param_1 + 5) & 1) != 0) {
        iVar5 = FUN_00b351c0(param_2,0x57);
        if (iVar5 != 0) {
          return iVar5;
        }
        lVar13 = param_2[1];
        param_1[1] = param_1[1] | 0x200;
        param_1[8] = (int)lVar13 + 9;
        iVar5 = FUN_00b34fc0(param_2);
        if (iVar5 != 0) {
          return iVar5;
        }
        iVar5 = FUN_00b353b0(*(undefined8 *)(param_1 + 6),param_2);
        iVar5 = FUN_00b35220(param_2,0x3f,iVar5 + 7);
        if (iVar5 != 0) {
          return iVar5;
        }
      }
      if ((int)param_1[3] < 0x20) {
        bVar22 = (1 << ((byte)param_1[3] & 0x1f) & *(uint *)((long)param_2 + 0x2c)) != 0;
      }
      else {
        bVar22 = (bool)((byte)*(uint *)((long)param_2 + 0x2c) & 1);
      }
      if (bVar22 == false) {
        iVar5 = FUN_00b351c0(param_2,0x37);
      }
      else {
        iVar5 = FUN_00b351c0(param_2,0x38);
      }
      if (((iVar5 == 0) && (iVar5 = FUN_00b35160(param_2,param_1[3]), iVar5 == 0)) &&
         (iVar5 = FUN_00b37ee0(*(undefined8 *)(param_1 + 6),param_2), iVar5 == 0)) {
        iVar5 = param_1[3];
        uVar6 = *(uint *)(param_2 + 6);
        if ((param_1[1] & 0x100) == 0) {
          bVar22 = (bool)((byte)uVar6 & 1);
          if (iVar5 < 0x20) {
            bVar22 = (1 << ((byte)iVar5 & 0x1f) & uVar6) != 0;
          }
          if (bVar22 == false) {
            iVar5 = FUN_00b351c0(param_2,0x3b);
          }
          else {
            iVar5 = FUN_00b351c0(param_2,0x39);
          }
          if (iVar5 == 0) {
            iVar5 = FUN_00b35160(param_2,param_1[3]);
          }
        }
        else {
          bVar22 = (bool)((byte)uVar6 & 1);
          if (iVar5 < 0x20) {
            bVar22 = (1 << ((byte)iVar5 & 0x1f) & uVar6) != 0;
          }
          uVar6 = param_1[1] & 0x80;
          if (bVar22 == false) {
            iVar5 = FUN_00b351c0(param_2,0x3c - (uint)(uVar6 == 0));
          }
          else {
            iVar5 = FUN_00b351c0(param_2,0x3a - (uint)(uVar6 == 0));
          }
          if ((iVar5 == 0) && (iVar5 = FUN_00b35160(param_2,param_1[3]), iVar5 == 0)) {
            iVar5 = FUN_00b351c0(param_2,0x58);
          }
        }
      }
    }
    break;
  case 7:
    iVar4 = param_1[1];
    if (iVar4 == 0x80) {
      if (param_1[5] == 0) {
        iVar5 = FUN_00b351c0(param_2,0x20);
      }
      else {
        iVar5 = FUN_00b351c0(param_2,0x26);
      }
    }
    else if (iVar4 < 0x81) {
      if (iVar4 == 8) {
        iVar5 = FUN_00b351c0(param_2,0x2a);
      }
      else if (iVar4 < 9) {
        if (iVar4 == 2) {
          iVar5 = FUN_00b351c0(param_2,0x2b);
        }
        else if (iVar4 == 4) {
          iVar5 = FUN_00b351c0(param_2,0x2e);
        }
        else {
          iVar5 = -6;
          if (iVar4 == 1) {
            iVar5 = FUN_00b351c0(param_2,0x29);
          }
        }
      }
      else if (iVar4 == 0x20) {
        iVar5 = FUN_00b351c0(param_2,0x2c);
      }
      else if (iVar4 == 0x40) {
        if (param_1[5] == 0) {
          iVar5 = FUN_00b351c0(param_2,0x1f);
        }
        else {
          iVar5 = FUN_00b351c0(param_2,0x25);
        }
      }
      else {
        iVar5 = -6;
        if (iVar4 == 0x10) {
          iVar5 = FUN_00b351c0(param_2,0x2d);
        }
      }
    }
    else if (iVar4 == 0x800) {
      iVar5 = FUN_00b353b0(*(undefined8 *)(param_1 + 2));
      if (((-1 < iVar5) && (iVar5 = FUN_00b35220(param_2,0x50,iVar5 + 1), iVar5 == 0)) &&
         (iVar5 = FUN_00b37ee0(*(undefined8 *)(param_1 + 2),param_2), iVar5 == 0)) {
        iVar5 = FUN_00b351c0(param_2,0x51);
      }
    }
    else if (iVar4 < 0x801) {
      if (iVar4 == 0x200) {
        if (param_1[5] == 0) {
          iVar5 = FUN_00b351c0(param_2,0x22);
        }
        else {
          iVar5 = FUN_00b351c0(param_2,0x28);
        }
      }
      else if (iVar4 == 0x400) {
        iVar5 = FUN_00b351c0(param_2,0x4e);
        if ((iVar5 == 0) && (iVar5 = FUN_00b37ee0(*(undefined8 *)(param_1 + 2),param_2), iVar5 == 0)
           ) {
          iVar5 = FUN_00b351c0(param_2,0x4f);
        }
      }
      else {
        iVar5 = -6;
        if (iVar4 == 0x100) {
          if (param_1[5] == 0) {
            iVar5 = FUN_00b351c0(param_2,0x21);
          }
          else {
            iVar5 = FUN_00b351c0(param_2,0x27);
          }
        }
      }
    }
    else if (iVar4 == 0x2000) {
      iVar5 = FUN_00b353b0(*(undefined8 *)(param_1 + 2));
      iVar5 = FUN_00b35220(param_2,0x55,iVar5 + 1);
      if (iVar5 == 0) {
        iVar5 = param_1[4];
        if (((int)param_1[4] < 0) &&
           (iVar4 = FUN_00b342f0(*(undefined8 *)(param_1 + 2),param_2,local_3c), iVar5 = local_3c[0]
           , iVar4 != 0)) {
          return -0x7a;
        }
        local_3c[0] = iVar5;
        iVar5 = FUN_00b35100(param_2,(long)local_3c[0]);
        if ((iVar5 == 0) && (iVar5 = FUN_00b37ee0(*(undefined8 *)(param_1 + 2),param_2), iVar5 == 0)
           ) {
          iVar5 = FUN_00b351c0(param_2,0x56);
        }
      }
    }
    else if (iVar4 < 0x2001) {
      iVar5 = -6;
      if ((iVar4 == 0x1000) && (iVar5 = FUN_00b351c0(param_2,0x54), iVar5 == 0)) {
        iVar5 = param_1[4];
        if (((int)param_1[4] < 0) &&
           (iVar4 = FUN_00b342f0(*(undefined8 *)(param_1 + 2),param_2,local_3c), iVar5 = local_3c[0]
           , iVar4 != 0)) {
          return -0x7a;
        }
        local_3c[0] = iVar5;
        iVar5 = FUN_00b35100(param_2,(long)local_3c[0]);
        if (iVar5 == 0) {
          iVar5 = FUN_00b37ee0(*(undefined8 *)(param_1 + 2),param_2);
        }
      }
    }
    else if (iVar4 == 0x4000) {
      iVar5 = FUN_00b351c0(param_2,0x2f);
    }
    else {
      iVar5 = -6;
      if (iVar4 == 0x10000) {
        iVar5 = FUN_00b351c0(param_2,0x3d);
      }
    }
    break;
  case 8:
    do {
      iVar5 = FUN_00b37ee0(*(undefined8 *)(param_1 + 2),param_2);
      if (iVar5 != 0) {
        return iVar5;
      }
      param_1 = *(undefined4 **)(param_1 + 4);
    } while (param_1 != (undefined4 *)0x0);
    goto LAB_00b37f30;
  case 9:
    iVar5 = 0;
    puVar10 = param_1;
    while( true ) {
      iVar4 = FUN_00b353b0(*(undefined8 *)(puVar10 + 2),param_2);
      puVar10 = *(undefined4 **)(puVar10 + 4);
      if (puVar10 == (undefined4 *)0x0) break;
      iVar5 = iVar5 + iVar4 + 10;
    }
    lVar13 = param_2[1];
    do {
      iVar7 = FUN_00b353b0(*(undefined8 *)(param_1 + 2),param_2);
      if ((*(long *)(param_1 + 4) != 0) &&
         (iVar7 = FUN_00b35220(param_2,0x40,iVar7 + 5), iVar7 != 0)) {
        return iVar7;
      }
      iVar7 = FUN_00b37ee0(*(undefined8 *)(param_1 + 2),param_2);
      if (iVar7 != 0) {
        return iVar7;
      }
      if (*(long *)(param_1 + 4) == 0) break;
      iVar7 = FUN_00b35220(param_2,0x3f,(-5 - (int)param_2[1]) + iVar5 + iVar4 + (int)lVar13);
      if (iVar7 != 0) {
        return iVar7;
      }
      param_1 = *(undefined4 **)(param_1 + 4);
    } while (param_1 != (undefined4 *)0x0);
LAB_00b37f30:
    iVar5 = 0;
    break;
  case 10:
    iVar5 = FUN_00b351c0(param_2,0x57);
    if (iVar5 != 0) {
      return iVar5;
    }
    uVar15 = *(undefined8 *)(param_1 + 8);
    piVar11 = *(int **)(param_1 + 10);
    lVar13 = param_2[1];
    iVar5 = *piVar11;
    pvVar12 = *(void **)(piVar11 + 2);
    if (piVar11[1] <= iVar5) {
      iVar5 = piVar11[1] * 2;
      pvVar12 = realloc(pvVar12,(long)iVar5 << 4);
      if (pvVar12 == (void *)0x0) {
        return -5;
      }
      piVar11[1] = iVar5;
      iVar5 = *piVar11;
      *(void **)(piVar11 + 2) = pvVar12;
    }
    puVar10 = (undefined4 *)((long)pvVar12 + (long)iVar5 * 0x10);
    *puVar10 = (int)lVar13;
    *(undefined8 *)(puVar10 + 2) = uVar15;
    *piVar11 = iVar5 + 1;
    iVar5 = FUN_00b34fc0(param_2,0);
    break;
  default:
    return 0;
  }
  return iVar5;
}


// ==== entry=00b39460 name=FUN_00b39460 size=182 ====

void FUN_00b39460(undefined8 param_1,long param_2,int param_3)

{
  undefined4 uVar1;
  int iVar2;
  
  if (param_3 == 0) {
    FUN_00b37ee0();
    return;
  }
  uVar1 = *(undefined4 *)(param_2 + 0x1c);
  iVar2 = FUN_00b351c0(param_2,0x4a);
  if ((iVar2 == 0) && (iVar2 = FUN_00b35160(param_2,*(undefined4 *)(param_2 + 0x1c)), iVar2 == 0)) {
    *(int *)(param_2 + 0x1c) = *(int *)(param_2 + 0x1c) + 1;
    iVar2 = FUN_00b37ee0(param_1,param_2);
    if (iVar2 != 0) {
      return;
    }
    if (param_3 == 1) {
      iVar2 = FUN_00b351c0(param_2,0x4b);
    }
    else if (param_3 == 2) {
      iVar2 = FUN_00b351c0(param_2,0x4c);
    }
    else {
      if (param_3 != 3) goto LAB_00b394dc;
      iVar2 = FUN_00b351c0(param_2,0x4d);
    }
    if (iVar2 == 0) {
LAB_00b394dc:
      FUN_00b35160(param_2,uVar1);
      return;
    }
  }
  return;
}


// ==== entry=00b39530 name=FUN_00b39530 size=7 ====

undefined4 FUN_00b39530(void)

{
  return DAT_011becc8;
}


// ==== entry=00b39540 name=FUN_00b39540 size=9 ====

undefined8 FUN_00b39540(undefined4 param_1)

{
  DAT_011becc8 = param_1;
  return 0;
}


// ==== entry=00b39550 name=FUN_00b39550 size=67 ====

undefined8 FUN_00b39550(undefined8 *param_1,size_t param_2)

{
  void *pvVar1;
  
  if (param_2 == 0) {
    *param_1 = 0;
  }
  else {
    pvVar1 = malloc(param_2);
    *param_1 = pvVar1;
    if (pvVar1 == (void *)0x0) {
      return 0xfffffffb;
    }
  }
  *(int *)((long)param_1 + 0xc) = (int)param_2;
  *(undefined4 *)(param_1 + 1) = 0;
  return 0;
}


// ==== entry=00b395a0 name=FUN_00b395a0 size=139 ====

void FUN_00b395a0(undefined8 *param_1)

{
  void *__ptr;
  
  if (param_1 != (undefined8 *)0x0) {
    if ((void *)*param_1 != (void *)0x0) {
      free((void *)*param_1);
    }
    if ((void *)param_1[0x13] != (void *)0x0) {
      free((void *)param_1[0x13]);
    }
    if ((void *)param_1[0x35] != (void *)0x0) {
      free((void *)param_1[0x35]);
    }
    if ((void *)param_1[0x36] != (void *)0x0) {
      free((void *)param_1[0x36]);
    }
    if ((void *)param_1[8] != (void *)0x0) {
      free((void *)param_1[8]);
    }
    __ptr = (void *)param_1[0x39];
    if (__ptr != (void *)0x0) {
      FUN_00b395a0(__ptr);
      free(__ptr);
    }
    FUN_00b2e8e0(param_1);
    return;
  }
  return;
}


// ==== entry=00b39640 name=FUN_00b39640 size=24 ====

void FUN_00b39640(void *param_1)

{
  if (param_1 != (void *)0x0) {
    FUN_00b395a0();
    free(param_1);
    return;
  }
  return;
}


// ==== entry=00b39670 name=FUN_00b39670 size=128 ====

long FUN_00b39670(long *param_1)

{
  long lVar1;
  long lVar2;
  
  lVar1 = 0;
  if (param_1 == (long *)0x0) {
    return 0;
  }
  do {
    lVar2 = 0x1d0;
    if (*param_1 != 0) {
      lVar2 = (ulong)*(uint *)((long)param_1 + 0xc) + 0x1d0;
    }
    if (param_1[0x13] != 0) {
      lVar2 = lVar2 + (param_1[0x14] - param_1[0x13]);
    }
    if (param_1[0x35] != 0) {
      lVar2 = lVar2 + 0x400;
    }
    if (param_1[0x36] != 0) {
      lVar2 = lVar2 + 0x400;
    }
    if (param_1[8] != 0) {
      lVar2 = lVar2 + (long)(int)param_1[7] * 8;
    }
    param_1 = (long *)param_1[0x39];
    lVar1 = lVar1 + lVar2;
  } while (param_1 != (long *)0x0);
  return lVar1;
}


// ==== entry=00b396f0 name=FUN_00b396f0 size=20 ====

long FUN_00b396f0(int *param_1)

{
  if (param_1 != (int *)0x0) {
    return (long)*param_1 * 0x10 + 0x20;
  }
  return 0;
}


// ==== entry=00b39710 name=FUN_00b39710 size=90 ====

void FUN_00b39710(undefined8 *param_1,undefined8 *param_2)

{
  ulong uVar1;
  long lVar2;
  undefined8 *puVar3;
  undefined8 *puVar4;
  byte bVar5;
  
  bVar5 = 0;
  *(undefined4 *)(param_1 + 2) = 0xfffffffe;
  FUN_00b395a0();
  *param_1 = *param_2;
  param_1[0x39] = param_2[0x39];
  lVar2 = (long)param_1 - (long)((ulong)(param_1 + 1) & 0xfffffffffffffff8);
  puVar3 = (undefined8 *)((long)param_2 - lVar2);
  puVar4 = (undefined8 *)((ulong)(param_1 + 1) & 0xfffffffffffffff8);
  for (uVar1 = (ulong)((int)lVar2 + 0x1d0U >> 3); uVar1 != 0; uVar1 = uVar1 - 1) {
    *puVar4 = *puVar3;
    puVar3 = puVar3 + (ulong)bVar5 * -2 + 1;
    puVar4 = puVar4 + (ulong)bVar5 * -2 + 1;
  }
  free(param_2);
  return;
}


// ==== entry=00b39770 orig=FUN_00b39770 size=5 name=thunk_FUN_00b3977b ====

void thunk_FUN_00b3977b(long param_1,undefined8 param_2)

{
  long lVar1;
  
  do {
    lVar1 = param_1;
    param_1 = *(long *)(lVar1 + 0x1c8);
  } while (param_1 != 0);
  *(undefined8 *)(lVar1 + 0x1c8) = param_2;
  return;
}


// ==== entry=00b3977b name=FUN_00b3977b size=20 ====

void FUN_00b3977b(long param_1,undefined8 param_2)

{
  long lVar1;
  
  do {
    lVar1 = param_1;
    param_1 = *(long *)(lVar1 + 0x1c8);
  } while (param_1 != 0);
  *(undefined8 *)(lVar1 + 0x1c8) = param_2;
  return;
}


// ==== entry=00b39790 name=FUN_00b39790 size=140 ====

void FUN_00b39790(undefined8 *param_1)

{
  ulong uVar1;
  undefined8 *puVar2;
  undefined8 *__ptr;
  long lVar3;
  undefined8 *puVar4;
  undefined8 *puVar5;
  byte bVar6;
  
  bVar6 = 0;
  puVar4 = param_1;
  puVar5 = (undefined8 *)param_1[0x39];
  if ((undefined8 *)param_1[0x39] != (undefined8 *)0x0) {
    do {
      __ptr = puVar5;
      puVar2 = puVar4;
      puVar4 = __ptr;
      puVar5 = (undefined8 *)__ptr[0x39];
    } while ((undefined8 *)__ptr[0x39] != (undefined8 *)0x0);
    puVar2[0x39] = 0;
    *(undefined4 *)(param_1 + 2) = 0xfffffffe;
    FUN_00b395a0();
    *param_1 = *__ptr;
    param_1[0x39] = __ptr[0x39];
    lVar3 = (long)param_1 - (long)((ulong)(param_1 + 1) & 0xfffffffffffffff8);
    puVar4 = (undefined8 *)((long)__ptr - lVar3);
    puVar5 = (undefined8 *)((ulong)(param_1 + 1) & 0xfffffffffffffff8);
    for (uVar1 = (ulong)((int)lVar3 + 0x1d0U >> 3); uVar1 != 0; uVar1 = uVar1 - 1) {
      *puVar5 = *puVar4;
      puVar4 = puVar4 + (ulong)bVar6 * -2 + 1;
      puVar5 = puVar5 + (ulong)bVar6 * -2 + 1;
    }
    free(__ptr);
    return;
  }
  return;
}


// ==== entry=00b39830 name=FUN_00b39830 size=248 ====

undefined8
FUN_00b39830(undefined8 *param_1,uint param_2,undefined4 param_3,long param_4,long param_5)

{
  uint uVar1;
  undefined8 uVar2;
  
  if (DAT_011c3820 == 0) {
    DAT_011c3820 = 1;
    FUN_00b42f40();
  }
  if (param_1 == (undefined8 *)0x0) {
    uVar2 = 0xffffffe2;
  }
  else if (param_4 == 0) {
    uVar2 = 0xffffffeb;
  }
  else if ((param_2 & 0x180) == 0x180) {
    uVar2 = 0xfffffe6d;
  }
  else {
    uVar1 = *(uint *)(param_5 + 0xc);
    *(undefined4 *)(param_1 + 2) = 0xfffffffe;
    param_1[9] = param_4;
    uVar1 = uVar1 | param_2;
    param_1[0xb] = param_5;
    *(undefined4 *)(param_1 + 0xc) = param_3;
    *(undefined4 *)(param_1 + 0xe) = 0;
    if ((param_2 & 0x40) != 0) {
      uVar1 = uVar1 & 0xfffffff7;
    }
    param_1[0x13] = 0;
    param_1[0x35] = 0;
    param_1[0x36] = 0;
    param_1[0x39] = 0;
    *param_1 = 0;
    param_1[1] = 0;
    param_1[0xd] = 0;
    *(uint *)(param_1 + 10) = uVar1;
    uVar2 = 0;
  }
  return uVar2;
}


// ==== entry=00b39930 name=FUN_00b39930 size=39 ====

undefined8 FUN_00b39930(void)

{
  if (DAT_011c3820 != 0) {
    return 0;
  }
  DAT_011c3820 = 1;
  FUN_00b42f40();
  return 0;
}


// ==== entry=00b39960 name=FUN_00b39960 size=36 ====

undefined8 FUN_00b39960(void)

{
  FUN_00b33780();
  FUN_00b2eb10();
  FUN_00b337d0();
  DAT_011c3820 = 0;
  return 0;
}


// ==== entry=00b39990 name=FUN_00b39990 size=90 ====

bool FUN_00b39990(uint *param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  bool bVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  
  uVar4 = 0;
  uVar6 = *param_1;
  while (uVar4 < uVar6) {
    uVar5 = uVar6 + uVar4 >> 1;
    uVar1 = param_1[(ulong)(uVar5 * 2 + 1) + 1];
    while (uVar2 = uVar5, param_2 <= uVar1) {
      if (uVar2 <= uVar4) goto LAB_00b399ce;
      uVar5 = uVar4 + uVar2 >> 1;
      uVar1 = param_1[(ulong)(uVar5 * 2 + 1) + 1];
      uVar6 = uVar2;
    }
    uVar4 = uVar2 + 1;
  }
LAB_00b399ce:
  bVar3 = false;
  if (uVar4 < *param_1) {
    bVar3 = param_1[(ulong)(uVar4 * 2) + 1] <= param_2;
  }
  return bVar3;
}


// ==== entry=00b399f0 name=FUN_00b399f0 size=98 ====

bool FUN_00b399f0(int param_1,uint param_2,long param_3)

{
  int iVar1;
  bool bVar2;
  
  if ((param_1 < 2) && (param_2 < 0x100)) {
    bVar2 = (*(uint *)(param_3 + 8 + (long)((int)param_2 >> 5) * 4) & 1 << ((byte)param_2 & 0x1f))
            != 0;
  }
  else {
    bVar2 = false;
    if (*(undefined8 **)(param_3 + 0x28) != (undefined8 *)0x0) {
      iVar1 = FUN_00b39990(**(undefined8 **)(param_3 + 0x28));
      bVar2 = iVar1 != 0;
      if ((*(byte *)(param_3 + 4) & 1) != 0) {
        bVar2 = iVar1 == 0;
      }
      return bVar2;
    }
  }
  if ((*(byte *)(param_3 + 4) & 1) != 0) {
    bVar2 = (bool)(bVar2 ^ 1);
  }
  return bVar2;
}


// ==== entry=00b39a60 name=FUN_00b39a60 size=54 ====

void FUN_00b39a60(long param_1,undefined4 param_2,undefined8 param_3)

{
  undefined4 uVar1;
  
  if (1 < *(int *)(param_1 + 0x1c)) {
    FUN_00b399f0(2);
    return;
  }
  uVar1 = (**(code **)(param_1 + 0x40))(param_2);
  FUN_00b399f0(uVar1,param_2,param_3);
  return;
}


// ==== entry=00b39aa0 name=FUN_00b39aa0 size=2980 ====

int FUN_00b39aa0(int *param_1,long param_2,uint param_3,uint *param_4)

{
  char *pcVar1;
  code *pcVar2;
  code *pcVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  undefined4 uVar8;
  long lVar9;
  long lVar10;
  undefined8 uVar11;
  int *piVar12;
  int *piVar13;
  ulong uVar14;
  long lVar15;
  ulong uVar16;
  uint uVar17;
  uint uVar18;
  ulong uVar19;
  uint *puVar20;
  ulong uVar21;
  uint uVar22;
  uint *puVar23;
  uint uVar24;
  int *piVar25;
  int *piVar26;
  uint local_68;
  long local_40 [2];
  
  uVar24 = param_3 & 0xffffffef;
LAB_00b39ac5:
  switch(*param_1) {
  case 0:
    if ((*(byte *)(param_2 + 0x50) & 1) == 0) {
      return 0;
    }
    if ((*(byte *)(param_1 + 6) & 1) != 0) {
      return 0;
    }
    iVar4 = FUN_00b37810(param_1,param_2);
    return iVar4;
  default:
    break;
  case 4:
    puVar23 = *(uint **)(param_4 + 0x2c);
    if (*(uint **)(param_4 + 0x2c) == (uint *)0x0) {
      puVar23 = param_4 + 0x1c;
    }
    puVar20 = *(uint **)(param_1 + 10);
    if (*(uint **)(param_1 + 10) == (uint *)0x0) {
      puVar20 = (uint *)(param_1 + 3);
    }
    if (param_1[2] < 1) {
      return 0;
    }
    uVar24 = *puVar20;
    uVar18 = param_4[0x18];
    if ((int)uVar18 < (int)uVar24) {
      return -0xd0;
    }
    uVar17 = param_4[9];
    uVar5 = param_4[7];
    iVar4 = 0;
    while( true ) {
      uVar22 = 1 << ((byte)uVar24 & 0x1f) | uVar17;
      uVar17 = uVar17 | 1;
      if ((int)uVar24 < 0x20) {
        uVar17 = uVar22;
      }
      param_4[9] = uVar17;
      uVar24 = 1 << ((byte)*puVar20 & 0x1f) | uVar5;
      uVar5 = uVar5 | 1;
      if ((int)*puVar20 < 0x20) {
        uVar5 = uVar24;
      }
      param_4[7] = uVar5;
      if ((*(byte *)((long)param_1 + 5) & 0x20) != 0) {
        uVar24 = param_4[8] | 1 << (*puVar20 & 0x1f);
        if (0x1f < (int)*puVar20) {
          uVar24 = param_4[8] | 1;
        }
        param_4[8] = uVar24;
      }
      iVar4 = iVar4 + 1;
      *(uint *)(*(long *)(puVar23 + (long)(int)*puVar20 * 2) + 4) =
           *(uint *)(*(long *)(puVar23 + (long)(int)*puVar20 * 2) + 4) | 0x20;
      if (param_1[2] <= iVar4) break;
      puVar20 = puVar20 + 1;
      uVar24 = *puVar20;
      if ((int)uVar18 < (int)uVar24) {
        return -0xd0;
      }
    }
    break;
  case 5:
    piVar25 = *(int **)(param_1 + 2);
    if ((param_3 & 4) != 0) {
      param_1[1] = param_1[1] | 0x1000;
    }
    iVar4 = param_1[5];
    if ((iVar4 == -1) || (0 < iVar4)) {
      iVar4 = FUN_00b33d30(piVar25,local_40,param_4);
      if (iVar4 != 0) {
        return iVar4;
      }
      if (local_40[0] == 0) {
        param_1[7] = 1;
        iVar7 = FUN_00b33c70(piVar25);
        if (iVar7 < 0) {
          return iVar7;
        }
        iVar4 = param_1[5];
        if (iVar7 != 0) {
          param_1[7] = iVar7;
        }
      }
      else {
        iVar4 = param_1[5];
      }
    }
    uVar18 = uVar24 | 0xc;
    if (param_1[4] == iVar4) {
      uVar18 = uVar24 | 4;
    }
    iVar4 = FUN_00b39aa0(piVar25,param_2,uVar18,param_4);
    if (iVar4 != 0) {
      return iVar4;
    }
    if ((*piVar25 != 0) || (iVar4 = param_1[4], iVar4 < 2)) {
      if (param_1[6] == 0) {
        return 0;
      }
      if (param_1[7] == 0) {
        return 0;
      }
      if (*piVar25 != 5) {
        uVar11 = FUN_00b359d0(*(undefined8 *)(param_1 + 2),1,param_2);
        *(undefined8 *)(param_1 + 8) = uVar11;
        return 0;
      }
      if (*(long *)(piVar25 + 8) != 0) {
        *(long *)(param_1 + 8) = *(long *)(piVar25 + 8);
        piVar25[8] = 0;
        piVar25[9] = 0;
        return 0;
      }
      return 0;
    }
    lVar10 = *(long *)(piVar25 + 4);
    lVar15 = *(long *)(piVar25 + 2);
    lVar9 = thunk_FUN_00b2edc0();
    if (lVar9 == 0) {
      return -5;
    }
    uVar14 = (lVar10 - lVar15) * 2;
    *(int *)(lVar9 + 0x18) = piVar25[6];
    iVar7 = 1;
    goto LAB_00b39d30;
  case 6:
    iVar4 = param_1[2];
    if (iVar4 == 2) {
      uVar8 = *(undefined4 *)(param_2 + 0x50);
      uVar11 = *(undefined8 *)(param_1 + 6);
      *(int *)(param_2 + 0x50) = param_1[4];
      iVar4 = FUN_00b39aa0(uVar11,param_2,param_3,param_4);
      *(undefined4 *)(param_2 + 0x50) = uVar8;
      return iVar4;
    }
    if (iVar4 < 3) {
      if (iVar4 != 1) {
        return 0;
      }
      if ((param_3 & 0xb) != 0) {
        uVar18 = param_4[7] | 1 << (param_1[3] & 0x1fU);
        if (0x1f < param_1[3]) {
          uVar18 = param_4[7] | 1;
        }
        param_4[7] = uVar18;
      }
    }
    else {
      if (iVar4 == 4) {
        piVar25 = *(int **)(param_1 + 6);
        iVar4 = FUN_00b39aa0(piVar25,param_2,uVar24,param_4);
        if (*piVar25 != 5) {
          return iVar4;
        }
        if (piVar25[5] != -1) {
          return iVar4;
        }
        if (1 < piVar25[4]) {
          return iVar4;
        }
        if (piVar25[6] != 0) {
          if ((0x1fU >> (**(uint **)(piVar25 + 2) & 0x1f) & 1) != 0) {
            param_1[1] = param_1[1] | 0x40;
            return iVar4;
          }
          return iVar4;
        }
        return iVar4;
      }
      if (iVar4 != 8) {
        return 0;
      }
      if ((((*(byte *)((long)param_1 + 5) & 8) == 0) && (0 < (int)param_4[0x19])) &&
         (((*(byte *)(*(long *)(param_4 + 4) + 8) & 0x80) != 0 && ((*param_4 & 0x100) == 0)))) {
        return -0xd1;
      }
    }
    uVar11 = *(undefined8 *)(param_1 + 6);
    goto LAB_00b39efa;
  case 7:
    iVar4 = param_1[1];
    if (iVar4 == 0x800) {
LAB_00b39eb0:
      iVar4 = FUN_00b39aa0(*(undefined8 *)(param_1 + 2),param_2,uVar24 | 2,param_4);
      return iVar4;
    }
    if (iVar4 < 0x801) {
      if (iVar4 != 0x400) {
        return 0;
      }
      goto LAB_00b39f3b;
    }
    if (iVar4 == 0x1000) goto LAB_00b3a090;
    if (iVar4 != 0x2000) {
      return 0;
    }
    iVar4 = FUN_00b345b0(*(undefined8 *)(param_1 + 2),0x7ef,2,0x133e7);
    if (iVar4 < 0) {
      return iVar4;
    }
    if (iVar4 != 0) {
      return -0x7a;
    }
    iVar4 = FUN_00b37540(param_1,param_2,param_4 + 4);
    if (iVar4 != 0) {
      return iVar4;
    }
    if (*param_1 == 7) goto LAB_00b39eb0;
    goto LAB_00b39ac5;
  case 8:
    local_68 = 0;
    piVar25 = (int *)0x0;
    goto LAB_00b39b12;
  case 9:
    do {
      iVar4 = FUN_00b39aa0(*(undefined8 *)(param_1 + 2),param_2,uVar24 | 1,param_4);
      if (iVar4 != 0) {
        return iVar4;
      }
      param_1 = *(int **)(param_1 + 4);
    } while (param_1 != (int *)0x0);
  }
  return 0;
LAB_00b39b12:
  iVar4 = FUN_00b39aa0(*(undefined8 *)(param_1 + 2),param_2,param_3,param_4);
  if ((piVar25 != (int *)0x0) && (iVar4 == 0)) {
    iVar4 = *piVar25;
    piVar13 = *(int **)(param_1 + 2);
    if (iVar4 != 5) {
      do {
        if ((iVar4 != 6) || (piVar25[2] != 1)) goto LAB_00b39b7d;
        piVar25 = *(int **)(piVar25 + 6);
        iVar4 = *piVar25;
      } while (iVar4 != 5);
      local_68 = 0;
    }
    if ((piVar25[6] == 0) || (piVar25[5] != -1)) goto LAB_00b39b7d;
    lVar10 = FUN_00b359d0(piVar13,1,param_2);
    if ((lVar10 != 0) && (**(char **)(lVar10 + 8) != '\0')) {
      *(long *)(piVar25 + 10) = lVar10;
    }
    if ((((piVar25[4] < 2) && ((0x1fU >> (**(uint **)(piVar25 + 2) & 0x1f) & 1) != 0)) &&
        (piVar12 = (int *)FUN_00b359d0(*(uint **)(piVar25 + 2),0,param_2), piVar12 != (int *)0x0))
       && (piVar13 = (int *)FUN_00b359d0(piVar13,0,param_2), piVar13 != (int *)0x0)) {
      do {
        while( true ) {
          piVar26 = piVar13;
          piVar13 = piVar12;
          iVar4 = *piVar13;
          iVar7 = *piVar26;
          piVar12 = piVar26;
          if (iVar4 != 1) break;
          if (iVar7 == 1) {
            iVar4 = 0;
            uVar24 = piVar13[1] & 1;
            goto LAB_00b3a4be;
          }
          if (iVar7 == 2) {
            if (piVar26[1] != 0xc) goto LAB_00b39f94;
            if (piVar26[2] != 0) {
              iVar4 = 1;
              goto LAB_00b3a5b8;
            }
            if ((*(long *)(piVar13 + 10) != 0) || (uVar24 = 0, (piVar13[1] & 1U) != 0))
            goto LAB_00b39f94;
            goto LAB_00b3a470;
          }
          if (iVar7 != 0) goto LAB_00b39f94;
        }
        if (iVar4 != 2) {
          if (iVar4 != 0) goto LAB_00b39f94;
          lVar10 = *(long *)(piVar13 + 2);
          if (*(long *)(piVar13 + 4) == lVar10) goto LAB_00b39f94;
          if (iVar7 == 1) {
            uVar8 = (**(code **)(*(long *)(param_2 + 0x48) + 0x30))
                              (lVar10,*(int *)(*(long *)(param_2 + 0x48) + 0x18) + lVar10);
            iVar4 = FUN_00b39a60(*(undefined8 *)(param_2 + 0x48),uVar8,piVar26);
            uVar24 = (uint)(iVar4 == 0);
          }
          else {
            if (iVar7 != 2) {
              if (((iVar7 != 0) || ((*(byte *)(piVar13 + 6) & 2) != 0)) ||
                 ((*(byte *)(piVar26 + 6) & 2) != 0)) goto LAB_00b39f94;
              uVar14 = 0;
              uVar21 = *(long *)(piVar13 + 4) - lVar10;
              uVar19 = *(long *)(piVar26 + 4) - *(long *)(piVar26 + 2);
              goto LAB_00b3a27b;
            }
            if (piVar26[1] != 0xc) goto LAB_00b39f94;
            pcVar2 = *(code **)(*(long *)(param_2 + 0x48) + 0x30);
            if (piVar26[3] == 0) {
              pcVar3 = *(code **)(*(long *)(param_2 + 0x48) + 0x78);
              uVar8 = (*pcVar2)();
              iVar4 = (*pcVar3)(uVar8,0xc);
            }
            else {
              uVar8 = (*pcVar2)();
              iVar4 = FUN_00b43940(uVar8,0xc);
            }
            if (iVar4 == 0) {
              uVar24 = (uint)(piVar26[2] == 0);
            }
            else {
              uVar24 = piVar26[2];
            }
          }
          if (uVar24 == 0) goto LAB_00b39f94;
          goto LAB_00b3a29d;
        }
        if (iVar7 < 0) goto LAB_00b39f94;
      } while (iVar7 < 2);
      if (((iVar7 != 2) || (piVar26[1] != piVar13[1])) ||
         ((piVar26[2] == piVar13[2] || (piVar26[3] != piVar13[3])))) goto LAB_00b39f94;
      goto LAB_00b3a29d;
    }
    goto LAB_00b39f94;
  }
  piVar13 = *(int **)(param_1 + 2);
  if (iVar4 != 0) {
    return iVar4;
  }
  goto LAB_00b39b7d;
  while (pcVar1 = (char *)(*(long *)(piVar26 + 2) + uVar14), uVar14 = uVar14 + 1,
        *pcVar1 == *(char *)(lVar10 + -1 + uVar14)) {
LAB_00b3a27b:
    uVar16 = uVar21;
    if (uVar19 <= uVar21) {
      uVar16 = uVar19;
    }
    if (uVar16 <= uVar14) goto LAB_00b39f94;
  }
LAB_00b3a29d:
  lVar10 = thunk_FUN_00b2c120(4);
  if (lVar10 == 0) {
    return -5;
  }
  *(uint *)(lVar10 + 4) = *(uint *)(lVar10 + 4) | 0x40;
  FUN_00b33a40(piVar25,lVar10);
  *(long *)(piVar25 + 6) = lVar10;
  goto LAB_00b39f94;
LAB_00b3a4be:
  do {
    uVar18 = 1 << ((byte)iVar4 & 0x1f);
    if ((piVar13[(long)(iVar4 >> 5) + 2] & uVar18) == 0) {
      if (uVar24 != 0) goto LAB_00b3a4a1;
    }
    else if (uVar24 == 0) {
LAB_00b3a4a1:
      if ((piVar26[(long)(iVar4 >> 5) + 2] & uVar18) == 0) {
        if ((*(byte *)(piVar26 + 1) & 1) != 0) goto LAB_00b39f94;
      }
      else if ((*(byte *)(piVar26 + 1) & 1) == 0) goto LAB_00b39f94;
    }
    iVar4 = iVar4 + 1;
  } while (iVar4 != 0x100);
  if (((*(long *)(piVar13 + 10) == 0) && ((piVar13[1] & 1U) == 0)) ||
     ((*(long *)(piVar26 + 10) == 0 && ((*(byte *)(piVar26 + 1) & 1) == 0)))) goto LAB_00b3a29d;
LAB_00b39f94:
  if ((((*piVar25 == 5) && (local_68 != 0)) && (**(int **)(piVar25 + 2) == 3)) &&
     ((*(byte *)(param_2 + 0x50) & 4) == 0)) {
    lVar10 = thunk_FUN_00b2c0d0(0,0);
    if (lVar10 != 0) {
      FUN_00b33a40(piVar25,lVar10);
      lVar15 = thunk_FUN_00b2c0d0(lVar10,0);
      *(long *)(piVar25 + 4) = lVar15;
      if (lVar15 == 0) {
        thunk_FUN_00b2d8d0(lVar10);
      }
      else {
        lVar10 = FUN_00b2ebf0(0x4000);
        if (lVar10 != 0) {
          *(long *)(piVar25 + 2) = lVar10;
          goto LAB_00b39f9f;
        }
      }
    }
    return -5;
  }
LAB_00b39f9f:
  piVar13 = *(int **)(param_1 + 2);
LAB_00b39b7d:
  local_68 = param_3 & 0x10;
  param_3 = param_3 & 0xffffffef;
  param_1 = *(int **)(param_1 + 4);
  piVar25 = piVar13;
  if (param_1 == (int *)0x0) {
    return 0;
  }
  goto LAB_00b39b12;
LAB_00b3a5b8:
  uVar24 = iVar4 - 1;
  if (piVar26[3] == 0) {
    iVar7 = (**(code **)(*(long *)(param_2 + 0x48) + 0x78))(uVar24,0xc);
    if (iVar7 == 0) {
LAB_00b3a586:
      uVar24 = 1 << ((byte)uVar24 & 0x1f) & piVar13[(long)((int)uVar24 >> 5) + 2];
      if ((*(byte *)(piVar13 + 1) & 1) == 0) {
        if (uVar24 != 0) goto LAB_00b39f94;
      }
      else if (uVar24 == 0) goto LAB_00b39f94;
    }
    if (iVar4 == 0x100) goto LAB_00b3a29d;
  }
  else if ((0x7f < uVar24) ||
          (iVar7 = (**(code **)(*(long *)(param_2 + 0x48) + 0x78))(uVar24,0xc), iVar7 == 0))
  goto LAB_00b3a586;
  iVar4 = iVar4 + 1;
  goto LAB_00b3a5b8;
LAB_00b3a470:
  if ((piVar13[(long)((int)uVar24 >> 5) + 2] & 1 << ((byte)uVar24 & 0x1f)) == 0) {
LAB_00b3a52e:
    if (uVar24 == 0xff) goto LAB_00b3a29d;
  }
  else {
    if (piVar26[3] == 0) {
      iVar4 = (**(code **)(*(long *)(param_2 + 0x48) + 0x78))(uVar24,0xc);
      if (iVar4 == 0) goto LAB_00b3a52e;
      goto LAB_00b39f94;
    }
    if (0x7f < uVar24) goto LAB_00b3a52e;
    iVar4 = (**(code **)(*(long *)(param_2 + 0x48) + 0x78))(uVar24,0xc);
    if (iVar4 != 0) goto LAB_00b39f94;
  }
  uVar24 = uVar24 + 1;
  goto LAB_00b3a470;
LAB_00b3a090:
  iVar4 = FUN_00b345b0(*(undefined8 *)(param_1 + 2),0x7ef,3,0x133e7);
  if (iVar4 < 0) {
    return iVar4;
  }
  if (iVar4 != 0) {
    return -0x7a;
  }
  iVar4 = FUN_00b37540(param_1,param_2,param_4 + 4);
  if (iVar4 != 0) {
    return iVar4;
  }
  if (*param_1 == 7) {
LAB_00b39f3b:
    uVar11 = *(undefined8 *)(param_1 + 2);
LAB_00b39efa:
    iVar4 = FUN_00b39aa0(uVar11,param_2,uVar24,param_4);
    return iVar4;
  }
  goto LAB_00b39ac5;
  while( true ) {
    iVar6 = FUN_00b2ec50(lVar9,*(undefined8 *)(piVar25 + 2),*(undefined8 *)(piVar25 + 4));
    if (iVar6 != 0) {
      thunk_FUN_00b2d8d0(lVar9);
      return iVar6;
    }
    uVar14 = uVar14 + (lVar10 - lVar15);
    iVar6 = iVar4;
    if (iVar4 == iVar7) break;
LAB_00b39d30:
    iVar6 = iVar7;
    iVar7 = iVar6 + 1;
    if (100 < uVar14) break;
  }
  iVar4 = param_1[5];
  if (iVar6 < iVar4) {
    param_1[4] = param_1[4] - iVar6;
    param_1[5] = iVar4 - iVar6;
  }
  else {
    if (iVar4 != -1) {
      FUN_00b33a40(lVar9,param_1);
      thunk_FUN_00b2d8d0();
      return 0;
    }
    param_1[4] = param_1[4] - iVar6;
  }
  lVar10 = thunk_FUN_00b2c0d0(lVar9,0);
  if (lVar10 == 0) {
    thunk_FUN_00b2d8d0(lVar9);
    return -5;
  }
  FUN_00b33a40(lVar10,param_1);
  lVar15 = FUN_00b2eb60(param_1,lVar10);
  if (lVar15 == 0) {
    thunk_FUN_00b2d8d0(lVar10);
    return -5;
  }
  return 0;
}


// ==== entry=00b3a6a0 name=FUN_00b3a6a0 size=2368 ====

int FUN_00b3a6a0(undefined8 *param_1,long param_2,long param_3,undefined8 *param_4)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  void *pvVar5;
  int *piVar6;
  long lVar7;
  size_t sVar8;
  long lVar9;
  ulong __size;
  long *plVar10;
  uint uVar11;
  undefined8 uVar12;
  undefined8 local_340;
  int local_338;
  int local_334;
  int *local_330;
  undefined8 local_328;
  undefined8 local_320;
  undefined8 local_318;
  uint local_310;
  undefined4 local_30c;
  long *local_308;
  long local_2f8 [3];
  uint local_2e0;
  uint local_2dc;
  uint local_2d8;
  long local_2c0;
  undefined8 local_2b8;
  int local_2a8;
  int *local_2a0;
  int local_298;
  int local_294;
  void *local_248;
  undefined8 local_238;
  long local_230;
  uint local_228;
  uint local_224;
  long local_220;
  undefined8 local_218;
  uint local_210;
  uint local_20c;
  int local_204;
  int local_200;
  undefined1 local_1fc [28];
  undefined1 local_1e0 [32];
  int local_1c0;
  long local_160;
  undefined8 local_158;
  uint local_150;
  uint local_14c;
  int local_148;
  undefined1 local_144 [276];
  
  plVar10 = local_2f8;
  for (lVar7 = 0x17; lVar7 != 0; lVar7 = lVar7 + -1) {
    *plVar10 = 0;
    plVar10 = plVar10 + 1;
  }
  if (param_4 != (undefined8 *)0x0) {
    param_4[1] = 0;
  }
  *(undefined4 *)(param_1 + 2) = 0xffffffff;
  if (*(int *)((long)param_1 + 0xc) == 0) {
    sVar8 = (param_3 - param_2) * 2;
    if (sVar8 == 0) {
      sVar8 = 0x14;
    }
    pvVar5 = malloc(sVar8);
    *param_1 = pvVar5;
    if (pvVar5 == (void *)0x0) {
      iVar2 = -5;
      goto LAB_00b3aa02;
    }
    *(int *)((long)param_1 + 0xc) = (int)sVar8;
    *(undefined4 *)(param_1 + 1) = 0;
  }
  else {
    *(undefined4 *)(param_1 + 1) = 0;
  }
  *(undefined4 *)((long)param_1 + 0x14) = 0;
  param_1[3] = 0;
  *(undefined4 *)(param_1 + 7) = 0;
  param_1[8] = 0;
  iVar2 = FUN_00b33860(&local_340,param_2,param_3,param_1,local_2f8);
  uVar12 = local_340;
  if (iVar2 != 0) goto LAB_00b3ab15;
  if (((0 < local_294) && ((*(byte *)(local_2f8[2] + 8) & 0x80) != 0)) &&
     ((*(byte *)((long)param_1 + 0x51) & 1) == 0)) {
    if (local_294 == local_298) {
      iVar2 = FUN_00b33c00(local_340);
    }
    else {
      iVar2 = FUN_00b34c30(&local_340,param_1,local_2f8);
      uVar12 = local_340;
    }
    if (iVar2 != 0) goto LAB_00b3ab15;
  }
  iVar2 = local_2a8;
  if (local_2a8 < 1) {
    *(undefined4 *)((long)param_1 + 0x24) = 0;
LAB_00b3a793:
    iVar2 = FUN_00b39aa0(uVar12,param_1,0x10,local_2f8);
    if (iVar2 != 0) goto LAB_00b3aa30;
    uVar11 = 0xffffffff;
    *(uint *)(param_1 + 5) = local_2e0;
    *(uint *)((long)param_1 + 0x2c) = local_2dc | local_2e0;
    local_310 = *(uint *)(param_1 + 10);
    if ((local_310 & 0x30) == 0) {
      uVar11 = local_2d8 | local_2e0;
    }
    *(uint *)(param_1 + 6) = uVar11;
    param_1[0x10] = 0;
    param_1[0x11] = 0;
    *(undefined4 *)(param_1 + 0x12) = 0;
    param_1[0x14] = 0;
    param_1[0xe] = 0;
    *(undefined4 *)(param_1 + 0xf) = 0;
    if ((void *)param_1[0x13] != (void *)0x0) {
      free((void *)param_1[0x13]);
      local_310 = *(uint *)(param_1 + 10);
      param_1[0x13] = 0;
    }
    local_318 = param_1[9];
    local_30c = *(undefined4 *)(param_1 + 0xc);
    local_320 = 0;
    local_328 = 0;
    local_308 = local_2f8;
    iVar2 = FUN_00b35ff0(local_340,&local_238,&local_328);
    if (iVar2 != 0) goto LAB_00b3aa30;
    *(uint *)(param_1 + 0xf) = local_228 & 0xd005 | local_224 & 0x18;
    if ((local_224 & 0x18) != 0) {
      param_1[0x10] = local_238;
      param_1[0x11] = local_230;
    }
    if ((local_200 < 1) && (local_1c0 < 1)) {
      uVar11 = *(uint *)(param_1 + 0x12);
      if (local_148 < 1) {
        uVar11 = local_228 & 2 | uVar11;
        *(uint *)(param_1 + 0x12) = uVar11;
        if (local_230 == 0) {
          *(uint *)(param_1 + 0x12) = uVar11 | local_224 & 0x20;
        }
      }
      else {
LAB_00b3ad96:
        lVar7 = 0;
        do {
          *(undefined1 *)((long)param_1 + lVar7 + 0xa8) = local_144[lVar7];
          lVar7 = lVar7 + 1;
        } while (lVar7 != 0x100);
        *(undefined4 *)(param_1 + 0xe) = 5;
        param_1[0x37] = local_160;
        param_1[0x38] = local_158;
        if (local_160 != -1) {
          *(int *)((long)param_1 + 0x74) = (int)local_160 + 1;
        }
        *(uint *)(param_1 + 0x12) = local_150 & 2 | local_14c & 0x20 | uVar11;
      }
    }
    else {
      FUN_00b35b60(param_1[9],&local_220,local_1e0);
      iVar2 = local_200;
      sVar8 = (size_t)local_200;
      if (0 < local_148) {
        iVar3 = local_200;
        if (local_204 < 1) {
          iVar3 = local_200 * 2;
        }
        if (((int)(200 / (long)local_148) != 0) &&
           ((iVar3 * 0x14 < 1 ||
            (iVar3 = FUN_00b35ad0(&local_220,&local_160,iVar3 * 0x14,
                                  200 / (long)local_148 & 0xffffffff), 0 < iVar3)))) {
          uVar11 = *(uint *)(param_1 + 0x12);
          goto LAB_00b3ad96;
        }
      }
      if (iVar2 != 0) {
        pvVar5 = malloc(sVar8);
        param_1[0x13] = pvVar5;
        if (pvVar5 == (void *)0x0) {
          iVar2 = -5;
          goto LAB_00b3aa13;
        }
        pvVar5 = memcpy(pvVar5,local_1fc,sVar8);
        param_1[0x14] = (long)pvVar5 + sVar8;
        iVar3 = (**(code **)(param_1[9] + 0x98))(pvVar5);
        if (local_204 < 1) {
          if (local_200 < 3) {
            if ((local_200 == 2) && (iVar3 != 0)) {
              iVar2 = FUN_00b37120(param_1[0x13],param_1[0x14],param_1[9],param_1 + 0xc,
                                   param_1 + 0x15,param_1 + 0x35,0);
              if (iVar2 == 0) goto LAB_00b3af85;
LAB_00b3aa13:
              *(uint *)(param_1 + 0x12) =
                   *(uint *)(param_1 + 0x12) | local_20c & 0x20 | local_210 & 2;
              goto LAB_00b3aa30;
            }
            *(undefined4 *)(param_1 + 0xe) = 1;
          }
          else {
            iVar2 = FUN_00b37120(param_1[0x13],param_1[0x14],param_1[9],param_1 + 0xc,param_1 + 0x15
                                 ,param_1 + 0x35,0);
            if (iVar2 != 0) goto LAB_00b3aa13;
            uVar4 = 3;
            if (iVar3 == 0) goto LAB_00b3af37;
LAB_00b3af85:
            uVar4 = 2;
LAB_00b3af37:
            *(undefined4 *)(param_1 + 0xe) = uVar4;
          }
        }
        else {
          if (local_200 < 3) {
            if (((local_200 == 2) && (iVar3 != 0)) &&
               (iVar2 = FUN_00b37120(param_1[0x13],param_1[0x14],param_1[9],param_1 + 0xc,
                                     param_1 + 0x15,param_1 + 0x35,1), iVar2 == 0)) {
LAB_00b3afc5:
              uVar4 = 6;
              goto LAB_00b3af37;
            }
          }
          else {
            iVar2 = FUN_00b37120(param_1[0x13],param_1[0x14],param_1[9],param_1 + 0xc,param_1 + 0x15
                                 ,param_1 + 0x35,1);
            if (iVar2 == 0) {
              uVar4 = 7;
              if (iVar3 == 0) goto LAB_00b3af37;
              goto LAB_00b3afc5;
            }
          }
          *(undefined4 *)(param_1 + 0xe) = 4;
        }
        param_1[0x37] = local_220;
        param_1[0x38] = local_218;
        if (local_220 != -1) {
          *(int *)((long)param_1 + 0x74) =
               ((int)param_1[0x14] - (int)param_1[0x13]) + (int)local_220;
        }
      }
      *(uint *)(param_1 + 0x12) = *(uint *)(param_1 + 0x12) | local_210 & 2 | local_20c & 0x20;
    }
    if (local_248 != (void *)0x0) {
      free(local_248);
      local_248 = (void *)0x0;
    }
    if ((*(byte *)((long)param_1 + 0x52) & 1) != 0) {
      FUN_00b351c0(param_1,0x21);
    }
    iVar2 = FUN_00b37ee0(local_340,param_1);
    if (iVar2 != 0) {
      if ((0 < local_2a8) && (local_330 != (int *)0x0)) {
        free(local_330);
      }
LAB_00b3a9f8:
      thunk_FUN_00b2d8d0(local_340);
LAB_00b3aa02:
      *(undefined4 *)(param_1 + 2) = 0;
      return iVar2;
    }
    if ((*(byte *)((long)param_1 + 0x52) & 1) != 0) {
      FUN_00b351c0(param_1,0x22);
    }
    iVar2 = FUN_00b351c0(param_1,1);
    if (local_2a8 < 1) {
LAB_00b3a9e2:
      if ((*(int *)(param_1 + 3) == 0) && (*(int *)(param_1 + 6) == 0)) {
        if (*(int *)((long)param_1 + 0x2c) == 0) {
          *(undefined4 *)((long)param_1 + 0x34) = 0;
        }
        else {
          *(undefined4 *)((long)param_1 + 0x34) = 1;
        }
      }
      else {
        *(undefined4 *)((long)param_1 + 0x34) = 2;
      }
      goto LAB_00b3a9f8;
    }
    if (local_338 < 1) {
LAB_00b3aec0:
      if (local_330 != (int *)0x0) {
        free(local_330);
      }
      iVar2 = 0;
      goto LAB_00b3a9e2;
    }
    lVar7 = *(long *)(local_330 + 2);
    if ((*(byte *)(lVar7 + 5) & 2) == 0) {
      iVar2 = -0xb;
      free(local_330);
      uVar12 = local_340;
      goto LAB_00b3ab15;
    }
    lVar9 = 0;
    piVar6 = local_330;
    do {
      iVar2 = *piVar6;
      __size = (ulong)*(uint *)((long)param_1 + 0xc);
      uVar4 = *(undefined4 *)(lVar7 + 0x20);
      pvVar5 = (void *)*param_1;
      uVar11 = iVar2 + 4;
      if (*(uint *)((long)param_1 + 0xc) < uVar11) {
        do {
          uVar1 = (int)__size * 2;
          __size = (ulong)uVar1;
        } while (uVar1 < uVar11);
        *(uint *)((long)param_1 + 0xc) = uVar1;
        pvVar5 = realloc(pvVar5,__size);
        *param_1 = pvVar5;
        if (pvVar5 == (void *)0x0) {
          iVar2 = -5;
          goto joined_r0x00b3aa47;
        }
      }
      *(undefined4 *)((long)pvVar5 + (long)iVar2) = uVar4;
      if (*(uint *)(param_1 + 1) < uVar11) {
        *(uint *)(param_1 + 1) = uVar11;
      }
      if (local_338 <= (int)lVar9 + 1) goto LAB_00b3aec0;
      lVar9 = lVar9 + 1;
      piVar6 = local_330 + lVar9 * 4;
      lVar7 = *(long *)(piVar6 + 2);
    } while ((*(byte *)(lVar7 + 5) & 2) != 0);
    iVar2 = -0xb;
  }
  else {
    piVar6 = malloc((long)local_2a8 << 4);
    if (piVar6 == (int *)0x0) {
      iVar2 = -5;
      goto LAB_00b3ab15;
    }
    local_2a0 = &local_338;
    local_334 = iVar2;
    local_338 = 0;
    local_330 = piVar6;
    iVar2 = FUN_00b34da0(uVar12,local_2f8);
    if (((iVar2 == 0) && (iVar2 = FUN_00b349c0(local_340,local_2f8), -1 < iVar2)) &&
       (iVar2 = FUN_00b34810(local_340,local_2f8), iVar2 == 0)) {
      *(int *)((long)param_1 + 0x24) = local_2a8;
      uVar12 = local_340;
      goto LAB_00b3a793;
    }
LAB_00b3aa30:
    uVar12 = local_340;
    if (local_2a8 < 1) goto LAB_00b3ab15;
  }
joined_r0x00b3aa47:
  uVar12 = local_340;
  if (local_330 != (int *)0x0) {
    free(local_330);
    uVar12 = local_340;
  }
LAB_00b3ab15:
  if ((local_2c0 != 0) && (param_4 != (undefined8 *)0x0)) {
    param_4[1] = local_2c0;
    *param_4 = local_2f8[1];
    param_4[2] = local_2b8;
  }
  thunk_FUN_00b2d8d0(uVar12);
  if (local_248 != (void *)0x0) {
    free(local_248);
  }
  return iVar2;
}


// ==== entry=00b3b030 name=FUN_00b3b030 size=85 ====

void FUN_00b3b030(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
                 undefined8 param_5,undefined8 param_6,undefined8 param_7)

{
  int iVar1;
  
  iVar1 = FUN_00b39830(param_1,param_4,DAT_011becc8,param_5,param_6);
  if (iVar1 != 0) {
    return;
  }
  FUN_00b3a6a0(param_1,param_2,param_3,param_7);
  return;
}


// ==== entry=00b3b090 name=FUN_00b3b090 size=174 ====

ulong FUN_00b3b090(undefined8 *param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
                  undefined8 param_5,undefined8 param_6,undefined8 param_7)

{
  void *pvVar1;
  ulong uVar2;
  
  pvVar1 = malloc(0x1d0);
  *param_1 = pvVar1;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0xfffffffb;
  }
  else {
    uVar2 = FUN_00b39830(pvVar1,param_4,DAT_011becc8,param_5,param_6);
    if ((int)uVar2 == 0) {
      uVar2 = FUN_00b3a6a0(*param_1,param_2,param_3,param_7);
      if ((int)uVar2 == 0) {
        return uVar2;
      }
    }
    pvVar1 = (void *)*param_1;
    if (pvVar1 != (void *)0x0) {
      FUN_00b395a0(pvVar1);
      free(pvVar1);
      uVar2 = uVar2 & 0xffffffff;
    }
    *param_1 = 0;
  }
  return uVar2;
}


// ==== entry=00b3b150 name=FUN_00b3b150 size=61 ====

void FUN_00b3b150(void)

{
  undefined4 *puVar1;
  
  puVar1 = malloc(0x28);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = 0xffffffff;
    *(undefined8 *)(puVar1 + 2) = 0xffffffffffffffff;
    *(undefined8 *)(puVar1 + 4) = 0xffffffffffffffff;
    *(undefined8 *)(puVar1 + 6) = 0;
    *(undefined8 *)(puVar1 + 8) = 0;
  }
  return;
}


// ==== entry=00b3b190 name=FUN_00b3b190 size=198 ====

undefined8
FUN_00b3b190(undefined8 param_1,undefined8 *param_2,undefined4 param_3,long param_4,long *param_5,
            long param_6)

{
  long lVar1;
  char *pcVar2;
  char *pcVar3;
  int iVar4;
  int iVar5;
  long lVar6;
  long local_90 [2];
  long local_80;
  char local_78 [32];
  char local_58 [40];
  
  local_80 = *param_5;
  lVar1 = local_80 + param_6;
  local_90[0] = param_4;
  while( true ) {
    if (param_4 + param_6 <= local_90[0]) {
      *param_5 = local_80;
      return 1;
    }
    iVar4 = (*(code *)*param_2)(param_1,param_3,local_90,param_4 + param_6,local_78);
    iVar5 = (*(code *)*param_2)(param_1,param_3,&local_80,lVar1,local_58);
    if (iVar4 != iVar5) break;
    if (0 < iVar4) {
      if (local_58[0] != local_78[0]) {
        return 0;
      }
      lVar6 = 1;
      while (lVar6 != (ulong)(iVar4 - 1) + 1) {
        pcVar2 = local_78 + lVar6;
        pcVar3 = local_58 + lVar6;
        lVar6 = lVar6 + 1;
        if (*pcVar2 != *pcVar3) {
          return 0;
        }
      }
    }
  }
  return 0;
}


// ==== entry=00b3b260 name=FUN_00b3b260 size=147 ====

void FUN_00b3b260(undefined4 *param_1)

{
  int iVar1;
  void *__ptr;
  undefined8 *puVar2;
  long lVar3;
  undefined8 *__ptr_00;
  
  if (param_1 != (undefined4 *)0x0) {
    __ptr_00 = *(undefined8 **)(param_1 + 8);
    if (0 < (int)param_1[7]) {
      lVar3 = 0;
      do {
        __ptr = (void *)__ptr_00[lVar3];
        if (__ptr != (void *)0x0) {
          FUN_00b3b260(__ptr);
          free(__ptr);
          __ptr_00 = *(undefined8 **)(param_1 + 8);
        }
        lVar3 = lVar3 + 1;
      } while ((int)lVar3 < (int)param_1[7]);
    }
    iVar1 = param_1[6];
    if (0 < iVar1) {
      puVar2 = __ptr_00;
      do {
        *puVar2 = 0;
        puVar2 = puVar2 + 1;
      } while (puVar2 != __ptr_00 + (ulong)(iVar1 - 1) + 1);
    }
    param_1[7] = 0;
    *(undefined8 *)(param_1 + 2) = 0xffffffffffffffff;
    *(undefined8 *)(param_1 + 4) = 0xffffffffffffffff;
    *param_1 = 0xffffffff;
    free(__ptr_00);
    *(undefined8 *)(param_1 + 8) = 0;
    return;
  }
  return;
}


// ==== entry=00b3b300 name=FUN_00b3b300 size=197 ====

undefined8 FUN_00b3b300(long param_1,undefined8 param_2)

{
  void *__ptr;
  undefined8 *puVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar2 = *(int *)(param_1 + 0x1c);
  iVar3 = *(int *)(param_1 + 0x18);
  __ptr = *(void **)(param_1 + 0x20);
  if (iVar3 <= iVar2) {
    if (__ptr == (void *)0x0) {
      __ptr = malloc(0x40);
      *(void **)(param_1 + 0x20) = __ptr;
      if (__ptr == (void *)0x0) {
        return 0xfffffffb;
      }
      iVar4 = 8;
    }
    else {
      iVar4 = iVar3 * 2;
      __ptr = realloc(__ptr,(long)iVar4 << 3);
      if (__ptr == (void *)0x0) {
        FUN_00b3b260(param_1);
        return 0xfffffffb;
      }
      iVar3 = *(int *)(param_1 + 0x18);
      iVar2 = *(int *)(param_1 + 0x1c);
      *(void **)(param_1 + 0x20) = __ptr;
    }
    if (iVar3 < iVar4) {
      puVar1 = (undefined8 *)((long)__ptr + (long)iVar3 * 8);
      do {
        *puVar1 = 0;
        puVar1 = puVar1 + 1;
      } while ((undefined8 *)
               ((long)__ptr + ((ulong)(uint)((iVar4 + -1) - iVar3) + (long)iVar3) * 8 + 8) != puVar1
              );
    }
    *(int *)(param_1 + 0x18) = iVar4;
  }
  *(undefined8 *)((long)__ptr + (long)iVar2 * 8) = param_2;
  *(int *)(param_1 + 0x1c) = iVar2 + 1;
  return 0;
}


// ==== entry=00b3b3d0 name=FUN_00b3b3d0 size=166 ====

void * FUN_00b3b3d0(long param_1)

{
  int iVar1;
  void *__ptr;
  void *__ptr_00;
  long lVar2;
  
  __ptr = (void *)FUN_00b3b150();
  if (__ptr != (void *)0x0) {
    *(undefined8 *)((long)__ptr + 8) = *(undefined8 *)(param_1 + 8);
    *(undefined8 *)((long)__ptr + 0x10) = *(undefined8 *)(param_1 + 0x10);
    if (0 < *(int *)(param_1 + 0x1c)) {
      lVar2 = 0;
      do {
        __ptr_00 = (void *)FUN_00b3b3d0(*(undefined8 *)(*(long *)(param_1 + 0x20) + lVar2 * 8));
        if (__ptr_00 == (void *)0x0) {
LAB_00b3b458:
          FUN_00b3b260(__ptr);
          free(__ptr);
          return (void *)0x0;
        }
        iVar1 = FUN_00b3b300(__ptr,__ptr_00);
        if (iVar1 != 0) {
          FUN_00b3b260(__ptr_00);
          free(__ptr_00);
          goto LAB_00b3b458;
        }
        lVar2 = lVar2 + 1;
      } while ((int)lVar2 < *(int *)(param_1 + 0x1c));
    }
  }
  return __ptr;
}


// ==== entry=00b3b480 name=FUN_00b3b480 size=326 ====

ulong FUN_00b3b480(int *param_1,long *param_2,int *param_3,long param_4,long param_5)

{
  int iVar1;
  uint uVar2;
  int *__ptr;
  ulong uVar3;
  int *piVar4;
  
  piVar4 = (int *)*param_2;
  do {
    while( true ) {
      if (param_3 <= piVar4) {
        return 1;
      }
      if (*piVar4 == 0x100) break;
      if ((*piVar4 == 0x8200) && (piVar4[2] == *param_1)) {
        *(long *)(param_1 + 4) = *(long *)(piVar4 + 4) - param_4;
        *param_2 = (long)piVar4;
        return 0;
      }
LAB_00b3b4bb:
      piVar4 = piVar4 + 10;
    }
    iVar1 = piVar4[2];
    if ((0x1f < iVar1) || ((*(uint *)(param_5 + 0x28) & 1 << ((byte)iVar1 & 0x1f)) == 0))
    goto LAB_00b3b4bb;
    __ptr = (int *)FUN_00b3b150();
    if (__ptr == (int *)0x0) {
      return 0xfffffffb;
    }
    *__ptr = iVar1;
    *(long *)(__ptr + 2) = *(long *)(piVar4 + 4) - param_4;
    uVar2 = FUN_00b3b300(param_1,__ptr);
    if (uVar2 != 0) {
      FUN_00b3b260(__ptr);
      free(__ptr);
      return (ulong)uVar2;
    }
    *param_2 = (long)(piVar4 + 10);
    uVar3 = FUN_00b3b480(__ptr,param_2,param_3,param_4,param_5);
    if ((int)uVar3 != 0) {
      return uVar3;
    }
    piVar4 = (int *)(*param_2 + 0x28);
    *(long *)(__ptr + 4) = *(long *)(*param_2 + 0x10) - param_4;
  } while( true );
}


// ==== entry=00b3b5d0 name=FUN_00b3b5d0 size=47 ====

void FUN_00b3b5d0(undefined8 *param_1)

{
  void *__ptr;
  
  __ptr = (void *)*param_1;
  if (__ptr != (void *)0x0) {
    FUN_00b3b260(__ptr);
    free(__ptr);
    *param_1 = 0;
  }
  return;
}


// ==== entry=00b3b600 name=FUN_00b3b600 size=269 ====

ulong FUN_00b3b600(undefined8 param_1,long param_2,long param_3,undefined8 param_4,long param_5,
                  uint param_6,int param_7)

{
  int iVar1;
  int iVar2;
  ulong uVar3;
  long lVar4;
  bool bVar5;
  
  if ((param_6 & 0x8000) == 0) {
                    /* WARNING: Could not recover jumptable at 0x00b3b6c8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar3 = (**(code **)(param_2 + 0x28))(param_1,param_3,param_5);
    return uVar3;
  }
  iVar1 = (**(code **)(param_2 + 0x38))(param_1,param_3,param_5);
  if (iVar1 == 10) {
    if ((param_7 != 0) && (lVar4 = FUN_00b43110(param_1,param_2,param_4,param_3), lVar4 != -1)) {
      iVar1 = (**(code **)(param_2 + 0x38))(param_1,lVar4,param_5);
      bVar5 = iVar1 != 0xd;
LAB_00b3b67e:
      return (ulong)bVar5;
    }
  }
  else {
    iVar1 = (**(code **)(param_2 + 8))(param_1,param_3);
    if (((param_5 <= iVar1 + param_3) ||
        (iVar2 = (**(code **)(param_2 + 0x38))(param_1,param_3,param_5), iVar2 != 0xd)) ||
       (iVar1 = (**(code **)(param_2 + 0x38))(param_1,iVar1 + param_3,param_5), iVar1 != 10)) {
      iVar1 = (**(code **)(param_2 + 0x28))(param_1,param_3,param_5);
      bVar5 = iVar1 != 0;
      goto LAB_00b3b67e;
    }
  }
  return 1;
}


// ==== entry=00b3b730 name=FUN_00b3b730 size=1395 ====

undefined8
FUN_00b3b730(undefined8 *param_1,long param_2,long param_3,long param_4,long param_5,long param_6,
            undefined8 param_7,long *param_8,long *param_9)

{
  undefined4 uVar1;
  long lVar2;
  undefined8 uVar3;
  byte bVar4;
  char cVar5;
  char cVar6;
  int iVar7;
  long lVar8;
  char *pcVar9;
  long lVar10;
  int *piVar11;
  int *piVar12;
  char *pcVar13;
  char *pcVar14;
  char *pcVar15;
  long local_60;
  char local_58;
  char local_57 [39];
  
  param_6 = param_6 + *(long *)(param_2 + 0x1b8);
  lVar8 = param_5 - param_6;
LAB_00b3b768:
  switch(*(undefined4 *)(param_2 + 0x70)) {
  case 1:
    pcVar14 = *(char **)(param_2 + 0xa0);
    pcVar13 = *(char **)(param_2 + 0x98);
LAB_00b3b95e:
    lVar10 = *(long *)(param_2 + 0x48);
    if (param_4 - ((long)pcVar14 - (long)pcVar13) <= param_5) {
      param_5 = (**(code **)(lVar10 + 0x90))(param_1,param_7);
    }
    if (param_5 < param_6) {
      return 0;
    }
    do {
      cVar6 = (*(code *)*param_1)(param_5,param_1[1]);
      if (cVar6 == *pcVar13) {
        pcVar15 = pcVar13 + 1;
        if (pcVar15 < pcVar14) {
          while (cVar6 = *pcVar15,
                cVar5 = (*(code *)*param_1)(pcVar15 + (param_5 - (long)pcVar13),param_1[1]),
                cVar6 == cVar5) {
            pcVar15 = pcVar15 + 1;
            if (pcVar15 == pcVar14) goto switchD_00b3b777_caseD_0;
          }
        }
        if (pcVar14 == pcVar15) goto switchD_00b3b777_caseD_0;
      }
      param_5 = FUN_00b43110(param_1,lVar10,param_7,param_5);
      if (param_5 < param_6) {
        return 0;
      }
    } while( true );
  case 2:
  case 3:
    pcVar14 = *(char **)(param_2 + 0xa0);
    pcVar13 = *(char **)(param_2 + 0x98);
    if (*(long *)(param_2 + 0x1b0) == 0) {
      if (lVar8 < 100) goto LAB_00b3b95e;
      piVar11 = malloc(0x400);
      *(int **)(param_2 + 0x1b0) = piVar11;
      if (piVar11 == (int *)0x0) {
        return 0xfffffffb;
      }
      piVar12 = piVar11;
      do {
        iVar7 = (int)((long)pcVar14 - (long)pcVar13);
        *piVar12 = iVar7;
        piVar12 = piVar12 + 1;
      } while (piVar12 != piVar11 + 0x100);
      iVar7 = iVar7 + -1;
      if (0 < iVar7) {
        lVar10 = (long)iVar7;
        do {
          piVar11[(byte)pcVar13[lVar10]] = (int)lVar10;
          lVar10 = lVar10 + -1;
        } while (0 < (int)lVar10);
      }
    }
    lVar10 = param_5;
    if (param_4 - ((long)pcVar14 - (long)pcVar13) <= param_5) {
      lVar10 = (**(code **)(*(long *)(param_2 + 0x48) + 0x90))(param_1,param_7);
    }
    while( true ) {
      if (lVar10 < param_6) {
        return 0;
      }
      pcVar15 = pcVar13;
      if (pcVar13 < pcVar14) {
        while (cVar6 = (*(code *)*param_1)(pcVar15 + (lVar10 - (long)pcVar13),param_1[1]),
              cVar6 == *pcVar15) {
          pcVar15 = pcVar15 + 1;
          if (pcVar14 == pcVar15) goto LAB_00b3b7f3;
        }
      }
      if (pcVar15 == pcVar14) break;
      lVar2 = *(long *)(param_2 + 0x1b0);
      bVar4 = (*(code *)*param_1)(lVar10,param_1[1]);
      lVar10 = (**(code **)(*(long *)(param_2 + 0x48) + 0x90))
                         (param_1,param_7,lVar10 - *(int *)(lVar2 + (ulong)bVar4 * 4));
    }
    break;
  case 4:
  case 6:
  case 7:
    uVar1 = *(undefined4 *)(param_2 + 0x60);
    pcVar14 = *(char **)(param_2 + 0xa0);
    pcVar13 = *(char **)(param_2 + 0x98);
    lVar10 = *(long *)(param_2 + 0x48);
    if (param_4 - ((long)pcVar14 - (long)pcVar13) <= param_5) {
      param_5 = (**(code **)(lVar10 + 0x90))(param_1,param_7);
    }
    if (param_5 < param_6) {
      return 0;
    }
LAB_00b3b8d0:
    pcVar15 = pcVar13;
    local_60 = param_5;
    if (pcVar13 < pcVar14) {
      do {
        iVar7 = (**(code **)(lVar10 + 0x58))(param_1,uVar1,&local_60,param_4,&local_58);
        if (0 < iVar7) {
          if (local_58 != *pcVar15) goto LAB_00b3bc80;
          pcVar9 = local_57;
          while (pcVar15 = pcVar15 + 1, pcVar9 != local_57 + (iVar7 - 1)) {
            cVar6 = *pcVar9;
            pcVar9 = pcVar9 + 1;
            if (*pcVar15 != cVar6) goto LAB_00b3bc80;
          }
        }
        if (pcVar14 <= pcVar15) break;
      } while( true );
    }
    goto switchD_00b3b777_caseD_0;
  case 5:
    uVar3 = *(undefined8 *)(param_2 + 0x48);
    while( true ) {
      if (param_5 < param_6) {
        return 0;
      }
      bVar4 = (*(code *)*param_1)(param_5,param_1[1]);
      if (*(char *)(param_2 + 0xa8 + (ulong)bVar4) != '\0') break;
      param_5 = FUN_00b43110(param_1,uVar3,param_7,param_5);
    }
  default:
switchD_00b3b777_caseD_0:
    lVar10 = param_5;
  }
LAB_00b3b7f3:
  if (lVar10 == -1) {
    return 0;
  }
  iVar7 = *(int *)(param_2 + 0x90);
  if (iVar7 != 0) {
    if (iVar7 != 2) {
      if (((iVar7 != 0x20) || (lVar10 == param_4)) ||
         (iVar7 = FUN_00b3b600(param_1,*(undefined8 *)(param_2 + 0x48),lVar10,param_3,param_4,
                               *(undefined4 *)(param_2 + 0x50),1), iVar7 != 0)) goto LAB_00b3bb50;
      param_5 = FUN_00b43110(param_1,*(undefined8 *)(param_2 + 0x48),param_7,lVar10);
      if (param_5 == -1) {
        return 0;
      }
      goto LAB_00b3b768;
    }
    if (lVar10 != param_3) {
      param_5 = FUN_00b43110(param_1,*(undefined8 *)(param_2 + 0x48),param_3,lVar10);
      iVar7 = FUN_00b3b600(param_1,*(undefined8 *)(param_2 + 0x48),param_5,param_3,param_4,
                           *(undefined4 *)(param_2 + 0x50),0);
      if (iVar7 != 0) goto LAB_00b3bb50;
      goto LAB_00b3b768;
    }
  }
LAB_00b3bb50:
  if (*(long *)(param_2 + 0x1c0) != -1) {
    lVar8 = *(long *)(param_2 + 0x1b8);
    uVar3 = *(undefined8 *)(param_2 + 0x48);
    *param_8 = lVar10 - *(long *)(param_2 + 0x1c0);
    *param_9 = lVar10 - lVar8;
    lVar8 = FUN_00b42fb0(param_1,uVar3,param_7);
    *param_9 = lVar8;
    return 1;
  }
  return 1;
LAB_00b3bc80:
  param_5 = FUN_00b43110(param_1,lVar10,param_7,param_5);
  if (param_5 < param_6) {
    return 0;
  }
  goto LAB_00b3b8d0;
}


// ==== entry=00b3bcf0 name=FUN_00b3bcf0 size=3530 ====

undefined8
FUN_00b3bcf0(undefined8 *param_1,long param_2,byte *param_3,byte *param_4,byte *param_5,
            byte *param_6,long *param_7,long *param_8,long *param_9)

{
  undefined4 uVar1;
  uint uVar2;
  code *pcVar3;
  long lVar4;
  long lVar5;
  char *pcVar6;
  byte bVar7;
  char cVar8;
  byte bVar9;
  int iVar10;
  int iVar11;
  long lVar12;
  byte *pbVar13;
  byte *pbVar14;
  byte *pbVar15;
  byte *pbVar16;
  byte *pbVar17;
  byte *extraout_RDX;
  byte *extraout_RDX_00;
  byte *extraout_RDX_01;
  byte *extraout_RDX_02;
  byte *extraout_RDX_03;
  byte *extraout_RDX_04;
  byte *extraout_RDX_05;
  byte *extraout_RDX_06;
  long lVar18;
  byte *extraout_RDX_07;
  byte *extraout_RDX_08;
  byte *extraout_RDX_09;
  byte *extraout_RDX_10;
  byte *extraout_RDX_11;
  byte *extraout_RDX_12;
  byte *extraout_RDX_13;
  byte *extraout_RDX_14;
  byte *extraout_RDX_15;
  byte *extraout_RDX_16;
  byte *extraout_RDX_17;
  byte *extraout_RDX_18;
  byte *pbVar19;
  byte *pbVar20;
  undefined8 uVar21;
  byte *pbVar22;
  byte *pbVar23;
  byte *pbStack_d8;
  byte *local_90;
  byte *local_60;
  byte local_58;
  byte local_57 [39];
  
  pbStack_d8 = *(byte **)(param_2 + 0x1b8);
  pbVar19 = param_5;
  if (pbStack_d8 != (byte *)0x0) {
    lVar12 = *(long *)(param_2 + 0x48);
    pbVar20 = param_5 + (long)pbStack_d8;
    pbVar19 = pbVar20;
    if ((*(int *)(lVar12 + 0x18) != 1) && (pbVar19 = param_5, (long)param_5 < (long)pbVar20)) {
      while( true ) {
        iVar10 = (**(code **)(lVar12 + 8))(param_1,pbVar19);
        pbVar19 = pbVar19 + iVar10;
        pbStack_d8 = extraout_RDX;
        if ((long)pbVar20 <= (long)pbVar19) break;
        lVar12 = *(long *)(param_2 + 0x48);
      }
    }
  }
  local_90 = (byte *)0xffffffffffffffff;
LAB_00b3bd73:
  pbVar20 = pbVar19;
  switch(*(undefined4 *)(param_2 + 0x70)) {
  case 1:
    pcVar6 = *(char **)(param_2 + 0x98);
    pbVar17 = *(byte **)(param_2 + 0xa0);
    lVar12 = *(long *)(param_2 + 0x48);
    pbVar14 = param_4 + -(((long)pbVar17 - (long)pcVar6) + -1);
    if ((long)param_6 <= (long)(param_4 + -(((long)pbVar17 - (long)pcVar6) + -1))) {
      pbVar14 = param_6;
    }
    iVar10 = *(int *)(lVar12 + 0x18);
    if (iVar10 == *(int *)(lVar12 + 0x1c)) {
      if ((long)pbVar19 < (long)pbVar14) {
        pbVar13 = (byte *)(pcVar6 + 1);
        lVar12 = (long)pcVar6 - (long)pbVar19;
        do {
          cVar8 = (*(code *)*param_1)(pbVar20,param_1[1]);
          if (cVar8 == *pcVar6) {
            pbVar19 = pbVar20 + 1;
            pbStack_d8 = pbVar13;
            if ((pbVar17 == pbVar13) || (pbVar17 <= pbVar13)) goto LAB_00b3bd90;
            while( true ) {
              bVar7 = pbVar19[lVar12];
              pbVar23 = pbVar19 + 1;
              bVar9 = (*(code *)*param_1)(pbVar19,param_1[1]);
              if (bVar7 != bVar9) break;
              pbStack_d8 = extraout_RDX_12;
              pbVar19 = pbVar23;
              if (pbVar20 + ((long)pbVar17 - (long)pcVar6) == pbVar23) goto LAB_00b3bd90;
            }
          }
          pbVar20 = pbVar20 + iVar10;
          lVar12 = lVar12 - iVar10;
          if ((long)pbVar14 <= (long)pbVar20) {
            return 0;
          }
        } while( true );
      }
    }
    else if ((long)pbVar19 < (long)pbVar14) {
      do {
        cVar8 = (*(code *)*param_1)(pbVar20,param_1[1]);
        if (cVar8 == *pcVar6) {
          pbStack_d8 = extraout_RDX_09;
          if ((pbVar17 == (byte *)(pcVar6 + 1)) || (pbVar17 <= pcVar6 + 1)) goto LAB_00b3bd90;
          pbVar19 = pbVar20 + 1;
          while( true ) {
            bVar7 = pbVar19[(long)pcVar6 - (long)pbVar20];
            pbVar13 = pbVar19 + 1;
            bVar9 = (*(code *)*param_1)(pbVar19,param_1[1]);
            if (bVar7 != bVar9) break;
            pbStack_d8 = extraout_RDX_10;
            pbVar19 = pbVar13;
            if (pbVar20 + ((long)pbVar17 - (long)pcVar6) == pbVar13) goto LAB_00b3bd90;
          }
        }
        iVar10 = (**(code **)(lVar12 + 8))(param_1,pbVar20);
        pbVar20 = pbVar20 + iVar10;
        if ((long)pbVar14 <= (long)pbVar20) {
          return 0;
        }
      } while( true );
    }
    break;
  case 2:
    lVar12 = *(long *)(param_2 + 0xa0);
    lVar4 = *(long *)(param_2 + 0x98);
    lVar18 = (lVar12 + -1) - lVar4;
    pbVar17 = param_6 + lVar18;
    if ((long)param_4 <= (long)(param_6 + lVar18)) {
      pbVar17 = param_4;
    }
    pbVar19 = pbVar19 + lVar18;
    if (*(long *)(param_2 + 0x1a8) == 0) {
      if ((long)pbVar19 < (long)pbVar17) {
        do {
          pbVar20 = pbVar19 + ((lVar4 + 1) - lVar12);
          for (pbVar14 = pbVar19; bVar7 = (*(code *)*param_1)(pbVar14,param_1[1]),
              bVar7 == pbVar14[(lVar12 - (long)pbVar19) + -1]; pbVar14 = pbVar14 + -1) {
            pbStack_d8 = extraout_RDX_13;
            if (pbVar20 == pbVar14) goto LAB_00b3bd90;
          }
          if ((long)pbVar17 <= (long)(pbVar19 + 1)) {
            return 0;
          }
          bVar7 = (*(code *)*param_1)(pbVar19 + 1,param_1[1]);
          pbVar19 = pbVar19 + *(byte *)(param_2 + 0xa8 + (ulong)bVar7);
        } while ((long)pbVar19 < (long)pbVar17);
      }
    }
    else if ((long)pbVar19 < (long)pbVar17) {
      do {
        pbVar20 = pbVar19 + ((lVar4 + 1) - lVar12);
        for (pbVar14 = pbVar19; bVar7 = (*(code *)*param_1)(pbVar14,param_1[1]),
            bVar7 == pbVar14[(lVar12 - (long)pbVar19) + -1]; pbVar14 = pbVar14 + -1) {
          pbStack_d8 = extraout_RDX_08;
          if (pbVar14 == pbVar20) goto LAB_00b3bd90;
        }
        if ((long)pbVar17 <= (long)(pbVar19 + 1)) {
          return 0;
        }
        lVar18 = *(long *)(param_2 + 0x1a8);
        bVar7 = (*(code *)*param_1)(pbVar19 + 1,param_1[1]);
        pbVar19 = pbVar19 + *(int *)(lVar18 + (ulong)bVar7 * 4);
      } while ((long)pbVar19 < (long)pbVar17);
    }
    break;
  case 3:
    lVar12 = *(long *)(param_2 + 0xa0);
    lVar4 = *(long *)(param_2 + 0x98);
    pcVar3 = *(code **)(*(long *)(param_2 + 0x48) + 8);
    lVar18 = (lVar12 + -1) - lVar4;
    pbVar17 = param_4 + -lVar18;
    if ((long)(param_6 + lVar18) <= (long)param_4) {
      pbVar17 = param_6;
    }
    if (*(long *)(param_2 + 0x1a8) == 0) {
      if ((long)pbVar19 < (long)pbVar17) {
        do {
          pbVar14 = pbVar20 + lVar18;
          for (pbVar19 = pbVar14; bVar7 = (*(code *)*param_1)(pbVar19,param_1[1]),
              bVar7 == pbVar19[(lVar12 - (long)pbVar14) + -1]; pbVar19 = pbVar19 + -1) {
            pbStack_d8 = extraout_RDX_14;
            if (pbVar19 == pbVar14 + ((lVar4 + 1) - lVar12)) goto LAB_00b3bd90;
          }
          if ((long)pbVar17 <= (long)(pbVar20 + 1)) {
            return 0;
          }
          bVar7 = (*(code *)*param_1)(pbVar14 + 1,param_1[1]);
          bVar7 = *(byte *)(param_2 + 0xa8 + (ulong)bVar7);
          pbVar19 = pbVar20;
          do {
            iVar10 = (*pcVar3)(param_1,pbVar19);
            pbVar19 = pbVar19 + iVar10;
            if ((long)(ulong)bVar7 <= (long)pbVar19 - (long)pbVar20) break;
          } while ((long)pbVar19 < (long)pbVar17);
          pbVar20 = pbVar19;
        } while ((long)pbVar19 < (long)pbVar17);
      }
    }
    else if ((long)pbVar19 < (long)pbVar17) {
      do {
        pbVar14 = pbVar20 + lVar18;
        for (pbVar19 = pbVar14; bVar7 = (*(code *)*param_1)(pbVar19,param_1[1]),
            bVar7 == pbVar19[(lVar12 - (long)pbVar14) + -1]; pbVar19 = pbVar19 + -1) {
          pbStack_d8 = extraout_RDX_07;
          if (pbVar19 == pbVar14 + ((lVar4 + 1) - lVar12)) goto LAB_00b3bd90;
        }
        if ((long)pbVar17 <= (long)(pbVar20 + 1)) {
          return 0;
        }
        lVar5 = *(long *)(param_2 + 0x1a8);
        bVar7 = (*(code *)*param_1)(pbVar14 + 1,param_1[1]);
        iVar10 = *(int *)(lVar5 + (ulong)bVar7 * 4);
        pbVar19 = pbVar20;
        do {
          iVar11 = (*pcVar3)(param_1,pbVar19);
          pbVar19 = pbVar19 + iVar11;
          if ((long)iVar10 <= (long)pbVar19 - (long)pbVar20) break;
        } while ((long)pbVar19 < (long)pbVar17);
        pbVar20 = pbVar19;
      } while ((long)pbVar19 < (long)pbVar17);
    }
    break;
  case 4:
    uVar1 = *(undefined4 *)(param_2 + 0x60);
    pbVar20 = *(byte **)(param_2 + 0x98);
    pbVar17 = *(byte **)(param_2 + 0xa0);
    lVar12 = *(long *)(param_2 + 0x48);
    pbVar14 = param_4 + (long)(pbVar20 + (1 - (long)pbVar17));
    if ((long)param_6 <= (long)(param_4 + (long)(pbVar20 + (1 - (long)pbVar17)))) {
      pbVar14 = param_6;
    }
    pbStack_d8 = param_6;
    if ((long)pbVar19 < (long)pbVar14) {
LAB_00b3c230:
      pbVar13 = pbVar20;
      local_60 = pbVar19;
      if (pbVar20 < pbVar17) {
        do {
          iVar10 = (**(code **)(lVar12 + 0x58))(param_1,uVar1,&local_60,param_4,&local_58);
          pbStack_d8 = extraout_RDX_06;
          if (0 < iVar10) {
            pbStack_d8 = pbVar13 + 1;
            if (local_58 != *pbVar13) goto LAB_00b3be28;
            pbVar23 = local_57;
            pbVar13 = pbStack_d8;
            while (pbVar23 != local_57 + (iVar10 - 1)) {
              bVar7 = *pbVar23;
              pbStack_d8 = (byte *)(ulong)bVar7;
              bVar9 = *pbVar13;
              pbVar23 = pbVar23 + 1;
              pbVar13 = pbVar13 + 1;
              if (bVar9 != bVar7) goto LAB_00b3be28;
            }
          }
          if (pbVar17 <= pbVar13) break;
        } while( true );
      }
      goto switchD_00b3bd7e_caseD_0;
    }
    break;
  case 5:
    lVar12 = *(long *)(param_2 + 0x48);
    while( true ) {
      if ((long)param_6 <= (long)pbVar19) {
        return 0;
      }
      bVar7 = (*(code *)*param_1)(pbVar19,param_1[1]);
      pbStack_d8 = extraout_RDX_05;
      if (*(char *)(param_2 + 0xa8 + (ulong)bVar7) != '\0') break;
      iVar10 = (**(code **)(lVar12 + 8))(param_1,pbVar19);
      pbVar19 = pbVar19 + iVar10;
    }
  default:
switchD_00b3bd7e_caseD_0:
    pbVar20 = pbVar19;
LAB_00b3bd90:
    if (pbVar20 == (byte *)0xffffffffffffffff) {
      return 0;
    }
    if ((long)param_6 <= (long)pbVar20) {
      return 0;
    }
    if (param_5 <= pbVar20 + -*(long *)(param_2 + 0x1b8)) {
      iVar10 = *(int *)(param_2 + 0x90);
      if (iVar10 != 0) {
        if (iVar10 == 2) {
          if (pbVar20 == param_3) goto LAB_00b3be60;
          pbVar19 = param_3;
          if (local_90 != (byte *)0xffffffffffffffff) {
            pbVar19 = local_90;
          }
          pbVar19 = (byte *)FUN_00b43110(param_1,*(undefined8 *)(param_2 + 0x48),pbVar19,pbVar20);
          uVar21 = *(undefined8 *)(param_2 + 0x48);
          pbStack_d8 = (byte *)0x0;
          uVar1 = *(undefined4 *)(param_2 + 0x50);
        }
        else {
          if ((iVar10 != 0x20) || (pbVar20 == param_4)) goto LAB_00b3be60;
          uVar21 = *(undefined8 *)(param_2 + 0x48);
          pbStack_d8 = (byte *)0x1;
          uVar1 = *(undefined4 *)(param_2 + 0x50);
          pbVar19 = pbVar20;
        }
        iVar10 = FUN_00b3b600(param_1,uVar21,pbVar19,param_3,param_4,uVar1);
        if (iVar10 == 0) goto LAB_00b3be08;
      }
LAB_00b3be60:
      lVar12 = *(long *)(param_2 + 0x1c0);
      if (lVar12 == 0) {
        *param_7 = (long)pbVar20;
        if (param_9 != (long *)0x0) {
          if ((long)param_5 < (long)pbVar20) {
            lVar12 = FUN_00b43110(param_1,*(undefined8 *)(param_2 + 0x48),param_5,pbVar20);
            *param_9 = lVar12;
          }
          else {
            if (local_90 != (byte *)0xffffffffffffffff) {
              param_3 = local_90;
            }
            lVar12 = FUN_00b43110(param_1,*(undefined8 *)(param_2 + 0x48),param_3,pbVar20);
            *param_9 = lVar12;
          }
        }
      }
      else if (lVar12 != -1) {
        lVar12 = (long)pbVar20 - lVar12;
        *param_7 = lVar12;
        if ((long)param_5 < lVar12) {
          lVar12 = FUN_00b43070(param_1,*(undefined8 *)(param_2 + 0x48),param_5,lVar12,param_9);
          *param_7 = lVar12;
          if ((param_9 != (long *)0x0) && (*param_9 == -1)) {
            if (local_90 != (byte *)0xffffffffffffffff) {
              param_5 = local_90;
            }
            lVar12 = FUN_00b43110(param_1,*(undefined8 *)(param_2 + 0x48),param_5,lVar12);
            *param_9 = lVar12;
          }
        }
        else if (param_9 != (long *)0x0) {
          if (local_90 != (byte *)0xffffffffffffffff) {
            param_3 = local_90;
          }
          lVar12 = FUN_00b43110(param_1,*(undefined8 *)(param_2 + 0x48),param_3);
          *param_9 = lVar12;
        }
      }
      *param_8 = (long)pbVar20 - *(long *)(param_2 + 0x1b8);
      return 1;
    }
LAB_00b3be08:
    iVar10 = (**(code **)(*(long *)(param_2 + 0x48) + 8))(param_1,pbVar20,pbStack_d8);
    pbVar19 = pbVar20 + iVar10;
    pbStack_d8 = extraout_RDX_00;
    local_90 = pbVar20;
    goto LAB_00b3bd73;
  case 6:
    pbVar17 = *(byte **)(param_2 + 0xa0);
    pbVar14 = *(byte **)(param_2 + 0x98);
    lVar12 = *(long *)(param_2 + 0x48);
    uVar2 = *(uint *)(param_2 + 0x60);
    pbStack_d8 = (byte *)(ulong)uVar2;
    pbVar23 = pbVar17 + (-1 - (long)pbVar14);
    pbVar13 = param_6 + (long)pbVar23;
    if ((long)param_4 <= (long)(param_6 + (long)pbVar23)) {
      pbVar13 = param_4;
    }
    pbVar19 = pbVar19 + (long)pbVar23;
    if (*(long *)(param_2 + 0x1a8) == 0) {
      if ((long)pbVar19 < (long)pbVar13) {
LAB_00b3c8f8:
        pbVar20 = pbVar19 + -(long)pbVar23;
        pbVar16 = pbVar19 + 1;
        pbVar22 = pbVar14;
        local_60 = pbVar20;
        if (pbVar14 < pbVar17) {
          do {
            iVar10 = (**(code **)(lVar12 + 0x58))(param_1,uVar2,&local_60,pbVar16,&local_58);
            pbStack_d8 = extraout_RDX_15;
            if (0 < iVar10) {
              if (local_58 != *pbVar22) goto LAB_00b3c980;
              pbStack_d8 = local_57 + (iVar10 - 1);
              pbVar15 = local_57;
              while (pbVar22 = pbVar22 + 1, pbVar15 != pbStack_d8) {
                bVar7 = *pbVar15;
                pbVar15 = pbVar15 + 1;
                if (*pbVar22 != bVar7) goto LAB_00b3c980;
              }
            }
            if (pbVar17 <= pbVar22) break;
          } while( true );
        }
        goto LAB_00b3bd90;
      }
    }
    else if ((long)pbVar19 < (long)pbVar13) {
LAB_00b3c0f8:
      pbVar20 = pbVar19 + -(long)pbVar23;
      pbVar16 = pbVar19 + 1;
      pbVar22 = pbVar14;
      local_60 = pbVar20;
      if (pbVar14 < pbVar17) {
        do {
          iVar10 = (**(code **)(lVar12 + 0x58))(param_1,uVar2,&local_60,pbVar16,&local_58);
          pbStack_d8 = extraout_RDX_04;
          if (0 < iVar10) {
            pbStack_d8 = pbVar22 + 1;
            if (local_58 != *pbVar22) goto LAB_00b3c5e0;
            pbVar15 = local_57;
            pbVar22 = pbStack_d8;
            while (local_57 + (iVar10 - 1) != pbVar15) {
              bVar7 = *pbVar15;
              pbStack_d8 = (byte *)(ulong)bVar7;
              bVar9 = *pbVar22;
              pbVar15 = pbVar15 + 1;
              pbVar22 = pbVar22 + 1;
              if (bVar9 != bVar7) goto LAB_00b3c5e0;
            }
          }
          if (pbVar17 <= pbVar22) break;
        } while( true );
      }
      goto LAB_00b3bd90;
    }
    break;
  case 7:
    lVar12 = *(long *)(param_2 + 0x48);
    pbVar20 = *(byte **)(param_2 + 0xa0);
    pbVar17 = *(byte **)(param_2 + 0x98);
    pcVar3 = *(code **)(lVar12 + 8);
    uVar1 = *(undefined4 *)(param_2 + 0x60);
    pbVar13 = pbVar20 + (-1 - (long)pbVar17);
    pbVar14 = param_4 + -(long)pbVar13;
    if ((long)(param_6 + (long)pbVar13) <= (long)param_4) {
      pbVar14 = param_6;
    }
    pbVar23 = pbVar19;
    pbStack_d8 = param_6;
    if (*(long *)(param_2 + 0x1a8) == 0) {
      do {
        pbVar19 = pbVar23;
        if ((long)pbVar14 <= (long)pbVar19) {
          return 0;
        }
        pbVar23 = pbVar17;
        local_60 = pbVar19;
        while( true ) {
          do {
            if (pbVar20 <= pbVar23) goto switchD_00b3bd7e_caseD_0;
            iVar10 = (**(code **)(lVar12 + 0x58))
                               (param_1,uVar1,&local_60,pbVar19 + (long)(pbVar13 + 1),&local_58);
            pbStack_d8 = extraout_RDX_17;
          } while (iVar10 < 1);
          if (*pbVar23 != local_58) break;
          pbStack_d8 = local_57 + (iVar10 - 1);
          pbVar16 = local_57;
          while (pbVar23 = pbVar23 + 1, pbStack_d8 != pbVar16) {
            bVar7 = *pbVar16;
            pbVar16 = pbVar16 + 1;
            if (*pbVar23 != bVar7) goto LAB_00b3ca47;
          }
        }
LAB_00b3ca47:
        if ((long)pbVar14 <= (long)(pbVar19 + 1)) {
          return 0;
        }
        bVar7 = (*(code *)*param_1)(pbVar19 + (long)(pbVar13 + 1),param_1[1]);
        bVar7 = *(byte *)(param_2 + 0xa8 + (ulong)bVar7);
        pbVar23 = pbVar19;
        do {
          iVar10 = (*pcVar3)(param_1,pbVar23);
          pbVar23 = pbVar23 + iVar10;
          pbStack_d8 = extraout_RDX_18;
          if ((long)(ulong)bVar7 <= (long)pbVar23 - (long)pbVar19) break;
        } while ((long)pbVar23 < (long)pbVar14);
      } while( true );
    }
    do {
      pbVar19 = pbVar23;
      if ((long)pbVar14 <= (long)pbVar19) {
        return 0;
      }
      pbVar23 = pbVar17;
      local_60 = pbVar19;
      while( true ) {
        do {
          if (pbVar20 <= pbVar23) goto switchD_00b3bd7e_caseD_0;
          iVar10 = (**(code **)(lVar12 + 0x58))
                             (param_1,uVar1,&local_60,pbVar19 + (long)(pbVar13 + 1),&local_58);
          pbStack_d8 = extraout_RDX_02;
        } while (iVar10 < 1);
        pbStack_d8 = pbVar23 + 1;
        if (local_58 != *pbVar23) break;
        pbVar16 = local_57;
        pbVar23 = pbStack_d8;
        while (local_57 + (iVar10 - 1) != pbVar16) {
          bVar7 = *pbVar16;
          pbStack_d8 = (byte *)(ulong)bVar7;
          bVar9 = *pbVar23;
          pbVar16 = pbVar16 + 1;
          pbVar23 = pbVar23 + 1;
          if (bVar9 != bVar7) goto LAB_00b3c01f;
        }
      }
LAB_00b3c01f:
      if ((long)pbVar14 <= (long)(pbVar19 + 1)) {
        return 0;
      }
      lVar4 = *(long *)(param_2 + 0x1a8);
      bVar7 = (*(code *)*param_1)(pbVar19 + (long)(pbVar13 + 1),param_1[1]);
      iVar10 = *(int *)(lVar4 + (ulong)bVar7 * 4);
      pbVar23 = pbVar19;
      do {
        iVar11 = (*pcVar3)(param_1,pbVar23);
        pbVar23 = pbVar23 + iVar11;
        pbStack_d8 = extraout_RDX_03;
        if ((long)iVar10 <= (long)pbVar23 - (long)pbVar19) break;
      } while ((long)pbVar23 < (long)pbVar14);
    } while( true );
  }
  return 0;
LAB_00b3c980:
  if ((long)pbVar13 <= (long)pbVar16) {
    return 0;
  }
  bVar7 = (*(code *)*param_1)(pbVar16,param_1[1]);
  pbVar19 = pbVar19 + *(byte *)(param_2 + 0xa8 + (ulong)bVar7);
  pbStack_d8 = extraout_RDX_16;
  if ((long)pbVar13 <= (long)pbVar19) {
    return 0;
  }
  goto LAB_00b3c8f8;
LAB_00b3c5e0:
  if ((long)pbVar13 <= (long)pbVar16) {
    return 0;
  }
  lVar4 = *(long *)(param_2 + 0x1a8);
  bVar7 = (*(code *)*param_1)(pbVar16,param_1[1]);
  pbVar19 = pbVar19 + *(int *)(lVar4 + (ulong)bVar7 * 4);
  pbStack_d8 = extraout_RDX_11;
  if ((long)pbVar13 <= (long)pbVar19) {
    return 0;
  }
  goto LAB_00b3c0f8;
LAB_00b3be28:
  iVar10 = (**(code **)(lVar12 + 8))(param_1,pbVar19);
  pbVar19 = pbVar19 + iVar10;
  pbStack_d8 = extraout_RDX_01;
  if ((long)pbVar14 <= (long)pbVar19) {
    return 0;
  }
  goto LAB_00b3c230;
}


// ==== entry=00b3cb70 name=FUN_00b3cb70 size=263 ====

undefined8
FUN_00b3cb70(undefined8 *param_1,long *param_2,long *param_3,void *param_4,long *param_5,
            long *param_6)

{
  void *__src;
  long lVar1;
  long lVar2;
  ulong uVar3;
  void *pvVar4;
  long lVar5;
  size_t __size;
  
  __src = (void *)*param_1;
  lVar1 = *param_3;
  lVar2 = *param_2;
  lVar5 = lVar2 - (long)__src >> 3;
  if ((__src == param_4) && (*param_5 == 0)) {
    __size = lVar5 << 4;
    pvVar4 = malloc(__size);
    if (pvVar4 == (void *)0x0) {
      return 0xfffffffb;
    }
    pvVar4 = memcpy(pvVar4,__src,lVar2 - (long)__src);
  }
  else {
    uVar3 = lVar5 * -0x6666666666666666;
    if ((DAT_011c3828 != 0) &&
       ((DAT_011c3828 < uVar3 &&
        (uVar3 = (ulong)DAT_011c3828, DAT_011c3828 == (uint)(lVar5 * -0x3333333333333333))))) {
      return 0xfffffff1;
    }
    __size = uVar3 * 0x28;
    pvVar4 = realloc(__src,__size);
    if (pvVar4 == (void *)0x0) {
      if (__src == param_4) {
        return 0xfffffffb;
      }
      *param_5 = (long)__src;
      *param_6 = lVar5 * -0x3333333333333333;
      return 0xfffffffb;
    }
  }
  *param_3 = (lVar1 - (long)__src) + (long)pvVar4;
  *param_1 = pvVar4;
  *param_2 = __size + (long)pvVar4;
  return 0;
}


// ==== entry=00b3cc80 name=FUN_00b3cc80 size=20839 ====

/* WARNING: Type propagation algorithm not settling */

long FUN_00b3cc80(undefined8 *param_1,long *param_2,code *******param_3,code *******param_4,
                 code *******param_5,code *******param_6,undefined8 *param_7)

{
  code ******ppppppcVar1;
  uint *puVar2;
  uint uVar3;
  code *pcVar4;
  code *pcVar5;
  undefined8 uVar6;
  byte *pbVar7;
  long *plVar8;
  char cVar9;
  byte bVar10;
  undefined1 uVar11;
  char cVar12;
  byte bVar13;
  undefined4 uVar14;
  long lVar15;
  code *******pppppppcVar16;
  code *******pppppppcVar17;
  ulong uVar18;
  code ******ppppppcVar19;
  code *******pppppppcVar20;
  int iVar21;
  int iVar22;
  code *******pppppppcVar23;
  short sVar24;
  code *******pppppppcVar25;
  code ******ppppppcVar26;
  code ******ppppppcVar27;
  undefined1 *puVar28;
  byte *pbVar29;
  code *******pppppppcVar30;
  bool bVar31;
  long lVar32;
  ushort uVar33;
  code *******pppppppcVar34;
  uint uVar35;
  code *******pppppppcVar36;
  code *******pppppppcVar37;
  code *******local_118;
  undefined8 uStack_110;
  code *******local_108;
  code *******local_100;
  undefined8 local_f8;
  code *******local_f0;
  undefined4 local_e8;
  uint local_e4;
  code *******local_e0;
  long local_d8;
  long local_d0;
  code *******local_c8;
  long *local_c0;
  code *******local_b8;
  int local_b0;
  int local_ac;
  code *******local_a8;
  code *******local_a0;
  long local_98;
  code *******local_90;
  code *******local_80;
  code *******local_78;
  code *******local_70;
  code *******local_68;
  code *******local_60;
  undefined8 local_58;
  
  local_e4 = *(uint *)(param_2 + 10);
  local_b0 = *(int *)((long)param_2 + 0x14);
  local_98 = param_2[9];
  pppppppcVar36 = (code *******)*param_2;
  local_e8 = (undefined4)param_2[0xc];
  lVar15 = (long)((int)param_2[3] + 2 + local_b0 * 2) * 8;
  local_78 = (code *******)*param_7;
  if (local_78 == (code *******)0x0) {
    local_d8 = -(lVar15 + 0x1917U & 0xfffffffffffffff0);
    puVar28 = (undefined1 *)((long)&local_118 + local_d8);
    local_d8 = (long)&uStack_110 + local_d8;
    local_78 = (code *******)(local_d8 + lVar15);
    local_68 = local_78 + 800;
  }
  else {
    local_d8 = -(lVar15 + 0x17U & 0xfffffffffffffff0);
    puVar28 = (undefined1 *)((long)&local_118 + local_d8);
    local_d8 = (long)&uStack_110 + local_d8;
    local_68 = local_78 + param_7[1] * 5;
  }
  local_ac = *(int *)((long)param_2 + 0x34);
  pppppppcVar37 = (code *******)(local_d8 + (long)(int)param_2[3] * 8);
  local_a8 = pppppppcVar37 + (long)local_b0 + 1;
  lVar15 = 0;
  if (-1 < local_b0) {
    do {
      pbVar29 = (byte *)((long)local_a8 + lVar15);
      pbVar29[0] = 0xff;
      pbVar29[1] = 0xff;
      pbVar29[2] = 0xff;
      pbVar29[3] = 0xff;
      pbVar29[4] = 0xff;
      pbVar29[5] = 0xff;
      pbVar29[6] = 0xff;
      pbVar29[7] = 0xff;
      pbVar29 = (byte *)((long)pppppppcVar37 + lVar15);
      pbVar29[0] = 0xff;
      pbVar29[1] = 0xff;
      pbVar29[2] = 0xff;
      pbVar29[3] = 0xff;
      pbVar29[4] = 0xff;
      pbVar29[5] = 0xff;
      pbVar29[6] = 0xff;
      pbVar29[7] = 0xff;
      lVar15 = lVar15 + 8;
    } while ((long)local_b0 * 8 + 8 != lVar15);
  }
  local_d0 = -1;
  *(uint *)local_78 = 1;
  local_78[1] = (code ******)&DAT_011c3824;
  uVar18 = (ulong)*(byte *)pppppppcVar36;
  local_e0 = param_5;
  local_c8 = param_3;
  local_c0 = param_2;
  local_b8 = local_78;
  local_a0 = param_5;
  local_90 = param_4;
  local_80 = param_5;
  local_70 = local_78 + 5;
LAB_00b3cde0:
  pppppppcVar20 = param_5;
  pppppppcVar30 = local_90;
  lVar15 = local_98;
  pppppppcVar34 = local_b8;
  plVar8 = local_c0;
  pppppppcVar16 = local_c8;
  uVar35 = local_e4;
  uVar14 = local_e8;
  bVar13 = (byte)uVar18;
  pppppppcVar25 = (code *******)((long)pppppppcVar36 + 1);
  pppppppcVar17 = pppppppcVar36;
joined_r0x00b3cde7:
  pppppppcVar36 = pppppppcVar25;
  if (0x59 < bVar13) {
    if (local_78 != local_b8) {
      *param_7 = local_78;
      param_7[1] = ((long)local_68 - (long)local_78 >> 3) * -0x3333333333333333;
    }
    return -0xd;
  }
  param_5 = pppppppcVar20;
  switch((&switchD_00b3cded::switchdataD_00d438c0)[uVar18]) {
  case (undefined *)0xb3cdf4:
    if ((code *******)param_7[5] == pppppppcVar20) {
      uVar18 = (ulong)*(byte *)((long)pppppppcVar17 + 1);
      goto LAB_00b3cde0;
    }
switchD_00b3cded_caseD_b3ce02:
    if (local_c8 == pppppppcVar20) {
      if ((*(byte *)((long)param_7 + 0x11) & 2) != 0) goto joined_r0x00b3d741;
      uVar18 = (ulong)*(byte *)((long)pppppppcVar17 + 1);
      goto LAB_00b3cde0;
    }
    pcVar5 = *(code **)(local_98 + 0x28);
    local_f0 = param_6;
    *(undefined8 *)(puVar28 + -8) = 0xb3ce2d;
    iVar21 = (*pcVar5)(param_1,param_6,pppppppcVar30);
    pppppppcVar16 = local_90;
    pppppppcVar20 = local_f0;
    if (iVar21 == 0) goto joined_r0x00b3d741;
    if ((local_e4 & 0x8000) == 0) {
      uVar18 = (ulong)*(byte *)((long)pppppppcVar17 + 1);
      param_5 = local_80;
      param_6 = local_f0;
      goto LAB_00b3cde0;
    }
    pcVar5 = *(code **)(local_98 + 0x38);
    *(undefined8 *)(puVar28 + -8) = 0xb3ce6a;
    iVar21 = (*pcVar5)(param_1,pppppppcVar20,pppppppcVar16);
    pppppppcVar20 = local_f0;
    if (iVar21 == 0xd) {
      pcVar5 = *(code **)(local_98 + 0x38);
      pcVar4 = *(code **)(local_98 + 8);
      *(undefined8 *)(puVar28 + -8) = 0xb3ce95;
      iVar21 = (*pcVar4)(param_1,pppppppcVar20);
      pppppppcVar20 = local_90;
      pbVar29 = (byte *)((long)local_f0 + (long)iVar21);
      *(undefined8 *)(puVar28 + -8) = 0xb3ceae;
      iVar21 = (*pcVar5)(param_1,pbVar29,pppppppcVar20);
      if (iVar21 == 10) goto joined_r0x00b3d741;
      uVar18 = (ulong)*(byte *)((long)pppppppcVar17 + 1);
      param_5 = local_80;
      param_6 = local_f0;
    }
    else {
      uVar18 = (ulong)*(byte *)((long)pppppppcVar17 + 1);
      param_5 = local_80;
      param_6 = local_f0;
    }
    goto LAB_00b3cde0;
  case (undefined *)0xb3ce02:
    goto switchD_00b3cded_caseD_b3ce02;
  case (undefined *)0xb3cf67:
    goto switchD_00b3cded_caseD_b3cf67;
  case (undefined *)0xb3cff3:
    iVar21 = 1;
    sVar24 = 1;
    break;
  case (undefined *)0xb3d146:
    local_f8 = (code *******)(param_7 + 1);
    goto LAB_00b3d174;
  case (undefined *)0xb3d1db:
    local_f0 = (code *******)((long)pppppppcVar17 + 2);
    local_f8 = pppppppcVar20;
    goto LAB_00b3d20c;
  case (undefined *)0xb3d252:
    if ((long)local_90 <= (long)pppppppcVar20) goto joined_r0x00b3d741;
    pcVar5 = *(code **)(local_98 + 0x38);
    local_f0 = param_6;
    *(undefined8 *)(puVar28 + -8) = 0xb3d281;
    uVar14 = (*pcVar5)(param_1,pppppppcVar20,pppppppcVar30);
    *(undefined8 *)(puVar28 + -8) = 0xb3d28d;
    iVar21 = FUN_00b43940(uVar14);
    pppppppcVar16 = local_90;
    pppppppcVar20 = local_f0;
    if (iVar21 == 0) goto joined_r0x00b3d741;
    if (local_80 == local_c8) {
      uVar18 = (ulong)*(byte *)((long)pppppppcVar17 + 1);
      param_5 = local_c8;
      param_6 = local_f0;
    }
    else {
      pcVar5 = *(code **)(local_98 + 0x38);
      *(undefined8 *)(puVar28 + -8) = 0xb3d2cb;
      uVar14 = (*pcVar5)(param_1,pppppppcVar20,pppppppcVar16);
      *(undefined8 *)(puVar28 + -8) = 0xb3d2d7;
      iVar21 = FUN_00b43940(uVar14);
      if (iVar21 != 0) goto joined_r0x00b3d741;
      uVar18 = (ulong)*(byte *)((long)pppppppcVar17 + 1);
      param_5 = local_80;
      param_6 = local_f0;
    }
    goto LAB_00b3cde0;
  case (undefined *)0xb3d2f7:
    pppppppcVar36 = (code *******)((long)pppppppcVar17 + 3);
    pppppppcVar25 = local_70;
    do {
      do {
        pppppppcVar23 = pppppppcVar25;
        pppppppcVar25 = pppppppcVar23 + -5;
      } while (*(uint *)(pppppppcVar23 + -5) != 0x3000);
    } while (*(uint *)(pppppppcVar23 + -4) != (int)*(short *)((long)pppppppcVar17 + 1));
    if ((code *******)pppppppcVar23[-3] != pppppppcVar20) goto code_r0x00b3d32f;
    if (pppppppcVar25 < local_70) {
      iVar22 = 1;
      iVar21 = 1;
      do {
        local_f0 = pppppppcVar36;
        if (*(uint *)pppppppcVar25 == 0x100) {
          pppppppcVar16 = (code *******)pppppppcVar25[4];
          if (pppppppcVar16 == (code *******)0xffffffffffffffff) {
            uVar18 = (ulong)*(byte *)((long)pppppppcVar17 + 3);
            goto LAB_00b3cde0;
          }
          bVar31 = (bool)((byte)*(uint *)(local_c0 + 6) & 1);
          if ((int)*(uint *)(pppppppcVar25 + 1) < 0x20) {
            bVar31 = (1 << ((byte)*(uint *)(pppppppcVar25 + 1) & 0x1f) & *(uint *)(local_c0 + 6)) !=
                     0;
          }
          if (bVar31 != false) {
            pppppppcVar16 = (code *******)local_78[(long)pppppppcVar16 * 5 + 2];
          }
          if ((code *******)local_78[(long)pppppppcVar25[3] * 5 + 2] != pppppppcVar16) {
            uVar18 = (ulong)*(byte *)((long)pppppppcVar17 + 3);
            goto LAB_00b3cde0;
          }
          iVar21 = iVar22;
          if (pppppppcVar16 != pppppppcVar20) {
            iVar21 = -1;
            iVar22 = iVar21;
          }
        }
        pppppppcVar25 = pppppppcVar25 + 5;
      } while (pppppppcVar25 < local_70);
      goto joined_r0x00b41bd1;
    }
    goto LAB_00b401b1;
  case (undefined *)0xb3d38c:
    uVar35 = (uint)*(short *)((long)pppppppcVar17 + 1);
    iVar21 = 0;
    pppppppcVar36 = local_70;
    goto LAB_00b3d3a0;
  case (undefined *)0xb3d3e2:
    if (local_68 == local_70 || (long)local_68 - (long)local_70 < 0) {
      local_f0 = param_6;
      *(undefined8 *)(puVar28 + -8) = 0xb408b5;
      iVar21 = FUN_00b3cb70(&local_78,&local_68,&local_70,pppppppcVar34,param_7,param_7 + 1);
      pppppppcVar20 = local_80;
      param_6 = local_f0;
      if (iVar21 != 0) goto LAB_00b3d695;
    }
    *(uint *)local_70 = 0x500;
    local_70[1] = (code ******)0x0;
    local_70[2] = (code ******)pppppppcVar20;
    local_70[3] = (code ******)param_6;
    local_70[4] = (code ******)local_a0;
    uVar18 = (ulong)*(byte *)((long)pppppppcVar17 + 1);
    param_5 = pppppppcVar20;
    local_70 = local_70 + 5;
    goto LAB_00b3cde0;
  case (undefined *)0xb3d42c:
    local_60 = local_70;
    do {
      while( true ) {
        pppppppcVar20 = local_60;
        local_60 = pppppppcVar20 + -5;
        if ((*(uint *)(pppppppcVar20 + -5) & 0x10ff) == 0) break;
        *(uint *)(pppppppcVar20 + -5) = 0xa00;
      }
    } while (*(uint *)(pppppppcVar20 + -5) != 0x500);
    *(uint *)(pppppppcVar20 + -5) = 0xa00;
    uVar18 = (ulong)*(byte *)((long)pppppppcVar17 + 1);
    param_5 = (code *******)pppppppcVar20[-3];
    param_6 = (code *******)pppppppcVar20[-2];
    local_80 = (code *******)pppppppcVar20[-3];
    goto LAB_00b3cde0;
  case (undefined *)0xb3d485:
    pppppppcVar36 = (code *******)((long)pppppppcVar17 + 5);
    iVar21 = *(int *)((long)pppppppcVar17 + 1);
    if (local_68 == local_70 || (long)local_68 - (long)local_70 < 0) {
      local_f0 = (code *******)CONCAT44(local_f0._4_4_,*(int *)((long)pppppppcVar17 + 1));
      local_f8 = param_6;
      *(undefined8 *)(puVar28 + -8) = 0xb40742;
      iVar21 = FUN_00b3cb70(&local_78,&local_68,&local_70,pppppppcVar34,param_7,param_7 + 1);
      if (iVar21 != 0) goto LAB_00b3d695;
      pppppppcVar20 = local_80;
      param_6 = local_f8;
      iVar21 = (int)local_f0;
    }
    local_70[2] = (code ******)pppppppcVar20;
    *(uint *)local_70 = 3;
    local_70[1] = (code ******)((long)pppppppcVar36 + (long)iVar21);
    local_70[3] = (code ******)param_6;
    local_70[4] = (code ******)local_a0;
    uVar18 = (ulong)*(byte *)((long)pppppppcVar17 + 5);
    param_5 = pppppppcVar20;
    local_70 = local_70 + 5;
    goto LAB_00b3cde0;
  case (undefined *)0xb3d4da:
    goto LAB_00b3d508;
  case (undefined *)0xb3d538:
    if (local_68 == local_70 || (long)local_68 - (long)local_70 < 0) {
      local_f0 = param_6;
      *(undefined8 *)(puVar28 + -8) = 0xb406a5;
      iVar21 = FUN_00b3cb70(&local_78,&local_68,&local_70,pppppppcVar34,param_7,param_7 + 1);
      pppppppcVar20 = local_80;
      param_6 = local_f0;
      if (iVar21 != 0) goto LAB_00b3d695;
    }
    *(uint *)local_70 = 0x600;
    uVar18 = (ulong)*(byte *)((long)pppppppcVar17 + 1);
    param_5 = pppppppcVar20;
    local_70 = local_70 + 5;
    goto LAB_00b3cde0;
  case (undefined *)0xb3d567:
    pppppppcVar20 = local_70;
    do {
      pppppppcVar20 = pppppppcVar20 + -5;
      uVar35 = *(uint *)pppppppcVar20;
      while ((uVar35 & 0x10ff) != 0) {
        *(uint *)pppppppcVar20 = 0xa00;
        pppppppcVar20 = pppppppcVar20 + -5;
        uVar35 = *(uint *)pppppppcVar20;
      }
    } while (uVar35 != 0x600);
    *(uint *)pppppppcVar20 = 0xa00;
    uVar18 = (ulong)*(byte *)((long)pppppppcVar17 + 1);
    goto LAB_00b3cde0;
  case (undefined *)0xb3d5ad:
    uVar14 = *(undefined4 *)((long)pppppppcVar17 + 1);
    *(undefined8 *)(puVar28 + -8) = 0xb3d5ca;
    local_80 = (code *******)FUN_00b43190(param_1,lVar15,pppppppcVar16,pppppppcVar20,uVar14);
    lVar15 = local_98;
    pppppppcVar20 = local_c8;
    if (local_80 == (code *******)0xffffffffffffffff) goto joined_r0x00b3d741;
    pppppppcVar36 = (code *******)((long)pppppppcVar17 + 5);
    *(undefined8 *)(puVar28 + -8) = 0xb3d5f5;
    param_6 = (code *******)FUN_00b43110(param_1,lVar15,pppppppcVar20);
    uVar18 = (ulong)*(byte *)((long)pppppppcVar17 + 5);
    param_5 = local_80;
    goto LAB_00b3cde0;
  case (undefined *)0xb3d609:
    uVar14 = *(undefined4 *)((long)pppppppcVar17 + 5);
    pppppppcVar36 = (code *******)((long)pppppppcVar17 + 9);
    local_f8 = (code *******)CONCAT44(local_f8._4_4_,*(undefined4 *)((long)pppppppcVar17 + 1));
    local_f0 = param_6;
    *(undefined8 *)(puVar28 + -8) = 0xb3d63b;
    pppppppcVar16 = (code *******)FUN_00b43190(param_1,lVar15,pppppppcVar16,pppppppcVar20,uVar14);
    pppppppcVar20 = local_b8;
    if (pppppppcVar16 == (code *******)0xffffffffffffffff) {
      pppppppcVar36 = (code *******)((long)pppppppcVar36 + (long)(int)local_f8);
      uVar18 = (ulong)*(byte *)pppppppcVar36;
      param_5 = local_80;
      param_6 = local_f0;
      goto LAB_00b3cde0;
    }
    if (local_68 == local_70 || (long)local_68 - (long)local_70 < 0) {
      *(undefined8 *)(puVar28 + -8) = 0xb3d68d;
      iVar21 = FUN_00b3cb70(&local_78,&local_68,&local_70,pppppppcVar20,param_7,param_7 + 1);
      if (iVar21 != 0) goto LAB_00b3d695;
    }
    lVar15 = local_98;
    pppppppcVar20 = local_c8;
    *(uint *)local_70 = 2;
    local_70[3] = (code ******)local_f0;
    local_70[4] = (code ******)local_a0;
    local_70[1] = (code ******)((long)pppppppcVar36 + (long)(int)local_f8);
    local_70[2] = (code ******)local_80;
    local_80 = pppppppcVar16;
    local_70 = local_70 + 5;
    *(undefined8 *)(puVar28 + -8) = 0xb402c6;
    param_6 = (code *******)FUN_00b43110(param_1,lVar15,pppppppcVar20);
    uVar18 = (ulong)*(byte *)((long)pppppppcVar17 + 9);
    param_5 = local_80;
    goto LAB_00b3cde0;
  case (undefined *)0xb3d6d7:
    goto LAB_00b3d6e0;
  case (undefined *)0xb3d78d:
    iVar22 = *(int *)((long)pppppppcVar17 + 1);
    if (local_68 == local_70 || (long)local_68 - (long)local_70 < 0) {
      local_f0 = param_6;
      *(undefined8 *)(puVar28 + -8) = 0xb40995;
      iVar21 = FUN_00b3cb70(&local_78,&local_68,&local_70,pppppppcVar34,param_7,param_7 + 1);
      pppppppcVar20 = local_80;
      param_6 = local_f0;
      if (iVar21 != 0) goto LAB_00b3d695;
    }
    *(uint *)local_70 = 0x800;
    local_70[1] = (code ******)((long)pppppppcVar17 + 5);
    pppppppcVar36 = (code *******)((long)iVar22 + *local_c0);
    uVar18 = (ulong)*(byte *)pppppppcVar36;
    param_5 = pppppppcVar20;
    local_70 = local_70 + 5;
    goto LAB_00b3cde0;
  case (undefined *)0xb3d7d2:
    iVar21 = 0;
    pppppppcVar36 = local_70;
    while( true ) {
      pppppppcVar36 = pppppppcVar36 + -5;
      uVar35 = *(uint *)pppppppcVar36;
      while (uVar35 != 0x800) {
        pppppppcVar36 = pppppppcVar36 + -5;
        iVar21 = iVar21 + (uint)(uVar35 == 0x900);
        uVar35 = *(uint *)pppppppcVar36;
      }
      if (iVar21 == 0) break;
      iVar21 = iVar21 + -1;
    }
    pppppppcVar36 = (code *******)pppppppcVar36[1];
    if (local_68 == local_70 || (long)local_68 - (long)local_70 < 0) {
      local_f0 = param_6;
      *(undefined8 *)(puVar28 + -8) = 0xb4094f;
      iVar21 = FUN_00b3cb70(&local_78,&local_68,&local_70,pppppppcVar34,param_7,param_7 + 1);
      pppppppcVar20 = local_80;
      param_6 = local_f0;
      if (iVar21 != 0) {
LAB_00b3d695:
        if (local_78 != local_b8) {
          *param_7 = local_78;
          param_7[1] = ((long)local_68 - (long)local_78 >> 3) * -0x3333333333333333;
        }
        goto LAB_00b3d6c9;
      }
    }
    *(uint *)local_70 = 0x900;
    uVar18 = (ulong)*(byte *)pppppppcVar36;
    param_5 = pppppppcVar20;
    local_70 = local_70 + 5;
    goto LAB_00b3cde0;
  case (undefined *)0xb3d817:
    if ((long)local_90 <= (long)((long)pppppppcVar20 + 5)) goto joined_r0x00b3d741;
    bVar13 = *(byte *)((long)pppppppcVar17 + 1);
    pcVar5 = (code *)*param_1;
    *(undefined8 *)(puVar28 + -8) = 0xb3d837;
    bVar10 = (*pcVar5)(pppppppcVar20);
    if (bVar13 != bVar10) goto joined_r0x00b3d741;
    local_80 = (code *******)((long)local_80 + 1);
    bVar13 = *(byte *)((long)pppppppcVar17 + 2);
    pcVar5 = (code *)*param_1;
    *(undefined8 *)(puVar28 + -8) = 0xb3d858;
    bVar10 = (*pcVar5)();
    if (bVar13 != bVar10) goto joined_r0x00b3d741;
    local_80 = (code *******)((long)local_80 + 1);
    bVar13 = *(byte *)((long)pppppppcVar17 + 3);
    pcVar5 = (code *)*param_1;
    *(undefined8 *)(puVar28 + -8) = 0xb3d878;
    bVar10 = (*pcVar5)();
    if (bVar13 != bVar10) goto joined_r0x00b3d741;
    local_80 = (code *******)((long)local_80 + 1);
    bVar13 = *(byte *)((long)pppppppcVar17 + 4);
    pcVar5 = (code *)*param_1;
    *(undefined8 *)(puVar28 + -8) = 0xb3d898;
    bVar10 = (*pcVar5)();
    if (bVar13 != bVar10) goto joined_r0x00b3d741;
    pppppppcVar36 = (code *******)((long)local_80 + 1);
    bVar13 = *(byte *)((long)pppppppcVar17 + 5);
    pcVar5 = (code *)*param_1;
    local_f0 = pppppppcVar36;
    local_80 = pppppppcVar36;
    *(undefined8 *)(puVar28 + -8) = 0xb3d8c2;
    bVar10 = (*pcVar5)(pppppppcVar36);
    if (bVar13 != bVar10) goto joined_r0x00b3d741;
    local_80 = (code *******)((long)local_80 + 1);
    bVar13 = *(byte *)((long)pppppppcVar17 + 6);
    pcVar5 = (code *)*param_1;
    *(undefined8 *)(puVar28 + -8) = 0xb3d8f0;
    bVar10 = (*pcVar5)();
    if (bVar13 != bVar10) goto joined_r0x00b3d741;
    pppppppcVar36 = (code *******)((long)pppppppcVar17 + 7);
    uVar18 = (ulong)*(byte *)pppppppcVar36;
    param_5 = (code *******)((long)local_80 + 1);
    param_6 = local_f0;
    local_80 = (code *******)((long)local_80 + 1);
    goto LAB_00b3cde0;
  case (undefined *)0xb3d910:
    if ((long)local_90 <= (long)((long)pppppppcVar20 + 1)) goto joined_r0x00b3d741;
    bVar13 = *(byte *)((long)pppppppcVar17 + 1);
    pcVar5 = (code *)*param_1;
    *(undefined8 *)(puVar28 + -8) = 0xb3d930;
    bVar10 = (*pcVar5)(pppppppcVar20);
    if (bVar13 != bVar10) goto joined_r0x00b3d741;
    local_80 = (code *******)((long)local_80 + 1);
    bVar13 = *(byte *)((long)pppppppcVar17 + 2);
    pcVar5 = (code *)*param_1;
    *(undefined8 *)(puVar28 + -8) = 0xb3d951;
    bVar10 = (*pcVar5)();
    if (bVar13 != bVar10) goto joined_r0x00b3d741;
    pppppppcVar36 = (code *******)((long)pppppppcVar17 + 3);
    uVar18 = (ulong)*(byte *)pppppppcVar36;
    param_5 = (code *******)((long)local_80 + 1);
    param_6 = pppppppcVar20;
    local_80 = (code *******)((long)local_80 + 1);
    goto LAB_00b3cde0;
  case (undefined *)0xb3d97a:
    if ((long)local_90 <= (long)((long)pppppppcVar20 + 3)) goto joined_r0x00b3d741;
    bVar13 = *(byte *)((long)pppppppcVar17 + 1);
    pcVar5 = (code *)*param_1;
    *(undefined8 *)(puVar28 + -8) = 0xb3d99a;
    bVar10 = (*pcVar5)(pppppppcVar20);
    if (bVar13 != bVar10) goto joined_r0x00b3d741;
    local_80 = (code *******)((long)local_80 + 1);
    bVar13 = *(byte *)((long)pppppppcVar17 + 2);
    pcVar5 = (code *)*param_1;
    *(undefined8 *)(puVar28 + -8) = 0xb3d9bb;
    bVar10 = (*pcVar5)();
    if (bVar13 != bVar10) goto joined_r0x00b3d741;
    pppppppcVar36 = (code *******)((long)local_80 + 1);
    bVar13 = *(byte *)((long)pppppppcVar17 + 3);
    pcVar5 = (code *)*param_1;
    local_f0 = pppppppcVar36;
    local_80 = pppppppcVar36;
    *(undefined8 *)(puVar28 + -8) = 0xb3d9e5;
    bVar10 = (*pcVar5)(pppppppcVar36);
    if (bVar13 != bVar10) goto joined_r0x00b3d741;
    local_80 = (code *******)((long)local_80 + 1);
    bVar13 = *(byte *)((long)pppppppcVar17 + 4);
    pcVar5 = (code *)*param_1;
    *(undefined8 *)(puVar28 + -8) = 0xb3da13;
    bVar10 = (*pcVar5)();
    if (bVar13 != bVar10) goto joined_r0x00b3d741;
    pppppppcVar36 = (code *******)((long)pppppppcVar17 + 5);
    uVar18 = (ulong)*(byte *)pppppppcVar36;
    param_5 = (code *******)((long)local_80 + 1);
    param_6 = local_f0;
    local_80 = (code *******)((long)local_80 + 1);
    goto LAB_00b3cde0;
  case (undefined *)0xb3da2b:
    goto switchD_00b3cded_caseD_b3da2b;
  case (undefined *)0xb3da6a:
    if ((long)local_90 <= (long)pppppppcVar20) goto joined_r0x00b3d741;
    pcVar5 = *(code **)(local_98 + 0x58);
    local_f0 = (code *******)&local_58;
    *(undefined8 *)(puVar28 + -8) = 0xb3daa2;
    iVar21 = (*pcVar5)(param_1,uVar14,&local_80,pppppppcVar30,&local_58);
    if ((long)local_90 < (long)local_80) goto joined_r0x00b3d741;
    pppppppcVar16 = pppppppcVar36;
    if (iVar21 < 1) goto LAB_00b41d18;
    if ((byte)local_58 != *(byte *)((long)pppppppcVar17 + 1)) goto joined_r0x00b3d741;
    pppppppcVar16 = (code *******)((long)pppppppcVar17 + (ulong)(iVar21 - 1) + 2);
    pppppppcVar17 = local_f0;
    goto LAB_00b3dad4;
  case (undefined *)0xb3daf7:
    iVar21 = *(int *)((long)pppppppcVar17 + 1);
    if ((long)local_90 < (long)((long)pppppppcVar20 + (long)(iVar21 * 3))) goto joined_r0x00b3d741;
    pppppppcVar36 = (code *******)((long)pppppppcVar17 + 5);
    if (iVar21 < 1) goto LAB_00b3db97;
    goto LAB_00b3db29;
  case (undefined *)0xb3dba8:
    if ((long)local_90 <= (long)((long)pppppppcVar20 + 2)) goto joined_r0x00b3d741;
    bVar13 = *(byte *)((long)pppppppcVar17 + 1);
    pcVar5 = (code *)*param_1;
    *(undefined8 *)(puVar28 + -8) = 0xb3dbc8;
    bVar10 = (*pcVar5)(pppppppcVar20);
    if (bVar13 != bVar10) goto joined_r0x00b3d741;
    local_80 = (code *******)((long)local_80 + 1);
    bVar13 = *(byte *)((long)pppppppcVar17 + 2);
    pcVar5 = (code *)*param_1;
    *(undefined8 *)(puVar28 + -8) = 0xb3dbe9;
    bVar10 = (*pcVar5)();
    if (bVar13 != bVar10) goto joined_r0x00b3d741;
    local_80 = (code *******)((long)local_80 + 1);
    bVar13 = *(byte *)((long)pppppppcVar17 + 3);
    pcVar5 = (code *)*param_1;
    *(undefined8 *)(puVar28 + -8) = 0xb3dc09;
    bVar10 = (*pcVar5)();
    if (bVar13 != bVar10) goto joined_r0x00b3d741;
    pppppppcVar36 = (code *******)((long)pppppppcVar17 + 4);
    uVar18 = (ulong)*(byte *)pppppppcVar36;
    param_5 = (code *******)((long)local_80 + 1);
    param_6 = local_80;
    local_80 = (code *******)((long)local_80 + 1);
    goto LAB_00b3cde0;
  case (undefined *)0xb3dc1a:
    iVar21 = *(int *)((long)pppppppcVar17 + 1);
    if ((long)local_90 < (long)((long)pppppppcVar20 + (long)(iVar21 * 2))) goto joined_r0x00b3d741;
    pppppppcVar36 = (code *******)((long)pppppppcVar17 + 5);
    if (iVar21 < 1) goto LAB_00b3dc96;
    goto LAB_00b3dc49;
  case (undefined *)0xb3dca7:
    iVar21 = *(int *)((long)pppppppcVar17 + 1);
    iVar22 = *(int *)((long)pppppppcVar17 + 5) * iVar21;
    if ((long)local_90 < (long)((long)pppppppcVar20 + (long)iVar22)) goto joined_r0x00b3d741;
    pppppppcVar36 = (code *******)((long)pppppppcVar17 + 9);
    if (iVar22 < 1) goto LAB_00b3dd21;
    local_f0 = (code *******)CONCAT44(local_f0._4_4_,iVar21);
    pppppppcVar17 = (code *******)((long)pppppppcVar17 + (ulong)(iVar22 - 1) + 10);
    goto LAB_00b3dcea;
  case (undefined *)0xb3dd34:
    pppppppcVar36 = (code *******)((long)pppppppcVar17 + 5);
    pppppppcVar17 = (code *******)((long)pppppppcVar36 + (long)*(int *)((long)pppppppcVar17 + 1));
    if (pppppppcVar17 <= pppppppcVar36) goto LAB_00b40c1f;
    if ((long)local_90 <= (long)pppppppcVar20) goto joined_r0x00b3d741;
    pppppppcVar16 = (code *******)&local_80;
    param_6 = pppppppcVar20;
    local_f8 = pppppppcVar17;
    goto LAB_00b3dd6c;
  case (undefined *)0xb3dde8:
    if ((long)local_90 <= (long)((long)pppppppcVar20 + 3)) goto joined_r0x00b3d741;
    bVar13 = *(byte *)((long)pppppppcVar17 + 1);
    pcVar5 = (code *)*param_1;
    *(undefined8 *)(puVar28 + -8) = 0xb3de08;
    bVar10 = (*pcVar5)(pppppppcVar20);
    if (bVar13 != bVar10) goto joined_r0x00b3d741;
    local_80 = (code *******)((long)local_80 + 1);
    bVar13 = *(byte *)((long)pppppppcVar17 + 2);
    pcVar5 = (code *)*param_1;
    *(undefined8 *)(puVar28 + -8) = 0xb3de29;
    bVar10 = (*pcVar5)();
    if (bVar13 != bVar10) goto joined_r0x00b3d741;
    local_80 = (code *******)((long)local_80 + 1);
    bVar13 = *(byte *)((long)pppppppcVar17 + 3);
    pcVar5 = (code *)*param_1;
    *(undefined8 *)(puVar28 + -8) = 0xb3de49;
    bVar10 = (*pcVar5)();
    if (bVar13 != bVar10) goto joined_r0x00b3d741;
    local_80 = (code *******)((long)local_80 + 1);
    bVar13 = *(byte *)((long)pppppppcVar17 + 4);
    pcVar5 = (code *)*param_1;
    *(undefined8 *)(puVar28 + -8) = 0xb3de69;
    bVar10 = (*pcVar5)();
    if (bVar13 != bVar10) goto joined_r0x00b3d741;
    pppppppcVar36 = (code *******)((long)pppppppcVar17 + 5);
    uVar18 = (ulong)*(byte *)pppppppcVar36;
    param_5 = (code *******)((long)local_80 + 1);
    param_6 = local_80;
    local_80 = (code *******)((long)local_80 + 1);
    goto LAB_00b3cde0;
  case (undefined *)0xb3de7a:
    if ((long)local_90 <= (long)((long)pppppppcVar20 + 4)) goto joined_r0x00b3d741;
    bVar13 = *(byte *)((long)pppppppcVar17 + 1);
    pcVar5 = (code *)*param_1;
    *(undefined8 *)(puVar28 + -8) = 0xb3de9a;
    bVar10 = (*pcVar5)(pppppppcVar20);
    if (bVar13 != bVar10) goto joined_r0x00b3d741;
    local_80 = (code *******)((long)local_80 + 1);
    bVar13 = *(byte *)((long)pppppppcVar17 + 2);
    pcVar5 = (code *)*param_1;
    *(undefined8 *)(puVar28 + -8) = 0xb3debb;
    bVar10 = (*pcVar5)();
    if (bVar13 != bVar10) goto joined_r0x00b3d741;
    local_80 = (code *******)((long)local_80 + 1);
    bVar13 = *(byte *)((long)pppppppcVar17 + 3);
    pcVar5 = (code *)*param_1;
    *(undefined8 *)(puVar28 + -8) = 0xb3dedb;
    bVar10 = (*pcVar5)();
    if (bVar13 != bVar10) goto joined_r0x00b3d741;
    local_80 = (code *******)((long)local_80 + 1);
    bVar13 = *(byte *)((long)pppppppcVar17 + 4);
    pcVar5 = (code *)*param_1;
    *(undefined8 *)(puVar28 + -8) = 0xb3defb;
    bVar10 = (*pcVar5)();
    if (bVar13 != bVar10) goto joined_r0x00b3d741;
    local_80 = (code *******)((long)local_80 + 1);
    bVar13 = *(byte *)((long)pppppppcVar17 + 5);
    pcVar5 = (code *)*param_1;
    *(undefined8 *)(puVar28 + -8) = 0xb3df1b;
    bVar10 = (*pcVar5)();
    if (bVar13 != bVar10) goto joined_r0x00b3d741;
    pppppppcVar36 = (code *******)((long)pppppppcVar17 + 6);
    uVar18 = (ulong)*(byte *)pppppppcVar36;
    param_5 = (code *******)((long)local_80 + 1);
    param_6 = local_80;
    local_80 = (code *******)((long)local_80 + 1);
    goto LAB_00b3cde0;
  case (undefined *)0xb3df30:
    if ((long)local_90 < (long)((long)pppppppcVar20 + (long)*(int *)((long)pppppppcVar17 + 1)))
    goto joined_r0x00b3d741;
    pppppppcVar36 = (code *******)((long)pppppppcVar17 + 5);
    iVar21 = (int)pppppppcVar36;
    iVar22 = *(int *)((long)pppppppcVar17 + 1) + iVar21;
    bVar13 = *(byte *)pppppppcVar36;
    goto joined_r0x00b3df5f;
  case (undefined *)0xb3df9e:
    bVar13 = *(byte *)((long)pppppppcVar17 + 1);
    local_80 = (code *******)((long)pppppppcVar20 + 1);
    pcVar5 = (code *)*param_1;
    *(undefined8 *)(puVar28 + -8) = 0xb3dfb5;
    bVar10 = (*pcVar5)(pppppppcVar20);
    if ((bVar13 != bVar10) || ((long)local_90 < (long)local_80)) goto joined_r0x00b3d741;
    uVar18 = (ulong)*(byte *)((long)pppppppcVar17 + 2);
    pppppppcVar36 = (code *******)((long)pppppppcVar17 + 2);
    param_5 = local_80;
    param_6 = pppppppcVar20;
    goto LAB_00b3cde0;
  case (undefined *)0xb3dfe3:
    if ((code *******)param_7[5] != pppppppcVar20) goto joined_r0x00b3d741;
    uVar18 = (ulong)*(byte *)((long)pppppppcVar17 + 1);
    goto LAB_00b3cde0;
  case (undefined *)0xb3dffe:
    ppppppcVar27 = *(code *******)(local_d8 + (long)*(short *)((long)pppppppcVar17 + 1) * 8);
    lVar15 = (long)*(short *)((long)pppppppcVar17 + 1) * 8;
    local_60 = local_78 + (long)ppppppcVar27 * 5;
LAB_00b3e02e:
    pppppppcVar36 = (code *******)((long)pppppppcVar17 + 3);
    uVar35 = *(uint *)(local_60 + 1) + 1;
    *(uint *)(local_60 + 1) = uVar35;
    lVar32 = (long)local_68 - (long)local_70;
    if ((int)uVar35 < ((int *)(lVar15 + local_c0[8]))[1]) {
      if ((int)uVar35 < *(int *)(lVar15 + local_c0[8])) {
        pppppppcVar36 = (code *******)local_60[2];
      }
      else {
        if (lVar32 < 1) {
          local_f0 = param_6;
          *(undefined8 *)(puVar28 + -8) = 0xb41b13;
          iVar21 = FUN_00b3cb70(&local_78,&local_68,&local_70,pppppppcVar34,param_7,param_7 + 1);
          param_6 = local_f0;
          if (iVar21 != 0) {
LAB_00b41b52:
            if (local_78 != local_b8) {
              *param_7 = local_78;
              param_7[1] = ((long)local_68 - (long)local_78 >> 3) * -0x3333333333333333;
            }
            goto LAB_00b3d6c9;
          }
        }
        local_70[1] = (code ******)pppppppcVar36;
        *(uint *)local_70 = 1;
        local_70[2] = (code ******)local_80;
        local_70[3] = (code ******)param_6;
        local_70[4] = (code ******)local_a0;
        lVar32 = (long)local_68 - (long)(local_70 + 5);
        pppppppcVar36 = (code *******)local_78[(long)ppppppcVar27 * 5 + 2];
        local_70 = local_70 + 5;
      }
    }
    pppppppcVar20 = local_b8;
    if (lVar32 < 1) {
      local_f0 = param_6;
      *(undefined8 *)(puVar28 + -8) = 0xb40142;
      iVar21 = FUN_00b3cb70(&local_78,&local_68,&local_70,pppppppcVar20,param_7,param_7 + 1);
      param_6 = local_f0;
      if (iVar21 != 0) {
LAB_00b4034c:
        if (local_78 != local_b8) {
          *param_7 = local_78;
          param_7[1] = ((long)local_68 - (long)local_78 >> 3) * -0x3333333333333333;
        }
        goto LAB_00b3d6c9;
      }
    }
    local_70[1] = ppppppcVar27;
    *(uint *)local_70 = 0x300;
    uVar18 = (ulong)*(byte *)pppppppcVar36;
    param_5 = local_80;
    local_70 = local_70 + 5;
    goto LAB_00b3cde0;
  case (undefined *)0xb3e0cc:
    pppppppcVar36 = (code *******)((long)pppppppcVar17 + 3);
    uVar33 = *(ushort *)((long)pppppppcVar17 + 1);
    if (local_68 == local_70 || (long)local_68 - (long)local_70 < 0) {
      local_f0 = (code *******)CONCAT44(local_f0._4_4_,(uint)uVar33);
      local_f8 = param_6;
      *(undefined8 *)(puVar28 + -8) = 0xb4079f;
      iVar21 = FUN_00b3cb70(&local_78,&local_68,&local_70,pppppppcVar34,param_7,param_7 + 1);
      if (iVar21 != 0) goto LAB_00b3fe49;
      uVar33 = (ushort)local_f0;
      pppppppcVar20 = local_80;
      param_6 = local_f8;
    }
    *(uint *)local_70 = 0x3000;
    *(int *)(local_70 + 1) = (int)(short)uVar33;
    local_70[2] = (code ******)pppppppcVar20;
    uVar18 = (ulong)*(byte *)((long)pppppppcVar17 + 3);
    param_5 = pppppppcVar20;
    local_70 = local_70 + 5;
    goto LAB_00b3cde0;
  case (undefined *)0xb3e10f:
    iVar21 = 0;
    pppppppcVar36 = local_70;
    goto LAB_00b3e147;
  case (undefined *)0xb3e185:
    uStack_110._4_4_ = *(int *)((long)pppppppcVar17 + 1);
    pppppppcVar36 = (code *******)((long)pppppppcVar17 + 5);
    local_100 = pppppppcVar36;
    if (0 < uStack_110._4_4_) {
      local_f8 = (code *******)((ulong)local_f8._4_4_ << 0x20);
      local_108 = pppppppcVar37;
      goto LAB_00b3e1b3;
    }
    if (uStack_110._4_4_ == 0) goto joined_r0x00b3d741;
    uVar18 = (ulong)*(byte *)((long)pppppppcVar17 + 5);
    param_5 = local_80;
    goto LAB_00b3cde0;
  case (undefined *)0xb3e31c:
    ppppppcVar27 = *(code *******)(local_d8 + (long)*(short *)((long)pppppppcVar17 + 1) * 8);
    lVar15 = (long)*(short *)((long)pppppppcVar17 + 1) * 8;
    local_60 = local_78 + (long)ppppppcVar27 * 5;
LAB_00b3e348:
    pppppppcVar36 = (code *******)((long)pppppppcVar17 + 3);
    uVar35 = *(uint *)(local_60 + 1) + 1;
    *(uint *)(local_60 + 1) = uVar35;
    uVar3 = ((int *)(lVar15 + local_c0[8]))[1];
    if ((int)uVar35 < (int)uVar3) {
      pppppppcVar20 = (code *******)local_60[2];
      if ((int)uVar35 < *(int *)(lVar15 + local_c0[8])) {
        pppppppcVar36 = pppppppcVar20;
        if (local_68 == local_70 || (long)local_68 - (long)local_70 < 0) {
          local_f8 = param_6;
          local_f0 = pppppppcVar20;
          *(undefined8 *)(puVar28 + -8) = 0xb40dee;
          iVar21 = FUN_00b3cb70(&local_78,&local_68,&local_70,pppppppcVar34,param_7,param_7 + 1);
          pppppppcVar36 = local_f0;
          param_6 = local_f8;
          if (iVar21 != 0) goto LAB_00b4034c;
        }
        local_70[1] = ppppppcVar27;
        *(uint *)local_70 = 0x300;
        uVar18 = (ulong)*(byte *)pppppppcVar36;
        param_5 = local_80;
        local_70 = local_70 + 5;
      }
      else {
        pppppppcVar16 = local_70;
        if ((long)local_68 - (long)local_70 < 1) {
          local_f8 = param_6;
          local_f0 = pppppppcVar20;
          *(undefined8 *)(puVar28 + -8) = 0xb41ac6;
          iVar21 = FUN_00b3cb70(&local_78,&local_68,&local_70,pppppppcVar34,param_7,param_7 + 1);
          pppppppcVar16 = local_70;
          pppppppcVar20 = local_f0;
          param_6 = local_f8;
          if (iVar21 != 0) goto LAB_00b3d695;
        }
        pppppppcVar34 = local_b8;
        *(uint *)pppppppcVar16 = 0x300;
        local_70 = pppppppcVar16 + 5;
        pppppppcVar16[1] = ppppppcVar27;
        if (local_68 == local_70 || (long)local_68 - (long)local_70 < 0) {
          local_f8 = param_6;
          local_f0 = pppppppcVar20;
          *(undefined8 *)(puVar28 + -8) = 0xb40d33;
          iVar21 = FUN_00b3cb70(&local_78,&local_68,&local_70,pppppppcVar34,param_7,param_7 + 1);
          pppppppcVar20 = local_f0;
          param_6 = local_f8;
          if (iVar21 != 0) goto LAB_00b41b52;
        }
        local_70[1] = (code ******)pppppppcVar20;
        *(uint *)local_70 = 1;
        local_70[2] = (code ******)local_80;
        local_70[3] = (code ******)param_6;
        local_70[4] = (code ******)local_a0;
        uVar18 = (ulong)*(byte *)((long)pppppppcVar17 + 3);
        param_5 = local_80;
        local_70 = local_70 + 5;
      }
    }
    else if (uVar35 == uVar3) {
      if (local_68 == local_70 || (long)local_68 - (long)local_70 < 0) {
        local_f0 = param_6;
        *(undefined8 *)(puVar28 + -8) = 0xb40cd2;
        iVar21 = FUN_00b3cb70(&local_78,&local_68,&local_70,pppppppcVar34,param_7,param_7 + 1);
        param_6 = local_f0;
        if (iVar21 != 0) goto LAB_00b3d695;
      }
      local_70[1] = ppppppcVar27;
      *(uint *)local_70 = 0x300;
      uVar18 = (ulong)*(byte *)((long)pppppppcVar17 + 3);
      param_5 = local_80;
      local_70 = local_70 + 5;
    }
    else {
      uVar18 = (ulong)*(byte *)((long)pppppppcVar17 + 3);
      param_5 = local_80;
    }
    goto LAB_00b3cde0;
  case (undefined *)0xb3e3dd:
    pppppppcVar36 = (code *******)((long)pppppppcVar17 + 3);
    pppppppcVar16 = local_70;
    do {
      do {
        pppppppcVar34 = pppppppcVar16;
        pppppppcVar16 = pppppppcVar34 + -5;
      } while (*(uint *)(pppppppcVar34 + -5) != 0x3000);
    } while (*(uint *)(pppppppcVar34 + -4) != (int)*(short *)((long)pppppppcVar17 + 1));
    if ((code *******)pppppppcVar34[-3] == pppppppcVar20) goto LAB_00b401b1;
    uVar18 = (ulong)*(byte *)((long)pppppppcVar17 + 3);
    goto LAB_00b3cde0;
  case (undefined *)0xb3e41c:
    iVar21 = *(int *)((long)pppppppcVar17 + 1);
    pppppppcVar36 = (code *******)((long)pppppppcVar17 + 5);
    local_f0 = (code *******)CONCAT44(local_f0._4_4_,iVar21);
    if (iVar21 < 1) {
      if (iVar21 != 0) goto LAB_00b40881;
      goto joined_r0x00b3d741;
    }
    iVar21 = 0;
    goto LAB_00b3e445;
  case (undefined *)0xb3e520:
    iVar21 = 0;
    pppppppcVar36 = local_70;
    goto LAB_00b3e557;
  case (undefined *)0xb3e595:
    iVar21 = *(int *)((long)pppppppcVar17 + 9);
    pppppppcVar36 = local_70 + -5;
    if (pppppppcVar36 < local_78) goto joined_r0x00b3d741;
    local_f0 = (code *******)0xffffffffffffffff;
    pbVar29 = (byte *)((long)pppppppcVar17 + (ulong)(iVar21 - 1) * 2 + 0xf);
    iVar22 = 0;
    goto LAB_00b3e5f2;
  case (undefined *)0xb3e601:
    if (local_c8 == pppppppcVar20) {
      if ((long)local_90 <= (long)local_c8) goto joined_r0x00b3d741;
      pcVar5 = *(code **)(local_98 + 0x78);
      pcVar4 = *(code **)(local_98 + 0x38);
      local_f0 = param_6;
      *(undefined8 *)(puVar28 + -8) = 0xb4110a;
      uVar14 = (*pcVar4)(param_1,pppppppcVar16,pppppppcVar30);
      *(undefined8 *)(puVar28 + -8) = 0xb41113;
      iVar21 = (*pcVar5)(uVar14);
      if (iVar21 == 0) goto joined_r0x00b3d741;
      uVar18 = (ulong)*(byte *)((long)pppppppcVar17 + 1);
      param_5 = local_80;
      param_6 = local_f0;
    }
    else {
      local_f0 = *(code ********)(local_98 + 0x78);
      pcVar5 = *(code **)(local_98 + 0x38);
      if (local_90 == pppppppcVar20) {
        local_f8 = local_f0;
        local_f0 = param_6;
        *(undefined8 *)(puVar28 + -8) = 0xb41600;
        uVar14 = (*pcVar5)(param_1,param_6,pppppppcVar30);
        pppppppcVar20 = local_f8;
        *(undefined8 *)(puVar28 + -8) = 0xb41610;
        iVar21 = (*(code *)pppppppcVar20)(uVar14);
        if (iVar21 == 0) goto joined_r0x00b3d741;
        uVar18 = (ulong)*(byte *)((long)pppppppcVar17 + 1);
        param_5 = local_80;
        param_6 = local_f0;
      }
      else {
        local_f8 = param_6;
        *(undefined8 *)(puVar28 + -8) = 0xb3e647;
        uVar14 = (*pcVar5)(param_1,pppppppcVar20,pppppppcVar30);
        pppppppcVar20 = local_f0;
        *(undefined8 *)(puVar28 + -8) = 0xb3e657;
        uVar14 = (*(code *)pppppppcVar20)(uVar14,0xc);
        pppppppcVar16 = local_90;
        pppppppcVar20 = local_f8;
        local_f0 = (code *******)CONCAT44(local_f0._4_4_,uVar14);
        pcVar5 = *(code **)(local_98 + 0x78);
        pcVar4 = *(code **)(local_98 + 0x38);
        *(undefined8 *)(puVar28 + -8) = 0xb3e67f;
        uVar14 = (*pcVar4)(param_1,pppppppcVar20,pppppppcVar16);
        *(undefined8 *)(puVar28 + -8) = 0xb3e688;
        iVar21 = (*pcVar5)(uVar14);
        if ((int)local_f0 == iVar21) goto joined_r0x00b3d741;
        uVar18 = (ulong)*(byte *)((long)pppppppcVar17 + 1);
        param_5 = local_80;
        param_6 = local_f8;
      }
    }
    goto LAB_00b3cde0;
  case (undefined *)0xb3e6ac:
    if ((long)local_90 <= (long)pppppppcVar20) goto joined_r0x00b3d741;
    pcVar5 = *(code **)(local_98 + 8);
    *(undefined8 *)(puVar28 + -8) = 0xb3e6cd;
    iVar21 = (*pcVar5)(param_1);
    param_5 = (code *******)((long)local_80 + (long)iVar21);
    if ((long)local_90 < (long)param_5) goto joined_r0x00b3d741;
    uVar18 = (ulong)*(byte *)((long)pppppppcVar17 + 1);
    param_6 = pppppppcVar20;
    local_80 = param_5;
    goto LAB_00b3cde0;
  case (undefined *)0xb3e6f7:
    if ((long)local_90 <= (long)pppppppcVar20) {
      uVar18 = (ulong)*(byte *)((long)pppppppcVar17 + 1);
      param_6 = pppppppcVar20;
      goto LAB_00b3cde0;
    }
    local_f0 = (code *******)(param_7 + 1);
    local_100 = pppppppcVar20;
    local_f8 = pppppppcVar17;
    goto LAB_00b3e727;
  case (undefined *)0xb3e7f0:
    if (local_c8 == pppppppcVar20) goto joined_r0x00b3d741;
    pcVar5 = *(code **)(local_98 + 0x38);
    local_f0 = param_6;
    *(undefined8 *)(puVar28 + -8) = 0xb3e81f;
    uVar14 = (*pcVar5)(param_1,param_6,pppppppcVar30);
    *(undefined8 *)(puVar28 + -8) = 0xb3e82b;
    iVar21 = FUN_00b43940(uVar14);
    pppppppcVar16 = local_80;
    pppppppcVar20 = local_90;
    if (iVar21 == 0) goto joined_r0x00b3d741;
    if (local_80 == local_90) {
      uVar18 = (ulong)*(byte *)((long)pppppppcVar17 + 1);
      param_5 = local_90;
      param_6 = local_f0;
    }
    else {
      pcVar5 = *(code **)(local_98 + 0x38);
      *(undefined8 *)(puVar28 + -8) = 0xb3e866;
      uVar14 = (*pcVar5)(param_1,pppppppcVar16,pppppppcVar20);
      *(undefined8 *)(puVar28 + -8) = 0xb3e872;
      iVar21 = FUN_00b43940(uVar14);
      if (iVar21 != 0) goto joined_r0x00b3d741;
      uVar18 = (ulong)*(byte *)((long)pppppppcVar17 + 1);
      param_5 = local_80;
      param_6 = local_f0;
    }
    goto LAB_00b3cde0;
  case (undefined *)0xb3e892:
    if (local_c8 != pppppppcVar20) goto joined_r0x00b3d741;
    uVar18 = (ulong)*(byte *)((long)pppppppcVar17 + 1);
    goto LAB_00b3cde0;
  case (undefined *)0xb3e8ac:
    if (local_c8 == pppppppcVar20) {
      if ((long)local_c8 < (long)local_90) {
        pcVar5 = *(code **)(local_98 + 0x78);
        pcVar4 = *(code **)(local_98 + 0x38);
        local_f0 = param_6;
        *(undefined8 *)(puVar28 + -8) = 0xb40fc2;
        uVar14 = (*pcVar4)(param_1,pppppppcVar16,pppppppcVar30);
        *(undefined8 *)(puVar28 + -8) = 0xb40fcb;
        iVar21 = (*pcVar5)(uVar14);
        if (iVar21 != 0) goto joined_r0x00b3d741;
        uVar18 = (ulong)*(byte *)((long)pppppppcVar17 + 1);
        param_5 = local_80;
        param_6 = local_f0;
      }
      else {
        uVar18 = (ulong)*(byte *)((long)pppppppcVar17 + 1);
      }
    }
    else {
      local_f0 = *(code ********)(local_98 + 0x78);
      pcVar5 = *(code **)(local_98 + 0x38);
      if (local_90 == pppppppcVar20) {
        local_f8 = local_f0;
        local_f0 = param_6;
        *(undefined8 *)(puVar28 + -8) = 0xb415a2;
        uVar14 = (*pcVar5)(param_1,param_6,pppppppcVar30);
        pppppppcVar20 = local_f8;
        *(undefined8 *)(puVar28 + -8) = 0xb415b2;
        iVar21 = (*(code *)pppppppcVar20)(uVar14);
        if (iVar21 != 0) goto joined_r0x00b3d741;
        uVar18 = (ulong)*(byte *)((long)pppppppcVar17 + 1);
        param_5 = local_80;
        param_6 = local_f0;
      }
      else {
        local_f8 = param_6;
        *(undefined8 *)(puVar28 + -8) = 0xb3e8f2;
        uVar14 = (*pcVar5)(param_1,pppppppcVar20,pppppppcVar30);
        pppppppcVar20 = local_f0;
        *(undefined8 *)(puVar28 + -8) = 0xb3e902;
        uVar14 = (*(code *)pppppppcVar20)(uVar14,0xc);
        pppppppcVar16 = local_90;
        pppppppcVar20 = local_f8;
        local_f0 = (code *******)CONCAT44(local_f0._4_4_,uVar14);
        pcVar5 = *(code **)(local_98 + 0x78);
        pcVar4 = *(code **)(local_98 + 0x38);
        *(undefined8 *)(puVar28 + -8) = 0xb3e92a;
        uVar14 = (*pcVar4)(param_1,pppppppcVar20,pppppppcVar16);
        *(undefined8 *)(puVar28 + -8) = 0xb3e933;
        iVar21 = (*pcVar5)(uVar14);
        if ((int)local_f0 != iVar21) goto joined_r0x00b3d741;
        uVar18 = (ulong)*(byte *)((long)pppppppcVar17 + 1);
        param_5 = local_80;
        param_6 = local_f8;
      }
    }
    goto LAB_00b3cde0;
  case (undefined *)0xb3e948:
    if ((long)local_90 <= (long)pppppppcVar20) goto joined_r0x00b3d741;
    if (local_c8 == pppppppcVar20) {
      uVar18 = (ulong)*(byte *)((long)pppppppcVar17 + 1);
      goto LAB_00b3cde0;
    }
    pcVar5 = *(code **)(local_98 + 0x78);
    pcVar4 = *(code **)(local_98 + 0x38);
    local_f0 = param_6;
    *(undefined8 *)(puVar28 + -8) = 0xb3e988;
    uVar14 = (*pcVar4)(param_1,param_6,pppppppcVar30);
    *(undefined8 *)(puVar28 + -8) = 0xb3e991;
    iVar21 = (*pcVar5)(uVar14);
    pppppppcVar16 = local_80;
    pppppppcVar20 = local_90;
    if (iVar21 == 0) {
      uVar18 = (ulong)*(byte *)((long)pppppppcVar17 + 1);
      param_5 = local_80;
      param_6 = local_f0;
      goto LAB_00b3cde0;
    }
    pcVar5 = *(code **)(local_98 + 0x78);
    pcVar4 = *(code **)(local_98 + 0x38);
    *(undefined8 *)(puVar28 + -8) = 0xb3e9c3;
    uVar14 = (*pcVar4)(param_1,pppppppcVar16,pppppppcVar20);
    *(undefined8 *)(puVar28 + -8) = 0xb3e9cc;
    iVar21 = (*pcVar5)(uVar14);
    pppppppcVar16 = local_90;
    pppppppcVar20 = local_f0;
    if (iVar21 == 0) {
      uVar18 = (ulong)*(byte *)((long)pppppppcVar17 + 1);
      param_5 = local_80;
      param_6 = local_f0;
      goto LAB_00b3cde0;
    }
    pcVar5 = *(code **)(local_98 + 0x38);
    *(undefined8 *)(puVar28 + -8) = 0xb3e9f9;
    uVar14 = (*pcVar5)(param_1,pppppppcVar20,pppppppcVar16);
    *(undefined8 *)(puVar28 + -8) = 0xb3ea00;
    lVar15 = FUN_00b44e10(uVar14);
    pppppppcVar16 = local_80;
    pppppppcVar20 = local_90;
    pcVar5 = *(code **)(local_98 + 0x38);
    *(undefined8 *)(puVar28 + -8) = 0xb3ea1b;
    uVar14 = (*pcVar5)(param_1,pppppppcVar16,pppppppcVar20);
    *(undefined8 *)(puVar28 + -8) = 0xb3ea22;
    lVar32 = FUN_00b44e10(uVar14);
    pppppppcVar16 = local_90;
    pppppppcVar20 = local_f0;
    if (lVar15 == lVar32) goto joined_r0x00b3d741;
    pcVar5 = *(code **)(local_98 + 0x38);
    *(undefined8 *)(puVar28 + -8) = 0xb3ea50;
    uVar35 = (*pcVar5)(param_1,pppppppcVar20,pppppppcVar16);
    pppppppcVar16 = local_80;
    pppppppcVar20 = local_90;
    if (uVar35 < 0x100) {
      pcVar5 = *(code **)(local_98 + 0x38);
      *(undefined8 *)(puVar28 + -8) = 0xb3ea81;
      uVar35 = (*pcVar5)(param_1,pppppppcVar16,pppppppcVar20);
      if (uVar35 < 0x100) goto joined_r0x00b3d741;
      uVar18 = (ulong)*(byte *)((long)pppppppcVar17 + 1);
      param_5 = local_80;
      param_6 = local_f0;
    }
    else {
      uVar18 = (ulong)*(byte *)((long)pppppppcVar17 + 1);
      param_5 = local_80;
      param_6 = local_f0;
    }
    goto LAB_00b3cde0;
  case (undefined *)0xb3eaa4:
    if (local_c8 == pppppppcVar20) goto joined_r0x00b3d741;
    if (local_90 == pppppppcVar20) {
      uVar18 = (ulong)*(byte *)((long)pppppppcVar17 + 1);
      goto LAB_00b3cde0;
    }
    local_f0 = *(code ********)(local_98 + 0x78);
    pcVar5 = *(code **)(local_98 + 0x38);
    local_f8 = param_6;
    *(undefined8 *)(puVar28 + -8) = 0xb3eaeb;
    uVar14 = (*pcVar5)(param_1,pppppppcVar20,pppppppcVar30);
    pppppppcVar20 = local_f0;
    *(undefined8 *)(puVar28 + -8) = 0xb3eafb;
    iVar21 = (*(code *)pppppppcVar20)(uVar14);
    pppppppcVar16 = local_90;
    pppppppcVar20 = local_f8;
    if (iVar21 == 0) {
      uVar18 = (ulong)*(byte *)((long)pppppppcVar17 + 1);
      param_5 = local_80;
      param_6 = local_f8;
      goto LAB_00b3cde0;
    }
    local_f0 = local_f8;
    pcVar5 = *(code **)(local_98 + 0x78);
    pcVar4 = *(code **)(local_98 + 0x38);
    *(undefined8 *)(puVar28 + -8) = 0xb3eb2c;
    uVar14 = (*pcVar4)(param_1,pppppppcVar20,pppppppcVar16);
    *(undefined8 *)(puVar28 + -8) = 0xb3eb35;
    iVar21 = (*pcVar5)(uVar14);
    pppppppcVar16 = local_80;
    pppppppcVar20 = local_90;
    if (iVar21 == 0) {
      uVar18 = (ulong)*(byte *)((long)pppppppcVar17 + 1);
      param_5 = local_80;
      param_6 = local_f0;
      goto LAB_00b3cde0;
    }
    pcVar5 = *(code **)(local_98 + 0x38);
    *(undefined8 *)(puVar28 + -8) = 0xb3eb63;
    uVar14 = (*pcVar5)(param_1,pppppppcVar16,pppppppcVar20);
    *(undefined8 *)(puVar28 + -8) = 0xb3eb6a;
    lVar15 = FUN_00b44e10(uVar14);
    pppppppcVar16 = local_90;
    pppppppcVar20 = local_f0;
    pcVar5 = *(code **)(local_98 + 0x38);
    *(undefined8 *)(puVar28 + -8) = 0xb3eb8b;
    uVar14 = (*pcVar5)(param_1,pppppppcVar20,pppppppcVar16);
    *(undefined8 *)(puVar28 + -8) = 0xb3eb92;
    lVar32 = FUN_00b44e10(uVar14);
    pppppppcVar16 = local_80;
    pppppppcVar20 = local_90;
    if (lVar15 == lVar32) goto joined_r0x00b3d741;
    pcVar5 = *(code **)(local_98 + 0x38);
    *(undefined8 *)(puVar28 + -8) = 0xb3ebc1;
    uVar35 = (*pcVar5)(param_1,pppppppcVar16,pppppppcVar20);
    pppppppcVar16 = local_90;
    pppppppcVar20 = local_f0;
    if (uVar35 < 0x100) {
      pcVar5 = *(code **)(local_98 + 0x38);
      *(undefined8 *)(puVar28 + -8) = 0xb3ebf1;
      uVar35 = (*pcVar5)(param_1,pppppppcVar20,pppppppcVar16);
      if (uVar35 < 0x100) goto joined_r0x00b3d741;
      uVar18 = (ulong)*(byte *)((long)pppppppcVar17 + 1);
      param_5 = local_80;
      param_6 = local_f0;
    }
    else {
      uVar18 = (ulong)*(byte *)((long)pppppppcVar17 + 1);
      param_5 = local_80;
      param_6 = local_f0;
    }
    goto LAB_00b3cde0;
  case (undefined *)0xb3ec14:
    if ((long)local_90 <= (long)pppppppcVar20) goto joined_r0x00b3d741;
    pcVar5 = *(code **)(local_98 + 0x38);
    *(undefined8 *)(puVar28 + -8) = 0xb3ec3c;
    uVar14 = (*pcVar5)(param_1,pppppppcVar20,pppppppcVar30);
    *(undefined8 *)(puVar28 + -8) = 0xb3ec48;
    iVar21 = FUN_00b43940(uVar14);
    if (iVar21 == 0) goto joined_r0x00b3d741;
    pcVar5 = *(code **)(local_98 + 8);
    *(undefined8 *)(puVar28 + -8) = 0xb3ec61;
    iVar21 = (*pcVar5)(param_1);
    uVar18 = (ulong)*(byte *)((long)pppppppcVar17 + 1);
    param_5 = (code *******)((long)local_80 + (long)iVar21);
    param_6 = pppppppcVar20;
    local_80 = (code *******)((long)local_80 + (long)iVar21);
    goto LAB_00b3cde0;
  case (undefined *)0xb3ec7e:
    if ((long)local_90 <= (long)pppppppcVar20) goto joined_r0x00b3d741;
    pcVar5 = *(code **)(local_98 + 0x38);
    *(undefined8 *)(puVar28 + -8) = 0xb3eca6;
    uVar14 = (*pcVar5)(param_1,pppppppcVar20,pppppppcVar30);
    *(undefined8 *)(puVar28 + -8) = 0xb3ecb2;
    iVar21 = FUN_00b43940(uVar14);
    if (iVar21 != 0) goto joined_r0x00b3d741;
    pcVar5 = *(code **)(local_98 + 8);
    *(undefined8 *)(puVar28 + -8) = 0xb3eccb;
    iVar21 = (*pcVar5)(param_1);
    uVar18 = (ulong)*(byte *)((long)pppppppcVar17 + 1);
    param_5 = (code *******)((long)local_80 + (long)iVar21);
    param_6 = pppppppcVar20;
    local_80 = (code *******)((long)local_80 + (long)iVar21);
    goto LAB_00b3cde0;
  case (undefined *)0xb3ece8:
    if (local_c8 == pppppppcVar20) {
      if ((long)local_90 <= (long)local_c8) goto joined_r0x00b3d741;
      pcVar5 = *(code **)(local_98 + 0x38);
      local_f0 = param_6;
      *(undefined8 *)(puVar28 + -8) = 0xb41087;
      uVar14 = (*pcVar5)(param_1,pppppppcVar16,pppppppcVar30);
      *(undefined8 *)(puVar28 + -8) = 0xb41093;
      iVar21 = FUN_00b43940(uVar14);
      if (iVar21 == 0) goto joined_r0x00b3d741;
      uVar18 = (ulong)*(byte *)((long)pppppppcVar17 + 1);
      param_5 = local_80;
      param_6 = local_f0;
    }
    else {
      pcVar5 = *(code **)(local_98 + 0x38);
      if (local_90 == pppppppcVar20) {
        local_f0 = param_6;
        *(undefined8 *)(puVar28 + -8) = 0xb41659;
        uVar14 = (*pcVar5)(param_1,param_6,pppppppcVar30);
        *(undefined8 *)(puVar28 + -8) = 0xb41665;
        iVar21 = FUN_00b43940(uVar14);
        if (iVar21 == 0) goto joined_r0x00b3d741;
        uVar18 = (ulong)*(byte *)((long)pppppppcVar17 + 1);
        param_5 = local_80;
        param_6 = local_f0;
      }
      else {
        local_f0 = param_6;
        *(undefined8 *)(puVar28 + -8) = 0xb3ed23;
        uVar14 = (*pcVar5)(param_1,pppppppcVar20,pppppppcVar30);
        *(undefined8 *)(puVar28 + -8) = 0xb3ed2f;
        iVar21 = FUN_00b43940(uVar14,0xc);
        pppppppcVar16 = local_90;
        pppppppcVar20 = local_f0;
        pcVar5 = *(code **)(local_98 + 0x38);
        *(undefined8 *)(puVar28 + -8) = 0xb3ed4f;
        uVar14 = (*pcVar5)(param_1,pppppppcVar20,pppppppcVar16);
        *(undefined8 *)(puVar28 + -8) = 0xb3ed5b;
        iVar22 = FUN_00b43940(uVar14);
        if (iVar21 == iVar22) goto joined_r0x00b3d741;
        uVar18 = (ulong)*(byte *)((long)pppppppcVar17 + 1);
        param_5 = local_80;
        param_6 = local_f0;
      }
    }
    goto LAB_00b3cde0;
  case (undefined *)0xb3ed7b:
    if (local_c8 == pppppppcVar20) {
      if ((long)local_c8 < (long)local_90) {
        pcVar5 = *(code **)(local_98 + 0x38);
        local_f0 = param_6;
        *(undefined8 *)(puVar28 + -8) = 0xb41021;
        uVar14 = (*pcVar5)(param_1,pppppppcVar16,pppppppcVar30);
        *(undefined8 *)(puVar28 + -8) = 0xb4102d;
        iVar21 = FUN_00b43940(uVar14);
        if (iVar21 != 0) goto joined_r0x00b3d741;
        uVar18 = (ulong)*(byte *)((long)pppppppcVar17 + 1);
        param_5 = local_80;
        param_6 = local_f0;
      }
      else {
        uVar18 = (ulong)*(byte *)((long)pppppppcVar17 + 1);
      }
    }
    else {
      pcVar5 = *(code **)(local_98 + 0x38);
      if (local_90 == pppppppcVar20) {
        local_f0 = param_6;
        *(undefined8 *)(puVar28 + -8) = 0xb4152c;
        uVar14 = (*pcVar5)(param_1,param_6,pppppppcVar30);
        *(undefined8 *)(puVar28 + -8) = 0xb41538;
        iVar21 = FUN_00b43940(uVar14);
        if (iVar21 != 0) goto joined_r0x00b3d741;
        uVar18 = (ulong)*(byte *)((long)pppppppcVar17 + 1);
        param_5 = local_80;
        param_6 = local_f0;
      }
      else {
        local_f0 = param_6;
        *(undefined8 *)(puVar28 + -8) = 0xb3edb6;
        uVar14 = (*pcVar5)(param_1,pppppppcVar20,pppppppcVar30);
        *(undefined8 *)(puVar28 + -8) = 0xb3edc2;
        iVar21 = FUN_00b43940(uVar14,0xc);
        pppppppcVar16 = local_90;
        pppppppcVar20 = local_f0;
        pcVar5 = *(code **)(local_98 + 0x38);
        *(undefined8 *)(puVar28 + -8) = 0xb3ede2;
        uVar14 = (*pcVar5)(param_1,pppppppcVar20,pppppppcVar16);
        *(undefined8 *)(puVar28 + -8) = 0xb3edee;
        iVar22 = FUN_00b43940(uVar14);
        if (iVar21 != iVar22) goto joined_r0x00b3d741;
        uVar18 = (ulong)*(byte *)((long)pppppppcVar17 + 1);
        param_5 = local_80;
        param_6 = local_f0;
      }
    }
    goto LAB_00b3cde0;
  case (undefined *)0xb3edff:
    if ((long)local_90 <= (long)pppppppcVar20) goto joined_r0x00b3d741;
    pcVar5 = *(code **)(local_98 + 8);
    *(undefined8 *)(puVar28 + -8) = 0xb3ee20;
    iVar21 = (*pcVar5)(param_1,pppppppcVar20);
    pppppppcVar16 = local_80;
    if (iVar21 == 1) {
      uVar6 = param_1[1];
      local_f0 = (code *******)CONCAT44(local_f0._4_4_,1);
      pcVar5 = (code *)*param_1;
      *(undefined8 *)(puVar28 + -8) = 0xb40b6f;
      bVar13 = (*pcVar5)(pppppppcVar16,uVar6);
      pppppppcVar16 = local_80;
      uVar35 = *(uint *)((long)pppppppcVar36 + (ulong)(bVar13 >> 5) * 4);
      pcVar5 = (code *)*param_1;
      *(undefined8 *)(puVar28 + -8) = 0xb40b84;
      bVar13 = (*pcVar5)(pppppppcVar16);
      if (((int)local_f0 << (bVar13 & 0x1f) & uVar35) == 0) goto joined_r0x00b3d741;
      pppppppcVar36 =
           (code *******)((long)pppppppcVar17 + (long)*(int *)((long)pppppppcVar17 + 0x21) + 0x25);
      uVar18 = (ulong)*(byte *)pppppppcVar36;
      param_5 = (code *******)((long)local_80 + 1);
      param_6 = pppppppcVar20;
      local_80 = (code *******)((long)local_80 + 1);
      goto LAB_00b3cde0;
    }
    pppppppcVar36 = (code *******)((long)pppppppcVar17 + 0x21);
LAB_00b3ee2d:
    if ((long)local_90 <= (long)local_80) goto joined_r0x00b3d741;
    local_f0 = (code *******)CONCAT44(local_f0._4_4_,*(uint *)pppppppcVar36);
    pcVar5 = *(code **)(local_98 + 8);
    *(undefined8 *)(puVar28 + -8) = 0xb3ee59;
    iVar21 = (*pcVar5)(param_1);
    local_80 = (code *******)((long)local_80 + (long)iVar21);
    if ((long)local_90 < (long)local_80) goto joined_r0x00b3d741;
    pcVar5 = *(code **)(local_98 + 0x38);
    *(undefined8 *)(puVar28 + -8) = 0xb3ee8a;
    (*pcVar5)(param_1);
    *(undefined8 *)(puVar28 + -8) = 0xb3ee94;
    iVar21 = FUN_00b39990((uint *)((long)pppppppcVar36 + 4));
    if (iVar21 == 0) goto joined_r0x00b3d741;
    pppppppcVar36 = (code *******)((long)pppppppcVar36 + 4 + (long)(int)local_f0);
    uVar18 = (ulong)*(byte *)pppppppcVar36;
    param_5 = local_80;
    param_6 = pppppppcVar20;
    goto LAB_00b3cde0;
  case (undefined *)0xb3eeb7:
    if ((long)local_90 <= (long)pppppppcVar20) goto joined_r0x00b3d741;
    uVar6 = param_1[1];
    pcVar5 = (code *)*param_1;
    *(undefined8 *)(puVar28 + -8) = 0xb3eed2;
    bVar13 = (*pcVar5)(pppppppcVar20,uVar6);
    pppppppcVar16 = local_80;
    uVar35 = *(uint *)((long)pppppppcVar36 + (ulong)(bVar13 >> 5) * 4);
    pcVar5 = (code *)*param_1;
    *(undefined8 *)(puVar28 + -8) = 0xb3eee7;
    bVar13 = (*pcVar5)(pppppppcVar16);
    if ((1 << (bVar13 & 0x1f) & uVar35) != 0) goto joined_r0x00b3d741;
    pppppppcVar36 = (code *******)((long)pppppppcVar17 + 0x21);
    pcVar5 = *(code **)(local_98 + 8);
    *(undefined8 *)(puVar28 + -8) = 0xb3ef12;
    iVar21 = (*pcVar5)(param_1);
    uVar18 = (ulong)*(byte *)((long)pppppppcVar17 + 0x21);
    param_5 = (code *******)((long)local_80 + (long)iVar21);
    param_6 = pppppppcVar20;
    local_80 = (code *******)((long)local_80 + (long)iVar21);
    goto LAB_00b3cde0;
  case (undefined *)0xb3ef2f:
    iVar21 = 2;
    sVar24 = 2;
    break;
  case (undefined *)0xb3ef3e:
    pppppppcVar16 = pppppppcVar20;
    if ((long)local_90 <= (long)pppppppcVar20) goto LAB_00b3eff8;
    local_f8 = (code *******)((long)pppppppcVar17 + 2);
    local_100 = pppppppcVar20;
    local_f0 = pppppppcVar37;
    goto LAB_00b3ef70;
  case (undefined *)0xb3f010:
    if ((long)local_90 <= (long)pppppppcVar20) goto joined_r0x00b3d741;
    uVar6 = param_1[1];
    pcVar5 = (code *)*param_1;
    *(undefined8 *)(puVar28 + -8) = 0xb3f02b;
    bVar13 = (*pcVar5)(pppppppcVar20,uVar6);
    pppppppcVar16 = local_80;
    uVar35 = *(uint *)((long)pppppppcVar36 + (ulong)(bVar13 >> 5) * 4);
    pcVar5 = (code *)*param_1;
    *(undefined8 *)(puVar28 + -8) = 0xb3f040;
    bVar13 = (*pcVar5)(pppppppcVar16);
    if ((1 << (bVar13 & 0x1f) & uVar35) == 0) goto joined_r0x00b3d741;
    pppppppcVar36 = (code *******)((long)pppppppcVar17 + 0x21);
    pcVar5 = *(code **)(local_98 + 8);
    *(undefined8 *)(puVar28 + -8) = 0xb3f06b;
    iVar21 = (*pcVar5)(param_1);
    uVar18 = (ulong)*(byte *)((long)pppppppcVar17 + 0x21);
    param_5 = (code *******)((long)local_80 + (long)iVar21);
    param_6 = pppppppcVar20;
    local_80 = (code *******)((long)local_80 + (long)iVar21);
    goto LAB_00b3cde0;
  case (undefined *)0xb3f088:
    pcVar5 = *(code **)(local_98 + 8);
    *(undefined8 *)(puVar28 + -8) = 0xb3f098;
    iVar21 = (*pcVar5)(param_1);
    if (iVar21 != 1) goto LAB_00b3ee2d;
    goto joined_r0x00b3d741;
  case (undefined *)0xb3f0aa:
    if ((long)local_90 <= (long)pppppppcVar20) goto joined_r0x00b3d741;
    local_f0 = *(code ********)((long)pppppppcVar17 + 1);
    pcVar5 = *(code **)(local_98 + 8);
    *(undefined8 *)(puVar28 + -8) = 0xb3f0d6;
    iVar21 = (*pcVar5)(param_1,pppppppcVar20);
    local_80 = (code *******)((long)local_80 + (long)iVar21);
    if ((long)local_90 < (long)local_80) goto joined_r0x00b3d741;
    pcVar5 = *(code **)(local_98 + 0x38);
    *(undefined8 *)(puVar28 + -8) = 0xb3f105;
    uVar14 = (*pcVar5)(param_1);
    pppppppcVar36 = local_f0;
    *(undefined8 *)(puVar28 + -8) = 0xb3f116;
    iVar21 = FUN_00b399f0(iVar21,uVar14,pppppppcVar36);
    if (iVar21 == 0) goto joined_r0x00b3d741;
    uVar18 = (ulong)*(byte *)((long)pppppppcVar17 + 9);
    pppppppcVar36 = (code *******)((long)pppppppcVar17 + 9);
    param_5 = local_80;
    param_6 = pppppppcVar20;
    goto LAB_00b3cde0;
  case (undefined *)0xb3f133:
    if ((long)local_90 <= (long)pppppppcVar20) goto joined_r0x00b3d741;
    pcVar5 = *(code **)(local_98 + 8);
    *(undefined8 *)(puVar28 + -8) = 0xb3f154;
    iVar21 = (*pcVar5)(param_1);
    if ((long)local_90 < (long)((long)local_80 + (long)iVar21)) goto joined_r0x00b3d741;
    *(undefined8 *)(puVar28 + -0x10) = 0;
    local_f0 = (code *******)(long)iVar21;
    *(undefined8 *)(puVar28 + -0x18) = 0xb3f19d;
    iVar21 = FUN_00b3b600(param_1);
    if (iVar21 != 0) goto joined_r0x00b3d741;
    uVar18 = (ulong)*(byte *)((long)pppppppcVar17 + 1);
    param_5 = (code *******)((long)local_80 + (long)local_f0);
    param_6 = pppppppcVar20;
    local_80 = (code *******)((long)local_80 + (long)local_f0);
    goto LAB_00b3cde0;
  case (undefined *)0xb3f1ce:
    if ((long)local_90 <= (long)pppppppcVar20) goto joined_r0x00b3d741;
    local_f0 = *(code ********)(local_98 + 0x78);
    pcVar5 = *(code **)(local_98 + 0x38);
    *(undefined8 *)(puVar28 + -8) = 0xb3f201;
    uVar14 = (*pcVar5)(param_1,pppppppcVar20,pppppppcVar30);
    pppppppcVar16 = local_f0;
    *(undefined8 *)(puVar28 + -8) = 0xb3f211;
    iVar21 = (*(code *)pppppppcVar16)(uVar14);
    if (iVar21 == 0) goto joined_r0x00b3d741;
    pcVar5 = *(code **)(local_98 + 8);
    *(undefined8 *)(puVar28 + -8) = 0xb3f22a;
    iVar21 = (*pcVar5)(param_1);
    uVar18 = (ulong)*(byte *)((long)pppppppcVar17 + 1);
    param_5 = (code *******)((long)local_80 + (long)iVar21);
    param_6 = pppppppcVar20;
    local_80 = (code *******)((long)local_80 + (long)iVar21);
    goto LAB_00b3cde0;
  case (undefined *)0xb3f247:
    if ((long)local_90 <= (long)pppppppcVar20) goto joined_r0x00b3d741;
    local_f0 = *(code ********)(local_98 + 0x78);
    pcVar5 = *(code **)(local_98 + 0x38);
    *(undefined8 *)(puVar28 + -8) = 0xb3f27a;
    uVar14 = (*pcVar5)(param_1,pppppppcVar20,pppppppcVar30);
    pppppppcVar16 = local_f0;
    *(undefined8 *)(puVar28 + -8) = 0xb3f28a;
    iVar21 = (*(code *)pppppppcVar16)(uVar14);
    if (iVar21 != 0) goto joined_r0x00b3d741;
    pcVar5 = *(code **)(local_98 + 8);
    *(undefined8 *)(puVar28 + -8) = 0xb3f2a3;
    iVar21 = (*pcVar5)(param_1);
    uVar18 = (ulong)*(byte *)((long)pppppppcVar17 + 1);
    param_5 = (code *******)((long)local_80 + (long)iVar21);
    param_6 = pppppppcVar20;
    local_80 = (code *******)((long)local_80 + (long)iVar21);
    goto LAB_00b3cde0;
  case (undefined *)0xb3f2c0:
    if ((long)local_90 <= (long)pppppppcVar20) goto joined_r0x00b3d741;
    pcVar5 = *(code **)(local_98 + 8);
    *(undefined8 *)(puVar28 + -8) = 0xb3f2e1;
    iVar21 = (*pcVar5)(param_1);
    if (iVar21 != 1) goto LAB_00b3f2ea;
    pppppppcVar36 =
         (code *******)((long)pppppppcVar17 + (long)*(int *)((long)pppppppcVar17 + 1) + 5);
    uVar18 = (ulong)*(byte *)pppppppcVar36;
    param_5 = (code *******)((long)local_80 + 1);
    param_6 = pppppppcVar20;
    local_80 = (code *******)((long)local_80 + 1);
    goto LAB_00b3cde0;
  case (undefined *)0xb3f352:
    if ((long)local_90 <= (long)pppppppcVar20) goto joined_r0x00b3d741;
    pcVar5 = *(code **)(local_98 + 8);
    *(undefined8 *)(puVar28 + -8) = 0xb3f373;
    iVar21 = (*pcVar5)(param_1,pppppppcVar20);
    pppppppcVar16 = local_80;
    if (iVar21 == 1) {
      uVar6 = param_1[1];
      local_f0 = (code *******)CONCAT44(local_f0._4_4_,1);
      pcVar5 = (code *)*param_1;
      *(undefined8 *)(puVar28 + -8) = 0xb40b11;
      bVar13 = (*pcVar5)(pppppppcVar16,uVar6);
      pppppppcVar16 = local_80;
      uVar35 = *(uint *)((long)pppppppcVar36 + (ulong)(bVar13 >> 5) * 4);
      pcVar5 = (code *)*param_1;
      *(undefined8 *)(puVar28 + -8) = 0xb40b26;
      bVar13 = (*pcVar5)(pppppppcVar16);
      if (((int)local_f0 << (bVar13 & 0x1f) & uVar35) != 0) goto joined_r0x00b3d741;
      pppppppcVar36 =
           (code *******)((long)pppppppcVar17 + (long)*(int *)((long)pppppppcVar17 + 0x21) + 0x25);
      uVar18 = (ulong)*(byte *)pppppppcVar36;
      param_5 = (code *******)((long)local_80 + 1);
      param_6 = pppppppcVar20;
      local_80 = (code *******)((long)local_80 + 1);
      goto LAB_00b3cde0;
    }
    pppppppcVar36 = (code *******)((long)pppppppcVar17 + 0x21);
LAB_00b3f2ea:
    pppppppcVar17 = local_80;
    puVar2 = (uint *)((long)pppppppcVar36 + 4);
    local_f0 = (code *******)CONCAT44(local_f0._4_4_,*(uint *)pppppppcVar36);
    pcVar5 = *(code **)(local_98 + 8);
    *(undefined8 *)(puVar28 + -8) = 0xb3f30a;
    iVar21 = (*pcVar5)(param_1,pppppppcVar17);
    if ((long)local_90 < (long)local_80 + (long)iVar21) {
      if ((long)local_90 <= (long)local_80) goto joined_r0x00b3d741;
      pppppppcVar36 = (code *******)((long)puVar2 + (long)(int)local_f0);
      local_80 = local_90;
      uVar18 = (ulong)*(byte *)pppppppcVar36;
      param_5 = local_90;
      param_6 = pppppppcVar20;
    }
    else {
      pcVar5 = *(code **)(local_98 + 0x38);
      local_80 = (code *******)((long)local_80 + (long)iVar21);
      *(undefined8 *)(puVar28 + -8) = 0xb4031f;
      (*pcVar5)(param_1);
      *(undefined8 *)(puVar28 + -8) = 0xb40329;
      iVar21 = FUN_00b39990(puVar2);
      if (iVar21 != 0) goto joined_r0x00b3d741;
      pppppppcVar36 = (code *******)((long)puVar2 + (long)(int)local_f0);
      uVar18 = (ulong)*(byte *)pppppppcVar36;
      param_5 = local_80;
      param_6 = pppppppcVar20;
    }
    goto LAB_00b3cde0;
  case (undefined *)0xb3f385:
    sVar24 = *(short *)((long)pppppppcVar17 + 1);
    iVar21 = (int)sVar24;
    pppppppcVar36 = (code *******)((long)pppppppcVar17 + 3);
    break;
  case (undefined *)0xb3f395:
    sVar24 = *(short *)((long)pppppppcVar17 + 1);
    if (local_b0 < sVar24) goto joined_r0x00b3d741;
    ppppppcVar27 = local_a8[sVar24];
    if ((ppppppcVar27 == (code ******)0xffffffffffffffff) ||
       (ppppppcVar19 = pppppppcVar37[sVar24], ppppppcVar19 == (code ******)0xffffffffffffffff))
    goto joined_r0x00b3d741;
    if (sVar24 < 0x20) {
      uVar35 = 1 << ((byte)sVar24 & 0x1f);
      if ((uVar35 & *(uint *)((long)local_c0 + 0x2c)) != 0) {
        ppppppcVar19 = local_78[(long)ppppppcVar19 * 5 + 2];
      }
      bVar31 = (*(uint *)(local_c0 + 6) & uVar35) != 0;
    }
    else {
      if ((*(uint *)((long)local_c0 + 0x2c) & 1) != 0) {
        ppppppcVar19 = local_78[(long)ppppppcVar19 * 5 + 2];
      }
      local_f0 = (code *******)CONCAT44(local_f0._4_4_,(int)local_c0[6]);
      pppppppcVar36 = local_f0;
      local_f0._0_1_ = (byte)(int)local_c0[6];
      bVar31 = (bool)((byte)local_f0 & 1);
      local_f0 = pppppppcVar36;
    }
    if (bVar31 != false) {
      ppppppcVar27 = local_78[(long)ppppppcVar27 * 5 + 2];
    }
    if ((long)local_90 < (long)((long)pppppppcVar20 + ((long)ppppppcVar27 - (long)ppppppcVar19)))
    goto joined_r0x00b3d741;
    lVar15 = local_98 + 0x58;
    *(undefined8 *)(puVar28 + -8) = 0xb3f458;
    iVar21 = FUN_00b3b190(param_1,lVar15,uVar14,ppppppcVar19,&local_80);
    lVar15 = local_98;
    if (iVar21 == 0) goto joined_r0x00b3d741;
    do {
      param_6 = pppppppcVar20;
      pcVar5 = *(code **)(lVar15 + 8);
      *(undefined8 *)(puVar28 + -8) = 0xb41849;
      iVar21 = (*pcVar5)(param_1);
      pppppppcVar20 = (code *******)((long)param_6 + (long)iVar21);
    } while ((long)pppppppcVar20 < (long)local_80);
    uVar18 = (ulong)*(byte *)((long)pppppppcVar17 + 3);
    pppppppcVar36 = (code *******)((long)pppppppcVar17 + 3);
    param_5 = local_80;
    goto LAB_00b3cde0;
  case (undefined *)0xb3f466:
    goto joined_r0x00b3d741;
  case (undefined *)0xb3f4ff:
    pppppppcVar36 =
         (code *******)((long)pppppppcVar17 + (long)*(int *)((long)pppppppcVar17 + 1) + 5);
    uVar18 = (ulong)*(byte *)pppppppcVar36;
    goto LAB_00b3cde0;
  case (undefined *)0xb3f512:
    pppppppcVar36 = (code *******)((long)pppppppcVar17 + 5);
    iVar21 = *(int *)((long)pppppppcVar17 + 1);
    if (local_68 == local_70 || (long)local_68 - (long)local_70 < 0) {
      local_f0 = (code *******)CONCAT44(local_f0._4_4_,*(int *)((long)pppppppcVar17 + 1));
      local_f8 = param_6;
      *(undefined8 *)(puVar28 + -8) = 0xb407f3;
      iVar21 = FUN_00b3cb70(&local_78,&local_68,&local_70,pppppppcVar34,param_7,param_7 + 1);
      if (iVar21 != 0) goto LAB_00b3fe49;
      pppppppcVar20 = local_80;
      param_6 = local_f8;
      iVar21 = (int)local_f0;
    }
    local_70[2] = (code ******)pppppppcVar20;
    *(uint *)local_70 = 1;
    local_70[1] = (code ******)((long)pppppppcVar36 + (long)iVar21);
    local_70[3] = (code ******)param_6;
    local_70[4] = (code ******)local_a0;
    uVar18 = (ulong)*(byte *)((long)pppppppcVar17 + 5);
    param_5 = pppppppcVar20;
    local_70 = local_70 + 5;
    goto LAB_00b3cde0;
  case (undefined *)0xb3f567:
    uVar18 = (ulong)*(byte *)((long)pppppppcVar17 + 1);
    local_70 = local_70 + -5;
    goto LAB_00b3cde0;
  case (undefined *)0xb3f579:
    bVar13 = *(byte *)((long)pppppppcVar17 + 5);
    local_f0 = (code *******)CONCAT44(local_f0._4_4_,*(undefined4 *)((long)pppppppcVar17 + 1));
    pcVar5 = (code *)*param_1;
    local_f8 = param_6;
    *(undefined8 *)(puVar28 + -8) = 0xb3f599;
    bVar10 = (*pcVar5)(pppppppcVar20);
    pppppppcVar20 = local_b8;
    if ((bVar13 != bVar10) || ((long)local_90 <= (long)local_80)) {
      pppppppcVar36 = (code *******)((long)pppppppcVar17 + (long)(int)local_f0 + 6);
      uVar18 = (ulong)*(byte *)pppppppcVar36;
      param_5 = local_80;
      param_6 = local_f8;
      goto LAB_00b3cde0;
    }
    pppppppcVar36 = (code *******)((long)pppppppcVar17 + 6);
    if (local_68 == local_70 || (long)local_68 - (long)local_70 < 0) {
      *(undefined8 *)(puVar28 + -8) = 0xb40e97;
      iVar21 = FUN_00b3cb70(&local_78,&local_68,&local_70,pppppppcVar20,param_7,param_7 + 1);
      if (iVar21 != 0) goto LAB_00b3d695;
    }
    local_70[2] = (code ******)local_80;
    *(uint *)local_70 = 1;
    local_70[3] = (code ******)local_f8;
    local_70[1] = (code ******)((long)pppppppcVar36 + (long)(int)local_f0);
    local_70[4] = (code ******)local_a0;
    uVar18 = (ulong)*(byte *)((long)pppppppcVar17 + 6);
    param_5 = local_80;
    param_6 = local_f8;
    local_70 = local_70 + 5;
    goto LAB_00b3cde0;
  case (undefined *)0xb3f5c6:
    bVar13 = *(byte *)((long)pppppppcVar17 + 5);
    local_f8 = (code *******)CONCAT44(local_f8._4_4_,*(undefined4 *)((long)pppppppcVar17 + 1));
    pcVar5 = (code *)*param_1;
    local_f0 = param_6;
    *(undefined8 *)(puVar28 + -8) = 0xb3f5e6;
    bVar10 = (*pcVar5)(pppppppcVar20);
    pppppppcVar20 = local_b8;
    pppppppcVar36 = (code *******)((long)pppppppcVar17 + 6);
    if (bVar13 != bVar10) {
      uVar18 = (ulong)*(byte *)((long)pppppppcVar17 + 6);
      param_5 = local_80;
      param_6 = local_f0;
      goto LAB_00b3cde0;
    }
    param_6 = local_f0;
    if (local_68 == local_70 || (long)local_68 - (long)local_70 < 0) {
      local_100 = local_f0;
      local_f0 = pppppppcVar36;
      *(undefined8 *)(puVar28 + -8) = 0xb40d83;
      iVar21 = FUN_00b3cb70(&local_78,&local_68,&local_70,pppppppcVar20,param_7,param_7 + 1);
      pppppppcVar36 = local_f0;
      param_6 = local_100;
      if (iVar21 != 0) goto LAB_00b3fe49;
    }
    *(uint *)local_70 = 1;
    local_70[3] = (code ******)param_6;
    local_70[2] = (code ******)local_80;
    local_70[1] = (code ******)((long)pppppppcVar36 + (long)(int)local_f8);
    local_70[4] = (code ******)local_a0;
    uVar18 = (ulong)*(byte *)((long)pppppppcVar17 + 6);
    param_5 = local_80;
    local_70 = local_70 + 5;
    goto LAB_00b3cde0;
  case (undefined *)0xb3f64e:
    sVar24 = *(short *)((long)pppppppcVar17 + 1);
    uVar35 = (uint)sVar24;
    pppppppcVar36 = (code *******)((long)pppppppcVar17 + 3);
    bVar31 = false;
    iVar21 = 0;
    local_60 = local_70;
    pppppppcVar16 = local_70;
    goto LAB_00b3f67f;
  case (undefined *)0xb3f6ad:
    pppppppcVar36 = (code *******)((long)pppppppcVar17 + 3);
    local_a8[*(short *)((long)pppppppcVar17 + 1)] = (code ******)pppppppcVar20;
    uVar18 = (ulong)*(byte *)pppppppcVar36;
    goto LAB_00b3cde0;
  case (undefined *)0xb3f6cb:
    pppppppcVar36 = (code *******)((long)pppppppcVar17 + 7);
    sVar24 = *(short *)((long)pppppppcVar17 + 1);
    local_f0 = (code *******)CONCAT44(local_f0._4_4_,*(undefined4 *)((long)pppppppcVar17 + 3));
    if (local_68 == local_70 || (long)local_68 - (long)local_70 < 0) {
      local_100 = param_6;
      local_f8 = (code *******)(param_7 + 1);
      *(undefined8 *)(puVar28 + -8) = 0xb4133c;
      iVar21 = FUN_00b3cb70(&local_78,&local_68,&local_70,pppppppcVar34,param_7,param_7 + 1);
      pppppppcVar16 = local_b8;
      pppppppcVar20 = local_f8;
      if (iVar21 != 0) {
LAB_00b41e41:
        if (local_78 != local_b8) {
          *param_7 = local_78;
          param_7[1] = ((long)local_68 - (long)local_78 >> 3) * -0x3333333333333333;
        }
        goto LAB_00b3d6c9;
      }
      pppppppcVar34 = (code *******)((long)sVar24 * 8);
      *(long *)(local_d8 + (long)sVar24 * 8) =
           ((long)local_70 - (long)local_78 >> 3) * -0x3333333333333333;
      param_6 = local_100;
      if ((long)local_68 - (long)local_70 < 1) {
        local_108 = local_100;
        local_100 = pppppppcVar34;
        *(undefined8 *)(puVar28 + -8) = 0xb413c0;
        iVar21 = FUN_00b3cb70(&local_78,&local_68,&local_70,pppppppcVar16,param_7,pppppppcVar20);
        pppppppcVar34 = local_100;
        param_6 = local_108;
        if (iVar21 != 0) {
LAB_00b41e00:
          if (local_78 != local_b8) {
            *param_7 = local_78;
            param_7[1] = ((long)local_68 - (long)local_78 >> 3) * -0x3333333333333333;
          }
          goto LAB_00b3d6c9;
        }
      }
    }
    else {
      *(long *)(local_d8 + (long)sVar24 * 8) =
           ((long)local_70 - (long)local_78 >> 3) * -0x3333333333333333;
      pppppppcVar34 = (code *******)((long)sVar24 * 8);
    }
    pppppppcVar20 = local_b8;
    *(int *)(local_70 + 3) = (int)sVar24;
    pppppppcVar16 = local_70 + 5;
    *(uint *)local_70 = 0x700;
    lVar15 = local_c0[8];
    local_70[2] = (code ******)pppppppcVar36;
    *(uint *)(local_70 + 1) = 0;
    local_70 = pppppppcVar16;
    if (*(int *)((long)pppppppcVar34 + lVar15) != 0) {
      uVar18 = (ulong)*(byte *)((long)pppppppcVar17 + 7);
      param_5 = local_80;
      goto LAB_00b3cde0;
    }
    if (local_68 == pppppppcVar16 || (long)local_68 - (long)pppppppcVar16 < 0) {
      local_f8 = param_6;
      *(undefined8 *)(puVar28 + -8) = 0xb412cd;
      iVar21 = FUN_00b3cb70(&local_78,&local_68,&local_70,pppppppcVar20,param_7,param_7 + 1);
      param_6 = local_f8;
      if (iVar21 != 0) goto LAB_00b3d695;
    }
    *(uint *)local_70 = 1;
    local_70[3] = (code ******)param_6;
    local_70[2] = (code ******)local_80;
    local_70[1] = (code ******)((long)pppppppcVar36 + (long)(int)local_f0);
    local_70[4] = (code ******)local_a0;
    uVar18 = (ulong)*(byte *)((long)pppppppcVar17 + 7);
    param_5 = local_80;
    local_70 = local_70 + 5;
    goto LAB_00b3cde0;
  case (undefined *)0xb3f7a6:
    pppppppcVar36 = (code *******)((long)pppppppcVar17 + 7);
    sVar24 = *(short *)((long)pppppppcVar17 + 1);
    local_f0 = (code *******)CONCAT44(local_f0._4_4_,*(undefined4 *)((long)pppppppcVar17 + 3));
    if (local_68 == local_70 || (long)local_68 - (long)local_70 < 0) {
      local_100 = param_6;
      local_f8 = (code *******)(param_7 + 1);
      *(undefined8 *)(puVar28 + -8) = 0xb41473;
      iVar21 = FUN_00b3cb70(&local_78,&local_68,&local_70,pppppppcVar34,param_7,param_7 + 1);
      pppppppcVar16 = local_b8;
      pppppppcVar20 = local_f8;
      if (iVar21 != 0) goto LAB_00b41e41;
      pppppppcVar34 = (code *******)((long)sVar24 * 8);
      *(long *)(local_d8 + (long)sVar24 * 8) =
           ((long)local_70 - (long)local_78 >> 3) * -0x3333333333333333;
      param_6 = local_100;
      if (local_68 == local_70 || (long)local_68 - (long)local_70 < 0) {
        local_108 = local_100;
        local_100 = pppppppcVar34;
        *(undefined8 *)(puVar28 + -8) = 0xb414f7;
        iVar21 = FUN_00b3cb70(&local_78,&local_68,&local_70,pppppppcVar16,param_7,pppppppcVar20);
        pppppppcVar34 = local_100;
        param_6 = local_108;
        if (iVar21 != 0) goto LAB_00b41e00;
      }
    }
    else {
      *(long *)(local_d8 + (long)sVar24 * 8) =
           ((long)local_70 - (long)local_78 >> 3) * -0x3333333333333333;
      pppppppcVar34 = (code *******)((long)sVar24 * 8);
    }
    pppppppcVar20 = local_b8;
    *(int *)(local_70 + 3) = (int)sVar24;
    pppppppcVar16 = local_70 + 5;
    *(uint *)local_70 = 0x700;
    lVar15 = local_c0[8];
    local_70[2] = (code ******)pppppppcVar36;
    *(uint *)(local_70 + 1) = 0;
    local_70 = pppppppcVar16;
    if (*(int *)((long)pppppppcVar34 + lVar15) != 0) {
      uVar18 = (ulong)*(byte *)((long)pppppppcVar17 + 7);
      param_5 = local_80;
      goto LAB_00b3cde0;
    }
    if (local_68 == pppppppcVar16 || (long)local_68 - (long)pppppppcVar16 < 0) {
      local_f8 = param_6;
      *(undefined8 *)(puVar28 + -8) = 0xb4128b;
      iVar21 = FUN_00b3cb70(&local_78,&local_68,&local_70,pppppppcVar20,param_7,param_7 + 1);
      param_6 = local_f8;
      if (iVar21 != 0) goto LAB_00b3d695;
    }
    *(uint *)local_70 = 1;
    local_70[1] = (code ******)pppppppcVar36;
    local_70[2] = (code ******)local_80;
    local_70[3] = (code ******)param_6;
    pppppppcVar36 = (code *******)((long)pppppppcVar36 + (long)(int)local_f0);
    local_70[4] = (code ******)local_a0;
    uVar18 = (ulong)*(byte *)pppppppcVar36;
    param_5 = local_80;
    local_70 = local_70 + 5;
    goto LAB_00b3cde0;
  case (undefined *)0xb3f87e:
    lVar32 = (long)pppppppcVar20 - (long)local_e0;
    lVar15 = local_d0;
    if (lVar32 <= local_d0) goto LAB_00b3ff71;
    if ((local_e4 & 0x10) != 0) {
      if (lVar32 <= (long)param_7[6]) goto LAB_00b3ff71;
      param_7[6] = lVar32;
      param_7[7] = local_e0;
    }
    pppppppcVar36 = (code *******)param_7[3];
    lVar15 = lVar32;
    if (pppppppcVar36 != (code *******)0x0) {
      if ((*(byte *)((long)param_7 + 0x11) & 8) == 0) {
        ppppppcVar27 = pppppppcVar36[1];
        ppppppcVar19 = pppppppcVar36[2];
        if ((long)local_a0 <= (long)pppppppcVar20) {
          pppppppcVar20 = local_a0;
        }
        *ppppppcVar27 = (code *****)((long)pppppppcVar20 - (long)local_c8);
        *ppppppcVar19 = (code *****)((long)local_80 - (long)local_c8);
        if (0 < local_b0) {
          uVar18 = 1;
          do {
            ppppppcVar1 = ppppppcVar19 + uVar18;
            ppppppcVar26 = ppppppcVar27 + uVar18;
            if (local_a8[uVar18] == (code ******)0xffffffffffffffff) {
              *ppppppcVar1 = (code *****)0xffffffffffffffff;
              *ppppppcVar26 = (code *****)0xffffffffffffffff;
            }
            else {
              bVar31 = (bool)((byte)*(uint *)((long)local_c0 + 0x2c) & 1);
              if (uVar18 < 0x20) {
                bVar31 = (1 << ((byte)uVar18 & 0x1f) & *(uint *)((long)local_c0 + 0x2c)) != 0;
              }
              if (bVar31 == false) {
                *ppppppcVar26 = (code *****)((long)pppppppcVar37[uVar18] - (long)local_c8);
              }
              else {
                *ppppppcVar26 =
                     (code *****)
                     ((long)local_78[(long)pppppppcVar37[uVar18] * 5 + 2] - (long)local_c8);
              }
              bVar31 = (bool)((byte)*(uint *)(local_c0 + 6) & 1);
              if (uVar18 < 0x20) {
                bVar31 = (1 << ((byte)uVar18 & 0x1f) & *(uint *)(local_c0 + 6)) != 0;
              }
              ppppppcVar26 = local_a8[uVar18];
              if (bVar31 != false) {
                ppppppcVar26 = local_78[(long)ppppppcVar26 * 5 + 2];
              }
              *ppppppcVar1 = (code *****)((long)ppppppcVar26 - (long)local_c8);
            }
            uVar18 = uVar18 + 1;
            local_f0 = pppppppcVar36;
            local_d0 = lVar32;
          } while ((ulong)(local_b0 - 1) + 2 != uVar18);
        }
        if ((int)local_c0[5] != 0) {
          ppppppcVar27 = pppppppcVar36[3];
          if (ppppppcVar27 == (code ******)0x0) {
            *(undefined8 *)(puVar28 + -8) = 0xb41d7d;
            ppppppcVar27 = (code ******)FUN_00b3b150();
            pppppppcVar36[3] = ppppppcVar27;
            ppppppcVar19 = ppppppcVar27;
            if (ppppppcVar27 == (code ******)0x0) {
              return -5;
            }
          }
          else {
            *(undefined8 *)(puVar28 + -8) = 0xb3cf05;
            FUN_00b3b260(ppppppcVar27);
            ppppppcVar19 = pppppppcVar36[3];
          }
          pppppppcVar20 = local_70;
          plVar8 = local_c0;
          pppppppcVar36 = local_c8;
          *(undefined4 *)ppppppcVar27 = 0;
          pppppppcVar17 = local_a0;
          if ((long)local_80 <= (long)local_a0) {
            pppppppcVar17 = local_80;
          }
          ppppppcVar27[2] = (code *****)((long)local_80 - (long)local_c8);
          local_60 = local_78;
          ppppppcVar27[1] = (code *****)((long)pppppppcVar17 - (long)local_c8);
          *(undefined8 *)(puVar28 + -8) = 0xb3cf56;
          iVar21 = FUN_00b3b480(ppppppcVar19,&local_60,pppppppcVar20,pppppppcVar36,plVar8);
          if (iVar21 < 0) {
            local_d0 = (long)iVar21;
            goto switchD_00b3cded_caseD_b3cf67;
          }
        }
      }
      else {
        iVar21 = (int)local_c8;
        if ((long)pppppppcVar20 < (long)local_a0) {
          local_a0 = pppppppcVar20;
        }
        *(int *)((long)pppppppcVar36 + 4) = (int)pppppppcVar20 - iVar21;
        *(int *)pppppppcVar36 = (int)local_a0 - iVar21;
        if (0 < local_b0) {
          uVar18 = 1;
          do {
            ppppppcVar27 = local_a8[uVar18];
            uVar35 = (uint)ppppppcVar27;
            if (ppppppcVar27 == (code ******)0xffffffffffffffff) {
              pbVar29 = (byte *)((long)pppppppcVar36 + uVar18 * 8 + 4);
              pbVar29[0] = 0xff;
              pbVar29[1] = 0xff;
              pbVar29[2] = 0xff;
              pbVar29[3] = 0xff;
              *(uint *)(pppppppcVar36 + uVar18) = 0xffffffff;
            }
            else {
              bVar31 = (bool)((byte)*(uint *)((long)local_c0 + 0x2c) & 1);
              if (uVar18 < 0x20) {
                bVar31 = (1 << ((byte)uVar18 & 0x1f) & *(uint *)((long)local_c0 + 0x2c)) != 0;
              }
              if (bVar31 == false) {
                *(int *)(pppppppcVar36 + uVar18) = (int)pppppppcVar37[uVar18] - iVar21;
              }
              else {
                *(int *)(pppppppcVar36 + uVar18) =
                     (int)local_78[(long)pppppppcVar37[uVar18] * 5 + 2] - iVar21;
              }
              bVar31 = (bool)((byte)*(uint *)(local_c0 + 6) & 1);
              if (uVar18 < 0x20) {
                bVar31 = (1 << ((byte)uVar18 & 0x1f) & *(uint *)(local_c0 + 6)) != 0;
              }
              if (bVar31 != false) {
                uVar35 = *(uint *)(local_78 + (long)ppppppcVar27 * 5 + 2);
              }
              *(uint *)((long)pppppppcVar36 + uVar18 * 8 + 4) = uVar35 - iVar21;
            }
            uVar18 = uVar18 + 1;
          } while ((ulong)(local_b0 - 1) + 2 != uVar18);
        }
      }
    }
LAB_00b3ff71:
    local_d0 = lVar15;
    if ((local_e4 & 0x30) != 0) {
      if (((local_e4 & 0x20) == 0) || (local_80 != local_e0)) {
        if (((local_e4 & 0x10) == 0) || ((long)local_90 <= (long)local_80))
        goto switchD_00b3cded_caseD_b3cf67;
      }
      else {
        local_d0 = -1;
      }
      goto joined_r0x00b3d741;
    }
switchD_00b3cded_caseD_b3cf67:
    if (local_78 == local_b8) {
      return local_d0;
    }
    *param_7 = local_78;
    param_7[1] = ((long)local_68 - (long)local_78 >> 3) * -0x3333333333333333;
    return local_d0;
  case (undefined *)0xb3f9bb:
    if (local_90 != pppppppcVar20) goto joined_r0x00b3d741;
    uVar18 = (ulong)*(byte *)((long)pppppppcVar17 + 1);
    goto LAB_00b3cde0;
  case (undefined *)0xb3f9d5:
    sVar24 = *(short *)((long)pppppppcVar17 + 1);
    bVar31 = false;
    iVar21 = 0;
    pppppppcVar36 = (code *******)((long)pppppppcVar17 + 3);
    local_a8[sVar24] = (code ******)pppppppcVar20;
    pppppppcVar20 = local_70;
    goto LAB_00b3fa20;
  case (undefined *)0xb3fa4f:
    pppppppcVar36 = (code *******)((long)pppppppcVar17 + 3);
    uVar33 = *(ushort *)((long)pppppppcVar17 + 1);
    if (local_68 == local_70 || (long)local_68 - (long)local_70 < 0) {
      local_f0 = (code *******)CONCAT44(local_f0._4_4_,(uint)uVar33);
      local_f8 = param_6;
      *(undefined8 *)(puVar28 + -8) = 0xb3fe41;
      iVar21 = FUN_00b3cb70(&local_78,&local_68,&local_70,pppppppcVar34,param_7,param_7 + 1);
      if (iVar21 != 0) goto LAB_00b3fe49;
      uVar33 = (ushort)local_f0;
      pppppppcVar20 = local_80;
      param_6 = local_f8;
    }
    local_70[2] = (code ******)pppppppcVar20;
    *(int *)(local_70 + 1) = (int)(short)uVar33;
    *(uint *)local_70 = 0x100;
    local_70[3] = pppppppcVar37[(short)uVar33];
    local_70[4] = local_a8[(short)uVar33];
    lVar15 = (long)local_70 - (long)local_78;
    local_70 = local_70 + 5;
    pppppppcVar37[(short)uVar33] = (code ******)((lVar15 >> 3) * -0x3333333333333333);
    local_a8[(short)uVar33] = (code ******)0xffffffffffffffff;
    uVar18 = (ulong)*(byte *)((long)pppppppcVar17 + 3);
    param_5 = pppppppcVar20;
    goto LAB_00b3cde0;
  case (undefined *)0xb3fad6:
    if ((long)local_90 <= (long)((long)pppppppcVar20 + 1)) goto joined_r0x00b3d741;
    bVar13 = *(byte *)((long)pppppppcVar17 + 1);
    pcVar5 = (code *)*param_1;
    *(undefined8 *)(puVar28 + -8) = 0xb3faf6;
    bVar10 = (*pcVar5)(pppppppcVar20);
    if (bVar13 != bVar10) goto joined_r0x00b3d741;
    local_80 = (code *******)((long)local_80 + 1);
    bVar13 = *(byte *)((long)pppppppcVar17 + 2);
    pcVar5 = (code *)*param_1;
    *(undefined8 *)(puVar28 + -8) = 0xb3fb17;
    bVar10 = (*pcVar5)();
    if (bVar13 != bVar10) goto joined_r0x00b3d741;
    pppppppcVar36 = (code *******)((long)pppppppcVar17 + 3);
    uVar18 = (ulong)*(byte *)pppppppcVar36;
    param_5 = (code *******)((long)local_80 + 1);
    param_6 = local_80;
    local_80 = (code *******)((long)local_80 + 1);
    goto LAB_00b3cde0;
  case (undefined *)0xb3fb28:
    if (local_90 == pppppppcVar20) {
      if ((*(byte *)((long)param_7 + 0x11) & 4) != 0) goto joined_r0x00b3d741;
      uVar18 = (ulong)*(byte *)((long)pppppppcVar17 + 1);
    }
    else {
      *(undefined8 *)(puVar28 + -0x10) = 1;
      pppppppcVar34 = local_90;
      lVar15 = local_98;
      local_f0 = param_6;
      *(undefined8 *)(puVar28 + -0x18) = 0xb404c6;
      iVar21 = FUN_00b3b600(param_1,lVar15,pppppppcVar20,pppppppcVar16,pppppppcVar34,uVar35);
      if (iVar21 == 0) goto joined_r0x00b3d741;
      uVar18 = (ulong)*(byte *)((long)pppppppcVar17 + 1);
      param_5 = local_80;
      param_6 = local_f0;
    }
    goto LAB_00b3cde0;
  case (undefined *)0xb3fb50:
    if (local_90 == pppppppcVar20) {
      if ((*(byte *)((long)param_7 + 0x11) & 4) != 0) goto joined_r0x00b3d741;
      uVar18 = (ulong)*(byte *)((long)pppppppcVar17 + 1);
      goto LAB_00b3cde0;
    }
    *(undefined8 *)(puVar28 + -0x10) = 1;
    lVar15 = local_98;
    pppppppcVar16 = local_c8;
    local_f0 = param_6;
    *(undefined8 *)(puVar28 + -0x18) = 0xb4052e;
    iVar21 = FUN_00b3b600(param_1,lVar15,pppppppcVar20,pppppppcVar16,pppppppcVar30,uVar35);
    if (iVar21 == 0) goto joined_r0x00b3d741;
    local_f8 = local_f0;
    pcVar5 = *(code **)(local_98 + 8);
    *(undefined8 *)(puVar28 + -8) = 0xb40558;
    iVar21 = (*pcVar5)(param_1);
    pppppppcVar16 = local_80;
    pppppppcVar20 = local_90;
    local_f0 = (code *******)((long)local_80 + (long)iVar21);
    if (local_90 == local_f0) {
      uVar18 = (ulong)*(byte *)((long)pppppppcVar17 + 1);
      param_5 = local_80;
      param_6 = local_f8;
      goto LAB_00b3cde0;
    }
    if ((local_e4 & 0x8000) == 0) goto joined_r0x00b3d741;
    pcVar5 = *(code **)(local_98 + 0x38);
    *(undefined8 *)(puVar28 + -8) = 0xb405ae;
    iVar21 = (*pcVar5)(param_1,pppppppcVar16,pppppppcVar20);
    pppppppcVar20 = local_80;
    if (iVar21 != 0xd) goto joined_r0x00b3d741;
    pcVar5 = *(code **)(local_98 + 0x38);
    pcVar4 = *(code **)(local_98 + 8);
    *(undefined8 *)(puVar28 + -8) = 0xb405da;
    iVar21 = (*pcVar4)(param_1,pppppppcVar20);
    pppppppcVar20 = local_90;
    pbVar29 = (byte *)((long)local_80 + (long)iVar21);
    *(undefined8 *)(puVar28 + -8) = 0xb405ed;
    iVar21 = (*pcVar5)(param_1,pbVar29,pppppppcVar20);
    pppppppcVar20 = local_f0;
    if (iVar21 != 10) goto joined_r0x00b3d741;
    pcVar5 = *(code **)(local_98 + 8);
    *(undefined8 *)(puVar28 + -8) = 0xb4061b;
    iVar21 = (*pcVar5)(param_1);
    if (local_90 != (code *******)((long)pppppppcVar20 + (long)iVar21)) goto joined_r0x00b3d741;
    uVar18 = (ulong)*(byte *)((long)pppppppcVar17 + 1);
    param_5 = local_80;
    param_6 = local_f8;
    goto LAB_00b3cde0;
  case (undefined *)0xb3fb78:
    uVar18 = (ulong)*(byte *)((long)pppppppcVar17 + 1);
    local_a0 = pppppppcVar20;
    goto LAB_00b3cde0;
  case (undefined *)0xb3fb8c:
    pppppppcVar36 = (code *******)((long)pppppppcVar17 + 3);
    pppppppcVar37[*(short *)((long)pppppppcVar17 + 1)] = (code ******)pppppppcVar20;
    uVar18 = (ulong)*(byte *)pppppppcVar36;
    goto LAB_00b3cde0;
  case (undefined *)0xb3fba3:
    pppppppcVar36 = (code *******)((long)pppppppcVar17 + 3);
    uVar33 = *(ushort *)((long)pppppppcVar17 + 1);
    if (local_68 == local_70 || (long)local_68 - (long)local_70 < 0) {
      local_f0 = (code *******)CONCAT44(local_f0._4_4_,(uint)uVar33);
      local_f8 = param_6;
      *(undefined8 *)(puVar28 + -8) = 0xb40902;
      iVar21 = FUN_00b3cb70(&local_78,&local_68,&local_70,pppppppcVar34,param_7,param_7 + 1);
      if (iVar21 != 0) goto LAB_00b3fe49;
      uVar33 = (ushort)local_f0;
      pppppppcVar20 = local_80;
      param_6 = local_f8;
    }
    local_70[2] = (code ******)pppppppcVar20;
    *(int *)(local_70 + 1) = (int)(short)uVar33;
    ppppppcVar27 = pppppppcVar37[(short)uVar33];
    *(uint *)local_70 = 0x8200;
    local_70[3] = ppppppcVar27;
    local_70[4] = local_a8[(short)uVar33];
    lVar15 = (long)local_70 - (long)local_78;
    local_70 = local_70 + 5;
    local_a8[(short)uVar33] = (code ******)((lVar15 >> 3) * -0x3333333333333333);
    uVar18 = (ulong)*(byte *)((long)pppppppcVar17 + 3);
    param_5 = pppppppcVar20;
    goto LAB_00b3cde0;
  }
  if (local_b0 < iVar21) goto joined_r0x00b3d741;
  ppppppcVar27 = local_a8[sVar24];
  if ((ppppppcVar27 == (code ******)0xffffffffffffffff) ||
     (pppppppcVar17 = (code *******)pppppppcVar37[sVar24],
     pppppppcVar17 == (code *******)0xffffffffffffffff)) goto joined_r0x00b3d741;
  if (sVar24 < 0x20) {
    uVar35 = 1 << ((byte)iVar21 & 0x1f);
    if ((uVar35 & *(uint *)((long)local_c0 + 0x2c)) != 0) {
      pppppppcVar17 = (code *******)local_78[(long)pppppppcVar17 * 5 + 2];
    }
    bVar31 = (*(uint *)(local_c0 + 6) & uVar35) != 0;
  }
  else {
    if ((*(uint *)((long)local_c0 + 0x2c) & 1) != 0) {
      pppppppcVar17 = (code *******)local_78[(long)pppppppcVar17 * 5 + 2];
    }
    local_f0._0_1_ = (byte)(int)local_c0[6];
    bVar31 = (bool)((byte)local_f0 & 1);
  }
  if (bVar31 != false) {
    ppppppcVar27 = local_78[(long)ppppppcVar27 * 5 + 2];
  }
  local_f0 = (code *******)((long)pppppppcVar17 + ((long)ppppppcVar27 - (long)pppppppcVar17));
  if ((long)local_90 < (long)((long)pppppppcVar20 + ((long)ppppppcVar27 - (long)pppppppcVar17)))
  goto joined_r0x00b3d741;
  local_f8 = pppppppcVar36;
  if (local_f0 == pppppppcVar17 || (long)local_f0 - (long)pppppppcVar17 < 0) goto LAB_00b3d11b;
  goto LAB_00b3d0bf;
switchD_00b3cded_caseD_b3da2b:
  sVar24 = *(short *)((long)pppppppcVar17 + 1);
  pppppppcVar36 = (code *******)((long)pppppppcVar17 + 7);
  if (((local_b0 < sVar24) || (local_a8[sVar24] == (code ******)0xffffffffffffffff)) ||
     (pppppppcVar37[sVar24] == (code ******)0xffffffffffffffff)) {
    pppppppcVar36 = (code *******)((long)pppppppcVar36 + (long)*(int *)((long)pppppppcVar17 + 3));
    uVar18 = (ulong)*(byte *)pppppppcVar36;
  }
  else {
    uVar18 = (ulong)*(byte *)((long)pppppppcVar17 + 7);
  }
  goto LAB_00b3cde0;
LAB_00b3d6e0:
  local_70 = local_70 + -5;
  uVar35 = *(uint *)local_70;
  if (uVar35 != 2) {
    while (uVar35 != 0x100) {
      if (uVar35 == 0x300) {
        *(uint *)(local_78 + (long)local_70[1] * 5 + 1) =
             *(uint *)(local_78 + (long)local_70[1] * 5 + 1) - 1;
        goto LAB_00b3d6e0;
      }
      if (uVar35 != 0x8200) goto LAB_00b3d6e0;
      pppppppcVar36 = local_70 + -5;
      pppppppcVar37[(int)*(uint *)(local_70 + 1)] = local_70[3];
      local_a8[(int)*(uint *)(local_70 + 1)] = local_70[4];
      uVar35 = *(uint *)pppppppcVar36;
      local_70 = pppppppcVar36;
      if (uVar35 == 2) goto joined_r0x00b3d741;
    }
    pppppppcVar37[(int)*(uint *)(local_70 + 1)] = local_70[3];
    local_a8[(int)*(uint *)(local_70 + 1)] = local_70[4];
    goto LAB_00b3d6e0;
  }
  goto joined_r0x00b3d741;
LAB_00b3d508:
  pppppppcVar36 = local_70;
  local_70 = pppppppcVar36 + -5;
  uVar35 = *(uint *)local_70;
  if (uVar35 != 3) {
    if (uVar35 == 0x100) {
LAB_00b3d51e:
      pppppppcVar37[(int)*(uint *)(pppppppcVar36 + -4)] = pppppppcVar36[-2];
      local_a8[(int)*(uint *)(pppppppcVar36 + -4)] = pppppppcVar36[-1];
    }
    else if (uVar35 == 0x300) {
      *(uint *)(local_78 + (long)pppppppcVar36[-4] * 5 + 1) =
           *(uint *)(local_78 + (long)pppppppcVar36[-4] * 5 + 1) - 1;
    }
    else if (uVar35 == 0x8200) goto LAB_00b3d51e;
    goto LAB_00b3d508;
  }
  goto joined_r0x00b3d741;
code_r0x00b3d32f:
  bVar13 = *(byte *)((long)pppppppcVar17 + 3);
  uVar18 = (ulong)bVar13;
  pppppppcVar25 = (code *******)((long)pppppppcVar17 + 4);
  pppppppcVar17 = pppppppcVar36;
  goto joined_r0x00b3cde7;
LAB_00b3e557:
  local_60 = pppppppcVar36 + -5;
  uVar35 = *(uint *)(pppppppcVar36 + -5);
  pppppppcVar36 = local_60;
  if (uVar35 == 0x700) goto code_r0x00b3e565;
  goto joined_r0x00b3e584;
code_r0x00b3e565:
  if (iVar21 == 0) {
    do {
      if (*(uint *)(local_60 + 3) == (int)*(short *)((long)pppppppcVar17 + 1)) {
        ppppppcVar27 = (code ******)(((long)local_60 - (long)local_78 >> 3) * -0x3333333333333333);
        lVar15 = (long)*(short *)((long)pppppppcVar17 + 1) << 3;
        goto LAB_00b3e348;
      }
      local_60 = local_60 + -5;
      uVar35 = *(uint *)local_60;
      pppppppcVar36 = local_60;
    } while (uVar35 == 0x700);
joined_r0x00b3e584:
    if (uVar35 == 0x800) {
      iVar21 = iVar21 + -1;
    }
    else {
      iVar21 = iVar21 + (uint)(uVar35 == 0x900);
    }
  }
  goto LAB_00b3e557;
LAB_00b3e147:
  local_60 = pppppppcVar36 + -5;
  uVar35 = *(uint *)(pppppppcVar36 + -5);
  pppppppcVar36 = local_60;
  if (uVar35 == 0x700) goto code_r0x00b3e155;
  goto joined_r0x00b3e174;
code_r0x00b3e155:
  if (iVar21 == 0) {
    do {
      if (*(uint *)(local_60 + 3) == (int)*(short *)((long)pppppppcVar17 + 1)) {
        ppppppcVar27 = (code ******)(((long)local_60 - (long)local_78 >> 3) * -0x3333333333333333);
        lVar15 = (long)*(short *)((long)pppppppcVar17 + 1) << 3;
        goto LAB_00b3e02e;
      }
      local_60 = local_60 + -5;
      uVar35 = *(uint *)local_60;
      pppppppcVar36 = local_60;
    } while (uVar35 == 0x700);
joined_r0x00b3e174:
    if (uVar35 == 0x800) {
      iVar21 = iVar21 + -1;
    }
    else {
      iVar21 = iVar21 + (uint)(uVar35 == 0x900);
    }
  }
  goto LAB_00b3e147;
LAB_00b3fa20:
  if (pppppppcVar20 <= local_78) goto LAB_00b4007d;
  pppppppcVar16 = pppppppcVar20 + -5;
  if ((*(uint *)pppppppcVar16 & 0x8000) == 0) {
    if ((*(uint *)pppppppcVar16 == 0x100) && (*(uint *)(pppppppcVar20 + -4) == (int)sVar24)) {
      pppppppcVar20 = pppppppcVar16;
      if (iVar21 == 0) goto LAB_00b40085;
      iVar21 = iVar21 + -1;
    }
  }
  else {
    iVar21 = iVar21 + (uint)(*(uint *)(pppppppcVar20 + -4) == (int)sVar24);
  }
  bVar31 = true;
  pppppppcVar20 = pppppppcVar16;
  goto LAB_00b3fa20;
LAB_00b4007d:
  local_60 = local_70;
  if (bVar31) {
LAB_00b40085:
    local_60 = pppppppcVar20;
  }
  bVar31 = (bool)((byte)*(uint *)((long)local_c0 + 0x2c) & 1);
  if (sVar24 < 0x20) {
    bVar31 = (1 << ((byte)sVar24 & 0x1f) & *(uint *)((long)local_c0 + 0x2c)) != 0;
  }
  if (bVar31 == false) {
    pppppppcVar37[sVar24] = local_60[2];
  }
  else {
    pppppppcVar37[sVar24] =
         (code ******)(((long)local_60 - (long)local_78 >> 3) * -0x3333333333333333);
  }
  if (local_68 == local_70 || (long)local_68 - (long)local_70 < 0) {
    local_f0 = (code *******)CONCAT44(local_f0._4_4_,(int)sVar24);
    local_f8 = param_6;
    *(undefined8 *)(puVar28 + -8) = 0xb406f2;
    iVar21 = FUN_00b3cb70(&local_78,&local_68,&local_70,pppppppcVar34,param_7,param_7 + 1);
    if (iVar21 != 0) goto LAB_00b3fe49;
    sVar24 = (short)local_f0;
    param_6 = local_f8;
  }
  *(uint *)local_70 = 0x8400;
  *(int *)(local_70 + 1) = (int)sVar24;
  uVar18 = (ulong)*(byte *)((long)pppppppcVar17 + 3);
  param_5 = local_80;
  local_70 = local_70 + 5;
  goto LAB_00b3cde0;
LAB_00b3f67f:
  if (pppppppcVar16 <= local_78) goto LAB_00b3ffef;
  pppppppcVar30 = pppppppcVar16 + -5;
  if ((*(uint *)pppppppcVar30 & 0x8000) == 0) {
    if ((*(uint *)pppppppcVar30 == 0x100) && (*(uint *)(pppppppcVar16 + -4) == uVar35)) {
      pppppppcVar16 = pppppppcVar30;
      if (iVar21 == 0) goto LAB_00b3fff3;
      iVar21 = iVar21 + -1;
    }
  }
  else {
    iVar21 = iVar21 + (uint)(*(uint *)(pppppppcVar16 + -4) == uVar35);
  }
  bVar31 = true;
  pppppppcVar16 = pppppppcVar30;
  goto LAB_00b3f67f;
LAB_00b3ffef:
  if (bVar31) {
LAB_00b3fff3:
    local_60 = pppppppcVar16;
  }
  if (local_68 == local_70 || (long)local_68 - (long)local_70 < 0) {
    local_f0 = (code *******)CONCAT44(local_f0._4_4_,uVar35);
    local_f8 = param_6;
    *(undefined8 *)(puVar28 + -8) = 0xb409e2;
    iVar21 = FUN_00b3cb70(&local_78,&local_68,&local_70,pppppppcVar34,param_7,param_7 + 1);
    if (iVar21 != 0) {
LAB_00b3fe49:
      if (local_78 != local_b8) {
        *param_7 = local_78;
        param_7[1] = ((long)local_68 - (long)local_78 >> 3) * -0x3333333333333333;
      }
LAB_00b3d6c9:
      return (long)iVar21;
    }
    sVar24 = (short)local_f0;
    pppppppcVar20 = local_80;
    param_6 = local_f8;
  }
  local_70[2] = (code ******)pppppppcVar20;
  *(int *)(local_70 + 1) = (int)sVar24;
  *(uint *)local_70 = 0x8200;
  local_70[3] = pppppppcVar37[sVar24];
  local_70[4] = local_a8[sVar24];
  local_a8[sVar24] = (code ******)(((long)local_70 - (long)local_78 >> 3) * -0x3333333333333333);
  pppppppcVar37[sVar24] =
       (code ******)(((long)local_60 - (long)local_78 >> 3) * -0x3333333333333333);
  uVar18 = (ulong)*(byte *)((long)pppppppcVar17 + 3);
  param_5 = pppppppcVar20;
  local_70 = local_70 + 5;
  goto LAB_00b3cde0;
LAB_00b3e5f2:
  do {
    uVar35 = *(uint *)pppppppcVar36;
    if (uVar35 == 0x800) {
      iVar22 = iVar22 + -1;
    }
    else if (uVar35 == 0x900) {
      iVar22 = iVar22 + 1;
    }
    else if (*(int *)((long)pppppppcVar17 + 5) == iVar22) {
      if (uVar35 == 0x100) {
        if (0 < iVar21) {
          sVar24 = *(short *)((long)pppppppcVar17 + 0xd);
          pbVar7 = (byte *)((long)pppppppcVar17 + 0xf);
          while (*(uint *)(pppppppcVar36 + 1) != (int)sVar24) {
            if (pbVar7 == pbVar29) goto LAB_00b3e5e5;
            sVar24 = *(short *)pbVar7;
            pbVar7 = pbVar7 + 2;
          }
          if (local_f0 != (code *******)0xffffffffffffffff) {
            pppppppcVar36 = (code *******)pppppppcVar36[2];
            if ((long)local_f0 - (long)pppppppcVar36 <= (long)local_90 - (long)pppppppcVar20) {
              local_58 = pppppppcVar20;
              if (*(int *)((long)pppppppcVar17 + 1) == 0) {
                if ((long)pppppppcVar36 < (long)local_f0) goto LAB_00b40ac0;
                goto LAB_00b40f1d;
              }
              local_f0 = (code *******)local_c0[9];
              pppppppcVar16 = local_f0 + 0xb;
              *(undefined8 *)(puVar28 + -8) = 0xb41ddf;
              iVar22 = FUN_00b3b190(param_1,pppppppcVar16,uVar14,pppppppcVar36,&local_58);
              if (iVar22 != 0) goto LAB_00b40f1d;
            }
            break;
          }
        }
      }
      else if ((uVar35 == 0x8200) && (0 < iVar21)) {
        sVar24 = *(short *)((long)pppppppcVar17 + 0xd);
        pbVar7 = (byte *)((long)pppppppcVar17 + 0xf);
        while (*(uint *)(pppppppcVar36 + 1) != (int)sVar24) {
          if (pbVar7 == pbVar29) goto LAB_00b3e5e5;
          sVar24 = *(short *)pbVar7;
          pbVar7 = pbVar7 + 2;
        }
        local_f0 = (code *******)pppppppcVar36[2];
      }
    }
LAB_00b3e5e5:
    pppppppcVar36 = pppppppcVar36 + -5;
  } while (local_78 <= pppppppcVar36);
  goto joined_r0x00b3d741;
  while (pppppppcVar36 = local_f8, local_f0 != local_f8) {
LAB_00b40ac0:
    local_f8 = (code *******)((long)pppppppcVar36 + 1);
    uVar6 = param_1[1];
    pcVar5 = (code *)*param_1;
    *(undefined8 *)(puVar28 + -8) = 0xb40ad2;
    uVar11 = (*pcVar5)(pppppppcVar36,uVar6);
    local_100 = (code *******)CONCAT71(local_100._1_7_,uVar11);
    local_58 = (code *******)((long)local_58 + 1);
    pcVar5 = (code *)*param_1;
    *(undefined8 *)(puVar28 + -8) = 0xb40aeb;
    cVar12 = (*pcVar5)();
    bVar31 = (char)local_100 != cVar12;
    if (bVar31) goto joined_r0x00b3d741;
  }
LAB_00b40f1d:
  lVar15 = local_98;
  local_f0 = (code *******)CONCAT44(local_f0._4_4_,iVar21);
  local_80 = local_58;
  do {
    param_6 = pppppppcVar20;
    pcVar5 = *(code **)(lVar15 + 8);
    *(undefined8 *)(puVar28 + -8) = 0xb40f4c;
    iVar21 = (*pcVar5)(param_1);
    pppppppcVar20 = (code *******)((long)param_6 + (long)iVar21);
  } while ((long)pppppppcVar20 < (long)local_80);
  pppppppcVar36 = (code *******)((long)pppppppcVar17 + (long)((int)local_f0 * 2) + 0xd);
  uVar18 = (ulong)*(byte *)pppppppcVar36;
  param_5 = local_80;
  goto LAB_00b3cde0;
LAB_00b3e445:
  uVar14 = local_e8;
  sVar24 = *(short *)pppppppcVar36;
  pppppppcVar36 = (code *******)((long)pppppppcVar36 + 2);
  ppppppcVar27 = local_a8[sVar24];
  if ((ppppppcVar27 != (code ******)0xffffffffffffffff) &&
     (ppppppcVar19 = pppppppcVar37[sVar24], ppppppcVar19 != (code ******)0xffffffffffffffff)) {
    if (sVar24 < 0x20) {
      uVar35 = 1 << ((byte)sVar24 & 0x1f);
      if ((uVar35 & *(uint *)((long)plVar8 + 0x2c)) != 0) {
        ppppppcVar19 = local_78[(long)ppppppcVar19 * 5 + 2];
      }
      bVar31 = (*(uint *)(plVar8 + 6) & uVar35) != 0;
    }
    else {
      if ((*(uint *)((long)plVar8 + 0x2c) & 1) != 0) {
        ppppppcVar19 = local_78[(long)ppppppcVar19 * 5 + 2];
      }
      bVar31 = (bool)(*(byte *)(plVar8 + 6) & 1);
    }
    if (bVar31 != false) {
      ppppppcVar27 = local_78[(long)ppppppcVar27 * 5 + 2];
    }
    if ((long)local_90 < (long)((long)local_80 + ((long)ppppppcVar27 - (long)ppppppcVar19)))
    goto joined_r0x00b3d741;
    local_58 = local_80;
    local_f8 = local_80;
    lVar15 = local_98 + 0x58;
    *(undefined8 *)(puVar28 + -8) = 0xb3e4f5;
    iVar22 = FUN_00b3b190(param_1,lVar15,uVar14,ppppppcVar19,&local_58);
    lVar15 = local_98;
    pppppppcVar20 = local_f8;
    if (iVar22 != 0) {
      local_f8 = (code *******)CONCAT44(local_f8._4_4_,iVar21);
      local_80 = local_58;
      do {
        param_6 = pppppppcVar20;
        pcVar5 = *(code **)(lVar15 + 8);
        *(undefined8 *)(puVar28 + -8) = 0xb40854;
        iVar21 = (*pcVar5)(param_1);
        pppppppcVar20 = (code *******)((long)param_6 + (long)iVar21);
      } while ((long)param_6 + (long)iVar21 < (long)local_80);
      pppppppcVar36 =
           (code *******)((long)pppppppcVar36 + (long)(((int)local_f0 - (int)local_f8) * 2 + -2));
LAB_00b40881:
      uVar18 = (ulong)*(byte *)pppppppcVar36;
      param_5 = local_80;
      goto LAB_00b3cde0;
    }
  }
  iVar21 = iVar21 + 1;
  if ((int)local_f0 == iVar21) goto joined_r0x00b3d741;
  goto LAB_00b3e445;
LAB_00b3e1b3:
  do {
    sVar24 = *(short *)local_100;
    local_100 = (code *******)((long)local_100 + 2);
    ppppppcVar27 = local_a8[sVar24];
    if ((ppppppcVar27 != (code ******)0xffffffffffffffff) &&
       (ppppppcVar19 = local_108[sVar24], ppppppcVar19 != (code ******)0xffffffffffffffff)) {
      if (sVar24 < 0x20) {
        uVar35 = 1 << ((byte)sVar24 & 0x1f);
        if ((uVar35 & *(uint *)((long)local_c0 + 0x2c)) != 0) {
          ppppppcVar19 = local_78[(long)ppppppcVar19 * 5 + 2];
        }
        bVar31 = (*(uint *)(local_c0 + 6) & uVar35) != 0;
      }
      else {
        if ((*(uint *)((long)local_c0 + 0x2c) & 1) != 0) {
          ppppppcVar19 = local_78[(long)ppppppcVar19 * 5 + 2];
        }
        local_f0._0_1_ = (byte)(int)local_c0[6];
        bVar31 = (bool)((byte)local_f0 & 1);
      }
      if (bVar31 != false) {
        ppppppcVar27 = local_78[(long)ppppppcVar27 * 5 + 2];
      }
      local_f0 = (code *******)((long)local_80 + ((long)ppppppcVar27 - (long)ppppppcVar19));
      local_118 = local_80;
      pppppppcVar37 = local_108;
      if ((long)local_90 < (long)local_f0) break;
      lVar15 = (long)ppppppcVar19 - (long)local_80;
      pppppppcVar36 = local_80;
      do {
        lVar32 = local_98;
        pppppppcVar37 = local_108;
        pppppppcVar20 = local_118;
        if (local_f0 == pppppppcVar36 || (long)local_f0 - (long)pppppppcVar36 < 0)
        goto LAB_00b3e2db;
        uVar6 = param_1[1];
        pcVar5 = (code *)*param_1;
        *(undefined8 *)(puVar28 + -8) = 0xb3e28c;
        cVar12 = (*pcVar5)((byte *)((long)pppppppcVar36 + lVar15),uVar6);
        pcVar5 = (code *)*param_1;
        *(undefined8 *)(puVar28 + -8) = 0xb3e298;
        cVar9 = (*pcVar5)(pppppppcVar36);
        pppppppcVar36 = (code *******)((long)pppppppcVar36 + 1);
      } while (cVar12 == cVar9);
    }
    iVar21 = (int)local_f8 + 1;
    local_f8 = (code *******)CONCAT44(local_f8._4_4_,iVar21);
    pppppppcVar37 = local_108;
  } while (uStack_110._4_4_ != iVar21);
  goto joined_r0x00b3d741;
LAB_00b3e2db:
  do {
    local_80 = pppppppcVar36;
    param_6 = pppppppcVar20;
    pcVar5 = *(code **)(lVar32 + 8);
    *(undefined8 *)(puVar28 + -8) = 0xb3e2e6;
    iVar21 = (*pcVar5)(param_1);
    pppppppcVar20 = (code *******)((long)param_6 + (long)iVar21);
    pppppppcVar36 = local_80;
  } while ((long)pppppppcVar20 < (long)local_80);
  pppppppcVar36 =
       (code *******)((long)local_100 + (long)((uStack_110._4_4_ - (int)local_f8) * 2 + -2));
  uVar18 = (ulong)*(byte *)pppppppcVar36;
  param_5 = local_80;
  goto LAB_00b3cde0;
  while (pppppppcVar17 = pppppppcVar16, lVar15 = local_98, pppppppcVar36 = local_f8,
        local_f0 != pppppppcVar16 && -1 < (long)local_f0 - (long)pppppppcVar16) {
LAB_00b3d0bf:
    pppppppcVar16 = (code *******)((long)pppppppcVar17 + 1);
    uVar6 = param_1[1];
    pcVar5 = (code *)*param_1;
    *(undefined8 *)(puVar28 + -8) = 0xb3d0cc;
    cVar12 = (*pcVar5)(pppppppcVar17,uVar6);
    local_80 = (code *******)((long)local_80 + 1);
    pcVar5 = (code *)*param_1;
    *(undefined8 *)(puVar28 + -8) = 0xb3d0e4;
    cVar9 = (*pcVar5)();
    if (cVar12 != cVar9) goto joined_r0x00b3d741;
  }
LAB_00b3d11b:
  do {
    param_6 = pppppppcVar20;
    pcVar5 = *(code **)(lVar15 + 8);
    *(undefined8 *)(puVar28 + -8) = 0xb3d125;
    iVar21 = (*pcVar5)(param_1);
    pppppppcVar20 = (code *******)((long)param_6 + (long)iVar21);
  } while ((long)pppppppcVar20 < (long)local_80);
  uVar18 = (ulong)*(byte *)pppppppcVar36;
  param_5 = local_80;
  goto LAB_00b3cde0;
  while (pppppppcVar20 = (code *******)((long)local_80 + (long)iVar21), local_80 = pppppppcVar20,
        (long)pppppppcVar20 <= (long)local_90) {
LAB_00b3d20c:
    if ((long)local_90 <= (long)pppppppcVar20) {
      uVar18 = (ulong)*(byte *)((long)pppppppcVar17 + 2);
      pppppppcVar36 = (code *******)((long)pppppppcVar17 + 2);
      param_5 = pppppppcVar20;
      param_6 = local_f8;
      goto LAB_00b3cde0;
    }
    bVar13 = *(byte *)((long)pppppppcVar17 + 1);
    uVar6 = param_1[1];
    pcVar5 = (code *)*param_1;
    *(undefined8 *)(puVar28 + -8) = 0xb3d225;
    bVar10 = (*pcVar5)(pppppppcVar20,uVar6);
    pppppppcVar36 = local_b8;
    if (bVar13 == bVar10) {
      if ((long)local_68 - (long)local_70 < 1) {
        *(undefined8 *)(puVar28 + -8) = 0xb402fd;
        iVar21 = FUN_00b3cb70(&local_78,&local_68,&local_70,pppppppcVar36,param_7,param_7 + 1);
        if (iVar21 != 0) goto LAB_00b3fe49;
      }
      local_70[3] = (code ******)param_6;
      *(uint *)local_70 = 1;
      local_70[2] = (code ******)local_80;
      local_70[1] = (code ******)local_f0;
      local_70[4] = (code ******)local_a0;
      local_70 = local_70 + 5;
    }
    pcVar5 = *(code **)(local_98 + 8);
    *(undefined8 *)(puVar28 + -8) = 0xb3d23f;
    iVar21 = (*pcVar5)(param_1);
    param_6 = local_80;
    if ((long)iVar21 < 2) {
      pppppppcVar20 = (code *******)((long)local_80 + 1);
      local_80 = pppppppcVar20;
      goto LAB_00b3d20c;
    }
  }
  goto joined_r0x00b3d741;
  while( true ) {
    pcVar5 = *(code **)(local_98 + 8);
    *(undefined8 *)(puVar28 + -8) = 0xb3ef95;
    iVar21 = (*pcVar5)(param_1);
    pppppppcVar20 = local_80;
    lVar15 = local_98;
    pppppppcVar36 = local_c8;
    uVar35 = local_e4;
    pppppppcVar37 = local_f0;
    if ((long)pppppppcVar30 < (long)((long)local_80 + (long)iVar21)) goto joined_r0x00b3d741;
    *(undefined8 *)(puVar28 + -0x10) = 0;
    *(undefined8 *)(puVar28 + -0x18) = 0xb3efcf;
    iVar22 = FUN_00b3b600(param_1,lVar15,pppppppcVar20,pppppppcVar36,pppppppcVar30,uVar35);
    pppppppcVar37 = local_f0;
    if (iVar22 != 0) goto joined_r0x00b3d741;
    pppppppcVar20 = (code *******)((long)local_80 + (long)iVar21);
    pppppppcVar16 = local_100;
    param_6 = local_80;
    local_80 = pppppppcVar20;
    if ((long)pppppppcVar30 <= (long)pppppppcVar20) break;
LAB_00b3ef70:
    bVar13 = *(byte *)((long)pppppppcVar17 + 1);
    uVar6 = param_1[1];
    pcVar5 = (code *)*param_1;
    *(undefined8 *)(puVar28 + -8) = 0xb3ef7c;
    bVar10 = (*pcVar5)(pppppppcVar20,uVar6);
    pppppppcVar36 = local_b8;
    if (bVar13 == bVar10) {
      if ((long)local_68 - (long)local_70 < 1) {
        *(undefined8 *)(puVar28 + -8) = 0xb4180f;
        iVar21 = FUN_00b3cb70(&local_78,&local_68,&local_70,pppppppcVar36,param_7,param_7 + 1);
        if (iVar21 != 0) goto LAB_00b3fe49;
      }
      local_70[3] = (code ******)param_6;
      *(uint *)local_70 = 1;
      local_70[1] = (code ******)local_f8;
      local_70[2] = (code ******)local_80;
      local_70[4] = (code ******)local_a0;
      local_70 = local_70 + 5;
    }
  }
LAB_00b3eff8:
  uVar18 = (ulong)*(byte *)((long)pppppppcVar17 + 2);
  pppppppcVar36 = (code *******)((long)pppppppcVar17 + 2);
  param_5 = pppppppcVar20;
  param_6 = pppppppcVar16;
  goto LAB_00b3cde0;
  while (param_5 = (code *******)((long)local_80 + (long)iVar21), local_80 = param_5,
        (long)param_5 <= (long)local_90) {
LAB_00b3d174:
    pppppppcVar34 = local_b8;
    pppppppcVar16 = local_f8;
    if ((long)local_90 <= (long)param_5) {
      uVar18 = (ulong)*(byte *)((long)pppppppcVar17 + 1);
      param_6 = pppppppcVar20;
      goto LAB_00b3cde0;
    }
    if ((long)local_68 - (long)local_70 < 1) {
      local_f0 = param_6;
      *(undefined8 *)(puVar28 + -8) = 0xb3fdf8;
      iVar21 = FUN_00b3cb70(&local_78,&local_68,&local_70,pppppppcVar34,param_7,pppppppcVar16);
      param_5 = local_80;
      param_6 = local_f0;
      if (iVar21 != 0) goto LAB_00b3fe49;
    }
    local_70[2] = (code ******)param_5;
    local_70[3] = (code ******)param_6;
    local_70[4] = (code ******)local_a0;
    *(uint *)local_70 = 1;
    local_70[1] = (code ******)pppppppcVar36;
    pcVar5 = *(code **)(local_98 + 8);
    local_70 = local_70 + 5;
    *(undefined8 *)(puVar28 + -8) = 0xb3d1c8;
    iVar21 = (*pcVar5)(param_1);
    param_6 = local_80;
    if ((long)iVar21 < 2) {
      param_5 = (code *******)((long)local_80 + 1);
      local_80 = param_5;
      goto LAB_00b3d174;
    }
  }
  goto joined_r0x00b3d741;
  while( true ) {
    local_70[1] = (code ******)pppppppcVar36;
    *(uint *)local_70 = 1;
    local_70[2] = (code ******)local_80;
    local_70[4] = (code ******)local_a0;
    local_70[3] = (code ******)param_6;
    pcVar5 = *(code **)(local_98 + 8);
    local_70 = local_70 + 5;
    *(undefined8 *)(puVar28 + -8) = 0xb3e772;
    iVar21 = (*pcVar5)(param_1);
    if ((long)pppppppcVar30 < (long)((long)local_80 + (long)iVar21)) goto joined_r0x00b3d741;
    *(undefined8 *)(puVar28 + -0x10) = 0;
    *(undefined8 *)(puVar28 + -0x18) = 0xb3e7ac;
    iVar22 = FUN_00b3b600(param_1);
    if (iVar22 != 0) goto joined_r0x00b3d741;
    param_5 = (code *******)((long)local_80 + (long)iVar21);
    param_6 = local_80;
    local_80 = param_5;
    if ((long)pppppppcVar30 <= (long)param_5) break;
LAB_00b3e727:
    pppppppcVar17 = local_b8;
    pppppppcVar20 = local_f0;
    if ((long)local_68 - (long)local_70 < 1) {
      local_108 = param_6;
      *(undefined8 *)(puVar28 + -8) = 0xb40460;
      iVar21 = FUN_00b3cb70(&local_78,&local_68,&local_70,pppppppcVar17,param_7,pppppppcVar20);
      param_6 = local_108;
      if (iVar21 != 0) goto LAB_00b3fe49;
    }
  }
  uVar18 = (ulong)*(byte *)((long)local_f8 + 1);
  param_6 = local_100;
  goto LAB_00b3cde0;
  while( true ) {
    if (0 < iVar21) {
      if ((byte)local_58 != *(byte *)pppppppcVar36) break;
      pppppppcVar20 = (code *******)((long)pppppppcVar36 + (ulong)(iVar21 - 1) + 1);
      pbVar29 = (byte *)&local_58;
      while( true ) {
        pppppppcVar36 = (code *******)((long)pppppppcVar36 + 1);
        pbVar29 = pbVar29 + 1;
        if (pppppppcVar36 == pppppppcVar20) break;
        if (*(byte *)pppppppcVar36 != *pbVar29) goto joined_r0x00b3d741;
      }
    }
    pppppppcVar20 = local_80;
    if (local_f8 <= pppppppcVar36) goto LAB_00b40c1f;
    pppppppcVar16 = local_f0;
    param_6 = local_80;
    if (local_80 == local_90) break;
LAB_00b3dd6c:
    pppppppcVar20 = local_90;
    uVar14 = local_e8;
    pcVar5 = *(code **)(local_98 + 0x58);
    local_f0 = pppppppcVar16;
    *(undefined8 *)(puVar28 + -8) = 0xb3dd93;
    iVar21 = (*pcVar5)(param_1,uVar14,pppppppcVar16,pppppppcVar20,&local_58);
    if ((long)local_90 < (long)local_80) break;
  }
  goto joined_r0x00b3d741;
LAB_00b40c1f:
  uVar18 = (ulong)*(byte *)pppppppcVar36;
  param_5 = pppppppcVar20;
  goto LAB_00b3cde0;
  while (*(byte *)pppppppcVar36 == *(byte *)pppppppcVar17) {
LAB_00b3dad4:
    pppppppcVar36 = (code *******)((long)pppppppcVar36 + 1);
    pppppppcVar17 = (code *******)((long)pppppppcVar17 + 1);
    if (pppppppcVar36 == pppppppcVar16) goto LAB_00b41d18;
  }
joined_r0x00b3d741:
  if (local_ac == 0) {
    do {
      local_70 = local_70 + -5;
    } while (*(byte *)local_70 == 0);
  }
  else if (local_ac == 1) {
    while( true ) {
      pppppppcVar36 = local_70;
      local_70 = pppppppcVar36 + -5;
      if ((char)*(uint *)(pppppppcVar36 + -5) != '\0') break;
      if (*(uint *)(pppppppcVar36 + -5) == 0x100) {
        pppppppcVar37[(int)*(uint *)(pppppppcVar36 + -4)] = pppppppcVar36[-2];
        local_a8[(int)*(uint *)(pppppppcVar36 + -4)] = pppppppcVar36[-1];
      }
    }
  }
  else {
    while( true ) {
      pppppppcVar36 = local_70;
      local_70 = pppppppcVar36 + -5;
      uVar35 = *(uint *)local_70;
      if ((char)uVar35 != '\0') break;
      if (uVar35 == 0x100) {
LAB_00b3f4c5:
        pppppppcVar37[(int)*(uint *)(pppppppcVar36 + -4)] = pppppppcVar36[-2];
        local_a8[(int)*(uint *)(pppppppcVar36 + -4)] = pppppppcVar36[-1];
      }
      else if (uVar35 == 0x300) {
        *(uint *)(local_78 + (long)pppppppcVar36[-4] * 5 + 1) =
             *(uint *)(local_78 + (long)pppppppcVar36[-4] * 5 + 1) - 1;
      }
      else if (uVar35 == 0x8200) goto LAB_00b3f4c5;
    }
  }
  pppppppcVar36 = (code *******)local_70[1];
  uVar18 = (ulong)*(byte *)pppppppcVar36;
  param_5 = (code *******)local_70[2];
  param_6 = (code *******)local_70[3];
  local_a0 = (code *******)local_70[4];
  local_80 = (code *******)local_70[2];
  goto LAB_00b3cde0;
LAB_00b41d18:
  pppppppcVar36 = pppppppcVar16;
  uVar18 = (ulong)*(byte *)pppppppcVar36;
  param_5 = local_80;
  param_6 = pppppppcVar20;
  goto LAB_00b3cde0;
  while( true ) {
    pppppppcVar36 = (code *******)((long)pppppppcVar36 + 1);
    pppppppcVar20 = (code *******)((long)local_80 + 1);
    local_80 = pppppppcVar20;
    if (pppppppcVar36 == pppppppcVar17) break;
LAB_00b3dcea:
    bVar13 = *(byte *)pppppppcVar36;
    pcVar5 = (code *)*param_1;
    *(undefined8 *)(puVar28 + -8) = 0xb3dcf7;
    bVar10 = (*pcVar5)(pppppppcVar20);
    if (bVar13 != bVar10) goto joined_r0x00b3d741;
  }
  pppppppcVar36 = pppppppcVar17;
  iVar21 = (int)local_f0;
LAB_00b3dd21:
  uVar18 = (ulong)*(byte *)pppppppcVar36;
  param_5 = pppppppcVar20;
  param_6 = (code *******)((long)pppppppcVar20 - (long)iVar21);
  goto LAB_00b3cde0;
  while( true ) {
    local_80 = (code *******)((long)local_80 + 1);
    bVar13 = *(byte *)((long)pppppppcVar36 + 1);
    pcVar5 = (code *)*param_1;
    *(undefined8 *)(puVar28 + -8) = 0xb3db56;
    bVar10 = (*pcVar5)();
    if (bVar13 != bVar10) goto joined_r0x00b3d741;
    local_80 = (code *******)((long)local_80 + 1);
    bVar13 = *(byte *)((long)pppppppcVar36 + 2);
    pcVar5 = (code *)*param_1;
    *(undefined8 *)(puVar28 + -8) = 0xb3db77;
    bVar10 = (*pcVar5)();
    if (bVar13 != bVar10) goto joined_r0x00b3d741;
    pppppppcVar36 = (code *******)((long)pppppppcVar36 + 3);
    pppppppcVar20 = (code *******)((long)local_80 + 1);
    local_80 = pppppppcVar20;
    if ((code *******)((long)pppppppcVar17 + (ulong)(iVar21 - 1) * 3 + 8) == pppppppcVar36) break;
LAB_00b3db29:
    bVar13 = *(byte *)pppppppcVar36;
    pcVar5 = (code *)*param_1;
    *(undefined8 *)(puVar28 + -8) = 0xb3db35;
    bVar10 = (*pcVar5)(pppppppcVar20);
    if (bVar13 != bVar10) goto joined_r0x00b3d741;
  }
LAB_00b3db97:
  uVar18 = (ulong)*(byte *)pppppppcVar36;
  param_5 = pppppppcVar20;
  param_6 = (code *******)((long)pppppppcVar20 + -3);
  goto LAB_00b3cde0;
  while( true ) {
    local_80 = (code *******)((long)local_80 + 1);
    bVar13 = *(byte *)((long)pppppppcVar36 + 1);
    pcVar5 = (code *)*param_1;
    *(undefined8 *)(puVar28 + -8) = 0xb3dc76;
    bVar10 = (*pcVar5)();
    if (bVar13 != bVar10) goto joined_r0x00b3d741;
    pppppppcVar36 = (code *******)((long)pppppppcVar36 + 2);
    pppppppcVar20 = (code *******)((long)local_80 + 1);
    local_80 = pppppppcVar20;
    if ((code *******)((long)pppppppcVar17 + (ulong)(iVar21 - 1) * 2 + 7) == pppppppcVar36) break;
LAB_00b3dc49:
    bVar13 = *(byte *)pppppppcVar36;
    pcVar5 = (code *)*param_1;
    *(undefined8 *)(puVar28 + -8) = 0xb3dc55;
    bVar10 = (*pcVar5)(pppppppcVar20);
    if (bVar13 != bVar10) goto joined_r0x00b3d741;
  }
LAB_00b3dc96:
  uVar18 = (ulong)*(byte *)pppppppcVar36;
  param_5 = pppppppcVar20;
  param_6 = (code *******)((long)pppppppcVar20 + -2);
  goto LAB_00b3cde0;
joined_r0x00b3df5f:
  if (iVar22 - iVar21 < 1) goto LAB_00b3df8f;
  local_80 = (code *******)((long)pppppppcVar20 + 1);
  pcVar5 = (code *)*param_1;
  *(undefined8 *)(puVar28 + -8) = 0xb3df70;
  bVar10 = (*pcVar5)();
  if (bVar10 != bVar13) goto joined_r0x00b3d741;
  pppppppcVar36 = (code *******)((long)pppppppcVar36 + 1);
  bVar13 = *(byte *)pppppppcVar36;
  iVar21 = (int)pppppppcVar36;
  pppppppcVar20 = local_80;
  goto joined_r0x00b3df5f;
LAB_00b3df8f:
  uVar18 = (ulong)bVar13;
  param_5 = pppppppcVar20;
  param_6 = (code *******)((long)pppppppcVar20 + -1);
  goto LAB_00b3cde0;
LAB_00b3d3a0:
  do {
    pppppppcVar36 = pppppppcVar36 + -5;
    uVar3 = *(uint *)pppppppcVar36;
    while (uVar3 != 0x3000) {
      if (uVar3 != 0x5000) goto LAB_00b3d3a0;
      pppppppcVar16 = pppppppcVar36 + 1;
      pppppppcVar36 = pppppppcVar36 + -5;
      iVar21 = iVar21 + (uint)(*(uint *)pppppppcVar16 == uVar35);
      uVar3 = *(uint *)pppppppcVar36;
    }
  } while (*(uint *)(pppppppcVar36 + 1) != uVar35);
  if (iVar21 != 0) {
    iVar21 = iVar21 + -1;
    goto LAB_00b3d3a0;
  }
  if ((code *******)pppppppcVar36[2] != pppppppcVar20) {
LAB_00b3fe94:
    pppppppcVar36 = (code *******)((long)pppppppcVar17 + 3);
    if (local_68 == local_70 || (long)local_68 - (long)local_70 < 0) {
      local_f8 = param_6;
      local_f0 = (code *******)((long)pppppppcVar17 + 3);
      *(undefined8 *)(puVar28 + -8) = 0xb40bed;
      iVar21 = FUN_00b3cb70(&local_78,&local_68,&local_70,pppppppcVar34,param_7,param_7 + 1);
      pppppppcVar20 = local_80;
      pppppppcVar36 = local_f0;
      param_6 = local_f8;
      if (iVar21 != 0) goto LAB_00b3fe49;
    }
    *(uint *)local_70 = 0x5000;
    *(uint *)(local_70 + 1) = uVar35;
    uVar18 = (ulong)*(byte *)((long)pppppppcVar17 + 3);
    param_5 = pppppppcVar20;
    local_70 = local_70 + 5;
    goto LAB_00b3cde0;
  }
  if (pppppppcVar36 < local_70) {
    local_f0 = local_78;
    iVar21 = 1;
    while (pppppppcVar16 = pppppppcVar36, pppppppcVar36 = pppppppcVar16 + 5,
          pppppppcVar36 < local_70) {
      if (*(uint *)pppppppcVar36 == 0x100) {
        pppppppcVar30 = (code *******)pppppppcVar16[9];
        if (pppppppcVar30 == (code *******)0xffffffffffffffff) goto LAB_00b3fe94;
        bVar31 = (bool)((byte)*(uint *)(local_c0 + 6) & 1);
        if ((int)*(uint *)(pppppppcVar16 + 6) < 0x20) {
          bVar31 = (1 << ((byte)*(uint *)(pppppppcVar16 + 6) & 0x1f) & *(uint *)(local_c0 + 6)) != 0
          ;
        }
        if (bVar31 != false) {
          pppppppcVar30 = (code *******)local_78[(long)pppppppcVar30 * 5 + 2];
        }
        if ((code *******)local_78[(long)pppppppcVar16[8] * 5 + 2] != pppppppcVar30)
        goto LAB_00b3fe94;
        if (pppppppcVar30 != pppppppcVar20) {
          iVar21 = -1;
        }
      }
    }
joined_r0x00b41bd1:
    if (iVar21 == -1) goto joined_r0x00b3d741;
  }
LAB_00b401b1:
  bVar13 = *(byte *)((long)pppppppcVar17 + 3);
  if (0x3e < bVar13) {
    if (bVar13 < 0x41) {
      uVar18 = (ulong)*(byte *)(pppppppcVar17 + 1);
      pppppppcVar36 = pppppppcVar17 + 1;
      goto LAB_00b3cde0;
    }
    if ((byte)(bVar13 + 0xba) < 4) {
      uVar18 = (ulong)*(byte *)((long)pppppppcVar17 + 6);
      pppppppcVar36 = (code *******)((long)pppppppcVar17 + 6);
      goto LAB_00b3cde0;
    }
  }
  if (local_78 != local_b8) {
    *param_7 = local_78;
    param_7[1] = ((long)local_68 - (long)local_78 >> 3) * -0x3333333333333333;
  }
  return -0xe;
}


// ==== entry=00b41e90 name=FUN_00b41e90 size=5 ====

undefined8 FUN_00b41e90(long param_1)

{
  return *(undefined8 *)(param_1 + 0x18);
}


// ==== entry=00b41ea0 name=FUN_00b41ea0 size=58 ====

void FUN_00b41ea0(long param_1)

{
  int iVar1;
  long lVar2;
  long lVar3;
  ulong uVar4;
  bool bVar5;
  
  iVar1 = *(int *)(param_1 + 4);
  if (0 < iVar1) {
    lVar2 = *(long *)(param_1 + 0x10);
    lVar3 = *(long *)(param_1 + 8);
    uVar4 = 0;
    do {
      *(undefined8 *)(lVar2 + uVar4 * 8) = 0xffffffffffffffff;
      *(undefined8 *)(lVar3 + uVar4 * 8) = 0xffffffffffffffff;
      bVar5 = iVar1 - 1 != uVar4;
      uVar4 = uVar4 + 1;
    } while (bVar5);
  }
  FUN_00b3b5d0(param_1 + 0x18);
  return;
}


// ==== entry=00b41ee0 name=FUN_00b41ee0 size=244 ====

undefined4 FUN_00b41ee0(int *param_1,int param_2)

{
  void *pvVar1;
  void *pvVar2;
  int iVar3;
  undefined4 uVar4;
  
  param_1[1] = param_2;
  iVar3 = 10;
  if (9 < param_2) {
    iVar3 = param_2;
  }
  if (*param_1 == 0) {
    pvVar1 = malloc((long)iVar3 << 3);
    *(void **)(param_1 + 2) = pvVar1;
    if (pvVar1 == (void *)0x0) {
      uVar4 = 0xfffffffb;
    }
    else {
      pvVar2 = malloc((long)iVar3 << 3);
      *(void **)(param_1 + 4) = pvVar2;
      if (pvVar2 != (void *)0x0) {
        *param_1 = iVar3;
        return 0;
      }
      uVar4 = 0xfffffffb;
      free(pvVar1);
    }
  }
  else if (*param_1 < iVar3) {
    *param_1 = 0;
    pvVar1 = realloc(*(void **)(param_1 + 2),(long)iVar3 << 3);
    if (pvVar1 != (void *)0x0) {
      *(void **)(param_1 + 2) = pvVar1;
      pvVar1 = realloc(*(void **)(param_1 + 4),(long)iVar3 << 3);
      if (pvVar1 != (void *)0x0) {
        *(void **)(param_1 + 4) = pvVar1;
        *param_1 = iVar3;
        return 0;
      }
    }
    uVar4 = 0xfffffffb;
    free(*(void **)(param_1 + 2));
    free(*(void **)(param_1 + 4));
  }
  else {
    uVar4 = 0;
  }
  return uVar4;
}


// ==== entry=00b41fe0 name=FUN_00b41fe0 size=85 ====

undefined8 FUN_00b41fe0(int *param_1,int param_2,int param_3,int param_4)

{
  undefined8 uVar1;
  
  if (-1 < param_2) {
    if ((param_2 < *param_1) || (uVar1 = FUN_00b41ee0(param_1,param_2 + 1), -1 < (int)uVar1)) {
      *(long *)(*(long *)(param_1 + 2) + (long)param_2 * 8) = (long)param_3;
      *(long *)(*(long *)(param_1 + 4) + (long)param_2 * 8) = (long)param_4;
      uVar1 = 0;
    }
    return uVar1;
  }
  return 0xffffffe2;
}


// ==== entry=00b42040 name=FUN_00b42040 size=32 ====

void FUN_00b42040(undefined8 *param_1)

{
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  return;
}


// ==== entry=00b42060 name=FUN_00b42060 size=55 ====

void FUN_00b42060(void)

{
  undefined8 *puVar1;
  
  puVar1 = malloc(0x20);
  if (puVar1 != (undefined8 *)0x0) {
    *puVar1 = 0;
    puVar1[1] = 0;
    puVar1[2] = 0;
    puVar1[3] = 0;
  }
  return;
}


// ==== entry=00b420a0 name=FUN_00b420a0 size=91 ====

void FUN_00b420a0(int *param_1,int param_2)

{
  if (param_1 == (int *)0x0) {
    return;
  }
  if (0 < *param_1) {
    if (*(void **)(param_1 + 2) != (void *)0x0) {
      free(*(void **)(param_1 + 2));
    }
    if (*(void **)(param_1 + 4) != (void *)0x0) {
      free(*(void **)(param_1 + 4));
    }
    *param_1 = 0;
  }
  FUN_00b3b5d0(param_1 + 6);
  if (param_2 == 0) {
    return;
  }
  free(param_1);
  return;
}


// ==== entry=00b42110 name=FUN_00b42110 size=129 ====

void FUN_00b42110(long param_1,long param_2)

{
  long lVar1;
  long lVar2;
  long lVar3;
  long lVar4;
  int iVar5;
  ulong uVar6;
  undefined8 uVar7;
  bool bVar8;
  
  if (param_1 == param_2) {
    return;
  }
  iVar5 = FUN_00b41ee0(param_1,*(undefined4 *)(param_2 + 4));
  if (iVar5 == 0) {
    iVar5 = *(int *)(param_2 + 4);
    if (0 < iVar5) {
      lVar1 = *(long *)(param_2 + 8);
      lVar2 = *(long *)(param_1 + 8);
      lVar3 = *(long *)(param_2 + 0x10);
      lVar4 = *(long *)(param_1 + 0x10);
      uVar6 = 0;
      do {
        *(undefined8 *)(lVar2 + uVar6 * 8) = *(undefined8 *)(lVar1 + uVar6 * 8);
        *(undefined8 *)(lVar4 + uVar6 * 8) = *(undefined8 *)(lVar3 + uVar6 * 8);
        bVar8 = uVar6 != iVar5 - 1;
        uVar6 = uVar6 + 1;
      } while (bVar8);
    }
    *(int *)(param_1 + 4) = iVar5;
    FUN_00b3b5d0(param_1 + 0x18);
    if (*(long *)(param_2 + 0x18) != 0) {
      uVar7 = FUN_00b3b3d0();
      *(undefined8 *)(param_1 + 0x18) = uVar7;
    }
  }
  return;
}


// ==== entry=00b421a0 name=FUN_00b421a0 size=7 ====

undefined4 FUN_00b421a0(void)

{
  return DAT_011c3828;
}


// ==== entry=00b421b0 name=FUN_00b421b0 size=9 ====

undefined8 FUN_00b421b0(undefined4 param_1)

{
  DAT_011c3828 = param_1;
  return 0;
}


// ==== entry=00b421c0 name=FUN_00b421c0 size=220 ====

long FUN_00b421c0(undefined8 param_1,long param_2,undefined8 param_3,undefined8 param_4,
                 undefined8 param_5,undefined8 param_6,long param_7,uint param_8)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  void *local_78 [2];
  uint local_68;
  long local_60;
  undefined8 local_58;
  undefined8 local_50;
  undefined8 local_48;
  
  local_78[0] = (void *)0x0;
  local_68 = param_8;
  local_60 = param_7;
  local_48 = 0xffffffffffffffff;
  local_58 = param_6;
  local_50 = param_5;
  if ((param_7 != 0) && ((param_8 & 0x800) == 0)) {
    iVar1 = FUN_00b41ee0(param_7,*(int *)(param_2 + 0x14) + 1);
    if (iVar1 == 0) {
      FUN_00b41ea0(param_7);
    }
    else {
      lVar3 = (long)iVar1;
      if (lVar3 != 0) goto LAB_00b42253;
    }
  }
  uVar2 = FUN_00b43110(param_1,*(undefined8 *)(param_2 + 0x48),param_3,param_6);
  lVar3 = FUN_00b3cc80(param_1,param_2,param_3,param_4,param_6,uVar2,local_78);
LAB_00b42253:
  if (local_78[0] != (void *)0x0) {
    free(local_78[0]);
  }
  return lVar3;
}


// ==== entry=00b422b0 name=FUN_00b422b0 size=24 ====

void FUN_00b422b0(void)

{
  FUN_00b421c0();
  return;
}


// ==== entry=00b422d0 name=FUN_00b422d0 size=2750 ====

long FUN_00b422d0(undefined8 param_1,long param_2,long param_3,long param_4,long param_5,
                 long param_6,long param_7,long param_8,uint param_9)

{
  ulong uVar1;
  code *pcVar2;
  bool bVar3;
  int iVar4;
  uint uVar5;
  long lVar6;
  long lVar7;
  ulong uVar8;
  undefined8 extraout_RDX;
  ulong uVar9;
  undefined8 uVar10;
  undefined8 uStack_c0;
  long local_b8;
  long local_a0;
  long local_90;
  long local_88;
  long local_80;
  void *local_78 [2];
  uint local_68;
  long local_60;
  long local_58;
  long local_50;
  long local_48;
  long local_40;
  
  if ((param_8 != 0) && ((param_9 & 0x800) == 0)) {
    uStack_c0 = 0xb42783;
    iVar4 = FUN_00b41ee0(param_8,*(int *)(param_2 + 0x14) + 1);
    if (iVar4 == 0) {
      uStack_c0 = 0xb429ed;
      FUN_00b41ea0(param_8);
    }
    else if ((long)iVar4 != 0) {
      return (long)iVar4;
    }
  }
  if (param_4 < param_6) {
    return -1;
  }
  if (param_6 < param_3) {
    return -1;
  }
  uVar5 = *(uint *)(param_2 + 0x78);
  local_50 = param_5;
  if ((uVar5 == 0) || (param_4 <= param_3)) {
    if (param_4 != param_3) goto LAB_00b4233a;
    if (*(int *)(param_2 + 0x74) != 0) {
      return -1;
    }
    local_68 = param_9;
    local_78[0] = (void *)0x0;
    local_60 = param_8;
    local_58 = 0;
    local_50 = 0;
    local_48 = -1;
    lVar6 = FUN_00b3cc80(param_1,param_2,0,0,0,0xffffffffffffffff,local_78);
    if (lVar6 == -1) {
      param_3 = 0;
      goto LAB_00b424d0;
    }
    if (lVar6 < 0) goto LAB_00b424e1;
    param_3 = 0;
    if ((*(byte *)(param_2 + 0x50) & 0x10) == 0) {
      param_3 = 0;
      goto LAB_00b42748;
    }
LAB_00b42888:
    if (-1 < local_48) {
      param_3 = local_40 - param_3;
LAB_00b42748:
      if (local_78[0] != (void *)0x0) {
        free(local_78[0]);
        return param_3;
      }
      return param_3;
    }
  }
  else {
    if ((uVar5 & 4) != 0) {
LAB_00b427a8:
      bVar3 = param_6 < param_7;
      param_7 = param_6;
      if (bVar3) {
        param_7 = param_6 + 1;
        goto LAB_00b4233a;
      }
LAB_00b4257c:
      local_48 = -1;
      local_78[0] = (void *)0x0;
      local_68 = param_9;
      local_60 = param_8;
      local_58 = param_6;
      if (*(int *)(param_2 + 0x70) == 0) {
LAB_00b42815:
        do {
          lVar7 = FUN_00b43110(param_1,*(undefined8 *)(param_2 + 0x48),param_3,param_6);
          lVar6 = FUN_00b3cc80(param_1,param_2,param_3,param_4,param_6,lVar7,local_78);
          if (lVar6 != -1) {
            if (lVar6 < 0) goto LAB_00b424e1;
            if ((*(byte *)(param_2 + 0x50) & 0x10) == 0) goto LAB_00b42a23;
          }
          param_6 = lVar7;
        } while (param_7 <= lVar7);
      }
      else {
        local_b8 = param_4;
        if (param_7 < param_4) {
          local_b8 = (**(code **)(*(long *)(param_2 + 0x48) + 0x90))(param_1,param_3,param_7);
        }
        lVar6 = *(long *)(param_2 + 0x1c0);
        if (lVar6 == -1) {
          if (((long)*(int *)(param_2 + 0x74) <= param_4 - param_7) &&
             (iVar4 = FUN_00b3b730(param_1,param_2,param_3,param_4,param_4,param_7,local_b8,
                                   &local_88,&local_80), 0 < iVar4)) goto LAB_00b42815;
        }
        else if ((long)*(int *)(param_2 + 0x74) <= param_4 - param_7) {
          while( true ) {
            lVar7 = param_6 + lVar6;
            if (param_4 <= param_6 + lVar6) {
              lVar7 = param_4;
            }
            iVar4 = FUN_00b3b730(param_1,param_2,param_3,param_4,lVar7,param_7,local_b8,&local_88,
                                 &local_80);
            if (iVar4 < 1) break;
            lVar7 = param_6;
            if (local_80 < param_6) {
              lVar7 = local_80;
            }
            while (param_6 = lVar7, local_88 <= param_6) {
              lVar7 = FUN_00b43110(param_1,*(undefined8 *)(param_2 + 0x48),param_3,param_6);
              lVar6 = FUN_00b3cc80(param_1,param_2,param_3,param_4,param_6,lVar7,local_78);
              if (lVar6 != -1) {
                if (lVar6 < 0) goto LAB_00b424e1;
                if ((*(byte *)(param_2 + 0x50) & 0x10) == 0) goto LAB_00b42a23;
              }
            }
            if (param_6 < param_7) break;
            lVar6 = *(long *)(param_2 + 0x1c0);
          }
        }
      }
      goto LAB_00b424d0;
    }
    if ((uVar5 & 1) == 0) {
      lVar6 = param_4;
      if ((uVar5 & 8) == 0) {
        if ((uVar5 & 0x10) != 0) {
          lVar7 = FUN_00b43190(param_1,*(undefined8 *)(param_2 + 0x48),param_3,param_4,1);
          uStack_c0 = 0xb42cdf;
          iVar4 = (**(code **)(*(long *)(param_2 + 0x48) + 0x28))(param_1,lVar7,param_4);
          if (iVar4 != 0) {
            uStack_c0 = 0xb42d08;
            lVar6 = FUN_00b43190(param_1,*(undefined8 *)(param_2 + 0x48),param_3,lVar7,1);
            if ((lVar6 != -1) && ((*(byte *)(param_2 + 0x51) & 0x80) != 0)) {
              uStack_c0 = 0xb42d2d;
              iVar4 = (**(code **)(*(long *)(param_2 + 0x48) + 0x38))(param_1,lVar6,param_4);
              if (iVar4 == 0xd) {
                pcVar2 = *(code **)(*(long *)(param_2 + 0x48) + 0x38);
                iVar4 = (**(code **)(*(long *)(param_2 + 0x48) + 8))(param_1,lVar6);
                uStack_c0 = 0xb42d67;
                iVar4 = (*pcVar2)(param_1,iVar4 + lVar6,param_4);
                if (iVar4 == 10) {
                  lVar7 = lVar6;
                }
              }
            }
            if ((lVar7 <= param_3) || (lVar6 = lVar7, lVar7 < param_6)) goto LAB_00b4233a;
          }
          goto LAB_00b42a53;
        }
        if (((uVar5 & 0x8000) != 0) && ((uVar5 & 0x1000) == 0)) goto LAB_00b427a8;
LAB_00b4233a:
        if (param_7 <= param_6) goto LAB_00b4257c;
      }
      else {
LAB_00b42a53:
        uVar8 = *(ulong *)(param_2 + 0x80);
        if ((ulong)(param_4 - param_3) < uVar8) {
          return -1;
        }
        uVar1 = *(ulong *)(param_2 + 0x88);
        if (param_7 <= param_6) {
          if (uVar1 < (ulong)(lVar6 - param_7)) {
            param_7 = lVar6 - uVar1;
            if ((ulong)(param_4 - param_6) < uVar8) goto LAB_00b42c7f;
          }
          else {
            if (uVar8 <= (ulong)(param_4 - param_6)) goto LAB_00b4257c;
LAB_00b42c7f:
            param_6 = (**(code **)(*(long *)(param_2 + 0x48) + 0x90))
                                (param_1,param_3,param_4 - uVar8);
          }
          if (param_6 < param_7) {
            return -1;
          }
          goto LAB_00b4257c;
        }
        uVar9 = param_4 - (param_7 + -1);
        if (uVar1 < (ulong)(lVar6 - param_6)) {
          param_6 = lVar6 - uVar1;
          if (param_6 < param_4) {
            uStack_c0 = 0xb42df1;
            param_6 = FUN_00b42fb0(param_1,*(undefined8 *)(param_2 + 0x48),param_3,param_6);
            uVar8 = *(ulong *)(param_2 + 0x80);
          }
          if (uVar9 < uVar8) goto LAB_00b42aaf;
LAB_00b42abe:
          if (param_7 < param_6) {
            return -1;
          }
          goto LAB_00b4233a;
        }
        if (uVar9 < uVar8) {
LAB_00b42aaf:
          param_7 = (param_4 + 1) - uVar8;
          goto LAB_00b42abe;
        }
      }
      local_60 = param_8;
      local_68 = param_9;
      local_48 = -1;
      local_78[0] = (void *)0x0;
      local_58 = param_6;
      if (param_6 <= param_3) goto LAB_00b4238c;
      uStack_c0 = 0xb42a0a;
      lVar7 = FUN_00b43110(param_1,*(undefined8 *)(param_2 + 0x48),param_3,param_6);
      lVar6 = param_6;
      param_6 = lVar7;
      if (*(int *)(param_2 + 0x70) != 0) goto LAB_00b42399;
LAB_00b428a8:
      do {
        param_6 = lVar6;
        uVar10 = uStack_c0;
        lVar6 = FUN_00b3cc80(param_1,param_2,param_3,param_4,param_6,lVar7,local_78);
        if (lVar6 != -1) {
          if (lVar6 < 0) goto LAB_00b424e1;
          if ((*(byte *)(param_2 + 0x50) & 0x10) == 0) goto LAB_00b42a23;
        }
        uStack_c0 = 0xb42906;
        iVar4 = (**(code **)(*(long *)(param_2 + 0x48) + 8))(param_1,param_6,uVar10);
        lVar6 = iVar4 + param_6;
        lVar7 = param_6;
      } while (lVar6 < param_7);
      if ((lVar6 == param_7) &&
         (lVar6 = FUN_00b3cc80(param_1,param_2,param_3,param_4,param_7,param_6,local_78),
         lVar6 != -1)) {
        if (lVar6 < 0) goto LAB_00b424e1;
        if ((*(byte *)(param_2 + 0x50) & 0x10) == 0) {
          param_3 = param_7 - param_3;
          goto LAB_00b42748;
        }
        goto LAB_00b42888;
      }
    }
    else {
      if (param_7 <= param_6) {
        bVar3 = param_3 < param_7;
        param_6 = param_3;
        param_7 = param_3;
        if (bVar3) {
          return -1;
        }
        goto LAB_00b4257c;
      }
      if (param_6 != param_3) {
        return -1;
      }
      param_7 = param_6 + 1;
      local_58 = param_6;
LAB_00b4238c:
      local_60 = param_8;
      local_68 = param_9;
      local_48 = -1;
      local_78[0] = (void *)0x0;
      lVar6 = local_58;
      lVar7 = -1;
      param_6 = -1;
      if (*(int *)(param_2 + 0x70) == 0) goto LAB_00b428a8;
LAB_00b42399:
      local_a0 = *(long *)(param_2 + 0x1c0);
      if (local_a0 == 0) {
        local_a0 = param_7;
LAB_00b423d1:
        if ((long)*(int *)(param_2 + 0x74) <= param_4 - lVar6) {
          do {
            iVar4 = FUN_00b3bcf0(param_1,param_2,param_3,param_4,lVar6,local_a0,&local_90,&local_88,
                                 &local_80);
            if (iVar4 == 0) break;
            if (lVar6 < local_90) {
              param_6 = local_80;
              lVar6 = local_90;
            }
            lVar7 = param_6;
            if (lVar6 <= local_88) {
              do {
                param_6 = lVar6;
                lVar6 = FUN_00b3cc80(param_1,param_2,param_3,param_4,param_6,lVar7);
                if (lVar6 != -1) {
                  if (lVar6 < 0) goto LAB_00b424e1;
                  if ((*(byte *)(param_2 + 0x50) & 0x10) == 0) goto LAB_00b42a23;
                }
                iVar4 = (**(code **)(*(long *)(param_2 + 0x48) + 8))(param_1,param_6);
                lVar6 = iVar4 + param_6;
                lVar7 = param_6;
              } while (lVar6 <= local_88);
            }
          } while (lVar6 < param_7);
        }
      }
      else {
        if (local_a0 != -1) {
          local_a0 = local_a0 + param_7;
          if (param_4 < local_a0) {
            local_a0 = param_4;
          }
          goto LAB_00b423d1;
        }
        if (((long)*(int *)(param_2 + 0x74) <= param_4 - lVar6) &&
           (iVar4 = FUN_00b3bcf0(param_1,param_2,param_3,param_4,lVar6,param_4,&local_90,&local_88,0
                                ), iVar4 != 0)) {
          uVar5 = *(uint *)(param_2 + 0x78);
          lVar7 = param_6;
          if ((uVar5 & 0x4000) == 0) goto LAB_00b428a8;
          while( true ) {
            param_6 = lVar6;
            if ((uVar5 & 4) == 0) {
              local_50 = param_6;
            }
            lVar6 = FUN_00b3cc80(param_1,param_2,param_3,param_4,param_6,lVar7,local_78);
            if (lVar6 != -1) {
              if (lVar6 < 0) goto LAB_00b424e1;
              if ((*(byte *)(param_2 + 0x50) & 0x10) == 0) goto LAB_00b42a23;
            }
            iVar4 = (**(code **)(*(long *)(param_2 + 0x48) + 8))(param_1,param_6);
            lVar6 = iVar4 + param_6;
            if ((*(byte *)(param_2 + 0x79) & 0x10) == 0) {
              while( true ) {
                uVar10 = 0;
                iVar4 = FUN_00b3b600(param_1,*(undefined8 *)(param_2 + 0x48),param_6,param_3,param_4
                                     ,*(undefined4 *)(param_2 + 0x50));
                if ((iVar4 != 0) || (param_7 <= lVar6)) break;
                iVar4 = (**(code **)(*(long *)(param_2 + 0x48) + 8))
                                  (param_1,lVar6,extraout_RDX,uVar10);
                param_6 = lVar6;
                lVar6 = lVar6 + iVar4;
              }
            }
            if (param_7 <= lVar6) break;
            uVar5 = *(uint *)(param_2 + 0x78);
            lVar7 = param_6;
          }
        }
      }
    }
LAB_00b424d0:
    if ((*(byte *)(param_2 + 0x50) & 0x10) != 0) goto LAB_00b42888;
  }
  lVar6 = -1;
LAB_00b424e1:
  if (local_78[0] != (void *)0x0) {
    free(local_78[0]);
  }
  if ((((*(byte *)(param_2 + 0x50) & 0x20) != 0) && (param_8 != 0)) && ((param_9 & 0x800) == 0)) {
    FUN_00b41ea0(param_8);
  }
  return lVar6;
LAB_00b42a23:
  param_3 = param_6 - param_3;
  goto LAB_00b42748;
}


// ==== entry=00b42e10 name=FUN_00b42e10 size=28 ====

void FUN_00b42e10(void)

{
  FUN_00b422d0();
  return;
}


// ==== entry=00b42e30 name=FUN_00b42e30 size=5 ====

undefined8 FUN_00b42e30(long param_1)

{
  return *(undefined8 *)(param_1 + 0x48);
}


// ==== entry=00b42e40 name=FUN_00b42e40 size=4 ====

undefined4 FUN_00b42e40(long param_1)

{
  return *(undefined4 *)(param_1 + 0x50);
}


