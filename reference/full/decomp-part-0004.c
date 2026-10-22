// Ghidra 12.1.4 decompiled — WindTerm 2.7.0 (sha256 9491b87e…) part 4
// ==== entry=004c5d66 name=FUN_004c5d66 size=22 ====

void FUN_004c5d66(void)

{
  long in_stack_00000048;
  
  __cxa_begin_catch();
  *(int *)(in_stack_00000048 + 8) = *(int *)(in_stack_00000048 + 8) + 1;
                    /* WARNING: Subroutine does not return */
                    /* try { // try from 004c5d77 to 004c5d7b has its CatchHandler @ 004c5d96 */
  __cxa_rethrow();
}


// ==== entry=004c5d7c name=FUN_004c5d7c size=26 ====

void FUN_004c5d7c(void)

{
  QIcon *in_stack_00000028;
  
  FUN_005249f0();
  QIcon::~QIcon(in_stack_00000028);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c5da4 name=FUN_004c5da4 size=16 ====

void FUN_004c5da4(void)

{
  QMouseEvent *unaff_R14;
  
  QMouseEvent::~QMouseEvent(unaff_R14);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c5db4 name=FUN_004c5db4 size=21 ====

void FUN_004c5db4(void)

{
  void *unaff_RBX;
  
  operator_delete(unaff_RBX,0x78);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c5dc9 name=FUN_004c5dc9 size=21 ====

void FUN_004c5dc9(void)

{
  void *unaff_RBX;
  
  operator_delete(unaff_RBX,0x20);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c5dde name=FUN_004c5dde size=60 ====

void FUN_004c5dde(void)

{
  QWidget *unaff_RBX;
  QArrayData *in_stack_00000008;
  
  if (*(int *)in_stack_00000008 != 0) {
    if (*(int *)in_stack_00000008 == -1) goto LAB_004c5df8;
    LOCK();
    *(int *)in_stack_00000008 = *(int *)in_stack_00000008 + -1;
    UNLOCK();
    if (*(int *)in_stack_00000008 != 0) goto LAB_004c5df8;
  }
  QArrayData::deallocate(in_stack_00000008,2,8);
LAB_004c5df8:
  QWidget::~QWidget(unaff_RBX);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c5e20 name=FUN_004c5e20 size=16 ====

void FUN_004c5e20(void)

{
  QVariant *unaff_RBP;
  
  QVariant::~QVariant(unaff_RBP);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c5e30 name=FUN_004c5e30 size=16 ====

void FUN_004c5e30(void)

{
  FUN_005249f0();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c5e40 name=FUN_004c5e40 size=24 ====

void FUN_004c5e40(void)

{
  FUN_005249f0();
  FUN_005249f0();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c5e58 name=FUN_004c5e58 size=26 ====

void FUN_004c5e58(void)

{
  QIcon *unaff_R14;
  
  QIcon::~QIcon(unaff_R14);
  FUN_005249f0();
  FUN_005249f0();
  FUN_005249f0();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c5e72 name=FUN_004c5e72 size=32 ====

void FUN_004c5e72(void)

{
  QIcon *unaff_RBP;
  
  QIcon::~QIcon(unaff_RBP);
  FUN_005249f0();
  FUN_005249f0();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c5e92 name=FUN_004c5e92 size=16 ====

void FUN_004c5e92(void)

{
  FUN_005249f0();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c5ea2 name=FUN_004c5ea2 size=16 ====

void FUN_004c5ea2(void)

{
  FUN_005249f0();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c5eb2 name=FUN_004c5eb2 size=16 ====

void FUN_004c5eb2(void)

{
  FUN_005249f0();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c5ec2 name=FUN_004c5ec2 size=21 ====

void FUN_004c5ec2(void)

{
  void *unaff_RBP;
  
  operator_delete(unaff_RBP,0x30);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c5ed7 name=FUN_004c5ed7 size=21 ====

void FUN_004c5ed7(void)

{
  void *unaff_RBP;
  
  operator_delete(unaff_RBP,0x48);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c5eec name=FUN_004c5eec size=21 ====

void FUN_004c5eec(void)

{
  void *unaff_RBP;
  
  operator_delete(unaff_RBP,0x30);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c5f01 name=FUN_004c5f01 size=13 ====

void FUN_004c5f01(void)

{
  FUN_005249f0();
  FUN_005249f0();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c5f0e name=FUN_004c5f0e size=29 ====

void FUN_004c5f0e(void)

{
  QIcon *unaff_R14;
  
  QIcon::~QIcon(unaff_R14);
  FUN_005249f0();
  FUN_005249f0();
  FUN_005249f0();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c5f2b name=FUN_004c5f2b size=13 ====

void FUN_004c5f2b(void)

{
  FUN_005249f0();
  FUN_005249f0();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c5f38 name=FUN_004c5f38 size=13 ====

void FUN_004c5f38(void)

{
  FUN_005249f0();
  FUN_005249f0();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c5f45 name=FUN_004c5f45 size=21 ====

void FUN_004c5f45(void)

{
  void *unaff_R13;
  
  operator_delete(unaff_R13,0x20);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c5f5a name=FUN_004c5f5a size=21 ====

void FUN_004c5f5a(void)

{
  void *unaff_R12;
  
  operator_delete(unaff_R12,0x20);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c5f6f name=FUN_004c5f6f size=16 ====

void FUN_004c5f6f(void)

{
  FUN_005249f0();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c5f7f name=FUN_004c5f7f size=16 ====

void FUN_004c5f7f(void)

{
  FUN_005249f0();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c5f8f name=FUN_004c5f8f size=21 ====

void FUN_004c5f8f(void)

{
  void *unaff_R12;
  
  operator_delete(unaff_R12,0x30);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c5fa4 name=FUN_004c5fa4 size=21 ====

void FUN_004c5fa4(void)

{
  void *unaff_RBP;
  
  operator_delete(unaff_RBP,0x30);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c5fba name=FUN_004c5fba size=27 ====

void FUN_004c5fba(void)

{
  QWidget *unaff_RBX;
  
  FUN_005249f0();
  QWidget::~QWidget(unaff_RBX);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c5fd5 name=FUN_004c5fd5 size=21 ====

void FUN_004c5fd5(void)

{
  void *unaff_RBP;
  
  operator_delete(unaff_RBP,0x18);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c5fea name=FUN_004c5fea size=19 ====

void FUN_004c5fea(void)

{
  QVariant *unaff_RBX;
  
  QVariant::~QVariant(unaff_RBX);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c5ffe name=FUN_004c5ffe size=16 ====

void FUN_004c5ffe(void)

{
  QVariant *unaff_RBX;
  
  QVariant::~QVariant(unaff_RBX);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c600e name=FUN_004c600e size=16 ====

void FUN_004c600e(void)

{
  FUN_005249f0();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c601e name=FUN_004c601e size=21 ====

void FUN_004c601e(void)

{
  void *unaff_RBX;
  
  operator_delete(unaff_RBX,0x68);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c6033 name=FUN_004c6033 size=16 ====

void FUN_004c6033(void)

{
  QVariant *unaff_RBX;
  
  QVariant::~QVariant(unaff_RBX);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c6044 name=FUN_004c6044 size=16 ====

void FUN_004c6044(void)

{
  QPixmap *unaff_RBP;
  
  QPixmap::~QPixmap(unaff_RBP);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c6054 name=FUN_004c6054 size=23 ====

void FUN_004c6054(void)

{
  QVariant *unaff_RBX;
  QIcon *in_stack_00000008;
  
  QIcon::~QIcon(in_stack_00000008);
  QVariant::~QVariant(unaff_RBX);
  FUN_005249f0();
  FUN_005249f0();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c606b name=FUN_004c606b size=43 ====

void FUN_004c606b(void)

{
  QVariant *unaff_RBX;
  QIcon *unaff_R13;
  
  QVariant::~QVariant(unaff_RBX);
  QIcon::~QIcon(unaff_R13);
  FUN_005249f0();
  FUN_005249f0();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c6096 name=FUN_004c6096 size=13 ====

void FUN_004c6096(void)

{
  QVariant *unaff_RBX;
  
  QVariant::~QVariant(unaff_RBX);
  FUN_005249f0();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c60a3 name=FUN_004c60a3 size=16 ====

void FUN_004c60a3(void)

{
  QVariant *unaff_RBX;
  
  QVariant::~QVariant(unaff_RBX);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c60b3 name=FUN_004c60b3 size=16 ====

void FUN_004c60b3(void)

{
  QVariant *unaff_RBX;
  
  QVariant::~QVariant(unaff_RBX);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c60c4 name=FUN_004c60c4 size=56 ====

void FUN_004c60c4(void)

{
  QIcon *unaff_RBP;
  QMenu *unaff_R13;
  undefined8 in_stack_00000020;
  
  QIcon::~QIcon(unaff_RBP);
  FUN_005249f0();
  FUN_005249f0(in_stack_00000020);
  FUN_005249f0();
  QMenu::~QMenu(unaff_R13);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c60fc name=FUN_004c60fc size=10 ====

void FUN_004c60fc(void)

{
  QVariant *unaff_RBX;
  QMenu *unaff_R13;
  undefined8 in_stack_00000020;
  
  QVariant::~QVariant(unaff_RBX);
  FUN_005249f0(in_stack_00000020);
  FUN_005249f0();
  QMenu::~QMenu(unaff_R13);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c6106 name=FUN_004c6106 size=72 ====

void FUN_004c6106(void)

{
  long unaff_RBX;
  QMenu *unaff_R13;
  char in_stack_000000a0;
  code *in_stack_000000b8;
  code *in_stack_000000c0;
  
  if (in_stack_000000a0 != '\0') {
    if (in_stack_000000b8 == (code *)0x0) {
                    /* WARNING: Subroutine does not return */
      std::__throw_bad_function_call();
    }
    (*in_stack_000000c0)(unaff_RBX + 8);
  }
  if (in_stack_000000b8 != (code *)0x0) {
    (*in_stack_000000b8)(unaff_RBX + 8,unaff_RBX + 8,3);
  }
  QMenu::~QMenu(unaff_R13);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c6120 name=FUN_004c6120 size=84 ====

void FUN_004c6120(void)

{
  long unaff_RBX;
  QMenu *unaff_R13;
  code *in_stack_00000070;
  code *in_stack_00000090;
  code *in_stack_000000b8;
  
  if (in_stack_000000b8 != (code *)0x0) {
    (*in_stack_000000b8)(unaff_RBX + 8,unaff_RBX + 8,3);
  }
  if (in_stack_00000070 != (code *)0x0) {
    (*in_stack_00000070)();
  }
  if (in_stack_00000090 != (code *)0x0) {
    (*in_stack_00000090)();
  }
  QMenu::~QMenu(unaff_R13);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c61a2 name=FUN_004c61a2 size=34 ====

void FUN_004c61a2(void)

{
  QVariant *unaff_RBX;
  QMenu *unaff_R13;
  undefined8 in_stack_00000020;
  
  QVariant::~QVariant(unaff_RBX);
  FUN_005249f0(in_stack_00000020);
  FUN_005249f0();
  QMenu::~QMenu(unaff_R13);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c61c4 name=FUN_004c61c4 size=45 ====

void FUN_004c61c4(void)

{
  QIcon *unaff_RBP;
  QMenu *unaff_R13;
  undefined8 in_stack_00000020;
  
  QIcon::~QIcon(unaff_RBP);
  FUN_005249f0();
  FUN_005249f0(in_stack_00000020);
  FUN_005249f0();
  QMenu::~QMenu(unaff_R13);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c61f1 name=FUN_004c61f1 size=21 ====

void FUN_004c61f1(void)

{
  QIcon *unaff_RBP;
  QMenu *unaff_R13;
  undefined8 in_stack_00000020;
  
  QIcon::~QIcon(unaff_RBP);
  FUN_005249f0();
  FUN_005249f0(in_stack_00000020);
  FUN_005249f0();
  QMenu::~QMenu(unaff_R13);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c6206 name=FUN_004c6206 size=12 ====

void FUN_004c6206(void)

{
  QVariant *unaff_RBX;
  QMenu *unaff_R13;
  undefined8 in_stack_00000020;
  
  QVariant::~QVariant(unaff_RBX);
  FUN_005249f0(in_stack_00000020);
  FUN_005249f0();
  QMenu::~QMenu(unaff_R13);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c6212 name=FUN_004c6212 size=34 ====

void FUN_004c6212(void)

{
  QVariant *unaff_RBX;
  QMenu *unaff_R13;
  undefined8 in_stack_00000020;
  
  QVariant::~QVariant(unaff_RBX);
  FUN_005249f0(in_stack_00000020);
  FUN_005249f0();
  QMenu::~QMenu(unaff_R13);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c6234 name=FUN_004c6234 size=45 ====

void FUN_004c6234(void)

{
  QIcon *unaff_RBP;
  QMenu *unaff_R13;
  undefined8 in_stack_00000020;
  
  QIcon::~QIcon(unaff_RBP);
  FUN_005249f0();
  FUN_005249f0(in_stack_00000020);
  FUN_005249f0();
  QMenu::~QMenu(unaff_R13);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c6261 name=FUN_004c6261 size=10 ====

void FUN_004c6261(void)

{
  QVariant *unaff_RBX;
  QMenu *unaff_R13;
  undefined8 in_stack_00000020;
  
  QVariant::~QVariant(unaff_RBX);
  FUN_005249f0(in_stack_00000020);
  FUN_005249f0();
  QMenu::~QMenu(unaff_R13);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c626b name=FUN_004c626b size=21 ====

void FUN_004c626b(void)

{
  QIcon *unaff_RBP;
  QMenu *unaff_R13;
  undefined8 in_stack_00000020;
  
  QIcon::~QIcon(unaff_RBP);
  FUN_005249f0();
  FUN_005249f0(in_stack_00000020);
  FUN_005249f0();
  QMenu::~QMenu(unaff_R13);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c6280 name=FUN_004c6280 size=16 ====

void FUN_004c6280(void)

{
  FUN_005249f0();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c6290 name=FUN_004c6290 size=16 ====

void FUN_004c6290(void)

{
  FUN_005249f0();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c62a0 name=FUN_004c62a0 size=16 ====

void FUN_004c62a0(void)

{
  FUN_005249f0();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c62b0 name=FUN_004c62b0 size=16 ====

void FUN_004c62b0(void)

{
  QVariant *unaff_RBX;
  
  QVariant::~QVariant(unaff_RBX);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c62c0 name=FUN_004c62c0 size=16 ====

void FUN_004c62c0(void)

{
  QVariant *unaff_RBP;
  
  QVariant::~QVariant(unaff_RBP);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c62d0 name=FUN_004c62d0 size=42 ====

void FUN_004c62d0(void)

{
  void *unaff_RBP;
  undefined8 unaff_R12;
  
  operator_delete(unaff_RBP,0x18);
  FUN_005d5b28();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70(unaff_R12);
}


// ==== entry=004c62fa name=FUN_004c62fa size=13 ====

void FUN_004c62fa(void)

{
  undefined8 unaff_R12;
  
  FUN_005249f0();
  FUN_005d5b28();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70(unaff_R12);
}


// ==== entry=004c6307 name=FUN_004c6307 size=18 ====

void FUN_004c6307(void)

{
  void *unaff_RBP;
  undefined8 unaff_R12;
  
  operator_delete(unaff_RBP,0x10);
  FUN_005d5b28();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70(unaff_R12);
}


// ==== entry=004c631a name=FUN_004c631a size=19 ====

void FUN_004c631a(void)

{
  QVariant *unaff_R12;
  
  QVariant::~QVariant(unaff_R12);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c632e name=FUN_004c632e size=25 ====

void FUN_004c632e(void)

{
  QVariant *unaff_RBP;
  undefined8 unaff_retaddr;
  
  QVariant::~QVariant(unaff_RBP);
  FUN_00535600(unaff_retaddr);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c6347 name=FUN_004c6347 size=10 ====

void FUN_004c6347(void)

{
  QVariant *unaff_RBP;
  undefined8 unaff_retaddr;
  
  QVariant::~QVariant(unaff_RBP);
  FUN_00535600(unaff_retaddr);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c6352 name=FUN_004c6352 size=16 ====

void FUN_004c6352(void)

{
  QVariant *unaff_RBX;
  
  QVariant::~QVariant(unaff_RBX);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c6362 name=FUN_004c6362 size=16 ====

void FUN_004c6362(void)

{
  QVariant *unaff_RBX;
  
  QVariant::~QVariant(unaff_RBX);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c6372 name=FUN_004c6372 size=16 ====

void FUN_004c6372(void)

{
  QVariant *unaff_RBX;
  
  QVariant::~QVariant(unaff_RBX);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c6382 name=FUN_004c6382 size=16 ====

void FUN_004c6382(void)

{
  QVariant *unaff_R12;
  
  QVariant::~QVariant(unaff_R12);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c6392 name=FUN_004c6392 size=25 ====

void FUN_004c6392(void)

{
  QVariant *unaff_RBX;
  undefined8 unaff_retaddr;
  
  QVariant::~QVariant(unaff_RBX);
  FUN_005249f0(unaff_retaddr);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c63ab name=FUN_004c63ab size=10 ====

void FUN_004c63ab(void)

{
  QVariant *unaff_R13;
  undefined8 unaff_retaddr;
  
  QVariant::~QVariant(unaff_R13);
  FUN_005249f0(unaff_retaddr);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c63b5 name=FUN_004c63b5 size=16 ====

void FUN_004c63b5(void)

{
  QVariant *unaff_RBX;
  
  QVariant::~QVariant(unaff_RBX);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c63c5 name=FUN_004c63c5 size=13 ====

void FUN_004c63c5(void)

{
  __cxa_begin_catch();
                    /* WARNING: Subroutine does not return */
                    /* try { // try from 004c63cd to 004c63d1 has its CatchHandler @ 004c63d2 */
  __cxa_rethrow();
}


// ==== entry=004c63ea name=FUN_004c63ea size=21 ====

void FUN_004c63ea(void)

{
  void *unaff_R12;
  
  operator_delete(unaff_R12,0x10);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c63ff name=FUN_004c63ff size=16 ====

void FUN_004c63ff(void)

{
  QVariant *unaff_RBX;
  
  QVariant::~QVariant(unaff_RBX);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c640f name=FUN_004c640f size=16 ====

void FUN_004c640f(void)

{
  QVariant *unaff_RBX;
  
  QVariant::~QVariant(unaff_RBX);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c6420 name=FUN_004c6420 size=30 ====

void FUN_004c6420(void)

{
  QVariant *unaff_RBP;
  
  QVariant::~QVariant(unaff_RBP);
  FUN_005249c0(&stack0x00000000);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c643e name=FUN_004c643e size=24 ====

void FUN_004c643e(void)

{
  QVariant *unaff_RBX;
  
  QVariant::~QVariant(unaff_RBX);
  FUN_005249c0();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c6456 name=FUN_004c6456 size=24 ====

void FUN_004c6456(void)

{
  QVariant *unaff_RBP;
  
  QVariant::~QVariant(unaff_RBP);
  FUN_005249f0();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c646e name=FUN_004c646e size=16 ====

void FUN_004c646e(void)

{
  QDir *unaff_RBP;
  
  QDir::~QDir(unaff_RBP);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c647e name=FUN_004c647e size=45 ====

void FUN_004c647e(void)

{
  QVariant *unaff_RBX;
  QVariant *unaff_R13;
  
  QVariant::~QVariant(unaff_RBX);
  FUN_005249c0();
  QVariant::~QVariant(unaff_R13);
  FUN_005249f0(&stack0x00000008);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c64ac name=FUN_004c64ac size=43 ====

void FUN_004c64ac(void)

{
  QFileDialog *unaff_RBP;
  undefined8 in_stack_00000038;
  
  FUN_00556570(in_stack_00000038);
  FUN_005249f0();
  FUN_005249c0(unaff_RBP + 0x30);
  QFileDialog::~QFileDialog(unaff_RBP);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c64d7 name=FUN_004c64d7 size=20 ====

void FUN_004c64d7(void)

{
  QFileDialog *unaff_RBP;
  undefined8 in_stack_00000038;
  
  FUN_005249f0();
  FUN_00556570(in_stack_00000038);
  FUN_005249c0(unaff_RBP + 0x30);
  QFileDialog::~QFileDialog(unaff_RBP);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c64eb name=FUN_004c64eb size=34 ====

void FUN_004c64eb(void)

{
  undefined8 in_stack_00000030;
  
  FUN_005249f0(in_stack_00000030);
  FUN_005249f0();
  FUN_005249f0();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c650d name=FUN_004c650d size=26 ====

void FUN_004c650d(void)

{
  QFileDialog *unaff_RBP;
  undefined8 in_stack_00000038;
  
  FUN_005249f0();
  FUN_005249f0();
  FUN_005249f0();
  FUN_00556570(in_stack_00000038);
  FUN_005249c0(unaff_RBP + 0x30);
  QFileDialog::~QFileDialog(unaff_RBP);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c6527 name=FUN_004c6527 size=11 ====

void FUN_004c6527(void)

{
  QFileDialog *unaff_RBP;
  
  FUN_005249f0();
  FUN_005249c0(unaff_RBP + 0x30);
  QFileDialog::~QFileDialog(unaff_RBP);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c6532 name=FUN_004c6532 size=10 ====

void FUN_004c6532(void)

{
  QFileDialog *unaff_RBP;
  
  FUN_005249f0();
  FUN_005249c0(unaff_RBP + 0x30);
  QFileDialog::~QFileDialog(unaff_RBP);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c653c name=FUN_004c653c size=16 ====

void FUN_004c653c(void)

{
  FUN_00525060();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c654c name=FUN_004c654c size=40 ====

void FUN_004c654c(void)

{
  FUN_005249f0();
  FUN_005249f0();
  FUN_005249f0();
  FUN_005249f0();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c6574 name=FUN_004c6574 size=18 ====

void FUN_004c6574(void)

{
  FUN_005249f0();
  FUN_005249f0();
  FUN_005249f0();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c6586 name=FUN_004c6586 size=12 ====

void FUN_004c6586(void)

{
  FUN_005249f0();
  FUN_005249f0();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c65a0 name=FUN_004c65a0 size=42 ====

void FUN_004c65a0(void)

{
  QVariant *unaff_RBP;
  QFont *unaff_R13;
  undefined8 in_stack_00000008;
  
  QVariant::~QVariant(unaff_RBP);
  FUN_005249f0();
  FUN_005249f0(in_stack_00000008);
  QFont::~QFont(unaff_R13);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c65ca name=FUN_004c65ca size=10 ====

void FUN_004c65ca(void)

{
  QFont *unaff_R13;
  undefined8 in_stack_00000008;
  
  FUN_005249f0();
  FUN_005249f0(in_stack_00000008);
  QFont::~QFont(unaff_R13);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c65d4 name=FUN_004c65d4 size=14 ====

void FUN_004c65d4(void)

{
  QFont *unaff_R13;
  undefined8 in_stack_00000008;
  
  FUN_005249f0();
  FUN_005249f0();
  FUN_005249f0(in_stack_00000008);
  QFont::~QFont(unaff_R13);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c65e2 name=FUN_004c65e2 size=34 ====

void FUN_004c65e2(void)

{
  QIcon *unaff_R12;
  QVariant *unaff_R13;
  undefined8 in_stack_00000020;
  
  QIcon::~QIcon(unaff_R12);
  QVariant::~QVariant(unaff_R13);
  FUN_00525060(in_stack_00000020);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c6604 name=FUN_004c6604 size=31 ====

void FUN_004c6604(void)

{
  QIcon *unaff_RBX;
  QVariant *unaff_R13;
  undefined8 in_stack_00000020;
  undefined8 in_stack_00000028;
  
  QIcon::~QIcon(unaff_RBX);
  FUN_005249f0(in_stack_00000028);
  QVariant::~QVariant(unaff_R13);
  FUN_00525060(in_stack_00000020);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c6624 name=FUN_004c6624 size=85 ====

void FUN_004c6624(void)

{
  int *piVar1;
  QComboBox *unaff_RBX;
  void *unaff_RBP;
  
  operator_delete(unaff_RBP,8);
  *(undefined ***)unaff_RBX = &PTR_FUN_0119bd58;
  *(undefined ***)(unaff_RBX + 0x10) = &PTR_FUN_0119bf18;
  piVar1 = *(int **)(unaff_RBX + 0x30);
  if (piVar1 != (int *)0x0) {
    LOCK();
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if ((*piVar1 == 0) && (*(void **)(unaff_RBX + 0x30) != (void *)0x0)) {
      operator_delete(*(void **)(unaff_RBX + 0x30));
    }
  }
  QComboBox::~QComboBox(unaff_RBX);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c667a name=FUN_004c667a size=21 ====

void FUN_004c667a(void)

{
  void *unaff_R12;
  
  operator_delete(unaff_R12,0x68);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c6690 name=FUN_004c6690 size=16 ====

void FUN_004c6690(void)

{
  QStyledItemDelegate *unaff_RBX;
  
  QStyledItemDelegate::~QStyledItemDelegate(unaff_RBX);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c66a0 name=FUN_004c66a0 size=32 ====

void FUN_004c66a0(void)

{
  FUN_005249f0();
  FUN_00528c1c();
  FUN_00558a5a();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c66c0 name=FUN_004c66c0 size=13 ====

void FUN_004c66c0(void)

{
  QRegion *unaff_RBP;
  
  QRegion::~QRegion(unaff_RBP);
  FUN_00528c1c();
  FUN_00558a5a();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c66cd name=FUN_004c66cd size=13 ====

void FUN_004c66cd(void)

{
  QVariant *unaff_RBP;
  
  QVariant::~QVariant(unaff_RBP);
  FUN_00558a5a();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c66da name=FUN_004c66da size=70 ====

void FUN_004c66da(void)

{
  QStyleOption *unaff_RBX;
  
  QBrush::~QBrush((QBrush *)(unaff_RBX + 0xb8));
  FUN_005249f0(unaff_RBX + 0xa8);
  QIcon::~QIcon((QIcon *)(unaff_RBX + 0xa0));
  QLocale::~QLocale((QLocale *)(unaff_RBX + 0x70));
  QFont::~QFont((QFont *)(unaff_RBX + 0x58));
  QStyleOption::~QStyleOption(unaff_RBX);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c6720 name=FUN_004c6720 size=54 ====

void FUN_004c6720(void)

{
  QLineEdit *unaff_RBX;
  
  FUN_005249f0();
  FUN_005249f0();
  FUN_005249f0();
  FUN_005249f0();
  QLineEdit::~QLineEdit(unaff_RBX);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c6756 name=FUN_004c6756 size=16 ====

void FUN_004c6756(void)

{
  QBrush *unaff_R14;
  
  QBrush::~QBrush(unaff_R14);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c6766 name=FUN_004c6766 size=16 ====

void FUN_004c6766(void)

{
  QPen *unaff_R13;
  
  QPen::~QPen(unaff_R13);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c6776 name=FUN_004c6776 size=24 ====

void FUN_004c6776(void)

{
  QFontMetrics *unaff_RBP;
  
  FUN_005249f0();
  QFontMetrics::~QFontMetrics(unaff_RBP);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c678e name=FUN_004c678e size=32 ====

void FUN_004c678e(void)

{
  QPainter *unaff_RBP;
  QStyleOption *unaff_R12;
  
  FUN_005249f0();
  QStyleOption::~QStyleOption(unaff_R12);
  QPainter::~QPainter(unaff_RBP);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c67ae name=FUN_004c67ae size=64 ====

/* WARNING: Removing unreachable block (ram,0x004c67e3) */

void FUN_004c67ae(void)

{
  int *piVar1;
  int iVar2;
  long in_stack_00000008;
  
  if ((undefined8 *)(in_stack_00000008 + -0x18) != &std::string::_Rep::_S_empty_rep_storage) {
    LOCK();
    piVar1 = (int *)(in_stack_00000008 + -8);
    iVar2 = *piVar1;
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if (iVar2 < 1) {
      operator_delete((undefined8 *)(in_stack_00000008 + -0x18));
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c67ee name=FUN_004c67ee size=16 ====

void FUN_004c67ee(void)

{
  QStyleOption *unaff_R12;
  
  QStyleOption::~QStyleOption(unaff_R12);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c6800 name=FUN_004c6800 size=92 ====

void FUN_004c6800(void)

{
  undefined8 in_stack_00000008;
  undefined8 in_stack_00000010;
  undefined8 in_stack_00000018;
  undefined8 in_stack_00000020;
  undefined8 in_stack_00000028;
  
  FUN_005249c0();
  FUN_005249f0();
  FUN_005249f0(in_stack_00000028);
  FUN_005249f0();
  FUN_005249f0(in_stack_00000010);
  FUN_005249f0(in_stack_00000020);
  FUN_005249f0(&stack0x00000048);
  FUN_005249f0(in_stack_00000008);
  FUN_005249f0(in_stack_00000018);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c685c name=FUN_004c685c size=16 ====

void FUN_004c685c(void)

{
  QIcon *unaff_R12;
  
  QIcon::~QIcon(unaff_R12);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c686c name=FUN_004c686c size=20 ====

void FUN_004c686c(void)

{
  QVariant *unaff_RBP;
  
  QVariant::~QVariant(unaff_RBP);
  FUN_005249f0(&stack0x00000038);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c6880 name=FUN_004c6880 size=24 ====

void FUN_004c6880(void)

{
  QVariant *unaff_RBX;
  
  FUN_005249f0();
  QVariant::~QVariant(unaff_RBX);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c6898 name=FUN_004c6898 size=71 ====

void FUN_004c6898(void)

{
  char in_stack_00000008;
  undefined8 in_stack_00000010;
  undefined8 in_stack_00000020;
  
  FUN_005249f0();
  FUN_005249f0();
  if (in_stack_00000008 != '\0') {
    FUN_005249c0(&stack0x00000040);
  }
  FUN_005249f0(in_stack_00000010);
  FUN_005249f0(in_stack_00000020);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c68df name=FUN_004c68df size=10 ====

void FUN_004c68df(void)

{
  undefined8 in_stack_00000010;
  undefined8 in_stack_00000020;
  
  FUN_005249f0();
  FUN_005249f0(in_stack_00000010);
  FUN_005249f0(in_stack_00000020);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c68e9 name=FUN_004c68e9 size=16 ====

void FUN_004c68e9(void)

{
  QVariant *unaff_R14;
  
  QVariant::~QVariant(unaff_R14);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c68fa name=FUN_004c68fa size=24 ====

void FUN_004c68fa(void)

{
  QVariant *unaff_R13;
  
  FUN_005249f0();
  QVariant::~QVariant(unaff_R13);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c6912 name=FUN_004c6912 size=19 ====

void FUN_004c6912(void)

{
  bool unaff_BPL;
  
  QObject::blockSignals(unaff_BPL);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c6925 name=FUN_004c6925 size=19 ====

void FUN_004c6925(void)

{
  bool unaff_BPL;
  
  QObject::blockSignals(unaff_BPL);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c6938 name=FUN_004c6938 size=21 ====

void FUN_004c6938(void)

{
  void *unaff_R13;
  
  operator_delete(unaff_R13,0x30);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c694d name=FUN_004c694d size=21 ====

void FUN_004c694d(void)

{
  void *unaff_R14;
  
  operator_delete(unaff_R14,0x20);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c6962 name=FUN_004c6962 size=16 ====

void FUN_004c6962(void)

{
  QVariant *unaff_RBP;
  
  QVariant::~QVariant(unaff_RBP);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c6972 name=FUN_004c6972 size=16 ====

void FUN_004c6972(void)

{
  FUN_005249f0();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c6982 name=FUN_004c6982 size=87 ====

void FUN_004c6982(void)

{
  QWidget *unaff_RBP;
  Data *pDVar1;
  undefined1 *unaff_R12;
  undefined1 *puVar2;
  
  FUN_00525060();
  puVar2 = &stack0x00000050;
  do {
    puVar2 = puVar2 + -8;
    FUN_005249f0(puVar2);
  } while (puVar2 != unaff_R12);
  FUN_00525060(unaff_RBP + 0x40);
  pDVar1 = *(Data **)(unaff_RBP + 0x30);
  if (*(int *)pDVar1 != 0) {
    if (*(int *)pDVar1 == -1) goto LAB_004c69b8;
    LOCK();
    *(int *)pDVar1 = *(int *)pDVar1 + -1;
    UNLOCK();
    if (*(int *)pDVar1 != 0) goto LAB_004c69b8;
    pDVar1 = *(Data **)(unaff_RBP + 0x30);
  }
  QListData::dispose(pDVar1);
LAB_004c69b8:
  QWidget::~QWidget(unaff_RBP);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c69da name=FUN_004c69da size=21 ====

void FUN_004c69da(void)

{
  void *unaff_R12;
  
  operator_delete(unaff_R12,0x48);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c69ef name=FUN_004c69ef size=16 ====

void FUN_004c69ef(void)

{
  FUN_00534d80();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c6a00 name=FUN_004c6a00 size=45 ====

void FUN_004c6a00(void)

{
  int *piVar1;
  QToolButton *unaff_RBX;
  
  piVar1 = *(int **)(unaff_RBX + 0x30);
  if (piVar1 != (int *)0x0) {
    LOCK();
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if ((*piVar1 == 0) && (*(void **)(unaff_RBX + 0x30) != (void *)0x0)) {
      operator_delete(*(void **)(unaff_RBX + 0x30));
    }
  }
  QToolButton::~QToolButton(unaff_RBX);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c6a2e name=FUN_004c6a2e size=21 ====

void FUN_004c6a2e(void)

{
  void *unaff_RBP;
  
  operator_delete(unaff_RBP,0x20);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c6a44 name=FUN_004c6a44 size=24 ====

void FUN_004c6a44(void)

{
  QVariant *unaff_R12;
  QVariant *unaff_R13;
  
  QVariant::~QVariant(unaff_R13);
  QVariant::~QVariant(unaff_R12);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c6a5c name=FUN_004c6a5c size=10 ====

void FUN_004c6a5c(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ==== entry=004c6a70 name=FUN_004c6a70 size=16 ====

void FUN_004c6a70(void)

{
  QVariant *unaff_RBX;
  
  QVariant::~QVariant(unaff_RBX);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c6a80 name=FUN_004c6a80 size=32 ====

void FUN_004c6a80(void)

{
  QVariant *unaff_RBX;
  QIcon *unaff_R12;
  QVariant *unaff_R13;
  
  QVariant::~QVariant(unaff_RBX);
  FUN_005249f0();
  QIcon::~QIcon(unaff_R12);
  QVariant::~QVariant(unaff_R13);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c6aa0 name=FUN_004c6aa0 size=24 ====

void FUN_004c6aa0(void)

{
  QVariant *unaff_RBX;
  QVariant *unaff_R13;
  
  QVariant::~QVariant(unaff_RBX);
  QVariant::~QVariant(unaff_R13);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c6ab8 name=FUN_004c6ab8 size=10 ====

void FUN_004c6ab8(void)

{
  QVariant *unaff_R13;
  
  FUN_005249f0();
  QVariant::~QVariant(unaff_R13);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c6ac2 name=FUN_004c6ac2 size=10 ====

void FUN_004c6ac2(void)

{
  QVariant *unaff_R13;
  
  FUN_005249f0();
  QVariant::~QVariant(unaff_R13);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c6acc name=FUN_004c6acc size=57 ====

void FUN_004c6acc(void)

{
  QPushButton *unaff_RBX;
  
  FUN_005249f0();
  FUN_005249f0(unaff_RBX + 0x38);
  *(undefined ***)unaff_RBX = &PTR_FUN_011986d0;
  *(undefined ***)(unaff_RBX + 0x10) = &PTR_FUN_01198898;
  QPushButton::~QPushButton(unaff_RBX);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c6b05 name=FUN_004c6b05 size=15 ====

void FUN_004c6b05(void)

{
  QPushButton *unaff_RBX;
  void *unaff_RBP;
  
  operator_delete(unaff_RBP,0x10);
  FUN_005249f0(unaff_RBX + 0x38);
  *(undefined ***)unaff_RBX = &PTR_FUN_011986d0;
  *(undefined ***)(unaff_RBX + 0x10) = &PTR_FUN_01198898;
  QPushButton::~QPushButton(unaff_RBX);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c6b14 name=FUN_004c6b14 size=31 ====

void FUN_004c6b14(void)

{
  void *unaff_R13;
  undefined8 in_stack_00000058;
  
  operator_delete(unaff_R13,0x30);
  FUN_00525060(in_stack_00000058);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c6b33 name=FUN_004c6b33 size=12 ====

void FUN_004c6b33(void)

{
  undefined8 in_stack_00000028;
  undefined8 in_stack_00000058;
  
  FUN_005249f0(in_stack_00000028);
  FUN_00525060(in_stack_00000058);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c6b3f name=FUN_004c6b3f size=23 ====

void FUN_004c6b3f(void)

{
  void *in_stack_00000048;
  
  operator_delete(in_stack_00000048,0x20);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c6b56 name=FUN_004c6b56 size=23 ====

void FUN_004c6b56(void)

{
  void *in_stack_00000040;
  
  operator_delete(in_stack_00000040,0x30);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c6b6d name=FUN_004c6b6d size=23 ====

void FUN_004c6b6d(void)

{
  void *in_stack_00000068;
  
  operator_delete(in_stack_00000068,0x30);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c6b84 name=FUN_004c6b84 size=35 ====

void FUN_004c6b84(void)

{
  undefined8 in_stack_00000020;
  QIcon *in_stack_00000028;
  undefined8 in_stack_00000030;
  undefined8 in_stack_00000058;
  
  QIcon::~QIcon(in_stack_00000028);
  FUN_005249f0(in_stack_00000030);
  FUN_005249f0(in_stack_00000020);
  FUN_00525060(in_stack_00000058);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c6ba7 name=FUN_004c6ba7 size=18 ====

void FUN_004c6ba7(void)

{
  undefined8 in_stack_00000058;
  
  FUN_005249f0(&stack0x000000a0);
  FUN_00525060(in_stack_00000058);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c6bb9 name=FUN_004c6bb9 size=20 ====

void FUN_004c6bb9(void)

{
  FUN_005249f0();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c6bce name=FUN_004c6bce size=21 ====

void FUN_004c6bce(void)

{
  void *unaff_RBP;
  
  operator_delete(unaff_RBP,0x58);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c6be4 name=FUN_004c6be4 size=41 ====

void FUN_004c6be4(void)

{
  QFrame *unaff_RBX;
  
  *(undefined ***)unaff_RBX = &PTR_FUN_01193238;
  *(undefined ***)(unaff_RBX + 0x10) = &PTR_FUN_011933e8;
  QFrame::~QFrame(unaff_RBX);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c6c0e name=FUN_004c6c0e size=16 ====

void FUN_004c6c0e(void)

{
  QVariant *unaff_RBX;
  
  QVariant::~QVariant(unaff_RBX);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c6c1e name=FUN_004c6c1e size=52 ====

void FUN_004c6c1e(void)

{
  QArrayData *in_stack_00000030;
  
  if (*(int *)in_stack_00000030 != 0) {
    if (*(int *)in_stack_00000030 == -1) goto LAB_004c6c38;
    LOCK();
    *(int *)in_stack_00000030 = *(int *)in_stack_00000030 + -1;
    UNLOCK();
    if (*(int *)in_stack_00000030 != 0) goto LAB_004c6c38;
  }
  QArrayData::deallocate(in_stack_00000030,1,8);
LAB_004c6c38:
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c6c40 name=FUN_004c6c40 size=60 ====

/* WARNING: Removing unreachable block (ram,0x004c6ca3) */

void FUN_004c6c40(void)

{
  int *piVar1;
  int iVar2;
  void *unaff_RBX;
  long in_stack_00000028;
  
  if ((void *)(in_stack_00000028 + -0x18) != unaff_RBX) {
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
  FUN_00c86f70();
}


// ==== entry=004c6c83 name=FUN_004c6c83 size=16 ====

void FUN_004c6c83(void)

{
  QVariant *unaff_R14;
  
  QVariant::~QVariant(unaff_R14);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c6c93 name=FUN_004c6c93 size=16 ====

void FUN_004c6c93(void)

{
  FUN_005249f0();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c6cae name=FUN_004c6cae size=32 ====

void FUN_004c6cae(void)

{
  QListWidget *unaff_RBX;
  void *unaff_RBP;
  
  operator_delete(unaff_RBP,0xb0);
  QListWidget::~QListWidget(unaff_RBX);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c6cce name=FUN_004c6cce size=22 ====

void FUN_004c6cce(void)

{
  QListWidget *unaff_RBX;
  
  FUN_005249f0();
  FUN_005249f0(unaff_RBX + 0x48);
  QListWidget::~QListWidget(unaff_RBX);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c6ce4 name=FUN_004c6ce4 size=16 ====

void FUN_004c6ce4(void)

{
  QVariant *unaff_R14;
  
  QVariant::~QVariant(unaff_R14);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c6cf4 name=FUN_004c6cf4 size=21 ====

void FUN_004c6cf4(void)

{
  void *unaff_RBP;
  
  operator_delete(unaff_RBP,0x20);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c6d0a name=FUN_004c6d0a size=27 ====

void FUN_004c6d0a(void)

{
  QVariant *unaff_RBX;
  
  QVariant::~QVariant(unaff_RBX);
  FUN_0055fa30();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c6d25 name=FUN_004c6d25 size=16 ====

void FUN_004c6d25(void)

{
  FUN_005249f0();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c6d35 name=FUN_004c6d35 size=10 ====

void FUN_004c6d35(void)

{
  QVariant *unaff_R14;
  
  QVariant::~QVariant(unaff_R14);
  FUN_0055fa30();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c6d40 name=FUN_004c6d40 size=16 ====

void FUN_004c6d40(void)

{
  FUN_005249f0();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c6d50 name=FUN_004c6d50 size=68 ====

void FUN_004c6d50(void)

{
  QLocale *unaff_RBP;
  QDateTime *unaff_R12;
  undefined8 in_stack_00000010;
  undefined8 in_stack_00000018;
  
  FUN_005249f0();
  FUN_005249f0();
  FUN_005249f0();
  FUN_005249f0(in_stack_00000018);
  QDateTime::~QDateTime(unaff_R12);
  QLocale::~QLocale(unaff_RBP);
  FUN_005249f0(in_stack_00000010);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c6d94 name=FUN_004c6d94 size=10 ====

void FUN_004c6d94(void)

{
  QLocale *unaff_RBP;
  QDateTime *unaff_R12;
  undefined8 in_stack_00000010;
  undefined8 in_stack_00000018;
  
  FUN_005249f0();
  FUN_005249f0();
  FUN_005249f0();
  FUN_005249f0(in_stack_00000018);
  QDateTime::~QDateTime(unaff_R12);
  QLocale::~QLocale(unaff_RBP);
  FUN_005249f0(in_stack_00000010);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c6d9e name=FUN_004c6d9e size=32 ====

void FUN_004c6d9e(void)

{
  FUN_005249f0();
  FUN_005249f0();
  FUN_005249f0();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c6dbe name=FUN_004c6dbe size=21 ====

void FUN_004c6dbe(void)

{
  void *unaff_R13;
  
  operator_delete(unaff_R13,0x20);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c6dd3 name=FUN_004c6dd3 size=16 ====

void FUN_004c6dd3(void)

{
  FUN_005249f0();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c6de3 name=FUN_004c6de3 size=29 ====

void FUN_004c6de3(void)

{
  void *unaff_R13;
  
  operator_delete(unaff_R13,0x30);
  FUN_005249f0();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c6e00 name=FUN_004c6e00 size=21 ====

void FUN_004c6e00(void)

{
  void *unaff_R12;
  
  operator_delete(unaff_R12,0x90);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c6e15 name=FUN_004c6e15 size=21 ====

void FUN_004c6e15(void)

{
  void *unaff_R12;
  
  operator_delete(unaff_R12,0x30);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c6e2a name=FUN_004c6e2a size=21 ====

void FUN_004c6e2a(void)

{
  void *unaff_R12;
  
  operator_delete(unaff_R12,0x30);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c6e3f name=FUN_004c6e3f size=21 ====

void FUN_004c6e3f(void)

{
  void *unaff_R12;
  
  operator_delete(unaff_R12,0x30);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c6e54 name=FUN_004c6e54 size=21 ====

void FUN_004c6e54(void)

{
  void *unaff_R12;
  
  operator_delete(unaff_R12,0x30);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c6e69 name=FUN_004c6e69 size=21 ====

void FUN_004c6e69(void)

{
  void *unaff_R12;
  
  operator_delete(unaff_R12,0x90);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c6e7e name=FUN_004c6e7e size=21 ====

void FUN_004c6e7e(void)

{
  void *unaff_R12;
  
  operator_delete(unaff_R12,0x90);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c6e93 name=FUN_004c6e93 size=29 ====

void FUN_004c6e93(void)

{
  void *unaff_R12;
  
  operator_delete(unaff_R12,0x30);
  FUN_005249f0();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c6eb0 name=FUN_004c6eb0 size=29 ====

void FUN_004c6eb0(void)

{
  void *unaff_R13;
  
  operator_delete(unaff_R13,0x30);
  FUN_005249f0();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c6ecd name=FUN_004c6ecd size=21 ====

void FUN_004c6ecd(void)

{
  void *unaff_R14;
  
  operator_delete(unaff_R14,0x20);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c6ee2 name=FUN_004c6ee2 size=21 ====

void FUN_004c6ee2(void)

{
  void *unaff_R12;
  
  operator_delete(unaff_R12,0x20);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c6ef8 name=FUN_004c6ef8 size=27 ====

void FUN_004c6ef8(void)

{
  QWidget *unaff_RBX;
  
  FUN_005249f0();
  QWidget::~QWidget(unaff_RBX);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c6f14 name=FUN_004c6f14 size=29 ====

void FUN_004c6f14(void)

{
  void *unaff_R12;
  
  operator_delete(unaff_R12,0x40);
  FUN_005249f0();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c6f32 name=FUN_004c6f32 size=24 ====

void FUN_004c6f32(void)

{
  FUN_00534d80();
  FUN_005249f0();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c6f4a name=FUN_004c6f4a size=16 ====

void FUN_004c6f4a(void)

{
  FUN_00534d80();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c6f5a name=FUN_004c6f5a size=21 ====

void FUN_004c6f5a(void)

{
  void *unaff_RBP;
  
  operator_delete(unaff_RBP,0x20);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c6f6f name=FUN_004c6f6f size=16 ====

void FUN_004c6f6f(void)

{
  FUN_00534d80();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c6f80 name=FUN_004c6f80 size=16 ====

void FUN_004c6f80(void)

{
  FUN_00534d80();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c6f90 name=FUN_004c6f90 size=16 ====

void FUN_004c6f90(void)

{
  FUN_005249f0();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c6fa0 name=FUN_004c6fa0 size=16 ====

void FUN_004c6fa0(void)

{
  FUN_005249f0();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c6fb0 name=FUN_004c6fb0 size=16 ====

void FUN_004c6fb0(void)

{
  FUN_005249f0();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c6fc0 name=FUN_004c6fc0 size=16 ====

void FUN_004c6fc0(void)

{
  FUN_005249f0();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c6fd0 name=FUN_004c6fd0 size=21 ====

void FUN_004c6fd0(void)

{
  void *unaff_R12;
  
  operator_delete(unaff_R12,0x20);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c6fe5 name=FUN_004c6fe5 size=21 ====

void FUN_004c6fe5(void)

{
  void *unaff_R13;
  
  operator_delete(unaff_R13,0x20);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c6ffa name=FUN_004c6ffa size=16 ====

void FUN_004c6ffa(void)

{
  FUN_00534d80();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c700a name=FUN_004c700a size=16 ====

void FUN_004c700a(void)

{
  FUN_005249f0();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c701a name=FUN_004c701a size=16 ====

void FUN_004c701a(void)

{
  FUN_005249f0();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c702a name=FUN_004c702a size=21 ====

void FUN_004c702a(void)

{
  void *unaff_RBP;
  
  operator_delete(unaff_RBP,0x20);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c7040 name=FUN_004c7040 size=21 ====

void FUN_004c7040(void)

{
  void *unaff_R12;
  
  operator_delete(unaff_R12,0x30);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c7055 name=FUN_004c7055 size=40 ====

void FUN_004c7055(void)

{
  FUN_005249f0();
  FUN_005249f0();
  FUN_005249f0();
  FUN_005249f0();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c707d name=FUN_004c707d size=16 ====

void FUN_004c707d(void)

{
  FUN_005249f0();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c708d name=FUN_004c708d size=16 ====

void FUN_004c708d(void)

{
  FUN_005249f0();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c709d name=FUN_004c709d size=10 ====

void FUN_004c709d(void)

{
  FUN_005249f0();
  FUN_005249f0();
  FUN_005249f0();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c70a8 name=FUN_004c70a8 size=16 ====

void FUN_004c70a8(void)

{
  FUN_005249f0();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c70c0 name=FUN_004c70c0 size=16 ====

void FUN_004c70c0(void)

{
  QVariant *unaff_RBP;
  
  QVariant::~QVariant(unaff_RBP);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c70d0 name=FUN_004c70d0 size=27 ====

void FUN_004c70d0(void)

{
  QProgressBar *unaff_RBX;
  
  FUN_005249f0();
  QProgressBar::~QProgressBar(unaff_RBX);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c70eb name=FUN_004c70eb size=13 ====

void FUN_004c70eb(void)

{
  QProgressBar *unaff_RBX;
  
  FUN_005249f0();
  QProgressBar::~QProgressBar(unaff_RBX);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c70f8 name=FUN_004c70f8 size=40 ====

void FUN_004c70f8(void)

{
  QRegularExpression *unaff_R12;
  
  QRegularExpression::~QRegularExpression(unaff_R12);
  FUN_005249f0();
  FUN_005249f0();
  FUN_005249f0();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c7120 name=FUN_004c7120 size=32 ====

void FUN_004c7120(void)

{
  FUN_005249f0();
  FUN_005249f0();
  FUN_005249f0();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c7140 name=FUN_004c7140 size=13 ====

void FUN_004c7140(void)

{
  FUN_005249f0();
  FUN_005249f0();
  FUN_005249f0();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c714d name=FUN_004c714d size=13 ====

void FUN_004c714d(void)

{
  FUN_005249f0();
  FUN_005249f0();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c715a name=FUN_004c715a size=27 ====

void FUN_004c715a(void)

{
  FUN_005249f0();
  FUN_005249f0();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c7175 name=FUN_004c7175 size=21 ====

void FUN_004c7175(void)

{
  FUN_005249f0();
  FUN_005249f0();
  FUN_005249f0();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c718a name=FUN_004c718a size=21 ====

void FUN_004c718a(void)

{
  void *unaff_RBX;
  
  operator_delete(unaff_RBX,0x30);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c719f name=FUN_004c719f size=16 ====

void FUN_004c719f(void)

{
  FUN_005249f0();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c71af name=FUN_004c71af size=16 ====

void FUN_004c71af(void)

{
  FUN_005249f0();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c71bf name=FUN_004c71bf size=16 ====

void FUN_004c71bf(void)

{
  FUN_005249f0();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c71d0 name=FUN_004c71d0 size=21 ====

void FUN_004c71d0(void)

{
  void *unaff_RBX;
  
  operator_delete(unaff_RBX,0x10);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c71e5 name=FUN_004c71e5 size=21 ====

void FUN_004c71e5(void)

{
  void *unaff_R12;
  
  operator_delete(unaff_R12,0x10);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c71fa name=FUN_004c71fa size=78 ====

void FUN_004c71fa(void)

{
  int *piVar1;
  QLineEdit *unaff_RBX;
  
  *(undefined ***)unaff_RBX = &PTR_FUN_01198458;
  *(undefined ***)(unaff_RBX + 0x10) = &PTR_FUN_01198608;
  FUN_00544670(unaff_RBX + 0x50);
  piVar1 = *(int **)(unaff_RBX + 0x30);
  if (piVar1 != (int *)0x0) {
    LOCK();
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if ((*piVar1 == 0) && (*(void **)(unaff_RBX + 0x30) != (void *)0x0)) {
      operator_delete(*(void **)(unaff_RBX + 0x30));
    }
  }
  QLineEdit::~QLineEdit(unaff_RBX);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c7250 name=FUN_004c7250 size=26 ====

void FUN_004c7250(undefined8 param_1,undefined8 param_2,long param_3)

{
  int *piVar1;
  long lVar2;
  long *plVar3;
  int iVar4;
  long *plVar5;
  long *plVar6;
  long *plVar7;
  long *plVar8;
  Node *unaff_R12;
  long unaff_R13;
  Node *unaff_R14;
  undefined8 in_stack_00000008;
  
  if (param_3 != 1) {
                    /* WARNING: Subroutine does not return */
    FUN_00c86f70();
  }
  __cxa_begin_catch();
  __cxa_end_catch();
  do {
    do {
      do {
        unaff_R12 = (Node *)QHashData::nextNode(unaff_R12);
        if (unaff_R14 == unaff_R12) {
          return;
        }
      } while (*(int *)(*(long *)(unaff_R13 + 0x30) + 0x14) == 0);
      if (1 < *(uint *)(*(long *)(unaff_R13 + 0x30) + 0x10)) {
        FUN_005629a0(in_stack_00000008);
      }
      plVar5 = (long *)FUN_00562d90(in_stack_00000008,unaff_R12 + 0xc,0);
      plVar3 = (long *)*plVar5;
      plVar8 = *(long **)(unaff_R13 + 0x30);
    } while (plVar3 == plVar8);
    plVar6 = (long *)*plVar3;
    if ((plVar8 != plVar6) &&
       (plVar7 = plVar6, *(int *)((long)plVar3 + 0xc) == *(int *)((long)plVar6 + 0xc))) {
      do {
        QHashData::freeNode(plVar8);
        *plVar5 = (long)plVar7;
        plVar8 = *(long **)(unaff_R13 + 0x30);
        *(int *)((long)plVar8 + 0x14) = *(int *)((long)plVar8 + 0x14) + -1;
        plVar6 = (long *)*plVar7;
        if (plVar6 == plVar8) break;
        piVar1 = (int *)((long)plVar7 + 0xc);
        plVar7 = plVar6;
      } while (*(int *)((long)plVar6 + 0xc) == *piVar1);
    }
    QHashData::freeNode(plVar8);
    *plVar5 = (long)plVar6;
    lVar2 = *(long *)(unaff_R13 + 0x30);
    iVar4 = *(int *)(lVar2 + 0x14) + -1;
    *(int *)(lVar2 + 0x14) = iVar4;
    if ((iVar4 <= *(int *)(lVar2 + 0x20) >> 3) &&
       (*(short *)(lVar2 + 0x1c) < *(short *)(lVar2 + 0x1e))) {
      QHashData::rehash((int)lVar2);
    }
  } while( true );
}


// ==== entry=004c7270 name=FUN_004c7270 size=48 ====

/* WARNING: Removing unreachable block (ram,0x004c728d) */

void FUN_004c7270(undefined8 *param_1)

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


// ==== entry=004c72a0 name=FUN_004c72a0 size=16 ====

void FUN_004c72a0(void)

{
  QVariant *unaff_RBP;
  
  QVariant::~QVariant(unaff_RBP);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c72b0 name=FUN_004c72b0 size=29 ====

void FUN_004c72b0(void)

{
  FUN_005249f0();
  FUN_005249f0(&stack0x00000008);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c72ce name=FUN_004c72ce size=16 ====

void FUN_004c72ce(void)

{
  FUN_00563e60();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c72de name=FUN_004c72de size=21 ====

void FUN_004c72de(void)

{
  void *unaff_RBP;
  
  operator_delete(unaff_RBP,0x38);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c72f3 name=FUN_004c72f3 size=16 ====

void FUN_004c72f3(void)

{
  FUN_00563e60();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c7304 name=FUN_004c7304 size=68 ====

void FUN_004c7304(void)

{
  QFrame *unaff_RBX;
  
  FUN_005249f0(unaff_RBX + 0x60);
  FUN_005249f0(unaff_RBX + 0x58);
  FUN_00525060(unaff_RBX + 0x50);
  *(undefined ***)unaff_RBX = &PTR_FUN_01193238;
  *(undefined ***)(unaff_RBX + 0x10) = &PTR_FUN_011933e8;
  QFrame::~QFrame(unaff_RBX);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c7348 name=FUN_004c7348 size=129 ====

/* WARNING: Removing unreachable block (ram,0x004c7414) */

void FUN_004c7348(void)

{
  void *pvVar1;
  int *piVar2;
  int iVar3;
  void *unaff_R13;
  long *plVar4;
  _Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *unaff_R15;
  long in_stack_00000018;
  long *in_stack_00000040;
  long *in_stack_00000048;
  
  FUN_005249f0();
  for (plVar4 = in_stack_00000040; in_stack_00000048 != plVar4; plVar4 = plVar4 + 2) {
    pvVar1 = (void *)(*plVar4 + -0x18);
    if (pvVar1 != unaff_R13) {
      LOCK();
      piVar2 = (int *)(*plVar4 + -8);
      iVar3 = *piVar2;
      *piVar2 = *piVar2 + -1;
      UNLOCK();
      if (iVar3 < 1) {
        operator_delete(pvVar1);
      }
    }
  }
  if (in_stack_00000040 != (long *)0x0) {
    operator_delete(in_stack_00000040);
  }
  FUN_00525060();
  if (unaff_R15 != (_Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *)0x0) {
    std::_Sp_counted_base<(__gnu_cxx::_Lock_policy)2>::_M_release(unaff_R15);
  }
  FUN_004c7270(in_stack_00000018 + -0x18);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c7399 name=FUN_004c7399 size=32 ====

/* WARNING: Removing unreachable block (ram,0x004c737b) */

void FUN_004c7399(void)

{
  long in_stack_00000018;
  long in_stack_00000038;
  
  FUN_004c7270(in_stack_00000038 + -0x18);
  FUN_005249f0();
  FUN_00525060(&stack0x00000020);
  FUN_004c7270(in_stack_00000018 + -0x18);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c73b9 name=FUN_004c73b9 size=15 ====

void FUN_004c73b9(void)

{
  _Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *unaff_R15;
  long in_stack_00000018;
  
  FUN_005249f0();
  FUN_00525060(&stack0x00000020);
  if (unaff_R15 != (_Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *)0x0) {
    std::_Sp_counted_base<(__gnu_cxx::_Lock_policy)2>::_M_release(unaff_R15);
  }
  FUN_004c7270(in_stack_00000018 + -0x18);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c73f8 name=FUN_004c73f8 size=50 ====

/* WARNING: Removing unreachable block (ram,0x004c737b) */

void FUN_004c73f8(void)

{
  long in_stack_00000018;
  QArrayData *in_stack_00000030;
  
  if (*(int *)in_stack_00000030 != 0) {
    if (*(int *)in_stack_00000030 == -1) goto LAB_004c736e;
    LOCK();
    *(int *)in_stack_00000030 = *(int *)in_stack_00000030 + -1;
    UNLOCK();
    if (*(int *)in_stack_00000030 != 0) goto LAB_004c736e;
  }
  QArrayData::deallocate(in_stack_00000030,1,8);
LAB_004c736e:
  FUN_005249f0();
  FUN_00525060(&stack0x00000020);
  FUN_004c7270(in_stack_00000018 + -0x18);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c7436 name=FUN_004c7436 size=16 ====

void FUN_004c7436(void)

{
  FUN_005249f0();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c7446 name=FUN_004c7446 size=32 ====

void FUN_004c7446(void)

{
  QIcon *unaff_RBP;
  
  QIcon::~QIcon(unaff_RBP);
  FUN_005249f0();
  FUN_005249f0();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c7466 name=FUN_004c7466 size=32 ====

void FUN_004c7466(void)

{
  QIcon *unaff_RBP;
  
  QIcon::~QIcon(unaff_RBP);
  FUN_005249f0();
  FUN_005249f0();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c7486 name=FUN_004c7486 size=16 ====

void FUN_004c7486(void)

{
  QCursor *unaff_RBP;
  
  QCursor::~QCursor(unaff_RBP);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c7496 name=FUN_004c7496 size=21 ====

void FUN_004c7496(void)

{
  void *unaff_RBP;
  
  operator_delete(unaff_RBP,0x30);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c74ab name=FUN_004c74ab size=16 ====

void FUN_004c74ab(void)

{
  FUN_005249f0();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c74bc name=FUN_004c74bc size=24 ====

void FUN_004c74bc(void)

{
  QPainter *unaff_RBP;
  QStyleOption *unaff_R12;
  
  QStyleOption::~QStyleOption(unaff_R12);
  QPainter::~QPainter(unaff_RBP);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c74d4 name=FUN_004c74d4 size=16 ====

void FUN_004c74d4(void)

{
  QStyleOption *unaff_RBX;
  
  QStyleOption::~QStyleOption(unaff_RBX);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c74e4 name=FUN_004c74e4 size=90 ====

void FUN_004c74e4(void)

{
  int *piVar1;
  QLineEdit *unaff_RBX;
  
  FUN_005249f0(unaff_RBX + 0x88);
  *(undefined ***)unaff_RBX = &PTR_FUN_01198458;
  *(undefined ***)(unaff_RBX + 0x10) = &PTR_FUN_01198608;
  FUN_00544670(unaff_RBX + 0x50);
  piVar1 = *(int **)(unaff_RBX + 0x30);
  if (piVar1 != (int *)0x0) {
    LOCK();
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if ((*piVar1 == 0) && (*(void **)(unaff_RBX + 0x30) != (void *)0x0)) {
      operator_delete(*(void **)(unaff_RBX + 0x30));
    }
  }
  QLineEdit::~QLineEdit(unaff_RBX);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c7540 name=FUN_004c7540 size=27 ====

void FUN_004c7540(void)

{
  FUN_005249f0();
  FUN_005249f0(&stack0x00000000);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c755b name=FUN_004c755b size=10 ====

void FUN_004c755b(void)

{
  QVariant *unaff_RBP;
  
  QVariant::~QVariant(unaff_RBP);
  FUN_005249f0();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c7566 name=FUN_004c7566 size=21 ====

void FUN_004c7566(void)

{
  void *unaff_R13;
  
  operator_delete(unaff_R13,0x10);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c757b name=FUN_004c757b size=28 ====

void FUN_004c757b(void)

{
  FUN_005249f0(&stack0x00000058);
  FUN_005249f0(&stack0x00000048);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c7597 name=FUN_004c7597 size=29 ====

void FUN_004c7597(void)

{
  void *unaff_R12;
  
  operator_delete(unaff_R12,0x30);
  FUN_005249f0();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c75b4 name=FUN_004c75b4 size=24 ====

void FUN_004c75b4(void)

{
  QKeySequence *unaff_RBX;
  
  QKeySequence::~QKeySequence(unaff_RBX);
  FUN_005249f0();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c75cc name=FUN_004c75cc size=12 ====

void FUN_004c75cc(void)

{
  undefined8 in_stack_00000028;
  
  FUN_005249f0(in_stack_00000028);
  FUN_005249f0(&stack0x00000048);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c75d8 name=FUN_004c75d8 size=16 ====

void FUN_004c75d8(void)

{
  FUN_005249f0();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c75e8 name=FUN_004c75e8 size=16 ====

void FUN_004c75e8(void)

{
  FUN_005249f0();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c75f8 name=FUN_004c75f8 size=16 ====

void FUN_004c75f8(void)

{
  FUN_005249f0();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c7608 name=FUN_004c7608 size=24 ====

void FUN_004c7608(void)

{
  QJsonDocument *unaff_RBX;
  
  QJsonDocument::~QJsonDocument(unaff_RBX);
  FUN_005249c0();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c7620 name=FUN_004c7620 size=43 ====

void FUN_004c7620(void)

{
  QJsonObject *unaff_R12;
  QJsonValue *unaff_R14;
  
  QJsonValue::~QJsonValue(unaff_R14);
  FUN_005249f0();
  FUN_005249f0();
  QJsonObject::~QJsonObject(unaff_R12);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c764b name=FUN_004c764b size=21 ====

void FUN_004c764b(void)

{
  QJsonValue *unaff_RBX;
  QJsonObject *unaff_R12;
  
  QJsonValue::~QJsonValue(unaff_RBX);
  FUN_005249f0();
  FUN_005249f0();
  QJsonObject::~QJsonObject(unaff_R12);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c7660 name=FUN_004c7660 size=21 ====

void FUN_004c7660(void)

{
  QJsonValue *unaff_RBX;
  QJsonObject *unaff_R12;
  
  QJsonValue::~QJsonValue(unaff_RBX);
  FUN_005249f0();
  QJsonObject::~QJsonObject(unaff_R12);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c7675 name=FUN_004c7675 size=21 ====

void FUN_004c7675(void)

{
  QJsonValue *unaff_RBP;
  QJsonObject *unaff_R12;
  
  QJsonValue::~QJsonValue(unaff_RBP);
  FUN_005249f0();
  FUN_005249f0();
  QJsonObject::~QJsonObject(unaff_R12);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c768a name=FUN_004c768a size=35 ====

void FUN_004c768a(void)

{
  QJsonValue *unaff_RBX;
  QJsonObject *unaff_R12;
  
  FUN_005249f0();
  QJsonValue::~QJsonValue(unaff_RBX);
  QJsonObject::~QJsonObject(unaff_R12);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c76ad name=FUN_004c76ad size=29 ====

void FUN_004c76ad(void)

{
  QJsonValue *unaff_RBX;
  QJsonObject *unaff_R12;
  
  FUN_005249f0();
  QJsonValue::~QJsonValue(unaff_RBX);
  FUN_005249f0();
  QJsonObject::~QJsonObject(unaff_R12);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c76ca name=FUN_004c76ca size=13 ====

void FUN_004c76ca(void)

{
  QJsonValue *unaff_RBX;
  QJsonObject *unaff_R12;
  
  FUN_005249f0();
  QJsonValue::~QJsonValue(unaff_RBX);
  QJsonObject::~QJsonObject(unaff_R12);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c76d7 name=FUN_004c76d7 size=21 ====

void FUN_004c76d7(void)

{
  QJsonDocument *unaff_RBP;
  QJsonObject *unaff_R12;
  
  FUN_005249c0();
  QJsonDocument::~QJsonDocument(unaff_RBP);
  QJsonObject::~QJsonObject(unaff_R12);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c76ec name=FUN_004c76ec size=13 ====

void FUN_004c76ec(void)

{
  QJsonValue *unaff_RBX;
  QJsonObject *unaff_R12;
  
  FUN_005249f0();
  QJsonValue::~QJsonValue(unaff_RBX);
  QJsonObject::~QJsonObject(unaff_R12);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c76fa name=FUN_004c76fa size=78 ====

void FUN_004c76fa(void)

{
  int *piVar1;
  QLineEdit *unaff_RBX;
  
  *(undefined ***)unaff_RBX = &PTR_FUN_01198458;
  *(undefined ***)(unaff_RBX + 0x10) = &PTR_FUN_01198608;
  FUN_00544670(unaff_RBX + 0x50);
  piVar1 = *(int **)(unaff_RBX + 0x30);
  if (piVar1 != (int *)0x0) {
    LOCK();
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if ((*piVar1 == 0) && (*(void **)(unaff_RBX + 0x30) != (void *)0x0)) {
      operator_delete(*(void **)(unaff_RBX + 0x30));
    }
  }
  QLineEdit::~QLineEdit(unaff_RBX);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c7748 name=FUN_004c7748 size=96 ====

void FUN_004c7748(void)

{
  undefined8 in_RAX;
  QWidget *unaff_RBX;
  QCursor *unaff_RBP;
  QBrush *unaff_R12;
  QBrush *unaff_R13;
  QBrush *unaff_R14;
  QBrush *unaff_R15;
  undefined8 uStack0000000000000008;
  
  uStack0000000000000008 = in_RAX;
  QCursor::~QCursor(unaff_RBP);
  QBrush::~QBrush(unaff_R15);
  QBrush::~QBrush(unaff_R14);
  QBrush::~QBrush(unaff_R13);
  QBrush::~QBrush(unaff_R12);
  QBrush::~QBrush((QBrush *)(unaff_RBX + 0x60));
  QVariant::~QVariant((QVariant *)(unaff_RBX + 0x40));
  FUN_005249f0(unaff_RBX + 0x38);
  QWidget::~QWidget(unaff_RBX);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70(uStack0000000000000008);
}


// ==== entry=004c77a8 name=FUN_004c77a8 size=27 ====

void FUN_004c77a8(void)

{
  QFontMetrics *unaff_RBX;
  
  FUN_005249f0();
  QFontMetrics::~QFontMetrics(unaff_RBX);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c77c4 name=FUN_004c77c4 size=42 ====

void FUN_004c77c4(void)

{
  QFontMetrics *unaff_RBX;
  QStyleOption *unaff_RBP;
  
  QFontMetrics::~QFontMetrics(unaff_RBX);
  QIcon::~QIcon((QIcon *)(unaff_RBP + 0x50));
  FUN_005249f0(unaff_RBP + 0x48);
  QStyleOption::~QStyleOption(unaff_RBP);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c77ee name=FUN_004c77ee size=21 ====

void FUN_004c77ee(void)

{
  void *unaff_R12;
  
  operator_delete(unaff_R12,0x10);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c7804 name=FUN_004c7804 size=21 ====

void FUN_004c7804(void)

{
  void *unaff_RBP;
  
  operator_delete(unaff_RBP,0x10);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c781a name=FUN_004c781a size=50 ====

void FUN_004c781a(void)

{
  QDateTime *unaff_RBP;
  
  FUN_005249f0();
  FUN_005249f0();
  FUN_005249f0();
  QDateTime::~QDateTime(unaff_RBP);
  FUN_005249f0(&stack0x00000008);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c784c name=FUN_004c784c size=16 ====

void FUN_004c784c(void)

{
  FUN_005249f0();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c785c name=FUN_004c785c size=40 ====

void FUN_004c785c(void)

{
  QPainter *unaff_RBP;
  QBrush *unaff_R12;
  QPen *unaff_R13;
  QBrush *unaff_R14;
  
  QBrush::~QBrush(unaff_R14);
  QPen::~QPen(unaff_R13);
  QBrush::~QBrush(unaff_R12);
  QPainter::~QPainter(unaff_RBP);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c7884 name=FUN_004c7884 size=36 ====

void FUN_004c7884(void)

{
  QTableWidget *unaff_RBX;
  
  FUN_005249f0();
  FUN_005249f0(unaff_RBX + 0x38);
  QTableWidget::~QTableWidget(unaff_RBX);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c78b0 name=FUN_004c78b0 size=21 ====

void FUN_004c78b0(void)

{
  void *unaff_RBP;
  
  operator_delete(unaff_RBP,0x78);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c78c6 name=FUN_004c78c6 size=42 ====

void FUN_004c78c6(void)

{
  long unaff_RBP;
  
  FUN_00525060();
  FUN_005249f0(unaff_RBP + 0x10);
  FUN_005249f0(unaff_RBP + 8);
  FUN_005249f0();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c78f0 name=FUN_004c78f0 size=21 ====

void FUN_004c78f0(void)

{
  void *unaff_RBX;
  
  operator_delete(unaff_RBX,0x18);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c7905 name=FUN_004c7905 size=10 ====

void FUN_004c7905(void)

{
  long unaff_RBP;
  
  FUN_00525060();
  FUN_005249f0(unaff_RBP + 0x10);
  FUN_005249f0(unaff_RBP + 8);
  FUN_005249f0();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c790f name=FUN_004c790f size=16 ====

void FUN_004c790f(void)

{
  FUN_005249f0();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c7920 name=FUN_004c7920 size=41 ====

void FUN_004c7920(void)

{
  QFrame *unaff_RBX;
  
  *(undefined ***)unaff_RBX = &PTR_FUN_01193238;
  *(undefined ***)(unaff_RBX + 0x10) = &PTR_FUN_011933e8;
  QFrame::~QFrame(unaff_RBX);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c794a name=FUN_004c794a size=34 ====

void FUN_004c794a(void)

{
  QVariant *unaff_R12;
  QVariant *unaff_R14;
  undefined8 in_stack_00000008;
  
  QVariant::~QVariant(unaff_R12);
  FUN_005249f0(in_stack_00000008);
  QVariant::~QVariant(unaff_R14);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c796c name=FUN_004c796c size=51 ====

void FUN_004c796c(void)

{
  void *in_stack_00000010;
  undefined8 in_stack_00000018;
  undefined8 in_stack_00000020;
  
  operator_delete(in_stack_00000010,0x30);
  FUN_005249f0();
  FUN_005249f0(in_stack_00000020);
  FUN_005249f0(in_stack_00000018);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c799f name=FUN_004c799f size=10 ====

void FUN_004c799f(void)

{
  QVariant *unaff_R12;
  undefined8 in_stack_00000018;
  undefined8 in_stack_00000020;
  
  QVariant::~QVariant(unaff_R12);
  FUN_005249f0(in_stack_00000020);
  FUN_005249f0(in_stack_00000018);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c79a9 name=FUN_004c79a9 size=28 ====

void FUN_004c79a9(void)

{
  QVariant *unaff_R12;
  QVariant *unaff_R14;
  undefined8 in_stack_00000008;
  undefined8 in_stack_00000018;
  
  QVariant::~QVariant(unaff_R12);
  FUN_005249f0(in_stack_00000008);
  QVariant::~QVariant(unaff_R14);
  FUN_005249f0(in_stack_00000018);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c79c5 name=FUN_004c79c5 size=51 ====

void FUN_004c79c5(void)

{
  QRegularExpression *unaff_R14;
  void *unaff_R15;
  undefined8 in_stack_00000008;
  undefined8 in_stack_00000018;
  undefined8 in_stack_00000020;
  undefined8 in_stack_00000038;
  
  operator_delete(unaff_R15,0x30);
  QRegularExpression::~QRegularExpression(unaff_R14);
  FUN_005249f0();
  FUN_005249f0(in_stack_00000008);
  FUN_005249f0(in_stack_00000038);
  FUN_005249f0(in_stack_00000020);
  FUN_005249f0(in_stack_00000018);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c79f8 name=FUN_004c79f8 size=41 ====

void FUN_004c79f8(void)

{
  QRegularExpression *unaff_R14;
  void *unaff_R15;
  undefined8 in_stack_00000008;
  undefined8 in_stack_00000018;
  undefined8 in_stack_00000020;
  undefined8 in_stack_00000038;
  
  operator_delete(unaff_R15,0x30);
  QRegularExpression::~QRegularExpression(unaff_R14);
  FUN_005249f0();
  FUN_005249f0(in_stack_00000008);
  FUN_005249f0(in_stack_00000038);
  FUN_005249f0(in_stack_00000020);
  FUN_005249f0(in_stack_00000018);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c7a21 name=FUN_004c7a21 size=13 ====

void FUN_004c7a21(void)

{
  QVariant *unaff_R14;
  undefined8 in_stack_00000018;
  undefined8 in_stack_00000020;
  
  QVariant::~QVariant(unaff_R14);
  FUN_005249f0(in_stack_00000020);
  FUN_005249f0(in_stack_00000018);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c7a2e name=FUN_004c7a2e size=52 ====

void FUN_004c7a2e(void)

{
  int *piVar1;
  QVariant *unaff_RBP;
  undefined8 *unaff_R14;
  
  QVariant::~QVariant(unaff_RBP);
  piVar1 = (int *)*unaff_R14;
  if (*piVar1 != 0) {
    if (*piVar1 == -1) goto LAB_004c7a47;
    LOCK();
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if (*piVar1 != 0) goto LAB_004c7a47;
  }
  FUN_00566e90(*unaff_R14);
LAB_004c7a47:
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c7a62 name=FUN_004c7a62 size=16 ====

void FUN_004c7a62(void)

{
  FUN_00528c1c();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c7a72 name=FUN_004c7a72 size=21 ====

void FUN_004c7a72(void)

{
  void *unaff_RBP;
  
  operator_delete(unaff_RBP,0x78);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c7a87 name=FUN_004c7a87 size=16 ====

void FUN_004c7a87(void)

{
  FUN_00528c1c();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c7a97 name=FUN_004c7a97 size=16 ====

void FUN_004c7a97(void)

{
  QVariant *unaff_R13;
  
  QVariant::~QVariant(unaff_R13);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c7aa8 name=FUN_004c7aa8 size=16 ====

void FUN_004c7aa8(void)

{
  FUN_00528c1c();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c7ac0 name=FUN_004c7ac0 size=41 ====

void FUN_004c7ac0(void)

{
  long unaff_RBP;
  long in_stack_00000050;
  undefined8 in_stack_00000058;
  
  FUN_005249f0(unaff_RBP + 8);
  FUN_005249f0(in_stack_00000050 + 8);
  FUN_005249f0(in_stack_00000058);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c7ae9 name=FUN_004c7ae9 size=25 ====

void FUN_004c7ae9(void)

{
  long unaff_RBP;
  long in_stack_00000050;
  undefined8 in_stack_00000058;
  
  FUN_005249f0(in_stack_00000050 + 8);
  FUN_005249f0(unaff_RBP + 8);
  FUN_005249f0(in_stack_00000058);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c7b02 name=FUN_004c7b02 size=21 ====

void FUN_004c7b02(void)

{
  void *unaff_R13;
  
  operator_delete(unaff_R13,0x30);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c7b17 name=FUN_004c7b17 size=16 ====

void FUN_004c7b17(void)

{
  FUN_005249f0();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c7b27 name=FUN_004c7b27 size=46 ====

void FUN_004c7b27(void)

{
  undefined8 in_stack_00000030;
  QIcon *in_stack_00000038;
  undefined8 in_stack_00000050;
  
  QIcon::~QIcon(in_stack_00000038);
  FUN_005249f0(in_stack_00000030);
  FUN_005249f0(in_stack_00000050);
  FUN_005249f0();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c7b55 name=FUN_004c7b55 size=16 ====

void FUN_004c7b55(void)

{
  QVariant *unaff_RBP;
  
  QVariant::~QVariant(unaff_RBP);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c7b65 name=FUN_004c7b65 size=24 ====

void FUN_004c7b65(void)

{
  FUN_00af2c10();
  FUN_00af2c10();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c7b7d name=FUN_004c7b7d size=37 ====

void FUN_004c7b7d(void)

{
  FUN_00af2c10();
  FUN_00af2c10();
  FUN_005249f0(&stack0x00000020);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c7ba2 name=FUN_004c7ba2 size=34 ====

void FUN_004c7ba2(void)

{
  FUN_00af2c10();
  FUN_00af2c10();
  FUN_005249f0(&stack0x00000060);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c7bc4 name=FUN_004c7bc4 size=24 ====

void FUN_004c7bc4(void)

{
  FUN_00af2c10();
  FUN_00af2c10();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c7bdc name=FUN_004c7bdc size=34 ====

void FUN_004c7bdc(void)

{
  FUN_00af2c10();
  FUN_00af2c10();
  FUN_005249f0(&stack0x00000060);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c7bfe name=FUN_004c7bfe size=24 ====

void FUN_004c7bfe(void)

{
  FUN_00af2c10();
  FUN_00af2c10();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c7c16 name=FUN_004c7c16 size=24 ====

void FUN_004c7c16(void)

{
  FUN_00af2c10();
  FUN_00af2c10();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c7c2e name=FUN_004c7c2e size=34 ====

void FUN_004c7c2e(void)

{
  FUN_00af2c10();
  FUN_00af2c10();
  FUN_005249f0(&stack0x00000020);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c7c50 name=FUN_004c7c50 size=37 ====

void FUN_004c7c50(void)

{
  undefined8 in_stack_00000018;
  
  FUN_00af2c10();
  FUN_00af2c10();
  FUN_005249f0(in_stack_00000018);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c7c75 name=FUN_004c7c75 size=24 ====

void FUN_004c7c75(void)

{
  FUN_00af2c10();
  FUN_00af2c10();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c7c8d name=FUN_004c7c8d size=37 ====

void FUN_004c7c8d(void)

{
  undefined8 in_stack_00000018;
  
  FUN_00af2c10();
  FUN_00af2c10();
  FUN_005249f0(in_stack_00000018);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c7cb2 name=FUN_004c7cb2 size=37 ====

void FUN_004c7cb2(void)

{
  undefined8 in_stack_00000018;
  
  FUN_00af2c10();
  FUN_00af2c10();
  FUN_005249f0(in_stack_00000018);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c7cd7 name=FUN_004c7cd7 size=24 ====

void FUN_004c7cd7(void)

{
  FUN_00af2c10();
  FUN_00af2c10();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c7cef name=FUN_004c7cef size=24 ====

void FUN_004c7cef(void)

{
  FUN_00af2c10();
  FUN_00af2c10();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c7d07 name=FUN_004c7d07 size=24 ====

void FUN_004c7d07(void)

{
  FUN_00af2c10();
  FUN_00af2c10();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c7d1f name=FUN_004c7d1f size=37 ====

void FUN_004c7d1f(void)

{
  undefined8 in_stack_00000018;
  
  FUN_00af2c10();
  FUN_00af2c10();
  FUN_005249f0(in_stack_00000018);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c7d44 name=FUN_004c7d44 size=37 ====

void FUN_004c7d44(void)

{
  FUN_00af2c10();
  FUN_00af2c10();
  FUN_005249f0(&stack0x00000050);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c7d69 name=FUN_004c7d69 size=37 ====

void FUN_004c7d69(void)

{
  undefined8 in_stack_00000018;
  
  FUN_00af2c10();
  FUN_00af2c10();
  FUN_005249f0(in_stack_00000018);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c7d8e name=FUN_004c7d8e size=24 ====

void FUN_004c7d8e(void)

{
  FUN_00af2c10();
  FUN_00af2c10();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c7da6 name=FUN_004c7da6 size=37 ====

void FUN_004c7da6(void)

{
  undefined8 in_stack_00000018;
  
  FUN_00af2c10();
  FUN_00af2c10();
  FUN_005249f0(in_stack_00000018);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c7dcb name=FUN_004c7dcb size=24 ====

void FUN_004c7dcb(void)

{
  FUN_00af2c10();
  FUN_00af2c10();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c7de3 name=FUN_004c7de3 size=24 ====

void FUN_004c7de3(void)

{
  FUN_00af2c10();
  FUN_00af2c10();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c7dfc name=FUN_004c7dfc size=118 ====

void FUN_004c7dfc(void)

{
  QFontMetrics *unaff_RBX;
  undefined8 in_stack_00000028;
  
  QFontMetrics::~QFontMetrics(unaff_RBX);
  FUN_005249f0(&stack0x00000088);
  FUN_005249f0(&stack0x00000080);
  FUN_005249f0(&stack0x00000078);
  FUN_005249f0(&stack0x00000070);
  FUN_005249f0(in_stack_00000028);
  FUN_005249f0(&stack0x00000060);
  FUN_005249f0(&stack0x00000058);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c7e72 name=FUN_004c7e72 size=24 ====

void FUN_004c7e72(void)

{
  FUN_00af2c10();
  FUN_00af2c10();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c7e8a name=FUN_004c7e8a size=21 ====

void FUN_004c7e8a(void)

{
  FUN_00af2c10();
  FUN_00af2c10();
  FUN_005249f0(&stack0x00000058);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c7e9f name=FUN_004c7e9f size=44 ====

void FUN_004c7e9f(void)

{
  FUN_00af2c10();
  FUN_00af2c10();
  FUN_005249f0(&stack0x00000070);
  FUN_005249f0(&stack0x00000068);
  FUN_005249f0(&stack0x00000060);
  FUN_005249f0(&stack0x00000058);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c7ecb name=FUN_004c7ecb size=44 ====

void FUN_004c7ecb(void)

{
  FUN_00af2c10();
  FUN_00af2c10();
  FUN_005249f0(&stack0x00000078);
  FUN_005249f0(&stack0x00000070);
  FUN_005249f0(&stack0x00000068);
  FUN_005249f0(&stack0x00000060);
  FUN_005249f0(&stack0x00000058);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c7ef7 name=FUN_004c7ef7 size=24 ====

void FUN_004c7ef7(void)

{
  FUN_00af2c10();
  FUN_00af2c10();
  FUN_005249f0(&stack0x00000060);
  FUN_005249f0(&stack0x00000058);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c7f0f name=FUN_004c7f0f size=34 ====

void FUN_004c7f0f(void)

{
  FUN_00af2c10();
  FUN_00af2c10();
  FUN_005249f0(&stack0x00000068);
  FUN_005249f0(&stack0x00000060);
  FUN_005249f0(&stack0x00000058);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c7f31 name=FUN_004c7f31 size=34 ====

void FUN_004c7f31(void)

{
  undefined8 in_stack_00000020;
  undefined8 in_stack_00000028;
  undefined8 in_stack_00000048;
  
  FUN_005249f0();
  FUN_005249f0(&stack0x000000b8);
  FUN_005249f0();
  FUN_005249f0();
  FUN_005249f0(in_stack_00000020);
  FUN_005249f0(&stack0x00000078);
  FUN_005249f0(in_stack_00000048);
  FUN_005249f0(in_stack_00000028);
  FUN_005249f0(&stack0x00000060);
  FUN_005249f0(&stack0x00000058);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c7f53 name=FUN_004c7f53 size=57 ====

void FUN_004c7f53(void)

{
  undefined8 in_stack_00000020;
  undefined8 in_stack_00000028;
  undefined8 in_stack_00000038;
  undefined8 in_stack_00000040;
  undefined8 in_stack_00000048;
  
  FUN_005249f0();
  FUN_005249f0(&stack0x000000b0);
  FUN_005249f0(in_stack_00000040);
  FUN_005249f0();
  FUN_005249c0(in_stack_00000038);
  FUN_005249f0();
  FUN_005249f0(in_stack_00000020);
  FUN_005249f0(&stack0x00000078);
  FUN_005249f0(in_stack_00000048);
  FUN_005249f0(in_stack_00000028);
  FUN_005249f0(&stack0x00000060);
  FUN_005249f0(&stack0x00000058);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c7f8c name=FUN_004c7f8c size=50 ====

void FUN_004c7f8c(void)

{
  undefined8 in_stack_00000028;
  undefined8 in_stack_00000048;
  
  FUN_005249f0();
  FUN_005249f0(&stack0x000000a0);
  FUN_005249f0();
  FUN_005249f0();
  FUN_005249f0(&stack0x00000080);
  FUN_005249f0(&stack0x00000078);
  FUN_005249f0(in_stack_00000048);
  FUN_005249f0(in_stack_00000028);
  FUN_005249f0(&stack0x00000060);
  FUN_005249f0(&stack0x00000058);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c7fbe name=FUN_004c7fbe size=58 ====

void FUN_004c7fbe(void)

{
  QIcon *unaff_RBX;
  void *unaff_R13;
  undefined8 in_stack_00000028;
  undefined8 in_stack_00000048;
  
  operator_delete(unaff_R13,0x10);
  QIcon::~QIcon(unaff_RBX);
  FUN_005249f0();
  FUN_005249f0(&stack0x00000088);
  FUN_005249f0(&stack0x00000080);
  FUN_005249f0(&stack0x00000078);
  FUN_005249f0(in_stack_00000048);
  FUN_005249f0(in_stack_00000028);
  FUN_005249f0(&stack0x00000060);
  FUN_005249f0(&stack0x00000058);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c7ff8 name=FUN_004c7ff8 size=50 ====

void FUN_004c7ff8(void)

{
  undefined8 in_stack_00000028;
  undefined8 in_stack_00000048;
  
  FUN_005249f0();
  FUN_005249f0(&stack0x000000a8);
  FUN_005249f0();
  FUN_005249f0();
  FUN_005249f0(&stack0x00000080);
  FUN_005249f0(&stack0x00000078);
  FUN_005249f0(in_stack_00000048);
  FUN_005249f0(in_stack_00000028);
  FUN_005249f0(&stack0x00000060);
  FUN_005249f0(&stack0x00000058);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c802a name=FUN_004c802a size=16 ====

void FUN_004c802a(void)

{
  QVariant *unaff_RBX;
  undefined8 in_stack_00000020;
  undefined8 in_stack_00000028;
  undefined8 in_stack_00000048;
  
  QVariant::~QVariant(unaff_RBX);
  FUN_005249f0();
  FUN_005249f0(in_stack_00000020);
  FUN_005249f0(&stack0x00000078);
  FUN_005249f0(in_stack_00000048);
  FUN_005249f0(in_stack_00000028);
  FUN_005249f0(&stack0x00000060);
  FUN_005249f0(&stack0x00000058);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c803a name=FUN_004c803a size=13 ====

void FUN_004c803a(void)

{
  undefined8 in_stack_00000020;
  undefined8 in_stack_00000028;
  undefined8 in_stack_00000048;
  
  FUN_005249f0();
  FUN_005249f0();
  FUN_005249f0(in_stack_00000020);
  FUN_005249f0(&stack0x00000078);
  FUN_005249f0(in_stack_00000048);
  FUN_005249f0(in_stack_00000028);
  FUN_005249f0(&stack0x00000060);
  FUN_005249f0(&stack0x00000058);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c8047 name=FUN_004c8047 size=14 ====

void FUN_004c8047(void)

{
  undefined8 in_stack_00000020;
  undefined8 in_stack_00000028;
  undefined8 in_stack_00000048;
  
  FUN_005249f0();
  FUN_005249f0();
  FUN_005249f0(in_stack_00000020);
  FUN_005249f0(&stack0x00000078);
  FUN_005249f0(in_stack_00000048);
  FUN_005249f0(in_stack_00000028);
  FUN_005249f0(&stack0x00000060);
  FUN_005249f0(&stack0x00000058);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c8056 name=FUN_004c8056 size=21 ====

void FUN_004c8056(void)

{
  void *unaff_R12;
  
  operator_delete(unaff_R12,0x30);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c806b name=FUN_004c806b size=42 ====

void FUN_004c806b(void)

{
  QIcon *unaff_R12;
  undefined8 in_stack_00000008;
  
  QIcon::~QIcon(unaff_R12);
  FUN_005249f0();
  FUN_005249f0(in_stack_00000008);
  FUN_005249f0();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c8095 name=FUN_004c8095 size=29 ====

void FUN_004c8095(void)

{
  void *unaff_R13;
  
  operator_delete(unaff_R13,0x30);
  FUN_005249f0();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c80b2 name=FUN_004c80b2 size=10 ====

void FUN_004c80b2(void)

{
  FUN_005249f0();
  FUN_005249f0();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c80bc name=FUN_004c80bc size=15 ====

void FUN_004c80bc(void)

{
  void *unaff_R13;
  
  operator_delete(unaff_R13,0x30);
  FUN_005249f0();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c80cb name=FUN_004c80cb size=29 ====

void FUN_004c80cb(void)

{
  void *unaff_R13;
  
  operator_delete(unaff_R13,0x30);
  FUN_005249f0();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c80e8 name=FUN_004c80e8 size=21 ====

void FUN_004c80e8(void)

{
  void *unaff_RBP;
  
  operator_delete(unaff_RBP,0x20);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c80fd name=FUN_004c80fd size=10 ====

void FUN_004c80fd(void)

{
  FUN_005249f0();
  FUN_005249f0();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c8107 name=FUN_004c8107 size=28 ====

void FUN_004c8107(void)

{
  QIcon *unaff_R12;
  undefined8 in_stack_00000008;
  
  QIcon::~QIcon(unaff_R12);
  FUN_005249f0();
  FUN_005249f0(in_stack_00000008);
  FUN_005249f0();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c8123 name=FUN_004c8123 size=31 ====

void FUN_004c8123(void)

{
  QIcon *unaff_R12;
  undefined8 in_stack_00000008;
  
  QIcon::~QIcon(unaff_R12);
  FUN_005249f0();
  FUN_005249f0(in_stack_00000008);
  FUN_005249f0();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c8142 name=FUN_004c8142 size=13 ====

void FUN_004c8142(void)

{
  FUN_005249f0();
  FUN_005249f0();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c814f name=FUN_004c814f size=16 ====

void FUN_004c814f(void)

{
  FUN_005249f0();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c815f name=FUN_004c815f size=21 ====

void FUN_004c815f(void)

{
  void *unaff_R12;
  
  operator_delete(unaff_R12,0x20);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c8174 name=FUN_004c8174 size=59 ====

void FUN_004c8174(void)

{
  undefined8 unaff_retaddr;
  undefined8 in_stack_00000008;
  
  FUN_005249f0();
  FUN_005249f0(&stack0x00000038);
  FUN_005249f0();
  FUN_005249f0(in_stack_00000008);
  FUN_005249f0(unaff_retaddr);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c81af name=FUN_004c81af size=21 ====

void FUN_004c81af(void)

{
  undefined8 unaff_retaddr;
  undefined8 in_stack_00000008;
  
  FUN_00af2c10();
  FUN_00af2c10();
  FUN_005249f0();
  FUN_005249f0(in_stack_00000008);
  FUN_005249f0(unaff_retaddr);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c81c4 name=FUN_004c81c4 size=18 ====

void FUN_004c81c4(void)

{
  undefined8 unaff_retaddr;
  
  FUN_00af2c10();
  FUN_00af2c10();
  FUN_005249f0(unaff_retaddr);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c81d6 name=FUN_004c81d6 size=16 ====

void FUN_004c81d6(void)

{
  QVariant *unaff_RBP;
  
  QVariant::~QVariant(unaff_RBP);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c81e6 name=FUN_004c81e6 size=18 ====

void FUN_004c81e6(void)

{
  undefined8 unaff_retaddr;
  undefined8 in_stack_00000008;
  
  FUN_00af2c10();
  FUN_00af2c10();
  FUN_005249f0(in_stack_00000008);
  FUN_005249f0(unaff_retaddr);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c81f8 name=FUN_004c81f8 size=35 ====

void FUN_004c81f8(void)

{
  QVariant *unaff_RBX;
  QVariant *unaff_RBP;
  
  QVariant::~QVariant(unaff_RBP);
  FUN_005249c0();
  QVariant::~QVariant(unaff_RBX);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c821c name=FUN_004c821c size=35 ====

void FUN_004c821c(void)

{
  QVariant *unaff_RBX;
  QVariant *unaff_RBP;
  
  QVariant::~QVariant(unaff_RBP);
  FUN_005249c0();
  QVariant::~QVariant(unaff_RBX);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c8240 name=FUN_004c8240 size=35 ====

void FUN_004c8240(void)

{
  QVariant *unaff_RBX;
  QVariant *unaff_RBP;
  
  QVariant::~QVariant(unaff_RBP);
  FUN_005249c0();
  QVariant::~QVariant(unaff_RBX);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c8264 name=FUN_004c8264 size=16 ====

void FUN_004c8264(void)

{
  QEasingCurve *unaff_RBX;
  
  QEasingCurve::~QEasingCurve(unaff_RBX);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c8274 name=FUN_004c8274 size=29 ====

void FUN_004c8274(void)

{
  void *unaff_RBP;
  
  operator_delete(unaff_RBP,0x10);
  FUN_005249c0();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c8291 name=FUN_004c8291 size=16 ====

void FUN_004c8291(void)

{
  QVariant *unaff_RBX;
  
  QVariant::~QVariant(unaff_RBX);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c82a1 name=FUN_004c82a1 size=16 ====

void FUN_004c82a1(void)

{
  QVariant *unaff_RBX;
  
  QVariant::~QVariant(unaff_RBX);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c82b2 name=FUN_004c82b2 size=44 ====

void FUN_004c82b2(void)

{
  QWidget *unaff_RBX;
  
  FUN_005249f0();
  FUN_005249f0();
  FUN_00525060(unaff_RBX + 0x68);
  QWidget::~QWidget(unaff_RBX);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c82de name=FUN_004c82de size=10 ====

void FUN_004c82de(void)

{
  QWidget *unaff_RBX;
  
  FUN_005249f0();
  FUN_00525060(unaff_RBX + 0x68);
  QWidget::~QWidget(unaff_RBX);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c82e8 name=FUN_004c82e8 size=13 ====

void FUN_004c82e8(void)

{
  undefined8 in_stack_00000048;
  
  FUN_005249f0();
  FUN_00570d30(in_stack_00000048);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c82f5 name=FUN_004c82f5 size=21 ====

void FUN_004c82f5(void)

{
  void *unaff_R12;
  
  operator_delete(unaff_R12,0x30);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c830a name=FUN_004c830a size=37 ====

void FUN_004c830a(void)

{
  undefined8 in_stack_00000048;
  
  FUN_00af2c10();
  FUN_00af2c10();
  FUN_00570d30(in_stack_00000048);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c832f name=FUN_004c832f size=12 ====

void FUN_004c832f(void)

{
  undefined8 in_stack_00000040;
  undefined8 in_stack_00000048;
  
  FUN_005249f0(in_stack_00000040);
  FUN_00570d30(in_stack_00000048);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c833b name=FUN_004c833b size=21 ====

void FUN_004c833b(void)

{
  void *unaff_RBP;
  
  operator_delete(unaff_RBP,0x30);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c8350 name=FUN_004c8350 size=90 ====

void FUN_004c8350(void)

{
  long unaff_RBP;
  long in_stack_00000010;
  undefined8 in_stack_00000038;
  undefined8 in_stack_00000040;
  undefined8 in_stack_00000048;
  
  FUN_005249c0(unaff_RBP + 0x10);
  FUN_00570ce0(in_stack_00000010 + 0x50);
  FUN_00570ce0(in_stack_00000010 + 0x28);
  FUN_00570ce0(in_stack_00000010);
  FUN_005249c0(in_stack_00000048);
  FUN_005249c0(in_stack_00000040);
  FUN_005249c0(in_stack_00000038);
  __cxa_guard_abort(&DAT_011c0b80);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c83aa name=FUN_004c83aa size=21 ====

void FUN_004c83aa(void)

{
  void *unaff_RBX;
  
  operator_delete(unaff_RBX,0xc0);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c83bf name=FUN_004c83bf size=16 ====

void FUN_004c83bf(void)

{
  FUN_005249f0();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c83cf name=FUN_004c83cf size=16 ====

void FUN_004c83cf(void)

{
  FUN_005249f0();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c83e0 name=FUN_004c83e0 size=26 ====

void FUN_004c83e0(void)

{
  undefined8 in_stack_00000018;
  
  FUN_005249f0();
  FUN_005446f0(in_stack_00000018);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c83fa name=FUN_004c83fa size=18 ====

void FUN_004c83fa(void)

{
  QVariant *unaff_RBP;
  undefined8 in_stack_00000018;
  
  FUN_005249f0();
  QVariant::~QVariant(unaff_RBP);
  FUN_005446f0(in_stack_00000018);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c840c name=FUN_004c840c size=35 ====

void FUN_004c840c(void)

{
  FUN_00570d50();
  FUN_005249f0();
  FUN_005249f0();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c842f name=FUN_004c842f size=10 ====

void FUN_004c842f(void)

{
  FUN_00570d50();
  FUN_005249f0();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c843a name=FUN_004c843a size=13 ====

void FUN_004c843a(void)

{
  QVariant *unaff_RBX;
  undefined8 in_stack_00000028;
  undefined8 in_stack_00000030;
  undefined8 in_stack_000000f0;
  
  QVariant::~QVariant(unaff_RBX);
  FUN_00570d30(in_stack_00000028);
  FUN_00570eb4(in_stack_00000030,in_stack_000000f0);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c8447 name=FUN_004c8447 size=49 ====

void FUN_004c8447(void)

{
  void *unaff_RBP;
  undefined8 in_stack_00000028;
  undefined8 in_stack_00000030;
  undefined8 in_stack_000000f0;
  
  operator_delete(unaff_RBP,0x10);
  FUN_00570d30(in_stack_00000028);
  FUN_00570eb4(in_stack_00000030,in_stack_000000f0);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c8478 name=FUN_004c8478 size=65 ====

void FUN_004c8478(void)

{
  QIcon *unaff_RBX;
  void *unaff_RBP;
  undefined8 in_stack_00000030;
  undefined8 in_stack_00000048;
  undefined8 in_stack_000000f0;
  
  operator_delete(unaff_RBP,0x10);
  FUN_005249f0(in_stack_00000048);
  QIcon::~QIcon(unaff_RBX);
  FUN_005249f0();
  FUN_005249f0();
  FUN_00570d30(&stack0x00000068);
  FUN_00570eb4(in_stack_00000030,in_stack_000000f0);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c84b9 name=FUN_004c84b9 size=68 ====

void FUN_004c84b9(void)

{
  QWidgetAction *unaff_RBP;
  void *unaff_R12;
  undefined8 in_stack_00000028;
  undefined8 in_stack_00000030;
  undefined8 in_stack_000000f0;
  
  operator_delete(unaff_R12,0x30);
  *(undefined ***)unaff_RBP = &PTR_metaObject_01184688;
  QWidgetAction::~QWidgetAction(unaff_RBP);
  operator_delete(unaff_RBP,0x28);
  FUN_005249f0();
  FUN_00570d30(in_stack_00000028);
  FUN_00570eb4(in_stack_00000030,in_stack_000000f0);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c84fd name=FUN_004c84fd size=72 ====

void FUN_004c84fd(void)

{
  code *pcVar1;
  undefined8 in_stack_00000020;
  _func_void_Node_ptr *in_stack_00000078;
  
  FUN_00af2c10();
  FUN_00af2c10(in_stack_00000020);
  pcVar1 = in_stack_00000078 + 0x10;
  if (*(int *)(in_stack_00000078 + 0x10) != 0) {
    if (*(int *)(in_stack_00000078 + 0x10) == -1) goto LAB_004c852b;
    LOCK();
    *(int *)pcVar1 = *(int *)pcVar1 + -1;
    UNLOCK();
    if (*(int *)pcVar1 != 0) goto LAB_004c852b;
  }
  QHashData::free_helper(in_stack_00000078);
LAB_004c852b:
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c8533 name=FUN_004c8533 size=18 ====

void FUN_004c8533(void)

{
  undefined8 in_stack_00000030;
  
  FUN_00570d50(in_stack_00000030);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c8557 name=FUN_004c8557 size=12 ====

void FUN_004c8557(void)

{
  code *pcVar1;
  undefined8 in_stack_00000028;
  _func_void_Node_ptr *in_stack_00000078;
  
  FUN_005249f0(in_stack_00000028);
  pcVar1 = in_stack_00000078 + 0x10;
  if (*(int *)(in_stack_00000078 + 0x10) != 0) {
    if (*(int *)(in_stack_00000078 + 0x10) == -1) goto LAB_004c852b;
    LOCK();
    *(int *)pcVar1 = *(int *)pcVar1 + -1;
    UNLOCK();
    if (*(int *)pcVar1 != 0) goto LAB_004c852b;
  }
  QHashData::free_helper(in_stack_00000078);
LAB_004c852b:
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c8563 name=FUN_004c8563 size=26 ====

void FUN_004c8563(void)

{
  undefined8 in_stack_00000030;
  
  FUN_00570d50(in_stack_00000030);
  FUN_005249f0();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c857d name=FUN_004c857d size=24 ====

void FUN_004c857d(void)

{
  FUN_00525060();
  FUN_005249f0();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c8595 name=FUN_004c8595 size=68 ====

void FUN_004c8595(void)

{
  QWidgetAction *unaff_RBP;
  void *unaff_R12;
  undefined8 in_stack_00000028;
  undefined8 in_stack_00000030;
  undefined8 in_stack_000000f0;
  
  operator_delete(unaff_R12,0x30);
  *(undefined ***)unaff_RBP = &PTR_metaObject_01184688;
  QWidgetAction::~QWidgetAction(unaff_RBP);
  operator_delete(unaff_RBP,0x28);
  FUN_005249f0();
  FUN_00570d30(in_stack_00000028);
  FUN_00570eb4(in_stack_00000030,in_stack_000000f0);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c85d9 name=FUN_004c85d9 size=24 ====

void FUN_004c85d9(void)

{
  undefined8 in_stack_00000028;
  undefined8 in_stack_00000030;
  undefined8 in_stack_000000f0;
  
  FUN_00af2c10();
  FUN_00af2c10();
  FUN_00570d30(in_stack_00000028);
  FUN_00570eb4(in_stack_00000030,in_stack_000000f0);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c85f1 name=FUN_004c85f1 size=13 ====

void FUN_004c85f1(void)

{
  undefined8 in_stack_00000028;
  undefined8 in_stack_00000030;
  undefined8 in_stack_000000f0;
  
  FUN_005249f0();
  FUN_00570d30(in_stack_00000028);
  FUN_00570eb4(in_stack_00000030,in_stack_000000f0);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c85fe name=FUN_004c85fe size=16 ====

void FUN_004c85fe(void)

{
  FUN_005249f0();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c860e name=FUN_004c860e size=24 ====

void FUN_004c860e(void)

{
  FUN_00af2c10();
  FUN_00af2c10();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c8630 name=FUN_004c8630 size=21 ====

void FUN_004c8630(void)

{
  void *unaff_R12;
  
  operator_delete(unaff_R12,0x20);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c8645 name=FUN_004c8645 size=21 ====

void FUN_004c8645(void)

{
  void *unaff_RBP;
  
  operator_delete(unaff_RBP,0x20);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c865a name=FUN_004c865a size=29 ====

void FUN_004c865a(void)

{
  void *unaff_R13;
  
  operator_delete(unaff_R13,0x48);
  FUN_005249f0();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c8677 name=FUN_004c8677 size=32 ====

void FUN_004c8677(void)

{
  void *unaff_R13;
  
  operator_delete(unaff_R13,0x48);
  FUN_005249f0(&stack0x00000000);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c8697 name=FUN_004c8697 size=21 ====

void FUN_004c8697(void)

{
  void *unaff_R13;
  
  operator_delete(unaff_R13,0x30);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c86ac name=FUN_004c86ac size=21 ====

void FUN_004c86ac(void)

{
  void *unaff_RBP;
  
  operator_delete(unaff_RBP,0x20);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c86c1 name=FUN_004c86c1 size=21 ====

void FUN_004c86c1(void)

{
  void *unaff_R13;
  
  operator_delete(unaff_R13,0x30);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c86d6 name=FUN_004c86d6 size=16 ====

void FUN_004c86d6(void)

{
  FUN_005249f0();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c86e6 name=FUN_004c86e6 size=29 ====

void FUN_004c86e6(void)

{
  void *unaff_R13;
  
  operator_delete(unaff_R13,0x48);
  FUN_005249f0();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c8704 name=FUN_004c8704 size=40 ====

void FUN_004c8704(void)

{
  QStyledItemDelegate *unaff_RBX;
  QIcon *unaff_R12;
  
  FUN_005249f0();
  FUN_005249f0();
  QIcon::~QIcon(unaff_R12);
  QStyledItemDelegate::~QStyledItemDelegate(unaff_RBX);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c872c name=FUN_004c872c size=202 ====

void FUN_004c872c(void)

{
  QVariant *unaff_RBP;
  QVariant *unaff_R15;
  undefined8 in_stack_00000008;
  undefined8 in_stack_00000020;
  undefined8 in_stack_00000048;
  undefined8 in_stack_00000058;
  undefined8 in_stack_00000060;
  undefined8 in_stack_00000068;
  undefined8 in_stack_00000070;
  undefined8 in_stack_00000080;
  undefined8 in_stack_00000088;
  undefined8 in_stack_00000090;
  undefined8 in_stack_00000098;
  
  QVariant::~QVariant(unaff_RBP);
  FUN_005249f0(in_stack_00000008);
  QVariant::~QVariant(unaff_R15);
  FUN_005249f0(in_stack_00000088);
  FUN_005249f0(in_stack_00000068);
  FUN_005249f0(&stack0x000000f0);
  FUN_005249f0(in_stack_00000060);
  FUN_005249f0(in_stack_00000098);
  FUN_005249f0(in_stack_00000058);
  FUN_005249f0(in_stack_00000070);
  FUN_005249f0(in_stack_00000048);
  FUN_005249f0(in_stack_00000080);
  FUN_005249f0(in_stack_00000020);
  FUN_00528c1c(in_stack_00000090);
  QIcon::~QIcon((QIcon *)&stack0x000000a8);
  FUN_005249f0(&stack0x000000a0);
  FUN_00558a5a();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c87f6 name=FUN_004c87f6 size=78 ====

void FUN_004c87f6(void)

{
  undefined8 in_stack_00000008;
  undefined8 in_stack_00000020;
  undefined8 in_stack_00000028;
  undefined8 in_stack_00000048;
  undefined8 in_stack_00000050;
  undefined8 in_stack_00000058;
  undefined8 in_stack_00000060;
  undefined8 in_stack_00000068;
  undefined8 in_stack_00000070;
  undefined8 in_stack_00000080;
  undefined8 in_stack_00000088;
  undefined8 in_stack_00000090;
  undefined8 in_stack_00000098;
  
  FUN_005249f0();
  FUN_005249f0();
  FUN_005249f0(in_stack_00000008);
  FUN_005249f0(in_stack_00000028);
  FUN_005249f0();
  FUN_005249f0(in_stack_00000050);
  FUN_005249f0(in_stack_00000088);
  FUN_005249f0(in_stack_00000068);
  FUN_005249f0(&stack0x000000f0);
  FUN_005249f0(in_stack_00000060);
  FUN_005249f0(in_stack_00000098);
  FUN_005249f0(in_stack_00000058);
  FUN_005249f0(in_stack_00000070);
  FUN_005249f0(in_stack_00000048);
  FUN_005249f0(in_stack_00000080);
  FUN_005249f0(in_stack_00000020);
  FUN_00528c1c(in_stack_00000090);
  QIcon::~QIcon((QIcon *)&stack0x000000a8);
  FUN_005249f0(&stack0x000000a0);
  FUN_00558a5a();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c8844 name=FUN_004c8844 size=42 ====

void FUN_004c8844(void)

{
  QVariant *unaff_RBP;
  QVariant *unaff_R15;
  undefined8 in_stack_00000008;
  undefined8 in_stack_00000020;
  undefined8 in_stack_00000080;
  undefined8 in_stack_00000090;
  
  QVariant::~QVariant(unaff_RBP);
  FUN_005249f0(in_stack_00000008);
  QVariant::~QVariant(unaff_R15);
  FUN_005249f0(in_stack_00000080);
  FUN_005249f0(in_stack_00000020);
  FUN_00528c1c(in_stack_00000090);
  QIcon::~QIcon((QIcon *)&stack0x000000a8);
  FUN_005249f0(&stack0x000000a0);
  FUN_00558a5a();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c886e name=FUN_004c886e size=42 ====

void FUN_004c886e(void)

{
  QVariant *unaff_RBP;
  QVariant *unaff_R15;
  undefined8 in_stack_00000008;
  undefined8 in_stack_00000020;
  undefined8 in_stack_00000090;
  
  QVariant::~QVariant(unaff_RBP);
  FUN_005249f0(in_stack_00000008);
  QVariant::~QVariant(unaff_R15);
  FUN_005249f0(in_stack_00000020);
  FUN_00528c1c(in_stack_00000090);
  QIcon::~QIcon((QIcon *)&stack0x000000a8);
  FUN_005249f0(&stack0x000000a0);
  FUN_00558a5a();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c8898 name=FUN_004c8898 size=55 ====

void FUN_004c8898(void)

{
  QIcon *unaff_R13;
  undefined8 in_stack_00000020;
  undefined8 in_stack_00000038;
  undefined8 in_stack_00000048;
  undefined8 in_stack_00000058;
  undefined8 in_stack_00000060;
  undefined8 in_stack_00000068;
  undefined8 in_stack_00000070;
  undefined8 in_stack_00000080;
  undefined8 in_stack_00000088;
  undefined8 in_stack_00000090;
  undefined8 in_stack_00000098;
  
  FUN_005249f0();
  FUN_005249f0();
  FUN_005249f0(&stack0x00000178);
  FUN_005249f0(in_stack_00000038);
  FUN_005249f0(in_stack_00000088);
  FUN_005249f0(in_stack_00000068);
  FUN_005249f0(&stack0x000000f0);
  FUN_005249f0(in_stack_00000060);
  FUN_005249f0(in_stack_00000098);
  FUN_005249f0(in_stack_00000058);
  FUN_005249f0(in_stack_00000070);
  FUN_005249f0(in_stack_00000048);
  FUN_005249f0(in_stack_00000080);
  FUN_005249f0(in_stack_00000020);
  FUN_00528c1c(in_stack_00000090);
  QIcon::~QIcon(unaff_R13);
  FUN_005249f0(&stack0x000000a0);
  FUN_00558a5a();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c88cf name=FUN_004c88cf size=42 ====

void FUN_004c88cf(void)

{
  QVariant *unaff_RBP;
  QVariant *unaff_R15;
  undefined8 in_stack_00000008;
  undefined8 in_stack_00000020;
  undefined8 in_stack_00000048;
  undefined8 in_stack_00000058;
  undefined8 in_stack_00000070;
  undefined8 in_stack_00000080;
  undefined8 in_stack_00000090;
  undefined8 in_stack_00000098;
  
  QVariant::~QVariant(unaff_RBP);
  FUN_005249f0(in_stack_00000008);
  QVariant::~QVariant(unaff_R15);
  FUN_005249f0(in_stack_00000098);
  FUN_005249f0(in_stack_00000058);
  FUN_005249f0(in_stack_00000070);
  FUN_005249f0(in_stack_00000048);
  FUN_005249f0(in_stack_00000080);
  FUN_005249f0(in_stack_00000020);
  FUN_00528c1c(in_stack_00000090);
  QIcon::~QIcon((QIcon *)&stack0x000000a8);
  FUN_005249f0(&stack0x000000a0);
  FUN_00558a5a();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c88f9 name=FUN_004c88f9 size=32 ====

void FUN_004c88f9(void)

{
  QVariant *unaff_RBP;
  undefined8 in_stack_00000020;
  undefined8 in_stack_00000048;
  undefined8 in_stack_00000058;
  undefined8 in_stack_00000060;
  undefined8 in_stack_00000070;
  undefined8 in_stack_00000080;
  undefined8 in_stack_00000090;
  undefined8 in_stack_00000098;
  
  QVariant::~QVariant(unaff_RBP);
  FUN_005249f0(&stack0x000000f0);
  FUN_005249f0(in_stack_00000060);
  FUN_005249f0(in_stack_00000098);
  FUN_005249f0(in_stack_00000058);
  FUN_005249f0(in_stack_00000070);
  FUN_005249f0(in_stack_00000048);
  FUN_005249f0(in_stack_00000080);
  FUN_005249f0(in_stack_00000020);
  FUN_00528c1c(in_stack_00000090);
  QIcon::~QIcon((QIcon *)&stack0x000000a8);
  FUN_005249f0(&stack0x000000a0);
  FUN_00558a5a();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c8919 name=FUN_004c8919 size=36 ====

void FUN_004c8919(void)

{
  undefined8 in_stack_00000020;
  char in_stack_00000038;
  undefined8 in_stack_00000048;
  undefined8 in_stack_00000058;
  undefined8 in_stack_00000060;
  undefined8 in_stack_00000068;
  undefined8 in_stack_00000070;
  undefined8 in_stack_00000080;
  undefined8 in_stack_00000088;
  undefined8 in_stack_00000090;
  undefined8 in_stack_00000098;
  
  if (in_stack_00000038 != '\0') {
    FUN_005249f0();
  }
  FUN_005249f0(in_stack_00000088);
  FUN_005249f0(in_stack_00000068);
  FUN_005249f0(&stack0x000000f0);
  FUN_005249f0(in_stack_00000060);
  FUN_005249f0(in_stack_00000098);
  FUN_005249f0(in_stack_00000058);
  FUN_005249f0(in_stack_00000070);
  FUN_005249f0(in_stack_00000048);
  FUN_005249f0(in_stack_00000080);
  FUN_005249f0(in_stack_00000020);
  FUN_00528c1c(in_stack_00000090);
  QIcon::~QIcon((QIcon *)&stack0x000000a8);
  FUN_005249f0(&stack0x000000a0);
  FUN_00558a5a();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c893d name=FUN_004c893d size=24 ====

void FUN_004c893d(void)

{
  QVariant *unaff_RBP;
  
  QVariant::~QVariant(unaff_RBP);
  QIcon::~QIcon((QIcon *)&stack0x000000a8);
  FUN_005249f0(&stack0x000000a0);
  FUN_00558a5a();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c8955 name=FUN_004c8955 size=70 ====

void FUN_004c8955(void)

{
  QStyleOption *unaff_RBX;
  
  QBrush::~QBrush((QBrush *)(unaff_RBX + 0xb8));
  FUN_005249f0(unaff_RBX + 0xa8);
  QIcon::~QIcon((QIcon *)(unaff_RBX + 0xa0));
  QLocale::~QLocale((QLocale *)(unaff_RBX + 0x70));
  QFont::~QFont((QFont *)(unaff_RBX + 0x58));
  QStyleOption::~QStyleOption(unaff_RBX);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c899b name=FUN_004c899b size=42 ====

void FUN_004c899b(void)

{
  QVariant *unaff_RBP;
  QVariant *unaff_R15;
  undefined8 in_stack_00000008;
  undefined8 in_stack_00000020;
  undefined8 in_stack_00000038;
  undefined8 in_stack_00000048;
  undefined8 in_stack_00000058;
  undefined8 in_stack_00000060;
  undefined8 in_stack_00000068;
  undefined8 in_stack_00000070;
  undefined8 in_stack_00000080;
  undefined8 in_stack_00000088;
  undefined8 in_stack_00000090;
  undefined8 in_stack_00000098;
  
  QVariant::~QVariant(unaff_RBP);
  FUN_005249f0(in_stack_00000008);
  QVariant::~QVariant(unaff_R15);
  FUN_005249f0(&stack0x00000178);
  FUN_005249f0(in_stack_00000038);
  FUN_005249f0(in_stack_00000088);
  FUN_005249f0(in_stack_00000068);
  FUN_005249f0(&stack0x000000f0);
  FUN_005249f0(in_stack_00000060);
  FUN_005249f0(in_stack_00000098);
  FUN_005249f0(in_stack_00000058);
  FUN_005249f0(in_stack_00000070);
  FUN_005249f0(in_stack_00000048);
  FUN_005249f0(in_stack_00000080);
  FUN_005249f0(in_stack_00000020);
  FUN_00528c1c(in_stack_00000090);
  QIcon::~QIcon((QIcon *)&stack0x000000a8);
  FUN_005249f0(&stack0x000000a0);
  FUN_00558a5a();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c89c5 name=FUN_004c89c5 size=42 ====

void FUN_004c89c5(void)

{
  QVariant *unaff_RBP;
  QVariant *unaff_R15;
  undefined8 in_stack_00000008;
  undefined8 in_stack_00000020;
  undefined8 in_stack_00000048;
  undefined8 in_stack_00000058;
  undefined8 in_stack_00000070;
  undefined8 in_stack_00000080;
  undefined8 in_stack_00000090;
  
  QVariant::~QVariant(unaff_RBP);
  FUN_005249f0(in_stack_00000008);
  QVariant::~QVariant(unaff_R15);
  FUN_005249f0(in_stack_00000058);
  FUN_005249f0(in_stack_00000070);
  FUN_005249f0(in_stack_00000048);
  FUN_005249f0(in_stack_00000080);
  FUN_005249f0(in_stack_00000020);
  FUN_00528c1c(in_stack_00000090);
  QIcon::~QIcon((QIcon *)&stack0x000000a8);
  FUN_005249f0(&stack0x000000a0);
  FUN_00558a5a();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c89ef name=FUN_004c89ef size=52 ====

void FUN_004c89ef(void)

{
  undefined8 in_stack_00000008;
  undefined8 in_stack_00000020;
  undefined8 in_stack_00000028;
  undefined8 in_stack_00000038;
  undefined8 in_stack_00000048;
  undefined8 in_stack_00000058;
  undefined8 in_stack_00000060;
  undefined8 in_stack_00000068;
  undefined8 in_stack_00000070;
  undefined8 in_stack_00000080;
  undefined8 in_stack_00000088;
  undefined8 in_stack_00000090;
  undefined8 in_stack_00000098;
  
  FUN_005249f0();
  FUN_005249f0();
  FUN_005249f0(in_stack_00000008);
  FUN_005249f0(in_stack_00000028);
  FUN_005249f0(&stack0x00000178);
  FUN_005249f0(in_stack_00000038);
  FUN_005249f0(in_stack_00000088);
  FUN_005249f0(in_stack_00000068);
  FUN_005249f0(&stack0x000000f0);
  FUN_005249f0(in_stack_00000060);
  FUN_005249f0(in_stack_00000098);
  FUN_005249f0(in_stack_00000058);
  FUN_005249f0(in_stack_00000070);
  FUN_005249f0(in_stack_00000048);
  FUN_005249f0(in_stack_00000080);
  FUN_005249f0(in_stack_00000020);
  FUN_00528c1c(in_stack_00000090);
  QIcon::~QIcon((QIcon *)&stack0x000000a8);
  FUN_005249f0(&stack0x000000a0);
  FUN_00558a5a();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c8a23 name=FUN_004c8a23 size=24 ====

void FUN_004c8a23(void)

{
  undefined8 in_stack_00000020;
  undefined8 in_stack_00000038;
  undefined8 in_stack_00000048;
  undefined8 in_stack_00000058;
  undefined8 in_stack_00000060;
  undefined8 in_stack_00000068;
  undefined8 in_stack_00000070;
  undefined8 in_stack_00000080;
  undefined8 in_stack_00000088;
  undefined8 in_stack_00000090;
  undefined8 in_stack_00000098;
  
  FUN_005249f0();
  FUN_005249f0(&stack0x00000178);
  FUN_005249f0(in_stack_00000038);
  FUN_005249f0(in_stack_00000088);
  FUN_005249f0(in_stack_00000068);
  FUN_005249f0(&stack0x000000f0);
  FUN_005249f0(in_stack_00000060);
  FUN_005249f0(in_stack_00000098);
  FUN_005249f0(in_stack_00000058);
  FUN_005249f0(in_stack_00000070);
  FUN_005249f0(in_stack_00000048);
  FUN_005249f0(in_stack_00000080);
  FUN_005249f0(in_stack_00000020);
  FUN_00528c1c(in_stack_00000090);
  QIcon::~QIcon((QIcon *)&stack0x000000a8);
  FUN_005249f0(&stack0x000000a0);
  FUN_00558a5a();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c8a3b name=FUN_004c8a3b size=16 ====

void FUN_004c8a3b(void)

{
  QIcon *unaff_R13;
  undefined8 in_stack_00000020;
  undefined8 in_stack_00000038;
  undefined8 in_stack_00000048;
  undefined8 in_stack_00000058;
  undefined8 in_stack_00000060;
  undefined8 in_stack_00000068;
  undefined8 in_stack_00000070;
  undefined8 in_stack_00000080;
  undefined8 in_stack_00000088;
  undefined8 in_stack_00000090;
  undefined8 in_stack_00000098;
  
  FUN_005249f0();
  FUN_005249f0(&stack0x00000178);
  FUN_005249f0(in_stack_00000038);
  FUN_005249f0(in_stack_00000088);
  FUN_005249f0(in_stack_00000068);
  FUN_005249f0(&stack0x000000f0);
  FUN_005249f0(in_stack_00000060);
  FUN_005249f0(in_stack_00000098);
  FUN_005249f0(in_stack_00000058);
  FUN_005249f0(in_stack_00000070);
  FUN_005249f0(in_stack_00000048);
  FUN_005249f0(in_stack_00000080);
  FUN_005249f0(in_stack_00000020);
  FUN_00528c1c(in_stack_00000090);
  QIcon::~QIcon(unaff_R13);
  FUN_005249f0(&stack0x000000a0);
  FUN_00558a5a();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c8a4b name=FUN_004c8a4b size=13 ====

void FUN_004c8a4b(void)

{
  QIcon *unaff_R13;
  QPixmap *unaff_R15;
  undefined8 in_stack_00000020;
  undefined8 in_stack_00000038;
  undefined8 in_stack_00000048;
  undefined8 in_stack_00000058;
  undefined8 in_stack_00000060;
  undefined8 in_stack_00000068;
  undefined8 in_stack_00000070;
  undefined8 in_stack_00000080;
  undefined8 in_stack_00000088;
  undefined8 in_stack_00000090;
  undefined8 in_stack_00000098;
  
  QPixmap::~QPixmap(unaff_R15);
  FUN_005249f0(&stack0x00000178);
  FUN_005249f0(in_stack_00000038);
  FUN_005249f0(in_stack_00000088);
  FUN_005249f0(in_stack_00000068);
  FUN_005249f0(&stack0x000000f0);
  FUN_005249f0(in_stack_00000060);
  FUN_005249f0(in_stack_00000098);
  FUN_005249f0(in_stack_00000058);
  FUN_005249f0(in_stack_00000070);
  FUN_005249f0(in_stack_00000048);
  FUN_005249f0(in_stack_00000080);
  FUN_005249f0(in_stack_00000020);
  FUN_00528c1c(in_stack_00000090);
  QIcon::~QIcon(unaff_R13);
  FUN_005249f0(&stack0x000000a0);
  FUN_00558a5a();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c8a58 name=FUN_004c8a58 size=16 ====

void FUN_004c8a58(void)

{
  QIcon *unaff_R13;
  undefined8 in_stack_00000020;
  undefined8 in_stack_00000038;
  undefined8 in_stack_00000048;
  undefined8 in_stack_00000058;
  undefined8 in_stack_00000060;
  undefined8 in_stack_00000068;
  undefined8 in_stack_00000070;
  undefined8 in_stack_00000080;
  undefined8 in_stack_00000088;
  undefined8 in_stack_00000090;
  undefined8 in_stack_00000098;
  
  FUN_005249f0();
  FUN_005249f0(&stack0x00000178);
  FUN_005249f0(in_stack_00000038);
  FUN_005249f0(in_stack_00000088);
  FUN_005249f0(in_stack_00000068);
  FUN_005249f0(&stack0x000000f0);
  FUN_005249f0(in_stack_00000060);
  FUN_005249f0(in_stack_00000098);
  FUN_005249f0(in_stack_00000058);
  FUN_005249f0(in_stack_00000070);
  FUN_005249f0(in_stack_00000048);
  FUN_005249f0(in_stack_00000080);
  FUN_005249f0(in_stack_00000020);
  FUN_00528c1c(in_stack_00000090);
  QIcon::~QIcon(unaff_R13);
  FUN_005249f0(&stack0x000000a0);
  FUN_00558a5a();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c8a68 name=FUN_004c8a68 size=50 ====

void FUN_004c8a68(void)

{
  QVariant *unaff_RBP;
  QVariant *unaff_R15;
  undefined8 in_stack_00000008;
  undefined8 in_stack_00000020;
  undefined8 in_stack_00000048;
  undefined8 in_stack_00000058;
  undefined8 in_stack_00000060;
  undefined8 in_stack_00000068;
  undefined8 in_stack_00000070;
  undefined8 in_stack_00000080;
  undefined8 in_stack_00000088;
  undefined8 in_stack_00000090;
  undefined8 in_stack_00000098;
  
  QVariant::~QVariant(unaff_RBP);
  FUN_005249f0(in_stack_00000008);
  QVariant::~QVariant(unaff_R15);
  FUN_005249f0(in_stack_00000088);
  FUN_005249f0(in_stack_00000068);
  FUN_005249f0(&stack0x000000f0);
  FUN_005249f0(in_stack_00000060);
  FUN_005249f0(in_stack_00000098);
  FUN_005249f0(in_stack_00000058);
  FUN_005249f0(in_stack_00000070);
  FUN_005249f0(in_stack_00000048);
  FUN_005249f0(in_stack_00000080);
  FUN_005249f0(in_stack_00000020);
  FUN_00528c1c(in_stack_00000090);
  QIcon::~QIcon((QIcon *)&stack0x000000a8);
  FUN_005249f0(&stack0x000000a0);
  FUN_00558a5a();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c8a9a name=FUN_004c8a9a size=32 ====

void FUN_004c8a9a(void)

{
  undefined8 in_stack_00000020;
  undefined8 in_stack_00000048;
  undefined8 in_stack_00000058;
  undefined8 in_stack_00000060;
  undefined8 in_stack_00000068;
  undefined8 in_stack_00000070;
  undefined8 in_stack_00000080;
  undefined8 in_stack_00000088;
  undefined8 in_stack_00000090;
  undefined8 in_stack_00000098;
  
  FUN_005249f0();
  FUN_005249f0(in_stack_00000088);
  FUN_005249f0(in_stack_00000068);
  FUN_005249f0(&stack0x000000f0);
  FUN_005249f0(in_stack_00000060);
  FUN_005249f0(in_stack_00000098);
  FUN_005249f0(in_stack_00000058);
  FUN_005249f0(in_stack_00000070);
  FUN_005249f0(in_stack_00000048);
  FUN_005249f0(in_stack_00000080);
  FUN_005249f0(in_stack_00000020);
  FUN_00528c1c(in_stack_00000090);
  QIcon::~QIcon((QIcon *)&stack0x000000a8);
  FUN_005249f0(&stack0x000000a0);
  FUN_00558a5a();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c8aba name=FUN_004c8aba size=16 ====

void FUN_004c8aba(void)

{
  QPixmap *unaff_RBP;
  QIcon *unaff_R13;
  undefined8 in_stack_00000020;
  undefined8 in_stack_00000038;
  undefined8 in_stack_00000048;
  undefined8 in_stack_00000058;
  undefined8 in_stack_00000060;
  undefined8 in_stack_00000068;
  undefined8 in_stack_00000070;
  undefined8 in_stack_00000080;
  undefined8 in_stack_00000088;
  undefined8 in_stack_00000090;
  undefined8 in_stack_00000098;
  
  QPixmap::~QPixmap(unaff_RBP);
  FUN_005249f0(&stack0x00000178);
  FUN_005249f0(in_stack_00000038);
  FUN_005249f0(in_stack_00000088);
  FUN_005249f0(in_stack_00000068);
  FUN_005249f0(&stack0x000000f0);
  FUN_005249f0(in_stack_00000060);
  FUN_005249f0(in_stack_00000098);
  FUN_005249f0(in_stack_00000058);
  FUN_005249f0(in_stack_00000070);
  FUN_005249f0(in_stack_00000048);
  FUN_005249f0(in_stack_00000080);
  FUN_005249f0(in_stack_00000020);
  FUN_00528c1c(in_stack_00000090);
  QIcon::~QIcon(unaff_R13);
  FUN_005249f0(&stack0x000000a0);
  FUN_00558a5a();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c8aca name=FUN_004c8aca size=42 ====

void FUN_004c8aca(void)

{
  undefined8 in_stack_00000020;
  undefined8 in_stack_00000028;
  undefined8 in_stack_00000048;
  undefined8 in_stack_00000058;
  undefined8 in_stack_00000060;
  undefined8 in_stack_00000068;
  undefined8 in_stack_00000070;
  undefined8 in_stack_00000080;
  undefined8 in_stack_00000088;
  undefined8 in_stack_00000090;
  undefined8 in_stack_00000098;
  
  FUN_005249f0();
  FUN_005249f0();
  FUN_005249f0(in_stack_00000028);
  FUN_005249f0(in_stack_00000088);
  FUN_005249f0(in_stack_00000068);
  FUN_005249f0();
  FUN_005249f0(in_stack_00000060);
  FUN_005249f0(in_stack_00000098);
  FUN_005249f0(in_stack_00000058);
  FUN_005249f0(in_stack_00000070);
  FUN_005249f0(in_stack_00000048);
  FUN_005249f0(in_stack_00000080);
  FUN_005249f0(in_stack_00000020);
  FUN_00528c1c(in_stack_00000090);
  QIcon::~QIcon((QIcon *)&stack0x000000a8);
  FUN_005249f0(&stack0x000000a0);
  FUN_00558a5a();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c8af4 name=FUN_004c8af4 size=42 ====

void FUN_004c8af4(void)

{
  QVariant *unaff_RBP;
  QVariant *unaff_R15;
  undefined8 in_stack_00000008;
  undefined8 in_stack_00000090;
  
  QVariant::~QVariant(unaff_RBP);
  FUN_005249f0(in_stack_00000008);
  QVariant::~QVariant(unaff_R15);
  FUN_00528c1c(in_stack_00000090);
  QIcon::~QIcon((QIcon *)&stack0x000000a8);
  FUN_005249f0(&stack0x000000a0);
  FUN_00558a5a();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c8b1e name=FUN_004c8b1e size=23 ====

void FUN_004c8b1e(void)

{
  QVariant *unaff_RBP;
  QVariant *unaff_R15;
  undefined8 in_stack_00000008;
  undefined8 in_stack_00000090;
  
  QVariant::~QVariant(unaff_RBP);
  FUN_005249f0(in_stack_00000008);
  QVariant::~QVariant(unaff_R15);
  FUN_00528c1c(in_stack_00000090);
  QIcon::~QIcon((QIcon *)&stack0x000000a8);
  FUN_005249f0(&stack0x000000a0);
  FUN_00558a5a();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c8b35 name=FUN_004c8b35 size=32 ====

void FUN_004c8b35(void)

{
  QVariant *unaff_RBP;
  undefined8 in_stack_00000020;
  undefined8 in_stack_00000048;
  undefined8 in_stack_00000058;
  undefined8 in_stack_00000060;
  undefined8 in_stack_00000068;
  undefined8 in_stack_00000070;
  undefined8 in_stack_00000080;
  undefined8 in_stack_00000088;
  undefined8 in_stack_00000090;
  undefined8 in_stack_00000098;
  
  QVariant::~QVariant(unaff_RBP);
  FUN_005249f0(in_stack_00000088);
  FUN_005249f0(in_stack_00000068);
  FUN_005249f0(&stack0x000000f0);
  FUN_005249f0(in_stack_00000060);
  FUN_005249f0(in_stack_00000098);
  FUN_005249f0(in_stack_00000058);
  FUN_005249f0(in_stack_00000070);
  FUN_005249f0(in_stack_00000048);
  FUN_005249f0(in_stack_00000080);
  FUN_005249f0(in_stack_00000020);
  FUN_00528c1c(in_stack_00000090);
  QIcon::~QIcon((QIcon *)&stack0x000000a8);
  FUN_005249f0(&stack0x000000a0);
  FUN_00558a5a();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c8b55 name=FUN_004c8b55 size=23 ====

void FUN_004c8b55(void)

{
  QVariant *unaff_RBP;
  QVariant *unaff_R15;
  undefined8 in_stack_00000008;
  undefined8 in_stack_00000090;
  
  QVariant::~QVariant(unaff_RBP);
  FUN_005249f0(in_stack_00000008);
  QVariant::~QVariant(unaff_R15);
  FUN_00528c1c(in_stack_00000090);
  QIcon::~QIcon((QIcon *)&stack0x000000a8);
  FUN_005249f0(&stack0x000000a0);
  FUN_00558a5a();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c8b6c name=FUN_004c8b6c size=23 ====

void FUN_004c8b6c(void)

{
  QVariant *unaff_RBP;
  QVariant *unaff_R15;
  undefined8 in_stack_00000008;
  undefined8 in_stack_00000090;
  
  QVariant::~QVariant(unaff_RBP);
  FUN_005249f0(in_stack_00000008);
  QVariant::~QVariant(unaff_R15);
  FUN_00528c1c(in_stack_00000090);
  QIcon::~QIcon((QIcon *)&stack0x000000a8);
  FUN_005249f0(&stack0x000000a0);
  FUN_00558a5a();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c8b83 name=FUN_004c8b83 size=26 ====

void FUN_004c8b83(void)

{
  QVariant *unaff_RBP;
  QVariant *unaff_R15;
  undefined8 in_stack_00000008;
  undefined8 in_stack_00000090;
  
  QVariant::~QVariant(unaff_RBP);
  FUN_005249f0(in_stack_00000008);
  QVariant::~QVariant(unaff_R15);
  FUN_00528c1c(in_stack_00000090);
  QIcon::~QIcon((QIcon *)&stack0x000000a8);
  FUN_005249f0(&stack0x000000a0);
  FUN_00558a5a();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c8b9d name=FUN_004c8b9d size=26 ====

void FUN_004c8b9d(void)

{
  QVariant *unaff_RBP;
  QVariant *unaff_R15;
  undefined8 in_stack_00000008;
  undefined8 in_stack_00000090;
  
  QVariant::~QVariant(unaff_RBP);
  FUN_005249f0(in_stack_00000008);
  QVariant::~QVariant(unaff_R15);
  FUN_00528c1c(in_stack_00000090);
  QIcon::~QIcon((QIcon *)&stack0x000000a8);
  FUN_005249f0(&stack0x000000a0);
  FUN_00558a5a();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c8bb7 name=FUN_004c8bb7 size=26 ====

void FUN_004c8bb7(void)

{
  QVariant *unaff_RBP;
  QVariant *unaff_R15;
  undefined8 in_stack_00000008;
  undefined8 in_stack_00000090;
  
  QVariant::~QVariant(unaff_RBP);
  FUN_005249f0(in_stack_00000008);
  QVariant::~QVariant(unaff_R15);
  FUN_00528c1c(in_stack_00000090);
  QIcon::~QIcon((QIcon *)&stack0x000000a8);
  FUN_005249f0(&stack0x000000a0);
  FUN_00558a5a();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c8bd1 name=FUN_004c8bd1 size=42 ====

void FUN_004c8bd1(void)

{
  QVariant *unaff_RBP;
  QVariant *unaff_R15;
  undefined8 in_stack_00000008;
  undefined8 in_stack_00000020;
  undefined8 in_stack_00000048;
  undefined8 in_stack_00000070;
  undefined8 in_stack_00000080;
  undefined8 in_stack_00000090;
  
  QVariant::~QVariant(unaff_RBP);
  FUN_005249f0(in_stack_00000008);
  QVariant::~QVariant(unaff_R15);
  FUN_005249f0(in_stack_00000070);
  FUN_005249f0(in_stack_00000048);
  FUN_005249f0(in_stack_00000080);
  FUN_005249f0(in_stack_00000020);
  FUN_00528c1c(in_stack_00000090);
  QIcon::~QIcon((QIcon *)&stack0x000000a8);
  FUN_005249f0(&stack0x000000a0);
  FUN_00558a5a();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c8bfb name=FUN_004c8bfb size=42 ====

void FUN_004c8bfb(void)

{
  QVariant *unaff_RBP;
  QVariant *unaff_R15;
  undefined8 in_stack_00000008;
  undefined8 in_stack_00000020;
  undefined8 in_stack_00000048;
  undefined8 in_stack_00000080;
  undefined8 in_stack_00000090;
  
  QVariant::~QVariant(unaff_RBP);
  FUN_005249f0(in_stack_00000008);
  QVariant::~QVariant(unaff_R15);
  FUN_005249f0(in_stack_00000048);
  FUN_005249f0(in_stack_00000080);
  FUN_005249f0(in_stack_00000020);
  FUN_00528c1c(in_stack_00000090);
  QIcon::~QIcon((QIcon *)&stack0x000000a8);
  FUN_005249f0(&stack0x000000a0);
  FUN_00558a5a();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c8c25 name=FUN_004c8c25 size=42 ====

void FUN_004c8c25(void)

{
  undefined8 in_stack_00000020;
  undefined8 in_stack_00000028;
  undefined8 in_stack_00000048;
  undefined8 in_stack_00000058;
  undefined8 in_stack_00000060;
  undefined8 in_stack_00000068;
  undefined8 in_stack_00000070;
  undefined8 in_stack_00000080;
  undefined8 in_stack_00000088;
  undefined8 in_stack_00000090;
  undefined8 in_stack_00000098;
  
  FUN_005249f0();
  FUN_005249f0();
  FUN_005249f0(in_stack_00000028);
  FUN_005249f0(in_stack_00000088);
  FUN_005249f0(in_stack_00000068);
  FUN_005249f0();
  FUN_005249f0(in_stack_00000060);
  FUN_005249f0(in_stack_00000098);
  FUN_005249f0(in_stack_00000058);
  FUN_005249f0(in_stack_00000070);
  FUN_005249f0(in_stack_00000048);
  FUN_005249f0(in_stack_00000080);
  FUN_005249f0(in_stack_00000020);
  FUN_00528c1c(in_stack_00000090);
  QIcon::~QIcon((QIcon *)&stack0x000000a8);
  FUN_005249f0(&stack0x000000a0);
  FUN_00558a5a();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c8c4f name=FUN_004c8c4f size=71 ====

void FUN_004c8c4f(void)

{
  undefined8 in_stack_00000020;
  undefined8 in_stack_00000028;
  undefined8 in_stack_00000048;
  undefined8 in_stack_00000058;
  undefined8 in_stack_00000060;
  undefined8 in_stack_00000068;
  undefined8 in_stack_00000070;
  undefined8 in_stack_00000080;
  undefined8 in_stack_00000088;
  undefined8 in_stack_00000090;
  undefined8 in_stack_00000098;
  
  FUN_005249f0();
  FUN_005249f0();
  FUN_005249f0();
  FUN_005249c0(in_stack_00000028);
  FUN_005249f0(&stack0x00000210);
  FUN_005249f0(in_stack_00000088);
  FUN_005249f0(in_stack_00000068);
  FUN_005249f0(&stack0x000000f0);
  FUN_005249f0(in_stack_00000060);
  FUN_005249f0(in_stack_00000098);
  FUN_005249f0(in_stack_00000058);
  FUN_005249f0(in_stack_00000070);
  FUN_005249f0(in_stack_00000048);
  FUN_005249f0(in_stack_00000080);
  FUN_005249f0(in_stack_00000020);
  FUN_00528c1c(in_stack_00000090);
  QIcon::~QIcon((QIcon *)&stack0x000000a8);
  FUN_005249f0(&stack0x000000a0);
  FUN_00558a5a();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c8c96 name=FUN_004c8c96 size=29 ====

void FUN_004c8c96(void)

{
  undefined8 in_stack_00000020;
  undefined8 in_stack_00000048;
  undefined8 in_stack_00000058;
  undefined8 in_stack_00000060;
  undefined8 in_stack_00000068;
  undefined8 in_stack_00000070;
  undefined8 in_stack_00000080;
  undefined8 in_stack_00000088;
  undefined8 in_stack_00000090;
  undefined8 in_stack_00000098;
  
  FUN_005249f0();
  FUN_005249f0();
  FUN_005249f0(in_stack_00000088);
  FUN_005249f0(in_stack_00000068);
  FUN_005249f0();
  FUN_005249f0(in_stack_00000060);
  FUN_005249f0(in_stack_00000098);
  FUN_005249f0(in_stack_00000058);
  FUN_005249f0(in_stack_00000070);
  FUN_005249f0(in_stack_00000048);
  FUN_005249f0(in_stack_00000080);
  FUN_005249f0(in_stack_00000020);
  FUN_00528c1c(in_stack_00000090);
  QIcon::~QIcon((QIcon *)&stack0x000000a8);
  FUN_005249f0(&stack0x000000a0);
  FUN_00558a5a();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c8cb3 name=FUN_004c8cb3 size=13 ====

void FUN_004c8cb3(void)

{
  undefined8 in_stack_00000020;
  undefined8 in_stack_00000048;
  undefined8 in_stack_00000058;
  undefined8 in_stack_00000060;
  undefined8 in_stack_00000068;
  undefined8 in_stack_00000070;
  undefined8 in_stack_00000080;
  undefined8 in_stack_00000088;
  undefined8 in_stack_00000090;
  undefined8 in_stack_00000098;
  
  FUN_005249f0();
  FUN_005249f0();
  FUN_005249f0(in_stack_00000088);
  FUN_005249f0(in_stack_00000068);
  FUN_005249f0();
  FUN_005249f0(in_stack_00000060);
  FUN_005249f0(in_stack_00000098);
  FUN_005249f0(in_stack_00000058);
  FUN_005249f0(in_stack_00000070);
  FUN_005249f0(in_stack_00000048);
  FUN_005249f0(in_stack_00000080);
  FUN_005249f0(in_stack_00000020);
  FUN_00528c1c(in_stack_00000090);
  QIcon::~QIcon((QIcon *)&stack0x000000a8);
  FUN_005249f0(&stack0x000000a0);
  FUN_00558a5a();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c8cc0 name=FUN_004c8cc0 size=29 ====

void FUN_004c8cc0(void)

{
  undefined8 in_stack_00000020;
  undefined8 in_stack_00000048;
  undefined8 in_stack_00000058;
  undefined8 in_stack_00000060;
  undefined8 in_stack_00000068;
  undefined8 in_stack_00000070;
  undefined8 in_stack_00000080;
  undefined8 in_stack_00000088;
  undefined8 in_stack_00000090;
  undefined8 in_stack_00000098;
  
  FUN_005249f0();
  FUN_005249f0(in_stack_00000088);
  FUN_005249f0(in_stack_00000068);
  FUN_005249f0(&stack0x000000f0);
  FUN_005249f0(in_stack_00000060);
  FUN_005249f0(in_stack_00000098);
  FUN_005249f0(in_stack_00000058);
  FUN_005249f0(in_stack_00000070);
  FUN_005249f0(in_stack_00000048);
  FUN_005249f0(in_stack_00000080);
  FUN_005249f0(in_stack_00000020);
  FUN_00528c1c(in_stack_00000090);
  QIcon::~QIcon((QIcon *)&stack0x000000a8);
  FUN_005249f0(&stack0x000000a0);
  FUN_00558a5a();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c8cdd name=FUN_004c8cdd size=21 ====

void FUN_004c8cdd(void)

{
  QIcon *unaff_R13;
  QRegion *unaff_R15;
  undefined8 in_stack_00000020;
  undefined8 in_stack_00000038;
  undefined8 in_stack_00000048;
  undefined8 in_stack_00000058;
  undefined8 in_stack_00000060;
  undefined8 in_stack_00000068;
  undefined8 in_stack_00000070;
  undefined8 in_stack_00000080;
  undefined8 in_stack_00000088;
  undefined8 in_stack_00000090;
  undefined8 in_stack_00000098;
  
  QRegion::~QRegion(unaff_R15);
  FUN_005249f0();
  FUN_005249f0(&stack0x00000178);
  FUN_005249f0(in_stack_00000038);
  FUN_005249f0(in_stack_00000088);
  FUN_005249f0(in_stack_00000068);
  FUN_005249f0(&stack0x000000f0);
  FUN_005249f0(in_stack_00000060);
  FUN_005249f0(in_stack_00000098);
  FUN_005249f0(in_stack_00000058);
  FUN_005249f0(in_stack_00000070);
  FUN_005249f0(in_stack_00000048);
  FUN_005249f0(in_stack_00000080);
  FUN_005249f0(in_stack_00000020);
  FUN_00528c1c(in_stack_00000090);
  QIcon::~QIcon(unaff_R13);
  FUN_005249f0(&stack0x000000a0);
  FUN_00558a5a();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c8cf2 name=FUN_004c8cf2 size=16 ====

void FUN_004c8cf2(void)

{
  FUN_005249f0();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c8d02 name=FUN_004c8d02 size=16 ====

void FUN_004c8d02(void)

{
  FUN_005249f0();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c8d12 name=FUN_004c8d12 size=24 ====

void FUN_004c8d12(void)

{
  QRegularExpressionMatch *unaff_RBP;
  QRegularExpression *unaff_R13;
  
  QRegularExpressionMatch::~QRegularExpressionMatch(unaff_RBP);
  QRegularExpression::~QRegularExpression(unaff_R13);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c8d2a name=FUN_004c8d2a size=10 ====

void FUN_004c8d2a(void)

{
  QRegularExpression *unaff_R13;
  
  FUN_005249f0();
  QRegularExpression::~QRegularExpression(unaff_R13);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c8d34 name=FUN_004c8d34 size=21 ====

void FUN_004c8d34(void)

{
  void *unaff_RBX;
  
  operator_delete(unaff_RBX,0x30);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c8d49 name=FUN_004c8d49 size=24 ====

void FUN_004c8d49(void)

{
  QFontMetrics *unaff_R12;
  
  QFontMetrics::~QFontMetrics(unaff_R12);
  FUN_005249f0();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c8d62 name=FUN_004c8d62 size=16 ====

void FUN_004c8d62(void)

{
  FUN_005249f0();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c8d72 name=FUN_004c8d72 size=16 ====

void FUN_004c8d72(void)

{
  FUN_005249f0();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c8d82 name=FUN_004c8d82 size=70 ====

void FUN_004c8d82(void)

{
  QStyleOption *unaff_RBP;
  
  QBrush::~QBrush((QBrush *)(unaff_RBP + 0xb8));
  FUN_005249f0(unaff_RBP + 0xa8);
  QIcon::~QIcon((QIcon *)(unaff_RBP + 0xa0));
  QLocale::~QLocale((QLocale *)(unaff_RBP + 0x70));
  QFont::~QFont((QFont *)(unaff_RBP + 0x58));
  QStyleOption::~QStyleOption(unaff_RBP);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c8dc8 name=FUN_004c8dc8 size=16 ====

void FUN_004c8dc8(void)

{
  FUN_00558a5a();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c8dd8 name=FUN_004c8dd8 size=31 ====

void FUN_004c8dd8(void)

{
  _Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *in_stack_00000038;
  
  if (in_stack_00000038 != (_Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *)0x0) {
    std::_Sp_counted_base<(__gnu_cxx::_Lock_policy)2>::_M_release(in_stack_00000038);
  }
  FUN_005249f0();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c8df7 name=FUN_004c8df7 size=16 ====

void FUN_004c8df7(void)

{
  QVariant *unaff_R12;
  
  QVariant::~QVariant(unaff_R12);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c8e08 name=FUN_004c8e08 size=16 ====

void FUN_004c8e08(void)

{
  QVariant *unaff_RBP;
  
  QVariant::~QVariant(unaff_RBP);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c8e18 name=FUN_004c8e18 size=52 ====

void FUN_004c8e18(void)

{
  QArrayData *in_stack_00000008;
  
  if (*(int *)in_stack_00000008 != 0) {
    if (*(int *)in_stack_00000008 == -1) goto LAB_004c8e32;
    LOCK();
    *(int *)in_stack_00000008 = *(int *)in_stack_00000008 + -1;
    UNLOCK();
    if (*(int *)in_stack_00000008 != 0) goto LAB_004c8e32;
  }
  QArrayData::deallocate(in_stack_00000008,2,8);
LAB_004c8e32:
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c8e4c name=FUN_004c8e4c size=16 ====

void FUN_004c8e4c(void)

{
  FUN_0058b7a8();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c8e60 name=FUN_004c8e60 size=25 ====

void FUN_004c8e60(void)

{
  long unaff_RBP;
  
  if (unaff_RBP != 0) {
    QObject::blockSignals(SUB81(unaff_RBP,0));
  }
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c8e79 name=FUN_004c8e79 size=24 ====

void FUN_004c8e79(void)

{
  QVariant *unaff_RBX;
  QVariant *unaff_R12;
  
  QVariant::~QVariant(unaff_RBX);
  QVariant::~QVariant(unaff_R12);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c8e91 name=FUN_004c8e91 size=40 ====

void FUN_004c8e91(void)

{
  QVariant *unaff_RBP;
  QVariant *unaff_R12;
  
  QVariant::~QVariant(unaff_RBP);
  QVariant::~QVariant(unaff_R12);
  FUN_005249f0();
  FUN_005249f0();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c8eb9 name=FUN_004c8eb9 size=32 ====

void FUN_004c8eb9(void)

{
  FUN_005249f0();
  FUN_005249f0();
  FUN_005249f0();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c8eda name=FUN_004c8eda size=51 ====

void FUN_004c8eda(void)

{
  QVariant *unaff_RBP;
  QVariant *unaff_R15;
  
  QVariant::~QVariant(unaff_R15);
  QVariant::~QVariant(unaff_RBP);
  FUN_005249f0();
  FUN_005249f0();
  FUN_005249f0();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c8f0e name=FUN_004c8f0e size=9 ====

void FUN_004c8f0e(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ==== entry=004c8f17 name=FUN_004c8f17 size=24 ====

void FUN_004c8f17(void)

{
  QVariant *unaff_R13;
  QVariant *unaff_R15;
  
  QVariant::~QVariant(unaff_R15);
  QVariant::~QVariant(unaff_R13);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c8f30 name=FUN_004c8f30 size=24 ====

void FUN_004c8f30(void)

{
  QVariant *unaff_RBX;
  QVariant *unaff_RBP;
  
  QVariant::~QVariant(unaff_RBP);
  QVariant::~QVariant(unaff_RBX);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c8f48 name=FUN_004c8f48 size=20 ====

void FUN_004c8f48(void)

{
  bool unaff_BL;
  
  QObject::blockSignals(unaff_BL);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c8f5c name=FUN_004c8f5c size=24 ====

void FUN_004c8f5c(void)

{
  QIcon *unaff_RBP;
  
  QIcon::~QIcon(unaff_RBP);
  FUN_005249f0();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c8f74 name=FUN_004c8f74 size=21 ====

void FUN_004c8f74(void)

{
  void *unaff_RBX;
  
  operator_delete(unaff_RBX,0x30);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c8f8a name=FUN_004c8f8a size=16 ====

void FUN_004c8f8a(void)

{
  FUN_005249f0();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c8f9a name=FUN_004c8f9a size=16 ====

void FUN_004c8f9a(void)

{
  FUN_005249f0();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c8faa name=FUN_004c8faa size=24 ====

void FUN_004c8faa(void)

{
  QVariant *unaff_RBP;
  
  QVariant::~QVariant(unaff_RBP);
  FUN_005249c0();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c8fc2 name=FUN_004c8fc2 size=21 ====

void FUN_004c8fc2(void)

{
  void *unaff_RBX;
  
  operator_delete(unaff_RBX,0x30);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c8fd7 name=FUN_004c8fd7 size=32 ====

void FUN_004c8fd7(void)

{
  FUN_005249f0();
  FUN_005249f0();
  FUN_005249f0();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c8ff7 name=FUN_004c8ff7 size=16 ====

void FUN_004c8ff7(void)

{
  FUN_005249f0();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c9007 name=FUN_004c9007 size=24 ====

void FUN_004c9007(void)

{
  QVariant *unaff_R14;
  
  QVariant::~QVariant(unaff_R14);
  FUN_005249c0();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c901f name=FUN_004c901f size=24 ====

void FUN_004c901f(void)

{
  FUN_00af2c10();
  FUN_005249f0();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c9038 name=FUN_004c9038 size=34 ====

void FUN_004c9038(void)

{
  undefined8 in_stack_00000010;
  
  FUN_005249c0();
  FUN_005249f0();
  FUN_005249f0(in_stack_00000010);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c905a name=FUN_004c905a size=31 ====

void FUN_004c905a(void)

{
  undefined8 in_stack_00000010;
  undefined8 in_stack_00000018;
  
  FUN_005249f0();
  FUN_005249f0();
  FUN_005249f0(in_stack_00000018);
  FUN_005249f0();
  FUN_005249f0(in_stack_00000010);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c907a name=FUN_004c907a size=10 ====

void FUN_004c907a(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ==== entry=004c9084 name=FUN_004c9084 size=43 ====

void FUN_004c9084(void)

{
  QDialog *unaff_RBX;
  undefined **ppuStack0000000000000010;
  
  ppuStack0000000000000010 = &PTR_FUN_011a26f0;
  QDialog::~QDialog(unaff_RBX);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c90b0 name=FUN_004c90b0 size=24 ====

void FUN_004c90b0(void)

{
  QVariant *unaff_RBX;
  QVariant *unaff_RBP;
  
  QVariant::~QVariant(unaff_RBP);
  QVariant::~QVariant(unaff_RBX);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c90c8 name=FUN_004c90c8 size=21 ====

void FUN_004c90c8(void)

{
  FUN_005249f0();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c90de name=FUN_004c90de size=24 ====

void FUN_004c90de(void)

{
  QVariant *unaff_RBP;
  QVariant *unaff_R12;
  
  QVariant::~QVariant(unaff_RBP);
  QVariant::~QVariant(unaff_R12);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c90f6 name=FUN_004c90f6 size=24 ====

void FUN_004c90f6(void)

{
  FUN_005249f0();
  FUN_005249f0();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c910e name=FUN_004c910e size=16 ====

void FUN_004c910e(void)

{
  FUN_005249f0();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c911e name=FUN_004c911e size=16 ====

void FUN_004c911e(void)

{
  FUN_005249f0();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c912e name=FUN_004c912e size=24 ====

void FUN_004c912e(void)

{
  FUN_005249f0();
  FUN_005249f0();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c9146 name=FUN_004c9146 size=16 ====

void FUN_004c9146(void)

{
  FUN_005249f0();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c9156 name=FUN_004c9156 size=16 ====

void FUN_004c9156(void)

{
  FUN_005249f0();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c9166 name=FUN_004c9166 size=32 ====

void FUN_004c9166(void)

{
  FUN_005249f0();
  FUN_005249f0();
  FUN_005249f0();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c9186 name=FUN_004c9186 size=24 ====

void FUN_004c9186(void)

{
  QVariant *unaff_RBP;
  QVariant *unaff_R12;
  
  QVariant::~QVariant(unaff_R12);
  QVariant::~QVariant(unaff_RBP);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c919e name=FUN_004c919e size=32 ====

void FUN_004c919e(void)

{
  FUN_005249f0();
  FUN_005249f0();
  FUN_005249f0();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c91be name=FUN_004c91be size=42 ====

void FUN_004c91be(void)

{
  QVariant *unaff_RBP;
  QVariant *unaff_R14;
  undefined8 in_stack_00000008;
  
  QVariant::~QVariant(unaff_R14);
  QVariant::~QVariant(unaff_RBP);
  FUN_005249f0();
  FUN_005249f0(in_stack_00000008);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c91e8 name=FUN_004c91e8 size=18 ====

void FUN_004c91e8(void)

{
  undefined8 in_stack_00000008;
  
  FUN_005249f0();
  FUN_005249f0();
  FUN_005249f0(in_stack_00000008);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c91fa name=FUN_004c91fa size=19 ====

void FUN_004c91fa(void)

{
  FUN_0057d040();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c920e name=FUN_004c920e size=32 ====

void FUN_004c920e(void)

{
  FUN_00525060();
  FUN_0057d040();
  FUN_005249f0();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c922e name=FUN_004c922e size=10 ====

void FUN_004c922e(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ==== entry=004c9238 name=FUN_004c9238 size=24 ====

void FUN_004c9238(void)

{
  FUN_00525060();
  FUN_00525060();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c9250 name=FUN_004c9250 size=36 ====

void FUN_004c9250(void)

{
  void *unaff_RBP;
  _Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *in_stack_00000038;
  
  operator_delete(unaff_RBP,0xa0);
  if (in_stack_00000038 != (_Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *)0x0) {
    std::_Sp_counted_base<(__gnu_cxx::_Lock_policy)2>::_M_release(in_stack_00000038);
  }
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c9274 name=FUN_004c9274 size=36 ====

void FUN_004c9274(void)

{
  void *unaff_RBP;
  _Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *in_stack_00000038;
  
  operator_delete(unaff_RBP,0xa0);
  if (in_stack_00000038 != (_Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *)0x0) {
    std::_Sp_counted_base<(__gnu_cxx::_Lock_policy)2>::_M_release(in_stack_00000038);
  }
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c9298 name=FUN_004c9298 size=36 ====

void FUN_004c9298(void)

{
  void *unaff_RBP;
  _Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *in_stack_00000038;
  
  operator_delete(unaff_RBP,0xa0);
  if (in_stack_00000038 != (_Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *)0x0) {
    std::_Sp_counted_base<(__gnu_cxx::_Lock_policy)2>::_M_release(in_stack_00000038);
  }
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c92bc name=FUN_004c92bc size=22 ====

void FUN_004c92bc(void)

{
  long unaff_RBX;
  
  if (*(_Sp_counted_base<(__gnu_cxx::_Lock_policy)2> **)(unaff_RBX + 8) !=
      (_Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *)0x0) {
    std::_Sp_counted_base<(__gnu_cxx::_Lock_policy)2>::_M_release
              (*(_Sp_counted_base<(__gnu_cxx::_Lock_policy)2> **)(unaff_RBX + 8));
  }
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c92d2 name=FUN_004c92d2 size=50 ====

void FUN_004c92d2(void)

{
  QVariant *unaff_RBX;
  QVariant *unaff_RBP;
  _Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *in_stack_00000008;
  
  QVariant::~QVariant(unaff_RBP);
  QVariant::~QVariant(unaff_RBX);
  FUN_005249f0();
  if (in_stack_00000008 != (_Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *)0x0) {
    std::_Sp_counted_base<(__gnu_cxx::_Lock_policy)2>::_M_release(in_stack_00000008);
  }
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c9304 name=FUN_004c9304 size=29 ====

void FUN_004c9304(void)

{
  QVariant *unaff_RBX;
  QVariant *unaff_RBP;
  _Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *in_stack_00000008;
  
  QVariant::~QVariant(unaff_RBX);
  QVariant::~QVariant(unaff_RBP);
  FUN_005249f0();
  if (in_stack_00000008 != (_Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *)0x0) {
    std::_Sp_counted_base<(__gnu_cxx::_Lock_policy)2>::_M_release(in_stack_00000008);
  }
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c9321 name=FUN_004c9321 size=29 ====

void FUN_004c9321(void)

{
  QVariant *unaff_RBX;
  QVariant *unaff_R13;
  _Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *in_stack_00000008;
  
  QVariant::~QVariant(unaff_RBX);
  QVariant::~QVariant(unaff_R13);
  FUN_005249f0();
  if (in_stack_00000008 != (_Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *)0x0) {
    std::_Sp_counted_base<(__gnu_cxx::_Lock_policy)2>::_M_release(in_stack_00000008);
  }
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c933e name=FUN_004c933e size=16 ====

void FUN_004c933e(void)

{
  FUN_00525060();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c934e name=FUN_004c934e size=16 ====

void FUN_004c934e(void)

{
  FUN_00525060();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c935e name=FUN_004c935e size=16 ====

void FUN_004c935e(void)

{
  FUN_00525060();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c936e name=FUN_004c936e size=16 ====

void FUN_004c936e(void)

{
  FUN_00525060();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c937e name=FUN_004c937e size=29 ====

void FUN_004c937e(void)

{
  void *unaff_RBP;
  
  operator_delete(unaff_RBP,0x10);
  FUN_005249f0();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c939b name=FUN_004c939b size=18 ====

void FUN_004c939b(void)

{
  FUN_005249f0();
  FUN_005249f0();
  FUN_005249f0();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c93ad name=FUN_004c93ad size=10 ====

void FUN_004c93ad(void)

{
  FUN_005249f0();
  FUN_005249f0();
  FUN_005249f0();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c93c1 name=FUN_004c93c1 size=43 ====

void FUN_004c93c1(void)

{
  QVariant *unaff_RBP;
  QVariant *unaff_R12;
  
  QVariant::~QVariant(unaff_R12);
  QVariant::~QVariant(unaff_RBP);
  FUN_00544650();
  FUN_005249f0();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c93ec name=FUN_004c93ec size=28 ====

void FUN_004c93ec(void)

{
  QVariant *unaff_RBP;
  
  QVariant::~QVariant(unaff_RBP + 0x20);
  QVariant::~QVariant(unaff_RBP + 0x10);
  QVariant::~QVariant(unaff_RBP);
  FUN_005249f0();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c9408 name=FUN_004c9408 size=32 ====

void FUN_004c9408(void)

{
  FUN_005249f0();
  FUN_005249f0();
  FUN_005249f0();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c9428 name=FUN_004c9428 size=43 ====

void FUN_004c9428(void)

{
  QVariant *unaff_RBP;
  QVariant *unaff_R12;
  
  QVariant::~QVariant(unaff_R12);
  QVariant::~QVariant(unaff_RBP);
  FUN_00544650();
  FUN_005249f0();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c9453 name=FUN_004c9453 size=28 ====

void FUN_004c9453(void)

{
  QVariant *unaff_RBP;
  
  QVariant::~QVariant(unaff_RBP + 0x20);
  QVariant::~QVariant(unaff_RBP + 0x10);
  QVariant::~QVariant(unaff_RBP);
  FUN_005249f0();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c946f name=FUN_004c946f size=32 ====

void FUN_004c946f(void)

{
  FUN_005249f0();
  FUN_005249f0();
  FUN_005249f0();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c9490 name=FUN_004c9490 size=16 ====

void FUN_004c9490(void)

{
  __cxa_guard_abort();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c94a0 name=FUN_004c94a0 size=31 ====

void FUN_004c94a0(void)

{
  void *unaff_RBP;
  undefined8 in_stack_00000008;
  
  operator_delete(unaff_RBP,0x30);
  FUN_00525060(in_stack_00000008);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c94c9 name=FUN_004c94c9 size=10 ====

void FUN_004c94c9(void)

{
  QFileInfo *unaff_R13;
  undefined8 in_stack_00000008;
  
  QFileInfo::~QFileInfo(unaff_R13);
  FUN_00525060(in_stack_00000008);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c94d3 name=FUN_004c94d3 size=15 ====

void FUN_004c94d3(void)

{
  undefined8 in_stack_00000008;
  
  FUN_005249f0();
  FUN_00525060(in_stack_00000008);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c94e2 name=FUN_004c94e2 size=21 ====

void FUN_004c94e2(void)

{
  undefined8 in_stack_00000008;
  
  FUN_005249f0();
  FUN_005249f0();
  FUN_00525060(in_stack_00000008);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c94f7 name=FUN_004c94f7 size=13 ====

void FUN_004c94f7(void)

{
  undefined8 in_stack_00000008;
  
  FUN_005249f0();
  FUN_00525060(in_stack_00000008);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c9504 name=FUN_004c9504 size=24 ====

void FUN_004c9504(void)

{
  FUN_005249f0();
  FUN_005249f0();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c951c name=FUN_004c951c size=87 ====

void FUN_004c951c(void)

{
  QVariant *unaff_R14;
  QVariant *in_stack_00000028;
  QVariant *in_stack_00000030;
  _Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *in_stack_00000078;
  _Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *in_stack_000000b8;
  
  if (in_stack_000000b8 != (_Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *)0x0) {
    std::_Sp_counted_base<(__gnu_cxx::_Lock_policy)2>::_M_release(in_stack_000000b8);
  }
  QVariant::~QVariant(unaff_R14);
  QVariant::~QVariant(in_stack_00000028);
  QVariant::~QVariant(in_stack_00000030);
  FUN_00535600();
  FUN_005249f0();
  if (in_stack_00000078 != (_Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *)0x0) {
    std::_Sp_counted_base<(__gnu_cxx::_Lock_policy)2>::_M_release(in_stack_00000078);
  }
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c9573 name=FUN_004c9573 size=15 ====

void FUN_004c9573(void)

{
  _Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *in_stack_00000078;
  
  FUN_005249f0();
  FUN_00535600();
  FUN_005249f0();
  if (in_stack_00000078 != (_Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *)0x0) {
    std::_Sp_counted_base<(__gnu_cxx::_Lock_policy)2>::_M_release(in_stack_00000078);
  }
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c9582 name=FUN_004c9582 size=28 ====

void FUN_004c9582(void)

{
  _Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *in_stack_00000078;
  
  FUN_005249f0(&stack0x000000e0);
  FUN_005249f0(&stack0x000000c0);
  FUN_005249f0();
  if (in_stack_00000078 != (_Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *)0x0) {
    std::_Sp_counted_base<(__gnu_cxx::_Lock_policy)2>::_M_release(in_stack_00000078);
  }
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c959e name=FUN_004c959e size=15 ====

void FUN_004c959e(void)

{
  void *unaff_R14;
  _Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *in_stack_00000078;
  
  operator_delete(unaff_R14,0xa0);
  FUN_005249f0();
  if (in_stack_00000078 != (_Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *)0x0) {
    std::_Sp_counted_base<(__gnu_cxx::_Lock_policy)2>::_M_release(in_stack_00000078);
  }
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c95ad name=FUN_004c95ad size=15 ====

void FUN_004c95ad(void)

{
  _Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *in_stack_00000078;
  
  FUN_005249f0();
  FUN_00535600();
  FUN_005249f0(&stack0x00000040);
  if (in_stack_00000078 != (_Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *)0x0) {
    std::_Sp_counted_base<(__gnu_cxx::_Lock_policy)2>::_M_release(in_stack_00000078);
  }
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c95bc name=FUN_004c95bc size=15 ====

void FUN_004c95bc(void)

{
  QVariant *unaff_R14;
  QVariant *in_stack_00000028;
  QVariant *in_stack_00000030;
  undefined8 in_stack_00000038;
  _Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *in_stack_00000078;
  
  FUN_005249c0(in_stack_00000038);
  QVariant::~QVariant(unaff_R14);
  QVariant::~QVariant(in_stack_00000028);
  QVariant::~QVariant(in_stack_00000030);
  FUN_00535600();
  FUN_005249f0();
  if (in_stack_00000078 != (_Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *)0x0) {
    std::_Sp_counted_base<(__gnu_cxx::_Lock_policy)2>::_M_release(in_stack_00000078);
  }
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c95cc name=FUN_004c95cc size=16 ====

void FUN_004c95cc(void)

{
  FUN_00535600();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c95dc name=FUN_004c95dc size=40 ====

void FUN_004c95dc(void)

{
  QVariant *unaff_RBP;
  
  FUN_005249f0();
  QVariant::~QVariant(unaff_RBP);
  FUN_00535600();
  FUN_00525060();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c9604 name=FUN_004c9604 size=44 ====

void FUN_004c9604(void)

{
  void *unaff_RBP;
  _Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *in_stack_00000068;
  
  operator_delete(unaff_RBP,0xa0);
  if (in_stack_00000068 != (_Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *)0x0) {
    std::_Sp_counted_base<(__gnu_cxx::_Lock_policy)2>::_M_release(in_stack_00000068);
  }
  FUN_00525060();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c9630 name=FUN_004c9630 size=21 ====

void FUN_004c9630(void)

{
  long unaff_R12;
  long unaff_R13;
  
  FUN_00525060(unaff_R13 + 0x10);
  FUN_00525060(unaff_R12 + 0x10);
  FUN_00525060();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c9646 name=FUN_004c9646 size=42 ====

void FUN_004c9646(void)

{
  undefined8 in_stack_00000008;
  
  FUN_005249f0();
  FUN_005249f0(in_stack_00000008);
  FUN_00525060();
  FUN_00525060();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c9670 name=FUN_004c9670 size=10 ====

void FUN_004c9670(void)

{
  undefined8 in_stack_00000008;
  
  FUN_005249f0();
  FUN_005249f0(in_stack_00000008);
  FUN_00525060();
  FUN_00525060();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c967a name=FUN_004c967a size=32 ====

void FUN_004c967a(void)

{
  FUN_005249f0();
  FUN_00525060();
  FUN_00535600();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c969a name=FUN_004c969a size=33 ====

/* WARNING: Removing unreachable block (ram,0x004c96a1) */

void FUN_004c969a(void)

{
  FUN_00525060();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c96bb name=FUN_004c96bb size=14 ====

/* WARNING: Removing unreachable block (ram,0x004c96a1) */

void FUN_004c96bb(void)

{
  FUN_005249f0(&stack0x00000028);
  FUN_00525060();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c96c9 name=FUN_004c96c9 size=26 ====

void FUN_004c96c9(void)

{
  QVariant *unaff_RBP;
  QVariant *unaff_R14;
  
  QVariant::~QVariant(unaff_R14);
  QVariant::~QVariant(unaff_RBP);
  FUN_005249f0();
  FUN_00525060();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c96e3 name=FUN_004c96e3 size=15 ====

void FUN_004c96e3(void)

{
  FUN_005249f0();
  FUN_005249f0();
  FUN_00525060();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c96f2 name=FUN_004c96f2 size=7 ====

void FUN_004c96f2(void)

{
  FUN_005249f0(&stack0x00000020);
  FUN_00525060();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c96f9 name=FUN_004c96f9 size=22 ====

/* WARNING: Removing unreachable block (ram,0x004c96a1) */

void FUN_004c96f9(void)

{
  FUN_005249f0();
  FUN_005249f0(&stack0x00000030);
  FUN_005249f0(&stack0x00000028);
  FUN_00525060();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c9710 name=FUN_004c9710 size=24 ====

void FUN_004c9710(void)

{
  FUN_005249f0();
  FUN_00535600();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c9728 name=FUN_004c9728 size=31 ====

void FUN_004c9728(void)

{
  _Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *in_stack_00000078;
  
  if (in_stack_00000078 != (_Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *)0x0) {
    std::_Sp_counted_base<(__gnu_cxx::_Lock_policy)2>::_M_release(in_stack_00000078);
  }
  FUN_00535600();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c9747 name=FUN_004c9747 size=16 ====

void FUN_004c9747(void)

{
  FUN_005249f0();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c9757 name=FUN_004c9757 size=35 ====

void FUN_004c9757(void)

{
  FUN_005249f0();
  FUN_005249f0();
  FUN_005249f0();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c977a name=FUN_004c977a size=37 ====

void FUN_004c977a(void)

{
  FUN_005249f0();
  FUN_005249f0();
  FUN_005249f0();
  FUN_005249f0();
  FUN_005249f0();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c979f name=FUN_004c979f size=23 ====

void FUN_004c979f(void)

{
  _Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *in_stack_00000078;
  
  if (in_stack_00000078 != (_Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *)0x0) {
    std::_Sp_counted_base<(__gnu_cxx::_Lock_policy)2>::_M_release(in_stack_00000078);
  }
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c97b6 name=FUN_004c97b6 size=21 ====

void FUN_004c97b6(void)

{
  void *unaff_RBP;
  
  operator_delete(unaff_RBP,0x10);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c97cb name=FUN_004c97cb size=55 ====

void FUN_004c97cb(void)

{
  code *pcVar1;
  _func_void_Node_ptr *unaff_R12;
  
  pcVar1 = unaff_R12 + 0x10;
  if (*(int *)(unaff_R12 + 0x10) != 0) {
    if (*(int *)(unaff_R12 + 0x10) == -1) goto LAB_004c97e8;
    LOCK();
    *(int *)pcVar1 = *(int *)pcVar1 + -1;
    UNLOCK();
    if (*(int *)pcVar1 != 0) goto LAB_004c97e8;
  }
  QHashData::free_helper(unaff_R12);
LAB_004c97e8:
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c9802 name=FUN_004c9802 size=10 ====

void FUN_004c9802(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ==== entry=004c980c name=FUN_004c980c size=24 ====

void FUN_004c980c(void)

{
  QVariant *unaff_RBP;
  QVariant *unaff_R12;
  
  QVariant::~QVariant(unaff_RBP);
  QVariant::~QVariant(unaff_R12);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c9824 name=FUN_004c9824 size=32 ====

void FUN_004c9824(void)

{
  QVariant *unaff_RBP;
  QVariant *unaff_R12;
  
  QVariant::~QVariant(unaff_R12);
  FUN_005249c0();
  QVariant::~QVariant(unaff_RBP);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c9844 name=FUN_004c9844 size=63 ====

void FUN_004c9844(void)

{
  QRegularExpression *unaff_R14;
  void *in_stack_00000020;
  
  operator_delete(in_stack_00000020,0x10);
  QRegularExpression::~QRegularExpression(unaff_R14);
  FUN_005249f0();
  FUN_005249f0();
  FUN_005249f0();
  FUN_005249f0();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c9883 name=FUN_004c9883 size=63 ====

void FUN_004c9883(void)

{
  QRegularExpression *unaff_R14;
  void *in_stack_00000020;
  
  operator_delete(in_stack_00000020,0x10);
  QRegularExpression::~QRegularExpression(unaff_R14);
  FUN_005249f0();
  FUN_005249f0();
  FUN_005249f0();
  FUN_005249f0();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c98c2 name=FUN_004c98c2 size=16 ====

void FUN_004c98c2(void)

{
  FUN_005249f0();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c98d2 name=FUN_004c98d2 size=21 ====

void FUN_004c98d2(void)

{
  void *unaff_RBP;
  
  operator_delete(unaff_RBP,0x50);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c98e7 name=FUN_004c98e7 size=16 ====

void FUN_004c98e7(void)

{
  FUN_00550ec0();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c98f7 name=FUN_004c98f7 size=29 ====

void FUN_004c98f7(void)

{
  void *unaff_R12;
  
  operator_delete(unaff_R12,8);
  FUN_005249f0();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c9914 name=FUN_004c9914 size=21 ====

void FUN_004c9914(void)

{
  void *unaff_RBP;
  
  operator_delete(unaff_RBP,0x78);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c9929 name=FUN_004c9929 size=16 ====

void FUN_004c9929(void)

{
  FUN_00550ec0();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c993a name=FUN_004c993a size=21 ====

void FUN_004c993a(void)

{
  void *unaff_RBP;
  
  operator_delete(unaff_RBP,0x48);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c994f name=FUN_004c994f size=21 ====

void FUN_004c994f(void)

{
  void *unaff_RBP;
  
  operator_delete(unaff_RBP,0x20);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c9964 name=FUN_004c9964 size=21 ====

void FUN_004c9964(void)

{
  void *unaff_R12;
  
  operator_delete(unaff_R12,0x20);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c9979 name=FUN_004c9979 size=21 ====

void FUN_004c9979(void)

{
  void *unaff_RBP;
  
  operator_delete(unaff_RBP,0x20);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c998e name=FUN_004c998e size=74 ====

void FUN_004c998e(void)

{
  QWidget *unaff_RBX;
  
  FUN_005249f0();
  FUN_00550ea0(unaff_RBX + 0xb0);
  FUN_00550ea0(unaff_RBX + 0xa0);
  FUN_00550ea0(unaff_RBX + 0x88);
  if (*(_Sp_counted_base<(__gnu_cxx::_Lock_policy)2> **)(unaff_RBX + 0x60) !=
      (_Sp_counted_base<(__gnu_cxx::_Lock_policy)2> *)0x0) {
    std::_Sp_counted_base<(__gnu_cxx::_Lock_policy)2>::_M_release
              (*(_Sp_counted_base<(__gnu_cxx::_Lock_policy)2> **)(unaff_RBX + 0x60));
  }
  QWidget::~QWidget(unaff_RBX);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c99d8 name=FUN_004c99d8 size=24 ====

void FUN_004c99d8(void)

{
  FUN_005249f0();
  FUN_005249f0();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c99f0 name=FUN_004c99f0 size=21 ====

void FUN_004c99f0(void)

{
  void *unaff_RBX;
  
  operator_delete(unaff_RBX,0x30);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c9a05 name=FUN_004c9a05 size=35 ====

void FUN_004c9a05(void)

{
  QIcon *unaff_RBX;
  
  QIcon::~QIcon(unaff_RBX);
  FUN_005249f0();
  FUN_005249f0();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c9a28 name=FUN_004c9a28 size=16 ====

void FUN_004c9a28(void)

{
  FUN_005249f0();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c9a38 name=FUN_004c9a38 size=16 ====

void FUN_004c9a38(void)

{
  QCursor *unaff_RBX;
  
  QCursor::~QCursor(unaff_RBX);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c9a48 name=FUN_004c9a48 size=94 ====

void FUN_004c9a48(void)

{
  int *piVar1;
  QLineEdit *unaff_RBX;
  void *unaff_RBP;
  
  operator_delete(unaff_RBP,0x20);
  *(undefined ***)unaff_RBX = &PTR_FUN_01198458;
  *(undefined ***)(unaff_RBX + 0x10) = &PTR_FUN_01198608;
  FUN_00544670(unaff_RBX + 0x50);
  piVar1 = *(int **)(unaff_RBX + 0x30);
  if (piVar1 != (int *)0x0) {
    LOCK();
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if ((*piVar1 == 0) && (*(void **)(unaff_RBX + 0x30) != (void *)0x0)) {
      operator_delete(*(void **)(unaff_RBX + 0x30));
    }
  }
  QLineEdit::~QLineEdit(unaff_RBX);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c9aa6 name=FUN_004c9aa6 size=13 ====

void FUN_004c9aa6(void)

{
  int *piVar1;
  QLineEdit *unaff_RBX;
  
  FUN_005249f0();
  *(undefined ***)unaff_RBX = &PTR_FUN_01198458;
  *(undefined ***)(unaff_RBX + 0x10) = &PTR_FUN_01198608;
  FUN_00544670(unaff_RBX + 0x50);
  piVar1 = *(int **)(unaff_RBX + 0x30);
  if (piVar1 != (int *)0x0) {
    LOCK();
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if ((*piVar1 == 0) && (*(void **)(unaff_RBX + 0x30) != (void *)0x0)) {
      operator_delete(*(void **)(unaff_RBX + 0x30));
    }
  }
  QLineEdit::~QLineEdit(unaff_RBX);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c9ac0 name=FUN_004c9ac0 size=24 ====

void FUN_004c9ac0(void)

{
  QStyledItemDelegate *unaff_RBX;
  QTextOption *unaff_R12;
  
  QTextOption::~QTextOption(unaff_R12);
  QStyledItemDelegate::~QStyledItemDelegate(unaff_RBX);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c9ad8 name=FUN_004c9ad8 size=15 ====

void FUN_004c9ad8(void)

{
  QStyledItemDelegate *unaff_RBX;
  void *unaff_R12;
  
  operator_delete(unaff_R12,0x10);
  QStyledItemDelegate::~QStyledItemDelegate(unaff_RBX);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c9ae8 name=FUN_004c9ae8 size=32 ====

void FUN_004c9ae8(void)

{
  FUN_005249f0();
  FUN_005249f0();
  FUN_00558a5a();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c9b08 name=FUN_004c9b08 size=70 ====

void FUN_004c9b08(void)

{
  QStyleOption *unaff_RBX;
  
  QBrush::~QBrush((QBrush *)(unaff_RBX + 0xb8));
  FUN_005249f0(unaff_RBX + 0xa8);
  QIcon::~QIcon((QIcon *)(unaff_RBX + 0xa0));
  QLocale::~QLocale((QLocale *)(unaff_RBX + 0x70));
  QFont::~QFont((QFont *)(unaff_RBX + 0x58));
  QStyleOption::~QStyleOption(unaff_RBX);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c9b4e name=FUN_004c9b4e size=44 ====

void FUN_004c9b4e(void)

{
  undefined8 in_stack_00000018;
  
  FUN_005249f0();
  FUN_005249f0();
  FUN_005249f0();
  FUN_005249f0(in_stack_00000018);
  FUN_005249f0(&stack0x00000028);
  FUN_00558a5a();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c9b7a name=FUN_004c9b7a size=13 ====

void FUN_004c9b7a(void)

{
  FUN_005249f0();
  FUN_005249f0();
  FUN_00558a5a();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c9b88 name=FUN_004c9b88 size=64 ====

void FUN_004c9b88(void)

{
  long unaff_R12;
  QIcon *in_stack_00000008;
  undefined8 in_stack_00000010;
  
  FUN_005249f0(in_stack_00000010);
  FUN_00580040(unaff_R12 + 0x38);
  QPalette::~QPalette((QPalette *)(unaff_R12 + 8));
  QIcon::~QIcon(in_stack_00000008);
  FUN_005249f0();
  FUN_00558a5a();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c9bc8 name=FUN_004c9bc8 size=20 ====

void FUN_004c9bc8(void)

{
  long unaff_R12;
  QBrush *unaff_R15;
  QIcon *in_stack_00000008;
  undefined8 in_stack_00000010;
  
  QBrush::~QBrush(unaff_R15);
  FUN_005249f0(in_stack_00000010);
  FUN_00580040(unaff_R12 + 0x38);
  QPalette::~QPalette((QPalette *)(unaff_R12 + 8));
  QIcon::~QIcon(in_stack_00000008);
  FUN_005249f0();
  FUN_00558a5a();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c9bdc name=FUN_004c9bdc size=12 ====

void FUN_004c9bdc(void)

{
  long unaff_R12;
  QIcon *in_stack_00000008;
  undefined8 in_stack_00000010;
  
  FUN_005249f0(in_stack_00000010);
  FUN_00580040(unaff_R12 + 0x38);
  QPalette::~QPalette((QPalette *)(unaff_R12 + 8));
  QIcon::~QIcon(in_stack_00000008);
  FUN_005249f0();
  FUN_00558a5a();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c9be8 name=FUN_004c9be8 size=70 ====

void FUN_004c9be8(void)

{
  QStyleOption *unaff_RBX;
  
  QBrush::~QBrush((QBrush *)(unaff_RBX + 0xb8));
  FUN_005249f0(unaff_RBX + 0xa8);
  QIcon::~QIcon((QIcon *)(unaff_RBX + 0xa0));
  QLocale::~QLocale((QLocale *)(unaff_RBX + 0x70));
  QFont::~QFont((QFont *)(unaff_RBX + 0x58));
  QStyleOption::~QStyleOption(unaff_RBX);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c9c2e name=FUN_004c9c2e size=23 ====

void FUN_004c9c2e(void)

{
  long unaff_R12;
  QIcon *in_stack_00000008;
  
  FUN_005249f0(&stack0x00000090);
  FUN_00580040(unaff_R12 + 0x38);
  QPalette::~QPalette((QPalette *)(unaff_R12 + 8));
  QIcon::~QIcon(in_stack_00000008);
  FUN_005249f0(&stack0x00000030);
  FUN_00558a5a();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c9c45 name=FUN_004c9c45 size=10 ====

void FUN_004c9c45(void)

{
  long unaff_R12;
  QIcon *in_stack_00000008;
  undefined8 in_stack_00000010;
  
  FUN_005249f0();
  FUN_005249f0(in_stack_00000010);
  FUN_00580040(unaff_R12 + 0x38);
  QPalette::~QPalette((QPalette *)(unaff_R12 + 8));
  QIcon::~QIcon(in_stack_00000008);
  FUN_005249f0();
  FUN_00558a5a();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c9c4f name=FUN_004c9c4f size=13 ====

void FUN_004c9c4f(void)

{
  long unaff_R12;
  QIcon *in_stack_00000008;
  undefined8 in_stack_00000010;
  
  FUN_005249f0();
  FUN_005249f0(in_stack_00000010);
  FUN_00580040(unaff_R12 + 0x38);
  QPalette::~QPalette((QPalette *)(unaff_R12 + 8));
  QIcon::~QIcon(in_stack_00000008);
  FUN_005249f0();
  FUN_00558a5a();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c9c5c name=FUN_004c9c5c size=20 ====

void FUN_004c9c5c(void)

{
  long unaff_R12;
  QIcon *in_stack_00000008;
  QBrush *in_stack_00000010;
  
  QBrush::~QBrush(in_stack_00000010);
  FUN_00580040(unaff_R12 + 0x38);
  QPalette::~QPalette((QPalette *)(unaff_R12 + 8));
  QIcon::~QIcon(in_stack_00000008);
  FUN_005249f0(&stack0x00000030);
  FUN_00558a5a();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c9c70 name=FUN_004c9c70 size=16 ====

void FUN_004c9c70(void)

{
  FUN_005249f0();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c9c80 name=FUN_004c9c80 size=24 ====

void FUN_004c9c80(void)

{
  QFontMetrics *unaff_RBP;
  
  QFontMetrics::~QFontMetrics(unaff_RBP);
  FUN_005249f0();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c9ca0 name=FUN_004c9ca0 size=29 ====

void FUN_004c9ca0(void)

{
  void *unaff_R14;
  
  operator_delete(unaff_R14,0x48);
  FUN_005249f0();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c9cbd name=FUN_004c9cbd size=29 ====

void FUN_004c9cbd(void)

{
  void *unaff_R14;
  
  operator_delete(unaff_R14,0x48);
  FUN_005249f0();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c9cda name=FUN_004c9cda size=34 ====

void FUN_004c9cda(void)

{
  void *unaff_R14;
  
  operator_delete(unaff_R14,0x48);
  FUN_005249f0(&stack0x00000008);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c9cfc name=FUN_004c9cfc size=29 ====

void FUN_004c9cfc(void)

{
  void *unaff_R14;
  
  operator_delete(unaff_R14,0x48);
  FUN_005249f0();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c9d19 name=FUN_004c9d19 size=29 ====

void FUN_004c9d19(void)

{
  void *unaff_R14;
  
  operator_delete(unaff_R14,0x48);
  FUN_005249f0();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c9d36 name=FUN_004c9d36 size=16 ====

void FUN_004c9d36(void)

{
  FUN_005249f0();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c9d46 name=FUN_004c9d46 size=21 ====

void FUN_004c9d46(void)

{
  void *unaff_R12;
  
  operator_delete(unaff_R12,0x20);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c9d5b name=FUN_004c9d5b size=21 ====

void FUN_004c9d5b(void)

{
  void *unaff_R13;
  
  operator_delete(unaff_R13,0x30);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c9d70 name=FUN_004c9d70 size=16 ====

void FUN_004c9d70(void)

{
  FUN_005249f0();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c9d80 name=FUN_004c9d80 size=29 ====

void FUN_004c9d80(void)

{
  void *unaff_R14;
  
  operator_delete(unaff_R14,0x48);
  FUN_005249f0();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c9d9d name=FUN_004c9d9d size=29 ====

void FUN_004c9d9d(void)

{
  void *unaff_R14;
  
  operator_delete(unaff_R14,0x48);
  FUN_005249f0();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c9dba name=FUN_004c9dba size=34 ====

void FUN_004c9dba(void)

{
  FUN_005249f0();
  FUN_005249f0(&stack0x00000008);
  FUN_005249f0();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c9ddc name=FUN_004c9ddc size=16 ====

void FUN_004c9ddc(void)

{
  QVariant *unaff_R13;
  
  QVariant::~QVariant(unaff_R13);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c9dec name=FUN_004c9dec size=10 ====

void FUN_004c9dec(void)

{
  FUN_005249f0();
  FUN_005249f0(&stack0x00000008);
  FUN_005249f0();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c9df6 name=FUN_004c9df6 size=12 ====

void FUN_004c9df6(void)

{
  QVariant *unaff_R13;
  
  QVariant::~QVariant(unaff_R13);
  FUN_005249f0();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c9e02 name=FUN_004c9e02 size=21 ====

void FUN_004c9e02(void)

{
  void *unaff_R12;
  
  operator_delete(unaff_R12,0x20);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c9e18 name=FUN_004c9e18 size=16 ====

void FUN_004c9e18(void)

{
  FUN_005820a0();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c9e28 name=FUN_004c9e28 size=69 ====

void FUN_004c9e28(void)

{
  QVariant *in_stack_00000010;
  
  QVariant::~QVariant(in_stack_00000010);
  FUN_005249f0(&stack0x00000040);
  FUN_005249f0(&stack0x00000038);
  QIcon::~QIcon((QIcon *)&stack0x00000030);
  FUN_005249f0(&stack0x00000028);
  FUN_00558a5a();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c9e6d name=FUN_004c9e6d size=15 ====

void FUN_004c9e6d(void)

{
  QVariant *unaff_R13;
  
  QVariant::~QVariant(unaff_R13);
  QIcon::~QIcon((QIcon *)&stack0x00000030);
  FUN_005249f0(&stack0x00000028);
  FUN_00558a5a();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c9e7c name=FUN_004c9e7c size=70 ====

void FUN_004c9e7c(void)

{
  QStyleOption *unaff_RBX;
  
  QBrush::~QBrush((QBrush *)(unaff_RBX + 0xb8));
  FUN_005249f0(unaff_RBX + 0xa8);
  QIcon::~QIcon((QIcon *)(unaff_RBX + 0xa0));
  QLocale::~QLocale((QLocale *)(unaff_RBX + 0x70));
  QFont::~QFont((QFont *)(unaff_RBX + 0x58));
  QStyleOption::~QStyleOption(unaff_RBX);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c9ec2 name=FUN_004c9ec2 size=23 ====

void FUN_004c9ec2(void)

{
  QIcon *unaff_R14;
  undefined8 in_stack_00000010;
  
  FUN_00582180();
  FUN_005249f0(in_stack_00000010);
  FUN_005249f0(&stack0x00000040);
  FUN_005249f0(&stack0x00000038);
  QIcon::~QIcon(unaff_R14);
  FUN_005249f0(&stack0x00000028);
  FUN_00558a5a();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c9ed9 name=FUN_004c9ed9 size=18 ====

void FUN_004c9ed9(void)

{
  FUN_005249f0();
  FUN_005249f0(&stack0x00000040);
  FUN_005249f0(&stack0x00000038);
  QIcon::~QIcon((QIcon *)&stack0x00000030);
  FUN_005249f0(&stack0x00000028);
  FUN_00558a5a();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c9eeb name=FUN_004c9eeb size=15 ====

void FUN_004c9eeb(void)

{
  QIcon *unaff_R14;
  QRegion *in_stack_00000010;
  
  QRegion::~QRegion(in_stack_00000010);
  FUN_005249f0(&stack0x00000040);
  FUN_005249f0(&stack0x00000038);
  QIcon::~QIcon(unaff_R14);
  FUN_005249f0(&stack0x00000028);
  FUN_00558a5a();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c9efa name=FUN_004c9efa size=13 ====

void FUN_004c9efa(void)

{
  QIcon *unaff_R14;
  
  FUN_00582180();
  FUN_005249f0(&stack0x00000040);
  FUN_005249f0(&stack0x00000038);
  QIcon::~QIcon(unaff_R14);
  FUN_005249f0(&stack0x00000028);
  FUN_00558a5a();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c9f07 name=FUN_004c9f07 size=18 ====

void FUN_004c9f07(void)

{
  QVariant *unaff_R13;
  
  QVariant::~QVariant(unaff_R13);
  FUN_005249f0(&stack0x00000040);
  FUN_005249f0(&stack0x00000038);
  QIcon::~QIcon((QIcon *)&stack0x00000030);
  FUN_005249f0(&stack0x00000028);
  FUN_00558a5a();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c9f19 name=FUN_004c9f19 size=18 ====

void FUN_004c9f19(void)

{
  QVariant *unaff_R13;
  
  QVariant::~QVariant(unaff_R13);
  FUN_005249f0(&stack0x00000038);
  QIcon::~QIcon((QIcon *)&stack0x00000030);
  FUN_005249f0(&stack0x00000028);
  FUN_00558a5a();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c9f2b name=FUN_004c9f2b size=13 ====

void FUN_004c9f2b(void)

{
  QIcon *unaff_R14;
  
  FUN_005249f0();
  FUN_005249f0(&stack0x00000040);
  FUN_005249f0(&stack0x00000038);
  QIcon::~QIcon(unaff_R14);
  FUN_005249f0(&stack0x00000028);
  FUN_00558a5a();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c9f38 name=FUN_004c9f38 size=13 ====

void FUN_004c9f38(void)

{
  QPixmap *unaff_R13;
  QIcon *unaff_R14;
  
  QPixmap::~QPixmap(unaff_R13);
  FUN_005249f0(&stack0x00000040);
  FUN_005249f0(&stack0x00000038);
  QIcon::~QIcon(unaff_R14);
  FUN_005249f0(&stack0x00000028);
  FUN_00558a5a();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c9f45 name=FUN_004c9f45 size=18 ====

void FUN_004c9f45(void)

{
  QVariant *unaff_R13;
  
  QVariant::~QVariant(unaff_R13);
  QIcon::~QIcon((QIcon *)&stack0x00000030);
  FUN_005249f0(&stack0x00000028);
  FUN_00558a5a();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c9f57 name=FUN_004c9f57 size=15 ====

void FUN_004c9f57(void)

{
  QIcon *unaff_R14;
  QPixmap *in_stack_00000010;
  
  QPixmap::~QPixmap(in_stack_00000010);
  FUN_005249f0(&stack0x00000040);
  FUN_005249f0(&stack0x00000038);
  QIcon::~QIcon(unaff_R14);
  FUN_005249f0(&stack0x00000028);
  FUN_00558a5a();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c9f66 name=FUN_004c9f66 size=26 ====

void FUN_004c9f66(void)

{
  QVariant *unaff_R13;
  
  QVariant::~QVariant(unaff_R13);
  FUN_005249f0();
  FUN_005249f0(&stack0x00000040);
  FUN_005249f0(&stack0x00000038);
  QIcon::~QIcon((QIcon *)&stack0x00000030);
  FUN_005249f0(&stack0x00000028);
  FUN_00558a5a();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c9f80 name=FUN_004c9f80 size=32 ====

void FUN_004c9f80(void)

{
  QListView *unaff_RBX;
  void *unaff_RBP;
  
  operator_delete(unaff_RBP,0x28);
  QListView::~QListView(unaff_RBX);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c9fa0 name=FUN_004c9fa0 size=74 ====

void FUN_004c9fa0(void)

{
  undefined8 in_stack_00000018;
  undefined8 in_stack_00000028;
  QFontMetrics *in_stack_00000030;
  undefined8 in_stack_00000048;
  QFont *in_stack_00000058;
  
  FUN_005249f0();
  FUN_005249f0();
  FUN_005249f0(in_stack_00000028);
  FUN_005249f0(in_stack_00000018);
  QFontMetrics::~QFontMetrics(in_stack_00000030);
  QFont::~QFont(in_stack_00000058);
  FUN_00558a5a(in_stack_00000048);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004c9fea name=FUN_004c9fea size=12 ====

void FUN_004c9fea(void)

{
  undefined8 in_stack_00000018;
  QFontMetrics *in_stack_00000030;
  undefined8 in_stack_00000048;
  QFont *in_stack_00000058;
  
  FUN_005249f0(in_stack_00000018);
  QFontMetrics::~QFontMetrics(in_stack_00000030);
  QFont::~QFont(in_stack_00000058);
  FUN_00558a5a(in_stack_00000048);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004ca000 name=FUN_004ca000 size=48 ====

/* WARNING: Removing unreachable block (ram,0x004ca01d) */

void FUN_004ca000(undefined8 *param_1)

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


// ==== entry=004ca030 name=FUN_004ca030 size=30 ====

void FUN_004ca030(void)

{
  long in_stack_00000008;
  
  FUN_004ca000(in_stack_00000008 + -0x18);
  FUN_005249f0();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004ca04e name=FUN_004ca04e size=10 ====

void FUN_004ca04e(void)

{
  FUN_005249c0();
  FUN_005249f0();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004ca058 name=FUN_004ca058 size=21 ====

void FUN_004ca058(void)

{
  FUN_005249f0();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004ca06e name=FUN_004ca06e size=32 ====

void FUN_004ca06e(void)

{
  FUN_005249c0();
  FUN_005249f0();
  FUN_005249f0();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004ca08e name=FUN_004ca08e size=21 ====

void FUN_004ca08e(void)

{
  void *unaff_RBP;
  
  operator_delete(unaff_RBP,0x20);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004ca0a3 name=FUN_004ca0a3 size=16 ====

void FUN_004ca0a3(void)

{
  long in_stack_00000040;
  
  FUN_004ca000(in_stack_00000040 + -0x18);
  FUN_005249f0();
  FUN_005249f0();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004ca0b4 name=FUN_004ca0b4 size=16 ====

void FUN_004ca0b4(void)

{
  FUN_005249f0();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004ca0c4 name=FUN_004ca0c4 size=38 ====

void FUN_004ca0c4(void)

{
  QListView *unaff_RBX;
  void *unaff_RBP;
  
  operator_delete(unaff_RBP,0x50);
  FUN_005249f0(unaff_RBX + 0x40);
  QListView::~QListView(unaff_RBX);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004ca0ea name=FUN_004ca0ea size=15 ====

void FUN_004ca0ea(void)

{
  QListView *unaff_RBX;
  void *unaff_RBP;
  
  operator_delete(unaff_RBP,0x98);
  FUN_005249f0(unaff_RBX + 0x40);
  QListView::~QListView(unaff_RBX);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004ca0f9 name=FUN_004ca0f9 size=15 ====

void FUN_004ca0f9(void)

{
  QListView *unaff_RBX;
  void *unaff_RBP;
  
  operator_delete(unaff_RBP,0xb0);
  FUN_005249f0(unaff_RBX + 0x40);
  QListView::~QListView(unaff_RBX);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004ca108 name=FUN_004ca108 size=32 ====

void FUN_004ca108(void)

{
  FUN_005249c0();
  FUN_005249f0();
  FUN_005249f0();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004ca128 name=FUN_004ca128 size=16 ====

void FUN_004ca128(void)

{
  long in_stack_00000020;
  
  FUN_004ca000(in_stack_00000020 + -0x18);
  FUN_005249f0();
  FUN_005249f0();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004ca138 name=FUN_004ca138 size=10 ====

void FUN_004ca138(void)

{
  QRegularExpressionMatch *unaff_RBP;
  
  QRegularExpressionMatch::~QRegularExpressionMatch(unaff_RBP);
  FUN_005249f0();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004ca142 name=FUN_004ca142 size=16 ====

void FUN_004ca142(void)

{
  QScrollBar *unaff_RBX;
  
  QScrollBar::~QScrollBar(unaff_RBX);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004ca152 name=FUN_004ca152 size=20 ====

void FUN_004ca152(void)

{
  bool unaff_BPL;
  
  QObject::blockSignals(unaff_BPL);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004ca166 name=FUN_004ca166 size=21 ====

void FUN_004ca166(void)

{
  void *unaff_RBX;
  
  operator_delete(unaff_RBX,0x40);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004ca17c name=FUN_004ca17c size=41 ====

void FUN_004ca17c(void)

{
  QFrame *unaff_RBX;
  
  *(undefined ***)unaff_RBX = &PTR_FUN_01193238;
  *(undefined ***)(unaff_RBX + 0x10) = &PTR_FUN_011933e8;
  QFrame::~QFrame(unaff_RBX);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004ca1b0 name=FUN_004ca1b0 size=72 ====

void FUN_004ca1b0(void)

{
  void *unaff_RBP;
  char in_stack_00000060;
  code *in_stack_00000078;
  code *in_stack_00000080;
  
  operator_delete(unaff_RBP,0x88);
  if (in_stack_00000060 != '\0') {
    if (in_stack_00000078 == (code *)0x0) {
                    /* WARNING: Subroutine does not return */
      std::__throw_bad_function_call();
    }
    (*in_stack_00000080)(&stack0x00000068);
  }
  if (in_stack_00000078 != (code *)0x0) {
    (*in_stack_00000078)(&stack0x00000068,&stack0x00000068,3);
  }
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004ca1d1 name=FUN_004ca1d1 size=81 ====

void FUN_004ca1d1(void)

{
  code *in_stack_00000030;
  code *in_stack_00000050;
  code *in_stack_00000078;
  
  if (in_stack_00000078 != (code *)0x0) {
    (*in_stack_00000078)(&stack0x00000068,&stack0x00000068,3);
  }
  if (in_stack_00000030 != (code *)0x0) {
    (*in_stack_00000030)();
  }
  if (in_stack_00000050 != (code *)0x0) {
    (*in_stack_00000050)(&stack0x00000040,&stack0x00000040,3);
  }
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004ca24a name=FUN_004ca24a size=32 ====

void FUN_004ca24a(void)

{
  QIcon *unaff_RBP;
  
  QIcon::~QIcon(unaff_RBP);
  FUN_005249f0();
  FUN_005249f0();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004ca26a name=FUN_004ca26a size=16 ====

void FUN_004ca26a(void)

{
  FUN_005249f0();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004ca27a name=FUN_004ca27a size=16 ====

void FUN_004ca27a(void)

{
  FUN_005249f0();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004ca28a name=FUN_004ca28a size=21 ====

void FUN_004ca28a(void)

{
  void *unaff_RBP;
  
  operator_delete(unaff_RBP,0x30);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004ca29f name=FUN_004ca29f size=21 ====

void FUN_004ca29f(void)

{
  void *unaff_RBP;
  
  operator_delete(unaff_RBP,0x30);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004ca2b4 name=FUN_004ca2b4 size=21 ====

void FUN_004ca2b4(void)

{
  void *unaff_R12;
  
  operator_delete(unaff_R12,0x20);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004ca2c9 name=FUN_004ca2c9 size=16 ====

void FUN_004ca2c9(void)

{
  FUN_005249f0();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004ca2d9 name=FUN_004ca2d9 size=16 ====

void FUN_004ca2d9(void)

{
  FUN_005249f0();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004ca2ea name=FUN_004ca2ea size=44 ====

void FUN_004ca2ea(void)

{
  QWidget *unaff_RBX;
  
  FUN_005249f0();
  FUN_005249f0();
  FUN_005249f0(unaff_RBX + 0x50);
  QWidget::~QWidget(unaff_RBX);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004ca316 name=FUN_004ca316 size=10 ====

void FUN_004ca316(void)

{
  QWidget *unaff_RBX;
  
  FUN_005249f0();
  FUN_005249f0(unaff_RBX + 0x50);
  QWidget::~QWidget(unaff_RBX);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004ca320 name=FUN_004ca320 size=16 ====

void FUN_004ca320(void)

{
  QEasingCurve *unaff_RBX;
  
  QEasingCurve::~QEasingCurve(unaff_RBX);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004ca330 name=FUN_004ca330 size=63 ====

void FUN_004ca330(void)

{
  void *unaff_RBP;
  QArrayData *unaff_retaddr;
  
  operator_delete(unaff_RBP,0x10);
  if (*(int *)unaff_retaddr != 0) {
    if (*(int *)unaff_retaddr == -1) goto LAB_004ca356;
    LOCK();
    *(int *)unaff_retaddr = *(int *)unaff_retaddr + -1;
    UNLOCK();
    if (*(int *)unaff_retaddr != 0) goto LAB_004ca356;
  }
  QArrayData::deallocate(unaff_retaddr,1,8);
LAB_004ca356:
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004ca35e name=FUN_004ca35e size=16 ====

void FUN_004ca35e(void)

{
  QVariant *unaff_RBX;
  
  QVariant::~QVariant(unaff_RBX);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004ca36e name=FUN_004ca36e size=16 ====

void FUN_004ca36e(void)

{
  QVariant *unaff_RBX;
  
  QVariant::~QVariant(unaff_RBX);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004ca38f name=FUN_004ca38f size=24 ====

void FUN_004ca38f(void)

{
  FUN_00585f80();
  FUN_005249f0();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004ca3a7 name=FUN_004ca3a7 size=16 ====

void FUN_004ca3a7(void)

{
  FUN_00585f80();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004ca3b8 name=FUN_004ca3b8 size=24 ====

void FUN_004ca3b8(void)

{
  FUN_00585f80();
  FUN_005249f0();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004ca3d0 name=FUN_004ca3d0 size=16 ====

void FUN_004ca3d0(void)

{
  FUN_00585f80();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004ca3e0 name=FUN_004ca3e0 size=24 ====

void FUN_004ca3e0(void)

{
  QKeySequence *unaff_RBP;
  
  FUN_005249f0();
  QKeySequence::~QKeySequence(unaff_RBP);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004ca3f8 name=FUN_004ca3f8 size=21 ====

void FUN_004ca3f8(void)

{
  void *unaff_RBP;
  
  operator_delete(unaff_RBP,0x48);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004ca40d name=FUN_004ca40d size=21 ====

void FUN_004ca40d(void)

{
  void *unaff_RBP;
  
  operator_delete(unaff_RBP,0x30);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004ca422 name=FUN_004ca422 size=24 ====

void FUN_004ca422(void)

{
  QKeySequence *unaff_RBP;
  
  FUN_005249f0();
  QKeySequence::~QKeySequence(unaff_RBP);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004ca43a name=FUN_004ca43a size=16 ====

void FUN_004ca43a(void)

{
  FUN_005249f0();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004ca44a name=FUN_004ca44a size=21 ====

void FUN_004ca44a(void)

{
  void *unaff_RBP;
  
  operator_delete(unaff_RBP,0x48);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004ca45f name=FUN_004ca45f size=16 ====

void FUN_004ca45f(void)

{
  FUN_005249f0();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004ca46f name=FUN_004ca46f size=21 ====

void FUN_004ca46f(void)

{
  void *unaff_RBP;
  
  operator_delete(unaff_RBP,0x48);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004ca484 name=FUN_004ca484 size=24 ====

void FUN_004ca484(void)

{
  QKeySequence *unaff_RBP;
  
  FUN_005249f0();
  QKeySequence::~QKeySequence(unaff_RBP);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004ca49c name=FUN_004ca49c size=21 ====

void FUN_004ca49c(void)

{
  void *unaff_R12;
  
  operator_delete(unaff_R12,0x30);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004ca4b1 name=FUN_004ca4b1 size=21 ====

void FUN_004ca4b1(void)

{
  void *unaff_RBP;
  
  operator_delete(unaff_RBP,0x20);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004ca4c6 name=FUN_004ca4c6 size=21 ====

void FUN_004ca4c6(void)

{
  void *unaff_R13;
  
  operator_delete(unaff_R13,0x20);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004ca4db name=FUN_004ca4db size=16 ====

void FUN_004ca4db(void)

{
  FUN_005249f0();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004ca4eb name=FUN_004ca4eb size=16 ====

void FUN_004ca4eb(void)

{
  FUN_005249f0();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004ca4fb name=FUN_004ca4fb size=24 ====

void FUN_004ca4fb(void)

{
  QKeySequence *unaff_RBP;
  
  FUN_005249f0();
  QKeySequence::~QKeySequence(unaff_RBP);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004ca514 name=FUN_004ca514 size=44 ====

void FUN_004ca514(void)

{
  QFrame *unaff_RBX;
  QBrush *unaff_RBP;
  QBrush *unaff_R12;
  
  QBrush::~QBrush(unaff_R12);
  QBrush::~QBrush(unaff_RBP);
  FUN_005249f0(unaff_RBX + 0x30);
  QFrame::~QFrame(unaff_RBX);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004ca540 name=FUN_004ca540 size=34 ====

void FUN_004ca540(void)

{
  QPainter *unaff_RBX;
  QPixmap *unaff_R13;
  QPixmap *in_stack_00000018;
  
  QPixmap::~QPixmap(in_stack_00000018);
  QPainter::~QPainter(unaff_RBX);
  QPixmap::~QPixmap(unaff_R13);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004ca562 name=FUN_004ca562 size=10 ====

void FUN_004ca562(void)

{
  QPainter *unaff_RBX;
  QPixmap *unaff_R13;
  QBrush *unaff_R14;
  
  QBrush::~QBrush(unaff_R14);
  QPainter::~QPainter(unaff_RBX);
  QPixmap::~QPixmap(unaff_R13);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004ca56c name=FUN_004ca56c size=16 ====

void FUN_004ca56c(void)

{
  QVariant *unaff_RBX;
  
  QVariant::~QVariant(unaff_RBX);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004ca57c name=FUN_004ca57c size=24 ====

void FUN_004ca57c(void)

{
  QPixmap *unaff_RBX;
  
  QPixmap::~QPixmap(unaff_RBX);
  FUN_005249f0();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004ca594 name=FUN_004ca594 size=10 ====

void FUN_004ca594(void)

{
  QVariant *unaff_RBX;
  
  QVariant::~QVariant(unaff_RBX);
  FUN_005249f0();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004ca59e name=FUN_004ca59e size=117 ====

void FUN_004ca59e(void)

{
  undefined8 unaff_retaddr;
  undefined8 in_stack_00000008;
  QIcon *in_stack_00000018;
  undefined8 in_stack_00000038;
  undefined8 in_stack_00000040;
  undefined8 in_stack_00000050;
  undefined8 in_stack_00000058;
  
  FUN_005249f0();
  FUN_005249f0(in_stack_00000040);
  FUN_005249f0(unaff_retaddr);
  FUN_005249f0(&stack0x00000090);
  FUN_005249f0(&stack0x00000088);
  FUN_005249f0(in_stack_00000050);
  FUN_005249f0(in_stack_00000058);
  FUN_005249f0(in_stack_00000008);
  FUN_00528c1c(in_stack_00000038);
  QIcon::~QIcon(in_stack_00000018);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004ca613 name=FUN_004ca613 size=72 ====

void FUN_004ca613(void)

{
  undefined8 in_RAX;
  undefined8 unaff_retaddr;
  undefined8 in_stack_00000008;
  undefined8 uStack0000000000000010;
  QIcon *in_stack_00000018;
  undefined8 in_stack_00000038;
  undefined8 in_stack_00000040;
  undefined8 in_stack_00000048;
  undefined8 in_stack_00000050;
  undefined8 in_stack_00000058;
  
  uStack0000000000000010 = in_RAX;
  FUN_005249f0();
  FUN_005249f0();
  FUN_005249f0();
  FUN_005249f0(in_stack_00000048);
  FUN_005249f0(in_stack_00000040);
  FUN_005249f0(unaff_retaddr);
  FUN_005249f0();
  FUN_005249f0(&stack0x00000088);
  FUN_005249f0(in_stack_00000050);
  FUN_005249f0(in_stack_00000058);
  FUN_005249f0(in_stack_00000008);
  FUN_00528c1c(in_stack_00000038);
  QIcon::~QIcon(in_stack_00000018);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70(uStack0000000000000010);
}


// ==== entry=004ca65b name=FUN_004ca65b size=37 ====

void FUN_004ca65b(void)

{
  QVariant *unaff_RBX;
  QVariant *unaff_RBP;
  undefined8 unaff_retaddr;
  undefined8 in_stack_00000008;
  QIcon *in_stack_00000018;
  undefined8 in_stack_00000038;
  undefined8 in_stack_00000040;
  undefined8 in_stack_00000048;
  undefined8 in_stack_00000050;
  undefined8 in_stack_00000058;
  
  QVariant::~QVariant(unaff_RBX);
  FUN_005249f0();
  QVariant::~QVariant(unaff_RBP);
  FUN_005249f0(in_stack_00000048);
  FUN_005249f0(in_stack_00000040);
  FUN_005249f0(unaff_retaddr);
  FUN_005249f0(&stack0x00000090);
  FUN_005249f0(&stack0x00000088);
  FUN_005249f0(in_stack_00000050);
  FUN_005249f0(in_stack_00000058);
  FUN_005249f0(in_stack_00000008);
  FUN_00528c1c(in_stack_00000038);
  QIcon::~QIcon(in_stack_00000018);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004ca680 name=FUN_004ca680 size=32 ====

void FUN_004ca680(void)

{
  QVariant *unaff_RBX;
  QVariant *unaff_RBP;
  QIcon *in_stack_00000018;
  undefined8 in_stack_00000038;
  
  QVariant::~QVariant(unaff_RBX);
  FUN_005249f0();
  QVariant::~QVariant(unaff_RBP);
  FUN_00528c1c(in_stack_00000038);
  QIcon::~QIcon(in_stack_00000018);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004ca6a0 name=FUN_004ca6a0 size=40 ====

void FUN_004ca6a0(void)

{
  QVariant *unaff_RBX;
  QVariant *unaff_RBP;
  undefined8 in_stack_00000008;
  QIcon *in_stack_00000018;
  undefined8 in_stack_00000038;
  undefined8 in_stack_00000050;
  undefined8 in_stack_00000058;
  
  QVariant::~QVariant(unaff_RBX);
  FUN_005249f0();
  QVariant::~QVariant(unaff_RBP);
  FUN_005249f0(&stack0x00000090);
  FUN_005249f0(&stack0x00000088);
  FUN_005249f0(in_stack_00000050);
  FUN_005249f0(in_stack_00000058);
  FUN_005249f0(in_stack_00000008);
  FUN_00528c1c(in_stack_00000038);
  QIcon::~QIcon(in_stack_00000018);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004ca6c8 name=FUN_004ca6c8 size=40 ====

void FUN_004ca6c8(void)

{
  QVariant *unaff_RBX;
  QVariant *unaff_RBP;
  undefined8 unaff_retaddr;
  undefined8 in_stack_00000008;
  QIcon *in_stack_00000018;
  undefined8 in_stack_00000038;
  undefined8 in_stack_00000040;
  undefined8 in_stack_00000050;
  undefined8 in_stack_00000058;
  
  QVariant::~QVariant(unaff_RBX);
  FUN_005249f0();
  QVariant::~QVariant(unaff_RBP);
  FUN_005249f0(in_stack_00000040);
  FUN_005249f0(unaff_retaddr);
  FUN_005249f0(&stack0x00000090);
  FUN_005249f0(&stack0x00000088);
  FUN_005249f0(in_stack_00000050);
  FUN_005249f0(in_stack_00000058);
  FUN_005249f0(in_stack_00000008);
  FUN_00528c1c(in_stack_00000038);
  QIcon::~QIcon(in_stack_00000018);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004ca6f0 name=FUN_004ca6f0 size=32 ====

void FUN_004ca6f0(void)

{
  QVariant *unaff_RBX;
  QVariant *unaff_RBP;
  undefined8 in_stack_00000008;
  QIcon *in_stack_00000018;
  undefined8 in_stack_00000038;
  undefined8 in_stack_00000058;
  
  QVariant::~QVariant(unaff_RBX);
  FUN_005249f0();
  QVariant::~QVariant(unaff_RBP);
  FUN_005249f0(in_stack_00000058);
  FUN_005249f0(in_stack_00000008);
  FUN_00528c1c(in_stack_00000038);
  QIcon::~QIcon(in_stack_00000018);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004ca710 name=FUN_004ca710 size=32 ====

void FUN_004ca710(void)

{
  QVariant *unaff_RBX;
  QVariant *unaff_RBP;
  undefined8 in_stack_00000008;
  QIcon *in_stack_00000018;
  undefined8 in_stack_00000038;
  
  QVariant::~QVariant(unaff_RBX);
  FUN_005249f0();
  QVariant::~QVariant(unaff_RBP);
  FUN_005249f0(in_stack_00000008);
  FUN_00528c1c(in_stack_00000038);
  QIcon::~QIcon(in_stack_00000018);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004ca730 name=FUN_004ca730 size=16 ====

void FUN_004ca730(void)

{
  QVariant *unaff_RBX;
  QIcon *in_stack_00000018;
  
  QVariant::~QVariant(unaff_RBX);
  QIcon::~QIcon(in_stack_00000018);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004ca740 name=FUN_004ca740 size=24 ====

void FUN_004ca740(void)

{
  QVariant *unaff_RBX;
  QVariant *unaff_RBP;
  QIcon *in_stack_00000018;
  undefined8 in_stack_00000038;
  
  QVariant::~QVariant(unaff_RBX);
  FUN_005249f0();
  QVariant::~QVariant(unaff_RBP);
  FUN_00528c1c(in_stack_00000038);
  QIcon::~QIcon(in_stack_00000018);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004ca758 name=FUN_004ca758 size=24 ====

void FUN_004ca758(void)

{
  QVariant *unaff_RBX;
  QVariant *unaff_RBP;
  QIcon *in_stack_00000018;
  undefined8 in_stack_00000038;
  
  QVariant::~QVariant(unaff_RBX);
  FUN_005249f0();
  QVariant::~QVariant(unaff_RBP);
  FUN_00528c1c(in_stack_00000038);
  QIcon::~QIcon(in_stack_00000018);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004ca770 name=FUN_004ca770 size=24 ====

void FUN_004ca770(void)

{
  QVariant *unaff_RBX;
  QVariant *unaff_RBP;
  QIcon *in_stack_00000018;
  undefined8 in_stack_00000038;
  
  QVariant::~QVariant(unaff_RBX);
  FUN_005249f0();
  QVariant::~QVariant(unaff_RBP);
  FUN_00528c1c(in_stack_00000038);
  QIcon::~QIcon(in_stack_00000018);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004ca788 name=FUN_004ca788 size=40 ====

void FUN_004ca788(void)

{
  undefined8 unaff_retaddr;
  undefined8 in_stack_00000008;
  QIcon *in_stack_00000018;
  undefined8 in_stack_00000038;
  undefined8 in_stack_00000040;
  undefined8 in_stack_00000050;
  undefined8 in_stack_00000058;
  
  FUN_005249f0();
  FUN_005249f0();
  FUN_005249f0();
  FUN_005249f0(in_stack_00000040);
  FUN_005249f0(unaff_retaddr);
  FUN_005249f0(&stack0x00000090);
  FUN_005249f0(&stack0x00000088);
  FUN_005249f0(in_stack_00000050);
  FUN_005249f0(in_stack_00000058);
  FUN_005249f0(in_stack_00000008);
  FUN_00528c1c(in_stack_00000038);
  QIcon::~QIcon(in_stack_00000018);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004ca7b0 name=FUN_004ca7b0 size=40 ====

void FUN_004ca7b0(void)

{
  QVariant *unaff_RBX;
  QVariant *unaff_RBP;
  undefined8 unaff_retaddr;
  undefined8 in_stack_00000008;
  QIcon *in_stack_00000018;
  undefined8 in_stack_00000038;
  undefined8 in_stack_00000040;
  undefined8 in_stack_00000050;
  undefined8 in_stack_00000058;
  
  QVariant::~QVariant(unaff_RBX);
  FUN_005249f0();
  QVariant::~QVariant(unaff_RBP);
  FUN_005249f0(in_stack_00000040);
  FUN_005249f0(unaff_retaddr);
  FUN_005249f0(&stack0x00000090);
  FUN_005249f0(&stack0x00000088);
  FUN_005249f0(in_stack_00000050);
  FUN_005249f0(in_stack_00000058);
  FUN_005249f0(in_stack_00000008);
  FUN_00528c1c(in_stack_00000038);
  QIcon::~QIcon(in_stack_00000018);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004ca7d8 name=FUN_004ca7d8 size=21 ====

void FUN_004ca7d8(void)

{
  undefined8 unaff_retaddr;
  undefined8 in_stack_00000008;
  QIcon *in_stack_00000018;
  undefined8 in_stack_00000038;
  undefined8 in_stack_00000040;
  undefined8 in_stack_00000050;
  undefined8 in_stack_00000058;
  
  FUN_005249f0();
  FUN_005249f0(in_stack_00000040);
  FUN_005249f0(unaff_retaddr);
  FUN_005249f0(&stack0x00000090);
  FUN_005249f0(&stack0x00000088);
  FUN_005249f0(in_stack_00000050);
  FUN_005249f0(in_stack_00000058);
  FUN_005249f0(in_stack_00000008);
  FUN_00528c1c(in_stack_00000038);
  QIcon::~QIcon(in_stack_00000018);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004ca7ed name=FUN_004ca7ed size=24 ====

void FUN_004ca7ed(void)

{
  QVariant *unaff_RBX;
  QVariant *unaff_RBP;
  QIcon *in_stack_00000018;
  undefined8 in_stack_00000038;
  
  QVariant::~QVariant(unaff_RBX);
  FUN_005249f0();
  QVariant::~QVariant(unaff_RBP);
  FUN_00528c1c(in_stack_00000038);
  QIcon::~QIcon(in_stack_00000018);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004ca805 name=FUN_004ca805 size=40 ====

void FUN_004ca805(void)

{
  undefined8 unaff_retaddr;
  undefined8 in_stack_00000008;
  QIcon *in_stack_00000018;
  undefined8 in_stack_00000038;
  undefined8 in_stack_00000040;
  undefined8 in_stack_00000050;
  undefined8 in_stack_00000058;
  
  FUN_005249f0();
  FUN_005249f0();
  FUN_005249f0();
  FUN_005249f0(in_stack_00000040);
  FUN_005249f0(unaff_retaddr);
  FUN_005249f0(&stack0x00000090);
  FUN_005249f0(&stack0x00000088);
  FUN_005249f0(in_stack_00000050);
  FUN_005249f0(in_stack_00000058);
  FUN_005249f0(in_stack_00000008);
  FUN_00528c1c(in_stack_00000038);
  QIcon::~QIcon(in_stack_00000018);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004ca82d name=FUN_004ca82d size=24 ====

void FUN_004ca82d(void)

{
  QFontMetrics *unaff_RBX;
  undefined8 unaff_retaddr;
  undefined8 in_stack_00000008;
  QIcon *in_stack_00000018;
  undefined8 in_stack_00000038;
  undefined8 in_stack_00000040;
  undefined8 in_stack_00000050;
  undefined8 in_stack_00000058;
  
  QFontMetrics::~QFontMetrics(unaff_RBX);
  FUN_005249f0(in_stack_00000040);
  FUN_005249f0(unaff_retaddr);
  FUN_005249f0(&stack0x00000090);
  FUN_005249f0(&stack0x00000088);
  FUN_005249f0(in_stack_00000050);
  FUN_005249f0(in_stack_00000058);
  FUN_005249f0(in_stack_00000008);
  FUN_00528c1c(in_stack_00000038);
  QIcon::~QIcon(in_stack_00000018);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004ca845 name=FUN_004ca845 size=24 ====

void FUN_004ca845(void)

{
  QVariant *unaff_RBX;
  QIcon *unaff_RBP;
  
  QIcon::~QIcon(unaff_RBP);
  QVariant::~QVariant(unaff_RBX);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004ca85d name=FUN_004ca85d size=24 ====

void FUN_004ca85d(void)

{
  undefined8 unaff_retaddr;
  undefined8 in_stack_00000008;
  QIcon *in_stack_00000018;
  undefined8 in_stack_00000038;
  undefined8 in_stack_00000040;
  undefined8 in_stack_00000050;
  undefined8 in_stack_00000058;
  
  FUN_005249f0();
  FUN_005249f0(in_stack_00000040);
  FUN_005249f0(unaff_retaddr);
  FUN_005249f0(&stack0x00000090);
  FUN_005249f0(&stack0x00000088);
  FUN_005249f0(in_stack_00000050);
  FUN_005249f0(in_stack_00000058);
  FUN_005249f0(in_stack_00000008);
  FUN_00528c1c(in_stack_00000038);
  QIcon::~QIcon(in_stack_00000018);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004ca875 name=FUN_004ca875 size=24 ====

void FUN_004ca875(void)

{
  undefined8 unaff_retaddr;
  undefined8 in_stack_00000008;
  QIcon *in_stack_00000018;
  undefined8 in_stack_00000038;
  undefined8 in_stack_00000040;
  undefined8 in_stack_00000048;
  undefined8 in_stack_00000050;
  undefined8 in_stack_00000058;
  
  FUN_005249f0();
  FUN_005249f0();
  FUN_005249f0(in_stack_00000048);
  FUN_005249f0(in_stack_00000040);
  FUN_005249f0(unaff_retaddr);
  FUN_005249f0();
  FUN_005249f0(&stack0x00000088);
  FUN_005249f0(in_stack_00000050);
  FUN_005249f0(in_stack_00000058);
  FUN_005249f0(in_stack_00000008);
  FUN_00528c1c(in_stack_00000038);
  QIcon::~QIcon(in_stack_00000018);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004ca88d name=FUN_004ca88d size=40 ====

void FUN_004ca88d(void)

{
  QVariant *unaff_RBX;
  QVariant *unaff_RBP;
  undefined8 unaff_retaddr;
  undefined8 in_stack_00000008;
  QIcon *in_stack_00000018;
  undefined8 in_stack_00000038;
  undefined8 in_stack_00000040;
  undefined8 in_stack_00000048;
  undefined8 in_stack_00000050;
  undefined8 in_stack_00000058;
  
  QVariant::~QVariant(unaff_RBX);
  FUN_005249f0();
  QVariant::~QVariant(unaff_RBP);
  FUN_005249f0(in_stack_00000048);
  FUN_005249f0(in_stack_00000040);
  FUN_005249f0(unaff_retaddr);
  FUN_005249f0(&stack0x00000090);
  FUN_005249f0(&stack0x00000088);
  FUN_005249f0(in_stack_00000050);
  FUN_005249f0(in_stack_00000058);
  FUN_005249f0(in_stack_00000008);
  FUN_00528c1c(in_stack_00000038);
  QIcon::~QIcon(in_stack_00000018);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004ca8b5 name=FUN_004ca8b5 size=32 ====

void FUN_004ca8b5(void)

{
  undefined8 unaff_retaddr;
  undefined8 in_stack_00000008;
  QIcon *in_stack_00000018;
  undefined8 in_stack_00000038;
  undefined8 in_stack_00000040;
  undefined8 in_stack_00000048;
  undefined8 in_stack_00000050;
  undefined8 in_stack_00000058;
  
  FUN_005249f0();
  FUN_005249f0();
  FUN_005249f0();
  FUN_005249f0(in_stack_00000048);
  FUN_005249f0(in_stack_00000040);
  FUN_005249f0(unaff_retaddr);
  FUN_005249f0();
  FUN_005249f0(&stack0x00000088);
  FUN_005249f0(in_stack_00000050);
  FUN_005249f0(in_stack_00000058);
  FUN_005249f0(in_stack_00000008);
  FUN_00528c1c(in_stack_00000038);
  QIcon::~QIcon(in_stack_00000018);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004ca8d5 name=FUN_004ca8d5 size=40 ====

void FUN_004ca8d5(void)

{
  undefined8 unaff_retaddr;
  undefined8 in_stack_00000008;
  QIcon *in_stack_00000018;
  undefined8 in_stack_00000038;
  undefined8 in_stack_00000040;
  undefined8 in_stack_00000050;
  undefined8 in_stack_00000058;
  
  FUN_005249f0();
  FUN_005249f0();
  FUN_005249f0();
  FUN_005249f0(in_stack_00000040);
  FUN_005249f0(unaff_retaddr);
  FUN_005249f0(&stack0x00000090);
  FUN_005249f0(&stack0x00000088);
  FUN_005249f0(in_stack_00000050);
  FUN_005249f0(in_stack_00000058);
  FUN_005249f0(in_stack_00000008);
  FUN_00528c1c(in_stack_00000038);
  QIcon::~QIcon(in_stack_00000018);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004ca8fd name=FUN_004ca8fd size=32 ====

void FUN_004ca8fd(void)

{
  undefined8 unaff_retaddr;
  undefined8 in_stack_00000008;
  QIcon *in_stack_00000018;
  undefined8 in_stack_00000038;
  undefined8 in_stack_00000040;
  undefined8 in_stack_00000050;
  undefined8 in_stack_00000058;
  
  FUN_005249f0();
  FUN_005249f0();
  FUN_005249f0(in_stack_00000040);
  FUN_005249f0(unaff_retaddr);
  FUN_005249f0(&stack0x00000090);
  FUN_005249f0(&stack0x00000088);
  FUN_005249f0(in_stack_00000050);
  FUN_005249f0(in_stack_00000058);
  FUN_005249f0(in_stack_00000008);
  FUN_00528c1c(in_stack_00000038);
  QIcon::~QIcon(in_stack_00000018);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004ca91d name=FUN_004ca91d size=10 ====

void FUN_004ca91d(void)

{
  undefined8 unaff_retaddr;
  undefined8 in_stack_00000008;
  QIcon *in_stack_00000018;
  undefined8 in_stack_00000038;
  undefined8 in_stack_00000040;
  undefined8 in_stack_00000050;
  undefined8 in_stack_00000058;
  
  FUN_005249f0();
  FUN_005249f0();
  FUN_005249f0(in_stack_00000040);
  FUN_005249f0(unaff_retaddr);
  FUN_005249f0(&stack0x00000090);
  FUN_005249f0(&stack0x00000088);
  FUN_005249f0(in_stack_00000050);
  FUN_005249f0(in_stack_00000058);
  FUN_005249f0(in_stack_00000008);
  FUN_00528c1c(in_stack_00000038);
  QIcon::~QIcon(in_stack_00000018);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004ca927 name=FUN_004ca927 size=49 ====

void FUN_004ca927(void)

{
  undefined8 unaff_retaddr;
  undefined8 in_stack_00000008;
  QIcon *in_stack_00000018;
  undefined8 in_stack_00000038;
  undefined8 in_stack_00000040;
  undefined8 in_stack_00000048;
  undefined8 in_stack_00000050;
  undefined8 in_stack_00000058;
  
  FUN_005249f0(&stack0x000000f8);
  FUN_005249f0(in_stack_00000048);
  FUN_005249f0(&stack0x000000e8);
  FUN_005249f0(in_stack_00000040);
  FUN_005249f0(unaff_retaddr);
  FUN_005249f0(&stack0x00000090);
  FUN_005249f0(&stack0x00000088);
  FUN_005249f0(in_stack_00000050);
  FUN_005249f0(in_stack_00000058);
  FUN_005249f0(in_stack_00000008);
  FUN_00528c1c(in_stack_00000038);
  QIcon::~QIcon(in_stack_00000018);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004ca958 name=FUN_004ca958 size=24 ====

void FUN_004ca958(void)

{
  undefined8 unaff_retaddr;
  undefined8 in_stack_00000008;
  QIcon *in_stack_00000018;
  undefined8 in_stack_00000038;
  undefined8 in_stack_00000040;
  undefined8 in_stack_00000048;
  undefined8 in_stack_00000050;
  undefined8 in_stack_00000058;
  
  FUN_005249f0();
  FUN_005249f0();
  FUN_005249f0(in_stack_00000048);
  FUN_005249f0(in_stack_00000040);
  FUN_005249f0(unaff_retaddr);
  FUN_005249f0();
  FUN_005249f0(&stack0x00000088);
  FUN_005249f0(in_stack_00000050);
  FUN_005249f0(in_stack_00000058);
  FUN_005249f0(in_stack_00000008);
  FUN_00528c1c(in_stack_00000038);
  QIcon::~QIcon(in_stack_00000018);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004ca970 name=FUN_004ca970 size=21 ====

void FUN_004ca970(void)

{
  void *unaff_RBP;
  
  operator_delete(unaff_RBP,0x20);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004ca985 name=FUN_004ca985 size=34 ====

void FUN_004ca985(void)

{
  void *unaff_RBP;
  
  operator_delete(unaff_RBP,0x48);
  FUN_005249f0(&stack0x00000008);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004ca9a7 name=FUN_004ca9a7 size=29 ====

void FUN_004ca9a7(void)

{
  void *unaff_RBP;
  
  operator_delete(unaff_RBP,0x48);
  FUN_005249f0();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004ca9c4 name=FUN_004ca9c4 size=21 ====

void FUN_004ca9c4(void)

{
  void *unaff_RBP;
  
  operator_delete(unaff_RBP,0x30);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004ca9d9 name=FUN_004ca9d9 size=16 ====

void FUN_004ca9d9(void)

{
  FUN_005249f0();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004ca9ea name=FUN_004ca9ea size=24 ====

void FUN_004ca9ea(void)

{
  FUN_005249f0();
  FUN_005249f0();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004caa02 name=FUN_004caa02 size=16 ====

void FUN_004caa02(void)

{
  QVariant *unaff_R13;
  
  QVariant::~QVariant(unaff_R13);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004caa12 name=FUN_004caa12 size=62 ====

void FUN_004caa12(void)

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
  FUN_00c86f70();
}


// ==== entry=004caa50 name=FUN_004caa50 size=21 ====

void FUN_004caa50(void)

{
  void *unaff_R12;
  
  operator_delete(unaff_R12,0x20);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004caa66 name=FUN_004caa66 size=33 ====

int FUN_004caa66(undefined8 param_1,undefined8 param_2,long param_3)

{
  long *unaff_RBP;
  int unaff_R14D;
  
  if (param_3 == 1) {
    __cxa_begin_catch();
    __cxa_end_catch();
    return unaff_R14D - *(int *)(*unaff_RBP + 0x14);
  }
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004caa88 name=FUN_004caa88 size=120 ====

void FUN_004caa88(void)

{
  code *pcVar1;
  long unaff_RBX;
  QPixmap *unaff_RBP;
  _func_void_Node_ptr *p_Var2;
  Data *pDVar3;
  
  FUN_0058ad66(unaff_RBX + 0xa0);
  p_Var2 = *(_func_void_Node_ptr **)(unaff_RBX + 0xb0);
  pcVar1 = p_Var2 + 0x10;
  if (*(int *)(p_Var2 + 0x10) == 0) {
LAB_004caab8:
    QHashData::free_helper(p_Var2);
  }
  else if (*(int *)(p_Var2 + 0x10) != -1) {
    LOCK();
    *(int *)pcVar1 = *(int *)pcVar1 + -1;
    UNLOCK();
    if (*(int *)pcVar1 == 0) {
      p_Var2 = *(_func_void_Node_ptr **)(unaff_RBX + 0xb0);
      goto LAB_004caab8;
    }
  }
  pDVar3 = *(Data **)(unaff_RBX + 0x90);
  if (*(int *)pDVar3 != 0) {
    if (*(int *)pDVar3 == -1) goto LAB_004caae8;
    LOCK();
    *(int *)pDVar3 = *(int *)pDVar3 + -1;
    UNLOCK();
    if (*(int *)pDVar3 != 0) goto LAB_004caae8;
    pDVar3 = *(Data **)(unaff_RBX + 0x90);
  }
  QListData::dispose(pDVar3);
LAB_004caae8:
  QPixmap::~QPixmap(unaff_RBP);
  FUN_005820a0();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004cab00 name=FUN_004cab00 size=47 ====

void FUN_004cab00(void)

{
  QIcon *unaff_R12;
  void *unaff_R15;
  
  operator_delete(unaff_R15,0x20);
  QIcon::~QIcon(unaff_R12);
  FUN_005249f0(&stack0x00000010);
  FUN_00558a5a();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004cab2f name=FUN_004cab2f size=10 ====

void FUN_004cab2f(void)

{
  QIcon *unaff_R12;
  QRegion *unaff_R14;
  
  QRegion::~QRegion(unaff_R14);
  QIcon::~QIcon(unaff_R12);
  FUN_005249f0(&stack0x00000010);
  FUN_00558a5a();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004cab39 name=FUN_004cab39 size=10 ====

void FUN_004cab39(void)

{
  QIcon *unaff_R12;
  
  FUN_005249f0();
  QIcon::~QIcon(unaff_R12);
  FUN_005249f0(&stack0x00000010);
  FUN_00558a5a();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004cab43 name=FUN_004cab43 size=15 ====

void FUN_004cab43(void)

{
  QVariant *unaff_R14;
  
  QVariant::~QVariant(unaff_R14);
  QIcon::~QIcon((QIcon *)&stack0x00000018);
  FUN_005249f0(&stack0x00000010);
  FUN_00558a5a();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004cab52 name=FUN_004cab52 size=70 ====

void FUN_004cab52(void)

{
  QStyleOption *unaff_RBX;
  
  QBrush::~QBrush((QBrush *)(unaff_RBX + 0xb8));
  FUN_005249f0(unaff_RBX + 0xa8);
  QIcon::~QIcon((QIcon *)(unaff_RBX + 0xa0));
  QLocale::~QLocale((QLocale *)(unaff_RBX + 0x70));
  QFont::~QFont((QFont *)(unaff_RBX + 0x58));
  QStyleOption::~QStyleOption(unaff_RBX);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004caba0 name=FUN_004caba0 size=48 ====

/* WARNING: Removing unreachable block (ram,0x004cabbd) */

void FUN_004caba0(undefined8 *param_1)

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


// ==== entry=004cabd0 name=FUN_004cabd0 size=30 ====

void FUN_004cabd0(void)

{
  long in_stack_00000008;
  
  FUN_004caba0(in_stack_00000008 + -0x18);
  FUN_005249f0();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004cabee name=FUN_004cabee size=10 ====

void FUN_004cabee(void)

{
  FUN_005249c0();
  FUN_005249f0();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004cabf8 name=FUN_004cabf8 size=24 ====

void FUN_004cabf8(void)

{
  FUN_005249c0();
  FUN_005249f0();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004cac10 name=FUN_004cac10 size=16 ====

void FUN_004cac10(void)

{
  QRegularExpressionMatch *unaff_R14;
  
  QRegularExpressionMatch::~QRegularExpressionMatch(unaff_R14);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004cac20 name=FUN_004cac20 size=16 ====

void FUN_004cac20(void)

{
  long in_stack_00000020;
  
  FUN_004caba0(in_stack_00000020 + -0x18);
  FUN_005249f0();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004cac30 name=FUN_004cac30 size=40 ====

void FUN_004cac30(void)

{
  undefined8 in_stack_00000030;
  long in_stack_00000060;
  
  FUN_004caba0(in_stack_00000060 + -0x18);
  FUN_005249f0();
  FUN_005249f0(in_stack_00000030);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004cac58 name=FUN_004cac58 size=10 ====

void FUN_004cac58(void)

{
  undefined8 in_stack_00000030;
  
  FUN_005249c0();
  FUN_005249f0();
  FUN_005249f0(in_stack_00000030);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004cac62 name=FUN_004cac62 size=29 ====

void FUN_004cac62(void)

{
  QTreeView *unaff_RBX;
  void *unaff_RBP;
  
  operator_delete(unaff_RBP,0xc0);
  QTreeView::~QTreeView(unaff_RBX);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004cac7f name=FUN_004cac7f size=15 ====

void FUN_004cac7f(void)

{
  QTreeView *unaff_RBX;
  void *unaff_RBP;
  
  operator_delete(unaff_RBP,0x50);
  QTreeView::~QTreeView(unaff_RBX);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004cac8e name=FUN_004cac8e size=10 ====

void FUN_004cac8e(void)

{
  QTreeView *unaff_RBX;
  
  FUN_005249f0();
  QTreeView::~QTreeView(unaff_RBX);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004cac98 name=FUN_004cac98 size=15 ====

void FUN_004cac98(void)

{
  QTreeView *unaff_RBX;
  void *unaff_RBP;
  
  operator_delete(unaff_RBP,0xb0);
  QTreeView::~QTreeView(unaff_RBX);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004caca8 name=FUN_004caca8 size=21 ====

void FUN_004caca8(void)

{
  void *unaff_RBP;
  
  operator_delete(unaff_RBP,0x20);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004cacbe name=FUN_004cacbe size=16 ====

void FUN_004cacbe(void)

{
  FUN_00550ec0();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004cacce name=FUN_004cacce size=24 ====

void FUN_004cacce(void)

{
  QRegularExpressionMatch *unaff_R13;
  
  QRegularExpressionMatch::~QRegularExpressionMatch(unaff_R13);
  FUN_005249f0();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004cace6 name=FUN_004cace6 size=16 ====

void FUN_004cace6(void)

{
  FUN_005249f0();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004cad00 name=FUN_004cad00 size=27 ====

void FUN_004cad00(void)

{
  QPushButton *unaff_RBX;
  QCursor *unaff_RBP;
  
  QCursor::~QCursor(unaff_RBP);
  QPushButton::~QPushButton(unaff_RBX);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004cad1c name=FUN_004cad1c size=16 ====

void FUN_004cad1c(void)

{
  QWidget *unaff_RBX;
  
  QWidget::~QWidget(unaff_RBX);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004cad2c name=FUN_004cad2c size=16 ====

void FUN_004cad2c(void)

{
  QStyleOption *unaff_RBP;
  
  QStyleOption::~QStyleOption(unaff_RBP);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004cad3c name=FUN_004cad3c size=24 ====

void FUN_004cad3c(void)

{
  QStyleOption *unaff_RBX;
  QPainter *unaff_R12;
  
  QStyleOption::~QStyleOption(unaff_RBX);
  QPainter::~QPainter(unaff_R12);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004cad54 name=FUN_004cad54 size=21 ====

void FUN_004cad54(void)

{
  void *unaff_RBX;
  
  operator_delete(unaff_RBX,0x30);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004cad69 name=FUN_004cad69 size=24 ====

void FUN_004cad69(void)

{
  QVariant *unaff_RBP;
  
  FUN_005249f0();
  QVariant::~QVariant(unaff_RBP);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004cad82 name=FUN_004cad82 size=16 ====

void FUN_004cad82(void)

{
  QVariant *unaff_R12;
  
  QVariant::~QVariant(unaff_R12);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004cad92 name=FUN_004cad92 size=21 ====

void FUN_004cad92(void)

{
  void *unaff_R13;
  
  operator_delete(unaff_R13,0x30);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004cada7 name=FUN_004cada7 size=32 ====

void FUN_004cada7(void)

{
  QIcon *unaff_R12;
  
  QIcon::~QIcon(unaff_R12);
  FUN_005249f0();
  FUN_005249f0();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004cadc7 name=FUN_004cadc7 size=16 ====

void FUN_004cadc7(void)

{
  FUN_005249f0();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004cadd8 name=FUN_004cadd8 size=16 ====

void FUN_004cadd8(void)

{
  QStyleOption *unaff_R12;
  
  QStyleOption::~QStyleOption(unaff_R12);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004cade8 name=FUN_004cade8 size=21 ====

void FUN_004cade8(void)

{
  void *unaff_R12;
  
  operator_delete(unaff_R12,0x20);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004cadfe name=FUN_004cadfe size=77 ====

void FUN_004cadfe(void)

{
  QLineEdit *unaff_RBX;
  int *piVar1;
  
  piVar1 = *(int **)(unaff_RBX + 0x50);
  if (*piVar1 != 0) {
    if (*piVar1 == -1) goto LAB_004cae0d;
    LOCK();
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if (*piVar1 != 0) goto LAB_004cae0d;
    piVar1 = *(int **)(unaff_RBX + 0x50);
  }
  FUN_0058d460(piVar1);
LAB_004cae0d:
  piVar1 = *(int **)(unaff_RBX + 0x30);
  if (piVar1 != (int *)0x0) {
    LOCK();
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if ((*piVar1 == 0) && (*(void **)(unaff_RBX + 0x30) != (void *)0x0)) {
      operator_delete(*(void **)(unaff_RBX + 0x30));
    }
  }
  QLineEdit::~QLineEdit(unaff_RBX);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004cae4c name=FUN_004cae4c size=24 ====

void FUN_004cae4c(void)

{
  __cxa_begin_catch();
  FUN_005249c0(&stack0x00000008);
                    /* WARNING: Subroutine does not return */
                    /* try { // try from 004cae5f to 004cae63 has its CatchHandler @ 004cae64 */
  __cxa_rethrow();
}


// ==== entry=004cae74 name=FUN_004cae74 size=30 ====

void FUN_004cae74(void)

{
  void *unaff_RBX;
  
                    /* catch(type#1 @ 00000000) { ... } // from try @ 004caf07 with catch @ 004cae75
                        */
  __cxa_end_catch();
  operator_delete(unaff_RBX,0x50);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004cae92 name=FUN_004cae92 size=23 ====

void FUN_004cae92(void)

{
  void *in_stack_00000040;
  
  operator_delete(in_stack_00000040,0x28);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004caea9 name=FUN_004caea9 size=13 ====

void FUN_004caea9(void)

{
  __cxa_begin_catch();
                    /* WARNING: Subroutine does not return */
                    /* try { // try from 004caeb1 to 004caeb5 has its CatchHandler @ 004caee0 */
  __cxa_rethrow();
}


// ==== entry=004caeb6 name=FUN_004caeb6 size=42 ====

void FUN_004caeb6(void)

{
  long unaff_R12;
  long in_stack_00000028;
  
  QVariant::~QVariant((QVariant *)(unaff_R12 + 8));
  FUN_005249f0(in_stack_00000028 + 8);
  FUN_005249f0(&stack0x00000068);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004caf0c name=FUN_004caf0c size=21 ====

void FUN_004caf0c(void)

{
  void *unaff_RBX;
  
  operator_delete(unaff_RBX,0x40);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004caf22 name=FUN_004caf22 size=32 ====

void FUN_004caf22(void)

{
  QIcon *unaff_R12;
  
  QIcon::~QIcon(unaff_R12);
  FUN_005249f0();
  FUN_005249f0();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004caf42 name=FUN_004caf42 size=16 ====

void FUN_004caf42(void)

{
  QVariant *unaff_R12;
  
  QVariant::~QVariant(unaff_R12);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004caf52 name=FUN_004caf52 size=16 ====

void FUN_004caf52(void)

{
  FUN_005249f0();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004caf62 name=FUN_004caf62 size=16 ====

void FUN_004caf62(void)

{
  FUN_005249f0();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004caf72 name=FUN_004caf72 size=16 ====

void FUN_004caf72(void)

{
  QFontMetrics *unaff_R12;
  
  QFontMetrics::~QFontMetrics(unaff_R12);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004caf90 name=FUN_004caf90 size=24 ====

void FUN_004caf90(void)

{
  FUN_005249f0();
  FUN_005249f0();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004cafa8 name=FUN_004cafa8 size=43 ====

void FUN_004cafa8(void)

{
  QVariant *unaff_RBP;
  
  FUN_005249f0();
  FUN_005249f0();
  QVariant::~QVariant(unaff_RBP);
  FUN_005249f0();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004cafd3 name=FUN_004cafd3 size=45 ====

void FUN_004cafd3(void)

{
  QVariant *unaff_RBX;
  QVariant *unaff_R12;
  QVariant *unaff_R13;
  
  QVariant::~QVariant(unaff_RBX);
  QVariant::~QVariant((QVariant *)&stack0x00000040);
  QVariant::~QVariant(unaff_R13);
  QVariant::~QVariant(unaff_R12);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004cb000 name=FUN_004cb000 size=10 ====

void FUN_004cb000(void)

{
  QVariant *unaff_R12;
  
  FUN_005249f0();
  QVariant::~QVariant(unaff_R12);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004cb00a name=FUN_004cb00a size=8 ====

void FUN_004cb00a(void)

{
  char unaff_BL;
  QVariant *unaff_R12;
  QVariant *unaff_R13;
  
  if (unaff_BL != '\0') {
    QVariant::~QVariant((QVariant *)&stack0x00000040);
  }
  QVariant::~QVariant(unaff_R13);
  QVariant::~QVariant(unaff_R12);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004cb012 name=FUN_004cb012 size=13 ====

void FUN_004cb012(void)

{
  QVariant *unaff_RBX;
  QVariant *unaff_RBP;
  
  QVariant::~QVariant(unaff_RBX);
  QVariant::~QVariant(unaff_RBP);
  FUN_005249f0();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004cb01f name=FUN_004cb01f size=13 ====

void FUN_004cb01f(void)

{
  QVariant *unaff_R12;
  
  FUN_005249f0();
  QVariant::~QVariant(unaff_R12);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004cb02c name=FUN_004cb02c size=16 ====

void FUN_004cb02c(void)

{
  QVariant *unaff_RBP;
  
  QVariant::~QVariant(unaff_RBP);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004cb03c name=FUN_004cb03c size=16 ====

void FUN_004cb03c(void)

{
  QVariant *unaff_RBP;
  
  QVariant::~QVariant(unaff_RBP);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004cb04c name=FUN_004cb04c size=26 ====

void FUN_004cb04c(void)

{
  long unaff_R13;
  
  if (unaff_R13 != 0) {
    QObject::blockSignals(SUB81(unaff_R13,0));
  }
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004cb066 name=FUN_004cb066 size=16 ====

void FUN_004cb066(void)

{
  FUN_005249f0();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004cb076 name=FUN_004cb076 size=24 ====

void FUN_004cb076(void)

{
  FUN_005249f0();
  FUN_005249f0();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004cb08e name=FUN_004cb08e size=13 ====

void FUN_004cb08e(void)

{
  QVariant *unaff_RBX;
  
  FUN_005249c0();
  QVariant::~QVariant(unaff_RBX);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004cb09b name=FUN_004cb09b size=24 ====

void FUN_004cb09b(void)

{
  QVariant *unaff_RBX;
  
  FUN_005249f0();
  QVariant::~QVariant(unaff_RBX);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004cb0b3 name=FUN_004cb0b3 size=24 ====

void FUN_004cb0b3(void)

{
  FUN_005249f0();
  FUN_005249f0();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004cb0cb name=FUN_004cb0cb size=10 ====

void FUN_004cb0cb(void)

{
  QVariant *unaff_RBP;
  
  QVariant::~QVariant(unaff_RBP);
  FUN_005249f0();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004cb0d5 name=FUN_004cb0d5 size=16 ====

void FUN_004cb0d5(void)

{
  QVariant *unaff_RBP;
  
  QVariant::~QVariant(unaff_RBP);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004cb0e6 name=FUN_004cb0e6 size=121 ====

void FUN_004cb0e6(void)

{
  undefined8 in_RAX;
  QVariant *unaff_RBP;
  undefined8 uStack0000000000000020;
  QVariant *in_stack_00000040;
  QVariant *in_stack_00000048;
  undefined8 in_stack_00000058;
  undefined8 in_stack_00000060;
  undefined8 in_stack_00000070;
  
  uStack0000000000000020 = in_RAX;
  QVariant::~QVariant((QVariant *)&stack0x00000100);
  FUN_005249c0(&stack0x000000a8);
  QVariant::~QVariant(unaff_RBP);
  FUN_005249c0(in_stack_00000070);
  QVariant::~QVariant(in_stack_00000040);
  FUN_005249c0(in_stack_00000058);
  QVariant::~QVariant(in_stack_00000048);
  FUN_005249f0(in_stack_00000060);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70(uStack0000000000000020);
}


// ==== entry=004cb15f name=FUN_004cb15f size=7 ====

void FUN_004cb15f(void)

{
  undefined8 in_RAX;
  QVariant *unaff_RBP;
  undefined8 uStack0000000000000020;
  QVariant *in_stack_00000040;
  QVariant *in_stack_00000048;
  undefined8 in_stack_00000058;
  undefined8 in_stack_00000060;
  undefined8 in_stack_00000070;
  
  uStack0000000000000020 = in_RAX;
  FUN_005249c0(&stack0x000000a8);
  QVariant::~QVariant(unaff_RBP);
  FUN_005249c0(in_stack_00000070);
  QVariant::~QVariant(in_stack_00000040);
  FUN_005249c0(in_stack_00000058);
  QVariant::~QVariant(in_stack_00000048);
  FUN_005249f0(in_stack_00000060);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70(uStack0000000000000020);
}


// ==== entry=004cb166 name=FUN_004cb166 size=34 ====

void FUN_004cb166(void)

{
  QIcon *unaff_RBP;
  undefined8 in_stack_00000020;
  
  FUN_005249f0(in_stack_00000020);
  QIcon::~QIcon(unaff_RBP);
  FUN_005249f0();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004cb188 name=FUN_004cb188 size=23 ====

void FUN_004cb188(void)

{
  void *in_stack_00000030;
  
  operator_delete(in_stack_00000030,0x20);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004cb19f name=FUN_004cb19f size=10 ====

void FUN_004cb19f(void)

{
  undefined8 in_RAX;
  QVariant *unaff_RBP;
  undefined8 uStack0000000000000020;
  QVariant *in_stack_00000040;
  QVariant *in_stack_00000048;
  undefined8 in_stack_00000058;
  undefined8 in_stack_00000060;
  undefined8 in_stack_00000070;
  
  uStack0000000000000020 = in_RAX;
  QVariant::~QVariant(unaff_RBP);
  FUN_005249c0(in_stack_00000070);
  QVariant::~QVariant(in_stack_00000040);
  FUN_005249c0(in_stack_00000058);
  QVariant::~QVariant(in_stack_00000048);
  FUN_005249f0(in_stack_00000060);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70(uStack0000000000000020);
}


// ==== entry=004cb1a9 name=FUN_004cb1a9 size=16 ====

void FUN_004cb1a9(void)

{
  QVariant *unaff_RBX;
  
  QVariant::~QVariant(unaff_RBX);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004cb1b9 name=FUN_004cb1b9 size=21 ====

void FUN_004cb1b9(void)

{
  void *unaff_R14;
  
  operator_delete(unaff_R14,0x30);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004cb1ce name=FUN_004cb1ce size=7 ====

/* WARNING: Removing unreachable block (ram,0x004cb11d) */

void FUN_004cb1ce(void)

{
  undefined8 in_RAX;
  QVariant *in_stack_00000040;
  QVariant *in_stack_00000048;
  undefined8 in_stack_00000058;
  undefined8 in_stack_00000060;
  undefined8 in_stack_00000070;
  
  FUN_005249c0(in_stack_00000070);
  QVariant::~QVariant(in_stack_00000040);
  FUN_005249c0(in_stack_00000058);
  QVariant::~QVariant(in_stack_00000048);
  FUN_005249f0(in_stack_00000060);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70(in_RAX);
}


// ==== entry=004cb1d5 name=FUN_004cb1d5 size=16 ====

void FUN_004cb1d5(void)

{
  QVariant *unaff_RBX;
  
  QVariant::~QVariant(unaff_RBX);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004cb1e5 name=FUN_004cb1e5 size=27 ====

void FUN_004cb1e5(void)

{
  QVariant *unaff_RBX;
  
  QVariant::~QVariant(unaff_RBX);
  FUN_005249c0();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004cb200 name=FUN_004cb200 size=36 ====

void FUN_004cb200(void)

{
  undefined8 in_stack_00000020;
  undefined8 in_stack_00000048;
  
  FUN_005249f0(in_stack_00000020);
  FUN_005249f0();
  FUN_005249f0(in_stack_00000048);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004cb224 name=FUN_004cb224 size=31 ====

void FUN_004cb224(void)

{
  void *unaff_R12;
  undefined8 in_stack_00000060;
  
  operator_delete(unaff_R12,0x90);
  FUN_005249f0(in_stack_00000060);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004cb243 name=FUN_004cb243 size=30 ====

void FUN_004cb243(void)

{
  undefined8 in_RAX;
  QVariant *unaff_RBP;
  undefined8 uStack0000000000000020;
  QVariant *in_stack_00000040;
  QVariant *in_stack_00000048;
  undefined8 in_stack_00000058;
  undefined8 in_stack_00000060;
  undefined8 in_stack_00000068;
  undefined8 in_stack_00000070;
  
  uStack0000000000000020 = in_RAX;
  FUN_005249c0(in_stack_00000068);
  QVariant::~QVariant((QVariant *)&stack0x00000100);
  FUN_005249c0(&stack0x000000a8);
  QVariant::~QVariant(unaff_RBP);
  FUN_005249c0(in_stack_00000070);
  QVariant::~QVariant(in_stack_00000040);
  FUN_005249c0(in_stack_00000058);
  QVariant::~QVariant(in_stack_00000048);
  FUN_005249f0(in_stack_00000060);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70(uStack0000000000000020);
}


// ==== entry=004cb261 name=FUN_004cb261 size=12 ====

void FUN_004cb261(void)

{
  undefined8 in_stack_00000020;
  undefined8 in_stack_00000048;
  
  FUN_005249f0(in_stack_00000020);
  FUN_005249f0();
  FUN_005249f0(in_stack_00000048);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004cb26d name=FUN_004cb26d size=26 ====

void FUN_004cb26d(void)

{
  undefined8 in_stack_00000020;
  
  FUN_005249f0();
  FUN_005249f0(in_stack_00000020);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004cb287 name=FUN_004cb287 size=21 ====

void FUN_004cb287(void)

{
  void *unaff_RBP;
  
  operator_delete(unaff_RBP,0x48);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004cb29c name=FUN_004cb29c size=10 ====

void FUN_004cb29c(void)

{
  QVariant *unaff_RBX;
  undefined8 in_stack_00000020;
  
  QVariant::~QVariant(unaff_RBX);
  FUN_005249f0(in_stack_00000020);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004cb2a6 name=FUN_004cb2a6 size=16 ====

void FUN_004cb2a6(void)

{
  undefined8 in_stack_00000060;
  
  FUN_005249f0();
  FUN_005249f0(in_stack_00000060);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004cb2b6 name=FUN_004cb2b6 size=21 ====

void FUN_004cb2b6(void)

{
  void *unaff_R12;
  
  operator_delete(unaff_R12,0x20);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004cb2cb name=FUN_004cb2cb size=21 ====

void FUN_004cb2cb(void)

{
  void *unaff_RBX;
  
  operator_delete(unaff_RBX,0x20);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004cb2e0 name=FUN_004cb2e0 size=21 ====

void FUN_004cb2e0(void)

{
  void *unaff_RBP;
  
  operator_delete(unaff_RBP,0x20);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004cb2f6 name=FUN_004cb2f6 size=21 ====

void FUN_004cb2f6(void)

{
  void *unaff_R13;
  
  operator_delete(unaff_R13,0x20);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004cb30b name=FUN_004cb30b size=29 ====

void FUN_004cb30b(void)

{
  void *unaff_R12;
  
  operator_delete(unaff_R12,0x30);
  FUN_005249f0();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004cb328 name=FUN_004cb328 size=29 ====

void FUN_004cb328(void)

{
  void *unaff_R13;
  
  operator_delete(unaff_R13,0x30);
  FUN_005249f0();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004cb345 name=FUN_004cb345 size=21 ====

void FUN_004cb345(void)

{
  void *unaff_R13;
  
  operator_delete(unaff_R13,0x30);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004cb35a name=FUN_004cb35a size=16 ====

void FUN_004cb35a(void)

{
  FUN_005249f0();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004cb36a name=FUN_004cb36a size=16 ====

void FUN_004cb36a(void)

{
  FUN_005249f0();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004cb37a name=FUN_004cb37a size=29 ====

void FUN_004cb37a(void)

{
  void *unaff_R13;
  
  operator_delete(unaff_R13,0x30);
  FUN_005249f0();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004cb397 name=FUN_004cb397 size=21 ====

void FUN_004cb397(void)

{
  void *unaff_RBP;
  
  operator_delete(unaff_RBP,0x30);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004cb3ac name=FUN_004cb3ac size=21 ====

void FUN_004cb3ac(void)

{
  void *unaff_RBP;
  
  operator_delete(unaff_RBP,0x30);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004cb3c1 name=FUN_004cb3c1 size=21 ====

void FUN_004cb3c1(void)

{
  void *unaff_R12;
  
  operator_delete(unaff_R12,0x20);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004cb3d6 name=FUN_004cb3d6 size=21 ====

void FUN_004cb3d6(void)

{
  void *unaff_R13;
  
  operator_delete(unaff_R13,0x30);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004cb3eb name=FUN_004cb3eb size=21 ====

void FUN_004cb3eb(void)

{
  void *unaff_R14;
  
  operator_delete(unaff_R14,0x30);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004cb400 name=FUN_004cb400 size=21 ====

void FUN_004cb400(void)

{
  void *unaff_R12;
  
  operator_delete(unaff_R12,0x20);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004cb415 name=FUN_004cb415 size=21 ====

void FUN_004cb415(void)

{
  void *unaff_R14;
  
  operator_delete(unaff_R14,0x30);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004cb42a name=FUN_004cb42a size=24 ====

void FUN_004cb42a(void)

{
  FUN_00af2c10();
  FUN_005249f0();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004cb442 name=FUN_004cb442 size=83 ====

void FUN_004cb442(void)

{
  undefined8 in_stack_00000020;
  undefined8 in_stack_00000028;
  undefined8 in_stack_00000058;
  undefined8 in_stack_00000088;
  
  FUN_005249f0(in_stack_00000028);
  FUN_005249f0();
  FUN_005249f0(in_stack_00000020);
  FUN_005249f0();
  FUN_005249f0(in_stack_00000058);
  FUN_005249f0(&stack0x000000e0);
  FUN_005249f0(in_stack_00000088);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004cb495 name=FUN_004cb495 size=17 ====

void FUN_004cb495(void)

{
  void *in_stack_00000030;
  undefined8 in_stack_00000088;
  
  operator_delete(in_stack_00000030,0x20);
  FUN_005249f0(in_stack_00000088);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004cb4a6 name=FUN_004cb4a6 size=17 ====

void FUN_004cb4a6(void)

{
  void *in_stack_00000060;
  undefined8 in_stack_00000088;
  
  operator_delete(in_stack_00000060,0x30);
  FUN_005249f0(in_stack_00000088);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004cb4b7 name=FUN_004cb4b7 size=36 ====

void FUN_004cb4b7(void)

{
  QVariant *unaff_RBP;
  QVariant *in_stack_00000020;
  undefined8 in_stack_00000028;
  
  QVariant::~QVariant(unaff_RBP);
  FUN_005249c0(in_stack_00000028);
  QVariant::~QVariant(in_stack_00000020);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004cb4db name=FUN_004cb4db size=23 ====

void FUN_004cb4db(void)

{
  void *in_stack_00000040;
  
  operator_delete(in_stack_00000040,0x20);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004cb4f2 name=FUN_004cb4f2 size=21 ====

void FUN_004cb4f2(void)

{
  void *unaff_R15;
  
  operator_delete(unaff_R15,0xa8);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004cb507 name=FUN_004cb507 size=49 ====

void FUN_004cb507(void)

{
  undefined8 in_stack_00000020;
  undefined8 in_stack_00000058;
  undefined8 in_stack_00000088;
  
  FUN_005249f0(in_stack_00000020);
  FUN_005249f0();
  FUN_005249f0();
  FUN_005249f0(in_stack_00000058);
  FUN_005249f0(&stack0x000000e0);
  FUN_005249f0(in_stack_00000088);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004cb538 name=FUN_004cb538 size=31 ====

void FUN_004cb538(void)

{
  undefined8 in_stack_00000058;
  undefined8 in_stack_00000088;
  
  FUN_005249f0();
  FUN_005249f0(in_stack_00000058);
  FUN_005249f0(&stack0x000000e0);
  FUN_005249f0(in_stack_00000088);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004cb557 name=FUN_004cb557 size=15 ====

void FUN_004cb557(void)

{
  void *unaff_R12;
  undefined8 in_stack_00000058;
  undefined8 in_stack_00000088;
  
  operator_delete(unaff_R12,0x30);
  FUN_005249f0(in_stack_00000058);
  FUN_005249f0(&stack0x000000e0);
  FUN_005249f0(in_stack_00000088);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004cb566 name=FUN_004cb566 size=49 ====

void FUN_004cb566(void)

{
  QIcon *unaff_RBP;
  undefined8 in_stack_00000020;
  undefined8 in_stack_00000028;
  undefined8 in_stack_00000088;
  
  QIcon::~QIcon(unaff_RBP);
  FUN_005249f0(in_stack_00000028);
  FUN_005249f0(in_stack_00000020);
  FUN_005249f0();
  FUN_005249f0(&stack0x000000e0);
  FUN_005249f0(in_stack_00000088);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004cb597 name=FUN_004cb597 size=21 ====

void FUN_004cb597(void)

{
  undefined8 in_stack_00000088;
  
  FUN_005249f0();
  FUN_005249f0(&stack0x000000e0);
  FUN_005249f0(in_stack_00000088);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004cb5ac name=FUN_004cb5ac size=21 ====

void FUN_004cb5ac(void)

{
  undefined8 in_stack_00000088;
  
  FUN_005249f0();
  FUN_005249f0(&stack0x000000e0);
  FUN_005249f0(in_stack_00000088);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004cb5c1 name=FUN_004cb5c1 size=23 ====

void FUN_004cb5c1(void)

{
  undefined8 in_stack_00000020;
  undefined8 in_stack_00000058;
  undefined8 in_stack_00000088;
  
  FUN_005249f0(in_stack_00000020);
  FUN_005249f0();
  FUN_005249f0();
  FUN_005249f0(in_stack_00000058);
  FUN_005249f0(&stack0x000000e0);
  FUN_005249f0(in_stack_00000088);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004cb5d8 name=FUN_004cb5d8 size=64 ====

void FUN_004cb5d8(void)

{
  char unaff_R12B;
  void *in_stack_00000080;
  undefined8 in_stack_00000088;
  
  operator_delete(in_stack_00000080,0x30);
  FUN_005249f0();
  if (unaff_R12B != '\0') {
    FUN_005249f0(&stack0x00000118);
  }
  FUN_005249f0(&stack0x000000e0);
  FUN_005249f0(in_stack_00000088);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004cb618 name=FUN_004cb618 size=21 ====

void FUN_004cb618(void)

{
  undefined8 in_stack_00000088;
  
  FUN_005249f0();
  FUN_005249f0(&stack0x000000e0);
  FUN_005249f0(in_stack_00000088);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004cb62d name=FUN_004cb62d size=28 ====

void FUN_004cb62d(void)

{
  void *in_stack_00000050;
  undefined8 in_stack_00000088;
  
  operator_delete(in_stack_00000050,0x30);
  FUN_005249f0(&stack0x000000e0);
  FUN_005249f0(in_stack_00000088);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004cb649 name=FUN_004cb649 size=49 ====

void FUN_004cb649(void)

{
  QIcon *unaff_RBP;
  undefined8 in_stack_00000020;
  undefined8 in_stack_00000028;
  undefined8 in_stack_00000088;
  
  QIcon::~QIcon(unaff_RBP);
  FUN_005249f0(in_stack_00000028);
  FUN_005249f0(in_stack_00000020);
  FUN_005249f0();
  FUN_005249f0(&stack0x000000e0);
  FUN_005249f0(in_stack_00000088);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004cb67a name=FUN_004cb67a size=33 ====

void FUN_004cb67a(void)

{
  undefined8 in_stack_00000020;
  undefined8 in_stack_00000028;
  undefined8 in_stack_00000058;
  undefined8 in_stack_00000088;
  
  FUN_005249f0(in_stack_00000028);
  FUN_005249f0();
  FUN_005249f0(in_stack_00000020);
  FUN_005249f0();
  FUN_005249f0(in_stack_00000058);
  FUN_005249f0(&stack0x000000e0);
  FUN_005249f0(in_stack_00000088);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004cb69b name=FUN_004cb69b size=59 ====

void FUN_004cb69b(void)

{
  undefined8 in_stack_00000020;
  undefined8 in_stack_00000028;
  undefined8 in_stack_00000058;
  undefined8 in_stack_00000088;
  
  FUN_005249f0();
  FUN_005249f0(in_stack_00000020);
  FUN_005249f0();
  FUN_005249f0(in_stack_00000028);
  FUN_005249f0(in_stack_00000058);
  FUN_005249f0(&stack0x000000e0);
  FUN_005249f0(in_stack_00000088);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004cb6d6 name=FUN_004cb6d6 size=28 ====

void FUN_004cb6d6(void)

{
  void *in_stack_00000068;
  undefined8 in_stack_00000088;
  
  operator_delete(in_stack_00000068,0x20);
  FUN_005249f0(&stack0x000000e0);
  FUN_005249f0(in_stack_00000088);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004cb6f2 name=FUN_004cb6f2 size=28 ====

void FUN_004cb6f2(void)

{
  void *in_stack_00000038;
  undefined8 in_stack_00000088;
  
  operator_delete(in_stack_00000038,0x30);
  FUN_005249f0(&stack0x000000e0);
  FUN_005249f0(in_stack_00000088);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004cb70e name=FUN_004cb70e size=15 ====

void FUN_004cb70e(void)

{
  void *unaff_R13;
  undefined8 in_stack_00000058;
  undefined8 in_stack_00000088;
  
  operator_delete(unaff_R13,0x30);
  FUN_005249f0(in_stack_00000058);
  FUN_005249f0(&stack0x000000e0);
  FUN_005249f0(in_stack_00000088);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004cb71d name=FUN_004cb71d size=13 ====

void FUN_004cb71d(void)

{
  undefined8 in_stack_00000088;
  
  FUN_005249f0(&stack0x000000e0);
  FUN_005249f0(in_stack_00000088);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004cb72a name=FUN_004cb72a size=13 ====

void FUN_004cb72a(void)

{
  undefined8 in_stack_00000088;
  
  FUN_005249f0(&stack0x000000e0);
  FUN_005249f0(in_stack_00000088);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004cb738 name=FUN_004cb738 size=40 ====

void FUN_004cb738(void)

{
  FUN_005249f0();
  FUN_005249f0();
  FUN_005249f0();
  FUN_005249f0();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004cb760 name=FUN_004cb760 size=39 ====

void FUN_004cb760(void)

{
  FUN_005249f0();
  FUN_005249f0();
  FUN_005249f0();
  FUN_005249f0();
  FUN_005249f0(&stack0x00000018);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004cb788 name=FUN_004cb788 size=26 ====

void FUN_004cb788(void)

{
  undefined8 in_stack_00000028;
  
  FUN_005249f0();
  FUN_005249c0(in_stack_00000028);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004cb7a2 name=FUN_004cb7a2 size=18 ====

void FUN_004cb7a2(void)

{
  undefined8 in_stack_00000028;
  
  FUN_005249f0();
  FUN_005249f0();
  FUN_005249c0(in_stack_00000028);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004cb7b4 name=FUN_004cb7b4 size=23 ====

void FUN_004cb7b4(void)

{
  void *in_stack_00000040;
  
  operator_delete(in_stack_00000040,0x90);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004cb7cb name=FUN_004cb7cb size=21 ====

void FUN_004cb7cb(void)

{
  void *unaff_R14;
  
  operator_delete(unaff_R14,0x30);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004cb7e0 name=FUN_004cb7e0 size=21 ====

void FUN_004cb7e0(void)

{
  void *unaff_R15;
  
  operator_delete(unaff_R15,0x20);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004cb7f5 name=FUN_004cb7f5 size=16 ====

void FUN_004cb7f5(void)

{
  FUN_005249f0();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004cb805 name=FUN_004cb805 size=21 ====

void FUN_004cb805(void)

{
  void *unaff_R13;
  
  operator_delete(unaff_R13,0x90);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004cb81a name=FUN_004cb81a size=31 ====

void FUN_004cb81a(void)

{
  void *in_stack_00000030;
  
  operator_delete(in_stack_00000030,0x80);
  FUN_005249f0();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004cb839 name=FUN_004cb839 size=49 ====

void FUN_004cb839(void)

{
  undefined8 in_stack_00000028;
  void *in_stack_00000038;
  
  operator_delete(in_stack_00000038,0x30);
  FUN_005249f0(in_stack_00000028);
  FUN_005249f0();
  FUN_005249f0();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004cb86a name=FUN_004cb86a size=16 ====

void FUN_004cb86a(void)

{
  FUN_005249f0();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004cb87a name=FUN_004cb87a size=16 ====

void FUN_004cb87a(void)

{
  FUN_005249f0();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004cb88a name=FUN_004cb88a size=34 ====

void FUN_004cb88a(void)

{
  QIcon *unaff_R13;
  undefined8 in_stack_00000028;
  
  FUN_005249f0(in_stack_00000028);
  QIcon::~QIcon(unaff_R13);
  FUN_005249f0();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004cb8ac name=FUN_004cb8ac size=16 ====

void FUN_004cb8ac(void)

{
  FUN_005249f0();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004cb8bc name=FUN_004cb8bc size=16 ====

void FUN_004cb8bc(void)

{
  FUN_005249f0();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004cb8cc name=FUN_004cb8cc size=16 ====

void FUN_004cb8cc(void)

{
  FUN_005249f0();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004cb8dc name=FUN_004cb8dc size=16 ====

void FUN_004cb8dc(void)

{
  FUN_005249f0();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004cb8ec name=FUN_004cb8ec size=81 ====

void FUN_004cb8ec(void)

{
  QWidget *unaff_RBX;
  
  FUN_005249f0();
  FUN_005249f0(unaff_RBX + 0xa8);
  FUN_00550ea0(unaff_RBX + 0x90);
  FUN_00550ea0(unaff_RBX + 0x80);
  FUN_00525060(unaff_RBX + 0x48);
  FUN_00525060(unaff_RBX + 0x38);
  QWidget::~QWidget(unaff_RBX);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004cb93e name=FUN_004cb93e size=54 ====

void FUN_004cb93e(void)

{
  undefined8 in_stack_00000008;
  undefined8 in_stack_00000010;
  
  FUN_005249f0();
  FUN_005249f0(in_stack_00000010);
  FUN_005249f0(in_stack_00000008);
  FUN_005249c0(&stack0x00000030);
  FUN_005249f0();
  FUN_005249f0();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004cb974 name=FUN_004cb974 size=32 ====

void FUN_004cb974(void)

{
  FUN_005249c0();
  FUN_005249f0();
  FUN_005249f0();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004cb994 name=FUN_004cb994 size=16 ====

void FUN_004cb994(void)

{
  QVariant *unaff_RBX;
  
  QVariant::~QVariant(unaff_RBX);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004cb9a4 name=FUN_004cb9a4 size=10 ====

void FUN_004cb9a4(void)

{
  FUN_005249f0();
  FUN_005249f0();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004cb9ae name=FUN_004cb9ae size=31 ====

void FUN_004cb9ae(void)

{
  QJsonDocument *unaff_RBX;
  QJsonObject *unaff_R13;
  undefined8 in_stack_00000018;
  
  QJsonDocument::~QJsonDocument(unaff_RBX);
  QJsonObject::~QJsonObject(unaff_R13);
  FUN_005249c0(in_stack_00000018);
  FUN_005249c0();
  FUN_005249f0();
  FUN_005249f0();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004cb9cd name=FUN_004cb9cd size=10 ====

void FUN_004cb9cd(void)

{
  QVariant *unaff_RBX;
  
  QVariant::~QVariant(unaff_RBX);
  FUN_005249f0();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004cb9d7 name=FUN_004cb9d7 size=16 ====

void FUN_004cb9d7(void)

{
  undefined8 in_stack_00000008;
  undefined8 in_stack_00000010;
  
  FUN_005249f0();
  FUN_005249f0(in_stack_00000010);
  FUN_005249f0(in_stack_00000008);
  FUN_005249c0(&stack0x00000030);
  FUN_005249f0();
  FUN_005249f0();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004cb9e7 name=FUN_004cb9e7 size=24 ====

void FUN_004cb9e7(void)

{
  undefined8 in_stack_00000008;
  undefined8 in_stack_00000010;
  
  FUN_005249f0();
  FUN_005249f0();
  FUN_005249f0(in_stack_00000010);
  FUN_005249f0(in_stack_00000008);
  FUN_005249c0(&stack0x00000030);
  FUN_005249f0();
  FUN_005249f0();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004cb9ff name=FUN_004cb9ff size=48 ====

void FUN_004cb9ff(void)

{
  long unaff_RBX;
  
  FUN_005249f0(unaff_RBX + 0x20);
  FUN_005249f0(unaff_RBX + 0x18);
  FUN_005249f0(unaff_RBX + 0x10);
  FUN_005249f0();
  FUN_005249c0(&stack0x00000030);
  FUN_005249f0();
  FUN_005249f0();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004cba2f name=FUN_004cba2f size=23 ====

void FUN_004cba2f(void)

{
  QJsonValue *unaff_RBX;
  QJsonObject *unaff_R13;
  undefined8 in_stack_00000008;
  undefined8 in_stack_00000018;
  
  FUN_005249f0(in_stack_00000008);
  QJsonValue::~QJsonValue(unaff_RBX);
  QJsonObject::~QJsonObject(unaff_R13);
  FUN_005249c0(in_stack_00000018);
  FUN_005249c0();
  FUN_005249f0();
  FUN_005249f0();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004cba46 name=FUN_004cba46 size=16 ====

void FUN_004cba46(void)

{
  QJsonDocument *unaff_RBX;
  undefined8 in_stack_00000018;
  
  QJsonDocument::~QJsonDocument(unaff_RBX);
  FUN_005249c0(in_stack_00000018);
  FUN_005249c0();
  FUN_005249f0();
  FUN_005249f0();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004cba56 name=FUN_004cba56 size=25 ====

void FUN_004cba56(void)

{
  undefined8 unaff_retaddr;
  
  FUN_005249f0(unaff_retaddr);
  FUN_00596d30();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004cba70 name=FUN_004cba70 size=44 ====

void FUN_004cba70(void)

{
  undefined8 in_stack_00000040;
  undefined8 in_stack_00000048;
  
  FUN_005249f0();
  FUN_005249f0();
  FUN_005249f0(in_stack_00000048);
  FUN_00525060(in_stack_00000040);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004cba9c name=FUN_004cba9c size=16 ====

void FUN_004cba9c(void)

{
  FUN_005249f0();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004cbaac name=FUN_004cbaac size=23 ====

void FUN_004cbaac(void)

{
  void *unaff_RBP;
  undefined8 in_stack_00000040;
  
  operator_delete(unaff_RBP,0x30);
  FUN_005249f0();
  FUN_00525060(in_stack_00000040);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004cbac3 name=FUN_004cbac3 size=15 ====

void FUN_004cbac3(void)

{
  void *unaff_R13;
  undefined8 in_stack_00000040;
  undefined8 in_stack_00000048;
  
  operator_delete(unaff_R13,0x90);
  FUN_005249f0(in_stack_00000048);
  FUN_00525060(in_stack_00000040);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004cbad2 name=FUN_004cbad2 size=15 ====

void FUN_004cbad2(void)

{
  void *unaff_RBP;
  undefined8 in_stack_00000040;
  undefined8 in_stack_00000048;
  
  operator_delete(unaff_RBP,0x30);
  FUN_005249f0();
  FUN_005249f0(in_stack_00000048);
  FUN_00525060(in_stack_00000040);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004cbae2 name=FUN_004cbae2 size=38 ====

void FUN_004cbae2(void)

{
  undefined8 in_stack_00000030;
  undefined8 in_stack_00000040;
  undefined8 in_stack_00000048;
  
  FUN_00596d30(in_stack_00000030);
  FUN_005249c0(in_stack_00000048);
  FUN_005249f0(in_stack_00000040);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004cbb08 name=FUN_004cbb08 size=47 ====

void FUN_004cbb08(void)

{
  FUN_005249f0(&stack0x00000090);
  FUN_005249f0(&stack0x000000a0);
  FUN_005249f0(&stack0x00000088);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004cbb37 name=FUN_004cbb37 size=17 ====

void FUN_004cbb37(void)

{
  void *in_stack_00000038;
  undefined8 in_stack_00000040;
  undefined8 in_stack_00000048;
  
  operator_delete(in_stack_00000038,0x20);
  FUN_005249c0(in_stack_00000048);
  FUN_005249f0(in_stack_00000040);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004cbb48 name=FUN_004cbb48 size=23 ====

void FUN_004cbb48(void)

{
  QVariant *unaff_RBX;
  undefined8 in_stack_00000030;
  undefined8 in_stack_00000040;
  
  QVariant::~QVariant(unaff_RBX);
  FUN_005249c0(in_stack_00000030);
  FUN_005249f0(in_stack_00000040);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004cbb5f name=FUN_004cbb5f size=21 ====

void FUN_004cbb5f(void)

{
  void *unaff_R14;
  
  operator_delete(unaff_R14,0xa8);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004cbb74 name=FUN_004cbb74 size=15 ====

void FUN_004cbb74(void)

{
  undefined8 in_stack_00000030;
  undefined8 in_stack_00000040;
  undefined8 in_stack_00000048;
  
  FUN_005249f0(in_stack_00000030);
  FUN_005249c0(in_stack_00000048);
  FUN_005249f0(in_stack_00000040);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004cbb83 name=FUN_004cbb83 size=23 ====

void FUN_004cbb83(void)

{
  undefined8 in_stack_00000030;
  undefined8 in_stack_00000040;
  undefined8 in_stack_00000048;
  
  FUN_00596d30(in_stack_00000030);
  FUN_005249f0();
  FUN_005249c0(in_stack_00000048);
  FUN_005249f0(in_stack_00000040);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004cbb9a name=FUN_004cbb9a size=57 ====

void FUN_004cbb9a(void)

{
  undefined8 in_stack_00000028;
  undefined8 in_stack_00000030;
  undefined8 in_stack_00000040;
  
  FUN_005249f0();
  FUN_005249c0();
  FUN_005249f0(in_stack_00000028);
  FUN_00525060(in_stack_00000040);
  FUN_00525060(in_stack_00000030);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004cbbd3 name=FUN_004cbbd3 size=33 ====

void FUN_004cbbd3(void)

{
  QVariant *unaff_RBX;
  undefined8 in_stack_00000028;
  undefined8 in_stack_00000030;
  undefined8 in_stack_00000038;
  
  QVariant::~QVariant(unaff_RBX);
  FUN_005249c0(in_stack_00000038);
  FUN_005249f0(in_stack_00000028);
  FUN_00525060(&stack0x00000060);
  FUN_00525060(in_stack_00000030);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004cbbf4 name=FUN_004cbbf4 size=23 ====

void FUN_004cbbf4(void)

{
  undefined8 in_stack_00000030;
  
  FUN_005249f0();
  FUN_00525060(&stack0x00000060);
  FUN_00525060(in_stack_00000030);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004cbc0b name=FUN_004cbc0b size=31 ====

void FUN_004cbc0b(void)

{
  undefined8 in_stack_00000030;
  undefined8 in_stack_00000038;
  
  FUN_005249f0();
  FUN_005249f0(in_stack_00000038);
  FUN_005249f0();
  FUN_00525060(in_stack_00000030);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004cbc2a name=FUN_004cbc2a size=99 ====

void FUN_004cbc2a(void)

{
  QVariant *in_stack_00000038;
  char in_stack_000000b0;
  code *in_stack_000000c8;
  code *in_stack_000000d0;
  
  QVariant::~QVariant(in_stack_00000038);
  FUN_005249c0();
  if (in_stack_000000b0 != '\0') {
    if (in_stack_000000c8 == (code *)0x0) {
                    /* WARNING: Subroutine does not return */
      std::__throw_bad_function_call();
    }
    (*in_stack_000000d0)(&stack0x000000b8);
  }
  if (in_stack_000000c8 != (code *)0x0) {
    (*in_stack_000000c8)(&stack0x000000b8,&stack0x000000b8,3);
  }
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004cbc8d name=FUN_004cbc8d size=97 ====

void FUN_004cbc8d(void)

{
  code *in_stack_00000080;
  code *in_stack_000000a0;
  code *in_stack_000000c8;
  
  if (in_stack_000000c8 != (code *)0x0) {
    (*in_stack_000000c8)(&stack0x000000b8,&stack0x000000b8,3);
  }
  if (in_stack_00000080 != (code *)0x0) {
    (*in_stack_00000080)();
  }
  if (in_stack_000000a0 != (code *)0x0) {
    (*in_stack_000000a0)(&stack0x00000090,&stack0x00000090,3);
  }
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004cbcee name=FUN_004cbcee size=16 ====

void FUN_004cbcee(void)

{
  QVariant *unaff_RBX;
  
  QVariant::~QVariant(unaff_RBX);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004cbcfe name=FUN_004cbcfe size=16 ====

void FUN_004cbcfe(void)

{
  FUN_005249f0();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004cbd0e name=FUN_004cbd0e size=21 ====

void FUN_004cbd0e(void)

{
  void *unaff_R13;
  
  operator_delete(unaff_R13,0x30);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004cbd23 name=FUN_004cbd23 size=16 ====

void FUN_004cbd23(void)

{
  undefined8 in_stack_00000030;
  undefined8 in_stack_00000040;
  
  FUN_005249c0();
  FUN_00525060(in_stack_00000040);
  FUN_00525060(in_stack_00000030);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004cbd33 name=FUN_004cbd33 size=26 ====

void FUN_004cbd33(void)

{
  QVariant *unaff_RBX;
  undefined8 in_stack_00000030;
  undefined8 in_stack_00000038;
  
  QVariant::~QVariant(unaff_RBX);
  FUN_005249c0(in_stack_00000038);
  FUN_00525060(in_stack_00000030);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004cbd4d name=FUN_004cbd4d size=16 ====

void FUN_004cbd4d(void)

{
  undefined8 in_stack_00000030;
  undefined8 in_stack_00000040;
  
  FUN_005249f0();
  FUN_00525060(in_stack_00000040);
  FUN_00525060(in_stack_00000030);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004cbd5d name=FUN_004cbd5d size=34 ====

void FUN_004cbd5d(void)

{
  undefined8 in_stack_00000030;
  undefined8 in_stack_00000038;
  undefined8 in_stack_00000040;
  
  FUN_005249f0();
  FUN_005249f0(in_stack_00000038);
  FUN_005249f0();
  FUN_00525060(in_stack_00000040);
  FUN_00525060(in_stack_00000030);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004cbd7f name=FUN_004cbd7f size=26 ====

void FUN_004cbd7f(void)

{
  undefined8 in_stack_00000030;
  undefined8 in_stack_00000038;
  undefined8 in_stack_00000040;
  
  FUN_005249f0();
  FUN_005249f0(in_stack_00000038);
  FUN_00525060(in_stack_00000040);
  FUN_00525060(in_stack_00000030);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004cbd99 name=FUN_004cbd99 size=26 ====

void FUN_004cbd99(void)

{
  undefined8 in_stack_00000030;
  undefined8 in_stack_00000038;
  
  FUN_005249f0();
  FUN_005249f0(in_stack_00000038);
  FUN_005249f0();
  FUN_00525060(in_stack_00000030);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004cbdb3 name=FUN_004cbdb3 size=18 ====

void FUN_004cbdb3(void)

{
  undefined8 in_stack_00000028;
  char in_stack_000000b0;
  code *in_stack_000000c8;
  code *in_stack_000000d0;
  
  FUN_005249f0(in_stack_00000028);
  if (in_stack_000000b0 != '\0') {
    if (in_stack_000000c8 == (code *)0x0) {
                    /* WARNING: Subroutine does not return */
      std::__throw_bad_function_call();
    }
    (*in_stack_000000d0)(&stack0x000000b8);
  }
  if (in_stack_000000c8 != (code *)0x0) {
    (*in_stack_000000c8)(&stack0x000000b8,&stack0x000000b8,3);
  }
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004cbdc5 name=FUN_004cbdc5 size=16 ====

void FUN_004cbdc5(void)

{
  undefined8 in_stack_00000030;
  
  FUN_005249f0();
  FUN_00525060(in_stack_00000030);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004cbdd5 name=FUN_004cbdd5 size=26 ====

void FUN_004cbdd5(void)

{
  QVariant *unaff_RBX;
  undefined8 in_stack_00000030;
  undefined8 in_stack_00000038;
  
  QVariant::~QVariant(unaff_RBX);
  FUN_005249c0(in_stack_00000038);
  FUN_00525060(in_stack_00000030);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004cbdef name=FUN_004cbdef size=16 ====

void FUN_004cbdef(void)

{
  undefined8 in_stack_00000030;
  
  FUN_005249f0();
  FUN_00525060(in_stack_00000030);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004cbdff name=FUN_004cbdff size=33 ====

void FUN_004cbdff(void)

{
  undefined8 in_stack_00000028;
  undefined8 in_stack_00000030;
  undefined8 in_stack_00000038;
  
  FUN_005249c0(in_stack_00000038);
  FUN_005249c0();
  FUN_005249c0();
  FUN_005249f0(in_stack_00000028);
  FUN_00525060(&stack0x00000060);
  FUN_00525060(in_stack_00000030);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004cbe20 name=FUN_004cbe20 size=16 ====

void FUN_004cbe20(void)

{
  FUN_00596d30();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004cbe30 name=FUN_004cbe30 size=50 ====

void FUN_004cbe30(void)

{
  undefined8 in_stack_00000008;
  
  FUN_005249f0();
  FUN_005249c0();
  FUN_005249c0();
  FUN_00596d30();
  FUN_005249f0(in_stack_00000008);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004cbea7 name=FUN_004cbea7 size=11 ====

void FUN_004cbea7(void)

{
  undefined8 in_stack_00000008;
  
  FUN_005249f0();
  FUN_00596d30();
  FUN_005249f0(in_stack_00000008);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004cbeb2 name=FUN_004cbeb2 size=10 ====

void FUN_004cbeb2(void)

{
  undefined8 in_stack_00000008;
  
  FUN_005249f0();
  FUN_005249c0();
  FUN_00596d30();
  FUN_005249f0(in_stack_00000008);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004cbebc name=FUN_004cbebc size=30 ====

void FUN_004cbebc(void)

{
  QVariant *unaff_RBP;
  undefined8 in_stack_00000008;
  undefined8 in_stack_00000020;
  
  QVariant::~QVariant(unaff_RBP);
  FUN_005249c0(in_stack_00000020);
  FUN_00528c1c();
  FUN_005249f0(in_stack_00000008);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004cbed0 name=FUN_004cbed0 size=31 ====

void FUN_004cbed0(void)

{
  undefined8 in_stack_00000008;
  undefined8 in_stack_00000020;
  
  FUN_005249c0();
  FUN_005249c0(in_stack_00000020);
  FUN_005249f0();
  FUN_005249f0(in_stack_00000008);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004cbeef name=FUN_004cbeef size=13 ====

void FUN_004cbeef(void)

{
  undefined8 in_stack_00000008;
  
  FUN_005249f0();
  FUN_005249f0(in_stack_00000008);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004cbefc name=FUN_004cbefc size=22 ====

void FUN_004cbefc(void)

{
  long unaff_R15;
  
  __cxa_begin_catch();
  FUN_005249f0(unaff_R15 + 0x18);
                    /* WARNING: Subroutine does not return */
                    /* try { // try from 004cbf0d to 004cbf11 has its CatchHandler @ 004cbf12 */
  __cxa_rethrow();
}


// ==== entry=004cbf32 name=FUN_004cbf32 size=31 ====

void FUN_004cbf32(void)

{
  QVariant *unaff_RBP;
  undefined8 in_stack_00000008;
  undefined8 in_stack_00000020;
  
  FUN_005249c0(in_stack_00000020);
  QVariant::~QVariant(unaff_RBP);
  FUN_005249f0();
  FUN_005249c0();
  FUN_005249c0();
  FUN_00596d30();
  FUN_005249f0(in_stack_00000008);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004cbf51 name=FUN_004cbf51 size=10 ====

void FUN_004cbf51(void)

{
  undefined8 in_stack_00000008;
  
  FUN_005249c0();
  FUN_005249f0();
  FUN_005249c0();
  FUN_005249c0();
  FUN_00596d30();
  FUN_005249f0(in_stack_00000008);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004cbf5c name=FUN_004cbf5c size=16 ====

void FUN_004cbf5c(void)

{
  FUN_00534d80();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004cbf6c name=FUN_004cbf6c size=24 ====

void FUN_004cbf6c(void)

{
  FUN_00534d80();
  FUN_005249f0();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004cbf90 name=FUN_004cbf90 size=16 ====

void FUN_004cbf90(void)

{
  FUN_005249f0();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004cbfa0 name=FUN_004cbfa0 size=21 ====

void FUN_004cbfa0(void)

{
  void *unaff_R12;
  
  operator_delete(unaff_R12,0x20);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004cbfb6 name=FUN_004cbfb6 size=21 ====

void FUN_004cbfb6(void)

{
  void *unaff_RBP;
  
  operator_delete(unaff_RBP,0x30);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004cbfcb name=FUN_004cbfcb size=16 ====

void FUN_004cbfcb(void)

{
  FUN_005249f0();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004cbfdb name=FUN_004cbfdb size=32 ====

void FUN_004cbfdb(void)

{
  QIcon *unaff_RBP;
  
  QIcon::~QIcon(unaff_RBP);
  FUN_005249f0();
  FUN_005249f0();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004cbffb name=FUN_004cbffb size=16 ====

void FUN_004cbffb(void)

{
  FUN_005249f0();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004cc00b name=FUN_004cc00b size=16 ====

void FUN_004cc00b(void)

{
  FUN_005249f0();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004cc01b name=FUN_004cc01b size=16 ====

void FUN_004cc01b(void)

{
  FUN_005249f0();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004cc02b name=FUN_004cc02b size=21 ====

void FUN_004cc02b(void)

{
  void *unaff_R12;
  
  operator_delete(unaff_R12,0x20);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004cc040 name=FUN_004cc040 size=21 ====

void FUN_004cc040(void)

{
  void *unaff_RBP;
  
  operator_delete(unaff_RBP,0x20);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004cc055 name=FUN_004cc055 size=21 ====

void FUN_004cc055(void)

{
  void *unaff_RBP;
  
  operator_delete(unaff_RBP,0x30);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004cc06a name=FUN_004cc06a size=16 ====

void FUN_004cc06a(void)

{
  FUN_005249f0();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004cc07a name=FUN_004cc07a size=16 ====

void FUN_004cc07a(void)

{
  FUN_005249f0();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004cc08a name=FUN_004cc08a size=16 ====

void FUN_004cc08a(void)

{
  QEasingCurve *unaff_RBX;
  
  QEasingCurve::~QEasingCurve(unaff_RBX);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004cc09a name=FUN_004cc09a size=29 ====

void FUN_004cc09a(void)

{
  void *unaff_RBP;
  
  operator_delete(unaff_RBP,0x10);
  FUN_005249c0();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004cc0b7 name=FUN_004cc0b7 size=16 ====

void FUN_004cc0b7(void)

{
  QVariant *unaff_RBX;
  
  QVariant::~QVariant(unaff_RBX);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004cc0c7 name=FUN_004cc0c7 size=16 ====

void FUN_004cc0c7(void)

{
  QVariant *unaff_RBX;
  
  QVariant::~QVariant(unaff_RBX);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004cc0d8 name=FUN_004cc0d8 size=45 ====

void FUN_004cc0d8(void)

{
  QWidget *unaff_RBX;
  
  FUN_005249f0();
  FUN_0059d0a0(unaff_RBX + 0x60);
  FUN_005249f0(unaff_RBX + 0x58);
  QWidget::~QWidget(unaff_RBX);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004cc106 name=FUN_004cc106 size=26 ====

void FUN_004cc106(void)

{
  undefined8 in_stack_00000008;
  
  FUN_00556570(in_stack_00000008);
  FUN_005249f0();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004cc120 name=FUN_004cc120 size=18 ====

void FUN_004cc120(void)

{
  undefined8 in_stack_00000008;
  
  FUN_00556570(in_stack_00000008);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004cc132 name=FUN_004cc132 size=21 ====

void FUN_004cc132(void)

{
  undefined8 *unaff_RBX;
  
  if ((void *)*unaff_RBX != (void *)0x0) {
    operator_delete((void *)*unaff_RBX);
  }
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004cc148 name=FUN_004cc148 size=57 ====

void FUN_004cc148(void)

{
  QPixmap *unaff_R14;
  undefined8 in_stack_00000078;
  undefined8 in_stack_00000080;
  QIcon *in_stack_00000088;
  
  QPixmap::~QPixmap(unaff_R14);
  FUN_00525060(in_stack_00000078);
  QIcon::~QIcon(in_stack_00000088);
  FUN_005249f0(in_stack_00000080);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004cc181 name=FUN_004cc181 size=22 ====

void FUN_004cc181(void)

{
  long unaff_R14;
  
  __cxa_begin_catch();
  FUN_005249f0(unaff_R14 + 0x18);
                    /* WARNING: Subroutine does not return */
                    /* try { // try from 004cc192 to 004cc196 has its CatchHandler @ 004cc1a6 */
  __cxa_rethrow();
}


// ==== entry=004cc197 name=FUN_004cc197 size=15 ====

void FUN_004cc197(void)

{
  void *unaff_RBP;
  undefined8 in_stack_00000078;
  undefined8 in_stack_00000080;
  QIcon *in_stack_00000088;
  
  operator_delete(unaff_RBP,0x20);
  FUN_00525060(in_stack_00000078);
  QIcon::~QIcon(in_stack_00000088);
  FUN_005249f0(in_stack_00000080);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004cc1f1 name=FUN_004cc1f1 size=33 ====

void FUN_004cc1f1(void)

{
  QVariant *unaff_R14;
  QVariant *in_stack_00000028;
  undefined8 in_stack_00000030;
  undefined8 in_stack_00000080;
  QIcon *in_stack_00000088;
  
  QVariant::~QVariant(unaff_R14);
  FUN_005249f0(in_stack_00000030);
  QVariant::~QVariant(in_stack_00000028);
  QIcon::~QIcon(in_stack_00000088);
  FUN_005249f0(in_stack_00000080);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004cc212 name=FUN_004cc212 size=20 ====

void FUN_004cc212(void)

{
  QVariant *unaff_R14;
  QVariant *in_stack_00000028;
  undefined8 in_stack_00000030;
  undefined8 in_stack_00000080;
  QIcon *in_stack_00000088;
  
  QVariant::~QVariant(unaff_R14);
  FUN_005249f0(in_stack_00000030);
  QVariant::~QVariant(in_stack_00000028);
  QIcon::~QIcon(in_stack_00000088);
  FUN_005249f0(in_stack_00000080);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004cc226 name=FUN_004cc226 size=33 ====

void FUN_004cc226(void)

{
  QVariant *unaff_R14;
  QVariant *in_stack_00000028;
  undefined8 in_stack_00000030;
  undefined8 in_stack_00000078;
  undefined8 in_stack_00000080;
  QIcon *in_stack_00000088;
  
  QVariant::~QVariant(unaff_R14);
  FUN_005249f0(in_stack_00000030);
  QVariant::~QVariant(in_stack_00000028);
  FUN_00525060(in_stack_00000078);
  QIcon::~QIcon(in_stack_00000088);
  FUN_005249f0(in_stack_00000080);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004cc247 name=FUN_004cc247 size=21 ====

void FUN_004cc247(void)

{
  QVariant *unaff_R14;
  undefined8 in_stack_00000078;
  undefined8 in_stack_00000080;
  QIcon *in_stack_00000088;
  
  QVariant::~QVariant(unaff_R14);
  FUN_005249f0();
  FUN_00525060(in_stack_00000078);
  QIcon::~QIcon(in_stack_00000088);
  FUN_005249f0(in_stack_00000080);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004cc25c name=FUN_004cc25c size=13 ====

void FUN_004cc25c(void)

{
  undefined8 in_stack_00000078;
  undefined8 in_stack_00000080;
  QIcon *in_stack_00000088;
  
  FUN_005249f0();
  FUN_00525060(in_stack_00000078);
  QIcon::~QIcon(in_stack_00000088);
  FUN_005249f0(in_stack_00000080);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004cc269 name=FUN_004cc269 size=20 ====

void FUN_004cc269(void)

{
  void *in_stack_00000060;
  undefined8 in_stack_00000078;
  undefined8 in_stack_00000080;
  QIcon *in_stack_00000088;
  
  operator_delete(in_stack_00000060,0x30);
  FUN_00525060(in_stack_00000078);
  QIcon::~QIcon(in_stack_00000088);
  FUN_005249f0(in_stack_00000080);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004cc27d name=FUN_004cc27d size=46 ====

void FUN_004cc27d(void)

{
  QVariant *unaff_R14;
  QVariant *in_stack_00000028;
  undefined8 in_stack_00000030;
  undefined8 in_stack_00000058;
  
  FUN_005249f0(in_stack_00000030);
  QVariant::~QVariant(unaff_R14);
  FUN_005249f0(in_stack_00000058);
  QVariant::~QVariant(in_stack_00000028);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004cc2ab name=FUN_004cc2ab size=36 ====

void FUN_004cc2ab(void)

{
  QVariant *unaff_R14;
  QVariant *in_stack_00000028;
  undefined8 in_stack_00000030;
  
  QVariant::~QVariant(unaff_R14);
  FUN_005249f0(in_stack_00000030);
  QVariant::~QVariant(in_stack_00000028);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004cc2cf name=FUN_004cc2cf size=43 ====

void FUN_004cc2cf(void)

{
  QVariant *unaff_R14;
  QVariant *in_stack_00000028;
  undefined8 in_stack_00000030;
  QIcon *in_stack_00000078;
  undefined8 in_stack_00000080;
  
  QIcon::~QIcon(in_stack_00000078);
  QVariant::~QVariant(unaff_R14);
  FUN_005249f0(in_stack_00000030);
  QVariant::~QVariant(in_stack_00000028);
  FUN_005249f0(in_stack_00000080);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004cc2fa name=FUN_004cc2fa size=23 ====

void FUN_004cc2fa(void)

{
  QVariant *unaff_R14;
  QVariant *in_stack_00000028;
  undefined8 in_stack_00000030;
  undefined8 in_stack_00000080;
  QIcon *in_stack_00000088;
  
  QVariant::~QVariant(unaff_R14);
  FUN_005249f0(in_stack_00000030);
  QVariant::~QVariant(in_stack_00000028);
  QIcon::~QIcon(in_stack_00000088);
  FUN_005249f0(in_stack_00000080);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004cc311 name=FUN_004cc311 size=55 ====

void FUN_004cc311(void)

{
  QDateTime *unaff_R12;
  undefined8 in_stack_00000078;
  undefined8 in_stack_00000080;
  QIcon *in_stack_00000088;
  undefined8 in_stack_00000098;
  
  FUN_005249f0();
  FUN_005249f0(in_stack_00000098);
  FUN_005249f0();
  QDateTime::~QDateTime(unaff_R12);
  FUN_005249f0(&stack0x000000f8);
  FUN_00525060(in_stack_00000078);
  QIcon::~QIcon(in_stack_00000088);
  FUN_005249f0(in_stack_00000080);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004cc348 name=FUN_004cc348 size=20 ====

void FUN_004cc348(void)

{
  void *in_stack_00000070;
  undefined8 in_stack_00000078;
  undefined8 in_stack_00000080;
  QIcon *in_stack_00000088;
  
  operator_delete(in_stack_00000070,0x30);
  FUN_00525060(in_stack_00000078);
  QIcon::~QIcon(in_stack_00000088);
  FUN_005249f0(in_stack_00000080);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004cc35c name=FUN_004cc35c size=20 ====

void FUN_004cc35c(void)

{
  void *in_stack_00000050;
  undefined8 in_stack_00000078;
  undefined8 in_stack_00000080;
  QIcon *in_stack_00000088;
  
  operator_delete(in_stack_00000050,0x30);
  FUN_00525060(in_stack_00000078);
  QIcon::~QIcon(in_stack_00000088);
  FUN_005249f0(in_stack_00000080);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004cc370 name=FUN_004cc370 size=16 ====

void FUN_004cc370(void)

{
  FUN_005249f0();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004cc380 name=FUN_004cc380 size=16 ====

void FUN_004cc380(void)

{
  FUN_005249f0();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004cc390 name=FUN_004cc390 size=32 ====

void FUN_004cc390(void)

{
  QIcon *unaff_R14;
  
  QIcon::~QIcon(unaff_R14);
  FUN_005249f0();
  FUN_005249f0();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004cc3b0 name=FUN_004cc3b0 size=32 ====

void FUN_004cc3b0(void)

{
  QVariant *unaff_RBP;
  QVariant *unaff_R15;
  
  QVariant::~QVariant(unaff_RBP);
  FUN_005249f0();
  QVariant::~QVariant(unaff_R15);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004cc3d0 name=FUN_004cc3d0 size=16 ====

void FUN_004cc3d0(void)

{
  FUN_005249f0();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004cc3e0 name=FUN_004cc3e0 size=32 ====

void FUN_004cc3e0(void)

{
  QVariant *unaff_RBP;
  QVariant *unaff_R14;
  
  QVariant::~QVariant(unaff_RBP);
  FUN_005249f0();
  QVariant::~QVariant(unaff_R14);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004cc400 name=FUN_004cc400 size=21 ====

void FUN_004cc400(void)

{
  void *unaff_RBX;
  
  operator_delete(unaff_RBX,0x20);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004cc416 name=FUN_004cc416 size=16 ====

void FUN_004cc416(void)

{
  QFrame *unaff_RBX;
  
  QFrame::~QFrame(unaff_RBX);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004cc426 name=FUN_004cc426 size=46 ====

void FUN_004cc426(void)

{
  FUN_00550ea0(&stack0x00000058);
  FUN_00550ea0(&stack0x00000038);
  FUN_00550ea0(&stack0x00000018);
  FUN_00550ea0(&stack0x00000000);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004cc454 name=FUN_004cc454 size=78 ====

void FUN_004cc454(void)

{
  QRegion *unaff_R13;
  QRegion *unaff_R14;
  QRegion *in_stack_00000010;
  QArrayData *in_stack_00000048;
  
  QRegion::~QRegion(in_stack_00000010);
  QRegion::~QRegion(unaff_R14);
  QRegion::~QRegion(unaff_R13);
  if (*(int *)in_stack_00000048 != 0) {
    if (*(int *)in_stack_00000048 == -1) goto LAB_004cc488;
    LOCK();
    *(int *)in_stack_00000048 = *(int *)in_stack_00000048 + -1;
    UNLOCK();
    if (*(int *)in_stack_00000048 != 0) goto LAB_004cc488;
  }
  QArrayData::deallocate(in_stack_00000048,8,8);
LAB_004cc488:
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004cc4a2 name=FUN_004cc4a2 size=16 ====

void FUN_004cc4a2(void)

{
  FUN_005a1bac();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004cc4b2 name=FUN_004cc4b2 size=69 ====

void FUN_004cc4b2(void)

{
  QStyleOption *unaff_R14;
  QArrayData *in_stack_00000048;
  
  QIcon::~QIcon((QIcon *)(unaff_R14 + 0x50));
  if (*(int *)in_stack_00000048 != 0) {
    if (*(int *)in_stack_00000048 == -1) goto LAB_004cc4d5;
    LOCK();
    *(int *)in_stack_00000048 = *(int *)in_stack_00000048 + -1;
    UNLOCK();
    if (*(int *)in_stack_00000048 != 0) goto LAB_004cc4d5;
  }
  QArrayData::deallocate(in_stack_00000048,2,8);
LAB_004cc4d5:
  QStyleOption::~QStyleOption(unaff_R14);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004cc4f8 name=FUN_004cc4f8 size=16 ====

void FUN_004cc4f8(void)

{
  QPalette *unaff_R13;
  
  QPalette::~QPalette(unaff_R13);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004cc508 name=FUN_004cc508 size=24 ====

void FUN_004cc508(void)

{
  QBrush *unaff_R12;
  QPen *unaff_R14;
  
  QBrush::~QBrush(unaff_R12);
  QPen::~QPen(unaff_R14);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004cc520 name=FUN_004cc520 size=16 ====

void FUN_004cc520(void)

{
  FUN_00550ec0();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004cc530 name=FUN_004cc530 size=24 ====

void FUN_004cc530(void)

{
  QVariant *unaff_R15;
  
  QVariant::~QVariant(unaff_R15);
  FUN_00550ec0();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004cc548 name=FUN_004cc548 size=24 ====

void FUN_004cc548(void)

{
  QVariant *unaff_RBX;
  
  QVariant::~QVariant(unaff_RBX);
  FUN_00550ec0();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004cc560 name=FUN_004cc560 size=21 ====

void FUN_004cc560(void)

{
  void *unaff_RBP;
  
  operator_delete(unaff_RBP,0x30);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004cc575 name=FUN_004cc575 size=21 ====

void FUN_004cc575(void)

{
  void *unaff_RBP;
  
  operator_delete(unaff_RBP,0x20);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004cc58a name=FUN_004cc58a size=16 ====

void FUN_004cc58a(void)

{
  QWidget *unaff_RBX;
  
  QWidget::~QWidget(unaff_RBX);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004cc59a name=FUN_004cc59a size=21 ====

void FUN_004cc59a(void)

{
  void *unaff_R13;
  
  operator_delete(unaff_R13,0x30);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004cc5af name=FUN_004cc5af size=18 ====

void FUN_004cc5af(void)

{
  long *unaff_R13;
  
  (**(code **)(*unaff_R13 + 0x20))();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004cc5c2 name=FUN_004cc5c2 size=81 ====

void FUN_004cc5c2(void)

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
  FUN_00c86f70();
}


// ==== entry=004cc613 name=FUN_004cc613 size=75 ====

void FUN_004cc613(void)

{
  void *unaff_R13;
  char in_stack_00000040;
  code *in_stack_00000058;
  code *in_stack_00000060;
  
  operator_delete(unaff_R13,0x30);
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
  FUN_00c86f70();
}


// ==== entry=004cc65e name=FUN_004cc65e size=22 ====

void FUN_004cc65e(void)

{
  void *unaff_retaddr;
  
  operator_delete(unaff_retaddr,0x30);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004cc674 name=FUN_004cc674 size=13 ====

void FUN_004cc674(void)

{
  __cxa_begin_catch();
                    /* WARNING: Subroutine does not return */
                    /* try { // try from 004cc67c to 004cc680 has its CatchHandler @ 004cc681 */
  __cxa_rethrow();
}


// ==== entry=004cc69a name=FUN_004cc69a size=16 ====

void FUN_004cc69a(void)

{
  FUN_00550ec0();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004cc6b0 name=FUN_004cc6b0 size=27 ====

void FUN_004cc6b0(void)

{
  QStatusBar *unaff_RBX;
  
  FUN_005249f0();
  QStatusBar::~QStatusBar(unaff_RBX);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004cc6cc name=FUN_004cc6cc size=21 ====

void FUN_004cc6cc(void)

{
  void *unaff_R15;
  
  operator_delete(unaff_R15,0x20);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004cc6e1 name=FUN_004cc6e1 size=37 ====

void FUN_004cc6e1(void)

{
  void *unaff_R13;
  
  operator_delete(unaff_R13,0x30);
  FUN_005249f0();
  FUN_005249f0();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004cc706 name=FUN_004cc706 size=32 ====

void FUN_004cc706(void)

{
  QJSValue *unaff_RBX;
  QJSValue *unaff_R12;
  
  FUN_00544630();
  QJSValue::~QJSValue(unaff_R12);
  QJSValue::~QJSValue(unaff_RBX);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004cc726 name=FUN_004cc726 size=85 ====

void FUN_004cc726(void)

{
  QVariant *unaff_RBX;
  long unaff_R15;
  QJSValue *in_stack_00000038;
  undefined8 in_stack_00000048;
  undefined8 in_stack_00000050;
  undefined8 in_stack_00000058;
  undefined8 in_stack_00000060;
  undefined8 in_stack_00000068;
  
  FUN_005249f0(unaff_R15 + 0x18);
  FUN_005249f0(in_stack_00000060);
  FUN_005249f0(in_stack_00000068);
  QJSValue::~QJSValue(in_stack_00000038);
  FUN_005249f0(in_stack_00000048);
  FUN_005249f0(in_stack_00000058);
  FUN_005249f0(in_stack_00000050);
  QVariant::~QVariant(unaff_RBX);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004cc77b name=FUN_004cc77b size=10 ====

void FUN_004cc77b(void)

{
  QVariant *unaff_RBX;
  QJSValue *in_stack_00000038;
  undefined8 in_stack_00000048;
  undefined8 in_stack_00000050;
  undefined8 in_stack_00000058;
  undefined8 in_stack_00000060;
  undefined8 in_stack_00000068;
  
  FUN_005249f0();
  FUN_005249f0(in_stack_00000060);
  FUN_005249f0(in_stack_00000068);
  QJSValue::~QJSValue(in_stack_00000038);
  FUN_005249f0(in_stack_00000048);
  FUN_005249f0(in_stack_00000058);
  FUN_005249f0(in_stack_00000050);
  QVariant::~QVariant(unaff_RBX);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004cc785 name=FUN_004cc785 size=31 ====

void FUN_004cc785(void)

{
  QVariant *unaff_RBX;
  QVariant *unaff_R15;
  QVariant *in_stack_00000020;
  QJSValue *in_stack_00000038;
  undefined8 in_stack_00000048;
  undefined8 in_stack_00000050;
  undefined8 in_stack_00000058;
  undefined8 in_stack_00000068;
  
  QVariant::~QVariant(unaff_R15);
  FUN_005249f0();
  QVariant::~QVariant(in_stack_00000020);
  FUN_005249f0(in_stack_00000068);
  QJSValue::~QJSValue(in_stack_00000038);
  FUN_005249f0(in_stack_00000048);
  FUN_005249f0(in_stack_00000058);
  FUN_005249f0(in_stack_00000050);
  QVariant::~QVariant(unaff_RBX);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004cc7a4 name=FUN_004cc7a4 size=14 ====

void FUN_004cc7a4(void)

{
  QVariant *unaff_RBX;
  undefined8 in_stack_00000048;
  undefined8 in_stack_00000050;
  
  FUN_005249c0(in_stack_00000048);
  FUN_005249f0(in_stack_00000050);
  QVariant::~QVariant(unaff_RBX);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004cc7b2 name=FUN_004cc7b2 size=12 ====

void FUN_004cc7b2(void)

{
  QVariant *unaff_RBX;
  undefined8 in_stack_00000038;
  undefined8 in_stack_00000050;
  
  FUN_005249c0(in_stack_00000038);
  FUN_005249f0(in_stack_00000050);
  QVariant::~QVariant(unaff_RBX);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004cc7be name=FUN_004cc7be size=15 ====

void FUN_004cc7be(void)

{
  QVariant *unaff_RBX;
  undefined8 in_stack_00000020;
  QJSValue *in_stack_00000038;
  undefined8 in_stack_00000048;
  undefined8 in_stack_00000050;
  undefined8 in_stack_00000058;
  undefined8 in_stack_00000060;
  undefined8 in_stack_00000068;
  
  FUN_00528c1c(in_stack_00000020);
  FUN_005249f0(in_stack_00000060);
  FUN_005249f0(in_stack_00000068);
  QJSValue::~QJSValue(in_stack_00000038);
  FUN_005249f0(in_stack_00000048);
  FUN_005249f0(in_stack_00000058);
  FUN_005249f0(in_stack_00000050);
  QVariant::~QVariant(unaff_RBX);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004cc7cd name=FUN_004cc7cd size=22 ====

void FUN_004cc7cd(void)

{
  long unaff_R13;
  
  __cxa_begin_catch();
  FUN_005249f0(unaff_R13 + 0x18);
                    /* WARNING: Subroutine does not return */
                    /* try { // try from 004cc7de to 004cc7e2 has its CatchHandler @ 004cc7e3 */
  __cxa_rethrow();
}


// ==== entry=004cc803 name=FUN_004cc803 size=18 ====

void FUN_004cc803(void)

{
  QVariant *unaff_RBX;
  void *unaff_R13;
  undefined8 in_stack_00000050;
  
  operator_delete(unaff_R13,0x40);
  FUN_005249f0(in_stack_00000050);
  QVariant::~QVariant(unaff_RBX);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004cc845 name=FUN_004cc845 size=16 ====

void FUN_004cc845(void)

{
  QVariant *unaff_RBX;
  undefined8 in_stack_00000050;
  undefined8 in_stack_00000060;
  
  FUN_005249c0(in_stack_00000060);
  FUN_005249f0(in_stack_00000050);
  QVariant::~QVariant(unaff_RBX);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004cc855 name=FUN_004cc855 size=34 ====

void FUN_004cc855(void)

{
  QVariant *unaff_RBX;
  QVariant *unaff_R15;
  QVariant *in_stack_00000020;
  QJSValue *in_stack_00000038;
  undefined8 in_stack_00000048;
  undefined8 in_stack_00000050;
  undefined8 in_stack_00000058;
  
  QVariant::~QVariant(unaff_R15);
  FUN_005249f0();
  QVariant::~QVariant(in_stack_00000020);
  QJSValue::~QJSValue(in_stack_00000038);
  FUN_005249f0(in_stack_00000048);
  FUN_005249f0(in_stack_00000058);
  FUN_005249f0(in_stack_00000050);
  QVariant::~QVariant(unaff_RBX);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004cc877 name=FUN_004cc877 size=34 ====

void FUN_004cc877(void)

{
  QVariant *unaff_RBX;
  QVariant *unaff_R15;
  QVariant *in_stack_00000020;
  undefined8 in_stack_00000050;
  
  QVariant::~QVariant(unaff_R15);
  FUN_005249f0();
  QVariant::~QVariant(in_stack_00000020);
  FUN_005249f0(in_stack_00000050);
  QVariant::~QVariant(unaff_RBX);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004cc899 name=FUN_004cc899 size=34 ====

void FUN_004cc899(void)

{
  QVariant *unaff_RBX;
  QVariant *unaff_R15;
  QVariant *in_stack_00000020;
  undefined8 in_stack_00000050;
  undefined8 in_stack_00000058;
  
  QVariant::~QVariant(unaff_R15);
  FUN_005249f0();
  QVariant::~QVariant(in_stack_00000020);
  FUN_005249f0(in_stack_00000058);
  FUN_005249f0(in_stack_00000050);
  QVariant::~QVariant(unaff_RBX);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004cc8bb name=FUN_004cc8bb size=18 ====

void FUN_004cc8bb(void)

{
  QVariant *unaff_RBX;
  void *unaff_R13;
  undefined8 in_stack_00000050;
  
  operator_delete(unaff_R13,0x30);
  FUN_005249f0(in_stack_00000050);
  QVariant::~QVariant(unaff_RBX);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004cc8cd name=FUN_004cc8cd size=13 ====

void FUN_004cc8cd(void)

{
  QVariant *unaff_RBX;
  QCursor *unaff_R15;
  undefined8 in_stack_00000050;
  
  QCursor::~QCursor(unaff_R15);
  FUN_005249f0(in_stack_00000050);
  QVariant::~QVariant(unaff_RBX);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004cc8da name=FUN_004cc8da size=34 ====

void FUN_004cc8da(void)

{
  QVariant *unaff_RBX;
  QVariant *unaff_R15;
  QVariant *in_stack_00000020;
  
  QVariant::~QVariant(unaff_R15);
  FUN_005249f0();
  QVariant::~QVariant(in_stack_00000020);
  QVariant::~QVariant(unaff_RBX);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004cc8fc name=FUN_004cc8fc size=16 ====

void FUN_004cc8fc(void)

{
  FUN_00528c1c();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004cc90c name=FUN_004cc90c size=24 ====

void FUN_004cc90c(void)

{
  QVariant *unaff_RBP;
  
  QVariant::~QVariant(unaff_RBP);
  FUN_005249f0();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004cc924 name=FUN_004cc924 size=21 ====

void FUN_004cc924(void)

{
  FUN_00534d80();
  FUN_005249f0();
  FUN_005249f0();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004cc939 name=FUN_004cc939 size=10 ====

void FUN_004cc939(void)

{
  FUN_005249f0();
  FUN_005249f0();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004cc943 name=FUN_004cc943 size=15 ====

void FUN_004cc943(void)

{
  FUN_00534d80();
  FUN_005249f0();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004cc952 name=FUN_004cc952 size=16 ====

void FUN_004cc952(void)

{
  QVariant *unaff_RBP;
  
  QVariant::~QVariant(unaff_RBP);
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004cc962 name=FUN_004cc962 size=16 ====

void FUN_004cc962(void)

{
  FUN_005249f0();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004cc972 name=FUN_004cc972 size=16 ====

void FUN_004cc972(void)

{
  FUN_005249f0();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004cc982 name=FUN_004cc982 size=16 ====

void FUN_004cc982(void)

{
  FUN_005249f0();
                    /* WARNING: Subroutine does not return */
  FUN_00c86f70();
}


// ==== entry=004cc9a0 name=FUN_004cc9a0 size=56 ====

void FUN_004cc9a0(undefined8 *param_1)

{
  int *piVar1;
  
  piVar1 = (int *)*param_1;
  if (*piVar1 != 0) {
    if (*piVar1 == -1) goto LAB_004cc9ca;
    LOCK();
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if (*piVar1 != 0) goto LAB_004cc9ca;
  }
  QArrayData::deallocate((QArrayData *)*param_1,2,8);
LAB_004cc9ca:
  operator_delete(param_1,8);
  return;
}


