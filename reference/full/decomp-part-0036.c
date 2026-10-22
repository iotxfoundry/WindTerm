// Ghidra 12.1.4 decompiled — WindTerm 2.7.0 (sha256 9491b87e…) part 36
// ==== entry=00b02a24 name=FUN_00b02a24 size=68 ====

void FUN_00b02a24(undefined8 *param_1)

{
  undefined8 uVar1;
  
  uVar1 = FUN_00b02e54(param_1);
  FUN_00b02e62(*param_1,param_1[1],uVar1);
  FUN_00b02e06(param_1);
  return;
}


// ==== entry=00b02a68 name=FUN_00b02a68 size=27 ====

void FUN_00b02a68(undefined8 param_1)

{
  FUN_00b02e8c(param_1);
  return;
}


// ==== entry=00b02a84 name=FUN_00b02a84 size=39 ====

void FUN_00b02a84(undefined8 param_1)

{
  FUN_00b02ea8(param_1);
  FUN_00b02a68(param_1);
  return;
}


// ==== entry=00b02aac name=FUN_00b02aac size=55 ====

void FUN_00b02aac(undefined8 *param_1,undefined8 param_2)

{
  FUN_00b02d1a(param_1);
  *param_1 = &PTR_FUN_00d39da8;
  param_1[2] = param_2;
  return;
}


// ==== entry=00b02ae4 name=FUN_00b02ae4 size=14 ====

undefined8 FUN_00b02ae4(undefined8 param_1)

{
  return param_1;
}


// ==== entry=00b02af2 name=FUN_00b02af2 size=30 ====

void FUN_00b02af2(long param_1)

{
  FUN_00b02f22(param_1 + 0x20);
  return;
}


// ==== entry=00b02b10 name=FUN_00b02b10 size=38 ====

void FUN_00b02b10(undefined8 param_1,undefined8 param_2)

{
  FUN_00b02f3c(param_1,param_2);
  return;
}


// ==== entry=00b02b36 name=FUN_00b02b36 size=46 ====

void FUN_00b02b36(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  FUN_00b02f4c(param_1,param_2,param_3);
  return;
}


// ==== entry=00b02b64 name=FUN_00b02b64 size=55 ====

void FUN_00b02b64(undefined8 *param_1,undefined8 param_2)

{
  FUN_00b02d1a(param_1);
  *param_1 = &PTR_FUN_00d39d70;
  param_1[2] = param_2;
  return;
}


// ==== entry=00b02b9b name=FUN_00b02b9b size=26 ====

void FUN_00b02b9b(undefined8 param_1)

{
  FUN_00b0245e(param_1);
  return;
}


// ==== entry=00b02bb6 name=FUN_00b02bb6 size=32 ====

bool FUN_00b02bb6(undefined8 param_1,ulong param_2,ulong param_3)

{
  return param_2 < param_3;
}


// ==== entry=00b02bd6 name=FUN_00b02bd6 size=26 ====

void FUN_00b02bd6(undefined8 param_1)

{
  FUN_00b0245e(param_1);
  return;
}


// ==== entry=00b02bf0 name=FUN_00b02bf0 size=72 ====

undefined8 FUN_00b02bf0(undefined8 param_1,undefined8 param_2)

{
  undefined8 uVar1;
  undefined8 uVar2;
  
  uVar1 = FUN_00b02f70(param_1);
  uVar2 = FUN_00b016fe(param_2);
  FUN_00b02f98(param_1,uVar1,uVar2);
  return uVar1;
}


// ==== entry=00b02c38 name=FUN_00b02c38 size=26 ====

void FUN_00b02c38(undefined8 param_1)

{
  FUN_00b03036(param_1);
  return;
}


// ==== entry=00b02c52 name=FUN_00b02c52 size=40 ====

undefined8 FUN_00b02c52(undefined8 *param_1)

{
  undefined8 local_10;
  
  FUN_00b01e20(&local_10,*param_1);
  return local_10;
}


// ==== entry=00b02c7a name=FUN_00b02c7a size=18 ====

undefined8 FUN_00b02c7a(long param_1)

{
  return *(undefined8 *)(param_1 + 0x28);
}


// ==== entry=00b02c8c name=FUN_00b02c8c size=18 ====

long FUN_00b02c8c(long param_1)

{
  return param_1 + 0x20;
}


// ==== entry=00b02c9e name=FUN_00b02c9e size=18 ====

long FUN_00b02c9e(long param_1)

{
  return param_1 + 0x18;
}


// ==== entry=00b02cb0 name=FUN_00b02cb0 size=43 ====

undefined8 * FUN_00b02cb0(undefined8 *param_1)

{
  undefined8 uVar1;
  
  uVar1 = std::_Rb_tree_increment((_Rb_tree_node_base *)*param_1);
  *param_1 = uVar1;
  return param_1;
}


// ==== entry=00b02cdc name=FUN_00b02cdc size=26 ====

void FUN_00b02cdc(undefined8 param_1)

{
  FUN_00b03044(param_1);
  return;
}


// ==== entry=00b02cf6 name=FUN_00b02cf6 size=35 ====

void FUN_00b02cf6(undefined8 param_1,void *param_2)

{
  operator_delete(param_2);
  return;
}


// ==== entry=00b02d1a name=FUN_00b02d1a size=45 ====

void FUN_00b02d1a(undefined8 *param_1)

{
  *param_1 = &DAT_00d39e18;
  *(undefined4 *)(param_1 + 1) = 1;
  *(undefined4 *)((long)param_1 + 0xc) = 1;
  return;
}


// ==== entry=00b02d48 name=FUN_00b02d48 size=27 ====

void FUN_00b02d48(undefined8 param_1)

{
  FUN_00b03052(param_1);
  return;
}


// ==== entry=00b02d64 name=FUN_00b02d64 size=77 ====

void FUN_00b02d64(long *param_1)

{
  FUN_00b0306e(param_1,*param_1,param_1[2] - *param_1 >> 3);
  FUN_00b02d48(param_1);
  return;
}


// ==== entry=00b02db2 name=FUN_00b02db2 size=14 ====

undefined8 FUN_00b02db2(undefined8 param_1)

{
  return param_1;
}


// ==== entry=00b02dc0 name=FUN_00b02dc0 size=42 ====

void FUN_00b02dc0(undefined8 param_1,undefined8 param_2)

{
  FUN_00b030a3(param_1,param_2);
  return;
}


// ==== entry=00b02dea name=FUN_00b02dea size=27 ====

void FUN_00b02dea(undefined8 param_1)

{
  FUN_00b030ca(param_1);
  return;
}


// ==== entry=00b02e06 name=FUN_00b02e06 size=77 ====

void FUN_00b02e06(long *param_1)

{
  FUN_00b030e6(param_1,*param_1,param_1[2] - *param_1 >> 4);
  FUN_00b02dea(param_1);
  return;
}


// ==== entry=00b02e54 name=FUN_00b02e54 size=14 ====

undefined8 FUN_00b02e54(undefined8 param_1)

{
  return param_1;
}


// ==== entry=00b02e62 name=FUN_00b02e62 size=42 ====

void FUN_00b02e62(undefined8 param_1,undefined8 param_2)

{
  FUN_00b0311b(param_1,param_2);
  return;
}


// ==== entry=00b02e8c name=FUN_00b02e8c size=27 ====

void FUN_00b02e8c(undefined8 param_1)

{
  FUN_00b03142(param_1);
  return;
}


// ==== entry=00b02ea8 name=FUN_00b02ea8 size=122 ====

void FUN_00b02ea8(undefined8 *param_1)

{
  undefined8 *puVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 local_10;
  
  local_10 = (undefined8 *)*param_1;
  while (local_10 != param_1) {
    puVar1 = (undefined8 *)*local_10;
    uVar2 = FUN_00b0314e(local_10);
    uVar3 = FUN_00b0316c(param_1);
    FUN_00b0317a(uVar3,uVar2);
    FUN_00b031a0(param_1,local_10);
    local_10 = puVar1;
  }
  return;
}


// ==== entry=00b02f22 name=FUN_00b02f22 size=26 ====

void FUN_00b02f22(undefined8 param_1)

{
  FUN_00b031cc(param_1);
  return;
}


// ==== entry=00b02f3c name=FUN_00b02f3c size=15 ====

void FUN_00b02f3c(void)

{
  return;
}


// ==== entry=00b02f4c name=FUN_00b02f4c size=35 ====

void FUN_00b02f4c(undefined8 param_1,void *param_2)

{
  operator_delete(param_2);
  return;
}


// ==== entry=00b02f70 name=FUN_00b02f70 size=39 ====

void FUN_00b02f70(undefined8 param_1)

{
  undefined8 uVar1;
  
  uVar1 = FUN_00b0294e(param_1);
  FUN_00b031da(uVar1,1);
  return;
}


// ==== entry=00b02f98 name=FUN_00b02f98 size=107 ====

void FUN_00b02f98(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  
  identity_forward(0x30,param_2);
  uVar1 = FUN_00b016fe(param_3);
  uVar2 = FUN_00b0295c(param_2);
  uVar3 = FUN_00b0294e(param_1);
                    /* try { // try from 00b02ff3 to 00b02ff7 has its CatchHandler @ 00b02ffa */
  FUN_00b03204(uVar3,uVar2,uVar1);
  return;
}


// ==== entry=00b03036 name=FUN_00b03036 size=14 ====

undefined8 FUN_00b03036(undefined8 param_1)

{
  return param_1;
}


// ==== entry=00b03044 name=FUN_00b03044 size=14 ====

undefined8 FUN_00b03044(undefined8 param_1)

{
  return param_1;
}


// ==== entry=00b03052 name=FUN_00b03052 size=27 ====

void FUN_00b03052(undefined8 param_1)

{
  FUN_00b0323e(param_1);
  return;
}


// ==== entry=00b0306e name=FUN_00b0306e size=53 ====

void FUN_00b0306e(undefined8 param_1,long param_2,undefined8 param_3)

{
  if (param_2 != 0) {
    FUN_00b03249(param_1,param_2,param_3);
  }
  return;
}


// ==== entry=00b030a3 name=FUN_00b030a3 size=38 ====

void FUN_00b030a3(undefined8 param_1,undefined8 param_2)

{
  FUN_00b03277(param_1,param_2);
  return;
}


// ==== entry=00b030ca name=FUN_00b030ca size=27 ====

void FUN_00b030ca(undefined8 param_1)

{
  FUN_00b03286(param_1);
  return;
}


// ==== entry=00b030e6 name=FUN_00b030e6 size=53 ====

void FUN_00b030e6(undefined8 param_1,long param_2,undefined8 param_3)

{
  if (param_2 != 0) {
    FUN_00b03291(param_1,param_2,param_3);
  }
  return;
}


// ==== entry=00b0311b name=FUN_00b0311b size=38 ====

void FUN_00b0311b(undefined8 param_1,undefined8 param_2)

{
  FUN_00b032bf(param_1,param_2);
  return;
}


// ==== entry=00b03142 name=FUN_00b03142 size=11 ====

void FUN_00b03142(void)

{
  return;
}


// ==== entry=00b0314e name=FUN_00b0314e size=30 ====

void FUN_00b0314e(long param_1)

{
  FUN_00b032ce(param_1 + 0x10);
  return;
}


// ==== entry=00b0316c name=FUN_00b0316c size=14 ====

undefined8 FUN_00b0316c(undefined8 param_1)

{
  return param_1;
}


// ==== entry=00b0317a name=FUN_00b0317a size=38 ====

void FUN_00b0317a(undefined8 param_1,undefined8 param_2)

{
  FUN_00b032e8(param_1,param_2);
  return;
}


// ==== entry=00b031a0 name=FUN_00b031a0 size=43 ====

void FUN_00b031a0(undefined8 param_1,undefined8 param_2)

{
  FUN_00b032f7(param_1,param_2,1);
  return;
}


// ==== entry=00b031cc name=FUN_00b031cc size=14 ====

undefined8 FUN_00b031cc(undefined8 param_1)

{
  return param_1;
}


// ==== entry=00b031da name=FUN_00b031da size=42 ====

void FUN_00b031da(undefined8 param_1,undefined8 param_2)

{
  FUN_00b03326(param_1,param_2,0);
  return;
}


// ==== entry=00b03204 name=FUN_00b03204 size=57 ====

void FUN_00b03204(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  undefined8 uVar1;
  
  uVar1 = FUN_00b016fe(param_3);
  FUN_00b033d4(param_1,param_2,uVar1);
  return;
}


// ==== entry=00b0323e name=FUN_00b0323e size=11 ====

void FUN_00b0323e(void)

{
  return;
}


// ==== entry=00b03249 name=FUN_00b03249 size=46 ====

void FUN_00b03249(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  FUN_00b0341c(param_1,param_2,param_3);
  return;
}


// ==== entry=00b03277 name=FUN_00b03277 size=15 ====

void FUN_00b03277(void)

{
  return;
}


// ==== entry=00b03286 name=FUN_00b03286 size=11 ====

void FUN_00b03286(void)

{
  return;
}


// ==== entry=00b03291 name=FUN_00b03291 size=46 ====

void FUN_00b03291(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  FUN_00b03440(param_1,param_2,param_3);
  return;
}


// ==== entry=00b032bf name=FUN_00b032bf size=15 ====

void FUN_00b032bf(void)

{
  return;
}


// ==== entry=00b032ce name=FUN_00b032ce size=26 ====

void FUN_00b032ce(undefined8 param_1)

{
  FUN_00b03464(param_1);
  return;
}


// ==== entry=00b032e8 name=FUN_00b032e8 size=15 ====

void FUN_00b032e8(void)

{
  return;
}


// ==== entry=00b032f7 name=FUN_00b032f7 size=46 ====

void FUN_00b032f7(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  FUN_00b03472(param_1,param_2,param_3);
  return;
}


// ==== entry=00b03326 name=FUN_00b03326 size=75 ====

void FUN_00b03326(undefined8 param_1,ulong param_2)

{
  ulong uVar1;
  
  uVar1 = FUN_00b03496(param_1);
  if (uVar1 < param_2) {
                    /* WARNING: Subroutine does not return */
    std::__throw_bad_alloc();
  }
  operator_new(param_2 * 0x30);
  return;
}


// ==== entry=00b03372 name=FUN_00b03372 size=60 ====

void FUN_00b03372(undefined8 *param_1,undefined8 *param_2)

{
  *param_1 = *param_2;
  FUN_00b013fc(param_1 + 1,param_2 + 1);
  return;
}


// ==== entry=00b033ae name=FUN_00b033ae size=38 ====

void FUN_00b033ae(undefined8 param_1,undefined8 param_2)

{
  FUN_00b03372(param_1,param_2);
  return;
}


// ==== entry=00b033d4 name=FUN_00b033d4 size=72 ====

void FUN_00b033d4(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  undefined8 uVar1;
  undefined8 uVar2;
  
  uVar1 = FUN_00b016fe(param_3);
  uVar2 = identity_forward(0x10,param_2);
  FUN_00b033ae(uVar2,uVar1);
  return;
}


// ==== entry=00b0341c name=FUN_00b0341c size=35 ====

void FUN_00b0341c(undefined8 param_1,void *param_2)

{
  operator_delete(param_2);
  return;
}


// ==== entry=00b03440 name=FUN_00b03440 size=35 ====

void FUN_00b03440(undefined8 param_1,void *param_2)

{
  operator_delete(param_2);
  return;
}


// ==== entry=00b03464 name=FUN_00b03464 size=14 ====

undefined8 FUN_00b03464(undefined8 param_1)

{
  return param_1;
}


// ==== entry=00b03472 name=FUN_00b03472 size=35 ====

void FUN_00b03472(undefined8 param_1,void *param_2)

{
  operator_delete(param_2);
  return;
}


// ==== entry=00b03496 name=FUN_00b03496 size=20 ====

undefined8 FUN_00b03496(void)

{
  return 0x555555555555555;
}


// ==== entry=00b034aa name=FUN_00b034aa size=39 ====

void FUN_00b034aa(undefined8 *param_1)

{
  *param_1 = &PTR_FUN_00d39d70;
  FUN_00b01fea(param_1);
  return;
}


// ==== entry=00b034d2 name=FUN_00b034d2 size=38 ====

void FUN_00b034d2(void *param_1)

{
  FUN_00b034aa(param_1);
  operator_delete(param_1);
  return;
}


// ==== entry=00b034f8 name=FUN_00b034f8 size=39 ====

void FUN_00b034f8(undefined8 *param_1)

{
  *param_1 = &PTR_FUN_00d39da8;
  FUN_00b01fea(param_1);
  return;
}


// ==== entry=00b03520 name=FUN_00b03520 size=38 ====

void FUN_00b03520(void *param_1)

{
  FUN_00b034f8(param_1);
  operator_delete(param_1);
  return;
}


// ==== entry=00b03546 name=FUN_00b03546 size=39 ====

void FUN_00b03546(undefined8 *param_1)

{
  *param_1 = &PTR_FUN_00d39de0;
  FUN_00b01fea(param_1);
  return;
}


// ==== entry=00b0356e name=FUN_00b0356e size=38 ====

void FUN_00b0356e(void *param_1)

{
  FUN_00b03546(param_1);
  operator_delete(param_1);
  return;
}


// ==== entry=00b03594 name=FUN_00b03594 size=50 ====

void FUN_00b03594(long param_1)

{
  void *pvVar1;
  
  pvVar1 = *(void **)(param_1 + 0x10);
  if (pvVar1 != (void *)0x0) {
    FUN_00b02248(pvVar1);
    operator_delete(pvVar1);
  }
  return;
}


// ==== entry=00b035c6 name=FUN_00b035c6 size=34 ====

void FUN_00b035c6(long param_1)

{
  if (param_1 != 0) {
    FUN_00b034d2(param_1);
  }
  return;
}


// ==== entry=00b035e8 name=FUN_00b035e8 size=19 ====

undefined8 FUN_00b035e8(void)

{
  return 0;
}


// ==== entry=00b035fc name=FUN_00b035fc size=50 ====

void FUN_00b035fc(long param_1)

{
  void *pvVar1;
  
  pvVar1 = *(void **)(param_1 + 0x10);
  if (pvVar1 != (void *)0x0) {
    FUN_00b02126(pvVar1);
    operator_delete(pvVar1);
  }
  return;
}


// ==== entry=00b0362e name=FUN_00b0362e size=34 ====

void FUN_00b0362e(long param_1)

{
  if (param_1 != 0) {
    FUN_00b03520(param_1);
  }
  return;
}


// ==== entry=00b03650 name=FUN_00b03650 size=19 ====

undefined8 FUN_00b03650(void)

{
  return 0;
}


// ==== entry=00b03664 name=FUN_00b03664 size=50 ====

void FUN_00b03664(long param_1)

{
  void *pvVar1;
  
  pvVar1 = *(void **)(param_1 + 0x10);
  if (pvVar1 != (void *)0x0) {
    FUN_00b02044(pvVar1);
    operator_delete(pvVar1);
  }
  return;
}


// ==== entry=00b03696 name=FUN_00b03696 size=34 ====

void FUN_00b03696(long param_1)

{
  if (param_1 != 0) {
    FUN_00b0356e(param_1);
  }
  return;
}


// ==== entry=00b036b8 name=FUN_00b036b8 size=19 ====

undefined8 FUN_00b036b8(void)

{
  return 0;
}


// ==== entry=00b036cc name=FUN_00b036cc size=100 ====

undefined * FUN_00b036cc(void)

{
  int iVar1;
  
  if (DAT_011c2a98 == '\0') {
    iVar1 = __cxa_guard_acquire(&DAT_011c2a98);
    if (iVar1 != 0) {
                    /* try { // try from 00b03701 to 00b03705 has its CatchHandler @ 00b0372b */
      std::string::string((string *)&DAT_011c2a90);
      __cxa_guard_release(&DAT_011c2a98);
      __cxa_atexit(std::string::~string,&DAT_011c2a90,&DAT_00c89008);
    }
  }
  return &DAT_011c2a90;
}


// ==== entry=00b0374e name=FUN_00b0374e size=191 ====

void FUN_00b0374e(undefined1 *param_1)

{
  undefined1 auVar1 [12];
  
  *param_1 = 0;
  auVar1 = FUN_00b004e3();
  *(undefined1 (*) [12])(param_1 + 4) = auVar1;
  *(undefined4 *)(param_1 + 0x10) = 1;
  std::string::string((string *)(param_1 + 0x18));
  *(undefined4 *)(param_1 + 0x20) = 0;
                    /* try { // try from 00b037ab to 00b037af has its CatchHandler @ 00b03806 */
  std::string::string((string *)(param_1 + 0x28));
  FUN_00b04cfe(param_1 + 0x30);
  *(undefined8 *)(param_1 + 0x48) = 0;
  FUN_00b04d1a(param_1 + 0x50);
  *(undefined8 *)(param_1 + 0x68) = 0;
  *(undefined8 *)(param_1 + 0x70) = 0;
  FUN_00b04be0(param_1 + 0x68);
  return;
}


// ==== entry=00b0382c name=FUN_00b0382c size=40 ====

void FUN_00b0382c(undefined1 *param_1)

{
  if (*(int *)(param_1 + 0x10) == 0) {
    *(undefined4 *)(param_1 + 0x10) = 1;
  }
  *param_1 = 1;
  return;
}


// ==== entry=00b03854 name=FUN_00b03854 size=36 ====

void FUN_00b03854(long param_1,undefined8 *param_2)

{
  *(undefined8 *)(param_1 + 4) = *param_2;
  *(undefined4 *)(param_1 + 0xc) = *(undefined4 *)(param_2 + 1);
  return;
}


// ==== entry=00b03878 name=FUN_00b03878 size=173 ====

void FUN_00b03878(undefined1 *param_1,int param_2)

{
  if (param_2 == 0) {
    *(undefined4 *)(param_1 + 0x10) = 0;
    *param_1 = 0;
  }
  else {
    *param_1 = 1;
    if (param_2 != *(int *)(param_1 + 0x10)) {
      *(int *)(param_1 + 0x10) = param_2;
      switch(*(undefined4 *)(param_1 + 0x10)) {
      case 0:
                    /* WARNING: Subroutine does not return */
        __assert_fail("false","/mnt/hgfs/Develop/Library/yaml-cpp-0.7.0/src/node_data.cpp",0x45,
                      "void YAML::detail::node_data::set_type(YAML::NodeType::value)");
      case 2:
        std::string::clear((string *)(param_1 + 0x28));
        break;
      case 3:
        FUN_00b043ca(param_1);
        break;
      case 4:
        FUN_00b043f6(param_1);
      }
    }
  }
  return;
}


// ==== entry=00b03926 name=FUN_00b03926 size=42 ====

void FUN_00b03926(long param_1,string *param_2)

{
  std::string::operator=((string *)(param_1 + 0x18),param_2);
  return;
}


// ==== entry=00b03950 name=FUN_00b03950 size=24 ====

void FUN_00b03950(long param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 0x20) = param_2;
  return;
}


// ==== entry=00b03968 name=FUN_00b03968 size=29 ====

void FUN_00b03968(undefined1 *param_1)

{
  *param_1 = 1;
  *(undefined4 *)(param_1 + 0x10) = 1;
  return;
}


// ==== entry=00b03986 name=FUN_00b03986 size=60 ====

void FUN_00b03986(undefined1 *param_1,string *param_2)

{
  *param_1 = 1;
  *(undefined4 *)(param_1 + 0x10) = 2;
  std::string::operator=((string *)(param_1 + 0x28),param_2);
  return;
}


// ==== entry=00b039c2 name=FUN_00b039c2 size=142 ====

long FUN_00b039c2(char *param_1)

{
  long lVar1;
  long lVar2;
  
  if (*param_1 == '\x01') {
    if (*(int *)(param_1 + 0x10) == 3) {
      FUN_00b03a50(param_1);
      lVar1 = *(long *)(param_1 + 0x48);
    }
    else if (*(int *)(param_1 + 0x10) == 4) {
      FUN_00b03ad2(param_1);
      lVar1 = FUN_00b04d5e(param_1 + 0x50);
      lVar2 = FUN_00b04d82(param_1 + 0x68);
      lVar1 = lVar1 - lVar2;
    }
    else {
      lVar1 = 0;
    }
  }
  else {
    lVar1 = 0;
  }
  return lVar1;
}


// ==== entry=00b03a50 name=FUN_00b03a50 size=130 ====

void FUN_00b03a50(long param_1)

{
  ulong uVar1;
  bool bVar2;
  char cVar3;
  ulong uVar4;
  undefined8 *puVar5;
  
  do {
    uVar1 = *(ulong *)(param_1 + 0x48);
    uVar4 = FUN_00b04d9c(param_1 + 0x30);
    if (uVar1 < uVar4) {
      puVar5 = (undefined8 *)FUN_00b04dc0(param_1 + 0x30,*(undefined8 *)(param_1 + 0x48));
      cVar3 = FUN_00b04b64(*puVar5);
      if (cVar3 == '\0') goto LAB_00b03aab;
      bVar2 = true;
    }
    else {
LAB_00b03aab:
      bVar2 = false;
    }
    if (!bVar2) {
      return;
    }
    *(long *)(param_1 + 0x48) = *(long *)(param_1 + 0x48) + 1;
  } while( true );
}


// ==== entry=00b03ad2 name=FUN_00b03ad2 size=235 ====

void FUN_00b03ad2(long param_1)

{
  bool bVar1;
  char cVar2;
  undefined8 uVar3;
  undefined8 *puVar4;
  long lVar5;
  undefined8 local_30;
  undefined8 local_28;
  undefined8 local_20 [2];
  
  uVar3 = FUN_00b04de0(param_1 + 0x68);
  do {
    local_30 = uVar3;
    local_28 = FUN_00b04e08(param_1 + 0x68);
    cVar2 = FUN_00b04e2e(&local_30,&local_28);
    if (cVar2 == '\0') {
      return;
    }
    uVar3 = FUN_00b04e50(local_30,1);
    puVar4 = (undefined8 *)FUN_00b04e7a(&local_30);
    cVar2 = FUN_00b04b64(*puVar4);
    if (cVar2 == '\0') {
LAB_00b03b75:
      bVar1 = false;
    }
    else {
      lVar5 = FUN_00b04e7a(&local_30);
      cVar2 = FUN_00b04b64(*(undefined8 *)(lVar5 + 8));
      if (cVar2 == '\0') goto LAB_00b03b75;
      bVar1 = true;
    }
    if (bVar1) {
      FUN_00b04e98(local_20,&local_30);
      FUN_00b04eb6(param_1 + 0x68,local_20[0]);
    }
  } while( true );
}


// ==== entry=00b03bbe name=FUN_00b03bbe size=181 ====

undefined8 FUN_00b03bbe(undefined8 param_1,char *param_2)

{
  undefined8 uVar1;
  undefined8 uVar2;
  
  if (*param_2 == '\x01') {
    if (*(int *)(param_2 + 0x10) == 3) {
      uVar1 = FUN_00b04f4a(param_2 + 0x30);
      FUN_00b04f7a(param_1,uVar1);
    }
    else if (*(int *)(param_2 + 0x10) == 4) {
      uVar1 = FUN_00b04ff4(param_2 + 0x50);
      uVar2 = FUN_00b04fc4(param_2 + 0x50);
      FUN_00b05026(param_1,uVar2,uVar1);
    }
    else {
      FUN_00b04f00(param_1);
    }
  }
  else {
    FUN_00b04f00(param_1);
  }
  return param_1;
}


// ==== entry=00b03c74 name=FUN_00b03c74 size=181 ====

undefined8 FUN_00b03c74(undefined8 param_1,char *param_2)

{
  undefined8 uVar1;
  undefined8 uVar2;
  
  if (*param_2 == '\x01') {
    if (*(int *)(param_2 + 0x10) == 3) {
      uVar1 = FUN_00b050de(param_2 + 0x30);
      FUN_00b05104(param_1,uVar1);
    }
    else if (*(int *)(param_2 + 0x10) == 4) {
      uVar1 = FUN_00b05174(param_2 + 0x50);
      uVar2 = FUN_00b0514e(param_2 + 0x50);
      FUN_00b0519e(param_1,uVar2,uVar1);
    }
    else {
      FUN_00b05094(param_1);
    }
  }
  else {
    FUN_00b05094(param_1);
  }
  return param_1;
}


// ==== entry=00b03d2a name=FUN_00b03d2a size=181 ====

undefined8 FUN_00b03d2a(undefined8 param_1,char *param_2)

{
  undefined8 uVar1;
  undefined8 uVar2;
  
  if (*param_2 == '\x01') {
    if (*(int *)(param_2 + 0x10) == 3) {
      uVar1 = FUN_00b0520c(param_2 + 0x30);
      FUN_00b04f7a(param_1,uVar1);
    }
    else if (*(int *)(param_2 + 0x10) == 4) {
      uVar1 = FUN_00b04ff4(param_2 + 0x50);
      uVar2 = FUN_00b04ff4(param_2 + 0x50);
      FUN_00b05026(param_1,uVar2,uVar1);
    }
    else {
      FUN_00b04f00(param_1);
    }
  }
  else {
    FUN_00b04f00(param_1);
  }
  return param_1;
}


// ==== entry=00b03de0 name=FUN_00b03de0 size=181 ====

undefined8 FUN_00b03de0(undefined8 param_1,char *param_2)

{
  undefined8 uVar1;
  undefined8 uVar2;
  
  if (*param_2 == '\x01') {
    if (*(int *)(param_2 + 0x10) == 3) {
      uVar1 = FUN_00b0523e(param_2 + 0x30);
      FUN_00b05104(param_1,uVar1);
    }
    else if (*(int *)(param_2 + 0x10) == 4) {
      uVar1 = FUN_00b05174(param_2 + 0x50);
      uVar2 = FUN_00b05174(param_2 + 0x50);
      FUN_00b0519e(param_1,uVar2,uVar1);
    }
    else {
      FUN_00b05094(param_1);
    }
  }
  else {
    FUN_00b05094(param_1);
  }
  return param_1;
}


// ==== entry=00b03e96 name=FUN_00b03e96 size=162 ====

void FUN_00b03e96(long param_1,undefined8 param_2)

{
  undefined8 uVar1;
  undefined8 local_20;
  
  if ((*(int *)(param_1 + 0x10) == 0) || (*(int *)(param_1 + 0x10) == 1)) {
    *(undefined4 *)(param_1 + 0x10) = 3;
    FUN_00b043ca(param_1);
  }
  if (*(int *)(param_1 + 0x10) != 3) {
    uVar1 = __cxa_allocate_exception(0x28);
                    /* try { // try from 00b03ef7 to 00b03efb has its CatchHandler @ 00b03f2f */
    FUN_00b0499e(uVar1);
                    /* WARNING: Subroutine does not return */
    __cxa_throw(uVar1,&PTR_PTR_00d39b58,FUN_00b00c56);
  }
  local_20 = param_2;
  FUN_00b05268(param_1 + 0x30,&local_20);
  return;
}


// ==== entry=00b03f4e name=FUN_00b03f4e size=164 ====

void FUN_00b03f4e(long param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 uVar1;
  
  switch(*(undefined4 *)(param_1 + 0x10)) {
  case 0:
  case 1:
  case 3:
    FUN_00b044ca(param_1,param_4);
    break;
  case 2:
    uVar1 = __cxa_allocate_exception(0x28);
                    /* try { // try from 00b03fb8 to 00b03fbc has its CatchHandler @ 00b03fe9 */
    FUN_00b0529a(uVar1,param_1 + 4,param_2);
                    /* WARNING: Subroutine does not return */
    __cxa_throw(uVar1,&PTR_PTR_00d39b88,FUN_00b00c08);
  }
  FUN_00b04426(param_1,param_2,param_3);
  return;
}


// ==== entry=00b04008 name=FUN_00b04008 size=182 ====

undefined8 FUN_00b04008(long param_1,undefined8 param_2)

{
  char cVar1;
  undefined8 local_28;
  undefined8 local_20;
  undefined8 *local_18;
  long local_10;
  
  if (*(int *)(param_1 + 0x10) == 4) {
    local_10 = param_1 + 0x50;
    local_20 = FUN_00b04fc4(local_10);
    local_28 = FUN_00b04ff4(local_10);
    while (cVar1 = FUN_00b05319(&local_20,&local_28), cVar1 != '\0') {
      local_18 = (undefined8 *)FUN_00b05376(&local_20);
      cVar1 = FUN_00b04b3e(*local_18,param_2);
      if (cVar1 != '\0') {
        return local_18[1];
      }
      FUN_00b05356(&local_20);
    }
  }
  return 0;
}


// ==== entry=00b040be name=FUN_00b040be size=321 ====

undefined8 FUN_00b040be(long param_1,undefined8 param_2,undefined8 param_3)

{
  char cVar1;
  undefined8 uVar2;
  undefined8 local_40;
  undefined8 local_38;
  undefined8 local_30;
  undefined8 *local_28;
  long local_20;
  
  switch(*(undefined4 *)(param_1 + 0x10)) {
  case 0:
  case 1:
  case 3:
    FUN_00b044ca(param_1,param_3);
    break;
  case 2:
    uVar2 = __cxa_allocate_exception(0x28);
                    /* try { // try from 00b04124 to 00b04128 has its CatchHandler @ 00b041f6 */
    FUN_00b0529a(uVar2,param_1 + 4,param_2);
                    /* WARNING: Subroutine does not return */
    __cxa_throw(uVar2,&PTR_PTR_00d39b88,FUN_00b00c08);
  }
  local_20 = param_1 + 0x50;
  local_38 = FUN_00b0514e(local_20);
  local_40 = FUN_00b05174(local_20);
  while( true ) {
    cVar1 = FUN_00b05387(&local_38,&local_40);
    if (cVar1 == '\0') {
      uVar2 = FUN_00b053f6(param_3);
      local_30 = FUN_00b04a50(uVar2);
      FUN_00b04426(param_1,param_2,local_30);
      return local_30;
    }
    local_28 = (undefined8 *)FUN_00b053e4(&local_38);
    cVar1 = FUN_00b04b3e(*local_28,param_2);
    if (cVar1 != '\0') break;
    FUN_00b053c4(&local_38);
  }
  return local_28[1];
}


// ==== entry=00b04216 name=FUN_00b04216 size=53 ====

void FUN_00b04216(undefined8 *param_1,undefined8 param_2)

{
  FUN_00b04b3e(param_2,*param_1);
  return;
}


// ==== entry=00b0424c name=FUN_00b0424c size=381 ====

undefined8 FUN_00b0424c(long param_1,undefined8 param_2)

{
  char cVar1;
  undefined8 uVar2;
  undefined8 *puVar3;
  undefined8 uVar4;
  undefined8 local_48;
  undefined8 local_40;
  undefined8 local_38;
  undefined8 local_30;
  undefined8 local_28;
  undefined8 local_20;
  
  if (*(int *)(param_1 + 0x10) == 4) {
    uVar2 = FUN_00b04de0(param_1 + 0x68);
    while( true ) {
      local_48 = uVar2;
      local_38 = FUN_00b04e08(param_1 + 0x68);
      cVar1 = FUN_00b04e2e(&local_48,&local_38);
      if (cVar1 == '\0') break;
      uVar2 = FUN_00b04e50(local_48,1);
      puVar3 = (undefined8 *)FUN_00b04e7a(&local_48);
      cVar1 = FUN_00b04b3e(*puVar3,param_2);
      if (cVar1 != '\0') {
        FUN_00b04e98(&local_30,&local_48);
        FUN_00b04eb6(param_1 + 0x68,local_30);
      }
    }
    uVar2 = FUN_00b05174(param_1 + 0x50);
    uVar4 = FUN_00b0514e(param_1 + 0x50);
    local_40 = FUN_00b046e8(uVar4,uVar2,param_2);
    local_28 = FUN_00b05174(param_1 + 0x50);
    cVar1 = FUN_00b05387(&local_40,&local_28);
    if (cVar1 == '\0') {
      uVar2 = 0;
    }
    else {
      FUN_00b05410(&local_20,&local_40);
      FUN_00b0543a(param_1 + 0x50,local_20);
      uVar2 = 1;
    }
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}


// ==== entry=00b043ca name=FUN_00b043ca size=43 ====

void FUN_00b043ca(long param_1)

{
  FUN_00b054aa(param_1 + 0x30);
  *(undefined8 *)(param_1 + 0x48) = 0;
  return;
}


// ==== entry=00b043f6 name=FUN_00b043f6 size=47 ====

void FUN_00b043f6(long param_1)

{
  FUN_00b054d0(param_1 + 0x50);
  FUN_00b054f6(param_1 + 0x68);
  return;
}


// ==== entry=00b04426 name=FUN_00b04426 size=163 ====

void FUN_00b04426(long param_1,undefined8 param_2,undefined8 param_3)

{
  bool bVar1;
  char cVar2;
  undefined8 local_28;
  undefined8 local_20;
  undefined8 local_18;
  undefined8 local_10;
  
  local_28 = param_3;
  local_20 = param_2;
  FUN_00b0552c(param_1 + 0x50,&local_20,&local_28);
  cVar2 = FUN_00b04b64(param_2);
  if (cVar2 == '\x01') {
    cVar2 = FUN_00b04b64(param_3);
    if (cVar2 == '\x01') {
      bVar1 = false;
      goto LAB_00b04497;
    }
  }
  bVar1 = true;
LAB_00b04497:
  if (bVar1) {
    local_18 = param_3;
    local_10 = param_2;
    FUN_00b055ec(param_1 + 0x68,&local_10,&local_18);
  }
  return;
}


// ==== entry=00b044ca name=FUN_00b044ca size=115 ====

void FUN_00b044ca(long param_1,undefined8 param_2)

{
  switch(*(undefined4 *)(param_1 + 0x10)) {
  case 0:
  case 1:
    FUN_00b043f6(param_1);
    *(undefined4 *)(param_1 + 0x10) = 4;
    break;
  case 2:
                    /* WARNING: Subroutine does not return */
    __assert_fail("false","/mnt/hgfs/Develop/Library/yaml-cpp-0.7.0/src/node_data.cpp",0x12e,
                  "void YAML::detail::node_data::convert_to_map(const shared_memory_holder&)");
  case 3:
    FUN_00b0453e(param_1,param_2);
  }
  return;
}


// ==== entry=00b0453e name=FUN_00b0453e size=380 ====

void FUN_00b0453e(long param_1,undefined8 param_2)

{
  undefined4 uVar1;
  ulong uVar2;
  undefined8 uVar3;
  undefined8 *puVar4;
  stringstream local_1a8 [16];
  ostream aoStack_198 [360];
  string local_30 [8];
  undefined8 local_28;
  ulong local_20;
  
  if (*(int *)(param_1 + 0x10) != 3) {
                    /* WARNING: Subroutine does not return */
    __assert_fail("m_type == NodeType::Sequence",
                  "/mnt/hgfs/Develop/Library/yaml-cpp-0.7.0/src/node_data.cpp",0x134,
                  "void YAML::detail::node_data::convert_sequence_to_map(const shared_memory_holder&)"
                 );
  }
  FUN_00b043f6(param_1);
  local_20 = 0;
  while( true ) {
    uVar2 = FUN_00b04d9c(param_1 + 0x30);
    if (uVar2 <= local_20) break;
    uVar1 = FUN_00b004d1(0x10,8);
    std::stringstream::stringstream(local_1a8,uVar1);
                    /* try { // try from 00b045f0 to 00b04625 has its CatchHandler @ 00b046c1 */
    std::ostream::operator<<(aoStack_198,local_20);
    uVar3 = FUN_00b053f6(param_2);
    local_28 = FUN_00b04a50(uVar3);
    std::stringstream::str();
                    /* try { // try from 00b04634 to 00b04638 has its CatchHandler @ 00b046b0 */
    FUN_00b04b86(local_28,local_30);
    std::string::~string(local_30);
    puVar4 = (undefined8 *)FUN_00b0564c(param_1 + 0x30,local_20);
                    /* try { // try from 00b04673 to 00b04677 has its CatchHandler @ 00b046c1 */
    FUN_00b04426(param_1,local_28,*puVar4);
    std::stringstream::~stringstream(local_1a8);
    local_20 = local_20 + 1;
  }
  FUN_00b043ca(param_1);
  *(undefined4 *)(param_1 + 0x10) = 4;
  return;
}


// ==== entry=00b046e8 name=FUN_00b046e8 size=56 ====

void FUN_00b046e8(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  undefined8 uVar1;
  
  uVar1 = FUN_00b0472e(param_3);
  FUN_00b0475e(param_1,param_2,uVar1);
  return;
}


// ==== entry=00b04720 name=FUN_00b04720 size=14 ====

undefined8 FUN_00b04720(undefined8 param_1)

{
  return param_1;
}


// ==== entry=00b0472e name=FUN_00b0472e size=48 ====

undefined8 FUN_00b0472e(undefined8 param_1)

{
  undefined8 *puVar1;
  undefined8 local_20 [2];
  undefined8 local_10;
  
  local_20[0] = param_1;
  puVar1 = (undefined8 *)FUN_00b04720(local_20);
  FUN_00b04798(&local_10,*puVar1);
  return local_10;
}


// ==== entry=00b0475e name=FUN_00b0475e size=58 ====

void FUN_00b0475e(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  undefined8 local_20 [3];
  
  local_20[0] = param_1;
  FUN_00b05b86(local_20);
  FUN_00b047c4(local_20[0],param_2,param_3);
  return;
}


// ==== entry=00b04798 name=FUN_00b04798 size=44 ====

void FUN_00b04798(undefined8 *param_1,undefined8 param_2)

{
  undefined8 *puVar1;
  undefined8 local_18;
  undefined8 *local_10;
  
  local_18 = param_2;
  local_10 = param_1;
  puVar1 = (undefined8 *)FUN_00b04720(&local_18);
  *local_10 = *puVar1;
  return;
}


// ==== entry=00b047c4 name=FUN_00b047c4 size=412 ====

undefined8 FUN_00b047c4(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  char cVar1;
  long lVar2;
  undefined8 local_30;
  undefined8 local_28;
  undefined8 local_20 [2];
  long local_10;
  
  local_30 = param_3;
  local_28 = param_2;
  local_20[0] = param_1;
  local_10 = FUN_00b0677b(&local_28,local_20);
  for (local_10 = local_10 >> 2; 0 < local_10; local_10 = local_10 + -1) {
    cVar1 = FUN_00b04960(&local_30,local_20[0]);
    if (cVar1 != '\0') {
      return local_20[0];
    }
    FUN_00b053c4(local_20);
    cVar1 = FUN_00b04960(&local_30,local_20[0]);
    if (cVar1 != '\0') {
      return local_20[0];
    }
    FUN_00b053c4(local_20);
    cVar1 = FUN_00b04960(&local_30,local_20[0]);
    if (cVar1 != '\0') {
      return local_20[0];
    }
    FUN_00b053c4(local_20);
    cVar1 = FUN_00b04960(&local_30,local_20[0]);
    if (cVar1 != '\0') {
      return local_20[0];
    }
    FUN_00b053c4(local_20);
  }
  lVar2 = FUN_00b0677b(&local_28,local_20);
  if (lVar2 != 2) {
    if (lVar2 != 3) {
      if (lVar2 != 1) {
        return local_28;
      }
      goto LAB_00b04931;
    }
    cVar1 = FUN_00b04960(&local_30,local_20[0]);
    if (cVar1 != '\0') {
      return local_20[0];
    }
    FUN_00b053c4(local_20);
  }
  cVar1 = FUN_00b04960(&local_30,local_20[0]);
  if (cVar1 != '\0') {
    return local_20[0];
  }
  FUN_00b053c4(local_20);
LAB_00b04931:
  cVar1 = FUN_00b04960(&local_30,local_20[0]);
  if (cVar1 == '\0') {
    FUN_00b053c4(local_20);
    local_20[0] = local_28;
  }
  return local_20[0];
}


// ==== entry=00b04960 name=FUN_00b04960 size=61 ====

void FUN_00b04960(undefined8 param_1,undefined8 param_2)

{
  undefined8 *puVar1;
  undefined8 local_28;
  undefined8 local_20;
  
  local_28 = param_2;
  local_20 = param_1;
  puVar1 = (undefined8 *)FUN_00b053e4(&local_28);
  FUN_00b04216(param_1,*puVar1,puVar1[1]);
  return;
}


// ==== entry=00b0499e name=FUN_00b0499e size=134 ====

void FUN_00b0499e(undefined8 *param_1)

{
  string local_30 [11];
  allocator local_25;
  undefined1 local_24 [12];
  
  std::allocator<char>::allocator();
                    /* try { // try from 00b049cb to 00b049cf has its CatchHandler @ 00b04a2e */
  std::string::string(local_30,"appending to a non-sequence",&local_25);
  local_24 = FUN_00b004e3();
                    /* try { // try from 00b049f2 to 00b049f6 has its CatchHandler @ 00b04a1d */
  FUN_00b0058c(param_1,local_24,local_30);
  std::string::~string(local_30);
  std::allocator<char>::~allocator((allocator<char> *)&local_25);
  *param_1 = &PTR_FUN_00d39930;
  return;
}


// ==== entry=00b04a50 name=FUN_00b04a50 size=34 ====

void FUN_00b04a50(undefined8 param_1)

{
  undefined8 uVar1;
  
  uVar1 = FUN_00b012a0(param_1);
  FUN_00b00e10(uVar1);
  return;
}


// ==== entry=00b04a72 name=FUN_00b04a72 size=27 ====

void FUN_00b04a72(undefined8 param_1)

{
  FUN_00b04a8e(param_1);
  return;
}


// ==== entry=00b04a8e name=FUN_00b04a8e size=38 ====

void FUN_00b04a8e(undefined8 *param_1)

{
  param_1[1] = param_1;
  *param_1 = param_1[1];
  return;
}


// ==== entry=00b04ab4 name=FUN_00b04ab4 size=17 ====

undefined1 FUN_00b04ab4(undefined1 *param_1)

{
  return *param_1;
}


// ==== entry=00b04ac6 name=FUN_00b04ac6 size=34 ====

void FUN_00b04ac6(undefined8 param_1)

{
  undefined8 uVar1;
  
  uVar1 = FUN_00b00738(param_1);
  FUN_00b04ab4(uVar1);
  return;
}


// ==== entry=00b04ae8 name=FUN_00b04ae8 size=35 ====

void FUN_00b04ae8(undefined8 param_1)

{
  undefined8 uVar1;
  
  uVar1 = FUN_00b00738(param_1);
  FUN_00b0382c(uVar1);
  return;
}


// ==== entry=00b04b0c name=FUN_00b04b0c size=49 ====

void FUN_00b04b0c(undefined8 param_1,undefined8 param_2)

{
  undefined8 uVar1;
  
  uVar1 = FUN_00b00738(param_1);
  FUN_00b03986(uVar1,param_2);
  return;
}


// ==== entry=00b04b3e name=FUN_00b04b3e size=37 ====

void FUN_00b04b3e(undefined8 param_1,undefined8 param_2)

{
  FUN_00b04bfb(param_1,param_2);
  return;
}


// ==== entry=00b04b64 name=FUN_00b04b64 size=34 ====

void FUN_00b04b64(undefined8 param_1)

{
  undefined8 uVar1;
  
  uVar1 = FUN_00b00764(param_1);
  FUN_00b04ac6(uVar1);
  return;
}


// ==== entry=00b04b86 name=FUN_00b04b86 size=61 ====

void FUN_00b04b86(undefined8 param_1,undefined8 param_2)

{
  undefined8 uVar1;
  
  rbtree_clear_recursive(param_1);
  uVar1 = FUN_00b00764(param_1);
  FUN_00b04b0c(uVar1,param_2);
  return;
}


// ==== entry=00b04bc4 name=FUN_00b04bc4 size=27 ====

void FUN_00b04bc4(undefined8 param_1)

{
  FUN_00b04d36(param_1);
  return;
}


// ==== entry=00b04be0 name=FUN_00b04be0 size=27 ====

void FUN_00b04be0(undefined8 param_1)

{
  FUN_00b04bc4(param_1);
  return;
}


// ==== entry=00b04bfb name=FUN_00b04bfb size=57 ====

bool FUN_00b04bfb(undefined8 param_1,undefined8 param_2)

{
  long lVar1;
  long lVar2;
  
  lVar1 = FUN_00b00752(param_1);
  lVar2 = FUN_00b00752(param_2);
  return lVar1 == lVar2;
}


// ==== entry=00b04c34 name=FUN_00b04c34 size=26 ====

void FUN_00b04c34(undefined8 param_1)

{
  FUN_00b0566c(param_1);
  return;
}


// ==== entry=00b04c4e name=FUN_00b04c4e size=26 ====

void FUN_00b04c4e(undefined8 param_1)

{
  FUN_00b05696(param_1);
  return;
}


// ==== entry=00b04c68 name=FUN_00b04c68 size=34 ====

undefined8 FUN_00b04c68(long *param_1,long *param_2)

{
  return CONCAT71((int7)((ulong)*param_2 >> 8),*param_1 != *param_2);
}


// ==== entry=00b04c8a name=FUN_00b04c8a size=43 ====

undefined8 * FUN_00b04c8a(undefined8 *param_1)

{
  undefined8 uVar1;
  
  uVar1 = std::_Rb_tree_increment((_Rb_tree_node_base *)*param_1);
  *param_1 = uVar1;
  return param_1;
}


// ==== entry=00b04cb6 name=FUN_00b04cb6 size=29 ====

void FUN_00b04cb6(undefined8 *param_1)

{
  FUN_00b056c0(*param_1);
  return;
}


// ==== entry=00b04cd4 name=FUN_00b04cd4 size=27 ====

void FUN_00b04cd4(undefined8 param_1)

{
  FUN_00b056de(param_1);
  return;
}


// ==== entry=00b04cef name=FUN_00b04cef size=14 ====

undefined8 FUN_00b04cef(undefined8 param_1)

{
  return param_1;
}


// ==== entry=00b04cfe name=FUN_00b04cfe size=27 ====

void FUN_00b04cfe(undefined8 param_1)

{
  FUN_00b0571c(param_1);
  return;
}


// ==== entry=00b04d1a name=FUN_00b04d1a size=27 ====

void FUN_00b04d1a(undefined8 param_1)

{
  FUN_00b05738(param_1);
  return;
}


// ==== entry=00b04d36 name=FUN_00b04d36 size=39 ====

void FUN_00b04d36(undefined8 param_1)

{
  FUN_00b05754(param_1);
  FUN_00b04a72(param_1);
  return;
}


// ==== entry=00b04d5e name=FUN_00b04d5e size=35 ====

long FUN_00b04d5e(long *param_1)

{
  return param_1[1] - *param_1 >> 4;
}


// ==== entry=00b04d82 name=FUN_00b04d82 size=26 ====

void FUN_00b04d82(undefined8 param_1)

{
  FUN_00b05770(param_1);
  return;
}


// ==== entry=00b04d9c name=FUN_00b04d9c size=35 ====

long FUN_00b04d9c(long *param_1)

{
  return param_1[1] - *param_1 >> 3;
}


// ==== entry=00b04dc0 name=FUN_00b04dc0 size=32 ====

long FUN_00b04dc0(long *param_1,long param_2)

{
  return *param_1 + param_2 * 8;
}


// ==== entry=00b04de0 name=FUN_00b04de0 size=40 ====

undefined8 FUN_00b04de0(undefined8 *param_1)

{
  undefined8 local_10;
  
  FUN_00b057aa(&local_10,*param_1);
  return local_10;
}


// ==== entry=00b04e08 name=FUN_00b04e08 size=37 ====

undefined8 FUN_00b04e08(undefined8 param_1)

{
  undefined8 local_10;
  
  FUN_00b057aa(&local_10,param_1);
  return local_10;
}


// ==== entry=00b04e2e name=FUN_00b04e2e size=34 ====

undefined8 FUN_00b04e2e(long *param_1,long *param_2)

{
  return CONCAT71((int7)((ulong)*param_2 >> 8),*param_1 != *param_2);
}


// ==== entry=00b04e50 name=FUN_00b04e50 size=41 ====

undefined8 FUN_00b04e50(undefined8 param_1,undefined8 param_2)

{
  undefined8 local_10;
  
  local_10 = param_1;
  FUN_00b057ce(&local_10,param_2);
  return local_10;
}


// ==== entry=00b04e7a name=FUN_00b04e7a size=29 ====

void FUN_00b04e7a(undefined8 *param_1)

{
  FUN_00b0314e(*param_1);
  return;
}


// ==== entry=00b04e98 name=FUN_00b04e98 size=29 ====

void FUN_00b04e98(undefined8 *param_1,undefined8 *param_2)

{
  *param_1 = *param_2;
  return;
}


// ==== entry=00b04eb6 name=FUN_00b04eb6 size=74 ====

undefined8 FUN_00b04eb6(undefined8 param_1,undefined8 *param_2)

{
  undefined8 uVar1;
  undefined8 *local_28;
  undefined8 local_20;
  undefined8 local_10;
  
  local_28 = param_2;
  local_20 = param_1;
  FUN_00b057aa(&local_10,*param_2);
  uVar1 = FUN_00b05880(&local_28);
  FUN_00b05808(local_20,uVar1);
  return local_10;
}


// ==== entry=00b04f00 name=FUN_00b04f00 size=73 ====

void FUN_00b04f00(undefined4 *param_1)

{
  *param_1 = 0;
  FUN_00b058a8(param_1 + 2);
  FUN_00b058be(param_1 + 4);
  FUN_00b058be(param_1 + 6);
  return;
}


// ==== entry=00b04f4a name=FUN_00b04f4a size=48 ====

undefined8 FUN_00b04f4a(undefined8 *param_1)

{
  undefined8 local_18;
  undefined8 local_10;
  
  local_10 = *param_1;
  FUN_00b058d4(&local_18,&local_10);
  return local_18;
}


// ==== entry=00b04f7a name=FUN_00b04f7a size=73 ====

void FUN_00b04f7a(undefined4 *param_1,undefined8 param_2)

{
  *param_1 = 1;
  *(undefined8 *)(param_1 + 2) = param_2;
  FUN_00b058be(param_1 + 4);
  FUN_00b058be(param_1 + 6);
  return;
}


// ==== entry=00b04fc4 name=FUN_00b04fc4 size=48 ====

undefined8 FUN_00b04fc4(undefined8 *param_1)

{
  undefined8 local_18;
  undefined8 local_10;
  
  local_10 = *param_1;
  FUN_00b058f2(&local_18,&local_10);
  return local_18;
}


// ==== entry=00b04ff4 name=FUN_00b04ff4 size=49 ====

undefined8 FUN_00b04ff4(long param_1)

{
  undefined8 local_18;
  undefined8 local_10;
  
  local_10 = *(undefined8 *)(param_1 + 8);
  FUN_00b058f2(&local_18,&local_10);
  return local_18;
}


// ==== entry=00b05026 name=FUN_00b05026 size=110 ====

void FUN_00b05026(undefined4 *param_1,undefined8 param_2,undefined8 param_3)

{
  undefined8 uVar1;
  
  *param_1 = 2;
  FUN_00b058a8(param_1 + 2);
  *(undefined8 *)(param_1 + 4) = param_2;
  *(undefined8 *)(param_1 + 6) = param_3;
  uVar1 = FUN_00b05910(param_1,*(undefined8 *)(param_1 + 4));
  *(undefined8 *)(param_1 + 4) = uVar1;
  return;
}


// ==== entry=00b05094 name=FUN_00b05094 size=73 ====

void FUN_00b05094(undefined4 *param_1)

{
  *param_1 = 0;
  FUN_00b0597a(param_1 + 2);
  FUN_00b05990(param_1 + 4);
  FUN_00b05990(param_1 + 6);
  return;
}


// ==== entry=00b050de name=FUN_00b050de size=37 ====

undefined8 FUN_00b050de(undefined8 param_1)

{
  undefined8 local_10;
  
  FUN_00b059a6(&local_10,param_1);
  return local_10;
}


// ==== entry=00b05104 name=FUN_00b05104 size=73 ====

void FUN_00b05104(undefined4 *param_1,undefined8 param_2)

{
  *param_1 = 1;
  *(undefined8 *)(param_1 + 2) = param_2;
  FUN_00b05990(param_1 + 4);
  FUN_00b05990(param_1 + 6);
  return;
}


// ==== entry=00b0514e name=FUN_00b0514e size=37 ====

undefined8 FUN_00b0514e(undefined8 param_1)

{
  undefined8 local_10;
  
  FUN_00b059c4(&local_10,param_1);
  return local_10;
}


// ==== entry=00b05174 name=FUN_00b05174 size=41 ====

undefined8 FUN_00b05174(long param_1)

{
  undefined8 local_10;
  
  FUN_00b059c4(&local_10,param_1 + 8);
  return local_10;
}


// ==== entry=00b0519e name=FUN_00b0519e size=110 ====

void FUN_00b0519e(undefined4 *param_1,undefined8 param_2,undefined8 param_3)

{
  undefined8 uVar1;
  
  *param_1 = 2;
  FUN_00b0597a(param_1 + 2);
  *(undefined8 *)(param_1 + 4) = param_2;
  *(undefined8 *)(param_1 + 6) = param_3;
  uVar1 = FUN_00b059e2(param_1,*(undefined8 *)(param_1 + 4));
  *(undefined8 *)(param_1 + 4) = uVar1;
  return;
}


// ==== entry=00b0520c name=FUN_00b0520c size=49 ====

undefined8 FUN_00b0520c(long param_1)

{
  undefined8 local_18;
  undefined8 local_10;
  
  local_10 = *(undefined8 *)(param_1 + 8);
  FUN_00b058d4(&local_18,&local_10);
  return local_18;
}


// ==== entry=00b0523e name=FUN_00b0523e size=41 ====

undefined8 FUN_00b0523e(long param_1)

{
  undefined8 local_10;
  
  FUN_00b059a6(&local_10,param_1 + 8);
  return local_10;
}


// ==== entry=00b05268 name=FUN_00b05268 size=49 ====

void FUN_00b05268(undefined8 param_1,undefined8 param_2)

{
  undefined8 uVar1;
  
  uVar1 = FUN_00b04cef(param_2);
  FUN_00b05a4c(param_1,uVar1);
  return;
}


// ==== entry=00b0529a name=FUN_00b0529a size=101 ====

void FUN_00b0529a(undefined8 *param_1,undefined8 param_2,undefined8 param_3)

{
  string local_20 [16];
  
  FUN_00b05ae6(local_20,param_3,0);
                    /* try { // try from 00b052d9 to 00b052dd has its CatchHandler @ 00b052f8 */
  FUN_00b0058c(param_1,param_2,local_20);
  std::string::~string(local_20);
  *param_1 = &PTR_FUN_00d39958;
  return;
}


// ==== entry=00b05319 name=FUN_00b05319 size=60 ====

undefined8 FUN_00b05319(undefined8 param_1,undefined8 param_2)

{
  long lVar1;
  long *plVar2;
  
  plVar2 = (long *)FUN_00b05b50(param_1);
  lVar1 = *plVar2;
  plVar2 = (long *)FUN_00b05b50(param_2);
  return CONCAT71((int7)((ulong)*plVar2 >> 8),lVar1 != *plVar2);
}


// ==== entry=00b05356 name=FUN_00b05356 size=32 ====

long * FUN_00b05356(long *param_1)

{
  *param_1 = *param_1 + 0x10;
  return param_1;
}


// ==== entry=00b05376 name=FUN_00b05376 size=17 ====

undefined8 FUN_00b05376(undefined8 *param_1)

{
  return *param_1;
}


// ==== entry=00b05387 name=FUN_00b05387 size=60 ====

undefined8 FUN_00b05387(undefined8 param_1,undefined8 param_2)

{
  long lVar1;
  long *plVar2;
  
  plVar2 = (long *)FUN_00b05b5e(param_1);
  lVar1 = *plVar2;
  plVar2 = (long *)FUN_00b05b5e(param_2);
  return CONCAT71((int7)((ulong)*plVar2 >> 8),lVar1 != *plVar2);
}


// ==== entry=00b053c4 name=FUN_00b053c4 size=32 ====

long * FUN_00b053c4(long *param_1)

{
  *param_1 = *param_1 + 0x10;
  return param_1;
}


// ==== entry=00b053e4 name=FUN_00b053e4 size=17 ====

undefined8 FUN_00b053e4(undefined8 *param_1)

{
  return *param_1;
}


// ==== entry=00b053f6 name=FUN_00b053f6 size=26 ====

void FUN_00b053f6(undefined8 param_1)

{
  FUN_00b05b6c(param_1);
  return;
}


// ==== entry=00b05410 name=FUN_00b05410 size=41 ====

void FUN_00b05410(undefined8 *param_1,undefined8 param_2)

{
  undefined8 *puVar1;
  
  puVar1 = (undefined8 *)FUN_00b05b5e(param_2);
  *param_1 = *puVar1;
  return;
}


// ==== entry=00b0543a name=FUN_00b0543a size=111 ====

void FUN_00b0543a(undefined8 param_1,undefined8 param_2)

{
  undefined8 uVar1;
  undefined8 local_38;
  undefined8 local_30;
  undefined8 local_28;
  undefined8 local_20 [2];
  
  local_38 = param_2;
  local_30 = param_1;
  local_28 = FUN_00b05b90(param_1);
  uVar1 = FUN_00b05bc0(&local_38,&local_28);
  local_20[0] = FUN_00b0514e(local_30);
  uVar1 = FUN_00b05c00(local_20,uVar1);
  FUN_00b05c40(local_30,uVar1);
  return;
}


// ==== entry=00b054aa name=FUN_00b054aa size=37 ====

void FUN_00b054aa(undefined8 *param_1)

{
  FUN_00b05cf8(param_1,*param_1);
  return;
}


// ==== entry=00b054d0 name=FUN_00b054d0 size=37 ====

void FUN_00b054d0(undefined8 *param_1)

{
  FUN_00b05d58(param_1,*param_1);
  return;
}


// ==== entry=00b054f6 name=FUN_00b054f6 size=39 ====

void FUN_00b054f6(undefined8 param_1)

{
  FUN_00b02ea8(param_1);
  FUN_00b05db8(param_1);
  return;
}


// ==== entry=00b0551d name=FUN_00b0551d size=14 ====

undefined8 FUN_00b0551d(undefined8 param_1)

{
  return param_1;
}


// ==== entry=00b0552c name=FUN_00b0552c size=192 ====

void FUN_00b0552c(long param_1,undefined8 param_2,undefined8 param_3)

{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  
  if (*(long *)(param_1 + 8) == *(long *)(param_1 + 0x10)) {
    uVar1 = FUN_00b0551d(param_3);
    uVar2 = FUN_00b0551d(param_2);
    uVar3 = FUN_00b05174(param_1);
    FUN_00b05e26(param_1,uVar3,uVar2,uVar1);
  }
  else {
    uVar1 = FUN_00b0551d(param_3);
    uVar2 = FUN_00b0551d(param_2);
    FUN_00b05dd3(param_1,*(undefined8 *)(param_1 + 8),uVar2,uVar1);
    *(long *)(param_1 + 8) = *(long *)(param_1 + 8) + 0x10;
  }
  return;
}


// ==== entry=00b055ec name=FUN_00b055ec size=96 ====

void FUN_00b055ec(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  
  uVar1 = FUN_00b0551d(param_3);
  uVar2 = FUN_00b0551d(param_2);
  uVar3 = FUN_00b04e08(param_1);
  FUN_00b06076(param_1,uVar3,uVar2,uVar1);
  return;
}


// ==== entry=00b0564c name=FUN_00b0564c size=32 ====

long FUN_00b0564c(long *param_1,long param_2)

{
  return *param_1 + param_2 * 8;
}


// ==== entry=00b0566c name=FUN_00b0566c size=41 ====

undefined8 FUN_00b0566c(long param_1)

{
  undefined8 local_10;
  
  FUN_00b060f0(&local_10,*(undefined8 *)(param_1 + 0x18));
  return local_10;
}


// ==== entry=00b05696 name=FUN_00b05696 size=41 ====

undefined8 FUN_00b05696(long param_1)

{
  undefined8 local_10;
  
  FUN_00b060f0(&local_10,param_1 + 8);
  return local_10;
}


// ==== entry=00b056c0 name=FUN_00b056c0 size=30 ====

void FUN_00b056c0(long param_1)

{
  FUN_00b0610a(param_1 + 0x20);
  return;
}


// ==== entry=00b056de name=FUN_00b056de size=61 ====

void FUN_00b056de(long param_1)

{
  undefined8 uVar1;
  
  uVar1 = FUN_00b01692(param_1);
  FUN_00528980(param_1,uVar1);
  FUN_00b00f32(param_1 + 8);
  return;
}


// ==== entry=00b0571c name=FUN_00b0571c size=27 ====

void FUN_00b0571c(undefined8 param_1)

{
  FUN_00b06124(param_1);
  return;
}


// ==== entry=00b05738 name=FUN_00b05738 size=27 ====

void FUN_00b05738(undefined8 param_1)

{
  FUN_00b06162(param_1);
  return;
}


// ==== entry=00b05754 name=FUN_00b05754 size=27 ====

void FUN_00b05754(undefined8 param_1)

{
  FUN_00b061a0(param_1);
  return;
}


// ==== entry=00b05770 name=FUN_00b05770 size=58 ====

void FUN_00b05770(undefined8 param_1)

{
  undefined8 uVar1;
  undefined8 uVar2;
  
  uVar1 = FUN_00b061d4(param_1);
  uVar2 = FUN_00b061ac(param_1);
  FUN_00b06203(uVar2,uVar1);
  return;
}


// ==== entry=00b057aa name=FUN_00b057aa size=26 ====

void FUN_00b057aa(undefined8 *param_1,undefined8 param_2)

{
  *param_1 = param_2;
  return;
}


// ==== entry=00b057c4 name=FUN_00b057c4 size=10 ====

void FUN_00b057c4(void)

{
  return;
}


// ==== entry=00b057ce name=FUN_00b057ce size=58 ====

void FUN_00b057ce(undefined8 param_1,undefined8 param_2)

{
  FUN_00b057c4(param_1);
  FUN_00b06235(param_1,param_2);
  return;
}


// ==== entry=00b05808 name=FUN_00b05808 size=119 ====

void FUN_00b05808(undefined8 param_1,_List_node_base *param_2)

{
  undefined8 uVar1;
  undefined8 uVar2;
  
  FUN_00b06298(param_1,1);
  std::__detail::_List_node_base::_M_unhook(param_2);
  uVar1 = FUN_00b0314e(param_2);
  uVar2 = FUN_00b0316c(param_1);
  FUN_00b0317a(uVar2,uVar1);
  FUN_00b031a0(param_1,param_2);
  return;
}


// ==== entry=00b05880 name=FUN_00b05880 size=40 ====

undefined8 FUN_00b05880(undefined8 *param_1)

{
  undefined8 local_10;
  
  FUN_00b057aa(&local_10,*param_1);
  return local_10;
}


// ==== entry=00b058a8 name=FUN_00b058a8 size=22 ====

void FUN_00b058a8(undefined8 *param_1)

{
  *param_1 = 0;
  return;
}


// ==== entry=00b058be name=FUN_00b058be size=22 ====

void FUN_00b058be(undefined8 *param_1)

{
  *param_1 = 0;
  return;
}


// ==== entry=00b058d4 name=FUN_00b058d4 size=29 ====

void FUN_00b058d4(undefined8 *param_1,undefined8 *param_2)

{
  *param_1 = *param_2;
  return;
}


// ==== entry=00b058f2 name=FUN_00b058f2 size=29 ====

void FUN_00b058f2(undefined8 *param_1,undefined8 *param_2)

{
  *param_1 = *param_2;
  return;
}


// ==== entry=00b05910 name=FUN_00b05910 size=105 ====

undefined8 FUN_00b05910(long param_1,undefined8 param_2)

{
  bool bVar1;
  char cVar2;
  undefined8 local_18;
  long local_10;
  
  local_18 = param_2;
  local_10 = param_1;
  do {
    cVar2 = FUN_00b05319(&local_18,local_10 + 0x18);
    if (cVar2 == '\0') {
LAB_00b0595c:
      bVar1 = false;
    }
    else {
      cVar2 = FUN_00b062a8(local_10,local_18);
      if (cVar2 == '\x01') goto LAB_00b0595c;
      bVar1 = true;
    }
    if (!bVar1) {
      return local_18;
    }
    FUN_00b05356(&local_18);
  } while( true );
}


// ==== entry=00b0597a name=FUN_00b0597a size=22 ====

void FUN_00b0597a(undefined8 *param_1)

{
  *param_1 = 0;
  return;
}


// ==== entry=00b05990 name=FUN_00b05990 size=22 ====

void FUN_00b05990(undefined8 *param_1)

{
  *param_1 = 0;
  return;
}


// ==== entry=00b059a6 name=FUN_00b059a6 size=29 ====

void FUN_00b059a6(undefined8 *param_1,undefined8 *param_2)

{
  *param_1 = *param_2;
  return;
}


// ==== entry=00b059c4 name=FUN_00b059c4 size=29 ====

void FUN_00b059c4(undefined8 *param_1,undefined8 *param_2)

{
  *param_1 = *param_2;
  return;
}


// ==== entry=00b059e2 name=FUN_00b059e2 size=105 ====

undefined8 FUN_00b059e2(long param_1,undefined8 param_2)

{
  bool bVar1;
  char cVar2;
  undefined8 local_18;
  long local_10;
  
  local_18 = param_2;
  local_10 = param_1;
  do {
    cVar2 = FUN_00b05387(&local_18,local_10 + 0x18);
    if (cVar2 == '\0') {
LAB_00b05a2e:
      bVar1 = false;
    }
    else {
      cVar2 = FUN_00b062fe(local_10,local_18);
      if (cVar2 == '\x01') goto LAB_00b05a2e;
      bVar1 = true;
    }
    if (!bVar1) {
      return local_18;
    }
    FUN_00b053c4(&local_18);
  } while( true );
}


// ==== entry=00b05a4c name=FUN_00b05a4c size=154 ====

void FUN_00b05a4c(long param_1,undefined8 param_2)

{
  undefined8 uVar1;
  undefined8 uVar2;
  
  if (*(long *)(param_1 + 8) == *(long *)(param_1 + 0x10)) {
    uVar1 = FUN_00b0551d(param_2);
    uVar2 = FUN_00b0523e(param_1);
    FUN_00b0638c(param_1,uVar2,uVar1);
  }
  else {
    uVar1 = FUN_00b0551d(param_2);
    FUN_00b06353(param_1,*(undefined8 *)(param_1 + 8),uVar1);
    *(long *)(param_1 + 8) = *(long *)(param_1 + 8) + 8;
  }
  return;
}


// ==== entry=00b05ae6 name=FUN_00b05ae6 size=79 ====

string * FUN_00b05ae6(string *param_1)

{
  allocator local_19 [9];
  
  std::allocator<char>::allocator();
                    /* try { // try from 00b05b17 to 00b05b1b has its CatchHandler @ 00b05b2a */
  std::string::string(param_1,"operator[] call on a scalar",local_19);
  std::allocator<char>::~allocator((allocator<char> *)local_19);
  return param_1;
}


// ==== entry=00b05b50 name=FUN_00b05b50 size=14 ====

undefined8 FUN_00b05b50(undefined8 param_1)

{
  return param_1;
}


// ==== entry=00b05b5e name=FUN_00b05b5e size=14 ====

undefined8 FUN_00b05b5e(undefined8 param_1)

{
  return param_1;
}


// ==== entry=00b05b6c name=FUN_00b05b6c size=26 ====

void FUN_00b05b6c(undefined8 param_1)

{
  FUN_00b065cc(param_1);
  return;
}


// ==== entry=00b05b86 name=FUN_00b05b86 size=10 ====

void FUN_00b05b86(void)

{
  return;
}


// ==== entry=00b05b90 name=FUN_00b05b90 size=48 ====

undefined8 FUN_00b05b90(undefined8 *param_1)

{
  undefined8 local_18;
  undefined8 local_10;
  
  local_10 = *param_1;
  FUN_00b058f2(&local_18,&local_10);
  return local_18;
}


// ==== entry=00b05bc0 name=FUN_00b05bc0 size=64 ====

long FUN_00b05bc0(undefined8 param_1,undefined8 param_2)

{
  long lVar1;
  long *plVar2;
  
  plVar2 = (long *)FUN_00b05b50(param_1);
  lVar1 = *plVar2;
  plVar2 = (long *)FUN_00b05b50(param_2);
  return lVar1 - *plVar2 >> 4;
}


// ==== entry=00b05c00 name=FUN_00b05c00 size=63 ====

undefined8 FUN_00b05c00(long *param_1,long param_2)

{
  undefined8 local_18;
  long local_10;
  
  local_10 = *param_1 + param_2 * 0x10;
  FUN_00b059c4(&local_18,&local_10);
  return local_18;
}


// ==== entry=00b05c40 name=FUN_00b05c40 size=184 ====

undefined8 FUN_00b05c40(long param_1,undefined8 param_2)

{
  char cVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 local_38;
  long local_30;
  undefined8 local_28;
  undefined8 local_20 [2];
  
  local_38 = param_2;
  local_30 = param_1;
  local_28 = FUN_00b05174(param_1);
  local_20[0] = FUN_00b05c00(&local_38,1);
  cVar1 = FUN_00b05387(local_20,&local_28);
  if (cVar1 != '\0') {
    uVar2 = FUN_00b05174(local_30);
    uVar3 = FUN_00b05c00(&local_38,1);
    FUN_00b065dd(uVar3,uVar2,local_38);
  }
  *(long *)(local_30 + 8) = *(long *)(local_30 + 8) + -0x10;
  FUN_00b06629(local_30,*(undefined8 *)(local_30 + 8));
  return local_38;
}


// ==== entry=00b05cf8 name=FUN_00b05cf8 size=96 ====

void FUN_00b05cf8(long param_1,long param_2)

{
  undefined8 uVar1;
  
  if (*(long *)(param_1 + 8) - param_2 >> 3 != 0) {
    uVar1 = FUN_00b02db2(param_1);
    FUN_00b02dc0(param_2,*(undefined8 *)(param_1 + 8),uVar1);
    *(long *)(param_1 + 8) = param_2;
  }
  return;
}


// ==== entry=00b05d58 name=FUN_00b05d58 size=96 ====

void FUN_00b05d58(long param_1,long param_2)

{
  undefined8 uVar1;
  
  if (*(long *)(param_1 + 8) - param_2 >> 4 != 0) {
    uVar1 = FUN_00b02e54(param_1);
    FUN_00b02e62(param_2,*(undefined8 *)(param_1 + 8),uVar1);
    *(long *)(param_1 + 8) = param_2;
  }
  return;
}


// ==== entry=00b05db8 name=FUN_00b05db8 size=27 ====

void FUN_00b05db8(undefined8 param_1)

{
  FUN_00b04a8e(param_1);
  return;
}


// ==== entry=00b05dd3 name=FUN_00b05dd3 size=82 ====

void FUN_00b05dd3(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 uVar1;
  undefined8 uVar2;
  
  uVar1 = FUN_00b0551d(param_4);
  uVar2 = FUN_00b0551d(param_3);
  FUN_00b06650(param_1,param_2,uVar2,uVar1);
  return;
}


// ==== entry=00b05e26 name=FUN_00b05e26 size=460 ====

void FUN_00b05e26(long *param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

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
  local_28 = FUN_00b066b2(param_1,1,"vector::_M_realloc_insert");
  local_30 = *local_60;
  local_38 = local_60[1];
  local_50 = FUN_00b0514e(local_60);
  local_40 = FUN_00b0677b(&local_68,&local_50);
  local_48 = FUN_00b067bc(local_60,local_28);
  local_20 = local_48;
  uVar1 = FUN_00b0551d(param_4);
  uVar2 = FUN_00b0551d(param_3);
                    /* try { // try from 00b05ef4 to 00b05f6b has its CatchHandler @ 00b05feb */
  FUN_00b05dd3(local_60,local_40 * 0x10 + local_48,uVar2,uVar1);
  local_20 = 0;
  uVar1 = FUN_00b02e54(local_60);
  puVar3 = (undefined8 *)FUN_00b05b5e(&local_68);
  local_20 = FUN_00b067ef(local_30,*puVar3,local_48,uVar1);
  local_20 = local_20 + 0x10;
  uVar1 = FUN_00b02e54(local_60);
  puVar3 = (undefined8 *)FUN_00b05b5e(&local_68);
  local_20 = FUN_00b067ef(*puVar3,local_38,local_20,uVar1);
  uVar1 = FUN_00b02e54(local_60);
  FUN_00b02e62(local_30,local_38,uVar1);
  FUN_00b030e6(local_60,local_30,local_60[2] - local_30 >> 4);
  *local_60 = local_48;
  local_60[1] = local_20;
  local_60[2] = local_28 * 0x10 + local_48;
  return;
}


// ==== entry=00b06076 name=FUN_00b06076 size=121 ====

void FUN_00b06076(undefined8 param_1,_List_node_base *param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 uVar1;
  undefined8 uVar2;
  _List_node_base *this;
  
  uVar1 = FUN_00b0551d(param_4);
  uVar2 = FUN_00b0551d(param_3);
  this = (_List_node_base *)FUN_00b06844(param_1,uVar2,uVar1);
  std::__detail::_List_node_base::_M_hook(this,param_2);
  FUN_00b0691a(param_1,1);
  return;
}


// ==== entry=00b060f0 name=FUN_00b060f0 size=26 ====

void FUN_00b060f0(undefined8 *param_1,undefined8 param_2)

{
  *param_1 = param_2;
  return;
}


// ==== entry=00b0610a name=FUN_00b0610a size=26 ====

void FUN_00b0610a(undefined8 param_1)

{
  FUN_00b0692a(param_1);
  return;
}


// ==== entry=00b06124 name=FUN_00b06124 size=62 ====

void FUN_00b06124(undefined8 *param_1)

{
  FUN_00b06938(param_1);
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  return;
}


// ==== entry=00b06162 name=FUN_00b06162 size=62 ====

void FUN_00b06162(undefined8 *param_1)

{
  FUN_00b06954(param_1);
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  return;
}


// ==== entry=00b061a0 name=FUN_00b061a0 size=11 ====

void FUN_00b061a0(void)

{
  return;
}


// ==== entry=00b061ac name=FUN_00b061ac size=40 ====

undefined8 FUN_00b061ac(undefined8 *param_1)

{
  undefined8 local_10;
  
  FUN_00b06970(&local_10,*param_1);
  return local_10;
}


// ==== entry=00b061d4 name=FUN_00b061d4 size=37 ====

undefined8 FUN_00b061d4(undefined8 param_1)

{
  undefined8 local_10;
  
  FUN_00b06970(&local_10,param_1);
  return local_10;
}


// ==== entry=00b061f9 name=FUN_00b061f9 size=10 ====

void FUN_00b061f9(void)

{
  return;
}


// ==== entry=00b06203 name=FUN_00b06203 size=50 ====

void FUN_00b06203(undefined8 param_1,undefined8 param_2)

{
  undefined8 local_20 [3];
  
  local_20[0] = param_1;
  FUN_00b061f9(local_20);
  FUN_00b0698a(local_20[0],param_2);
  return;
}


// ==== entry=00b06235 name=FUN_00b06235 size=98 ====

void FUN_00b06235(undefined8 param_1,long param_2)

{
  undefined8 local_18;
  
  local_18 = param_2;
  if (param_2 < 1) {
    while( true ) {
      if (local_18 == 0) break;
      FUN_00b069f2(param_1);
      local_18 = local_18 + 1;
    }
  }
  else {
    while( true ) {
      if (local_18 == 0) break;
      FUN_00b069d2(param_1);
      local_18 = local_18 + -1;
    }
  }
  return;
}


// ==== entry=00b06298 name=FUN_00b06298 size=15 ====

void FUN_00b06298(void)

{
  return;
}


// ==== entry=00b062a8 name=FUN_00b062a8 size=85 ====

undefined8 FUN_00b062a8(undefined8 param_1,undefined8 param_2)

{
  char cVar1;
  undefined8 *puVar2;
  long lVar3;
  undefined8 local_18;
  undefined8 local_10;
  
  local_18 = param_2;
  local_10 = param_1;
  puVar2 = (undefined8 *)FUN_00b06a12(&local_18);
  cVar1 = FUN_00b04b64(*puVar2);
  if (cVar1 != '\0') {
    lVar3 = FUN_00b06a12(&local_18);
    cVar1 = FUN_00b04b64(*(undefined8 *)(lVar3 + 8));
    if (cVar1 != '\0') {
      return 1;
    }
  }
  return 0;
}


// ==== entry=00b062fe name=FUN_00b062fe size=85 ====

undefined8 FUN_00b062fe(undefined8 param_1,undefined8 param_2)

{
  char cVar1;
  undefined8 *puVar2;
  long lVar3;
  undefined8 local_18;
  undefined8 local_10;
  
  local_18 = param_2;
  local_10 = param_1;
  puVar2 = (undefined8 *)FUN_00b06a24(&local_18);
  cVar1 = FUN_00b04b64(*puVar2);
  if (cVar1 != '\0') {
    lVar3 = FUN_00b06a24(&local_18);
    cVar1 = FUN_00b04b64(*(undefined8 *)(lVar3 + 8));
    if (cVar1 != '\0') {
      return 1;
    }
  }
  return 0;
}


// ==== entry=00b06353 name=FUN_00b06353 size=57 ====

void FUN_00b06353(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  undefined8 uVar1;
  
  uVar1 = FUN_00b0551d(param_3);
  FUN_00b06a36(param_1,param_2,uVar1);
  return;
}


// ==== entry=00b0638c name=FUN_00b0638c size=443 ====

void FUN_00b0638c(long *param_1,undefined8 param_2,undefined8 param_3)

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
  local_28 = FUN_00b06a76(param_1,1,"vector::_M_realloc_insert");
  local_30 = *local_60;
  local_38 = local_60[1];
  local_50 = FUN_00b050de(local_60);
  local_40 = FUN_00b06b3f(&local_68,&local_50);
  local_48 = FUN_00b06b80(local_60,local_28);
  local_20 = local_48;
  uVar1 = FUN_00b0551d(param_3);
  FUN_00b06353(local_60,local_40 * 8 + local_48,uVar1);
  local_20 = 0;
  uVar1 = FUN_00b02db2(local_60);
  puVar2 = (undefined8 *)FUN_00b06bb4(&local_68);
                    /* try { // try from 00b06481 to 00b064bf has its CatchHandler @ 00b06540 */
  local_20 = FUN_00b06bc2(local_30,*puVar2,local_48,uVar1);
  local_20 = local_20 + 8;
  uVar1 = FUN_00b02db2(local_60);
  puVar2 = (undefined8 *)FUN_00b06bb4(&local_68);
  local_20 = FUN_00b06bc2(*puVar2,local_38,local_20,uVar1);
  uVar1 = FUN_00b02db2(local_60);
  FUN_00b02dc0(local_30,local_38,uVar1);
  FUN_00b0306e(local_60,local_30,local_60[2] - local_30 >> 3);
  *local_60 = local_48;
  local_60[1] = local_20;
  local_60[2] = local_28 * 8 + local_48;
  return;
}


// ==== entry=00b065cc name=FUN_00b065cc size=17 ====

undefined8 FUN_00b065cc(undefined8 *param_1)

{
  return *param_1;
}


// ==== entry=00b065dd name=FUN_00b065dd size=76 ====

void FUN_00b065dd(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  undefined8 uVar1;
  undefined8 uVar2;
  
  uVar1 = FUN_00b06c3c(param_2);
  uVar2 = FUN_00b06c3c(param_1);
  FUN_00b06c4a(uVar2,uVar1,param_3);
  return;
}


// ==== entry=00b06629 name=FUN_00b06629 size=38 ====

void FUN_00b06629(undefined8 param_1,undefined8 param_2)

{
  FUN_00b06cbe(param_1,param_2);
  return;
}


// ==== entry=00b06650 name=FUN_00b06650 size=98 ====

void FUN_00b06650(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  
  uVar1 = FUN_00b0551d(param_3);
  uVar2 = FUN_00b0551d(param_4);
  uVar3 = identity_forward(0x10,param_2);
  FUN_00b06cce(uVar3,uVar1,uVar2);
  return;
}


// ==== entry=00b066b2 name=FUN_00b066b2 size=201 ====

ulong FUN_00b066b2(undefined8 param_1,ulong param_2,char *param_3)

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
  lVar1 = FUN_00b06d12(param_1);
  lVar2 = FUN_00b04d5e(local_30);
  if (local_38 <= (ulong)(lVar1 - lVar2)) {
    lVar1 = FUN_00b04d5e(local_30);
    local_28 = FUN_00b04d5e(local_30);
    plVar3 = (long *)FUN_00b06d34(&local_28,&local_38);
    local_20 = *plVar3 + lVar1;
    uVar4 = FUN_00b04d5e(local_30);
    if ((local_20 < uVar4) || (uVar4 = FUN_00b06d12(local_30), uVar4 < local_20)) {
      local_20 = FUN_00b06d12(local_30);
    }
    return local_20;
  }
                    /* WARNING: Subroutine does not return */
  std::__throw_length_error(param_3);
}


// ==== entry=00b0677b name=FUN_00b0677b size=64 ====

long FUN_00b0677b(undefined8 param_1,undefined8 param_2)

{
  long lVar1;
  long *plVar2;
  
  plVar2 = (long *)FUN_00b05b5e(param_1);
  lVar1 = *plVar2;
  plVar2 = (long *)FUN_00b05b5e(param_2);
  return lVar1 - *plVar2 >> 4;
}


// ==== entry=00b067bc name=FUN_00b067bc size=51 ====

undefined8 FUN_00b067bc(undefined8 param_1,long param_2)

{
  undefined8 uVar1;
  
  if (param_2 == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = FUN_00b06d5f(param_1,param_2);
  }
  return uVar1;
}


// ==== entry=00b067ef name=FUN_00b067ef size=84 ====

void FUN_00b067ef(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 uVar1;
  undefined8 uVar2;
  
  uVar1 = FUN_00b06d89(param_2);
  uVar2 = FUN_00b06d89(param_1);
  FUN_00b06dae(uVar2,uVar1,param_3,param_4);
  return;
}


// ==== entry=00b06844 name=FUN_00b06844 size=188 ====

undefined8 FUN_00b06844(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined1 local_38 [16];
  undefined8 local_28;
  undefined8 local_20;
  
  local_20 = FUN_00b06de0(param_1);
  local_28 = FUN_00b0316c(param_1);
  FUN_00b06e00(local_38,local_28,local_20);
  uVar1 = FUN_00b0551d(param_3);
  uVar2 = FUN_00b0551d(param_2);
  uVar3 = FUN_00b0314e(local_20);
                    /* try { // try from 00b068cc to 00b068d0 has its CatchHandler @ 00b068f7 */
  FUN_00b06e75(local_28,uVar3,uVar2,uVar1);
  FUN_00b06ec8(local_38,0);
  uVar1 = local_20;
  FUN_00b06e3a(local_38);
  return uVar1;
}


// ==== entry=00b0691a name=FUN_00b0691a size=15 ====

void FUN_00b0691a(void)

{
  return;
}


// ==== entry=00b0692a name=FUN_00b0692a size=14 ====

undefined8 FUN_00b0692a(undefined8 param_1)

{
  return param_1;
}


// ==== entry=00b06938 name=FUN_00b06938 size=27 ====

void FUN_00b06938(undefined8 param_1)

{
  FUN_00b06ee6(param_1);
  return;
}


// ==== entry=00b06954 name=FUN_00b06954 size=27 ====

void FUN_00b06954(undefined8 param_1)

{
  FUN_00b06ef2(param_1);
  return;
}


// ==== entry=00b06970 name=FUN_00b06970 size=26 ====

void FUN_00b06970(undefined8 *param_1,undefined8 param_2)

{
  *param_1 = param_2;
  return;
}


// ==== entry=00b0698a name=FUN_00b0698a size=72 ====

long FUN_00b0698a(undefined8 param_1,undefined8 param_2)

{
  char cVar1;
  undefined8 local_28;
  undefined8 local_20 [2];
  long local_10;
  
  local_10 = 0;
  local_28 = param_2;
  local_20[0] = param_1;
  while( true ) {
    cVar1 = FUN_00b06efe(local_20,&local_28);
    if (cVar1 == '\0') break;
    FUN_00b06f20(local_20);
    local_10 = local_10 + 1;
  }
  return local_10;
}


// ==== entry=00b069d2 name=FUN_00b069d2 size=31 ====

undefined8 * FUN_00b069d2(undefined8 *param_1)

{
  *param_1 = *(undefined8 *)*param_1;
  return param_1;
}


// ==== entry=00b069f2 name=FUN_00b069f2 size=32 ====

long * FUN_00b069f2(long *param_1)

{
  *param_1 = *(long *)(*param_1 + 8);
  return param_1;
}


// ==== entry=00b06a12 name=FUN_00b06a12 size=17 ====

undefined8 FUN_00b06a12(undefined8 *param_1)

{
  return *param_1;
}


// ==== entry=00b06a24 name=FUN_00b06a24 size=17 ====

undefined8 FUN_00b06a24(undefined8 *param_1)

{
  return *param_1;
}


// ==== entry=00b06a36 name=FUN_00b06a36 size=64 ====

void FUN_00b06a36(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  undefined8 uVar1;
  undefined8 *puVar2;
  
  puVar2 = (undefined8 *)FUN_00b0551d(param_3);
  uVar1 = *puVar2;
  puVar2 = (undefined8 *)identity_forward(8,param_2);
  *puVar2 = uVar1;
  return;
}


// ==== entry=00b06a76 name=FUN_00b06a76 size=201 ====

ulong FUN_00b06a76(undefined8 param_1,ulong param_2,char *param_3)

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
  lVar1 = FUN_00b06f40(param_1);
  lVar2 = FUN_00b04d9c(local_30);
  if (local_38 <= (ulong)(lVar1 - lVar2)) {
    lVar1 = FUN_00b04d9c(local_30);
    local_28 = FUN_00b04d9c(local_30);
    plVar3 = (long *)FUN_00b06d34(&local_28,&local_38);
    local_20 = *plVar3 + lVar1;
    uVar4 = FUN_00b04d9c(local_30);
    if ((local_20 < uVar4) || (uVar4 = FUN_00b06f40(local_30), uVar4 < local_20)) {
      local_20 = FUN_00b06f40(local_30);
    }
    return local_20;
  }
                    /* WARNING: Subroutine does not return */
  std::__throw_length_error(param_3);
}


// ==== entry=00b06b3f name=FUN_00b06b3f size=64 ====

long FUN_00b06b3f(undefined8 param_1,undefined8 param_2)

{
  long lVar1;
  long *plVar2;
  
  plVar2 = (long *)FUN_00b06bb4(param_1);
  lVar1 = *plVar2;
  plVar2 = (long *)FUN_00b06bb4(param_2);
  return lVar1 - *plVar2 >> 3;
}


// ==== entry=00b06b80 name=FUN_00b06b80 size=51 ====

undefined8 FUN_00b06b80(undefined8 param_1,long param_2)

{
  undefined8 uVar1;
  
  if (param_2 == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = FUN_00b06f62(param_1,param_2);
  }
  return uVar1;
}


// ==== entry=00b06bb4 name=FUN_00b06bb4 size=14 ====

undefined8 FUN_00b06bb4(undefined8 param_1)

{
  return param_1;
}


// ==== entry=00b06bc2 name=FUN_00b06bc2 size=84 ====

void FUN_00b06bc2(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 uVar1;
  undefined8 uVar2;
  
  uVar1 = FUN_00b06f8c(param_2);
  uVar2 = FUN_00b06f8c(param_1);
  FUN_00b06fb1(uVar2,uVar1,param_3,param_4);
  return;
}


// ==== entry=00b06c16 name=FUN_00b06c16 size=38 ====

void FUN_00b06c16(undefined8 param_1,undefined8 param_2)

{
  FUN_00b06fe2(param_1,param_2);
  return;
}


// ==== entry=00b06c3c name=FUN_00b06c3c size=14 ====

undefined8 FUN_00b06c3c(undefined8 param_1)

{
  return param_1;
}


// ==== entry=00b06c4a name=FUN_00b06c4a size=115 ====

undefined8 FUN_00b06c4a(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 local_28;
  undefined8 local_20;
  
  uVar1 = FUN_00b06ff1(param_3);
  uVar2 = FUN_00b06ff1(param_2);
  uVar3 = FUN_00b06ff1(param_1);
  local_20 = FUN_00b0700e(uVar3,uVar2,uVar1);
  FUN_00b059c4(&local_28,&local_20);
  return local_28;
}


// ==== entry=00b06cbe name=FUN_00b06cbe size=15 ====

void FUN_00b06cbe(void)

{
  return;
}


// ==== entry=00b06cce name=FUN_00b06cce size=68 ====

void FUN_00b06cce(undefined8 *param_1,undefined8 param_2,undefined8 param_3)

{
  undefined8 *puVar1;
  
  puVar1 = (undefined8 *)FUN_00b0551d(param_2);
  *param_1 = *puVar1;
  puVar1 = (undefined8 *)FUN_00b0551d(param_3);
  param_1[1] = *puVar1;
  return;
}


// ==== entry=00b06d12 name=FUN_00b06d12 size=34 ====

void FUN_00b06d12(undefined8 param_1)

{
  undefined8 uVar1;
  
  uVar1 = FUN_00b0705a(param_1);
  FUN_00b0703f(uVar1);
  return;
}


// ==== entry=00b06d34 name=FUN_00b06d34 size=43 ====

ulong * FUN_00b06d34(ulong *param_1,ulong *param_2)

{
  if (*param_1 < *param_2) {
    param_1 = param_2;
  }
  return param_1;
}


// ==== entry=00b06d5f name=FUN_00b06d5f size=42 ====

void FUN_00b06d5f(undefined8 param_1,undefined8 param_2)

{
  FUN_00b07068(param_1,param_2,0);
  return;
}


// ==== entry=00b06d89 name=FUN_00b06d89 size=37 ====

undefined8 FUN_00b06d89(undefined8 param_1)

{
  undefined8 local_10;
  
  FUN_00b070aa(&local_10,param_1);
  return local_10;
}


// ==== entry=00b06dae name=FUN_00b06dae size=49 ====

void FUN_00b06dae(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  FUN_00b070c4(param_1,param_2,param_3);
  return;
}


// ==== entry=00b06de0 name=FUN_00b06de0 size=31 ====

void FUN_00b06de0(undefined8 param_1)

{
  FUN_00b070f5(param_1,1);
  return;
}


// ==== entry=00b06e00 name=FUN_00b06e00 size=57 ====

void FUN_00b06e00(undefined8 *param_1,undefined8 param_2,undefined8 param_3)

{
  undefined8 uVar1;
  
  uVar1 = FUN_00b0711f(param_2);
  *param_1 = uVar1;
  param_1[1] = param_3;
  return;
}


// ==== entry=00b06e3a name=FUN_00b06e3a size=59 ====

void FUN_00b06e3a(undefined8 *param_1)

{
  if (param_1[1] != 0) {
    FUN_00b032f7(*param_1,param_1[1],1);
  }
  return;
}


// ==== entry=00b06e75 name=FUN_00b06e75 size=82 ====

void FUN_00b06e75(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 uVar1;
  undefined8 uVar2;
  
  uVar1 = FUN_00b0551d(param_4);
  uVar2 = FUN_00b0551d(param_3);
  FUN_00b0712e(param_1,param_2,uVar2,uVar1);
  return;
}


// ==== entry=00b06ec8 name=FUN_00b06ec8 size=30 ====

long FUN_00b06ec8(long param_1)

{
  *(undefined8 *)(param_1 + 8) = 0;
  return param_1;
}


// ==== entry=00b06ee6 name=FUN_00b06ee6 size=11 ====

void FUN_00b06ee6(void)

{
  return;
}


// ==== entry=00b06ef2 name=FUN_00b06ef2 size=11 ====

void FUN_00b06ef2(void)

{
  return;
}


// ==== entry=00b06efe name=FUN_00b06efe size=34 ====

undefined8 FUN_00b06efe(long *param_1,long *param_2)

{
  return CONCAT71((int7)((ulong)*param_2 >> 8),*param_1 != *param_2);
}


// ==== entry=00b06f20 name=FUN_00b06f20 size=31 ====

undefined8 * FUN_00b06f20(undefined8 *param_1)

{
  *param_1 = *(undefined8 *)*param_1;
  return param_1;
}


// ==== entry=00b06f40 name=FUN_00b06f40 size=34 ====

void FUN_00b06f40(undefined8 param_1)

{
  undefined8 uVar1;
  
  uVar1 = FUN_00b071aa(param_1);
  FUN_00b07190(uVar1);
  return;
}


// ==== entry=00b06f62 name=FUN_00b06f62 size=42 ====

void FUN_00b06f62(undefined8 param_1,undefined8 param_2)

{
  FUN_00b071b8(param_1,param_2,0);
  return;
}


// ==== entry=00b06f8c name=FUN_00b06f8c size=37 ====

undefined8 FUN_00b06f8c(undefined8 param_1)

{
  undefined8 local_10;
  
  FUN_00b071fa(&local_10,param_1);
  return local_10;
}


// ==== entry=00b06fb1 name=FUN_00b06fb1 size=49 ====

void FUN_00b06fb1(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  FUN_00b07214(param_1,param_2,param_3);
  return;
}


// ==== entry=00b06fe2 name=FUN_00b06fe2 size=15 ====

void FUN_00b06fe2(void)

{
  return;
}


// ==== entry=00b06ff1 name=FUN_00b06ff1 size=29 ====

undefined8 FUN_00b06ff1(undefined8 param_1)

{
  undefined8 *puVar1;
  undefined8 local_10;
  
  local_10 = param_1;
  puVar1 = (undefined8 *)FUN_00b05b5e(&local_10);
  return *puVar1;
}


// ==== entry=00b0700e name=FUN_00b0700e size=49 ====

void FUN_00b0700e(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  FUN_00b07253(param_1,param_2,param_3);
  return;
}


// ==== entry=00b0703f name=FUN_00b0703f size=26 ====

void FUN_00b0703f(undefined8 param_1)

{
  FUN_00b072b4(param_1);
  return;
}


// ==== entry=00b0705a name=FUN_00b0705a size=14 ====

undefined8 FUN_00b0705a(undefined8 param_1)

{
  return param_1;
}


// ==== entry=00b07068 name=FUN_00b07068 size=66 ====

void FUN_00b07068(undefined8 param_1,ulong param_2)

{
  ulong uVar1;
  
  uVar1 = FUN_00b072b4(param_1);
  if (uVar1 < param_2) {
                    /* WARNING: Subroutine does not return */
    std::__throw_bad_alloc();
  }
  operator_new(param_2 << 4);
  return;
}


// ==== entry=00b070aa name=FUN_00b070aa size=26 ====

void FUN_00b070aa(undefined8 *param_1,undefined8 param_2)

{
  *param_1 = param_2;
  return;
}


// ==== entry=00b070c4 name=FUN_00b070c4 size=49 ====

void FUN_00b070c4(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  FUN_00b072c8(param_1,param_2,param_3);
  return;
}


// ==== entry=00b070f5 name=FUN_00b070f5 size=42 ====

void FUN_00b070f5(undefined8 param_1,undefined8 param_2)

{
  FUN_00b07376(param_1,param_2,0);
  return;
}


// ==== entry=00b0711f name=FUN_00b0711f size=14 ====

undefined8 FUN_00b0711f(undefined8 param_1)

{
  return param_1;
}


// ==== entry=00b0712e name=FUN_00b0712e size=98 ====

void FUN_00b0712e(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  
  uVar1 = FUN_00b0551d(param_3);
  uVar2 = FUN_00b0551d(param_4);
  uVar3 = identity_forward(0x10,param_2);
  FUN_00b06cce(uVar3,uVar1,uVar2);
  return;
}


// ==== entry=00b07190 name=FUN_00b07190 size=26 ====

void FUN_00b07190(undefined8 param_1)

{
  FUN_00b073b8(param_1);
  return;
}


// ==== entry=00b071aa name=FUN_00b071aa size=14 ====

undefined8 FUN_00b071aa(undefined8 param_1)

{
  return param_1;
}


// ==== entry=00b071b8 name=FUN_00b071b8 size=66 ====

void FUN_00b071b8(undefined8 param_1,ulong param_2)

{
  ulong uVar1;
  
  uVar1 = FUN_00b073b8(param_1);
  if (uVar1 < param_2) {
                    /* WARNING: Subroutine does not return */
    std::__throw_bad_alloc();
  }
  operator_new(param_2 << 3);
  return;
}


// ==== entry=00b071fa name=FUN_00b071fa size=26 ====

void FUN_00b071fa(undefined8 *param_1,undefined8 param_2)

{
  *param_1 = param_2;
  return;
}


// ==== entry=00b07214 name=FUN_00b07214 size=49 ====

void FUN_00b07214(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  FUN_00b073cc(param_1,param_2,param_3);
  return;
}


// ==== entry=00b07245 name=FUN_00b07245 size=14 ====

undefined8 FUN_00b07245(undefined8 param_1)

{
  return param_1;
}


// ==== entry=00b07253 name=FUN_00b07253 size=96 ====

long FUN_00b07253(long param_1,long param_2,long param_3)

{
  undefined8 uVar1;
  undefined8 local_30;
  undefined8 local_20;
  undefined8 local_10;
  
  local_30 = param_3;
  local_20 = param_1;
  for (local_10 = param_2 - param_1 >> 4; 0 < local_10; local_10 = local_10 + -1) {
    uVar1 = FUN_00b07245(local_20);
    FUN_00b073fa(local_30,uVar1);
    local_20 = local_20 + 0x10;
    local_30 = local_30 + 0x10;
  }
  return local_30;
}


// ==== entry=00b072b4 name=FUN_00b072b4 size=20 ====

undefined8 FUN_00b072b4(void)

{
  return 0xfffffffffffffff;
}


// ==== entry=00b072c8 name=FUN_00b072c8 size=122 ====

long FUN_00b072c8(undefined8 param_1,undefined8 param_2,long param_3)

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
                    /* try { // try from 00b072f3 to 00b072f7 has its CatchHandler @ 00b0733b */
    cVar1 = FUN_00b07441(local_30,&local_38);
    if (cVar1 == '\0') break;
    uVar2 = FUN_00b07498(local_30);
    uVar3 = FUN_00b0748a(local_20);
    FUN_00b074b7(uVar3,uVar2);
    FUN_00b0746a(local_30);
    local_20 = local_20 + 0x10;
  }
  return local_20;
}


// ==== entry=00b07376 name=FUN_00b07376 size=66 ====

void FUN_00b07376(undefined8 param_1,ulong param_2)

{
  ulong uVar1;
  
  uVar1 = FUN_00b07502(param_1);
  if (uVar1 < param_2) {
                    /* WARNING: Subroutine does not return */
    std::__throw_bad_alloc();
  }
  operator_new(param_2 << 5);
  return;
}


// ==== entry=00b073b8 name=FUN_00b073b8 size=20 ====

undefined8 FUN_00b073b8(void)

{
  return 0x1fffffffffffffff;
}


// ==== entry=00b073cc name=FUN_00b073cc size=45 ====

void FUN_00b073cc(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  FUN_00b07516(param_1,param_2,param_3);
  return;
}


// ==== entry=00b073fa name=FUN_00b073fa size=71 ====

undefined8 * FUN_00b073fa(undefined8 *param_1,long param_2)

{
  undefined8 *puVar1;
  
  puVar1 = (undefined8 *)FUN_00b0551d(param_2);
  *param_1 = *puVar1;
  puVar1 = (undefined8 *)FUN_00b0551d(param_2 + 8);
  param_1[1] = *puVar1;
  return param_1;
}


// ==== entry=00b07441 name=FUN_00b07441 size=40 ====

uint FUN_00b07441(undefined8 param_1,undefined8 param_2)

{
  uint uVar1;
  
  uVar1 = FUN_00b07562(param_1,param_2);
  return uVar1 ^ 1;
}


// ==== entry=00b0746a name=FUN_00b0746a size=32 ====

long * FUN_00b0746a(long *param_1)

{
  *param_1 = *param_1 + 0x10;
  return param_1;
}


// ==== entry=00b0748a name=FUN_00b0748a size=14 ====

undefined8 FUN_00b0748a(undefined8 param_1)

{
  return param_1;
}


// ==== entry=00b07498 name=FUN_00b07498 size=17 ====

undefined8 FUN_00b07498(undefined8 *param_1)

{
  return *param_1;
}


// ==== entry=00b074a9 name=FUN_00b074a9 size=14 ====

undefined8 FUN_00b074a9(undefined8 param_1)

{
  return param_1;
}


// ==== entry=00b074b7 name=FUN_00b074b7 size=74 ====

void FUN_00b074b7(undefined8 param_1,undefined8 param_2)

{
  undefined8 uVar1;
  undefined8 *puVar2;
  undefined8 *puVar3;
  
  puVar2 = (undefined8 *)FUN_00b074a9(param_2);
  puVar3 = (undefined8 *)identity_forward(0x10,param_1);
  uVar1 = puVar2[1];
  *puVar3 = *puVar2;
  puVar3[1] = uVar1;
  return;
}


// ==== entry=00b07502 name=FUN_00b07502 size=20 ====

undefined8 FUN_00b07502(void)

{
  return 0x7ffffffffffffff;
}


// ==== entry=00b07516 name=FUN_00b07516 size=76 ====

void FUN_00b07516(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  undefined8 uVar1;
  undefined8 uVar2;
  
  uVar1 = FUN_00b0759b(param_2);
  uVar2 = FUN_00b0759b(param_1);
  FUN_00b075bd(uVar2,uVar1,param_3);
  return;
}


// ==== entry=00b07562 name=FUN_00b07562 size=57 ====

bool FUN_00b07562(undefined8 param_1,undefined8 param_2)

{
  long lVar1;
  long lVar2;
  
  lVar1 = FUN_00b07616(param_1);
  lVar2 = FUN_00b07616(param_2);
  return lVar1 == lVar2;
}


// ==== entry=00b0759b name=FUN_00b0759b size=34 ====

void FUN_00b0759b(undefined8 param_1)

{
  undefined8 uVar1;
  undefined8 local_10;
  
  local_10 = param_1;
  uVar1 = FUN_00b07628(&local_10);
  FUN_00b07639(uVar1);
  return;
}


// ==== entry=00b075bd name=FUN_00b075bd size=88 ====

void FUN_00b075bd(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  
  uVar1 = FUN_00b07647(param_3);
  uVar2 = FUN_00b07647(param_2);
  uVar3 = FUN_00b07647(param_1);
  FUN_00b07655(uVar3,uVar2,uVar1);
  return;
}


// ==== entry=00b07616 name=FUN_00b07616 size=17 ====

undefined8 FUN_00b07616(undefined8 *param_1)

{
  return *param_1;
}


// ==== entry=00b07628 name=FUN_00b07628 size=17 ====

undefined8 FUN_00b07628(undefined8 *param_1)

{
  return *param_1;
}


// ==== entry=00b07639 name=FUN_00b07639 size=14 ====

undefined8 FUN_00b07639(undefined8 param_1)

{
  return param_1;
}


// ==== entry=00b07647 name=FUN_00b07647 size=14 ====

undefined8 FUN_00b07647(undefined8 param_1)

{
  return param_1;
}


// ==== entry=00b07655 name=FUN_00b07655 size=49 ====

void FUN_00b07655(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  FUN_00b07686(param_1,param_2,param_3);
  return;
}


// ==== entry=00b07686 name=FUN_00b07686 size=95 ====

void * FUN_00b07686(void *param_1,long param_2,void *param_3)

{
  long lVar1;
  
  lVar1 = param_2 - (long)param_1 >> 3;
  if (lVar1 != 0) {
    memmove(param_3,param_1,lVar1 * 8);
  }
  return (void *)((long)param_3 + lVar1 * 8);
}


// ==== entry=00b076e5 name=FUN_00b076e5 size=22 ====

bool FUN_00b076e5(void)

{
  return PTR___pthread_key_create_011be910 != (undefined *)0x0;
}


// ==== entry=00b076fb name=FUN_00b076fb size=128 ====

undefined8 FUN_00b076fb(undefined8 param_1,undefined8 param_2)

{
  undefined4 uVar1;
  stringstream local_188 [376];
  
  uVar1 = FUN_00b004d1(0x10,8);
  std::stringstream::stringstream(local_188,param_2,uVar1);
                    /* try { // try from 00b07753 to 00b07757 has its CatchHandler @ 00b0776a */
  FUN_00b0789d(param_1,local_188);
  std::stringstream::~stringstream(local_188);
  return param_1;
}


// ==== entry=00b07798 name=FUN_00b07798 size=189 ====

undefined8 FUN_00b07798(undefined8 param_1,char *param_2)

{
  undefined4 uVar1;
  stringstream local_198 [368];
  string local_28 [15];
  allocator local_19 [9];
  
  uVar1 = FUN_00b004d1(0x10,8);
  std::allocator<char>::allocator();
                    /* try { // try from 00b077e4 to 00b077e8 has its CatchHandler @ 00b07855 */
  std::string::string(local_28,param_2,local_19);
                    /* try { // try from 00b077fc to 00b07800 has its CatchHandler @ 00b07844 */
  std::stringstream::stringstream(local_198,local_28,uVar1);
  std::string::~string(local_28);
  std::allocator<char>::~allocator((allocator<char> *)local_19);
                    /* try { // try from 00b0782d to 00b07831 has its CatchHandler @ 00b0786f */
  FUN_00b0789d(param_1,local_198);
  std::stringstream::~stringstream(local_198);
  return param_1;
}


// ==== entry=00b0789d name=FUN_00b0789d size=180 ====

undefined8 FUN_00b0789d(undefined8 param_1,undefined8 param_2)

{
  char cVar1;
  undefined1 local_98 [112];
  undefined1 local_28 [24];
  
  FUN_00b08cba(local_28,param_2);
                    /* try { // try from 00b078d7 to 00b078db has its CatchHandler @ 00b07954 */
  FUN_00b24194(local_98);
                    /* try { // try from 00b078ed to 00b07922 has its CatchHandler @ 00b07940 */
  cVar1 = FUN_00b08e1e(local_28,local_98);
  if (cVar1 == '\x01') {
    FUN_00b24352(param_1,local_98);
  }
  else {
    FUN_00b07fca(param_1);
  }
  FUN_00b242c4(local_98);
  FUN_00b08d0e(local_28);
  return param_1;
}


// ==== entry=00b0797f name=FUN_00b0797f size=194 ====

undefined8 FUN_00b0797f(undefined8 param_1,undefined8 param_2)

{
  char cVar1;
  undefined8 uVar2;
  ifstream local_228 [256];
  ios aiStack_128 [272];
  
  std::ifstream::ifstream(local_228,param_2,8);
                    /* try { // try from 00b079c9 to 00b079cd has its CatchHandler @ 00b07a3e */
  cVar1 = std::ios::operator!(aiStack_128);
  if (cVar1 != '\0') {
    uVar2 = __cxa_allocate_exception(0x28);
                    /* try { // try from 00b079ec to 00b079f0 has its CatchHandler @ 00b07a2e */
    FUN_00b07e4a(uVar2,param_2);
                    /* WARNING: Subroutine does not return */
                    /* try { // try from 00b079fe to 00b07a1b has its CatchHandler @ 00b07a3e */
    __cxa_throw(uVar2,&PTR_PTR_00d39ab0,FUN_00b00d40);
  }
  FUN_00b0789d(param_1,local_228);
  std::ifstream::~ifstream(local_228);
  return param_1;
}


// ==== entry=00b07a6e name=FUN_00b07a6e size=128 ====

undefined8 FUN_00b07a6e(undefined8 param_1,undefined8 param_2)

{
  undefined4 uVar1;
  stringstream local_188 [376];
  
  uVar1 = FUN_00b004d1(0x10,8);
  std::stringstream::stringstream(local_188,param_2,uVar1);
                    /* try { // try from 00b07ac6 to 00b07aca has its CatchHandler @ 00b07add */
  FUN_00b07c10(param_1,local_188);
  std::stringstream::~stringstream(local_188);
  return param_1;
}


// ==== entry=00b07b0b name=FUN_00b07b0b size=189 ====

undefined8 FUN_00b07b0b(undefined8 param_1,char *param_2)

{
  undefined4 uVar1;
  stringstream local_198 [368];
  string local_28 [15];
  allocator local_19 [9];
  
  uVar1 = FUN_00b004d1(0x10,8);
  std::allocator<char>::allocator();
                    /* try { // try from 00b07b57 to 00b07b5b has its CatchHandler @ 00b07bc8 */
  std::string::string(local_28,param_2,local_19);
                    /* try { // try from 00b07b6f to 00b07b73 has its CatchHandler @ 00b07bb7 */
  std::stringstream::stringstream(local_198,local_28,uVar1);
  std::string::~string(local_28);
  std::allocator<char>::~allocator((allocator<char> *)local_19);
                    /* try { // try from 00b07ba0 to 00b07ba4 has its CatchHandler @ 00b07be2 */
  FUN_00b07c10(param_1,local_198);
  std::stringstream::~stringstream(local_198);
  return param_1;
}


// ==== entry=00b07c10 name=FUN_00b07c10 size=232 ====

undefined8 FUN_00b07c10(undefined8 param_1,undefined8 param_2)

{
  char cVar1;
  undefined1 local_c8 [112];
  undefined1 local_58 [16];
  undefined1 local_48 [56];
  
  FUN_00b080e6(param_1);
                    /* try { // try from 00b07c4a to 00b07c4e has its CatchHandler @ 00b07d1d */
  FUN_00b08cba(local_58,param_2);
  do {
                    /* try { // try from 00b07c59 to 00b07c5d has its CatchHandler @ 00b07d0c */
    FUN_00b24194(local_c8);
                    /* try { // try from 00b07c6f to 00b07c97 has its CatchHandler @ 00b07cf8 */
    cVar1 = FUN_00b08e1e(local_58,local_c8);
    if (cVar1 == '\x01') {
      FUN_00b24352(local_48,local_c8);
                    /* try { // try from 00b07ca9 to 00b07cad has its CatchHandler @ 00b07ce7 */
      FUN_00b08110(param_1,local_48);
      refcounted_pair_release(local_48);
    }
    FUN_00b242c4(local_c8);
  } while (cVar1 == '\x01');
  FUN_00b08d0e(local_58);
  return param_1;
}


// ==== entry=00b07d4b name=FUN_00b07d4b size=194 ====

undefined8 FUN_00b07d4b(undefined8 param_1,undefined8 param_2)

{
  char cVar1;
  undefined8 uVar2;
  ifstream local_228 [256];
  ios aiStack_128 [272];
  
  std::ifstream::ifstream(local_228,param_2,8);
                    /* try { // try from 00b07d95 to 00b07d99 has its CatchHandler @ 00b07e0a */
  cVar1 = std::ios::operator!(aiStack_128);
  if (cVar1 != '\0') {
    uVar2 = __cxa_allocate_exception(0x28);
                    /* try { // try from 00b07db8 to 00b07dbc has its CatchHandler @ 00b07dfa */
    FUN_00b07e4a(uVar2,param_2);
                    /* WARNING: Subroutine does not return */
                    /* try { // try from 00b07dca to 00b07de7 has its CatchHandler @ 00b07e0a */
    __cxa_throw(uVar2,&PTR_PTR_00d39ab0,FUN_00b00d40);
  }
  FUN_00b07c10(param_1,local_228);
  std::ifstream::~ifstream(local_228);
  return param_1;
}


// ==== entry=00b07e3a name=FUN_00b07e3a size=15 ====

void FUN_00b07e3a(void)

{
  return;
}


// ==== entry=00b07e4a name=FUN_00b07e4a size=209 ====

void FUN_00b07e4a(undefined8 *param_1,undefined8 param_2)

{
  string local_40 [8];
  string local_38 [8];
  string local_30 [11];
  allocator local_25;
  undefined1 local_24 [12];
  
  std::allocator<char>::allocator();
                    /* try { // try from 00b07e7b to 00b07e7f has its CatchHandler @ 00b07f47 */
  std::string::string(local_30,"bad file",&local_25);
                    /* try { // try from 00b07e93 to 00b07e97 has its CatchHandler @ 00b07f36 */
  FUN_007c4f98(local_38,local_30,&DAT_00d3b373);
                    /* try { // try from 00b07eaa to 00b07eae has its CatchHandler @ 00b07f25 */
  FUN_00b08011(local_40,local_38,param_2);
  local_24 = FUN_00b004e3();
                    /* try { // try from 00b07ed1 to 00b07ed5 has its CatchHandler @ 00b07f14 */
  FUN_0052ca8a(param_1,local_24,local_40);
  std::string::~string(local_40);
  std::string::~string(local_38);
  std::string::~string(local_30);
  std::allocator<char>::~allocator((allocator<char> *)&local_25);
  *param_1 = &PTR_FUN_00d398b8;
  return;
}


// ==== entry=00b07f68 name=FUN_00b07f68 size=31 ====

void FUN_00b07f68(long param_1)

{
  FUN_00b01276(param_1 + 8);
  return;
}


// ==== entry=00b07f88 name=FUN_00b07f88 size=38 ====

void FUN_00b07f88(undefined8 param_1,undefined8 param_2)

{
  shared_ptr_copy_ref(param_1,param_2);
  return;
}


// ==== entry=00b07fae name=FUN_00b07fae size=27 ====

void FUN_00b07fae(undefined8 param_1)

{
  FUN_00b07f68(param_1);
  return;
}


// ==== entry=00b07fca name=FUN_00b07fca size=71 ====

void FUN_00b07fca(undefined1 *param_1)

{
  *param_1 = 1;
  std::string::string((string *)(param_1 + 8));
  FUN_00b08082(param_1 + 0x10,0);
  *(undefined8 *)(param_1 + 0x20) = 0;
  return;
}


// ==== entry=00b08011 name=FUN_00b08011 size=71 ====

string * FUN_00b08011(string *param_1,string *param_2,string *param_3)

{
  undefined8 uVar1;
  string *psVar2;
  
  uVar1 = std::string::append(param_2,param_3);
  psVar2 = (string *)FUN_00b08141(uVar1);
  std::string::string(param_1,psVar2);
  return param_1;
}


// ==== entry=00b08058 name=FUN_00b08058 size=14 ====

undefined8 FUN_00b08058(undefined8 param_1)

{
  return param_1;
}


// ==== entry=00b08066 name=FUN_00b08066 size=27 ====

void FUN_00b08066(undefined8 param_1)

{
  FUN_00b08150(param_1);
  return;
}


// ==== entry=00b08082 name=FUN_00b08082 size=31 ====

void FUN_00b08082(undefined8 param_1)

{
  FUN_00b08066(param_1);
  return;
}


// ==== entry=00b080a2 name=FUN_00b080a2 size=68 ====

void FUN_00b080a2(undefined8 *param_1)

{
  undefined8 uVar1;
  
  uVar1 = FUN_00b081f4(param_1);
  FUN_00b08202(*param_1,param_1[1],uVar1);
  FUN_00b08196(param_1);
  return;
}


// ==== entry=00b080e6 name=FUN_00b080e6 size=27 ====

void FUN_00b080e6(undefined8 param_1)

{
  FUN_00b0822c(param_1);
  return;
}


// ==== entry=00b08101 name=FUN_00b08101 size=14 ====

undefined8 FUN_00b08101(undefined8 param_1)

{
  return param_1;
}


// ==== entry=00b08110 name=FUN_00b08110 size=49 ====

void FUN_00b08110(undefined8 param_1,undefined8 param_2)

{
  undefined8 uVar1;
  
  uVar1 = FUN_00b08101(param_2);
  FUN_00b08248(param_1,uVar1);
  return;
}


// ==== entry=00b08141 name=FUN_00b08141 size=14 ====

undefined8 FUN_00b08141(undefined8 param_1)

{
  return param_1;
}


// ==== entry=00b08150 name=FUN_00b08150 size=42 ====

void FUN_00b08150(undefined8 *param_1)

{
  *param_1 = 0;
  FUN_00b082e2(param_1 + 1);
  return;
}


// ==== entry=00b0817a name=FUN_00b0817a size=27 ====

void FUN_00b0817a(undefined8 param_1)

{
  FUN_00b082f8(param_1);
  return;
}


// ==== entry=00b08196 name=FUN_00b08196 size=94 ====

void FUN_00b08196(long *param_1)

{
  FUN_00b08314(param_1,*param_1,(param_1[2] - *param_1 >> 3) * -0x3333333333333333);
  FUN_00b0817a(param_1);
  return;
}


// ==== entry=00b081f4 name=FUN_00b081f4 size=14 ====

undefined8 FUN_00b081f4(undefined8 param_1)

{
  return param_1;
}


// ==== entry=00b08202 name=FUN_00b08202 size=42 ====

void FUN_00b08202(undefined8 param_1,undefined8 param_2)

{
  FUN_00b08349(param_1,param_2);
  return;
}


// ==== entry=00b0822c name=FUN_00b0822c size=27 ====

void FUN_00b0822c(undefined8 param_1)

{
  FUN_00b08370(param_1);
  return;
}


// ==== entry=00b08248 name=FUN_00b08248 size=154 ====

void FUN_00b08248(long param_1,undefined8 param_2)

{
  undefined8 uVar1;
  undefined8 uVar2;
  
  if (*(long *)(param_1 + 8) == *(long *)(param_1 + 0x10)) {
    uVar1 = FUN_00b08058(param_2);
    uVar2 = FUN_00b083e8(param_1);
    FUN_00b08412(param_1,uVar2,uVar1);
  }
  else {
    uVar1 = FUN_00b08058(param_2);
    FUN_00b083ae(param_1,*(undefined8 *)(param_1 + 8),uVar1);
    *(long *)(param_1 + 8) = *(long *)(param_1 + 8) + 0x28;
  }
  return;
}


// ==== entry=00b082e2 name=FUN_00b082e2 size=22 ====

void FUN_00b082e2(undefined8 *param_1)

{
  *param_1 = 0;
  return;
}


// ==== entry=00b082f8 name=FUN_00b082f8 size=27 ====

void FUN_00b082f8(undefined8 param_1)

{
  FUN_00b0867e(param_1);
  return;
}


// ==== entry=00b08314 name=FUN_00b08314 size=53 ====

void FUN_00b08314(undefined8 param_1,long param_2,undefined8 param_3)

{
  if (param_2 != 0) {
    FUN_00b08689(param_1,param_2,param_3);
  }
  return;
}


// ==== entry=00b08349 name=FUN_00b08349 size=38 ====

void FUN_00b08349(undefined8 param_1,undefined8 param_2)

{
  FUN_00b086c5(param_1,param_2);
  return;
}


// ==== entry=00b08370 name=FUN_00b08370 size=62 ====

void FUN_00b08370(undefined8 *param_1)

{
  FUN_00b086fe(param_1);
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  return;
}


// ==== entry=00b083ae name=FUN_00b083ae size=57 ====

void FUN_00b083ae(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  undefined8 uVar1;
  
  uVar1 = FUN_00b08058(param_3);
  FUN_00b0871a(param_1,param_2,uVar1);
  return;
}


// ==== entry=00b083e8 name=FUN_00b083e8 size=41 ====

undefined8 FUN_00b083e8(long param_1)

{
  undefined8 local_10;
  
  FUN_00b08788(&local_10,param_1 + 8);
  return local_10;
}


// ==== entry=00b08412 name=FUN_00b08412 size=478 ====

void FUN_00b08412(long *param_1,undefined8 param_2,undefined8 param_3)

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
  local_28 = FUN_00b087a6(param_1,1,"vector::_M_realloc_insert");
  local_30 = *local_60;
  local_38 = local_60[1];
  local_50 = FUN_00b08870(local_60);
  local_40 = FUN_00b08895(&local_68,&local_50);
  local_48 = FUN_00b088e6(local_60,local_28);
  local_20 = local_48;
  uVar1 = FUN_00b08058(param_3);
                    /* try { // try from 00b084d7 to 00b0854e has its CatchHandler @ 00b085e9 */
  FUN_00b083ae(local_60,local_40 * 0x28 + local_48,uVar1);
  local_20 = 0;
  uVar1 = FUN_00b081f4(local_60);
  puVar2 = (undefined8 *)FUN_00b0891a(&local_68);
  local_20 = FUN_00b08928(local_30,*puVar2,local_48,uVar1);
  local_20 = local_20 + 0x28;
  uVar1 = FUN_00b081f4(local_60);
  puVar2 = (undefined8 *)FUN_00b0891a(&local_68);
  local_20 = FUN_00b08928(*puVar2,local_38,local_20,uVar1);
  uVar1 = FUN_00b081f4(local_60);
  FUN_00b08202(local_30,local_38,uVar1);
  FUN_00b08314(local_60,local_30,(local_60[2] - local_30 >> 3) * -0x3333333333333333);
  *local_60 = local_48;
  local_60[1] = local_20;
  local_60[2] = local_28 * 0x28 + local_48;
  return;
}


// ==== entry=00b0867e name=FUN_00b0867e size=11 ====

void FUN_00b0867e(void)

{
  return;
}


// ==== entry=00b08689 name=FUN_00b08689 size=46 ====

void FUN_00b08689(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  FUN_00b089a2(param_1,param_2,param_3);
  return;
}


// ==== entry=00b086b7 name=FUN_00b086b7 size=14 ====

undefined8 FUN_00b086b7(undefined8 param_1)

{
  return param_1;
}


// ==== entry=00b086c5 name=FUN_00b086c5 size=56 ====

void FUN_00b086c5(long param_1,long param_2)

{
  undefined8 uVar1;
  undefined8 local_10;
  
  for (local_10 = param_1; local_10 != param_2; local_10 = local_10 + 0x28) {
    uVar1 = FUN_00b086b7(local_10);
    FUN_00b089c5(uVar1);
  }
  return;
}


// ==== entry=00b086fe name=FUN_00b086fe size=27 ====

void FUN_00b086fe(undefined8 param_1)

{
  FUN_00b089e0(param_1);
  return;
}


// ==== entry=00b0871a name=FUN_00b0871a size=84 ====

void FUN_00b0871a(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  undefined8 uVar1;
  undefined8 uVar2;
  
  uVar1 = FUN_00b08058(param_3);
  uVar2 = identity_forward(0x28,param_2);
                    /* try { // try from 00b0875c to 00b08760 has its CatchHandler @ 00b08763 */
  FUN_007876f8(uVar2,uVar1);
  return;
}


// ==== entry=00b08788 name=FUN_00b08788 size=29 ====

void FUN_00b08788(undefined8 *param_1,undefined8 *param_2)

{
  *param_1 = *param_2;
  return;
}


// ==== entry=00b087a6 name=FUN_00b087a6 size=201 ====

ulong FUN_00b087a6(undefined8 param_1,ulong param_2,char *param_3)

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
  lVar1 = FUN_00b089ec(param_1);
  lVar2 = FUN_00b08a0e(local_30);
  if (local_38 <= (ulong)(lVar1 - lVar2)) {
    lVar1 = FUN_00b08a0e(local_30);
    local_28 = FUN_00b08a0e(local_30);
    plVar3 = (long *)FUN_00b06d34(&local_28,&local_38);
    local_20 = *plVar3 + lVar1;
    uVar4 = FUN_00b08a0e(local_30);
    if ((local_20 < uVar4) || (uVar4 = FUN_00b089ec(local_30), uVar4 < local_20)) {
      local_20 = FUN_00b089ec(local_30);
    }
    return local_20;
  }
                    /* WARNING: Subroutine does not return */
  std::__throw_length_error(param_3);
}


// ==== entry=00b08870 name=FUN_00b08870 size=37 ====

undefined8 FUN_00b08870(undefined8 param_1)

{
  undefined8 local_10;
  
  FUN_00b08788(&local_10,param_1);
  return local_10;
}


// ==== entry=00b08895 name=FUN_00b08895 size=81 ====

long FUN_00b08895(undefined8 param_1,undefined8 param_2)

{
  long lVar1;
  long *plVar2;
  
  plVar2 = (long *)FUN_00b0891a(param_1);
  lVar1 = *plVar2;
  plVar2 = (long *)FUN_00b0891a(param_2);
  return (lVar1 - *plVar2 >> 3) * -0x3333333333333333;
}


// ==== entry=00b088e6 name=FUN_00b088e6 size=51 ====

undefined8 FUN_00b088e6(undefined8 param_1,long param_2)

{
  undefined8 uVar1;
  
  if (param_2 == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = FUN_00b08a42(param_1,param_2);
  }
  return uVar1;
}


// ==== entry=00b0891a name=FUN_00b0891a size=14 ====

undefined8 FUN_00b0891a(undefined8 param_1)

{
  return param_1;
}


// ==== entry=00b08928 name=FUN_00b08928 size=84 ====

void FUN_00b08928(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 uVar1;
  undefined8 uVar2;
  
  uVar1 = FUN_00b08a6c(param_2);
  uVar2 = FUN_00b08a6c(param_1);
  FUN_00b08a7a(uVar2,uVar1,param_3,param_4);
  return;
}


// ==== entry=00b0897c name=FUN_00b0897c size=38 ====

void FUN_00b0897c(undefined8 param_1,undefined8 param_2)

{
  FUN_00b08aac(param_1,param_2);
  return;
}


// ==== entry=00b089a2 name=FUN_00b089a2 size=35 ====

void FUN_00b089a2(undefined8 param_1,void *param_2)

{
  operator_delete(param_2);
  return;
}


// ==== entry=00b089c5 name=FUN_00b089c5 size=27 ====

void FUN_00b089c5(undefined8 param_1)

{
  refcounted_pair_release(param_1);
  return;
}


// ==== entry=00b089e0 name=FUN_00b089e0 size=11 ====

void FUN_00b089e0(void)

{
  return;
}


// ==== entry=00b089ec name=FUN_00b089ec size=34 ====

void FUN_00b089ec(undefined8 param_1)

{
  undefined8 uVar1;
  
  uVar1 = FUN_00b08ae6(param_1);
  FUN_00b08acb(uVar1);
  return;
}


// ==== entry=00b08a0e name=FUN_00b08a0e size=52 ====

long FUN_00b08a0e(long *param_1)

{
  return (param_1[1] - *param_1 >> 3) * -0x3333333333333333;
}


// ==== entry=00b08a42 name=FUN_00b08a42 size=42 ====

void FUN_00b08a42(undefined8 param_1,undefined8 param_2)

{
  FUN_00b08af4(param_1,param_2,0);
  return;
}


// ==== entry=00b08a6c name=FUN_00b08a6c size=14 ====

undefined8 FUN_00b08a6c(undefined8 param_1)

{
  return param_1;
}


// ==== entry=00b08a7a name=FUN_00b08a7a size=49 ====

void FUN_00b08a7a(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  FUN_00b08b40(param_1,param_2,param_3);
  return;
}


// ==== entry=00b08aac name=FUN_00b08aac size=31 ====

void FUN_00b08aac(undefined8 param_1,undefined8 param_2)

{
  refcounted_pair_release(param_2);
  return;
}


// ==== entry=00b08acb name=FUN_00b08acb size=26 ====

void FUN_00b08acb(undefined8 param_1)

{
  FUN_00b08b72(param_1);
  return;
}


// ==== entry=00b08ae6 name=FUN_00b08ae6 size=14 ====

undefined8 FUN_00b08ae6(undefined8 param_1)

{
  return param_1;
}


// ==== entry=00b08af4 name=FUN_00b08af4 size=76 ====

void FUN_00b08af4(undefined8 param_1,ulong param_2)

{
  ulong uVar1;
  
  uVar1 = FUN_00b08b72(param_1);
  if (uVar1 < param_2) {
                    /* WARNING: Subroutine does not return */
    std::__throw_bad_alloc();
  }
  operator_new(param_2 * 0x28);
  return;
}


// ==== entry=00b08b40 name=FUN_00b08b40 size=49 ====

void FUN_00b08b40(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  FUN_00b08b86(param_1,param_2,param_3);
  return;
}


// ==== entry=00b08b72 name=FUN_00b08b72 size=20 ====

undefined8 FUN_00b08b72(void)

{
  return 0x666666666666666;
}


// ==== entry=00b08b86 name=FUN_00b08b86 size=94 ====

long FUN_00b08b86(long param_1,long param_2,long param_3)

{
  undefined8 uVar1;
  undefined8 local_30;
  undefined8 local_20;
  
  local_20 = param_3;
  for (local_30 = param_1; local_30 != param_2; local_30 = local_30 + 0x28) {
    uVar1 = FUN_00b086b7(local_20);
                    /* try { // try from 00b08bc6 to 00b08bca has its CatchHandler @ 00b08bdd */
    FUN_00b08c25(uVar1,local_30);
    local_20 = local_20 + 0x28;
  }
  return local_20;
}


// ==== entry=00b08c17 name=FUN_00b08c17 size=14 ====

undefined8 FUN_00b08c17(undefined8 param_1)

{
  return param_1;
}


// ==== entry=00b08c25 name=FUN_00b08c25 size=80 ====

void FUN_00b08c25(undefined8 param_1,undefined8 param_2)

{
  undefined8 uVar1;
  undefined8 uVar2;
  
  uVar1 = FUN_00b08c17(param_2);
  uVar2 = identity_forward(0x28,param_1);
                    /* try { // try from 00b08c63 to 00b08c67 has its CatchHandler @ 00b08c6a */
  FUN_007876f8(uVar2,uVar1);
  return;
}


// ==== entry=00b08c8e name=FUN_00b08c8e size=43 ====

void FUN_00b08c8e(long param_1)

{
  FUN_00b0a106(param_1);
  FUN_00b0a1bc(param_1 + 8);
  return;
}


// ==== entry=00b08cba name=FUN_00b08cba size=57 ====

void FUN_00b08cba(undefined8 param_1,undefined8 param_2)

{
  FUN_00b08c8e(param_1);
                    /* try { // try from 00b08ce5 to 00b08ce9 has its CatchHandler @ 00b08cec */
  FUN_00b08d80(param_1,param_2);
  return;
}


// ==== entry=00b08d0e name=FUN_00b08d0e size=43 ====

void FUN_00b08d0e(long param_1)

{
  FUN_00b0a1e2(param_1 + 8);
  FUN_00b0a12c(param_1);
  return;
}


// ==== entry=00b08d3a name=FUN_00b08d3a size=69 ====

undefined8 FUN_00b08d3a(undefined8 param_1)

{
  char cVar1;
  undefined8 uVar2;
  
  cVar1 = FUN_00b0a254(param_1);
  if (cVar1 != '\0') {
    uVar2 = FUN_00b0a23a(param_1);
    cVar1 = FUN_00b0c0ba(uVar2);
    if (cVar1 != '\x01') {
      return 1;
    }
  }
  return 0;
}


// ==== entry=00b08d80 name=FUN_00b08d80 size=113 ====

void FUN_00b08d80(long param_1,undefined8 param_2)

{
  void *pvVar1;
  
  pvVar1 = operator_new(0x1e0);
                    /* try { // try from 00b08dae to 00b08db2 has its CatchHandler @ 00b08de8 */
  FUN_00b0bf26(pvVar1,param_2);
  FUN_00b0a274(param_1,pvVar1);
  pvVar1 = operator_new(0x40);
                    /* try { // try from 00b08dd6 to 00b08dda has its CatchHandler @ 00b08dfe */
  FUN_00b23d22(pvVar1);
  FUN_00b0a2cc(param_1 + 8,pvVar1);
  return;
}


// ==== entry=00b08e1e name=FUN_00b08e1e size=188 ====

undefined8 FUN_00b08e1e(long param_1,undefined8 param_2)

{
  char cVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined1 local_78 [104];
  
  cVar1 = FUN_00b0a254(param_1);
  if (cVar1 == '\x01') {
    FUN_00b08ef4(param_1);
    uVar3 = FUN_00b0a23a(param_1);
    cVar1 = FUN_00b0c0ba(uVar3);
    if (cVar1 == '\0') {
      uVar3 = FUN_00b0a33e(param_1 + 8);
      uVar2 = FUN_00b0a324(param_1);
      FUN_00b1bd90(local_78,uVar2,uVar3);
                    /* try { // try from 00b08eb9 to 00b08ebd has its CatchHandler @ 00b08ed3 */
      FUN_00b1be9a(local_78,param_2);
      uVar3 = 1;
      FUN_00b1be6a(local_78);
    }
    else {
      uVar3 = 0;
    }
  }
  else {
    uVar3 = 0;
  }
  return uVar3;
}


// ==== entry=00b08ef4 name=FUN_00b08ef4 size=197 ====

void FUN_00b08ef4(long param_1)

{
  bool bVar1;
  char cVar2;
  undefined8 uVar3;
  long lVar4;
  void *pvVar5;
  
  bVar1 = false;
  while( true ) {
    uVar3 = FUN_00b0a23a(param_1);
    cVar2 = FUN_00b0c0ba(uVar3);
    if (cVar2 == '\x01') {
      return;
    }
    uVar3 = FUN_00b0a23a(param_1);
    lVar4 = yaml_scanner_peek(uVar3);
    if (*(int *)(lVar4 + 4) != 0) break;
    if (!bVar1) {
      pvVar5 = operator_new(0x40);
                    /* try { // try from 00b08f6c to 00b08f70 has its CatchHandler @ 00b08faf */
      FUN_00b23d22(pvVar5);
      FUN_00b0a2cc(param_1 + 8,pvVar5);
    }
    bVar1 = true;
    FUN_00b08fd0(param_1,lVar4);
    uVar3 = FUN_00b0a23a(param_1);
    yaml_scanner_pop(uVar3);
  }
  return;
}


// ==== entry=00b08fd0 name=FUN_00b08fd0 size=109 ====

void FUN_00b08fd0(undefined8 param_1,long param_2)

{
  char cVar1;
  
  cVar1 = FUN_00b0a358(param_2 + 0x18,&DAT_00d3bc6b);
  if (cVar1 == '\0') {
    cVar1 = FUN_00b0a358(param_2 + 0x18,&DAT_00d3bc70);
    if (cVar1 != '\0') {
      FUN_00b094ca(param_1,param_2);
    }
  }
  else {
    yaml_parseDirective(param_1,param_2);
  }
  return;
}


// ==== entry=00b0903e orig=FUN_00b0903e size=926 name=yaml_parseDirective ====

void yaml_parseDirective(long param_1,long param_2)

{
  bool bVar1;
  char cVar2;
  undefined4 uVar3;
  int iVar4;
  long lVar5;
  undefined8 uVar6;
  char *pcVar7;
  undefined8 uVar8;
  undefined1 *puVar9;
  stringstream local_1d8 [104];
  ios aiStack_170 [272];
  string local_60 [15];
  allocator local_51;
  string local_50 [15];
  allocator local_41;
  string local_40 [8];
  string local_38 [15];
  allocator local_29;
  string local_28 [15];
  allocator local_19;
  
  lVar5 = FUN_00b0a382(param_2 + 0x20);
  if (lVar5 != 1) {
    uVar6 = __cxa_allocate_exception(0x28);
    std::allocator<char>::allocator();
                    /* try { // try from 00b090a1 to 00b090a5 has its CatchHandler @ 00b093e1 */
    std::string::string(local_60,"YAML directives must have exactly one argument",&local_51);
                    /* try { // try from 00b090be to 00b090c2 has its CatchHandler @ 00b093d0 */
    FUN_00b09fc4(uVar6,param_2 + 8,local_60);
    std::string::~string(local_60);
    std::allocator<char>::~allocator((allocator<char> *)&local_51);
                    /* WARNING: Subroutine does not return */
    __cxa_throw(uVar6,&PTR_PTR_00d39ce8,FUN_00b009e6);
  }
  pcVar7 = (char *)FUN_00b0a3a6(param_1 + 8);
  if (*pcVar7 != '\x01') {
    uVar6 = __cxa_allocate_exception(0x28);
    std::allocator<char>::allocator();
                    /* try { // try from 00b09133 to 00b09137 has its CatchHandler @ 00b09414 */
    std::string::string(local_50,"repeated YAML directive",&local_41);
                    /* try { // try from 00b09150 to 00b09154 has its CatchHandler @ 00b09403 */
    FUN_00b09fc4(uVar6,param_2 + 8,local_50);
    std::string::~string(local_50);
    std::allocator<char>::~allocator((allocator<char> *)&local_41);
                    /* WARNING: Subroutine does not return */
    __cxa_throw(uVar6,&PTR_PTR_00d39ce8,FUN_00b009e6);
  }
  uVar3 = FUN_00b004d1(0x10,8);
  uVar6 = FUN_00b0a3c0(param_2 + 0x20,0);
  std::stringstream::stringstream(local_1d8,uVar6,uVar3);
  lVar5 = FUN_00b0a3a6(param_1 + 8);
                    /* try { // try from 00b091e3 to 00b09245 has its CatchHandler @ 00b094a1 */
  std::istream::operator>>((istream *)local_1d8,(int *)(lVar5 + 4));
  std::istream::get((istream *)local_1d8);
  lVar5 = FUN_00b0a3a6(param_1 + 8);
  std::istream::operator>>((istream *)local_1d8,(int *)(lVar5 + 8));
  cVar2 = std::ios::operator!(aiStack_170);
  if (cVar2 == '\0') {
    iVar4 = std::istream::peek((istream *)local_1d8);
    if (iVar4 == -1) {
      bVar1 = false;
      goto LAB_00b09257;
    }
  }
  bVar1 = true;
LAB_00b09257:
  if (bVar1) {
    uVar6 = __cxa_allocate_exception(0x28);
    uVar8 = FUN_00b0a3c0(param_2 + 0x20,0);
    std::allocator<char>::allocator();
                    /* try { // try from 00b092a3 to 00b092a7 has its CatchHandler @ 00b09458 */
    std::string::string(local_38,"bad YAML version: ",&local_29);
                    /* try { // try from 00b092b9 to 00b092bd has its CatchHandler @ 00b09447 */
    FUN_00b08011(local_40,local_38,uVar8);
                    /* try { // try from 00b092d6 to 00b092da has its CatchHandler @ 00b09436 */
    FUN_00b09fc4(uVar6,param_2 + 8,local_40);
    std::string::~string(local_40);
    std::string::~string(local_38);
    std::allocator<char>::~allocator((allocator<char> *)&local_29);
                    /* WARNING: Subroutine does not return */
                    /* try { // try from 00b0930c to 00b09310 has its CatchHandler @ 00b094a1 */
    __cxa_throw(uVar6,&PTR_PTR_00d39ce8,FUN_00b009e6);
  }
  lVar5 = FUN_00b0a3a6(param_1 + 8);
  if (1 < *(int *)(lVar5 + 4)) {
    uVar6 = __cxa_allocate_exception(0x28);
    std::allocator<char>::allocator();
                    /* try { // try from 00b0935a to 00b0935e has its CatchHandler @ 00b09485 */
    std::string::string(local_28,"YAML major version too large",&local_19);
                    /* try { // try from 00b09377 to 00b0937b has its CatchHandler @ 00b09474 */
    FUN_00b09fc4(uVar6,param_2 + 8,local_28);
    std::string::~string(local_28);
    std::allocator<char>::~allocator((allocator<char> *)&local_19);
                    /* WARNING: Subroutine does not return */
                    /* try { // try from 00b093a1 to 00b093a5 has its CatchHandler @ 00b094a1 */
    __cxa_throw(uVar6,&PTR_PTR_00d39ce8,FUN_00b009e6);
  }
  puVar9 = (undefined1 *)FUN_00b0a3a6(param_1 + 8);
  *puVar9 = 0;
  std::stringstream::~stringstream(local_1d8);
  return;
}


// ==== entry=00b094ca name=FUN_00b094ca size=482 ====

void FUN_00b094ca(long param_1,long param_2)

{
  char cVar1;
  long lVar2;
  undefined8 uVar3;
  string *this;
  string local_58 [15];
  allocator local_49;
  undefined8 local_48;
  undefined8 local_40;
  string local_38 [15];
  allocator local_29;
  string *local_28;
  undefined8 local_20;
  
  lVar2 = FUN_00b0a382(param_2 + 0x20);
  if (lVar2 != 2) {
    uVar3 = __cxa_allocate_exception(0x28);
    std::allocator<char>::allocator();
                    /* try { // try from 00b09521 to 00b09525 has its CatchHandler @ 00b096b4 */
    std::string::string(local_58,"TAG directives must have exactly two arguments",&local_49);
                    /* try { // try from 00b0953b to 00b0953f has its CatchHandler @ 00b096a3 */
    FUN_00b09fc4(uVar3,param_2 + 8,local_58);
    std::string::~string(local_58);
    std::allocator<char>::~allocator((allocator<char> *)&local_49);
                    /* WARNING: Subroutine does not return */
    __cxa_throw(uVar3,&PTR_PTR_00d39ce8,FUN_00b009e6);
  }
  local_20 = FUN_00b0a3c0(param_2 + 0x20,0);
  local_28 = (string *)FUN_00b0a3c0(param_2 + 0x20,1);
  lVar2 = FUN_00b0a3a6(param_1 + 8);
  local_48 = FUN_00b0a406(lVar2 + 0x10);
  lVar2 = FUN_00b0a3a6(param_1 + 8);
  local_40 = FUN_00b0a3e0(lVar2 + 0x10,local_20);
  cVar1 = FUN_00b0a420(&local_40,&local_48);
  if (cVar1 != '\0') {
    uVar3 = __cxa_allocate_exception(0x28);
    std::allocator<char>::allocator();
                    /* try { // try from 00b09623 to 00b09627 has its CatchHandler @ 00b096e7 */
    std::string::string(local_38,"repeated TAG directive",&local_29);
                    /* try { // try from 00b0963d to 00b09641 has its CatchHandler @ 00b096d6 */
    FUN_00b09fc4(uVar3,param_2 + 8,local_38);
    std::string::~string(local_38);
    std::allocator<char>::~allocator((allocator<char> *)&local_29);
                    /* WARNING: Subroutine does not return */
    __cxa_throw(uVar3,&PTR_PTR_00d39ce8,FUN_00b009e6);
  }
  lVar2 = FUN_00b0a3a6(param_1 + 8);
  this = (string *)FUN_00b0a4a8(lVar2 + 0x10,local_20);
  std::string::operator=(this,local_28);
  return;
}


// ==== entry=00b09712 name=FUN_00b09712 size=138 ====

void FUN_00b09712(undefined8 param_1,undefined8 param_2)

{
  char cVar1;
  undefined8 uVar2;
  ostream *poVar3;
  
  cVar1 = FUN_00b0a254(param_1);
  if (cVar1 == '\x01') {
    while( true ) {
      uVar2 = FUN_00b0a23a(param_1);
      cVar1 = FUN_00b0c0ba(uVar2);
      if (cVar1 == '\x01') break;
      uVar2 = FUN_00b0a23a(param_1);
      uVar2 = yaml_scanner_peek(uVar2);
      poVar3 = (ostream *)FUN_00b09e0a(param_2,uVar2);
      std::operator<<(poVar3,"\n");
      uVar2 = FUN_00b0a23a(param_1);
      yaml_scanner_pop(uVar2);
    }
  }
  return;
}


// ==== entry=00b0979c name=FUN_00b0979c size=48 ====

void FUN_00b0979c(void)

{
  string *this;
  
  this = (string *)&DAT_011c2b60;
  while (this != (string *)&DAT_011c2ac0) {
    this = this + -8;
    std::string::~string(this);
  }
  return;
}


// ==== entry=00b097cc orig=FUN_00b097cc size=1151 name=yaml_static_init_a ====

void yaml_static_init_a(int param_1,int param_2)

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
    std::ios_base::Init::Init((Init *)&DAT_011c2aa0);
    __cxa_atexit(std::ios_base::Init::~Init,&DAT_011c2aa0,&DAT_00c89008);
    std::allocator<char>::allocator();
                    /* try { // try from 00b0983a to 00b0983e has its CatchHandler @ 00b09c40 */
    std::string::string((string *)&DAT_011c2ac0,"DIRECTIVE",&local_3c);
    std::allocator<char>::~allocator((allocator<char> *)&local_3c);
    std::allocator<char>::allocator();
                    /* try { // try from 00b0986e to 00b09872 has its CatchHandler @ 00b09c54 */
    std::string::string((string *)&DAT_011c2ac8,"DOC_START",&local_3b);
    std::allocator<char>::~allocator((allocator<char> *)&local_3b);
    std::allocator<char>::allocator();
                    /* try { // try from 00b098a2 to 00b098a6 has its CatchHandler @ 00b09c68 */
    std::string::string((string *)&DAT_011c2ad0,"DOC_END",&local_3a);
    std::allocator<char>::~allocator((allocator<char> *)&local_3a);
    std::allocator<char>::allocator();
                    /* try { // try from 00b098d6 to 00b098da has its CatchHandler @ 00b09c7c */
    std::string::string((string *)&DAT_011c2ad8,"BLOCK_SEQ_START",&local_39);
    std::allocator<char>::~allocator((allocator<char> *)&local_39);
    std::allocator<char>::allocator();
                    /* try { // try from 00b0990a to 00b0990e has its CatchHandler @ 00b09c90 */
    std::string::string((string *)&DAT_011c2ae0,"BLOCK_MAP_START",&local_38);
    std::allocator<char>::~allocator((allocator<char> *)&local_38);
    std::allocator<char>::allocator();
                    /* try { // try from 00b0993e to 00b09942 has its CatchHandler @ 00b09ca4 */
    std::string::string((string *)&DAT_011c2ae8,"BLOCK_SEQ_END",&local_37);
    std::allocator<char>::~allocator((allocator<char> *)&local_37);
    std::allocator<char>::allocator();
                    /* try { // try from 00b09972 to 00b09976 has its CatchHandler @ 00b09cb8 */
    std::string::string((string *)&DAT_011c2af0,"BLOCK_MAP_END",&local_36);
    std::allocator<char>::~allocator((allocator<char> *)&local_36);
    std::allocator<char>::allocator();
                    /* try { // try from 00b099a6 to 00b099aa has its CatchHandler @ 00b09ccc */
    std::string::string((string *)&DAT_011c2af8,"BLOCK_ENTRY",&local_35);
    std::allocator<char>::~allocator((allocator<char> *)&local_35);
    std::allocator<char>::allocator();
                    /* try { // try from 00b099da to 00b099de has its CatchHandler @ 00b09ce0 */
    std::string::string((string *)&DAT_011c2b00,"FLOW_SEQ_START",&local_34);
    std::allocator<char>::~allocator((allocator<char> *)&local_34);
    std::allocator<char>::allocator();
                    /* try { // try from 00b09a0e to 00b09a12 has its CatchHandler @ 00b09cf4 */
    std::string::string((string *)&DAT_011c2b08,"FLOW_MAP_START",&local_33);
    std::allocator<char>::~allocator((allocator<char> *)&local_33);
    std::allocator<char>::allocator();
                    /* try { // try from 00b09a42 to 00b09a46 has its CatchHandler @ 00b09d08 */
    std::string::string((string *)&DAT_011c2b10,"FLOW_SEQ_END",&local_32);
    std::allocator<char>::~allocator((allocator<char> *)&local_32);
    std::allocator<char>::allocator();
                    /* try { // try from 00b09a76 to 00b09a7a has its CatchHandler @ 00b09d1c */
    std::string::string((string *)&DAT_011c2b18,"FLOW_MAP_END",&local_31);
    std::allocator<char>::~allocator((allocator<char> *)&local_31);
    std::allocator<char>::allocator();
                    /* try { // try from 00b09aaa to 00b09aae has its CatchHandler @ 00b09d30 */
    std::string::string((string *)&DAT_011c2b20,"FLOW_MAP_COMPACT",&local_30);
    std::allocator<char>::~allocator((allocator<char> *)&local_30);
    std::allocator<char>::allocator();
                    /* try { // try from 00b09ade to 00b09ae2 has its CatchHandler @ 00b09d41 */
    std::string::string((string *)&DAT_011c2b28,"FLOW_ENTRY",&local_2f);
    std::allocator<char>::~allocator((allocator<char> *)&local_2f);
    std::allocator<char>::allocator();
                    /* try { // try from 00b09b12 to 00b09b16 has its CatchHandler @ 00b09d52 */
    std::string::string((string *)&DAT_011c2b30,"KEY",&local_2e);
    std::allocator<char>::~allocator((allocator<char> *)&local_2e);
    std::allocator<char>::allocator();
                    /* try { // try from 00b09b46 to 00b09b4a has its CatchHandler @ 00b09d63 */
    std::string::string((string *)&DAT_011c2b38,"VALUE",&local_2d);
    std::allocator<char>::~allocator((allocator<char> *)&local_2d);
    std::allocator<char>::allocator();
                    /* try { // try from 00b09b7a to 00b09b7e has its CatchHandler @ 00b09d74 */
    std::string::string((string *)&DAT_011c2b40,"ANCHOR",&local_2c);
    std::allocator<char>::~allocator((allocator<char> *)&local_2c);
    std::allocator<char>::allocator();
                    /* try { // try from 00b09bae to 00b09bb2 has its CatchHandler @ 00b09d85 */
    std::string::string((string *)&DAT_011c2b48,"ALIAS",&local_2b);
    std::allocator<char>::~allocator((allocator<char> *)&local_2b);
    std::allocator<char>::allocator();
                    /* try { // try from 00b09be2 to 00b09be6 has its CatchHandler @ 00b09d96 */
    std::string::string((string *)&DAT_011c2b50,"TAG",&local_2a);
    std::allocator<char>::~allocator((allocator<char> *)&local_2a);
    std::allocator<char>::allocator();
                    /* try { // try from 00b09c16 to 00b09c1a has its CatchHandler @ 00b09da7 */
    std::string::string((string *)&DAT_011c2b58,"SCALAR",local_29);
    std::allocator<char>::~allocator((allocator<char> *)local_29);
    __cxa_atexit(FUN_00b0979c,0,&DAT_00c89008);
  }
  return;
}


// ==== entry=00b09df5 orig=FUN_00b09df5 size=21 name=_INIT_170 ====

void _INIT_170(void)

{
  yaml_static_init_a(1,0xffff);
  return;
}


// ==== entry=00b09e0a name=FUN_00b09e0a size=356 ====

ostream * FUN_00b09e0a(ostream *param_1,long param_2)

{
  char cVar1;
  ostream *poVar2;
  undefined8 local_58;
  undefined8 local_50;
  string local_48 [15];
  allocator local_39;
  string local_38 [15];
  allocator local_29;
  string *local_28;
  long local_20;
  
  poVar2 = std::operator<<(param_1,(string *)(&DAT_011c2ac0 + (long)*(int *)(param_2 + 4) * 8));
  std::allocator<char>::allocator();
                    /* try { // try from 00b09e5d to 00b09e61 has its CatchHandler @ 00b09f78 */
  std::string::string(local_48,": ",&local_39);
                    /* try { // try from 00b09e6c to 00b09e86 has its CatchHandler @ 00b09f67 */
  poVar2 = std::operator<<(poVar2,local_48);
  std::operator<<(poVar2,(string *)(param_2 + 0x18));
  std::string::~string(local_48);
  std::allocator<char>::~allocator((allocator<char> *)&local_39);
  local_20 = param_2 + 0x20;
  local_50 = FUN_00b09ffe(local_20);
  local_58 = FUN_00b0a02e(local_20);
  while( true ) {
    cVar1 = FUN_00b0a05f(&local_50,&local_58);
    if (cVar1 == '\0') break;
    local_28 = (string *)FUN_00b0a0bc(&local_50);
    std::allocator<char>::allocator();
                    /* try { // try from 00b09f0e to 00b09f12 has its CatchHandler @ 00b09fa3 */
    std::string::string(local_38," ",&local_29);
                    /* try { // try from 00b09f21 to 00b09f37 has its CatchHandler @ 00b09f92 */
    poVar2 = std::operator<<(param_1,local_38);
    std::operator<<(poVar2,local_28);
    std::string::~string(local_38);
    std::allocator<char>::~allocator((allocator<char> *)&local_29);
    FUN_00b0a09c(&local_50);
  }
  return param_1;
}


// ==== entry=00b09fc4 name=FUN_00b09fc4 size=58 ====

void FUN_00b09fc4(undefined8 *param_1,undefined8 param_2,undefined8 param_3)

{
  FUN_0052ca8a(param_1,param_2,param_3);
  *param_1 = &PTR_FUN_00d39a70;
  return;
}


// ==== entry=00b09ffe name=FUN_00b09ffe size=48 ====

undefined8 FUN_00b09ffe(undefined8 *param_1)

{
  undefined8 local_18;
  undefined8 local_10;
  
  local_10 = *param_1;
  FUN_00b0a5a0(&local_18,&local_10);
  return local_18;
}


// ==== entry=00b0a02e name=FUN_00b0a02e size=49 ====

undefined8 FUN_00b0a02e(long param_1)

{
  undefined8 local_18;
  undefined8 local_10;
  
  local_10 = *(undefined8 *)(param_1 + 8);
  FUN_00b0a5a0(&local_18,&local_10);
  return local_18;
}


// ==== entry=00b0a05f name=FUN_00b0a05f size=60 ====

undefined8 FUN_00b0a05f(undefined8 param_1,undefined8 param_2)

{
  long lVar1;
  long *plVar2;
  
  plVar2 = (long *)FUN_00b0a5be(param_1);
  lVar1 = *plVar2;
  plVar2 = (long *)FUN_00b0a5be(param_2);
  return CONCAT71((int7)((ulong)*plVar2 >> 8),lVar1 != *plVar2);
}


// ==== entry=00b0a09c name=FUN_00b0a09c size=32 ====

long * FUN_00b0a09c(long *param_1)

{
  *param_1 = *param_1 + 8;
  return param_1;
}


// ==== entry=00b0a0bc name=FUN_00b0a0bc size=17 ====

undefined8 FUN_00b0a0bc(undefined8 *param_1)

{
  return *param_1;
}


// ==== entry=00b0a0ce name=FUN_00b0a0ce size=27 ====

void FUN_00b0a0ce(undefined8 param_1)

{
  FUN_00b0a5cc(param_1);
  return;
}


// ==== entry=00b0a0ea name=FUN_00b0a0ea size=27 ====

void FUN_00b0a0ea(undefined8 param_1)

{
  FUN_00b0a0ce(param_1);
  return;
}


// ==== entry=00b0a106 name=FUN_00b0a106 size=38 ====

void FUN_00b0a106(undefined8 *param_1)

{
  *param_1 = 0;
  FUN_00b0a0ea(param_1);
  return;
}


// ==== entry=00b0a12c name=FUN_00b0a12c size=87 ====

void FUN_00b0a12c(undefined8 param_1)

{
  long *plVar1;
  undefined8 uVar2;
  
  plVar1 = (long *)FUN_00b0a5f4(param_1);
  if (*plVar1 != 0) {
    uVar2 = FUN_00b0a60e(param_1);
    FUN_00b0a628(uVar2,*plVar1);
  }
  *plVar1 = 0;
  return;
}


// ==== entry=00b0a184 name=FUN_00b0a184 size=27 ====

void FUN_00b0a184(undefined8 param_1)

{
  FUN_00b0a65a(param_1);
  return;
}


// ==== entry=00b0a1a0 name=FUN_00b0a1a0 size=27 ====

void FUN_00b0a1a0(undefined8 param_1)

{
  FUN_00b0a184(param_1);
  return;
}


// ==== entry=00b0a1bc name=FUN_00b0a1bc size=38 ====

void FUN_00b0a1bc(undefined8 *param_1)

{
  *param_1 = 0;
  FUN_00b0a1a0(param_1);
  return;
}


// ==== entry=00b0a1e2 name=FUN_00b0a1e2 size=87 ====

void FUN_00b0a1e2(undefined8 param_1)

{
  long *plVar1;
  undefined8 uVar2;
  
  plVar1 = (long *)FUN_00b0a682(param_1);
  if (*plVar1 != 0) {
    uVar2 = FUN_00b0a69c(param_1);
    FUN_00b0a6f2(uVar2,*plVar1);
  }
  *plVar1 = 0;
  return;
}


// ==== entry=00b0a23a name=FUN_00b0a23a size=26 ====

void FUN_00b0a23a(undefined8 param_1)

{
  FUN_00b0a724(param_1);
  return;
}


// ==== entry=00b0a254 name=FUN_00b0a254 size=32 ====

bool FUN_00b0a254(undefined8 param_1)

{
  long lVar1;
  
  lVar1 = FUN_00b0a724(param_1);
  return lVar1 != 0;
}


// ==== entry=00b0a274 name=FUN_00b0a274 size=88 ====

void FUN_00b0a274(undefined8 param_1,long param_2)

{
  undefined8 uVar1;
  long local_18;
  undefined8 local_10;
  
  local_18 = param_2;
  local_10 = param_1;
  uVar1 = FUN_00b0a5f4(param_1);
  FUN_00b0a74c(uVar1,&local_18);
  if (local_18 != 0) {
    uVar1 = FUN_00b0a60e(local_10);
    FUN_00b0a628(uVar1,local_18);
  }
  return;
}


// ==== entry=00b0a2cc name=FUN_00b0a2cc size=88 ====

void FUN_00b0a2cc(undefined8 param_1,long param_2)

{
  undefined8 uVar1;
  long local_18;
  undefined8 local_10;
  
  local_18 = param_2;
  local_10 = param_1;
  uVar1 = FUN_00b0a682(param_1);
  FUN_00b0a7ac(uVar1,&local_18);
  if (local_18 != 0) {
    uVar1 = FUN_00b0a69c(local_10);
    FUN_00b0a6f2(uVar1,local_18);
  }
  return;
}


// ==== entry=00b0a324 name=FUN_00b0a324 size=26 ====

void FUN_00b0a324(undefined8 param_1)

{
  FUN_00b0a724(param_1);
  return;
}


// ==== entry=00b0a33e name=FUN_00b0a33e size=26 ====

void FUN_00b0a33e(undefined8 param_1)

{
  FUN_00b0a7fe(param_1);
  return;
}


// ==== entry=00b0a358 name=FUN_00b0a358 size=42 ====

bool FUN_00b0a358(string *param_1,char *param_2)

{
  int iVar1;
  
  iVar1 = std::string::compare(param_1,param_2);
  return iVar1 == 0;
}


// ==== entry=00b0a382 name=FUN_00b0a382 size=35 ====

long FUN_00b0a382(long *param_1)

{
  return param_1[1] - *param_1 >> 3;
}


// ==== entry=00b0a3a6 name=FUN_00b0a3a6 size=26 ====

void FUN_00b0a3a6(undefined8 param_1)

{
  FUN_00b0a7fe(param_1);
  return;
}


// ==== entry=00b0a3c0 name=FUN_00b0a3c0 size=32 ====

long FUN_00b0a3c0(long *param_1,long param_2)

{
  return *param_1 + param_2 * 8;
}


// ==== entry=00b0a3e0 name=FUN_00b0a3e0 size=37 ====

void FUN_00b0a3e0(undefined8 param_1,undefined8 param_2)

{
  FUN_00b0a818(param_1,param_2);
  return;
}


// ==== entry=00b0a406 name=FUN_00b0a406 size=26 ====

void FUN_00b0a406(undefined8 param_1)

{
  FUN_00b0a8c8(param_1);
  return;
}


// ==== entry=00b0a420 name=FUN_00b0a420 size=34 ====

undefined8 FUN_00b0a420(long *param_1,long *param_2)

{
  return CONCAT71((int7)((ulong)*param_2 >> 8),*param_1 != *param_2);
}


// ==== entry=00b0a442 name=FUN_00b0a442 size=38 ====

void FUN_00b0a442(undefined8 param_1,undefined8 param_2)

{
  FUN_00b0a468(param_1,param_2);
  return;
}


// ==== entry=00b0a468 name=FUN_00b0a468 size=38 ====

void FUN_00b0a468(undefined8 param_1,undefined8 param_2)

{
  FUN_00b0a48e(param_1,param_2);
  return;
}


// ==== entry=00b0a48e name=FUN_00b0a48e size=26 ====

void FUN_00b0a48e(undefined8 *param_1,undefined8 param_2)

{
  *param_1 = param_2;
  return;
}


// ==== entry=00b0a4a8 name=FUN_00b0a4a8 size=248 ====

long FUN_00b0a4a8(undefined8 param_1,undefined8 param_2)

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
  
  local_40 = FUN_00b0a8f2(param_1,param_2);
  local_38 = FUN_00b0a406(param_1);
  cVar2 = FUN_00b0a918(&local_40,&local_38);
  if (cVar2 == '\0') {
    FUN_00b0a93a(param_1);
    uVar3 = FUN_00b0a95c(&local_40);
    cVar2 = FUN_00b0a97a(&local_2a,param_2,uVar3);
    if (cVar2 == '\0') {
      bVar1 = false;
      goto LAB_00b0a535;
    }
  }
  bVar1 = true;
LAB_00b0a535:
  if (bVar1) {
    FUN_00b0a442(local_28,param_2);
    FUN_00b0a9a4(local_20,&local_40);
    local_40 = FUN_00b0a9ec(param_1,local_20[0],&DAT_00d3b390,local_28,&local_29);
  }
  lVar4 = FUN_00b0a95c(&local_40);
  return lVar4 + 8;
}


// ==== entry=00b0a5a0 name=FUN_00b0a5a0 size=29 ====

void FUN_00b0a5a0(undefined8 *param_1,undefined8 *param_2)

{
  *param_1 = *param_2;
  return;
}


// ==== entry=00b0a5be name=FUN_00b0a5be size=14 ====

undefined8 FUN_00b0a5be(undefined8 param_1)

{
  return param_1;
}


// ==== entry=00b0a5cc name=FUN_00b0a5cc size=39 ====

void FUN_00b0a5cc(undefined8 param_1)

{
  FUN_00b0ab04(param_1);
  FUN_00b0ab20(param_1);
  return;
}


// ==== entry=00b0a5f4 name=FUN_00b0a5f4 size=26 ====

void FUN_00b0a5f4(undefined8 param_1)

{
  FUN_00b0ab36(param_1);
  return;
}


// ==== entry=00b0a60e name=FUN_00b0a60e size=26 ====

void FUN_00b0a60e(undefined8 param_1)

{
  FUN_00b0ab50(param_1);
  return;
}


// ==== entry=00b0a628 name=FUN_00b0a628 size=50 ====

void FUN_00b0a628(undefined8 param_1,void *param_2)

{
  if (param_2 != (void *)0x0) {
    FUN_00b0c046(param_2);
    operator_delete(param_2);
  }
  return;
}


// ==== entry=00b0a65a name=FUN_00b0a65a size=39 ====

void FUN_00b0a65a(undefined8 param_1)

{
  FUN_00b0ab6a(param_1);
  FUN_00b0ab86(param_1);
  return;
}


// ==== entry=00b0a682 name=FUN_00b0a682 size=26 ====

void FUN_00b0a682(undefined8 param_1)

{
  FUN_00b0ab9c(param_1);
  return;
}


// ==== entry=00b0a69c name=FUN_00b0a69c size=26 ====

void FUN_00b0a69c(undefined8 param_1)

{
  FUN_00b0abb6(param_1);
  return;
}


// ==== entry=00b0a6b6 name=FUN_00b0a6b6 size=27 ====

void FUN_00b0a6b6(undefined8 param_1)

{
  FUN_00b0abec(param_1);
  return;
}


// ==== entry=00b0a6d2 name=FUN_00b0a6d2 size=31 ====

void FUN_00b0a6d2(long param_1)

{
  FUN_00b0a6b6(param_1 + 0x10);
  return;
}


// ==== entry=00b0a6f2 name=FUN_00b0a6f2 size=50 ====

void FUN_00b0a6f2(undefined8 param_1,void *param_2)

{
  if (param_2 != (void *)0x0) {
    FUN_00b0a6d2(param_2);
    operator_delete(param_2);
  }
  return;
}


// ==== entry=00b0a724 name=FUN_00b0a724 size=26 ====

void FUN_00b0a724(undefined8 param_1)

{
  FUN_00b0ac26(param_1);
  return;
}


// ==== entry=00b0a73e name=FUN_00b0a73e size=14 ====

undefined8 FUN_00b0a73e(undefined8 param_1)

{
  return param_1;
}


// ==== entry=00b0a74c name=FUN_00b0a74c size=82 ====

void FUN_00b0a74c(undefined8 *param_1,undefined8 *param_2)

{
  undefined8 *puVar1;
  undefined8 local_10;
  
  puVar1 = (undefined8 *)FUN_00b0a73e(param_1);
  local_10 = *puVar1;
  puVar1 = (undefined8 *)FUN_00b0a73e(param_2);
  *param_1 = *puVar1;
  puVar1 = (undefined8 *)FUN_00b0a73e(&local_10);
  *param_2 = *puVar1;
  return;
}


// ==== entry=00b0a79e name=FUN_00b0a79e size=14 ====

undefined8 FUN_00b0a79e(undefined8 param_1)

{
  return param_1;
}


// ==== entry=00b0a7ac name=FUN_00b0a7ac size=82 ====

void FUN_00b0a7ac(undefined8 *param_1,undefined8 *param_2)

{
  undefined8 *puVar1;
  undefined8 local_10;
  
  puVar1 = (undefined8 *)FUN_00b0a79e(param_1);
  local_10 = *puVar1;
  puVar1 = (undefined8 *)FUN_00b0a79e(param_2);
  *param_1 = *puVar1;
  puVar1 = (undefined8 *)FUN_00b0a79e(&local_10);
  *param_2 = *puVar1;
  return;
}


// ==== entry=00b0a7fe name=FUN_00b0a7fe size=26 ====

void FUN_00b0a7fe(undefined8 param_1)

{
  FUN_00b0ac44(param_1);
  return;
}


// ==== entry=00b0a818 name=FUN_00b0a818 size=175 ====

undefined8 FUN_00b0a818(undefined8 param_1,undefined8 param_2)

{
  char cVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 local_28;
  undefined8 local_20 [2];
  
  uVar2 = FUN_00b0ac74(param_1);
  uVar3 = FUN_00b0ac62(param_1);
  local_28 = FUN_00b0ac86(param_1,uVar3,uVar2,param_2);
  local_20[0] = FUN_00b0a8c8(param_1);
  cVar1 = FUN_00b0a918(&local_28,local_20);
  if (cVar1 == '\0') {
    uVar2 = FUN_00b0ad1c(local_28);
    cVar1 = FUN_00b0a97a(param_1,param_2,uVar2);
    if (cVar1 == '\0') {
      return local_28;
    }
  }
  uVar2 = FUN_00b0a8c8(param_1);
  return uVar2;
}


// ==== entry=00b0a8c8 name=FUN_00b0a8c8 size=41 ====

undefined8 FUN_00b0a8c8(long param_1)

{
  undefined8 local_10;
  
  FUN_00b0ad4a(&local_10,param_1 + 8);
  return local_10;
}


// ==== entry=00b0a8f2 name=FUN_00b0a8f2 size=37 ====

void FUN_00b0a8f2(undefined8 param_1,undefined8 param_2)

{
  FUN_00b0ad64(param_1,param_2);
  return;
}


// ==== entry=00b0a918 name=FUN_00b0a918 size=34 ====

undefined8 FUN_00b0a918(long *param_1,long *param_2)

{
  return CONCAT71((int7)((ulong)*param_2 >> 8),*param_1 == *param_2);
}


// ==== entry=00b0a93a name=FUN_00b0a93a size=34 ====

undefined4 FUN_00b0a93a(undefined8 param_1)

{
  undefined4 unaff_EBX;
  
  FUN_00b0adb0(param_1);
  return unaff_EBX;
}


// ==== entry=00b0a95c name=FUN_00b0a95c size=29 ====

void FUN_00b0a95c(undefined8 *param_1)

{
  FUN_00b0adba(*param_1);
  return;
}


// ==== entry=00b0a97a name=FUN_00b0a97a size=41 ====

void FUN_00b0a97a(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  FUN_00b0add8(param_2,param_3);
  return;
}


// ==== entry=00b0a9a4 name=FUN_00b0a9a4 size=29 ====

void FUN_00b0a9a4(undefined8 *param_1,undefined8 *param_2)

{
  *param_1 = *param_2;
  return;
}


// ==== entry=00b0a9c1 name=FUN_00b0a9c1 size=14 ====

undefined8 FUN_00b0a9c1(undefined8 param_1)

{
  return param_1;
}


// ==== entry=00b0a9cf name=FUN_00b0a9cf size=14 ====

undefined8 FUN_00b0a9cf(undefined8 param_1)

{
  return param_1;
}


// ==== entry=00b0a9dd name=FUN_00b0a9dd size=14 ====

undefined8 FUN_00b0a9dd(undefined8 param_1)

{
  return param_1;
}


// ==== entry=00b0a9ec name=FUN_00b0a9ec size=228 ====

undefined8
FUN_00b0a9ec(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
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
  local_20 = FUN_00b0ae00(param_1,uVar3,uVar2,uVar1);
                    /* try { // try from 00b0aa55 to 00b0aa98 has its CatchHandler @ 00b0aac7 */
  uVar1 = FUN_00b0b2ce(local_20);
  auVar4 = FUN_00b0ae7c(param_1,param_2,uVar1);
  if (auVar4._8_8_ == 0) {
    FUN_00b0b3c0(param_1,local_20);
    FUN_00b0ad4a(&local_28,auVar4._0_8_);
  }
  else {
    local_28 = FUN_00b0b2fc(param_1,auVar4._0_8_,auVar4._8_8_,local_20);
  }
  return local_28;
}


// ==== entry=00b0ab04 name=FUN_00b0ab04 size=27 ====

void FUN_00b0ab04(undefined8 param_1)

{
  FUN_00b0b3fa(param_1);
  return;
}


// ==== entry=00b0ab20 name=FUN_00b0ab20 size=22 ====

void FUN_00b0ab20(undefined8 *param_1)

{
  *param_1 = 0;
  return;
}


// ==== entry=00b0ab36 name=FUN_00b0ab36 size=26 ====

void FUN_00b0ab36(undefined8 param_1)

{
  FUN_00b0b405(param_1);
  return;
}


// ==== entry=00b0ab50 name=FUN_00b0ab50 size=26 ====

void FUN_00b0ab50(undefined8 param_1)

{
  FUN_00b0b41f(param_1);
  return;
}


// ==== entry=00b0ab6a name=FUN_00b0ab6a size=27 ====

void FUN_00b0ab6a(undefined8 param_1)

{
  FUN_00b0b43a(param_1);
  return;
}


// ==== entry=00b0ab86 name=FUN_00b0ab86 size=22 ====

void FUN_00b0ab86(undefined8 *param_1)

{
  *param_1 = 0;
  return;
}


// ==== entry=00b0ab9c name=FUN_00b0ab9c size=26 ====

void FUN_00b0ab9c(undefined8 param_1)

{
  FUN_00b0b445(param_1);
  return;
}


// ==== entry=00b0abb6 name=FUN_00b0abb6 size=26 ====

void FUN_00b0abb6(undefined8 param_1)

{
  FUN_00b0b45f(param_1);
  return;
}


// ==== entry=00b0abd0 name=FUN_00b0abd0 size=27 ====

void FUN_00b0abd0(undefined8 param_1)

{
  FUN_00b0b47a(param_1);
  return;
}


// ==== entry=00b0abec name=FUN_00b0abec size=57 ====

void FUN_00b0abec(undefined8 param_1)

{
  undefined8 uVar1;
  
  uVar1 = FUN_00b0ac62(param_1);
  FUN_00b0b496(param_1,uVar1);
  FUN_00b0abd0(param_1);
  return;
}


// ==== entry=00b0ac26 name=FUN_00b0ac26 size=29 ====

undefined8 FUN_00b0ac26(undefined8 param_1)

{
  undefined8 *puVar1;
  
  puVar1 = (undefined8 *)FUN_00b0b4fb(param_1);
  return *puVar1;
}


// ==== entry=00b0ac44 name=FUN_00b0ac44 size=29 ====

undefined8 FUN_00b0ac44(undefined8 param_1)

{
  undefined8 *puVar1;
  
  puVar1 = (undefined8 *)FUN_00b0b515(param_1);
  return *puVar1;
}


// ==== entry=00b0ac62 name=FUN_00b0ac62 size=18 ====

undefined8 FUN_00b0ac62(long param_1)

{
  return *(undefined8 *)(param_1 + 0x10);
}


// ==== entry=00b0ac74 name=FUN_00b0ac74 size=18 ====

long FUN_00b0ac74(long param_1)

{
  return param_1 + 8;
}


// ==== entry=00b0ac86 name=FUN_00b0ac86 size=150 ====

undefined8 FUN_00b0ac86(undefined8 param_1,long param_2,long param_3,undefined8 param_4)

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
      local_38 = FUN_00b0b541(local_38);
    }
    else {
      local_40 = local_38;
      local_38 = FUN_00b0b52f(local_38);
    }
  }
  FUN_00b0ad4a(local_20,local_40);
  return local_20[0];
}


// ==== entry=00b0ad1c name=FUN_00b0ad1c size=45 ====

void FUN_00b0ad1c(undefined8 param_1)

{
  undefined8 uVar1;
  undefined1 local_9;
  
  uVar1 = FUN_00b0b553(param_1);
  FUN_00b0b56e(&local_9,uVar1);
  return;
}


// ==== entry=00b0ad4a name=FUN_00b0ad4a size=26 ====

void FUN_00b0ad4a(undefined8 *param_1,undefined8 param_2)

{
  *param_1 = param_2;
  return;
}


// ==== entry=00b0ad64 name=FUN_00b0ad64 size=76 ====

void FUN_00b0ad64(undefined8 param_1,undefined8 param_2)

{
  undefined8 uVar1;
  undefined8 uVar2;
  
  uVar1 = FUN_00b0ac74(param_1);
  uVar2 = FUN_00b0ac62(param_1);
  FUN_00b0ac86(param_1,uVar2,uVar1,param_2);
  return;
}


// ==== entry=00b0adb0 name=FUN_00b0adb0 size=10 ====

void FUN_00b0adb0(void)

{
  return;
}


// ==== entry=00b0adba name=FUN_00b0adba size=30 ====

void FUN_00b0adba(long param_1)

{
  FUN_00b0b580(param_1 + 0x20);
  return;
}


// ==== entry=00b0add8 name=FUN_00b0add8 size=40 ====

uint FUN_00b0add8(string *param_1,string *param_2)

{
  uint uVar1;
  
  uVar1 = std::string::compare(param_1,param_2);
  return uVar1 >> 0x1f;
}


// ==== entry=00b0ae00 name=FUN_00b0ae00 size=123 ====

undefined8 FUN_00b0ae00(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  
  uVar1 = FUN_00b0b59a(param_1);
  uVar2 = FUN_00b0a9dd(param_4);
  uVar3 = FUN_00b0a9cf(param_3);
  uVar4 = FUN_00b0a9c1(param_2);
  FUN_00b0b5c2(param_1,uVar1,uVar4,uVar3,uVar2);
  return uVar1;
}


// ==== entry=00b0ae7c name=FUN_00b0ae7c size=1106 ====

undefined8 FUN_00b0ae7c(undefined8 param_1,undefined8 param_2,undefined8 param_3)

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
  lVar3 = FUN_00b0b694(&local_118);
  local_f0 = lVar3;
  lVar4 = FUN_00b0ac74(local_110);
  uVar7 = local_110;
  if (lVar3 != lVar4) {
    uVar6 = FUN_00b0ad1c(local_f0);
    cVar2 = FUN_00b0a97a(uVar7,param_3,uVar6);
    lVar3 = local_f0;
    uVar7 = local_110;
    if (cVar2 != '\0') {
      local_f8 = local_f0;
      plVar8 = (long *)FUN_00b0b8a8(local_110);
      uVar7 = local_110;
      if (lVar3 == *plVar8) {
        uVar7 = FUN_00b0b8a8(local_110);
        uVar6 = FUN_00b0b8a8(local_110);
        FUN_00b024b8(local_c8,uVar6,uVar7);
        return local_c8[0];
      }
      puVar5 = (undefined8 *)FUN_00b0b8ba(&local_f8);
      uVar6 = FUN_00b0ad1c(*puVar5);
      cVar2 = FUN_00b0a97a(uVar7,uVar6,param_3);
      if (cVar2 != '\0') {
        lVar3 = FUN_00b0b541(local_f8);
        if (lVar3 == 0) {
          local_a0 = 0;
          FUN_00b0247c(local_b8,&local_a0,&local_f8);
          return local_b8[0];
        }
        FUN_00b024b8(local_98,&local_f0,&local_f0);
        return local_98[0];
      }
      uVar7 = FUN_00b0b732(local_110,param_3);
      return uVar7;
    }
    uVar6 = FUN_00b0ad1c(local_f0);
    cVar2 = FUN_00b0a97a(uVar7,uVar6,param_3);
    lVar3 = local_f0;
    if (cVar2 == '\0') {
      local_20[0] = 0;
      FUN_00b01a5a(local_38,&local_f0,local_20);
      return local_38[0];
    }
    local_100 = local_f0;
    plVar8 = (long *)FUN_00b0b6ce(local_110);
    uVar7 = local_110;
    if (lVar3 == *plVar8) {
      uVar7 = FUN_00b0b6ce(local_110);
      local_70 = 0;
      FUN_00b0247c(local_88,&local_70,uVar7);
      return local_88[0];
    }
    puVar5 = (undefined8 *)FUN_00b0b8e6(&local_100);
    uVar6 = FUN_00b0ad1c(*puVar5);
    cVar2 = FUN_00b0a97a(uVar7,param_3,uVar6);
    if (cVar2 == '\0') {
      uVar7 = FUN_00b0b732(local_110,param_3);
      return uVar7;
    }
    lVar3 = FUN_00b0b541(local_f0);
    if (lVar3 == 0) {
      local_50 = 0;
      FUN_00b0247c(local_68,&local_50,&local_f0);
      return local_68[0];
    }
    FUN_00b024b8(local_48,&local_100,&local_100);
    return local_48[0];
  }
  lVar3 = FUN_00b0b6bc(local_110);
  uVar7 = local_110;
  if (lVar3 != 0) {
    puVar5 = (undefined8 *)FUN_00b0b6ce(local_110);
    uVar6 = FUN_00b0ad1c(*puVar5);
    cVar2 = FUN_00b0a97a(uVar7,uVar6,param_3);
    if (cVar2 != '\0') {
      bVar1 = true;
      goto LAB_00b0af34;
    }
  }
  bVar1 = false;
LAB_00b0af34:
  if (bVar1) {
    uVar7 = FUN_00b0b6ce(local_110);
    local_d0 = 0;
    FUN_00b0247c(local_e8,&local_d0,uVar7);
  }
  else {
    local_e8[0] = FUN_00b0b732(local_110,param_3);
  }
  return local_e8[0];
}


// ==== entry=00b0b2ce name=FUN_00b0b2ce size=45 ====

void FUN_00b0b2ce(undefined8 param_1)

{
  undefined8 uVar1;
  undefined1 local_9;
  
  uVar1 = FUN_00b0b911(param_1);
  FUN_00b0b56e(&local_9,uVar1);
  return;
}


// ==== entry=00b0b2fc name=FUN_00b0b2fc size=195 ====

undefined8
FUN_00b0b2fc(long param_1,long param_2,_Rb_tree_node_base *param_3,_Rb_tree_node_base *param_4)

{
  char cVar1;
  _Rb_tree_node_base *p_Var2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined8 local_28;
  undefined1 local_19;
  
  if (param_2 == 0) {
    p_Var2 = (_Rb_tree_node_base *)FUN_00b0ac74(param_1);
    if (param_3 != p_Var2) {
      uVar3 = FUN_00b0ad1c(param_3);
      uVar4 = FUN_00b0b2ce(param_4);
      cVar1 = FUN_00b0a97a(param_1,uVar4,uVar3);
      if (cVar1 == '\0') {
        local_19 = false;
        goto LAB_00b0b36d;
      }
    }
  }
  local_19 = true;
LAB_00b0b36d:
  std::_Rb_tree_insert_and_rebalance
            ((bool)local_19,param_4,param_3,(_Rb_tree_node_base *)(param_1 + 8));
  *(long *)(param_1 + 0x28) = *(long *)(param_1 + 0x28) + 1;
  FUN_00b0ad4a(&local_28,param_4);
  return local_28;
}


// ==== entry=00b0b3c0 name=FUN_00b0b3c0 size=57 ====

void FUN_00b0b3c0(undefined8 param_1,undefined8 param_2)

{
  FUN_00b0b92c(param_1,param_2);
  FUN_00b0b96c(param_1,param_2);
  return;
}


// ==== entry=00b0b3fa name=FUN_00b0b3fa size=11 ====

void FUN_00b0b3fa(void)

{
  return;
}


// ==== entry=00b0b405 name=FUN_00b0b405 size=26 ====

void FUN_00b0b405(undefined8 param_1)

{
  FUN_00b0b9a2(param_1);
  return;
}


// ==== entry=00b0b41f name=FUN_00b0b41f size=26 ====

void FUN_00b0b41f(undefined8 param_1)

{
  FUN_00b0b9bc(param_1);
  return;
}


// ==== entry=00b0b43a name=FUN_00b0b43a size=11 ====

void FUN_00b0b43a(void)

{
  return;
}


// ==== entry=00b0b445 name=FUN_00b0b445 size=26 ====

void FUN_00b0b445(undefined8 param_1)

{
  FUN_00b0b9d6(param_1);
  return;
}


// ==== entry=00b0b45f name=FUN_00b0b45f size=26 ====

void FUN_00b0b45f(undefined8 param_1)

{
  FUN_00b0b9f0(param_1);
  return;
}


// ==== entry=00b0b47a name=FUN_00b0b47a size=27 ====

void FUN_00b0b47a(undefined8 param_1)

{
  FUN_00b0ba0a(param_1);
  return;
}


// ==== entry=00b0b496 name=FUN_00b0b496 size=101 ====

void FUN_00b0b496(undefined8 param_1,long param_2)

{
  undefined8 uVar1;
  long lVar2;
  undefined8 local_28;
  
  local_28 = param_2;
  while (local_28 != 0) {
    uVar1 = FUN_00b0b541(local_28);
    FUN_00b0b496(param_1,uVar1);
    lVar2 = FUN_00b0b52f(local_28);
    FUN_00b0b3c0(param_1,local_28);
    local_28 = lVar2;
  }
  return;
}


// ==== entry=00b0b4fb name=FUN_00b0b4fb size=26 ====

void FUN_00b0b4fb(undefined8 param_1)

{
  FUN_00b0ba15(param_1);
  return;
}


// ==== entry=00b0b515 name=FUN_00b0b515 size=26 ====

void FUN_00b0b515(undefined8 param_1)

{
  FUN_00b0ba2f(param_1);
  return;
}


// ==== entry=00b0b52f name=FUN_00b0b52f size=18 ====

undefined8 FUN_00b0b52f(long param_1)

{
  return *(undefined8 *)(param_1 + 0x10);
}


// ==== entry=00b0b541 name=FUN_00b0b541 size=18 ====

undefined8 FUN_00b0b541(long param_1)

{
  return *(undefined8 *)(param_1 + 0x18);
}


// ==== entry=00b0b553 name=FUN_00b0b553 size=26 ====

void FUN_00b0b553(undefined8 param_1)

{
  FUN_00b0ba4a(param_1);
  return;
}


// ==== entry=00b0b56e name=FUN_00b0b56e size=18 ====

undefined8 FUN_00b0b56e(undefined8 param_1,undefined8 param_2)

{
  return param_2;
}


// ==== entry=00b0b580 name=FUN_00b0b580 size=26 ====

void FUN_00b0b580(undefined8 param_1)

{
  FUN_00b0ba68(param_1);
  return;
}


// ==== entry=00b0b59a name=FUN_00b0b59a size=39 ====

void FUN_00b0b59a(undefined8 param_1)

{
  undefined8 uVar1;
  
  uVar1 = FUN_00b0ba76(param_1);
  FUN_00b0ba84(uVar1,1);
  return;
}


// ==== entry=00b0b5c2 name=FUN_00b0b5c2 size=159 ====

void FUN_00b0b5c2(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                 undefined8 param_5)

{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  
  identity_forward(0x30,param_2);
  uVar1 = FUN_00b0a9dd(param_5);
  uVar2 = FUN_00b0a9cf(param_4);
  uVar3 = FUN_00b0a9c1(param_3);
  uVar4 = FUN_00b0adba(param_2);
  uVar5 = FUN_00b0ba76(param_1);
                    /* try { // try from 00b0b64d to 00b0b651 has its CatchHandler @ 00b0b654 */
  FUN_00b0baae(uVar5,uVar4,uVar3,uVar2,uVar1);
  return;
}


// ==== entry=00b0b694 name=FUN_00b0b694 size=40 ====

undefined8 FUN_00b0b694(undefined8 *param_1)

{
  undefined8 local_10;
  
  FUN_00b0ad4a(&local_10,*param_1);
  return local_10;
}


// ==== entry=00b0b6bc name=FUN_00b0b6bc size=18 ====

undefined8 FUN_00b0b6bc(long param_1)

{
  return *(undefined8 *)(param_1 + 0x28);
}


// ==== entry=00b0b6ce name=FUN_00b0b6ce size=18 ====

long FUN_00b0b6ce(long param_1)

{
  return param_1 + 0x20;
}


// ==== entry=00b0b6e0 name=FUN_00b0b6e0 size=68 ====

void FUN_00b0b6e0(undefined8 *param_1,undefined8 param_2,undefined8 param_3)

{
  undefined8 *puVar1;
  
  puVar1 = (undefined8 *)FUN_00b0b724(param_2);
  *param_1 = *puVar1;
  puVar1 = (undefined8 *)FUN_00b01a96(param_3);
  param_1[1] = *puVar1;
  return;
}


// ==== entry=00b0b724 name=FUN_00b0b724 size=14 ====

undefined8 FUN_00b0b724(undefined8 param_1)

{
  return param_1;
}


// ==== entry=00b0b732 name=FUN_00b0b732 size=374 ====

undefined1  [16] FUN_00b0b732(undefined8 param_1,undefined8 param_2)

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
  
  local_68 = FUN_00b0ac62(param_1);
  local_70 = FUN_00b0ac74(param_1);
  local_19 = '\x01';
  while (local_68 != 0) {
    local_70 = local_68;
    uVar2 = FUN_00b0b2ce(local_68);
    local_19 = FUN_00b0a97a(param_1,param_2,uVar2);
    if (local_19 == '\0') {
      local_68 = FUN_00b0b541(local_68);
    }
    else {
      local_68 = FUN_00b0b52f(local_68);
    }
  }
  FUN_00b0ad4a(&local_78,local_70);
  if (local_19 != '\0') {
    local_60 = FUN_00b0bb1a(param_1);
    cVar1 = FUN_00b0a918(&local_78,&local_60);
    if (cVar1 != '\0') {
      FUN_00b0b6e0(&local_58,&local_68,&local_70);
      goto LAB_00b0b8a1;
    }
    FUN_00b0b8ba(&local_78);
  }
  uVar2 = FUN_00b0ad1c(local_78);
  cVar1 = FUN_00b0a97a(param_1,uVar2,param_2);
  if (cVar1 == '\0') {
    local_28 = 0;
    FUN_00b01a5a(&local_38,&local_78,&local_28);
    local_58 = local_38;
    local_50 = local_30;
  }
  else {
    FUN_00b0b6e0(&local_48,&local_68,&local_70);
    local_58 = local_48;
    local_50 = local_40;
  }
LAB_00b0b8a1:
  auVar3._8_8_ = local_50;
  auVar3._0_8_ = local_58;
  return auVar3;
}


// ==== entry=00b0b8a8 name=FUN_00b0b8a8 size=18 ====

long FUN_00b0b8a8(long param_1)

{
  return param_1 + 0x18;
}


// ==== entry=00b0b8ba name=FUN_00b0b8ba size=43 ====

undefined8 * FUN_00b0b8ba(undefined8 *param_1)

{
  undefined8 uVar1;
  
  uVar1 = std::_Rb_tree_decrement((_Rb_tree_node_base *)*param_1);
  *param_1 = uVar1;
  return param_1;
}


// ==== entry=00b0b8e6 name=FUN_00b0b8e6 size=43 ====

undefined8 * FUN_00b0b8e6(undefined8 *param_1)

{
  undefined8 uVar1;
  
  uVar1 = std::_Rb_tree_increment((_Rb_tree_node_base *)*param_1);
  *param_1 = uVar1;
  return param_1;
}


// ==== entry=00b0b911 name=FUN_00b0b911 size=26 ====

void FUN_00b0b911(undefined8 param_1)

{
  FUN_00b0ba4a(param_1);
  return;
}


// ==== entry=00b0b92c name=FUN_00b0b92c size=63 ====

void FUN_00b0b92c(undefined8 param_1,undefined8 param_2)

{
  undefined8 uVar1;
  undefined8 uVar2;
  
  uVar1 = FUN_00b0adba(param_2);
  uVar2 = FUN_00b0ba76(param_1);
  FUN_00b0bb43(uVar2,uVar1);
  return;
}


// ==== entry=00b0b96c name=FUN_00b0b96c size=54 ====

void FUN_00b0b96c(undefined8 param_1,undefined8 param_2)

{
  undefined8 uVar1;
  
  uVar1 = FUN_00b0ba76(param_1);
  FUN_00b0bb69(uVar1,param_2,1);
  return;
}


// ==== entry=00b0b9a2 name=FUN_00b0b9a2 size=26 ====

void FUN_00b0b9a2(undefined8 param_1)

{
  FUN_00b0bb97(param_1);
  return;
}


// ==== entry=00b0b9bc name=FUN_00b0b9bc size=26 ====

void FUN_00b0b9bc(undefined8 param_1)

{
  FUN_00b0bba5(param_1);
  return;
}


// ==== entry=00b0b9d6 name=FUN_00b0b9d6 size=26 ====

void FUN_00b0b9d6(undefined8 param_1)

{
  FUN_00b0bbbf(param_1);
  return;
}


// ==== entry=00b0b9f0 name=FUN_00b0b9f0 size=26 ====

void FUN_00b0b9f0(undefined8 param_1)

{
  FUN_00b0bbcd(param_1);
  return;
}


// ==== entry=00b0ba0a name=FUN_00b0ba0a size=11 ====

void FUN_00b0ba0a(void)

{
  return;
}


// ==== entry=00b0ba15 name=FUN_00b0ba15 size=26 ====

void FUN_00b0ba15(undefined8 param_1)

{
  FUN_00b0bbe7(param_1);
  return;
}


// ==== entry=00b0ba2f name=FUN_00b0ba2f size=26 ====

void FUN_00b0ba2f(undefined8 param_1)

{
  FUN_00b0bc01(param_1);
  return;
}


// ==== entry=00b0ba4a name=FUN_00b0ba4a size=30 ====

void FUN_00b0ba4a(long param_1)

{
  FUN_00b0bc1c(param_1 + 0x20);
  return;
}


// ==== entry=00b0ba68 name=FUN_00b0ba68 size=14 ====

undefined8 FUN_00b0ba68(undefined8 param_1)

{
  return param_1;
}


// ==== entry=00b0ba76 name=FUN_00b0ba76 size=14 ====

undefined8 FUN_00b0ba76(undefined8 param_1)

{
  return param_1;
}


// ==== entry=00b0ba84 name=FUN_00b0ba84 size=42 ====

void FUN_00b0ba84(undefined8 param_1,undefined8 param_2)

{
  FUN_00b0bc36(param_1,param_2,0);
  return;
}


// ==== entry=00b0baae name=FUN_00b0baae size=108 ====

void FUN_00b0baae(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                 undefined8 param_5)

{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  
  uVar1 = FUN_00b0a9dd(param_5);
  uVar2 = FUN_00b0a9cf(param_4);
  uVar3 = FUN_00b0a9c1(param_3);
  FUN_00b0bca8(param_1,param_2,uVar3,uVar2,uVar1);
  return;
}


// ==== entry=00b0bb1a name=FUN_00b0bb1a size=41 ====

undefined8 FUN_00b0bb1a(long param_1)

{
  undefined8 local_10;
  
  FUN_00b0ad4a(&local_10,*(undefined8 *)(param_1 + 0x18));
  return local_10;
}


// ==== entry=00b0bb43 name=FUN_00b0bb43 size=38 ====

void FUN_00b0bb43(undefined8 param_1,undefined8 param_2)

{
  FUN_00b0bd48(param_1,param_2);
  return;
}


// ==== entry=00b0bb69 name=FUN_00b0bb69 size=46 ====

void FUN_00b0bb69(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  FUN_00b0bd68(param_1,param_2,param_3);
  return;
}


// ==== entry=00b0bb97 name=FUN_00b0bb97 size=14 ====

undefined8 FUN_00b0bb97(undefined8 param_1)

{
  return param_1;
}


// ==== entry=00b0bba5 name=FUN_00b0bba5 size=26 ====

void FUN_00b0bba5(undefined8 param_1)

{
  FUN_00b0bd8b(param_1);
  return;
}


// ==== entry=00b0bbbf name=FUN_00b0bbbf size=14 ====

undefined8 FUN_00b0bbbf(undefined8 param_1)

{
  return param_1;
}


// ==== entry=00b0bbcd name=FUN_00b0bbcd size=26 ====

void FUN_00b0bbcd(undefined8 param_1)

{
  FUN_00b0bd99(param_1);
  return;
}


// ==== entry=00b0bbe7 name=FUN_00b0bbe7 size=26 ====

void FUN_00b0bbe7(undefined8 param_1)

{
  FUN_00b0bda7(param_1);
  return;
}


// ==== entry=00b0bc01 name=FUN_00b0bc01 size=26 ====

void FUN_00b0bc01(undefined8 param_1)

{
  FUN_00b0bdb5(param_1);
  return;
}


// ==== entry=00b0bc1c name=FUN_00b0bc1c size=26 ====

void FUN_00b0bc1c(undefined8 param_1)

{
  FUN_00b0bdc4(param_1);
  return;
}


// ==== entry=00b0bc36 name=FUN_00b0bc36 size=75 ====

void FUN_00b0bc36(undefined8 param_1,ulong param_2)

{
  ulong uVar1;
  
  uVar1 = FUN_00b0bdd2(param_1);
  if (uVar1 < param_2) {
                    /* WARNING: Subroutine does not return */
    std::__throw_bad_alloc();
  }
  operator_new(param_2 * 0x30);
  return;
}


// ==== entry=00b0bc82 name=FUN_00b0bc82 size=38 ====

void FUN_00b0bc82(undefined8 param_1,undefined8 param_2)

{
  FUN_00b0be20(param_1,param_2);
  return;
}


// ==== entry=00b0bca8 name=FUN_00b0bca8 size=135 ====

void FUN_00b0bca8(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                 undefined8 param_5)

{
  undefined8 uVar1;
  undefined1 local_38 [24];
  
  FUN_00b0a9c1(param_3);
  uVar1 = FUN_00b0a9cf(param_4);
  FUN_00b0bc82(local_38,uVar1);
  FUN_00b0a9dd(param_5);
  uVar1 = identity_forward(0x10,param_2);
                    /* try { // try from 00b0bd1d to 00b0bd21 has its CatchHandler @ 00b0bd24 */
  FUN_00b0be5c(uVar1,local_38);
  return;
}


// ==== entry=00b0bd48 name=FUN_00b0bd48 size=31 ====

void FUN_00b0bd48(undefined8 param_1,undefined8 param_2)

{
  FUN_009a3690(param_2);
  return;
}


// ==== entry=00b0bd68 name=FUN_00b0bd68 size=35 ====

void FUN_00b0bd68(undefined8 param_1,void *param_2)

{
  operator_delete(param_2);
  return;
}


// ==== entry=00b0bd8b name=FUN_00b0bd8b size=14 ====

undefined8 FUN_00b0bd8b(undefined8 param_1)

{
  return param_1;
}


// ==== entry=00b0bd99 name=FUN_00b0bd99 size=14 ====

undefined8 FUN_00b0bd99(undefined8 param_1)

{
  return param_1;
}


// ==== entry=00b0bda7 name=FUN_00b0bda7 size=14 ====

undefined8 FUN_00b0bda7(undefined8 param_1)

{
  return param_1;
}


// ==== entry=00b0bdb5 name=FUN_00b0bdb5 size=14 ====

undefined8 FUN_00b0bdb5(undefined8 param_1)

{
  return param_1;
}


// ==== entry=00b0bdc4 name=FUN_00b0bdc4 size=14 ====

undefined8 FUN_00b0bdc4(undefined8 param_1)

{
  return param_1;
}


// ==== entry=00b0bdd2 name=FUN_00b0bdd2 size=20 ====

undefined8 FUN_00b0bdd2(void)

{
  return 0x555555555555555;
}


// ==== entry=00b0bde6 name=FUN_00b0bde6 size=26 ====

void FUN_00b0bde6(undefined8 param_1)

{
  FUN_00b0be00(param_1);
  return;
}


// ==== entry=00b0be00 name=FUN_00b0be00 size=17 ====

undefined8 FUN_00b0be00(undefined8 *param_1)

{
  return *param_1;
}


// ==== entry=00b0be11 name=FUN_00b0be11 size=14 ====

undefined8 FUN_00b0be11(undefined8 param_1)

{
  return param_1;
}


// ==== entry=00b0be20 name=FUN_00b0be20 size=60 ====

void FUN_00b0be20(undefined8 param_1,undefined8 param_2)

{
  undefined8 uVar1;
  
  uVar1 = FUN_00b0bde6(param_2);
  uVar1 = FUN_00b0be11(uVar1);
  FUN_00b0a48e(param_1,uVar1);
  return;
}


// ==== entry=00b0be5c name=FUN_00b0be5c size=42 ====

void FUN_00b0be5c(undefined8 param_1,undefined8 param_2)

{
  FUN_00b0beba(param_1,param_2,&stack0x00000008);
  return;
}


// ==== entry=00b0be86 name=FUN_00b0be86 size=26 ====

void FUN_00b0be86(undefined8 param_1)

{
  FUN_00b0bea0(param_1);
  return;
}


// ==== entry=00b0bea0 name=FUN_00b0bea0 size=26 ====

void FUN_00b0bea0(undefined8 param_1)

{
  FUN_00b0bde6(param_1);
  return;
}


// ==== entry=00b0beba name=FUN_00b0beba size=81 ====

void FUN_00b0beba(string *param_1,undefined8 param_2)

{
  undefined8 uVar1;
  string *psVar2;
  
  uVar1 = FUN_00b0be86(param_2);
  psVar2 = (string *)FUN_00b0be11(uVar1);
  std::string::string(param_1,psVar2);
                    /* try { // try from 00b0befd to 00b0bf01 has its CatchHandler @ 00b0bf04 */
  std::string::string(param_1 + 8);
  return;
}


// ==== entry=00b0bf26 name=FUN_00b0bf26 size=177 ====

void FUN_00b0bf26(long param_1,undefined8 param_2)

{
  FUN_00b21302(param_1,param_2);
                    /* try { // try from 00b0bf55 to 00b0bf59 has its CatchHandler @ 00b0c025 */
  FUN_00b0f10c(param_1 + 0x80);
  *(undefined1 *)(param_1 + 0xd0) = 0;
  *(undefined1 *)(param_1 + 0xd1) = 0;
  *(undefined1 *)(param_1 + 0xd2) = 0;
  *(undefined1 *)(param_1 + 0xd3) = 0;
                    /* try { // try from 00b0bf93 to 00b0bf97 has its CatchHandler @ 00b0c010 */
  FUN_00b0f196(param_1 + 0xd8);
                    /* try { // try from 00b0bfa5 to 00b0bfa9 has its CatchHandler @ 00b0bff9 */
  FUN_00b0f220(param_1 + 0x128);
  FUN_00b0f2aa(param_1 + 0x178);
                    /* try { // try from 00b0bfc9 to 00b0bfcd has its CatchHandler @ 00b0bfd0 */
  FUN_00b0f30a(param_1 + 400);
  return;
}


// ==== entry=00b0c046 name=FUN_00b0c046 size=115 ====

void FUN_00b0c046(long param_1)

{
  FUN_00b0eeae(param_1 + 400);
  FUN_00b0ee92(param_1 + 0x178);
  FUN_00b0ee76(param_1 + 0x128);
  FUN_00b0ee5a(param_1 + 0xd8);
  FUN_00b0ee3e(param_1 + 0x80);
  FUN_00b2155a(param_1);
  return;
}


// ==== entry=00b0c0ba name=FUN_00b0c0ba size=42 ====

void FUN_00b0c0ba(long param_1)

{
  FUN_00b0c1b4(param_1);
  FUN_00b0f394(param_1 + 0x80);
  return;
}


// ==== entry=00b0c0e4 orig=FUN_00b0c0e4 size=66 name=yaml_scanner_pop ====

void yaml_scanner_pop(long param_1)

{
  char cVar1;
  
  FUN_00b0c1b4(param_1);
  cVar1 = FUN_00b0f394(param_1 + 0x80);
  if (cVar1 != '\x01') {
    FUN_00b0f3ae(param_1 + 0x80);
  }
  return;
}


// ==== entry=00b0c126 orig=FUN_00b0c126 size=90 name=yaml_scanner_peek ====

void yaml_scanner_peek(long param_1)

{
  char cVar1;
  
  FUN_00b0c1b4(param_1);
  cVar1 = FUN_00b0f394(param_1 + 0x80);
  if (cVar1 == '\x01') {
                    /* WARNING: Subroutine does not return */
    __assert_fail("!m_tokens.empty()","/mnt/hgfs/Develop/Library/yaml-cpp-0.7.0/src/scanner.cpp",
                  0x25,"YAML::Token& YAML::Scanner::peek()");
  }
  FUN_00b0f3ca(param_1 + 0x80);
  return;
}


// ==== entry=00b0c180 name=FUN_00b0c180 size=51 ====

undefined1  [16] FUN_00b0c180(undefined8 param_1)

{
  undefined1 auVar1 [12];
  undefined1 auVar2 [16];
  
  auVar1 = FUN_00b0d79a(param_1);
  auVar2._12_4_ = 0;
  auVar2._0_12_ = auVar1;
  return auVar2;
}


// ==== entry=00b0c1b4 name=FUN_00b0c1b4 size=129 ====

void FUN_00b0c1b4(long param_1)

{
  char cVar1;
  int *piVar2;
  
  do {
    while (cVar1 = FUN_00b0f394(param_1 + 0x80), cVar1 == '\x01') {
LAB_00b0c212:
      if (*(char *)(param_1 + 0xd1) != '\0') {
        return;
      }
      yaml_scan_token(param_1);
    }
    piVar2 = (int *)FUN_00b0f3ca(param_1 + 0x80);
    if (*piVar2 == 0) {
      return;
    }
    if (*piVar2 != 1) goto LAB_00b0c212;
    FUN_00b0f3ae(param_1 + 0x80);
  } while( true );
}


// ==== entry=00b0c236 orig=FUN_00b0c236 size=1139 name=yaml_scan_token ====

void yaml_scan_token(long param_1)

{
  bool bVar1;
  char cVar2;
  int iVar3;
  undefined8 uVar4;
  string local_30 [11];
  allocator local_25;
  undefined1 local_24 [12];
  
  if (*(char *)(param_1 + 0xd1) != '\0') {
    return;
  }
  if (*(char *)(param_1 + 0xd0) != '\x01') {
    FUN_00b0c914(param_1);
    return;
  }
  FUN_00b0c6dc(param_1);
  FUN_00b0ccc6(param_1);
  cVar2 = FUN_00b0d772(param_1);
  if (cVar2 != '\0') {
    FUN_00b0c9e6(param_1);
    return;
  }
  iVar3 = FUN_00b0d7c0(param_1);
  if ((iVar3 == 0) && (cVar2 = yaml_read_byte(param_1), cVar2 == '%')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    FUN_00b15394(param_1);
    return;
  }
  iVar3 = FUN_00b0d7c0(param_1);
  if (iVar3 == 0) {
    uVar4 = FUN_00b0dda4();
    cVar2 = FUN_00b0d930(uVar4,param_1);
    if (cVar2 == '\0') goto LAB_00b0c327;
    bVar1 = true;
  }
  else {
LAB_00b0c327:
    bVar1 = false;
  }
  if (bVar1) {
    FUN_00b156d4(param_1);
    return;
  }
  iVar3 = FUN_00b0d7c0(param_1);
  if (iVar3 == 0) {
    uVar4 = FUN_00b0df2f();
    cVar2 = FUN_00b0d930(uVar4,param_1);
    if (cVar2 != '\0') {
      bVar1 = true;
      goto LAB_00b0c378;
    }
  }
  bVar1 = false;
LAB_00b0c378:
  if (bVar1) {
    FUN_00b1579a(param_1);
    return;
  }
  cVar2 = yaml_read_byte(param_1);
  if ((cVar2 == '[') || (cVar2 = yaml_read_byte(param_1), cVar2 == '{')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    FUN_00b15860(param_1);
    return;
  }
  cVar2 = yaml_read_byte(param_1);
  if ((cVar2 == ']') || (cVar2 = yaml_read_byte(param_1), cVar2 == '}')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    FUN_00b1595e(param_1);
    return;
  }
  cVar2 = yaml_read_byte(param_1);
  if (cVar2 == ',') {
    FUN_00b15d36(param_1);
    return;
  }
  uVar4 = FUN_00b0e0ba();
  cVar2 = FUN_00b0d930(uVar4,param_1);
  if (cVar2 == '\0') {
    cVar2 = FUN_00b0ee1e(param_1);
    if (cVar2 == '\0') {
      uVar4 = FUN_00b0e2b4();
    }
    else {
      uVar4 = FUN_00b0e1e8();
    }
    cVar2 = FUN_00b0d930(uVar4,param_1);
    if (cVar2 != '\0') {
      FUN_00b161b8(param_1);
      return;
    }
    uVar4 = FUN_00b0c8d4(param_1);
    cVar2 = FUN_00b0d930(uVar4,param_1);
    if (cVar2 != '\0') {
      FUN_00b16390(param_1);
      return;
    }
    cVar2 = yaml_read_byte(param_1);
    if ((cVar2 == '*') || (cVar2 = yaml_read_byte(param_1), cVar2 == '&')) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if (!bVar1) {
      cVar2 = yaml_read_byte(param_1);
      if (cVar2 == '!') {
        FUN_00b1693a(param_1);
        return;
      }
      cVar2 = FUN_00b0ee1e(param_1);
      if ((cVar2 == '\0') ||
         ((cVar2 = yaml_read_byte(param_1), cVar2 != '|' &&
          (cVar2 = yaml_read_byte(param_1), cVar2 != '>')))) {
        bVar1 = false;
      }
      else {
        bVar1 = true;
      }
      if (!bVar1) {
        cVar2 = yaml_read_byte(param_1);
        if ((cVar2 == '\'') || (cVar2 = yaml_read_byte(param_1), cVar2 == '\"')) {
          bVar1 = true;
        }
        else {
          bVar1 = false;
        }
        if (bVar1) {
          FUN_00b16dac(param_1);
        }
        else {
          cVar2 = FUN_00b0ee1e(param_1);
          if (cVar2 == '\0') {
            uVar4 = FUN_00b0ea5d();
          }
          else {
            uVar4 = FUN_00b0e766();
          }
          cVar2 = FUN_00b0d930(uVar4,param_1);
          if (cVar2 == '\0') {
            uVar4 = __cxa_allocate_exception(0x28);
            std::allocator<char>::allocator();
                    /* try { // try from 00b0c642 to 00b0c646 has its CatchHandler @ 00b0c6b0 */
            std::string::string(local_30,"unknown token",&local_25);
            local_24 = FUN_00b0d79a(param_1);
                    /* try { // try from 00b0c670 to 00b0c674 has its CatchHandler @ 00b0c69f */
            FUN_00b09fc4(uVar4,local_24,local_30);
            std::string::~string(local_30);
            std::allocator<char>::~allocator((allocator<char> *)&local_25);
                    /* WARNING: Subroutine does not return */
            __cxa_throw(uVar4,&PTR_PTR_00d39ce8,FUN_00b009e6);
          }
          FUN_00b16bca(param_1);
        }
        return;
      }
      yaml_scan_block_scalar(param_1);
      return;
    }
    FUN_00b165ae(param_1);
    return;
  }
  FUN_00b15f10(param_1);
  return;
}


// ==== entry=00b0c6dc name=FUN_00b0c6dc size=431 ====

void FUN_00b0c6dc(long param_1)

{
  bool bVar1;
  char cVar2;
  undefined8 uVar3;
  undefined1 local_48 [44];
  undefined4 local_1c;
  
LAB_00b0c6e9:
  do {
    cVar2 = FUN_00b215d8(param_1);
    if (cVar2 == '\0') {
LAB_00b0c721:
      bVar1 = false;
    }
    else {
      cVar2 = yaml_read_byte(param_1);
      cVar2 = FUN_00b0c8a6(param_1,(int)cVar2);
      if (cVar2 == '\0') goto LAB_00b0c721;
      bVar1 = true;
    }
    if (bVar1) {
      cVar2 = FUN_00b0ee1e(param_1);
      if (cVar2 == '\0') {
LAB_00b0c75c:
        bVar1 = false;
      }
      else {
        uVar3 = FUN_00b0da92();
        cVar2 = FUN_00b0d930(uVar3,param_1);
        if (cVar2 == '\0') goto LAB_00b0c75c;
        bVar1 = true;
      }
      if (bVar1) {
        *(undefined1 *)(param_1 + 0xd2) = 0;
      }
      FUN_00b2174c(param_1,1);
      goto LAB_00b0c6e9;
    }
    FUN_00b0e6c4(local_48);
                    /* try { // try from 00b0c7a0 to 00b0c7a4 has its CatchHandler @ 00b0c884 */
    cVar2 = FUN_00b0d930(local_48,param_1);
    FUN_00b0d994(local_48);
    if (cVar2 != '\0') {
      do {
        cVar2 = FUN_00b215d8(param_1);
        if (cVar2 == '\0') {
LAB_00b0c7ec:
          bVar1 = false;
        }
        else {
          uVar3 = FUN_00b0dbb2();
          cVar2 = FUN_00b0d930(uVar3,param_1);
          if (cVar2 == '\x01') goto LAB_00b0c7ec;
          bVar1 = true;
        }
        if (!bVar1) break;
        FUN_00b2174c(param_1,1);
      } while( true );
    }
    uVar3 = FUN_00b0dbb2();
    cVar2 = FUN_00b0d930(uVar3,param_1);
    if (cVar2 != '\x01') {
      return;
    }
    uVar3 = FUN_00b0dbb2();
    local_1c = FUN_00b0d95a(uVar3,param_1);
    FUN_00b2174c(param_1,local_1c);
    FUN_00b1a946(param_1);
    cVar2 = FUN_00b0ee1e(param_1);
    if (cVar2 != '\0') {
      *(undefined1 *)(param_1 + 0xd2) = 1;
    }
  } while( true );
}


// ==== entry=00b0c8a6 name=FUN_00b0c8a6 size=46 ====

undefined8 FUN_00b0c8a6(undefined8 param_1,char param_2)

{
  undefined8 uVar1;
  
  if (param_2 == ' ') {
    uVar1 = 1;
  }
  else if (param_2 == '\t') {
    uVar1 = 1;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


// ==== entry=00b0c8d4 name=FUN_00b0c8d4 size=64 ====

void FUN_00b0c8d4(long param_1)

{
  char cVar1;
  
  cVar1 = FUN_00b0ee1e(param_1);
  if (cVar1 == '\0') {
    if (*(char *)(param_1 + 0xd3) == '\0') {
      FUN_00b0e4ae();
    }
    else {
      FUN_00b0e63e();
    }
  }
  else {
    FUN_00b0e380();
  }
  return;
}


// ==== entry=00b0c914 name=FUN_00b0c914 size=184 ====

void FUN_00b0c914(long param_1)

{
  void *pvVar1;
  undefined8 uVar2;
  undefined1 local_28 [8];
  undefined8 local_20 [2];
  
  *(undefined1 *)(param_1 + 0xd0) = 1;
  *(undefined1 *)(param_1 + 0xd2) = 1;
  pvVar1 = operator_new(0x18);
  FUN_00b0edbe(pvVar1,0xffffffff,2);
  FUN_00b0f3e4(local_28,pvVar1);
  uVar2 = FUN_00b0eec9(local_28);
                    /* try { // try from 00b0c982 to 00b0c9b6 has its CatchHandler @ 00b0c9c5 */
  FUN_00b0f462(param_1 + 0x178,uVar2);
  local_20[0] = FUN_00b0f496(param_1 + 0x178);
  FUN_00b0f4c6(param_1 + 0x128,local_20);
  FUN_00b0f40a(local_28);
  return;
}


// ==== entry=00b0c9e6 name=FUN_00b0c9e6 size=94 ====

void FUN_00b0c9e6(long param_1)

{
  int iVar1;
  
  iVar1 = FUN_00b0d7c0(param_1);
  if (0 < iVar1) {
    FUN_00b0d7d2(param_1);
  }
  FUN_00b0cdf6(param_1);
  FUN_00b1aade(param_1);
  *(undefined1 *)(param_1 + 0xd2) = 0;
  *(undefined1 *)(param_1 + 0xd1) = 1;
  return;
}


// ==== entry=00b0ca44 name=FUN_00b0ca44 size=127 ====

void FUN_00b0ca44(long param_1,undefined4 param_2)

{
  undefined1 local_68 [68];
  undefined1 local_24 [12];
  
  local_24 = FUN_00b0d79a(param_1);
  FUN_00b0ed54(local_68,param_2,local_24);
                    /* try { // try from 00b0ca99 to 00b0ca9d has its CatchHandler @ 00b0cabc */
  FUN_00b0f508(param_1 + 0x80,local_68);
  yaml_token_dtor(local_68);
  FUN_00b0f53c(param_1 + 0x80);
  return;
}


// ==== entry=00b0cade name=FUN_00b0cade size=100 ====

undefined8 FUN_00b0cade(undefined8 param_1,int param_2)

{
  undefined8 uVar1;
  
  if (param_2 == 1) {
    uVar1 = 3;
  }
  else {
    if (param_2 == 2) {
                    /* WARNING: Subroutine does not return */
      __assert_fail("false","/mnt/hgfs/Develop/Library/yaml-cpp-0.7.0/src/scanner.cpp",0x117,
                    "YAML::Token::TYPE YAML::Scanner::GetStartTokenFor(YAML::Scanner::IndentMarker::INDENT_TYPE) const"
                   );
    }
    if (param_2 != 0) {
                    /* WARNING: Subroutine does not return */
      __assert_fail("false","/mnt/hgfs/Develop/Library/yaml-cpp-0.7.0/src/scanner.cpp",0x11a,
                    "YAML::Token::TYPE YAML::Scanner::GetStartTokenFor(YAML::Scanner::IndentMarker::INDENT_TYPE) const"
                   );
    }
    uVar1 = 4;
  }
  return uVar1;
}


// ==== entry=00b0cb42 name=FUN_00b0cb42 size=362 ====

undefined8 FUN_00b0cb42(long param_1,undefined4 param_2,undefined4 param_3)

{
  char cVar1;
  undefined4 uVar2;
  void *pvVar3;
  undefined8 *puVar4;
  undefined8 uVar5;
  undefined1 local_38 [8];
  int *local_30;
  int *local_28;
  int *local_20;
  
  cVar1 = FUN_00b0edfa(param_1);
  if (cVar1 == '\0') {
    pvVar3 = operator_new(0x18);
    FUN_00b0edbe(pvVar3,param_2,param_3);
    FUN_00b0f3e4(local_38,pvVar3);
    local_20 = (int *)FUN_00b0f556(local_38);
    puVar4 = (undefined8 *)FUN_00b0f570(param_1 + 0x128);
    local_28 = (int *)*puVar4;
    if (*local_20 < *local_28) {
      uVar5 = 0;
    }
    else if ((*local_20 == *local_28) && ((local_20[1] != 1 || (local_28[1] != 0)))) {
      uVar5 = 0;
    }
    else {
      uVar2 = FUN_00b0cade(param_1,param_3);
                    /* try { // try from 00b0cc2b to 00b0cc7e has its CatchHandler @ 00b0cca5 */
      uVar5 = FUN_00b0ca44(param_1,uVar2);
      *(undefined8 *)(local_20 + 4) = uVar5;
      local_30 = local_20;
      FUN_00b0f4c6(param_1 + 0x128,&local_30);
      uVar5 = FUN_00b0eec9(local_38);
      FUN_00b0f462(param_1 + 0x178,uVar5);
      uVar5 = FUN_00b0f496(param_1 + 0x178);
    }
    FUN_00b0f40a(local_38);
  }
  else {
    uVar5 = 0;
  }
  return uVar5;
}


// ==== entry=00b0ccc6 name=FUN_00b0ccc6 size=304 ====

void FUN_00b0ccc6(long param_1)

{
  int iVar1;
  int *piVar2;
  bool bVar3;
  char cVar4;
  int iVar5;
  undefined8 *puVar6;
  undefined8 uVar7;
  long *plVar8;
  
  cVar4 = FUN_00b0edfa(param_1);
  if (cVar4 == '\0') {
    while (cVar4 = FUN_00b0f58a(param_1 + 0x128), cVar4 != '\x01') {
      puVar6 = (undefined8 *)FUN_00b0f570(param_1 + 0x128);
      piVar2 = (int *)*puVar6;
      iVar1 = *piVar2;
      iVar5 = FUN_00b0d7c0(param_1);
      if (iVar1 < iVar5) break;
      iVar1 = *piVar2;
      iVar5 = FUN_00b0d7c0(param_1);
      if (iVar1 == iVar5) {
        if (piVar2[1] == 1) {
          uVar7 = FUN_00b0e0ba();
          cVar4 = FUN_00b0d930(uVar7,param_1);
          if (cVar4 == '\0') goto LAB_00b0cd7c;
        }
        bVar3 = true;
      }
      else {
LAB_00b0cd7c:
        bVar3 = false;
      }
      if (bVar3) break;
      FUN_00b0ce64(param_1);
    }
    while( true ) {
      cVar4 = FUN_00b0f58a(param_1 + 0x128);
      if ((cVar4 == '\x01') ||
         (plVar8 = (long *)FUN_00b0f570(param_1 + 0x128), *(int *)(*plVar8 + 8) != 1)) {
        bVar3 = false;
      }
      else {
        bVar3 = true;
      }
      if (!bVar3) break;
      FUN_00b0ce64(param_1);
    }
  }
  return;
}


// ==== entry=00b0cdf6 name=FUN_00b0cdf6 size=110 ====

void FUN_00b0cdf6(long param_1)

{
  char cVar1;
  long *plVar2;
  
  cVar1 = FUN_00b0edfa(param_1);
  if (cVar1 == '\0') {
    while ((cVar1 = FUN_00b0f58a(param_1 + 0x128), cVar1 != '\x01' &&
           (plVar2 = (long *)FUN_00b0f570(param_1 + 0x128), *(int *)(*plVar2 + 4) != 2))) {
      FUN_00b0ce64(param_1);
    }
  }
  return;
}


// ==== entry=00b0ce64 name=FUN_00b0ce64 size=336 ====

void FUN_00b0ce64(long param_1)

{
  long *plVar1;
  undefined1 local_c8 [68];
  undefined1 local_84 [12];
  undefined1 local_78 [76];
  undefined1 local_2c [12];
  long local_20;
  
  plVar1 = (long *)FUN_00b0f570(param_1 + 0x128);
  local_20 = *plVar1;
  FUN_00b0f5a4(param_1 + 0x128);
  if (*(int *)(local_20 + 8) == 0) {
    if (*(int *)(local_20 + 4) == 1) {
      local_84 = FUN_00b0d79a(param_1);
      FUN_00b0ed54(local_c8,5,local_84);
                    /* try { // try from 00b0cf24 to 00b0cf28 has its CatchHandler @ 00b0cfaa */
      FUN_00b0f508(param_1 + 0x80,local_c8);
      yaml_token_dtor(local_c8);
    }
    else if (*(int *)(local_20 + 4) == 0) {
      local_2c = FUN_00b0d79a(param_1);
      FUN_00b0ed54(local_78,6,local_2c);
                    /* try { // try from 00b0cf97 to 00b0cf9b has its CatchHandler @ 00b0cfc7 */
      FUN_00b0f508(param_1 + 0x80,local_78);
      yaml_token_dtor(local_78);
    }
  }
  else {
    FUN_00b1a946(param_1);
  }
  return;
}


// ==== entry=00b0cfec name=FUN_00b0cfec size=66 ====

undefined4 FUN_00b0cfec(long param_1)

{
  char cVar1;
  undefined4 uVar2;
  undefined8 *puVar3;
  
  cVar1 = FUN_00b0f58a(param_1 + 0x128);
  if (cVar1 == '\0') {
    puVar3 = (undefined8 *)FUN_00b0f5c0(param_1 + 0x128);
    uVar2 = *(undefined4 *)*puVar3;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}


// ==== entry=00b0d02e name=FUN_00b0d02e size=150 ====

void FUN_00b0d02e(long param_1,undefined8 param_2)

{
  char cVar1;
  undefined8 uVar2;
  undefined1 local_2c [12];
  long local_20;
  
  local_2c = FUN_00b004e3();
  cVar1 = FUN_00b0f394(param_1 + 0x80);
  if (cVar1 != '\x01') {
    local_20 = FUN_00b0f5da(param_1 + 0x80);
    local_2c = *(undefined1 (*) [12])(local_20 + 8);
  }
  uVar2 = __cxa_allocate_exception(0x28);
                    /* try { // try from 00b0d0ad to 00b0d0b1 has its CatchHandler @ 00b0d0c4 */
  FUN_00b09fc4(uVar2,local_2c,param_2);
                    /* WARNING: Subroutine does not return */
  __cxa_throw(uVar2,&PTR_PTR_00d39ce8,FUN_00b009e6);
}


// ==== entry=00b0d0da name=FUN_00b0d0da size=48 ====

void FUN_00b0d0da(void)

{
  string *this;
  
  this = (string *)&DAT_011c2c20;
  while (this != (string *)&DAT_011c2b80) {
    this = this + -8;
    std::string::~string(this);
  }
  return;
}


// ==== entry=00b0d10a orig=FUN_00b0d10a size=1151 name=yaml_static_init_b ====

void yaml_static_init_b(int param_1,int param_2)

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
    std::ios_base::Init::Init((Init *)&DAT_011c2b60);
    __cxa_atexit(std::ios_base::Init::~Init,&DAT_011c2b60,&DAT_00c89008);
    std::allocator<char>::allocator();
                    /* try { // try from 00b0d178 to 00b0d17c has its CatchHandler @ 00b0d57e */
    std::string::string((string *)&DAT_011c2b80,"DIRECTIVE",&local_3c);
    std::allocator<char>::~allocator((allocator<char> *)&local_3c);
    std::allocator<char>::allocator();
                    /* try { // try from 00b0d1ac to 00b0d1b0 has its CatchHandler @ 00b0d592 */
    std::string::string((string *)&DAT_011c2b88,"DOC_START",&local_3b);
    std::allocator<char>::~allocator((allocator<char> *)&local_3b);
    std::allocator<char>::allocator();
                    /* try { // try from 00b0d1e0 to 00b0d1e4 has its CatchHandler @ 00b0d5a6 */
    std::string::string((string *)&DAT_011c2b90,"DOC_END",&local_3a);
    std::allocator<char>::~allocator((allocator<char> *)&local_3a);
    std::allocator<char>::allocator();
                    /* try { // try from 00b0d214 to 00b0d218 has its CatchHandler @ 00b0d5ba */
    std::string::string((string *)&DAT_011c2b98,"BLOCK_SEQ_START",&local_39);
    std::allocator<char>::~allocator((allocator<char> *)&local_39);
    std::allocator<char>::allocator();
                    /* try { // try from 00b0d248 to 00b0d24c has its CatchHandler @ 00b0d5ce */
    std::string::string((string *)&DAT_011c2ba0,"BLOCK_MAP_START",&local_38);
    std::allocator<char>::~allocator((allocator<char> *)&local_38);
    std::allocator<char>::allocator();
                    /* try { // try from 00b0d27c to 00b0d280 has its CatchHandler @ 00b0d5e2 */
    std::string::string((string *)&DAT_011c2ba8,"BLOCK_SEQ_END",&local_37);
    std::allocator<char>::~allocator((allocator<char> *)&local_37);
    std::allocator<char>::allocator();
                    /* try { // try from 00b0d2b0 to 00b0d2b4 has its CatchHandler @ 00b0d5f6 */
    std::string::string((string *)&DAT_011c2bb0,"BLOCK_MAP_END",&local_36);
    std::allocator<char>::~allocator((allocator<char> *)&local_36);
    std::allocator<char>::allocator();
                    /* try { // try from 00b0d2e4 to 00b0d2e8 has its CatchHandler @ 00b0d60a */
    std::string::string((string *)&DAT_011c2bb8,"BLOCK_ENTRY",&local_35);
    std::allocator<char>::~allocator((allocator<char> *)&local_35);
    std::allocator<char>::allocator();
                    /* try { // try from 00b0d318 to 00b0d31c has its CatchHandler @ 00b0d61e */
    std::string::string((string *)&DAT_011c2bc0,"FLOW_SEQ_START",&local_34);
    std::allocator<char>::~allocator((allocator<char> *)&local_34);
    std::allocator<char>::allocator();
                    /* try { // try from 00b0d34c to 00b0d350 has its CatchHandler @ 00b0d632 */
    std::string::string((string *)&DAT_011c2bc8,"FLOW_MAP_START",&local_33);
    std::allocator<char>::~allocator((allocator<char> *)&local_33);
    std::allocator<char>::allocator();
                    /* try { // try from 00b0d380 to 00b0d384 has its CatchHandler @ 00b0d646 */
    std::string::string((string *)&DAT_011c2bd0,"FLOW_SEQ_END",&local_32);
    std::allocator<char>::~allocator((allocator<char> *)&local_32);
    std::allocator<char>::allocator();
                    /* try { // try from 00b0d3b4 to 00b0d3b8 has its CatchHandler @ 00b0d65a */
    std::string::string((string *)&DAT_011c2bd8,"FLOW_MAP_END",&local_31);
    std::allocator<char>::~allocator((allocator<char> *)&local_31);
    std::allocator<char>::allocator();
                    /* try { // try from 00b0d3e8 to 00b0d3ec has its CatchHandler @ 00b0d66e */
    std::string::string((string *)&DAT_011c2be0,"FLOW_MAP_COMPACT",&local_30);
    std::allocator<char>::~allocator((allocator<char> *)&local_30);
    std::allocator<char>::allocator();
                    /* try { // try from 00b0d41c to 00b0d420 has its CatchHandler @ 00b0d67f */
    std::string::string((string *)&DAT_011c2be8,"FLOW_ENTRY",&local_2f);
    std::allocator<char>::~allocator((allocator<char> *)&local_2f);
    std::allocator<char>::allocator();
                    /* try { // try from 00b0d450 to 00b0d454 has its CatchHandler @ 00b0d690 */
    std::string::string((string *)&DAT_011c2bf0,"KEY",&local_2e);
    std::allocator<char>::~allocator((allocator<char> *)&local_2e);
    std::allocator<char>::allocator();
                    /* try { // try from 00b0d484 to 00b0d488 has its CatchHandler @ 00b0d6a1 */
    std::string::string((string *)&DAT_011c2bf8,"VALUE",&local_2d);
    std::allocator<char>::~allocator((allocator<char> *)&local_2d);
    std::allocator<char>::allocator();
                    /* try { // try from 00b0d4b8 to 00b0d4bc has its CatchHandler @ 00b0d6b2 */
    std::string::string((string *)&DAT_011c2c00,"ANCHOR",&local_2c);
    std::allocator<char>::~allocator((allocator<char> *)&local_2c);
    std::allocator<char>::allocator();
                    /* try { // try from 00b0d4ec to 00b0d4f0 has its CatchHandler @ 00b0d6c3 */
    std::string::string((string *)&DAT_011c2c08,"ALIAS",&local_2b);
    std::allocator<char>::~allocator((allocator<char> *)&local_2b);
    std::allocator<char>::allocator();
                    /* try { // try from 00b0d520 to 00b0d524 has its CatchHandler @ 00b0d6d4 */
    std::string::string((string *)&DAT_011c2c10,"TAG",&local_2a);
    std::allocator<char>::~allocator((allocator<char> *)&local_2a);
    std::allocator<char>::allocator();
                    /* try { // try from 00b0d554 to 00b0d558 has its CatchHandler @ 00b0d6e5 */
    std::string::string((string *)&DAT_011c2c18,"SCALAR",local_29);
    std::allocator<char>::~allocator((allocator<char> *)local_29);
    __cxa_atexit(FUN_00b0d0da,0,&DAT_00c89008);
  }
  return;
}


// ==== entry=00b0d733 orig=FUN_00b0d733 size=21 name=_INIT_171 ====

void _INIT_171(void)

{
  yaml_static_init_b(1,0xffff);
  return;
}


// ==== entry=00b0d748 name=FUN_00b0d748 size=41 ====

undefined8 FUN_00b0d748(ulong param_1)

{
  undefined1 auVar1 [16];
  undefined8 uVar2;
  
  if (param_1 < 0x200) {
    auVar1._8_8_ = 0;
    auVar1._0_8_ = param_1;
    uVar2 = SUB168((ZEXT816(0) << 0x40 | ZEXT816(0x200)) / auVar1,0);
  }
  else {
    uVar2 = 1;
  }
  return uVar2;
}


// ==== entry=00b0d772 name=FUN_00b0d772 size=29 ====

uint FUN_00b0d772(undefined8 param_1)

{
  uint uVar1;
  
  uVar1 = FUN_00b215d8(param_1);
  return uVar1 ^ 1;
}


// ==== entry=00b0d78f name=FUN_00b0d78f size=11 ====

undefined8 FUN_00b0d78f(void)

{
  return 4;
}


// ==== entry=00b0d79a name=FUN_00b0d79a size=38 ====

undefined1  [16] FUN_00b0d79a(long param_1)

{
  undefined1 auVar1 [16];
  
  auVar1._12_4_ = 0;
  auVar1._0_12_ = *(undefined1 (*) [12])(param_1 + 8);
  return auVar1;
}


// ==== entry=00b0d7c0 name=FUN_00b0d7c0 size=17 ====

undefined4 FUN_00b0d7c0(long param_1)

{
  return *(undefined4 *)(param_1 + 0x10);
}


// ==== entry=00b0d7d2 name=FUN_00b0d7d2 size=22 ====

void FUN_00b0d7d2(long param_1)

{
  *(undefined4 *)(param_1 + 0x10) = 0;
  return;
}


// ==== entry=00b0d7e8 name=FUN_00b0d7e8 size=44 ====

undefined1 FUN_00b0d7e8(long param_1,undefined8 param_2)

{
  undefined1 *puVar1;
  
  puVar1 = (undefined1 *)FUN_00b0ef08(param_1 + 0x18,param_2);
  return *puVar1;
}


// ==== entry=00b0d814 name=FUN_00b0d814 size=72 ====

undefined8 FUN_00b0d814(long param_1,ulong param_2)

{
  ulong uVar1;
  undefined8 uVar2;
  
  uVar1 = FUN_00b0ef32(param_1 + 0x18);
  if (param_2 < uVar1) {
    uVar2 = 1;
  }
  else {
    uVar2 = FUN_00b217d8(param_1,param_2);
  }
  return uVar2;
}


// ==== entry=00b0d85c name=FUN_00b0d85c size=38 ====

void FUN_00b0d85c(undefined8 *param_1,undefined8 param_2)

{
  *param_1 = 0;
  param_1[1] = param_2;
  return;
}


// ==== entry=00b0d882 name=FUN_00b0d882 size=51 ====

void FUN_00b0d882(long *param_1,long param_2)

{
  FUN_00b0d7e8(param_1[1],param_2 + *param_1);
  return;
}


// ==== entry=00b0d8b6 name=FUN_00b0d8b6 size=40 ====

void FUN_00b0d8b6(undefined8 *param_1)

{
  FUN_00b0d814(param_1[1],*param_1);
  return;
}


// ==== entry=00b0d8de name=FUN_00b0d8de size=81 ====

undefined1  [16] FUN_00b0d8de(long *param_1,int param_2)

{
  undefined1 auVar1 [16];
  long local_18;
  
  if (param_2 + (int)*param_1 < 0) {
    local_18 = 0;
  }
  else {
    local_18 = (long)param_2 + *param_1;
  }
  auVar1._8_8_ = param_1[1];
  auVar1._0_8_ = local_18;
  return auVar1;
}


// ==== entry=00b0d930 name=FUN_00b0d930 size=42 ====

uint FUN_00b0d930(undefined8 param_1,undefined8 param_2)

{
  uint uVar1;
  
  uVar1 = FUN_00b0d95a(param_1,param_2);
  return ~uVar1 >> 0x1f;
}


// ==== entry=00b0d95a name=FUN_00b0d95a size=57 ====

void FUN_00b0d95a(undefined8 param_1,undefined8 param_2)

{
  undefined1 local_18 [16];
  
  FUN_00b0d85c(local_18,param_2);
  FUN_00b0ef5c(param_1,local_18);
  return;
}


// ==== entry=00b0d994 name=FUN_00b0d994 size=31 ====

void FUN_00b0d994(long param_1)

{
  FUN_00b0efa0(param_1 + 8);
  return;
}


// ==== entry=00b0d9b4 name=FUN_00b0d9b4 size=88 ====

void FUN_00b0d9b4(undefined4 *param_1,undefined4 *param_2)

{
  *param_1 = *param_2;
  *(undefined1 *)(param_1 + 1) = *(undefined1 *)(param_2 + 1);
  *(undefined1 *)((long)param_1 + 5) = *(undefined1 *)((long)param_2 + 5);
  FUN_00b0efe4(param_1 + 2,param_2 + 2);
  return;
}


// ==== entry=00b0da0c name=FUN_00b0da0c size=105 ====

undefined * FUN_00b0da0c(void)

{
  int iVar1;
  
  if (DAT_011c2c40 == '\0') {
    iVar1 = __cxa_guard_acquire(&DAT_011c2c40);
    if (iVar1 != 0) {
                    /* try { // try from 00b0da46 to 00b0da4a has its CatchHandler @ 00b0da70 */
      onig_nodeInitAlt(&DAT_011c2c20,0x20);
      __cxa_guard_release(&DAT_011c2c40);
      __cxa_atexit(FUN_00b0d994,&DAT_011c2c20,&DAT_00c89008);
    }
  }
  return &DAT_011c2c20;
}


// ==== entry=00b0da92 name=FUN_00b0da92 size=105 ====

undefined * FUN_00b0da92(void)

{
  int iVar1;
  
  if (DAT_011c2c80 == '\0') {
    iVar1 = __cxa_guard_acquire(&DAT_011c2c80);
    if (iVar1 != 0) {
                    /* try { // try from 00b0dacc to 00b0dad0 has its CatchHandler @ 00b0daf6 */
      onig_nodeInitAlt(&DAT_011c2c60,9);
      __cxa_guard_release(&DAT_011c2c80);
      __cxa_atexit(FUN_00b0d994,&DAT_011c2c60,&DAT_00c89008);
    }
  }
  return &DAT_011c2c60;
}


// ==== entry=00b0db18 name=FUN_00b0db18 size=125 ====

undefined * FUN_00b0db18(void)

{
  int iVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  
  if (DAT_011c2cc0 == '\0') {
    iVar1 = __cxa_guard_acquire(&DAT_011c2cc0);
    if (iVar1 != 0) {
                    /* try { // try from 00b0db48 to 00b0db6a has its CatchHandler @ 00b0db90 */
      uVar2 = FUN_00b0da92();
      uVar3 = FUN_00b0da0c();
      FUN_00b26d8c(&DAT_011c2ca0,uVar3,uVar2);
      __cxa_guard_release(&DAT_011c2cc0);
      __cxa_atexit(FUN_00b0d994,&DAT_011c2ca0,&DAT_00c89008);
    }
  }
  return &DAT_011c2ca0;
}


// ==== entry=00b0dbb2 name=FUN_00b0dbb2 size=252 ====

undefined * FUN_00b0dbb2(void)

{
  int iVar1;
  undefined1 local_68 [32];
  string local_48 [15];
  allocator local_39;
  undefined1 local_38 [32];
  
  if (DAT_011c2d00 == '\0') {
    iVar1 = __cxa_guard_acquire(&DAT_011c2d00);
    if (iVar1 != 0) {
      std::allocator<char>::allocator();
                    /* try { // try from 00b0dc0a to 00b0dc0e has its CatchHandler @ 00b0dcd8 */
      std::string::string(local_48,"\r\n",&local_39);
                    /* try { // try from 00b0dc22 to 00b0dc26 has its CatchHandler @ 00b0dcc7 */
      FUN_00b26c88(local_68,local_48,6);
                    /* try { // try from 00b0dc33 to 00b0dc37 has its CatchHandler @ 00b0dcb6 */
      onig_nodeInitAlt(local_38,10);
                    /* try { // try from 00b0dc4b to 00b0dc4f has its CatchHandler @ 00b0dca5 */
      FUN_00b26d8c(&DAT_011c2ce0,local_38,local_68);
      __cxa_guard_release(&DAT_011c2d00);
      __cxa_atexit(FUN_00b0d994,&DAT_011c2ce0,&DAT_00c89008);
      FUN_00b0d994(local_38);
      FUN_00b0d994(local_68);
      std::string::~string(local_48);
      std::allocator<char>::~allocator((allocator<char> *)&local_39);
    }
  }
  return &DAT_011c2ce0;
}


// ==== entry=00b0dd0a orig=FUN_00b0dd0a size=125 name=yaml_getSingleton ====

undefined * yaml_getSingleton(void)

{
  int iVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  
  if (DAT_011c2d40 == '\0') {
    iVar1 = __cxa_guard_acquire(&DAT_011c2d40);
    if (iVar1 != 0) {
                    /* try { // try from 00b0dd3a to 00b0dd5c has its CatchHandler @ 00b0dd82 */
      uVar2 = FUN_00b0dbb2();
      uVar3 = FUN_00b0db18();
      FUN_00b26d8c(&DAT_011c2d20,uVar3,uVar2);
      __cxa_guard_release(&DAT_011c2d40);
      __cxa_atexit(FUN_00b0d994,&DAT_011c2d20,&DAT_00c89008);
    }
  }
  return &DAT_011c2d20;
}


// ==== entry=00b0dda4 name=FUN_00b0dda4 size=286 ====

undefined * FUN_00b0dda4(void)

{
  int iVar1;
  undefined8 uVar2;
  undefined1 local_88 [32];
  undefined1 local_68 [32];
  undefined1 local_48 [32];
  string local_28 [15];
  allocator local_19;
  
  if (DAT_011c2d80 == '\0') {
    iVar1 = __cxa_guard_acquire(&DAT_011c2d80);
    if (iVar1 != 0) {
                    /* try { // try from 00b0dde7 to 00b0ddeb has its CatchHandler @ 00b0df09 */
      FUN_00b26bdc(local_68);
                    /* try { // try from 00b0ddec to 00b0de06 has its CatchHandler @ 00b0def8 */
      uVar2 = yaml_getSingleton();
      FUN_00b26d8c(local_88,uVar2,local_68);
      std::allocator<char>::allocator();
                    /* try { // try from 00b0de23 to 00b0de27 has its CatchHandler @ 00b0dedb */
      std::string::string(local_28,"---",&local_19);
                    /* try { // try from 00b0de3b to 00b0de3f has its CatchHandler @ 00b0deca */
      FUN_00b26c88(local_48,local_28,6);
                    /* try { // try from 00b0de53 to 00b0de57 has its CatchHandler @ 00b0deb9 */
      onig_nodeAdd2(&DAT_011c2d60,local_48,local_88);
      __cxa_guard_release(&DAT_011c2d80);
      __cxa_atexit(FUN_00b0d994,&DAT_011c2d60,&DAT_00c89008);
      FUN_00b0d994(local_48);
      std::string::~string(local_28);
      std::allocator<char>::~allocator((allocator<char> *)&local_19);
      FUN_00b0d994(local_88);
      FUN_00b0d994(local_68);
    }
  }
  return &DAT_011c2d60;
}


// ==== entry=00b0df2f name=FUN_00b0df2f size=286 ====

undefined * FUN_00b0df2f(void)

{
  int iVar1;
  undefined8 uVar2;
  undefined1 local_88 [32];
  undefined1 local_68 [32];
  undefined1 local_48 [32];
  string local_28 [15];
  allocator local_19;
  
  if (DAT_011c2dc0 == '\0') {
    iVar1 = __cxa_guard_acquire(&DAT_011c2dc0);
    if (iVar1 != 0) {
                    /* try { // try from 00b0df72 to 00b0df76 has its CatchHandler @ 00b0e094 */
      FUN_00b26bdc(local_68);
                    /* try { // try from 00b0df77 to 00b0df91 has its CatchHandler @ 00b0e083 */
      uVar2 = yaml_getSingleton();
      FUN_00b26d8c(local_88,uVar2,local_68);
      std::allocator<char>::allocator();
                    /* try { // try from 00b0dfae to 00b0dfb2 has its CatchHandler @ 00b0e066 */
      std::string::string(local_28,"...",&local_19);
                    /* try { // try from 00b0dfc6 to 00b0dfca has its CatchHandler @ 00b0e055 */
      FUN_00b26c88(local_48,local_28,6);
                    /* try { // try from 00b0dfde to 00b0dfe2 has its CatchHandler @ 00b0e044 */
      onig_nodeAdd2(&DAT_011c2da0,local_48,local_88);
      __cxa_guard_release(&DAT_011c2dc0);
      __cxa_atexit(FUN_00b0d994,&DAT_011c2da0,&DAT_00c89008);
      FUN_00b0d994(local_48);
      std::string::~string(local_28);
      std::allocator<char>::~allocator((allocator<char> *)&local_19);
      FUN_00b0d994(local_88);
      FUN_00b0d994(local_68);
    }
  }
  return &DAT_011c2da0;
}


// ==== entry=00b0e0ba name=FUN_00b0e0ba size=222 ====

undefined * FUN_00b0e0ba(void)

{
  int iVar1;
  undefined8 uVar2;
  undefined1 local_78 [32];
  undefined1 local_58 [32];
  undefined1 local_38 [32];
  
  if (DAT_011c2e00 == '\0') {
    iVar1 = __cxa_guard_acquire(&DAT_011c2e00);
    if (iVar1 != 0) {
                    /* try { // try from 00b0e0fd to 00b0e101 has its CatchHandler @ 00b0e1c2 */
      FUN_00b26bdc(local_58);
                    /* try { // try from 00b0e102 to 00b0e11c has its CatchHandler @ 00b0e1b1 */
      uVar2 = yaml_getSingleton();
      FUN_00b26d8c(local_78,uVar2,local_58);
                    /* try { // try from 00b0e129 to 00b0e12d has its CatchHandler @ 00b0e1a0 */
      onig_nodeInitAlt(local_38,0x2d);
                    /* try { // try from 00b0e141 to 00b0e145 has its CatchHandler @ 00b0e18f */
      onig_nodeAdd2(&DAT_011c2de0,local_38,local_78);
      __cxa_guard_release(&DAT_011c2e00);
      __cxa_atexit(FUN_00b0d994,&DAT_011c2de0,&DAT_00c89008);
      FUN_00b0d994(local_38);
      FUN_00b0d994(local_78);
      FUN_00b0d994(local_58);
    }
  }
  return &DAT_011c2de0;
}


// ==== entry=00b0e1e8 name=FUN_00b0e1e8 size=158 ====

undefined * FUN_00b0e1e8(void)

{
  int iVar1;
  undefined8 uVar2;
  undefined1 local_38 [32];
  
  if (DAT_011c2e40 == '\0') {
    iVar1 = __cxa_guard_acquire(&DAT_011c2e40);
    if (iVar1 != 0) {
                    /* try { // try from 00b0e21c to 00b0e234 has its CatchHandler @ 00b0e28e */
      uVar2 = yaml_getSingleton();
      onig_nodeInitAlt(local_38,0x3f);
                    /* try { // try from 00b0e247 to 00b0e24b has its CatchHandler @ 00b0e27d */
      onig_nodeAdd2(&DAT_011c2e20,local_38,uVar2);
      __cxa_guard_release(&DAT_011c2e40);
      __cxa_atexit(FUN_00b0d994,&DAT_011c2e20,&DAT_00c89008);
      FUN_00b0d994(local_38);
    }
  }
  return &DAT_011c2e20;
}


// ==== entry=00b0e2b4 name=FUN_00b0e2b4 size=158 ====

undefined * FUN_00b0e2b4(void)

{
  int iVar1;
  undefined8 uVar2;
  undefined1 local_38 [32];
  
  if (DAT_011c2e80 == '\0') {
    iVar1 = __cxa_guard_acquire(&DAT_011c2e80);
    if (iVar1 != 0) {
                    /* try { // try from 00b0e2e8 to 00b0e300 has its CatchHandler @ 00b0e35a */
      uVar2 = yaml_getSingleton();
      onig_nodeInitAlt(local_38,0x3f);
                    /* try { // try from 00b0e313 to 00b0e317 has its CatchHandler @ 00b0e349 */
      onig_nodeAdd2(&DAT_011c2e60,local_38,uVar2);
      __cxa_guard_release(&DAT_011c2e80);
      __cxa_atexit(FUN_00b0d994,&DAT_011c2e60,&DAT_00c89008);
      FUN_00b0d994(local_38);
    }
  }
  return &DAT_011c2e60;
}


// ==== entry=00b0e380 name=FUN_00b0e380 size=222 ====

undefined * FUN_00b0e380(void)

{
  int iVar1;
  undefined8 uVar2;
  undefined1 local_78 [32];
  undefined1 local_58 [32];
  undefined1 local_38 [32];
  
  if (DAT_011c2ec0 == '\0') {
    iVar1 = __cxa_guard_acquire(&DAT_011c2ec0);
    if (iVar1 != 0) {
                    /* try { // try from 00b0e3c3 to 00b0e3c7 has its CatchHandler @ 00b0e488 */
      FUN_00b26bdc(local_58);
                    /* try { // try from 00b0e3c8 to 00b0e3e2 has its CatchHandler @ 00b0e477 */
      uVar2 = yaml_getSingleton();
      FUN_00b26d8c(local_78,uVar2,local_58);
                    /* try { // try from 00b0e3ef to 00b0e3f3 has its CatchHandler @ 00b0e466 */
      onig_nodeInitAlt(local_38,0x3a);
                    /* try { // try from 00b0e407 to 00b0e40b has its CatchHandler @ 00b0e455 */
      onig_nodeAdd2(&DAT_011c2ea0,local_38,local_78);
      __cxa_guard_release(&DAT_011c2ec0);
      __cxa_atexit(FUN_00b0d994,&DAT_011c2ea0,&DAT_00c89008);
      FUN_00b0d994(local_38);
      FUN_00b0d994(local_78);
      FUN_00b0d994(local_58);
    }
  }
  return &DAT_011c2ea0;
}


// ==== entry=00b0e4ae name=FUN_00b0e4ae size=291 ====

undefined * FUN_00b0e4ae(void)

{
  int iVar1;
  undefined8 uVar2;
  undefined1 local_88 [32];
  undefined1 local_68 [32];
  string local_48 [15];
  allocator local_39;
  undefined1 local_38 [32];
  
  if (DAT_011c2f00 == '\0') {
    iVar1 = __cxa_guard_acquire(&DAT_011c2f00);
    if (iVar1 != 0) {
      std::allocator<char>::allocator();
                    /* try { // try from 00b0e506 to 00b0e50a has its CatchHandler @ 00b0e60c */
      std::string::string(local_48,",]}",&local_39);
                    /* try { // try from 00b0e51e to 00b0e522 has its CatchHandler @ 00b0e5fb */
      FUN_00b26c88(local_68,local_48,3);
                    /* try { // try from 00b0e523 to 00b0e53d has its CatchHandler @ 00b0e5ea */
      uVar2 = yaml_getSingleton();
      FUN_00b26d8c(local_88,uVar2,local_68);
                    /* try { // try from 00b0e54a to 00b0e54e has its CatchHandler @ 00b0e5d9 */
      onig_nodeInitAlt(local_38,0x3a);
                    /* try { // try from 00b0e562 to 00b0e566 has its CatchHandler @ 00b0e5c8 */
      onig_nodeAdd2(&DAT_011c2ee0,local_38,local_88);
      __cxa_guard_release(&DAT_011c2f00);
      __cxa_atexit(FUN_00b0d994,&DAT_011c2ee0,&DAT_00c89008);
      FUN_00b0d994(local_38);
      FUN_00b0d994(local_88);
      FUN_00b0d994(local_68);
      std::string::~string(local_48);
      std::allocator<char>::~allocator((allocator<char> *)&local_39);
    }
  }
  return &DAT_011c2ee0;
}


// ==== entry=00b0e63e name=FUN_00b0e63e size=105 ====

undefined * FUN_00b0e63e(void)

{
  int iVar1;
  
  if (DAT_011c2f40 == '\0') {
    iVar1 = __cxa_guard_acquire(&DAT_011c2f40);
    if (iVar1 != 0) {
                    /* try { // try from 00b0e678 to 00b0e67c has its CatchHandler @ 00b0e6a2 */
      onig_nodeInitAlt(&DAT_011c2f20,0x3a);
      __cxa_guard_release(&DAT_011c2f40);
      __cxa_atexit(FUN_00b0d994,&DAT_011c2f20,&DAT_00c89008);
    }
  }
  return &DAT_011c2f20;
}


// ==== entry=00b0e6c4 name=FUN_00b0e6c4 size=133 ====

undefined8 FUN_00b0e6c4(undefined8 param_1)

{
  int iVar1;
  
  if (DAT_011c2f80 == '\0') {
    iVar1 = __cxa_guard_acquire(&DAT_011c2f80);
    if (iVar1 != 0) {
                    /* try { // try from 00b0e706 to 00b0e70a has its CatchHandler @ 00b0e73c */
      onig_nodeInitAlt(&DAT_011c2f60,0x23);
      __cxa_guard_release(&DAT_011c2f80);
      __cxa_atexit(FUN_00b0d994,&DAT_011c2f60,&DAT_00c89008);
    }
  }
  FUN_00b0d9b4(param_1,&DAT_011c2f60);
  return param_1;
}


// ==== entry=00b0e766 name=FUN_00b0e766 size=538 ====

undefined * FUN_00b0e766(void)

{
  int iVar1;
  undefined8 uVar2;
  undefined1 local_118 [32];
  undefined1 local_f8 [32];
  undefined1 local_d8 [32];
  undefined1 local_b8 [32];
  undefined1 local_98 [32];
  string local_78 [15];
  allocator local_69;
  undefined1 local_68 [32];
  undefined1 local_48 [32];
  string local_28 [15];
  allocator local_19;
  
  if (DAT_011c2fc0 == '\0') {
    iVar1 = __cxa_guard_acquire(&DAT_011c2fc0);
    if (iVar1 != 0) {
                    /* try { // try from 00b0e7af to 00b0e7b3 has its CatchHandler @ 00b0ea34 */
      FUN_00b26bdc(local_b8);
                    /* try { // try from 00b0e7b4 to 00b0e7d4 has its CatchHandler @ 00b0ea20 */
      uVar2 = yaml_getSingleton();
      FUN_00b26d8c(local_d8,uVar2,local_b8);
      std::allocator<char>::allocator();
                    /* try { // try from 00b0e7f1 to 00b0e7f5 has its CatchHandler @ 00b0ea00 */
      std::string::string(local_78,"-?:",&local_69);
                    /* try { // try from 00b0e80c to 00b0e810 has its CatchHandler @ 00b0e9ef */
      FUN_00b26c88(local_98,local_78,3);
                    /* try { // try from 00b0e82c to 00b0e830 has its CatchHandler @ 00b0e9db */
      onig_nodeAdd2(local_f8,local_98,local_d8);
      std::allocator<char>::allocator();
                    /* try { // try from 00b0e84d to 00b0e851 has its CatchHandler @ 00b0e9bb */
      std::string::string(local_28,",[]{}#&*!|>\'\"%@`",&local_19);
                    /* try { // try from 00b0e865 to 00b0e869 has its CatchHandler @ 00b0e9aa */
      FUN_00b26c88(local_48,local_28,3);
                    /* try { // try from 00b0e86a to 00b0e884 has its CatchHandler @ 00b0e999 */
      uVar2 = yaml_getSingleton();
      FUN_00b26d8c(local_68,uVar2,local_48);
                    /* try { // try from 00b0e89d to 00b0e8a1 has its CatchHandler @ 00b0e988 */
      FUN_00b26d8c(local_118,local_68,local_f8);
                    /* try { // try from 00b0e8b4 to 00b0e8b8 has its CatchHandler @ 00b0e974 */
      FUN_00b26d2c(&DAT_011c2fa0,local_118);
      __cxa_guard_release(&DAT_011c2fc0);
      __cxa_atexit(FUN_00b0d994,&DAT_011c2fa0,&DAT_00c89008);
      FUN_00b0d994(local_118);
      FUN_00b0d994(local_68);
      FUN_00b0d994(local_48);
      std::string::~string(local_28);
      std::allocator<char>::~allocator((allocator<char> *)&local_19);
      FUN_00b0d994(local_f8);
      FUN_00b0d994(local_98);
      std::string::~string(local_78);
      std::allocator<char>::~allocator((allocator<char> *)&local_69);
      FUN_00b0d994(local_d8);
      FUN_00b0d994(local_b8);
    }
  }
  return &DAT_011c2fa0;
}


// ==== entry=00b0ea5d name=FUN_00b0ea5d size=538 ====

undefined * FUN_00b0ea5d(void)

{
  int iVar1;
  undefined8 uVar2;
  undefined1 local_118 [32];
  undefined1 local_f8 [32];
  undefined1 local_d8 [32];
  undefined1 local_b8 [32];
  undefined1 local_98 [32];
  string local_78 [15];
  allocator local_69;
  undefined1 local_68 [32];
  undefined1 local_48 [32];
  string local_28 [15];
  allocator local_19;
  
  if (DAT_011c3000 == '\0') {
    iVar1 = __cxa_guard_acquire(&DAT_011c3000);
    if (iVar1 != 0) {
                    /* try { // try from 00b0eaa6 to 00b0eaaa has its CatchHandler @ 00b0ed2b */
      FUN_00b26bdc(local_b8);
                    /* try { // try from 00b0eaab to 00b0eacb has its CatchHandler @ 00b0ed17 */
      uVar2 = FUN_00b0db18();
      FUN_00b26d8c(local_d8,uVar2,local_b8);
      std::allocator<char>::allocator();
                    /* try { // try from 00b0eae8 to 00b0eaec has its CatchHandler @ 00b0ecf7 */
      std::string::string(local_78,"-:",&local_69);
                    /* try { // try from 00b0eb03 to 00b0eb07 has its CatchHandler @ 00b0ece6 */
      FUN_00b26c88(local_98,local_78,3);
                    /* try { // try from 00b0eb23 to 00b0eb27 has its CatchHandler @ 00b0ecd2 */
      onig_nodeAdd2(local_f8,local_98,local_d8);
      std::allocator<char>::allocator();
                    /* try { // try from 00b0eb44 to 00b0eb48 has its CatchHandler @ 00b0ecb2 */
      std::string::string(local_28,"?,[]{}#&*!|>\'\"%@`",&local_19);
                    /* try { // try from 00b0eb5c to 00b0eb60 has its CatchHandler @ 00b0eca1 */
      FUN_00b26c88(local_48,local_28,3);
                    /* try { // try from 00b0eb61 to 00b0eb7b has its CatchHandler @ 00b0ec90 */
      uVar2 = yaml_getSingleton();
      FUN_00b26d8c(local_68,uVar2,local_48);
                    /* try { // try from 00b0eb94 to 00b0eb98 has its CatchHandler @ 00b0ec7f */
      FUN_00b26d8c(local_118,local_68,local_f8);
                    /* try { // try from 00b0ebab to 00b0ebaf has its CatchHandler @ 00b0ec6b */
      FUN_00b26d2c(&DAT_011c2fe0,local_118);
      __cxa_guard_release(&DAT_011c3000);
      __cxa_atexit(FUN_00b0d994,&DAT_011c2fe0,&DAT_00c89008);
      FUN_00b0d994(local_118);
      FUN_00b0d994(local_68);
      FUN_00b0d994(local_48);
      std::string::~string(local_28);
      std::allocator<char>::~allocator((allocator<char> *)&local_19);
      FUN_00b0d994(local_f8);
      FUN_00b0d994(local_98);
      std::string::~string(local_78);
      std::allocator<char>::~allocator((allocator<char> *)&local_69);
      FUN_00b0d994(local_d8);
      FUN_00b0d994(local_b8);
    }
  }
  return &DAT_011c2fe0;
}


// ==== entry=00b0ed54 name=FUN_00b0ed54 size=106 ====

void FUN_00b0ed54(undefined4 *param_1,undefined4 param_2,undefined8 *param_3)

{
  *param_1 = 0;
  param_1[1] = param_2;
  *(undefined8 *)(param_1 + 2) = *param_3;
  param_1[4] = *(undefined4 *)(param_3 + 1);
  std::string::string((string *)(param_1 + 6));
  FUN_00b0f0d6(param_1 + 8);
  param_1[0xe] = 0;
  return;
}


// ==== entry=00b0edbe name=FUN_00b0edbe size=59 ====

void FUN_00b0edbe(undefined4 *param_1,undefined4 param_2,undefined4 param_3)

{
  *param_1 = param_2;
  param_1[1] = param_3;
  param_1[2] = 0;
  *(undefined8 *)(param_1 + 4) = 0;
  return;
}


// ==== entry=00b0edfa name=FUN_00b0edfa size=35 ====

uint FUN_00b0edfa(long param_1)

{
  uint uVar1;
  
  uVar1 = FUN_00b0f0f2(param_1 + 400);
  return uVar1 ^ 1;
}


// ==== entry=00b0ee1e name=FUN_00b0ee1e size=32 ====

void FUN_00b0ee1e(long param_1)

{
  FUN_00b0f0f2(param_1 + 400);
  return;
}


// ==== entry=00b0ee3e name=FUN_00b0ee3e size=27 ====

void FUN_00b0ee3e(undefined8 param_1)

{
  FUN_00b0f128(param_1);
  return;
}


// ==== entry=00b0ee5a name=FUN_00b0ee5a size=27 ====

void FUN_00b0ee5a(undefined8 param_1)

{
  FUN_00b0f1b2(param_1);
  return;
}


// ==== entry=00b0ee76 name=FUN_00b0ee76 size=27 ====

void FUN_00b0ee76(undefined8 param_1)

{
  FUN_00b0f23c(param_1);
  return;
}


// ==== entry=00b0ee92 name=FUN_00b0ee92 size=27 ====

void FUN_00b0ee92(undefined8 param_1)

{
  FUN_00b0f2c6(param_1);
  return;
}


// ==== entry=00b0eeae name=FUN_00b0eeae size=27 ====

void FUN_00b0eeae(undefined8 param_1)

{
  FUN_00b0f326(param_1);
  return;
}


// ==== entry=00b0eec9 name=FUN_00b0eec9 size=14 ====

undefined8 FUN_00b0eec9(undefined8 param_1)

{
  return param_1;
}


// ==== entry=00b0eed8 orig=FUN_00b0eed8 size=47 name=yaml_token_dtor ====

void yaml_token_dtor(long param_1)

{
  string_vector_destroy(param_1 + 0x20);
  std::string::~string((string *)(param_1 + 0x18));
  return;
}


// ==== entry=00b0ef08 name=FUN_00b0ef08 size=41 ====

void FUN_00b0ef08(long param_1,undefined8 param_2)

{
  FUN_00b0f5f4(param_1 + 0x10,param_2);
  return;
}


// ==== entry=00b0ef32 name=FUN_00b0ef32 size=41 ====

void FUN_00b0ef32(long param_1)

{
  FUN_00b0f62a(param_1 + 0x30,param_1 + 0x10);
  return;
}


// ==== entry=00b0ef5c name=FUN_00b0ef5c size=67 ====

undefined8 FUN_00b0ef5c(undefined8 param_1,undefined8 param_2)

{
  char cVar1;
  undefined8 uVar2;
  
  cVar1 = FUN_00b0f69a(param_1,param_2);
  if (cVar1 == '\0') {
    uVar2 = 0xffffffff;
  }
  else {
    uVar2 = FUN_00b0f6b8(param_1,param_2);
  }
  return uVar2;
}


// ==== entry=00b0efa0 name=FUN_00b0efa0 size=68 ====

void FUN_00b0efa0(undefined8 *param_1)

{
  undefined8 uVar1;
  
  uVar1 = FUN_00b0f7ea(param_1);
  FUN_00b0f7f8(*param_1,param_1[1],uVar1);
  FUN_00b0f79c(param_1);
  return;
}


// ==== entry=00b0efe4 name=FUN_00b0efe4 size=190 ====

void FUN_00b0efe4(undefined8 *param_1,undefined8 param_2)

{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined1 local_29 [9];
  
  uVar1 = FUN_00b0f86e(param_2);
  FUN_00b0f845(local_29,uVar1);
  uVar1 = FUN_00b0f822(param_2);
                    /* try { // try from 00b0f037 to 00b0f03b has its CatchHandler @ 00b0f097 */
  FUN_00b0f898(param_1,uVar1,local_29);
  FUN_00b0f87c(local_29);
  uVar2 = FUN_00b0f7ea(param_1);
  uVar1 = *param_1;
  uVar3 = FUN_00b0f926(param_2);
  uVar4 = FUN_00b0f8f6(param_2);
                    /* try { // try from 00b0f085 to 00b0f089 has its CatchHandler @ 00b0f0b1 */
  uVar1 = FUN_00b0f957(uVar4,uVar3,uVar1,uVar2);
  param_1[1] = uVar1;
  return;
}


// ==== entry=00b0f0d6 name=FUN_00b0f0d6 size=27 ====

void FUN_00b0f0d6(undefined8 param_1)

{
  FUN_00b0f9a4(param_1);
  return;
}


// ==== entry=00b0f0f2 name=FUN_00b0f0f2 size=26 ====

void FUN_00b0f0f2(undefined8 param_1)

{
  FUN_00b0fa46(param_1);
  return;
}


// ==== entry=00b0f10c name=FUN_00b0f10c size=27 ====

void FUN_00b0f10c(undefined8 param_1)

{
  FUN_00b0fa70(param_1);
  return;
}


// ==== entry=00b0f128 name=FUN_00b0f128 size=109 ====

void FUN_00b0f128(undefined8 param_1)

{
  undefined8 uVar1;
  undefined1 local_58 [32];
  undefined1 local_38 [40];
  
  uVar1 = FUN_00b0fb6c(param_1);
  FUN_00b0fb3e(local_58,param_1);
  FUN_00b0fb10(local_38,param_1);
  FUN_00b0fbc8(param_1,local_38,local_58,uVar1);
  FUN_00b0faa8(param_1);
  return;
}


// ==== entry=00b0f196 name=FUN_00b0f196 size=27 ====

void FUN_00b0f196(undefined8 param_1)

{
  FUN_00b0fc20(param_1);
  return;
}


// ==== entry=00b0f1b2 name=FUN_00b0f1b2 size=109 ====

void FUN_00b0f1b2(undefined8 param_1)

{
  undefined8 uVar1;
  undefined1 local_58 [32];
  undefined1 local_38 [40];
  
  uVar1 = FUN_00b0fd1c(param_1);
  FUN_00b0fcee(local_58,param_1);
  FUN_00b0fcc0(local_38,param_1);
  FUN_00b0fd78(param_1,local_38,local_58,uVar1);
  FUN_00b0fc58(param_1);
  return;
}


// ==== entry=00b0f220 name=FUN_00b0f220 size=27 ====

void FUN_00b0f220(undefined8 param_1)

{
  FUN_00b0fd90(param_1);
  return;
}


// ==== entry=00b0f23c name=FUN_00b0f23c size=109 ====

void FUN_00b0f23c(undefined8 param_1)

{
  undefined8 uVar1;
  undefined1 local_58 [32];
  undefined1 local_38 [40];
  
  uVar1 = FUN_00b0fe8c(param_1);
  FUN_00b0fe5e(local_58,param_1);
  FUN_00b0fe30(local_38,param_1);
  FUN_00b0fee8(param_1,local_38,local_58,uVar1);
  FUN_00b0fdc8(param_1);
  return;
}


// ==== entry=00b0f2aa name=FUN_00b0f2aa size=27 ====

void FUN_00b0f2aa(undefined8 param_1)

{
  FUN_00b0ff00(param_1);
  return;
}


// ==== entry=00b0f2c6 name=FUN_00b0f2c6 size=68 ====

void FUN_00b0f2c6(undefined8 *param_1)

{
  undefined8 uVar1;
  
  uVar1 = FUN_00b0ff86(param_1);
  FUN_00b0ff94(*param_1,param_1[1],uVar1);
  FUN_00b0ff38(param_1);
  return;
}


// ==== entry=00b0f30a name=FUN_00b0f30a size=27 ====

void FUN_00b0f30a(undefined8 param_1)

{
  FUN_00b0ffbe(param_1);
  return;
}


// ==== entry=00b0f326 name=FUN_00b0f326 size=109 ====

void FUN_00b0f326(undefined8 param_1)

{
  undefined8 uVar1;
  undefined1 local_58 [32];
  undefined1 local_38 [40];
  
  uVar1 = FUN_00b100ba(param_1);
  FUN_00b1008c(local_58,param_1);
  FUN_00b1005e(local_38,param_1);
  FUN_00b10116(param_1,local_38,local_58,uVar1);
  FUN_00b0fff6(param_1);
  return;
}


// ==== entry=00b0f394 name=FUN_00b0f394 size=26 ====

void FUN_00b0f394(undefined8 param_1)

{
  FUN_00b1012e(param_1);
  return;
}


// ==== entry=00b0f3ae name=FUN_00b0f3ae size=27 ====

void FUN_00b0f3ae(undefined8 param_1)

{
  FUN_00b10158(param_1);
  return;
}


// ==== entry=00b0f3ca name=FUN_00b0f3ca size=26 ====

void FUN_00b0f3ca(undefined8 param_1)

{
  FUN_00b101ba(param_1);
  return;
}


// ==== entry=00b0f3e4 name=FUN_00b0f3e4 size=38 ====

void FUN_00b0f3e4(undefined8 param_1,undefined8 param_2)

{
  FUN_00b101e8(param_1,param_2);
  return;
}


// ==== entry=00b0f40a name=FUN_00b0f40a size=87 ====

void FUN_00b0f40a(undefined8 param_1)

{
  long *plVar1;
  undefined8 uVar2;
  
  plVar1 = (long *)FUN_00b1021e(param_1);
  if (*plVar1 != 0) {
    uVar2 = FUN_00b10238(param_1);
    FUN_00b10252(uVar2,*plVar1);
  }
  *plVar1 = 0;
  return;
}


// ==== entry=00b0f462 name=FUN_00b0f462 size=52 ====

void FUN_00b0f462(undefined8 param_1,undefined8 param_2)

{
  undefined8 uVar1;
  
  uVar1 = FUN_00b0eec9(param_2);
  FUN_00b10272(param_1,uVar1);
  return;
}


// ==== entry=00b0f496 name=FUN_00b0f496 size=34 ====

void FUN_00b0f496(undefined8 param_1)

{
  undefined8 uVar1;
  
  uVar1 = FUN_00b102a4(param_1);
  FUN_00b102e4(uVar1);
  return;
}


// ==== entry=00b0f4b8 name=FUN_00b0f4b8 size=14 ====

undefined8 FUN_00b0f4b8(undefined8 param_1)

{
  return param_1;
}


// ==== entry=00b0f4c6 name=FUN_00b0f4c6 size=52 ====

void FUN_00b0f4c6(undefined8 param_1,undefined8 param_2)

{
  undefined8 uVar1;
  
  uVar1 = FUN_00b0f4b8(param_2);
  FUN_00b102fe(param_1,uVar1);
  return;
}


// ==== entry=00b0f4fa name=FUN_00b0f4fa size=14 ====

undefined8 FUN_00b0f4fa(undefined8 param_1)

{
  return param_1;
}


// ==== entry=00b0f508 name=FUN_00b0f508 size=52 ====

void FUN_00b0f508(undefined8 param_1,undefined8 param_2)

{
  undefined8 uVar1;
  
  uVar1 = FUN_00b0f4fa(param_2);
  FUN_00b10330(param_1,uVar1);
  return;
}


// ==== entry=00b0f53c name=FUN_00b0f53c size=26 ====

void FUN_00b0f53c(undefined8 param_1)

{
  FUN_00b10362(param_1);
  return;
}


// ==== entry=00b0f556 name=FUN_00b0f556 size=26 ====

void FUN_00b0f556(undefined8 param_1)

{
  FUN_00b102e4(param_1);
  return;
}


// ==== entry=00b0f570 name=FUN_00b0f570 size=26 ====

void FUN_00b0f570(undefined8 param_1)

{
  FUN_00b1039c(param_1);
  return;
}


// ==== entry=00b0f58a name=FUN_00b0f58a size=26 ====

void FUN_00b0f58a(undefined8 param_1)

{
  FUN_00b103d6(param_1);
  return;
}


// ==== entry=00b0f5a4 name=FUN_00b0f5a4 size=27 ====

void FUN_00b0f5a4(undefined8 param_1)

{
  FUN_00b10400(param_1);
  return;
}


// ==== entry=00b0f5c0 name=FUN_00b0f5c0 size=26 ====

void FUN_00b0f5c0(undefined8 param_1)

{
  FUN_00b1045e(param_1);
  return;
}


// ==== entry=00b0f5da name=FUN_00b0f5da size=26 ====

void FUN_00b0f5da(undefined8 param_1)

{
  FUN_00b10498(param_1);
  return;
}


// ==== entry=00b0f5f4 name=FUN_00b0f5f4 size=54 ====

void FUN_00b0f5f4(undefined8 param_1,undefined8 param_2)

{
  undefined1 local_28 [32];
  
  FUN_00b104c6(local_28,param_1,param_2);
  FUN_00b10518(local_28);
  return;
}


// ==== entry=00b0f62a name=FUN_00b0f62a size=112 ====

long FUN_00b0f62a(long *param_1,long *param_2)

{
  long lVar1;
  
  lVar1 = FUN_00b10529();
  return (param_2[2] - *param_2) +
         lVar1 * ((param_1[3] - param_2[3] >> 3) + -1) + (*param_1 - param_1[1]);
}


// ==== entry=00b0f69a name=FUN_00b0f69a size=30 ====

void FUN_00b0f69a(undefined8 param_1,undefined8 param_2)

{
  FUN_00b0d8b6(param_2);
  return;
}


// ==== entry=00b0f6b8 name=FUN_00b0f6b8 size=200 ====

undefined8 FUN_00b0f6b8(undefined4 *param_1,undefined8 param_2)

{
  undefined8 uVar1;
  
  switch(*param_1) {
  case 0:
    uVar1 = FUN_00b1053a(param_1,param_2);
    break;
  case 1:
    uVar1 = FUN_00b1057a(param_1,param_2);
    break;
  case 2:
    uVar1 = FUN_00b105bc(param_1,param_2);
    break;
  case 3:
    uVar1 = FUN_00b1062a(param_1,param_2);
    break;
  case 4:
    uVar1 = FUN_00b106c4(param_1,param_2);
    break;
  case 5:
    uVar1 = FUN_00b10750(param_1,param_2);
    break;
  case 6:
    uVar1 = FUN_00b107ba(param_1,param_2);
    break;
  default:
    uVar1 = 0xffffffff;
  }
  return uVar1;
}


// ==== entry=00b0f780 name=FUN_00b0f780 size=27 ====

void FUN_00b0f780(undefined8 param_1)

{
  FUN_00b0f87c(param_1);
  return;
}


// ==== entry=00b0f79c name=FUN_00b0f79c size=77 ====

void FUN_00b0f79c(long *param_1)

{
  FUN_00b1087a(param_1,*param_1,param_1[2] - *param_1 >> 5);
  FUN_00b0f780(param_1);
  return;
}


// ==== entry=00b0f7ea name=FUN_00b0f7ea size=14 ====

undefined8 FUN_00b0f7ea(undefined8 param_1)

{
  return param_1;
}


// ==== entry=00b0f7f8 name=FUN_00b0f7f8 size=42 ====

void FUN_00b0f7f8(undefined8 param_1,undefined8 param_2)

{
  FUN_00b108af(param_1,param_2);
  return;
}


// ==== entry=00b0f822 name=FUN_00b0f822 size=35 ====

long FUN_00b0f822(long *param_1)

{
  return param_1[1] - *param_1 >> 5;
}


// ==== entry=00b0f845 name=FUN_00b0f845 size=41 ====

undefined8 FUN_00b0f845(undefined8 param_1,undefined8 param_2)

{
  FUN_00b108d5(param_1,param_2);
  return param_1;
}


// ==== entry=00b0f86e name=FUN_00b0f86e size=14 ====

undefined8 FUN_00b0f86e(undefined8 param_1)

{
  return param_1;
}


// ==== entry=00b0f87c name=FUN_00b0f87c size=27 ====

void FUN_00b0f87c(undefined8 param_1)

{
  FUN_00b10924(param_1);
  return;
}


// ==== entry=00b0f898 name=FUN_00b0f898 size=68 ====

void FUN_00b0f898(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  FUN_00b10930(param_1,param_3);
                    /* try { // try from 00b0f8ce to 00b0f8d2 has its CatchHandler @ 00b0f8d5 */
  FUN_00b1097a(param_1,param_2);
  return;
}


// ==== entry=00b0f8f6 name=FUN_00b0f8f6 size=48 ====

undefined8 FUN_00b0f8f6(undefined8 *param_1)

{
  undefined8 local_18;
  undefined8 local_10;
  
  local_10 = *param_1;
  FUN_00b109d4(&local_18,&local_10);
  return local_18;
}


// ==== entry=00b0f926 name=FUN_00b0f926 size=49 ====

undefined8 FUN_00b0f926(long param_1)

{
  undefined8 local_18;
  undefined8 local_10;
  
  local_10 = *(undefined8 *)(param_1 + 8);
  FUN_00b109d4(&local_18,&local_10);
  return local_18;
}


// ==== entry=00b0f957 name=FUN_00b0f957 size=49 ====

void FUN_00b0f957(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  FUN_00b109f1(param_1,param_2,param_3);
  return;
}


// ==== entry=00b0f988 name=FUN_00b0f988 size=27 ====

void FUN_00b0f988(undefined8 param_1)

{
  FUN_00b10a60(param_1);
  return;
}


// ==== entry=00b0f9a4 name=FUN_00b0f9a4 size=27 ====

void FUN_00b0f9a4(undefined8 param_1)

{
  FUN_00b10a22(param_1);
  return;
}


// ==== entry=00b0f9c0 name=FUN_00b0f9c0 size=77 ====

void FUN_00b0f9c0(long *param_1)

{
  FUN_00b10a7c(param_1,*param_1,param_1[2] - *param_1 >> 3);
  FUN_00b0f988(param_1);
  return;
}


// ==== entry=00b0fa0e name=FUN_00b0fa0e size=14 ====

undefined8 FUN_00b0fa0e(undefined8 param_1)

{
  return param_1;
}


// ==== entry=00b0fa1c name=FUN_00b0fa1c size=42 ====

void FUN_00b0fa1c(undefined8 param_1,undefined8 param_2)

{
  FUN_00b10ab1(param_1,param_2);
  return;
}


// ==== entry=00b0fa46 name=FUN_00b0fa46 size=41 ====

void FUN_00b0fa46(long param_1)

{
  FUN_00b10ad7(param_1 + 0x30,param_1 + 0x10);
  return;
}


// ==== entry=00b0fa70 name=FUN_00b0fa70 size=27 ====

void FUN_00b0fa70(undefined8 param_1)

{
  FUN_00b10afa(param_1);
  return;
}


// ==== entry=00b0fa8c name=FUN_00b0fa8c size=27 ====

void FUN_00b0fa8c(undefined8 param_1)

{
  FUN_00b10b48(param_1);
  return;
}


// ==== entry=00b0faa8 name=FUN_00b0faa8 size=104 ====

void FUN_00b0faa8(long *param_1)

{
  if (*param_1 != 0) {
    FUN_00b10b64(param_1,param_1[5],param_1[9] + 8);
    FUN_00b10baa(param_1,*param_1,param_1[1]);
  }
  FUN_00b0fa8c(param_1);
  return;
}


// ==== entry=00b0fb10 name=FUN_00b0fb10 size=45 ====

undefined8 FUN_00b0fb10(undefined8 param_1,long param_2)

{
  FUN_00b0fb7a(param_1,param_2 + 0x10);
  return param_1;
}


// ==== entry=00b0fb3e name=FUN_00b0fb3e size=45 ====

undefined8 FUN_00b0fb3e(undefined8 param_1,long param_2)

{
  FUN_00b0fb7a(param_1,param_2 + 0x30);
  return param_1;
}


// ==== entry=00b0fb6c name=FUN_00b0fb6c size=14 ====

undefined8 FUN_00b0fb6c(undefined8 param_1)

{
  return param_1;
}


// ==== entry=00b0fb7a name=FUN_00b0fb7a size=77 ====

void FUN_00b0fb7a(undefined8 *param_1,undefined8 *param_2)

{
  *param_1 = *param_2;
  param_1[1] = param_2[1];
  param_1[2] = param_2[2];
  param_1[3] = param_2[3];
  return;
}


// ==== entry=00b0fbc8 name=FUN_00b0fbc8 size=88 ====

void FUN_00b0fbc8(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  undefined1 local_48 [32];
  undefined1 local_28 [32];
  
  FUN_00b0fb7a(local_48,param_3);
  FUN_00b0fb7a(local_28,param_2);
  FUN_00b10bf8(param_1,local_28,local_48);
  return;
}


// ==== entry=00b0fc20 name=FUN_00b0fc20 size=27 ====

void FUN_00b0fc20(undefined8 param_1)

{
  FUN_00b10d08(param_1);
  return;
}


// ==== entry=00b0fc3c name=FUN_00b0fc3c size=27 ====

void FUN_00b0fc3c(undefined8 param_1)

{
  FUN_00b10d56(param_1);
  return;
}


// ==== entry=00b0fc58 name=FUN_00b0fc58 size=104 ====

void FUN_00b0fc58(long *param_1)

{
  if (*param_1 != 0) {
    FUN_00b10d72(param_1,param_1[5],param_1[9] + 8);
    FUN_00b10db8(param_1,*param_1,param_1[1]);
  }
  FUN_00b0fc3c(param_1);
  return;
}


// ==== entry=00b0fcc0 name=FUN_00b0fcc0 size=45 ====

undefined8 FUN_00b0fcc0(undefined8 param_1,long param_2)

{
  FUN_00b0fd2a(param_1,param_2 + 0x10);
  return param_1;
}


// ==== entry=00b0fcee name=FUN_00b0fcee size=45 ====

undefined8 FUN_00b0fcee(undefined8 param_1,long param_2)

{
  FUN_00b0fd2a(param_1,param_2 + 0x30);
  return param_1;
}


// ==== entry=00b0fd1c name=FUN_00b0fd1c size=14 ====

undefined8 FUN_00b0fd1c(undefined8 param_1)

{
  return param_1;
}


// ==== entry=00b0fd2a name=FUN_00b0fd2a size=77 ====

void FUN_00b0fd2a(undefined8 *param_1,undefined8 *param_2)

{
  *param_1 = *param_2;
  param_1[1] = param_2[1];
  param_1[2] = param_2[2];
  param_1[3] = param_2[3];
  return;
}


// ==== entry=00b0fd78 name=FUN_00b0fd78 size=23 ====

void FUN_00b0fd78(void)

{
  return;
}


// ==== entry=00b0fd90 name=FUN_00b0fd90 size=27 ====

void FUN_00b0fd90(undefined8 param_1)

{
  FUN_00b10e06(param_1);
  return;
}


// ==== entry=00b0fdac name=FUN_00b0fdac size=27 ====

void FUN_00b0fdac(undefined8 param_1)

{
  FUN_00b10e54(param_1);
  return;
}


// ==== entry=00b0fdc8 name=FUN_00b0fdc8 size=104 ====

void FUN_00b0fdc8(long *param_1)

{
  if (*param_1 != 0) {
    FUN_00b10e70(param_1,param_1[5],param_1[9] + 8);
    FUN_00b10eb6(param_1,*param_1,param_1[1]);
  }
  FUN_00b0fdac(param_1);
  return;
}


// ==== entry=00b0fe30 name=FUN_00b0fe30 size=45 ====

undefined8 FUN_00b0fe30(undefined8 param_1,long param_2)

{
  FUN_00b0fe9a(param_1,param_2 + 0x10);
  return param_1;
}


// ==== entry=00b0fe5e name=FUN_00b0fe5e size=45 ====

undefined8 FUN_00b0fe5e(undefined8 param_1,long param_2)

{
  FUN_00b0fe9a(param_1,param_2 + 0x30);
  return param_1;
}


// ==== entry=00b0fe8c name=FUN_00b0fe8c size=14 ====

undefined8 FUN_00b0fe8c(undefined8 param_1)

{
  return param_1;
}


// ==== entry=00b0fe9a name=FUN_00b0fe9a size=77 ====

void FUN_00b0fe9a(undefined8 *param_1,undefined8 *param_2)

{
  *param_1 = *param_2;
  param_1[1] = param_2[1];
  param_1[2] = param_2[2];
  param_1[3] = param_2[3];
  return;
}


// ==== entry=00b0fee8 name=FUN_00b0fee8 size=23 ====

void FUN_00b0fee8(void)

{
  return;
}


// ==== entry=00b0ff00 name=FUN_00b0ff00 size=27 ====

void FUN_00b0ff00(undefined8 param_1)

{
  FUN_00b10f04(param_1);
  return;
}


// ==== entry=00b0ff1c name=FUN_00b0ff1c size=27 ====

void FUN_00b0ff1c(undefined8 param_1)

{
  FUN_00b10f20(param_1);
  return;
}


// ==== entry=00b0ff38 name=FUN_00b0ff38 size=77 ====

void FUN_00b0ff38(long *param_1)

{
  FUN_00b10f3c(param_1,*param_1,param_1[2] - *param_1 >> 3);
  FUN_00b0ff1c(param_1);
  return;
}


// ==== entry=00b0ff86 name=FUN_00b0ff86 size=14 ====

undefined8 FUN_00b0ff86(undefined8 param_1)

{
  return param_1;
}


// ==== entry=00b0ff94 name=FUN_00b0ff94 size=42 ====

void FUN_00b0ff94(undefined8 param_1,undefined8 param_2)

{
  FUN_00b10f71(param_1,param_2);
  return;
}


// ==== entry=00b0ffbe name=FUN_00b0ffbe size=27 ====

void FUN_00b0ffbe(undefined8 param_1)

{
  FUN_00b10f98(param_1);
  return;
}


// ==== entry=00b0ffda name=FUN_00b0ffda size=27 ====

void FUN_00b0ffda(undefined8 param_1)

{
  FUN_00b10fe6(param_1);
  return;
}


// ==== entry=00b0fff6 name=FUN_00b0fff6 size=104 ====

void FUN_00b0fff6(long *param_1)

{
  if (*param_1 != 0) {
    FUN_00b11002(param_1,param_1[5],param_1[9] + 8);
    FUN_00b11048(param_1,*param_1,param_1[1]);
  }
  FUN_00b0ffda(param_1);
  return;
}


// ==== entry=00b1005e name=FUN_00b1005e size=45 ====

undefined8 FUN_00b1005e(undefined8 param_1,long param_2)

{
  FUN_00b100c8(param_1,param_2 + 0x10);
  return param_1;
}


// ==== entry=00b1008c name=FUN_00b1008c size=45 ====

undefined8 FUN_00b1008c(undefined8 param_1,long param_2)

{
  FUN_00b100c8(param_1,param_2 + 0x30);
  return param_1;
}


// ==== entry=00b100ba name=FUN_00b100ba size=14 ====

undefined8 FUN_00b100ba(undefined8 param_1)

{
  return param_1;
}


// ==== entry=00b100c8 name=FUN_00b100c8 size=77 ====

void FUN_00b100c8(undefined8 *param_1,undefined8 *param_2)

{
  *param_1 = *param_2;
  param_1[1] = param_2[1];
  param_1[2] = param_2[2];
  param_1[3] = param_2[3];
  return;
}


// ==== entry=00b10116 name=FUN_00b10116 size=23 ====

void FUN_00b10116(void)

{
  return;
}


// ==== entry=00b1012e name=FUN_00b1012e size=41 ====

void FUN_00b1012e(long param_1)

{
  FUN_00b11095(param_1 + 0x30,param_1 + 0x10);
  return;
}


// ==== entry=00b10158 name=FUN_00b10158 size=97 ====

void FUN_00b10158(long param_1)

{
  if (*(long *)(param_1 + 0x10) == *(long *)(param_1 + 0x20) + -0x40) {
    FUN_00b110de(param_1);
  }
  else {
    FUN_00b110b7(param_1,*(undefined8 *)(param_1 + 0x10));
    *(long *)(param_1 + 0x10) = *(long *)(param_1 + 0x10) + 0x40;
  }
  return;
}


// ==== entry=00b101ba name=FUN_00b101ba size=46 ====

void FUN_00b101ba(undefined8 param_1)

{
  undefined1 local_28 [32];
  
  FUN_00b0fb10(local_28,param_1);
  FUN_00b11158(local_28);
  return;
}


// ==== entry=00b101e8 name=FUN_00b101e8 size=53 ====

void FUN_00b101e8(undefined8 param_1,undefined8 param_2)

{
  undefined8 *puVar1;
  
  FUN_00b1116a(param_1);
  puVar1 = (undefined8 *)FUN_00b1021e(param_1);
  *puVar1 = param_2;
  return;
}


// ==== entry=00b1021e name=FUN_00b1021e size=26 ====

void FUN_00b1021e(undefined8 param_1)

{
  FUN_00b11185(param_1);
  return;
}


// ==== entry=00b10238 name=FUN_00b10238 size=26 ====

void FUN_00b10238(undefined8 param_1)

{
  FUN_00b111a0(param_1);
  return;
}


// ==== entry=00b10252 name=FUN_00b10252 size=31 ====

void FUN_00b10252(undefined8 param_1,void *param_2)

{
  operator_delete(param_2);
  return;
}


// ==== entry=00b10272 name=FUN_00b10272 size=49 ====

void FUN_00b10272(undefined8 param_1,undefined8 param_2)

{
  undefined8 uVar1;
  
  uVar1 = FUN_00b0eec9(param_2);
  FUN_00b111c8(param_1,uVar1);
  return;
}


// ==== entry=00b102a4 name=FUN_00b102a4 size=64 ====

void FUN_00b102a4(undefined8 param_1)

{
  undefined8 local_18;
  undefined8 local_10;
  
  local_10 = FUN_00b11262(param_1);
  local_18 = FUN_00b1128c(&local_10,1);
  FUN_00b112ce(&local_18);
  return;
}


// ==== entry=00b102e4 name=FUN_00b102e4 size=26 ====

void FUN_00b102e4(undefined8 param_1)

{
  FUN_00b112e0(param_1);
  return;
}


// ==== entry=00b102fe name=FUN_00b102fe size=49 ====

void FUN_00b102fe(undefined8 param_1,undefined8 param_2)

{
  undefined8 uVar1;
  
  uVar1 = FUN_00b0f4b8(param_2);
  FUN_00b1130c(param_1,uVar1);
  return;
}


// ==== entry=00b10330 name=FUN_00b10330 size=49 ====

void FUN_00b10330(undefined8 param_1,undefined8 param_2)

{
  undefined8 uVar1;
  
  uVar1 = FUN_00b0f4fa(param_2);
  FUN_00b113a0(param_1,uVar1);
  return;
}


// ==== entry=00b10362 name=FUN_00b10362 size=58 ====

void FUN_00b10362(undefined8 param_1)

{
  undefined1 local_28 [32];
  
  FUN_00b0fb3e(local_28,param_1);
  FUN_00b11426(local_28);
  FUN_00b11158(local_28);
  return;
}


// ==== entry=00b1039c name=FUN_00b1039c size=58 ====

void FUN_00b1039c(undefined8 param_1)

{
  undefined1 local_28 [32];
  
  FUN_00b0fe5e(local_28,param_1);
  FUN_00b11488(local_28);
  FUN_00b114ea(local_28);
  return;
}


// ==== entry=00b103d6 name=FUN_00b103d6 size=41 ====

void FUN_00b103d6(long param_1)

{
  FUN_00b114fb(param_1 + 0x30,param_1 + 0x10);
  return;
}


// ==== entry=00b10400 name=FUN_00b10400 size=93 ====

void FUN_00b10400(long param_1)

{
  if (*(long *)(param_1 + 0x30) == *(long *)(param_1 + 0x38)) {
    FUN_00b11544(param_1);
  }
  else {
    *(long *)(param_1 + 0x30) = *(long *)(param_1 + 0x30) + -8;
    FUN_00b1151d(param_1,*(undefined8 *)(param_1 + 0x30));
  }
  return;
}


// ==== entry=00b1045e name=FUN_00b1045e size=58 ====

void FUN_00b1045e(undefined8 param_1)

{
  undefined1 local_28 [32];
  
  FUN_00b115c2(local_28,param_1);
  FUN_00b115f0(local_28);
  FUN_00b11652(local_28);
  return;
}


// ==== entry=00b10498 name=FUN_00b10498 size=46 ====

void FUN_00b10498(undefined8 param_1)

{
  undefined1 local_28 [32];
  
  FUN_00b11664(local_28,param_1);
  FUN_00b11692(local_28);
  return;
}


// ==== entry=00b104c6 name=FUN_00b104c6 size=82 ====

undefined8 FUN_00b104c6(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  undefined8 uVar1;
  undefined1 local_28 [32];
  
  FUN_00b116a4(local_28,param_2);
  uVar1 = FUN_00b116f2(local_28,param_3);
  FUN_00b116a4(param_1,uVar1);
  return param_1;
}


// ==== entry=00b10518 name=FUN_00b10518 size=17 ====

undefined8 FUN_00b10518(undefined8 *param_1)

{
  return *param_1;
}


// ==== entry=00b10529 name=FUN_00b10529 size=16 ====

void FUN_00b10529(void)

{
  FUN_00b0d748(1);
  return;
}


// ==== entry=00b1053a name=FUN_00b1053a size=64 ====

undefined8 FUN_00b1053a(undefined8 param_1,undefined8 param_2)

{
  char cVar1;
  char cVar2;
  undefined8 uVar3;
  
  cVar1 = FUN_00b0d882(param_2,0);
  cVar2 = FUN_00b0d78f();
  if (cVar1 == cVar2) {
    uVar3 = 0;
  }
  else {
    uVar3 = 0xffffffff;
  }
  return uVar3;
}


// ==== entry=00b1057a name=FUN_00b1057a size=66 ====

undefined8 FUN_00b1057a(long param_1,undefined8 param_2)

{
  char cVar1;
  undefined8 uVar2;
  
  cVar1 = FUN_00b0d882(param_2,0);
  if (cVar1 == *(char *)(param_1 + 4)) {
    uVar2 = 1;
  }
  else {
    uVar2 = 0xffffffff;
  }
  return uVar2;
}


// ==== entry=00b105bc name=FUN_00b105bc size=110 ====

undefined8 FUN_00b105bc(long param_1,undefined8 param_2)

{
  char cVar1;
  bool bVar2;
  char cVar3;
  undefined8 uVar4;
  
  cVar1 = *(char *)(param_1 + 4);
  cVar3 = FUN_00b0d882(param_2,0);
  if (cVar1 <= cVar3) {
    cVar1 = *(char *)(param_1 + 5);
    cVar3 = FUN_00b0d882(param_2,0);
    if (cVar3 <= cVar1) {
      bVar2 = false;
      goto LAB_00b10613;
    }
  }
  bVar2 = true;
LAB_00b10613:
  if (bVar2) {
    uVar4 = 0xffffffff;
  }
  else {
    uVar4 = 1;
  }
  return uVar4;
}


// ==== entry=00b1062a name=FUN_00b1062a size=153 ====

int FUN_00b1062a(long param_1,undefined8 param_2)

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
    local_1c = FUN_00b0f6b8(local_18,param_2);
    if (-1 < local_1c) break;
    FUN_00b1182a(&local_28);
  }
  return local_1c;
}


// ==== entry=00b106c4 name=FUN_00b106c4 size=140 ====

int FUN_00b106c4(long param_1,undefined8 param_2)

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
    iVar1 = FUN_00b0f6b8(uVar3,param_2);
    if (iVar1 == -1) break;
    if (local_18 == 0) {
      local_c = iVar1;
    }
    local_18 = local_18 + 1;
  }
  return -1;
}


// ==== entry=00b10750 name=FUN_00b10750 size=105 ====

undefined8 FUN_00b10750(long param_1,undefined8 param_2)

{
  char cVar1;
  int iVar2;
  undefined8 uVar3;
  
  cVar1 = FUN_00b1187c(param_1 + 8);
  if (cVar1 == '\0') {
    uVar3 = FUN_00b1185c(param_1 + 8,0);
    iVar2 = FUN_00b0f6b8(uVar3,param_2);
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


// ==== entry=00b107ba name=FUN_00b107ba size=191 ====

int FUN_00b107ba(long param_1,undefined8 param_2)

{
  char cVar1;
  undefined1 auVar2 [16];
  undefined8 local_48;
  undefined8 local_40;
  undefined1 local_38 [16];
  int local_24;
  undefined8 local_20;
  long local_18;
  int local_c;
  
  local_c = 0;
  local_18 = param_1 + 8;
  local_40 = FUN_00b0f8f6(local_18);
  local_48 = FUN_00b0f926(local_18);
  while( true ) {
    cVar1 = FUN_00b117ee(&local_40,&local_48);
    if (cVar1 == '\0') {
      return local_c;
    }
    local_20 = FUN_00b1184a(&local_40);
    auVar2 = FUN_00b0d8de(param_2,local_c);
    local_38 = auVar2;
    local_24 = FUN_00b0ef5c(local_20,local_38);
    if (local_24 == -1) break;
    local_c = local_c + local_24;
    FUN_00b1182a(&local_40);
  }
  return -1;
}


// ==== entry=00b1087a name=FUN_00b1087a size=53 ====

void FUN_00b1087a(undefined8 param_1,long param_2,undefined8 param_3)

{
  if (param_2 != 0) {
    FUN_00b118be(param_1,param_2,param_3);
  }
  return;
}


// ==== entry=00b108af name=FUN_00b108af size=38 ====

void FUN_00b108af(undefined8 param_1,undefined8 param_2)

{
  FUN_00b118fa(param_1,param_2);
  return;
}


// ==== entry=00b108d5 name=FUN_00b108d5 size=41 ====

undefined8 FUN_00b108d5(undefined8 param_1,undefined8 param_2)

{
  FUN_00b108fe(param_1,param_2);
  return param_1;
}


// ==== entry=00b108fe name=FUN_00b108fe size=38 ====

void FUN_00b108fe(undefined8 param_1,undefined8 param_2)

{
  FUN_00b11932(param_1,param_2);
  return;
}


// ==== entry=00b10924 name=FUN_00b10924 size=11 ====

void FUN_00b10924(void)

{
  return;
}


// ==== entry=00b10930 name=FUN_00b10930 size=73 ====

void FUN_00b10930(undefined8 *param_1,undefined8 param_2)

{
  FUN_00b108fe(param_1,param_2);
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  return;
}


// ==== entry=00b1097a name=FUN_00b1097a size=89 ====

void FUN_00b1097a(long *param_1,long param_2)

{
  long lVar1;
  
  lVar1 = FUN_00b11942(param_1,param_2);
  *param_1 = lVar1;
  param_1[1] = *param_1;
  param_1[2] = param_2 * 0x20 + *param_1;
  return;
}


// ==== entry=00b109d4 name=FUN_00b109d4 size=29 ====

void FUN_00b109d4(undefined8 *param_1,undefined8 *param_2)

{
  *param_1 = *param_2;
  return;
}


// ==== entry=00b109f1 name=FUN_00b109f1 size=49 ====

void FUN_00b109f1(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  FUN_00b11975(param_1,param_2,param_3);
  return;
}


// ==== entry=00b10a22 name=FUN_00b10a22 size=62 ====

void FUN_00b10a22(undefined8 *param_1)

{
  FUN_00b11a22(param_1);
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  return;
}


// ==== entry=00b10a60 name=FUN_00b10a60 size=27 ====

void FUN_00b10a60(undefined8 param_1)

{
  FUN_00b11a3e(param_1);
  return;
}


// ==== entry=00b10a7c name=FUN_00b10a7c size=53 ====

void FUN_00b10a7c(undefined8 param_1,long param_2,undefined8 param_3)

{
  if (param_2 != 0) {
    FUN_00b11a49(param_1,param_2,param_3);
  }
  return;
}


// ==== entry=00b10ab1 name=FUN_00b10ab1 size=38 ====

void FUN_00b10ab1(undefined8 param_1,undefined8 param_2)

{
  FUN_00b11a85(param_1,param_2);
  return;
}


// ==== entry=00b10ad7 name=FUN_00b10ad7 size=34 ====

undefined8 FUN_00b10ad7(long *param_1,long *param_2)

{
  return CONCAT71((int7)((ulong)*param_2 >> 8),*param_1 == *param_2);
}


// ==== entry=00b10afa name=FUN_00b10afa size=51 ====

void FUN_00b10afa(undefined8 param_1)

{
  FUN_00b11ace(param_1);
                    /* try { // try from 00b10b1f to 00b10b23 has its CatchHandler @ 00b10b26 */
  FUN_00b11b20(param_1,0);
  return;
}


// ==== entry=00b10b48 name=FUN_00b10b48 size=27 ====

void FUN_00b10b48(undefined8 param_1)

{
  FUN_00b11cc8(param_1);
  return;
}


// ==== entry=00b10b64 name=FUN_00b10b64 size=70 ====

void FUN_00b10b64(undefined8 param_1,undefined8 *param_2,undefined8 *param_3)

{
  undefined8 *local_10;
  
  for (local_10 = param_2; local_10 < param_3; local_10 = local_10 + 1) {
    FUN_00b11cd4(param_1,*local_10);
  }
  return;
}


// ==== entry=00b10baa name=FUN_00b10baa size=77 ====

void FUN_00b10baa(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  undefined1 local_9;
  
  FUN_00b11d08(&local_9,param_1);
  FUN_00b11d57(&local_9,param_2,param_3);
  FUN_00b11d3c(&local_9);
  return;
}


// ==== entry=00b10bf8 name=FUN_00b10bf8 size=271 ====

void FUN_00b10bf8(undefined8 param_1,undefined8 *param_2,undefined8 *param_3)

{
  long lVar1;
  undefined8 uVar2;
  long lVar3;
  long *local_20;
  
  local_20 = (long *)param_2[3];
  while (local_20 = local_20 + 1, local_20 < (long *)param_3[3]) {
    uVar2 = FUN_00b0fb6c(param_1);
    lVar1 = *local_20;
    lVar3 = FUN_00b11d85();
    FUN_00b11d95(*local_20,lVar1 + lVar3 * 0x40,uVar2);
  }
  if (param_2[3] == param_3[3]) {
    uVar2 = FUN_00b0fb6c(param_1);
    FUN_00b11d95(*param_2,*param_3,uVar2);
  }
  else {
    uVar2 = FUN_00b0fb6c(param_1);
    FUN_00b11d95(*param_2,param_2[2],uVar2);
    uVar2 = FUN_00b0fb6c(param_1);
    FUN_00b11d95(param_3[1],*param_3,uVar2);
  }
  return;
}


// ==== entry=00b10d08 name=FUN_00b10d08 size=51 ====

void FUN_00b10d08(undefined8 param_1)

{
  FUN_00b11dc0(param_1);
                    /* try { // try from 00b10d2d to 00b10d31 has its CatchHandler @ 00b10d34 */
  FUN_00b11e12(param_1,0);
  return;
}


// ==== entry=00b10d56 name=FUN_00b10d56 size=27 ====

void FUN_00b10d56(undefined8 param_1)

{
  FUN_00b11fc0(param_1);
  return;
}


// ==== entry=00b10d72 name=FUN_00b10d72 size=70 ====

void FUN_00b10d72(undefined8 param_1,undefined8 *param_2,undefined8 *param_3)

{
  undefined8 *local_10;
  
  for (local_10 = param_2; local_10 < param_3; local_10 = local_10 + 1) {
    FUN_00b11fcc(param_1,*local_10);
  }
  return;
}


// ==== entry=00b10db8 name=FUN_00b10db8 size=77 ====

void FUN_00b10db8(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  undefined1 local_9;
  
  FUN_00b12000(&local_9,param_1);
  FUN_00b1204f(&local_9,param_2,param_3);
  FUN_00b12034(&local_9);
  return;
}


// ==== entry=00b10e06 name=FUN_00b10e06 size=51 ====

void FUN_00b10e06(undefined8 param_1)

{
  FUN_00b1207e(param_1);
                    /* try { // try from 00b10e2b to 00b10e2f has its CatchHandler @ 00b10e32 */
  FUN_00b120d0(param_1,0);
  return;
}


// ==== entry=00b10e54 name=FUN_00b10e54 size=27 ====

void FUN_00b10e54(undefined8 param_1)

{
  FUN_00b12278(param_1);
  return;
}


// ==== entry=00b10e70 name=FUN_00b10e70 size=70 ====

void FUN_00b10e70(undefined8 param_1,undefined8 *param_2,undefined8 *param_3)

{
  undefined8 *local_10;
  
  for (local_10 = param_2; local_10 < param_3; local_10 = local_10 + 1) {
    FUN_00b12284(param_1,*local_10);
  }
  return;
}


// ==== entry=00b10eb6 name=FUN_00b10eb6 size=77 ====

void FUN_00b10eb6(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  undefined1 local_9;
  
  FUN_00b122b8(&local_9,param_1);
  FUN_00b12307(&local_9,param_2,param_3);
  FUN_00b122ec(&local_9);
  return;
}


// ==== entry=00b10f04 name=FUN_00b10f04 size=27 ====

void FUN_00b10f04(undefined8 param_1)

{
  FUN_00b12336(param_1);
  return;
}


// ==== entry=00b10f20 name=FUN_00b10f20 size=27 ====

void FUN_00b10f20(undefined8 param_1)

{
  FUN_00b12374(param_1);
  return;
}


// ==== entry=00b10f3c name=FUN_00b10f3c size=53 ====

void FUN_00b10f3c(undefined8 param_1,long param_2,undefined8 param_3)

{
  if (param_2 != 0) {
    FUN_00b1237f(param_1,param_2,param_3);
  }
  return;
}


// ==== entry=00b10f71 name=FUN_00b10f71 size=38 ====

void FUN_00b10f71(undefined8 param_1,undefined8 param_2)

{
  FUN_00b123bb(param_1,param_2);
  return;
}


// ==== entry=00b10f98 name=FUN_00b10f98 size=51 ====

void FUN_00b10f98(undefined8 param_1)

{
  FUN_00b123f4(param_1);
                    /* try { // try from 00b10fbd to 00b10fc1 has its CatchHandler @ 00b10fc4 */
  FUN_00b12446(param_1,0);
  return;
}


// ==== entry=00b10fe6 name=FUN_00b10fe6 size=27 ====

void FUN_00b10fe6(undefined8 param_1)

{
  FUN_00b125ee(param_1);
  return;
}


// ==== entry=00b11002 name=FUN_00b11002 size=70 ====

void FUN_00b11002(undefined8 param_1,undefined8 *param_2,undefined8 *param_3)

{
  undefined8 *local_10;
  
  for (local_10 = param_2; local_10 < param_3; local_10 = local_10 + 1) {
    FUN_00b125fa(param_1,*local_10);
  }
  return;
}


// ==== entry=00b11048 name=FUN_00b11048 size=77 ====

void FUN_00b11048(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  undefined1 local_9;
  
  FUN_00b1262e(&local_9,param_1);
  FUN_00b1267d(&local_9,param_2,param_3);
  FUN_00b12662(&local_9);
  return;
}


// ==== entry=00b11095 name=FUN_00b11095 size=34 ====

undefined8 FUN_00b11095(long *param_1,long *param_2)

{
  return CONCAT71((int7)((ulong)*param_2 >> 8),*param_1 == *param_2);
}


// ==== entry=00b110b7 name=FUN_00b110b7 size=38 ====

void FUN_00b110b7(undefined8 param_1,undefined8 param_2)

{
  FUN_00b126ac(param_1,param_2);
  return;
}


// ==== entry=00b110de name=FUN_00b110de size=122 ====

void FUN_00b110de(long param_1)

{
  undefined8 uVar1;
  undefined8 uVar2;
  
  uVar1 = *(undefined8 *)(param_1 + 0x10);
  uVar2 = FUN_00b0fb6c(param_1);
  FUN_00b110b7(uVar2,uVar1);
  FUN_00b11cd4(param_1,*(undefined8 *)(param_1 + 0x18));
  FUN_00b126cc(param_1 + 0x10,*(long *)(param_1 + 0x28) + 8);
  *(undefined8 *)(param_1 + 0x10) = *(undefined8 *)(param_1 + 0x18);
  return;
}


// ==== entry=00b11158 name=FUN_00b11158 size=17 ====

undefined8 FUN_00b11158(undefined8 *param_1)

{
  return *param_1;
}


// ==== entry=00b1116a name=FUN_00b1116a size=27 ====

void FUN_00b1116a(undefined8 param_1)

{
  FUN_00b1271e(param_1);
  return;
}


// ==== entry=00b11185 name=FUN_00b11185 size=26 ====

void FUN_00b11185(undefined8 param_1)

{
  FUN_00b12745(param_1);
  return;
}


// ==== entry=00b111a0 name=FUN_00b111a0 size=26 ====

void FUN_00b111a0(undefined8 param_1)

{
  FUN_00b1275f(param_1);
  return;
}


// ==== entry=00b111ba name=FUN_00b111ba size=14 ====

undefined8 FUN_00b111ba(undefined8 param_1)

{
  return param_1;
}


// ==== entry=00b111c8 name=FUN_00b111c8 size=154 ====

void FUN_00b111c8(long param_1,undefined8 param_2)

{
  undefined8 uVar1;
  undefined8 uVar2;
  
  if (*(long *)(param_1 + 8) == *(long *)(param_1 + 0x10)) {
    uVar1 = FUN_00b111ba(param_2);
    uVar2 = FUN_00b11262(param_1);
    FUN_00b127b2(param_1,uVar2,uVar1);
  }
  else {
    uVar1 = FUN_00b111ba(param_2);
    FUN_00b12779(param_1,*(undefined8 *)(param_1 + 8),uVar1);
    *(long *)(param_1 + 8) = *(long *)(param_1 + 8) + 8;
  }
  return;
}


// ==== entry=00b11262 name=FUN_00b11262 size=41 ====

undefined8 FUN_00b11262(long param_1)

{
  undefined8 local_10;
  
  FUN_00b129f2(&local_10,param_1 + 8);
  return local_10;
}


// ==== entry=00b1128c name=FUN_00b1128c size=66 ====

undefined8 FUN_00b1128c(long *param_1,long param_2)

{
  undefined8 local_18;
  long local_10;
  
  local_10 = *param_1 + param_2 * -8;
  FUN_00b129f2(&local_18,&local_10);
  return local_18;
}


// ==== entry=00b112ce name=FUN_00b112ce size=17 ====

undefined8 FUN_00b112ce(undefined8 *param_1)

{
  return *param_1;
}


// ==== entry=00b112e0 name=FUN_00b112e0 size=29 ====

undefined8 FUN_00b112e0(undefined8 param_1)

{
  undefined8 *puVar1;
  
  puVar1 = (undefined8 *)FUN_00b12a0f(param_1);
  return *puVar1;
}


// ==== entry=00b112fd name=FUN_00b112fd size=14 ====

undefined8 FUN_00b112fd(undefined8 param_1)

{
  return param_1;
}


// ==== entry=00b1130c name=FUN_00b1130c size=134 ====

void FUN_00b1130c(long param_1,undefined8 param_2)

{
  undefined8 uVar1;
  
  if (*(long *)(param_1 + 0x30) == *(long *)(param_1 + 0x40) + -8) {
    uVar1 = FUN_00b112fd(param_2);
    FUN_00b12a62(param_1,uVar1);
  }
  else {
    uVar1 = FUN_00b112fd(param_2);
    FUN_00b12a29(param_1,*(undefined8 *)(param_1 + 0x30),uVar1);
    *(long *)(param_1 + 0x30) = *(long *)(param_1 + 0x30) + 8;
  }
  return;
}


// ==== entry=00b11392 name=FUN_00b11392 size=14 ====

undefined8 FUN_00b11392(undefined8 param_1)

{
  return param_1;
}


// ==== entry=00b113a0 name=FUN_00b113a0 size=134 ====

void FUN_00b113a0(long param_1,undefined8 param_2)

{
  undefined8 uVar1;
  
  if (*(long *)(param_1 + 0x30) == *(long *)(param_1 + 0x40) + -0x40) {
    uVar1 = FUN_00b11392(param_2);
    FUN_00b12b36(param_1,uVar1);
  }
  else {
    uVar1 = FUN_00b11392(param_2);
    FUN_00b12afc(param_1,*(undefined8 *)(param_1 + 0x30),uVar1);
    *(long *)(param_1 + 0x30) = *(long *)(param_1 + 0x30) + 0x40;
  }
  return;
}


// ==== entry=00b11426 name=FUN_00b11426 size=98 ====

long * FUN_00b11426(long *param_1)

{
  if (*param_1 == param_1[1]) {
    FUN_00b126cc(param_1,param_1[3] + -8);
    *param_1 = param_1[2];
  }
  *param_1 = *param_1 + -0x40;
  return param_1;
}


// ==== entry=00b11488 name=FUN_00b11488 size=98 ====

long * FUN_00b11488(long *param_1)

{
  if (*param_1 == param_1[1]) {
    FUN_00b12bd0(param_1,param_1[3] + -8);
    *param_1 = param_1[2];
  }
  *param_1 = *param_1 + -8;
  return param_1;
}


// ==== entry=00b114ea name=FUN_00b114ea size=17 ====

undefined8 FUN_00b114ea(undefined8 *param_1)

{
  return *param_1;
}


// ==== entry=00b114fb name=FUN_00b114fb size=34 ====

undefined8 FUN_00b114fb(long *param_1,long *param_2)

{
  return CONCAT71((int7)((ulong)*param_2 >> 8),*param_1 == *param_2);
}


// ==== entry=00b1151d name=FUN_00b1151d size=38 ====

void FUN_00b1151d(undefined8 param_1,undefined8 param_2)

{
  FUN_00b12c22(param_1,param_2);
  return;
}


// ==== entry=00b11544 name=FUN_00b11544 size=126 ====

void FUN_00b11544(long param_1)

{
  undefined8 uVar1;
  undefined8 uVar2;
  
  FUN_00b12284(param_1,*(undefined8 *)(param_1 + 0x38));
  FUN_00b12bd0(param_1 + 0x30,*(long *)(param_1 + 0x48) + -8);
  *(long *)(param_1 + 0x30) = *(long *)(param_1 + 0x40) + -8;
  uVar1 = *(undefined8 *)(param_1 + 0x30);
  uVar2 = FUN_00b0fe8c(param_1);
  FUN_00b1151d(uVar2,uVar1);
  return;
}


// ==== entry=00b115c2 name=FUN_00b115c2 size=45 ====

undefined8 FUN_00b115c2(undefined8 param_1,long param_2)

{
  FUN_00b12c32(param_1,param_2 + 0x30);
  return param_1;
}


// ==== entry=00b115f0 name=FUN_00b115f0 size=98 ====

long * FUN_00b115f0(long *param_1)

{
  if (*param_1 == param_1[1]) {
    FUN_00b12c80(param_1,param_1[3] + -8);
    *param_1 = param_1[2];
  }
  *param_1 = *param_1 + -8;
  return param_1;
}


// ==== entry=00b11652 name=FUN_00b11652 size=17 ====

undefined8 FUN_00b11652(undefined8 *param_1)

{
  return *param_1;
}


// ==== entry=00b11664 name=FUN_00b11664 size=45 ====

undefined8 FUN_00b11664(undefined8 param_1,long param_2)

{
  FUN_00b12cd2(param_1,param_2 + 0x10);
  return param_1;
}


// ==== entry=00b11692 name=FUN_00b11692 size=17 ====

undefined8 FUN_00b11692(undefined8 *param_1)

{
  return *param_1;
}


// ==== entry=00b116a4 name=FUN_00b116a4 size=77 ====

void FUN_00b116a4(undefined8 *param_1,undefined8 *param_2)

{
  *param_1 = *param_2;
  param_1[1] = param_2[1];
  param_1[2] = param_2[2];
  param_1[3] = param_2[3];
  return;
}


// ==== entry=00b116f2 name=FUN_00b116f2 size=252 ====

long * FUN_00b116f2(long *param_1,long param_2)

{
  bool bVar1;
  ulong uVar2;
  long lVar3;
  ulong uVar4;
  long lVar5;
  
  uVar2 = param_2 + (*param_1 - param_1[1]);
  if (-1 < (long)uVar2) {
    lVar3 = FUN_00b10529();
    if ((long)uVar2 < lVar3) {
      bVar1 = true;
      goto LAB_00b1173e;
    }
  }
  bVar1 = false;
LAB_00b1173e:
  if (bVar1) {
    *param_1 = *param_1 + param_2;
  }
  else {
    if ((long)uVar2 < 1) {
      uVar4 = FUN_00b10529();
      uVar4 = ~(~uVar2 / uVar4);
    }
    else {
      lVar3 = FUN_00b10529();
      uVar4 = (long)uVar2 / lVar3;
    }
    FUN_00b12d20(param_1,uVar4 * 8 + param_1[3]);
    lVar3 = param_1[1];
    lVar5 = FUN_00b10529();
    *param_1 = lVar3 + (uVar2 - lVar5 * uVar4);
  }
  return param_1;
}


// ==== entry=00b117ee name=FUN_00b117ee size=60 ====

undefined8 FUN_00b117ee(undefined8 param_1,undefined8 param_2)

{
  long lVar1;
  long *plVar2;
  
  plVar2 = (long *)FUN_00b12d6e(param_1);
  lVar1 = *plVar2;
  plVar2 = (long *)FUN_00b12d6e(param_2);
  return CONCAT71((int7)((ulong)*plVar2 >> 8),lVar1 != *plVar2);
}


// ==== entry=00b1182a name=FUN_00b1182a size=32 ====

long * FUN_00b1182a(long *param_1)

{
  *param_1 = *param_1 + 0x20;
  return param_1;
}


// ==== entry=00b1184a name=FUN_00b1184a size=17 ====

undefined8 FUN_00b1184a(undefined8 *param_1)

{
  return *param_1;
}


// ==== entry=00b1185c name=FUN_00b1185c size=32 ====

long FUN_00b1185c(long *param_1,long param_2)

{
  return *param_1 + param_2 * 0x20;
}


// ==== entry=00b1187c name=FUN_00b1187c size=66 ====

void FUN_00b1187c(undefined8 param_1)

{
  undefined8 local_18;
  undefined8 local_10;
  
  local_18 = FUN_00b0f926(param_1);
  local_10 = FUN_00b0f8f6(param_1);
  FUN_00b12d7c(&local_10,&local_18);
  return;
}


// ==== entry=00b118be name=FUN_00b118be size=46 ====

void FUN_00b118be(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  FUN_00b12db8(param_1,param_2,param_3);
  return;
}


// ==== entry=00b118ec name=FUN_00b118ec size=14 ====

undefined8 FUN_00b118ec(undefined8 param_1)

{
  return param_1;
}


// ==== entry=00b118fa name=FUN_00b118fa size=56 ====

void FUN_00b118fa(long param_1,long param_2)

{
  undefined8 uVar1;
  undefined8 local_10;
  
  for (local_10 = param_1; local_10 != param_2; local_10 = local_10 + 0x20) {
    uVar1 = FUN_00b118ec(local_10);
    FUN_00b12ddb(uVar1);
  }
  return;
}


// ==== entry=00b11932 name=FUN_00b11932 size=15 ====

void FUN_00b11932(void)

{
  return;
}


// ==== entry=00b11942 name=FUN_00b11942 size=51 ====

undefined8 FUN_00b11942(undefined8 param_1,long param_2)

{
  undefined8 uVar1;
  
  if (param_2 == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = FUN_00b12df6(param_1,param_2);
  }
  return uVar1;
}


// ==== entry=00b11975 name=FUN_00b11975 size=122 ====

long FUN_00b11975(undefined8 param_1,undefined8 param_2,long param_3)

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
    cVar1 = FUN_00b117ee(local_30,&local_38);
    if (cVar1 == '\0') break;
    uVar2 = FUN_00b1184a(local_30);
    uVar3 = FUN_00b118ec(local_20);
                    /* try { // try from 00b119ca to 00b119ce has its CatchHandler @ 00b119e8 */
    FUN_00b12e2e(uVar3,uVar2);
    FUN_00b1182a(local_30);
    local_20 = local_20 + 0x20;
  }
  return local_20;
}


// ==== entry=00b11a22 name=FUN_00b11a22 size=27 ====

void FUN_00b11a22(undefined8 param_1)

{
  FUN_00b12e98(param_1);
  return;
}


// ==== entry=00b11a3e name=FUN_00b11a3e size=11 ====

void FUN_00b11a3e(void)

{
  return;
}


// ==== entry=00b11a49 name=FUN_00b11a49 size=46 ====

void FUN_00b11a49(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  FUN_00b12ea4(param_1,param_2,param_3);
  return;
}


// ==== entry=00b11a77 name=FUN_00b11a77 size=14 ====

undefined8 FUN_00b11a77(undefined8 param_1)

{
  return param_1;
}


// ==== entry=00b11a85 name=FUN_00b11a85 size=56 ====

void FUN_00b11a85(long param_1,long param_2)

{
  undefined8 uVar1;
  undefined8 local_10;
  
  for (local_10 = param_1; local_10 != param_2; local_10 = local_10 + 8) {
    uVar1 = FUN_00b11a77(local_10);
    FUN_00b12ec7(uVar1);
  }
  return;
}


// ==== entry=00b11abd name=FUN_00b11abd size=16 ====

void FUN_00b11abd(void)

{
  FUN_00b0d748(4);
  return;
}


// ==== entry=00b11ace name=FUN_00b11ace size=82 ====

void FUN_00b11ace(undefined8 *param_1)

{
  FUN_00b12ee2(param_1);
  *param_1 = 0;
  param_1[1] = 0;
  FUN_00b12efe(param_1 + 2);
  FUN_00b12efe(param_1 + 6);
  return;
}


// ==== entry=00b11b20 name=FUN_00b11b20 size=339 ====

/* WARNING: Type propagation algorithm not settling */

void FUN_00b11b20(long *param_1,ulong param_2)

{
  ulong uVar1;
  long *plVar2;
  long lVar3;
  long local_40 [3];
  long local_28;
  long local_20;
  
  uVar1 = FUN_00b0d748(0x40);
  local_20 = param_2 / uVar1 + 1;
  local_40[0] = param_2 / uVar1 + 3;
  local_40[1] = 8;
  plVar2 = (long *)FUN_00b06d34(local_40 + 1,local_40);
  param_1[1] = *plVar2;
  lVar3 = FUN_00b12f38(param_1,param_1[1]);
  *param_1 = lVar3;
  local_28 = ((ulong)(param_1[1] - local_20) >> 1) * 8 + *param_1;
  local_40[2] = local_28 + local_20 * 8;
                    /* try { // try from 00b11bef to 00b11bf3 has its CatchHandler @ 00b11c6c */
  FUN_00b12fa6(param_1,local_28,local_40[2]);
  FUN_00b126cc(param_1 + 2,local_28);
  FUN_00b126cc(param_1 + 6,local_40[2] + -8);
  param_1[2] = param_1[3];
  lVar3 = param_1[7];
  uVar1 = FUN_00b0d748(0x40);
  param_1[6] = lVar3 + (param_2 % uVar1) * 0x40;
  return;
}


// ==== entry=00b11cc8 name=FUN_00b11cc8 size=11 ====

void FUN_00b11cc8(void)

{
  return;
}


// ==== entry=00b11cd4 name=FUN_00b11cd4 size=51 ====

void FUN_00b11cd4(undefined8 param_1,undefined8 param_2)

{
  undefined8 uVar1;
  
  uVar1 = FUN_00b0d748(0x40);
  FUN_00b13029(param_1,param_2,uVar1);
  return;
}


// ==== entry=00b11d08 name=FUN_00b11d08 size=52 ====

undefined8 FUN_00b11d08(undefined8 param_1,undefined8 param_2)

{
  undefined8 uVar1;
  
  uVar1 = FUN_00b13058(param_2);
  FUN_00b13066(param_1,uVar1);
  return param_1;
}


// ==== entry=00b11d3c name=FUN_00b11d3c size=27 ====

void FUN_00b11d3c(undefined8 param_1)

{
  FUN_00b13086(param_1);
  return;
}


// ==== entry=00b11d57 name=FUN_00b11d57 size=46 ====

void FUN_00b11d57(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  FUN_00b13092(param_1,param_2,param_3);
  return;
}


// ==== entry=00b11d85 name=FUN_00b11d85 size=16 ====

void FUN_00b11d85(void)

{
  FUN_00b0d748(0x40);
  return;
}


// ==== entry=00b11d95 name=FUN_00b11d95 size=42 ====

void FUN_00b11d95(undefined8 param_1,undefined8 param_2)

{
  FUN_00b130b5(param_1,param_2);
  return;
}


// ==== entry=00b11dc0 name=FUN_00b11dc0 size=82 ====

void FUN_00b11dc0(undefined8 *param_1)

{
  FUN_00b130dc(param_1);
  *param_1 = 0;
  param_1[1] = 0;
  FUN_00b130f8(param_1 + 2);
  FUN_00b130f8(param_1 + 6);
  return;
}


// ==== entry=00b11e12 name=FUN_00b11e12 size=345 ====

/* WARNING: Type propagation algorithm not settling */

void FUN_00b11e12(long *param_1,ulong param_2)

{
  ulong uVar1;
  long *plVar2;
  long lVar3;
  long local_40 [3];
  long local_28;
  long local_20;
  
  uVar1 = FUN_00b0d748(0x30);
  local_20 = param_2 / uVar1 + 1;
  local_40[0] = param_2 / uVar1 + 3;
  local_40[1] = 8;
  plVar2 = (long *)FUN_00b06d34(local_40 + 1,local_40);
  param_1[1] = *plVar2;
  lVar3 = FUN_00b13132(param_1,param_1[1]);
  *param_1 = lVar3;
  local_28 = ((ulong)(param_1[1] - local_20) >> 1) * 8 + *param_1;
  local_40[2] = local_28 + local_20 * 8;
                    /* try { // try from 00b11ee1 to 00b11ee5 has its CatchHandler @ 00b11f64 */
  FUN_00b131a0(param_1,local_28,local_40[2]);
  FUN_00b13224(param_1 + 2,local_28);
  FUN_00b13224(param_1 + 6,local_40[2] + -8);
  param_1[2] = param_1[3];
  lVar3 = param_1[7];
  uVar1 = FUN_00b0d748(0x30);
  param_1[6] = lVar3 + (param_2 % uVar1) * 0x30;
  return;
}


// ==== entry=00b11fc0 name=FUN_00b11fc0 size=11 ====

void FUN_00b11fc0(void)

{
  return;
}


// ==== entry=00b11fcc name=FUN_00b11fcc size=51 ====

void FUN_00b11fcc(undefined8 param_1,undefined8 param_2)

{
  undefined8 uVar1;
  
  uVar1 = FUN_00b0d748(0x30);
  FUN_00b13281(param_1,param_2,uVar1);
  return;
}


// ==== entry=00b12000 name=FUN_00b12000 size=52 ====

undefined8 FUN_00b12000(undefined8 param_1,undefined8 param_2)

{
  undefined8 uVar1;
  
  uVar1 = FUN_00b132b0(param_2);
  FUN_00b132be(param_1,uVar1);
  return param_1;
}


// ==== entry=00b12034 name=FUN_00b12034 size=27 ====

void FUN_00b12034(undefined8 param_1)

{
  FUN_00b132de(param_1);
  return;
}


// ==== entry=00b1204f name=FUN_00b1204f size=46 ====

void FUN_00b1204f(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  FUN_00b132ea(param_1,param_2,param_3);
  return;
}


// ==== entry=00b1207e name=FUN_00b1207e size=82 ====

void FUN_00b1207e(undefined8 *param_1)

{
  FUN_00b1330e(param_1);
  *param_1 = 0;
  param_1[1] = 0;
  FUN_00b1332a(param_1 + 2);
  FUN_00b1332a(param_1 + 6);
  return;
}


// ==== entry=00b120d0 name=FUN_00b120d0 size=339 ====

/* WARNING: Type propagation algorithm not settling */

void FUN_00b120d0(long *param_1,ulong param_2)

{
  ulong uVar1;
  long *plVar2;
  long lVar3;
  long local_40 [3];
  long local_28;
  long local_20;
  
  uVar1 = FUN_00b0d748(8);
  local_20 = param_2 / uVar1 + 1;
  local_40[0] = param_2 / uVar1 + 3;
  local_40[1] = 8;
  plVar2 = (long *)FUN_00b06d34(local_40 + 1,local_40);
  param_1[1] = *plVar2;
  lVar3 = FUN_00b13364(param_1,param_1[1]);
  *param_1 = lVar3;
  local_28 = ((ulong)(param_1[1] - local_20) >> 1) * 8 + *param_1;
  local_40[2] = local_28 + local_20 * 8;
                    /* try { // try from 00b1219f to 00b121a3 has its CatchHandler @ 00b1221c */
  FUN_00b133d2(param_1,local_28,local_40[2]);
  FUN_00b12bd0(param_1 + 2,local_28);
  FUN_00b12bd0(param_1 + 6,local_40[2] + -8);
  param_1[2] = param_1[3];
  lVar3 = param_1[7];
  uVar1 = FUN_00b0d748(8);
  param_1[6] = lVar3 + (param_2 % uVar1) * 8;
  return;
}


// ==== entry=00b12278 name=FUN_00b12278 size=11 ====

void FUN_00b12278(void)

{
  return;
}


// ==== entry=00b12284 name=FUN_00b12284 size=51 ====

void FUN_00b12284(undefined8 param_1,undefined8 param_2)

{
  undefined8 uVar1;
  
  uVar1 = FUN_00b0d748(8);
  FUN_00b13455(param_1,param_2,uVar1);
  return;
}


// ==== entry=00b122b8 name=FUN_00b122b8 size=52 ====

undefined8 FUN_00b122b8(undefined8 param_1,undefined8 param_2)

{
  undefined8 uVar1;
  
  uVar1 = FUN_00b13484(param_2);
  FUN_00b13492(param_1,uVar1);
  return param_1;
}


// ==== entry=00b122ec name=FUN_00b122ec size=27 ====

void FUN_00b122ec(undefined8 param_1)

{
  FUN_00b134b2(param_1);
  return;
}


// ==== entry=00b12307 name=FUN_00b12307 size=46 ====

void FUN_00b12307(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  FUN_00b134be(param_1,param_2,param_3);
  return;
}


// ==== entry=00b12336 name=FUN_00b12336 size=62 ====

void FUN_00b12336(undefined8 *param_1)

{
  FUN_00b134e2(param_1);
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  return;
}


// ==== entry=00b12374 name=FUN_00b12374 size=11 ====

void FUN_00b12374(void)

{
  return;
}


// ==== entry=00b1237f name=FUN_00b1237f size=46 ====

void FUN_00b1237f(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  FUN_00b134fe(param_1,param_2,param_3);
  return;
}


// ==== entry=00b123ad name=FUN_00b123ad size=14 ====

undefined8 FUN_00b123ad(undefined8 param_1)

{
  return param_1;
}


// ==== entry=00b123bb name=FUN_00b123bb size=56 ====

void FUN_00b123bb(long param_1,long param_2)

{
  undefined8 uVar1;
  undefined8 local_10;
  
  for (local_10 = param_1; local_10 != param_2; local_10 = local_10 + 8) {
    uVar1 = FUN_00b123ad(local_10);
    FUN_00b13521(uVar1);
  }
  return;
}


// ==== entry=00b123f4 name=FUN_00b123f4 size=82 ====

void FUN_00b123f4(undefined8 *param_1)

{
  FUN_00b1353c(param_1);
  *param_1 = 0;
  param_1[1] = 0;
  FUN_00b13558(param_1 + 2);
  FUN_00b13558(param_1 + 6);
  return;
}


// ==== entry=00b12446 name=FUN_00b12446 size=339 ====

/* WARNING: Type propagation algorithm not settling */

void FUN_00b12446(long *param_1,ulong param_2)

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
  lVar3 = FUN_00b13592(param_1,param_1[1]);
  *param_1 = lVar3;
  local_28 = ((ulong)(param_1[1] - local_20) >> 1) * 8 + *param_1;
  local_40[2] = local_28 + local_20 * 8;
                    /* try { // try from 00b12515 to 00b12519 has its CatchHandler @ 00b12592 */
  FUN_00b13600(param_1,local_28,local_40[2]);
  FUN_00b13684(param_1 + 2,local_28);
  FUN_00b13684(param_1 + 6,local_40[2] + -8);
  param_1[2] = param_1[3];
  lVar3 = param_1[7];
  uVar1 = FUN_00b0d748(4);
  param_1[6] = lVar3 + (param_2 % uVar1) * 4;
  return;
}


// ==== entry=00b125ee name=FUN_00b125ee size=11 ====

void FUN_00b125ee(void)

{
  return;
}


// ==== entry=00b125fa name=FUN_00b125fa size=51 ====

void FUN_00b125fa(undefined8 param_1,undefined8 param_2)

{
  undefined8 uVar1;
  
  uVar1 = FUN_00b0d748(4);
  FUN_00b136d5(param_1,param_2,uVar1);
  return;
}


// ==== entry=00b1262e name=FUN_00b1262e size=52 ====

undefined8 FUN_00b1262e(undefined8 param_1,undefined8 param_2)

{
  undefined8 uVar1;
  
  uVar1 = FUN_00b13704(param_2);
  FUN_00b13712(param_1,uVar1);
  return param_1;
}


// ==== entry=00b12662 name=FUN_00b12662 size=27 ====

void FUN_00b12662(undefined8 param_1)

{
  FUN_00b13732(param_1);
  return;
}


// ==== entry=00b1267d name=FUN_00b1267d size=46 ====

void FUN_00b1267d(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  FUN_00b1373e(param_1,param_2,param_3);
  return;
}


// ==== entry=00b126ac name=FUN_00b126ac size=31 ====

void FUN_00b126ac(undefined8 param_1,undefined8 param_2)

{
  yaml_token_dtor(param_2);
  return;
}


// ==== entry=00b126cc name=FUN_00b126cc size=81 ====

void FUN_00b126cc(long param_1,undefined8 *param_2)

{
  long lVar1;
  long lVar2;
  
  *(undefined8 **)(param_1 + 0x18) = param_2;
  *(undefined8 *)(param_1 + 8) = *param_2;
  lVar1 = *(long *)(param_1 + 8);
  lVar2 = FUN_00b13761();
  *(long *)(param_1 + 0x10) = lVar1 + lVar2 * 0x40;
  return;
}


// ==== entry=00b1271e name=FUN_00b1271e size=39 ====

void FUN_00b1271e(undefined8 param_1)

{
  FUN_00b13772(param_1);
  FUN_00b1378e(param_1);
  return;
}


// ==== entry=00b12745 name=FUN_00b12745 size=26 ====

void FUN_00b12745(undefined8 param_1)

{
  FUN_00b137a4(param_1);
  return;
}


// ==== entry=00b1275f name=FUN_00b1275f size=26 ====

void FUN_00b1275f(undefined8 param_1)

{
  FUN_00b137be(param_1);
  return;
}


// ==== entry=00b12779 name=FUN_00b12779 size=57 ====

void FUN_00b12779(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  undefined8 uVar1;
  
  uVar1 = FUN_00b111ba(param_3);
  FUN_00b137d8(param_1,param_2,uVar1);
  return;
}


// ==== entry=00b127b2 name=FUN_00b127b2 size=443 ====

void FUN_00b127b2(long *param_1,undefined8 param_2,undefined8 param_3)

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
  local_28 = FUN_00b13820(param_1,1,"vector::_M_realloc_insert");
  local_30 = *local_60;
  local_38 = local_60[1];
  local_50 = FUN_00b138ea(local_60);
  local_40 = FUN_00b1390f(&local_68,&local_50);
  local_48 = FUN_00b13950(local_60,local_28);
  local_20 = local_48;
  uVar1 = FUN_00b111ba(param_3);
  FUN_00b12779(local_60,local_40 * 8 + local_48,uVar1);
  local_20 = 0;
  uVar1 = FUN_00b0ff86(local_60);
  puVar2 = (undefined8 *)FUN_00b13984(&local_68);
                    /* try { // try from 00b128a7 to 00b128e5 has its CatchHandler @ 00b12966 */
  local_20 = FUN_00b13992(local_30,*puVar2,local_48,uVar1);
  local_20 = local_20 + 8;
  uVar1 = FUN_00b0ff86(local_60);
  puVar2 = (undefined8 *)FUN_00b13984(&local_68);
  local_20 = FUN_00b13992(*puVar2,local_38,local_20,uVar1);
  uVar1 = FUN_00b0ff86(local_60);
  FUN_00b0ff94(local_30,local_38,uVar1);
  FUN_00b10f3c(local_60,local_30,local_60[2] - local_30 >> 3);
  *local_60 = local_48;
  local_60[1] = local_20;
  local_60[2] = local_28 * 8 + local_48;
  return;
}


// ==== entry=00b129f2 name=FUN_00b129f2 size=29 ====

void FUN_00b129f2(undefined8 *param_1,undefined8 *param_2)

{
  *param_1 = *param_2;
  return;
}


// ==== entry=00b12a0f name=FUN_00b12a0f size=26 ====

void FUN_00b12a0f(undefined8 param_1)

{
  FUN_00b13a0c(param_1);
  return;
}


// ==== entry=00b12a29 name=FUN_00b12a29 size=57 ====

void FUN_00b12a29(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  undefined8 uVar1;
  
  uVar1 = FUN_00b112fd(param_3);
  FUN_00b13a26(param_1,param_2,uVar1);
  return;
}


// ==== entry=00b12a62 name=FUN_00b12a62 size=154 ====

void FUN_00b12a62(long param_1,undefined8 param_2)

{
  long lVar1;
  undefined8 uVar2;
  
  FUN_00b13a66(param_1,1);
  lVar1 = *(long *)(param_1 + 0x48);
  uVar2 = FUN_00b13ac6(param_1);
  *(undefined8 *)(lVar1 + 8) = uVar2;
  uVar2 = FUN_00b112fd(param_2);
  FUN_00b12a29(param_1,*(undefined8 *)(param_1 + 0x30),uVar2);
  FUN_00b12bd0(param_1 + 0x30,*(long *)(param_1 + 0x48) + 8);
  *(undefined8 *)(param_1 + 0x30) = *(undefined8 *)(param_1 + 0x38);
  return;
}


// ==== entry=00b12afc name=FUN_00b12afc size=57 ====

void FUN_00b12afc(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  undefined8 uVar1;
  
  uVar1 = FUN_00b11392(param_3);
  FUN_00b13b78(param_1,param_2,uVar1);
  return;
}


// ==== entry=00b12b36 name=FUN_00b12b36 size=154 ====

void FUN_00b12b36(long param_1,undefined8 param_2)

{
  long lVar1;
  undefined8 uVar2;
  
  FUN_00b13bc0(param_1,1);
  lVar1 = *(long *)(param_1 + 0x48);
  uVar2 = FUN_00b13c20(param_1);
  *(undefined8 *)(lVar1 + 8) = uVar2;
  uVar2 = FUN_00b11392(param_2);
  FUN_00b12afc(param_1,*(undefined8 *)(param_1 + 0x30),uVar2);
  FUN_00b126cc(param_1 + 0x30,*(long *)(param_1 + 0x48) + 8);
  *(undefined8 *)(param_1 + 0x30) = *(undefined8 *)(param_1 + 0x38);
  return;
}


// ==== entry=00b12bd0 name=FUN_00b12bd0 size=81 ====

void FUN_00b12bd0(long param_1,undefined8 *param_2)

{
  long lVar1;
  long lVar2;
  
  *(undefined8 **)(param_1 + 0x18) = param_2;
  *(undefined8 *)(param_1 + 8) = *param_2;
  lVar1 = *(long *)(param_1 + 8);
  lVar2 = FUN_00b13c4a();
  *(long *)(param_1 + 0x10) = lVar1 + lVar2 * 8;
  return;
}


// ==== entry=00b12c22 name=FUN_00b12c22 size=15 ====

void FUN_00b12c22(void)

{
  return;
}


// ==== entry=00b12c32 name=FUN_00b12c32 size=77 ====

void FUN_00b12c32(undefined8 *param_1,undefined8 *param_2)

{
  *param_1 = *param_2;
  param_1[1] = param_2[1];
  param_1[2] = param_2[2];
  param_1[3] = param_2[3];
  return;
}


// ==== entry=00b12c80 name=FUN_00b12c80 size=81 ====

void FUN_00b12c80(long param_1,undefined8 *param_2)

{
  long lVar1;
  long lVar2;
  
  *(undefined8 **)(param_1 + 0x18) = param_2;
  *(undefined8 *)(param_1 + 8) = *param_2;
  lVar1 = *(long *)(param_1 + 8);
  lVar2 = FUN_00b13c5a();
  *(long *)(param_1 + 0x10) = lVar1 + lVar2 * 8;
  return;
}


// ==== entry=00b12cd2 name=FUN_00b12cd2 size=77 ====

void FUN_00b12cd2(undefined8 *param_1,undefined8 *param_2)

{
  *param_1 = *param_2;
  param_1[1] = param_2[1];
  param_1[2] = param_2[2];
  param_1[3] = param_2[3];
  return;
}


// ==== entry=00b12d20 name=FUN_00b12d20 size=77 ====

void FUN_00b12d20(long param_1,undefined8 *param_2)

{
  long lVar1;
  long lVar2;
  
  *(undefined8 **)(param_1 + 0x18) = param_2;
  *(undefined8 *)(param_1 + 8) = *param_2;
  lVar1 = *(long *)(param_1 + 8);
  lVar2 = FUN_00b10529();
  *(long *)(param_1 + 0x10) = lVar1 + lVar2;
  return;
}


// ==== entry=00b12d6e name=FUN_00b12d6e size=14 ====

undefined8 FUN_00b12d6e(undefined8 param_1)

{
  return param_1;
}


// ==== entry=00b12d7c name=FUN_00b12d7c size=60 ====

undefined8 FUN_00b12d7c(undefined8 param_1,undefined8 param_2)

{
  long lVar1;
  long *plVar2;
  
  plVar2 = (long *)FUN_00b12d6e(param_1);
  lVar1 = *plVar2;
  plVar2 = (long *)FUN_00b12d6e(param_2);
  return CONCAT71((int7)((ulong)*plVar2 >> 8),lVar1 == *plVar2);
}


// ==== entry=00b12db8 name=FUN_00b12db8 size=35 ====

void FUN_00b12db8(undefined8 param_1,void *param_2)

{
  operator_delete(param_2);
  return;
}


// ==== entry=00b12ddb name=FUN_00b12ddb size=27 ====

void FUN_00b12ddb(undefined8 param_1)

{
  FUN_00b0d994(param_1);
  return;
}


// ==== entry=00b12df6 name=FUN_00b12df6 size=42 ====

void FUN_00b12df6(undefined8 param_1,undefined8 param_2)

{
  FUN_00b13c6a(param_1,param_2,0);
  return;
}


// ==== entry=00b12e20 name=FUN_00b12e20 size=14 ====

undefined8 FUN_00b12e20(undefined8 param_1)

{
  return param_1;
}


// ==== entry=00b12e2e name=FUN_00b12e2e size=80 ====

void FUN_00b12e2e(undefined8 param_1,undefined8 param_2)

{
  undefined8 uVar1;
  undefined8 uVar2;
  
  uVar1 = FUN_00b12e20(param_2);
  uVar2 = identity_forward(0x20,param_1);
                    /* try { // try from 00b12e6c to 00b12e70 has its CatchHandler @ 00b12e73 */
  FUN_00b0d9b4(uVar2,uVar1);
  return;
}


// ==== entry=00b12e98 name=FUN_00b12e98 size=11 ====

void FUN_00b12e98(void)

{
  return;
}


// ==== entry=00b12ea4 name=FUN_00b12ea4 size=35 ====

void FUN_00b12ea4(undefined8 param_1,void *param_2)

{
  operator_delete(param_2);
  return;
}


// ==== entry=00b12ec7 name=FUN_00b12ec7 size=27 ====

void FUN_00b12ec7(string *param_1)

{
  std::string::~string(param_1);
  return;
}


// ==== entry=00b12ee2 name=FUN_00b12ee2 size=27 ====

void FUN_00b12ee2(undefined8 param_1)

{
  FUN_00b13cac(param_1);
  return;
}


// ==== entry=00b12efe name=FUN_00b12efe size=58 ====

void FUN_00b12efe(undefined8 *param_1)

{
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  return;
}


// ==== entry=00b12f38 name=FUN_00b12f38 size=83 ====

undefined8 FUN_00b12f38(undefined8 param_1,undefined8 param_2)

{
  undefined8 uVar1;
  undefined1 local_19 [9];
  
  FUN_00b11d08(local_19,param_1);
                    /* try { // try from 00b12f6a to 00b12f6e has its CatchHandler @ 00b12f84 */
  uVar1 = FUN_00b13cb7(local_19,param_2);
  FUN_00b11d3c(local_19);
  return uVar1;
}


// ==== entry=00b12fa6 name=FUN_00b12fa6 size=76 ====

void FUN_00b12fa6(undefined8 param_1,undefined8 *param_2,undefined8 *param_3)

{
  undefined8 uVar1;
  undefined8 *local_20;
  
  for (local_20 = param_2; local_20 < param_3; local_20 = local_20 + 1) {
                    /* try { // try from 00b12fd4 to 00b12fd8 has its CatchHandler @ 00b12fea */
    uVar1 = FUN_00b13c20(param_1);
    *local_20 = uVar1;
  }
  return;
}


// ==== entry=00b13029 name=FUN_00b13029 size=46 ====

void FUN_00b13029(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  FUN_00b13ce2(param_1,param_2,param_3);
  return;
}


// ==== entry=00b13058 name=FUN_00b13058 size=14 ====

undefined8 FUN_00b13058(undefined8 param_1)

{
  return param_1;
}


// ==== entry=00b13066 name=FUN_00b13066 size=31 ====

void FUN_00b13066(undefined8 param_1)

{
  FUN_00b13d06(param_1);
  return;
}


// ==== entry=00b13086 name=FUN_00b13086 size=11 ====

void FUN_00b13086(void)

{
  return;
}


// ==== entry=00b13092 name=FUN_00b13092 size=35 ====

void FUN_00b13092(undefined8 param_1,void *param_2)

{
  operator_delete(param_2);
  return;
}


// ==== entry=00b130b5 name=FUN_00b130b5 size=38 ====

void FUN_00b130b5(undefined8 param_1,undefined8 param_2)

{
  FUN_00b13d1f(param_1,param_2);
  return;
}


// ==== entry=00b130dc name=FUN_00b130dc size=27 ====

void FUN_00b130dc(undefined8 param_1)

{
  FUN_00b13d58(param_1);
  return;
}


// ==== entry=00b130f8 name=FUN_00b130f8 size=58 ====

void FUN_00b130f8(undefined8 *param_1)

{
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  return;
}


// ==== entry=00b13132 name=FUN_00b13132 size=83 ====

undefined8 FUN_00b13132(undefined8 param_1,undefined8 param_2)

{
  undefined8 uVar1;
  undefined1 local_19 [9];
  
  FUN_00b12000(local_19,param_1);
                    /* try { // try from 00b13164 to 00b13168 has its CatchHandler @ 00b1317e */
  uVar1 = FUN_00b13d63(local_19,param_2);
  FUN_00b12034(local_19);
  return uVar1;
}


// ==== entry=00b131a0 name=FUN_00b131a0 size=76 ====

void FUN_00b131a0(undefined8 param_1,undefined8 *param_2,undefined8 *param_3)

{
  undefined8 uVar1;
  undefined8 *local_20;
  
  for (local_20 = param_2; local_20 < param_3; local_20 = local_20 + 1) {
                    /* try { // try from 00b131ce to 00b131d2 has its CatchHandler @ 00b131e4 */
    uVar1 = FUN_00b13d8e(param_1);
    *local_20 = uVar1;
  }
  return;
}


// ==== entry=00b13224 name=FUN_00b13224 size=93 ====

void FUN_00b13224(long param_1,undefined8 *param_2)

{
  long lVar1;
  long lVar2;
  
  *(undefined8 **)(param_1 + 0x18) = param_2;
  *(undefined8 *)(param_1 + 8) = *param_2;
  lVar1 = *(long *)(param_1 + 8);
  lVar2 = FUN_00b13db8();
  *(long *)(param_1 + 0x10) = lVar1 + lVar2 * 0x30;
  return;
}


// ==== entry=00b13281 name=FUN_00b13281 size=46 ====

void FUN_00b13281(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  FUN_00b13dc8(param_1,param_2,param_3);
  return;
}


// ==== entry=00b132b0 name=FUN_00b132b0 size=14 ====

undefined8 FUN_00b132b0(undefined8 param_1)

{
  return param_1;
}


// ==== entry=00b132be name=FUN_00b132be size=31 ====

void FUN_00b132be(undefined8 param_1)

{
  FUN_00b13dec(param_1);
  return;
}


// ==== entry=00b132de name=FUN_00b132de size=11 ====

void FUN_00b132de(void)

{
  return;
}


// ==== entry=00b132ea name=FUN_00b132ea size=35 ====

void FUN_00b132ea(undefined8 param_1,void *param_2)

{
  operator_delete(param_2);
  return;
}


// ==== entry=00b1330e name=FUN_00b1330e size=27 ====

void FUN_00b1330e(undefined8 param_1)

{
  FUN_00b13df8(param_1);
  return;
}


// ==== entry=00b1332a name=FUN_00b1332a size=58 ====

void FUN_00b1332a(undefined8 *param_1)

{
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  return;
}


// ==== entry=00b13364 name=FUN_00b13364 size=83 ====

undefined8 FUN_00b13364(undefined8 param_1,undefined8 param_2)

{
  undefined8 uVar1;
  undefined1 local_19 [9];
  
  FUN_00b122b8(local_19,param_1);
                    /* try { // try from 00b13396 to 00b1339a has its CatchHandler @ 00b133b0 */
  uVar1 = FUN_00b13e03(local_19,param_2);
  FUN_00b122ec(local_19);
  return uVar1;
}


// ==== entry=00b133d2 name=FUN_00b133d2 size=76 ====

void FUN_00b133d2(undefined8 param_1,undefined8 *param_2,undefined8 *param_3)

{
  undefined8 uVar1;
  undefined8 *local_20;
  
  for (local_20 = param_2; local_20 < param_3; local_20 = local_20 + 1) {
                    /* try { // try from 00b13400 to 00b13404 has its CatchHandler @ 00b13416 */
    uVar1 = FUN_00b13ac6(param_1);
    *local_20 = uVar1;
  }
  return;
}


// ==== entry=00b13455 name=FUN_00b13455 size=46 ====

void FUN_00b13455(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  FUN_00b13e2e(param_1,param_2,param_3);
  return;
}


// ==== entry=00b13484 name=FUN_00b13484 size=14 ====

undefined8 FUN_00b13484(undefined8 param_1)

{
  return param_1;
}


// ==== entry=00b13492 name=FUN_00b13492 size=31 ====

void FUN_00b13492(undefined8 param_1)

{
  FUN_00b13e52(param_1);
  return;
}


// ==== entry=00b134b2 name=FUN_00b134b2 size=11 ====

void FUN_00b134b2(void)

{
  return;
}


// ==== entry=00b134be name=FUN_00b134be size=35 ====

void FUN_00b134be(undefined8 param_1,void *param_2)

{
  operator_delete(param_2);
  return;
}


// ==== entry=00b134e2 name=FUN_00b134e2 size=27 ====

void FUN_00b134e2(undefined8 param_1)

{
  FUN_00b13e5e(param_1);
  return;
}


// ==== entry=00b134fe name=FUN_00b134fe size=35 ====

void FUN_00b134fe(undefined8 param_1,void *param_2)

{
  operator_delete(param_2);
  return;
}


// ==== entry=00b13521 name=FUN_00b13521 size=27 ====

void FUN_00b13521(undefined8 param_1)

{
  FUN_00b0f40a(param_1);
  return;
}


// ==== entry=00b1353c name=FUN_00b1353c size=27 ====

void FUN_00b1353c(undefined8 param_1)

{
  FUN_00b13e6a(param_1);
  return;
}


// ==== entry=00b13558 name=FUN_00b13558 size=58 ====

void FUN_00b13558(undefined8 *param_1)

{
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  return;
}


// ==== entry=00b13592 name=FUN_00b13592 size=83 ====

undefined8 FUN_00b13592(undefined8 param_1,undefined8 param_2)

{
  undefined8 uVar1;
  undefined1 local_19 [9];
  
  FUN_00b1262e(local_19,param_1);
                    /* try { // try from 00b135c4 to 00b135c8 has its CatchHandler @ 00b135de */
  uVar1 = FUN_00b13e75(local_19,param_2);
  FUN_00b12662(local_19);
  return uVar1;
}


// ==== entry=00b13600 name=FUN_00b13600 size=76 ====

void FUN_00b13600(undefined8 param_1,undefined8 *param_2,undefined8 *param_3)

{
  undefined8 uVar1;
  undefined8 *local_20;
  
  for (local_20 = param_2; local_20 < param_3; local_20 = local_20 + 1) {
                    /* try { // try from 00b1362e to 00b13632 has its CatchHandler @ 00b13644 */
    uVar1 = FUN_00b13ea0(param_1);
    *local_20 = uVar1;
  }
  return;
}


// ==== entry=00b13684 name=FUN_00b13684 size=81 ====

void FUN_00b13684(long param_1,undefined8 *param_2)

{
  long lVar1;
  long lVar2;
  
  *(undefined8 **)(param_1 + 0x18) = param_2;
  *(undefined8 *)(param_1 + 8) = *param_2;
  lVar1 = *(long *)(param_1 + 8);
  lVar2 = FUN_00b11abd();
  *(long *)(param_1 + 0x10) = lVar1 + lVar2 * 4;
  return;
}


// ==== entry=00b136d5 name=FUN_00b136d5 size=46 ====

void FUN_00b136d5(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  FUN_00b13eca(param_1,param_2,param_3);
  return;
}


// ==== entry=00b13704 name=FUN_00b13704 size=14 ====

undefined8 FUN_00b13704(undefined8 param_1)

{
  return param_1;
}


// ==== entry=00b13712 name=FUN_00b13712 size=31 ====

void FUN_00b13712(undefined8 param_1)

{
  FUN_00b13eee(param_1);
  return;
}


// ==== entry=00b13732 name=FUN_00b13732 size=11 ====

void FUN_00b13732(void)

{
  return;
}


// ==== entry=00b1373e name=FUN_00b1373e size=35 ====

void FUN_00b1373e(undefined8 param_1,void *param_2)

{
  operator_delete(param_2);
  return;
}


// ==== entry=00b13761 name=FUN_00b13761 size=16 ====

void FUN_00b13761(void)

{
  FUN_00b0d748(0x40);
  return;
}


// ==== entry=00b13772 name=FUN_00b13772 size=27 ====

void FUN_00b13772(undefined8 param_1)

{
  FUN_00b13efa(param_1);
  return;
}


// ==== entry=00b1378e name=FUN_00b1378e size=22 ====

void FUN_00b1378e(undefined8 *param_1)

{
  *param_1 = 0;
  return;
}


// ==== entry=00b137a4 name=FUN_00b137a4 size=26 ====

void FUN_00b137a4(undefined8 param_1)

{
  FUN_00b13f05(param_1);
  return;
}


// ==== entry=00b137be name=FUN_00b137be size=26 ====

void FUN_00b137be(undefined8 param_1)

{
  FUN_00b13f13(param_1);
  return;
}


// ==== entry=00b137d8 name=FUN_00b137d8 size=72 ====

void FUN_00b137d8(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  undefined8 uVar1;
  undefined8 uVar2;
  
  uVar1 = FUN_00b111ba(param_3);
  uVar2 = identity_forward(8,param_2);
  FUN_00b13f2e(uVar2,uVar1);
  return;
}


// ==== entry=00b13820 name=FUN_00b13820 size=201 ====

ulong FUN_00b13820(undefined8 param_1,ulong param_2,char *param_3)

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
  lVar1 = FUN_00b13f80(param_1);
  lVar2 = FUN_00b13fa2(local_30);
  if (local_38 <= (ulong)(lVar1 - lVar2)) {
    lVar1 = FUN_00b13fa2(local_30);
    local_28 = FUN_00b13fa2(local_30);
    plVar3 = (long *)FUN_00b06d34(&local_28,&local_38);
    local_20 = *plVar3 + lVar1;
    uVar4 = FUN_00b13fa2(local_30);
    if ((local_20 < uVar4) || (uVar4 = FUN_00b13f80(local_30), uVar4 < local_20)) {
      local_20 = FUN_00b13f80(local_30);
    }
    return local_20;
  }
                    /* WARNING: Subroutine does not return */
  std::__throw_length_error(param_3);
}


// ==== entry=00b138ea name=FUN_00b138ea size=37 ====

undefined8 FUN_00b138ea(undefined8 param_1)

{
  undefined8 local_10;
  
  FUN_00b129f2(&local_10,param_1);
  return local_10;
}


// ==== entry=00b1390f name=FUN_00b1390f size=64 ====

long FUN_00b1390f(undefined8 param_1,undefined8 param_2)

{
  long lVar1;
  long *plVar2;
  
  plVar2 = (long *)FUN_00b13984(param_1);
  lVar1 = *plVar2;
  plVar2 = (long *)FUN_00b13984(param_2);
  return lVar1 - *plVar2 >> 3;
}


// ==== entry=00b13950 name=FUN_00b13950 size=51 ====

undefined8 FUN_00b13950(undefined8 param_1,long param_2)

{
  undefined8 uVar1;
  
  if (param_2 == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = FUN_00b13fc5(param_1,param_2);
  }
  return uVar1;
}


// ==== entry=00b13984 name=FUN_00b13984 size=14 ====

undefined8 FUN_00b13984(undefined8 param_1)

{
  return param_1;
}


// ==== entry=00b13992 name=FUN_00b13992 size=84 ====

void FUN_00b13992(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 uVar1;
  undefined8 uVar2;
  
  uVar1 = FUN_00b13fef(param_2);
  uVar2 = FUN_00b13fef(param_1);
  FUN_00b14014(uVar2,uVar1,param_3,param_4);
  return;
}


// ==== entry=00b139e6 name=FUN_00b139e6 size=38 ====

void FUN_00b139e6(undefined8 param_1,undefined8 param_2)

{
  FUN_00b14046(param_1,param_2);
  return;
}


// ==== entry=00b13a0c name=FUN_00b13a0c size=26 ====

void FUN_00b13a0c(undefined8 param_1)

{
  FUN_00b14065(param_1);
  return;
}


// ==== entry=00b13a26 name=FUN_00b13a26 size=64 ====

void FUN_00b13a26(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  undefined8 uVar1;
  undefined8 *puVar2;
  
  puVar2 = (undefined8 *)FUN_00b112fd(param_3);
  uVar1 = *puVar2;
  puVar2 = (undefined8 *)identity_forward(8,param_2);
  *puVar2 = uVar1;
  return;
}


// ==== entry=00b13a66 name=FUN_00b13a66 size=95 ====

void FUN_00b13a66(long *param_1,long param_2)

{
  if ((ulong)(param_1[1] - (param_1[9] - *param_1 >> 3)) < param_2 + 1U) {
    FUN_00b14080(param_1,param_2,0);
  }
  return;
}


// ==== entry=00b13ac6 name=FUN_00b13ac6 size=42 ====

void FUN_00b13ac6(undefined8 param_1)

{
  undefined8 uVar1;
  
  uVar1 = FUN_00b0d748(8);
  FUN_00b142a0(param_1,uVar1);
  return;
}


// ==== entry=00b13af0 name=FUN_00b13af0 size=135 ====

void FUN_00b13af0(undefined4 *param_1,undefined4 *param_2)

{
  *param_1 = *param_2;
  param_1[1] = param_2[1];
  *(undefined8 *)(param_1 + 2) = *(undefined8 *)(param_2 + 2);
  param_1[4] = param_2[4];
  std::string::string((string *)(param_1 + 6),(string *)(param_2 + 6));
  FUN_00b142d8(param_1 + 8,param_2 + 8);
  param_1[0xe] = param_2[0xe];
  return;
}


// ==== entry=00b13b78 name=FUN_00b13b78 size=72 ====

void FUN_00b13b78(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  undefined8 uVar1;
  undefined8 uVar2;
  
  uVar1 = FUN_00b11392(param_3);
  uVar2 = identity_forward(0x40,param_2);
  FUN_00b13af0(uVar2,uVar1);
  return;
}


// ==== entry=00b13bc0 name=FUN_00b13bc0 size=95 ====

void FUN_00b13bc0(long *param_1,long param_2)

{
  if ((ulong)(param_1[1] - (param_1[9] - *param_1 >> 3)) < param_2 + 1U) {
    FUN_00b1430c(param_1,param_2,0);
  }
  return;
}


// ==== entry=00b13c20 name=FUN_00b13c20 size=42 ====

void FUN_00b13c20(undefined8 param_1)

{
  undefined8 uVar1;
  
  uVar1 = FUN_00b0d748(0x40);
  FUN_00b1452c(param_1,uVar1);
  return;
}


// ==== entry=00b13c4a name=FUN_00b13c4a size=16 ====

void FUN_00b13c4a(void)

{
  FUN_00b0d748(8);
  return;
}


// ==== entry=00b13c5a name=FUN_00b13c5a size=16 ====

void FUN_00b13c5a(void)

{
  FUN_00b0d748(8);
  return;
}


// ==== entry=00b13c6a name=FUN_00b13c6a size=66 ====

void FUN_00b13c6a(undefined8 param_1,ulong param_2)

{
  ulong uVar1;
  
  uVar1 = FUN_00b14556(param_1);
  if (uVar1 < param_2) {
                    /* WARNING: Subroutine does not return */
    std::__throw_bad_alloc();
  }
  operator_new(param_2 << 5);
  return;
}


// ==== entry=00b13cac name=FUN_00b13cac size=11 ====

void FUN_00b13cac(void)

{
  return;
}


// ==== entry=00b13cb7 name=FUN_00b13cb7 size=42 ====

void FUN_00b13cb7(undefined8 param_1,undefined8 param_2)

{
  FUN_00b1456a(param_1,param_2,0);
  return;
}


// ==== entry=00b13ce2 name=FUN_00b13ce2 size=35 ====

void FUN_00b13ce2(undefined8 param_1,void *param_2)

{
  operator_delete(param_2);
  return;
}


// ==== entry=00b13d06 name=FUN_00b13d06 size=11 ====

void FUN_00b13d06(void)

{
  return;
}


// ==== entry=00b13d11 name=FUN_00b13d11 size=14 ====

undefined8 FUN_00b13d11(undefined8 param_1)

{
  return param_1;
}


// ==== entry=00b13d1f name=FUN_00b13d1f size=56 ====

void FUN_00b13d1f(long param_1,long param_2)

{
  undefined8 uVar1;
  undefined8 local_10;
  
  for (local_10 = param_1; local_10 != param_2; local_10 = local_10 + 0x40) {
    uVar1 = FUN_00b13d11(local_10);
    FUN_00b145ac(uVar1);
  }
  return;
}


// ==== entry=00b13d58 name=FUN_00b13d58 size=11 ====

void FUN_00b13d58(void)

{
  return;
}


// ==== entry=00b13d63 name=FUN_00b13d63 size=42 ====

void FUN_00b13d63(undefined8 param_1,undefined8 param_2)

{
  FUN_00b145c8(param_1,param_2,0);
  return;
}


// ==== entry=00b13d8e name=FUN_00b13d8e size=42 ====

void FUN_00b13d8e(undefined8 param_1)

{
  undefined8 uVar1;
  
  uVar1 = FUN_00b0d748(0x30);
  FUN_00b1460a(param_1,uVar1);
  return;
}


// ==== entry=00b13db8 name=FUN_00b13db8 size=16 ====

void FUN_00b13db8(void)

{
  FUN_00b0d748(0x30);
  return;
}


// ==== entry=00b13dc8 name=FUN_00b13dc8 size=35 ====

void FUN_00b13dc8(undefined8 param_1,void *param_2)

{
  operator_delete(param_2);
  return;
}


// ==== entry=00b13dec name=FUN_00b13dec size=11 ====

void FUN_00b13dec(void)

{
  return;
}


// ==== entry=00b13df8 name=FUN_00b13df8 size=11 ====

void FUN_00b13df8(void)

{
  return;
}


// ==== entry=00b13e03 name=FUN_00b13e03 size=42 ====

void FUN_00b13e03(undefined8 param_1,undefined8 param_2)

{
  FUN_00b14634(param_1,param_2,0);
  return;
}


// ==== entry=00b13e2e name=FUN_00b13e2e size=35 ====

void FUN_00b13e2e(undefined8 param_1,void *param_2)

{
  operator_delete(param_2);
  return;
}


// ==== entry=00b13e52 name=FUN_00b13e52 size=11 ====

void FUN_00b13e52(void)

{
  return;
}


// ==== entry=00b13e5e name=FUN_00b13e5e size=11 ====

void FUN_00b13e5e(void)

{
  return;
}


// ==== entry=00b13e6a name=FUN_00b13e6a size=11 ====

void FUN_00b13e6a(void)

{
  return;
}


// ==== entry=00b13e75 name=FUN_00b13e75 size=42 ====

void FUN_00b13e75(undefined8 param_1,undefined8 param_2)

{
  FUN_00b14676(param_1,param_2,0);
  return;
}


// ==== entry=00b13ea0 name=FUN_00b13ea0 size=42 ====

void FUN_00b13ea0(undefined8 param_1)

{
  undefined8 uVar1;
  
  uVar1 = FUN_00b0d748(4);
  FUN_00b146b8(param_1,uVar1);
  return;
}


// ==== entry=00b13eca name=FUN_00b13eca size=35 ====

void FUN_00b13eca(undefined8 param_1,void *param_2)

{
  operator_delete(param_2);
  return;
}


// ==== entry=00b13eee name=FUN_00b13eee size=11 ====

void FUN_00b13eee(void)

{
  return;
}


// ==== entry=00b13efa name=FUN_00b13efa size=11 ====

void FUN_00b13efa(void)

{
  return;
}


// ==== entry=00b13f05 name=FUN_00b13f05 size=14 ====

undefined8 FUN_00b13f05(undefined8 param_1)

{
  return param_1;
}


// ==== entry=00b13f13 name=FUN_00b13f13 size=26 ====

void FUN_00b13f13(undefined8 param_1)

{
  FUN_00b146e2(param_1);
  return;
}


// ==== entry=00b13f2e name=FUN_00b13f2e size=82 ====

void FUN_00b13f2e(undefined8 param_1,undefined8 param_2)

{
  undefined8 uVar1;
  undefined8 uVar2;
  
  uVar1 = FUN_00b10238(param_2);
  uVar1 = FUN_00b14725(uVar1);
  uVar2 = FUN_00b146f0(param_2);
  FUN_00b14734(param_1,uVar2,uVar1);
  return;
}


// ==== entry=00b13f80 name=FUN_00b13f80 size=34 ====

void FUN_00b13f80(undefined8 param_1)

{
  undefined8 uVar1;
  
  uVar1 = FUN_00b1478e(param_1);
  FUN_00b14773(uVar1);
  return;
}


