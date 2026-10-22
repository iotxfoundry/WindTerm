// Ghidra 12.1.4 decompiled — WindTerm 2.7.0 (sha256 9491b87e…) part 15
// ==== entry=00511b80 name=FUN_00511b80 size=50 ====

void FUN_00511b80(void)

{
  int *piVar1;
  undefined8 *unaff_RBX;
  
  piVar1 = (int *)*unaff_RBX;
  if (*piVar1 != 0) {
    if (*piVar1 == -1) goto LAB_00511b9b;
    LOCK();
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if (*piVar1 != 0) goto LAB_00511b9b;
  }
  QArrayData::deallocate((QArrayData *)*unaff_RBX,1,8);
LAB_00511b9b:
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00511bb2 name=FUN_00511bb2 size=36 ====

void FUN_00511bb2(void)

{
  long unaff_RBX;
  
  if (*(long *)(unaff_RBX + 0x20) != 0) {
    FUN_00a11700();
  }
  if (*(void **)(unaff_RBX + 8) != (void *)0x0) {
    operator_delete(*(void **)(unaff_RBX + 8));
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00511bd6 name=FUN_00511bd6 size=63 ====

void FUN_00511bd6(void)

{
  void *unaff_R12;
  long unaff_R15;
  
  operator_delete(unaff_R12,0x10);
  if (*(long *)(unaff_R15 + 0x28) != 0) {
    FUN_00a11700();
  }
  if (*(long *)(unaff_R15 + 0x20) != 0) {
    FUN_00a11700();
  }
  if (*(void **)(unaff_R15 + 8) != (void *)0x0) {
    operator_delete(*(void **)(unaff_R15 + 8));
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00511c16 name=FUN_00511c16 size=32 ====

void FUN_00511c16(void)

{
  long unaff_RBP;
  void *unaff_R13;
  undefined8 in_stack_00000028;
  
  operator_delete(unaff_R13,0x10);
  if (in_stack_00000028._7_1_ != '\0') {
    *(undefined1 *)(unaff_RBP + 0x31) = 0;
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00511c36 name=FUN_00511c36 size=58 ====

/* WARNING: Removing unreachable block (ram,0x00511c65) */

void FUN_00511c36(void)

{
  int *piVar1;
  int iVar2;
  long unaff_RBP;
  undefined8 in_stack_00000028;
  long in_stack_00000050;
  
  if ((undefined8 *)(in_stack_00000050 + -0x18) != &std::string::_Rep::_S_empty_rep_storage) {
    LOCK();
    piVar1 = (int *)(in_stack_00000050 + -8);
    iVar2 = *piVar1;
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if (iVar2 < 1) {
      operator_delete((undefined8 *)(in_stack_00000050 + -0x18));
    }
  }
  if (in_stack_00000028._7_1_ != '\0') {
    *(undefined1 *)(unaff_RBP + 0x31) = 0;
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00511c70 name=FUN_00511c70 size=21 ====

void FUN_00511c70(void)

{
  void *unaff_RBX;
  
  operator_delete(unaff_RBX,0x38);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00511c86 name=FUN_00511c86 size=30 ====

void FUN_00511c86(void)

{
  void *unaff_RBX;
  long unaff_R12;
  
  operator_delete(unaff_RBX,0x38);
  *(undefined1 *)(unaff_R12 + 0x10) = 0;
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00511ca4 name=FUN_00511ca4 size=14 ====

void FUN_00511ca4(void)

{
  long unaff_R12;
  
  *(undefined1 *)(unaff_R12 + 0x10) = 0;
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00511cc0 name=FUN_00511cc0 size=39 ====

/* WARNING: Removing unreachable block (ram,0x00511cd4) */

void FUN_00511cc0(void *param_1)

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


// ==== entry=00511ce8 name=FUN_00511ce8 size=13 ====

void FUN_00511ce8(void)

{
  long unaff_RBX;
  
  *(undefined1 *)(unaff_RBX + 4) = 0;
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00511cf6 name=FUN_00511cf6 size=125 ====

/* WARNING: Removing unreachable block (ram,0x00511d68) */

void FUN_00511cf6(void)

{
  undefined8 *puVar1;
  int *piVar2;
  int iVar3;
  undefined8 *puVar4;
  long unaff_RBX;
  undefined8 *puVar5;
  
  if (*(long *)(unaff_RBX + 0x48) != 0) {
    puVar5 = *(undefined8 **)(*(long *)(unaff_RBX + 0x48) + *(long *)(unaff_RBX + 0x28) * 8);
    while (puVar5 != (undefined8 *)0x0) {
      puVar4 = (undefined8 *)*puVar5;
      puVar1 = (undefined8 *)(puVar5[2] + -0x18);
      if (puVar1 != &std::string::_Rep::_S_empty_rep_storage) {
        LOCK();
        piVar2 = (int *)(puVar5[2] + -8);
        iVar3 = *piVar2;
        *piVar2 = *piVar2 + -1;
        UNLOCK();
        if (iVar3 < 1) {
          operator_delete(puVar1);
        }
      }
      operator_delete(puVar5);
      puVar5 = puVar4;
    }
    operator_delete(*(void **)(unaff_RBX + 0x48));
  }
  if (*(void **)(unaff_RBX + 8) != (void *)0x0) {
    operator_delete(*(void **)(unaff_RBX + 8));
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00511d74 name=FUN_00511d74 size=41 ====

void FUN_00511d74(void)

{
  if (DAT_011c2830 == -1) {
    DAT_011c2830 = -2;
  }
  __cxa_guard_abort(&DAT_011c27c8);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00511d9e name=FUN_00511d9e size=33 ====

void FUN_00511d9e(void)

{
  long unaff_R15;
  long unaff_retaddr;
  
  FUN_00a0fe1c(&stack0x00000050);
  if (unaff_retaddr != unaff_R15) {
    FUN_00511cc0(unaff_retaddr);
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00511dbf name=FUN_00511dbf size=27 ====

void FUN_00511dbf(void)

{
  long unaff_R15;
  long in_stack_00000050;
  
  if (in_stack_00000050 + -0x18 != unaff_R15) {
    FUN_00511cc0();
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00511dda name=FUN_00511dda size=10 ====

void FUN_00511dda(void)

{
  void *unaff_R12;
  long unaff_R15;
  long unaff_retaddr;
  
  operator_delete(unaff_R12);
  if (unaff_retaddr != unaff_R15) {
    FUN_00511cc0(unaff_retaddr);
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00511de4 name=FUN_00511de4 size=33 ====

void FUN_00511de4(void)

{
  void *unaff_RBP;
  long unaff_R15;
  long unaff_retaddr;
  
  if (*(long *)((long)unaff_RBP + 8) + -0x18 != unaff_R15) {
    FUN_00511cc0();
  }
  operator_delete(unaff_RBP,0x38);
  if (unaff_retaddr != unaff_R15) {
    FUN_00511cc0(unaff_retaddr);
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00511e05 name=FUN_00511e05 size=27 ====

void FUN_00511e05(void)

{
  long unaff_R15;
  long in_stack_00000050;
  
  if (in_stack_00000050 + -0x18 != unaff_R15) {
    FUN_00511cc0();
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00511e20 name=FUN_00511e20 size=60 ====

/* WARNING: Removing unreachable block (ram,0x00511e51) */

void FUN_00511e20(void)

{
  int *piVar1;
  int iVar2;
  void *unaff_RBX;
  long in_stack_00000008;
  
  if ((void *)(in_stack_00000008 + -0x18) != unaff_RBX) {
    LOCK();
    piVar1 = (int *)(in_stack_00000008 + -8);
    iVar2 = *piVar1;
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if (iVar2 < 1) {
      operator_delete((void *)(in_stack_00000008 + -0x18));
    }
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00511e5c name=FUN_00511e5c size=33 ====

void FUN_00511e5c(void)

{
  code *in_stack_00000030;
  
  if (in_stack_00000030 != (code *)0x0) {
    (*in_stack_00000030)(&stack0x00000020,&stack0x00000020,3);
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00511e7d name=FUN_00511e7d size=39 ====

void FUN_00511e7d(void)

{
  code *in_stack_00000030;
  
  qt_byte_array_unref();
  if (in_stack_00000030 != (code *)0x0) {
    (*in_stack_00000030)();
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00511ea4 name=FUN_00511ea4 size=24 ====

void FUN_00511ea4(void)

{
  undefined1 *unaff_R12;
  
  qt_byte_array_unref();
  *unaff_R12 = 0;
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00511ebc name=FUN_00511ebc size=42 ====

void FUN_00511ebc(void)

{
  undefined8 in_stack_00000010;
  
  qt_byte_array_unref(in_stack_00000010);
  qt_byte_array_unref();
  qt_byte_array_unref();
  qt_byte_array_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00511ee6 name=FUN_00511ee6 size=25 ====

void FUN_00511ee6(void)

{
  undefined8 in_stack_00000010;
  
  qt_byte_array_unref();
  qt_byte_array_unref(in_stack_00000010);
  qt_byte_array_unref(&stack0x00000030);
  qt_byte_array_unref();
  qt_byte_array_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00511eff name=FUN_00511eff size=13 ====

void FUN_00511eff(void)

{
  qt_byte_array_unref();
  qt_byte_array_unref();
  qt_byte_array_unref();
  qt_byte_array_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00511f0c name=FUN_00511f0c size=23 ====

void FUN_00511f0c(void)

{
  qt_byte_array_unref();
  qt_byte_array_unref(&stack0x00000030);
  qt_byte_array_unref(&stack0x00000028);
  qt_byte_array_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00511f23 name=FUN_00511f23 size=17 ====

void FUN_00511f23(void)

{
  qt_byte_array_unref(&stack0x00000038);
  qt_byte_array_unref(&stack0x00000030);
  qt_byte_array_unref();
  qt_byte_array_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00511f34 name=FUN_00511f34 size=15 ====

void FUN_00511f34(void)

{
  qt_byte_array_unref();
  qt_byte_array_unref(&stack0x00000030);
  qt_byte_array_unref();
  qt_byte_array_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00511f44 name=FUN_00511f44 size=20 ====

void FUN_00511f44(void)

{
  __cxa_guard_abort(&DAT_011c2840);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00511f58 name=FUN_00511f58 size=15 ====

void FUN_00511f58(void)

{
  DAT_011c2888 = 0;
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00511f68 name=FUN_00511f68 size=18 ====

void FUN_00511f68(void)

{
  undefined8 in_stack_00000070;
  
  qt_byte_array_unref(in_stack_00000070);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00511f7a name=FUN_00511f7a size=18 ====

void FUN_00511f7a(void)

{
  undefined8 in_stack_00000040;
  
  qt_byte_array_unref(in_stack_00000040);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00511f8c name=FUN_00511f8c size=67 ====

void FUN_00511f8c(void)

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


// ==== entry=00511fd0 name=FUN_00511fd0 size=21 ====

void FUN_00511fd0(void)

{
  void *unaff_RBP;
  
  operator_delete(unaff_RBP,0x50);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00511fe6 name=FUN_00511fe6 size=16 ====

void FUN_00511fe6(void)

{
  FUN_0096bd50();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00511ff6 name=FUN_00511ff6 size=16 ====

void FUN_00511ff6(void)

{
  FUN_0096bb02();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00512006 name=FUN_00512006 size=16 ====

void FUN_00512006(void)

{
  FUN_0096bb02();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00512016 name=FUN_00512016 size=16 ====

void FUN_00512016(void)

{
  FUN_0096bb02();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00512026 name=FUN_00512026 size=24 ====

void FUN_00512026(void)

{
  FUN_0096bb02();
  FUN_0096bb02();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0051203e name=FUN_0051203e size=16 ====

void FUN_0051203e(void)

{
  qt_array_data_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0051204e name=FUN_0051204e size=16 ====

void FUN_0051204e(void)

{
  qt_array_data_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0051205e name=FUN_0051205e size=16 ====

void FUN_0051205e(void)

{
  qt_array_data_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0051206e name=FUN_0051206e size=16 ====

void FUN_0051206e(void)

{
  qt_array_data_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0051207e name=FUN_0051207e size=16 ====

void FUN_0051207e(void)

{
  qt_array_data_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0051208e name=FUN_0051208e size=16 ====

void FUN_0051208e(void)

{
  qt_array_data_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0051209e name=FUN_0051209e size=34 ====

void FUN_0051209e(void)

{
  QEvent *unaff_RBX;
  
  qt_byte_array_unref(unaff_RBX + 0x28);
  qt_byte_array_unref(unaff_RBX + 0x20);
  QEvent::~QEvent(unaff_RBX);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=005120c0 name=FUN_005120c0 size=24 ====

void FUN_005120c0(void)

{
  QEvent *unaff_RBX;
  QVariant *unaff_RBP;
  
  QVariant::~QVariant(unaff_RBP);
  QEvent::~QEvent(unaff_RBX);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=005120d8 name=FUN_005120d8 size=32 ====

void FUN_005120d8(void)

{
  void *unaff_RBP;
  
  operator_delete(unaff_RBP,8);
  FUN_00948650();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=005120f8 name=FUN_005120f8 size=12 ====

void FUN_005120f8(void)

{
  long unaff_RBP;
  
  *(undefined1 *)(unaff_RBP + 8) = 0;
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00512104 name=FUN_00512104 size=16 ====

void FUN_00512104(void)

{
  QEvent *unaff_RBX;
  
  QEvent::~QEvent(unaff_RBX);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00512114 name=FUN_00512114 size=14 ====

void FUN_00512114(void)

{
  long unaff_R12;
  
  *(undefined1 *)(unaff_R12 + 8) = 0;
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00512122 name=FUN_00512122 size=16 ====

void FUN_00512122(void)

{
  QStyleOption *unaff_RBP;
  
  QStyleOption::~QStyleOption(unaff_RBP);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00512132 name=FUN_00512132 size=21 ====

void FUN_00512132(void)

{
  void *unaff_R12;
  
  operator_delete(unaff_R12,0x60);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00512148 name=FUN_00512148 size=16 ====

void FUN_00512148(void)

{
  QStyleOption *unaff_RBP;
  
  QStyleOption::~QStyleOption(unaff_RBP);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00512158 name=FUN_00512158 size=24 ====

void FUN_00512158(void)

{
  QVariant *unaff_RBX;
  QVariant *unaff_R12;
  
  QVariant::~QVariant(unaff_RBX);
  QVariant::~QVariant(unaff_R12);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00512170 name=FUN_00512170 size=21 ====

void FUN_00512170(void)

{
  void *unaff_R12;
  
  operator_delete(unaff_R12,0x20);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00512186 name=FUN_00512186 size=64 ====

void FUN_00512186(void)

{
  QScrollBar *unaff_RBX;
  void *unaff_RBP;
  QPixmap *unaff_R13;
  
  operator_delete(unaff_RBP,0x20);
  QPixmap::~QPixmap(unaff_R13);
  *(undefined ***)unaff_RBX = &ScrollBar_vtable;
  *(undefined ***)(unaff_RBX + 0x10) = &PTR_FUN_01196ad0;
  QScrollBar::~QScrollBar(unaff_RBX);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=005121c6 name=FUN_005121c6 size=40 ====

void FUN_005121c6(void)

{
  QVariant *unaff_RBP;
  QVariant *unaff_R12;
  QPixmap *unaff_R14;
  QVariant *unaff_R15;
  
  QPixmap::~QPixmap(unaff_R14);
  QVariant::~QVariant(unaff_RBP);
  QVariant::~QVariant(unaff_R12);
  QVariant::~QVariant(unaff_R15);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=005121ee name=FUN_005121ee size=16 ====

void FUN_005121ee(void)

{
  QPainter *unaff_RBP;
  
  QPainter::~QPainter(unaff_RBP);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00512200 name=FUN_00512200 size=16 ====

void FUN_00512200(void)

{
  FUN_0096bb02();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00512210 name=FUN_00512210 size=16 ====

void FUN_00512210(void)

{
  FUN_0096bb02();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00512220 name=FUN_00512220 size=16 ====

void FUN_00512220(void)

{
  FUN_0096bb02();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00512230 name=FUN_00512230 size=16 ====

void FUN_00512230(void)

{
  FUN_0096bb02();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00512240 name=FUN_00512240 size=16 ====

void FUN_00512240(void)

{
  sharedptr_release();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00512250 name=FUN_00512250 size=25 ====

void FUN_00512250(void)

{
  long in_stack_00000008;
  
  if (in_stack_00000008 != 0) {
    sharedptr_release();
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0051226a name=FUN_0051226a size=28 ====

void FUN_0051226a(void)

{
  qt_array_data_unref();
  __cxa_guard_abort(&DAT_011c28a0);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00512286 name=FUN_00512286 size=32 ====

void FUN_00512286(void)

{
  QRegularExpressionMatch *unaff_RBP;
  
  qt_array_data_unref();
  QRegularExpressionMatch::~QRegularExpressionMatch(unaff_RBP);
  qt_array_data_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=005122a6 name=FUN_005122a6 size=10 ====

void FUN_005122a6(void)

{
  QRegularExpressionMatch *unaff_RBP;
  
  qt_array_data_unref();
  QRegularExpressionMatch::~QRegularExpressionMatch(unaff_RBP);
  qt_array_data_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=005122b0 name=FUN_005122b0 size=16 ====

void FUN_005122b0(void)

{
  sharedptr_release();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=005122c0 name=FUN_005122c0 size=25 ====

void FUN_005122c0(void)

{
  long in_stack_00000018;
  
  if (in_stack_00000018 != 0) {
    sharedptr_release();
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=005122da name=FUN_005122da size=16 ====

void FUN_005122da(void)

{
  FUN_0096bb02();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=005122ea name=FUN_005122ea size=16 ====

void FUN_005122ea(void)

{
  splitvector_blocks_free();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=005122fa name=FUN_005122fa size=16 ====

void FUN_005122fa(void)

{
  FUN_00974856();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0051230a name=FUN_0051230a size=16 ====

void FUN_0051230a(void)

{
  FUN_00974856();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0051231a name=FUN_0051231a size=16 ====

void FUN_0051231a(void)

{
  FUN_00974856();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0051232a name=FUN_0051232a size=16 ====

void FUN_0051232a(void)

{
  FUN_00974856();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0051233a name=FUN_0051233a size=16 ====

void FUN_0051233a(void)

{
  FUN_00974856();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0051234a name=FUN_0051234a size=16 ====

void FUN_0051234a(void)

{
  FUN_00974856();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0051235a name=FUN_0051235a size=16 ====

void FUN_0051235a(void)

{
  FUN_00974856();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0051236a name=FUN_0051236a size=16 ====

void FUN_0051236a(void)

{
  FUN_00974856();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0051237a name=FUN_0051237a size=16 ====

void FUN_0051237a(void)

{
  FUN_00974856();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0051238a name=FUN_0051238a size=16 ====

void FUN_0051238a(void)

{
  FUN_00974856();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0051239a name=FUN_0051239a size=16 ====

void FUN_0051239a(void)

{
  FUN_00974856();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=005123aa name=FUN_005123aa size=16 ====

void FUN_005123aa(void)

{
  FUN_00974856();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=005123ba name=FUN_005123ba size=16 ====

void FUN_005123ba(void)

{
  FUN_00a161d8();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=005123ca name=FUN_005123ca size=16 ====

void FUN_005123ca(void)

{
  FUN_00a161d8();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=005123da name=FUN_005123da size=16 ====

void FUN_005123da(void)

{
  FUN_00a161d8();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=005123ea name=FUN_005123ea size=16 ====

void FUN_005123ea(void)

{
  FUN_00a161d8();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=005123fa name=FUN_005123fa size=16 ====

void FUN_005123fa(void)

{
  FUN_00a161d8();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0051240a name=FUN_0051240a size=16 ====

void FUN_0051240a(void)

{
  FUN_00a161d8();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0051241a name=FUN_0051241a size=16 ====

void FUN_0051241a(void)

{
  FUN_0096bb02();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0051242a name=FUN_0051242a size=16 ====

void FUN_0051242a(void)

{
  FUN_0096bb02();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0051243a name=FUN_0051243a size=19 ====

void FUN_0051243a(void)

{
  FUN_0096bb02();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0051244e name=FUN_0051244e size=24 ====

void FUN_0051244e(void)

{
  FUN_0096bd50();
  FUN_00974856();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00512466 name=FUN_00512466 size=24 ====

void FUN_00512466(void)

{
  FUN_0096bb02();
  FUN_0096bb02();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0051247e name=FUN_0051247e size=16 ====

void FUN_0051247e(void)

{
  FUN_00974856();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0051248e name=FUN_0051248e size=24 ====

void FUN_0051248e(void)

{
  FUN_0096bd50();
  FUN_00974856();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=005124a6 name=FUN_005124a6 size=24 ====

void FUN_005124a6(void)

{
  FUN_0096bd50();
  FUN_00974856();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=005124be name=FUN_005124be size=24 ====

void FUN_005124be(void)

{
  FUN_0096bb02();
  FUN_0096bb02();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=005124d6 name=FUN_005124d6 size=24 ====

void FUN_005124d6(void)

{
  FUN_0096bb02();
  FUN_0096bb02();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=005124ee name=FUN_005124ee size=24 ====

void FUN_005124ee(void)

{
  FUN_0096bd50();
  FUN_00974856();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00512506 name=FUN_00512506 size=24 ====

void FUN_00512506(void)

{
  FUN_0096bb02();
  FUN_0096bb02();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0051251e name=FUN_0051251e size=16 ====

void FUN_0051251e(void)

{
  FUN_00a161d8();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0051252e name=FUN_0051252e size=21 ====

void FUN_0051252e(void)

{
  FUN_00927a14();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00512544 name=FUN_00512544 size=38 ====

void FUN_00512544(void)

{
  undefined1 *unaff_retaddr;
  
  if (unaff_retaddr != &DAT_011c5338) {
    refcount_delete_offset10_c();
  }
  qt_byte_array_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0051256a name=FUN_0051256a size=24 ====

void FUN_0051256a(void)

{
  FUN_0096bb02();
  FUN_0096bb02();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00512582 name=FUN_00512582 size=24 ====

void FUN_00512582(void)

{
  FUN_0096bb02();
  FUN_0096bb02();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0051259a name=FUN_0051259a size=16 ====

void FUN_0051259a(void)

{
  FUN_0096bb02();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=005125aa name=FUN_005125aa size=29 ====

void FUN_005125aa(void)

{
  FUN_0096bb02();
  FUN_00927a14();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=005125c7 name=FUN_005125c7 size=16 ====

void FUN_005125c7(void)

{
  FUN_0096bb02();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=005125d8 name=FUN_005125d8 size=21 ====

void FUN_005125d8(void)

{
  qt_byte_array_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=005125ee name=FUN_005125ee size=16 ====

void FUN_005125ee(void)

{
  qt_array_data_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=005125fe name=FUN_005125fe size=16 ====

void FUN_005125fe(void)

{
  qt_array_data_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0051260e name=FUN_0051260e size=16 ====

void FUN_0051260e(void)

{
  FUN_0096bb02();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0051261e name=FUN_0051261e size=24 ====

void FUN_0051261e(void)

{
  FUN_0096bb02();
  FUN_0096bb02();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00512636 name=FUN_00512636 size=16 ====

void FUN_00512636(void)

{
  FUN_0096bd50();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00512646 name=FUN_00512646 size=24 ====

void FUN_00512646(void)

{
  FUN_0096bb02();
  FUN_0096bb02();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0051265e name=FUN_0051265e size=24 ====

void FUN_0051265e(void)

{
  FUN_0096bb02();
  FUN_0096bb02();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00512676 name=FUN_00512676 size=24 ====

void FUN_00512676(void)

{
  FUN_0096bb02();
  FUN_0096bb02();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0051268e name=FUN_0051268e size=16 ====

void FUN_0051268e(void)

{
  FUN_0096bb02();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0051269e name=FUN_0051269e size=24 ====

void FUN_0051269e(void)

{
  FUN_0096bb02();
  FUN_0096bb02();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=005126b6 name=FUN_005126b6 size=16 ====

void FUN_005126b6(void)

{
  FUN_0096bb02();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=005126c6 name=FUN_005126c6 size=16 ====

void FUN_005126c6(void)

{
  FUN_0096bb02();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=005126d6 name=FUN_005126d6 size=24 ====

void FUN_005126d6(void)

{
  FUN_0096bb02();
  FUN_0096bb02();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=005126ee name=FUN_005126ee size=16 ====

void FUN_005126ee(void)

{
  FUN_0096bb02();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=005126fe name=FUN_005126fe size=24 ====

void FUN_005126fe(void)

{
  FUN_0096bb02();
  FUN_00974856();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00512716 name=FUN_00512716 size=16 ====

void FUN_00512716(void)

{
  FUN_0096bb02();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00512726 name=FUN_00512726 size=16 ====

void FUN_00512726(void)

{
  FUN_0096bb02();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00512736 name=FUN_00512736 size=16 ====

void FUN_00512736(void)

{
  FUN_00974856();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00512746 name=FUN_00512746 size=16 ====

void FUN_00512746(void)

{
  FUN_00974856();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00512756 name=FUN_00512756 size=16 ====

void FUN_00512756(void)

{
  FUN_00974856();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00512766 name=FUN_00512766 size=16 ====

void FUN_00512766(void)

{
  FUN_00974856();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00512776 name=FUN_00512776 size=16 ====

void FUN_00512776(void)

{
  FUN_00a161d8();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00512786 name=FUN_00512786 size=28 ====

void FUN_00512786(void)

{
  undefined8 in_stack_00000008;
  
  qt_byte_array_unref(&stack0x00000018);
  FUN_00963b22(in_stack_00000008);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=005127a2 name=FUN_005127a2 size=16 ====

void FUN_005127a2(void)

{
  sharedptr_release();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=005127b2 name=FUN_005127b2 size=25 ====

void FUN_005127b2(void)

{
  long in_stack_00000018;
  
  if (in_stack_00000018 != 0) {
    sharedptr_release();
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=005127cc name=FUN_005127cc size=16 ====

void FUN_005127cc(void)

{
  sharedptr_release();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=005127dc name=FUN_005127dc size=25 ====

void FUN_005127dc(void)

{
  long in_stack_00000008;
  
  if (in_stack_00000008 != 0) {
    sharedptr_release();
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=005127f6 name=FUN_005127f6 size=16 ====

void FUN_005127f6(void)

{
  sharedptr_release();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00512806 name=FUN_00512806 size=25 ====

void FUN_00512806(void)

{
  long in_stack_00000028;
  
  if (in_stack_00000028 != 0) {
    sharedptr_release();
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00512820 name=FUN_00512820 size=16 ====

void FUN_00512820(void)

{
  sharedptr_release();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00512830 name=FUN_00512830 size=25 ====

void FUN_00512830(void)

{
  long in_stack_00000008;
  
  if (in_stack_00000008 != 0) {
    sharedptr_release();
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0051284a name=FUN_0051284a size=16 ====

void FUN_0051284a(void)

{
  sharedptr_release();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0051285a name=FUN_0051285a size=25 ====

void FUN_0051285a(void)

{
  long in_stack_00000008;
  
  if (in_stack_00000008 != 0) {
    sharedptr_release();
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00512874 name=FUN_00512874 size=23 ====

void FUN_00512874(void)

{
  long in_stack_00000018;
  
  if (in_stack_00000018 != 0) {
    sharedptr_release();
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0051288b name=FUN_0051288b size=16 ====

void FUN_0051288b(void)

{
  sharedptr_release();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0051289c name=FUN_0051289c size=24 ====

void FUN_0051289c(void)

{
  FUN_0096bb02();
  FUN_0096bb02();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=005128b4 name=FUN_005128b4 size=16 ====

void FUN_005128b4(void)

{
  sharedptr_release();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=005128c4 name=FUN_005128c4 size=25 ====

void FUN_005128c4(void)

{
  long in_stack_00000018;
  
  if (in_stack_00000018 != 0) {
    sharedptr_release();
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=005128de name=FUN_005128de size=24 ====

void FUN_005128de(void)

{
  sharedptr_release();
  FUN_00a161d8();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=005128f6 name=FUN_005128f6 size=17 ====

void FUN_005128f6(void)

{
  long in_stack_00000018;
  
  if (in_stack_00000018 != 0) {
    sharedptr_release();
  }
  FUN_00a161d8();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00512908 name=FUN_00512908 size=28 ====

void FUN_00512908(void)

{
  undefined8 in_stack_00000018;
  
  FUN_0096bd50(&stack0x00000030);
  FUN_00963b22(in_stack_00000018);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00512924 name=FUN_00512924 size=16 ====

void FUN_00512924(void)

{
  FUN_00963b22();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00512934 name=FUN_00512934 size=28 ====

void FUN_00512934(void)

{
  undefined8 in_stack_00000008;
  undefined8 in_stack_00000018;
  
  FUN_0096bb02(in_stack_00000008);
  FUN_00963b22(in_stack_00000018);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00512950 name=FUN_00512950 size=12 ====

void FUN_00512950(void)

{
  undefined8 in_stack_00000008;
  undefined8 in_stack_00000018;
  
  FUN_0096bb02(in_stack_00000008);
  FUN_00963b22(in_stack_00000018);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0051295c name=FUN_0051295c size=12 ====

void FUN_0051295c(void)

{
  undefined8 in_stack_00000008;
  undefined8 in_stack_00000018;
  
  FUN_0096bb02(in_stack_00000008);
  FUN_00963b22(in_stack_00000018);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00512968 name=FUN_00512968 size=12 ====

void FUN_00512968(void)

{
  undefined8 in_stack_00000008;
  undefined8 in_stack_00000018;
  
  FUN_0096bb02(in_stack_00000008);
  FUN_00963b22(in_stack_00000018);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00512974 name=FUN_00512974 size=14 ====

void FUN_00512974(void)

{
  undefined8 in_stack_00000008;
  undefined8 in_stack_00000018;
  
  FUN_0096bb02(in_stack_00000008);
  FUN_00963b22(in_stack_00000018);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00512982 name=FUN_00512982 size=18 ====

void FUN_00512982(void)

{
  undefined8 in_stack_00000018;
  
  FUN_00963b22(in_stack_00000018);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00512994 name=FUN_00512994 size=16 ====

void FUN_00512994(void)

{
  FUN_0096bb02();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=005129a4 name=FUN_005129a4 size=16 ====

void FUN_005129a4(void)

{
  FUN_0096bb02();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=005129b4 name=FUN_005129b4 size=16 ====

void FUN_005129b4(void)

{
  FUN_0096bb02();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=005129c4 name=FUN_005129c4 size=31 ====

void FUN_005129c4(void)

{
  undefined1 *in_stack_00000068;
  
  if (in_stack_00000068 != &DAT_011c5338) {
    refcount_delete_offset10_c();
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=005129e4 name=FUN_005129e4 size=18 ====

void FUN_005129e4(void)

{
  undefined8 in_stack_00000008;
  
  FUN_00963b22(in_stack_00000008);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=005129f6 name=FUN_005129f6 size=54 ====

void FUN_005129f6(void)

{
  undefined8 in_stack_00000038;
  undefined8 in_stack_00000040;
  undefined8 in_stack_00000048;
  
  qt_byte_array_unref();
  qt_byte_array_unref(in_stack_00000038);
  qt_byte_array_unref();
  qt_byte_array_unref(in_stack_00000040);
  FUN_00963b22(in_stack_00000048);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00512a2c name=FUN_00512a2c size=15 ====

void FUN_00512a2c(void)

{
  undefined8 in_stack_00000040;
  undefined8 in_stack_00000048;
  
  qt_byte_array_unref();
  qt_byte_array_unref(&stack0x00000068);
  qt_byte_array_unref(in_stack_00000040);
  FUN_00963b22(in_stack_00000048);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00512a3b name=FUN_00512a3b size=18 ====

void FUN_00512a3b(void)

{
  undefined8 in_stack_00000040;
  undefined8 in_stack_00000048;
  
  qt_byte_array_unref();
  qt_byte_array_unref();
  qt_byte_array_unref();
  qt_byte_array_unref(in_stack_00000040);
  FUN_00963b22(in_stack_00000048);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00512a4d name=FUN_00512a4d size=20 ====

void FUN_00512a4d(void)

{
  undefined8 in_stack_00000018;
  undefined8 in_stack_00000040;
  undefined8 in_stack_00000048;
  
  qt_byte_array_unref();
  qt_byte_array_unref(in_stack_00000018);
  qt_byte_array_unref();
  qt_byte_array_unref(in_stack_00000040);
  FUN_00963b22(in_stack_00000048);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00512a61 name=FUN_00512a61 size=20 ====

void FUN_00512a61(void)

{
  undefined8 in_stack_00000040;
  undefined8 in_stack_00000048;
  
  FUN_0096bb02();
  qt_byte_array_unref(&stack0x00000060);
  qt_byte_array_unref(in_stack_00000040);
  FUN_00963b22(in_stack_00000048);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00512a75 name=FUN_00512a75 size=17 ====

void FUN_00512a75(void)

{
  undefined8 in_stack_00000038;
  undefined8 in_stack_00000040;
  undefined8 in_stack_00000048;
  
  qt_byte_array_unref(in_stack_00000038);
  qt_byte_array_unref(&stack0x00000068);
  qt_byte_array_unref(in_stack_00000040);
  FUN_00963b22(in_stack_00000048);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00512a86 name=FUN_00512a86 size=10 ====

void FUN_00512a86(void)

{
  undefined8 in_stack_00000040;
  undefined8 in_stack_00000048;
  
  FUN_0096bb02();
  qt_byte_array_unref(&stack0x00000060);
  qt_byte_array_unref(in_stack_00000040);
  FUN_00963b22(in_stack_00000048);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00512a90 name=FUN_00512a90 size=10 ====

void FUN_00512a90(void)

{
  undefined8 in_stack_00000040;
  undefined8 in_stack_00000048;
  
  FUN_0096bb02();
  qt_byte_array_unref(&stack0x00000060);
  qt_byte_array_unref(in_stack_00000040);
  FUN_00963b22(in_stack_00000048);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00512a9a name=FUN_00512a9a size=18 ====

void FUN_00512a9a(void)

{
  undefined8 in_stack_00000008;
  
  FUN_00963b22(in_stack_00000008);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00512aac name=FUN_00512aac size=26 ====

void FUN_00512aac(void)

{
  undefined8 in_stack_00000008;
  
  FUN_0096bb02();
  FUN_00963b22(in_stack_00000008);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00512ac6 name=FUN_00512ac6 size=10 ====

void FUN_00512ac6(void)

{
  undefined8 in_stack_00000008;
  
  FUN_0096bb02();
  FUN_00963b22(in_stack_00000008);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00512ad0 name=FUN_00512ad0 size=26 ====

void FUN_00512ad0(void)

{
  undefined8 in_stack_00000018;
  
  FUN_0096bb02();
  FUN_00963b22(in_stack_00000018);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00512aea name=FUN_00512aea size=26 ====

void FUN_00512aea(void)

{
  undefined8 in_stack_00000018;
  
  FUN_0096bb02();
  FUN_00963b22(in_stack_00000018);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00512b04 name=FUN_00512b04 size=32 ====

void FUN_00512b04(void)

{
  FUN_0096bb02();
  FUN_0096bb02();
  FUN_00963b22();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00512b24 name=FUN_00512b24 size=10 ====

void FUN_00512b24(void)

{
  FUN_0096bd50();
  FUN_00963b22();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00512b2e name=FUN_00512b2e size=16 ====

void FUN_00512b2e(void)

{
  FUN_00963b22();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00512b3e name=FUN_00512b3e size=63 ====

void FUN_00512b3e(void)

{
  undefined1 *in_stack_00000020;
  undefined1 *in_stack_00000028;
  
  if (in_stack_00000028 != &DAT_011c5338) {
    refcount_delete_offset10_c();
  }
  if (in_stack_00000020 != &DAT_011c5338) {
    refcount_delete_offset10_c();
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00512b69 name=FUN_00512b69 size=37 ====

void FUN_00512b69(void)

{
  undefined1 *in_stack_00000028;
  
  if (in_stack_00000028 != &DAT_011c5338) {
    refcount_delete_offset10_c();
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00512ba2 name=FUN_00512ba2 size=43 ====

void FUN_00512ba2(void)

{
  FUN_0096bd50();
  FUN_0096bb02();
  FUN_0096bb02();
  FUN_00974856();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00512bce name=FUN_00512bce size=16 ====

void FUN_00512bce(void)

{
  FUN_0096bb02();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00512bde name=FUN_00512bde size=16 ====

void FUN_00512bde(void)

{
  FUN_0096bb02();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00512bee name=FUN_00512bee size=16 ====

void FUN_00512bee(void)

{
  FUN_0096bb02();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00512bfe name=FUN_00512bfe size=16 ====

void FUN_00512bfe(void)

{
  FUN_0096bb02();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00512c0e name=FUN_00512c0e size=18 ====

void FUN_00512c0e(void)

{
  undefined8 in_stack_00000008;
  
  FUN_00963b22(in_stack_00000008);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00512c20 name=FUN_00512c20 size=16 ====

void FUN_00512c20(void)

{
  FUN_0096bb02();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00512c30 name=FUN_00512c30 size=26 ====

void FUN_00512c30(void)

{
  undefined8 in_stack_00000010;
  
  FUN_0096bb02(in_stack_00000010);
  FUN_0096bb02();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00512c4a name=FUN_00512c4a size=26 ====

void FUN_00512c4a(void)

{
  undefined8 in_stack_00000010;
  
  FUN_0096bb02(in_stack_00000010);
  FUN_0096bb02();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00512c64 name=FUN_00512c64 size=26 ====

void FUN_00512c64(void)

{
  undefined8 in_stack_00000010;
  
  FUN_0096bb02(in_stack_00000010);
  FUN_0096bb02();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00512c7e name=FUN_00512c7e size=26 ====

void FUN_00512c7e(void)

{
  undefined8 in_stack_00000010;
  
  FUN_0096bb02(in_stack_00000010);
  FUN_0096bb02();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00512c98 name=FUN_00512c98 size=26 ====

void FUN_00512c98(void)

{
  undefined8 in_stack_00000010;
  
  FUN_0096bb02(in_stack_00000010);
  FUN_0096bb02();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00512cb2 name=FUN_00512cb2 size=26 ====

void FUN_00512cb2(void)

{
  undefined8 in_stack_00000010;
  
  FUN_0096bb02(in_stack_00000010);
  FUN_0096bb02();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00512ccc name=FUN_00512ccc size=42 ====

void FUN_00512ccc(void)

{
  undefined8 in_stack_00000010;
  
  FUN_0096bd50(in_stack_00000010);
  FUN_0096bd50();
  FUN_0096bb02();
  FUN_0096bb02();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00512cf6 name=FUN_00512cf6 size=26 ====

void FUN_00512cf6(void)

{
  undefined8 in_stack_00000010;
  
  FUN_0096bb02(in_stack_00000010);
  FUN_0096bb02();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00512d10 name=FUN_00512d10 size=26 ====

void FUN_00512d10(void)

{
  undefined8 in_stack_00000010;
  
  FUN_0096bb02(in_stack_00000010);
  FUN_0096bb02();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00512d2a name=FUN_00512d2a size=38 ====

void FUN_00512d2a(void)

{
  undefined8 unaff_retaddr;
  
  FUN_0096bb02(unaff_retaddr);
  FUN_0096bb02(&stack0x00000030);
  FUN_00974856();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00512d50 name=FUN_00512d50 size=16 ====

void FUN_00512d50(void)

{
  undefined8 unaff_retaddr;
  
  FUN_0096bb02(unaff_retaddr);
  FUN_0096bb02(&stack0x00000030);
  FUN_00974856();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00512d60 name=FUN_00512d60 size=10 ====

void FUN_00512d60(void)

{
  FUN_0096bb02();
  FUN_0096bb02();
  FUN_00974856();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00512d6a name=FUN_00512d6a size=10 ====

void FUN_00512d6a(void)

{
  FUN_0096bb02();
  FUN_0096bb02();
  FUN_00974856();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00512d74 name=FUN_00512d74 size=25 ====

void FUN_00512d74(void)

{
  undefined8 in_stack_00000008;
  
  FUN_0096bb02(in_stack_00000008);
  FUN_0096bb02();
  FUN_0096bb02(&stack0x00000030);
  FUN_00974856();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00512d8d name=FUN_00512d8d size=25 ====

void FUN_00512d8d(void)

{
  undefined8 in_stack_00000008;
  
  FUN_0096bb02(in_stack_00000008);
  FUN_0096bb02();
  FUN_0096bb02(&stack0x00000030);
  FUN_00974856();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00512da6 name=FUN_00512da6 size=16 ====

void FUN_00512da6(void)

{
  FUN_0096bb02();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00512db6 name=FUN_00512db6 size=16 ====

void FUN_00512db6(void)

{
  FUN_0096bb02();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00512dc6 name=FUN_00512dc6 size=16 ====

void FUN_00512dc6(void)

{
  FUN_0096bb02();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00512dd6 name=FUN_00512dd6 size=16 ====

void FUN_00512dd6(void)

{
  FUN_0096bb02();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00512de6 name=FUN_00512de6 size=21 ====

void FUN_00512de6(void)

{
  void *unaff_RBP;
  
  operator_delete(unaff_RBP,0x88);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00512dfc name=FUN_00512dfc size=26 ====

void FUN_00512dfc(void)

{
  undefined8 in_stack_00000018;
  
  FUN_0096bb02();
  FUN_00963b22(in_stack_00000018);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00512e16 name=FUN_00512e16 size=16 ====

void FUN_00512e16(void)

{
  FUN_0096bb02();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00512e26 name=FUN_00512e26 size=16 ====

void FUN_00512e26(void)

{
  FUN_00974856();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00512e36 name=FUN_00512e36 size=16 ====

void FUN_00512e36(void)

{
  FUN_00974856();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00512e46 name=FUN_00512e46 size=24 ====

void FUN_00512e46(void)

{
  FUN_0096bb02();
  FUN_00963b22();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00512e5e name=FUN_00512e5e size=16 ====

void FUN_00512e5e(void)

{
  FUN_0096bb02();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00512e6e name=FUN_00512e6e size=16 ====

void FUN_00512e6e(void)

{
  FUN_0096bb02();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00512e7e name=FUN_00512e7e size=16 ====

void FUN_00512e7e(void)

{
  qt_byte_array_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00512e8e name=FUN_00512e8e size=16 ====

void FUN_00512e8e(void)

{
  FUN_0096bb02();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00512e9e name=FUN_00512e9e size=16 ====

void FUN_00512e9e(void)

{
  FUN_0096bd50();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00512eae name=FUN_00512eae size=24 ====

void FUN_00512eae(void)

{
  FUN_0096bb02();
  FUN_0096bb02();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00512ec6 name=FUN_00512ec6 size=16 ====

void FUN_00512ec6(void)

{
  FUN_0096bb02();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00512ed6 name=FUN_00512ed6 size=16 ====

void FUN_00512ed6(void)

{
  FUN_0096bb02();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00512ee6 name=FUN_00512ee6 size=44 ====

void FUN_00512ee6(void)

{
  undefined8 in_stack_00000018;
  void *in_stack_000000c8;
  
  FUN_0096bb02();
  FUN_0096bb02(in_stack_00000018);
  if (in_stack_000000c8 != (void *)0x0) {
    operator_delete(in_stack_000000c8);
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00512f12 name=FUN_00512f12 size=10 ====

void FUN_00512f12(void)

{
  void *in_stack_000000c8;
  
  FUN_0096bb02();
  if (in_stack_000000c8 != (void *)0x0) {
    operator_delete(in_stack_000000c8);
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00512f1c name=FUN_00512f1c size=18 ====

void FUN_00512f1c(void)

{
  void *in_stack_000000c8;
  
  FUN_0096bb02();
  FUN_0096bb02();
  if (in_stack_000000c8 != (void *)0x0) {
    operator_delete(in_stack_000000c8);
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00512f2e name=FUN_00512f2e size=21 ====

void FUN_00512f2e(void)

{
  void *in_stack_000000c8;
  
  FUN_0096bb02();
  FUN_0096bb02();
  if (in_stack_000000c8 != (void *)0x0) {
    operator_delete(in_stack_000000c8);
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00512f43 name=FUN_00512f43 size=21 ====

void FUN_00512f43(void)

{
  void *in_stack_000000c8;
  
  FUN_0096bb02();
  FUN_0096bb02();
  if (in_stack_000000c8 != (void *)0x0) {
    operator_delete(in_stack_000000c8);
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00512f58 name=FUN_00512f58 size=26 ====

void FUN_00512f58(void)

{
  FUN_00974856();
  splitvector_blocks_free(&stack0x00000020);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00512f72 name=FUN_00512f72 size=24 ====

void FUN_00512f72(void)

{
  FUN_0096bb02();
  FUN_0096bb02();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00512f8a name=FUN_00512f8a size=24 ====

void FUN_00512f8a(void)

{
  QVariant *unaff_R13;
  QVariant *unaff_R14;
  
  QVariant::~QVariant(unaff_R14);
  QVariant::~QVariant(unaff_R13);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00512fa2 name=FUN_00512fa2 size=16 ====

void FUN_00512fa2(void)

{
  FUN_0096bb02();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00512fb2 name=FUN_00512fb2 size=16 ====

void FUN_00512fb2(void)

{
  FUN_0096bb02();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00512fc2 name=FUN_00512fc2 size=21 ====

void FUN_00512fc2(void)

{
  void *unaff_R12;
  
  operator_delete(unaff_R12,4);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00512fd7 name=FUN_00512fd7 size=10 ====

void FUN_00512fd7(void)

{
  FUN_0096bb02();
  FUN_0096bb02();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00512fe1 name=FUN_00512fe1 size=16 ====

void FUN_00512fe1(void)

{
  FUN_0096bb02();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00512ff2 name=FUN_00512ff2 size=16 ====

void FUN_00512ff2(void)

{
  FUN_00a161d8();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00513002 name=FUN_00513002 size=31 ====

void FUN_00513002(void)

{
  undefined1 *in_stack_00000018;
  
  if (in_stack_00000018 != &DAT_011c5338) {
    refcount_delete_offset10_c();
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00513022 name=FUN_00513022 size=16 ====

void FUN_00513022(void)

{
  FUN_0096bb02();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00513032 name=FUN_00513032 size=48 ====

void FUN_00513032(void)

{
  undefined8 in_stack_00000008;
  code *in_stack_00000030;
  code *in_stack_00000050;
  
  if (in_stack_00000030 != (code *)0x0) {
    (*in_stack_00000030)();
  }
  if (in_stack_00000050 != (code *)0x0) {
    (*in_stack_00000050)();
  }
  FUN_009cff96(in_stack_00000008);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00513062 name=FUN_00513062 size=34 ====

void FUN_00513062(void)

{
  undefined8 in_stack_00000008;
  
  qt_byte_array_unref();
  stdfunction_state_destroy();
  FUN_009cff96(in_stack_00000008);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00513084 name=FUN_00513084 size=16 ====

void FUN_00513084(void)

{
  FUN_0096bb02();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00513094 name=FUN_00513094 size=44 ====

void FUN_00513094(void)

{
  undefined8 in_stack_00000008;
  undefined8 in_stack_00000010;
  
  stdfunction_state_destroy();
  FUN_009cff96();
  FUN_00974856(in_stack_00000008);
  FUN_00a161d8(in_stack_00000010);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=005130c0 name=FUN_005130c0 size=54 ====

void FUN_005130c0(void)

{
  undefined8 in_stack_00000008;
  undefined8 in_stack_00000010;
  code *in_stack_00000080;
  code *in_stack_000000a0;
  
  if (in_stack_00000080 != (code *)0x0) {
    (*in_stack_00000080)();
  }
  if (in_stack_000000a0 != (code *)0x0) {
    (*in_stack_000000a0)();
  }
  FUN_009cff96();
  FUN_00974856(in_stack_00000008);
  FUN_00a161d8(in_stack_00000010);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=005130f6 name=FUN_005130f6 size=16 ====

void FUN_005130f6(void)

{
  qt_array_data_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00513106 name=FUN_00513106 size=16 ====

void FUN_00513106(void)

{
  sharedptr_release();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00513116 name=FUN_00513116 size=25 ====

void FUN_00513116(void)

{
  long in_stack_00000008;
  
  if (in_stack_00000008 != 0) {
    sharedptr_release();
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00513130 name=FUN_00513130 size=16 ====

void FUN_00513130(void)

{
  sharedptr_release();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00513140 name=FUN_00513140 size=25 ====

void FUN_00513140(void)

{
  long in_stack_00000018;
  
  if (in_stack_00000018 != 0) {
    sharedptr_release();
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0051315a name=FUN_0051315a size=23 ====

void FUN_0051315a(void)

{
  long *unaff_RBP;
  
  if (unaff_RBP != (long *)0x0) {
    (**(code **)(*unaff_RBP + 8))();
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00513171 name=FUN_00513171 size=10 ====

void FUN_00513171(void)

{
  long *unaff_RBP;
  
  stdfunction_state_destroy();
  (**(code **)(*unaff_RBP + 8))();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0051317b name=FUN_0051317b size=48 ====

void FUN_0051317b(void)

{
  long *unaff_RBP;
  code *in_stack_00000030;
  code *in_stack_00000050;
  
  if (in_stack_00000030 != (code *)0x0) {
    (*in_stack_00000030)();
  }
  if (in_stack_00000050 != (code *)0x0) {
    (*in_stack_00000050)();
  }
  (**(code **)(*unaff_RBP + 8))();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=005131ac name=FUN_005131ac size=16 ====

void FUN_005131ac(void)

{
  FUN_0096bb02();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=005131bc name=FUN_005131bc size=16 ====

void FUN_005131bc(void)

{
  FUN_0096bb02();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=005131cc name=FUN_005131cc size=24 ====

void FUN_005131cc(void)

{
  sharedptr_release();
  FUN_0096bb02();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=005131e4 name=FUN_005131e4 size=17 ====

void FUN_005131e4(void)

{
  long in_stack_00000028;
  
  if (in_stack_00000028 != 0) {
    sharedptr_release();
  }
  FUN_0096bb02();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=005131f6 name=FUN_005131f6 size=16 ====

void FUN_005131f6(void)

{
  FUN_0096bb02();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00513206 name=FUN_00513206 size=16 ====

void FUN_00513206(void)

{
  FUN_0096bb02();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00513216 name=FUN_00513216 size=24 ====

void FUN_00513216(void)

{
  FUN_0096bb02();
  FUN_0096bb02();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0051322e name=FUN_0051322e size=10 ====

void FUN_0051322e(void)

{
  FUN_0096bb02();
  FUN_0096bb02();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00513238 name=FUN_00513238 size=16 ====

void FUN_00513238(void)

{
  FUN_0096bb02();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00513248 name=FUN_00513248 size=24 ====

void FUN_00513248(void)

{
  FUN_0096bb02();
  FUN_0096bb02();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00513260 name=FUN_00513260 size=23 ====

void FUN_00513260(void)

{
  _Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *in_stack_00000028;
  
  if (in_stack_00000028 != (_Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *)0x0) {
    std::_Sp_counted_base<(__gnu_cxx::_Lock_policy)2>::_M_release(in_stack_00000028);
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00513277 name=FUN_00513277 size=16 ====

void FUN_00513277(void)

{
  FUN_0096bd50();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00513288 name=FUN_00513288 size=21 ====

void FUN_00513288(void)

{
  void *unaff_R12;
  
  operator_delete(unaff_R12,0x58);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0051329d name=FUN_0051329d size=21 ====

void FUN_0051329d(void)

{
  void *unaff_R12;
  
  operator_delete(unaff_R12,0x198);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=005132b2 name=FUN_005132b2 size=16 ====

void FUN_005132b2(void)

{
  void *unaff_R12;
  
  operator_delete(unaff_R12);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=005132c2 name=FUN_005132c2 size=21 ====

void FUN_005132c2(void)

{
  void *unaff_R12;
  
  operator_delete(unaff_R12,0x18);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=005132d7 name=FUN_005132d7 size=21 ====

void FUN_005132d7(void)

{
  void *unaff_R12;
  
  operator_delete(unaff_R12,0x30);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=005132ec name=FUN_005132ec size=21 ====

void FUN_005132ec(void)

{
  void *unaff_R12;
  
  operator_delete(unaff_R12,0xa0);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00513301 name=FUN_00513301 size=21 ====

void FUN_00513301(void)

{
  void *unaff_RBP;
  
  operator_delete(unaff_RBP,0x20);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00513316 name=FUN_00513316 size=17 ====

void FUN_00513316(void)

{
  long unaff_RBX;
  
  free(*(void **)(unaff_RBX + 0x10));
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00513328 name=FUN_00513328 size=18 ====

void FUN_00513328(void)

{
  void *in_stack_00000010;
  
  free(in_stack_00000010);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0051333a name=FUN_0051333a size=654 ====

void FUN_0051333a(void)

{
  int iVar1;
  undefined8 *puVar2;
  void *pvVar3;
  long lVar4;
  int *piVar5;
  QArrayData *pQVar6;
  QArrayData *pQVar7;
  long unaff_RBX;
  void *unaff_RBP;
  undefined8 in_stack_00000010;
  undefined8 in_stack_00000018;
  undefined8 in_stack_00000020;
  
  operator_delete(unaff_RBP,0xa0);
  puVar2 = *(undefined8 **)(unaff_RBX + 0x1140);
  if (puVar2 != (undefined8 *)0x0) {
    if ((void *)*puVar2 != (void *)0x0) {
      operator_delete((void *)*puVar2);
    }
    operator_delete(puVar2,0x18);
  }
  FUN_0096bb02();
  pvVar3 = *(void **)(unaff_RBX + 0x10d0);
  if (pvVar3 != (void *)0x0) {
    FUN_00a634ba(pvVar3);
    operator_delete(pvVar3,0x48);
  }
  pvVar3 = *(void **)(unaff_RBX + 0x10c8);
  if (pvVar3 != (void *)0x0) {
    FUN_00a164e8(pvVar3);
    operator_delete(pvVar3,0x58);
  }
  pvVar3 = *(void **)(unaff_RBX + 0x10c0);
  if (pvVar3 == (void *)0x0) goto LAB_005133fc;
  pQVar6 = *(QArrayData **)((long)pvVar3 + 8);
  if (*(int *)pQVar6 == 0) {
LAB_005133bf:
    lVar4 = *(long *)(pQVar6 + 0x10);
    iVar1 = *(int *)(pQVar6 + 4);
    for (pQVar7 = pQVar6 + lVar4; pQVar6 + (long)iVar1 * 0x28 + lVar4 != pQVar7;
        pQVar7 = pQVar7 + 0x28) {
      piVar5 = *(int **)pQVar7;
      if (*piVar5 == 0) {
LAB_0051358c:
        QArrayData::deallocate(*(QArrayData **)pQVar7,2,8);
      }
      else if (*piVar5 != -1) {
        LOCK();
        *piVar5 = *piVar5 + -1;
        UNLOCK();
        if (*piVar5 == 0) goto LAB_0051358c;
      }
    }
    QArrayData::deallocate(pQVar6,0x28,8);
  }
  else if (*(int *)pQVar6 != -1) {
    LOCK();
    *(int *)pQVar6 = *(int *)pQVar6 + -1;
    UNLOCK();
    if (*(int *)pQVar6 == 0) {
      pQVar6 = *(QArrayData **)((long)pvVar3 + 8);
      goto LAB_005133bf;
    }
  }
  operator_delete(pvVar3,0x30);
LAB_005133fc:
  pvVar3 = *(void **)(unaff_RBX + 0x10b8);
  if (pvVar3 != (void *)0x0) {
    FUN_00a5e8ba(pvVar3);
    operator_delete(pvVar3,0x18);
  }
  pvVar3 = *(void **)(unaff_RBX + 0x10b0);
  if (pvVar3 != (void *)0x0) {
    FUN_00a53b6c(pvVar3);
    operator_delete(pvVar3,0x30);
  }
  if (*(void **)(unaff_RBX + 0x10a8) != (void *)0x0) {
    operator_delete(*(void **)(unaff_RBX + 0x10a8),0x20);
  }
  pvVar3 = *(void **)(unaff_RBX + 0x10a0);
  if (pvVar3 != (void *)0x0) {
    FUN_0095a5fc(pvVar3);
    operator_delete(pvVar3,0x198);
  }
  if (*(_Sp_counted_base<(__gnu_cxx::_Lock_policy)2> **)(unaff_RBX + 0x1090) !=
      (_Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *)0x0) {
    std::_Sp_counted_base<(__gnu_cxx::_Lock_policy)2>::_M_release
              (*(_Sp_counted_base<(__gnu_cxx::_Lock_policy)2> **)(unaff_RBX + 0x1090));
  }
  FUN_0096bb02();
  pvVar3 = *(void **)(unaff_RBX + 0x1038);
  if (pvVar3 != (void *)0x0) {
    FUN_00974b40(pvVar3);
    operator_delete(pvVar3,0xa0);
  }
  free(*(void **)(unaff_RBX + 0x1020));
  pvVar3 = *(void **)(unaff_RBX + 0xfb8);
  if (pvVar3 != (void *)0x0) {
    splitvector_blocks_free((long)pvVar3 + 0x38);
    FUN_0096bd50(pvVar3);
    operator_delete(pvVar3,0x88);
  }
  FUN_0096bb02(in_stack_00000020);
  FUN_0096bb02(in_stack_00000018);
  FUN_0096bb02(in_stack_00000010);
  if (*(void **)(unaff_RBX + 0xef0) != (void *)0x0) {
    operator_delete(*(void **)(unaff_RBX + 0xef0),4);
  }
  if (*(void **)(unaff_RBX + 0xeb8) != (void *)0x0) {
    operator_delete(*(void **)(unaff_RBX + 0xeb8),0x40);
  }
  FUN_00950310();
  Window_metaObject(unaff_RBX + 0x20);
  Window_metaObject(unaff_RBX + 8);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=005135c8 name=FUN_005135c8 size=18 ====

void FUN_005135c8(void)

{
  int iVar1;
  undefined8 *puVar2;
  void *pvVar3;
  long lVar4;
  int *piVar5;
  QArrayData *pQVar6;
  QArrayData *pQVar7;
  long unaff_RBX;
  void *unaff_RBP;
  undefined8 in_stack_00000010;
  undefined8 in_stack_00000018;
  undefined8 in_stack_00000020;
  
  operator_delete(unaff_RBP,0x18);
  puVar2 = *(undefined8 **)(unaff_RBX + 0x1140);
  if (puVar2 != (undefined8 *)0x0) {
    if ((void *)*puVar2 != (void *)0x0) {
      operator_delete((void *)*puVar2);
    }
    operator_delete(puVar2,0x18);
  }
  FUN_0096bb02();
  pvVar3 = *(void **)(unaff_RBX + 0x10d0);
  if (pvVar3 != (void *)0x0) {
    FUN_00a634ba(pvVar3);
    operator_delete(pvVar3,0x48);
  }
  pvVar3 = *(void **)(unaff_RBX + 0x10c8);
  if (pvVar3 != (void *)0x0) {
    FUN_00a164e8(pvVar3);
    operator_delete(pvVar3,0x58);
  }
  pvVar3 = *(void **)(unaff_RBX + 0x10c0);
  if (pvVar3 == (void *)0x0) goto LAB_005133fc;
  pQVar6 = *(QArrayData **)((long)pvVar3 + 8);
  if (*(int *)pQVar6 == 0) {
LAB_005133bf:
    lVar4 = *(long *)(pQVar6 + 0x10);
    iVar1 = *(int *)(pQVar6 + 4);
    for (pQVar7 = pQVar6 + lVar4; pQVar6 + (long)iVar1 * 0x28 + lVar4 != pQVar7;
        pQVar7 = pQVar7 + 0x28) {
      piVar5 = *(int **)pQVar7;
      if (*piVar5 == 0) {
LAB_0051358c:
        QArrayData::deallocate(*(QArrayData **)pQVar7,2,8);
      }
      else if (*piVar5 != -1) {
        LOCK();
        *piVar5 = *piVar5 + -1;
        UNLOCK();
        if (*piVar5 == 0) goto LAB_0051358c;
      }
    }
    QArrayData::deallocate(pQVar6,0x28,8);
  }
  else if (*(int *)pQVar6 != -1) {
    LOCK();
    *(int *)pQVar6 = *(int *)pQVar6 + -1;
    UNLOCK();
    if (*(int *)pQVar6 == 0) {
      pQVar6 = *(QArrayData **)((long)pvVar3 + 8);
      goto LAB_005133bf;
    }
  }
  operator_delete(pvVar3,0x30);
LAB_005133fc:
  pvVar3 = *(void **)(unaff_RBX + 0x10b8);
  if (pvVar3 != (void *)0x0) {
    FUN_00a5e8ba(pvVar3);
    operator_delete(pvVar3,0x18);
  }
  pvVar3 = *(void **)(unaff_RBX + 0x10b0);
  if (pvVar3 != (void *)0x0) {
    FUN_00a53b6c(pvVar3);
    operator_delete(pvVar3,0x30);
  }
  if (*(void **)(unaff_RBX + 0x10a8) != (void *)0x0) {
    operator_delete(*(void **)(unaff_RBX + 0x10a8),0x20);
  }
  pvVar3 = *(void **)(unaff_RBX + 0x10a0);
  if (pvVar3 != (void *)0x0) {
    FUN_0095a5fc(pvVar3);
    operator_delete(pvVar3,0x198);
  }
  if (*(_Sp_counted_base<(__gnu_cxx::_Lock_policy)2> **)(unaff_RBX + 0x1090) !=
      (_Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *)0x0) {
    std::_Sp_counted_base<(__gnu_cxx::_Lock_policy)2>::_M_release
              (*(_Sp_counted_base<(__gnu_cxx::_Lock_policy)2> **)(unaff_RBX + 0x1090));
  }
  FUN_0096bb02();
  pvVar3 = *(void **)(unaff_RBX + 0x1038);
  if (pvVar3 != (void *)0x0) {
    FUN_00974b40(pvVar3);
    operator_delete(pvVar3,0xa0);
  }
  free(*(void **)(unaff_RBX + 0x1020));
  pvVar3 = *(void **)(unaff_RBX + 0xfb8);
  if (pvVar3 != (void *)0x0) {
    splitvector_blocks_free((long)pvVar3 + 0x38);
    FUN_0096bd50(pvVar3);
    operator_delete(pvVar3,0x88);
  }
  FUN_0096bb02(in_stack_00000020);
  FUN_0096bb02(in_stack_00000018);
  FUN_0096bb02(in_stack_00000010);
  if (*(void **)(unaff_RBX + 0xef0) != (void *)0x0) {
    operator_delete(*(void **)(unaff_RBX + 0xef0),4);
  }
  if (*(void **)(unaff_RBX + 0xeb8) != (void *)0x0) {
    operator_delete(*(void **)(unaff_RBX + 0xeb8),0x40);
  }
  FUN_00950310();
  Window_metaObject(unaff_RBX + 0x20);
  Window_metaObject(unaff_RBX + 8);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=005135da name=FUN_005135da size=18 ====

void FUN_005135da(void)

{
  int iVar1;
  undefined8 *puVar2;
  void *pvVar3;
  long lVar4;
  int *piVar5;
  QArrayData *pQVar6;
  QArrayData *pQVar7;
  long unaff_RBX;
  void *unaff_RBP;
  undefined8 in_stack_00000010;
  undefined8 in_stack_00000018;
  undefined8 in_stack_00000020;
  
  operator_delete(unaff_RBP,0x20);
  puVar2 = *(undefined8 **)(unaff_RBX + 0x1140);
  if (puVar2 != (undefined8 *)0x0) {
    if ((void *)*puVar2 != (void *)0x0) {
      operator_delete((void *)*puVar2);
    }
    operator_delete(puVar2,0x18);
  }
  FUN_0096bb02();
  pvVar3 = *(void **)(unaff_RBX + 0x10d0);
  if (pvVar3 != (void *)0x0) {
    FUN_00a634ba(pvVar3);
    operator_delete(pvVar3,0x48);
  }
  pvVar3 = *(void **)(unaff_RBX + 0x10c8);
  if (pvVar3 != (void *)0x0) {
    FUN_00a164e8(pvVar3);
    operator_delete(pvVar3,0x58);
  }
  pvVar3 = *(void **)(unaff_RBX + 0x10c0);
  if (pvVar3 == (void *)0x0) goto LAB_005133fc;
  pQVar6 = *(QArrayData **)((long)pvVar3 + 8);
  if (*(int *)pQVar6 == 0) {
LAB_005133bf:
    lVar4 = *(long *)(pQVar6 + 0x10);
    iVar1 = *(int *)(pQVar6 + 4);
    for (pQVar7 = pQVar6 + lVar4; pQVar6 + (long)iVar1 * 0x28 + lVar4 != pQVar7;
        pQVar7 = pQVar7 + 0x28) {
      piVar5 = *(int **)pQVar7;
      if (*piVar5 == 0) {
LAB_0051358c:
        QArrayData::deallocate(*(QArrayData **)pQVar7,2,8);
      }
      else if (*piVar5 != -1) {
        LOCK();
        *piVar5 = *piVar5 + -1;
        UNLOCK();
        if (*piVar5 == 0) goto LAB_0051358c;
      }
    }
    QArrayData::deallocate(pQVar6,0x28,8);
  }
  else if (*(int *)pQVar6 != -1) {
    LOCK();
    *(int *)pQVar6 = *(int *)pQVar6 + -1;
    UNLOCK();
    if (*(int *)pQVar6 == 0) {
      pQVar6 = *(QArrayData **)((long)pvVar3 + 8);
      goto LAB_005133bf;
    }
  }
  operator_delete(pvVar3,0x30);
LAB_005133fc:
  pvVar3 = *(void **)(unaff_RBX + 0x10b8);
  if (pvVar3 != (void *)0x0) {
    FUN_00a5e8ba(pvVar3);
    operator_delete(pvVar3,0x18);
  }
  pvVar3 = *(void **)(unaff_RBX + 0x10b0);
  if (pvVar3 != (void *)0x0) {
    FUN_00a53b6c(pvVar3);
    operator_delete(pvVar3,0x30);
  }
  if (*(void **)(unaff_RBX + 0x10a8) != (void *)0x0) {
    operator_delete(*(void **)(unaff_RBX + 0x10a8),0x20);
  }
  pvVar3 = *(void **)(unaff_RBX + 0x10a0);
  if (pvVar3 != (void *)0x0) {
    FUN_0095a5fc(pvVar3);
    operator_delete(pvVar3,0x198);
  }
  if (*(_Sp_counted_base<(__gnu_cxx::_Lock_policy)2> **)(unaff_RBX + 0x1090) !=
      (_Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *)0x0) {
    std::_Sp_counted_base<(__gnu_cxx::_Lock_policy)2>::_M_release
              (*(_Sp_counted_base<(__gnu_cxx::_Lock_policy)2> **)(unaff_RBX + 0x1090));
  }
  FUN_0096bb02();
  pvVar3 = *(void **)(unaff_RBX + 0x1038);
  if (pvVar3 != (void *)0x0) {
    FUN_00974b40(pvVar3);
    operator_delete(pvVar3,0xa0);
  }
  free(*(void **)(unaff_RBX + 0x1020));
  pvVar3 = *(void **)(unaff_RBX + 0xfb8);
  if (pvVar3 != (void *)0x0) {
    splitvector_blocks_free((long)pvVar3 + 0x38);
    FUN_0096bd50(pvVar3);
    operator_delete(pvVar3,0x88);
  }
  FUN_0096bb02(in_stack_00000020);
  FUN_0096bb02(in_stack_00000018);
  FUN_0096bb02(in_stack_00000010);
  if (*(void **)(unaff_RBX + 0xef0) != (void *)0x0) {
    operator_delete(*(void **)(unaff_RBX + 0xef0),4);
  }
  if (*(void **)(unaff_RBX + 0xeb8) != (void *)0x0) {
    operator_delete(*(void **)(unaff_RBX + 0xeb8),0x40);
  }
  FUN_00950310();
  Window_metaObject(unaff_RBX + 0x20);
  Window_metaObject(unaff_RBX + 8);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=005135ec name=FUN_005135ec size=18 ====

void FUN_005135ec(void)

{
  int iVar1;
  undefined8 *puVar2;
  void *pvVar3;
  long lVar4;
  int *piVar5;
  QArrayData *pQVar6;
  QArrayData *pQVar7;
  long unaff_RBX;
  void *unaff_RBP;
  undefined8 in_stack_00000010;
  undefined8 in_stack_00000018;
  undefined8 in_stack_00000020;
  
  operator_delete(unaff_RBP,0x30);
  puVar2 = *(undefined8 **)(unaff_RBX + 0x1140);
  if (puVar2 != (undefined8 *)0x0) {
    if ((void *)*puVar2 != (void *)0x0) {
      operator_delete((void *)*puVar2);
    }
    operator_delete(puVar2,0x18);
  }
  FUN_0096bb02();
  pvVar3 = *(void **)(unaff_RBX + 0x10d0);
  if (pvVar3 != (void *)0x0) {
    FUN_00a634ba(pvVar3);
    operator_delete(pvVar3,0x48);
  }
  pvVar3 = *(void **)(unaff_RBX + 0x10c8);
  if (pvVar3 != (void *)0x0) {
    FUN_00a164e8(pvVar3);
    operator_delete(pvVar3,0x58);
  }
  pvVar3 = *(void **)(unaff_RBX + 0x10c0);
  if (pvVar3 == (void *)0x0) goto LAB_005133fc;
  pQVar6 = *(QArrayData **)((long)pvVar3 + 8);
  if (*(int *)pQVar6 == 0) {
LAB_005133bf:
    lVar4 = *(long *)(pQVar6 + 0x10);
    iVar1 = *(int *)(pQVar6 + 4);
    for (pQVar7 = pQVar6 + lVar4; pQVar6 + (long)iVar1 * 0x28 + lVar4 != pQVar7;
        pQVar7 = pQVar7 + 0x28) {
      piVar5 = *(int **)pQVar7;
      if (*piVar5 == 0) {
LAB_0051358c:
        QArrayData::deallocate(*(QArrayData **)pQVar7,2,8);
      }
      else if (*piVar5 != -1) {
        LOCK();
        *piVar5 = *piVar5 + -1;
        UNLOCK();
        if (*piVar5 == 0) goto LAB_0051358c;
      }
    }
    QArrayData::deallocate(pQVar6,0x28,8);
  }
  else if (*(int *)pQVar6 != -1) {
    LOCK();
    *(int *)pQVar6 = *(int *)pQVar6 + -1;
    UNLOCK();
    if (*(int *)pQVar6 == 0) {
      pQVar6 = *(QArrayData **)((long)pvVar3 + 8);
      goto LAB_005133bf;
    }
  }
  operator_delete(pvVar3,0x30);
LAB_005133fc:
  pvVar3 = *(void **)(unaff_RBX + 0x10b8);
  if (pvVar3 != (void *)0x0) {
    FUN_00a5e8ba(pvVar3);
    operator_delete(pvVar3,0x18);
  }
  pvVar3 = *(void **)(unaff_RBX + 0x10b0);
  if (pvVar3 != (void *)0x0) {
    FUN_00a53b6c(pvVar3);
    operator_delete(pvVar3,0x30);
  }
  if (*(void **)(unaff_RBX + 0x10a8) != (void *)0x0) {
    operator_delete(*(void **)(unaff_RBX + 0x10a8),0x20);
  }
  pvVar3 = *(void **)(unaff_RBX + 0x10a0);
  if (pvVar3 != (void *)0x0) {
    FUN_0095a5fc(pvVar3);
    operator_delete(pvVar3,0x198);
  }
  if (*(_Sp_counted_base<(__gnu_cxx::_Lock_policy)2> **)(unaff_RBX + 0x1090) !=
      (_Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *)0x0) {
    std::_Sp_counted_base<(__gnu_cxx::_Lock_policy)2>::_M_release
              (*(_Sp_counted_base<(__gnu_cxx::_Lock_policy)2> **)(unaff_RBX + 0x1090));
  }
  FUN_0096bb02();
  pvVar3 = *(void **)(unaff_RBX + 0x1038);
  if (pvVar3 != (void *)0x0) {
    FUN_00974b40(pvVar3);
    operator_delete(pvVar3,0xa0);
  }
  free(*(void **)(unaff_RBX + 0x1020));
  pvVar3 = *(void **)(unaff_RBX + 0xfb8);
  if (pvVar3 != (void *)0x0) {
    splitvector_blocks_free((long)pvVar3 + 0x38);
    FUN_0096bd50(pvVar3);
    operator_delete(pvVar3,0x88);
  }
  FUN_0096bb02(in_stack_00000020);
  FUN_0096bb02(in_stack_00000018);
  FUN_0096bb02(in_stack_00000010);
  if (*(void **)(unaff_RBX + 0xef0) != (void *)0x0) {
    operator_delete(*(void **)(unaff_RBX + 0xef0),4);
  }
  if (*(void **)(unaff_RBX + 0xeb8) != (void *)0x0) {
    operator_delete(*(void **)(unaff_RBX + 0xeb8),0x40);
  }
  FUN_00950310();
  Window_metaObject(unaff_RBX + 0x20);
  Window_metaObject(unaff_RBX + 8);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=005135fe name=FUN_005135fe size=50 ====

void FUN_005135fe(void)

{
  int iVar1;
  undefined8 *puVar2;
  void *pvVar3;
  long lVar4;
  int *piVar5;
  QArrayData *pQVar6;
  QArrayData *pQVar7;
  long unaff_RBX;
  void *unaff_RBP;
  undefined8 in_stack_00000010;
  undefined8 in_stack_00000018;
  undefined8 in_stack_00000020;
  
  operator_delete(unaff_RBP,0x48);
  puVar2 = *(undefined8 **)(unaff_RBX + 0x1140);
  if (puVar2 != (undefined8 *)0x0) {
    if ((void *)*puVar2 != (void *)0x0) {
      operator_delete((void *)*puVar2);
    }
    operator_delete(puVar2,0x18);
  }
  FUN_0096bb02();
  pvVar3 = *(void **)(unaff_RBX + 0x10d0);
  if (pvVar3 != (void *)0x0) {
    FUN_00a634ba(pvVar3);
    operator_delete(pvVar3,0x48);
  }
  pvVar3 = *(void **)(unaff_RBX + 0x10c8);
  if (pvVar3 != (void *)0x0) {
    FUN_00a164e8(pvVar3);
    operator_delete(pvVar3,0x58);
  }
  pvVar3 = *(void **)(unaff_RBX + 0x10c0);
  if (pvVar3 == (void *)0x0) goto LAB_005133fc;
  pQVar6 = *(QArrayData **)((long)pvVar3 + 8);
  if (*(int *)pQVar6 == 0) {
LAB_005133bf:
    lVar4 = *(long *)(pQVar6 + 0x10);
    iVar1 = *(int *)(pQVar6 + 4);
    for (pQVar7 = pQVar6 + lVar4; pQVar6 + (long)iVar1 * 0x28 + lVar4 != pQVar7;
        pQVar7 = pQVar7 + 0x28) {
      piVar5 = *(int **)pQVar7;
      if (*piVar5 == 0) {
LAB_0051358c:
        QArrayData::deallocate(*(QArrayData **)pQVar7,2,8);
      }
      else if (*piVar5 != -1) {
        LOCK();
        *piVar5 = *piVar5 + -1;
        UNLOCK();
        if (*piVar5 == 0) goto LAB_0051358c;
      }
    }
    QArrayData::deallocate(pQVar6,0x28,8);
  }
  else if (*(int *)pQVar6 != -1) {
    LOCK();
    *(int *)pQVar6 = *(int *)pQVar6 + -1;
    UNLOCK();
    if (*(int *)pQVar6 == 0) {
      pQVar6 = *(QArrayData **)((long)pvVar3 + 8);
      goto LAB_005133bf;
    }
  }
  operator_delete(pvVar3,0x30);
LAB_005133fc:
  pvVar3 = *(void **)(unaff_RBX + 0x10b8);
  if (pvVar3 != (void *)0x0) {
    FUN_00a5e8ba(pvVar3);
    operator_delete(pvVar3,0x18);
  }
  pvVar3 = *(void **)(unaff_RBX + 0x10b0);
  if (pvVar3 != (void *)0x0) {
    FUN_00a53b6c(pvVar3);
    operator_delete(pvVar3,0x30);
  }
  if (*(void **)(unaff_RBX + 0x10a8) != (void *)0x0) {
    operator_delete(*(void **)(unaff_RBX + 0x10a8),0x20);
  }
  pvVar3 = *(void **)(unaff_RBX + 0x10a0);
  if (pvVar3 != (void *)0x0) {
    FUN_0095a5fc(pvVar3);
    operator_delete(pvVar3,0x198);
  }
  if (*(_Sp_counted_base<(__gnu_cxx::_Lock_policy)2> **)(unaff_RBX + 0x1090) !=
      (_Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *)0x0) {
    std::_Sp_counted_base<(__gnu_cxx::_Lock_policy)2>::_M_release
              (*(_Sp_counted_base<(__gnu_cxx::_Lock_policy)2> **)(unaff_RBX + 0x1090));
  }
  FUN_0096bb02();
  pvVar3 = *(void **)(unaff_RBX + 0x1038);
  if (pvVar3 != (void *)0x0) {
    FUN_00974b40(pvVar3);
    operator_delete(pvVar3,0xa0);
  }
  free(*(void **)(unaff_RBX + 0x1020));
  pvVar3 = *(void **)(unaff_RBX + 0xfb8);
  if (pvVar3 != (void *)0x0) {
    splitvector_blocks_free((long)pvVar3 + 0x38);
    FUN_0096bd50(pvVar3);
    operator_delete(pvVar3,0x88);
  }
  FUN_0096bb02(in_stack_00000020);
  FUN_0096bb02(in_stack_00000018);
  FUN_0096bb02(in_stack_00000010);
  if (*(void **)(unaff_RBX + 0xef0) != (void *)0x0) {
    operator_delete(*(void **)(unaff_RBX + 0xef0),4);
  }
  if (*(void **)(unaff_RBX + 0xeb8) != (void *)0x0) {
    operator_delete(*(void **)(unaff_RBX + 0xeb8),0x40);
  }
  FUN_00950310();
  Window_metaObject(unaff_RBX + 0x20);
  Window_metaObject(unaff_RBX + 8);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00513630 name=FUN_00513630 size=18 ====

void FUN_00513630(void)

{
  int iVar1;
  undefined8 *puVar2;
  void *pvVar3;
  long lVar4;
  int *piVar5;
  QArrayData *pQVar6;
  QArrayData *pQVar7;
  long unaff_RBX;
  void *unaff_RBP;
  undefined8 in_stack_00000010;
  undefined8 in_stack_00000018;
  undefined8 in_stack_00000020;
  
  operator_delete(unaff_RBP,0x28);
  puVar2 = *(undefined8 **)(unaff_RBX + 0x1140);
  if (puVar2 != (undefined8 *)0x0) {
    if ((void *)*puVar2 != (void *)0x0) {
      operator_delete((void *)*puVar2);
    }
    operator_delete(puVar2,0x18);
  }
  FUN_0096bb02();
  pvVar3 = *(void **)(unaff_RBX + 0x10d0);
  if (pvVar3 != (void *)0x0) {
    FUN_00a634ba(pvVar3);
    operator_delete(pvVar3,0x48);
  }
  pvVar3 = *(void **)(unaff_RBX + 0x10c8);
  if (pvVar3 != (void *)0x0) {
    FUN_00a164e8(pvVar3);
    operator_delete(pvVar3,0x58);
  }
  pvVar3 = *(void **)(unaff_RBX + 0x10c0);
  if (pvVar3 == (void *)0x0) goto LAB_005133fc;
  pQVar6 = *(QArrayData **)((long)pvVar3 + 8);
  if (*(int *)pQVar6 == 0) {
LAB_005133bf:
    lVar4 = *(long *)(pQVar6 + 0x10);
    iVar1 = *(int *)(pQVar6 + 4);
    for (pQVar7 = pQVar6 + lVar4; pQVar6 + (long)iVar1 * 0x28 + lVar4 != pQVar7;
        pQVar7 = pQVar7 + 0x28) {
      piVar5 = *(int **)pQVar7;
      if (*piVar5 == 0) {
LAB_0051358c:
        QArrayData::deallocate(*(QArrayData **)pQVar7,2,8);
      }
      else if (*piVar5 != -1) {
        LOCK();
        *piVar5 = *piVar5 + -1;
        UNLOCK();
        if (*piVar5 == 0) goto LAB_0051358c;
      }
    }
    QArrayData::deallocate(pQVar6,0x28,8);
  }
  else if (*(int *)pQVar6 != -1) {
    LOCK();
    *(int *)pQVar6 = *(int *)pQVar6 + -1;
    UNLOCK();
    if (*(int *)pQVar6 == 0) {
      pQVar6 = *(QArrayData **)((long)pvVar3 + 8);
      goto LAB_005133bf;
    }
  }
  operator_delete(pvVar3,0x30);
LAB_005133fc:
  pvVar3 = *(void **)(unaff_RBX + 0x10b8);
  if (pvVar3 != (void *)0x0) {
    FUN_00a5e8ba(pvVar3);
    operator_delete(pvVar3,0x18);
  }
  pvVar3 = *(void **)(unaff_RBX + 0x10b0);
  if (pvVar3 != (void *)0x0) {
    FUN_00a53b6c(pvVar3);
    operator_delete(pvVar3,0x30);
  }
  if (*(void **)(unaff_RBX + 0x10a8) != (void *)0x0) {
    operator_delete(*(void **)(unaff_RBX + 0x10a8),0x20);
  }
  pvVar3 = *(void **)(unaff_RBX + 0x10a0);
  if (pvVar3 != (void *)0x0) {
    FUN_0095a5fc(pvVar3);
    operator_delete(pvVar3,0x198);
  }
  if (*(_Sp_counted_base<(__gnu_cxx::_Lock_policy)2> **)(unaff_RBX + 0x1090) !=
      (_Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *)0x0) {
    std::_Sp_counted_base<(__gnu_cxx::_Lock_policy)2>::_M_release
              (*(_Sp_counted_base<(__gnu_cxx::_Lock_policy)2> **)(unaff_RBX + 0x1090));
  }
  FUN_0096bb02();
  pvVar3 = *(void **)(unaff_RBX + 0x1038);
  if (pvVar3 != (void *)0x0) {
    FUN_00974b40(pvVar3);
    operator_delete(pvVar3,0xa0);
  }
  free(*(void **)(unaff_RBX + 0x1020));
  pvVar3 = *(void **)(unaff_RBX + 0xfb8);
  if (pvVar3 != (void *)0x0) {
    splitvector_blocks_free((long)pvVar3 + 0x38);
    FUN_0096bd50(pvVar3);
    operator_delete(pvVar3,0x88);
  }
  FUN_0096bb02(in_stack_00000020);
  FUN_0096bb02(in_stack_00000018);
  FUN_0096bb02(in_stack_00000010);
  if (*(void **)(unaff_RBX + 0xef0) != (void *)0x0) {
    operator_delete(*(void **)(unaff_RBX + 0xef0),4);
  }
  if (*(void **)(unaff_RBX + 0xeb8) != (void *)0x0) {
    operator_delete(*(void **)(unaff_RBX + 0xeb8),0x40);
  }
  FUN_00950310();
  Window_metaObject(unaff_RBX + 0x20);
  Window_metaObject(unaff_RBX + 8);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00513642 name=FUN_00513642 size=18 ====

void FUN_00513642(void)

{
  int iVar1;
  undefined8 *puVar2;
  void *pvVar3;
  long lVar4;
  int *piVar5;
  QArrayData *pQVar6;
  QArrayData *pQVar7;
  long unaff_RBX;
  void *unaff_RBP;
  undefined8 in_stack_00000010;
  undefined8 in_stack_00000018;
  undefined8 in_stack_00000020;
  
  operator_delete(unaff_RBP,0x58);
  puVar2 = *(undefined8 **)(unaff_RBX + 0x1140);
  if (puVar2 != (undefined8 *)0x0) {
    if ((void *)*puVar2 != (void *)0x0) {
      operator_delete((void *)*puVar2);
    }
    operator_delete(puVar2,0x18);
  }
  FUN_0096bb02();
  pvVar3 = *(void **)(unaff_RBX + 0x10d0);
  if (pvVar3 != (void *)0x0) {
    FUN_00a634ba(pvVar3);
    operator_delete(pvVar3,0x48);
  }
  pvVar3 = *(void **)(unaff_RBX + 0x10c8);
  if (pvVar3 != (void *)0x0) {
    FUN_00a164e8(pvVar3);
    operator_delete(pvVar3,0x58);
  }
  pvVar3 = *(void **)(unaff_RBX + 0x10c0);
  if (pvVar3 == (void *)0x0) goto LAB_005133fc;
  pQVar6 = *(QArrayData **)((long)pvVar3 + 8);
  if (*(int *)pQVar6 == 0) {
LAB_005133bf:
    lVar4 = *(long *)(pQVar6 + 0x10);
    iVar1 = *(int *)(pQVar6 + 4);
    for (pQVar7 = pQVar6 + lVar4; pQVar6 + (long)iVar1 * 0x28 + lVar4 != pQVar7;
        pQVar7 = pQVar7 + 0x28) {
      piVar5 = *(int **)pQVar7;
      if (*piVar5 == 0) {
LAB_0051358c:
        QArrayData::deallocate(*(QArrayData **)pQVar7,2,8);
      }
      else if (*piVar5 != -1) {
        LOCK();
        *piVar5 = *piVar5 + -1;
        UNLOCK();
        if (*piVar5 == 0) goto LAB_0051358c;
      }
    }
    QArrayData::deallocate(pQVar6,0x28,8);
  }
  else if (*(int *)pQVar6 != -1) {
    LOCK();
    *(int *)pQVar6 = *(int *)pQVar6 + -1;
    UNLOCK();
    if (*(int *)pQVar6 == 0) {
      pQVar6 = *(QArrayData **)((long)pvVar3 + 8);
      goto LAB_005133bf;
    }
  }
  operator_delete(pvVar3,0x30);
LAB_005133fc:
  pvVar3 = *(void **)(unaff_RBX + 0x10b8);
  if (pvVar3 != (void *)0x0) {
    FUN_00a5e8ba(pvVar3);
    operator_delete(pvVar3,0x18);
  }
  pvVar3 = *(void **)(unaff_RBX + 0x10b0);
  if (pvVar3 != (void *)0x0) {
    FUN_00a53b6c(pvVar3);
    operator_delete(pvVar3,0x30);
  }
  if (*(void **)(unaff_RBX + 0x10a8) != (void *)0x0) {
    operator_delete(*(void **)(unaff_RBX + 0x10a8),0x20);
  }
  pvVar3 = *(void **)(unaff_RBX + 0x10a0);
  if (pvVar3 != (void *)0x0) {
    FUN_0095a5fc(pvVar3);
    operator_delete(pvVar3,0x198);
  }
  if (*(_Sp_counted_base<(__gnu_cxx::_Lock_policy)2> **)(unaff_RBX + 0x1090) !=
      (_Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *)0x0) {
    std::_Sp_counted_base<(__gnu_cxx::_Lock_policy)2>::_M_release
              (*(_Sp_counted_base<(__gnu_cxx::_Lock_policy)2> **)(unaff_RBX + 0x1090));
  }
  FUN_0096bb02();
  pvVar3 = *(void **)(unaff_RBX + 0x1038);
  if (pvVar3 != (void *)0x0) {
    FUN_00974b40(pvVar3);
    operator_delete(pvVar3,0xa0);
  }
  free(*(void **)(unaff_RBX + 0x1020));
  pvVar3 = *(void **)(unaff_RBX + 0xfb8);
  if (pvVar3 != (void *)0x0) {
    splitvector_blocks_free((long)pvVar3 + 0x38);
    FUN_0096bd50(pvVar3);
    operator_delete(pvVar3,0x88);
  }
  FUN_0096bb02(in_stack_00000020);
  FUN_0096bb02(in_stack_00000018);
  FUN_0096bb02(in_stack_00000010);
  if (*(void **)(unaff_RBX + 0xef0) != (void *)0x0) {
    operator_delete(*(void **)(unaff_RBX + 0xef0),4);
  }
  if (*(void **)(unaff_RBX + 0xeb8) != (void *)0x0) {
    operator_delete(*(void **)(unaff_RBX + 0xeb8),0x40);
  }
  FUN_00950310();
  Window_metaObject(unaff_RBX + 0x20);
  Window_metaObject(unaff_RBX + 8);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00513654 name=FUN_00513654 size=18 ====

void FUN_00513654(void)

{
  int iVar1;
  undefined8 *puVar2;
  void *pvVar3;
  long lVar4;
  int *piVar5;
  QArrayData *pQVar6;
  QArrayData *pQVar7;
  long unaff_RBX;
  void *unaff_RBP;
  undefined8 in_stack_00000010;
  undefined8 in_stack_00000018;
  undefined8 in_stack_00000020;
  
  operator_delete(unaff_RBP,0x198);
  puVar2 = *(undefined8 **)(unaff_RBX + 0x1140);
  if (puVar2 != (undefined8 *)0x0) {
    if ((void *)*puVar2 != (void *)0x0) {
      operator_delete((void *)*puVar2);
    }
    operator_delete(puVar2,0x18);
  }
  FUN_0096bb02();
  pvVar3 = *(void **)(unaff_RBX + 0x10d0);
  if (pvVar3 != (void *)0x0) {
    FUN_00a634ba(pvVar3);
    operator_delete(pvVar3,0x48);
  }
  pvVar3 = *(void **)(unaff_RBX + 0x10c8);
  if (pvVar3 != (void *)0x0) {
    FUN_00a164e8(pvVar3);
    operator_delete(pvVar3,0x58);
  }
  pvVar3 = *(void **)(unaff_RBX + 0x10c0);
  if (pvVar3 == (void *)0x0) goto LAB_005133fc;
  pQVar6 = *(QArrayData **)((long)pvVar3 + 8);
  if (*(int *)pQVar6 == 0) {
LAB_005133bf:
    lVar4 = *(long *)(pQVar6 + 0x10);
    iVar1 = *(int *)(pQVar6 + 4);
    for (pQVar7 = pQVar6 + lVar4; pQVar6 + (long)iVar1 * 0x28 + lVar4 != pQVar7;
        pQVar7 = pQVar7 + 0x28) {
      piVar5 = *(int **)pQVar7;
      if (*piVar5 == 0) {
LAB_0051358c:
        QArrayData::deallocate(*(QArrayData **)pQVar7,2,8);
      }
      else if (*piVar5 != -1) {
        LOCK();
        *piVar5 = *piVar5 + -1;
        UNLOCK();
        if (*piVar5 == 0) goto LAB_0051358c;
      }
    }
    QArrayData::deallocate(pQVar6,0x28,8);
  }
  else if (*(int *)pQVar6 != -1) {
    LOCK();
    *(int *)pQVar6 = *(int *)pQVar6 + -1;
    UNLOCK();
    if (*(int *)pQVar6 == 0) {
      pQVar6 = *(QArrayData **)((long)pvVar3 + 8);
      goto LAB_005133bf;
    }
  }
  operator_delete(pvVar3,0x30);
LAB_005133fc:
  pvVar3 = *(void **)(unaff_RBX + 0x10b8);
  if (pvVar3 != (void *)0x0) {
    FUN_00a5e8ba(pvVar3);
    operator_delete(pvVar3,0x18);
  }
  pvVar3 = *(void **)(unaff_RBX + 0x10b0);
  if (pvVar3 != (void *)0x0) {
    FUN_00a53b6c(pvVar3);
    operator_delete(pvVar3,0x30);
  }
  if (*(void **)(unaff_RBX + 0x10a8) != (void *)0x0) {
    operator_delete(*(void **)(unaff_RBX + 0x10a8),0x20);
  }
  pvVar3 = *(void **)(unaff_RBX + 0x10a0);
  if (pvVar3 != (void *)0x0) {
    FUN_0095a5fc(pvVar3);
    operator_delete(pvVar3,0x198);
  }
  if (*(_Sp_counted_base<(__gnu_cxx::_Lock_policy)2> **)(unaff_RBX + 0x1090) !=
      (_Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *)0x0) {
    std::_Sp_counted_base<(__gnu_cxx::_Lock_policy)2>::_M_release
              (*(_Sp_counted_base<(__gnu_cxx::_Lock_policy)2> **)(unaff_RBX + 0x1090));
  }
  FUN_0096bb02();
  pvVar3 = *(void **)(unaff_RBX + 0x1038);
  if (pvVar3 != (void *)0x0) {
    FUN_00974b40(pvVar3);
    operator_delete(pvVar3,0xa0);
  }
  free(*(void **)(unaff_RBX + 0x1020));
  pvVar3 = *(void **)(unaff_RBX + 0xfb8);
  if (pvVar3 != (void *)0x0) {
    splitvector_blocks_free((long)pvVar3 + 0x38);
    FUN_0096bd50(pvVar3);
    operator_delete(pvVar3,0x88);
  }
  FUN_0096bb02(in_stack_00000020);
  FUN_0096bb02(in_stack_00000018);
  FUN_0096bb02(in_stack_00000010);
  if (*(void **)(unaff_RBX + 0xef0) != (void *)0x0) {
    operator_delete(*(void **)(unaff_RBX + 0xef0),4);
  }
  if (*(void **)(unaff_RBX + 0xeb8) != (void *)0x0) {
    operator_delete(*(void **)(unaff_RBX + 0xeb8),0x40);
  }
  FUN_00950310();
  Window_metaObject(unaff_RBX + 0x20);
  Window_metaObject(unaff_RBX + 8);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00513666 name=FUN_00513666 size=15 ====

void FUN_00513666(void)

{
  int iVar1;
  undefined8 *puVar2;
  void *pvVar3;
  long lVar4;
  int *piVar5;
  QArrayData *pQVar6;
  QArrayData *pQVar7;
  long unaff_RBX;
  void *unaff_RBP;
  undefined8 in_stack_00000010;
  undefined8 in_stack_00000018;
  undefined8 in_stack_00000020;
  
  operator_delete(unaff_RBP);
  puVar2 = *(undefined8 **)(unaff_RBX + 0x1140);
  if (puVar2 != (undefined8 *)0x0) {
    if ((void *)*puVar2 != (void *)0x0) {
      operator_delete((void *)*puVar2);
    }
    operator_delete(puVar2,0x18);
  }
  FUN_0096bb02();
  pvVar3 = *(void **)(unaff_RBX + 0x10d0);
  if (pvVar3 != (void *)0x0) {
    FUN_00a634ba(pvVar3);
    operator_delete(pvVar3,0x48);
  }
  pvVar3 = *(void **)(unaff_RBX + 0x10c8);
  if (pvVar3 != (void *)0x0) {
    FUN_00a164e8(pvVar3);
    operator_delete(pvVar3,0x58);
  }
  pvVar3 = *(void **)(unaff_RBX + 0x10c0);
  if (pvVar3 == (void *)0x0) goto LAB_005133fc;
  pQVar6 = *(QArrayData **)((long)pvVar3 + 8);
  if (*(int *)pQVar6 == 0) {
LAB_005133bf:
    lVar4 = *(long *)(pQVar6 + 0x10);
    iVar1 = *(int *)(pQVar6 + 4);
    for (pQVar7 = pQVar6 + lVar4; pQVar6 + (long)iVar1 * 0x28 + lVar4 != pQVar7;
        pQVar7 = pQVar7 + 0x28) {
      piVar5 = *(int **)pQVar7;
      if (*piVar5 == 0) {
LAB_0051358c:
        QArrayData::deallocate(*(QArrayData **)pQVar7,2,8);
      }
      else if (*piVar5 != -1) {
        LOCK();
        *piVar5 = *piVar5 + -1;
        UNLOCK();
        if (*piVar5 == 0) goto LAB_0051358c;
      }
    }
    QArrayData::deallocate(pQVar6,0x28,8);
  }
  else if (*(int *)pQVar6 != -1) {
    LOCK();
    *(int *)pQVar6 = *(int *)pQVar6 + -1;
    UNLOCK();
    if (*(int *)pQVar6 == 0) {
      pQVar6 = *(QArrayData **)((long)pvVar3 + 8);
      goto LAB_005133bf;
    }
  }
  operator_delete(pvVar3,0x30);
LAB_005133fc:
  pvVar3 = *(void **)(unaff_RBX + 0x10b8);
  if (pvVar3 != (void *)0x0) {
    FUN_00a5e8ba(pvVar3);
    operator_delete(pvVar3,0x18);
  }
  pvVar3 = *(void **)(unaff_RBX + 0x10b0);
  if (pvVar3 != (void *)0x0) {
    FUN_00a53b6c(pvVar3);
    operator_delete(pvVar3,0x30);
  }
  if (*(void **)(unaff_RBX + 0x10a8) != (void *)0x0) {
    operator_delete(*(void **)(unaff_RBX + 0x10a8),0x20);
  }
  pvVar3 = *(void **)(unaff_RBX + 0x10a0);
  if (pvVar3 != (void *)0x0) {
    FUN_0095a5fc(pvVar3);
    operator_delete(pvVar3,0x198);
  }
  if (*(_Sp_counted_base<(__gnu_cxx::_Lock_policy)2> **)(unaff_RBX + 0x1090) !=
      (_Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *)0x0) {
    std::_Sp_counted_base<(__gnu_cxx::_Lock_policy)2>::_M_release
              (*(_Sp_counted_base<(__gnu_cxx::_Lock_policy)2> **)(unaff_RBX + 0x1090));
  }
  FUN_0096bb02();
  pvVar3 = *(void **)(unaff_RBX + 0x1038);
  if (pvVar3 != (void *)0x0) {
    FUN_00974b40(pvVar3);
    operator_delete(pvVar3,0xa0);
  }
  free(*(void **)(unaff_RBX + 0x1020));
  pvVar3 = *(void **)(unaff_RBX + 0xfb8);
  if (pvVar3 != (void *)0x0) {
    splitvector_blocks_free((long)pvVar3 + 0x38);
    FUN_0096bd50(pvVar3);
    operator_delete(pvVar3,0x88);
  }
  FUN_0096bb02(in_stack_00000020);
  FUN_0096bb02(in_stack_00000018);
  FUN_0096bb02(in_stack_00000010);
  if (*(void **)(unaff_RBX + 0xef0) != (void *)0x0) {
    operator_delete(*(void **)(unaff_RBX + 0xef0),4);
  }
  if (*(void **)(unaff_RBX + 0xeb8) != (void *)0x0) {
    operator_delete(*(void **)(unaff_RBX + 0xeb8),0x40);
  }
  FUN_00950310();
  Window_metaObject(unaff_RBX + 0x20);
  Window_metaObject(unaff_RBX + 8);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00513676 name=FUN_00513676 size=24 ====

void FUN_00513676(void)

{
  FUN_0096bb02();
  FUN_0096bb02();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0051368e name=FUN_0051368e size=42 ====

void FUN_0051368e(void)

{
  undefined8 in_stack_00000018;
  
  FUN_0096bb02();
  FUN_0096bb02();
  FUN_0096bb02();
  FUN_0096bb02(in_stack_00000018);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=005136b8 name=FUN_005136b8 size=21 ====

void FUN_005136b8(void)

{
  FUN_0096bb02();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=005136ce name=FUN_005136ce size=16 ====

void FUN_005136ce(void)

{
  FUN_0096bb02();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=005136de name=FUN_005136de size=41 ====

void FUN_005136de(void)

{
  undefined8 in_stack_00000008;
  void *in_stack_00000010;
  
  FUN_0096bb02();
  FUN_0096bb02(in_stack_00000008);
  if (in_stack_00000010 != (void *)0x0) {
    operator_delete(in_stack_00000010);
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00513708 name=FUN_00513708 size=23 ====

void FUN_00513708(void)

{
  undefined8 in_stack_00000010;
  undefined8 in_stack_00000050;
  
  if (in_stack_00000050._4_1_ != '\0') {
    FUN_0096bb02(in_stack_00000010);
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0051371f name=FUN_0051371f size=28 ====

void FUN_0051371f(void)

{
  undefined8 in_stack_00000010;
  undefined8 in_stack_00000028;
  
  FUN_0096bb02(in_stack_00000028);
  FUN_0096bb02(in_stack_00000010);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0051373b name=FUN_0051373b size=12 ====

void FUN_0051373b(void)

{
  char unaff_R15B;
  undefined8 in_stack_00000010;
  undefined8 in_stack_00000028;
  
  FUN_0096bb02(in_stack_00000028);
  if (unaff_R15B != '\0') {
    FUN_0096bb02(in_stack_00000010);
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00513747 name=FUN_00513747 size=28 ====

void FUN_00513747(void)

{
  undefined8 in_stack_00000038;
  undefined8 in_stack_00000048;
  
  FUN_0096bb02(in_stack_00000038);
  FUN_0096bb02(in_stack_00000048);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00513764 name=FUN_00513764 size=21 ====

void FUN_00513764(void)

{
  void *unaff_RBX;
  
  operator_delete(unaff_RBX,0x88);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0051377a name=FUN_0051377a size=46 ====

void FUN_0051377a(void)

{
  QVariant *unaff_RBP;
  QVariant *this;
  
  this = (QVariant *)&stack0x00000050;
  do {
    this = this + -0x10;
    QVariant::~QVariant(this);
  } while (this != unaff_RBP);
  qt_array_data_unref();
  qt_array_data_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=005137a8 name=FUN_005137a8 size=73 ====

void FUN_005137a8(void)

{
  locale *unaff_retaddr;
  locale *in_stack_00000028;
  undefined1 *in_stack_00000058;
  undefined1 *in_stack_00000060;
  
  std::locale::~locale(unaff_retaddr);
  std::locale::~locale(in_stack_00000028);
  if (in_stack_00000060 != &DAT_011c5338) {
    refcount_delete_offset10_c();
  }
  if (in_stack_00000058 != &DAT_011c5338) {
    refcount_delete_offset10_c();
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=005137f2 name=FUN_005137f2 size=16 ====

void FUN_005137f2(void)

{
  FUN_0096bb02();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00513802 name=FUN_00513802 size=524 ====

/* WARNING: Removing unreachable block (ram,0x005139fd) */
/* WARNING: Removing unreachable block (ram,0x00513a1d) */
/* WARNING: Removing unreachable block (ram,0x00513a2b) */

void FUN_00513802(void)

{
  undefined8 *puVar1;
  int *piVar2;
  int iVar3;
  undefined8 *puVar4;
  undefined8 *puVar5;
  long lVar6;
  undefined8 *puVar7;
  QArrayData *pQVar8;
  void *unaff_R12;
  undefined8 *puVar9;
  undefined8 unaff_retaddr;
  undefined8 *puStack0000000000000008;
  
  FUN_0096bb02(unaff_retaddr);
  puVar9 = *(undefined8 **)((long)unaff_R12 + 0x30);
  puStack0000000000000008 = *(undefined8 **)((long)unaff_R12 + 0x40);
  puVar7 = *(undefined8 **)((long)unaff_R12 + 0x48);
  puVar4 = *(undefined8 **)((long)unaff_R12 + 0x50);
  do {
    if (puVar4 == puVar9) {
      if (*(long *)((long)unaff_R12 + 0x20) != 0) {
        lVar6 = *(long *)((long)unaff_R12 + 0x68);
        for (puVar9 = *(undefined8 **)((long)unaff_R12 + 0x48); puVar9 < (undefined8 *)(lVar6 + 8U);
            puVar9 = puVar9 + 1) {
          operator_delete((void *)*puVar9);
        }
        operator_delete(*(void **)((long)unaff_R12 + 0x20));
      }
      if (*(undefined1 **)((long)unaff_R12 + 0x18) != &DAT_011c5338) {
        refcount_delete_offset10_c();
      }
      operator_delete(unaff_R12,0x70);
      FUN_00963b22();
                    /* WARNING: Subroutine does not return */
      cxa_throw_exception();
    }
    puVar5 = (undefined8 *)*puVar9;
    if (puVar5 != (undefined8 *)0x0) {
      puVar1 = (undefined8 *)(puVar5[6] + -0x18);
      if (puVar1 != &std::string::_Rep::_S_empty_rep_storage) {
        LOCK();
        piVar2 = (int *)(puVar5[6] + -8);
        iVar3 = *piVar2;
        *piVar2 = *piVar2 + -1;
        UNLOCK();
        if (iVar3 < 1) {
          operator_delete(puVar1);
        }
      }
      puVar1 = (undefined8 *)(puVar5[5] + -0x18);
      if (puVar1 != &std::string::_Rep::_S_empty_rep_storage) {
        LOCK();
        piVar2 = (int *)(puVar5[5] + -8);
        iVar3 = *piVar2;
        *piVar2 = *piVar2 + -1;
        UNLOCK();
        if (iVar3 < 1) {
          operator_delete(puVar1);
        }
      }
      puVar1 = (undefined8 *)(puVar5[4] + -0x18);
      if (puVar1 != &std::string::_Rep::_S_empty_rep_storage) {
        LOCK();
        piVar2 = (int *)(puVar5[4] + -8);
        iVar3 = *piVar2;
        *piVar2 = *piVar2 + -1;
        UNLOCK();
        if (iVar3 < 1) {
          operator_delete(puVar1);
        }
      }
      QVariant::~QVariant((QVariant *)(puVar5 + 2));
      pQVar8 = (QArrayData *)puVar5[1];
      if (*(int *)pQVar8 == 0) {
LAB_005138ec:
        QArrayData::deallocate(pQVar8,2,8);
      }
      else if (*(int *)pQVar8 != -1) {
        LOCK();
        *(int *)pQVar8 = *(int *)pQVar8 + -1;
        UNLOCK();
        if (*(int *)pQVar8 == 0) {
          pQVar8 = (QArrayData *)puVar5[1];
          goto LAB_005138ec;
        }
      }
      piVar2 = (int *)*puVar5;
      if (*piVar2 == 0) {
LAB_00513909:
        QArrayData::deallocate((QArrayData *)*puVar5,2,8);
      }
      else if (*piVar2 != -1) {
        LOCK();
        *piVar2 = *piVar2 + -1;
        UNLOCK();
        if (*piVar2 == 0) goto LAB_00513909;
      }
      operator_delete(puVar5,0x40);
    }
    puVar9 = puVar9 + 1;
    if (puStack0000000000000008 == puVar9) {
      puVar7 = puVar7 + 1;
      puVar9 = (undefined8 *)*puVar7;
      puStack0000000000000008 = puVar9 + 0x40;
    }
  } while( true );
}


// ==== entry=00513956 name=FUN_00513956 size=32 ====

void FUN_00513956(void)

{
  QVariant *unaff_RBP;
  QVariant *unaff_R12;
  
  QVariant::~QVariant(unaff_RBP);
  QVariant::~QVariant(unaff_R12);
  FUN_00963b22();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00513976 name=FUN_00513976 size=11 ====

void FUN_00513976(void)

{
  undefined8 unaff_retaddr;
  
  FUN_0096bb02(unaff_retaddr);
  FUN_00963b22();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00513a3a name=FUN_00513a3a size=54 ====

void FUN_00513a3a(void)

{
  QVariant *unaff_RBX;
  long unaff_R12;
  QVariant *unaff_R13;
  long in_stack_00000008;
  
  QVariant::~QVariant(unaff_R13);
  QVariant::~QVariant(unaff_RBX);
  if (in_stack_00000008 + -0x18 != unaff_R12) {
    refcount_delete_offset10_c();
  }
  FUN_00963b22();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00513a70 name=FUN_00513a70 size=58 ====

void FUN_00513a70(void)

{
  undefined8 in_RAX;
  undefined1 *unaff_RBX;
  undefined1 *puVar1;
  undefined8 uStack0000000000000008;
  
  puVar1 = &stack0x00000180;
  do {
    puVar1 = puVar1 + -0x10;
    uStack0000000000000008 = in_RAX;
    qt_byte_array_unref(puVar1);
    in_RAX = uStack0000000000000008;
  } while (puVar1 != unaff_RBX);
  __cxa_guard_abort(&DAT_011c2890);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception(uStack0000000000000008);
}


// ==== entry=00513aaa name=FUN_00513aaa size=16 ====

void FUN_00513aaa(void)

{
  qt_byte_array_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00513aba name=FUN_00513aba size=18 ====

void FUN_00513aba(void)

{
  void *in_stack_00000010;
  
  free(in_stack_00000010);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00513acc name=FUN_00513acc size=16 ====

void FUN_00513acc(void)

{
  random_device *unaff_RBP;
  
  std::random_device::_M_fini(unaff_RBP);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00513adc name=FUN_00513adc size=34 ====

void FUN_00513adc(void)

{
  undefined1 *in_stack_000013a0;
  
  if (in_stack_000013a0 != &DAT_011c5338) {
    refcount_delete_offset10_c();
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00513afe name=FUN_00513afe size=41 ====

void FUN_00513afe(void)

{
  undefined8 in_stack_00000008;
  undefined1 *in_stack_00000040;
  
  qt_array_data_unref(in_stack_00000008);
  if (in_stack_00000040 != &DAT_011c5338) {
    refcount_delete_offset10_c();
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00513b28 name=FUN_00513b28 size=16 ====

void FUN_00513b28(void)

{
  qt_array_data_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00513b38 name=FUN_00513b38 size=31 ====

void FUN_00513b38(void)

{
  undefined1 *in_stack_00000058;
  
  if (in_stack_00000058 != &DAT_011c5338) {
    refcount_delete_offset10_c();
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00513b58 name=FUN_00513b58 size=31 ====

void FUN_00513b58(void)

{
  undefined1 *in_stack_00000018;
  
  if (in_stack_00000018 != &DAT_011c5338) {
    refcount_delete_offset10_c();
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00513b78 name=FUN_00513b78 size=16 ====

void FUN_00513b78(void)

{
  qt_array_data_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00513b88 name=FUN_00513b88 size=16 ====

void FUN_00513b88(void)

{
  FUN_00a161d8();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00513b98 name=FUN_00513b98 size=16 ====

void FUN_00513b98(void)

{
  FUN_0096bb02();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00513ba8 name=FUN_00513ba8 size=32 ====

void FUN_00513ba8(void)

{
  FUN_0096bb02();
  FUN_0096bb02();
  FUN_00974856();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00513bc8 name=FUN_00513bc8 size=26 ====

void FUN_00513bc8(void)

{
  FUN_0096bd50();
  FUN_0096bb02();
  FUN_0096bb02();
  FUN_00974856();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00513be2 name=FUN_00513be2 size=36 ====

void FUN_00513be2(void)

{
  QDateTime *unaff_R13;
  undefined8 in_stack_00000008;
  
  qt_array_data_unref(in_stack_00000008);
  QDateTime::~QDateTime(unaff_R13);
  qt_byte_array_unref(&stack0x00000010);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00513c06 name=FUN_00513c06 size=10 ====

void FUN_00513c06(void)

{
  qt_array_data_unref();
  qt_byte_array_unref(&stack0x00000010);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00513c10 name=FUN_00513c10 size=58 ====

void FUN_00513c10(void)

{
  QVariant *unaff_RBX;
  QVariant *unaff_R14;
  undefined1 *in_stack_00000008;
  
  QVariant::~QVariant(unaff_RBX);
  QVariant::~QVariant(unaff_R14);
  if (in_stack_00000008 != &DAT_011c5338) {
    refcount_delete_offset10_c();
  }
  FUN_00963b22();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00513c4a name=FUN_00513c4a size=57 ====

void FUN_00513c4a(void)

{
  QVariant *unaff_RBP;
  QVariant *unaff_R12;
  undefined1 *in_stack_00000008;
  
  QVariant::~QVariant(unaff_R12);
  QVariant::~QVariant(unaff_RBP);
  if (in_stack_00000008 != &DAT_011c5338) {
    refcount_delete_offset10_c();
  }
  FUN_00963b22();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00513c84 name=FUN_00513c84 size=98 ====

void FUN_00513c84(void)

{
  undefined8 in_RAX;
  undefined8 unaff_retaddr;
  undefined8 in_stack_00000008;
  undefined8 in_stack_00000010;
  undefined8 uStack0000000000000018;
  
  uStack0000000000000018 = in_RAX;
  qt_array_data_unref();
  qt_array_data_unref();
  qt_array_data_unref();
  qt_array_data_unref();
  qt_array_data_unref();
  qt_array_data_unref(in_stack_00000010);
  qt_array_data_unref(in_stack_00000008);
  qt_array_data_unref(unaff_retaddr);
  qt_array_data_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception(uStack0000000000000018);
}


// ==== entry=00513ce6 name=FUN_00513ce6 size=31 ====

void FUN_00513ce6(void)

{
  undefined1 *in_stack_00000060;
  
  if (in_stack_00000060 != &DAT_011c5338) {
    refcount_delete_offset10_c();
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00513d05 name=FUN_00513d05 size=16 ====

void FUN_00513d05(void)

{
  qt_byte_array_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00513d16 name=FUN_00513d16 size=62 ====

void FUN_00513d16(void)

{
  code *in_stack_00000030;
  code *in_stack_00000050;
  
  if (in_stack_00000030 != (code *)0x0) {
    (*in_stack_00000030)();
  }
  if (in_stack_00000050 != (code *)0x0) {
    (*in_stack_00000050)();
  }
  qt_byte_array_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00513d54 name=FUN_00513d54 size=46 ====

void FUN_00513d54(void)

{
  undefined1 *in_stack_00000040;
  
  if (in_stack_00000040 != &DAT_011c5338) {
    refcount_delete_offset10_c();
  }
  qt_byte_array_unref();
  stdfunction_state_destroy();
  qt_byte_array_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00513d82 name=FUN_00513d82 size=99 ====

void FUN_00513d82(void)

{
  long unaff_RBP;
  QVariant *unaff_R14;
  undefined8 in_stack_00000018;
  _Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *in_stack_00000048;
  _Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *in_stack_00000058;
  
  QVariant::~QVariant(unaff_R14);
  qmap_freetree_variant_nodes();
  QVariant::~QVariant((QVariant *)(unaff_RBP + 0x20));
  qt_array_data_unref(unaff_RBP + 0x18);
  QVariant::~QVariant((QVariant *)(unaff_RBP + 8));
  qt_array_data_unref();
  if (in_stack_00000058 != (_Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *)0x0) {
    std::_Sp_counted_base<(__gnu_cxx::_Lock_policy)2>::_M_release(in_stack_00000058);
  }
  if (in_stack_00000048 != (_Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *)0x0) {
    std::_Sp_counted_base<(__gnu_cxx::_Lock_policy)2>::_M_release(in_stack_00000048);
  }
  qatomic_unref_call_deleter(in_stack_00000018);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00513de5 name=FUN_00513de5 size=56 ====

void FUN_00513de5(void)

{
  long unaff_RBX;
  QVariant *unaff_R13;
  undefined8 in_stack_00000018;
  _Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *in_stack_00000048;
  _Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *in_stack_00000058;
  
  QVariant::~QVariant(unaff_R13);
  qmap_freetree_variant_nodes();
  QVariant::~QVariant((QVariant *)(unaff_RBX + 0x20));
  qt_array_data_unref(unaff_RBX + 0x18);
  QVariant::~QVariant((QVariant *)(unaff_RBX + 8));
  qt_array_data_unref();
  if (in_stack_00000058 != (_Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *)0x0) {
    std::_Sp_counted_base<(__gnu_cxx::_Lock_policy)2>::_M_release(in_stack_00000058);
  }
  if (in_stack_00000048 != (_Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *)0x0) {
    std::_Sp_counted_base<(__gnu_cxx::_Lock_policy)2>::_M_release(in_stack_00000048);
  }
  qatomic_unref_call_deleter(in_stack_00000018);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00513e1d name=FUN_00513e1d size=14 ====

void FUN_00513e1d(void)

{
  long unaff_RBX;
  undefined8 in_stack_00000018;
  _Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *in_stack_00000048;
  _Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *in_stack_00000058;
  
  qt_array_data_unref(unaff_RBX + 0x18);
  if (in_stack_00000058 != (_Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *)0x0) {
    std::_Sp_counted_base<(__gnu_cxx::_Lock_policy)2>::_M_release(in_stack_00000058);
  }
  if (in_stack_00000048 != (_Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *)0x0) {
    std::_Sp_counted_base<(__gnu_cxx::_Lock_policy)2>::_M_release(in_stack_00000048);
  }
  qatomic_unref_call_deleter(in_stack_00000018);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00513e2b name=FUN_00513e2b size=16 ====

void FUN_00513e2b(void)

{
  undefined8 in_stack_00000018;
  _Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *in_stack_00000048;
  _Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *in_stack_00000058;
  
  qt_array_data_unref();
  if (in_stack_00000058 != (_Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *)0x0) {
    std::_Sp_counted_base<(__gnu_cxx::_Lock_policy)2>::_M_release(in_stack_00000058);
  }
  if (in_stack_00000048 != (_Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *)0x0) {
    std::_Sp_counted_base<(__gnu_cxx::_Lock_policy)2>::_M_release(in_stack_00000048);
  }
  qatomic_unref_call_deleter(in_stack_00000018);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00513e3b name=FUN_00513e3b size=14 ====

void FUN_00513e3b(void)

{
  long unaff_RBP;
  undefined8 in_stack_00000018;
  _Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *in_stack_00000048;
  _Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *in_stack_00000058;
  
  qt_array_data_unref(unaff_RBP + 0x18);
  if (in_stack_00000058 != (_Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *)0x0) {
    std::_Sp_counted_base<(__gnu_cxx::_Lock_policy)2>::_M_release(in_stack_00000058);
  }
  if (in_stack_00000048 != (_Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *)0x0) {
    std::_Sp_counted_base<(__gnu_cxx::_Lock_policy)2>::_M_release(in_stack_00000048);
  }
  qatomic_unref_call_deleter(in_stack_00000018);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00513e4a name=FUN_00513e4a size=16 ====

void FUN_00513e4a(void)

{
  sharedptr_release();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00513e5a name=FUN_00513e5a size=25 ====

void FUN_00513e5a(void)

{
  long in_stack_00000008;
  
  if (in_stack_00000008 != 0) {
    sharedptr_release();
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00513e74 name=FUN_00513e74 size=18 ====

void FUN_00513e74(void)

{
  undefined8 in_stack_00000058;
  
  FUN_0096bb02(in_stack_00000058);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00513e86 name=FUN_00513e86 size=58 ====

/* WARNING: Removing unreachable block (ram,0x00513f06) */
/* WARNING: Removing unreachable block (ram,0x00513ee4) */
/* WARNING: Removing unreachable block (ram,0x00513f28) */

void FUN_00513e86(void)

{
  undefined8 in_stack_00000008;
  undefined8 in_stack_00000088;
  _Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *in_stack_00000098;
  _Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *in_stack_000000a8;
  
  FUN_0096bd50(in_stack_00000008);
  FUN_0096bb02();
  FUN_0096bb02();
  splitvector_blocks_free(in_stack_00000088);
  if (in_stack_000000a8 != (_Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *)0x0) {
    std::_Sp_counted_base<(__gnu_cxx::_Lock_policy)2>::_M_release(in_stack_000000a8);
  }
  if (in_stack_00000098 != (_Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *)0x0) {
    std::_Sp_counted_base<(__gnu_cxx::_Lock_policy)2>::_M_release(in_stack_00000098);
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00513ec0 name=FUN_00513ec0 size=174 ====

void FUN_00513ec0(void)

{
  void *in_stack_00000038;
  void *in_stack_00000048;
  void *in_stack_00000050;
  void *in_stack_00000060;
  undefined8 in_stack_00000088;
  _Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *in_stack_00000098;
  _Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *in_stack_000000a8;
  
  operator_delete(in_stack_00000060,0x18);
  splitvector_blocks_free(in_stack_00000088);
  if (in_stack_00000038 != (void *)0x0) {
    FUN_00974856(in_stack_00000038);
    operator_delete(in_stack_00000038,0x18);
  }
  if (in_stack_00000048 != (void *)0x0) {
    FUN_00963b22(in_stack_00000048);
    operator_delete(in_stack_00000048,0x10);
  }
  if (in_stack_00000050 != (void *)0x0) {
    FUN_00a161d8(in_stack_00000050);
    operator_delete(in_stack_00000050,0x18);
  }
  if (in_stack_000000a8 != (_Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *)0x0) {
    std::_Sp_counted_base<(__gnu_cxx::_Lock_policy)2>::_M_release(in_stack_000000a8);
  }
  if (in_stack_00000098 != (_Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *)0x0) {
    std::_Sp_counted_base<(__gnu_cxx::_Lock_policy)2>::_M_release(in_stack_00000098);
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00513f6e name=FUN_00513f6e size=25 ====

void FUN_00513f6e(void)

{
  undefined8 in_stack_00000008;
  void *in_stack_00000038;
  undefined8 in_stack_00000040;
  void *in_stack_00000048;
  void *in_stack_00000050;
  undefined8 in_stack_00000088;
  _Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *in_stack_00000098;
  _Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *in_stack_000000a8;
  
  FUN_0096bb02(in_stack_00000040);
  FUN_0096bb02(in_stack_00000008);
  splitvector_blocks_free(in_stack_00000088);
  if (in_stack_00000038 != (void *)0x0) {
    FUN_00974856(in_stack_00000038);
    operator_delete(in_stack_00000038,0x18);
  }
  if (in_stack_00000048 != (void *)0x0) {
    FUN_00963b22(in_stack_00000048);
    operator_delete(in_stack_00000048,0x10);
  }
  if (in_stack_00000050 != (void *)0x0) {
    FUN_00a161d8(in_stack_00000050);
    operator_delete(in_stack_00000050,0x18);
  }
  if (in_stack_000000a8 != (_Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *)0x0) {
    std::_Sp_counted_base<(__gnu_cxx::_Lock_policy)2>::_M_release(in_stack_000000a8);
  }
  if (in_stack_00000098 != (_Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *)0x0) {
    std::_Sp_counted_base<(__gnu_cxx::_Lock_policy)2>::_M_release(in_stack_00000098);
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00513f87 name=FUN_00513f87 size=18 ====

void FUN_00513f87(void)

{
  void *unaff_R13;
  void *in_stack_00000038;
  void *in_stack_00000048;
  void *in_stack_00000050;
  undefined8 in_stack_00000088;
  _Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *in_stack_00000098;
  _Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *in_stack_000000a8;
  
  operator_delete(unaff_R13,0x10);
  splitvector_blocks_free(in_stack_00000088);
  if (in_stack_00000038 != (void *)0x0) {
    FUN_00974856(in_stack_00000038);
    operator_delete(in_stack_00000038,0x18);
  }
  if (in_stack_00000048 != (void *)0x0) {
    FUN_00963b22(in_stack_00000048);
    operator_delete(in_stack_00000048,0x10);
  }
  if (in_stack_00000050 != (void *)0x0) {
    FUN_00a161d8(in_stack_00000050);
    operator_delete(in_stack_00000050,0x18);
  }
  if (in_stack_000000a8 != (_Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *)0x0) {
    std::_Sp_counted_base<(__gnu_cxx::_Lock_policy)2>::_M_release(in_stack_000000a8);
  }
  if (in_stack_00000098 != (_Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *)0x0) {
    std::_Sp_counted_base<(__gnu_cxx::_Lock_policy)2>::_M_release(in_stack_00000098);
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00513f99 name=FUN_00513f99 size=18 ====

void FUN_00513f99(void)

{
  void *unaff_R13;
  void *in_stack_00000038;
  void *in_stack_00000048;
  void *in_stack_00000050;
  undefined8 in_stack_00000088;
  _Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *in_stack_00000098;
  _Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *in_stack_000000a8;
  
  operator_delete(unaff_R13,0x18);
  splitvector_blocks_free(in_stack_00000088);
  if (in_stack_00000038 != (void *)0x0) {
    FUN_00974856(in_stack_00000038);
    operator_delete(in_stack_00000038,0x18);
  }
  if (in_stack_00000048 != (void *)0x0) {
    FUN_00963b22(in_stack_00000048);
    operator_delete(in_stack_00000048,0x10);
  }
  if (in_stack_00000050 != (void *)0x0) {
    FUN_00a161d8(in_stack_00000050);
    operator_delete(in_stack_00000050,0x18);
  }
  if (in_stack_000000a8 != (_Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *)0x0) {
    std::_Sp_counted_base<(__gnu_cxx::_Lock_policy)2>::_M_release(in_stack_000000a8);
  }
  if (in_stack_00000098 != (_Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *)0x0) {
    std::_Sp_counted_base<(__gnu_cxx::_Lock_policy)2>::_M_release(in_stack_00000098);
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00513fab name=FUN_00513fab size=15 ====

void FUN_00513fab(void)

{
  undefined8 in_stack_00000008;
  void *in_stack_00000038;
  void *in_stack_00000048;
  void *in_stack_00000050;
  undefined8 in_stack_00000088;
  _Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *in_stack_00000098;
  _Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *in_stack_000000a8;
  
  qt_byte_array_unref(in_stack_00000008);
  splitvector_blocks_free(in_stack_00000088);
  if (in_stack_00000038 != (void *)0x0) {
    FUN_00974856(in_stack_00000038);
    operator_delete(in_stack_00000038,0x18);
  }
  if (in_stack_00000048 != (void *)0x0) {
    FUN_00963b22(in_stack_00000048);
    operator_delete(in_stack_00000048,0x10);
  }
  if (in_stack_00000050 != (void *)0x0) {
    FUN_00a161d8(in_stack_00000050);
    operator_delete(in_stack_00000050,0x18);
  }
  if (in_stack_000000a8 != (_Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *)0x0) {
    std::_Sp_counted_base<(__gnu_cxx::_Lock_policy)2>::_M_release(in_stack_000000a8);
  }
  if (in_stack_00000098 != (_Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *)0x0) {
    std::_Sp_counted_base<(__gnu_cxx::_Lock_policy)2>::_M_release(in_stack_00000098);
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00513fba name=FUN_00513fba size=48 ====

void FUN_00513fba(void)

{
  void *pvVar1;
  void *pvStack0000000000000038;
  void *pvStack0000000000000048;
  void *pvStack0000000000000050;
  undefined1 *puStack0000000000000088;
  _Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *in_stack_00000098;
  _Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *in_stack_000000a8;
  
  pvStack0000000000000038 = (void *)0x0;
  pvStack0000000000000048 = (void *)0x0;
  pvStack0000000000000050 = (void *)0x0;
  puStack0000000000000088 = &stack0x00000170;
  splitvector_blocks_free(puStack0000000000000088);
  pvVar1 = pvStack0000000000000038;
  if (pvStack0000000000000038 != (void *)0x0) {
    FUN_00974856(pvStack0000000000000038);
    operator_delete(pvVar1,0x18);
  }
  pvVar1 = pvStack0000000000000048;
  if (pvStack0000000000000048 != (void *)0x0) {
    FUN_00963b22(pvStack0000000000000048);
    operator_delete(pvVar1,0x10);
  }
  pvVar1 = pvStack0000000000000050;
  if (pvStack0000000000000050 != (void *)0x0) {
    FUN_00a161d8(pvStack0000000000000050);
    operator_delete(pvVar1,0x18);
  }
  if (in_stack_000000a8 != (_Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *)0x0) {
    std::_Sp_counted_base<(__gnu_cxx::_Lock_policy)2>::_M_release(in_stack_000000a8);
  }
  if (in_stack_00000098 != (_Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *)0x0) {
    std::_Sp_counted_base<(__gnu_cxx::_Lock_policy)2>::_M_release(in_stack_00000098);
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00513fea name=FUN_00513fea size=12 ====

void FUN_00513fea(void)

{
  undefined8 in_stack_00000008;
  void *in_stack_00000038;
  undefined8 in_stack_00000040;
  void *in_stack_00000048;
  void *in_stack_00000050;
  undefined8 in_stack_00000088;
  _Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *in_stack_00000098;
  _Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *in_stack_000000a8;
  
  FUN_0096bb02(in_stack_00000040);
  FUN_0096bb02(in_stack_00000008);
  splitvector_blocks_free(in_stack_00000088);
  if (in_stack_00000038 != (void *)0x0) {
    FUN_00974856(in_stack_00000038);
    operator_delete(in_stack_00000038,0x18);
  }
  if (in_stack_00000048 != (void *)0x0) {
    FUN_00963b22(in_stack_00000048);
    operator_delete(in_stack_00000048,0x10);
  }
  if (in_stack_00000050 != (void *)0x0) {
    FUN_00a161d8(in_stack_00000050);
    operator_delete(in_stack_00000050,0x18);
  }
  if (in_stack_000000a8 != (_Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *)0x0) {
    std::_Sp_counted_base<(__gnu_cxx::_Lock_policy)2>::_M_release(in_stack_000000a8);
  }
  if (in_stack_00000098 != (_Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *)0x0) {
    std::_Sp_counted_base<(__gnu_cxx::_Lock_policy)2>::_M_release(in_stack_00000098);
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00513ff6 name=FUN_00513ff6 size=27 ====

/* WARNING: Removing unreachable block (ram,0x00513f06) */
/* WARNING: Removing unreachable block (ram,0x00513ee4) */
/* WARNING: Removing unreachable block (ram,0x00513f28) */

void FUN_00513ff6(void)

{
  undefined8 in_stack_00000088;
  _Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *in_stack_00000098;
  _Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *in_stack_000000a8;
  _Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *in_stack_00000138;
  
  if (in_stack_00000138 != (_Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *)0x0) {
    std::_Sp_counted_base<(__gnu_cxx::_Lock_policy)2>::_M_release(in_stack_00000138);
  }
  splitvector_blocks_free(in_stack_00000088);
  if (in_stack_000000a8 != (_Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *)0x0) {
    std::_Sp_counted_base<(__gnu_cxx::_Lock_policy)2>::_M_release(in_stack_000000a8);
  }
  if (in_stack_00000098 != (_Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *)0x0) {
    std::_Sp_counted_base<(__gnu_cxx::_Lock_policy)2>::_M_release(in_stack_00000098);
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00514012 name=FUN_00514012 size=29 ====

void FUN_00514012(void)

{
  undefined8 in_stack_00000018;
  void *in_stack_00000040;
  _Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *in_stack_00000068;
  _Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *in_stack_00000078;
  
  FUN_0096bd50();
  FUN_0096bb02();
  FUN_0096bb02();
  splitvector_blocks_free(in_stack_00000018);
  if (in_stack_00000040 != (void *)0x0) {
    FUN_009cff96(in_stack_00000040);
    operator_delete(in_stack_00000040,0x10);
  }
  if (in_stack_00000078 != (_Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *)0x0) {
    std::_Sp_counted_base<(__gnu_cxx::_Lock_policy)2>::_M_release(in_stack_00000078);
  }
  if (in_stack_00000068 != (_Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *)0x0) {
    std::_Sp_counted_base<(__gnu_cxx::_Lock_policy)2>::_M_release(in_stack_00000068);
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0051402f name=FUN_0051402f size=103 ====

void FUN_0051402f(void)

{
  void *unaff_R12;
  undefined8 in_stack_00000018;
  void *in_stack_00000040;
  _Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *in_stack_00000068;
  _Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *in_stack_00000078;
  
  operator_delete(unaff_R12,0x88);
  FUN_0096bd50();
  splitvector_blocks_free(in_stack_00000018);
  if (in_stack_00000040 != (void *)0x0) {
    FUN_009cff96(in_stack_00000040);
    operator_delete(in_stack_00000040,0x10);
  }
  if (in_stack_00000078 != (_Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *)0x0) {
    std::_Sp_counted_base<(__gnu_cxx::_Lock_policy)2>::_M_release(in_stack_00000078);
  }
  if (in_stack_00000068 != (_Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *)0x0) {
    std::_Sp_counted_base<(__gnu_cxx::_Lock_policy)2>::_M_release(in_stack_00000068);
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00514096 name=FUN_00514096 size=10 ====

void FUN_00514096(void)

{
  undefined8 in_stack_00000018;
  void *in_stack_00000040;
  _Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *in_stack_00000068;
  _Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *in_stack_00000078;
  
  qt_byte_array_unref();
  splitvector_blocks_free(in_stack_00000018);
  if (in_stack_00000040 != (void *)0x0) {
    FUN_009cff96(in_stack_00000040);
    operator_delete(in_stack_00000040,0x10);
  }
  if (in_stack_00000078 != (_Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *)0x0) {
    std::_Sp_counted_base<(__gnu_cxx::_Lock_policy)2>::_M_release(in_stack_00000078);
  }
  if (in_stack_00000068 != (_Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *)0x0) {
    std::_Sp_counted_base<(__gnu_cxx::_Lock_policy)2>::_M_release(in_stack_00000068);
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=005140a0 name=FUN_005140a0 size=19 ====

void FUN_005140a0(void)

{
  char unaff_BL;
  undefined8 in_stack_00000018;
  void *in_stack_00000040;
  _Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *in_stack_00000068;
  _Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *in_stack_00000078;
  
  if (unaff_BL != '\0') {
    FUN_0096bb02(&stack0x000000a0);
  }
  FUN_0096bd50();
  splitvector_blocks_free(in_stack_00000018);
  if (in_stack_00000040 != (void *)0x0) {
    FUN_009cff96(in_stack_00000040);
    operator_delete(in_stack_00000040,0x10);
  }
  if (in_stack_00000078 != (_Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *)0x0) {
    std::_Sp_counted_base<(__gnu_cxx::_Lock_policy)2>::_M_release(in_stack_00000078);
  }
  if (in_stack_00000068 != (_Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *)0x0) {
    std::_Sp_counted_base<(__gnu_cxx::_Lock_policy)2>::_M_release(in_stack_00000068);
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=005140b3 name=FUN_005140b3 size=18 ====

void FUN_005140b3(void)

{
  undefined8 in_stack_00000018;
  void *in_stack_00000040;
  _Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *in_stack_00000068;
  _Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *in_stack_00000078;
  
  FUN_0096bb02();
  FUN_0096bd50();
  splitvector_blocks_free(in_stack_00000018);
  if (in_stack_00000040 != (void *)0x0) {
    FUN_009cff96(in_stack_00000040);
    operator_delete(in_stack_00000040,0x10);
  }
  if (in_stack_00000078 != (_Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *)0x0) {
    std::_Sp_counted_base<(__gnu_cxx::_Lock_policy)2>::_M_release(in_stack_00000078);
  }
  if (in_stack_00000068 != (_Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *)0x0) {
    std::_Sp_counted_base<(__gnu_cxx::_Lock_policy)2>::_M_release(in_stack_00000068);
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=005140c5 name=FUN_005140c5 size=13 ====

void FUN_005140c5(void)

{
  undefined8 in_stack_00000018;
  void *in_stack_00000040;
  _Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *in_stack_00000068;
  _Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *in_stack_00000078;
  
  FUN_0096bb02();
  splitvector_blocks_free(in_stack_00000018);
  if (in_stack_00000040 != (void *)0x0) {
    FUN_009cff96(in_stack_00000040);
    operator_delete(in_stack_00000040,0x10);
  }
  if (in_stack_00000078 != (_Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *)0x0) {
    std::_Sp_counted_base<(__gnu_cxx::_Lock_policy)2>::_M_release(in_stack_00000078);
  }
  if (in_stack_00000068 != (_Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *)0x0) {
    std::_Sp_counted_base<(__gnu_cxx::_Lock_policy)2>::_M_release(in_stack_00000068);
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=005140d2 name=FUN_005140d2 size=17 ====

void FUN_005140d2(void)

{
  void *in_stack_00000040;
  _Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *in_stack_00000068;
  _Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *in_stack_00000078;
  
  operator_delete(in_stack_00000040,0x10);
  if (in_stack_00000078 != (_Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *)0x0) {
    std::_Sp_counted_base<(__gnu_cxx::_Lock_policy)2>::_M_release(in_stack_00000078);
  }
  if (in_stack_00000068 != (_Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *)0x0) {
    std::_Sp_counted_base<(__gnu_cxx::_Lock_policy)2>::_M_release(in_stack_00000068);
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=005140e4 name=FUN_005140e4 size=33 ====

int FUN_005140e4(undefined8 param_1,undefined8 param_2,long param_3)

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


// ==== entry=00514106 name=FUN_00514106 size=22 ====

void FUN_00514106(void)

{
                    /* WARNING: Subroutine does not return */
  __cxa_throw();
}


// ==== entry=0051411c name=FUN_0051411c size=16 ====

void FUN_0051411c(void)

{
  __cxa_free_exception();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0051412c name=FUN_0051412c size=11 ====

void FUN_0051412c(void)

{
  undefined1 *unaff_RBX;
  
  *unaff_RBX = 0;
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00514138 name=FUN_00514138 size=13 ====

void FUN_00514138(void)

{
  undefined1 *unaff_R12;
  
  *unaff_R12 = 0;
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00514145 name=FUN_00514145 size=16 ====

void FUN_00514145(void)

{
  __cxa_free_exception();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00514155 name=FUN_00514155 size=22 ====

void FUN_00514155(void)

{
                    /* WARNING: Subroutine does not return */
  __cxa_throw();
}


// ==== entry=0051416b name=FUN_0051416b size=10 ====

void FUN_0051416b(void)

{
  undefined1 *unaff_R13;
  
  *unaff_R13 = 0;
                    /* WARNING: Subroutine does not return */
  std::terminate();
}


// ==== entry=00514176 name=FUN_00514176 size=34 ====

void FUN_00514176(void)

{
  undefined8 in_stack_00000008;
  long *in_stack_00000028;
  
  if (in_stack_00000028 != (long *)0x0) {
    (**(code **)(*in_stack_00000028 + 8))();
  }
  FUN_00963b22(in_stack_00000008);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00514198 name=FUN_00514198 size=13 ====

void FUN_00514198(void)

{
  undefined8 in_stack_00000008;
  
  FUN_0096bd50();
  FUN_00963b22(in_stack_00000008);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=005141a6 name=FUN_005141a6 size=74 ====

void FUN_005141a6(void)

{
  undefined8 in_stack_00000008;
  undefined8 in_stack_00000018;
  
  FUN_0096bd50();
  FUN_0096bb02();
  FUN_0096bb02(in_stack_00000008);
  FUN_0096bd50();
  FUN_0096bb02();
  FUN_0096bb02();
  splitvector_blocks_free(in_stack_00000018);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=005141f0 name=FUN_005141f0 size=58 ====

void FUN_005141f0(void)

{
  undefined8 in_stack_00000008;
  undefined8 in_stack_00000018;
  
  FUN_0096bd50();
  FUN_0096bb02();
  FUN_0096bb02(in_stack_00000008);
  FUN_0096bd50();
  FUN_0096bb02();
  FUN_0096bb02();
  splitvector_blocks_free(in_stack_00000018);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0051422a name=FUN_0051422a size=60 ====

void FUN_0051422a(void)

{
  undefined8 in_stack_00000008;
  undefined8 in_stack_00000018;
  
  FUN_0096bd50();
  FUN_0096bb02(in_stack_00000008);
  FUN_0096bb02();
  FUN_0096bd50(in_stack_00000018);
  FUN_0096bb02();
  FUN_0096bb02();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00514266 name=FUN_00514266 size=60 ====

void FUN_00514266(void)

{
  undefined8 in_stack_00000008;
  undefined8 in_stack_00000018;
  
  FUN_0096bd50();
  FUN_0096bb02(in_stack_00000008);
  FUN_0096bb02();
  FUN_0096bd50(in_stack_00000018);
  FUN_0096bb02();
  FUN_0096bb02();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=005142a2 name=FUN_005142a2 size=24 ====

void FUN_005142a2(void)

{
  FUN_0096bd50();
  FUN_00963b22();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=005142ba name=FUN_005142ba size=18 ====

void FUN_005142ba(void)

{
  long *in_stack_00000018;
  
  if (in_stack_00000018 != (long *)0x0) {
    (**(code **)(*in_stack_00000018 + 8))();
  }
  FUN_00963b22();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=005142cc name=FUN_005142cc size=24 ====

void FUN_005142cc(void)

{
  long *in_stack_00000050;
  
  if (in_stack_00000050 != (long *)0x0) {
    (**(code **)(*in_stack_00000050 + 8))();
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=005142e4 name=FUN_005142e4 size=16 ====

void FUN_005142e4(void)

{
  FUN_0096bd50();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=005142f4 name=FUN_005142f4 size=18 ====

void FUN_005142f4(void)

{
  undefined8 in_stack_00000040;
  
  splitvector_blocks_free(in_stack_00000040);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00514306 name=FUN_00514306 size=16 ====

void FUN_00514306(void)

{
  qt_byte_array_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00514316 name=FUN_00514316 size=18 ====

void FUN_00514316(void)

{
  void *in_stack_00000010;
  
  free(in_stack_00000010);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00514328 name=FUN_00514328 size=26 ====

void FUN_00514328(void)

{
  void *in_stack_00000020;
  
  qt_byte_array_unref();
  free(in_stack_00000020);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00514342 name=FUN_00514342 size=68 ====

void FUN_00514342(void)

{
  undefined8 in_stack_00000020;
  undefined8 in_stack_00000028;
  undefined8 in_stack_00000030;
  undefined8 in_stack_00000058;
  undefined8 in_stack_00000060;
  undefined8 in_stack_00000070;
  
  FUN_0096bb02(in_stack_00000028);
  FUN_0096bb02(in_stack_00000070);
  FUN_00a4bb24(in_stack_00000020);
  FUN_00963b22(in_stack_00000060);
  splitvector_blocks_free(in_stack_00000030);
  FUN_00a2d524(in_stack_00000058);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00514386 name=FUN_00514386 size=25 ====

void FUN_00514386(void)

{
  undefined8 in_stack_00000020;
  undefined8 in_stack_00000058;
  undefined8 in_stack_00000060;
  
  FUN_0096bd50(in_stack_00000020);
  FUN_00963b22(in_stack_00000060);
  splitvector_blocks_free(&stack0x00000180);
  FUN_00a2d524(in_stack_00000058);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0051439f name=FUN_0051439f size=13 ====

void FUN_0051439f(void)

{
  __cxa_begin_catch();
                    /* WARNING: Subroutine does not return */
                    /* try { // try from 005143a7 to 005143ab has its CatchHandler @ 005143d5 */
  __cxa_rethrow();
}


// ==== entry=005143ac name=FUN_005143ac size=41 ====

void FUN_005143ac(void)

{
  undefined8 in_stack_00000020;
  undefined8 in_stack_00000030;
  undefined8 in_stack_00000038;
  undefined8 in_stack_00000058;
  undefined8 in_stack_00000060;
  long *in_stack_00000100;
  
  FUN_0096bb02(in_stack_00000038);
  FUN_0096bb02(in_stack_00000020);
  if (in_stack_00000100 != (long *)0x0) {
    (**(code **)(*in_stack_00000100 + 8))();
  }
  FUN_00963b22(in_stack_00000060);
  splitvector_blocks_free(in_stack_00000030);
  FUN_00a2d524(in_stack_00000058);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00514429 name=FUN_00514429 size=25 ====

void FUN_00514429(void)

{
  undefined8 in_stack_00000020;
  undefined8 in_stack_00000028;
  undefined8 in_stack_00000030;
  undefined8 in_stack_00000058;
  undefined8 in_stack_00000060;
  undefined8 in_stack_00000068;
  
  FUN_0096bb02(in_stack_00000028);
  FUN_0096bb02(in_stack_00000068);
  FUN_00a4bb24(in_stack_00000020);
  FUN_00963b22(in_stack_00000060);
  splitvector_blocks_free(in_stack_00000030);
  FUN_00a2d524(in_stack_00000058);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00514442 name=FUN_00514442 size=25 ====

void FUN_00514442(void)

{
  undefined8 in_stack_00000020;
  undefined8 in_stack_00000030;
  undefined8 in_stack_00000048;
  undefined8 in_stack_00000058;
  undefined8 in_stack_00000060;
  long *in_stack_00000100;
  
  FUN_0096bb02(in_stack_00000020);
  FUN_0096bb02(in_stack_00000048);
  if (in_stack_00000100 != (long *)0x0) {
    (**(code **)(*in_stack_00000100 + 8))();
  }
  FUN_00963b22(in_stack_00000060);
  splitvector_blocks_free(in_stack_00000030);
  FUN_00a2d524(in_stack_00000058);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0051445b name=FUN_0051445b size=36 ====

void FUN_0051445b(void)

{
  undefined8 in_stack_00000010;
  undefined8 in_stack_00000020;
  undefined8 in_stack_00000058;
  undefined8 in_stack_00000060;
  
  qt_byte_array_unref(in_stack_00000010);
  FUN_0096bd50();
  FUN_00a4bb24(in_stack_00000020);
  FUN_00963b22(in_stack_00000060);
  splitvector_blocks_free(&stack0x00000180);
  FUN_00a2d524(in_stack_00000058);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00514480 name=FUN_00514480 size=26 ====

void FUN_00514480(void)

{
  undefined8 in_stack_00000008;
  
  FUN_0096bd50();
  FUN_00963b22(in_stack_00000008);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0051449a name=FUN_0051449a size=10 ====

void FUN_0051449a(void)

{
  undefined8 in_stack_00000008;
  
  FUN_0096bb02();
  FUN_00963b22(in_stack_00000008);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=005144a4 name=FUN_005144a4 size=14 ====

void FUN_005144a4(void)

{
  undefined8 in_stack_00000008;
  
  FUN_0096bb02();
  FUN_00963b22(in_stack_00000008);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=005144b2 name=FUN_005144b2 size=75 ====

void FUN_005144b2(void)

{
  char cVar1;
  undefined8 *unaff_R12;
  ulong in_stack_00000010;
  long *in_stack_00000028;
  
  if ((in_stack_00000010 != 0) && ((in_stack_00000010 & 1) != 0)) {
    QReadWriteLock::unlock();
  }
  if (in_stack_00000028 != (long *)0x0) {
    (**(code **)(*in_stack_00000028 + 8))();
  }
  cVar1 = qatomic_int_deref(*unaff_R12);
  if (cVar1 == '\0') {
    QListData::dispose((Data *)*unaff_R12);
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=005144fd name=FUN_005144fd size=10 ====

void FUN_005144fd(void)

{
  char cVar1;
  undefined8 *unaff_R12;
  
  FUN_0096bd50();
  cVar1 = qatomic_int_deref(*unaff_R12);
  if (cVar1 == '\0') {
    QListData::dispose((Data *)*unaff_R12);
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00514508 name=FUN_00514508 size=63 ====

void FUN_00514508(void)

{
  undefined8 in_stack_00000010;
  ulong in_stack_00000020;
  long *in_stack_00000038;
  
  if ((in_stack_00000020 != 0) && ((in_stack_00000020 & 1) != 0)) {
    QReadWriteLock::unlock();
  }
  if (in_stack_00000038 != (long *)0x0) {
    (**(code **)(*in_stack_00000038 + 8))();
  }
  FUN_00963b22(in_stack_00000010);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00514547 name=FUN_00514547 size=13 ====

void FUN_00514547(void)

{
  undefined8 in_stack_00000010;
  
  FUN_0096bd50();
  FUN_00963b22(in_stack_00000010);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00514554 name=FUN_00514554 size=37 ====

void FUN_00514554(void)

{
  ulong in_stack_00000028;
  
  if ((in_stack_00000028 != 0) && ((in_stack_00000028 & 1) != 0)) {
    QReadWriteLock::unlock();
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00514579 name=FUN_00514579 size=31 ====

void FUN_00514579(void)

{
  undefined1 *in_stack_00000058;
  
  if (in_stack_00000058 != &DAT_011c5338) {
    refcount_delete_offset10_c();
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00514598 name=FUN_00514598 size=69 ====

void FUN_00514598(void)

{
  long in_stack_00000010;
  long in_stack_00000020;
  undefined8 in_stack_00000040;
  undefined8 in_stack_00000048;
  
  if (in_stack_00000010 != in_stack_00000020) {
    refcount_delete_offset10_c(in_stack_00000010);
  }
  FUN_00889746(in_stack_00000048);
  FUN_00963b22(in_stack_00000040);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=005145dd name=FUN_005145dd size=24 ====

void FUN_005145dd(void)

{
  long in_stack_00000018;
  long in_stack_00000020;
  undefined8 in_stack_00000040;
  undefined8 in_stack_00000048;
  
  if (in_stack_00000018 != in_stack_00000020) {
    refcount_delete_offset10_c(in_stack_00000018);
  }
  FUN_00889746(in_stack_00000048);
  FUN_00963b22(in_stack_00000040);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=005145f5 name=FUN_005145f5 size=28 ====

void FUN_005145f5(void)

{
  byte unaff_retaddr;
  undefined7 unaff_retaddr_00;
  undefined8 in_stack_00000040;
  undefined8 in_stack_00000048;
  
  if ((CONCAT71(unaff_retaddr_00,unaff_retaddr) != 0) && ((unaff_retaddr & 1) != 0)) {
    QReadWriteLock::unlock();
  }
  FUN_00889746(in_stack_00000048);
  FUN_00963b22(in_stack_00000040);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00514611 name=FUN_00514611 size=43 ====

void FUN_00514611(void)

{
  locale *in_stack_00000030;
  long in_stack_00000038;
  undefined8 in_stack_00000040;
  undefined8 in_stack_00000048;
  long in_stack_00000068;
  
  std::locale::~locale((locale *)(in_stack_00000038 + 8));
  std::locale::~locale((locale *)(in_stack_00000068 + 8));
  std::locale::~locale(in_stack_00000030);
  FUN_00889746(in_stack_00000048);
  FUN_00963b22(in_stack_00000040);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0051463c name=FUN_0051463c size=43 ====

void FUN_0051463c(void)

{
  locale *in_stack_00000028;
  long in_stack_00000030;
  undefined8 in_stack_00000040;
  undefined8 in_stack_00000048;
  long in_stack_00000058;
  
  std::locale::~locale((locale *)(in_stack_00000030 + 8));
  std::locale::~locale((locale *)(in_stack_00000058 + 8));
  std::locale::~locale(in_stack_00000028);
  FUN_00889746(in_stack_00000048);
  FUN_00963b22(in_stack_00000040);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00514668 name=FUN_00514668 size=67 ====

void FUN_00514668(void)

{
  undefined8 in_stack_00000028;
  undefined8 in_stack_00000038;
  undefined8 in_stack_00000040;
  undefined **in_stack_00000090;
  
  FUN_0096bb02(&stack0x00000070);
  in_stack_00000090 = &Uint8RunStyles_vtable;
  FUN_00889746(in_stack_00000038);
  qt_byte_array_unref(in_stack_00000028);
  FUN_00963b22(in_stack_00000040);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=005146ab name=FUN_005146ab size=31 ====

void FUN_005146ab(void)

{
  ulong in_stack_00000008;
  undefined8 in_stack_00000028;
  undefined8 in_stack_00000038;
  undefined8 in_stack_00000040;
  
  if ((in_stack_00000008 != 0) && ((in_stack_00000008 & 1) != 0)) {
    QReadWriteLock::unlock();
  }
  FUN_00889746(in_stack_00000038);
  qt_byte_array_unref(in_stack_00000028);
  FUN_00963b22(in_stack_00000040);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=005146ca name=FUN_005146ca size=61 ====

void FUN_005146ca(void)

{
  ulong in_stack_00000010;
  long *in_stack_00000028;
  
  if ((in_stack_00000010 != 0) && ((in_stack_00000010 & 1) != 0)) {
    QReadWriteLock::unlock();
  }
  if (in_stack_00000028 != (long *)0x0) {
    (**(code **)(*in_stack_00000028 + 8))();
  }
  FUN_00963b22();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00514707 name=FUN_00514707 size=13 ====

void FUN_00514707(void)

{
  FUN_0096bd50();
  FUN_00963b22();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00514714 name=FUN_00514714 size=58 ====

void FUN_00514714(void)

{
  void *unaff_R12;
  undefined8 in_stack_00000050;
  undefined8 in_stack_00000060;
  void *in_stack_000000b0;
  
  operator_delete(unaff_R12,0x20);
  if (in_stack_000000b0 != (void *)0x0) {
    operator_delete(in_stack_000000b0);
  }
  FUN_00963b22(in_stack_00000060);
  FUN_00a161d8(in_stack_00000050);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0051474e name=FUN_0051474e size=89 ====

void FUN_0051474e(void)

{
  QCollatorSortKey *this;
  long *unaff_R12;
  undefined8 in_stack_00000050;
  nothrow_t *in_stack_00000058;
  undefined8 in_stack_00000060;
  void *in_stack_000000b0;
  QCollatorSortKey *in_stack_000000d0;
  QCollatorSortKey *in_stack_000000d8;
  
  operator_delete((void *)0x0,in_stack_00000058);
  for (this = in_stack_000000d0; in_stack_000000d8 != this; this = this + 8) {
    QCollatorSortKey::~QCollatorSortKey(this);
  }
  if (in_stack_000000d0 != (QCollatorSortKey *)0x0) {
    operator_delete(in_stack_000000d0);
  }
  (**(code **)(*unaff_R12 + 8))();
  if (in_stack_000000b0 != (void *)0x0) {
    operator_delete(in_stack_000000b0);
  }
  FUN_00963b22(in_stack_00000060);
  FUN_00a161d8(in_stack_00000050);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=005147d5 name=FUN_005147d5 size=25 ====

void FUN_005147d5(void)

{
  QCollatorSortKey *this;
  long *unaff_R12;
  QCollatorSortKey *in_stack_00000010;
  undefined8 in_stack_00000018;
  undefined8 in_stack_00000050;
  undefined8 in_stack_00000060;
  void *in_stack_000000b0;
  QCollatorSortKey *in_stack_000000d0;
  QCollatorSortKey *in_stack_000000d8;
  
  QCollatorSortKey::~QCollatorSortKey(in_stack_00000010);
  qt_array_data_unref(in_stack_00000018);
  for (this = in_stack_000000d0; in_stack_000000d8 != this; this = this + 8) {
    QCollatorSortKey::~QCollatorSortKey(this);
  }
  if (in_stack_000000d0 != (QCollatorSortKey *)0x0) {
    operator_delete(in_stack_000000d0);
  }
  (**(code **)(*unaff_R12 + 8))();
  if (in_stack_000000b0 != (void *)0x0) {
    operator_delete(in_stack_000000b0);
  }
  FUN_00963b22(in_stack_00000060);
  FUN_00a161d8(in_stack_00000050);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=005147ee name=FUN_005147ee size=32 ====

void FUN_005147ee(void)

{
  QCollatorSortKey *this;
  long *unaff_R12;
  undefined8 in_stack_00000010;
  undefined8 in_stack_00000050;
  undefined8 in_stack_00000060;
  void *in_stack_000000b0;
  QCollatorSortKey *in_stack_000000d0;
  QCollatorSortKey *in_stack_000000d8;
  
  qt_byte_array_unref(in_stack_00000010);
  for (this = in_stack_000000d0; in_stack_000000d8 != this; this = this + 8) {
    QCollatorSortKey::~QCollatorSortKey(this);
  }
  if (in_stack_000000d0 != (QCollatorSortKey *)0x0) {
    operator_delete(in_stack_000000d0);
  }
  (**(code **)(*unaff_R12 + 8))();
  if (in_stack_000000b0 != (void *)0x0) {
    operator_delete(in_stack_000000b0);
  }
  FUN_00963b22(in_stack_00000060);
  FUN_00a161d8(in_stack_00000050);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0051480e name=FUN_0051480e size=31 ====

void FUN_0051480e(void)

{
  long *unaff_R12;
  ulong in_stack_00000038;
  undefined8 in_stack_00000050;
  undefined8 in_stack_00000060;
  void *in_stack_000000b0;
  
  if ((in_stack_00000038 != 0) && ((in_stack_00000038 & 1) != 0)) {
    QReadWriteLock::unlock();
  }
  (**(code **)(*unaff_R12 + 8))();
  if (in_stack_000000b0 != (void *)0x0) {
    operator_delete(in_stack_000000b0);
  }
  FUN_00963b22(in_stack_00000060);
  FUN_00a161d8(in_stack_00000050);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0051482d name=FUN_0051482d size=31 ====

void FUN_0051482d(void)

{
  long *unaff_R12;
  undefined8 in_stack_00000010;
  undefined8 in_stack_00000050;
  undefined8 in_stack_00000060;
  void *in_stack_000000b0;
  undefined8 in_stack_00000100;
  
  qt_byte_array_unref();
  FUN_00a4b9e0(in_stack_00000010,in_stack_00000100);
  (**(code **)(*unaff_R12 + 8))();
  if (in_stack_000000b0 != (void *)0x0) {
    operator_delete(in_stack_000000b0);
  }
  FUN_00963b22(in_stack_00000060);
  FUN_00a161d8(in_stack_00000050);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0051483a name=FUN_0051483a size=15 ====

void FUN_0051483a(void)

{
  undefined8 in_stack_00000010;
  undefined8 in_stack_00000050;
  undefined8 in_stack_00000060;
  void *in_stack_000000b0;
  
  FUN_0096bd50(in_stack_00000010);
  if (in_stack_000000b0 != (void *)0x0) {
    operator_delete(in_stack_000000b0);
  }
  FUN_00963b22(in_stack_00000060);
  FUN_00a161d8(in_stack_00000050);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00514849 name=FUN_00514849 size=21 ====

void FUN_00514849(void)

{
  void *unaff_R14;
  
  __cxa_begin_catch();
  operator_delete(unaff_R14);
                    /* WARNING: Subroutine does not return */
                    /* try { // try from 00514859 to 0051485d has its CatchHandler @ 0051478b */
  __cxa_rethrow();
}


// ==== entry=0051485e name=FUN_0051485e size=47 ====

void FUN_0051485e(void)

{
  undefined8 unaff_retaddr;
  ulong in_stack_00000010;
  long *in_stack_00000028;
  
  if ((in_stack_00000010 != 0) && ((in_stack_00000010 & 1) != 0)) {
    QReadWriteLock::unlock();
  }
  if (in_stack_00000028 != (long *)0x0) {
    (**(code **)(*in_stack_00000028 + 8))();
  }
  FUN_00963b22(unaff_retaddr);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0051488d name=FUN_0051488d size=25 ====

void FUN_0051488d(void)

{
  undefined8 unaff_retaddr;
  
  FUN_0096bd50();
  FUN_00963b22(unaff_retaddr);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=005148a6 name=FUN_005148a6 size=25 ====

void FUN_005148a6(void)

{
  undefined8 unaff_retaddr;
  undefined1 *in_stack_00000040;
  
  if (in_stack_00000040 != &DAT_011c5338) {
    refcount_delete_offset10_c();
  }
  FUN_00963b22(unaff_retaddr);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=005148bf name=FUN_005148bf size=25 ====

void FUN_005148bf(void)

{
  undefined8 unaff_retaddr;
  long *in_stack_00000028;
  undefined1 *in_stack_00000040;
  
  if (in_stack_00000040 != &DAT_011c5338) {
    refcount_delete_offset10_c();
  }
  if (in_stack_00000028 != (long *)0x0) {
    (**(code **)(*in_stack_00000028 + 8))();
  }
  FUN_00963b22(unaff_retaddr);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=005148d8 name=FUN_005148d8 size=24 ====

void FUN_005148d8(void)

{
  QVariant *unaff_R12;
  QVariant *unaff_R13;
  
  QVariant::~QVariant(unaff_R13);
  QVariant::~QVariant(unaff_R12);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=005148f0 name=FUN_005148f0 size=24 ====

void FUN_005148f0(void)

{
  QVariant *unaff_R12;
  QVariant *unaff_R13;
  
  QVariant::~QVariant(unaff_R13);
  QVariant::~QVariant(unaff_R12);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00514908 name=FUN_00514908 size=31 ====

void FUN_00514908(void)

{
  undefined1 *in_stack_00000068;
  
  if (in_stack_00000068 != &DAT_011c5338) {
    refcount_delete_offset10_c();
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00514927 name=FUN_00514927 size=48 ====

void FUN_00514927(void)

{
  ulong in_stack_00000040;
  undefined1 *in_stack_00000050;
  
  *in_stack_00000050 = 0;
  if ((in_stack_00000040 != 0) && ((in_stack_00000040 & 1) != 0)) {
    QReadWriteLock::unlock();
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00514958 name=FUN_00514958 size=31 ====

void FUN_00514958(void)

{
  undefined1 *in_stack_00000018;
  
  if (in_stack_00000018 != &DAT_011c5338) {
    refcount_delete_offset10_c();
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00514977 name=FUN_00514977 size=39 ====

void FUN_00514977(void)

{
  long unaff_R13;
  byte unaff_R14B;
  undefined7 unaff_000000b1;
  
  *(undefined1 *)(unaff_R13 + 0x28) = 0;
  if ((CONCAT71(unaff_000000b1,unaff_R14B) != 0) && ((unaff_R14B & 1) != 0)) {
    QReadWriteLock::unlock();
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0051499e name=FUN_0051499e size=16 ====

void FUN_0051499e(void)

{
  FUN_0096bb02();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=005149ae name=FUN_005149ae size=42 ====

void FUN_005149ae(void)

{
  undefined8 in_stack_00000010;
  
  FUN_0096bb02();
  FUN_0096bb02();
  FUN_0096bd50();
  FUN_00974856(in_stack_00000010);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=005149d8 name=FUN_005149d8 size=18 ====

void FUN_005149d8(void)

{
  undefined8 in_stack_00000010;
  
  FUN_0096bb02();
  FUN_0096bb02();
  FUN_00974856(in_stack_00000010);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=005149ea name=FUN_005149ea size=10 ====

void FUN_005149ea(void)

{
  undefined8 in_stack_00000010;
  
  FUN_0096bb02();
  FUN_00974856(in_stack_00000010);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=005149f4 name=FUN_005149f4 size=14 ====

void FUN_005149f4(void)

{
  undefined8 in_stack_00000010;
  
  FUN_0096bb02();
  FUN_00974856(in_stack_00000010);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00514a02 name=FUN_00514a02 size=18 ====

void FUN_00514a02(void)

{
  undefined8 in_stack_00000010;
  
  FUN_0096bb02();
  FUN_0096bb02();
  FUN_0096bd50();
  FUN_00974856(in_stack_00000010);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00514a14 name=FUN_00514a14 size=14 ====

void FUN_00514a14(void)

{
  undefined8 in_stack_00000010;
  
  FUN_0096bb02();
  FUN_0096bd50();
  FUN_00974856(in_stack_00000010);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00514a22 name=FUN_00514a22 size=26 ====

void FUN_00514a22(void)

{
  undefined8 in_stack_00000008;
  
  FUN_0096bb02();
  FUN_0096bb02(in_stack_00000008);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00514a3c name=FUN_00514a3c size=16 ====

void FUN_00514a3c(void)

{
  FUN_0096bb02();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00514a4c name=FUN_00514a4c size=10 ====

void FUN_00514a4c(void)

{
  undefined8 in_stack_00000008;
  
  FUN_0096bd50();
  FUN_0096bb02(in_stack_00000008);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00514a56 name=FUN_00514a56 size=18 ====

void FUN_00514a56(void)

{
  undefined8 in_stack_00000008;
  
  FUN_0096bd50();
  FUN_0096bd50();
  FUN_0096bb02(in_stack_00000008);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00514a68 name=FUN_00514a68 size=10 ====

void FUN_00514a68(void)

{
  undefined8 in_stack_00000008;
  
  FUN_0096bb02();
  FUN_0096bb02(in_stack_00000008);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00514a72 name=FUN_00514a72 size=28 ====

void FUN_00514a72(void)

{
  undefined1 *unaff_R14;
  
  QReadWriteLock::unlock();
  *unaff_R14 = 0;
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00514a8e name=FUN_00514a8e size=37 ====

void FUN_00514a8e(void)

{
  undefined1 *unaff_RBX;
  byte unaff_R14B;
  undefined7 unaff_000000b1;
  
  *unaff_RBX = 0;
  if ((CONCAT71(unaff_000000b1,unaff_R14B) != 0) && ((unaff_R14B & 1) != 0)) {
    QReadWriteLock::unlock();
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00514ab3 name=FUN_00514ab3 size=12 ====

void FUN_00514ab3(void)

{
  undefined1 *unaff_R14;
  
  *unaff_R14 = 0;
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00514ac0 name=FUN_00514ac0 size=82 ====

void FUN_00514ac0(void)

{
  QVariant *unaff_RBX;
  undefined8 in_stack_00000008;
  undefined8 in_stack_00000010;
  
  QVariant::~QVariant(unaff_RBX + 0x10);
  QVariant::~QVariant(unaff_RBX);
  qmap_freetree_variant_nodes(in_stack_00000010);
  qatomic_unref_call_deleter(&stack0x00000058);
  qt_array_data_unref(in_stack_00000008);
  qt_array_data_unref(&stack0x00000048);
  qmap_freetree_variant_nodes();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00514b12 name=FUN_00514b12 size=46 ====

void FUN_00514b12(void)

{
  QVariant *unaff_RBP;
  undefined8 in_stack_00000008;
  undefined8 in_stack_00000010;
  undefined8 in_stack_00000018;
  undefined8 in_stack_00000020;
  
  qt_array_data_unref(in_stack_00000018);
  QVariant::~QVariant(unaff_RBP);
  qt_array_data_unref(in_stack_00000020);
  FUN_009700a4();
  qmap_freetree_variant_nodes(in_stack_00000010);
  qatomic_unref_call_deleter(&stack0x00000058);
  qt_array_data_unref(in_stack_00000008);
  qt_array_data_unref(&stack0x00000048);
  qmap_freetree_variant_nodes();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00514b40 name=FUN_00514b40 size=26 ====

void FUN_00514b40(void)

{
  QVariant *unaff_RBX;
  undefined8 in_stack_00000008;
  
  qt_array_data_unref();
  QVariant::~QVariant(unaff_RBX);
  qatomic_unref_call_deleter(&stack0x00000058);
  qt_array_data_unref(in_stack_00000008);
  qt_array_data_unref();
  qmap_freetree_variant_nodes();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00514b5a name=FUN_00514b5a size=27 ====

void FUN_00514b5a(void)

{
  QVariant *unaff_RBX;
  undefined8 in_stack_00000008;
  
  qt_array_data_unref();
  QVariant::~QVariant(unaff_RBX);
  qatomic_unref_call_deleter();
  qt_array_data_unref(in_stack_00000008);
  qt_array_data_unref();
  qmap_freetree_variant_nodes();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00514b75 name=FUN_00514b75 size=30 ====

void FUN_00514b75(void)

{
  QVariant *unaff_RBX;
  undefined8 in_stack_00000008;
  
  QVariant::~QVariant(unaff_RBX + 0x10);
  QVariant::~QVariant(unaff_RBX);
  qatomic_unref_call_deleter(&stack0x00000058);
  qt_array_data_unref(in_stack_00000008);
  qt_array_data_unref();
  qmap_freetree_variant_nodes();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00514b93 name=FUN_00514b93 size=41 ====

void FUN_00514b93(void)

{
  undefined8 in_stack_00000008;
  undefined1 *in_stack_000000b0;
  
  if (in_stack_000000b0 != &DAT_011c5338) {
    refcount_delete_offset10_c();
  }
  qatomic_unref_call_deleter(&stack0x00000058);
  qt_array_data_unref(in_stack_00000008);
  qt_array_data_unref(&stack0x00000048);
  qmap_freetree_variant_nodes();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00514bbc name=FUN_00514bbc size=24 ====

void FUN_00514bbc(void)

{
  QVariant *unaff_RBX;
  undefined8 in_stack_00000008;
  undefined8 in_stack_00000010;
  
  qt_array_data_unref();
  QVariant::~QVariant(unaff_RBX);
  qmap_freetree_variant_nodes(in_stack_00000010);
  qatomic_unref_call_deleter(&stack0x00000058);
  qt_array_data_unref(in_stack_00000008);
  qt_array_data_unref();
  qmap_freetree_variant_nodes();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00514bd4 name=FUN_00514bd4 size=14 ====

void FUN_00514bd4(void)

{
  QVariant *unaff_RBX;
  undefined8 in_stack_00000008;
  undefined8 in_stack_00000010;
  
  qt_array_data_unref();
  QVariant::~QVariant(unaff_RBX);
  qmap_freetree_variant_nodes(in_stack_00000010);
  qatomic_unref_call_deleter(&stack0x00000058);
  qt_array_data_unref(in_stack_00000008);
  qt_array_data_unref();
  qmap_freetree_variant_nodes();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00514be2 name=FUN_00514be2 size=13 ====

void FUN_00514be2(void)

{
  QVariant *unaff_RBX;
  undefined8 in_stack_00000008;
  undefined8 in_stack_00000010;
  
  qt_array_data_unref();
  QVariant::~QVariant(unaff_RBX);
  qmap_freetree_variant_nodes(in_stack_00000010);
  qatomic_unref_call_deleter(&stack0x00000058);
  qt_array_data_unref(in_stack_00000008);
  qt_array_data_unref();
  qmap_freetree_variant_nodes();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00514bef name=FUN_00514bef size=44 ====

void FUN_00514bef(void)

{
  undefined8 in_stack_00000008;
  undefined8 in_stack_00000018;
  
  qt_array_data_unref();
  qt_array_data_unref();
  qt_array_data_unref(in_stack_00000018);
  qatomic_unref_call_deleter(&stack0x00000058);
  qt_array_data_unref(in_stack_00000008);
  qt_array_data_unref(&stack0x00000048);
  qmap_freetree_variant_nodes();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00514c1b name=FUN_00514c1b size=29 ====

void FUN_00514c1b(void)

{
  QVariant *unaff_RBX;
  undefined8 in_stack_00000008;
  
  qt_array_data_unref();
  QVariant::~QVariant(unaff_RBX);
  qatomic_unref_call_deleter(&stack0x00000058);
  qt_array_data_unref(in_stack_00000008);
  qt_array_data_unref();
  qmap_freetree_variant_nodes();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00514c38 name=FUN_00514c38 size=24 ====

void FUN_00514c38(void)

{
  FUN_0096bb02();
  FUN_0096bb02();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00514c50 name=FUN_00514c50 size=24 ====

void FUN_00514c50(void)

{
  FUN_0096bb02();
  FUN_0096bb02();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00514c68 name=FUN_00514c68 size=39 ====

void FUN_00514c68(void)

{
  undefined1 *in_stack_00000020;
  
  if (in_stack_00000020 != &DAT_011c5338) {
    refcount_delete_offset10_c();
  }
  FUN_0096bb02();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00514c90 name=FUN_00514c90 size=46 ====

void FUN_00514c90(void)

{
  undefined8 in_stack_00000008;
  undefined8 in_stack_00000010;
  undefined8 in_stack_00000018;
  
  FUN_0096bb02();
  FUN_0096bb02(in_stack_00000018);
  FUN_0096bb02(in_stack_00000008);
  FUN_00974856(in_stack_00000010);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00514cbe name=FUN_00514cbe size=10 ====

void FUN_00514cbe(void)

{
  undefined8 in_stack_00000008;
  undefined8 in_stack_00000010;
  undefined8 in_stack_00000018;
  
  FUN_0096bb02();
  FUN_0096bb02(in_stack_00000018);
  FUN_0096bb02(in_stack_00000008);
  FUN_00974856(in_stack_00000010);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00514cc8 name=FUN_00514cc8 size=10 ====

void FUN_00514cc8(void)

{
  undefined8 in_stack_00000008;
  undefined8 in_stack_00000010;
  
  FUN_0096bb02();
  FUN_0096bb02(in_stack_00000008);
  FUN_00974856(in_stack_00000010);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00514cd2 name=FUN_00514cd2 size=16 ====

void FUN_00514cd2(void)

{
  FUN_0096bb02();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00514ce2 name=FUN_00514ce2 size=16 ====

void FUN_00514ce2(void)

{
  FUN_0096bb02();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00514cf2 name=FUN_00514cf2 size=16 ====

void FUN_00514cf2(void)

{
  FUN_0096bb02();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00514d02 name=FUN_00514d02 size=31 ====

void FUN_00514d02(void)

{
  char unaff_R15B;
  undefined8 in_stack_00000018;
  
  FUN_0096bb02(in_stack_00000018);
  if (unaff_R15B != '\0') {
    FUN_0096bb02();
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00514d21 name=FUN_00514d21 size=13 ====

void FUN_00514d21(void)

{
  undefined8 in_stack_00000008;
  undefined8 in_stack_00000010;
  
  FUN_0096bd50();
  FUN_0096bb02(in_stack_00000008);
  FUN_00974856(in_stack_00000010);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00514d2e name=FUN_00514d2e size=16 ====

void FUN_00514d2e(void)

{
  qt_byte_array_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00514d3e name=FUN_00514d3e size=33 ====

void FUN_00514d3e(void)

{
  undefined1 *in_stack_00000030;
  
  QReadWriteLock::unlock();
  *in_stack_00000030 = 0;
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00514d5f name=FUN_00514d5f size=45 ====

void FUN_00514d5f(void)

{
  undefined1 *unaff_R13;
  ulong in_stack_00000030;
  
  *unaff_R13 = 0;
  if ((in_stack_00000030 != 0) && ((in_stack_00000030 & 1) != 0)) {
    QReadWriteLock::unlock();
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00514d8c name=FUN_00514d8c size=16 ====

void FUN_00514d8c(void)

{
  undefined1 *in_stack_00000030;
  
  *in_stack_00000030 = 0;
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00514d9c name=FUN_00514d9c size=33 ====

void FUN_00514d9c(void)

{
  undefined1 *in_stack_00000048;
  
  QReadWriteLock::unlock();
  *in_stack_00000048 = 0;
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00514dbd name=FUN_00514dbd size=45 ====

void FUN_00514dbd(void)

{
  undefined1 *unaff_R13;
  ulong in_stack_00000048;
  
  *unaff_R13 = 0;
  if ((in_stack_00000048 != 0) && ((in_stack_00000048 & 1) != 0)) {
    QReadWriteLock::unlock();
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00514dea name=FUN_00514dea size=16 ====

void FUN_00514dea(void)

{
  undefined1 *in_stack_00000048;
  
  *in_stack_00000048 = 0;
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00514dfa name=FUN_00514dfa size=31 ====

void FUN_00514dfa(void)

{
  undefined1 *in_stack_00000068;
  
  if (in_stack_00000068 != &DAT_011c5338) {
    refcount_delete_offset10_c();
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00514e19 name=FUN_00514e19 size=48 ====

void FUN_00514e19(void)

{
  ulong in_stack_00000040;
  undefined1 *in_stack_00000050;
  
  *in_stack_00000050 = 0;
  if ((in_stack_00000040 != 0) && ((in_stack_00000040 & 1) != 0)) {
    QReadWriteLock::unlock();
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00514e4a name=FUN_00514e4a size=70 ====

/* WARNING: Removing unreachable block (ram,0x00514e74) */

void FUN_00514e4a(void)

{
  undefined8 in_stack_00000058;
  void *in_stack_00000060;
  undefined8 in_stack_00000068;
  undefined8 in_stack_00000070;
  void *in_stack_00000078;
  
  operator_delete(in_stack_00000078,0x10);
  stdfunction_state_destroy(in_stack_00000058);
  FUN_00974856(in_stack_00000070);
  FUN_00a161d8(in_stack_00000068);
  if (in_stack_00000060 != (void *)0x0) {
    FUN_005f38a6(in_stack_00000060);
    operator_delete(in_stack_00000060,0x10);
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00514e90 name=FUN_00514e90 size=11 ====

void FUN_00514e90(void)

{
  void *pvVar1;
  undefined8 in_stack_00000058;
  void *in_stack_00000060;
  undefined8 in_stack_00000068;
  undefined8 in_stack_00000070;
  void *pvStack0000000000000078;
  
  pvStack0000000000000078 = (void *)0x0;
  stdfunction_state_destroy(in_stack_00000058);
  pvVar1 = pvStack0000000000000078;
  if (pvStack0000000000000078 != (void *)0x0) {
    FUN_009cff96(pvStack0000000000000078);
    operator_delete(pvVar1,0x10);
  }
  FUN_00974856(in_stack_00000070);
  FUN_00a161d8(in_stack_00000068);
  if (in_stack_00000060 != (void *)0x0) {
    FUN_005f38a6(in_stack_00000060);
    operator_delete(in_stack_00000060,0x10);
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00514e9b name=FUN_00514e9b size=116 ====

void FUN_00514e9b(void)

{
  undefined8 in_stack_00000008;
  void *in_stack_00000060;
  undefined8 in_stack_00000068;
  undefined8 in_stack_00000070;
  code *in_stack_00000120;
  code *in_stack_00000140;
  
  if (in_stack_00000120 != (code *)0x0) {
    (*in_stack_00000120)();
  }
  if (in_stack_00000140 != (code *)0x0) {
    (*in_stack_00000140)(in_stack_00000008,in_stack_00000008,3);
  }
  FUN_00974856(in_stack_00000070);
  FUN_00a161d8(in_stack_00000068);
  if (in_stack_00000060 != (void *)0x0) {
    FUN_005f38a6(in_stack_00000060);
    operator_delete(in_stack_00000060,0x10);
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00514f0f name=FUN_00514f0f size=14 ====

void FUN_00514f0f(void)

{
  void *pvVar1;
  undefined8 in_stack_00000058;
  void *in_stack_00000060;
  undefined8 in_stack_00000068;
  undefined8 in_stack_00000070;
  void *pvStack0000000000000078;
  
  pvStack0000000000000078 = (void *)0x0;
  stdfunction_state_destroy(in_stack_00000058);
  pvVar1 = pvStack0000000000000078;
  if (pvStack0000000000000078 != (void *)0x0) {
    FUN_009cff96(pvStack0000000000000078);
    operator_delete(pvVar1,0x10);
  }
  FUN_00974856(in_stack_00000070);
  FUN_00a161d8(in_stack_00000068);
  if (in_stack_00000060 != (void *)0x0) {
    FUN_005f38a6(in_stack_00000060);
    operator_delete(in_stack_00000060,0x10);
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00514f1d name=FUN_00514f1d size=15 ====

void FUN_00514f1d(void)

{
  undefined8 in_stack_00000008;
  undefined8 in_stack_00000058;
  void *in_stack_00000060;
  undefined8 in_stack_00000068;
  undefined8 in_stack_00000070;
  void *in_stack_00000078;
  
  qt_byte_array_unref(in_stack_00000008);
  stdfunction_state_destroy(in_stack_00000058);
  if (in_stack_00000078 != (void *)0x0) {
    FUN_009cff96(in_stack_00000078);
    operator_delete(in_stack_00000078,0x10);
  }
  FUN_00974856(in_stack_00000070);
  FUN_00a161d8(in_stack_00000068);
  if (in_stack_00000060 != (void *)0x0) {
    FUN_005f38a6(in_stack_00000060);
    operator_delete(in_stack_00000060,0x10);
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00514f2c name=FUN_00514f2c size=33 ====

void FUN_00514f2c(void)

{
  undefined8 in_stack_00000058;
  void *in_stack_00000060;
  
  operator_delete(in_stack_00000060,0x10);
  qt_array_data_unref(in_stack_00000058);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00514f4d name=FUN_00514f4d size=15 ====

void FUN_00514f4d(void)

{
  undefined8 in_stack_00000008;
  undefined8 in_stack_00000058;
  void *in_stack_00000060;
  undefined8 in_stack_00000068;
  undefined8 in_stack_00000070;
  void *in_stack_00000078;
  
  qt_byte_array_unref(in_stack_00000008);
  stdfunction_state_destroy(in_stack_00000058);
  if (in_stack_00000078 != (void *)0x0) {
    FUN_009cff96(in_stack_00000078);
    operator_delete(in_stack_00000078,0x10);
  }
  FUN_00974856(in_stack_00000070);
  FUN_00a161d8(in_stack_00000068);
  if (in_stack_00000060 != (void *)0x0) {
    FUN_005f38a6(in_stack_00000060);
    operator_delete(in_stack_00000060,0x10);
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00514f5c name=FUN_00514f5c size=29 ====

/* WARNING: Removing unreachable block (ram,0x00514e74) */

void FUN_00514f5c(void)

{
  undefined8 in_stack_00000058;
  void *in_stack_00000060;
  undefined8 in_stack_00000068;
  undefined8 in_stack_00000070;
  void *in_stack_00000078;
  
  operator_delete(in_stack_00000078,0x10);
  stdfunction_state_destroy(in_stack_00000058);
  FUN_00974856(in_stack_00000070);
  FUN_00a161d8(in_stack_00000068);
  if (in_stack_00000060 != (void *)0x0) {
    FUN_005f38a6(in_stack_00000060);
    operator_delete(in_stack_00000060,0x10);
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00514f7a name=FUN_00514f7a size=83 ====

void FUN_00514f7a(void)

{
  QPixmap *unaff_RBP;
  long *unaff_R12;
  code *in_stack_00000080;
  code *in_stack_000000a0;
  
  if (in_stack_00000080 != (code *)0x0) {
    (*in_stack_00000080)();
  }
  if (in_stack_000000a0 != (code *)0x0) {
    (*in_stack_000000a0)();
  }
  if (unaff_R12 != (long *)0x0) {
    (**(code **)(*unaff_R12 + 8))();
  }
  QPixmap::~QPixmap(unaff_RBP);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00514fcd name=FUN_00514fcd size=10 ====

void FUN_00514fcd(void)

{
  QPixmap *unaff_RBP;
  long *unaff_R12;
  
  stdfunction_state_destroy();
  (**(code **)(*unaff_R12 + 8))();
  QPixmap::~QPixmap(unaff_RBP);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00514fd8 name=FUN_00514fd8 size=55 ====

void FUN_00514fd8(void)

{
  undefined1 *in_stack_000000f0;
  
  if (in_stack_000000f0 != &DAT_011c5338) {
    refcount_delete_offset10_c();
  }
  FUN_0096bd50();
  qt_array_data_unref(&stack0x00000048);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0051500f name=FUN_0051500f size=35 ====

void FUN_0051500f(void)

{
  undefined8 in_stack_00000010;
  undefined8 in_stack_00000020;
  
  FUN_0096bd50();
  FUN_0096bb02(in_stack_00000020);
  FUN_0096bb02(in_stack_00000010);
  qt_array_data_unref(&stack0x00000048);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00515032 name=FUN_00515032 size=24 ====

void FUN_00515032(void)

{
  FUN_0096bb02();
  qt_array_data_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0051504a name=FUN_0051504a size=27 ====

void FUN_0051504a(void)

{
  undefined8 in_stack_00000010;
  undefined8 in_stack_00000020;
  
  FUN_0096bb02(in_stack_00000020);
  FUN_0096bb02(in_stack_00000010);
  FUN_0096bd50();
  qt_array_data_unref(&stack0x00000048);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00515065 name=FUN_00515065 size=36 ====

void FUN_00515065(void)

{
  QVariant *in_stack_00000010;
  undefined8 in_stack_00000018;
  
  qt_array_data_unref();
  QVariant::~QVariant(in_stack_00000010);
  qmap_freetree_variant_nodes(in_stack_00000018);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00515089 name=FUN_00515089 size=16 ====

void FUN_00515089(void)

{
  FUN_0096bb02();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00515099 name=FUN_00515099 size=44 ====

void FUN_00515099(void)

{
  QVariant *unaff_R15;
  undefined8 in_stack_00000018;
  undefined8 in_stack_00000020;
  
  qt_byte_array_unref();
  qt_byte_array_unref(in_stack_00000020);
  qmap_freetree_variant_nodes(in_stack_00000018);
  QVariant::~QVariant(unaff_R15);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=005150c5 name=FUN_005150c5 size=34 ====

void FUN_005150c5(void)

{
  undefined1 *in_stack_000000f0;
  
  if (in_stack_000000f0 != &DAT_011c5338) {
    refcount_delete_offset10_c();
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=005150e7 name=FUN_005150e7 size=16 ====

void FUN_005150e7(void)

{
  qt_array_data_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=005150f7 name=FUN_005150f7 size=24 ====

void FUN_005150f7(void)

{
  FUN_0096bb02();
  FUN_0096bb02();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0051510f name=FUN_0051510f size=24 ====

void FUN_0051510f(void)

{
  FUN_0096bb02();
  FUN_0096bb02();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00515127 name=FUN_00515127 size=16 ====

void FUN_00515127(void)

{
  qt_byte_array_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00515137 name=FUN_00515137 size=16 ====

void FUN_00515137(void)

{
  FUN_0096bb02();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00515147 name=FUN_00515147 size=46 ====

void FUN_00515147(void)

{
  undefined8 in_stack_00000010;
  
  qt_array_data_unref();
  qatomic_unref_call_deleter(in_stack_00000010);
  qt_array_data_unref(&stack0x00000070);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00515175 name=FUN_00515175 size=16 ====

void FUN_00515175(void)

{
  qt_array_data_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00515185 name=FUN_00515185 size=24 ====

void FUN_00515185(void)

{
  FUN_0096bb02();
  FUN_0096bb02();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0051519d name=FUN_0051519d size=16 ====

void FUN_0051519d(void)

{
  FUN_0096bb02();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=005151ad name=FUN_005151ad size=24 ====

void FUN_005151ad(void)

{
  FUN_00a161d8();
  qt_byte_array_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=005151c5 name=FUN_005151c5 size=34 ====

void FUN_005151c5(void)

{
  undefined1 *in_stack_000000f0;
  
  if (in_stack_000000f0 != &DAT_011c5338) {
    refcount_delete_offset10_c();
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=005151e7 name=FUN_005151e7 size=16 ====

void FUN_005151e7(void)

{
  FUN_0096bb02();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=005151f7 name=FUN_005151f7 size=34 ====

void FUN_005151f7(void)

{
  undefined8 in_stack_00000010;
  
  FUN_0096bb02();
  FUN_0096bb02();
  FUN_00974856(in_stack_00000010);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00515219 name=FUN_00515219 size=16 ====

void FUN_00515219(void)

{
  qt_array_data_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00515229 name=FUN_00515229 size=34 ====

void FUN_00515229(void)

{
  undefined1 *in_stack_000000f0;
  
  if (in_stack_000000f0 != &DAT_011c5338) {
    refcount_delete_offset10_c();
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0051524b name=FUN_0051524b size=16 ====

void FUN_0051524b(void)

{
  qt_byte_array_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0051525b name=FUN_0051525b size=24 ====

void FUN_0051525b(void)

{
  qt_array_data_unref();
  qt_array_data_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00515273 name=FUN_00515273 size=16 ====

void FUN_00515273(void)

{
  qatomic_unref_call_deleter();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00515283 name=FUN_00515283 size=16 ====

void FUN_00515283(void)

{
  FUN_0096bb02();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00515293 name=FUN_00515293 size=44 ====

void FUN_00515293(void)

{
  undefined8 in_stack_00000020;
  undefined1 *in_stack_000000f0;
  
  if (in_stack_000000f0 != &DAT_011c5338) {
    refcount_delete_offset10_c();
  }
  qt_array_data_unref(in_stack_00000020);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=005152bf name=FUN_005152bf size=61 ====

void FUN_005152bf(void)

{
  void *unaff_R12;
  undefined8 in_stack_00000010;
  undefined8 in_stack_00000020;
  
  operator_delete(unaff_R12,0x68);
  qt_array_data_unref(in_stack_00000010);
  qatomic_unref_call_deleter(in_stack_00000020);
  qatomic_unref_call_deleter(&stack0x00000060);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=005152fc name=FUN_005152fc size=16 ====

void FUN_005152fc(void)

{
  FUN_0096bb02();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0051530c name=FUN_0051530c size=23 ====

void FUN_0051530c(void)

{
  QVariant *in_stack_00000010;
  undefined8 in_stack_00000018;
  
  qt_array_data_unref();
  QVariant::~QVariant(in_stack_00000010);
  qmap_freetree_variant_nodes(in_stack_00000018);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00515323 name=FUN_00515323 size=23 ====

void FUN_00515323(void)

{
  QVariant *in_stack_00000010;
  undefined8 in_stack_00000018;
  
  qt_array_data_unref();
  QVariant::~QVariant(in_stack_00000010);
  qmap_freetree_variant_nodes(in_stack_00000018);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0051533a name=FUN_0051533a size=23 ====

void FUN_0051533a(void)

{
  QVariant *in_stack_00000010;
  undefined8 in_stack_00000018;
  
  qt_array_data_unref();
  QVariant::~QVariant(in_stack_00000010);
  qmap_freetree_variant_nodes(in_stack_00000018);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00515351 name=FUN_00515351 size=23 ====

void FUN_00515351(void)

{
  QVariant *in_stack_00000010;
  undefined8 in_stack_00000018;
  
  qt_array_data_unref();
  QVariant::~QVariant(in_stack_00000010);
  qmap_freetree_variant_nodes(in_stack_00000018);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00515368 name=FUN_00515368 size=23 ====

void FUN_00515368(void)

{
  QVariant *in_stack_00000010;
  undefined8 in_stack_00000018;
  
  qt_array_data_unref();
  QVariant::~QVariant(in_stack_00000010);
  qmap_freetree_variant_nodes(in_stack_00000018);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0051537f name=FUN_0051537f size=23 ====

void FUN_0051537f(void)

{
  QVariant *in_stack_00000010;
  undefined8 in_stack_00000018;
  
  qt_array_data_unref();
  QVariant::~QVariant(in_stack_00000010);
  qmap_freetree_variant_nodes(in_stack_00000018);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00515396 name=FUN_00515396 size=23 ====

void FUN_00515396(void)

{
  QVariant *in_stack_00000010;
  undefined8 in_stack_00000018;
  
  qt_array_data_unref();
  QVariant::~QVariant(in_stack_00000010);
  qmap_freetree_variant_nodes(in_stack_00000018);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=005153ad name=FUN_005153ad size=23 ====

void FUN_005153ad(void)

{
  QVariant *in_stack_00000010;
  undefined8 in_stack_00000018;
  
  qt_array_data_unref();
  QVariant::~QVariant(in_stack_00000010);
  qmap_freetree_variant_nodes(in_stack_00000018);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=005153c4 name=FUN_005153c4 size=23 ====

void FUN_005153c4(void)

{
  QVariant *in_stack_00000010;
  undefined8 in_stack_00000018;
  
  qt_array_data_unref();
  QVariant::~QVariant(in_stack_00000010);
  qmap_freetree_variant_nodes(in_stack_00000018);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=005153db name=FUN_005153db size=23 ====

void FUN_005153db(void)

{
  QVariant *in_stack_00000010;
  undefined8 in_stack_00000018;
  
  qt_array_data_unref();
  QVariant::~QVariant(in_stack_00000010);
  qmap_freetree_variant_nodes(in_stack_00000018);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=005153f2 name=FUN_005153f2 size=23 ====

void FUN_005153f2(void)

{
  QVariant *in_stack_00000010;
  undefined8 in_stack_00000018;
  
  qt_array_data_unref();
  QVariant::~QVariant(in_stack_00000010);
  qmap_freetree_variant_nodes(in_stack_00000018);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00515409 name=FUN_00515409 size=23 ====

void FUN_00515409(void)

{
  QVariant *in_stack_00000010;
  undefined8 in_stack_00000018;
  
  qt_array_data_unref();
  QVariant::~QVariant(in_stack_00000010);
  qmap_freetree_variant_nodes(in_stack_00000018);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00515420 name=FUN_00515420 size=33 ====

void FUN_00515420(void)

{
  QVariant *in_stack_00000010;
  undefined8 in_stack_00000018;
  undefined8 in_stack_00000030;
  
  qt_array_data_unref(in_stack_00000030);
  QVariant::~QVariant(in_stack_00000010);
  qt_array_data_unref();
  qmap_freetree_variant_nodes(in_stack_00000018);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00515441 name=FUN_00515441 size=23 ====

void FUN_00515441(void)

{
  QVariant *in_stack_00000010;
  undefined8 in_stack_00000018;
  
  qt_array_data_unref();
  QVariant::~QVariant(in_stack_00000010);
  qmap_freetree_variant_nodes(in_stack_00000018);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00515458 name=FUN_00515458 size=16 ====

void FUN_00515458(void)

{
  FUN_0096bb02();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00515468 name=FUN_00515468 size=34 ====

void FUN_00515468(void)

{
  QCollator *unaff_R15;
  undefined8 in_stack_00000010;
  
  qt_array_data_unref();
  QCollator::~QCollator(unaff_R15);
  qmap_freetree_variant_nodes(in_stack_00000010);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0051548a name=FUN_0051548a size=10 ====

void FUN_0051548a(void)

{
  QCollator *unaff_R15;
  undefined8 in_stack_00000010;
  
  qt_array_data_unref();
  QCollator::~QCollator(unaff_R15);
  qmap_freetree_variant_nodes(in_stack_00000010);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00515494 name=FUN_00515494 size=14 ====

void FUN_00515494(void)

{
  QCollator *unaff_R15;
  undefined8 in_stack_00000010;
  
  qt_array_data_unref();
  QCollator::~QCollator(unaff_R15);
  qmap_freetree_variant_nodes(in_stack_00000010);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=005154a2 name=FUN_005154a2 size=10 ====

void FUN_005154a2(void)

{
  undefined8 in_stack_00000010;
  
  qt_array_data_unref();
  qmap_freetree_variant_nodes(in_stack_00000010);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=005154ac name=FUN_005154ac size=34 ====

void FUN_005154ac(void)

{
  undefined1 *in_stack_000000b0;
  
  if (in_stack_000000b0 != &DAT_011c5338) {
    refcount_delete_offset10_c();
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=005154ce name=FUN_005154ce size=30 ====

void FUN_005154ce(void)

{
  long unaff_R12;
  long in_stack_000000f0;
  
  if (in_stack_000000f0 + -0x18 != unaff_R12) {
    refcount_delete_offset10_c();
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=005154ec name=FUN_005154ec size=47 ====

void FUN_005154ec(void)

{
  char unaff_R14B;
  undefined1 *in_stack_000000b0;
  
  if ((unaff_R14B != '\0') && (in_stack_000000b0 != &DAT_011c5338)) {
    refcount_delete_offset10_c();
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=005154fd name=FUN_005154fd size=24 ====

void FUN_005154fd(void)

{
  FUN_0096bb02();
  FUN_0096bb02();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00515515 name=FUN_00515515 size=16 ====

void FUN_00515515(void)

{
  qt_array_data_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00515525 name=FUN_00515525 size=30 ====

void FUN_00515525(void)

{
  long unaff_R12;
  long in_stack_000000f0;
  
  if (in_stack_000000f0 + -0x18 != unaff_R12) {
    refcount_delete_offset10_c();
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00515543 name=FUN_00515543 size=16 ====

void FUN_00515543(void)

{
  FUN_0096bb02();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00515553 name=FUN_00515553 size=24 ====

void FUN_00515553(void)

{
  FUN_0096bb02();
  FUN_0096bb02();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0051556b name=FUN_0051556b size=16 ====

void FUN_0051556b(void)

{
  QPixmap *unaff_R13;
  
  QPixmap::~QPixmap(unaff_R13);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0051557b name=FUN_0051557b size=16 ====

void FUN_0051557b(void)

{
  FUN_0096bb02();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0051558b name=FUN_0051558b size=16 ====

void FUN_0051558b(void)

{
  qt_array_data_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0051559b name=FUN_0051559b size=44 ====

void FUN_0051559b(void)

{
  undefined8 in_stack_00000010;
  undefined8 in_stack_00000020;
  
  FUN_0096bb02();
  FUN_0096bb02();
  qatomic_unref_call_deleter(in_stack_00000010);
  qt_byte_array_unref(in_stack_00000020);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=005155c7 name=FUN_005155c7 size=24 ====

void FUN_005155c7(void)

{
  qt_shared_data_unref();
  qt_shared_data_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=005155df name=FUN_005155df size=23 ====

void FUN_005155df(void)

{
  QVariant *in_stack_00000010;
  undefined8 in_stack_00000018;
  
  qt_array_data_unref();
  QVariant::~QVariant(in_stack_00000010);
  qmap_freetree_variant_nodes(in_stack_00000018);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=005155f6 name=FUN_005155f6 size=23 ====

void FUN_005155f6(void)

{
  QVariant *in_stack_00000010;
  undefined8 in_stack_00000018;
  
  qt_array_data_unref();
  QVariant::~QVariant(in_stack_00000010);
  qmap_freetree_variant_nodes(in_stack_00000018);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0051560d name=FUN_0051560d size=16 ====

void FUN_0051560d(void)

{
  qmap_freetree_variant_nodes();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0051561d name=FUN_0051561d size=16 ====

void FUN_0051561d(void)

{
  FUN_0096bb02();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0051562d name=FUN_0051562d size=16 ====

void FUN_0051562d(void)

{
  qt_array_data_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0051563d name=FUN_0051563d size=26 ====

void FUN_0051563d(void)

{
  _Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *in_stack_000000f8;
  
  if (in_stack_000000f8 != (_Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *)0x0) {
    std::_Sp_counted_base<(__gnu_cxx::_Lock_policy)2>::_M_release(in_stack_000000f8);
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00515657 name=FUN_00515657 size=16 ====

void FUN_00515657(void)

{
  FUN_0096bb02();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00515667 name=FUN_00515667 size=16 ====

void FUN_00515667(void)

{
  qt_array_data_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00515677 name=FUN_00515677 size=21 ====

void FUN_00515677(void)

{
  undefined8 in_stack_00000018;
  
  qt_array_data_unref();
  qmap_freetree_variant_nodes(in_stack_00000018);
  QVariant::~QVariant((QVariant *)&stack0x000000b0);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0051568c name=FUN_0051568c size=16 ====

void FUN_0051568c(void)

{
  FUN_0096bb02();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0051569c name=FUN_0051569c size=24 ====

void FUN_0051569c(void)

{
  qt_array_data_unref();
  FUN_0096bb02();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=005156b4 name=FUN_005156b4 size=13 ====

void FUN_005156b4(void)

{
  QVariant *unaff_R15;
  undefined8 in_stack_00000018;
  undefined8 in_stack_00000020;
  
  qt_array_data_unref();
  qt_byte_array_unref(in_stack_00000020);
  qmap_freetree_variant_nodes(in_stack_00000018);
  QVariant::~QVariant(unaff_R15);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=005156c1 name=FUN_005156c1 size=13 ====

void FUN_005156c1(void)

{
  undefined8 in_stack_00000020;
  
  qt_array_data_unref();
  qt_array_data_unref(in_stack_00000020);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=005156ce name=FUN_005156ce size=16 ====

void FUN_005156ce(void)

{
  qt_array_data_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=005156de name=FUN_005156de size=24 ====

void FUN_005156de(void)

{
  qt_byte_array_unref();
  qt_byte_array_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=005156f6 name=FUN_005156f6 size=16 ====

void FUN_005156f6(void)

{
  qt_byte_array_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00515706 name=FUN_00515706 size=16 ====

void FUN_00515706(void)

{
  FUN_0096bb02();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00515716 name=FUN_00515716 size=16 ====

void FUN_00515716(void)

{
  qt_byte_array_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00515726 name=FUN_00515726 size=16 ====

void FUN_00515726(void)

{
  qmap_freetree_variant_nodes();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00515736 name=FUN_00515736 size=16 ====

void FUN_00515736(void)

{
  FUN_009cff96();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00515746 name=FUN_00515746 size=16 ====

void FUN_00515746(void)

{
  qatomic_unref_call_deleter();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00515756 name=FUN_00515756 size=34 ====

void FUN_00515756(void)

{
  undefined1 *in_stack_000000f0;
  
  if (in_stack_000000f0 != &DAT_011c5338) {
    refcount_delete_offset10_c();
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00515778 name=FUN_00515778 size=34 ====

void FUN_00515778(void)

{
  undefined1 *in_stack_000000f0;
  
  if (in_stack_000000f0 != &DAT_011c5338) {
    refcount_delete_offset10_c();
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0051579a name=FUN_0051579a size=34 ====

void FUN_0051579a(void)

{
  undefined8 in_stack_00000010;
  
  qt_array_data_unref();
  qt_array_data_unref();
  qt_array_data_unref(in_stack_00000010);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=005157bc name=FUN_005157bc size=42 ====

void FUN_005157bc(void)

{
  undefined1 *in_stack_000000b0;
  
  qt_byte_array_unref();
  if (in_stack_000000b0 != &DAT_011c5338) {
    refcount_delete_offset10_c();
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=005157e6 name=FUN_005157e6 size=16 ====

void FUN_005157e6(void)

{
  FUN_0096bb02();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=005157f6 name=FUN_005157f6 size=23 ====

void FUN_005157f6(void)

{
  QVariant *in_stack_00000010;
  undefined8 in_stack_00000018;
  
  qt_array_data_unref();
  QVariant::~QVariant(in_stack_00000010);
  qmap_freetree_variant_nodes(in_stack_00000018);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0051580d name=FUN_0051580d size=16 ====

void FUN_0051580d(void)

{
  FUN_0096bb02();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0051581d name=FUN_0051581d size=34 ====

void FUN_0051581d(void)

{
  undefined1 *in_stack_000000f0;
  
  if (in_stack_000000f0 != &DAT_011c5338) {
    refcount_delete_offset10_c();
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0051583f name=FUN_0051583f size=42 ====

void FUN_0051583f(void)

{
  undefined1 *in_stack_000000b0;
  
  qt_array_data_unref();
  if (in_stack_000000b0 != &DAT_011c5338) {
    refcount_delete_offset10_c();
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00515869 name=FUN_00515869 size=23 ====

void FUN_00515869(void)

{
  QVariant *in_stack_00000010;
  undefined8 in_stack_00000018;
  
  qt_array_data_unref();
  QVariant::~QVariant(in_stack_00000010);
  qmap_freetree_variant_nodes(in_stack_00000018);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00515880 name=FUN_00515880 size=23 ====

void FUN_00515880(void)

{
  QVariant *in_stack_00000010;
  undefined8 in_stack_00000018;
  
  qt_array_data_unref();
  QVariant::~QVariant(in_stack_00000010);
  qmap_freetree_variant_nodes(in_stack_00000018);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00515897 name=FUN_00515897 size=23 ====

void FUN_00515897(void)

{
  QVariant *in_stack_00000010;
  undefined8 in_stack_00000018;
  
  qt_array_data_unref();
  QVariant::~QVariant(in_stack_00000010);
  qmap_freetree_variant_nodes(in_stack_00000018);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=005158ae name=FUN_005158ae size=23 ====

void FUN_005158ae(void)

{
  QVariant *in_stack_00000010;
  undefined8 in_stack_00000018;
  
  qt_array_data_unref();
  QVariant::~QVariant(in_stack_00000010);
  qmap_freetree_variant_nodes(in_stack_00000018);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=005158c5 name=FUN_005158c5 size=16 ====

void FUN_005158c5(void)

{
  long *unaff_R12;
  undefined8 in_stack_00000010;
  undefined8 in_stack_00000020;
  
  (**(code **)(*unaff_R12 + 8))();
  qt_array_data_unref(in_stack_00000010);
  qatomic_unref_call_deleter(in_stack_00000020);
  qatomic_unref_call_deleter(&stack0x00000060);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=005158d5 name=FUN_005158d5 size=24 ====

void FUN_005158d5(void)

{
  qt_array_data_unref();
  qt_shared_data_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=005158ed name=FUN_005158ed size=42 ====

void FUN_005158ed(void)

{
  undefined1 *in_stack_000000f0;
  
  if (in_stack_000000f0 != &DAT_011c5338) {
    refcount_delete_offset10_c();
  }
  qt_byte_array_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00515917 name=FUN_00515917 size=24 ====

void FUN_00515917(void)

{
  FUN_0096bb02();
  FUN_00963b22();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0051592f name=FUN_0051592f size=24 ====

void FUN_0051592f(void)

{
  qt_array_data_unref();
  qt_shared_data_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00515947 name=FUN_00515947 size=34 ====

void FUN_00515947(void)

{
  undefined1 *in_stack_000000f0;
  
  if (in_stack_000000f0 != &DAT_011c5338) {
    refcount_delete_offset10_c();
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00515969 name=FUN_00515969 size=16 ====

void FUN_00515969(void)

{
  QPixmap *unaff_R13;
  
  QPixmap::~QPixmap(unaff_R13);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00515979 name=FUN_00515979 size=16 ====

void FUN_00515979(void)

{
  qt_array_data_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00515989 name=FUN_00515989 size=24 ====

void FUN_00515989(void)

{
  FUN_0096bb02();
  qt_byte_array_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=005159a1 name=FUN_005159a1 size=24 ====

void FUN_005159a1(void)

{
  qt_array_data_unref();
  qt_array_data_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=005159b9 name=FUN_005159b9 size=16 ====

void FUN_005159b9(void)

{
  QPixmap *unaff_R13;
  
  QPixmap::~QPixmap(unaff_R13);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=005159c9 name=FUN_005159c9 size=24 ====

void FUN_005159c9(void)

{
  FUN_0096bb02();
  FUN_0096bb02();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=005159e1 name=FUN_005159e1 size=16 ====

void FUN_005159e1(void)

{
  FUN_0096bb02();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=005159f1 name=FUN_005159f1 size=24 ====

void FUN_005159f1(void)

{
  FUN_0096bb02();
  FUN_0096bb02();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00515a09 name=FUN_00515a09 size=16 ====

void FUN_00515a09(void)

{
  FUN_0096bb02();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00515a19 name=FUN_00515a19 size=35 ====

void FUN_00515a19(void)

{
  undefined1 *in_stack_000000f0;
  
  if (in_stack_000000f0 != &DAT_011c5338) {
    refcount_delete_offset10_c();
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00515a3c name=FUN_00515a3c size=34 ====

void FUN_00515a3c(void)

{
  undefined1 *in_stack_000000f0;
  
  if (in_stack_000000f0 != &DAT_011c5338) {
    refcount_delete_offset10_c();
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00515a5e name=FUN_00515a5e size=16 ====

void FUN_00515a5e(void)

{
  qt_array_data_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00515a6e name=FUN_00515a6e size=16 ====

void FUN_00515a6e(void)

{
  qt_array_data_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00515a7e name=FUN_00515a7e size=24 ====

void FUN_00515a7e(void)

{
  qatomic_unref_call_deleter();
  FUN_0096bb02();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00515a96 name=FUN_00515a96 size=34 ====

void FUN_00515a96(void)

{
  undefined1 *in_stack_000000f0;
  
  if (in_stack_000000f0 != &DAT_011c5338) {
    refcount_delete_offset10_c();
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00515ab8 name=FUN_00515ab8 size=16 ====

void FUN_00515ab8(void)

{
  qt_byte_array_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00515ac8 name=FUN_00515ac8 size=16 ====

void FUN_00515ac8(void)

{
  FUN_0096bb02();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00515ad8 name=FUN_00515ad8 size=16 ====

void FUN_00515ad8(void)

{
  FUN_0096bb02();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00515ae8 name=FUN_00515ae8 size=34 ====

void FUN_00515ae8(void)

{
  undefined1 *in_stack_000000b0;
  
  if (in_stack_000000b0 != &DAT_011c5338) {
    refcount_delete_offset10_c();
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00515b0a name=FUN_00515b0a size=34 ====

void FUN_00515b0a(void)

{
  undefined8 in_stack_00000010;
  
  FUN_0096bd50();
  FUN_0096bb02(in_stack_00000010);
  FUN_0096bb02();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00515b2c name=FUN_00515b2c size=34 ====

void FUN_00515b2c(void)

{
  undefined1 *in_stack_000000f0;
  
  if (in_stack_000000f0 != &DAT_011c5338) {
    refcount_delete_offset10_c();
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00515b4e name=FUN_00515b4e size=42 ====

void FUN_00515b4e(void)

{
  undefined1 *in_stack_000000b0;
  
  qt_byte_array_unref();
  if (in_stack_000000b0 != &DAT_011c5338) {
    refcount_delete_offset10_c();
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00515b78 name=FUN_00515b78 size=16 ====

void FUN_00515b78(void)

{
  qt_array_data_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00515b88 name=FUN_00515b88 size=24 ====

void FUN_00515b88(void)

{
  FUN_0096bb02();
  FUN_0096bb02();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00515ba0 name=FUN_00515ba0 size=16 ====

void FUN_00515ba0(void)

{
  qt_byte_array_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00515bb0 name=FUN_00515bb0 size=16 ====

void FUN_00515bb0(void)

{
  qt_array_data_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00515bc0 name=FUN_00515bc0 size=24 ====

void FUN_00515bc0(void)

{
  qt_byte_array_unref();
  qt_byte_array_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00515bd8 name=FUN_00515bd8 size=34 ====

void FUN_00515bd8(void)

{
  undefined1 *in_stack_000000f0;
  
  if (in_stack_000000f0 != &DAT_011c5338) {
    refcount_delete_offset10_c();
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00515bfa name=FUN_00515bfa size=34 ====

void FUN_00515bfa(void)

{
  undefined1 *in_stack_000000f0;
  
  if (in_stack_000000f0 != &DAT_011c5338) {
    refcount_delete_offset10_c();
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00515c3a name=FUN_00515c3a size=16 ====

void FUN_00515c3a(void)

{
  FUN_0096bb02();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00515c4a name=FUN_00515c4a size=34 ====

void FUN_00515c4a(void)

{
  undefined8 in_stack_00000010;
  
  FUN_0096bd50();
  FUN_0096bb02(in_stack_00000010);
  FUN_0096bb02();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00515c6c name=FUN_00515c6c size=16 ====

void FUN_00515c6c(void)

{
  FUN_0096bb02();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00515c7c name=FUN_00515c7c size=21 ====

void FUN_00515c7c(void)

{
  void *unaff_RBP;
  
  operator_delete(unaff_RBP,0x1030);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00515c92 name=FUN_00515c92 size=21 ====

void FUN_00515c92(void)

{
  void *unaff_RBP;
  
  operator_delete(unaff_RBP,0x1030);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00515ca8 name=FUN_00515ca8 size=21 ====

void FUN_00515ca8(void)

{
  void *unaff_RBP;
  
  operator_delete(unaff_RBP,0x30);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00515cbe name=FUN_00515cbe size=58 ====

void FUN_00515cbe(void)

{
  QArrayData *in_stack_000000c0;
  
  if (*(int *)in_stack_000000c0 != 0) {
    if (*(int *)in_stack_000000c0 == -1) goto LAB_00515cdb;
    LOCK();
    *(int *)in_stack_000000c0 = *(int *)in_stack_000000c0 + -1;
    UNLOCK();
    if (*(int *)in_stack_000000c0 != 0) goto LAB_00515cdb;
  }
  QArrayData::deallocate(in_stack_000000c0,2,8);
LAB_00515cdb:
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00515d00 name=FUN_00515d00 size=29 ====

void FUN_00515d00(int *param_1)

{
  int *piVar1;
  
  LOCK();
  piVar1 = param_1 + 1;
  *piVar1 = *piVar1 + -1;
  UNLOCK();
  if (*piVar1 == 0) {
    (**(code **)(param_1 + 2))();
  }
  LOCK();
  *param_1 = *param_1 + -1;
  UNLOCK();
  if (*param_1 == 0) {
    operator_delete(param_1);
    return;
  }
  return;
}


// ==== entry=00515d1e orig=FUN_00515d1e size=39 name=refcount_releaseDelete2 ====

/* WARNING: Removing unreachable block (ram,0x00515d32) */

void refcount_releaseDelete2(void *param_1)

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


// ==== entry=00515d46 name=FUN_00515d46 size=27 ====

void FUN_00515d46(void)

{
  FUN_00a73f6c();
  FUN_00a2bf50();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00515d62 name=FUN_00515d62 size=42 ====

void FUN_00515d62(void)

{
  QVariant *unaff_R12;
  undefined8 in_stack_00000018;
  
  QVariant::~QVariant(unaff_R12);
  qt_byte_array_unref();
  qt_byte_array_unref(in_stack_00000018);
  FUN_00515d00();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00515d8c name=FUN_00515d8c size=25 ====

void FUN_00515d8c(void)

{
  long in_stack_00000038;
  
  if (in_stack_00000038 != 0) {
    FUN_00515d00();
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00515da6 name=FUN_00515da6 size=16 ====

void FUN_00515da6(void)

{
  qt_array_data_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00515db6 name=FUN_00515db6 size=23 ====

void FUN_00515db6(void)

{
  long in_stack_00000038;
  
  if (in_stack_00000038 != 0) {
    FUN_00515d00();
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00515dcd name=FUN_00515dcd size=42 ====

void FUN_00515dcd(void)

{
  QVariant *unaff_R12;
  undefined8 in_stack_00000018;
  
  QVariant::~QVariant(unaff_R12);
  qt_byte_array_unref();
  qt_byte_array_unref(in_stack_00000018);
  FUN_00515d00();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00515df8 name=FUN_00515df8 size=16 ====

void FUN_00515df8(void)

{
  FUN_00515d00();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00515e08 name=FUN_00515e08 size=26 ====

void FUN_00515e08(void)

{
  long in_stack_00000008;
  
  if (in_stack_00000008 != 0) {
    FUN_00515d00();
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00515e22 name=FUN_00515e22 size=31 ====

void FUN_00515e22(void)

{
  undefined1 *in_stack_00000030;
  
  if (in_stack_00000030 != &DAT_011c5338) {
    refcount_releaseDelete2();
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00515e41 name=FUN_00515e41 size=21 ====

void FUN_00515e41(void)

{
  void *unaff_RBP;
  
  operator_delete(unaff_RBP,0x40);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00515e56 name=FUN_00515e56 size=21 ====

void FUN_00515e56(void)

{
  void *unaff_RBP;
  
  operator_delete(unaff_RBP,0x50);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00515e6c name=FUN_00515e6c size=31 ====

void FUN_00515e6c(void)

{
  undefined1 *in_stack_00000060;
  
  if (in_stack_00000060 != &DAT_011c5338) {
    refcount_releaseDelete2();
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00515e8b name=FUN_00515e8b size=16 ====

void FUN_00515e8b(void)

{
  Window_metaObject();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00515e9b name=FUN_00515e9b size=16 ====

void FUN_00515e9b(void)

{
  FUN_0096bb02();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00515eab name=FUN_00515eab size=16 ====

void FUN_00515eab(void)

{
  FUN_0096bb02();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00515ebc name=FUN_00515ebc size=31 ====

void FUN_00515ebc(void)

{
  undefined1 *in_stack_00000070;
  
  if (in_stack_00000070 != &DAT_011c5338) {
    refcount_releaseDelete2();
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00515edc name=FUN_00515edc size=31 ====

void FUN_00515edc(void)

{
  undefined1 *in_stack_00000008;
  
  if (in_stack_00000008 != &DAT_011c5338) {
    refcount_releaseDelete2();
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00515efc name=FUN_00515efc size=39 ====

void FUN_00515efc(void)

{
  long in_stack_00000020;
  long in_stack_00000050;
  long in_stack_00000068;
  
  FUN_0096bb02();
  FUN_009cff96();
  if (in_stack_00000068 + -0x18 != in_stack_00000020) {
    refcount_releaseDelete2();
  }
  if (in_stack_00000050 + -0x18 != in_stack_00000020) {
    refcount_releaseDelete2();
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00515f23 name=FUN_00515f23 size=69 ====

void FUN_00515f23(void)

{
  long in_stack_00000020;
  long in_stack_00000050;
  long in_stack_00000080;
  
  if (in_stack_00000080 + -0x18 != in_stack_00000020) {
    refcount_releaseDelete2();
  }
  FUN_009cff96();
  if (in_stack_00000050 + -0x18 != in_stack_00000020) {
    refcount_releaseDelete2();
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00515f5b name=FUN_00515f5b size=10 ====

void FUN_00515f5b(void)

{
  long in_stack_00000020;
  long in_stack_00000050;
  long in_stack_00000068;
  
  FUN_0096bb02();
  if (in_stack_00000068 + -0x18 != in_stack_00000020) {
    refcount_releaseDelete2();
  }
  if (in_stack_00000050 + -0x18 != in_stack_00000020) {
    refcount_releaseDelete2();
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00515f72 name=FUN_00515f72 size=10 ====

void FUN_00515f72(void)

{
  long in_stack_00000020;
  long in_stack_00000050;
  
  qt_byte_array_unref();
  if (in_stack_00000050 + -0x18 != in_stack_00000020) {
    refcount_releaseDelete2();
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00515f7c name=FUN_00515f7c size=59 ====

void FUN_00515f7c(void)

{
  QVariant *unaff_RBP;
  long in_stack_00000020;
  undefined8 in_stack_00000030;
  undefined8 in_stack_00000038;
  undefined8 in_stack_00000048;
  long in_stack_00000050;
  
  QVariant::~QVariant(unaff_RBP);
  qt_byte_array_unref(in_stack_00000038);
  qt_byte_array_unref();
  FUN_00515d00();
  qt_byte_array_unref(in_stack_00000030);
  qt_byte_array_unref(in_stack_00000048);
  if (in_stack_00000050 + -0x18 != in_stack_00000020) {
    refcount_releaseDelete2();
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00515fb7 name=FUN_00515fb7 size=14 ====

void FUN_00515fb7(void)

{
  long in_stack_00000020;
  long in_stack_00000050;
  
  FUN_0096bb02();
  FUN_009cff96();
  if (in_stack_00000050 + -0x18 != in_stack_00000020) {
    refcount_releaseDelete2();
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00515fc5 name=FUN_00515fc5 size=20 ====

void FUN_00515fc5(void)

{
  long in_stack_00000020;
  undefined8 in_stack_00000030;
  undefined8 in_stack_00000048;
  long in_stack_00000050;
  long in_stack_00000088;
  
  if (in_stack_00000088 != 0) {
    FUN_00515d00();
  }
  qt_byte_array_unref(in_stack_00000030);
  qt_byte_array_unref(in_stack_00000048);
  if (in_stack_00000050 + -0x18 != in_stack_00000020) {
    refcount_releaseDelete2();
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00515fd9 name=FUN_00515fd9 size=33 ====

void FUN_00515fd9(void)

{
  long in_stack_00000020;
  long in_stack_00000050;
  long in_stack_00000080;
  
  if (in_stack_00000080 + -0x18 != in_stack_00000020) {
    refcount_releaseDelete2();
  }
  if (in_stack_00000050 + -0x18 != in_stack_00000020) {
    refcount_releaseDelete2();
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00515ffa name=FUN_00515ffa size=16 ====

void FUN_00515ffa(void)

{
  long in_stack_00000020;
  long in_stack_00000050;
  long in_stack_00000068;
  
  FUN_0096bb02();
  FUN_009cff96();
  if (in_stack_00000068 + -0x18 != in_stack_00000020) {
    refcount_releaseDelete2();
  }
  if (in_stack_00000050 + -0x18 != in_stack_00000020) {
    refcount_releaseDelete2();
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0051600a name=FUN_0051600a size=35 ====

void FUN_0051600a(void)

{
  long unaff_R13;
  long in_stack_00000048;
  
  qt_byte_array_unref();
  if (in_stack_00000048 + -0x18 != unaff_R13) {
    refcount_releaseDelete2();
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0051602d name=FUN_0051602d size=59 ====

void FUN_0051602d(void)

{
  QVariant *unaff_RBP;
  long unaff_R13;
  undefined8 in_stack_00000028;
  undefined8 in_stack_00000030;
  undefined8 in_stack_00000038;
  long in_stack_00000048;
  
  QVariant::~QVariant(unaff_RBP);
  qt_byte_array_unref(in_stack_00000028);
  qt_byte_array_unref();
  FUN_00515d00();
  qt_byte_array_unref(in_stack_00000030);
  qt_byte_array_unref(in_stack_00000038);
  if (in_stack_00000048 + -0x18 != unaff_R13) {
    refcount_releaseDelete2();
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00516068 name=FUN_00516068 size=17 ====

void FUN_00516068(void)

{
  long unaff_R13;
  undefined8 in_stack_00000030;
  undefined8 in_stack_00000038;
  long in_stack_00000048;
  long in_stack_00000078;
  
  if (in_stack_00000078 != 0) {
    FUN_00515d00();
  }
  qt_byte_array_unref(in_stack_00000030);
  qt_byte_array_unref(in_stack_00000038);
  if (in_stack_00000048 + -0x18 != unaff_R13) {
    refcount_releaseDelete2();
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0051607a name=FUN_0051607a size=18 ====

void FUN_0051607a(void)

{
  undefined8 in_stack_00000010;
  
  FUN_0096bb02(in_stack_00000010);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0051608c name=FUN_0051608c size=16 ====

void FUN_0051608c(void)

{
  qt_array_data_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0051609c name=FUN_0051609c size=16 ====

void FUN_0051609c(void)

{
  FUN_0096bb02();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=005160b0 name=FUN_005160b0 size=16 ====

void FUN_005160b0(void)

{
  FUN_0096bb02();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=005160c0 name=FUN_005160c0 size=24 ====

void FUN_005160c0(void)

{
  FUN_0096bb02();
  FUN_0096bb02();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=005160d8 name=FUN_005160d8 size=10 ====

void FUN_005160d8(void)

{
  FUN_0096bb02();
  FUN_0096bb02();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=005160e2 name=FUN_005160e2 size=16 ====

void FUN_005160e2(void)

{
  FUN_0096bb02();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=005160f2 name=FUN_005160f2 size=16 ====

void FUN_005160f2(void)

{
  QFontMetricsF *unaff_RBP;
  
  QFontMetricsF::~QFontMetricsF(unaff_RBP);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00516102 name=FUN_00516102 size=16 ====

void FUN_00516102(void)

{
  FUN_0096bb02();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00516112 name=FUN_00516112 size=26 ====

void FUN_00516112(void)

{
  qt_array_data_unref(&stack0x00000020);
  qt_array_data_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00516130 name=FUN_00516130 size=16 ====

void FUN_00516130(void)

{
  FUN_0096bb02();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00516140 name=FUN_00516140 size=16 ====

void FUN_00516140(void)

{
  FUN_0096bb02();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00516150 name=FUN_00516150 size=16 ====

void FUN_00516150(void)

{
  FUN_0096bb02();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00516160 name=FUN_00516160 size=16 ====

void FUN_00516160(void)

{
  FUN_0096bb02();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00516170 name=FUN_00516170 size=16 ====

void FUN_00516170(void)

{
  FUN_0096bb02();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00516180 name=FUN_00516180 size=16 ====

void FUN_00516180(void)

{
  FUN_0096bb02();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00516190 name=FUN_00516190 size=39 ====

void FUN_00516190(void)

{
  undefined8 *unaff_RBX;
  
  __cxa_begin_catch();
  if ((void *)*unaff_RBX != (void *)0x0) {
    operator_delete((void *)*unaff_RBX);
  }
  operator_delete(unaff_RBX,0x18);
                    /* WARNING: Subroutine does not return */
                    /* try { // try from 005161b2 to 005161b6 has its CatchHandler @ 005161b7 */
  __cxa_rethrow();
}


// ==== entry=005161c8 name=FUN_005161c8 size=24 ====

void FUN_005161c8(void)

{
  FUN_0096bb02();
  FUN_0096bb02();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=005161e0 name=FUN_005161e0 size=24 ====

void FUN_005161e0(void)

{
  FUN_0096bb02();
  FUN_0096bb02();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=005161f8 name=FUN_005161f8 size=24 ====

void FUN_005161f8(void)

{
  FUN_0096bb02();
  FUN_0096bb02();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00516210 name=FUN_00516210 size=24 ====

void FUN_00516210(void)

{
  FUN_0096bb02();
  FUN_0096bb02();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00516228 name=FUN_00516228 size=24 ====

void FUN_00516228(void)

{
  FUN_0096bb02();
  FUN_0096bb02();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00516240 name=FUN_00516240 size=24 ====

void FUN_00516240(void)

{
  FUN_0096bb02();
  FUN_0096bb02();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00516258 name=FUN_00516258 size=24 ====

void FUN_00516258(void)

{
  FUN_0096bb02();
  FUN_0096bb02();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00516270 name=FUN_00516270 size=16 ====

void FUN_00516270(void)

{
  FUN_0096bb02();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00516280 name=FUN_00516280 size=23 ====

void FUN_00516280(void)

{
  void *in_stack_00000048;
  
  if (in_stack_00000048 != (void *)0x0) {
    operator_delete(in_stack_00000048);
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00516298 name=FUN_00516298 size=26 ====

void FUN_00516298(void)

{
  undefined8 in_stack_00000008;
  
  FUN_0096bb02();
  FUN_0096bb02(in_stack_00000008);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=005162b2 name=FUN_005162b2 size=11 ====

void FUN_005162b2(void)

{
  undefined8 unaff_retaddr;
  undefined8 in_stack_00000008;
  
  FUN_0096bb02(unaff_retaddr);
  FUN_0096bb02(in_stack_00000008);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=005162bd name=FUN_005162bd size=11 ====

void FUN_005162bd(void)

{
  undefined8 unaff_retaddr;
  undefined8 in_stack_00000008;
  
  FUN_0096bb02(unaff_retaddr);
  FUN_0096bb02(in_stack_00000008);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=005162c8 name=FUN_005162c8 size=10 ====

void FUN_005162c8(void)

{
  undefined8 in_stack_00000008;
  
  FUN_0096bb02();
  FUN_0096bb02(in_stack_00000008);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=005162d2 name=FUN_005162d2 size=10 ====

void FUN_005162d2(void)

{
  undefined8 in_stack_00000008;
  
  FUN_0096bb02();
  FUN_0096bb02(in_stack_00000008);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=005162dc name=FUN_005162dc size=10 ====

void FUN_005162dc(void)

{
  undefined8 in_stack_00000008;
  
  FUN_0096bb02();
  FUN_0096bb02(in_stack_00000008);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=005162e6 name=FUN_005162e6 size=12 ====

void FUN_005162e6(void)

{
  undefined8 in_stack_00000008;
  
  FUN_0096bb02();
  FUN_0096bb02(in_stack_00000008);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=005162f2 name=FUN_005162f2 size=10 ====

void FUN_005162f2(void)

{
  undefined8 in_stack_00000008;
  
  FUN_0096bb02();
  FUN_0096bb02(in_stack_00000008);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=005162fc name=FUN_005162fc size=10 ====

void FUN_005162fc(void)

{
  undefined8 in_stack_00000008;
  
  FUN_0096bb02();
  FUN_0096bb02(in_stack_00000008);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00516306 name=FUN_00516306 size=12 ====

void FUN_00516306(void)

{
  undefined8 in_stack_00000008;
  
  FUN_0096bb02();
  FUN_0096bb02(in_stack_00000008);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00516312 name=FUN_00516312 size=10 ====

void FUN_00516312(void)

{
  undefined8 in_stack_00000008;
  
  FUN_0096bb02();
  FUN_0096bb02(in_stack_00000008);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0051631c name=FUN_0051631c size=13 ====

void FUN_0051631c(void)

{
  undefined8 in_stack_00000008;
  
  FUN_0096bb02();
  FUN_0096bb02(in_stack_00000008);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00516329 name=FUN_00516329 size=13 ====

void FUN_00516329(void)

{
  undefined8 in_stack_00000008;
  
  FUN_0096bb02();
  FUN_0096bb02(in_stack_00000008);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00516336 name=FUN_00516336 size=15 ====

void FUN_00516336(void)

{
  undefined8 in_stack_00000008;
  
  FUN_0096bb02();
  FUN_0096bb02(in_stack_00000008);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00516345 name=FUN_00516345 size=16 ====

void FUN_00516345(void)

{
  undefined8 in_stack_00000008;
  
  FUN_0096bb02();
  FUN_0096bb02(in_stack_00000008);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00516355 name=FUN_00516355 size=16 ====

void FUN_00516355(void)

{
  undefined8 in_stack_00000008;
  
  FUN_0096bb02();
  FUN_0096bb02(in_stack_00000008);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00516365 name=FUN_00516365 size=16 ====

void FUN_00516365(void)

{
  undefined8 in_stack_00000008;
  
  FUN_0096bb02();
  FUN_0096bb02(in_stack_00000008);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00516375 name=FUN_00516375 size=16 ====

void FUN_00516375(void)

{
  undefined8 in_stack_00000008;
  
  FUN_0096bb02();
  FUN_0096bb02(in_stack_00000008);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00516385 name=FUN_00516385 size=16 ====

void FUN_00516385(void)

{
  undefined8 in_stack_00000008;
  
  FUN_0096bb02();
  FUN_0096bb02(in_stack_00000008);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00516395 name=FUN_00516395 size=16 ====

void FUN_00516395(void)

{
  undefined8 in_stack_00000008;
  
  FUN_0096bb02();
  FUN_0096bb02(in_stack_00000008);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=005163a5 name=FUN_005163a5 size=27 ====

void FUN_005163a5(void)

{
  char unaff_BPL;
  undefined8 in_stack_00000008;
  
  if (unaff_BPL != '\0') {
    FUN_0096bb02(&stack0x00000290);
  }
  FUN_0096bb02(in_stack_00000008);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=005163c0 name=FUN_005163c0 size=13 ====

void FUN_005163c0(void)

{
  undefined8 in_stack_00000008;
  
  FUN_0096bb02();
  FUN_0096bb02(in_stack_00000008);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=005163cd name=FUN_005163cd size=29 ====

void FUN_005163cd(void)

{
  undefined8 in_stack_00000008;
  undefined8 in_stack_00000018;
  
  if (in_stack_00000018._6_1_ != '\0') {
    FUN_0096bb02(&stack0x00000290);
  }
  FUN_0096bb02(in_stack_00000008);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=005163ea name=FUN_005163ea size=14 ====

void FUN_005163ea(void)

{
  undefined8 unaff_retaddr;
  undefined8 in_stack_00000008;
  
  FUN_0096bb02(unaff_retaddr);
  FUN_0096bb02(in_stack_00000008);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=005163f8 name=FUN_005163f8 size=28 ====

void FUN_005163f8(void)

{
  undefined8 in_stack_00000030;
  undefined8 in_stack_00000050;
  
  FUN_0096bb02(in_stack_00000030);
  FUN_00974856(in_stack_00000050);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00516414 name=FUN_00516414 size=22 ====

void FUN_00516414(void)

{
  undefined8 in_stack_00000028;
  undefined8 in_stack_00000030;
  undefined8 in_stack_00000050;
  
  FUN_0096bb02(in_stack_00000030);
  FUN_0096bb02(in_stack_00000028);
  FUN_00974856(in_stack_00000050);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0051642a name=FUN_0051642a size=12 ====

void FUN_0051642a(void)

{
  undefined8 in_stack_00000030;
  undefined8 in_stack_00000050;
  
  FUN_0096bb02(in_stack_00000030);
  FUN_00974856(in_stack_00000050);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00516436 name=FUN_00516436 size=12 ====

void FUN_00516436(void)

{
  undefined8 in_stack_00000030;
  undefined8 in_stack_00000050;
  
  FUN_0096bb02(in_stack_00000030);
  FUN_00974856(in_stack_00000050);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00516442 name=FUN_00516442 size=46 ====

void FUN_00516442(void)

{
  undefined8 in_stack_00000020;
  undefined8 in_stack_00000038;
  void *in_stack_000000d8;
  
  FUN_0096bb02(in_stack_00000020);
  if (in_stack_000000d8 != (void *)0x0) {
    operator_delete(in_stack_000000d8);
  }
  FUN_00974856(in_stack_00000038);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00516470 name=FUN_00516470 size=27 ====

void FUN_00516470(void)

{
  char unaff_R15B;
  undefined8 in_stack_00000020;
  undefined8 in_stack_00000038;
  undefined8 in_stack_00000048;
  void *in_stack_000000d8;
  
  FUN_0096bb02(in_stack_00000020);
  if (unaff_R15B != '\0') {
    FUN_0096bb02(in_stack_00000048);
  }
  if (in_stack_000000d8 != (void *)0x0) {
    operator_delete(in_stack_000000d8);
  }
  FUN_00974856(in_stack_00000038);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0051648b name=FUN_0051648b size=30 ====

void FUN_0051648b(void)

{
  undefined8 in_stack_00000020;
  undefined8 in_stack_00000038;
  void *in_stack_000000d8;
  
  FUN_0096bb02(in_stack_00000020);
  if (in_stack_000000d8 != (void *)0x0) {
    operator_delete(in_stack_000000d8);
  }
  FUN_00974856(in_stack_00000038);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=005164a9 name=FUN_005164a9 size=22 ====

void FUN_005164a9(void)

{
  undefined8 in_stack_00000010;
  undefined8 in_stack_00000020;
  undefined8 in_stack_00000038;
  
  FUN_0096bb02(in_stack_00000010);
  FUN_0096bb02(in_stack_00000020);
  FUN_00974856(in_stack_00000038);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=005164c0 name=FUN_005164c0 size=88 ====

void FUN_005164c0(void)

{
  undefined8 in_stack_00000010;
  undefined8 in_stack_00000028;
  void *in_stack_00000090;
  void *in_stack_00000118;
  undefined8 in_stack_00000140;
  
  FUN_0096bd50();
  FUN_0096bb02();
  FUN_0096bb02(in_stack_00000028);
  if (in_stack_00000090 != (void *)0x0) {
    operator_delete(in_stack_00000090);
  }
  if (in_stack_00000118 != (void *)0x0) {
    operator_delete(in_stack_00000118);
  }
  FUN_00a53800(in_stack_00000010,in_stack_00000140);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00516518 name=FUN_00516518 size=63 ====

void FUN_00516518(void)

{
  undefined8 in_stack_00000010;
  undefined8 in_stack_00000018;
  undefined8 in_stack_00000028;
  void *in_stack_00000070;
  void *in_stack_000000f8;
  undefined8 in_stack_00000140;
  
  FUN_0096bd50();
  FUN_0096bb02(in_stack_00000018);
  FUN_0096bb02(in_stack_00000028);
  if (in_stack_00000070 != (void *)0x0) {
    operator_delete(in_stack_00000070);
  }
  if (in_stack_000000f8 != (void *)0x0) {
    operator_delete(in_stack_000000f8);
  }
  FUN_00a53800(in_stack_00000010,in_stack_00000140);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00516557 name=FUN_00516557 size=68 ====

void FUN_00516557(void)

{
  undefined8 in_stack_00000010;
  undefined8 in_stack_00000018;
  void *in_stack_00000050;
  void *in_stack_000000d8;
  undefined8 in_stack_00000140;
  
  FUN_0096bd50();
  FUN_0096bb02(in_stack_00000018);
  FUN_0096bb02();
  if (in_stack_00000050 != (void *)0x0) {
    operator_delete(in_stack_00000050);
  }
  if (in_stack_000000d8 != (void *)0x0) {
    operator_delete(in_stack_000000d8);
  }
  FUN_00a53800(in_stack_00000010,in_stack_00000140);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0051659b name=FUN_0051659b size=33 ====

void FUN_0051659b(void)

{
  undefined8 in_stack_00000010;
  undefined8 in_stack_00000028;
  void *in_stack_00000090;
  void *in_stack_00000118;
  undefined8 in_stack_00000140;
  
  FUN_0096bd50();
  FUN_0096bb02();
  FUN_0096bb02(in_stack_00000028);
  if (in_stack_00000090 != (void *)0x0) {
    operator_delete(in_stack_00000090);
  }
  if (in_stack_00000118 != (void *)0x0) {
    operator_delete(in_stack_00000118);
  }
  FUN_00a53800(in_stack_00000010,in_stack_00000140);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=005165bc name=FUN_005165bc size=28 ====

void FUN_005165bc(void)

{
  undefined8 in_stack_00000010;
  undefined8 in_stack_00000018;
  void *in_stack_00000050;
  void *in_stack_000000d8;
  undefined8 in_stack_00000140;
  
  FUN_0096bd50();
  FUN_0096bb02(in_stack_00000018);
  FUN_0096bb02();
  if (in_stack_00000050 != (void *)0x0) {
    operator_delete(in_stack_00000050);
  }
  if (in_stack_000000d8 != (void *)0x0) {
    operator_delete(in_stack_000000d8);
  }
  FUN_00a53800(in_stack_00000010,in_stack_00000140);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=005165d8 name=FUN_005165d8 size=68 ====

void FUN_005165d8(void)

{
  undefined8 in_stack_00000010;
  undefined8 in_stack_00000018;
  void *in_stack_00000030;
  void *in_stack_000000b8;
  undefined8 in_stack_00000140;
  
  FUN_0096bd50();
  FUN_0096bb02(in_stack_00000018);
  FUN_0096bb02();
  if (in_stack_00000030 != (void *)0x0) {
    operator_delete(in_stack_00000030);
  }
  if (in_stack_000000b8 != (void *)0x0) {
    operator_delete(in_stack_000000b8);
  }
  FUN_00a53800(in_stack_00000010,in_stack_00000140);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0051661c name=FUN_0051661c size=34 ====

void FUN_0051661c(void)

{
  undefined8 in_stack_00000010;
  undefined8 in_stack_00000018;
  undefined8 in_stack_00000028;
  void *in_stack_00000070;
  void *in_stack_000000f8;
  undefined8 in_stack_00000140;
  
  FUN_0096bd50();
  FUN_0096bb02(in_stack_00000018);
  FUN_0096bb02(in_stack_00000028);
  if (in_stack_00000070 != (void *)0x0) {
    operator_delete(in_stack_00000070);
  }
  if (in_stack_000000f8 != (void *)0x0) {
    operator_delete(in_stack_000000f8);
  }
  FUN_00a53800(in_stack_00000010,in_stack_00000140);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0051663e name=FUN_0051663e size=31 ====

void FUN_0051663e(void)

{
  undefined8 in_stack_00000010;
  undefined8 in_stack_00000018;
  undefined8 in_stack_00000140;
  
  FUN_0096bb02();
  FUN_0096bb02(in_stack_00000018);
  FUN_0096bd50();
  FUN_00a53800(in_stack_00000010,in_stack_00000140);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0051665d name=FUN_0051665d size=23 ====

void FUN_0051665d(void)

{
  undefined8 in_stack_00000010;
  undefined8 in_stack_00000018;
  undefined8 in_stack_00000140;
  
  FUN_0096bb02();
  FUN_0096bb02(in_stack_00000018);
  FUN_00a53800(in_stack_00000010,in_stack_00000140);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00516674 name=FUN_00516674 size=31 ====

void FUN_00516674(void)

{
  undefined8 in_stack_00000010;
  undefined8 in_stack_00000018;
  void *in_stack_00000030;
  void *in_stack_000000b8;
  undefined8 in_stack_00000140;
  
  FUN_0096bd50();
  FUN_0096bb02(in_stack_00000018);
  FUN_0096bb02();
  if (in_stack_00000030 != (void *)0x0) {
    operator_delete(in_stack_00000030);
  }
  if (in_stack_000000b8 != (void *)0x0) {
    operator_delete(in_stack_000000b8);
  }
  FUN_00a53800(in_stack_00000010,in_stack_00000140);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00516694 name=FUN_00516694 size=50 ====

void FUN_00516694(void)

{
  undefined8 in_stack_00000010;
  undefined8 in_stack_00000140;
  
  FUN_0096bd50();
  FUN_0096bb02();
  FUN_0096bb02();
  FUN_00a5a850(in_stack_00000010,in_stack_00000140);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=005166c6 name=FUN_005166c6 size=21 ====

void FUN_005166c6(void)

{
  undefined8 in_stack_00000010;
  undefined8 in_stack_00000140;
  
  FUN_0096bd50();
  FUN_0096bb02();
  FUN_0096bb02();
  FUN_00a5a850(in_stack_00000010,in_stack_00000140);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=005166db name=FUN_005166db size=21 ====

void FUN_005166db(void)

{
  undefined8 in_stack_00000010;
  undefined8 in_stack_00000140;
  
  FUN_0096bd50();
  FUN_0096bb02();
  FUN_0096bb02();
  FUN_00a5a850(in_stack_00000010,in_stack_00000140);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=005166f0 name=FUN_005166f0 size=29 ====

void FUN_005166f0(void)

{
  undefined8 in_stack_00000010;
  undefined8 in_stack_00000140;
  
  FUN_0096bd50();
  FUN_0096bb02();
  FUN_0096bb02();
  FUN_00a5a850(in_stack_00000010,in_stack_00000140);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0051670d name=FUN_0051670d size=21 ====

void FUN_0051670d(void)

{
  undefined8 in_stack_00000010;
  undefined8 in_stack_00000140;
  
  FUN_0096bd50();
  FUN_0096bb02();
  FUN_0096bb02();
  FUN_00a5a850(in_stack_00000010,in_stack_00000140);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00516722 name=FUN_00516722 size=21 ====

void FUN_00516722(void)

{
  undefined8 in_stack_00000010;
  undefined8 in_stack_00000140;
  
  FUN_0096bb02();
  FUN_0096bb02();
  FUN_00a5a850(in_stack_00000010,in_stack_00000140);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00516737 name=FUN_00516737 size=31 ====

void FUN_00516737(void)

{
  undefined8 in_stack_00000008;
  undefined8 in_stack_00000010;
  undefined8 in_stack_00000140;
  
  FUN_0096bb02();
  FUN_0096bb02();
  FUN_0096bd50(in_stack_00000008);
  FUN_00a5a850(in_stack_00000010,in_stack_00000140);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00516756 name=FUN_00516756 size=21 ====

void FUN_00516756(void)

{
  undefined8 in_stack_00000010;
  undefined8 in_stack_00000140;
  
  FUN_0096bd50();
  FUN_0096bb02();
  FUN_0096bb02();
  FUN_00a5a850(in_stack_00000010,in_stack_00000140);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0051676b name=FUN_0051676b size=32 ====

void FUN_0051676b(void)

{
  undefined8 in_stack_00000010;
  undefined8 in_stack_00000140;
  
  FUN_0096bd50();
  FUN_0096bb02();
  FUN_0096bb02();
  FUN_00a5a850(in_stack_00000010,in_stack_00000140);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0051678b name=FUN_0051678b size=18 ====

void FUN_0051678b(void)

{
  undefined8 in_stack_00000010;
  undefined8 in_stack_00000140;
  
  FUN_0096bd50();
  FUN_0096bb02();
  FUN_0096bb02();
  FUN_00a5a850(in_stack_00000010,in_stack_00000140);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0051679e name=FUN_0051679e size=16 ====

void FUN_0051679e(void)

{
  FUN_0096bd50();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=005167ae name=FUN_005167ae size=26 ====

void FUN_005167ae(void)

{
  undefined8 in_stack_00000008;
  
  FUN_0096bd50();
  FUN_00974856(in_stack_00000008);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=005167c8 name=FUN_005167c8 size=63 ====

void FUN_005167c8(void)

{
  QRegularExpressionMatch *unaff_R12;
  long *unaff_R13;
  undefined8 in_stack_00000008;
  
  FUN_0096bb02();
  FUN_0096bb02();
  if (unaff_R13 != (long *)0x0) {
    (**(code **)(*unaff_R13 + 8))();
  }
  qt_array_data_unref(in_stack_00000008);
  QRegularExpressionMatch::~QRegularExpressionMatch(unaff_R12);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00516807 name=FUN_00516807 size=13 ====

void FUN_00516807(void)

{
  QRegularExpressionMatch *unaff_R12;
  long *unaff_R13;
  undefined8 in_stack_00000008;
  
  FUN_0096bb02();
  FUN_0096bb02();
  if (unaff_R13 != (long *)0x0) {
    (**(code **)(*unaff_R13 + 8))();
  }
  qt_array_data_unref(in_stack_00000008);
  QRegularExpressionMatch::~QRegularExpressionMatch(unaff_R12);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00516814 name=FUN_00516814 size=13 ====

void FUN_00516814(void)

{
  QRegularExpressionMatch *unaff_R12;
  long *unaff_R13;
  undefined8 in_stack_00000008;
  
  FUN_0096bb02();
  FUN_0096bb02();
  if (unaff_R13 != (long *)0x0) {
    (**(code **)(*unaff_R13 + 8))();
  }
  qt_array_data_unref(in_stack_00000008);
  QRegularExpressionMatch::~QRegularExpressionMatch(unaff_R12);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00516821 name=FUN_00516821 size=28 ====

void FUN_00516821(void)

{
  qt_array_data_unref();
  __cxa_guard_abort(&DAT_011c28c0);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0051683d name=FUN_0051683d size=15 ====

void FUN_0051683d(void)

{
  QRegularExpressionMatch *unaff_R12;
  void *unaff_R13;
  undefined8 in_stack_00000008;
  
  operator_delete(unaff_R13,0x68);
  qt_array_data_unref(in_stack_00000008);
  QRegularExpressionMatch::~QRegularExpressionMatch(unaff_R12);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0051684c name=FUN_0051684c size=10 ====

void FUN_0051684c(void)

{
  QRegularExpressionMatch *unaff_R12;
  
  qt_array_data_unref();
  QRegularExpressionMatch::~QRegularExpressionMatch(unaff_R12);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00516856 name=FUN_00516856 size=16 ====

void FUN_00516856(void)

{
  QRegularExpressionMatch *unaff_R12;
  long *unaff_R13;
  undefined8 in_stack_00000008;
  
  FUN_0096bb02();
  FUN_0096bb02();
  if (unaff_R13 != (long *)0x0) {
    (**(code **)(*unaff_R13 + 8))();
  }
  qt_array_data_unref(in_stack_00000008);
  QRegularExpressionMatch::~QRegularExpressionMatch(unaff_R12);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00516866 name=FUN_00516866 size=16 ====

void FUN_00516866(void)

{
  QRegularExpressionMatch *unaff_R12;
  long *unaff_R13;
  undefined8 in_stack_00000008;
  
  FUN_0096bb02();
  FUN_0096bb02();
  if (unaff_R13 != (long *)0x0) {
    (**(code **)(*unaff_R13 + 8))();
  }
  qt_array_data_unref(in_stack_00000008);
  QRegularExpressionMatch::~QRegularExpressionMatch(unaff_R12);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00516876 name=FUN_00516876 size=16 ====

void FUN_00516876(void)

{
  QRegularExpressionMatch *unaff_R12;
  long *unaff_R13;
  undefined8 in_stack_00000008;
  
  FUN_0096bb02();
  FUN_0096bb02();
  if (unaff_R13 != (long *)0x0) {
    (**(code **)(*unaff_R13 + 8))();
  }
  qt_array_data_unref(in_stack_00000008);
  QRegularExpressionMatch::~QRegularExpressionMatch(unaff_R12);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00516886 name=FUN_00516886 size=16 ====

void FUN_00516886(void)

{
  QRegularExpressionMatch *unaff_R12;
  long *unaff_R13;
  undefined8 in_stack_00000008;
  
  FUN_0096bb02();
  FUN_0096bb02();
  if (unaff_R13 != (long *)0x0) {
    (**(code **)(*unaff_R13 + 8))();
  }
  qt_array_data_unref(in_stack_00000008);
  QRegularExpressionMatch::~QRegularExpressionMatch(unaff_R12);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00516896 name=FUN_00516896 size=16 ====

void FUN_00516896(void)

{
  QRegularExpressionMatch *unaff_R12;
  long *unaff_R13;
  undefined8 in_stack_00000008;
  
  FUN_0096bb02();
  FUN_0096bb02();
  if (unaff_R13 != (long *)0x0) {
    (**(code **)(*unaff_R13 + 8))();
  }
  qt_array_data_unref(in_stack_00000008);
  QRegularExpressionMatch::~QRegularExpressionMatch(unaff_R12);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=005168a6 name=FUN_005168a6 size=16 ====

void FUN_005168a6(void)

{
  QRegularExpressionMatch *unaff_R12;
  long *unaff_R13;
  undefined8 in_stack_00000008;
  
  FUN_0096bb02();
  FUN_0096bb02();
  if (unaff_R13 != (long *)0x0) {
    (**(code **)(*unaff_R13 + 8))();
  }
  qt_array_data_unref(in_stack_00000008);
  QRegularExpressionMatch::~QRegularExpressionMatch(unaff_R12);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=005168b6 name=FUN_005168b6 size=51 ====

void FUN_005168b6(void)

{
  QVariant *unaff_RBX;
  QVariant *unaff_RBP;
  QRegularExpressionMatch *unaff_R12;
  long *unaff_R13;
  undefined8 unaff_retaddr;
  undefined8 in_stack_00000008;
  undefined8 in_stack_00000010;
  
  QVariant::~QVariant(unaff_RBX);
  qt_array_data_unref();
  QVariant::~QVariant(unaff_RBP);
  qmap_freetree_variant_nodes(unaff_retaddr);
  qatomic_unref_call_deleter(in_stack_00000010);
  if (unaff_R13 != (long *)0x0) {
    (**(code **)(*unaff_R13 + 8))();
  }
  qt_array_data_unref(in_stack_00000008);
  QRegularExpressionMatch::~QRegularExpressionMatch(unaff_R12);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=005168e9 name=FUN_005168e9 size=16 ====

void FUN_005168e9(void)

{
  QRegularExpressionMatch *unaff_R12;
  long *unaff_R13;
  undefined8 in_stack_00000008;
  
  FUN_0096bb02();
  FUN_0096bb02();
  if (unaff_R13 != (long *)0x0) {
    (**(code **)(*unaff_R13 + 8))();
  }
  qt_array_data_unref(in_stack_00000008);
  QRegularExpressionMatch::~QRegularExpressionMatch(unaff_R12);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=005168f9 name=FUN_005168f9 size=16 ====

void FUN_005168f9(void)

{
  QRegularExpressionMatch *unaff_R12;
  long *unaff_R13;
  undefined8 in_stack_00000008;
  
  FUN_0096bb02();
  FUN_0096bb02();
  if (unaff_R13 != (long *)0x0) {
    (**(code **)(*unaff_R13 + 8))();
  }
  qt_array_data_unref(in_stack_00000008);
  QRegularExpressionMatch::~QRegularExpressionMatch(unaff_R12);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00516909 name=FUN_00516909 size=38 ====

void FUN_00516909(void)

{
  QVariant *unaff_RBX;
  QVariant *unaff_RBP;
  QRegularExpressionMatch *unaff_R12;
  long *unaff_R13;
  undefined8 unaff_retaddr;
  undefined8 in_stack_00000008;
  undefined8 in_stack_00000010;
  
  QVariant::~QVariant(unaff_RBX);
  qt_array_data_unref();
  QVariant::~QVariant(unaff_RBP);
  qmap_freetree_variant_nodes(unaff_retaddr);
  qatomic_unref_call_deleter(in_stack_00000010);
  if (unaff_R13 != (long *)0x0) {
    (**(code **)(*unaff_R13 + 8))();
  }
  qt_array_data_unref(in_stack_00000008);
  QRegularExpressionMatch::~QRegularExpressionMatch(unaff_R12);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0051692f name=FUN_0051692f size=16 ====

void FUN_0051692f(void)

{
  QRegularExpressionMatch *unaff_R12;
  long *unaff_R13;
  undefined8 in_stack_00000008;
  
  qt_array_data_unref();
  if (unaff_R13 != (long *)0x0) {
    (**(code **)(*unaff_R13 + 8))();
  }
  qt_array_data_unref(in_stack_00000008);
  QRegularExpressionMatch::~QRegularExpressionMatch(unaff_R12);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0051693f name=FUN_0051693f size=41 ====

void FUN_0051693f(void)

{
  QVariant *unaff_RBX;
  QVariant *unaff_RBP;
  QRegularExpressionMatch *unaff_R12;
  long *unaff_R13;
  undefined8 unaff_retaddr;
  undefined8 in_stack_00000008;
  undefined8 in_stack_00000010;
  
  QVariant::~QVariant(unaff_RBX);
  qt_array_data_unref();
  QVariant::~QVariant(unaff_RBP);
  qmap_freetree_variant_nodes(unaff_retaddr);
  qatomic_unref_call_deleter(in_stack_00000010);
  if (unaff_R13 != (long *)0x0) {
    (**(code **)(*unaff_R13 + 8))();
  }
  qt_array_data_unref(in_stack_00000008);
  QRegularExpressionMatch::~QRegularExpressionMatch(unaff_R12);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00516968 name=FUN_00516968 size=41 ====

void FUN_00516968(void)

{
  QVariant *unaff_RBX;
  QVariant *unaff_RBP;
  QRegularExpressionMatch *unaff_R12;
  long *unaff_R13;
  undefined8 unaff_retaddr;
  undefined8 in_stack_00000008;
  undefined8 in_stack_00000010;
  
  QVariant::~QVariant(unaff_RBX);
  qt_array_data_unref();
  QVariant::~QVariant(unaff_RBP);
  qmap_freetree_variant_nodes(unaff_retaddr);
  qatomic_unref_call_deleter(in_stack_00000010);
  if (unaff_R13 != (long *)0x0) {
    (**(code **)(*unaff_R13 + 8))();
  }
  qt_array_data_unref(in_stack_00000008);
  QRegularExpressionMatch::~QRegularExpressionMatch(unaff_R12);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00516991 name=FUN_00516991 size=16 ====

void FUN_00516991(void)

{
  QRegularExpressionMatch *unaff_R12;
  long *unaff_R13;
  undefined8 in_stack_00000008;
  
  FUN_0096bb02();
  FUN_0096bb02();
  if (unaff_R13 != (long *)0x0) {
    (**(code **)(*unaff_R13 + 8))();
  }
  qt_array_data_unref(in_stack_00000008);
  QRegularExpressionMatch::~QRegularExpressionMatch(unaff_R12);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=005169a1 name=FUN_005169a1 size=16 ====

void FUN_005169a1(void)

{
  QRegularExpressionMatch *unaff_R12;
  long *unaff_R13;
  undefined8 in_stack_00000008;
  
  FUN_0096bb02();
  FUN_0096bb02();
  if (unaff_R13 != (long *)0x0) {
    (**(code **)(*unaff_R13 + 8))();
  }
  qt_array_data_unref(in_stack_00000008);
  QRegularExpressionMatch::~QRegularExpressionMatch(unaff_R12);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=005169b1 name=FUN_005169b1 size=16 ====

void FUN_005169b1(void)

{
  QRegularExpressionMatch *unaff_R12;
  long *unaff_R13;
  undefined8 in_stack_00000008;
  
  FUN_0096bb02();
  FUN_0096bb02();
  if (unaff_R13 != (long *)0x0) {
    (**(code **)(*unaff_R13 + 8))();
  }
  qt_array_data_unref(in_stack_00000008);
  QRegularExpressionMatch::~QRegularExpressionMatch(unaff_R12);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=005169c1 name=FUN_005169c1 size=16 ====

void FUN_005169c1(void)

{
  QRegularExpressionMatch *unaff_R12;
  long *unaff_R13;
  undefined8 in_stack_00000008;
  
  FUN_0096bb02();
  FUN_0096bb02();
  if (unaff_R13 != (long *)0x0) {
    (**(code **)(*unaff_R13 + 8))();
  }
  qt_array_data_unref(in_stack_00000008);
  QRegularExpressionMatch::~QRegularExpressionMatch(unaff_R12);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=005169d1 name=FUN_005169d1 size=16 ====

void FUN_005169d1(void)

{
  QRegularExpressionMatch *unaff_R12;
  long *unaff_R13;
  undefined8 in_stack_00000008;
  
  FUN_0096bb02();
  FUN_0096bb02();
  if (unaff_R13 != (long *)0x0) {
    (**(code **)(*unaff_R13 + 8))();
  }
  qt_array_data_unref(in_stack_00000008);
  QRegularExpressionMatch::~QRegularExpressionMatch(unaff_R12);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=005169e1 name=FUN_005169e1 size=16 ====

void FUN_005169e1(void)

{
  QRegularExpressionMatch *unaff_R12;
  long *unaff_R13;
  undefined8 in_stack_00000008;
  
  FUN_0096bb02();
  FUN_0096bb02();
  if (unaff_R13 != (long *)0x0) {
    (**(code **)(*unaff_R13 + 8))();
  }
  qt_array_data_unref(in_stack_00000008);
  QRegularExpressionMatch::~QRegularExpressionMatch(unaff_R12);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=005169f1 name=FUN_005169f1 size=16 ====

void FUN_005169f1(void)

{
  QRegularExpressionMatch *unaff_R12;
  long *unaff_R13;
  undefined8 in_stack_00000008;
  
  FUN_0096bb02();
  FUN_0096bb02();
  if (unaff_R13 != (long *)0x0) {
    (**(code **)(*unaff_R13 + 8))();
  }
  qt_array_data_unref(in_stack_00000008);
  QRegularExpressionMatch::~QRegularExpressionMatch(unaff_R12);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00516a02 name=FUN_00516a02 size=22 ====

void FUN_00516a02(void)

{
  long in_stack_00000018;
  
  FUN_00a5aa04(in_stack_00000018 + -0x18);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00516a18 name=FUN_00516a18 size=22 ====

void FUN_00516a18(void)

{
  long in_stack_00000018;
  
  FUN_00a5aa04(in_stack_00000018 + -0x18);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00516a2e name=FUN_00516a2e size=22 ====

void FUN_00516a2e(void)

{
  long in_stack_00000018;
  
  FUN_00a5aa04(in_stack_00000018 + -0x18);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00516a44 name=FUN_00516a44 size=22 ====

void FUN_00516a44(void)

{
  long in_stack_00000018;
  
  FUN_00a5aa04(in_stack_00000018 + -0x18);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00516a5a name=FUN_00516a5a size=12 ====

void FUN_00516a5a(void)

{
  undefined1 *unaff_RBP;
  
  *unaff_RBP = 0;
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00516a66 name=FUN_00516a66 size=12 ====

void FUN_00516a66(void)

{
  undefined1 *unaff_RBP;
  
  *unaff_RBP = 0;
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00516a72 name=FUN_00516a72 size=22 ====

void FUN_00516a72(void)

{
                    /* WARNING: Subroutine does not return */
  __cxa_throw();
}


// ==== entry=00516a88 name=FUN_00516a88 size=16 ====

void FUN_00516a88(void)

{
  __cxa_free_exception();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00516a98 name=FUN_00516a98 size=22 ====

void FUN_00516a98(void)

{
                    /* WARNING: Subroutine does not return */
  __cxa_throw();
}


// ==== entry=00516aae name=FUN_00516aae size=16 ====

void FUN_00516aae(void)

{
  __cxa_free_exception();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00516abe name=FUN_00516abe size=11 ====

void FUN_00516abe(void)

{
  undefined1 *unaff_RBX;
  
  *unaff_RBX = 0;
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00516aca name=FUN_00516aca size=12 ====

void FUN_00516aca(void)

{
  undefined1 *unaff_R14;
  
  *unaff_R14 = 0;
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00516ad6 name=FUN_00516ad6 size=11 ====

void FUN_00516ad6(void)

{
  undefined1 *unaff_RBX;
  
  *unaff_RBX = 0;
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00516ae2 name=FUN_00516ae2 size=22 ====

void FUN_00516ae2(void)

{
  long in_stack_00000008;
  
  FUN_00a5aa04(in_stack_00000008 + -0x18);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00516af8 name=FUN_00516af8 size=22 ====

void FUN_00516af8(void)

{
  long in_stack_00000008;
  
  FUN_00a5aa04(in_stack_00000008 + -0x18);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00516b0e name=FUN_00516b0e size=22 ====

void FUN_00516b0e(void)

{
  long in_stack_00000008;
  
  FUN_00a5aa04(in_stack_00000008 + -0x18);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00516b24 name=FUN_00516b24 size=41 ====

void FUN_00516b24(void)

{
  long unaff_RBX;
  void *unaff_RBP;
  
  operator_delete(unaff_RBP,0x20);
  FUN_00a5ab92();
  qt_array_data_unref(unaff_RBX + 0x38);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00516b4e name=FUN_00516b4e size=40 ====

void FUN_00516b4e(void)

{
  ulong in_stack_00000008;
  
  if ((in_stack_00000008 != 0) && ((in_stack_00000008 & 1) != 0)) {
    QReadWriteLock::unlock();
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00516b76 name=FUN_00516b76 size=18 ====

void FUN_00516b76(void)

{
  undefined8 in_stack_00000028;
  
  FUN_00a5e626(in_stack_00000028);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00516b88 name=FUN_00516b88 size=21 ====

void FUN_00516b88(void)

{
  void *unaff_R13;
  
  operator_delete(unaff_R13,0x20);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00516b9e name=FUN_00516b9e size=34 ====

void FUN_00516b9e(void)

{
  void *unaff_RBP;
  void *unaff_R15;
  
  operator_delete(unaff_RBP,0x30);
  operator_delete(unaff_R15,0x20);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00516bc0 name=FUN_00516bc0 size=40 ====

void FUN_00516bc0(void)

{
  ulong in_stack_00000068;
  
  if ((in_stack_00000068 != 0) && ((in_stack_00000068 & 1) != 0)) {
    QReadWriteLock::unlock();
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00516be8 name=FUN_00516be8 size=15 ====

void FUN_00516be8(void)

{
  void *unaff_RBP;
  void *unaff_R15;
  
  operator_delete(unaff_RBP,0x60);
  operator_delete(unaff_R15,0x20);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00516bf7 name=FUN_00516bf7 size=18 ====

void FUN_00516bf7(void)

{
  undefined8 in_stack_00000020;
  
  FUN_00a5e626(in_stack_00000020);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00516c10 name=FUN_00516c10 size=16 ====

void FUN_00516c10(void)

{
  FUN_0096bb02();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00516c20 name=FUN_00516c20 size=28 ====

void FUN_00516c20(void)

{
  undefined8 in_stack_00000010;
  undefined8 in_stack_00000018;
  
  FUN_0096bb02(in_stack_00000010);
  FUN_00974856(in_stack_00000018);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00516c3c name=FUN_00516c3c size=12 ====

void FUN_00516c3c(void)

{
  undefined8 in_stack_00000008;
  undefined8 in_stack_00000018;
  
  FUN_0096bb02(in_stack_00000008);
  FUN_00974856(in_stack_00000018);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00516c48 name=FUN_00516c48 size=23 ====

void FUN_00516c48(void)

{
  void *in_stack_00000030;
  
  if (in_stack_00000030 != (void *)0x0) {
    operator_delete(in_stack_00000030);
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00516c5f name=FUN_00516c5f size=16 ====

void FUN_00516c5f(void)

{
  FUN_0096bb02();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00516c70 name=FUN_00516c70 size=52 ====

void FUN_00516c70(void)

{
  QArrayData *in_stack_00000018;
  
  if (*(int *)in_stack_00000018 != 0) {
    if (*(int *)in_stack_00000018 == -1) goto LAB_00516c8a;
    LOCK();
    *(int *)in_stack_00000018 = *(int *)in_stack_00000018 + -1;
    UNLOCK();
    if (*(int *)in_stack_00000018 != 0) goto LAB_00516c8a;
  }
  QArrayData::deallocate(in_stack_00000018,1,8);
LAB_00516c8a:
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00516ca4 name=FUN_00516ca4 size=32 ====

void FUN_00516ca4(void)

{
  void *unaff_RBP;
  
  operator_delete(unaff_RBP,0x20);
  FUN_00a62960();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00516cd0 name=FUN_00516cd0 size=22 ====

void FUN_00516cd0(void)

{
                    /* WARNING: Subroutine does not return */
  __cxa_throw();
}


// ==== entry=00516ce6 name=FUN_00516ce6 size=16 ====

void FUN_00516ce6(void)

{
  __cxa_free_exception();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00516cf6 name=FUN_00516cf6 size=21 ====

void FUN_00516cf6(void)

{
  void *unaff_RBX;
  
  operator_delete(unaff_RBX,0x28);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00516d0c name=FUN_00516d0c size=21 ====

void FUN_00516d0c(void)

{
  void *unaff_RBX;
  
  operator_delete(unaff_RBX,0x28);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00516d22 name=FUN_00516d22 size=33 ====

int FUN_00516d22(undefined8 param_1,undefined8 param_2,long param_3)

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


// ==== entry=00516d44 name=FUN_00516d44 size=23 ====

void FUN_00516d44(void)

{
  undefined1 *unaff_RBX;
  
  QReadWriteLock::unlock();
  *unaff_RBX = 0;
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00516d5b name=FUN_00516d5b size=11 ====

void FUN_00516d5b(void)

{
  undefined1 *unaff_RBX;
  
  *unaff_RBX = 0;
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00516d66 name=FUN_00516d66 size=13 ====

void FUN_00516d66(void)

{
  __cxa_begin_catch();
                    /* WARNING: Subroutine does not return */
                    /* try { // try from 00516d6e to 00516d72 has its CatchHandler @ 00516d73 */
  __cxa_rethrow();
}


// ==== entry=00516d7e name=FUN_00516d7e size=21 ====

void FUN_00516d7e(void)

{
  void *unaff_RBP;
  
  operator_delete(unaff_RBP,0x60);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00516d94 name=FUN_00516d94 size=23 ====

void FUN_00516d94(void)

{
  void *in_stack_00000010;
  
  operator_delete(in_stack_00000010,0x60);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00516dab name=FUN_00516dab size=23 ====

void FUN_00516dab(void)

{
  void *in_stack_00000008;
  
  operator_delete(in_stack_00000008,0x60);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00516dc2 name=FUN_00516dc2 size=17 ====

void FUN_00516dc2(void)

{
  long unaff_RBX;
  char unaff_R13B;
  
  if (unaff_R13B != '\0') {
    *(undefined1 *)(unaff_RBX + 0x31) = 0;
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00516dd4 name=FUN_00516dd4 size=17 ====

void FUN_00516dd4(void)

{
  long unaff_RBX;
  char unaff_R13B;
  
  if (unaff_R13B != '\0') {
    *(undefined1 *)(unaff_RBX + 0x31) = 0;
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00516de6 name=FUN_00516de6 size=21 ====

void FUN_00516de6(void)

{
  void *unaff_RBP;
  
  operator_delete(unaff_RBP,0x20);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00516e00 name=FUN_00516e00 size=16 ====

void FUN_00516e00(void)

{
  FUN_0096bb02();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00516e10 name=FUN_00516e10 size=28 ====

void FUN_00516e10(void)

{
  undefined8 in_stack_00000020;
  undefined8 in_stack_00000050;
  
  FUN_0096bb02(in_stack_00000050);
  qt_array_data_unref(in_stack_00000020);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00516e2c name=FUN_00516e2c size=44 ====

void FUN_00516e2c(void)

{
  undefined8 in_stack_00000020;
  undefined8 in_stack_00000028;
  
  FUN_00a75688();
  FUN_0096bd50();
  FUN_0096bd50(in_stack_00000028);
  FUN_0096bd50(in_stack_00000020);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00516e58 name=FUN_00516e58 size=10 ====

void FUN_00516e58(void)

{
  undefined8 in_stack_00000020;
  undefined8 in_stack_00000028;
  
  FUN_00a75688();
  FUN_0096bd50();
  FUN_0096bd50(in_stack_00000028);
  FUN_0096bd50(in_stack_00000020);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00516e62 name=FUN_00516e62 size=10 ====

void FUN_00516e62(void)

{
  undefined8 in_stack_00000020;
  undefined8 in_stack_00000028;
  
  FUN_0096bb02();
  FUN_0096bd50();
  FUN_0096bd50(in_stack_00000028);
  FUN_0096bd50(in_stack_00000020);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00516e6c name=FUN_00516e6c size=10 ====

void FUN_00516e6c(void)

{
  undefined8 in_stack_00000020;
  undefined8 in_stack_00000028;
  
  FUN_0096bb02();
  FUN_0096bd50();
  FUN_0096bd50(in_stack_00000028);
  FUN_0096bd50(in_stack_00000020);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00516e76 name=FUN_00516e76 size=18 ====

void FUN_00516e76(void)

{
  undefined8 in_stack_00000030;
  
  FUN_0096bd50(in_stack_00000030);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00516e88 name=FUN_00516e88 size=31 ====

void FUN_00516e88(void)

{
  undefined1 *in_stack_00000018;
  
  if (in_stack_00000018 != &DAT_011c5338) {
    FUN_00a63a70();
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00516ea8 name=FUN_00516ea8 size=53 ====

void FUN_00516ea8(void)

{
  void *pvVar1;
  void *in_stack_00000060;
  void *in_stack_00000068;
  
  for (pvVar1 = in_stack_00000060; in_stack_00000068 != pvVar1;
      pvVar1 = (void *)((long)pvVar1 + 0x20)) {
    FUN_0096bb02((long)pvVar1 + 8);
  }
  if (in_stack_00000060 != (void *)0x0) {
    operator_delete(in_stack_00000060);
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00516ede name=FUN_00516ede size=31 ====

void FUN_00516ede(void)

{
  undefined1 *in_stack_00000040;
  
  if (in_stack_00000040 != &DAT_011c5338) {
    FUN_00a63a70();
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00516efd name=FUN_00516efd size=16 ====

void FUN_00516efd(void)

{
  FUN_0096bb02();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00516f0d name=FUN_00516f0d size=16 ====

void FUN_00516f0d(void)

{
  FUN_0096bb02();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00516f1d name=FUN_00516f1d size=16 ====

void FUN_00516f1d(void)

{
  FUN_0096bb02();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00516f2e name=FUN_00516f2e size=31 ====

void FUN_00516f2e(void)

{
  undefined1 *in_stack_00000060;
  
  if (in_stack_00000060 != &DAT_011c5338) {
    FUN_00a63a70();
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00516f4e name=FUN_00516f4e size=31 ====

void FUN_00516f4e(void)

{
  undefined1 *in_stack_00000028;
  
  if (in_stack_00000028 != &DAT_011c5338) {
    FUN_00a63a70();
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00516f6e name=FUN_00516f6e size=33 ====

void FUN_00516f6e(void)

{
  undefined1 *in_stack_00000040;
  
  if (in_stack_00000040 != &DAT_011c5338) {
    FUN_00a63a70();
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00516f88 name=FUN_00516f88 size=40 ====

void FUN_00516f88(void)

{
  undefined1 *in_stack_00000038;
  
  if (in_stack_00000038 != &DAT_011c5338) {
    FUN_00a63a70();
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00516fb8 name=FUN_00516fb8 size=47 ====

void FUN_00516fb8(void)

{
  long in_stack_00000080;
  long in_stack_00000120;
  
  if (in_stack_00000120 + -0x18 != in_stack_00000080) {
    FUN_00a63a70();
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00516fda name=FUN_00516fda size=37 ====

void FUN_00516fda(void)

{
  long in_stack_00000080;
  long in_stack_00000120;
  
  if (in_stack_00000120 + -0x18 != in_stack_00000080) {
    FUN_00a63a70();
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00516ff8 name=FUN_00516ff8 size=42 ====

void FUN_00516ff8(void)

{
  undefined1 *in_stack_00000120;
  
  if (in_stack_00000120 != &DAT_011c5338) {
    FUN_00a63a70();
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0051701c name=FUN_0051701c size=36 ====

void FUN_0051701c(void)

{
  undefined1 *in_stack_00000120;
  
  if (in_stack_00000120 != &DAT_011c5338) {
    FUN_00a63a70();
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00517039 name=FUN_00517039 size=36 ====

void FUN_00517039(void)

{
  undefined1 *in_stack_00000120;
  
  if (in_stack_00000120 != &DAT_011c5338) {
    FUN_00a63a70();
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00517077 name=FUN_00517077 size=44 ====

void FUN_00517077(void)

{
  undefined8 in_stack_00000048;
  undefined1 *in_stack_00000098;
  
  if (in_stack_00000098 != &DAT_011c5338) {
    FUN_00a63a70();
  }
  FUN_0096bd50(in_stack_00000048);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=005170aa name=FUN_005170aa size=31 ====

void FUN_005170aa(void)

{
  undefined1 *in_stack_00000070;
  
  if (in_stack_00000070 != &DAT_011c5338) {
    FUN_00a63a70();
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=005170ca name=FUN_005170ca size=31 ====

void FUN_005170ca(void)

{
  undefined1 *in_stack_00000060;
  
  if (in_stack_00000060 != &DAT_011c5338) {
    FUN_00a63a70();
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=005170ea name=FUN_005170ea size=33 ====

void FUN_005170ea(void)

{
  undefined1 *in_stack_00000060;
  
  if (in_stack_00000060 != &DAT_011c5338) {
    FUN_00a63a70();
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00517104 name=FUN_00517104 size=39 ====

void FUN_00517104(void)

{
  undefined1 *in_stack_00000058;
  
  if (in_stack_00000058 != &DAT_011c5338) {
    FUN_00a63a70();
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00517132 name=FUN_00517132 size=29 ====

void FUN_00517132(void)

{
  undefined1 *in_stack_00000090;
  
  if (in_stack_00000090 != &DAT_011c5338) {
    FUN_00a63a70();
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0051714f name=FUN_0051714f size=26 ====

void FUN_0051714f(void)

{
  undefined8 in_stack_00000038;
  
  FUN_00a75688();
  FUN_0096bb02(in_stack_00000038);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00517169 name=FUN_00517169 size=29 ====

void FUN_00517169(void)

{
  char unaff_BL;
  undefined1 *in_stack_00000070;
  
  if ((unaff_BL != '\0') && (in_stack_00000070 != &DAT_011c5338)) {
    FUN_00a63a70();
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00517186 name=FUN_00517186 size=31 ====

void FUN_00517186(void)

{
  undefined1 *in_stack_00000038;
  
  if (in_stack_00000038 != &DAT_011c5338) {
    FUN_00a63a70();
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=005171a6 name=FUN_005171a6 size=34 ====

void FUN_005171a6(void)

{
  undefined1 *in_stack_00000050;
  
  if (in_stack_00000050 != &DAT_011c5338) {
    FUN_00a63a70();
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=005171c0 name=FUN_005171c0 size=33 ====

void FUN_005171c0(void)

{
  undefined1 *in_stack_00000050;
  
  if (in_stack_00000050 != &DAT_011c5338) {
    FUN_00a63a70();
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=005171ea name=FUN_005171ea size=31 ====

void FUN_005171ea(void)

{
  undefined1 *in_stack_00000038;
  
  if (in_stack_00000038 != &DAT_011c5338) {
    FUN_00a63a70();
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0051720a name=FUN_0051720a size=31 ====

void FUN_0051720a(void)

{
  undefined1 *in_stack_00000040;
  
  if (in_stack_00000040 != &DAT_011c5338) {
    FUN_00a63a70();
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0051722a name=FUN_0051722a size=32 ====

void FUN_0051722a(void)

{
  long in_stack_00000038;
  long in_stack_00000058;
  
  if (in_stack_00000058 + -0x18 != in_stack_00000038) {
    FUN_00a63a70();
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00517242 name=FUN_00517242 size=34 ====

void FUN_00517242(void)

{
  long in_stack_00000038;
  long in_stack_00000060;
  
  if (in_stack_00000060 + -0x18 != in_stack_00000038) {
    FUN_00a63a70();
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00517262 name=FUN_00517262 size=33 ====

void FUN_00517262(void)

{
  undefined1 *in_stack_00000060;
  
  if (in_stack_00000060 != &DAT_011c5338) {
    FUN_00a63a70();
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0051727c name=FUN_0051727c size=37 ====

void FUN_0051727c(void)

{
  undefined1 *in_stack_00000060;
  
  if (in_stack_00000060 != &DAT_011c5338) {
    FUN_00a63a70();
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=005172b2 name=FUN_005172b2 size=34 ====

void FUN_005172b2(void)

{
  undefined1 *in_stack_000000f0;
  
  if (in_stack_000000f0 != &DAT_011c5338) {
    FUN_00a63a70();
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=005172d4 name=FUN_005172d4 size=34 ====

void FUN_005172d4(void)

{
  undefined1 *in_stack_000000c0;
  
  if (in_stack_000000c0 != &DAT_011c5338) {
    FUN_00a63a70();
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=005172f6 name=FUN_005172f6 size=44 ====

void FUN_005172f6(void)

{
  undefined8 in_stack_00000038;
  undefined8 in_stack_00000040;
  
  qt_array_data_unref(in_stack_00000040);
  qt_array_data_unref(in_stack_00000038);
  qt_array_data_unref(&stack0x000000b0);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00517322 name=FUN_00517322 size=38 ====

void FUN_00517322(void)

{
  undefined8 in_stack_00000038;
  undefined1 *in_stack_000000f0;
  
  if (in_stack_000000f0 != &DAT_011c5338) {
    FUN_00a63a70();
  }
  qt_array_data_unref(in_stack_00000038);
  qt_array_data_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00517348 name=FUN_00517348 size=28 ====

void FUN_00517348(void)

{
  undefined1 *in_stack_000000f0;
  
  if (in_stack_000000f0 != &DAT_011c5338) {
    FUN_00a63a70();
  }
  qt_array_data_unref(&stack0x000000b0);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00517364 name=FUN_00517364 size=32 ====

void FUN_00517364(void)

{
  long in_stack_00000050;
  long in_stack_000000c0;
  
  if (in_stack_000000c0 + -0x18 != in_stack_00000050) {
    FUN_00a63a70();
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00517384 name=FUN_00517384 size=33 ====

void FUN_00517384(void)

{
  long in_stack_00000050;
  long in_stack_000000b8;
  
  if (in_stack_000000b8 + -0x18 != in_stack_00000050) {
    FUN_00a63a70();
  }
  qt_array_data_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=005173a5 name=FUN_005173a5 size=34 ====

void FUN_005173a5(void)

{
  undefined1 *in_stack_000000f0;
  
  if (in_stack_000000f0 != &DAT_011c5338) {
    FUN_00a63a70();
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=005173c7 name=FUN_005173c7 size=34 ====

void FUN_005173c7(void)

{
  undefined1 *in_stack_000000f0;
  
  if (in_stack_000000f0 != &DAT_011c5338) {
    FUN_00a63a70();
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=005173e9 name=FUN_005173e9 size=34 ====

void FUN_005173e9(void)

{
  undefined1 *in_stack_000000f0;
  
  if (in_stack_000000f0 != &DAT_011c5338) {
    FUN_00a63a70();
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0051740c name=FUN_0051740c size=34 ====

void FUN_0051740c(void)

{
  undefined1 *in_stack_000000c0;
  
  if (in_stack_000000c0 != &DAT_011c5338) {
    FUN_00a63a70();
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0051742e name=FUN_0051742e size=33 ====

void FUN_0051742e(void)

{
  undefined1 *in_stack_00000028;
  
  if (in_stack_00000028 != &DAT_011c5338) {
    FUN_00a63a70();
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00517448 name=FUN_00517448 size=40 ====

void FUN_00517448(void)

{
  undefined1 *in_stack_00000028;
  
  if (in_stack_00000028 != &DAT_011c5338) {
    FUN_00a63a70();
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00517469 name=FUN_00517469 size=33 ====

void FUN_00517469(void)

{
  undefined1 *in_stack_00000028;
  
  if (in_stack_00000028 != &DAT_011c5338) {
    FUN_00a63a70();
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00517483 name=FUN_00517483 size=33 ====

void FUN_00517483(void)

{
  undefined1 *in_stack_00000028;
  
  if (in_stack_00000028 != &DAT_011c5338) {
    FUN_00a63a70();
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=005174ba name=FUN_005174ba size=33 ====

void FUN_005174ba(void)

{
  undefined1 *in_stack_00000040;
  
  if (in_stack_00000040 != &DAT_011c5338) {
    FUN_00a63a70();
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=005174d4 name=FUN_005174d4 size=39 ====

void FUN_005174d4(void)

{
  undefined1 *in_stack_00000040;
  
  if (in_stack_00000040 != &DAT_011c5338) {
    FUN_00a63a70();
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00517502 name=FUN_00517502 size=33 ====

void FUN_00517502(void)

{
  undefined1 *in_stack_00000028;
  
  if (in_stack_00000028 != &DAT_011c5338) {
    FUN_00a63a70();
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0051751c name=FUN_0051751c size=41 ====

void FUN_0051751c(void)

{
  undefined1 *in_stack_00000028;
  
  if (in_stack_00000028 != &DAT_011c5338) {
    FUN_00a63a70();
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0051753d name=FUN_0051753d size=33 ====

void FUN_0051753d(void)

{
  undefined1 *in_stack_00000028;
  
  if (in_stack_00000028 != &DAT_011c5338) {
    FUN_00a63a70();
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00517557 name=FUN_00517557 size=37 ====

void FUN_00517557(void)

{
  undefined1 *in_stack_00000028;
  
  if (in_stack_00000028 != &DAT_011c5338) {
    FUN_00a63a70();
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00517592 name=FUN_00517592 size=33 ====

void FUN_00517592(void)

{
  undefined1 *in_stack_00000048;
  
  if (in_stack_00000048 != &DAT_011c5338) {
    FUN_00a63a70();
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=005175ac name=FUN_005175ac size=36 ====

void FUN_005175ac(void)

{
  undefined1 *in_stack_00000048;
  
  if (in_stack_00000048 != &DAT_011c5338) {
    FUN_00a63a70();
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=005175d8 name=FUN_005175d8 size=49 ====

void FUN_005175d8(void)

{
  void *in_stack_00000010;
  undefined1 *in_stack_00000058;
  
  if (in_stack_00000058 != &DAT_011c5338) {
    FUN_00a63a70();
  }
  if (in_stack_00000010 != (void *)0x0) {
    operator_delete(in_stack_00000010);
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0051760a name=FUN_0051760a size=96 ====

void FUN_0051760a(void)

{
  long in_stack_00000048;
  undefined8 in_stack_00000068;
  undefined1 *in_stack_00000078;
  long in_stack_00000100;
  long in_stack_00000108;
  long *in_stack_00000110;
  
  *in_stack_00000078 = 0;
  if (in_stack_00000110 != (long *)0x0) {
    (**(code **)(*in_stack_00000110 + 8))();
  }
  if (in_stack_00000108 + -0x18 != in_stack_00000048) {
    FUN_00a63a70();
  }
  if (in_stack_00000100 + -0x18 != in_stack_00000048) {
    FUN_00a63a70();
  }
  FUN_00a73700(in_stack_00000068);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0051766a name=FUN_0051766a size=26 ====

void FUN_0051766a(void)

{
  long in_stack_00000048;
  undefined8 in_stack_00000068;
  long in_stack_00000100;
  long in_stack_00000108;
  long in_stack_00000130;
  
  if (in_stack_00000130 + -0x18 != in_stack_00000048) {
    FUN_00a63a70();
  }
  if (in_stack_00000108 + -0x18 != in_stack_00000048) {
    FUN_00a63a70();
  }
  if (in_stack_00000100 + -0x18 != in_stack_00000048) {
    FUN_00a63a70();
  }
  FUN_00a73700(in_stack_00000068);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00517684 name=FUN_00517684 size=45 ====

void FUN_00517684(void)

{
  undefined1 *unaff_RBP;
  long in_stack_00000048;
  undefined8 in_stack_00000068;
  ulong in_stack_00000078;
  long in_stack_00000100;
  long in_stack_00000108;
  long *in_stack_00000110;
  
  *unaff_RBP = 0;
  if ((in_stack_00000078 != 0) && ((in_stack_00000078 & 1) != 0)) {
    QReadWriteLock::unlock();
  }
  if (in_stack_00000110 != (long *)0x0) {
    (**(code **)(*in_stack_00000110 + 8))();
  }
  if (in_stack_00000108 + -0x18 != in_stack_00000048) {
    FUN_00a63a70();
  }
  if (in_stack_00000100 + -0x18 != in_stack_00000048) {
    FUN_00a63a70();
  }
  FUN_00a73700(in_stack_00000068);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=005176b1 name=FUN_005176b1 size=33 ====

void FUN_005176b1(void)

{
  long in_stack_00000048;
  undefined8 in_stack_00000068;
  long in_stack_00000100;
  long in_stack_00000108;
  long in_stack_00000130;
  
  if (in_stack_00000130 + -0x18 != in_stack_00000048) {
    FUN_00a63a70();
  }
  if (in_stack_00000108 + -0x18 != in_stack_00000048) {
    FUN_00a63a70();
  }
  if (in_stack_00000100 + -0x18 != in_stack_00000048) {
    FUN_00a63a70();
  }
  FUN_00a73700(in_stack_00000068);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=005176d2 name=FUN_005176d2 size=71 ====

void FUN_005176d2(void)

{
  long in_stack_00000048;
  undefined8 in_stack_00000068;
  undefined8 in_stack_000000a0;
  long in_stack_00000100;
  long in_stack_00000108;
  long *in_stack_00000110;
  long in_stack_00000120;
  long in_stack_00000128;
  
  if (in_stack_00000128 + -0x18 != in_stack_00000048) {
    FUN_00a63a70();
  }
  if ((in_stack_000000a0._7_1_ != '\0') && (in_stack_00000120 + -0x18 != in_stack_00000048)) {
    FUN_00a63a70();
  }
  if (in_stack_00000110 != (long *)0x0) {
    (**(code **)(*in_stack_00000110 + 8))();
  }
  if (in_stack_00000108 + -0x18 != in_stack_00000048) {
    FUN_00a63a70();
  }
  if (in_stack_00000100 + -0x18 != in_stack_00000048) {
    FUN_00a63a70();
  }
  FUN_00a73700(in_stack_00000068);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00517719 name=FUN_00517719 size=33 ====

void FUN_00517719(void)

{
  long in_stack_00000048;
  undefined8 in_stack_00000068;
  long in_stack_00000100;
  long in_stack_00000108;
  long in_stack_00000130;
  
  if (in_stack_00000130 + -0x18 != in_stack_00000048) {
    FUN_00a63a70();
  }
  if (in_stack_00000108 + -0x18 != in_stack_00000048) {
    FUN_00a63a70();
  }
  if (in_stack_00000100 + -0x18 != in_stack_00000048) {
    FUN_00a63a70();
  }
  FUN_00a73700(in_stack_00000068);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0051773a name=FUN_0051773a size=18 ====

void FUN_0051773a(void)

{
  undefined8 in_stack_00000068;
  
  FUN_00a73700(in_stack_00000068);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0051774c name=FUN_0051774c size=33 ====

void FUN_0051774c(void)

{
  long in_stack_00000048;
  undefined8 in_stack_00000068;
  long in_stack_00000100;
  long in_stack_00000108;
  long in_stack_00000130;
  
  if (in_stack_00000130 + -0x18 != in_stack_00000048) {
    FUN_00a63a70();
  }
  if (in_stack_00000108 + -0x18 != in_stack_00000048) {
    FUN_00a63a70();
  }
  if (in_stack_00000100 + -0x18 != in_stack_00000048) {
    FUN_00a63a70();
  }
  FUN_00a73700(in_stack_00000068);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0051776e name=FUN_0051776e size=33 ====

void FUN_0051776e(void)

{
  undefined1 *in_stack_00000098;
  
  QReadWriteLock::unlock();
  *in_stack_00000098 = 0;
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0051778f name=FUN_0051778f size=13 ====

void FUN_0051778f(void)

{
  __cxa_begin_catch();
                    /* WARNING: Subroutine does not return */
                    /* try { // try from 00517797 to 0051779b has its CatchHandler @ 005177e9 */
  __cxa_rethrow();
}


// ==== entry=0051779c name=FUN_0051779c size=58 ====

void FUN_0051779c(void)

{
  long unaff_R12;
  undefined8 in_stack_00000030;
  undefined8 in_stack_00000040;
  long in_stack_000000f0;
  
  FUN_0096bd50(in_stack_00000030);
  FUN_0096bb02();
  FUN_0096bb02(in_stack_00000040);
  if (in_stack_000000f0 + -0x18 != unaff_R12) {
    FUN_00a63a70();
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=005177d6 name=FUN_005177d6 size=19 ====

void FUN_005177d6(void)

{
  undefined1 *in_stack_00000098;
  
  *in_stack_00000098 = 0;
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=005177f3 name=FUN_005177f3 size=48 ====

void FUN_005177f3(void)

{
  ulong in_stack_00000040;
  undefined1 *in_stack_00000048;
  
  *in_stack_00000048 = 0;
  if ((in_stack_00000040 != 0) && ((in_stack_00000040 & 1) != 0)) {
    QReadWriteLock::unlock();
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00517823 name=FUN_00517823 size=36 ====

void FUN_00517823(void)

{
  undefined8 in_stack_00000030;
  undefined8 in_stack_00000040;
  
  FUN_0096bd50(in_stack_00000030);
  FUN_0096bb02();
  FUN_0096bb02(in_stack_00000040);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00517847 name=FUN_00517847 size=18 ====

void FUN_00517847(void)

{
  undefined8 in_stack_00000030;
  
  qt_byte_array_unref(in_stack_00000030);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0051785a name=FUN_0051785a size=48 ====

void FUN_0051785a(void)

{
  undefined1 *in_stack_00000040;
  ulong in_stack_00000058;
  
  *in_stack_00000040 = 0;
  if ((in_stack_00000058 != 0) && ((in_stack_00000058 & 1) != 0)) {
    QReadWriteLock::unlock();
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0051788a name=FUN_0051788a size=33 ====

void FUN_0051788a(void)

{
  undefined1 *in_stack_00000058;
  
  QReadWriteLock::unlock();
  *in_stack_00000058 = 0;
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=005178ab name=FUN_005178ab size=18 ====

void FUN_005178ab(void)

{
  undefined8 in_stack_00000048;
  
  qt_byte_array_unref(in_stack_00000048);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=005178bd name=FUN_005178bd size=30 ====

void FUN_005178bd(void)

{
  long unaff_R13;
  long in_stack_000000d0;
  
  if (in_stack_000000d0 + -0x18 != unaff_R13) {
    FUN_00a63a70();
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=005178db name=FUN_005178db size=34 ====

void FUN_005178db(void)

{
  undefined1 *in_stack_000000e0;
  
  if (in_stack_000000e0 != &DAT_011c5338) {
    FUN_00a63a70();
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=005178fd name=FUN_005178fd size=16 ====

void FUN_005178fd(void)

{
  undefined1 *in_stack_00000058;
  
  *in_stack_00000058 = 0;
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0051790d name=FUN_0051790d size=16 ====

void FUN_0051790d(void)

{
  FUN_0096bb02();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0051791d name=FUN_0051791d size=13 ====

void FUN_0051791d(void)

{
  __cxa_begin_catch();
                    /* WARNING: Subroutine does not return */
                    /* try { // try from 00517925 to 00517929 has its CatchHandler @ 0051792a */
  __cxa_rethrow();
}


// ==== entry=00517938 name=FUN_00517938 size=60 ====

void FUN_00517938(void)

{
  undefined8 in_stack_00000048;
  undefined1 *in_stack_000001f0;
  
  if (in_stack_000001f0 != &DAT_011c5338) {
    FUN_00a63a70();
  }
  FUN_0096bb02();
  qt_array_data_unref();
  FUN_0096bb02(in_stack_00000048);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00517974 name=FUN_00517974 size=45 ====

void FUN_00517974(void)

{
  undefined1 *unaff_R12;
  ulong in_stack_00000060;
  
  *unaff_R12 = 0;
  if ((in_stack_00000060 != 0) && ((in_stack_00000060 & 1) != 0)) {
    QReadWriteLock::unlock();
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=005179a1 name=FUN_005179a1 size=28 ====

void FUN_005179a1(void)

{
  undefined8 in_stack_00000048;
  undefined1 *in_stack_000001f0;
  
  if (in_stack_000001f0 != &DAT_011c5338) {
    FUN_00a63a70();
  }
  FUN_0096bb02();
  qt_array_data_unref();
  FUN_0096bb02(in_stack_00000048);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=005179bd name=FUN_005179bd size=31 ====

void FUN_005179bd(void)

{
  undefined8 in_stack_00000048;
  undefined1 *in_stack_000001f0;
  
  if (in_stack_000001f0 != &DAT_011c5338) {
    FUN_00a63a70();
  }
  FUN_0096bb02();
  qt_array_data_unref();
  FUN_0096bb02(in_stack_00000048);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=005179dc name=FUN_005179dc size=36 ====

void FUN_005179dc(void)

{
  undefined1 *in_stack_00000060;
  
  QReadWriteLock::unlock();
  *in_stack_00000060 = 0;
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00517a00 name=FUN_00517a00 size=13 ====

void FUN_00517a00(void)

{
  undefined8 in_stack_00000048;
  
  FUN_0096bd50();
  FUN_0096bb02();
  qt_array_data_unref();
  FUN_0096bb02(in_stack_00000048);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00517a0d name=FUN_00517a0d size=16 ====

void FUN_00517a0d(void)

{
  undefined1 *in_stack_00000060;
  
  *in_stack_00000060 = 0;
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00517a1d name=FUN_00517a1d size=13 ====

void FUN_00517a1d(void)

{
  undefined8 in_stack_00000048;
  
  FUN_0096bb02();
  FUN_0096bb02();
  qt_array_data_unref();
  FUN_0096bb02(in_stack_00000048);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00517a2a name=FUN_00517a2a size=60 ====

void FUN_00517a2a(void)

{
  undefined1 *unaff_RBP;
  ulong in_stack_00000040;
  long *in_stack_00000058;
  
  *unaff_RBP = 0;
  if ((in_stack_00000040 != 0) && ((in_stack_00000040 & 1) != 0)) {
    QReadWriteLock::unlock();
  }
  if (in_stack_00000058 != (long *)0x0) {
    (**(code **)(*in_stack_00000058 + 8))();
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00517a66 name=FUN_00517a66 size=21 ====

void FUN_00517a66(void)

{
  long unaff_R12;
  long *in_stack_00000058;
  long in_stack_00000070;
  
  if (in_stack_00000070 + -0x18 != unaff_R12) {
    FUN_00a63a70();
  }
  if (in_stack_00000058 != (long *)0x0) {
    (**(code **)(*in_stack_00000058 + 8))();
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00517a7b name=FUN_00517a7b size=20 ====

void FUN_00517a7b(void)

{
  long *in_stack_00000058;
  undefined1 *in_stack_00000070;
  
  if (in_stack_00000070 != &DAT_011c5338) {
    FUN_00a63a70();
  }
  if (in_stack_00000058 != (long *)0x0) {
    (**(code **)(*in_stack_00000058 + 8))();
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00517a90 name=FUN_00517a90 size=16 ====

void FUN_00517a90(void)

{
  FUN_00a75688();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00517aa0 name=FUN_00517aa0 size=88 ====

void FUN_00517aa0(void)

{
  long unaff_R13;
  QDataStream *unaff_R14;
  QPixmap *in_stack_00000008;
  QPainter *in_stack_00000018;
  undefined8 in_stack_00000020;
  undefined8 in_stack_00000040;
  undefined8 in_stack_00000048;
  long in_stack_00000110;
  
  if (in_stack_00000110 + -0x18 != unaff_R13) {
    FUN_00a63a70();
  }
  QDataStream::~QDataStream(unaff_R14);
  qt_byte_array_unref(in_stack_00000020);
  qt_byte_array_unref(in_stack_00000048);
  qt_byte_array_unref(in_stack_00000040);
  QPainter::~QPainter(in_stack_00000018);
  QPixmap::~QPixmap(in_stack_00000008);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00517af8 name=FUN_00517af8 size=46 ====

void FUN_00517af8(void)

{
  long unaff_R13;
  QPixmap *in_stack_00000008;
  QPainter *in_stack_00000018;
  long in_stack_000000f0;
  long in_stack_00000110;
  
  if (in_stack_000000f0 + -0x18 != unaff_R13) {
    FUN_00a63a70();
  }
  if (in_stack_00000110 + -0x18 != unaff_R13) {
    FUN_00a63a70();
  }
  QPainter::~QPainter(in_stack_00000018);
  QPixmap::~QPixmap(in_stack_00000008);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00517b26 name=FUN_00517b26 size=31 ====

void FUN_00517b26(void)

{
  QPixmap *in_stack_00000008;
  QPainter *in_stack_00000018;
  undefined1 *in_stack_000000f0;
  undefined1 *in_stack_00000110;
  
  if (in_stack_000000f0 != &DAT_011c5338) {
    FUN_00a63a70();
  }
  if (in_stack_00000110 != &DAT_011c5338) {
    FUN_00a63a70();
  }
  QPainter::~QPainter(in_stack_00000018);
  QPixmap::~QPixmap(in_stack_00000008);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00517b45 name=FUN_00517b45 size=24 ====

void FUN_00517b45(void)

{
  long unaff_R13;
  QPixmap *in_stack_00000008;
  QPainter *in_stack_00000018;
  long in_stack_000000f0;
  long in_stack_00000110;
  
  if (in_stack_000000f0 + -0x18 != unaff_R13) {
    FUN_00a63a70();
  }
  if (in_stack_00000110 + -0x18 != unaff_R13) {
    FUN_00a63a70();
  }
  QPainter::~QPainter(in_stack_00000018);
  QPixmap::~QPixmap(in_stack_00000008);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00517b5e name=FUN_00517b5e size=68 ====

void FUN_00517b5e(void)

{
  QFrame *unaff_RBX;
  QPixmap *unaff_R13;
  QArrayData *in_stack_00000008;
  
  if (*(int *)in_stack_00000008 != 0) {
    if (*(int *)in_stack_00000008 == -1) goto LAB_00517b78;
    LOCK();
    *(int *)in_stack_00000008 = *(int *)in_stack_00000008 + -1;
    UNLOCK();
    if (*(int *)in_stack_00000008 != 0) goto LAB_00517b78;
  }
  QArrayData::deallocate(in_stack_00000008,2,8);
LAB_00517b78:
  QPixmap::~QPixmap(unaff_R13);
  QFrame::~QFrame(unaff_RBX);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00517ba2 name=FUN_00517ba2 size=16 ====

void FUN_00517ba2(void)

{
  QPainter *unaff_RBP;
  
  QPainter::~QPainter(unaff_RBP);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00517bb2 name=FUN_00517bb2 size=16 ====

void FUN_00517bb2(void)

{
  QPainter *unaff_R12;
  
  QPainter::~QPainter(unaff_R12);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00517bc2 name=FUN_00517bc2 size=42 ====

void FUN_00517bc2(void)

{
  QPixmap *unaff_R13;
  QVariant *unaff_R14;
  QVariant *unaff_R15;
  QVariant *in_stack_00000008;
  
  QPixmap::~QPixmap(unaff_R13);
  QVariant::~QVariant(unaff_R14);
  QVariant::~QVariant(unaff_R15);
  QVariant::~QVariant(in_stack_00000008);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00517bf0 name=FUN_00517bf0 size=39 ====

/* WARNING: Removing unreachable block (ram,0x00517c04) */

void FUN_00517bf0(void *param_1)

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


// ==== entry=00517c18 name=FUN_00517c18 size=26 ====

void FUN_00517c18(void)

{
  long unaff_RBX;
  long unaff_R12;
  
  if (*(long *)(unaff_RBX + 8) + -0x18 != unaff_R12) {
    FUN_00517bf0();
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00517c32 name=FUN_00517c32 size=125 ====

void FUN_00517c32(void)

{
  char unaff_R12B;
  undefined8 in_stack_00000080;
  QArrayData *in_stack_000000b8;
  undefined1 *in_stack_000000c0;
  undefined1 *in_stack_00000110;
  
  if ((unaff_R12B != '\0') && (in_stack_00000110 != &DAT_011c5338)) {
    FUN_00517bf0();
  }
  if ((in_stack_00000080._7_1_ != '\0') && (in_stack_000000c0 != &DAT_011c5338)) {
    FUN_00517bf0();
  }
  if (*(int *)in_stack_000000b8 != 0) {
    if (*(int *)in_stack_000000b8 == -1) goto LAB_00517c92;
    LOCK();
    *(int *)in_stack_000000b8 = *(int *)in_stack_000000b8 + -1;
    UNLOCK();
    if (*(int *)in_stack_000000b8 != 0) goto LAB_00517c92;
  }
  QArrayData::deallocate(in_stack_000000b8,2,8);
LAB_00517c92:
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00517caf name=FUN_00517caf size=34 ====

void FUN_00517caf(void)

{
  undefined1 *in_stack_00000110;
  
  if (in_stack_00000110 != &DAT_011c5338) {
    FUN_00517bf0();
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00517cd1 name=FUN_00517cd1 size=60 ====

void FUN_00517cd1(void)

{
  undefined1 *in_stack_000000b0;
  undefined1 *in_stack_000000b8;
  
  if (in_stack_000000b0 != &DAT_011c5338) {
    FUN_00517bf0();
  }
  if (in_stack_000000b8 != &DAT_011c5338) {
    FUN_00517bf0();
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00517d0d name=FUN_00517d0d size=60 ====

void FUN_00517d0d(void)

{
  undefined1 *in_stack_000000b0;
  undefined1 *in_stack_000000b8;
  
  if (in_stack_000000b0 != &DAT_011c5338) {
    FUN_00517bf0();
  }
  if (in_stack_000000b8 != &DAT_011c5338) {
    FUN_00517bf0();
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00517d49 name=FUN_00517d49 size=34 ====

void FUN_00517d49(void)

{
  undefined1 *in_stack_00000110;
  
  if (in_stack_00000110 != &DAT_011c5338) {
    FUN_00517bf0();
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00517d6c name=FUN_00517d6c size=31 ====

void FUN_00517d6c(void)

{
  undefined1 *in_stack_00000038;
  
  if (in_stack_00000038 != &DAT_011c5338) {
    FUN_00517bf0();
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00517d8c name=FUN_00517d8c size=48 ====

/* WARNING: Removing unreachable block (ram,0x00517da9) */

void FUN_00517d8c(undefined8 *param_1)

{
  int *piVar1;
  int iVar2;
  
  if (param_1 != &std::string::_Rep::_S_empty_rep_storage) {
    LOCK();
    piVar1 = (int *)(param_1 + 2);
    iVar2 = *piVar1;
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if (iVar2 < 1) {
      operator_delete(param_1);
      return;
    }
  }
  return;
}


// ==== entry=00517dbc name=FUN_00517dbc size=17 ====

void FUN_00517dbc(void)

{
  long unaff_RBX;
  
  qt_array_data_unref(unaff_RBX + 0x10);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00517dce name=FUN_00517dce size=31 ====

void FUN_00517dce(void)

{
  long unaff_R12;
  
  FUN_00a5ab92(unaff_R12 + 0x90);
  qt_array_data_unref(unaff_R12 + 0x38);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00517dee name=FUN_00517dee size=24 ====

void FUN_00517dee(void)

{
  FUN_0096bb02();
  FUN_0096bb02();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00517e06 name=FUN_00517e06 size=16 ====

void FUN_00517e06(void)

{
  FUN_0096bb02();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00517e16 name=FUN_00517e16 size=24 ====

void FUN_00517e16(void)

{
  FUN_0096bb02();
  FUN_0096bb02();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00517e2e name=FUN_00517e2e size=24 ====

void FUN_00517e2e(void)

{
  FUN_0096bb02();
  FUN_0096bb02();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00517e46 name=FUN_00517e46 size=18 ====

void FUN_00517e46(void)

{
  undefined8 in_stack_00000020;
  
  FUN_0096bd50(in_stack_00000020);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00517e58 name=FUN_00517e58 size=116 ====

void FUN_00517e58(void)

{
  long unaff_RBP;
  undefined8 in_stack_00000020;
  undefined8 in_stack_00000028;
  undefined8 in_stack_00000040;
  undefined8 in_stack_00000048;
  
  if (*(void **)(unaff_RBP + 0x1c0) != (void *)0x0) {
    operator_delete(*(void **)(unaff_RBP + 0x1c0));
  }
  if (*(void **)(unaff_RBP + 0x180) != (void *)0x0) {
    operator_delete(*(void **)(unaff_RBP + 0x180));
  }
  if (*(void **)(unaff_RBP + 0x168) != (void *)0x0) {
    operator_delete(*(void **)(unaff_RBP + 0x168));
  }
  if (*(void **)(unaff_RBP + 0x150) != (void *)0x0) {
    operator_delete(*(void **)(unaff_RBP + 0x150));
  }
  splitvector_blocks_free(in_stack_00000048);
  FUN_0096bd50(in_stack_00000020);
  FUN_0096bb02(in_stack_00000040);
  FUN_0096bb02(in_stack_00000028);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00517ecc name=FUN_00517ecc size=53 ====

void FUN_00517ecc(void)

{
  long unaff_RBP;
  long in_stack_00000040;
  
  FUN_00517d8c(in_stack_00000040 + -0x18);
  qt_array_data_unref(&stack0x00000028);
  FUN_00a5ab92(unaff_RBP + 0x90);
  qt_array_data_unref(unaff_RBP + 0x38);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00517f01 name=FUN_00517f01 size=65 ====

void FUN_00517f01(void)

{
  void *in_stack_00000008;
  int *in_stack_00000038;
  
  operator_delete(in_stack_00000008,0x58);
  FUN_0096bb02();
  if (*in_stack_00000038 != 0) {
    if (*in_stack_00000038 == -1) goto LAB_00517f28;
    LOCK();
    *in_stack_00000038 = *in_stack_00000038 + -1;
    UNLOCK();
    if (*in_stack_00000038 != 0) goto LAB_00517f28;
  }
  FUN_00a753b0(in_stack_00000038);
LAB_00517f28:
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00517f30 name=FUN_00517f30 size=42 ====

void FUN_00517f30(void)

{
  long unaff_RBP;
  void *unaff_R13;
  
  operator_delete(unaff_R13,0x58);
  FUN_00a5ab92(unaff_RBP + 0x90);
  qt_array_data_unref(unaff_RBP + 0x38);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00517f6c name=FUN_00517f6c size=18 ====

void FUN_00517f6c(void)

{
  long unaff_RBP;
  void *unaff_R12;
  
  operator_delete(unaff_R12,0x58);
  qt_array_data_unref(&stack0x00000028);
  FUN_00a5ab92(unaff_RBP + 0x90);
  qt_array_data_unref(unaff_RBP + 0x38);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00517f7e name=FUN_00517f7e size=30 ====

void FUN_00517f7e(void)

{
  long in_stack_00000040;
  
  FUN_00517d8c(in_stack_00000040 + -0x18);
  FUN_0096bb02();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00517f9c name=FUN_00517f9c size=30 ====

void FUN_00517f9c(void)

{
  long in_stack_00000040;
  
  FUN_00517d8c(in_stack_00000040 + -0x18);
  FUN_0096bb02();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00517fba name=FUN_00517fba size=16 ====

void FUN_00517fba(void)

{
  long in_stack_00000040;
  
  FUN_00517d8c(in_stack_00000040 + -0x18);
  FUN_0096bb02();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00517fca name=FUN_00517fca size=15 ====

void FUN_00517fca(void)

{
  void *unaff_R13;
  
  operator_delete(unaff_R13,0x58);
  FUN_0096bb02();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00517fd9 name=FUN_00517fd9 size=16 ====

void FUN_00517fd9(void)

{
  long in_stack_00000040;
  
  FUN_00517d8c(in_stack_00000040 + -0x18);
  FUN_0096bb02();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00517fe9 name=FUN_00517fe9 size=16 ====

void FUN_00517fe9(void)

{
  long in_stack_00000040;
  
  FUN_00517d8c(in_stack_00000040 + -0x18);
  FUN_0096bb02();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00517ff9 name=FUN_00517ff9 size=16 ====

void FUN_00517ff9(void)

{
  long in_stack_00000040;
  
  FUN_00517d8c(in_stack_00000040 + -0x18);
  FUN_0096bb02();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00518009 name=FUN_00518009 size=15 ====

void FUN_00518009(void)

{
  void *unaff_R13;
  
  operator_delete(unaff_R13,0x58);
  FUN_0096bb02();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00518018 name=FUN_00518018 size=21 ====

void FUN_00518018(void)

{
  void *unaff_R14;
  
  operator_delete(unaff_R14,0x60);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0051802d name=FUN_0051802d size=21 ====

void FUN_0051802d(void)

{
  void *unaff_RBP;
  
  operator_delete(unaff_RBP,0x38);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00518042 name=FUN_00518042 size=21 ====

void FUN_00518042(void)

{
  void *unaff_R14;
  
  operator_delete(unaff_R14,0x20);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00518057 name=FUN_00518057 size=21 ====

void FUN_00518057(void)

{
  void *unaff_R14;
  
  operator_delete(unaff_R14,0x98);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0051806c name=FUN_0051806c size=21 ====

void FUN_0051806c(void)

{
  void *unaff_R12;
  
  operator_delete(unaff_R12,0x80);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00518081 name=FUN_00518081 size=21 ====

void FUN_00518081(void)

{
  void *unaff_R12;
  
  operator_delete(unaff_R12,0x80);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00518096 name=FUN_00518096 size=21 ====

void FUN_00518096(void)

{
  void *unaff_R12;
  
  operator_delete(unaff_R12,0x48);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=005180ab name=FUN_005180ab size=21 ====

void FUN_005180ab(void)

{
  void *unaff_R12;
  
  operator_delete(unaff_R12,0x48);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=005180c0 name=FUN_005180c0 size=21 ====

void FUN_005180c0(void)

{
  void *unaff_R12;
  
  operator_delete(unaff_R12,0x18);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=005180d5 name=FUN_005180d5 size=21 ====

void FUN_005180d5(void)

{
  void *unaff_RBP;
  
  operator_delete(unaff_RBP,0x48);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=005180ea name=FUN_005180ea size=21 ====

void FUN_005180ea(void)

{
  void *unaff_R12;
  
  operator_delete(unaff_R12,0x48);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00518100 name=FUN_00518100 size=21 ====

void FUN_00518100(void)

{
  void *unaff_R13;
  
  operator_delete(unaff_R13,0x40);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00518115 name=FUN_00518115 size=21 ====

void FUN_00518115(void)

{
  void *unaff_R13;
  
  operator_delete(unaff_R13,0x40);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0051812a name=FUN_0051812a size=21 ====

void FUN_0051812a(void)

{
  void *unaff_R12;
  
  operator_delete(unaff_R12,0x28);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0051813f name=FUN_0051813f size=21 ====

void FUN_0051813f(void)

{
  void *unaff_R12;
  
  operator_delete(unaff_R12,0x40);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00518154 name=FUN_00518154 size=21 ====

void FUN_00518154(void)

{
  void *unaff_R12;
  
  operator_delete(unaff_R12,0x40);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00518169 name=FUN_00518169 size=21 ====

void FUN_00518169(void)

{
  void *unaff_R12;
  
  operator_delete(unaff_R12,0x40);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0051817e name=FUN_0051817e size=21 ====

void FUN_0051817e(void)

{
  void *unaff_R12;
  
  operator_delete(unaff_R12,0x40);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00518193 name=FUN_00518193 size=21 ====

void FUN_00518193(void)

{
  void *unaff_R12;
  
  operator_delete(unaff_R12,0x40);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=005181a8 name=FUN_005181a8 size=21 ====

void FUN_005181a8(void)

{
  void *unaff_R12;
  
  operator_delete(unaff_R12,0x40);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=005181bd name=FUN_005181bd size=21 ====

void FUN_005181bd(void)

{
  void *unaff_R12;
  
  operator_delete(unaff_R12,0x40);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=005181d2 name=FUN_005181d2 size=21 ====

void FUN_005181d2(void)

{
  void *unaff_R12;
  
  operator_delete(unaff_R12,0x40);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=005181e7 name=FUN_005181e7 size=21 ====

void FUN_005181e7(void)

{
  void *unaff_R12;
  
  operator_delete(unaff_R12,0x40);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=005181fc name=FUN_005181fc size=21 ====

void FUN_005181fc(void)

{
  void *unaff_R12;
  
  operator_delete(unaff_R12,0x40);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00518211 name=FUN_00518211 size=21 ====

void FUN_00518211(void)

{
  void *unaff_R12;
  
  operator_delete(unaff_R12,0x40);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00518226 name=FUN_00518226 size=12 ====

void FUN_00518226(void)

{
  long unaff_RBX;
  
  *(undefined1 *)(unaff_RBX + 0xc) = 0;
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00518232 name=FUN_00518232 size=12 ====

void FUN_00518232(void)

{
  long unaff_RBP;
  
  *(undefined1 *)(unaff_RBP + 0xc) = 0;
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00518240 name=FUN_00518240 size=16 ====

void FUN_00518240(void)

{
  qt_byte_array_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00518250 name=FUN_00518250 size=32 ====

void FUN_00518250(void)

{
  qt_byte_array_unref();
  qt_byte_array_unref();
  qt_byte_array_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00518270 name=FUN_00518270 size=32 ====

void FUN_00518270(void)

{
  qt_byte_array_unref();
  qt_byte_array_unref();
  qt_byte_array_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00518290 name=FUN_00518290 size=16 ====

void FUN_00518290(void)

{
  qt_byte_array_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=005182a0 name=FUN_005182a0 size=34 ====

void FUN_005182a0(void)

{
  QJsonValue *unaff_RBX;
  undefined8 in_stack_00000008;
  
  qt_array_data_unref(in_stack_00000008);
  QJsonValue::~QJsonValue(unaff_RBX);
  qt_array_data_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=005182c2 name=FUN_005182c2 size=16 ====

void FUN_005182c2(void)

{
  qt_byte_array_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=005182d2 name=FUN_005182d2 size=16 ====

void FUN_005182d2(void)

{
  qt_array_data_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=005182e2 name=FUN_005182e2 size=16 ====

void FUN_005182e2(void)

{
  QJsonDocument *unaff_RBX;
  
  QJsonDocument::~QJsonDocument(unaff_RBX);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=005182f2 name=FUN_005182f2 size=24 ====

void FUN_005182f2(void)

{
  qt_byte_array_unref();
  qt_byte_array_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00518310 name=FUN_00518310 size=48 ====

/* WARNING: Removing unreachable block (ram,0x0051832d) */

void FUN_00518310(undefined8 *param_1)

{
  int *piVar1;
  int iVar2;
  
  if (param_1 != &std::string::_Rep::_S_empty_rep_storage) {
    LOCK();
    piVar1 = (int *)(param_1 + 2);
    iVar2 = *piVar1;
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if (iVar2 < 1) {
      operator_delete(param_1);
      return;
    }
  }
  return;
}


// ==== entry=00518340 name=FUN_00518340 size=16 ====

void FUN_00518340(void)

{
  json_value_destruct();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00518350 name=FUN_00518350 size=21 ====

void FUN_00518350(void)

{
  void *unaff_R12;
  
  operator_delete(unaff_R12,0x28);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00518366 name=FUN_00518366 size=38 ====

void FUN_00518366(void)

{
  long in_stack_00000038;
  
  FUN_00518310(in_stack_00000038 + -0x18);
  FUN_00a80882();
  json_value_destruct();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0051838c name=FUN_0051838c size=10 ====

void FUN_0051838c(void)

{
  json_value_destruct();
  FUN_00a80882();
  json_value_destruct();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00518396 name=FUN_00518396 size=22 ====

void FUN_00518396(void)

{
  long unaff_R15;
  
  __cxa_begin_catch();
  qt_array_data_unref(unaff_R15 + 0x18);
                    /* WARNING: Subroutine does not return */
                    /* try { // try from 005183a7 to 005183ab has its CatchHandler @ 005183f5 */
  __cxa_rethrow();
}


// ==== entry=00518452 name=FUN_00518452 size=30 ====

void FUN_00518452(void)

{
  long in_stack_00000040;
  
  qt_byte_array_unref();
  FUN_00518310(in_stack_00000040 + -0x18);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00518470 name=FUN_00518470 size=30 ====

void FUN_00518470(void)

{
  long in_stack_00000040;
  
  qt_array_data_unref();
  FUN_00518310(in_stack_00000040 + -0x18);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0051848e name=FUN_0051848e size=25 ====

void FUN_0051848e(void)

{
  QVariant *unaff_RBP;
  undefined8 unaff_retaddr;
  
  QVariant::~QVariant(unaff_RBP);
  qatomic_unref_call_deleter(unaff_retaddr);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=005184a8 name=FUN_005184a8 size=24 ====

void FUN_005184a8(void)

{
  qt_byte_array_unref();
  qt_array_data_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=005184c0 name=FUN_005184c0 size=32 ====

void FUN_005184c0(void)

{
  json_value_destruct();
  qatomic_unref_call_deleter();
  json_value_destruct();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=005184e0 name=FUN_005184e0 size=16 ====

void FUN_005184e0(void)

{
  QJSValue *unaff_RBP;
  
  QJSValue::~QJSValue(unaff_RBP);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=005184f0 name=FUN_005184f0 size=16 ====

void FUN_005184f0(void)

{
  long in_stack_00000030;
  
  FUN_00518310(in_stack_00000030 + -0x18);
  qt_array_data_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00518500 name=FUN_00518500 size=28 ====

void FUN_00518500(void)

{
  qt_byte_array_unref();
  __cxa_guard_abort(&DAT_011c28d8);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0051851c name=FUN_0051851c size=30 ====

void FUN_0051851c(void)

{
  long in_stack_00000060;
  
  FUN_00518310(in_stack_00000060 + -0x18);
  qt_byte_array_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0051853a name=FUN_0051853a size=40 ====

void FUN_0051853a(void)

{
  qt_byte_array_unref();
  json_value_destruct();
  qmap_freetree_variant_nodes();
  json_value_destruct();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00518562 name=FUN_00518562 size=24 ====

void FUN_00518562(void)

{
  QVariant *unaff_R13;
  
  QVariant::~QVariant(unaff_R13);
  qatomic_unref_call_deleter();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0051857a name=FUN_0051857a size=16 ====

void FUN_0051857a(void)

{
  QVariant *unaff_R13;
  
  QVariant::~QVariant(unaff_R13);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0051858a name=FUN_0051858a size=16 ====

void FUN_0051858a(void)

{
  qt_byte_array_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0051859a name=FUN_0051859a size=16 ====

void FUN_0051859a(void)

{
  QJSValue *unaff_R13;
  
  QJSValue::~QJSValue(unaff_R13);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=005185aa name=FUN_005185aa size=30 ====

void FUN_005185aa(void)

{
  long in_stack_00000060;
  
  FUN_00518310(in_stack_00000060 + -0x18);
  qt_byte_array_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=005185c8 name=FUN_005185c8 size=19 ====

void FUN_005185c8(void)

{
  long in_stack_00000020;
  
  FUN_00518310(in_stack_00000020 + -0x18);
  json_value_destruct();
  qmap_freetree_variant_nodes();
  json_value_destruct();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=005185db name=FUN_005185db size=24 ====

void FUN_005185db(void)

{
  QVariant *unaff_R13;
  
  QVariant::~QVariant(unaff_R13);
  qmap_freetree_variant_nodes();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=005185f4 name=FUN_005185f4 size=21 ====

void FUN_005185f4(void)

{
  void *unaff_R12;
  
  operator_delete(unaff_R12,0x28);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00518609 name=FUN_00518609 size=16 ====

void FUN_00518609(void)

{
  json_value_destruct();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0051861a name=FUN_0051861a size=43 ====

void FUN_0051861a(void)

{
  QFile *unaff_RBP;
  
  json_value_destruct();
  qt_byte_array_unref();
  QFile::~QFile(unaff_RBP);
  qt_array_data_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00518646 name=FUN_00518646 size=21 ====

void FUN_00518646(void)

{
  void *unaff_RBP;
  
  operator_delete(unaff_RBP,0x28);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0051865c name=FUN_0051865c size=21 ====

void FUN_0051865c(void)

{
  void *unaff_RBP;
  
  operator_delete(unaff_RBP,0x28);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00518672 name=FUN_00518672 size=24 ====

void FUN_00518672(void)

{
  json_value_destruct();
  json_value_destruct();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0051868a name=FUN_0051868a size=10 ====

void FUN_0051868a(void)

{
  json_value_destruct();
  json_value_destruct();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00518694 name=FUN_00518694 size=14 ====

void FUN_00518694(void)

{
  json_value_destruct();
  json_value_destruct();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=005186a2 name=FUN_005186a2 size=10 ====

void FUN_005186a2(void)

{
  json_value_destruct();
  json_value_destruct();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=005186ac name=FUN_005186ac size=16 ====

void FUN_005186ac(void)

{
  QVariant *unaff_RBP;
  
  QVariant::~QVariant(unaff_RBP);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=005186bc name=FUN_005186bc size=16 ====

void FUN_005186bc(void)

{
  QVariant *unaff_RBX;
  
  QVariant::~QVariant(unaff_RBX);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=005186cc name=FUN_005186cc size=16 ====

void FUN_005186cc(void)

{
  QVariant *unaff_RBP;
  
  QVariant::~QVariant(unaff_RBP);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=005186dc name=FUN_005186dc size=24 ====

void FUN_005186dc(void)

{
  json_value_destruct();
  json_value_destruct();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=005186f4 name=FUN_005186f4 size=44 ====

void FUN_005186f4(void)

{
  ofstream *unaff_RBX;
  QMessageBox *unaff_R15;
  undefined8 in_stack_00000008;
  undefined8 in_stack_00000018;
  
  qt_array_data_unref(in_stack_00000008);
  qt_array_data_unref(in_stack_00000018);
  QMessageBox::~QMessageBox(unaff_R15);
  std::ofstream::~ofstream(unaff_RBX);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00518720 name=FUN_00518720 size=16 ====

void FUN_00518720(void)

{
  ofstream *unaff_RBX;
  long in_stack_00000040;
  
  FUN_00518310(in_stack_00000040 + -0x18);
  std::ofstream::~ofstream(unaff_RBX);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00518730 name=FUN_00518730 size=10 ====

void FUN_00518730(void)

{
  ofstream *unaff_RBX;
  
  qt_byte_array_unref();
  std::ofstream::~ofstream(unaff_RBX);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0051873a name=FUN_0051873a size=11 ====

void FUN_0051873a(void)

{
  ofstream *unaff_RBX;
  long unaff_R15;
  
  FUN_00518310(unaff_R15 + -0x18);
  std::ofstream::~ofstream(unaff_RBX);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00518745 name=FUN_00518745 size=63 ====

void FUN_00518745(void)

{
  long unaff_RBX;
  long unaff_R12;
  undefined8 unaff_R15;
  undefined8 in_stack_00000070;
  
  std::filebuf::~filebuf((filebuf *)(unaff_RBX + 8));
  *(undefined8 *)((long)&stack0x00000070 + *(long *)(unaff_R12 + -0x18)) = unaff_R15;
  std::ios_base::~ios_base((ios_base *)(unaff_RBX + 0xf8));
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=00518784 name=FUN_00518784 size=10 ====

void FUN_00518784(void)

{
  ofstream *unaff_RBX;
  
  qt_byte_array_unref();
  std::ofstream::~ofstream(unaff_RBX);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0051878e name=FUN_0051878e size=15 ====

void FUN_0051878e(void)

{
  ofstream *unaff_RBX;
  long unaff_R12;
  
  FUN_00518310(unaff_R12 + -0x18);
  std::ofstream::~ofstream(unaff_RBX);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=0051879d name=FUN_0051879d size=41 ====

void FUN_0051879d(void)

{
  ofstream *unaff_RBX;
  QDir *in_stack_00000008;
  undefined8 in_stack_00000018;
  
  QDir::~QDir(in_stack_00000008);
  qt_array_data_unref();
  qt_array_data_unref(in_stack_00000018);
  qt_array_data_unref();
  std::ofstream::~ofstream(unaff_RBX);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


