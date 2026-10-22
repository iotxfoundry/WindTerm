// Ghidra 12.1.4 decompiled — WindTerm 2.7.0 (sha256 9491b87e…) part 14
// ==== entry=00509452 name=FUN_00509452 size=65 ====

void FUN_00509452(void)

{
  long unaff_R12;
  long in_stack_00000018;
  long in_stack_00000020;
  long in_stack_00000028;
  
  if (in_stack_00000028 + -0x18 != unaff_R12) {
    FUN_0094fc60();
  }
  if (in_stack_00000020 + -0x18 != unaff_R12) {
    FUN_0094fc60();
  }
  if (in_stack_00000018 + -0x18 != unaff_R12) {
    FUN_0094fc60();
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00509493 name=FUN_00509493 size=21 ====

void FUN_00509493(void)

{
  long unaff_R12;
  long in_stack_00000018;
  long in_stack_00000028;
  
  if (in_stack_00000028 + -0x18 != unaff_R12) {
    FUN_0094fc60();
  }
  if (in_stack_00000018 + -0x18 != unaff_R12) {
    FUN_0094fc60();
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=005094a8 name=FUN_005094a8 size=83 ====

void FUN_005094a8(void)

{
  QMapNodeBase *unaff_RBP;
  long unaff_R12;
  undefined1 *in_stack_00000028;
  
  if (in_stack_00000028 != &DAT_011c5338) {
    FUN_0094fc60();
  }
  if (*(int *)unaff_RBP != 0) {
    if (*(int *)unaff_RBP == -1) goto LAB_005094e5;
    LOCK();
    *(int *)unaff_RBP = *(int *)unaff_RBP + -1;
    UNLOCK();
    if (*(int *)unaff_RBP != 0) goto LAB_005094e5;
  }
  if (*(long *)(unaff_R12 + 0x10) != 0) {
    QMapDataBase::freeTree(unaff_RBP,(int)*(long *)(unaff_R12 + 0x10));
  }
  QMapDataBase::freeData((QMapDataBase *)unaff_RBP);
LAB_005094e5:
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=005094fc name=FUN_005094fc size=16 ====

void FUN_005094fc(void)

{
  void *unaff_R13;
  
  operator_delete(unaff_R13);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050950c name=FUN_0050950c size=31 ====

void FUN_0050950c(void)

{
  undefined1 *in_stack_00000008;
  
  if (in_stack_00000008 != &DAT_011c5338) {
    FUN_0094fc60();
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050952c name=FUN_0050952c size=52 ====

void FUN_0050952c(void)

{
  QArrayData *in_stack_00000018;
  
  if (*(int *)in_stack_00000018 != 0) {
    if (*(int *)in_stack_00000018 == -1) goto LAB_00509546;
    LOCK();
    *(int *)in_stack_00000018 = *(int *)in_stack_00000018 + -1;
    UNLOCK();
    if (*(int *)in_stack_00000018 != 0) goto LAB_00509546;
  }
  QArrayData::deallocate(in_stack_00000018,2,8);
LAB_00509546:
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00509560 name=FUN_00509560 size=22 ====

void FUN_00509560(void)

{
  long unaff_RBX;
  
  if (*(void **)(unaff_RBX + 0x10) != (void *)0x0) {
    operator_delete(*(void **)(unaff_RBX + 0x10));
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00509576 name=FUN_00509576 size=22 ====

void FUN_00509576(void)

{
  long unaff_RBP;
  
  if (*(void **)(unaff_RBP + 0x18) != (void *)0x0) {
    operator_delete(*(void **)(unaff_RBP + 0x18));
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050958c name=FUN_0050958c size=21 ====

void FUN_0050958c(void)

{
  undefined8 *unaff_R14;
  
  if ((void *)*unaff_R14 != (void *)0x0) {
    operator_delete((void *)*unaff_R14);
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=005095a2 name=FUN_005095a2 size=22 ====

void FUN_005095a2(void)

{
  void *unaff_retaddr;
  
  if (unaff_retaddr != (void *)0x0) {
    operator_delete(unaff_retaddr);
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=005095b8 name=FUN_005095b8 size=22 ====

void FUN_005095b8(void)

{
  long unaff_RBX;
  
  if (*(void **)(unaff_RBX + 0x10) != (void *)0x0) {
    operator_delete(*(void **)(unaff_RBX + 0x10));
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=005095ce name=FUN_005095ce size=22 ====

void FUN_005095ce(void)

{
  long unaff_RBX;
  
  if (*(void **)(unaff_RBX + 0x18) != (void *)0x0) {
    operator_delete(*(void **)(unaff_RBX + 0x18));
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=005095f0 name=FUN_005095f0 size=33 ====

int FUN_005095f0(undefined8 param_1,undefined8 param_2,long param_3)

{
  long *unaff_RBP;
  int unaff_R14D;
  
  if (param_3 == 1) {
    __cxa_begin_catch();
    __cxa_end_catch();
    return unaff_R14D - *(int *)(*unaff_RBP + 0x14);
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00509612 name=FUN_00509612 size=22 ====

void FUN_00509612(void)

{
                    /* WARNING: Subroutine does not return */
  __cxa_throw();
}


// ==== entry=00509628 name=FUN_00509628 size=16 ====

void FUN_00509628(void)

{
  __cxa_free_exception();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00509638 name=FUN_00509638 size=11 ====

void FUN_00509638(void)

{
  undefined1 *unaff_RBX;
  
  *unaff_RBX = 0;
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00509644 name=FUN_00509644 size=9 ====

void FUN_00509644(void)

{
  undefined1 *unaff_R15;
  
  *unaff_R15 = 0;
                    /* WARNING: Subroutine does not return */
  std::terminate();
}


// ==== entry=0050964d name=FUN_0050964d size=47 ====

void FUN_0050964d(void)

{
  void *unaff_RBX;
  void *unaff_R13;
  void *unaff_R14;
  
  operator_delete(unaff_R13,0x60);
  operator_delete(unaff_R14,0x20);
  operator_delete(unaff_RBX,0x10);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050967c name=FUN_0050967c size=15 ====

void FUN_0050967c(void)

{
  void *unaff_RBX;
  void *unaff_R13;
  void *unaff_R14;
  
  operator_delete(unaff_R13,0x30);
  operator_delete(unaff_R14,0x20);
  operator_delete(unaff_RBX,0x10);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050968c name=FUN_0050968c size=22 ====

void FUN_0050968c(void)

{
                    /* WARNING: Subroutine does not return */
  __cxa_throw();
}


// ==== entry=005096a2 name=FUN_005096a2 size=16 ====

void FUN_005096a2(void)

{
  __cxa_free_exception();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=005096b2 name=FUN_005096b2 size=13 ====

void FUN_005096b2(void)

{
  undefined1 *unaff_R12;
  
  *unaff_R12 = 0;
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=005096c0 name=FUN_005096c0 size=31 ====

void FUN_005096c0(void)

{
  byte unaff_R12B;
  undefined7 unaff_000000a1;
  
  if ((CONCAT71(unaff_000000a1,unaff_R12B) != 0) && ((unaff_R12B & 1) != 0)) {
    QReadWriteLock::unlock();
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=005096e0 name=FUN_005096e0 size=31 ====

void FUN_005096e0(void)

{
  byte unaff_R12B;
  undefined7 unaff_000000a1;
  
  if ((CONCAT71(unaff_000000a1,unaff_R12B) != 0) && ((unaff_R12B & 1) != 0)) {
    QReadWriteLock::unlock();
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00509700 name=FUN_00509700 size=25 ====

void FUN_00509700(void)

{
  byte unaff_R12B;
  undefined7 unaff_000000a1;
  
  if ((CONCAT71(unaff_000000a1,unaff_R12B) != 0) && ((unaff_R12B & 1) != 0)) {
    QReadWriteLock::unlock();
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00509719 name=FUN_00509719 size=31 ====

void FUN_00509719(void)

{
  byte unaff_R15B;
  undefined7 unaff_000000b9;
  
  if ((CONCAT71(unaff_000000b9,unaff_R15B) != 0) && ((unaff_R15B & 1) != 0)) {
    QReadWriteLock::unlock();
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00509738 name=FUN_00509738 size=31 ====

void FUN_00509738(void)

{
  ulong in_stack_00000008;
  
  if ((in_stack_00000008 != 0) && ((in_stack_00000008 & 1) != 0)) {
    QReadWriteLock::unlock();
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00509758 name=FUN_00509758 size=41 ====

void FUN_00509758(void)

{
  QListView *unaff_RBX;
  
  *(undefined ***)unaff_RBX = &HtmlList_vtable;
  *(undefined ***)(unaff_RBX + 0x10) = &PTR_FUN_01199510;
  QListView::~QListView(unaff_RBX);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00509782 name=FUN_00509782 size=16 ====

void FUN_00509782(void)

{
  QKeyEvent *unaff_RBX;
  
  QKeyEvent::~QKeyEvent(unaff_RBX);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00509792 name=FUN_00509792 size=52 ====

void FUN_00509792(void)

{
  QArrayData *in_stack_00000018;
  
  if (*(int *)in_stack_00000018 != 0) {
    if (*(int *)in_stack_00000018 == -1) goto LAB_005097ac;
    LOCK();
    *(int *)in_stack_00000018 = *(int *)in_stack_00000018 + -1;
    UNLOCK();
    if (*(int *)in_stack_00000018 != 0) goto LAB_005097ac;
  }
  QArrayData::deallocate(in_stack_00000018,2,8);
LAB_005097ac:
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=005097c6 name=FUN_005097c6 size=56 ====

void FUN_005097c6(void)

{
  QAbstractListModel *unaff_RBX;
  void *unaff_RBP;
  
  operator_delete(unaff_RBP,0xb0);
  *(undefined ***)unaff_RBX = &HtmlListModel_vtable;
  *(undefined ***)(unaff_RBX + 0x10) = &PTR_ActionHandler_vt2_011991f0;
  QAbstractListModel::~QAbstractListModel(unaff_RBX);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=005097fe name=FUN_005097fe size=32 ====

void FUN_005097fe(void)

{
  QIcon *unaff_R12;
  
  QIcon::~QIcon(unaff_R12);
  qt_array_data_unref();
  qt_array_data_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050981e name=FUN_0050981e size=24 ====

void FUN_0050981e(void)

{
  qt_array_data_unref();
  qt_array_data_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00509836 name=FUN_00509836 size=31 ====

void FUN_00509836(void)

{
  QFont *unaff_R15;
  void *in_stack_00000008;
  
  operator_delete(in_stack_00000008,8);
  QFont::~QFont(unaff_R15);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00509856 name=FUN_00509856 size=16 ====

void FUN_00509856(void)

{
  qt_array_data_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00509866 name=FUN_00509866 size=29 ====

void FUN_00509866(void)

{
  qt_array_data_unref();
  qt_array_data_unref(&stack0x00000018);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00509884 name=FUN_00509884 size=60 ====

/* WARNING: Removing unreachable block (ram,0x005098b5) */

void FUN_00509884(void)

{
  int *piVar1;
  int iVar2;
  void *unaff_R14;
  long in_stack_00000028;
  
  if ((void *)(in_stack_00000028 + -0x18) != unaff_R14) {
    LOCK();
    piVar1 = (int *)(in_stack_00000028 + -8);
    iVar2 = *piVar1;
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if (iVar2 < 1) {
      operator_delete((void *)(in_stack_00000028 + -0x18));
    }
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=005098c0 name=FUN_005098c0 size=12 ====

void FUN_005098c0(void)

{
  long unaff_RBX;
  
  *(undefined1 *)(unaff_RBX + 0xc) = 0;
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=005098cc name=FUN_005098cc size=21 ====

void FUN_005098cc(void)

{
  void *unaff_RBX;
  
  operator_delete(unaff_RBX,0x50);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=005098e2 name=FUN_005098e2 size=260 ====

void FUN_005098e2(void)

{
  ulong *puVar1;
  void *pvVar2;
  long unaff_RBX;
  void *pvVar3;
  ulong uVar4;
  undefined8 in_stack_00000008;
  
  if (*(long **)(unaff_RBX + 400) != (long *)0x0) {
    (**(code **)(**(long **)(unaff_RBX + 400) + 8))();
  }
  if (*(long **)(unaff_RBX + 0x180) != (long *)0x0) {
    (**(code **)(**(long **)(unaff_RBX + 0x180) + 8))();
  }
  puVar1 = *(ulong **)(unaff_RBX + 0x178);
  if (puVar1 != (ulong *)0x0) {
    pvVar3 = (void *)puVar1[2];
    for (uVar4 = 0; uVar4 < *puVar1; uVar4 = uVar4 + 1) {
      pvVar2 = *(void **)((long)pvVar3 + uVar4 * 8);
      if (pvVar2 != (void *)0x0) {
        scanner_resetState(pvVar2);
        operator_delete(pvVar2,0x40);
        pvVar3 = (void *)puVar1[2];
      }
      *(undefined8 *)((long)pvVar3 + uVar4 * 8) = 0;
    }
    if (pvVar3 != (void *)puVar1[3]) {
      puVar1[3] = (ulong)pvVar3;
    }
    *puVar1 = 0;
    puVar1[1] = 0;
    if (pvVar3 != (void *)0x0) {
      operator_delete(pvVar3);
    }
    operator_delete(puVar1,0x28);
  }
  if (*(long **)(unaff_RBX + 0x170) != (long *)0x0) {
    (**(code **)(**(long **)(unaff_RBX + 0x170) + 8))();
  }
  pvVar3 = *(void **)(unaff_RBX + 0x168);
  if (pvVar3 != (void *)0x0) {
    FUN_0099a362(pvVar3);
    operator_delete(pvVar3,0x10);
  }
  if (*(long **)(unaff_RBX + 0x160) != (long *)0x0) {
    (**(code **)(**(long **)(unaff_RBX + 0x160) + 8))();
  }
  FUN_0096bb02();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception(in_stack_00000008);
}


// ==== entry=005099e6 name=FUN_005099e6 size=16 ====

void FUN_005099e6(void)

{
  FUN_0096bb02();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=005099f6 name=FUN_005099f6 size=16 ====

void FUN_005099f6(void)

{
  FUN_0096bb02();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00509a06 name=FUN_00509a06 size=16 ====

void FUN_00509a06(void)

{
  FUN_0096bb02();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00509a16 name=FUN_00509a16 size=50 ====

void FUN_00509a16(void)

{
  undefined8 in_stack_00000018;
  
  FUN_0096bb02();
  FUN_0096bb02(&stack0x00000060);
  FUN_0096bb02();
  FUN_0096bb02(in_stack_00000018);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00509a48 name=FUN_00509a48 size=44 ====

void FUN_00509a48(void)

{
  long in_stack_00000008;
  void *in_stack_00000040;
  
  free(in_stack_00000040);
  FUN_00a5ab92(in_stack_00000008 + 0x90);
  qt_array_data_unref(in_stack_00000008 + 0x38);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00509a74 name=FUN_00509a74 size=21 ====

void FUN_00509a74(void)

{
  void *unaff_RBP;
  
  operator_delete(unaff_RBP,0x10);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00509a8a name=FUN_00509a8a size=33 ====

int FUN_00509a8a(undefined8 param_1,undefined8 param_2,long param_3)

{
  long *unaff_RBP;
  int unaff_R14D;
  
  if (param_3 == 1) {
    __cxa_begin_catch();
    __cxa_end_catch();
    return unaff_R14D - *(int *)(*unaff_RBP + 0x14);
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00509aac name=FUN_00509aac size=11 ====

void FUN_00509aac(void)

{
  undefined1 *unaff_RBX;
  
  *unaff_RBX = 0;
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00509ab8 name=FUN_00509ab8 size=22 ====

void FUN_00509ab8(void)

{
                    /* WARNING: Subroutine does not return */
  __cxa_throw();
}


// ==== entry=00509ace name=FUN_00509ace size=16 ====

void FUN_00509ace(void)

{
  __cxa_free_exception();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00509ade name=FUN_00509ade size=33 ====

int FUN_00509ade(undefined8 param_1,undefined8 param_2,long param_3)

{
  long *unaff_RBP;
  int unaff_R14D;
  
  if (param_3 == 1) {
    __cxa_begin_catch();
    __cxa_end_catch();
    return unaff_R14D - *(int *)(*unaff_RBP + 0x14);
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00509b00 name=FUN_00509b00 size=11 ====

void FUN_00509b00(void)

{
  undefined1 *unaff_RBX;
  
  *unaff_RBX = 0;
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00509b0c name=FUN_00509b0c size=22 ====

void FUN_00509b0c(void)

{
                    /* WARNING: Subroutine does not return */
  __cxa_throw();
}


// ==== entry=00509b22 name=FUN_00509b22 size=16 ====

void FUN_00509b22(void)

{
  __cxa_free_exception();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00509b32 name=FUN_00509b32 size=11 ====

void FUN_00509b32(void)

{
  undefined1 *unaff_RBX;
  
  *unaff_RBX = 0;
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00509b3e name=FUN_00509b3e size=12 ====

void FUN_00509b3e(void)

{
  undefined1 *unaff_R14;
  
  *unaff_R14 = 0;
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00509b4a name=FUN_00509b4a size=9 ====

void FUN_00509b4a(void)

{
  undefined1 *unaff_R15;
  
  *unaff_R15 = 0;
                    /* WARNING: Subroutine does not return */
  std::terminate();
}


// ==== entry=00509b53 name=FUN_00509b53 size=34 ====

void FUN_00509b53(void)

{
  void *unaff_RBP;
  void *unaff_R12;
  
  operator_delete(unaff_R12,0x60);
  operator_delete(unaff_RBP,0x20);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00509b75 name=FUN_00509b75 size=15 ====

void FUN_00509b75(void)

{
  void *unaff_RBP;
  void *unaff_R12;
  
  operator_delete(unaff_R12,0x30);
  operator_delete(unaff_RBP,0x20);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00509b84 name=FUN_00509b84 size=11 ====

void FUN_00509b84(void)

{
  undefined1 *unaff_RBX;
  
  *unaff_RBX = 0;
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00509b90 name=FUN_00509b90 size=44 ====

void FUN_00509b90(void)

{
  undefined8 in_stack_00000008;
  long in_stack_00000010;
  
  FUN_0096bb02(in_stack_00000008);
  FUN_00a5ab92(in_stack_00000010 + 0x90);
  qt_array_data_unref(in_stack_00000010 + 0x38);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00509bbc name=FUN_00509bbc size=12 ====

void FUN_00509bbc(void)

{
  undefined8 in_stack_00000008;
  long in_stack_00000010;
  
  FUN_0096bb02(in_stack_00000008);
  FUN_00a5ab92(in_stack_00000010 + 0x90);
  qt_array_data_unref(in_stack_00000010 + 0x38);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00509bc8 name=FUN_00509bc8 size=12 ====

void FUN_00509bc8(void)

{
  undefined8 in_stack_00000008;
  long in_stack_00000010;
  
  FUN_0096bb02(in_stack_00000008);
  FUN_00a5ab92(in_stack_00000010 + 0x90);
  qt_array_data_unref(in_stack_00000010 + 0x38);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00509bd4 name=FUN_00509bd4 size=14 ====

void FUN_00509bd4(void)

{
  undefined8 in_stack_00000008;
  long in_stack_00000010;
  
  FUN_0096bb02(in_stack_00000008);
  FUN_00a5ab92(in_stack_00000010 + 0x90);
  qt_array_data_unref(in_stack_00000010 + 0x38);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00509be2 name=FUN_00509be2 size=12 ====

void FUN_00509be2(void)

{
  undefined8 in_stack_00000008;
  long in_stack_00000010;
  
  FUN_0096bb02(in_stack_00000008);
  FUN_00a5ab92(in_stack_00000010 + 0x90);
  qt_array_data_unref(in_stack_00000010 + 0x38);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00509bee name=FUN_00509bee size=34 ====

void FUN_00509bee(void)

{
  long in_stack_00000010;
  
  FUN_00a5ab92(in_stack_00000010 + 0x90);
  qt_array_data_unref(in_stack_00000010 + 0x38);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00509c10 name=FUN_00509c10 size=16 ====

void FUN_00509c10(void)

{
  FUN_0096bb02();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00509c20 name=FUN_00509c20 size=16 ====

void FUN_00509c20(void)

{
  FUN_0096bb02();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00509c30 name=FUN_00509c30 size=34 ====

void FUN_00509c30(void)

{
  void *unaff_RBX;
  void *unaff_RBP;
  
  operator_delete(unaff_RBX,0x30);
  operator_delete(unaff_RBP,0x20);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00509c52 name=FUN_00509c52 size=15 ====

void FUN_00509c52(void)

{
  void *unaff_RBX;
  void *unaff_RBP;
  
  operator_delete(unaff_RBX,0x60);
  operator_delete(unaff_RBP,0x20);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00509c62 name=FUN_00509c62 size=23 ====

void FUN_00509c62(void)

{
  void *in_stack_00000040;
  
  if (in_stack_00000040 != (void *)0x0) {
    operator_delete(in_stack_00000040);
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00509c79 name=FUN_00509c79 size=18 ====

void FUN_00509c79(void)

{
  undefined8 in_stack_00000018;
  
  FUN_0096bb02(in_stack_00000018);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00509c8b name=FUN_00509c8b size=18 ====

void FUN_00509c8b(void)

{
  undefined8 in_stack_00000018;
  
  FUN_0096bb02(in_stack_00000018);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00509c9e name=FUN_00509c9e size=18 ====

void FUN_00509c9e(void)

{
  undefined8 in_stack_00000008;
  
  FUN_00a161d8(in_stack_00000008);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00509cb0 name=FUN_00509cb0 size=21 ====

void FUN_00509cb0(void)

{
  void *unaff_RBP;
  
  operator_delete(unaff_RBP,0x40);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00509cc5 name=FUN_00509cc5 size=34 ====

void FUN_00509cc5(void)

{
  void *unaff_RBP;
  void *unaff_R13;
  
  operator_delete(unaff_RBP,0x50);
  operator_delete(unaff_R13,0x20);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00509ce7 name=FUN_00509ce7 size=15 ====

void FUN_00509ce7(void)

{
  void *unaff_RBP;
  void *unaff_R13;
  
  operator_delete(unaff_RBP,0x30);
  operator_delete(unaff_R13,0x20);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00509cf6 name=FUN_00509cf6 size=13 ====

void FUN_00509cf6(void)

{
  undefined1 *in_stack_00000030;
  
  *in_stack_00000030 = 0;
                    /* WARNING: Subroutine does not return */
  std::terminate();
}


// ==== entry=00509d04 name=FUN_00509d04 size=16 ====

void FUN_00509d04(void)

{
  FUN_0096bb02();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00509d14 name=FUN_00509d14 size=16 ====

void FUN_00509d14(void)

{
  FUN_0096bb02();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00509d24 name=FUN_00509d24 size=23 ====

void FUN_00509d24(void)

{
  void *in_stack_00000010;
  
  if (in_stack_00000010 != (void *)0x0) {
    operator_delete(in_stack_00000010);
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00509d3c name=FUN_00509d3c size=23 ====

void FUN_00509d3c(void)

{
  void *in_stack_00000030;
  
  if (in_stack_00000030 != (void *)0x0) {
    operator_delete(in_stack_00000030);
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00509d54 name=FUN_00509d54 size=12 ====

void FUN_00509d54(void)

{
  long unaff_RBX;
  
  *(undefined1 *)(unaff_RBX + 0x20) = 0;
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00509d60 name=FUN_00509d60 size=21 ====

void FUN_00509d60(void)

{
  void *unaff_RBX;
  
  operator_delete(unaff_RBX,0x10);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00509d75 name=FUN_00509d75 size=21 ====

void FUN_00509d75(void)

{
  void *unaff_RBX;
  
  operator_delete(unaff_RBX,0x18);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00509d8a name=FUN_00509d8a size=48 ====

void FUN_00509d8a(void)

{
  QVariant *unaff_RBX;
  undefined8 unaff_retaddr;
  QVariant *in_stack_00000008;
  undefined8 in_stack_00000010;
  
  QVariant::~QVariant(unaff_RBX);
  qt_array_data_unref(in_stack_00000010);
  QVariant::~QVariant(in_stack_00000008);
  qt_array_data_unref(unaff_retaddr);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00509dba name=FUN_00509dba size=39 ====

void FUN_00509dba(void)

{
  QVariant *unaff_RBX;
  QVariant *in_stack_00000008;
  undefined8 in_stack_00000010;
  
  QVariant::~QVariant(unaff_RBX);
  qt_array_data_unref(in_stack_00000010);
  QVariant::~QVariant(in_stack_00000008);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00509de2 name=FUN_00509de2 size=26 ====

void FUN_00509de2(void)

{
  undefined8 in_stack_00000008;
  
  atomic_refptr_delete(in_stack_00000008);
  qmap_freetree_variant_nodes();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00509dfc name=FUN_00509dfc size=45 ====

void FUN_00509dfc(void)

{
  QVariant *unaff_RBX;
  QVariant *unaff_RBP;
  undefined8 in_stack_00000008;
  
  QVariant::~QVariant(unaff_RBX);
  qt_array_data_unref();
  QVariant::~QVariant(unaff_RBP);
  qt_array_data_unref(in_stack_00000008);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00509e29 name=FUN_00509e29 size=35 ====

void FUN_00509e29(void)

{
  QVariant *unaff_RBX;
  QVariant *unaff_RBP;
  
  QVariant::~QVariant(unaff_RBX);
  qt_array_data_unref();
  QVariant::~QVariant(unaff_RBP);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00509e4c name=FUN_00509e4c size=35 ====

void FUN_00509e4c(void)

{
  QVariant *unaff_RBX;
  QVariant *unaff_RBP;
  
  QVariant::~QVariant(unaff_RBP);
  qt_array_data_unref();
  QVariant::~QVariant(unaff_RBX);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00509e6f name=FUN_00509e6f size=41 ====

void FUN_00509e6f(void)

{
  QVariant *unaff_RBX;
  QVariant *unaff_R13;
  undefined8 unaff_retaddr;
  
  atomic_refptr_delete();
  QVariant::~QVariant(unaff_RBX);
  qt_array_data_unref(unaff_retaddr);
  QVariant::~QVariant(unaff_R13);
  qmap_freetree_variant_nodes();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00509e98 name=FUN_00509e98 size=35 ====

void FUN_00509e98(void)

{
  QVariant *unaff_RBX;
  QVariant *unaff_RBP;
  
  QVariant::~QVariant(unaff_RBP);
  qt_array_data_unref();
  QVariant::~QVariant(unaff_RBX);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00509ebc name=FUN_00509ebc size=34 ====

void FUN_00509ebc(void)

{
  QVariant *unaff_R15;
  QVariant *in_stack_00000058;
  
  QVariant::~QVariant(in_stack_00000058);
  qt_array_data_unref();
  QVariant::~QVariant(unaff_R15);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00509ede name=FUN_00509ede size=160 ====

/* WARNING: Removing unreachable block (ram,0x00509efe) */
/* WARNING: Removing unreachable block (ram,0x00509f10) */

void FUN_00509ede(void)

{
  QVariant *in_stack_00000038;
  
  QVariant::~QVariant((QVariant *)&stack0x000000a0);
  qt_array_data_unref(&stack0x00000070);
  QVariant::~QVariant((QVariant *)&stack0x00000090);
  QVariant::~QVariant((QVariant *)&stack0x000000c0);
  qt_array_data_unref(&stack0x00000078);
  QVariant::~QVariant(in_stack_00000038);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00509f7e name=FUN_00509f7e size=30 ====

/* WARNING: Removing unreachable block (ram,0x00509efe) */
/* WARNING: Removing unreachable block (ram,0x00509f10) */
/* WARNING: Removing unreachable block (ram,0x00509f22) */

void FUN_00509f7e(void)

{
  QVariant *in_stack_00000038;
  
  qt_array_data_unref(&stack0x00000070);
  QVariant::~QVariant((QVariant *)&stack0x00000090);
  QVariant::~QVariant((QVariant *)&stack0x000000c0);
  qt_array_data_unref(&stack0x00000078);
  QVariant::~QVariant(in_stack_00000038);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00509f9c name=FUN_00509f9c size=27 ====

/* WARNING: Removing unreachable block (ram,0x00509f22) */
/* WARNING: Removing unreachable block (ram,0x00509efe) */
/* WARNING: Removing unreachable block (ram,0x00509f10) */
/* WARNING: Removing unreachable block (ram,0x00509f34) */

void FUN_00509f9c(void)

{
  QVariant *in_stack_00000038;
  
  QVariant::~QVariant((QVariant *)&stack0x00000090);
  QVariant::~QVariant((QVariant *)&stack0x000000c0);
  qt_array_data_unref(&stack0x00000078);
  QVariant::~QVariant(in_stack_00000038);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00509fb7 name=FUN_00509fb7 size=24 ====

/* WARNING: Removing unreachable block (ram,0x00509f22) */
/* WARNING: Removing unreachable block (ram,0x00509efe) */
/* WARNING: Removing unreachable block (ram,0x00509f10) */
/* WARNING: Removing unreachable block (ram,0x00509f34) */
/* WARNING: Removing unreachable block (ram,0x00509f43) */

void FUN_00509fb7(void)

{
  QVariant *in_stack_00000038;
  
  qt_array_data_unref(&stack0x00000078);
  QVariant::~QVariant(in_stack_00000038);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00509fcf name=FUN_00509fcf size=21 ====

/* WARNING: Removing unreachable block (ram,0x00509f43) */
/* WARNING: Removing unreachable block (ram,0x00509f22) */
/* WARNING: Removing unreachable block (ram,0x00509efe) */
/* WARNING: Removing unreachable block (ram,0x00509f10) */
/* WARNING: Removing unreachable block (ram,0x00509f34) */
/* WARNING: Removing unreachable block (ram,0x00509f62) */

void FUN_00509fcf(void)

{
  QVariant *in_stack_00000038;
  
  QVariant::~QVariant(in_stack_00000038);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00509fe4 name=FUN_00509fe4 size=34 ====

void FUN_00509fe4(void)

{
  QVariant *unaff_R15;
  QVariant *in_stack_00000058;
  
  QVariant::~QVariant(in_stack_00000058);
  qt_array_data_unref();
  QVariant::~QVariant(unaff_R15);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050a006 name=FUN_0050a006 size=112 ====

void FUN_0050a006(void)

{
  char cVar1;
  char unaff_R12B;
  QVariant *unaff_R14;
  QVariant *in_stack_00000038;
  
  QVariant::~QVariant(unaff_R14);
  cVar1 = '\0';
  if (unaff_R12B != '\0') {
    qt_array_data_unref(&stack0x00000080);
    cVar1 = unaff_R12B;
  }
  if (cVar1 != '\0') {
    QVariant::~QVariant((QVariant *)&stack0x000000d0);
    QVariant::~QVariant((QVariant *)&stack0x00000100);
    qt_array_data_unref(&stack0x00000088);
  }
  if (unaff_R12B != '\0') {
    QVariant::~QVariant((QVariant *)&stack0x000000f0);
    QVariant::~QVariant((QVariant *)&stack0x000000a0);
    qt_array_data_unref(&stack0x00000070);
    QVariant::~QVariant((QVariant *)&stack0x00000090);
    QVariant::~QVariant((QVariant *)&stack0x000000c0);
    qt_array_data_unref(&stack0x00000078);
  }
  QVariant::~QVariant(in_stack_00000038);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050a076 name=FUN_0050a076 size=20 ====

void FUN_0050a076(void)

{
  char unaff_R12B;
  QVariant *in_stack_00000038;
  
  if (unaff_R12B != '\0') {
    QVariant::~QVariant((QVariant *)&stack0x000000d0);
    QVariant::~QVariant((QVariant *)&stack0x00000100);
    qt_array_data_unref(&stack0x00000088);
    QVariant::~QVariant((QVariant *)&stack0x000000f0);
    QVariant::~QVariant((QVariant *)&stack0x000000a0);
    qt_array_data_unref(&stack0x00000070);
    QVariant::~QVariant((QVariant *)&stack0x00000090);
    QVariant::~QVariant((QVariant *)&stack0x000000c0);
    qt_array_data_unref(&stack0x00000078);
  }
  QVariant::~QVariant(in_stack_00000038);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050a08a name=FUN_0050a08a size=20 ====

void FUN_0050a08a(void)

{
  char unaff_R12B;
  QVariant *in_stack_00000038;
  
  if (unaff_R12B != '\0') {
    qt_array_data_unref(&stack0x00000088);
    QVariant::~QVariant((QVariant *)&stack0x000000f0);
    QVariant::~QVariant((QVariant *)&stack0x000000a0);
    qt_array_data_unref(&stack0x00000070);
    QVariant::~QVariant((QVariant *)&stack0x00000090);
    QVariant::~QVariant((QVariant *)&stack0x000000c0);
    qt_array_data_unref(&stack0x00000078);
  }
  QVariant::~QVariant(in_stack_00000038);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050a09e name=FUN_0050a09e size=19 ====

/* WARNING: Removing unreachable block (ram,0x00509efe) */

void FUN_0050a09e(void)

{
  char unaff_R12B;
  QVariant *in_stack_00000038;
  
  if (unaff_R12B != '\0') {
    QVariant::~QVariant((QVariant *)&stack0x000000f0);
    QVariant::~QVariant((QVariant *)&stack0x000000a0);
    qt_array_data_unref(&stack0x00000070);
    QVariant::~QVariant((QVariant *)&stack0x00000090);
    QVariant::~QVariant((QVariant *)&stack0x000000c0);
    qt_array_data_unref(&stack0x00000078);
  }
  QVariant::~QVariant(in_stack_00000038);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050a0b1 name=FUN_0050a0b1 size=21 ====

void FUN_0050a0b1(void)

{
  void *unaff_RBP;
  
  operator_delete(unaff_RBP,0x20);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050a0c6 name=FUN_0050a0c6 size=52 ====

void FUN_0050a0c6(void)

{
  QVariant *unaff_RBX;
  QVariant *in_stack_00000008;
  undefined8 in_stack_00000018;
  
  QVariant::~QVariant(unaff_RBX);
  qt_array_data_unref(in_stack_00000018);
  QVariant::~QVariant(in_stack_00000008);
  qmap_freetree_variant_nodes(&stack0x00000040);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050a0fa name=FUN_0050a0fa size=23 ====

void FUN_0050a0fa(void)

{
  QVariant *unaff_RBX;
  undefined8 in_stack_00000010;
  
  qt_array_data_unref(in_stack_00000010);
  QVariant::~QVariant(unaff_RBX);
  qmap_freetree_variant_nodes();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050a111 name=FUN_0050a111 size=17 ====

void FUN_0050a111(void)

{
  undefined8 in_stack_00000010;
  
  qmap_freetree_variant_nodes(in_stack_00000010);
  qmap_freetree_variant_nodes(&stack0x00000040);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050a122 name=FUN_0050a122 size=38 ====

void FUN_0050a122(void)

{
  QVariant *unaff_RBX;
  QVariant *in_stack_00000010;
  undefined8 in_stack_00000018;
  
  QVariant::~QVariant(unaff_RBX);
  qt_array_data_unref(in_stack_00000018);
  QVariant::~QVariant(in_stack_00000010);
  qmap_freetree_variant_nodes(&stack0x00000040);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050a148 name=FUN_0050a148 size=26 ====

void FUN_0050a148(void)

{
  QVariant *unaff_RBX;
  undefined8 in_stack_00000008;
  
  qt_array_data_unref(in_stack_00000008);
  QVariant::~QVariant(unaff_RBX);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050a162 name=FUN_0050a162 size=39 ====

void FUN_0050a162(void)

{
  QVariant *unaff_RBX;
  QVariant *in_stack_00000008;
  undefined8 in_stack_00000010;
  
  QVariant::~QVariant(unaff_RBX);
  qt_array_data_unref(in_stack_00000010);
  QVariant::~QVariant(in_stack_00000008);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050a189 name=FUN_0050a189 size=39 ====

void FUN_0050a189(void)

{
  QVariant *unaff_RBX;
  QVariant *in_stack_00000008;
  undefined8 in_stack_00000010;
  
  QVariant::~QVariant(unaff_RBX);
  qt_array_data_unref(in_stack_00000010);
  QVariant::~QVariant(in_stack_00000008);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050a1b0 name=FUN_0050a1b0 size=26 ====

void FUN_0050a1b0(void)

{
  QVariant *unaff_RBX;
  undefined8 in_stack_00000010;
  
  qt_array_data_unref(in_stack_00000010);
  QVariant::~QVariant(unaff_RBX);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050a1ca name=FUN_0050a1ca size=39 ====

void FUN_0050a1ca(void)

{
  QVariant *unaff_RBX;
  QVariant *in_stack_00000010;
  undefined8 in_stack_00000018;
  
  QVariant::~QVariant(unaff_RBX);
  qt_array_data_unref(in_stack_00000018);
  QVariant::~QVariant(in_stack_00000010);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050a1f1 name=FUN_0050a1f1 size=39 ====

void FUN_0050a1f1(void)

{
  QVariant *unaff_RBX;
  QVariant *in_stack_00000010;
  undefined8 in_stack_00000018;
  
  QVariant::~QVariant(unaff_RBX);
  qt_array_data_unref(in_stack_00000018);
  QVariant::~QVariant(in_stack_00000010);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050a218 name=FUN_0050a218 size=26 ====

void FUN_0050a218(void)

{
  QVariant *unaff_RBX;
  undefined8 in_stack_00000010;
  
  qt_array_data_unref(in_stack_00000010);
  QVariant::~QVariant(unaff_RBX);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050a240 name=FUN_0050a240 size=21 ====

void FUN_0050a240(void)

{
  void *unaff_RBX;
  
  operator_delete(unaff_RBX,0x20);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050a256 name=FUN_0050a256 size=16 ====

void FUN_0050a256(void)

{
  FUN_00a8dc88();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050a270 name=FUN_0050a270 size=22 ====

void FUN_0050a270(void)

{
                    /* WARNING: Subroutine does not return */
  __cxa_throw();
}


// ==== entry=0050a286 name=FUN_0050a286 size=22 ====

void FUN_0050a286(void)

{
                    /* WARNING: Subroutine does not return */
  __cxa_throw();
}


// ==== entry=0050a29c name=FUN_0050a29c size=16 ====

void FUN_0050a29c(void)

{
  __cxa_free_exception();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050a2ac name=FUN_0050a2ac size=16 ====

void FUN_0050a2ac(void)

{
  __cxa_free_exception();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050a2bc name=FUN_0050a2bc size=33 ====

int FUN_0050a2bc(undefined8 param_1,undefined8 param_2,long param_3)

{
  long *unaff_RBP;
  int unaff_R14D;
  
  if (param_3 == 1) {
    __cxa_begin_catch();
    __cxa_end_catch();
    return unaff_R14D - *(int *)(*unaff_RBP + 0x14);
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050a2de name=FUN_0050a2de size=11 ====

void FUN_0050a2de(void)

{
  undefined1 *unaff_RBX;
  
  *unaff_RBX = 0;
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050a2ea name=FUN_0050a2ea size=21 ====

void FUN_0050a2ea(void)

{
  void *unaff_RBP;
  
  operator_delete(unaff_RBP,0x28);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050a300 name=FUN_0050a300 size=25 ====

void FUN_0050a300(void)

{
  byte unaff_R13B;
  undefined7 unaff_000000a9;
  
  if ((CONCAT71(unaff_000000a9,unaff_R13B) != 0) && ((unaff_R13B & 1) != 0)) {
    QReadWriteLock::unlock();
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050a319 name=FUN_0050a319 size=31 ====

void FUN_0050a319(void)

{
  byte unaff_R13B;
  undefined7 unaff_000000a9;
  
  if ((CONCAT71(unaff_000000a9,unaff_R13B) != 0) && ((unaff_R13B & 1) != 0)) {
    QReadWriteLock::unlock();
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050a338 name=FUN_0050a338 size=25 ====

void FUN_0050a338(void)

{
  byte unaff_R15B;
  undefined7 unaff_000000b9;
  
  if ((CONCAT71(unaff_000000b9,unaff_R15B) != 0) && ((unaff_R15B & 1) != 0)) {
    QReadWriteLock::unlock();
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050a352 name=FUN_0050a352 size=31 ====

void FUN_0050a352(void)

{
  byte unaff_R14B;
  undefined7 unaff_000000b1;
  
  if ((CONCAT71(unaff_000000b1,unaff_R14B) != 0) && ((unaff_R14B & 1) != 0)) {
    QReadWriteLock::unlock();
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050a371 name=FUN_0050a371 size=31 ====

void FUN_0050a371(void)

{
  byte unaff_R13B;
  undefined7 unaff_000000a9;
  
  if ((CONCAT71(unaff_000000a9,unaff_R13B) != 0) && ((unaff_R13B & 1) != 0)) {
    QReadWriteLock::unlock();
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050a390 name=FUN_0050a390 size=31 ====

void FUN_0050a390(void)

{
  byte unaff_R12B;
  undefined7 unaff_000000a1;
  
  if ((CONCAT71(unaff_000000a1,unaff_R12B) != 0) && ((unaff_R12B & 1) != 0)) {
    QReadWriteLock::unlock();
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050a3b0 name=FUN_0050a3b0 size=37 ====

void FUN_0050a3b0(void)

{
  ulong in_stack_00000008;
  
  if ((in_stack_00000008 != 0) && ((in_stack_00000008 & 1) != 0)) {
    QReadWriteLock::unlock();
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050a3d5 name=FUN_0050a3d5 size=37 ====

void FUN_0050a3d5(void)

{
  ulong in_stack_00000008;
  
  if ((in_stack_00000008 != 0) && ((in_stack_00000008 & 1) != 0)) {
    QReadWriteLock::unlock();
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050a3fa name=FUN_0050a3fa size=22 ====

void FUN_0050a3fa(void)

{
                    /* WARNING: Subroutine does not return */
  __cxa_throw();
}


// ==== entry=0050a410 name=FUN_0050a410 size=16 ====

void FUN_0050a410(void)

{
  __cxa_free_exception();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050a420 name=FUN_0050a420 size=21 ====

void FUN_0050a420(void)

{
  void *unaff_RBX;
  
  operator_delete(unaff_RBX,0x30);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050a435 name=FUN_0050a435 size=17 ====

void FUN_0050a435(void)

{
  long unaff_RBP;
  
  FUN_0096ab16(unaff_RBP + 0x40);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050a446 name=FUN_0050a446 size=31 ====

void FUN_0050a446(void)

{
  byte unaff_R14B;
  undefined7 unaff_000000b1;
  
  if ((CONCAT71(unaff_000000b1,unaff_R14B) != 0) && ((unaff_R14B & 1) != 0)) {
    QReadWriteLock::unlock();
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050a466 name=FUN_0050a466 size=37 ====

void FUN_0050a466(void)

{
  ulong in_stack_00000008;
  
  if ((in_stack_00000008 != 0) && ((in_stack_00000008 & 1) != 0)) {
    QReadWriteLock::unlock();
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050a48b name=FUN_0050a48b size=31 ====

void FUN_0050a48b(void)

{
  byte unaff_R15B;
  undefined7 unaff_000000b9;
  
  if ((CONCAT71(unaff_000000b9,unaff_R15B) != 0) && ((unaff_R15B & 1) != 0)) {
    QReadWriteLock::unlock();
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050a4aa name=FUN_0050a4aa size=37 ====

void FUN_0050a4aa(void)

{
  ulong in_stack_00000008;
  
  if ((in_stack_00000008 != 0) && ((in_stack_00000008 & 1) != 0)) {
    QReadWriteLock::unlock();
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050a4d0 name=FUN_0050a4d0 size=24 ====

void FUN_0050a4d0(void)

{
  FUN_0096bb02();
  FUN_0096bb02();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050a4e8 name=FUN_0050a4e8 size=26 ====

void FUN_0050a4e8(void)

{
  long unaff_RBX;
  
  FUN_0096bb02(unaff_RBX + 0x20);
  FUN_0096bb02(unaff_RBX + 8);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050a502 name=FUN_0050a502 size=26 ====

void FUN_0050a502(void)

{
  long unaff_RBX;
  
  FUN_0096bb02(unaff_RBX + 0x20);
  FUN_0096bb02(unaff_RBX + 8);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050a520 name=FUN_0050a520 size=12 ====

void FUN_0050a520(void)

{
  undefined1 *unaff_R15;
  
  *unaff_R15 = 0;
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050a52c name=FUN_0050a52c size=32 ====

void FUN_0050a52c(void)

{
  QVariant *unaff_RBX;
  QVariant *unaff_RBP;
  
  QVariant::~QVariant(unaff_RBX);
  qt_array_data_unref();
  QVariant::~QVariant(unaff_RBP);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050a54c name=FUN_0050a54c size=7 ====

void FUN_0050a54c(void)

{
  QVariant::~QVariant((QVariant *)&stack0x00000010);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050a554 name=FUN_0050a554 size=13 ====

void FUN_0050a554(void)

{
  long unaff_R13;
  
  *(undefined1 *)(unaff_R13 + 0x70) = 0;
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050a562 name=FUN_0050a562 size=12 ====

void FUN_0050a562(void)

{
  long unaff_RBX;
  
  *(undefined1 *)(unaff_RBX + 0x70) = 0;
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050a56e name=FUN_0050a56e size=12 ====

void FUN_0050a56e(void)

{
  long unaff_RBP;
  
  *(undefined1 *)(unaff_RBP + 0x70) = 0;
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050a57a name=FUN_0050a57a size=12 ====

void FUN_0050a57a(void)

{
  long unaff_RBX;
  
  *(undefined1 *)(unaff_RBX + 0x70) = 0;
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050a586 name=FUN_0050a586 size=25 ====

void FUN_0050a586(void)

{
  long unaff_RBP;
  undefined8 in_stack_00000018;
  
  FUN_0096bb02(in_stack_00000018);
  *(undefined1 *)(unaff_RBP + 0x70) = 0;
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050a5a0 name=FUN_0050a5a0 size=12 ====

void FUN_0050a5a0(void)

{
  long unaff_RBX;
  
  *(undefined1 *)(unaff_RBX + 0x70) = 0;
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050a5ac name=FUN_0050a5ac size=41 ====

void FUN_0050a5ac(void)

{
  char cVar1;
  long *unaff_RBP;
  
  cVar1 = qatomic_int_deref(*unaff_RBP + 0x10);
  if (cVar1 == '\0') {
    QHashData::free_helper((_func_void_Node_ptr *)*unaff_RBP);
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050a5d6 name=FUN_0050a5d6 size=24 ====

void FUN_0050a5d6(void)

{
  QVariant *unaff_RBX;
  
  qt_array_data_unref();
  QVariant::~QVariant(unaff_RBX);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050a5ee name=FUN_0050a5ee size=54 ====

void FUN_0050a5ee(void)

{
  QVariant *unaff_R15;
  undefined8 in_stack_00000040;
  undefined8 in_stack_00000050;
  undefined8 in_stack_00000058;
  
  qt_array_data_unref();
  QVariant::~QVariant(unaff_R15);
  FUN_009700a4(in_stack_00000050);
  qmap_freetree_variant_nodes(in_stack_00000058);
  qmap_freetree_variant_nodes(in_stack_00000040);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050a624 name=FUN_0050a624 size=32 ====

void FUN_0050a624(void)

{
  undefined8 in_stack_00000038;
  undefined8 in_stack_00000040;
  QVariant *in_stack_00000048;
  undefined8 in_stack_00000050;
  undefined8 in_stack_00000058;
  undefined8 in_stack_00000068;
  
  qt_array_data_unref(in_stack_00000068);
  QVariant::~QVariant(in_stack_00000048);
  qt_array_data_unref(in_stack_00000038);
  FUN_009700a4(in_stack_00000050);
  qmap_freetree_variant_nodes(in_stack_00000058);
  qmap_freetree_variant_nodes(in_stack_00000040);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050a644 name=FUN_0050a644 size=14 ====

void FUN_0050a644(void)

{
  QVariant *unaff_R15;
  undefined8 in_stack_00000040;
  undefined8 in_stack_00000050;
  undefined8 in_stack_00000058;
  
  qt_array_data_unref();
  QVariant::~QVariant(unaff_R15);
  FUN_009700a4(in_stack_00000050);
  qmap_freetree_variant_nodes(in_stack_00000058);
  qmap_freetree_variant_nodes(in_stack_00000040);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050a652 name=FUN_0050a652 size=10 ====

void FUN_0050a652(void)

{
  QVariant *unaff_R15;
  undefined8 in_stack_00000040;
  undefined8 in_stack_00000050;
  undefined8 in_stack_00000058;
  
  qt_array_data_unref();
  QVariant::~QVariant(unaff_R15);
  FUN_009700a4(in_stack_00000050);
  qmap_freetree_variant_nodes(in_stack_00000058);
  qmap_freetree_variant_nodes(in_stack_00000040);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050a65c name=FUN_0050a65c size=28 ====

void FUN_0050a65c(void)

{
  QVariant *unaff_R15;
  undefined8 in_stack_00000040;
  undefined8 in_stack_00000050;
  undefined8 in_stack_00000058;
  undefined8 in_stack_00000060;
  
  qt_array_data_unref();
  QVariant::~QVariant(unaff_R15);
  qt_array_data_unref(in_stack_00000060);
  FUN_009700a4(in_stack_00000050);
  qmap_freetree_variant_nodes(in_stack_00000058);
  qmap_freetree_variant_nodes(in_stack_00000040);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050a678 name=FUN_0050a678 size=56 ====

void FUN_0050a678(void)

{
  char in_stack_00000040;
  code *in_stack_00000058;
  code *in_stack_00000060;
  
  if (in_stack_00000040 != '\0') {
    if (in_stack_00000058 == (code *)0x0) {
                    /* WARNING: Subroutine does not return */
      std::__throw_bad_function_call();
    }
    (*in_stack_00000060)(&stack0x00000048);
  }
  if (in_stack_00000058 != (code *)0x0) {
    (*in_stack_00000058)(&stack0x00000048,&stack0x00000048,3);
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050a68c name=FUN_0050a68c size=81 ====

void FUN_0050a68c(void)

{
  code *in_stack_00000010;
  code *in_stack_00000030;
  code *in_stack_00000058;
  
  if (in_stack_00000058 != (code *)0x0) {
    (*in_stack_00000058)(&stack0x00000048,&stack0x00000048,3);
  }
  if (in_stack_00000010 != (code *)0x0) {
    (*in_stack_00000010)();
  }
  if (in_stack_00000030 != (code *)0x0) {
    (*in_stack_00000030)(&stack0x00000020,&stack0x00000020,3);
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050a702 name=FUN_0050a702 size=12 ====

void FUN_0050a702(void)

{
  undefined1 *unaff_RBP;
  
  *unaff_RBP = 0;
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050a70e name=FUN_0050a70e size=12 ====

void FUN_0050a70e(void)

{
  undefined1 *unaff_RBP;
  
  *unaff_RBP = 0;
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050a71a name=FUN_0050a71a size=22 ====

void FUN_0050a71a(void)

{
                    /* WARNING: Subroutine does not return */
  __cxa_throw();
}


// ==== entry=0050a730 name=FUN_0050a730 size=16 ====

void FUN_0050a730(void)

{
  __cxa_free_exception();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050a740 name=FUN_0050a740 size=22 ====

void FUN_0050a740(void)

{
                    /* WARNING: Subroutine does not return */
  __cxa_throw();
}


// ==== entry=0050a756 name=FUN_0050a756 size=16 ====

void FUN_0050a756(void)

{
  __cxa_free_exception();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050a766 name=FUN_0050a766 size=11 ====

void FUN_0050a766(void)

{
  undefined1 *unaff_RBX;
  
  *unaff_RBX = 0;
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050a772 name=FUN_0050a772 size=12 ====

void FUN_0050a772(void)

{
  undefined1 *unaff_R14;
  
  *unaff_R14 = 0;
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050a77e name=FUN_0050a77e size=11 ====

void FUN_0050a77e(void)

{
  undefined1 *unaff_RBX;
  
  *unaff_RBX = 0;
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050a78a name=FUN_0050a78a size=13 ====

void FUN_0050a78a(void)

{
  undefined1 *in_stack_00000010;
  
  *in_stack_00000010 = 0;
                    /* WARNING: Subroutine does not return */
  std::terminate();
}


// ==== entry=0050a797 name=FUN_0050a797 size=42 ====

void FUN_0050a797(void)

{
  void *unaff_RBX;
  void *unaff_RBP;
  long unaff_R13;
  
  operator_delete(unaff_RBX,0x30);
  operator_delete(unaff_RBP,0x20);
  *(undefined1 *)(unaff_R13 + 0x70) = 0;
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050a7c1 name=FUN_0050a7c1 size=15 ====

void FUN_0050a7c1(void)

{
  void *unaff_RBX;
  void *unaff_RBP;
  long unaff_R13;
  
  operator_delete(unaff_RBX,0x60);
  operator_delete(unaff_RBP,0x20);
  *(undefined1 *)(unaff_R13 + 0x70) = 0;
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050a7d0 name=FUN_0050a7d0 size=21 ====

void FUN_0050a7d0(void)

{
  long unaff_R13;
  long *in_stack_00000008;
  
  if ((long *)*in_stack_00000008 != (long *)0x0) {
    (**(code **)(*(long *)*in_stack_00000008 + 8))();
  }
  *(undefined1 *)(unaff_R13 + 0x70) = 0;
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050a7e6 name=FUN_0050a7e6 size=434 ====

void FUN_0050a7e6(void)

{
  undefined8 *puVar1;
  QMapNodeBase *pQVar2;
  long lVar3;
  long lVar4;
  long lVar5;
  char cVar6;
  long unaff_RBX;
  void *unaff_RBP;
  undefined8 unaff_R12;
  
  operator_delete(unaff_RBP,0x18);
  puVar1 = *(undefined8 **)(unaff_RBX + 0x58);
  if (puVar1 != (undefined8 *)0x0) {
    cVar6 = qatomic_int_deref(*puVar1);
    if (cVar6 == '\0') {
      pQVar2 = (QMapNodeBase *)*puVar1;
      lVar3 = *(long *)(pQVar2 + 0x10);
      if (lVar3 != 0) {
        qt_array_data_unref(lVar3 + 0x18);
        QVariant::~QVariant((QVariant *)(lVar3 + 0x20));
        lVar4 = *(long *)(lVar3 + 8);
        if (lVar4 != 0) {
          qt_array_data_unref(lVar4 + 0x18);
          QVariant::~QVariant((QVariant *)(lVar4 + 0x20));
          lVar5 = *(long *)(lVar4 + 8);
          if (lVar5 != 0) {
            qt_array_data_unref(lVar5 + 0x18);
            QVariant::~QVariant((QVariant *)(lVar5 + 0x20));
            if (*(long *)(lVar5 + 8) != 0) {
              qmap_node_list_destruct();
            }
            if (*(long *)(lVar5 + 0x10) != 0) {
              qmap_node_list_destruct();
            }
          }
          lVar4 = *(long *)(lVar4 + 0x10);
          if (lVar4 != 0) {
            qt_array_data_unref(lVar4 + 0x18);
            QVariant::~QVariant((QVariant *)(lVar4 + 0x20));
            if (*(long *)(lVar4 + 8) != 0) {
              qmap_node_list_destruct();
            }
            if (*(long *)(lVar4 + 0x10) != 0) {
              qmap_node_list_destruct();
            }
          }
        }
        lVar3 = *(long *)(lVar3 + 0x10);
        if (lVar3 != 0) {
          qt_array_data_unref(lVar3 + 0x18);
          QVariant::~QVariant((QVariant *)(lVar3 + 0x20));
          lVar4 = *(long *)(lVar3 + 8);
          if (lVar4 != 0) {
            qt_array_data_unref(lVar4 + 0x18);
            QVariant::~QVariant((QVariant *)(lVar4 + 0x20));
            if (*(long *)(lVar4 + 8) != 0) {
              qmap_node_list_destruct();
            }
            if (*(long *)(lVar4 + 0x10) != 0) {
              qmap_node_list_destruct();
            }
          }
          lVar3 = *(long *)(lVar3 + 0x10);
          if (lVar3 != 0) {
            qt_array_data_unref(lVar3 + 0x18);
            QVariant::~QVariant((QVariant *)(lVar3 + 0x20));
            if (*(long *)(lVar3 + 8) != 0) {
              qmap_node_list_destruct();
            }
            if (*(long *)(lVar3 + 0x10) != 0) {
              qmap_node_list_destruct();
            }
          }
        }
        QMapDataBase::freeTree(pQVar2,(int)*(undefined8 *)(pQVar2 + 0x10));
      }
      QMapDataBase::freeData((QMapDataBase *)pQVar2);
    }
    operator_delete(puVar1,8);
  }
  FUN_0096ff8c(unaff_RBX + 0x30);
  DocumentTask_metaObject();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception(unaff_R12);
}


// ==== entry=0050a998 name=FUN_0050a998 size=12 ====

void FUN_0050a998(void)

{
  long unaff_RBX;
  
  *(undefined1 *)(unaff_RBX + 0x70) = 0;
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050a9a4 name=FUN_0050a9a4 size=13 ====

void FUN_0050a9a4(void)

{
  long unaff_R14;
  
  *(undefined1 *)(unaff_R14 + 0x70) = 0;
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050a9b2 name=FUN_0050a9b2 size=14 ====

void FUN_0050a9b2(void)

{
  long unaff_R12;
  
  *(undefined1 *)(unaff_R12 + 0x70) = 0;
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050a9c0 name=FUN_0050a9c0 size=12 ====

void FUN_0050a9c0(void)

{
  undefined1 *unaff_R14;
  
  *unaff_R14 = 0;
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050a9d0 name=FUN_0050a9d0 size=22 ====

void FUN_0050a9d0(void)

{
                    /* WARNING: Subroutine does not return */
  __cxa_throw();
}


// ==== entry=0050a9e6 name=FUN_0050a9e6 size=16 ====

void FUN_0050a9e6(void)

{
  __cxa_free_exception();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050a9f6 name=FUN_0050a9f6 size=33 ====

int FUN_0050a9f6(undefined8 param_1,undefined8 param_2,long param_3)

{
  long *unaff_RBP;
  int unaff_R14D;
  
  if (param_3 == 1) {
    __cxa_begin_catch();
    __cxa_end_catch();
    return unaff_R14D - *(int *)(*unaff_RBP + 0x14);
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050aa18 name=FUN_0050aa18 size=11 ====

void FUN_0050aa18(void)

{
  undefined1 *unaff_RBX;
  
  *unaff_RBX = 0;
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050aa24 name=FUN_0050aa24 size=21 ====

void FUN_0050aa24(void)

{
  void *unaff_RBP;
  
  operator_delete(unaff_RBP,0x60);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050aa39 name=FUN_0050aa39 size=23 ====

void FUN_0050aa39(void)

{
  void *in_stack_00000008;
  
  operator_delete(in_stack_00000008,0x60);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050aa50 name=FUN_0050aa50 size=21 ====

void FUN_0050aa50(void)

{
  void *unaff_R12;
  
  operator_delete(unaff_R12,0x60);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050aa66 name=FUN_0050aa66 size=21 ====

void FUN_0050aa66(void)

{
  void *unaff_RBX;
  
  operator_delete(unaff_RBX,0x30);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050aa7b name=FUN_0050aa7b size=17 ====

void FUN_0050aa7b(void)

{
  long unaff_RBP;
  
  FUN_00973554(unaff_RBP + 0x30);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050aa8c name=FUN_0050aa8c size=37 ====

void FUN_0050aa8c(void)

{
  ulong in_stack_00000018;
  
  if ((in_stack_00000018 != 0) && ((in_stack_00000018 & 1) != 0)) {
    QReadWriteLock::unlock();
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050aab1 name=FUN_0050aab1 size=37 ====

void FUN_0050aab1(void)

{
  ulong in_stack_00000018;
  
  if ((in_stack_00000018 != 0) && ((in_stack_00000018 & 1) != 0)) {
    QReadWriteLock::unlock();
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050aad6 name=FUN_0050aad6 size=11 ====

void FUN_0050aad6(void)

{
  undefined1 *unaff_RBX;
  
  *unaff_RBX = 0;
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050aae2 name=FUN_0050aae2 size=21 ====

void FUN_0050aae2(void)

{
  void *unaff_RBP;
  
  operator_delete(unaff_RBP,0x30);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050aaf8 name=FUN_0050aaf8 size=39 ====

void FUN_0050aaf8(void)

{
  ulong in_stack_00000008;
  
  if ((in_stack_00000008 != 0) && ((in_stack_00000008 & 1) != 0)) {
    QReadWriteLock::unlock();
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050ab20 name=FUN_0050ab20 size=37 ====

void FUN_0050ab20(void)

{
  ulong in_stack_00000008;
  
  if ((in_stack_00000008 != 0) && ((in_stack_00000008 & 1) != 0)) {
    QReadWriteLock::unlock();
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050ab46 name=FUN_0050ab46 size=37 ====

void FUN_0050ab46(void)

{
  ulong in_stack_00000008;
  
  if ((in_stack_00000008 != 0) && ((in_stack_00000008 & 1) != 0)) {
    QReadWriteLock::unlock();
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050ab6c name=FUN_0050ab6c size=31 ====

void FUN_0050ab6c(void)

{
  byte unaff_R15B;
  undefined7 unaff_000000b9;
  
  if ((CONCAT71(unaff_000000b9,unaff_R15B) != 0) && ((unaff_R15B & 1) != 0)) {
    QReadWriteLock::unlock();
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050ab8c name=FUN_0050ab8c size=37 ====

void FUN_0050ab8c(void)

{
  ulong in_stack_00000008;
  
  if ((in_stack_00000008 != 0) && ((in_stack_00000008 & 1) != 0)) {
    QReadWriteLock::unlock();
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050abb2 name=FUN_0050abb2 size=37 ====

void FUN_0050abb2(void)

{
  ulong in_stack_00000018;
  
  if ((in_stack_00000018 != 0) && ((in_stack_00000018 & 1) != 0)) {
    QReadWriteLock::unlock();
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050abe0 name=FUN_0050abe0 size=33 ====

void FUN_0050abe0(void)

{
  undefined8 unaff_retaddr;
  
  FUN_0096bd50();
  FUN_0096bb02();
  FUN_0096bb02(unaff_retaddr);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050ac01 name=FUN_0050ac01 size=45 ====

void FUN_0050ac01(void)

{
  long unaff_RBX;
  long unaff_RBP;
  long lVar1;
  
  lVar1 = (6 - unaff_RBP) * 0x20 + unaff_RBX;
  while (lVar1 != unaff_RBX) {
    lVar1 = lVar1 + -0x20;
    qt_byte_array_unref(lVar1);
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050ac20 name=FUN_0050ac20 size=43 ====

void FUN_0050ac20(void)

{
  undefined8 in_RAX;
  undefined1 *unaff_RBX;
  undefined1 *puVar1;
  undefined8 uStack0000000000000008;
  
  puVar1 = &stack0x00000110;
  do {
    puVar1 = puVar1 + -0x20;
    uStack0000000000000008 = in_RAX;
    qt_byte_array_unref(puVar1);
    in_RAX = uStack0000000000000008;
  } while (puVar1 != unaff_RBX);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception(uStack0000000000000008);
}


// ==== entry=0050ac5a name=FUN_0050ac5a size=16 ====

void FUN_0050ac5a(void)

{
  qt_byte_array_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050ac6a name=FUN_0050ac6a size=18 ====

void FUN_0050ac6a(void)

{
  undefined8 in_stack_00000038;
  
  qt_byte_array_unref(in_stack_00000038);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050ac7c name=FUN_0050ac7c size=54 ====

void FUN_0050ac7c(void)

{
  long lVar1;
  long *unaff_RBX;
  undefined8 *puVar2;
  
  if (*unaff_RBX != 0) {
    lVar1 = unaff_RBX[9];
    for (puVar2 = (undefined8 *)unaff_RBX[5]; puVar2 < (undefined8 *)(lVar1 + 8U);
        puVar2 = puVar2 + 1) {
      operator_delete((void *)*puVar2);
    }
    operator_delete((void *)*unaff_RBX);
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050acb2 name=FUN_0050acb2 size=34 ====

void FUN_0050acb2(void)

{
  undefined8 in_stack_00000008;
  
  FUN_0096bd50();
  FUN_0096bb02(in_stack_00000008);
  FUN_0096bb02();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050acd4 name=FUN_0050acd4 size=24 ====

void FUN_0050acd4(void)

{
  splitvector_blocks_free();
  FUN_0096bd50();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050acec name=FUN_0050acec size=34 ====

void FUN_0050acec(void)

{
  undefined8 in_stack_00000008;
  
  splitvector_blocks_free(in_stack_00000008);
  FUN_0096bd50();
  splitvector_blocks_free();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050ad0e name=FUN_0050ad0e size=23 ====

void FUN_0050ad0e(void)

{
  undefined8 in_stack_00000008;
  
  FUN_0096bb02();
  FUN_0096bb02(in_stack_00000008);
  splitvector_blocks_free();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050ad25 name=FUN_0050ad25 size=13 ====

void FUN_0050ad25(void)

{
  undefined8 in_stack_00000008;
  
  FUN_0096bb02(in_stack_00000008);
  FUN_0096bd50();
  splitvector_blocks_free();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050ad32 name=FUN_0050ad32 size=12 ====

void FUN_0050ad32(void)

{
  undefined8 in_stack_00000008;
  
  FUN_0096bb02(in_stack_00000008);
  FUN_0096bd50();
  splitvector_blocks_free();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050ad3e name=FUN_0050ad3e size=16 ====

void FUN_0050ad3e(void)

{
  splitvector_blocks_free();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050ad4e name=FUN_0050ad4e size=26 ====

void FUN_0050ad4e(void)

{
  undefined8 in_stack_00000010;
  
  splitvector_blocks_free(in_stack_00000010);
  FUN_0096bd50();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050ad68 name=FUN_0050ad68 size=26 ====

void FUN_0050ad68(void)

{
  undefined8 in_stack_00000010;
  
  FUN_0096bb02();
  FUN_0096bb02(in_stack_00000010);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050ad82 name=FUN_0050ad82 size=12 ====

void FUN_0050ad82(void)

{
  undefined8 in_stack_00000010;
  
  FUN_0096bb02(in_stack_00000010);
  FUN_0096bd50();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050ad8e name=FUN_0050ad8e size=12 ====

void FUN_0050ad8e(void)

{
  undefined8 in_stack_00000010;
  
  FUN_0096bb02(in_stack_00000010);
  FUN_0096bd50();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050ad9a name=FUN_0050ad9a size=26 ====

void FUN_0050ad9a(void)

{
  undefined8 in_stack_00000010;
  
  splitvector_blocks_free(in_stack_00000010);
  FUN_0096bd50();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050adb4 name=FUN_0050adb4 size=36 ====

void FUN_0050adb4(void)

{
  long unaff_RBX;
  
  FUN_0096bd50();
  FUN_0096bb02();
  splitvector_blocks_free(unaff_RBX + 0x50);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050add8 name=FUN_0050add8 size=24 ====

void FUN_0050add8(void)

{
  FUN_0096bd50();
  FUN_0096bd50();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050adf0 name=FUN_0050adf0 size=16 ====

void FUN_0050adf0(void)

{
  FUN_0096bd50();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050ae00 name=FUN_0050ae00 size=54 ====

void FUN_0050ae00(void)

{
  undefined8 in_stack_00000008;
  undefined8 in_stack_00000028;
  
  FUN_0096bd50();
  FUN_0096bb02();
  FUN_0096bb02(in_stack_00000028);
  FUN_0096bd50(in_stack_00000008);
  FUN_0096bb02(&stack0x00000040);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050ae36 name=FUN_0050ae36 size=18 ====

void FUN_0050ae36(void)

{
  undefined8 in_stack_00000008;
  
  FUN_0096bd50();
  splitvector_blocks_free();
  FUN_0096bd50(in_stack_00000008);
  FUN_0096bb02(&stack0x00000040);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050ae48 name=FUN_0050ae48 size=10 ====

void FUN_0050ae48(void)

{
  undefined8 in_stack_00000008;
  
  FUN_0096bb02();
  FUN_0096bd50(in_stack_00000008);
  FUN_0096bb02(&stack0x00000040);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050ae52 name=FUN_0050ae52 size=18 ====

void FUN_0050ae52(void)

{
  undefined8 in_stack_00000010;
  
  FUN_0096bd50(in_stack_00000010);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050ae64 name=FUN_0050ae64 size=39 ====

void FUN_0050ae64(void)

{
  long lVar1;
  long in_stack_00000028;
  
  lVar1 = in_stack_00000028 + 0x38;
  do {
    lVar1 = lVar1 + -8;
    qt_byte_array_unref(lVar1);
  } while (lVar1 != in_stack_00000028);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050ae8b name=FUN_0050ae8b size=79 ====

void FUN_0050ae8b(void)

{
  long unaff_RBX;
  long in_stack_00000018;
  long in_stack_00000070;
  long in_stack_00000080;
  long in_stack_00000088;
  
  __cxa_begin_catch();
  while (in_stack_00000070 != unaff_RBX) {
    FUN_0096bd50(in_stack_00000070);
    in_stack_00000070 = in_stack_00000070 + 0x38;
    if (in_stack_00000070 == in_stack_00000080) {
      in_stack_00000070 = *(long *)(in_stack_00000088 + 8);
      in_stack_00000080 = (in_stack_00000080 - in_stack_00000018) + in_stack_00000070;
      in_stack_00000088 = in_stack_00000088 + 8;
      in_stack_00000018 = in_stack_00000070;
    }
  }
                    /* WARNING: Subroutine does not return */
                    /* try { // try from 0050aed5 to 0050aed9 has its CatchHandler @ 0050aeda */
  __cxa_rethrow();
}


// ==== entry=0050aef6 name=FUN_0050aef6 size=40 ====

void FUN_0050aef6(void)

{
  splitvector_blocks_free();
  FUN_0096bd50();
  FUN_0096bb02();
  FUN_0096bb02();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050af1e name=FUN_0050af1e size=33 ====

int FUN_0050af1e(undefined8 param_1,undefined8 param_2,long param_3)

{
  long *unaff_RBP;
  int unaff_R14D;
  
  if (param_3 == 1) {
    __cxa_begin_catch();
    __cxa_end_catch();
    return unaff_R14D - *(int *)(*unaff_RBP + 0x14);
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050af40 name=FUN_0050af40 size=12 ====

void FUN_0050af40(void)

{
  undefined1 *unaff_RBP;
  
  *unaff_RBP = 0;
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050af4c name=FUN_0050af4c size=16 ====

void FUN_0050af4c(void)

{
  FUN_0096bb02();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050af5c name=FUN_0050af5c size=36 ====

void FUN_0050af5c(void)

{
  undefined8 in_stack_00000010;
  undefined8 in_stack_00000018;
  
  FUN_0096bd50();
  FUN_0096bb02(in_stack_00000010);
  FUN_0096bb02(in_stack_00000018);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050af80 name=FUN_0050af80 size=10 ====

void FUN_0050af80(void)

{
  undefined8 in_stack_00000010;
  undefined8 in_stack_00000018;
  
  FUN_0096bd50();
  FUN_0096bb02(in_stack_00000010);
  FUN_0096bb02(in_stack_00000018);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050af8a name=FUN_0050af8a size=11 ====

void FUN_0050af8a(void)

{
  undefined1 *unaff_RBX;
  
  *unaff_RBX = 0;
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050af96 name=FUN_0050af96 size=13 ====

void FUN_0050af96(void)

{
  undefined1 *unaff_R12;
  
  *unaff_R12 = 0;
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050afa4 name=FUN_0050afa4 size=13 ====

void FUN_0050afa4(void)

{
  undefined1 *in_stack_00000018;
  
  *in_stack_00000018 = 0;
                    /* WARNING: Subroutine does not return */
  std::terminate();
}


// ==== entry=0050afb1 name=FUN_0050afb1 size=27 ====

void FUN_0050afb1(void)

{
  long *in_stack_00000008;
  
  if ((long *)*in_stack_00000008 != (long *)0x0) {
    (**(code **)(*(long *)*in_stack_00000008 + 8))();
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050afcc name=FUN_0050afcc size=34 ====

void FUN_0050afcc(void)

{
  void *unaff_RBX;
  void *unaff_R12;
  
  operator_delete(unaff_RBX,0x60);
  operator_delete(unaff_R12,0x20);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050afee name=FUN_0050afee size=15 ====

void FUN_0050afee(void)

{
  void *unaff_RBX;
  void *unaff_R12;
  
  operator_delete(unaff_RBX,0x30);
  operator_delete(unaff_R12,0x20);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050b000 name=FUN_0050b000 size=71 ====

void FUN_0050b000(void)

{
  void *pvVar1;
  long unaff_RBX;
  void *unaff_RBP;
  QArrayData *pQVar2;
  
  operator_delete(unaff_RBP,0x48);
  pvVar1 = *(void **)(unaff_RBX + 0x38);
  if (pvVar1 == (void *)0x0) goto LAB_0050b03f;
  pQVar2 = *(QArrayData **)((long)pvVar1 + 0x18);
  if (*(int *)pQVar2 == 0) {
LAB_0050b023:
    QArrayData::deallocate(pQVar2,1,8);
  }
  else if (*(int *)pQVar2 != -1) {
    LOCK();
    *(int *)pQVar2 = *(int *)pQVar2 + -1;
    UNLOCK();
    if (*(int *)pQVar2 == 0) {
      pQVar2 = *(QArrayData **)((long)pvVar1 + 0x18);
      goto LAB_0050b023;
    }
  }
  operator_delete(pvVar1,0x20);
LAB_0050b03f:
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050b047 name=FUN_0050b047 size=35 ====

void FUN_0050b047(void)

{
  void *pvVar1;
  long unaff_RBX;
  void *unaff_RBP;
  QArrayData *pQVar2;
  
  operator_delete(unaff_RBP,0x20);
  pvVar1 = *(void **)(unaff_RBX + 0x38);
  if (pvVar1 == (void *)0x0) goto LAB_0050b03f;
  pQVar2 = *(QArrayData **)((long)pvVar1 + 0x18);
  if (*(int *)pQVar2 == 0) {
LAB_0050b023:
    QArrayData::deallocate(pQVar2,1,8);
  }
  else if (*(int *)pQVar2 != -1) {
    LOCK();
    *(int *)pQVar2 = *(int *)pQVar2 + -1;
    UNLOCK();
    if (*(int *)pQVar2 == 0) {
      pQVar2 = *(QArrayData **)((long)pvVar1 + 0x18);
      goto LAB_0050b023;
    }
  }
  operator_delete(pvVar1,0x20);
LAB_0050b03f:
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050b06a name=FUN_0050b06a size=16 ====

void FUN_0050b06a(void)

{
  qt_array_data_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050b07a name=FUN_0050b07a size=19 ====

void FUN_0050b07a(void)

{
  qt_byte_array_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050b08e name=FUN_0050b08e size=16 ====

void FUN_0050b08e(void)

{
  qt_byte_array_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050b09e name=FUN_0050b09e size=24 ====

void FUN_0050b09e(void)

{
  qt_byte_array_unref();
  FUN_00a8dc88();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050b0b6 name=FUN_0050b0b6 size=63 ====

void FUN_0050b0b6(void)

{
  QSaveFile *unaff_RBX;
  void *unaff_R12;
  QTextEncoder *unaff_retaddr;
  QTextDecoder *in_stack_00000008;
  undefined8 in_stack_00000020;
  undefined8 in_stack_00000028;
  
  qt_byte_array_unref(in_stack_00000028);
  qt_array_data_unref(in_stack_00000020);
  QTextDecoder::~QTextDecoder(in_stack_00000008);
  QTextEncoder::~QTextEncoder(unaff_retaddr);
  QSaveFile::~QSaveFile(unaff_RBX);
  free(unaff_R12);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050b0f5 name=FUN_0050b0f5 size=12 ====

void FUN_0050b0f5(void)

{
  QSaveFile *unaff_RBX;
  void *unaff_R12;
  QTextEncoder *unaff_retaddr;
  QTextDecoder *in_stack_00000008;
  undefined8 in_stack_00000020;
  
  qt_byte_array_unref(in_stack_00000020);
  QTextDecoder::~QTextDecoder(in_stack_00000008);
  QTextEncoder::~QTextEncoder(unaff_retaddr);
  QSaveFile::~QSaveFile(unaff_RBX);
  free(unaff_R12);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050b101 name=FUN_0050b101 size=10 ====

void FUN_0050b101(void)

{
  QSaveFile *unaff_RBX;
  void *unaff_R12;
  QTextEncoder *unaff_retaddr;
  QTextDecoder *in_stack_00000008;
  
  qt_byte_array_unref();
  QTextDecoder::~QTextDecoder(in_stack_00000008);
  QTextEncoder::~QTextEncoder(unaff_retaddr);
  QSaveFile::~QSaveFile(unaff_RBX);
  free(unaff_R12);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050b10c name=FUN_0050b10c size=22 ====

void FUN_0050b10c(void)

{
                    /* WARNING: Subroutine does not return */
  __cxa_throw();
}


// ==== entry=0050b122 name=FUN_0050b122 size=16 ====

void FUN_0050b122(void)

{
  __cxa_free_exception();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050b132 name=FUN_0050b132 size=33 ====

int FUN_0050b132(undefined8 param_1,undefined8 param_2,long param_3)

{
  long *unaff_RBP;
  int unaff_R14D;
  
  if (param_3 == 1) {
    __cxa_begin_catch();
    __cxa_end_catch();
    return unaff_R14D - *(int *)(*unaff_RBP + 0x14);
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050b154 name=FUN_0050b154 size=11 ====

void FUN_0050b154(void)

{
  undefined1 *unaff_RBX;
  
  *unaff_RBX = 0;
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050b160 name=FUN_0050b160 size=32 ====

void FUN_0050b160(void)

{
  void *unaff_RBX;
  
  operator_delete(unaff_RBX,0x30);
  FUN_00980410();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050b180 name=FUN_0050b180 size=31 ====

void FUN_0050b180(void)

{
  byte unaff_R12B;
  undefined7 unaff_000000a1;
  
  if ((CONCAT71(unaff_000000a1,unaff_R12B) != 0) && ((unaff_R12B & 1) != 0)) {
    QReadWriteLock::unlock();
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050b1a0 name=FUN_0050b1a0 size=37 ====

void FUN_0050b1a0(void)

{
  ulong in_stack_00000010;
  
  if ((in_stack_00000010 != 0) && ((in_stack_00000010 & 1) != 0)) {
    QReadWriteLock::unlock();
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050b1c6 name=FUN_0050b1c6 size=37 ====

void FUN_0050b1c6(void)

{
  ulong in_stack_00000008;
  
  if ((in_stack_00000008 != 0) && ((in_stack_00000008 & 1) != 0)) {
    QReadWriteLock::unlock();
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050b1ec name=FUN_0050b1ec size=31 ====

void FUN_0050b1ec(void)

{
  byte unaff_R15B;
  undefined7 unaff_000000b9;
  
  if ((CONCAT71(unaff_000000b9,unaff_R15B) != 0) && ((unaff_R15B & 1) != 0)) {
    QReadWriteLock::unlock();
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050b20c name=FUN_0050b20c size=37 ====

void FUN_0050b20c(void)

{
  ulong in_stack_00000008;
  
  if ((in_stack_00000008 != 0) && ((in_stack_00000008 & 1) != 0)) {
    QReadWriteLock::unlock();
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050b232 name=FUN_0050b232 size=37 ====

void FUN_0050b232(void)

{
  ulong in_stack_00000010;
  
  if ((in_stack_00000010 != 0) && ((in_stack_00000010 & 1) != 0)) {
    QReadWriteLock::unlock();
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050b258 name=FUN_0050b258 size=34 ====

void FUN_0050b258(void)

{
  byte unaff_retaddr;
  undefined7 unaff_retaddr_00;
  
  if ((CONCAT71(unaff_retaddr_00,unaff_retaddr) != 0) && ((unaff_retaddr & 1) != 0)) {
    QReadWriteLock::unlock();
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050b27a name=FUN_0050b27a size=13 ====

void FUN_0050b27a(void)

{
  undefined1 *unaff_R12;
  
  *unaff_R12 = 0;
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050b287 orig=FUN_0050b287 size=22 name=CSuperBuffer32_h50b287 ====

void CSuperBuffer32_h50b287(void)

{
                    /* WARNING: Subroutine does not return */
  __cxa_throw();
}


// ==== entry=0050b29d orig=FUN_0050b29d size=22 name=CSuperBuffer32_h50b29d ====

void CSuperBuffer32_h50b29d(void)

{
                    /* WARNING: Subroutine does not return */
  __cxa_throw();
}


// ==== entry=0050b2b3 name=FUN_0050b2b3 size=30 ====

void FUN_0050b2b3(void)

{
  void *unaff_RBX;
  
  free(*(void **)((long)unaff_RBX + 8));
  operator_delete(unaff_RBX,0x30);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050b2d1 name=FUN_0050b2d1 size=16 ====

void FUN_0050b2d1(void)

{
  __cxa_free_exception();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050b2e1 name=FUN_0050b2e1 size=26 ====

void FUN_0050b2e1(void)

{
  byte unaff_R12B;
  
  if ((unaff_R12B & 1) != 0) {
    QReadWriteLock::unlock();
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050b2fb name=FUN_0050b2fb size=37 ====

void FUN_0050b2fb(void)

{
  ulong in_stack_00000020;
  
  if ((in_stack_00000020 != 0) && ((in_stack_00000020 & 1) != 0)) {
    QReadWriteLock::unlock();
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050b320 name=FUN_0050b320 size=13 ====

void FUN_0050b320(void)

{
  undefined1 *unaff_R13;
  
  *unaff_R13 = 0;
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050b32d name=FUN_0050b32d size=16 ====

void FUN_0050b32d(void)

{
  __cxa_free_exception();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050b33e name=FUN_0050b33e size=32 ====

void FUN_0050b33e(void)

{
  void *unaff_RBX;
  
  operator_delete(unaff_RBX,0x70);
  FUN_00980410();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050b35e name=FUN_0050b35e size=21 ====

void FUN_0050b35e(void)

{
  void *unaff_RBX;
  
  operator_delete(unaff_RBX,0x70);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050b380 name=FUN_0050b380 size=18 ====

void FUN_0050b380(void)

{
  undefined8 in_stack_00000020;
  
  FUN_0098fdbc(in_stack_00000020);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050b392 name=FUN_0050b392 size=56 ====

void FUN_0050b392(void)

{
  undefined8 in_stack_00000018;
  void *in_stack_00000040;
  undefined1 *in_stack_00000068;
  
  operator_delete(in_stack_00000040,0x40);
  if (in_stack_00000068 != &DAT_011c5338) {
    refcount_delete_offset10_e();
  }
  qt_array_data_unref(in_stack_00000018);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050b3ca name=FUN_0050b3ca size=154 ====

void FUN_0050b3ca(void)

{
  long unaff_R12;
  long unaff_R13;
  long unaff_R14;
  undefined8 in_stack_00000038;
  long in_stack_00000080;
  undefined8 in_stack_00000090;
  undefined **ppuStack0000000000000098;
  long in_stack_000000e0;
  
  ppuStack0000000000000098 = &PTR__stringbuf_011b4680;
  if (in_stack_000000e0 + -0x18 != unaff_R13) {
    refcount_delete_offset10_e();
  }
  ppuStack0000000000000098 = &PTR__streambuf_011b2b68;
  std::locale::~locale((locale *)(unaff_R12 + 0x40));
  *(undefined8 *)((long)&stack0x00000090 + *(long *)(unaff_R14 + -0x18)) = in_stack_00000038;
  std::ios_base::~ios_base((ios_base *)(unaff_R12 + 0x58));
  if (in_stack_00000080 + -0x18 != unaff_R13) {
    refcount_delete_offset10_e();
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050b464 name=FUN_0050b464 size=47 ====

void FUN_0050b464(void)

{
  long unaff_R13;
  void *unaff_R14;
  undefined8 in_stack_00000008;
  long in_stack_00000080;
  long in_stack_00000090;
  
  operator_delete(unaff_R14,0x40);
  if (in_stack_00000090 + -0x18 != unaff_R13) {
    refcount_delete_offset10_e();
  }
  qt_array_data_unref(in_stack_00000008);
  if (in_stack_00000080 + -0x18 != unaff_R13) {
    refcount_delete_offset10_e();
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050b493 name=FUN_0050b493 size=32 ====

void FUN_0050b493(void)

{
  ostringstream *unaff_R12;
  long unaff_R13;
  long in_stack_00000080;
  long in_stack_00000088;
  
  if (in_stack_00000088 + -0x18 != unaff_R13) {
    refcount_delete_offset10_e();
  }
  std::ostringstream::~ostringstream(unaff_R12);
  if (in_stack_00000080 + -0x18 != unaff_R13) {
    refcount_delete_offset10_e();
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050b4b4 name=FUN_0050b4b4 size=33 ====

void FUN_0050b4b4(void)

{
  undefined8 in_stack_00000018;
  void *in_stack_00000020;
  
  operator_delete(in_stack_00000020,0x40);
  qt_array_data_unref(in_stack_00000018);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050b4d6 name=FUN_0050b4d6 size=24 ====

void FUN_0050b4d6(void)

{
  qt_array_data_unref();
  qt_array_data_unref(&stack0x00000000);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050b4ee name=FUN_0050b4ee size=15 ====

void FUN_0050b4ee(void)

{
  long unaff_RBP;
  
  *(undefined1 *)(unaff_RBP + 0xd8) = 0;
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050b4fe name=FUN_0050b4fe size=33 ====

int FUN_0050b4fe(undefined8 param_1,undefined8 param_2,long param_3)

{
  long *unaff_RBP;
  int unaff_R14D;
  
  if (param_3 == 1) {
    __cxa_begin_catch();
    __cxa_end_catch();
    return unaff_R14D - *(int *)(*unaff_RBP + 0x14);
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050b520 name=FUN_0050b520 size=11 ====

void FUN_0050b520(void)

{
  undefined1 *unaff_RBX;
  
  *unaff_RBX = 0;
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050b52c name=FUN_0050b52c size=22 ====

void FUN_0050b52c(void)

{
                    /* WARNING: Subroutine does not return */
  __cxa_throw();
}


// ==== entry=0050b542 name=FUN_0050b542 size=16 ====

void FUN_0050b542(void)

{
  __cxa_free_exception();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050b552 name=FUN_0050b552 size=11 ====

void FUN_0050b552(void)

{
  undefined1 *unaff_RBX;
  
  *unaff_RBX = 0;
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050b55e name=FUN_0050b55e size=12 ====

void FUN_0050b55e(void)

{
  undefined1 *unaff_R14;
  
  *unaff_R14 = 0;
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050b56a name=FUN_0050b56a size=13 ====

void FUN_0050b56a(void)

{
  undefined1 *in_stack_00000008;
  
  *in_stack_00000008 = 0;
                    /* WARNING: Subroutine does not return */
  std::terminate();
}


// ==== entry=0050b577 name=FUN_0050b577 size=167 ====

void FUN_0050b577(void)

{
  long lVar1;
  char cVar2;
  long unaff_RBX;
  void *unaff_RBP;
  void *unaff_R12;
  long lVar3;
  void *unaff_R14;
  
  operator_delete(unaff_RBP,0x50);
  operator_delete(unaff_R12,0x20);
  operator_delete(unaff_R14,0x10);
  if (*(long *)(unaff_RBX + 0x108) != 0) {
    FUN_00990238(unaff_RBX + 0x108);
  }
  if (*(long *)(unaff_RBX + 0xf8) != 0) {
    FUN_00990120(unaff_RBX + 0xf8);
  }
  lVar1 = *(long *)(unaff_RBX + 200);
  for (lVar3 = *(long *)(unaff_RBX + 0xc0); lVar1 != lVar3; lVar3 = lVar3 + 0x20) {
    if (*(undefined1 **)(lVar3 + 8) != &DAT_011c5338) {
      refcount_delete_offset10_e();
    }
  }
  if (*(void **)(unaff_RBX + 0xc0) != (void *)0x0) {
    operator_delete(*(void **)(unaff_RBX + 0xc0));
  }
  cVar2 = qatomic_int_deref(*(long *)(unaff_RBX + 0x30) + 0x10);
  if (cVar2 == '\0') {
    QHashData::free_helper(*(_func_void_Node_ptr **)(unaff_RBX + 0x30));
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050b61e name=FUN_0050b61e size=21 ====

void FUN_0050b61e(void)

{
  long lVar1;
  char cVar2;
  long unaff_RBX;
  void *unaff_RBP;
  long lVar3;
  
  operator_delete(unaff_RBP,0xb0);
  if (*(long *)(unaff_RBX + 0x108) != 0) {
    FUN_00990238(unaff_RBX + 0x108);
  }
  if (*(long *)(unaff_RBX + 0xf8) != 0) {
    FUN_00990120(unaff_RBX + 0xf8);
  }
  lVar1 = *(long *)(unaff_RBX + 200);
  for (lVar3 = *(long *)(unaff_RBX + 0xc0); lVar1 != lVar3; lVar3 = lVar3 + 0x20) {
    if (*(undefined1 **)(lVar3 + 8) != &DAT_011c5338) {
      refcount_delete_offset10_e();
    }
  }
  if (*(void **)(unaff_RBX + 0xc0) != (void *)0x0) {
    operator_delete(*(void **)(unaff_RBX + 0xc0));
  }
  cVar2 = qatomic_int_deref(*(long *)(unaff_RBX + 0x30) + 0x10);
  if (cVar2 == '\0') {
    QHashData::free_helper(*(_func_void_Node_ptr **)(unaff_RBX + 0x30));
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050b633 name=FUN_0050b633 size=50 ====

void FUN_0050b633(void)

{
  long lVar1;
  char cVar2;
  long unaff_RBX;
  void *unaff_RBP;
  void *unaff_R12;
  long lVar3;
  void *unaff_R14;
  
  operator_delete(unaff_RBP,0x30);
  operator_delete(unaff_R12,0x20);
  operator_delete(unaff_R14,0x10);
  if (*(long *)(unaff_RBX + 0x108) != 0) {
    FUN_00990238(unaff_RBX + 0x108);
  }
  if (*(long *)(unaff_RBX + 0xf8) != 0) {
    FUN_00990120(unaff_RBX + 0xf8);
  }
  lVar1 = *(long *)(unaff_RBX + 200);
  for (lVar3 = *(long *)(unaff_RBX + 0xc0); lVar1 != lVar3; lVar3 = lVar3 + 0x20) {
    if (*(undefined1 **)(lVar3 + 8) != &DAT_011c5338) {
      refcount_delete_offset10_e();
    }
  }
  if (*(void **)(unaff_RBX + 0xc0) != (void *)0x0) {
    operator_delete(*(void **)(unaff_RBX + 0xc0));
  }
  cVar2 = qatomic_int_deref(*(long *)(unaff_RBX + 0x30) + 0x10);
  if (cVar2 == '\0') {
    QHashData::free_helper(*(_func_void_Node_ptr **)(unaff_RBX + 0x30));
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050b666 name=FUN_0050b666 size=31 ====

void FUN_0050b666(void)

{
  byte unaff_R12B;
  undefined7 unaff_000000a1;
  
  if ((CONCAT71(unaff_000000a1,unaff_R12B) != 0) && ((unaff_R12B & 1) != 0)) {
    QReadWriteLock::unlock();
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050b686 name=FUN_0050b686 size=61 ====

void FUN_0050b686(void)

{
  undefined1 *unaff_R15;
  undefined1 *in_stack_00000068;
  undefined1 *in_stack_00000090;
  
  if (in_stack_00000090 != &DAT_011c5338) {
    refcount_delete_offset10_e();
  }
  *unaff_R15 = 0;
  if (in_stack_00000068 != &DAT_011c5338) {
    refcount_delete_offset10_e();
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050b6c4 name=FUN_0050b6c4 size=158 ====

void FUN_0050b6c4(void)

{
  void *in_stack_00000010;
  undefined8 in_stack_00000050;
  undefined1 *in_stack_00000098;
  undefined1 *in_stack_000000a0;
  undefined1 *in_stack_000000a8;
  undefined1 *in_stack_000000b8;
  
  operator_delete(in_stack_00000010,0x40);
  if (in_stack_000000b8 != &DAT_011c5338) {
    refcount_delete_offset10_e();
  }
  qt_array_data_unref(in_stack_00000050);
  if (in_stack_000000a8 != &DAT_011c5338) {
    refcount_delete_offset10_e();
  }
  if (in_stack_000000a0 != &DAT_011c5338) {
    refcount_delete_offset10_e();
  }
  if (in_stack_00000098 != &DAT_011c5338) {
    refcount_delete_offset10_e();
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050b762 name=FUN_0050b762 size=61 ====

void FUN_0050b762(void)

{
  undefined8 in_stack_00000030;
  long in_stack_00000048;
  undefined1 *in_stack_00000070;
  
  if (in_stack_00000070 != &DAT_011c5338) {
    refcount_delete_offset10_e();
  }
  if (in_stack_00000048 != 0) {
    FUN_009906f4(&stack0x00000048);
  }
  qt_array_data_unref(in_stack_00000030);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050b7a0 name=FUN_0050b7a0 size=87 ====

void FUN_0050b7a0(void)

{
  long unaff_RBP;
  long in_stack_00000060;
  undefined1 *in_stack_00000068;
  undefined1 *in_stack_000000c0;
  
  if (in_stack_000000c0 != &DAT_011c5338) {
    refcount_delete_offset10_e();
  }
  if (in_stack_00000068 != &DAT_011c5338) {
    refcount_delete_offset10_e();
  }
  if (in_stack_00000060 != 0) {
    FUN_00990924(&stack0x00000060);
  }
  *(undefined1 *)(unaff_RBP + 0xd8) = 0;
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050b7f7 name=FUN_0050b7f7 size=54 ====

void FUN_0050b7f7(void)

{
  long unaff_RBP;
  long in_stack_00000060;
  undefined1 *in_stack_00000068;
  undefined1 *in_stack_000000a0;
  undefined1 *in_stack_000000c0;
  
  if (in_stack_000000c0 != &DAT_011c5338) {
    refcount_delete_offset10_e();
  }
  if (in_stack_000000a0 != &DAT_011c5338) {
    refcount_delete_offset10_e();
  }
  if (in_stack_00000068 != &DAT_011c5338) {
    refcount_delete_offset10_e();
  }
  if (in_stack_00000060 != 0) {
    FUN_00990924(&stack0x00000060);
  }
  *(undefined1 *)(unaff_RBP + 0xd8) = 0;
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050b82d name=FUN_0050b82d size=13 ====

void FUN_0050b82d(void)

{
  __cxa_begin_catch();
                    /* WARNING: Subroutine does not return */
                    /* try { // try from 0050b835 to 0050b839 has its CatchHandler @ 0050b86d */
  __cxa_rethrow();
}


// ==== entry=0050b89c name=FUN_0050b89c size=43 ====

void FUN_0050b89c(void)

{
  long unaff_R12;
  undefined1 *in_stack_00000010;
  
  if (in_stack_00000010 != &DAT_011c5338) {
    refcount_delete_offset10_e();
  }
  *(undefined1 *)(unaff_R12 + 0xd8) = 0;
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050b8c8 name=FUN_0050b8c8 size=16 ====

void FUN_0050b8c8(void)

{
  long unaff_R13;
  
  *(undefined1 *)(unaff_R13 + 0xd8) = 0;
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050b8d8 name=FUN_0050b8d8 size=31 ====

void FUN_0050b8d8(void)

{
  undefined1 *in_stack_00000058;
  
  if (in_stack_00000058 != &DAT_011c5338) {
    refcount_delete_offset10_e();
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050b8f8 name=FUN_0050b8f8 size=56 ====

void FUN_0050b8f8(void)

{
  char in_stack_00000050;
  code *in_stack_00000068;
  code *in_stack_00000070;
  
  if (in_stack_00000050 != '\0') {
    if (in_stack_00000068 == (code *)0x0) {
                    /* WARNING: Subroutine does not return */
      std::__throw_bad_function_call();
    }
    (*in_stack_00000070)(&stack0x00000058);
  }
  if (in_stack_00000068 != (code *)0x0) {
    (*in_stack_00000068)(&stack0x00000058,&stack0x00000058,3);
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050b90c name=FUN_0050b90c size=81 ====

void FUN_0050b90c(void)

{
  code *in_stack_00000020;
  code *in_stack_00000040;
  code *in_stack_00000068;
  
  if (in_stack_00000068 != (code *)0x0) {
    (*in_stack_00000068)(&stack0x00000058,&stack0x00000058,3);
  }
  if (in_stack_00000020 != (code *)0x0) {
    (*in_stack_00000020)();
  }
  if (in_stack_00000040 != (code *)0x0) {
    (*in_stack_00000040)(&stack0x00000030,&stack0x00000030,3);
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050b990 name=FUN_0050b990 size=16 ====

void FUN_0050b990(void)

{
  qt_array_data_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050b9a0 name=FUN_0050b9a0 size=70 ====

void FUN_0050b9a0(void)

{
  undefined8 in_stack_00000028;
  QArrayData *in_stack_00000050;
  
  qt_byte_array_unref();
  if (*(int *)in_stack_00000050 != 0) {
    if (*(int *)in_stack_00000050 == -1) goto LAB_0050b9c2;
    LOCK();
    *(int *)in_stack_00000050 = *(int *)in_stack_00000050 + -1;
    UNLOCK();
    if (*(int *)in_stack_00000050 != 0) goto LAB_0050b9c2;
  }
  QArrayData::deallocate(in_stack_00000050,4,8);
LAB_0050b9c2:
  qt_array_data_unref(in_stack_00000028);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050b9e6 name=FUN_0050b9e6 size=16 ====

void FUN_0050b9e6(void)

{
  qt_array_data_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050b9f6 name=FUN_0050b9f6 size=16 ====

void FUN_0050b9f6(void)

{
  qt_byte_array_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050ba06 name=FUN_0050ba06 size=16 ====

void FUN_0050ba06(void)

{
  qt_array_data_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050ba16 name=FUN_0050ba16 size=16 ====

void FUN_0050ba16(void)

{
  qt_byte_array_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050ba26 name=FUN_0050ba26 size=28 ====

void FUN_0050ba26(void)

{
  void *unaff_R12;
  
  operator_delete(unaff_R12,8);
  DAT_011c2718 = 0;
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050ba42 name=FUN_0050ba42 size=31 ====

void FUN_0050ba42(void)

{
  undefined8 unaff_retaddr;
  ConverterState *in_stack_00000008;
  undefined8 in_stack_00000010;
  
  qt_byte_array_unref(unaff_retaddr);
  QTextCodec::ConverterState::~ConverterState(in_stack_00000008);
  qt_array_data_unref(in_stack_00000010);
  DAT_011c2718 = 0;
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050ba62 name=FUN_0050ba62 size=16 ====

void FUN_0050ba62(void)

{
  qt_byte_array_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050ba72 name=FUN_0050ba72 size=16 ====

void FUN_0050ba72(void)

{
  qt_byte_array_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050ba82 name=FUN_0050ba82 size=33 ====

int FUN_0050ba82(undefined8 param_1,undefined8 param_2,long param_3)

{
  long *unaff_RBP;
  int unaff_R14D;
  
  if (param_3 == 1) {
    __cxa_begin_catch();
    __cxa_end_catch();
    return unaff_R14D - *(int *)(*unaff_RBP + 0x14);
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050baa4 name=FUN_0050baa4 size=22 ====

void FUN_0050baa4(void)

{
                    /* WARNING: Subroutine does not return */
  __cxa_throw();
}


// ==== entry=0050baba name=FUN_0050baba size=16 ====

void FUN_0050baba(void)

{
  __cxa_free_exception();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050baca name=FUN_0050baca size=11 ====

void FUN_0050baca(void)

{
  undefined1 *unaff_RBX;
  
  *unaff_RBX = 0;
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050bad6 name=FUN_0050bad6 size=13 ====

void FUN_0050bad6(void)

{
  undefined1 *unaff_R12;
  
  *unaff_R12 = 0;
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050bae4 name=FUN_0050bae4 size=22 ====

void FUN_0050bae4(void)

{
                    /* WARNING: Subroutine does not return */
  __cxa_throw();
}


// ==== entry=0050bafa name=FUN_0050bafa size=16 ====

void FUN_0050bafa(void)

{
  __cxa_free_exception();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050bb0a name=FUN_0050bb0a size=21 ====

void FUN_0050bb0a(void)

{
  void *unaff_RBX;
  
  operator_delete(unaff_RBX,0x20);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050bb20 name=FUN_0050bb20 size=31 ====

void FUN_0050bb20(void)

{
  byte unaff_BPL;
  undefined7 unaff_00000029;
  
  if ((CONCAT71(unaff_00000029,unaff_BPL) != 0) && ((unaff_BPL & 1) != 0)) {
    QReadWriteLock::unlock();
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050bb40 name=FUN_0050bb40 size=31 ====

void FUN_0050bb40(void)

{
  byte unaff_R12B;
  undefined7 unaff_000000a1;
  
  if ((CONCAT71(unaff_000000a1,unaff_R12B) != 0) && ((unaff_R12B & 1) != 0)) {
    QReadWriteLock::unlock();
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050bb60 name=FUN_0050bb60 size=31 ====

void FUN_0050bb60(void)

{
  byte unaff_R12B;
  undefined7 unaff_000000a1;
  
  if ((CONCAT71(unaff_000000a1,unaff_R12B) != 0) && ((unaff_R12B & 1) != 0)) {
    QReadWriteLock::unlock();
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050bb80 name=FUN_0050bb80 size=31 ====

void FUN_0050bb80(void)

{
  byte unaff_R13B;
  undefined7 unaff_000000a9;
  
  if ((CONCAT71(unaff_000000a9,unaff_R13B) != 0) && ((unaff_R13B & 1) != 0)) {
    QReadWriteLock::unlock();
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050bba0 name=FUN_0050bba0 size=37 ====

void FUN_0050bba0(void)

{
  ulong in_stack_00000020;
  
  if ((in_stack_00000020 != 0) && ((in_stack_00000020 & 1) != 0)) {
    QReadWriteLock::unlock();
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050bbd0 name=FUN_0050bbd0 size=13 ====

void FUN_0050bbd0(void)

{
  long unaff_R14;
  
  *(undefined1 *)(unaff_R14 + 0x48) = 0;
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050bbde name=FUN_0050bbde size=12 ====

void FUN_0050bbde(void)

{
  long unaff_RBX;
  
  *(undefined1 *)(unaff_RBX + 0x48) = 0;
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050bbea name=FUN_0050bbea size=18 ====

void FUN_0050bbea(void)

{
  undefined8 in_stack_00000020;
  
  FUN_0098fdbc(in_stack_00000020);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050bbfc name=FUN_0050bbfc size=18 ====

void FUN_0050bbfc(void)

{
  undefined8 in_stack_00000058;
  
  FUN_0098fdbc(in_stack_00000058);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050bc0e name=FUN_0050bc0e size=25 ====

void FUN_0050bc0e(void)

{
  long *unaff_RBX;
  long unaff_RBP;
  
  if (*unaff_RBX + -0x18 != unaff_RBP) {
    refcount_release();
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050bc28 name=FUN_0050bc28 size=35 ====

void FUN_0050bc28(void)

{
  long in_stack_000000d8;
  
  __cxa_begin_catch();
  operator_delete(*(void **)(in_stack_000000d8 + 8));
                    /* WARNING: Subroutine does not return */
                    /* try { // try from 0050bc46 to 0050bc4a has its CatchHandler @ 0050bd01 */
  __cxa_rethrow();
}


// ==== entry=0050bc81 name=FUN_0050bc81 size=115 ====

void FUN_0050bc81(void)

{
  long in_stack_000000a0;
  long in_stack_000000b0;
  long in_stack_000000b8;
  
  __cxa_begin_catch();
  if (in_stack_000000a0 + 0x10 == in_stack_000000b0) {
    in_stack_000000b8 = in_stack_000000b8 + 8;
  }
  operator_delete(*(void **)(in_stack_000000b8 + -8));
                    /* WARNING: Subroutine does not return */
                    /* try { // try from 0050bcef to 0050bcf3 has its CatchHandler @ 0050bc4b */
  __cxa_rethrow();
}


// ==== entry=0050bcf4 name=FUN_0050bcf4 size=13 ====

void FUN_0050bcf4(void)

{
  __cxa_begin_catch();
                    /* WARNING: Subroutine does not return */
                    /* try { // try from 0050bcfc to 0050bd00 has its CatchHandler @ 0050bd16 */
  __cxa_rethrow();
}


// ==== entry=0050bd5e name=FUN_0050bd5e size=17 ====

void FUN_0050bd5e(void)

{
  undefined8 unaff_retaddr;
  
  FUN_009a3acc(unaff_retaddr);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050bd70 name=FUN_0050bd70 size=11 ====

void FUN_0050bd70(void)

{
  undefined1 *unaff_RBX;
  
  *unaff_RBX = 0;
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050bd7c name=FUN_0050bd7c size=11 ====

void FUN_0050bd7c(void)

{
  undefined1 *unaff_RBX;
  
  *unaff_RBX = 0;
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050bd88 name=FUN_0050bd88 size=22 ====

void FUN_0050bd88(void)

{
                    /* WARNING: Subroutine does not return */
  __cxa_throw();
}


// ==== entry=0050bd9e name=FUN_0050bd9e size=16 ====

void FUN_0050bd9e(void)

{
  __cxa_free_exception();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050bdae name=FUN_0050bdae size=22 ====

void FUN_0050bdae(void)

{
                    /* WARNING: Subroutine does not return */
  __cxa_throw();
}


// ==== entry=0050bdc4 name=FUN_0050bdc4 size=16 ====

void FUN_0050bdc4(void)

{
  __cxa_free_exception();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050bdd4 name=FUN_0050bdd4 size=11 ====

void FUN_0050bdd4(void)

{
  undefined1 *unaff_RBX;
  
  *unaff_RBX = 0;
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050bde0 name=FUN_0050bde0 size=22 ====

void FUN_0050bde0(void)

{
                    /* WARNING: Subroutine does not return */
  __cxa_throw();
}


// ==== entry=0050bdf6 name=FUN_0050bdf6 size=16 ====

void FUN_0050bdf6(void)

{
  __cxa_free_exception();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050be06 name=FUN_0050be06 size=11 ====

void FUN_0050be06(void)

{
  undefined1 *unaff_RBX;
  
  *unaff_RBX = 0;
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050be12 name=FUN_0050be12 size=12 ====

void FUN_0050be12(void)

{
  undefined1 *unaff_R14;
  
  *unaff_R14 = 0;
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050be1e name=FUN_0050be1e size=11 ====

void FUN_0050be1e(void)

{
  undefined1 *unaff_RBX;
  
  *unaff_RBX = 0;
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050be2a name=FUN_0050be2a size=12 ====

void FUN_0050be2a(void)

{
  undefined1 *unaff_R14;
  
  *unaff_R14 = 0;
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050be36 name=FUN_0050be36 size=11 ====

void FUN_0050be36(void)

{
  undefined1 *unaff_RBX;
  
  *unaff_RBX = 0;
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050be42 name=FUN_0050be42 size=12 ====

void FUN_0050be42(void)

{
  long unaff_RBP;
  
  *(undefined1 *)(unaff_RBP + 0x48) = 0;
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050be4e name=FUN_0050be4e size=12 ====

void FUN_0050be4e(void)

{
  long unaff_RBP;
  
  *(undefined1 *)(unaff_RBP + 0x48) = 0;
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050be5a name=FUN_0050be5a size=12 ====

void FUN_0050be5a(void)

{
  long unaff_RBP;
  
  *(undefined1 *)(unaff_RBP + 0x48) = 0;
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050be66 name=FUN_0050be66 size=77 ====

void FUN_0050be66(void)

{
  undefined8 in_stack_00000018;
  long in_stack_00000078;
  undefined1 *in_stack_000000b0;
  
  if (in_stack_000000b0 != &DAT_011c5338) {
    refcount_release();
  }
  FUN_009a3e50(in_stack_00000018);
  if (in_stack_00000078 != 0) {
    FUN_009a3cb0(&stack0x00000078);
  }
  qt_array_data_unref(&stack0x00000070);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050beb3 name=FUN_0050beb3 size=36 ====

void FUN_0050beb3(void)

{
  undefined1 *in_stack_000000b0;
  
  qt_array_data_unref();
  if (in_stack_000000b0 != &DAT_011c5338) {
    refcount_release();
  }
  qt_array_data_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050bed7 name=FUN_0050bed7 size=77 ====

void FUN_0050bed7(void)

{
  long unaff_RBX;
  undefined8 in_stack_00000018;
  long in_stack_00000078;
  long in_stack_00000080;
  long in_stack_00000088;
  
  FUN_009a3690(in_stack_00000018);
  FUN_009a3640(&stack0x000000a0);
  if (in_stack_00000088 + -0x18 != unaff_RBX) {
    refcount_release();
  }
  if (in_stack_00000080 + -0x18 != unaff_RBX) {
    refcount_release();
  }
  if (in_stack_00000078 != 0) {
    FUN_009a3cb0(&stack0x00000078);
  }
  qt_array_data_unref(&stack0x00000070);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050bf24 name=FUN_0050bf24 size=24 ====

void FUN_0050bf24(void)

{
  long unaff_RBX;
  long in_stack_00000078;
  long in_stack_00000080;
  long in_stack_00000088;
  long in_stack_000000a0;
  
  if (in_stack_000000a0 + -0x18 != unaff_RBX) {
    refcount_release();
  }
  if (in_stack_00000088 + -0x18 != unaff_RBX) {
    refcount_release();
  }
  if (in_stack_00000080 + -0x18 != unaff_RBX) {
    refcount_release();
  }
  if (in_stack_00000078 != 0) {
    FUN_009a3cb0(&stack0x00000078);
  }
  qt_array_data_unref(&stack0x00000070);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050bf3c name=FUN_0050bf3c size=29 ====

void FUN_0050bf3c(void)

{
  void *unaff_RBP;
  
  operator_delete(unaff_RBP,0x18);
  qt_array_data_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050bf59 name=FUN_0050bf59 size=16 ====

void FUN_0050bf59(void)

{
  QVariant *unaff_RBX;
  
  QVariant::~QVariant(unaff_RBX);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050bf69 name=FUN_0050bf69 size=29 ====

void FUN_0050bf69(void)

{
  void *unaff_RBP;
  
  operator_delete(unaff_RBP,0x18);
  qt_array_data_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050bf86 name=FUN_0050bf86 size=18 ====

void FUN_0050bf86(void)

{
  undefined8 in_stack_00000028;
  
  FUN_009a3acc(in_stack_00000028);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050bf98 name=FUN_0050bf98 size=16 ====

void FUN_0050bf98(void)

{
  void *unaff_R15;
  
  operator_delete(unaff_R15);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050bfa8 name=FUN_0050bfa8 size=38 ====

void FUN_0050bfa8(void)

{
  long unaff_RBX;
  _Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *unaff_R15;
  void *in_stack_00000020;
  
  *(undefined1 *)(unaff_RBX + 0x48) = 0;
  if (in_stack_00000020 != (void *)0x0) {
    operator_delete(in_stack_00000020);
  }
  std::_Sp_counted_base<(__gnu_cxx::_Lock_policy)2>::_M_release(unaff_R15);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050bfce name=FUN_0050bfce size=56 ====

void FUN_0050bfce(void)

{
  char in_stack_00000050;
  code *in_stack_00000068;
  code *in_stack_00000070;
  
  if (in_stack_00000050 != '\0') {
    if (in_stack_00000068 == (code *)0x0) {
                    /* WARNING: Subroutine does not return */
      std::__throw_bad_function_call();
    }
    (*in_stack_00000070)(&stack0x00000058);
  }
  if (in_stack_00000068 != (code *)0x0) {
    (*in_stack_00000068)(&stack0x00000058,&stack0x00000058,3);
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050bfe2 name=FUN_0050bfe2 size=81 ====

void FUN_0050bfe2(void)

{
  code *in_stack_00000020;
  code *in_stack_00000040;
  code *in_stack_00000068;
  
  if (in_stack_00000068 != (code *)0x0) {
    (*in_stack_00000068)(&stack0x00000058,&stack0x00000058,3);
  }
  if (in_stack_00000020 != (code *)0x0) {
    (*in_stack_00000020)();
  }
  if (in_stack_00000040 != (code *)0x0) {
    (*in_stack_00000040)(&stack0x00000030,&stack0x00000030,3);
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050c058 name=FUN_0050c058 size=13 ====

void FUN_0050c058(void)

{
  undefined1 *in_stack_00000008;
  
  *in_stack_00000008 = 0;
                    /* WARNING: Subroutine does not return */
  std::terminate();
}


// ==== entry=0050c065 name=FUN_0050c065 size=164 ====

void FUN_0050c065(void)

{
  void *pvVar1;
  undefined8 *puVar2;
  char cVar3;
  long unaff_RBX;
  void *unaff_RBP;
  undefined8 *puVar4;
  void *unaff_R12;
  void *unaff_R13;
  
  operator_delete(unaff_RBP,0x50);
  operator_delete(unaff_R13,0x20);
  operator_delete(unaff_R12,0x38);
  if (*(_Sp_counted_base<(__gnu_cxx::_Lock_policy)2> **)(unaff_RBX + 0x68) !=
      (_Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *)0x0) {
    std::_Sp_counted_base<(__gnu_cxx::_Lock_policy)2>::_M_release
              (*(_Sp_counted_base<(__gnu_cxx::_Lock_policy)2> **)(unaff_RBX + 0x68));
  }
  if (*(_Sp_counted_base<(__gnu_cxx::_Lock_policy)2> **)(unaff_RBX + 0x58) !=
      (_Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *)0x0) {
    std::_Sp_counted_base<(__gnu_cxx::_Lock_policy)2>::_M_release
              (*(_Sp_counted_base<(__gnu_cxx::_Lock_policy)2> **)(unaff_RBX + 0x58));
  }
  cVar3 = qatomic_int_deref(*(long *)(unaff_RBX + 0x38) + 0x10);
  if (cVar3 == '\0') {
    QHashData::free_helper(*(_func_void_Node_ptr **)(unaff_RBX + 0x38));
  }
  pvVar1 = *(void **)(unaff_RBX + 0x30);
  if (pvVar1 != (void *)0x0) {
    if (*(long *)((long)pvVar1 + 0x28) != 0) {
      puVar4 = *(undefined8 **)(*(long *)((long)pvVar1 + 0x28) + *(long *)((long)pvVar1 + 8) * 8);
      while (puVar4 != (undefined8 *)0x0) {
        puVar2 = (undefined8 *)*puVar4;
        operator_delete(puVar4);
        puVar4 = puVar2;
      }
      operator_delete(*(void **)((long)pvVar1 + 0x28));
    }
    operator_delete(pvVar1,0x30);
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050c109 name=FUN_0050c109 size=21 ====

void FUN_0050c109(void)

{
  void *pvVar1;
  undefined8 *puVar2;
  char cVar3;
  long unaff_RBX;
  void *unaff_RBP;
  undefined8 *puVar4;
  void *unaff_R12;
  
  operator_delete(unaff_RBP,0x40);
  operator_delete(unaff_R12,0x38);
  if (*(_Sp_counted_base<(__gnu_cxx::_Lock_policy)2> **)(unaff_RBX + 0x68) !=
      (_Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *)0x0) {
    std::_Sp_counted_base<(__gnu_cxx::_Lock_policy)2>::_M_release
              (*(_Sp_counted_base<(__gnu_cxx::_Lock_policy)2> **)(unaff_RBX + 0x68));
  }
  if (*(_Sp_counted_base<(__gnu_cxx::_Lock_policy)2> **)(unaff_RBX + 0x58) !=
      (_Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *)0x0) {
    std::_Sp_counted_base<(__gnu_cxx::_Lock_policy)2>::_M_release
              (*(_Sp_counted_base<(__gnu_cxx::_Lock_policy)2> **)(unaff_RBX + 0x58));
  }
  cVar3 = qatomic_int_deref(*(long *)(unaff_RBX + 0x38) + 0x10);
  if (cVar3 == '\0') {
    QHashData::free_helper(*(_func_void_Node_ptr **)(unaff_RBX + 0x38));
  }
  pvVar1 = *(void **)(unaff_RBX + 0x30);
  if (pvVar1 != (void *)0x0) {
    if (*(long *)((long)pvVar1 + 0x28) != 0) {
      puVar4 = *(undefined8 **)(*(long *)((long)pvVar1 + 0x28) + *(long *)((long)pvVar1 + 8) * 8);
      while (puVar4 != (undefined8 *)0x0) {
        puVar2 = (undefined8 *)*puVar4;
        operator_delete(puVar4);
        puVar4 = puVar2;
      }
      operator_delete(*(void **)((long)pvVar1 + 0x28));
    }
    operator_delete(pvVar1,0x30);
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050c11e name=FUN_0050c11e size=31 ====

void FUN_0050c11e(void)

{
  void *pvVar1;
  undefined8 *puVar2;
  char cVar3;
  long unaff_RBX;
  void *unaff_RBP;
  undefined8 *puVar4;
  void *unaff_R12;
  void *unaff_R13;
  
  operator_delete(unaff_RBP,0x30);
  operator_delete(unaff_R13,0x20);
  operator_delete(unaff_R12,0x38);
  if (*(_Sp_counted_base<(__gnu_cxx::_Lock_policy)2> **)(unaff_RBX + 0x68) !=
      (_Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *)0x0) {
    std::_Sp_counted_base<(__gnu_cxx::_Lock_policy)2>::_M_release
              (*(_Sp_counted_base<(__gnu_cxx::_Lock_policy)2> **)(unaff_RBX + 0x68));
  }
  if (*(_Sp_counted_base<(__gnu_cxx::_Lock_policy)2> **)(unaff_RBX + 0x58) !=
      (_Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *)0x0) {
    std::_Sp_counted_base<(__gnu_cxx::_Lock_policy)2>::_M_release
              (*(_Sp_counted_base<(__gnu_cxx::_Lock_policy)2> **)(unaff_RBX + 0x58));
  }
  cVar3 = qatomic_int_deref(*(long *)(unaff_RBX + 0x38) + 0x10);
  if (cVar3 == '\0') {
    QHashData::free_helper(*(_func_void_Node_ptr **)(unaff_RBX + 0x38));
  }
  pvVar1 = *(void **)(unaff_RBX + 0x30);
  if (pvVar1 != (void *)0x0) {
    if (*(long *)((long)pvVar1 + 0x28) != 0) {
      puVar4 = *(undefined8 **)(*(long *)((long)pvVar1 + 0x28) + *(long *)((long)pvVar1 + 8) * 8);
      while (puVar4 != (undefined8 *)0x0) {
        puVar2 = (undefined8 *)*puVar4;
        operator_delete(puVar4);
        puVar4 = puVar2;
      }
      operator_delete(*(void **)((long)pvVar1 + 0x28));
    }
    operator_delete(pvVar1,0x30);
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050c13e name=FUN_0050c13e size=12 ====

void FUN_0050c13e(void)

{
  undefined1 *unaff_R14;
  
  *unaff_R14 = 0;
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050c150 name=FUN_0050c150 size=152 ====

void FUN_0050c150(void)

{
  long unaff_R13;
  long lStack0000000000000008;
  undefined8 in_stack_00000010;
  void *in_stack_00000038;
  undefined8 in_stack_00000050;
  long in_stack_00000080;
  
  lStack0000000000000008 = *(long *)((long)in_stack_00000038 + 0x28);
  if (lStack0000000000000008 + -0x18 != unaff_R13) {
    refcount_release();
  }
  lStack0000000000000008 = *(long *)((long)in_stack_00000038 + 0x20);
  if (lStack0000000000000008 + -0x18 != unaff_R13) {
    refcount_release();
  }
  QVariant::~QVariant((QVariant *)((long)in_stack_00000038 + 0x10));
  qt_array_data_unref((long)in_stack_00000038 + 8);
  qt_array_data_unref(in_stack_00000038);
  operator_delete(in_stack_00000038,0x40);
  qt_array_data_unref(in_stack_00000050);
  completer_priv_dtor(in_stack_00000010);
  if (in_stack_00000080 + -0x18 != unaff_R13) {
    refcount_release();
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050c1e8 name=FUN_0050c1e8 size=18 ====

void FUN_0050c1e8(void)

{
  __cxa_begin_catch();
                    /* WARNING: Subroutine does not return */
                    /* try { // try from 0050c1f5 to 0050c1f9 has its CatchHandler @ 0050c223 */
  __cxa_rethrow();
}


// ==== entry=0050c252 name=FUN_0050c252 size=16 ====

void FUN_0050c252(void)

{
  FUN_0067cf84();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050c262 name=FUN_0050c262 size=62 ====

void FUN_0050c262(void)

{
  long unaff_RBX;
  long unaff_R13;
  undefined8 in_stack_00000020;
  undefined8 in_stack_00000048;
  long in_stack_00000068;
  long in_stack_00000078;
  
  if (*(long *)(unaff_RBX + 0x20) + -0x18 != unaff_R13) {
    refcount_release();
  }
  FUN_009a9620(in_stack_00000048);
  if (in_stack_00000078 + -0x18 != unaff_R13) {
    refcount_release();
  }
  FUN_009a3e50(in_stack_00000020);
  if (in_stack_00000068 + -0x18 != unaff_R13) {
    refcount_release();
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050c2a0 name=FUN_0050c2a0 size=108 ====

void FUN_0050c2a0(void)

{
  long unaff_R13;
  long in_stack_00000068;
  long in_stack_00000078;
  long in_stack_00000080;
  long in_stack_00000090;
  long in_stack_000000f0;
  
  if (in_stack_00000090 + -0x18 != unaff_R13) {
    refcount_release();
  }
  if (in_stack_000000f0 + -0x18 != unaff_R13) {
    refcount_release();
  }
  if (in_stack_00000080 != 0) {
    FUN_0081e506();
  }
  if (in_stack_00000078 + -0x18 != unaff_R13) {
    refcount_release();
  }
  if (in_stack_00000068 + -0x18 != unaff_R13) {
    refcount_release();
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050c30c name=FUN_0050c30c size=25 ====

void FUN_0050c30c(void)

{
  long unaff_R13;
  undefined8 in_stack_00000010;
  undefined8 in_stack_00000020;
  undefined8 in_stack_00000038;
  undefined8 in_stack_00000048;
  long in_stack_00000068;
  long in_stack_00000078;
  
  FUN_009a3690(in_stack_00000038);
  FUN_009a3640(in_stack_00000010);
  FUN_009a9620(in_stack_00000048);
  if (in_stack_00000078 + -0x18 != unaff_R13) {
    refcount_release();
  }
  FUN_009a3e50(in_stack_00000020);
  if (in_stack_00000068 + -0x18 != unaff_R13) {
    refcount_release();
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050c325 name=FUN_0050c325 size=24 ====

void FUN_0050c325(void)

{
  long unaff_R13;
  long in_stack_00000068;
  long in_stack_00000078;
  long in_stack_00000080;
  long in_stack_000000f0;
  
  if (in_stack_000000f0 + -0x18 != unaff_R13) {
    refcount_release();
  }
  if (in_stack_00000080 != 0) {
    FUN_0081e506();
  }
  if (in_stack_00000078 + -0x18 != unaff_R13) {
    refcount_release();
  }
  if (in_stack_00000068 + -0x18 != unaff_R13) {
    refcount_release();
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050c33d name=FUN_0050c33d size=32 ====

void FUN_0050c33d(void)

{
  long unaff_R13;
  undefined8 in_stack_00000020;
  undefined8 in_stack_00000028;
  long in_stack_00000068;
  long in_stack_000000a0;
  
  if (in_stack_000000a0 != 0) {
    FUN_009a3cb0(in_stack_00000028);
  }
  FUN_009a3e50(in_stack_00000020);
  if (in_stack_00000068 + -0x18 != unaff_R13) {
    refcount_release();
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050c35d name=FUN_0050c35d size=65 ====

void FUN_0050c35d(void)

{
  long unaff_R13;
  undefined8 in_stack_00000028;
  long in_stack_00000068;
  long in_stack_00000078;
  long in_stack_00000080;
  QArrayData *in_stack_000000f0;
  
  if (*(int *)in_stack_000000f0 != 0) {
    if (*(int *)in_stack_000000f0 == -1) goto LAB_0050c37a;
    LOCK();
    *(int *)in_stack_000000f0 = *(int *)in_stack_000000f0 + -1;
    UNLOCK();
    if (*(int *)in_stack_000000f0 != 0) goto LAB_0050c37a;
  }
  QArrayData::deallocate(in_stack_000000f0,1,8);
LAB_0050c37a:
  qt_array_data_unref(in_stack_00000028);
  if (in_stack_00000080 != 0) {
    FUN_0081e506();
  }
  if (in_stack_00000078 + -0x18 != unaff_R13) {
    refcount_release();
  }
  if (in_stack_00000068 + -0x18 != unaff_R13) {
    refcount_release();
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050c39e name=FUN_0050c39e size=22 ====

void FUN_0050c39e(void)

{
  long unaff_R14;
  
  if (unaff_R14 != 0) {
    qslotobject_release_destroy(unaff_R14 + 8);
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050c3b4 name=FUN_0050c3b4 size=22 ====

void FUN_0050c3b4(void)

{
  long unaff_R14;
  
  if (unaff_R14 != 0) {
    qslotobject_release_destroy(unaff_R14 + 8);
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050c3ca name=FUN_0050c3ca size=21 ====

void FUN_0050c3ca(void)

{
  FUN_0081f982(&stack0x00000090);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050c3df name=FUN_0050c3df size=22 ====

void FUN_0050c3df(void)

{
  long unaff_R14;
  
  if (unaff_R14 != 0) {
    qslotobject_release_destroy(unaff_R14 + 8);
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050c3f5 name=FUN_0050c3f5 size=22 ====

void FUN_0050c3f5(void)

{
  long unaff_R14;
  
  if (unaff_R14 != 0) {
    qslotobject_release_destroy(unaff_R14 + 8);
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050c40c name=FUN_0050c40c size=12 ====

void FUN_0050c40c(void)

{
  undefined1 *unaff_RBP;
  
  *unaff_RBP = 0;
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050c418 name=FUN_0050c418 size=22 ====

void FUN_0050c418(void)

{
                    /* WARNING: Subroutine does not return */
  __cxa_throw();
}


// ==== entry=0050c42e name=FUN_0050c42e size=16 ====

void FUN_0050c42e(void)

{
  __cxa_free_exception();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050c43e name=FUN_0050c43e size=12 ====

void FUN_0050c43e(void)

{
  undefined1 *unaff_RBP;
  
  *unaff_RBP = 0;
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050c44a name=FUN_0050c44a size=22 ====

void FUN_0050c44a(void)

{
                    /* WARNING: Subroutine does not return */
  __cxa_throw();
}


// ==== entry=0050c460 name=FUN_0050c460 size=16 ====

void FUN_0050c460(void)

{
  __cxa_free_exception();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050c470 name=FUN_0050c470 size=11 ====

void FUN_0050c470(void)

{
  undefined1 *unaff_RBX;
  
  *unaff_RBX = 0;
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050c47c name=FUN_0050c47c size=13 ====

void FUN_0050c47c(void)

{
  undefined1 *in_stack_00000008;
  
  *in_stack_00000008 = 0;
                    /* WARNING: Subroutine does not return */
  std::terminate();
}


// ==== entry=0050c489 name=FUN_0050c489 size=50 ====

void FUN_0050c489(void)

{
  void *unaff_RBX;
  void *unaff_RBP;
  void *unaff_R14;
  
  operator_delete(unaff_RBX,0x50);
  operator_delete(unaff_RBP,0x20);
  operator_delete(unaff_R14,0x20);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050c4bb name=FUN_0050c4bb size=15 ====

void FUN_0050c4bb(void)

{
  void *unaff_RBX;
  void *unaff_RBP;
  void *unaff_R14;
  
  operator_delete(unaff_RBX,0x30);
  operator_delete(unaff_RBP,0x20);
  operator_delete(unaff_R14,0x20);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050c4ca name=FUN_0050c4ca size=11 ====

void FUN_0050c4ca(void)

{
  undefined1 *unaff_RBX;
  
  *unaff_RBX = 0;
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050c4d6 name=FUN_0050c4d6 size=40 ====

void FUN_0050c4d6(void)

{
  ulong in_stack_00000038;
  
  if ((in_stack_00000038 != 0) && ((in_stack_00000038 & 1) != 0)) {
    QReadWriteLock::unlock();
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050c4fe name=FUN_0050c4fe size=21 ====

void FUN_0050c4fe(void)

{
  void *unaff_RBP;
  
  operator_delete(unaff_RBP,0x20);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050c520 name=FUN_0050c520 size=27 ====

void FUN_0050c520(void)

{
  qt_byte_array_unref();
  qt_byte_array_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050c53c name=FUN_0050c53c size=94 ====

void FUN_0050c53c(void)

{
  undefined8 in_RAX;
  long unaff_RBX;
  undefined8 uStack0000000000000008;
  
  uStack0000000000000008 = in_RAX;
  FUN_009b66a0();
  qt_byte_array_unref();
  qt_byte_array_unref();
  qt_byte_array_unref();
  qt_byte_array_unref();
  qt_byte_array_unref(unaff_RBX + 0x18);
  qt_byte_array_unref(unaff_RBX + 0x10);
  qt_byte_array_unref(unaff_RBX + 8);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception(uStack0000000000000008);
}


// ==== entry=0050c59a name=FUN_0050c59a size=16 ====

void FUN_0050c59a(void)

{
  qt_byte_array_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050c5aa name=FUN_0050c5aa size=16 ====

void FUN_0050c5aa(void)

{
  qt_byte_array_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050c5ba name=FUN_0050c5ba size=16 ====

void FUN_0050c5ba(void)

{
  qt_byte_array_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050c5ca name=FUN_0050c5ca size=16 ====

void FUN_0050c5ca(void)

{
  qt_byte_array_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050c5da name=FUN_0050c5da size=16 ====

void FUN_0050c5da(void)

{
  qt_byte_array_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050c5ea name=FUN_0050c5ea size=16 ====

void FUN_0050c5ea(void)

{
  qt_byte_array_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050c5fa name=FUN_0050c5fa size=16 ====

void FUN_0050c5fa(void)

{
  qt_byte_array_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050c60a name=FUN_0050c60a size=161 ====

void FUN_0050c60a(void)

{
  long unaff_RBX;
  
  if (*(void **)(unaff_RBX + 0x80) != (void *)0x0) {
    operator_delete(*(void **)(unaff_RBX + 0x80),0x20);
  }
  if (*(void **)(unaff_RBX + 0x78) != (void *)0x0) {
    operator_delete(*(void **)(unaff_RBX + 0x78),0x20);
  }
  if (*(void **)(unaff_RBX + 0x70) != (void *)0x0) {
    operator_delete(*(void **)(unaff_RBX + 0x70),0x20);
  }
  if (*(void **)(unaff_RBX + 0x68) != (void *)0x0) {
    operator_delete(*(void **)(unaff_RBX + 0x68),0x20);
  }
  if (*(void **)(unaff_RBX + 0x60) != (void *)0x0) {
    operator_delete(*(void **)(unaff_RBX + 0x60),0x20);
  }
  if (*(void **)(unaff_RBX + 0x58) != (void *)0x0) {
    operator_delete(*(void **)(unaff_RBX + 0x58),0x20);
  }
  if (*(void **)(unaff_RBX + 0x50) != (void *)0x0) {
    operator_delete(*(void **)(unaff_RBX + 0x50),0x20);
  }
  qt_byte_array_unref();
  qt_byte_array_unref(unaff_RBX + 0x20);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050c6ac name=FUN_0050c6ac size=17 ====

void FUN_0050c6ac(void)

{
  long unaff_RBX;
  
  qt_byte_array_unref(unaff_RBX + 8);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050c6be name=FUN_0050c6be size=186 ====

void FUN_0050c6be(void)

{
  long lVar1;
  void *pvVar2;
  long unaff_RBX;
  long lVar3;
  undefined8 *puVar4;
  QArrayData *pQVar5;
  long *plVar6;
  long lVar7;
  long lVar8;
  undefined8 in_stack_00000008;
  
  lVar1 = *(long *)(unaff_RBX + 0x48);
  lVar3 = *(long *)(unaff_RBX + 0x28);
  lVar8 = *(long *)(unaff_RBX + 0x38);
  plVar6 = *(long **)(unaff_RBX + 0x40);
  lVar7 = *(long *)(unaff_RBX + 0x30);
  do {
    if (lVar1 == lVar3) {
      if (*(long *)(unaff_RBX + 0x18) != 0) {
        lVar1 = *(long *)(unaff_RBX + 0x60);
        for (puVar4 = *(undefined8 **)(unaff_RBX + 0x40); puVar4 < (undefined8 *)(lVar1 + 8U);
            puVar4 = puVar4 + 1) {
          operator_delete((void *)*puVar4);
        }
        operator_delete(*(void **)(unaff_RBX + 0x18));
      }
      pvVar2 = *(void **)(unaff_RBX + 0x10);
      if (pvVar2 != (void *)0x0) {
        qstring_bundle_release(pvVar2);
        operator_delete(pvVar2,0x118);
      }
                    /* WARNING: Subroutine does not return */
      cxa_throw_exception(in_stack_00000008);
    }
    pQVar5 = *(QArrayData **)(lVar3 + 8);
    if (*(int *)pQVar5 == 0) {
LAB_0050c6e1:
      QArrayData::deallocate(pQVar5,1,8);
    }
    else if (*(int *)pQVar5 != -1) {
      LOCK();
      *(int *)pQVar5 = *(int *)pQVar5 + -1;
      UNLOCK();
      if (*(int *)pQVar5 == 0) {
        pQVar5 = *(QArrayData **)(lVar3 + 8);
        goto LAB_0050c6e1;
      }
    }
    lVar3 = lVar3 + 0x10;
    if (lVar8 == lVar3) {
      plVar6 = plVar6 + 1;
      lVar3 = *plVar6;
      lVar8 = (lVar8 - lVar7) + lVar3;
      lVar7 = lVar3;
    }
  } while( true );
}


// ==== entry=0050c778 name=FUN_0050c778 size=21 ====

void FUN_0050c778(void)

{
  void *unaff_RBP;
  
  operator_delete(unaff_RBP,0x38);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050c78d name=FUN_0050c78d size=16 ====

void FUN_0050c78d(void)

{
  FUN_00a8dc88();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050c79d name=FUN_0050c79d size=16 ====

void FUN_0050c79d(void)

{
  FUN_00a8dc88();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050c7ae name=FUN_0050c7ae size=21 ====

void FUN_0050c7ae(void)

{
  void *unaff_R13;
  
  operator_delete(unaff_R13,0x118);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050c7c4 name=FUN_0050c7c4 size=17 ====

void FUN_0050c7c4(void)

{
  long unaff_RBP;
  
  qt_byte_array_unref(unaff_RBP + 8);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050c7d6 name=FUN_0050c7d6 size=16 ====

void FUN_0050c7d6(void)

{
  qstring_bundle_release();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050c7e6 name=FUN_0050c7e6 size=16 ====

void FUN_0050c7e6(void)

{
  qt_byte_array_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050c7f6 name=FUN_0050c7f6 size=21 ====

void FUN_0050c7f6(void)

{
  void *unaff_R12;
  
  operator_delete(unaff_R12,0x118);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050c810 name=FUN_0050c810 size=20 ====

void FUN_0050c810(void)

{
  __cxa_guard_abort(&DAT_011c2748);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050c824 name=FUN_0050c824 size=33 ====

void FUN_0050c824(void)

{
  char unaff_BPL;
  undefined1 *in_stack_00000020;
  
  if ((unaff_BPL != '\0') && (in_stack_00000020 != &DAT_011c5338)) {
    refcount_release();
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050c831 name=FUN_0050c831 size=31 ====

void FUN_0050c831(void)

{
  undefined1 *in_stack_00000028;
  
  if (in_stack_00000028 != &DAT_011c5338) {
    refcount_release();
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050c850 name=FUN_0050c850 size=25 ====

void FUN_0050c850(void)

{
  undefined1 *in_stack_00000028;
  
  if (in_stack_00000028 != &DAT_011c5338) {
    refcount_release();
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050c87e name=FUN_0050c87e size=21 ====

void FUN_0050c87e(void)

{
  void *unaff_R13;
  
  operator_delete(unaff_R13,0x20);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050c893 name=FUN_0050c893 size=31 ====

void FUN_0050c893(void)

{
  undefined1 *in_stack_00000020;
  
  if (in_stack_00000020 != &DAT_011c5338) {
    refcount_release();
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050c8b2 name=FUN_0050c8b2 size=32 ====

void FUN_0050c8b2(void)

{
  QVariant *unaff_RBX;
  QVariant *unaff_R12;
  
  QVariant::~QVariant(unaff_R12);
  qt_byte_array_unref();
  QVariant::~QVariant(unaff_RBX);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050c8d2 name=FUN_0050c8d2 size=55 ====

void FUN_0050c8d2(void)

{
  QVariant *unaff_RBX;
  QVariant *unaff_R12;
  
  QVariant::~QVariant(unaff_R12);
  qt_byte_array_unref();
  QVariant::~QVariant(unaff_RBX);
  qt_shared_data_unref(&stack0x00000040);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050c909 name=FUN_0050c909 size=31 ====

void FUN_0050c909(void)

{
  undefined1 *in_stack_00000070;
  
  if (in_stack_00000070 != &DAT_011c5338) {
    refcount_release();
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050c928 name=FUN_0050c928 size=21 ====

void FUN_0050c928(void)

{
  void *unaff_R15;
  
  operator_delete(unaff_R15,0x20);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050c93d name=FUN_0050c93d size=32 ====

void FUN_0050c93d(void)

{
  QVariant *unaff_RBX;
  QVariant *unaff_R12;
  
  QVariant::~QVariant(unaff_R12);
  qt_byte_array_unref();
  QVariant::~QVariant(unaff_RBX);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050c95d name=FUN_0050c95d size=34 ====

void FUN_0050c95d(void)

{
  undefined1 *in_stack_00000080;
  
  if (in_stack_00000080 != &DAT_011c5338) {
    refcount_release();
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050c97f name=FUN_0050c97f size=13 ====

void FUN_0050c97f(void)

{
  undefined8 in_stack_00000018;
  
  qt_shared_data_unref();
  qt_shared_data_unref(in_stack_00000018);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050c98c name=FUN_0050c98c size=15 ====

void FUN_0050c98c(void)

{
  undefined8 in_stack_00000010;
  undefined8 in_stack_00000018;
  
  qt_array_data_unref(in_stack_00000010);
  qt_shared_data_unref(in_stack_00000018);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050c99b name=FUN_0050c99b size=44 ====

void FUN_0050c99b(void)

{
  QVariant *unaff_RBX;
  QVariant *unaff_R13;
  undefined8 in_stack_00000018;
  undefined8 in_stack_00000020;
  undefined8 in_stack_00000028;
  
  qt_array_data_unref(in_stack_00000028);
  QVariant::~QVariant(unaff_RBX);
  qt_byte_array_unref(in_stack_00000020);
  QVariant::~QVariant(unaff_R13);
  qt_shared_data_unref(in_stack_00000018);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050c9c8 name=FUN_0050c9c8 size=73 ====

void FUN_0050c9c8(void)

{
  locale *unaff_R15;
  void *in_stack_00000028;
  undefined8 in_stack_00000038;
  undefined1 *in_stack_00000180;
  
  std::locale::~locale(unaff_R15);
  if (in_stack_00000180 != &DAT_011c5338) {
    refcount_release();
  }
  string_vector_destroy(in_stack_00000038);
  qfont_release(in_stack_00000028);
  operator_delete(in_stack_00000028,0x20);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050ca11 name=FUN_0050ca11 size=10 ====

void FUN_0050ca11(void)

{
  locale *unaff_R15;
  void *in_stack_00000028;
  undefined8 in_stack_00000038;
  undefined1 *in_stack_00000180;
  
  std::locale::~locale(unaff_R15);
  if (in_stack_00000180 != &DAT_011c5338) {
    refcount_release();
  }
  string_vector_destroy(in_stack_00000038);
  qfont_release(in_stack_00000028);
  operator_delete(in_stack_00000028,0x20);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050ca1b name=FUN_0050ca1b size=63 ====

void FUN_0050ca1b(void)

{
  QRegularExpression *unaff_R14;
  void *in_stack_00000028;
  undefined8 in_stack_00000038;
  undefined1 *in_stack_00000140;
  
  qt_shared_data_unref();
  QRegularExpression::~QRegularExpression(unaff_R14);
  qt_array_data_unref();
  qt_array_data_unref();
  if (in_stack_00000140 != &DAT_011c5338) {
    refcount_release();
  }
  string_vector_destroy(in_stack_00000038);
  qfont_release(in_stack_00000028);
  operator_delete(in_stack_00000028,0x20);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050ca5a name=FUN_0050ca5a size=16 ====

void FUN_0050ca5a(void)

{
  locale *unaff_R15;
  void *in_stack_00000028;
  undefined8 in_stack_00000038;
  undefined1 *in_stack_00000180;
  
  std::locale::~locale(unaff_R15);
  if (in_stack_00000180 != &DAT_011c5338) {
    refcount_release();
  }
  string_vector_destroy(in_stack_00000038);
  qfont_release(in_stack_00000028);
  operator_delete(in_stack_00000028,0x20);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050ca6a name=FUN_0050ca6a size=13 ====

void FUN_0050ca6a(void)

{
  locale *unaff_R15;
  void *in_stack_00000028;
  undefined8 in_stack_00000038;
  undefined1 *in_stack_00000180;
  
  std::locale::~locale(unaff_R15);
  if (in_stack_00000180 != &DAT_011c5338) {
    refcount_release();
  }
  string_vector_destroy(in_stack_00000038);
  qfont_release(in_stack_00000028);
  operator_delete(in_stack_00000028,0x20);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050ca77 name=FUN_0050ca77 size=21 ====

void FUN_0050ca77(void)

{
  locale *unaff_RBP;
  locale *unaff_R15;
  void *in_stack_00000028;
  undefined8 in_stack_00000038;
  
  std::locale::~locale(unaff_R15);
  std::locale::~locale(unaff_RBP);
  string_vector_destroy(in_stack_00000038);
  qfont_release(in_stack_00000028);
  operator_delete(in_stack_00000028,0x20);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050ca8c name=FUN_0050ca8c size=42 ====

void FUN_0050ca8c(void)

{
  locale *unaff_R15;
  void *in_stack_00000028;
  undefined8 in_stack_00000038;
  undefined1 *in_stack_00000118;
  
  std::locale::~locale(unaff_R15);
  string_vector_destroy();
  if (in_stack_00000118 != &DAT_011c5338) {
    refcount_release();
  }
  string_vector_destroy(in_stack_00000038);
  qfont_release(in_stack_00000028);
  operator_delete(in_stack_00000028,0x20);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050cab6 name=FUN_0050cab6 size=18 ====

void FUN_0050cab6(void)

{
  locale *unaff_RBP;
  locale *unaff_R15;
  void *in_stack_00000028;
  undefined8 in_stack_00000038;
  undefined1 *in_stack_00000118;
  
  std::locale::~locale(unaff_RBP);
  std::locale::~locale(unaff_R15);
  string_vector_destroy();
  if (in_stack_00000118 != &DAT_011c5338) {
    refcount_release();
  }
  string_vector_destroy(in_stack_00000038);
  qfont_release(in_stack_00000028);
  operator_delete(in_stack_00000028,0x20);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050cac8 name=FUN_0050cac8 size=60 ====

void FUN_0050cac8(void)

{
  void *in_stack_00000028;
  undefined8 in_stack_00000038;
  undefined1 *in_stack_00000118;
  void *in_stack_00000160;
  ulong in_stack_00000170;
  void *in_stack_00000180;
  
  if (in_stack_00000180 != (void *)0x0) {
    operator_delete__(in_stack_00000180);
  }
  if ((0x10 < in_stack_00000170) && (in_stack_00000160 != (void *)0x0)) {
    operator_delete__(in_stack_00000160);
  }
  string_vector_destroy(&stack0x00000140);
  if (in_stack_00000118 != &DAT_011c5338) {
    refcount_release();
  }
  string_vector_destroy(in_stack_00000038);
  qfont_release(in_stack_00000028);
  operator_delete(in_stack_00000028,0x20);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050cb5d name=FUN_0050cb5d size=21 ====

void FUN_0050cb5d(void)

{
  locale *unaff_R12;
  locale *unaff_R15;
  void *in_stack_00000028;
  undefined8 in_stack_00000038;
  undefined1 *in_stack_00000180;
  
  std::locale::~locale(unaff_R12);
  std::locale::~locale(unaff_R15);
  if (in_stack_00000180 != &DAT_011c5338) {
    refcount_release();
  }
  string_vector_destroy(in_stack_00000038);
  qfont_release(in_stack_00000028);
  operator_delete(in_stack_00000028,0x20);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050cb72 name=FUN_0050cb72 size=30 ====

void FUN_0050cb72(void)

{
  void *in_stack_00000028;
  undefined8 in_stack_00000038;
  undefined1 *in_stack_000001d0;
  
  if (in_stack_000001d0 != &DAT_011c5338) {
    refcount_release();
  }
  string_vector_destroy(in_stack_00000038);
  qfont_release(in_stack_00000028);
  operator_delete(in_stack_00000028,0x20);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050cb90 name=FUN_0050cb90 size=44 ====

void FUN_0050cb90(void)

{
  ulong unaff_RBX;
  void *in_stack_00000028;
  undefined8 in_stack_00000038;
  undefined1 *in_stack_00000118;
  void *in_stack_00000160;
  ulong in_stack_00000170;
  void *in_stack_00000180;
  void *in_stack_000001d0;
  ulong in_stack_000001e0;
  
  if ((0x10 < in_stack_000001e0) && (in_stack_000001d0 != (void *)0x0)) {
    operator_delete__(in_stack_000001d0);
  }
  if ((0x10 < unaff_RBX) && (in_stack_00000180 != (void *)0x0)) {
    operator_delete__(in_stack_00000180);
  }
  if ((0x10 < in_stack_00000170) && (in_stack_00000160 != (void *)0x0)) {
    operator_delete__(in_stack_00000160);
  }
  string_vector_destroy();
  if (in_stack_00000118 != &DAT_011c5338) {
    refcount_release();
  }
  string_vector_destroy(in_stack_00000038);
  qfont_release(in_stack_00000028);
  operator_delete(in_stack_00000028,0x20);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050cbbc name=FUN_0050cbbc size=21 ====

void FUN_0050cbbc(void)

{
  void *in_stack_00000028;
  undefined8 in_stack_00000038;
  
  json_value_destruct();
  json_value_destruct();
  string_vector_destroy(in_stack_00000038);
  qfont_release(in_stack_00000028);
  operator_delete(in_stack_00000028,0x20);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050cbd1 name=FUN_0050cbd1 size=23 ====

void FUN_0050cbd1(void)

{
  locale *unaff_R15;
  locale *in_stack_00000010;
  void *in_stack_00000028;
  undefined8 in_stack_00000038;
  
  std::locale::~locale(in_stack_00000010);
  std::locale::~locale(unaff_R15);
  string_vector_destroy(in_stack_00000038);
  qfont_release(in_stack_00000028);
  operator_delete(in_stack_00000028,0x20);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050cbe8 name=FUN_0050cbe8 size=21 ====

void FUN_0050cbe8(void)

{
  locale *unaff_R13;
  locale *unaff_R15;
  void *in_stack_00000028;
  undefined8 in_stack_00000038;
  undefined1 *in_stack_00000180;
  
  std::locale::~locale(unaff_R13);
  std::locale::~locale(unaff_R15);
  if (in_stack_00000180 != &DAT_011c5338) {
    refcount_release();
  }
  string_vector_destroy(in_stack_00000038);
  qfont_release(in_stack_00000028);
  operator_delete(in_stack_00000028,0x20);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050cbfd name=FUN_0050cbfd size=21 ====

void FUN_0050cbfd(void)

{
  locale *unaff_R14;
  locale *unaff_R15;
  void *in_stack_00000028;
  undefined8 in_stack_00000038;
  
  std::locale::~locale(unaff_R14);
  std::locale::~locale(unaff_R15);
  string_vector_destroy(in_stack_00000038);
  qfont_release(in_stack_00000028);
  operator_delete(in_stack_00000028,0x20);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050cc12 name=FUN_0050cc12 size=10 ====

void FUN_0050cc12(void)

{
  void *in_stack_00000028;
  undefined8 in_stack_00000038;
  
  json_value_destruct();
  json_value_destruct();
  string_vector_destroy(in_stack_00000038);
  qfont_release(in_stack_00000028);
  operator_delete(in_stack_00000028,0x20);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050cc1c name=FUN_0050cc1c size=21 ====

void FUN_0050cc1c(void)

{
  locale *unaff_R14;
  locale *unaff_R15;
  void *in_stack_00000028;
  undefined8 in_stack_00000038;
  undefined1 *in_stack_00000180;
  
  std::locale::~locale(unaff_R14);
  std::locale::~locale(unaff_R15);
  if (in_stack_00000180 != &DAT_011c5338) {
    refcount_release();
  }
  string_vector_destroy(in_stack_00000038);
  qfont_release(in_stack_00000028);
  operator_delete(in_stack_00000028,0x20);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050cc31 name=FUN_0050cc31 size=21 ====

void FUN_0050cc31(void)

{
  locale *unaff_R13;
  locale *unaff_R15;
  void *in_stack_00000028;
  undefined8 in_stack_00000038;
  undefined1 *in_stack_00000180;
  
  std::locale::~locale(unaff_R13);
  std::locale::~locale(unaff_R15);
  if (in_stack_00000180 != &DAT_011c5338) {
    refcount_release();
  }
  string_vector_destroy(in_stack_00000038);
  qfont_release(in_stack_00000028);
  operator_delete(in_stack_00000028,0x20);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050cc46 name=FUN_0050cc46 size=21 ====

void FUN_0050cc46(void)

{
  locale *unaff_R12;
  locale *unaff_R15;
  void *in_stack_00000028;
  undefined8 in_stack_00000038;
  
  std::locale::~locale(unaff_R12);
  std::locale::~locale(unaff_R15);
  string_vector_destroy(in_stack_00000038);
  qfont_release(in_stack_00000028);
  operator_delete(in_stack_00000028,0x20);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050cc5b name=FUN_0050cc5b size=21 ====

void FUN_0050cc5b(void)

{
  locale *unaff_R12;
  locale *unaff_R15;
  void *in_stack_00000028;
  undefined8 in_stack_00000038;
  undefined1 *in_stack_00000180;
  
  std::locale::~locale(unaff_R12);
  std::locale::~locale(unaff_R15);
  if (in_stack_00000180 != &DAT_011c5338) {
    refcount_release();
  }
  string_vector_destroy(in_stack_00000038);
  qfont_release(in_stack_00000028);
  operator_delete(in_stack_00000028,0x20);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050cc70 name=FUN_0050cc70 size=21 ====

void FUN_0050cc70(void)

{
  locale *unaff_R12;
  locale *unaff_R15;
  void *in_stack_00000028;
  undefined8 in_stack_00000038;
  undefined1 *in_stack_00000180;
  
  std::locale::~locale(unaff_R12);
  std::locale::~locale(unaff_R15);
  if (in_stack_00000180 != &DAT_011c5338) {
    refcount_release();
  }
  string_vector_destroy(in_stack_00000038);
  qfont_release(in_stack_00000028);
  operator_delete(in_stack_00000028,0x20);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050cc85 name=FUN_0050cc85 size=24 ====

void FUN_0050cc85(void)

{
  locale *unaff_RBX;
  locale *unaff_R15;
  void *in_stack_00000028;
  undefined8 in_stack_00000038;
  
  std::locale::~locale(unaff_RBX);
  std::locale::~locale(unaff_R15);
  string_vector_destroy(in_stack_00000038);
  qfont_release(in_stack_00000028);
  operator_delete(in_stack_00000028,0x20);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050cc9d name=FUN_0050cc9d size=21 ====

void FUN_0050cc9d(void)

{
  locale *unaff_R14;
  locale *unaff_R15;
  void *in_stack_00000028;
  undefined8 in_stack_00000038;
  undefined1 *in_stack_00000180;
  
  std::locale::~locale(unaff_R14);
  std::locale::~locale(unaff_R15);
  if (in_stack_00000180 != &DAT_011c5338) {
    refcount_release();
  }
  string_vector_destroy(in_stack_00000038);
  qfont_release(in_stack_00000028);
  operator_delete(in_stack_00000028,0x20);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050ccb2 name=FUN_0050ccb2 size=21 ====

void FUN_0050ccb2(void)

{
  locale *unaff_R12;
  locale *unaff_R15;
  void *in_stack_00000028;
  undefined8 in_stack_00000038;
  undefined1 *in_stack_00000180;
  
  std::locale::~locale(unaff_R12);
  std::locale::~locale(unaff_R15);
  if (in_stack_00000180 != &DAT_011c5338) {
    refcount_release();
  }
  string_vector_destroy(in_stack_00000038);
  qfont_release(in_stack_00000028);
  operator_delete(in_stack_00000028,0x20);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050ccc7 name=FUN_0050ccc7 size=14 ====

void FUN_0050ccc7(void)

{
  void *in_stack_00000028;
  undefined8 in_stack_00000038;
  
  json_value_destruct();
  json_value_destruct();
  string_vector_destroy(in_stack_00000038);
  qfont_release(in_stack_00000028);
  operator_delete(in_stack_00000028,0x20);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050ccd5 name=FUN_0050ccd5 size=51 ====

void FUN_0050ccd5(void)

{
  long unaff_RBX;
  void *in_stack_00000028;
  undefined8 in_stack_00000038;
  long in_stack_00000180;
  
  FUN_009bead0();
  if (in_stack_00000180 + -0x18 != unaff_RBX) {
    refcount_release();
  }
  string_vector_destroy(in_stack_00000038);
  qfont_release(in_stack_00000028);
  operator_delete(in_stack_00000028,0x20);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050ccea name=FUN_0050ccea size=31 ====

void FUN_0050ccea(void)

{
  ulong unaff_RBX;
  void *in_stack_00000028;
  undefined8 in_stack_00000038;
  undefined1 *in_stack_00000118;
  void *in_stack_00000160;
  ulong in_stack_00000170;
  void *in_stack_00000180;
  void *in_stack_000001a0;
  
  if (in_stack_000001a0 != (void *)0x0) {
    operator_delete__(in_stack_000001a0);
  }
  if ((0x10 < unaff_RBX) && (in_stack_00000180 != (void *)0x0)) {
    operator_delete__(in_stack_00000180);
  }
  if ((0x10 < in_stack_00000170) && (in_stack_00000160 != (void *)0x0)) {
    operator_delete__(in_stack_00000160);
  }
  string_vector_destroy(&stack0x00000140);
  if (in_stack_00000118 != &DAT_011c5338) {
    refcount_release();
  }
  string_vector_destroy(in_stack_00000038);
  qfont_release(in_stack_00000028);
  operator_delete(in_stack_00000028,0x20);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050cd09 name=FUN_0050cd09 size=13 ====

void FUN_0050cd09(void)

{
  locale *unaff_R15;
  void *in_stack_00000028;
  undefined8 in_stack_00000038;
  undefined1 *in_stack_00000180;
  
  std::locale::~locale(unaff_R15);
  if (in_stack_00000180 != &DAT_011c5338) {
    refcount_release();
  }
  string_vector_destroy(in_stack_00000038);
  qfont_release(in_stack_00000028);
  operator_delete(in_stack_00000028,0x20);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050cd16 name=FUN_0050cd16 size=15 ====

void FUN_0050cd16(void)

{
  void *in_stack_00000028;
  undefined8 in_stack_00000038;
  
  json_value_destruct();
  json_value_destruct();
  string_vector_destroy(in_stack_00000038);
  qfont_release(in_stack_00000028);
  operator_delete(in_stack_00000028,0x20);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050cd25 name=FUN_0050cd25 size=23 ====

void FUN_0050cd25(void)

{
  void *in_stack_00000040;
  
  __cxa_begin_catch();
  operator_delete(in_stack_00000040);
                    /* WARNING: Subroutine does not return */
                    /* try { // try from 0050cd37 to 0050cd3b has its CatchHandler @ 0050cb04 */
  __cxa_rethrow();
}


// ==== entry=0050cd3c name=FUN_0050cd3c size=21 ====

void FUN_0050cd3c(void)

{
  locale *unaff_R14;
  locale *unaff_R15;
  void *in_stack_00000028;
  undefined8 in_stack_00000038;
  undefined1 *in_stack_00000180;
  
  std::locale::~locale(unaff_R14);
  std::locale::~locale(unaff_R15);
  if (in_stack_00000180 != &DAT_011c5338) {
    refcount_release();
  }
  string_vector_destroy(in_stack_00000038);
  qfont_release(in_stack_00000028);
  operator_delete(in_stack_00000028,0x20);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050cd51 name=FUN_0050cd51 size=13 ====

void FUN_0050cd51(void)

{
  void *in_stack_00000028;
  undefined8 in_stack_00000038;
  
  json_value_destruct();
  json_value_destruct();
  string_vector_destroy(in_stack_00000038);
  qfont_release(in_stack_00000028);
  operator_delete(in_stack_00000028,0x20);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050cd5e name=FUN_0050cd5e size=23 ====

void FUN_0050cd5e(void)

{
  void *in_stack_00000028;
  
  operator_delete(in_stack_00000028,0x20);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050cd75 name=FUN_0050cd75 size=23 ====

void FUN_0050cd75(void)

{
  locale *unaff_R15;
  locale *in_stack_00000018;
  void *in_stack_00000028;
  undefined8 in_stack_00000038;
  undefined1 *in_stack_00000118;
  
  std::locale::~locale(in_stack_00000018);
  std::locale::~locale(unaff_R15);
  string_vector_destroy();
  if (in_stack_00000118 != &DAT_011c5338) {
    refcount_release();
  }
  string_vector_destroy(in_stack_00000038);
  qfont_release(in_stack_00000028);
  operator_delete(in_stack_00000028,0x20);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050cd8c name=FUN_0050cd8c size=44 ====

void FUN_0050cd8c(void)

{
  undefined8 in_stack_00000008;
  undefined8 in_stack_00000038;
  
  json_value_destruct();
  json_value_destruct();
  json_value_destruct(in_stack_00000008);
  json_value_destruct(in_stack_00000038);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050cdb8 name=FUN_0050cdb8 size=56 ====

void FUN_0050cdb8(void)

{
  long unaff_retaddr;
  undefined8 in_stack_00000008;
  undefined8 in_stack_00000038;
  long in_stack_00000080;
  long in_stack_00000100;
  
  if (in_stack_00000100 + -0x18 != unaff_retaddr) {
    refcount_release();
  }
  json_value_destruct();
  if (in_stack_00000080 + -0x18 != unaff_retaddr) {
    refcount_release();
  }
  json_value_destruct(in_stack_00000008);
  json_value_destruct(in_stack_00000038);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050cdf0 name=FUN_0050cdf0 size=59 ====

void FUN_0050cdf0(void)

{
  void *unaff_R14;
  long unaff_retaddr;
  undefined8 in_stack_00000008;
  undefined8 in_stack_00000018;
  undefined8 in_stack_00000038;
  long in_stack_00000058;
  
  operator_delete(unaff_R14,0x10);
  qt_byte_array_unref();
  json_value_destruct();
  json_value_destruct();
  if (in_stack_00000058 + -0x18 != unaff_retaddr) {
    refcount_release();
  }
  json_value_destruct(in_stack_00000018);
  json_value_destruct(in_stack_00000008);
  json_value_destruct(in_stack_00000038);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050ce2b name=FUN_0050ce2b size=33 ====

void FUN_0050ce2b(void)

{
  undefined8 in_stack_00000008;
  undefined8 in_stack_00000018;
  undefined8 in_stack_00000038;
  
  json_value_destruct();
  json_value_destruct();
  json_value_destruct(in_stack_00000018);
  json_value_destruct(in_stack_00000008);
  json_value_destruct(in_stack_00000038);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050ce4c name=FUN_0050ce4c size=32 ====

void FUN_0050ce4c(void)

{
  undefined8 in_stack_00000008;
  undefined8 in_stack_00000018;
  undefined8 in_stack_00000038;
  undefined1 *in_stack_00000058;
  undefined1 *in_stack_00000070;
  
  if (in_stack_00000070 != &DAT_011c5338) {
    refcount_release();
  }
  json_value_destruct();
  json_value_destruct();
  if (in_stack_00000058 != &DAT_011c5338) {
    refcount_release();
  }
  json_value_destruct(in_stack_00000018);
  json_value_destruct(in_stack_00000008);
  json_value_destruct(in_stack_00000038);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050ce6c name=FUN_0050ce6c size=25 ====

void FUN_0050ce6c(void)

{
  long unaff_retaddr;
  undefined8 in_stack_00000008;
  undefined8 in_stack_00000018;
  undefined8 in_stack_00000038;
  long in_stack_00000058;
  long in_stack_00000070;
  
  if (in_stack_00000070 + -0x18 != unaff_retaddr) {
    refcount_release();
  }
  qt_byte_array_unref();
  json_value_destruct();
  json_value_destruct();
  if (in_stack_00000058 + -0x18 != unaff_retaddr) {
    refcount_release();
  }
  json_value_destruct(in_stack_00000018);
  json_value_destruct(in_stack_00000008);
  json_value_destruct(in_stack_00000038);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050ce85 name=FUN_0050ce85 size=20 ====

void FUN_0050ce85(void)

{
  long unaff_retaddr;
  undefined8 in_stack_00000008;
  undefined8 in_stack_00000018;
  void *in_stack_00000028;
  undefined8 in_stack_00000038;
  long in_stack_00000058;
  
  operator_delete(in_stack_00000028,0x20);
  qt_byte_array_unref();
  json_value_destruct();
  json_value_destruct();
  if (in_stack_00000058 + -0x18 != unaff_retaddr) {
    refcount_release();
  }
  json_value_destruct(in_stack_00000018);
  json_value_destruct(in_stack_00000008);
  json_value_destruct(in_stack_00000038);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050cea0 name=FUN_0050cea0 size=16 ====

void FUN_0050cea0(void)

{
  qt_array_data_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050ceb0 name=FUN_0050ceb0 size=16 ====

void FUN_0050ceb0(void)

{
  qt_array_data_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050cec0 name=FUN_0050cec0 size=17 ====

void FUN_0050cec0(void)

{
  char unaff_R13B;
  
  if (unaff_R13B != '\0') {
    qt_array_data_unref(&stack0x00000010);
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050ced2 name=FUN_0050ced2 size=41 ====

void FUN_0050ced2(void)

{
  QListView *unaff_RBX;
  
  *(undefined ***)unaff_RBX = &HtmlList_vtable;
  *(undefined ***)(unaff_RBX + 0x10) = &PTR_FUN_01199510;
  QListView::~QListView(unaff_RBX);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050cefc name=FUN_0050cefc size=21 ====

void FUN_0050cefc(void)

{
  void *unaff_R14;
  
  operator_delete(unaff_R14,0x20);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050cf11 name=FUN_0050cf11 size=21 ====

void FUN_0050cf11(void)

{
  void *unaff_R13;
  
  operator_delete(unaff_R13,0x30);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050cf26 name=FUN_0050cf26 size=21 ====

void FUN_0050cf26(void)

{
  void *unaff_RBX;
  
  operator_delete(unaff_RBX,0x40);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050cf3b name=FUN_0050cf3b size=21 ====

void FUN_0050cf3b(void)

{
  void *unaff_R12;
  
  operator_delete(unaff_R12,0x30);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050cf50 name=FUN_0050cf50 size=16 ====

void FUN_0050cf50(void)

{
  FUN_009c45ce();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050cf60 name=FUN_0050cf60 size=16 ====

void FUN_0050cf60(void)

{
  qlist_unref_dispose5();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050cf70 name=FUN_0050cf70 size=16 ====

void FUN_0050cf70(void)

{
  qt_array_data_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050cf80 name=FUN_0050cf80 size=27 ====

void FUN_0050cf80(void)

{
  qt_array_data_unref();
  qt_array_data_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050cf9b name=FUN_0050cf9b size=54 ====

void FUN_0050cf9b(void)

{
  QArrayData *in_stack_00000018;
  
  qt_array_data_unref();
  if (*(int *)in_stack_00000018 != 0) {
    if (*(int *)in_stack_00000018 == -1) goto LAB_0050cf8b;
    LOCK();
    *(int *)in_stack_00000018 = *(int *)in_stack_00000018 + -1;
    UNLOCK();
    if (*(int *)in_stack_00000018 != 0) goto LAB_0050cf8b;
  }
  QArrayData::deallocate(in_stack_00000018,1,8);
LAB_0050cf8b:
  qt_array_data_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050cfd2 name=FUN_0050cfd2 size=48 ====

void FUN_0050cfd2(void)

{
  QDateTime *unaff_RBP;
  QDateTime *unaff_R13;
  
  QDateTime::~QDateTime(unaff_RBP);
  qt_array_data_unref(&stack0x00000010);
  QDateTime::~QDateTime(unaff_R13);
  qt_array_data_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050d010 name=FUN_0050d010 size=22 ====

void FUN_0050d010(void)

{
                    /* WARNING: Subroutine does not return */
  __cxa_throw();
}


// ==== entry=0050d026 name=FUN_0050d026 size=16 ====

void FUN_0050d026(void)

{
  __cxa_free_exception();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050d036 name=FUN_0050d036 size=22 ====

void FUN_0050d036(void)

{
                    /* WARNING: Subroutine does not return */
  __cxa_throw();
}


// ==== entry=0050d04c name=FUN_0050d04c size=16 ====

void FUN_0050d04c(void)

{
  __cxa_free_exception();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050d05c name=FUN_0050d05c size=33 ====

int FUN_0050d05c(undefined8 param_1,undefined8 param_2,long param_3)

{
  long *unaff_RBP;
  int unaff_R14D;
  
  if (param_3 == 1) {
    __cxa_begin_catch();
    __cxa_end_catch();
    return unaff_R14D - *(int *)(*unaff_RBP + 0x14);
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050d07e name=FUN_0050d07e size=11 ====

void FUN_0050d07e(void)

{
  undefined1 *unaff_RBX;
  
  *unaff_RBX = 0;
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050d08a name=FUN_0050d08a size=13 ====

void FUN_0050d08a(void)

{
  undefined1 *unaff_R12;
  
  *unaff_R12 = 0;
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050d098 name=FUN_0050d098 size=13 ====

void FUN_0050d098(void)

{
  undefined1 *unaff_R12;
  
  *unaff_R12 = 0;
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050d0a5 name=FUN_0050d0a5 size=10 ====

void FUN_0050d0a5(void)

{
  undefined1 *unaff_R12;
  
  *unaff_R12 = 0;
                    /* WARNING: Subroutine does not return */
  std::terminate();
}


// ==== entry=0050d0b0 name=FUN_0050d0b0 size=22 ====

void FUN_0050d0b0(void)

{
  long unaff_RBX;
  
  if (*(_Sp_counted_base<(__gnu_cxx::_Lock_policy)2> **)(unaff_RBX + 0x20) !=
      (_Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *)0x0) {
    std::_Sp_counted_base<(__gnu_cxx::_Lock_policy)2>::_M_release
              (*(_Sp_counted_base<(__gnu_cxx::_Lock_policy)2> **)(unaff_RBX + 0x20));
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050d0c6 name=FUN_0050d0c6 size=30 ====

void FUN_0050d0c6(void)

{
  long unaff_RBX;
  undefined1 *unaff_R13;
  
  *unaff_R13 = 0;
  if (*(_Sp_counted_base<(__gnu_cxx::_Lock_policy)2> **)(unaff_RBX + 8) !=
      (_Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *)0x0) {
    std::_Sp_counted_base<(__gnu_cxx::_Lock_policy)2>::_M_release
              (*(_Sp_counted_base<(__gnu_cxx::_Lock_policy)2> **)(unaff_RBX + 8));
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050d0e4 name=FUN_0050d0e4 size=21 ====

void FUN_0050d0e4(void)

{
  void *unaff_R12;
  
  operator_delete(unaff_R12,0x28);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050d0fa name=FUN_0050d0fa size=16 ====

void FUN_0050d0fa(void)

{
  __cxa_begin_catch();
                    /* WARNING: Subroutine does not return */
                    /* try { // try from 0050d105 to 0050d109 has its CatchHandler @ 0050d13e */
  __cxa_rethrow();
}


// ==== entry=0050d10a name=FUN_0050d10a size=21 ====

void FUN_0050d10a(void)

{
  void *unaff_RBP;
  
  operator_delete(unaff_RBP,0x18);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050d11f name=FUN_0050d11f size=31 ====

void FUN_0050d11f(void)

{
  QFile *unaff_RBP;
  
  __cxa_begin_catch();
  QFile::~QFile(unaff_RBP);
  operator_delete(unaff_RBP,0x18);
                    /* WARNING: Subroutine does not return */
  __cxa_rethrow();
}


// ==== entry=0050d14e name=FUN_0050d14e size=14 ====

void FUN_0050d14e(void)

{
  long unaff_R12;
  
  *(undefined1 *)(unaff_R12 + 0x10) = 0;
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050d15c name=FUN_0050d15c size=37 ====

void FUN_0050d15c(void)

{
  ulong in_stack_00000010;
  
  if ((in_stack_00000010 != 0) && ((in_stack_00000010 & 1) != 0)) {
    QReadWriteLock::unlock();
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050d181 name=FUN_0050d181 size=16 ====

void FUN_0050d181(void)

{
  qt_array_data_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050d191 name=FUN_0050d191 size=13 ====

void FUN_0050d191(void)

{
  long unaff_R15;
  
  *(undefined1 *)(unaff_R15 + 0x10) = 0;
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050d19e name=FUN_0050d19e size=14 ====

void FUN_0050d19e(void)

{
  long unaff_R12;
  
  *(undefined1 *)(unaff_R12 + 0x10) = 0;
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050d1ac name=FUN_0050d1ac size=84 ====

void FUN_0050d1ac(void)

{
  long unaff_R14;
  byte unaff_retaddr;
  undefined7 unaff_retaddr_00;
  undefined8 in_stack_00000008;
  
  if ((CONCAT71(unaff_retaddr_00,unaff_retaddr) != 0) && ((unaff_retaddr & 1) != 0)) {
    QReadWriteLock::unlock();
  }
  FUN_009c8460(unaff_R14 + 0x50);
  *(undefined ***)(unaff_R14 + 0x28) = &Uint64RunStyles_vtable;
  Uint32RunStyles_vt13(in_stack_00000008);
  if (*(_Sp_counted_base<(__gnu_cxx::_Lock_policy)2> **)(unaff_R14 + 0x20) !=
      (_Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *)0x0) {
    std::_Sp_counted_base<(__gnu_cxx::_Lock_policy)2>::_M_release
              (*(_Sp_counted_base<(__gnu_cxx::_Lock_policy)2> **)(unaff_R14 + 0x20));
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050d1eb name=FUN_0050d1eb size=13 ====

void FUN_0050d1eb(void)

{
  long unaff_R14;
  undefined8 in_stack_00000008;
  
  qt_array_data_unref();
  FUN_009c8460(unaff_R14 + 0x50);
  *(undefined ***)(unaff_R14 + 0x28) = &Uint64RunStyles_vtable;
  Uint32RunStyles_vt13(in_stack_00000008);
  if (*(_Sp_counted_base<(__gnu_cxx::_Lock_policy)2> **)(unaff_R14 + 0x20) !=
      (_Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *)0x0) {
    std::_Sp_counted_base<(__gnu_cxx::_Lock_policy)2>::_M_release
              (*(_Sp_counted_base<(__gnu_cxx::_Lock_policy)2> **)(unaff_R14 + 0x20));
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050d210 name=FUN_0050d210 size=16 ====

void FUN_0050d210(void)

{
  qatomic_unref_call_deleter();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050d220 name=FUN_0050d220 size=35 ====

void FUN_0050d220(void)

{
  QVariant *unaff_RBX;
  QVariant *unaff_RBP;
  
  QVariant::~QVariant(unaff_RBX);
  qt_array_data_unref();
  QVariant::~QVariant(unaff_RBP);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050d243 name=FUN_0050d243 size=43 ====

void FUN_0050d243(void)

{
  QVariant *unaff_RBX;
  QVariant *unaff_RBP;
  
  QVariant::~QVariant(unaff_RBX);
  qt_array_data_unref();
  QVariant::~QVariant(unaff_RBP);
  qt_array_data_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050d26e name=FUN_0050d26e size=113 ====

/* WARNING: Removing unreachable block (ram,0x0050d30e) */

void FUN_0050d26e(void)

{
  int *piVar1;
  int iVar2;
  void *unaff_R15;
  QArrayData *in_stack_00000030;
  long in_stack_00000040;
  
  if ((void *)(in_stack_00000040 + -0x18) != unaff_R15) {
    LOCK();
    piVar1 = (int *)(in_stack_00000040 + -8);
    iVar2 = *piVar1;
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if (iVar2 < 1) {
      operator_delete((void *)(in_stack_00000040 + -0x18));
    }
  }
  if (*(int *)in_stack_00000030 != 0) {
    if (*(int *)in_stack_00000030 == -1) goto LAB_0050d25e;
    LOCK();
    *(int *)in_stack_00000030 = *(int *)in_stack_00000030 + -1;
    UNLOCK();
    if (*(int *)in_stack_00000030 != 0) goto LAB_0050d25e;
  }
  QArrayData::deallocate(in_stack_00000030,1,8);
LAB_0050d25e:
  qt_array_data_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050d2b7 name=FUN_0050d2b7 size=29 ====

void FUN_0050d2b7(void)

{
  QVariant *unaff_RBX;
  QVariant *unaff_RBP;
  
  QVariant::~QVariant(unaff_RBX);
  qt_array_data_unref();
  QVariant::~QVariant(unaff_RBP);
  qt_array_data_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050d2d4 name=FUN_0050d2d4 size=32 ====

void FUN_0050d2d4(void)

{
  QVariant *unaff_RBX;
  QVariant *unaff_RBP;
  
  QVariant::~QVariant(unaff_RBX);
  qt_array_data_unref();
  QVariant::~QVariant(unaff_RBP);
  qt_array_data_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050d31c name=FUN_0050d31c size=36 ====

void FUN_0050d31c(void)

{
  void *in_stack_00000060;
  
  if (in_stack_00000060 != (void *)0x0) {
    operator_delete(in_stack_00000060,0x34);
  }
  qmap_freetree_variant_nodes();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050d340 name=FUN_0050d340 size=681 ====

/* WARNING: Removing unreachable block (ram,0x0050d535) */
/* WARNING: Removing unreachable block (ram,0x0050d37b) */
/* WARNING: Removing unreachable block (ram,0x0050d554) */
/* WARNING: Removing unreachable block (ram,0x0050d566) */
/* WARNING: Removing unreachable block (ram,0x0050d4f5) */
/* WARNING: Removing unreachable block (ram,0x0050d499) */
/* WARNING: Removing unreachable block (ram,0x0050d420) */
/* WARNING: Removing unreachable block (ram,0x0050d3d3) */
/* WARNING: Removing unreachable block (ram,0x0050d462) */
/* WARNING: Removing unreachable block (ram,0x0050d4d2) */
/* WARNING: Removing unreachable block (ram,0x0050d50f) */
/* WARNING: Removing unreachable block (ram,0x0050d523) */
/* WARNING: Removing unreachable block (ram,0x0050d57a) */

void FUN_0050d340(void)

{
  undefined8 in_stack_00000008;
  undefined1 uStack0000000000000010;
  undefined1 uStack0000000000000018;
  QVariant *in_stack_00000030;
  undefined1 uStack000000000000006b;
  char cStack000000000000006c;
  
  cStack000000000000006c = '\x01';
  uStack000000000000006b = 1;
  uStack0000000000000018 = 0;
  uStack0000000000000010 = 0;
  qt_array_data_unref(&stack0x00000080);
  if (cStack000000000000006c != '\0') {
    QVariant::~QVariant((QVariant *)&stack0x000000c0);
    QVariant::~QVariant((QVariant *)&stack0x000000f0);
  }
  qt_array_data_unref(&stack0x00000088);
  QVariant::~QVariant(in_stack_00000030);
  qmap_freetree_variant_nodes(in_stack_00000008);
  qatomic_unref_call_deleter();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050d5e9 name=FUN_0050d5e9 size=59 ====

/* WARNING: Removing unreachable block (ram,0x0050d535) */
/* WARNING: Removing unreachable block (ram,0x0050d37b) */
/* WARNING: Removing unreachable block (ram,0x0050d554) */
/* WARNING: Removing unreachable block (ram,0x0050d566) */
/* WARNING: Removing unreachable block (ram,0x0050d4f5) */
/* WARNING: Removing unreachable block (ram,0x0050d499) */
/* WARNING: Removing unreachable block (ram,0x0050d420) */
/* WARNING: Removing unreachable block (ram,0x0050d3d3) */
/* WARNING: Removing unreachable block (ram,0x0050d462) */
/* WARNING: Removing unreachable block (ram,0x0050d4d2) */
/* WARNING: Removing unreachable block (ram,0x0050d50f) */
/* WARNING: Removing unreachable block (ram,0x0050d523) */
/* WARNING: Removing unreachable block (ram,0x0050d57a) */
/* WARNING: Removing unreachable block (ram,0x0050d58e) */

void FUN_0050d5e9(void)

{
  undefined8 in_stack_00000008;
  undefined1 uStack0000000000000010;
  undefined1 uStack0000000000000018;
  QVariant *in_stack_00000030;
  undefined1 uStack000000000000006b;
  undefined1 uStack000000000000006c;
  
  uStack000000000000006c = 1;
  uStack000000000000006b = 0;
  uStack0000000000000018 = 0;
  uStack0000000000000010 = 0;
  QVariant::~QVariant((QVariant *)&stack0x000000c0);
  QVariant::~QVariant((QVariant *)&stack0x000000f0);
  qt_array_data_unref(&stack0x00000088);
  QVariant::~QVariant(in_stack_00000030);
  qmap_freetree_variant_nodes(in_stack_00000008);
  qatomic_unref_call_deleter();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050d624 name=FUN_0050d624 size=53 ====

/* WARNING: Removing unreachable block (ram,0x0050d37b) */
/* WARNING: Removing unreachable block (ram,0x0050d535) */
/* WARNING: Removing unreachable block (ram,0x0050d4f5) */
/* WARNING: Removing unreachable block (ram,0x0050d499) */
/* WARNING: Removing unreachable block (ram,0x0050d420) */
/* WARNING: Removing unreachable block (ram,0x0050d3d3) */
/* WARNING: Removing unreachable block (ram,0x0050d462) */
/* WARNING: Removing unreachable block (ram,0x0050d4d2) */
/* WARNING: Removing unreachable block (ram,0x0050d50f) */
/* WARNING: Removing unreachable block (ram,0x0050d523) */

void FUN_0050d624(void)

{
  char unaff_R14B;
  undefined8 in_stack_00000008;
  char cStack0000000000000010;
  undefined1 uStack0000000000000018;
  QVariant *in_stack_00000030;
  char cStack000000000000006b;
  char cStack000000000000006c;
  
  uStack0000000000000018 = 0;
  cStack0000000000000010 = unaff_R14B;
  cStack000000000000006b = unaff_R14B;
  cStack000000000000006c = unaff_R14B;
  if (unaff_R14B != '\0') {
    qt_array_data_unref(&stack0x00000098);
    QVariant::~QVariant((QVariant *)&stack0x00000120);
  }
  if (cStack0000000000000010 != '\0') {
    QVariant::~QVariant((QVariant *)&stack0x000000d0);
  }
  if (cStack000000000000006b != '\0') {
    qt_array_data_unref(&stack0x00000080);
  }
  if (cStack000000000000006c != '\0') {
    QVariant::~QVariant((QVariant *)&stack0x000000c0);
    QVariant::~QVariant((QVariant *)&stack0x000000f0);
  }
  if (unaff_R14B != '\0') {
    qt_array_data_unref(&stack0x00000088);
  }
  QVariant::~QVariant(in_stack_00000030);
  qmap_freetree_variant_nodes(in_stack_00000008);
  qatomic_unref_call_deleter();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050d659 name=FUN_0050d659 size=53 ====

/* WARNING: Removing unreachable block (ram,0x0050d535) */
/* WARNING: Removing unreachable block (ram,0x0050d37b) */
/* WARNING: Removing unreachable block (ram,0x0050d554) */
/* WARNING: Removing unreachable block (ram,0x0050d4f5) */
/* WARNING: Removing unreachable block (ram,0x0050d499) */
/* WARNING: Removing unreachable block (ram,0x0050d420) */
/* WARNING: Removing unreachable block (ram,0x0050d3d3) */
/* WARNING: Removing unreachable block (ram,0x0050d462) */
/* WARNING: Removing unreachable block (ram,0x0050d4d2) */
/* WARNING: Removing unreachable block (ram,0x0050d50f) */
/* WARNING: Removing unreachable block (ram,0x0050d523) */

void FUN_0050d659(void)

{
  char unaff_R14B;
  undefined8 in_stack_00000008;
  char cStack0000000000000010;
  undefined1 uStack0000000000000018;
  QVariant *in_stack_00000030;
  char cStack000000000000006b;
  char cStack000000000000006c;
  
  uStack0000000000000018 = 0;
  cStack0000000000000010 = unaff_R14B;
  cStack000000000000006b = unaff_R14B;
  cStack000000000000006c = unaff_R14B;
  if (unaff_R14B != '\0') {
    QVariant::~QVariant((QVariant *)&stack0x00000120);
  }
  if (cStack0000000000000010 != '\0') {
    QVariant::~QVariant((QVariant *)&stack0x000000d0);
  }
  if (cStack000000000000006b != '\0') {
    qt_array_data_unref(&stack0x00000080);
  }
  if (cStack000000000000006c != '\0') {
    QVariant::~QVariant((QVariant *)&stack0x000000c0);
    QVariant::~QVariant((QVariant *)&stack0x000000f0);
  }
  if (unaff_R14B != '\0') {
    qt_array_data_unref(&stack0x00000088);
  }
  QVariant::~QVariant(in_stack_00000030);
  qmap_freetree_variant_nodes(in_stack_00000008);
  qatomic_unref_call_deleter();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050d68e name=FUN_0050d68e size=57 ====

/* WARNING: Removing unreachable block (ram,0x0050d37b) */
/* WARNING: Removing unreachable block (ram,0x0050d499) */
/* WARNING: Removing unreachable block (ram,0x0050d420) */
/* WARNING: Removing unreachable block (ram,0x0050d3d3) */
/* WARNING: Removing unreachable block (ram,0x0050d462) */
/* WARNING: Removing unreachable block (ram,0x0050d4d2) */

void FUN_0050d68e(void)

{
  undefined8 in_stack_00000008;
  char cStack0000000000000010;
  char cStack0000000000000018;
  QVariant *in_stack_00000030;
  undefined8 in_stack_00000068;
  
  cStack0000000000000018 = in_stack_00000068._3_1_;
  cStack0000000000000010 = in_stack_00000068._3_1_;
  if (in_stack_00000068._3_1_ != '\0') {
    QVariant::~QVariant((QVariant *)&stack0x00000160);
    QVariant::~QVariant((QVariant *)&stack0x00000110);
  }
  if (cStack0000000000000018 != '\0') {
    qt_array_data_unref(&stack0x00000090);
  }
  if (in_stack_00000068._3_1_ != '\0') {
    QVariant::~QVariant((QVariant *)&stack0x00000100);
    QVariant::~QVariant((QVariant *)&stack0x00000130);
    qt_array_data_unref(&stack0x00000098);
    QVariant::~QVariant((QVariant *)&stack0x00000120);
  }
  if (cStack0000000000000010 != '\0') {
    QVariant::~QVariant((QVariant *)&stack0x000000d0);
  }
  if (in_stack_00000068._3_1_ != '\0') {
    qt_array_data_unref(&stack0x00000080);
    QVariant::~QVariant((QVariant *)&stack0x000000c0);
    QVariant::~QVariant((QVariant *)&stack0x000000f0);
    qt_array_data_unref(&stack0x00000088);
  }
  QVariant::~QVariant(in_stack_00000030);
  qmap_freetree_variant_nodes(in_stack_00000008);
  qatomic_unref_call_deleter();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050d6c7 name=FUN_0050d6c7 size=55 ====

/* WARNING: Removing unreachable block (ram,0x0050d37b) */
/* WARNING: Removing unreachable block (ram,0x0050d4d2) */
/* WARNING: Removing unreachable block (ram,0x0050d462) */
/* WARNING: Removing unreachable block (ram,0x0050d3d3) */
/* WARNING: Removing unreachable block (ram,0x0050d420) */
/* WARNING: Removing unreachable block (ram,0x0050d499) */
/* WARNING: Removing unreachable block (ram,0x0050d4f5) */

void FUN_0050d6c7(void)

{
  char unaff_R14B;
  undefined8 in_stack_00000008;
  char cStack0000000000000010;
  char cStack0000000000000018;
  QVariant *in_stack_00000030;
  char cStack000000000000006b;
  char cStack000000000000006c;
  
  cStack0000000000000010 = unaff_R14B;
  cStack0000000000000018 = unaff_R14B;
  cStack000000000000006b = unaff_R14B;
  cStack000000000000006c = unaff_R14B;
  if (unaff_R14B != '\0') {
    QVariant::~QVariant((QVariant *)&stack0x00000110);
  }
  if (cStack0000000000000018 != '\0') {
    qt_array_data_unref(&stack0x00000090);
  }
  if (unaff_R14B != '\0') {
    QVariant::~QVariant((QVariant *)&stack0x00000100);
    QVariant::~QVariant((QVariant *)&stack0x00000130);
    qt_array_data_unref(&stack0x00000098);
    QVariant::~QVariant((QVariant *)&stack0x00000120);
  }
  if (cStack0000000000000010 != '\0') {
    QVariant::~QVariant((QVariant *)&stack0x000000d0);
  }
  if (cStack000000000000006b != '\0') {
    qt_array_data_unref(&stack0x00000080);
  }
  if (cStack000000000000006c != '\0') {
    QVariant::~QVariant((QVariant *)&stack0x000000c0);
    QVariant::~QVariant((QVariant *)&stack0x000000f0);
  }
  if (unaff_R14B != '\0') {
    qt_array_data_unref(&stack0x00000088);
  }
  QVariant::~QVariant(in_stack_00000030);
  qmap_freetree_variant_nodes(in_stack_00000008);
  qatomic_unref_call_deleter();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050d6fe name=FUN_0050d6fe size=54 ====

/* WARNING: Removing unreachable block (ram,0x0050d37b) */
/* WARNING: Removing unreachable block (ram,0x0050d4f5) */
/* WARNING: Removing unreachable block (ram,0x0050d499) */
/* WARNING: Removing unreachable block (ram,0x0050d420) */
/* WARNING: Removing unreachable block (ram,0x0050d3d3) */
/* WARNING: Removing unreachable block (ram,0x0050d462) */
/* WARNING: Removing unreachable block (ram,0x0050d4d2) */
/* WARNING: Removing unreachable block (ram,0x0050d50f) */

void FUN_0050d6fe(void)

{
  char unaff_R14B;
  undefined8 in_stack_00000008;
  char cStack0000000000000010;
  QVariant *in_stack_00000030;
  char cStack000000000000006b;
  char cStack000000000000006c;
  
  cStack0000000000000010 = unaff_R14B;
  cStack000000000000006b = unaff_R14B;
  cStack000000000000006c = unaff_R14B;
  if (unaff_R14B != '\0') {
    qt_array_data_unref(&stack0x00000090);
    QVariant::~QVariant((QVariant *)&stack0x00000100);
    QVariant::~QVariant((QVariant *)&stack0x00000130);
    qt_array_data_unref(&stack0x00000098);
    QVariant::~QVariant((QVariant *)&stack0x00000120);
  }
  if (cStack0000000000000010 != '\0') {
    QVariant::~QVariant((QVariant *)&stack0x000000d0);
  }
  if (cStack000000000000006b != '\0') {
    qt_array_data_unref(&stack0x00000080);
  }
  if (cStack000000000000006c != '\0') {
    QVariant::~QVariant((QVariant *)&stack0x000000c0);
    QVariant::~QVariant((QVariant *)&stack0x000000f0);
  }
  if (unaff_R14B != '\0') {
    qt_array_data_unref(&stack0x00000088);
  }
  QVariant::~QVariant(in_stack_00000030);
  qmap_freetree_variant_nodes(in_stack_00000008);
  qatomic_unref_call_deleter();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050d734 name=FUN_0050d734 size=54 ====

/* WARNING: Removing unreachable block (ram,0x0050d37b) */
/* WARNING: Removing unreachable block (ram,0x0050d4f5) */
/* WARNING: Removing unreachable block (ram,0x0050d499) */
/* WARNING: Removing unreachable block (ram,0x0050d420) */
/* WARNING: Removing unreachable block (ram,0x0050d3d3) */
/* WARNING: Removing unreachable block (ram,0x0050d462) */
/* WARNING: Removing unreachable block (ram,0x0050d4d2) */
/* WARNING: Removing unreachable block (ram,0x0050d50f) */
/* WARNING: Removing unreachable block (ram,0x0050d523) */

void FUN_0050d734(void)

{
  char unaff_R14B;
  undefined8 in_stack_00000008;
  char cStack0000000000000010;
  undefined1 uStack0000000000000018;
  QVariant *in_stack_00000030;
  char cStack000000000000006b;
  char cStack000000000000006c;
  
  uStack0000000000000018 = 0;
  cStack0000000000000010 = unaff_R14B;
  cStack000000000000006b = unaff_R14B;
  cStack000000000000006c = unaff_R14B;
  if (unaff_R14B != '\0') {
    QVariant::~QVariant((QVariant *)&stack0x00000100);
    QVariant::~QVariant((QVariant *)&stack0x00000130);
    qt_array_data_unref(&stack0x00000098);
    QVariant::~QVariant((QVariant *)&stack0x00000120);
  }
  if (cStack0000000000000010 != '\0') {
    QVariant::~QVariant((QVariant *)&stack0x000000d0);
  }
  if (cStack000000000000006b != '\0') {
    qt_array_data_unref(&stack0x00000080);
  }
  if (cStack000000000000006c != '\0') {
    QVariant::~QVariant((QVariant *)&stack0x000000c0);
    QVariant::~QVariant((QVariant *)&stack0x000000f0);
  }
  if (unaff_R14B != '\0') {
    qt_array_data_unref(&stack0x00000088);
  }
  QVariant::~QVariant(in_stack_00000030);
  qmap_freetree_variant_nodes(in_stack_00000008);
  qatomic_unref_call_deleter();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050d76a name=FUN_0050d76a size=77 ====

/* WARNING: Removing unreachable block (ram,0x0050d535) */
/* WARNING: Removing unreachable block (ram,0x0050d37b) */
/* WARNING: Removing unreachable block (ram,0x0050d554) */
/* WARNING: Removing unreachable block (ram,0x0050d566) */
/* WARNING: Removing unreachable block (ram,0x0050d4f5) */
/* WARNING: Removing unreachable block (ram,0x0050d499) */
/* WARNING: Removing unreachable block (ram,0x0050d420) */
/* WARNING: Removing unreachable block (ram,0x0050d3d3) */
/* WARNING: Removing unreachable block (ram,0x0050d462) */
/* WARNING: Removing unreachable block (ram,0x0050d4d2) */
/* WARNING: Removing unreachable block (ram,0x0050d50f) */
/* WARNING: Removing unreachable block (ram,0x0050d523) */

void FUN_0050d76a(void)

{
  undefined8 in_stack_00000008;
  undefined1 uStack0000000000000010;
  undefined1 uStack0000000000000018;
  QVariant *in_stack_00000030;
  char cStack000000000000006b;
  char cStack000000000000006c;
  
  cStack000000000000006c = '\x01';
  cStack000000000000006b = '\x01';
  uStack0000000000000018 = 0;
  uStack0000000000000010 = 1;
  QVariant::~QVariant((QVariant *)&stack0x000000d0);
  if (cStack000000000000006b != '\0') {
    qt_array_data_unref(&stack0x00000080);
  }
  if (cStack000000000000006c != '\0') {
    QVariant::~QVariant((QVariant *)&stack0x000000c0);
    QVariant::~QVariant((QVariant *)&stack0x000000f0);
  }
  qt_array_data_unref(&stack0x00000088);
  QVariant::~QVariant(in_stack_00000030);
  qmap_freetree_variant_nodes(in_stack_00000008);
  qatomic_unref_call_deleter();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050d7b7 name=FUN_0050d7b7 size=69 ====

/* WARNING: Removing unreachable block (ram,0x0050d566) */
/* WARNING: Removing unreachable block (ram,0x0050d535) */
/* WARNING: Removing unreachable block (ram,0x0050d37b) */
/* WARNING: Removing unreachable block (ram,0x0050d554) */
/* WARNING: Removing unreachable block (ram,0x0050d7a5) */
/* WARNING: Removing unreachable block (ram,0x0050d4f5) */
/* WARNING: Removing unreachable block (ram,0x0050d499) */
/* WARNING: Removing unreachable block (ram,0x0050d420) */
/* WARNING: Removing unreachable block (ram,0x0050d3d3) */
/* WARNING: Removing unreachable block (ram,0x0050d462) */
/* WARNING: Removing unreachable block (ram,0x0050d4d2) */
/* WARNING: Removing unreachable block (ram,0x0050d50f) */
/* WARNING: Removing unreachable block (ram,0x0050d523) */
/* WARNING: Removing unreachable block (ram,0x0050d57a) */
/* WARNING: Removing unreachable block (ram,0x0050d58e) */
/* WARNING: Removing unreachable block (ram,0x0050d5a2) */

void FUN_0050d7b7(void)

{
  undefined8 in_stack_00000008;
  undefined1 uStack0000000000000010;
  undefined1 uStack0000000000000018;
  QVariant *pQStack0000000000000030;
  undefined1 uStack000000000000006b;
  undefined1 uStack000000000000006c;
  
  pQStack0000000000000030 = (QVariant *)&stack0x000000e0;
  uStack000000000000006c = 0;
  uStack000000000000006b = 0;
  uStack0000000000000018 = 0;
  uStack0000000000000010 = 0;
  QVariant::~QVariant(pQStack0000000000000030);
  qmap_freetree_variant_nodes(in_stack_00000008);
  qatomic_unref_call_deleter();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050d7fc name=FUN_0050d7fc size=59 ====

/* WARNING: Removing unreachable block (ram,0x0050d37b) */

void FUN_0050d7fc(void)

{
  undefined8 in_stack_00000008;
  char cStack0000000000000010;
  char cStack0000000000000018;
  QVariant *in_stack_00000030;
  undefined8 in_stack_00000068;
  
  cStack0000000000000010 = in_stack_00000068._4_1_;
  cStack0000000000000018 = cStack0000000000000010;
  if (in_stack_00000068._4_1_ != '\0') {
    QVariant::~QVariant((QVariant *)&stack0x000001a0);
    QVariant::~QVariant((QVariant *)&stack0x00000150);
    qt_array_data_unref(&stack0x000000a0);
    QVariant::~QVariant((QVariant *)&stack0x00000140);
    QVariant::~QVariant((QVariant *)&stack0x00000170);
    qt_array_data_unref(&stack0x000000a8);
    QVariant::~QVariant((QVariant *)&stack0x00000160);
    QVariant::~QVariant((QVariant *)&stack0x00000110);
  }
  if (cStack0000000000000018 != '\0') {
    qt_array_data_unref(&stack0x00000090);
  }
  if (in_stack_00000068._4_1_ != '\0') {
    QVariant::~QVariant((QVariant *)&stack0x00000100);
    QVariant::~QVariant((QVariant *)&stack0x00000130);
    qt_array_data_unref(&stack0x00000098);
    QVariant::~QVariant((QVariant *)&stack0x00000120);
  }
  if (cStack0000000000000010 != '\0') {
    QVariant::~QVariant((QVariant *)&stack0x000000d0);
  }
  if (in_stack_00000068._4_1_ != '\0') {
    qt_array_data_unref(&stack0x00000080);
    QVariant::~QVariant((QVariant *)&stack0x000000c0);
    QVariant::~QVariant((QVariant *)&stack0x000000f0);
    qt_array_data_unref(&stack0x00000088);
  }
  QVariant::~QVariant(in_stack_00000030);
  qmap_freetree_variant_nodes(in_stack_00000008);
  qatomic_unref_call_deleter();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050d837 name=FUN_0050d837 size=179 ====

void FUN_0050d837(void)

{
  undefined8 in_stack_00000008;
  char cStack0000000000000010;
  char cStack0000000000000018;
  char cStack0000000000000020;
  QVariant *in_stack_00000030;
  QVariant *in_stack_00000040;
  undefined8 in_stack_00000068;
  
  cStack0000000000000010 = in_stack_00000068._4_1_;
  cStack0000000000000018 = in_stack_00000068._4_1_;
  cStack0000000000000020 = cStack0000000000000010;
  if (in_stack_00000068._4_1_ != '\0') {
    cStack0000000000000020 = in_stack_00000068._4_1_;
    QVariant::~QVariant((QVariant *)&stack0x00000180);
    QVariant::~QVariant(in_stack_00000040);
    qt_array_data_unref(&stack0x000000b8);
    QVariant::~QVariant((QVariant *)&stack0x000001a0);
    QVariant::~QVariant((QVariant *)&stack0x00000150);
    qt_array_data_unref(&stack0x000000a0);
    QVariant::~QVariant((QVariant *)&stack0x00000140);
    QVariant::~QVariant((QVariant *)&stack0x00000170);
    qt_array_data_unref(&stack0x000000a8);
    QVariant::~QVariant((QVariant *)&stack0x00000160);
  }
  if (cStack0000000000000020 != '\0') {
    QVariant::~QVariant((QVariant *)&stack0x00000110);
  }
  if (cStack0000000000000018 != '\0') {
    qt_array_data_unref(&stack0x00000090);
  }
  if (in_stack_00000068._4_1_ != '\0') {
    QVariant::~QVariant((QVariant *)&stack0x00000100);
    QVariant::~QVariant((QVariant *)&stack0x00000130);
    qt_array_data_unref(&stack0x00000098);
    QVariant::~QVariant((QVariant *)&stack0x00000120);
  }
  if (cStack0000000000000010 != '\0') {
    QVariant::~QVariant((QVariant *)&stack0x000000d0);
  }
  if (in_stack_00000068._4_1_ != '\0') {
    qt_array_data_unref(&stack0x00000080);
    QVariant::~QVariant((QVariant *)&stack0x000000c0);
    QVariant::~QVariant((QVariant *)&stack0x000000f0);
    qt_array_data_unref(&stack0x00000088);
  }
  QVariant::~QVariant(in_stack_00000030);
  qmap_freetree_variant_nodes(in_stack_00000008);
  qatomic_unref_call_deleter();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050d8ea name=FUN_0050d8ea size=59 ====

void FUN_0050d8ea(void)

{
  undefined8 in_stack_00000008;
  char cStack0000000000000010;
  char cStack0000000000000018;
  QVariant *in_stack_00000030;
  undefined8 in_stack_00000068;
  
  cStack0000000000000010 = in_stack_00000068._4_1_;
  cStack0000000000000018 = cStack0000000000000010;
  if (in_stack_00000068._4_1_ != '\0') {
    qt_array_data_unref(&stack0x000000b8);
    QVariant::~QVariant((QVariant *)&stack0x000001a0);
    QVariant::~QVariant((QVariant *)&stack0x00000150);
    qt_array_data_unref(&stack0x000000a0);
    QVariant::~QVariant((QVariant *)&stack0x00000140);
    QVariant::~QVariant((QVariant *)&stack0x00000170);
    qt_array_data_unref(&stack0x000000a8);
    QVariant::~QVariant((QVariant *)&stack0x00000160);
    QVariant::~QVariant((QVariant *)&stack0x00000110);
  }
  if (cStack0000000000000018 != '\0') {
    qt_array_data_unref(&stack0x00000090);
  }
  if (in_stack_00000068._4_1_ != '\0') {
    QVariant::~QVariant((QVariant *)&stack0x00000100);
    QVariant::~QVariant((QVariant *)&stack0x00000130);
    qt_array_data_unref(&stack0x00000098);
    QVariant::~QVariant((QVariant *)&stack0x00000120);
  }
  if (cStack0000000000000010 != '\0') {
    QVariant::~QVariant((QVariant *)&stack0x000000d0);
  }
  if (in_stack_00000068._4_1_ != '\0') {
    qt_array_data_unref(&stack0x00000080);
    QVariant::~QVariant((QVariant *)&stack0x000000c0);
    QVariant::~QVariant((QVariant *)&stack0x000000f0);
    qt_array_data_unref(&stack0x00000088);
  }
  QVariant::~QVariant(in_stack_00000030);
  qmap_freetree_variant_nodes(in_stack_00000008);
  qatomic_unref_call_deleter();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050d925 name=FUN_0050d925 size=60 ====

void FUN_0050d925(void)

{
  QVariant *in_stack_00000040;
  void *in_stack_00000190;
  _Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *in_stack_000001a8;
  
  QVariant::~QVariant(in_stack_00000040);
  if (in_stack_00000190 != (void *)0x0) {
    operator_delete(in_stack_00000190,0x34);
  }
  if (in_stack_000001a8 != (_Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *)0x0) {
    std::_Sp_counted_base<(__gnu_cxx::_Lock_policy)2>::_M_release(in_stack_000001a8);
  }
  qatomic_unref_call_deleter();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050d961 name=FUN_0050d961 size=269 ====

void FUN_0050d961(void)

{
  bool bVar1;
  undefined8 in_stack_00000008;
  char cStack0000000000000010;
  char cStack0000000000000018;
  char cStack0000000000000020;
  QVariant *in_stack_00000030;
  QVariant *in_stack_00000040;
  QVariant *in_stack_00000060;
  undefined8 in_stack_00000068;
  
  cStack0000000000000010 = in_stack_00000068._4_1_;
  cStack0000000000000020 = in_stack_00000068._4_1_;
  cStack0000000000000018 = in_stack_00000068._4_1_;
  if (in_stack_00000068._4_1_ != '\0') {
    QVariant::~QVariant(in_stack_00000060);
    if (in_stack_00000068._4_1_ != '\0') {
      qt_array_data_unref(&stack0x000000b0);
    }
    bVar1 = cStack0000000000000020 != '\0';
    cStack0000000000000020 = in_stack_00000068._4_1_;
    if (bVar1) {
      QVariant::~QVariant((QVariant *)&stack0x00000180);
      QVariant::~QVariant(in_stack_00000040);
    }
  }
  if (in_stack_00000068._4_1_ != '\0') {
    qt_array_data_unref(&stack0x000000b8);
    QVariant::~QVariant((QVariant *)&stack0x000001a0);
    QVariant::~QVariant((QVariant *)&stack0x00000150);
    qt_array_data_unref(&stack0x000000a0);
    QVariant::~QVariant((QVariant *)&stack0x00000140);
    QVariant::~QVariant((QVariant *)&stack0x00000170);
    qt_array_data_unref(&stack0x000000a8);
    QVariant::~QVariant((QVariant *)&stack0x00000160);
  }
  if (cStack0000000000000020 != '\0') {
    QVariant::~QVariant((QVariant *)&stack0x00000110);
  }
  if (cStack0000000000000018 != '\0') {
    qt_array_data_unref(&stack0x00000090);
  }
  if (in_stack_00000068._4_1_ != '\0') {
    QVariant::~QVariant((QVariant *)&stack0x00000100);
    QVariant::~QVariant((QVariant *)&stack0x00000130);
    qt_array_data_unref(&stack0x00000098);
    QVariant::~QVariant((QVariant *)&stack0x00000120);
  }
  if (cStack0000000000000010 != '\0') {
    QVariant::~QVariant((QVariant *)&stack0x000000d0);
  }
  if (in_stack_00000068._4_1_ != '\0') {
    qt_array_data_unref(&stack0x00000080);
    QVariant::~QVariant((QVariant *)&stack0x000000c0);
    QVariant::~QVariant((QVariant *)&stack0x000000f0);
    qt_array_data_unref(&stack0x00000088);
  }
  QVariant::~QVariant(in_stack_00000030);
  qmap_freetree_variant_nodes(in_stack_00000008);
  qatomic_unref_call_deleter();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050da6e name=FUN_0050da6e size=64 ====

void FUN_0050da6e(void)

{
  bool bVar1;
  undefined8 in_stack_00000008;
  char cStack0000000000000010;
  char cStack0000000000000018;
  char cStack0000000000000020;
  QVariant *in_stack_00000030;
  QVariant *in_stack_00000040;
  undefined8 in_stack_00000068;
  
  cStack0000000000000010 = in_stack_00000068._4_1_;
  cStack0000000000000018 = cStack0000000000000010;
  cStack0000000000000020 = cStack0000000000000010;
  if (in_stack_00000068._4_1_ != '\0') {
    qt_array_data_unref(&stack0x000000b0);
  }
  bVar1 = cStack0000000000000020 != '\0';
  cStack0000000000000020 = in_stack_00000068._4_1_;
  if (bVar1) {
    cStack0000000000000020 = in_stack_00000068._4_1_;
    QVariant::~QVariant((QVariant *)&stack0x00000180);
    QVariant::~QVariant(in_stack_00000040);
  }
  if (in_stack_00000068._4_1_ != '\0') {
    qt_array_data_unref(&stack0x000000b8);
    QVariant::~QVariant((QVariant *)&stack0x000001a0);
    QVariant::~QVariant((QVariant *)&stack0x00000150);
    qt_array_data_unref(&stack0x000000a0);
    QVariant::~QVariant((QVariant *)&stack0x00000140);
    QVariant::~QVariant((QVariant *)&stack0x00000170);
    qt_array_data_unref(&stack0x000000a8);
    QVariant::~QVariant((QVariant *)&stack0x00000160);
  }
  if (cStack0000000000000020 != '\0') {
    QVariant::~QVariant((QVariant *)&stack0x00000110);
  }
  if (cStack0000000000000018 != '\0') {
    qt_array_data_unref(&stack0x00000090);
  }
  if (in_stack_00000068._4_1_ != '\0') {
    QVariant::~QVariant((QVariant *)&stack0x00000100);
    QVariant::~QVariant((QVariant *)&stack0x00000130);
    qt_array_data_unref(&stack0x00000098);
    QVariant::~QVariant((QVariant *)&stack0x00000120);
  }
  if (cStack0000000000000010 != '\0') {
    QVariant::~QVariant((QVariant *)&stack0x000000d0);
  }
  if (in_stack_00000068._4_1_ != '\0') {
    qt_array_data_unref(&stack0x00000080);
    QVariant::~QVariant((QVariant *)&stack0x000000c0);
    QVariant::~QVariant((QVariant *)&stack0x000000f0);
    qt_array_data_unref(&stack0x00000088);
  }
  QVariant::~QVariant(in_stack_00000030);
  qmap_freetree_variant_nodes(in_stack_00000008);
  qatomic_unref_call_deleter();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050daae name=FUN_0050daae size=59 ====

/* WARNING: Removing unreachable block (ram,0x0050d535) */
/* WARNING: Removing unreachable block (ram,0x0050d37b) */
/* WARNING: Removing unreachable block (ram,0x0050d554) */
/* WARNING: Removing unreachable block (ram,0x0050d566) */
/* WARNING: Removing unreachable block (ram,0x0050d4f5) */
/* WARNING: Removing unreachable block (ram,0x0050d499) */
/* WARNING: Removing unreachable block (ram,0x0050d420) */
/* WARNING: Removing unreachable block (ram,0x0050d3d3) */
/* WARNING: Removing unreachable block (ram,0x0050d462) */
/* WARNING: Removing unreachable block (ram,0x0050d4d2) */
/* WARNING: Removing unreachable block (ram,0x0050d50f) */
/* WARNING: Removing unreachable block (ram,0x0050d523) */
/* WARNING: Removing unreachable block (ram,0x0050d57a) */
/* WARNING: Removing unreachable block (ram,0x0050d58e) */
/* WARNING: Removing unreachable block (ram,0x0050d5a2) */

void FUN_0050daae(void)

{
  undefined8 in_stack_00000008;
  undefined1 uStack0000000000000010;
  undefined1 uStack0000000000000018;
  QVariant *in_stack_00000030;
  undefined1 uStack000000000000006b;
  undefined1 uStack000000000000006c;
  
  uStack000000000000006c = 0;
  uStack000000000000006b = 0;
  uStack0000000000000018 = 0;
  uStack0000000000000010 = 0;
  qt_array_data_unref(&stack0x00000088);
  QVariant::~QVariant(in_stack_00000030);
  qmap_freetree_variant_nodes(in_stack_00000008);
  qatomic_unref_call_deleter();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050dae9 name=FUN_0050dae9 size=58 ====

/* WARNING: Removing unreachable block (ram,0x0050d37b) */
/* WARNING: Removing unreachable block (ram,0x0050d462) */
/* WARNING: Removing unreachable block (ram,0x0050d3d3) */
/* WARNING: Removing unreachable block (ram,0x0050d420) */
/* WARNING: Removing unreachable block (ram,0x0050d499) */

void FUN_0050dae9(void)

{
  undefined8 in_stack_00000008;
  char cStack0000000000000010;
  char cStack0000000000000018;
  QVariant *in_stack_00000030;
  undefined8 in_stack_00000068;
  
  cStack0000000000000018 = in_stack_00000068._3_1_;
  cStack0000000000000010 = in_stack_00000068._3_1_;
  if (in_stack_00000068._3_1_ != '\0') {
    qt_array_data_unref(&stack0x000000a8);
    QVariant::~QVariant((QVariant *)&stack0x00000160);
    QVariant::~QVariant((QVariant *)&stack0x00000110);
  }
  if (cStack0000000000000018 != '\0') {
    qt_array_data_unref(&stack0x00000090);
  }
  if (in_stack_00000068._3_1_ != '\0') {
    QVariant::~QVariant((QVariant *)&stack0x00000100);
    QVariant::~QVariant((QVariant *)&stack0x00000130);
    qt_array_data_unref(&stack0x00000098);
    QVariant::~QVariant((QVariant *)&stack0x00000120);
  }
  if (cStack0000000000000010 != '\0') {
    QVariant::~QVariant((QVariant *)&stack0x000000d0);
  }
  if (in_stack_00000068._3_1_ != '\0') {
    qt_array_data_unref(&stack0x00000080);
    QVariant::~QVariant((QVariant *)&stack0x000000c0);
    QVariant::~QVariant((QVariant *)&stack0x000000f0);
    qt_array_data_unref(&stack0x00000088);
  }
  QVariant::~QVariant(in_stack_00000030);
  qmap_freetree_variant_nodes(in_stack_00000008);
  qatomic_unref_call_deleter();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050db23 name=FUN_0050db23 size=59 ====

/* WARNING: Removing unreachable block (ram,0x0050d37b) */
/* WARNING: Removing unreachable block (ram,0x0050d420) */
/* WARNING: Removing unreachable block (ram,0x0050d3d3) */
/* WARNING: Removing unreachable block (ram,0x0050d462) */

void FUN_0050db23(void)

{
  undefined8 in_stack_00000008;
  char cStack0000000000000010;
  char cStack0000000000000018;
  QVariant *in_stack_00000030;
  undefined8 in_stack_00000068;
  
  cStack0000000000000018 = in_stack_00000068._3_1_;
  cStack0000000000000010 = in_stack_00000068._3_1_;
  if (in_stack_00000068._3_1_ != '\0') {
    QVariant::~QVariant((QVariant *)&stack0x00000140);
    QVariant::~QVariant((QVariant *)&stack0x00000170);
    qt_array_data_unref(&stack0x000000a8);
    QVariant::~QVariant((QVariant *)&stack0x00000160);
    QVariant::~QVariant((QVariant *)&stack0x00000110);
  }
  if (cStack0000000000000018 != '\0') {
    qt_array_data_unref(&stack0x00000090);
  }
  if (in_stack_00000068._3_1_ != '\0') {
    QVariant::~QVariant((QVariant *)&stack0x00000100);
    QVariant::~QVariant((QVariant *)&stack0x00000130);
    qt_array_data_unref(&stack0x00000098);
    QVariant::~QVariant((QVariant *)&stack0x00000120);
  }
  if (cStack0000000000000010 != '\0') {
    QVariant::~QVariant((QVariant *)&stack0x000000d0);
  }
  if (in_stack_00000068._3_1_ != '\0') {
    qt_array_data_unref(&stack0x00000080);
    QVariant::~QVariant((QVariant *)&stack0x000000c0);
    QVariant::~QVariant((QVariant *)&stack0x000000f0);
    qt_array_data_unref(&stack0x00000088);
  }
  QVariant::~QVariant(in_stack_00000030);
  qmap_freetree_variant_nodes(in_stack_00000008);
  qatomic_unref_call_deleter();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050db5e name=FUN_0050db5e size=59 ====

/* WARNING: Removing unreachable block (ram,0x0050d37b) */
/* WARNING: Removing unreachable block (ram,0x0050d3d3) */
/* WARNING: Removing unreachable block (ram,0x0050d420) */

void FUN_0050db5e(void)

{
  undefined8 in_stack_00000008;
  char cStack0000000000000010;
  char cStack0000000000000018;
  QVariant *in_stack_00000030;
  undefined8 in_stack_00000068;
  
  cStack0000000000000018 = in_stack_00000068._3_1_;
  cStack0000000000000010 = in_stack_00000068._3_1_;
  if (in_stack_00000068._3_1_ != '\0') {
    qt_array_data_unref(&stack0x000000a0);
    QVariant::~QVariant((QVariant *)&stack0x00000140);
    QVariant::~QVariant((QVariant *)&stack0x00000170);
    qt_array_data_unref(&stack0x000000a8);
    QVariant::~QVariant((QVariant *)&stack0x00000160);
    QVariant::~QVariant((QVariant *)&stack0x00000110);
  }
  if (cStack0000000000000018 != '\0') {
    qt_array_data_unref(&stack0x00000090);
  }
  if (in_stack_00000068._3_1_ != '\0') {
    QVariant::~QVariant((QVariant *)&stack0x00000100);
    QVariant::~QVariant((QVariant *)&stack0x00000130);
    qt_array_data_unref(&stack0x00000098);
    QVariant::~QVariant((QVariant *)&stack0x00000120);
  }
  if (cStack0000000000000010 != '\0') {
    QVariant::~QVariant((QVariant *)&stack0x000000d0);
  }
  if (in_stack_00000068._3_1_ != '\0') {
    qt_array_data_unref(&stack0x00000080);
    QVariant::~QVariant((QVariant *)&stack0x000000c0);
    QVariant::~QVariant((QVariant *)&stack0x000000f0);
    qt_array_data_unref(&stack0x00000088);
  }
  QVariant::~QVariant(in_stack_00000030);
  qmap_freetree_variant_nodes(in_stack_00000008);
  qatomic_unref_call_deleter();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050db99 name=FUN_0050db99 size=59 ====

/* WARNING: Removing unreachable block (ram,0x0050d37b) */
/* WARNING: Removing unreachable block (ram,0x0050d3d3) */

void FUN_0050db99(void)

{
  undefined8 in_stack_00000008;
  char cStack0000000000000010;
  char cStack0000000000000018;
  QVariant *in_stack_00000030;
  undefined8 in_stack_00000068;
  
  cStack0000000000000018 = in_stack_00000068._3_1_;
  cStack0000000000000010 = in_stack_00000068._3_1_;
  if (in_stack_00000068._3_1_ != '\0') {
    QVariant::~QVariant((QVariant *)&stack0x00000150);
    qt_array_data_unref(&stack0x000000a0);
    QVariant::~QVariant((QVariant *)&stack0x00000140);
    QVariant::~QVariant((QVariant *)&stack0x00000170);
    qt_array_data_unref(&stack0x000000a8);
    QVariant::~QVariant((QVariant *)&stack0x00000160);
    QVariant::~QVariant((QVariant *)&stack0x00000110);
  }
  if (cStack0000000000000018 != '\0') {
    qt_array_data_unref(&stack0x00000090);
  }
  if (in_stack_00000068._3_1_ != '\0') {
    QVariant::~QVariant((QVariant *)&stack0x00000100);
    QVariant::~QVariant((QVariant *)&stack0x00000130);
    qt_array_data_unref(&stack0x00000098);
    QVariant::~QVariant((QVariant *)&stack0x00000120);
  }
  if (cStack0000000000000010 != '\0') {
    QVariant::~QVariant((QVariant *)&stack0x000000d0);
  }
  if (in_stack_00000068._3_1_ != '\0') {
    qt_array_data_unref(&stack0x00000080);
    QVariant::~QVariant((QVariant *)&stack0x000000c0);
    QVariant::~QVariant((QVariant *)&stack0x000000f0);
    qt_array_data_unref(&stack0x00000088);
  }
  QVariant::~QVariant(in_stack_00000030);
  qmap_freetree_variant_nodes(in_stack_00000008);
  qatomic_unref_call_deleter();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050dbd4 name=FUN_0050dbd4 size=15 ====

void FUN_0050dbd4(void)

{
  undefined8 in_stack_00000008;
  QVariant *in_stack_00000040;
  
  QVariant::~QVariant(in_stack_00000040);
  qmap_freetree_variant_nodes(in_stack_00000008);
  qatomic_unref_call_deleter();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050dbe4 name=FUN_0050dbe4 size=11 ====

void FUN_0050dbe4(void)

{
  undefined1 *unaff_RBX;
  
  *unaff_RBX = 0;
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050dbf0 name=FUN_0050dbf0 size=11 ====

void FUN_0050dbf0(void)

{
  undefined1 *unaff_RBX;
  
  *unaff_RBX = 0;
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050dbfc name=FUN_0050dbfc size=22 ====

void FUN_0050dbfc(void)

{
                    /* WARNING: Subroutine does not return */
  __cxa_throw();
}


// ==== entry=0050dc12 name=FUN_0050dc12 size=16 ====

void FUN_0050dc12(void)

{
  __cxa_free_exception();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050dc22 name=FUN_0050dc22 size=11 ====

void FUN_0050dc22(void)

{
  undefined1 *unaff_RBX;
  
  *unaff_RBX = 0;
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050dc2e name=FUN_0050dc2e size=22 ====

void FUN_0050dc2e(void)

{
                    /* WARNING: Subroutine does not return */
  __cxa_throw();
}


// ==== entry=0050dc44 name=FUN_0050dc44 size=16 ====

void FUN_0050dc44(void)

{
  __cxa_free_exception();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050dc54 name=FUN_0050dc54 size=22 ====

void FUN_0050dc54(void)

{
                    /* WARNING: Subroutine does not return */
  __cxa_throw();
}


// ==== entry=0050dc6a name=FUN_0050dc6a size=16 ====

void FUN_0050dc6a(void)

{
  __cxa_free_exception();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050dc7a name=FUN_0050dc7a size=11 ====

void FUN_0050dc7a(void)

{
  undefined1 *unaff_RBX;
  
  *unaff_RBX = 0;
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050dc86 name=FUN_0050dc86 size=11 ====

void FUN_0050dc86(void)

{
  undefined1 *unaff_RBX;
  
  *unaff_RBX = 0;
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050dc92 name=FUN_0050dc92 size=11 ====

void FUN_0050dc92(void)

{
  undefined1 *unaff_RBX;
  
  *unaff_RBX = 0;
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050dc9e name=FUN_0050dc9e size=21 ====

void FUN_0050dc9e(void)

{
  void *unaff_R14;
  
  operator_delete(unaff_R14,0x20);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050dcb3 name=FUN_0050dcb3 size=21 ====

void FUN_0050dcb3(void)

{
  void *unaff_R14;
  
  operator_delete(unaff_R14,0x20);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050dcc8 name=FUN_0050dcc8 size=21 ====

void FUN_0050dcc8(void)

{
  void *unaff_R14;
  
  operator_delete(unaff_R14,0x20);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050dcdd name=FUN_0050dcdd size=21 ====

void FUN_0050dcdd(void)

{
  void *unaff_R14;
  
  operator_delete(unaff_R14,0x20);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050dcf2 name=FUN_0050dcf2 size=21 ====

void FUN_0050dcf2(void)

{
  void *unaff_R14;
  
  operator_delete(unaff_R14,0x20);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050dd07 name=FUN_0050dd07 size=21 ====

void FUN_0050dd07(void)

{
  void *unaff_R14;
  
  operator_delete(unaff_R14,0x20);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050dd1c name=FUN_0050dd1c size=21 ====

void FUN_0050dd1c(void)

{
  void *unaff_R13;
  
  operator_delete(unaff_R13,0x20);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050dd31 name=FUN_0050dd31 size=21 ====

void FUN_0050dd31(void)

{
  void *unaff_R13;
  
  operator_delete(unaff_R13,0x20);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050dd46 name=FUN_0050dd46 size=21 ====

void FUN_0050dd46(void)

{
  void *unaff_R13;
  
  operator_delete(unaff_R13,0x20);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050dd5b name=FUN_0050dd5b size=21 ====

void FUN_0050dd5b(void)

{
  void *unaff_R13;
  
  operator_delete(unaff_R13,0x20);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050dd70 name=FUN_0050dd70 size=21 ====

void FUN_0050dd70(void)

{
  void *unaff_R13;
  
  operator_delete(unaff_R13,0x20);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050dd85 name=FUN_0050dd85 size=21 ====

void FUN_0050dd85(void)

{
  void *unaff_R13;
  
  operator_delete(unaff_R13,0x20);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050dda0 name=FUN_0050dda0 size=16 ====

void FUN_0050dda0(void)

{
  qt_byte_array_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050ddb0 name=FUN_0050ddb0 size=41 ====

void FUN_0050ddb0(void)

{
  long unaff_RBX;
  long unaff_R14;
  long in_stack_00000008;
  
  if (in_stack_00000008 + -0x18 != unaff_R14) {
    refcount_delete_offset10();
  }
  if (*(_Sp_counted_base<(__gnu_cxx::_Lock_policy)2> **)(unaff_RBX + 8) !=
      (_Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *)0x0) {
    std::_Sp_counted_base<(__gnu_cxx::_Lock_policy)2>::_M_release
              (*(_Sp_counted_base<(__gnu_cxx::_Lock_policy)2> **)(unaff_RBX + 8));
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050ddda name=FUN_0050ddda size=41 ====

void FUN_0050ddda(void)

{
  long unaff_RBX;
  long unaff_R13;
  long in_stack_00000008;
  
  if (in_stack_00000008 + -0x18 != unaff_R13) {
    refcount_delete_offset10();
  }
  if (*(_Sp_counted_base<(__gnu_cxx::_Lock_policy)2> **)(unaff_RBX + 8) !=
      (_Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *)0x0) {
    std::_Sp_counted_base<(__gnu_cxx::_Lock_policy)2>::_M_release
              (*(_Sp_counted_base<(__gnu_cxx::_Lock_policy)2> **)(unaff_RBX + 8));
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050de04 name=FUN_0050de04 size=31 ====

void FUN_0050de04(void)

{
  undefined1 *in_stack_00000038;
  
  if (in_stack_00000038 != &DAT_011c5338) {
    refcount_delete_offset10();
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050de24 name=FUN_0050de24 size=31 ====

void FUN_0050de24(void)

{
  undefined1 *in_stack_00000038;
  
  if (in_stack_00000038 != &DAT_011c5338) {
    refcount_delete_offset10();
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050de44 name=FUN_0050de44 size=31 ====

void FUN_0050de44(void)

{
  void *unaff_RBP;
  undefined8 in_stack_00000010;
  
  operator_delete(unaff_RBP,0x28);
  json_value_destruct(in_stack_00000010);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050de63 name=FUN_0050de63 size=18 ====

void FUN_0050de63(void)

{
  undefined8 in_stack_00000010;
  
  json_value_destruct();
  json_value_destruct();
  json_value_destruct(in_stack_00000010);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050de75 name=FUN_0050de75 size=28 ====

void FUN_0050de75(void)

{
  void *unaff_RBX;
  undefined8 in_stack_00000008;
  undefined8 in_stack_00000010;
  
  operator_delete(unaff_RBX,0x18);
  json_value_destruct(in_stack_00000008);
  json_value_destruct(in_stack_00000010);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050de91 name=FUN_0050de91 size=66 ====

/* WARNING: Removing unreachable block (ram,0x0050dee6) */
/* WARNING: Removing unreachable block (ram,0x0050deef) */
/* WARNING: Removing unreachable block (ram,0x0050def4) */

void FUN_0050de91(void)

{
  void *unaff_RBX;
  undefined8 in_stack_00000008;
  undefined8 in_stack_00000010;
  undefined8 in_stack_00000018;
  undefined1 *in_stack_00000030;
  
  operator_delete(unaff_RBX,0x20);
  qt_byte_array_unref(in_stack_00000018);
  json_value_destruct();
  if (in_stack_00000030 != &DAT_011c5338) {
    refcount_delete_offset10();
  }
  json_value_destruct(in_stack_00000008);
  json_value_destruct(in_stack_00000010);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050ded3 name=FUN_0050ded3 size=51 ====

void FUN_0050ded3(void)

{
  void *unaff_RBX;
  undefined8 in_stack_00000008;
  undefined8 in_stack_00000010;
  
  json_value_destruct();
  json_value_destruct();
  if (*(_Sp_counted_base<(__gnu_cxx::_Lock_policy)2> **)((long)unaff_RBX + 0x10) !=
      (_Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *)0x0) {
    std::_Sp_counted_base<(__gnu_cxx::_Lock_policy)2>::_M_release
              (*(_Sp_counted_base<(__gnu_cxx::_Lock_policy)2> **)((long)unaff_RBX + 0x10));
  }
  operator_delete(unaff_RBX,0x18);
  json_value_destruct(in_stack_00000008);
  json_value_destruct(in_stack_00000010);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050df06 name=FUN_0050df06 size=117 ====

void FUN_0050df06(void)

{
  void *unaff_RBX;
  long unaff_R13;
  undefined8 in_stack_00000010;
  
  json_value_destruct();
  json_value_destruct();
  json_value_destruct();
  if (unaff_RBX != (void *)0x0) {
    if (*(long *)((long)unaff_RBX + 0x18) + -0x18 != unaff_R13) {
      refcount_delete_offset10();
    }
    if (*(long *)((long)unaff_RBX + 0x10) + -0x18 != unaff_R13) {
      refcount_delete_offset10();
    }
    if (*(long *)((long)unaff_RBX + 8) + -0x18 != unaff_R13) {
      refcount_delete_offset10();
    }
    operator_delete(unaff_RBX,0x20);
  }
  json_value_destruct(in_stack_00000010);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050df7b name=FUN_0050df7b size=18 ====

void FUN_0050df7b(void)

{
  void *unaff_RBP;
  undefined8 in_stack_00000010;
  
  operator_delete(unaff_RBP,0x28);
  json_value_destruct(in_stack_00000010);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050df8d name=FUN_0050df8d size=31 ====

void FUN_0050df8d(void)

{
  void *unaff_RBX;
  undefined8 in_stack_00000010;
  
  json_value_destruct();
  json_value_destruct();
  if (*(undefined1 **)((long)unaff_RBX + 0x18) != &DAT_011c5338) {
    refcount_delete_offset10();
  }
  if (*(undefined1 **)((long)unaff_RBX + 0x10) != &DAT_011c5338) {
    refcount_delete_offset10();
  }
  if (*(undefined1 **)((long)unaff_RBX + 8) != &DAT_011c5338) {
    refcount_delete_offset10();
  }
  operator_delete(unaff_RBX,0x20);
  json_value_destruct(in_stack_00000010);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050dfac name=FUN_0050dfac size=41 ====

/* WARNING: Removing unreachable block (ram,0x0050df26) */
/* WARNING: Removing unreachable block (ram,0x0050df33) */
/* WARNING: Removing unreachable block (ram,0x0050df38) */
/* WARNING: Removing unreachable block (ram,0x0050df45) */
/* WARNING: Removing unreachable block (ram,0x0050df4a) */
/* WARNING: Removing unreachable block (ram,0x0050df57) */
/* WARNING: Removing unreachable block (ram,0x0050df5c) */

void FUN_0050dfac(void)

{
  void *unaff_RBX;
  undefined8 in_stack_00000010;
  undefined8 in_stack_00000018;
  
  operator_delete(unaff_RBX,0x20);
  qt_byte_array_unref(in_stack_00000018);
  json_value_destruct();
  json_value_destruct();
  json_value_destruct(in_stack_00000010);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050dfd5 name=FUN_0050dfd5 size=35 ====

void FUN_0050dfd5(void)

{
  void *unaff_RBX;
  long unaff_R13;
  undefined8 in_stack_00000010;
  long in_stack_00000058;
  
  if (in_stack_00000058 + -0x18 != unaff_R13) {
    refcount_delete_offset10();
  }
  json_value_destruct();
  json_value_destruct();
  json_value_destruct();
  if (unaff_RBX != (void *)0x0) {
    if (*(long *)((long)unaff_RBX + 0x18) + -0x18 != unaff_R13) {
      refcount_delete_offset10();
    }
    if (*(long *)((long)unaff_RBX + 0x10) + -0x18 != unaff_R13) {
      refcount_delete_offset10();
    }
    if (*(long *)((long)unaff_RBX + 8) + -0x18 != unaff_R13) {
      refcount_delete_offset10();
    }
    operator_delete(unaff_RBX,0x20);
  }
  json_value_destruct(in_stack_00000010);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050dff8 name=FUN_0050dff8 size=120 ====

void FUN_0050dff8(void)

{
  long unaff_R12;
  long unaff_R13;
  undefined8 in_stack_00000008;
  locale *in_stack_00000010;
  long in_stack_00000028;
  long in_stack_00000030;
  undefined1 *in_stack_00000050;
  undefined1 *in_stack_00000058;
  
  std::locale::~locale((locale *)(in_stack_00000028 + 8));
  std::locale::~locale((locale *)(unaff_R13 + 8));
  std::locale::~locale((locale *)(unaff_R12 + 8));
  std::locale::~locale((locale *)(in_stack_00000030 + 8));
  std::locale::~locale(in_stack_00000010);
  if (in_stack_00000058 != &DAT_011c5338) {
    refcount_delete_offset10();
  }
  if (in_stack_00000050 != &DAT_011c5338) {
    refcount_delete_offset10();
  }
  json_value_destruct(in_stack_00000008);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050e070 name=FUN_0050e070 size=28 ====

void FUN_0050e070(void)

{
  undefined8 unaff_retaddr;
  undefined8 in_stack_00000008;
  undefined8 in_stack_00000028;
  undefined1 *in_stack_00000050;
  
  json_value_destruct(unaff_retaddr);
  json_value_destruct(in_stack_00000028);
  if (in_stack_00000050 != &DAT_011c5338) {
    refcount_delete_offset10();
  }
  json_value_destruct(in_stack_00000008);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050e08c name=FUN_0050e08c size=67 ====

void FUN_0050e08c(void)

{
  long unaff_R13;
  long unaff_R15;
  locale *unaff_retaddr;
  undefined8 in_stack_00000008;
  long in_stack_00000020;
  long in_stack_00000038;
  undefined1 *in_stack_00000050;
  
  std::locale::~locale((locale *)(in_stack_00000038 + 8));
  std::locale::~locale((locale *)(unaff_R13 + 8));
  std::locale::~locale((locale *)(unaff_R15 + 8));
  std::locale::~locale((locale *)(in_stack_00000020 + 8));
  std::locale::~locale(unaff_retaddr);
  if (in_stack_00000050 != &DAT_011c5338) {
    refcount_delete_offset10();
  }
  json_value_destruct(in_stack_00000008);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050e0cf name=FUN_0050e0cf size=25 ====

void FUN_0050e0cf(void)

{
  long unaff_R15;
  locale *unaff_retaddr;
  undefined8 in_stack_00000008;
  long in_stack_00000010;
  long in_stack_00000020;
  undefined1 *in_stack_00000050;
  
  std::locale::~locale((locale *)(in_stack_00000010 + 8));
  std::locale::~locale((locale *)(unaff_R15 + 8));
  std::locale::~locale((locale *)(in_stack_00000020 + 8));
  std::locale::~locale(unaff_retaddr);
  if (in_stack_00000050 != &DAT_011c5338) {
    refcount_delete_offset10();
  }
  json_value_destruct(in_stack_00000008);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050e0e8 name=FUN_0050e0e8 size=24 ====

void FUN_0050e0e8(void)

{
  undefined8 unaff_retaddr;
  undefined8 in_stack_00000008;
  undefined8 in_stack_00000028;
  
  json_value_destruct(unaff_retaddr);
  json_value_destruct(in_stack_00000028);
  json_value_destruct(in_stack_00000008);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050e100 name=FUN_0050e100 size=27 ====

void FUN_0050e100(void)

{
  long unaff_R13;
  long unaff_retaddr;
  undefined8 in_stack_00000008;
  locale *in_stack_00000010;
  long in_stack_00000030;
  undefined1 *in_stack_00000050;
  undefined1 *in_stack_00000058;
  
  std::locale::~locale((locale *)(unaff_retaddr + 8));
  std::locale::~locale((locale *)(unaff_R13 + 8));
  std::locale::~locale((locale *)(in_stack_00000030 + 8));
  std::locale::~locale(in_stack_00000010);
  if (in_stack_00000058 != &DAT_011c5338) {
    refcount_delete_offset10();
  }
  if (in_stack_00000050 != &DAT_011c5338) {
    refcount_delete_offset10();
  }
  json_value_destruct(in_stack_00000008);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050e11c name=FUN_0050e11c size=37 ====

void FUN_0050e11c(void)

{
  long *unaff_RBX;
  
  json_value_destruct();
  json_value_destruct();
  if (*unaff_RBX != 0) {
    FUN_009d0e26();
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050e141 name=FUN_0050e141 size=47 ====

void FUN_0050e141(void)

{
  long *unaff_RBX;
  undefined1 *in_stack_00000018;
  undefined1 *in_stack_00000050;
  
  if (in_stack_00000050 != &DAT_011c5338) {
    refcount_delete_offset10();
  }
  if (in_stack_00000018 != &DAT_011c5338) {
    refcount_delete_offset10();
  }
  if (*unaff_RBX != 0) {
    FUN_009d0e26();
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050e170 name=FUN_0050e170 size=21 ====

void FUN_0050e170(void)

{
  long *unaff_RBX;
  long unaff_R14;
  long in_stack_00000018;
  long in_stack_00000050;
  
  if (in_stack_00000050 + -0x18 != unaff_R14) {
    refcount_delete_offset10();
  }
  if (in_stack_00000018 + -0x18 != unaff_R14) {
    refcount_delete_offset10();
  }
  if (*unaff_RBX != 0) {
    FUN_009d0e26();
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050e185 name=FUN_0050e185 size=21 ====

void FUN_0050e185(void)

{
  void *unaff_R12;
  
  operator_delete(unaff_R12,0x20);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050e19a name=FUN_0050e19a size=88 ====

void FUN_0050e19a(void)

{
  undefined8 *unaff_RBX;
  undefined8 *puVar1;
  void *unaff_R12;
  
  puVar1 = unaff_RBX + 4;
  while (puVar1 != unaff_RBX) {
    puVar1 = puVar1 + -1;
    if ((undefined1 *)*puVar1 != &DAT_011c5338) {
      refcount_delete_offset10();
    }
  }
  FUN_00a0d718();
  operator_delete(unaff_R12,0x28);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050e1d3 name=FUN_0050e1d3 size=63 ====

/* WARNING: Removing unreachable block (ram,0x0050e1b6) */

void FUN_0050e1d3(void)

{
  undefined8 *unaff_RBX;
  undefined8 *puVar1;
  
  qt_byte_array_unref();
  json_value_destruct();
  puVar1 = unaff_RBX + 9;
  do {
    puVar1 = puVar1 + -1;
    if ((undefined1 *)*puVar1 != &DAT_011c5338) {
      refcount_delete_offset10();
    }
  } while (puVar1 != unaff_RBX);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050e212 name=FUN_0050e212 size=5 ====

/* WARNING: Removing unreachable block (ram,0x0050e1b6) */

void FUN_0050e212(void)

{
  undefined8 *unaff_RBX;
  undefined8 *puVar1;
  
  qt_byte_array_unref();
  json_value_destruct();
  puVar1 = unaff_RBX + 9;
  do {
    puVar1 = puVar1 + -1;
    if ((undefined1 *)*puVar1 != &DAT_011c5338) {
      refcount_delete_offset10();
    }
  } while (puVar1 != unaff_RBX);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050e236 name=FUN_0050e236 size=18 ====

/* WARNING: Removing unreachable block (ram,0x0050e1b6) */

void FUN_0050e236(void)

{
  undefined8 *unaff_RBX;
  void *unaff_R12;
  undefined8 *puVar1;
  
  operator_delete(unaff_R12,0x20);
  qt_byte_array_unref();
  json_value_destruct();
  puVar1 = unaff_RBX + 9;
  do {
    puVar1 = puVar1 + -1;
    if ((undefined1 *)*puVar1 != &DAT_011c5338) {
      refcount_delete_offset10();
    }
  } while (puVar1 != unaff_RBX);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050e248 name=FUN_0050e248 size=5 ====

/* WARNING: Removing unreachable block (ram,0x0050e1b6) */

void FUN_0050e248(void)

{
  undefined8 *unaff_RBX;
  undefined8 *puVar1;
  
  qt_byte_array_unref();
  json_value_destruct();
  puVar1 = unaff_RBX + 9;
  do {
    puVar1 = puVar1 + -1;
    if ((undefined1 *)*puVar1 != &DAT_011c5338) {
      refcount_delete_offset10();
    }
  } while (puVar1 != unaff_RBX);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050e24d name=FUN_0050e24d size=8 ====

void FUN_0050e24d(void)

{
  undefined8 *unaff_RBX;
  undefined8 *puVar1;
  void *unaff_R12;
  
  puVar1 = unaff_RBX + 8;
  while (puVar1 != unaff_RBX) {
    puVar1 = puVar1 + -1;
    if ((undefined1 *)*puVar1 != &DAT_011c5338) {
      refcount_delete_offset10();
    }
  }
  FUN_00a0d718();
  operator_delete(unaff_R12,0x28);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050e255 name=FUN_0050e255 size=10 ====

void FUN_0050e255(void)

{
  undefined8 *unaff_RBX;
  undefined8 *puVar1;
  void *unaff_R12;
  
  puVar1 = unaff_RBX + 7;
  while (puVar1 != unaff_RBX) {
    puVar1 = puVar1 + -1;
    if ((undefined1 *)*puVar1 != &DAT_011c5338) {
      refcount_delete_offset10();
    }
  }
  FUN_00a0d718();
  operator_delete(unaff_R12,0x28);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050e25f name=FUN_0050e25f size=24 ====

void FUN_0050e25f(void)

{
  undefined8 *unaff_RBX;
  void *unaff_R12;
  undefined8 *puVar1;
  
  json_value_destruct();
  json_value_destruct();
  puVar1 = unaff_RBX + 9;
  do {
    puVar1 = puVar1 + -1;
    if ((undefined1 *)*puVar1 != &DAT_011c5338) {
      refcount_delete_offset10();
    }
  } while (puVar1 != unaff_RBX);
  if (unaff_R12 != (void *)0x0) {
    FUN_00a0d718();
    operator_delete(unaff_R12,0x28);
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050e277 name=FUN_0050e277 size=46 ====

/* WARNING: Removing unreachable block (ram,0x0050e298) */

void FUN_0050e277(void)

{
  undefined8 in_RAX;
  undefined8 *unaff_RBX;
  void *unaff_R12;
  undefined8 *puVar1;
  undefined8 uStack0000000000000008;
  
  uStack0000000000000008 = in_RAX;
  json_value_destruct();
  puVar1 = unaff_RBX + 9;
  do {
    puVar1 = puVar1 + -1;
    if ((undefined1 *)*puVar1 != &DAT_011c5338) {
      refcount_delete_offset10();
    }
  } while (puVar1 != unaff_RBX);
  if (unaff_R12 != (void *)0x0) {
    FUN_00a0d718();
    operator_delete(unaff_R12,0x28);
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception(uStack0000000000000008);
}


// ==== entry=0050e2a5 name=FUN_0050e2a5 size=5 ====

/* WARNING: Removing unreachable block (ram,0x0050e298) */

void FUN_0050e2a5(void)

{
  undefined8 in_RAX;
  undefined8 *unaff_RBX;
  void *unaff_R12;
  undefined8 *puVar1;
  undefined8 uStack0000000000000008;
  
  uStack0000000000000008 = in_RAX;
  json_value_destruct();
  puVar1 = unaff_RBX + 9;
  do {
    puVar1 = puVar1 + -1;
    if ((undefined1 *)*puVar1 != &DAT_011c5338) {
      refcount_delete_offset10();
    }
  } while (puVar1 != unaff_RBX);
  if (unaff_R12 != (void *)0x0) {
    FUN_00a0d718();
    operator_delete(unaff_R12,0x28);
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception(uStack0000000000000008);
}


// ==== entry=0050e2aa name=FUN_0050e2aa size=21 ====

/* WARNING: Removing unreachable block (ram,0x0050e298) */

void FUN_0050e2aa(void)

{
  undefined8 *unaff_RBX;
  void *unaff_R12;
  undefined8 *puVar1;
  undefined8 unaff_R13;
  void *unaff_R15;
  
  operator_delete(unaff_R15,0x20);
  json_value_destruct();
  puVar1 = unaff_RBX + 9;
  do {
    puVar1 = puVar1 + -1;
    if ((undefined1 *)*puVar1 != &DAT_011c5338) {
      refcount_delete_offset10();
    }
  } while (puVar1 != unaff_RBX);
  if (unaff_R12 != (void *)0x0) {
    FUN_00a0d718();
    operator_delete(unaff_R12,0x28);
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception(unaff_R13);
}


// ==== entry=0050e2bf name=FUN_0050e2bf size=5 ====

/* WARNING: Removing unreachable block (ram,0x0050e298) */

void FUN_0050e2bf(void)

{
  undefined8 in_RAX;
  undefined8 *unaff_RBX;
  void *unaff_R12;
  undefined8 *puVar1;
  undefined8 uStack0000000000000008;
  
  uStack0000000000000008 = in_RAX;
  json_value_destruct();
  puVar1 = unaff_RBX + 9;
  do {
    puVar1 = puVar1 + -1;
    if ((undefined1 *)*puVar1 != &DAT_011c5338) {
      refcount_delete_offset10();
    }
  } while (puVar1 != unaff_RBX);
  if (unaff_R12 != (void *)0x0) {
    FUN_00a0d718();
    operator_delete(unaff_R12,0x28);
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception(uStack0000000000000008);
}


// ==== entry=0050e2c4 name=FUN_0050e2c4 size=10 ====

void FUN_0050e2c4(void)

{
  undefined8 *unaff_RBX;
  undefined8 *puVar1;
  void *unaff_R12;
  
  puVar1 = unaff_RBX + 6;
  while (puVar1 != unaff_RBX) {
    puVar1 = puVar1 + -1;
    if ((undefined1 *)*puVar1 != &DAT_011c5338) {
      refcount_delete_offset10();
    }
  }
  FUN_00a0d718();
  operator_delete(unaff_R12,0x28);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050e2ce name=FUN_0050e2ce size=34 ====

void FUN_0050e2ce(void)

{
  undefined8 in_RAX;
  undefined8 *unaff_RBX;
  void *unaff_R12;
  undefined8 *puVar1;
  undefined8 uStack0000000000000008;
  
  uStack0000000000000008 = in_RAX;
  json_value_destruct();
  json_value_destruct();
  qt_byte_array_unref();
  json_value_destruct();
  puVar1 = unaff_RBX + 9;
  do {
    puVar1 = puVar1 + -1;
    if ((undefined1 *)*puVar1 != &DAT_011c5338) {
      refcount_delete_offset10();
    }
  } while (puVar1 != unaff_RBX);
  if (unaff_R12 != (void *)0x0) {
    FUN_00a0d718();
    operator_delete(unaff_R12,0x28);
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception(uStack0000000000000008);
}


// ==== entry=0050e2f0 name=FUN_0050e2f0 size=31 ====

void FUN_0050e2f0(void)

{
  undefined8 *unaff_RBX;
  void *unaff_R12;
  undefined8 *puVar1;
  undefined8 unaff_R13;
  long unaff_R15;
  undefined1 *in_stack_00000070;
  
  if (in_stack_00000070 != &DAT_011c5338) {
    refcount_delete_offset10();
  }
  json_value_destruct();
  if (unaff_R15 != 0) {
    FUN_009d0e26();
  }
  puVar1 = unaff_RBX + 9;
  do {
    puVar1 = puVar1 + -1;
    if ((undefined1 *)*puVar1 != &DAT_011c5338) {
      refcount_delete_offset10();
    }
  } while (puVar1 != unaff_RBX);
  if (unaff_R12 != (void *)0x0) {
    FUN_00a0d718();
    operator_delete(unaff_R12,0x28);
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception(unaff_R13);
}


// ==== entry=0050e30f name=FUN_0050e30f size=10 ====

void FUN_0050e30f(void)

{
  undefined8 *unaff_RBX;
  undefined8 *puVar1;
  void *unaff_R12;
  
  puVar1 = unaff_RBX + 2;
  while (puVar1 != unaff_RBX) {
    puVar1 = puVar1 + -1;
    if ((undefined1 *)*puVar1 != &DAT_011c5338) {
      refcount_delete_offset10();
    }
  }
  FUN_00a0d718();
  operator_delete(unaff_R12,0x28);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050e319 name=FUN_0050e319 size=34 ====

void FUN_0050e319(void)

{
  undefined8 in_RAX;
  undefined8 *unaff_RBX;
  void *unaff_R12;
  undefined8 *puVar1;
  undefined8 uStack0000000000000008;
  
  uStack0000000000000008 = in_RAX;
  json_value_destruct();
  json_value_destruct();
  qt_byte_array_unref();
  json_value_destruct();
  puVar1 = unaff_RBX + 9;
  do {
    puVar1 = puVar1 + -1;
    if ((undefined1 *)*puVar1 != &DAT_011c5338) {
      refcount_delete_offset10();
    }
  } while (puVar1 != unaff_RBX);
  if (unaff_R12 != (void *)0x0) {
    FUN_00a0d718();
    operator_delete(unaff_R12,0x28);
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception(uStack0000000000000008);
}


// ==== entry=0050e33b name=FUN_0050e33b size=10 ====

void FUN_0050e33b(void)

{
  undefined8 *unaff_RBX;
  undefined8 *puVar1;
  void *unaff_R12;
  
  puVar1 = unaff_RBX;
  while (puVar1 != unaff_RBX) {
    puVar1 = puVar1 + -1;
    if ((undefined1 *)*puVar1 != &DAT_011c5338) {
      refcount_delete_offset10();
    }
  }
  FUN_00a0d718();
  operator_delete(unaff_R12,0x28);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050e345 name=FUN_0050e345 size=21 ====

void FUN_0050e345(void)

{
  void *unaff_R12;
  
  operator_delete(unaff_R12,0x28);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050e35a name=FUN_0050e35a size=10 ====

void FUN_0050e35a(void)

{
  undefined8 *unaff_RBX;
  undefined8 *puVar1;
  void *unaff_R12;
  
  puVar1 = unaff_RBX + 1;
  while (puVar1 != unaff_RBX) {
    puVar1 = puVar1 + -1;
    if ((undefined1 *)*puVar1 != &DAT_011c5338) {
      refcount_delete_offset10();
    }
  }
  FUN_00a0d718();
  operator_delete(unaff_R12,0x28);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050e364 name=FUN_0050e364 size=10 ====

void FUN_0050e364(void)

{
  undefined8 *unaff_RBX;
  undefined8 *puVar1;
  void *unaff_R12;
  
  puVar1 = unaff_RBX + 5;
  while (puVar1 != unaff_RBX) {
    puVar1 = puVar1 + -1;
    if ((undefined1 *)*puVar1 != &DAT_011c5338) {
      refcount_delete_offset10();
    }
  }
  FUN_00a0d718();
  operator_delete(unaff_R12,0x28);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050e36e name=FUN_0050e36e size=10 ====

void FUN_0050e36e(void)

{
  undefined8 *unaff_RBX;
  undefined8 *puVar1;
  void *unaff_R12;
  
  puVar1 = unaff_RBX + 3;
  while (puVar1 != unaff_RBX) {
    puVar1 = puVar1 + -1;
    if ((undefined1 *)*puVar1 != &DAT_011c5338) {
      refcount_delete_offset10();
    }
  }
  FUN_00a0d718();
  operator_delete(unaff_R12,0x28);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050e378 name=FUN_0050e378 size=31 ====

void FUN_0050e378(void)

{
  undefined8 in_stack_00000010;
  undefined8 in_stack_00000038;
  undefined1 *in_stack_00000058;
  undefined1 *in_stack_00000130;
  
  if (in_stack_00000130 != &DAT_011c5338) {
    refcount_delete_offset10();
  }
  json_value_destruct();
  if (in_stack_00000058 != &DAT_011c5338) {
    refcount_delete_offset10();
  }
  json_value_destruct(in_stack_00000038);
  json_value_destruct(in_stack_00000010);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050e397 name=FUN_0050e397 size=80 ====

void FUN_0050e397(void)

{
  long unaff_R12;
  undefined8 in_stack_00000010;
  undefined8 in_stack_00000038;
  long in_stack_00000058;
  long in_stack_00000130;
  
  if (in_stack_00000130 + -0x18 != unaff_R12) {
    refcount_delete_offset10();
  }
  json_value_destruct();
  if (in_stack_00000058 + -0x18 != unaff_R12) {
    refcount_delete_offset10();
  }
  json_value_destruct(in_stack_00000038);
  json_value_destruct(in_stack_00000010);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050e3e7 name=FUN_0050e3e7 size=24 ====

void FUN_0050e3e7(void)

{
  long unaff_R12;
  undefined8 in_stack_00000010;
  undefined8 in_stack_00000038;
  long in_stack_00000058;
  long in_stack_00000130;
  
  if (in_stack_00000130 + -0x18 != unaff_R12) {
    refcount_delete_offset10();
  }
  json_value_destruct();
  if (in_stack_00000058 + -0x18 != unaff_R12) {
    refcount_delete_offset10();
  }
  json_value_destruct(in_stack_00000038);
  json_value_destruct(in_stack_00000010);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050e3ff name=FUN_0050e3ff size=28 ====

void FUN_0050e3ff(void)

{
  undefined8 in_stack_00000010;
  undefined8 in_stack_00000038;
  undefined1 *in_stack_00000058;
  
  json_value_destruct();
  json_value_destruct();
  json_value_destruct();
  if (in_stack_00000058 != &DAT_011c5338) {
    refcount_delete_offset10();
  }
  json_value_destruct(in_stack_00000038);
  json_value_destruct(in_stack_00000010);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050e41b name=FUN_0050e41b size=10 ====

void FUN_0050e41b(void)

{
  undefined8 in_stack_00000010;
  
  json_value_destruct();
  json_value_destruct(in_stack_00000010);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050e425 name=FUN_0050e425 size=29 ====

void FUN_0050e425(void)

{
  undefined8 in_stack_00000010;
  undefined8 in_stack_00000038;
  
  json_value_destruct();
  json_value_destruct();
  json_value_destruct();
  json_value_destruct(in_stack_00000038);
  json_value_destruct(in_stack_00000010);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050e442 name=FUN_0050e442 size=38 ====

void FUN_0050e442(void)

{
  void *unaff_R14;
  undefined8 in_stack_00000010;
  undefined8 in_stack_00000038;
  undefined1 *in_stack_00000050;
  
  operator_delete(unaff_R14,0x18);
  if (in_stack_00000050 != &DAT_011c5338) {
    refcount_delete_offset10();
  }
  json_value_destruct();
  json_value_destruct(in_stack_00000038);
  json_value_destruct(in_stack_00000010);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050e468 name=FUN_0050e468 size=18 ====

void FUN_0050e468(void)

{
  void *unaff_RBX;
  undefined8 in_stack_00000010;
  
  operator_delete(unaff_RBX,0x78);
  json_value_destruct(in_stack_00000010);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050e47a name=FUN_0050e47a size=24 ====

void FUN_0050e47a(void)

{
  undefined8 in_stack_00000010;
  undefined8 in_stack_00000038;
  
  json_value_destruct();
  json_value_destruct();
  json_value_destruct(in_stack_00000038);
  json_value_destruct(in_stack_00000010);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050e492 name=FUN_0050e492 size=74 ====

/* WARNING: Removing unreachable block (ram,0x0050e4bc) */
/* WARNING: Removing unreachable block (ram,0x0050e4c5) */
/* WARNING: Removing unreachable block (ram,0x0050e4ca) */

void FUN_0050e492(void)

{
  void *unaff_R14;
  undefined8 in_stack_00000010;
  undefined8 in_stack_00000020;
  undefined8 in_stack_00000038;
  undefined1 *in_stack_00000050;
  
  operator_delete(unaff_R14,0x20);
  qt_byte_array_unref(in_stack_00000020);
  json_value_destruct();
  if (in_stack_00000050 != &DAT_011c5338) {
    refcount_delete_offset10();
  }
  json_value_destruct();
  json_value_destruct(in_stack_00000038);
  json_value_destruct(in_stack_00000010);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050e4dc name=FUN_0050e4dc size=117 ====

void FUN_0050e4dc(void)

{
  undefined8 *puVar1;
  undefined8 *unaff_RBX;
  undefined8 *puVar2;
  
  json_value_destruct();
  json_value_destruct();
  json_value_destruct();
  if ((undefined1 *)unaff_RBX[4] != &DAT_011c5338) {
    refcount_delete_offset10();
  }
  if ((undefined1 *)unaff_RBX[3] != &DAT_011c5338) {
    refcount_delete_offset10();
  }
  puVar1 = (undefined8 *)unaff_RBX[1];
  for (puVar2 = (undefined8 *)*unaff_RBX; puVar1 != puVar2; puVar2 = puVar2 + 1) {
    if ((undefined1 *)*puVar2 != &DAT_011c5338) {
      refcount_delete_offset10();
    }
  }
  if ((void *)*unaff_RBX != (void *)0x0) {
    operator_delete((void *)*unaff_RBX);
  }
  operator_delete(unaff_RBX,0x28);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050e551 name=FUN_0050e551 size=36 ====

void FUN_0050e551(void)

{
  undefined8 *puVar1;
  undefined8 *unaff_RBX;
  undefined8 *puVar2;
  undefined1 *in_stack_00000038;
  
  FUN_009e2048();
  if (in_stack_00000038 != &DAT_011c5338) {
    refcount_delete_offset10();
  }
  json_value_destruct();
  if ((undefined1 *)unaff_RBX[4] != &DAT_011c5338) {
    refcount_delete_offset10();
  }
  if ((undefined1 *)unaff_RBX[3] != &DAT_011c5338) {
    refcount_delete_offset10();
  }
  puVar1 = (undefined8 *)unaff_RBX[1];
  for (puVar2 = (undefined8 *)*unaff_RBX; puVar1 != puVar2; puVar2 = puVar2 + 1) {
    if ((undefined1 *)*puVar2 != &DAT_011c5338) {
      refcount_delete_offset10();
    }
  }
  if ((void *)*unaff_RBX != (void *)0x0) {
    operator_delete((void *)*unaff_RBX);
  }
  operator_delete(unaff_RBX,0x28);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050e575 name=FUN_0050e575 size=41 ====

void FUN_0050e575(void)

{
  undefined8 *puVar1;
  undefined8 *unaff_RBX;
  undefined8 *puVar2;
  void *unaff_R15;
  undefined1 *in_stack_00000038;
  
  operator_delete(unaff_R15);
  if (in_stack_00000038 != &DAT_011c5338) {
    refcount_delete_offset10();
  }
  json_value_destruct();
  if ((undefined1 *)unaff_RBX[4] != &DAT_011c5338) {
    refcount_delete_offset10();
  }
  if ((undefined1 *)unaff_RBX[3] != &DAT_011c5338) {
    refcount_delete_offset10();
  }
  puVar1 = (undefined8 *)unaff_RBX[1];
  for (puVar2 = (undefined8 *)*unaff_RBX; puVar1 != puVar2; puVar2 = puVar2 + 1) {
    if ((undefined1 *)*puVar2 != &DAT_011c5338) {
      refcount_delete_offset10();
    }
  }
  if ((void *)*unaff_RBX != (void *)0x0) {
    operator_delete((void *)*unaff_RBX);
  }
  operator_delete(unaff_RBX,0x28);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050e59e name=FUN_0050e59e size=24 ====

void FUN_0050e59e(void)

{
  undefined8 *puVar1;
  undefined8 *unaff_RBX;
  undefined8 *puVar2;
  
  json_value_destruct();
  json_value_destruct();
  json_value_destruct();
  if ((undefined1 *)unaff_RBX[4] != &DAT_011c5338) {
    refcount_delete_offset10();
  }
  if ((undefined1 *)unaff_RBX[3] != &DAT_011c5338) {
    refcount_delete_offset10();
  }
  puVar1 = (undefined8 *)unaff_RBX[1];
  for (puVar2 = (undefined8 *)*unaff_RBX; puVar1 != puVar2; puVar2 = puVar2 + 1) {
    if ((undefined1 *)*puVar2 != &DAT_011c5338) {
      refcount_delete_offset10();
    }
  }
  if ((void *)*unaff_RBX != (void *)0x0) {
    operator_delete((void *)*unaff_RBX);
  }
  operator_delete(unaff_RBX,0x28);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050e5b6 name=FUN_0050e5b6 size=24 ====

void FUN_0050e5b6(void)

{
  undefined8 *puVar1;
  undefined8 *unaff_RBX;
  undefined8 *puVar2;
  
  json_value_destruct();
  json_value_destruct();
  json_value_destruct();
  if ((undefined1 *)unaff_RBX[4] != &DAT_011c5338) {
    refcount_delete_offset10();
  }
  if ((undefined1 *)unaff_RBX[3] != &DAT_011c5338) {
    refcount_delete_offset10();
  }
  puVar1 = (undefined8 *)unaff_RBX[1];
  for (puVar2 = (undefined8 *)*unaff_RBX; puVar1 != puVar2; puVar2 = puVar2 + 1) {
    if ((undefined1 *)*puVar2 != &DAT_011c5338) {
      refcount_delete_offset10();
    }
  }
  if ((void *)*unaff_RBX != (void *)0x0) {
    operator_delete((void *)*unaff_RBX);
  }
  operator_delete(unaff_RBX,0x28);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050e5ce name=FUN_0050e5ce size=32 ====

void FUN_0050e5ce(void)

{
  undefined8 *puVar1;
  undefined8 *unaff_RBX;
  undefined8 *puVar2;
  undefined1 *in_stack_00000038;
  undefined1 *in_stack_00000070;
  
  if (in_stack_00000070 != &DAT_011c5338) {
    refcount_delete_offset10();
  }
  if (in_stack_00000038 != &DAT_011c5338) {
    refcount_delete_offset10();
  }
  json_value_destruct();
  if ((undefined1 *)unaff_RBX[4] != &DAT_011c5338) {
    refcount_delete_offset10();
  }
  if ((undefined1 *)unaff_RBX[3] != &DAT_011c5338) {
    refcount_delete_offset10();
  }
  puVar1 = (undefined8 *)unaff_RBX[1];
  for (puVar2 = (undefined8 *)*unaff_RBX; puVar1 != puVar2; puVar2 = puVar2 + 1) {
    if ((undefined1 *)*puVar2 != &DAT_011c5338) {
      refcount_delete_offset10();
    }
  }
  if ((void *)*unaff_RBX != (void *)0x0) {
    operator_delete((void *)*unaff_RBX);
  }
  operator_delete(unaff_RBX,0x28);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050e5ee name=FUN_0050e5ee size=35 ====

void FUN_0050e5ee(void)

{
  undefined8 *puVar1;
  undefined8 *unaff_RBX;
  undefined8 *puVar2;
  undefined1 *in_stack_000000a0;
  
  if (in_stack_000000a0 != &DAT_011c5338) {
    refcount_delete_offset10();
  }
  json_value_destruct();
  if ((undefined1 *)unaff_RBX[4] != &DAT_011c5338) {
    refcount_delete_offset10();
  }
  if ((undefined1 *)unaff_RBX[3] != &DAT_011c5338) {
    refcount_delete_offset10();
  }
  puVar1 = (undefined8 *)unaff_RBX[1];
  for (puVar2 = (undefined8 *)*unaff_RBX; puVar1 != puVar2; puVar2 = puVar2 + 1) {
    if ((undefined1 *)*puVar2 != &DAT_011c5338) {
      refcount_delete_offset10();
    }
  }
  if ((void *)*unaff_RBX != (void *)0x0) {
    operator_delete((void *)*unaff_RBX);
  }
  operator_delete(unaff_RBX,0x28);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050e611 name=FUN_0050e611 size=24 ====

void FUN_0050e611(void)

{
  json_value_destruct();
  json_value_destruct();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050e629 name=FUN_0050e629 size=31 ====

void FUN_0050e629(void)

{
  undefined1 *in_stack_00000040;
  
  if (in_stack_00000040 != &DAT_011c5338) {
    refcount_delete_offset10();
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050e648 name=FUN_0050e648 size=156 ====

/* WARNING: Removing unreachable block (ram,0x0050e700) */
/* WARNING: Removing unreachable block (ram,0x0050e709) */
/* WARNING: Removing unreachable block (ram,0x0050e70e) */
/* WARNING: Removing unreachable block (ram,0x0050e71d) */
/* WARNING: Removing unreachable block (ram,0x0050e722) */
/* WARNING: Removing unreachable block (ram,0x0050e72b) */
/* WARNING: Removing unreachable block (ram,0x0050e730) */

void FUN_0050e648(void)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  long in_stack_00000010;
  undefined8 in_stack_00000020;
  undefined8 in_stack_00000028;
  undefined8 in_stack_00000068;
  undefined8 in_stack_00000070;
  undefined8 in_stack_00000080;
  long in_stack_00000098;
  long in_stack_00000258;
  void *in_stack_00000278;
  
  qt_byte_array_unref();
  json_value_destruct();
  json_value_destruct(in_stack_00000020);
  json_value_destruct(in_stack_00000028);
  if (in_stack_00000098 + -0x18 != in_stack_00000010) {
    refcount_delete_offset10();
  }
  json_value_destruct(in_stack_00000068);
  json_value_destruct(in_stack_00000070);
  if (in_stack_00000278 != (void *)0x0) {
    puVar2 = *(undefined8 **)((long)in_stack_00000278 + in_stack_00000258 * 8);
    while (puVar2 != (undefined8 *)0x0) {
      puVar1 = (undefined8 *)*puVar2;
      if ((undefined1 *)puVar2[2] != &DAT_011c5338) {
        refcount_delete_offset10();
      }
      operator_delete(puVar2);
      puVar2 = puVar1;
    }
    operator_delete(in_stack_00000278);
  }
  json_value_destruct(in_stack_00000080);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050e6e4 name=FUN_0050e6e4 size=94 ====

void FUN_0050e6e4(void)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  void *unaff_R13;
  undefined8 in_stack_00000068;
  undefined8 in_stack_00000070;
  undefined8 in_stack_00000080;
  long in_stack_00000258;
  void *in_stack_00000278;
  
  json_value_destruct();
  json_value_destruct();
  if (*(void **)((long)unaff_R13 + 0x20) != (void *)0x0) {
    operator_delete(*(void **)((long)unaff_R13 + 0x20));
  }
  if (*(undefined1 **)((long)unaff_R13 + 0x18) != &DAT_011c5338) {
    refcount_delete_offset10();
  }
  if (*(_Sp_counted_base<(__gnu_cxx::_Lock_policy)2> **)((long)unaff_R13 + 0x10) !=
      (_Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *)0x0) {
    std::_Sp_counted_base<(__gnu_cxx::_Lock_policy)2>::_M_release
              (*(_Sp_counted_base<(__gnu_cxx::_Lock_policy)2> **)((long)unaff_R13 + 0x10));
  }
  operator_delete(unaff_R13,0x38);
  json_value_destruct(in_stack_00000068);
  json_value_destruct(in_stack_00000070);
  if (in_stack_00000278 != (void *)0x0) {
    puVar2 = *(undefined8 **)((long)in_stack_00000278 + in_stack_00000258 * 8);
    while (puVar2 != (undefined8 *)0x0) {
      puVar1 = (undefined8 *)*puVar2;
      if ((undefined1 *)puVar2[2] != &DAT_011c5338) {
        refcount_delete_offset10();
      }
      operator_delete(puVar2);
      puVar2 = puVar1;
    }
    operator_delete(in_stack_00000278);
  }
  json_value_destruct(in_stack_00000080);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050e742 name=FUN_0050e742 size=21 ====

void FUN_0050e742(void)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  void *unaff_R13;
  long in_stack_00000010;
  undefined8 in_stack_00000020;
  undefined8 in_stack_00000028;
  undefined8 in_stack_00000068;
  undefined8 in_stack_00000070;
  undefined8 in_stack_00000080;
  long in_stack_00000098;
  long in_stack_00000258;
  void *in_stack_00000278;
  
  json_value_destruct();
  json_value_destruct();
  json_value_destruct(in_stack_00000020);
  json_value_destruct(in_stack_00000028);
  if (in_stack_00000098 + -0x18 != in_stack_00000010) {
    refcount_delete_offset10();
  }
  if (unaff_R13 != (void *)0x0) {
    if (*(void **)((long)unaff_R13 + 0x20) != (void *)0x0) {
      operator_delete(*(void **)((long)unaff_R13 + 0x20));
    }
    if (*(long *)((long)unaff_R13 + 0x18) + -0x18 != in_stack_00000010) {
      refcount_delete_offset10();
    }
    if (*(_Sp_counted_base<(__gnu_cxx::_Lock_policy)2> **)((long)unaff_R13 + 0x10) !=
        (_Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *)0x0) {
      std::_Sp_counted_base<(__gnu_cxx::_Lock_policy)2>::_M_release
                (*(_Sp_counted_base<(__gnu_cxx::_Lock_policy)2> **)((long)unaff_R13 + 0x10));
    }
    operator_delete(unaff_R13,0x38);
  }
  json_value_destruct(in_stack_00000068);
  json_value_destruct(in_stack_00000070);
  if (in_stack_00000278 != (void *)0x0) {
    puVar2 = *(undefined8 **)((long)in_stack_00000278 + in_stack_00000258 * 8);
    while (puVar2 != (undefined8 *)0x0) {
      puVar1 = (undefined8 *)*puVar2;
      if ((undefined1 *)puVar2[2] != &DAT_011c5338) {
        refcount_delete_offset10();
      }
      operator_delete(puVar2);
      puVar2 = puVar1;
    }
    operator_delete(in_stack_00000278);
  }
  json_value_destruct(in_stack_00000080);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050e757 name=FUN_0050e757 size=46 ====

void FUN_0050e757(void)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  void *unaff_R13;
  void *unaff_R14;
  long in_stack_00000010;
  undefined8 in_stack_00000020;
  undefined8 in_stack_00000028;
  undefined8 in_stack_00000068;
  undefined8 in_stack_00000070;
  undefined8 in_stack_00000080;
  long in_stack_00000098;
  long in_stack_000000a8;
  long in_stack_00000258;
  void *in_stack_00000278;
  
  operator_delete(unaff_R14,0x18);
  if (in_stack_000000a8 + -0x18 != in_stack_00000010) {
    refcount_delete_offset10();
  }
  json_value_destruct(in_stack_00000020);
  json_value_destruct(in_stack_00000028);
  if (in_stack_00000098 + -0x18 != in_stack_00000010) {
    refcount_delete_offset10();
  }
  if (unaff_R13 != (void *)0x0) {
    if (*(void **)((long)unaff_R13 + 0x20) != (void *)0x0) {
      operator_delete(*(void **)((long)unaff_R13 + 0x20));
    }
    if (*(long *)((long)unaff_R13 + 0x18) + -0x18 != in_stack_00000010) {
      refcount_delete_offset10();
    }
    if (*(_Sp_counted_base<(__gnu_cxx::_Lock_policy)2> **)((long)unaff_R13 + 0x10) !=
        (_Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *)0x0) {
      std::_Sp_counted_base<(__gnu_cxx::_Lock_policy)2>::_M_release
                (*(_Sp_counted_base<(__gnu_cxx::_Lock_policy)2> **)((long)unaff_R13 + 0x10));
    }
    operator_delete(unaff_R13,0x38);
  }
  json_value_destruct(in_stack_00000068);
  json_value_destruct(in_stack_00000070);
  if (in_stack_00000278 != (void *)0x0) {
    puVar2 = *(undefined8 **)((long)in_stack_00000278 + in_stack_00000258 * 8);
    while (puVar2 != (undefined8 *)0x0) {
      puVar1 = (undefined8 *)*puVar2;
      if ((undefined1 *)puVar2[2] != &DAT_011c5338) {
        refcount_delete_offset10();
      }
      operator_delete(puVar2);
      puVar2 = puVar1;
    }
    operator_delete(in_stack_00000278);
  }
  json_value_destruct(in_stack_00000080);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050e785 name=FUN_0050e785 size=71 ====

/* WARNING: Removing unreachable block (ram,0x0050e7af) */
/* WARNING: Removing unreachable block (ram,0x0050e7b8) */
/* WARNING: Removing unreachable block (ram,0x0050e7bd) */

void FUN_0050e785(void)

{
  undefined8 *puVar1;
  void *unaff_RBX;
  undefined8 *puVar2;
  void *unaff_R13;
  long in_stack_00000010;
  undefined8 in_stack_00000020;
  undefined8 in_stack_00000028;
  undefined8 in_stack_00000058;
  undefined8 in_stack_00000068;
  undefined8 in_stack_00000070;
  undefined8 in_stack_00000080;
  long in_stack_00000098;
  long in_stack_000000a8;
  long in_stack_00000258;
  void *in_stack_00000278;
  
  operator_delete(unaff_RBX,0x20);
  qt_byte_array_unref(in_stack_00000058);
  json_value_destruct();
  if (in_stack_000000a8 + -0x18 != in_stack_00000010) {
    refcount_delete_offset10();
  }
  json_value_destruct(in_stack_00000020);
  json_value_destruct(in_stack_00000028);
  if (in_stack_00000098 + -0x18 != in_stack_00000010) {
    refcount_delete_offset10();
  }
  if (unaff_R13 != (void *)0x0) {
    if (*(void **)((long)unaff_R13 + 0x20) != (void *)0x0) {
      operator_delete(*(void **)((long)unaff_R13 + 0x20));
    }
    if (*(long *)((long)unaff_R13 + 0x18) + -0x18 != in_stack_00000010) {
      refcount_delete_offset10();
    }
    if (*(_Sp_counted_base<(__gnu_cxx::_Lock_policy)2> **)((long)unaff_R13 + 0x10) !=
        (_Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *)0x0) {
      std::_Sp_counted_base<(__gnu_cxx::_Lock_policy)2>::_M_release
                (*(_Sp_counted_base<(__gnu_cxx::_Lock_policy)2> **)((long)unaff_R13 + 0x10));
    }
    operator_delete(unaff_R13,0x38);
  }
  json_value_destruct(in_stack_00000068);
  json_value_destruct(in_stack_00000070);
  if (in_stack_00000278 != (void *)0x0) {
    puVar2 = *(undefined8 **)((long)in_stack_00000278 + in_stack_00000258 * 8);
    while (puVar2 != (undefined8 *)0x0) {
      puVar1 = (undefined8 *)*puVar2;
      if ((undefined1 *)puVar2[2] != &DAT_011c5338) {
        refcount_delete_offset10();
      }
      operator_delete(puVar2);
      puVar2 = puVar1;
    }
    operator_delete(in_stack_00000278);
  }
  json_value_destruct(in_stack_00000080);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050e7cc name=FUN_0050e7cc size=21 ====

void FUN_0050e7cc(void)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  void *unaff_R13;
  long in_stack_00000010;
  undefined8 in_stack_00000020;
  undefined8 in_stack_00000028;
  undefined8 in_stack_00000068;
  undefined8 in_stack_00000070;
  undefined8 in_stack_00000080;
  long in_stack_00000098;
  long in_stack_00000258;
  void *in_stack_00000278;
  
  json_value_destruct();
  json_value_destruct();
  qt_byte_array_unref();
  json_value_destruct();
  json_value_destruct(in_stack_00000020);
  json_value_destruct(in_stack_00000028);
  if (in_stack_00000098 + -0x18 != in_stack_00000010) {
    refcount_delete_offset10();
  }
  if (unaff_R13 != (void *)0x0) {
    if (*(void **)((long)unaff_R13 + 0x20) != (void *)0x0) {
      operator_delete(*(void **)((long)unaff_R13 + 0x20));
    }
    if (*(long *)((long)unaff_R13 + 0x18) + -0x18 != in_stack_00000010) {
      refcount_delete_offset10();
    }
    if (*(_Sp_counted_base<(__gnu_cxx::_Lock_policy)2> **)((long)unaff_R13 + 0x10) !=
        (_Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *)0x0) {
      std::_Sp_counted_base<(__gnu_cxx::_Lock_policy)2>::_M_release
                (*(_Sp_counted_base<(__gnu_cxx::_Lock_policy)2> **)((long)unaff_R13 + 0x10));
    }
    operator_delete(unaff_R13,0x38);
  }
  json_value_destruct(in_stack_00000068);
  json_value_destruct(in_stack_00000070);
  if (in_stack_00000278 != (void *)0x0) {
    puVar2 = *(undefined8 **)((long)in_stack_00000278 + in_stack_00000258 * 8);
    while (puVar2 != (undefined8 *)0x0) {
      puVar1 = (undefined8 *)*puVar2;
      if ((undefined1 *)puVar2[2] != &DAT_011c5338) {
        refcount_delete_offset10();
      }
      operator_delete(puVar2);
      puVar2 = puVar1;
    }
    operator_delete(in_stack_00000278);
  }
  json_value_destruct(in_stack_00000080);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050e7e1 name=FUN_0050e7e1 size=21 ====

void FUN_0050e7e1(void)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  void *unaff_R13;
  long in_stack_00000010;
  undefined8 in_stack_00000020;
  undefined8 in_stack_00000028;
  undefined8 in_stack_00000068;
  undefined8 in_stack_00000070;
  undefined8 in_stack_00000080;
  long in_stack_00000098;
  long in_stack_00000258;
  void *in_stack_00000278;
  
  json_value_destruct();
  json_value_destruct();
  qt_byte_array_unref();
  json_value_destruct();
  json_value_destruct(in_stack_00000020);
  json_value_destruct(in_stack_00000028);
  if (in_stack_00000098 + -0x18 != in_stack_00000010) {
    refcount_delete_offset10();
  }
  if (unaff_R13 != (void *)0x0) {
    if (*(void **)((long)unaff_R13 + 0x20) != (void *)0x0) {
      operator_delete(*(void **)((long)unaff_R13 + 0x20));
    }
    if (*(long *)((long)unaff_R13 + 0x18) + -0x18 != in_stack_00000010) {
      refcount_delete_offset10();
    }
    if (*(_Sp_counted_base<(__gnu_cxx::_Lock_policy)2> **)((long)unaff_R13 + 0x10) !=
        (_Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *)0x0) {
      std::_Sp_counted_base<(__gnu_cxx::_Lock_policy)2>::_M_release
                (*(_Sp_counted_base<(__gnu_cxx::_Lock_policy)2> **)((long)unaff_R13 + 0x10));
    }
    operator_delete(unaff_R13,0x38);
  }
  json_value_destruct(in_stack_00000068);
  json_value_destruct(in_stack_00000070);
  if (in_stack_00000278 != (void *)0x0) {
    puVar2 = *(undefined8 **)((long)in_stack_00000278 + in_stack_00000258 * 8);
    while (puVar2 != (undefined8 *)0x0) {
      puVar1 = (undefined8 *)*puVar2;
      if ((undefined1 *)puVar2[2] != &DAT_011c5338) {
        refcount_delete_offset10();
      }
      operator_delete(puVar2);
      puVar2 = puVar1;
    }
    operator_delete(in_stack_00000278);
  }
  json_value_destruct(in_stack_00000080);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050e7f6 name=FUN_0050e7f6 size=18 ====

void FUN_0050e7f6(void)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  void *unaff_R13;
  undefined8 in_stack_00000068;
  undefined8 in_stack_00000070;
  undefined8 in_stack_00000080;
  long in_stack_00000258;
  void *in_stack_00000278;
  
  operator_delete(unaff_R13,0x38);
  json_value_destruct(in_stack_00000068);
  json_value_destruct(in_stack_00000070);
  if (in_stack_00000278 != (void *)0x0) {
    puVar2 = *(undefined8 **)((long)in_stack_00000278 + in_stack_00000258 * 8);
    while (puVar2 != (undefined8 *)0x0) {
      puVar1 = (undefined8 *)*puVar2;
      if ((undefined1 *)puVar2[2] != &DAT_011c5338) {
        refcount_delete_offset10();
      }
      operator_delete(puVar2);
      puVar2 = puVar1;
    }
    operator_delete(in_stack_00000278);
  }
  json_value_destruct(in_stack_00000080);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050e808 name=FUN_0050e808 size=17 ====

void FUN_0050e808(void)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  void *unaff_R13;
  undefined8 *puStack0000000000000010;
  undefined8 in_stack_00000068;
  undefined8 in_stack_00000070;
  undefined8 in_stack_00000080;
  long in_stack_00000258;
  void *in_stack_00000278;
  
  puStack0000000000000010 = &std::string::_Rep::_S_empty_rep_storage;
  if (*(void **)((long)unaff_R13 + 0x20) != (void *)0x0) {
    operator_delete(*(void **)((long)unaff_R13 + 0x20));
  }
  if ((undefined8 *)(*(long *)((long)unaff_R13 + 0x18) + -0x18) != puStack0000000000000010) {
    refcount_delete_offset10();
  }
  if (*(_Sp_counted_base<(__gnu_cxx::_Lock_policy)2> **)((long)unaff_R13 + 0x10) !=
      (_Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *)0x0) {
    std::_Sp_counted_base<(__gnu_cxx::_Lock_policy)2>::_M_release
              (*(_Sp_counted_base<(__gnu_cxx::_Lock_policy)2> **)((long)unaff_R13 + 0x10));
  }
  operator_delete(unaff_R13,0x38);
  json_value_destruct(in_stack_00000068);
  json_value_destruct(in_stack_00000070);
  if (in_stack_00000278 != (void *)0x0) {
    puVar2 = *(undefined8 **)((long)in_stack_00000278 + in_stack_00000258 * 8);
    while (puVar2 != (undefined8 *)0x0) {
      puVar1 = (undefined8 *)*puVar2;
      if ((undefined1 *)puVar2[2] != &DAT_011c5338) {
        refcount_delete_offset10();
      }
      operator_delete(puVar2);
      puVar2 = puVar1;
    }
    operator_delete(in_stack_00000278);
  }
  json_value_destruct(in_stack_00000080);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050e819 name=FUN_0050e819 size=21 ====

void FUN_0050e819(void)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  void *unaff_R13;
  long in_stack_00000010;
  undefined8 in_stack_00000020;
  undefined8 in_stack_00000028;
  undefined8 in_stack_00000068;
  undefined8 in_stack_00000070;
  undefined8 in_stack_00000080;
  long in_stack_00000098;
  long in_stack_00000258;
  void *in_stack_00000278;
  
  json_value_destruct();
  json_value_destruct();
  qt_byte_array_unref();
  json_value_destruct();
  json_value_destruct(in_stack_00000020);
  json_value_destruct(in_stack_00000028);
  if (in_stack_00000098 + -0x18 != in_stack_00000010) {
    refcount_delete_offset10();
  }
  if (unaff_R13 != (void *)0x0) {
    if (*(void **)((long)unaff_R13 + 0x20) != (void *)0x0) {
      operator_delete(*(void **)((long)unaff_R13 + 0x20));
    }
    if (*(long *)((long)unaff_R13 + 0x18) + -0x18 != in_stack_00000010) {
      refcount_delete_offset10();
    }
    if (*(_Sp_counted_base<(__gnu_cxx::_Lock_policy)2> **)((long)unaff_R13 + 0x10) !=
        (_Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *)0x0) {
      std::_Sp_counted_base<(__gnu_cxx::_Lock_policy)2>::_M_release
                (*(_Sp_counted_base<(__gnu_cxx::_Lock_policy)2> **)((long)unaff_R13 + 0x10));
    }
    operator_delete(unaff_R13,0x38);
  }
  json_value_destruct(in_stack_00000068);
  json_value_destruct(in_stack_00000070);
  if (in_stack_00000278 != (void *)0x0) {
    puVar2 = *(undefined8 **)((long)in_stack_00000278 + in_stack_00000258 * 8);
    while (puVar2 != (undefined8 *)0x0) {
      puVar1 = (undefined8 *)*puVar2;
      if ((undefined1 *)puVar2[2] != &DAT_011c5338) {
        refcount_delete_offset10();
      }
      operator_delete(puVar2);
      puVar2 = puVar1;
    }
    operator_delete(in_stack_00000278);
  }
  json_value_destruct(in_stack_00000080);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050e82e name=FUN_0050e82e size=24 ====

/* WARNING: Removing unreachable block (ram,0x0050e700) */
/* WARNING: Removing unreachable block (ram,0x0050e709) */
/* WARNING: Removing unreachable block (ram,0x0050e70e) */
/* WARNING: Removing unreachable block (ram,0x0050e71d) */
/* WARNING: Removing unreachable block (ram,0x0050e722) */
/* WARNING: Removing unreachable block (ram,0x0050e72b) */
/* WARNING: Removing unreachable block (ram,0x0050e730) */

void FUN_0050e82e(void)

{
  undefined8 *puVar1;
  void *unaff_RBX;
  undefined8 *puVar2;
  long in_stack_00000010;
  undefined8 in_stack_00000020;
  undefined8 in_stack_00000028;
  undefined8 in_stack_00000068;
  undefined8 in_stack_00000070;
  undefined8 in_stack_00000080;
  long in_stack_00000098;
  long in_stack_00000258;
  void *in_stack_00000278;
  
  operator_delete(unaff_RBX,0x20);
  qt_byte_array_unref();
  json_value_destruct();
  json_value_destruct(in_stack_00000020);
  json_value_destruct(in_stack_00000028);
  if (in_stack_00000098 + -0x18 != in_stack_00000010) {
    refcount_delete_offset10();
  }
  json_value_destruct(in_stack_00000068);
  json_value_destruct(in_stack_00000070);
  if (in_stack_00000278 != (void *)0x0) {
    puVar2 = *(undefined8 **)((long)in_stack_00000278 + in_stack_00000258 * 8);
    while (puVar2 != (undefined8 *)0x0) {
      puVar1 = (undefined8 *)*puVar2;
      if ((undefined1 *)puVar2[2] != &DAT_011c5338) {
        refcount_delete_offset10();
      }
      operator_delete(puVar2);
      puVar2 = puVar1;
    }
    operator_delete(in_stack_00000278);
  }
  json_value_destruct(in_stack_00000080);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050e846 name=FUN_0050e846 size=8 ====

/* WARNING: Removing unreachable block (ram,0x0050e700) */
/* WARNING: Removing unreachable block (ram,0x0050e709) */
/* WARNING: Removing unreachable block (ram,0x0050e70e) */
/* WARNING: Removing unreachable block (ram,0x0050e71d) */
/* WARNING: Removing unreachable block (ram,0x0050e722) */
/* WARNING: Removing unreachable block (ram,0x0050e72b) */
/* WARNING: Removing unreachable block (ram,0x0050e730) */

void FUN_0050e846(void)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  long in_stack_00000010;
  undefined8 in_stack_00000020;
  undefined8 in_stack_00000028;
  undefined8 in_stack_00000068;
  undefined8 in_stack_00000070;
  undefined8 in_stack_00000080;
  long in_stack_00000098;
  long in_stack_00000258;
  void *in_stack_00000278;
  
  qt_byte_array_unref();
  json_value_destruct();
  json_value_destruct(in_stack_00000020);
  json_value_destruct(in_stack_00000028);
  if (in_stack_00000098 + -0x18 != in_stack_00000010) {
    refcount_delete_offset10();
  }
  json_value_destruct(in_stack_00000068);
  json_value_destruct(in_stack_00000070);
  if (in_stack_00000278 != (void *)0x0) {
    puVar2 = *(undefined8 **)((long)in_stack_00000278 + in_stack_00000258 * 8);
    while (puVar2 != (undefined8 *)0x0) {
      puVar1 = (undefined8 *)*puVar2;
      if ((undefined1 *)puVar2[2] != &DAT_011c5338) {
        refcount_delete_offset10();
      }
      operator_delete(puVar2);
      puVar2 = puVar1;
    }
    operator_delete(in_stack_00000278);
  }
  json_value_destruct(in_stack_00000080);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050e84e name=FUN_0050e84e size=21 ====

void FUN_0050e84e(void)

{
  void *unaff_RBX;
  undefined8 in_stack_00000080;
  
  operator_delete(unaff_RBX,0x78);
  json_value_destruct(in_stack_00000080);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050e863 name=FUN_0050e863 size=50 ====

/* WARNING: Removing unreachable block (ram,0x0050e700) */
/* WARNING: Removing unreachable block (ram,0x0050e709) */
/* WARNING: Removing unreachable block (ram,0x0050e70e) */
/* WARNING: Removing unreachable block (ram,0x0050e71d) */
/* WARNING: Removing unreachable block (ram,0x0050e722) */
/* WARNING: Removing unreachable block (ram,0x0050e72b) */
/* WARNING: Removing unreachable block (ram,0x0050e730) */

void FUN_0050e863(void)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  long in_stack_00000010;
  undefined8 in_stack_00000020;
  undefined8 in_stack_00000028;
  undefined8 in_stack_00000068;
  undefined8 in_stack_00000070;
  undefined8 in_stack_00000080;
  long in_stack_00000098;
  long in_stack_00000258;
  void *in_stack_00000278;
  
  qt_byte_array_unref();
  json_value_destruct();
  json_value_destruct(in_stack_00000020);
  json_value_destruct(in_stack_00000028);
  if (in_stack_00000098 + -0x18 != in_stack_00000010) {
    refcount_delete_offset10();
  }
  json_value_destruct(in_stack_00000068);
  json_value_destruct(in_stack_00000070);
  if (in_stack_00000278 != (void *)0x0) {
    puVar2 = *(undefined8 **)((long)in_stack_00000278 + in_stack_00000258 * 8);
    while (puVar2 != (undefined8 *)0x0) {
      puVar1 = (undefined8 *)*puVar2;
      if ((undefined1 *)puVar2[2] != &DAT_011c5338) {
        refcount_delete_offset10();
      }
      operator_delete(puVar2);
      puVar2 = puVar1;
    }
    operator_delete(in_stack_00000278);
  }
  json_value_destruct(in_stack_00000080);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050e896 name=FUN_0050e896 size=79 ====

void FUN_0050e896(void)

{
  undefined8 in_stack_00000020;
  _Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *in_stack_000000d8;
  _Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *in_stack_00000108;
  
                    /* catch() { ... } // from try @ 0050e91e with catch @ 0050e897 */
  FUN_007836c0();
  if (in_stack_00000108 != (_Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *)0x0) {
    std::_Sp_counted_base<(__gnu_cxx::_Lock_policy)2>::_M_release(in_stack_00000108);
  }
  if (in_stack_000000d8 != (_Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *)0x0) {
    std::_Sp_counted_base<(__gnu_cxx::_Lock_policy)2>::_M_release(in_stack_000000d8);
  }
  refcounted_pair_release(in_stack_00000020);
  refcounted_pair_release();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050e8e5 name=FUN_0050e8e5 size=25 ====

void FUN_0050e8e5(void)

{
  undefined8 in_stack_00000020;
  undefined1 *in_stack_00000048;
  _Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *in_stack_000000d8;
  _Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *in_stack_00000108;
  
  if (in_stack_00000048 != &DAT_011c5338) {
    refcount_delete_offset10();
  }
  FUN_007836c0();
  if (in_stack_00000108 != (_Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *)0x0) {
    std::_Sp_counted_base<(__gnu_cxx::_Lock_policy)2>::_M_release(in_stack_00000108);
  }
  if (in_stack_000000d8 != (_Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *)0x0) {
    std::_Sp_counted_base<(__gnu_cxx::_Lock_policy)2>::_M_release(in_stack_000000d8);
  }
  refcounted_pair_release(in_stack_00000020);
  refcounted_pair_release();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050e8fe name=FUN_0050e8fe size=15 ====

void FUN_0050e8fe(void)

{
  void *unaff_RBP;
  
  operator_delete(unaff_RBP,8);
  refcounted_pair_release();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050e90d name=FUN_0050e90d size=22 ====

void FUN_0050e90d(void)

{
                    /* WARNING: Subroutine does not return */
                    /* try { // try from 0050e91e to 0050e922 has its CatchHandler @ 0050e897 */
  __cxa_throw();
}


// ==== entry=0050e923 name=FUN_0050e923 size=16 ====

void FUN_0050e923(void)

{
  undefined8 in_stack_00000020;
  _Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *in_stack_000000d8;
  _Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *in_stack_00000108;
  
  qt_array_data_unref();
  FUN_007836c0();
  if (in_stack_00000108 != (_Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *)0x0) {
    std::_Sp_counted_base<(__gnu_cxx::_Lock_policy)2>::_M_release(in_stack_00000108);
  }
  if (in_stack_000000d8 != (_Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *)0x0) {
    std::_Sp_counted_base<(__gnu_cxx::_Lock_policy)2>::_M_release(in_stack_000000d8);
  }
  refcounted_pair_release(in_stack_00000020);
  refcounted_pair_release();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050e933 name=FUN_0050e933 size=13 ====

void FUN_0050e933(void)

{
  undefined8 in_stack_00000020;
  _Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *in_stack_000000d8;
  _Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *in_stack_00000108;
  
  __cxa_free_exception();
  FUN_007836c0();
  if (in_stack_00000108 != (_Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *)0x0) {
    std::_Sp_counted_base<(__gnu_cxx::_Lock_policy)2>::_M_release(in_stack_00000108);
  }
  if (in_stack_000000d8 != (_Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *)0x0) {
    std::_Sp_counted_base<(__gnu_cxx::_Lock_policy)2>::_M_release(in_stack_000000d8);
  }
  refcounted_pair_release(in_stack_00000020);
  refcounted_pair_release();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050e940 name=FUN_0050e940 size=22 ====

void FUN_0050e940(void)

{
                    /* WARNING: Subroutine does not return */
                    /* try { // try from 0050e951 to 0050e955 has its CatchHandler @ 0050e9a2 */
  __cxa_throw();
}


// ==== entry=0050e956 name=FUN_0050e956 size=76 ====

void FUN_0050e956(void)

{
  undefined8 in_stack_00000018;
  _Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *in_stack_000000e8;
  _Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *in_stack_00000118;
  
                    /* catch() { ... } // from try @ 0050ea03 with catch @ 0050e956 */
  FUN_007836c0();
  if (in_stack_00000118 != (_Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *)0x0) {
    std::_Sp_counted_base<(__gnu_cxx::_Lock_policy)2>::_M_release(in_stack_00000118);
  }
  if (in_stack_000000e8 != (_Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *)0x0) {
    std::_Sp_counted_base<(__gnu_cxx::_Lock_policy)2>::_M_release(in_stack_000000e8);
  }
  refcounted_pair_release(in_stack_00000018);
  refcounted_pair_release();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050e9a2 name=FUN_0050e9a2 size=5 ====

void FUN_0050e9a2(void)

{
                    /* catch() { ... } // from try @ 0050e951 with catch @ 0050e9a2 */
  refcounted_pair_release();
  refcounted_pair_release();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050e9a7 name=FUN_0050e9a7 size=21 ====

void FUN_0050e9a7(void)

{
  __cxa_free_exception();
  refcounted_pair_release();
  refcounted_pair_release();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050e9bc name=FUN_0050e9bc size=39 ====

void FUN_0050e9bc(void)

{
  undefined8 in_stack_00000018;
  undefined1 *in_stack_00000050;
  _Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *in_stack_000000e8;
  _Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *in_stack_00000118;
  
  qt_array_data_unref();
  if (in_stack_00000050 != &DAT_011c5338) {
    refcount_delete_offset10();
  }
  FUN_007836c0();
  if (in_stack_00000118 != (_Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *)0x0) {
    std::_Sp_counted_base<(__gnu_cxx::_Lock_policy)2>::_M_release(in_stack_00000118);
  }
  if (in_stack_000000e8 != (_Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *)0x0) {
    std::_Sp_counted_base<(__gnu_cxx::_Lock_policy)2>::_M_release(in_stack_000000e8);
  }
  refcounted_pair_release(in_stack_00000018);
  refcounted_pair_release();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050e9e3 name=FUN_0050e9e3 size=15 ====

void FUN_0050e9e3(void)

{
  void *unaff_RBP;
  
  operator_delete(unaff_RBP,0x18);
  refcounted_pair_release();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050e9f2 name=FUN_0050e9f2 size=22 ====

void FUN_0050e9f2(void)

{
                    /* WARNING: Subroutine does not return */
                    /* try { // try from 0050ea03 to 0050ea07 has its CatchHandler @ 0050e956 */
  __cxa_throw();
}


// ==== entry=0050ea08 name=FUN_0050ea08 size=13 ====

void FUN_0050ea08(void)

{
  undefined8 in_stack_00000018;
  _Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *in_stack_000000e8;
  _Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *in_stack_00000118;
  
  __cxa_free_exception();
  FUN_007836c0();
  if (in_stack_00000118 != (_Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *)0x0) {
    std::_Sp_counted_base<(__gnu_cxx::_Lock_policy)2>::_M_release(in_stack_00000118);
  }
  if (in_stack_000000e8 != (_Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *)0x0) {
    std::_Sp_counted_base<(__gnu_cxx::_Lock_policy)2>::_M_release(in_stack_000000e8);
  }
  refcounted_pair_release(in_stack_00000018);
  refcounted_pair_release();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050ea15 name=FUN_0050ea15 size=42 ====

void FUN_0050ea15(void)

{
  undefined8 in_stack_00000018;
  undefined1 *in_stack_00000058;
  
  qt_array_data_unref(in_stack_00000018);
  if (in_stack_00000058 != &DAT_011c5338) {
    refcount_delete_offset10();
  }
  refcounted_pair_release();
  refcounted_pair_release();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050ea40 name=FUN_0050ea40 size=24 ====

void FUN_0050ea40(void)

{
  json_value_destruct();
  json_value_destruct();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050ea58 name=FUN_0050ea58 size=67 ====

void FUN_0050ea58(void)

{
  long unaff_RBP;
  long in_stack_00000040;
  long in_stack_00000048;
  
  FUN_009a3690();
  FUN_009a3640(&stack0x00000050);
  if (in_stack_00000048 + -0x18 != unaff_RBP) {
    refcount_delete_offset10();
  }
  if (in_stack_00000040 + -0x18 != unaff_RBP) {
    refcount_delete_offset10();
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050ea9b name=FUN_0050ea9b size=28 ====

void FUN_0050ea9b(void)

{
  undefined1 *in_stack_00000040;
  undefined1 *in_stack_00000048;
  undefined1 *in_stack_00000050;
  
  if (in_stack_00000050 != &DAT_011c5338) {
    refcount_delete_offset10();
  }
  if (in_stack_00000048 != &DAT_011c5338) {
    refcount_delete_offset10();
  }
  if (in_stack_00000040 != &DAT_011c5338) {
    refcount_delete_offset10();
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050eab7 name=FUN_0050eab7 size=28 ====

void FUN_0050eab7(void)

{
  undefined1 *in_stack_00000040;
  
  json_value_destruct();
  json_value_destruct();
  if (in_stack_00000040 != &DAT_011c5338) {
    refcount_delete_offset10();
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050ead4 name=FUN_0050ead4 size=163 ====

void FUN_0050ead4(void)

{
  long unaff_RBX;
  void *unaff_R12;
  undefined8 in_stack_00000008;
  undefined8 in_stack_00000028;
  undefined8 in_stack_00000030;
  undefined8 in_stack_00000040;
  undefined8 in_stack_00000048;
  long in_stack_00000068;
  _Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *in_stack_00000088;
  _Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *in_stack_00000098;
  code *in_stack_000000d0;
  
  if (in_stack_00000068 + -0x18 != unaff_RBX) {
    refcount_delete_offset10();
  }
  string_vector_destroy(in_stack_00000040);
  json_value_destruct();
  json_value_destruct(in_stack_00000028);
  json_value_destruct(in_stack_00000048);
  FUN_00a0ef16();
  operator_delete(unaff_R12,0x88);
  if (in_stack_000000d0 != (code *)0x0) {
    (*in_stack_000000d0)(in_stack_00000008,in_stack_00000008,3);
  }
  if (in_stack_00000098 != (_Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *)0x0) {
    std::_Sp_counted_base<(__gnu_cxx::_Lock_policy)2>::_M_release(in_stack_00000098);
  }
  if (in_stack_00000088 != (_Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *)0x0) {
    std::_Sp_counted_base<(__gnu_cxx::_Lock_policy)2>::_M_release(in_stack_00000088);
  }
  json_value_destruct(in_stack_00000030);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050eb77 name=FUN_0050eb77 size=30 ====

void FUN_0050eb77(void)

{
  long unaff_RBX;
  void *unaff_R12;
  undefined8 in_stack_00000008;
  undefined8 in_stack_00000028;
  undefined8 in_stack_00000030;
  undefined8 in_stack_00000048;
  _Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *in_stack_00000088;
  _Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *in_stack_00000098;
  code *in_stack_000000d0;
  long in_stack_00000170;
  
  if (in_stack_00000170 + -0x18 != unaff_RBX) {
    refcount_delete_offset10();
  }
  json_value_destruct(in_stack_00000028);
  json_value_destruct(in_stack_00000048);
  FUN_00a0ef16();
  operator_delete(unaff_R12,0x88);
  if (in_stack_000000d0 != (code *)0x0) {
    (*in_stack_000000d0)(in_stack_00000008,in_stack_00000008,3);
  }
  if (in_stack_00000098 != (_Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *)0x0) {
    std::_Sp_counted_base<(__gnu_cxx::_Lock_policy)2>::_M_release(in_stack_00000098);
  }
  if (in_stack_00000088 != (_Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *)0x0) {
    std::_Sp_counted_base<(__gnu_cxx::_Lock_policy)2>::_M_release(in_stack_00000088);
  }
  json_value_destruct(in_stack_00000030);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050eb95 name=FUN_0050eb95 size=23 ====

void FUN_0050eb95(void)

{
  QRegularExpression *unaff_RBP;
  void *unaff_R12;
  undefined8 in_stack_00000008;
  undefined8 in_stack_00000028;
  undefined8 in_stack_00000030;
  _Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *in_stack_00000088;
  _Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *in_stack_00000098;
  code *in_stack_000000d0;
  
  QRegularExpression::~QRegularExpression(unaff_RBP);
  qt_array_data_unref(in_stack_00000028);
  FUN_00a0ef16();
  operator_delete(unaff_R12,0x88);
  if (in_stack_000000d0 != (code *)0x0) {
    (*in_stack_000000d0)(in_stack_00000008,in_stack_00000008,3);
  }
  if (in_stack_00000098 != (_Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *)0x0) {
    std::_Sp_counted_base<(__gnu_cxx::_Lock_policy)2>::_M_release(in_stack_00000098);
  }
  if (in_stack_00000088 != (_Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *)0x0) {
    std::_Sp_counted_base<(__gnu_cxx::_Lock_policy)2>::_M_release(in_stack_00000088);
  }
  json_value_destruct(in_stack_00000030);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050ebac name=FUN_0050ebac size=27 ====

void FUN_0050ebac(void)

{
  long unaff_RBX;
  undefined8 in_stack_00000030;
  _Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *in_stack_00000088;
  long in_stack_00000170;
  
  if (in_stack_00000170 + -0x18 != unaff_RBX) {
    refcount_delete_offset10();
  }
  if (in_stack_00000088 != (_Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *)0x0) {
    std::_Sp_counted_base<(__gnu_cxx::_Lock_policy)2>::_M_release(in_stack_00000088);
  }
  json_value_destruct(in_stack_00000030);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050ebc7 name=FUN_0050ebc7 size=18 ====

void FUN_0050ebc7(void)

{
  void *unaff_R12;
  undefined8 in_stack_00000008;
  undefined8 in_stack_00000030;
  _Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *in_stack_00000088;
  _Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *in_stack_00000098;
  code *in_stack_000000d0;
  
  operator_delete(unaff_R12,0x88);
  if (in_stack_000000d0 != (code *)0x0) {
    (*in_stack_000000d0)(in_stack_00000008,in_stack_00000008,3);
  }
  if (in_stack_00000098 != (_Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *)0x0) {
    std::_Sp_counted_base<(__gnu_cxx::_Lock_policy)2>::_M_release(in_stack_00000098);
  }
  if (in_stack_00000088 != (_Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *)0x0) {
    std::_Sp_counted_base<(__gnu_cxx::_Lock_policy)2>::_M_release(in_stack_00000088);
  }
  json_value_destruct(in_stack_00000030);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050ebd9 name=FUN_0050ebd9 size=13 ====

void FUN_0050ebd9(void)

{
  void *unaff_R12;
  undefined8 in_stack_00000008;
  undefined8 in_stack_00000028;
  undefined8 in_stack_00000030;
  undefined8 in_stack_00000048;
  _Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *in_stack_00000088;
  _Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *in_stack_00000098;
  code *in_stack_000000d0;
  
  json_value_destruct();
  json_value_destruct(in_stack_00000028);
  json_value_destruct(in_stack_00000048);
  FUN_00a0ef16();
  operator_delete(unaff_R12,0x88);
  if (in_stack_000000d0 != (code *)0x0) {
    (*in_stack_000000d0)(in_stack_00000008,in_stack_00000008,3);
  }
  if (in_stack_00000098 != (_Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *)0x0) {
    std::_Sp_counted_base<(__gnu_cxx::_Lock_policy)2>::_M_release(in_stack_00000098);
  }
  if (in_stack_00000088 != (_Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *)0x0) {
    std::_Sp_counted_base<(__gnu_cxx::_Lock_policy)2>::_M_release(in_stack_00000088);
  }
  json_value_destruct(in_stack_00000030);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050ebe6 name=FUN_0050ebe6 size=15 ====

void FUN_0050ebe6(void)

{
  void *unaff_R12;
  undefined8 in_stack_00000008;
  undefined8 in_stack_00000028;
  undefined8 in_stack_00000030;
  undefined8 in_stack_00000048;
  _Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *in_stack_00000088;
  _Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *in_stack_00000098;
  code *in_stack_000000d0;
  
  json_value_destruct();
  json_value_destruct(in_stack_00000028);
  json_value_destruct(in_stack_00000048);
  FUN_00a0ef16();
  operator_delete(unaff_R12,0x88);
  if (in_stack_000000d0 != (code *)0x0) {
    (*in_stack_000000d0)(in_stack_00000008,in_stack_00000008,3);
  }
  if (in_stack_00000098 != (_Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *)0x0) {
    std::_Sp_counted_base<(__gnu_cxx::_Lock_policy)2>::_M_release(in_stack_00000098);
  }
  if (in_stack_00000088 != (_Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *)0x0) {
    std::_Sp_counted_base<(__gnu_cxx::_Lock_policy)2>::_M_release(in_stack_00000088);
  }
  json_value_destruct(in_stack_00000030);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050ebf5 name=FUN_0050ebf5 size=38 ====

void FUN_0050ebf5(void)

{
  long unaff_RBX;
  void *unaff_R12;
  undefined8 in_stack_00000008;
  undefined8 in_stack_00000030;
  undefined8 in_stack_00000048;
  _Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *in_stack_00000088;
  _Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *in_stack_00000098;
  code *in_stack_000000d0;
  long in_stack_00000140;
  
  if (in_stack_00000140 + -0x18 != unaff_RBX) {
    refcount_delete_offset10();
  }
  json_value_destruct();
  json_value_destruct(in_stack_00000048);
  FUN_00a0ef16();
  operator_delete(unaff_R12,0x88);
  if (in_stack_000000d0 != (code *)0x0) {
    (*in_stack_000000d0)(in_stack_00000008,in_stack_00000008,3);
  }
  if (in_stack_00000098 != (_Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *)0x0) {
    std::_Sp_counted_base<(__gnu_cxx::_Lock_policy)2>::_M_release(in_stack_00000098);
  }
  if (in_stack_00000088 != (_Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *)0x0) {
    std::_Sp_counted_base<(__gnu_cxx::_Lock_policy)2>::_M_release(in_stack_00000088);
  }
  json_value_destruct(in_stack_00000030);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050ec1b name=FUN_0050ec1b size=35 ====

void FUN_0050ec1b(void)

{
  undefined8 in_stack_00000030;
  undefined1 *in_stack_00000170;
  
  if (in_stack_00000170 != &DAT_011c5338) {
    refcount_delete_offset10();
  }
  json_value_destruct(in_stack_00000030);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050ec3e name=FUN_0050ec3e size=40 ====

void FUN_0050ec3e(void)

{
  undefined8 in_stack_00000030;
  _Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *in_stack_00000088;
  _Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *in_stack_00000098;
  code *in_stack_000000d0;
  
  if (in_stack_000000d0 != (code *)0x0) {
    (*in_stack_000000d0)(&stack0x000000c0,&stack0x000000c0,3);
  }
  if (in_stack_00000098 != (_Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *)0x0) {
    std::_Sp_counted_base<(__gnu_cxx::_Lock_policy)2>::_M_release(in_stack_00000098);
  }
  if (in_stack_00000088 != (_Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *)0x0) {
    std::_Sp_counted_base<(__gnu_cxx::_Lock_policy)2>::_M_release(in_stack_00000088);
  }
  json_value_destruct(in_stack_00000030);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050ec66 name=FUN_0050ec66 size=47 ====

void FUN_0050ec66(void)

{
  long in_stack_00000028;
  long in_stack_00000040;
  
  qt_array_data_unref();
  qt_array_data_unref(&stack0x00000058);
  if (in_stack_00000040 + -0x18 != in_stack_00000028) {
    refcount_delete_offset10();
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050ec95 name=FUN_0050ec95 size=13 ====

void FUN_0050ec95(void)

{
  long in_stack_00000028;
  long in_stack_00000040;
  
  qt_array_data_unref();
  if (in_stack_00000040 + -0x18 != in_stack_00000028) {
    refcount_delete_offset10();
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050eca2 name=FUN_0050eca2 size=36 ====

void FUN_0050eca2(void)

{
  locale *unaff_R14;
  locale *in_stack_00000020;
  locale *in_stack_00000028;
  
  std::locale::~locale(unaff_R14);
  std::locale::~locale(in_stack_00000028);
  std::locale::~locale(in_stack_00000020);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050ecc6 name=FUN_0050ecc6 size=10 ====

void FUN_0050ecc6(void)

{
  locale *unaff_R13;
  locale *in_stack_00000020;
  
  std::locale::~locale(unaff_R13);
  std::locale::~locale(in_stack_00000020);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050ecd0 name=FUN_0050ecd0 size=31 ====

void FUN_0050ecd0(void)

{
  undefined1 *in_stack_00000018;
  
  if (in_stack_00000018 != &DAT_011c5338) {
    refcount_delete_offset10();
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050ecf0 name=FUN_0050ecf0 size=50 ====

void FUN_0050ecf0(void)

{
  long unaff_RBX;
  code *in_stack_00000040;
  
  if (in_stack_00000040 != (code *)0x0) {
    (*in_stack_00000040)(&stack0x00000030,&stack0x00000030,3);
  }
  if (unaff_RBX != 0) {
    pthread_mutex_unlock((pthread_mutex_t *)&DAT_011be720);
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050ed22 name=FUN_0050ed22 size=28 ====

void FUN_0050ed22(void)

{
  long unaff_RBX;
  code *in_stack_00000040;
  
  if (in_stack_00000040 != (code *)0x0) {
    (*in_stack_00000040)();
  }
  if (unaff_RBX != 0) {
    pthread_mutex_unlock((pthread_mutex_t *)&DAT_011be720);
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050ed3e name=FUN_0050ed3e size=31 ====

void FUN_0050ed3e(void)

{
  undefined1 *in_stack_00000018;
  
  if (in_stack_00000018 != &DAT_011c5338) {
    refcount_delete_offset10();
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050ed5e name=FUN_0050ed5e size=83 ====

void FUN_0050ed5e(void)

{
  undefined8 *puVar1;
  undefined8 *unaff_R13;
  
  puVar1 = unaff_R13 + 4;
  while (puVar1 != unaff_R13) {
    puVar1 = puVar1 + -1;
    if ((undefined1 *)*puVar1 != &DAT_011c5338) {
      refcount_delete_offset10();
    }
  }
  FUN_009d0656();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050ed8f name=FUN_0050ed8f size=105 ====

void FUN_0050ed8f(void)

{
  undefined8 *puVar1;
  long unaff_R12;
  undefined8 *unaff_R13;
  undefined1 *in_stack_00000068;
  _Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *in_stack_000000a8;
  _Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *in_stack_000000d8;
  
  if (in_stack_000000a8 != (_Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *)0x0) {
    std::_Sp_counted_base<(__gnu_cxx::_Lock_policy)2>::_M_release(in_stack_000000a8);
  }
  if (in_stack_000000d8 != (_Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *)0x0) {
    std::_Sp_counted_base<(__gnu_cxx::_Lock_policy)2>::_M_release(in_stack_000000d8);
  }
  if (in_stack_00000068 != &DAT_011c5338) {
    refcount_delete_offset10();
  }
  puVar1 = (undefined8 *)&stack0x00000140;
  do {
    puVar1 = puVar1 + -1;
    if ((undefined1 *)*puVar1 != &DAT_011c5338) {
      refcount_delete_offset10();
    }
  } while (puVar1 != unaff_R13);
  if (unaff_R12 != 0) {
    FUN_009d0656();
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050edf8 name=FUN_0050edf8 size=62 ====

/* WARNING: Removing unreachable block (ram,0x0050ed7f) */

void FUN_0050edf8(void)

{
  void *unaff_RBX;
  undefined8 *puVar1;
  undefined8 *unaff_R13;
  undefined8 in_stack_00000008;
  undefined1 *in_stack_00000058;
  
  operator_delete(unaff_RBX,0x20);
  qt_byte_array_unref(in_stack_00000008);
  json_value_destruct();
  if (in_stack_00000058 != &DAT_011c5338) {
    refcount_delete_offset10();
  }
  puVar1 = (undefined8 *)&stack0x00000140;
  do {
    puVar1 = puVar1 + -1;
    if ((undefined1 *)*puVar1 != &DAT_011c5338) {
      refcount_delete_offset10();
    }
  } while (puVar1 != unaff_R13);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050ee36 name=FUN_0050ee36 size=5 ====

/* WARNING: Removing unreachable block (ram,0x0050ed7f) */

void FUN_0050ee36(void)

{
  undefined8 *puVar1;
  undefined8 *unaff_R13;
  undefined8 in_stack_00000008;
  undefined1 *in_stack_00000058;
  
  qt_byte_array_unref(in_stack_00000008);
  json_value_destruct();
  if (in_stack_00000058 != &DAT_011c5338) {
    refcount_delete_offset10();
  }
  puVar1 = (undefined8 *)&stack0x00000140;
  do {
    puVar1 = puVar1 + -1;
    if ((undefined1 *)*puVar1 != &DAT_011c5338) {
      refcount_delete_offset10();
    }
  } while (puVar1 != unaff_R13);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050ee5d name=FUN_0050ee5d size=5 ====

/* WARNING: Removing unreachable block (ram,0x0050ed7f) */

void FUN_0050ee5d(void)

{
  undefined8 *puVar1;
  undefined8 *unaff_R13;
  undefined8 in_stack_00000008;
  undefined1 *in_stack_00000058;
  
  qt_byte_array_unref(in_stack_00000008);
  json_value_destruct();
  if (in_stack_00000058 != &DAT_011c5338) {
    refcount_delete_offset10();
  }
  puVar1 = (undefined8 *)&stack0x00000140;
  do {
    puVar1 = puVar1 + -1;
    if ((undefined1 *)*puVar1 != &DAT_011c5338) {
      refcount_delete_offset10();
    }
  } while (puVar1 != unaff_R13);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050ee62 name=FUN_0050ee62 size=28 ====

void FUN_0050ee62(void)

{
  undefined8 *puVar1;
  long unaff_R12;
  undefined8 *unaff_R13;
  undefined8 in_stack_00000008;
  undefined1 *in_stack_00000058;
  undefined1 *in_stack_000000a0;
  
  if (in_stack_000000a0 != &DAT_011c5338) {
    refcount_delete_offset10();
  }
  qt_byte_array_unref(in_stack_00000008);
  json_value_destruct();
  if (in_stack_00000058 != &DAT_011c5338) {
    refcount_delete_offset10();
  }
  puVar1 = (undefined8 *)&stack0x00000140;
  do {
    puVar1 = puVar1 + -1;
    if ((undefined1 *)*puVar1 != &DAT_011c5338) {
      refcount_delete_offset10();
    }
  } while (puVar1 != unaff_R13);
  if (unaff_R12 != 0) {
    FUN_009d0656();
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050ee7e name=FUN_0050ee7e size=21 ====

void FUN_0050ee7e(void)

{
  void *unaff_R12;
  
  operator_delete(unaff_R12,0x20);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050ee93 name=FUN_0050ee93 size=48 ====

void FUN_0050ee93(void)

{
  undefined8 *puVar1;
  long unaff_R12;
  undefined8 *unaff_R13;
  undefined8 in_stack_00000008;
  undefined1 *in_stack_00000058;
  undefined1 *in_stack_00000068;
  
  json_value_destruct();
  json_value_destruct();
  if (in_stack_00000068 != &DAT_011c5338) {
    refcount_delete_offset10();
  }
  qt_byte_array_unref(in_stack_00000008);
  json_value_destruct();
  if (in_stack_00000058 != &DAT_011c5338) {
    refcount_delete_offset10();
  }
  puVar1 = (undefined8 *)&stack0x00000140;
  do {
    puVar1 = puVar1 + -1;
    if ((undefined1 *)*puVar1 != &DAT_011c5338) {
      refcount_delete_offset10();
    }
  } while (puVar1 != unaff_R13);
  if (unaff_R12 != 0) {
    FUN_009d0656();
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050eec3 name=FUN_0050eec3 size=10 ====

void FUN_0050eec3(void)

{
  undefined8 *puVar1;
  undefined8 *unaff_R13;
  
  puVar1 = unaff_R13 + 3;
  while (puVar1 != unaff_R13) {
    puVar1 = puVar1 + -1;
    if ((undefined1 *)*puVar1 != &DAT_011c5338) {
      refcount_delete_offset10();
    }
  }
  FUN_009d0656();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050eecd name=FUN_0050eecd size=10 ====

void FUN_0050eecd(void)

{
  undefined8 *puVar1;
  undefined8 *unaff_R13;
  
  puVar1 = unaff_R13 + 2;
  while (puVar1 != unaff_R13) {
    puVar1 = puVar1 + -1;
    if ((undefined1 *)*puVar1 != &DAT_011c5338) {
      refcount_delete_offset10();
    }
  }
  FUN_009d0656();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050eed7 name=FUN_0050eed7 size=10 ====

void FUN_0050eed7(void)

{
  undefined8 *puVar1;
  undefined8 *unaff_R13;
  
  puVar1 = unaff_R13 + 1;
  while (puVar1 != unaff_R13) {
    puVar1 = puVar1 + -1;
    if ((undefined1 *)*puVar1 != &DAT_011c5338) {
      refcount_delete_offset10();
    }
  }
  FUN_009d0656();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050eee1 name=FUN_0050eee1 size=21 ====

void FUN_0050eee1(void)

{
  undefined8 *puVar1;
  long unaff_R12;
  undefined8 *unaff_R13;
  undefined1 *in_stack_00000058;
  
  json_value_destruct();
  json_value_destruct();
  if (in_stack_00000058 != &DAT_011c5338) {
    refcount_delete_offset10();
  }
  puVar1 = (undefined8 *)&stack0x00000140;
  do {
    puVar1 = puVar1 + -1;
    if ((undefined1 *)*puVar1 != &DAT_011c5338) {
      refcount_delete_offset10();
    }
  } while (puVar1 != unaff_R13);
  if (unaff_R12 != 0) {
    FUN_009d0656();
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050eef6 name=FUN_0050eef6 size=44 ====

void FUN_0050eef6(void)

{
  undefined8 *puVar1;
  long unaff_R12;
  undefined8 *unaff_R13;
  undefined1 *in_stack_00000070;
  
  json_value_destruct();
  if (in_stack_00000070 != &DAT_011c5338) {
    refcount_delete_offset10();
  }
  json_value_destruct();
  puVar1 = (undefined8 *)&stack0x00000140;
  do {
    puVar1 = puVar1 + -1;
    if ((undefined1 *)*puVar1 != &DAT_011c5338) {
      refcount_delete_offset10();
    }
  } while (puVar1 != unaff_R13);
  if (unaff_R12 != 0) {
    FUN_009d0656();
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050ef22 name=FUN_0050ef22 size=7 ====

void FUN_0050ef22(void)

{
  undefined8 *puVar1;
  undefined8 *unaff_R13;
  
  puVar1 = unaff_R13 + 7;
  while (puVar1 != unaff_R13) {
    puVar1 = puVar1 + -1;
    if ((undefined1 *)*puVar1 != &DAT_011c5338) {
      refcount_delete_offset10();
    }
  }
  FUN_009d0656();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050ef29 name=FUN_0050ef29 size=12 ====

void FUN_0050ef29(void)

{
  undefined8 *puVar1;
  undefined8 *unaff_R13;
  
  puVar1 = unaff_R13 + 6;
  while (puVar1 != unaff_R13) {
    puVar1 = puVar1 + -1;
    if ((undefined1 *)*puVar1 != &DAT_011c5338) {
      refcount_delete_offset10();
    }
  }
  FUN_009d0656();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050ef35 name=FUN_0050ef35 size=10 ====

void FUN_0050ef35(void)

{
  undefined8 *puVar1;
  undefined8 *unaff_R13;
  
  puVar1 = unaff_R13 + 5;
  while (puVar1 != unaff_R13) {
    puVar1 = puVar1 + -1;
    if ((undefined1 *)*puVar1 != &DAT_011c5338) {
      refcount_delete_offset10();
    }
  }
  FUN_009d0656();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050ef3f name=FUN_0050ef3f size=10 ====

void FUN_0050ef3f(void)

{
  undefined8 *puVar1;
  undefined8 *unaff_R13;
  
  puVar1 = unaff_R13;
  while (puVar1 != unaff_R13) {
    puVar1 = puVar1 + -1;
    if ((undefined1 *)*puVar1 != &DAT_011c5338) {
      refcount_delete_offset10();
    }
  }
  FUN_009d0656();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050ef49 name=FUN_0050ef49 size=21 ====

void FUN_0050ef49(void)

{
  undefined8 *puVar1;
  long unaff_R12;
  undefined8 *unaff_R13;
  undefined8 in_stack_00000008;
  undefined1 *in_stack_00000058;
  undefined1 *in_stack_00000068;
  
  json_value_destruct();
  json_value_destruct();
  if (in_stack_00000068 != &DAT_011c5338) {
    refcount_delete_offset10();
  }
  qt_byte_array_unref(in_stack_00000008);
  json_value_destruct();
  if (in_stack_00000058 != &DAT_011c5338) {
    refcount_delete_offset10();
  }
  puVar1 = (undefined8 *)&stack0x00000140;
  do {
    puVar1 = puVar1 + -1;
    if ((undefined1 *)*puVar1 != &DAT_011c5338) {
      refcount_delete_offset10();
    }
  } while (puVar1 != unaff_R13);
  if (unaff_R12 != 0) {
    FUN_009d0656();
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050ef5e name=FUN_0050ef5e size=21 ====

void FUN_0050ef5e(void)

{
  undefined8 *puVar1;
  long unaff_R12;
  undefined8 *unaff_R13;
  undefined8 in_stack_00000008;
  undefined1 *in_stack_00000058;
  undefined1 *in_stack_00000068;
  
  json_value_destruct();
  json_value_destruct();
  if (in_stack_00000068 != &DAT_011c5338) {
    refcount_delete_offset10();
  }
  qt_byte_array_unref(in_stack_00000008);
  json_value_destruct();
  if (in_stack_00000058 != &DAT_011c5338) {
    refcount_delete_offset10();
  }
  puVar1 = (undefined8 *)&stack0x00000140;
  do {
    puVar1 = puVar1 + -1;
    if ((undefined1 *)*puVar1 != &DAT_011c5338) {
      refcount_delete_offset10();
    }
  } while (puVar1 != unaff_R13);
  if (unaff_R12 != 0) {
    FUN_009d0656();
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050ef73 name=FUN_0050ef73 size=21 ====

void FUN_0050ef73(void)

{
  undefined8 *puVar1;
  long unaff_R12;
  undefined8 *unaff_R13;
  undefined8 in_stack_00000008;
  undefined1 *in_stack_00000058;
  
  json_value_destruct();
  json_value_destruct();
  qt_byte_array_unref(in_stack_00000008);
  json_value_destruct();
  if (in_stack_00000058 != &DAT_011c5338) {
    refcount_delete_offset10();
  }
  puVar1 = (undefined8 *)&stack0x00000140;
  do {
    puVar1 = puVar1 + -1;
    if ((undefined1 *)*puVar1 != &DAT_011c5338) {
      refcount_delete_offset10();
    }
  } while (puVar1 != unaff_R13);
  if (unaff_R12 != 0) {
    FUN_009d0656();
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050ef88 name=FUN_0050ef88 size=21 ====

void FUN_0050ef88(void)

{
  undefined8 *puVar1;
  long unaff_R12;
  undefined8 *unaff_R13;
  
  json_value_destruct();
  json_value_destruct();
  puVar1 = (undefined8 *)&stack0x00000140;
  do {
    puVar1 = puVar1 + -1;
    if ((undefined1 *)*puVar1 != &DAT_011c5338) {
      refcount_delete_offset10();
    }
  } while (puVar1 != unaff_R13);
  if (unaff_R12 != 0) {
    FUN_009d0656();
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050ef9d name=FUN_0050ef9d size=21 ====

void FUN_0050ef9d(void)

{
  undefined8 *puVar1;
  long unaff_R12;
  undefined8 *unaff_R13;
  undefined1 *in_stack_00000058;
  
  json_value_destruct();
  json_value_destruct();
  if (in_stack_00000058 != &DAT_011c5338) {
    refcount_delete_offset10();
  }
  puVar1 = (undefined8 *)&stack0x00000140;
  do {
    puVar1 = puVar1 + -1;
    if ((undefined1 *)*puVar1 != &DAT_011c5338) {
      refcount_delete_offset10();
    }
  } while (puVar1 != unaff_R13);
  if (unaff_R12 != 0) {
    FUN_009d0656();
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050efb2 name=FUN_0050efb2 size=8 ====

/* WARNING: Removing unreachable block (ram,0x0050ed7f) */

void FUN_0050efb2(void)

{
  undefined8 *puVar1;
  undefined8 *unaff_R13;
  undefined8 in_stack_00000008;
  undefined1 *in_stack_00000058;
  
  qt_byte_array_unref(in_stack_00000008);
  json_value_destruct();
  if (in_stack_00000058 != &DAT_011c5338) {
    refcount_delete_offset10();
  }
  puVar1 = (undefined8 *)&stack0x00000140;
  do {
    puVar1 = puVar1 + -1;
    if ((undefined1 *)*puVar1 != &DAT_011c5338) {
      refcount_delete_offset10();
    }
  } while (puVar1 != unaff_R13);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050efba name=FUN_0050efba size=47 ====

void FUN_0050efba(void)

{
  long in_stack_00000018;
  
  json_value_destruct();
  if (in_stack_00000018 != 0) {
    FUN_009e1c20(&stack0x00000018);
  }
  json_value_destruct();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050efe9 name=FUN_0050efe9 size=10 ====

void FUN_0050efe9(void)

{
  long in_stack_00000018;
  
  json_value_destruct();
  if (in_stack_00000018 != 0) {
    FUN_009e1c20(&stack0x00000018);
  }
  json_value_destruct();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050eff3 name=FUN_0050eff3 size=15 ====

void FUN_0050eff3(void)

{
  void *unaff_RBX;
  long in_stack_00000018;
  
  operator_delete(unaff_RBX,0x48);
  if (in_stack_00000018 != 0) {
    FUN_009e1c20(&stack0x00000018);
  }
  json_value_destruct();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050f002 name=FUN_0050f002 size=10 ====

void FUN_0050f002(void)

{
  long in_stack_00000018;
  
  json_value_destruct();
  if (in_stack_00000018 != 0) {
    FUN_009e1c20(&stack0x00000018);
  }
  json_value_destruct();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050f00c name=FUN_0050f00c size=10 ====

void FUN_0050f00c(void)

{
  long in_stack_00000018;
  
  json_value_destruct();
  if (in_stack_00000018 != 0) {
    FUN_009e1c20(&stack0x00000018);
  }
  json_value_destruct();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050f016 name=FUN_0050f016 size=12 ====

void FUN_0050f016(void)

{
  long in_stack_00000018;
  
  json_value_destruct();
  if (in_stack_00000018 != 0) {
    FUN_009e1c20(&stack0x00000018);
  }
  json_value_destruct();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050f022 name=FUN_0050f022 size=153 ====

void FUN_0050f022(void)

{
  long in_stack_00000018;
  long in_stack_00000080;
  ostringstream *in_stack_000000a0;
  long in_stack_000000e8;
  undefined1 *in_stack_000000f0;
  long in_stack_00000ab8;
  undefined8 in_stack_00000ad0;
  
  FUN_0081e560(in_stack_00000018 + 0x240,in_stack_00000ad0);
  if (in_stack_00000ab8 != 0) {
    refcounted_vt_destroy();
  }
  std::locale::~locale((locale *)(in_stack_00000018 + 0x210));
  std::locale::~locale((locale *)(in_stack_00000080 + 0x200));
  if (in_stack_000000f0 != &DAT_011c5338) {
    refcount_delete_offset10();
  }
  if (in_stack_000000e8 != 0) {
    iconTree_freeNode2(&stack0x000000e8);
  }
  std::ostringstream::~ostringstream(in_stack_000000a0);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050f0bb name=FUN_0050f0bb size=61 ====

void FUN_0050f0bb(void)

{
  locale *in_stack_00000048;
  long in_stack_00000080;
  locale *in_stack_00000098;
  ostringstream *in_stack_000000a0;
  locale *in_stack_000000b0;
  long in_stack_000000e8;
  undefined1 *in_stack_000000f0;
  
  std::locale::~locale(in_stack_00000098);
  std::locale::~locale(in_stack_00000048);
  std::locale::~locale((locale *)(in_stack_00000080 + 0x200));
  std::locale::~locale(in_stack_000000b0);
  if (in_stack_000000f0 != &DAT_011c5338) {
    refcount_delete_offset10();
  }
  if (in_stack_000000e8 != 0) {
    iconTree_freeNode2(&stack0x000000e8);
  }
  std::ostringstream::~ostringstream(in_stack_000000a0);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050f0f8 name=FUN_0050f0f8 size=35 ====

void FUN_0050f0f8(void)

{
  ostringstream *in_stack_000000a0;
  long in_stack_000000e8;
  undefined1 *in_stack_000000f0;
  long in_stack_00000108;
  
  FUN_009e2c8b();
  if (in_stack_00000108 != 0) {
    FUN_0081e506();
  }
  if (in_stack_000000f0 != &DAT_011c5338) {
    refcount_delete_offset10();
  }
  if (in_stack_000000e8 != 0) {
    iconTree_freeNode2(&stack0x000000e8);
  }
  std::ostringstream::~ostringstream(in_stack_000000a0);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050f11b name=FUN_0050f11b size=67 ====

void FUN_0050f11b(void)

{
  undefined8 unaff_R13;
  long unaff_R15;
  ostringstream *in_stack_000000a0;
  long in_stack_000000e8;
  undefined1 *in_stack_000000f0;
  long in_stack_00000108;
  long in_stack_00000120;
  long in_stack_00000148;
  
  if (in_stack_00000148 != 0) {
    FUN_0067cdf0();
  }
  if (in_stack_00000120 != 0) {
    FUN_0081e506();
  }
  if (unaff_R15 != 0) {
    FUN_009e2c8b();
  }
  if (in_stack_00000108 != 0) {
    FUN_0081e506();
  }
  if (in_stack_000000f0 != &DAT_011c5338) {
    refcount_delete_offset10();
  }
  if (in_stack_000000e8 != 0) {
    iconTree_freeNode2(&stack0x000000e8);
  }
  std::ostringstream::~ostringstream(in_stack_000000a0);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception(unaff_R13);
}


// ==== entry=0050f15e name=FUN_0050f15e size=31 ====

void FUN_0050f15e(void)

{
  undefined8 unaff_RBX;
  long unaff_R15;
  ostringstream *in_stack_000000a0;
  long in_stack_000000e8;
  undefined1 *in_stack_000000f0;
  long in_stack_00000108;
  undefined1 *in_stack_00000880;
  
  if (in_stack_00000880 != &DAT_011c5338) {
    refcount_delete_offset10();
  }
  if (unaff_R15 != 0) {
    FUN_009e2c8b();
  }
  if (in_stack_00000108 != 0) {
    FUN_0081e506();
  }
  if (in_stack_000000f0 != &DAT_011c5338) {
    refcount_delete_offset10();
  }
  if (in_stack_000000e8 != 0) {
    iconTree_freeNode2(&stack0x000000e8);
  }
  std::ostringstream::~ostringstream(in_stack_000000a0);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception(unaff_RBX);
}


// ==== entry=0050f17d name=FUN_0050f17d size=18 ====

void FUN_0050f17d(void)

{
  void *unaff_R15;
  ostringstream *in_stack_000000a0;
  long in_stack_000000e8;
  undefined1 *in_stack_000000f0;
  long in_stack_00000108;
  
  operator_delete(unaff_R15,0x180);
  if (in_stack_00000108 != 0) {
    FUN_0081e506();
  }
  if (in_stack_000000f0 != &DAT_011c5338) {
    refcount_delete_offset10();
  }
  if (in_stack_000000e8 != 0) {
    iconTree_freeNode2(&stack0x000000e8);
  }
  std::ostringstream::~ostringstream(in_stack_000000a0);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050f18f name=FUN_0050f18f size=15 ====

void FUN_0050f18f(void)

{
  undefined8 in_stack_00000018;
  long in_stack_00000080;
  ostringstream *in_stack_000000a0;
  long in_stack_000000e8;
  undefined1 *in_stack_000000f0;
  
  FUN_009e2cc0(in_stack_00000018);
  std::locale::~locale((locale *)(in_stack_00000080 + 0x200));
  if (in_stack_000000f0 != &DAT_011c5338) {
    refcount_delete_offset10();
  }
  if (in_stack_000000e8 != 0) {
    iconTree_freeNode2(&stack0x000000e8);
  }
  std::ostringstream::~ostringstream(in_stack_000000a0);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050f19e name=FUN_0050f19e size=104 ====

void FUN_0050f19e(void)

{
  undefined8 unaff_RBX;
  undefined1 unaff_R14B;
  long unaff_R15;
  long in_stack_00000018;
  ostringstream *in_stack_000000a0;
  long in_stack_000000e8;
  undefined1 *in_stack_000000f0;
  long in_stack_00000108;
  long in_stack_00000130;
  undefined8 in_stack_00000890;
  undefined8 in_stack_000008c0;
  long in_stack_000008e8;
  
  if (in_stack_000008e8 != 0) {
    refcounted_vt_destroy();
  }
  FUN_00822170(in_stack_00000018 + 0x30,in_stack_000008c0);
  tree_freeRefNodes(in_stack_00000018,in_stack_00000890);
  if (in_stack_00000130 != 0) {
    FUN_0081e506();
  }
  *(undefined1 *)(unaff_R15 + 0x10e) = unaff_R14B;
  if (unaff_R15 != 0) {
    FUN_009e2c8b();
  }
  if (in_stack_00000108 != 0) {
    FUN_0081e506();
  }
  if (in_stack_000000f0 != &DAT_011c5338) {
    refcount_delete_offset10();
  }
  if (in_stack_000000e8 != 0) {
    iconTree_freeNode2(&stack0x000000e8);
  }
  std::ostringstream::~ostringstream(in_stack_000000a0);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception(unaff_RBX);
}


// ==== entry=0050f1f6 name=FUN_0050f1f6 size=148 ====

void FUN_0050f1f6(void)

{
  long unaff_RBX;
  long unaff_RBP;
  long unaff_R12;
  undefined8 unaff_R13;
  long unaff_R15;
  undefined8 in_stack_00000018;
  long in_stack_00000020;
  undefined8 in_stack_00000058;
  undefined8 in_stack_00000080;
  ostringstream *in_stack_000000a0;
  undefined8 in_stack_000000b8;
  long in_stack_000000e8;
  undefined1 *in_stack_000000f0;
  long in_stack_00000108;
  long in_stack_00000120;
  long in_stack_00000178;
  long in_stack_00000198;
  
  FUN_00820e8e(in_stack_00000018);
  FUN_00820e8e(in_stack_00000058);
  FUN_00820e8e(in_stack_00000080);
  if (unaff_R12 != 0) {
    refcounted_vt_destroy();
  }
  if (unaff_RBX != 0) {
    refcounted_vt_destroy();
  }
  FUN_00820e8e(in_stack_000000b8);
  if (in_stack_00000020 != 0) {
    refcounted_vt_destroy(in_stack_00000020);
  }
  if (unaff_RBP != 0) {
    refcounted_vt_destroy();
  }
  if (in_stack_00000198 != 0) {
    refcounted_vt_destroy();
  }
  if (in_stack_00000178 != 0) {
    refcounted_vt_destroy();
  }
  if (in_stack_00000120 != 0) {
    FUN_0081e506();
  }
  if (unaff_R15 != 0) {
    FUN_009e2c8b();
  }
  if (in_stack_00000108 != 0) {
    FUN_0081e506();
  }
  if (in_stack_000000f0 != &DAT_011c5338) {
    refcount_delete_offset10();
  }
  if (in_stack_000000e8 != 0) {
    iconTree_freeNode2(&stack0x000000e8);
  }
  std::ostringstream::~ostringstream(in_stack_000000a0);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception(unaff_R13);
}


// ==== entry=0050f28a name=FUN_0050f28a size=96 ====

void FUN_0050f28a(void)

{
  void *unaff_RBX;
  undefined8 unaff_RBP;
  long unaff_R15;
  ostringstream *in_stack_000000a0;
  long in_stack_000000c0;
  long in_stack_000000e8;
  undefined1 *in_stack_000000f0;
  long in_stack_00000108;
  undefined8 in_stack_000002a0;
  undefined8 in_stack_000002d0;
  long in_stack_000002f8;
  
  if (in_stack_000002f8 != 0) {
    refcounted_vt_destroy();
  }
  FUN_00822170(in_stack_000000c0 + 0x30,in_stack_000002d0);
  tree_freeRefNodes(in_stack_000000c0,in_stack_000002a0);
  if (*(long *)((long)unaff_RBX + 8) != 0) {
    FUN_0081e506();
  }
  operator_delete(unaff_RBX,0x180);
  if (unaff_R15 != 0) {
    FUN_009e2c8b();
  }
  if (in_stack_00000108 != 0) {
    FUN_0081e506();
  }
  if (in_stack_000000f0 != &DAT_011c5338) {
    refcount_delete_offset10();
  }
  if (in_stack_000000e8 != 0) {
    iconTree_freeNode2(&stack0x000000e8);
  }
  std::ostringstream::~ostringstream(in_stack_000000a0);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception(unaff_RBP);
}


// ==== entry=0050f2fa name=FUN_0050f2fa size=61 ====

void FUN_0050f2fa(void)

{
  undefined8 unaff_R13;
  long unaff_R15;
  long in_stack_00000048;
  ostringstream *in_stack_000000a0;
  long in_stack_000000e8;
  undefined1 *in_stack_000000f0;
  long in_stack_00000108;
  long in_stack_00000120;
  undefined8 in_stack_00000360;
  undefined8 in_stack_00000390;
  long in_stack_000003b8;
  
  if (in_stack_000003b8 != 0) {
    refcounted_vt_destroy();
  }
  FUN_00822170(in_stack_00000048 + 0x30,in_stack_00000390);
  tree_freeRefNodes(in_stack_00000048,in_stack_00000360);
  if (in_stack_00000120 != 0) {
    FUN_0081e506();
  }
  if (unaff_R15 != 0) {
    FUN_009e2c8b();
  }
  if (in_stack_00000108 != 0) {
    FUN_0081e506();
  }
  if (in_stack_000000f0 != &DAT_011c5338) {
    refcount_delete_offset10();
  }
  if (in_stack_000000e8 != 0) {
    iconTree_freeNode2(&stack0x000000e8);
  }
  std::ostringstream::~ostringstream(in_stack_000000a0);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception(unaff_R13);
}


// ==== entry=0050f337 name=FUN_0050f337 size=102 ====

void FUN_0050f337(void)

{
  void *unaff_RBX;
  undefined8 unaff_RBP;
  long unaff_R15;
  ostringstream *in_stack_000000a0;
  undefined8 in_stack_000000c0;
  long in_stack_000000e8;
  undefined1 *in_stack_000000f0;
  long in_stack_00000108;
  long in_stack_00000308;
  long in_stack_00000310;
  long in_stack_00000318;
  void *in_stack_00000320;
  
  if (in_stack_00000320 != (void *)0x0) {
    operator_delete(in_stack_00000320);
  }
  if (in_stack_00000318 != 0) {
    FUN_00821f2c(in_stack_00000318 + 8);
  }
  if (in_stack_00000310 != 0) {
    FUN_0081e715(in_stack_00000310 + 8);
  }
  if (in_stack_00000308 != 0) {
    qslotobject_release_destroy(in_stack_00000308 + 8);
  }
  FUN_008221d6(in_stack_000000c0);
  if (*(long *)((long)unaff_RBX + 8) != 0) {
    FUN_0081e506();
  }
  operator_delete(unaff_RBX,0x180);
  if (unaff_R15 != 0) {
    FUN_009e2c8b();
  }
  if (in_stack_00000108 != 0) {
    FUN_0081e506();
  }
  if (in_stack_000000f0 != &DAT_011c5338) {
    refcount_delete_offset10();
  }
  if (in_stack_000000e8 != 0) {
    iconTree_freeNode2(&stack0x000000e8);
  }
  std::ostringstream::~ostringstream(in_stack_000000a0);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception(unaff_RBP);
}


// ==== entry=0050f408 name=FUN_0050f408 size=50 ====

void FUN_0050f408(void)

{
  undefined8 *unaff_R12;
  undefined8 *in_stack_00000058;
  
  __cxa_begin_catch();
  for (; in_stack_00000058 != unaff_R12; in_stack_00000058 = in_stack_00000058 + 2) {
    if ((undefined1 *)*in_stack_00000058 != &DAT_011c5338) {
      refcount_delete_offset10();
    }
  }
                    /* WARNING: Subroutine does not return */
                    /* try { // try from 0050f41a to 0050f41e has its CatchHandler @ 0050f43a */
  __cxa_rethrow();
}


// ==== entry=0050f4a5 name=FUN_0050f4a5 size=16 ====

void FUN_0050f4a5(void)

{
  void *unaff_RBX;
  undefined8 unaff_RBP;
  long unaff_R15;
  ostringstream *in_stack_000000a0;
  long in_stack_000000e8;
  undefined1 *in_stack_000000f0;
  long in_stack_00000108;
  
  FUN_0081cbd0();
  if (*(long *)((long)unaff_RBX + 8) != 0) {
    FUN_0081e506();
  }
  operator_delete(unaff_RBX,0x180);
  if (unaff_R15 != 0) {
    FUN_009e2c8b();
  }
  if (in_stack_00000108 != 0) {
    FUN_0081e506();
  }
  if (in_stack_000000f0 != &DAT_011c5338) {
    refcount_delete_offset10();
  }
  if (in_stack_000000e8 != 0) {
    iconTree_freeNode2(&stack0x000000e8);
  }
  std::ostringstream::~ostringstream(in_stack_000000a0);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception(unaff_RBP);
}


// ==== entry=0050f4b5 name=FUN_0050f4b5 size=8 ====

void FUN_0050f4b5(void)

{
  undefined8 in_RAX;
  long unaff_RBX;
  ostringstream *in_stack_000000a0;
  long in_stack_000000e8;
  undefined1 *in_stack_000000f0;
  long in_stack_00000108;
  
  if (unaff_RBX != 0) {
    FUN_009e2c8b();
  }
  if (in_stack_00000108 != 0) {
    FUN_0081e506();
  }
  if (in_stack_000000f0 != &DAT_011c5338) {
    refcount_delete_offset10();
  }
  if (in_stack_000000e8 != 0) {
    iconTree_freeNode2(&stack0x000000e8);
  }
  std::ostringstream::~ostringstream(in_stack_000000a0);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception(in_RAX);
}


// ==== entry=0050f4bd name=FUN_0050f4bd size=46 ====

void FUN_0050f4bd(void)

{
  undefined8 *unaff_R12;
  undefined8 *unaff_R13;
  
  __cxa_begin_catch();
  for (; unaff_R13 != unaff_R12; unaff_R13 = unaff_R13 + 2) {
    if ((undefined1 *)*unaff_R13 != &DAT_011c5338) {
      refcount_delete_offset10();
    }
  }
                    /* WARNING: Subroutine does not return */
                    /* try { // try from 0050f4ca to 0050f4ce has its CatchHandler @ 0050f39d */
  __cxa_rethrow();
}


// ==== entry=0050f4ec name=FUN_0050f4ec size=31 ====

void FUN_0050f4ec(void)

{
  undefined1 *in_stack_00000008;
  
  if (in_stack_00000008 != &DAT_011c5338) {
    refcount_delete_offset10();
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050f50c name=FUN_0050f50c size=151 ====

void FUN_0050f50c(void)

{
  long unaff_R15;
  undefined8 in_stack_00000020;
  void *in_stack_00000030;
  void *in_stack_00000048;
  long in_stack_000000b8;
  long in_stack_000000c0;
  long in_stack_00000160;
  
  if (in_stack_00000160 + -0x18 != unaff_R15) {
    refcount_delete_offset10();
  }
  json_value_destruct(in_stack_00000020);
  if (in_stack_000000c0 + -0x18 != unaff_R15) {
    refcount_delete_offset10();
  }
  if (in_stack_000000b8 + -0x18 != unaff_R15) {
    refcount_delete_offset10();
  }
  if (in_stack_00000030 != (void *)0x0) {
    completion_entry_dtor(in_stack_00000030);
    operator_delete(in_stack_00000030,0x88);
  }
  if (in_stack_00000048 != (void *)0x0) {
    FUN_00a114bc(in_stack_00000048);
    operator_delete(in_stack_00000048,0x38);
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050f5a3 name=FUN_0050f5a3 size=35 ====

void FUN_0050f5a3(void)

{
  long unaff_R15;
  undefined8 in_stack_00000018;
  undefined8 in_stack_00000020;
  undefined8 in_stack_00000028;
  void *in_stack_00000030;
  void *in_stack_00000048;
  long in_stack_000000b8;
  long in_stack_000000c0;
  long in_stack_000000f0;
  
  if (in_stack_000000f0 + -0x18 != unaff_R15) {
    refcount_delete_offset10();
  }
  json_value_destruct();
  string_vector_destroy(in_stack_00000018);
  json_value_destruct(in_stack_00000028);
  json_value_destruct(in_stack_00000020);
  if (in_stack_000000c0 + -0x18 != unaff_R15) {
    refcount_delete_offset10();
  }
  if (in_stack_000000b8 + -0x18 != unaff_R15) {
    refcount_delete_offset10();
  }
  if (in_stack_00000030 != (void *)0x0) {
    completion_entry_dtor(in_stack_00000030);
    operator_delete(in_stack_00000030,0x88);
  }
  if (in_stack_00000048 != (void *)0x0) {
    FUN_00a114bc(in_stack_00000048);
    operator_delete(in_stack_00000048,0x38);
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050f5c6 name=FUN_0050f5c6 size=31 ====

void FUN_0050f5c6(void)

{
  long unaff_R15;
  undefined8 in_stack_00000020;
  void *in_stack_00000030;
  void *in_stack_00000048;
  long in_stack_000000b8;
  long in_stack_000000c0;
  long in_stack_00000110;
  
  if (in_stack_00000110 + -0x18 != unaff_R15) {
    refcount_delete_offset10();
  }
  json_value_destruct(in_stack_00000020);
  if (in_stack_000000c0 + -0x18 != unaff_R15) {
    refcount_delete_offset10();
  }
  if (in_stack_000000b8 + -0x18 != unaff_R15) {
    refcount_delete_offset10();
  }
  if (in_stack_00000030 != (void *)0x0) {
    completion_entry_dtor(in_stack_00000030);
    operator_delete(in_stack_00000030,0x88);
  }
  if (in_stack_00000048 != (void *)0x0) {
    FUN_00a114bc(in_stack_00000048);
    operator_delete(in_stack_00000048,0x38);
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050f5e5 name=FUN_0050f5e5 size=46 ====

void FUN_0050f5e5(void)

{
  long unaff_R15;
  undefined8 in_stack_00000018;
  undefined8 in_stack_00000020;
  undefined8 in_stack_00000028;
  void *in_stack_00000030;
  void *in_stack_00000048;
  long in_stack_000000b8;
  long in_stack_000000c0;
  long in_stack_000000e8;
  long in_stack_00000108;
  
  if (in_stack_00000108 + -0x18 != unaff_R15) {
    refcount_delete_offset10();
  }
  if (in_stack_000000e8 + -0x18 != unaff_R15) {
    refcount_delete_offset10();
  }
  json_value_destruct();
  string_vector_destroy(in_stack_00000018);
  json_value_destruct(in_stack_00000028);
  json_value_destruct(in_stack_00000020);
  if (in_stack_000000c0 + -0x18 != unaff_R15) {
    refcount_delete_offset10();
  }
  if (in_stack_000000b8 + -0x18 != unaff_R15) {
    refcount_delete_offset10();
  }
  if (in_stack_00000030 != (void *)0x0) {
    completion_entry_dtor(in_stack_00000030);
    operator_delete(in_stack_00000030,0x88);
  }
  if (in_stack_00000048 != (void *)0x0) {
    FUN_00a114bc(in_stack_00000048);
    operator_delete(in_stack_00000048,0x38);
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050f613 name=FUN_0050f613 size=26 ====

void FUN_0050f613(void)

{
  long unaff_R15;
  undefined8 in_stack_00000028;
  void *in_stack_00000030;
  void *in_stack_00000048;
  long in_stack_000000b8;
  long in_stack_000000c0;
  
  json_value_destruct();
  json_value_destruct(in_stack_00000028);
  if (in_stack_000000c0 + -0x18 != unaff_R15) {
    refcount_delete_offset10();
  }
  if (in_stack_000000b8 + -0x18 != unaff_R15) {
    refcount_delete_offset10();
  }
  if (in_stack_00000030 != (void *)0x0) {
    completion_entry_dtor(in_stack_00000030);
    operator_delete(in_stack_00000030,0x88);
  }
  if (in_stack_00000048 != (void *)0x0) {
    FUN_00a114bc(in_stack_00000048);
    operator_delete(in_stack_00000048,0x38);
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050f62d name=FUN_0050f62d size=13 ====

void FUN_0050f62d(void)

{
  long unaff_R15;
  undefined8 in_stack_00000028;
  void *in_stack_00000030;
  void *in_stack_00000048;
  long in_stack_000000b8;
  long in_stack_000000c0;
  
  json_value_destruct();
  json_value_destruct(in_stack_00000028);
  if (in_stack_000000c0 + -0x18 != unaff_R15) {
    refcount_delete_offset10();
  }
  if (in_stack_000000b8 + -0x18 != unaff_R15) {
    refcount_delete_offset10();
  }
  if (in_stack_00000030 != (void *)0x0) {
    completion_entry_dtor(in_stack_00000030);
    operator_delete(in_stack_00000030,0x88);
  }
  if (in_stack_00000048 != (void *)0x0) {
    FUN_00a114bc(in_stack_00000048);
    operator_delete(in_stack_00000048,0x38);
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050f63a name=FUN_0050f63a size=13 ====

void FUN_0050f63a(void)

{
  long unaff_R15;
  undefined8 in_stack_00000028;
  void *in_stack_00000030;
  void *in_stack_00000048;
  long in_stack_000000b8;
  long in_stack_000000c0;
  
  json_value_destruct();
  json_value_destruct(in_stack_00000028);
  if (in_stack_000000c0 + -0x18 != unaff_R15) {
    refcount_delete_offset10();
  }
  if (in_stack_000000b8 + -0x18 != unaff_R15) {
    refcount_delete_offset10();
  }
  if (in_stack_00000030 != (void *)0x0) {
    completion_entry_dtor(in_stack_00000030);
    operator_delete(in_stack_00000030,0x88);
  }
  if (in_stack_00000048 != (void *)0x0) {
    FUN_00a114bc(in_stack_00000048);
    operator_delete(in_stack_00000048,0x38);
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050f647 name=FUN_0050f647 size=20 ====

void FUN_0050f647(void)

{
  void *in_stack_00000030;
  void *in_stack_00000048;
  
  operator_delete(in_stack_00000030,0x88);
  FUN_00a114bc(in_stack_00000048);
  operator_delete(in_stack_00000048,0x38);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050f65b name=FUN_0050f65b size=26 ====

void FUN_0050f65b(void)

{
  long unaff_R15;
  undefined8 in_stack_00000020;
  void *in_stack_00000030;
  void *in_stack_00000048;
  long in_stack_000000b8;
  long in_stack_000000c0;
  long in_stack_00000190;
  
  if (in_stack_00000190 + -0x18 != unaff_R15) {
    refcount_delete_offset10();
  }
  json_value_destruct(in_stack_00000020);
  if (in_stack_000000c0 + -0x18 != unaff_R15) {
    refcount_delete_offset10();
  }
  if (in_stack_000000b8 + -0x18 != unaff_R15) {
    refcount_delete_offset10();
  }
  if (in_stack_00000030 != (void *)0x0) {
    completion_entry_dtor(in_stack_00000030);
    operator_delete(in_stack_00000030,0x88);
  }
  if (in_stack_00000048 != (void *)0x0) {
    FUN_00a114bc(in_stack_00000048);
    operator_delete(in_stack_00000048,0x38);
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050f675 name=FUN_0050f675 size=14 ====

void FUN_0050f675(void)

{
  void *pvVar1;
  long unaff_R15;
  undefined8 in_stack_00000020;
  void *in_stack_00000030;
  void *pvStack0000000000000048;
  long in_stack_000000b8;
  long in_stack_000000c0;
  
  pvStack0000000000000048 = (void *)0x0;
  json_value_destruct(in_stack_00000020);
  if (in_stack_000000c0 + -0x18 != unaff_R15) {
    refcount_delete_offset10();
  }
  if (in_stack_000000b8 + -0x18 != unaff_R15) {
    refcount_delete_offset10();
  }
  if (in_stack_00000030 != (void *)0x0) {
    completion_entry_dtor(in_stack_00000030);
    operator_delete(in_stack_00000030,0x88);
  }
  pvVar1 = pvStack0000000000000048;
  if (pvStack0000000000000048 != (void *)0x0) {
    FUN_00a114bc(pvStack0000000000000048);
    operator_delete(pvVar1,0x38);
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050f683 name=FUN_0050f683 size=26 ====

void FUN_0050f683(void)

{
  locale *unaff_RBX;
  long unaff_R15;
  locale *in_stack_00000020;
  void *in_stack_00000030;
  void *in_stack_00000048;
  long in_stack_000000b8;
  long in_stack_000000c0;
  
  std::locale::~locale(in_stack_00000020);
  std::locale::~locale(unaff_RBX);
  if (in_stack_000000c0 + -0x18 != unaff_R15) {
    refcount_delete_offset10();
  }
  if (in_stack_000000b8 + -0x18 != unaff_R15) {
    refcount_delete_offset10();
  }
  if (in_stack_00000030 != (void *)0x0) {
    completion_entry_dtor(in_stack_00000030);
    operator_delete(in_stack_00000030,0x88);
  }
  if (in_stack_00000048 != (void *)0x0) {
    FUN_00a114bc(in_stack_00000048);
    operator_delete(in_stack_00000048,0x38);
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050f69d name=FUN_0050f69d size=16 ====

void FUN_0050f69d(void)

{
  long unaff_R15;
  undefined8 in_stack_00000028;
  void *in_stack_00000030;
  void *in_stack_00000048;
  long in_stack_000000b8;
  long in_stack_000000c0;
  
  json_value_destruct();
  json_value_destruct(in_stack_00000028);
  if (in_stack_000000c0 + -0x18 != unaff_R15) {
    refcount_delete_offset10();
  }
  if (in_stack_000000b8 + -0x18 != unaff_R15) {
    refcount_delete_offset10();
  }
  if (in_stack_00000030 != (void *)0x0) {
    completion_entry_dtor(in_stack_00000030);
    operator_delete(in_stack_00000030,0x88);
  }
  if (in_stack_00000048 != (void *)0x0) {
    FUN_00a114bc(in_stack_00000048);
    operator_delete(in_stack_00000048,0x38);
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050f6ad name=FUN_0050f6ad size=36 ====

void FUN_0050f6ad(void)

{
  long unaff_R15;
  undefined8 in_stack_00000018;
  undefined8 in_stack_00000020;
  undefined8 in_stack_00000028;
  void *in_stack_00000030;
  void *in_stack_00000048;
  long in_stack_000000b8;
  long in_stack_000000c0;
  
  qt_byte_array_unref();
  string_vector_destroy(in_stack_00000018);
  json_value_destruct(in_stack_00000028);
  json_value_destruct(in_stack_00000020);
  if (in_stack_000000c0 + -0x18 != unaff_R15) {
    refcount_delete_offset10();
  }
  if (in_stack_000000b8 + -0x18 != unaff_R15) {
    refcount_delete_offset10();
  }
  if (in_stack_00000030 != (void *)0x0) {
    completion_entry_dtor(in_stack_00000030);
    operator_delete(in_stack_00000030,0x88);
  }
  if (in_stack_00000048 != (void *)0x0) {
    FUN_00a114bc(in_stack_00000048);
    operator_delete(in_stack_00000048,0x38);
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050f6d1 name=FUN_0050f6d1 size=13 ====

void FUN_0050f6d1(void)

{
  long unaff_R15;
  undefined8 in_stack_00000020;
  undefined8 in_stack_00000028;
  void *in_stack_00000030;
  void *in_stack_00000048;
  long in_stack_000000b8;
  long in_stack_000000c0;
  
  json_value_destruct();
  json_value_destruct(in_stack_00000028);
  json_value_destruct(in_stack_00000020);
  if (in_stack_000000c0 + -0x18 != unaff_R15) {
    refcount_delete_offset10();
  }
  if (in_stack_000000b8 + -0x18 != unaff_R15) {
    refcount_delete_offset10();
  }
  if (in_stack_00000030 != (void *)0x0) {
    completion_entry_dtor(in_stack_00000030);
    operator_delete(in_stack_00000030,0x88);
  }
  if (in_stack_00000048 != (void *)0x0) {
    FUN_00a114bc(in_stack_00000048);
    operator_delete(in_stack_00000048,0x38);
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050f6de name=FUN_0050f6de size=26 ====

void FUN_0050f6de(void)

{
  undefined8 in_stack_00000028;
  
  json_value_destruct();
  json_value_destruct(in_stack_00000028);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050f6f8 name=FUN_0050f6f8 size=23 ====

void FUN_0050f6f8(void)

{
  void *in_stack_00000048;
  
  operator_delete(in_stack_00000048,0x38);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050f70f name=FUN_0050f70f size=16 ====

void FUN_0050f70f(void)

{
  long unaff_R15;
  undefined8 in_stack_00000028;
  void *in_stack_00000030;
  void *in_stack_00000048;
  long in_stack_000000b8;
  long in_stack_000000c0;
  
  json_value_destruct();
  json_value_destruct(in_stack_00000028);
  if (in_stack_000000c0 + -0x18 != unaff_R15) {
    refcount_delete_offset10();
  }
  if (in_stack_000000b8 + -0x18 != unaff_R15) {
    refcount_delete_offset10();
  }
  if (in_stack_00000030 != (void *)0x0) {
    completion_entry_dtor(in_stack_00000030);
    operator_delete(in_stack_00000030,0x88);
  }
  if (in_stack_00000048 != (void *)0x0) {
    FUN_00a114bc(in_stack_00000048);
    operator_delete(in_stack_00000048,0x38);
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050f71f name=FUN_0050f71f size=31 ====

void FUN_0050f71f(void)

{
  long unaff_R15;
  undefined8 in_stack_00000018;
  undefined8 in_stack_00000020;
  undefined8 in_stack_00000028;
  void *in_stack_00000030;
  void *in_stack_00000048;
  long in_stack_000000b8;
  long in_stack_000000c0;
  long in_stack_00000100;
  
  if (in_stack_00000100 + -0x18 != unaff_R15) {
    refcount_delete_offset10();
  }
  json_value_destruct();
  string_vector_destroy(in_stack_00000018);
  json_value_destruct(in_stack_00000028);
  json_value_destruct(in_stack_00000020);
  if (in_stack_000000c0 + -0x18 != unaff_R15) {
    refcount_delete_offset10();
  }
  if (in_stack_000000b8 + -0x18 != unaff_R15) {
    refcount_delete_offset10();
  }
  if (in_stack_00000030 != (void *)0x0) {
    completion_entry_dtor(in_stack_00000030);
    operator_delete(in_stack_00000030,0x88);
  }
  if (in_stack_00000048 != (void *)0x0) {
    FUN_00a114bc(in_stack_00000048);
    operator_delete(in_stack_00000048,0x38);
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050f73e name=FUN_0050f73e size=18 ====

void FUN_0050f73e(void)

{
  void *unaff_R13;
  long unaff_R15;
  void *in_stack_00000030;
  void *in_stack_00000048;
  long in_stack_000000b8;
  long in_stack_000000c0;
  
  operator_delete(unaff_R13,8);
  if (in_stack_000000c0 + -0x18 != unaff_R15) {
    refcount_delete_offset10();
  }
  if (in_stack_000000b8 + -0x18 != unaff_R15) {
    refcount_delete_offset10();
  }
  if (in_stack_00000030 != (void *)0x0) {
    completion_entry_dtor(in_stack_00000030);
    operator_delete(in_stack_00000030,0x88);
  }
  if (in_stack_00000048 != (void *)0x0) {
    FUN_00a114bc(in_stack_00000048);
    operator_delete(in_stack_00000048,0x38);
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050f750 name=FUN_0050f750 size=27 ====

void FUN_0050f750(void)

{
  long unaff_RBX;
  long in_stack_00000008;
  
  if (in_stack_00000008 + -0x18 != unaff_RBX) {
    refcount_delete_offset10();
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050f76c name=FUN_0050f76c size=193 ====

/* WARNING: Removing unreachable block (ram,0x0050f9c4) */
/* WARNING: Removing unreachable block (ram,0x0050f9cf) */

void FUN_0050f76c(void)

{
  long *plVar1;
  int *piVar2;
  int iVar3;
  long lVar4;
  long lVar5;
  long *plVar6;
  long *unaff_R12;
  void *unaff_R13;
  long unaff_R15;
  long lVar7;
  undefined8 in_stack_00000008;
  undefined8 in_stack_00000040;
  undefined8 in_stack_00000048;
  undefined8 in_stack_00000050;
  long in_stack_00000098;
  
  json_value_destruct();
  if (in_stack_00000098 + -0x18 != unaff_R15) {
    refcount_delete_offset10();
  }
  json_value_destruct(in_stack_00000008);
  plVar6 = (long *)&stack0x00000170;
  do {
    plVar6 = plVar6 + -1;
    if (*plVar6 + -0x18 != unaff_R15) {
      refcount_delete_offset10();
    }
  } while (plVar6 != unaff_R12);
  qt_byte_array_unref(in_stack_00000040);
  qt_byte_array_unref(in_stack_00000050);
  json_value_destruct(in_stack_00000048);
  if (unaff_R13 != (void *)0x0) {
    lVar4 = *(long *)((long)unaff_R13 + 0x18);
    for (lVar7 = *(long *)((long)unaff_R13 + 0x10); lVar4 != lVar7; lVar7 = lVar7 + 0x18) {
      plVar6 = *(long **)(lVar7 + 8);
      if (plVar6 != (long *)0x0) {
        LOCK();
        plVar1 = plVar6 + 1;
        lVar5 = *plVar1;
        *(int *)plVar1 = (int)*plVar1 + -1;
        UNLOCK();
        if ((int)lVar5 == 1) {
          (**(code **)(*plVar6 + 0x10))(plVar6);
          LOCK();
          piVar2 = (int *)((long)plVar6 + 0xc);
          iVar3 = *piVar2;
          *piVar2 = *piVar2 + -1;
          UNLOCK();
          if (iVar3 == 1) {
            (**(code **)(*plVar6 + 0x18))(plVar6);
          }
        }
      }
    }
    if (*(void **)((long)unaff_R13 + 0x10) != (void *)0x0) {
      operator_delete(*(void **)((long)unaff_R13 + 0x10));
    }
    if (*(undefined1 **)((long)unaff_R13 + 8) != &DAT_011c5338) {
      refcount_delete_offset10();
    }
    operator_delete(unaff_R13,0x28);
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050f82d name=FUN_0050f82d size=53 ====

/* WARNING: Removing unreachable block (ram,0x0050f9c4) */
/* WARNING: Removing unreachable block (ram,0x0050f9cf) */

void FUN_0050f82d(void)

{
  long *plVar1;
  int *piVar2;
  int iVar3;
  long lVar4;
  long *plVar5;
  long lVar6;
  undefined8 *puVar7;
  undefined8 *unaff_R12;
  void *unaff_R13;
  long lVar8;
  undefined8 in_stack_00000040;
  undefined8 in_stack_00000048;
  undefined8 in_stack_00000050;
  
  puVar7 = unaff_R12 + 7;
  while (puVar7 != unaff_R12) {
    puVar7 = puVar7 + -1;
    if ((undefined1 *)*puVar7 != &DAT_011c5338) {
      refcount_delete_offset10();
    }
  }
  qt_byte_array_unref(in_stack_00000040);
  qt_byte_array_unref(in_stack_00000050);
  json_value_destruct(in_stack_00000048);
  if (unaff_R13 != (void *)0x0) {
    lVar4 = *(long *)((long)unaff_R13 + 0x18);
    for (lVar8 = *(long *)((long)unaff_R13 + 0x10); lVar4 != lVar8; lVar8 = lVar8 + 0x18) {
      plVar5 = *(long **)(lVar8 + 8);
      if (plVar5 != (long *)0x0) {
        LOCK();
        plVar1 = plVar5 + 1;
        lVar6 = *plVar1;
        *(int *)plVar1 = (int)*plVar1 + -1;
        UNLOCK();
        if ((int)lVar6 == 1) {
          (**(code **)(*plVar5 + 0x10))(plVar5);
          LOCK();
          piVar2 = (int *)((long)plVar5 + 0xc);
          iVar3 = *piVar2;
          *piVar2 = *piVar2 + -1;
          UNLOCK();
          if (iVar3 == 1) {
            (**(code **)(*plVar5 + 0x18))(plVar5);
          }
        }
      }
    }
    if (*(void **)((long)unaff_R13 + 0x10) != (void *)0x0) {
      operator_delete(*(void **)((long)unaff_R13 + 0x10));
    }
    if (*(undefined1 **)((long)unaff_R13 + 8) != &DAT_011c5338) {
      refcount_delete_offset10();
    }
    operator_delete(unaff_R13,0x28);
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050f862 name=FUN_0050f862 size=66 ====

/* WARNING: Removing unreachable block (ram,0x0050f9c4) */
/* WARNING: Removing unreachable block (ram,0x0050f9cf) */

void FUN_0050f862(void)

{
  long *plVar1;
  int *piVar2;
  int iVar3;
  long lVar4;
  long lVar5;
  long *plVar6;
  long *unaff_R12;
  void *unaff_R13;
  long unaff_R15;
  long lVar7;
  undefined8 in_stack_00000040;
  undefined8 in_stack_00000048;
  undefined8 in_stack_00000050;
  long in_stack_00000090;
  _Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *in_stack_000000d8;
  _Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *in_stack_00000108;
  
  if (in_stack_000000d8 != (_Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *)0x0) {
    std::_Sp_counted_base<(__gnu_cxx::_Lock_policy)2>::_M_release(in_stack_000000d8);
  }
  if (in_stack_00000108 != (_Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *)0x0) {
    std::_Sp_counted_base<(__gnu_cxx::_Lock_policy)2>::_M_release(in_stack_00000108);
  }
  if (in_stack_00000090 + -0x18 != unaff_R15) {
    refcount_delete_offset10();
  }
  plVar6 = (long *)&stack0x00000170;
  do {
    plVar6 = plVar6 + -1;
    if (*plVar6 + -0x18 != unaff_R15) {
      refcount_delete_offset10();
    }
  } while (plVar6 != unaff_R12);
  qt_byte_array_unref(in_stack_00000040);
  qt_byte_array_unref(in_stack_00000050);
  json_value_destruct(in_stack_00000048);
  if (unaff_R13 != (void *)0x0) {
    lVar4 = *(long *)((long)unaff_R13 + 0x18);
    for (lVar7 = *(long *)((long)unaff_R13 + 0x10); lVar4 != lVar7; lVar7 = lVar7 + 0x18) {
      plVar6 = *(long **)(lVar7 + 8);
      if (plVar6 != (long *)0x0) {
        LOCK();
        plVar1 = plVar6 + 1;
        lVar5 = *plVar1;
        *(int *)plVar1 = (int)*plVar1 + -1;
        UNLOCK();
        if ((int)lVar5 == 1) {
          (**(code **)(*plVar6 + 0x10))(plVar6);
          LOCK();
          piVar2 = (int *)((long)plVar6 + 0xc);
          iVar3 = *piVar2;
          *piVar2 = *piVar2 + -1;
          UNLOCK();
          if (iVar3 == 1) {
            (**(code **)(*plVar6 + 0x18))(plVar6);
          }
        }
      }
    }
    if (*(void **)((long)unaff_R13 + 0x10) != (void *)0x0) {
      operator_delete(*(void **)((long)unaff_R13 + 0x10));
    }
    if (*(undefined1 **)((long)unaff_R13 + 8) != &DAT_011c5338) {
      refcount_delete_offset10();
    }
    operator_delete(unaff_R13,0x28);
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050f8a4 name=FUN_0050f8a4 size=38 ====

/* WARNING: Removing unreachable block (ram,0x0050f9c4) */
/* WARNING: Removing unreachable block (ram,0x0050f9cf) */

void FUN_0050f8a4(void)

{
  long *plVar1;
  int *piVar2;
  int iVar3;
  long lVar4;
  long lVar5;
  long *plVar6;
  long *unaff_R12;
  void *unaff_R13;
  long unaff_R15;
  long lVar7;
  undefined8 in_stack_00000040;
  undefined8 in_stack_00000048;
  undefined8 in_stack_00000050;
  _Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *in_stack_000000d8;
  _Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *in_stack_00000108;
  
  if (in_stack_00000108 != (_Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *)0x0) {
    std::_Sp_counted_base<(__gnu_cxx::_Lock_policy)2>::_M_release(in_stack_00000108);
  }
  if (in_stack_000000d8 != (_Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *)0x0) {
    std::_Sp_counted_base<(__gnu_cxx::_Lock_policy)2>::_M_release(in_stack_000000d8);
  }
  plVar6 = (long *)&stack0x00000170;
  do {
    plVar6 = plVar6 + -1;
    if (*plVar6 + -0x18 != unaff_R15) {
      refcount_delete_offset10();
    }
  } while (plVar6 != unaff_R12);
  qt_byte_array_unref(in_stack_00000040);
  qt_byte_array_unref(in_stack_00000050);
  json_value_destruct(in_stack_00000048);
  if (unaff_R13 != (void *)0x0) {
    lVar4 = *(long *)((long)unaff_R13 + 0x18);
    for (lVar7 = *(long *)((long)unaff_R13 + 0x10); lVar4 != lVar7; lVar7 = lVar7 + 0x18) {
      plVar6 = *(long **)(lVar7 + 8);
      if (plVar6 != (long *)0x0) {
        LOCK();
        plVar1 = plVar6 + 1;
        lVar5 = *plVar1;
        *(int *)plVar1 = (int)*plVar1 + -1;
        UNLOCK();
        if ((int)lVar5 == 1) {
          (**(code **)(*plVar6 + 0x10))(plVar6);
          LOCK();
          piVar2 = (int *)((long)plVar6 + 0xc);
          iVar3 = *piVar2;
          *piVar2 = *piVar2 + -1;
          UNLOCK();
          if (iVar3 == 1) {
            (**(code **)(*plVar6 + 0x18))(plVar6);
          }
        }
      }
    }
    if (*(void **)((long)unaff_R13 + 0x10) != (void *)0x0) {
      operator_delete(*(void **)((long)unaff_R13 + 0x10));
    }
    if (*(undefined1 **)((long)unaff_R13 + 8) != &DAT_011c5338) {
      refcount_delete_offset10();
    }
    operator_delete(unaff_R13,0x28);
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050f8ca name=FUN_0050f8ca size=21 ====

/* WARNING: Removing unreachable block (ram,0x0050f9c4) */
/* WARNING: Removing unreachable block (ram,0x0050f9cf) */

void FUN_0050f8ca(void)

{
  long *plVar1;
  int *piVar2;
  int iVar3;
  long lVar4;
  long lVar5;
  long *plVar6;
  long *unaff_R12;
  void *unaff_R13;
  long unaff_R15;
  long lVar7;
  undefined8 in_stack_00000040;
  undefined8 in_stack_00000048;
  undefined8 in_stack_00000050;
  
  json_value_destruct();
  json_value_destruct();
  plVar6 = (long *)&stack0x00000170;
  do {
    plVar6 = plVar6 + -1;
    if (*plVar6 + -0x18 != unaff_R15) {
      refcount_delete_offset10();
    }
  } while (plVar6 != unaff_R12);
  qt_byte_array_unref(in_stack_00000040);
  qt_byte_array_unref(in_stack_00000050);
  json_value_destruct(in_stack_00000048);
  if (unaff_R13 != (void *)0x0) {
    lVar4 = *(long *)((long)unaff_R13 + 0x18);
    for (lVar7 = *(long *)((long)unaff_R13 + 0x10); lVar4 != lVar7; lVar7 = lVar7 + 0x18) {
      plVar6 = *(long **)(lVar7 + 8);
      if (plVar6 != (long *)0x0) {
        LOCK();
        plVar1 = plVar6 + 1;
        lVar5 = *plVar1;
        *(int *)plVar1 = (int)*plVar1 + -1;
        UNLOCK();
        if ((int)lVar5 == 1) {
          (**(code **)(*plVar6 + 0x10))(plVar6);
          LOCK();
          piVar2 = (int *)((long)plVar6 + 0xc);
          iVar3 = *piVar2;
          *piVar2 = *piVar2 + -1;
          UNLOCK();
          if (iVar3 == 1) {
            (**(code **)(*plVar6 + 0x18))(plVar6);
          }
        }
      }
    }
    if (*(void **)((long)unaff_R13 + 0x10) != (void *)0x0) {
      operator_delete(*(void **)((long)unaff_R13 + 0x10));
    }
    if (*(undefined1 **)((long)unaff_R13 + 8) != &DAT_011c5338) {
      refcount_delete_offset10();
    }
    operator_delete(unaff_R13,0x28);
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050f8df name=FUN_0050f8df size=24 ====

/* WARNING: Removing unreachable block (ram,0x0050f7e3) */
/* WARNING: Removing unreachable block (ram,0x0050f9c4) */
/* WARNING: Removing unreachable block (ram,0x0050f990) */
/* WARNING: Removing unreachable block (ram,0x0050f995) */
/* WARNING: Removing unreachable block (ram,0x0050f9cf) */
/* WARNING: Removing unreachable block (ram,0x0050f9a4) */
/* WARNING: Removing unreachable block (ram,0x0050f9ac) */
/* WARNING: Removing unreachable block (ram,0x0050f9b1) */
/* WARNING: Removing unreachable block (ram,0x0050f9bb) */
/* WARNING: Removing unreachable block (ram,0x0050f7eb) */
/* WARNING: Removing unreachable block (ram,0x0050f973) */
/* WARNING: Removing unreachable block (ram,0x0050f97c) */
/* WARNING: Removing unreachable block (ram,0x0050f988) */
/* WARNING: Removing unreachable block (ram,0x0050f7f4) */
/* WARNING: Removing unreachable block (ram,0x0050f7fd) */
/* WARNING: Removing unreachable block (ram,0x0050f802) */
/* WARNING: Removing unreachable block (ram,0x0050f813) */
/* WARNING: Removing unreachable block (ram,0x0050f818) */

void FUN_0050f8df(void)

{
  long *plVar1;
  void *unaff_RBX;
  long *unaff_R12;
  long unaff_R15;
  undefined8 in_stack_00000040;
  undefined8 in_stack_00000048;
  undefined8 in_stack_00000050;
  
  operator_delete(unaff_RBX,0x20);
  plVar1 = (long *)&stack0x00000170;
  do {
    plVar1 = plVar1 + -1;
    if (*plVar1 + -0x18 != unaff_R15) {
      refcount_delete_offset10();
    }
  } while (plVar1 != unaff_R12);
  qt_byte_array_unref(in_stack_00000040);
  qt_byte_array_unref(in_stack_00000050);
  json_value_destruct(in_stack_00000048);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050f8f7 name=FUN_0050f8f7 size=10 ====

/* WARNING: Removing unreachable block (ram,0x0050f9c4) */
/* WARNING: Removing unreachable block (ram,0x0050f9cf) */

void FUN_0050f8f7(void)

{
  long *plVar1;
  int *piVar2;
  int iVar3;
  long lVar4;
  long *plVar5;
  long lVar6;
  undefined8 *puVar7;
  undefined8 *unaff_R12;
  void *unaff_R13;
  long lVar8;
  undefined8 in_stack_00000040;
  undefined8 in_stack_00000048;
  undefined8 in_stack_00000050;
  
  puVar7 = unaff_R12 + 3;
  while (puVar7 != unaff_R12) {
    puVar7 = puVar7 + -1;
    if ((undefined1 *)*puVar7 != &DAT_011c5338) {
      refcount_delete_offset10();
    }
  }
  qt_byte_array_unref(in_stack_00000040);
  qt_byte_array_unref(in_stack_00000050);
  json_value_destruct(in_stack_00000048);
  if (unaff_R13 != (void *)0x0) {
    lVar4 = *(long *)((long)unaff_R13 + 0x18);
    for (lVar8 = *(long *)((long)unaff_R13 + 0x10); lVar4 != lVar8; lVar8 = lVar8 + 0x18) {
      plVar5 = *(long **)(lVar8 + 8);
      if (plVar5 != (long *)0x0) {
        LOCK();
        plVar1 = plVar5 + 1;
        lVar6 = *plVar1;
        *(int *)plVar1 = (int)*plVar1 + -1;
        UNLOCK();
        if ((int)lVar6 == 1) {
          (**(code **)(*plVar5 + 0x10))(plVar5);
          LOCK();
          piVar2 = (int *)((long)plVar5 + 0xc);
          iVar3 = *piVar2;
          *piVar2 = *piVar2 + -1;
          UNLOCK();
          if (iVar3 == 1) {
            (**(code **)(*plVar5 + 0x18))(plVar5);
          }
        }
      }
    }
    if (*(void **)((long)unaff_R13 + 0x10) != (void *)0x0) {
      operator_delete(*(void **)((long)unaff_R13 + 0x10));
    }
    if (*(undefined1 **)((long)unaff_R13 + 8) != &DAT_011c5338) {
      refcount_delete_offset10();
    }
    operator_delete(unaff_R13,0x28);
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050f901 name=FUN_0050f901 size=10 ====

/* WARNING: Removing unreachable block (ram,0x0050f9c4) */
/* WARNING: Removing unreachable block (ram,0x0050f9cf) */

void FUN_0050f901(void)

{
  long *plVar1;
  int *piVar2;
  int iVar3;
  long lVar4;
  long *plVar5;
  long lVar6;
  undefined8 *puVar7;
  undefined8 *unaff_R12;
  void *unaff_R13;
  long lVar8;
  undefined8 in_stack_00000040;
  undefined8 in_stack_00000048;
  undefined8 in_stack_00000050;
  
  puVar7 = unaff_R12 + 2;
  while (puVar7 != unaff_R12) {
    puVar7 = puVar7 + -1;
    if ((undefined1 *)*puVar7 != &DAT_011c5338) {
      refcount_delete_offset10();
    }
  }
  qt_byte_array_unref(in_stack_00000040);
  qt_byte_array_unref(in_stack_00000050);
  json_value_destruct(in_stack_00000048);
  if (unaff_R13 != (void *)0x0) {
    lVar4 = *(long *)((long)unaff_R13 + 0x18);
    for (lVar8 = *(long *)((long)unaff_R13 + 0x10); lVar4 != lVar8; lVar8 = lVar8 + 0x18) {
      plVar5 = *(long **)(lVar8 + 8);
      if (plVar5 != (long *)0x0) {
        LOCK();
        plVar1 = plVar5 + 1;
        lVar6 = *plVar1;
        *(int *)plVar1 = (int)*plVar1 + -1;
        UNLOCK();
        if ((int)lVar6 == 1) {
          (**(code **)(*plVar5 + 0x10))(plVar5);
          LOCK();
          piVar2 = (int *)((long)plVar5 + 0xc);
          iVar3 = *piVar2;
          *piVar2 = *piVar2 + -1;
          UNLOCK();
          if (iVar3 == 1) {
            (**(code **)(*plVar5 + 0x18))(plVar5);
          }
        }
      }
    }
    if (*(void **)((long)unaff_R13 + 0x10) != (void *)0x0) {
      operator_delete(*(void **)((long)unaff_R13 + 0x10));
    }
    if (*(undefined1 **)((long)unaff_R13 + 8) != &DAT_011c5338) {
      refcount_delete_offset10();
    }
    operator_delete(unaff_R13,0x28);
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050f90b name=FUN_0050f90b size=10 ====

/* WARNING: Removing unreachable block (ram,0x0050f9c4) */
/* WARNING: Removing unreachable block (ram,0x0050f9cf) */

void FUN_0050f90b(void)

{
  long *plVar1;
  int *piVar2;
  int iVar3;
  long lVar4;
  long lVar5;
  long *plVar6;
  long *unaff_R12;
  void *unaff_R13;
  long unaff_R15;
  long lVar7;
  undefined8 in_stack_00000040;
  undefined8 in_stack_00000048;
  undefined8 in_stack_00000050;
  
  json_value_destruct();
  json_value_destruct();
  plVar6 = (long *)&stack0x00000170;
  do {
    plVar6 = plVar6 + -1;
    if (*plVar6 + -0x18 != unaff_R15) {
      refcount_delete_offset10();
    }
  } while (plVar6 != unaff_R12);
  qt_byte_array_unref(in_stack_00000040);
  qt_byte_array_unref(in_stack_00000050);
  json_value_destruct(in_stack_00000048);
  if (unaff_R13 != (void *)0x0) {
    lVar4 = *(long *)((long)unaff_R13 + 0x18);
    for (lVar7 = *(long *)((long)unaff_R13 + 0x10); lVar4 != lVar7; lVar7 = lVar7 + 0x18) {
      plVar6 = *(long **)(lVar7 + 8);
      if (plVar6 != (long *)0x0) {
        LOCK();
        plVar1 = plVar6 + 1;
        lVar5 = *plVar1;
        *(int *)plVar1 = (int)*plVar1 + -1;
        UNLOCK();
        if ((int)lVar5 == 1) {
          (**(code **)(*plVar6 + 0x10))(plVar6);
          LOCK();
          piVar2 = (int *)((long)plVar6 + 0xc);
          iVar3 = *piVar2;
          *piVar2 = *piVar2 + -1;
          UNLOCK();
          if (iVar3 == 1) {
            (**(code **)(*plVar6 + 0x18))(plVar6);
          }
        }
      }
    }
    if (*(void **)((long)unaff_R13 + 0x10) != (void *)0x0) {
      operator_delete(*(void **)((long)unaff_R13 + 0x10));
    }
    if (*(undefined1 **)((long)unaff_R13 + 8) != &DAT_011c5338) {
      refcount_delete_offset10();
    }
    operator_delete(unaff_R13,0x28);
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050f915 name=FUN_0050f915 size=13 ====

/* WARNING: Removing unreachable block (ram,0x0050f9c4) */
/* WARNING: Removing unreachable block (ram,0x0050f9cf) */

void FUN_0050f915(void)

{
  long *plVar1;
  int *piVar2;
  int iVar3;
  long lVar4;
  long lVar5;
  long *plVar6;
  long *unaff_R12;
  void *unaff_R13;
  long unaff_R15;
  long lVar7;
  undefined8 in_stack_00000040;
  undefined8 in_stack_00000048;
  undefined8 in_stack_00000050;
  
  json_value_destruct();
  json_value_destruct();
  plVar6 = (long *)&stack0x00000170;
  do {
    plVar6 = plVar6 + -1;
    if (*plVar6 + -0x18 != unaff_R15) {
      refcount_delete_offset10();
    }
  } while (plVar6 != unaff_R12);
  qt_byte_array_unref(in_stack_00000040);
  qt_byte_array_unref(in_stack_00000050);
  json_value_destruct(in_stack_00000048);
  if (unaff_R13 != (void *)0x0) {
    lVar4 = *(long *)((long)unaff_R13 + 0x18);
    for (lVar7 = *(long *)((long)unaff_R13 + 0x10); lVar4 != lVar7; lVar7 = lVar7 + 0x18) {
      plVar6 = *(long **)(lVar7 + 8);
      if (plVar6 != (long *)0x0) {
        LOCK();
        plVar1 = plVar6 + 1;
        lVar5 = *plVar1;
        *(int *)plVar1 = (int)*plVar1 + -1;
        UNLOCK();
        if ((int)lVar5 == 1) {
          (**(code **)(*plVar6 + 0x10))(plVar6);
          LOCK();
          piVar2 = (int *)((long)plVar6 + 0xc);
          iVar3 = *piVar2;
          *piVar2 = *piVar2 + -1;
          UNLOCK();
          if (iVar3 == 1) {
            (**(code **)(*plVar6 + 0x18))(plVar6);
          }
        }
      }
    }
    if (*(void **)((long)unaff_R13 + 0x10) != (void *)0x0) {
      operator_delete(*(void **)((long)unaff_R13 + 0x10));
    }
    if (*(undefined1 **)((long)unaff_R13 + 8) != &DAT_011c5338) {
      refcount_delete_offset10();
    }
    operator_delete(unaff_R13,0x28);
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050f922 name=FUN_0050f922 size=10 ====

/* WARNING: Removing unreachable block (ram,0x0050f9c4) */
/* WARNING: Removing unreachable block (ram,0x0050f9cf) */

void FUN_0050f922(void)

{
  long *plVar1;
  int *piVar2;
  int iVar3;
  long lVar4;
  long lVar5;
  long *plVar6;
  long *unaff_R12;
  void *unaff_R13;
  long unaff_R15;
  long lVar7;
  undefined8 in_stack_00000040;
  undefined8 in_stack_00000048;
  undefined8 in_stack_00000050;
  
  json_value_destruct();
  json_value_destruct();
  plVar6 = (long *)&stack0x00000170;
  do {
    plVar6 = plVar6 + -1;
    if (*plVar6 + -0x18 != unaff_R15) {
      refcount_delete_offset10();
    }
  } while (plVar6 != unaff_R12);
  qt_byte_array_unref(in_stack_00000040);
  qt_byte_array_unref(in_stack_00000050);
  json_value_destruct(in_stack_00000048);
  if (unaff_R13 != (void *)0x0) {
    lVar4 = *(long *)((long)unaff_R13 + 0x18);
    for (lVar7 = *(long *)((long)unaff_R13 + 0x10); lVar4 != lVar7; lVar7 = lVar7 + 0x18) {
      plVar6 = *(long **)(lVar7 + 8);
      if (plVar6 != (long *)0x0) {
        LOCK();
        plVar1 = plVar6 + 1;
        lVar5 = *plVar1;
        *(int *)plVar1 = (int)*plVar1 + -1;
        UNLOCK();
        if ((int)lVar5 == 1) {
          (**(code **)(*plVar6 + 0x10))(plVar6);
          LOCK();
          piVar2 = (int *)((long)plVar6 + 0xc);
          iVar3 = *piVar2;
          *piVar2 = *piVar2 + -1;
          UNLOCK();
          if (iVar3 == 1) {
            (**(code **)(*plVar6 + 0x18))(plVar6);
          }
        }
      }
    }
    if (*(void **)((long)unaff_R13 + 0x10) != (void *)0x0) {
      operator_delete(*(void **)((long)unaff_R13 + 0x10));
    }
    if (*(undefined1 **)((long)unaff_R13 + 8) != &DAT_011c5338) {
      refcount_delete_offset10();
    }
    operator_delete(unaff_R13,0x28);
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050f92c name=FUN_0050f92c size=21 ====

void FUN_0050f92c(void)

{
  void *unaff_R13;
  
  operator_delete(unaff_R13,0x28);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050f941 name=FUN_0050f941 size=10 ====

/* WARNING: Removing unreachable block (ram,0x0050f9c4) */
/* WARNING: Removing unreachable block (ram,0x0050f9cf) */

void FUN_0050f941(void)

{
  long *plVar1;
  int *piVar2;
  int iVar3;
  long lVar4;
  long *plVar5;
  long lVar6;
  undefined8 *puVar7;
  undefined8 *unaff_R12;
  void *unaff_R13;
  long lVar8;
  undefined8 in_stack_00000040;
  undefined8 in_stack_00000048;
  undefined8 in_stack_00000050;
  
  puVar7 = unaff_R12 + 5;
  while (puVar7 != unaff_R12) {
    puVar7 = puVar7 + -1;
    if ((undefined1 *)*puVar7 != &DAT_011c5338) {
      refcount_delete_offset10();
    }
  }
  qt_byte_array_unref(in_stack_00000040);
  qt_byte_array_unref(in_stack_00000050);
  json_value_destruct(in_stack_00000048);
  if (unaff_R13 != (void *)0x0) {
    lVar4 = *(long *)((long)unaff_R13 + 0x18);
    for (lVar8 = *(long *)((long)unaff_R13 + 0x10); lVar4 != lVar8; lVar8 = lVar8 + 0x18) {
      plVar5 = *(long **)(lVar8 + 8);
      if (plVar5 != (long *)0x0) {
        LOCK();
        plVar1 = plVar5 + 1;
        lVar6 = *plVar1;
        *(int *)plVar1 = (int)*plVar1 + -1;
        UNLOCK();
        if ((int)lVar6 == 1) {
          (**(code **)(*plVar5 + 0x10))(plVar5);
          LOCK();
          piVar2 = (int *)((long)plVar5 + 0xc);
          iVar3 = *piVar2;
          *piVar2 = *piVar2 + -1;
          UNLOCK();
          if (iVar3 == 1) {
            (**(code **)(*plVar5 + 0x18))(plVar5);
          }
        }
      }
    }
    if (*(void **)((long)unaff_R13 + 0x10) != (void *)0x0) {
      operator_delete(*(void **)((long)unaff_R13 + 0x10));
    }
    if (*(undefined1 **)((long)unaff_R13 + 8) != &DAT_011c5338) {
      refcount_delete_offset10();
    }
    operator_delete(unaff_R13,0x28);
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050f94b name=FUN_0050f94b size=10 ====

/* WARNING: Removing unreachable block (ram,0x0050f9c4) */
/* WARNING: Removing unreachable block (ram,0x0050f9cf) */

void FUN_0050f94b(void)

{
  long *plVar1;
  int *piVar2;
  int iVar3;
  long lVar4;
  long *plVar5;
  long lVar6;
  undefined8 *puVar7;
  undefined8 *unaff_R12;
  void *unaff_R13;
  long lVar8;
  undefined8 in_stack_00000040;
  undefined8 in_stack_00000048;
  undefined8 in_stack_00000050;
  
  puVar7 = unaff_R12 + 6;
  while (puVar7 != unaff_R12) {
    puVar7 = puVar7 + -1;
    if ((undefined1 *)*puVar7 != &DAT_011c5338) {
      refcount_delete_offset10();
    }
  }
  qt_byte_array_unref(in_stack_00000040);
  qt_byte_array_unref(in_stack_00000050);
  json_value_destruct(in_stack_00000048);
  if (unaff_R13 != (void *)0x0) {
    lVar4 = *(long *)((long)unaff_R13 + 0x18);
    for (lVar8 = *(long *)((long)unaff_R13 + 0x10); lVar4 != lVar8; lVar8 = lVar8 + 0x18) {
      plVar5 = *(long **)(lVar8 + 8);
      if (plVar5 != (long *)0x0) {
        LOCK();
        plVar1 = plVar5 + 1;
        lVar6 = *plVar1;
        *(int *)plVar1 = (int)*plVar1 + -1;
        UNLOCK();
        if ((int)lVar6 == 1) {
          (**(code **)(*plVar5 + 0x10))(plVar5);
          LOCK();
          piVar2 = (int *)((long)plVar5 + 0xc);
          iVar3 = *piVar2;
          *piVar2 = *piVar2 + -1;
          UNLOCK();
          if (iVar3 == 1) {
            (**(code **)(*plVar5 + 0x18))(plVar5);
          }
        }
      }
    }
    if (*(void **)((long)unaff_R13 + 0x10) != (void *)0x0) {
      operator_delete(*(void **)((long)unaff_R13 + 0x10));
    }
    if (*(undefined1 **)((long)unaff_R13 + 8) != &DAT_011c5338) {
      refcount_delete_offset10();
    }
    operator_delete(unaff_R13,0x28);
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050f955 name=FUN_0050f955 size=10 ====

/* WARNING: Removing unreachable block (ram,0x0050f9c4) */
/* WARNING: Removing unreachable block (ram,0x0050f9cf) */

void FUN_0050f955(void)

{
  long *plVar1;
  int *piVar2;
  int iVar3;
  long lVar4;
  long *plVar5;
  long lVar6;
  undefined8 *puVar7;
  undefined8 *unaff_R12;
  void *unaff_R13;
  long lVar8;
  undefined8 in_stack_00000040;
  undefined8 in_stack_00000048;
  undefined8 in_stack_00000050;
  
  puVar7 = unaff_R12 + 4;
  while (puVar7 != unaff_R12) {
    puVar7 = puVar7 + -1;
    if ((undefined1 *)*puVar7 != &DAT_011c5338) {
      refcount_delete_offset10();
    }
  }
  qt_byte_array_unref(in_stack_00000040);
  qt_byte_array_unref(in_stack_00000050);
  json_value_destruct(in_stack_00000048);
  if (unaff_R13 != (void *)0x0) {
    lVar4 = *(long *)((long)unaff_R13 + 0x18);
    for (lVar8 = *(long *)((long)unaff_R13 + 0x10); lVar4 != lVar8; lVar8 = lVar8 + 0x18) {
      plVar5 = *(long **)(lVar8 + 8);
      if (plVar5 != (long *)0x0) {
        LOCK();
        plVar1 = plVar5 + 1;
        lVar6 = *plVar1;
        *(int *)plVar1 = (int)*plVar1 + -1;
        UNLOCK();
        if ((int)lVar6 == 1) {
          (**(code **)(*plVar5 + 0x10))(plVar5);
          LOCK();
          piVar2 = (int *)((long)plVar5 + 0xc);
          iVar3 = *piVar2;
          *piVar2 = *piVar2 + -1;
          UNLOCK();
          if (iVar3 == 1) {
            (**(code **)(*plVar5 + 0x18))(plVar5);
          }
        }
      }
    }
    if (*(void **)((long)unaff_R13 + 0x10) != (void *)0x0) {
      operator_delete(*(void **)((long)unaff_R13 + 0x10));
    }
    if (*(undefined1 **)((long)unaff_R13 + 8) != &DAT_011c5338) {
      refcount_delete_offset10();
    }
    operator_delete(unaff_R13,0x28);
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050f95f name=FUN_0050f95f size=10 ====

/* WARNING: Removing unreachable block (ram,0x0050f9c4) */
/* WARNING: Removing unreachable block (ram,0x0050f9cf) */

void FUN_0050f95f(void)

{
  long *plVar1;
  int *piVar2;
  int iVar3;
  long lVar4;
  long *plVar5;
  long lVar6;
  undefined8 *puVar7;
  undefined8 *unaff_R12;
  void *unaff_R13;
  long lVar8;
  undefined8 in_stack_00000040;
  undefined8 in_stack_00000048;
  undefined8 in_stack_00000050;
  
  puVar7 = unaff_R12 + 1;
  while (puVar7 != unaff_R12) {
    puVar7 = puVar7 + -1;
    if ((undefined1 *)*puVar7 != &DAT_011c5338) {
      refcount_delete_offset10();
    }
  }
  qt_byte_array_unref(in_stack_00000040);
  qt_byte_array_unref(in_stack_00000050);
  json_value_destruct(in_stack_00000048);
  if (unaff_R13 != (void *)0x0) {
    lVar4 = *(long *)((long)unaff_R13 + 0x18);
    for (lVar8 = *(long *)((long)unaff_R13 + 0x10); lVar4 != lVar8; lVar8 = lVar8 + 0x18) {
      plVar5 = *(long **)(lVar8 + 8);
      if (plVar5 != (long *)0x0) {
        LOCK();
        plVar1 = plVar5 + 1;
        lVar6 = *plVar1;
        *(int *)plVar1 = (int)*plVar1 + -1;
        UNLOCK();
        if ((int)lVar6 == 1) {
          (**(code **)(*plVar5 + 0x10))(plVar5);
          LOCK();
          piVar2 = (int *)((long)plVar5 + 0xc);
          iVar3 = *piVar2;
          *piVar2 = *piVar2 + -1;
          UNLOCK();
          if (iVar3 == 1) {
            (**(code **)(*plVar5 + 0x18))(plVar5);
          }
        }
      }
    }
    if (*(void **)((long)unaff_R13 + 0x10) != (void *)0x0) {
      operator_delete(*(void **)((long)unaff_R13 + 0x10));
    }
    if (*(undefined1 **)((long)unaff_R13 + 8) != &DAT_011c5338) {
      refcount_delete_offset10();
    }
    operator_delete(unaff_R13,0x28);
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050f969 name=FUN_0050f969 size=113 ====

/* WARNING: Removing unreachable block (ram,0x0050f9c4) */
/* WARNING: Removing unreachable block (ram,0x0050f9cf) */

void FUN_0050f969(void)

{
  long *plVar1;
  int *piVar2;
  int iVar3;
  long lVar4;
  long *plVar5;
  long lVar6;
  undefined8 *puVar7;
  undefined8 *unaff_R12;
  void *unaff_R13;
  long lVar8;
  undefined8 in_stack_00000040;
  undefined8 in_stack_00000048;
  undefined8 in_stack_00000050;
  
  puVar7 = unaff_R12;
  while (puVar7 != unaff_R12) {
    puVar7 = puVar7 + -1;
    if ((undefined1 *)*puVar7 != &DAT_011c5338) {
      refcount_delete_offset10();
    }
  }
  qt_byte_array_unref(in_stack_00000040);
  qt_byte_array_unref(in_stack_00000050);
  json_value_destruct(in_stack_00000048);
  if (unaff_R13 != (void *)0x0) {
    lVar4 = *(long *)((long)unaff_R13 + 0x18);
    for (lVar8 = *(long *)((long)unaff_R13 + 0x10); lVar4 != lVar8; lVar8 = lVar8 + 0x18) {
      plVar5 = *(long **)(lVar8 + 8);
      if (plVar5 != (long *)0x0) {
        LOCK();
        plVar1 = plVar5 + 1;
        lVar6 = *plVar1;
        *(int *)plVar1 = (int)*plVar1 + -1;
        UNLOCK();
        if ((int)lVar6 == 1) {
          (**(code **)(*plVar5 + 0x10))(plVar5);
          LOCK();
          piVar2 = (int *)((long)plVar5 + 0xc);
          iVar3 = *piVar2;
          *piVar2 = *piVar2 + -1;
          UNLOCK();
          if (iVar3 == 1) {
            (**(code **)(*plVar5 + 0x18))(plVar5);
          }
        }
      }
    }
    if (*(void **)((long)unaff_R13 + 0x10) != (void *)0x0) {
      operator_delete(*(void **)((long)unaff_R13 + 0x10));
    }
    if (*(undefined1 **)((long)unaff_R13 + 8) != &DAT_011c5338) {
      refcount_delete_offset10();
    }
    operator_delete(unaff_R13,0x28);
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050f9da name=FUN_0050f9da size=69 ====

void FUN_0050f9da(void)

{
  undefined8 in_stack_00000038;
  undefined8 in_stack_00000048;
  undefined1 *in_stack_00000050;
  
  json_value_destruct();
  json_value_destruct(in_stack_00000048);
  if (in_stack_00000050 != &DAT_011c5338) {
    refcount_delete_offset10();
  }
  json_value_destruct(in_stack_00000038);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050fa1f name=FUN_0050fa1f size=132 ====

void FUN_0050fa1f(void)

{
  void *unaff_RBX;
  undefined8 unaff_retaddr;
  long in_stack_00000008;
  undefined8 in_stack_00000028;
  undefined8 in_stack_00000038;
  undefined8 in_stack_00000048;
  long in_stack_00000050;
  
  json_value_destruct();
  json_value_destruct();
  json_value_destruct(unaff_retaddr);
  if (unaff_RBX != (void *)0x0) {
    if (*(void **)((long)unaff_RBX + 0x38) != (void *)0x0) {
      operator_delete(*(void **)((long)unaff_RBX + 0x38));
    }
    if (*(void **)((long)unaff_RBX + 0x20) != (void *)0x0) {
      operator_delete(*(void **)((long)unaff_RBX + 0x20));
    }
    if (*(long *)((long)unaff_RBX + 0x10) + -0x18 != in_stack_00000008) {
      refcount_delete_offset10();
    }
    if (*(long *)((long)unaff_RBX + 8) + -0x18 != in_stack_00000008) {
      refcount_delete_offset10();
    }
    operator_delete(unaff_RBX,0x50);
  }
  json_value_destruct(in_stack_00000028);
  json_value_destruct(in_stack_00000048);
  if (in_stack_00000050 + -0x18 != in_stack_00000008) {
    refcount_delete_offset10();
  }
  json_value_destruct(in_stack_00000038);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050faa3 name=FUN_0050faa3 size=24 ====

void FUN_0050faa3(void)

{
  void *unaff_RBX;
  undefined8 unaff_retaddr;
  long in_stack_00000008;
  undefined8 in_stack_00000028;
  undefined8 in_stack_00000038;
  undefined8 in_stack_00000048;
  long in_stack_00000050;
  
  json_value_destruct();
  json_value_destruct();
  json_value_destruct(unaff_retaddr);
  if (unaff_RBX != (void *)0x0) {
    if (*(void **)((long)unaff_RBX + 0x38) != (void *)0x0) {
      operator_delete(*(void **)((long)unaff_RBX + 0x38));
    }
    if (*(void **)((long)unaff_RBX + 0x20) != (void *)0x0) {
      operator_delete(*(void **)((long)unaff_RBX + 0x20));
    }
    if (*(long *)((long)unaff_RBX + 0x10) + -0x18 != in_stack_00000008) {
      refcount_delete_offset10();
    }
    if (*(long *)((long)unaff_RBX + 8) + -0x18 != in_stack_00000008) {
      refcount_delete_offset10();
    }
    operator_delete(unaff_RBX,0x50);
  }
  json_value_destruct(in_stack_00000028);
  json_value_destruct(in_stack_00000048);
  if (in_stack_00000050 + -0x18 != in_stack_00000008) {
    refcount_delete_offset10();
  }
  json_value_destruct(in_stack_00000038);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050fabb name=FUN_0050fabb size=24 ====

void FUN_0050fabb(void)

{
  void *unaff_RBX;
  undefined8 unaff_retaddr;
  long in_stack_00000008;
  undefined8 in_stack_00000028;
  undefined8 in_stack_00000038;
  undefined8 in_stack_00000048;
  long in_stack_00000050;
  
  json_value_destruct();
  json_value_destruct();
  json_value_destruct(unaff_retaddr);
  if (unaff_RBX != (void *)0x0) {
    if (*(void **)((long)unaff_RBX + 0x38) != (void *)0x0) {
      operator_delete(*(void **)((long)unaff_RBX + 0x38));
    }
    if (*(void **)((long)unaff_RBX + 0x20) != (void *)0x0) {
      operator_delete(*(void **)((long)unaff_RBX + 0x20));
    }
    if (*(long *)((long)unaff_RBX + 0x10) + -0x18 != in_stack_00000008) {
      refcount_delete_offset10();
    }
    if (*(long *)((long)unaff_RBX + 8) + -0x18 != in_stack_00000008) {
      refcount_delete_offset10();
    }
    operator_delete(unaff_RBX,0x50);
  }
  json_value_destruct(in_stack_00000028);
  json_value_destruct(in_stack_00000048);
  if (in_stack_00000050 + -0x18 != in_stack_00000008) {
    refcount_delete_offset10();
  }
  json_value_destruct(in_stack_00000038);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050fad3 name=FUN_0050fad3 size=25 ====

void FUN_0050fad3(void)

{
  undefined8 in_stack_00000038;
  undefined8 in_stack_00000048;
  undefined1 *in_stack_00000050;
  
  json_value_destruct();
  json_value_destruct(in_stack_00000048);
  if (in_stack_00000050 != &DAT_011c5338) {
    refcount_delete_offset10();
  }
  json_value_destruct(in_stack_00000038);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050faec name=FUN_0050faec size=24 ====

void FUN_0050faec(void)

{
  void *unaff_RBX;
  undefined8 unaff_retaddr;
  long in_stack_00000008;
  undefined8 in_stack_00000028;
  undefined8 in_stack_00000038;
  undefined8 in_stack_00000048;
  long in_stack_00000050;
  
  json_value_destruct();
  json_value_destruct();
  json_value_destruct(unaff_retaddr);
  if (unaff_RBX != (void *)0x0) {
    if (*(void **)((long)unaff_RBX + 0x38) != (void *)0x0) {
      operator_delete(*(void **)((long)unaff_RBX + 0x38));
    }
    if (*(void **)((long)unaff_RBX + 0x20) != (void *)0x0) {
      operator_delete(*(void **)((long)unaff_RBX + 0x20));
    }
    if (*(long *)((long)unaff_RBX + 0x10) + -0x18 != in_stack_00000008) {
      refcount_delete_offset10();
    }
    if (*(long *)((long)unaff_RBX + 8) + -0x18 != in_stack_00000008) {
      refcount_delete_offset10();
    }
    operator_delete(unaff_RBX,0x50);
  }
  json_value_destruct(in_stack_00000028);
  json_value_destruct(in_stack_00000048);
  if (in_stack_00000050 + -0x18 != in_stack_00000008) {
    refcount_delete_offset10();
  }
  json_value_destruct(in_stack_00000038);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050fb04 name=FUN_0050fb04 size=18 ====

void FUN_0050fb04(void)

{
  void *unaff_RBX;
  long in_stack_00000008;
  undefined8 in_stack_00000028;
  undefined8 in_stack_00000038;
  undefined8 in_stack_00000048;
  long in_stack_00000050;
  
  operator_delete(unaff_RBX,0x50);
  json_value_destruct(in_stack_00000028);
  json_value_destruct(in_stack_00000048);
  if (in_stack_00000050 + -0x18 != in_stack_00000008) {
    refcount_delete_offset10();
  }
  json_value_destruct(in_stack_00000038);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050fb16 name=FUN_0050fb16 size=21 ====

void FUN_0050fb16(void)

{
  void *unaff_RBX;
  undefined8 in_stack_00000038;
  
  operator_delete(unaff_RBX,0x70);
  json_value_destruct(in_stack_00000038);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050fb2b name=FUN_0050fb2b size=21 ====

void FUN_0050fb2b(void)

{
  undefined8 in_stack_00000038;
  
  json_value_destruct();
  json_value_destruct();
  json_value_destruct(in_stack_00000038);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050fb40 name=FUN_0050fb40 size=33 ====

void FUN_0050fb40(void)

{
  undefined8 in_stack_00000038;
  undefined1 *in_stack_00000050;
  
  json_value_destruct();
  json_value_destruct();
  if (in_stack_00000050 != &DAT_011c5338) {
    refcount_delete_offset10();
  }
  json_value_destruct(in_stack_00000038);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050fb61 name=FUN_0050fb61 size=7 ====

/* WARNING: Removing unreachable block (ram,0x0050fa40) */
/* WARNING: Removing unreachable block (ram,0x0050fa49) */
/* WARNING: Removing unreachable block (ram,0x0050fa4e) */
/* WARNING: Removing unreachable block (ram,0x0050fa57) */
/* WARNING: Removing unreachable block (ram,0x0050fa5c) */
/* WARNING: Removing unreachable block (ram,0x0050fa6b) */
/* WARNING: Removing unreachable block (ram,0x0050fa70) */
/* WARNING: Removing unreachable block (ram,0x0050fa7f) */
/* WARNING: Removing unreachable block (ram,0x0050fa84) */

void FUN_0050fb61(void)

{
  undefined8 unaff_retaddr;
  long in_stack_00000008;
  undefined8 in_stack_00000028;
  undefined8 in_stack_00000038;
  undefined8 in_stack_00000048;
  long in_stack_00000050;
  
  json_value_destruct(unaff_retaddr);
  json_value_destruct(in_stack_00000028);
  json_value_destruct(in_stack_00000048);
  if (in_stack_00000050 + -0x18 != in_stack_00000008) {
    refcount_delete_offset10();
  }
  json_value_destruct(in_stack_00000038);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050fb68 name=FUN_0050fb68 size=254 ====

/* WARNING: Removing unreachable block (ram,0x0050fd70) */
/* WARNING: Removing unreachable block (ram,0x0050fda8) */

void FUN_0050fb68(void)

{
  long *plVar1;
  int *piVar2;
  int iVar3;
  undefined8 *puVar4;
  undefined8 *puVar5;
  long lVar6;
  long lVar7;
  long *plVar8;
  void *unaff_R12;
  long *unaff_R13;
  undefined8 *puVar9;
  long lVar10;
  long unaff_R15;
  undefined8 in_stack_00000038;
  undefined8 in_stack_00000040;
  undefined8 in_stack_00000048;
  _Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *in_stack_000000e8;
  _Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *in_stack_00000118;
  
  if (in_stack_00000118 != (_Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *)0x0) {
    std::_Sp_counted_base<(__gnu_cxx::_Lock_policy)2>::_M_release(in_stack_00000118);
  }
  if (in_stack_000000e8 != (_Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *)0x0) {
    std::_Sp_counted_base<(__gnu_cxx::_Lock_policy)2>::_M_release(in_stack_000000e8);
  }
  plVar8 = (long *)&stack0x00000180;
  do {
    plVar8 = plVar8 + -1;
    if (*plVar8 + -0x18 != unaff_R15) {
      refcount_delete_offset10();
    }
  } while (plVar8 != unaff_R13);
  qt_byte_array_unref(in_stack_00000038);
  qt_byte_array_unref(in_stack_00000048);
  json_value_destruct(in_stack_00000040);
  if (unaff_R12 != (void *)0x0) {
    puVar4 = *(undefined8 **)((long)unaff_R12 + 0x28);
    if (puVar4 != (undefined8 *)0x0) {
      puVar5 = (undefined8 *)puVar4[1];
      for (puVar9 = (undefined8 *)*puVar4; puVar5 != puVar9; puVar9 = puVar9 + 2) {
        if ((undefined1 *)*puVar9 != &DAT_011c5338) {
          refcount_delete_offset10();
        }
      }
      if ((void *)*puVar4 != (void *)0x0) {
        operator_delete((void *)*puVar4);
      }
      operator_delete(puVar4,0x18);
    }
    lVar6 = *(long *)((long)unaff_R12 + 0x18);
    for (lVar10 = *(long *)((long)unaff_R12 + 0x10); lVar6 != lVar10; lVar10 = lVar10 + 0x18) {
      plVar8 = *(long **)(lVar10 + 8);
      if (plVar8 != (long *)0x0) {
        LOCK();
        plVar1 = plVar8 + 1;
        lVar7 = *plVar1;
        *(int *)plVar1 = (int)*plVar1 + -1;
        UNLOCK();
        if ((int)lVar7 == 1) {
          (**(code **)(*plVar8 + 0x10))(plVar8);
          LOCK();
          piVar2 = (int *)((long)plVar8 + 0xc);
          iVar3 = *piVar2;
          *piVar2 = *piVar2 + -1;
          UNLOCK();
          if (iVar3 == 1) {
            (**(code **)(*plVar8 + 0x18))(plVar8);
          }
        }
      }
    }
    if (*(void **)((long)unaff_R12 + 0x10) != (void *)0x0) {
      operator_delete(*(void **)((long)unaff_R12 + 0x10));
    }
    if (*(undefined1 **)((long)unaff_R12 + 8) != &DAT_011c5338) {
      refcount_delete_offset10();
    }
    operator_delete(unaff_R12,0x30);
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050fc66 name=FUN_0050fc66 size=38 ====

/* WARNING: Removing unreachable block (ram,0x0050fd70) */
/* WARNING: Removing unreachable block (ram,0x0050fda8) */

void FUN_0050fc66(void)

{
  long *plVar1;
  int *piVar2;
  int iVar3;
  undefined8 *puVar4;
  long lVar5;
  long *plVar6;
  long lVar7;
  undefined8 *puVar8;
  void *unaff_R12;
  undefined8 *puVar9;
  undefined8 *unaff_R13;
  long lVar10;
  undefined8 in_stack_00000038;
  undefined8 in_stack_00000040;
  undefined8 in_stack_00000048;
  
  puVar8 = unaff_R13 + 5;
  while (puVar8 != unaff_R13) {
    puVar8 = puVar8 + -1;
    if ((undefined1 *)*puVar8 != &DAT_011c5338) {
      refcount_delete_offset10();
    }
  }
  qt_byte_array_unref(in_stack_00000038);
  qt_byte_array_unref(in_stack_00000048);
  json_value_destruct(in_stack_00000040);
  if (unaff_R12 != (void *)0x0) {
    puVar8 = *(undefined8 **)((long)unaff_R12 + 0x28);
    if (puVar8 != (undefined8 *)0x0) {
      puVar4 = (undefined8 *)puVar8[1];
      for (puVar9 = (undefined8 *)*puVar8; puVar4 != puVar9; puVar9 = puVar9 + 2) {
        if ((undefined1 *)*puVar9 != &DAT_011c5338) {
          refcount_delete_offset10();
        }
      }
      if ((void *)*puVar8 != (void *)0x0) {
        operator_delete((void *)*puVar8);
      }
      operator_delete(puVar8,0x18);
    }
    lVar5 = *(long *)((long)unaff_R12 + 0x18);
    for (lVar10 = *(long *)((long)unaff_R12 + 0x10); lVar5 != lVar10; lVar10 = lVar10 + 0x18) {
      plVar6 = *(long **)(lVar10 + 8);
      if (plVar6 != (long *)0x0) {
        LOCK();
        plVar1 = plVar6 + 1;
        lVar7 = *plVar1;
        *(int *)plVar1 = (int)*plVar1 + -1;
        UNLOCK();
        if ((int)lVar7 == 1) {
          (**(code **)(*plVar6 + 0x10))(plVar6);
          LOCK();
          piVar2 = (int *)((long)plVar6 + 0xc);
          iVar3 = *piVar2;
          *piVar2 = *piVar2 + -1;
          UNLOCK();
          if (iVar3 == 1) {
            (**(code **)(*plVar6 + 0x18))(plVar6);
          }
        }
      }
    }
    if (*(void **)((long)unaff_R12 + 0x10) != (void *)0x0) {
      operator_delete(*(void **)((long)unaff_R12 + 0x10));
    }
    if (*(undefined1 **)((long)unaff_R12 + 8) != &DAT_011c5338) {
      refcount_delete_offset10();
    }
    operator_delete(unaff_R12,0x30);
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050fc8c name=FUN_0050fc8c size=67 ====

/* WARNING: Removing unreachable block (ram,0x0050fd70) */
/* WARNING: Removing unreachable block (ram,0x0050fda8) */

void FUN_0050fc8c(void)

{
  long *plVar1;
  int *piVar2;
  int iVar3;
  undefined8 *puVar4;
  undefined8 *puVar5;
  long lVar6;
  long lVar7;
  long *plVar8;
  void *unaff_R12;
  undefined8 *puVar9;
  long *unaff_R13;
  long lVar10;
  long unaff_R15;
  undefined8 in_stack_00000038;
  undefined8 in_stack_00000040;
  undefined8 in_stack_00000048;
  long in_stack_000000a0;
  _Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *in_stack_000000e8;
  _Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *in_stack_00000118;
  
  if (in_stack_000000e8 != (_Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *)0x0) {
    std::_Sp_counted_base<(__gnu_cxx::_Lock_policy)2>::_M_release(in_stack_000000e8);
  }
  if (in_stack_00000118 != (_Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *)0x0) {
    std::_Sp_counted_base<(__gnu_cxx::_Lock_policy)2>::_M_release(in_stack_00000118);
  }
  if (in_stack_000000a0 + -0x18 != unaff_R15) {
    refcount_delete_offset10();
  }
  plVar8 = (long *)&stack0x00000180;
  do {
    plVar8 = plVar8 + -1;
    if (*plVar8 + -0x18 != unaff_R15) {
      refcount_delete_offset10();
    }
  } while (plVar8 != unaff_R13);
  qt_byte_array_unref(in_stack_00000038);
  qt_byte_array_unref(in_stack_00000048);
  json_value_destruct(in_stack_00000040);
  if (unaff_R12 != (void *)0x0) {
    puVar4 = *(undefined8 **)((long)unaff_R12 + 0x28);
    if (puVar4 != (undefined8 *)0x0) {
      puVar5 = (undefined8 *)puVar4[1];
      for (puVar9 = (undefined8 *)*puVar4; puVar5 != puVar9; puVar9 = puVar9 + 2) {
        if ((undefined1 *)*puVar9 != &DAT_011c5338) {
          refcount_delete_offset10();
        }
      }
      if ((void *)*puVar4 != (void *)0x0) {
        operator_delete((void *)*puVar4);
      }
      operator_delete(puVar4,0x18);
    }
    lVar6 = *(long *)((long)unaff_R12 + 0x18);
    for (lVar10 = *(long *)((long)unaff_R12 + 0x10); lVar6 != lVar10; lVar10 = lVar10 + 0x18) {
      plVar8 = *(long **)(lVar10 + 8);
      if (plVar8 != (long *)0x0) {
        LOCK();
        plVar1 = plVar8 + 1;
        lVar7 = *plVar1;
        *(int *)plVar1 = (int)*plVar1 + -1;
        UNLOCK();
        if ((int)lVar7 == 1) {
          (**(code **)(*plVar8 + 0x10))(plVar8);
          LOCK();
          piVar2 = (int *)((long)plVar8 + 0xc);
          iVar3 = *piVar2;
          *piVar2 = *piVar2 + -1;
          UNLOCK();
          if (iVar3 == 1) {
            (**(code **)(*plVar8 + 0x18))(plVar8);
          }
        }
      }
    }
    if (*(void **)((long)unaff_R12 + 0x10) != (void *)0x0) {
      operator_delete(*(void **)((long)unaff_R12 + 0x10));
    }
    if (*(undefined1 **)((long)unaff_R12 + 8) != &DAT_011c5338) {
      refcount_delete_offset10();
    }
    operator_delete(unaff_R12,0x30);
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050fccf name=FUN_0050fccf size=7 ====

/* WARNING: Removing unreachable block (ram,0x0050fd70) */
/* WARNING: Removing unreachable block (ram,0x0050fda8) */

void FUN_0050fccf(void)

{
  long *plVar1;
  int *piVar2;
  int iVar3;
  undefined8 *puVar4;
  long lVar5;
  long *plVar6;
  long lVar7;
  undefined8 *puVar8;
  void *unaff_R12;
  undefined8 *puVar9;
  undefined8 *unaff_R13;
  long lVar10;
  undefined8 in_stack_00000038;
  undefined8 in_stack_00000040;
  undefined8 in_stack_00000048;
  
  puVar8 = unaff_R13 + 1;
  while (puVar8 != unaff_R13) {
    puVar8 = puVar8 + -1;
    if ((undefined1 *)*puVar8 != &DAT_011c5338) {
      refcount_delete_offset10();
    }
  }
  qt_byte_array_unref(in_stack_00000038);
  qt_byte_array_unref(in_stack_00000048);
  json_value_destruct(in_stack_00000040);
  if (unaff_R12 != (void *)0x0) {
    puVar8 = *(undefined8 **)((long)unaff_R12 + 0x28);
    if (puVar8 != (undefined8 *)0x0) {
      puVar4 = (undefined8 *)puVar8[1];
      for (puVar9 = (undefined8 *)*puVar8; puVar4 != puVar9; puVar9 = puVar9 + 2) {
        if ((undefined1 *)*puVar9 != &DAT_011c5338) {
          refcount_delete_offset10();
        }
      }
      if ((void *)*puVar8 != (void *)0x0) {
        operator_delete((void *)*puVar8);
      }
      operator_delete(puVar8,0x18);
    }
    lVar5 = *(long *)((long)unaff_R12 + 0x18);
    for (lVar10 = *(long *)((long)unaff_R12 + 0x10); lVar5 != lVar10; lVar10 = lVar10 + 0x18) {
      plVar6 = *(long **)(lVar10 + 8);
      if (plVar6 != (long *)0x0) {
        LOCK();
        plVar1 = plVar6 + 1;
        lVar7 = *plVar1;
        *(int *)plVar1 = (int)*plVar1 + -1;
        UNLOCK();
        if ((int)lVar7 == 1) {
          (**(code **)(*plVar6 + 0x10))(plVar6);
          LOCK();
          piVar2 = (int *)((long)plVar6 + 0xc);
          iVar3 = *piVar2;
          *piVar2 = *piVar2 + -1;
          UNLOCK();
          if (iVar3 == 1) {
            (**(code **)(*plVar6 + 0x18))(plVar6);
          }
        }
      }
    }
    if (*(void **)((long)unaff_R12 + 0x10) != (void *)0x0) {
      operator_delete(*(void **)((long)unaff_R12 + 0x10));
    }
    if (*(undefined1 **)((long)unaff_R12 + 8) != &DAT_011c5338) {
      refcount_delete_offset10();
    }
    operator_delete(unaff_R12,0x30);
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050fcd6 name=FUN_0050fcd6 size=21 ====

void FUN_0050fcd6(void)

{
  void *unaff_R12;
  
  operator_delete(unaff_R12,0x30);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050fceb name=FUN_0050fceb size=144 ====

/* WARNING: Removing unreachable block (ram,0x0050fd70) */
/* WARNING: Removing unreachable block (ram,0x0050fda8) */

void FUN_0050fceb(void)

{
  long *plVar1;
  int *piVar2;
  int iVar3;
  undefined8 *puVar4;
  long lVar5;
  long *plVar6;
  long lVar7;
  undefined8 *puVar8;
  void *unaff_R12;
  undefined8 *puVar9;
  undefined8 *unaff_R13;
  long lVar10;
  undefined8 in_stack_00000038;
  undefined8 in_stack_00000040;
  undefined8 in_stack_00000048;
  
  puVar8 = unaff_R13 + 4;
  while (puVar8 != unaff_R13) {
    puVar8 = puVar8 + -1;
    if ((undefined1 *)*puVar8 != &DAT_011c5338) {
      refcount_delete_offset10();
    }
  }
  qt_byte_array_unref(in_stack_00000038);
  qt_byte_array_unref(in_stack_00000048);
  json_value_destruct(in_stack_00000040);
  if (unaff_R12 != (void *)0x0) {
    puVar8 = *(undefined8 **)((long)unaff_R12 + 0x28);
    if (puVar8 != (undefined8 *)0x0) {
      puVar4 = (undefined8 *)puVar8[1];
      for (puVar9 = (undefined8 *)*puVar8; puVar4 != puVar9; puVar9 = puVar9 + 2) {
        if ((undefined1 *)*puVar9 != &DAT_011c5338) {
          refcount_delete_offset10();
        }
      }
      if ((void *)*puVar8 != (void *)0x0) {
        operator_delete((void *)*puVar8);
      }
      operator_delete(puVar8,0x18);
    }
    lVar5 = *(long *)((long)unaff_R12 + 0x18);
    for (lVar10 = *(long *)((long)unaff_R12 + 0x10); lVar5 != lVar10; lVar10 = lVar10 + 0x18) {
      plVar6 = *(long **)(lVar10 + 8);
      if (plVar6 != (long *)0x0) {
        LOCK();
        plVar1 = plVar6 + 1;
        lVar7 = *plVar1;
        *(int *)plVar1 = (int)*plVar1 + -1;
        UNLOCK();
        if ((int)lVar7 == 1) {
          (**(code **)(*plVar6 + 0x10))(plVar6);
          LOCK();
          piVar2 = (int *)((long)plVar6 + 0xc);
          iVar3 = *piVar2;
          *piVar2 = *piVar2 + -1;
          UNLOCK();
          if (iVar3 == 1) {
            (**(code **)(*plVar6 + 0x18))(plVar6);
          }
        }
      }
    }
    if (*(void **)((long)unaff_R12 + 0x10) != (void *)0x0) {
      operator_delete(*(void **)((long)unaff_R12 + 0x10));
    }
    if (*(undefined1 **)((long)unaff_R12 + 8) != &DAT_011c5338) {
      refcount_delete_offset10();
    }
    operator_delete(unaff_R12,0x30);
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050fd7b name=FUN_0050fd7b size=21 ====

/* WARNING: Removing unreachable block (ram,0x0050fbdb) */
/* WARNING: Removing unreachable block (ram,0x0050fcf5) */
/* WARNING: Removing unreachable block (ram,0x0050fbe9) */
/* WARNING: Removing unreachable block (ram,0x0050fbf8) */
/* WARNING: Removing unreachable block (ram,0x0050fd01) */
/* WARNING: Removing unreachable block (ram,0x0050fd0e) */
/* WARNING: Removing unreachable block (ram,0x0050fd13) */
/* WARNING: Removing unreachable block (ram,0x0050fc01) */
/* WARNING: Removing unreachable block (ram,0x0050fc0a) */
/* WARNING: Removing unreachable block (ram,0x0050fc0f) */
/* WARNING: Removing unreachable block (ram,0x0050fc1c) */
/* WARNING: Removing unreachable block (ram,0x0050fd70) */
/* WARNING: Removing unreachable block (ram,0x0050fd37) */
/* WARNING: Removing unreachable block (ram,0x0050fd3c) */
/* WARNING: Removing unreachable block (ram,0x0050fda8) */
/* WARNING: Removing unreachable block (ram,0x0050fd50) */
/* WARNING: Removing unreachable block (ram,0x0050fd58) */
/* WARNING: Removing unreachable block (ram,0x0050fd5d) */
/* WARNING: Removing unreachable block (ram,0x0050fd67) */
/* WARNING: Removing unreachable block (ram,0x0050fc26) */
/* WARNING: Removing unreachable block (ram,0x0050fd1c) */
/* WARNING: Removing unreachable block (ram,0x0050fd25) */
/* WARNING: Removing unreachable block (ram,0x0050fd2f) */
/* WARNING: Removing unreachable block (ram,0x0050fc2f) */
/* WARNING: Removing unreachable block (ram,0x0050fc39) */
/* WARNING: Removing unreachable block (ram,0x0050fc3e) */
/* WARNING: Removing unreachable block (ram,0x0050fc4c) */
/* WARNING: Removing unreachable block (ram,0x0050fc51) */

void FUN_0050fd7b(void)

{
  long *plVar1;
  void *unaff_RBX;
  long *unaff_R13;
  long unaff_R15;
  undefined8 in_stack_00000038;
  undefined8 in_stack_00000040;
  undefined8 in_stack_00000048;
  
  operator_delete(unaff_RBX,0x20);
  plVar1 = (long *)&stack0x00000180;
  do {
    plVar1 = plVar1 + -1;
    if (*plVar1 + -0x18 != unaff_R15) {
      refcount_delete_offset10();
    }
  } while (plVar1 != unaff_R13);
  qt_byte_array_unref(in_stack_00000038);
  qt_byte_array_unref(in_stack_00000048);
  json_value_destruct(in_stack_00000040);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050fd90 name=FUN_0050fd90 size=35 ====

/* WARNING: Removing unreachable block (ram,0x0050fd70) */
/* WARNING: Removing unreachable block (ram,0x0050fda8) */

void FUN_0050fd90(void)

{
  long *plVar1;
  int *piVar2;
  int iVar3;
  undefined8 *puVar4;
  undefined8 *puVar5;
  long lVar6;
  long lVar7;
  long *plVar8;
  void *unaff_R12;
  undefined8 *puVar9;
  long *unaff_R13;
  long lVar10;
  long unaff_R15;
  undefined8 in_stack_00000038;
  undefined8 in_stack_00000040;
  undefined8 in_stack_00000048;
  
  json_value_destruct();
  json_value_destruct();
  plVar8 = (long *)&stack0x00000180;
  do {
    plVar8 = plVar8 + -1;
    if (*plVar8 + -0x18 != unaff_R15) {
      refcount_delete_offset10();
    }
  } while (plVar8 != unaff_R13);
  qt_byte_array_unref(in_stack_00000038);
  qt_byte_array_unref(in_stack_00000048);
  json_value_destruct(in_stack_00000040);
  if (unaff_R12 != (void *)0x0) {
    puVar4 = *(undefined8 **)((long)unaff_R12 + 0x28);
    if (puVar4 != (undefined8 *)0x0) {
      puVar5 = (undefined8 *)puVar4[1];
      for (puVar9 = (undefined8 *)*puVar4; puVar5 != puVar9; puVar9 = puVar9 + 2) {
        if ((undefined1 *)*puVar9 != &DAT_011c5338) {
          refcount_delete_offset10();
        }
      }
      if ((void *)*puVar4 != (void *)0x0) {
        operator_delete((void *)*puVar4);
      }
      operator_delete(puVar4,0x18);
    }
    lVar6 = *(long *)((long)unaff_R12 + 0x18);
    for (lVar10 = *(long *)((long)unaff_R12 + 0x10); lVar6 != lVar10; lVar10 = lVar10 + 0x18) {
      plVar8 = *(long **)(lVar10 + 8);
      if (plVar8 != (long *)0x0) {
        LOCK();
        plVar1 = plVar8 + 1;
        lVar7 = *plVar1;
        *(int *)plVar1 = (int)*plVar1 + -1;
        UNLOCK();
        if ((int)lVar7 == 1) {
          (**(code **)(*plVar8 + 0x10))(plVar8);
          LOCK();
          piVar2 = (int *)((long)plVar8 + 0xc);
          iVar3 = *piVar2;
          *piVar2 = *piVar2 + -1;
          UNLOCK();
          if (iVar3 == 1) {
            (**(code **)(*plVar8 + 0x18))(plVar8);
          }
        }
      }
    }
    if (*(void **)((long)unaff_R12 + 0x10) != (void *)0x0) {
      operator_delete(*(void **)((long)unaff_R12 + 0x10));
    }
    if (*(undefined1 **)((long)unaff_R12 + 8) != &DAT_011c5338) {
      refcount_delete_offset10();
    }
    operator_delete(unaff_R12,0x30);
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050fdb3 name=FUN_0050fdb3 size=10 ====

/* WARNING: Removing unreachable block (ram,0x0050fd70) */
/* WARNING: Removing unreachable block (ram,0x0050fda8) */

void FUN_0050fdb3(void)

{
  long *plVar1;
  int *piVar2;
  int iVar3;
  undefined8 *puVar4;
  long lVar5;
  long *plVar6;
  long lVar7;
  undefined8 *puVar8;
  void *unaff_R12;
  undefined8 *puVar9;
  undefined8 *unaff_R13;
  long lVar10;
  undefined8 in_stack_00000038;
  undefined8 in_stack_00000040;
  undefined8 in_stack_00000048;
  
  puVar8 = unaff_R13 + 6;
  while (puVar8 != unaff_R13) {
    puVar8 = puVar8 + -1;
    if ((undefined1 *)*puVar8 != &DAT_011c5338) {
      refcount_delete_offset10();
    }
  }
  qt_byte_array_unref(in_stack_00000038);
  qt_byte_array_unref(in_stack_00000048);
  json_value_destruct(in_stack_00000040);
  if (unaff_R12 != (void *)0x0) {
    puVar8 = *(undefined8 **)((long)unaff_R12 + 0x28);
    if (puVar8 != (undefined8 *)0x0) {
      puVar4 = (undefined8 *)puVar8[1];
      for (puVar9 = (undefined8 *)*puVar8; puVar4 != puVar9; puVar9 = puVar9 + 2) {
        if ((undefined1 *)*puVar9 != &DAT_011c5338) {
          refcount_delete_offset10();
        }
      }
      if ((void *)*puVar8 != (void *)0x0) {
        operator_delete((void *)*puVar8);
      }
      operator_delete(puVar8,0x18);
    }
    lVar5 = *(long *)((long)unaff_R12 + 0x18);
    for (lVar10 = *(long *)((long)unaff_R12 + 0x10); lVar5 != lVar10; lVar10 = lVar10 + 0x18) {
      plVar6 = *(long **)(lVar10 + 8);
      if (plVar6 != (long *)0x0) {
        LOCK();
        plVar1 = plVar6 + 1;
        lVar7 = *plVar1;
        *(int *)plVar1 = (int)*plVar1 + -1;
        UNLOCK();
        if ((int)lVar7 == 1) {
          (**(code **)(*plVar6 + 0x10))(plVar6);
          LOCK();
          piVar2 = (int *)((long)plVar6 + 0xc);
          iVar3 = *piVar2;
          *piVar2 = *piVar2 + -1;
          UNLOCK();
          if (iVar3 == 1) {
            (**(code **)(*plVar6 + 0x18))(plVar6);
          }
        }
      }
    }
    if (*(void **)((long)unaff_R12 + 0x10) != (void *)0x0) {
      operator_delete(*(void **)((long)unaff_R12 + 0x10));
    }
    if (*(undefined1 **)((long)unaff_R12 + 8) != &DAT_011c5338) {
      refcount_delete_offset10();
    }
    operator_delete(unaff_R12,0x30);
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050fdbd name=FUN_0050fdbd size=47 ====

/* WARNING: Removing unreachable block (ram,0x0050fd70) */
/* WARNING: Removing unreachable block (ram,0x0050fda8) */

void FUN_0050fdbd(void)

{
  long *plVar1;
  int *piVar2;
  int iVar3;
  undefined8 *puVar4;
  undefined8 *puVar5;
  long lVar6;
  long lVar7;
  long *plVar8;
  void *unaff_R12;
  undefined8 *puVar9;
  long *unaff_R13;
  long lVar10;
  long unaff_R15;
  undefined8 unaff_retaddr;
  undefined8 in_stack_00000038;
  undefined8 in_stack_00000040;
  undefined8 in_stack_00000048;
  long in_stack_000000a8;
  
  json_value_destruct();
  if (in_stack_000000a8 + -0x18 != unaff_R15) {
    refcount_delete_offset10();
  }
  json_value_destruct(unaff_retaddr);
  plVar8 = (long *)&stack0x00000180;
  do {
    plVar8 = plVar8 + -1;
    if (*plVar8 + -0x18 != unaff_R15) {
      refcount_delete_offset10();
    }
  } while (plVar8 != unaff_R13);
  qt_byte_array_unref(in_stack_00000038);
  qt_byte_array_unref(in_stack_00000048);
  json_value_destruct(in_stack_00000040);
  if (unaff_R12 != (void *)0x0) {
    puVar4 = *(undefined8 **)((long)unaff_R12 + 0x28);
    if (puVar4 != (undefined8 *)0x0) {
      puVar5 = (undefined8 *)puVar4[1];
      for (puVar9 = (undefined8 *)*puVar4; puVar5 != puVar9; puVar9 = puVar9 + 2) {
        if ((undefined1 *)*puVar9 != &DAT_011c5338) {
          refcount_delete_offset10();
        }
      }
      if ((void *)*puVar4 != (void *)0x0) {
        operator_delete((void *)*puVar4);
      }
      operator_delete(puVar4,0x18);
    }
    lVar6 = *(long *)((long)unaff_R12 + 0x18);
    for (lVar10 = *(long *)((long)unaff_R12 + 0x10); lVar6 != lVar10; lVar10 = lVar10 + 0x18) {
      plVar8 = *(long **)(lVar10 + 8);
      if (plVar8 != (long *)0x0) {
        LOCK();
        plVar1 = plVar8 + 1;
        lVar7 = *plVar1;
        *(int *)plVar1 = (int)*plVar1 + -1;
        UNLOCK();
        if ((int)lVar7 == 1) {
          (**(code **)(*plVar8 + 0x10))(plVar8);
          LOCK();
          piVar2 = (int *)((long)plVar8 + 0xc);
          iVar3 = *piVar2;
          *piVar2 = *piVar2 + -1;
          UNLOCK();
          if (iVar3 == 1) {
            (**(code **)(*plVar8 + 0x18))(plVar8);
          }
        }
      }
    }
    if (*(void **)((long)unaff_R12 + 0x10) != (void *)0x0) {
      operator_delete(*(void **)((long)unaff_R12 + 0x10));
    }
    if (*(undefined1 **)((long)unaff_R12 + 8) != &DAT_011c5338) {
      refcount_delete_offset10();
    }
    operator_delete(unaff_R12,0x30);
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050fdec name=FUN_0050fdec size=10 ====

/* WARNING: Removing unreachable block (ram,0x0050fd70) */
/* WARNING: Removing unreachable block (ram,0x0050fda8) */

void FUN_0050fdec(void)

{
  long *plVar1;
  int *piVar2;
  int iVar3;
  undefined8 *puVar4;
  long lVar5;
  long *plVar6;
  long lVar7;
  undefined8 *puVar8;
  void *unaff_R12;
  undefined8 *puVar9;
  undefined8 *unaff_R13;
  long lVar10;
  undefined8 in_stack_00000038;
  undefined8 in_stack_00000040;
  undefined8 in_stack_00000048;
  
  puVar8 = unaff_R13;
  while (puVar8 != unaff_R13) {
    puVar8 = puVar8 + -1;
    if ((undefined1 *)*puVar8 != &DAT_011c5338) {
      refcount_delete_offset10();
    }
  }
  qt_byte_array_unref(in_stack_00000038);
  qt_byte_array_unref(in_stack_00000048);
  json_value_destruct(in_stack_00000040);
  if (unaff_R12 != (void *)0x0) {
    puVar8 = *(undefined8 **)((long)unaff_R12 + 0x28);
    if (puVar8 != (undefined8 *)0x0) {
      puVar4 = (undefined8 *)puVar8[1];
      for (puVar9 = (undefined8 *)*puVar8; puVar4 != puVar9; puVar9 = puVar9 + 2) {
        if ((undefined1 *)*puVar9 != &DAT_011c5338) {
          refcount_delete_offset10();
        }
      }
      if ((void *)*puVar8 != (void *)0x0) {
        operator_delete((void *)*puVar8);
      }
      operator_delete(puVar8,0x18);
    }
    lVar5 = *(long *)((long)unaff_R12 + 0x18);
    for (lVar10 = *(long *)((long)unaff_R12 + 0x10); lVar5 != lVar10; lVar10 = lVar10 + 0x18) {
      plVar6 = *(long **)(lVar10 + 8);
      if (plVar6 != (long *)0x0) {
        LOCK();
        plVar1 = plVar6 + 1;
        lVar7 = *plVar1;
        *(int *)plVar1 = (int)*plVar1 + -1;
        UNLOCK();
        if ((int)lVar7 == 1) {
          (**(code **)(*plVar6 + 0x10))(plVar6);
          LOCK();
          piVar2 = (int *)((long)plVar6 + 0xc);
          iVar3 = *piVar2;
          *piVar2 = *piVar2 + -1;
          UNLOCK();
          if (iVar3 == 1) {
            (**(code **)(*plVar6 + 0x18))(plVar6);
          }
        }
      }
    }
    if (*(void **)((long)unaff_R12 + 0x10) != (void *)0x0) {
      operator_delete(*(void **)((long)unaff_R12 + 0x10));
    }
    if (*(undefined1 **)((long)unaff_R12 + 8) != &DAT_011c5338) {
      refcount_delete_offset10();
    }
    operator_delete(unaff_R12,0x30);
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050fdf6 name=FUN_0050fdf6 size=7 ====

/* WARNING: Removing unreachable block (ram,0x0050fd70) */
/* WARNING: Removing unreachable block (ram,0x0050fda8) */

void FUN_0050fdf6(void)

{
  long *plVar1;
  int *piVar2;
  int iVar3;
  undefined8 *puVar4;
  long lVar5;
  long *plVar6;
  long lVar7;
  undefined8 *puVar8;
  void *unaff_R12;
  undefined8 *puVar9;
  undefined8 *unaff_R13;
  long lVar10;
  undefined8 in_stack_00000038;
  undefined8 in_stack_00000040;
  undefined8 in_stack_00000048;
  
  puVar8 = unaff_R13 + 7;
  while (puVar8 != unaff_R13) {
    puVar8 = puVar8 + -1;
    if ((undefined1 *)*puVar8 != &DAT_011c5338) {
      refcount_delete_offset10();
    }
  }
  qt_byte_array_unref(in_stack_00000038);
  qt_byte_array_unref(in_stack_00000048);
  json_value_destruct(in_stack_00000040);
  if (unaff_R12 != (void *)0x0) {
    puVar8 = *(undefined8 **)((long)unaff_R12 + 0x28);
    if (puVar8 != (undefined8 *)0x0) {
      puVar4 = (undefined8 *)puVar8[1];
      for (puVar9 = (undefined8 *)*puVar8; puVar4 != puVar9; puVar9 = puVar9 + 2) {
        if ((undefined1 *)*puVar9 != &DAT_011c5338) {
          refcount_delete_offset10();
        }
      }
      if ((void *)*puVar8 != (void *)0x0) {
        operator_delete((void *)*puVar8);
      }
      operator_delete(puVar8,0x18);
    }
    lVar5 = *(long *)((long)unaff_R12 + 0x18);
    for (lVar10 = *(long *)((long)unaff_R12 + 0x10); lVar5 != lVar10; lVar10 = lVar10 + 0x18) {
      plVar6 = *(long **)(lVar10 + 8);
      if (plVar6 != (long *)0x0) {
        LOCK();
        plVar1 = plVar6 + 1;
        lVar7 = *plVar1;
        *(int *)plVar1 = (int)*plVar1 + -1;
        UNLOCK();
        if ((int)lVar7 == 1) {
          (**(code **)(*plVar6 + 0x10))(plVar6);
          LOCK();
          piVar2 = (int *)((long)plVar6 + 0xc);
          iVar3 = *piVar2;
          *piVar2 = *piVar2 + -1;
          UNLOCK();
          if (iVar3 == 1) {
            (**(code **)(*plVar6 + 0x18))(plVar6);
          }
        }
      }
    }
    if (*(void **)((long)unaff_R12 + 0x10) != (void *)0x0) {
      operator_delete(*(void **)((long)unaff_R12 + 0x10));
    }
    if (*(undefined1 **)((long)unaff_R12 + 8) != &DAT_011c5338) {
      refcount_delete_offset10();
    }
    operator_delete(unaff_R12,0x30);
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050fdfd name=FUN_0050fdfd size=13 ====

/* WARNING: Removing unreachable block (ram,0x0050fd70) */
/* WARNING: Removing unreachable block (ram,0x0050fda8) */

void FUN_0050fdfd(void)

{
  long *plVar1;
  int *piVar2;
  int iVar3;
  undefined8 *puVar4;
  undefined8 *puVar5;
  long lVar6;
  long lVar7;
  long *plVar8;
  void *unaff_R12;
  undefined8 *puVar9;
  long *unaff_R13;
  long lVar10;
  long unaff_R15;
  undefined8 in_stack_00000038;
  undefined8 in_stack_00000040;
  undefined8 in_stack_00000048;
  
  json_value_destruct();
  json_value_destruct();
  plVar8 = (long *)&stack0x00000180;
  do {
    plVar8 = plVar8 + -1;
    if (*plVar8 + -0x18 != unaff_R15) {
      refcount_delete_offset10();
    }
  } while (plVar8 != unaff_R13);
  qt_byte_array_unref(in_stack_00000038);
  qt_byte_array_unref(in_stack_00000048);
  json_value_destruct(in_stack_00000040);
  if (unaff_R12 != (void *)0x0) {
    puVar4 = *(undefined8 **)((long)unaff_R12 + 0x28);
    if (puVar4 != (undefined8 *)0x0) {
      puVar5 = (undefined8 *)puVar4[1];
      for (puVar9 = (undefined8 *)*puVar4; puVar5 != puVar9; puVar9 = puVar9 + 2) {
        if ((undefined1 *)*puVar9 != &DAT_011c5338) {
          refcount_delete_offset10();
        }
      }
      if ((void *)*puVar4 != (void *)0x0) {
        operator_delete((void *)*puVar4);
      }
      operator_delete(puVar4,0x18);
    }
    lVar6 = *(long *)((long)unaff_R12 + 0x18);
    for (lVar10 = *(long *)((long)unaff_R12 + 0x10); lVar6 != lVar10; lVar10 = lVar10 + 0x18) {
      plVar8 = *(long **)(lVar10 + 8);
      if (plVar8 != (long *)0x0) {
        LOCK();
        plVar1 = plVar8 + 1;
        lVar7 = *plVar1;
        *(int *)plVar1 = (int)*plVar1 + -1;
        UNLOCK();
        if ((int)lVar7 == 1) {
          (**(code **)(*plVar8 + 0x10))(plVar8);
          LOCK();
          piVar2 = (int *)((long)plVar8 + 0xc);
          iVar3 = *piVar2;
          *piVar2 = *piVar2 + -1;
          UNLOCK();
          if (iVar3 == 1) {
            (**(code **)(*plVar8 + 0x18))(plVar8);
          }
        }
      }
    }
    if (*(void **)((long)unaff_R12 + 0x10) != (void *)0x0) {
      operator_delete(*(void **)((long)unaff_R12 + 0x10));
    }
    if (*(undefined1 **)((long)unaff_R12 + 8) != &DAT_011c5338) {
      refcount_delete_offset10();
    }
    operator_delete(unaff_R12,0x30);
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050fe0a name=FUN_0050fe0a size=13 ====

/* WARNING: Removing unreachable block (ram,0x0050fd70) */
/* WARNING: Removing unreachable block (ram,0x0050fda8) */

void FUN_0050fe0a(void)

{
  long *plVar1;
  int *piVar2;
  int iVar3;
  undefined8 *puVar4;
  undefined8 *puVar5;
  long lVar6;
  long lVar7;
  long *plVar8;
  void *unaff_R12;
  undefined8 *puVar9;
  long *unaff_R13;
  long lVar10;
  long unaff_R15;
  undefined8 in_stack_00000038;
  undefined8 in_stack_00000040;
  undefined8 in_stack_00000048;
  
  json_value_destruct();
  json_value_destruct();
  plVar8 = (long *)&stack0x00000180;
  do {
    plVar8 = plVar8 + -1;
    if (*plVar8 + -0x18 != unaff_R15) {
      refcount_delete_offset10();
    }
  } while (plVar8 != unaff_R13);
  qt_byte_array_unref(in_stack_00000038);
  qt_byte_array_unref(in_stack_00000048);
  json_value_destruct(in_stack_00000040);
  if (unaff_R12 != (void *)0x0) {
    puVar4 = *(undefined8 **)((long)unaff_R12 + 0x28);
    if (puVar4 != (undefined8 *)0x0) {
      puVar5 = (undefined8 *)puVar4[1];
      for (puVar9 = (undefined8 *)*puVar4; puVar5 != puVar9; puVar9 = puVar9 + 2) {
        if ((undefined1 *)*puVar9 != &DAT_011c5338) {
          refcount_delete_offset10();
        }
      }
      if ((void *)*puVar4 != (void *)0x0) {
        operator_delete((void *)*puVar4);
      }
      operator_delete(puVar4,0x18);
    }
    lVar6 = *(long *)((long)unaff_R12 + 0x18);
    for (lVar10 = *(long *)((long)unaff_R12 + 0x10); lVar6 != lVar10; lVar10 = lVar10 + 0x18) {
      plVar8 = *(long **)(lVar10 + 8);
      if (plVar8 != (long *)0x0) {
        LOCK();
        plVar1 = plVar8 + 1;
        lVar7 = *plVar1;
        *(int *)plVar1 = (int)*plVar1 + -1;
        UNLOCK();
        if ((int)lVar7 == 1) {
          (**(code **)(*plVar8 + 0x10))(plVar8);
          LOCK();
          piVar2 = (int *)((long)plVar8 + 0xc);
          iVar3 = *piVar2;
          *piVar2 = *piVar2 + -1;
          UNLOCK();
          if (iVar3 == 1) {
            (**(code **)(*plVar8 + 0x18))(plVar8);
          }
        }
      }
    }
    if (*(void **)((long)unaff_R12 + 0x10) != (void *)0x0) {
      operator_delete(*(void **)((long)unaff_R12 + 0x10));
    }
    if (*(undefined1 **)((long)unaff_R12 + 8) != &DAT_011c5338) {
      refcount_delete_offset10();
    }
    operator_delete(unaff_R12,0x30);
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050fe17 name=FUN_0050fe17 size=10 ====

/* WARNING: Removing unreachable block (ram,0x0050fd70) */
/* WARNING: Removing unreachable block (ram,0x0050fda8) */

void FUN_0050fe17(void)

{
  long *plVar1;
  int *piVar2;
  int iVar3;
  undefined8 *puVar4;
  long lVar5;
  long *plVar6;
  long lVar7;
  undefined8 *puVar8;
  void *unaff_R12;
  undefined8 *puVar9;
  undefined8 *unaff_R13;
  long lVar10;
  undefined8 in_stack_00000038;
  undefined8 in_stack_00000040;
  undefined8 in_stack_00000048;
  
  puVar8 = unaff_R13 + 2;
  while (puVar8 != unaff_R13) {
    puVar8 = puVar8 + -1;
    if ((undefined1 *)*puVar8 != &DAT_011c5338) {
      refcount_delete_offset10();
    }
  }
  qt_byte_array_unref(in_stack_00000038);
  qt_byte_array_unref(in_stack_00000048);
  json_value_destruct(in_stack_00000040);
  if (unaff_R12 != (void *)0x0) {
    puVar8 = *(undefined8 **)((long)unaff_R12 + 0x28);
    if (puVar8 != (undefined8 *)0x0) {
      puVar4 = (undefined8 *)puVar8[1];
      for (puVar9 = (undefined8 *)*puVar8; puVar4 != puVar9; puVar9 = puVar9 + 2) {
        if ((undefined1 *)*puVar9 != &DAT_011c5338) {
          refcount_delete_offset10();
        }
      }
      if ((void *)*puVar8 != (void *)0x0) {
        operator_delete((void *)*puVar8);
      }
      operator_delete(puVar8,0x18);
    }
    lVar5 = *(long *)((long)unaff_R12 + 0x18);
    for (lVar10 = *(long *)((long)unaff_R12 + 0x10); lVar5 != lVar10; lVar10 = lVar10 + 0x18) {
      plVar6 = *(long **)(lVar10 + 8);
      if (plVar6 != (long *)0x0) {
        LOCK();
        plVar1 = plVar6 + 1;
        lVar7 = *plVar1;
        *(int *)plVar1 = (int)*plVar1 + -1;
        UNLOCK();
        if ((int)lVar7 == 1) {
          (**(code **)(*plVar6 + 0x10))(plVar6);
          LOCK();
          piVar2 = (int *)((long)plVar6 + 0xc);
          iVar3 = *piVar2;
          *piVar2 = *piVar2 + -1;
          UNLOCK();
          if (iVar3 == 1) {
            (**(code **)(*plVar6 + 0x18))(plVar6);
          }
        }
      }
    }
    if (*(void **)((long)unaff_R12 + 0x10) != (void *)0x0) {
      operator_delete(*(void **)((long)unaff_R12 + 0x10));
    }
    if (*(undefined1 **)((long)unaff_R12 + 8) != &DAT_011c5338) {
      refcount_delete_offset10();
    }
    operator_delete(unaff_R12,0x30);
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050fe21 name=FUN_0050fe21 size=44 ====

/* WARNING: Removing unreachable block (ram,0x0050fd70) */
/* WARNING: Removing unreachable block (ram,0x0050fda8) */

void FUN_0050fe21(void)

{
  long *plVar1;
  int *piVar2;
  int iVar3;
  undefined8 *puVar4;
  long lVar5;
  long *plVar6;
  long lVar7;
  undefined8 *puVar8;
  void *unaff_R12;
  undefined8 *puVar9;
  undefined8 *unaff_R13;
  long lVar10;
  undefined8 in_stack_00000038;
  undefined8 in_stack_00000040;
  undefined8 in_stack_00000048;
  
  puVar8 = unaff_R13 + 3;
  while (puVar8 != unaff_R13) {
    puVar8 = puVar8 + -1;
    if ((undefined1 *)*puVar8 != &DAT_011c5338) {
      refcount_delete_offset10();
    }
  }
  qt_byte_array_unref(in_stack_00000038);
  qt_byte_array_unref(in_stack_00000048);
  json_value_destruct(in_stack_00000040);
  if (unaff_R12 != (void *)0x0) {
    puVar8 = *(undefined8 **)((long)unaff_R12 + 0x28);
    if (puVar8 != (undefined8 *)0x0) {
      puVar4 = (undefined8 *)puVar8[1];
      for (puVar9 = (undefined8 *)*puVar8; puVar4 != puVar9; puVar9 = puVar9 + 2) {
        if ((undefined1 *)*puVar9 != &DAT_011c5338) {
          refcount_delete_offset10();
        }
      }
      if ((void *)*puVar8 != (void *)0x0) {
        operator_delete((void *)*puVar8);
      }
      operator_delete(puVar8,0x18);
    }
    lVar5 = *(long *)((long)unaff_R12 + 0x18);
    for (lVar10 = *(long *)((long)unaff_R12 + 0x10); lVar5 != lVar10; lVar10 = lVar10 + 0x18) {
      plVar6 = *(long **)(lVar10 + 8);
      if (plVar6 != (long *)0x0) {
        LOCK();
        plVar1 = plVar6 + 1;
        lVar7 = *plVar1;
        *(int *)plVar1 = (int)*plVar1 + -1;
        UNLOCK();
        if ((int)lVar7 == 1) {
          (**(code **)(*plVar6 + 0x10))(plVar6);
          LOCK();
          piVar2 = (int *)((long)plVar6 + 0xc);
          iVar3 = *piVar2;
          *piVar2 = *piVar2 + -1;
          UNLOCK();
          if (iVar3 == 1) {
            (**(code **)(*plVar6 + 0x18))(plVar6);
          }
        }
      }
    }
    if (*(void **)((long)unaff_R12 + 0x10) != (void *)0x0) {
      operator_delete(*(void **)((long)unaff_R12 + 0x10));
    }
    if (*(undefined1 **)((long)unaff_R12 + 8) != &DAT_011c5338) {
      refcount_delete_offset10();
    }
    operator_delete(unaff_R12,0x30);
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050fe2b name=FUN_0050fe2b size=16 ====

/* WARNING: Removing unreachable block (ram,0x0050fd70) */
/* WARNING: Removing unreachable block (ram,0x0050fda8) */

void FUN_0050fe2b(void)

{
  long *plVar1;
  int *piVar2;
  int iVar3;
  undefined8 *puVar4;
  undefined8 *puVar5;
  long lVar6;
  long lVar7;
  long *plVar8;
  void *unaff_R12;
  undefined8 *puVar9;
  long *unaff_R13;
  long lVar10;
  long unaff_R15;
  undefined8 in_stack_00000038;
  undefined8 in_stack_00000040;
  undefined8 in_stack_00000048;
  
  json_value_destruct();
  json_value_destruct();
  plVar8 = (long *)&stack0x00000180;
  do {
    plVar8 = plVar8 + -1;
    if (*plVar8 + -0x18 != unaff_R15) {
      refcount_delete_offset10();
    }
  } while (plVar8 != unaff_R13);
  qt_byte_array_unref(in_stack_00000038);
  qt_byte_array_unref(in_stack_00000048);
  json_value_destruct(in_stack_00000040);
  if (unaff_R12 != (void *)0x0) {
    puVar4 = *(undefined8 **)((long)unaff_R12 + 0x28);
    if (puVar4 != (undefined8 *)0x0) {
      puVar5 = (undefined8 *)puVar4[1];
      for (puVar9 = (undefined8 *)*puVar4; puVar5 != puVar9; puVar9 = puVar9 + 2) {
        if ((undefined1 *)*puVar9 != &DAT_011c5338) {
          refcount_delete_offset10();
        }
      }
      if ((void *)*puVar4 != (void *)0x0) {
        operator_delete((void *)*puVar4);
      }
      operator_delete(puVar4,0x18);
    }
    lVar6 = *(long *)((long)unaff_R12 + 0x18);
    for (lVar10 = *(long *)((long)unaff_R12 + 0x10); lVar6 != lVar10; lVar10 = lVar10 + 0x18) {
      plVar8 = *(long **)(lVar10 + 8);
      if (plVar8 != (long *)0x0) {
        LOCK();
        plVar1 = plVar8 + 1;
        lVar7 = *plVar1;
        *(int *)plVar1 = (int)*plVar1 + -1;
        UNLOCK();
        if ((int)lVar7 == 1) {
          (**(code **)(*plVar8 + 0x10))(plVar8);
          LOCK();
          piVar2 = (int *)((long)plVar8 + 0xc);
          iVar3 = *piVar2;
          *piVar2 = *piVar2 + -1;
          UNLOCK();
          if (iVar3 == 1) {
            (**(code **)(*plVar8 + 0x18))(plVar8);
          }
        }
      }
    }
    if (*(void **)((long)unaff_R12 + 0x10) != (void *)0x0) {
      operator_delete(*(void **)((long)unaff_R12 + 0x10));
    }
    if (*(undefined1 **)((long)unaff_R12 + 8) != &DAT_011c5338) {
      refcount_delete_offset10();
    }
    operator_delete(unaff_R12,0x30);
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050fe5e name=FUN_0050fe5e size=166 ====

void FUN_0050fe5e(void)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  undefined8 in_stack_00000008;
  long in_stack_00000018;
  undefined8 in_stack_00000048;
  undefined8 in_stack_00000058;
  undefined8 in_stack_00000068;
  long in_stack_00000080;
  long in_stack_000001a8;
  void *in_stack_000001c8;
  
  FUN_009e27d6(&stack0x00000140);
  FUN_009a3e50(in_stack_00000008);
  if (in_stack_000001c8 != (void *)0x0) {
    puVar2 = *(undefined8 **)((long)in_stack_000001c8 + in_stack_000001a8 * 8);
    while (puVar2 != (undefined8 *)0x0) {
      puVar1 = (undefined8 *)*puVar2;
      if (puVar2[2] + -0x18 != in_stack_00000018) {
        refcount_delete_offset10();
      }
      operator_delete(puVar2);
      puVar2 = puVar1;
    }
    operator_delete(in_stack_000001c8);
  }
  json_value_destruct(in_stack_00000048);
  json_value_destruct(in_stack_00000068);
  if (in_stack_00000080 + -0x18 != in_stack_00000018) {
    refcount_delete_offset10();
  }
  json_value_destruct(in_stack_00000058);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050febb name=FUN_0050febb size=142 ====

void FUN_0050febb(void)

{
  void *unaff_RBX;
  undefined8 in_stack_00000008;
  long in_stack_00000018;
  undefined8 in_stack_00000048;
  undefined8 in_stack_00000058;
  undefined8 in_stack_00000068;
  long in_stack_00000080;
  
  json_value_destruct();
  json_value_destruct(in_stack_00000008);
  json_value_destruct();
  if (unaff_RBX != (void *)0x0) {
    if (*(void **)((long)unaff_RBX + 0x40) != (void *)0x0) {
      operator_delete(*(void **)((long)unaff_RBX + 0x40));
    }
    if (*(void **)((long)unaff_RBX + 0x28) != (void *)0x0) {
      operator_delete(*(void **)((long)unaff_RBX + 0x28));
    }
    if (*(long *)((long)unaff_RBX + 0x18) + -0x18 != in_stack_00000018) {
      refcount_delete_offset10();
    }
    if (*(long *)((long)unaff_RBX + 0x10) + -0x18 != in_stack_00000018) {
      refcount_delete_offset10();
    }
    if (*(long *)((long)unaff_RBX + 8) + -0x18 != in_stack_00000018) {
      refcount_delete_offset10();
    }
    operator_delete(unaff_RBX,0x58);
  }
  json_value_destruct(in_stack_00000048);
  json_value_destruct(in_stack_00000068);
  if (in_stack_00000080 + -0x18 != in_stack_00000018) {
    refcount_delete_offset10();
  }
  json_value_destruct(in_stack_00000058);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050ff49 name=FUN_0050ff49 size=23 ====

void FUN_0050ff49(void)

{
  void *unaff_RBX;
  undefined8 in_stack_00000008;
  long in_stack_00000018;
  undefined8 in_stack_00000048;
  undefined8 in_stack_00000058;
  undefined8 in_stack_00000068;
  long in_stack_00000080;
  
  json_value_destruct();
  json_value_destruct(in_stack_00000008);
  json_value_destruct();
  if (unaff_RBX != (void *)0x0) {
    if (*(void **)((long)unaff_RBX + 0x40) != (void *)0x0) {
      operator_delete(*(void **)((long)unaff_RBX + 0x40));
    }
    if (*(void **)((long)unaff_RBX + 0x28) != (void *)0x0) {
      operator_delete(*(void **)((long)unaff_RBX + 0x28));
    }
    if (*(long *)((long)unaff_RBX + 0x18) + -0x18 != in_stack_00000018) {
      refcount_delete_offset10();
    }
    if (*(long *)((long)unaff_RBX + 0x10) + -0x18 != in_stack_00000018) {
      refcount_delete_offset10();
    }
    if (*(long *)((long)unaff_RBX + 8) + -0x18 != in_stack_00000018) {
      refcount_delete_offset10();
    }
    operator_delete(unaff_RBX,0x58);
  }
  json_value_destruct(in_stack_00000048);
  json_value_destruct(in_stack_00000068);
  if (in_stack_00000080 + -0x18 != in_stack_00000018) {
    refcount_delete_offset10();
  }
  json_value_destruct(in_stack_00000058);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050ff60 name=FUN_0050ff60 size=36 ====

void FUN_0050ff60(void)

{
  undefined8 in_stack_00000008;
  undefined8 in_stack_00000058;
  
  json_value_destruct();
  json_value_destruct(in_stack_00000008);
  json_value_destruct(in_stack_00000058);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050ff84 name=FUN_0050ff84 size=18 ====

void FUN_0050ff84(void)

{
  void *unaff_RBX;
  undefined8 in_stack_00000058;
  
  operator_delete(unaff_RBX,0x70);
  json_value_destruct(in_stack_00000058);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050ffdf name=FUN_0050ffdf size=23 ====

void FUN_0050ffdf(void)

{
  void *unaff_RBX;
  undefined8 in_stack_00000008;
  long in_stack_00000018;
  undefined8 in_stack_00000048;
  undefined8 in_stack_00000058;
  undefined8 in_stack_00000068;
  long in_stack_00000080;
  
  json_value_destruct();
  json_value_destruct(in_stack_00000008);
  json_value_destruct();
  if (unaff_RBX != (void *)0x0) {
    if (*(void **)((long)unaff_RBX + 0x40) != (void *)0x0) {
      operator_delete(*(void **)((long)unaff_RBX + 0x40));
    }
    if (*(void **)((long)unaff_RBX + 0x28) != (void *)0x0) {
      operator_delete(*(void **)((long)unaff_RBX + 0x28));
    }
    if (*(long *)((long)unaff_RBX + 0x18) + -0x18 != in_stack_00000018) {
      refcount_delete_offset10();
    }
    if (*(long *)((long)unaff_RBX + 0x10) + -0x18 != in_stack_00000018) {
      refcount_delete_offset10();
    }
    if (*(long *)((long)unaff_RBX + 8) + -0x18 != in_stack_00000018) {
      refcount_delete_offset10();
    }
    operator_delete(unaff_RBX,0x58);
  }
  json_value_destruct(in_stack_00000048);
  json_value_destruct(in_stack_00000068);
  if (in_stack_00000080 + -0x18 != in_stack_00000018) {
    refcount_delete_offset10();
  }
  json_value_destruct(in_stack_00000058);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0050fff6 name=FUN_0050fff6 size=23 ====

void FUN_0050fff6(void)

{
  void *unaff_RBX;
  undefined8 in_stack_00000008;
  long in_stack_00000018;
  undefined8 in_stack_00000048;
  undefined8 in_stack_00000058;
  undefined8 in_stack_00000068;
  long in_stack_00000080;
  
  json_value_destruct();
  json_value_destruct(in_stack_00000008);
  json_value_destruct();
  if (unaff_RBX != (void *)0x0) {
    if (*(void **)((long)unaff_RBX + 0x40) != (void *)0x0) {
      operator_delete(*(void **)((long)unaff_RBX + 0x40));
    }
    if (*(void **)((long)unaff_RBX + 0x28) != (void *)0x0) {
      operator_delete(*(void **)((long)unaff_RBX + 0x28));
    }
    if (*(long *)((long)unaff_RBX + 0x18) + -0x18 != in_stack_00000018) {
      refcount_delete_offset10();
    }
    if (*(long *)((long)unaff_RBX + 0x10) + -0x18 != in_stack_00000018) {
      refcount_delete_offset10();
    }
    if (*(long *)((long)unaff_RBX + 8) + -0x18 != in_stack_00000018) {
      refcount_delete_offset10();
    }
    operator_delete(unaff_RBX,0x58);
  }
  json_value_destruct(in_stack_00000048);
  json_value_destruct(in_stack_00000068);
  if (in_stack_00000080 + -0x18 != in_stack_00000018) {
    refcount_delete_offset10();
  }
  json_value_destruct(in_stack_00000058);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0051000d name=FUN_0051000d size=21 ====

void FUN_0051000d(void)

{
  void *unaff_RBX;
  long in_stack_00000018;
  undefined8 in_stack_00000048;
  undefined8 in_stack_00000058;
  undefined8 in_stack_00000068;
  long in_stack_00000080;
  
  operator_delete(unaff_RBX,0x58);
  json_value_destruct(in_stack_00000048);
  json_value_destruct(in_stack_00000068);
  if (in_stack_00000080 + -0x18 != in_stack_00000018) {
    refcount_delete_offset10();
  }
  json_value_destruct(in_stack_00000058);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00510022 name=FUN_00510022 size=13 ====

void FUN_00510022(void)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  void *unaff_R14;
  undefined8 in_stack_00000008;
  long in_stack_00000018;
  undefined8 in_stack_00000048;
  undefined8 in_stack_00000058;
  undefined8 in_stack_00000068;
  long in_stack_00000080;
  long in_stack_000001a8;
  void *in_stack_000001c8;
  
  operator_delete(unaff_R14);
  FUN_009a3e50(in_stack_00000008);
  if (in_stack_000001c8 != (void *)0x0) {
    puVar2 = *(undefined8 **)((long)in_stack_000001c8 + in_stack_000001a8 * 8);
    while (puVar2 != (undefined8 *)0x0) {
      puVar1 = (undefined8 *)*puVar2;
      if (puVar2[2] + -0x18 != in_stack_00000018) {
        refcount_delete_offset10();
      }
      operator_delete(puVar2);
      puVar2 = puVar1;
    }
    operator_delete(in_stack_000001c8);
  }
  json_value_destruct(in_stack_00000048);
  json_value_destruct(in_stack_00000068);
  if (in_stack_00000080 + -0x18 != in_stack_00000018) {
    refcount_delete_offset10();
  }
  json_value_destruct(in_stack_00000058);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0051002f name=FUN_0051002f size=7 ====

/* WARNING: Removing unreachable block (ram,0x0050fedc) */
/* WARNING: Removing unreachable block (ram,0x0050fee5) */
/* WARNING: Removing unreachable block (ram,0x0050feea) */
/* WARNING: Removing unreachable block (ram,0x0050fef3) */
/* WARNING: Removing unreachable block (ram,0x0050fef8) */
/* WARNING: Removing unreachable block (ram,0x0050ff07) */
/* WARNING: Removing unreachable block (ram,0x0050ff0c) */
/* WARNING: Removing unreachable block (ram,0x0050ff1b) */
/* WARNING: Removing unreachable block (ram,0x0050ff20) */
/* WARNING: Removing unreachable block (ram,0x0050ff2f) */
/* WARNING: Removing unreachable block (ram,0x0050ff34) */

void FUN_0051002f(void)

{
  long in_stack_00000018;
  undefined8 in_stack_00000048;
  undefined8 in_stack_00000058;
  undefined8 in_stack_00000068;
  long in_stack_00000080;
  
  json_value_destruct();
  json_value_destruct(in_stack_00000048);
  json_value_destruct(in_stack_00000068);
  if (in_stack_00000080 + -0x18 != in_stack_00000018) {
    refcount_delete_offset10();
  }
  json_value_destruct(in_stack_00000058);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00510036 name=FUN_00510036 size=25 ====

void FUN_00510036(void)

{
  undefined8 in_stack_00000058;
  undefined8 in_stack_00000068;
  undefined1 *in_stack_00000080;
  
  json_value_destruct();
  json_value_destruct(in_stack_00000068);
  if (in_stack_00000080 != &DAT_011c5338) {
    refcount_delete_offset10();
  }
  json_value_destruct(in_stack_00000058);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0051004f name=FUN_0051004f size=25 ====

void FUN_0051004f(void)

{
  undefined8 in_stack_00000058;
  undefined8 in_stack_00000068;
  undefined1 *in_stack_00000080;
  
  json_value_destruct();
  json_value_destruct(in_stack_00000068);
  if (in_stack_00000080 != &DAT_011c5338) {
    refcount_delete_offset10();
  }
  json_value_destruct(in_stack_00000058);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00510068 name=FUN_00510068 size=31 ====

void FUN_00510068(void)

{
  undefined1 *in_stack_00000008;
  
  if (in_stack_00000008 != &DAT_011c5338) {
    refcount_delete_offset10();
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00510088 name=FUN_00510088 size=22 ====

void FUN_00510088(void)

{
  long unaff_R14;
  
  if (unaff_R14 != 0) {
    qslotobject_release_destroy(unaff_R14 + 8);
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0051009e name=FUN_0051009e size=21 ====

void FUN_0051009e(void)

{
  FUN_0081f982(&stack0x00000090);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=005100b3 name=FUN_005100b3 size=22 ====

void FUN_005100b3(void)

{
  long unaff_R14;
  
  if (unaff_R14 != 0) {
    qslotobject_release_destroy(unaff_R14 + 8);
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=005100d0 name=FUN_005100d0 size=15 ====

void FUN_005100d0(void)

{
  long unaff_RBP;
  
  *(undefined1 *)(unaff_RBP + 0xa0) = 0;
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=005100e0 name=FUN_005100e0 size=15 ====

void FUN_005100e0(void)

{
  long unaff_RBX;
  
  *(undefined1 *)(unaff_RBX + 0xa0) = 0;
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=005100f0 name=FUN_005100f0 size=18 ====

void FUN_005100f0(void)

{
  undefined8 in_stack_00000020;
  
  FUN_0098fdbc(in_stack_00000020);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00510102 name=FUN_00510102 size=18 ====

void FUN_00510102(void)

{
  undefined8 in_stack_00000050;
  
  FUN_0098fdbc(in_stack_00000050);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00510114 name=FUN_00510114 size=17 ====

void FUN_00510114(void)

{
  long unaff_R12;
  
  *(undefined1 *)(unaff_R12 + 0xa0) = 0;
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00510126 name=FUN_00510126 size=25 ====

void FUN_00510126(void)

{
  long *unaff_RBX;
  long unaff_RBP;
  
  if (*unaff_RBX + -0x18 != unaff_RBP) {
    FUN_009e77b8();
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00510140 name=FUN_00510140 size=30 ====

void FUN_00510140(void)

{
  long in_stack_000000d8;
  
  __cxa_begin_catch();
  operator_delete(*(void **)(in_stack_000000d8 + 8));
                    /* WARNING: Subroutine does not return */
                    /* try { // try from 00510159 to 0051015d has its CatchHandler @ 00510214 */
  __cxa_rethrow();
}


// ==== entry=00510194 name=FUN_00510194 size=115 ====

void FUN_00510194(void)

{
  long in_stack_000000a0;
  long in_stack_000000b0;
  long in_stack_000000b8;
  
  __cxa_begin_catch();
  if (in_stack_000000a0 + 0x10 == in_stack_000000b0) {
    in_stack_000000b8 = in_stack_000000b8 + 8;
  }
  operator_delete(*(void **)(in_stack_000000b8 + -8));
                    /* WARNING: Subroutine does not return */
                    /* try { // try from 00510202 to 00510206 has its CatchHandler @ 0051015e */
  __cxa_rethrow();
}


// ==== entry=00510207 name=FUN_00510207 size=13 ====

void FUN_00510207(void)

{
  __cxa_begin_catch();
                    /* WARNING: Subroutine does not return */
                    /* try { // try from 0051020f to 00510213 has its CatchHandler @ 00510229 */
  __cxa_rethrow();
}


// ==== entry=00510270 name=FUN_00510270 size=18 ====

void FUN_00510270(void)

{
  undefined8 in_stack_00000018;
  
  FUN_009ef0b6(in_stack_00000018);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00510282 name=FUN_00510282 size=33 ====

int FUN_00510282(undefined8 param_1,undefined8 param_2,long param_3)

{
  long *unaff_RBP;
  int unaff_R14D;
  
  if (param_3 == 1) {
    __cxa_begin_catch();
    __cxa_end_catch();
    return unaff_R14D - *(int *)(*unaff_RBP + 0x14);
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=005102a4 name=FUN_005102a4 size=11 ====

void FUN_005102a4(void)

{
  undefined1 *unaff_RBX;
  
  *unaff_RBX = 0;
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=005102b0 name=FUN_005102b0 size=33 ====

int FUN_005102b0(undefined8 param_1,undefined8 param_2,long param_3)

{
  long *unaff_RBP;
  int unaff_R14D;
  
  if (param_3 == 1) {
    __cxa_begin_catch();
    __cxa_end_catch();
    return unaff_R14D - *(int *)(*unaff_RBP + 0x14);
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=005102d2 name=FUN_005102d2 size=11 ====

void FUN_005102d2(void)

{
  undefined1 *unaff_RBX;
  
  *unaff_RBX = 0;
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=005102de name=FUN_005102de size=22 ====

void FUN_005102de(void)

{
                    /* WARNING: Subroutine does not return */
  __cxa_throw();
}


// ==== entry=005102f4 name=FUN_005102f4 size=16 ====

void FUN_005102f4(void)

{
  __cxa_free_exception();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00510304 name=FUN_00510304 size=22 ====

void FUN_00510304(void)

{
                    /* WARNING: Subroutine does not return */
  __cxa_throw();
}


// ==== entry=0051031a name=FUN_0051031a size=16 ====

void FUN_0051031a(void)

{
  __cxa_free_exception();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0051032a name=FUN_0051032a size=11 ====

void FUN_0051032a(void)

{
  undefined1 *unaff_RBX;
  
  *unaff_RBX = 0;
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00510336 name=FUN_00510336 size=12 ====

void FUN_00510336(void)

{
  undefined1 *unaff_R14;
  
  *unaff_R14 = 0;
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00510342 name=FUN_00510342 size=11 ====

void FUN_00510342(void)

{
  undefined1 *unaff_RBX;
  
  *unaff_RBX = 0;
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0051034e name=FUN_0051034e size=18 ====

void FUN_0051034e(void)

{
  undefined8 in_stack_00000048;
  
  FUN_009ef0b6(in_stack_00000048);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00510360 name=FUN_00510360 size=120 ====

void FUN_00510360(void)

{
  void *pvVar1;
  undefined8 *puVar2;
  char cVar3;
  long unaff_RBX;
  void *unaff_RBP;
  undefined8 *puVar4;
  void *unaff_R13;
  
  operator_delete(unaff_R13,0x40);
  operator_delete(unaff_RBP,0x40);
  cVar3 = qatomic_int_deref(*(long *)(unaff_RBX + 0x38) + 0x10);
  if (cVar3 == '\0') {
    QHashData::free_helper(*(_func_void_Node_ptr **)(unaff_RBX + 0x38));
  }
  pvVar1 = *(void **)(unaff_RBX + 0x30);
  if (pvVar1 != (void *)0x0) {
    if (*(long *)((long)pvVar1 + 0x28) != 0) {
      puVar4 = *(undefined8 **)(*(long *)((long)pvVar1 + 0x28) + *(long *)((long)pvVar1 + 8) * 8);
      while (puVar4 != (undefined8 *)0x0) {
        puVar2 = (undefined8 *)*puVar4;
        operator_delete(puVar4);
        puVar4 = puVar2;
      }
      operator_delete(*(void **)((long)pvVar1 + 0x28));
    }
    operator_delete(pvVar1,0x30);
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=005103d8 name=FUN_005103d8 size=31 ====

void FUN_005103d8(void)

{
  void *pvVar1;
  undefined8 *puVar2;
  char cVar3;
  long unaff_RBX;
  void *unaff_RBP;
  undefined8 *puVar4;
  void *unaff_R12;
  
  operator_delete(unaff_R12,0x20);
  operator_delete(unaff_RBP,0x40);
  cVar3 = qatomic_int_deref(*(long *)(unaff_RBX + 0x38) + 0x10);
  if (cVar3 == '\0') {
    QHashData::free_helper(*(_func_void_Node_ptr **)(unaff_RBX + 0x38));
  }
  pvVar1 = *(void **)(unaff_RBX + 0x30);
  if (pvVar1 != (void *)0x0) {
    if (*(long *)((long)pvVar1 + 0x28) != 0) {
      puVar4 = *(undefined8 **)(*(long *)((long)pvVar1 + 0x28) + *(long *)((long)pvVar1 + 8) * 8);
      while (puVar4 != (undefined8 *)0x0) {
        puVar2 = (undefined8 *)*puVar4;
        operator_delete(puVar4);
        puVar4 = puVar2;
      }
      operator_delete(*(void **)((long)pvVar1 + 0x28));
    }
    operator_delete(pvVar1,0x30);
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=005103f8 name=FUN_005103f8 size=21 ====

void FUN_005103f8(void)

{
  void *unaff_RBP;
  
  operator_delete(unaff_RBP,0x20);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0051040d name=FUN_0051040d size=21 ====

void FUN_0051040d(void)

{
  void *unaff_R14;
  
  operator_delete(unaff_R14,0x40);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00510422 name=FUN_00510422 size=23 ====

void FUN_00510422(void)

{
  void *in_stack_00000010;
  
  if (in_stack_00000010 != (void *)0x0) {
    operator_delete(in_stack_00000010);
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0051043a name=FUN_0051043a size=9 ====

void FUN_0051043a(void)

{
  undefined1 *unaff_R15;
  
  *unaff_R15 = 0;
                    /* WARNING: Subroutine does not return */
  std::terminate();
}


// ==== entry=00510443 name=FUN_00510443 size=17 ====

void FUN_00510443(void)

{
  long *unaff_R14;
  
  (**(code **)(*unaff_R14 + 8))();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00510454 name=FUN_00510454 size=34 ====

void FUN_00510454(void)

{
  void *unaff_RBP;
  void *unaff_R14;
  
  operator_delete(unaff_RBP,0x30);
  operator_delete(unaff_R14,0x20);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00510476 name=FUN_00510476 size=15 ====

void FUN_00510476(void)

{
  void *unaff_RBP;
  void *unaff_R14;
  
  operator_delete(unaff_RBP,0x60);
  operator_delete(unaff_R14,0x20);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00510486 name=FUN_00510486 size=56 ====

void FUN_00510486(void)

{
  char in_stack_00000050;
  code *in_stack_00000068;
  code *in_stack_00000070;
  
  if (in_stack_00000050 != '\0') {
    if (in_stack_00000068 == (code *)0x0) {
                    /* WARNING: Subroutine does not return */
      std::__throw_bad_function_call();
    }
    (*in_stack_00000070)(&stack0x00000058);
  }
  if (in_stack_00000068 != (code *)0x0) {
    (*in_stack_00000068)(&stack0x00000058,&stack0x00000058,3);
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0051049a name=FUN_0051049a size=81 ====

void FUN_0051049a(void)

{
  code *in_stack_00000020;
  code *in_stack_00000040;
  code *in_stack_00000068;
  
  if (in_stack_00000068 != (code *)0x0) {
    (*in_stack_00000068)(&stack0x00000058,&stack0x00000058,3);
  }
  if (in_stack_00000020 != (code *)0x0) {
    (*in_stack_00000020)();
  }
  if (in_stack_00000040 != (code *)0x0) {
    (*in_stack_00000040)(&stack0x00000030,&stack0x00000030,3);
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00510510 name=FUN_00510510 size=12 ====

void FUN_00510510(void)

{
  undefined1 *unaff_R14;
  
  *unaff_R14 = 0;
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00510520 name=FUN_00510520 size=21 ====

void FUN_00510520(void)

{
  long unaff_R14;
  
  *(undefined1 *)(unaff_R14 + 0x138) = 0;
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00510536 name=FUN_00510536 size=18 ====

void FUN_00510536(void)

{
  undefined8 in_stack_00000020;
  
  FUN_0098fdbc(in_stack_00000020);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00510548 name=FUN_00510548 size=18 ====

void FUN_00510548(void)

{
  undefined8 in_stack_00000050;
  
  FUN_0098fdbc(in_stack_00000050);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0051055a name=FUN_0051055a size=81 ====

void FUN_0051055a(void)

{
  code *in_stack_00000020;
  code *in_stack_00000040;
  code *in_stack_00000068;
  
  if (in_stack_00000068 != (code *)0x0) {
    (*in_stack_00000068)(&stack0x00000058,&stack0x00000058,3);
  }
  if (in_stack_00000020 != (code *)0x0) {
    (*in_stack_00000020)();
  }
  if (in_stack_00000040 != (code *)0x0) {
    (*in_stack_00000040)(&stack0x00000030,&stack0x00000030,3);
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=005105ab name=FUN_005105ab size=56 ====

void FUN_005105ab(void)

{
  char in_stack_00000050;
  code *in_stack_00000068;
  code *in_stack_00000070;
  
  if (in_stack_00000050 != '\0') {
    if (in_stack_00000068 == (code *)0x0) {
                    /* WARNING: Subroutine does not return */
      std::__throw_bad_function_call();
    }
    (*in_stack_00000070)(&stack0x00000058);
  }
  if (in_stack_00000068 != (code *)0x0) {
    (*in_stack_00000068)(&stack0x00000058,&stack0x00000058,3);
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=005105e4 name=FUN_005105e4 size=30 ====

void FUN_005105e4(void)

{
  undefined8 *unaff_RBP;
  
  if ((undefined1 *)*unaff_RBP != &DAT_011c5338) {
    FUN_009efe24();
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00510602 name=FUN_00510602 size=16 ====

void FUN_00510602(void)

{
  FUN_009f5a46();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00510612 name=FUN_00510612 size=16 ====

void FUN_00510612(void)

{
  FUN_009f5a46();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00510622 name=FUN_00510622 size=62 ====

void FUN_00510622(void)

{
  undefined1 *in_stack_00000048;
  undefined1 *in_stack_00000058;
  
  if (in_stack_00000048 != &DAT_011c5338) {
    FUN_009efe24();
  }
  FUN_009f55d0();
  if (in_stack_00000058 != &DAT_011c5338) {
    FUN_009efe24();
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00510660 name=FUN_00510660 size=13 ====

void FUN_00510660(void)

{
  __cxa_begin_catch();
                    /* WARNING: Subroutine does not return */
                    /* try { // try from 00510668 to 0051066c has its CatchHandler @ 0051066d */
  __cxa_rethrow();
}


// ==== entry=005106b2 name=FUN_005106b2 size=21 ====

void FUN_005106b2(void)

{
  void *unaff_R12;
  
  operator_delete(unaff_R12,0x18);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=005106c8 name=FUN_005106c8 size=18 ====

void FUN_005106c8(void)

{
  undefined8 in_stack_00000010;
  
  FUN_009f5a46(in_stack_00000010);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=005106da name=FUN_005106da size=15 ====

void FUN_005106da(void)

{
  long unaff_RBX;
  
  *(undefined1 *)(unaff_RBX + 0x138) = 0;
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=005106ea name=FUN_005106ea size=15 ====

void FUN_005106ea(void)

{
  long unaff_RBX;
  
  *(undefined1 *)(unaff_RBX + 0x138) = 0;
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=005106fa name=FUN_005106fa size=33 ====

int FUN_005106fa(undefined8 param_1,undefined8 param_2,long param_3)

{
  long *unaff_RBP;
  int unaff_R14D;
  
  if (param_3 == 1) {
    __cxa_begin_catch();
    __cxa_end_catch();
    return unaff_R14D - *(int *)(*unaff_RBP + 0x14);
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0051071c name=FUN_0051071c size=11 ====

void FUN_0051071c(void)

{
  undefined1 *unaff_RBX;
  
  *unaff_RBX = 0;
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00510728 name=FUN_00510728 size=13 ====

void FUN_00510728(void)

{
  undefined1 *in_stack_00000008;
  
  *in_stack_00000008 = 0;
                    /* WARNING: Subroutine does not return */
  std::terminate();
}


// ==== entry=00510735 name=FUN_00510735 size=126 ====

void FUN_00510735(void)

{
  code *pcVar1;
  long unaff_RBX;
  void *unaff_RBP;
  _func_void_Node_ptr *p_Var2;
  void *unaff_R12;
  void *unaff_R14;
  
  operator_delete(unaff_RBP,0x50);
  operator_delete(unaff_R12,0x20);
  operator_delete(unaff_R14,0x18);
  p_Var2 = *(_func_void_Node_ptr **)(unaff_RBX + 0xa8);
  pcVar1 = p_Var2 + 0x10;
  if (*(int *)(p_Var2 + 0x10) != 0) {
    if (*(int *)(p_Var2 + 0x10) == -1) goto LAB_0051077d;
    LOCK();
    *(int *)pcVar1 = *(int *)pcVar1 + -1;
    UNLOCK();
    if (*(int *)pcVar1 != 0) goto LAB_0051077d;
    p_Var2 = *(_func_void_Node_ptr **)(unaff_RBX + 0xa8);
  }
  QHashData::free_helper(p_Var2);
LAB_0051077d:
  if (*(long *)(unaff_RBX + 0x50) != 0) {
    FUN_009f5d6e(unaff_RBX + 0x50);
  }
  FUN_009f5804();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=005107b3 name=FUN_005107b3 size=13 ====

void FUN_005107b3(void)

{
  __cxa_begin_catch();
                    /* WARNING: Subroutine does not return */
                    /* try { // try from 005107bb to 005107bf has its CatchHandler @ 005107d2 */
  __cxa_rethrow();
}


// ==== entry=005107c0 name=FUN_005107c0 size=18 ====

void FUN_005107c0(void)

{
  code *pcVar1;
  long unaff_RBX;
  void *unaff_RBP;
  _func_void_Node_ptr *p_Var2;
  void *unaff_R12;
  void *unaff_R14;
  
  operator_delete(unaff_RBP,0x30);
  operator_delete(unaff_R12,0x20);
  operator_delete(unaff_R14,0x18);
  p_Var2 = *(_func_void_Node_ptr **)(unaff_RBX + 0xa8);
  pcVar1 = p_Var2 + 0x10;
  if (*(int *)(p_Var2 + 0x10) != 0) {
    if (*(int *)(p_Var2 + 0x10) == -1) goto LAB_0051077d;
    LOCK();
    *(int *)pcVar1 = *(int *)pcVar1 + -1;
    UNLOCK();
    if (*(int *)pcVar1 != 0) goto LAB_0051077d;
    p_Var2 = *(_func_void_Node_ptr **)(unaff_RBX + 0xa8);
  }
  QHashData::free_helper(p_Var2);
LAB_0051077d:
  if (*(long *)(unaff_RBX + 0x50) != 0) {
    FUN_009f5d6e(unaff_RBX + 0x50);
  }
  FUN_009f5804();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=005107fe name=FUN_005107fe size=21 ====

void FUN_005107fe(void)

{
  code *pcVar1;
  long unaff_RBX;
  void *unaff_RBP;
  _func_void_Node_ptr *p_Var2;
  void *unaff_R14;
  
  operator_delete(unaff_RBP,0x40);
  operator_delete(unaff_R14,0x18);
  p_Var2 = *(_func_void_Node_ptr **)(unaff_RBX + 0xa8);
  pcVar1 = p_Var2 + 0x10;
  if (*(int *)(p_Var2 + 0x10) != 0) {
    if (*(int *)(p_Var2 + 0x10) == -1) goto LAB_0051077d;
    LOCK();
    *(int *)pcVar1 = *(int *)pcVar1 + -1;
    UNLOCK();
    if (*(int *)pcVar1 != 0) goto LAB_0051077d;
    p_Var2 = *(_func_void_Node_ptr **)(unaff_RBX + 0xa8);
  }
  QHashData::free_helper(p_Var2);
LAB_0051077d:
  if (*(long *)(unaff_RBX + 0x50) != 0) {
    FUN_009f5d6e(unaff_RBX + 0x50);
  }
  FUN_009f5804();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00510824 name=FUN_00510824 size=12 ====

void FUN_00510824(void)

{
  undefined1 *unaff_R14;
  
  *unaff_R14 = 0;
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00510830 name=FUN_00510830 size=14 ====

void FUN_00510830(void)

{
  long unaff_R12;
  
  *(undefined1 *)(unaff_R12 + 0x21) = 0;
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0051083e name=FUN_0051083e size=14 ====

void FUN_0051083e(void)

{
  long unaff_R12;
  
  *(undefined1 *)(unaff_R12 + 0x21) = 0;
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0051084c name=FUN_0051084c size=14 ====

void FUN_0051084c(void)

{
  long unaff_R12;
  
  *(undefined1 *)(unaff_R12 + 0x21) = 0;
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0051085a name=FUN_0051085a size=13 ====

void FUN_0051085a(void)

{
  long unaff_R13;
  
  *(undefined1 *)(unaff_R13 + 0x21) = 0;
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00510868 name=FUN_00510868 size=33 ====

int FUN_00510868(undefined8 param_1,undefined8 param_2,long param_3)

{
  long *unaff_RBP;
  int unaff_R14D;
  
  if (param_3 == 1) {
    __cxa_begin_catch();
    __cxa_end_catch();
    return unaff_R14D - *(int *)(*unaff_RBP + 0x14);
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0051088a name=FUN_0051088a size=22 ====

void FUN_0051088a(void)

{
                    /* WARNING: Subroutine does not return */
  __cxa_throw();
}


// ==== entry=005108a0 name=FUN_005108a0 size=16 ====

void FUN_005108a0(void)

{
  __cxa_free_exception();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=005108b0 name=FUN_005108b0 size=11 ====

void FUN_005108b0(void)

{
  undefined1 *unaff_RBX;
  
  *unaff_RBX = 0;
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=005108bc name=FUN_005108bc size=12 ====

void FUN_005108bc(void)

{
  undefined1 *unaff_R14;
  
  *unaff_R14 = 0;
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=005108c8 name=FUN_005108c8 size=16 ====

void FUN_005108c8(void)

{
  __cxa_free_exception();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=005108d8 name=FUN_005108d8 size=22 ====

void FUN_005108d8(void)

{
                    /* WARNING: Subroutine does not return */
  __cxa_throw();
}


// ==== entry=005108ee name=FUN_005108ee size=10 ====

void FUN_005108ee(void)

{
  undefined1 *unaff_R13;
  
  *unaff_R13 = 0;
                    /* WARNING: Subroutine does not return */
  std::terminate();
}


// ==== entry=005108f8 name=FUN_005108f8 size=14 ====

void FUN_005108f8(void)

{
  long unaff_R12;
  
  *(undefined1 *)(unaff_R12 + 0x21) = 0;
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00510906 name=FUN_00510906 size=13 ====

void FUN_00510906(void)

{
  long unaff_R13;
  
  *(undefined1 *)(unaff_R13 + 0x21) = 0;
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00510914 name=FUN_00510914 size=13 ====

void FUN_00510914(void)

{
  long unaff_R13;
  
  *(undefined1 *)(unaff_R13 + 0x21) = 0;
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00510922 name=FUN_00510922 size=21 ====

void FUN_00510922(void)

{
  void *unaff_RBP;
  
  operator_delete(unaff_RBP,0x20);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00510938 name=FUN_00510938 size=47 ====

void FUN_00510938(void)

{
  long unaff_R15;
  ulong in_stack_00000030;
  
  if ((in_stack_00000030 != 0) && ((in_stack_00000030 & 1) != 0)) {
    QReadWriteLock::unlock();
  }
  *(undefined1 *)(unaff_R15 + 0x21) = 0;
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00510968 name=FUN_00510968 size=31 ====

void FUN_00510968(void)

{
  byte unaff_R12B;
  undefined7 unaff_000000a1;
  
  if ((CONCAT71(unaff_000000a1,unaff_R12B) != 0) && ((unaff_R12B & 1) != 0)) {
    QReadWriteLock::unlock();
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00510988 name=FUN_00510988 size=44 ====

void FUN_00510988(void)

{
  byte unaff_R12B;
  undefined7 unaff_000000a1;
  long unaff_R13;
  
  if ((CONCAT71(unaff_000000a1,unaff_R12B) != 0) && ((unaff_R12B & 1) != 0)) {
    QReadWriteLock::unlock();
  }
  *(undefined1 *)(unaff_R13 + 0x21) = 0;
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=005109b4 name=FUN_005109b4 size=31 ====

void FUN_005109b4(void)

{
  byte unaff_R12B;
  undefined7 unaff_000000a1;
  
  if ((CONCAT71(unaff_000000a1,unaff_R12B) != 0) && ((unaff_R12B & 1) != 0)) {
    QReadWriteLock::unlock();
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=005109d4 name=FUN_005109d4 size=54 ====

void FUN_005109d4(void)

{
  code *pcVar1;
  _func_void_Node_ptr *in_stack_00000078;
  
  pcVar1 = in_stack_00000078 + 0x10;
  if (*(int *)(in_stack_00000078 + 0x10) != 0) {
    if (*(int *)(in_stack_00000078 + 0x10) == -1) goto LAB_005109f0;
    LOCK();
    *(int *)pcVar1 = *(int *)pcVar1 + -1;
    UNLOCK();
    if (*(int *)pcVar1 != 0) goto LAB_005109f0;
  }
  QHashData::free_helper(in_stack_00000078);
LAB_005109f0:
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00510a10 name=FUN_00510a10 size=13 ====

void FUN_00510a10(void)

{
  long unaff_R14;
  
  *(undefined1 *)(unaff_R14 + 0x48) = 0;
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00510a1e name=FUN_00510a1e size=12 ====

void FUN_00510a1e(void)

{
  long unaff_RBP;
  
  *(undefined1 *)(unaff_RBP + 0x48) = 0;
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00510a2a name=FUN_00510a2a size=12 ====

void FUN_00510a2a(void)

{
  long unaff_RBX;
  
  *(undefined1 *)(unaff_RBX + 0x48) = 0;
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00510a36 name=FUN_00510a36 size=12 ====

void FUN_00510a36(void)

{
  long unaff_RBX;
  
  *(undefined1 *)(unaff_RBX + 0x48) = 0;
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00510a42 name=FUN_00510a42 size=18 ====

void FUN_00510a42(void)

{
  undefined8 in_stack_00000020;
  
  FUN_0098fdbc(in_stack_00000020);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00510a54 name=FUN_00510a54 size=30 ====

void FUN_00510a54(void)

{
  undefined8 *unaff_RBP;
  
  if ((undefined1 *)*unaff_RBP != &DAT_011c5338) {
    FUN_009fabba();
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00510a72 name=FUN_00510a72 size=18 ====

void FUN_00510a72(void)

{
  undefined8 in_stack_00000008;
  
  FUN_00a00cd0(in_stack_00000008);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00510a84 name=FUN_00510a84 size=56 ====

void FUN_00510a84(void)

{
  char in_stack_00000050;
  code *in_stack_00000068;
  code *in_stack_00000070;
  
  if (in_stack_00000050 != '\0') {
    if (in_stack_00000068 == (code *)0x0) {
                    /* WARNING: Subroutine does not return */
      std::__throw_bad_function_call();
    }
    (*in_stack_00000070)(&stack0x00000058);
  }
  if (in_stack_00000068 != (code *)0x0) {
    (*in_stack_00000068)(&stack0x00000058,&stack0x00000058,3);
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00510a98 name=FUN_00510a98 size=81 ====

void FUN_00510a98(void)

{
  code *in_stack_00000020;
  code *in_stack_00000040;
  code *in_stack_00000068;
  
  if (in_stack_00000068 != (code *)0x0) {
    (*in_stack_00000068)(&stack0x00000058,&stack0x00000058,3);
  }
  if (in_stack_00000020 != (code *)0x0) {
    (*in_stack_00000020)();
  }
  if (in_stack_00000040 != (code *)0x0) {
    (*in_stack_00000040)(&stack0x00000030,&stack0x00000030,3);
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00510b0e name=FUN_00510b0e size=63 ====

void FUN_00510b0e(void)

{
  undefined8 in_stack_00000008;
  undefined1 *in_stack_00000040;
  undefined1 *in_stack_00000048;
  
  if (in_stack_00000048 != &DAT_011c5338) {
    FUN_009fabba();
  }
  if (in_stack_00000040 != &DAT_011c5338) {
    FUN_009fabba();
  }
  FUN_00a013de(in_stack_00000008);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00510b4e name=FUN_00510b4e size=71 ====

void FUN_00510b4e(void)

{
  undefined8 in_stack_00000018;
  undefined1 *in_stack_00000050;
  undefined1 *in_stack_00000058;
  
  if (in_stack_00000058 != &DAT_011c5338) {
    FUN_009fabba();
  }
  if (in_stack_00000050 != &DAT_011c5338) {
    FUN_009fabba();
  }
  FUN_00a013de(in_stack_00000018);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00510b96 name=FUN_00510b96 size=68 ====

void FUN_00510b96(void)

{
  undefined8 unaff_retaddr;
  undefined1 *in_stack_000000a0;
  undefined1 *in_stack_000000c0;
  
  if (in_stack_000000c0 != &DAT_011c5338) {
    FUN_009fabba();
  }
  if (in_stack_000000a0 != &DAT_011c5338) {
    FUN_009fabba();
  }
  FUN_00a013de(unaff_retaddr);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00510bda name=FUN_00510bda size=17 ====

void FUN_00510bda(void)

{
  undefined8 unaff_retaddr;
  
  FUN_00a013de(unaff_retaddr);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00510bec name=FUN_00510bec size=26 ====

void FUN_00510bec(void)

{
  long unaff_R15;
  undefined8 in_stack_00000010;
  
  FUN_00a013de(in_stack_00000010);
  *(undefined1 *)(unaff_R15 + 0x48) = 0;
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00510c06 name=FUN_00510c06 size=33 ====

int FUN_00510c06(undefined8 param_1,undefined8 param_2,long param_3)

{
  long *unaff_RBP;
  int unaff_R14D;
  
  if (param_3 == 1) {
    __cxa_begin_catch();
    __cxa_end_catch();
    return unaff_R14D - *(int *)(*unaff_RBP + 0x14);
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00510c28 name=FUN_00510c28 size=22 ====

void FUN_00510c28(void)

{
                    /* WARNING: Subroutine does not return */
  __cxa_throw();
}


// ==== entry=00510c3e name=FUN_00510c3e size=16 ====

void FUN_00510c3e(void)

{
  __cxa_free_exception();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00510c4e name=FUN_00510c4e size=11 ====

void FUN_00510c4e(void)

{
  undefined1 *unaff_RBX;
  
  *unaff_RBX = 0;
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00510c5a name=FUN_00510c5a size=13 ====

void FUN_00510c5a(void)

{
  undefined1 *in_stack_00000008;
  
  *in_stack_00000008 = 0;
                    /* WARNING: Subroutine does not return */
  std::terminate();
}


// ==== entry=00510c67 name=FUN_00510c67 size=130 ====

void FUN_00510c67(void)

{
  code *pcVar1;
  void *pvVar2;
  void *unaff_RBX;
  long unaff_RBP;
  _func_void_Node_ptr *p_Var3;
  void *unaff_R12;
  void *unaff_R14;
  
  operator_delete(unaff_RBX,0x50);
  operator_delete(unaff_R12,0x20);
  operator_delete(unaff_R14,0x18);
  p_Var3 = *(_func_void_Node_ptr **)(unaff_RBP + 0x38);
  pcVar1 = p_Var3 + 0x10;
  if (*(int *)(p_Var3 + 0x10) != 0) {
    if (*(int *)(p_Var3 + 0x10) == -1) goto LAB_00510cac;
    LOCK();
    *(int *)pcVar1 = *(int *)pcVar1 + -1;
    UNLOCK();
    if (*(int *)pcVar1 != 0) goto LAB_00510cac;
    p_Var3 = *(_func_void_Node_ptr **)(unaff_RBP + 0x38);
  }
  QHashData::free_helper(p_Var3);
LAB_00510cac:
  pvVar2 = *(void **)(unaff_RBP + 0x28);
  if (pvVar2 != (void *)0x0) {
    if (*(void **)((long)pvVar2 + 0x10) != (void *)0x0) {
      operator_delete(*(void **)((long)pvVar2 + 0x10));
    }
    operator_delete(pvVar2,0x28);
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00510ce9 name=FUN_00510ce9 size=21 ====

void FUN_00510ce9(void)

{
  void *unaff_RBX;
  
  operator_delete(unaff_RBX,0x28);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00510cfe name=FUN_00510cfe size=18 ====

void FUN_00510cfe(void)

{
  code *pcVar1;
  void *pvVar2;
  void *unaff_RBX;
  long unaff_RBP;
  _func_void_Node_ptr *p_Var3;
  void *unaff_R12;
  void *unaff_R14;
  
  operator_delete(unaff_RBX,0x30);
  operator_delete(unaff_R12,0x20);
  operator_delete(unaff_R14,0x18);
  p_Var3 = *(_func_void_Node_ptr **)(unaff_RBP + 0x38);
  pcVar1 = p_Var3 + 0x10;
  if (*(int *)(p_Var3 + 0x10) != 0) {
    if (*(int *)(p_Var3 + 0x10) == -1) goto LAB_00510cac;
    LOCK();
    *(int *)pcVar1 = *(int *)pcVar1 + -1;
    UNLOCK();
    if (*(int *)pcVar1 != 0) goto LAB_00510cac;
    p_Var3 = *(_func_void_Node_ptr **)(unaff_RBP + 0x38);
  }
  QHashData::free_helper(p_Var3);
LAB_00510cac:
  pvVar2 = *(void **)(unaff_RBP + 0x28);
  if (pvVar2 != (void *)0x0) {
    if (*(void **)((long)pvVar2 + 0x10) != (void *)0x0) {
      operator_delete(*(void **)((long)pvVar2 + 0x10));
    }
    operator_delete(pvVar2,0x28);
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00510d10 name=FUN_00510d10 size=21 ====

void FUN_00510d10(void)

{
  code *pcVar1;
  void *pvVar2;
  void *unaff_RBX;
  long unaff_RBP;
  _func_void_Node_ptr *p_Var3;
  void *unaff_R14;
  
  operator_delete(unaff_RBX,0x40);
  operator_delete(unaff_R14,0x18);
  p_Var3 = *(_func_void_Node_ptr **)(unaff_RBP + 0x38);
  pcVar1 = p_Var3 + 0x10;
  if (*(int *)(p_Var3 + 0x10) != 0) {
    if (*(int *)(p_Var3 + 0x10) == -1) goto LAB_00510cac;
    LOCK();
    *(int *)pcVar1 = *(int *)pcVar1 + -1;
    UNLOCK();
    if (*(int *)pcVar1 != 0) goto LAB_00510cac;
    p_Var3 = *(_func_void_Node_ptr **)(unaff_RBP + 0x38);
  }
  QHashData::free_helper(p_Var3);
LAB_00510cac:
  pvVar2 = *(void **)(unaff_RBP + 0x28);
  if (pvVar2 != (void *)0x0) {
    if (*(void **)((long)pvVar2 + 0x10) != (void *)0x0) {
      operator_delete(*(void **)((long)pvVar2 + 0x10));
    }
    operator_delete(pvVar2,0x28);
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00510d26 name=FUN_00510d26 size=42 ====

void FUN_00510d26(void)

{
  long unaff_R13;
  long *unaff_R15;
  void *in_stack_00000028;
  
  operator_delete(in_stack_00000028,0x20);
  if ((long *)*unaff_R15 != (long *)0x0) {
    (**(code **)(*(long *)*unaff_R15 + 8))();
  }
  *(undefined1 *)(unaff_R13 + 0x48) = 0;
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00510d50 name=FUN_00510d50 size=12 ====

void FUN_00510d50(void)

{
  undefined1 *unaff_R14;
  
  *unaff_R14 = 0;
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00510d5c name=FUN_00510d5c size=13 ====

void FUN_00510d5c(void)

{
  long unaff_R13;
  
  *(undefined1 *)(unaff_R13 + 0x78) = 0;
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00510d6a name=FUN_00510d6a size=13 ====

void FUN_00510d6a(void)

{
  long unaff_R14;
  
  *(undefined1 *)(unaff_R14 + 0x78) = 0;
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00510d78 name=FUN_00510d78 size=12 ====

void FUN_00510d78(void)

{
  long unaff_RBX;
  
  *(undefined1 *)(unaff_RBX + 0x78) = 0;
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00510d84 name=FUN_00510d84 size=12 ====

void FUN_00510d84(void)

{
  long unaff_RBX;
  
  *(undefined1 *)(unaff_RBX + 0x78) = 0;
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00510d90 name=FUN_00510d90 size=12 ====

void FUN_00510d90(void)

{
  long unaff_RBX;
  
  *(undefined1 *)(unaff_RBX + 0x78) = 0;
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00510d9c name=FUN_00510d9c size=12 ====

void FUN_00510d9c(void)

{
  long unaff_RBX;
  
  *(undefined1 *)(unaff_RBX + 0x78) = 0;
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00510da8 name=FUN_00510da8 size=12 ====

void FUN_00510da8(void)

{
  long unaff_RBX;
  
  *(undefined1 *)(unaff_RBX + 0x78) = 0;
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00510db4 name=FUN_00510db4 size=12 ====

void FUN_00510db4(void)

{
  long unaff_RBX;
  
  *(undefined1 *)(unaff_RBX + 0x78) = 0;
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00510dc0 name=FUN_00510dc0 size=12 ====

void FUN_00510dc0(void)

{
  long unaff_RBX;
  
  *(undefined1 *)(unaff_RBX + 0x78) = 0;
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00510dcc name=FUN_00510dcc size=12 ====

void FUN_00510dcc(void)

{
  long unaff_RBX;
  
  *(undefined1 *)(unaff_RBX + 0x78) = 0;
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00510dd8 name=FUN_00510dd8 size=12 ====

void FUN_00510dd8(void)

{
  long unaff_RBX;
  
  *(undefined1 *)(unaff_RBX + 0x78) = 0;
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00510de4 name=FUN_00510de4 size=16 ====

void FUN_00510de4(void)

{
  qt_byte_array_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00510df4 name=FUN_00510df4 size=16 ====

void FUN_00510df4(void)

{
  qt_byte_array_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00510e04 name=FUN_00510e04 size=16 ====

void FUN_00510e04(void)

{
  FUN_0067cf84();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00510e14 name=FUN_00510e14 size=41 ====

void FUN_00510e14(void)

{
  long unaff_RBP;
  long unaff_R12;
  long in_stack_00000018;
  
  if (unaff_RBP + -0x18 != unaff_R12) {
    refcount_release();
  }
  if (in_stack_00000018 + -0x18 != unaff_R12) {
    refcount_release();
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00510e3d name=FUN_00510e3d size=43 ====

void FUN_00510e3d(void)

{
  locale *unaff_RBP;
  long unaff_R12;
  long unaff_R14;
  long in_stack_00000008;
  long in_stack_00000018;
  
  std::locale::~locale(unaff_RBP);
  if (in_stack_00000008 + -0x18 != unaff_R12) {
    refcount_release();
  }
  if (unaff_R14 + -0x18 != unaff_R12) {
    refcount_release();
  }
  if (in_stack_00000018 + -0x18 != unaff_R12) {
    refcount_release();
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00510e68 name=FUN_00510e68 size=27 ====

void FUN_00510e68(void)

{
  long unaff_R12;
  long in_stack_00000018;
  
  if (in_stack_00000018 + -0x18 != unaff_R12) {
    refcount_release();
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00510e84 name=FUN_00510e84 size=33 ====

int FUN_00510e84(undefined8 param_1,undefined8 param_2,long param_3)

{
  long *unaff_RBP;
  int unaff_R14D;
  
  if (param_3 == 1) {
    __cxa_begin_catch();
    __cxa_end_catch();
    return unaff_R14D - *(int *)(*unaff_RBP + 0x14);
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00510ea6 name=FUN_00510ea6 size=11 ====

void FUN_00510ea6(void)

{
  undefined1 *unaff_RBX;
  
  *unaff_RBX = 0;
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00510eb2 name=FUN_00510eb2 size=22 ====

void FUN_00510eb2(void)

{
                    /* WARNING: Subroutine does not return */
  __cxa_throw();
}


// ==== entry=00510ec8 name=FUN_00510ec8 size=16 ====

void FUN_00510ec8(void)

{
  __cxa_free_exception();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00510ed8 name=FUN_00510ed8 size=33 ====

int FUN_00510ed8(undefined8 param_1,undefined8 param_2,long param_3)

{
  long *unaff_RBP;
  int unaff_R14D;
  
  if (param_3 == 1) {
    __cxa_begin_catch();
    __cxa_end_catch();
    return unaff_R14D - *(int *)(*unaff_RBP + 0x14);
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00510efa name=FUN_00510efa size=11 ====

void FUN_00510efa(void)

{
  undefined1 *unaff_RBX;
  
  *unaff_RBX = 0;
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00510f06 name=FUN_00510f06 size=22 ====

void FUN_00510f06(void)

{
                    /* WARNING: Subroutine does not return */
  __cxa_throw();
}


// ==== entry=00510f1c name=FUN_00510f1c size=16 ====

void FUN_00510f1c(void)

{
  __cxa_free_exception();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00510f2c name=FUN_00510f2c size=11 ====

void FUN_00510f2c(void)

{
  undefined1 *unaff_RBX;
  
  *unaff_RBX = 0;
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00510f38 name=FUN_00510f38 size=11 ====

void FUN_00510f38(void)

{
  undefined1 *unaff_RBX;
  
  *unaff_RBX = 0;
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00510f43 name=FUN_00510f43 size=16 ====

void FUN_00510f43(void)

{
  FUN_0081cbd0();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00510f53 name=FUN_00510f53 size=62 ====

void FUN_00510f53(void)

{
  undefined1 *in_stack_00000050;
  undefined1 *in_stack_00000060;
  
  if (in_stack_00000060 != &DAT_011c5338) {
    refcount_release();
  }
  if (in_stack_00000050 != &DAT_011c5338) {
    refcount_release();
  }
  FUN_0081cbd0();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00510f91 name=FUN_00510f91 size=51 ====

void FUN_00510f91(void)

{
  undefined1 *in_stack_00000070;
  undefined1 *in_stack_00000080;
  
  if (in_stack_00000080 != &DAT_011c5338) {
    refcount_release();
  }
  if (in_stack_00000070 != &DAT_011c5338) {
    refcount_release();
  }
  FUN_0081cbd0();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00510fc4 name=FUN_00510fc4 size=20 ====

void FUN_00510fc4(void)

{
  undefined1 *unaff_R14;
  undefined1 *in_stack_00000050;
  
  if (unaff_R14 != &DAT_011c5338) {
    refcount_release();
  }
  if (in_stack_00000050 != &DAT_011c5338) {
    refcount_release();
  }
  FUN_0081cbd0();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00510fd8 name=FUN_00510fd8 size=25 ====

void FUN_00510fd8(void)

{
  undefined1 *in_stack_00000070;
  
  if (in_stack_00000070 != &DAT_011c5338) {
    refcount_release();
  }
  FUN_0081cbd0();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00510ff1 name=FUN_00510ff1 size=20 ====

void FUN_00510ff1(void)

{
  undefined1 *unaff_R13;
  undefined1 *in_stack_00000070;
  
  if (unaff_R13 != &DAT_011c5338) {
    refcount_release();
  }
  if (in_stack_00000070 != &DAT_011c5338) {
    refcount_release();
  }
  FUN_0081cbd0();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00511005 name=FUN_00511005 size=32 ====

void FUN_00511005(void)

{
  undefined1 *in_stack_00000050;
  
  if (in_stack_00000050 != &DAT_011c5338) {
    refcount_release();
  }
  FUN_0081cbd0();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00511026 name=FUN_00511026 size=20 ====

void FUN_00511026(void)

{
  __cxa_guard_abort(&DAT_011c2790);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0051103a name=FUN_0051103a size=26 ====

void FUN_0051103a(void)

{
  long unaff_R12;
  long unaff_retaddr;
  
  if (unaff_retaddr + -0x18 != unaff_R12) {
    refcount_release();
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00511054 name=FUN_00511054 size=26 ====

void FUN_00511054(void)

{
  long unaff_R12;
  long unaff_retaddr;
  
  if (unaff_retaddr + -0x18 != unaff_R12) {
    refcount_release();
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0051106e name=FUN_0051106e size=20 ====

void FUN_0051106e(void)

{
  __cxa_guard_abort(&DAT_011c2780);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00511082 name=FUN_00511082 size=20 ====

void FUN_00511082(void)

{
  __cxa_guard_abort(&DAT_011c2770);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00511096 name=FUN_00511096 size=27 ====

void FUN_00511096(void)

{
  long unaff_R12;
  long in_stack_00000020;
  
  if (in_stack_00000020 + -0x18 != unaff_R12) {
    refcount_release();
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=005110b1 name=FUN_005110b1 size=46 ====

void FUN_005110b1(void)

{
  long unaff_R12;
  long in_stack_00000020;
  long in_stack_00000028;
  
  if (in_stack_00000028 + -0x18 != unaff_R12) {
    refcount_release();
  }
  if (in_stack_00000020 + -0x18 != unaff_R12) {
    refcount_release();
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=005110e0 name=FUN_005110e0 size=26 ====

void FUN_005110e0(void)

{
  long in_stack_00000088;
  
  if (in_stack_00000088 != 0) {
    FUN_00a04f38();
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=005110fa name=FUN_005110fa size=39 ====

void FUN_005110fa(void)

{
  void *unaff_R12;
  _Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *in_stack_00000098;
  
  operator_delete(unaff_R12,0x50);
  if (in_stack_00000098 != (_Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *)0x0) {
    std::_Sp_counted_base<(__gnu_cxx::_Lock_policy)2>::_M_release(in_stack_00000098);
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00511122 name=FUN_00511122 size=21 ====

void FUN_00511122(void)

{
  qt_byte_array_unref(&stack0x00000078);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00511137 name=FUN_00511137 size=41 ====

void FUN_00511137(void)

{
  void *unaff_RBX;
  _Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *in_stack_00000088;
  
  operator_delete(unaff_RBX,0x50);
  if (in_stack_00000088 != (_Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *)0x0) {
    std::_Sp_counted_base<(__gnu_cxx::_Lock_policy)2>::_M_release(in_stack_00000088);
  }
  qt_byte_array_unref(&stack0x00000078);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00511160 name=FUN_00511160 size=51 ====

void FUN_00511160(void)

{
  void *unaff_RBP;
  void *in_stack_00000020;
  _Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *in_stack_00000098;
  
  operator_delete(unaff_RBP,0x50);
  if (in_stack_00000098 != (_Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *)0x0) {
    std::_Sp_counted_base<(__gnu_cxx::_Lock_policy)2>::_M_release(in_stack_00000098);
  }
  if (in_stack_00000020 != (void *)0x0) {
    operator_delete(in_stack_00000020);
  }
  qt_byte_array_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00511193 name=FUN_00511193 size=7 ====

void FUN_00511193(void)

{
  qt_byte_array_unref(&stack0x00000078);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0051119a name=FUN_0051119a size=28 ====

void FUN_0051119a(void)

{
  long in_stack_00000090;
  
  if (in_stack_00000090 != 0) {
    FUN_00a04f38();
  }
  qt_byte_array_unref(&stack0x00000078);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=005111b6 name=FUN_005111b6 size=10 ====

void FUN_005111b6(void)

{
  qt_byte_array_unref(&stack0x00000078);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=005111c0 name=FUN_005111c0 size=20 ====

void FUN_005111c0(void)

{
  void *in_stack_00000020;
  long in_stack_00000080;
  
  if (in_stack_00000080 != 0) {
    FUN_00a04f38();
  }
  if (in_stack_00000020 != (void *)0x0) {
    operator_delete(in_stack_00000020);
  }
  qt_byte_array_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=005111d4 name=FUN_005111d4 size=22 ====

void FUN_005111d4(void)

{
  code *pcVar1;
  undefined8 uStack0000000000000188;
  
  uStack0000000000000188 = 0;
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ==== entry=005111ea name=FUN_005111ea size=98 ====

void FUN_005111ea(void)

{
  undefined8 in_stack_00000008;
  code *in_stack_000000b8;
  code *in_stack_00000140;
  code *in_stack_00000170;
  
  if (in_stack_000000b8 != (code *)0x0) {
    (*in_stack_000000b8)(&stack0x000000a8,&stack0x000000a8,3);
  }
  if (in_stack_00000140 != (code *)0x0) {
    (*in_stack_00000140)(in_stack_00000008,in_stack_00000008,3);
  }
  if (in_stack_00000170 != (code *)0x0) {
    (*in_stack_00000170)(&stack0x00000160,&stack0x00000160,3);
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0051124c name=FUN_0051124c size=325 ====

/* WARNING: Removing unreachable block (ram,0x0051158a) */
/* WARNING: Removing unreachable block (ram,0x00511598) */

void FUN_0051124c(void)

{
  long *plVar1;
  int *piVar2;
  int iVar3;
  void *pvVar4;
  undefined8 *puVar5;
  long *plVar6;
  long lVar7;
  undefined8 *puVar8;
  undefined8 *puVar9;
  QArrayData *pQVar10;
  undefined8 *puVar11;
  undefined8 *puVar12;
  undefined8 *puVar13;
  undefined8 in_stack_00000008;
  undefined8 in_stack_00000038;
  char in_stack_000000a0;
  code *in_stack_000000b8;
  code *in_stack_000000c0;
  void *in_stack_00000160;
  undefined8 *in_stack_00000170;
  undefined8 *in_stack_00000178;
  undefined8 *in_stack_00000180;
  undefined8 *in_stack_00000188;
  undefined8 *in_stack_00000190;
  long in_stack_000001a8;
  
  qt_byte_array_unref(in_stack_00000008);
  qt_byte_array_unref(in_stack_00000038);
  puVar9 = in_stack_00000190;
  puVar8 = in_stack_00000170;
  puVar11 = in_stack_00000180;
  puVar12 = in_stack_00000188;
  puVar13 = in_stack_00000178;
  do {
    if (puVar9 == puVar8) {
      if (in_stack_00000160 != (void *)0x0) {
        puVar8 = (undefined8 *)(in_stack_000001a8 + 8);
        for (puVar9 = in_stack_00000188; puVar9 < puVar8; puVar9 = puVar9 + 1) {
          operator_delete((void *)*puVar9);
        }
        operator_delete(in_stack_00000160);
      }
      if (in_stack_000000a0 != '\0') {
        if (in_stack_000000b8 == (code *)0x0) {
                    /* WARNING: Subroutine does not return */
          std::__throw_bad_function_call();
        }
        (*in_stack_000000c0)(&stack0x000000a8);
      }
      if (in_stack_000000b8 != (code *)0x0) {
        (*in_stack_000000b8)(&stack0x000000a8,&stack0x000000a8,3);
      }
                    /* WARNING: Subroutine does not return */
      cxa_throw_exception();
    }
    pvVar4 = (void *)*puVar8;
    if (pvVar4 != (void *)0x0) {
      puVar5 = *(undefined8 **)((long)pvVar4 + 0x10);
      if (puVar5 != (undefined8 *)0x0) {
        if ((undefined1 *)*puVar5 != &DAT_011c5338) {
          refcount_release();
        }
        operator_delete(puVar5,8);
      }
      if (*(void **)((long)pvVar4 + 0x38) != (void *)0x0) {
        operator_delete(*(void **)((long)pvVar4 + 0x38));
      }
      plVar6 = *(long **)((long)pvVar4 + 0x28);
      if (plVar6 != (long *)0x0) {
        LOCK();
        plVar1 = plVar6 + 1;
        lVar7 = *plVar1;
        *(int *)plVar1 = (int)*plVar1 + -1;
        UNLOCK();
        if ((int)lVar7 == 1) {
          (**(code **)(*plVar6 + 0x10))(plVar6);
          LOCK();
          piVar2 = (int *)((long)plVar6 + 0xc);
          iVar3 = *piVar2;
          *piVar2 = *piVar2 + -1;
          UNLOCK();
          if (iVar3 == 1) {
            (**(code **)(*plVar6 + 0x18))(plVar6);
          }
        }
      }
      pQVar10 = *(QArrayData **)((long)pvVar4 + 8);
      if (*(int *)pQVar10 == 0) {
LAB_00511353:
        QArrayData::deallocate(pQVar10,1,8);
      }
      else if (*(int *)pQVar10 != -1) {
        LOCK();
        *(int *)pQVar10 = *(int *)pQVar10 + -1;
        UNLOCK();
        if (*(int *)pQVar10 == 0) {
          pQVar10 = *(QArrayData **)((long)pvVar4 + 8);
          goto LAB_00511353;
        }
      }
      operator_delete(pvVar4,0x50);
    }
    puVar8 = puVar8 + 1;
    if (puVar11 == puVar8) {
      puVar12 = puVar12 + 1;
      puVar8 = (undefined8 *)*puVar12;
      puVar11 = (undefined8 *)(((long)puVar11 - (long)puVar13) + (long)puVar8);
      puVar13 = puVar8;
    }
  } while( true );
}


// ==== entry=00511391 name=FUN_00511391 size=43 ====

/* WARNING: Removing unreachable block (ram,0x0051158a) */
/* WARNING: Removing unreachable block (ram,0x00511598) */

void FUN_00511391(void)

{
  long *plVar1;
  int *piVar2;
  int iVar3;
  void *pvVar4;
  undefined8 *puVar5;
  long *plVar6;
  long lVar7;
  void *unaff_RBX;
  undefined8 *puVar8;
  undefined8 *puVar9;
  QArrayData *pQVar10;
  undefined8 *puVar11;
  undefined8 *puVar12;
  undefined8 *puVar13;
  char in_stack_000000a0;
  code *in_stack_000000b8;
  code *in_stack_000000c0;
  _Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *in_stack_000000d8;
  void *in_stack_00000160;
  undefined8 *in_stack_00000170;
  undefined8 *in_stack_00000178;
  undefined8 *in_stack_00000180;
  undefined8 *in_stack_00000188;
  undefined8 *in_stack_00000190;
  long in_stack_000001a8;
  
  operator_delete(unaff_RBX,0x50);
  puVar8 = in_stack_00000170;
  puVar11 = in_stack_00000180;
  puVar12 = in_stack_00000188;
  puVar13 = in_stack_00000178;
  puVar9 = in_stack_00000190;
  if (in_stack_000000d8 != (_Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *)0x0) {
    std::_Sp_counted_base<(__gnu_cxx::_Lock_policy)2>::_M_release(in_stack_000000d8);
    puVar8 = in_stack_00000170;
    puVar11 = in_stack_00000180;
    puVar12 = in_stack_00000188;
    puVar13 = in_stack_00000178;
    puVar9 = in_stack_00000190;
  }
  do {
    if (puVar9 == puVar8) {
      if (in_stack_00000160 != (void *)0x0) {
        puVar8 = (undefined8 *)(in_stack_000001a8 + 8);
        for (puVar9 = in_stack_00000188; puVar9 < puVar8; puVar9 = puVar9 + 1) {
          operator_delete((void *)*puVar9);
        }
        operator_delete(in_stack_00000160);
      }
      if (in_stack_000000a0 != '\0') {
        if (in_stack_000000b8 == (code *)0x0) {
                    /* WARNING: Subroutine does not return */
          std::__throw_bad_function_call();
        }
        (*in_stack_000000c0)(&stack0x000000a8);
      }
      if (in_stack_000000b8 != (code *)0x0) {
        (*in_stack_000000b8)(&stack0x000000a8,&stack0x000000a8,3);
      }
                    /* WARNING: Subroutine does not return */
      cxa_throw_exception();
    }
    pvVar4 = (void *)*puVar8;
    if (pvVar4 != (void *)0x0) {
      puVar5 = *(undefined8 **)((long)pvVar4 + 0x10);
      if (puVar5 != (undefined8 *)0x0) {
        if ((undefined1 *)*puVar5 != &DAT_011c5338) {
          refcount_release();
        }
        operator_delete(puVar5,8);
      }
      if (*(void **)((long)pvVar4 + 0x38) != (void *)0x0) {
        operator_delete(*(void **)((long)pvVar4 + 0x38));
      }
      plVar6 = *(long **)((long)pvVar4 + 0x28);
      if (plVar6 != (long *)0x0) {
        LOCK();
        plVar1 = plVar6 + 1;
        lVar7 = *plVar1;
        *(int *)plVar1 = (int)*plVar1 + -1;
        UNLOCK();
        if ((int)lVar7 == 1) {
          (**(code **)(*plVar6 + 0x10))(plVar6);
          LOCK();
          piVar2 = (int *)((long)plVar6 + 0xc);
          iVar3 = *piVar2;
          *piVar2 = *piVar2 + -1;
          UNLOCK();
          if (iVar3 == 1) {
            (**(code **)(*plVar6 + 0x18))(plVar6);
          }
        }
      }
      pQVar10 = *(QArrayData **)((long)pvVar4 + 8);
      if (*(int *)pQVar10 == 0) {
LAB_00511353:
        QArrayData::deallocate(pQVar10,1,8);
      }
      else if (*(int *)pQVar10 != -1) {
        LOCK();
        *(int *)pQVar10 = *(int *)pQVar10 + -1;
        UNLOCK();
        if (*(int *)pQVar10 == 0) {
          pQVar10 = *(QArrayData **)((long)pvVar4 + 8);
          goto LAB_00511353;
        }
      }
      operator_delete(pvVar4,0x50);
    }
    puVar8 = puVar8 + 1;
    if (puVar11 == puVar8) {
      puVar8 = (undefined8 *)puVar12[1];
      puVar11 = (undefined8 *)(((long)puVar11 - (long)puVar13) + (long)puVar8);
      puVar12 = puVar12 + 1;
      puVar13 = puVar8;
    }
  } while( true );
}


// ==== entry=005113bc name=FUN_005113bc size=66 ====

/* WARNING: Removing unreachable block (ram,0x0051158a) */
/* WARNING: Removing unreachable block (ram,0x00511598) */

void FUN_005113bc(void)

{
  long *plVar1;
  int *piVar2;
  int iVar3;
  void *pvVar4;
  undefined8 *puVar5;
  long *plVar6;
  long lVar7;
  undefined8 *puVar8;
  undefined8 *puVar9;
  QArrayData *pQVar10;
  undefined8 *puVar11;
  undefined8 *puVar12;
  undefined8 *puVar13;
  undefined8 in_stack_00000038;
  void *in_stack_00000048;
  char in_stack_000000a0;
  code *in_stack_000000b8;
  code *in_stack_000000c0;
  long in_stack_00000138;
  void *in_stack_00000158;
  void *in_stack_00000160;
  undefined8 *in_stack_00000170;
  undefined8 *in_stack_00000178;
  undefined8 *in_stack_00000180;
  undefined8 *in_stack_00000188;
  undefined8 *in_stack_00000190;
  long in_stack_000001a8;
  
  operator_delete(in_stack_00000048);
  if (in_stack_00000158 != (void *)0x0) {
    puVar8 = *(undefined8 **)((long)in_stack_00000158 + in_stack_00000138 * 8);
    while (puVar8 != (undefined8 *)0x0) {
      puVar9 = (undefined8 *)*puVar8;
      operator_delete(puVar8);
      puVar8 = puVar9;
    }
    operator_delete(in_stack_00000158);
  }
  qt_byte_array_unref(in_stack_00000038);
  puVar9 = in_stack_00000190;
  puVar8 = in_stack_00000170;
  puVar11 = in_stack_00000180;
  puVar12 = in_stack_00000188;
  puVar13 = in_stack_00000178;
  do {
    if (puVar9 == puVar8) {
      if (in_stack_00000160 != (void *)0x0) {
        puVar8 = (undefined8 *)(in_stack_000001a8 + 8);
        for (puVar9 = in_stack_00000188; puVar9 < puVar8; puVar9 = puVar9 + 1) {
          operator_delete((void *)*puVar9);
        }
        operator_delete(in_stack_00000160);
      }
      if (in_stack_000000a0 != '\0') {
        if (in_stack_000000b8 == (code *)0x0) {
                    /* WARNING: Subroutine does not return */
          std::__throw_bad_function_call();
        }
        (*in_stack_000000c0)(&stack0x000000a8);
      }
      if (in_stack_000000b8 != (code *)0x0) {
        (*in_stack_000000b8)(&stack0x000000a8,&stack0x000000a8,3);
      }
                    /* WARNING: Subroutine does not return */
      cxa_throw_exception();
    }
    pvVar4 = (void *)*puVar8;
    if (pvVar4 != (void *)0x0) {
      puVar5 = *(undefined8 **)((long)pvVar4 + 0x10);
      if (puVar5 != (undefined8 *)0x0) {
        if ((undefined1 *)*puVar5 != &DAT_011c5338) {
          refcount_release();
        }
        operator_delete(puVar5,8);
      }
      if (*(void **)((long)pvVar4 + 0x38) != (void *)0x0) {
        operator_delete(*(void **)((long)pvVar4 + 0x38));
      }
      plVar6 = *(long **)((long)pvVar4 + 0x28);
      if (plVar6 != (long *)0x0) {
        LOCK();
        plVar1 = plVar6 + 1;
        lVar7 = *plVar1;
        *(int *)plVar1 = (int)*plVar1 + -1;
        UNLOCK();
        if ((int)lVar7 == 1) {
          (**(code **)(*plVar6 + 0x10))(plVar6);
          LOCK();
          piVar2 = (int *)((long)plVar6 + 0xc);
          iVar3 = *piVar2;
          *piVar2 = *piVar2 + -1;
          UNLOCK();
          if (iVar3 == 1) {
            (**(code **)(*plVar6 + 0x18))(plVar6);
          }
        }
      }
      pQVar10 = *(QArrayData **)((long)pvVar4 + 8);
      if (*(int *)pQVar10 == 0) {
LAB_00511353:
        QArrayData::deallocate(pQVar10,1,8);
      }
      else if (*(int *)pQVar10 != -1) {
        LOCK();
        *(int *)pQVar10 = *(int *)pQVar10 + -1;
        UNLOCK();
        if (*(int *)pQVar10 == 0) {
          pQVar10 = *(QArrayData **)((long)pvVar4 + 8);
          goto LAB_00511353;
        }
      }
      operator_delete(pvVar4,0x50);
    }
    puVar8 = puVar8 + 1;
    if (puVar11 == puVar8) {
      puVar12 = puVar12 + 1;
      puVar8 = (undefined8 *)*puVar12;
      puVar11 = (undefined8 *)(((long)puVar11 - (long)puVar13) + (long)puVar8);
      puVar13 = puVar8;
    }
  } while( true );
}


// ==== entry=005113fe name=FUN_005113fe size=97 ====

/* WARNING: Removing unreachable block (ram,0x0051158a) */
/* WARNING: Removing unreachable block (ram,0x00511598) */

void FUN_005113fe(void)

{
  long *plVar1;
  int *piVar2;
  int iVar3;
  void *pvVar4;
  undefined8 *puVar5;
  long *plVar6;
  long lVar7;
  undefined8 *puVar8;
  undefined8 *puVar9;
  QArrayData *pQVar10;
  void *unaff_R12;
  undefined8 *puVar11;
  undefined8 *puVar12;
  undefined8 *puVar13;
  undefined8 in_stack_00000038;
  _Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *in_stack_00000098;
  char in_stack_000000a0;
  code *in_stack_000000b8;
  code *in_stack_000000c0;
  void *in_stack_00000160;
  undefined8 *in_stack_00000170;
  undefined8 *in_stack_00000178;
  undefined8 *in_stack_00000180;
  undefined8 *in_stack_00000188;
  undefined8 *in_stack_00000190;
  long in_stack_000001a8;
  
  operator_delete(unaff_R12,0x50);
  if (in_stack_00000098 != (_Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *)0x0) {
    std::_Sp_counted_base<(__gnu_cxx::_Lock_policy)2>::_M_release(in_stack_00000098);
  }
  qt_byte_array_unref(in_stack_00000038);
  puVar9 = in_stack_00000190;
  puVar8 = in_stack_00000170;
  puVar11 = in_stack_00000180;
  puVar12 = in_stack_00000188;
  puVar13 = in_stack_00000178;
  do {
    if (puVar9 == puVar8) {
      if (in_stack_00000160 != (void *)0x0) {
        puVar8 = (undefined8 *)(in_stack_000001a8 + 8);
        for (puVar9 = in_stack_00000188; puVar9 < puVar8; puVar9 = puVar9 + 1) {
          operator_delete((void *)*puVar9);
        }
        operator_delete(in_stack_00000160);
      }
      if (in_stack_000000a0 != '\0') {
        if (in_stack_000000b8 == (code *)0x0) {
                    /* WARNING: Subroutine does not return */
          std::__throw_bad_function_call();
        }
        (*in_stack_000000c0)(&stack0x000000a8);
      }
      if (in_stack_000000b8 != (code *)0x0) {
        (*in_stack_000000b8)(&stack0x000000a8,&stack0x000000a8,3);
      }
                    /* WARNING: Subroutine does not return */
      cxa_throw_exception();
    }
    pvVar4 = (void *)*puVar8;
    if (pvVar4 != (void *)0x0) {
      puVar5 = *(undefined8 **)((long)pvVar4 + 0x10);
      if (puVar5 != (undefined8 *)0x0) {
        if ((undefined1 *)*puVar5 != &DAT_011c5338) {
          refcount_release();
        }
        operator_delete(puVar5,8);
      }
      if (*(void **)((long)pvVar4 + 0x38) != (void *)0x0) {
        operator_delete(*(void **)((long)pvVar4 + 0x38));
      }
      plVar6 = *(long **)((long)pvVar4 + 0x28);
      if (plVar6 != (long *)0x0) {
        LOCK();
        plVar1 = plVar6 + 1;
        lVar7 = *plVar1;
        *(int *)plVar1 = (int)*plVar1 + -1;
        UNLOCK();
        if ((int)lVar7 == 1) {
          (**(code **)(*plVar6 + 0x10))(plVar6);
          LOCK();
          piVar2 = (int *)((long)plVar6 + 0xc);
          iVar3 = *piVar2;
          *piVar2 = *piVar2 + -1;
          UNLOCK();
          if (iVar3 == 1) {
            (**(code **)(*plVar6 + 0x18))(plVar6);
          }
        }
      }
      pQVar10 = *(QArrayData **)((long)pvVar4 + 8);
      if (*(int *)pQVar10 == 0) {
LAB_00511353:
        QArrayData::deallocate(pQVar10,1,8);
      }
      else if (*(int *)pQVar10 != -1) {
        LOCK();
        *(int *)pQVar10 = *(int *)pQVar10 + -1;
        UNLOCK();
        if (*(int *)pQVar10 == 0) {
          pQVar10 = *(QArrayData **)((long)pvVar4 + 8);
          goto LAB_00511353;
        }
      }
      operator_delete(pvVar4,0x50);
    }
    puVar8 = puVar8 + 1;
    if (puVar11 == puVar8) {
      puVar12 = puVar12 + 1;
      puVar8 = (undefined8 *)*puVar12;
      puVar11 = (undefined8 *)(((long)puVar11 - (long)puVar13) + (long)puVar8);
      puVar13 = puVar8;
    }
  } while( true );
}


// ==== entry=0051143b name=FUN_0051143b size=13 ====

void FUN_0051143b(void)

{
  __cxa_begin_catch();
                    /* WARNING: Subroutine does not return */
                    /* try { // try from 00511443 to 00511447 has its CatchHandler @ 00511455 */
  __cxa_rethrow();
}


// ==== entry=00511448 name=FUN_00511448 size=13 ====

void FUN_00511448(void)

{
  __cxa_begin_catch();
                    /* WARNING: Subroutine does not return */
                    /* try { // try from 00511450 to 00511454 has its CatchHandler @ 0051148f */
  __cxa_rethrow();
}


// ==== entry=005114d2 name=FUN_005114d2 size=88 ====

/* WARNING: Removing unreachable block (ram,0x0051158a) */
/* WARNING: Removing unreachable block (ram,0x00511598) */

void FUN_005114d2(void)

{
  long *plVar1;
  int *piVar2;
  int iVar3;
  void *pvVar4;
  undefined8 *puVar5;
  long *plVar6;
  long lVar7;
  undefined8 *puVar8;
  undefined8 *puVar9;
  QArrayData *pQVar10;
  undefined8 *puVar11;
  undefined8 *puVar12;
  undefined8 *puVar13;
  undefined8 in_stack_00000038;
  char in_stack_000000a0;
  code *in_stack_000000b8;
  code *in_stack_000000c0;
  long in_stack_00000138;
  void *in_stack_00000158;
  void *in_stack_00000160;
  undefined8 *in_stack_00000170;
  undefined8 *in_stack_00000178;
  undefined8 *in_stack_00000180;
  undefined8 *in_stack_00000188;
  undefined8 *in_stack_00000190;
  long in_stack_000001a8;
  
  qt_byte_array_unref();
  if (in_stack_00000158 != (void *)0x0) {
    puVar8 = *(undefined8 **)((long)in_stack_00000158 + in_stack_00000138 * 8);
    while (puVar8 != (undefined8 *)0x0) {
      puVar9 = (undefined8 *)*puVar8;
      operator_delete(puVar8);
      puVar8 = puVar9;
    }
    operator_delete(in_stack_00000158);
  }
  qt_byte_array_unref(in_stack_00000038);
  puVar9 = in_stack_00000190;
  puVar8 = in_stack_00000170;
  puVar11 = in_stack_00000180;
  puVar12 = in_stack_00000188;
  puVar13 = in_stack_00000178;
  do {
    if (puVar9 == puVar8) {
      if (in_stack_00000160 != (void *)0x0) {
        puVar8 = (undefined8 *)(in_stack_000001a8 + 8);
        for (puVar9 = in_stack_00000188; puVar9 < puVar8; puVar9 = puVar9 + 1) {
          operator_delete((void *)*puVar9);
        }
        operator_delete(in_stack_00000160);
      }
      if (in_stack_000000a0 != '\0') {
        if (in_stack_000000b8 == (code *)0x0) {
                    /* WARNING: Subroutine does not return */
          std::__throw_bad_function_call();
        }
        (*in_stack_000000c0)(&stack0x000000a8);
      }
      if (in_stack_000000b8 != (code *)0x0) {
        (*in_stack_000000b8)(&stack0x000000a8,&stack0x000000a8,3);
      }
                    /* WARNING: Subroutine does not return */
      cxa_throw_exception();
    }
    pvVar4 = (void *)*puVar8;
    if (pvVar4 != (void *)0x0) {
      puVar5 = *(undefined8 **)((long)pvVar4 + 0x10);
      if (puVar5 != (undefined8 *)0x0) {
        if ((undefined1 *)*puVar5 != &DAT_011c5338) {
          refcount_release();
        }
        operator_delete(puVar5,8);
      }
      if (*(void **)((long)pvVar4 + 0x38) != (void *)0x0) {
        operator_delete(*(void **)((long)pvVar4 + 0x38));
      }
      plVar6 = *(long **)((long)pvVar4 + 0x28);
      if (plVar6 != (long *)0x0) {
        LOCK();
        plVar1 = plVar6 + 1;
        lVar7 = *plVar1;
        *(int *)plVar1 = (int)*plVar1 + -1;
        UNLOCK();
        if ((int)lVar7 == 1) {
          (**(code **)(*plVar6 + 0x10))(plVar6);
          LOCK();
          piVar2 = (int *)((long)plVar6 + 0xc);
          iVar3 = *piVar2;
          *piVar2 = *piVar2 + -1;
          UNLOCK();
          if (iVar3 == 1) {
            (**(code **)(*plVar6 + 0x18))(plVar6);
          }
        }
      }
      pQVar10 = *(QArrayData **)((long)pvVar4 + 8);
      if (*(int *)pQVar10 == 0) {
LAB_00511353:
        QArrayData::deallocate(pQVar10,1,8);
      }
      else if (*(int *)pQVar10 != -1) {
        LOCK();
        *(int *)pQVar10 = *(int *)pQVar10 + -1;
        UNLOCK();
        if (*(int *)pQVar10 == 0) {
          pQVar10 = *(QArrayData **)((long)pvVar4 + 8);
          goto LAB_00511353;
        }
      }
      operator_delete(pvVar4,0x50);
    }
    puVar8 = puVar8 + 1;
    if (puVar11 == puVar8) {
      puVar12 = puVar12 + 1;
      puVar8 = (undefined8 *)*puVar12;
      puVar11 = (undefined8 *)(((long)puVar11 - (long)puVar13) + (long)puVar8);
      puVar13 = puVar8;
    }
  } while( true );
}


// ==== entry=00511519 name=FUN_00511519 size=124 ====

/* WARNING: Removing unreachable block (ram,0x0051158a) */
/* WARNING: Removing unreachable block (ram,0x00511598) */

void FUN_00511519(void)

{
  long *plVar1;
  int *piVar2;
  int iVar3;
  void *pvVar4;
  undefined8 *puVar5;
  long *plVar6;
  long lVar7;
  undefined8 *puVar8;
  undefined8 *puVar9;
  QArrayData *pQVar10;
  undefined8 *puVar11;
  undefined8 *puVar12;
  undefined8 *puVar13;
  char in_stack_000000a0;
  code *in_stack_000000b8;
  code *in_stack_000000c0;
  long in_stack_00000130;
  void *in_stack_00000160;
  undefined8 *in_stack_00000170;
  undefined8 *in_stack_00000178;
  undefined8 *in_stack_00000180;
  undefined8 *in_stack_00000188;
  undefined8 *in_stack_00000190;
  long in_stack_000001a8;
  
  puVar8 = in_stack_00000170;
  puVar11 = in_stack_00000180;
  puVar12 = in_stack_00000188;
  puVar13 = in_stack_00000178;
  puVar9 = in_stack_00000190;
  if (in_stack_00000130 != 0) {
    FUN_00a04f38();
    puVar8 = in_stack_00000170;
    puVar11 = in_stack_00000180;
    puVar12 = in_stack_00000188;
    puVar13 = in_stack_00000178;
    puVar9 = in_stack_00000190;
  }
  do {
    if (puVar9 == puVar8) {
      if (in_stack_00000160 != (void *)0x0) {
        puVar8 = (undefined8 *)(in_stack_000001a8 + 8);
        for (puVar9 = in_stack_00000188; puVar9 < puVar8; puVar9 = puVar9 + 1) {
          operator_delete((void *)*puVar9);
        }
        operator_delete(in_stack_00000160);
      }
      if (in_stack_000000a0 != '\0') {
        if (in_stack_000000b8 == (code *)0x0) {
                    /* WARNING: Subroutine does not return */
          std::__throw_bad_function_call();
        }
        (*in_stack_000000c0)(&stack0x000000a8);
      }
      if (in_stack_000000b8 != (code *)0x0) {
        (*in_stack_000000b8)(&stack0x000000a8,&stack0x000000a8,3);
      }
                    /* WARNING: Subroutine does not return */
      cxa_throw_exception();
    }
    pvVar4 = (void *)*puVar8;
    if (pvVar4 != (void *)0x0) {
      puVar5 = *(undefined8 **)((long)pvVar4 + 0x10);
      if (puVar5 != (undefined8 *)0x0) {
        if ((undefined1 *)*puVar5 != &DAT_011c5338) {
          refcount_release();
        }
        operator_delete(puVar5,8);
      }
      if (*(void **)((long)pvVar4 + 0x38) != (void *)0x0) {
        operator_delete(*(void **)((long)pvVar4 + 0x38));
      }
      plVar6 = *(long **)((long)pvVar4 + 0x28);
      if (plVar6 != (long *)0x0) {
        LOCK();
        plVar1 = plVar6 + 1;
        lVar7 = *plVar1;
        *(int *)plVar1 = (int)*plVar1 + -1;
        UNLOCK();
        if ((int)lVar7 == 1) {
          (**(code **)(*plVar6 + 0x10))(plVar6);
          LOCK();
          piVar2 = (int *)((long)plVar6 + 0xc);
          iVar3 = *piVar2;
          *piVar2 = *piVar2 + -1;
          UNLOCK();
          if (iVar3 == 1) {
            (**(code **)(*plVar6 + 0x18))(plVar6);
          }
        }
      }
      pQVar10 = *(QArrayData **)((long)pvVar4 + 8);
      if (*(int *)pQVar10 == 0) {
LAB_00511353:
        QArrayData::deallocate(pQVar10,1,8);
      }
      else if (*(int *)pQVar10 != -1) {
        LOCK();
        *(int *)pQVar10 = *(int *)pQVar10 + -1;
        UNLOCK();
        if (*(int *)pQVar10 == 0) {
          pQVar10 = *(QArrayData **)((long)pvVar4 + 8);
          goto LAB_00511353;
        }
      }
      operator_delete(pvVar4,0x50);
    }
    puVar8 = puVar8 + 1;
    if (puVar11 == puVar8) {
      puVar8 = (undefined8 *)puVar12[1];
      puVar11 = (undefined8 *)(((long)puVar11 - (long)puVar13) + (long)puVar8);
      puVar12 = puVar12 + 1;
      puVar13 = puVar8;
    }
  } while( true );
}


// ==== entry=005115a6 name=FUN_005115a6 size=89 ====

void FUN_005115a6(void)

{
  char cVar1;
  long unaff_RBX;
  void *unaff_R12;
  void *unaff_R13;
  void *unaff_R14;
  
  operator_delete(unaff_R14,0x60);
  operator_delete(unaff_R12,0x20);
  operator_delete(unaff_R13,0x10);
  cVar1 = qatomic_int_deref(*(long *)(unaff_RBX + 0x58) + 0x10);
  if (cVar1 == '\0') {
    QHashData::free_helper(*(_func_void_Node_ptr **)(unaff_RBX + 0x58));
  }
  qt_array_data_unref(unaff_RBX + 0x10);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=005115ff name=FUN_005115ff size=18 ====

void FUN_005115ff(void)

{
  char cVar1;
  long unaff_RBX;
  void *unaff_RBP;
  void *unaff_R12;
  void *unaff_R13;
  
  operator_delete(unaff_RBP,0x30);
  operator_delete(unaff_R12,0x20);
  operator_delete(unaff_R13,0x10);
  cVar1 = qatomic_int_deref(*(long *)(unaff_RBX + 0x58) + 0x10);
  if (cVar1 == '\0') {
    QHashData::free_helper(*(_func_void_Node_ptr **)(unaff_RBX + 0x58));
  }
  qt_array_data_unref(unaff_RBX + 0x10);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00511611 name=FUN_00511611 size=18 ====

void FUN_00511611(void)

{
  char cVar1;
  long unaff_RBX;
  void *unaff_RBP;
  void *unaff_R13;
  
  operator_delete(unaff_RBP,0x40);
  operator_delete(unaff_R13,0x10);
  cVar1 = qatomic_int_deref(*(long *)(unaff_RBX + 0x58) + 0x10);
  if (cVar1 == '\0') {
    QHashData::free_helper(*(_func_void_Node_ptr **)(unaff_RBX + 0x58));
  }
  qt_array_data_unref(unaff_RBX + 0x10);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00511623 name=FUN_00511623 size=21 ====

void FUN_00511623(void)

{
  char cVar1;
  long unaff_RBX;
  void *unaff_RBP;
  void *unaff_R12;
  void *unaff_R13;
  
  operator_delete(unaff_RBP,0x30);
  operator_delete(unaff_R12,0x20);
  operator_delete(unaff_R13,0x10);
  cVar1 = qatomic_int_deref(*(long *)(unaff_RBX + 0x58) + 0x10);
  if (cVar1 == '\0') {
    QHashData::free_helper(*(_func_void_Node_ptr **)(unaff_RBX + 0x58));
  }
  qt_array_data_unref(unaff_RBX + 0x10);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00511638 name=FUN_00511638 size=18 ====

void FUN_00511638(void)

{
  char cVar1;
  long unaff_RBX;
  void *unaff_R12;
  void *unaff_R13;
  void *unaff_R14;
  
  operator_delete(unaff_R14,0x50);
  operator_delete(unaff_R12,0x20);
  operator_delete(unaff_R13,0x10);
  cVar1 = qatomic_int_deref(*(long *)(unaff_RBX + 0x58) + 0x10);
  if (cVar1 == '\0') {
    QHashData::free_helper(*(_func_void_Node_ptr **)(unaff_RBX + 0x58));
  }
  qt_array_data_unref(unaff_RBX + 0x10);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0051164a name=FUN_0051164a size=22 ====

void FUN_0051164a(void)

{
  long unaff_R14;
  
  if (unaff_R14 != 0) {
    qslotobject_release_destroy(unaff_R14 + 8);
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00511660 name=FUN_00511660 size=21 ====

void FUN_00511660(void)

{
  FUN_0081f982(&stack0x00000090);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00511675 name=FUN_00511675 size=22 ====

void FUN_00511675(void)

{
  long unaff_R14;
  
  if (unaff_R14 != 0) {
    qslotobject_release_destroy(unaff_R14 + 8);
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0051168c name=FUN_0051168c size=149 ====

void FUN_0051168c(void)

{
  void *pvVar1;
  undefined8 *unaff_RBX;
  void *unaff_RBP;
  
  operator_delete(unaff_RBP,0x38);
  pvVar1 = (void *)unaff_RBX[0xd];
  if (pvVar1 != (void *)0x0) {
    FUN_00a1492a(pvVar1);
    operator_delete(pvVar1,0x18);
  }
  pvVar1 = (void *)unaff_RBX[0xc];
  if (pvVar1 != (void *)0x0) {
    FUN_00a1492a(pvVar1);
    operator_delete(pvVar1,0x18);
  }
  if ((void *)unaff_RBX[9] != (void *)0x0) {
    operator_delete((void *)unaff_RBX[9]);
  }
  if ((void *)unaff_RBX[6] != (void *)0x0) {
    operator_delete((void *)unaff_RBX[6]);
  }
  if ((void *)unaff_RBX[3] != (void *)0x0) {
    operator_delete((void *)unaff_RBX[3]);
  }
  *unaff_RBX = &PTR_FUN_011ae040;
  FUN_0098fdbc(unaff_RBX + 1);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00511722 name=FUN_00511722 size=12 ====

void FUN_00511722(void)

{
  long unaff_RBP;
  
  *(undefined1 *)(unaff_RBP + 0xc) = 0;
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0051172e name=FUN_0051172e size=12 ====

void FUN_0051172e(void)

{
  long unaff_RBP;
  
  *(undefined1 *)(unaff_RBP + 0xc) = 0;
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0051173a name=FUN_0051173a size=77 ====

void FUN_0051173a(void)

{
  undefined8 *unaff_RBX;
  
  if (unaff_RBX[10] != 0) {
    FUN_00a0d450(unaff_RBX + 10);
  }
  if ((void *)unaff_RBX[6] != (void *)0x0) {
    operator_delete((void *)unaff_RBX[6]);
  }
  if ((void *)unaff_RBX[3] != (void *)0x0) {
    operator_delete((void *)unaff_RBX[3]);
  }
  *unaff_RBX = &PTR_FUN_011ae040;
  FUN_0098fdbc(unaff_RBX + 1);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00511788 name=FUN_00511788 size=12 ====

void FUN_00511788(void)

{
  long unaff_RBP;
  
  *(undefined1 *)(unaff_RBP + 0xc) = 0;
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00511794 name=FUN_00511794 size=159 ====

void FUN_00511794(void)

{
  void *pvVar1;
  undefined8 *unaff_RBX;
  void *unaff_RBP;
  
  operator_delete(unaff_RBP,0x30);
  FUN_0098fdbc(unaff_RBX + 0xe);
  if ((long *)unaff_RBX[0xc] != (long *)0x0) {
    (**(code **)(*(long *)unaff_RBX[0xc] + 8))();
  }
  pvVar1 = (void *)unaff_RBX[0xb];
  if (pvVar1 != (void *)0x0) {
    FUN_00a1492a(pvVar1);
    operator_delete(pvVar1,0x18);
  }
  pvVar1 = (void *)unaff_RBX[10];
  if (pvVar1 != (void *)0x0) {
    FUN_00a1492a(pvVar1);
    operator_delete(pvVar1,0x18);
  }
  if ((void *)unaff_RBX[7] != (void *)0x0) {
    operator_delete((void *)unaff_RBX[7]);
  }
  if ((void *)unaff_RBX[4] != (void *)0x0) {
    operator_delete((void *)unaff_RBX[4]);
  }
  *unaff_RBX = &PTR_FUN_011ae040;
  FUN_0098fdbc(unaff_RBX + 1);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00511833 name=FUN_00511833 size=21 ====

void FUN_00511833(void)

{
  void *pvVar1;
  undefined8 *unaff_RBX;
  void *unaff_RBP;
  
  operator_delete(unaff_RBP,0x38);
  if ((long *)unaff_RBX[0xc] != (long *)0x0) {
    (**(code **)(*(long *)unaff_RBX[0xc] + 8))();
  }
  pvVar1 = (void *)unaff_RBX[0xb];
  if (pvVar1 != (void *)0x0) {
    FUN_00a1492a(pvVar1);
    operator_delete(pvVar1,0x18);
  }
  pvVar1 = (void *)unaff_RBX[10];
  if (pvVar1 != (void *)0x0) {
    FUN_00a1492a(pvVar1);
    operator_delete(pvVar1,0x18);
  }
  if ((void *)unaff_RBX[7] != (void *)0x0) {
    operator_delete((void *)unaff_RBX[7]);
  }
  if ((void *)unaff_RBX[4] != (void *)0x0) {
    operator_delete((void *)unaff_RBX[4]);
  }
  *unaff_RBX = &PTR_FUN_011ae040;
  FUN_0098fdbc(unaff_RBX + 1);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00511848 name=FUN_00511848 size=73 ====

/* WARNING: Removing unreachable block (ram,0x00511886) */

void FUN_00511848(void)

{
  void *pvVar1;
  int *piVar2;
  int iVar3;
  long unaff_RBX;
  void *unaff_R12;
  
  if (*(void **)(unaff_RBX + 0x10) != (void *)0x0) {
    operator_delete(*(void **)(unaff_RBX + 0x10));
  }
  pvVar1 = (void *)(*(long *)(unaff_RBX + 8) + -0x18);
  if (pvVar1 != unaff_R12) {
    LOCK();
    piVar2 = (int *)(*(long *)(unaff_RBX + 8) + -8);
    iVar3 = *piVar2;
    *piVar2 = *piVar2 + -1;
    UNLOCK();
    if (iVar3 < 1) {
      operator_delete(pvVar1);
    }
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=005118a0 name=FUN_005118a0 size=39 ====

/* WARNING: Removing unreachable block (ram,0x005118b4) */

void FUN_005118a0(void *param_1)

{
  int *piVar1;
  int iVar2;
  
  LOCK();
  piVar1 = (int *)((long)param_1 + 0x10);
  iVar2 = *piVar1;
  *piVar1 = *piVar1 + -1;
  UNLOCK();
  if (0 < iVar2) {
    return;
  }
  operator_delete(param_1);
  return;
}


// ==== entry=005118c8 name=FUN_005118c8 size=12 ====

void FUN_005118c8(void)

{
  long unaff_RBP;
  
  *(undefined1 *)(unaff_RBP + 0xc) = 0;
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=005118d4 name=FUN_005118d4 size=16 ====

void FUN_005118d4(void)

{
  qt_byte_array_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=005118e4 name=FUN_005118e4 size=16 ====

void FUN_005118e4(void)

{
  qt_byte_array_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=005118f4 name=FUN_005118f4 size=51 ====

void FUN_005118f4(void)

{
  locale *unaff_R14;
  locale *in_stack_00000030;
  undefined8 in_stack_00000038;
  long in_stack_00000048;
  
  std::locale::~locale(unaff_R14);
  std::locale::~locale(in_stack_00000030);
  qt_byte_array_unref(in_stack_00000038);
  *(undefined1 *)(in_stack_00000048 + 0x80) = 0;
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00511927 name=FUN_00511927 size=20 ====

void FUN_00511927(void)

{
  locale *unaff_R12;
  locale *in_stack_00000030;
  undefined8 in_stack_00000038;
  long in_stack_00000048;
  
  std::locale::~locale(unaff_R12);
  std::locale::~locale(in_stack_00000030);
  qt_byte_array_unref(in_stack_00000038);
  *(undefined1 *)(in_stack_00000048 + 0x80) = 0;
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0051193b name=FUN_0051193b size=20 ====

void FUN_0051193b(void)

{
  locale *unaff_R12;
  locale *in_stack_00000018;
  undefined8 in_stack_00000038;
  long in_stack_00000048;
  
  std::locale::~locale(unaff_R12);
  std::locale::~locale(in_stack_00000018);
  qt_byte_array_unref(in_stack_00000038);
  *(undefined1 *)(in_stack_00000048 + 0x80) = 0;
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0051194f name=FUN_0051194f size=20 ====

void FUN_0051194f(void)

{
  locale *unaff_R12;
  locale *in_stack_00000020;
  undefined8 in_stack_00000038;
  long in_stack_00000048;
  
  std::locale::~locale(unaff_R12);
  std::locale::~locale(in_stack_00000020);
  qt_byte_array_unref(in_stack_00000038);
  *(undefined1 *)(in_stack_00000048 + 0x80) = 0;
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00511964 name=FUN_00511964 size=209 ====

/* WARNING: Removing unreachable block (ram,0x00511a2a) */

void FUN_00511964(void)

{
  void *pvVar1;
  int *piVar2;
  int iVar3;
  undefined8 *puVar4;
  long *unaff_RBX;
  undefined8 *puVar5;
  QArrayData *pQVar6;
  void *unaff_R14;
  
  qt_byte_array_unref();
  if (unaff_RBX[0xf] != 0) {
    FUN_00a0d450(unaff_RBX + 0xf);
  }
  if ((void *)unaff_RBX[0xc] != (void *)0x0) {
    operator_delete((void *)unaff_RBX[0xc]);
  }
  if (unaff_RBX[10] != 0) {
    puVar5 = *(undefined8 **)(unaff_RBX[10] + unaff_RBX[6] * 8);
    while (puVar5 != (undefined8 *)0x0) {
      puVar4 = (undefined8 *)*puVar5;
      pvVar1 = (void *)(puVar5[2] + -0x18);
      if (pvVar1 != unaff_R14) {
        LOCK();
        piVar2 = (int *)(puVar5[2] + -8);
        iVar3 = *piVar2;
        *piVar2 = *piVar2 + -1;
        UNLOCK();
        if (iVar3 < 1) {
          operator_delete(pvVar1);
        }
      }
      operator_delete(puVar5);
      puVar5 = puVar4;
    }
    operator_delete((void *)unaff_RBX[10]);
  }
  pQVar6 = (QArrayData *)unaff_RBX[4];
  if (*(int *)pQVar6 != 0) {
    if (*(int *)pQVar6 == -1) goto LAB_005119c4;
    LOCK();
    *(int *)pQVar6 = *(int *)pQVar6 + -1;
    UNLOCK();
    if (*(int *)pQVar6 != 0) goto LAB_005119c4;
    pQVar6 = (QArrayData *)unaff_RBX[4];
  }
  QArrayData::deallocate(pQVar6,2,8);
LAB_005119c4:
  if ((void *)(*unaff_RBX + -0x18) != unaff_R14) {
    FUN_005118a0();
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00511a36 name=FUN_00511a36 size=38 ====

void FUN_00511a36(void)

{
  undefined8 *unaff_R12;
  
  qt_byte_array_unref();
  if ((undefined1 *)*unaff_R12 != &DAT_011c5338) {
    FUN_005118a0();
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00511a5c name=FUN_00511a5c size=16 ====

void FUN_00511a5c(void)

{
  void *unaff_RBP;
  
  operator_delete(unaff_RBP);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00511a6c name=FUN_00511a6c size=16 ====

void FUN_00511a6c(void)

{
  FUN_00a0fe1c();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00511a7c name=FUN_00511a7c size=67 ====

void FUN_00511a7c(void)

{
  void *pvVar1;
  undefined8 *unaff_RBX;
  void *unaff_RBP;
  
  operator_delete(unaff_RBP,0x38);
  pvVar1 = (void *)unaff_RBX[3];
  if (pvVar1 != (void *)0x0) {
    FUN_00a1492a(pvVar1);
    operator_delete(pvVar1,0x18);
  }
  if ((void *)*unaff_RBX != (void *)0x0) {
    operator_delete((void *)*unaff_RBX);
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00511ac0 name=FUN_00511ac0 size=12 ====

void FUN_00511ac0(void)

{
  long unaff_RBP;
  
  *(undefined1 *)(unaff_RBP + 0xc) = 0;
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00511acc name=FUN_00511acc size=12 ====

void FUN_00511acc(void)

{
  long unaff_RBP;
  
  *(undefined1 *)(unaff_RBP + 0xc) = 0;
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00511ad8 name=FUN_00511ad8 size=77 ====

void FUN_00511ad8(void)

{
  undefined8 *unaff_RBX;
  
  if (unaff_RBX[10] != 0) {
    FUN_00a0d450(unaff_RBX + 10);
  }
  if ((void *)unaff_RBX[6] != (void *)0x0) {
    operator_delete((void *)unaff_RBX[6]);
  }
  if ((void *)unaff_RBX[3] != (void *)0x0) {
    operator_delete((void *)unaff_RBX[3]);
  }
  *unaff_RBX = &PTR_FUN_011ae040;
  FUN_0098fdbc(unaff_RBX + 1);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00511b26 name=FUN_00511b26 size=22 ====

void FUN_00511b26(void)

{
  long unaff_RBX;
  
  if (*(void **)(unaff_RBX + 8) != (void *)0x0) {
    operator_delete(*(void **)(unaff_RBX + 8));
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00511b3c name=FUN_00511b3c size=12 ====

void FUN_00511b3c(void)

{
  long unaff_RBP;
  
  *(undefined1 *)(unaff_RBP + 0xc) = 0;
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00511b48 name=FUN_00511b48 size=45 ====

void FUN_00511b48(void)

{
  undefined8 *unaff_RBX;
  
  if ((void *)unaff_RBX[3] != (void *)0x0) {
    operator_delete((void *)unaff_RBX[3]);
  }
  *unaff_RBX = &PTR_FUN_011ae040;
  FUN_0098fdbc(unaff_RBX + 1);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


