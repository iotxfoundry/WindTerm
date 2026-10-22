// Ghidra 12.1.4 decompiled — WindTerm 2.7.0 (sha256 9491b87e…) part 6
// ==== entry=004d3682 name=FUN_004d3682 size=57 ====

void FUN_004d3682(void)

{
  undefined8 uVar1;
  long unaff_RBX;
  long unaff_R12;
  void *unaff_R13;
  
  operator_delete(unaff_R13,0x20);
  if (unaff_R12 == 1) {
    uVar1 = __cxa_begin_catch();
                    /* try { // try from 004d36a7 to 004d36ab has its CatchHandler @ 004d36bb */
    ssh_disconnectMsg(*(undefined8 *)(unaff_RBX + 0x20),uVar1);
    __cxa_end_catch();
    return;
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d36ce name=FUN_004d36ce size=16 ====

void FUN_004d36ce(void)

{
  qt_byte_array_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d36de name=FUN_004d36de size=16 ====

void FUN_004d36de(void)

{
  qt_byte_array_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d36f0 name=FUN_004d36f0 size=36 ====

void FUN_004d36f0(void)

{
  undefined8 *unaff_RBX;
  
  *unaff_RBX = &PTR_FUN_01185b20;
                    /* WARNING: Subroutine does not return */
  __cxa_throw();
}


// ==== entry=004d3714 name=FUN_004d3714 size=16 ====

void FUN_004d3714(void)

{
  __cxa_free_exception();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d3724 name=FUN_004d3724 size=41 ====

void FUN_004d3724(void)

{
  if (DAT_011c14c0 == -1) {
    DAT_011c14c0 = -2;
  }
  __cxa_guard_abort(&DAT_011c1488);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d374e name=FUN_004d374e size=148 ====

void FUN_004d374e(undefined8 *param_1)

{
  long *plVar1;
  long *plVar2;
  
  if (param_1 != (undefined8 *)0x0) {
    *param_1 = &PTR_FUN_01185c90;
    FUN_005f611c(param_1 + 0xf);
    plVar1 = (long *)param_1[0xd];
    for (plVar2 = (long *)param_1[0xc]; plVar1 != plVar2; plVar2 = plVar2 + 1) {
      if ((long *)*plVar2 != (long *)0x0) {
        (**(code **)(*(long *)*plVar2 + 8))();
      }
    }
    if ((void *)param_1[0xc] != (void *)0x0) {
      operator_delete((void *)param_1[0xc]);
    }
    if ((undefined1 *)param_1[2] != &DAT_011c5338) {
      refcount_delete_offset10_f();
    }
    if ((undefined1 *)param_1[1] != &DAT_011c5338) {
      refcount_delete_offset10_f();
    }
    operator_delete(param_1,0xb0);
    return;
  }
  return;
}


// ==== entry=004d37e2 name=FUN_004d37e2 size=107 ====

void FUN_004d37e2(void)

{
  _Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *this;
  long unaff_RBX;
  long unaff_RBP;
  long unaff_R14;
  void *unaff_R15;
  undefined1 *in_stack_00000020;
  
  operator_delete(unaff_R15,0xb0);
  if (in_stack_00000020 != &DAT_011c5338) {
    refcount_delete_offset10_f();
  }
  FUN_005f9fbe(unaff_RBX + 0xb0);
  FUN_005f9e92(unaff_RBX + 0x78);
  __cxa_guard_abort();
  if (unaff_R14 == 1) {
    __cxa_begin_catch();
                    /* try { // try from 004d3837 to 004d383b has its CatchHandler @ 004d3841 */
    __cxa_end_catch();
    *(undefined8 *)(unaff_RBP + 8) = 0;
    this = *(_Sp_counted_base<(__gnu_cxx::_Lock_policy)2> **)(unaff_RBP + 0x10);
    *(undefined8 *)(unaff_RBP + 0x10) = 0;
    if (this != (_Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *)0x0) {
      std::_Sp_counted_base<(__gnu_cxx::_Lock_policy)2>::_M_release(this);
    }
    *(undefined1 *)(unaff_RBP + 0x18) = 0;
    return;
  }
                    /* catch() { ... } // from try @ 004d3837 with catch @ 004d3841 */
  *(undefined1 *)(unaff_RBP + 0x18) = 0;
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d384e name=FUN_004d384e size=58 ====

void FUN_004d384e(void)

{
  long unaff_R12;
  QDateTime *in_stack_00000008;
  undefined8 in_stack_00000010;
  undefined8 in_stack_00000018;
  
  qt_byte_array_unref();
  qt_array_data_unref(in_stack_00000018);
  qt_array_data_unref(in_stack_00000010);
  QDateTime::~QDateTime(in_stack_00000008);
  *(undefined1 *)(unaff_R12 + 0x18) = 0;
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d3888 name=FUN_004d3888 size=57 ====

void FUN_004d3888(void)

{
  undefined1 *unaff_RBX;
  long unaff_R12;
  long unaff_R14;
  QDateTime *in_stack_00000008;
  undefined8 in_stack_00000010;
  undefined8 in_stack_00000018;
  void *in_stack_00000278;
  
  if (in_stack_00000278 != (void *)(unaff_R14 + 0x20)) {
    operator_delete(in_stack_00000278);
  }
  if (unaff_RBX != &DAT_011c5338) {
    refcount_delete_offset10_f();
  }
  qt_array_data_unref(in_stack_00000018);
  qt_array_data_unref(in_stack_00000010);
  QDateTime::~QDateTime(in_stack_00000008);
  *(undefined1 *)(unaff_R12 + 0x18) = 0;
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d38c1 name=FUN_004d38c1 size=85 ====

void FUN_004d38c1(void)

{
  undefined1 *unaff_RBX;
  undefined1 *unaff_RBP;
  long unaff_R12;
  long unaff_R14;
  pthread_mutex_t *unaff_R15;
  QDateTime *in_stack_00000008;
  undefined8 in_stack_00000010;
  undefined8 in_stack_00000018;
  undefined **ppuStack0000000000000150;
  void *in_stack_00000158;
  
  ppuStack0000000000000150 = &PTR_vector_reserveGrow_01185b60;
  if (in_stack_00000158 != (void *)(unaff_R14 + 0x80)) {
    operator_delete(in_stack_00000158);
  }
  pthread_mutex_unlock(unaff_R15);
  if (unaff_RBP != &DAT_011c5338) {
    refcount_delete_offset10_f();
  }
  if (unaff_RBX != &DAT_011c5338) {
    refcount_delete_offset10_f();
  }
  qt_array_data_unref(in_stack_00000018);
  qt_array_data_unref(in_stack_00000010);
  QDateTime::~QDateTime(in_stack_00000008);
  *(undefined1 *)(unaff_R12 + 0x18) = 0;
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d3916 name=FUN_004d3916 size=51 ====

void FUN_004d3916(void)

{
  qt_byte_array_unref();
  qt_array_data_unref();
  qt_array_data_unref();
  qt_array_data_unref();
  qt_array_data_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d3949 name=FUN_004d3949 size=25 ====

void FUN_004d3949(void)

{
  undefined1 *in_stack_00000018;
  
  if (in_stack_00000018 != &DAT_011c5338) {
    refcount_delete_offset10_f();
  }
  qt_array_data_unref();
  qt_array_data_unref();
  qt_array_data_unref();
  qt_array_data_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d3962 name=FUN_004d3962 size=13 ====

void FUN_004d3962(void)

{
  qt_byte_array_unref();
                    /* WARNING: Subroutine does not return */
  std::terminate();
}


// ==== entry=004d3970 name=FUN_004d3970 size=192 ====

/* WARNING: Removing unreachable block (ram,0x004d39db) */

void FUN_004d3970(void)

{
  _Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *unaff_RBX;
  long unaff_RBP;
  long unaff_R13;
  long unaff_R14;
  long unaff_R15;
  void *in_stack_00000020;
  undefined8 in_stack_00000028;
  undefined8 in_stack_00000030;
  long in_stack_00000060;
  long in_stack_00000068;
  long in_stack_00000070;
  
  operator_delete(in_stack_00000020,0xb0);
  if (in_stack_00000070 + -0x18 != unaff_R14) {
    refcount_delete_offset10_f();
  }
  FUN_005f9fbe(unaff_R13 + 0xb0);
  FUN_005f9e92(unaff_R13 + 0x78);
  __cxa_guard_abort(&DAT_011c14c8);
  std::_Sp_counted_base<(__gnu_cxx::_Lock_policy)2>::_M_release(unaff_RBX);
  if (in_stack_00000068 + -0x18 != unaff_R14) {
    refcount_delete_offset10_f();
  }
  if (in_stack_00000060 + -0x18 != unaff_R14) {
    refcount_delete_offset10_f();
  }
  if (unaff_R15 == 1) {
    __cxa_begin_catch();
    __cxa_end_catch();
    qt_array_data_unref(in_stack_00000030);
    qt_array_data_unref(in_stack_00000028);
    *(undefined1 *)(unaff_RBP + 0x18) = 0;
    return;
  }
  qt_array_data_unref(in_stack_00000030);
  qt_array_data_unref(in_stack_00000028);
  *(undefined1 *)(unaff_RBP + 0x18) = 0;
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d3a30 name=FUN_004d3a30 size=83 ====

void FUN_004d3a30(void)

{
  long unaff_RBP;
  void *unaff_R13;
  long unaff_R14;
  long unaff_R15;
  undefined8 in_stack_00000028;
  undefined8 in_stack_00000030;
  long in_stack_00000058;
  long in_stack_00000060;
  long in_stack_00000068;
  
  operator_delete(unaff_R13,0xb0);
  FUN_005f611c();
  if (in_stack_00000060 + -0x18 != unaff_R14) {
    refcount_delete_offset10_f();
  }
  if (in_stack_00000068 + -0x18 != unaff_R14) {
    refcount_delete_offset10_f();
  }
  if (in_stack_00000058 + -0x18 != unaff_R14) {
    refcount_delete_offset10_f();
  }
  if (unaff_R15 != 1) {
    qt_array_data_unref(in_stack_00000030);
    qt_array_data_unref(in_stack_00000028);
    *(undefined1 *)(unaff_RBP + 0x18) = 0;
                    /* WARNING: Subroutine does not return */
    cxa_throw_exception();
  }
  __cxa_begin_catch();
  __cxa_end_catch();
  qt_array_data_unref(in_stack_00000030);
  qt_array_data_unref(in_stack_00000028);
  *(undefined1 *)(unaff_RBP + 0x18) = 0;
  return;
}


// ==== entry=004d3a83 name=FUN_004d3a83 size=24 ====

/* WARNING: Removing unreachable block (ram,0x004d39db) */

void FUN_004d3a83(void)

{
  _Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *unaff_RBX;
  long unaff_RBP;
  long unaff_R13;
  long unaff_R14;
  undefined8 in_stack_00000028;
  undefined8 in_stack_00000030;
  long in_stack_00000060;
  long in_stack_00000068;
  _Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *in_stack_00000078;
  
  if (in_stack_00000078 != (_Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *)0x0) {
    std::_Sp_counted_base<(__gnu_cxx::_Lock_policy)2>::_M_release(in_stack_00000078);
  }
  std::_Sp_counted_base<(__gnu_cxx::_Lock_policy)2>::_M_release(unaff_RBX);
  if (in_stack_00000068 + -0x18 != unaff_R14) {
    refcount_delete_offset10_f();
  }
  if (in_stack_00000060 + -0x18 != unaff_R14) {
    refcount_delete_offset10_f();
  }
  if (unaff_R13 == 1) {
    __cxa_begin_catch();
    __cxa_end_catch();
    qt_array_data_unref(in_stack_00000030);
    qt_array_data_unref(in_stack_00000028);
    *(undefined1 *)(unaff_RBP + 0x18) = 0;
    return;
  }
  qt_array_data_unref(in_stack_00000030);
  qt_array_data_unref(in_stack_00000028);
  *(undefined1 *)(unaff_RBP + 0x18) = 0;
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d3a9b name=FUN_004d3a9b size=86 ====

/* WARNING: Removing unreachable block (ram,0x004d39db) */

void FUN_004d3a9b(void)

{
  void *unaff_RBX;
  long unaff_RBP;
  _Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *unaff_R13;
  long unaff_R14;
  long unaff_R15;
  undefined8 in_stack_00000028;
  undefined8 in_stack_00000030;
  long in_stack_00000060;
  long in_stack_00000068;
  
  if (*(void **)((long)unaff_RBX + 0x20) != (void *)0x0) {
    operator_delete(*(void **)((long)unaff_RBX + 0x20));
  }
  if (*(long *)((long)unaff_RBX + 0x18) + -0x18 != unaff_R14) {
    refcount_delete_offset10_f();
  }
  std::_Sp_counted_base<(__gnu_cxx::_Lock_policy)2>::_M_release(unaff_R13);
  operator_delete(unaff_RBX);
  if (in_stack_00000068 + -0x18 != unaff_R14) {
    refcount_delete_offset10_f();
  }
  if (in_stack_00000060 + -0x18 != unaff_R14) {
    refcount_delete_offset10_f();
  }
  if (unaff_R15 == 1) {
    __cxa_begin_catch();
                    /* try { // try from 004d3ae7 to 004d3aeb has its CatchHandler @ 004d3b24 */
    __cxa_end_catch();
    qt_array_data_unref(in_stack_00000030);
    qt_array_data_unref(in_stack_00000028);
    *(undefined1 *)(unaff_RBP + 0x18) = 0;
    return;
  }
  qt_array_data_unref(in_stack_00000030);
  qt_array_data_unref(in_stack_00000028);
  *(undefined1 *)(unaff_RBP + 0x18) = 0;
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d3af1 name=FUN_004d3af1 size=51 ====

void FUN_004d3af1(void)

{
  long unaff_RBP;
  QDateTime *unaff_R15;
  undefined8 in_stack_00000008;
  undefined8 in_stack_00000010;
  
  qt_array_data_unref();
  qt_array_data_unref(in_stack_00000010);
  QDateTime::~QDateTime(unaff_R15);
  qt_array_data_unref(in_stack_00000008);
  qt_array_data_unref(&stack0x00000048);
  *(undefined1 *)(unaff_RBP + 0x18) = 0;
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d3b2c name=FUN_004d3b2c size=25 ====

void FUN_004d3b2c(void)

{
  long unaff_RBP;
  long unaff_R12;
  long unaff_R14;
  undefined8 in_stack_00000028;
  undefined8 in_stack_00000030;
  long in_stack_00000058;
  long *in_stack_00000070;
  
  if (in_stack_00000070 != (long *)0x0) {
    (**(code **)(*in_stack_00000070 + 8))();
  }
  if (in_stack_00000058 + -0x18 != unaff_R14) {
    refcount_delete_offset10_f();
  }
  if (unaff_R12 != 1) {
    qt_array_data_unref(in_stack_00000030);
    qt_array_data_unref(in_stack_00000028);
    *(undefined1 *)(unaff_RBP + 0x18) = 0;
                    /* WARNING: Subroutine does not return */
    cxa_throw_exception();
  }
  __cxa_begin_catch();
  __cxa_end_catch();
  qt_array_data_unref(in_stack_00000030);
  qt_array_data_unref(in_stack_00000028);
  *(undefined1 *)(unaff_RBP + 0x18) = 0;
  return;
}


// ==== entry=004d3b45 name=FUN_004d3b45 size=47 ====

void FUN_004d3b45(void)

{
  void *unaff_RBX;
  long unaff_RBP;
  void *unaff_R13;
  long unaff_R14;
  undefined1 *in_stack_00000020;
  undefined8 in_stack_00000028;
  undefined8 in_stack_00000030;
  undefined1 *in_stack_00000060;
  undefined1 *in_stack_00000068;
  undefined1 *in_stack_00000070;
  
  operator_delete(unaff_RBX,0xb0);
  if (in_stack_00000070 != &DAT_011c5338) {
    refcount_delete_offset10_f();
  }
  operator_delete(unaff_R13);
  if (in_stack_00000020 != &DAT_011c5338) {
    refcount_delete_offset10_f();
  }
  if (in_stack_00000068 != &DAT_011c5338) {
    refcount_delete_offset10_f();
  }
  if (in_stack_00000060 != &DAT_011c5338) {
    refcount_delete_offset10_f();
  }
  if (unaff_R14 != 1) {
    qt_array_data_unref(in_stack_00000030);
    qt_array_data_unref(in_stack_00000028);
    *(undefined1 *)(unaff_RBP + 0x18) = 0;
                    /* WARNING: Subroutine does not return */
    cxa_throw_exception();
  }
  __cxa_begin_catch();
  __cxa_end_catch();
  qt_array_data_unref(in_stack_00000030);
  qt_array_data_unref(in_stack_00000028);
  *(undefined1 *)(unaff_RBP + 0x18) = 0;
  return;
}


// ==== entry=004d3b74 name=FUN_004d3b74 size=22 ====

void FUN_004d3b74(void)

{
  long unaff_RBP;
  long unaff_R12;
  _Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *unaff_R13;
  long unaff_R14;
  long in_stack_00000020;
  undefined8 in_stack_00000028;
  undefined8 in_stack_00000030;
  long in_stack_00000060;
  long in_stack_00000068;
  
  if (unaff_R13 != (_Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *)0x0) {
    std::_Sp_counted_base<(__gnu_cxx::_Lock_policy)2>::_M_release(unaff_R13);
  }
  if (in_stack_00000020 + -0x18 != unaff_R14) {
    refcount_delete_offset10_f();
  }
  if (in_stack_00000068 + -0x18 != unaff_R14) {
    refcount_delete_offset10_f();
  }
  if (in_stack_00000060 + -0x18 != unaff_R14) {
    refcount_delete_offset10_f();
  }
  if (unaff_R12 != 1) {
    qt_array_data_unref(in_stack_00000030);
    qt_array_data_unref(in_stack_00000028);
    *(undefined1 *)(unaff_RBP + 0x18) = 0;
                    /* WARNING: Subroutine does not return */
    cxa_throw_exception();
  }
  __cxa_begin_catch();
  __cxa_end_catch();
  qt_array_data_unref(in_stack_00000030);
  qt_array_data_unref(in_stack_00000028);
  *(undefined1 *)(unaff_RBP + 0x18) = 0;
  return;
}


// ==== entry=004d3b8a name=FUN_004d3b8a size=83 ====

void FUN_004d3b8a(void)

{
  long unaff_RBP;
  long unaff_R12;
  void *unaff_R13;
  long unaff_R14;
  long in_stack_00000020;
  undefined8 in_stack_00000028;
  undefined8 in_stack_00000030;
  long in_stack_00000060;
  long in_stack_00000068;
  
  if (*(FILE **)((long)unaff_R13 + 0x58) != (FILE *)0x0) {
    fclose(*(FILE **)((long)unaff_R13 + 0x58));
    *(undefined8 *)((long)unaff_R13 + 0x58) = 0;
  }
  if (*(long *)((long)unaff_R13 + 0x60) + -0x18 != unaff_R14) {
    refcount_delete_offset10_f();
  }
  *(undefined **)((long)unaff_R13 + 0x10) = &DAT_01186900;
  if (*(long **)((long)unaff_R13 + 0x20) != (long *)0x0) {
    (**(code **)(**(long **)((long)unaff_R13 + 0x20) + 8))();
  }
  operator_delete(unaff_R13);
  if (in_stack_00000020 + -0x18 != unaff_R14) {
    refcount_delete_offset10_f();
  }
  if (in_stack_00000068 + -0x18 != unaff_R14) {
    refcount_delete_offset10_f();
  }
  if (in_stack_00000060 + -0x18 != unaff_R14) {
    refcount_delete_offset10_f();
  }
  if (unaff_R12 != 1) {
    qt_array_data_unref(in_stack_00000030);
    qt_array_data_unref(in_stack_00000028);
    *(undefined1 *)(unaff_RBP + 0x18) = 0;
                    /* WARNING: Subroutine does not return */
    cxa_throw_exception();
  }
  __cxa_begin_catch();
  __cxa_end_catch();
  qt_array_data_unref(in_stack_00000030);
  qt_array_data_unref(in_stack_00000028);
  *(undefined1 *)(unaff_RBP + 0x18) = 0;
  return;
}


// ==== entry=004d3bdd name=FUN_004d3bdd size=21 ====

void FUN_004d3bdd(void)

{
  long unaff_RBP;
  
  qt_array_data_unref();
  qt_array_data_unref();
  *(undefined1 *)(unaff_RBP + 0x18) = 0;
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d3bf2 name=FUN_004d3bf2 size=16 ====

void FUN_004d3bf2(void)

{
  long unaff_RBP;
  long unaff_R13;
  undefined8 in_stack_00000028;
  undefined8 in_stack_00000030;
  
  qt_byte_array_unref();
  if (unaff_R13 != 1) {
    qt_array_data_unref(in_stack_00000030);
    qt_array_data_unref(in_stack_00000028);
    *(undefined1 *)(unaff_RBP + 0x18) = 0;
                    /* WARNING: Subroutine does not return */
    cxa_throw_exception();
  }
  __cxa_begin_catch();
  __cxa_end_catch();
  qt_array_data_unref(in_stack_00000030);
  qt_array_data_unref(in_stack_00000028);
  *(undefined1 *)(unaff_RBP + 0x18) = 0;
  return;
}


// ==== entry=004d3c02 name=FUN_004d3c02 size=21 ====

void FUN_004d3c02(void)

{
  void *unaff_RBX;
  
  operator_delete(unaff_RBX,0x20);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d3c18 name=FUN_004d3c18 size=16 ====

void FUN_004d3c18(void)

{
  QObject *unaff_RBX;
  
  QObject::~QObject(unaff_RBX);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d3c30 name=FUN_004d3c30 size=86 ====

void FUN_004d3c30(void)

{
  QTcpServer *unaff_RBX;
  QMapDataBase *pQVar1;
  
  pQVar1 = *(QMapDataBase **)(unaff_RBX + 0x28);
  if (*(int *)pQVar1 != 0) {
    if (*(int *)pQVar1 == -1) goto LAB_004d3c4c;
    LOCK();
    *(int *)pQVar1 = *(int *)pQVar1 + -1;
    UNLOCK();
    if (*(int *)pQVar1 != 0) goto LAB_004d3c4c;
    pQVar1 = *(QMapDataBase **)(unaff_RBX + 0x28);
  }
  if (*(long *)(pQVar1 + 0x10) != 0) {
    QMapDataBase::freeTree((QMapNodeBase *)pQVar1,(int)*(long *)(pQVar1 + 0x10));
  }
  QMapDataBase::freeData(pQVar1);
LAB_004d3c4c:
  qt_array_data_unref(unaff_RBX + 0x18);
  QTcpServer::~QTcpServer(unaff_RBX);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d3c86 name=FUN_004d3c86 size=24 ====

void FUN_004d3c86(void)

{
  QDataStream *unaff_RBX;
  
  QDataStream::~QDataStream(unaff_RBX);
  qt_byte_array_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d3c9e name=FUN_004d3c9e size=35 ====

void FUN_004d3c9e(void)

{
  QHostAddress *unaff_RBX;
  QDataStream *unaff_RBP;
  
  QHostAddress::~QHostAddress(unaff_RBX);
  QDataStream::~QDataStream(unaff_RBP);
  qt_byte_array_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d3cc2 name=FUN_004d3cc2 size=63 ====

void FUN_004d3cc2(void)

{
  QDataStream *unaff_RBX;
  
  qt_array_data_unref();
  __cxa_free_exception();
  QDataStream::~QDataStream(unaff_RBX);
  qt_byte_array_unref();
  atomic_refptr_delete(&stack0x00000088);
  atomic_refptr_delete(&stack0x00000070);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d3d01 name=FUN_004d3d01 size=23 ====

void FUN_004d3d01(void)

{
  QDataStream *unaff_RBX;
  
  __cxa_free_exception();
  qt_array_data_unref(&stack0x00000048);
  QDataStream::~QDataStream(unaff_RBX);
  qt_byte_array_unref();
  atomic_refptr_delete(&stack0x00000088);
  atomic_refptr_delete(&stack0x00000070);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d3d18 name=FUN_004d3d18 size=10 ====

void FUN_004d3d18(void)

{
  QDataStream *unaff_RBX;
  
  qt_array_data_unref();
  __cxa_free_exception();
  QDataStream::~QDataStream(unaff_RBX);
  qt_byte_array_unref();
  atomic_refptr_delete(&stack0x00000088);
  atomic_refptr_delete(&stack0x00000070);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d3d22 name=FUN_004d3d22 size=15 ====

void FUN_004d3d22(void)

{
  QDataStream *unaff_RBX;
  
  qt_byte_array_unref();
  qt_array_data_unref(&stack0x00000048);
  QDataStream::~QDataStream(unaff_RBX);
  qt_byte_array_unref();
  atomic_refptr_delete(&stack0x00000088);
  atomic_refptr_delete(&stack0x00000070);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d3d31 name=FUN_004d3d31 size=33 ====

void FUN_004d3d31(void)

{
  QDataStream *unaff_RBX;
  QHostAddress *unaff_R12;
  QDataStream *unaff_R13;
  undefined8 in_stack_00000008;
  
  QHostAddress::~QHostAddress(unaff_R12);
  QDataStream::~QDataStream(unaff_R13);
  qt_byte_array_unref(in_stack_00000008);
  qt_array_data_unref(&stack0x00000048);
  QDataStream::~QDataStream(unaff_RBX);
  qt_byte_array_unref();
  atomic_refptr_delete(&stack0x00000088);
  atomic_refptr_delete(&stack0x00000070);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d3d52 name=FUN_004d3d52 size=55 ====

void FUN_004d3d52(void)

{
  QDataStream *unaff_RBX;
  long unaff_R13;
  
  atomic_refptr_delete(unaff_R13 + 0x30);
  atomic_refptr_delete(unaff_R13 + 0x10);
  atomic_refptr_delete(&stack0x000000f0);
  atomic_refptr_delete(&stack0x000000d0);
  qt_array_data_unref(&stack0x00000048);
  QDataStream::~QDataStream(unaff_RBX);
  qt_byte_array_unref();
  atomic_refptr_delete(&stack0x00000088);
  atomic_refptr_delete(&stack0x00000070);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d3d89 name=FUN_004d3d89 size=13 ====

void FUN_004d3d89(void)

{
  QDataStream *unaff_RBX;
  
  qt_array_data_unref();
  __cxa_free_exception();
  QDataStream::~QDataStream(unaff_RBX);
  qt_byte_array_unref();
  atomic_refptr_delete(&stack0x00000088);
  atomic_refptr_delete(&stack0x00000070);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d3d96 name=FUN_004d3d96 size=18 ====

void FUN_004d3d96(void)

{
  QDataStream *unaff_RBX;
  QHostAddress *unaff_R13;
  
  QHostAddress::~QHostAddress(unaff_R13);
  qt_array_data_unref(&stack0x00000048);
  QDataStream::~QDataStream(unaff_RBX);
  qt_byte_array_unref();
  atomic_refptr_delete(&stack0x00000088);
  atomic_refptr_delete(&stack0x00000070);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d3da8 name=FUN_004d3da8 size=13 ====

void FUN_004d3da8(void)

{
  QDataStream *unaff_RBX;
  
  qt_array_data_unref();
  __cxa_free_exception();
  QDataStream::~QDataStream(unaff_RBX);
  qt_byte_array_unref();
  atomic_refptr_delete(&stack0x00000088);
  atomic_refptr_delete(&stack0x00000070);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d3db6 name=FUN_004d3db6 size=32 ====

void FUN_004d3db6(void)

{
  qt_array_data_unref();
  __cxa_free_exception();
  qt_byte_array_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d3dd6 name=FUN_004d3dd6 size=18 ====

void FUN_004d3dd6(void)

{
  qt_array_data_unref();
  __cxa_free_exception();
  qt_byte_array_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d3de8 name=FUN_004d3de8 size=16 ====

void FUN_004d3de8(void)

{
  QHostAddress *unaff_R12;
  
  QHostAddress::~QHostAddress(unaff_R12);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d3df8 name=FUN_004d3df8 size=16 ====

void FUN_004d3df8(void)

{
  qt_array_data_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d3e08 name=FUN_004d3e08 size=84 ====

void FUN_004d3e08(undefined8 param_1,undefined8 param_2,long param_3)

{
  undefined8 uVar1;
  long unaff_RBX;
  undefined **in_stack_00000010;
  undefined8 in_stack_00000018;
  
  if (param_3 == 1) {
    in_stack_00000018 = __cxa_begin_catch();
    uVar1 = *(undefined8 *)(unaff_RBX + 0x10);
    in_stack_00000010 = &PTR_s__important_01181928;
                    /* try { // try from 004d3e35 to 004d3e39 has its CatchHandler @ 004d3e74 */
    FUN_006153ee(&stack0x00000008,&stack0x00000010);
                    /* try { // try from 004d3e40 to 004d3e44 has its CatchHandler @ 004d3e5c */
    FUN_008fcb08(uVar1,&stack0x00000008);
    qt_array_data_unref(&stack0x00000008);
    __cxa_end_catch();
    return;
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d3e79 name=FUN_004d3e79 size=32 ====

void FUN_004d3e79(void)

{
  QDataStream *unaff_RBP;
  QHostAddress *unaff_R13;
  
  QHostAddress::~QHostAddress(unaff_R13);
  QDataStream::~QDataStream(unaff_RBP);
  qt_byte_array_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d3e99 name=FUN_004d3e99 size=50 ====

void FUN_004d3e99(void)

{
  QDataStream *unaff_RBP;
  QHostAddress *unaff_R13;
  undefined8 in_stack_00000008;
  
  QHostAddress::~QHostAddress(unaff_R13);
  QDataStream::~QDataStream(unaff_RBP);
  qt_byte_array_unref();
  qt_array_data_unref(in_stack_00000008);
  FUN_006153d0();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d3ed0 name=FUN_004d3ed0 size=43 ====

void FUN_004d3ed0(void)

{
  qt_array_data_unref();
  qt_array_data_unref();
  qt_array_data_unref();
  qt_array_data_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d3efc name=FUN_004d3efc size=16 ====

void FUN_004d3efc(void)

{
  qt_array_data_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d3f0c name=FUN_004d3f0c size=16 ====

void FUN_004d3f0c(void)

{
  qt_array_data_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d3f1c name=FUN_004d3f1c size=52 ====

void FUN_004d3f1c(void)

{
  void *in_stack_00000008;
  
  operator_delete(in_stack_00000008,0x30);
  qt_array_data_unref();
  qt_array_data_unref(&stack0x00000030);
  qt_array_data_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d3f50 name=FUN_004d3f50 size=10 ====

void FUN_004d3f50(void)

{
  qt_array_data_unref();
  qt_array_data_unref();
  qt_array_data_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d3f5a name=FUN_004d3f5a size=26 ====

void FUN_004d3f5a(void)

{
  qt_array_data_unref();
  qt_array_data_unref();
  qt_array_data_unref();
  qt_array_data_unref();
  qt_array_data_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d3f74 name=FUN_004d3f74 size=23 ====

void FUN_004d3f74(void)

{
  qt_array_data_unref();
  qt_array_data_unref();
  qt_array_data_unref(&stack0x00000030);
  qt_array_data_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d3f8b name=FUN_004d3f8b size=23 ====

void FUN_004d3f8b(void)

{
  qt_array_data_unref();
  qt_array_data_unref();
  qt_array_data_unref(&stack0x00000030);
  qt_array_data_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d3fa2 name=FUN_004d3fa2 size=26 ====

void FUN_004d3fa2(void)

{
  qt_array_data_unref();
  qt_array_data_unref();
  qt_array_data_unref(&stack0x00000030);
  qt_array_data_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d3fbc name=FUN_004d3fbc size=21 ====

void FUN_004d3fbc(void)

{
  void *unaff_RBX;
  
  operator_delete(unaff_RBX,0x30);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d3fd2 name=FUN_004d3fd2 size=16 ====

void FUN_004d3fd2(void)

{
  qt_array_data_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d3fe2 name=FUN_004d3fe2 size=24 ====

void FUN_004d3fe2(void)

{
  qt_array_data_unref();
  qt_array_data_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d3ffa name=FUN_004d3ffa size=43 ====

void FUN_004d3ffa(void)

{
  QLocale *unaff_RBP;
  
  qt_array_data_unref();
  qt_array_data_unref();
  QLocale::~QLocale(unaff_RBP);
  qt_array_data_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d4026 name=FUN_004d4026 size=32 ====

void FUN_004d4026(void)

{
  QLocale *unaff_R13;
  
  QLocale::~QLocale(unaff_R13);
  qt_array_data_unref();
  qt_array_data_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d4046 name=FUN_004d4046 size=13 ====

void FUN_004d4046(void)

{
  qt_array_data_unref();
  qt_array_data_unref();
  qt_array_data_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d4054 name=FUN_004d4054 size=32 ====

void FUN_004d4054(void)

{
  qt_array_data_unref();
  qt_array_data_unref();
  qt_array_data_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d4074 name=FUN_004d4074 size=32 ====

void FUN_004d4074(void)

{
  qt_array_data_unref();
  qt_array_data_unref();
  qt_array_data_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d4094 name=FUN_004d4094 size=24 ====

void FUN_004d4094(void)

{
  QDateTime *unaff_RBP;
  
  qt_array_data_unref();
  QDateTime::~QDateTime(unaff_RBP);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d40ac name=FUN_004d40ac size=35 ====

void FUN_004d40ac(void)

{
  qt_array_data_unref();
  qt_array_data_unref();
  qt_array_data_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d40cf name=FUN_004d40cf size=37 ====

void FUN_004d40cf(void)

{
  qt_array_data_unref();
  qt_array_data_unref();
  qt_array_data_unref();
  qt_array_data_unref();
  qt_array_data_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d40f4 name=FUN_004d40f4 size=16 ====

void FUN_004d40f4(void)

{
  qqlist_derefDispose();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d4104 name=FUN_004d4104 size=24 ====

void FUN_004d4104(void)

{
  qt_shared_data_unref();
  qt_array_data_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d411c name=FUN_004d411c size=32 ====

void FUN_004d411c(void)

{
  qt_shared_data_unref();
  qt_array_data_unref();
  qt_array_data_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d413c name=FUN_004d413c size=36 ====

void FUN_004d413c(void)

{
  QMimeType *in_stack_00000030;
  QMimeDatabase *in_stack_00000038;
  
  qt_array_data_unref();
  QMimeType::~QMimeType(in_stack_00000030);
  QMimeDatabase::~QMimeDatabase(in_stack_00000038);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d4160 name=FUN_004d4160 size=10 ====

void FUN_004d4160(void)

{
  QVariant *unaff_R14;
  QMimeType *in_stack_00000030;
  QMimeDatabase *in_stack_00000038;
  
  QVariant::~QVariant(unaff_R14);
  QMimeType::~QMimeType(in_stack_00000030);
  QMimeDatabase::~QMimeDatabase(in_stack_00000038);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d416a name=FUN_004d416a size=18 ====

void FUN_004d416a(void)

{
  QMimeType *in_stack_00000030;
  QMimeDatabase *in_stack_00000038;
  
  qt_array_data_unref();
  qt_array_data_unref();
  QMimeType::~QMimeType(in_stack_00000030);
  QMimeDatabase::~QMimeDatabase(in_stack_00000038);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d417c name=FUN_004d417c size=26 ====

void FUN_004d417c(void)

{
  QMimeType *in_stack_00000030;
  QMimeDatabase *in_stack_00000038;
  
  qt_array_data_unref();
  qt_array_data_unref();
  qt_array_data_unref();
  QMimeType::~QMimeType(in_stack_00000030);
  QMimeDatabase::~QMimeDatabase(in_stack_00000038);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d4196 name=FUN_004d4196 size=12 ====

void FUN_004d4196(void)

{
  QUrl *unaff_RBP;
  QMimeType *in_stack_00000030;
  QMimeDatabase *in_stack_00000038;
  
  QUrl::~QUrl(unaff_RBP);
  QMimeType::~QMimeType(in_stack_00000030);
  QMimeDatabase::~QMimeDatabase(in_stack_00000038);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d41a2 name=FUN_004d41a2 size=10 ====

void FUN_004d41a2(void)

{
  QUrl *unaff_RBP;
  QMimeDatabase *in_stack_00000038;
  
  QUrl::~QUrl(unaff_RBP);
  QMimeDatabase::~QMimeDatabase(in_stack_00000038);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d41ac name=FUN_004d41ac size=10 ====

void FUN_004d41ac(void)

{
  QMimeType *in_stack_00000030;
  QMimeDatabase *in_stack_00000038;
  
  qt_array_data_unref();
  QMimeType::~QMimeType(in_stack_00000030);
  QMimeDatabase::~QMimeDatabase(in_stack_00000038);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d41b6 name=FUN_004d41b6 size=15 ====

void FUN_004d41b6(void)

{
  long unaff_RBX;
  
  *(undefined1 *)(unaff_RBX + 0x10) = 0;
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d41c6 name=FUN_004d41c6 size=43 ====

void FUN_004d41c6(void)

{
  QVariant *unaff_RBX;
  QIcon *unaff_R12;
  QVariant *unaff_R13;
  
  QVariant::~QVariant(unaff_RBX);
  qt_array_data_unref();
  QVariant::~QVariant(unaff_R13);
  QIcon::~QIcon(unaff_R12);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d41f1 name=FUN_004d41f1 size=10 ====

void FUN_004d41f1(void)

{
  QIcon *unaff_R12;
  
  qt_array_data_unref();
  QIcon::~QIcon(unaff_R12);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d41fb name=FUN_004d41fb size=29 ====

void FUN_004d41fb(void)

{
  QVariant *unaff_RBX;
  QIcon *unaff_R12;
  QVariant *unaff_R13;
  
  QVariant::~QVariant(unaff_RBX);
  qt_array_data_unref();
  QVariant::~QVariant(unaff_R13);
  QIcon::~QIcon(unaff_R12);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d4218 name=FUN_004d4218 size=29 ====

void FUN_004d4218(void)

{
  QVariant *unaff_RBX;
  QIcon *unaff_R12;
  QVariant *unaff_R13;
  
  QVariant::~QVariant(unaff_RBX);
  qt_array_data_unref();
  QVariant::~QVariant(unaff_R13);
  QIcon::~QIcon(unaff_R12);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d4235 name=FUN_004d4235 size=29 ====

void FUN_004d4235(void)

{
  QVariant *unaff_RBX;
  QIcon *unaff_R12;
  QVariant *unaff_R13;
  
  QVariant::~QVariant(unaff_RBX);
  qt_array_data_unref();
  QVariant::~QVariant(unaff_R13);
  QIcon::~QIcon(unaff_R12);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d4252 name=FUN_004d4252 size=10 ====

void FUN_004d4252(void)

{
  QIcon *unaff_R12;
  
  qt_array_data_unref();
  QIcon::~QIcon(unaff_R12);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d425c name=FUN_004d425c size=88 ====

void FUN_004d425c(void)

{
  undefined1 *puVar1;
  undefined8 in_stack_00000020;
  undefined1 *puStack0000000000000048;
  undefined8 in_stack_00000050;
  
  puVar1 = &stack0x000001a0;
  puStack0000000000000048 = puVar1;
  while (puVar1 != puStack0000000000000048) {
    puVar1 = puVar1 + -0x10;
    qt_array_data_unref(puVar1);
  }
  qt_array_data_unref(in_stack_00000020);
  qt_array_data_unref(in_stack_00000050);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d42a6 name=FUN_004d42a6 size=45 ====

void FUN_004d42a6(void)

{
  undefined1 *puVar1;
  undefined8 in_stack_00000020;
  undefined1 *in_stack_00000048;
  undefined8 in_stack_00000050;
  
  qt_array_data_unref();
  qt_array_data_unref();
  puVar1 = &stack0x00000230;
  do {
    puVar1 = puVar1 + -0x10;
    qt_array_data_unref(puVar1);
  } while (puVar1 != in_stack_00000048);
  qt_array_data_unref(in_stack_00000020);
  qt_array_data_unref(in_stack_00000050);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d42d3 name=FUN_004d42d3 size=15 ====

void FUN_004d42d3(void)

{
  undefined1 *puVar1;
  undefined8 in_stack_00000020;
  undefined1 *in_stack_00000048;
  undefined8 in_stack_00000050;
  
  qt_array_data_unref();
  qt_array_data_unref();
  puVar1 = &stack0x00000230;
  do {
    puVar1 = puVar1 + -0x10;
    qt_array_data_unref(puVar1);
  } while (puVar1 != in_stack_00000048);
  qt_array_data_unref(in_stack_00000020);
  qt_array_data_unref(in_stack_00000050);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d42f0 name=FUN_004d42f0 size=13 ====

void FUN_004d42f0(void)

{
  undefined1 *puVar1;
  undefined8 in_stack_00000020;
  undefined1 *in_stack_00000048;
  undefined8 in_stack_00000050;
  
  qt_array_data_unref();
  puVar1 = &stack0x00000230;
  do {
    puVar1 = puVar1 + -0x10;
    qt_array_data_unref(puVar1);
  } while (puVar1 != in_stack_00000048);
  qt_array_data_unref(in_stack_00000020);
  qt_array_data_unref(in_stack_00000050);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d42fd name=FUN_004d42fd size=13 ====

void FUN_004d42fd(void)

{
  undefined1 *puVar1;
  undefined8 in_stack_00000020;
  undefined1 *in_stack_00000048;
  undefined8 in_stack_00000050;
  
  qt_array_data_unref();
  puVar1 = &stack0x00000230;
  do {
    puVar1 = puVar1 + -0x10;
    qt_array_data_unref(puVar1);
  } while (puVar1 != in_stack_00000048);
  qt_array_data_unref(in_stack_00000020);
  qt_array_data_unref(in_stack_00000050);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d430a name=FUN_004d430a size=10 ====

void FUN_004d430a(void)

{
  undefined1 *puVar1;
  undefined8 in_stack_00000020;
  undefined1 *puStack0000000000000048;
  undefined8 in_stack_00000050;
  
  puStack0000000000000048 = &stack0x000001a0;
  puVar1 = &stack0x000001e0;
  while (puVar1 != puStack0000000000000048) {
    puVar1 = puVar1 + -0x10;
    qt_array_data_unref(puVar1);
  }
  qt_array_data_unref(in_stack_00000020);
  qt_array_data_unref(in_stack_00000050);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d4314 name=FUN_004d4314 size=10 ====

void FUN_004d4314(void)

{
  undefined1 *puVar1;
  undefined8 in_stack_00000020;
  undefined1 *puStack0000000000000048;
  undefined8 in_stack_00000050;
  
  puStack0000000000000048 = &stack0x000001a0;
  puVar1 = &stack0x000001d0;
  while (puVar1 != puStack0000000000000048) {
    puVar1 = puVar1 + -0x10;
    qt_array_data_unref(puVar1);
  }
  qt_array_data_unref(in_stack_00000020);
  qt_array_data_unref(in_stack_00000050);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d431e name=FUN_004d431e size=10 ====

void FUN_004d431e(void)

{
  undefined1 *puVar1;
  undefined8 in_stack_00000020;
  undefined1 *puStack0000000000000048;
  undefined8 in_stack_00000050;
  
  puStack0000000000000048 = &stack0x000001a0;
  puVar1 = &stack0x000001c0;
  while (puVar1 != puStack0000000000000048) {
    puVar1 = puVar1 + -0x10;
    qt_array_data_unref(puVar1);
  }
  qt_array_data_unref(in_stack_00000020);
  qt_array_data_unref(in_stack_00000050);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d4328 name=FUN_004d4328 size=10 ====

void FUN_004d4328(void)

{
  undefined1 *puVar1;
  undefined8 in_stack_00000020;
  undefined1 *puStack0000000000000048;
  undefined8 in_stack_00000050;
  
  puStack0000000000000048 = &stack0x000001a0;
  puVar1 = &stack0x000001b0;
  while (puVar1 != puStack0000000000000048) {
    puVar1 = puVar1 + -0x10;
    qt_array_data_unref(puVar1);
  }
  qt_array_data_unref(in_stack_00000020);
  qt_array_data_unref(in_stack_00000050);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d4332 name=FUN_004d4332 size=10 ====

void FUN_004d4332(void)

{
  undefined1 *puVar1;
  undefined8 in_stack_00000020;
  undefined1 *puStack0000000000000048;
  undefined8 in_stack_00000050;
  
  puStack0000000000000048 = &stack0x000001a0;
  puVar1 = &stack0x00000200;
  while (puVar1 != puStack0000000000000048) {
    puVar1 = puVar1 + -0x10;
    qt_array_data_unref(puVar1);
  }
  qt_array_data_unref(in_stack_00000020);
  qt_array_data_unref(in_stack_00000050);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d433c name=FUN_004d433c size=10 ====

void FUN_004d433c(void)

{
  undefined1 *puVar1;
  undefined8 in_stack_00000020;
  undefined1 *puStack0000000000000048;
  undefined8 in_stack_00000050;
  
  puStack0000000000000048 = &stack0x000001a0;
  puVar1 = &stack0x000001f0;
  while (puVar1 != puStack0000000000000048) {
    puVar1 = puVar1 + -0x10;
    qt_array_data_unref(puVar1);
  }
  qt_array_data_unref(in_stack_00000020);
  qt_array_data_unref(in_stack_00000050);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d4346 name=FUN_004d4346 size=49 ====

void FUN_004d4346(void)

{
  undefined1 *puVar1;
  QVariant *unaff_RBP;
  QVariant *unaff_R14;
  undefined8 in_stack_00000020;
  undefined8 in_stack_00000038;
  undefined8 in_stack_00000040;
  undefined1 *in_stack_00000048;
  undefined8 in_stack_00000050;
  
  qt_array_data_unref();
  QVariant::~QVariant(unaff_RBP);
  qt_array_data_unref(in_stack_00000040);
  QVariant::~QVariant(unaff_R14);
  qt_array_data_unref(in_stack_00000038);
  qt_array_data_unref();
  puVar1 = &stack0x00000230;
  do {
    puVar1 = puVar1 + -0x10;
    qt_array_data_unref(puVar1);
  } while (puVar1 != in_stack_00000048);
  qt_array_data_unref(in_stack_00000020);
  qt_array_data_unref(in_stack_00000050);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d4377 name=FUN_004d4377 size=10 ====

void FUN_004d4377(void)

{
  undefined1 *puVar1;
  undefined8 in_stack_00000020;
  undefined1 *puStack0000000000000048;
  undefined8 in_stack_00000050;
  
  puStack0000000000000048 = &stack0x000001a0;
  puVar1 = &stack0x00000210;
  while (puVar1 != puStack0000000000000048) {
    puVar1 = puVar1 + -0x10;
    qt_array_data_unref(puVar1);
  }
  qt_array_data_unref(in_stack_00000020);
  qt_array_data_unref(in_stack_00000050);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d4381 name=FUN_004d4381 size=15 ====

void FUN_004d4381(void)

{
  undefined1 *puVar1;
  undefined8 in_stack_00000018;
  undefined8 in_stack_00000020;
  undefined1 *in_stack_00000048;
  undefined8 in_stack_00000050;
  
  qt_array_data_unref(in_stack_00000018);
  qt_array_data_unref();
  puVar1 = &stack0x00000230;
  do {
    puVar1 = puVar1 + -0x10;
    qt_array_data_unref(puVar1);
  } while (puVar1 != in_stack_00000048);
  qt_array_data_unref(in_stack_00000020);
  qt_array_data_unref(in_stack_00000050);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d4390 name=FUN_004d4390 size=29 ====

void FUN_004d4390(void)

{
  undefined1 *puVar1;
  QVariant *unaff_RBP;
  QVariant *unaff_R14;
  undefined8 in_stack_00000020;
  undefined1 *in_stack_00000048;
  undefined8 in_stack_00000050;
  
  QVariant::~QVariant(unaff_RBP);
  qt_array_data_unref();
  QVariant::~QVariant(unaff_R14);
  puVar1 = &stack0x00000230;
  do {
    puVar1 = puVar1 + -0x10;
    qt_array_data_unref(puVar1);
  } while (puVar1 != in_stack_00000048);
  qt_array_data_unref(in_stack_00000020);
  qt_array_data_unref(in_stack_00000050);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d43ad name=FUN_004d43ad size=8 ====

void FUN_004d43ad(void)

{
  undefined1 *puVar1;
  undefined8 in_stack_00000020;
  undefined1 *puStack0000000000000048;
  undefined8 in_stack_00000050;
  
  puStack0000000000000048 = &stack0x000001a0;
  puVar1 = &stack0x00000220;
  while (puVar1 != puStack0000000000000048) {
    puVar1 = puVar1 + -0x10;
    qt_array_data_unref(puVar1);
  }
  qt_array_data_unref(in_stack_00000020);
  qt_array_data_unref(in_stack_00000050);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d43b6 name=FUN_004d43b6 size=43 ====

void FUN_004d43b6(void)

{
  QVariant *unaff_RBX;
  QVariant *unaff_R14;
  
  QVariant::~QVariant(unaff_RBX);
  qt_array_data_unref();
  QVariant::~QVariant(unaff_R14);
  qmap_freetree_variant_nodes();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d43e1 name=FUN_004d43e1 size=16 ====

void FUN_004d43e1(void)

{
  QVariant *unaff_RBX;
  
  QVariant::~QVariant(unaff_RBX);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d43f1 name=FUN_004d43f1 size=10 ====

void FUN_004d43f1(void)

{
  qt_array_data_unref();
  qmap_freetree_variant_nodes();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d43fc name=FUN_004d43fc size=43 ====

void FUN_004d43fc(void)

{
  QVariant *unaff_RBX;
  QVariant *unaff_R12;
  
  QVariant::~QVariant(unaff_RBX);
  qt_array_data_unref();
  QVariant::~QVariant(unaff_R12);
  qmap_freetree_variant_nodes();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d4427 name=FUN_004d4427 size=37 ====

void FUN_004d4427(void)

{
  QVariant *unaff_RBX;
  QVariant *unaff_R12;
  
  QVariant::~QVariant(unaff_RBX);
  qt_array_data_unref();
  QVariant::~QVariant(unaff_R12);
  qt_array_data_unref();
  qmap_freetree_variant_nodes();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d444c name=FUN_004d444c size=47 ====

void FUN_004d444c(void)

{
  undefined8 in_RAX;
  QVariant *unaff_RBX;
  QVariant *unaff_R12;
  undefined8 uStack0000000000000008;
  
  uStack0000000000000008 = in_RAX;
  QVariant::~QVariant(unaff_RBX);
  qt_array_data_unref();
  QVariant::~QVariant(unaff_R12);
  qt_array_data_unref();
  qt_array_data_unref();
  qmap_freetree_variant_nodes();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception(uStack0000000000000008);
}


// ==== entry=004d447b name=FUN_004d447b size=13 ====

void FUN_004d447b(void)

{
  qt_array_data_unref();
  qt_array_data_unref();
  qt_array_data_unref();
  qmap_freetree_variant_nodes();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d4488 name=FUN_004d4488 size=13 ====

void FUN_004d4488(void)

{
  qt_array_data_unref();
  qt_array_data_unref();
  qt_array_data_unref();
  qmap_freetree_variant_nodes();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d4495 name=FUN_004d4495 size=16 ====

void FUN_004d4495(void)

{
  QVariant *unaff_RBX;
  
  QVariant::~QVariant(unaff_RBX);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d44a6 name=FUN_004d44a6 size=40 ====

void FUN_004d44a6(void)

{
  QVariant *unaff_RBP;
  QVariant *unaff_R15;
  
  QVariant::~QVariant(unaff_RBP);
  qt_array_data_unref();
  QVariant::~QVariant(unaff_R15);
  qmap_freetree_variant_nodes();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d44ce name=FUN_004d44ce size=16 ====

void FUN_004d44ce(void)

{
  QVariant *unaff_RBP;
  
  QVariant::~QVariant(unaff_RBP);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d44de name=FUN_004d44de size=136 ====

void FUN_004d44de(void)

{
  char cVar1;
  QObject *unaff_RBX;
  void *unaff_RBP;
  
  operator_delete(unaff_RBP,0x10);
  cVar1 = qatomic_int_deref(*(long *)(unaff_RBX + 0x48) + 0x10);
  if (cVar1 == '\0') {
    QHashData::free_helper(*(_func_void_Node_ptr **)(unaff_RBX + 0x48));
  }
  cVar1 = qatomic_int_deref(*(undefined8 *)(unaff_RBX + 0x40));
  if (cVar1 == '\0') {
    FUN_0061e588(*(undefined8 *)(unaff_RBX + 0x40));
  }
  cVar1 = qatomic_int_deref(*(undefined8 *)(unaff_RBX + 0x38));
  if (cVar1 == '\0') {
    FUN_0061d3c8(*(undefined8 *)(unaff_RBX + 0x38));
  }
  TransferCenter_map_freetree(unaff_RBX + 0x30);
  FUN_0061c030(unaff_RBX + 0x28);
  FUN_0061c010(unaff_RBX + 0x20);
  QObject::~QObject(unaff_RBX);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d4566 name=FUN_004d4566 size=41 ====

void FUN_004d4566(void)

{
  if (DAT_011c16f0 == -1) {
    DAT_011c16f0 = -2;
  }
  __cxa_guard_abort(&DAT_011c1688);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d4590 name=FUN_004d4590 size=53 ====

void FUN_004d4590(void)

{
  QVariant *unaff_RBX;
  QVariant *unaff_R13;
  undefined8 in_stack_00000038;
  
  QVariant::~QVariant(unaff_RBX);
  qt_array_data_unref();
  QVariant::~QVariant(unaff_R13);
  qt_array_data_unref(in_stack_00000038);
  qt_array_data_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d45c5 name=FUN_004d45c5 size=29 ====

void FUN_004d45c5(void)

{
  QVariant *unaff_RBX;
  QVariant *unaff_R13;
  
  QVariant::~QVariant(unaff_RBX);
  qt_array_data_unref();
  QVariant::~QVariant(unaff_R13);
  qt_array_data_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d45e2 name=FUN_004d45e2 size=35 ====

void FUN_004d45e2(void)

{
  QVariant *unaff_RBX;
  QVariant *unaff_R13;
  
  QVariant::~QVariant(unaff_RBX);
  qt_array_data_unref();
  QVariant::~QVariant(unaff_R13);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d4605 name=FUN_004d4605 size=23 ====

void FUN_004d4605(void)

{
  undefined8 in_stack_00000028;
  undefined8 in_stack_00000038;
  
  qt_array_data_unref();
  qt_array_data_unref(in_stack_00000028);
  qt_array_data_unref(in_stack_00000038);
  qt_array_data_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d461c name=FUN_004d461c size=21 ====

void FUN_004d461c(void)

{
  undefined8 in_stack_00000028;
  undefined8 in_stack_00000038;
  
  qt_array_data_unref();
  qt_array_data_unref();
  qt_array_data_unref(in_stack_00000028);
  qt_array_data_unref(in_stack_00000038);
  qt_array_data_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d4631 name=FUN_004d4631 size=32 ====

void FUN_004d4631(void)

{
  QVariant *unaff_RBX;
  QVariant *unaff_R13;
  
  QVariant::~QVariant(unaff_RBX);
  qt_array_data_unref();
  QVariant::~QVariant(unaff_R13);
  qt_array_data_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d4651 name=FUN_004d4651 size=10 ====

void FUN_004d4651(void)

{
  undefined8 in_stack_00000028;
  undefined8 in_stack_00000038;
  
  qt_array_data_unref();
  qt_array_data_unref();
  qt_array_data_unref(in_stack_00000028);
  qt_array_data_unref(in_stack_00000038);
  qt_array_data_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d465b name=FUN_004d465b size=10 ====

void FUN_004d465b(void)

{
  undefined8 in_stack_00000028;
  undefined8 in_stack_00000038;
  
  qt_array_data_unref();
  qt_array_data_unref();
  qt_array_data_unref(in_stack_00000028);
  qt_array_data_unref(in_stack_00000038);
  qt_array_data_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d4666 name=FUN_004d4666 size=34 ====

void FUN_004d4666(void)

{
  QRegularExpressionMatch *unaff_R14;
  QRegularExpression *in_stack_00000030;
  
  qt_array_data_unref();
  QRegularExpressionMatch::~QRegularExpressionMatch(unaff_R14);
  QRegularExpression::~QRegularExpression(in_stack_00000030);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d4688 name=FUN_004d4688 size=18 ====

void FUN_004d4688(void)

{
  QRegularExpressionMatch *unaff_R14;
  QRegularExpression *in_stack_00000030;
  
  qt_array_data_unref();
  qt_array_data_unref();
  QRegularExpressionMatch::~QRegularExpressionMatch(unaff_R14);
  QRegularExpression::~QRegularExpression(in_stack_00000030);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d469a name=FUN_004d469a size=71 ====

void FUN_004d469a(void)

{
  long unaff_RBP;
  QRegularExpressionMatch *unaff_R14;
  undefined8 in_stack_00000020;
  undefined8 in_stack_00000028;
  QRegularExpression *in_stack_00000030;
  
  qt_array_data_unref(&stack0x000000d8);
  qt_array_data_unref(&stack0x000000d0);
  qt_array_data_unref(unaff_RBP + 0x18);
  qt_array_data_unref(unaff_RBP + 0x10);
  qt_array_data_unref(in_stack_00000028);
  qt_array_data_unref(in_stack_00000020);
  qt_array_data_unref();
  QRegularExpressionMatch::~QRegularExpressionMatch(unaff_R14);
  QRegularExpression::~QRegularExpression(in_stack_00000030);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d46e1 name=FUN_004d46e1 size=10 ====

void FUN_004d46e1(void)

{
  QRegularExpressionMatch *unaff_R14;
  undefined8 in_stack_00000020;
  QRegularExpression *in_stack_00000030;
  
  qt_array_data_unref();
  qt_array_data_unref(in_stack_00000020);
  qt_array_data_unref();
  QRegularExpressionMatch::~QRegularExpressionMatch(unaff_R14);
  QRegularExpression::~QRegularExpression(in_stack_00000030);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d46eb name=FUN_004d46eb size=16 ====

void FUN_004d46eb(void)

{
  qt_array_data_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d46fb name=FUN_004d46fb size=21 ====

void FUN_004d46fb(void)

{
  QRegularExpressionMatch *unaff_R14;
  undefined8 in_stack_00000020;
  undefined8 in_stack_00000028;
  QRegularExpression *in_stack_00000030;
  
  qt_shared_data_unref();
  qt_array_data_unref();
  qt_array_data_unref(in_stack_00000028);
  qt_array_data_unref(in_stack_00000020);
  qt_array_data_unref();
  QRegularExpressionMatch::~QRegularExpressionMatch(unaff_R14);
  QRegularExpression::~QRegularExpression(in_stack_00000030);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d4710 name=FUN_004d4710 size=24 ====

void FUN_004d4710(void)

{
  long unaff_RBP;
  QRegularExpressionMatch *unaff_R14;
  undefined8 in_stack_00000020;
  undefined8 in_stack_00000028;
  QRegularExpression *in_stack_00000030;
  
  qt_array_data_unref(unaff_RBP + 0x18);
  qt_array_data_unref(&stack0x000000d8);
  qt_array_data_unref(in_stack_00000028);
  qt_array_data_unref(in_stack_00000020);
  qt_array_data_unref();
  QRegularExpressionMatch::~QRegularExpressionMatch(unaff_R14);
  QRegularExpression::~QRegularExpression(in_stack_00000030);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d4728 name=FUN_004d4728 size=12 ====

void FUN_004d4728(void)

{
  long unaff_RBX;
  
  *(undefined1 *)(unaff_RBX + 0x10) = 0;
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d4734 name=FUN_004d4734 size=26 ====

void FUN_004d4734(void)

{
  QVariant *unaff_RBX;
  undefined8 in_stack_00000008;
  
  qt_array_data_unref(in_stack_00000008);
  QVariant::~QVariant(unaff_RBX);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d474e name=FUN_004d474e size=24 ====

void FUN_004d474e(void)

{
  QVariant *unaff_RBX;
  QVariant *unaff_R12;
  
  QVariant::~QVariant(unaff_R12);
  QVariant::~QVariant(unaff_RBX);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d4766 name=FUN_004d4766 size=24 ====

void FUN_004d4766(void)

{
  QVariant *unaff_RBX;
  QVariant *unaff_RBP;
  
  QVariant::~QVariant(unaff_RBP);
  QVariant::~QVariant(unaff_RBX);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d477e name=FUN_004d477e size=24 ====

void FUN_004d477e(void)

{
  QVariant *unaff_RBX;
  QVariant *unaff_R12;
  
  QVariant::~QVariant(unaff_R12);
  QVariant::~QVariant(unaff_RBX);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d4796 name=FUN_004d4796 size=23 ====

void FUN_004d4796(void)

{
  long unaff_RBX;
  
  atomic_refptr_delete();
  *(undefined1 *)(unaff_RBX + 0x10) = 0;
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d47ae name=FUN_004d47ae size=23 ====

void FUN_004d47ae(void)

{
  long unaff_RBP;
  
  *(undefined1 *)(unaff_RBP + 0x10) = 0;
  FUN_0061bf70();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d47c6 name=FUN_004d47c6 size=29 ====

void FUN_004d47c6(void)

{
  QVariant *unaff_RBX;
  QVariant *unaff_R13;
  
  QVariant::~QVariant(unaff_RBX);
  qt_array_data_unref();
  QVariant::~QVariant(unaff_R13);
  qt_array_data_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d47e3 name=FUN_004d47e3 size=35 ====

void FUN_004d47e3(void)

{
  QVariant *unaff_RBX;
  QIcon *unaff_R13;
  
  QVariant::~QVariant(unaff_RBX);
  QIcon::~QIcon(unaff_R13);
  qt_array_data_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d4823 name=FUN_004d4823 size=13 ====

void FUN_004d4823(void)

{
  QVariant *unaff_RBX;
  
  QVariant::~QVariant(unaff_RBX);
  qt_array_data_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d4830 name=FUN_004d4830 size=28 ====

void FUN_004d4830(void)

{
  QIcon *unaff_R13;
  void *unaff_R15;
  
  operator_delete(unaff_R15,0x10);
  QIcon::~QIcon(unaff_R13);
  qt_array_data_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d483f name=FUN_004d483f size=10 ====

void FUN_004d483f(void)

{
  QVariant *unaff_RBX;
  QIcon *unaff_R13;
  
  QVariant::~QVariant(unaff_RBX);
  QIcon::~QIcon(unaff_R13);
  qt_array_data_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d4849 name=FUN_004d4849 size=35 ====

void FUN_004d4849(void)

{
  QVariant *unaff_RBX;
  QVariant *unaff_R13;
  
  QVariant::~QVariant(unaff_RBX);
  qt_array_data_unref();
  QVariant::~QVariant(unaff_R13);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d486c name=FUN_004d486c size=24 ====

void FUN_004d486c(void)

{
  QVariant *unaff_RBX;
  QVariant *unaff_R13;
  
  QVariant::~QVariant(unaff_RBX);
  qt_array_data_unref();
  QVariant::~QVariant(unaff_R13);
  qt_array_data_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d4884 name=FUN_004d4884 size=14 ====

void FUN_004d4884(void)

{
  QVariant *unaff_RBX;
  QIcon *unaff_R13;
  
  QVariant::~QVariant(unaff_RBX);
  QIcon::~QIcon(unaff_R13);
  qt_array_data_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d4892 name=FUN_004d4892 size=13 ====

void FUN_004d4892(void)

{
  __cxa_begin_catch();
                    /* WARNING: Subroutine does not return */
                    /* try { // try from 004d489a to 004d489e has its CatchHandler @ 004d4806 */
  __cxa_rethrow();
}


// ==== entry=004d48a0 name=FUN_004d48a0 size=60 ====

void FUN_004d48a0(void)

{
  QArrayData *in_stack_00000020;
  
  if (*(int *)in_stack_00000020 != 0) {
    if (*(int *)in_stack_00000020 == -1) goto LAB_004d48ba;
    LOCK();
    *(int *)in_stack_00000020 = *(int *)in_stack_00000020 + -1;
    UNLOCK();
    if (*(int *)in_stack_00000020 != 0) goto LAB_004d48ba;
  }
  QArrayData::deallocate(in_stack_00000020,2,8);
LAB_004d48ba:
  qmap_freetree_variant_nodes();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d48ca name=FUN_004d48ca size=16 ====

void FUN_004d48ca(void)

{
  QVariant *unaff_RBP;
  
  QVariant::~QVariant(unaff_RBP);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d48f0 name=FUN_004d48f0 size=35 ====

void FUN_004d48f0(void)

{
  QDateTime *unaff_RBP;
  
  qt_array_data_unref();
  QDateTime::~QDateTime(unaff_RBP);
  qt_array_data_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d4914 name=FUN_004d4914 size=24 ====

void FUN_004d4914(void)

{
  qt_array_data_unref();
  qt_array_data_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d492c name=FUN_004d492c size=48 ====

void FUN_004d492c(void)

{
  QLocale *unaff_R12;
  
  qt_array_data_unref();
  qt_array_data_unref();
  qt_array_data_unref();
  QLocale::~QLocale(unaff_R12);
  qt_array_data_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d495c name=FUN_004d495c size=20 ====

void FUN_004d495c(void)

{
  QMimeType *unaff_R13;
  QMimeDatabase *unaff_R14;
  
  qt_array_data_unref();
  QMimeType::~QMimeType(unaff_R13);
  QMimeDatabase::~QMimeDatabase(unaff_R14);
  qt_array_data_unref(&stack0x00000018);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d4970 name=FUN_004d4970 size=50 ====

void FUN_004d4970(void)

{
  QMimeType *unaff_R13;
  QMimeDatabase *unaff_R14;
  undefined8 in_stack_00000008;
  
  qt_array_data_unref();
  qt_array_data_unref();
  QMimeType::~QMimeType(unaff_R13);
  QMimeDatabase::~QMimeDatabase(unaff_R14);
  qt_array_data_unref(in_stack_00000008);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d49a2 name=FUN_004d49a2 size=20 ====

void FUN_004d49a2(void)

{
  QMimeType *unaff_R13;
  QMimeDatabase *unaff_R14;
  
  qt_array_data_unref();
  QMimeType::~QMimeType(unaff_R13);
  QMimeDatabase::~QMimeDatabase(unaff_R14);
  qt_array_data_unref(&stack0x00000018);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d49b6 name=FUN_004d49b6 size=19 ====

void FUN_004d49b6(void)

{
  QMimeType *unaff_R13;
  QMimeDatabase *unaff_R14;
  undefined8 unaff_retaddr;
  undefined8 in_stack_00000008;
  
  qt_array_data_unref();
  qt_array_data_unref(unaff_retaddr);
  QMimeType::~QMimeType(unaff_R13);
  QMimeDatabase::~QMimeDatabase(unaff_R14);
  qt_array_data_unref(in_stack_00000008);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d49c9 name=FUN_004d49c9 size=10 ====

void FUN_004d49c9(void)

{
  QMimeType *unaff_R13;
  QMimeDatabase *unaff_R14;
  undefined8 in_stack_00000008;
  
  qt_array_data_unref();
  QMimeType::~QMimeType(unaff_R13);
  QMimeDatabase::~QMimeDatabase(unaff_R14);
  qt_array_data_unref(in_stack_00000008);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d49e0 name=FUN_004d49e0 size=38 ====

void FUN_004d49e0(void)

{
  long lVar1;
  long unaff_R12;
  
  qt_shared_data_unref();
  lVar1 = unaff_R12 + 0x38;
  do {
    lVar1 = lVar1 + -8;
    qt_array_data_unref(lVar1);
  } while (lVar1 != unaff_R12);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d4a06 name=FUN_004d4a06 size=27 ====

void FUN_004d4a06(void)

{
  qt_shared_data_unref();
  RemoteFileSystemModel_h626248();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d4a22 name=FUN_004d4a22 size=74 ====

void FUN_004d4a22(void)

{
  long unaff_RBX;
  QVariant *unaff_R12;
  QArrayData *in_stack_00000008;
  
  if (*(int *)in_stack_00000008 != 0) {
    if (*(int *)in_stack_00000008 == -1) goto LAB_004d4a3c;
    LOCK();
    *(int *)in_stack_00000008 = *(int *)in_stack_00000008 + -1;
    UNLOCK();
    if (*(int *)in_stack_00000008 != 0) goto LAB_004d4a3c;
  }
  QArrayData::deallocate(in_stack_00000008,1,8);
LAB_004d4a3c:
  QVariant::~QVariant(unaff_R12);
  if (*(_Sp_counted_base<(__gnu_cxx::_Lock_policy)2> **)(unaff_RBX + 8) !=
      (_Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *)0x0) {
    std::_Sp_counted_base<(__gnu_cxx::_Lock_policy)2>::_M_release
              (*(_Sp_counted_base<(__gnu_cxx::_Lock_policy)2> **)(unaff_RBX + 8));
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d4a6c name=FUN_004d4a6c size=17 ====

void FUN_004d4a6c(void)

{
  long unaff_RBX;
  QVariant *unaff_R12;
  _Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *in_stack_00000028;
  
  if (in_stack_00000028 != (_Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *)0x0) {
    std::_Sp_counted_base<(__gnu_cxx::_Lock_policy)2>::_M_release(in_stack_00000028);
  }
  QVariant::~QVariant(unaff_R12);
  if (*(_Sp_counted_base<(__gnu_cxx::_Lock_policy)2> **)(unaff_RBX + 8) !=
      (_Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *)0x0) {
    std::_Sp_counted_base<(__gnu_cxx::_Lock_policy)2>::_M_release
              (*(_Sp_counted_base<(__gnu_cxx::_Lock_policy)2> **)(unaff_RBX + 8));
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d4a7e name=FUN_004d4a7e size=34 ====

void FUN_004d4a7e(void)

{
  _Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *in_stack_00000298;
  
  qt_array_data_unref();
  if (in_stack_00000298 != (_Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *)0x0) {
    std::_Sp_counted_base<(__gnu_cxx::_Lock_policy)2>::_M_release(in_stack_00000298);
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d4aa0 name=FUN_004d4aa0 size=72 ====

void FUN_004d4aa0(void)

{
  _Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *in_stack_00000068;
  
  qt_array_data_unref();
  qt_array_data_unref();
  qt_array_data_unref(&stack0x00000290);
  if (in_stack_00000068 != (_Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *)0x0) {
    std::_Sp_counted_base<(__gnu_cxx::_Lock_policy)2>::_M_release(in_stack_00000068);
  }
  qt_array_data_unref(&stack0x00000020);
  qt_array_data_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d4ae8 name=FUN_004d4ae8 size=28 ====

void FUN_004d4ae8(void)

{
  undefined8 in_stack_00000008;
  _Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *in_stack_00000068;
  
  qt_array_data_unref(in_stack_00000008);
  qt_array_data_unref();
  qt_array_data_unref();
  if (in_stack_00000068 != (_Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *)0x0) {
    std::_Sp_counted_base<(__gnu_cxx::_Lock_policy)2>::_M_release(in_stack_00000068);
  }
  qt_array_data_unref(&stack0x00000020);
  qt_array_data_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d4b04 name=FUN_004d4b04 size=28 ====

void FUN_004d4b04(void)

{
  undefined8 in_stack_00000008;
  _Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *in_stack_00000068;
  
  qt_array_data_unref();
  qt_array_data_unref();
  qt_array_data_unref(in_stack_00000008);
  if (in_stack_00000068 != (_Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *)0x0) {
    std::_Sp_counted_base<(__gnu_cxx::_Lock_policy)2>::_M_release(in_stack_00000068);
  }
  qt_array_data_unref(&stack0x00000020);
  qt_array_data_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d4b20 name=FUN_004d4b20 size=34 ====

void FUN_004d4b20(void)

{
  QIcon *unaff_R12;
  _Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *in_stack_00000298;
  
  QIcon::~QIcon(unaff_R12);
  if (in_stack_00000298 != (_Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *)0x0) {
    std::_Sp_counted_base<(__gnu_cxx::_Lock_policy)2>::_M_release(in_stack_00000298);
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d4b42 name=FUN_004d4b42 size=31 ====

void FUN_004d4b42(void)

{
  undefined8 in_stack_00000008;
  _Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *in_stack_00000068;
  
  qt_array_data_unref(in_stack_00000008);
  qt_array_data_unref();
  qt_array_data_unref();
  if (in_stack_00000068 != (_Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *)0x0) {
    std::_Sp_counted_base<(__gnu_cxx::_Lock_policy)2>::_M_release(in_stack_00000068);
  }
  qt_array_data_unref(&stack0x00000020);
  qt_array_data_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d4b61 name=FUN_004d4b61 size=31 ====

void FUN_004d4b61(void)

{
  undefined8 in_stack_00000008;
  _Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *in_stack_00000068;
  
  qt_array_data_unref(in_stack_00000008);
  qt_array_data_unref();
  qt_array_data_unref();
  if (in_stack_00000068 != (_Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *)0x0) {
    std::_Sp_counted_base<(__gnu_cxx::_Lock_policy)2>::_M_release(in_stack_00000068);
  }
  qt_array_data_unref(&stack0x00000020);
  qt_array_data_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d4b80 name=FUN_004d4b80 size=34 ====

void FUN_004d4b80(void)

{
  _Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *in_stack_00000068;
  
  qt_array_data_unref();
  qt_array_data_unref();
  qt_array_data_unref(&stack0x00000290);
  if (in_stack_00000068 != (_Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *)0x0) {
    std::_Sp_counted_base<(__gnu_cxx::_Lock_policy)2>::_M_release(in_stack_00000068);
  }
  qt_array_data_unref(&stack0x00000020);
  qt_array_data_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d4ba2 name=FUN_004d4ba2 size=13 ====

void FUN_004d4ba2(void)

{
  qt_array_data_unref();
  qt_array_data_unref(&stack0x00000020);
  qt_array_data_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d4baf name=FUN_004d4baf size=13 ====

void FUN_004d4baf(void)

{
  _Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *in_stack_00000298;
  
  qt_array_data_unref();
  if (in_stack_00000298 != (_Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *)0x0) {
    std::_Sp_counted_base<(__gnu_cxx::_Lock_policy)2>::_M_release(in_stack_00000298);
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d4bbc name=FUN_004d4bbc size=13 ====

void FUN_004d4bbc(void)

{
  _Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *in_stack_00000298;
  
  qt_array_data_unref();
  if (in_stack_00000298 != (_Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *)0x0) {
    std::_Sp_counted_base<(__gnu_cxx::_Lock_policy)2>::_M_release(in_stack_00000298);
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d4bc9 name=FUN_004d4bc9 size=16 ====

void FUN_004d4bc9(void)

{
  QIcon *unaff_R13;
  
  QIcon::~QIcon(unaff_R13);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d4bd9 name=FUN_004d4bd9 size=13 ====

void FUN_004d4bd9(void)

{
  _Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *in_stack_00000298;
  
  qt_array_data_unref();
  if (in_stack_00000298 != (_Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *)0x0) {
    std::_Sp_counted_base<(__gnu_cxx::_Lock_policy)2>::_M_release(in_stack_00000298);
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d4be6 name=FUN_004d4be6 size=15 ====

void FUN_004d4be6(void)

{
  qt_array_data_unref();
  qt_array_data_unref(&stack0x00000020);
  qt_array_data_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d4bf5 name=FUN_004d4bf5 size=16 ====

void FUN_004d4bf5(void)

{
  _Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *in_stack_00000298;
  
  qt_array_data_unref();
  if (in_stack_00000298 != (_Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *)0x0) {
    std::_Sp_counted_base<(__gnu_cxx::_Lock_policy)2>::_M_release(in_stack_00000298);
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d4c05 name=FUN_004d4c05 size=16 ====

void FUN_004d4c05(void)

{
  _Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *in_stack_00000298;
  
  qt_array_data_unref();
  if (in_stack_00000298 != (_Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *)0x0) {
    std::_Sp_counted_base<(__gnu_cxx::_Lock_policy)2>::_M_release(in_stack_00000298);
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d4c15 name=FUN_004d4c15 size=16 ====

void FUN_004d4c15(void)

{
  _Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *in_stack_00000298;
  
  qt_array_data_unref();
  if (in_stack_00000298 != (_Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *)0x0) {
    std::_Sp_counted_base<(__gnu_cxx::_Lock_policy)2>::_M_release(in_stack_00000298);
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d4c30 name=FUN_004d4c30 size=20 ====

void FUN_004d4c30(void)

{
  long unaff_R13;
  undefined8 in_stack_00000008;
  
  if (in_stack_00000008._7_1_ != '\0') {
    *(undefined1 *)(unaff_R13 + 0x11) = 0;
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d4c44 name=FUN_004d4c44 size=20 ====

void FUN_004d4c44(void)

{
  long unaff_R13;
  undefined8 in_stack_00000008;
  
  if (in_stack_00000008._7_1_ != '\0') {
    *(undefined1 *)(unaff_R13 + 0x11) = 0;
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d4c58 name=FUN_004d4c58 size=20 ====

void FUN_004d4c58(void)

{
  long unaff_R14;
  undefined8 in_stack_00000008;
  
  if (in_stack_00000008._7_1_ != '\0') {
    *(undefined1 *)(unaff_R14 + 0x11) = 0;
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d4c6c name=FUN_004d4c6c size=20 ====

void FUN_004d4c6c(void)

{
  long unaff_R14;
  undefined8 in_stack_00000008;
  
  if (in_stack_00000008._7_1_ != '\0') {
    *(undefined1 *)(unaff_R14 + 0x11) = 0;
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d4c80 name=FUN_004d4c80 size=19 ====

void FUN_004d4c80(void)

{
  long unaff_R12;
  char unaff_R14B;
  
  if (unaff_R14B != '\0') {
    *(undefined1 *)(unaff_R12 + 0x11) = 0;
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d4c94 name=FUN_004d4c94 size=18 ====

void FUN_004d4c94(void)

{
  long unaff_R13;
  char unaff_R15B;
  
  if (unaff_R15B != '\0') {
    *(undefined1 *)(unaff_R13 + 0x11) = 0;
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d4ca6 name=FUN_004d4ca6 size=15 ====

void FUN_004d4ca6(void)

{
  __cxa_begin_catch();
                    /* WARNING: Subroutine does not return */
                    /* try { // try from 004d4cb0 to 004d4cb4 has its CatchHandler @ 004d4cb5 */
  __cxa_rethrow();
}


// ==== entry=004d4cc6 name=FUN_004d4cc6 size=74 ====

void FUN_004d4cc6(void)

{
  long unaff_RBP;
  char unaff_R13B;
  QVariant *unaff_R14;
  QArrayData *in_stack_00000008;
  
  QVariant::~QVariant((QVariant *)(unaff_RBP + 8));
  QVariant::~QVariant(unaff_R14);
  if (unaff_R13B == '\0') goto LAB_004d4cf6;
  if (*(int *)in_stack_00000008 != 0) {
    if (*(int *)in_stack_00000008 == -1) goto LAB_004d4cf6;
    LOCK();
    *(int *)in_stack_00000008 = *(int *)in_stack_00000008 + -1;
    UNLOCK();
    if (*(int *)in_stack_00000008 != 0) goto LAB_004d4cf6;
  }
  QArrayData::deallocate(in_stack_00000008,1,8);
LAB_004d4cf6:
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d4cfe name=FUN_004d4cfe size=52 ====

void FUN_004d4cfe(void)

{
  QArrayData *in_stack_00000010;
  
  if (*(int *)in_stack_00000010 != 0) {
    if (*(int *)in_stack_00000010 == -1) goto LAB_004d4d18;
    LOCK();
    *(int *)in_stack_00000010 = *(int *)in_stack_00000010 + -1;
    UNLOCK();
    if (*(int *)in_stack_00000010 != 0) goto LAB_004d4d18;
  }
  QArrayData::deallocate(in_stack_00000010,4,8);
LAB_004d4d18:
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d4d44 name=FUN_004d4d44 size=51 ====

void FUN_004d4d44(void)

{
  long unaff_RBX;
  QVariant *unaff_RBP;
  int *piVar1;
  
  QVariant::~QVariant(unaff_RBP);
  piVar1 = *(int **)(unaff_RBX + 0x18);
  if (*piVar1 != 0) {
    if (*piVar1 == -1) goto LAB_004d4d5e;
    LOCK();
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if (*piVar1 != 0) goto LAB_004d4d5e;
    piVar1 = *(int **)(unaff_RBX + 0x18);
  }
  FUN_00624a8a(piVar1);
LAB_004d4d5e:
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d4d78 name=FUN_004d4d78 size=73 ====

void FUN_004d4d78(void)

{
  QAbstractItemModel *unaff_RBX;
  void *unaff_RBP;
  QArrayData *in_stack_00000008;
  
  operator_delete(unaff_RBP,0x20);
  if (*(int *)in_stack_00000008 != 0) {
    if (*(int *)in_stack_00000008 == -1) goto LAB_004d4d9f;
    LOCK();
    *(int *)in_stack_00000008 = *(int *)in_stack_00000008 + -1;
    UNLOCK();
    if (*(int *)in_stack_00000008 != 0) goto LAB_004d4d9f;
  }
  QArrayData::deallocate(in_stack_00000008,2,8);
LAB_004d4d9f:
  QAbstractItemModel::~QAbstractItemModel(unaff_RBX);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d4dc2 name=FUN_004d4dc2 size=19 ====

void FUN_004d4dc2(void)

{
  long unaff_R12;
  char unaff_R13B;
  
  if (unaff_R13B != '\0') {
    *(undefined1 *)(unaff_R12 + 0x11) = 0;
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d4dd6 name=FUN_004d4dd6 size=16 ====

void FUN_004d4dd6(void)

{
  QVariant *unaff_RBP;
  
  QVariant::~QVariant(unaff_RBP);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d4de6 name=FUN_004d4de6 size=31 ====

void FUN_004d4de6(undefined8 param_1,undefined8 param_2,long param_3)

{
  if (param_3 == 1) {
    __cxa_begin_catch();
    __cxa_end_catch();
    return;
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d4e10 name=FUN_004d4e10 size=16 ====

void FUN_004d4e10(void)

{
  qt_byte_array_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d4e20 name=FUN_004d4e20 size=48 ====

void FUN_004d4e20(void)

{
  qt_array_data_unref();
  qt_array_data_unref();
  qt_array_data_unref();
  qt_array_data_unref();
  qt_byte_array_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d4e50 name=FUN_004d4e50 size=18 ====

void FUN_004d4e50(void)

{
  stdfunction_state_destroy(&stack0x00000040);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d4e62 name=FUN_004d4e62 size=75 ====

void FUN_004d4e62(void)

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


// ==== entry=004d4eae name=FUN_004d4eae size=18 ====

void FUN_004d4eae(void)

{
  stdfunction_state_destroy(&stack0x00000040);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d4ec0 name=FUN_004d4ec0 size=75 ====

void FUN_004d4ec0(void)

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


// ==== entry=004d4f0c name=FUN_004d4f0c size=16 ====

void FUN_004d4f0c(void)

{
  qt_byte_array_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d4f1c name=FUN_004d4f1c size=16 ====

void FUN_004d4f1c(void)

{
  qt_byte_array_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d4f2c name=FUN_004d4f2c size=16 ====

void FUN_004d4f2c(void)

{
  qt_byte_array_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d4f3c name=FUN_004d4f3c size=16 ====

void FUN_004d4f3c(void)

{
  qt_byte_array_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d4f4c name=FUN_004d4f4c size=24 ====

void FUN_004d4f4c(void)

{
  qt_byte_array_unref();
  qt_byte_array_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d4f64 name=FUN_004d4f64 size=16 ====

void FUN_004d4f64(void)

{
  qt_byte_array_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d4f74 name=FUN_004d4f74 size=16 ====

void FUN_004d4f74(void)

{
  qt_byte_array_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d4f84 name=FUN_004d4f84 size=24 ====

void FUN_004d4f84(void)

{
  qt_byte_array_unref();
  qt_byte_array_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d4f9c name=FUN_004d4f9c size=16 ====

void FUN_004d4f9c(void)

{
  qt_byte_array_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d4fac name=FUN_004d4fac size=16 ====

void FUN_004d4fac(void)

{
  qt_byte_array_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d4fbc name=FUN_004d4fbc size=16 ====

void FUN_004d4fbc(void)

{
  qt_byte_array_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d4fcc name=FUN_004d4fcc size=17 ====

void FUN_004d4fcc(void)

{
  long unaff_RBX;
  
  qt_byte_array_unref(unaff_RBX + 8);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d4fde name=FUN_004d4fde size=22 ====

void FUN_004d4fde(void)

{
                    /* WARNING: Subroutine does not return */
  __cxa_throw();
}


// ==== entry=004d4ff4 name=FUN_004d4ff4 size=16 ====

void FUN_004d4ff4(void)

{
  __cxa_free_exception();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d5004 name=FUN_004d5004 size=22 ====

void FUN_004d5004(void)

{
                    /* WARNING: Subroutine does not return */
  __cxa_throw();
}


// ==== entry=004d501a name=FUN_004d501a size=16 ====

void FUN_004d501a(void)

{
  __cxa_free_exception();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d502a name=FUN_004d502a size=16 ====

void FUN_004d502a(void)

{
  qt_byte_array_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d503a name=FUN_004d503a size=22 ====

void FUN_004d503a(void)

{
                    /* WARNING: Subroutine does not return */
  __cxa_throw();
}


// ==== entry=004d5050 name=FUN_004d5050 size=16 ====

void FUN_004d5050(void)

{
  __cxa_free_exception();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d5060 name=FUN_004d5060 size=22 ====

void FUN_004d5060(void)

{
                    /* WARNING: Subroutine does not return */
  __cxa_throw();
}


// ==== entry=004d5076 name=FUN_004d5076 size=16 ====

void FUN_004d5076(void)

{
  __cxa_free_exception();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d5086 name=FUN_004d5086 size=22 ====

void FUN_004d5086(void)

{
                    /* WARNING: Subroutine does not return */
  __cxa_throw();
}


// ==== entry=004d509c name=FUN_004d509c size=16 ====

void FUN_004d509c(void)

{
  __cxa_free_exception();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d50ac name=FUN_004d50ac size=22 ====

void FUN_004d50ac(void)

{
                    /* WARNING: Subroutine does not return */
  __cxa_throw();
}


// ==== entry=004d50c2 name=FUN_004d50c2 size=16 ====

void FUN_004d50c2(void)

{
  __cxa_free_exception();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d50d2 name=FUN_004d50d2 size=22 ====

void FUN_004d50d2(void)

{
                    /* WARNING: Subroutine does not return */
  __cxa_throw();
}


// ==== entry=004d50e8 name=FUN_004d50e8 size=16 ====

void FUN_004d50e8(void)

{
  __cxa_free_exception();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d50f8 name=FUN_004d50f8 size=22 ====

void FUN_004d50f8(void)

{
                    /* WARNING: Subroutine does not return */
  __cxa_throw();
}


// ==== entry=004d510e name=FUN_004d510e size=16 ====

void FUN_004d510e(void)

{
  __cxa_free_exception();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d511e name=FUN_004d511e size=22 ====

void FUN_004d511e(void)

{
                    /* WARNING: Subroutine does not return */
  __cxa_throw();
}


// ==== entry=004d5134 name=FUN_004d5134 size=16 ====

void FUN_004d5134(void)

{
  __cxa_free_exception();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d5144 name=FUN_004d5144 size=22 ====

void FUN_004d5144(void)

{
                    /* WARNING: Subroutine does not return */
                    /* try { // try from 004d5155 to 004d516f has its CatchHandler @ 004d5170 */
  __cxa_throw();
}


// ==== entry=004d515a name=FUN_004d515a size=22 ====

void FUN_004d515a(void)

{
                    /* WARNING: Subroutine does not return */
  __cxa_throw();
}


// ==== entry=004d5170 name=FUN_004d5170 size=5 ====

void FUN_004d5170(void)

{
                    /* catch() { ... } // from try @ 004d5155 with catch @ 004d5170 */
  qt_byte_array_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d5175 name=FUN_004d5175 size=24 ====

void FUN_004d5175(void)

{
  __cxa_free_exception();
  qt_byte_array_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d518e name=FUN_004d518e size=22 ====

void FUN_004d518e(void)

{
                    /* WARNING: Subroutine does not return */
                    /* try { // try from 004d519f to 004d51a3 has its CatchHandler @ 004d51a4 */
  __cxa_throw();
}


// ==== entry=004d51a4 name=FUN_004d51a4 size=5 ====

void FUN_004d51a4(void)

{
                    /* catch() { ... } // from try @ 004d519f with catch @ 004d51a4 */
  stdfunction_state_destroy(&stack0x00000040);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d51a9 name=FUN_004d51a9 size=26 ====

void FUN_004d51a9(void)

{
  __cxa_free_exception();
  stdfunction_state_destroy(&stack0x00000040);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d51c3 name=FUN_004d51c3 size=75 ====

void FUN_004d51c3(void)

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


// ==== entry=004d520e name=FUN_004d520e size=22 ====

void FUN_004d520e(void)

{
                    /* WARNING: Subroutine does not return */
                    /* try { // try from 004d521f to 004d5223 has its CatchHandler @ 004d5224 */
  __cxa_throw();
}


// ==== entry=004d5224 name=FUN_004d5224 size=5 ====

void FUN_004d5224(void)

{
                    /* catch() { ... } // from try @ 004d521f with catch @ 004d5224 */
  stdfunction_state_destroy(&stack0x00000040);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d5229 name=FUN_004d5229 size=26 ====

void FUN_004d5229(void)

{
  __cxa_free_exception();
  stdfunction_state_destroy(&stack0x00000040);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d5243 name=FUN_004d5243 size=75 ====

void FUN_004d5243(void)

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


// ==== entry=004d528e name=FUN_004d528e size=22 ====

void FUN_004d528e(void)

{
                    /* WARNING: Subroutine does not return */
                    /* try { // try from 004d529f to 004d52a3 has its CatchHandler @ 004d52a4 */
  __cxa_throw();
}


// ==== entry=004d52a4 name=FUN_004d52a4 size=5 ====

void FUN_004d52a4(void)

{
                    /* catch() { ... } // from try @ 004d529f with catch @ 004d52a4 */
  stdfunction_state_destroy(&stack0x00000040);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d52a9 name=FUN_004d52a9 size=26 ====

void FUN_004d52a9(void)

{
  __cxa_free_exception();
  stdfunction_state_destroy(&stack0x00000040);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d52c3 name=FUN_004d52c3 size=75 ====

void FUN_004d52c3(void)

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


// ==== entry=004d530e name=FUN_004d530e size=32 ====

void FUN_004d530e(void)

{
  qt_byte_array_unref();
  __cxa_free_exception();
  qt_byte_array_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d532e name=FUN_004d532e size=24 ====

void FUN_004d532e(void)

{
  qt_byte_array_unref();
  __cxa_free_exception();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d5346 name=FUN_004d5346 size=24 ====

void FUN_004d5346(void)

{
  qt_byte_array_unref();
  __cxa_free_exception();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d535e name=FUN_004d535e size=6 ====

void FUN_004d535e(void)

{
                    /* catch() { ... } // from try @ 004d5395 with catch @ 004d535f */
  qt_byte_array_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d5364 name=FUN_004d5364 size=32 ====

void FUN_004d5364(void)

{
  qt_byte_array_unref();
  __cxa_free_exception();
  qt_byte_array_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d5384 name=FUN_004d5384 size=22 ====

void FUN_004d5384(void)

{
                    /* WARNING: Subroutine does not return */
                    /* try { // try from 004d5395 to 004d53af has its CatchHandler @ 004d535f */
  __cxa_throw();
}


// ==== entry=004d539a name=FUN_004d539a size=22 ====

void FUN_004d539a(void)

{
                    /* WARNING: Subroutine does not return */
  __cxa_throw();
}


// ==== entry=004d53b0 name=FUN_004d53b0 size=16 ====

void FUN_004d53b0(void)

{
  qt_byte_array_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d53c0 name=FUN_004d53c0 size=16 ====

void FUN_004d53c0(void)

{
  qt_byte_array_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d53d0 name=FUN_004d53d0 size=17 ====

void FUN_004d53d0(void)

{
  long unaff_RBX;
  
  qt_byte_array_unref(unaff_RBX + 8);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d53e2 name=FUN_004d53e2 size=17 ====

void FUN_004d53e2(void)

{
  long unaff_RBP;
  
  qt_byte_array_unref(unaff_RBP + 8);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d53f4 name=FUN_004d53f4 size=21 ====

void FUN_004d53f4(void)

{
  void *unaff_RBX;
  
  operator_delete(unaff_RBX,0x10);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d540a name=FUN_004d540a size=21 ====

void FUN_004d540a(void)

{
  void *unaff_RBX;
  
  operator_delete(unaff_RBX,0x18);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d5420 name=FUN_004d5420 size=21 ====

void FUN_004d5420(void)

{
  void *unaff_RBX;
  
  operator_delete(unaff_RBX,0x20);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d5436 name=FUN_004d5436 size=24 ====

void FUN_004d5436(void)

{
  qt_array_data_unref();
  qt_shared_data_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d544e name=FUN_004d544e size=94 ====

void FUN_004d544e(void)

{
  long unaff_RBX;
  code *in_stack_00000030;
  code *in_stack_00000050;
  code *in_stack_00000078;
  
  if (in_stack_00000078 != (code *)0x0) {
    (*in_stack_00000078)(unaff_RBX + 8,unaff_RBX + 8,3);
  }
  if (in_stack_00000030 != (code *)0x0) {
    (*in_stack_00000030)();
  }
  if (in_stack_00000050 != (code *)0x0) {
    (*in_stack_00000050)();
  }
  qt_shared_data_unref(&stack0x00000018);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d54ac name=FUN_004d54ac size=24 ====

void FUN_004d54ac(void)

{
  undefined8 unaff_retaddr;
  
  qt_array_data_unref(unaff_retaddr);
  qt_shared_data_unref();
  qt_shared_data_unref(&stack0x00000018);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d54c4 name=FUN_004d54c4 size=15 ====

void FUN_004d54c4(void)

{
  stdfunction_state_destroy();
  qt_shared_data_unref(&stack0x00000018);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d54d4 name=FUN_004d54d4 size=64 ====

void FUN_004d54d4(void)

{
  QVariant *in_stack_00000008;
  undefined8 in_stack_00000028;
  QVariant *in_stack_00000030;
  undefined8 in_stack_00000038;
  
  QVariant::~QVariant(in_stack_00000030);
  qt_array_data_unref();
  QVariant::~QVariant(in_stack_00000008);
  qt_array_data_unref(in_stack_00000028);
  qmap_freetree_variant_nodes(in_stack_00000038);
  qt_shared_data_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d5514 name=FUN_004d5514 size=10 ====

void FUN_004d5514(void)

{
  qt_byte_array_unref();
  qt_shared_data_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d551e name=FUN_004d551e size=12 ====

void FUN_004d551e(void)

{
  undefined8 in_stack_00000018;
  undefined8 in_stack_00000028;
  undefined8 in_stack_00000038;
  
  qt_array_data_unref(in_stack_00000018);
  qt_array_data_unref(in_stack_00000028);
  qmap_freetree_variant_nodes(in_stack_00000038);
  qt_shared_data_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d552a name=FUN_004d552a size=44 ====

void FUN_004d552a(void)

{
  QFile *unaff_R15;
  undefined8 in_stack_00000008;
  undefined8 in_stack_00000018;
  
  qt_byte_array_unref();
  qatomic_unref_call_deleter2(in_stack_00000008);
  qt_byte_array_unref(in_stack_00000018);
  QFile::~QFile(unaff_R15);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d5556 name=FUN_004d5556 size=16 ====

void FUN_004d5556(void)

{
  qt_array_data_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d5566 name=FUN_004d5566 size=16 ====

void FUN_004d5566(void)

{
  qt_array_data_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d5580 name=FUN_004d5580 size=83 ====

void FUN_004d5580(void)

{
  code *pcVar1;
  QThread *unaff_RBX;
  void *unaff_RBP;
  _func_void_Node_ptr *p_Var2;
  
  operator_delete(unaff_RBP,0x10);
  p_Var2 = *(_func_void_Node_ptr **)(unaff_RBX + 0x28);
  pcVar1 = p_Var2 + 0x10;
  if (*(int *)(p_Var2 + 0x10) == 0) {
LAB_004d559c:
    QHashData::free_helper(p_Var2);
  }
  else if (*(int *)(p_Var2 + 0x10) != -1) {
    LOCK();
    *(int *)pcVar1 = *(int *)pcVar1 + -1;
    UNLOCK();
    if (*(int *)pcVar1 == 0) {
      p_Var2 = *(_func_void_Node_ptr **)(unaff_RBX + 0x28);
      goto LAB_004d559c;
    }
  }
  p_Var2 = *(_func_void_Node_ptr **)(unaff_RBX + 0x20);
  pcVar1 = p_Var2 + 0x10;
  if (*(int *)(p_Var2 + 0x10) != 0) {
    if (*(int *)(p_Var2 + 0x10) == -1) goto LAB_004d55c3;
    LOCK();
    *(int *)pcVar1 = *(int *)pcVar1 + -1;
    UNLOCK();
    if (*(int *)pcVar1 != 0) goto LAB_004d55c3;
    p_Var2 = *(_func_void_Node_ptr **)(unaff_RBX + 0x20);
  }
  QHashData::free_helper(p_Var2);
LAB_004d55c3:
  QThread::~QThread(unaff_RBX);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d55d3 name=FUN_004d55d3 size=54 ====

void FUN_004d55d3(void)

{
  code *pcVar1;
  QThread *unaff_RBX;
  void *unaff_RBP;
  _func_void_Node_ptr *p_Var2;
  
  operator_delete(unaff_RBP,8);
  p_Var2 = *(_func_void_Node_ptr **)(unaff_RBX + 0x28);
  pcVar1 = p_Var2 + 0x10;
  if (*(int *)(p_Var2 + 0x10) == 0) {
LAB_004d559c:
    QHashData::free_helper(p_Var2);
  }
  else if (*(int *)(p_Var2 + 0x10) != -1) {
    LOCK();
    *(int *)pcVar1 = *(int *)pcVar1 + -1;
    UNLOCK();
    if (*(int *)pcVar1 == 0) {
      p_Var2 = *(_func_void_Node_ptr **)(unaff_RBX + 0x28);
      goto LAB_004d559c;
    }
  }
  p_Var2 = *(_func_void_Node_ptr **)(unaff_RBX + 0x20);
  pcVar1 = p_Var2 + 0x10;
  if (*(int *)(p_Var2 + 0x10) != 0) {
    if (*(int *)(p_Var2 + 0x10) == -1) goto LAB_004d55c3;
    LOCK();
    *(int *)pcVar1 = *(int *)pcVar1 + -1;
    UNLOCK();
    if (*(int *)pcVar1 != 0) goto LAB_004d55c3;
    p_Var2 = *(_func_void_Node_ptr **)(unaff_RBX + 0x20);
  }
  QHashData::free_helper(p_Var2);
LAB_004d55c3:
  QThread::~QThread(unaff_RBX);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d560a name=FUN_004d560a size=55 ====

void FUN_004d560a(void)

{
  QFileInfo *unaff_R12;
  QDateTime *in_stack_00000008;
  ulong in_stack_00000020;
  
  QDateTime::~QDateTime(in_stack_00000008);
  QFileInfo::~QFileInfo(unaff_R12);
  if ((in_stack_00000020 != 0) && ((in_stack_00000020 & 1) != 0)) {
    QReadWriteLock::unlock();
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d5642 name=FUN_004d5642 size=27 ====

void FUN_004d5642(void)

{
  qt_shared_data_unref();
  qt_shared_data_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d565d name=FUN_004d565d size=36 ====

void FUN_004d565d(void)

{
  byte unaff_R13B;
  undefined7 unaff_000000a9;
  
  qt_shared_data_unref();
  if ((CONCAT71(unaff_000000a9,unaff_R13B) != 0) && ((unaff_R13B & 1) != 0)) {
    QReadWriteLock::unlock();
  }
  qt_shared_data_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d5682 name=FUN_004d5682 size=31 ====

void FUN_004d5682(void)

{
  byte unaff_BPL;
  undefined7 unaff_00000029;
  
  if ((CONCAT71(unaff_00000029,unaff_BPL) != 0) && ((unaff_BPL & 1) != 0)) {
    QReadWriteLock::unlock();
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d56a1 name=FUN_004d56a1 size=16 ====

void FUN_004d56a1(void)

{
  qt_array_data_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d56b2 name=FUN_004d56b2 size=39 ====

void FUN_004d56b2(void)

{
  byte unaff_BPL;
  undefined7 unaff_00000029;
  
  qt_array_data_unref();
  if ((CONCAT71(unaff_00000029,unaff_BPL) != 0) && ((unaff_BPL & 1) != 0)) {
    QReadWriteLock::unlock();
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d56da name=FUN_004d56da size=39 ====

void FUN_004d56da(void)

{
  byte unaff_R15B;
  undefined7 unaff_000000b9;
  
  if ((CONCAT71(unaff_000000b9,unaff_R15B) != 0) && ((unaff_R15B & 1) != 0)) {
    QReadWriteLock::unlock();
  }
  qt_array_data_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d5702 name=FUN_004d5702 size=31 ====

void FUN_004d5702(void)

{
  byte unaff_BPL;
  undefined7 unaff_00000029;
  
  if ((CONCAT71(unaff_00000029,unaff_BPL) != 0) && ((unaff_BPL & 1) != 0)) {
    QReadWriteLock::unlock();
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d5722 name=FUN_004d5722 size=16 ====

void FUN_004d5722(void)

{
  qt_array_data_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d5732 name=FUN_004d5732 size=31 ====

void FUN_004d5732(void)

{
  byte unaff_R14B;
  undefined7 unaff_000000b1;
  
  if ((CONCAT71(unaff_000000b1,unaff_R14B) != 0) && ((unaff_R14B & 1) != 0)) {
    QReadWriteLock::unlock();
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d5752 name=FUN_004d5752 size=39 ====

void FUN_004d5752(void)

{
  byte unaff_BPL;
  undefined7 unaff_00000029;
  
  qt_array_data_unref();
  if ((CONCAT71(unaff_00000029,unaff_BPL) != 0) && ((unaff_BPL & 1) != 0)) {
    QReadWriteLock::unlock();
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d5779 name=FUN_004d5779 size=12 ====

void FUN_004d5779(void)

{
  byte unaff_BPL;
  undefined7 unaff_00000029;
  
  qt_shared_data_unref(&stack0x00000008);
  if ((CONCAT71(unaff_00000029,unaff_BPL) != 0) && ((unaff_BPL & 1) != 0)) {
    QReadWriteLock::unlock();
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d5786 name=FUN_004d5786 size=16 ====

void FUN_004d5786(void)

{
  qt_array_data_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d5796 name=FUN_004d5796 size=16 ====

void FUN_004d5796(void)

{
  QVariant *unaff_RBX;
  
  QVariant::~QVariant(unaff_RBX);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d57a6 name=FUN_004d57a6 size=40 ====

void FUN_004d57a6(void)

{
  QVariant *unaff_RBP;
  QIcon *unaff_R12;
  
  QIcon::~QIcon(unaff_R12);
  qt_array_data_unref();
  qt_array_data_unref();
  QVariant::~QVariant(unaff_RBP);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d57ce name=FUN_004d57ce size=35 ====

void FUN_004d57ce(void)

{
  QVariant *unaff_RBP;
  QVariant *unaff_retaddr;
  undefined8 in_stack_00000020;
  
  qt_array_data_unref(in_stack_00000020);
  QVariant::~QVariant(unaff_RBP);
  QVariant::~QVariant(unaff_retaddr);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d57f1 name=FUN_004d57f1 size=35 ====

void FUN_004d57f1(void)

{
  QVariant *unaff_RBP;
  QVariant *unaff_retaddr;
  undefined8 in_stack_00000020;
  
  qt_array_data_unref(in_stack_00000020);
  QVariant::~QVariant(unaff_RBP);
  QVariant::~QVariant(unaff_retaddr);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d5814 name=FUN_004d5814 size=36 ====

void FUN_004d5814(void)

{
  QVariant *unaff_R13;
  QVariant *in_stack_00000010;
  undefined8 in_stack_00000048;
  
  qt_array_data_unref(in_stack_00000048);
  QVariant::~QVariant(unaff_R13);
  QVariant::~QVariant(in_stack_00000010);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d5838 name=FUN_004d5838 size=36 ====

void FUN_004d5838(void)

{
  QVariant *unaff_R12;
  QVariant *in_stack_00000010;
  undefined8 in_stack_00000058;
  
  qt_array_data_unref(in_stack_00000058);
  QVariant::~QVariant(unaff_R12);
  QVariant::~QVariant(in_stack_00000010);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d585c name=FUN_004d585c size=36 ====

void FUN_004d585c(void)

{
  QVariant *unaff_R12;
  QVariant *in_stack_00000010;
  undefined8 in_stack_00000058;
  
  qt_array_data_unref(in_stack_00000058);
  QVariant::~QVariant(unaff_R12);
  QVariant::~QVariant(in_stack_00000010);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d5880 name=FUN_004d5880 size=36 ====

void FUN_004d5880(void)

{
  QVariant *unaff_RBP;
  QVariant *in_stack_00000008;
  undefined8 in_stack_00000040;
  
  qt_array_data_unref(in_stack_00000040);
  QVariant::~QVariant(unaff_RBP);
  QVariant::~QVariant(in_stack_00000008);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d58a4 name=FUN_004d58a4 size=27 ====

void FUN_004d58a4(void)

{
  long unaff_R12;
  long unaff_R13;
  
  QVariant::~QVariant((QVariant *)(unaff_R13 + 8));
  QVariant::~QVariant((QVariant *)(unaff_R12 + 8));
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d58bf name=FUN_004d58bf size=41 ====

void FUN_004d58bf(void)

{
  QVariant *in_stack_00000028;
  QVariant *in_stack_00000030;
  undefined8 in_stack_00000090;
  
  qt_array_data_unref(in_stack_00000090);
  QVariant::~QVariant(in_stack_00000028);
  QVariant::~QVariant(in_stack_00000030);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d58e8 name=FUN_004d58e8 size=38 ====

void FUN_004d58e8(void)

{
  QVariant *in_stack_00000028;
  QVariant *in_stack_00000030;
  undefined8 in_stack_00000058;
  
  qt_array_data_unref(in_stack_00000058);
  QVariant::~QVariant(in_stack_00000028);
  QVariant::~QVariant(in_stack_00000030);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d590e name=FUN_004d590e size=36 ====

void FUN_004d590e(void)

{
  QVariant *in_stack_00000010;
  QVariant *in_stack_00000028;
  
  qt_array_data_unref();
  QVariant::~QVariant(in_stack_00000010);
  QVariant::~QVariant(in_stack_00000028);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d5932 name=FUN_004d5932 size=21 ====

void FUN_004d5932(void)

{
  nothrow_t *unaff_R15;
  
  operator_delete((void *)0x0,unaff_R15);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d5950 name=FUN_004d5950 size=24 ====

void FUN_004d5950(void)

{
  QDateTime *unaff_RBX;
  
  QDateTime::~QDateTime(unaff_RBX);
  qt_array_data_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d5968 name=FUN_004d5968 size=10 ====

void FUN_004d5968(void)

{
  QDateTime *unaff_RBX;
  
  QDateTime::~QDateTime(unaff_RBX);
  qt_array_data_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d5972 name=FUN_004d5972 size=10 ====

void FUN_004d5972(void)

{
  QDateTime *unaff_RBX;
  
  QDateTime::~QDateTime(unaff_RBX);
  qt_array_data_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d597c name=FUN_004d597c size=28 ====

void FUN_004d597c(void)

{
  undefined8 in_stack_00000008;
  undefined8 in_stack_00000010;
  
  qt_array_data_unref(in_stack_00000010);
  qt_array_data_unref(in_stack_00000008);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d5998 name=FUN_004d5998 size=20 ====

void FUN_004d5998(void)

{
  qt_array_data_unref();
  qt_array_data_unref(&stack0x00000028);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d59ac name=FUN_004d59ac size=51 ====

void FUN_004d59ac(void)

{
  QFileInfo *unaff_RBP;
  
  qt_array_data_unref();
  qt_array_data_unref();
  qt_array_data_unref();
  QFileInfo::~QFileInfo(unaff_RBP);
  FileSystemItem_metaObject();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d59e0 name=FUN_004d59e0 size=16 ====

void FUN_004d59e0(void)

{
  FileSystemItem_metaObject();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d59f0 name=FUN_004d59f0 size=35 ====

void FUN_004d59f0(void)

{
  QDateTime *unaff_RBP;
  
  QDateTime::~QDateTime(unaff_RBP);
  qt_array_data_unref();
  FileSystemItem_metaObject();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d5a13 name=FUN_004d5a13 size=10 ====

void FUN_004d5a13(void)

{
  qt_array_data_unref();
  qt_array_data_unref();
  FileSystemItem_metaObject();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d5a1d name=FUN_004d5a1d size=10 ====

void FUN_004d5a1d(void)

{
  QFile *unaff_RBP;
  
  QFile::~QFile(unaff_RBP);
  qt_array_data_unref();
  FileSystemItem_metaObject();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d5a27 name=FUN_004d5a27 size=11 ====

void FUN_004d5a27(void)

{
  qt_array_data_unref();
  qt_array_data_unref();
  FileSystemItem_metaObject();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d5a32 name=FUN_004d5a32 size=60 ====

void FUN_004d5a32(void)

{
  QArrayData *in_stack_00000008;
  
  if (*(int *)in_stack_00000008 != 0) {
    if (*(int *)in_stack_00000008 == -1) goto LAB_004d5a4c;
    LOCK();
    *(int *)in_stack_00000008 = *(int *)in_stack_00000008 + -1;
    UNLOCK();
    if (*(int *)in_stack_00000008 != 0) goto LAB_004d5a4c;
  }
  QArrayData::deallocate(in_stack_00000008,2,8);
LAB_004d5a4c:
  FileSystemItem_metaObject();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d5a70 name=FUN_004d5a70 size=48 ====

/* WARNING: Removing unreachable block (ram,0x004d5a8d) */

void FUN_004d5a70(undefined8 *param_1)

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


// ==== entry=004d5aa0 name=FUN_004d5aa0 size=24 ====

void FUN_004d5aa0(void)

{
  qt_array_data_unref();
  qt_array_data_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d5ab8 name=FUN_004d5ab8 size=35 ====

void FUN_004d5ab8(void)

{
  QLocale *unaff_R14;
  
  qt_array_data_unref();
  qt_array_data_unref();
  QLocale::~QLocale(unaff_R14);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d5adb name=FUN_004d5adb size=10 ====

void FUN_004d5adb(void)

{
  QLocale *unaff_R14;
  
  qt_array_data_unref();
  QLocale::~QLocale(unaff_R14);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d5ae6 name=FUN_004d5ae6 size=56 ====

void FUN_004d5ae6(void)

{
  qt_array_data_unref();
  qt_array_data_unref();
  qt_array_data_unref(&stack0x00000008);
  qt_array_data_unref();
  qt_array_data_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d5b1e name=FUN_004d5b1e size=15 ====

void FUN_004d5b1e(void)

{
  qt_array_data_unref();
  qt_array_data_unref(&stack0x00000008);
  qt_array_data_unref();
  qt_array_data_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d5b2d name=FUN_004d5b2d size=12 ====

void FUN_004d5b2d(void)

{
  qt_array_data_unref(&stack0x00000008);
  qt_array_data_unref();
  qt_array_data_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d5b3a name=FUN_004d5b3a size=32 ====

void FUN_004d5b3a(void)

{
  QVariant *unaff_R12;
  
  qt_byte_array_unref();
  QVariant::~QVariant(unaff_R12);
  qt_array_data_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d5b5a name=FUN_004d5b5a size=69 ====

void FUN_004d5b5a(void)

{
  undefined8 in_stack_00000008;
  undefined8 in_stack_00000010;
  long in_stack_00000050;
  long in_stack_00000058;
  
  qt_array_data_unref(in_stack_00000008);
  qt_array_data_unref(in_stack_00000010);
  FUN_004d5a70(in_stack_00000058 + -0x18);
  FUN_004d5a70(in_stack_00000050 + -0x18);
  json_value_destruct();
  qt_array_data_unref();
  qt_array_data_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d5b9f name=FUN_004d5b9f size=39 ====

void FUN_004d5b9f(void)

{
  QVariant *unaff_R12;
  
  QVariant::~QVariant(unaff_R12);
  qt_byte_array_unref(&stack0x00000060);
  QVariant::~QVariant((QVariant *)&stack0x00000090);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d5bc6 name=FUN_004d5bc6 size=22 ====

void FUN_004d5bc6(void)

{
  undefined8 in_stack_00000008;
  undefined8 in_stack_00000010;
  
  json_value_destruct(in_stack_00000010);
  json_value_destruct(in_stack_00000008);
  json_value_destruct();
  qt_array_data_unref();
  qt_array_data_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d5bdc name=FUN_004d5bdc size=12 ====

void FUN_004d5bdc(void)

{
  qt_array_data_unref(&stack0x00000058);
  json_value_destruct();
  qt_array_data_unref();
  qt_array_data_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d5be8 name=FUN_004d5be8 size=25 ====

void FUN_004d5be8(void)

{
  undefined8 in_stack_00000008;
  undefined8 in_stack_00000010;
  long in_stack_00000050;
  
  json_value_destruct(in_stack_00000010);
  json_value_destruct(in_stack_00000008);
  FUN_004d5a70(in_stack_00000050 + -0x18);
  json_value_destruct();
  qt_array_data_unref();
  qt_array_data_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d5c01 name=FUN_004d5c01 size=24 ====

void FUN_004d5c01(void)

{
  json_value_destruct();
  json_value_destruct();
  json_value_destruct();
  qt_array_data_unref();
  qt_array_data_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d5c1a name=FUN_004d5c1a size=60 ====

void FUN_004d5c1a(void)

{
  code *pcVar1;
  QTranslator *unaff_RBX;
  _func_void_Node_ptr *p_Var2;
  
  p_Var2 = *(_func_void_Node_ptr **)(unaff_RBX + 0x18);
  pcVar1 = p_Var2 + 0x10;
  if (*(int *)(p_Var2 + 0x10) != 0) {
    if (*(int *)(p_Var2 + 0x10) == -1) goto LAB_004d5c35;
    LOCK();
    *(int *)pcVar1 = *(int *)pcVar1 + -1;
    UNLOCK();
    if (*(int *)pcVar1 != 0) goto LAB_004d5c35;
    p_Var2 = *(_func_void_Node_ptr **)(unaff_RBX + 0x18);
  }
  QHashData::free_helper(p_Var2);
LAB_004d5c35:
  QTranslator::~QTranslator(unaff_RBX);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d5c56 name=FUN_004d5c56 size=55 ====

void FUN_004d5c56(void)

{
  undefined8 unaff_retaddr;
  undefined8 in_stack_00000020;
  QDir *in_stack_00000028;
  undefined8 in_stack_00000038;
  
  qt_shared_data_unref();
  qt_array_data_unref(unaff_retaddr);
  QDir::~QDir(in_stack_00000028);
  qt_array_data_unref(in_stack_00000038);
  qmap_freetree_variant_nodes_b(in_stack_00000020);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d5c8d name=FUN_004d5c8d size=10 ====

void FUN_004d5c8d(void)

{
  undefined8 in_stack_00000020;
  
  qt_array_data_unref();
  qmap_freetree_variant_nodes_b(in_stack_00000020);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d5c97 name=FUN_004d5c97 size=29 ====

void FUN_004d5c97(void)

{
  undefined8 unaff_retaddr;
  undefined8 in_stack_00000020;
  QDir *in_stack_00000028;
  undefined8 in_stack_00000030;
  undefined8 in_stack_00000038;
  
  qt_array_data_unref(unaff_retaddr);
  qt_array_data_unref();
  FUN_0054be70(in_stack_00000030);
  QDir::~QDir(in_stack_00000028);
  qt_array_data_unref(in_stack_00000038);
  qmap_freetree_variant_nodes_b(in_stack_00000020);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d5cb4 name=FUN_004d5cb4 size=18 ====

void FUN_004d5cb4(void)

{
  undefined8 in_stack_00000020;
  QDir *in_stack_00000028;
  undefined8 in_stack_00000030;
  undefined8 in_stack_00000038;
  
  qt_array_data_unref();
  qt_array_data_unref();
  FUN_0054be70(in_stack_00000030);
  QDir::~QDir(in_stack_00000028);
  qt_array_data_unref(in_stack_00000038);
  qmap_freetree_variant_nodes_b(in_stack_00000020);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d5cc6 name=FUN_004d5cc6 size=45 ====

void FUN_004d5cc6(void)

{
  undefined8 unaff_retaddr;
  undefined8 in_stack_00000020;
  QDir *in_stack_00000028;
  undefined8 in_stack_00000030;
  undefined8 in_stack_00000038;
  
  json_value_destruct(unaff_retaddr);
  json_value_destruct();
  qt_array_data_unref();
  qt_array_data_unref(&stack0x00000068);
  json_value_destruct();
  qt_array_data_unref();
  FUN_0054be70(in_stack_00000030);
  QDir::~QDir(in_stack_00000028);
  qt_array_data_unref(in_stack_00000038);
  qmap_freetree_variant_nodes_b(in_stack_00000020);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d5cf3 name=FUN_004d5cf3 size=18 ====

void FUN_004d5cf3(void)

{
  undefined8 unaff_retaddr;
  undefined8 in_stack_00000020;
  QDir *in_stack_00000028;
  undefined8 in_stack_00000038;
  
  qt_shared_data_unref();
  qt_array_data_unref(unaff_retaddr);
  QDir::~QDir(in_stack_00000028);
  qt_array_data_unref(in_stack_00000038);
  qmap_freetree_variant_nodes_b(in_stack_00000020);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d5d10 name=FUN_004d5d10 size=92 ====

void FUN_004d5d10(void)

{
  QIconEngine *unaff_RBX;
  QArrayData *pQVar1;
  
                    /* catch() { ... } // from try @ 004d5d79 with catch @ 004d5d11 */
  __cxa_end_catch();
  if (*(void **)(unaff_RBX + 0x18) != (void *)0x0) {
    operator_delete(*(void **)(unaff_RBX + 0x18));
  }
  pQVar1 = *(QArrayData **)(unaff_RBX + 8);
  if (*(int *)pQVar1 != 0) {
    if (*(int *)pQVar1 == -1) goto LAB_004d5d4f;
    LOCK();
    *(int *)pQVar1 = *(int *)pQVar1 + -1;
    UNLOCK();
    if (*(int *)pQVar1 != 0) goto LAB_004d5d4f;
    pQVar1 = *(QArrayData **)(unaff_RBX + 8);
  }
  QArrayData::deallocate(pQVar1,2,8);
LAB_004d5d4f:
  QIconEngine::~QIconEngine(unaff_RBX);
  operator_delete(unaff_RBX,0x30);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d5d6c name=FUN_004d5d6c size=32 ====

void FUN_004d5d6c(void)

{
  QPixmap *unaff_R12;
  QPixmap *unaff_R14;
  
  __cxa_begin_catch();
  for (; unaff_R12 != unaff_R14; unaff_R14 = unaff_R14 + 0x28) {
    QPixmap::~QPixmap(unaff_R14);
  }
                    /* WARNING: Subroutine does not return */
                    /* try { // try from 004d5d79 to 004d5d7d has its CatchHandler @ 004d5d11 */
  __cxa_rethrow();
}


// ==== entry=004d5d8c name=FUN_004d5d8c size=24 ====

void FUN_004d5d8c(void)

{
  QIcon *unaff_RBX;
  QPixmap *unaff_R15;
  
  QIcon::~QIcon(unaff_RBX);
  QPixmap::~QPixmap(unaff_R15);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d5da4 name=FUN_004d5da4 size=16 ====

void FUN_004d5da4(void)

{
  QPixmap *unaff_R14;
  
  QPixmap::~QPixmap(unaff_R14);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d5db4 name=FUN_004d5db4 size=14 ====

void FUN_004d5db4(void)

{
  long unaff_R12;
  
  *(undefined1 *)(unaff_R12 + 0x10) = 0;
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d5dc2 name=FUN_004d5dc2 size=14 ====

void FUN_004d5dc2(void)

{
  long unaff_R12;
  
  *(undefined1 *)(unaff_R12 + 0x10) = 0;
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d5dd0 name=FUN_004d5dd0 size=21 ====

void FUN_004d5dd0(void)

{
  void *unaff_RBP;
  
  operator_delete(unaff_RBP,0x20);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d5de6 name=FUN_004d5de6 size=62 ====

void FUN_004d5de6(void)

{
  void *pvVar1;
  QObject *unaff_RBX;
  void *unaff_RBP;
  
  operator_delete(unaff_RBP,0x20);
  pvVar1 = *(void **)(unaff_RBX + 0x20);
  if (pvVar1 != (void *)0x0) {
    FUN_00a80de0(pvVar1);
    operator_delete(pvVar1,0x20);
  }
  QObject::~QObject(unaff_RBX);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d5e24 name=FUN_004d5e24 size=14 ====

void FUN_004d5e24(void)

{
  long unaff_R12;
  
  *(undefined1 *)(unaff_R12 + 0x10) = 0;
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d5e40 name=FUN_004d5e40 size=24 ====

void FUN_004d5e40(void)

{
  QVariant *unaff_RBP;
  
  QVariant::~QVariant(unaff_RBP);
  qt_byte_array_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d5e58 name=FUN_004d5e58 size=16 ====

void FUN_004d5e58(void)

{
  qt_array_data_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d5e68 name=FUN_004d5e68 size=45 ====

void FUN_004d5e68(void)

{
  long unaff_RBX;
  QDateTime *unaff_RBP;
  
  qt_array_data_unref();
  QDateTime::~QDateTime(unaff_RBP);
  qt_array_data_unref(unaff_RBX + 0x58);
  qt_array_data_unref(unaff_RBX + 0x50);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d5e96 name=FUN_004d5e96 size=24 ====

void FUN_004d5e96(void)

{
  qt_array_data_unref();
  qt_array_data_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d5eae name=FUN_004d5eae size=16 ====

void FUN_004d5eae(void)

{
  qt_array_data_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d5ebe name=FUN_004d5ebe size=24 ====

void FUN_004d5ebe(void)

{
  qt_array_data_unref();
  qt_array_data_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d5ed6 name=FUN_004d5ed6 size=16 ====

void FUN_004d5ed6(void)

{
  qt_array_data_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d5ee6 name=FUN_004d5ee6 size=30 ====

void FUN_004d5ee6(void)

{
  long in_stack_00000008;
  
  stdstring_repRelease(in_stack_00000008 + -0x18);
  qt_array_data_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d5f04 name=FUN_004d5f04 size=16 ====

void FUN_004d5f04(void)

{
  qt_array_data_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d5f14 name=FUN_004d5f14 size=16 ====

void FUN_004d5f14(void)

{
  qt_array_data_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d5f24 name=FUN_004d5f24 size=30 ====

void FUN_004d5f24(void)

{
  long in_stack_00000008;
  
  stdstring_repRelease(in_stack_00000008 + -0x18);
  qt_array_data_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d5f42 name=FUN_004d5f42 size=21 ====

void FUN_004d5f42(void)

{
  void *unaff_R12;
  
  operator_delete(unaff_R12,0x20);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d5f58 name=FUN_004d5f58 size=24 ====

void FUN_004d5f58(void)

{
  QVariant *unaff_R12;
  
  QVariant::~QVariant(unaff_R12);
  qt_byte_array_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d5f70 name=FUN_004d5f70 size=24 ====

void FUN_004d5f70(void)

{
  QVariant *unaff_R12;
  
  QVariant::~QVariant(unaff_R12);
  qt_byte_array_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d5f88 name=FUN_004d5f88 size=24 ====

void FUN_004d5f88(void)

{
  QVariant *unaff_R12;
  
  QVariant::~QVariant(unaff_R12);
  qt_byte_array_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d5fa0 name=FUN_004d5fa0 size=58 ====

void FUN_004d5fa0(void)

{
  undefined8 unaff_retaddr;
  long in_stack_00000040;
  
  stdstring_repRelease(in_stack_00000040 + -0x18);
  qt_array_data_unref();
  qt_array_data_unref();
  qt_array_data_unref();
  qt_array_data_unref(unaff_retaddr);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d5fda name=FUN_004d5fda size=24 ====

void FUN_004d5fda(void)

{
  QVariant *unaff_R12;
  
  QVariant::~QVariant(unaff_R12);
  qt_byte_array_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d5ff2 name=FUN_004d5ff2 size=24 ====

void FUN_004d5ff2(void)

{
  QVariant *unaff_R12;
  
  QVariant::~QVariant(unaff_R12);
  qt_byte_array_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d600a name=FUN_004d600a size=35 ====

void FUN_004d600a(void)

{
  undefined8 unaff_retaddr;
  long in_stack_00000040;
  
  stdstring_repRelease(in_stack_00000040 + -0x18);
  qt_array_data_unref();
  qt_array_data_unref();
  qt_array_data_unref();
  qt_array_data_unref(unaff_retaddr);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d602d name=FUN_004d602d size=24 ====

void FUN_004d602d(void)

{
  QVariant *unaff_R12;
  
  QVariant::~QVariant(unaff_R12);
  qt_byte_array_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d6045 name=FUN_004d6045 size=38 ====

void FUN_004d6045(void)

{
  undefined8 unaff_retaddr;
  long in_stack_00000040;
  
  stdstring_repRelease(in_stack_00000040 + -0x18);
  qt_array_data_unref();
  qt_array_data_unref();
  qt_array_data_unref();
  qt_array_data_unref(unaff_retaddr);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d606b name=FUN_004d606b size=38 ====

void FUN_004d606b(void)

{
  undefined8 unaff_retaddr;
  long in_stack_00000040;
  
  stdstring_repRelease(in_stack_00000040 + -0x18);
  qt_array_data_unref();
  qt_array_data_unref();
  qt_array_data_unref();
  qt_array_data_unref(unaff_retaddr);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d6091 name=FUN_004d6091 size=38 ====

void FUN_004d6091(void)

{
  undefined8 unaff_retaddr;
  long in_stack_00000040;
  
  stdstring_repRelease(in_stack_00000040 + -0x18);
  qt_array_data_unref();
  qt_array_data_unref();
  qt_array_data_unref();
  qt_array_data_unref(unaff_retaddr);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d60b7 name=FUN_004d60b7 size=38 ====

void FUN_004d60b7(void)

{
  undefined8 unaff_retaddr;
  long in_stack_00000040;
  
  stdstring_repRelease(in_stack_00000040 + -0x18);
  qt_array_data_unref();
  qt_array_data_unref();
  qt_array_data_unref();
  qt_array_data_unref(unaff_retaddr);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d60dd name=FUN_004d60dd size=38 ====

void FUN_004d60dd(void)

{
  undefined8 unaff_retaddr;
  long in_stack_00000040;
  
  stdstring_repRelease(in_stack_00000040 + -0x18);
  qt_array_data_unref();
  qt_array_data_unref();
  qt_array_data_unref();
  qt_array_data_unref(unaff_retaddr);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d6104 name=FUN_004d6104 size=170 ====

void FUN_004d6104(void)

{
  void *pvVar1;
  QObject *unaff_RBX;
  
  FUN_00642420();
  FUN_00642420();
  FUN_006424c0(unaff_RBX + 0xf8);
  FUN_006424c0(unaff_RBX + 0xf0);
  pvVar1 = *(void **)(unaff_RBX + 0xb8);
  if (pvVar1 != (void *)0x0) {
    FUN_00a80de0(pvVar1);
    operator_delete(pvVar1,0x20);
  }
  qt_array_data_unref(unaff_RBX + 0xb0);
  qt_array_data_unref(unaff_RBX + 0xa8);
  qt_shared_data_unref(unaff_RBX + 0x48);
  qt_array_data_unref(unaff_RBX + 0x40);
  qt_array_data_unref(unaff_RBX + 0x38);
  qt_array_data_unref(unaff_RBX + 0x30);
  FUN_006424a0(unaff_RBX + 0x28);
  FUN_00642480(unaff_RBX + 0x20);
  QObject::~QObject(unaff_RBX);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d61ae name=FUN_004d61ae size=23 ====

void FUN_004d61ae(void)

{
  _Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *in_stack_00000008;
  
  if (in_stack_00000008 != (_Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *)0x0) {
    std::_Sp_counted_base<(__gnu_cxx::_Lock_policy)2>::_M_release(in_stack_00000008);
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d61c6 name=FUN_004d61c6 size=24 ====

void FUN_004d61c6(void)

{
  FUN_0064233a();
  FUN_0064233a();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d61de name=FUN_004d61de size=70 ====

void FUN_004d61de(void)

{
  long unaff_RBP;
  undefined8 in_stack_00000010;
  undefined8 in_stack_00000020;
  undefined8 in_stack_00000028;
  undefined8 in_stack_00000060;
  undefined8 in_stack_00000068;
  
  qt_array_data_unref(unaff_RBP + 0xc0);
  qt_array_data_unref(in_stack_00000028);
  qt_array_data_unref(in_stack_00000020);
  qt_array_data_unref(in_stack_00000068);
  qt_array_data_unref(in_stack_00000060);
  qt_array_data_unref(in_stack_00000010);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d6224 name=FUN_004d6224 size=24 ====

void FUN_004d6224(void)

{
  long unaff_RBP;
  undefined8 in_stack_00000010;
  undefined8 in_stack_00000020;
  undefined8 in_stack_00000028;
  undefined8 in_stack_00000030;
  undefined8 in_stack_00000060;
  undefined8 in_stack_00000068;
  
  qt_array_data_unref(unaff_RBP + 0xf0);
  qt_array_data_unref(in_stack_00000030);
  qt_array_data_unref(in_stack_00000028);
  qt_array_data_unref(in_stack_00000020);
  qt_array_data_unref(in_stack_00000068);
  qt_array_data_unref(in_stack_00000060);
  qt_array_data_unref(in_stack_00000010);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d623c name=FUN_004d623c size=14 ====

void FUN_004d623c(void)

{
  long unaff_RBP;
  undefined8 in_stack_00000010;
  undefined8 in_stack_00000020;
  undefined8 in_stack_00000028;
  undefined8 in_stack_00000030;
  undefined8 in_stack_00000060;
  undefined8 in_stack_00000068;
  
  qt_array_data_unref(unaff_RBP + 0xd8);
  qt_array_data_unref(in_stack_00000030);
  qt_array_data_unref(in_stack_00000028);
  qt_array_data_unref(in_stack_00000020);
  qt_array_data_unref(in_stack_00000068);
  qt_array_data_unref(in_stack_00000060);
  qt_array_data_unref(in_stack_00000010);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d624a name=FUN_004d624a size=24 ====

void FUN_004d624a(void)

{
  long unaff_RBP;
  undefined8 in_stack_00000010;
  undefined8 in_stack_00000020;
  undefined8 in_stack_00000028;
  undefined8 in_stack_00000030;
  undefined8 in_stack_00000038;
  undefined8 in_stack_00000060;
  undefined8 in_stack_00000068;
  
  qt_array_data_unref(unaff_RBP + 0x150);
  qt_array_data_unref(in_stack_00000038);
  qt_array_data_unref(in_stack_00000030);
  qt_array_data_unref(in_stack_00000028);
  qt_array_data_unref(in_stack_00000020);
  qt_array_data_unref(in_stack_00000068);
  qt_array_data_unref(in_stack_00000060);
  qt_array_data_unref(in_stack_00000010);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d6262 name=FUN_004d6262 size=14 ====

void FUN_004d6262(void)

{
  long unaff_RBP;
  undefined8 in_stack_00000010;
  undefined8 in_stack_00000020;
  undefined8 in_stack_00000028;
  undefined8 in_stack_00000030;
  undefined8 in_stack_00000038;
  undefined8 in_stack_00000060;
  undefined8 in_stack_00000068;
  
  qt_array_data_unref(unaff_RBP + 0x108);
  qt_array_data_unref(in_stack_00000038);
  qt_array_data_unref(in_stack_00000030);
  qt_array_data_unref(in_stack_00000028);
  qt_array_data_unref(in_stack_00000020);
  qt_array_data_unref(in_stack_00000068);
  qt_array_data_unref(in_stack_00000060);
  qt_array_data_unref(in_stack_00000010);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d6270 name=FUN_004d6270 size=14 ====

void FUN_004d6270(void)

{
  long unaff_RBP;
  undefined8 in_stack_00000010;
  undefined8 in_stack_00000020;
  undefined8 in_stack_00000028;
  undefined8 in_stack_00000030;
  undefined8 in_stack_00000038;
  undefined8 in_stack_00000060;
  undefined8 in_stack_00000068;
  
  qt_array_data_unref(unaff_RBP + 0x120);
  qt_array_data_unref(in_stack_00000038);
  qt_array_data_unref(in_stack_00000030);
  qt_array_data_unref(in_stack_00000028);
  qt_array_data_unref(in_stack_00000020);
  qt_array_data_unref(in_stack_00000068);
  qt_array_data_unref(in_stack_00000060);
  qt_array_data_unref(in_stack_00000010);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d627e name=FUN_004d627e size=14 ====

void FUN_004d627e(void)

{
  long unaff_RBP;
  undefined8 in_stack_00000010;
  undefined8 in_stack_00000020;
  undefined8 in_stack_00000028;
  undefined8 in_stack_00000030;
  undefined8 in_stack_00000038;
  undefined8 in_stack_00000060;
  undefined8 in_stack_00000068;
  
  qt_array_data_unref(unaff_RBP + 0x138);
  qt_array_data_unref(in_stack_00000038);
  qt_array_data_unref(in_stack_00000030);
  qt_array_data_unref(in_stack_00000028);
  qt_array_data_unref(in_stack_00000020);
  qt_array_data_unref(in_stack_00000068);
  qt_array_data_unref(in_stack_00000060);
  qt_array_data_unref(in_stack_00000010);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d628c name=FUN_004d628c size=24 ====

void FUN_004d628c(void)

{
  long unaff_RBP;
  undefined8 in_stack_00000010;
  undefined8 in_stack_00000020;
  undefined8 in_stack_00000028;
  undefined8 in_stack_00000030;
  undefined8 in_stack_00000038;
  undefined8 in_stack_00000040;
  undefined8 in_stack_00000060;
  undefined8 in_stack_00000068;
  
  qt_array_data_unref(unaff_RBP + 0x168);
  qt_array_data_unref(in_stack_00000040);
  qt_array_data_unref(in_stack_00000038);
  qt_array_data_unref(in_stack_00000030);
  qt_array_data_unref(in_stack_00000028);
  qt_array_data_unref(in_stack_00000020);
  qt_array_data_unref(in_stack_00000068);
  qt_array_data_unref(in_stack_00000060);
  qt_array_data_unref(in_stack_00000010);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d62a4 name=FUN_004d62a4 size=24 ====

void FUN_004d62a4(void)

{
  long unaff_RBP;
  undefined8 in_stack_00000010;
  undefined8 in_stack_00000020;
  undefined8 in_stack_00000028;
  undefined8 in_stack_00000030;
  undefined8 in_stack_00000038;
  undefined8 in_stack_00000040;
  undefined8 in_stack_00000048;
  undefined8 in_stack_00000060;
  undefined8 in_stack_00000068;
  
  qt_array_data_unref(unaff_RBP + 0x180);
  qt_array_data_unref(in_stack_00000048);
  qt_array_data_unref(in_stack_00000040);
  qt_array_data_unref(in_stack_00000038);
  qt_array_data_unref(in_stack_00000030);
  qt_array_data_unref(in_stack_00000028);
  qt_array_data_unref(in_stack_00000020);
  qt_array_data_unref(in_stack_00000068);
  qt_array_data_unref(in_stack_00000060);
  qt_array_data_unref(in_stack_00000010);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d62bc name=FUN_004d62bc size=24 ====

void FUN_004d62bc(void)

{
  long unaff_RBP;
  undefined8 in_stack_00000010;
  undefined8 in_stack_00000020;
  undefined8 in_stack_00000028;
  undefined8 in_stack_00000030;
  undefined8 in_stack_00000038;
  undefined8 in_stack_00000040;
  undefined8 in_stack_00000048;
  undefined8 in_stack_00000050;
  undefined8 in_stack_00000060;
  undefined8 in_stack_00000068;
  
  qt_array_data_unref(unaff_RBP + 0x198);
  qt_array_data_unref(in_stack_00000050);
  qt_array_data_unref(in_stack_00000048);
  qt_array_data_unref(in_stack_00000040);
  qt_array_data_unref(in_stack_00000038);
  qt_array_data_unref(in_stack_00000030);
  qt_array_data_unref(in_stack_00000028);
  qt_array_data_unref(in_stack_00000020);
  qt_array_data_unref(in_stack_00000068);
  qt_array_data_unref(in_stack_00000060);
  qt_array_data_unref(in_stack_00000010);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d62d4 name=FUN_004d62d4 size=24 ====

void FUN_004d62d4(void)

{
  long unaff_RBP;
  undefined8 in_stack_00000010;
  undefined8 in_stack_00000020;
  undefined8 in_stack_00000028;
  undefined8 in_stack_00000030;
  undefined8 in_stack_00000038;
  undefined8 in_stack_00000040;
  undefined8 in_stack_00000048;
  undefined8 in_stack_00000050;
  undefined8 in_stack_00000058;
  undefined8 in_stack_00000060;
  undefined8 in_stack_00000068;
  
  qt_array_data_unref(unaff_RBP + 0x228);
  qt_array_data_unref(in_stack_00000058);
  qt_array_data_unref(in_stack_00000050);
  qt_array_data_unref(in_stack_00000048);
  qt_array_data_unref(in_stack_00000040);
  qt_array_data_unref(in_stack_00000038);
  qt_array_data_unref(in_stack_00000030);
  qt_array_data_unref(in_stack_00000028);
  qt_array_data_unref(in_stack_00000020);
  qt_array_data_unref(in_stack_00000068);
  qt_array_data_unref(in_stack_00000060);
  qt_array_data_unref(in_stack_00000010);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d62ec name=FUN_004d62ec size=27 ====

void FUN_004d62ec(void)

{
  long unaff_RBP;
  undefined8 in_stack_00000020;
  undefined8 in_stack_00000060;
  undefined8 in_stack_00000068;
  
  qt_array_data_unref(unaff_RBP + 0x18);
  qt_array_data_unref(in_stack_00000020);
  qt_array_data_unref(in_stack_00000068);
  qt_array_data_unref(in_stack_00000060);
  qt_array_data_unref(&stack0x00000080);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d6307 name=FUN_004d6307 size=27 ====

void FUN_004d6307(void)

{
  long unaff_RBP;
  undefined8 in_stack_00000020;
  undefined8 in_stack_00000060;
  undefined8 in_stack_00000068;
  
  qt_array_data_unref(unaff_RBP + 0x30);
  qt_array_data_unref(in_stack_00000020);
  qt_array_data_unref(in_stack_00000068);
  qt_array_data_unref(in_stack_00000060);
  qt_array_data_unref(&stack0x00000080);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d6322 name=FUN_004d6322 size=27 ====

void FUN_004d6322(void)

{
  long unaff_RBP;
  undefined8 in_stack_00000020;
  undefined8 in_stack_00000060;
  undefined8 in_stack_00000068;
  
  qt_array_data_unref(unaff_RBP + 0x48);
  qt_array_data_unref(in_stack_00000020);
  qt_array_data_unref(in_stack_00000068);
  qt_array_data_unref(in_stack_00000060);
  qt_array_data_unref(&stack0x00000080);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d633d name=FUN_004d633d size=27 ====

void FUN_004d633d(void)

{
  long unaff_RBP;
  undefined8 in_stack_00000020;
  undefined8 in_stack_00000028;
  undefined8 in_stack_00000060;
  undefined8 in_stack_00000068;
  
  qt_array_data_unref(unaff_RBP + 0x60);
  qt_array_data_unref(in_stack_00000028);
  qt_array_data_unref(in_stack_00000020);
  qt_array_data_unref(in_stack_00000068);
  qt_array_data_unref(in_stack_00000060);
  qt_array_data_unref(&stack0x00000080);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d6358 name=FUN_004d6358 size=27 ====

void FUN_004d6358(void)

{
  long unaff_RBP;
  undefined8 in_stack_00000020;
  undefined8 in_stack_00000028;
  undefined8 in_stack_00000060;
  undefined8 in_stack_00000068;
  
  qt_array_data_unref(unaff_RBP + 0x78);
  qt_array_data_unref(in_stack_00000028);
  qt_array_data_unref(in_stack_00000020);
  qt_array_data_unref(in_stack_00000068);
  qt_array_data_unref(in_stack_00000060);
  qt_array_data_unref(&stack0x00000080);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d6373 name=FUN_004d6373 size=17 ====

void FUN_004d6373(void)

{
  long unaff_RBP;
  undefined8 in_stack_00000010;
  undefined8 in_stack_00000020;
  undefined8 in_stack_00000028;
  undefined8 in_stack_00000060;
  undefined8 in_stack_00000068;
  
  qt_array_data_unref(unaff_RBP + 0x90);
  qt_array_data_unref(in_stack_00000028);
  qt_array_data_unref(in_stack_00000020);
  qt_array_data_unref(in_stack_00000068);
  qt_array_data_unref(in_stack_00000060);
  qt_array_data_unref(in_stack_00000010);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d6384 name=FUN_004d6384 size=17 ====

void FUN_004d6384(void)

{
  long unaff_RBP;
  undefined8 in_stack_00000010;
  undefined8 in_stack_00000020;
  undefined8 in_stack_00000028;
  undefined8 in_stack_00000060;
  undefined8 in_stack_00000068;
  
  qt_array_data_unref(unaff_RBP + 0xa8);
  qt_array_data_unref(in_stack_00000028);
  qt_array_data_unref(in_stack_00000020);
  qt_array_data_unref(in_stack_00000068);
  qt_array_data_unref(in_stack_00000060);
  qt_array_data_unref(in_stack_00000010);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d6395 name=FUN_004d6395 size=45 ====

void FUN_004d6395(void)

{
  undefined1 *puVar1;
  undefined1 *unaff_RBP;
  undefined8 in_stack_00000010;
  undefined8 in_stack_00000020;
  undefined8 in_stack_00000028;
  undefined8 in_stack_00000030;
  undefined8 in_stack_00000038;
  undefined8 in_stack_00000040;
  undefined8 in_stack_00000048;
  undefined8 in_stack_00000050;
  undefined8 in_stack_00000058;
  undefined8 in_stack_00000060;
  undefined8 in_stack_00000068;
  undefined1 *puVar2;
  
  puVar2 = &stack0x00000320;
  do {
    puVar1 = puVar2 + -0x18;
    QVariant::~QVariant((QVariant *)(puVar2 + -0x10));
    qt_array_data_unref(puVar1);
    puVar2 = puVar1;
  } while (puVar1 != unaff_RBP);
  qt_array_data_unref(in_stack_00000058);
  qt_array_data_unref(in_stack_00000050);
  qt_array_data_unref(in_stack_00000048);
  qt_array_data_unref(in_stack_00000040);
  qt_array_data_unref(in_stack_00000038);
  qt_array_data_unref(in_stack_00000030);
  qt_array_data_unref(in_stack_00000028);
  qt_array_data_unref(in_stack_00000020);
  qt_array_data_unref(in_stack_00000068);
  qt_array_data_unref(in_stack_00000060);
  qt_array_data_unref(in_stack_00000010);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d63c2 name=FUN_004d63c2 size=13 ====

void FUN_004d63c2(void)

{
  undefined8 in_stack_00000010;
  undefined8 in_stack_00000060;
  undefined8 in_stack_00000068;
  
  qmap_freetree_variant_nodes();
  qt_array_data_unref(in_stack_00000068);
  qt_array_data_unref(in_stack_00000060);
  qt_array_data_unref(in_stack_00000010);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d63cf name=FUN_004d63cf size=26 ====

void FUN_004d63cf(void)

{
  qt_array_data_unref();
  qt_array_data_unref(&stack0x00000080);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d63e9 name=FUN_004d63e9 size=26 ====

void FUN_004d63e9(void)

{
  undefined8 in_stack_00000060;
  undefined8 in_stack_00000068;
  
  qt_array_data_unref();
  qt_array_data_unref(in_stack_00000068);
  qt_array_data_unref(in_stack_00000060);
  qt_array_data_unref(&stack0x00000080);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d6403 name=FUN_004d6403 size=17 ====

void FUN_004d6403(void)

{
  long unaff_RBP;
  undefined8 in_stack_00000010;
  undefined8 in_stack_00000020;
  undefined8 in_stack_00000028;
  undefined8 in_stack_00000030;
  undefined8 in_stack_00000038;
  undefined8 in_stack_00000040;
  undefined8 in_stack_00000048;
  undefined8 in_stack_00000050;
  undefined8 in_stack_00000058;
  undefined8 in_stack_00000060;
  undefined8 in_stack_00000068;
  
  qt_array_data_unref(unaff_RBP + 0x1b0);
  qt_array_data_unref(in_stack_00000058);
  qt_array_data_unref(in_stack_00000050);
  qt_array_data_unref(in_stack_00000048);
  qt_array_data_unref(in_stack_00000040);
  qt_array_data_unref(in_stack_00000038);
  qt_array_data_unref(in_stack_00000030);
  qt_array_data_unref(in_stack_00000028);
  qt_array_data_unref(in_stack_00000020);
  qt_array_data_unref(in_stack_00000068);
  qt_array_data_unref(in_stack_00000060);
  qt_array_data_unref(in_stack_00000010);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d6414 name=FUN_004d6414 size=17 ====

void FUN_004d6414(void)

{
  long unaff_RBP;
  undefined8 in_stack_00000010;
  undefined8 in_stack_00000020;
  undefined8 in_stack_00000028;
  undefined8 in_stack_00000030;
  undefined8 in_stack_00000038;
  undefined8 in_stack_00000040;
  undefined8 in_stack_00000048;
  undefined8 in_stack_00000050;
  undefined8 in_stack_00000058;
  undefined8 in_stack_00000060;
  undefined8 in_stack_00000068;
  
  qt_array_data_unref(unaff_RBP + 0x1c8);
  qt_array_data_unref(in_stack_00000058);
  qt_array_data_unref(in_stack_00000050);
  qt_array_data_unref(in_stack_00000048);
  qt_array_data_unref(in_stack_00000040);
  qt_array_data_unref(in_stack_00000038);
  qt_array_data_unref(in_stack_00000030);
  qt_array_data_unref(in_stack_00000028);
  qt_array_data_unref(in_stack_00000020);
  qt_array_data_unref(in_stack_00000068);
  qt_array_data_unref(in_stack_00000060);
  qt_array_data_unref(in_stack_00000010);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d6425 name=FUN_004d6425 size=17 ====

void FUN_004d6425(void)

{
  long unaff_RBP;
  undefined8 in_stack_00000010;
  undefined8 in_stack_00000020;
  undefined8 in_stack_00000028;
  undefined8 in_stack_00000030;
  undefined8 in_stack_00000038;
  undefined8 in_stack_00000040;
  undefined8 in_stack_00000048;
  undefined8 in_stack_00000050;
  undefined8 in_stack_00000058;
  undefined8 in_stack_00000060;
  undefined8 in_stack_00000068;
  
  qt_array_data_unref(unaff_RBP + 0x1e0);
  qt_array_data_unref(in_stack_00000058);
  qt_array_data_unref(in_stack_00000050);
  qt_array_data_unref(in_stack_00000048);
  qt_array_data_unref(in_stack_00000040);
  qt_array_data_unref(in_stack_00000038);
  qt_array_data_unref(in_stack_00000030);
  qt_array_data_unref(in_stack_00000028);
  qt_array_data_unref(in_stack_00000020);
  qt_array_data_unref(in_stack_00000068);
  qt_array_data_unref(in_stack_00000060);
  qt_array_data_unref(in_stack_00000010);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d6436 name=FUN_004d6436 size=17 ====

void FUN_004d6436(void)

{
  long unaff_RBP;
  undefined8 in_stack_00000010;
  undefined8 in_stack_00000020;
  undefined8 in_stack_00000028;
  undefined8 in_stack_00000030;
  undefined8 in_stack_00000038;
  undefined8 in_stack_00000040;
  undefined8 in_stack_00000048;
  undefined8 in_stack_00000050;
  undefined8 in_stack_00000058;
  undefined8 in_stack_00000060;
  undefined8 in_stack_00000068;
  
  qt_array_data_unref(unaff_RBP + 0x1f8);
  qt_array_data_unref(in_stack_00000058);
  qt_array_data_unref(in_stack_00000050);
  qt_array_data_unref(in_stack_00000048);
  qt_array_data_unref(in_stack_00000040);
  qt_array_data_unref(in_stack_00000038);
  qt_array_data_unref(in_stack_00000030);
  qt_array_data_unref(in_stack_00000028);
  qt_array_data_unref(in_stack_00000020);
  qt_array_data_unref(in_stack_00000068);
  qt_array_data_unref(in_stack_00000060);
  qt_array_data_unref(in_stack_00000010);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d6447 name=FUN_004d6447 size=17 ====

void FUN_004d6447(void)

{
  long unaff_RBP;
  undefined8 in_stack_00000010;
  undefined8 in_stack_00000020;
  undefined8 in_stack_00000028;
  undefined8 in_stack_00000030;
  undefined8 in_stack_00000038;
  undefined8 in_stack_00000040;
  undefined8 in_stack_00000048;
  undefined8 in_stack_00000050;
  undefined8 in_stack_00000058;
  undefined8 in_stack_00000060;
  undefined8 in_stack_00000068;
  
  qt_array_data_unref(unaff_RBP + 0x210);
  qt_array_data_unref(in_stack_00000058);
  qt_array_data_unref(in_stack_00000050);
  qt_array_data_unref(in_stack_00000048);
  qt_array_data_unref(in_stack_00000040);
  qt_array_data_unref(in_stack_00000038);
  qt_array_data_unref(in_stack_00000030);
  qt_array_data_unref(in_stack_00000028);
  qt_array_data_unref(in_stack_00000020);
  qt_array_data_unref(in_stack_00000068);
  qt_array_data_unref(in_stack_00000060);
  qt_array_data_unref(in_stack_00000010);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d6458 name=FUN_004d6458 size=22 ====

void FUN_004d6458(void)

{
  long unaff_R14;
  
  __cxa_begin_catch();
  qt_array_data_unref(unaff_R14 + 0x18);
                    /* WARNING: Subroutine does not return */
                    /* try { // try from 004d6469 to 004d646d has its CatchHandler @ 004d646e */
  __cxa_rethrow();
}


// ==== entry=004d64aa name=FUN_004d64aa size=22 ====

void FUN_004d64aa(void)

{
  long unaff_RBP;
  
  if (*(_Sp_counted_base<(__gnu_cxx::_Lock_policy)2> **)(unaff_RBP + 8) !=
      (_Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *)0x0) {
    std::_Sp_counted_base<(__gnu_cxx::_Lock_policy)2>::_M_release
              (*(_Sp_counted_base<(__gnu_cxx::_Lock_policy)2> **)(unaff_RBP + 8));
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d64c0 name=FUN_004d64c0 size=16 ====

void FUN_004d64c0(void)

{
  void *unaff_R12;
  
  operator_delete(unaff_R12);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d64d0 name=FUN_004d64d0 size=44 ====

void FUN_004d64d0(void)

{
  undefined8 in_stack_00000018;
  undefined8 in_stack_00000028;
  
  qt_array_data_unref(in_stack_00000018);
  qt_array_data_unref(in_stack_00000028);
  qt_array_data_unref();
  qt_array_data_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d64fc name=FUN_004d64fc size=45 ====

void FUN_004d64fc(void)

{
  void *unaff_R12;
  undefined8 in_stack_00000020;
  undefined8 in_stack_00000028;
  undefined8 in_stack_00000030;
  _Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *in_stack_00000078;
  
  operator_delete(unaff_R12);
  qt_array_data_unref(in_stack_00000020);
  qt_array_data_unref(in_stack_00000030);
  if (in_stack_00000078 != (_Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *)0x0) {
    std::_Sp_counted_base<(__gnu_cxx::_Lock_policy)2>::_M_release(in_stack_00000078);
  }
  qt_array_data_unref(in_stack_00000028);
  qt_array_data_unref();
  qt_array_data_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d6529 name=FUN_004d6529 size=20 ====

void FUN_004d6529(void)

{
  undefined8 in_stack_00000018;
  undefined8 in_stack_00000028;
  
  qt_array_data_unref(in_stack_00000018);
  qt_array_data_unref();
  qt_array_data_unref(in_stack_00000028);
  qt_array_data_unref();
  qt_array_data_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d653d name=FUN_004d653d size=20 ====

void FUN_004d653d(void)

{
  undefined8 in_stack_00000028;
  _Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *in_stack_00000078;
  _Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *in_stack_00000088;
  
  if (in_stack_00000088 != (_Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *)0x0) {
    std::_Sp_counted_base<(__gnu_cxx::_Lock_policy)2>::_M_release(in_stack_00000088);
  }
  if (in_stack_00000078 != (_Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *)0x0) {
    std::_Sp_counted_base<(__gnu_cxx::_Lock_policy)2>::_M_release(in_stack_00000078);
  }
  qt_array_data_unref(in_stack_00000028);
  qt_array_data_unref();
  qt_array_data_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d6551 name=FUN_004d6551 size=30 ====

void FUN_004d6551(void)

{
  undefined8 in_stack_00000018;
  
  qt_array_data_unref(in_stack_00000018);
  qt_array_data_unref(&stack0x00000058);
  qt_array_data_unref();
  qt_array_data_unref(&stack0x00000048);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d656f name=FUN_004d656f size=18 ====

void FUN_004d656f(void)

{
  qt_array_data_unref();
  qt_array_data_unref(&stack0x00000048);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d6581 name=FUN_004d6581 size=20 ====

void FUN_004d6581(void)

{
  _Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *in_stack_00000078;
  _Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *in_stack_00000088;
  
  if (in_stack_00000088 != (_Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *)0x0) {
    std::_Sp_counted_base<(__gnu_cxx::_Lock_policy)2>::_M_release(in_stack_00000088);
  }
  if (in_stack_00000078 != (_Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *)0x0) {
    std::_Sp_counted_base<(__gnu_cxx::_Lock_policy)2>::_M_release(in_stack_00000078);
  }
  qt_array_data_unref();
  qt_array_data_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d6595 name=FUN_004d6595 size=32 ====

void FUN_004d6595(void)

{
  void *unaff_R12;
  _Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *in_stack_00000078;
  
  operator_delete(unaff_R12);
  if (in_stack_00000078 != (_Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *)0x0) {
    std::_Sp_counted_base<(__gnu_cxx::_Lock_policy)2>::_M_release(in_stack_00000078);
  }
  qt_array_data_unref();
  qt_array_data_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d65b6 name=FUN_004d65b6 size=26 ====

void FUN_004d65b6(void)

{
  undefined8 in_stack_00000008;
  
  qt_array_data_unref();
  qt_array_data_unref(in_stack_00000008);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d65d0 name=FUN_004d65d0 size=10 ====

void FUN_004d65d0(void)

{
  undefined8 in_stack_00000008;
  
  qt_array_data_unref();
  qt_array_data_unref(in_stack_00000008);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d65da name=FUN_004d65da size=31 ====

void FUN_004d65da(void)

{
  _Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *in_stack_00000008;
  
  FUN_0064233a();
  if (in_stack_00000008 != (_Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *)0x0) {
    std::_Sp_counted_base<(__gnu_cxx::_Lock_policy)2>::_M_release(in_stack_00000008);
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d65fa name=FUN_004d65fa size=31 ====

void FUN_004d65fa(void)

{
  _Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *in_stack_00000008;
  
  qt_array_data_unref();
  if (in_stack_00000008 != (_Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *)0x0) {
    std::_Sp_counted_base<(__gnu_cxx::_Lock_policy)2>::_M_release(in_stack_00000008);
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d6619 name=FUN_004d6619 size=10 ====

void FUN_004d6619(void)

{
  _Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *in_stack_00000008;
  
  FUN_0064233a();
  if (in_stack_00000008 != (_Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *)0x0) {
    std::_Sp_counted_base<(__gnu_cxx::_Lock_policy)2>::_M_release(in_stack_00000008);
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d6623 name=FUN_004d6623 size=23 ====

void FUN_004d6623(void)

{
  _Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *in_stack_00000008;
  
  if (in_stack_00000008 != (_Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *)0x0) {
    std::_Sp_counted_base<(__gnu_cxx::_Lock_policy)2>::_M_release(in_stack_00000008);
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d663a name=FUN_004d663a size=16 ====

void FUN_004d663a(void)

{
  FUN_0064233a();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d664a name=FUN_004d664a size=16 ====

void FUN_004d664a(void)

{
  FUN_0064233a();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d665a name=FUN_004d665a size=24 ====

void FUN_004d665a(void)

{
  qt_array_data_unref();
  qt_array_data_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d6672 name=FUN_004d6672 size=10 ====

void FUN_004d6672(void)

{
  qt_array_data_unref();
  qt_array_data_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d667c name=FUN_004d667c size=16 ====

void FUN_004d667c(void)

{
  FUN_0064233a();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d668c name=FUN_004d668c size=21 ====

void FUN_004d668c(void)

{
  void *unaff_R12;
  
  operator_delete(unaff_R12,0x20);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d66a1 name=FUN_004d66a1 size=18 ====

void FUN_004d66a1(void)

{
  undefined8 in_stack_00000010;
  
  qt_array_data_unref(in_stack_00000010);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d66b3 name=FUN_004d66b3 size=18 ====

void FUN_004d66b3(void)

{
  undefined8 in_stack_00000010;
  
  qt_array_data_unref(in_stack_00000010);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d66c5 name=FUN_004d66c5 size=16 ====

void FUN_004d66c5(void)

{
  FUN_0064233a();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d66d5 name=FUN_004d66d5 size=16 ====

void FUN_004d66d5(void)

{
  FUN_0064233a();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d66e6 name=FUN_004d66e6 size=18 ====

void FUN_004d66e6(void)

{
  undefined8 in_stack_00000020;
  
  FUN_0064233a(in_stack_00000020);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d66f8 name=FUN_004d66f8 size=42 ====

void FUN_004d66f8(void)

{
  undefined8 in_stack_00000018;
  undefined8 in_stack_00000020;
  long in_stack_00000060;
  
  stdstring_repRelease(in_stack_00000060 + -0x18);
  qt_array_data_unref(in_stack_00000020);
  qt_array_data_unref(in_stack_00000018);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d6722 name=FUN_004d6722 size=36 ====

void FUN_004d6722(void)

{
  undefined8 in_stack_00000018;
  undefined8 in_stack_00000028;
  
  qt_array_data_unref();
  qt_array_data_unref();
  qt_array_data_unref();
  qt_array_data_unref(in_stack_00000028);
  qt_array_data_unref(in_stack_00000018);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d6746 name=FUN_004d6746 size=16 ====

void FUN_004d6746(void)

{
  qt_array_data_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d6756 name=FUN_004d6756 size=18 ====

void FUN_004d6756(void)

{
  undefined8 in_stack_00000008;
  
  FUN_0064233a(in_stack_00000008);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d6768 name=FUN_004d6768 size=16 ====

void FUN_004d6768(void)

{
  FUN_0064233a();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d6778 name=FUN_004d6778 size=26 ====

void FUN_004d6778(void)

{
  undefined8 in_stack_00000038;
  
  qt_array_data_unref(in_stack_00000038);
  qt_array_data_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d6792 name=FUN_004d6792 size=16 ====

void FUN_004d6792(void)

{
  qt_array_data_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d67a2 name=FUN_004d67a2 size=18 ====

void FUN_004d67a2(void)

{
  undefined8 in_stack_00000008;
  
  qt_array_data_unref(in_stack_00000008);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d67b4 name=FUN_004d67b4 size=18 ====

void FUN_004d67b4(void)

{
  undefined8 in_stack_00000008;
  
  qt_array_data_unref(in_stack_00000008);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d67c6 name=FUN_004d67c6 size=18 ====

void FUN_004d67c6(void)

{
  undefined8 in_stack_00000008;
  
  qt_array_data_unref(in_stack_00000008);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d67d8 name=FUN_004d67d8 size=18 ====

void FUN_004d67d8(void)

{
  undefined8 in_stack_00000008;
  
  qt_array_data_unref(in_stack_00000008);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d67ea name=FUN_004d67ea size=40 ====

void FUN_004d67ea(void)

{
  _Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *unaff_R12;
  undefined8 in_stack_00000008;
  
                    /* catch() { ... } // from try @ 004d6845 with catch @ 004d67eb */
  __cxa_end_catch();
  FUN_0064233a(in_stack_00000008);
  if (unaff_R12 != (_Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *)0x0) {
    std::_Sp_counted_base<(__gnu_cxx::_Lock_policy)2>::_M_release(unaff_R12);
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d6812 name=FUN_004d6812 size=12 ====

void FUN_004d6812(void)

{
  _Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *unaff_R12;
  undefined8 in_stack_00000008;
  
  qt_array_data_unref(in_stack_00000008);
  if (unaff_R12 != (_Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *)0x0) {
    std::_Sp_counted_base<(__gnu_cxx::_Lock_policy)2>::_M_release(unaff_R12);
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d681e name=FUN_004d681e size=22 ====

void FUN_004d681e(void)

{
  _Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *unaff_R12;
  undefined8 in_stack_00000008;
  undefined8 in_stack_00000018;
  
  qt_array_data_unref(in_stack_00000008);
  qt_array_data_unref(in_stack_00000018);
  if (unaff_R12 != (_Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *)0x0) {
    std::_Sp_counted_base<(__gnu_cxx::_Lock_policy)2>::_M_release(unaff_R12);
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d6834 name=FUN_004d6834 size=22 ====

void FUN_004d6834(void)

{
  long *unaff_R15;
  
  __cxa_begin_catch();
  (**(code **)(*unaff_R15 + 0x20))();
                    /* WARNING: Subroutine does not return */
                    /* try { // try from 004d6845 to 004d6849 has its CatchHandler @ 004d67eb */
  __cxa_rethrow();
}


// ==== entry=004d684a name=FUN_004d684a size=21 ====

void FUN_004d684a(void)

{
  _Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *unaff_R12;
  
  if (unaff_R12 != (_Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *)0x0) {
    std::_Sp_counted_base<(__gnu_cxx::_Lock_policy)2>::_M_release(unaff_R12);
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d6860 name=FUN_004d6860 size=16 ====

void FUN_004d6860(void)

{
  qlist_release_custom();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d6870 name=FUN_004d6870 size=24 ====

void FUN_004d6870(void)

{
  qt_array_data_unref();
  qt_array_data_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d6888 name=FUN_004d6888 size=16 ====

void FUN_004d6888(void)

{
  FUN_0064233a();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d6898 name=FUN_004d6898 size=16 ====

void FUN_004d6898(void)

{
  FUN_0064233a();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d68a8 name=FUN_004d68a8 size=24 ====

void FUN_004d68a8(void)

{
  qt_array_data_unref();
  qt_array_data_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d68c0 name=FUN_004d68c0 size=18 ====

void FUN_004d68c0(void)

{
  qt_array_data_unref(&stack0x00000008);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d68d2 name=FUN_004d68d2 size=31 ====

void FUN_004d68d2(void)

{
  _Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *in_stack_00000018;
  
  if (in_stack_00000018 != (_Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *)0x0) {
    std::_Sp_counted_base<(__gnu_cxx::_Lock_policy)2>::_M_release(in_stack_00000018);
  }
  qt_array_data_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d68f2 name=FUN_004d68f2 size=81 ====

void FUN_004d68f2(void)

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


// ==== entry=004d6943 name=FUN_004d6943 size=62 ====

void FUN_004d6943(void)

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


// ==== entry=004d6957 name=FUN_004d6957 size=27 ====

void FUN_004d6957(void)

{
  code *in_stack_00000020;
  code *in_stack_00000040;
  
  if (in_stack_00000020 != (code *)0x0) {
    (*in_stack_00000020)(&stack0x00000010,&stack0x00000010,3);
  }
  if (in_stack_00000040 != (code *)0x0) {
    (*in_stack_00000040)(&stack0x00000030,&stack0x00000030,3);
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d6972 name=FUN_004d6972 size=33 ====

void FUN_004d6972(void)

{
  code *in_stack_00000040;
  
  if (in_stack_00000040 != (code *)0x0) {
    (*in_stack_00000040)(&stack0x00000030,&stack0x00000030,3);
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d69c0 name=FUN_004d69c0 size=77 ====

void FUN_004d69c0(void)

{
  long unaff_RBX;
  char unaff_R12B;
  QVariant *unaff_R13;
  QArrayData *in_stack_00000008;
  
  QVariant::~QVariant((QVariant *)(unaff_RBX + 8));
  QVariant::~QVariant(unaff_R13);
  if (unaff_R12B == '\0') goto LAB_004d69f3;
  if (*(int *)in_stack_00000008 != 0) {
    if (*(int *)in_stack_00000008 == -1) goto LAB_004d69f3;
    LOCK();
    *(int *)in_stack_00000008 = *(int *)in_stack_00000008 + -1;
    UNLOCK();
    if (*(int *)in_stack_00000008 != 0) goto LAB_004d69f3;
  }
  QArrayData::deallocate(in_stack_00000008,1,8);
LAB_004d69f3:
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d6a0e name=FUN_004d6a0e size=52 ====

void FUN_004d6a0e(void)

{
  long unaff_RBX;
  QVariant *unaff_RBP;
  int *piVar1;
  
  QVariant::~QVariant(unaff_RBP);
  piVar1 = *(int **)(unaff_RBX + 0x10);
  if (*piVar1 != 0) {
    if (*piVar1 == -1) goto LAB_004d6a28;
    LOCK();
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if (*piVar1 != 0) goto LAB_004d6a28;
    piVar1 = *(int **)(unaff_RBX + 0x10);
  }
  FUN_00643be0(piVar1);
LAB_004d6a28:
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d6a42 name=FUN_004d6a42 size=40 ====

void FUN_004d6a42(void)

{
  QAbstractItemModel *unaff_RBX;
  void *unaff_RBP;
  
  operator_delete(unaff_RBP,0x18);
  qt_array_data_unref();
  QAbstractItemModel::~QAbstractItemModel(unaff_RBX);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d6a6a name=FUN_004d6a6a size=29 ====

void FUN_004d6a6a(void)

{
  void *unaff_RBX;
  
  operator_delete(unaff_RBX,0x18);
  qt_array_data_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d6a90 name=FUN_004d6a90 size=16 ====

void FUN_004d6a90(void)

{
  qt_byte_array_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d6aa0 name=FUN_004d6aa0 size=16 ====

void FUN_004d6aa0(void)

{
  QVariant *unaff_R12;
  
  QVariant::~QVariant(unaff_R12);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d6ab0 name=FUN_004d6ab0 size=21 ====

void FUN_004d6ab0(void)

{
  void *unaff_R12;
  
  operator_delete(unaff_R12,8);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d6ac5 name=FUN_004d6ac5 size=21 ====

void FUN_004d6ac5(void)

{
  void *unaff_R12;
  
  operator_delete(unaff_R12,0x10);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d6ada name=FUN_004d6ada size=18 ====

void FUN_004d6ada(void)

{
  undefined8 in_stack_00000010;
  
  qatomic_unref_call_deleter2(in_stack_00000010);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d6aec name=FUN_004d6aec size=39 ====

void FUN_004d6aec(void)

{
  undefined8 in_stack_00000120;
  byte in_stack_000001a0;
  
  qt_byte_array_unref(in_stack_00000120);
  if ((in_stack_000001a0 & 0x80) != 0) {
    QMetaType::dtor();
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d6b13 name=FUN_004d6b13 size=26 ====

void FUN_004d6b13(void)

{
  byte in_stack_000001a0;
  
  if ((in_stack_000001a0 & 0x80) != 0) {
    QMetaType::dtor();
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d6b2e name=FUN_004d6b2e size=16 ====

void FUN_004d6b2e(void)

{
  QVariant *unaff_RBX;
  
  QVariant::~QVariant(unaff_RBX);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d6b3e name=FUN_004d6b3e size=47 ====

void FUN_004d6b3e(void)

{
  int *piVar1;
  int iVar2;
  long *unaff_RBX;
  undefined8 in_stack_00000020;
  
  qt_byte_array_unref(in_stack_00000020);
  piVar1 = (int *)(*unaff_RBX + 0x10);
  iVar2 = *(int *)(*unaff_RBX + 0x10);
  if (iVar2 != 0) {
    if (iVar2 == -1) goto LAB_004d6b65;
    LOCK();
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if (*piVar1 != 0) goto LAB_004d6b65;
  }
  QHashData::free_helper((_func_void_Node_ptr *)*unaff_RBX);
LAB_004d6b65:
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d6b6d name=FUN_004d6b6d size=62 ====

void FUN_004d6b6d(void)

{
  int *piVar1;
  int iVar2;
  long *unaff_RBX;
  undefined8 unaff_retaddr;
  long in_stack_00000018;
  long in_stack_00000020;
  undefined8 in_stack_00000028;
  
  qt_byte_array_unref(in_stack_00000020 + 0x10);
  qatomic_unref_call_deleter2(in_stack_00000028);
  qt_byte_array_unref(unaff_retaddr);
  FUN_00647000(in_stack_00000018 + 0x18);
  piVar1 = (int *)(*unaff_RBX + 0x10);
  iVar2 = *(int *)(*unaff_RBX + 0x10);
  if (iVar2 != 0) {
    if (iVar2 == -1) goto LAB_004d6b65;
    LOCK();
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if (*piVar1 != 0) goto LAB_004d6b65;
  }
  QHashData::free_helper((_func_void_Node_ptr *)*unaff_RBX);
LAB_004d6b65:
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d6bb0 name=FUN_004d6bb0 size=52 ====

void FUN_004d6bb0(void)

{
  QThread *unaff_RBX;
  QVariant *unaff_RBP;
  QVariant *unaff_R12;
  
  QVariant::~QVariant(unaff_R12);
  qt_byte_array_unref();
  QVariant::~QVariant(unaff_RBP);
  qt_array_data_unref(unaff_RBX + 0x20);
  QThread::~QThread(unaff_RBX);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d6be4 name=FUN_004d6be4 size=16 ====

void FUN_004d6be4(void)

{
  qt_byte_array_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d6bf4 name=FUN_004d6bf4 size=56 ====

void FUN_004d6bf4(void)

{
  undefined8 in_stack_00000010;
  undefined8 in_stack_00000018;
  undefined8 in_stack_00000048;
  undefined8 in_stack_00000058;
  
  FUN_0064a780(in_stack_00000018);
  qt_byte_array_unref(in_stack_00000058);
  FUN_00a8dc88(in_stack_00000048);
  FUN_0064a780();
  FUN_0064a780(in_stack_00000010);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d6c2c name=FUN_004d6c2c size=26 ====

void FUN_004d6c2c(void)

{
  QRegExp *unaff_RBP;
  undefined8 in_stack_00000020;
  
  QRegExp::~QRegExp(unaff_RBP);
  qt_shared_data_unref(in_stack_00000020);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d6c46 name=FUN_004d6c46 size=16 ====

void FUN_004d6c46(void)

{
  qt_array_data_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d6c56 name=FUN_004d6c56 size=10 ====

void FUN_004d6c56(void)

{
  undefined8 in_stack_00000020;
  
  qt_array_data_unref();
  qt_shared_data_unref(in_stack_00000020);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d6c60 name=FUN_004d6c60 size=25 ====

void FUN_004d6c60(void)

{
  undefined8 in_stack_00000018;
  
  qt_byte_array_unref(in_stack_00000018);
  qt_byte_array_unref();
  qt_array_data_unref();
  qt_array_data_unref(&stack0x00000020);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d6c79 name=FUN_004d6c79 size=50 ====

void FUN_004d6c79(void)

{
  QRegularExpressionMatch *unaff_R15;
  undefined8 in_stack_00000018;
  
  qt_array_data_unref(in_stack_00000018);
  qt_array_data_unref();
  QRegularExpressionMatch::~QRegularExpressionMatch(unaff_R15);
  qt_array_data_unref();
  qt_array_data_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d6cab name=FUN_004d6cab size=13 ====

void FUN_004d6cab(void)

{
  QRegularExpressionMatch *unaff_R15;
  
  qt_byte_array_unref();
  QRegularExpressionMatch::~QRegularExpressionMatch(unaff_R15);
  qt_array_data_unref();
  qt_array_data_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d6cb8 name=FUN_004d6cb8 size=28 ====

void FUN_004d6cb8(void)

{
  undefined8 in_stack_00000018;
  
  qt_byte_array_unref(in_stack_00000018);
  qt_byte_array_unref();
  qt_array_data_unref();
  qt_array_data_unref(&stack0x00000020);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d6cd4 name=FUN_004d6cd4 size=146 ====

void FUN_004d6cd4(void)

{
  QTextDecoder *pQVar1;
  undefined8 unaff_RBX;
  QFile *in_stack_00000018;
  undefined8 in_stack_00000020;
  QTextDecoder *in_stack_00000028;
  QTextDecoder *pQStack0000000000000038;
  QTextEncoder *in_stack_00000040;
  undefined8 in_stack_00000058;
  undefined8 in_stack_00000070;
  QIcon *in_stack_00000078;
  QFileInfo *in_stack_00000090;
  
  pQStack0000000000000038 = in_stack_00000028;
  qt_byte_array_unref(in_stack_00000020);
  QIcon::~QIcon(in_stack_00000078);
  qt_array_data_unref(in_stack_00000070);
  QFileInfo::~QFileInfo(in_stack_00000090);
  if (in_stack_00000040 != (QTextEncoder *)0x0) {
    QTextEncoder::~QTextEncoder(in_stack_00000040);
    operator_delete(in_stack_00000040,0x28);
  }
  pQVar1 = pQStack0000000000000038;
  if (pQStack0000000000000038 != (QTextDecoder *)0x0) {
    QTextDecoder::~QTextDecoder(pQStack0000000000000038);
    operator_delete(pQVar1,0x28);
  }
  gapnode_free(in_stack_00000058);
  QFile::~QFile(in_stack_00000018);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception(unaff_RBX);
}


// ==== entry=004d6d66 name=FUN_004d6d66 size=30 ====

void FUN_004d6d66(void)

{
  undefined8 unaff_RBX;
  QFile *in_stack_00000018;
  undefined8 in_stack_00000020;
  QTextDecoder *in_stack_00000028;
  void *in_stack_00000030;
  QTextEncoder *in_stack_00000040;
  undefined8 in_stack_00000058;
  undefined8 in_stack_00000070;
  QIcon *in_stack_00000078;
  QFileInfo *in_stack_00000090;
  
  operator_delete(in_stack_00000030,0x28);
  qt_byte_array_unref(in_stack_00000020);
  QIcon::~QIcon(in_stack_00000078);
  qt_array_data_unref(in_stack_00000070);
  QFileInfo::~QFileInfo(in_stack_00000090);
  if (in_stack_00000040 != (QTextEncoder *)0x0) {
    QTextEncoder::~QTextEncoder(in_stack_00000040);
    operator_delete(in_stack_00000040,0x28);
  }
  if (in_stack_00000028 != (QTextDecoder *)0x0) {
    QTextDecoder::~QTextDecoder(in_stack_00000028);
    operator_delete(in_stack_00000028,0x28);
  }
  gapnode_free(in_stack_00000058);
  QFile::~QFile(in_stack_00000018);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception(unaff_RBX);
}


// ==== entry=004d6d84 name=FUN_004d6d84 size=23 ====

void FUN_004d6d84(void)

{
  QTextDecoder *pQVar1;
  QTextEncoder *pQVar2;
  undefined8 in_RAX;
  undefined8 uStack0000000000000008;
  QFile *in_stack_00000018;
  QTextDecoder *pQStack0000000000000038;
  QTextEncoder *pQStack0000000000000040;
  undefined8 in_stack_00000058;
  undefined8 in_stack_00000070;
  QIcon *in_stack_00000078;
  QFileInfo *in_stack_00000090;
  
  pQStack0000000000000040 = (QTextEncoder *)0x0;
  pQStack0000000000000038 = (QTextDecoder *)0x0;
  uStack0000000000000008 = in_RAX;
  QIcon::~QIcon(in_stack_00000078);
  qt_array_data_unref(in_stack_00000070);
  QFileInfo::~QFileInfo(in_stack_00000090);
  pQVar2 = pQStack0000000000000040;
  if (pQStack0000000000000040 != (QTextEncoder *)0x0) {
    QTextEncoder::~QTextEncoder(pQStack0000000000000040);
    operator_delete(pQVar2,0x28);
  }
  pQVar1 = pQStack0000000000000038;
  if (pQStack0000000000000038 != (QTextDecoder *)0x0) {
    QTextDecoder::~QTextDecoder(pQStack0000000000000038);
    operator_delete(pQVar1,0x28);
  }
  gapnode_free(in_stack_00000058);
  QFile::~QFile(in_stack_00000018);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception(uStack0000000000000008);
}


// ==== entry=004d6d9b name=FUN_004d6d9b size=50 ====

/* WARNING: Removing unreachable block (ram,0x004d6d21) */
/* WARNING: Removing unreachable block (ram,0x004d6d47) */

void FUN_004d6d9b(void)

{
  undefined8 in_RAX;
  char unaff_BL;
  undefined8 uStack0000000000000008;
  QFile *in_stack_00000018;
  undefined8 in_stack_00000058;
  undefined8 in_stack_00000070;
  QIcon *in_stack_00000078;
  undefined8 in_stack_00000080;
  QFileInfo *in_stack_00000090;
  
  if (unaff_BL != '\0') {
    uStack0000000000000008 = in_RAX;
    qt_byte_array_unref(in_stack_00000080);
    in_RAX = uStack0000000000000008;
  }
  uStack0000000000000008 = in_RAX;
  QIcon::~QIcon(in_stack_00000078);
  qt_array_data_unref(in_stack_00000070);
  QFileInfo::~QFileInfo(in_stack_00000090);
  gapnode_free(in_stack_00000058);
  QFile::~QFile(in_stack_00000018);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception(uStack0000000000000008);
}


// ==== entry=004d6dcd name=FUN_004d6dcd size=36 ====

/* WARNING: Removing unreachable block (ram,0x004d6d21) */
/* WARNING: Removing unreachable block (ram,0x004d6d47) */

void FUN_004d6dcd(void)

{
  undefined8 unaff_RBX;
  QFile *in_stack_00000018;
  undefined8 in_stack_00000048;
  undefined8 in_stack_00000058;
  undefined8 in_stack_00000070;
  QIcon *in_stack_00000078;
  QFileInfo *in_stack_00000090;
  
  qt_array_data_unref(in_stack_00000048);
  QIcon::~QIcon(in_stack_00000078);
  qt_array_data_unref(in_stack_00000070);
  QFileInfo::~QFileInfo(in_stack_00000090);
  gapnode_free(in_stack_00000058);
  QFile::~QFile(in_stack_00000018);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception(unaff_RBX);
}


// ==== entry=004d6df1 name=FUN_004d6df1 size=15 ====

void FUN_004d6df1(void)

{
  undefined8 unaff_RBX;
  QFile *in_stack_00000018;
  undefined8 in_stack_00000020;
  QTextDecoder *in_stack_00000038;
  QTextEncoder *in_stack_00000040;
  undefined8 in_stack_00000048;
  undefined8 in_stack_00000058;
  undefined8 in_stack_00000070;
  QIcon *in_stack_00000078;
  QFileInfo *in_stack_00000090;
  
  qt_array_data_unref(in_stack_00000048);
  qt_byte_array_unref(in_stack_00000020);
  QIcon::~QIcon(in_stack_00000078);
  qt_array_data_unref(in_stack_00000070);
  QFileInfo::~QFileInfo(in_stack_00000090);
  if (in_stack_00000040 != (QTextEncoder *)0x0) {
    QTextEncoder::~QTextEncoder(in_stack_00000040);
    operator_delete(in_stack_00000040,0x28);
  }
  if (in_stack_00000038 != (QTextDecoder *)0x0) {
    QTextDecoder::~QTextDecoder(in_stack_00000038);
    operator_delete(in_stack_00000038,0x28);
  }
  gapnode_free(in_stack_00000058);
  QFile::~QFile(in_stack_00000018);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception(unaff_RBX);
}


// ==== entry=004d6e00 name=FUN_004d6e00 size=23 ====

void FUN_004d6e00(void)

{
  QTextDecoder *pQVar1;
  QTextEncoder *pQVar2;
  undefined8 in_RAX;
  undefined8 uStack0000000000000008;
  QFile *in_stack_00000018;
  QTextDecoder *pQStack0000000000000038;
  QTextEncoder *pQStack0000000000000040;
  undefined8 in_stack_00000058;
  undefined8 in_stack_00000070;
  QIcon *in_stack_00000078;
  QFileInfo *in_stack_00000090;
  
  pQStack0000000000000040 = (QTextEncoder *)0x0;
  pQStack0000000000000038 = (QTextDecoder *)0x0;
  uStack0000000000000008 = in_RAX;
  QIcon::~QIcon(in_stack_00000078);
  qt_array_data_unref(in_stack_00000070);
  QFileInfo::~QFileInfo(in_stack_00000090);
  pQVar2 = pQStack0000000000000040;
  if (pQStack0000000000000040 != (QTextEncoder *)0x0) {
    QTextEncoder::~QTextEncoder(pQStack0000000000000040);
    operator_delete(pQVar2,0x28);
  }
  pQVar1 = pQStack0000000000000038;
  if (pQStack0000000000000038 != (QTextDecoder *)0x0) {
    QTextDecoder::~QTextDecoder(pQStack0000000000000038);
    operator_delete(pQVar1,0x28);
  }
  gapnode_free(in_stack_00000058);
  QFile::~QFile(in_stack_00000018);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception(uStack0000000000000008);
}


// ==== entry=004d6e17 name=FUN_004d6e17 size=23 ====

void FUN_004d6e17(void)

{
  QTextDecoder *pQVar1;
  QTextEncoder *pQVar2;
  undefined8 in_RAX;
  undefined8 uStack0000000000000008;
  QFile *in_stack_00000018;
  QTextDecoder *pQStack0000000000000038;
  QTextEncoder *pQStack0000000000000040;
  undefined8 in_stack_00000058;
  undefined8 in_stack_00000070;
  QIcon *in_stack_00000078;
  QFileInfo *in_stack_00000090;
  
  pQStack0000000000000040 = (QTextEncoder *)0x0;
  pQStack0000000000000038 = (QTextDecoder *)0x0;
  uStack0000000000000008 = in_RAX;
  QIcon::~QIcon(in_stack_00000078);
  qt_array_data_unref(in_stack_00000070);
  QFileInfo::~QFileInfo(in_stack_00000090);
  pQVar2 = pQStack0000000000000040;
  if (pQStack0000000000000040 != (QTextEncoder *)0x0) {
    QTextEncoder::~QTextEncoder(pQStack0000000000000040);
    operator_delete(pQVar2,0x28);
  }
  pQVar1 = pQStack0000000000000038;
  if (pQStack0000000000000038 != (QTextDecoder *)0x0) {
    QTextDecoder::~QTextDecoder(pQStack0000000000000038);
    operator_delete(pQVar1,0x28);
  }
  gapnode_free(in_stack_00000058);
  QFile::~QFile(in_stack_00000018);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception(uStack0000000000000008);
}


// ==== entry=004d6e2e name=FUN_004d6e2e size=23 ====

void FUN_004d6e2e(void)

{
  QTextDecoder *pQVar1;
  QTextEncoder *pQVar2;
  undefined8 in_RAX;
  undefined8 uStack0000000000000008;
  QFile *in_stack_00000018;
  QTextDecoder *pQStack0000000000000038;
  QTextEncoder *pQStack0000000000000040;
  undefined8 in_stack_00000058;
  undefined8 in_stack_00000070;
  QIcon *in_stack_00000078;
  QFileInfo *in_stack_00000090;
  
  pQStack0000000000000040 = (QTextEncoder *)0x0;
  pQStack0000000000000038 = (QTextDecoder *)0x0;
  uStack0000000000000008 = in_RAX;
  QIcon::~QIcon(in_stack_00000078);
  qt_array_data_unref(in_stack_00000070);
  QFileInfo::~QFileInfo(in_stack_00000090);
  pQVar2 = pQStack0000000000000040;
  if (pQStack0000000000000040 != (QTextEncoder *)0x0) {
    QTextEncoder::~QTextEncoder(pQStack0000000000000040);
    operator_delete(pQVar2,0x28);
  }
  pQVar1 = pQStack0000000000000038;
  if (pQStack0000000000000038 != (QTextDecoder *)0x0) {
    QTextDecoder::~QTextDecoder(pQStack0000000000000038);
    operator_delete(pQVar1,0x28);
  }
  gapnode_free(in_stack_00000058);
  QFile::~QFile(in_stack_00000018);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception(uStack0000000000000008);
}


// ==== entry=004d6e45 name=FUN_004d6e45 size=28 ====

void FUN_004d6e45(void)

{
  QFile *in_stack_00000018;
  undefined8 in_stack_00000058;
  
  qt_array_data_unref(in_stack_00000058);
  QFile::~QFile(in_stack_00000018);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d6e61 name=FUN_004d6e61 size=45 ====

void FUN_004d6e61(void)

{
  QFile *in_stack_00000018;
  QVariant *in_stack_00000048;
  undefined8 in_stack_00000058;
  undefined8 in_stack_00000060;
  QVariant *in_stack_00000080;
  
  QVariant::~QVariant(in_stack_00000048);
  qt_byte_array_unref(in_stack_00000060);
  QVariant::~QVariant(in_stack_00000080);
  gapnode_free(in_stack_00000058);
  QFile::~QFile(in_stack_00000018);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d6e8e name=FUN_004d6e8e size=28 ====

void FUN_004d6e8e(void)

{
  undefined8 unaff_RBX;
  QFile *in_stack_00000018;
  QTextDecoder *in_stack_00000038;
  QTextEncoder *in_stack_00000040;
  undefined8 in_stack_00000048;
  undefined8 in_stack_00000058;
  undefined8 in_stack_00000070;
  QIcon *in_stack_00000078;
  QFileInfo *in_stack_00000090;
  
  qt_byte_array_unref(in_stack_00000048);
  qt_byte_array_unref(&stack0x000000c0);
  QIcon::~QIcon(in_stack_00000078);
  qt_array_data_unref(in_stack_00000070);
  QFileInfo::~QFileInfo(in_stack_00000090);
  if (in_stack_00000040 != (QTextEncoder *)0x0) {
    QTextEncoder::~QTextEncoder(in_stack_00000040);
    operator_delete(in_stack_00000040,0x28);
  }
  if (in_stack_00000038 != (QTextDecoder *)0x0) {
    QTextDecoder::~QTextDecoder(in_stack_00000038);
    operator_delete(in_stack_00000038,0x28);
  }
  gapnode_free(in_stack_00000058);
  QFile::~QFile(in_stack_00000018);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception(unaff_RBX);
}


// ==== entry=004d6eaa name=FUN_004d6eaa size=14 ====

void FUN_004d6eaa(void)

{
  QTextEncoder *pQVar1;
  undefined8 in_RAX;
  undefined8 uStack0000000000000008;
  QFile *in_stack_00000018;
  QTextDecoder *in_stack_00000038;
  QTextEncoder *pQStack0000000000000040;
  undefined8 in_stack_00000058;
  undefined8 in_stack_00000070;
  QIcon *in_stack_00000078;
  QFileInfo *in_stack_00000090;
  
  pQStack0000000000000040 = (QTextEncoder *)0x0;
  uStack0000000000000008 = in_RAX;
  QIcon::~QIcon(in_stack_00000078);
  qt_array_data_unref(in_stack_00000070);
  QFileInfo::~QFileInfo(in_stack_00000090);
  pQVar1 = pQStack0000000000000040;
  if (pQStack0000000000000040 != (QTextEncoder *)0x0) {
    QTextEncoder::~QTextEncoder(pQStack0000000000000040);
    operator_delete(pQVar1,0x28);
  }
  if (in_stack_00000038 != (QTextDecoder *)0x0) {
    QTextDecoder::~QTextDecoder(in_stack_00000038);
    operator_delete(in_stack_00000038,0x28);
  }
  gapnode_free(in_stack_00000058);
  QFile::~QFile(in_stack_00000018);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception(uStack0000000000000008);
}


// ==== entry=004d6eb8 name=FUN_004d6eb8 size=23 ====

void FUN_004d6eb8(void)

{
  QTextDecoder *pQVar1;
  QTextEncoder *pQVar2;
  QFile *in_stack_00000018;
  QTextDecoder *pQStack0000000000000038;
  QTextEncoder *pQStack0000000000000040;
  undefined8 in_stack_00000058;
  undefined8 in_stack_00000070;
  QFileInfo *in_stack_00000090;
  
  pQStack0000000000000040 = (QTextEncoder *)0x0;
  pQStack0000000000000038 = (QTextDecoder *)0x0;
  qt_array_data_unref(in_stack_00000070);
  QFileInfo::~QFileInfo(in_stack_00000090);
  pQVar2 = pQStack0000000000000040;
  if (pQStack0000000000000040 != (QTextEncoder *)0x0) {
    QTextEncoder::~QTextEncoder(pQStack0000000000000040);
    operator_delete(pQVar2,0x28);
  }
  pQVar1 = pQStack0000000000000038;
  if (pQStack0000000000000038 != (QTextDecoder *)0x0) {
    QTextDecoder::~QTextDecoder(pQStack0000000000000038);
    operator_delete(pQVar1,0x28);
  }
  gapnode_free(in_stack_00000058);
  QFile::~QFile(in_stack_00000018);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d6ecf name=FUN_004d6ecf size=13 ====

void FUN_004d6ecf(void)

{
  undefined8 unaff_RBX;
  QFile *in_stack_00000018;
  undefined8 in_stack_00000020;
  QTextDecoder *in_stack_00000038;
  QTextEncoder *in_stack_00000040;
  undefined8 in_stack_00000058;
  undefined8 in_stack_00000070;
  QIcon *in_stack_00000078;
  QFileInfo *in_stack_00000090;
  
  qt_byte_array_unref();
  qt_byte_array_unref(in_stack_00000020);
  QIcon::~QIcon(in_stack_00000078);
  qt_array_data_unref(in_stack_00000070);
  QFileInfo::~QFileInfo(in_stack_00000090);
  if (in_stack_00000040 != (QTextEncoder *)0x0) {
    QTextEncoder::~QTextEncoder(in_stack_00000040);
    operator_delete(in_stack_00000040,0x28);
  }
  if (in_stack_00000038 != (QTextDecoder *)0x0) {
    QTextDecoder::~QTextDecoder(in_stack_00000038);
    operator_delete(in_stack_00000038,0x28);
  }
  gapnode_free(in_stack_00000058);
  QFile::~QFile(in_stack_00000018);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception(unaff_RBX);
}


// ==== entry=004d6edc name=FUN_004d6edc size=23 ====

void FUN_004d6edc(void)

{
  QTextDecoder *pQVar1;
  QTextEncoder *pQVar2;
  QFile *in_stack_00000018;
  QTextDecoder *pQStack0000000000000038;
  QTextEncoder *pQStack0000000000000040;
  undefined8 in_stack_00000058;
  QFileInfo *in_stack_00000090;
  
  pQStack0000000000000040 = (QTextEncoder *)0x0;
  pQStack0000000000000038 = (QTextDecoder *)0x0;
  QFileInfo::~QFileInfo(in_stack_00000090);
  pQVar2 = pQStack0000000000000040;
  if (pQStack0000000000000040 != (QTextEncoder *)0x0) {
    QTextEncoder::~QTextEncoder(pQStack0000000000000040);
    operator_delete(pQVar2,0x28);
  }
  pQVar1 = pQStack0000000000000038;
  if (pQStack0000000000000038 != (QTextDecoder *)0x0) {
    QTextDecoder::~QTextDecoder(pQStack0000000000000038);
    operator_delete(pQVar1,0x28);
  }
  gapnode_free(in_stack_00000058);
  QFile::~QFile(in_stack_00000018);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d6ef3 name=FUN_004d6ef3 size=15 ====

void FUN_004d6ef3(void)

{
  undefined8 unaff_RBX;
  QFile *in_stack_00000018;
  undefined8 in_stack_00000020;
  QTextDecoder *in_stack_00000038;
  QTextEncoder *in_stack_00000040;
  undefined8 in_stack_00000048;
  undefined8 in_stack_00000058;
  undefined8 in_stack_00000070;
  QIcon *in_stack_00000078;
  QFileInfo *in_stack_00000090;
  
  qt_byte_array_unref(in_stack_00000048);
  qt_byte_array_unref(in_stack_00000020);
  QIcon::~QIcon(in_stack_00000078);
  qt_array_data_unref(in_stack_00000070);
  QFileInfo::~QFileInfo(in_stack_00000090);
  if (in_stack_00000040 != (QTextEncoder *)0x0) {
    QTextEncoder::~QTextEncoder(in_stack_00000040);
    operator_delete(in_stack_00000040,0x28);
  }
  if (in_stack_00000038 != (QTextDecoder *)0x0) {
    QTextDecoder::~QTextDecoder(in_stack_00000038);
    operator_delete(in_stack_00000038,0x28);
  }
  gapnode_free(in_stack_00000058);
  QFile::~QFile(in_stack_00000018);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception(unaff_RBX);
}


// ==== entry=004d6f02 name=FUN_004d6f02 size=23 ====

void FUN_004d6f02(void)

{
  QTextDecoder *pQVar1;
  QTextEncoder *pQVar2;
  undefined8 in_RAX;
  undefined8 uStack0000000000000008;
  QFile *in_stack_00000018;
  QTextDecoder *pQStack0000000000000038;
  QTextEncoder *pQStack0000000000000040;
  undefined8 in_stack_00000058;
  undefined8 in_stack_00000070;
  QIcon *in_stack_00000078;
  QFileInfo *in_stack_00000090;
  
  pQStack0000000000000040 = (QTextEncoder *)0x0;
  pQStack0000000000000038 = (QTextDecoder *)0x0;
  uStack0000000000000008 = in_RAX;
  QIcon::~QIcon(in_stack_00000078);
  qt_array_data_unref(in_stack_00000070);
  QFileInfo::~QFileInfo(in_stack_00000090);
  pQVar2 = pQStack0000000000000040;
  if (pQStack0000000000000040 != (QTextEncoder *)0x0) {
    QTextEncoder::~QTextEncoder(pQStack0000000000000040);
    operator_delete(pQVar2,0x28);
  }
  pQVar1 = pQStack0000000000000038;
  if (pQStack0000000000000038 != (QTextDecoder *)0x0) {
    QTextDecoder::~QTextDecoder(pQStack0000000000000038);
    operator_delete(pQVar1,0x28);
  }
  gapnode_free(in_stack_00000058);
  QFile::~QFile(in_stack_00000018);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception(uStack0000000000000008);
}


// ==== entry=004d6f19 name=FUN_004d6f19 size=20 ====

void FUN_004d6f19(void)

{
  undefined8 unaff_RBX;
  QFile *in_stack_00000018;
  undefined8 in_stack_00000020;
  void *in_stack_00000028;
  QTextDecoder *in_stack_00000038;
  QTextEncoder *in_stack_00000040;
  undefined8 in_stack_00000058;
  undefined8 in_stack_00000070;
  QIcon *in_stack_00000078;
  QFileInfo *in_stack_00000090;
  
  operator_delete(in_stack_00000028,0x28);
  qt_byte_array_unref(in_stack_00000020);
  QIcon::~QIcon(in_stack_00000078);
  qt_array_data_unref(in_stack_00000070);
  QFileInfo::~QFileInfo(in_stack_00000090);
  if (in_stack_00000040 != (QTextEncoder *)0x0) {
    QTextEncoder::~QTextEncoder(in_stack_00000040);
    operator_delete(in_stack_00000040,0x28);
  }
  if (in_stack_00000038 != (QTextDecoder *)0x0) {
    QTextDecoder::~QTextDecoder(in_stack_00000038);
    operator_delete(in_stack_00000038,0x28);
  }
  gapnode_free(in_stack_00000058);
  QFile::~QFile(in_stack_00000018);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception(unaff_RBX);
}


// ==== entry=004d6f2d name=FUN_004d6f2d size=15 ====

void FUN_004d6f2d(void)

{
  QTextDecoder *pQVar1;
  undefined8 unaff_RBX;
  QFile *in_stack_00000018;
  undefined8 in_stack_00000020;
  QTextDecoder *in_stack_00000028;
  QTextDecoder *pQStack0000000000000038;
  QTextEncoder *in_stack_00000040;
  undefined8 in_stack_00000058;
  undefined8 in_stack_00000070;
  QIcon *in_stack_00000078;
  QFileInfo *in_stack_00000090;
  
  pQStack0000000000000038 = in_stack_00000028;
  qt_byte_array_unref(in_stack_00000020);
  QIcon::~QIcon(in_stack_00000078);
  qt_array_data_unref(in_stack_00000070);
  QFileInfo::~QFileInfo(in_stack_00000090);
  if (in_stack_00000040 != (QTextEncoder *)0x0) {
    QTextEncoder::~QTextEncoder(in_stack_00000040);
    operator_delete(in_stack_00000040,0x28);
  }
  pQVar1 = pQStack0000000000000038;
  if (pQStack0000000000000038 != (QTextDecoder *)0x0) {
    QTextDecoder::~QTextDecoder(pQStack0000000000000038);
    operator_delete(pQVar1,0x28);
  }
  gapnode_free(in_stack_00000058);
  QFile::~QFile(in_stack_00000018);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception(unaff_RBX);
}


// ==== entry=004d6f3c name=FUN_004d6f3c size=16 ====

void FUN_004d6f3c(void)

{
  qt_array_data_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d6f4c name=FUN_004d6f4c size=16 ====

void FUN_004d6f4c(void)

{
  qt_array_data_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d6f60 name=FUN_004d6f60 size=16 ====

void FUN_004d6f60(void)

{
  QJSValue *unaff_RBX;
  
  QJSValue::~QJSValue(unaff_RBX);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d6f70 name=FUN_004d6f70 size=126 ====

void FUN_004d6f70(undefined8 param_1,undefined8 param_2,long param_3)

{
  long lVar1;
  QJSValue *unaff_RBX;
  QJSValue *unaff_RBP;
  undefined8 *unaff_R12;
  long lStack0000000000000008;
  undefined8 in_stack_00000038;
  
  lStack0000000000000008 = param_3;
  QJSValue::~QJSValue(unaff_RBP);
  qt_array_data_unref();
  lVar1 = lStack0000000000000008;
  qt_array_data_unref();
  QJSValue::~QJSValue(unaff_RBX);
  if (lVar1 == 1) {
    __cxa_begin_catch();
                    /* try { // try from 004d6fc5 to 004d6fc9 has its CatchHandler @ 004d704d */
    QJSValue::toString();
    *unaff_R12 = in_stack_00000038;
    qt_array_data_unref();
                    /* try { // try from 004d6fe4 to 004d6fe8 has its CatchHandler @ 004d703a */
    __cxa_end_catch();
    return;
  }
  qt_array_data_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d6fee name=FUN_004d6fee size=32 ====

void FUN_004d6fee(void)

{
  undefined8 *unaff_R12;
  long unaff_R15;
  undefined8 in_stack_00000038;
  
  qt_array_data_unref();
  qt_array_data_unref();
  qt_array_data_unref();
  if (unaff_R15 == 1) {
    __cxa_begin_catch();
    QJSValue::toString();
    *unaff_R12 = in_stack_00000038;
    qt_array_data_unref();
    __cxa_end_catch();
    return;
  }
  qt_array_data_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d700e name=FUN_004d700e size=60 ====

void FUN_004d700e(undefined8 param_1,undefined8 param_2,long param_3)

{
  long lVar1;
  QJSValue *unaff_RBX;
  undefined8 *unaff_R12;
  long lStack0000000000000008;
  undefined8 in_stack_00000038;
  
  lStack0000000000000008 = param_3;
  qt_array_data_unref();
  qt_array_data_unref();
  lVar1 = lStack0000000000000008;
  qt_array_data_unref();
  QJSValue::~QJSValue(unaff_RBX);
  if (lVar1 == 1) {
    __cxa_begin_catch();
    QJSValue::toString();
    *unaff_R12 = in_stack_00000038;
    qt_array_data_unref();
    __cxa_end_catch();
    return;
  }
  qt_array_data_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d7058 name=FUN_004d7058 size=45 ====

void FUN_004d7058(void)

{
  QJSValue *unaff_R12;
  long unaff_R14;
  
  qt_array_data_unref();
  qt_array_data_unref(&stack0x00000008);
  if (unaff_R14 == 1) {
    __cxa_begin_catch();
                    /* try { // try from 004d707b to 004d707f has its CatchHandler @ 004d7092 */
    __cxa_end_catch();
    return;
  }
  QJSValue::~QJSValue(unaff_R12);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d7085 name=FUN_004d7085 size=29 ====

void FUN_004d7085(void)

{
  QJSValue *unaff_R12;
  long unaff_R14;
  
  qt_array_data_unref();
  qt_array_data_unref();
  if (unaff_R14 == 1) {
    __cxa_begin_catch();
    __cxa_end_catch();
    return;
  }
  QJSValue::~QJSValue(unaff_R12);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d70a6 name=FUN_004d70a6 size=16 ====

void FUN_004d70a6(void)

{
  QJSValue *unaff_RBX;
  
  QJSValue::~QJSValue(unaff_RBX);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d70b6 name=FUN_004d70b6 size=35 ====

void FUN_004d70b6(void)

{
  QJSValue *unaff_RBX;
  QJSValue *unaff_R12;
  
  QJSValue::~QJSValue(unaff_RBX);
  QJSValue::~QJSValue(unaff_R12);
  qt_array_data_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d70d9 name=FUN_004d70d9 size=43 ====

void FUN_004d70d9(void)

{
  QJSValue *unaff_R12;
  
  qt_array_data_unref();
  qt_array_data_unref();
  QJSValue::~QJSValue(unaff_R12);
  qt_array_data_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d7104 name=FUN_004d7104 size=43 ====

void FUN_004d7104(void)

{
  QJSValue *unaff_R12;
  
  qt_array_data_unref();
  qt_array_data_unref();
  QJSValue::~QJSValue(unaff_R12);
  qt_array_data_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d712f name=FUN_004d712f size=10 ====

void FUN_004d712f(void)

{
  QJSValue *unaff_R12;
  
  qt_array_data_unref();
  QJSValue::~QJSValue(unaff_R12);
  qt_array_data_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d7139 name=FUN_004d7139 size=10 ====

void FUN_004d7139(void)

{
  QJSValue *unaff_RBX;
  QJSValue *unaff_R12;
  
  QJSValue::~QJSValue(unaff_RBX);
  QJSValue::~QJSValue(unaff_R12);
  qt_array_data_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d7143 name=FUN_004d7143 size=21 ====

void FUN_004d7143(void)

{
  QJSValue *unaff_R12;
  
  qt_array_data_unref();
  qt_array_data_unref();
  QJSValue::~QJSValue(unaff_R12);
  qt_array_data_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d7158 name=FUN_004d7158 size=10 ====

void FUN_004d7158(void)

{
  QJSValue *unaff_RBX;
  QJSValue *unaff_R12;
  
  QJSValue::~QJSValue(unaff_RBX);
  QJSValue::~QJSValue(unaff_R12);
  qt_array_data_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d7162 name=FUN_004d7162 size=16 ====

void FUN_004d7162(void)

{
  QJSValue *unaff_RBX;
  
  QJSValue::~QJSValue(unaff_RBX);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d7172 name=FUN_004d7172 size=35 ====

void FUN_004d7172(void)

{
  QJSValue *unaff_R12;
  
  qt_array_data_unref();
  QJSValue::~QJSValue(unaff_R12);
  qt_array_data_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d7195 name=FUN_004d7195 size=18 ====

void FUN_004d7195(void)

{
  QJSValue *unaff_R12;
  
  qt_array_data_unref();
  qt_array_data_unref();
  QJSValue::~QJSValue(unaff_R12);
  qt_array_data_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d71a7 name=FUN_004d71a7 size=21 ====

void FUN_004d71a7(void)

{
  void *unaff_R12;
  
  operator_delete(unaff_R12,0x18);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d71bc name=FUN_004d71bc size=16 ====

void FUN_004d71bc(void)

{
  qt_array_data_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d71cc name=FUN_004d71cc size=10 ====

void FUN_004d71cc(void)

{
  QJSValue *unaff_RBX;
  QJSValue *unaff_R12;
  
  QJSValue::~QJSValue(unaff_RBX);
  QJSValue::~QJSValue(unaff_R12);
  qt_array_data_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d71e0 name=FUN_004d71e0 size=58 ====

void FUN_004d71e0(void)

{
  QObject *unaff_RBX;
  QArrayData *pQVar1;
  
  pQVar1 = *(QArrayData **)(unaff_RBX + 0x20);
  if (*(int *)pQVar1 != 0) {
    if (*(int *)pQVar1 == -1) goto LAB_004d71f9;
    LOCK();
    *(int *)pQVar1 = *(int *)pQVar1 + -1;
    UNLOCK();
    if (*(int *)pQVar1 != 0) goto LAB_004d71f9;
    pQVar1 = *(QArrayData **)(unaff_RBX + 0x20);
  }
  QArrayData::deallocate(pQVar1,2,8);
LAB_004d71f9:
  QObject::~QObject(unaff_RBX);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d721a name=FUN_004d721a size=16 ====

void FUN_004d721a(void)

{
  record_freeStrings();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d722a name=FUN_004d722a size=16 ====

void FUN_004d722a(void)

{
  QHostAddress *unaff_RBX;
  
  QHostAddress::~QHostAddress(unaff_RBX);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d723a name=FUN_004d723a size=38 ====

void FUN_004d723a(void)

{
  qt_array_data_unref(&stack0x00000028);
  qt_array_data_unref(&stack0x00000018);
  qt_array_data_unref(&stack0x00000008);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d7260 name=FUN_004d7260 size=16 ====

void FUN_004d7260(void)

{
  qt_array_data_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d7270 name=FUN_004d7270 size=24 ====

void FUN_004d7270(void)

{
  qt_array_data_unref();
  qt_array_data_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d7288 name=FUN_004d7288 size=16 ====

void FUN_004d7288(void)

{
  qt_array_data_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d7298 name=FUN_004d7298 size=41 ====

void FUN_004d7298(void)

{
  if (DAT_011c17c8 == -1) {
    DAT_011c17c8 = -2;
  }
  __cxa_guard_abort(&DAT_011c1788);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d72c2 name=FUN_004d72c2 size=42 ====

void FUN_004d72c2(void)

{
  QDir *unaff_R12;
  undefined8 in_stack_00000008;
  
  qt_array_data_unref();
  qt_array_data_unref(in_stack_00000008);
  qt_shared_data_unref();
  QDir::~QDir(unaff_R12);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d72ec name=FUN_004d72ec size=16 ====

void FUN_004d72ec(void)

{
  qt_array_data_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d72fc name=FUN_004d72fc size=16 ====

void FUN_004d72fc(void)

{
  atomic_refptr_delete();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d730c name=FUN_004d730c size=29 ====

void FUN_004d730c(void)

{
  QFileInfo *unaff_R14;
  void *unaff_R15;
  
  operator_delete(unaff_R15,0x18);
  QFileInfo::~QFileInfo(unaff_R14);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d7329 name=FUN_004d7329 size=56 ====

void FUN_004d7329(void)

{
  long unaff_R12;
  QFileInfo *unaff_R14;
  
  qt_array_data_unref(unaff_R12 + 0x18);
  atomic_refptr_delete(unaff_R12 + 8);
  qt_array_data_unref(&stack0x00000078);
  atomic_refptr_delete(&stack0x00000068);
  atomic_refptr_delete(&stack0x00000040);
  QFileInfo::~QFileInfo(unaff_R14);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d7361 name=FUN_004d7361 size=18 ====

void FUN_004d7361(void)

{
  QMediaContent *unaff_R12;
  QFileInfo *unaff_R14;
  QUrl *unaff_R15;
  
  QMediaContent::~QMediaContent(unaff_R12);
  QUrl::~QUrl(unaff_R15);
  atomic_refptr_delete(&stack0x00000040);
  QFileInfo::~QFileInfo(unaff_R14);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d7380 name=FUN_004d7380 size=16 ====

void FUN_004d7380(void)

{
  QRegularExpressionMatch *unaff_R12;
  
  QRegularExpressionMatch::~QRegularExpressionMatch(unaff_R12);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d7390 name=FUN_004d7390 size=21 ====

void FUN_004d7390(void)

{
  void *unaff_RBP;
  
  operator_delete(unaff_RBP,0xd8);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d73a5 name=FUN_004d73a5 size=16 ====

void FUN_004d73a5(void)

{
  qt_array_data_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d73b5 name=FUN_004d73b5 size=16 ====

void FUN_004d73b5(void)

{
  QVariant *unaff_R12;
  
  QVariant::~QVariant(unaff_R12);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d73c5 name=FUN_004d73c5 size=29 ====

void FUN_004d73c5(void)

{
  void *unaff_RBP;
  
  operator_delete(unaff_RBP,8);
  qt_array_data_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d73e2 name=FUN_004d73e2 size=24 ====

void FUN_004d73e2(void)

{
  qt_array_data_unref();
  qt_array_data_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d73fa name=FUN_004d73fa size=16 ====

void FUN_004d73fa(void)

{
  qt_array_data_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d740a name=FUN_004d740a size=24 ====

void FUN_004d740a(void)

{
  QJsonDocument *unaff_RBP;
  
  QJsonDocument::~QJsonDocument(unaff_RBP);
  qt_byte_array_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d7422 name=FUN_004d7422 size=60 ====

void FUN_004d7422(void)

{
  long unaff_RBX;
  
  qt_byte_array_unref(unaff_RBX + 0x30);
  qmap_freetree_variant_nodes(unaff_RBX + 0x28);
  qt_array_data_unref(unaff_RBX + 0x20);
  qt_array_data_unref(unaff_RBX + 0x18);
  qt_array_data_unref();
  qt_array_data_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d745e name=FUN_004d745e size=24 ====

void FUN_004d745e(void)

{
  qt_array_data_unref();
  qt_array_data_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d7476 name=FUN_004d7476 size=32 ====

void FUN_004d7476(void)

{
  QJsonValue *unaff_R13;
  QJsonObject *unaff_R14;
  
  qt_array_data_unref();
  QJsonValue::~QJsonValue(unaff_R13);
  QJsonObject::~QJsonObject(unaff_R14);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d7496 name=FUN_004d7496 size=32 ====

void FUN_004d7496(void)

{
  QJsonObject *unaff_R14;
  
  QJsonObject::~QJsonObject(unaff_R14);
  qt_byte_array_unref();
  qt_byte_array_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d74b6 name=FUN_004d74b6 size=10 ====

void FUN_004d74b6(void)

{
  QJsonDocument *unaff_R12;
  
  QJsonDocument::~QJsonDocument(unaff_R12);
  qt_byte_array_unref();
  qt_byte_array_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d74c0 name=FUN_004d74c0 size=35 ====

void FUN_004d74c0(void)

{
  QVariant *unaff_RBP;
  QVariant *unaff_R12;
  
  QVariant::~QVariant(unaff_RBP);
  qt_array_data_unref();
  QVariant::~QVariant(unaff_R12);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d74e4 name=FUN_004d74e4 size=35 ====

void FUN_004d74e4(void)

{
  QVariant *unaff_RBP;
  QVariant *unaff_R13;
  
  QVariant::~QVariant(unaff_RBP);
  qt_array_data_unref();
  QVariant::~QVariant(unaff_R13);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d7508 name=FUN_004d7508 size=35 ====

void FUN_004d7508(void)

{
  QVariant *unaff_RBP;
  QVariant *unaff_R13;
  
  QVariant::~QVariant(unaff_RBP);
  qt_array_data_unref();
  QVariant::~QVariant(unaff_R13);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d752c name=FUN_004d752c size=35 ====

void FUN_004d752c(void)

{
  QVariant *unaff_RBP;
  QVariant *unaff_R13;
  
  QVariant::~QVariant(unaff_RBP);
  qt_array_data_unref();
  QVariant::~QVariant(unaff_R13);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d7550 name=FUN_004d7550 size=35 ====

void FUN_004d7550(void)

{
  QVariant *unaff_RBP;
  QVariant *unaff_R13;
  
  QVariant::~QVariant(unaff_RBP);
  qt_array_data_unref();
  QVariant::~QVariant(unaff_R13);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d7574 name=FUN_004d7574 size=47 ====

void FUN_004d7574(void)

{
  QVariant *unaff_R12;
  
  QVariant::~QVariant(unaff_R12);
  qt_array_data_unref(&stack0x00000020);
  QVariant::~QVariant((QVariant *)&stack0x00000030);
  qt_array_data_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d75a3 name=FUN_004d75a3 size=18 ====

void FUN_004d75a3(void)

{
  QVariant::~QVariant((QVariant *)&stack0x00000030);
  qt_array_data_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d75b5 name=FUN_004d75b5 size=24 ====

void FUN_004d75b5(void)

{
  QVariant *unaff_R12;
  
  qt_array_data_unref();
  QVariant::~QVariant(unaff_R12);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d75cd name=FUN_004d75cd size=8 ====

void FUN_004d75cd(void)

{
  qt_array_data_unref(&stack0x00000020);
  QVariant::~QVariant((QVariant *)&stack0x00000030);
  qt_array_data_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d75d6 name=FUN_004d75d6 size=47 ====

void FUN_004d75d6(void)

{
  QVariant *unaff_R12;
  
  QVariant::~QVariant(unaff_R12);
  qt_array_data_unref(&stack0x00000018);
  QVariant::~QVariant((QVariant *)&stack0x00000020);
  qt_array_data_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d7605 name=FUN_004d7605 size=8 ====

void FUN_004d7605(void)

{
  QVariant::~QVariant((QVariant *)&stack0x00000020);
  qt_array_data_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d760d name=FUN_004d760d size=24 ====

void FUN_004d760d(void)

{
  QVariant *unaff_R12;
  
  qt_array_data_unref();
  QVariant::~QVariant(unaff_R12);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d7625 name=FUN_004d7625 size=18 ====

void FUN_004d7625(void)

{
  qt_array_data_unref(&stack0x00000018);
  QVariant::~QVariant((QVariant *)&stack0x00000020);
  qt_array_data_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d7638 name=FUN_004d7638 size=47 ====

void FUN_004d7638(void)

{
  QVariant *unaff_R12;
  
  QVariant::~QVariant(unaff_R12);
  qt_array_data_unref(&stack0x00000020);
  QVariant::~QVariant((QVariant *)&stack0x00000030);
  qt_array_data_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d7667 name=FUN_004d7667 size=18 ====

void FUN_004d7667(void)

{
  QVariant::~QVariant((QVariant *)&stack0x00000030);
  qt_array_data_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d7679 name=FUN_004d7679 size=24 ====

void FUN_004d7679(void)

{
  QVariant *unaff_R12;
  
  qt_array_data_unref();
  QVariant::~QVariant(unaff_R12);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d7691 name=FUN_004d7691 size=8 ====

void FUN_004d7691(void)

{
  qt_array_data_unref(&stack0x00000020);
  QVariant::~QVariant((QVariant *)&stack0x00000030);
  qt_array_data_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d769a name=FUN_004d769a size=24 ====

void FUN_004d769a(void)

{
  QVariant *unaff_R12;
  
  qt_array_data_unref();
  QVariant::~QVariant(unaff_R12);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d76b2 name=FUN_004d76b2 size=19 ====

void FUN_004d76b2(void)

{
  QVariant::~QVariant((QVariant *)&stack0x00000030);
  qt_array_data_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d76c5 name=FUN_004d76c5 size=5 ====

/* WARNING: Removing unreachable block (ram,0x004d76dc) */

void FUN_004d76c5(void)

{
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d76ca name=FUN_004d76ca size=38 ====

void FUN_004d76ca(void)

{
  qt_array_data_unref(&stack0x00000020);
  QVariant::~QVariant((QVariant *)&stack0x00000030);
  qt_array_data_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d76f0 name=FUN_004d76f0 size=26 ====

void FUN_004d76f0(void)

{
  qmap_freetree_variant_nodes();
  QVariant::~QVariant((QVariant *)&stack0x00000040);
  qt_array_data_unref(&stack0x00000020);
  QVariant::~QVariant((QVariant *)&stack0x00000030);
  qt_array_data_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d770a name=FUN_004d770a size=16 ====

void FUN_004d770a(void)

{
  qt_array_data_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d771a name=FUN_004d771a size=24 ====

void FUN_004d771a(void)

{
  QVariant *unaff_R12;
  
  qt_array_data_unref();
  QVariant::~QVariant(unaff_R12);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d7732 name=FUN_004d7732 size=19 ====

void FUN_004d7732(void)

{
  QVariant::~QVariant((QVariant *)&stack0x00000030);
  qt_array_data_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d7745 name=FUN_004d7745 size=5 ====

/* WARNING: Removing unreachable block (ram,0x004d775c) */

void FUN_004d7745(void)

{
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d774a name=FUN_004d774a size=38 ====

void FUN_004d774a(void)

{
  qt_array_data_unref(&stack0x00000020);
  QVariant::~QVariant((QVariant *)&stack0x00000030);
  qt_array_data_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d7770 name=FUN_004d7770 size=26 ====

void FUN_004d7770(void)

{
  qmap_freetree_variant_nodes();
  QVariant::~QVariant((QVariant *)&stack0x00000040);
  qt_array_data_unref(&stack0x00000020);
  QVariant::~QVariant((QVariant *)&stack0x00000030);
  qt_array_data_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d778a name=FUN_004d778a size=16 ====

void FUN_004d778a(void)

{
  qt_array_data_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d779a name=FUN_004d779a size=364 ====

void FUN_004d779a(void)

{
  int iVar1;
  QRegularExpression *pQVar2;
  undefined8 *puVar3;
  Data *pDVar4;
  QStringMatcher *this;
  char cVar5;
  QObject *unaff_RBX;
  void *unaff_R12;
  Data *pDVar6;
  
  operator_delete(unaff_R12,0xb0);
  FUN_0065a8d0(unaff_RBX + 0x78);
  FUN_0065a8d0(unaff_RBX + 0x70);
  pQVar2 = *(QRegularExpression **)(unaff_RBX + 0x68);
  if (pQVar2 != (QRegularExpression *)0x0) {
    QRegularExpression::~QRegularExpression(pQVar2);
    operator_delete(pQVar2,8);
  }
  pQVar2 = *(QRegularExpression **)(unaff_RBX + 0x60);
  if (pQVar2 != (QRegularExpression *)0x0) {
    QRegularExpression::~QRegularExpression(pQVar2);
    operator_delete(pQVar2,8);
  }
  puVar3 = *(undefined8 **)(unaff_RBX + 0x58);
  if (puVar3 != (undefined8 *)0x0) {
    if ((void *)puVar3[0x13] != (void *)0x0) {
      operator_delete((void *)puVar3[0x13]);
    }
    if ((void *)puVar3[0xf] != (void *)0x0) {
      operator_delete((void *)puVar3[0xf]);
    }
    if ((void *)puVar3[0xc] != (void *)0x0) {
      operator_delete((void *)puVar3[0xc]);
    }
    if ((void *)puVar3[9] != (void *)0x0) {
      operator_delete((void *)puVar3[9]);
    }
    cVar5 = qatomic_int_deref(puVar3[8]);
    if (cVar5 == '\0') {
      pDVar4 = (Data *)puVar3[8];
      pDVar6 = pDVar4 + (long)*(int *)(pDVar4 + 0xc) * 8 + 0x10;
      iVar1 = *(int *)(pDVar4 + 8);
      while (pDVar4 + (long)iVar1 * 8 + 0x10 != pDVar6) {
        pDVar6 = pDVar6 + -8;
        this = *(QStringMatcher **)pDVar6;
        if (this != (QStringMatcher *)0x0) {
          QStringMatcher::~QStringMatcher(this);
          operator_delete(this,0x418);
        }
      }
      QListData::dispose(pDVar4);
    }
    qt_shared_data_unref(puVar3 + 3);
    qt_array_data_unref(puVar3 + 2);
    qt_array_data_unref(puVar3 + 1);
    if ((undefined1 *)*puVar3 != &DAT_011c5338) {
      refcount_releaseDelete();
    }
    operator_delete(puVar3,0xb0);
  }
  FUN_00659276();
  FUN_00659460(unaff_RBX + 0x18);
  QObject::~QObject(unaff_RBX);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d7906 name=FUN_004d7906 size=41 ====

void FUN_004d7906(void)

{
  if (DAT_011c1880 == -1) {
    DAT_011c1880 = -2;
  }
  __cxa_guard_abort(&DAT_011c17e8);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d7930 name=FUN_004d7930 size=40 ====

void FUN_004d7930(void)

{
  QJsonValue *unaff_R12;
  QJsonDocument *unaff_R13;
  
  QJsonValue::~QJsonValue(unaff_R12);
  qt_array_data_unref();
  qt_array_data_unref();
  QJsonDocument::~QJsonDocument(unaff_R13);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d7958 name=FUN_004d7958 size=10 ====

void FUN_004d7958(void)

{
  QJsonDocument *unaff_R13;
  
  qt_array_data_unref();
  qt_array_data_unref();
  QJsonDocument::~QJsonDocument(unaff_R13);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d7962 name=FUN_004d7962 size=16 ====

void FUN_004d7962(void)

{
  qt_byte_array_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d7972 name=FUN_004d7972 size=15 ====

void FUN_004d7972(void)

{
  void *unaff_R12;
  QJsonDocument *unaff_R13;
  
  operator_delete(unaff_R12,8);
  qt_array_data_unref();
  QJsonDocument::~QJsonDocument(unaff_R13);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d7981 name=FUN_004d7981 size=10 ====

void FUN_004d7981(void)

{
  QJsonDocument *unaff_R13;
  
  qt_array_data_unref();
  qt_array_data_unref();
  QJsonDocument::~QJsonDocument(unaff_R13);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d798b name=FUN_004d798b size=18 ====

void FUN_004d798b(void)

{
  QJsonValue *unaff_R12;
  QJsonDocument *unaff_R13;
  
  QJsonValue::~QJsonValue(unaff_R12);
  qt_array_data_unref();
  QJsonDocument::~QJsonDocument(unaff_R13);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d799d name=FUN_004d799d size=18 ====

void FUN_004d799d(void)

{
  QJsonValue *unaff_R12;
  QJsonDocument *unaff_R13;
  
  QJsonValue::~QJsonValue(unaff_R12);
  qt_array_data_unref();
  qt_array_data_unref();
  QJsonDocument::~QJsonDocument(unaff_R13);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d79af name=FUN_004d79af size=21 ====

void FUN_004d79af(void)

{
  QJsonValue *unaff_R12;
  QJsonDocument *unaff_R13;
  
  QJsonValue::~QJsonValue(unaff_R12);
  qt_array_data_unref();
  qt_array_data_unref();
  QJsonDocument::~QJsonDocument(unaff_R13);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d79c4 name=FUN_004d79c4 size=16 ====

void FUN_004d79c4(void)

{
  qt_array_data_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d79d4 name=FUN_004d79d4 size=16 ====

void FUN_004d79d4(void)

{
  qt_array_data_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d79e4 name=FUN_004d79e4 size=88 ====

void FUN_004d79e4(void)

{
  undefined8 in_stack_00000008;
  undefined8 in_stack_00000018;
  undefined8 in_stack_00000020;
  undefined8 in_stack_00000030;
  undefined8 in_stack_00000040;
  
  json_value_destruct();
  json_value_destruct(in_stack_00000030);
  FUN_00659276();
  qt_array_data_unref(in_stack_00000020);
  qt_array_data_unref(in_stack_00000018);
  qt_byte_array_unref();
  qt_array_data_unref(in_stack_00000040);
  json_value_destruct(in_stack_00000008);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d7a3c name=FUN_004d7a3c size=21 ====

void FUN_004d7a3c(void)

{
  undefined8 in_stack_00000008;
  undefined8 in_stack_00000018;
  undefined8 in_stack_00000040;
  
  json_value_destruct();
  json_value_destruct();
  qt_array_data_unref(in_stack_00000018);
  qt_byte_array_unref();
  qt_array_data_unref(in_stack_00000040);
  json_value_destruct(in_stack_00000008);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d7a51 name=FUN_004d7a51 size=21 ====

void FUN_004d7a51(void)

{
  undefined8 in_stack_00000008;
  undefined8 in_stack_00000040;
  
  json_value_destruct();
  json_value_destruct();
  qt_array_data_unref(in_stack_00000040);
  json_value_destruct(in_stack_00000008);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d7a66 name=FUN_004d7a66 size=21 ====

void FUN_004d7a66(void)

{
  undefined8 in_stack_00000008;
  undefined8 in_stack_00000040;
  
  json_value_destruct();
  json_value_destruct();
  qt_byte_array_unref();
  qt_array_data_unref(in_stack_00000040);
  json_value_destruct(in_stack_00000008);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d7a7b name=FUN_004d7a7b size=26 ====

void FUN_004d7a7b(void)

{
  undefined8 in_stack_00000008;
  undefined8 in_stack_00000018;
  undefined8 in_stack_00000020;
  undefined8 in_stack_00000030;
  undefined8 in_stack_00000040;
  
  json_value_destruct();
  json_value_destruct(in_stack_00000030);
  FUN_00659276();
  qt_array_data_unref(in_stack_00000020);
  qt_array_data_unref(in_stack_00000018);
  qt_byte_array_unref();
  qt_array_data_unref(in_stack_00000040);
  json_value_destruct(in_stack_00000008);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d7a95 name=FUN_004d7a95 size=24 ====

void FUN_004d7a95(void)

{
  undefined8 in_stack_00000008;
  undefined8 in_stack_00000040;
  
  json_value_destruct();
  json_value_destruct();
  qt_byte_array_unref();
  qt_array_data_unref(in_stack_00000040);
  json_value_destruct(in_stack_00000008);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d7aae name=FUN_004d7aae size=46 ====

void FUN_004d7aae(void)

{
  QVariant *unaff_RBP;
  undefined8 in_stack_00000010;
  undefined8 in_stack_00000018;
  undefined8 in_stack_00000028;
  
  QVariant::~QVariant(unaff_RBP);
  qt_array_data_unref(in_stack_00000018);
  qt_array_data_unref(in_stack_00000010);
  FUN_00659460(in_stack_00000028);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d7adc name=FUN_004d7adc size=10 ====

void FUN_004d7adc(void)

{
  QVariant *unaff_RBP;
  undefined8 in_stack_00000010;
  undefined8 in_stack_00000018;
  undefined8 in_stack_00000028;
  
  QVariant::~QVariant(unaff_RBP);
  qt_array_data_unref(in_stack_00000018);
  qt_array_data_unref(in_stack_00000010);
  FUN_00659460(in_stack_00000028);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d7ae6 name=FUN_004d7ae6 size=12 ====

void FUN_004d7ae6(void)

{
  QVariant *unaff_RBP;
  undefined8 in_stack_00000010;
  undefined8 in_stack_00000018;
  undefined8 in_stack_00000028;
  
  QVariant::~QVariant(unaff_RBP);
  qt_array_data_unref(in_stack_00000018);
  qt_array_data_unref(in_stack_00000010);
  FUN_00659460(in_stack_00000028);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d7af2 name=FUN_004d7af2 size=10 ====

void FUN_004d7af2(void)

{
  QVariant *unaff_RBP;
  undefined8 in_stack_00000028;
  
  QVariant::~QVariant(unaff_RBP);
  FUN_00659460(in_stack_00000028);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d7afc name=FUN_004d7afc size=10 ====

void FUN_004d7afc(void)

{
  QVariant *unaff_RBP;
  undefined8 in_stack_00000010;
  undefined8 in_stack_00000028;
  
  QVariant::~QVariant(unaff_RBP);
  qt_array_data_unref(in_stack_00000010);
  FUN_00659460(in_stack_00000028);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d7b06 name=FUN_004d7b06 size=29 ====

void FUN_004d7b06(void)

{
  QIcon *unaff_RBX;
  QVariant *unaff_RBP;
  undefined8 in_stack_00000010;
  undefined8 in_stack_00000018;
  undefined8 in_stack_00000028;
  
  QIcon::~QIcon(unaff_RBX);
  qt_array_data_unref();
  QVariant::~QVariant(unaff_RBP);
  qt_array_data_unref(in_stack_00000018);
  qt_array_data_unref(in_stack_00000010);
  FUN_00659460(in_stack_00000028);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d7b23 name=FUN_004d7b23 size=42 ====

void FUN_004d7b23(void)

{
  QVariant *unaff_RBP;
  undefined8 unaff_retaddr;
  undefined8 in_stack_00000008;
  undefined8 in_stack_00000010;
  undefined8 in_stack_00000018;
  QIcon *in_stack_00000020;
  undefined8 in_stack_00000028;
  
  QIcon::~QIcon(in_stack_00000020);
  qt_array_data_unref(unaff_retaddr);
  QVariant::~QVariant(unaff_RBP);
  qt_array_data_unref(in_stack_00000008);
  qt_array_data_unref(in_stack_00000018);
  qt_array_data_unref(in_stack_00000010);
  FUN_00659460(in_stack_00000028);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d7b4d name=FUN_004d7b4d size=24 ====

void FUN_004d7b4d(void)

{
  undefined8 in_stack_00000010;
  undefined8 in_stack_00000018;
  undefined8 in_stack_00000028;
  
  json_value_destruct();
  json_value_destruct();
  qt_array_data_unref(in_stack_00000018);
  qt_array_data_unref(in_stack_00000010);
  FUN_00659460(in_stack_00000028);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d7b66 name=FUN_004d7b66 size=16 ====

void FUN_004d7b66(void)

{
  QVariant *unaff_RBX;
  
  QVariant::~QVariant(unaff_RBX);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d7b76 name=FUN_004d7b76 size=16 ====

void FUN_004d7b76(void)

{
  __cxa_guard_abort();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d7b86 name=FUN_004d7b86 size=16 ====

void FUN_004d7b86(void)

{
  QVariant *unaff_RBX;
  
  QVariant::~QVariant(unaff_RBX);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d7b96 name=FUN_004d7b96 size=16 ====

void FUN_004d7b96(void)

{
  qt_array_data_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d7ba6 name=FUN_004d7ba6 size=35 ====

void FUN_004d7ba6(void)

{
  QIcon *unaff_RBX;
  
  QIcon::~QIcon(unaff_RBX);
  qt_array_data_unref();
  qt_array_data_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d7bc9 name=FUN_004d7bc9 size=21 ====

void FUN_004d7bc9(void)

{
  void *unaff_R13;
  
  operator_delete(unaff_R13,0x30);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d7bde name=FUN_004d7bde size=36 ====

void FUN_004d7bde(void)

{
  undefined8 in_stack_00000008;
  undefined8 in_stack_00000010;
  undefined8 in_stack_00000018;
  undefined8 in_stack_00000030;
  undefined1 *in_stack_00000060;
  
  json_value_destruct();
  if (in_stack_00000060 != &DAT_011c5338) {
    refcount_releaseDelete();
  }
  qt_array_data_unref(in_stack_00000008);
  qt_array_data_unref(in_stack_00000010);
  json_value_destruct();
  qt_array_data_unref(in_stack_00000030);
  json_value_destruct(in_stack_00000018);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d7c02 name=FUN_004d7c02 size=98 ====

void FUN_004d7c02(void)

{
  undefined8 in_stack_00000008;
  undefined8 in_stack_00000010;
  undefined8 in_stack_00000018;
  undefined8 in_stack_00000030;
  undefined1 *in_stack_00000060;
  
  json_value_destruct();
  if (in_stack_00000060 != &DAT_011c5338) {
    refcount_releaseDelete();
  }
  qt_array_data_unref();
  qt_array_data_unref(in_stack_00000008);
  qt_array_data_unref(in_stack_00000010);
  json_value_destruct();
  qt_array_data_unref(in_stack_00000030);
  json_value_destruct(in_stack_00000018);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d7c64 name=FUN_004d7c64 size=46 ====

void FUN_004d7c64(void)

{
  undefined8 in_stack_00000008;
  undefined8 in_stack_00000010;
  undefined8 in_stack_00000018;
  undefined8 in_stack_00000030;
  undefined1 *in_stack_00000060;
  
  json_value_destruct();
  if (in_stack_00000060 != &DAT_011c5338) {
    refcount_releaseDelete();
  }
  qt_array_data_unref();
  qt_array_data_unref(in_stack_00000008);
  qt_array_data_unref(in_stack_00000010);
  json_value_destruct();
  qt_array_data_unref(in_stack_00000030);
  json_value_destruct(in_stack_00000018);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d7c92 name=FUN_004d7c92 size=13 ====

void FUN_004d7c92(void)

{
  undefined8 in_stack_00000008;
  undefined8 in_stack_00000010;
  undefined8 in_stack_00000018;
  undefined8 in_stack_00000030;
  
  json_value_destruct();
  qt_array_data_unref(in_stack_00000008);
  qt_array_data_unref(in_stack_00000010);
  json_value_destruct();
  qt_array_data_unref(in_stack_00000030);
  json_value_destruct(in_stack_00000018);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d7c9f name=FUN_004d7c9f size=47 ====

void FUN_004d7c9f(void)

{
  undefined8 in_stack_00000008;
  undefined8 in_stack_00000010;
  undefined8 in_stack_00000018;
  undefined8 in_stack_00000030;
  undefined1 *in_stack_00000060;
  
  json_value_destruct();
  if (in_stack_00000060 != &DAT_011c5338) {
    refcount_releaseDelete();
  }
  qt_byte_array_unref();
  qt_array_data_unref(in_stack_00000008);
  qt_array_data_unref(in_stack_00000010);
  json_value_destruct();
  qt_array_data_unref(in_stack_00000030);
  json_value_destruct(in_stack_00000018);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d7cce name=FUN_004d7cce size=43 ====

void FUN_004d7cce(void)

{
  undefined8 in_stack_00000008;
  undefined8 in_stack_00000010;
  undefined8 in_stack_00000018;
  undefined8 in_stack_00000030;
  undefined1 *in_stack_00000060;
  
  json_value_destruct();
  if (in_stack_00000060 != &DAT_011c5338) {
    refcount_releaseDelete();
  }
  qt_array_data_unref(in_stack_00000008);
  qt_array_data_unref(in_stack_00000010);
  json_value_destruct();
  qt_array_data_unref(in_stack_00000030);
  json_value_destruct(in_stack_00000018);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d7cf9 name=FUN_004d7cf9 size=16 ====

void FUN_004d7cf9(void)

{
  FUN_00659276();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d7d09 name=FUN_004d7d09 size=26 ====

void FUN_004d7d09(void)

{
  FUN_00659276();
  FUN_00659276(&stack0x00000010);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d7d23 name=FUN_004d7d23 size=16 ====

void FUN_004d7d23(void)

{
  FUN_00659276();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d7d33 name=FUN_004d7d33 size=26 ====

void FUN_004d7d33(void)

{
  undefined8 in_stack_00000010;
  
  FUN_00659276(in_stack_00000010);
  FUN_00659276();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d7d4d name=FUN_004d7d4d size=18 ====

void FUN_004d7d4d(void)

{
  undefined8 in_stack_00000010;
  
  qt_array_data_unref(in_stack_00000010);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d7d60 name=FUN_004d7d60 size=16 ====

void FUN_004d7d60(void)

{
  qt_byte_array_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d7d70 name=FUN_004d7d70 size=64 ====

void FUN_004d7d70(void)

{
  undefined8 in_stack_00000018;
  undefined8 in_stack_00000028;
  undefined8 in_stack_00000030;
  QRegularExpressionMatch *in_stack_00000038;
  undefined1 *in_stack_00000130;
  
  if (in_stack_00000130 != &DAT_011c5338) {
    refcount_releaseDelete();
  }
  QRegularExpressionMatch::~QRegularExpressionMatch(in_stack_00000038);
  qt_array_data_unref();
  qt_array_data_unref();
  qt_array_data_unref();
  qt_shared_data_unref(in_stack_00000030);
  qt_array_data_unref(in_stack_00000028);
  qt_array_data_unref(in_stack_00000018);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d7da9 name=FUN_004d7da9 size=75 ====

void FUN_004d7da9(void)

{
  undefined8 in_stack_00000018;
  undefined8 in_stack_00000028;
  undefined8 in_stack_00000030;
  undefined8 in_stack_00000048;
  
  qt_array_data_unref();
  qt_array_data_unref();
  qt_array_data_unref();
  qt_array_data_unref(in_stack_00000048);
  qt_shared_data_unref(in_stack_00000030);
  qt_array_data_unref(in_stack_00000028);
  qt_array_data_unref(in_stack_00000018);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d7dfb name=FUN_004d7dfb size=19 ====

void FUN_004d7dfb(void)

{
  long unaff_RBX;
  undefined8 in_stack_00000018;
  undefined8 in_stack_00000028;
  undefined8 in_stack_00000030;
  undefined8 in_stack_00000048;
  
  QVariant::~QVariant((QVariant *)(unaff_RBX + 8));
  qt_array_data_unref();
  qt_array_data_unref();
  qt_array_data_unref();
  qt_array_data_unref(in_stack_00000048);
  qt_shared_data_unref(in_stack_00000030);
  qt_array_data_unref(in_stack_00000028);
  qt_array_data_unref(in_stack_00000018);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d7e0e name=FUN_004d7e0e size=12 ====

void FUN_004d7e0e(void)

{
  undefined8 in_stack_00000018;
  undefined8 in_stack_00000028;
  undefined8 in_stack_00000030;
  undefined8 in_stack_00000038;
  
  qmap_freetree_variant_nodes(in_stack_00000038);
  qt_shared_data_unref(in_stack_00000030);
  qt_array_data_unref(in_stack_00000028);
  qt_array_data_unref(in_stack_00000018);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d7e1a name=FUN_004d7e1a size=63 ====

void FUN_004d7e1a(void)

{
  QRegularExpressionMatch *unaff_R12;
  
  qt_shared_data_unref();
  QRegularExpressionMatch::~QRegularExpressionMatch(unaff_R12);
  qt_shared_data_unref(&stack0x000000a8);
  qt_array_data_unref(&stack0x000000a0);
  qt_array_data_unref(&stack0x00000098);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d7e59 name=FUN_004d7e59 size=64 ====

void FUN_004d7e59(void)

{
  undefined8 in_stack_00000018;
  undefined8 in_stack_00000028;
  undefined8 in_stack_00000030;
  QRegularExpressionMatch *in_stack_00000038;
  long in_stack_00000040;
  undefined8 in_stack_00000048;
  undefined8 in_stack_00000050;
  undefined8 in_stack_00000088;
  long in_stack_00000130;
  
  if (in_stack_00000130 + -0x18 != in_stack_00000040) {
    refcount_releaseDelete();
  }
  qmap_freetree_variant_nodes(in_stack_00000088);
  qt_array_data_unref(in_stack_00000048);
  qt_array_data_unref(in_stack_00000050);
  QRegularExpressionMatch::~QRegularExpressionMatch(in_stack_00000038);
  qt_array_data_unref();
  qt_array_data_unref();
  qt_array_data_unref();
  qt_shared_data_unref(in_stack_00000030);
  qt_array_data_unref(in_stack_00000028);
  qt_array_data_unref(in_stack_00000018);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d7e92 name=FUN_004d7e92 size=55 ====

void FUN_004d7e92(void)

{
  qt_array_data_unref();
  qt_shared_data_unref(&stack0x000000a8);
  qt_array_data_unref(&stack0x000000a0);
  qt_array_data_unref(&stack0x00000098);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d7ed0 name=FUN_004d7ed0 size=63 ====

void FUN_004d7ed0(void)

{
  QRegularExpressionMatch *unaff_R12;
  
  qt_array_data_unref();
  QRegularExpressionMatch::~QRegularExpressionMatch(unaff_R12);
  qt_shared_data_unref(&stack0x000000a8);
  qt_array_data_unref(&stack0x000000a0);
  qt_array_data_unref(&stack0x00000098);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d7f0f name=FUN_004d7f0f size=58 ====

void FUN_004d7f0f(void)

{
  QRegularExpressionMatch *unaff_RBX;
  QRegularExpressionMatchIterator *unaff_RBP;
  undefined8 in_stack_00000030;
  
  qt_array_data_unref();
  QRegularExpressionMatch::~QRegularExpressionMatch(unaff_RBX);
  QRegularExpressionMatchIterator::~QRegularExpressionMatchIterator(unaff_RBP);
  qt_shared_data_unref(in_stack_00000030);
  qt_array_data_unref(&stack0x000000a0);
  qt_array_data_unref(&stack0x00000098);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d7f49 name=FUN_004d7f49 size=15 ====

void FUN_004d7f49(void)

{
  undefined8 in_stack_00000018;
  undefined8 in_stack_00000028;
  undefined8 in_stack_00000030;
  QRegularExpressionMatch *in_stack_00000038;
  undefined8 in_stack_00000058;
  
  qt_array_data_unref(in_stack_00000058);
  QRegularExpressionMatch::~QRegularExpressionMatch(in_stack_00000038);
  qt_array_data_unref();
  qt_array_data_unref();
  qt_array_data_unref();
  qt_shared_data_unref(in_stack_00000030);
  qt_array_data_unref(in_stack_00000028);
  qt_array_data_unref(in_stack_00000018);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d7f58 name=FUN_004d7f58 size=27 ====

void FUN_004d7f58(void)

{
  undefined8 in_stack_00000018;
  undefined8 in_stack_00000028;
  undefined8 in_stack_00000030;
  QRegularExpressionMatch *in_stack_00000038;
  undefined8 in_stack_00000048;
  undefined8 in_stack_00000050;
  long in_stack_00000058;
  
  QVariant::~QVariant((QVariant *)(in_stack_00000058 + 8));
  qt_array_data_unref(in_stack_00000058);
  qt_array_data_unref(in_stack_00000048);
  qt_array_data_unref(in_stack_00000050);
  QRegularExpressionMatch::~QRegularExpressionMatch(in_stack_00000038);
  qt_array_data_unref();
  qt_array_data_unref();
  qt_array_data_unref();
  qt_shared_data_unref(in_stack_00000030);
  qt_array_data_unref(in_stack_00000028);
  qt_array_data_unref(in_stack_00000018);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d7f73 name=FUN_004d7f73 size=18 ====

void FUN_004d7f73(void)

{
  undefined8 in_stack_00000018;
  undefined8 in_stack_00000028;
  undefined8 in_stack_00000030;
  QRegularExpressionMatch *in_stack_00000038;
  undefined8 in_stack_00000048;
  undefined8 in_stack_00000050;
  undefined8 in_stack_00000058;
  undefined8 in_stack_00000088;
  
  qt_array_data_unref(in_stack_00000058);
  qmap_freetree_variant_nodes(in_stack_00000088);
  qt_array_data_unref(in_stack_00000048);
  qt_array_data_unref(in_stack_00000050);
  QRegularExpressionMatch::~QRegularExpressionMatch(in_stack_00000038);
  qt_array_data_unref();
  qt_array_data_unref();
  qt_array_data_unref();
  qt_shared_data_unref(in_stack_00000030);
  qt_array_data_unref(in_stack_00000028);
  qt_array_data_unref(in_stack_00000018);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d7f85 name=FUN_004d7f85 size=16 ====

void FUN_004d7f85(void)

{
  undefined8 in_stack_00000018;
  undefined8 in_stack_00000028;
  undefined8 in_stack_00000030;
  QRegularExpressionMatch *in_stack_00000038;
  undefined8 in_stack_00000048;
  undefined8 in_stack_00000050;
  undefined8 in_stack_00000058;
  
  qt_array_data_unref(in_stack_00000058);
  qt_array_data_unref(in_stack_00000048);
  qt_array_data_unref(in_stack_00000050);
  QRegularExpressionMatch::~QRegularExpressionMatch(in_stack_00000038);
  qt_array_data_unref();
  qt_array_data_unref();
  qt_array_data_unref();
  qt_shared_data_unref(in_stack_00000030);
  qt_array_data_unref(in_stack_00000028);
  qt_array_data_unref(in_stack_00000018);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d7fa0 name=FUN_004d7fa0 size=24 ====

void FUN_004d7fa0(void)

{
  QProcessEnvironment *unaff_R12;
  
  qt_array_data_unref();
  QProcessEnvironment::~QProcessEnvironment(unaff_R12);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d7fb8 name=FUN_004d7fb8 size=24 ====

void FUN_004d7fb8(void)

{
  qt_array_data_unref();
  qt_array_data_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d7fd0 name=FUN_004d7fd0 size=34 ====

void FUN_004d7fd0(void)

{
  qt_array_data_unref(&stack0x00000028);
  qt_array_data_unref();
  qt_array_data_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d7ff2 name=FUN_004d7ff2 size=26 ====

void FUN_004d7ff2(void)

{
  undefined8 in_stack_00000010;
  
  qt_array_data_unref();
  qt_shared_data_unref(in_stack_00000010);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d800c name=FUN_004d800c size=32 ====

void FUN_004d800c(void)

{
  QVariant *unaff_R12;
  
  qt_array_data_unref();
  QVariant::~QVariant(unaff_R12);
  qt_array_data_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d802c name=FUN_004d802c size=32 ====

void FUN_004d802c(void)

{
  QVariant *unaff_R12;
  
  qt_array_data_unref();
  QVariant::~QVariant(unaff_R12);
  qt_array_data_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d804c name=FUN_004d804c size=24 ====

void FUN_004d804c(void)

{
  qt_array_data_unref();
  qt_array_data_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d8064 name=FUN_004d8064 size=16 ====

void FUN_004d8064(void)

{
  qt_array_data_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d8074 name=FUN_004d8074 size=24 ====

void FUN_004d8074(void)

{
  qt_shared_data_unref();
  qt_shared_data_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d808c name=FUN_004d808c size=24 ====

void FUN_004d808c(void)

{
  qt_array_data_unref();
  qmap_freetree_variant_nodes();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d80a4 name=FUN_004d80a4 size=36 ====

void FUN_004d80a4(void)

{
  QVariant *unaff_R12;
  undefined8 in_stack_00000008;
  
  QVariant::~QVariant(unaff_R12);
  qt_shared_data_unref();
  qt_array_data_unref();
  qt_shared_data_unref(in_stack_00000008);
  qmap_freetree_variant_nodes();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d80d0 name=FUN_004d80d0 size=24 ====

void FUN_004d80d0(void)

{
  qt_array_data_unref();
  qt_byte_array_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d80e8 name=FUN_004d80e8 size=16 ====

void FUN_004d80e8(void)

{
  QDir *unaff_RBX;
  
  QDir::~QDir(unaff_RBX);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d80f8 name=FUN_004d80f8 size=16 ====

void FUN_004d80f8(void)

{
  qt_array_data_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d8108 name=FUN_004d8108 size=16 ====

void FUN_004d8108(void)

{
  qt_array_data_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d8118 name=FUN_004d8118 size=16 ====

void FUN_004d8118(void)

{
  qt_array_data_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d8128 name=FUN_004d8128 size=32 ====

void FUN_004d8128(void)

{
  QProcessEnvironment *unaff_R13;
  
  qt_array_data_unref();
  QProcessEnvironment::~QProcessEnvironment(unaff_R13);
  qmap_freetree_variant_nodes();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d8148 name=FUN_004d8148 size=20 ====

void FUN_004d8148(void)

{
  QProcessEnvironment *unaff_R13;
  undefined8 in_stack_00000030;
  
  qt_byte_array_unref(in_stack_00000030);
  __cxa_guard_abort();
  QProcessEnvironment::~QProcessEnvironment(unaff_R13);
  qmap_freetree_variant_nodes();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d815c name=FUN_004d815c size=15 ====

void FUN_004d815c(void)

{
  void *unaff_R12;
  QProcessEnvironment *unaff_R13;
  
  operator_delete(unaff_R12,0x10);
  QProcessEnvironment::~QProcessEnvironment(unaff_R13);
  qmap_freetree_variant_nodes();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d816b name=FUN_004d816b size=10 ====

void FUN_004d816b(void)

{
  QProcessEnvironment *unaff_R13;
  
  qt_array_data_unref();
  QProcessEnvironment::~QProcessEnvironment(unaff_R13);
  qmap_freetree_variant_nodes();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d8176 name=FUN_004d8176 size=15 ====

void FUN_004d8176(void)

{
  __cxa_begin_catch();
                    /* WARNING: Subroutine does not return */
                    /* try { // try from 004d8180 to 004d8184 has its CatchHandler @ 004d8185 */
  __cxa_rethrow();
}


// ==== entry=004d81b6 name=FUN_004d81b6 size=87 ====

void FUN_004d81b6(void)

{
  QTcpSocket *unaff_RBX;
  int *piVar1;
  
  qt_byte_array_unref();
  __cxa_guard_abort(&DAT_011c18b8);
  piVar1 = *(int **)(unaff_RBX + 0x38);
  if (*piVar1 != 0) {
    if (*piVar1 == -1) goto LAB_004d81d9;
    LOCK();
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if (*piVar1 != 0) goto LAB_004d81d9;
    piVar1 = *(int **)(unaff_RBX + 0x38);
  }
  qmap_freetree_free_variants(piVar1);
LAB_004d81d9:
  qt_array_data_unref(unaff_RBX + 0x28);
  qt_array_data_unref(unaff_RBX + 0x20);
  qt_shared_data_unref(unaff_RBX + 0x18);
  qt_array_data_unref(unaff_RBX + 0x10);
  QTcpSocket::~QTcpSocket(unaff_RBX);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d820d name=FUN_004d820d size=43 ====

void FUN_004d820d(void)

{
  QTcpSocket *unaff_RBX;
  int *piVar1;
  
  qt_byte_array_unref();
  __cxa_guard_abort(&DAT_011c18b0);
  piVar1 = *(int **)(unaff_RBX + 0x38);
  if (*piVar1 != 0) {
    if (*piVar1 == -1) goto LAB_004d81d9;
    LOCK();
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if (*piVar1 != 0) goto LAB_004d81d9;
    piVar1 = *(int **)(unaff_RBX + 0x38);
  }
  qmap_freetree_free_variants(piVar1);
LAB_004d81d9:
  qt_array_data_unref(unaff_RBX + 0x28);
  qt_array_data_unref(unaff_RBX + 0x20);
  qt_shared_data_unref(unaff_RBX + 0x18);
  qt_array_data_unref(unaff_RBX + 0x10);
  QTcpSocket::~QTcpSocket(unaff_RBX);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d8238 name=FUN_004d8238 size=40 ====

void FUN_004d8238(void)

{
  QTcpSocket *unaff_RBX;
  int *piVar1;
  QNetworkProxy *unaff_R12;
  
  QNetworkProxy::~QNetworkProxy(unaff_R12);
  qt_array_data_unref();
  qt_array_data_unref();
  qt_array_data_unref();
  piVar1 = *(int **)(unaff_RBX + 0x38);
  if (*piVar1 != 0) {
    if (*piVar1 == -1) goto LAB_004d81d9;
    LOCK();
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if (*piVar1 != 0) goto LAB_004d81d9;
    piVar1 = *(int **)(unaff_RBX + 0x38);
  }
  qmap_freetree_free_variants(piVar1);
LAB_004d81d9:
  qt_array_data_unref(unaff_RBX + 0x28);
  qt_array_data_unref(unaff_RBX + 0x20);
  qt_shared_data_unref(unaff_RBX + 0x18);
  qt_array_data_unref(unaff_RBX + 0x10);
  QTcpSocket::~QTcpSocket(unaff_RBX);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d8260 name=FUN_004d8260 size=16 ====

void FUN_004d8260(void)

{
  QTcpSocket *unaff_RBX;
  QVariant *unaff_RBP;
  int *piVar1;
  
  QVariant::~QVariant(unaff_RBP);
  piVar1 = *(int **)(unaff_RBX + 0x38);
  if (*piVar1 != 0) {
    if (*piVar1 == -1) goto LAB_004d81d9;
    LOCK();
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if (*piVar1 != 0) goto LAB_004d81d9;
    piVar1 = *(int **)(unaff_RBX + 0x38);
  }
  qmap_freetree_free_variants(piVar1);
LAB_004d81d9:
  qt_array_data_unref(unaff_RBX + 0x28);
  qt_array_data_unref(unaff_RBX + 0x20);
  qt_shared_data_unref(unaff_RBX + 0x18);
  qt_array_data_unref(unaff_RBX + 0x10);
  QTcpSocket::~QTcpSocket(unaff_RBX);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d8270 name=FUN_004d8270 size=24 ====

void FUN_004d8270(void)

{
  QVariant *unaff_R13;
  QVariant *unaff_R15;
  
  QVariant::~QVariant(unaff_R15);
  QVariant::~QVariant(unaff_R13);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d8290 name=FUN_004d8290 size=16 ====

void FUN_004d8290(void)

{
  QVariant *unaff_RBX;
  
  QVariant::~QVariant(unaff_RBX);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d82a0 name=FUN_004d82a0 size=16 ====

void FUN_004d82a0(void)

{
  QVariant *unaff_RBX;
  
  QVariant::~QVariant(unaff_RBX);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d82b0 name=FUN_004d82b0 size=16 ====

void FUN_004d82b0(void)

{
  QVariant *unaff_RBX;
  
  QVariant::~QVariant(unaff_RBX);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d82c0 name=FUN_004d82c0 size=16 ====

void FUN_004d82c0(void)

{
  QVariant *unaff_RBX;
  
  QVariant::~QVariant(unaff_RBX);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d82d0 name=FUN_004d82d0 size=16 ====

void FUN_004d82d0(void)

{
  QVariant *unaff_RBP;
  
  QVariant::~QVariant(unaff_RBP);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d82e0 name=FUN_004d82e0 size=24 ====

void FUN_004d82e0(void)

{
  QVariant *unaff_RBP;
  
  QVariant::~QVariant(unaff_RBP);
  qt_array_data_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d82f8 name=FUN_004d82f8 size=16 ====

void FUN_004d82f8(void)

{
  QVariant *unaff_RBX;
  
  QVariant::~QVariant(unaff_RBX);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d8308 name=FUN_004d8308 size=25 ====

void FUN_004d8308(void)

{
  QVariant *unaff_RBX;
  undefined8 unaff_retaddr;
  
  QVariant::~QVariant(unaff_RBX);
  qt_array_data_unref(unaff_retaddr);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d8321 name=FUN_004d8321 size=16 ====

void FUN_004d8321(void)

{
  QVariant *unaff_RBX;
  
  QVariant::~QVariant(unaff_RBX);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d8331 name=FUN_004d8331 size=25 ====

void FUN_004d8331(void)

{
  QVariant *unaff_RBX;
  undefined8 unaff_retaddr;
  
  QVariant::~QVariant(unaff_RBX);
  qt_array_data_unref(unaff_retaddr);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d834a name=FUN_004d834a size=16 ====

void FUN_004d834a(void)

{
  QVariant *unaff_RBX;
  
  QVariant::~QVariant(unaff_RBX);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d835a name=FUN_004d835a size=25 ====

void FUN_004d835a(void)

{
  QVariant *unaff_RBX;
  undefined8 unaff_retaddr;
  
  QVariant::~QVariant(unaff_RBX);
  qt_array_data_unref(unaff_retaddr);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d8373 name=FUN_004d8373 size=25 ====

void FUN_004d8373(void)

{
  QVariant *unaff_RBX;
  undefined8 unaff_retaddr;
  
  QVariant::~QVariant(unaff_RBX);
  qt_array_data_unref(unaff_retaddr);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d838c name=FUN_004d838c size=16 ====

void FUN_004d838c(void)

{
  QVariant *unaff_RBX;
  
  QVariant::~QVariant(unaff_RBX);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d839c name=FUN_004d839c size=25 ====

void FUN_004d839c(void)

{
  QVariant *unaff_RBX;
  undefined8 unaff_retaddr;
  
  QVariant::~QVariant(unaff_RBX);
  qt_array_data_unref(unaff_retaddr);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d83b5 name=FUN_004d83b5 size=16 ====

void FUN_004d83b5(void)

{
  QVariant *unaff_RBX;
  
  QVariant::~QVariant(unaff_RBX);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d83c5 name=FUN_004d83c5 size=25 ====

void FUN_004d83c5(void)

{
  QVariant *unaff_RBX;
  undefined8 unaff_retaddr;
  
  QVariant::~QVariant(unaff_RBX);
  qt_array_data_unref(unaff_retaddr);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d83de name=FUN_004d83de size=16 ====

void FUN_004d83de(void)

{
  QVariant *unaff_RBX;
  
  QVariant::~QVariant(unaff_RBX);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d83ee name=FUN_004d83ee size=16 ====

void FUN_004d83ee(void)

{
  QVariant *unaff_RBX;
  
  QVariant::~QVariant(unaff_RBX);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d83fe name=FUN_004d83fe size=26 ====

void FUN_004d83fe(void)

{
  QVariant *unaff_RBX;
  undefined8 in_stack_00000008;
  
  QVariant::~QVariant(unaff_RBX);
  qt_array_data_unref(in_stack_00000008);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d8418 name=FUN_004d8418 size=16 ====

void FUN_004d8418(void)

{
  QVariant *unaff_RBX;
  
  QVariant::~QVariant(unaff_RBX);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d8428 name=FUN_004d8428 size=26 ====

void FUN_004d8428(void)

{
  QVariant *unaff_RBX;
  undefined8 in_stack_00000008;
  
  QVariant::~QVariant(unaff_RBX);
  qt_array_data_unref(in_stack_00000008);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d8442 name=FUN_004d8442 size=16 ====

void FUN_004d8442(void)

{
  QVariant *unaff_RBP;
  
  QVariant::~QVariant(unaff_RBP);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d8452 name=FUN_004d8452 size=26 ====

void FUN_004d8452(void)

{
  QVariant *unaff_RBP;
  undefined8 in_stack_00000008;
  
  QVariant::~QVariant(unaff_RBP);
  qt_array_data_unref(in_stack_00000008);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d846c name=FUN_004d846c size=26 ====

void FUN_004d846c(void)

{
  QVariant *unaff_RBX;
  undefined8 in_stack_00000008;
  
  QVariant::~QVariant(unaff_RBX);
  qt_array_data_unref(in_stack_00000008);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d8486 name=FUN_004d8486 size=16 ====

void FUN_004d8486(void)

{
  QVariant *unaff_RBX;
  
  QVariant::~QVariant(unaff_RBX);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d8496 name=FUN_004d8496 size=26 ====

void FUN_004d8496(void)

{
  QVariant *unaff_RBX;
  undefined8 in_stack_00000008;
  
  QVariant::~QVariant(unaff_RBX);
  qt_array_data_unref(in_stack_00000008);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d84b0 name=FUN_004d84b0 size=16 ====

void FUN_004d84b0(void)

{
  QVariant *unaff_RBX;
  
  QVariant::~QVariant(unaff_RBX);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d84c0 name=FUN_004d84c0 size=26 ====

void FUN_004d84c0(void)

{
  QVariant *unaff_RBX;
  undefined8 in_stack_00000008;
  
  QVariant::~QVariant(unaff_RBX);
  qt_array_data_unref(in_stack_00000008);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d84da name=FUN_004d84da size=16 ====

void FUN_004d84da(void)

{
  QVariant *unaff_RBX;
  
  QVariant::~QVariant(unaff_RBX);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d84ea name=FUN_004d84ea size=26 ====

void FUN_004d84ea(void)

{
  QVariant *unaff_RBX;
  undefined8 in_stack_00000008;
  
  QVariant::~QVariant(unaff_RBX);
  qt_array_data_unref(in_stack_00000008);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d8504 name=FUN_004d8504 size=16 ====

void FUN_004d8504(void)

{
  QVariant *unaff_RBX;
  
  QVariant::~QVariant(unaff_RBX);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d8514 name=FUN_004d8514 size=26 ====

void FUN_004d8514(void)

{
  QVariant *unaff_RBX;
  undefined8 in_stack_00000008;
  
  QVariant::~QVariant(unaff_RBX);
  qt_array_data_unref(in_stack_00000008);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d852e name=FUN_004d852e size=26 ====

void FUN_004d852e(void)

{
  QVariant *unaff_RBX;
  undefined8 in_stack_00000008;
  
  QVariant::~QVariant(unaff_RBX);
  qt_array_data_unref(in_stack_00000008);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d8548 name=FUN_004d8548 size=16 ====

void FUN_004d8548(void)

{
  QVariant *unaff_RBX;
  
  QVariant::~QVariant(unaff_RBX);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d8558 name=FUN_004d8558 size=16 ====

void FUN_004d8558(void)

{
  QVariant *unaff_RBX;
  
  QVariant::~QVariant(unaff_RBX);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d8568 name=FUN_004d8568 size=16 ====

void FUN_004d8568(void)

{
  QVariant *unaff_RBX;
  
  QVariant::~QVariant(unaff_RBX);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d8578 name=FUN_004d8578 size=26 ====

void FUN_004d8578(void)

{
  QVariant *unaff_RBX;
  undefined8 in_stack_00000008;
  
  QVariant::~QVariant(unaff_RBX);
  qt_array_data_unref(in_stack_00000008);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d8592 name=FUN_004d8592 size=30 ====

void FUN_004d8592(void)

{
  QSortFilterProxyModel *unaff_RBX;
  
  if (*(void **)(unaff_RBX + 0x30) != (void *)0x0) {
    operator_delete(*(void **)(unaff_RBX + 0x30));
  }
  QSortFilterProxyModel::~QSortFilterProxyModel(unaff_RBX);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d85b0 name=FUN_004d85b0 size=16 ====

void FUN_004d85b0(void)

{
  QVariant *unaff_R14;
  
  QVariant::~QVariant(unaff_R14);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d85c0 name=FUN_004d85c0 size=18 ====

void FUN_004d85c0(void)

{
  undefined8 in_stack_00000008;
  
  qt_array_data_unref(in_stack_00000008);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d85d2 name=FUN_004d85d2 size=16 ====

void FUN_004d85d2(void)

{
  QVariant *unaff_R14;
  
  QVariant::~QVariant(unaff_R14);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d85e2 name=FUN_004d85e2 size=18 ====

void FUN_004d85e2(void)

{
  undefined8 in_stack_00000008;
  
  qt_array_data_unref(in_stack_00000008);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d85f4 name=FUN_004d85f4 size=18 ====

void FUN_004d85f4(void)

{
  undefined8 in_stack_00000008;
  
  qt_array_data_unref(in_stack_00000008);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d8606 name=FUN_004d8606 size=16 ====

void FUN_004d8606(void)

{
  QVariant *unaff_R15;
  
  QVariant::~QVariant(unaff_R15);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d8616 name=FUN_004d8616 size=18 ====

void FUN_004d8616(void)

{
  undefined8 in_stack_00000008;
  
  qt_array_data_unref(in_stack_00000008);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d8628 name=FUN_004d8628 size=16 ====

void FUN_004d8628(void)

{
  QVariant *unaff_R15;
  
  QVariant::~QVariant(unaff_R15);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d8638 name=FUN_004d8638 size=24 ====

void FUN_004d8638(void)

{
  QVariant *unaff_RBX;
  
  QVariant::~QVariant(unaff_RBX);
  qt_array_data_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d8650 name=FUN_004d8650 size=16 ====

void FUN_004d8650(void)

{
  QVariant *unaff_RBX;
  
  QVariant::~QVariant(unaff_RBX);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d8660 name=FUN_004d8660 size=16 ====

void FUN_004d8660(void)

{
  QVariant *unaff_RBP;
  
  QVariant::~QVariant(unaff_RBP);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d8670 name=FUN_004d8670 size=26 ====

void FUN_004d8670(void)

{
  QVariant *unaff_RBP;
  undefined8 in_stack_00000020;
  
  QVariant::~QVariant(unaff_RBP);
  qt_array_data_unref(in_stack_00000020);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d868a name=FUN_004d868a size=10 ====

void FUN_004d868a(void)

{
  QVariant *unaff_RBP;
  undefined8 in_stack_00000020;
  
  QVariant::~QVariant(unaff_RBP);
  qt_array_data_unref(in_stack_00000020);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d8694 name=FUN_004d8694 size=75 ====

/* WARNING: Removing unreachable block (ram,0x004d86fa) */

void FUN_004d8694(void)

{
  int *piVar1;
  int iVar2;
  nothrow_t *unaff_R12;
  void *unaff_R15;
  long in_stack_00000040;
  void *in_stack_00000048;
  void *in_stack_00000058;
  
  operator_delete((void *)0x0,unaff_R12);
  if (in_stack_00000048 != in_stack_00000058) {
    LOCK();
    piVar1 = (int *)(in_stack_00000040 + -8);
    iVar2 = *piVar1;
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if (iVar2 < 1) {
      operator_delete(in_stack_00000048);
    }
  }
  if (unaff_R15 != (void *)0x0) {
    operator_delete(unaff_R15);
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d86d4 name=FUN_004d86d4 size=38 ====

void FUN_004d86d4(void)

{
  QVariant *unaff_R13;
  void *unaff_R15;
  undefined8 unaff_retaddr;
  
  QVariant::~QVariant(unaff_R13);
  qt_array_data_unref(unaff_retaddr);
  if (unaff_R15 != (void *)0x0) {
    operator_delete(unaff_R15);
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d8705 name=FUN_004d8705 size=10 ====

/* WARNING: Removing unreachable block (ram,0x004d86fa) */

void FUN_004d8705(void)

{
  int *piVar1;
  int iVar2;
  QVariant *unaff_R12;
  void *unaff_R15;
  long in_stack_00000040;
  void *in_stack_00000048;
  void *in_stack_00000058;
  
  QVariant::~QVariant(unaff_R12);
  if (in_stack_00000048 != in_stack_00000058) {
    LOCK();
    piVar1 = (int *)(in_stack_00000040 + -8);
    iVar2 = *piVar1;
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if (iVar2 < 1) {
      operator_delete(in_stack_00000048);
    }
  }
  if (unaff_R15 != (void *)0x0) {
    operator_delete(unaff_R15);
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d870f name=FUN_004d870f size=10 ====

void FUN_004d870f(void)

{
  QVariant *unaff_R13;
  void *unaff_R15;
  undefined8 unaff_retaddr;
  
  QVariant::~QVariant(unaff_R13);
  qt_array_data_unref(unaff_retaddr);
  if (unaff_R15 != (void *)0x0) {
    operator_delete(unaff_R15);
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d8719 name=FUN_004d8719 size=13 ====

/* WARNING: Removing unreachable block (ram,0x004d86fa) */

void FUN_004d8719(void)

{
  int *piVar1;
  int iVar2;
  QVariant *unaff_R14;
  void *unaff_R15;
  long in_stack_00000040;
  void *in_stack_00000048;
  void *in_stack_00000058;
  
  QVariant::~QVariant(unaff_R14);
  if (in_stack_00000048 != in_stack_00000058) {
    LOCK();
    piVar1 = (int *)(in_stack_00000040 + -8);
    iVar2 = *piVar1;
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if (iVar2 < 1) {
      operator_delete(in_stack_00000048);
    }
  }
  if (unaff_R15 != (void *)0x0) {
    operator_delete(unaff_R15);
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d8726 name=FUN_004d8726 size=12 ====

void FUN_004d8726(void)

{
  QVariant *unaff_R13;
  void *unaff_R15;
  
  QVariant::~QVariant(unaff_R13);
  if (unaff_R15 != (void *)0x0) {
    operator_delete(unaff_R15);
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d8740 name=FUN_004d8740 size=60 ====

void FUN_004d8740(void)

{
  code *pcVar1;
  QObject *unaff_RBX;
  _func_void_Node_ptr *p_Var2;
  
  p_Var2 = *(_func_void_Node_ptr **)(unaff_RBX + 0x10);
  pcVar1 = p_Var2 + 0x10;
  if (*(int *)(p_Var2 + 0x10) != 0) {
    if (*(int *)(p_Var2 + 0x10) == -1) goto LAB_004d875b;
    LOCK();
    *(int *)pcVar1 = *(int *)pcVar1 + -1;
    UNLOCK();
    if (*(int *)pcVar1 != 0) goto LAB_004d875b;
    p_Var2 = *(_func_void_Node_ptr **)(unaff_RBX + 0x10);
  }
  QHashData::free_helper(p_Var2);
LAB_004d875b:
  QObject::~QObject(unaff_RBX);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d877c name=FUN_004d877c size=24 ====

void FUN_004d877c(void)

{
  QVariant *unaff_RBP;
  
  qt_byte_array_unref();
  QVariant::~QVariant(unaff_RBP);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d8794 name=FUN_004d8794 size=10 ====

void FUN_004d8794(void)

{
  QVariant *unaff_RBP;
  
  qt_byte_array_unref();
  QVariant::~QVariant(unaff_RBP);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d879e name=FUN_004d879e size=21 ====

void FUN_004d879e(void)

{
  QVariant *unaff_RBX;
  QVariant *unaff_RBP;
  
  qt_byte_array_unref();
  QVariant::~QVariant(unaff_RBX);
  QVariant::~QVariant(unaff_RBP);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d87b4 name=FUN_004d87b4 size=16 ====

void FUN_004d87b4(void)

{
  QVariant *unaff_RBX;
  
  QVariant::~QVariant(unaff_RBX);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d87c4 name=FUN_004d87c4 size=24 ====

void FUN_004d87c4(void)

{
  qt_array_data_unref();
  qt_byte_array_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d87dc name=FUN_004d87dc size=15 ====

void FUN_004d87dc(void)

{
  void *unaff_R13;
  
  operator_delete(unaff_R13,0x10);
  qt_byte_array_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d87eb name=FUN_004d87eb size=15 ====

void FUN_004d87eb(void)

{
  void *unaff_R13;
  
  operator_delete(unaff_R13,0x20);
  qt_byte_array_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d87fa name=FUN_004d87fa size=96 ====

void FUN_004d87fa(void)

{
  QVariant *unaff_RBX;
  QVariant *unaff_RBP;
  undefined8 in_stack_00000008;
  undefined8 in_stack_00000010;
  undefined8 in_stack_00000018;
  undefined8 in_stack_00000020;
  undefined8 in_stack_00000028;
  
  qt_array_data_unref();
  qt_byte_array_unref(in_stack_00000018);
  qt_array_data_unref(in_stack_00000010);
  qt_array_data_unref(in_stack_00000008);
  QVariant::~QVariant(unaff_RBX);
  qt_array_data_unref();
  QVariant::~QVariant(unaff_RBP);
  qt_array_data_unref(in_stack_00000020);
  qt_array_data_unref(in_stack_00000028);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d885a name=FUN_004d885a size=70 ====

void FUN_004d885a(void)

{
  QVariant *unaff_RBX;
  QVariant *unaff_RBP;
  undefined8 in_stack_00000008;
  undefined8 in_stack_00000010;
  undefined8 in_stack_00000018;
  undefined8 in_stack_00000020;
  undefined8 in_stack_00000028;
  
  qt_array_data_unref();
  qt_byte_array_unref(in_stack_00000018);
  qt_array_data_unref(in_stack_00000010);
  qt_array_data_unref(in_stack_00000008);
  QVariant::~QVariant(unaff_RBX);
  qt_array_data_unref();
  QVariant::~QVariant(unaff_RBP);
  qt_array_data_unref(in_stack_00000020);
  qt_array_data_unref(in_stack_00000028);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d88a0 name=FUN_004d88a0 size=29 ====

void FUN_004d88a0(void)

{
  QVariant *unaff_RBX;
  QVariant *unaff_RBP;
  undefined8 in_stack_00000020;
  undefined8 in_stack_00000028;
  
  QVariant::~QVariant(unaff_RBX);
  qt_array_data_unref();
  QVariant::~QVariant(unaff_RBP);
  qt_array_data_unref(in_stack_00000020);
  qt_array_data_unref(in_stack_00000028);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d88bd name=FUN_004d88bd size=32 ====

void FUN_004d88bd(void)

{
  QVariant *unaff_RBX;
  QVariant *unaff_RBP;
  undefined8 in_stack_00000028;
  
  QVariant::~QVariant(unaff_RBX);
  qt_array_data_unref();
  QVariant::~QVariant(unaff_RBP);
  qt_array_data_unref(in_stack_00000028);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d88dd name=FUN_004d88dd size=16 ====

void FUN_004d88dd(void)

{
  QVariant *unaff_RBX;
  undefined8 in_stack_00000020;
  undefined8 in_stack_00000028;
  
  QVariant::~QVariant(unaff_RBX);
  qt_array_data_unref(in_stack_00000020);
  qt_array_data_unref(in_stack_00000028);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d88ed name=FUN_004d88ed size=24 ====

void FUN_004d88ed(void)

{
  QIcon *unaff_RBX;
  undefined8 in_stack_00000020;
  undefined8 in_stack_00000028;
  
  QIcon::~QIcon(unaff_RBX);
  qt_array_data_unref();
  qt_array_data_unref(in_stack_00000020);
  qt_array_data_unref(in_stack_00000028);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d8905 name=FUN_004d8905 size=16 ====

void FUN_004d8905(void)

{
  QVariant *unaff_RBX;
  undefined8 in_stack_00000028;
  
  QVariant::~QVariant(unaff_RBX);
  qt_array_data_unref(in_stack_00000028);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d8915 name=FUN_004d8915 size=45 ====

void FUN_004d8915(void)

{
  QVariant *unaff_RBX;
  QVariant *unaff_RBP;
  undefined8 in_stack_00000018;
  
  qt_array_data_unref();
  QVariant::~QVariant(unaff_RBX);
  qt_array_data_unref(in_stack_00000018);
  QVariant::~QVariant(unaff_RBP);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d8942 name=FUN_004d8942 size=44 ====

void FUN_004d8942(void)

{
  QRegularExpression *unaff_RBX;
  undefined8 in_stack_00000008;
  undefined8 in_stack_00000010;
  undefined8 in_stack_00000020;
  undefined8 in_stack_00000028;
  
  QRegularExpression::~QRegularExpression(unaff_RBX);
  qt_array_data_unref();
  qt_array_data_unref(in_stack_00000010);
  qt_shared_data_unref(in_stack_00000008);
  qt_array_data_unref(in_stack_00000020);
  qt_array_data_unref(in_stack_00000028);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d896e name=FUN_004d896e size=13 ====

void FUN_004d896e(void)

{
  QVariant *unaff_RBX;
  undefined8 in_stack_00000008;
  undefined8 in_stack_00000010;
  undefined8 in_stack_00000020;
  undefined8 in_stack_00000028;
  
  QVariant::~QVariant(unaff_RBX);
  qt_array_data_unref(in_stack_00000010);
  qt_shared_data_unref(in_stack_00000008);
  qt_array_data_unref(in_stack_00000020);
  qt_array_data_unref(in_stack_00000028);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d897b name=FUN_004d897b size=29 ====

void FUN_004d897b(void)

{
  QRegularExpression *unaff_RBP;
  undefined8 in_stack_00000008;
  undefined8 in_stack_00000010;
  undefined8 in_stack_00000020;
  undefined8 in_stack_00000028;
  
  QRegularExpression::~QRegularExpression(unaff_RBP);
  qt_array_data_unref();
  qt_array_data_unref();
  qt_array_data_unref(in_stack_00000010);
  qt_shared_data_unref(in_stack_00000008);
  qt_array_data_unref(in_stack_00000020);
  qt_array_data_unref(in_stack_00000028);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d8998 name=FUN_004d8998 size=39 ====

void FUN_004d8998(void)

{
  QVariant *unaff_RBX;
  QVariant *unaff_RBP;
  undefined8 in_stack_00000008;
  undefined8 in_stack_00000018;
  undefined8 in_stack_00000020;
  undefined8 in_stack_00000028;
  
  qt_array_data_unref();
  QVariant::~QVariant(unaff_RBX);
  qt_array_data_unref(in_stack_00000018);
  QVariant::~QVariant(unaff_RBP);
  qt_shared_data_unref(in_stack_00000008);
  qt_array_data_unref(in_stack_00000020);
  qt_array_data_unref(in_stack_00000028);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d89bf name=FUN_004d89bf size=13 ====

void FUN_004d89bf(void)

{
  QVariant *unaff_RBX;
  undefined8 in_stack_00000008;
  undefined8 in_stack_00000020;
  undefined8 in_stack_00000028;
  
  QVariant::~QVariant(unaff_RBX);
  qt_shared_data_unref(in_stack_00000008);
  qt_array_data_unref(in_stack_00000020);
  qt_array_data_unref(in_stack_00000028);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d89cc name=FUN_004d89cc size=16 ====

void FUN_004d89cc(void)

{
  qt_array_data_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d89dc name=FUN_004d89dc size=16 ====

void FUN_004d89dc(void)

{
  QIcon *unaff_RBX;
  
  QIcon::~QIcon(unaff_RBX);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d89ec name=FUN_004d89ec size=16 ====

void FUN_004d89ec(void)

{
  QKeySequence *unaff_RBX;
  
  QKeySequence::~QKeySequence(unaff_RBX);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d89fc name=FUN_004d89fc size=29 ====

void FUN_004d89fc(void)

{
  void *unaff_RBP;
  
  operator_delete(unaff_RBP,0x10);
  qt_array_data_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d8a19 name=FUN_004d8a19 size=16 ====

void FUN_004d8a19(void)

{
  QVariant *unaff_RBX;
  
  QVariant::~QVariant(unaff_RBX);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d8a29 name=FUN_004d8a29 size=16 ====

void FUN_004d8a29(void)

{
  qt_byte_array_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d8a3a name=FUN_004d8a3a size=25 ====

void FUN_004d8a3a(void)

{
  undefined8 unaff_retaddr;
  
  qt_byte_array_unref();
  qmap_freetree_variant_nodes(unaff_retaddr);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d8a54 name=FUN_004d8a54 size=24 ====

void FUN_004d8a54(void)

{
  QJSValue *unaff_RBX;
  
  QJSValue::~QJSValue(unaff_RBX);
  qlist_release_data();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d8a6c name=FUN_004d8a6c size=10 ====

void FUN_004d8a6c(void)

{
  QJSValue *unaff_RBX;
  
  QJSValue::~QJSValue(unaff_RBX);
  qlist_release_data();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d8a76 name=FUN_004d8a76 size=24 ====

void FUN_004d8a76(void)

{
  QVariant *unaff_RBP;
  
  qt_byte_array_unref();
  QVariant::~QVariant(unaff_RBP);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d8a8e name=FUN_004d8a8e size=29 ====

void FUN_004d8a8e(void)

{
  QVariant *unaff_RBX;
  QVariant *unaff_RBP;
  QJSValue *unaff_R15;
  
  qt_byte_array_unref();
  QJSValue::~QJSValue(unaff_R15);
  QVariant::~QVariant(unaff_RBX);
  QVariant::~QVariant(unaff_RBP);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d8aab name=FUN_004d8aab size=13 ====

void FUN_004d8aab(void)

{
  QVariant *unaff_RBX;
  QVariant *unaff_RBP;
  QJSValue *unaff_R12;
  QJSValue *in_stack_00000008;
  
  QJSValue::~QJSValue(unaff_R12);
  QJSValue::~QJSValue(in_stack_00000008);
  QVariant::~QVariant(unaff_RBX);
  QVariant::~QVariant(unaff_RBP);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d8ab8 name=FUN_004d8ab8 size=20 ====

void FUN_004d8ab8(void)

{
  QVariant *unaff_RBX;
  QVariant *unaff_RBP;
  QJSValue *unaff_R15;
  QJSValue *in_stack_00000008;
  
  QJSValue::~QJSValue(unaff_R15);
  QJSValue::~QJSValue(in_stack_00000008);
  QVariant::~QVariant(unaff_RBX);
  QVariant::~QVariant(unaff_RBP);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d8acc name=FUN_004d8acc size=10 ====

void FUN_004d8acc(void)

{
  QVariant *unaff_RBP;
  
  qt_byte_array_unref();
  QVariant::~QVariant(unaff_RBP);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d8ad6 name=FUN_004d8ad6 size=13 ====

void FUN_004d8ad6(void)

{
  QVariant *unaff_RBX;
  QVariant *unaff_RBP;
  QJSValue *in_stack_00000008;
  
  qt_byte_array_unref();
  QJSValue::~QJSValue(in_stack_00000008);
  QVariant::~QVariant(unaff_RBX);
  QVariant::~QVariant(unaff_RBP);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d8ae3 name=FUN_004d8ae3 size=13 ====

void FUN_004d8ae3(void)

{
  QVariant *unaff_RBX;
  QVariant *unaff_RBP;
  
  qt_byte_array_unref();
  QVariant::~QVariant(unaff_RBX);
  QVariant::~QVariant(unaff_RBP);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d8af0 name=FUN_004d8af0 size=13 ====

void FUN_004d8af0(void)

{
  QVariant *unaff_RBX;
  QVariant *unaff_RBP;
  
  qt_array_data_unref();
  QVariant::~QVariant(unaff_RBX);
  QVariant::~QVariant(unaff_RBP);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d8afe name=FUN_004d8afe size=61 ====

void FUN_004d8afe(void)

{
  QJSValue *unaff_RBP;
  QVariant *unaff_R12;
  QVariant *unaff_retaddr;
  QJSValue *in_stack_00000020;
  QVariant *in_stack_00000028;
  
  qt_byte_array_unref();
  QJSValue::~QJSValue(in_stack_00000020);
  QVariant::~QVariant(unaff_R12);
  QVariant::~QVariant(in_stack_00000028);
  QVariant::~QVariant(unaff_retaddr);
  QJSValue::~QJSValue(unaff_RBP);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d8b3b name=FUN_004d8b3b size=10 ====

void FUN_004d8b3b(void)

{
  QJSValue *unaff_RBP;
  QVariant *unaff_retaddr;
  QVariant *in_stack_00000028;
  
  qt_byte_array_unref();
  QVariant::~QVariant(in_stack_00000028);
  QVariant::~QVariant(unaff_retaddr);
  QJSValue::~QJSValue(unaff_RBP);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d8b45 name=FUN_004d8b45 size=33 ====

void FUN_004d8b45(void)

{
  QJSValue *unaff_RBP;
  QVariant *unaff_R12;
  QJSValue *unaff_R13;
  QVariant *unaff_retaddr;
  QVariant *in_stack_00000028;
  
  QJSValue::~QJSValue(unaff_R13);
  qt_array_data_unref(&stack0x000000b0);
  QVariant::~QVariant(unaff_R12);
  QVariant::~QVariant(in_stack_00000028);
  QVariant::~QVariant(unaff_retaddr);
  QJSValue::~QJSValue(unaff_RBP);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d8b66 name=FUN_004d8b66 size=12 ====

void FUN_004d8b66(void)

{
  QJSValue *unaff_RBP;
  QVariant *unaff_R12;
  QVariant *unaff_retaddr;
  QVariant *in_stack_00000028;
  
  qt_array_data_unref();
  QVariant::~QVariant(unaff_R12);
  QVariant::~QVariant(in_stack_00000028);
  QVariant::~QVariant(unaff_retaddr);
  QJSValue::~QJSValue(unaff_RBP);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d8b72 name=FUN_004d8b72 size=25 ====

void FUN_004d8b72(void)

{
  QJSValue *unaff_RBP;
  QVariant *unaff_R12;
  QVariant *unaff_retaddr;
  QJSValue *in_stack_00000020;
  QVariant *in_stack_00000028;
  
  QJSValue::~QJSValue(in_stack_00000020);
  qt_array_data_unref(&stack0x000000b0);
  QVariant::~QVariant(unaff_R12);
  QVariant::~QVariant(in_stack_00000028);
  QVariant::~QVariant(unaff_retaddr);
  QJSValue::~QJSValue(unaff_RBP);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d8b8b name=FUN_004d8b8b size=23 ====

void FUN_004d8b8b(void)

{
  QJSValue *unaff_RBP;
  QVariant *unaff_R12;
  QVariant *unaff_retaddr;
  QVariant *in_stack_00000028;
  
  qt_array_data_unref();
  qt_array_data_unref(&stack0x000000b0);
  QVariant::~QVariant(unaff_R12);
  QVariant::~QVariant(in_stack_00000028);
  QVariant::~QVariant(unaff_retaddr);
  QJSValue::~QJSValue(unaff_RBP);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d8ba2 name=FUN_004d8ba2 size=13 ====

void FUN_004d8ba2(void)

{
  QJSValue *unaff_RBP;
  QVariant *unaff_retaddr;
  QVariant *in_stack_00000028;
  
  qt_byte_array_unref();
  QVariant::~QVariant(in_stack_00000028);
  QVariant::~QVariant(unaff_retaddr);
  QJSValue::~QJSValue(unaff_RBP);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d8baf name=FUN_004d8baf size=23 ====

void FUN_004d8baf(void)

{
  QJSValue *unaff_RBP;
  QVariant *unaff_R12;
  QVariant *unaff_retaddr;
  QVariant *in_stack_00000028;
  
  qt_byte_array_unref();
  qt_array_data_unref(&stack0x000000b0);
  QVariant::~QVariant(unaff_R12);
  QVariant::~QVariant(in_stack_00000028);
  QVariant::~QVariant(unaff_retaddr);
  QJSValue::~QJSValue(unaff_RBP);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d8bc6 name=FUN_004d8bc6 size=13 ====

void FUN_004d8bc6(void)

{
  QJSValue *unaff_RBP;
  QVariant *unaff_R12;
  QVariant *unaff_retaddr;
  QVariant *in_stack_00000028;
  
  qt_byte_array_unref();
  QVariant::~QVariant(unaff_R12);
  QVariant::~QVariant(in_stack_00000028);
  QVariant::~QVariant(unaff_retaddr);
  QJSValue::~QJSValue(unaff_RBP);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d8bd4 name=FUN_004d8bd4 size=16 ====

void FUN_004d8bd4(void)

{
  QJSValue *unaff_RBX;
  
  QJSValue::~QJSValue(unaff_RBX);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d8be4 name=FUN_004d8be4 size=105 ====

void FUN_004d8be4(void)

{
  int *piVar1;
  undefined8 in_stack_00000030;
  undefined8 in_stack_00000040;
  undefined8 *in_stack_00000050;
  QJSValue *in_stack_00000058;
  undefined8 in_stack_00000088;
  
  qt_array_data_unref();
  qt_array_data_unref(in_stack_00000040);
  qt_array_data_unref();
  qt_array_data_unref(in_stack_00000030);
  qt_byte_array_unref();
  qt_shared_data_unref(in_stack_00000088);
  QJSValue::~QJSValue(in_stack_00000058);
  piVar1 = (int *)*in_stack_00000050;
  if (*piVar1 != 0) {
    if (*piVar1 == -1) goto LAB_004d8c45;
    LOCK();
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if (*piVar1 != 0) goto LAB_004d8c45;
  }
  QListData::dispose((Data *)*in_stack_00000050);
LAB_004d8c45:
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d8c4d name=FUN_004d8c4d size=10 ====

void FUN_004d8c4d(void)

{
  int *piVar1;
  undefined8 *in_stack_00000050;
  QJSValue *in_stack_00000058;
  
  qt_byte_array_unref();
  QJSValue::~QJSValue(in_stack_00000058);
  piVar1 = (int *)*in_stack_00000050;
  if (*piVar1 != 0) {
    if (*piVar1 == -1) goto LAB_004d8c45;
    LOCK();
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if (*piVar1 != 0) goto LAB_004d8c45;
  }
  QListData::dispose((Data *)*in_stack_00000050);
LAB_004d8c45:
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d8c57 name=FUN_004d8c57 size=43 ====

void FUN_004d8c57(void)

{
  int *piVar1;
  void *unaff_RBP;
  undefined8 in_stack_00000048;
  undefined8 *in_stack_00000050;
  QJSValue *in_stack_00000058;
  undefined8 in_stack_00000088;
  
  operator_delete(unaff_RBP,0x10);
  qt_array_data_unref(in_stack_00000048);
  qt_shared_data_unref(in_stack_00000088);
  QJSValue::~QJSValue(in_stack_00000058);
  piVar1 = (int *)*in_stack_00000050;
  if (*piVar1 != 0) {
    if (*piVar1 == -1) goto LAB_004d8c45;
    LOCK();
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if (*piVar1 != 0) goto LAB_004d8c45;
  }
  QListData::dispose((Data *)*in_stack_00000050);
LAB_004d8c45:
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d8c82 name=FUN_004d8c82 size=59 ====

void FUN_004d8c82(void)

{
  int *piVar1;
  undefined8 in_stack_00000028;
  undefined8 in_stack_00000040;
  undefined8 in_stack_00000048;
  undefined8 *in_stack_00000050;
  QJSValue *in_stack_00000058;
  undefined8 in_stack_00000088;
  undefined8 in_stack_00000090;
  
  json_value_destruct();
  json_value_destruct(in_stack_00000040);
  qt_array_data_unref(&stack0x000000d8);
  json_value_destruct(in_stack_00000028);
  qt_array_data_unref(in_stack_00000090);
  qt_array_data_unref(in_stack_00000048);
  qt_shared_data_unref(in_stack_00000088);
  QJSValue::~QJSValue(in_stack_00000058);
  piVar1 = (int *)*in_stack_00000050;
  if (*piVar1 != 0) {
    if (*piVar1 == -1) goto LAB_004d8c45;
    LOCK();
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if (*piVar1 != 0) goto LAB_004d8c45;
  }
  QListData::dispose((Data *)*in_stack_00000050);
LAB_004d8c45:
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d8cbd name=FUN_004d8cbd size=10 ====

void FUN_004d8cbd(void)

{
  int *piVar1;
  undefined8 in_stack_00000048;
  undefined8 *in_stack_00000050;
  QJSValue *in_stack_00000058;
  undefined8 in_stack_00000088;
  undefined8 in_stack_00000090;
  
  qt_byte_array_unref();
  qt_array_data_unref(in_stack_00000090);
  qt_array_data_unref(in_stack_00000048);
  qt_shared_data_unref(in_stack_00000088);
  QJSValue::~QJSValue(in_stack_00000058);
  piVar1 = (int *)*in_stack_00000050;
  if (*piVar1 != 0) {
    if (*piVar1 == -1) goto LAB_004d8c45;
    LOCK();
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if (*piVar1 != 0) goto LAB_004d8c45;
  }
  QListData::dispose((Data *)*in_stack_00000050);
LAB_004d8c45:
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d8cc7 name=FUN_004d8cc7 size=36 ====

void FUN_004d8cc7(void)

{
  int *piVar1;
  undefined8 in_stack_00000028;
  undefined8 in_stack_00000040;
  undefined8 in_stack_00000048;
  undefined8 *in_stack_00000050;
  QJSValue *in_stack_00000058;
  undefined8 in_stack_00000088;
  undefined8 in_stack_00000090;
  
  json_value_destruct();
  json_value_destruct(in_stack_00000040);
  qt_array_data_unref(&stack0x000000e0);
  qt_array_data_unref(&stack0x000000d8);
  json_value_destruct(in_stack_00000028);
  qt_array_data_unref(in_stack_00000090);
  qt_array_data_unref(in_stack_00000048);
  qt_shared_data_unref(in_stack_00000088);
  QJSValue::~QJSValue(in_stack_00000058);
  piVar1 = (int *)*in_stack_00000050;
  if (*piVar1 != 0) {
    if (*piVar1 == -1) goto LAB_004d8c45;
    LOCK();
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if (*piVar1 != 0) goto LAB_004d8c45;
  }
  QListData::dispose((Data *)*in_stack_00000050);
LAB_004d8c45:
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d8ceb name=FUN_004d8ceb size=16 ====

void FUN_004d8ceb(void)

{
  int *piVar1;
  undefined8 *in_stack_00000050;
  
  qt_array_data_unref();
  piVar1 = (int *)*in_stack_00000050;
  if (*piVar1 != 0) {
    if (*piVar1 == -1) goto LAB_004d8c45;
    LOCK();
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if (*piVar1 != 0) goto LAB_004d8c45;
  }
  QListData::dispose((Data *)*in_stack_00000050);
LAB_004d8c45:
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d8cfb name=FUN_004d8cfb size=16 ====

void FUN_004d8cfb(void)

{
  int *piVar1;
  undefined8 *in_stack_00000050;
  QJSValue *in_stack_00000058;
  
  qlist_release_data();
  QJSValue::~QJSValue(in_stack_00000058);
  piVar1 = (int *)*in_stack_00000050;
  if (*piVar1 != 0) {
    if (*piVar1 == -1) goto LAB_004d8c45;
    LOCK();
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if (*piVar1 != 0) goto LAB_004d8c45;
  }
  QListData::dispose((Data *)*in_stack_00000050);
LAB_004d8c45:
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d8d0b name=FUN_004d8d0b size=60 ====

void FUN_004d8d0b(void)

{
  int *piVar1;
  QIcon *unaff_RBX;
  undefined8 in_stack_00000028;
  undefined8 in_stack_00000040;
  undefined8 in_stack_00000048;
  undefined8 *in_stack_00000050;
  QJSValue *in_stack_00000058;
  undefined8 in_stack_00000088;
  undefined8 in_stack_00000090;
  char cStack00000000000000a7;
  
  cStack00000000000000a7 = '\x01';
  QIcon::~QIcon(unaff_RBX);
  if (cStack00000000000000a7 != '\0') {
    qt_array_data_unref(in_stack_00000040);
  }
  qt_array_data_unref();
  qt_array_data_unref(&stack0x000000e0);
  qt_array_data_unref(&stack0x000000d8);
  json_value_destruct(in_stack_00000028);
  qt_array_data_unref(in_stack_00000090);
  qt_array_data_unref(in_stack_00000048);
  qt_shared_data_unref(in_stack_00000088);
  QJSValue::~QJSValue(in_stack_00000058);
  piVar1 = (int *)*in_stack_00000050;
  if (*piVar1 != 0) {
    if (*piVar1 == -1) goto LAB_004d8c45;
    LOCK();
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if (*piVar1 != 0) goto LAB_004d8c45;
  }
  QListData::dispose((Data *)*in_stack_00000050);
LAB_004d8c45:
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d8d47 name=FUN_004d8d47 size=29 ====

void FUN_004d8d47(void)

{
  int *piVar1;
  QVariant *unaff_RBX;
  undefined8 in_stack_00000028;
  undefined8 in_stack_00000048;
  undefined8 *in_stack_00000050;
  QJSValue *in_stack_00000058;
  undefined8 in_stack_00000088;
  undefined8 in_stack_00000090;
  
  QVariant::~QVariant(unaff_RBX);
  qt_array_data_unref(&stack0x000000e8);
  qt_array_data_unref(&stack0x000000e0);
  qt_array_data_unref(&stack0x000000d8);
  json_value_destruct(in_stack_00000028);
  qt_array_data_unref(in_stack_00000090);
  qt_array_data_unref(in_stack_00000048);
  qt_shared_data_unref(in_stack_00000088);
  QJSValue::~QJSValue(in_stack_00000058);
  piVar1 = (int *)*in_stack_00000050;
  if (*piVar1 != 0) {
    if (*piVar1 == -1) goto LAB_004d8c45;
    LOCK();
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if (*piVar1 != 0) goto LAB_004d8c45;
  }
  QListData::dispose((Data *)*in_stack_00000050);
LAB_004d8c45:
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d8d64 name=FUN_004d8d64 size=10 ====

void FUN_004d8d64(void)

{
  int *piVar1;
  undefined8 in_stack_00000028;
  undefined8 in_stack_00000048;
  undefined8 *in_stack_00000050;
  QJSValue *in_stack_00000058;
  undefined8 in_stack_00000088;
  undefined8 in_stack_00000090;
  
  qt_array_data_unref(&stack0x000000e8);
  qt_array_data_unref(&stack0x000000e0);
  qt_array_data_unref(&stack0x000000d8);
  json_value_destruct(in_stack_00000028);
  qt_array_data_unref(in_stack_00000090);
  qt_array_data_unref(in_stack_00000048);
  qt_shared_data_unref(in_stack_00000088);
  QJSValue::~QJSValue(in_stack_00000058);
  piVar1 = (int *)*in_stack_00000050;
  if (*piVar1 != 0) {
    if (*piVar1 == -1) goto LAB_004d8c45;
    LOCK();
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if (*piVar1 != 0) goto LAB_004d8c45;
  }
  QListData::dispose((Data *)*in_stack_00000050);
LAB_004d8c45:
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d8d6e name=FUN_004d8d6e size=32 ====

void FUN_004d8d6e(void)

{
  int *piVar1;
  QVariant *unaff_RBX;
  undefined8 *in_stack_00000050;
  QJSValue *in_stack_00000058;
  
  QVariant::~QVariant(unaff_RBX);
  qt_shared_data_unref(&stack0x000000b8);
  QJSValue::~QJSValue(in_stack_00000058);
  piVar1 = (int *)*in_stack_00000050;
  if (*piVar1 != 0) {
    if (*piVar1 == -1) goto LAB_004d8c45;
    LOCK();
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if (*piVar1 != 0) goto LAB_004d8c45;
  }
  QListData::dispose((Data *)*in_stack_00000050);
LAB_004d8c45:
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d8d8e name=FUN_004d8d8e size=16 ====

void FUN_004d8d8e(void)

{
  int *piVar1;
  QVariant *unaff_RBX;
  undefined8 *in_stack_00000050;
  QJSValue *in_stack_00000058;
  
  QVariant::~QVariant(unaff_RBX);
  QJSValue::~QJSValue(in_stack_00000058);
  piVar1 = (int *)*in_stack_00000050;
  if (*piVar1 != 0) {
    if (*piVar1 == -1) goto LAB_004d8c45;
    LOCK();
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if (*piVar1 != 0) goto LAB_004d8c45;
  }
  QListData::dispose((Data *)*in_stack_00000050);
LAB_004d8c45:
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d8d9e name=FUN_004d8d9e size=28 ====

void FUN_004d8d9e(void)

{
  int *piVar1;
  undefined8 in_stack_00000028;
  QVariant *in_stack_00000030;
  undefined8 in_stack_00000048;
  undefined8 *in_stack_00000050;
  QJSValue *in_stack_00000058;
  undefined8 in_stack_00000088;
  undefined8 in_stack_00000090;
  
  QVariant::~QVariant(in_stack_00000030);
  qt_array_data_unref(&stack0x000000e8);
  qt_array_data_unref(&stack0x000000e0);
  qt_array_data_unref(&stack0x000000d8);
  json_value_destruct(in_stack_00000028);
  qt_array_data_unref(in_stack_00000090);
  qt_array_data_unref(in_stack_00000048);
  qt_shared_data_unref(in_stack_00000088);
  QJSValue::~QJSValue(in_stack_00000058);
  piVar1 = (int *)*in_stack_00000050;
  if (*piVar1 != 0) {
    if (*piVar1 == -1) goto LAB_004d8c45;
    LOCK();
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if (*piVar1 != 0) goto LAB_004d8c45;
  }
  QListData::dispose((Data *)*in_stack_00000050);
LAB_004d8c45:
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d8dba name=FUN_004d8dba size=23 ====

void FUN_004d8dba(void)

{
  int *piVar1;
  undefined8 in_stack_00000028;
  undefined8 in_stack_00000040;
  undefined8 in_stack_00000048;
  undefined8 *in_stack_00000050;
  QJSValue *in_stack_00000058;
  undefined8 in_stack_00000088;
  undefined8 in_stack_00000090;
  
  json_value_destruct();
  json_value_destruct(in_stack_00000040);
  json_value_destruct(in_stack_00000028);
  qt_array_data_unref(in_stack_00000090);
  qt_array_data_unref(in_stack_00000048);
  qt_shared_data_unref(in_stack_00000088);
  QJSValue::~QJSValue(in_stack_00000058);
  piVar1 = (int *)*in_stack_00000050;
  if (*piVar1 != 0) {
    if (*piVar1 == -1) goto LAB_004d8c45;
    LOCK();
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if (*piVar1 != 0) goto LAB_004d8c45;
  }
  QListData::dispose((Data *)*in_stack_00000050);
LAB_004d8c45:
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d8dd1 name=FUN_004d8dd1 size=34 ====

void FUN_004d8dd1(void)

{
  int *piVar1;
  void *unaff_RBP;
  undefined8 in_stack_00000028;
  undefined8 in_stack_00000048;
  undefined8 *in_stack_00000050;
  QJSValue *in_stack_00000058;
  undefined8 in_stack_00000088;
  undefined8 in_stack_00000090;
  
  operator_delete(unaff_RBP,0x10);
  qt_array_data_unref(&stack0x000000e8);
  qt_array_data_unref(&stack0x000000e0);
  qt_array_data_unref(&stack0x000000d8);
  json_value_destruct(in_stack_00000028);
  qt_array_data_unref(in_stack_00000090);
  qt_array_data_unref(in_stack_00000048);
  qt_shared_data_unref(in_stack_00000088);
  QJSValue::~QJSValue(in_stack_00000058);
  piVar1 = (int *)*in_stack_00000050;
  if (*piVar1 != 0) {
    if (*piVar1 == -1) goto LAB_004d8c45;
    LOCK();
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if (*piVar1 != 0) goto LAB_004d8c45;
  }
  QListData::dispose((Data *)*in_stack_00000050);
LAB_004d8c45:
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d8df3 name=FUN_004d8df3 size=29 ====

void FUN_004d8df3(void)

{
  int *piVar1;
  undefined8 in_stack_00000028;
  undefined8 in_stack_00000048;
  undefined8 *in_stack_00000050;
  QJSValue *in_stack_00000058;
  undefined8 in_stack_00000088;
  undefined8 in_stack_00000090;
  
  qt_byte_array_unref();
  qt_array_data_unref(&stack0x000000e8);
  qt_array_data_unref(&stack0x000000e0);
  qt_array_data_unref(&stack0x000000d8);
  json_value_destruct(in_stack_00000028);
  qt_array_data_unref(in_stack_00000090);
  qt_array_data_unref(in_stack_00000048);
  qt_shared_data_unref(in_stack_00000088);
  QJSValue::~QJSValue(in_stack_00000058);
  piVar1 = (int *)*in_stack_00000050;
  if (*piVar1 != 0) {
    if (*piVar1 == -1) goto LAB_004d8c45;
    LOCK();
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if (*piVar1 != 0) goto LAB_004d8c45;
  }
  QListData::dispose((Data *)*in_stack_00000050);
LAB_004d8c45:
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d8e10 name=FUN_004d8e10 size=31 ====

void FUN_004d8e10(void)

{
  qt_byte_array_unref();
  __cxa_guard_abort(&DAT_011c1930);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d8e30 name=FUN_004d8e30 size=31 ====

void FUN_004d8e30(void)

{
  qt_byte_array_unref();
  __cxa_guard_abort(&DAT_011c1920);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d8e50 name=FUN_004d8e50 size=31 ====

void FUN_004d8e50(void)

{
  qt_byte_array_unref();
  __cxa_guard_abort(&DAT_011c1910);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d8e70 name=FUN_004d8e70 size=31 ====

void FUN_004d8e70(void)

{
  qt_byte_array_unref();
  __cxa_guard_abort(&DAT_011c1900);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d8e90 name=FUN_004d8e90 size=31 ====

void FUN_004d8e90(void)

{
  qt_byte_array_unref();
  __cxa_guard_abort(&DAT_011c18f0);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d8eb0 name=FUN_004d8eb0 size=31 ====

void FUN_004d8eb0(void)

{
  qt_byte_array_unref();
  __cxa_guard_abort(&DAT_011c18e0);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d8ed0 name=FUN_004d8ed0 size=16 ====

void FUN_004d8ed0(void)

{
  qt_byte_array_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d8ee0 name=FUN_004d8ee0 size=16 ====

void FUN_004d8ee0(void)

{
  qt_byte_array_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d8ef0 name=FUN_004d8ef0 size=40 ====

void FUN_004d8ef0(void)

{
  qt_byte_array_unref();
  FUN_00a793f0();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d8f18 name=FUN_004d8f18 size=24 ====

void FUN_004d8f18(void)

{
  qt_array_data_unref();
  qt_array_data_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d8f30 name=FUN_004d8f30 size=98 ====

void FUN_004d8f30(void)

{
  undefined1 *puVar1;
  undefined1 *unaff_R13;
  undefined8 in_stack_00000018;
  undefined8 in_stack_00000020;
  undefined8 in_stack_00000028;
  undefined8 in_stack_00000030;
  undefined8 in_stack_00000038;
  undefined1 *puVar2;
  
  puVar2 = &stack0x000000c0;
  do {
    puVar1 = puVar2 + -0x10;
    qt_byte_array_unref(puVar2 + -8);
    qt_byte_array_unref(puVar1);
    puVar2 = puVar1;
  } while (puVar1 != unaff_R13);
  qt_byte_array_unref(in_stack_00000038);
  qt_byte_array_unref(in_stack_00000030);
  qt_byte_array_unref(in_stack_00000028);
  qt_byte_array_unref(in_stack_00000020);
  qt_byte_array_unref(in_stack_00000018);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d8f92 name=FUN_004d8f92 size=58 ====

void FUN_004d8f92(void)

{
  code *pcVar1;
  _func_void_Node_ptr *in_stack_00000040;
  
  pcVar1 = in_stack_00000040 + 0x10;
  if (*(int *)(in_stack_00000040 + 0x10) != 0) {
    if (*(int *)(in_stack_00000040 + 0x10) == -1) goto LAB_004d8fb2;
    LOCK();
    *(int *)pcVar1 = *(int *)pcVar1 + -1;
    UNLOCK();
    if (*(int *)pcVar1 != 0) goto LAB_004d8fb2;
  }
  QHashData::free_helper(in_stack_00000040);
LAB_004d8fb2:
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d8fcc name=FUN_004d8fcc size=16 ====

void FUN_004d8fcc(void)

{
  qt_byte_array_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d8fdc name=FUN_004d8fdc size=16 ====

void FUN_004d8fdc(void)

{
  qt_byte_array_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d8fec name=FUN_004d8fec size=25 ====

void FUN_004d8fec(void)

{
  void *unaff_R13;
  undefined8 unaff_retaddr;
  
  qatomic_unref_call_deleter2(unaff_retaddr);
  operator_delete(unaff_R13);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d9006 name=FUN_004d9006 size=102 ====

void FUN_004d9006(void)

{
  undefined8 in_stack_00000018;
  QMapNodeBase *in_stack_00000038;
  long in_stack_00000048;
  
                    /* catch() { ... } // from try @ 004d9232 with catch @ 004d9007 */
  __cxa_end_catch();
  qt_array_data_unref(&stack0x00000088);
  qt_shared_data_unref();
  qt_shared_data_unref(in_stack_00000018);
  if (*(int *)in_stack_00000038 != 0) {
    if (*(int *)in_stack_00000038 == -1) goto LAB_004d9064;
    LOCK();
    *(int *)in_stack_00000038 = *(int *)in_stack_00000038 + -1;
    UNLOCK();
    if (*(int *)in_stack_00000038 != 0) goto LAB_004d9064;
  }
  if (*(long *)(in_stack_00000048 + 0x10) != 0) {
    QMapDataBase::freeTree(in_stack_00000038,(int)*(long *)(in_stack_00000048 + 0x10));
  }
  QMapDataBase::freeData((QMapDataBase *)in_stack_00000038);
LAB_004d9064:
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d9093 name=FUN_004d9093 size=23 ====

void FUN_004d9093(void)

{
  __cxa_begin_catch();
  qt_array_data_unref(&stack0x00000070);
                    /* WARNING: Subroutine does not return */
                    /* try { // try from 004d90a5 to 004d90a9 has its CatchHandler @ 004d90aa */
  __cxa_rethrow();
}


// ==== entry=004d90c4 name=FUN_004d90c4 size=31 ====

void FUN_004d90c4(void)

{
  undefined8 in_stack_00000018;
  undefined8 in_stack_00000020;
  QMapNodeBase *in_stack_00000038;
  long in_stack_00000048;
  
  qt_byte_array_unref(&stack0x00000058);
  qt_byte_array_unref();
  qt_byte_array_unref();
  FUN_00670706(in_stack_00000020);
  qt_shared_data_unref(in_stack_00000018);
  if (*(int *)in_stack_00000038 != 0) {
    if (*(int *)in_stack_00000038 == -1) goto LAB_004d9064;
    LOCK();
    *(int *)in_stack_00000038 = *(int *)in_stack_00000038 + -1;
    UNLOCK();
    if (*(int *)in_stack_00000038 != 0) goto LAB_004d9064;
  }
  if (*(long *)(in_stack_00000048 + 0x10) != 0) {
    QMapDataBase::freeTree(in_stack_00000038,(int)*(long *)(in_stack_00000048 + 0x10));
  }
  QMapDataBase::freeData((QMapDataBase *)in_stack_00000038);
LAB_004d9064:
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d90e3 name=FUN_004d90e3 size=42 ====

void FUN_004d90e3(void)

{
  undefined8 unaff_retaddr;
  undefined8 in_stack_00000018;
  undefined8 in_stack_00000020;
  undefined8 in_stack_00000028;
  QMapNodeBase *in_stack_00000038;
  long in_stack_00000048;
  
  qt_byte_array_unref();
  qt_byte_array_unref(unaff_retaddr);
  qatomic_unref_call_deleter2(in_stack_00000028);
  FUN_00670706(in_stack_00000020);
  qt_shared_data_unref(in_stack_00000018);
  if (*(int *)in_stack_00000038 != 0) {
    if (*(int *)in_stack_00000038 == -1) goto LAB_004d9064;
    LOCK();
    *(int *)in_stack_00000038 = *(int *)in_stack_00000038 + -1;
    UNLOCK();
    if (*(int *)in_stack_00000038 != 0) goto LAB_004d9064;
  }
  if (*(long *)(in_stack_00000048 + 0x10) != 0) {
    QMapDataBase::freeTree(in_stack_00000038,(int)*(long *)(in_stack_00000048 + 0x10));
  }
  QMapDataBase::freeData((QMapDataBase *)in_stack_00000038);
LAB_004d9064:
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d910d name=FUN_004d910d size=44 ====

void FUN_004d910d(void)

{
  undefined8 in_stack_00000018;
  undefined8 in_stack_00000020;
  QMapNodeBase *in_stack_00000038;
  long in_stack_00000048;
  
  qt_array_data_unref();
  qt_array_data_unref(&stack0x00000088);
  qt_array_data_unref();
  qlist_unref_dispose(in_stack_00000020);
  qt_shared_data_unref(in_stack_00000018);
  if (*(int *)in_stack_00000038 != 0) {
    if (*(int *)in_stack_00000038 == -1) goto LAB_004d9064;
    LOCK();
    *(int *)in_stack_00000038 = *(int *)in_stack_00000038 + -1;
    UNLOCK();
    if (*(int *)in_stack_00000038 != 0) goto LAB_004d9064;
  }
  if (*(long *)(in_stack_00000048 + 0x10) != 0) {
    QMapDataBase::freeTree(in_stack_00000038,(int)*(long *)(in_stack_00000048 + 0x10));
  }
  QMapDataBase::freeData((QMapDataBase *)in_stack_00000038);
LAB_004d9064:
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d9139 name=FUN_004d9139 size=11 ====

void FUN_004d9139(void)

{
  undefined8 unaff_retaddr;
  undefined8 in_stack_00000018;
  undefined8 in_stack_00000020;
  QMapNodeBase *in_stack_00000038;
  long in_stack_00000048;
  
  qt_byte_array_unref(unaff_retaddr);
  FUN_00670706(in_stack_00000020);
  qt_shared_data_unref(in_stack_00000018);
  if (*(int *)in_stack_00000038 != 0) {
    if (*(int *)in_stack_00000038 == -1) goto LAB_004d9064;
    LOCK();
    *(int *)in_stack_00000038 = *(int *)in_stack_00000038 + -1;
    UNLOCK();
    if (*(int *)in_stack_00000038 != 0) goto LAB_004d9064;
  }
  if (*(long *)(in_stack_00000048 + 0x10) != 0) {
    QMapDataBase::freeTree(in_stack_00000038,(int)*(long *)(in_stack_00000048 + 0x10));
  }
  QMapDataBase::freeData((QMapDataBase *)in_stack_00000038);
LAB_004d9064:
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d9159 name=FUN_004d9159 size=26 ====

void FUN_004d9159(void)

{
  __cxa_begin_catch();
  qt_array_data_unref(&stack0x00000080);
                    /* WARNING: Subroutine does not return */
                    /* try { // try from 004d916e to 004d9172 has its CatchHandler @ 004d918a */
  __cxa_rethrow();
}


// ==== entry=004d9173 name=FUN_004d9173 size=23 ====

void FUN_004d9173(void)

{
  undefined8 in_stack_00000020;
  
  __cxa_begin_catch();
  qt_array_data_unref(in_stack_00000020);
                    /* WARNING: Subroutine does not return */
                    /* try { // try from 004d9185 to 004d9189 has its CatchHandler @ 004d906c */
  __cxa_rethrow();
}


// ==== entry=004d919f name=FUN_004d919f size=13 ====

void FUN_004d919f(void)

{
  undefined8 in_stack_00000018;
  undefined8 in_stack_00000020;
  QMapNodeBase *in_stack_00000038;
  long in_stack_00000048;
  
  qt_array_data_unref(&stack0x00000080);
  qlist_unref_dispose(in_stack_00000020);
  qt_shared_data_unref(in_stack_00000018);
  if (*(int *)in_stack_00000038 != 0) {
    if (*(int *)in_stack_00000038 == -1) goto LAB_004d9064;
    LOCK();
    *(int *)in_stack_00000038 = *(int *)in_stack_00000038 + -1;
    UNLOCK();
    if (*(int *)in_stack_00000038 != 0) goto LAB_004d9064;
  }
  if (*(long *)(in_stack_00000048 + 0x10) != 0) {
    QMapDataBase::freeTree(in_stack_00000038,(int)*(long *)(in_stack_00000048 + 0x10));
  }
  QMapDataBase::freeData((QMapDataBase *)in_stack_00000038);
LAB_004d9064:
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d91ac name=FUN_004d91ac size=21 ====

void FUN_004d91ac(void)

{
  undefined8 in_stack_00000018;
  undefined8 in_stack_00000020;
  QMapNodeBase *in_stack_00000038;
  long in_stack_00000048;
  
  qt_array_data_unref();
  qt_array_data_unref();
  qt_array_data_unref();
  qlist_unref_dispose(in_stack_00000020);
  qt_shared_data_unref(in_stack_00000018);
  if (*(int *)in_stack_00000038 != 0) {
    if (*(int *)in_stack_00000038 == -1) goto LAB_004d9064;
    LOCK();
    *(int *)in_stack_00000038 = *(int *)in_stack_00000038 + -1;
    UNLOCK();
    if (*(int *)in_stack_00000038 != 0) goto LAB_004d9064;
  }
  if (*(long *)(in_stack_00000048 + 0x10) != 0) {
    QMapDataBase::freeTree(in_stack_00000038,(int)*(long *)(in_stack_00000048 + 0x10));
  }
  QMapDataBase::freeData((QMapDataBase *)in_stack_00000038);
LAB_004d9064:
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d91c1 name=FUN_004d91c1 size=26 ====

void FUN_004d91c1(void)

{
  __cxa_begin_catch();
  qt_array_data_unref(&stack0x00000088);
                    /* WARNING: Subroutine does not return */
                    /* try { // try from 004d91d6 to 004d91da has its CatchHandler @ 004d9144 */
  __cxa_rethrow();
}


// ==== entry=004d91db name=FUN_004d91db size=13 ====

void FUN_004d91db(void)

{
  undefined8 in_stack_00000018;
  undefined8 in_stack_00000020;
  QMapNodeBase *in_stack_00000038;
  long in_stack_00000048;
  
  qt_byte_array_unref();
  qlist_unref_dispose(in_stack_00000020);
  qt_shared_data_unref(in_stack_00000018);
  if (*(int *)in_stack_00000038 != 0) {
    if (*(int *)in_stack_00000038 == -1) goto LAB_004d9064;
    LOCK();
    *(int *)in_stack_00000038 = *(int *)in_stack_00000038 + -1;
    UNLOCK();
    if (*(int *)in_stack_00000038 != 0) goto LAB_004d9064;
  }
  if (*(long *)(in_stack_00000048 + 0x10) != 0) {
    QMapDataBase::freeTree(in_stack_00000038,(int)*(long *)(in_stack_00000048 + 0x10));
  }
  QMapDataBase::freeData((QMapDataBase *)in_stack_00000038);
LAB_004d9064:
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d91e8 name=FUN_004d91e8 size=35 ====

void FUN_004d91e8(void)

{
  long lVar1;
  long unaff_R13;
  undefined8 in_stack_00000018;
  QMapNodeBase *in_stack_00000038;
  long in_stack_00000048;
  
  qt_shared_data_unref();
  lVar1 = unaff_R13 + 0x28;
  do {
    lVar1 = lVar1 + -8;
    qt_array_data_unref(lVar1);
  } while (lVar1 != unaff_R13);
  qt_shared_data_unref(in_stack_00000018);
  if (*(int *)in_stack_00000038 != 0) {
    if (*(int *)in_stack_00000038 == -1) goto LAB_004d9064;
    LOCK();
    *(int *)in_stack_00000038 = *(int *)in_stack_00000038 + -1;
    UNLOCK();
    if (*(int *)in_stack_00000038 != 0) goto LAB_004d9064;
  }
  if (*(long *)(in_stack_00000048 + 0x10) != 0) {
    QMapDataBase::freeTree(in_stack_00000038,(int)*(long *)(in_stack_00000048 + 0x10));
  }
  QMapDataBase::freeData((QMapDataBase *)in_stack_00000038);
LAB_004d9064:
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d920b name=FUN_004d920b size=23 ====

void FUN_004d920b(void)

{
  undefined8 in_stack_00000018;
  undefined8 in_stack_00000020;
  QMapNodeBase *in_stack_00000038;
  long in_stack_00000048;
  
  qt_array_data_unref();
  qt_array_data_unref();
  FUN_00670706(in_stack_00000020);
  qt_shared_data_unref(in_stack_00000018);
  if (*(int *)in_stack_00000038 != 0) {
    if (*(int *)in_stack_00000038 == -1) goto LAB_004d9064;
    LOCK();
    *(int *)in_stack_00000038 = *(int *)in_stack_00000038 + -1;
    UNLOCK();
    if (*(int *)in_stack_00000038 != 0) goto LAB_004d9064;
  }
  if (*(long *)(in_stack_00000048 + 0x10) != 0) {
    QMapDataBase::freeTree(in_stack_00000038,(int)*(long *)(in_stack_00000048 + 0x10));
  }
  QMapDataBase::freeData((QMapDataBase *)in_stack_00000038);
LAB_004d9064:
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d9222 name=FUN_004d9222 size=21 ====

void FUN_004d9222(void)

{
  __cxa_begin_catch();
  qt_array_data_unref();
                    /* WARNING: Subroutine does not return */
                    /* try { // try from 004d9232 to 004d9236 has its CatchHandler @ 004d9007 */
  __cxa_rethrow();
}


// ==== entry=004d9237 name=FUN_004d9237 size=40 ====

void FUN_004d9237(void)

{
  undefined8 in_stack_00000018;
  undefined8 in_stack_00000020;
  QMapNodeBase *in_stack_00000038;
  long in_stack_00000048;
  
  qt_array_data_unref();
  qt_array_data_unref();
  FUN_00670706(in_stack_00000020);
  qt_shared_data_unref(in_stack_00000018);
  if (*(int *)in_stack_00000038 != 0) {
    if (*(int *)in_stack_00000038 == -1) goto LAB_004d9064;
    LOCK();
    *(int *)in_stack_00000038 = *(int *)in_stack_00000038 + -1;
    UNLOCK();
    if (*(int *)in_stack_00000038 != 0) goto LAB_004d9064;
  }
  if (*(long *)(in_stack_00000048 + 0x10) != 0) {
    QMapDataBase::freeTree(in_stack_00000038,(int)*(long *)(in_stack_00000048 + 0x10));
  }
  QMapDataBase::freeData((QMapDataBase *)in_stack_00000038);
LAB_004d9064:
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d9260 name=FUN_004d9260 size=34 ====

void FUN_004d9260(void)

{
  long unaff_RBP;
  
  qt_byte_array_unref(unaff_RBP + 0x10);
  qt_byte_array_unref(unaff_RBP + 8);
  qt_byte_array_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d9282 name=FUN_004d9282 size=16 ====

void FUN_004d9282(void)

{
  qatomic_unref_call_deleter2();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d9292 name=FUN_004d9292 size=33 ====

void FUN_004d9292(void)

{
  undefined1 *puVar1;
  undefined1 *unaff_RBP;
  
  puVar1 = &stack0x00000120;
  do {
    puVar1 = puVar1 + -8;
    qt_byte_array_unref(puVar1);
  } while (puVar1 != unaff_RBP);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d92b3 name=FUN_004d92b3 size=16 ====

void FUN_004d92b3(void)

{
  qatomic_unref_call_deleter2();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d92d0 name=FUN_004d92d0 size=34 ====

void FUN_004d92d0(void)

{
  QKeySequence *in_stack_00000018;
  
  qt_array_data_unref();
  QKeySequence::~QKeySequence(in_stack_00000018);
  qt_array_data_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d92f2 name=FUN_004d92f2 size=10 ====

void FUN_004d92f2(void)

{
  qt_array_data_unref();
  qt_array_data_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d92fc name=FUN_004d92fc size=57 ====

void FUN_004d92fc(void)

{
  char cVar1;
  QObject *unaff_RBX;
  QRegularExpression *unaff_R13;
  
  qt_array_data_unref();
  QRegularExpression::~QRegularExpression(unaff_R13);
  cVar1 = qatomic_int_deref(*(undefined8 *)(unaff_RBX + 0x10));
  if (cVar1 == '\0') {
    FUN_006744ae(*(undefined8 *)(unaff_RBX + 0x10));
  }
  QObject::~QObject(unaff_RBX);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d9336 name=FUN_004d9336 size=40 ====

void FUN_004d9336(void)

{
  undefined8 *unaff_R13;
  undefined8 in_stack_00000018;
  
  qt_byte_array_unref(in_stack_00000018);
  if ((undefined *)*unaff_R13 != &DAT_011c5118) {
    refcount_delete_offset10_g();
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d935e name=FUN_004d935e size=26 ====

void FUN_004d935e(void)

{
  undefined8 in_stack_00000018;
  
  qt_array_data_unref();
  qt_array_data_unref(in_stack_00000018);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d9378 name=FUN_004d9378 size=16 ====

void FUN_004d9378(void)

{
  qt_array_data_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d9388 name=FUN_004d9388 size=27 ====

void FUN_004d9388(void)

{
  long unaff_RBX;
  QRegularExpression *in_stack_00000038;
  long *in_stack_00000048;
  
  if (*in_stack_00000048 + -0x18 != unaff_RBX) {
    refcount_delete_offset10_g();
  }
  QRegularExpression::~QRegularExpression(in_stack_00000038);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d93a3 name=FUN_004d93a3 size=45 ====

void FUN_004d93a3(void)

{
  QKeySequence *unaff_RBX;
  QRegularExpressionMatch *unaff_R13;
  QRegularExpression *in_stack_00000038;
  
  QKeySequence::~QKeySequence(unaff_RBX);
  qt_array_data_unref();
  QRegularExpressionMatch::~QRegularExpressionMatch(unaff_R13);
  QRegularExpression::~QRegularExpression(in_stack_00000038);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d93d0 name=FUN_004d93d0 size=10 ====

void FUN_004d93d0(void)

{
  QRegularExpressionMatch *unaff_R13;
  QRegularExpression *in_stack_00000038;
  
  qt_array_data_unref();
  qt_array_data_unref();
  QRegularExpressionMatch::~QRegularExpressionMatch(unaff_R13);
  QRegularExpression::~QRegularExpression(in_stack_00000038);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d93da name=FUN_004d93da size=81 ====

void FUN_004d93da(void)

{
  int *unaff_RBP;
  int unaff_R12D;
  undefined8 in_stack_00000030;
  QJSValue *in_stack_00000088;
  _Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *in_stack_00000098;
  
  if (*unaff_RBP == 0) {
    *unaff_RBP = unaff_R12D;
  }
  __cxa_begin_catch();
  QJSValue::~QJSValue(in_stack_00000088);
  qt_array_data_unref();
  if (in_stack_00000098 != (_Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *)0x0) {
    std::_Sp_counted_base<(__gnu_cxx::_Lock_policy)2>::_M_release(in_stack_00000098);
  }
  treenode_dtor_recursive(in_stack_00000030);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d942b name=FUN_004d942b size=38 ====

void FUN_004d942b(void)

{
  undefined8 in_stack_00000030;
  _Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *in_stack_00000098;
  long in_stack_000000d0;
  long in_stack_00000138;
  
  if (in_stack_00000138 != 0) {
    FUN_0067cdf0();
  }
  if (in_stack_000000d0 != 0) {
    tree_node_release();
  }
  if (in_stack_00000098 != (_Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *)0x0) {
    std::_Sp_counted_base<(__gnu_cxx::_Lock_policy)2>::_M_release(in_stack_00000098);
  }
  treenode_dtor_recursive(in_stack_00000030);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d9451 name=FUN_004d9451 size=147 ====

void FUN_004d9451(void)

{
  long unaff_RBX;
  long unaff_RBP;
  long unaff_R12;
  long in_stack_00000008;
  undefined8 in_stack_00000030;
  undefined8 in_stack_00000038;
  undefined8 in_stack_00000058;
  _Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *in_stack_00000098;
  undefined8 in_stack_000000b0;
  long in_stack_000000d0;
  long in_stack_00000168;
  long in_stack_00000188;
  
  FUN_00680a52(in_stack_00000038);
  FUN_00680a52(in_stack_00000058);
  FUN_00680a52(&stack0x00000240);
  if (unaff_R12 != 0) {
    refcounted_vt_destroy();
  }
  if (unaff_RBX != 0) {
    refcounted_vt_destroy();
  }
  FUN_00680a52(in_stack_000000b0);
  if (in_stack_00000008 != 0) {
    refcounted_vt_destroy(in_stack_00000008);
  }
  if (unaff_RBP != 0) {
    refcounted_vt_destroy();
  }
  if (in_stack_00000188 != 0) {
    refcounted_vt_destroy();
  }
  if (in_stack_00000168 != 0) {
    refcounted_vt_destroy();
  }
  if (in_stack_000000d0 != 0) {
    tree_node_release();
  }
  if (in_stack_00000098 != (_Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *)0x0) {
    std::_Sp_counted_base<(__gnu_cxx::_Lock_policy)2>::_M_release(in_stack_00000098);
  }
  treenode_dtor_recursive(in_stack_00000030);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d94e4 name=FUN_004d94e4 size=41 ====

void FUN_004d94e4(void)

{
  undefined8 in_stack_00000030;
  undefined8 in_stack_00000038;
  undefined8 in_stack_00000088;
  _Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *in_stack_00000098;
  QJSValue *in_stack_000000b0;
  
  qt_array_data_unref(in_stack_00000038);
  qt_array_data_unref(in_stack_00000088);
  QJSValue::~QJSValue(in_stack_000000b0);
  if (in_stack_00000098 != (_Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *)0x0) {
    std::_Sp_counted_base<(__gnu_cxx::_Lock_policy)2>::_M_release(in_stack_00000098);
  }
  treenode_dtor_recursive(in_stack_00000030);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d950d name=FUN_004d950d size=21 ====

void FUN_004d950d(void)

{
  QJSValue *unaff_RBP;
  QJSValue *unaff_R12;
  undefined8 in_stack_00000030;
  _Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *in_stack_00000098;
  
  QJSValue::~QJSValue(unaff_RBP);
  QJSValue::~QJSValue(unaff_R12);
  if (in_stack_00000098 != (_Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *)0x0) {
    std::_Sp_counted_base<(__gnu_cxx::_Lock_policy)2>::_M_release(in_stack_00000098);
  }
  treenode_dtor_recursive(in_stack_00000030);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d9522 name=FUN_004d9522 size=12 ====

void FUN_004d9522(void)

{
  QJSValue *unaff_R12;
  undefined8 in_stack_00000030;
  undefined8 in_stack_00000038;
  _Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *in_stack_00000098;
  
  qlist_release_data(in_stack_00000038);
  QJSValue::~QJSValue(unaff_R12);
  if (in_stack_00000098 != (_Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *)0x0) {
    std::_Sp_counted_base<(__gnu_cxx::_Lock_policy)2>::_M_release(in_stack_00000098);
  }
  treenode_dtor_recursive(in_stack_00000030);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d952e name=FUN_004d952e size=48 ====

void FUN_004d952e(void)

{
  undefined8 *unaff_RBP;
  undefined8 *unaff_R14;
  
  __cxa_begin_catch();
  for (; unaff_R14 != unaff_RBP; unaff_R14 = unaff_R14 + 2) {
    if ((undefined *)*unaff_R14 != &DAT_011c5118) {
      refcount_delete_offset10_g();
    }
  }
                    /* WARNING: Subroutine does not return */
                    /* try { // try from 004d953b to 004d953f has its CatchHandler @ 004d9540 */
  __cxa_rethrow();
}


// ==== entry=004d95c9 name=FUN_004d95c9 size=61 ====

void FUN_004d95c9(void)

{
  undefined8 in_stack_00000030;
  long in_stack_00000038;
  _Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *in_stack_00000098;
  long in_stack_000000d0;
  undefined8 in_stack_000002f0;
  undefined8 in_stack_00000320;
  long in_stack_00000348;
  
  if (in_stack_00000348 != 0) {
    refcounted_vt_destroy();
  }
  FUN_006809c0(in_stack_00000038 + 0x30,in_stack_00000320);
  FUN_0067faa0(in_stack_00000038,in_stack_000002f0);
  if (in_stack_000000d0 != 0) {
    tree_node_release();
  }
  if (in_stack_00000098 != (_Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *)0x0) {
    std::_Sp_counted_base<(__gnu_cxx::_Lock_policy)2>::_M_release(in_stack_00000098);
  }
  treenode_dtor_recursive(in_stack_00000030);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d9606 name=FUN_004d9606 size=22 ====

void FUN_004d9606(void)

{
  QJSValue *unaff_retaddr;
  undefined8 in_stack_00000030;
  _Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *in_stack_00000098;
  QJSValue *in_stack_000000b0;
  
  qlist_release_data();
  QJSValue::~QJSValue(unaff_retaddr);
  QJSValue::~QJSValue(in_stack_000000b0);
  if (in_stack_00000098 != (_Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *)0x0) {
    std::_Sp_counted_base<(__gnu_cxx::_Lock_policy)2>::_M_release(in_stack_00000098);
  }
  treenode_dtor_recursive(in_stack_00000030);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d961c name=FUN_004d961c size=51 ====

void FUN_004d961c(void)

{
  long unaff_RBX;
  long unaff_RBP;
  QJSValue *unaff_R13;
  undefined8 in_stack_00000030;
  undefined8 in_stack_00000088;
  _Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *in_stack_00000098;
  QJSValue *in_stack_000000b0;
  
  qt_array_data_unref();
  QJSValue::~QJSValue(unaff_R13);
  qt_array_data_unref(in_stack_00000088);
  if (unaff_RBP + -0x18 != unaff_RBX) {
    refcount_delete_offset10_g();
  }
  QJSValue::~QJSValue(in_stack_000000b0);
  if (in_stack_00000098 != (_Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *)0x0) {
    std::_Sp_counted_base<(__gnu_cxx::_Lock_policy)2>::_M_release(in_stack_00000098);
  }
  treenode_dtor_recursive(in_stack_00000030);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d964f name=FUN_004d964f size=13 ====

void FUN_004d964f(void)

{
  undefined8 in_stack_00000030;
  _Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *in_stack_00000098;
  QJSValue *in_stack_000000b0;
  
  qt_byte_array_unref();
  QJSValue::~QJSValue(in_stack_000000b0);
  if (in_stack_00000098 != (_Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *)0x0) {
    std::_Sp_counted_base<(__gnu_cxx::_Lock_policy)2>::_M_release(in_stack_00000098);
  }
  treenode_dtor_recursive(in_stack_00000030);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d965c name=FUN_004d965c size=16 ====

void FUN_004d965c(void)

{
  QJSValue *unaff_RBX;
  undefined8 in_stack_00000030;
  _Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *in_stack_00000098;
  QJSValue *in_stack_000000b0;
  
  QJSValue::~QJSValue(unaff_RBX);
  QJSValue::~QJSValue(in_stack_000000b0);
  if (in_stack_00000098 != (_Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *)0x0) {
    std::_Sp_counted_base<(__gnu_cxx::_Lock_policy)2>::_M_release(in_stack_00000098);
  }
  treenode_dtor_recursive(in_stack_00000030);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d966c name=FUN_004d966c size=13 ====

void FUN_004d966c(void)

{
  undefined8 in_stack_00000030;
  _Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *in_stack_00000098;
  QJSValue *in_stack_000000b0;
  
  qt_array_data_unref();
  QJSValue::~QJSValue(in_stack_000000b0);
  if (in_stack_00000098 != (_Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *)0x0) {
    std::_Sp_counted_base<(__gnu_cxx::_Lock_policy)2>::_M_release(in_stack_00000098);
  }
  treenode_dtor_recursive(in_stack_00000030);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d9679 name=FUN_004d9679 size=18 ====

void FUN_004d9679(void)

{
  void *unaff_R14;
  undefined8 in_stack_00000030;
  _Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *in_stack_00000098;
  
  operator_delete(unaff_R14,0x28);
  if (in_stack_00000098 != (_Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *)0x0) {
    std::_Sp_counted_base<(__gnu_cxx::_Lock_policy)2>::_M_release(in_stack_00000098);
  }
  treenode_dtor_recursive(in_stack_00000030);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d968b name=FUN_004d968b size=13 ====

void FUN_004d968b(void)

{
  undefined8 in_stack_00000030;
  _Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *in_stack_00000098;
  
  qt_array_data_unref();
  if (in_stack_00000098 != (_Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *)0x0) {
    std::_Sp_counted_base<(__gnu_cxx::_Lock_policy)2>::_M_release(in_stack_00000098);
  }
  treenode_dtor_recursive(in_stack_00000030);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d9698 name=FUN_004d9698 size=51 ====

void FUN_004d9698(void)

{
  long *unaff_R12;
  long *plVar1;
  long in_stack_00000008;
  
  __cxa_begin_catch();
  for (plVar1 = unaff_R12; unaff_R12 != plVar1; plVar1 = plVar1 + 1) {
    if (*plVar1 + -0x18 != in_stack_00000008) {
      refcount_delete_offset10_g();
    }
  }
                    /* WARNING: Subroutine does not return */
                    /* try { // try from 004d96ac to 004d96b0 has its CatchHandler @ 004d96b1 */
  __cxa_rethrow();
}


// ==== entry=004d9718 name=FUN_004d9718 size=29 ====

void FUN_004d9718(void)

{
  qt_array_data_unref();
  FUN_0067ce7e();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d972d name=FUN_004d972d size=29 ====

void FUN_004d972d(void)

{
  qt_array_data_unref();
  qt_array_data_unref();
  qt_array_data_unref();
  FUN_0067ce7e();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d974a name=FUN_004d974a size=21 ====

void FUN_004d974a(void)

{
  qt_array_data_unref();
  qt_array_data_unref();
  qt_array_data_unref();
  FUN_0067ce7e();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d9760 name=FUN_004d9760 size=83 ====

void FUN_004d9760(void)

{
  QVariant *unaff_RBX;
  QVariant *unaff_R12;
  undefined8 in_stack_00000008;
  undefined8 in_stack_00000018;
  undefined8 in_stack_00000038;
  _Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *in_stack_000000a8;
  
  QVariant::~QVariant(unaff_RBX);
  qt_array_data_unref(in_stack_00000008);
  QVariant::~QVariant(unaff_R12);
  qatomic_unref_call_deleter2(in_stack_00000018);
  qt_shared_data_unref(in_stack_00000038);
  if (in_stack_000000a8 != (_Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *)0x0) {
    std::_Sp_counted_base<(__gnu_cxx::_Lock_policy)2>::_M_release(in_stack_000000a8);
  }
  qt_array_data_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d97b3 name=FUN_004d97b3 size=20 ====

void FUN_004d97b3(void)

{
  undefined8 in_stack_00000038;
  _Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *in_stack_000000a8;
  long in_stack_000000c0;
  
  if (in_stack_000000c0 != 0) {
    tree_node_release();
  }
  qt_shared_data_unref(in_stack_00000038);
  if (in_stack_000000a8 != (_Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *)0x0) {
    std::_Sp_counted_base<(__gnu_cxx::_Lock_policy)2>::_M_release(in_stack_000000a8);
  }
  qt_array_data_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d97c7 name=FUN_004d97c7 size=49 ====

void FUN_004d97c7(void)

{
  undefined8 unaff_retaddr;
  QVariant *in_stack_00000008;
  undefined8 in_stack_00000018;
  undefined8 in_stack_00000028;
  QVariant *in_stack_00000030;
  undefined8 in_stack_00000038;
  _Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *in_stack_000000a8;
  
  qt_byte_array_unref();
  qt_byte_array_unref(unaff_retaddr);
  QVariant::~QVariant(in_stack_00000008);
  qt_array_data_unref(in_stack_00000028);
  QVariant::~QVariant(in_stack_00000030);
  qatomic_unref_call_deleter2(in_stack_00000018);
  qt_shared_data_unref(in_stack_00000038);
  if (in_stack_000000a8 != (_Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *)0x0) {
    std::_Sp_counted_base<(__gnu_cxx::_Lock_policy)2>::_M_release(in_stack_000000a8);
  }
  qt_array_data_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d97f8 name=FUN_004d97f8 size=34 ====

void FUN_004d97f8(void)

{
  QVariant *unaff_RBX;
  QVariant *unaff_R12;
  undefined8 in_stack_00000008;
  undefined8 in_stack_00000018;
  undefined8 in_stack_00000038;
  _Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *in_stack_000000a8;
  
  QVariant::~QVariant(unaff_RBX);
  qt_array_data_unref(in_stack_00000008);
  QVariant::~QVariant(unaff_R12);
  qatomic_unref_call_deleter2(in_stack_00000018);
  qt_shared_data_unref(in_stack_00000038);
  if (in_stack_000000a8 != (_Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *)0x0) {
    std::_Sp_counted_base<(__gnu_cxx::_Lock_policy)2>::_M_release(in_stack_000000a8);
  }
  qt_array_data_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d981a name=FUN_004d981a size=44 ====

void FUN_004d981a(void)

{
  long unaff_RBX;
  undefined8 in_stack_00000018;
  undefined8 in_stack_00000038;
  _Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *in_stack_000000a8;
  
  qatomic_unref_call_deleter2(in_stack_00000018);
  qt_byte_array_unref(unaff_RBX + 0x10);
  qt_byte_array_unref(unaff_RBX + 8);
  qt_byte_array_unref();
  qt_shared_data_unref(in_stack_00000038);
  if (in_stack_000000a8 != (_Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *)0x0) {
    std::_Sp_counted_base<(__gnu_cxx::_Lock_policy)2>::_M_release(in_stack_000000a8);
  }
  qt_array_data_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d9846 name=FUN_004d9846 size=103 ====

void FUN_004d9846(void)

{
  QByteArray *pQVar1;
  undefined1 uVar2;
  char cVar3;
  long *plVar4;
  char *pcVar5;
  long lVar6;
  char *pcVar7;
  string *unaff_RBX;
  int iVar8;
  QVariant *pQVar9;
  QVariant *unaff_R12;
  QByteArray *pQVar10;
  long unaff_R14;
  undefined8 *unaff_R15;
  QVariant *in_stack_00000008;
  long in_stack_00000010;
  char in_stack_00000018;
  undefined8 in_stack_00000020;
  QVariant *in_stack_00000030;
  undefined8 in_stack_00000038;
  undefined8 *in_stack_00000070;
  undefined8 in_stack_00000078;
  long in_stack_000000a0;
  _Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *in_stack_000000a8;
  undefined8 in_stack_000000b0;
  undefined4 in_stack_000000b8;
  long in_stack_000000c0;
  undefined1 *in_stack_000000d0;
  undefined4 in_stack_000000d8;
  undefined1 *in_stack_000000f0;
  undefined4 in_stack_000000f8;
  
  if (in_stack_000000d0 != (undefined1 *)0x0) {
    tree_node_release();
  }
  if (unaff_R14 != 1) {
    if (in_stack_000000c0 != 0) {
      tree_node_release();
    }
    qt_shared_data_unref(in_stack_00000038);
    if (in_stack_000000a8 != (_Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *)0x0) {
      std::_Sp_counted_base<(__gnu_cxx::_Lock_policy)2>::_M_release(in_stack_000000a8);
    }
    qt_array_data_unref();
                    /* WARNING: Subroutine does not return */
    cxa_throw_exception();
  }
  plVar4 = (long *)__cxa_begin_catch();
  pcVar5 = (char *)(**(code **)(*plVar4 + 0x10))(plVar4);
                    /* try { // try from 004d987c to 004d9880 has its CatchHandler @ 004d98e7 */
  std::string::string(unaff_RBX,pcVar5,(allocator *)unaff_R12);
  if (in_stack_000000f0 != &DAT_011c5338) {
    FUN_00673ea0();
  }
  __cxa_end_catch();
  FUN_00687320(in_stack_000000a0 + 8,in_stack_00000008);
  if (in_stack_000000c0 != 0) {
    tree_node_release();
  }
  if (in_stack_00000018 == '\0') goto LAB_006780b2;
  QByteArray::QByteArray((QByteArray *)unaff_RBX,"action",-1);
  QByteArray::QByteArray((QByteArray *)(unaff_RBX + 8),"map",-1);
  QByteArray::QByteArray((QByteArray *)(unaff_RBX + 0x10),"script",-1);
  in_stack_00000070 = &QListData::shared_null;
  if (QListData::shared_null._4_4_ < 3) {
    if ((uint)QListData::shared_null < 2) {
      QListData::realloc((int)&stack0x00000070);
    }
    else {
      qlist_copyRefs(&stack0x00000070,3);
    }
  }
  _in_stack_00000018 = &stack0x00000070;
  qlist_str_append(_in_stack_00000018);
  qlist_str_append(_in_stack_00000018,unaff_RBX + 8);
  qlist_str_append(_in_stack_00000018);
  qt_byte_array_unref(unaff_RBX + 0x10);
  qt_byte_array_unref(unaff_RBX + 8);
  qt_byte_array_unref();
  FUN_0067dffe(_in_stack_00000018);
  pQVar10 = (QByteArray *)(in_stack_00000070 + (long)*(int *)(in_stack_00000070 + 1) + 2);
  FUN_0067dffe(_in_stack_00000018);
  pQVar1 = (QByteArray *)(in_stack_00000070 + (long)*(int *)((long)in_stack_00000070 + 0xc) + 2);
  for (; pQVar10 != pQVar1; pQVar10 = pQVar10 + 8) {
    lVar6 = *(long *)pQVar10;
    pcVar5 = (char *)(lVar6 + *(long *)(lVar6 + 0x10));
    if (((pcVar5 == (char *)0x0) || (*(int *)(lVar6 + 4) == 0)) || (*pcVar5 == '\0')) {
      iVar8 = 0;
    }
    else {
      pcVar7 = pcVar5 + 1;
      do {
        iVar8 = (1 - (int)(pcVar5 + 1)) + (int)pcVar7;
        if (pcVar7 == pcVar5 + (ulong)(*(int *)(lVar6 + 4) - 1) + 1) break;
        cVar3 = *pcVar7;
        pcVar7 = pcVar7 + 1;
      } while (cVar3 != '\0');
    }
    in_stack_000000f0 = (undefined1 *)QString::fromAscii_helper(pcVar5,iVar8);
    lVar6 = qmap_lower_bound_find(*unaff_R15);
    qt_array_data_unref();
    if (lVar6 != 0) {
      in_stack_000000b0 = 0;
      in_stack_000000b8 = 0x80000000;
      lVar6 = *(long *)pQVar10;
      pcVar5 = (char *)(lVar6 + *(long *)(lVar6 + 0x10));
      if (((pcVar5 != (char *)0x0) && (*(int *)(lVar6 + 4) != 0)) && (*pcVar5 != '\0')) {
        pcVar7 = pcVar5 + 1;
        goto LAB_00678779;
      }
      iVar8 = 0;
      goto LAB_00678781;
    }
  }
  goto LAB_00678588;
  while (cVar3 = *pcVar7, pcVar7 = pcVar7 + 1, cVar3 != '\0') {
LAB_00678779:
    iVar8 = (1 - (int)(pcVar5 + 1)) + (int)pcVar7;
    if (pcVar7 == pcVar5 + (ulong)(*(int *)(lVar6 + 4) - 1) + 1) break;
  }
LAB_00678781:
  in_stack_00000078 = QString::fromAscii_helper(pcVar5,iVar8);
  lVar6 = qmap_lower_bound_find(*unaff_R15,&stack0x00000078);
  pQVar9 = in_stack_00000030;
  if (lVar6 != 0) {
    pQVar9 = (QVariant *)(lVar6 + 0x20);
  }
  QVariant::QVariant(in_stack_00000008,pQVar9);
  QVariant::toByteArray();
  QByteArray::trimmed_helper((QByteArray *)&stack0x00000088);
  QVariant::QVariant(unaff_R12,(QByteArray *)&stack0x00000088);
  in_stack_000000f0 = *(undefined1 **)(in_stack_000000a0 + 0x20);
  in_stack_000000f8 = *(undefined4 *)(in_stack_000000a0 + 0x28);
  *(undefined1 **)(in_stack_000000a0 + 0x20) = in_stack_000000d0;
  *(undefined4 *)(in_stack_000000a0 + 0x28) = in_stack_000000d8;
  in_stack_000000d0 = in_stack_000000f0;
  in_stack_000000d8 = in_stack_000000f8;
  QVariant::~QVariant(unaff_R12);
  qt_byte_array_unref((QByteArray *)&stack0x00000088);
  qt_byte_array_unref(&stack0x00000080);
  QVariant::~QVariant(in_stack_00000008);
  qt_array_data_unref(&stack0x00000078);
  QVariant::~QVariant(in_stack_00000030);
  iVar8 = qstrcmp(pQVar10,"action");
  if (iVar8 == 0) {
    cVar3 = '\0';
  }
  else {
    iVar8 = qstrcmp(pQVar10,"map");
    cVar3 = (iVar8 != 0) + '\x01';
  }
  *(char *)(in_stack_000000a0 + 0x18) = cVar3;
LAB_00678588:
  in_stack_000000d0 = (undefined1 *)0x0;
  in_stack_000000d8 = 0x80000000;
  qstring_assign_from_ascii(in_stack_00000008,&DAT_00c91ca5);
  lVar6 = qmap_lower_bound_find(*unaff_R15,in_stack_00000008);
  pQVar9 = unaff_R12;
  if (lVar6 != 0) {
    pQVar9 = (QVariant *)(lVar6 + 0x20);
  }
  QVariant::QVariant((QVariant *)unaff_RBX,pQVar9);
  QVariant::operator=((QVariant *)(in_stack_000000a0 + 0x30),(QVariant *)unaff_RBX);
  QVariant::~QVariant((QVariant *)unaff_RBX);
  qt_array_data_unref(in_stack_00000008);
  QVariant::~QVariant(unaff_R12);
  QVariant::QVariant(unaff_R12,false);
  qstring_assign_from_ascii(in_stack_00000008,"repeatable");
  lVar6 = qmap_lower_bound_find(*unaff_R15,in_stack_00000008);
  pQVar9 = unaff_R12;
  if (lVar6 != 0) {
    pQVar9 = (QVariant *)(lVar6 + 0x20);
  }
  QVariant::QVariant((QVariant *)unaff_RBX,pQVar9);
  uVar2 = QVariant::toBool();
  *(undefined1 *)(in_stack_000000a0 + 0x10) = uVar2;
  QVariant::~QVariant((QVariant *)unaff_RBX);
  qt_array_data_unref(in_stack_00000008);
  QVariant::~QVariant(unaff_R12);
  QVariant::toByteArray();
  iVar8 = *(int *)(in_stack_000000f0 + 4);
  qt_byte_array_unref();
  if (iVar8 != 0) {
    FUN_0067db40(in_stack_00000010 + 0x10);
    FUN_0067de60(*(long *)(in_stack_00000010 + 0x10) + (long)in_stack_00000020._7_1_ * 8 +
                 *(long *)(*(long *)(in_stack_00000010 + 0x10) + 0x10),&stack0x000000a0);
  }
  qatomic_unref_call_deleter2(_in_stack_00000018);
LAB_006780b2:
  qt_shared_data_unref(in_stack_00000038);
  if (in_stack_000000a8 != (_Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *)0x0) {
    std::_Sp_counted_base<(__gnu_cxx::_Lock_policy)2>::_M_release(in_stack_000000a8);
  }
  qt_array_data_unref();
  return;
}


// ==== entry=004d98ad name=FUN_004d98ad size=84 ====

void FUN_004d98ad(void)

{
  QByteArray *pQVar1;
  undefined1 uVar2;
  char cVar3;
  long *plVar4;
  char *pcVar5;
  long lVar6;
  char *pcVar7;
  string *unaff_RBX;
  int iVar8;
  QVariant *pQVar9;
  QVariant *unaff_R12;
  QByteArray *pQVar10;
  long unaff_R14;
  undefined8 *unaff_R15;
  locale *unaff_retaddr;
  QVariant *in_stack_00000008;
  long in_stack_00000010;
  char in_stack_00000018;
  undefined8 in_stack_00000020;
  QVariant *in_stack_00000030;
  undefined8 in_stack_00000038;
  undefined8 *in_stack_00000070;
  undefined8 in_stack_00000078;
  long in_stack_000000a0;
  _Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *in_stack_000000a8;
  undefined8 in_stack_000000b0;
  undefined4 in_stack_000000b8;
  long in_stack_000000c0;
  undefined1 *in_stack_000000d0;
  undefined4 in_stack_000000d8;
  undefined1 *in_stack_000000f0;
  undefined4 in_stack_000000f8;
  long in_stack_00000128;
  undefined8 in_stack_00000140;
  
  FUN_0067fb80(unaff_RBX + 0x40,in_stack_00000140);
  if (in_stack_00000128 != 0) {
    refcounted_vt_destroy();
  }
  std::locale::~locale((locale *)(unaff_RBX + 0x10));
  std::locale::~locale(unaff_retaddr);
  if (unaff_R14 != 1) {
    if (in_stack_000000c0 != 0) {
      tree_node_release();
    }
    qt_shared_data_unref(in_stack_00000038);
    if (in_stack_000000a8 != (_Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *)0x0) {
      std::_Sp_counted_base<(__gnu_cxx::_Lock_policy)2>::_M_release(in_stack_000000a8);
    }
    qt_array_data_unref();
                    /* WARNING: Subroutine does not return */
    cxa_throw_exception();
  }
  plVar4 = (long *)__cxa_begin_catch();
  pcVar5 = (char *)(**(code **)(*plVar4 + 0x10))(plVar4);
  std::string::string(unaff_RBX,pcVar5,(allocator *)unaff_R12);
  if (in_stack_000000f0 != &DAT_011c5338) {
    FUN_00673ea0();
  }
  __cxa_end_catch();
  FUN_00687320(in_stack_000000a0 + 8,in_stack_00000008);
  if (in_stack_000000c0 != 0) {
    tree_node_release();
  }
  if (in_stack_00000018 == '\0') goto LAB_006780b2;
  QByteArray::QByteArray((QByteArray *)unaff_RBX,"action",-1);
  QByteArray::QByteArray((QByteArray *)(unaff_RBX + 8),"map",-1);
  QByteArray::QByteArray((QByteArray *)(unaff_RBX + 0x10),"script",-1);
  in_stack_00000070 = &QListData::shared_null;
  if (QListData::shared_null._4_4_ < 3) {
    if ((uint)QListData::shared_null < 2) {
      QListData::realloc((int)&stack0x00000070);
    }
    else {
      qlist_copyRefs(&stack0x00000070,3);
    }
  }
  _in_stack_00000018 = &stack0x00000070;
  qlist_str_append(_in_stack_00000018);
  qlist_str_append(_in_stack_00000018,unaff_RBX + 8);
  qlist_str_append(_in_stack_00000018);
  qt_byte_array_unref(unaff_RBX + 0x10);
  qt_byte_array_unref(unaff_RBX + 8);
  qt_byte_array_unref();
  FUN_0067dffe(_in_stack_00000018);
  pQVar10 = (QByteArray *)(in_stack_00000070 + (long)*(int *)(in_stack_00000070 + 1) + 2);
  FUN_0067dffe(_in_stack_00000018);
  pQVar1 = (QByteArray *)(in_stack_00000070 + (long)*(int *)((long)in_stack_00000070 + 0xc) + 2);
  for (; pQVar10 != pQVar1; pQVar10 = pQVar10 + 8) {
    lVar6 = *(long *)pQVar10;
    pcVar5 = (char *)(lVar6 + *(long *)(lVar6 + 0x10));
    if (((pcVar5 == (char *)0x0) || (*(int *)(lVar6 + 4) == 0)) || (*pcVar5 == '\0')) {
      iVar8 = 0;
    }
    else {
      pcVar7 = pcVar5 + 1;
      do {
        iVar8 = (1 - (int)(pcVar5 + 1)) + (int)pcVar7;
        if (pcVar7 == pcVar5 + (ulong)(*(int *)(lVar6 + 4) - 1) + 1) break;
        cVar3 = *pcVar7;
        pcVar7 = pcVar7 + 1;
      } while (cVar3 != '\0');
    }
    in_stack_000000f0 = (undefined1 *)QString::fromAscii_helper(pcVar5,iVar8);
    lVar6 = qmap_lower_bound_find(*unaff_R15);
    qt_array_data_unref();
    if (lVar6 != 0) {
      in_stack_000000b0 = 0;
      in_stack_000000b8 = 0x80000000;
      lVar6 = *(long *)pQVar10;
      pcVar5 = (char *)(lVar6 + *(long *)(lVar6 + 0x10));
      if (((pcVar5 != (char *)0x0) && (*(int *)(lVar6 + 4) != 0)) && (*pcVar5 != '\0')) {
        pcVar7 = pcVar5 + 1;
        goto LAB_00678779;
      }
      iVar8 = 0;
      goto LAB_00678781;
    }
  }
  goto LAB_00678588;
  while (cVar3 = *pcVar7, pcVar7 = pcVar7 + 1, cVar3 != '\0') {
LAB_00678779:
    iVar8 = (1 - (int)(pcVar5 + 1)) + (int)pcVar7;
    if (pcVar7 == pcVar5 + (ulong)(*(int *)(lVar6 + 4) - 1) + 1) break;
  }
LAB_00678781:
  in_stack_00000078 = QString::fromAscii_helper(pcVar5,iVar8);
  lVar6 = qmap_lower_bound_find(*unaff_R15,&stack0x00000078);
  pQVar9 = in_stack_00000030;
  if (lVar6 != 0) {
    pQVar9 = (QVariant *)(lVar6 + 0x20);
  }
  QVariant::QVariant(in_stack_00000008,pQVar9);
  QVariant::toByteArray();
  QByteArray::trimmed_helper((QByteArray *)&stack0x00000088);
  QVariant::QVariant(unaff_R12,(QByteArray *)&stack0x00000088);
  in_stack_000000f0 = *(undefined1 **)(in_stack_000000a0 + 0x20);
  in_stack_000000f8 = *(undefined4 *)(in_stack_000000a0 + 0x28);
  *(undefined1 **)(in_stack_000000a0 + 0x20) = in_stack_000000d0;
  *(undefined4 *)(in_stack_000000a0 + 0x28) = in_stack_000000d8;
  in_stack_000000d0 = in_stack_000000f0;
  in_stack_000000d8 = in_stack_000000f8;
  QVariant::~QVariant(unaff_R12);
  qt_byte_array_unref((QByteArray *)&stack0x00000088);
  qt_byte_array_unref(&stack0x00000080);
  QVariant::~QVariant(in_stack_00000008);
  qt_array_data_unref(&stack0x00000078);
  QVariant::~QVariant(in_stack_00000030);
  iVar8 = qstrcmp(pQVar10,"action");
  if (iVar8 == 0) {
    cVar3 = '\0';
  }
  else {
    iVar8 = qstrcmp(pQVar10,"map");
    cVar3 = (iVar8 != 0) + '\x01';
  }
  *(char *)(in_stack_000000a0 + 0x18) = cVar3;
LAB_00678588:
  in_stack_000000d0 = (undefined1 *)0x0;
  in_stack_000000d8 = 0x80000000;
  qstring_assign_from_ascii(in_stack_00000008,&DAT_00c91ca5);
  lVar6 = qmap_lower_bound_find(*unaff_R15,in_stack_00000008);
  pQVar9 = unaff_R12;
  if (lVar6 != 0) {
    pQVar9 = (QVariant *)(lVar6 + 0x20);
  }
  QVariant::QVariant((QVariant *)unaff_RBX,pQVar9);
  QVariant::operator=((QVariant *)(in_stack_000000a0 + 0x30),(QVariant *)unaff_RBX);
  QVariant::~QVariant((QVariant *)unaff_RBX);
  qt_array_data_unref(in_stack_00000008);
  QVariant::~QVariant(unaff_R12);
  QVariant::QVariant(unaff_R12,false);
  qstring_assign_from_ascii(in_stack_00000008,"repeatable");
  lVar6 = qmap_lower_bound_find(*unaff_R15,in_stack_00000008);
  pQVar9 = unaff_R12;
  if (lVar6 != 0) {
    pQVar9 = (QVariant *)(lVar6 + 0x20);
  }
  QVariant::QVariant((QVariant *)unaff_RBX,pQVar9);
  uVar2 = QVariant::toBool();
  *(undefined1 *)(in_stack_000000a0 + 0x10) = uVar2;
  QVariant::~QVariant((QVariant *)unaff_RBX);
  qt_array_data_unref(in_stack_00000008);
  QVariant::~QVariant(unaff_R12);
  QVariant::toByteArray();
  iVar8 = *(int *)(in_stack_000000f0 + 4);
  qt_byte_array_unref();
  if (iVar8 != 0) {
    FUN_0067db40(in_stack_00000010 + 0x10);
    FUN_0067de60(*(long *)(in_stack_00000010 + 0x10) + (long)in_stack_00000020._7_1_ * 8 +
                 *(long *)(*(long *)(in_stack_00000010 + 0x10) + 0x10),&stack0x000000a0);
  }
  qatomic_unref_call_deleter2(_in_stack_00000018);
LAB_006780b2:
  qt_shared_data_unref(in_stack_00000038);
  if (in_stack_000000a8 != (_Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *)0x0) {
    std::_Sp_counted_base<(__gnu_cxx::_Lock_policy)2>::_M_release(in_stack_000000a8);
  }
  qt_array_data_unref();
  return;
}


// ==== entry=004d9909 name=FUN_004d9909 size=37 ====

void FUN_004d9909(void)

{
  QByteArray *pQVar1;
  undefined1 uVar2;
  char cVar3;
  long *plVar4;
  char *pcVar5;
  long lVar6;
  char *pcVar7;
  string *unaff_RBX;
  int iVar8;
  QVariant *pQVar9;
  QVariant *unaff_R12;
  QByteArray *pQVar10;
  long unaff_R14;
  undefined8 *unaff_R15;
  locale *unaff_retaddr;
  QVariant *in_stack_00000008;
  long in_stack_00000010;
  char in_stack_00000018;
  undefined8 in_stack_00000020;
  QVariant *in_stack_00000030;
  undefined8 in_stack_00000038;
  undefined8 *in_stack_00000070;
  undefined8 in_stack_00000078;
  long in_stack_000000a0;
  _Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *in_stack_000000a8;
  undefined8 in_stack_000000b0;
  undefined4 in_stack_000000b8;
  long in_stack_000000c0;
  undefined1 *in_stack_000000d0;
  undefined4 in_stack_000000d8;
  undefined1 *in_stack_000000f0;
  undefined4 in_stack_000000f8;
  long in_stack_00000128;
  undefined8 in_stack_00000140;
  
  FUN_0067fb80(unaff_RBX + 0x40,in_stack_00000140);
  if (in_stack_00000128 != 0) {
    refcounted_vt_destroy();
  }
  std::locale::~locale((locale *)(unaff_RBX + 0x10));
  std::locale::~locale(unaff_retaddr);
  if (unaff_R14 != 1) {
    if (in_stack_000000c0 != 0) {
      tree_node_release();
    }
    qt_shared_data_unref(in_stack_00000038);
    if (in_stack_000000a8 != (_Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *)0x0) {
      std::_Sp_counted_base<(__gnu_cxx::_Lock_policy)2>::_M_release(in_stack_000000a8);
    }
    qt_array_data_unref();
                    /* WARNING: Subroutine does not return */
    cxa_throw_exception();
  }
  plVar4 = (long *)__cxa_begin_catch();
  pcVar5 = (char *)(**(code **)(*plVar4 + 0x10))(plVar4);
  std::string::string(unaff_RBX,pcVar5,(allocator *)unaff_R12);
  if (in_stack_000000f0 != &DAT_011c5338) {
    FUN_00673ea0();
  }
  __cxa_end_catch();
  FUN_00687320(in_stack_000000a0 + 8,in_stack_00000008);
  if (in_stack_000000c0 != 0) {
    tree_node_release();
  }
  if (in_stack_00000018 == '\0') goto LAB_006780b2;
  QByteArray::QByteArray((QByteArray *)unaff_RBX,"action",-1);
  QByteArray::QByteArray((QByteArray *)(unaff_RBX + 8),"map",-1);
  QByteArray::QByteArray((QByteArray *)(unaff_RBX + 0x10),"script",-1);
  in_stack_00000070 = &QListData::shared_null;
  if (QListData::shared_null._4_4_ < 3) {
    if ((uint)QListData::shared_null < 2) {
      QListData::realloc((int)&stack0x00000070);
    }
    else {
      qlist_copyRefs(&stack0x00000070,3);
    }
  }
  _in_stack_00000018 = &stack0x00000070;
  qlist_str_append(_in_stack_00000018);
  qlist_str_append(_in_stack_00000018,unaff_RBX + 8);
  qlist_str_append(_in_stack_00000018);
  qt_byte_array_unref(unaff_RBX + 0x10);
  qt_byte_array_unref(unaff_RBX + 8);
  qt_byte_array_unref();
  FUN_0067dffe(_in_stack_00000018);
  pQVar10 = (QByteArray *)(in_stack_00000070 + (long)*(int *)(in_stack_00000070 + 1) + 2);
  FUN_0067dffe(_in_stack_00000018);
  pQVar1 = (QByteArray *)(in_stack_00000070 + (long)*(int *)((long)in_stack_00000070 + 0xc) + 2);
  for (; pQVar10 != pQVar1; pQVar10 = pQVar10 + 8) {
    lVar6 = *(long *)pQVar10;
    pcVar5 = (char *)(lVar6 + *(long *)(lVar6 + 0x10));
    if (((pcVar5 == (char *)0x0) || (*(int *)(lVar6 + 4) == 0)) || (*pcVar5 == '\0')) {
      iVar8 = 0;
    }
    else {
      pcVar7 = pcVar5 + 1;
      do {
        iVar8 = (1 - (int)(pcVar5 + 1)) + (int)pcVar7;
        if (pcVar7 == pcVar5 + (ulong)(*(int *)(lVar6 + 4) - 1) + 1) break;
        cVar3 = *pcVar7;
        pcVar7 = pcVar7 + 1;
      } while (cVar3 != '\0');
    }
    in_stack_000000f0 = (undefined1 *)QString::fromAscii_helper(pcVar5,iVar8);
    lVar6 = qmap_lower_bound_find(*unaff_R15);
    qt_array_data_unref();
    if (lVar6 != 0) {
      in_stack_000000b0 = 0;
      in_stack_000000b8 = 0x80000000;
      lVar6 = *(long *)pQVar10;
      pcVar5 = (char *)(lVar6 + *(long *)(lVar6 + 0x10));
      if (((pcVar5 != (char *)0x0) && (*(int *)(lVar6 + 4) != 0)) && (*pcVar5 != '\0')) {
        pcVar7 = pcVar5 + 1;
        goto LAB_00678779;
      }
      iVar8 = 0;
      goto LAB_00678781;
    }
  }
  goto LAB_00678588;
  while (cVar3 = *pcVar7, pcVar7 = pcVar7 + 1, cVar3 != '\0') {
LAB_00678779:
    iVar8 = (1 - (int)(pcVar5 + 1)) + (int)pcVar7;
    if (pcVar7 == pcVar5 + (ulong)(*(int *)(lVar6 + 4) - 1) + 1) break;
  }
LAB_00678781:
  in_stack_00000078 = QString::fromAscii_helper(pcVar5,iVar8);
  lVar6 = qmap_lower_bound_find(*unaff_R15,&stack0x00000078);
  pQVar9 = in_stack_00000030;
  if (lVar6 != 0) {
    pQVar9 = (QVariant *)(lVar6 + 0x20);
  }
  QVariant::QVariant(in_stack_00000008,pQVar9);
  QVariant::toByteArray();
  QByteArray::trimmed_helper((QByteArray *)&stack0x00000088);
  QVariant::QVariant(unaff_R12,(QByteArray *)&stack0x00000088);
  in_stack_000000f0 = *(undefined1 **)(in_stack_000000a0 + 0x20);
  in_stack_000000f8 = *(undefined4 *)(in_stack_000000a0 + 0x28);
  *(undefined1 **)(in_stack_000000a0 + 0x20) = in_stack_000000d0;
  *(undefined4 *)(in_stack_000000a0 + 0x28) = in_stack_000000d8;
  in_stack_000000d0 = in_stack_000000f0;
  in_stack_000000d8 = in_stack_000000f8;
  QVariant::~QVariant(unaff_R12);
  qt_byte_array_unref((QByteArray *)&stack0x00000088);
  qt_byte_array_unref(&stack0x00000080);
  QVariant::~QVariant(in_stack_00000008);
  qt_array_data_unref(&stack0x00000078);
  QVariant::~QVariant(in_stack_00000030);
  iVar8 = qstrcmp(pQVar10,"action");
  if (iVar8 == 0) {
    cVar3 = '\0';
  }
  else {
    iVar8 = qstrcmp(pQVar10,"map");
    cVar3 = (iVar8 != 0) + '\x01';
  }
  *(char *)(in_stack_000000a0 + 0x18) = cVar3;
LAB_00678588:
  in_stack_000000d0 = (undefined1 *)0x0;
  in_stack_000000d8 = 0x80000000;
  qstring_assign_from_ascii(in_stack_00000008,&DAT_00c91ca5);
  lVar6 = qmap_lower_bound_find(*unaff_R15,in_stack_00000008);
  pQVar9 = unaff_R12;
  if (lVar6 != 0) {
    pQVar9 = (QVariant *)(lVar6 + 0x20);
  }
  QVariant::QVariant((QVariant *)unaff_RBX,pQVar9);
  QVariant::operator=((QVariant *)(in_stack_000000a0 + 0x30),(QVariant *)unaff_RBX);
  QVariant::~QVariant((QVariant *)unaff_RBX);
  qt_array_data_unref(in_stack_00000008);
  QVariant::~QVariant(unaff_R12);
  QVariant::QVariant(unaff_R12,false);
  qstring_assign_from_ascii(in_stack_00000008,"repeatable");
  lVar6 = qmap_lower_bound_find(*unaff_R15,in_stack_00000008);
  pQVar9 = unaff_R12;
  if (lVar6 != 0) {
    pQVar9 = (QVariant *)(lVar6 + 0x20);
  }
  QVariant::QVariant((QVariant *)unaff_RBX,pQVar9);
  uVar2 = QVariant::toBool();
  *(undefined1 *)(in_stack_000000a0 + 0x10) = uVar2;
  QVariant::~QVariant((QVariant *)unaff_RBX);
  qt_array_data_unref(in_stack_00000008);
  QVariant::~QVariant(unaff_R12);
  QVariant::toByteArray();
  iVar8 = *(int *)(in_stack_000000f0 + 4);
  qt_byte_array_unref();
  if (iVar8 != 0) {
    FUN_0067db40(in_stack_00000010 + 0x10);
    FUN_0067de60(*(long *)(in_stack_00000010 + 0x10) + (long)in_stack_00000020._7_1_ * 8 +
                 *(long *)(*(long *)(in_stack_00000010 + 0x10) + 0x10),&stack0x000000a0);
  }
  qatomic_unref_call_deleter2(_in_stack_00000018);
LAB_006780b2:
  qt_shared_data_unref(in_stack_00000038);
  if (in_stack_000000a8 != (_Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *)0x0) {
    std::_Sp_counted_base<(__gnu_cxx::_Lock_policy)2>::_M_release(in_stack_000000a8);
  }
  qt_array_data_unref();
  return;
}


// ==== entry=004d992e name=FUN_004d992e size=53 ====

void FUN_004d992e(undefined8 param_1,undefined8 param_2,long param_3)

{
  QByteArray *pQVar1;
  undefined1 uVar2;
  char cVar3;
  long *plVar4;
  char *pcVar5;
  long lVar6;
  char *pcVar7;
  string *unaff_RBX;
  int iVar8;
  QVariant *pQVar9;
  QVariant *unaff_R12;
  QByteArray *pQVar10;
  locale *unaff_R14;
  undefined8 *unaff_R15;
  locale *unaff_retaddr;
  QVariant *in_stack_00000008;
  long in_stack_00000010;
  char in_stack_00000018;
  undefined8 in_stack_00000020;
  locale *in_stack_00000028;
  QVariant *in_stack_00000030;
  undefined8 in_stack_00000038;
  long lStack0000000000000040;
  undefined8 *in_stack_00000070;
  undefined8 in_stack_00000078;
  long in_stack_000000a0;
  _Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *in_stack_000000a8;
  undefined8 in_stack_000000b0;
  undefined4 in_stack_000000b8;
  long in_stack_000000c0;
  undefined1 *in_stack_000000d0;
  undefined4 in_stack_000000d8;
  undefined1 *in_stack_000000f0;
  undefined4 in_stack_000000f8;
  
  lStack0000000000000040 = param_3;
  std::locale::~locale(in_stack_00000028);
  std::locale::~locale((locale *)unaff_RBX);
  std::locale::~locale(unaff_retaddr);
  std::locale::~locale(unaff_R14);
  if (lStack0000000000000040 != 1) {
    if (in_stack_000000c0 != 0) {
      tree_node_release();
    }
    qt_shared_data_unref(in_stack_00000038);
    if (in_stack_000000a8 != (_Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *)0x0) {
      std::_Sp_counted_base<(__gnu_cxx::_Lock_policy)2>::_M_release(in_stack_000000a8);
    }
    qt_array_data_unref();
                    /* WARNING: Subroutine does not return */
    cxa_throw_exception();
  }
  plVar4 = (long *)__cxa_begin_catch();
  pcVar5 = (char *)(**(code **)(*plVar4 + 0x10))(plVar4);
  std::string::string(unaff_RBX,pcVar5,(allocator *)unaff_R12);
  if (in_stack_000000f0 != &DAT_011c5338) {
    FUN_00673ea0();
  }
  __cxa_end_catch();
  FUN_00687320(in_stack_000000a0 + 8,in_stack_00000008);
  if (in_stack_000000c0 != 0) {
    tree_node_release();
  }
  if (in_stack_00000018 == '\0') goto LAB_006780b2;
  QByteArray::QByteArray((QByteArray *)unaff_RBX,"action",-1);
  QByteArray::QByteArray((QByteArray *)(unaff_RBX + 8),"map",-1);
  QByteArray::QByteArray((QByteArray *)(unaff_RBX + 0x10),"script",-1);
  in_stack_00000070 = &QListData::shared_null;
  if (QListData::shared_null._4_4_ < 3) {
    if ((uint)QListData::shared_null < 2) {
      QListData::realloc((int)&stack0x00000070);
    }
    else {
      qlist_copyRefs(&stack0x00000070,3);
    }
  }
  _in_stack_00000018 = &stack0x00000070;
  qlist_str_append(_in_stack_00000018);
  qlist_str_append(_in_stack_00000018,unaff_RBX + 8);
  qlist_str_append(_in_stack_00000018);
  qt_byte_array_unref(unaff_RBX + 0x10);
  qt_byte_array_unref(unaff_RBX + 8);
  qt_byte_array_unref();
  FUN_0067dffe(_in_stack_00000018);
  pQVar10 = (QByteArray *)(in_stack_00000070 + (long)*(int *)(in_stack_00000070 + 1) + 2);
  FUN_0067dffe(_in_stack_00000018);
  pQVar1 = (QByteArray *)(in_stack_00000070 + (long)*(int *)((long)in_stack_00000070 + 0xc) + 2);
  for (; pQVar10 != pQVar1; pQVar10 = pQVar10 + 8) {
    lVar6 = *(long *)pQVar10;
    pcVar5 = (char *)(lVar6 + *(long *)(lVar6 + 0x10));
    if (((pcVar5 == (char *)0x0) || (*(int *)(lVar6 + 4) == 0)) || (*pcVar5 == '\0')) {
      iVar8 = 0;
    }
    else {
      pcVar7 = pcVar5 + 1;
      do {
        iVar8 = (1 - (int)(pcVar5 + 1)) + (int)pcVar7;
        if (pcVar7 == pcVar5 + (ulong)(*(int *)(lVar6 + 4) - 1) + 1) break;
        cVar3 = *pcVar7;
        pcVar7 = pcVar7 + 1;
      } while (cVar3 != '\0');
    }
    in_stack_000000f0 = (undefined1 *)QString::fromAscii_helper(pcVar5,iVar8);
    lVar6 = qmap_lower_bound_find(*unaff_R15);
    qt_array_data_unref();
    if (lVar6 != 0) {
      in_stack_000000b0 = 0;
      in_stack_000000b8 = 0x80000000;
      lVar6 = *(long *)pQVar10;
      pcVar5 = (char *)(lVar6 + *(long *)(lVar6 + 0x10));
      if (((pcVar5 != (char *)0x0) && (*(int *)(lVar6 + 4) != 0)) && (*pcVar5 != '\0')) {
        pcVar7 = pcVar5 + 1;
        goto LAB_00678779;
      }
      iVar8 = 0;
      goto LAB_00678781;
    }
  }
  goto LAB_00678588;
  while (cVar3 = *pcVar7, pcVar7 = pcVar7 + 1, cVar3 != '\0') {
LAB_00678779:
    iVar8 = (1 - (int)(pcVar5 + 1)) + (int)pcVar7;
    if (pcVar7 == pcVar5 + (ulong)(*(int *)(lVar6 + 4) - 1) + 1) break;
  }
LAB_00678781:
  in_stack_00000078 = QString::fromAscii_helper(pcVar5,iVar8);
  lVar6 = qmap_lower_bound_find(*unaff_R15,&stack0x00000078);
  pQVar9 = in_stack_00000030;
  if (lVar6 != 0) {
    pQVar9 = (QVariant *)(lVar6 + 0x20);
  }
  QVariant::QVariant(in_stack_00000008,pQVar9);
  QVariant::toByteArray();
  QByteArray::trimmed_helper((QByteArray *)&stack0x00000088);
  QVariant::QVariant(unaff_R12,(QByteArray *)&stack0x00000088);
  in_stack_000000f0 = *(undefined1 **)(in_stack_000000a0 + 0x20);
  in_stack_000000f8 = *(undefined4 *)(in_stack_000000a0 + 0x28);
  *(undefined1 **)(in_stack_000000a0 + 0x20) = in_stack_000000d0;
  *(undefined4 *)(in_stack_000000a0 + 0x28) = in_stack_000000d8;
  in_stack_000000d0 = in_stack_000000f0;
  in_stack_000000d8 = in_stack_000000f8;
  QVariant::~QVariant(unaff_R12);
  qt_byte_array_unref((QByteArray *)&stack0x00000088);
  qt_byte_array_unref(&stack0x00000080);
  QVariant::~QVariant(in_stack_00000008);
  qt_array_data_unref(&stack0x00000078);
  QVariant::~QVariant(in_stack_00000030);
  iVar8 = qstrcmp(pQVar10,"action");
  if (iVar8 == 0) {
    cVar3 = '\0';
  }
  else {
    iVar8 = qstrcmp(pQVar10,"map");
    cVar3 = (iVar8 != 0) + '\x01';
  }
  *(char *)(in_stack_000000a0 + 0x18) = cVar3;
LAB_00678588:
  in_stack_000000d0 = (undefined1 *)0x0;
  in_stack_000000d8 = 0x80000000;
  qstring_assign_from_ascii(in_stack_00000008,&DAT_00c91ca5);
  lVar6 = qmap_lower_bound_find(*unaff_R15,in_stack_00000008);
  pQVar9 = unaff_R12;
  if (lVar6 != 0) {
    pQVar9 = (QVariant *)(lVar6 + 0x20);
  }
  QVariant::QVariant((QVariant *)unaff_RBX,pQVar9);
  QVariant::operator=((QVariant *)(in_stack_000000a0 + 0x30),(QVariant *)unaff_RBX);
  QVariant::~QVariant((QVariant *)unaff_RBX);
  qt_array_data_unref(in_stack_00000008);
  QVariant::~QVariant(unaff_R12);
  QVariant::QVariant(unaff_R12,false);
  qstring_assign_from_ascii(in_stack_00000008,"repeatable");
  lVar6 = qmap_lower_bound_find(*unaff_R15,in_stack_00000008);
  pQVar9 = unaff_R12;
  if (lVar6 != 0) {
    pQVar9 = (QVariant *)(lVar6 + 0x20);
  }
  QVariant::QVariant((QVariant *)unaff_RBX,pQVar9);
  uVar2 = QVariant::toBool();
  *(undefined1 *)(in_stack_000000a0 + 0x10) = uVar2;
  QVariant::~QVariant((QVariant *)unaff_RBX);
  qt_array_data_unref(in_stack_00000008);
  QVariant::~QVariant(unaff_R12);
  QVariant::toByteArray();
  iVar8 = *(int *)(in_stack_000000f0 + 4);
  qt_byte_array_unref();
  if (iVar8 != 0) {
    FUN_0067db40(in_stack_00000010 + 0x10);
    FUN_0067de60(*(long *)(in_stack_00000010 + 0x10) + (long)in_stack_00000020._7_1_ * 8 +
                 *(long *)(*(long *)(in_stack_00000010 + 0x10) + 0x10),&stack0x000000a0);
  }
  qatomic_unref_call_deleter2(_in_stack_00000018);
LAB_006780b2:
  qt_shared_data_unref(in_stack_00000038);
  if (in_stack_000000a8 != (_Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *)0x0) {
    std::_Sp_counted_base<(__gnu_cxx::_Lock_policy)2>::_M_release(in_stack_000000a8);
  }
  qt_array_data_unref();
  return;
}


// ==== entry=004d9963 name=FUN_004d9963 size=43 ====

void FUN_004d9963(void)

{
  QVariant *unaff_RBX;
  QVariant *unaff_retaddr;
  undefined8 in_stack_00000008;
  _Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *in_stack_000000a8;
  
  qt_array_data_unref();
  QVariant::~QVariant(unaff_RBX);
  qt_array_data_unref(in_stack_00000008);
  QVariant::~QVariant(unaff_retaddr);
  if (in_stack_000000a8 != (_Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *)0x0) {
    std::_Sp_counted_base<(__gnu_cxx::_Lock_policy)2>::_M_release(in_stack_000000a8);
  }
  qt_array_data_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d998e name=FUN_004d998e size=36 ====

void FUN_004d998e(void)

{
  QVariant *unaff_RBX;
  QVariant *unaff_retaddr;
  
  QVariant::~QVariant(unaff_RBX);
  qt_array_data_unref();
  QVariant::~QVariant(unaff_retaddr);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d99b2 name=FUN_004d99b2 size=16 ====

void FUN_004d99b2(void)

{
  _Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *in_stack_000000a8;
  
  qt_array_data_unref();
  if (in_stack_000000a8 != (_Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *)0x0) {
    std::_Sp_counted_base<(__gnu_cxx::_Lock_policy)2>::_M_release(in_stack_000000a8);
  }
  qt_array_data_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d99c2 name=FUN_004d99c2 size=16 ====

void FUN_004d99c2(void)

{
  qmap_freetree_variant_nodes();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d99d2 name=FUN_004d99d2 size=22 ====

void FUN_004d99d2(void)

{
  long unaff_R14;
  
  if (unaff_R14 != 0) {
    qslotobject_release_destroy2(unaff_R14 + 8);
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d99e8 name=FUN_004d99e8 size=21 ====

void FUN_004d99e8(void)

{
  FUN_0068175e(&stack0x00000090);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d99fd name=FUN_004d99fd size=22 ====

void FUN_004d99fd(void)

{
  long unaff_R14;
  
  if (unaff_R14 != 0) {
    qslotobject_release_destroy2(unaff_R14 + 8);
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d9a20 name=FUN_004d9a20 size=16 ====

void FUN_004d9a20(void)

{
  qt_array_data_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d9a30 name=FUN_004d9a30 size=21 ====

void FUN_004d9a30(void)

{
  void *unaff_RBX;
  
  operator_delete(unaff_RBX,0x48);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d9a45 name=FUN_004d9a45 size=24 ====

void FUN_004d9a45(void)

{
  qt_array_data_unref();
  qt_array_data_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d9a5d name=FUN_004d9a5d size=16 ====

void FUN_004d9a5d(void)

{
  qt_array_data_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d9a6e name=FUN_004d9a6e size=16 ====

void FUN_004d9a6e(void)

{
  qt_byte_array_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d9a7e name=FUN_004d9a7e size=18 ====

void FUN_004d9a7e(void)

{
  undefined8 in_stack_00000028;
  
  qt_byte_array_unref(in_stack_00000028);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d9a90 name=FUN_004d9a90 size=29 ====

void FUN_004d9a90(void)

{
  void *unaff_RBX;
  
  operator_delete(unaff_RBX,0x30);
  qt_array_data_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d9aae name=FUN_004d9aae size=29 ====

void FUN_004d9aae(void)

{
  void *unaff_RBX;
  
  operator_delete(unaff_RBX,0x30);
  qt_array_data_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d9acc name=FUN_004d9acc size=24 ====

void FUN_004d9acc(void)

{
  qt_array_data_unref();
  qt_array_data_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d9ae4 name=FUN_004d9ae4 size=16 ====

void FUN_004d9ae4(void)

{
  qt_array_data_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d9af4 name=FUN_004d9af4 size=21 ====

void FUN_004d9af4(void)

{
  void *unaff_RBX;
  
  operator_delete(unaff_RBX,0x30);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d9b0a name=FUN_004d9b0a size=16 ====

void FUN_004d9b0a(void)

{
  qt_byte_array_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d9b1a name=FUN_004d9b1a size=16 ====

void FUN_004d9b1a(void)

{
  QVariant *unaff_R12;
  
  QVariant::~QVariant(unaff_R12);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d9b2a name=FUN_004d9b2a size=16 ====

void FUN_004d9b2a(void)

{
  qatomic_unref_call_deleter();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d9b3a name=FUN_004d9b3a size=31 ====

void FUN_004d9b3a(void)

{
  void *unaff_R12;
  undefined8 in_stack_00000058;
  
  operator_delete(unaff_R12,0x30);
  qt_byte_array_unref(in_stack_00000058);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d9b59 name=FUN_004d9b59 size=15 ====

void FUN_004d9b59(void)

{
  void *unaff_R13;
  undefined8 in_stack_00000058;
  
  operator_delete(unaff_R13,0x30);
  qt_byte_array_unref(in_stack_00000058);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d9b68 name=FUN_004d9b68 size=23 ====

void FUN_004d9b68(void)

{
  undefined8 in_stack_00000040;
  undefined8 in_stack_00000058;
  
  qlist_disposeIfShared4(in_stack_00000040);
  qt_array_data_unref();
  qt_byte_array_unref(in_stack_00000058);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d9b7f name=FUN_004d9b7f size=13 ====

void FUN_004d9b7f(void)

{
  undefined8 in_stack_00000058;
  
  qt_array_data_unref();
  qt_byte_array_unref(in_stack_00000058);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d9b8c name=FUN_004d9b8c size=38 ====

void FUN_004d9b8c(void)

{
  void *unaff_R14;
  undefined8 in_stack_00000050;
  undefined8 in_stack_00000058;
  
  operator_delete(unaff_R14,0x30);
  qt_array_data_unref(in_stack_00000050);
  qt_byte_array_unref(&stack0x000000b0);
  qt_byte_array_unref(in_stack_00000058);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d9bb2 name=FUN_004d9bb2 size=12 ====

void FUN_004d9bb2(void)

{
  undefined8 in_stack_00000040;
  undefined8 in_stack_00000058;
  
  qlist_disposeIfShared4(in_stack_00000040);
  qt_byte_array_unref(in_stack_00000058);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d9bbe name=FUN_004d9bbe size=13 ====

void FUN_004d9bbe(void)

{
  QVariant *unaff_R12;
  undefined8 in_stack_00000058;
  
  QVariant::~QVariant(unaff_R12);
  qt_byte_array_unref(in_stack_00000058);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d9bcb name=FUN_004d9bcb size=16 ====

void FUN_004d9bcb(void)

{
  FUN_00694c00();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d9bdb name=FUN_004d9bdb size=24 ====

void FUN_004d9bdb(void)

{
  FUN_00694c00();
  qt_array_data_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d9bf3 name=FUN_004d9bf3 size=10 ====

void FUN_004d9bf3(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ==== entry=004d9bfd name=FUN_004d9bfd size=23 ====

void FUN_004d9bfd(void)

{
  void *in_stack_00000030;
  
  operator_delete(in_stack_00000030,0x20);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d9c14 name=FUN_004d9c14 size=18 ====

void FUN_004d9c14(void)

{
  void *unaff_R14;
  undefined8 in_stack_00000058;
  
  operator_delete(unaff_R14,0x30);
  qt_byte_array_unref(in_stack_00000058);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d9c26 name=FUN_004d9c26 size=16 ====

void FUN_004d9c26(void)

{
  QVariant *unaff_R12;
  
  QVariant::~QVariant(unaff_R12);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d9c36 name=FUN_004d9c36 size=16 ====

void FUN_004d9c36(void)

{
  atomic_refptr_delete();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d9c46 name=FUN_004d9c46 size=31 ====

void FUN_004d9c46(void)

{
  void *unaff_R14;
  undefined8 in_stack_00000028;
  
  operator_delete(unaff_R14,0x48);
  qlist_ref_release2(in_stack_00000028);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d9c65 name=FUN_004d9c65 size=10 ====

void FUN_004d9c65(void)

{
  undefined8 in_stack_00000028;
  
  qlist_ref_release2();
  qlist_ref_release2(in_stack_00000028);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d9c6f name=FUN_004d9c6f size=15 ====

void FUN_004d9c6f(void)

{
  void *unaff_R14;
  undefined8 in_stack_00000028;
  
  operator_delete(unaff_R14,0x80);
  qlist_ref_release2(in_stack_00000028);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d9c7e name=FUN_004d9c7e size=17 ====

void FUN_004d9c7e(void)

{
  undefined8 in_stack_00000028;
  void *in_stack_00000040;
  
  operator_delete(in_stack_00000040,0x30);
  qlist_ref_release2(in_stack_00000028);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d9c8f name=FUN_004d9c8f size=43 ====

void FUN_004d9c8f(void)

{
  undefined8 in_stack_00000028;
  
  atomic_refptr_delete();
  atomic_refptr_delete(&stack0x00000080);
  atomic_refptr_delete(&stack0x00000070);
  atomic_refptr_delete(&stack0x00000060);
  qlist_ref_release2(in_stack_00000028);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d9cba name=FUN_004d9cba size=23 ====

void FUN_004d9cba(void)

{
  void *unaff_R14;
  undefined8 in_stack_00000028;
  
  operator_delete(unaff_R14,0x30);
  qt_array_data_unref();
  qlist_ref_release2(in_stack_00000028);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d9cd1 name=FUN_004d9cd1 size=10 ====

void FUN_004d9cd1(void)

{
  QVariant *unaff_R15;
  undefined8 in_stack_00000028;
  
  QVariant::~QVariant(unaff_R15);
  atomic_refptr_delete(&stack0x00000060);
  qlist_ref_release2(in_stack_00000028);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d9cdb name=FUN_004d9cdb size=10 ====

void FUN_004d9cdb(void)

{
  QVariant *unaff_R15;
  undefined8 in_stack_00000028;
  
  QVariant::~QVariant(unaff_R15);
  atomic_refptr_delete(&stack0x00000060);
  qlist_ref_release2(in_stack_00000028);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d9ce5 name=FUN_004d9ce5 size=16 ====

void FUN_004d9ce5(void)

{
  undefined8 in_stack_00000028;
  
  qt_array_data_unref();
  qlist_ref_release2(in_stack_00000028);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d9cf5 name=FUN_004d9cf5 size=18 ====

void FUN_004d9cf5(void)

{
  void *unaff_R12;
  undefined8 in_stack_00000028;
  
  operator_delete(unaff_R12,0x30);
  qlist_ref_release2(in_stack_00000028);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d9d07 name=FUN_004d9d07 size=11 ====

void FUN_004d9d07(void)

{
  undefined8 in_stack_00000028;
  
  qt_array_data_unref();
  qt_array_data_unref();
  qlist_ref_release2(in_stack_00000028);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d9d12 name=FUN_004d9d12 size=18 ====

void FUN_004d9d12(void)

{
  void *unaff_R14;
  undefined8 in_stack_00000028;
  
  operator_delete(unaff_R14,0x30);
  qlist_ref_release2(in_stack_00000028);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d9d30 name=FUN_004d9d30 size=12 ====

void FUN_004d9d30(void)

{
  long unaff_RBP;
  
  *(undefined1 *)(unaff_RBP + 0x10) = 0;
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d9d3c name=FUN_004d9d3c size=41 ====

void FUN_004d9d3c(void)

{
  if (DAT_011c1a50 == -1) {
    DAT_011c1a50 = -2;
  }
  __cxa_guard_abort(&DAT_011c1a08);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d9d66 name=FUN_004d9d66 size=12 ====

void FUN_004d9d66(void)

{
  long unaff_RBP;
  
  *(undefined1 *)(unaff_RBP + 0x10) = 0;
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d9d72 name=FUN_004d9d72 size=12 ====

void FUN_004d9d72(void)

{
  long unaff_RBX;
  
  *(undefined1 *)(unaff_RBX + 0x10) = 0;
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d9d7e name=FUN_004d9d7e size=12 ====

void FUN_004d9d7e(void)

{
  long unaff_RBX;
  
  *(undefined1 *)(unaff_RBX + 0x10) = 0;
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d9d8a name=FUN_004d9d8a size=12 ====

void FUN_004d9d8a(void)

{
  long unaff_RBX;
  
  *(undefined1 *)(unaff_RBX + 0x10) = 0;
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d9d96 name=FUN_004d9d96 size=15 ====

void FUN_004d9d96(void)

{
  long unaff_R12;
  
  *(undefined1 *)(unaff_R12 + 0x10) = 0;
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d9da6 name=FUN_004d9da6 size=44 ====

void FUN_004d9da6(void)

{
  int *piVar1;
  undefined8 *unaff_R13;
  
  piVar1 = (int *)*unaff_R13;
  if (*piVar1 != 0) {
    if (*piVar1 == -1) goto LAB_004d9db9;
    LOCK();
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if (*piVar1 != 0) goto LAB_004d9db9;
  }
  QListData::dispose((Data *)*unaff_R13);
LAB_004d9db9:
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d9dd2 name=FUN_004d9dd2 size=16 ====

void FUN_004d9dd2(void)

{
  qt_shared_data_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d9de2 name=FUN_004d9de2 size=29 ====

void FUN_004d9de2(void)

{
  long lVar1;
  long unaff_RBP;
  
  lVar1 = unaff_RBP + 0x28;
  do {
    lVar1 = lVar1 + -8;
    qt_array_data_unref(lVar1);
  } while (lVar1 != unaff_RBP);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d9e00 name=FUN_004d9e00 size=16 ====

void FUN_004d9e00(void)

{
  qt_shared_data_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d9e10 name=FUN_004d9e10 size=29 ====

void FUN_004d9e10(void)

{
  long lVar1;
  long unaff_RBP;
  
  lVar1 = unaff_RBP + 0x28;
  do {
    lVar1 = lVar1 + -8;
    qt_array_data_unref(lVar1);
  } while (lVar1 != unaff_RBP);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d9e30 name=FUN_004d9e30 size=48 ====

/* WARNING: Removing unreachable block (ram,0x004d9e4d) */

void FUN_004d9e30(undefined8 *param_1)

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


// ==== entry=004d9e60 name=FUN_004d9e60 size=21 ====

void FUN_004d9e60(void)

{
  void *unaff_RBX;
  
  operator_delete(unaff_RBX,0x28);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d9e76 name=FUN_004d9e76 size=24 ====

void FUN_004d9e76(void)

{
  json_value_destruct();
  json_value_destruct();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d9e8e name=FUN_004d9e8e size=10 ====

void FUN_004d9e8e(void)

{
  json_value_destruct();
  json_value_destruct();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d9e98 name=FUN_004d9e98 size=30 ====

void FUN_004d9e98(void)

{
  long in_stack_00000018;
  
  FUN_004d9e30(in_stack_00000018 + -0x18);
  json_value_destruct();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d9eb6 name=FUN_004d9eb6 size=16 ====

void FUN_004d9eb6(void)

{
  qt_array_data_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d9ec6 name=FUN_004d9ec6 size=35 ====

void FUN_004d9ec6(void)

{
  qt_array_data_unref();
  qt_array_data_unref();
  qt_array_data_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d9eea name=FUN_004d9eea size=40 ====

void FUN_004d9eea(void)

{
  qt_array_data_unref();
  qt_array_data_unref();
  qt_array_data_unref();
  qt_array_data_unref(&stack0x00000000);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d9f12 name=FUN_004d9f12 size=16 ====

void FUN_004d9f12(void)

{
  qt_array_data_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d9f22 name=FUN_004d9f22 size=16 ====

void FUN_004d9f22(void)

{
  qt_array_data_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d9f32 name=FUN_004d9f32 size=16 ====

void FUN_004d9f32(void)

{
  qt_array_data_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d9f42 name=FUN_004d9f42 size=24 ====

void FUN_004d9f42(void)

{
  qt_byte_array_unref();
  qt_array_data_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d9f5a name=FUN_004d9f5a size=24 ====

void FUN_004d9f5a(void)

{
  qt_array_data_unref();
  qt_byte_array_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d9f72 name=FUN_004d9f72 size=16 ====

void FUN_004d9f72(void)

{
  qt_byte_array_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d9f82 name=FUN_004d9f82 size=16 ====

void FUN_004d9f82(void)

{
  qt_byte_array_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d9f92 name=FUN_004d9f92 size=16 ====

void FUN_004d9f92(void)

{
  qt_array_data_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d9fa2 name=FUN_004d9fa2 size=16 ====

void FUN_004d9fa2(void)

{
  qt_array_data_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d9fb2 name=FUN_004d9fb2 size=43 ====

void FUN_004d9fb2(void)

{
  ConverterState *unaff_RBX;
  
  qt_byte_array_unref();
  QTextCodec::ConverterState::~ConverterState(unaff_RBX);
  qt_array_data_unref();
  qt_array_data_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d9fdd name=FUN_004d9fdd size=10 ====

void FUN_004d9fdd(void)

{
  qt_byte_array_unref();
  qt_array_data_unref();
  qt_array_data_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004d9fe8 name=FUN_004d9fe8 size=46 ====

void FUN_004d9fe8(void)

{
  long in_stack_00000010;
  
  qt_array_data_unref();
  FUN_004d9e30(in_stack_00000010 + -0x18);
  json_value_destruct();
  qt_shared_data_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004da016 name=FUN_004da016 size=85 ====

void FUN_004da016(void)

{
  QTextDecoder *this;
  QProcess *unaff_RBX;
  
  qt_byte_array_unref();
  __cxa_guard_abort();
  this = *(QTextDecoder **)(unaff_RBX + 0x28);
  if (this != (QTextDecoder *)0x0) {
    QTextDecoder::~QTextDecoder(this);
    operator_delete(this,0x28);
  }
  qt_array_data_unref(unaff_RBX + 0x20);
  if (*(_Sp_counted_base<(__gnu_cxx::_Lock_policy)2> **)(unaff_RBX + 0x18) !=
      (_Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *)0x0) {
    std::_Sp_counted_base<(__gnu_cxx::_Lock_policy)2>::_M_release
              (*(_Sp_counted_base<(__gnu_cxx::_Lock_policy)2> **)(unaff_RBX + 0x18));
  }
  QProcess::~QProcess(unaff_RBX);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004da06b name=FUN_004da06b size=18 ====

void FUN_004da06b(void)

{
  QTextDecoder *this;
  QProcess *unaff_RBX;
  
  qt_byte_array_unref();
  __cxa_guard_abort();
  this = *(QTextDecoder **)(unaff_RBX + 0x28);
  if (this != (QTextDecoder *)0x0) {
    QTextDecoder::~QTextDecoder(this);
    operator_delete(this,0x28);
  }
  qt_array_data_unref(unaff_RBX + 0x20);
  if (*(_Sp_counted_base<(__gnu_cxx::_Lock_policy)2> **)(unaff_RBX + 0x18) !=
      (_Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *)0x0) {
    std::_Sp_counted_base<(__gnu_cxx::_Lock_policy)2>::_M_release
              (*(_Sp_counted_base<(__gnu_cxx::_Lock_policy)2> **)(unaff_RBX + 0x18));
  }
  QProcess::~QProcess(unaff_RBX);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004da07e name=FUN_004da07e size=21 ====

void FUN_004da07e(void)

{
  char unaff_R12B;
  
  if (unaff_R12B != '\0') {
    qt_array_data_unref();
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004da094 name=FUN_004da094 size=16 ====

void FUN_004da094(void)

{
  void *unaff_RBP;
  
  operator_delete(unaff_RBP);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004da0a4 name=FUN_004da0a4 size=24 ====

void FUN_004da0a4(void)

{
  qt_array_data_unref();
  qt_array_data_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004da0bc name=FUN_004da0bc size=23 ====

void FUN_004da0bc(void)

{
  _Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *in_stack_00000018;
  
  if (in_stack_00000018 != (_Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *)0x0) {
    std::_Sp_counted_base<(__gnu_cxx::_Lock_policy)2>::_M_release(in_stack_00000018);
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004da0d4 name=FUN_004da0d4 size=62 ====

void FUN_004da0d4(void)

{
  undefined8 in_stack_00000020;
  undefined8 in_stack_00000028;
  undefined8 in_stack_00000030;
  
  qt_array_data_unref();
  qt_array_data_unref();
  qt_shared_data_unref(in_stack_00000020);
  qt_shared_data_unref(in_stack_00000028);
  qt_array_data_unref(in_stack_00000030);
  qt_array_data_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004da112 name=FUN_004da112 size=21 ====

void FUN_004da112(void)

{
  QProcessEnvironment *unaff_RBX;
  undefined8 in_stack_00000028;
  undefined8 in_stack_00000030;
  
  qt_shared_data_unref();
  QProcessEnvironment::~QProcessEnvironment(unaff_RBX);
  qt_shared_data_unref(in_stack_00000028);
  qt_array_data_unref(in_stack_00000030);
  qt_array_data_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004da127 name=FUN_004da127 size=11 ====

void FUN_004da127(void)

{
  undefined8 in_stack_00000020;
  undefined8 in_stack_00000028;
  undefined8 in_stack_00000030;
  
  qt_array_data_unref();
  qt_array_data_unref();
  qt_shared_data_unref(in_stack_00000020);
  qt_shared_data_unref(in_stack_00000028);
  qt_array_data_unref(in_stack_00000030);
  qt_array_data_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004da132 name=FUN_004da132 size=29 ====

void FUN_004da132(void)

{
  undefined8 in_stack_00000020;
  undefined8 in_stack_00000028;
  undefined8 in_stack_00000030;
  
  qt_shared_data_unref();
  qt_array_data_unref();
  qt_array_data_unref();
  qt_shared_data_unref(in_stack_00000020);
  qt_shared_data_unref(in_stack_00000028);
  qt_array_data_unref(in_stack_00000030);
  qt_array_data_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004da14f name=FUN_004da14f size=10 ====

void FUN_004da14f(void)

{
  qt_array_data_unref();
  qt_array_data_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004da159 name=FUN_004da159 size=16 ====

void FUN_004da159(void)

{
  qt_array_data_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004da170 name=FUN_004da170 size=21 ====

void FUN_004da170(void)

{
  void *unaff_RBP;
  
  operator_delete(unaff_RBP,0x60);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004da185 name=FUN_004da185 size=28 ====

void FUN_004da185(void)

{
  qt_array_data_unref(&stack0x00000070);
  qt_array_data_unref(&stack0x00000050);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004da1a2 name=FUN_004da1a2 size=36 ====

void FUN_004da1a2(void)

{
  long unaff_RBP;
  long unaff_R13;
  
  qt_array_data_unref(unaff_R13 + 8);
  qt_array_data_unref(unaff_RBP + 8);
  qt_array_data_unref(&stack0x00000028);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004da1c6 name=FUN_004da1c6 size=21 ====

void FUN_004da1c6(void)

{
  void *unaff_RBX;
  
  operator_delete(unaff_RBX,0xe0);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004da1dc name=FUN_004da1dc size=24 ====

void FUN_004da1dc(void)

{
  qt_array_data_unref();
  qt_array_data_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004da1f4 name=FUN_004da1f4 size=35 ====

void FUN_004da1f4(void)

{
  QVariant *unaff_RBP;
  QVariant *unaff_R12;
  
  QVariant::~QVariant(unaff_RBP);
  qt_array_data_unref();
  QVariant::~QVariant(unaff_R12);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004da218 name=FUN_004da218 size=35 ====

void FUN_004da218(void)

{
  QVariant *unaff_RBP;
  QVariant *unaff_R12;
  
  QVariant::~QVariant(unaff_RBP);
  qt_array_data_unref();
  QVariant::~QVariant(unaff_R12);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004da23c name=FUN_004da23c size=37 ====

void FUN_004da23c(void)

{
  qt_array_data_unref();
  qt_array_data_unref();
  QVariant::~QVariant((QVariant *)&stack0x00000030);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004da261 name=FUN_004da261 size=13 ====

void FUN_004da261(void)

{
  QVariant *unaff_R12;
  
  qt_array_data_unref();
  qt_array_data_unref();
  QVariant::~QVariant(unaff_R12);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004da26e name=FUN_004da26e size=24 ====

void FUN_004da26e(void)

{
  QVariant *unaff_RBP;
  
  QVariant::~QVariant(unaff_RBP);
  qt_array_data_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004da286 name=FUN_004da286 size=24 ====

void FUN_004da286(void)

{
  QVariant *unaff_RBP;
  
  QVariant::~QVariant(unaff_RBP);
  qt_array_data_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004da29e name=FUN_004da29e size=24 ====

void FUN_004da29e(void)

{
  QVariant *unaff_RBP;
  
  QVariant::~QVariant(unaff_RBP);
  qt_array_data_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004da2b6 name=FUN_004da2b6 size=35 ====

void FUN_004da2b6(void)

{
  QVariant *unaff_RBX;
  QVariant *unaff_R13;
  
  QVariant::~QVariant(unaff_RBX);
  qt_array_data_unref();
  QVariant::~QVariant(unaff_R13);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004da2da name=FUN_004da2da size=35 ====

void FUN_004da2da(void)

{
  QVariant *unaff_RBP;
  QVariant *unaff_R13;
  
  QVariant::~QVariant(unaff_RBP);
  qt_array_data_unref();
  QVariant::~QVariant(unaff_R13);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004da2fe name=FUN_004da2fe size=89 ====

void FUN_004da2fe(void)

{
  long unaff_RBX;
  QVariant *unaff_R12;
  
  qt_array_data_unref();
  QVariant::~QVariant(unaff_R12);
  qmap_freetree_variant_nodes();
  qhash_unref_free(unaff_RBX + 0x40);
  FUN_0069f8f0(unaff_RBX + 0x38);
  QVariant::~QVariant((QVariant *)(unaff_RBX + 0x28));
  qt_array_data_unref(unaff_RBX + 0x18);
  qt_array_data_unref(unaff_RBX + 0x10);
  qt_array_data_unref(unaff_RBX + 8);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004da357 name=FUN_004da357 size=21 ====

void FUN_004da357(void)

{
  long unaff_RBX;
  QVariant *unaff_R13;
  
  qt_array_data_unref();
  QVariant::~QVariant(unaff_R13);
  qmap_freetree_variant_nodes();
  qhash_unref_free(unaff_RBX + 0x40);
  FUN_0069f8f0(unaff_RBX + 0x38);
  QVariant::~QVariant((QVariant *)(unaff_RBX + 0x28));
  qt_array_data_unref(unaff_RBX + 0x18);
  qt_array_data_unref(unaff_RBX + 0x10);
  qt_array_data_unref(unaff_RBX + 8);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004da36c name=FUN_004da36c size=50 ====

void FUN_004da36c(void)

{
  QObject *unaff_RBX;
  
  FUN_0069f90c();
  FUN_0069f950(unaff_RBX + 0x28);
  FUN_0069ea70(unaff_RBX + 0x20);
  qt_byte_array_unref();
  QObject::~QObject(unaff_RBX);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004da39e name=FUN_004da39e size=41 ====

void FUN_004da39e(void)

{
  if (DAT_011c1af8 == -1) {
    DAT_011c1af8 = -2;
  }
  __cxa_guard_abort(&DAT_011c1a68);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004da3c8 name=FUN_004da3c8 size=26 ====

void FUN_004da3c8(void)

{
  undefined8 in_stack_00000008;
  
  qt_array_data_unref(in_stack_00000008);
  qt_shared_data_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004da3e2 name=FUN_004da3e2 size=24 ====

void FUN_004da3e2(void)

{
  qhash_unref_free();
  qt_array_data_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004da3fa name=FUN_004da3fa size=35 ====

void FUN_004da3fa(void)

{
  QVariant *unaff_RBP;
  
  qt_array_data_unref();
  QVariant::~QVariant(unaff_RBP);
  qt_array_data_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004da41d name=FUN_004da41d size=16 ====

void FUN_004da41d(void)

{
  qt_shared_data_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004da42e name=FUN_004da42e size=48 ====

void FUN_004da42e(void)

{
  QProcess *unaff_R14;
  
  qt_array_data_unref();
  QProcess::~QProcess(unaff_R14);
  qt_array_data_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004da45e name=FUN_004da45e size=10 ====

void FUN_004da45e(void)

{
  QProcess *unaff_R14;
  
  qt_shared_data_unref();
  QProcess::~QProcess(unaff_R14);
  qt_array_data_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004da468 name=FUN_004da468 size=79 ====

void FUN_004da468(void)

{
  QVariant *unaff_RBX;
  QVariant *unaff_R12;
  undefined8 in_stack_00000028;
  undefined8 in_stack_00000030;
  long in_stack_00000048;
  undefined8 in_stack_00000068;
  
  QVariant::~QVariant(unaff_RBX);
  qt_array_data_unref();
  QVariant::~QVariant(unaff_R12);
  qt_array_data_unref(in_stack_00000028);
  qmap_freetree_variant_nodes(in_stack_00000030);
  qatomic_unref_call_deleter(in_stack_00000068);
  qt_array_data_unref(in_stack_00000048 + 0x10);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004da4b7 name=FUN_004da4b7 size=42 ====

void FUN_004da4b7(void)

{
  QVariant *unaff_RBX;
  QVariant *unaff_R12;
  
  QVariant::~QVariant(unaff_RBX);
  qt_array_data_unref();
  QVariant::~QVariant(unaff_R12);
  qt_array_data_unref(&stack0x000000d0);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004da4e1 name=FUN_004da4e1 size=29 ====

void FUN_004da4e1(void)

{
  QVariant *unaff_RBX;
  QVariant *unaff_R12;
  undefined8 in_stack_00000030;
  long in_stack_00000048;
  undefined8 in_stack_00000068;
  
  QVariant::~QVariant(unaff_RBX);
  qt_array_data_unref();
  QVariant::~QVariant(unaff_R12);
  qmap_freetree_variant_nodes(in_stack_00000030);
  qatomic_unref_call_deleter(in_stack_00000068);
  qt_array_data_unref(in_stack_00000048 + 0x10);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004da4fe name=FUN_004da4fe size=23 ====

void FUN_004da4fe(void)

{
  QVariant *unaff_R14;
  undefined8 in_stack_00000028;
  undefined8 in_stack_00000030;
  undefined8 in_stack_00000038;
  long in_stack_00000048;
  undefined8 in_stack_00000068;
  
  QVariant::~QVariant(unaff_R14);
  qt_array_data_unref(in_stack_00000038);
  qt_array_data_unref(in_stack_00000028);
  qmap_freetree_variant_nodes(in_stack_00000030);
  qatomic_unref_call_deleter(in_stack_00000068);
  qt_array_data_unref(in_stack_00000048 + 0x10);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004da515 name=FUN_004da515 size=33 ====

void FUN_004da515(void)

{
  long unaff_RBX;
  long unaff_RBP;
  long unaff_R12;
  undefined8 in_stack_00000028;
  undefined8 in_stack_00000030;
  undefined8 in_stack_00000038;
  long in_stack_00000048;
  undefined8 in_stack_00000068;
  
  qt_array_data_unref(unaff_RBX + 0x10);
  qt_array_data_unref(unaff_R12 + 0x10);
  qt_array_data_unref(unaff_RBP + 0x10);
  qt_array_data_unref(in_stack_00000038);
  qt_array_data_unref(in_stack_00000028);
  qmap_freetree_variant_nodes(in_stack_00000030);
  qatomic_unref_call_deleter(in_stack_00000068);
  qt_array_data_unref(in_stack_00000048 + 0x10);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004da536 name=FUN_004da536 size=15 ====

void FUN_004da536(void)

{
  void *unaff_R15;
  undefined8 in_stack_00000028;
  undefined8 in_stack_00000030;
  undefined8 in_stack_00000038;
  long in_stack_00000048;
  undefined8 in_stack_00000068;
  
  operator_delete(unaff_R15,0x30);
  qt_array_data_unref(in_stack_00000038);
  qt_array_data_unref(in_stack_00000028);
  qmap_freetree_variant_nodes(in_stack_00000030);
  qatomic_unref_call_deleter(in_stack_00000068);
  qt_array_data_unref(in_stack_00000048 + 0x10);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004da545 name=FUN_004da545 size=21 ====

void FUN_004da545(void)

{
  QVariant *unaff_RBX;
  undefined8 in_stack_00000028;
  undefined8 in_stack_00000030;
  undefined8 in_stack_00000038;
  long in_stack_00000048;
  undefined8 in_stack_00000068;
  
  qt_array_data_unref();
  QVariant::~QVariant(unaff_RBX);
  qt_array_data_unref(in_stack_00000038);
  qt_array_data_unref(in_stack_00000028);
  qmap_freetree_variant_nodes(in_stack_00000030);
  qatomic_unref_call_deleter(in_stack_00000068);
  qt_array_data_unref(in_stack_00000048 + 0x10);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004da55a name=FUN_004da55a size=55 ====

void FUN_004da55a(void)

{
  QWidgetAction *unaff_R14;
  undefined8 in_stack_00000028;
  undefined8 in_stack_00000030;
  undefined8 in_stack_00000038;
  long in_stack_00000048;
  void *in_stack_00000058;
  undefined8 in_stack_00000068;
  
  operator_delete(in_stack_00000058,0x30);
  *(undefined ***)unaff_R14 = &PTR_metaObject_01184688;
  QWidgetAction::~QWidgetAction(unaff_R14);
  operator_delete(unaff_R14,0x28);
  qt_array_data_unref(in_stack_00000038);
  qt_array_data_unref(in_stack_00000028);
  qmap_freetree_variant_nodes(in_stack_00000030);
  qatomic_unref_call_deleter(in_stack_00000068);
  qt_array_data_unref(in_stack_00000048 + 0x10);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004da591 name=FUN_004da591 size=32 ====

void FUN_004da591(void)

{
  undefined8 in_stack_00000028;
  undefined8 in_stack_00000030;
  undefined8 in_stack_00000038;
  long in_stack_00000048;
  undefined8 in_stack_00000068;
  
  qt_array_data_unref();
  qt_array_data_unref();
  qt_array_data_unref();
  qt_array_data_unref(in_stack_00000038);
  qt_array_data_unref(in_stack_00000028);
  qmap_freetree_variant_nodes(in_stack_00000030);
  qatomic_unref_call_deleter(in_stack_00000068);
  qt_array_data_unref(in_stack_00000048 + 0x10);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004da5b2 name=FUN_004da5b2 size=26 ====

void FUN_004da5b2(void)

{
  QJSValue *in_stack_00000028;
  
  QJSValue::~QJSValue(in_stack_00000028);
  qt_array_data_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004da5cc name=FUN_004da5cc size=48 ====

void FUN_004da5cc(void)

{
  QJSValue *unaff_RBX;
  QJSValue *unaff_RBP;
  undefined8 unaff_retaddr;
  QJSValue *in_stack_00000028;
  
  qt_array_data_unref(unaff_retaddr);
  qt_array_data_unref();
  QJSValue::~QJSValue(unaff_RBX);
  QJSValue::~QJSValue(unaff_RBP);
  QJSValue::~QJSValue(in_stack_00000028);
  qt_array_data_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004da5fc name=FUN_004da5fc size=10 ====

void FUN_004da5fc(void)

{
  QJSValue *unaff_RBP;
  QJSValue *in_stack_00000028;
  
  qlist_release_data();
  QJSValue::~QJSValue(unaff_RBP);
  QJSValue::~QJSValue(in_stack_00000028);
  qt_array_data_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004da606 name=FUN_004da606 size=19 ====

void FUN_004da606(void)

{
  QJSValue *unaff_RBP;
  QJSValue *unaff_R12;
  undefined8 unaff_retaddr;
  QJSValue *in_stack_00000028;
  
  QJSValue::~QJSValue(unaff_R12);
  qt_array_data_unref(unaff_retaddr);
  QJSValue::~QJSValue(unaff_RBP);
  QJSValue::~QJSValue(in_stack_00000028);
  qt_array_data_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004da619 name=FUN_004da619 size=33 ====

void FUN_004da619(void)

{
  QVariant *unaff_R12;
  QVariant *unaff_retaddr;
  
  QVariant::~QVariant(unaff_R12);
  qt_array_data_unref();
  QVariant::~QVariant(unaff_retaddr);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004da63a name=FUN_004da63a size=19 ====

void FUN_004da63a(void)

{
  undefined8 unaff_retaddr;
  QJSValue *in_stack_00000028;
  
  qt_array_data_unref(unaff_retaddr);
  qt_array_data_unref();
  QJSValue::~QJSValue(in_stack_00000028);
  qt_array_data_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004da64d name=FUN_004da64d size=18 ====

void FUN_004da64d(void)

{
  void *unaff_RBX;
  QJSValue *in_stack_00000028;
  
  operator_delete(unaff_RBX,0x18);
  QJSValue::~QJSValue(in_stack_00000028);
  qt_array_data_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004da660 name=FUN_004da660 size=40 ====

void FUN_004da660(void)

{
  undefined8 in_RAX;
  undefined1 *puVar1;
  undefined1 *unaff_R14;
  undefined8 uStack0000000000000008;
  
  puVar1 = &stack0x00000050;
  do {
    puVar1 = puVar1 + -0x10;
    uStack0000000000000008 = in_RAX;
    qt_array_data_unref(puVar1);
    in_RAX = uStack0000000000000008;
  } while (puVar1 != unaff_R14);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception(uStack0000000000000008);
}


// ==== entry=004da688 name=FUN_004da688 size=71 ====

void FUN_004da688(void)

{
  long unaff_RBP;
  QVariant *unaff_R14;
  QVariant *unaff_R15;
  
  QVariant::~QVariant(unaff_R15);
  qt_array_data_unref();
  QVariant::~QVariant(unaff_R14);
  if (*(void **)(unaff_RBP + 0x18) != (void *)0x0) {
    operator_delete(*(void **)(unaff_RBP + 0x18),0x34);
  }
  FUN_0069ea50(unaff_RBP + 0x10);
  qmap_freetree_variant_nodes();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004da6cf name=FUN_004da6cf size=10 ====

void FUN_004da6cf(void)

{
  long unaff_RBP;
  
  qt_array_data_unref();
  if (*(void **)(unaff_RBP + 0x18) != (void *)0x0) {
    operator_delete(*(void **)(unaff_RBP + 0x18),0x34);
  }
  FUN_0069ea50(unaff_RBP + 0x10);
  qmap_freetree_variant_nodes();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004da6da name=FUN_004da6da size=44 ====

void FUN_004da6da(void)

{
  long unaff_RBX;
  void *unaff_R12;
  
  operator_delete(unaff_R12,0x28);
  qt_array_data_unref(unaff_RBX + 0x20);
  if (*(_Sp_counted_base<(__gnu_cxx::_Lock_policy)2> **)(unaff_RBX + 0x10) !=
      (_Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *)0x0) {
    std::_Sp_counted_base<(__gnu_cxx::_Lock_policy)2>::_M_release
              (*(_Sp_counted_base<(__gnu_cxx::_Lock_policy)2> **)(unaff_RBX + 0x10));
  }
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004da706 name=FUN_004da706 size=24 ====

void FUN_004da706(void)

{
  qt_array_data_unref();
  qt_array_data_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004da71e name=FUN_004da71e size=59 ====

/* WARNING: Removing unreachable block (ram,0x004da74f) */

void FUN_004da71e(void)

{
  undefined8 in_RAX;
  long in_stack_00000028;
  _Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *in_stack_00000048;
  
  if (in_stack_00000048 != (_Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *)0x0) {
    std::_Sp_counted_base<(__gnu_cxx::_Lock_policy)2>::_M_release(in_stack_00000048);
  }
  FUN_00698dce(in_stack_00000028 + -0x18);
  qt_array_data_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception(in_RAX);
}


// ==== entry=004da759 name=FUN_004da759 size=4 ====

/* WARNING: Removing unreachable block (ram,0x004da74f) */

void FUN_004da759(void)

{
  long in_stack_00000028;
  
  FUN_00698dce(in_stack_00000028 + -0x18);
  qt_array_data_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004da75d name=FUN_004da75d size=5 ====

/* WARNING: Removing unreachable block (ram,0x004da74f) */

void FUN_004da75d(void)

{
  undefined8 in_RAX;
  long in_stack_00000028;
  _Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *in_stack_00000048;
  
  if (in_stack_00000048 != (_Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *)0x0) {
    std::_Sp_counted_base<(__gnu_cxx::_Lock_policy)2>::_M_release(in_stack_00000048);
  }
  FUN_00698dce(in_stack_00000028 + -0x18);
  qt_array_data_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception(in_RAX);
}


// ==== entry=004da762 name=FUN_004da762 size=20 ====

/* WARNING: Removing unreachable block (ram,0x004da74f) */

void FUN_004da762(void)

{
  void *unaff_RBX;
  undefined8 unaff_RBP;
  long in_stack_00000028;
  _Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *in_stack_00000048;
  
  operator_delete(unaff_RBX,0x28);
  if (in_stack_00000048 != (_Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *)0x0) {
    std::_Sp_counted_base<(__gnu_cxx::_Lock_policy)2>::_M_release(in_stack_00000048);
  }
  FUN_00698dce(in_stack_00000028 + -0x18);
  qt_array_data_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception(unaff_RBP);
}


// ==== entry=004da776 name=FUN_004da776 size=32 ====

void FUN_004da776(void)

{
  QVariant *unaff_RBX;
  QVariant *unaff_R12;
  
  QVariant::~QVariant(unaff_RBX);
  qt_array_data_unref();
  QVariant::~QVariant(unaff_R12);
  qt_array_data_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004da796 name=FUN_004da796 size=35 ====

void FUN_004da796(void)

{
  QVariant *unaff_RBX;
  QVariant *unaff_R12;
  
  QVariant::~QVariant(unaff_RBX);
  qt_array_data_unref();
  QVariant::~QVariant(unaff_R12);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004da7b9 name=FUN_004da7b9 size=32 ====

void FUN_004da7b9(void)

{
  QVariant *unaff_RBX;
  QVariant *unaff_R12;
  
  QVariant::~QVariant(unaff_RBX);
  qt_array_data_unref();
  QVariant::~QVariant(unaff_R12);
  qt_array_data_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004da7d9 name=FUN_004da7d9 size=32 ====

void FUN_004da7d9(void)

{
  QVariant *unaff_RBX;
  QVariant *unaff_R12;
  
  QVariant::~QVariant(unaff_RBX);
  qt_array_data_unref();
  QVariant::~QVariant(unaff_R12);
  qt_array_data_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004da7f9 name=FUN_004da7f9 size=7 ====

/* WARNING: Removing unreachable block (ram,0x004da74f) */

void FUN_004da7f9(void)

{
  undefined8 in_RAX;
  long in_stack_00000028;
  _Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *in_stack_00000048;
  
  if (in_stack_00000048 != (_Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *)0x0) {
    std::_Sp_counted_base<(__gnu_cxx::_Lock_policy)2>::_M_release(in_stack_00000048);
  }
  FUN_00698dce(in_stack_00000028 + -0x18);
  qt_array_data_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception(in_RAX);
}


// ==== entry=004da800 name=FUN_004da800 size=16 ====

void FUN_004da800(void)

{
  qmap_freetree_variant_nodes();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004da810 name=FUN_004da810 size=24 ====

void FUN_004da810(void)

{
  qmap_freetree_variant_nodes();
  qatomic_unref_call_deleter();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004da828 name=FUN_004da828 size=34 ====

void FUN_004da828(void)

{
  long unaff_R14;
  
  qt_array_data_unref(unaff_R14 + 0x20);
  qt_array_data_unref(unaff_R14 + 0x10);
  qt_array_data_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004da84a name=FUN_004da84a size=16 ====

void FUN_004da84a(void)

{
  qt_array_data_unref();
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004da85a name=FUN_004da85a size=35 ====

void FUN_004da85a(void)

{
  QVariant *unaff_RBX;
  QVariant *unaff_R13;
  
  QVariant::~QVariant(unaff_RBX);
  qt_array_data_unref();
  QVariant::~QVariant(unaff_R13);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004da87e name=FUN_004da87e size=43 ====

void FUN_004da87e(void)

{
  undefined8 in_RAX;
  undefined1 *puVar1;
  undefined1 *unaff_R13;
  undefined8 uStack0000000000000008;
  
  puVar1 = &stack0x000000c0;
  do {
    puVar1 = puVar1 + -0x10;
    uStack0000000000000008 = in_RAX;
    qt_array_data_unref(puVar1);
    in_RAX = uStack0000000000000008;
  } while (puVar1 != unaff_R13);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception(uStack0000000000000008);
}


// ==== entry=004da8aa name=FUN_004da8aa size=72 ====

void FUN_004da8aa(void)

{
  undefined8 in_stack_00000008;
  undefined8 in_stack_00000010;
  undefined8 in_stack_00000028;
  undefined8 in_stack_00000040;
  
  FUN_0069f8f0();
  qt_shared_data_unref(in_stack_00000028);
  qmap_freetree_variant_nodes(in_stack_00000040);
  FUN_0069f90c();
  qt_array_data_unref();
  qt_array_data_unref(in_stack_00000008);
  json_value_destruct(in_stack_00000010);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004da8f2 name=FUN_004da8f2 size=30 ====

void FUN_004da8f2(void)

{
  undefined8 unaff_retaddr;
  undefined8 in_stack_00000010;
  
  json_value_destruct();
  json_value_destruct();
  FUN_006a1fa0(unaff_retaddr);
  json_value_destruct(in_stack_00000010);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004da910 name=FUN_004da910 size=21 ====

void FUN_004da910(void)

{
  undefined8 in_stack_00000010;
  
  json_value_destruct();
  json_value_destruct();
  json_value_destruct(in_stack_00000010);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


// ==== entry=004da925 name=FUN_004da925 size=21 ====

void FUN_004da925(void)

{
  undefined8 in_stack_00000008;
  undefined8 in_stack_00000010;
  
  json_value_destruct();
  json_value_destruct();
  qt_array_data_unref(in_stack_00000008);
  json_value_destruct(in_stack_00000010);
                    /* WARNING: Subroutine does not return */
  cxa_throw_exception();
}


