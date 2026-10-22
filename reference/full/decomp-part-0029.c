// Ghidra 12.1.4 decompiled — WindTerm 2.7.0 (sha256 9491b87e…) part 29
// ==== entry=008f18c2 orig=FUN_008f18c2 size=120 name=TransferLabel_qt_metacall ====

ulong TransferLabel_qt_metacall
                (undefined8 param_1,int param_2,undefined8 param_3,undefined8 param_4)

{
  int iVar1;
  ulong uVar2;
  
  uVar2 = QFrame::qt_metacall();
  iVar1 = (int)uVar2;
  if (-1 < iVar1) {
    if ((param_2 - 1U < 3) || (param_2 == 0xb)) {
      FUN_008f17d8(param_1,param_2,uVar2 & 0xffffffff,param_4);
      return (ulong)(iVar1 - 1);
    }
    if ((((param_2 == 4) || (param_2 == 5)) || (param_2 == 6)) || ((param_2 == 7 || (param_2 == 8)))
       ) {
      return (ulong)(iVar1 - 1);
    }
  }
  return uVar2;
}


// ==== entry=008f193a orig=FUN_008f193a size=104 name=TransferLabel_dtor ====

void TransferLabel_dtor(QFrame *param_1)

{
  QArrayData *pQVar1;
  
  *(undefined ***)param_1 = &TransferLabel_vtable;
  *(undefined ***)(param_1 + 0x10) = &PTR_FUN_011964e8;
  QBrush::~QBrush((QBrush *)(param_1 + 0x40));
  QBrush::~QBrush((QBrush *)(param_1 + 0x38));
  pQVar1 = *(QArrayData **)(param_1 + 0x30);
  if (*(int *)pQVar1 == 0) {
LAB_008f198a:
    QArrayData::deallocate(pQVar1,2,8);
    QFrame::~QFrame(param_1);
    return;
  }
  if (*(int *)pQVar1 != -1) {
    LOCK();
    *(int *)pQVar1 = *(int *)pQVar1 + -1;
    UNLOCK();
    if (*(int *)pQVar1 == 0) {
      pQVar1 = *(QArrayData **)(param_1 + 0x30);
      goto LAB_008f198a;
    }
  }
  QFrame::~QFrame(param_1);
  return;
}


// ==== entry=008f19a2 name=FUN_008f19a2 size=106 ====

void FUN_008f19a2(undefined8 *param_1)

{
  QArrayData *pQVar1;
  
  param_1[-2] = &TransferLabel_vtable;
  *param_1 = &PTR_FUN_011964e8;
  QBrush::~QBrush((QBrush *)(param_1 + 6));
  QBrush::~QBrush((QBrush *)(param_1 + 5));
  pQVar1 = (QArrayData *)param_1[4];
  if (*(int *)pQVar1 == 0) {
LAB_008f19f3:
    QArrayData::deallocate(pQVar1,2,8);
    QFrame::~QFrame((QFrame *)(param_1 + -2));
    return;
  }
  if (*(int *)pQVar1 != -1) {
    LOCK();
    *(int *)pQVar1 = *(int *)pQVar1 + -1;
    UNLOCK();
    if (*(int *)pQVar1 == 0) {
      pQVar1 = (QArrayData *)param_1[4];
      goto LAB_008f19f3;
    }
  }
  QFrame::~QFrame((QFrame *)(param_1 + -2));
  return;
}


// ==== entry=008f1a0c name=FUN_008f1a0c size=124 ====

void FUN_008f1a0c(undefined8 *param_1)

{
  QArrayData *pQVar1;
  
  param_1[-2] = &TransferLabel_vtable;
  *param_1 = &PTR_FUN_011964e8;
  QBrush::~QBrush((QBrush *)(param_1 + 6));
  QBrush::~QBrush((QBrush *)(param_1 + 5));
  pQVar1 = (QArrayData *)param_1[4];
  if (*(int *)pQVar1 != 0) {
    if (*(int *)pQVar1 == -1) goto LAB_008f1a58;
    LOCK();
    *(int *)pQVar1 = *(int *)pQVar1 + -1;
    UNLOCK();
    if (*(int *)pQVar1 != 0) goto LAB_008f1a58;
    pQVar1 = (QArrayData *)param_1[4];
  }
  QArrayData::deallocate(pQVar1,2,8);
LAB_008f1a58:
  QFrame::~QFrame((QFrame *)(param_1 + -2));
  operator_delete((QFrame *)(param_1 + -2),0x88);
  return;
}


// ==== entry=008f1a88 orig=FUN_008f1a88 size=110 name=TransferLabel_dtor_deleting ====

void TransferLabel_dtor_deleting(QFrame *param_1)

{
  QArrayData *pQVar1;
  
  *(undefined ***)param_1 = &TransferLabel_vtable;
  *(undefined ***)(param_1 + 0x10) = &PTR_FUN_011964e8;
  QBrush::~QBrush((QBrush *)(param_1 + 0x40));
  QBrush::~QBrush((QBrush *)(param_1 + 0x38));
  pQVar1 = *(QArrayData **)(param_1 + 0x30);
  if (*(int *)pQVar1 != 0) {
    if (*(int *)pQVar1 == -1) goto LAB_008f1acb;
    LOCK();
    *(int *)pQVar1 = *(int *)pQVar1 + -1;
    UNLOCK();
    if (*(int *)pQVar1 != 0) goto LAB_008f1acb;
    pQVar1 = *(QArrayData **)(param_1 + 0x30);
  }
  QArrayData::deallocate(pQVar1,2,8);
LAB_008f1acb:
  QFrame::~QFrame(param_1);
  operator_delete(param_1,0x88);
  return;
}


// ==== entry=008f1b00 orig=FUN_008f1b00 size=24 name=TransferBar_metaObject ====

undefined ** TransferBar_metaObject(long param_1)

{
  undefined **ppuVar1;
  
  if (*(long *)(*(long *)(param_1 + 8) + 0x28) != 0) {
    ppuVar1 = (undefined **)QObjectData::dynamicMetaObject();
    return ppuVar1;
  }
  return &PTR_staticMetaObject_011967a0;
}


// ==== entry=008f1b18 name=FUN_008f1b18 size=16 ====

void FUN_008f1b18(QObject *param_1)

{
  QMetaObject::activate(param_1,(QMetaObject *)&PTR_staticMetaObject_011967a0,0,(void **)0x0);
  return;
}


// ==== entry=008f1b28 name=FUN_008f1b28 size=52 ====

void FUN_008f1b28(undefined8 param_1,int param_2,int param_3,undefined8 *param_4)

{
  if (param_2 == 0) {
    if (param_3 == 0) {
      FUN_008f1b18();
      return;
    }
  }
  else if (((param_2 == 10) && (*(code **)param_4[1] == FUN_008f1b18)) &&
          (((long *)param_4[1])[1] == 0)) {
    *(undefined4 *)*param_4 = 0;
    return;
  }
  return;
}


// ==== entry=008f1b5c orig=FUN_008f1b5c size=66 name=TransferBar_qt_metacast ====

char * TransferBar_qt_metacast(char *param_1,char *param_2)

{
  int iVar1;
  char *pcVar2;
  
  if (param_2 == (char *)0x0) {
    return (char *)0x0;
  }
  iVar1 = strcmp(param_2,"TransferBar");
  if (iVar1 == 0) {
    return param_1;
  }
  pcVar2 = (char *)QWidget::qt_metacast(param_1);
  return pcVar2;
}


// ==== entry=008f1b9e orig=FUN_008f1b9e size=87 name=TransferBar_qt_metacall ====

ulong TransferBar_qt_metacall(undefined8 param_1,int param_2,undefined8 param_3,undefined8 *param_4)

{
  int iVar1;
  ulong uVar2;
  
  uVar2 = QWidget::qt_metacall();
  iVar1 = (int)uVar2;
  if (-1 < iVar1) {
    if (param_2 == 0) {
      if (iVar1 == 0) {
        FUN_008f1b18(param_1);
        uVar2 = uVar2 & 0xffffffff;
      }
    }
    else {
      if (param_2 != 0xc) {
        return uVar2;
      }
      if (iVar1 == 0) {
        *(undefined4 *)*param_4 = 0xffffffff;
      }
    }
    uVar2 = (ulong)((int)uVar2 - 1);
  }
  return uVar2;
}


// ==== entry=008f1bf6 orig=FUN_008f1bf6 size=92 name=TransferBar_dtor_deleting ====

void TransferBar_dtor_deleting(QWidget *param_1)

{
  QArrayData *pQVar1;
  
  *(undefined ***)param_1 = &TransferBar_vtable;
  *(undefined ***)(param_1 + 0x10) = &PTR_FUN_01196748;
  pQVar1 = *(QArrayData **)(param_1 + 0x50);
  if (*(int *)pQVar1 != 0) {
    if (*(int *)pQVar1 == -1) goto LAB_008f1c27;
    LOCK();
    *(int *)pQVar1 = *(int *)pQVar1 + -1;
    UNLOCK();
    if (*(int *)pQVar1 != 0) goto LAB_008f1c27;
    pQVar1 = *(QArrayData **)(param_1 + 0x50);
  }
  QArrayData::deallocate(pQVar1,2,8);
LAB_008f1c27:
  QWidget::~QWidget(param_1);
  operator_delete(param_1,0x58);
  return;
}


// ==== entry=008f1c52 name=FUN_008f1c52 size=96 ====

void FUN_008f1c52(undefined8 *param_1)

{
  QArrayData *pQVar1;
  
  param_1[-2] = &TransferBar_vtable;
  *param_1 = &PTR_FUN_01196748;
  pQVar1 = (QArrayData *)param_1[8];
  if (*(int *)pQVar1 != 0) {
    if (*(int *)pQVar1 == -1) goto LAB_008f1c84;
    LOCK();
    *(int *)pQVar1 = *(int *)pQVar1 + -1;
    UNLOCK();
    if (*(int *)pQVar1 != 0) goto LAB_008f1c84;
    pQVar1 = (QArrayData *)param_1[8];
  }
  QArrayData::deallocate(pQVar1,2,8);
LAB_008f1c84:
  QWidget::~QWidget((QWidget *)(param_1 + -2));
  operator_delete((QWidget *)(param_1 + -2),0x58);
  return;
}


// ==== entry=008f1cb2 name=FUN_008f1cb2 size=88 ====

void FUN_008f1cb2(undefined8 *param_1)

{
  QArrayData *pQVar1;
  
  param_1[-2] = &TransferBar_vtable;
  *param_1 = &PTR_FUN_01196748;
  pQVar1 = (QArrayData *)param_1[8];
  if (*(int *)pQVar1 == 0) {
LAB_008f1cf1:
    QArrayData::deallocate(pQVar1,2,8);
    QWidget::~QWidget((QWidget *)(param_1 + -2));
    return;
  }
  if (*(int *)pQVar1 != -1) {
    LOCK();
    *(int *)pQVar1 = *(int *)pQVar1 + -1;
    UNLOCK();
    if (*(int *)pQVar1 == 0) {
      pQVar1 = (QArrayData *)param_1[8];
      goto LAB_008f1cf1;
    }
  }
  QWidget::~QWidget((QWidget *)(param_1 + -2));
  return;
}


// ==== entry=008f1d0a orig=FUN_008f1d0a size=86 name=TransferBar_dtor ====

void TransferBar_dtor(QWidget *param_1)

{
  QArrayData *pQVar1;
  
  *(undefined ***)param_1 = &TransferBar_vtable;
  *(undefined ***)(param_1 + 0x10) = &PTR_FUN_01196748;
  pQVar1 = *(QArrayData **)(param_1 + 0x50);
  if (*(int *)pQVar1 == 0) {
LAB_008f1d48:
    QArrayData::deallocate(pQVar1,2,8);
    QWidget::~QWidget(param_1);
    return;
  }
  if (*(int *)pQVar1 != -1) {
    LOCK();
    *(int *)pQVar1 = *(int *)pQVar1 + -1;
    UNLOCK();
    if (*(int *)pQVar1 == 0) {
      pQVar1 = *(QArrayData **)(param_1 + 0x50);
      goto LAB_008f1d48;
    }
  }
  QWidget::~QWidget(param_1);
  return;
}


// ==== entry=008f1d60 name=FUN_008f1d60 size=1 ====

void FUN_008f1d60(void)

{
  return;
}


// ==== entry=008f1d62 name=FUN_008f1d62 size=24 ====

undefined ** FUN_008f1d62(long param_1)

{
  undefined **ppuVar1;
  
  if (*(long *)(*(long *)(param_1 + 8) + 0x28) != 0) {
    ppuVar1 = (undefined **)QObjectData::dynamicMetaObject();
    return ppuVar1;
  }
  return &PTR_PTR_011968c0;
}


// ==== entry=008f1d7a orig=FUN_008f1d7a size=66 name=EditDelegate_dtor ====

undefined8 EditDelegate_dtor(undefined8 param_1,char *param_2)

{
  int iVar1;
  undefined8 uVar2;
  
  if (param_2 == (char *)0x0) {
    return 0;
  }
  iVar1 = strcmp(param_2,"TreeItemDelegate");
  if (iVar1 == 0) {
    return param_1;
  }
  uVar2 = s_EditDelegate_8f993c(param_1,param_2);
  return uVar2;
}


// ==== entry=008f1dbc orig=FUN_008f1dbc size=5 name=EditDelegate_dtor_deleting ====

ulong EditDelegate_dtor_deleting
                (undefined8 param_1,int param_2,undefined8 param_3,undefined8 *param_4)

{
  int iVar1;
  ulong uVar2;
  
  uVar2 = QStyledItemDelegate::qt_metacall();
  iVar1 = (int)uVar2;
  if (-1 < iVar1) {
    if (param_2 == 0) {
      if (iVar1 == 0) {
        FUN_008f98b8(param_1,*(undefined8 *)param_4[1],param_4[2],param_4[3]);
        uVar2 = uVar2 & 0xffffffff;
      }
    }
    else {
      if (param_2 != 0xc) {
        return uVar2;
      }
      if (iVar1 == 0) {
        *(undefined4 *)*param_4 = 0xffffffff;
      }
    }
    uVar2 = (ulong)((int)uVar2 - 1);
  }
  return uVar2;
}


// ==== entry=008f1dc2 orig=FUN_008f1dc2 size=458 name=TreeItemDelegate_dtor ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void TreeItemDelegate_dtor(QStyledItemDelegate *param_1)

{
  code *pcVar1;
  int *piVar2;
  int iVar3;
  long lVar4;
  _func_void_Node_ptr *p_Var5;
  Data *pDVar6;
  QArrayData *pQVar7;
  
  *(undefined ***)param_1 = &TreeItemDelegate_vtable;
  lVar4 = *(long *)(param_1 + 0xa0);
  while (lVar4 != 0) {
    if (*(long **)(lVar4 + 8) != (long *)0x0) {
      (**(code **)(**(long **)(lVar4 + 8) + 8))();
      lVar4 = *(long *)(param_1 + 0xa0);
    }
    lVar4 = *(long *)(lVar4 + 0x20);
    *(long *)(param_1 + 0xa0) = lVar4;
  }
  p_Var5 = *(_func_void_Node_ptr **)(param_1 + 0xb0);
  *(undefined8 **)(param_1 + 0xb0) = &QHashData::shared_null;
  pcVar1 = p_Var5 + 0x10;
  if (*(int *)(p_Var5 + 0x10) == 0) {
LAB_008f1f12:
    QHashData::free_helper(p_Var5);
    if (_display != 0) goto LAB_008f1e49;
LAB_008f1f29:
    QHashData::free_helper((_func_void_Node_ptr *)&QHashData::shared_null);
  }
  else {
    if (*(int *)(p_Var5 + 0x10) != -1) {
      LOCK();
      *(int *)pcVar1 = *(int *)pcVar1 + -1;
      UNLOCK();
      if (*(int *)pcVar1 == 0) goto LAB_008f1f12;
    }
    if (_display == 0) goto LAB_008f1f29;
LAB_008f1e49:
    if (_display != -1) {
      LOCK();
      _display = _display + -1;
      UNLOCK();
      if (_display == 0) goto LAB_008f1f29;
    }
  }
  *(undefined8 *)(param_1 + 0xa8) = 0;
  *(undefined4 *)(param_1 + 0xbc) = 0;
  p_Var5 = *(_func_void_Node_ptr **)(param_1 + 0xb0);
  pcVar1 = p_Var5 + 0x10;
  if (*(int *)(p_Var5 + 0x10) == 0) {
LAB_008f1f44:
    QHashData::free_helper(p_Var5);
    pDVar6 = *(Data **)(param_1 + 0x90);
    iVar3 = *(int *)pDVar6;
    if (iVar3 != 0) goto LAB_008f1ea4;
LAB_008f1f61:
    QListData::dispose(pDVar6);
  }
  else {
    if (*(int *)(p_Var5 + 0x10) != -1) {
      LOCK();
      *(int *)pcVar1 = *(int *)pcVar1 + -1;
      UNLOCK();
      if (*(int *)pcVar1 == 0) {
        p_Var5 = *(_func_void_Node_ptr **)(param_1 + 0xb0);
        goto LAB_008f1f44;
      }
    }
    pDVar6 = *(Data **)(param_1 + 0x90);
    iVar3 = *(int *)pDVar6;
    if (iVar3 == 0) goto LAB_008f1f61;
LAB_008f1ea4:
    if (iVar3 != -1) {
      LOCK();
      *(int *)pDVar6 = *(int *)pDVar6 + -1;
      UNLOCK();
      if (*(int *)pDVar6 == 0) {
        pDVar6 = *(Data **)(param_1 + 0x90);
        goto LAB_008f1f61;
      }
    }
  }
  QPixmap::~QPixmap((QPixmap *)(param_1 + 0x60));
  *(undefined ***)param_1 = &PTR_FUN_0119c0d8;
  pQVar7 = *(QArrayData **)(param_1 + 0x38);
  if (*(int *)pQVar7 != 0) {
    if (*(int *)pQVar7 == -1) goto LAB_008f1ee7;
    LOCK();
    *(int *)pQVar7 = *(int *)pQVar7 + -1;
    UNLOCK();
    if (*(int *)pQVar7 != 0) goto LAB_008f1ee7;
    pQVar7 = *(QArrayData **)(param_1 + 0x38);
  }
  QArrayData::deallocate(pQVar7,2,8);
LAB_008f1ee7:
  piVar2 = *(int **)(param_1 + 0x10);
  if (piVar2 != (int *)0x0) {
    LOCK();
    *piVar2 = *piVar2 + -1;
    UNLOCK();
    if ((*piVar2 == 0) && (*(void **)(param_1 + 0x10) != (void *)0x0)) {
      operator_delete(*(void **)(param_1 + 0x10));
    }
  }
  QStyledItemDelegate::~QStyledItemDelegate(param_1);
  return;
}


// ==== entry=008f1f8c orig=FUN_008f1f8c size=471 name=TreeItemDelegate_dtor_deleting ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void TreeItemDelegate_dtor_deleting(QStyledItemDelegate *param_1)

{
  code *pcVar1;
  int *piVar2;
  int iVar3;
  long lVar4;
  _func_void_Node_ptr *p_Var5;
  Data *pDVar6;
  QArrayData *pQVar7;
  
  *(undefined ***)param_1 = &TreeItemDelegate_vtable;
  lVar4 = *(long *)(param_1 + 0xa0);
  while (lVar4 != 0) {
    if (*(long **)(lVar4 + 8) != (long *)0x0) {
      (**(code **)(**(long **)(lVar4 + 8) + 8))();
      lVar4 = *(long *)(param_1 + 0xa0);
    }
    lVar4 = *(long *)(lVar4 + 0x20);
    *(long *)(param_1 + 0xa0) = lVar4;
  }
  p_Var5 = *(_func_void_Node_ptr **)(param_1 + 0xb0);
  *(undefined8 **)(param_1 + 0xb0) = &QHashData::shared_null;
  pcVar1 = p_Var5 + 0x10;
  if (*(int *)(p_Var5 + 0x10) == 0) {
LAB_008f20e9:
    QHashData::free_helper(p_Var5);
    if (_display != 0) goto LAB_008f2013;
LAB_008f2100:
    QHashData::free_helper((_func_void_Node_ptr *)&QHashData::shared_null);
  }
  else {
    if (*(int *)(p_Var5 + 0x10) != -1) {
      LOCK();
      *(int *)pcVar1 = *(int *)pcVar1 + -1;
      UNLOCK();
      if (*(int *)pcVar1 == 0) goto LAB_008f20e9;
    }
    if (_display == 0) goto LAB_008f2100;
LAB_008f2013:
    if (_display != -1) {
      LOCK();
      _display = _display + -1;
      UNLOCK();
      if (_display == 0) goto LAB_008f2100;
    }
  }
  *(undefined8 *)(param_1 + 0xa8) = 0;
  *(undefined4 *)(param_1 + 0xbc) = 0;
  p_Var5 = *(_func_void_Node_ptr **)(param_1 + 0xb0);
  pcVar1 = p_Var5 + 0x10;
  if (*(int *)(p_Var5 + 0x10) == 0) {
LAB_008f211b:
    QHashData::free_helper(p_Var5);
    pDVar6 = *(Data **)(param_1 + 0x90);
    iVar3 = *(int *)pDVar6;
    if (iVar3 != 0) goto LAB_008f206e;
LAB_008f2138:
    QListData::dispose(pDVar6);
  }
  else {
    if (*(int *)(p_Var5 + 0x10) != -1) {
      LOCK();
      *(int *)pcVar1 = *(int *)pcVar1 + -1;
      UNLOCK();
      if (*(int *)pcVar1 == 0) {
        p_Var5 = *(_func_void_Node_ptr **)(param_1 + 0xb0);
        goto LAB_008f211b;
      }
    }
    pDVar6 = *(Data **)(param_1 + 0x90);
    iVar3 = *(int *)pDVar6;
    if (iVar3 == 0) goto LAB_008f2138;
LAB_008f206e:
    if (iVar3 != -1) {
      LOCK();
      *(int *)pDVar6 = *(int *)pDVar6 + -1;
      UNLOCK();
      if (*(int *)pDVar6 == 0) {
        pDVar6 = *(Data **)(param_1 + 0x90);
        goto LAB_008f2138;
      }
    }
  }
  QPixmap::~QPixmap((QPixmap *)(param_1 + 0x60));
  *(undefined ***)param_1 = &PTR_FUN_0119c0d8;
  pQVar7 = *(QArrayData **)(param_1 + 0x38);
  if (*(int *)pQVar7 != 0) {
    if (*(int *)pQVar7 == -1) goto LAB_008f20b1;
    LOCK();
    *(int *)pQVar7 = *(int *)pQVar7 + -1;
    UNLOCK();
    if (*(int *)pQVar7 != 0) goto LAB_008f20b1;
    pQVar7 = *(QArrayData **)(param_1 + 0x38);
  }
  QArrayData::deallocate(pQVar7,2,8);
LAB_008f20b1:
  piVar2 = *(int **)(param_1 + 0x10);
  if (piVar2 != (int *)0x0) {
    LOCK();
    *piVar2 = *piVar2 + -1;
    UNLOCK();
    if ((*piVar2 == 0) && (*(void **)(param_1 + 0x10) != (void *)0x0)) {
      operator_delete(*(void **)(param_1 + 0x10));
    }
  }
  QStyledItemDelegate::~QStyledItemDelegate(param_1);
  operator_delete(param_1,0xc0);
  return;
}


// ==== entry=008f2170 orig=FUN_008f2170 size=24 name=ScrollBar_metaObject ====

undefined ** ScrollBar_metaObject(long param_1)

{
  undefined **ppuVar1;
  
  if (*(long *)(*(long *)(param_1 + 8) + 0x28) != 0) {
    ppuVar1 = (undefined **)QObjectData::dynamicMetaObject();
    return ppuVar1;
  }
  return &PTR_staticMetaObject_01196b20;
}


// ==== entry=008f2188 name=FUN_008f2188 size=51 ====

void FUN_008f2188(QObject *param_1,undefined4 param_2)

{
  undefined4 local_1c;
  void *local_18;
  undefined4 *local_10;
  
  local_18 = (void *)0x0;
  local_10 = &local_1c;
  local_1c = param_2;
  QMetaObject::activate(param_1,(QMetaObject *)&PTR_staticMetaObject_01196b20,0,&local_18);
  return;
}


// ==== entry=008f21bc name=FUN_008f21bc size=54 ====

void FUN_008f21bc(QObject *param_1,undefined4 param_2)

{
  undefined4 local_1c;
  void *local_18;
  undefined4 *local_10;
  
  local_18 = (void *)0x0;
  local_10 = &local_1c;
  local_1c = param_2;
  QMetaObject::activate(param_1,(QMetaObject *)&PTR_staticMetaObject_01196b20,2,&local_18);
  return;
}


// ==== entry=008f21f2 name=FUN_008f21f2 size=67 ====

void FUN_008f21f2(QObject *param_1,undefined8 param_2,undefined8 param_3)

{
  undefined8 local_38;
  undefined8 local_30;
  void *local_28;
  undefined8 *local_20;
  undefined1 *local_18;
  
  local_18 = (undefined1 *)&local_38;
  local_28 = (void *)0x0;
  local_20 = &local_30;
  local_38 = param_3;
  local_30 = param_2;
  QMetaObject::activate(param_1,(QMetaObject *)&PTR_staticMetaObject_01196b20,1,&local_28);
  return;
}


// ==== entry=008f2236 name=FUN_008f2236 size=67 ====

void FUN_008f2236(QObject *param_1,undefined8 param_2,undefined8 param_3)

{
  undefined8 local_38;
  undefined8 local_30;
  void *local_28;
  undefined8 *local_20;
  undefined1 *local_18;
  
  local_18 = (undefined1 *)&local_38;
  local_28 = (void *)0x0;
  local_20 = &local_30;
  local_38 = param_3;
  local_30 = param_2;
  QMetaObject::activate(param_1,(QMetaObject *)&PTR_staticMetaObject_01196b20,3,&local_28);
  return;
}


// ==== entry=008f227a name=FUN_008f227a size=85 ====

void FUN_008f227a(undefined8 param_1,int param_2,long param_3)

{
  if (param_2 == 1) {
    FUN_008f21f2(param_1,**(undefined8 **)(param_3 + 8),**(undefined8 **)(param_3 + 0x10));
    return;
  }
  if (param_2 < 2) {
    if (param_2 == 0) {
      FUN_008f2188(param_1,**(undefined4 **)(param_3 + 8));
      return;
    }
    return;
  }
  if (param_2 == 2) {
    FUN_008f21bc(param_1,**(undefined4 **)(param_3 + 8));
    return;
  }
  if (param_2 == 3) {
    FUN_008f2236(param_1,**(undefined8 **)(param_3 + 8),**(undefined8 **)(param_3 + 0x10));
    return;
  }
  return;
}


// ==== entry=008f22d0 name=FUN_008f22d0 size=121 ====

void FUN_008f22d0(undefined8 param_1,int param_2,undefined4 param_3,undefined8 *param_4)

{
  undefined4 *puVar1;
  long *plVar2;
  code *pcVar3;
  
  if (param_2 == 0) {
    FUN_008f227a(param_1,param_3,param_4);
    return;
  }
  if (param_2 == 10) {
    puVar1 = (undefined4 *)*param_4;
    plVar2 = (long *)param_4[1];
    pcVar3 = (code *)*plVar2;
    if ((pcVar3 == FUN_008f2188) && (plVar2[1] == 0)) {
      *puVar1 = 0;
      return;
    }
    if ((pcVar3 == FUN_008f21f2) && (plVar2[1] == 0)) {
      *puVar1 = 1;
      return;
    }
    if ((pcVar3 == FUN_008f21bc) && (plVar2[1] == 0)) {
      *puVar1 = 2;
      return;
    }
    if ((pcVar3 == FUN_008f2236) && (plVar2[1] == 0)) {
      *puVar1 = 3;
      return;
    }
  }
  return;
}


// ==== entry=008f234a orig=FUN_008f234a size=66 name=ScrollBar_qt_metacast ====

char * ScrollBar_qt_metacast(char *param_1,char *param_2)

{
  int iVar1;
  char *pcVar2;
  
  if (param_2 == (char *)0x0) {
    return (char *)0x0;
  }
  iVar1 = strcmp(param_2,"ScrollBar");
  if (iVar1 == 0) {
    return param_1;
  }
  pcVar2 = (char *)QScrollBar::qt_metacast(param_1);
  return pcVar2;
}


// ==== entry=008f238c orig=FUN_008f238c size=95 name=ScrollBar_qt_metacall ====

ulong ScrollBar_qt_metacall(undefined8 param_1,int param_2,undefined8 param_3,undefined8 *param_4)

{
  int iVar1;
  ulong uVar2;
  
  uVar2 = QScrollBar::qt_metacall();
  iVar1 = (int)uVar2;
  if (-1 < iVar1) {
    if (param_2 == 0) {
      if (iVar1 < 4) {
        FUN_008f227a(param_1,uVar2 & 0xffffffff,param_4);
        uVar2 = uVar2 & 0xffffffff;
      }
    }
    else {
      if (param_2 != 0xc) {
        return uVar2;
      }
      if (iVar1 < 4) {
        *(undefined4 *)*param_4 = 0xffffffff;
      }
    }
    uVar2 = (ulong)((int)uVar2 - 4);
  }
  return uVar2;
}


// ==== entry=008f23ec orig=FUN_008f23ec size=29 name=ScrollBar_dtor ====

void ScrollBar_dtor(QScrollBar *param_1)

{
  *(undefined ***)param_1 = &ScrollBar_vtable;
  *(undefined ***)(param_1 + 0x10) = &PTR_FUN_01196ad0;
  QScrollBar::~QScrollBar(param_1);
  return;
}


// ==== entry=008f2409 name=FUN_008f2409 size=33 ====

void FUN_008f2409(undefined8 *param_1)

{
  param_1[-2] = &ScrollBar_vtable;
  *param_1 = &PTR_FUN_01196ad0;
  QScrollBar::~QScrollBar((QScrollBar *)(param_1 + -2));
  return;
}


// ==== entry=008f242a orig=FUN_008f242a size=47 name=ScrollBar_dtor_deleting ====

void ScrollBar_dtor_deleting(QScrollBar *param_1)

{
  *(undefined ***)param_1 = &ScrollBar_vtable;
  *(undefined ***)(param_1 + 0x10) = &PTR_FUN_01196ad0;
  QScrollBar::~QScrollBar(param_1);
  operator_delete(param_1,0x48);
  return;
}


// ==== entry=008f2459 name=FUN_008f2459 size=51 ====

void FUN_008f2459(undefined8 *param_1)

{
  param_1[-2] = &ScrollBar_vtable;
  *param_1 = &PTR_FUN_01196ad0;
  QScrollBar::~QScrollBar((QScrollBar *)(param_1 + -2));
  operator_delete((QScrollBar *)(param_1 + -2),0x48);
  return;
}


// ==== entry=008f2490 name=FUN_008f2490 size=24 ====

undefined ** FUN_008f2490(long param_1)

{
  undefined **ppuVar1;
  
  if (*(long *)(*(long *)(param_1 + 8) + 0x28) != 0) {
    ppuVar1 = (undefined **)QObjectData::dynamicMetaObject();
    return ppuVar1;
  }
  return &PTR_staticMetaObject_01196d80;
}


// ==== entry=008f24a8 name=FUN_008f24a8 size=56 ====

void FUN_008f24a8(undefined8 param_1,int param_2,int param_3,long param_4)

{
  if (param_2 == 0) {
    if (param_3 == 1) {
      FUN_005a2e58(param_1,*(undefined8 *)(param_4 + 8),0);
      return;
    }
    if (param_3 == 2) {
      FUN_005a6552();
      return;
    }
    if (param_3 == 0) {
      FUN_005a2e58(param_1,*(undefined8 *)(param_4 + 8),**(undefined4 **)(param_4 + 0x10));
      return;
    }
  }
  return;
}


// ==== entry=008f24e0 name=FUN_008f24e0 size=66 ====

char * FUN_008f24e0(char *param_1,char *param_2)

{
  int iVar1;
  char *pcVar2;
  
  if (param_2 == (char *)0x0) {
    return (char *)0x0;
  }
  iVar1 = strcmp(param_2,"StatusBar");
  if (iVar1 == 0) {
    return param_1;
  }
  pcVar2 = (char *)QStatusBar::qt_metacast(param_1);
  return pcVar2;
}


// ==== entry=008f2522 name=FUN_008f2522 size=93 ====

ulong FUN_008f2522(undefined8 param_1,int param_2,undefined8 param_3,undefined8 *param_4)

{
  int iVar1;
  ulong uVar2;
  
  uVar2 = QStatusBar::qt_metacall();
  iVar1 = (int)uVar2;
  if (-1 < iVar1) {
    if (param_2 == 0) {
      if (iVar1 < 3) {
        FUN_008f24a8(param_1,0,uVar2 & 0xffffffff,param_4);
        uVar2 = uVar2 & 0xffffffff;
      }
    }
    else {
      if (param_2 != 0xc) {
        return uVar2;
      }
      if (iVar1 < 3) {
        *(undefined4 *)*param_4 = 0xffffffff;
      }
    }
    uVar2 = (ulong)((int)uVar2 - 3);
  }
  return uVar2;
}


// ==== entry=008f2580 name=FUN_008f2580 size=29 ====

void FUN_008f2580(QStatusBar *param_1)

{
  *(undefined ***)param_1 = &PTR_FUN_01196b78;
  *(undefined ***)(param_1 + 0x10) = &PTR_FUN_01196d28;
  QStatusBar::~QStatusBar(param_1);
  return;
}


// ==== entry=008f259d name=FUN_008f259d size=33 ====

void FUN_008f259d(undefined8 *param_1)

{
  param_1[-2] = &PTR_FUN_01196b78;
  *param_1 = &PTR_FUN_01196d28;
  QStatusBar::~QStatusBar((QStatusBar *)(param_1 + -2));
  return;
}


// ==== entry=008f25be name=FUN_008f25be size=47 ====

void FUN_008f25be(QStatusBar *param_1)

{
  *(undefined ***)param_1 = &PTR_FUN_01196b78;
  *(undefined ***)(param_1 + 0x10) = &PTR_FUN_01196d28;
  QStatusBar::~QStatusBar(param_1);
  operator_delete(param_1,0x48);
  return;
}


// ==== entry=008f25ed name=FUN_008f25ed size=51 ====

void FUN_008f25ed(undefined8 *param_1)

{
  param_1[-2] = &PTR_FUN_01196b78;
  *param_1 = &PTR_FUN_01196d28;
  QStatusBar::~QStatusBar((QStatusBar *)(param_1 + -2));
  operator_delete((QStatusBar *)(param_1 + -2),0x48);
  return;
}


// ==== entry=008f2620 name=FUN_008f2620 size=24 ====

undefined ** FUN_008f2620(long param_1)

{
  undefined **ppuVar1;
  
  if (*(long *)(*(long *)(param_1 + 8) + 0x28) != 0) {
    ppuVar1 = (undefined **)QObjectData::dynamicMetaObject();
    return ppuVar1;
  }
  return &PTR_PTR_011973e0;
}


// ==== entry=008f2638 orig=FUN_008f2638 size=66 name=TextView_dtor ====

undefined8 TextView_dtor(undefined8 param_1,char *param_2)

{
  int iVar1;
  undefined8 uVar2;
  
  if (param_2 == (char *)0x0) {
    return 0;
  }
  iVar1 = strcmp(param_2,"TextEdit");
  if (iVar1 == 0) {
    return param_1;
  }
  uVar2 = ScintillaEditWatcher_dtor_deleting(param_1,param_2);
  return uVar2;
}


// ==== entry=008f267a name=FUN_008f267a size=1263 ====

void FUN_008f267a(undefined8 param_1,int param_2,undefined4 param_3,long *param_4)

{
  undefined8 *puVar1;
  undefined1 uVar2;
  undefined8 uVar3;
  QArrayData *local_20 [2];
  
  if (param_2 != 0) {
switchD_008f269c_default:
    return;
  }
  switch(param_3) {
  case 0:
    FUN_005cac40();
    break;
  case 1:
    uVar2 = FUN_005cacb6();
    if ((undefined1 *)*param_4 != (undefined1 *)0x0) {
      *(undefined1 *)*param_4 = uVar2;
    }
    break;
  case 2:
    uVar2 = FUN_005cad46(param_1,*(undefined1 *)param_4[1]);
    if ((undefined1 *)*param_4 != (undefined1 *)0x0) {
      *(undefined1 *)*param_4 = uVar2;
    }
    break;
  case 3:
    FUN_005cade2();
    break;
  case 4:
    FUN_005cae58();
    break;
  case 5:
    FUN_005caece();
    break;
  case 6:
    FUN_005cafba();
    break;
  case 7:
    FUN_005cb030(param_1,*(undefined8 *)param_4[1]);
    break;
  case 8:
    FUN_005cb030(param_1,0xffffffffffffffff);
    break;
  case 9:
    FUN_005cb0b2();
    break;
  case 10:
    FUN_005cb128();
    break;
  case 0xb:
    FUN_005cb19e();
    break;
  case 0xc:
    FUN_005cb214();
    break;
  case 0xd:
    FUN_005cb28a();
    break;
  case 0xe:
    FUN_005cb300();
    break;
  case 0xf:
    FUN_005cb376();
    break;
  case 0x10:
    FUN_005cb3ec();
    break;
  case 0x11:
    FUN_005cb462();
    break;
  case 0x12:
    uVar2 = FUN_005cb54e(param_1,param_4[1]);
    if ((undefined1 *)*param_4 != (undefined1 *)0x0) {
      *(undefined1 *)*param_4 = uVar2;
    }
    break;
  case 0x13:
    local_20[0] = (QArrayData *)&QArrayData::shared_null;
                    /* try { // try from 008f27d7 to 008f27db has its CatchHandler @ 008f2b69 */
    uVar2 = FUN_005cb54e(param_1,local_20);
    if (*(int *)local_20[0] == 0) {
LAB_008f2b55:
      QArrayData::deallocate(local_20[0],1,8);
    }
    else if (*(int *)local_20[0] != -1) {
      LOCK();
      *(int *)local_20[0] = *(int *)local_20[0] + -1;
      UNLOCK();
      if (*(int *)local_20[0] == 0) goto LAB_008f2b55;
    }
    if ((undefined1 *)*param_4 != (undefined1 *)0x0) {
      *(undefined1 *)*param_4 = uVar2;
    }
    break;
  case 0x14:
    FUN_005cb662();
    break;
  case 0x15:
    FUN_005cb6d8(param_1,*(undefined8 *)param_4[1]);
    break;
  case 0x16:
    FUN_005cb6d8(param_1,0xffffffffffffffff);
    break;
  case 0x17:
    FUN_005cb7d4(param_1,*(undefined8 *)param_4[1],param_4[2]);
    break;
  case 0x18:
    FUN_005cb75a(param_1,*(undefined8 *)param_4[1],param_4[2]);
    break;
  case 0x19:
    uVar2 = FUN_005cba16();
    if ((undefined1 *)*param_4 != (undefined1 *)0x0) {
      *(undefined1 *)*param_4 = uVar2;
    }
    break;
  case 0x1a:
    uVar2 = FUN_005cbaa6();
    if ((undefined1 *)*param_4 != (undefined1 *)0x0) {
      *(undefined1 *)*param_4 = uVar2;
    }
    break;
  case 0x1b:
    FUN_005cbbc6();
    break;
  case 0x1c:
    FUN_005cbc3c();
    break;
  case 0x1d:
    FUN_005cbcb2();
    break;
  case 0x1e:
    FUN_005cbd28();
    break;
  case 0x1f:
    FUN_005cbd9e();
    break;
  case 0x20:
    FUN_005cbe14(param_1,*(undefined4 *)param_4[1]);
    break;
  case 0x21:
    FUN_005cbe14(param_1,1);
    break;
  case 0x22:
    uVar3 = FUN_005cc4d4();
    puVar1 = (undefined8 *)*param_4;
    goto joined_r0x008f2b45;
  case 0x23:
    FUN_005cc94e(param_1,*(undefined4 *)param_4[1]);
    break;
  case 0x24:
    FUN_005cc7f6(param_1,*(undefined8 *)param_4[1],*(undefined8 *)param_4[2],param_4[3]);
    break;
  case 0x25:
    FUN_005cc6f0(param_1,*(undefined8 *)param_4[1],*(undefined8 *)param_4[2],param_4[3]);
    break;
  case 0x26:
    FUN_005d0a4e();
    break;
  case 0x27:
    FUN_005cbf24(param_1,*(undefined1 *)param_4[1]);
    break;
  case 0x28:
    FUN_005cbf24(param_1,1);
    break;
  case 0x29:
    FUN_005cc026(param_1,*(undefined1 *)param_4[1]);
    break;
  case 0x2a:
    FUN_005cc0ac(param_1,*(undefined1 *)param_4[1]);
    break;
  case 0x2b:
    FUN_005cebe6();
    break;
  case 0x2c:
    FUN_005d28b6(param_1,*(undefined4 *)param_4[1]);
    break;
  case 0x2d:
    FUN_005cc0b6();
    break;
  case 0x2e:
    FUN_005cc188(param_1,*(undefined4 *)param_4[1]);
    break;
  case 0x2f:
    FUN_005cc188(param_1,1);
    break;
  case 0x30:
    FUN_005cc20a(param_1,*(undefined4 *)param_4[1]);
    break;
  case 0x31:
    FUN_005cc20a(param_1,1);
    break;
  case 0x32:
    FUN_005cc28c(param_1,*(undefined4 *)param_4[1]);
    break;
  case 0x33:
    FUN_005cc28c(param_1,1);
    break;
  case 0x34:
    FUN_005cc406(param_1,*(undefined8 *)param_4[1],*(undefined8 *)param_4[2]);
    break;
  case 0x35:
    FUN_005cc406(param_1,*(undefined8 *)param_4[1],0xffffffffffffffff);
    break;
  case 0x36:
    FUN_005cc406(param_1,0xffffffffffffffff);
    break;
  case 0x37:
    FUN_005cc30e(param_1,*(undefined8 *)param_4[1],*(undefined8 *)param_4[2]);
    break;
  case 0x38:
    FUN_005cc30e(param_1,*(undefined8 *)param_4[1],0xffffffffffffffff);
    break;
  case 0x39:
    FUN_005cc30e(param_1,0xffffffffffffffff);
    break;
  case 0x3a:
    FUN_005cc38a(param_1,*(undefined8 *)param_4[1],*(undefined8 *)param_4[2]);
    break;
  case 0x3b:
    FUN_005cc38a(param_1,*(undefined8 *)param_4[1],0xffffffffffffffff);
    break;
  case 0x3c:
    FUN_005cc38a(param_1,0xffffffffffffffff);
    break;
  case 0x3d:
    FUN_005cc42a();
    break;
  case 0x3e:
    FUN_005cc4de(param_1,*(undefined4 *)param_4[1]);
    break;
  case 0x3f:
    FUN_005cc4de(param_1,1);
    break;
  case 0x40:
    uVar3 = FUN_005cc578();
    puVar1 = (undefined8 *)*param_4;
joined_r0x008f2b45:
    if (puVar1 != (undefined8 *)0x0) {
      *puVar1 = uVar3;
    }
    break;
  case 0x41:
    FUN_005cc61e();
    break;
  default:
    goto switchD_008f269c_default;
  }
  return;
}


// ==== entry=008f2b72 orig=FUN_008f2b72 size=93 name=TextView_dtor_deleting ====

ulong TextView_dtor_deleting(undefined8 param_1,int param_2,undefined8 param_3,undefined8 *param_4)

{
  int iVar1;
  ulong uVar2;
  
  uVar2 = FUN_008f64ce();
  iVar1 = (int)uVar2;
  if (-1 < iVar1) {
    if (param_2 == 0) {
      if (iVar1 < 0x42) {
        FUN_008f267a(param_1,0,uVar2 & 0xffffffff,param_4);
        uVar2 = uVar2 & 0xffffffff;
      }
    }
    else {
      if (param_2 != 0xc) {
        return uVar2;
      }
      if (iVar1 < 0x42) {
        *(undefined4 *)*param_4 = 0xffffffff;
      }
    }
    uVar2 = (ulong)((int)uVar2 - 0x42);
  }
  return uVar2;
}


// ==== entry=008f2bd0 name=FUN_008f2bd0 size=1 ====

void FUN_008f2bd0(void)

{
  return;
}


// ==== entry=008f2bd2 name=FUN_008f2bd2 size=1 ====

void FUN_008f2bd2(void)

{
  return;
}


// ==== entry=008f2bd4 name=FUN_008f2bd4 size=1 ====

void FUN_008f2bd4(void)

{
  return;
}


// ==== entry=008f2bd6 name=FUN_008f2bd6 size=1 ====

void FUN_008f2bd6(void)

{
  return;
}


// ==== entry=008f2bd8 name=FUN_008f2bd8 size=1 ====

void FUN_008f2bd8(void)

{
  return;
}


// ==== entry=008f2bda name=FUN_008f2bda size=1 ====

void FUN_008f2bda(void)

{
  return;
}


// ==== entry=008f2bdc orig=FUN_008f2bdc size=40 name=TextEdit_dtor ====

void TextEdit_dtor(undefined8 *param_1)

{
  *param_1 = &TextEdit_vtable;
  param_1[2] = &PTR_FUN_01197198;
  param_1[9] = &PTR_FUN_011971e8;
  FUN_005d4b56();
  return;
}


// ==== entry=008f2c04 name=FUN_008f2c04 size=44 ====

void FUN_008f2c04(undefined8 *param_1)

{
  param_1[-9] = &TextEdit_vtable;
  param_1[-7] = &PTR_FUN_01197198;
  *param_1 = &PTR_FUN_011971e8;
  FUN_005d4b56(param_1 + -9);
  return;
}


// ==== entry=008f2c30 name=FUN_008f2c30 size=44 ====

void FUN_008f2c30(undefined8 *param_1)

{
  param_1[-2] = &TextEdit_vtable;
  *param_1 = &PTR_FUN_01197198;
  param_1[7] = &PTR_FUN_011971e8;
  FUN_005d4b56(param_1 + -2);
  return;
}


// ==== entry=008f2c5c orig=FUN_008f2c5c size=58 name=TextEdit_dtor_deleting ====

void TextEdit_dtor_deleting(undefined8 *param_1)

{
  *param_1 = &TextEdit_vtable;
  param_1[2] = &PTR_FUN_01197198;
  param_1[9] = &PTR_FUN_011971e8;
  FUN_005d4b56();
  operator_delete(param_1,0x100);
  return;
}


// ==== entry=008f2c96 name=FUN_008f2c96 size=62 ====

void FUN_008f2c96(undefined8 *param_1)

{
  param_1[-9] = &TextEdit_vtable;
  param_1[-7] = &PTR_FUN_01197198;
  *param_1 = &PTR_FUN_011971e8;
  FUN_005d4b56(param_1 + -9);
  operator_delete(param_1 + -9,0x100);
  return;
}


// ==== entry=008f2cd4 name=FUN_008f2cd4 size=62 ====

void FUN_008f2cd4(undefined8 *param_1)

{
  param_1[-2] = &TextEdit_vtable;
  *param_1 = &PTR_FUN_01197198;
  param_1[7] = &PTR_FUN_011971e8;
  FUN_005d4b56(param_1 + -2);
  operator_delete(param_1 + -2,0x100);
  return;
}


// ==== entry=008f2d20 orig=FUN_008f2d20 size=24 name=ScintillaEditWatcher_dtor ====

undefined ** ScintillaEditWatcher_dtor(long param_1)

{
  undefined **ppuVar1;
  
  if (*(long *)(*(long *)(param_1 + 8) + 0x28) != 0) {
    ppuVar1 = (undefined **)QObjectData::dynamicMetaObject();
    return ppuVar1;
  }
  return &PTR_PTR_01197a60;
}


// ==== entry=008f2d38 name=FUN_008f2d38 size=19 ====

void FUN_008f2d38(QObject *param_1)

{
  QMetaObject::activate(param_1,(QMetaObject *)&PTR_PTR_01197a60,5,(void **)0x0);
  return;
}


// ==== entry=008f2d4c name=FUN_008f2d4c size=19 ====

void FUN_008f2d4c(QObject *param_1)

{
  QMetaObject::activate(param_1,(QMetaObject *)&PTR_PTR_01197a60,7,(void **)0x0);
  return;
}


// ==== entry=008f2d60 name=FUN_008f2d60 size=19 ====

void FUN_008f2d60(QObject *param_1)

{
  QMetaObject::activate(param_1,(QMetaObject *)&PTR_PTR_01197a60,8,(void **)0x0);
  return;
}


// ==== entry=008f2d74 name=FUN_008f2d74 size=19 ====

void FUN_008f2d74(QObject *param_1)

{
  QMetaObject::activate(param_1,(QMetaObject *)&PTR_PTR_01197a60,0x11,(void **)0x0);
  return;
}


// ==== entry=008f2d88 name=FUN_008f2d88 size=19 ====

void FUN_008f2d88(QObject *param_1)

{
  QMetaObject::activate(param_1,(QMetaObject *)&PTR_PTR_01197a60,0x12,(void **)0x0);
  return;
}


// ==== entry=008f2d9c name=FUN_008f2d9c size=19 ====

void FUN_008f2d9c(QObject *param_1)

{
  QMetaObject::activate(param_1,(QMetaObject *)&PTR_PTR_01197a60,0x13,(void **)0x0);
  return;
}


// ==== entry=008f2db0 name=FUN_008f2db0 size=19 ====

void FUN_008f2db0(QObject *param_1)

{
  QMetaObject::activate(param_1,(QMetaObject *)&PTR_PTR_01197a60,0x14,(void **)0x0);
  return;
}


// ==== entry=008f2dc4 name=FUN_008f2dc4 size=19 ====

void FUN_008f2dc4(QObject *param_1)

{
  QMetaObject::activate(param_1,(QMetaObject *)&PTR_PTR_01197a60,0x15,(void **)0x0);
  return;
}


// ==== entry=008f2dd8 name=FUN_008f2dd8 size=19 ====

void FUN_008f2dd8(QObject *param_1)

{
  QMetaObject::activate(param_1,(QMetaObject *)&PTR_PTR_01197a60,0x16,(void **)0x0);
  return;
}


// ==== entry=008f2dec name=FUN_008f2dec size=19 ====

void FUN_008f2dec(QObject *param_1)

{
  QMetaObject::activate(param_1,(QMetaObject *)&PTR_PTR_01197a60,0x17,(void **)0x0);
  return;
}


// ==== entry=008f2e00 name=FUN_008f2e00 size=19 ====

void FUN_008f2e00(QObject *param_1)

{
  QMetaObject::activate(param_1,(QMetaObject *)&PTR_PTR_01197a60,0x18,(void **)0x0);
  return;
}


// ==== entry=008f2e14 name=FUN_008f2e14 size=19 ====

void FUN_008f2e14(QObject *param_1)

{
  QMetaObject::activate(param_1,(QMetaObject *)&PTR_PTR_01197a60,0x2a,(void **)0x0);
  return;
}


// ==== entry=008f2e28 name=FUN_008f2e28 size=19 ====

void FUN_008f2e28(QObject *param_1)

{
  QMetaObject::activate(param_1,(QMetaObject *)&PTR_PTR_01197a60,0x2b,(void **)0x0);
  return;
}


// ==== entry=008f2e3c name=FUN_008f2e3c size=19 ====

void FUN_008f2e3c(QObject *param_1)

{
  QMetaObject::activate(param_1,(QMetaObject *)&PTR_PTR_01197a60,0x2c,(void **)0x0);
  return;
}


// ==== entry=008f2e50 name=FUN_008f2e50 size=19 ====

void FUN_008f2e50(QObject *param_1)

{
  QMetaObject::activate(param_1,(QMetaObject *)&PTR_PTR_01197a60,0x31,(void **)0x0);
  return;
}


// ==== entry=008f2e64 name=FUN_008f2e64 size=19 ====

void FUN_008f2e64(QObject *param_1)

{
  QMetaObject::activate(param_1,(QMetaObject *)&PTR_PTR_01197a60,0x32,(void **)0x0);
  return;
}


// ==== entry=008f2e78 name=FUN_008f2e78 size=19 ====

void FUN_008f2e78(QObject *param_1)

{
  QMetaObject::activate(param_1,(QMetaObject *)&PTR_PTR_01197a60,0x33,(void **)0x0);
  return;
}


// ==== entry=008f2e8c name=FUN_008f2e8c size=19 ====

void FUN_008f2e8c(QObject *param_1)

{
  QMetaObject::activate(param_1,(QMetaObject *)&PTR_PTR_01197a60,0x39,(void **)0x0);
  return;
}


// ==== entry=008f2ea0 name=FUN_008f2ea0 size=52 ====

void FUN_008f2ea0(QObject *param_1,undefined8 param_2)

{
  undefined8 local_20;
  void *local_18;
  undefined8 *local_10;
  
  local_18 = (void *)0x0;
  local_10 = &local_20;
  local_20 = param_2;
  QMetaObject::activate(param_1,(QMetaObject *)&PTR_PTR_01197a60,0,&local_18);
  return;
}


// ==== entry=008f2ed4 name=FUN_008f2ed4 size=42 ====

void FUN_008f2ed4(QObject *param_1,undefined8 param_2)

{
  void *local_18;
  undefined8 local_10;
  
  local_18 = (void *)0x0;
  local_10 = param_2;
  QMetaObject::activate(param_1,(QMetaObject *)&PTR_PTR_01197a60,2,&local_18);
  return;
}


// ==== entry=008f2efe name=FUN_008f2efe size=42 ====

void FUN_008f2efe(QObject *param_1,undefined8 param_2)

{
  void *local_18;
  undefined8 local_10;
  
  local_18 = (void *)0x0;
  local_10 = param_2;
  QMetaObject::activate(param_1,(QMetaObject *)&PTR_PTR_01197a60,3,&local_18);
  return;
}


// ==== entry=008f2f28 name=FUN_008f2f28 size=42 ====

void FUN_008f2f28(QObject *param_1,undefined8 param_2)

{
  void *local_18;
  undefined8 local_10;
  
  local_18 = (void *)0x0;
  local_10 = param_2;
  QMetaObject::activate(param_1,(QMetaObject *)&PTR_PTR_01197a60,0x30,&local_18);
  return;
}


// ==== entry=008f2f52 name=FUN_008f2f52 size=80 ====

void FUN_008f2f52(QObject *param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                 undefined1 param_5)

{
  undefined1 local_44 [4];
  undefined8 local_40;
  void *local_38;
  undefined8 *local_30;
  undefined8 local_28;
  undefined8 local_20;
  undefined1 *local_18;
  
  local_38 = (void *)0x0;
  local_30 = &local_40;
  local_18 = local_44;
  local_44[0] = param_5;
  local_40 = param_2;
  local_28 = param_3;
  local_20 = param_4;
  QMetaObject::activate(param_1,(QMetaObject *)&PTR_PTR_01197a60,1,&local_38);
  return;
}


// ==== entry=008f2fa2 name=FUN_008f2fa2 size=55 ====

void FUN_008f2fa2(QObject *param_1,undefined1 param_2)

{
  undefined1 local_1c [4];
  void *local_18;
  undefined1 *local_10;
  
  local_18 = (void *)0x0;
  local_10 = local_1c;
  local_1c[0] = param_2;
  QMetaObject::activate(param_1,(QMetaObject *)&PTR_PTR_01197a60,0x2e,&local_18);
  return;
}


// ==== entry=008f2fda name=FUN_008f2fda size=54 ====

void FUN_008f2fda(QObject *param_1,undefined4 param_2)

{
  undefined4 local_1c;
  void *local_18;
  undefined4 *local_10;
  
  local_18 = (void *)0x0;
  local_10 = &local_1c;
  local_1c = param_2;
  QMetaObject::activate(param_1,(QMetaObject *)&PTR_PTR_01197a60,4,&local_18);
  return;
}


// ==== entry=008f3010 name=FUN_008f3010 size=54 ====

void FUN_008f3010(QObject *param_1,undefined4 param_2)

{
  undefined4 local_1c;
  void *local_18;
  undefined4 *local_10;
  
  local_18 = (void *)0x0;
  local_10 = &local_1c;
  local_1c = param_2;
  QMetaObject::activate(param_1,(QMetaObject *)&PTR_PTR_01197a60,10,&local_18);
  return;
}


// ==== entry=008f3046 name=FUN_008f3046 size=54 ====

void FUN_008f3046(QObject *param_1,undefined4 param_2)

{
  undefined4 local_1c;
  void *local_18;
  undefined4 *local_10;
  
  local_18 = (void *)0x0;
  local_10 = &local_1c;
  local_1c = param_2;
  QMetaObject::activate(param_1,(QMetaObject *)&PTR_PTR_01197a60,0x3a,&local_18);
  return;
}


// ==== entry=008f307c name=FUN_008f307c size=54 ====

void FUN_008f307c(QObject *param_1,undefined4 param_2)

{
  undefined4 local_1c;
  void *local_18;
  undefined4 *local_10;
  
  local_18 = (void *)0x0;
  local_10 = &local_1c;
  local_1c = param_2;
  QMetaObject::activate(param_1,(QMetaObject *)&PTR_PTR_01197a60,0x3b,&local_18);
  return;
}


// ==== entry=008f30b2 name=FUN_008f30b2 size=54 ====

void FUN_008f30b2(QObject *param_1,undefined4 param_2)

{
  undefined4 local_1c;
  void *local_18;
  undefined4 *local_10;
  
  local_18 = (void *)0x0;
  local_10 = &local_1c;
  local_1c = param_2;
  QMetaObject::activate(param_1,(QMetaObject *)&PTR_PTR_01197a60,0x3d,&local_18);
  return;
}


// ==== entry=008f30e8 name=FUN_008f30e8 size=84 ====

void FUN_008f30e8(QObject *param_1,undefined4 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 local_40;
  undefined8 local_38;
  undefined4 local_2c;
  void *local_28;
  undefined4 *local_20;
  undefined8 *local_18;
  undefined8 *local_10;
  
  local_28 = (void *)0x0;
  local_20 = &local_2c;
  local_18 = &local_38;
  local_10 = &local_40;
  local_40 = param_4;
  local_38 = param_3;
  local_2c = param_2;
  QMetaObject::activate(param_1,(QMetaObject *)&PTR_PTR_01197a60,6,&local_28);
  return;
}


// ==== entry=008f313c name=FUN_008f313c size=67 ====

void FUN_008f313c(QObject *param_1,undefined8 param_2,undefined8 param_3)

{
  undefined8 local_38;
  undefined8 local_30;
  void *local_28;
  undefined8 *local_20;
  undefined1 *local_18;
  
  local_18 = (undefined1 *)&local_38;
  local_28 = (void *)0x0;
  local_20 = &local_30;
  local_38 = param_3;
  local_30 = param_2;
  QMetaObject::activate(param_1,(QMetaObject *)&PTR_PTR_01197a60,0xb,&local_28);
  return;
}


// ==== entry=008f3180 name=FUN_008f3180 size=55 ====

void FUN_008f3180(QObject *param_1,undefined8 param_2)

{
  undefined8 local_20;
  void *local_18;
  undefined8 *local_10;
  
  local_18 = (void *)0x0;
  local_10 = &local_20;
  local_20 = param_2;
  QMetaObject::activate(param_1,(QMetaObject *)&PTR_PTR_01197a60,0x22,&local_18);
  return;
}


// ==== entry=008f31b8 name=FUN_008f31b8 size=55 ====

void FUN_008f31b8(QObject *param_1,undefined8 param_2)

{
  undefined8 local_20;
  void *local_18;
  undefined8 *local_10;
  
  local_18 = (void *)0x0;
  local_10 = &local_20;
  local_20 = param_2;
  QMetaObject::activate(param_1,(QMetaObject *)&PTR_PTR_01197a60,0x23,&local_18);
  return;
}


// ==== entry=008f31f0 name=FUN_008f31f0 size=55 ====

void FUN_008f31f0(QObject *param_1,undefined8 param_2)

{
  undefined8 local_20;
  void *local_18;
  undefined8 *local_10;
  
  local_18 = (void *)0x0;
  local_10 = &local_20;
  local_20 = param_2;
  QMetaObject::activate(param_1,(QMetaObject *)&PTR_PTR_01197a60,0x24,&local_18);
  return;
}


// ==== entry=008f3228 name=FUN_008f3228 size=55 ====

void FUN_008f3228(QObject *param_1,undefined8 param_2)

{
  undefined8 local_20;
  void *local_18;
  undefined8 *local_10;
  
  local_18 = (void *)0x0;
  local_10 = &local_20;
  local_20 = param_2;
  QMetaObject::activate(param_1,(QMetaObject *)&PTR_PTR_01197a60,0x25,&local_18);
  return;
}


// ==== entry=008f3260 name=FUN_008f3260 size=85 ====

void FUN_008f3260(QObject *param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 local_40;
  undefined8 local_38;
  undefined8 local_30;
  void *local_28;
  undefined8 *local_20;
  undefined8 *local_18;
  undefined8 *local_10;
  
  local_28 = (void *)0x0;
  local_20 = &local_30;
  local_18 = &local_38;
  local_10 = &local_40;
  local_40 = param_4;
  local_38 = param_3;
  local_30 = param_2;
  QMetaObject::activate(param_1,(QMetaObject *)&PTR_PTR_01197a60,0x29,&local_28);
  return;
}


// ==== entry=008f32b6 name=FUN_008f32b6 size=67 ====

void FUN_008f32b6(QObject *param_1,undefined8 param_2,undefined8 param_3)

{
  undefined8 local_38;
  undefined8 local_30;
  void *local_28;
  undefined8 *local_20;
  undefined1 *local_18;
  
  local_18 = (undefined1 *)&local_38;
  local_28 = (void *)0x0;
  local_20 = &local_30;
  local_38 = param_3;
  local_30 = param_2;
  QMetaObject::activate(param_1,(QMetaObject *)&PTR_PTR_01197a60,0x2d,&local_28);
  return;
}


// ==== entry=008f32fa name=FUN_008f32fa size=67 ====

void FUN_008f32fa(QObject *param_1,undefined8 param_2,undefined8 param_3)

{
  undefined8 local_38;
  undefined8 local_30;
  void *local_28;
  undefined8 *local_20;
  undefined1 *local_18;
  
  local_18 = (undefined1 *)&local_38;
  local_28 = (void *)0x0;
  local_20 = &local_30;
  local_38 = param_3;
  local_30 = param_2;
  QMetaObject::activate(param_1,(QMetaObject *)&PTR_PTR_01197a60,0x2f,&local_28);
  return;
}


// ==== entry=008f333e name=FUN_008f333e size=67 ====

void FUN_008f333e(QObject *param_1,undefined8 param_2,undefined8 param_3)

{
  undefined8 local_38;
  undefined8 local_30;
  void *local_28;
  undefined8 *local_20;
  undefined1 *local_18;
  
  local_18 = (undefined1 *)&local_38;
  local_28 = (void *)0x0;
  local_20 = &local_30;
  local_38 = param_3;
  local_30 = param_2;
  QMetaObject::activate(param_1,(QMetaObject *)&PTR_PTR_01197a60,0x34,&local_28);
  return;
}


// ==== entry=008f3382 name=FUN_008f3382 size=67 ====

void FUN_008f3382(QObject *param_1,undefined8 param_2,undefined8 param_3)

{
  undefined8 local_38;
  undefined8 local_30;
  void *local_28;
  undefined8 *local_20;
  undefined1 *local_18;
  
  local_18 = (undefined1 *)&local_38;
  local_28 = (void *)0x0;
  local_20 = &local_30;
  local_38 = param_3;
  local_30 = param_2;
  QMetaObject::activate(param_1,(QMetaObject *)&PTR_PTR_01197a60,0x35,&local_28);
  return;
}


// ==== entry=008f33c6 name=FUN_008f33c6 size=97 ====

void FUN_008f33c6(QObject *param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                 undefined8 param_5)

{
  undefined8 local_58;
  undefined8 local_50;
  undefined8 local_48;
  undefined8 local_40;
  void *local_38;
  undefined8 *local_30;
  undefined8 *local_28;
  undefined8 *local_20;
  undefined1 *local_18;
  
  local_18 = (undefined1 *)&local_58;
  local_38 = (void *)0x0;
  local_30 = &local_40;
  local_28 = &local_48;
  local_20 = &local_50;
  local_58 = param_5;
  local_50 = param_4;
  local_48 = param_3;
  local_40 = param_2;
  QMetaObject::activate(param_1,(QMetaObject *)&PTR_PTR_01197a60,0x36,&local_38);
  return;
}


// ==== entry=008f3428 name=FUN_008f3428 size=128 ====

void FUN_008f3428(QObject *param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                 undefined8 param_5,undefined8 param_6)

{
  undefined8 local_70;
  undefined8 local_68;
  undefined8 local_60;
  undefined8 local_58;
  undefined8 local_50;
  void *local_48;
  undefined8 *local_40;
  undefined8 *local_38;
  undefined8 *local_30;
  undefined8 *local_28;
  undefined8 *local_20;
  undefined1 *local_18;
  
  local_48 = (void *)0x0;
  local_40 = &local_50;
  local_38 = &local_58;
  local_30 = &local_60;
  local_28 = &local_68;
  local_20 = &local_70;
  local_18 = &stack0x00000008;
  local_70 = param_6;
  local_68 = param_5;
  local_60 = param_4;
  local_58 = param_3;
  local_50 = param_2;
  QMetaObject::activate(param_1,(QMetaObject *)&PTR_PTR_01197a60,0x38,&local_48);
  return;
}


// ==== entry=008f34a8 name=FUN_008f34a8 size=76 ====

void FUN_008f34a8(QObject *param_1,undefined4 param_2,undefined8 param_3,undefined8 param_4,
                 undefined8 param_5)

{
  undefined8 local_48;
  undefined4 local_3c;
  void *local_38;
  undefined4 *local_30;
  undefined1 *local_28;
  undefined8 local_20;
  undefined8 local_18;
  
  local_28 = (undefined1 *)&local_48;
  local_38 = (void *)0x0;
  local_30 = &local_3c;
  local_48 = param_3;
  local_3c = param_2;
  local_20 = param_4;
  local_18 = param_5;
  QMetaObject::activate(param_1,(QMetaObject *)&PTR_PTR_01197a60,0x3c,&local_38);
  return;
}


// ==== entry=008f34f4 name=FUN_008f34f4 size=70 ====

void FUN_008f34f4(QObject *param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                 undefined8 param_5)

{
  undefined8 local_40;
  void *local_38;
  undefined8 *local_30;
  undefined8 local_28;
  undefined8 local_20;
  undefined8 local_18;
  
  local_38 = (void *)0x0;
  local_30 = &local_40;
  local_40 = param_2;
  local_28 = param_3;
  local_20 = param_4;
  local_18 = param_5;
  QMetaObject::activate(param_1,(QMetaObject *)&PTR_PTR_01197a60,9,&local_38);
  return;
}


// ==== entry=008f353a name=FUN_008f353a size=64 ====

void FUN_008f353a(QObject *param_1,undefined4 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined4 local_2c;
  void *local_28;
  undefined4 *local_20;
  undefined8 local_18;
  undefined8 local_10;
  
  local_28 = (void *)0x0;
  local_20 = &local_2c;
  local_2c = param_2;
  local_18 = param_3;
  local_10 = param_4;
  QMetaObject::activate(param_1,(QMetaObject *)&PTR_PTR_01197a60,0x20,&local_28);
  return;
}


// ==== entry=008f357a name=FUN_008f357a size=72 ====

void FUN_008f357a(QObject *param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 local_38;
  undefined8 local_30;
  void *local_28;
  undefined8 local_20;
  undefined8 *local_18;
  undefined1 *local_10;
  
  local_10 = (undefined1 *)&local_38;
  local_28 = (void *)0x0;
  local_18 = &local_30;
  local_38 = param_4;
  local_30 = param_3;
  local_20 = param_2;
  QMetaObject::activate(param_1,(QMetaObject *)&PTR_PTR_01197a60,0x1c,&local_28);
  return;
}


// ==== entry=008f35c2 name=FUN_008f35c2 size=72 ====

void FUN_008f35c2(QObject *param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 local_38;
  undefined8 local_30;
  void *local_28;
  undefined8 local_20;
  undefined8 *local_18;
  undefined1 *local_10;
  
  local_10 = (undefined1 *)&local_38;
  local_28 = (void *)0x0;
  local_18 = &local_30;
  local_38 = param_4;
  local_30 = param_3;
  local_20 = param_2;
  QMetaObject::activate(param_1,(QMetaObject *)&PTR_PTR_01197a60,0x1d,&local_28);
  return;
}


// ==== entry=008f360a name=FUN_008f360a size=74 ====

void FUN_008f360a(QObject *param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4)

{
  undefined4 local_34;
  undefined8 local_30;
  void *local_28;
  undefined8 local_20;
  undefined8 *local_18;
  undefined4 *local_10;
  
  local_28 = (void *)0x0;
  local_18 = &local_30;
  local_10 = &local_34;
  local_34 = param_4;
  local_30 = param_3;
  local_20 = param_2;
  QMetaObject::activate(param_1,(QMetaObject *)&PTR_PTR_01197a60,0xc,&local_28);
  return;
}


// ==== entry=008f3654 name=FUN_008f3654 size=74 ====

void FUN_008f3654(QObject *param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4)

{
  undefined4 local_34;
  undefined8 local_30;
  void *local_28;
  undefined8 local_20;
  undefined8 *local_18;
  undefined4 *local_10;
  
  local_28 = (void *)0x0;
  local_18 = &local_30;
  local_10 = &local_34;
  local_34 = param_4;
  local_30 = param_3;
  local_20 = param_2;
  QMetaObject::activate(param_1,(QMetaObject *)&PTR_PTR_01197a60,0xd,&local_28);
  return;
}


// ==== entry=008f369e name=FUN_008f369e size=74 ====

void FUN_008f369e(QObject *param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4)

{
  undefined4 local_34;
  undefined8 local_30;
  void *local_28;
  undefined8 local_20;
  undefined8 *local_18;
  undefined4 *local_10;
  
  local_28 = (void *)0x0;
  local_18 = &local_30;
  local_10 = &local_34;
  local_34 = param_4;
  local_30 = param_3;
  local_20 = param_2;
  QMetaObject::activate(param_1,(QMetaObject *)&PTR_PTR_01197a60,0xe,&local_28);
  return;
}


// ==== entry=008f36e8 name=FUN_008f36e8 size=74 ====

void FUN_008f36e8(QObject *param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4)

{
  undefined4 local_34;
  undefined8 local_30;
  void *local_28;
  undefined8 local_20;
  undefined8 *local_18;
  undefined4 *local_10;
  
  local_28 = (void *)0x0;
  local_18 = &local_30;
  local_10 = &local_34;
  local_34 = param_4;
  local_30 = param_3;
  local_20 = param_2;
  QMetaObject::activate(param_1,(QMetaObject *)&PTR_PTR_01197a60,0x19,&local_28);
  return;
}


// ==== entry=008f3732 name=FUN_008f3732 size=74 ====

void FUN_008f3732(QObject *param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4)

{
  undefined4 local_34;
  undefined8 local_30;
  void *local_28;
  undefined8 local_20;
  undefined8 *local_18;
  undefined4 *local_10;
  
  local_28 = (void *)0x0;
  local_18 = &local_30;
  local_10 = &local_34;
  local_34 = param_4;
  local_30 = param_3;
  local_20 = param_2;
  QMetaObject::activate(param_1,(QMetaObject *)&PTR_PTR_01197a60,0x1a,&local_28);
  return;
}


// ==== entry=008f377c name=FUN_008f377c size=74 ====

void FUN_008f377c(QObject *param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4)

{
  undefined4 local_34;
  undefined8 local_30;
  void *local_28;
  undefined8 local_20;
  undefined8 *local_18;
  undefined4 *local_10;
  
  local_28 = (void *)0x0;
  local_18 = &local_30;
  local_10 = &local_34;
  local_34 = param_4;
  local_30 = param_3;
  local_20 = param_2;
  QMetaObject::activate(param_1,(QMetaObject *)&PTR_PTR_01197a60,0x1b,&local_28);
  return;
}


// ==== entry=008f37c6 name=FUN_008f37c6 size=80 ====

void FUN_008f37c6(QObject *param_1,undefined4 param_2,undefined8 param_3,undefined4 param_4)

{
  undefined8 local_38;
  undefined4 local_30;
  undefined4 local_2c;
  void *local_28;
  undefined4 *local_20;
  undefined1 *local_18;
  undefined4 *local_10;
  
  local_18 = (undefined1 *)&local_38;
  local_28 = (void *)0x0;
  local_20 = &local_2c;
  local_10 = &local_30;
  local_38 = param_3;
  local_30 = param_4;
  local_2c = param_2;
  QMetaObject::activate(param_1,(QMetaObject *)&PTR_PTR_01197a60,0x21,&local_28);
  return;
}


// ==== entry=008f3816 name=FUN_008f3816 size=74 ====

void FUN_008f3816(QObject *param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4)

{
  undefined4 local_34;
  undefined8 local_30;
  void *local_28;
  undefined8 local_20;
  undefined8 *local_18;
  undefined4 *local_10;
  
  local_28 = (void *)0x0;
  local_18 = &local_30;
  local_10 = &local_34;
  local_34 = param_4;
  local_30 = param_3;
  local_20 = param_2;
  QMetaObject::activate(param_1,(QMetaObject *)&PTR_PTR_01197a60,0x26,&local_28);
  return;
}


// ==== entry=008f3860 name=FUN_008f3860 size=74 ====

void FUN_008f3860(QObject *param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4)

{
  undefined4 local_34;
  undefined8 local_30;
  void *local_28;
  undefined8 local_20;
  undefined8 *local_18;
  undefined4 *local_10;
  
  local_28 = (void *)0x0;
  local_18 = &local_30;
  local_10 = &local_34;
  local_34 = param_4;
  local_30 = param_3;
  local_20 = param_2;
  QMetaObject::activate(param_1,(QMetaObject *)&PTR_PTR_01197a60,0x27,&local_28);
  return;
}


// ==== entry=008f38aa name=FUN_008f38aa size=74 ====

void FUN_008f38aa(QObject *param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4)

{
  undefined4 local_34;
  undefined8 local_30;
  void *local_28;
  undefined8 local_20;
  undefined8 *local_18;
  undefined4 *local_10;
  
  local_28 = (void *)0x0;
  local_18 = &local_30;
  local_10 = &local_34;
  local_34 = param_4;
  local_30 = param_3;
  local_20 = param_2;
  QMetaObject::activate(param_1,(QMetaObject *)&PTR_PTR_01197a60,0x28,&local_28);
  return;
}


// ==== entry=008f38f4 name=FUN_008f38f4 size=42 ====

void FUN_008f38f4(QObject *param_1,undefined8 param_2)

{
  void *local_18;
  undefined8 local_10;
  
  local_18 = (void *)0x0;
  local_10 = param_2;
  QMetaObject::activate(param_1,(QMetaObject *)&PTR_PTR_01197a60,0xf,&local_18);
  return;
}


// ==== entry=008f391e name=FUN_008f391e size=54 ====

void FUN_008f391e(QObject *param_1,undefined4 param_2)

{
  undefined4 local_1c;
  void *local_18;
  undefined4 *local_10;
  
  local_18 = (void *)0x0;
  local_10 = &local_1c;
  local_1c = param_2;
  QMetaObject::activate(param_1,(QMetaObject *)&PTR_PTR_01197a60,0x10,&local_18);
  return;
}


// ==== entry=008f3954 name=FUN_008f3954 size=82 ====

void FUN_008f3954(QObject *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  void *local_28;
  undefined4 *local_20;
  undefined4 *local_18;
  undefined4 *local_10;
  
  local_28 = (void *)0x0;
  local_20 = &local_2c;
  local_18 = &local_30;
  local_10 = &local_34;
  local_34 = param_4;
  local_30 = param_3;
  local_2c = param_2;
  QMetaObject::activate(param_1,(QMetaObject *)&PTR_PTR_01197a60,0x1e,&local_28);
  return;
}


// ==== entry=008f39a6 name=FUN_008f39a6 size=54 ====

void FUN_008f39a6(QObject *param_1,undefined4 param_2)

{
  undefined4 local_1c;
  void *local_18;
  undefined4 *local_10;
  
  local_18 = (void *)0x0;
  local_10 = &local_1c;
  local_1c = param_2;
  QMetaObject::activate(param_1,(QMetaObject *)&PTR_PTR_01197a60,0x1f,&local_18);
  return;
}


// ==== entry=008f39dc name=FUN_008f39dc size=47 ====

void FUN_008f39dc(QObject *param_1,undefined8 param_2,undefined8 param_3)

{
  void *local_28;
  undefined8 local_20;
  undefined8 local_18;
  
  local_28 = (void *)0x0;
  local_20 = param_2;
  local_18 = param_3;
  QMetaObject::activate(param_1,(QMetaObject *)&PTR_PTR_01197a60,0x37,&local_28);
  return;
}


// ==== entry=008f3a0c orig=FUN_008f3a0c size=104 name=ScintillaEditWatcher_dtor_deleting ====

long ScintillaEditWatcher_dtor_deleting(long param_1,byte *param_2)

{
  int iVar1;
  long lVar2;
  byte *pbVar3;
  byte *pbVar4;
  bool bVar5;
  bool bVar6;
  byte bVar7;
  
  bVar7 = 0;
  if (param_2 == (byte *)0x0) {
    return 0;
  }
  iVar1 = strcmp((char *)param_2,"TextView");
  bVar5 = false;
  if (iVar1 == 0) {
    return param_1;
  }
  lVar2 = 0x15;
  bVar6 = false;
  pbVar3 = param_2;
  pbVar4 = (byte *)"ScintillaEditWatcher";
  do {
    if (lVar2 == 0) break;
    lVar2 = lVar2 + -1;
    bVar5 = *pbVar3 < *pbVar4;
    bVar6 = *pbVar3 == *pbVar4;
    pbVar3 = pbVar3 + (ulong)bVar7 * -2 + 1;
    pbVar4 = pbVar4 + (ulong)bVar7 * -2 + 1;
  } while (bVar6);
  if ((!bVar5 && !bVar6) == bVar5) {
    return param_1 + 0x48;
  }
  lVar2 = s_MuxPane_91de9a(param_1,param_2);
  return lVar2;
}


// ==== entry=008f3a74 name=FUN_008f3a74 size=10735 ====

/* WARNING: Removing unreachable block (ram,0x008f6273) */
/* WARNING: Removing unreachable block (ram,0x008f5f61) */
/* WARNING: Removing unreachable block (ram,0x008f5e56) */
/* WARNING: Removing unreachable block (ram,0x008f5f44) */
/* WARNING: Removing unreachable block (ram,0x008f609f) */
/* WARNING: Removing unreachable block (ram,0x008f6335) */

void FUN_008f3a74(long *param_1,int param_2,int param_3,long *param_4)

{
  undefined4 *puVar1;
  long *plVar2;
  code *pcVar3;
  undefined8 *puVar4;
  QArrayData *pQVar5;
  undefined1 uVar6;
  undefined4 uVar7;
  undefined8 uVar8;
  undefined1 auVar9 [16];
  QArrayData *local_38;
  undefined4 local_30;
  QArrayData *local_28;
  undefined4 local_20;
  
  if (param_2 == 0) {
    switch(param_3) {
    case 0:
      FUN_008f2ea0(param_1,*(undefined8 *)param_4[1]);
      return;
    case 1:
      uVar6 = *(undefined1 *)param_4[4];
      local_28 = *(QArrayData **)param_4[3];
      if ((*(int *)local_28 != 0) && (*(int *)local_28 != -1)) {
        LOCK();
        *(int *)local_28 = *(int *)local_28 + 1;
        UNLOCK();
      }
                    /* try { // try from 008f5563 to 008f5567 has its CatchHandler @ 008f64a5 */
      FUN_008f2f52(param_1,*(undefined8 *)param_4[1],param_4[2],&local_28,uVar6);
      if (*(int *)local_28 != 0) {
        if (*(int *)local_28 == -1) {
          return;
        }
        LOCK();
        *(int *)local_28 = *(int *)local_28 + -1;
        UNLOCK();
        if (*(int *)local_28 != 0) {
          return;
        }
      }
      QArrayData::deallocate(local_28,2,8);
      return;
    case 2:
      local_28 = *(QArrayData **)param_4[1];
      if ((*(int *)local_28 != 0) && (*(int *)local_28 != -1)) {
        LOCK();
        *(int *)local_28 = *(int *)local_28 + 1;
        UNLOCK();
      }
                    /* try { // try from 008f55c2 to 008f55c6 has its CatchHandler @ 008f649d */
      FUN_008f2ed4(param_1,&local_28);
      if (*(int *)local_28 != 0) {
        if (*(int *)local_28 == -1) {
          return;
        }
        LOCK();
        *(int *)local_28 = *(int *)local_28 + -1;
        UNLOCK();
        if (*(int *)local_28 != 0) {
          return;
        }
      }
      QArrayData::deallocate(local_28,2,8);
      return;
    case 3:
      local_28 = *(QArrayData **)param_4[1];
      if ((*(int *)local_28 != 0) && (*(int *)local_28 != -1)) {
        LOCK();
        *(int *)local_28 = *(int *)local_28 + 1;
        UNLOCK();
      }
                    /* try { // try from 008f5621 to 008f5625 has its CatchHandler @ 008f648d */
      FUN_008f2efe(param_1,&local_28);
      if (*(int *)local_28 != 0) {
        if (*(int *)local_28 == -1) {
          return;
        }
        LOCK();
        *(int *)local_28 = *(int *)local_28 + -1;
        UNLOCK();
        if (*(int *)local_28 != 0) {
          return;
        }
      }
      QArrayData::deallocate(local_28,2,8);
      return;
    case 4:
      FUN_008f2fda(param_1,*(undefined4 *)param_4[1]);
      return;
    case 5:
      FUN_008f2d38();
      return;
    case 6:
      FUN_008f30e8(param_1,*(undefined4 *)param_4[1],*(undefined8 *)param_4[2],
                   *(undefined8 *)param_4[3]);
      return;
    case 7:
      FUN_008f2d4c();
      return;
    case 8:
      FUN_008f2d60();
      return;
    case 9:
      FUN_008f34f4(param_1,*(undefined8 *)param_4[1],param_4[2],param_4[3],param_4[4]);
      return;
    case 10:
      FUN_008f3010(param_1,*(undefined4 *)param_4[1]);
      return;
    case 0xb:
      FUN_008f313c(param_1,*(undefined8 *)param_4[1],*(undefined8 *)param_4[2]);
      return;
    case 0xc:
      FUN_008f360a(param_1,param_4[1],*(undefined8 *)param_4[2],*(undefined4 *)param_4[3]);
      return;
    case 0xd:
      FUN_008f3654(param_1,param_4[1],*(undefined8 *)param_4[2],*(undefined4 *)param_4[3]);
      return;
    case 0xe:
      FUN_008f369e(param_1,param_4[1],*(undefined8 *)param_4[2],*(undefined4 *)param_4[3]);
      return;
    case 0xf:
      FUN_008f38f4(param_1,param_4[1]);
      return;
    case 0x10:
      FUN_008f391e(param_1,*(undefined4 *)param_4[1]);
      return;
    case 0x11:
      FUN_008f2d74();
      return;
    case 0x12:
      FUN_008f2d88();
      return;
    case 0x13:
      FUN_008f2d9c();
      return;
    case 0x14:
      FUN_008f2db0();
      return;
    case 0x15:
      FUN_008f2dc4();
      return;
    case 0x16:
      FUN_008f2dd8();
      return;
    case 0x17:
      FUN_008f2dec();
      return;
    case 0x18:
      FUN_008f2e00();
      return;
    case 0x19:
      FUN_008f36e8(param_1,param_4[1],*(undefined8 *)param_4[2],*(undefined4 *)param_4[3]);
      return;
    case 0x1a:
      FUN_008f3732(param_1,param_4[1],*(undefined8 *)param_4[2],*(undefined4 *)param_4[3]);
      return;
    case 0x1b:
      FUN_008f377c(param_1,param_4[1],*(undefined8 *)param_4[2],*(undefined4 *)param_4[3]);
      return;
    case 0x1c:
      FUN_008f357a(param_1,param_4[1],*(undefined8 *)param_4[2],*(undefined8 *)param_4[3]);
      return;
    case 0x1d:
      FUN_008f35c2(param_1,param_4[1],*(undefined8 *)param_4[2],*(undefined8 *)param_4[3]);
      return;
    case 0x1e:
      FUN_008f3954(param_1,*(undefined4 *)param_4[1],*(undefined4 *)param_4[2],
                   *(undefined4 *)param_4[3]);
      return;
    case 0x1f:
      FUN_008f39a6(param_1,*(undefined4 *)param_4[1]);
      return;
    case 0x20:
      FUN_008f353a(param_1,*(undefined4 *)param_4[1],param_4[2],param_4[3]);
      return;
    case 0x21:
      FUN_008f37c6(param_1,*(undefined4 *)param_4[1],*(undefined8 *)param_4[2],
                   *(undefined4 *)param_4[3]);
      return;
    case 0x22:
      FUN_008f3180(param_1,*(undefined8 *)param_4[1]);
      return;
    case 0x23:
      FUN_008f31b8(param_1,*(undefined8 *)param_4[1]);
      return;
    case 0x24:
      FUN_008f31f0(param_1,*(undefined8 *)param_4[1]);
      return;
    case 0x25:
      FUN_008f3228(param_1,*(undefined8 *)param_4[1]);
      return;
    case 0x26:
      FUN_008f3816(param_1,param_4[1],*(undefined8 *)param_4[2],*(undefined4 *)param_4[3]);
      return;
    case 0x27:
      FUN_008f3860(param_1,param_4[1],*(undefined8 *)param_4[2],*(undefined4 *)param_4[3]);
      return;
    case 0x28:
      FUN_008f38aa(param_1,param_4[1],*(undefined8 *)param_4[2],*(undefined4 *)param_4[3]);
      return;
    case 0x29:
      FUN_008f3260(param_1,*(undefined8 *)param_4[1],*(undefined8 *)param_4[2],
                   *(undefined8 *)param_4[3]);
      return;
    case 0x2a:
      FUN_008f2e14();
      return;
    case 0x2b:
      FUN_008f2e28();
      return;
    case 0x2c:
      FUN_008f2e3c();
      return;
    case 0x2d:
      FUN_008f32b6(param_1,*(undefined8 *)param_4[1],*(undefined8 *)param_4[2]);
      return;
    case 0x2e:
      FUN_008f2fa2(param_1,*(undefined1 *)param_4[1]);
      return;
    case 0x2f:
      FUN_008f32fa(param_1,*(undefined8 *)param_4[1],*(undefined8 *)param_4[2]);
      return;
    case 0x30:
      local_28 = *(QArrayData **)param_4[1];
      if ((*(int *)local_28 != 0) && (*(int *)local_28 != -1)) {
        LOCK();
        *(int *)local_28 = *(int *)local_28 + 1;
        UNLOCK();
      }
                    /* try { // try from 008f4229 to 008f422d has its CatchHandler @ 008f6495 */
      FUN_008f2f28(param_1,&local_28);
      if (*(int *)local_28 != 0) {
        if (*(int *)local_28 == -1) {
          return;
        }
        LOCK();
        *(int *)local_28 = *(int *)local_28 + -1;
        UNLOCK();
        if (*(int *)local_28 != 0) {
          return;
        }
      }
      QArrayData::deallocate(local_28,2,8);
      return;
    case 0x31:
      FUN_008f2e50();
      return;
    case 0x32:
      FUN_008f2e64();
      return;
    case 0x33:
      FUN_008f2e78();
      return;
    case 0x34:
      FUN_008f333e(param_1,*(undefined8 *)param_4[1],*(undefined8 *)param_4[2]);
      return;
    case 0x35:
      FUN_008f3382(param_1,*(undefined8 *)param_4[1],*(undefined8 *)param_4[2]);
      return;
    case 0x36:
      FUN_008f33c6(param_1,*(undefined8 *)param_4[1],*(undefined8 *)param_4[2],
                   *(undefined8 *)param_4[3],*(undefined8 *)param_4[4]);
      return;
    case 0x37:
      FUN_008f39dc(param_1,param_4[1],param_4[2]);
      return;
    case 0x38:
      FUN_008f3428(param_1,*(undefined8 *)param_4[1],*(undefined8 *)param_4[2],
                   *(undefined8 *)param_4[3],*(undefined8 *)param_4[4],*(undefined8 *)param_4[5],
                   *(undefined8 *)param_4[6]);
      return;
    case 0x39:
      FUN_008f2e8c();
      return;
    case 0x3a:
      FUN_008f3046(param_1,*(undefined4 *)param_4[1]);
      return;
    case 0x3b:
      FUN_008f307c(param_1,*(undefined4 *)param_4[1]);
      return;
    case 0x3c:
      FUN_008f34a8(param_1,*(undefined4 *)param_4[1],*(undefined8 *)param_4[2],param_4[3],param_4[4]
                  );
      return;
    case 0x3d:
      FUN_008f30b2(param_1,*(undefined4 *)param_4[1]);
      return;
    case 0x3e:
      FUN_005b5d7e();
      return;
    case 0x3f:
      FUN_005b5df4();
      return;
    case 0x40:
      FUN_005c4c68(param_1,param_4[1],param_4[2],param_4[3]);
      return;
    case 0x41:
      FUN_005c4d5e(param_1,*(undefined8 *)param_4[1],param_4[2],*(undefined1 *)param_4[3]);
      return;
    case 0x42:
      FUN_005c4d5e(param_1,*(undefined8 *)param_4[1],param_4[2],0);
      return;
    case 0x43:
      FUN_005c0782();
      return;
    case 0x44:
      FUN_005b6006();
      return;
    case 0x45:
      FUN_005b607c();
      return;
    case 0x46:
      FUN_005b60f2();
      return;
    case 0x47:
      uVar6 = FUN_005b6168();
      if ((undefined1 *)*param_4 == (undefined1 *)0x0) {
        return;
      }
      *(undefined1 *)*param_4 = uVar6;
      return;
    case 0x48:
      uVar6 = FUN_005b61f8();
      if ((undefined1 *)*param_4 == (undefined1 *)0x0) {
        return;
      }
      *(undefined1 *)*param_4 = uVar6;
      return;
    case 0x49:
      uVar6 = FUN_005b6288();
      if ((undefined1 *)*param_4 == (undefined1 *)0x0) {
        return;
      }
      *(undefined1 *)*param_4 = uVar6;
      return;
    case 0x4a:
      uVar7 = FUN_005b65f8(param_1,*(undefined8 *)param_4[1]);
      if ((undefined4 *)*param_4 == (undefined4 *)0x0) {
        return;
      }
      *(undefined4 *)*param_4 = uVar7;
      return;
    case 0x4b:
      uVar7 = FUN_005b6692(param_1,*(undefined8 *)param_4[1]);
      if ((undefined4 *)*param_4 == (undefined4 *)0x0) {
        return;
      }
      *(undefined4 *)*param_4 = uVar7;
      return;
    case 0x4c:
      FUN_005b6968();
      return;
    case 0x4d:
      FUN_005b69de();
      return;
    case 0x4e:
      FUN_005b6a54();
      return;
    case 0x4f:
      FUN_005b6aca(param_1,*(undefined4 *)param_4[1]);
      return;
    case 0x50:
      FUN_005b6aca(param_1,0xffffffff);
      return;
    case 0x51:
      (**(code **)(*param_1 + 0x1c8))(&local_28,param_1);
      puVar4 = (undefined8 *)*param_4;
      if (puVar4 != (undefined8 *)0x0) {
        pQVar5 = (QArrayData *)*puVar4;
        *puVar4 = local_28;
        local_28 = pQVar5;
      }
      if (*(int *)local_28 != 0) {
        if (*(int *)local_28 == -1) {
          return;
        }
        LOCK();
        *(int *)local_28 = *(int *)local_28 + -1;
        UNLOCK();
        if (*(int *)local_28 != 0) {
          return;
        }
      }
      QArrayData::deallocate(local_28,2,8);
      return;
    case 0x52:
      uVar7 = FUN_005b6eaa();
      if ((undefined4 *)*param_4 == (undefined4 *)0x0) {
        return;
      }
      *(undefined4 *)*param_4 = uVar7;
      return;
    case 0x53:
      FUN_005b6f3c(&local_28,param_1,*(undefined8 *)param_4[1]);
      puVar4 = (undefined8 *)*param_4;
      if (puVar4 != (undefined8 *)0x0) {
        pQVar5 = (QArrayData *)*puVar4;
        *puVar4 = local_28;
        local_28 = pQVar5;
      }
      if (*(int *)local_28 != 0) {
        if (*(int *)local_28 == -1) {
          return;
        }
        LOCK();
        *(int *)local_28 = *(int *)local_28 + -1;
        UNLOCK();
        if (*(int *)local_28 != 0) {
          return;
        }
      }
      QArrayData::deallocate(local_28,2,8);
      return;
    case 0x54:
      FUN_005b6f3c(&local_28,param_1,0xffffffffffffffff);
      puVar4 = (undefined8 *)*param_4;
      if (puVar4 != (undefined8 *)0x0) {
        pQVar5 = (QArrayData *)*puVar4;
        *puVar4 = local_28;
        local_28 = pQVar5;
      }
      if (*(int *)local_28 != 0) {
        if (*(int *)local_28 == -1) {
          return;
        }
        LOCK();
        *(int *)local_28 = *(int *)local_28 + -1;
        UNLOCK();
        if (*(int *)local_28 != 0) {
          return;
        }
      }
      QArrayData::deallocate(local_28,2,8);
      return;
    case 0x55:
      FUN_005b6fde();
      return;
    case 0x56:
      uVar6 = FUN_005b7054();
      if ((undefined1 *)*param_4 == (undefined1 *)0x0) {
        return;
      }
      *(undefined1 *)*param_4 = uVar6;
      return;
    case 0x57:
      FUN_005c6834(param_1,*(undefined1 *)param_4[1]);
      return;
    case 0x58:
      FUN_005c6834(param_1,0);
      return;
    case 0x59:
      FUN_005c6842(param_1,*(undefined1 *)param_4[1]);
      return;
    case 0x5a:
      FUN_005c6842(param_1,0);
      return;
    case 0x5b:
      FUN_005b70e4(param_1,*(undefined8 *)param_4[1],*(undefined1 *)param_4[2]);
      return;
    case 0x5c:
      FUN_005b70e4(param_1,*(undefined8 *)param_4[1],0);
      return;
    case 0x5d:
      FUN_005b7160(param_1,*(undefined8 *)param_4[1],*(undefined8 *)param_4[2]);
      return;
    case 0x5e:
      FUN_005b71dc(param_1,param_4[1]);
      return;
    case 0x5f:
      FUN_005c4c0a((QVariant *)&local_38,param_1,param_4[1]);
      puVar4 = (undefined8 *)*param_4;
      if (puVar4 != (undefined8 *)0x0) {
        local_28 = (QArrayData *)*puVar4;
        local_20 = *(undefined4 *)(puVar4 + 1);
        *puVar4 = local_38;
        *(undefined4 *)(puVar4 + 1) = local_30;
        local_38 = local_28;
        local_30 = local_20;
      }
      QVariant::~QVariant((QVariant *)&local_38);
      return;
    case 0x60:
      FUN_005b725e(param_1,*(undefined8 *)param_4[1],(int)*(char *)param_4[2]);
      return;
    case 0x61:
      FUN_005b725e(param_1,*(undefined8 *)param_4[1],2);
      return;
    case 0x62:
      FUN_005b72da(param_1,*(undefined8 *)param_4[1]);
      return;
    case 99:
      uVar6 = FUN_005b73e4();
      if ((undefined1 *)*param_4 == (undefined1 *)0x0) {
        return;
      }
      *(undefined1 *)*param_4 = uVar6;
      return;
    case 100:
      uVar6 = FUN_005b76e6();
      if ((undefined1 *)*param_4 == (undefined1 *)0x0) {
        return;
      }
      *(undefined1 *)*param_4 = uVar6;
      return;
    case 0x65:
      uVar6 = FUN_005b7782();
      if ((undefined1 *)*param_4 == (undefined1 *)0x0) {
        return;
      }
      *(undefined1 *)*param_4 = uVar6;
      return;
    case 0x66:
      uVar7 = FUN_005b7a54();
      if ((undefined4 *)*param_4 == (undefined4 *)0x0) {
        return;
      }
      *(undefined4 *)*param_4 = uVar7;
      return;
    case 0x67:
      FUN_005c51aa(&local_38,param_1,param_4[1],*(undefined8 *)param_4[2],*(undefined8 *)param_4[3],
                   *(undefined4 *)param_4[4],*(undefined4 *)param_4[5]);
      pQVar5 = local_38;
      puVar4 = (undefined8 *)*param_4;
      if (puVar4 != (undefined8 *)0x0) {
        local_38 = (QArrayData *)&QListData::shared_null;
        local_28 = (QArrayData *)*puVar4;
        *puVar4 = pQVar5;
        FUN_00544650(&local_28);
      }
      FUN_00544650(&local_38);
      return;
    case 0x68:
      FUN_005c51aa(&local_38,param_1,param_4[1],*(undefined8 *)param_4[2],*(undefined8 *)param_4[3],
                   *(undefined4 *)param_4[4],1);
      pQVar5 = local_38;
      puVar4 = (undefined8 *)*param_4;
      if (puVar4 != (undefined8 *)0x0) {
        local_38 = (QArrayData *)&QListData::shared_null;
        local_28 = (QArrayData *)*puVar4;
        *puVar4 = pQVar5;
        FUN_00544650(&local_28);
      }
      FUN_00544650(&local_38);
      return;
    case 0x69:
      FUN_005b7ae6();
      return;
    case 0x6a:
      uVar6 = FUN_005b7b5c();
      if ((undefined1 *)*param_4 == (undefined1 *)0x0) {
        return;
      }
      *(undefined1 *)*param_4 = uVar6;
      return;
    case 0x6b:
      uVar6 = FUN_005b7bec();
      if ((undefined1 *)*param_4 == (undefined1 *)0x0) {
        return;
      }
      *(undefined1 *)*param_4 = uVar6;
      return;
    case 0x6c:
      uVar6 = FUN_005b6bde();
      if ((undefined1 *)*param_4 == (undefined1 *)0x0) {
        return;
      }
      *(undefined1 *)*param_4 = uVar6;
      return;
    case 0x6d:
      uVar6 = FUN_005b7d0c();
      if ((undefined1 *)*param_4 == (undefined1 *)0x0) {
        return;
      }
      *(undefined1 *)*param_4 = uVar6;
      return;
    case 0x6e:
      uVar6 = FUN_005b7f4c();
      if ((undefined1 *)*param_4 == (undefined1 *)0x0) {
        return;
      }
      *(undefined1 *)*param_4 = uVar6;
      return;
    case 0x6f:
      uVar6 = FUN_005b7fdc();
      if ((undefined1 *)*param_4 == (undefined1 *)0x0) {
        return;
      }
      *(undefined1 *)*param_4 = uVar6;
      return;
    case 0x70:
      uVar6 = FUN_005b806c();
      if ((undefined1 *)*param_4 == (undefined1 *)0x0) {
        return;
      }
      *(undefined1 *)*param_4 = uVar6;
      return;
    case 0x71:
      uVar6 = FUN_005b80fc();
      if ((undefined1 *)*param_4 == (undefined1 *)0x0) {
        return;
      }
      *(undefined1 *)*param_4 = uVar6;
      return;
    case 0x72:
      FUN_005b821c();
      return;
    case 0x73:
      FUN_005b82a2();
      return;
    case 0x74:
      uVar8 = FUN_005b84dc(param_1,*(undefined8 *)param_4[1]);
      if ((undefined8 *)*param_4 == (undefined8 *)0x0) {
        return;
      }
      *(undefined8 *)*param_4 = uVar8;
      return;
    case 0x75:
      uVar8 = FUN_005c19d0(param_1,param_4[1]);
      if ((undefined8 *)*param_4 == (undefined8 *)0x0) {
        return;
      }
      *(undefined8 *)*param_4 = uVar8;
      return;
    case 0x76:
      uVar8 = FUN_005b8576(param_1,*(undefined8 *)param_4[1]);
      if ((undefined8 *)*param_4 == (undefined8 *)0x0) {
        return;
      }
      *(undefined8 *)*param_4 = uVar8;
      return;
    case 0x77:
      uVar8 = FUN_005b8752(param_1,*(undefined8 *)param_4[1]);
      if ((undefined8 *)*param_4 == (undefined8 *)0x0) {
        return;
      }
      *(undefined8 *)*param_4 = uVar8;
      return;
    case 0x78:
      uVar8 = FUN_005b8886(param_1,*(undefined8 *)param_4[1]);
      if ((undefined8 *)*param_4 == (undefined8 *)0x0) {
        return;
      }
      *(undefined8 *)*param_4 = uVar8;
      return;
    case 0x79:
      FUN_005c0ccc(&local_28,param_1,*(undefined8 *)param_4[1]);
      puVar4 = (undefined8 *)*param_4;
      if (puVar4 != (undefined8 *)0x0) {
        pQVar5 = (QArrayData *)*puVar4;
        *puVar4 = local_28;
        local_28 = pQVar5;
      }
      if (*(int *)local_28 != 0) {
        if (*(int *)local_28 == -1) {
          return;
        }
        LOCK();
        *(int *)local_28 = *(int *)local_28 + -1;
        UNLOCK();
        if (*(int *)local_28 != 0) {
          return;
        }
      }
      QArrayData::deallocate(local_28,2,8);
      return;
    case 0x7a:
      FUN_005b8adc();
      return;
    case 0x7b:
      FUN_005b8b52(&local_38,param_1,param_4[1]);
      pQVar5 = local_38;
      puVar4 = (undefined8 *)*param_4;
      if (puVar4 != (undefined8 *)0x0) {
        local_38 = (QArrayData *)&QMapDataBase::shared_null;
        local_28 = (QArrayData *)*puVar4;
        *puVar4 = pQVar5;
        FUN_00528c1c(&local_28);
      }
      FUN_00528c1c(&local_38);
      return;
    case 0x7c:
      uVar7 = FUN_005bc118(param_1,param_4[1]);
      if ((undefined4 *)*param_4 == (undefined4 *)0x0) {
        return;
      }
      *(undefined4 *)*param_4 = uVar7;
      return;
    case 0x7d:
      FUN_005b8bf4(&local_38,param_1);
      pQVar5 = local_38;
      puVar4 = (undefined8 *)*param_4;
      if (puVar4 != (undefined8 *)0x0) {
        local_38 = (QArrayData *)&QListData::shared_null;
        local_28 = (QArrayData *)*puVar4;
        *puVar4 = pQVar5;
        FUN_00525060(&local_28);
      }
      FUN_00525060(&local_38);
      return;
    case 0x7e:
      uVar7 = FUN_005bc308();
      if ((undefined4 *)*param_4 == (undefined4 *)0x0) {
        return;
      }
      *(undefined4 *)*param_4 = uVar7;
      return;
    case 0x7f:
      uVar8 = FUN_005b8c84(param_1,*(undefined8 *)param_4[1],param_4[2]);
      if ((undefined8 *)*param_4 == (undefined8 *)0x0) {
        return;
      }
      *(undefined8 *)*param_4 = uVar8;
      return;
    case 0x80:
      uVar8 = FUN_005b8d18(param_1,*(undefined8 *)param_4[1],*(undefined1 *)param_4[2]);
      if ((undefined8 *)*param_4 == (undefined8 *)0x0) {
        return;
      }
      *(undefined8 *)*param_4 = uVar8;
      return;
    case 0x81:
      FUN_005b8dac(param_1,param_4[1],*(undefined4 *)param_4[2]);
      return;
    case 0x82:
      FUN_005b8dac(param_1,param_4[1],1);
      return;
    case 0x83:
      FUN_005c3320();
      return;
    case 0x84:
      FUN_005b9274();
      return;
    case 0x85:
      uVar8 = FUN_005b92ea(param_1,*(undefined8 *)param_4[1],*(undefined8 *)param_4[2]);
      if ((undefined8 *)*param_4 == (undefined8 *)0x0) {
        return;
      }
      *(undefined8 *)*param_4 = uVar8;
      return;
    case 0x86:
      uVar8 = FUN_005b937e(param_1,param_4[1]);
      if ((undefined8 *)*param_4 == (undefined8 *)0x0) {
        return;
      }
      *(undefined8 *)*param_4 = uVar8;
      return;
    case 0x87:
      FUN_005b9532(param_1,param_4[1]);
      return;
    case 0x88:
      uVar7 = FUN_005c6ee6(param_1,param_4[1]);
      if ((undefined4 *)*param_4 == (undefined4 *)0x0) {
        return;
      }
      *(undefined4 *)*param_4 = uVar7;
      return;
    case 0x89:
      FUN_005b962a(param_1,param_4[1]);
      return;
    case 0x8a:
      FUN_005bf47e();
      return;
    case 0x8b:
      (**(code **)(*param_1 + 0x1e0))(&local_28,param_1);
      puVar4 = (undefined8 *)*param_4;
      if (puVar4 != (undefined8 *)0x0) {
        pQVar5 = (QArrayData *)*puVar4;
        *puVar4 = local_28;
        local_28 = pQVar5;
      }
      if (*(int *)local_28 != 0) {
        if (*(int *)local_28 == -1) {
          return;
        }
        LOCK();
        *(int *)local_28 = *(int *)local_28 + -1;
        UNLOCK();
        if (*(int *)local_28 != 0) {
          return;
        }
      }
      QArrayData::deallocate(local_28,2,8);
      return;
    case 0x8c:
      goto switchD_008f3aa1_caseD_8c;
    case 0x8d:
      local_28 = (QArrayData *)&QArrayData::shared_null;
                    /* try { // try from 008f46bc to 008f46bd has its CatchHandler @ 008f646b */
      (**(code **)(*param_1 + 0x1e8))(&local_38,param_1,&local_28);
      if (*(int *)local_28 != 0) {
        if (*(int *)local_28 == -1) goto LAB_008f46dc;
        LOCK();
        *(int *)local_28 = *(int *)local_28 + -1;
        UNLOCK();
        if (*(int *)local_28 != 0) goto LAB_008f46dc;
      }
      QArrayData::deallocate(local_28,2,8);
LAB_008f46dc:
      puVar4 = (undefined8 *)*param_4;
      if (puVar4 != (undefined8 *)0x0) {
        pQVar5 = (QArrayData *)*puVar4;
        *puVar4 = local_38;
        local_38 = pQVar5;
      }
      if (*(int *)local_38 != 0) {
        if (*(int *)local_38 == -1) {
          return;
        }
        LOCK();
        *(int *)local_38 = *(int *)local_38 + -1;
        UNLOCK();
        if (*(int *)local_38 != 0) {
          return;
        }
      }
      QArrayData::deallocate(local_38,2,8);
      return;
    case 0x8e:
      local_28 = *(QArrayData **)param_4[1];
      if ((*(int *)local_28 != 0) && (*(int *)local_28 != -1)) {
        LOCK();
        *(int *)local_28 = *(int *)local_28 + 1;
        UNLOCK();
      }
                    /* try { // try from 008f4887 to 008f488b has its CatchHandler @ 008f64ad */
      FUN_005b5b7a(&local_38,param_1,&local_28);
      if (*(int *)local_28 != 0) {
        if (*(int *)local_28 == -1) goto LAB_008f48aa;
        LOCK();
        *(int *)local_28 = *(int *)local_28 + -1;
        UNLOCK();
        if (*(int *)local_28 != 0) goto LAB_008f48aa;
      }
      QArrayData::deallocate(local_28,2,8);
LAB_008f48aa:
      puVar4 = (undefined8 *)*param_4;
      if (puVar4 != (undefined8 *)0x0) {
        pQVar5 = (QArrayData *)*puVar4;
        *puVar4 = local_38;
        local_38 = pQVar5;
      }
      if (*(int *)local_38 != 0) {
        if (*(int *)local_38 == -1) {
          return;
        }
        LOCK();
        *(int *)local_38 = *(int *)local_38 + -1;
        UNLOCK();
        if (*(int *)local_38 != 0) {
          return;
        }
      }
      QArrayData::deallocate(local_38,2,8);
      return;
    case 0x8f:
      local_28 = (QArrayData *)&QArrayData::shared_null;
                    /* try { // try from 008f4749 to 008f474d has its CatchHandler @ 008f647b */
      FUN_005b5b7a(&local_38,param_1,&local_28);
      if (*(int *)local_28 != 0) {
        if (*(int *)local_28 == -1) goto LAB_008f476c;
        LOCK();
        *(int *)local_28 = *(int *)local_28 + -1;
        UNLOCK();
        if (*(int *)local_28 != 0) goto LAB_008f476c;
      }
      QArrayData::deallocate(local_28,2,8);
LAB_008f476c:
      puVar4 = (undefined8 *)*param_4;
      if (puVar4 != (undefined8 *)0x0) {
        pQVar5 = (QArrayData *)*puVar4;
        *puVar4 = local_38;
        local_38 = pQVar5;
      }
      if (*(int *)local_38 != 0) {
        if (*(int *)local_38 == -1) {
          return;
        }
        LOCK();
        *(int *)local_38 = *(int *)local_38 + -1;
        UNLOCK();
        if (*(int *)local_38 != 0) {
          return;
        }
      }
      QArrayData::deallocate(local_38,2,8);
      return;
    case 0x90:
      local_28 = *(QArrayData **)param_4[1];
      if ((*(int *)local_28 != 0) && (*(int *)local_28 != -1)) {
        LOCK();
        *(int *)local_28 = *(int *)local_28 + 1;
        UNLOCK();
      }
                    /* try { // try from 008f47e8 to 008f47ec has its CatchHandler @ 008f64b5 */
      FUN_005b5c00(&local_38,param_1,&local_28);
      if (*(int *)local_28 != 0) {
        if (*(int *)local_28 == -1) goto LAB_008f480b;
        LOCK();
        *(int *)local_28 = *(int *)local_28 + -1;
        UNLOCK();
        if (*(int *)local_28 != 0) goto LAB_008f480b;
      }
      QArrayData::deallocate(local_28,2,8);
LAB_008f480b:
      puVar4 = (undefined8 *)*param_4;
      if (puVar4 != (undefined8 *)0x0) {
        pQVar5 = (QArrayData *)*puVar4;
        *puVar4 = local_38;
        local_38 = pQVar5;
      }
      if (*(int *)local_38 != 0) {
        if (*(int *)local_38 == -1) {
          return;
        }
        LOCK();
        *(int *)local_38 = *(int *)local_38 + -1;
        UNLOCK();
        if (*(int *)local_38 != 0) {
          return;
        }
      }
      QArrayData::deallocate(local_38,2,8);
      return;
    case 0x91:
      local_28 = (QArrayData *)&QArrayData::shared_null;
                    /* try { // try from 008f4917 to 008f491b has its CatchHandler @ 008f64c5 */
      FUN_005b5c00(&local_38,param_1,&local_28);
      if (*(int *)local_28 != 0) {
        if (*(int *)local_28 == -1) goto LAB_008f493a;
        LOCK();
        *(int *)local_28 = *(int *)local_28 + -1;
        UNLOCK();
        if (*(int *)local_28 != 0) goto LAB_008f493a;
      }
      QArrayData::deallocate(local_28,2,8);
LAB_008f493a:
      puVar4 = (undefined8 *)*param_4;
      if (puVar4 != (undefined8 *)0x0) {
        pQVar5 = (QArrayData *)*puVar4;
        *puVar4 = local_38;
        local_38 = pQVar5;
      }
      if (*(int *)local_38 != 0) {
        if (*(int *)local_38 == -1) {
          return;
        }
        LOCK();
        *(int *)local_38 = *(int *)local_38 + -1;
        UNLOCK();
        if (*(int *)local_38 != 0) {
          return;
        }
      }
      QArrayData::deallocate(local_38,2,8);
      return;
    case 0x92:
      FUN_005b985e(&local_28,param_1);
      puVar4 = (undefined8 *)*param_4;
      if (puVar4 != (undefined8 *)0x0) {
        pQVar5 = (QArrayData *)*puVar4;
        *puVar4 = local_28;
        local_28 = pQVar5;
      }
      if (*(int *)local_28 != 0) {
        if (*(int *)local_28 == -1) {
          return;
        }
        LOCK();
        *(int *)local_28 = *(int *)local_28 + -1;
        UNLOCK();
        if (*(int *)local_28 != 0) {
          return;
        }
      }
      QArrayData::deallocate(local_28,2,8);
      return;
    case 0x93:
      FUN_005b9b0e();
      return;
    case 0x94:
      FUN_005b9b84();
      return;
    case 0x95:
      local_28 = *(QArrayData **)param_4[2];
      if ((*(int *)local_28 != 0) && (*(int *)local_28 != -1)) {
        LOCK();
        *(int *)local_28 = *(int *)local_28 + 1;
        UNLOCK();
      }
                    /* try { // try from 008f4a9d to 008f4aa1 has its CatchHandler @ 008f6473 */
      FUN_005c684e(param_1,param_4[1],&local_28);
      if (*(int *)local_28 != 0) {
        if (*(int *)local_28 == -1) {
          return;
        }
        LOCK();
        *(int *)local_28 = *(int *)local_28 + -1;
        UNLOCK();
        if (*(int *)local_28 != 0) {
          return;
        }
      }
      QArrayData::deallocate(local_28,2,8);
      return;
    case 0x96:
      local_28 = (QArrayData *)&QArrayData::shared_null;
                    /* try { // try from 008f4af1 to 008f4af5 has its CatchHandler @ 008f6463 */
      FUN_005c684e(param_1,param_4[1],&local_28);
      if (*(int *)local_28 != 0) {
        if (*(int *)local_28 == -1) {
          return;
        }
        LOCK();
        *(int *)local_28 = *(int *)local_28 + -1;
        UNLOCK();
        if (*(int *)local_28 != 0) {
          return;
        }
      }
      QArrayData::deallocate(local_28,2,8);
      return;
    case 0x97:
      FUN_005b9e42(param_1,param_4[1],*(undefined4 *)param_4[2]);
      return;
    case 0x98:
      FUN_005b9e42(param_1,param_4[1],1);
      return;
    case 0x99:
      uVar8 = FUN_005b9f38(param_1,*(undefined4 *)param_4[1]);
      if ((undefined8 *)*param_4 == (undefined8 *)0x0) {
        return;
      }
      *(undefined8 *)*param_4 = uVar8;
      return;
    case 0x9a:
      uVar8 = FUN_005b9f38(param_1,0xffffffff);
      if ((undefined8 *)*param_4 == (undefined8 *)0x0) {
        return;
      }
      *(undefined8 *)*param_4 = uVar8;
      return;
    case 0x9b:
      uVar8 = FUN_005ba06c(param_1,*(undefined4 *)param_4[1]);
      if ((undefined8 *)*param_4 == (undefined8 *)0x0) {
        return;
      }
      *(undefined8 *)*param_4 = uVar8;
      return;
    case 0x9c:
      uVar8 = FUN_005ba06c(param_1,0xffffffff);
      if ((undefined8 *)*param_4 == (undefined8 *)0x0) {
        return;
      }
      *(undefined8 *)*param_4 = uVar8;
      return;
    case 0x9d:
      uVar7 = FUN_005ba266();
      if ((undefined4 *)*param_4 == (undefined4 *)0x0) {
        return;
      }
      *(undefined4 *)*param_4 = uVar7;
      return;
    case 0x9e:
      uVar8 = FUN_005ba388(param_1,*(undefined4 *)param_4[1]);
      if ((undefined8 *)*param_4 == (undefined8 *)0x0) {
        return;
      }
      *(undefined8 *)*param_4 = uVar8;
      return;
    case 0x9f:
      uVar8 = FUN_005ba388(param_1,0xffffffff);
      if ((undefined8 *)*param_4 == (undefined8 *)0x0) {
        return;
      }
      *(undefined8 *)*param_4 = uVar8;
      return;
    case 0xa0:
      uVar8 = FUN_005ba54e(param_1,*(undefined4 *)param_4[1]);
      if ((undefined8 *)*param_4 == (undefined8 *)0x0) {
        return;
      }
      *(undefined8 *)*param_4 = uVar8;
      return;
    case 0xa1:
      uVar8 = FUN_005ba54e(param_1,0xffffffff);
      if ((undefined8 *)*param_4 == (undefined8 *)0x0) {
        return;
      }
      *(undefined8 *)*param_4 = uVar8;
      return;
    case 0xa2:
      FUN_005ba71c(&local_28,param_1,param_4[1],*(undefined1 *)param_4[2]);
      puVar4 = (undefined8 *)*param_4;
      if (puVar4 != (undefined8 *)0x0) {
        pQVar5 = (QArrayData *)*puVar4;
        *puVar4 = local_28;
        local_28 = pQVar5;
      }
      if (*(int *)local_28 != 0) {
        if (*(int *)local_28 == -1) {
          return;
        }
        LOCK();
        *(int *)local_28 = *(int *)local_28 + -1;
        UNLOCK();
        if (*(int *)local_28 != 0) {
          return;
        }
      }
      QArrayData::deallocate(local_28,2,8);
      return;
    case 0xa3:
      FUN_005ba71c(&local_28,param_1,param_4[1],0);
      puVar4 = (undefined8 *)*param_4;
      if (puVar4 != (undefined8 *)0x0) {
        pQVar5 = (QArrayData *)*puVar4;
        *puVar4 = local_28;
        local_28 = pQVar5;
      }
      if (*(int *)local_28 != 0) {
        if (*(int *)local_28 == -1) {
          return;
        }
        LOCK();
        *(int *)local_28 = *(int *)local_28 + -1;
        UNLOCK();
        if (*(int *)local_28 != 0) {
          return;
        }
      }
      QArrayData::deallocate(local_28,2,8);
      return;
    case 0xa4:
      local_28 = (QArrayData *)&QArrayData::shared_null;
                    /* try { // try from 008f4cdf to 008f4ce3 has its CatchHandler @ 008f64bd */
      FUN_005ba71c(&local_38,param_1,&local_28,0);
      if (*(int *)local_28 != 0) {
        if (*(int *)local_28 == -1) goto LAB_008f4d02;
        LOCK();
        *(int *)local_28 = *(int *)local_28 + -1;
        UNLOCK();
        if (*(int *)local_28 != 0) goto LAB_008f4d02;
      }
      QArrayData::deallocate(local_28,2,8);
LAB_008f4d02:
      puVar4 = (undefined8 *)*param_4;
      if (puVar4 != (undefined8 *)0x0) {
        pQVar5 = (QArrayData *)*puVar4;
        *puVar4 = local_38;
        local_38 = pQVar5;
      }
      if (*(int *)local_38 != 0) {
        if (*(int *)local_38 == -1) {
          return;
        }
        LOCK();
        *(int *)local_38 = *(int *)local_38 + -1;
        UNLOCK();
        if (*(int *)local_38 != 0) {
          return;
        }
      }
      QArrayData::deallocate(local_38,2,8);
      return;
    case 0xa5:
      FUN_005baabc();
      return;
    case 0xa6:
      FUN_005bab32();
      return;
    case 0xa7:
      FUN_005babb8();
      return;
    case 0xa8:
      FUN_005bac3e();
      return;
    case 0xa9:
      FUN_005bacc4();
      return;
    case 0xaa:
      FUN_005bad4a();
      return;
    case 0xab:
      FUN_005badd0();
      return;
    case 0xac:
      FUN_005bae56();
      return;
    case 0xad:
      FUN_005baedc(param_1,param_4[1],*(undefined4 *)param_4[2]);
      return;
    case 0xae:
      FUN_005baedc(param_1,param_4[1],1);
      return;
    case 0xaf:
      FUN_005bafd2();
      return;
    case 0xb0:
      FUN_005bcf78(param_1,*(undefined4 *)param_4[1]);
      return;
    case 0xb1:
      FUN_005bd03a(param_1,*(undefined1 *)param_4[1]);
      return;
    case 0xb2:
      FUN_005bd0e8(param_1,*(undefined4 *)param_4[1]);
      return;
    case 0xb3:
      FUN_005bd350(param_1,*(undefined1 *)param_4[1]);
      return;
    case 0xb4:
      FUN_005c1416(param_1,*(undefined4 *)param_4[1]);
      return;
    case 0xb5:
      FUN_005bdc2e(param_1,param_4[1]);
      return;
    case 0xb6:
      FUN_005bdc82(param_1,*(undefined1 *)param_4[1]);
      return;
    case 0xb7:
      FUN_005be2f8(param_1,*(undefined1 *)param_4[1]);
      return;
    case 0xb8:
      FUN_005c6fae(param_1,param_4[1],param_4[2]);
      return;
    case 0xb9:
      FUN_005be704(param_1,*(undefined8 *)param_4[1]);
      return;
    case 0xba:
      FUN_005be77e(param_1,*(undefined8 *)param_4[1],*(undefined8 *)param_4[2]);
      return;
    case 0xbb:
      FUN_005bec4c(param_1,*(undefined4 *)param_4[1],*(undefined4 *)param_4[2]);
      return;
    case 0xbc:
      FUN_005bec4c(param_1,*(undefined4 *)param_4[1],0xffffffff);
      return;
    case 0xbd:
      FUN_005c1504(param_1,*(undefined4 *)param_4[1]);
      return;
    case 0xbe:
      FUN_005c15f2(param_1,*(undefined4 *)param_4[1]);
      return;
    case 0xbf:
      FUN_005befd8(param_1,*(undefined1 *)param_4[1]);
      return;
    case 0xc0:
      FUN_005bf1ae(param_1,param_4[1],*(undefined1 *)param_4[2]);
      return;
    case 0xc1:
      FUN_005bf1ae(param_1,param_4[1],0);
      return;
    case 0xc2:
      FUN_005bf3fc(param_1,*(undefined4 *)param_4[1]);
      return;
    case 0xc3:
      FUN_005bf76a();
      return;
    case 0xc4:
      FUN_005c63d8(&local_28,param_1,*(undefined8 *)param_4[1],*(undefined8 *)param_4[2]);
      puVar4 = (undefined8 *)*param_4;
      if (puVar4 != (undefined8 *)0x0) {
        pQVar5 = (QArrayData *)*puVar4;
        *puVar4 = local_28;
        local_28 = pQVar5;
      }
      if (*(int *)local_28 != 0) {
        if (*(int *)local_28 == -1) {
          return;
        }
        LOCK();
        *(int *)local_28 = *(int *)local_28 + -1;
        UNLOCK();
        if (*(int *)local_28 != 0) {
          return;
        }
      }
      QArrayData::deallocate(local_28,1,8);
      return;
    case 0xc5:
      FUN_005c63d8(&local_28,param_1,*(undefined8 *)param_4[1],0xffffffffffffffff);
      puVar4 = (undefined8 *)*param_4;
      if (puVar4 != (undefined8 *)0x0) {
        pQVar5 = (QArrayData *)*puVar4;
        *puVar4 = local_28;
        local_28 = pQVar5;
      }
      if (*(int *)local_28 != 0) {
        if (*(int *)local_28 == -1) {
          return;
        }
        LOCK();
        *(int *)local_28 = *(int *)local_28 + -1;
        UNLOCK();
        if (*(int *)local_28 != 0) {
          return;
        }
      }
      QArrayData::deallocate(local_28,1,8);
      return;
    case 0xc6:
      FUN_005c0c32(&local_28,param_1,*(undefined8 *)param_4[1],*(undefined8 *)param_4[2]);
      puVar4 = (undefined8 *)*param_4;
      if (puVar4 != (undefined8 *)0x0) {
        pQVar5 = (QArrayData *)*puVar4;
        *puVar4 = local_28;
        local_28 = pQVar5;
      }
      if (*(int *)local_28 != 0) {
        if (*(int *)local_28 == -1) {
          return;
        }
        LOCK();
        *(int *)local_28 = *(int *)local_28 + -1;
        UNLOCK();
        if (*(int *)local_28 != 0) {
          return;
        }
      }
      QArrayData::deallocate(local_28,2,8);
      return;
    case 199:
      FUN_005c0c32(&local_28,param_1,*(undefined8 *)param_4[1],0xffffffffffffffff);
      puVar4 = (undefined8 *)*param_4;
      if (puVar4 != (undefined8 *)0x0) {
        pQVar5 = (QArrayData *)*puVar4;
        *puVar4 = local_28;
        local_28 = pQVar5;
      }
      if (*(int *)local_28 != 0) {
        if (*(int *)local_28 == -1) {
          return;
        }
        LOCK();
        *(int *)local_28 = *(int *)local_28 + -1;
        UNLOCK();
        if (*(int *)local_28 != 0) {
          return;
        }
      }
      QArrayData::deallocate(local_28,2,8);
      return;
    case 200:
      FUN_005c0d18();
      return;
    case 0xc9:
      uVar7 = FUN_005c0d8e();
      if ((undefined4 *)*param_4 == (undefined4 *)0x0) {
        return;
      }
      *(undefined4 *)*param_4 = uVar7;
      return;
    case 0xca:
      FUN_005c0fdc(param_1,*(undefined8 *)param_4[1]);
      return;
    case 0xcb:
      FUN_005c105e(param_1,*(undefined8 *)param_4[1],*(undefined1 *)param_4[2]);
      return;
    case 0xcc:
      FUN_005c105e(param_1,*(undefined8 *)param_4[1],0);
      return;
    case 0xcd:
      FUN_005c10da(param_1,*(undefined8 *)param_4[1],*(undefined8 *)param_4[2]);
      return;
    case 0xce:
      FUN_005c1156(param_1,param_4[1]);
      return;
    case 0xcf:
      FUN_005c11f0(param_1,*(undefined4 *)param_4[1]);
      return;
    case 0xd0:
      uVar7 = FUN_005c1384();
      if ((undefined4 *)*param_4 == (undefined4 *)0x0) {
        return;
      }
      *(undefined4 *)*param_4 = uVar7;
      return;
    case 0xd1:
      uVar6 = FUN_005c16e0();
      if ((undefined1 *)*param_4 == (undefined1 *)0x0) {
        return;
      }
      *(undefined1 *)*param_4 = uVar6;
      return;
    case 0xd2:
      uVar8 = FUN_005c1802(param_1,*(undefined8 *)param_4[1]);
      if ((undefined8 *)*param_4 == (undefined8 *)0x0) {
        return;
      }
      *(undefined8 *)*param_4 = uVar8;
      return;
    case 0xd3:
      uVar8 = FUN_005c189c(param_1,*(undefined8 *)param_4[1]);
      if ((undefined8 *)*param_4 == (undefined8 *)0x0) {
        return;
      }
      *(undefined8 *)*param_4 = uVar8;
      return;
    case 0xd4:
      uVar8 = FUN_005c1936(param_1,param_4[1]);
      if ((undefined8 *)*param_4 == (undefined8 *)0x0) {
        return;
      }
      *(undefined8 *)*param_4 = uVar8;
      return;
    case 0xd5:
      uVar8 = FUN_005c19e6(param_1,*(undefined8 *)param_4[1]);
      if ((undefined8 *)*param_4 == (undefined8 *)0x0) {
        return;
      }
      *(undefined8 *)*param_4 = uVar8;
      return;
    case 0xd6:
      uVar8 = FUN_005c1a80(param_1,*(undefined8 *)param_4[1]);
      if ((undefined8 *)*param_4 == (undefined8 *)0x0) {
        return;
      }
      *(undefined8 *)*param_4 = uVar8;
      return;
    case 0xd7:
      auVar9 = FUN_005c1b1a(param_1,param_4[1]);
      if ((undefined1 (*) [16])*param_4 == (undefined1 (*) [16])0x0) {
        return;
      }
      *(undefined1 (*) [16])*param_4 = auVar9;
      return;
    case 0xd8:
      auVar9 = FUN_005c1bc0(param_1,*(undefined8 *)param_4[1]);
      if ((undefined1 (*) [16])*param_4 == (undefined1 (*) [16])0x0) {
        return;
      }
      *(undefined1 (*) [16])*param_4 = auVar9;
      return;
    case 0xd9:
      FUN_005c1c66(&local_28,param_1,*(undefined1 *)param_4[1]);
      puVar4 = (undefined8 *)*param_4;
      if (puVar4 != (undefined8 *)0x0) {
        pQVar5 = (QArrayData *)*puVar4;
        *puVar4 = local_28;
        local_28 = pQVar5;
      }
      if (*(int *)local_28 != 0) {
        if (*(int *)local_28 == -1) {
          return;
        }
        LOCK();
        *(int *)local_28 = *(int *)local_28 + -1;
        UNLOCK();
        if (*(int *)local_28 != 0) {
          return;
        }
      }
      QArrayData::deallocate(local_28,2,8);
      return;
    case 0xda:
      FUN_005c1c66(&local_28,param_1,0);
      puVar4 = (undefined8 *)*param_4;
      if (puVar4 != (undefined8 *)0x0) {
        pQVar5 = (QArrayData *)*puVar4;
        *puVar4 = local_28;
        local_28 = pQVar5;
      }
      if (*(int *)local_28 != 0) {
        if (*(int *)local_28 == -1) {
          return;
        }
        LOCK();
        *(int *)local_28 = *(int *)local_28 + -1;
        UNLOCK();
        if (*(int *)local_28 != 0) {
          return;
        }
      }
      QArrayData::deallocate(local_28,2,8);
      return;
    case 0xdb:
      uVar8 = FUN_005c1d08(param_1,*(undefined8 *)param_4[1],*(undefined1 *)param_4[2]);
      if ((undefined8 *)*param_4 == (undefined8 *)0x0) {
        return;
      }
      *(undefined8 *)*param_4 = uVar8;
      return;
    case 0xdc:
      uVar8 = FUN_005c1d08(param_1,*(undefined8 *)param_4[1],1);
      if ((undefined8 *)*param_4 == (undefined8 *)0x0) {
        return;
      }
      *(undefined8 *)*param_4 = uVar8;
      return;
    case 0xdd:
      uVar8 = FUN_005c1d9c(param_1,*(undefined8 *)param_4[1],*(undefined1 *)param_4[2]);
      if ((undefined8 *)*param_4 == (undefined8 *)0x0) {
        return;
      }
      *(undefined8 *)*param_4 = uVar8;
      return;
    case 0xde:
      uVar8 = FUN_005c1d9c(param_1,*(undefined8 *)param_4[1],1);
      if ((undefined8 *)*param_4 == (undefined8 *)0x0) {
        return;
      }
      *(undefined8 *)*param_4 = uVar8;
      return;
    case 0xdf:
      uVar7 = FUN_005c1e30();
      if ((undefined4 *)*param_4 == (undefined4 *)0x0) {
        return;
      }
      *(undefined4 *)*param_4 = uVar7;
      return;
    case 0xe0:
      uVar7 = FUN_005c1ec2();
      if ((undefined4 *)*param_4 == (undefined4 *)0x0) {
        return;
      }
      *(undefined4 *)*param_4 = uVar7;
      return;
    case 0xe1:
      FUN_005c1f54();
      return;
    case 0xe2:
      FUN_005c1fca();
      return;
    default:
      return;
    }
  }
  if (param_2 != 10) {
    if (param_2 == 1) {
      puVar4 = (undefined8 *)*param_4;
      switch(param_3) {
      case 0:
        uVar7 = FUN_005ba1a8();
        *(undefined4 *)puVar4 = uVar7;
        return;
      case 1:
        uVar8 = FUN_005b8610();
        *puVar4 = uVar8;
        return;
      case 2:
        uVar8 = FUN_005ba1f6();
        *puVar4 = uVar8;
        return;
      case 3:
        uVar8 = FUN_005b643a();
        *puVar4 = uVar8;
        return;
      case 4:
        uVar8 = FUN_005c1770();
        *puVar4 = uVar8;
        return;
      case 5:
        uVar7 = FUN_005b8326();
        *(undefined4 *)puVar4 = uVar7;
        return;
      case 6:
        uVar8 = FUN_005b83b8();
        *puVar4 = uVar8;
        return;
      case 7:
        uVar8 = FUN_005b844a();
        *puVar4 = uVar8;
        return;
      case 8:
        uVar7 = FUN_005b99de();
        *(undefined4 *)puVar4 = uVar7;
        return;
      case 9:
        uVar8 = FUN_005b9a70();
        *puVar4 = uVar8;
        return;
      case 10:
        uVar8 = FUN_005b9d2e();
        *puVar4 = uVar8;
        return;
      default:
        return;
      }
    }
    if (param_2 != 2) {
      return;
    }
    puVar4 = (undefined8 *)*param_4;
    if (param_3 == 9) {
      FUN_005be592(param_1,*puVar4);
      return;
    }
    if (param_3 != 10) {
      if (param_3 != 5) {
        return;
      }
      s_editor_commandModeEnabled_5bd926(param_1,*(undefined4 *)puVar4);
      return;
    }
    FUN_005be68c(param_1,*puVar4);
    return;
  }
  puVar1 = (undefined4 *)*param_4;
  plVar2 = (long *)param_4[1];
  pcVar3 = (code *)*plVar2;
  if ((pcVar3 == FUN_008f2ea0) && (plVar2[1] == 0)) {
    *puVar1 = 0;
    return;
  }
  if ((pcVar3 == FUN_008f2f52) && (plVar2[1] == 0)) {
    *puVar1 = 1;
    return;
  }
  if (pcVar3 == FUN_008f2ed4) {
    if (plVar2[1] == 0) {
      *puVar1 = 2;
      return;
    }
  }
  else if ((pcVar3 == FUN_008f2efe) && (plVar2[1] == 0)) {
    *puVar1 = 3;
    return;
  }
  if ((pcVar3 == FUN_008f2fda) && (plVar2[1] == 0)) {
    *puVar1 = 4;
    return;
  }
  if ((pcVar3 == FUN_008f2d38) && (plVar2[1] == 0)) {
    *puVar1 = 5;
    return;
  }
  if ((pcVar3 == FUN_008f30e8) && (plVar2[1] == 0)) {
    *puVar1 = 6;
    return;
  }
  if (pcVar3 == FUN_008f2d4c) {
    if (plVar2[1] == 0) {
      *puVar1 = 7;
      return;
    }
  }
  else if ((pcVar3 == FUN_008f2d60) && (plVar2[1] == 0)) {
    *puVar1 = 8;
    return;
  }
  if ((pcVar3 == FUN_008f34f4) && (plVar2[1] == 0)) {
    *puVar1 = 9;
    return;
  }
  if ((pcVar3 == FUN_008f3010) && (plVar2[1] == 0)) {
    *puVar1 = 10;
    return;
  }
  if ((pcVar3 == FUN_008f313c) && (plVar2[1] == 0)) {
    *puVar1 = 0xb;
    return;
  }
  if (pcVar3 == FUN_008f360a) {
    if (plVar2[1] == 0) {
      *puVar1 = 0xc;
      return;
    }
LAB_008f3b63:
    if ((pcVar3 == FUN_008f369e) && (plVar2[1] == 0)) {
      *puVar1 = 0xe;
      return;
    }
  }
  else {
    if (pcVar3 != FUN_008f3654) goto LAB_008f3b63;
    if (plVar2[1] == 0) {
      *puVar1 = 0xd;
      return;
    }
  }
  if ((pcVar3 == FUN_008f38f4) && (plVar2[1] == 0)) {
    *puVar1 = 0xf;
    return;
  }
  if ((pcVar3 == FUN_008f391e) && (plVar2[1] == 0)) {
    *puVar1 = 0x10;
    return;
  }
  if ((pcVar3 == FUN_008f2d74) && (plVar2[1] == 0)) {
    *puVar1 = 0x11;
    return;
  }
  if ((pcVar3 == FUN_008f2d88) && (plVar2[1] == 0)) {
    *puVar1 = 0x12;
    return;
  }
  if ((pcVar3 == FUN_008f2d9c) && (plVar2[1] == 0)) {
    *puVar1 = 0x13;
    return;
  }
  if ((pcVar3 == FUN_008f2db0) && (plVar2[1] == 0)) {
    *puVar1 = 0x14;
    return;
  }
  if ((pcVar3 == FUN_008f2dc4) && (plVar2[1] == 0)) {
    *puVar1 = 0x15;
    return;
  }
  if (pcVar3 == FUN_008f2dd8) {
    if (plVar2[1] == 0) {
      *puVar1 = 0x16;
      return;
    }
LAB_008f3be5:
    if ((pcVar3 == FUN_008f2e00) && (plVar2[1] == 0)) {
      *puVar1 = 0x18;
      return;
    }
  }
  else {
    if (pcVar3 != FUN_008f2dec) goto LAB_008f3be5;
    if (plVar2[1] == 0) {
      *puVar1 = 0x17;
      return;
    }
  }
  if (pcVar3 == FUN_008f36e8) {
    if (plVar2[1] == 0) {
      *puVar1 = 0x19;
      return;
    }
LAB_008f3c0c:
    if ((pcVar3 == FUN_008f377c) && (plVar2[1] == 0)) {
      *puVar1 = 0x1b;
      return;
    }
  }
  else {
    if (pcVar3 != FUN_008f3732) goto LAB_008f3c0c;
    if (plVar2[1] == 0) {
      *puVar1 = 0x1a;
      return;
    }
  }
  if (pcVar3 == FUN_008f357a) {
    if (plVar2[1] == 0) {
      *puVar1 = 0x1c;
      return;
    }
  }
  else if ((pcVar3 == FUN_008f35c2) && (plVar2[1] == 0)) {
    *puVar1 = 0x1d;
    return;
  }
  if ((pcVar3 == FUN_008f3954) && (plVar2[1] == 0)) {
    *puVar1 = 0x1e;
    return;
  }
  if ((pcVar3 == FUN_008f39a6) && (plVar2[1] == 0)) {
    *puVar1 = 0x1f;
    return;
  }
  if ((pcVar3 == FUN_008f353a) && (plVar2[1] == 0)) {
    *puVar1 = 0x20;
    return;
  }
  if ((pcVar3 == FUN_008f37c6) && (plVar2[1] == 0)) {
    *puVar1 = 0x21;
    return;
  }
  if (pcVar3 == FUN_008f3180) {
    if (plVar2[1] == 0) {
      *puVar1 = 0x22;
      return;
    }
LAB_008f6058:
    if (pcVar3 != FUN_008f31f0) {
LAB_008f3c8e:
      if ((pcVar3 == FUN_008f3228) && (plVar2[1] == 0)) {
        *puVar1 = 0x25;
        return;
      }
    }
  }
  else {
    if (pcVar3 == FUN_008f31b8) {
      if (plVar2[1] == 0) {
        *puVar1 = 0x23;
        return;
      }
      goto LAB_008f6058;
    }
    if (pcVar3 != FUN_008f31f0) goto LAB_008f3c8e;
    if (plVar2[1] == 0) {
      *puVar1 = 0x24;
      return;
    }
  }
  if (pcVar3 == FUN_008f3816) {
    if (plVar2[1] == 0) {
      *puVar1 = 0x26;
      return;
    }
LAB_008f3cb5:
    if ((pcVar3 == FUN_008f38aa) && (plVar2[1] == 0)) {
      *puVar1 = 0x28;
      return;
    }
  }
  else {
    if (pcVar3 != FUN_008f3860) goto LAB_008f3cb5;
    if (plVar2[1] == 0) {
      *puVar1 = 0x27;
      return;
    }
  }
  if ((pcVar3 == FUN_008f3260) && (plVar2[1] == 0)) {
    *puVar1 = 0x29;
    return;
  }
  if (pcVar3 == FUN_008f2e14) {
    if (plVar2[1] == 0) {
      *puVar1 = 0x2a;
      return;
    }
LAB_008f3ce9:
    if ((pcVar3 == FUN_008f2e3c) && (plVar2[1] == 0)) {
      *puVar1 = 0x2c;
      return;
    }
  }
  else {
    if (pcVar3 != FUN_008f2e28) goto LAB_008f3ce9;
    if (plVar2[1] == 0) {
      *puVar1 = 0x2b;
      return;
    }
  }
  if ((pcVar3 == FUN_008f32b6) && (plVar2[1] == 0)) {
    *puVar1 = 0x2d;
    return;
  }
  if ((pcVar3 == FUN_008f2fa2) && (plVar2[1] == 0)) {
    *puVar1 = 0x2e;
    return;
  }
  if ((pcVar3 == FUN_008f32fa) && (plVar2[1] == 0)) {
    *puVar1 = 0x2f;
    return;
  }
  if ((pcVar3 == FUN_008f2f28) && (plVar2[1] == 0)) {
    *puVar1 = 0x30;
    return;
  }
  if (pcVar3 == FUN_008f2e50) {
    if (plVar2[1] == 0) {
      *puVar1 = 0x31;
      return;
    }
  }
  else if (pcVar3 == FUN_008f2e64) {
    if (plVar2[1] == 0) {
      *puVar1 = 0x32;
      return;
    }
    goto LAB_008f3d51;
  }
  if ((pcVar3 == FUN_008f2e78) && (plVar2[1] == 0)) {
    *puVar1 = 0x33;
    return;
  }
LAB_008f3d51:
  if (pcVar3 == FUN_008f333e) {
    if (plVar2[1] == 0) {
      *puVar1 = 0x34;
      return;
    }
  }
  else if ((pcVar3 == FUN_008f3382) && (plVar2[1] == 0)) {
    *puVar1 = 0x35;
    return;
  }
  if ((pcVar3 == FUN_008f33c6) && (plVar2[1] == 0)) {
    *puVar1 = 0x36;
  }
  else if ((pcVar3 == FUN_008f39dc) && (plVar2[1] == 0)) {
    *puVar1 = 0x37;
  }
  else if ((pcVar3 == FUN_008f3428) && (plVar2[1] == 0)) {
    *puVar1 = 0x38;
  }
  else if ((pcVar3 == FUN_008f2e8c) && (plVar2[1] == 0)) {
    *puVar1 = 0x39;
  }
  else {
    if (pcVar3 == FUN_008f3046) {
      if (plVar2[1] == 0) {
        *puVar1 = 0x3a;
        return;
      }
    }
    else if ((pcVar3 == FUN_008f307c) && (plVar2[1] == 0)) {
      *puVar1 = 0x3b;
      return;
    }
    if ((pcVar3 == FUN_008f34a8) && (plVar2[1] == 0)) {
      *puVar1 = 0x3c;
    }
    else if ((pcVar3 == FUN_008f30b2) && (plVar2[1] == 0)) {
      *puVar1 = 0x3d;
    }
  }
  return;
switchD_008f3aa1_caseD_8c:
  pcVar3 = *(code **)(*param_1 + 0x1e8);
  local_28 = *(QArrayData **)param_4[1];
  if ((*(int *)local_28 != 0) && (*(int *)local_28 != -1)) {
    LOCK();
    *(int *)local_28 = *(int *)local_28 + 1;
    UNLOCK();
  }
                    /* try { // try from 008f4625 to 008f4626 has its CatchHandler @ 008f6485 */
  (*pcVar3)(&local_38,param_1,&local_28);
  if (*(int *)local_28 != 0) {
    if (*(int *)local_28 == -1) goto LAB_008f4645;
    LOCK();
    *(int *)local_28 = *(int *)local_28 + -1;
    UNLOCK();
    if (*(int *)local_28 != 0) goto LAB_008f4645;
  }
  QArrayData::deallocate(local_28,2,8);
LAB_008f4645:
  puVar4 = (undefined8 *)*param_4;
  if (puVar4 != (undefined8 *)0x0) {
    pQVar5 = (QArrayData *)*puVar4;
    *puVar4 = local_38;
    local_38 = pQVar5;
  }
  if (*(int *)local_38 != 0) {
    if (*(int *)local_38 == -1) {
      return;
    }
    LOCK();
    *(int *)local_38 = *(int *)local_38 + -1;
    UNLOCK();
    if (*(int *)local_38 != 0) {
      return;
    }
  }
  QArrayData::deallocate(local_38,2,8);
  return;
}


// ==== entry=008f64ce name=FUN_008f64ce size=182 ====

ulong FUN_008f64ce(undefined8 param_1,int param_2,undefined8 param_3,undefined8 *param_4)

{
  int iVar1;
  ulong uVar2;
  
  uVar2 = FUN_0091dedc();
  iVar1 = (int)uVar2;
  if (-1 < iVar1) {
    if (param_2 == 0) {
      if (iVar1 < 0xe3) {
        FUN_008f3a74(param_1,0,uVar2 & 0xffffffff,param_4);
        uVar2 = uVar2 & 0xffffffff;
      }
    }
    else {
      if (param_2 != 0xc) {
        if ((param_2 - 1U < 3) || (param_2 == 0xb)) {
          FUN_008f3a74(param_1,param_2,uVar2 & 0xffffffff,param_4);
          return (ulong)(iVar1 - 0xb);
        }
        if ((((param_2 != 4) && (param_2 != 5)) && (param_2 != 6)) &&
           ((param_2 != 7 && (param_2 != 8)))) {
          return uVar2;
        }
        return (ulong)(iVar1 - 0xb);
      }
      if (iVar1 < 0xe3) {
        *(undefined4 *)*param_4 = 0xffffffff;
      }
    }
    uVar2 = (ulong)((int)uVar2 - 0xe3);
  }
  return uVar2;
}


// ==== entry=008f6584 name=FUN_008f6584 size=1 ====

void FUN_008f6584(void)

{
  return;
}


// ==== entry=008f6586 orig=FUN_008f6586 size=24 name=CommandPalette_metaObject ====

undefined ** CommandPalette_metaObject(long param_1)

{
  undefined **ppuVar1;
  
  if (*(long *)(*(long *)(param_1 + 8) + 0x28) != 0) {
    ppuVar1 = (undefined **)QObjectData::dynamicMetaObject();
    return ppuVar1;
  }
  return &PTR_staticMetaObject_01197cc0;
}


// ==== entry=008f659e orig=FUN_008f659e size=66 name=CommandPalette_qt_metacast ====

char * CommandPalette_qt_metacast(char *param_1,char *param_2)

{
  int iVar1;
  char *pcVar2;
  
  if (param_2 == (char *)0x0) {
    return (char *)0x0;
  }
  iVar1 = strcmp(param_2,"CommandPalette");
  if (iVar1 == 0) {
    return param_1;
  }
  pcVar2 = (char *)QFrame::qt_metacast(param_1);
  return pcVar2;
}


// ==== entry=008f65e0 orig=FUN_008f65e0 size=5 name=CommandPalette_qt_metacall ====

void QFrame::CommandPalette_qt_metacall(void)

{
  qt_metacall();
  return;
}


// ==== entry=008f65f0 orig=FUN_008f65f0 size=24 name=TabBar_metaObject ====

undefined ** TabBar_metaObject(long param_1)

{
  undefined **ppuVar1;
  
  if (*(long *)(*(long *)(param_1 + 8) + 0x28) != 0) {
    ppuVar1 = (undefined **)QObjectData::dynamicMetaObject();
    return ppuVar1;
  }
  return &PTR_staticMetaObject_01197f40;
}


// ==== entry=008f6608 name=FUN_008f6608 size=16 ====

void FUN_008f6608(QObject *param_1)

{
  QMetaObject::activate(param_1,(QMetaObject *)&PTR_staticMetaObject_01197f40,0,(void **)0x0);
  return;
}


// ==== entry=008f6618 name=FUN_008f6618 size=153 ====

void FUN_008f6618(long param_1,int param_2,int param_3,undefined8 *param_4)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  
  if (param_2 == 0) {
    if (param_3 == 0) {
      FUN_008f6608();
      return;
    }
  }
  else if (param_2 == 10) {
    if ((*(code **)param_4[1] == FUN_008f6608) && (((long *)param_4[1])[1] == 0)) {
      *(undefined4 *)*param_4 = 0;
      return;
    }
  }
  else if (param_2 == 1) {
    param_4 = (undefined8 *)*param_4;
    if (param_3 == 1) {
      *param_4 = *(undefined8 *)(param_1 + 0x4c);
      return;
    }
    if (param_3 == 2) {
      *(undefined1 *)param_4 = *(undefined1 *)(param_1 + 0x30);
      return;
    }
    if (param_3 == 0) {
      *param_4 = *(undefined8 *)(param_1 + 0x44);
      return;
    }
  }
  else if (param_2 == 2) {
    puVar2 = (undefined4 *)*param_4;
    if (param_3 == 1) {
      uVar1 = *puVar2;
      *(undefined4 *)(param_1 + 0x4c) = puVar2[1];
      *(undefined4 *)(param_1 + 0x50) = uVar1;
      return;
    }
    if (param_3 == 2) {
      FUN_005a84f6(param_1,*(undefined1 *)puVar2);
      return;
    }
    if (param_3 == 0) {
      uVar1 = *puVar2;
      *(undefined4 *)(param_1 + 0x44) = puVar2[1];
      *(undefined4 *)(param_1 + 0x48) = uVar1;
      return;
    }
  }
  return;
}


// ==== entry=008f66b2 orig=FUN_008f66b2 size=66 name=TabBar_qt_metacast ====

char * TabBar_qt_metacast(char *param_1,char *param_2)

{
  int iVar1;
  char *pcVar2;
  
  if (param_2 == (char *)0x0) {
    return (char *)0x0;
  }
  iVar1 = strcmp(param_2,"TabBar");
  if (iVar1 == 0) {
    return param_1;
  }
  pcVar2 = (char *)QTabBar::qt_metacast(param_1);
  return pcVar2;
}


// ==== entry=008f66f4 orig=FUN_008f66f4 size=166 name=TabBar_qt_metacall ====

ulong TabBar_qt_metacall(undefined8 param_1,int param_2,undefined8 param_3,undefined8 *param_4)

{
  int iVar1;
  ulong uVar2;
  
  uVar2 = QTabBar::qt_metacall();
  iVar1 = (int)uVar2;
  if (-1 < iVar1) {
    if (param_2 == 0) {
      if (iVar1 == 0) {
        FUN_008f6608(param_1);
        uVar2 = uVar2 & 0xffffffff;
      }
    }
    else {
      if (param_2 != 0xc) {
        if ((param_2 - 1U < 3) || (param_2 == 0xb)) {
          FUN_008f6618(param_1,param_2,uVar2 & 0xffffffff,param_4);
          return (ulong)(iVar1 - 3);
        }
        if ((((param_2 != 4) && (param_2 != 5)) && (param_2 != 6)) &&
           ((param_2 != 7 && (param_2 != 8)))) {
          return uVar2;
        }
        return (ulong)(iVar1 - 3);
      }
      if (iVar1 == 0) {
        *(undefined4 *)*param_4 = 0xffffffff;
      }
    }
    uVar2 = (ulong)((int)uVar2 - 1);
  }
  return uVar2;
}


// ==== entry=008f67a0 name=FUN_008f67a0 size=92 ====

void FUN_008f67a0(undefined8 *param_1)

{
  int iVar1;
  Data *pDVar2;
  Data *pDVar3;
  
  pDVar2 = (Data *)*param_1;
  if (*(int *)pDVar2 == 0) {
LAB_008f67c0:
    pDVar3 = pDVar2 + (long)*(int *)(pDVar2 + 0xc) * 8 + 0x10;
    iVar1 = *(int *)(pDVar2 + 8);
    while (pDVar3 != pDVar2 + (long)iVar1 * 8 + 0x10) {
      pDVar3 = pDVar3 + -8;
      operator_delete(*(void **)pDVar3,0x10);
    }
    QListData::dispose(pDVar2);
    return;
  }
  if (*(int *)pDVar2 != -1) {
    LOCK();
    *(int *)pDVar2 = *(int *)pDVar2 + -1;
    UNLOCK();
    if (*(int *)pDVar2 == 0) {
      pDVar2 = (Data *)*param_1;
      goto LAB_008f67c0;
    }
  }
  return;
}


// ==== entry=008f67fc name=FUN_008f67fc size=256 ====

void FUN_008f67fc(undefined8 *param_1)

{
  int iVar1;
  int iVar2;
  undefined8 *puVar3;
  undefined8 *puVar4;
  int *piVar5;
  Data *pDVar6;
  Data *pDVar7;
  
  pDVar6 = (Data *)*param_1;
  if (*(int *)pDVar6 == 0) {
LAB_008f6832:
    pDVar7 = pDVar6 + (long)*(int *)(pDVar6 + 0xc) * 8 + 0x10;
    iVar2 = *(int *)(pDVar6 + 8);
    do {
      do {
        if (pDVar7 == pDVar6 + (long)iVar2 * 8 + 0x10) {
          QListData::dispose(pDVar6);
          return;
        }
        pDVar7 = pDVar7 + -8;
        puVar3 = *(undefined8 **)pDVar7;
      } while (puVar3 == (undefined8 *)0x0);
      puVar4 = (undefined8 *)puVar3[2];
      if (puVar4 != (undefined8 *)0x0) {
        piVar5 = (int *)*puVar4;
        if (*piVar5 == 0) {
LAB_008f68e8:
          QArrayData::deallocate((QArrayData *)*puVar4,2,8);
        }
        else if (*piVar5 != -1) {
          LOCK();
          iVar1 = *piVar5;
          *piVar5 = *piVar5 + -1;
          UNLOCK();
          if (iVar1 == 1) goto LAB_008f68e8;
        }
        operator_delete(puVar4,8);
      }
      piVar5 = (int *)*puVar3;
      if (*piVar5 == 0) {
LAB_008f68d4:
        QArrayData::deallocate((QArrayData *)*puVar3,2,8);
      }
      else if (*piVar5 != -1) {
        LOCK();
        iVar1 = *piVar5;
        *piVar5 = *piVar5 + -1;
        UNLOCK();
        if (iVar1 == 1) goto LAB_008f68d4;
      }
      operator_delete(puVar3,0x18);
    } while( true );
  }
  if (*(int *)pDVar6 != -1) {
    LOCK();
    *(int *)pDVar6 = *(int *)pDVar6 + -1;
    UNLOCK();
    if (*(int *)pDVar6 == 0) {
      pDVar6 = (Data *)*param_1;
      goto LAB_008f6832;
    }
  }
  return;
}


// ==== entry=008f68fc orig=FUN_008f68fc size=113 name=TabBar_dtor ====

void TabBar_dtor(QTabBar *param_1)

{
  QArrayData *pQVar1;
  
  *(undefined ***)param_1 = &TabBar_vtable;
  *(undefined ***)(param_1 + 0x10) = &PTR_FUN_01197ef0;
  FUN_008f67fc(param_1 + 0x70);
  FUN_00525060(param_1 + 0x68);
  FUN_008f67a0(param_1 + 0x60);
  pQVar1 = *(QArrayData **)(param_1 + 0x38);
  if (*(int *)pQVar1 == 0) {
LAB_008f6955:
    QArrayData::deallocate(pQVar1,2,8);
    QTabBar::~QTabBar(param_1);
    return;
  }
  if (*(int *)pQVar1 != -1) {
    LOCK();
    *(int *)pQVar1 = *(int *)pQVar1 + -1;
    UNLOCK();
    if (*(int *)pQVar1 == 0) {
      pQVar1 = *(QArrayData **)(param_1 + 0x38);
      goto LAB_008f6955;
    }
  }
  QTabBar::~QTabBar(param_1);
  return;
}


// ==== entry=008f696d name=FUN_008f696d size=115 ====

void FUN_008f696d(undefined8 *param_1)

{
  QArrayData *pQVar1;
  
  param_1[-2] = &TabBar_vtable;
  *param_1 = &PTR_FUN_01197ef0;
  FUN_008f67fc(param_1 + 0xc);
  FUN_00525060(param_1 + 0xb);
  FUN_008f67a0(param_1 + 10);
  pQVar1 = (QArrayData *)param_1[5];
  if (*(int *)pQVar1 == 0) {
LAB_008f69c7:
    QArrayData::deallocate(pQVar1,2,8);
    QTabBar::~QTabBar((QTabBar *)(param_1 + -2));
    return;
  }
  if (*(int *)pQVar1 != -1) {
    LOCK();
    *(int *)pQVar1 = *(int *)pQVar1 + -1;
    UNLOCK();
    if (*(int *)pQVar1 == 0) {
      pQVar1 = (QArrayData *)param_1[5];
      goto LAB_008f69c7;
    }
  }
  QTabBar::~QTabBar((QTabBar *)(param_1 + -2));
  return;
}


// ==== entry=008f69e0 name=FUN_008f69e0 size=133 ====

void FUN_008f69e0(undefined8 *param_1)

{
  QArrayData *pQVar1;
  
  param_1[-2] = &TabBar_vtable;
  *param_1 = &PTR_FUN_01197ef0;
  FUN_008f67fc(param_1 + 0xc);
  FUN_00525060(param_1 + 0xb);
  FUN_008f67a0(param_1 + 10);
  pQVar1 = (QArrayData *)param_1[5];
  if (*(int *)pQVar1 != 0) {
    if (*(int *)pQVar1 == -1) goto LAB_008f6a35;
    LOCK();
    *(int *)pQVar1 = *(int *)pQVar1 + -1;
    UNLOCK();
    if (*(int *)pQVar1 != 0) goto LAB_008f6a35;
    pQVar1 = (QArrayData *)param_1[5];
  }
  QArrayData::deallocate(pQVar1,2,8);
LAB_008f6a35:
  QTabBar::~QTabBar((QTabBar *)(param_1 + -2));
  operator_delete((QTabBar *)(param_1 + -2),0x80);
  return;
}


// ==== entry=008f6a66 orig=FUN_008f6a66 size=119 name=TabBar_dtor_deleting ====

void TabBar_dtor_deleting(QTabBar *param_1)

{
  QArrayData *pQVar1;
  
  *(undefined ***)param_1 = &TabBar_vtable;
  *(undefined ***)(param_1 + 0x10) = &PTR_FUN_01197ef0;
  FUN_008f67fc(param_1 + 0x70);
  FUN_00525060(param_1 + 0x68);
  FUN_008f67a0(param_1 + 0x60);
  pQVar1 = *(QArrayData **)(param_1 + 0x38);
  if (*(int *)pQVar1 != 0) {
    if (*(int *)pQVar1 == -1) goto LAB_008f6ab2;
    LOCK();
    *(int *)pQVar1 = *(int *)pQVar1 + -1;
    UNLOCK();
    if (*(int *)pQVar1 != 0) goto LAB_008f6ab2;
    pQVar1 = *(QArrayData **)(param_1 + 0x38);
  }
  QArrayData::deallocate(pQVar1,2,8);
LAB_008f6ab2:
  QTabBar::~QTabBar(param_1);
  operator_delete(param_1,0x80);
  return;
}


// ==== entry=008f6ae0 orig=FUN_008f6ae0 size=24 name=Splitter_metaObject ====

undefined ** Splitter_metaObject(long param_1)

{
  undefined **ppuVar1;
  
  if (*(long *)(*(long *)(param_1 + 8) + 0x28) != 0) {
    ppuVar1 = (undefined **)QObjectData::dynamicMetaObject();
    return ppuVar1;
  }
  return &PTR_staticMetaObject_011981a0;
}


// ==== entry=008f6af8 name=FUN_008f6af8 size=51 ====

void FUN_008f6af8(QObject *param_1,undefined4 param_2)

{
  undefined4 local_1c;
  void *local_18;
  undefined4 *local_10;
  
  local_18 = (void *)0x0;
  local_10 = &local_1c;
  local_1c = param_2;
  QMetaObject::activate(param_1,(QMetaObject *)&PTR_staticMetaObject_011981a0,0,&local_18);
  return;
}


// ==== entry=008f6b2c name=FUN_008f6b2c size=54 ====

void FUN_008f6b2c(QObject *param_1,undefined4 param_2)

{
  undefined4 local_1c;
  void *local_18;
  undefined4 *local_10;
  
  local_18 = (void *)0x0;
  local_10 = &local_1c;
  local_1c = param_2;
  QMetaObject::activate(param_1,(QMetaObject *)&PTR_staticMetaObject_011981a0,1,&local_18);
  return;
}


// ==== entry=008f6b62 name=FUN_008f6b62 size=98 ====

void FUN_008f6b62(undefined8 param_1,int param_2,int param_3,undefined8 *param_4)

{
  long *plVar1;
  
  if (param_2 != 0) {
    if (param_2 == 10) {
      plVar1 = (long *)param_4[1];
      if ((code *)*plVar1 == FUN_008f6af8) {
        if (plVar1[1] == 0) {
          *(undefined4 *)*param_4 = 0;
          return;
        }
      }
      else if (((code *)*plVar1 == FUN_008f6b2c) && (plVar1[1] == 0)) {
        *(undefined4 *)*param_4 = 1;
        return;
      }
    }
    return;
  }
  if (param_3 == 0) {
    FUN_008f6af8(param_1,*(undefined4 *)param_4[1]);
    return;
  }
  if (param_3 == 1) {
    FUN_008f6b2c(param_1,*(undefined4 *)param_4[1]);
    return;
  }
  return;
}


// ==== entry=008f6bc4 orig=FUN_008f6bc4 size=66 name=Splitter_qt_metacast ====

char * Splitter_qt_metacast(char *param_1,char *param_2)

{
  int iVar1;
  char *pcVar2;
  
  if (param_2 == (char *)0x0) {
    return (char *)0x0;
  }
  iVar1 = strcmp(param_2,"Splitter");
  if (iVar1 == 0) {
    return param_1;
  }
  pcVar2 = (char *)QSplitter::qt_metacast(param_1);
  return pcVar2;
}


// ==== entry=008f6c06 orig=FUN_008f6c06 size=93 name=Splitter_qt_metacall ====

ulong Splitter_qt_metacall(undefined8 param_1,int param_2,undefined8 param_3,undefined8 *param_4)

{
  int iVar1;
  ulong uVar2;
  
  uVar2 = QSplitter::qt_metacall();
  iVar1 = (int)uVar2;
  if (-1 < iVar1) {
    if (param_2 == 0) {
      if (iVar1 < 2) {
        FUN_008f6b62(param_1,0,uVar2 & 0xffffffff,param_4);
        uVar2 = uVar2 & 0xffffffff;
      }
    }
    else {
      if (param_2 != 0xc) {
        return uVar2;
      }
      if (iVar1 < 2) {
        *(undefined4 *)*param_4 = 0xffffffff;
      }
    }
    uVar2 = (ulong)((int)uVar2 - 2);
  }
  return uVar2;
}


// ==== entry=008f6c64 name=FUN_008f6c64 size=1 ====

void FUN_008f6c64(void)

{
  return;
}


// ==== entry=008f6c66 orig=FUN_008f6c66 size=24 name=SplitterGroup_metaObject ====

undefined ** SplitterGroup_metaObject(long param_1)

{
  undefined **ppuVar1;
  
  if (*(long *)(*(long *)(param_1 + 8) + 0x28) != 0) {
    ppuVar1 = (undefined **)QObjectData::dynamicMetaObject();
    return ppuVar1;
  }
  return &PTR_staticMetaObject_01198400;
}


// ==== entry=008f6c7e orig=FUN_008f6c7e size=66 name=SplitterGroup_qt_metacast ====

char * SplitterGroup_qt_metacast(char *param_1,char *param_2)

{
  int iVar1;
  char *pcVar2;
  
  if (param_2 == (char *)0x0) {
    return (char *)0x0;
  }
  iVar1 = strcmp(param_2,"SplitterGroup");
  if (iVar1 == 0) {
    return param_1;
  }
  pcVar2 = (char *)QWidget::qt_metacast(param_1);
  return pcVar2;
}


// ==== entry=008f6cc0 orig=FUN_008f6cc0 size=5 name=SplitterGroup_qt_metacall ====

void QWidget::SplitterGroup_qt_metacall(void)

{
  qt_metacall();
  return;
}


// ==== entry=008f6cc6 orig=FUN_008f6cc6 size=29 name=SplitterGroup_dtor ====

void SplitterGroup_dtor(QWidget *param_1)

{
  *(undefined ***)param_1 = &SplitterGroup_vtable;
  *(undefined ***)(param_1 + 0x10) = &PTR_FUN_011983a8;
  QWidget::~QWidget(param_1);
  return;
}


// ==== entry=008f6ce3 name=FUN_008f6ce3 size=33 ====

void FUN_008f6ce3(undefined8 *param_1)

{
  param_1[-2] = &SplitterGroup_vtable;
  *param_1 = &PTR_FUN_011983a8;
  QWidget::~QWidget((QWidget *)(param_1 + -2));
  return;
}


// ==== entry=008f6d04 orig=FUN_008f6d04 size=47 name=SplitterGroup_dtor_deleting ====

void SplitterGroup_dtor_deleting(QWidget *param_1)

{
  *(undefined ***)param_1 = &SplitterGroup_vtable;
  *(undefined ***)(param_1 + 0x10) = &PTR_FUN_011983a8;
  QWidget::~QWidget(param_1);
  operator_delete(param_1,0x48);
  return;
}


// ==== entry=008f6d33 name=FUN_008f6d33 size=51 ====

void FUN_008f6d33(undefined8 *param_1)

{
  param_1[-2] = &SplitterGroup_vtable;
  *param_1 = &PTR_FUN_011983a8;
  QWidget::~QWidget((QWidget *)(param_1 + -2));
  operator_delete((QWidget *)(param_1 + -2),0x48);
  return;
}


// ==== entry=008f6d70 name=FUN_008f6d70 size=24 ====

undefined ** FUN_008f6d70(long param_1)

{
  undefined **ppuVar1;
  
  if (*(long *)(*(long *)(param_1 + 8) + 0x28) != 0) {
    ppuVar1 = (undefined **)QObjectData::dynamicMetaObject();
    return ppuVar1;
  }
  return &PTR_staticMetaObject_01198660;
}


// ==== entry=008f6d88 name=FUN_008f6d88 size=16 ====

void FUN_008f6d88(QObject *param_1)

{
  QMetaObject::activate(param_1,(QMetaObject *)&PTR_staticMetaObject_01198660,0,(void **)0x0);
  return;
}


// ==== entry=008f6d98 name=FUN_008f6d98 size=55 ====

void FUN_008f6d98(QObject *param_1,undefined1 param_2)

{
  undefined1 local_1c [4];
  void *local_18;
  undefined1 *local_10;
  
  local_18 = (void *)0x0;
  local_10 = local_1c;
  local_1c[0] = param_2;
  QMetaObject::activate(param_1,(QMetaObject *)&PTR_staticMetaObject_01198660,1,&local_18);
  return;
}


// ==== entry=008f6dd0 name=FUN_008f6dd0 size=94 ====

void FUN_008f6dd0(undefined8 param_1,int param_2,int param_3,undefined8 *param_4)

{
  long *plVar1;
  
  if (param_2 == 0) {
    if (param_3 == 0) {
      FUN_008f6d88();
      return;
    }
    if (param_3 == 1) {
      FUN_008f6d98(param_1,*(undefined1 *)param_4[1]);
      return;
    }
    return;
  }
  if (param_2 == 10) {
    plVar1 = (long *)param_4[1];
    if (((code *)*plVar1 == FUN_008f6d88) && (plVar1[1] == 0)) {
      *(undefined4 *)*param_4 = 0;
      return;
    }
    if (((code *)*plVar1 == FUN_008f6d98) && (plVar1[1] == 0)) {
      *(undefined4 *)*param_4 = 1;
      return;
    }
  }
  return;
}


// ==== entry=008f6e2e orig=FUN_008f6e2e size=66 name=s_LineEdit_8f6e2e ====

char * s_LineEdit_8f6e2e(char *param_1,char *param_2)

{
  int iVar1;
  char *pcVar2;
  
  if (param_2 == (char *)0x0) {
    return (char *)0x0;
  }
  iVar1 = strcmp(param_2,"LineEdit");
  if (iVar1 == 0) {
    return param_1;
  }
  pcVar2 = (char *)QLineEdit::qt_metacast(param_1);
  return pcVar2;
}


// ==== entry=008f6e70 name=FUN_008f6e70 size=93 ====

ulong FUN_008f6e70(undefined8 param_1,int param_2,undefined8 param_3,undefined8 *param_4)

{
  int iVar1;
  ulong uVar2;
  
  uVar2 = QLineEdit::qt_metacall();
  iVar1 = (int)uVar2;
  if (-1 < iVar1) {
    if (param_2 == 0) {
      if (iVar1 < 2) {
        FUN_008f6dd0(param_1,0,uVar2 & 0xffffffff,param_4);
        uVar2 = uVar2 & 0xffffffff;
      }
    }
    else {
      if (param_2 != 0xc) {
        return uVar2;
      }
      if (iVar1 < 2) {
        *(undefined4 *)*param_4 = 0xffffffff;
      }
    }
    uVar2 = (ulong)((int)uVar2 - 2);
  }
  return uVar2;
}


// ==== entry=008f6ece name=FUN_008f6ece size=75 ====

void FUN_008f6ece(QLineEdit *param_1)

{
  int *piVar1;
  
  *(undefined ***)param_1 = &PTR_FUN_01198458;
  *(undefined ***)(param_1 + 0x10) = &PTR_FUN_01198608;
  FUN_00544670(param_1 + 0x50);
  piVar1 = *(int **)(param_1 + 0x30);
  if (piVar1 != (int *)0x0) {
    LOCK();
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if ((*piVar1 == 0) && (*(void **)(param_1 + 0x30) != (void *)0x0)) {
      operator_delete(*(void **)(param_1 + 0x30));
    }
  }
  QLineEdit::~QLineEdit(param_1);
  return;
}


// ==== entry=008f6f19 name=FUN_008f6f19 size=76 ====

void FUN_008f6f19(undefined8 *param_1)

{
  int *piVar1;
  
  param_1[-2] = &PTR_FUN_01198458;
  *param_1 = &PTR_FUN_01198608;
  FUN_00544670(param_1 + 8);
  piVar1 = (int *)param_1[4];
  if (piVar1 != (int *)0x0) {
    LOCK();
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if ((*piVar1 == 0) && ((void *)param_1[4] != (void *)0x0)) {
      operator_delete((void *)param_1[4]);
    }
  }
  QLineEdit::~QLineEdit((QLineEdit *)(param_1 + -2));
  return;
}


// ==== entry=008f6f66 name=FUN_008f6f66 size=102 ====

void FUN_008f6f66(undefined8 *param_1)

{
  int *piVar1;
  
  param_1[-2] = &PTR_FUN_01198458;
  *param_1 = &PTR_FUN_01198608;
  FUN_00544670(param_1 + 8);
  piVar1 = (int *)param_1[4];
  if (piVar1 != (int *)0x0) {
    LOCK();
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if ((*piVar1 == 0) && ((void *)param_1[4] != (void *)0x0)) {
      operator_delete((void *)param_1[4]);
    }
  }
  QLineEdit::~QLineEdit((QLineEdit *)(param_1 + -2));
  operator_delete((QLineEdit *)(param_1 + -2),0x70);
  return;
}


// ==== entry=008f6fcc name=FUN_008f6fcc size=88 ====

void FUN_008f6fcc(QLineEdit *param_1)

{
  int *piVar1;
  
  *(undefined ***)param_1 = &PTR_FUN_01198458;
  *(undefined ***)(param_1 + 0x10) = &PTR_FUN_01198608;
  FUN_00544670(param_1 + 0x50);
  piVar1 = *(int **)(param_1 + 0x30);
  if (piVar1 != (int *)0x0) {
    LOCK();
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if ((*piVar1 == 0) && (*(void **)(param_1 + 0x30) != (void *)0x0)) {
      operator_delete(*(void **)(param_1 + 0x30));
    }
  }
  QLineEdit::~QLineEdit(param_1);
  operator_delete(param_1,0x70);
  return;
}


// ==== entry=008f7024 name=FUN_008f7024 size=1 ====

void FUN_008f7024(void)

{
  return;
}


// ==== entry=008f7026 orig=FUN_008f7026 size=24 name=SideButton_metaObject ====

undefined ** SideButton_metaObject(long param_1)

{
  undefined **ppuVar1;
  
  if (*(long *)(*(long *)(param_1 + 8) + 0x28) != 0) {
    ppuVar1 = (undefined **)QObjectData::dynamicMetaObject();
    return ppuVar1;
  }
  return &PTR_staticMetaObject_01198b20;
}


// ==== entry=008f703e orig=FUN_008f703e size=24 name=SideSeparator_metaObject ====

undefined ** SideSeparator_metaObject(long param_1)

{
  undefined **ppuVar1;
  
  if (*(long *)(*(long *)(param_1 + 8) + 0x28) != 0) {
    ppuVar1 = (undefined **)QObjectData::dynamicMetaObject();
    return ppuVar1;
  }
  return &PTR_staticMetaObject_01198ae0;
}


// ==== entry=008f7056 name=FUN_008f7056 size=1 ====

void FUN_008f7056(void)

{
  return;
}


// ==== entry=008f7058 orig=FUN_008f7058 size=66 name=SideButton_qt_metacast ====

char * SideButton_qt_metacast(char *param_1,char *param_2)

{
  int iVar1;
  char *pcVar2;
  
  if (param_2 == (char *)0x0) {
    return (char *)0x0;
  }
  iVar1 = strcmp(param_2,"SideButton");
  if (iVar1 == 0) {
    return param_1;
  }
  pcVar2 = (char *)QPushButton::qt_metacast(param_1);
  return pcVar2;
}


// ==== entry=008f709a orig=FUN_008f709a size=5 name=SideButton_qt_metacall ====

void QPushButton::SideButton_qt_metacall(void)

{
  qt_metacall();
  return;
}


// ==== entry=008f70a0 orig=FUN_008f70a0 size=66 name=SideSeparator_qt_metacast ====

char * SideSeparator_qt_metacast(char *param_1,char *param_2)

{
  int iVar1;
  char *pcVar2;
  
  if (param_2 == (char *)0x0) {
    return (char *)0x0;
  }
  iVar1 = strcmp(param_2,"SideSeparator");
  if (iVar1 == 0) {
    return param_1;
  }
  pcVar2 = (char *)QWidget::qt_metacast(param_1);
  return pcVar2;
}


// ==== entry=008f70e2 orig=FUN_008f70e2 size=5 name=SideSeparator_qt_metacall ====

void QWidget::SideSeparator_qt_metacall(void)

{
  qt_metacall();
  return;
}


// ==== entry=008f70e8 orig=FUN_008f70e8 size=29 name=SideSeparator_dtor ====

void SideSeparator_dtor(QWidget *param_1)

{
  *(undefined ***)param_1 = &SideSeparator_vtable;
  *(undefined ***)(param_1 + 0x10) = &PTR_FUN_01198a98;
  QWidget::~QWidget(param_1);
  return;
}


// ==== entry=008f7105 name=FUN_008f7105 size=33 ====

void FUN_008f7105(undefined8 *param_1)

{
  param_1[-2] = &SideSeparator_vtable;
  *param_1 = &PTR_FUN_01198a98;
  QWidget::~QWidget((QWidget *)(param_1 + -2));
  return;
}


// ==== entry=008f7126 orig=FUN_008f7126 size=47 name=SideSeparator_dtor_deleting ====

void SideSeparator_dtor_deleting(QWidget *param_1)

{
  *(undefined ***)param_1 = &SideSeparator_vtable;
  *(undefined ***)(param_1 + 0x10) = &PTR_FUN_01198a98;
  QWidget::~QWidget(param_1);
  operator_delete(param_1,0x30);
  return;
}


// ==== entry=008f7155 name=FUN_008f7155 size=51 ====

void FUN_008f7155(undefined8 *param_1)

{
  param_1[-2] = &SideSeparator_vtable;
  *param_1 = &PTR_FUN_01198a98;
  QWidget::~QWidget((QWidget *)(param_1 + -2));
  operator_delete((QWidget *)(param_1 + -2),0x30);
  return;
}


// ==== entry=008f7188 orig=FUN_008f7188 size=29 name=SideButton_dtor ====

void SideButton_dtor(QPushButton *param_1)

{
  *(undefined ***)param_1 = &SideButton_vtable;
  *(undefined ***)(param_1 + 0x10) = &PTR_FUN_01198898;
  QPushButton::~QPushButton(param_1);
  return;
}


// ==== entry=008f71a5 name=FUN_008f71a5 size=33 ====

void FUN_008f71a5(undefined8 *param_1)

{
  param_1[-2] = &SideButton_vtable;
  *param_1 = &PTR_FUN_01198898;
  QPushButton::~QPushButton((QPushButton *)(param_1 + -2));
  return;
}


// ==== entry=008f71c6 orig=FUN_008f71c6 size=47 name=SideButton_dtor_deleting ====

void SideButton_dtor_deleting(QPushButton *param_1)

{
  *(undefined ***)param_1 = &SideButton_vtable;
  *(undefined ***)(param_1 + 0x10) = &PTR_FUN_01198898;
  QPushButton::~QPushButton(param_1);
  operator_delete(param_1,0x30);
  return;
}


// ==== entry=008f71f5 name=FUN_008f71f5 size=51 ====

void FUN_008f71f5(undefined8 *param_1)

{
  param_1[-2] = &SideButton_vtable;
  *param_1 = &PTR_FUN_01198898;
  QPushButton::~QPushButton((QPushButton *)(param_1 + -2));
  operator_delete((QPushButton *)(param_1 + -2),0x30);
  return;
}


// ==== entry=008f7230 orig=FUN_008f7230 size=24 name=LoginWizard_metaObject ====

undefined ** LoginWizard_metaObject(long param_1)

{
  undefined **ppuVar1;
  
  if (*(long *)(*(long *)(param_1 + 8) + 0x28) != 0) {
    ppuVar1 = (undefined **)QObjectData::dynamicMetaObject();
    return ppuVar1;
  }
  return &PTR_staticMetaObject_01198d80;
}


// ==== entry=008f7248 name=FUN_008f7248 size=16 ====

void FUN_008f7248(QObject *param_1)

{
  QMetaObject::activate(param_1,(QMetaObject *)&PTR_staticMetaObject_01198d80,0,(void **)0x0);
  return;
}


// ==== entry=008f7258 name=FUN_008f7258 size=19 ====

void FUN_008f7258(QObject *param_1)

{
  QMetaObject::activate(param_1,(QMetaObject *)&PTR_staticMetaObject_01198d80,1,(void **)0x0);
  return;
}


// ==== entry=008f726c name=FUN_008f726c size=86 ====

void FUN_008f726c(undefined8 param_1,int param_2,int param_3,undefined8 *param_4)

{
  long *plVar1;
  
  if (param_2 != 0) {
    if (param_2 == 10) {
      plVar1 = (long *)param_4[1];
      if ((code *)*plVar1 == FUN_008f7248) {
        if (plVar1[1] == 0) {
          *(undefined4 *)*param_4 = 0;
          return;
        }
      }
      else if (((code *)*plVar1 == FUN_008f7258) && (plVar1[1] == 0)) {
        *(undefined4 *)*param_4 = 1;
        return;
      }
    }
    return;
  }
  if (param_3 == 0) {
    FUN_008f7248();
    return;
  }
  if (param_3 == 1) {
    FUN_008f7258();
    return;
  }
  return;
}


// ==== entry=008f72c2 orig=FUN_008f72c2 size=66 name=LoginWizard_qt_metacast ====

char * LoginWizard_qt_metacast(char *param_1,char *param_2)

{
  int iVar1;
  char *pcVar2;
  
  if (param_2 == (char *)0x0) {
    return (char *)0x0;
  }
  iVar1 = strcmp(param_2,"LoginWizard");
  if (iVar1 == 0) {
    return param_1;
  }
  pcVar2 = (char *)QWidget::qt_metacast(param_1);
  return pcVar2;
}


// ==== entry=008f7304 orig=FUN_008f7304 size=93 name=LoginWizard_qt_metacall ====

ulong LoginWizard_qt_metacall(undefined8 param_1,int param_2,undefined8 param_3,undefined8 *param_4)

{
  int iVar1;
  ulong uVar2;
  
  uVar2 = QWidget::qt_metacall();
  iVar1 = (int)uVar2;
  if (-1 < iVar1) {
    if (param_2 == 0) {
      if (iVar1 < 2) {
        FUN_008f726c(param_1,0,uVar2 & 0xffffffff,param_4);
        uVar2 = uVar2 & 0xffffffff;
      }
    }
    else {
      if (param_2 != 0xc) {
        return uVar2;
      }
      if (iVar1 < 2) {
        *(undefined4 *)*param_4 = 0xffffffff;
      }
    }
    uVar2 = (ulong)((int)uVar2 - 2);
  }
  return uVar2;
}


// ==== entry=008f7362 name=FUN_008f7362 size=1 ====

void FUN_008f7362(void)

{
  return;
}


// ==== entry=008f7364 orig=FUN_008f7364 size=24 name=SwitchButton_metaObject ====

undefined ** SwitchButton_metaObject(long param_1)

{
  undefined **ppuVar1;
  
  if (*(long *)(*(long *)(param_1 + 8) + 0x28) != 0) {
    ppuVar1 = (undefined **)QObjectData::dynamicMetaObject();
    return ppuVar1;
  }
  return &PTR_staticMetaObject_01198fe0;
}


// ==== entry=008f737c orig=FUN_008f737c size=66 name=SwitchButton_qt_metacast ====

char * SwitchButton_qt_metacast(char *param_1,char *param_2)

{
  int iVar1;
  char *pcVar2;
  
  if (param_2 == (char *)0x0) {
    return (char *)0x0;
  }
  iVar1 = strcmp(param_2,"SwitchButton");
  if (iVar1 == 0) {
    return param_1;
  }
  pcVar2 = (char *)QPushButton::qt_metacast(param_1);
  return pcVar2;
}


// ==== entry=008f73be orig=FUN_008f73be size=5 name=SwitchButton_qt_metacall ====

void QPushButton::SwitchButton_qt_metacall(void)

{
  qt_metacall();
  return;
}


// ==== entry=008f73c4 orig=FUN_008f73c4 size=29 name=SwitchButton_dtor ====

void SwitchButton_dtor(QPushButton *param_1)

{
  *(undefined ***)param_1 = &SwitchButton_vtable;
  *(undefined ***)(param_1 + 0x10) = &PTR_FUN_01198fa0;
  QPushButton::~QPushButton(param_1);
  return;
}


// ==== entry=008f73e1 name=FUN_008f73e1 size=33 ====

void FUN_008f73e1(undefined8 *param_1)

{
  param_1[-2] = &SwitchButton_vtable;
  *param_1 = &PTR_FUN_01198fa0;
  QPushButton::~QPushButton((QPushButton *)(param_1 + -2));
  return;
}


// ==== entry=008f7402 orig=FUN_008f7402 size=47 name=SwitchButton_dtor_deleting ====

void SwitchButton_dtor_deleting(QPushButton *param_1)

{
  *(undefined ***)param_1 = &SwitchButton_vtable;
  *(undefined ***)(param_1 + 0x10) = &PTR_FUN_01198fa0;
  QPushButton::~QPushButton(param_1);
  operator_delete(param_1,0x30);
  return;
}


// ==== entry=008f7431 name=FUN_008f7431 size=51 ====

void FUN_008f7431(undefined8 *param_1)

{
  param_1[-2] = &SwitchButton_vtable;
  *param_1 = &PTR_FUN_01198fa0;
  QPushButton::~QPushButton((QPushButton *)(param_1 + -2));
  operator_delete((QPushButton *)(param_1 + -2),0x30);
  return;
}


// ==== entry=008f7464 name=FUN_008f7464 size=1 ====

void FUN_008f7464(void)

{
  return;
}


// ==== entry=008f7466 orig=FUN_008f7466 size=24 name=HtmlListModel_metaObject ====

undefined ** HtmlListModel_metaObject(long param_1)

{
  undefined **ppuVar1;
  
  if (*(long *)(*(long *)(param_1 + 8) + 0x28) != 0) {
    ppuVar1 = (undefined **)QObjectData::dynamicMetaObject();
    return ppuVar1;
  }
  return &PTR_staticMetaObject_011995a0;
}


// ==== entry=008f747e orig=FUN_008f747e size=24 name=HtmlList_metaObject ====

undefined ** HtmlList_metaObject(long param_1)

{
  undefined **ppuVar1;
  
  if (*(long *)(*(long *)(param_1 + 8) + 0x28) != 0) {
    ppuVar1 = (undefined **)QObjectData::dynamicMetaObject();
    return ppuVar1;
  }
  return &PTR_staticMetaObject_01199560;
}


// ==== entry=008f7496 name=FUN_008f7496 size=1 ====

void FUN_008f7496(void)

{
  return;
}


// ==== entry=008f7498 orig=FUN_008f7498 size=104 name=HtmlListModel_qt_metacast ====

char * HtmlListModel_qt_metacast(char *param_1,byte *param_2)

{
  int iVar1;
  char *pcVar2;
  long lVar3;
  byte *pbVar4;
  bool bVar5;
  bool bVar6;
  byte bVar7;
  
  bVar7 = 0;
  if (param_2 == (byte *)0x0) {
    return (char *)0x0;
  }
  iVar1 = strcmp((char *)param_2,"HtmlListModel");
  bVar5 = false;
  if (iVar1 == 0) {
    return param_1;
  }
  lVar3 = 0x12;
  bVar6 = false;
  pbVar4 = (byte *)"HtmlAbstractModel";
  do {
    if (lVar3 == 0) break;
    lVar3 = lVar3 + -1;
    bVar5 = *param_2 < *pbVar4;
    bVar6 = *param_2 == *pbVar4;
    param_2 = param_2 + (ulong)bVar7 * -2 + 1;
    pbVar4 = pbVar4 + (ulong)bVar7 * -2 + 1;
  } while (bVar6);
  if ((!bVar5 && !bVar6) == bVar5) {
    return param_1 + 0x10;
  }
  pcVar2 = (char *)QAbstractListModel::qt_metacast(param_1);
  return pcVar2;
}


// ==== entry=008f7500 orig=FUN_008f7500 size=5 name=HtmlListModel_qt_metacall ====

void QAbstractListModel::HtmlListModel_qt_metacall(void)

{
  qt_metacall();
  return;
}


// ==== entry=008f7506 orig=FUN_008f7506 size=66 name=HtmlList_qt_metacast ====

char * HtmlList_qt_metacast(char *param_1,char *param_2)

{
  int iVar1;
  char *pcVar2;
  
  if (param_2 == (char *)0x0) {
    return (char *)0x0;
  }
  iVar1 = strcmp(param_2,"HtmlList");
  if (iVar1 == 0) {
    return param_1;
  }
  pcVar2 = (char *)QListView::qt_metacast(param_1);
  return pcVar2;
}


// ==== entry=008f7548 orig=FUN_008f7548 size=5 name=HtmlList_qt_metacall ====

void QListView::HtmlList_qt_metacall(void)

{
  qt_metacall();
  return;
}


// ==== entry=008f754e orig=FUN_008f754e size=29 name=HtmlList_dtor ====

void HtmlList_dtor(QListView *param_1)

{
  *(undefined ***)param_1 = &HtmlList_vtable;
  *(undefined ***)(param_1 + 0x10) = &PTR_FUN_01199510;
  QListView::~QListView(param_1);
  return;
}


// ==== entry=008f756b name=FUN_008f756b size=33 ====

void FUN_008f756b(undefined8 *param_1)

{
  param_1[-2] = &HtmlList_vtable;
  *param_1 = &PTR_FUN_01199510;
  QListView::~QListView((QListView *)(param_1 + -2));
  return;
}


// ==== entry=008f758c orig=FUN_008f758c size=47 name=HtmlList_dtor_deleting ====

void HtmlList_dtor_deleting(QListView *param_1)

{
  *(undefined ***)param_1 = &HtmlList_vtable;
  *(undefined ***)(param_1 + 0x10) = &PTR_FUN_01199510;
  QListView::~QListView(param_1);
  operator_delete(param_1,0x40);
  return;
}


// ==== entry=008f75bb name=FUN_008f75bb size=51 ====

void FUN_008f75bb(undefined8 *param_1)

{
  param_1[-2] = &HtmlList_vtable;
  *param_1 = &PTR_FUN_01199510;
  QListView::~QListView((QListView *)(param_1 + -2));
  operator_delete((QListView *)(param_1 + -2),0x40);
  return;
}


// ==== entry=008f75ee name=FUN_008f75ee size=1 ====

void FUN_008f75ee(void)

{
  return;
}


// ==== entry=008f75f0 orig=FUN_008f75f0 size=24 name=ListPanel_metaObject ====

undefined ** ListPanel_metaObject(long param_1)

{
  undefined **ppuVar1;
  
  if (*(long *)(*(long *)(param_1 + 8) + 0x28) != 0) {
    ppuVar1 = (undefined **)QObjectData::dynamicMetaObject();
    return ppuVar1;
  }
  return &PTR_PTR_01199800;
}


// ==== entry=008f7608 orig=FUN_008f7608 size=66 name=ListPanel_qt_metacast ====

undefined8 ListPanel_qt_metacast(undefined8 param_1,char *param_2)

{
  int iVar1;
  undefined8 uVar2;
  
  if (param_2 == (char *)0x0) {
    return 0;
  }
  iVar1 = strcmp(param_2,"ListPanel");
  if (iVar1 == 0) {
    return param_1;
  }
  uVar2 = ButtonBarPanel_qt_metacast(param_1,param_2);
  return uVar2;
}


// ==== entry=008f764a orig=FUN_008f764a size=5 name=ListPanel_qt_metacall ====

ulong ListPanel_qt_metacall(undefined8 param_1,int param_2,undefined8 param_3,undefined8 *param_4)

{
  int iVar1;
  ulong uVar2;
  
  uVar2 = QFrame::qt_metacall();
  iVar1 = (int)uVar2;
  if (-1 < iVar1) {
    if (param_2 == 0) {
      if (iVar1 < 0x11) {
        FUN_008ef9ea(param_1,0,uVar2 & 0xffffffff,param_4);
        uVar2 = uVar2 & 0xffffffff;
      }
    }
    else {
      if (param_2 != 0xc) {
        return uVar2;
      }
      if (iVar1 < 0x11) {
        *(undefined4 *)*param_4 = 0xffffffff;
      }
    }
    uVar2 = (ulong)((int)uVar2 - 0x11);
  }
  return uVar2;
}


// ==== entry=008f7650 orig=FUN_008f7650 size=29 name=ListPanel_dtor ====

void ListPanel_dtor(QFrame *param_1)

{
  *(undefined ***)param_1 = &ButtonBarPanel_vtable;
  *(undefined ***)(param_1 + 0x10) = &PTR_FUN_011933e8;
  QFrame::~QFrame(param_1);
  return;
}


// ==== entry=008f766d name=FUN_008f766d size=33 ====

void FUN_008f766d(undefined8 *param_1)

{
  param_1[-2] = &ButtonBarPanel_vtable;
  *param_1 = &PTR_FUN_011933e8;
  QFrame::~QFrame((QFrame *)(param_1 + -2));
  return;
}


// ==== entry=008f768e orig=FUN_008f768e size=47 name=ListPanel_dtor_deleting ====

void ListPanel_dtor_deleting(QFrame *param_1)

{
  *(undefined ***)param_1 = &ButtonBarPanel_vtable;
  *(undefined ***)(param_1 + 0x10) = &PTR_FUN_011933e8;
  QFrame::~QFrame(param_1);
  operator_delete(param_1,0x48);
  return;
}


// ==== entry=008f76bd name=FUN_008f76bd size=51 ====

void FUN_008f76bd(undefined8 *param_1)

{
  param_1[-2] = &ButtonBarPanel_vtable;
  *param_1 = &PTR_FUN_011933e8;
  QFrame::~QFrame((QFrame *)(param_1 + -2));
  operator_delete((QFrame *)(param_1 + -2),0x48);
  return;
}


// ==== entry=008f76f0 orig=FUN_008f76f0 size=24 name=ListWidget_metaObject ====

undefined ** ListWidget_metaObject(long param_1)

{
  undefined **ppuVar1;
  
  if (*(long *)(*(long *)(param_1 + 8) + 0x28) != 0) {
    ppuVar1 = (undefined **)QObjectData::dynamicMetaObject();
    return ppuVar1;
  }
  return &PTR_staticMetaObject_01199bc0;
}


// ==== entry=008f7708 name=FUN_008f7708 size=16 ====

void FUN_008f7708(QObject *param_1)

{
  QMetaObject::activate(param_1,(QMetaObject *)&PTR_staticMetaObject_01199bc0,0,(void **)0x0);
  return;
}


// ==== entry=008f7718 name=FUN_008f7718 size=52 ====

void FUN_008f7718(undefined8 param_1,int param_2,int param_3,undefined8 *param_4)

{
  if (param_2 == 0) {
    if (param_3 == 0) {
      FUN_008f7708();
      return;
    }
  }
  else if (((param_2 == 10) && (*(code **)param_4[1] == FUN_008f7708)) &&
          (((long *)param_4[1])[1] == 0)) {
    *(undefined4 *)*param_4 = 0;
    return;
  }
  return;
}


// ==== entry=008f774c orig=FUN_008f774c size=66 name=ListWidget_qt_metacast ====

char * ListWidget_qt_metacast(char *param_1,char *param_2)

{
  int iVar1;
  char *pcVar2;
  
  if (param_2 == (char *)0x0) {
    return (char *)0x0;
  }
  iVar1 = strcmp(param_2,"ListWidget");
  if (iVar1 == 0) {
    return param_1;
  }
  pcVar2 = (char *)QListWidget::qt_metacast(param_1);
  return pcVar2;
}


// ==== entry=008f778e orig=FUN_008f778e size=87 name=ListWidget_qt_metacall ====

ulong ListWidget_qt_metacall(undefined8 param_1,int param_2,undefined8 param_3,undefined8 *param_4)

{
  int iVar1;
  ulong uVar2;
  
  uVar2 = QListWidget::qt_metacall();
  iVar1 = (int)uVar2;
  if (-1 < iVar1) {
    if (param_2 == 0) {
      if (iVar1 == 0) {
        FUN_008f7708(param_1);
        uVar2 = uVar2 & 0xffffffff;
      }
    }
    else {
      if (param_2 != 0xc) {
        return uVar2;
      }
      if (iVar1 == 0) {
        *(undefined4 *)*param_4 = 0xffffffff;
      }
    }
    uVar2 = (ulong)((int)uVar2 - 1);
  }
  return uVar2;
}


// ==== entry=008f77f0 orig=FUN_008f77f0 size=24 name=LockScreen_metaObject ====

undefined ** LockScreen_metaObject(long param_1)

{
  undefined **ppuVar1;
  
  if (*(long *)(*(long *)(param_1 + 8) + 0x28) != 0) {
    ppuVar1 = (undefined **)QObjectData::dynamicMetaObject();
    return ppuVar1;
  }
  return &PTR_staticMetaObject_01199e20;
}


// ==== entry=008f7808 name=FUN_008f7808 size=19 ====

void FUN_008f7808(QObject *param_1)

{
  QMetaObject::activate(param_1,(QMetaObject *)&PTR_staticMetaObject_01199e20,1,(void **)0x0);
  return;
}


// ==== entry=008f781c name=FUN_008f781c size=39 ====

void FUN_008f781c(QObject *param_1,undefined8 param_2)

{
  void *local_18;
  undefined8 local_10;
  
  local_18 = (void *)0x0;
  local_10 = param_2;
  QMetaObject::activate(param_1,(QMetaObject *)&PTR_staticMetaObject_01199e20,0,&local_18);
  return;
}


// ==== entry=008f7844 name=FUN_008f7844 size=95 ====

void FUN_008f7844(undefined8 param_1,int param_2,int param_3,undefined8 *param_4)

{
  long *plVar1;
  
  if (param_2 == 0) {
    if (param_3 == 0) {
      FUN_008f781c(param_1,param_4[1]);
      return;
    }
    if (param_3 == 1) {
      FUN_008f7808();
      return;
    }
    return;
  }
  if (param_2 == 10) {
    plVar1 = (long *)param_4[1];
    if (((code *)*plVar1 == FUN_008f781c) && (plVar1[1] == 0)) {
      *(undefined4 *)*param_4 = 0;
      return;
    }
    if (((code *)*plVar1 == FUN_008f7808) && (plVar1[1] == 0)) {
      *(undefined4 *)*param_4 = 1;
      return;
    }
  }
  return;
}


// ==== entry=008f78a4 orig=FUN_008f78a4 size=66 name=LockScreen_qt_metacast ====

char * LockScreen_qt_metacast(char *param_1,char *param_2)

{
  int iVar1;
  char *pcVar2;
  
  if (param_2 == (char *)0x0) {
    return (char *)0x0;
  }
  iVar1 = strcmp(param_2,"LockScreen");
  if (iVar1 == 0) {
    return param_1;
  }
  pcVar2 = (char *)QWidget::qt_metacast(param_1);
  return pcVar2;
}


// ==== entry=008f78e6 orig=FUN_008f78e6 size=93 name=LockScreen_qt_metacall ====

ulong LockScreen_qt_metacall(undefined8 param_1,int param_2,undefined8 param_3,undefined8 *param_4)

{
  int iVar1;
  ulong uVar2;
  
  uVar2 = QWidget::qt_metacall();
  iVar1 = (int)uVar2;
  if (-1 < iVar1) {
    if (param_2 == 0) {
      if (iVar1 < 2) {
        FUN_008f7844(param_1,0,uVar2 & 0xffffffff,param_4);
        uVar2 = uVar2 & 0xffffffff;
      }
    }
    else {
      if (param_2 != 0xc) {
        return uVar2;
      }
      if (iVar1 < 2) {
        *(undefined4 *)*param_4 = 0xffffffff;
      }
    }
    uVar2 = (ulong)((int)uVar2 - 2);
  }
  return uVar2;
}


// ==== entry=008f7944 orig=FUN_008f7944 size=29 name=LockScreen_dtor ====

void LockScreen_dtor(QWidget *param_1)

{
  *(undefined ***)param_1 = &LockScreen_vtable;
  *(undefined ***)(param_1 + 0x10) = &PTR_FUN_01199dc8;
  QWidget::~QWidget(param_1);
  return;
}


// ==== entry=008f7961 name=FUN_008f7961 size=33 ====

void FUN_008f7961(undefined8 *param_1)

{
  param_1[-2] = &LockScreen_vtable;
  *param_1 = &PTR_FUN_01199dc8;
  QWidget::~QWidget((QWidget *)(param_1 + -2));
  return;
}


// ==== entry=008f7982 orig=FUN_008f7982 size=47 name=LockScreen_dtor_deleting ====

void LockScreen_dtor_deleting(QWidget *param_1)

{
  *(undefined ***)param_1 = &LockScreen_vtable;
  *(undefined ***)(param_1 + 0x10) = &PTR_FUN_01199dc8;
  QWidget::~QWidget(param_1);
  operator_delete(param_1,0x98);
  return;
}


// ==== entry=008f79b1 name=FUN_008f79b1 size=51 ====

void FUN_008f79b1(undefined8 *param_1)

{
  param_1[-2] = &LockScreen_vtable;
  *param_1 = &PTR_FUN_01199dc8;
  QWidget::~QWidget((QWidget *)(param_1 + -2));
  operator_delete((QWidget *)(param_1 + -2),0x98);
  return;
}


// ==== entry=008f79f0 orig=FUN_008f79f0 size=24 name=Menu_metaObject ====

undefined ** Menu_metaObject(long param_1)

{
  undefined **ppuVar1;
  
  if (*(long *)(*(long *)(param_1 + 8) + 0x28) != 0) {
    ppuVar1 = (undefined **)QObjectData::dynamicMetaObject();
    return ppuVar1;
  }
  return &PTR_staticMetaObject_0119a080;
}


// ==== entry=008f7a08 name=FUN_008f7a08 size=121 ====

void FUN_008f7a08(QIcon *param_1,undefined4 param_2,long *param_3)

{
  undefined8 uVar1;
  undefined8 *puVar2;
  
  switch(param_2) {
  case 0:
    QWidget::addAction((QAction *)param_1);
    return;
  case 1:
    uVar1 = QMenu::addAction(param_1,(QString *)param_3[1]);
    puVar2 = (undefined8 *)*param_3;
    if (puVar2 == (undefined8 *)0x0) {
      return;
    }
    break;
  case 2:
    uVar1 = QMenu::addMenu((QMenu *)param_1);
    puVar2 = (undefined8 *)*param_3;
    if (puVar2 == (undefined8 *)0x0) {
      return;
    }
    break;
  case 3:
    uVar1 = QMenu::addSection(param_1,(QString *)param_3[1]);
    puVar2 = (undefined8 *)*param_3;
    if (puVar2 == (undefined8 *)0x0) {
      return;
    }
    break;
  case 4:
    QMenu::addSeparator();
    return;
  default:
    return;
  }
  *puVar2 = uVar1;
  return;
}


// ==== entry=008f7a82 name=FUN_008f7a82 size=566 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_008f7a82(undefined8 param_1,int param_2,int param_3,undefined8 *param_4)

{
  int *piVar1;
  char cVar2;
  int iVar3;
  char *pcVar4;
  size_t sVar5;
  uint uVar6;
  int *piVar7;
  QArrayData *local_30;
  
  if (param_2 == 0) {
    FUN_008f7a08(param_1,param_3,param_4);
    return;
  }
  if (param_2 != 0xc) {
    return;
  }
  piVar1 = (int *)*param_4;
  if (param_3 == 0) {
    if (*(int *)param_4[1] != 0) goto LAB_008f7aca;
    piVar7 = &DAT_011c0b04;
    iVar3 = DAT_011c0b04;
    if (DAT_011c0b04 != 0) goto LAB_008f7ba9;
    pcVar4 = (char *)QMetaObject::className();
    local_30 = (QArrayData *)&QArrayData::shared_null;
    sVar5 = strlen(pcVar4);
    uVar6 = (int)sVar5 + 1;
    if (((uint)QArrayData::shared_null < 2) && ((int)sVar5 + 2U <= (_files & 0x7fffffff))) {
      _files = _files | 0x80000000;
    }
    else {
      if (uVar6 <= QArrayData::shared_null._4_4_) {
        uVar6 = QArrayData::shared_null._4_4_;
      }
                    /* try { // try from 008f7b46 to 008f7b86 has its CatchHandler @ 008f7cb8 */
      QByteArray::reallocData(&local_30,uVar6 + 1,1);
    }
    cVar2 = QByteArray::append((char *)&local_30);
    QByteArray::append(cVar2);
    iVar3 = QMetaType::registerNormalizedType
                      (&local_30,FUN_00532c15,FUN_00532c16,8,0x10c,&QAction::staticMetaObject);
  }
  else {
    if ((param_3 != 2) || (*(int *)param_4[1] != 0)) {
LAB_008f7aca:
      *piVar1 = -1;
      return;
    }
    piVar7 = &DAT_011c1df8;
    iVar3 = DAT_011c1df8;
    if (DAT_011c1df8 != 0) goto LAB_008f7ba9;
    pcVar4 = (char *)QMetaObject::className();
    local_30 = (QArrayData *)&QArrayData::shared_null;
    sVar5 = strlen(pcVar4);
    uVar6 = (int)sVar5 + 1;
    if (((uint)QArrayData::shared_null < 2) && ((int)sVar5 + 2U <= (_files & 0x7fffffff))) {
      _files = _files | 0x80000000;
    }
    else {
      if (uVar6 <= QArrayData::shared_null._4_4_) {
        uVar6 = QArrayData::shared_null._4_4_;
      }
                    /* try { // try from 008f7c0b to 008f7c4b has its CatchHandler @ 008f7cc0 */
      QByteArray::reallocData(&local_30,uVar6 + 1,1);
    }
    cVar2 = QByteArray::append((char *)&local_30);
    QByteArray::append(cVar2);
    iVar3 = QMetaType::registerNormalizedType
                      (&local_30,FUN_00770202,FUN_00770203,8,0x10c,&PTR_staticMetaObject_0119a080);
  }
  *piVar7 = iVar3;
  if (*(int *)local_30 != 0) {
    if (*(int *)local_30 != -1) {
      LOCK();
      *(int *)local_30 = *(int *)local_30 + -1;
      UNLOCK();
      if (*(int *)local_30 == 0) goto LAB_008f7c56;
    }
LAB_008f7ba9:
    *piVar1 = iVar3;
    return;
  }
LAB_008f7c56:
  QArrayData::deallocate(local_30,1,8);
  *piVar1 = iVar3;
  return;
}


// ==== entry=008f7cc8 orig=FUN_008f7cc8 size=66 name=Menu_qt_metacast ====

char * Menu_qt_metacast(char *param_1,char *param_2)

{
  int iVar1;
  char *pcVar2;
  
  if (param_2 == (char *)0x0) {
    return (char *)0x0;
  }
  iVar1 = strcmp(param_2,"Menu");
  if (iVar1 == 0) {
    return param_1;
  }
  pcVar2 = (char *)QMenu::qt_metacast(param_1);
  return pcVar2;
}


// ==== entry=008f7d0a orig=FUN_008f7d0a size=107 name=Menu_qt_metacall ====

ulong Menu_qt_metacall(undefined8 param_1,int param_2,undefined8 param_3,undefined8 param_4)

{
  int iVar1;
  ulong uVar2;
  
  uVar2 = QMenu::qt_metacall();
  iVar1 = (int)uVar2;
  if (-1 < iVar1) {
    if (param_2 == 0) {
      if (iVar1 < 5) {
        FUN_008f7a08(param_1,uVar2 & 0xffffffff,param_4);
        uVar2 = uVar2 & 0xffffffff;
      }
    }
    else {
      if (param_2 != 0xc) {
        return uVar2;
      }
      if (iVar1 < 5) {
        FUN_008f7a82(param_1,0xc,uVar2 & 0xffffffff,param_4);
        uVar2 = uVar2 & 0xffffffff;
      }
    }
    uVar2 = (ulong)((int)uVar2 - 5);
  }
  return uVar2;
}


// ==== entry=008f7d76 orig=FUN_008f7d76 size=29 name=Menu_dtor ====

void Menu_dtor(QMenu *param_1)

{
  *(undefined ***)param_1 = &Menu_vtable;
  *(undefined ***)(param_1 + 0x10) = &PTR_FUN_0119a028;
  QMenu::~QMenu(param_1);
  return;
}


// ==== entry=008f7d93 name=FUN_008f7d93 size=33 ====

void FUN_008f7d93(undefined8 *param_1)

{
  param_1[-2] = &Menu_vtable;
  *param_1 = &PTR_FUN_0119a028;
  QMenu::~QMenu((QMenu *)(param_1 + -2));
  return;
}


// ==== entry=008f7db4 orig=FUN_008f7db4 size=47 name=Menu_dtor_deleting ====

void Menu_dtor_deleting(QMenu *param_1)

{
  *(undefined ***)param_1 = &Menu_vtable;
  *(undefined ***)(param_1 + 0x10) = &PTR_FUN_0119a028;
  QMenu::~QMenu(param_1);
  operator_delete(param_1,0x30);
  return;
}


// ==== entry=008f7de3 name=FUN_008f7de3 size=51 ====

void FUN_008f7de3(undefined8 *param_1)

{
  param_1[-2] = &Menu_vtable;
  *param_1 = &PTR_FUN_0119a028;
  QMenu::~QMenu((QMenu *)(param_1 + -2));
  operator_delete((QMenu *)(param_1 + -2),0x30);
  return;
}


// ==== entry=008f7e20 orig=FUN_008f7e20 size=24 name=MessageBar_metaObject ====

undefined ** MessageBar_metaObject(long param_1)

{
  undefined **ppuVar1;
  
  if (*(long *)(*(long *)(param_1 + 8) + 0x28) != 0) {
    ppuVar1 = (undefined **)QObjectData::dynamicMetaObject();
    return ppuVar1;
  }
  return &PTR_staticMetaObject_0119a2e0;
}


// ==== entry=008f7e38 name=FUN_008f7e38 size=56 ====

void FUN_008f7e38(QObject *param_1,undefined4 param_2,undefined8 param_3)

{
  undefined4 local_2c;
  void *local_28;
  undefined4 *local_20;
  undefined8 local_18;
  
  local_28 = (void *)0x0;
  local_20 = &local_2c;
  local_2c = param_2;
  local_18 = param_3;
  QMetaObject::activate(param_1,(QMetaObject *)&PTR_staticMetaObject_0119a2e0,0,&local_28);
  return;
}


// ==== entry=008f7e70 name=FUN_008f7e70 size=175 ====

void FUN_008f7e70(undefined8 param_1,int param_2,int param_3,undefined8 *param_4)

{
  QArrayData *local_20 [2];
  
  if (param_2 == 0) {
    if (param_3 == 0) {
      FUN_008f7e38(param_1,*(undefined4 *)param_4[1],param_4[2]);
      return;
    }
    if (param_3 == 1) {
      local_20[0] = (QArrayData *)QString::fromAscii_helper("",0);
                    /* try { // try from 008f7eaa to 008f7eae has its CatchHandler @ 008f7f1f */
      FUN_008f7e38(param_1,*(undefined4 *)param_4[1],local_20);
      if (*(int *)local_20[0] != 0) {
        if (*(int *)local_20[0] == -1) {
          return;
        }
        LOCK();
        *(int *)local_20[0] = *(int *)local_20[0] + -1;
        UNLOCK();
        if (*(int *)local_20[0] != 0) {
          return;
        }
      }
      QArrayData::deallocate(local_20[0],2,8);
    }
  }
  else if (((param_2 == 10) && (*(code **)param_4[1] == FUN_008f7e38)) &&
          (((long *)param_4[1])[1] == 0)) {
    *(undefined4 *)*param_4 = 0;
  }
  return;
}


// ==== entry=008f7f28 orig=FUN_008f7f28 size=66 name=MessageBar_qt_metacast ====

char * MessageBar_qt_metacast(char *param_1,char *param_2)

{
  int iVar1;
  char *pcVar2;
  
  if (param_2 == (char *)0x0) {
    return (char *)0x0;
  }
  iVar1 = strcmp(param_2,"MessageBar");
  if (iVar1 == 0) {
    return param_1;
  }
  pcVar2 = (char *)QWidget::qt_metacast(param_1);
  return pcVar2;
}


// ==== entry=008f7f6a orig=FUN_008f7f6a size=93 name=MessageBar_qt_metacall ====

ulong MessageBar_qt_metacall(undefined8 param_1,int param_2,undefined8 param_3,undefined8 *param_4)

{
  int iVar1;
  ulong uVar2;
  
  uVar2 = QWidget::qt_metacall();
  iVar1 = (int)uVar2;
  if (-1 < iVar1) {
    if (param_2 == 0) {
      if (iVar1 < 2) {
        FUN_008f7e70(param_1,0,uVar2 & 0xffffffff,param_4);
        uVar2 = uVar2 & 0xffffffff;
      }
    }
    else {
      if (param_2 != 0xc) {
        return uVar2;
      }
      if (iVar1 < 2) {
        *(undefined4 *)*param_4 = 0xffffffff;
      }
    }
    uVar2 = (ulong)((int)uVar2 - 2);
  }
  return uVar2;
}


// ==== entry=008f7fc8 orig=FUN_008f7fc8 size=95 name=MessageBar_dtor ====

void MessageBar_dtor(QWidget *param_1)

{
  QArrayData *pQVar1;
  
  *(undefined ***)param_1 = &MessageBar_vtable;
  *(undefined ***)(param_1 + 0x10) = &PTR_FUN_0119a288;
  FUN_0059d0a0(param_1 + 0x60);
  pQVar1 = *(QArrayData **)(param_1 + 0x58);
  if (*(int *)pQVar1 == 0) {
LAB_008f800f:
    QArrayData::deallocate(pQVar1,2,8);
    QWidget::~QWidget(param_1);
    return;
  }
  if (*(int *)pQVar1 != -1) {
    LOCK();
    *(int *)pQVar1 = *(int *)pQVar1 + -1;
    UNLOCK();
    if (*(int *)pQVar1 == 0) {
      pQVar1 = *(QArrayData **)(param_1 + 0x58);
      goto LAB_008f800f;
    }
  }
  QWidget::~QWidget(param_1);
  return;
}


// ==== entry=008f8027 name=FUN_008f8027 size=97 ====

void FUN_008f8027(undefined8 *param_1)

{
  QArrayData *pQVar1;
  
  param_1[-2] = &MessageBar_vtable;
  *param_1 = &PTR_FUN_0119a288;
  FUN_0059d0a0(param_1 + 10);
  pQVar1 = (QArrayData *)param_1[9];
  if (*(int *)pQVar1 == 0) {
LAB_008f806f:
    QArrayData::deallocate(pQVar1,2,8);
    QWidget::~QWidget((QWidget *)(param_1 + -2));
    return;
  }
  if (*(int *)pQVar1 != -1) {
    LOCK();
    *(int *)pQVar1 = *(int *)pQVar1 + -1;
    UNLOCK();
    if (*(int *)pQVar1 == 0) {
      pQVar1 = (QArrayData *)param_1[9];
      goto LAB_008f806f;
    }
  }
  QWidget::~QWidget((QWidget *)(param_1 + -2));
  return;
}


// ==== entry=008f8088 name=FUN_008f8088 size=115 ====

void FUN_008f8088(undefined8 *param_1)

{
  QArrayData *pQVar1;
  
  param_1[-2] = &MessageBar_vtable;
  *param_1 = &PTR_FUN_0119a288;
  FUN_0059d0a0(param_1 + 10);
  pQVar1 = (QArrayData *)param_1[9];
  if (*(int *)pQVar1 != 0) {
    if (*(int *)pQVar1 == -1) goto LAB_008f80cb;
    LOCK();
    *(int *)pQVar1 = *(int *)pQVar1 + -1;
    UNLOCK();
    if (*(int *)pQVar1 != 0) goto LAB_008f80cb;
    pQVar1 = (QArrayData *)param_1[9];
  }
  QArrayData::deallocate(pQVar1,2,8);
LAB_008f80cb:
  QWidget::~QWidget((QWidget *)(param_1 + -2));
  operator_delete((QWidget *)(param_1 + -2),0x68);
  return;
}


// ==== entry=008f80fc orig=FUN_008f80fc size=101 name=MessageBar_dtor_deleting ====

void MessageBar_dtor_deleting(QWidget *param_1)

{
  QArrayData *pQVar1;
  
  *(undefined ***)param_1 = &MessageBar_vtable;
  *(undefined ***)(param_1 + 0x10) = &PTR_FUN_0119a288;
  FUN_0059d0a0(param_1 + 0x60);
  pQVar1 = *(QArrayData **)(param_1 + 0x58);
  if (*(int *)pQVar1 != 0) {
    if (*(int *)pQVar1 == -1) goto LAB_008f8136;
    LOCK();
    *(int *)pQVar1 = *(int *)pQVar1 + -1;
    UNLOCK();
    if (*(int *)pQVar1 != 0) goto LAB_008f8136;
    pQVar1 = *(QArrayData **)(param_1 + 0x58);
  }
  QArrayData::deallocate(pQVar1,2,8);
LAB_008f8136:
  QWidget::~QWidget(param_1);
  operator_delete(param_1,0x68);
  return;
}


// ==== entry=008f8170 orig=FUN_008f8170 size=24 name=BreadCrumb_metaObject ====

undefined ** BreadCrumb_metaObject(long param_1)

{
  undefined **ppuVar1;
  
  if (*(long *)(*(long *)(param_1 + 8) + 0x28) != 0) {
    ppuVar1 = (undefined **)QObjectData::dynamicMetaObject();
    return ppuVar1;
  }
  return &PTR_staticMetaObject_0119a540;
}


// ==== entry=008f8188 name=FUN_008f8188 size=71 ====

void FUN_008f8188(QObject *param_1,undefined8 param_2,undefined4 param_3,undefined8 param_4)

{
  undefined4 local_34;
  undefined8 local_30;
  void *local_28;
  undefined8 *local_20;
  undefined4 *local_18;
  undefined8 local_10;
  
  local_28 = (void *)0x0;
  local_20 = &local_30;
  local_18 = &local_34;
  local_34 = param_3;
  local_30 = param_2;
  local_10 = param_4;
  QMetaObject::activate(param_1,(QMetaObject *)&PTR_staticMetaObject_0119a540,0,&local_28);
  return;
}


// ==== entry=008f81d0 name=FUN_008f81d0 size=74 ====

void FUN_008f81d0(QObject *param_1,undefined8 param_2,undefined4 param_3,undefined8 param_4)

{
  undefined4 local_34;
  undefined8 local_30;
  void *local_28;
  undefined8 *local_20;
  undefined4 *local_18;
  undefined8 local_10;
  
  local_28 = (void *)0x0;
  local_20 = &local_30;
  local_18 = &local_34;
  local_34 = param_3;
  local_30 = param_2;
  local_10 = param_4;
  QMetaObject::activate(param_1,(QMetaObject *)&PTR_staticMetaObject_0119a540,1,&local_28);
  return;
}


// ==== entry=008f821a name=FUN_008f821a size=42 ====

void FUN_008f821a(QObject *param_1,undefined8 param_2)

{
  void *local_18;
  undefined8 local_10;
  
  local_18 = (void *)0x0;
  local_10 = param_2;
  QMetaObject::activate(param_1,(QMetaObject *)&PTR_staticMetaObject_0119a540,2,&local_18);
  return;
}


// ==== entry=008f8244 name=FUN_008f8244 size=42 ====

void FUN_008f8244(QObject *param_1,undefined8 param_2)

{
  void *local_18;
  undefined8 local_10;
  
  local_18 = (void *)0x0;
  local_10 = param_2;
  QMetaObject::activate(param_1,(QMetaObject *)&PTR_staticMetaObject_0119a540,4,&local_18);
  return;
}


// ==== entry=008f826e name=FUN_008f826e size=55 ====

void FUN_008f826e(QObject *param_1,undefined1 param_2)

{
  undefined1 local_1c [4];
  void *local_18;
  undefined1 *local_10;
  
  local_18 = (void *)0x0;
  local_10 = local_1c;
  local_1c[0] = param_2;
  QMetaObject::activate(param_1,(QMetaObject *)&PTR_staticMetaObject_0119a540,3,&local_18);
  return;
}


// ==== entry=008f82a6 name=FUN_008f82a6 size=305 ====

void FUN_008f82a6(undefined8 param_1,int param_2,undefined4 param_3,undefined8 *param_4)

{
  undefined4 *puVar1;
  long *plVar2;
  code *pcVar3;
  
  if (param_2 == 0) {
    switch(param_3) {
    case 0:
      FUN_008f8188(param_1,*(undefined8 *)param_4[1],*(undefined4 *)param_4[2],param_4[3]);
      return;
    case 1:
      FUN_008f81d0(param_1,*(undefined8 *)param_4[1],*(undefined4 *)param_4[2],param_4[3]);
      return;
    case 2:
      FUN_008f821a(param_1,param_4[1]);
      return;
    case 3:
      FUN_008f826e(param_1,*(undefined1 *)param_4[1]);
      return;
    case 4:
      FUN_008f8244(param_1,param_4[1]);
      return;
    case 5:
      FUN_00548cc6(param_1,*(undefined4 *)param_4[1],*(undefined1 *)param_4[2]);
      return;
    case 6:
      FUN_00548cc6(param_1,*(undefined4 *)param_4[1],0);
      return;
    case 7:
      FUN_00548cd2();
      return;
    }
  }
  else if (param_2 == 10) {
    puVar1 = (undefined4 *)*param_4;
    plVar2 = (long *)param_4[1];
    pcVar3 = (code *)*plVar2;
    if (pcVar3 == FUN_008f8188) {
      if (plVar2[1] == 0) {
        *puVar1 = 0;
        return;
      }
    }
    else if ((pcVar3 == FUN_008f81d0) && (plVar2[1] == 0)) {
      *puVar1 = 1;
      return;
    }
    if ((pcVar3 == FUN_008f821a) && (plVar2[1] == 0)) {
      *puVar1 = 2;
      return;
    }
    if ((pcVar3 == FUN_008f826e) && (plVar2[1] == 0)) {
      *puVar1 = 3;
      return;
    }
    if ((pcVar3 == FUN_008f8244) && (plVar2[1] == 0)) {
      *puVar1 = 4;
    }
  }
  return;
}


// ==== entry=008f83d8 orig=FUN_008f83d8 size=66 name=BreadCrumb_qt_metacast ====

char * BreadCrumb_qt_metacast(char *param_1,char *param_2)

{
  int iVar1;
  char *pcVar2;
  
  if (param_2 == (char *)0x0) {
    return (char *)0x0;
  }
  iVar1 = strcmp(param_2,"BreadCrumb");
  if (iVar1 == 0) {
    return param_1;
  }
  pcVar2 = (char *)QWidget::qt_metacast(param_1);
  return pcVar2;
}


// ==== entry=008f841a orig=FUN_008f841a size=93 name=BreadCrumb_qt_metacall ====

ulong BreadCrumb_qt_metacall(undefined8 param_1,int param_2,undefined8 param_3,undefined8 *param_4)

{
  int iVar1;
  ulong uVar2;
  
  uVar2 = QWidget::qt_metacall();
  iVar1 = (int)uVar2;
  if (-1 < iVar1) {
    if (param_2 == 0) {
      if (iVar1 < 8) {
        FUN_008f82a6(param_1,0,uVar2 & 0xffffffff,param_4);
        uVar2 = uVar2 & 0xffffffff;
      }
    }
    else {
      if (param_2 != 0xc) {
        return uVar2;
      }
      if (iVar1 < 8) {
        *(undefined4 *)*param_4 = 0xffffffff;
      }
    }
    uVar2 = (ulong)((int)uVar2 - 8);
  }
  return uVar2;
}


// ==== entry=008f8480 name=FUN_008f8480 size=1 ====

void FUN_008f8480(void)

{
  return;
}


// ==== entry=008f8482 orig=FUN_008f8482 size=24 name=BreadButton_metaObject ====

undefined ** BreadButton_metaObject(long param_1)

{
  undefined **ppuVar1;
  
  if (*(long *)(*(long *)(param_1 + 8) + 0x28) != 0) {
    ppuVar1 = (undefined **)QObjectData::dynamicMetaObject();
    return ppuVar1;
  }
  return &PTR_staticMetaObject_0119ac60;
}


// ==== entry=008f849a orig=FUN_008f849a size=24 name=BreadMenu_metaObject ====

undefined ** BreadMenu_metaObject(long param_1)

{
  undefined **ppuVar1;
  
  if (*(long *)(*(long *)(param_1 + 8) + 0x28) != 0) {
    ppuVar1 = (undefined **)QObjectData::dynamicMetaObject();
    return ppuVar1;
  }
  return &PTR_staticMetaObject_0119ac20;
}


// ==== entry=008f84b2 orig=FUN_008f84b2 size=24 name=BreadEdit_metaObject ====

undefined ** BreadEdit_metaObject(long param_1)

{
  undefined **ppuVar1;
  
  if (*(long *)(*(long *)(param_1 + 8) + 0x28) != 0) {
    ppuVar1 = (undefined **)QObjectData::dynamicMetaObject();
    return ppuVar1;
  }
  return &PTR_PTR_0119abe0;
}


// ==== entry=008f84ca name=FUN_008f84ca size=71 ====

void FUN_008f84ca(QObject *param_1,undefined8 param_2,undefined4 param_3,undefined8 param_4)

{
  undefined4 local_34;
  undefined8 local_30;
  void *local_28;
  undefined8 *local_20;
  undefined4 *local_18;
  undefined8 local_10;
  
  local_28 = (void *)0x0;
  local_20 = &local_30;
  local_18 = &local_34;
  local_34 = param_3;
  local_30 = param_2;
  local_10 = param_4;
  QMetaObject::activate(param_1,(QMetaObject *)&PTR_PTR_0119abe0,0,&local_28);
  return;
}


// ==== entry=008f8512 name=FUN_008f8512 size=74 ====

void FUN_008f8512(QObject *param_1,undefined8 param_2,undefined4 param_3,undefined8 param_4)

{
  undefined4 local_34;
  undefined8 local_30;
  void *local_28;
  undefined8 *local_20;
  undefined4 *local_18;
  undefined8 local_10;
  
  local_28 = (void *)0x0;
  local_20 = &local_30;
  local_18 = &local_34;
  local_34 = param_3;
  local_30 = param_2;
  local_10 = param_4;
  QMetaObject::activate(param_1,(QMetaObject *)&PTR_PTR_0119abe0,1,&local_28);
  return;
}


// ==== entry=008f855c name=FUN_008f855c size=134 ====

void FUN_008f855c(undefined8 param_1,int param_2,int param_3,undefined8 *param_4)

{
  long *plVar1;
  
  if (param_2 != 0) {
    if (param_2 == 10) {
      plVar1 = (long *)param_4[1];
      if ((code *)*plVar1 == FUN_008f84ca) {
        if (plVar1[1] == 0) {
          *(undefined4 *)*param_4 = 0;
          return;
        }
      }
      else if (((code *)*plVar1 == FUN_008f8512) && (plVar1[1] == 0)) {
        *(undefined4 *)*param_4 = 1;
        return;
      }
    }
    return;
  }
  if (param_3 == 0) {
    FUN_008f84ca(param_1,*(undefined8 *)param_4[1],*(undefined4 *)param_4[2],param_4[3]);
    return;
  }
  if (param_3 == 1) {
    FUN_008f8512(param_1,*(undefined8 *)param_4[1],*(undefined4 *)param_4[2],param_4[3]);
    return;
  }
  return;
}


// ==== entry=008f85e2 name=FUN_008f85e2 size=1 ====

void FUN_008f85e2(void)

{
  return;
}


// ==== entry=008f85e4 orig=FUN_008f85e4 size=66 name=BreadButton_qt_metacast ====

char * BreadButton_qt_metacast(char *param_1,char *param_2)

{
  int iVar1;
  char *pcVar2;
  
  if (param_2 == (char *)0x0) {
    return (char *)0x0;
  }
  iVar1 = strcmp(param_2,"BreadButton");
  if (iVar1 == 0) {
    return param_1;
  }
  pcVar2 = (char *)QToolButton::qt_metacast(param_1);
  return pcVar2;
}


// ==== entry=008f8626 orig=FUN_008f8626 size=5 name=BreadButton_qt_metacall ====

void QToolButton::BreadButton_qt_metacall(void)

{
  qt_metacall();
  return;
}


// ==== entry=008f862c orig=FUN_008f862c size=66 name=BreadMenu_qt_metacast ====

char * BreadMenu_qt_metacast(char *param_1,char *param_2)

{
  int iVar1;
  char *pcVar2;
  
  if (param_2 == (char *)0x0) {
    return (char *)0x0;
  }
  iVar1 = strcmp(param_2,"BreadMenu");
  if (iVar1 == 0) {
    return param_1;
  }
  pcVar2 = (char *)QMenu::qt_metacast(param_1);
  return pcVar2;
}


// ==== entry=008f866e orig=FUN_008f866e size=5 name=BreadMenu_qt_metacall ====

void QMenu::BreadMenu_qt_metacall(void)

{
  qt_metacall();
  return;
}


// ==== entry=008f8674 orig=FUN_008f8674 size=66 name=BreadEdit_qt_metacast ====

undefined8 BreadEdit_qt_metacast(undefined8 param_1,char *param_2)

{
  int iVar1;
  undefined8 uVar2;
  
  if (param_2 == (char *)0x0) {
    return 0;
  }
  iVar1 = strcmp(param_2,"BreadEdit");
  if (iVar1 == 0) {
    return param_1;
  }
  uVar2 = s_LineEdit_8f6e2e(param_1,param_2);
  return uVar2;
}


// ==== entry=008f86b6 orig=FUN_008f86b6 size=93 name=BreadEdit_qt_metacall ====

ulong BreadEdit_qt_metacall(undefined8 param_1,int param_2,undefined8 param_3,undefined8 *param_4)

{
  int iVar1;
  ulong uVar2;
  
  uVar2 = FUN_008f6e70();
  iVar1 = (int)uVar2;
  if (-1 < iVar1) {
    if (param_2 == 0) {
      if (iVar1 < 2) {
        FUN_008f855c(param_1,0,uVar2 & 0xffffffff,param_4);
        uVar2 = uVar2 & 0xffffffff;
      }
    }
    else {
      if (param_2 != 0xc) {
        return uVar2;
      }
      if (iVar1 < 2) {
        *(undefined4 *)*param_4 = 0xffffffff;
      }
    }
    uVar2 = (ulong)((int)uVar2 - 2);
  }
  return uVar2;
}


// ==== entry=008f8714 orig=FUN_008f8714 size=29 name=BreadMenu_dtor ====

void BreadMenu_dtor(QMenu *param_1)

{
  *(undefined ***)param_1 = &BreadMenu_vtable;
  *(undefined ***)(param_1 + 0x10) = &PTR_FUN_0119a990;
  QMenu::~QMenu(param_1);
  return;
}


// ==== entry=008f8731 name=FUN_008f8731 size=33 ====

void FUN_008f8731(undefined8 *param_1)

{
  param_1[-2] = &BreadMenu_vtable;
  *param_1 = &PTR_FUN_0119a990;
  QMenu::~QMenu((QMenu *)(param_1 + -2));
  return;
}


// ==== entry=008f8752 orig=FUN_008f8752 size=47 name=BreadMenu_dtor_deleting ====

void BreadMenu_dtor_deleting(QMenu *param_1)

{
  *(undefined ***)param_1 = &BreadMenu_vtable;
  *(undefined ***)(param_1 + 0x10) = &PTR_FUN_0119a990;
  QMenu::~QMenu(param_1);
  operator_delete(param_1,0x38);
  return;
}


// ==== entry=008f8781 name=FUN_008f8781 size=51 ====

void FUN_008f8781(undefined8 *param_1)

{
  param_1[-2] = &BreadMenu_vtable;
  *param_1 = &PTR_FUN_0119a990;
  QMenu::~QMenu((QMenu *)(param_1 + -2));
  operator_delete((QMenu *)(param_1 + -2),0x38);
  return;
}


// ==== entry=008f87b4 orig=FUN_008f87b4 size=95 name=BreadButton_dtor ====

void BreadButton_dtor(QToolButton *param_1)

{
  QArrayData *pQVar1;
  
  *(undefined ***)param_1 = &BreadButton_vtable;
  *(undefined ***)(param_1 + 0x10) = &PTR_FUN_0119a790;
  FUN_00550ec0(param_1 + 0x40);
  pQVar1 = *(QArrayData **)(param_1 + 0x30);
  if (*(int *)pQVar1 == 0) {
LAB_008f87fb:
    QArrayData::deallocate(pQVar1,2,8);
    QToolButton::~QToolButton(param_1);
    return;
  }
  if (*(int *)pQVar1 != -1) {
    LOCK();
    *(int *)pQVar1 = *(int *)pQVar1 + -1;
    UNLOCK();
    if (*(int *)pQVar1 == 0) {
      pQVar1 = *(QArrayData **)(param_1 + 0x30);
      goto LAB_008f87fb;
    }
  }
  QToolButton::~QToolButton(param_1);
  return;
}


// ==== entry=008f8813 name=FUN_008f8813 size=97 ====

void FUN_008f8813(undefined8 *param_1)

{
  QArrayData *pQVar1;
  
  param_1[-2] = &BreadButton_vtable;
  *param_1 = &PTR_FUN_0119a790;
  FUN_00550ec0(param_1 + 6);
  pQVar1 = (QArrayData *)param_1[4];
  if (*(int *)pQVar1 == 0) {
LAB_008f885b:
    QArrayData::deallocate(pQVar1,2,8);
    QToolButton::~QToolButton((QToolButton *)(param_1 + -2));
    return;
  }
  if (*(int *)pQVar1 != -1) {
    LOCK();
    *(int *)pQVar1 = *(int *)pQVar1 + -1;
    UNLOCK();
    if (*(int *)pQVar1 == 0) {
      pQVar1 = (QArrayData *)param_1[4];
      goto LAB_008f885b;
    }
  }
  QToolButton::~QToolButton((QToolButton *)(param_1 + -2));
  return;
}


// ==== entry=008f8874 name=FUN_008f8874 size=115 ====

void FUN_008f8874(undefined8 *param_1)

{
  QArrayData *pQVar1;
  
  param_1[-2] = &BreadButton_vtable;
  *param_1 = &PTR_FUN_0119a790;
  FUN_00550ec0(param_1 + 6);
  pQVar1 = (QArrayData *)param_1[4];
  if (*(int *)pQVar1 != 0) {
    if (*(int *)pQVar1 == -1) goto LAB_008f88b7;
    LOCK();
    *(int *)pQVar1 = *(int *)pQVar1 + -1;
    UNLOCK();
    if (*(int *)pQVar1 != 0) goto LAB_008f88b7;
    pQVar1 = (QArrayData *)param_1[4];
  }
  QArrayData::deallocate(pQVar1,2,8);
LAB_008f88b7:
  QToolButton::~QToolButton((QToolButton *)(param_1 + -2));
  operator_delete((QToolButton *)(param_1 + -2),0x50);
  return;
}


// ==== entry=008f88e8 orig=FUN_008f88e8 size=101 name=BreadButton_dtor_deleting ====

void BreadButton_dtor_deleting(QToolButton *param_1)

{
  QArrayData *pQVar1;
  
  *(undefined ***)param_1 = &BreadButton_vtable;
  *(undefined ***)(param_1 + 0x10) = &PTR_FUN_0119a790;
  FUN_00550ec0(param_1 + 0x40);
  pQVar1 = *(QArrayData **)(param_1 + 0x30);
  if (*(int *)pQVar1 != 0) {
    if (*(int *)pQVar1 == -1) goto LAB_008f8922;
    LOCK();
    *(int *)pQVar1 = *(int *)pQVar1 + -1;
    UNLOCK();
    if (*(int *)pQVar1 != 0) goto LAB_008f8922;
    pQVar1 = *(QArrayData **)(param_1 + 0x30);
  }
  QArrayData::deallocate(pQVar1,2,8);
LAB_008f8922:
  QToolButton::~QToolButton(param_1);
  operator_delete(param_1,0x50);
  return;
}


// ==== entry=008f8950 orig=FUN_008f8950 size=24 name=AddressBar_metaObject ====

undefined ** AddressBar_metaObject(long param_1)

{
  undefined **ppuVar1;
  
  if (*(long *)(*(long *)(param_1 + 8) + 0x28) != 0) {
    ppuVar1 = (undefined **)QObjectData::dynamicMetaObject();
    return ppuVar1;
  }
  return &PTR_PTR_0119aec0;
}


// ==== entry=008f8968 orig=FUN_008f8968 size=66 name=AddressBar_qt_metacast ====

undefined8 AddressBar_qt_metacast(undefined8 param_1,char *param_2)

{
  int iVar1;
  undefined8 uVar2;
  
  if (param_2 == (char *)0x0) {
    return 0;
  }
  iVar1 = strcmp(param_2,"AddressBar");
  if (iVar1 == 0) {
    return param_1;
  }
  uVar2 = BreadCrumb_qt_metacast(param_1,param_2);
  return uVar2;
}


// ==== entry=008f89aa name=FUN_008f89aa size=16 ====

void FUN_008f89aa(QObject *param_1)

{
  QMetaObject::activate(param_1,(QMetaObject *)&PTR_PTR_0119aec0,0,(void **)0x0);
  return;
}


// ==== entry=008f89ba name=FUN_008f89ba size=52 ====

void FUN_008f89ba(undefined8 param_1,int param_2,int param_3,undefined8 *param_4)

{
  if (param_2 == 0) {
    if (param_3 == 0) {
      FUN_008f89aa();
      return;
    }
  }
  else if (((param_2 == 10) && (*(code **)param_4[1] == FUN_008f89aa)) &&
          (((long *)param_4[1])[1] == 0)) {
    *(undefined4 *)*param_4 = 0;
    return;
  }
  return;
}


// ==== entry=008f89ee orig=FUN_008f89ee size=87 name=AddressBar_qt_metacall ====

ulong AddressBar_qt_metacall(undefined8 param_1,int param_2,undefined8 param_3,undefined8 *param_4)

{
  int iVar1;
  ulong uVar2;
  
  uVar2 = BreadCrumb_qt_metacall();
  iVar1 = (int)uVar2;
  if (-1 < iVar1) {
    if (param_2 == 0) {
      if (iVar1 == 0) {
        FUN_008f89aa(param_1);
        uVar2 = uVar2 & 0xffffffff;
      }
    }
    else {
      if (param_2 != 0xc) {
        return uVar2;
      }
      if (iVar1 == 0) {
        *(undefined4 *)*param_4 = 0xffffffff;
      }
    }
    uVar2 = (ulong)((int)uVar2 - 1);
  }
  return uVar2;
}


// ==== entry=008f8a46 orig=FUN_008f8a46 size=79 name=AddressBar_dtor_deleting ====

void AddressBar_dtor_deleting(QWidget *param_1)

{
  int *piVar1;
  
  *(undefined ***)param_1 = &BreadCrumb_vtable;
  *(undefined **)(param_1 + 0x10) = &DAT_0119a500;
  piVar1 = *(int **)(param_1 + 0x38);
  if (piVar1 != (int *)0x0) {
    LOCK();
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if ((*piVar1 == 0) && (*(void **)(param_1 + 0x38) != (void *)0x0)) {
      operator_delete(*(void **)(param_1 + 0x38));
    }
  }
  QWidget::~QWidget(param_1);
  operator_delete(param_1,0x48);
  return;
}


// ==== entry=008f8a95 name=FUN_008f8a95 size=80 ====

void FUN_008f8a95(undefined8 *param_1)

{
  int *piVar1;
  
  param_1[-2] = &BreadCrumb_vtable;
  *param_1 = &DAT_0119a500;
  piVar1 = (int *)param_1[5];
  if (piVar1 != (int *)0x0) {
    LOCK();
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if ((*piVar1 == 0) && ((void *)param_1[5] != (void *)0x0)) {
      operator_delete((void *)param_1[5]);
    }
  }
  QWidget::~QWidget((QWidget *)(param_1 + -2));
  operator_delete((QWidget *)(param_1 + -2),0x48);
  return;
}


// ==== entry=008f8ae6 name=FUN_008f8ae6 size=67 ====

void FUN_008f8ae6(undefined8 *param_1)

{
  int *piVar1;
  
  param_1[-2] = &BreadCrumb_vtable;
  *param_1 = &DAT_0119a500;
  piVar1 = (int *)param_1[5];
  if (piVar1 != (int *)0x0) {
    LOCK();
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if ((*piVar1 == 0) && ((void *)param_1[5] != (void *)0x0)) {
      operator_delete((void *)param_1[5]);
    }
  }
  QWidget::~QWidget((QWidget *)(param_1 + -2));
  return;
}


// ==== entry=008f8b2a orig=FUN_008f8b2a size=66 name=AddressBar_dtor ====

void AddressBar_dtor(QWidget *param_1)

{
  int *piVar1;
  
  *(undefined ***)param_1 = &BreadCrumb_vtable;
  *(undefined **)(param_1 + 0x10) = &DAT_0119a500;
  piVar1 = *(int **)(param_1 + 0x38);
  if (piVar1 != (int *)0x0) {
    LOCK();
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if ((*piVar1 == 0) && (*(void **)(param_1 + 0x38) != (void *)0x0)) {
      operator_delete(*(void **)(param_1 + 0x38));
    }
  }
  QWidget::~QWidget(param_1);
  return;
}


// ==== entry=008f8b6c name=FUN_008f8b6c size=1 ====

void FUN_008f8b6c(void)

{
  return;
}


// ==== entry=008f8b6e orig=FUN_008f8b6e size=24 name=PasswordMeter_metaObject ====

undefined ** PasswordMeter_metaObject(long param_1)

{
  undefined **ppuVar1;
  
  if (*(long *)(*(long *)(param_1 + 8) + 0x28) != 0) {
    ppuVar1 = (undefined **)QObjectData::dynamicMetaObject();
    return ppuVar1;
  }
  return &PTR_staticMetaObject_0119b120;
}


// ==== entry=008f8b86 orig=FUN_008f8b86 size=66 name=PasswordMeter_qt_metacast ====

char * PasswordMeter_qt_metacast(char *param_1,char *param_2)

{
  int iVar1;
  char *pcVar2;
  
  if (param_2 == (char *)0x0) {
    return (char *)0x0;
  }
  iVar1 = strcmp(param_2,"PasswordMeter");
  if (iVar1 == 0) {
    return param_1;
  }
  pcVar2 = (char *)QProgressBar::qt_metacast(param_1);
  return pcVar2;
}


// ==== entry=008f8bc8 orig=FUN_008f8bc8 size=5 name=PasswordMeter_qt_metacall ====

void QProgressBar::PasswordMeter_qt_metacall(void)

{
  qt_metacall();
  return;
}


// ==== entry=008f8bce orig=FUN_008f8bce size=29 name=PasswordMeter_dtor ====

void PasswordMeter_dtor(QProgressBar *param_1)

{
  *(undefined ***)param_1 = &PasswordMeter_vtable;
  *(undefined ***)(param_1 + 0x10) = &PTR_FUN_0119b0d0;
  QProgressBar::~QProgressBar(param_1);
  return;
}


// ==== entry=008f8beb name=FUN_008f8beb size=33 ====

void FUN_008f8beb(undefined8 *param_1)

{
  param_1[-2] = &PasswordMeter_vtable;
  *param_1 = &PTR_FUN_0119b0d0;
  QProgressBar::~QProgressBar((QProgressBar *)(param_1 + -2));
  return;
}


// ==== entry=008f8c0c orig=FUN_008f8c0c size=47 name=PasswordMeter_dtor_deleting ====

void PasswordMeter_dtor_deleting(QProgressBar *param_1)

{
  *(undefined ***)param_1 = &PasswordMeter_vtable;
  *(undefined ***)(param_1 + 0x10) = &PTR_FUN_0119b0d0;
  QProgressBar::~QProgressBar(param_1);
  operator_delete(param_1,0x30);
  return;
}


// ==== entry=008f8c3b name=FUN_008f8c3b size=51 ====

void FUN_008f8c3b(undefined8 *param_1)

{
  param_1[-2] = &PasswordMeter_vtable;
  *param_1 = &PTR_FUN_0119b0d0;
  QProgressBar::~QProgressBar((QProgressBar *)(param_1 + -2));
  operator_delete((QProgressBar *)(param_1 + -2),0x30);
  return;
}


// ==== entry=008f8c6e name=FUN_008f8c6e size=1 ====

void FUN_008f8c6e(void)

{
  return;
}


// ==== entry=008f8c70 orig=FUN_008f8c70 size=24 name=PopupWidget_metaObject ====

undefined ** PopupWidget_metaObject(long param_1)

{
  undefined **ppuVar1;
  
  if (*(long *)(*(long *)(param_1 + 8) + 0x28) != 0) {
    ppuVar1 = (undefined **)QObjectData::dynamicMetaObject();
    return ppuVar1;
  }
  return &PTR_staticMetaObject_0119b380;
}


// ==== entry=008f8c88 orig=FUN_008f8c88 size=66 name=PopupWidget_qt_metacast ====

char * PopupWidget_qt_metacast(char *param_1,char *param_2)

{
  int iVar1;
  char *pcVar2;
  
  if (param_2 == (char *)0x0) {
    return (char *)0x0;
  }
  iVar1 = strcmp(param_2,"PopupWidget");
  if (iVar1 == 0) {
    return param_1;
  }
  pcVar2 = (char *)QFrame::qt_metacast(param_1);
  return pcVar2;
}


// ==== entry=008f8cca orig=FUN_008f8cca size=5 name=PopupWidget_qt_metacall ====

void QFrame::PopupWidget_qt_metacall(void)

{
  qt_metacall();
  return;
}


// ==== entry=008f8cd0 orig=FUN_008f8cd0 size=24 name=ListView_metaObject ====

undefined ** ListView_metaObject(long param_1)

{
  undefined **ppuVar1;
  
  if (*(long *)(*(long *)(param_1 + 8) + 0x28) != 0) {
    ppuVar1 = (undefined **)QObjectData::dynamicMetaObject();
    return ppuVar1;
  }
  return &PTR_staticMetaObject_0119b720;
}


// ==== entry=008f8ce8 name=FUN_008f8ce8 size=16 ====

void FUN_008f8ce8(QObject *param_1)

{
  QMetaObject::activate(param_1,(QMetaObject *)&PTR_staticMetaObject_0119b720,0,(void **)0x0);
  return;
}


// ==== entry=008f8cf8 name=FUN_008f8cf8 size=54 ====

void FUN_008f8cf8(QObject *param_1,undefined4 param_2)

{
  undefined4 local_1c;
  void *local_18;
  undefined4 *local_10;
  
  local_18 = (void *)0x0;
  local_10 = &local_1c;
  local_1c = param_2;
  QMetaObject::activate(param_1,(QMetaObject *)&PTR_staticMetaObject_0119b720,1,&local_18);
  return;
}


// ==== entry=008f8d2e name=FUN_008f8d2e size=150 ====

void FUN_008f8d2e(undefined8 param_1,int param_2,int param_3,undefined8 *param_4)

{
  long *plVar1;
  undefined1 *puVar2;
  undefined1 uVar3;
  
  if (param_2 == 0) {
    if (param_3 == 1) {
      FUN_008f8cf8(param_1,*(undefined4 *)param_4[1]);
      return;
    }
    if (param_3 == 2) {
      FUN_00583e8e();
      return;
    }
    if (param_3 == 0) {
      FUN_008f8ce8();
      return;
    }
  }
  else if (param_2 == 10) {
    plVar1 = (long *)param_4[1];
    if (((code *)*plVar1 == FUN_008f8ce8) && (plVar1[1] == 0)) {
      *(undefined4 *)*param_4 = 0;
      return;
    }
    if (((code *)*plVar1 == FUN_008f8cf8) && (plVar1[1] == 0)) {
      *(undefined4 *)*param_4 = 1;
      return;
    }
  }
  else if (param_2 == 1) {
    if (param_3 == 0) {
      puVar2 = (undefined1 *)*param_4;
      uVar3 = FUN_00583abe();
      *puVar2 = uVar3;
      return;
    }
  }
  else if ((param_2 == 2) && (param_3 == 0)) {
    FUN_00583736(param_1,*(undefined1 *)*param_4);
    return;
  }
  return;
}


// ==== entry=008f8dc4 orig=FUN_008f8dc4 size=66 name=ListView_qt_metacast ====

char * ListView_qt_metacast(char *param_1,char *param_2)

{
  int iVar1;
  char *pcVar2;
  
  if (param_2 == (char *)0x0) {
    return (char *)0x0;
  }
  iVar1 = strcmp(param_2,"ListView");
  if (iVar1 == 0) {
    return param_1;
  }
  pcVar2 = (char *)QListView::qt_metacast(param_1);
  return pcVar2;
}


// ==== entry=008f8e06 orig=FUN_008f8e06 size=177 name=ListView_qt_metacall ====

ulong ListView_qt_metacall(undefined8 param_1,int param_2,undefined8 param_3,undefined8 *param_4)

{
  int iVar1;
  ulong uVar2;
  
  uVar2 = QListView::qt_metacall();
  iVar1 = (int)uVar2;
  if (-1 < iVar1) {
    if (param_2 == 0) {
      if (iVar1 < 3) {
        FUN_008f8d2e(param_1,0,uVar2 & 0xffffffff,param_4);
        uVar2 = uVar2 & 0xffffffff;
      }
    }
    else {
      if (param_2 != 0xc) {
        if ((param_2 - 1U < 3) || (param_2 == 0xb)) {
          FUN_008f8d2e(param_1,param_2,uVar2 & 0xffffffff,param_4);
          return (ulong)(iVar1 - 1);
        }
        if ((((param_2 != 4) && (param_2 != 5)) && (param_2 != 6)) &&
           ((param_2 != 7 && (param_2 != 8)))) {
          return uVar2;
        }
        return (ulong)(iVar1 - 1);
      }
      if (iVar1 < 3) {
        *(undefined4 *)*param_4 = 0xffffffff;
      }
    }
    uVar2 = (ulong)((int)uVar2 - 3);
  }
  return uVar2;
}


// ==== entry=008f8eb8 name=FUN_008f8eb8 size=1 ====

void FUN_008f8eb8(void)

{
  return;
}


// ==== entry=008f8eba orig=FUN_008f8eba size=24 name=ListItemDelegate_metaObject ====

undefined ** ListItemDelegate_metaObject(long param_1)

{
  undefined **ppuVar1;
  
  if (*(long *)(*(long *)(param_1 + 8) + 0x28) != 0) {
    ppuVar1 = (undefined **)QObjectData::dynamicMetaObject();
    return ppuVar1;
  }
  return &PTR_PTR_0119b840;
}


// ==== entry=008f8ed2 orig=FUN_008f8ed2 size=66 name=ListItemDelegate_qt_metacast ====

undefined8 ListItemDelegate_qt_metacast(undefined8 param_1,char *param_2)

{
  int iVar1;
  undefined8 uVar2;
  
  if (param_2 == (char *)0x0) {
    return 0;
  }
  iVar1 = strcmp(param_2,"ListItemDelegate");
  if (iVar1 == 0) {
    return param_1;
  }
  uVar2 = s_EditDelegate_8f993c(param_1,param_2);
  return uVar2;
}


// ==== entry=008f8f14 orig=FUN_008f8f14 size=5 name=ListItemDelegate_qt_metacall ====

ulong ListItemDelegate_qt_metacall
                (undefined8 param_1,int param_2,undefined8 param_3,undefined8 *param_4)

{
  int iVar1;
  ulong uVar2;
  
  uVar2 = QStyledItemDelegate::qt_metacall();
  iVar1 = (int)uVar2;
  if (-1 < iVar1) {
    if (param_2 == 0) {
      if (iVar1 == 0) {
        FUN_008f98b8(param_1,*(undefined8 *)param_4[1],param_4[2],param_4[3]);
        uVar2 = uVar2 & 0xffffffff;
      }
    }
    else {
      if (param_2 != 0xc) {
        return uVar2;
      }
      if (iVar1 == 0) {
        *(undefined4 *)*param_4 = 0xffffffff;
      }
    }
    uVar2 = (ulong)((int)uVar2 - 1);
  }
  return uVar2;
}


// ==== entry=008f8f1a orig=FUN_008f8f1a size=98 name=ListItemDelegate_dtor ====

void ListItemDelegate_dtor(QStyledItemDelegate *param_1)

{
  int *piVar1;
  QArrayData *pQVar2;
  
  *(undefined ***)param_1 = &PTR_FUN_0119c0d8;
  pQVar2 = *(QArrayData **)(param_1 + 0x38);
  if (*(int *)pQVar2 != 0) {
    if (*(int *)pQVar2 == -1) goto LAB_008f8f41;
    LOCK();
    *(int *)pQVar2 = *(int *)pQVar2 + -1;
    UNLOCK();
    if (*(int *)pQVar2 != 0) goto LAB_008f8f41;
    pQVar2 = *(QArrayData **)(param_1 + 0x38);
  }
  QArrayData::deallocate(pQVar2,2,8);
LAB_008f8f41:
  piVar1 = *(int **)(param_1 + 0x10);
  if (piVar1 != (int *)0x0) {
    LOCK();
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if ((*piVar1 == 0) && (*(void **)(param_1 + 0x10) != (void *)0x0)) {
      operator_delete(*(void **)(param_1 + 0x10));
    }
  }
  QStyledItemDelegate::~QStyledItemDelegate(param_1);
  return;
}


// ==== entry=008f8f7c orig=FUN_008f8f7c size=111 name=ListItemDelegate_dtor_deleting ====

void ListItemDelegate_dtor_deleting(QStyledItemDelegate *param_1)

{
  int *piVar1;
  QArrayData *pQVar2;
  
  *(undefined ***)param_1 = &PTR_FUN_0119c0d8;
  pQVar2 = *(QArrayData **)(param_1 + 0x38);
  if (*(int *)pQVar2 != 0) {
    if (*(int *)pQVar2 == -1) goto LAB_008f8fa3;
    LOCK();
    *(int *)pQVar2 = *(int *)pQVar2 + -1;
    UNLOCK();
    if (*(int *)pQVar2 != 0) goto LAB_008f8fa3;
    pQVar2 = *(QArrayData **)(param_1 + 0x38);
  }
  QArrayData::deallocate(pQVar2,2,8);
LAB_008f8fa3:
  piVar1 = *(int **)(param_1 + 0x10);
  if (piVar1 != (int *)0x0) {
    LOCK();
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if ((*piVar1 == 0) && (*(void **)(param_1 + 0x10) != (void *)0x0)) {
      operator_delete(*(void **)(param_1 + 0x10));
    }
  }
  QStyledItemDelegate::~QStyledItemDelegate(param_1);
  operator_delete(param_1,0x98);
  return;
}


// ==== entry=008f8ff0 orig=FUN_008f8ff0 size=24 name=Completer_metaObject ====

undefined ** Completer_metaObject(long param_1)

{
  undefined **ppuVar1;
  
  if (*(long *)(*(long *)(param_1 + 8) + 0x28) != 0) {
    ppuVar1 = (undefined **)QObjectData::dynamicMetaObject();
    return ppuVar1;
  }
  return &PTR_staticMetaObject_0119baa0;
}


// ==== entry=008f9008 name=FUN_008f9008 size=39 ====

void FUN_008f9008(QObject *param_1,undefined8 param_2)

{
  void *local_18;
  undefined8 local_10;
  
  local_18 = (void *)0x0;
  local_10 = param_2;
  QMetaObject::activate(param_1,(QMetaObject *)&PTR_staticMetaObject_0119baa0,0,&local_18);
  return;
}


// ==== entry=008f9030 name=FUN_008f9030 size=47 ====

void FUN_008f9030(QObject *param_1,undefined8 param_2,undefined8 param_3)

{
  void *local_28;
  undefined8 local_20;
  undefined8 local_18;
  
  local_28 = (void *)0x0;
  local_20 = param_2;
  local_18 = param_3;
  QMetaObject::activate(param_1,(QMetaObject *)&PTR_staticMetaObject_0119baa0,1,&local_28);
  return;
}


// ==== entry=008f9060 name=FUN_008f9060 size=42 ====

void FUN_008f9060(QObject *param_1,undefined8 param_2)

{
  void *local_18;
  undefined8 local_10;
  
  local_18 = (void *)0x0;
  local_10 = param_2;
  QMetaObject::activate(param_1,(QMetaObject *)&PTR_staticMetaObject_0119baa0,2,&local_18);
  return;
}


// ==== entry=008f908a name=FUN_008f908a size=138 ====

void FUN_008f908a(undefined8 param_1,int param_2,int param_3,undefined8 *param_4)

{
  undefined4 *puVar1;
  long *plVar2;
  code *pcVar3;
  
  if (param_2 == 0) {
    if (param_3 == 1) {
      FUN_008f9030(param_1,param_4[1],param_4[2]);
      return;
    }
    if (param_3 == 2) {
      FUN_008f9060(param_1,param_4[1]);
      return;
    }
    if (param_3 == 0) {
      FUN_008f9008(param_1,param_4[1]);
      return;
    }
  }
  else if (param_2 == 10) {
    puVar1 = (undefined4 *)*param_4;
    plVar2 = (long *)param_4[1];
    pcVar3 = (code *)*plVar2;
    if ((pcVar3 == FUN_008f9008) && (plVar2[1] == 0)) {
      *puVar1 = 0;
      return;
    }
    if ((pcVar3 == FUN_008f9030) && (plVar2[1] == 0)) {
      *puVar1 = 1;
      return;
    }
    if ((pcVar3 == FUN_008f9060) && (plVar2[1] == 0)) {
      *puVar1 = 2;
      return;
    }
  }
  return;
}


// ==== entry=008f9114 orig=FUN_008f9114 size=66 name=Completer_qt_metacast ====

char * Completer_qt_metacast(char *param_1,char *param_2)

{
  int iVar1;
  char *pcVar2;
  
  if (param_2 == (char *)0x0) {
    return (char *)0x0;
  }
  iVar1 = strcmp(param_2,"Completer");
  if (iVar1 == 0) {
    return param_1;
  }
  pcVar2 = (char *)QWidget::qt_metacast(param_1);
  return pcVar2;
}


// ==== entry=008f9156 orig=FUN_008f9156 size=93 name=Completer_qt_metacall ====

ulong Completer_qt_metacall(undefined8 param_1,int param_2,undefined8 param_3,undefined8 *param_4)

{
  int iVar1;
  ulong uVar2;
  
  uVar2 = QWidget::qt_metacall();
  iVar1 = (int)uVar2;
  if (-1 < iVar1) {
    if (param_2 == 0) {
      if (iVar1 < 3) {
        FUN_008f908a(param_1,0,uVar2 & 0xffffffff,param_4);
        uVar2 = uVar2 & 0xffffffff;
      }
    }
    else {
      if (param_2 != 0xc) {
        return uVar2;
      }
      if (iVar1 < 3) {
        *(undefined4 *)*param_4 = 0xffffffff;
      }
    }
    uVar2 = (ulong)((int)uVar2 - 3);
  }
  return uVar2;
}


// ==== entry=008f91b4 orig=FUN_008f91b4 size=29 name=Completer_dtor ====

void Completer_dtor(QWidget *param_1)

{
  *(undefined ***)param_1 = &Completer_vtable;
  *(undefined ***)(param_1 + 0x10) = &PTR_FUN_0119ba48;
  QWidget::~QWidget(param_1);
  return;
}


// ==== entry=008f91d1 name=FUN_008f91d1 size=33 ====

void FUN_008f91d1(undefined8 *param_1)

{
  param_1[-2] = &Completer_vtable;
  *param_1 = &PTR_FUN_0119ba48;
  QWidget::~QWidget((QWidget *)(param_1 + -2));
  return;
}


// ==== entry=008f91f2 orig=FUN_008f91f2 size=47 name=Completer_dtor_deleting ====

void Completer_dtor_deleting(QWidget *param_1)

{
  *(undefined ***)param_1 = &Completer_vtable;
  *(undefined ***)(param_1 + 0x10) = &PTR_FUN_0119ba48;
  QWidget::~QWidget(param_1);
  operator_delete(param_1,0x40);
  return;
}


// ==== entry=008f9221 name=FUN_008f9221 size=51 ====

void FUN_008f9221(undefined8 *param_1)

{
  param_1[-2] = &Completer_vtable;
  *param_1 = &PTR_FUN_0119ba48;
  QWidget::~QWidget((QWidget *)(param_1 + -2));
  operator_delete((QWidget *)(param_1 + -2),0x40);
  return;
}


// ==== entry=008f9260 orig=FUN_008f9260 size=24 name=FilterEdit_metaObject ====

undefined ** FilterEdit_metaObject(long param_1)

{
  undefined **ppuVar1;
  
  if (*(long *)(*(long *)(param_1 + 8) + 0x28) != 0) {
    ppuVar1 = (undefined **)QObjectData::dynamicMetaObject();
    return ppuVar1;
  }
  return &PTR_PTR_0119bd00;
}


// ==== entry=008f9278 orig=FUN_008f9278 size=66 name=FilterEdit_qt_metacast ====

undefined8 FilterEdit_qt_metacast(undefined8 param_1,char *param_2)

{
  int iVar1;
  undefined8 uVar2;
  
  if (param_2 == (char *)0x0) {
    return 0;
  }
  iVar1 = strcmp(param_2,"FilterEdit");
  if (iVar1 == 0) {
    return param_1;
  }
  uVar2 = s_LineEdit_8f6e2e(param_1,param_2);
  return uVar2;
}


// ==== entry=008f92ba name=FUN_008f92ba size=39 ====

void FUN_008f92ba(QObject *param_1,undefined8 param_2)

{
  void *local_18;
  undefined8 local_10;
  
  local_18 = (void *)0x0;
  local_10 = param_2;
  QMetaObject::activate(param_1,(QMetaObject *)&PTR_PTR_0119bd00,0,&local_18);
  return;
}


// ==== entry=008f92e2 name=FUN_008f92e2 size=69 ====

void FUN_008f92e2(QObject *param_1,undefined1 param_2,undefined4 param_3)

{
  undefined4 local_30;
  undefined1 local_2c [4];
  void *local_28;
  undefined1 *local_20;
  undefined4 *local_18;
  
  local_28 = (void *)0x0;
  local_20 = local_2c;
  local_18 = &local_30;
  local_30 = param_3;
  local_2c[0] = param_2;
  QMetaObject::activate(param_1,(QMetaObject *)&PTR_PTR_0119bd00,1,&local_28);
  return;
}


// ==== entry=008f9328 name=FUN_008f9328 size=106 ====

void FUN_008f9328(undefined8 param_1,int param_2,int param_3,undefined8 *param_4)

{
  long *plVar1;
  
  if (param_2 == 0) {
    if (param_3 == 0) {
      FUN_008f92ba(param_1,param_4[1]);
      return;
    }
    if (param_3 == 1) {
      FUN_008f92e2(param_1,*(undefined1 *)param_4[1],*(undefined4 *)param_4[2]);
      return;
    }
    return;
  }
  if (param_2 == 10) {
    plVar1 = (long *)param_4[1];
    if (((code *)*plVar1 == FUN_008f92ba) && (plVar1[1] == 0)) {
      *(undefined4 *)*param_4 = 0;
      return;
    }
    if (((code *)*plVar1 == FUN_008f92e2) && (plVar1[1] == 0)) {
      *(undefined4 *)*param_4 = 1;
      return;
    }
  }
  return;
}


// ==== entry=008f9392 orig=FUN_008f9392 size=93 name=FilterEdit_qt_metacall ====

ulong FilterEdit_qt_metacall(undefined8 param_1,int param_2,undefined8 param_3,undefined8 *param_4)

{
  int iVar1;
  ulong uVar2;
  
  uVar2 = FUN_008f6e70();
  iVar1 = (int)uVar2;
  if (-1 < iVar1) {
    if (param_2 == 0) {
      if (iVar1 < 2) {
        FUN_008f9328(param_1,0,uVar2 & 0xffffffff,param_4);
        uVar2 = uVar2 & 0xffffffff;
      }
    }
    else {
      if (param_2 != 0xc) {
        return uVar2;
      }
      if (iVar1 < 2) {
        *(undefined4 *)*param_4 = 0xffffffff;
      }
    }
    uVar2 = (ulong)((int)uVar2 - 2);
  }
  return uVar2;
}


// ==== entry=008f93f0 name=FUN_008f93f0 size=102 ====

void FUN_008f93f0(undefined8 *param_1)

{
  int *piVar1;
  
  param_1[-2] = &PTR_FUN_01198458;
  *param_1 = &PTR_FUN_01198608;
  FUN_00544670(param_1 + 8);
  piVar1 = (int *)param_1[4];
  if (piVar1 != (int *)0x0) {
    LOCK();
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if ((*piVar1 == 0) && ((void *)param_1[4] != (void *)0x0)) {
      operator_delete((void *)param_1[4]);
    }
  }
  QLineEdit::~QLineEdit((QLineEdit *)(param_1 + -2));
  operator_delete((QLineEdit *)(param_1 + -2),0x80);
  return;
}


// ==== entry=008f9456 orig=FUN_008f9456 size=88 name=FilterEdit_dtor_deleting ====

void FilterEdit_dtor_deleting(QLineEdit *param_1)

{
  int *piVar1;
  
  *(undefined ***)param_1 = &PTR_FUN_01198458;
  *(undefined ***)(param_1 + 0x10) = &PTR_FUN_01198608;
  FUN_00544670(param_1 + 0x50);
  piVar1 = *(int **)(param_1 + 0x30);
  if (piVar1 != (int *)0x0) {
    LOCK();
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if ((*piVar1 == 0) && (*(void **)(param_1 + 0x30) != (void *)0x0)) {
      operator_delete(*(void **)(param_1 + 0x30));
    }
  }
  QLineEdit::~QLineEdit(param_1);
  operator_delete(param_1,0x80);
  return;
}


// ==== entry=008f94ae name=FUN_008f94ae size=89 ====

void FUN_008f94ae(undefined8 *param_1)

{
  int *piVar1;
  
  param_1[-2] = &PTR_FUN_01198458;
  *param_1 = &PTR_FUN_01198608;
  FUN_00544670(param_1 + 8);
  piVar1 = (int *)param_1[4];
  if (piVar1 != (int *)0x0) {
    LOCK();
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if ((*piVar1 == 0) && ((void *)param_1[4] != (void *)0x0)) {
      operator_delete((void *)param_1[4]);
    }
  }
  QLineEdit::~QLineEdit((QLineEdit *)(param_1 + -2));
  return;
}


// ==== entry=008f9508 orig=FUN_008f9508 size=75 name=FilterEdit_dtor ====

void FilterEdit_dtor(QLineEdit *param_1)

{
  int *piVar1;
  
  *(undefined ***)param_1 = &PTR_FUN_01198458;
  *(undefined ***)(param_1 + 0x10) = &PTR_FUN_01198608;
  FUN_00544670(param_1 + 0x50);
  piVar1 = *(int **)(param_1 + 0x30);
  if (piVar1 != (int *)0x0) {
    LOCK();
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if ((*piVar1 == 0) && (*(void **)(param_1 + 0x30) != (void *)0x0)) {
      operator_delete(*(void **)(param_1 + 0x30));
    }
  }
  QLineEdit::~QLineEdit(param_1);
  return;
}


// ==== entry=008f9560 name=FUN_008f9560 size=24 ====

undefined ** FUN_008f9560(long param_1)

{
  undefined **ppuVar1;
  
  if (*(long *)(*(long *)(param_1 + 8) + 0x28) != 0) {
    ppuVar1 = (undefined **)QObjectData::dynamicMetaObject();
    return ppuVar1;
  }
  return &PTR_staticMetaObject_0119bf60;
}


// ==== entry=008f9578 name=FUN_008f9578 size=16 ====

void FUN_008f9578(QObject *param_1)

{
  QMetaObject::activate(param_1,(QMetaObject *)&PTR_staticMetaObject_0119bf60,0,(void **)0x0);
  return;
}


// ==== entry=008f9588 name=FUN_008f9588 size=55 ====

void FUN_008f9588(QObject *param_1,undefined8 param_2)

{
  undefined8 local_20;
  void *local_18;
  undefined8 *local_10;
  
  local_18 = (void *)0x0;
  local_10 = &local_20;
  local_20 = param_2;
  QMetaObject::activate(param_1,(QMetaObject *)&PTR_staticMetaObject_0119bf60,1,&local_18);
  return;
}


// ==== entry=008f95c0 name=FUN_008f95c0 size=94 ====

void FUN_008f95c0(undefined8 param_1,int param_2,int param_3,undefined8 *param_4)

{
  long *plVar1;
  
  if (param_2 == 0) {
    if (param_3 == 0) {
      FUN_008f9578();
      return;
    }
    if (param_3 == 1) {
      FUN_008f9588(param_1,*(undefined8 *)param_4[1]);
      return;
    }
    return;
  }
  if (param_2 == 10) {
    plVar1 = (long *)param_4[1];
    if (((code *)*plVar1 == FUN_008f9578) && (plVar1[1] == 0)) {
      *(undefined4 *)*param_4 = 0;
      return;
    }
    if (((code *)*plVar1 == FUN_008f9588) && (plVar1[1] == 0)) {
      *(undefined4 *)*param_4 = 1;
      return;
    }
  }
  return;
}


// ==== entry=008f961e name=FUN_008f961e size=66 ====

char * FUN_008f961e(char *param_1,char *param_2)

{
  int iVar1;
  char *pcVar2;
  
  if (param_2 == (char *)0x0) {
    return (char *)0x0;
  }
  iVar1 = strcmp(param_2,"ComboBox");
  if (iVar1 == 0) {
    return param_1;
  }
  pcVar2 = (char *)QComboBox::qt_metacast(param_1);
  return pcVar2;
}


// ==== entry=008f9660 name=FUN_008f9660 size=93 ====

ulong FUN_008f9660(undefined8 param_1,int param_2,undefined8 param_3,undefined8 *param_4)

{
  int iVar1;
  ulong uVar2;
  
  uVar2 = QComboBox::qt_metacall();
  iVar1 = (int)uVar2;
  if (-1 < iVar1) {
    if (param_2 == 0) {
      if (iVar1 < 2) {
        FUN_008f95c0(param_1,0,uVar2 & 0xffffffff,param_4);
        uVar2 = uVar2 & 0xffffffff;
      }
    }
    else {
      if (param_2 != 0xc) {
        return uVar2;
      }
      if (iVar1 < 2) {
        *(undefined4 *)*param_4 = 0xffffffff;
      }
    }
    uVar2 = (ulong)((int)uVar2 - 2);
  }
  return uVar2;
}


// ==== entry=008f96be name=FUN_008f96be size=79 ====

void FUN_008f96be(QComboBox *param_1)

{
  int *piVar1;
  
  *(undefined ***)param_1 = &PTR_FUN_0119bd58;
  *(undefined ***)(param_1 + 0x10) = &PTR_FUN_0119bf18;
  piVar1 = *(int **)(param_1 + 0x30);
  if (piVar1 != (int *)0x0) {
    LOCK();
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if ((*piVar1 == 0) && (*(void **)(param_1 + 0x30) != (void *)0x0)) {
      operator_delete(*(void **)(param_1 + 0x30));
    }
  }
  QComboBox::~QComboBox(param_1);
  operator_delete(param_1,0x48);
  return;
}


// ==== entry=008f970d name=FUN_008f970d size=80 ====

void FUN_008f970d(undefined8 *param_1)

{
  int *piVar1;
  
  param_1[-2] = &PTR_FUN_0119bd58;
  *param_1 = &PTR_FUN_0119bf18;
  piVar1 = (int *)param_1[4];
  if (piVar1 != (int *)0x0) {
    LOCK();
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if ((*piVar1 == 0) && ((void *)param_1[4] != (void *)0x0)) {
      operator_delete((void *)param_1[4]);
    }
  }
  QComboBox::~QComboBox((QComboBox *)(param_1 + -2));
  operator_delete((QComboBox *)(param_1 + -2),0x48);
  return;
}


// ==== entry=008f975e name=FUN_008f975e size=67 ====

void FUN_008f975e(undefined8 *param_1)

{
  int *piVar1;
  
  param_1[-2] = &PTR_FUN_0119bd58;
  *param_1 = &PTR_FUN_0119bf18;
  piVar1 = (int *)param_1[4];
  if (piVar1 != (int *)0x0) {
    LOCK();
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if ((*piVar1 == 0) && ((void *)param_1[4] != (void *)0x0)) {
      operator_delete((void *)param_1[4]);
    }
  }
  QComboBox::~QComboBox((QComboBox *)(param_1 + -2));
  return;
}


// ==== entry=008f97a2 name=FUN_008f97a2 size=66 ====

void FUN_008f97a2(QComboBox *param_1)

{
  int *piVar1;
  
  *(undefined ***)param_1 = &PTR_FUN_0119bd58;
  *(undefined ***)(param_1 + 0x10) = &PTR_FUN_0119bf18;
  piVar1 = *(int **)(param_1 + 0x30);
  if (piVar1 != (int *)0x0) {
    LOCK();
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if ((*piVar1 == 0) && (*(void **)(param_1 + 0x30) != (void *)0x0)) {
      operator_delete(*(void **)(param_1 + 0x30));
    }
  }
  QComboBox::~QComboBox(param_1);
  return;
}


// ==== entry=008f97e4 name=FUN_008f97e4 size=1 ====

void FUN_008f97e4(void)

{
  return;
}


// ==== entry=008f97e6 orig=FUN_008f97e6 size=24 name=TransferDelegate_metaObject ====

undefined ** TransferDelegate_metaObject(long param_1)

{
  undefined **ppuVar1;
  
  if (*(long *)(*(long *)(param_1 + 8) + 0x28) != 0) {
    ppuVar1 = (undefined **)QObjectData::dynamicMetaObject();
    return ppuVar1;
  }
  return &PTR_staticMetaObject_0119c080;
}


// ==== entry=008f97fe orig=FUN_008f97fe size=66 name=TransferDelegate_qt_metacast ====

char * TransferDelegate_qt_metacast(char *param_1,char *param_2)

{
  int iVar1;
  char *pcVar2;
  
  if (param_2 == (char *)0x0) {
    return (char *)0x0;
  }
  iVar1 = strcmp(param_2,"TransferDelegate");
  if (iVar1 == 0) {
    return param_1;
  }
  pcVar2 = (char *)QStyledItemDelegate::qt_metacast(param_1);
  return pcVar2;
}


// ==== entry=008f9840 orig=FUN_008f9840 size=5 name=TransferDelegate_qt_metacall ====

void QStyledItemDelegate::TransferDelegate_qt_metacall(void)

{
  qt_metacall();
  return;
}


// ==== entry=008f9846 orig=FUN_008f9846 size=36 name=TransferDelegate_dtor ====

void TransferDelegate_dtor(QStyledItemDelegate *param_1)

{
  *(undefined ***)param_1 = &TransferDelegate_vtable;
  QIcon::~QIcon((QIcon *)(param_1 + 0x10));
  QStyledItemDelegate::~QStyledItemDelegate(param_1);
  return;
}


// ==== entry=008f986a orig=FUN_008f986a size=49 name=TransferDelegate_dtor_deleting ====

void TransferDelegate_dtor_deleting(QStyledItemDelegate *param_1)

{
  *(undefined ***)param_1 = &TransferDelegate_vtable;
  QIcon::~QIcon((QIcon *)(param_1 + 0x10));
  QStyledItemDelegate::~QStyledItemDelegate(param_1);
  operator_delete(param_1,0x40);
  return;
}


// ==== entry=008f98a0 name=FUN_008f98a0 size=24 ====

undefined ** FUN_008f98a0(long param_1)

{
  undefined **ppuVar1;
  
  if (*(long *)(*(long *)(param_1 + 8) + 0x28) != 0) {
    ppuVar1 = (undefined **)QObjectData::dynamicMetaObject();
    return ppuVar1;
  }
  return &PTR_staticMetaObject_0119c1a0;
}


// ==== entry=008f98b8 name=FUN_008f98b8 size=62 ====

void FUN_008f98b8(QObject *param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 local_30;
  void *local_28;
  undefined8 *local_20;
  undefined8 local_18;
  undefined8 local_10;
  
  local_28 = (void *)0x0;
  local_20 = &local_30;
  local_30 = param_2;
  local_18 = param_3;
  local_10 = param_4;
  QMetaObject::activate(param_1,(QMetaObject *)&PTR_staticMetaObject_0119c1a0,0,&local_28);
  return;
}


// ==== entry=008f98f6 name=FUN_008f98f6 size=70 ====

void FUN_008f98f6(undefined8 param_1,int param_2,int param_3,undefined8 *param_4)

{
  if (param_2 == 0) {
    if (param_3 == 0) {
      FUN_008f98b8(param_1,*(undefined8 *)param_4[1],param_4[2],param_4[3]);
      return;
    }
  }
  else if (((param_2 == 10) && (*(code **)param_4[1] == FUN_008f98b8)) &&
          (((long *)param_4[1])[1] == 0)) {
    *(undefined4 *)*param_4 = 0;
    return;
  }
  return;
}


// ==== entry=008f993c orig=FUN_008f993c size=66 name=s_EditDelegate_8f993c ====

char * s_EditDelegate_8f993c(char *param_1,char *param_2)

{
  int iVar1;
  char *pcVar2;
  
  if (param_2 == (char *)0x0) {
    return (char *)0x0;
  }
  iVar1 = strcmp(param_2,"EditDelegate");
  if (iVar1 == 0) {
    return param_1;
  }
  pcVar2 = (char *)QStyledItemDelegate::qt_metacast(param_1);
  return pcVar2;
}


// ==== entry=008f997e name=FUN_008f997e size=102 ====

ulong FUN_008f997e(undefined8 param_1,int param_2,undefined8 param_3,undefined8 *param_4)

{
  int iVar1;
  ulong uVar2;
  
  uVar2 = QStyledItemDelegate::qt_metacall();
  iVar1 = (int)uVar2;
  if (-1 < iVar1) {
    if (param_2 == 0) {
      if (iVar1 == 0) {
        FUN_008f98b8(param_1,*(undefined8 *)param_4[1],param_4[2],param_4[3]);
        uVar2 = uVar2 & 0xffffffff;
      }
    }
    else {
      if (param_2 != 0xc) {
        return uVar2;
      }
      if (iVar1 == 0) {
        *(undefined4 *)*param_4 = 0xffffffff;
      }
    }
    uVar2 = (ulong)((int)uVar2 - 1);
  }
  return uVar2;
}


// ==== entry=008f99f0 orig=FUN_008f99f0 size=24 name=FileTree_metaObject ====

undefined ** FileTree_metaObject(long param_1)

{
  undefined **ppuVar1;
  
  if (*(long *)(*(long *)(param_1 + 8) + 0x28) != 0) {
    ppuVar1 = (undefined **)QObjectData::dynamicMetaObject();
    return ppuVar1;
  }
  return &PTR_PTR_0119c560;
}


// ==== entry=008f9a08 name=FUN_008f9a08 size=44 ====

void FUN_008f9a08(QObject *param_1,undefined8 param_2,undefined8 param_3)

{
  void *local_28;
  undefined8 local_20;
  undefined8 local_18;
  
  local_28 = (void *)0x0;
  local_20 = param_2;
  local_18 = param_3;
  QMetaObject::activate(param_1,(QMetaObject *)&PTR_PTR_0119c560,0,&local_28);
  return;
}


// ==== entry=008f9a34 name=FUN_008f9a34 size=60 ====

void FUN_008f9a34(undefined8 param_1,int param_2,int param_3,undefined8 *param_4)

{
  if (param_2 == 0) {
    if (param_3 == 0) {
      FUN_008f9a08(param_1,param_4[1],param_4[2]);
      return;
    }
  }
  else if (((param_2 == 10) && (*(code **)param_4[1] == FUN_008f9a08)) &&
          (((long *)param_4[1])[1] == 0)) {
    *(undefined4 *)*param_4 = 0;
    return;
  }
  return;
}


// ==== entry=008f9a70 orig=FUN_008f9a70 size=66 name=FileTree_qt_metacast ====

undefined8 FileTree_qt_metacast(undefined8 param_1,char *param_2)

{
  int iVar1;
  undefined8 uVar2;
  
  if (param_2 == (char *)0x0) {
    return 0;
  }
  iVar1 = strcmp(param_2,"FileTree");
  if (iVar1 == 0) {
    return param_1;
  }
  uVar2 = s_TreeView_8fb430(param_1,param_2);
  return uVar2;
}


// ==== entry=008f9ab2 orig=FUN_008f9ab2 size=92 name=FileTree_qt_metacall ====

ulong FileTree_qt_metacall(undefined8 param_1,int param_2,undefined8 param_3,undefined8 *param_4)

{
  int iVar1;
  ulong uVar2;
  
  uVar2 = FUN_008fb472();
  iVar1 = (int)uVar2;
  if (-1 < iVar1) {
    if (param_2 == 0) {
      if (iVar1 == 0) {
        FUN_008f9a08(param_1,param_4[1],param_4[2]);
        uVar2 = uVar2 & 0xffffffff;
      }
    }
    else {
      if (param_2 != 0xc) {
        return uVar2;
      }
      if (iVar1 == 0) {
        *(undefined4 *)*param_4 = 0xffffffff;
      }
    }
    uVar2 = (ulong)((int)uVar2 - 1);
  }
  return uVar2;
}


// ==== entry=008f9b0e orig=FUN_008f9b0e size=29 name=FileTree_dtor ====

void FileTree_dtor(undefined8 *param_1)

{
  *param_1 = &FileTree_vtable;
  param_1[2] = &PTR_FUN_0119c508;
  FUN_0058b7a8();
  return;
}


// ==== entry=008f9b2b name=FUN_008f9b2b size=33 ====

void FUN_008f9b2b(undefined8 *param_1)

{
  param_1[-2] = &FileTree_vtable;
  *param_1 = &PTR_FUN_0119c508;
  FUN_0058b7a8(param_1 + -2);
  return;
}


// ==== entry=008f9b4c orig=FUN_008f9b4c size=47 name=FileTree_dtor_deleting ====

void FileTree_dtor_deleting(undefined8 *param_1)

{
  *param_1 = &FileTree_vtable;
  param_1[2] = &PTR_FUN_0119c508;
  FUN_0058b7a8();
  operator_delete(param_1,0x78);
  return;
}


// ==== entry=008f9b7b name=FUN_008f9b7b size=51 ====

void FUN_008f9b7b(undefined8 *param_1)

{
  param_1[-2] = &FileTree_vtable;
  *param_1 = &PTR_FUN_0119c508;
  FUN_0058b7a8(param_1 + -2);
  operator_delete(param_1 + -2,0x78);
  return;
}


// ==== entry=008f9bb0 orig=FUN_008f9bb0 size=24 name=FileView_metaObject ====

undefined ** FileView_metaObject(long param_1)

{
  undefined **ppuVar1;
  
  if (*(long *)(*(long *)(param_1 + 8) + 0x28) != 0) {
    ppuVar1 = (undefined **)QObjectData::dynamicMetaObject();
    return ppuVar1;
  }
  return &PTR_staticMetaObject_0119c7c0;
}


// ==== entry=008f9bc8 name=FUN_008f9bc8 size=16 ====

void FUN_008f9bc8(QObject *param_1)

{
  QMetaObject::activate(param_1,(QMetaObject *)&PTR_staticMetaObject_0119c7c0,0,(void **)0x0);
  return;
}


// ==== entry=008f9bd8 name=FUN_008f9bd8 size=19 ====

void FUN_008f9bd8(QObject *param_1)

{
  QMetaObject::activate(param_1,(QMetaObject *)&PTR_staticMetaObject_0119c7c0,3,(void **)0x0);
  return;
}


// ==== entry=008f9bec name=FUN_008f9bec size=68 ====

void FUN_008f9bec(QObject *param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 local_30;
  undefined4 local_2c;
  void *local_28;
  undefined4 *local_20;
  undefined4 *local_18;
  
  local_28 = (void *)0x0;
  local_20 = &local_2c;
  local_18 = &local_30;
  local_30 = param_3;
  local_2c = param_2;
  QMetaObject::activate(param_1,(QMetaObject *)&PTR_staticMetaObject_0119c7c0,1,&local_28);
  return;
}


// ==== entry=008f9c30 name=FUN_008f9c30 size=55 ====

void FUN_008f9c30(QObject *param_1,undefined1 param_2)

{
  undefined1 local_1c [4];
  void *local_18;
  undefined1 *local_10;
  
  local_18 = (void *)0x0;
  local_10 = local_1c;
  local_1c[0] = param_2;
  QMetaObject::activate(param_1,(QMetaObject *)&PTR_staticMetaObject_0119c7c0,2,&local_18);
  return;
}


// ==== entry=008f9c68 name=FUN_008f9c68 size=183 ====

void FUN_008f9c68(undefined8 param_1,int param_2,int param_3,undefined8 *param_4)

{
  undefined4 *puVar1;
  long *plVar2;
  code *pcVar3;
  
  if (param_2 == 0) {
    if (param_3 == 1) {
      FUN_008f9bec(param_1,*(undefined4 *)param_4[1],*(undefined4 *)param_4[2]);
      return;
    }
    if (param_3 < 2) {
      if (param_3 == 0) {
        FUN_008f9bc8();
        return;
      }
      return;
    }
    if (param_3 == 2) {
      FUN_008f9c30(param_1,*(undefined1 *)param_4[1]);
      return;
    }
    if (param_3 == 3) {
      FUN_008f9bd8();
      return;
    }
    return;
  }
  if (param_2 == 10) {
    puVar1 = (undefined4 *)*param_4;
    plVar2 = (long *)param_4[1];
    pcVar3 = (code *)*plVar2;
    if ((pcVar3 == FUN_008f9bc8) && (plVar2[1] == 0)) {
      *puVar1 = 0;
      return;
    }
    if ((pcVar3 == FUN_008f9bec) && (plVar2[1] == 0)) {
      *puVar1 = 1;
      return;
    }
    if ((pcVar3 == FUN_008f9c30) && (plVar2[1] == 0)) {
      *puVar1 = 2;
      return;
    }
    if ((pcVar3 == FUN_008f9bd8) && (plVar2[1] == 0)) {
      *puVar1 = 3;
      return;
    }
  }
  return;
}


// ==== entry=008f9d20 orig=FUN_008f9d20 size=66 name=FileView_qt_metacast ====

char * FileView_qt_metacast(char *param_1,char *param_2)

{
  int iVar1;
  char *pcVar2;
  
  if (param_2 == (char *)0x0) {
    return (char *)0x0;
  }
  iVar1 = strcmp(param_2,"FileView");
  if (iVar1 == 0) {
    return param_1;
  }
  pcVar2 = (char *)QWidget::qt_metacast(param_1);
  return pcVar2;
}


// ==== entry=008f9d62 orig=FUN_008f9d62 size=93 name=FileView_qt_metacall ====

ulong FileView_qt_metacall(undefined8 param_1,int param_2,undefined8 param_3,undefined8 *param_4)

{
  int iVar1;
  ulong uVar2;
  
  uVar2 = QWidget::qt_metacall();
  iVar1 = (int)uVar2;
  if (-1 < iVar1) {
    if (param_2 == 0) {
      if (iVar1 < 4) {
        FUN_008f9c68(param_1,0,uVar2 & 0xffffffff,param_4);
        uVar2 = uVar2 & 0xffffffff;
      }
    }
    else {
      if (param_2 != 0xc) {
        return uVar2;
      }
      if (iVar1 < 4) {
        *(undefined4 *)*param_4 = 0xffffffff;
      }
    }
    uVar2 = (ulong)((int)uVar2 - 4);
  }
  return uVar2;
}


// ==== entry=008f9dc0 orig=FUN_008f9dc0 size=308 name=FileView_dtor ====

/* WARNING: Removing unreachable block (ram,0x008f9e85) */
/* WARNING: Removing unreachable block (ram,0x008f9ed4) */

void FileView_dtor(QWidget *param_1)

{
  long *plVar1;
  int iVar2;
  int *piVar3;
  long *plVar4;
  code *pcVar5;
  long lVar6;
  
  *(undefined ***)param_1 = &FileView_vtable;
  *(undefined ***)(param_1 + 0x10) = &PTR_FUN_0119c768;
  piVar3 = *(int **)(param_1 + 0xb0);
  if (piVar3 != (int *)0x0) {
    LOCK();
    *piVar3 = *piVar3 + -1;
    UNLOCK();
    if ((*piVar3 == 0) && (*(void **)(param_1 + 0xb0) != (void *)0x0)) {
      operator_delete(*(void **)(param_1 + 0xb0));
    }
  }
  piVar3 = *(int **)(param_1 + 0xa0);
  if (piVar3 != (int *)0x0) {
    LOCK();
    *piVar3 = *piVar3 + -1;
    UNLOCK();
    if ((*piVar3 == 0) && (*(void **)(param_1 + 0xa0) != (void *)0x0)) {
      operator_delete(*(void **)(param_1 + 0xa0));
    }
  }
  piVar3 = *(int **)(param_1 + 0x88);
  if (piVar3 != (int *)0x0) {
    LOCK();
    *piVar3 = *piVar3 + -1;
    UNLOCK();
    if ((*piVar3 == 0) && (*(void **)(param_1 + 0x88) != (void *)0x0)) {
      operator_delete(*(void **)(param_1 + 0x88));
    }
  }
  plVar4 = *(long **)(param_1 + 0x60);
  if (plVar4 != (long *)0x0) {
    LOCK();
    plVar1 = plVar4 + 1;
    lVar6 = *plVar1;
    *(int *)plVar1 = (int)*plVar1 + -1;
    UNLOCK();
    if ((int)lVar6 == 1) {
      if (*(code **)(*plVar4 + 0x10) != FUN_00575d12) {
        (**(code **)(*plVar4 + 0x10))(plVar4);
      }
      LOCK();
      piVar3 = (int *)((long)plVar4 + 0xc);
      iVar2 = *piVar3;
      *piVar3 = *piVar3 + -1;
      UNLOCK();
      if (iVar2 == 1) {
        pcVar5 = *(code **)(*plVar4 + 0x18);
        if (pcVar5 == std::_Sp_counted_base<(__gnu_cxx::_Lock_policy)2>::_M_destroy) {
          (**(code **)(*plVar4 + 8))();
        }
        else {
          (*pcVar5)(plVar4);
        }
      }
    }
  }
  QWidget::~QWidget(param_1);
  return;
}


// ==== entry=008f9ef4 name=FUN_008f9ef4 size=298 ====

/* WARNING: Removing unreachable block (ram,0x008f9fb4) */
/* WARNING: Removing unreachable block (ram,0x008fa00b) */

void FUN_008f9ef4(undefined8 *param_1)

{
  long *plVar1;
  int iVar2;
  int *piVar3;
  long *plVar4;
  code *pcVar5;
  long lVar6;
  
  param_1[-2] = &FileView_vtable;
  *param_1 = &PTR_FUN_0119c768;
  piVar3 = (int *)param_1[0x14];
  if (piVar3 != (int *)0x0) {
    LOCK();
    *piVar3 = *piVar3 + -1;
    UNLOCK();
    if ((*piVar3 == 0) && ((void *)param_1[0x14] != (void *)0x0)) {
      operator_delete((void *)param_1[0x14]);
    }
  }
  piVar3 = (int *)param_1[0x12];
  if (piVar3 != (int *)0x0) {
    LOCK();
    *piVar3 = *piVar3 + -1;
    UNLOCK();
    if ((*piVar3 == 0) && ((void *)param_1[0x12] != (void *)0x0)) {
      operator_delete((void *)param_1[0x12]);
    }
  }
  piVar3 = (int *)param_1[0xf];
  if (piVar3 != (int *)0x0) {
    LOCK();
    *piVar3 = *piVar3 + -1;
    UNLOCK();
    if ((*piVar3 == 0) && ((void *)param_1[0xf] != (void *)0x0)) {
      operator_delete((void *)param_1[0xf]);
    }
  }
  plVar4 = (long *)param_1[10];
  if (plVar4 != (long *)0x0) {
    LOCK();
    plVar1 = plVar4 + 1;
    lVar6 = *plVar1;
    *(int *)plVar1 = (int)*plVar1 + -1;
    UNLOCK();
    if ((int)lVar6 == 1) {
      if (*(code **)(*plVar4 + 0x10) != FUN_00575d12) {
        (**(code **)(*plVar4 + 0x10))(plVar4);
      }
      LOCK();
      piVar3 = (int *)((long)plVar4 + 0xc);
      iVar2 = *piVar3;
      *piVar3 = *piVar3 + -1;
      UNLOCK();
      if (iVar2 == 1) {
        pcVar5 = *(code **)(*plVar4 + 0x18);
        if (pcVar5 == std::_Sp_counted_base<(__gnu_cxx::_Lock_policy)2>::_M_destroy) {
          (**(code **)(*plVar4 + 8))(plVar4);
        }
        else {
          (*pcVar5)();
        }
      }
    }
  }
  QWidget::~QWidget((QWidget *)(param_1 + -2));
  return;
}


// ==== entry=008fa020 name=FUN_008fa020 size=316 ====

/* WARNING: Removing unreachable block (ram,0x008fa0f4) */
/* WARNING: Removing unreachable block (ram,0x008fa149) */

void FUN_008fa020(undefined8 *param_1)

{
  long *plVar1;
  int iVar2;
  int *piVar3;
  long *plVar4;
  code *pcVar5;
  long lVar6;
  
  param_1[-2] = &FileView_vtable;
  *param_1 = &PTR_FUN_0119c768;
  piVar3 = (int *)param_1[0x14];
  if (piVar3 != (int *)0x0) {
    LOCK();
    *piVar3 = *piVar3 + -1;
    UNLOCK();
    if ((*piVar3 == 0) && ((void *)param_1[0x14] != (void *)0x0)) {
      operator_delete((void *)param_1[0x14]);
    }
  }
  piVar3 = (int *)param_1[0x12];
  if (piVar3 != (int *)0x0) {
    LOCK();
    *piVar3 = *piVar3 + -1;
    UNLOCK();
    if ((*piVar3 == 0) && ((void *)param_1[0x12] != (void *)0x0)) {
      operator_delete((void *)param_1[0x12]);
    }
  }
  piVar3 = (int *)param_1[0xf];
  if (piVar3 != (int *)0x0) {
    LOCK();
    *piVar3 = *piVar3 + -1;
    UNLOCK();
    if ((*piVar3 == 0) && ((void *)param_1[0xf] != (void *)0x0)) {
      operator_delete((void *)param_1[0xf]);
    }
  }
  plVar4 = (long *)param_1[10];
  if (plVar4 != (long *)0x0) {
    LOCK();
    plVar1 = plVar4 + 1;
    lVar6 = *plVar1;
    *(int *)plVar1 = (int)*plVar1 + -1;
    UNLOCK();
    if ((int)lVar6 == 1) {
      if (*(code **)(*plVar4 + 0x10) != FUN_00575d12) {
        (**(code **)(*plVar4 + 0x10))(plVar4);
      }
      LOCK();
      piVar3 = (int *)((long)plVar4 + 0xc);
      iVar2 = *piVar3;
      *piVar3 = *piVar3 + -1;
      UNLOCK();
      if (iVar2 == 1) {
        pcVar5 = *(code **)(*plVar4 + 0x18);
        if (pcVar5 == std::_Sp_counted_base<(__gnu_cxx::_Lock_policy)2>::_M_destroy) {
          (**(code **)(*plVar4 + 8))(plVar4);
        }
        else {
          (*pcVar5)();
        }
      }
    }
  }
  QWidget::~QWidget((QWidget *)(param_1 + -2));
  operator_delete((QWidget *)(param_1 + -2),0xc0);
  return;
}


// ==== entry=008fa15c orig=FUN_008fa15c size=328 name=FileView_dtor_deleting ====

/* WARNING: Removing unreachable block (ram,0x008fa232) */
/* WARNING: Removing unreachable block (ram,0x008fa285) */

void FileView_dtor_deleting(QWidget *param_1)

{
  long *plVar1;
  int iVar2;
  int *piVar3;
  long *plVar4;
  code *pcVar5;
  long lVar6;
  
  *(undefined ***)param_1 = &FileView_vtable;
  *(undefined ***)(param_1 + 0x10) = &PTR_FUN_0119c768;
  piVar3 = *(int **)(param_1 + 0xb0);
  if (piVar3 != (int *)0x0) {
    LOCK();
    *piVar3 = *piVar3 + -1;
    UNLOCK();
    if ((*piVar3 == 0) && (*(void **)(param_1 + 0xb0) != (void *)0x0)) {
      operator_delete(*(void **)(param_1 + 0xb0));
    }
  }
  piVar3 = *(int **)(param_1 + 0xa0);
  if (piVar3 != (int *)0x0) {
    LOCK();
    *piVar3 = *piVar3 + -1;
    UNLOCK();
    if ((*piVar3 == 0) && (*(void **)(param_1 + 0xa0) != (void *)0x0)) {
      operator_delete(*(void **)(param_1 + 0xa0));
    }
  }
  piVar3 = *(int **)(param_1 + 0x88);
  if (piVar3 != (int *)0x0) {
    LOCK();
    *piVar3 = *piVar3 + -1;
    UNLOCK();
    if ((*piVar3 == 0) && (*(void **)(param_1 + 0x88) != (void *)0x0)) {
      operator_delete(*(void **)(param_1 + 0x88));
    }
  }
  plVar4 = *(long **)(param_1 + 0x60);
  if (plVar4 != (long *)0x0) {
    LOCK();
    plVar1 = plVar4 + 1;
    lVar6 = *plVar1;
    *(int *)plVar1 = (int)*plVar1 + -1;
    UNLOCK();
    if ((int)lVar6 == 1) {
      if (*(code **)(*plVar4 + 0x10) != FUN_00575d12) {
        (**(code **)(*plVar4 + 0x10))(plVar4);
      }
      LOCK();
      piVar3 = (int *)((long)plVar4 + 0xc);
      iVar2 = *piVar3;
      *piVar3 = *piVar3 + -1;
      UNLOCK();
      if (iVar2 == 1) {
        pcVar5 = *(code **)(*plVar4 + 0x18);
        if (pcVar5 == std::_Sp_counted_base<(__gnu_cxx::_Lock_policy)2>::_M_destroy) {
          (**(code **)(*plVar4 + 8))();
        }
        else {
          (*pcVar5)(plVar4);
        }
      }
    }
  }
  QWidget::~QWidget(param_1);
  operator_delete(param_1,0xc0);
  return;
}


// ==== entry=008fa2a4 name=FUN_008fa2a4 size=1 ====

void FUN_008fa2a4(void)

{
  return;
}


// ==== entry=008fa2a6 orig=FUN_008fa2a6 size=24 name=HtmlLabel_metaObject ====

undefined ** HtmlLabel_metaObject(long param_1)

{
  undefined **ppuVar1;
  
  if (*(long *)(*(long *)(param_1 + 8) + 0x28) != 0) {
    ppuVar1 = (undefined **)QObjectData::dynamicMetaObject();
    return ppuVar1;
  }
  return &PTR_staticMetaObject_0119ca20;
}


// ==== entry=008fa2be orig=FUN_008fa2be size=66 name=HtmlLabel_qt_metacast ====

char * HtmlLabel_qt_metacast(char *param_1,char *param_2)

{
  int iVar1;
  char *pcVar2;
  
  if (param_2 == (char *)0x0) {
    return (char *)0x0;
  }
  iVar1 = strcmp(param_2,"HtmlLabel");
  if (iVar1 == 0) {
    return param_1;
  }
  pcVar2 = (char *)QLabel::qt_metacast(param_1);
  return pcVar2;
}


// ==== entry=008fa300 orig=FUN_008fa300 size=5 name=HtmlLabel_qt_metacall ====

void QLabel::HtmlLabel_qt_metacall(void)

{
  qt_metacall();
  return;
}


// ==== entry=008fa306 orig=FUN_008fa306 size=92 name=HtmlLabel_dtor_deleting ====

void HtmlLabel_dtor_deleting(QLabel *param_1)

{
  QArrayData *pQVar1;
  
  *(undefined ***)param_1 = &HtmlLabel_vtable;
  *(undefined ***)(param_1 + 0x10) = &PTR_FUN_0119c9c8;
  pQVar1 = *(QArrayData **)(param_1 + 0x30);
  if (*(int *)pQVar1 != 0) {
    if (*(int *)pQVar1 == -1) goto LAB_008fa337;
    LOCK();
    *(int *)pQVar1 = *(int *)pQVar1 + -1;
    UNLOCK();
    if (*(int *)pQVar1 != 0) goto LAB_008fa337;
    pQVar1 = *(QArrayData **)(param_1 + 0x30);
  }
  QArrayData::deallocate(pQVar1,2,8);
LAB_008fa337:
  QLabel::~QLabel(param_1);
  operator_delete(param_1,0x48);
  return;
}


// ==== entry=008fa362 name=FUN_008fa362 size=96 ====

void FUN_008fa362(undefined8 *param_1)

{
  QArrayData *pQVar1;
  
  param_1[-2] = &HtmlLabel_vtable;
  *param_1 = &PTR_FUN_0119c9c8;
  pQVar1 = (QArrayData *)param_1[4];
  if (*(int *)pQVar1 != 0) {
    if (*(int *)pQVar1 == -1) goto LAB_008fa394;
    LOCK();
    *(int *)pQVar1 = *(int *)pQVar1 + -1;
    UNLOCK();
    if (*(int *)pQVar1 != 0) goto LAB_008fa394;
    pQVar1 = (QArrayData *)param_1[4];
  }
  QArrayData::deallocate(pQVar1,2,8);
LAB_008fa394:
  QLabel::~QLabel((QLabel *)(param_1 + -2));
  operator_delete((QLabel *)(param_1 + -2),0x48);
  return;
}


// ==== entry=008fa3c2 name=FUN_008fa3c2 size=88 ====

void FUN_008fa3c2(undefined8 *param_1)

{
  QArrayData *pQVar1;
  
  param_1[-2] = &HtmlLabel_vtable;
  *param_1 = &PTR_FUN_0119c9c8;
  pQVar1 = (QArrayData *)param_1[4];
  if (*(int *)pQVar1 == 0) {
LAB_008fa401:
    QArrayData::deallocate(pQVar1,2,8);
    QLabel::~QLabel((QLabel *)(param_1 + -2));
    return;
  }
  if (*(int *)pQVar1 != -1) {
    LOCK();
    *(int *)pQVar1 = *(int *)pQVar1 + -1;
    UNLOCK();
    if (*(int *)pQVar1 == 0) {
      pQVar1 = (QArrayData *)param_1[4];
      goto LAB_008fa401;
    }
  }
  QLabel::~QLabel((QLabel *)(param_1 + -2));
  return;
}


// ==== entry=008fa41a orig=FUN_008fa41a size=86 name=HtmlLabel_dtor ====

void HtmlLabel_dtor(QLabel *param_1)

{
  QArrayData *pQVar1;
  
  *(undefined ***)param_1 = &HtmlLabel_vtable;
  *(undefined ***)(param_1 + 0x10) = &PTR_FUN_0119c9c8;
  pQVar1 = *(QArrayData **)(param_1 + 0x30);
  if (*(int *)pQVar1 == 0) {
LAB_008fa458:
    QArrayData::deallocate(pQVar1,2,8);
    QLabel::~QLabel(param_1);
    return;
  }
  if (*(int *)pQVar1 != -1) {
    LOCK();
    *(int *)pQVar1 = *(int *)pQVar1 + -1;
    UNLOCK();
    if (*(int *)pQVar1 == 0) {
      pQVar1 = *(QArrayData **)(param_1 + 0x30);
      goto LAB_008fa458;
    }
  }
  QLabel::~QLabel(param_1);
  return;
}


// ==== entry=008fa470 name=FUN_008fa470 size=1 ====

void FUN_008fa470(void)

{
  return;
}


// ==== entry=008fa472 orig=FUN_008fa472 size=24 name=FileDialog_metaObject ====

undefined ** FileDialog_metaObject(long param_1)

{
  undefined **ppuVar1;
  
  if (*(long *)(*(long *)(param_1 + 8) + 0x28) != 0) {
    ppuVar1 = (undefined **)QObjectData::dynamicMetaObject();
    return ppuVar1;
  }
  return &PTR_staticMetaObject_0119cca0;
}


// ==== entry=008fa48a orig=FUN_008fa48a size=66 name=FileDialog_qt_metacast ====

char * FileDialog_qt_metacast(char *param_1,char *param_2)

{
  int iVar1;
  char *pcVar2;
  
  if (param_2 == (char *)0x0) {
    return (char *)0x0;
  }
  iVar1 = strcmp(param_2,"FileDialog");
  if (iVar1 == 0) {
    return param_1;
  }
  pcVar2 = (char *)QFileDialog::qt_metacast(param_1);
  return pcVar2;
}


// ==== entry=008fa4cc orig=FUN_008fa4cc size=5 name=FileDialog_qt_metacall ====

void QFileDialog::FileDialog_qt_metacall(void)

{
  qt_metacall();
  return;
}


// ==== entry=008fa4d2 orig=FUN_008fa4d2 size=92 name=FileDialog_dtor_deleting ====

void FileDialog_dtor_deleting(QFileDialog *param_1)

{
  QArrayData *pQVar1;
  
  *(undefined ***)param_1 = &FileDialog_vtable;
  *(undefined ***)(param_1 + 0x10) = &PTR_FUN_0119cc50;
  pQVar1 = *(QArrayData **)(param_1 + 0x30);
  if (*(int *)pQVar1 != 0) {
    if (*(int *)pQVar1 == -1) goto LAB_008fa503;
    LOCK();
    *(int *)pQVar1 = *(int *)pQVar1 + -1;
    UNLOCK();
    if (*(int *)pQVar1 != 0) goto LAB_008fa503;
    pQVar1 = *(QArrayData **)(param_1 + 0x30);
  }
  QArrayData::deallocate(pQVar1,1,8);
LAB_008fa503:
  QFileDialog::~QFileDialog(param_1);
  operator_delete(param_1,0x38);
  return;
}


// ==== entry=008fa52e name=FUN_008fa52e size=96 ====

void FUN_008fa52e(undefined8 *param_1)

{
  QArrayData *pQVar1;
  
  param_1[-2] = &FileDialog_vtable;
  *param_1 = &PTR_FUN_0119cc50;
  pQVar1 = (QArrayData *)param_1[4];
  if (*(int *)pQVar1 != 0) {
    if (*(int *)pQVar1 == -1) goto LAB_008fa560;
    LOCK();
    *(int *)pQVar1 = *(int *)pQVar1 + -1;
    UNLOCK();
    if (*(int *)pQVar1 != 0) goto LAB_008fa560;
    pQVar1 = (QArrayData *)param_1[4];
  }
  QArrayData::deallocate(pQVar1,1,8);
LAB_008fa560:
  QFileDialog::~QFileDialog((QFileDialog *)(param_1 + -2));
  operator_delete((QFileDialog *)(param_1 + -2),0x38);
  return;
}


// ==== entry=008fa58e name=FUN_008fa58e size=88 ====

void FUN_008fa58e(undefined8 *param_1)

{
  QArrayData *pQVar1;
  
  param_1[-2] = &FileDialog_vtable;
  *param_1 = &PTR_FUN_0119cc50;
  pQVar1 = (QArrayData *)param_1[4];
  if (*(int *)pQVar1 == 0) {
LAB_008fa5cd:
    QArrayData::deallocate(pQVar1,1,8);
    QFileDialog::~QFileDialog((QFileDialog *)(param_1 + -2));
    return;
  }
  if (*(int *)pQVar1 != -1) {
    LOCK();
    *(int *)pQVar1 = *(int *)pQVar1 + -1;
    UNLOCK();
    if (*(int *)pQVar1 == 0) {
      pQVar1 = (QArrayData *)param_1[4];
      goto LAB_008fa5cd;
    }
  }
  QFileDialog::~QFileDialog((QFileDialog *)(param_1 + -2));
  return;
}


// ==== entry=008fa5e6 orig=FUN_008fa5e6 size=86 name=FileDialog_dtor ====

void FileDialog_dtor(QFileDialog *param_1)

{
  QArrayData *pQVar1;
  
  *(undefined ***)param_1 = &FileDialog_vtable;
  *(undefined ***)(param_1 + 0x10) = &PTR_FUN_0119cc50;
  pQVar1 = *(QArrayData **)(param_1 + 0x30);
  if (*(int *)pQVar1 == 0) {
LAB_008fa624:
    QArrayData::deallocate(pQVar1,1,8);
    QFileDialog::~QFileDialog(param_1);
    return;
  }
  if (*(int *)pQVar1 != -1) {
    LOCK();
    *(int *)pQVar1 = *(int *)pQVar1 + -1;
    UNLOCK();
    if (*(int *)pQVar1 == 0) {
      pQVar1 = *(QArrayData **)(param_1 + 0x30);
      goto LAB_008fa624;
    }
  }
  QFileDialog::~QFileDialog(param_1);
  return;
}


// ==== entry=008fa640 orig=FUN_008fa640 size=24 name=IconSelector_metaObject ====

undefined ** IconSelector_metaObject(long param_1)

{
  undefined **ppuVar1;
  
  if (*(long *)(*(long *)(param_1 + 8) + 0x28) != 0) {
    ppuVar1 = (undefined **)QObjectData::dynamicMetaObject();
    return ppuVar1;
  }
  return &PTR_PTR_0119cf00;
}


// ==== entry=008fa658 orig=FUN_008fa658 size=66 name=IconSelector_qt_metacast ====

undefined8 IconSelector_qt_metacast(undefined8 param_1,char *param_2)

{
  int iVar1;
  undefined8 uVar2;
  
  if (param_2 == (char *)0x0) {
    return 0;
  }
  iVar1 = strcmp(param_2,"IconSelector");
  if (iVar1 == 0) {
    return param_1;
  }
  uVar2 = SideButton_qt_metacast(param_1,param_2);
  return uVar2;
}


// ==== entry=008fa69a name=FUN_008fa69a size=39 ====

void FUN_008fa69a(QObject *param_1,undefined8 param_2)

{
  void *local_18;
  undefined8 local_10;
  
  local_18 = (void *)0x0;
  local_10 = param_2;
  QMetaObject::activate(param_1,(QMetaObject *)&PTR_PTR_0119cf00,0,&local_18);
  return;
}


// ==== entry=008fa6c2 name=FUN_008fa6c2 size=58 ====

void FUN_008fa6c2(undefined8 param_1,int param_2,int param_3,undefined8 *param_4)

{
  if (param_2 == 0) {
    if (param_3 == 0) {
      FUN_008fa69a(param_1,param_4[1]);
      return;
    }
  }
  else if (((param_2 == 10) && (*(code **)param_4[1] == FUN_008fa69a)) &&
          (((long *)param_4[1])[1] == 0)) {
    *(undefined4 *)*param_4 = 0;
    return;
  }
  return;
}


// ==== entry=008fa6fc orig=FUN_008fa6fc size=93 name=IconSelector_qt_metacall ====

ulong IconSelector_qt_metacall
                (undefined8 param_1,int param_2,undefined8 param_3,undefined8 *param_4)

{
  int iVar1;
  ulong uVar2;
  
  uVar2 = QPushButton::SideButton_qt_metacall();
  iVar1 = (int)uVar2;
  if (-1 < iVar1) {
    if (param_2 == 0) {
      if (iVar1 == 0) {
        FUN_008fa69a(param_1,param_4[1]);
        uVar2 = uVar2 & 0xffffffff;
      }
    }
    else {
      if (param_2 != 0xc) {
        return uVar2;
      }
      if (iVar1 == 0) {
        *(undefined4 *)*param_4 = 0xffffffff;
      }
    }
    uVar2 = (ulong)((int)uVar2 - 1);
  }
  return uVar2;
}


// ==== entry=008fa75a orig=FUN_008fa75a size=116 name=IconSelector_dtor_deleting ====

void IconSelector_dtor_deleting(QPushButton *param_1)

{
  QArrayData *pQVar1;
  
  *(undefined ***)param_1 = &IconSelector_vtable;
  *(undefined ***)(param_1 + 0x10) = &PTR_FUN_0119cec0;
  pQVar1 = *(QArrayData **)(param_1 + 0x38);
  if (*(int *)pQVar1 != 0) {
    if (*(int *)pQVar1 == -1) goto LAB_008fa78b;
    LOCK();
    *(int *)pQVar1 = *(int *)pQVar1 + -1;
    UNLOCK();
    if (*(int *)pQVar1 != 0) goto LAB_008fa78b;
    pQVar1 = *(QArrayData **)(param_1 + 0x38);
  }
  QArrayData::deallocate(pQVar1,2,8);
LAB_008fa78b:
  *(undefined ***)param_1 = &SideButton_vtable;
  *(undefined ***)(param_1 + 0x10) = &PTR_FUN_01198898;
  QPushButton::~QPushButton(param_1);
  operator_delete(param_1,0x48);
  return;
}


// ==== entry=008fa7ce name=FUN_008fa7ce size=130 ====

void FUN_008fa7ce(undefined8 *param_1)

{
  QArrayData *pQVar1;
  
  param_1[-2] = &IconSelector_vtable;
  *param_1 = &PTR_FUN_0119cec0;
  pQVar1 = (QArrayData *)param_1[5];
  if (*(int *)pQVar1 != 0) {
    if (*(int *)pQVar1 == -1) goto LAB_008fa808;
    LOCK();
    *(int *)pQVar1 = *(int *)pQVar1 + -1;
    UNLOCK();
    if (*(int *)pQVar1 != 0) goto LAB_008fa808;
    pQVar1 = (QArrayData *)param_1[5];
  }
  QArrayData::deallocate(pQVar1,2,8);
LAB_008fa808:
  param_1[-2] = &SideButton_vtable;
  *param_1 = &PTR_FUN_01198898;
  QPushButton::~QPushButton((QPushButton *)(param_1 + -2));
  operator_delete((QPushButton *)(param_1 + -2),0x48);
  return;
}


// ==== entry=008fa850 name=FUN_008fa850 size=104 ====

void FUN_008fa850(undefined8 *param_1)

{
  QArrayData *pQVar1;
  
  param_1[-2] = &IconSelector_vtable;
  *param_1 = &PTR_FUN_0119cec0;
  pQVar1 = (QArrayData *)param_1[5];
  if (*(int *)pQVar1 != 0) {
    if (*(int *)pQVar1 == -1) goto LAB_008fa881;
    LOCK();
    *(int *)pQVar1 = *(int *)pQVar1 + -1;
    UNLOCK();
    if (*(int *)pQVar1 != 0) goto LAB_008fa881;
    pQVar1 = (QArrayData *)param_1[5];
  }
  QArrayData::deallocate(pQVar1,2,8);
LAB_008fa881:
  param_1[-2] = &SideButton_vtable;
  *param_1 = &PTR_FUN_01198898;
  QPushButton::~QPushButton((QPushButton *)(param_1 + -2));
  return;
}


// ==== entry=008fa8b8 orig=FUN_008fa8b8 size=103 name=IconSelector_dtor ====

void IconSelector_dtor(QPushButton *param_1)

{
  QArrayData *pQVar1;
  
  *(undefined ***)param_1 = &IconSelector_vtable;
  *(undefined ***)(param_1 + 0x10) = &PTR_FUN_0119cec0;
  pQVar1 = *(QArrayData **)(param_1 + 0x38);
  if (*(int *)pQVar1 != 0) {
    if (*(int *)pQVar1 == -1) goto LAB_008fa8e9;
    LOCK();
    *(int *)pQVar1 = *(int *)pQVar1 + -1;
    UNLOCK();
    if (*(int *)pQVar1 != 0) goto LAB_008fa8e9;
    pQVar1 = *(QArrayData **)(param_1 + 0x38);
  }
  QArrayData::deallocate(pQVar1,2,8);
LAB_008fa8e9:
  *(undefined ***)param_1 = &SideButton_vtable;
  *(undefined ***)(param_1 + 0x10) = &PTR_FUN_01198898;
  QPushButton::~QPushButton(param_1);
  return;
}


// ==== entry=008fa920 orig=FUN_008fa920 size=24 name=PathEdit_metaObject ====

undefined ** PathEdit_metaObject(long param_1)

{
  undefined **ppuVar1;
  
  if (*(long *)(*(long *)(param_1 + 8) + 0x28) != 0) {
    ppuVar1 = (undefined **)QObjectData::dynamicMetaObject();
    return ppuVar1;
  }
  return &PTR_PTR_0119d160;
}


// ==== entry=008fa938 orig=FUN_008fa938 size=66 name=PathEdit_qt_metacast ====

undefined8 PathEdit_qt_metacast(undefined8 param_1,char *param_2)

{
  int iVar1;
  undefined8 uVar2;
  
  if (param_2 == (char *)0x0) {
    return 0;
  }
  iVar1 = strcmp(param_2,"PathEdit");
  if (iVar1 == 0) {
    return param_1;
  }
  uVar2 = s_LineEdit_8f6e2e(param_1,param_2);
  return uVar2;
}


// ==== entry=008fa97a name=FUN_008fa97a size=16 ====

void FUN_008fa97a(QObject *param_1)

{
  QMetaObject::activate(param_1,(QMetaObject *)&PTR_PTR_0119d160,0,(void **)0x0);
  return;
}


// ==== entry=008fa98a name=FUN_008fa98a size=52 ====

void FUN_008fa98a(undefined8 param_1,int param_2,int param_3,undefined8 *param_4)

{
  if (param_2 == 0) {
    if (param_3 == 0) {
      FUN_008fa97a();
      return;
    }
  }
  else if (((param_2 == 10) && (*(code **)param_4[1] == FUN_008fa97a)) &&
          (((long *)param_4[1])[1] == 0)) {
    *(undefined4 *)*param_4 = 0;
    return;
  }
  return;
}


// ==== entry=008fa9be orig=FUN_008fa9be size=87 name=PathEdit_qt_metacall ====

ulong PathEdit_qt_metacall(undefined8 param_1,int param_2,undefined8 param_3,undefined8 *param_4)

{
  int iVar1;
  ulong uVar2;
  
  uVar2 = FUN_008f6e70();
  iVar1 = (int)uVar2;
  if (-1 < iVar1) {
    if (param_2 == 0) {
      if (iVar1 == 0) {
        FUN_008fa97a(param_1);
        uVar2 = uVar2 & 0xffffffff;
      }
    }
    else {
      if (param_2 != 0xc) {
        return uVar2;
      }
      if (iVar1 == 0) {
        *(undefined4 *)*param_4 = 0xffffffff;
      }
    }
    uVar2 = (ulong)((int)uVar2 - 1);
  }
  return uVar2;
}


// ==== entry=008faa16 name=FUN_008faa16 size=102 ====

void FUN_008faa16(undefined8 *param_1)

{
  int *piVar1;
  
  param_1[-2] = &PTR_FUN_01198458;
  *param_1 = &PTR_FUN_01198608;
  FUN_00544670(param_1 + 8);
  piVar1 = (int *)param_1[4];
  if (piVar1 != (int *)0x0) {
    LOCK();
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if ((*piVar1 == 0) && ((void *)param_1[4] != (void *)0x0)) {
      operator_delete((void *)param_1[4]);
    }
  }
  QLineEdit::~QLineEdit((QLineEdit *)(param_1 + -2));
  operator_delete((QLineEdit *)(param_1 + -2),0x80);
  return;
}


// ==== entry=008faa7c orig=FUN_008faa7c size=88 name=PathEdit_dtor_deleting ====

void PathEdit_dtor_deleting(QLineEdit *param_1)

{
  int *piVar1;
  
  *(undefined ***)param_1 = &PTR_FUN_01198458;
  *(undefined ***)(param_1 + 0x10) = &PTR_FUN_01198608;
  FUN_00544670(param_1 + 0x50);
  piVar1 = *(int **)(param_1 + 0x30);
  if (piVar1 != (int *)0x0) {
    LOCK();
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if ((*piVar1 == 0) && (*(void **)(param_1 + 0x30) != (void *)0x0)) {
      operator_delete(*(void **)(param_1 + 0x30));
    }
  }
  QLineEdit::~QLineEdit(param_1);
  operator_delete(param_1,0x80);
  return;
}


// ==== entry=008faad4 name=FUN_008faad4 size=89 ====

void FUN_008faad4(undefined8 *param_1)

{
  int *piVar1;
  
  param_1[-2] = &PTR_FUN_01198458;
  *param_1 = &PTR_FUN_01198608;
  FUN_00544670(param_1 + 8);
  piVar1 = (int *)param_1[4];
  if (piVar1 != (int *)0x0) {
    LOCK();
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if ((*piVar1 == 0) && ((void *)param_1[4] != (void *)0x0)) {
      operator_delete((void *)param_1[4]);
    }
  }
  QLineEdit::~QLineEdit((QLineEdit *)(param_1 + -2));
  return;
}


// ==== entry=008fab2e orig=FUN_008fab2e size=75 name=PathEdit_dtor ====

void PathEdit_dtor(QLineEdit *param_1)

{
  int *piVar1;
  
  *(undefined ***)param_1 = &PTR_FUN_01198458;
  *(undefined ***)(param_1 + 0x10) = &PTR_FUN_01198608;
  FUN_00544670(param_1 + 0x50);
  piVar1 = *(int **)(param_1 + 0x30);
  if (piVar1 != (int *)0x0) {
    LOCK();
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if ((*piVar1 == 0) && (*(void **)(param_1 + 0x30) != (void *)0x0)) {
      operator_delete(*(void **)(param_1 + 0x30));
    }
  }
  QLineEdit::~QLineEdit(param_1);
  return;
}


// ==== entry=008fab7a name=FUN_008fab7a size=1 ====

void FUN_008fab7a(void)

{
  return;
}


// ==== entry=008fab7c orig=FUN_008fab7c size=24 name=SafeEdit_metaObject ====

undefined ** SafeEdit_metaObject(long param_1)

{
  undefined **ppuVar1;
  
  if (*(long *)(*(long *)(param_1 + 8) + 0x28) != 0) {
    ppuVar1 = (undefined **)QObjectData::dynamicMetaObject();
    return ppuVar1;
  }
  return &PTR_PTR_0119d3c0;
}


// ==== entry=008fab94 orig=FUN_008fab94 size=66 name=SafeEdit_qt_metacast ====

undefined8 SafeEdit_qt_metacast(undefined8 param_1,char *param_2)

{
  int iVar1;
  undefined8 uVar2;
  
  if (param_2 == (char *)0x0) {
    return 0;
  }
  iVar1 = strcmp(param_2,"SafeEdit");
  if (iVar1 == 0) {
    return param_1;
  }
  uVar2 = s_LineEdit_8f6e2e(param_1,param_2);
  return uVar2;
}


// ==== entry=008fabd6 orig=FUN_008fabd6 size=5 name=SafeEdit_qt_metacall ====

ulong SafeEdit_qt_metacall(undefined8 param_1,int param_2,undefined8 param_3,undefined8 *param_4)

{
  int iVar1;
  ulong uVar2;
  
  uVar2 = QLineEdit::qt_metacall();
  iVar1 = (int)uVar2;
  if (-1 < iVar1) {
    if (param_2 == 0) {
      if (iVar1 < 2) {
        FUN_008f6dd0(param_1,0,uVar2 & 0xffffffff,param_4);
        uVar2 = uVar2 & 0xffffffff;
      }
    }
    else {
      if (param_2 != 0xc) {
        return uVar2;
      }
      if (iVar1 < 2) {
        *(undefined4 *)*param_4 = 0xffffffff;
      }
    }
    uVar2 = (ulong)((int)uVar2 - 2);
  }
  return uVar2;
}


// ==== entry=008fabdc name=FUN_008fabdc size=168 ====

void FUN_008fabdc(undefined8 *param_1)

{
  int *piVar1;
  QArrayData *pQVar2;
  
  param_1[-2] = &SafeEdit_vtable;
  *param_1 = &PTR_FUN_0119d368;
  pQVar2 = (QArrayData *)param_1[0xf];
  if (*(int *)pQVar2 != 0) {
    if (*(int *)pQVar2 == -1) goto LAB_008fac16;
    LOCK();
    *(int *)pQVar2 = *(int *)pQVar2 + -1;
    UNLOCK();
    if (*(int *)pQVar2 != 0) goto LAB_008fac16;
    pQVar2 = (QArrayData *)param_1[0xf];
  }
  QArrayData::deallocate(pQVar2,2,8);
LAB_008fac16:
  param_1[-2] = &PTR_FUN_01198458;
  *param_1 = &PTR_FUN_01198608;
  FUN_00544670(param_1 + 8);
  piVar1 = (int *)param_1[4];
  if (piVar1 != (int *)0x0) {
    LOCK();
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if ((*piVar1 == 0) && ((void *)param_1[4] != (void *)0x0)) {
      operator_delete((void *)param_1[4]);
    }
  }
  QLineEdit::~QLineEdit((QLineEdit *)(param_1 + -2));
  operator_delete((QLineEdit *)(param_1 + -2),0x90);
  return;
}


// ==== entry=008fac84 orig=FUN_008fac84 size=160 name=SafeEdit_dtor_deleting ====

void SafeEdit_dtor_deleting(QLineEdit *param_1)

{
  int *piVar1;
  QArrayData *pQVar2;
  
  *(undefined ***)param_1 = &SafeEdit_vtable;
  *(undefined ***)(param_1 + 0x10) = &PTR_FUN_0119d368;
  pQVar2 = *(QArrayData **)(param_1 + 0x88);
  if (*(int *)pQVar2 != 0) {
    if (*(int *)pQVar2 == -1) goto LAB_008facb8;
    LOCK();
    *(int *)pQVar2 = *(int *)pQVar2 + -1;
    UNLOCK();
    if (*(int *)pQVar2 != 0) goto LAB_008facb8;
    pQVar2 = *(QArrayData **)(param_1 + 0x88);
  }
  QArrayData::deallocate(pQVar2,2,8);
LAB_008facb8:
  *(undefined ***)param_1 = &PTR_FUN_01198458;
  *(undefined ***)(param_1 + 0x10) = &PTR_FUN_01198608;
  FUN_00544670(param_1 + 0x50);
  piVar1 = *(int **)(param_1 + 0x30);
  if (piVar1 != (int *)0x0) {
    LOCK();
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if ((*piVar1 == 0) && (*(void **)(param_1 + 0x30) != (void *)0x0)) {
      operator_delete(*(void **)(param_1 + 0x30));
    }
  }
  QLineEdit::~QLineEdit(param_1);
  operator_delete(param_1,0x90);
  return;
}


// ==== entry=008fad24 name=FUN_008fad24 size=155 ====

void FUN_008fad24(undefined8 *param_1)

{
  int *piVar1;
  QArrayData *pQVar2;
  
  param_1[-2] = &SafeEdit_vtable;
  *param_1 = &PTR_FUN_0119d368;
  pQVar2 = (QArrayData *)param_1[0xf];
  if (*(int *)pQVar2 != 0) {
    if (*(int *)pQVar2 == -1) goto LAB_008fad5a;
    LOCK();
    *(int *)pQVar2 = *(int *)pQVar2 + -1;
    UNLOCK();
    if (*(int *)pQVar2 != 0) goto LAB_008fad5a;
    pQVar2 = (QArrayData *)param_1[0xf];
  }
  QArrayData::deallocate(pQVar2,2,8);
LAB_008fad5a:
  param_1[-2] = &PTR_FUN_01198458;
  *param_1 = &PTR_FUN_01198608;
  FUN_00544670(param_1 + 8);
  piVar1 = (int *)param_1[4];
  if (piVar1 != (int *)0x0) {
    LOCK();
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if ((*piVar1 == 0) && ((void *)param_1[4] != (void *)0x0)) {
      operator_delete((void *)param_1[4]);
    }
  }
  QLineEdit::~QLineEdit((QLineEdit *)(param_1 + -2));
  return;
}


// ==== entry=008fadc0 orig=FUN_008fadc0 size=147 name=SafeEdit_dtor ====

void SafeEdit_dtor(QLineEdit *param_1)

{
  int *piVar1;
  QArrayData *pQVar2;
  
  *(undefined ***)param_1 = &SafeEdit_vtable;
  *(undefined ***)(param_1 + 0x10) = &PTR_FUN_0119d368;
  pQVar2 = *(QArrayData **)(param_1 + 0x88);
  if (*(int *)pQVar2 != 0) {
    if (*(int *)pQVar2 == -1) goto LAB_008fadf4;
    LOCK();
    *(int *)pQVar2 = *(int *)pQVar2 + -1;
    UNLOCK();
    if (*(int *)pQVar2 != 0) goto LAB_008fadf4;
    pQVar2 = *(QArrayData **)(param_1 + 0x88);
  }
  QArrayData::deallocate(pQVar2,2,8);
LAB_008fadf4:
  *(undefined ***)param_1 = &PTR_FUN_01198458;
  *(undefined ***)(param_1 + 0x10) = &PTR_FUN_01198608;
  FUN_00544670(param_1 + 0x50);
  piVar1 = *(int **)(param_1 + 0x30);
  if (piVar1 != (int *)0x0) {
    LOCK();
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if ((*piVar1 == 0) && (*(void **)(param_1 + 0x30) != (void *)0x0)) {
      operator_delete(*(void **)(param_1 + 0x30));
    }
  }
  QLineEdit::~QLineEdit(param_1);
  return;
}


// ==== entry=008fae60 orig=FUN_008fae60 size=24 name=SlipButton_metaObject ====

undefined ** SlipButton_metaObject(long param_1)

{
  undefined **ppuVar1;
  
  if (*(long *)(*(long *)(param_1 + 8) + 0x28) != 0) {
    ppuVar1 = (undefined **)QObjectData::dynamicMetaObject();
    return ppuVar1;
  }
  return &PTR_staticMetaObject_0119d620;
}


// ==== entry=008fae78 name=FUN_008fae78 size=52 ====

void FUN_008fae78(QObject *param_1,undefined1 param_2)

{
  undefined1 local_1c [4];
  void *local_18;
  undefined1 *local_10;
  
  local_18 = (void *)0x0;
  local_10 = local_1c;
  local_1c[0] = param_2;
  QMetaObject::activate(param_1,(QMetaObject *)&PTR_staticMetaObject_0119d620,0,&local_18);
  return;
}


// ==== entry=008faeac name=FUN_008faeac size=55 ====

void FUN_008faeac(QObject *param_1,undefined1 param_2)

{
  undefined1 local_1c [4];
  void *local_18;
  undefined1 *local_10;
  
  local_18 = (void *)0x0;
  local_10 = local_1c;
  local_1c[0] = param_2;
  QMetaObject::activate(param_1,(QMetaObject *)&PTR_staticMetaObject_0119d620,1,&local_18);
  return;
}


// ==== entry=008faee4 name=FUN_008faee4 size=460 ====

void FUN_008faee4(long param_1,int param_2,int param_3,undefined8 *param_4)

{
  undefined2 uVar1;
  undefined8 uVar2;
  long *plVar3;
  undefined4 *puVar4;
  long lVar5;
  undefined4 local_28;
  undefined4 uStack_24;
  
  if (param_2 == 0) {
    if (param_3 == 0) {
      FUN_008fae78(param_1,*(undefined1 *)param_4[1]);
      return;
    }
    if (param_3 == 1) {
      FUN_008faeac(param_1,*(undefined1 *)param_4[1]);
    }
  }
  else if (param_2 == 10) {
    plVar3 = (long *)param_4[1];
    if ((code *)*plVar3 == FUN_008fae78) {
      if (plVar3[1] == 0) {
        *(undefined4 *)*param_4 = 0;
      }
    }
    else if (((code *)*plVar3 == FUN_008faeac) && (plVar3[1] == 0)) {
      *(undefined4 *)*param_4 = 1;
    }
  }
  else if (param_2 == 1) {
    puVar4 = (undefined4 *)*param_4;
    switch(param_3) {
    case 0:
      lVar5 = *(long *)(param_1 + 0x60);
      break;
    case 1:
      lVar5 = *(long *)(param_1 + 0x70);
      break;
    case 2:
      lVar5 = *(long *)(param_1 + 0x68);
      break;
    case 3:
      lVar5 = *(long *)(param_1 + 0x78);
      break;
    case 4:
      lVar5 = *(long *)(param_1 + 0x80);
      break;
    default:
      goto switchD_008faf3f_default;
    }
    uVar2 = *(undefined8 *)(lVar5 + 0xc);
    uVar1 = *(undefined2 *)(lVar5 + 0x14);
    *puVar4 = *(undefined4 *)(lVar5 + 8);
    *(undefined8 *)(puVar4 + 1) = uVar2;
    *(undefined2 *)(puVar4 + 3) = uVar1;
  }
  else if (param_2 == 2) {
    uVar2 = *param_4;
    switch(param_3) {
    case 0:
      QBrush::QBrush((QBrush *)&local_28,uVar2,1);
      uVar2 = *(undefined8 *)(param_1 + 0x60);
      *(ulong *)(param_1 + 0x60) = CONCAT44(uStack_24,local_28);
      local_28 = (undefined4)uVar2;
      uStack_24 = (undefined4)((ulong)uVar2 >> 0x20);
      QBrush::~QBrush((QBrush *)&local_28);
      break;
    case 1:
      QBrush::QBrush((QBrush *)&local_28,uVar2,1);
      uVar2 = *(undefined8 *)(param_1 + 0x70);
      *(ulong *)(param_1 + 0x70) = CONCAT44(uStack_24,local_28);
      local_28 = (undefined4)uVar2;
      uStack_24 = (undefined4)((ulong)uVar2 >> 0x20);
      QBrush::~QBrush((QBrush *)&local_28);
      break;
    case 2:
      QBrush::QBrush((QBrush *)&local_28,uVar2,1);
      uVar2 = *(undefined8 *)(param_1 + 0x68);
      *(ulong *)(param_1 + 0x68) = CONCAT44(uStack_24,local_28);
      local_28 = (undefined4)uVar2;
      uStack_24 = (undefined4)((ulong)uVar2 >> 0x20);
      QBrush::~QBrush((QBrush *)&local_28);
      break;
    case 3:
      QBrush::QBrush((QBrush *)&local_28,uVar2,1);
      uVar2 = *(undefined8 *)(param_1 + 0x78);
      *(ulong *)(param_1 + 0x78) = CONCAT44(uStack_24,local_28);
      local_28 = (undefined4)uVar2;
      uStack_24 = (undefined4)((ulong)uVar2 >> 0x20);
      QBrush::~QBrush((QBrush *)&local_28);
      break;
    case 4:
      QBrush::QBrush((QBrush *)&local_28,uVar2,1);
      uVar2 = *(undefined8 *)(param_1 + 0x80);
      *(ulong *)(param_1 + 0x80) = CONCAT44(uStack_24,local_28);
      local_28 = (undefined4)uVar2;
      uStack_24 = (undefined4)((ulong)uVar2 >> 0x20);
      QBrush::~QBrush((QBrush *)&local_28);
    }
  }
switchD_008faf3f_default:
  return;
}


// ==== entry=008fb0b0 orig=FUN_008fb0b0 size=66 name=SlipButton_qt_metacast ====

char * SlipButton_qt_metacast(char *param_1,char *param_2)

{
  int iVar1;
  char *pcVar2;
  
  if (param_2 == (char *)0x0) {
    return (char *)0x0;
  }
  iVar1 = strcmp(param_2,"SlipButton");
  if (iVar1 == 0) {
    return param_1;
  }
  pcVar2 = (char *)QWidget::qt_metacast(param_1);
  return pcVar2;
}


// ==== entry=008fb0f2 orig=FUN_008fb0f2 size=176 name=SlipButton_qt_metacall ====

ulong SlipButton_qt_metacall(undefined8 param_1,int param_2,undefined8 param_3,undefined8 *param_4)

{
  int iVar1;
  ulong uVar2;
  
  uVar2 = QWidget::qt_metacall();
  iVar1 = (int)uVar2;
  if (-1 < iVar1) {
    if (param_2 == 0) {
      if (iVar1 < 2) {
        FUN_008faee4(param_1,0,uVar2 & 0xffffffff,param_4);
        uVar2 = uVar2 & 0xffffffff;
      }
    }
    else {
      if (param_2 != 0xc) {
        if ((param_2 - 1U < 3) || (param_2 == 0xb)) {
          FUN_008faee4(param_1,param_2,uVar2 & 0xffffffff,param_4);
          return (ulong)(iVar1 - 5);
        }
        if ((((param_2 != 4) && (param_2 != 5)) && (param_2 != 6)) &&
           ((param_2 != 7 && (param_2 != 8)))) {
          return uVar2;
        }
        return (ulong)(iVar1 - 5);
      }
      if (iVar1 < 2) {
        *(undefined4 *)*param_4 = 0xffffffff;
      }
    }
    uVar2 = (ulong)((int)uVar2 - 2);
  }
  return uVar2;
}


// ==== entry=008fb1a2 name=FUN_008fb1a2 size=1 ====

void FUN_008fb1a2(void)

{
  return;
}


// ==== entry=008fb1a4 name=FUN_008fb1a4 size=24 ====

undefined ** FUN_008fb1a4(long param_1)

{
  undefined **ppuVar1;
  
  if (*(long *)(*(long *)(param_1 + 8) + 0x28) != 0) {
    ppuVar1 = (undefined **)QObjectData::dynamicMetaObject();
    return ppuVar1;
  }
  return &PTR_PTR_0119d880;
}


// ==== entry=008fb1bc orig=FUN_008fb1bc size=66 name=s_TablePanel_8fb1bc ====

undefined8 s_TablePanel_8fb1bc(undefined8 param_1,char *param_2)

{
  int iVar1;
  undefined8 uVar2;
  
  if (param_2 == (char *)0x0) {
    return 0;
  }
  iVar1 = strcmp(param_2,"TablePanel");
  if (iVar1 == 0) {
    return param_1;
  }
  uVar2 = ButtonBarPanel_qt_metacast(param_1,param_2);
  return uVar2;
}


// ==== entry=008fb1fe orig=FUN_008fb1fe size=5 name=ButtonBarPanel_qt_metacall ====

ulong ButtonBarPanel_qt_metacall
                (undefined8 param_1,int param_2,undefined8 param_3,undefined8 *param_4)

{
  int iVar1;
  ulong uVar2;
  
  uVar2 = QFrame::qt_metacall();
  iVar1 = (int)uVar2;
  if (-1 < iVar1) {
    if (param_2 == 0) {
      if (iVar1 < 0x11) {
        FUN_008ef9ea(param_1,0,uVar2 & 0xffffffff,param_4);
        uVar2 = uVar2 & 0xffffffff;
      }
    }
    else {
      if (param_2 != 0xc) {
        return uVar2;
      }
      if (iVar1 < 0x11) {
        *(undefined4 *)*param_4 = 0xffffffff;
      }
    }
    uVar2 = (ulong)((int)uVar2 - 0x11);
  }
  return uVar2;
}


// ==== entry=008fb204 name=FUN_008fb204 size=29 ====

void FUN_008fb204(QFrame *param_1)

{
  *(undefined ***)param_1 = &ButtonBarPanel_vtable;
  *(undefined ***)(param_1 + 0x10) = &PTR_FUN_011933e8;
  QFrame::~QFrame(param_1);
  return;
}


// ==== entry=008fb221 name=FUN_008fb221 size=33 ====

void FUN_008fb221(undefined8 *param_1)

{
  param_1[-2] = &ButtonBarPanel_vtable;
  *param_1 = &PTR_FUN_011933e8;
  QFrame::~QFrame((QFrame *)(param_1 + -2));
  return;
}


// ==== entry=008fb242 name=FUN_008fb242 size=47 ====

void FUN_008fb242(QFrame *param_1)

{
  *(undefined ***)param_1 = &ButtonBarPanel_vtable;
  *(undefined ***)(param_1 + 0x10) = &PTR_FUN_011933e8;
  QFrame::~QFrame(param_1);
  operator_delete(param_1,0x48);
  return;
}


// ==== entry=008fb271 name=FUN_008fb271 size=51 ====

void FUN_008fb271(undefined8 *param_1)

{
  param_1[-2] = &ButtonBarPanel_vtable;
  *param_1 = &PTR_FUN_011933e8;
  QFrame::~QFrame((QFrame *)(param_1 + -2));
  operator_delete((QFrame *)(param_1 + -2),0x48);
  return;
}


// ==== entry=008fb2b0 name=FUN_008fb2b0 size=24 ====

undefined ** FUN_008fb2b0(long param_1)

{
  undefined **ppuVar1;
  
  if (*(long *)(*(long *)(param_1 + 8) + 0x28) != 0) {
    ppuVar1 = (undefined **)QObjectData::dynamicMetaObject();
    return ppuVar1;
  }
  return &PTR_staticMetaObject_0119dc40;
}


// ==== entry=008fb2c8 name=FUN_008fb2c8 size=16 ====

void FUN_008fb2c8(QObject *param_1)

{
  QMetaObject::activate(param_1,(QMetaObject *)&PTR_staticMetaObject_0119dc40,0,(void **)0x0);
  return;
}


// ==== entry=008fb2d8 name=FUN_008fb2d8 size=42 ====

void FUN_008fb2d8(QObject *param_1,undefined8 param_2)

{
  void *local_18;
  undefined8 local_10;
  
  local_18 = (void *)0x0;
  local_10 = param_2;
  QMetaObject::activate(param_1,(QMetaObject *)&PTR_staticMetaObject_0119dc40,1,&local_18);
  return;
}


// ==== entry=008fb302 name=FUN_008fb302 size=294 ====

void FUN_008fb302(undefined8 param_1,int param_2,int param_3,undefined8 *param_4)

{
  long *plVar1;
  undefined1 *puVar2;
  undefined1 uVar3;
  QArrayData *local_10;
  
  if (param_2 == 0) {
    if (param_3 == 1) {
      FUN_008fb2d8(param_1,param_4[1]);
    }
    else if (param_3 < 2) {
      if (param_3 == 0) {
        FUN_008fb2c8();
      }
    }
    else if (param_3 == 2) {
      local_10 = *(QArrayData **)param_4[1];
      if ((*(int *)local_10 != 0) && (*(int *)local_10 != -1)) {
        LOCK();
        *(int *)local_10 = *(int *)local_10 + 1;
        UNLOCK();
      }
                    /* try { // try from 008fb3d0 to 008fb3d4 has its CatchHandler @ 008fb428 */
      FUN_0058b440(param_1,&local_10);
      if (*(int *)local_10 != 0) {
        if (*(int *)local_10 == -1) {
          return;
        }
        LOCK();
        *(int *)local_10 = *(int *)local_10 + -1;
        UNLOCK();
        if (*(int *)local_10 != 0) {
          return;
        }
      }
      QArrayData::deallocate(local_10,2,8);
    }
    else if (param_3 == 3) {
      FUN_0058c770(param_1,*(undefined4 *)param_4[1]);
    }
  }
  else if (param_2 == 10) {
    plVar1 = (long *)param_4[1];
    if (((code *)*plVar1 == FUN_008fb2c8) && (plVar1[1] == 0)) {
      *(undefined4 *)*param_4 = 0;
    }
    else if (((code *)*plVar1 == FUN_008fb2d8) && (plVar1[1] == 0)) {
      *(undefined4 *)*param_4 = 1;
    }
  }
  else if (param_2 == 1) {
    if (param_3 == 0) {
      puVar2 = (undefined1 *)*param_4;
      uVar3 = FUN_0058c744();
      *puVar2 = uVar3;
    }
  }
  else if ((param_2 == 2) && (param_3 == 0)) {
    FUN_0058c1c6(param_1,*(undefined1 *)*param_4);
  }
  return;
}


// ==== entry=008fb430 orig=FUN_008fb430 size=66 name=s_TreeView_8fb430 ====

char * s_TreeView_8fb430(char *param_1,char *param_2)

{
  int iVar1;
  char *pcVar2;
  
  if (param_2 == (char *)0x0) {
    return (char *)0x0;
  }
  iVar1 = strcmp(param_2,"TreeView");
  if (iVar1 == 0) {
    return param_1;
  }
  pcVar2 = (char *)QTreeView::qt_metacast(param_1);
  return pcVar2;
}


// ==== entry=008fb472 name=FUN_008fb472 size=176 ====

ulong FUN_008fb472(undefined8 param_1,int param_2,undefined8 param_3,undefined8 *param_4)

{
  int iVar1;
  ulong uVar2;
  
  uVar2 = QTreeView::qt_metacall();
  iVar1 = (int)uVar2;
  if (-1 < iVar1) {
    if (param_2 == 0) {
      if (iVar1 < 4) {
        FUN_008fb302(param_1,0,uVar2 & 0xffffffff,param_4);
        uVar2 = uVar2 & 0xffffffff;
      }
    }
    else {
      if (param_2 != 0xc) {
        if ((param_2 - 1U < 3) || (param_2 == 0xb)) {
          FUN_008fb302(param_1,param_2,uVar2 & 0xffffffff,param_4);
          return (ulong)(iVar1 - 1);
        }
        if ((((param_2 != 4) && (param_2 != 5)) && (param_2 != 6)) &&
           ((param_2 != 7 && (param_2 != 8)))) {
          return uVar2;
        }
        return (ulong)(iVar1 - 1);
      }
      if (iVar1 < 4) {
        *(undefined4 *)*param_4 = 0xffffffff;
      }
    }
    uVar2 = (ulong)((int)uVar2 - 4);
  }
  return uVar2;
}


// ==== entry=008fb530 orig=FUN_008fb530 size=24 name=TabGroup_metaObject ====

undefined ** TabGroup_metaObject(long param_1)

{
  undefined **ppuVar1;
  
  if (*(long *)(*(long *)(param_1 + 8) + 0x28) != 0) {
    ppuVar1 = (undefined **)QObjectData::dynamicMetaObject();
    return ppuVar1;
  }
  return &PTR_staticMetaObject_0119dea0;
}


// ==== entry=008fb548 name=FUN_008fb548 size=19 ====

void FUN_008fb548(QObject *param_1)

{
  QMetaObject::activate(param_1,(QMetaObject *)&PTR_staticMetaObject_0119dea0,1,(void **)0x0);
  return;
}


// ==== entry=008fb55c name=FUN_008fb55c size=19 ====

void FUN_008fb55c(QObject *param_1)

{
  QMetaObject::activate(param_1,(QMetaObject *)&PTR_staticMetaObject_0119dea0,2,(void **)0x0);
  return;
}


// ==== entry=008fb570 name=FUN_008fb570 size=19 ====

void FUN_008fb570(QObject *param_1)

{
  QMetaObject::activate(param_1,(QMetaObject *)&PTR_staticMetaObject_0119dea0,5,(void **)0x0);
  return;
}


// ==== entry=008fb584 name=FUN_008fb584 size=19 ====

void FUN_008fb584(QObject *param_1)

{
  QMetaObject::activate(param_1,(QMetaObject *)&PTR_staticMetaObject_0119dea0,7,(void **)0x0);
  return;
}


// ==== entry=008fb598 name=FUN_008fb598 size=19 ====

void FUN_008fb598(QObject *param_1)

{
  QMetaObject::activate(param_1,(QMetaObject *)&PTR_staticMetaObject_0119dea0,8,(void **)0x0);
  return;
}


// ==== entry=008fb5ac name=FUN_008fb5ac size=51 ====

void FUN_008fb5ac(QObject *param_1,undefined4 param_2)

{
  undefined4 local_1c;
  void *local_18;
  undefined4 *local_10;
  
  local_18 = (void *)0x0;
  local_10 = &local_1c;
  local_1c = param_2;
  QMetaObject::activate(param_1,(QMetaObject *)&PTR_staticMetaObject_0119dea0,0,&local_18);
  return;
}


// ==== entry=008fb5e0 name=FUN_008fb5e0 size=54 ====

void FUN_008fb5e0(QObject *param_1,undefined4 param_2)

{
  undefined4 local_1c;
  void *local_18;
  undefined4 *local_10;
  
  local_18 = (void *)0x0;
  local_10 = &local_1c;
  local_1c = param_2;
  QMetaObject::activate(param_1,(QMetaObject *)&PTR_staticMetaObject_0119dea0,3,&local_18);
  return;
}


// ==== entry=008fb616 name=FUN_008fb616 size=54 ====

void FUN_008fb616(QObject *param_1,undefined4 param_2)

{
  undefined4 local_1c;
  void *local_18;
  undefined4 *local_10;
  
  local_18 = (void *)0x0;
  local_10 = &local_1c;
  local_1c = param_2;
  QMetaObject::activate(param_1,(QMetaObject *)&PTR_staticMetaObject_0119dea0,6,&local_18);
  return;
}


// ==== entry=008fb64c name=FUN_008fb64c size=68 ====

void FUN_008fb64c(QObject *param_1,undefined4 param_2,undefined1 param_3)

{
  undefined1 local_30 [4];
  undefined4 local_2c;
  void *local_28;
  undefined4 *local_20;
  undefined1 *local_18;
  
  local_28 = (void *)0x0;
  local_20 = &local_2c;
  local_18 = local_30;
  local_30[0] = param_3;
  local_2c = param_2;
  QMetaObject::activate(param_1,(QMetaObject *)&PTR_staticMetaObject_0119dea0,4,&local_28);
  return;
}


// ==== entry=008fb690 name=FUN_008fb690 size=55 ====

void FUN_008fb690(QObject *param_1,undefined1 param_2)

{
  undefined1 local_1c [4];
  void *local_18;
  undefined1 *local_10;
  
  local_18 = (void *)0x0;
  local_10 = local_1c;
  local_1c[0] = param_2;
  QMetaObject::activate(param_1,(QMetaObject *)&PTR_staticMetaObject_0119dea0,9,&local_18);
  return;
}


// ==== entry=008fb6c8 name=FUN_008fb6c8 size=534 ====

void FUN_008fb6c8(undefined8 param_1,int param_2,int param_3,undefined8 *param_4)

{
  long *plVar1;
  code *pcVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  
  if (param_2 == 0) {
    switch(param_3) {
    case 0:
      FUN_008fb5ac(param_1,*(undefined4 *)param_4[1]);
      return;
    case 1:
      FUN_008fb548();
      return;
    case 2:
      FUN_008fb55c();
      return;
    case 3:
      FUN_008fb5e0(param_1,*(undefined4 *)param_4[1]);
      return;
    case 4:
      FUN_008fb64c(param_1,*(undefined4 *)param_4[1],*(undefined1 *)param_4[2]);
      return;
    case 5:
      FUN_008fb570();
      return;
    case 6:
      FUN_008fb616(param_1,*(undefined4 *)param_4[1]);
      return;
    case 7:
      FUN_008fb584();
      return;
    case 8:
      FUN_008fb598();
      return;
    case 9:
      FUN_008fb690(param_1,*(undefined1 *)param_4[1]);
      return;
    }
  }
  else if (param_2 == 10) {
    puVar3 = (undefined4 *)*param_4;
    plVar1 = (long *)param_4[1];
    pcVar2 = (code *)*plVar1;
    if ((pcVar2 == FUN_008fb5ac) && (plVar1[1] == 0)) {
      *puVar3 = 0;
      return;
    }
    if (pcVar2 == FUN_008fb548) {
      if (plVar1[1] == 0) {
        *puVar3 = 1;
        return;
      }
    }
    else if ((pcVar2 == FUN_008fb55c) && (plVar1[1] == 0)) {
      *puVar3 = 2;
      return;
    }
    if ((pcVar2 == FUN_008fb5e0) && (plVar1[1] == 0)) {
      *puVar3 = 3;
      return;
    }
    if ((pcVar2 == FUN_008fb64c) && (plVar1[1] == 0)) {
      *puVar3 = 4;
      return;
    }
    if ((pcVar2 == FUN_008fb570) && (plVar1[1] == 0)) {
      *puVar3 = 5;
      return;
    }
    if ((pcVar2 == FUN_008fb616) && (plVar1[1] == 0)) {
      *puVar3 = 6;
      return;
    }
    if (pcVar2 == FUN_008fb584) {
      if (plVar1[1] == 0) {
        *puVar3 = 7;
        return;
      }
    }
    else if ((pcVar2 == FUN_008fb598) && (plVar1[1] == 0)) {
      *puVar3 = 8;
      return;
    }
    if ((pcVar2 == FUN_008fb690) && (plVar1[1] == 0)) {
      *puVar3 = 9;
      return;
    }
  }
  else {
    if (param_2 == 1) {
      puVar3 = (undefined4 *)*param_4;
      if (param_3 == 0) {
        uVar4 = FUN_005ab886();
        *puVar3 = uVar4;
        return;
      }
      if (param_3 == 1) {
        uVar4 = FUN_005aba1c();
        *puVar3 = uVar4;
      }
      return;
    }
    if (param_2 == 2) {
      if (param_3 == 0) {
        FUN_005ab88a(param_1,*(undefined4 *)*param_4);
        return;
      }
      if (param_3 == 1) {
        FUN_005aba20(param_1,*(undefined4 *)*param_4);
        return;
      }
      return;
    }
  }
  return;
}


// ==== entry=008fb8de orig=FUN_008fb8de size=66 name=TabGroup_qt_metacast ====

char * TabGroup_qt_metacast(char *param_1,char *param_2)

{
  int iVar1;
  char *pcVar2;
  
  if (param_2 == (char *)0x0) {
    return (char *)0x0;
  }
  iVar1 = strcmp(param_2,"TabGroup");
  if (iVar1 == 0) {
    return param_1;
  }
  pcVar2 = (char *)QFrame::qt_metacast(param_1);
  return pcVar2;
}


// ==== entry=008fb920 orig=FUN_008fb920 size=174 name=TabGroup_qt_metacall ====

ulong TabGroup_qt_metacall(undefined8 param_1,int param_2,undefined8 param_3,undefined8 *param_4)

{
  int iVar1;
  ulong uVar2;
  
  uVar2 = QFrame::qt_metacall();
  iVar1 = (int)uVar2;
  if (-1 < iVar1) {
    if (param_2 == 0) {
      if (iVar1 < 10) {
        FUN_008fb6c8(param_1,0,uVar2 & 0xffffffff,param_4);
        uVar2 = uVar2 & 0xffffffff;
      }
    }
    else {
      if (param_2 != 0xc) {
        if ((param_2 - 1U < 3) || (param_2 == 0xb)) {
          FUN_008fb6c8(param_1,param_2,uVar2 & 0xffffffff,param_4);
          return (ulong)(iVar1 - 2);
        }
        if ((((param_2 != 4) && (param_2 != 5)) && (param_2 != 6)) &&
           ((param_2 != 7 && (param_2 != 8)))) {
          return uVar2;
        }
        return (ulong)(iVar1 - 2);
      }
      if (iVar1 < 10) {
        *(undefined4 *)*param_4 = 0xffffffff;
      }
    }
    uVar2 = (ulong)((int)uVar2 - 10);
  }
  return uVar2;
}


// ==== entry=008fb9d0 orig=FUN_008fb9d0 size=24 name=ToolButton_metaObject ====

undefined ** ToolButton_metaObject(long param_1)

{
  undefined **ppuVar1;
  
  if (*(long *)(*(long *)(param_1 + 8) + 0x28) != 0) {
    ppuVar1 = (undefined **)QObjectData::dynamicMetaObject();
    return ppuVar1;
  }
  return &PTR_staticMetaObject_0119e100;
}


// ==== entry=008fb9e8 name=FUN_008fb9e8 size=196 ====

void FUN_008fb9e8(long param_1,int param_2,int param_3,undefined8 *param_4)

{
  int iVar1;
  QArrayData *pQVar2;
  undefined8 uVar3;
  undefined8 local_20;
  
  if (param_2 == 1) {
    param_4 = (undefined8 *)*param_4;
    if (param_3 == 1) {
      uVar3 = FUN_005d4f50();
      *param_4 = uVar3;
    }
    else if (param_3 == 2) {
      QAbstractButton::text();
      pQVar2 = (QArrayData *)*param_4;
      *param_4 = local_20;
      if (*(int *)pQVar2 != 0) {
        if (*(int *)pQVar2 == -1) {
          return;
        }
        LOCK();
        iVar1 = *(int *)pQVar2;
        *(int *)pQVar2 = *(int *)pQVar2 + -1;
        UNLOCK();
        if (iVar1 != 1) {
          return;
        }
      }
      QArrayData::deallocate(pQVar2,2,8);
    }
    else if (param_3 == 0) {
      *(undefined4 *)param_4 = *(undefined4 *)(param_1 + 0x30);
    }
  }
  else if (param_2 == 2) {
    if (param_3 == 1) {
      FUN_005d4f8a(param_1,*(undefined8 *)*param_4);
    }
    else if (param_3 == 2) {
      FUN_005d4f90();
    }
    else if (param_3 == 0) {
      FUN_005d4f82(param_1,*(undefined4 *)*param_4);
    }
  }
  return;
}


// ==== entry=008fbaac orig=FUN_008fbaac size=66 name=ToolButton_qt_metacast ====

char * ToolButton_qt_metacast(char *param_1,char *param_2)

{
  int iVar1;
  char *pcVar2;
  
  if (param_2 == (char *)0x0) {
    return (char *)0x0;
  }
  iVar1 = strcmp(param_2,"ToolButton");
  if (iVar1 == 0) {
    return param_1;
  }
  pcVar2 = (char *)QToolButton::qt_metacast(param_1);
  return pcVar2;
}


// ==== entry=008fbaee orig=FUN_008fbaee size=119 name=ToolButton_qt_metacall ====

ulong ToolButton_qt_metacall(undefined8 param_1,int param_2,undefined8 param_3,undefined8 param_4)

{
  int iVar1;
  ulong uVar2;
  
  uVar2 = QToolButton::qt_metacall();
  iVar1 = (int)uVar2;
  if (-1 < iVar1) {
    if ((param_2 - 1U < 3) || (param_2 == 0xb)) {
      FUN_008fb9e8(param_1,param_2,uVar2 & 0xffffffff,param_4);
      return (ulong)(iVar1 - 3);
    }
    if ((((param_2 == 4) || (param_2 == 5)) || (param_2 == 6)) || ((param_2 == 7 || (param_2 == 8)))
       ) {
      return (ulong)(iVar1 - 3);
    }
  }
  return uVar2;
}


// ==== entry=008fbb66 orig=FUN_008fbb66 size=29 name=ToolButton_dtor ====

void ToolButton_dtor(QToolButton *param_1)

{
  *(undefined ***)param_1 = &ToolButton_vtable;
  *(undefined ***)(param_1 + 0x10) = &PTR_FUN_0119e0c0;
  QToolButton::~QToolButton(param_1);
  return;
}


// ==== entry=008fbb83 name=FUN_008fbb83 size=33 ====

void FUN_008fbb83(undefined8 *param_1)

{
  param_1[-2] = &ToolButton_vtable;
  *param_1 = &PTR_FUN_0119e0c0;
  QToolButton::~QToolButton((QToolButton *)(param_1 + -2));
  return;
}


// ==== entry=008fbba4 orig=FUN_008fbba4 size=47 name=ToolButton_dtor_deleting ====

void ToolButton_dtor_deleting(QToolButton *param_1)

{
  *(undefined ***)param_1 = &ToolButton_vtable;
  *(undefined ***)(param_1 + 0x10) = &PTR_FUN_0119e0c0;
  QToolButton::~QToolButton(param_1);
  operator_delete(param_1,0x40);
  return;
}


// ==== entry=008fbbd3 name=FUN_008fbbd3 size=51 ====

void FUN_008fbbd3(undefined8 *param_1)

{
  param_1[-2] = &ToolButton_vtable;
  *param_1 = &PTR_FUN_0119e0c0;
  QToolButton::~QToolButton((QToolButton *)(param_1 + -2));
  operator_delete((QToolButton *)(param_1 + -2),0x40);
  return;
}


// ==== entry=008fbc06 name=FUN_008fbc06 size=1 ====

void FUN_008fbc06(void)

{
  return;
}


// ==== entry=008fbc08 name=FUN_008fbc08 size=24 ====

undefined ** FUN_008fbc08(long param_1)

{
  undefined **ppuVar1;
  
  if (*(long *)(*(long *)(param_1 + 8) + 0x28) != 0) {
    ppuVar1 = (undefined **)QObjectData::dynamicMetaObject();
    return ppuVar1;
  }
  return &PTR_staticMetaObject_0119e240;
}


// ==== entry=008fbc20 orig=FUN_008fbc20 size=66 name=s_WidgetDelegate_8fbc20 ====

char * s_WidgetDelegate_8fbc20(char *param_1,char *param_2)

{
  int iVar1;
  char *pcVar2;
  
  if (param_2 == (char *)0x0) {
    return (char *)0x0;
  }
  iVar1 = strcmp(param_2,"WidgetDelegate");
  if (iVar1 == 0) {
    return param_1;
  }
  pcVar2 = (char *)QStyledItemDelegate::qt_metacast(param_1);
  return pcVar2;
}


// ==== entry=008fbc62 orig=FUN_008fbc62 size=5 name=qt_metacall ====

void QStyledItemDelegate::qt_metacall(void)

{
  qt_metacall();
  return;
}


// ==== entry=008fbc70 name=FUN_008fbc70 size=24 ====

undefined ** FUN_008fbc70(long param_1)

{
  undefined **ppuVar1;
  
  if (*(long *)(*(long *)(param_1 + 8) + 0x28) != 0) {
    ppuVar1 = (undefined **)QObjectData::dynamicMetaObject();
    return ppuVar1;
  }
  return &PTR_staticMetaObject_0119e5e0;
}


// ==== entry=008fbc88 name=FUN_008fbc88 size=16 ====

void FUN_008fbc88(QObject *param_1)

{
  QMetaObject::activate(param_1,(QMetaObject *)&PTR_staticMetaObject_0119e5e0,0,(void **)0x0);
  return;
}


// ==== entry=008fbc98 name=FUN_008fbc98 size=54 ====

void FUN_008fbc98(QObject *param_1,undefined4 param_2)

{
  undefined4 local_1c;
  void *local_18;
  undefined4 *local_10;
  
  local_18 = (void *)0x0;
  local_10 = &local_1c;
  local_1c = param_2;
  QMetaObject::activate(param_1,(QMetaObject *)&PTR_staticMetaObject_0119e5e0,1,&local_18);
  return;
}


// ==== entry=008fbcce name=FUN_008fbcce size=96 ====

void FUN_008fbcce(undefined8 param_1,int param_2,int param_3,undefined8 *param_4)

{
  long *plVar1;
  
  if (param_2 == 0) {
    if (param_3 == 0) {
      FUN_008fbc88();
      return;
    }
    if (param_3 == 1) {
      FUN_008fbc98(param_1,*(undefined4 *)param_4[1]);
      return;
    }
    return;
  }
  if (param_2 == 10) {
    plVar1 = (long *)param_4[1];
    if (((code *)*plVar1 == FUN_008fbc88) && (plVar1[1] == 0)) {
      *(undefined4 *)*param_4 = 0;
      return;
    }
    if (((code *)*plVar1 == FUN_008fbc98) && (plVar1[1] == 0)) {
      *(undefined4 *)*param_4 = 1;
      return;
    }
  }
  return;
}


// ==== entry=008fbd2e orig=FUN_008fbd2e size=66 name=s_WidgetList_8fbd2e ====

char * s_WidgetList_8fbd2e(char *param_1,char *param_2)

{
  int iVar1;
  char *pcVar2;
  
  if (param_2 == (char *)0x0) {
    return (char *)0x0;
  }
  iVar1 = strcmp(param_2,"WidgetList");
  if (iVar1 == 0) {
    return param_1;
  }
  pcVar2 = (char *)QListView::qt_metacast(param_1);
  return pcVar2;
}


// ==== entry=008fbd70 name=FUN_008fbd70 size=93 ====

ulong FUN_008fbd70(undefined8 param_1,int param_2,undefined8 param_3,undefined8 *param_4)

{
  int iVar1;
  ulong uVar2;
  
  uVar2 = QListView::qt_metacall();
  iVar1 = (int)uVar2;
  if (-1 < iVar1) {
    if (param_2 == 0) {
      if (iVar1 < 2) {
        FUN_008fbcce(param_1,0,uVar2 & 0xffffffff,param_4);
        uVar2 = uVar2 & 0xffffffff;
      }
    }
    else {
      if (param_2 != 0xc) {
        return uVar2;
      }
      if (iVar1 < 2) {
        *(undefined4 *)*param_4 = 0xffffffff;
      }
    }
    uVar2 = (ulong)((int)uVar2 - 2);
  }
  return uVar2;
}


// ==== entry=008fbdd0 orig=FUN_008fbdd0 size=24 name=EditorView_metaObject ====

undefined ** EditorView_metaObject(long param_1)

{
  undefined **ppuVar1;
  
  if (*(long *)(*(long *)(param_1 + 8) + 0x28) != 0) {
    ppuVar1 = (undefined **)QObjectData::dynamicMetaObject();
    return ppuVar1;
  }
  return &PTR_PTR_0119ede0;
}


// ==== entry=008fbde8 name=FUN_008fbde8 size=16 ====

void FUN_008fbde8(QObject *param_1)

{
  QMetaObject::activate(param_1,(QMetaObject *)&PTR_PTR_0119ede0,0,(void **)0x0);
  return;
}


// ==== entry=008fbdf8 name=FUN_008fbdf8 size=65 ====

void FUN_008fbdf8(QObject *param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 local_30;
  void *local_28;
  undefined8 *local_20;
  undefined8 local_18;
  undefined8 local_10;
  
  local_28 = (void *)0x0;
  local_20 = &local_30;
  local_30 = param_2;
  local_18 = param_3;
  local_10 = param_4;
  QMetaObject::activate(param_1,(QMetaObject *)&PTR_PTR_0119ede0,1,&local_28);
  return;
}


// ==== entry=008fbe3a name=FUN_008fbe3a size=42 ====

void FUN_008fbe3a(QObject *param_1,undefined8 param_2)

{
  void *local_18;
  undefined8 local_10;
  
  local_18 = (void *)0x0;
  local_10 = param_2;
  QMetaObject::activate(param_1,(QMetaObject *)&PTR_PTR_0119ede0,2,&local_18);
  return;
}


// ==== entry=008fbe64 name=FUN_008fbe64 size=928 ====

void FUN_008fbe64(long param_1,int param_2,uint param_3,long *param_4)

{
  undefined4 *puVar1;
  long *plVar2;
  code *pcVar3;
  QArrayData *pQVar4;
  undefined8 *puVar5;
  undefined8 *puVar6;
  undefined1 uVar7;
  undefined8 uVar8;
  undefined8 *local_28;
  QArrayData *local_20 [2];
  
  if (param_2 != 0) {
    if (param_2 == 10) {
      puVar1 = (undefined4 *)*param_4;
      plVar2 = (long *)param_4[1];
      pcVar3 = (code *)*plVar2;
      if ((pcVar3 == FUN_008fbde8) && (plVar2[1] == 0)) {
        *puVar1 = 0;
        return;
      }
      if ((pcVar3 == FUN_008fbdf8) && (plVar2[1] == 0)) {
        *puVar1 = 1;
        return;
      }
      if ((pcVar3 == FUN_008fbe3a) && (plVar2[1] == 0)) {
        *puVar1 = 2;
        return;
      }
    }
    return;
  }
  if (0x14 < param_3) {
    return;
  }
  switch(param_3) {
  case 0:
    FUN_008fbde8();
    break;
  case 1:
    FUN_008fbdf8(param_1,*(undefined8 *)param_4[1],param_4[2],param_4[3]);
    break;
  case 2:
    FUN_008fbe3a(param_1,param_4[1]);
    break;
  case 3:
    uVar7 = FUN_008c5d72(param_1 + 0x100);
    if ((undefined1 *)*param_4 != (undefined1 *)0x0) {
      *(undefined1 *)*param_4 = uVar7;
    }
    break;
  case 4:
    uVar7 = FUN_008c5c16(param_1 + 0x100,*(undefined1 *)param_4[1]);
    if ((undefined1 *)*param_4 != (undefined1 *)0x0) {
      *(undefined1 *)*param_4 = uVar7;
    }
    break;
  case 5:
    uVar7 = FUN_008c5c16(param_1 + 0x100,0);
    if ((undefined1 *)*param_4 != (undefined1 *)0x0) {
      *(undefined1 *)*param_4 = uVar7;
    }
    break;
  case 6:
    FUN_008c6cc2(param_1 + 0x100,param_4[1]);
    break;
  case 7:
    FUN_008c53f8(local_20,param_1 + 0x100);
    puVar5 = (undefined8 *)*param_4;
    goto joined_r0x008fbff0;
  case 8:
    uVar7 = FUN_008c56f2(param_1 + 0x100);
    if ((undefined1 *)*param_4 != (undefined1 *)0x0) {
      *(undefined1 *)*param_4 = uVar7;
    }
    break;
  case 9:
    FUN_008c55bc(local_20,param_1 + 0x100);
    puVar5 = (undefined8 *)*param_4;
    goto joined_r0x008fbff0;
  case 10:
    FUN_008c5e24(param_1 + 0x100,param_4[1]);
    break;
  case 0xb:
    FUN_008c5e56(param_1 + 0x100,param_4[1]);
    break;
  case 0xc:
    s_SessionNotificationMessage_8c6f48(&local_28,param_1 + 0x100,param_4[1]);
    puVar6 = local_28;
    puVar5 = (undefined8 *)*param_4;
    if (puVar5 != (undefined8 *)0x0) {
      local_28 = &QListData::shared_null;
      local_20[0] = (QArrayData *)*puVar5;
      *puVar5 = puVar6;
      FUN_005ca570(local_20);
    }
    FUN_005ca570(&local_28);
    break;
  case 0xd:
    FUN_008c5e88((QIcon *)local_20,param_1 + 0x100);
    puVar5 = (undefined8 *)*param_4;
    if (puVar5 != (undefined8 *)0x0) {
      pQVar4 = (QArrayData *)*puVar5;
      *puVar5 = local_20[0];
      local_20[0] = pQVar4;
    }
    QIcon::~QIcon((QIcon *)local_20);
    break;
  case 0xe:
    FUN_008c5ecc(local_20,param_1 + 0x100);
    puVar5 = (undefined8 *)*param_4;
    goto joined_r0x008fbff0;
  case 0xf:
    FUN_008c5578(local_20,param_1 + 0x100);
    puVar5 = (undefined8 *)*param_4;
    goto joined_r0x008fbff0;
  case 0x10:
    FUN_005e42e0(local_20,param_1);
    puVar5 = (undefined8 *)*param_4;
joined_r0x008fbff0:
    if (puVar5 != (undefined8 *)0x0) {
      pQVar4 = (QArrayData *)*puVar5;
      *puVar5 = local_20[0];
      local_20[0] = pQVar4;
    }
    if (*(int *)local_20[0] != 0) {
      if (*(int *)local_20[0] == -1) {
        return;
      }
      LOCK();
      *(int *)local_20[0] = *(int *)local_20[0] + -1;
      UNLOCK();
      if (*(int *)local_20[0] != 0) {
        return;
      }
    }
    QArrayData::deallocate(local_20[0],2,8);
    break;
  case 0x11:
    uVar8 = s_FileErrorMessage_5e7442(param_1,param_4[1],*(undefined8 *)param_4[2]);
    if ((undefined8 *)*param_4 != (undefined8 *)0x0) {
      *(undefined8 *)*param_4 = uVar8;
    }
    break;
  case 0x12:
    uVar7 = *(undefined1 *)param_4[2];
    local_20[0] = *(QArrayData **)param_4[1];
    if ((*(int *)local_20[0] != 0) && (*(int *)local_20[0] != -1)) {
      LOCK();
      *(int *)local_20[0] = *(int *)local_20[0] + 1;
      UNLOCK();
    }
                    /* try { // try from 008fc1e8 to 008fc1ec has its CatchHandler @ 008fc204 */
    s_FileReloadMessage_5e6c92(param_1,local_20,uVar7);
    goto LAB_008fbf2d;
  case 0x13:
    local_20[0] = *(QArrayData **)param_4[1];
    if ((*(int *)local_20[0] != 0) && (*(int *)local_20[0] != -1)) {
      LOCK();
      *(int *)local_20[0] = *(int *)local_20[0] + 1;
      UNLOCK();
    }
                    /* try { // try from 008fbf28 to 008fbf2c has its CatchHandler @ 008fc20c */
    s_FileReloadMessage_5e6c92(param_1,local_20,1);
LAB_008fbf2d:
    if (*(int *)local_20[0] != 0) {
      if (*(int *)local_20[0] == -1) {
        return;
      }
      LOCK();
      *(int *)local_20[0] = *(int *)local_20[0] + -1;
      UNLOCK();
      if (*(int *)local_20[0] != 0) {
        return;
      }
    }
    QArrayData::deallocate(local_20[0],2,8);
    break;
  case 0x14:
    FUN_005e267e(param_1,param_4[1]);
  }
  return;
}


// ==== entry=008fc214 orig=FUN_008fc214 size=107 name=EditorView_qt_metacast ====

long EditorView_qt_metacast(long param_1,byte *param_2)

{
  int iVar1;
  long lVar2;
  byte *pbVar3;
  byte *pbVar4;
  bool bVar5;
  bool bVar6;
  byte bVar7;
  
  bVar7 = 0;
  if (param_2 == (byte *)0x0) {
    return 0;
  }
  iVar1 = strcmp((char *)param_2,"EditorView");
  bVar5 = false;
  if (iVar1 == 0) {
    return param_1;
  }
  lVar2 = 8;
  bVar6 = false;
  pbVar3 = param_2;
  pbVar4 = &DAT_00ccb890;
  do {
    if (lVar2 == 0) break;
    lVar2 = lVar2 + -1;
    bVar5 = *pbVar3 < *pbVar4;
    bVar6 = *pbVar3 == *pbVar4;
    pbVar3 = pbVar3 + (ulong)bVar7 * -2 + 1;
    pbVar4 = pbVar4 + (ulong)bVar7 * -2 + 1;
  } while (bVar6);
  if ((!bVar5 && !bVar6) == bVar5) {
    return param_1 + 0x100;
  }
  lVar2 = TextView_dtor(param_1,param_2);
  return lVar2;
}


// ==== entry=008fc280 orig=FUN_008fc280 size=93 name=EditorView_qt_metacall ====

ulong EditorView_qt_metacall(undefined8 param_1,int param_2,undefined8 param_3,undefined8 *param_4)

{
  int iVar1;
  ulong uVar2;
  
  uVar2 = TextView_dtor_deleting();
  iVar1 = (int)uVar2;
  if (-1 < iVar1) {
    if (param_2 == 0) {
      if (iVar1 < 0x15) {
        FUN_008fbe64(param_1,0,uVar2 & 0xffffffff,param_4);
        uVar2 = uVar2 & 0xffffffff;
      }
    }
    else {
      if (param_2 != 0xc) {
        return uVar2;
      }
      if (iVar1 < 0x15) {
        *(undefined4 *)*param_4 = 0xffffffff;
      }
    }
    uVar2 = (ulong)((int)uVar2 - 0x15);
  }
  return uVar2;
}


// ==== entry=008fc2e0 name=FUN_008fc2e0 size=24 ====

undefined ** FUN_008fc2e0(long param_1)

{
  undefined **ppuVar1;
  
  if (*(long *)(*(long *)(param_1 + 8) + 0x28) != 0) {
    ppuVar1 = (undefined **)QObjectData::dynamicMetaObject();
    return ppuVar1;
  }
  return &PTR_PTR_0119f0e0;
}


// ==== entry=008fc2f8 name=FUN_008fc2f8 size=57 ====

void FUN_008fc2f8(QObject *param_1,undefined1 param_2,undefined8 param_3)

{
  undefined1 local_2c [4];
  void *local_28;
  undefined1 *local_20;
  undefined8 local_18;
  
  local_28 = (void *)0x0;
  local_20 = local_2c;
  local_2c[0] = param_2;
  local_18 = param_3;
  QMetaObject::activate(param_1,(QMetaObject *)&PTR_PTR_0119f0e0,0,&local_28);
  return;
}


// ==== entry=008fc332 name=FUN_008fc332 size=60 ====

void FUN_008fc332(QObject *param_1,undefined8 param_2,undefined8 param_3)

{
  undefined8 local_30;
  void *local_28;
  undefined8 local_20;
  undefined8 *local_18;
  
  local_28 = (void *)0x0;
  local_18 = &local_30;
  local_30 = param_3;
  local_20 = param_2;
  QMetaObject::activate(param_1,(QMetaObject *)&PTR_PTR_0119f0e0,1,&local_28);
  return;
}


// ==== entry=008fc36e name=FUN_008fc36e size=480 ====

void FUN_008fc36e(undefined8 param_1,int param_2,undefined4 param_3,long *param_4)

{
  long *plVar1;
  undefined8 *puVar2;
  QArrayData *pQVar3;
  undefined8 uVar4;
  QArrayData **ppQVar5;
  QArrayData *local_28;
  QArrayData *local_20;
  
  if (param_2 != 0) {
    if (param_2 == 10) {
      plVar1 = (long *)param_4[1];
      if (((code *)*plVar1 == FUN_008fc2f8) && (plVar1[1] == 0)) {
        *(undefined4 *)*param_4 = 0;
        return;
      }
      if (((code *)*plVar1 == FUN_008fc332) && (plVar1[1] == 0)) {
        *(undefined4 *)*param_4 = 1;
        return;
      }
    }
switchD_008fc392_default:
    return;
  }
  switch(param_3) {
  case 0:
    FUN_008fc2f8(param_1,*(undefined1 *)param_4[1],param_4[2]);
    return;
  case 1:
    uVar4 = *(undefined8 *)param_4[2];
    ppQVar5 = &local_20;
    FUN_00533df0(ppQVar5,param_4[1]);
                    /* try { // try from 008fc4c7 to 008fc4cb has its CatchHandler @ 008fc55e */
    FUN_008fc332(param_1,ppQVar5,uVar4);
    goto LAB_008fc4cc;
  case 2:
    uVar4 = FUN_005eb4fc();
    if ((undefined8 *)*param_4 == (undefined8 *)0x0) {
      return;
    }
    *(undefined8 *)*param_4 = uVar4;
    return;
  case 3:
    uVar4 = *(undefined8 *)param_4[2];
    local_20 = *(QArrayData **)param_4[1];
    if ((*(int *)local_20 != 0) && (*(int *)local_20 != -1)) {
      LOCK();
      *(int *)local_20 = *(int *)local_20 + 1;
      UNLOCK();
    }
                    /* try { // try from 008fc479 to 008fc47d has its CatchHandler @ 008fc54e */
    FUN_005ea368(param_1,&local_20,uVar4);
    break;
  case 4:
    local_20 = *(QArrayData **)param_4[1];
    if ((*(int *)local_20 != 0) && (*(int *)local_20 != -1)) {
      LOCK();
      *(int *)local_20 = *(int *)local_20 + 1;
      UNLOCK();
    }
                    /* try { // try from 008fc445 to 008fc449 has its CatchHandler @ 008fc566 */
    FUN_005ea368(param_1,&local_20,0);
    break;
  case 5:
    local_20 = (QArrayData *)&QArrayData::shared_null;
                    /* try { // try from 008fc3ec to 008fc3f0 has its CatchHandler @ 008fc556 */
    FUN_005ea368(param_1,&local_20,0);
    break;
  case 6:
    FUN_005eb64e();
    return;
  case 7:
    ppQVar5 = &local_28;
    FUN_005e97ba(ppQVar5,param_1);
    pQVar3 = local_28;
    puVar2 = (undefined8 *)*param_4;
    if (puVar2 != (undefined8 *)0x0) {
      local_28 = (QArrayData *)&QListData::shared_null;
      local_20 = (QArrayData *)*puVar2;
      *puVar2 = pQVar3;
      FUN_00525060(&local_20);
    }
LAB_008fc4cc:
    FUN_00525060(ppQVar5);
    return;
  default:
    goto switchD_008fc392_default;
  }
  if (*(int *)local_20 != 0) {
    if (*(int *)local_20 == -1) {
      return;
    }
    LOCK();
    *(int *)local_20 = *(int *)local_20 + -1;
    UNLOCK();
    if (*(int *)local_20 != 0) {
      return;
    }
  }
  QArrayData::deallocate(local_20,2,8);
  return;
}


// ==== entry=008fc56e orig=FUN_008fc56e size=66 name=KitWindow_dtor ====

undefined8 KitWindow_dtor(undefined8 param_1,char *param_2)

{
  int iVar1;
  undefined8 uVar2;
  
  if (param_2 == (char *)0x0) {
    return 0;
  }
  iVar1 = strcmp(param_2,"EditorWindow");
  if (iVar1 == 0) {
    return param_1;
  }
  uVar2 = s_KitWindow_91d250(param_1,param_2);
  return uVar2;
}


// ==== entry=008fc5b0 orig=FUN_008fc5b0 size=93 name=KitWindow_dtor_deleting ====

ulong KitWindow_dtor_deleting(undefined8 param_1,int param_2,undefined8 param_3,undefined8 *param_4)

{
  int iVar1;
  ulong uVar2;
  
  uVar2 = FUN_0091d292();
  iVar1 = (int)uVar2;
  if (-1 < iVar1) {
    if (param_2 == 0) {
      if (iVar1 < 8) {
        FUN_008fc36e(param_1,0,uVar2 & 0xffffffff,param_4);
        uVar2 = uVar2 & 0xffffffff;
      }
    }
    else {
      if (param_2 != 0xc) {
        return uVar2;
      }
      if (iVar1 < 8) {
        *(undefined4 *)*param_4 = 0xffffffff;
      }
    }
    uVar2 = (ulong)((int)uVar2 - 8);
  }
  return uVar2;
}


// ==== entry=008fc610 orig=FUN_008fc610 size=24 name=TransferCenter_metaObject ====

undefined ** TransferCenter_metaObject(long param_1)

{
  undefined **ppuVar1;
  
  if (*(long *)(*(long *)(param_1 + 8) + 0x28) != 0) {
    ppuVar1 = (undefined **)QObjectData::dynamicMetaObject();
    return ppuVar1;
  }
  return &PTR_staticMetaObject_0119f1a0;
}


// ==== entry=008fc628 name=FUN_008fc628 size=56 ====

void FUN_008fc628(QObject *param_1,undefined8 param_2,undefined1 param_3)

{
  undefined1 local_2c [4];
  void *local_28;
  undefined8 local_20;
  undefined1 *local_18;
  
  local_28 = (void *)0x0;
  local_18 = local_2c;
  local_2c[0] = param_3;
  local_20 = param_2;
  QMetaObject::activate(param_1,(QMetaObject *)&PTR_staticMetaObject_0119f1a0,0,&local_28);
  return;
}


// ==== entry=008fc660 name=FUN_008fc660 size=59 ====

void FUN_008fc660(QObject *param_1,undefined8 param_2,undefined4 param_3)

{
  undefined4 local_2c;
  void *local_28;
  undefined8 local_20;
  undefined4 *local_18;
  
  local_28 = (void *)0x0;
  local_18 = &local_2c;
  local_2c = param_3;
  local_20 = param_2;
  QMetaObject::activate(param_1,(QMetaObject *)&PTR_staticMetaObject_0119f1a0,1,&local_28);
  return;
}


// ==== entry=008fc69c name=FUN_008fc69c size=59 ====

void FUN_008fc69c(QObject *param_1,undefined8 param_2,undefined4 param_3)

{
  undefined4 local_2c;
  void *local_28;
  undefined8 local_20;
  undefined4 *local_18;
  
  local_28 = (void *)0x0;
  local_18 = &local_2c;
  local_2c = param_3;
  local_20 = param_2;
  QMetaObject::activate(param_1,(QMetaObject *)&PTR_staticMetaObject_0119f1a0,2,&local_28);
  return;
}


// ==== entry=008fc6d8 name=FUN_008fc6d8 size=159 ====

void FUN_008fc6d8(undefined8 param_1,int param_2,int param_3,undefined8 *param_4)

{
  undefined4 *puVar1;
  long *plVar2;
  code *pcVar3;
  
  if (param_2 == 0) {
    if (param_3 == 1) {
      FUN_008fc660(param_1,param_4[1],*(undefined4 *)param_4[2]);
      return;
    }
    if (param_3 == 2) {
      FUN_008fc69c(param_1,param_4[1],*(undefined4 *)param_4[2]);
      return;
    }
    if (param_3 == 0) {
      FUN_008fc628(param_1,param_4[1],*(undefined1 *)param_4[2]);
      return;
    }
  }
  else if (param_2 == 10) {
    puVar1 = (undefined4 *)*param_4;
    plVar2 = (long *)param_4[1];
    pcVar3 = (code *)*plVar2;
    if ((pcVar3 == FUN_008fc628) && (plVar2[1] == 0)) {
      *puVar1 = 0;
      return;
    }
    if (pcVar3 == FUN_008fc660) {
      if (plVar2[1] == 0) {
        *puVar1 = 1;
        return;
      }
    }
    else if ((pcVar3 == FUN_008fc69c) && (plVar2[1] == 0)) {
      *puVar1 = 2;
      return;
    }
  }
  return;
}


// ==== entry=008fc778 orig=FUN_008fc778 size=66 name=TransferCenter_qt_metacast ====

char * TransferCenter_qt_metacast(char *param_1,char *param_2)

{
  int iVar1;
  char *pcVar2;
  
  if (param_2 == (char *)0x0) {
    return (char *)0x0;
  }
  iVar1 = strcmp(param_2,"TransferCenter");
  if (iVar1 == 0) {
    return param_1;
  }
  pcVar2 = (char *)QObject::qt_metacast(param_1);
  return pcVar2;
}


// ==== entry=008fc7ba orig=FUN_008fc7ba size=93 name=TransferCenter_qt_metacall ====

ulong TransferCenter_qt_metacall
                (undefined8 param_1,int param_2,undefined8 param_3,undefined8 *param_4)

{
  int iVar1;
  ulong uVar2;
  
  uVar2 = QObject::qt_metacall();
  iVar1 = (int)uVar2;
  if (-1 < iVar1) {
    if (param_2 == 0) {
      if (iVar1 < 3) {
        FUN_008fc6d8(param_1,0,uVar2 & 0xffffffff,param_4);
        uVar2 = uVar2 & 0xffffffff;
      }
    }
    else {
      if (param_2 != 0xc) {
        return uVar2;
      }
      if (iVar1 < 3) {
        *(undefined4 *)*param_4 = 0xffffffff;
      }
    }
    uVar2 = (ulong)((int)uVar2 - 3);
  }
  return uVar2;
}


// ==== entry=008fc820 orig=FUN_008fc820 size=24 name=ForwardingCenter_metaObject ====

undefined ** ForwardingCenter_metaObject(long param_1)

{
  undefined **ppuVar1;
  
  if (*(long *)(*(long *)(param_1 + 8) + 0x28) != 0) {
    ppuVar1 = (undefined **)QObjectData::dynamicMetaObject();
    return ppuVar1;
  }
  return &PTR_staticMetaObject_0119f260;
}


// ==== entry=008fc838 name=FUN_008fc838 size=42 ====

void FUN_008fc838(QObject *param_1,undefined8 param_2)

{
  void *local_18;
  undefined8 local_10;
  
  local_18 = (void *)0x0;
  local_10 = param_2;
  QMetaObject::activate(param_1,(QMetaObject *)&PTR_staticMetaObject_0119f260,1,&local_18);
  return;
}


// ==== entry=008fc862 name=FUN_008fc862 size=112 ====

void FUN_008fc862(QObject *param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                 undefined2 param_5,undefined8 param_6,undefined2 param_7)

{
  undefined2 local_60 [2];
  undefined2 local_5c [2];
  undefined8 local_58;
  undefined8 local_50;
  void *local_48;
  undefined8 local_40;
  undefined8 *local_38;
  undefined8 *local_30;
  undefined2 *local_28;
  undefined8 local_20;
  undefined2 *local_18;
  
  local_60[0] = param_7;
  local_48 = (void *)0x0;
  local_38 = &local_50;
  local_30 = &local_58;
  local_28 = local_5c;
  local_18 = local_60;
  local_5c[0] = param_5;
  local_58 = param_4;
  local_50 = param_3;
  local_40 = param_2;
  local_20 = param_6;
  QMetaObject::activate(param_1,(QMetaObject *)&PTR_staticMetaObject_0119f260,0,&local_48);
  return;
}


// ==== entry=008fc8d2 name=FUN_008fc8d2 size=60 ====

void FUN_008fc8d2(QObject *param_1,undefined8 param_2,undefined2 param_3)

{
  undefined2 local_2c [2];
  void *local_28;
  undefined8 local_20;
  undefined2 *local_18;
  
  local_28 = (void *)0x0;
  local_18 = local_2c;
  local_2c[0] = param_3;
  local_20 = param_2;
  QMetaObject::activate(param_1,(QMetaObject *)&PTR_staticMetaObject_0119f260,3,&local_28);
  return;
}


// ==== entry=008fc90e name=FUN_008fc90e size=64 ====

void FUN_008fc90e(QObject *param_1,undefined8 param_2,undefined4 param_3,undefined8 param_4)

{
  undefined4 local_2c;
  void *local_28;
  undefined8 local_20;
  undefined4 *local_18;
  undefined8 local_10;
  
  local_28 = (void *)0x0;
  local_18 = &local_2c;
  local_2c = param_3;
  local_20 = param_2;
  local_10 = param_4;
  QMetaObject::activate(param_1,(QMetaObject *)&PTR_staticMetaObject_0119f260,2,&local_28);
  return;
}


// ==== entry=008fc94e name=FUN_008fc94e size=128 ====

void FUN_008fc94e(undefined8 param_1,int param_2,long param_3)

{
  if (param_2 == 1) {
    FUN_008fc838(param_1,*(undefined8 *)(param_3 + 8));
    return;
  }
  if (param_2 < 2) {
    if (param_2 == 0) {
      FUN_008fc862(param_1,*(undefined8 *)(param_3 + 8),**(undefined8 **)(param_3 + 0x10),
                   **(undefined8 **)(param_3 + 0x18),**(undefined2 **)(param_3 + 0x20),
                   *(undefined8 *)(param_3 + 0x28),**(undefined2 **)(param_3 + 0x30));
      return;
    }
    return;
  }
  if (param_2 == 2) {
    FUN_008fc90e(param_1,*(undefined8 *)(param_3 + 8),**(undefined4 **)(param_3 + 0x10),
                 *(undefined8 *)(param_3 + 0x18));
    return;
  }
  if (param_2 == 3) {
    FUN_008fc8d2(param_1,*(undefined8 *)(param_3 + 8),**(undefined2 **)(param_3 + 0x10));
    return;
  }
  return;
}


// ==== entry=008fc9ce name=FUN_008fc9ce size=124 ====

void FUN_008fc9ce(undefined8 param_1,int param_2,undefined4 param_3,undefined8 *param_4)

{
  undefined4 *puVar1;
  long *plVar2;
  code *pcVar3;
  
  if (param_2 == 0) {
    FUN_008fc94e(param_1,param_3,param_4);
    return;
  }
  if (param_2 == 10) {
    puVar1 = (undefined4 *)*param_4;
    plVar2 = (long *)param_4[1];
    pcVar3 = (code *)*plVar2;
    if ((pcVar3 == FUN_008fc862) && (plVar2[1] == 0)) {
      *puVar1 = 0;
      return;
    }
    if ((pcVar3 == FUN_008fc838) && (plVar2[1] == 0)) {
      *puVar1 = 1;
      return;
    }
    if ((pcVar3 == FUN_008fc90e) && (plVar2[1] == 0)) {
      *puVar1 = 2;
      return;
    }
    if ((pcVar3 == FUN_008fc8d2) && (plVar2[1] == 0)) {
      *puVar1 = 3;
      return;
    }
  }
  return;
}


// ==== entry=008fca4a orig=FUN_008fca4a size=66 name=ForwardingCenter_qt_metacast ====

char * ForwardingCenter_qt_metacast(char *param_1,char *param_2)

{
  int iVar1;
  char *pcVar2;
  
  if (param_2 == (char *)0x0) {
    return (char *)0x0;
  }
  iVar1 = strcmp(param_2,"ForwardingCenter");
  if (iVar1 == 0) {
    return param_1;
  }
  pcVar2 = (char *)QObject::qt_metacast(param_1);
  return pcVar2;
}


// ==== entry=008fca8c orig=FUN_008fca8c size=95 name=ForwardingCenter_qt_metacall ====

ulong ForwardingCenter_qt_metacall
                (undefined8 param_1,int param_2,undefined8 param_3,undefined8 *param_4)

{
  int iVar1;
  ulong uVar2;
  
  uVar2 = QObject::qt_metacall();
  iVar1 = (int)uVar2;
  if (-1 < iVar1) {
    if (param_2 == 0) {
      if (iVar1 < 4) {
        FUN_008fc94e(param_1,uVar2 & 0xffffffff,param_4);
        uVar2 = uVar2 & 0xffffffff;
      }
    }
    else {
      if (param_2 != 0xc) {
        return uVar2;
      }
      if (iVar1 < 4) {
        *(undefined4 *)*param_4 = 0xffffffff;
      }
    }
    uVar2 = (ulong)((int)uVar2 - 4);
  }
  return uVar2;
}


// ==== entry=008fcaf0 orig=FUN_008fcaf0 size=24 name=ProxyServer_metaObject ====

undefined ** ProxyServer_metaObject(long param_1)

{
  undefined **ppuVar1;
  
  if (*(long *)(*(long *)(param_1 + 8) + 0x28) != 0) {
    ppuVar1 = (undefined **)QObjectData::dynamicMetaObject();
    return ppuVar1;
  }
  return &PTR_staticMetaObject_0119f340;
}


// ==== entry=008fcb08 name=FUN_008fcb08 size=42 ====

void FUN_008fcb08(QObject *param_1,undefined8 param_2)

{
  void *local_18;
  undefined8 local_10;
  
  local_18 = (void *)0x0;
  local_10 = param_2;
  QMetaObject::activate(param_1,(QMetaObject *)&PTR_staticMetaObject_0119f340,1,&local_18);
  return;
}


// ==== entry=008fcb32 name=FUN_008fcb32 size=78 ====

void FUN_008fcb32(QObject *param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                 undefined2 param_5)

{
  undefined2 local_44 [2];
  undefined8 local_40;
  void *local_38;
  undefined8 local_30;
  undefined8 *local_28;
  undefined8 local_20;
  undefined2 *local_18;
  
  local_38 = (void *)0x0;
  local_28 = &local_40;
  local_18 = local_44;
  local_44[0] = param_5;
  local_40 = param_3;
  local_30 = param_2;
  local_20 = param_4;
  QMetaObject::activate(param_1,(QMetaObject *)&PTR_staticMetaObject_0119f340,0,&local_38);
  return;
}


// ==== entry=008fcb80 name=FUN_008fcb80 size=120 ====

void FUN_008fcb80(undefined8 param_1,int param_2,int param_3,undefined8 *param_4)

{
  long *plVar1;
  
  if (param_2 == 0) {
    if (param_3 == 0) {
      FUN_008fcb32(param_1,param_4[1],*(undefined8 *)param_4[2],param_4[3],*(undefined2 *)param_4[4]
                  );
      return;
    }
    if (param_3 == 1) {
      FUN_008fcb08(param_1,param_4[1]);
      return;
    }
    return;
  }
  if (param_2 == 10) {
    plVar1 = (long *)param_4[1];
    if (((code *)*plVar1 == FUN_008fcb32) && (plVar1[1] == 0)) {
      *(undefined4 *)*param_4 = 0;
      return;
    }
    if (((code *)*plVar1 == FUN_008fcb08) && (plVar1[1] == 0)) {
      *(undefined4 *)*param_4 = 1;
      return;
    }
  }
  return;
}


// ==== entry=008fcbf8 orig=FUN_008fcbf8 size=66 name=ProxyServer_qt_metacast ====

char * ProxyServer_qt_metacast(char *param_1,char *param_2)

{
  int iVar1;
  char *pcVar2;
  
  if (param_2 == (char *)0x0) {
    return (char *)0x0;
  }
  iVar1 = strcmp(param_2,"ProxyServer");
  if (iVar1 == 0) {
    return param_1;
  }
  pcVar2 = (char *)QTcpServer::qt_metacast(param_1);
  return pcVar2;
}


// ==== entry=008fcc3a orig=FUN_008fcc3a size=93 name=ProxyServer_qt_metacall ====

ulong ProxyServer_qt_metacall(undefined8 param_1,int param_2,undefined8 param_3,undefined8 *param_4)

{
  int iVar1;
  ulong uVar2;
  
  uVar2 = QTcpServer::qt_metacall();
  iVar1 = (int)uVar2;
  if (-1 < iVar1) {
    if (param_2 == 0) {
      if (iVar1 < 2) {
        FUN_008fcb80(param_1,0,uVar2 & 0xffffffff,param_4);
        uVar2 = uVar2 & 0xffffffff;
      }
    }
    else {
      if (param_2 != 0xc) {
        return uVar2;
      }
      if (iVar1 < 2) {
        *(undefined4 *)*param_4 = 0xffffffff;
      }
    }
    uVar2 = (ulong)((int)uVar2 - 2);
  }
  return uVar2;
}


// ==== entry=008fcc98 orig=FUN_008fcc98 size=160 name=ProxyServer_dtor ====

void ProxyServer_dtor(QTcpServer *param_1)

{
  int iVar1;
  QMapNodeBase *pQVar2;
  QArrayData *pQVar3;
  
  *(undefined ***)param_1 = &ProxyServer_vtable;
  pQVar2 = *(QMapNodeBase **)(param_1 + 0x28);
  if (*(int *)pQVar2 == 0) {
LAB_008fcced:
    if (*(long *)(pQVar2 + 0x10) != 0) {
      QMapDataBase::freeTree(pQVar2,(int)*(long *)(pQVar2 + 0x10));
    }
    QMapDataBase::freeData((QMapDataBase *)pQVar2);
    pQVar3 = *(QArrayData **)(param_1 + 0x18);
    iVar1 = *(int *)pQVar3;
  }
  else {
    if (*(int *)pQVar2 != -1) {
      LOCK();
      *(int *)pQVar2 = *(int *)pQVar2 + -1;
      UNLOCK();
      if (*(int *)pQVar2 == 0) {
        pQVar2 = *(QMapNodeBase **)(param_1 + 0x28);
        goto LAB_008fcced;
      }
    }
    pQVar3 = *(QArrayData **)(param_1 + 0x18);
    iVar1 = *(int *)pQVar3;
  }
  if (iVar1 != 0) {
    if (iVar1 != -1) {
      LOCK();
      *(int *)pQVar3 = *(int *)pQVar3 + -1;
      UNLOCK();
      if (*(int *)pQVar3 == 0) {
        pQVar3 = *(QArrayData **)(param_1 + 0x18);
        goto LAB_008fcd15;
      }
    }
    QTcpServer::~QTcpServer(param_1);
    return;
  }
LAB_008fcd15:
  QArrayData::deallocate(pQVar3,2,8);
  QTcpServer::~QTcpServer(param_1);
  return;
}


// ==== entry=008fcd38 orig=FUN_008fcd38 size=161 name=ProxyServer_dtor_deleting ====

void ProxyServer_dtor_deleting(QTcpServer *param_1)

{
  int iVar1;
  QMapNodeBase *pQVar2;
  QArrayData *pQVar3;
  
  *(undefined ***)param_1 = &ProxyServer_vtable;
  pQVar2 = *(QMapNodeBase **)(param_1 + 0x28);
  if (*(int *)pQVar2 == 0) {
LAB_008fcd9a:
    if (*(long *)(pQVar2 + 0x10) != 0) {
      QMapDataBase::freeTree(pQVar2,(int)*(long *)(pQVar2 + 0x10));
    }
    QMapDataBase::freeData((QMapDataBase *)pQVar2);
    pQVar3 = *(QArrayData **)(param_1 + 0x18);
    iVar1 = *(int *)pQVar3;
  }
  else {
    if (*(int *)pQVar2 != -1) {
      LOCK();
      *(int *)pQVar2 = *(int *)pQVar2 + -1;
      UNLOCK();
      if (*(int *)pQVar2 == 0) {
        pQVar2 = *(QMapNodeBase **)(param_1 + 0x28);
        goto LAB_008fcd9a;
      }
    }
    pQVar3 = *(QArrayData **)(param_1 + 0x18);
    iVar1 = *(int *)pQVar3;
  }
  if (iVar1 != 0) {
    if (iVar1 == -1) goto LAB_008fcd7b;
    LOCK();
    *(int *)pQVar3 = *(int *)pQVar3 + -1;
    UNLOCK();
    if (*(int *)pQVar3 != 0) goto LAB_008fcd7b;
    pQVar3 = *(QArrayData **)(param_1 + 0x18);
  }
  QArrayData::deallocate(pQVar3,2,8);
LAB_008fcd7b:
  QTcpServer::~QTcpServer(param_1);
  operator_delete(param_1,0x30);
  return;
}


// ==== entry=008fcde0 orig=FUN_008fcde0 size=24 name=ForwardingHandler_metaObject ====

undefined ** ForwardingHandler_metaObject(long param_1)

{
  undefined **ppuVar1;
  
  if (*(long *)(*(long *)(param_1 + 8) + 0x28) != 0) {
    ppuVar1 = (undefined **)QObjectData::dynamicMetaObject();
    return ppuVar1;
  }
  return &PTR_staticMetaObject_0119f400;
}


// ==== entry=008fcdf8 name=FUN_008fcdf8 size=52 ====

void FUN_008fcdf8(QObject *param_1,undefined8 param_2)

{
  undefined8 local_20;
  void *local_18;
  undefined8 *local_10;
  
  local_18 = (void *)0x0;
  local_10 = &local_20;
  local_20 = param_2;
  QMetaObject::activate(param_1,(QMetaObject *)&PTR_staticMetaObject_0119f400,0,&local_18);
  return;
}


// ==== entry=008fce2c name=FUN_008fce2c size=132 ====

void FUN_008fce2c(QObject *param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
                 undefined2 param_5,undefined8 param_6,undefined2 param_7,undefined1 param_8)

{
  undefined1 local_60 [4];
  undefined2 local_5c [2];
  undefined2 local_58 [2];
  undefined4 local_54;
  undefined8 local_50;
  void *local_48;
  undefined8 *local_40;
  undefined8 local_38;
  undefined4 *local_30;
  undefined2 *local_28;
  undefined8 local_20;
  undefined2 *local_18;
  undefined1 *local_10;
  
  local_5c[0] = param_7;
  local_60[0] = param_8;
  local_48 = (void *)0x0;
  local_40 = &local_50;
  local_30 = &local_54;
  local_28 = local_58;
  local_18 = local_5c;
  local_10 = local_60;
  local_58[0] = param_5;
  local_54 = param_4;
  local_50 = param_2;
  local_38 = param_3;
  local_20 = param_6;
  QMetaObject::activate(param_1,(QMetaObject *)&PTR_staticMetaObject_0119f400,1,&local_48);
  return;
}


// ==== entry=008fceb0 name=FUN_008fceb0 size=740 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_008fceb0(undefined8 param_1,int param_2,int param_3,undefined8 *param_4)

{
  long *plVar1;
  int *piVar2;
  char cVar3;
  int iVar4;
  char *pcVar5;
  size_t sVar6;
  uint uVar7;
  QArrayData *local_30;
  
  if (param_2 == 0) {
    if (param_3 == 0) {
      FUN_008fcdf8(param_1,*(undefined8 *)param_4[1]);
      return;
    }
    if (param_3 != 1) {
      return;
    }
    FUN_008fce2c(param_1,*(undefined8 *)param_4[1],param_4[2],*(undefined4 *)param_4[3],
                 *(undefined2 *)param_4[4],param_4[5],*(undefined2 *)param_4[6],
                 *(undefined1 *)param_4[7]);
    return;
  }
  if (param_2 != 0xc) {
    if (param_2 != 10) {
      return;
    }
    plVar1 = (long *)param_4[1];
    if (((code *)*plVar1 == FUN_008fcdf8) && (plVar1[1] == 0)) {
      *(undefined4 *)*param_4 = 0;
      return;
    }
    if ((code *)*plVar1 != FUN_008fce2c) {
      return;
    }
    if (plVar1[1] != 0) {
      return;
    }
    *(undefined4 *)*param_4 = 1;
    return;
  }
  piVar2 = (int *)*param_4;
  iVar4 = DAT_011c1454;
  if (param_3 == 0) {
    if (*(int *)param_4[1] != 0) goto LAB_008fcf81;
    if (DAT_011c1454 != 0) goto LAB_008fd063;
    pcVar5 = (char *)QMetaObject::className();
    local_30 = (QArrayData *)&QArrayData::shared_null;
    sVar6 = strlen(pcVar5);
    uVar7 = (int)sVar6 + 1;
    if (((uint)QArrayData::shared_null < 2) && ((int)sVar6 + 2U <= (_files & 0x7fffffff))) {
      _files = _files | 0x80000000;
    }
    else {
      if (uVar7 <= QArrayData::shared_null._4_4_) {
        uVar7 = QArrayData::shared_null._4_4_;
      }
                    /* try { // try from 008fd001 to 008fd041 has its CatchHandler @ 008fd194 */
      QByteArray::reallocData(&local_30,uVar7 + 1,1);
    }
    cVar3 = QByteArray::append((char *)&local_30);
    QByteArray::append(cVar3);
    iVar4 = QMetaType::registerNormalizedType
                      (&local_30,FUN_005f1e26,FUN_005f1e27,8,0x10c,&PTR_staticMetaObject_0119f400);
  }
  else {
    if ((param_3 != 1) || (*(int *)param_4[1] != 0)) {
LAB_008fcf81:
      *piVar2 = -1;
      return;
    }
    if (DAT_011c1454 != 0) goto LAB_008fd063;
    pcVar5 = (char *)QMetaObject::className();
    local_30 = (QArrayData *)&QArrayData::shared_null;
    sVar6 = strlen(pcVar5);
    uVar7 = (int)sVar6 + 1;
    if (((uint)QArrayData::shared_null < 2) && ((int)sVar6 + 2U <= (_files & 0x7fffffff))) {
      _files = _files | 0x80000000;
    }
    else {
      if (uVar7 <= QArrayData::shared_null._4_4_) {
        uVar7 = QArrayData::shared_null._4_4_;
      }
                    /* try { // try from 008fd0c9 to 008fd109 has its CatchHandler @ 008fd19c */
      QByteArray::reallocData(&local_30,uVar7 + 1,1);
    }
    cVar3 = QByteArray::append((char *)&local_30);
    QByteArray::append(cVar3);
    iVar4 = QMetaType::registerNormalizedType
                      (&local_30,FUN_005f1e26,FUN_005f1e27,8,0x10c,&PTR_staticMetaObject_0119f400);
  }
  DAT_011c1454 = iVar4;
  if (*(int *)local_30 != 0) {
    if (*(int *)local_30 != -1) {
      LOCK();
      *(int *)local_30 = *(int *)local_30 + -1;
      UNLOCK();
      if (*(int *)local_30 == 0) goto LAB_008fd114;
    }
LAB_008fd063:
    *piVar2 = iVar4;
    return;
  }
LAB_008fd114:
  QArrayData::deallocate(local_30,1,8);
  *piVar2 = iVar4;
  return;
}


// ==== entry=008fd1a4 orig=FUN_008fd1a4 size=66 name=ForwardingHandler_qt_metacast ====

char * ForwardingHandler_qt_metacast(char *param_1,char *param_2)

{
  int iVar1;
  char *pcVar2;
  
  if (param_2 == (char *)0x0) {
    return (char *)0x0;
  }
  iVar1 = strcmp(param_2,"ForwardingHandler");
  if (iVar1 == 0) {
    return param_1;
  }
  pcVar2 = (char *)QObject::qt_metacast(param_1);
  return pcVar2;
}


// ==== entry=008fd1e6 orig=FUN_008fd1e6 size=109 name=ForwardingHandler_qt_metacall ====

ulong ForwardingHandler_qt_metacall
                (undefined8 param_1,int param_2,undefined8 param_3,undefined8 param_4)

{
  int iVar1;
  ulong uVar2;
  
  uVar2 = QObject::qt_metacall();
  iVar1 = (int)uVar2;
  if (-1 < iVar1) {
    if (param_2 == 0) {
      if (iVar1 < 2) {
        FUN_008fceb0(param_1,0,uVar2 & 0xffffffff,param_4);
        uVar2 = uVar2 & 0xffffffff;
      }
    }
    else {
      if (param_2 != 0xc) {
        return uVar2;
      }
      if (iVar1 < 2) {
        FUN_008fceb0(param_1,0xc,uVar2 & 0xffffffff,param_4);
        uVar2 = uVar2 & 0xffffffff;
      }
    }
    uVar2 = (ulong)((int)uVar2 - 2);
  }
  return uVar2;
}


// ==== entry=008fd260 orig=FUN_008fd260 size=24 name=PeriodTimer_metaObject ====

undefined ** PeriodTimer_metaObject(long param_1)

{
  undefined **ppuVar1;
  
  if (*(long *)(*(long *)(param_1 + 8) + 0x28) != 0) {
    ppuVar1 = (undefined **)QObjectData::dynamicMetaObject();
    return ppuVar1;
  }
  return &PTR_staticMetaObject_0119f4c0;
}


// ==== entry=008fd278 name=FUN_008fd278 size=16 ====

void FUN_008fd278(QObject *param_1)

{
  QMetaObject::activate(param_1,(QMetaObject *)&PTR_staticMetaObject_0119f4c0,0,(void **)0x0);
  return;
}


// ==== entry=008fd288 name=FUN_008fd288 size=52 ====

void FUN_008fd288(undefined8 param_1,int param_2,int param_3,undefined8 *param_4)

{
  if (param_2 == 0) {
    if (param_3 == 0) {
      FUN_008fd278();
      return;
    }
  }
  else if (((param_2 == 10) && (*(code **)param_4[1] == FUN_008fd278)) &&
          (((long *)param_4[1])[1] == 0)) {
    *(undefined4 *)*param_4 = 0;
    return;
  }
  return;
}


// ==== entry=008fd2bc orig=FUN_008fd2bc size=66 name=PeriodTimer_qt_metacast ====

char * PeriodTimer_qt_metacast(char *param_1,char *param_2)

{
  int iVar1;
  char *pcVar2;
  
  if (param_2 == (char *)0x0) {
    return (char *)0x0;
  }
  iVar1 = strcmp(param_2,"PeriodTimer");
  if (iVar1 == 0) {
    return param_1;
  }
  pcVar2 = (char *)QObject::qt_metacast(param_1);
  return pcVar2;
}


// ==== entry=008fd2fe orig=FUN_008fd2fe size=87 name=PeriodTimer_qt_metacall ====

ulong PeriodTimer_qt_metacall(undefined8 param_1,int param_2,undefined8 param_3,undefined8 *param_4)

{
  int iVar1;
  ulong uVar2;
  
  uVar2 = QObject::qt_metacall();
  iVar1 = (int)uVar2;
  if (-1 < iVar1) {
    if (param_2 == 0) {
      if (iVar1 == 0) {
        FUN_008fd278(param_1);
        uVar2 = uVar2 & 0xffffffff;
      }
    }
    else {
      if (param_2 != 0xc) {
        return uVar2;
      }
      if (iVar1 == 0) {
        *(undefined4 *)*param_4 = 0xffffffff;
      }
    }
    uVar2 = (ulong)((int)uVar2 - 1);
  }
  return uVar2;
}


// ==== entry=008fd356 orig=FUN_008fd356 size=19 name=PeriodTimer_dtor ====

void PeriodTimer_dtor(QObject *param_1)

{
  *(undefined ***)param_1 = &PeriodTimer_vtable;
  QObject::~QObject(param_1);
  return;
}


// ==== entry=008fd36a orig=FUN_008fd36a size=37 name=PeriodTimer_dtor_deleting ====

void PeriodTimer_dtor_deleting(QObject *param_1)

{
  *(undefined ***)param_1 = &PeriodTimer_vtable;
  QObject::~QObject(param_1);
  operator_delete(param_1,0x28);
  return;
}


// ==== entry=008fd390 orig=FUN_008fd390 size=24 name=Tools_metaObject ====

undefined ** Tools_metaObject(long param_1)

{
  undefined **ppuVar1;
  
  if (*(long *)(*(long *)(param_1 + 8) + 0x28) != 0) {
    ppuVar1 = (undefined **)QObjectData::dynamicMetaObject();
    return ppuVar1;
  }
  return &PTR_staticMetaObject_0119f720;
}


// ==== entry=008fd3a8 orig=FUN_008fd3a8 size=24 name=ToolRunner_metaObject ====

undefined ** ToolRunner_metaObject(long param_1)

{
  undefined **ppuVar1;
  
  if (*(long *)(*(long *)(param_1 + 8) + 0x28) != 0) {
    ppuVar1 = (undefined **)QObjectData::dynamicMetaObject();
    return ppuVar1;
  }
  return &PTR_staticMetaObject_0119f6e0;
}


// ==== entry=008fd3c0 name=FUN_008fd3c0 size=16 ====

void FUN_008fd3c0(QObject *param_1)

{
  QMetaObject::activate(param_1,(QMetaObject *)&PTR_staticMetaObject_0119f6e0,0,(void **)0x0);
  return;
}


// ==== entry=008fd3d0 name=FUN_008fd3d0 size=44 ====

void FUN_008fd3d0(QObject *param_1,undefined8 param_2,undefined8 param_3)

{
  void *local_28;
  undefined8 local_20;
  undefined8 local_18;
  
  local_28 = (void *)0x0;
  local_20 = param_2;
  local_18 = param_3;
  QMetaObject::activate(param_1,(QMetaObject *)&PTR_staticMetaObject_0119f720,0,&local_28);
  return;
}


// ==== entry=008fd3fc name=FUN_008fd3fc size=47 ====

void FUN_008fd3fc(QObject *param_1,undefined8 param_2,undefined8 param_3)

{
  void *local_28;
  undefined8 local_20;
  undefined8 local_18;
  
  local_28 = (void *)0x0;
  local_20 = param_2;
  local_18 = param_3;
  QMetaObject::activate(param_1,(QMetaObject *)&PTR_staticMetaObject_0119f720,1,&local_28);
  return;
}


// ==== entry=008fd42c name=FUN_008fd42c size=42 ====

void FUN_008fd42c(QObject *param_1,undefined8 param_2)

{
  void *local_18;
  undefined8 local_10;
  
  local_18 = (void *)0x0;
  local_10 = param_2;
  QMetaObject::activate(param_1,(QMetaObject *)&PTR_staticMetaObject_0119f6e0,1,&local_18);
  return;
}


// ==== entry=008fd456 name=FUN_008fd456 size=47 ====

void FUN_008fd456(QObject *param_1,undefined8 param_2,undefined8 param_3)

{
  void *local_28;
  undefined8 local_20;
  undefined8 local_18;
  
  local_28 = (void *)0x0;
  local_20 = param_2;
  local_18 = param_3;
  QMetaObject::activate(param_1,(QMetaObject *)&PTR_staticMetaObject_0119f6e0,2,&local_28);
  return;
}


// ==== entry=008fd486 name=FUN_008fd486 size=102 ====

void FUN_008fd486(undefined8 param_1,int param_2,int param_3,undefined8 *param_4)

{
  long *plVar1;
  
  if (param_2 != 0) {
    if (param_2 == 10) {
      plVar1 = (long *)param_4[1];
      if ((code *)*plVar1 == FUN_008fd3d0) {
        if (plVar1[1] == 0) {
          *(undefined4 *)*param_4 = 0;
          return;
        }
      }
      else if (((code *)*plVar1 == FUN_008fd3fc) && (plVar1[1] == 0)) {
        *(undefined4 *)*param_4 = 1;
        return;
      }
    }
    return;
  }
  if (param_3 == 0) {
    FUN_008fd3d0(param_1,param_4[1],param_4[2]);
    return;
  }
  if (param_3 == 1) {
    FUN_008fd3fc(param_1,param_4[1],param_4[2]);
    return;
  }
  return;
}


// ==== entry=008fd4ec name=FUN_008fd4ec size=132 ====

void FUN_008fd4ec(undefined8 param_1,int param_2,int param_3,undefined8 *param_4)

{
  undefined4 *puVar1;
  long *plVar2;
  code *pcVar3;
  
  if (param_2 == 0) {
    if (param_3 == 1) {
      FUN_008fd42c(param_1,param_4[1]);
      return;
    }
    if (param_3 == 2) {
      FUN_008fd456(param_1,param_4[1],param_4[2]);
      return;
    }
    if (param_3 == 0) {
      FUN_008fd3c0();
      return;
    }
  }
  else if (param_2 == 10) {
    puVar1 = (undefined4 *)*param_4;
    plVar2 = (long *)param_4[1];
    pcVar3 = (code *)*plVar2;
    if ((pcVar3 == FUN_008fd3c0) && (plVar2[1] == 0)) {
      *puVar1 = 0;
      return;
    }
    if ((pcVar3 == FUN_008fd42c) && (plVar2[1] == 0)) {
      *puVar1 = 1;
      return;
    }
    if ((pcVar3 == FUN_008fd456) && (plVar2[1] == 0)) {
      *puVar1 = 2;
      return;
    }
  }
  return;
}


// ==== entry=008fd570 orig=FUN_008fd570 size=104 name=Tools_qt_metacast ====

char * Tools_qt_metacast(char *param_1,byte *param_2)

{
  int iVar1;
  char *pcVar2;
  long lVar3;
  byte *pbVar4;
  bool bVar5;
  bool bVar6;
  byte bVar7;
  
  bVar7 = 0;
  if (param_2 == (byte *)0x0) {
    return (char *)0x0;
  }
  iVar1 = strcmp((char *)param_2,"Tools");
  bVar5 = false;
  if (iVar1 == 0) {
    return param_1;
  }
  lVar3 = 0xf;
  bVar6 = false;
  pbVar4 = (byte *)"QList<ToolPtr>";
  do {
    if (lVar3 == 0) break;
    lVar3 = lVar3 + -1;
    bVar5 = *param_2 < *pbVar4;
    bVar6 = *param_2 == *pbVar4;
    param_2 = param_2 + (ulong)bVar7 * -2 + 1;
    pbVar4 = pbVar4 + (ulong)bVar7 * -2 + 1;
  } while (bVar6);
  if ((!bVar5 && !bVar6) == bVar5) {
    return param_1 + 0x10;
  }
  pcVar2 = (char *)QObject::qt_metacast(param_1);
  return pcVar2;
}


// ==== entry=008fd5d8 orig=FUN_008fd5d8 size=93 name=Tools_qt_metacall ====

ulong Tools_qt_metacall(undefined8 param_1,int param_2,undefined8 param_3,undefined8 *param_4)

{
  int iVar1;
  ulong uVar2;
  
  uVar2 = QObject::qt_metacall();
  iVar1 = (int)uVar2;
  if (-1 < iVar1) {
    if (param_2 == 0) {
      if (iVar1 < 2) {
        FUN_008fd486(param_1,0,uVar2 & 0xffffffff,param_4);
        uVar2 = uVar2 & 0xffffffff;
      }
    }
    else {
      if (param_2 != 0xc) {
        return uVar2;
      }
      if (iVar1 < 2) {
        *(undefined4 *)*param_4 = 0xffffffff;
      }
    }
    uVar2 = (ulong)((int)uVar2 - 2);
  }
  return uVar2;
}


// ==== entry=008fd636 orig=FUN_008fd636 size=66 name=ToolRunner_qt_metacast ====

char * ToolRunner_qt_metacast(char *param_1,char *param_2)

{
  int iVar1;
  char *pcVar2;
  
  if (param_2 == (char *)0x0) {
    return (char *)0x0;
  }
  iVar1 = strcmp(param_2,"ToolRunner");
  if (iVar1 == 0) {
    return param_1;
  }
  pcVar2 = (char *)QProcess::qt_metacast(param_1);
  return pcVar2;
}


// ==== entry=008fd678 orig=FUN_008fd678 size=93 name=ToolRunner_qt_metacall ====

ulong ToolRunner_qt_metacall(undefined8 param_1,int param_2,undefined8 param_3,undefined8 *param_4)

{
  int iVar1;
  ulong uVar2;
  
  uVar2 = QProcess::qt_metacall();
  iVar1 = (int)uVar2;
  if (-1 < iVar1) {
    if (param_2 == 0) {
      if (iVar1 < 3) {
        FUN_008fd4ec(param_1,0,uVar2 & 0xffffffff,param_4);
        uVar2 = uVar2 & 0xffffffff;
      }
    }
    else {
      if (param_2 != 0xc) {
        return uVar2;
      }
      if (iVar1 < 3) {
        *(undefined4 *)*param_4 = 0xffffffff;
      }
    }
    uVar2 = (ulong)((int)uVar2 - 3);
  }
  return uVar2;
}


// ==== entry=008fd6e0 orig=FUN_008fd6e0 size=279 name=Tools_h8fd6e0 ====

/* WARNING: Removing unreachable block (ram,0x008fd777) */
/* WARNING: Removing unreachable block (ram,0x008fd7d7) */

void Tools_h8fd6e0(undefined8 *param_1)

{
  long *plVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  void *pvVar5;
  long *plVar6;
  code *pcVar7;
  long lVar8;
  Data *pDVar9;
  Data *pDVar10;
  
  pDVar9 = (Data *)*param_1;
  if (*(int *)pDVar9 == 0) {
LAB_008fd716:
    pDVar10 = pDVar9 + (long)*(int *)(pDVar9 + 0xc) * 8 + 0x10;
    iVar4 = *(int *)(pDVar9 + 8);
    while (pDVar10 != pDVar9 + (long)iVar4 * 8 + 0x10) {
      pDVar10 = pDVar10 + -8;
      pvVar5 = *(void **)pDVar10;
      if (pvVar5 != (void *)0x0) {
        plVar6 = *(long **)((long)pvVar5 + 8);
        if (plVar6 != (long *)0x0) {
          LOCK();
          plVar1 = plVar6 + 1;
          lVar8 = *plVar1;
          *(int *)plVar1 = (int)*plVar1 + -1;
          UNLOCK();
          if ((int)lVar8 == 1) {
            if (*(code **)(*plVar6 + 0x10) != FUN_00575d12) {
              (**(code **)(*plVar6 + 0x10))(plVar6);
            }
            LOCK();
            piVar2 = (int *)((long)plVar6 + 0xc);
            iVar3 = *piVar2;
            *piVar2 = *piVar2 + -1;
            UNLOCK();
            if (iVar3 == 1) {
              pcVar7 = *(code **)(*plVar6 + 0x18);
              if (pcVar7 == std::_Sp_counted_base<(__gnu_cxx::_Lock_policy)2>::_M_destroy) {
                (**(code **)(*plVar6 + 8))();
              }
              else {
                (*pcVar7)(plVar6);
              }
            }
          }
        }
        operator_delete(pvVar5,0x10);
      }
    }
    QListData::dispose(pDVar9);
    return;
  }
  if (*(int *)pDVar9 != -1) {
    LOCK();
    *(int *)pDVar9 = *(int *)pDVar9 + -1;
    UNLOCK();
    if (*(int *)pDVar9 == 0) {
      pDVar9 = (Data *)*param_1;
      goto LAB_008fd716;
    }
  }
  return;
}


// ==== entry=008fd7f8 orig=FUN_008fd7f8 size=36 name=Tools_dtor ====

void Tools_dtor(QObject *param_1)

{
  *(undefined ***)param_1 = &Tools_vtable;
  Tools_h8fd6e0(param_1 + 0x10);
  QObject::~QObject(param_1);
  return;
}


// ==== entry=008fd81c orig=FUN_008fd81c size=49 name=Tools_dtor_deleting ====

void Tools_dtor_deleting(QObject *param_1)

{
  *(undefined ***)param_1 = &Tools_vtable;
  Tools_h8fd6e0(param_1 + 0x10);
  QObject::~QObject(param_1);
  operator_delete(param_1,0x18);
  return;
}


// ==== entry=008fd84e name=FUN_008fd84e size=1 ====

void FUN_008fd84e(void)

{
  return;
}


// ==== entry=008fd850 orig=FUN_008fd850 size=24 name=JsEngine_metaObject ====

undefined ** JsEngine_metaObject(long param_1)

{
  undefined **ppuVar1;
  
  if (*(long *)(*(long *)(param_1 + 8) + 0x28) != 0) {
    ppuVar1 = (undefined **)QObjectData::dynamicMetaObject();
    return ppuVar1;
  }
  return &PTR_staticMetaObject_0119f7e0;
}


// ==== entry=008fd868 orig=FUN_008fd868 size=66 name=JsEngine_qt_metacast ====

char * JsEngine_qt_metacast(char *param_1,char *param_2)

{
  int iVar1;
  char *pcVar2;
  
  if (param_2 == (char *)0x0) {
    return (char *)0x0;
  }
  iVar1 = strcmp(param_2,"JsEngine");
  if (iVar1 == 0) {
    return param_1;
  }
  pcVar2 = (char *)QObject::qt_metacast(param_1);
  return pcVar2;
}


// ==== entry=008fd8aa orig=FUN_008fd8aa size=5 name=JsEngine_qt_metacall ====

void QObject::JsEngine_qt_metacall(void)

{
  qt_metacall();
  return;
}


// ==== entry=008fd8b0 orig=FUN_008fd8b0 size=24 name=JumpServer_metaObject ====

undefined ** JumpServer_metaObject(long param_1)

{
  undefined **ppuVar1;
  
  if (*(long *)(*(long *)(param_1 + 8) + 0x28) != 0) {
    ppuVar1 = (undefined **)QObjectData::dynamicMetaObject();
    return ppuVar1;
  }
  return &PTR_staticMetaObject_0119f8a0;
}


// ==== entry=008fd8c8 name=FUN_008fd8c8 size=52 ====

void FUN_008fd8c8(QObject *param_1,undefined2 param_2)

{
  undefined2 local_1c [2];
  void *local_18;
  undefined2 *local_10;
  
  local_18 = (void *)0x0;
  local_10 = local_1c;
  local_1c[0] = param_2;
  QMetaObject::activate(param_1,(QMetaObject *)&PTR_staticMetaObject_0119f8a0,0,&local_18);
  return;
}


// ==== entry=008fd8fc name=FUN_008fd8fc size=59 ====

void FUN_008fd8fc(undefined8 param_1,int param_2,int param_3,undefined8 *param_4)

{
  if (param_2 == 0) {
    if (param_3 == 0) {
      FUN_008fd8c8(param_1,*(undefined2 *)param_4[1]);
      return;
    }
  }
  else if (((param_2 == 10) && (*(code **)param_4[1] == FUN_008fd8c8)) &&
          (((long *)param_4[1])[1] == 0)) {
    *(undefined4 *)*param_4 = 0;
    return;
  }
  return;
}


// ==== entry=008fd938 orig=FUN_008fd938 size=66 name=JumpServer_qt_metacast ====

char * JumpServer_qt_metacast(char *param_1,char *param_2)

{
  int iVar1;
  char *pcVar2;
  
  if (param_2 == (char *)0x0) {
    return (char *)0x0;
  }
  iVar1 = strcmp(param_2,"JumpServer");
  if (iVar1 == 0) {
    return param_1;
  }
  pcVar2 = (char *)QObject::qt_metacast(param_1);
  return pcVar2;
}


// ==== entry=008fd97a orig=FUN_008fd97a size=91 name=JumpServer_qt_metacall ====

ulong JumpServer_qt_metacall(undefined8 param_1,int param_2,undefined8 param_3,undefined8 *param_4)

{
  int iVar1;
  ulong uVar2;
  
  uVar2 = QObject::qt_metacall();
  iVar1 = (int)uVar2;
  if (-1 < iVar1) {
    if (param_2 == 0) {
      if (iVar1 == 0) {
        FUN_008fd8c8(param_1,*(undefined2 *)param_4[1]);
        uVar2 = uVar2 & 0xffffffff;
      }
    }
    else {
      if (param_2 != 0xc) {
        return uVar2;
      }
      if (iVar1 == 0) {
        *(undefined4 *)*param_4 = 0xffffffff;
      }
    }
    uVar2 = (ulong)((int)uVar2 - 1);
  }
  return uVar2;
}


// ==== entry=008fd9d6 orig=FUN_008fd9d6 size=82 name=JumpServer_dtor_deleting ====

void JumpServer_dtor_deleting(QObject *param_1)

{
  QArrayData *pQVar1;
  
  *(undefined ***)param_1 = &JumpServer_vtable;
  pQVar1 = *(QArrayData **)(param_1 + 0x20);
  if (*(int *)pQVar1 != 0) {
    if (*(int *)pQVar1 == -1) goto LAB_008fd9fd;
    LOCK();
    *(int *)pQVar1 = *(int *)pQVar1 + -1;
    UNLOCK();
    if (*(int *)pQVar1 != 0) goto LAB_008fd9fd;
    pQVar1 = *(QArrayData **)(param_1 + 0x20);
  }
  QArrayData::deallocate(pQVar1,2,8);
LAB_008fd9fd:
  QObject::~QObject(param_1);
  operator_delete(param_1,0x28);
  return;
}


// ==== entry=008fda28 orig=FUN_008fda28 size=76 name=JumpServer_dtor ====

void JumpServer_dtor(QObject *param_1)

{
  QArrayData *pQVar1;
  
  *(undefined ***)param_1 = &JumpServer_vtable;
  pQVar1 = *(QArrayData **)(param_1 + 0x20);
  if (*(int *)pQVar1 == 0) {
LAB_008fda5c:
    QArrayData::deallocate(pQVar1,2,8);
    QObject::~QObject(param_1);
    return;
  }
  if (*(int *)pQVar1 != -1) {
    LOCK();
    *(int *)pQVar1 = *(int *)pQVar1 + -1;
    UNLOCK();
    if (*(int *)pQVar1 == 0) {
      pQVar1 = *(QArrayData **)(param_1 + 0x20);
      goto LAB_008fda5c;
    }
  }
  QObject::~QObject(param_1);
  return;
}


// ==== entry=008fda74 name=FUN_008fda74 size=1 ====

void FUN_008fda74(void)

{
  return;
}


// ==== entry=008fda76 orig=FUN_008fda76 size=24 name=ProxyCommandSocket_metaObject ====

undefined ** ProxyCommandSocket_metaObject(long param_1)

{
  undefined **ppuVar1;
  
  if (*(long *)(*(long *)(param_1 + 8) + 0x28) != 0) {
    ppuVar1 = (undefined **)QObjectData::dynamicMetaObject();
    return ppuVar1;
  }
  return &PTR_staticMetaObject_0119fa40;
}


// ==== entry=008fda8e orig=FUN_008fda8e size=66 name=ProxyCommandSocket_qt_metacast ====

char * ProxyCommandSocket_qt_metacast(char *param_1,char *param_2)

{
  int iVar1;
  char *pcVar2;
  
  if (param_2 == (char *)0x0) {
    return (char *)0x0;
  }
  iVar1 = strcmp(param_2,"ProxyCommandSocket");
  if (iVar1 == 0) {
    return param_1;
  }
  pcVar2 = (char *)QTcpSocket::qt_metacast(param_1);
  return pcVar2;
}


// ==== entry=008fdad0 orig=FUN_008fdad0 size=5 name=ProxyCommandSocket_qt_metacall ====

void QTcpSocket::ProxyCommandSocket_qt_metacall(void)

{
  qt_metacall();
  return;
}


// ==== entry=008fdae0 orig=FUN_008fdae0 size=5407 name=ProxyCommandSocket_dtor ====

void ProxyCommandSocket_dtor(QTcpSocket *param_1)

{
  int iVar1;
  long lVar2;
  long lVar3;
  long lVar4;
  long lVar5;
  long lVar6;
  long lVar7;
  long lVar8;
  int *piVar9;
  int iVar10;
  QMapNodeBase *pQVar11;
  Data *pDVar12;
  QArrayData *pQVar13;
  Data *pDVar14;
  
  *(undefined ***)param_1 = &ProxyCommandSocket_vtable;
  pQVar11 = *(QMapNodeBase **)(param_1 + 0x38);
  if (*(int *)pQVar11 == 0) {
LAB_008fdbb0:
    lVar2 = *(long *)(pQVar11 + 0x10);
    if (lVar2 != 0) {
      QVariant::~QVariant((QVariant *)(lVar2 + 0x20));
      lVar3 = *(long *)(lVar2 + 8);
      if (lVar3 != 0) {
        QVariant::~QVariant((QVariant *)(lVar3 + 0x20));
        lVar4 = *(long *)(lVar3 + 8);
        if (lVar4 != 0) {
          QVariant::~QVariant((QVariant *)(lVar4 + 0x20));
          lVar5 = *(long *)(lVar4 + 8);
          if (lVar5 != 0) {
            QVariant::~QVariant((QVariant *)(lVar5 + 0x20));
            lVar6 = *(long *)(lVar5 + 8);
            if (lVar6 != 0) {
              QVariant::~QVariant((QVariant *)(lVar6 + 0x20));
              lVar7 = *(long *)(lVar6 + 8);
              if (lVar7 != 0) {
                QVariant::~QVariant((QVariant *)(lVar7 + 0x20));
                lVar8 = *(long *)(lVar7 + 8);
                if (lVar8 != 0) {
                  QVariant::~QVariant((QVariant *)(lVar8 + 0x20));
                  if (*(long *)(lVar8 + 8) != 0) {
                    FUN_0065f8a6();
                  }
                  if (*(long *)(lVar8 + 0x10) != 0) {
                    FUN_0065f8a6();
                  }
                }
                lVar7 = *(long *)(lVar7 + 0x10);
                if (lVar7 != 0) {
                  QVariant::~QVariant((QVariant *)(lVar7 + 0x20));
                  if (*(long *)(lVar7 + 8) != 0) {
                    FUN_0065f8a6();
                  }
                  if (*(long *)(lVar7 + 0x10) != 0) {
                    FUN_0065f8a6();
                  }
                }
              }
              lVar6 = *(long *)(lVar6 + 0x10);
              if (lVar6 != 0) {
                QVariant::~QVariant((QVariant *)(lVar6 + 0x20));
                lVar7 = *(long *)(lVar6 + 8);
                if (lVar7 != 0) {
                  QVariant::~QVariant((QVariant *)(lVar7 + 0x20));
                  if (*(long *)(lVar7 + 8) != 0) {
                    FUN_0065f8a6();
                  }
                  if (*(long *)(lVar7 + 0x10) != 0) {
                    FUN_0065f8a6();
                  }
                }
                lVar6 = *(long *)(lVar6 + 0x10);
                if (lVar6 != 0) {
                  QVariant::~QVariant((QVariant *)(lVar6 + 0x20));
                  if (*(long *)(lVar6 + 8) != 0) {
                    FUN_0065f8a6();
                  }
                  if (*(long *)(lVar6 + 0x10) != 0) {
                    FUN_0065f8a6();
                  }
                }
              }
            }
            lVar5 = *(long *)(lVar5 + 0x10);
            if (lVar5 != 0) {
              QVariant::~QVariant((QVariant *)(lVar5 + 0x20));
              lVar6 = *(long *)(lVar5 + 8);
              if (lVar6 != 0) {
                QVariant::~QVariant((QVariant *)(lVar6 + 0x20));
                lVar7 = *(long *)(lVar6 + 8);
                if (lVar7 != 0) {
                  QVariant::~QVariant((QVariant *)(lVar7 + 0x20));
                  if (*(long *)(lVar7 + 8) != 0) {
                    FUN_0065f8a6();
                  }
                  if (*(long *)(lVar7 + 0x10) != 0) {
                    FUN_0065f8a6();
                  }
                }
                lVar6 = *(long *)(lVar6 + 0x10);
                if (lVar6 != 0) {
                  QVariant::~QVariant((QVariant *)(lVar6 + 0x20));
                  if (*(long *)(lVar6 + 8) != 0) {
                    FUN_0065f8a6();
                  }
                  if (*(long *)(lVar6 + 0x10) != 0) {
                    FUN_0065f8a6();
                  }
                }
              }
              lVar5 = *(long *)(lVar5 + 0x10);
              if (lVar5 != 0) {
                QVariant::~QVariant((QVariant *)(lVar5 + 0x20));
                lVar6 = *(long *)(lVar5 + 8);
                if (lVar6 != 0) {
                  QVariant::~QVariant((QVariant *)(lVar6 + 0x20));
                  if (*(long *)(lVar6 + 8) != 0) {
                    FUN_0065f8a6();
                  }
                  if (*(long *)(lVar6 + 0x10) != 0) {
                    FUN_0065f8a6();
                  }
                }
                lVar5 = *(long *)(lVar5 + 0x10);
                if (lVar5 != 0) {
                  QVariant::~QVariant((QVariant *)(lVar5 + 0x20));
                  if (*(long *)(lVar5 + 8) != 0) {
                    FUN_0065f8a6();
                  }
                  if (*(long *)(lVar5 + 0x10) != 0) {
                    FUN_0065f8a6();
                  }
                }
              }
            }
          }
          lVar4 = *(long *)(lVar4 + 0x10);
          if (lVar4 != 0) {
            QVariant::~QVariant((QVariant *)(lVar4 + 0x20));
            lVar5 = *(long *)(lVar4 + 8);
            if (lVar5 != 0) {
              QVariant::~QVariant((QVariant *)(lVar5 + 0x20));
              lVar6 = *(long *)(lVar5 + 8);
              if (lVar6 != 0) {
                QVariant::~QVariant((QVariant *)(lVar6 + 0x20));
                lVar7 = *(long *)(lVar6 + 8);
                if (lVar7 != 0) {
                  QVariant::~QVariant((QVariant *)(lVar7 + 0x20));
                  if (*(long *)(lVar7 + 8) != 0) {
                    FUN_0065f8a6();
                  }
                  if (*(long *)(lVar7 + 0x10) != 0) {
                    FUN_0065f8a6();
                  }
                }
                lVar6 = *(long *)(lVar6 + 0x10);
                if (lVar6 != 0) {
                  QVariant::~QVariant((QVariant *)(lVar6 + 0x20));
                  if (*(long *)(lVar6 + 8) != 0) {
                    FUN_0065f8a6();
                  }
                  if (*(long *)(lVar6 + 0x10) != 0) {
                    FUN_0065f8a6();
                  }
                }
              }
              lVar5 = *(long *)(lVar5 + 0x10);
              if (lVar5 != 0) {
                QVariant::~QVariant((QVariant *)(lVar5 + 0x20));
                lVar6 = *(long *)(lVar5 + 8);
                if (lVar6 != 0) {
                  QVariant::~QVariant((QVariant *)(lVar6 + 0x20));
                  if (*(long *)(lVar6 + 8) != 0) {
                    FUN_0065f8a6();
                  }
                  if (*(long *)(lVar6 + 0x10) != 0) {
                    FUN_0065f8a6();
                  }
                }
                lVar5 = *(long *)(lVar5 + 0x10);
                if (lVar5 != 0) {
                  QVariant::~QVariant((QVariant *)(lVar5 + 0x20));
                  if (*(long *)(lVar5 + 8) != 0) {
                    FUN_0065f8a6();
                  }
                  if (*(long *)(lVar5 + 0x10) != 0) {
                    FUN_0065f8a6();
                  }
                }
              }
            }
            lVar4 = *(long *)(lVar4 + 0x10);
            if (lVar4 != 0) {
              QVariant::~QVariant((QVariant *)(lVar4 + 0x20));
              lVar5 = *(long *)(lVar4 + 8);
              if (lVar5 != 0) {
                QVariant::~QVariant((QVariant *)(lVar5 + 0x20));
                lVar6 = *(long *)(lVar5 + 8);
                if (lVar6 != 0) {
                  QVariant::~QVariant((QVariant *)(lVar6 + 0x20));
                  if (*(long *)(lVar6 + 8) != 0) {
                    FUN_0065f8a6();
                  }
                  if (*(long *)(lVar6 + 0x10) != 0) {
                    FUN_0065f8a6();
                  }
                }
                lVar5 = *(long *)(lVar5 + 0x10);
                if (lVar5 != 0) {
                  QVariant::~QVariant((QVariant *)(lVar5 + 0x20));
                  if (*(long *)(lVar5 + 8) != 0) {
                    FUN_0065f8a6();
                  }
                  if (*(long *)(lVar5 + 0x10) != 0) {
                    FUN_0065f8a6();
                  }
                }
              }
              lVar4 = *(long *)(lVar4 + 0x10);
              if (lVar4 != 0) {
                QVariant::~QVariant((QVariant *)(lVar4 + 0x20));
                lVar5 = *(long *)(lVar4 + 8);
                if (lVar5 != 0) {
                  QVariant::~QVariant((QVariant *)(lVar5 + 0x20));
                  if (*(long *)(lVar5 + 8) != 0) {
                    FUN_0065f8a6();
                  }
                  if (*(long *)(lVar5 + 0x10) != 0) {
                    FUN_0065f8a6();
                  }
                }
                lVar4 = *(long *)(lVar4 + 0x10);
                if (lVar4 != 0) {
                  QVariant::~QVariant((QVariant *)(lVar4 + 0x20));
                  if (*(long *)(lVar4 + 8) != 0) {
                    FUN_0065f8a6();
                  }
                  if (*(long *)(lVar4 + 0x10) != 0) {
                    FUN_0065f8a6();
                  }
                }
              }
            }
          }
        }
        lVar3 = *(long *)(lVar3 + 0x10);
        if (lVar3 != 0) {
          QVariant::~QVariant((QVariant *)(lVar3 + 0x20));
          lVar4 = *(long *)(lVar3 + 8);
          if (lVar4 != 0) {
            QVariant::~QVariant((QVariant *)(lVar4 + 0x20));
            lVar5 = *(long *)(lVar4 + 8);
            if (lVar5 != 0) {
              QVariant::~QVariant((QVariant *)(lVar5 + 0x20));
              lVar6 = *(long *)(lVar5 + 8);
              if (lVar6 != 0) {
                QVariant::~QVariant((QVariant *)(lVar6 + 0x20));
                lVar7 = *(long *)(lVar6 + 8);
                if (lVar7 != 0) {
                  QVariant::~QVariant((QVariant *)(lVar7 + 0x20));
                  if (*(long *)(lVar7 + 8) != 0) {
                    FUN_0065f8a6();
                  }
                  if (*(long *)(lVar7 + 0x10) != 0) {
                    FUN_0065f8a6();
                  }
                }
                lVar6 = *(long *)(lVar6 + 0x10);
                if (lVar6 != 0) {
                  QVariant::~QVariant((QVariant *)(lVar6 + 0x20));
                  if (*(long *)(lVar6 + 8) != 0) {
                    FUN_0065f8a6();
                  }
                  if (*(long *)(lVar6 + 0x10) != 0) {
                    FUN_0065f8a6();
                  }
                }
              }
              lVar5 = *(long *)(lVar5 + 0x10);
              if (lVar5 != 0) {
                QVariant::~QVariant((QVariant *)(lVar5 + 0x20));
                lVar6 = *(long *)(lVar5 + 8);
                if (lVar6 != 0) {
                  QVariant::~QVariant((QVariant *)(lVar6 + 0x20));
                  if (*(long *)(lVar6 + 8) != 0) {
                    FUN_0065f8a6();
                  }
                  if (*(long *)(lVar6 + 0x10) != 0) {
                    FUN_0065f8a6();
                  }
                }
                lVar5 = *(long *)(lVar5 + 0x10);
                if (lVar5 != 0) {
                  QVariant::~QVariant((QVariant *)(lVar5 + 0x20));
                  if (*(long *)(lVar5 + 8) != 0) {
                    FUN_0065f8a6();
                  }
                  if (*(long *)(lVar5 + 0x10) != 0) {
                    FUN_0065f8a6();
                  }
                }
              }
            }
            lVar4 = *(long *)(lVar4 + 0x10);
            if (lVar4 != 0) {
              QVariant::~QVariant((QVariant *)(lVar4 + 0x20));
              lVar5 = *(long *)(lVar4 + 8);
              if (lVar5 != 0) {
                QVariant::~QVariant((QVariant *)(lVar5 + 0x20));
                lVar6 = *(long *)(lVar5 + 8);
                if (lVar6 != 0) {
                  QVariant::~QVariant((QVariant *)(lVar6 + 0x20));
                  if (*(long *)(lVar6 + 8) != 0) {
                    FUN_0065f8a6();
                  }
                  if (*(long *)(lVar6 + 0x10) != 0) {
                    FUN_0065f8a6();
                  }
                }
                lVar5 = *(long *)(lVar5 + 0x10);
                if (lVar5 != 0) {
                  QVariant::~QVariant((QVariant *)(lVar5 + 0x20));
                  if (*(long *)(lVar5 + 8) != 0) {
                    FUN_0065f8a6();
                  }
                  if (*(long *)(lVar5 + 0x10) != 0) {
                    FUN_0065f8a6();
                  }
                }
              }
              lVar4 = *(long *)(lVar4 + 0x10);
              if (lVar4 != 0) {
                QVariant::~QVariant((QVariant *)(lVar4 + 0x20));
                lVar5 = *(long *)(lVar4 + 8);
                if (lVar5 != 0) {
                  QVariant::~QVariant((QVariant *)(lVar5 + 0x20));
                  if (*(long *)(lVar5 + 8) != 0) {
                    FUN_0065f8a6();
                  }
                  if (*(long *)(lVar5 + 0x10) != 0) {
                    FUN_0065f8a6();
                  }
                }
                lVar4 = *(long *)(lVar4 + 0x10);
                if (lVar4 != 0) {
                  QVariant::~QVariant((QVariant *)(lVar4 + 0x20));
                  if (*(long *)(lVar4 + 8) != 0) {
                    FUN_0065f8a6();
                  }
                  if (*(long *)(lVar4 + 0x10) != 0) {
                    FUN_0065f8a6();
                  }
                }
              }
            }
          }
          lVar3 = *(long *)(lVar3 + 0x10);
          if (lVar3 != 0) {
            QVariant::~QVariant((QVariant *)(lVar3 + 0x20));
            lVar4 = *(long *)(lVar3 + 8);
            if (lVar4 != 0) {
              QVariant::~QVariant((QVariant *)(lVar4 + 0x20));
              lVar5 = *(long *)(lVar4 + 8);
              if (lVar5 != 0) {
                QVariant::~QVariant((QVariant *)(lVar5 + 0x20));
                lVar6 = *(long *)(lVar5 + 8);
                if (lVar6 != 0) {
                  QVariant::~QVariant((QVariant *)(lVar6 + 0x20));
                  if (*(long *)(lVar6 + 8) != 0) {
                    FUN_0065f8a6();
                  }
                  if (*(long *)(lVar6 + 0x10) != 0) {
                    FUN_0065f8a6();
                  }
                }
                lVar5 = *(long *)(lVar5 + 0x10);
                if (lVar5 != 0) {
                  QVariant::~QVariant((QVariant *)(lVar5 + 0x20));
                  if (*(long *)(lVar5 + 8) != 0) {
                    FUN_0065f8a6();
                  }
                  if (*(long *)(lVar5 + 0x10) != 0) {
                    FUN_0065f8a6();
                  }
                }
              }
              lVar4 = *(long *)(lVar4 + 0x10);
              if (lVar4 != 0) {
                QVariant::~QVariant((QVariant *)(lVar4 + 0x20));
                lVar5 = *(long *)(lVar4 + 8);
                if (lVar5 != 0) {
                  QVariant::~QVariant((QVariant *)(lVar5 + 0x20));
                  if (*(long *)(lVar5 + 8) != 0) {
                    FUN_0065f8a6();
                  }
                  if (*(long *)(lVar5 + 0x10) != 0) {
                    FUN_0065f8a6();
                  }
                }
                lVar4 = *(long *)(lVar4 + 0x10);
                if (lVar4 != 0) {
                  QVariant::~QVariant((QVariant *)(lVar4 + 0x20));
                  if (*(long *)(lVar4 + 8) != 0) {
                    FUN_0065f8a6();
                  }
                  if (*(long *)(lVar4 + 0x10) != 0) {
                    FUN_0065f8a6();
                  }
                }
              }
            }
            lVar3 = *(long *)(lVar3 + 0x10);
            if (lVar3 != 0) {
              QVariant::~QVariant((QVariant *)(lVar3 + 0x20));
              lVar4 = *(long *)(lVar3 + 8);
              if (lVar4 != 0) {
                QVariant::~QVariant((QVariant *)(lVar4 + 0x20));
                lVar5 = *(long *)(lVar4 + 8);
                if (lVar5 != 0) {
                  QVariant::~QVariant((QVariant *)(lVar5 + 0x20));
                  if (*(long *)(lVar5 + 8) != 0) {
                    FUN_0065f8a6();
                  }
                  if (*(long *)(lVar5 + 0x10) != 0) {
                    FUN_0065f8a6();
                  }
                }
                lVar4 = *(long *)(lVar4 + 0x10);
                if (lVar4 != 0) {
                  QVariant::~QVariant((QVariant *)(lVar4 + 0x20));
                  if (*(long *)(lVar4 + 8) != 0) {
                    FUN_0065f8a6();
                  }
                  if (*(long *)(lVar4 + 0x10) != 0) {
                    FUN_0065f8a6();
                  }
                }
              }
              lVar3 = *(long *)(lVar3 + 0x10);
              if (lVar3 != 0) {
                QVariant::~QVariant((QVariant *)(lVar3 + 0x20));
                lVar4 = *(long *)(lVar3 + 8);
                if (lVar4 != 0) {
                  QVariant::~QVariant((QVariant *)(lVar4 + 0x20));
                  if (*(long *)(lVar4 + 8) != 0) {
                    FUN_0065f8a6();
                  }
                  if (*(long *)(lVar4 + 0x10) != 0) {
                    FUN_0065f8a6();
                  }
                }
                lVar3 = *(long *)(lVar3 + 0x10);
                if (lVar3 != 0) {
                  QVariant::~QVariant((QVariant *)(lVar3 + 0x20));
                  if (*(long *)(lVar3 + 8) != 0) {
                    FUN_0065f8a6();
                  }
                  if (*(long *)(lVar3 + 0x10) != 0) {
                    FUN_0065f8a6();
                  }
                }
              }
            }
          }
        }
      }
      lVar2 = *(long *)(lVar2 + 0x10);
      if (lVar2 != 0) {
        QVariant::~QVariant((QVariant *)(lVar2 + 0x20));
        lVar3 = *(long *)(lVar2 + 8);
        if (lVar3 != 0) {
          QVariant::~QVariant((QVariant *)(lVar3 + 0x20));
          lVar4 = *(long *)(lVar3 + 8);
          if (lVar4 != 0) {
            QVariant::~QVariant((QVariant *)(lVar4 + 0x20));
            lVar5 = *(long *)(lVar4 + 8);
            if (lVar5 != 0) {
              QVariant::~QVariant((QVariant *)(lVar5 + 0x20));
              lVar6 = *(long *)(lVar5 + 8);
              if (lVar6 != 0) {
                QVariant::~QVariant((QVariant *)(lVar6 + 0x20));
                lVar7 = *(long *)(lVar6 + 8);
                if (lVar7 != 0) {
                  QVariant::~QVariant((QVariant *)(lVar7 + 0x20));
                  if (*(long *)(lVar7 + 8) != 0) {
                    FUN_0065f8a6();
                  }
                  if (*(long *)(lVar7 + 0x10) != 0) {
                    FUN_0065f8a6();
                  }
                }
                lVar6 = *(long *)(lVar6 + 0x10);
                if (lVar6 != 0) {
                  QVariant::~QVariant((QVariant *)(lVar6 + 0x20));
                  if (*(long *)(lVar6 + 8) != 0) {
                    FUN_0065f8a6();
                  }
                  if (*(long *)(lVar6 + 0x10) != 0) {
                    FUN_0065f8a6();
                  }
                }
              }
              lVar5 = *(long *)(lVar5 + 0x10);
              if (lVar5 != 0) {
                QVariant::~QVariant((QVariant *)(lVar5 + 0x20));
                lVar6 = *(long *)(lVar5 + 8);
                if (lVar6 != 0) {
                  QVariant::~QVariant((QVariant *)(lVar6 + 0x20));
                  if (*(long *)(lVar6 + 8) != 0) {
                    FUN_0065f8a6();
                  }
                  if (*(long *)(lVar6 + 0x10) != 0) {
                    FUN_0065f8a6();
                  }
                }
                lVar5 = *(long *)(lVar5 + 0x10);
                if (lVar5 != 0) {
                  QVariant::~QVariant((QVariant *)(lVar5 + 0x20));
                  if (*(long *)(lVar5 + 8) != 0) {
                    FUN_0065f8a6();
                  }
                  if (*(long *)(lVar5 + 0x10) != 0) {
                    FUN_0065f8a6();
                  }
                }
              }
            }
            lVar4 = *(long *)(lVar4 + 0x10);
            if (lVar4 != 0) {
              QVariant::~QVariant((QVariant *)(lVar4 + 0x20));
              lVar5 = *(long *)(lVar4 + 8);
              if (lVar5 != 0) {
                QVariant::~QVariant((QVariant *)(lVar5 + 0x20));
                lVar6 = *(long *)(lVar5 + 8);
                if (lVar6 != 0) {
                  QVariant::~QVariant((QVariant *)(lVar6 + 0x20));
                  if (*(long *)(lVar6 + 8) != 0) {
                    FUN_0065f8a6();
                  }
                  if (*(long *)(lVar6 + 0x10) != 0) {
                    FUN_0065f8a6();
                  }
                }
                lVar5 = *(long *)(lVar5 + 0x10);
                if (lVar5 != 0) {
                  QVariant::~QVariant((QVariant *)(lVar5 + 0x20));
                  if (*(long *)(lVar5 + 8) != 0) {
                    FUN_0065f8a6();
                  }
                  if (*(long *)(lVar5 + 0x10) != 0) {
                    FUN_0065f8a6();
                  }
                }
              }
              lVar4 = *(long *)(lVar4 + 0x10);
              if (lVar4 != 0) {
                QVariant::~QVariant((QVariant *)(lVar4 + 0x20));
                lVar5 = *(long *)(lVar4 + 8);
                if (lVar5 != 0) {
                  QVariant::~QVariant((QVariant *)(lVar5 + 0x20));
                  if (*(long *)(lVar5 + 8) != 0) {
                    FUN_0065f8a6();
                  }
                  if (*(long *)(lVar5 + 0x10) != 0) {
                    FUN_0065f8a6();
                  }
                }
                lVar4 = *(long *)(lVar4 + 0x10);
                if (lVar4 != 0) {
                  QVariant::~QVariant((QVariant *)(lVar4 + 0x20));
                  if (*(long *)(lVar4 + 8) != 0) {
                    FUN_0065f8a6();
                  }
                  if (*(long *)(lVar4 + 0x10) != 0) {
                    FUN_0065f8a6();
                  }
                }
              }
            }
          }
          lVar3 = *(long *)(lVar3 + 0x10);
          if (lVar3 != 0) {
            QVariant::~QVariant((QVariant *)(lVar3 + 0x20));
            lVar4 = *(long *)(lVar3 + 8);
            if (lVar4 != 0) {
              QVariant::~QVariant((QVariant *)(lVar4 + 0x20));
              lVar5 = *(long *)(lVar4 + 8);
              if (lVar5 != 0) {
                QVariant::~QVariant((QVariant *)(lVar5 + 0x20));
                lVar6 = *(long *)(lVar5 + 8);
                if (lVar6 != 0) {
                  QVariant::~QVariant((QVariant *)(lVar6 + 0x20));
                  if (*(long *)(lVar6 + 8) != 0) {
                    FUN_0065f8a6();
                  }
                  if (*(long *)(lVar6 + 0x10) != 0) {
                    FUN_0065f8a6();
                  }
                }
                lVar5 = *(long *)(lVar5 + 0x10);
                if (lVar5 != 0) {
                  QVariant::~QVariant((QVariant *)(lVar5 + 0x20));
                  if (*(long *)(lVar5 + 8) != 0) {
                    FUN_0065f8a6();
                  }
                  if (*(long *)(lVar5 + 0x10) != 0) {
                    FUN_0065f8a6();
                  }
                }
              }
              lVar4 = *(long *)(lVar4 + 0x10);
              if (lVar4 != 0) {
                QVariant::~QVariant((QVariant *)(lVar4 + 0x20));
                lVar5 = *(long *)(lVar4 + 8);
                if (lVar5 != 0) {
                  QVariant::~QVariant((QVariant *)(lVar5 + 0x20));
                  if (*(long *)(lVar5 + 8) != 0) {
                    FUN_0065f8a6();
                  }
                  if (*(long *)(lVar5 + 0x10) != 0) {
                    FUN_0065f8a6();
                  }
                }
                lVar4 = *(long *)(lVar4 + 0x10);
                if (lVar4 != 0) {
                  QVariant::~QVariant((QVariant *)(lVar4 + 0x20));
                  if (*(long *)(lVar4 + 8) != 0) {
                    FUN_0065f8a6();
                  }
                  if (*(long *)(lVar4 + 0x10) != 0) {
                    FUN_0065f8a6();
                  }
                }
              }
            }
            lVar3 = *(long *)(lVar3 + 0x10);
            if (lVar3 != 0) {
              QVariant::~QVariant((QVariant *)(lVar3 + 0x20));
              lVar4 = *(long *)(lVar3 + 8);
              if (lVar4 != 0) {
                QVariant::~QVariant((QVariant *)(lVar4 + 0x20));
                lVar5 = *(long *)(lVar4 + 8);
                if (lVar5 != 0) {
                  QVariant::~QVariant((QVariant *)(lVar5 + 0x20));
                  if (*(long *)(lVar5 + 8) != 0) {
                    FUN_0065f8a6();
                  }
                  if (*(long *)(lVar5 + 0x10) != 0) {
                    FUN_0065f8a6();
                  }
                }
                lVar4 = *(long *)(lVar4 + 0x10);
                if (lVar4 != 0) {
                  QVariant::~QVariant((QVariant *)(lVar4 + 0x20));
                  if (*(long *)(lVar4 + 8) != 0) {
                    FUN_0065f8a6();
                  }
                  if (*(long *)(lVar4 + 0x10) != 0) {
                    FUN_0065f8a6();
                  }
                }
              }
              lVar3 = *(long *)(lVar3 + 0x10);
              if (lVar3 != 0) {
                QVariant::~QVariant((QVariant *)(lVar3 + 0x20));
                lVar4 = *(long *)(lVar3 + 8);
                if (lVar4 != 0) {
                  QVariant::~QVariant((QVariant *)(lVar4 + 0x20));
                  if (*(long *)(lVar4 + 8) != 0) {
                    FUN_0065f8a6();
                  }
                  if (*(long *)(lVar4 + 0x10) != 0) {
                    FUN_0065f8a6();
                  }
                }
                lVar3 = *(long *)(lVar3 + 0x10);
                if (lVar3 != 0) {
                  QVariant::~QVariant((QVariant *)(lVar3 + 0x20));
                  if (*(long *)(lVar3 + 8) != 0) {
                    FUN_0065f8a6();
                  }
                  if (*(long *)(lVar3 + 0x10) != 0) {
                    FUN_0065f8a6();
                  }
                }
              }
            }
          }
        }
        lVar2 = *(long *)(lVar2 + 0x10);
        if (lVar2 != 0) {
          QVariant::~QVariant((QVariant *)(lVar2 + 0x20));
          lVar3 = *(long *)(lVar2 + 8);
          if (lVar3 != 0) {
            QVariant::~QVariant((QVariant *)(lVar3 + 0x20));
            lVar4 = *(long *)(lVar3 + 8);
            if (lVar4 != 0) {
              QVariant::~QVariant((QVariant *)(lVar4 + 0x20));
              lVar5 = *(long *)(lVar4 + 8);
              if (lVar5 != 0) {
                QVariant::~QVariant((QVariant *)(lVar5 + 0x20));
                lVar6 = *(long *)(lVar5 + 8);
                if (lVar6 != 0) {
                  QVariant::~QVariant((QVariant *)(lVar6 + 0x20));
                  if (*(long *)(lVar6 + 8) != 0) {
                    FUN_0065f8a6();
                  }
                  if (*(long *)(lVar6 + 0x10) != 0) {
                    FUN_0065f8a6();
                  }
                }
                lVar5 = *(long *)(lVar5 + 0x10);
                if (lVar5 != 0) {
                  QVariant::~QVariant((QVariant *)(lVar5 + 0x20));
                  if (*(long *)(lVar5 + 8) != 0) {
                    FUN_0065f8a6();
                  }
                  if (*(long *)(lVar5 + 0x10) != 0) {
                    FUN_0065f8a6();
                  }
                }
              }
              lVar4 = *(long *)(lVar4 + 0x10);
              if (lVar4 != 0) {
                QVariant::~QVariant((QVariant *)(lVar4 + 0x20));
                lVar5 = *(long *)(lVar4 + 8);
                if (lVar5 != 0) {
                  QVariant::~QVariant((QVariant *)(lVar5 + 0x20));
                  if (*(long *)(lVar5 + 8) != 0) {
                    FUN_0065f8a6();
                  }
                  if (*(long *)(lVar5 + 0x10) != 0) {
                    FUN_0065f8a6();
                  }
                }
                lVar4 = *(long *)(lVar4 + 0x10);
                if (lVar4 != 0) {
                  QVariant::~QVariant((QVariant *)(lVar4 + 0x20));
                  if (*(long *)(lVar4 + 8) != 0) {
                    FUN_0065f8a6();
                  }
                  if (*(long *)(lVar4 + 0x10) != 0) {
                    FUN_0065f8a6();
                  }
                }
              }
            }
            lVar3 = *(long *)(lVar3 + 0x10);
            if (lVar3 != 0) {
              QVariant::~QVariant((QVariant *)(lVar3 + 0x20));
              lVar4 = *(long *)(lVar3 + 8);
              if (lVar4 != 0) {
                QVariant::~QVariant((QVariant *)(lVar4 + 0x20));
                lVar5 = *(long *)(lVar4 + 8);
                if (lVar5 != 0) {
                  QVariant::~QVariant((QVariant *)(lVar5 + 0x20));
                  if (*(long *)(lVar5 + 8) != 0) {
                    FUN_0065f8a6();
                  }
                  if (*(long *)(lVar5 + 0x10) != 0) {
                    FUN_0065f8a6();
                  }
                }
                lVar4 = *(long *)(lVar4 + 0x10);
                if (lVar4 != 0) {
                  QVariant::~QVariant((QVariant *)(lVar4 + 0x20));
                  if (*(long *)(lVar4 + 8) != 0) {
                    FUN_0065f8a6();
                  }
                  if (*(long *)(lVar4 + 0x10) != 0) {
                    FUN_0065f8a6();
                  }
                }
              }
              lVar3 = *(long *)(lVar3 + 0x10);
              if (lVar3 != 0) {
                QVariant::~QVariant((QVariant *)(lVar3 + 0x20));
                lVar4 = *(long *)(lVar3 + 8);
                if (lVar4 != 0) {
                  QVariant::~QVariant((QVariant *)(lVar4 + 0x20));
                  if (*(long *)(lVar4 + 8) != 0) {
                    FUN_0065f8a6();
                  }
                  if (*(long *)(lVar4 + 0x10) != 0) {
                    FUN_0065f8a6();
                  }
                }
                lVar3 = *(long *)(lVar3 + 0x10);
                if (lVar3 != 0) {
                  QVariant::~QVariant((QVariant *)(lVar3 + 0x20));
                  if (*(long *)(lVar3 + 8) != 0) {
                    FUN_0065f8a6();
                  }
                  if (*(long *)(lVar3 + 0x10) != 0) {
                    FUN_0065f8a6();
                  }
                }
              }
            }
          }
          lVar2 = *(long *)(lVar2 + 0x10);
          if (lVar2 != 0) {
            QVariant::~QVariant((QVariant *)(lVar2 + 0x20));
            lVar3 = *(long *)(lVar2 + 8);
            if (lVar3 != 0) {
              QVariant::~QVariant((QVariant *)(lVar3 + 0x20));
              lVar4 = *(long *)(lVar3 + 8);
              if (lVar4 != 0) {
                QVariant::~QVariant((QVariant *)(lVar4 + 0x20));
                lVar5 = *(long *)(lVar4 + 8);
                if (lVar5 != 0) {
                  QVariant::~QVariant((QVariant *)(lVar5 + 0x20));
                  if (*(long *)(lVar5 + 8) != 0) {
                    FUN_0065f8a6();
                  }
                  if (*(long *)(lVar5 + 0x10) != 0) {
                    FUN_0065f8a6();
                  }
                }
                lVar4 = *(long *)(lVar4 + 0x10);
                if (lVar4 != 0) {
                  QVariant::~QVariant((QVariant *)(lVar4 + 0x20));
                  if (*(long *)(lVar4 + 8) != 0) {
                    FUN_0065f8a6();
                  }
                  if (*(long *)(lVar4 + 0x10) != 0) {
                    FUN_0065f8a6();
                  }
                }
              }
              lVar3 = *(long *)(lVar3 + 0x10);
              if (lVar3 != 0) {
                QVariant::~QVariant((QVariant *)(lVar3 + 0x20));
                lVar4 = *(long *)(lVar3 + 8);
                if (lVar4 != 0) {
                  QVariant::~QVariant((QVariant *)(lVar4 + 0x20));
                  if (*(long *)(lVar4 + 8) != 0) {
                    FUN_0065f8a6();
                  }
                  if (*(long *)(lVar4 + 0x10) != 0) {
                    FUN_0065f8a6();
                  }
                }
                lVar3 = *(long *)(lVar3 + 0x10);
                if (lVar3 != 0) {
                  QVariant::~QVariant((QVariant *)(lVar3 + 0x20));
                  if (*(long *)(lVar3 + 8) != 0) {
                    FUN_0065f8a6();
                  }
                  if (*(long *)(lVar3 + 0x10) != 0) {
                    FUN_0065f8a6();
                  }
                }
              }
            }
            lVar2 = *(long *)(lVar2 + 0x10);
            if (lVar2 != 0) {
              QVariant::~QVariant((QVariant *)(lVar2 + 0x20));
              lVar3 = *(long *)(lVar2 + 8);
              if (lVar3 != 0) {
                QVariant::~QVariant((QVariant *)(lVar3 + 0x20));
                lVar4 = *(long *)(lVar3 + 8);
                if (lVar4 != 0) {
                  QVariant::~QVariant((QVariant *)(lVar4 + 0x20));
                  if (*(long *)(lVar4 + 8) != 0) {
                    FUN_0065f8a6();
                  }
                  if (*(long *)(lVar4 + 0x10) != 0) {
                    FUN_0065f8a6();
                  }
                }
                lVar3 = *(long *)(lVar3 + 0x10);
                if (lVar3 != 0) {
                  QVariant::~QVariant((QVariant *)(lVar3 + 0x20));
                  if (*(long *)(lVar3 + 8) != 0) {
                    FUN_0065f8a6();
                  }
                  if (*(long *)(lVar3 + 0x10) != 0) {
                    FUN_0065f8a6();
                  }
                }
              }
              lVar2 = *(long *)(lVar2 + 0x10);
              if (lVar2 != 0) {
                QVariant::~QVariant((QVariant *)(lVar2 + 0x20));
                lVar3 = *(long *)(lVar2 + 8);
                if (lVar3 != 0) {
                  QVariant::~QVariant((QVariant *)(lVar3 + 0x20));
                  if (*(long *)(lVar3 + 8) != 0) {
                    FUN_0065f8a6();
                  }
                  if (*(long *)(lVar3 + 0x10) != 0) {
                    FUN_0065f8a6();
                  }
                }
                lVar2 = *(long *)(lVar2 + 0x10);
                if (lVar2 != 0) {
                  QVariant::~QVariant((QVariant *)(lVar2 + 0x20));
                  if (*(long *)(lVar2 + 8) != 0) {
                    FUN_0065f8a6();
                  }
                  if (*(long *)(lVar2 + 0x10) != 0) {
                    FUN_0065f8a6();
                  }
                }
              }
            }
          }
        }
      }
      QMapDataBase::freeTree(pQVar11,(int)*(undefined8 *)(pQVar11 + 0x10));
    }
    QMapDataBase::freeData((QMapDataBase *)pQVar11);
    pQVar13 = *(QArrayData **)(param_1 + 0x28);
    iVar10 = *(int *)pQVar13;
    if (iVar10 != 0) goto LAB_008fdb2c;
LAB_008fef16:
    QArrayData::deallocate(pQVar13,2,8);
    pQVar13 = *(QArrayData **)(param_1 + 0x20);
    iVar10 = *(int *)pQVar13;
    if (iVar10 == 0) goto LAB_008fef33;
LAB_008fdb49:
    if (iVar10 != -1) {
      LOCK();
      *(int *)pQVar13 = *(int *)pQVar13 + -1;
      UNLOCK();
      if (*(int *)pQVar13 == 0) {
        pQVar13 = *(QArrayData **)(param_1 + 0x20);
        goto LAB_008fef33;
      }
    }
    pDVar14 = *(Data **)(param_1 + 0x18);
    iVar10 = *(int *)pDVar14;
  }
  else {
    if (*(int *)pQVar11 != -1) {
      LOCK();
      *(int *)pQVar11 = *(int *)pQVar11 + -1;
      UNLOCK();
      if (*(int *)pQVar11 == 0) {
        pQVar11 = *(QMapNodeBase **)(param_1 + 0x38);
        goto LAB_008fdbb0;
      }
    }
    pQVar13 = *(QArrayData **)(param_1 + 0x28);
    iVar10 = *(int *)pQVar13;
    if (iVar10 == 0) goto LAB_008fef16;
LAB_008fdb2c:
    if (iVar10 != -1) {
      LOCK();
      *(int *)pQVar13 = *(int *)pQVar13 + -1;
      UNLOCK();
      if (*(int *)pQVar13 == 0) {
        pQVar13 = *(QArrayData **)(param_1 + 0x28);
        goto LAB_008fef16;
      }
    }
    pQVar13 = *(QArrayData **)(param_1 + 0x20);
    iVar10 = *(int *)pQVar13;
    if (iVar10 != 0) goto LAB_008fdb49;
LAB_008fef33:
    QArrayData::deallocate(pQVar13,2,8);
    pDVar14 = *(Data **)(param_1 + 0x18);
    iVar10 = *(int *)pDVar14;
  }
  if (iVar10 == 0) {
LAB_008fef52:
    pDVar12 = pDVar14 + (long)*(int *)(pDVar14 + 0xc) * 8 + 0x10;
    iVar10 = *(int *)(pDVar14 + 8);
joined_r0x008fef6c:
    if (pDVar12 != pDVar14 + (long)iVar10 * 8 + 0x10) {
      do {
        pDVar12 = pDVar12 + -8;
        piVar9 = *(int **)pDVar12;
        if (*piVar9 != 0) {
          if (*piVar9 == -1) goto joined_r0x008fef6c;
          LOCK();
          iVar1 = *piVar9;
          *piVar9 = *piVar9 + -1;
          UNLOCK();
          if (iVar1 != 1) goto joined_r0x008fef6c;
        }
        QArrayData::deallocate(*(QArrayData **)pDVar12,2,8);
        if (pDVar14 + (long)iVar10 * 8 + 0x10 == pDVar12) break;
      } while( true );
    }
    QListData::dispose(pDVar14);
    pQVar13 = *(QArrayData **)(param_1 + 0x10);
    iVar10 = *(int *)pQVar13;
  }
  else {
    if (iVar10 != -1) {
      LOCK();
      *(int *)pDVar14 = *(int *)pDVar14 + -1;
      UNLOCK();
      if (*(int *)pDVar14 == 0) {
        pDVar14 = *(Data **)(param_1 + 0x18);
        goto LAB_008fef52;
      }
    }
    pQVar13 = *(QArrayData **)(param_1 + 0x10);
    iVar10 = *(int *)pQVar13;
  }
  if (iVar10 != 0) {
    if (iVar10 == -1) goto LAB_008fdb96;
    LOCK();
    *(int *)pQVar13 = *(int *)pQVar13 + -1;
    UNLOCK();
    if (*(int *)pQVar13 != 0) goto LAB_008fdb96;
    pQVar13 = *(QArrayData **)(param_1 + 0x10);
  }
  QArrayData::deallocate(pQVar13,2,8);
LAB_008fdb96:
  QTcpSocket::~QTcpSocket(param_1);
  return;
}


// ==== entry=008ff000 orig=FUN_008ff000 size=23 name=ProxyCommandSocket_dtor_deleting ====

void ProxyCommandSocket_dtor_deleting(void *param_1)

{
  ProxyCommandSocket_dtor();
  operator_delete(param_1,0x40);
  return;
}


// ==== entry=008ff020 name=FUN_008ff020 size=10 ====

void FUN_008ff020(undefined8 param_1,int param_2,int param_3)

{
  if (param_3 == 0 && param_2 == 0) {
    FUN_00663faa();
    return;
  }
  return;
}


// ==== entry=008ff02a name=FUN_008ff02a size=24 ====

undefined ** FUN_008ff02a(long param_1)

{
  undefined **ppuVar1;
  
  if (*(long *)(*(long *)(param_1 + 8) + 0x28) != 0) {
    ppuVar1 = (undefined **)QObjectData::dynamicMetaObject();
    return ppuVar1;
  }
  return &PTR_staticMetaObject_0119fc60;
}


// ==== entry=008ff042 orig=FUN_008ff042 size=66 name=SortFilterProxyModel_dtor ====

char * SortFilterProxyModel_dtor(char *param_1,char *param_2)

{
  int iVar1;
  char *pcVar2;
  
  if (param_2 == (char *)0x0) {
    return (char *)0x0;
  }
  iVar1 = strcmp(param_2,"SortFilterProxyModel");
  if (iVar1 == 0) {
    return param_1;
  }
  pcVar2 = (char *)QSortFilterProxyModel::qt_metacast(param_1);
  return pcVar2;
}


// ==== entry=008ff084 orig=FUN_008ff084 size=84 name=SortFilterProxyModel_dtor_deleting ====

ulong SortFilterProxyModel_dtor_deleting
                (undefined8 param_1,int param_2,undefined8 param_3,undefined8 *param_4)

{
  int iVar1;
  ulong uVar2;
  
  uVar2 = QSortFilterProxyModel::qt_metacall();
  iVar1 = (int)uVar2;
  if (-1 < iVar1) {
    if (param_2 == 0) {
      if (iVar1 == 0) {
        FUN_00663faa(param_1);
        uVar2 = uVar2 & 0xffffffff;
      }
    }
    else {
      if (param_2 != 0xc) {
        return uVar2;
      }
      if (iVar1 == 0) {
        *(undefined4 *)*param_4 = 0xffffffff;
      }
    }
    uVar2 = (ulong)((int)uVar2 - 1);
  }
  return uVar2;
}


// ==== entry=008ff0d8 name=FUN_008ff0d8 size=41 ====

void FUN_008ff0d8(QSortFilterProxyModel *param_1)

{
  *(undefined ***)param_1 = &PTR_FUN_0119fa98;
  if (*(void **)(param_1 + 0x30) != (void *)0x0) {
    operator_delete(*(void **)(param_1 + 0x30));
  }
  QSortFilterProxyModel::~QSortFilterProxyModel(param_1);
  return;
}


// ==== entry=008ff102 name=FUN_008ff102 size=54 ====

void FUN_008ff102(QSortFilterProxyModel *param_1)

{
  *(undefined ***)param_1 = &PTR_FUN_0119fa98;
  if (*(void **)(param_1 + 0x30) != (void *)0x0) {
    operator_delete(*(void **)(param_1 + 0x30));
  }
  QSortFilterProxyModel::~QSortFilterProxyModel(param_1);
  operator_delete(param_1,0x50);
  return;
}


// ==== entry=008ff138 name=FUN_008ff138 size=1 ====

void FUN_008ff138(void)

{
  return;
}


// ==== entry=008ff13a name=FUN_008ff13a size=24 ====

undefined ** FUN_008ff13a(long param_1)

{
  undefined **ppuVar1;
  
  if (*(long *)(*(long *)(param_1 + 8) + 0x28) != 0) {
    ppuVar1 = (undefined **)QObjectData::dynamicMetaObject();
    return ppuVar1;
  }
  return &PTR_staticMetaObject_0119fe40;
}


// ==== entry=008ff152 orig=FUN_008ff152 size=66 name=ListModel_dtor ====

char * ListModel_dtor(char *param_1,char *param_2)

{
  int iVar1;
  char *pcVar2;
  
  if (param_2 == (char *)0x0) {
    return (char *)0x0;
  }
  iVar1 = strcmp(param_2,"ListModel");
  if (iVar1 == 0) {
    return param_1;
  }
  pcVar2 = (char *)QAbstractListModel::qt_metacast(param_1);
  return pcVar2;
}


// ==== entry=008ff194 orig=FUN_008ff194 size=5 name=ListModel_dtor_deleting ====

void QAbstractListModel::ListModel_dtor_deleting(void)

{
  qt_metacall();
  return;
}


// ==== entry=008ff19a name=FUN_008ff19a size=109 ====

void FUN_008ff19a(QAbstractListModel *param_1)

{
  void *pvVar1;
  QArrayData *pQVar2;
  
  *(undefined ***)param_1 = &PTR_FUN_0119fcb8;
  pQVar2 = *(QArrayData **)(param_1 + 0x20);
  if (*(int *)pQVar2 != 0) {
    if (*(int *)pQVar2 == -1) goto LAB_008ff1c6;
    LOCK();
    *(int *)pQVar2 = *(int *)pQVar2 + -1;
    UNLOCK();
    if (*(int *)pQVar2 != 0) goto LAB_008ff1c6;
    pQVar2 = *(QArrayData **)(param_1 + 0x20);
  }
  QArrayData::deallocate(pQVar2,2,8);
LAB_008ff1c6:
  pvVar1 = *(void **)(param_1 + 0x10);
  if (pvVar1 != (void *)0x0) {
    FUN_0062cf92(pvVar1);
    operator_delete(pvVar1,0x50);
  }
  QAbstractListModel::~QAbstractListModel(param_1);
  return;
}


// ==== entry=008ff208 name=FUN_008ff208 size=122 ====

void FUN_008ff208(QAbstractListModel *param_1)

{
  void *pvVar1;
  QArrayData *pQVar2;
  
  *(undefined ***)param_1 = &PTR_FUN_0119fcb8;
  pQVar2 = *(QArrayData **)(param_1 + 0x20);
  if (*(int *)pQVar2 != 0) {
    if (*(int *)pQVar2 == -1) goto LAB_008ff234;
    LOCK();
    *(int *)pQVar2 = *(int *)pQVar2 + -1;
    UNLOCK();
    if (*(int *)pQVar2 != 0) goto LAB_008ff234;
    pQVar2 = *(QArrayData **)(param_1 + 0x20);
  }
  QArrayData::deallocate(pQVar2,2,8);
LAB_008ff234:
  pvVar1 = *(void **)(param_1 + 0x10);
  if (pvVar1 != (void *)0x0) {
    FUN_0062cf92(pvVar1);
    operator_delete(pvVar1,0x50);
  }
  QAbstractListModel::~QAbstractListModel(param_1);
  operator_delete(param_1,0x28);
  return;
}


// ==== entry=008ff282 name=FUN_008ff282 size=1 ====

void FUN_008ff282(void)

{
  return;
}


// ==== entry=008ff284 orig=FUN_008ff284 size=24 name=MediaCenter_metaObject ====

undefined ** MediaCenter_metaObject(long param_1)

{
  undefined **ppuVar1;
  
  if (*(long *)(*(long *)(param_1 + 8) + 0x28) != 0) {
    ppuVar1 = (undefined **)QObjectData::dynamicMetaObject();
    return ppuVar1;
  }
  return &PTR_staticMetaObject_0119ff00;
}


// ==== entry=008ff29c orig=FUN_008ff29c size=66 name=MediaCenter_qt_metacast ====

char * MediaCenter_qt_metacast(char *param_1,char *param_2)

{
  int iVar1;
  char *pcVar2;
  
  if (param_2 == (char *)0x0) {
    return (char *)0x0;
  }
  iVar1 = strcmp(param_2,"MediaCenter");
  if (iVar1 == 0) {
    return param_1;
  }
  pcVar2 = (char *)QObject::qt_metacast(param_1);
  return pcVar2;
}


// ==== entry=008ff2de orig=FUN_008ff2de size=5 name=MediaCenter_qt_metacall ====

void QObject::MediaCenter_qt_metacall(void)

{
  qt_metacall();
  return;
}


// ==== entry=008ff2f0 orig=FUN_008ff2f0 size=7135 name=MediaCenter_dtor_deleting ====

void MediaCenter_dtor_deleting(QObject *param_1)

{
  int iVar1;
  int iVar2;
  long lVar3;
  long lVar4;
  long lVar5;
  long lVar6;
  long lVar7;
  int *piVar8;
  QMapNodeBase *pQVar9;
  Data *pDVar10;
  QArrayData *pQVar11;
  Data *pDVar12;
  
  *(undefined ***)param_1 = &MediaCenter_vtable;
  pQVar9 = *(QMapNodeBase **)(param_1 + 0x20);
  if (*(int *)pQVar9 == 0) {
LAB_008ff36e:
    lVar3 = *(long *)(pQVar9 + 0x10);
    if (lVar3 != 0) {
      pQVar11 = *(QArrayData **)(lVar3 + 0x18);
      if (*(int *)pQVar11 == 0) {
LAB_009008db:
        QArrayData::deallocate(pQVar11,2,8);
      }
      else if (*(int *)pQVar11 != -1) {
        LOCK();
        *(int *)pQVar11 = *(int *)pQVar11 + -1;
        UNLOCK();
        if (*(int *)pQVar11 == 0) {
          pQVar11 = *(QArrayData **)(lVar3 + 0x18);
          goto LAB_009008db;
        }
      }
      piVar8 = *(int **)(lVar3 + 0x20);
      if (piVar8 != (int *)0x0) {
        LOCK();
        *piVar8 = *piVar8 + -1;
        UNLOCK();
        if ((*piVar8 == 0) && (*(void **)(lVar3 + 0x20) != (void *)0x0)) {
          operator_delete(*(void **)(lVar3 + 0x20));
        }
      }
      lVar4 = *(long *)(lVar3 + 8);
      if (lVar4 != 0) {
        pQVar11 = *(QArrayData **)(lVar4 + 0x18);
        if (*(int *)pQVar11 == 0) {
LAB_008ff3d4:
          QArrayData::deallocate(pQVar11,2,8);
        }
        else if (*(int *)pQVar11 != -1) {
          LOCK();
          *(int *)pQVar11 = *(int *)pQVar11 + -1;
          UNLOCK();
          if (*(int *)pQVar11 == 0) {
            pQVar11 = *(QArrayData **)(lVar4 + 0x18);
            goto LAB_008ff3d4;
          }
        }
        piVar8 = *(int **)(lVar4 + 0x20);
        if (piVar8 != (int *)0x0) {
          LOCK();
          *piVar8 = *piVar8 + -1;
          UNLOCK();
          if ((*piVar8 == 0) && (*(void **)(lVar4 + 0x20) != (void *)0x0)) {
            operator_delete(*(void **)(lVar4 + 0x20));
          }
        }
        lVar5 = *(long *)(lVar4 + 8);
        if (lVar5 != 0) {
          pQVar11 = *(QArrayData **)(lVar5 + 0x18);
          if (*(int *)pQVar11 == 0) {
LAB_0090090b:
            QArrayData::deallocate(pQVar11,2,8);
          }
          else if (*(int *)pQVar11 != -1) {
            LOCK();
            *(int *)pQVar11 = *(int *)pQVar11 + -1;
            UNLOCK();
            if (*(int *)pQVar11 == 0) {
              pQVar11 = *(QArrayData **)(lVar5 + 0x18);
              goto LAB_0090090b;
            }
          }
          piVar8 = *(int **)(lVar5 + 0x20);
          if (piVar8 != (int *)0x0) {
            LOCK();
            *piVar8 = *piVar8 + -1;
            UNLOCK();
            if ((*piVar8 == 0) && (*(void **)(lVar5 + 0x20) != (void *)0x0)) {
              operator_delete(*(void **)(lVar5 + 0x20));
            }
          }
          lVar6 = *(long *)(lVar5 + 8);
          if (lVar6 != 0) {
            pQVar11 = *(QArrayData **)(lVar6 + 0x18);
            if (*(int *)pQVar11 == 0) {
LAB_0090096c:
              QArrayData::deallocate(pQVar11,2,8);
            }
            else if (*(int *)pQVar11 != -1) {
              LOCK();
              *(int *)pQVar11 = *(int *)pQVar11 + -1;
              UNLOCK();
              if (*(int *)pQVar11 == 0) {
                pQVar11 = *(QArrayData **)(lVar6 + 0x18);
                goto LAB_0090096c;
              }
            }
            piVar8 = *(int **)(lVar6 + 0x20);
            if (piVar8 != (int *)0x0) {
              LOCK();
              *piVar8 = *piVar8 + -1;
              UNLOCK();
              if ((*piVar8 == 0) && (*(void **)(lVar6 + 0x20) != (void *)0x0)) {
                operator_delete(*(void **)(lVar6 + 0x20));
              }
            }
            lVar7 = *(long *)(lVar6 + 8);
            if (lVar7 != 0) {
              pQVar11 = *(QArrayData **)(lVar7 + 0x18);
              if (*(int *)pQVar11 == 0) {
LAB_00900a75:
                QArrayData::deallocate(pQVar11,2,8);
              }
              else if (*(int *)pQVar11 != -1) {
                LOCK();
                *(int *)pQVar11 = *(int *)pQVar11 + -1;
                UNLOCK();
                if (*(int *)pQVar11 == 0) {
                  pQVar11 = *(QArrayData **)(lVar7 + 0x18);
                  goto LAB_00900a75;
                }
              }
              piVar8 = *(int **)(lVar7 + 0x20);
              if (piVar8 != (int *)0x0) {
                LOCK();
                *piVar8 = *piVar8 + -1;
                UNLOCK();
                if ((*piVar8 == 0) && (*(void **)(lVar7 + 0x20) != (void *)0x0)) {
                  operator_delete(*(void **)(lVar7 + 0x20));
                }
              }
              if (*(long *)(lVar7 + 8) != 0) {
                FUN_0064e5d8();
              }
              lVar7 = *(long *)(lVar7 + 0x10);
              if (lVar7 != 0) {
                pQVar11 = *(QArrayData **)(lVar7 + 0x18);
                if (*(int *)pQVar11 == 0) {
LAB_00900c30:
                  QArrayData::deallocate(pQVar11,2,8);
                }
                else if (*(int *)pQVar11 != -1) {
                  LOCK();
                  *(int *)pQVar11 = *(int *)pQVar11 + -1;
                  UNLOCK();
                  if (*(int *)pQVar11 == 0) {
                    pQVar11 = *(QArrayData **)(lVar7 + 0x18);
                    goto LAB_00900c30;
                  }
                }
                piVar8 = *(int **)(lVar7 + 0x20);
                if (piVar8 != (int *)0x0) {
                  LOCK();
                  *piVar8 = *piVar8 + -1;
                  UNLOCK();
                  if ((*piVar8 == 0) && (*(void **)(lVar7 + 0x20) != (void *)0x0)) {
                    operator_delete(*(void **)(lVar7 + 0x20));
                  }
                }
                if (*(long *)(lVar7 + 8) != 0) {
                  FUN_0064e5d8();
                }
                if (*(long *)(lVar7 + 0x10) != 0) {
                  FUN_0064e5d8();
                }
              }
            }
            lVar6 = *(long *)(lVar6 + 0x10);
            if (lVar6 != 0) {
              pQVar11 = *(QArrayData **)(lVar6 + 0x18);
              if (*(int *)pQVar11 == 0) {
LAB_00900a5d:
                QArrayData::deallocate(pQVar11,2,8);
              }
              else if (*(int *)pQVar11 != -1) {
                LOCK();
                *(int *)pQVar11 = *(int *)pQVar11 + -1;
                UNLOCK();
                if (*(int *)pQVar11 == 0) {
                  pQVar11 = *(QArrayData **)(lVar6 + 0x18);
                  goto LAB_00900a5d;
                }
              }
              piVar8 = *(int **)(lVar6 + 0x20);
              if (piVar8 != (int *)0x0) {
                LOCK();
                *piVar8 = *piVar8 + -1;
                UNLOCK();
                if ((*piVar8 == 0) && (*(void **)(lVar6 + 0x20) != (void *)0x0)) {
                  operator_delete(*(void **)(lVar6 + 0x20));
                }
              }
              lVar7 = *(long *)(lVar6 + 8);
              if (lVar7 != 0) {
                pQVar11 = *(QArrayData **)(lVar7 + 0x18);
                if (*(int *)pQVar11 == 0) {
LAB_00900d04:
                  QArrayData::deallocate(pQVar11,2,8);
                }
                else if (*(int *)pQVar11 != -1) {
                  LOCK();
                  *(int *)pQVar11 = *(int *)pQVar11 + -1;
                  UNLOCK();
                  if (*(int *)pQVar11 == 0) {
                    pQVar11 = *(QArrayData **)(lVar7 + 0x18);
                    goto LAB_00900d04;
                  }
                }
                piVar8 = *(int **)(lVar7 + 0x20);
                if (piVar8 != (int *)0x0) {
                  LOCK();
                  *piVar8 = *piVar8 + -1;
                  UNLOCK();
                  if ((*piVar8 == 0) && (*(void **)(lVar7 + 0x20) != (void *)0x0)) {
                    operator_delete(*(void **)(lVar7 + 0x20));
                  }
                }
                if (*(long *)(lVar7 + 8) != 0) {
                  FUN_0064e5d8();
                }
                if (*(long *)(lVar7 + 0x10) != 0) {
                  FUN_0064e5d8();
                }
              }
              lVar6 = *(long *)(lVar6 + 0x10);
              if (lVar6 != 0) {
                pQVar11 = *(QArrayData **)(lVar6 + 0x18);
                if (*(int *)pQVar11 == 0) {
LAB_00900ca4:
                  QArrayData::deallocate(pQVar11,2,8);
                }
                else if (*(int *)pQVar11 != -1) {
                  LOCK();
                  *(int *)pQVar11 = *(int *)pQVar11 + -1;
                  UNLOCK();
                  if (*(int *)pQVar11 == 0) {
                    pQVar11 = *(QArrayData **)(lVar6 + 0x18);
                    goto LAB_00900ca4;
                  }
                }
                piVar8 = *(int **)(lVar6 + 0x20);
                if (piVar8 != (int *)0x0) {
                  LOCK();
                  *piVar8 = *piVar8 + -1;
                  UNLOCK();
                  if ((*piVar8 == 0) && (*(void **)(lVar6 + 0x20) != (void *)0x0)) {
                    operator_delete(*(void **)(lVar6 + 0x20));
                  }
                }
                if (*(long *)(lVar6 + 8) != 0) {
                  FUN_0064e5d8();
                }
                if (*(long *)(lVar6 + 0x10) != 0) {
                  FUN_0064e5d8();
                }
              }
            }
          }
          lVar5 = *(long *)(lVar5 + 0x10);
          if (lVar5 != 0) {
            pQVar11 = *(QArrayData **)(lVar5 + 0x18);
            if (*(int *)pQVar11 == 0) {
LAB_00900984:
              QArrayData::deallocate(pQVar11,2,8);
            }
            else if (*(int *)pQVar11 != -1) {
              LOCK();
              *(int *)pQVar11 = *(int *)pQVar11 + -1;
              UNLOCK();
              if (*(int *)pQVar11 == 0) {
                pQVar11 = *(QArrayData **)(lVar5 + 0x18);
                goto LAB_00900984;
              }
            }
            piVar8 = *(int **)(lVar5 + 0x20);
            if (piVar8 != (int *)0x0) {
              LOCK();
              *piVar8 = *piVar8 + -1;
              UNLOCK();
              if ((*piVar8 == 0) && (*(void **)(lVar5 + 0x20) != (void *)0x0)) {
                operator_delete(*(void **)(lVar5 + 0x20));
              }
            }
            lVar6 = *(long *)(lVar5 + 8);
            if (lVar6 != 0) {
              pQVar11 = *(QArrayData **)(lVar6 + 0x18);
              if (*(int *)pQVar11 == 0) {
LAB_00900b58:
                QArrayData::deallocate(pQVar11,2,8);
              }
              else if (*(int *)pQVar11 != -1) {
                LOCK();
                *(int *)pQVar11 = *(int *)pQVar11 + -1;
                UNLOCK();
                if (*(int *)pQVar11 == 0) {
                  pQVar11 = *(QArrayData **)(lVar6 + 0x18);
                  goto LAB_00900b58;
                }
              }
              piVar8 = *(int **)(lVar6 + 0x20);
              if (piVar8 != (int *)0x0) {
                LOCK();
                *piVar8 = *piVar8 + -1;
                UNLOCK();
                if ((*piVar8 == 0) && (*(void **)(lVar6 + 0x20) != (void *)0x0)) {
                  operator_delete(*(void **)(lVar6 + 0x20));
                }
              }
              lVar7 = *(long *)(lVar6 + 8);
              if (lVar7 != 0) {
                pQVar11 = *(QArrayData **)(lVar7 + 0x18);
                if (*(int *)pQVar11 == 0) {
LAB_00900dc1:
                  QArrayData::deallocate(pQVar11,2,8);
                }
                else if (*(int *)pQVar11 != -1) {
                  LOCK();
                  *(int *)pQVar11 = *(int *)pQVar11 + -1;
                  UNLOCK();
                  if (*(int *)pQVar11 == 0) {
                    pQVar11 = *(QArrayData **)(lVar7 + 0x18);
                    goto LAB_00900dc1;
                  }
                }
                piVar8 = *(int **)(lVar7 + 0x20);
                if (piVar8 != (int *)0x0) {
                  LOCK();
                  *piVar8 = *piVar8 + -1;
                  UNLOCK();
                  if ((*piVar8 == 0) && (*(void **)(lVar7 + 0x20) != (void *)0x0)) {
                    operator_delete(*(void **)(lVar7 + 0x20));
                  }
                }
                if (*(long *)(lVar7 + 8) != 0) {
                  FUN_0064e5d8();
                }
                if (*(long *)(lVar7 + 0x10) != 0) {
                  FUN_0064e5d8();
                }
              }
              lVar6 = *(long *)(lVar6 + 0x10);
              if (lVar6 != 0) {
                pQVar11 = *(QArrayData **)(lVar6 + 0x18);
                if (*(int *)pQVar11 == 0) {
LAB_00900da9:
                  QArrayData::deallocate(pQVar11,2,8);
                }
                else if (*(int *)pQVar11 != -1) {
                  LOCK();
                  *(int *)pQVar11 = *(int *)pQVar11 + -1;
                  UNLOCK();
                  if (*(int *)pQVar11 == 0) {
                    pQVar11 = *(QArrayData **)(lVar6 + 0x18);
                    goto LAB_00900da9;
                  }
                }
                piVar8 = *(int **)(lVar6 + 0x20);
                if (piVar8 != (int *)0x0) {
                  LOCK();
                  *piVar8 = *piVar8 + -1;
                  UNLOCK();
                  if ((*piVar8 == 0) && (*(void **)(lVar6 + 0x20) != (void *)0x0)) {
                    operator_delete(*(void **)(lVar6 + 0x20));
                  }
                }
                if (*(long *)(lVar6 + 8) != 0) {
                  FUN_0064e5d8();
                }
                if (*(long *)(lVar6 + 0x10) != 0) {
                  FUN_0064e5d8();
                }
              }
            }
            lVar5 = *(long *)(lVar5 + 0x10);
            if (lVar5 != 0) {
              pQVar11 = *(QArrayData **)(lVar5 + 0x18);
              if (*(int *)pQVar11 == 0) {
LAB_00900b70:
                QArrayData::deallocate(pQVar11,2,8);
              }
              else if (*(int *)pQVar11 != -1) {
                LOCK();
                *(int *)pQVar11 = *(int *)pQVar11 + -1;
                UNLOCK();
                if (*(int *)pQVar11 == 0) {
                  pQVar11 = *(QArrayData **)(lVar5 + 0x18);
                  goto LAB_00900b70;
                }
              }
              piVar8 = *(int **)(lVar5 + 0x20);
              if (piVar8 != (int *)0x0) {
                LOCK();
                *piVar8 = *piVar8 + -1;
                UNLOCK();
                if ((*piVar8 == 0) && (*(void **)(lVar5 + 0x20) != (void *)0x0)) {
                  operator_delete(*(void **)(lVar5 + 0x20));
                }
              }
              lVar6 = *(long *)(lVar5 + 8);
              if (lVar6 != 0) {
                pQVar11 = *(QArrayData **)(lVar6 + 0x18);
                if (*(int *)pQVar11 == 0) {
LAB_00900bb8:
                  QArrayData::deallocate(pQVar11,2,8);
                }
                else if (*(int *)pQVar11 != -1) {
                  LOCK();
                  *(int *)pQVar11 = *(int *)pQVar11 + -1;
                  UNLOCK();
                  if (*(int *)pQVar11 == 0) {
                    pQVar11 = *(QArrayData **)(lVar6 + 0x18);
                    goto LAB_00900bb8;
                  }
                }
                piVar8 = *(int **)(lVar6 + 0x20);
                if (piVar8 != (int *)0x0) {
                  LOCK();
                  *piVar8 = *piVar8 + -1;
                  UNLOCK();
                  if ((*piVar8 == 0) && (*(void **)(lVar6 + 0x20) != (void *)0x0)) {
                    operator_delete(*(void **)(lVar6 + 0x20));
                  }
                }
                if (*(long *)(lVar6 + 8) != 0) {
                  FUN_0064e5d8();
                }
                if (*(long *)(lVar6 + 0x10) != 0) {
                  FUN_0064e5d8();
                }
              }
              lVar5 = *(long *)(lVar5 + 0x10);
              if (lVar5 != 0) {
                pQVar11 = *(QArrayData **)(lVar5 + 0x18);
                if (*(int *)pQVar11 == 0) {
LAB_00900c8c:
                  QArrayData::deallocate(pQVar11,2,8);
                }
                else if (*(int *)pQVar11 != -1) {
                  LOCK();
                  *(int *)pQVar11 = *(int *)pQVar11 + -1;
                  UNLOCK();
                  if (*(int *)pQVar11 == 0) {
                    pQVar11 = *(QArrayData **)(lVar5 + 0x18);
                    goto LAB_00900c8c;
                  }
                }
                piVar8 = *(int **)(lVar5 + 0x20);
                if (piVar8 != (int *)0x0) {
                  LOCK();
                  *piVar8 = *piVar8 + -1;
                  UNLOCK();
                  if ((*piVar8 == 0) && (*(void **)(lVar5 + 0x20) != (void *)0x0)) {
                    operator_delete(*(void **)(lVar5 + 0x20));
                  }
                }
                if (*(long *)(lVar5 + 8) != 0) {
                  FUN_0064e5d8();
                }
                if (*(long *)(lVar5 + 0x10) != 0) {
                  FUN_0064e5d8();
                }
              }
            }
          }
        }
        lVar4 = *(long *)(lVar4 + 0x10);
        if (lVar4 != 0) {
          pQVar11 = *(QArrayData **)(lVar4 + 0x18);
          if (*(int *)pQVar11 == 0) {
LAB_0090093c:
            QArrayData::deallocate(pQVar11,2,8);
          }
          else if (*(int *)pQVar11 != -1) {
            LOCK();
            *(int *)pQVar11 = *(int *)pQVar11 + -1;
            UNLOCK();
            if (*(int *)pQVar11 == 0) {
              pQVar11 = *(QArrayData **)(lVar4 + 0x18);
              goto LAB_0090093c;
            }
          }
          piVar8 = *(int **)(lVar4 + 0x20);
          if (piVar8 != (int *)0x0) {
            LOCK();
            *piVar8 = *piVar8 + -1;
            UNLOCK();
            if ((*piVar8 == 0) && (*(void **)(lVar4 + 0x20) != (void *)0x0)) {
              operator_delete(*(void **)(lVar4 + 0x20));
            }
          }
          lVar5 = *(long *)(lVar4 + 8);
          if (lVar5 != 0) {
            pQVar11 = *(QArrayData **)(lVar5 + 0x18);
            if (*(int *)pQVar11 == 0) {
LAB_00900a15:
              QArrayData::deallocate(pQVar11,2,8);
            }
            else if (*(int *)pQVar11 != -1) {
              LOCK();
              *(int *)pQVar11 = *(int *)pQVar11 + -1;
              UNLOCK();
              if (*(int *)pQVar11 == 0) {
                pQVar11 = *(QArrayData **)(lVar5 + 0x18);
                goto LAB_00900a15;
              }
            }
            piVar8 = *(int **)(lVar5 + 0x20);
            if (piVar8 != (int *)0x0) {
              LOCK();
              *piVar8 = *piVar8 + -1;
              UNLOCK();
              if ((*piVar8 == 0) && (*(void **)(lVar5 + 0x20) != (void *)0x0)) {
                operator_delete(*(void **)(lVar5 + 0x20));
              }
            }
            lVar6 = *(long *)(lVar5 + 8);
            if (lVar6 != 0) {
              pQVar11 = *(QArrayData **)(lVar6 + 0x18);
              if (*(int *)pQVar11 == 0) {
LAB_00900ac7:
                QArrayData::deallocate(pQVar11,2,8);
              }
              else if (*(int *)pQVar11 != -1) {
                LOCK();
                *(int *)pQVar11 = *(int *)pQVar11 + -1;
                UNLOCK();
                if (*(int *)pQVar11 == 0) {
                  pQVar11 = *(QArrayData **)(lVar6 + 0x18);
                  goto LAB_00900ac7;
                }
              }
              piVar8 = *(int **)(lVar6 + 0x20);
              if (piVar8 != (int *)0x0) {
                LOCK();
                *piVar8 = *piVar8 + -1;
                UNLOCK();
                if ((*piVar8 == 0) && (*(void **)(lVar6 + 0x20) != (void *)0x0)) {
                  operator_delete(*(void **)(lVar6 + 0x20));
                }
              }
              lVar7 = *(long *)(lVar6 + 8);
              if (lVar7 != 0) {
                pQVar11 = *(QArrayData **)(lVar7 + 0x18);
                if (*(int *)pQVar11 == 0) {
LAB_00900c6a:
                  QArrayData::deallocate(pQVar11,2,8);
                }
                else if (*(int *)pQVar11 != -1) {
                  LOCK();
                  *(int *)pQVar11 = *(int *)pQVar11 + -1;
                  UNLOCK();
                  if (*(int *)pQVar11 == 0) {
                    pQVar11 = *(QArrayData **)(lVar7 + 0x18);
                    goto LAB_00900c6a;
                  }
                }
                piVar8 = *(int **)(lVar7 + 0x20);
                if (piVar8 != (int *)0x0) {
                  LOCK();
                  *piVar8 = *piVar8 + -1;
                  UNLOCK();
                  if ((*piVar8 == 0) && (*(void **)(lVar7 + 0x20) != (void *)0x0)) {
                    operator_delete(*(void **)(lVar7 + 0x20));
                  }
                }
                if (*(long *)(lVar7 + 8) != 0) {
                  FUN_0064e5d8();
                }
                if (*(long *)(lVar7 + 0x10) != 0) {
                  FUN_0064e5d8();
                }
              }
              lVar6 = *(long *)(lVar6 + 0x10);
              if (lVar6 != 0) {
                pQVar11 = *(QArrayData **)(lVar6 + 0x18);
                if (*(int *)pQVar11 == 0) {
LAB_00900c52:
                  QArrayData::deallocate(pQVar11,2,8);
                }
                else if (*(int *)pQVar11 != -1) {
                  LOCK();
                  *(int *)pQVar11 = *(int *)pQVar11 + -1;
                  UNLOCK();
                  if (*(int *)pQVar11 == 0) {
                    pQVar11 = *(QArrayData **)(lVar6 + 0x18);
                    goto LAB_00900c52;
                  }
                }
                piVar8 = *(int **)(lVar6 + 0x20);
                if (piVar8 != (int *)0x0) {
                  LOCK();
                  *piVar8 = *piVar8 + -1;
                  UNLOCK();
                  if ((*piVar8 == 0) && (*(void **)(lVar6 + 0x20) != (void *)0x0)) {
                    operator_delete(*(void **)(lVar6 + 0x20));
                  }
                }
                if (*(long *)(lVar6 + 8) != 0) {
                  FUN_0064e5d8();
                }
                if (*(long *)(lVar6 + 0x10) != 0) {
                  FUN_0064e5d8();
                }
              }
            }
            lVar5 = *(long *)(lVar5 + 0x10);
            if (lVar5 != 0) {
              pQVar11 = *(QArrayData **)(lVar5 + 0x18);
              if (*(int *)pQVar11 == 0) {
LAB_00900adf:
                QArrayData::deallocate(pQVar11,2,8);
              }
              else if (*(int *)pQVar11 != -1) {
                LOCK();
                *(int *)pQVar11 = *(int *)pQVar11 + -1;
                UNLOCK();
                if (*(int *)pQVar11 == 0) {
                  pQVar11 = *(QArrayData **)(lVar5 + 0x18);
                  goto LAB_00900adf;
                }
              }
              piVar8 = *(int **)(lVar5 + 0x20);
              if (piVar8 != (int *)0x0) {
                LOCK();
                *piVar8 = *piVar8 + -1;
                UNLOCK();
                if ((*piVar8 == 0) && (*(void **)(lVar5 + 0x20) != (void *)0x0)) {
                  operator_delete(*(void **)(lVar5 + 0x20));
                }
              }
              lVar6 = *(long *)(lVar5 + 8);
              if (lVar6 != 0) {
                pQVar11 = *(QArrayData **)(lVar6 + 0x18);
                if (*(int *)pQVar11 == 0) {
LAB_00900c00:
                  QArrayData::deallocate(pQVar11,2,8);
                }
                else if (*(int *)pQVar11 != -1) {
                  LOCK();
                  *(int *)pQVar11 = *(int *)pQVar11 + -1;
                  UNLOCK();
                  if (*(int *)pQVar11 == 0) {
                    pQVar11 = *(QArrayData **)(lVar6 + 0x18);
                    goto LAB_00900c00;
                  }
                }
                piVar8 = *(int **)(lVar6 + 0x20);
                if (piVar8 != (int *)0x0) {
                  LOCK();
                  *piVar8 = *piVar8 + -1;
                  UNLOCK();
                  if ((*piVar8 == 0) && (*(void **)(lVar6 + 0x20) != (void *)0x0)) {
                    operator_delete(*(void **)(lVar6 + 0x20));
                  }
                }
                if (*(long *)(lVar6 + 8) != 0) {
                  FUN_0064e5d8();
                }
                if (*(long *)(lVar6 + 0x10) != 0) {
                  FUN_0064e5d8();
                }
              }
              lVar5 = *(long *)(lVar5 + 0x10);
              if (lVar5 != 0) {
                pQVar11 = *(QArrayData **)(lVar5 + 0x18);
                if (*(int *)pQVar11 == 0) {
LAB_00900d3e:
                  QArrayData::deallocate(pQVar11,2,8);
                }
                else if (*(int *)pQVar11 != -1) {
                  LOCK();
                  *(int *)pQVar11 = *(int *)pQVar11 + -1;
                  UNLOCK();
                  if (*(int *)pQVar11 == 0) {
                    pQVar11 = *(QArrayData **)(lVar5 + 0x18);
                    goto LAB_00900d3e;
                  }
                }
                piVar8 = *(int **)(lVar5 + 0x20);
                if (piVar8 != (int *)0x0) {
                  LOCK();
                  *piVar8 = *piVar8 + -1;
                  UNLOCK();
                  if ((*piVar8 == 0) && (*(void **)(lVar5 + 0x20) != (void *)0x0)) {
                    operator_delete(*(void **)(lVar5 + 0x20));
                  }
                }
                if (*(long *)(lVar5 + 8) != 0) {
                  FUN_0064e5d8();
                }
                if (*(long *)(lVar5 + 0x10) != 0) {
                  FUN_0064e5d8();
                }
              }
            }
          }
          lVar4 = *(long *)(lVar4 + 0x10);
          if (lVar4 != 0) {
            pQVar11 = *(QArrayData **)(lVar4 + 0x18);
            if (*(int *)pQVar11 == 0) {
LAB_009009fd:
              QArrayData::deallocate(pQVar11,2,8);
            }
            else if (*(int *)pQVar11 != -1) {
              LOCK();
              *(int *)pQVar11 = *(int *)pQVar11 + -1;
              UNLOCK();
              if (*(int *)pQVar11 == 0) {
                pQVar11 = *(QArrayData **)(lVar4 + 0x18);
                goto LAB_009009fd;
              }
            }
            piVar8 = *(int **)(lVar4 + 0x20);
            if (piVar8 != (int *)0x0) {
              LOCK();
              *piVar8 = *piVar8 + -1;
              UNLOCK();
              if ((*piVar8 == 0) && (*(void **)(lVar4 + 0x20) != (void *)0x0)) {
                operator_delete(*(void **)(lVar4 + 0x20));
              }
            }
            lVar5 = *(long *)(lVar4 + 8);
            if (lVar5 != 0) {
              pQVar11 = *(QArrayData **)(lVar5 + 0x18);
              if (*(int *)pQVar11 == 0) {
LAB_00900b28:
                QArrayData::deallocate(pQVar11,2,8);
              }
              else if (*(int *)pQVar11 != -1) {
                LOCK();
                *(int *)pQVar11 = *(int *)pQVar11 + -1;
                UNLOCK();
                if (*(int *)pQVar11 == 0) {
                  pQVar11 = *(QArrayData **)(lVar5 + 0x18);
                  goto LAB_00900b28;
                }
              }
              piVar8 = *(int **)(lVar5 + 0x20);
              if (piVar8 != (int *)0x0) {
                LOCK();
                *piVar8 = *piVar8 + -1;
                UNLOCK();
                if ((*piVar8 == 0) && (*(void **)(lVar5 + 0x20) != (void *)0x0)) {
                  operator_delete(*(void **)(lVar5 + 0x20));
                }
              }
              lVar6 = *(long *)(lVar5 + 8);
              if (lVar6 != 0) {
                pQVar11 = *(QArrayData **)(lVar6 + 0x18);
                if (*(int *)pQVar11 == 0) {
LAB_00900e73:
                  QArrayData::deallocate(pQVar11,2,8);
                }
                else if (*(int *)pQVar11 != -1) {
                  LOCK();
                  *(int *)pQVar11 = *(int *)pQVar11 + -1;
                  UNLOCK();
                  if (*(int *)pQVar11 == 0) {
                    pQVar11 = *(QArrayData **)(lVar6 + 0x18);
                    goto LAB_00900e73;
                  }
                }
                piVar8 = *(int **)(lVar6 + 0x20);
                if (piVar8 != (int *)0x0) {
                  LOCK();
                  *piVar8 = *piVar8 + -1;
                  UNLOCK();
                  if ((*piVar8 == 0) && (*(void **)(lVar6 + 0x20) != (void *)0x0)) {
                    operator_delete(*(void **)(lVar6 + 0x20));
                  }
                }
                if (*(long *)(lVar6 + 8) != 0) {
                  FUN_0064e5d8();
                }
                if (*(long *)(lVar6 + 0x10) != 0) {
                  FUN_0064e5d8();
                }
              }
              lVar5 = *(long *)(lVar5 + 0x10);
              if (lVar5 != 0) {
                pQVar11 = *(QArrayData **)(lVar5 + 0x18);
                if (*(int *)pQVar11 == 0) {
LAB_00900e8b:
                  QArrayData::deallocate(pQVar11,2,8);
                }
                else if (*(int *)pQVar11 != -1) {
                  LOCK();
                  *(int *)pQVar11 = *(int *)pQVar11 + -1;
                  UNLOCK();
                  if (*(int *)pQVar11 == 0) {
                    pQVar11 = *(QArrayData **)(lVar5 + 0x18);
                    goto LAB_00900e8b;
                  }
                }
                piVar8 = *(int **)(lVar5 + 0x20);
                if (piVar8 != (int *)0x0) {
                  LOCK();
                  *piVar8 = *piVar8 + -1;
                  UNLOCK();
                  if ((*piVar8 == 0) && (*(void **)(lVar5 + 0x20) != (void *)0x0)) {
                    operator_delete(*(void **)(lVar5 + 0x20));
                  }
                }
                if (*(long *)(lVar5 + 8) != 0) {
                  FUN_0064e5d8();
                }
                if (*(long *)(lVar5 + 0x10) != 0) {
                  FUN_0064e5d8();
                }
              }
            }
            lVar4 = *(long *)(lVar4 + 0x10);
            if (lVar4 != 0) {
              pQVar11 = *(QArrayData **)(lVar4 + 0x18);
              if (*(int *)pQVar11 == 0) {
LAB_00900b10:
                QArrayData::deallocate(pQVar11,2,8);
              }
              else if (*(int *)pQVar11 != -1) {
                LOCK();
                *(int *)pQVar11 = *(int *)pQVar11 + -1;
                UNLOCK();
                if (*(int *)pQVar11 == 0) {
                  pQVar11 = *(QArrayData **)(lVar4 + 0x18);
                  goto LAB_00900b10;
                }
              }
              piVar8 = *(int **)(lVar4 + 0x20);
              if (piVar8 != (int *)0x0) {
                LOCK();
                *piVar8 = *piVar8 + -1;
                UNLOCK();
                if ((*piVar8 == 0) && (*(void **)(lVar4 + 0x20) != (void *)0x0)) {
                  operator_delete(*(void **)(lVar4 + 0x20));
                }
              }
              lVar5 = *(long *)(lVar4 + 8);
              if (lVar5 != 0) {
                pQVar11 = *(QArrayData **)(lVar5 + 0x18);
                if (*(int *)pQVar11 == 0) {
LAB_00900be8:
                  QArrayData::deallocate(pQVar11,2,8);
                }
                else if (*(int *)pQVar11 != -1) {
                  LOCK();
                  *(int *)pQVar11 = *(int *)pQVar11 + -1;
                  UNLOCK();
                  if (*(int *)pQVar11 == 0) {
                    pQVar11 = *(QArrayData **)(lVar5 + 0x18);
                    goto LAB_00900be8;
                  }
                }
                piVar8 = *(int **)(lVar5 + 0x20);
                if (piVar8 != (int *)0x0) {
                  LOCK();
                  *piVar8 = *piVar8 + -1;
                  UNLOCK();
                  if ((*piVar8 == 0) && (*(void **)(lVar5 + 0x20) != (void *)0x0)) {
                    operator_delete(*(void **)(lVar5 + 0x20));
                  }
                }
                if (*(long *)(lVar5 + 8) != 0) {
                  FUN_0064e5d8();
                }
                if (*(long *)(lVar5 + 0x10) != 0) {
                  FUN_0064e5d8();
                }
              }
              lVar4 = *(long *)(lVar4 + 0x10);
              if (lVar4 != 0) {
                pQVar11 = *(QArrayData **)(lVar4 + 0x18);
                if (*(int *)pQVar11 == 0) {
LAB_00900bd0:
                  QArrayData::deallocate(pQVar11,2,8);
                }
                else if (*(int *)pQVar11 != -1) {
                  LOCK();
                  *(int *)pQVar11 = *(int *)pQVar11 + -1;
                  UNLOCK();
                  if (*(int *)pQVar11 == 0) {
                    pQVar11 = *(QArrayData **)(lVar4 + 0x18);
                    goto LAB_00900bd0;
                  }
                }
                piVar8 = *(int **)(lVar4 + 0x20);
                if (piVar8 != (int *)0x0) {
                  LOCK();
                  *piVar8 = *piVar8 + -1;
                  UNLOCK();
                  if ((*piVar8 == 0) && (*(void **)(lVar4 + 0x20) != (void *)0x0)) {
                    operator_delete(*(void **)(lVar4 + 0x20));
                  }
                }
                if (*(long *)(lVar4 + 8) != 0) {
                  FUN_0064e5d8();
                }
                if (*(long *)(lVar4 + 0x10) != 0) {
                  FUN_0064e5d8();
                }
              }
            }
          }
        }
      }
      lVar3 = *(long *)(lVar3 + 0x10);
      if (lVar3 != 0) {
        pQVar11 = *(QArrayData **)(lVar3 + 0x18);
        if (*(int *)pQVar11 == 0) {
LAB_008ffe0e:
          QArrayData::deallocate(pQVar11,2,8);
        }
        else if (*(int *)pQVar11 != -1) {
          LOCK();
          *(int *)pQVar11 = *(int *)pQVar11 + -1;
          UNLOCK();
          if (*(int *)pQVar11 == 0) {
            pQVar11 = *(QArrayData **)(lVar3 + 0x18);
            goto LAB_008ffe0e;
          }
        }
        piVar8 = *(int **)(lVar3 + 0x20);
        if (piVar8 != (int *)0x0) {
          LOCK();
          *piVar8 = *piVar8 + -1;
          UNLOCK();
          if ((*piVar8 == 0) && (*(void **)(lVar3 + 0x20) != (void *)0x0)) {
            operator_delete(*(void **)(lVar3 + 0x20));
          }
        }
        lVar4 = *(long *)(lVar3 + 8);
        if (lVar4 != 0) {
          pQVar11 = *(QArrayData **)(lVar4 + 0x18);
          if (*(int *)pQVar11 == 0) {
LAB_00900954:
            QArrayData::deallocate(pQVar11,2,8);
          }
          else if (*(int *)pQVar11 != -1) {
            LOCK();
            *(int *)pQVar11 = *(int *)pQVar11 + -1;
            UNLOCK();
            if (*(int *)pQVar11 == 0) {
              pQVar11 = *(QArrayData **)(lVar4 + 0x18);
              goto LAB_00900954;
            }
          }
          piVar8 = *(int **)(lVar4 + 0x20);
          if (piVar8 != (int *)0x0) {
            LOCK();
            *piVar8 = *piVar8 + -1;
            UNLOCK();
            if ((*piVar8 == 0) && (*(void **)(lVar4 + 0x20) != (void *)0x0)) {
              operator_delete(*(void **)(lVar4 + 0x20));
            }
          }
          lVar5 = *(long *)(lVar4 + 8);
          if (lVar5 != 0) {
            pQVar11 = *(QArrayData **)(lVar5 + 0x18);
            if (*(int *)pQVar11 == 0) {
LAB_009009b4:
              QArrayData::deallocate(pQVar11,2,8);
            }
            else if (*(int *)pQVar11 != -1) {
              LOCK();
              *(int *)pQVar11 = *(int *)pQVar11 + -1;
              UNLOCK();
              if (*(int *)pQVar11 == 0) {
                pQVar11 = *(QArrayData **)(lVar5 + 0x18);
                goto LAB_009009b4;
              }
            }
            piVar8 = *(int **)(lVar5 + 0x20);
            if (piVar8 != (int *)0x0) {
              LOCK();
              *piVar8 = *piVar8 + -1;
              UNLOCK();
              if ((*piVar8 == 0) && (*(void **)(lVar5 + 0x20) != (void *)0x0)) {
                operator_delete(*(void **)(lVar5 + 0x20));
              }
            }
            lVar6 = *(long *)(lVar5 + 8);
            if (lVar6 != 0) {
              pQVar11 = *(QArrayData **)(lVar6 + 0x18);
              if (*(int *)pQVar11 == 0) {
LAB_00900a2d:
                QArrayData::deallocate(pQVar11,2,8);
              }
              else if (*(int *)pQVar11 != -1) {
                LOCK();
                *(int *)pQVar11 = *(int *)pQVar11 + -1;
                UNLOCK();
                if (*(int *)pQVar11 == 0) {
                  pQVar11 = *(QArrayData **)(lVar6 + 0x18);
                  goto LAB_00900a2d;
                }
              }
              piVar8 = *(int **)(lVar6 + 0x20);
              if (piVar8 != (int *)0x0) {
                LOCK();
                *piVar8 = *piVar8 + -1;
                UNLOCK();
                if ((*piVar8 == 0) && (*(void **)(lVar6 + 0x20) != (void *)0x0)) {
                  operator_delete(*(void **)(lVar6 + 0x20));
                }
              }
              lVar7 = *(long *)(lVar6 + 8);
              if (lVar7 != 0) {
                pQVar11 = *(QArrayData **)(lVar7 + 0x18);
                if (*(int *)pQVar11 == 0) {
LAB_00900d6e:
                  QArrayData::deallocate(pQVar11,2,8);
                }
                else if (*(int *)pQVar11 != -1) {
                  LOCK();
                  *(int *)pQVar11 = *(int *)pQVar11 + -1;
                  UNLOCK();
                  if (*(int *)pQVar11 == 0) {
                    pQVar11 = *(QArrayData **)(lVar7 + 0x18);
                    goto LAB_00900d6e;
                  }
                }
                piVar8 = *(int **)(lVar7 + 0x20);
                if (piVar8 != (int *)0x0) {
                  LOCK();
                  *piVar8 = *piVar8 + -1;
                  UNLOCK();
                  if ((*piVar8 == 0) && (*(void **)(lVar7 + 0x20) != (void *)0x0)) {
                    operator_delete(*(void **)(lVar7 + 0x20));
                  }
                }
                if (*(long *)(lVar7 + 8) != 0) {
                  FUN_0064e5d8();
                }
                if (*(long *)(lVar7 + 0x10) != 0) {
                  FUN_0064e5d8();
                }
              }
              lVar6 = *(long *)(lVar6 + 0x10);
              if (lVar6 != 0) {
                pQVar11 = *(QArrayData **)(lVar6 + 0x18);
                if (*(int *)pQVar11 == 0) {
LAB_00900d56:
                  QArrayData::deallocate(pQVar11,2,8);
                }
                else if (*(int *)pQVar11 != -1) {
                  LOCK();
                  *(int *)pQVar11 = *(int *)pQVar11 + -1;
                  UNLOCK();
                  if (*(int *)pQVar11 == 0) {
                    pQVar11 = *(QArrayData **)(lVar6 + 0x18);
                    goto LAB_00900d56;
                  }
                }
                piVar8 = *(int **)(lVar6 + 0x20);
                if (piVar8 != (int *)0x0) {
                  LOCK();
                  *piVar8 = *piVar8 + -1;
                  UNLOCK();
                  if ((*piVar8 == 0) && (*(void **)(lVar6 + 0x20) != (void *)0x0)) {
                    operator_delete(*(void **)(lVar6 + 0x20));
                  }
                }
                if (*(long *)(lVar6 + 8) != 0) {
                  FUN_0064e5d8();
                }
                if (*(long *)(lVar6 + 0x10) != 0) {
                  FUN_0064e5d8();
                }
              }
            }
            lVar5 = *(long *)(lVar5 + 0x10);
            if (lVar5 != 0) {
              pQVar11 = *(QArrayData **)(lVar5 + 0x18);
              if (*(int *)pQVar11 == 0) {
LAB_00900a45:
                QArrayData::deallocate(pQVar11,2,8);
              }
              else if (*(int *)pQVar11 != -1) {
                LOCK();
                *(int *)pQVar11 = *(int *)pQVar11 + -1;
                UNLOCK();
                if (*(int *)pQVar11 == 0) {
                  pQVar11 = *(QArrayData **)(lVar5 + 0x18);
                  goto LAB_00900a45;
                }
              }
              piVar8 = *(int **)(lVar5 + 0x20);
              if (piVar8 != (int *)0x0) {
                LOCK();
                *piVar8 = *piVar8 + -1;
                UNLOCK();
                if ((*piVar8 == 0) && (*(void **)(lVar5 + 0x20) != (void *)0x0)) {
                  operator_delete(*(void **)(lVar5 + 0x20));
                }
              }
              lVar6 = *(long *)(lVar5 + 8);
              if (lVar6 != 0) {
                pQVar11 = *(QArrayData **)(lVar6 + 0x18);
                if (*(int *)pQVar11 == 0) {
LAB_00900e43:
                  QArrayData::deallocate(pQVar11,2,8);
                }
                else if (*(int *)pQVar11 != -1) {
                  LOCK();
                  *(int *)pQVar11 = *(int *)pQVar11 + -1;
                  UNLOCK();
                  if (*(int *)pQVar11 == 0) {
                    pQVar11 = *(QArrayData **)(lVar6 + 0x18);
                    goto LAB_00900e43;
                  }
                }
                piVar8 = *(int **)(lVar6 + 0x20);
                if (piVar8 != (int *)0x0) {
                  LOCK();
                  *piVar8 = *piVar8 + -1;
                  UNLOCK();
                  if ((*piVar8 == 0) && (*(void **)(lVar6 + 0x20) != (void *)0x0)) {
                    operator_delete(*(void **)(lVar6 + 0x20));
                  }
                }
                if (*(long *)(lVar6 + 8) != 0) {
                  FUN_0064e5d8();
                }
                if (*(long *)(lVar6 + 0x10) != 0) {
                  FUN_0064e5d8();
                }
              }
              lVar5 = *(long *)(lVar5 + 0x10);
              if (lVar5 != 0) {
                pQVar11 = *(QArrayData **)(lVar5 + 0x18);
                if (*(int *)pQVar11 == 0) {
LAB_00900c18:
                  QArrayData::deallocate(pQVar11,2,8);
                }
                else if (*(int *)pQVar11 != -1) {
                  LOCK();
                  *(int *)pQVar11 = *(int *)pQVar11 + -1;
                  UNLOCK();
                  if (*(int *)pQVar11 == 0) {
                    pQVar11 = *(QArrayData **)(lVar5 + 0x18);
                    goto LAB_00900c18;
                  }
                }
                piVar8 = *(int **)(lVar5 + 0x20);
                if (piVar8 != (int *)0x0) {
                  LOCK();
                  *piVar8 = *piVar8 + -1;
                  UNLOCK();
                  if ((*piVar8 == 0) && (*(void **)(lVar5 + 0x20) != (void *)0x0)) {
                    operator_delete(*(void **)(lVar5 + 0x20));
                  }
                }
                if (*(long *)(lVar5 + 8) != 0) {
                  FUN_0064e5d8();
                }
                if (*(long *)(lVar5 + 0x10) != 0) {
                  FUN_0064e5d8();
                }
              }
            }
          }
          lVar4 = *(long *)(lVar4 + 0x10);
          if (lVar4 != 0) {
            pQVar11 = *(QArrayData **)(lVar4 + 0x18);
            if (*(int *)pQVar11 == 0) {
LAB_0090099c:
              QArrayData::deallocate(pQVar11,2,8);
            }
            else if (*(int *)pQVar11 != -1) {
              LOCK();
              *(int *)pQVar11 = *(int *)pQVar11 + -1;
              UNLOCK();
              if (*(int *)pQVar11 == 0) {
                pQVar11 = *(QArrayData **)(lVar4 + 0x18);
                goto LAB_0090099c;
              }
            }
            piVar8 = *(int **)(lVar4 + 0x20);
            if (piVar8 != (int *)0x0) {
              LOCK();
              *piVar8 = *piVar8 + -1;
              UNLOCK();
              if ((*piVar8 == 0) && (*(void **)(lVar4 + 0x20) != (void *)0x0)) {
                operator_delete(*(void **)(lVar4 + 0x20));
              }
            }
            lVar5 = *(long *)(lVar4 + 8);
            if (lVar5 != 0) {
              pQVar11 = *(QArrayData **)(lVar5 + 0x18);
              if (*(int *)pQVar11 == 0) {
LAB_00900aaf:
                QArrayData::deallocate(pQVar11,2,8);
              }
              else if (*(int *)pQVar11 != -1) {
                LOCK();
                *(int *)pQVar11 = *(int *)pQVar11 + -1;
                UNLOCK();
                if (*(int *)pQVar11 == 0) {
                  pQVar11 = *(QArrayData **)(lVar5 + 0x18);
                  goto LAB_00900aaf;
                }
              }
              piVar8 = *(int **)(lVar5 + 0x20);
              if (piVar8 != (int *)0x0) {
                LOCK();
                *piVar8 = *piVar8 + -1;
                UNLOCK();
                if ((*piVar8 == 0) && (*(void **)(lVar5 + 0x20) != (void *)0x0)) {
                  operator_delete(*(void **)(lVar5 + 0x20));
                }
              }
              lVar6 = *(long *)(lVar5 + 8);
              if (lVar6 != 0) {
                pQVar11 = *(QArrayData **)(lVar6 + 0x18);
                if (*(int *)pQVar11 == 0) {
LAB_00900d26:
                  QArrayData::deallocate(pQVar11,2,8);
                }
                else if (*(int *)pQVar11 != -1) {
                  LOCK();
                  *(int *)pQVar11 = *(int *)pQVar11 + -1;
                  UNLOCK();
                  if (*(int *)pQVar11 == 0) {
                    pQVar11 = *(QArrayData **)(lVar6 + 0x18);
                    goto LAB_00900d26;
                  }
                }
                piVar8 = *(int **)(lVar6 + 0x20);
                if (piVar8 != (int *)0x0) {
                  LOCK();
                  *piVar8 = *piVar8 + -1;
                  UNLOCK();
                  if ((*piVar8 == 0) && (*(void **)(lVar6 + 0x20) != (void *)0x0)) {
                    operator_delete(*(void **)(lVar6 + 0x20));
                  }
                }
                if (*(long *)(lVar6 + 8) != 0) {
                  FUN_0064e5d8();
                }
                if (*(long *)(lVar6 + 0x10) != 0) {
                  FUN_0064e5d8();
                }
              }
              lVar5 = *(long *)(lVar5 + 0x10);
              if (lVar5 != 0) {
                pQVar11 = *(QArrayData **)(lVar5 + 0x18);
                if (*(int *)pQVar11 == 0) {
LAB_00900cec:
                  QArrayData::deallocate(pQVar11,2,8);
                }
                else if (*(int *)pQVar11 != -1) {
                  LOCK();
                  *(int *)pQVar11 = *(int *)pQVar11 + -1;
                  UNLOCK();
                  if (*(int *)pQVar11 == 0) {
                    pQVar11 = *(QArrayData **)(lVar5 + 0x18);
                    goto LAB_00900cec;
                  }
                }
                piVar8 = *(int **)(lVar5 + 0x20);
                if (piVar8 != (int *)0x0) {
                  LOCK();
                  *piVar8 = *piVar8 + -1;
                  UNLOCK();
                  if ((*piVar8 == 0) && (*(void **)(lVar5 + 0x20) != (void *)0x0)) {
                    operator_delete(*(void **)(lVar5 + 0x20));
                  }
                }
                if (*(long *)(lVar5 + 8) != 0) {
                  FUN_0064e5d8();
                }
                if (*(long *)(lVar5 + 0x10) != 0) {
                  FUN_0064e5d8();
                }
              }
            }
            lVar4 = *(long *)(lVar4 + 0x10);
            if (lVar4 != 0) {
              pQVar11 = *(QArrayData **)(lVar4 + 0x18);
              if (*(int *)pQVar11 == 0) {
LAB_00900a97:
                QArrayData::deallocate(pQVar11,2,8);
              }
              else if (*(int *)pQVar11 != -1) {
                LOCK();
                *(int *)pQVar11 = *(int *)pQVar11 + -1;
                UNLOCK();
                if (*(int *)pQVar11 == 0) {
                  pQVar11 = *(QArrayData **)(lVar4 + 0x18);
                  goto LAB_00900a97;
                }
              }
              piVar8 = *(int **)(lVar4 + 0x20);
              if (piVar8 != (int *)0x0) {
                LOCK();
                *piVar8 = *piVar8 + -1;
                UNLOCK();
                if ((*piVar8 == 0) && (*(void **)(lVar4 + 0x20) != (void *)0x0)) {
                  operator_delete(*(void **)(lVar4 + 0x20));
                }
              }
              lVar5 = *(long *)(lVar4 + 8);
              if (lVar5 != 0) {
                pQVar11 = *(QArrayData **)(lVar5 + 0x18);
                if (*(int *)pQVar11 == 0) {
LAB_00900cd4:
                  QArrayData::deallocate(pQVar11,2,8);
                }
                else if (*(int *)pQVar11 != -1) {
                  LOCK();
                  *(int *)pQVar11 = *(int *)pQVar11 + -1;
                  UNLOCK();
                  if (*(int *)pQVar11 == 0) {
                    pQVar11 = *(QArrayData **)(lVar5 + 0x18);
                    goto LAB_00900cd4;
                  }
                }
                piVar8 = *(int **)(lVar5 + 0x20);
                if (piVar8 != (int *)0x0) {
                  LOCK();
                  *piVar8 = *piVar8 + -1;
                  UNLOCK();
                  if ((*piVar8 == 0) && (*(void **)(lVar5 + 0x20) != (void *)0x0)) {
                    operator_delete(*(void **)(lVar5 + 0x20));
                  }
                }
                if (*(long *)(lVar5 + 8) != 0) {
                  FUN_0064e5d8();
                }
                if (*(long *)(lVar5 + 0x10) != 0) {
                  FUN_0064e5d8();
                }
              }
              lVar4 = *(long *)(lVar4 + 0x10);
              if (lVar4 != 0) {
                pQVar11 = *(QArrayData **)(lVar4 + 0x18);
                if (*(int *)pQVar11 == 0) {
LAB_00900cbc:
                  QArrayData::deallocate(pQVar11,2,8);
                }
                else if (*(int *)pQVar11 != -1) {
                  LOCK();
                  *(int *)pQVar11 = *(int *)pQVar11 + -1;
                  UNLOCK();
                  if (*(int *)pQVar11 == 0) {
                    pQVar11 = *(QArrayData **)(lVar4 + 0x18);
                    goto LAB_00900cbc;
                  }
                }
                piVar8 = *(int **)(lVar4 + 0x20);
                if (piVar8 != (int *)0x0) {
                  LOCK();
                  *piVar8 = *piVar8 + -1;
                  UNLOCK();
                  if ((*piVar8 == 0) && (*(void **)(lVar4 + 0x20) != (void *)0x0)) {
                    operator_delete(*(void **)(lVar4 + 0x20));
                  }
                }
                if (*(long *)(lVar4 + 8) != 0) {
                  FUN_0064e5d8();
                }
                if (*(long *)(lVar4 + 0x10) != 0) {
                  FUN_0064e5d8();
                }
              }
            }
          }
        }
        lVar3 = *(long *)(lVar3 + 0x10);
        if (lVar3 != 0) {
          pQVar11 = *(QArrayData **)(lVar3 + 0x18);
          if (*(int *)pQVar11 == 0) {
LAB_00900924:
            QArrayData::deallocate(pQVar11,2,8);
          }
          else if (*(int *)pQVar11 != -1) {
            LOCK();
            *(int *)pQVar11 = *(int *)pQVar11 + -1;
            UNLOCK();
            if (*(int *)pQVar11 == 0) {
              pQVar11 = *(QArrayData **)(lVar3 + 0x18);
              goto LAB_00900924;
            }
          }
          piVar8 = *(int **)(lVar3 + 0x20);
          if (piVar8 != (int *)0x0) {
            LOCK();
            *piVar8 = *piVar8 + -1;
            UNLOCK();
            if ((*piVar8 == 0) && (*(void **)(lVar3 + 0x20) != (void *)0x0)) {
              operator_delete(*(void **)(lVar3 + 0x20));
            }
          }
          lVar4 = *(long *)(lVar3 + 8);
          if (lVar4 != 0) {
            pQVar11 = *(QArrayData **)(lVar4 + 0x18);
            if (*(int *)pQVar11 == 0) {
LAB_009009e5:
              QArrayData::deallocate(pQVar11,2,8);
            }
            else if (*(int *)pQVar11 != -1) {
              LOCK();
              *(int *)pQVar11 = *(int *)pQVar11 + -1;
              UNLOCK();
              if (*(int *)pQVar11 == 0) {
                pQVar11 = *(QArrayData **)(lVar4 + 0x18);
                goto LAB_009009e5;
              }
            }
            piVar8 = *(int **)(lVar4 + 0x20);
            if (piVar8 != (int *)0x0) {
              LOCK();
              *piVar8 = *piVar8 + -1;
              UNLOCK();
              if ((*piVar8 == 0) && (*(void **)(lVar4 + 0x20) != (void *)0x0)) {
                operator_delete(*(void **)(lVar4 + 0x20));
              }
            }
            lVar5 = *(long *)(lVar4 + 8);
            if (lVar5 != 0) {
              pQVar11 = *(QArrayData **)(lVar5 + 0x18);
              if (*(int *)pQVar11 == 0) {
LAB_00900b40:
                QArrayData::deallocate(pQVar11,2,8);
              }
              else if (*(int *)pQVar11 != -1) {
                LOCK();
                *(int *)pQVar11 = *(int *)pQVar11 + -1;
                UNLOCK();
                if (*(int *)pQVar11 == 0) {
                  pQVar11 = *(QArrayData **)(lVar5 + 0x18);
                  goto LAB_00900b40;
                }
              }
              piVar8 = *(int **)(lVar5 + 0x20);
              if (piVar8 != (int *)0x0) {
                LOCK();
                *piVar8 = *piVar8 + -1;
                UNLOCK();
                if ((*piVar8 == 0) && (*(void **)(lVar5 + 0x20) != (void *)0x0)) {
                  operator_delete(*(void **)(lVar5 + 0x20));
                }
              }
              lVar6 = *(long *)(lVar5 + 8);
              if (lVar6 != 0) {
                pQVar11 = *(QArrayData **)(lVar6 + 0x18);
                if (*(int *)pQVar11 == 0) {
LAB_00900ebb:
                  QArrayData::deallocate(pQVar11,2,8);
                }
                else if (*(int *)pQVar11 != -1) {
                  LOCK();
                  *(int *)pQVar11 = *(int *)pQVar11 + -1;
                  UNLOCK();
                  if (*(int *)pQVar11 == 0) {
                    pQVar11 = *(QArrayData **)(lVar6 + 0x18);
                    goto LAB_00900ebb;
                  }
                }
                piVar8 = *(int **)(lVar6 + 0x20);
                if (piVar8 != (int *)0x0) {
                  LOCK();
                  *piVar8 = *piVar8 + -1;
                  UNLOCK();
                  if ((*piVar8 == 0) && (*(void **)(lVar6 + 0x20) != (void *)0x0)) {
                    operator_delete(*(void **)(lVar6 + 0x20));
                  }
                }
                if (*(long *)(lVar6 + 8) != 0) {
                  FUN_0064e5d8();
                }
                if (*(long *)(lVar6 + 0x10) != 0) {
                  FUN_0064e5d8();
                }
              }
              lVar5 = *(long *)(lVar5 + 0x10);
              if (lVar5 != 0) {
                pQVar11 = *(QArrayData **)(lVar5 + 0x18);
                if (*(int *)pQVar11 == 0) {
LAB_00900ea3:
                  QArrayData::deallocate(pQVar11,2,8);
                }
                else if (*(int *)pQVar11 != -1) {
                  LOCK();
                  *(int *)pQVar11 = *(int *)pQVar11 + -1;
                  UNLOCK();
                  if (*(int *)pQVar11 == 0) {
                    pQVar11 = *(QArrayData **)(lVar5 + 0x18);
                    goto LAB_00900ea3;
                  }
                }
                piVar8 = *(int **)(lVar5 + 0x20);
                if (piVar8 != (int *)0x0) {
                  LOCK();
                  *piVar8 = *piVar8 + -1;
                  UNLOCK();
                  if ((*piVar8 == 0) && (*(void **)(lVar5 + 0x20) != (void *)0x0)) {
                    operator_delete(*(void **)(lVar5 + 0x20));
                  }
                }
                if (*(long *)(lVar5 + 8) != 0) {
                  FUN_0064e5d8();
                }
                if (*(long *)(lVar5 + 0x10) != 0) {
                  FUN_0064e5d8();
                }
              }
            }
            lVar4 = *(long *)(lVar4 + 0x10);
            if (lVar4 != 0) {
              pQVar11 = *(QArrayData **)(lVar4 + 0x18);
              if (*(int *)pQVar11 == 0) {
LAB_00900b88:
                QArrayData::deallocate(pQVar11,2,8);
              }
              else if (*(int *)pQVar11 != -1) {
                LOCK();
                *(int *)pQVar11 = *(int *)pQVar11 + -1;
                UNLOCK();
                if (*(int *)pQVar11 == 0) {
                  pQVar11 = *(QArrayData **)(lVar4 + 0x18);
                  goto LAB_00900b88;
                }
              }
              piVar8 = *(int **)(lVar4 + 0x20);
              if (piVar8 != (int *)0x0) {
                LOCK();
                *piVar8 = *piVar8 + -1;
                UNLOCK();
                if ((*piVar8 == 0) && (*(void **)(lVar4 + 0x20) != (void *)0x0)) {
                  operator_delete(*(void **)(lVar4 + 0x20));
                }
              }
              lVar5 = *(long *)(lVar4 + 8);
              if (lVar5 != 0) {
                pQVar11 = *(QArrayData **)(lVar5 + 0x18);
                if (*(int *)pQVar11 == 0) {
LAB_00900de3:
                  QArrayData::deallocate(pQVar11,2,8);
                }
                else if (*(int *)pQVar11 != -1) {
                  LOCK();
                  *(int *)pQVar11 = *(int *)pQVar11 + -1;
                  UNLOCK();
                  if (*(int *)pQVar11 == 0) {
                    pQVar11 = *(QArrayData **)(lVar5 + 0x18);
                    goto LAB_00900de3;
                  }
                }
                piVar8 = *(int **)(lVar5 + 0x20);
                if (piVar8 != (int *)0x0) {
                  LOCK();
                  *piVar8 = *piVar8 + -1;
                  UNLOCK();
                  if ((*piVar8 == 0) && (*(void **)(lVar5 + 0x20) != (void *)0x0)) {
                    operator_delete(*(void **)(lVar5 + 0x20));
                  }
                }
                if (*(long *)(lVar5 + 8) != 0) {
                  FUN_0064e5d8();
                }
                if (*(long *)(lVar5 + 0x10) != 0) {
                  FUN_0064e5d8();
                }
              }
              lVar4 = *(long *)(lVar4 + 0x10);
              if (lVar4 != 0) {
                pQVar11 = *(QArrayData **)(lVar4 + 0x18);
                if (*(int *)pQVar11 == 0) {
LAB_00900dfb:
                  QArrayData::deallocate(pQVar11,2,8);
                }
                else if (*(int *)pQVar11 != -1) {
                  LOCK();
                  *(int *)pQVar11 = *(int *)pQVar11 + -1;
                  UNLOCK();
                  if (*(int *)pQVar11 == 0) {
                    pQVar11 = *(QArrayData **)(lVar4 + 0x18);
                    goto LAB_00900dfb;
                  }
                }
                piVar8 = *(int **)(lVar4 + 0x20);
                if (piVar8 != (int *)0x0) {
                  LOCK();
                  *piVar8 = *piVar8 + -1;
                  UNLOCK();
                  if ((*piVar8 == 0) && (*(void **)(lVar4 + 0x20) != (void *)0x0)) {
                    operator_delete(*(void **)(lVar4 + 0x20));
                  }
                }
                if (*(long *)(lVar4 + 8) != 0) {
                  FUN_0064e5d8();
                }
                if (*(long *)(lVar4 + 0x10) != 0) {
                  FUN_0064e5d8();
                }
              }
            }
          }
          lVar3 = *(long *)(lVar3 + 0x10);
          if (lVar3 != 0) {
            pQVar11 = *(QArrayData **)(lVar3 + 0x18);
            if (*(int *)pQVar11 == 0) {
LAB_009009cd:
              QArrayData::deallocate(pQVar11,2,8);
            }
            else if (*(int *)pQVar11 != -1) {
              LOCK();
              *(int *)pQVar11 = *(int *)pQVar11 + -1;
              UNLOCK();
              if (*(int *)pQVar11 == 0) {
                pQVar11 = *(QArrayData **)(lVar3 + 0x18);
                goto LAB_009009cd;
              }
            }
            piVar8 = *(int **)(lVar3 + 0x20);
            if (piVar8 != (int *)0x0) {
              LOCK();
              *piVar8 = *piVar8 + -1;
              UNLOCK();
              if ((*piVar8 == 0) && (*(void **)(lVar3 + 0x20) != (void *)0x0)) {
                operator_delete(*(void **)(lVar3 + 0x20));
              }
            }
            lVar4 = *(long *)(lVar3 + 8);
            if (lVar4 != 0) {
              pQVar11 = *(QArrayData **)(lVar4 + 0x18);
              if (*(int *)pQVar11 == 0) {
LAB_00900ba0:
                QArrayData::deallocate(pQVar11,2,8);
              }
              else if (*(int *)pQVar11 != -1) {
                LOCK();
                *(int *)pQVar11 = *(int *)pQVar11 + -1;
                UNLOCK();
                if (*(int *)pQVar11 == 0) {
                  pQVar11 = *(QArrayData **)(lVar4 + 0x18);
                  goto LAB_00900ba0;
                }
              }
              piVar8 = *(int **)(lVar4 + 0x20);
              if (piVar8 != (int *)0x0) {
                LOCK();
                *piVar8 = *piVar8 + -1;
                UNLOCK();
                if ((*piVar8 == 0) && (*(void **)(lVar4 + 0x20) != (void *)0x0)) {
                  operator_delete(*(void **)(lVar4 + 0x20));
                }
              }
              lVar5 = *(long *)(lVar4 + 8);
              if (lVar5 != 0) {
                pQVar11 = *(QArrayData **)(lVar5 + 0x18);
                if (*(int *)pQVar11 == 0) {
LAB_00900e2b:
                  QArrayData::deallocate(pQVar11,2,8);
                }
                else if (*(int *)pQVar11 != -1) {
                  LOCK();
                  *(int *)pQVar11 = *(int *)pQVar11 + -1;
                  UNLOCK();
                  if (*(int *)pQVar11 == 0) {
                    pQVar11 = *(QArrayData **)(lVar5 + 0x18);
                    goto LAB_00900e2b;
                  }
                }
                piVar8 = *(int **)(lVar5 + 0x20);
                if (piVar8 != (int *)0x0) {
                  LOCK();
                  *piVar8 = *piVar8 + -1;
                  UNLOCK();
                  if ((*piVar8 == 0) && (*(void **)(lVar5 + 0x20) != (void *)0x0)) {
                    operator_delete(*(void **)(lVar5 + 0x20));
                  }
                }
                if (*(long *)(lVar5 + 8) != 0) {
                  FUN_0064e5d8();
                }
                if (*(long *)(lVar5 + 0x10) != 0) {
                  FUN_0064e5d8();
                }
              }
              lVar4 = *(long *)(lVar4 + 0x10);
              if (lVar4 != 0) {
                pQVar11 = *(QArrayData **)(lVar4 + 0x18);
                if (*(int *)pQVar11 == 0) {
LAB_00900e5b:
                  QArrayData::deallocate(pQVar11,2,8);
                }
                else if (*(int *)pQVar11 != -1) {
                  LOCK();
                  *(int *)pQVar11 = *(int *)pQVar11 + -1;
                  UNLOCK();
                  if (*(int *)pQVar11 == 0) {
                    pQVar11 = *(QArrayData **)(lVar4 + 0x18);
                    goto LAB_00900e5b;
                  }
                }
                piVar8 = *(int **)(lVar4 + 0x20);
                if (piVar8 != (int *)0x0) {
                  LOCK();
                  *piVar8 = *piVar8 + -1;
                  UNLOCK();
                  if ((*piVar8 == 0) && (*(void **)(lVar4 + 0x20) != (void *)0x0)) {
                    operator_delete(*(void **)(lVar4 + 0x20));
                  }
                }
                if (*(long *)(lVar4 + 8) != 0) {
                  FUN_0064e5d8();
                }
                if (*(long *)(lVar4 + 0x10) != 0) {
                  FUN_0064e5d8();
                }
              }
            }
            lVar3 = *(long *)(lVar3 + 0x10);
            if (lVar3 != 0) {
              pQVar11 = *(QArrayData **)(lVar3 + 0x18);
              if (*(int *)pQVar11 == 0) {
LAB_00900af8:
                QArrayData::deallocate(pQVar11,2,8);
              }
              else if (*(int *)pQVar11 != -1) {
                LOCK();
                *(int *)pQVar11 = *(int *)pQVar11 + -1;
                UNLOCK();
                if (*(int *)pQVar11 == 0) {
                  pQVar11 = *(QArrayData **)(lVar3 + 0x18);
                  goto LAB_00900af8;
                }
              }
              piVar8 = *(int **)(lVar3 + 0x20);
              if (piVar8 != (int *)0x0) {
                LOCK();
                *piVar8 = *piVar8 + -1;
                UNLOCK();
                if ((*piVar8 == 0) && (*(void **)(lVar3 + 0x20) != (void *)0x0)) {
                  operator_delete(*(void **)(lVar3 + 0x20));
                }
              }
              lVar4 = *(long *)(lVar3 + 8);
              if (lVar4 != 0) {
                pQVar11 = *(QArrayData **)(lVar4 + 0x18);
                if (*(int *)pQVar11 == 0) {
LAB_00900e13:
                  QArrayData::deallocate(pQVar11,2,8);
                }
                else if (*(int *)pQVar11 != -1) {
                  LOCK();
                  *(int *)pQVar11 = *(int *)pQVar11 + -1;
                  UNLOCK();
                  if (*(int *)pQVar11 == 0) {
                    pQVar11 = *(QArrayData **)(lVar4 + 0x18);
                    goto LAB_00900e13;
                  }
                }
                piVar8 = *(int **)(lVar4 + 0x20);
                if (piVar8 != (int *)0x0) {
                  LOCK();
                  *piVar8 = *piVar8 + -1;
                  UNLOCK();
                  if ((*piVar8 == 0) && (*(void **)(lVar4 + 0x20) != (void *)0x0)) {
                    operator_delete(*(void **)(lVar4 + 0x20));
                  }
                }
                if (*(long *)(lVar4 + 8) != 0) {
                  FUN_0064e5d8();
                }
                if (*(long *)(lVar4 + 0x10) != 0) {
                  FUN_0064e5d8();
                }
              }
              lVar3 = *(long *)(lVar3 + 0x10);
              if (lVar3 != 0) {
                pQVar11 = *(QArrayData **)(lVar3 + 0x18);
                if (*(int *)pQVar11 == 0) {
LAB_00900d91:
                  QArrayData::deallocate(pQVar11,2,8);
                }
                else if (*(int *)pQVar11 != -1) {
                  LOCK();
                  *(int *)pQVar11 = *(int *)pQVar11 + -1;
                  UNLOCK();
                  if (*(int *)pQVar11 == 0) {
                    pQVar11 = *(QArrayData **)(lVar3 + 0x18);
                    goto LAB_00900d91;
                  }
                }
                piVar8 = *(int **)(lVar3 + 0x20);
                if (piVar8 != (int *)0x0) {
                  LOCK();
                  *piVar8 = *piVar8 + -1;
                  UNLOCK();
                  if ((*piVar8 == 0) && (*(void **)(lVar3 + 0x20) != (void *)0x0)) {
                    operator_delete(*(void **)(lVar3 + 0x20));
                  }
                }
                if (*(long *)(lVar3 + 8) != 0) {
                  FUN_0064e5d8();
                }
                if (*(long *)(lVar3 + 0x10) != 0) {
                  FUN_0064e5d8();
                }
              }
            }
          }
        }
      }
      QMapDataBase::freeTree(pQVar9,(int)*(undefined8 *)(pQVar9 + 0x10));
    }
    QMapDataBase::freeData((QMapDataBase *)pQVar9);
    pDVar12 = *(Data **)(param_1 + 0x18);
    iVar2 = *(int *)pDVar12;
  }
  else {
    if (*(int *)pQVar9 != -1) {
      LOCK();
      *(int *)pQVar9 = *(int *)pQVar9 + -1;
      UNLOCK();
      if (*(int *)pQVar9 == 0) {
        pQVar9 = *(QMapNodeBase **)(param_1 + 0x20);
        goto LAB_008ff36e;
      }
    }
    pDVar12 = *(Data **)(param_1 + 0x18);
    iVar2 = *(int *)pDVar12;
  }
  if (iVar2 != 0) {
    if (iVar2 == -1) goto LAB_008ff347;
    LOCK();
    *(int *)pDVar12 = *(int *)pDVar12 + -1;
    UNLOCK();
    if (*(int *)pDVar12 != 0) goto LAB_008ff347;
    pDVar12 = *(Data **)(param_1 + 0x18);
  }
  pDVar10 = pDVar12 + (long)*(int *)(pDVar12 + 0xc) * 8 + 0x10;
  iVar2 = *(int *)(pDVar12 + 8);
joined_r0x0090087b:
  if (pDVar10 != pDVar12 + (long)iVar2 * 8 + 0x10) {
    do {
      pDVar10 = pDVar10 + -8;
      piVar8 = *(int **)pDVar10;
      if (*piVar8 != 0) {
        if (*piVar8 == -1) goto joined_r0x0090087b;
        LOCK();
        iVar1 = *piVar8;
        *piVar8 = *piVar8 + -1;
        UNLOCK();
        if (iVar1 != 1) goto joined_r0x0090087b;
      }
      QArrayData::deallocate(*(QArrayData **)pDVar10,2,8);
      if (pDVar12 + (long)iVar2 * 8 + 0x10 == pDVar10) break;
    } while( true );
  }
  QListData::dispose(pDVar12);
LAB_008ff347:
  QObject::~QObject(param_1);
  operator_delete(param_1,0x28);
  return;
}


// ==== entry=00900ed0 orig=FUN_00900ed0 size=7140 name=MediaCenter_dtor ====

void MediaCenter_dtor(QObject *param_1)

{
  int iVar1;
  int iVar2;
  long lVar3;
  long lVar4;
  long lVar5;
  long lVar6;
  long lVar7;
  long lVar8;
  int *piVar9;
  QMapNodeBase *pQVar10;
  Data *pDVar11;
  QArrayData *pQVar12;
  Data *pDVar13;
  
  *(undefined ***)param_1 = &MediaCenter_vtable;
  pQVar10 = *(QMapNodeBase **)(param_1 + 0x20);
  if (*(int *)pQVar10 == 0) {
LAB_00900f3f:
    lVar3 = *(long *)(pQVar10 + 0x10);
    if (lVar3 != 0) {
      pQVar12 = *(QArrayData **)(lVar3 + 0x18);
      if (*(int *)pQVar12 == 0) {
LAB_009024ba:
        QArrayData::deallocate(pQVar12,2,8);
      }
      else if (*(int *)pQVar12 != -1) {
        LOCK();
        *(int *)pQVar12 = *(int *)pQVar12 + -1;
        UNLOCK();
        if (*(int *)pQVar12 == 0) {
          pQVar12 = *(QArrayData **)(lVar3 + 0x18);
          goto LAB_009024ba;
        }
      }
      piVar9 = *(int **)(lVar3 + 0x20);
      if (piVar9 != (int *)0x0) {
        LOCK();
        *piVar9 = *piVar9 + -1;
        UNLOCK();
        if ((*piVar9 == 0) && (*(void **)(lVar3 + 0x20) != (void *)0x0)) {
          operator_delete(*(void **)(lVar3 + 0x20));
        }
      }
      lVar4 = *(long *)(lVar3 + 8);
      if (lVar4 != 0) {
        pQVar12 = *(QArrayData **)(lVar4 + 0x18);
        if (*(int *)pQVar12 == 0) {
LAB_00900fa5:
          QArrayData::deallocate(pQVar12,2,8);
        }
        else if (*(int *)pQVar12 != -1) {
          LOCK();
          *(int *)pQVar12 = *(int *)pQVar12 + -1;
          UNLOCK();
          if (*(int *)pQVar12 == 0) {
            pQVar12 = *(QArrayData **)(lVar4 + 0x18);
            goto LAB_00900fa5;
          }
        }
        piVar9 = *(int **)(lVar4 + 0x20);
        if (piVar9 != (int *)0x0) {
          LOCK();
          *piVar9 = *piVar9 + -1;
          UNLOCK();
          if ((*piVar9 == 0) && (*(void **)(lVar4 + 0x20) != (void *)0x0)) {
            operator_delete(*(void **)(lVar4 + 0x20));
          }
        }
        lVar5 = *(long *)(lVar4 + 8);
        if (lVar5 != 0) {
          pQVar12 = *(QArrayData **)(lVar5 + 0x18);
          if (*(int *)pQVar12 == 0) {
LAB_009024ea:
            QArrayData::deallocate(pQVar12,2,8);
          }
          else if (*(int *)pQVar12 != -1) {
            LOCK();
            *(int *)pQVar12 = *(int *)pQVar12 + -1;
            UNLOCK();
            if (*(int *)pQVar12 == 0) {
              pQVar12 = *(QArrayData **)(lVar5 + 0x18);
              goto LAB_009024ea;
            }
          }
          piVar9 = *(int **)(lVar5 + 0x20);
          if (piVar9 != (int *)0x0) {
            LOCK();
            *piVar9 = *piVar9 + -1;
            UNLOCK();
            if ((*piVar9 == 0) && (*(void **)(lVar5 + 0x20) != (void *)0x0)) {
              operator_delete(*(void **)(lVar5 + 0x20));
            }
          }
          lVar6 = *(long *)(lVar5 + 8);
          if (lVar6 != 0) {
            pQVar12 = *(QArrayData **)(lVar6 + 0x18);
            if (*(int *)pQVar12 == 0) {
LAB_00902594:
              QArrayData::deallocate(pQVar12,2,8);
            }
            else if (*(int *)pQVar12 != -1) {
              LOCK();
              *(int *)pQVar12 = *(int *)pQVar12 + -1;
              UNLOCK();
              if (*(int *)pQVar12 == 0) {
                pQVar12 = *(QArrayData **)(lVar6 + 0x18);
                goto LAB_00902594;
              }
            }
            piVar9 = *(int **)(lVar6 + 0x20);
            if (piVar9 != (int *)0x0) {
              LOCK();
              *piVar9 = *piVar9 + -1;
              UNLOCK();
              if ((*piVar9 == 0) && (*(void **)(lVar6 + 0x20) != (void *)0x0)) {
                operator_delete(*(void **)(lVar6 + 0x20));
              }
            }
            lVar7 = *(long *)(lVar6 + 8);
            if (lVar7 != 0) {
              pQVar12 = *(QArrayData **)(lVar7 + 0x18);
              if (*(int *)pQVar12 == 0) {
LAB_00902775:
                QArrayData::deallocate(pQVar12,2,8);
              }
              else if (*(int *)pQVar12 != -1) {
                LOCK();
                *(int *)pQVar12 = *(int *)pQVar12 + -1;
                UNLOCK();
                if (*(int *)pQVar12 == 0) {
                  pQVar12 = *(QArrayData **)(lVar7 + 0x18);
                  goto LAB_00902775;
                }
              }
              piVar9 = *(int **)(lVar7 + 0x20);
              if (piVar9 != (int *)0x0) {
                LOCK();
                *piVar9 = *piVar9 + -1;
                UNLOCK();
                if ((*piVar9 == 0) && (*(void **)(lVar7 + 0x20) != (void *)0x0)) {
                  operator_delete(*(void **)(lVar7 + 0x20));
                }
              }
              lVar8 = *(long *)(lVar7 + 8);
              if (lVar8 != 0) {
                pQVar12 = *(QArrayData **)(lVar8 + 0x18);
                if (*(int *)pQVar12 == 0) {
LAB_009027cd:
                  QArrayData::deallocate(pQVar12,2,8);
                }
                else if (*(int *)pQVar12 != -1) {
                  LOCK();
                  *(int *)pQVar12 = *(int *)pQVar12 + -1;
                  UNLOCK();
                  if (*(int *)pQVar12 == 0) {
                    pQVar12 = *(QArrayData **)(lVar8 + 0x18);
                    goto LAB_009027cd;
                  }
                }
                piVar9 = *(int **)(lVar8 + 0x20);
                if (piVar9 != (int *)0x0) {
                  LOCK();
                  *piVar9 = *piVar9 + -1;
                  UNLOCK();
                  if ((*piVar9 == 0) && (*(void **)(lVar8 + 0x20) != (void *)0x0)) {
                    operator_delete(*(void **)(lVar8 + 0x20));
                  }
                }
                if (*(long *)(lVar8 + 8) != 0) {
                  FUN_0064e5d8();
                }
                if (*(long *)(lVar8 + 0x10) != 0) {
                  FUN_0064e5d8();
                }
              }
              lVar7 = *(long *)(lVar7 + 0x10);
              if (lVar7 != 0) {
                pQVar12 = *(QArrayData **)(lVar7 + 0x18);
                if (*(int *)pQVar12 == 0) {
LAB_00902a18:
                  QArrayData::deallocate(pQVar12,2,8);
                }
                else if (*(int *)pQVar12 != -1) {
                  LOCK();
                  *(int *)pQVar12 = *(int *)pQVar12 + -1;
                  UNLOCK();
                  if (*(int *)pQVar12 == 0) {
                    pQVar12 = *(QArrayData **)(lVar7 + 0x18);
                    goto LAB_00902a18;
                  }
                }
                piVar9 = *(int **)(lVar7 + 0x20);
                if (piVar9 != (int *)0x0) {
                  LOCK();
                  *piVar9 = *piVar9 + -1;
                  UNLOCK();
                  if ((*piVar9 == 0) && (*(void **)(lVar7 + 0x20) != (void *)0x0)) {
                    operator_delete(*(void **)(lVar7 + 0x20));
                  }
                }
                if (*(long *)(lVar7 + 8) != 0) {
                  FUN_0064e5d8();
                }
                if (*(long *)(lVar7 + 0x10) != 0) {
                  FUN_0064e5d8();
                }
              }
            }
            lVar6 = *(long *)(lVar6 + 0x10);
            if (lVar6 != 0) {
              pQVar12 = *(QArrayData **)(lVar6 + 0x18);
              if (*(int *)pQVar12 == 0) {
LAB_0090275d:
                QArrayData::deallocate(pQVar12,2,8);
              }
              else if (*(int *)pQVar12 != -1) {
                LOCK();
                *(int *)pQVar12 = *(int *)pQVar12 + -1;
                UNLOCK();
                if (*(int *)pQVar12 == 0) {
                  pQVar12 = *(QArrayData **)(lVar6 + 0x18);
                  goto LAB_0090275d;
                }
              }
              piVar9 = *(int **)(lVar6 + 0x20);
              if (piVar9 != (int *)0x0) {
                LOCK();
                *piVar9 = *piVar9 + -1;
                UNLOCK();
                if ((*piVar9 == 0) && (*(void **)(lVar6 + 0x20) != (void *)0x0)) {
                  operator_delete(*(void **)(lVar6 + 0x20));
                }
              }
              lVar7 = *(long *)(lVar6 + 8);
              if (lVar7 != 0) {
                pQVar12 = *(QArrayData **)(lVar7 + 0x18);
                if (*(int *)pQVar12 == 0) {
LAB_00902a68:
                  QArrayData::deallocate(pQVar12,2,8);
                }
                else if (*(int *)pQVar12 != -1) {
                  LOCK();
                  *(int *)pQVar12 = *(int *)pQVar12 + -1;
                  UNLOCK();
                  if (*(int *)pQVar12 == 0) {
                    pQVar12 = *(QArrayData **)(lVar7 + 0x18);
                    goto LAB_00902a68;
                  }
                }
                piVar9 = *(int **)(lVar7 + 0x20);
                if (piVar9 != (int *)0x0) {
                  LOCK();
                  *piVar9 = *piVar9 + -1;
                  UNLOCK();
                  if ((*piVar9 == 0) && (*(void **)(lVar7 + 0x20) != (void *)0x0)) {
                    operator_delete(*(void **)(lVar7 + 0x20));
                  }
                }
                if (*(long *)(lVar7 + 8) != 0) {
                  FUN_0064e5d8();
                }
                if (*(long *)(lVar7 + 0x10) != 0) {
                  FUN_0064e5d8();
                }
              }
              lVar6 = *(long *)(lVar6 + 0x10);
              if (lVar6 != 0) {
                pQVar12 = *(QArrayData **)(lVar6 + 0x18);
                if (*(int *)pQVar12 == 0) {
LAB_00902a50:
                  QArrayData::deallocate(pQVar12,2,8);
                }
                else if (*(int *)pQVar12 != -1) {
                  LOCK();
                  *(int *)pQVar12 = *(int *)pQVar12 + -1;
                  UNLOCK();
                  if (*(int *)pQVar12 == 0) {
                    pQVar12 = *(QArrayData **)(lVar6 + 0x18);
                    goto LAB_00902a50;
                  }
                }
                piVar9 = *(int **)(lVar6 + 0x20);
                if (piVar9 != (int *)0x0) {
                  LOCK();
                  *piVar9 = *piVar9 + -1;
                  UNLOCK();
                  if ((*piVar9 == 0) && (*(void **)(lVar6 + 0x20) != (void *)0x0)) {
                    operator_delete(*(void **)(lVar6 + 0x20));
                  }
                }
                if (*(long *)(lVar6 + 8) != 0) {
                  FUN_0064e5d8();
                }
                if (*(long *)(lVar6 + 0x10) != 0) {
                  FUN_0064e5d8();
                }
              }
            }
          }
          lVar5 = *(long *)(lVar5 + 0x10);
          if (lVar5 != 0) {
            pQVar12 = *(QArrayData **)(lVar5 + 0x18);
            if (*(int *)pQVar12 == 0) {
LAB_009025ac:
              QArrayData::deallocate(pQVar12,2,8);
            }
            else if (*(int *)pQVar12 != -1) {
              LOCK();
              *(int *)pQVar12 = *(int *)pQVar12 + -1;
              UNLOCK();
              if (*(int *)pQVar12 == 0) {
                pQVar12 = *(QArrayData **)(lVar5 + 0x18);
                goto LAB_009025ac;
              }
            }
            piVar9 = *(int **)(lVar5 + 0x20);
            if (piVar9 != (int *)0x0) {
              LOCK();
              *piVar9 = *piVar9 + -1;
              UNLOCK();
              if ((*piVar9 == 0) && (*(void **)(lVar5 + 0x20) != (void *)0x0)) {
                operator_delete(*(void **)(lVar5 + 0x20));
              }
            }
            lVar6 = *(long *)(lVar5 + 8);
            if (lVar6 != 0) {
              pQVar12 = *(QArrayData **)(lVar6 + 0x18);
              if (*(int *)pQVar12 == 0) {
LAB_0090272d:
                QArrayData::deallocate(pQVar12,2,8);
              }
              else if (*(int *)pQVar12 != -1) {
                LOCK();
                *(int *)pQVar12 = *(int *)pQVar12 + -1;
                UNLOCK();
                if (*(int *)pQVar12 == 0) {
                  pQVar12 = *(QArrayData **)(lVar6 + 0x18);
                  goto LAB_0090272d;
                }
              }
              piVar9 = *(int **)(lVar6 + 0x20);
              if (piVar9 != (int *)0x0) {
                LOCK();
                *piVar9 = *piVar9 + -1;
                UNLOCK();
                if ((*piVar9 == 0) && (*(void **)(lVar6 + 0x20) != (void *)0x0)) {
                  operator_delete(*(void **)(lVar6 + 0x20));
                }
              }
              lVar7 = *(long *)(lVar6 + 8);
              if (lVar7 != 0) {
                pQVar12 = *(QArrayData **)(lVar7 + 0x18);
                if (*(int *)pQVar12 == 0) {
LAB_009027ad:
                  QArrayData::deallocate(pQVar12,2,8);
                }
                else if (*(int *)pQVar12 != -1) {
                  LOCK();
                  *(int *)pQVar12 = *(int *)pQVar12 + -1;
                  UNLOCK();
                  if (*(int *)pQVar12 == 0) {
                    pQVar12 = *(QArrayData **)(lVar7 + 0x18);
                    goto LAB_009027ad;
                  }
                }
                piVar9 = *(int **)(lVar7 + 0x20);
                if (piVar9 != (int *)0x0) {
                  LOCK();
                  *piVar9 = *piVar9 + -1;
                  UNLOCK();
                  if ((*piVar9 == 0) && (*(void **)(lVar7 + 0x20) != (void *)0x0)) {
                    operator_delete(*(void **)(lVar7 + 0x20));
                  }
                }
                if (*(long *)(lVar7 + 8) != 0) {
                  FUN_0064e5d8();
                }
                if (*(long *)(lVar7 + 0x10) != 0) {
                  FUN_0064e5d8();
                }
              }
              lVar6 = *(long *)(lVar6 + 0x10);
              if (lVar6 != 0) {
                pQVar12 = *(QArrayData **)(lVar6 + 0x18);
                if (*(int *)pQVar12 == 0) {
LAB_00902795:
                  QArrayData::deallocate(pQVar12,2,8);
                }
                else if (*(int *)pQVar12 != -1) {
                  LOCK();
                  *(int *)pQVar12 = *(int *)pQVar12 + -1;
                  UNLOCK();
                  if (*(int *)pQVar12 == 0) {
                    pQVar12 = *(QArrayData **)(lVar6 + 0x18);
                    goto LAB_00902795;
                  }
                }
                piVar9 = *(int **)(lVar6 + 0x20);
                if (piVar9 != (int *)0x0) {
                  LOCK();
                  *piVar9 = *piVar9 + -1;
                  UNLOCK();
                  if ((*piVar9 == 0) && (*(void **)(lVar6 + 0x20) != (void *)0x0)) {
                    operator_delete(*(void **)(lVar6 + 0x20));
                  }
                }
                if (*(long *)(lVar6 + 8) != 0) {
                  FUN_0064e5d8();
                }
                if (*(long *)(lVar6 + 0x10) != 0) {
                  FUN_0064e5d8();
                }
              }
            }
            lVar5 = *(long *)(lVar5 + 0x10);
            if (lVar5 != 0) {
              pQVar12 = *(QArrayData **)(lVar5 + 0x18);
              if (*(int *)pQVar12 == 0) {
LAB_00902745:
                QArrayData::deallocate(pQVar12,2,8);
              }
              else if (*(int *)pQVar12 != -1) {
                LOCK();
                *(int *)pQVar12 = *(int *)pQVar12 + -1;
                UNLOCK();
                if (*(int *)pQVar12 == 0) {
                  pQVar12 = *(QArrayData **)(lVar5 + 0x18);
                  goto LAB_00902745;
                }
              }
              piVar9 = *(int **)(lVar5 + 0x20);
              if (piVar9 != (int *)0x0) {
                LOCK();
                *piVar9 = *piVar9 + -1;
                UNLOCK();
                if ((*piVar9 == 0) && (*(void **)(lVar5 + 0x20) != (void *)0x0)) {
                  operator_delete(*(void **)(lVar5 + 0x20));
                }
              }
              lVar6 = *(long *)(lVar5 + 8);
              if (lVar6 != 0) {
                pQVar12 = *(QArrayData **)(lVar6 + 0x18);
                if (*(int *)pQVar12 == 0) {
LAB_009029d0:
                  QArrayData::deallocate(pQVar12,2,8);
                }
                else if (*(int *)pQVar12 != -1) {
                  LOCK();
                  *(int *)pQVar12 = *(int *)pQVar12 + -1;
                  UNLOCK();
                  if (*(int *)pQVar12 == 0) {
                    pQVar12 = *(QArrayData **)(lVar6 + 0x18);
                    goto LAB_009029d0;
                  }
                }
                piVar9 = *(int **)(lVar6 + 0x20);
                if (piVar9 != (int *)0x0) {
                  LOCK();
                  *piVar9 = *piVar9 + -1;
                  UNLOCK();
                  if ((*piVar9 == 0) && (*(void **)(lVar6 + 0x20) != (void *)0x0)) {
                    operator_delete(*(void **)(lVar6 + 0x20));
                  }
                }
                if (*(long *)(lVar6 + 8) != 0) {
                  FUN_0064e5d8();
                }
                if (*(long *)(lVar6 + 0x10) != 0) {
                  FUN_0064e5d8();
                }
              }
              lVar5 = *(long *)(lVar5 + 0x10);
              if (lVar5 != 0) {
                pQVar12 = *(QArrayData **)(lVar5 + 0x18);
                if (*(int *)pQVar12 == 0) {
LAB_00902877:
                  QArrayData::deallocate(pQVar12,2,8);
                }
                else if (*(int *)pQVar12 != -1) {
                  LOCK();
                  *(int *)pQVar12 = *(int *)pQVar12 + -1;
                  UNLOCK();
                  if (*(int *)pQVar12 == 0) {
                    pQVar12 = *(QArrayData **)(lVar5 + 0x18);
                    goto LAB_00902877;
                  }
                }
                piVar9 = *(int **)(lVar5 + 0x20);
                if (piVar9 != (int *)0x0) {
                  LOCK();
                  *piVar9 = *piVar9 + -1;
                  UNLOCK();
                  if ((*piVar9 == 0) && (*(void **)(lVar5 + 0x20) != (void *)0x0)) {
                    operator_delete(*(void **)(lVar5 + 0x20));
                  }
                }
                if (*(long *)(lVar5 + 8) != 0) {
                  FUN_0064e5d8();
                }
                if (*(long *)(lVar5 + 0x10) != 0) {
                  FUN_0064e5d8();
                }
              }
            }
          }
        }
        lVar4 = *(long *)(lVar4 + 0x10);
        if (lVar4 != 0) {
          pQVar12 = *(QArrayData **)(lVar4 + 0x18);
          if (*(int *)pQVar12 == 0) {
LAB_00902533:
            QArrayData::deallocate(pQVar12,2,8);
          }
          else if (*(int *)pQVar12 != -1) {
            LOCK();
            *(int *)pQVar12 = *(int *)pQVar12 + -1;
            UNLOCK();
            if (*(int *)pQVar12 == 0) {
              pQVar12 = *(QArrayData **)(lVar4 + 0x18);
              goto LAB_00902533;
            }
          }
          piVar9 = *(int **)(lVar4 + 0x20);
          if (piVar9 != (int *)0x0) {
            LOCK();
            *piVar9 = *piVar9 + -1;
            UNLOCK();
            if ((*piVar9 == 0) && (*(void **)(lVar4 + 0x20) != (void *)0x0)) {
              operator_delete(*(void **)(lVar4 + 0x20));
            }
          }
          lVar5 = *(long *)(lVar4 + 8);
          if (lVar5 != 0) {
            pQVar12 = *(QArrayData **)(lVar5 + 0x18);
            if (*(int *)pQVar12 == 0) {
LAB_009025f4:
              QArrayData::deallocate(pQVar12,2,8);
            }
            else if (*(int *)pQVar12 != -1) {
              LOCK();
              *(int *)pQVar12 = *(int *)pQVar12 + -1;
              UNLOCK();
              if (*(int *)pQVar12 == 0) {
                pQVar12 = *(QArrayData **)(lVar5 + 0x18);
                goto LAB_009025f4;
              }
            }
            piVar9 = *(int **)(lVar5 + 0x20);
            if (piVar9 != (int *)0x0) {
              LOCK();
              *piVar9 = *piVar9 + -1;
              UNLOCK();
              if ((*piVar9 == 0) && (*(void **)(lVar5 + 0x20) != (void *)0x0)) {
                operator_delete(*(void **)(lVar5 + 0x20));
              }
            }
            lVar6 = *(long *)(lVar5 + 8);
            if (lVar6 != 0) {
              pQVar12 = *(QArrayData **)(lVar6 + 0x18);
              if (*(int *)pQVar12 == 0) {
LAB_0090269d:
                QArrayData::deallocate(pQVar12,2,8);
              }
              else if (*(int *)pQVar12 != -1) {
                LOCK();
                *(int *)pQVar12 = *(int *)pQVar12 + -1;
                UNLOCK();
                if (*(int *)pQVar12 == 0) {
                  pQVar12 = *(QArrayData **)(lVar6 + 0x18);
                  goto LAB_0090269d;
                }
              }
              piVar9 = *(int **)(lVar6 + 0x20);
              if (piVar9 != (int *)0x0) {
                LOCK();
                *piVar9 = *piVar9 + -1;
                UNLOCK();
                if ((*piVar9 == 0) && (*(void **)(lVar6 + 0x20) != (void *)0x0)) {
                  operator_delete(*(void **)(lVar6 + 0x20));
                }
              }
              lVar7 = *(long *)(lVar6 + 8);
              if (lVar7 != 0) {
                pQVar12 = *(QArrayData **)(lVar7 + 0x18);
                if (*(int *)pQVar12 == 0) {
LAB_00902827:
                  QArrayData::deallocate(pQVar12,2,8);
                }
                else if (*(int *)pQVar12 != -1) {
                  LOCK();
                  *(int *)pQVar12 = *(int *)pQVar12 + -1;
                  UNLOCK();
                  if (*(int *)pQVar12 == 0) {
                    pQVar12 = *(QArrayData **)(lVar7 + 0x18);
                    goto LAB_00902827;
                  }
                }
                piVar9 = *(int **)(lVar7 + 0x20);
                if (piVar9 != (int *)0x0) {
                  LOCK();
                  *piVar9 = *piVar9 + -1;
                  UNLOCK();
                  if ((*piVar9 == 0) && (*(void **)(lVar7 + 0x20) != (void *)0x0)) {
                    operator_delete(*(void **)(lVar7 + 0x20));
                  }
                }
                if (*(long *)(lVar7 + 8) != 0) {
                  FUN_0064e5d8();
                }
                if (*(long *)(lVar7 + 0x10) != 0) {
                  FUN_0064e5d8();
                }
              }
              lVar6 = *(long *)(lVar6 + 0x10);
              if (lVar6 != 0) {
                pQVar12 = *(QArrayData **)(lVar6 + 0x18);
                if (*(int *)pQVar12 == 0) {
LAB_0090280f:
                  QArrayData::deallocate(pQVar12,2,8);
                }
                else if (*(int *)pQVar12 != -1) {
                  LOCK();
                  *(int *)pQVar12 = *(int *)pQVar12 + -1;
                  UNLOCK();
                  if (*(int *)pQVar12 == 0) {
                    pQVar12 = *(QArrayData **)(lVar6 + 0x18);
                    goto LAB_0090280f;
                  }
                }
                piVar9 = *(int **)(lVar6 + 0x20);
                if (piVar9 != (int *)0x0) {
                  LOCK();
                  *piVar9 = *piVar9 + -1;
                  UNLOCK();
                  if ((*piVar9 == 0) && (*(void **)(lVar6 + 0x20) != (void *)0x0)) {
                    operator_delete(*(void **)(lVar6 + 0x20));
                  }
                }
                if (*(long *)(lVar6 + 8) != 0) {
                  FUN_0064e5d8();
                }
                if (*(long *)(lVar6 + 0x10) != 0) {
                  FUN_0064e5d8();
                }
              }
            }
            lVar5 = *(long *)(lVar5 + 0x10);
            if (lVar5 != 0) {
              pQVar12 = *(QArrayData **)(lVar5 + 0x18);
              if (*(int *)pQVar12 == 0) {
LAB_009026cd:
                QArrayData::deallocate(pQVar12,2,8);
              }
              else if (*(int *)pQVar12 != -1) {
                LOCK();
                *(int *)pQVar12 = *(int *)pQVar12 + -1;
                UNLOCK();
                if (*(int *)pQVar12 == 0) {
                  pQVar12 = *(QArrayData **)(lVar5 + 0x18);
                  goto LAB_009026cd;
                }
              }
              piVar9 = *(int **)(lVar5 + 0x20);
              if (piVar9 != (int *)0x0) {
                LOCK();
                *piVar9 = *piVar9 + -1;
                UNLOCK();
                if ((*piVar9 == 0) && (*(void **)(lVar5 + 0x20) != (void *)0x0)) {
                  operator_delete(*(void **)(lVar5 + 0x20));
                }
              }
              if (*(long *)(lVar5 + 8) != 0) {
                FUN_0064e5d8();
              }
              lVar5 = *(long *)(lVar5 + 0x10);
              if (lVar5 != 0) {
                pQVar12 = *(QArrayData **)(lVar5 + 0x18);
                if (*(int *)pQVar12 == 0) {
LAB_00902847:
                  QArrayData::deallocate(pQVar12,2,8);
                }
                else if (*(int *)pQVar12 != -1) {
                  LOCK();
                  *(int *)pQVar12 = *(int *)pQVar12 + -1;
                  UNLOCK();
                  if (*(int *)pQVar12 == 0) {
                    pQVar12 = *(QArrayData **)(lVar5 + 0x18);
                    goto LAB_00902847;
                  }
                }
                piVar9 = *(int **)(lVar5 + 0x20);
                if (piVar9 != (int *)0x0) {
                  LOCK();
                  *piVar9 = *piVar9 + -1;
                  UNLOCK();
                  if ((*piVar9 == 0) && (*(void **)(lVar5 + 0x20) != (void *)0x0)) {
                    operator_delete(*(void **)(lVar5 + 0x20));
                  }
                }
                if (*(long *)(lVar5 + 8) != 0) {
                  FUN_0064e5d8();
                }
                if (*(long *)(lVar5 + 0x10) != 0) {
                  FUN_0064e5d8();
                }
              }
            }
          }
          lVar4 = *(long *)(lVar4 + 0x10);
          if (lVar4 != 0) {
            pQVar12 = *(QArrayData **)(lVar4 + 0x18);
            if (*(int *)pQVar12 == 0) {
LAB_009025dc:
              QArrayData::deallocate(pQVar12,2,8);
            }
            else if (*(int *)pQVar12 != -1) {
              LOCK();
              *(int *)pQVar12 = *(int *)pQVar12 + -1;
              UNLOCK();
              if (*(int *)pQVar12 == 0) {
                pQVar12 = *(QArrayData **)(lVar4 + 0x18);
                goto LAB_009025dc;
              }
            }
            piVar9 = *(int **)(lVar4 + 0x20);
            if (piVar9 != (int *)0x0) {
              LOCK();
              *piVar9 = *piVar9 + -1;
              UNLOCK();
              if ((*piVar9 == 0) && (*(void **)(lVar4 + 0x20) != (void *)0x0)) {
                operator_delete(*(void **)(lVar4 + 0x20));
              }
            }
            lVar5 = *(long *)(lVar4 + 8);
            if (lVar5 != 0) {
              pQVar12 = *(QArrayData **)(lVar5 + 0x18);
              if (*(int *)pQVar12 == 0) {
LAB_00902715:
                QArrayData::deallocate(pQVar12,2,8);
              }
              else if (*(int *)pQVar12 != -1) {
                LOCK();
                *(int *)pQVar12 = *(int *)pQVar12 + -1;
                UNLOCK();
                if (*(int *)pQVar12 == 0) {
                  pQVar12 = *(QArrayData **)(lVar5 + 0x18);
                  goto LAB_00902715;
                }
              }
              piVar9 = *(int **)(lVar5 + 0x20);
              if (piVar9 != (int *)0x0) {
                LOCK();
                *piVar9 = *piVar9 + -1;
                UNLOCK();
                if ((*piVar9 == 0) && (*(void **)(lVar5 + 0x20) != (void *)0x0)) {
                  operator_delete(*(void **)(lVar5 + 0x20));
                }
              }
              lVar6 = *(long *)(lVar5 + 8);
              if (lVar6 != 0) {
                pQVar12 = *(QArrayData **)(lVar6 + 0x18);
                if (*(int *)pQVar12 == 0) {
LAB_00902a38:
                  QArrayData::deallocate(pQVar12,2,8);
                }
                else if (*(int *)pQVar12 != -1) {
                  LOCK();
                  *(int *)pQVar12 = *(int *)pQVar12 + -1;
                  UNLOCK();
                  if (*(int *)pQVar12 == 0) {
                    pQVar12 = *(QArrayData **)(lVar6 + 0x18);
                    goto LAB_00902a38;
                  }
                }
                piVar9 = *(int **)(lVar6 + 0x20);
                if (piVar9 != (int *)0x0) {
                  LOCK();
                  *piVar9 = *piVar9 + -1;
                  UNLOCK();
                  if ((*piVar9 == 0) && (*(void **)(lVar6 + 0x20) != (void *)0x0)) {
                    operator_delete(*(void **)(lVar6 + 0x20));
                  }
                }
                if (*(long *)(lVar6 + 8) != 0) {
                  FUN_0064e5d8();
                }
                if (*(long *)(lVar6 + 0x10) != 0) {
                  FUN_0064e5d8();
                }
              }
              lVar5 = *(long *)(lVar5 + 0x10);
              if (lVar5 != 0) {
                pQVar12 = *(QArrayData **)(lVar5 + 0x18);
                if (*(int *)pQVar12 == 0) {
LAB_00902968:
                  QArrayData::deallocate(pQVar12,2,8);
                }
                else if (*(int *)pQVar12 != -1) {
                  LOCK();
                  *(int *)pQVar12 = *(int *)pQVar12 + -1;
                  UNLOCK();
                  if (*(int *)pQVar12 == 0) {
                    pQVar12 = *(QArrayData **)(lVar5 + 0x18);
                    goto LAB_00902968;
                  }
                }
                piVar9 = *(int **)(lVar5 + 0x20);
                if (piVar9 != (int *)0x0) {
                  LOCK();
                  *piVar9 = *piVar9 + -1;
                  UNLOCK();
                  if ((*piVar9 == 0) && (*(void **)(lVar5 + 0x20) != (void *)0x0)) {
                    operator_delete(*(void **)(lVar5 + 0x20));
                  }
                }
                if (*(long *)(lVar5 + 8) != 0) {
                  FUN_0064e5d8();
                }
                if (*(long *)(lVar5 + 0x10) != 0) {
                  FUN_0064e5d8();
                }
              }
            }
            lVar4 = *(long *)(lVar4 + 0x10);
            if (lVar4 != 0) {
              pQVar12 = *(QArrayData **)(lVar4 + 0x18);
              if (*(int *)pQVar12 == 0) {
LAB_009026fd:
                QArrayData::deallocate(pQVar12,2,8);
              }
              else if (*(int *)pQVar12 != -1) {
                LOCK();
                *(int *)pQVar12 = *(int *)pQVar12 + -1;
                UNLOCK();
                if (*(int *)pQVar12 == 0) {
                  pQVar12 = *(QArrayData **)(lVar4 + 0x18);
                  goto LAB_009026fd;
                }
              }
              piVar9 = *(int **)(lVar4 + 0x20);
              if (piVar9 != (int *)0x0) {
                LOCK();
                *piVar9 = *piVar9 + -1;
                UNLOCK();
                if ((*piVar9 == 0) && (*(void **)(lVar4 + 0x20) != (void *)0x0)) {
                  operator_delete(*(void **)(lVar4 + 0x20));
                }
              }
              lVar5 = *(long *)(lVar4 + 8);
              if (lVar5 != 0) {
                pQVar12 = *(QArrayData **)(lVar5 + 0x18);
                if (*(int *)pQVar12 == 0) {
LAB_009029e8:
                  QArrayData::deallocate(pQVar12,2,8);
                }
                else if (*(int *)pQVar12 != -1) {
                  LOCK();
                  *(int *)pQVar12 = *(int *)pQVar12 + -1;
                  UNLOCK();
                  if (*(int *)pQVar12 == 0) {
                    pQVar12 = *(QArrayData **)(lVar5 + 0x18);
                    goto LAB_009029e8;
                  }
                }
                piVar9 = *(int **)(lVar5 + 0x20);
                if (piVar9 != (int *)0x0) {
                  LOCK();
                  *piVar9 = *piVar9 + -1;
                  UNLOCK();
                  if ((*piVar9 == 0) && (*(void **)(lVar5 + 0x20) != (void *)0x0)) {
                    operator_delete(*(void **)(lVar5 + 0x20));
                  }
                }
                if (*(long *)(lVar5 + 8) != 0) {
                  FUN_0064e5d8();
                }
                if (*(long *)(lVar5 + 0x10) != 0) {
                  FUN_0064e5d8();
                }
              }
              lVar4 = *(long *)(lVar4 + 0x10);
              if (lVar4 != 0) {
                pQVar12 = *(QArrayData **)(lVar4 + 0x18);
                if (*(int *)pQVar12 == 0) {
LAB_0090291f:
                  QArrayData::deallocate(pQVar12,2,8);
                }
                else if (*(int *)pQVar12 != -1) {
                  LOCK();
                  *(int *)pQVar12 = *(int *)pQVar12 + -1;
                  UNLOCK();
                  if (*(int *)pQVar12 == 0) {
                    pQVar12 = *(QArrayData **)(lVar4 + 0x18);
                    goto LAB_0090291f;
                  }
                }
                piVar9 = *(int **)(lVar4 + 0x20);
                if (piVar9 != (int *)0x0) {
                  LOCK();
                  *piVar9 = *piVar9 + -1;
                  UNLOCK();
                  if ((*piVar9 == 0) && (*(void **)(lVar4 + 0x20) != (void *)0x0)) {
                    operator_delete(*(void **)(lVar4 + 0x20));
                  }
                }
                if (*(long *)(lVar4 + 8) != 0) {
                  FUN_0064e5d8();
                }
                if (*(long *)(lVar4 + 0x10) != 0) {
                  FUN_0064e5d8();
                }
              }
            }
          }
        }
      }
      lVar3 = *(long *)(lVar3 + 0x10);
      if (lVar3 != 0) {
        pQVar12 = *(QArrayData **)(lVar3 + 0x18);
        if (*(int *)pQVar12 == 0) {
LAB_009019f3:
          QArrayData::deallocate(pQVar12,2,8);
        }
        else if (*(int *)pQVar12 != -1) {
          LOCK();
          *(int *)pQVar12 = *(int *)pQVar12 + -1;
          UNLOCK();
          if (*(int *)pQVar12 == 0) {
            pQVar12 = *(QArrayData **)(lVar3 + 0x18);
            goto LAB_009019f3;
          }
        }
        piVar9 = *(int **)(lVar3 + 0x20);
        if (piVar9 != (int *)0x0) {
          LOCK();
          *piVar9 = *piVar9 + -1;
          UNLOCK();
          if ((*piVar9 == 0) && (*(void **)(lVar3 + 0x20) != (void *)0x0)) {
            operator_delete(*(void **)(lVar3 + 0x20));
          }
        }
        lVar4 = *(long *)(lVar3 + 8);
        if (lVar4 != 0) {
          pQVar12 = *(QArrayData **)(lVar4 + 0x18);
          if (*(int *)pQVar12 == 0) {
LAB_0090251b:
            QArrayData::deallocate(pQVar12,2,8);
          }
          else if (*(int *)pQVar12 != -1) {
            LOCK();
            *(int *)pQVar12 = *(int *)pQVar12 + -1;
            UNLOCK();
            if (*(int *)pQVar12 == 0) {
              pQVar12 = *(QArrayData **)(lVar4 + 0x18);
              goto LAB_0090251b;
            }
          }
          piVar9 = *(int **)(lVar4 + 0x20);
          if (piVar9 != (int *)0x0) {
            LOCK();
            *piVar9 = *piVar9 + -1;
            UNLOCK();
            if ((*piVar9 == 0) && (*(void **)(lVar4 + 0x20) != (void *)0x0)) {
              operator_delete(*(void **)(lVar4 + 0x20));
            }
          }
          lVar5 = *(long *)(lVar4 + 8);
          if (lVar5 != 0) {
            pQVar12 = *(QArrayData **)(lVar5 + 0x18);
            if (*(int *)pQVar12 == 0) {
LAB_009025c4:
              QArrayData::deallocate(pQVar12,2,8);
            }
            else if (*(int *)pQVar12 != -1) {
              LOCK();
              *(int *)pQVar12 = *(int *)pQVar12 + -1;
              UNLOCK();
              if (*(int *)pQVar12 == 0) {
                pQVar12 = *(QArrayData **)(lVar5 + 0x18);
                goto LAB_009025c4;
              }
            }
            piVar9 = *(int **)(lVar5 + 0x20);
            if (piVar9 != (int *)0x0) {
              LOCK();
              *piVar9 = *piVar9 + -1;
              UNLOCK();
              if ((*piVar9 == 0) && (*(void **)(lVar5 + 0x20) != (void *)0x0)) {
                operator_delete(*(void **)(lVar5 + 0x20));
              }
            }
            lVar6 = *(long *)(lVar5 + 8);
            if (lVar6 != 0) {
              pQVar12 = *(QArrayData **)(lVar6 + 0x18);
              if (*(int *)pQVar12 == 0) {
LAB_009026e5:
                QArrayData::deallocate(pQVar12,2,8);
              }
              else if (*(int *)pQVar12 != -1) {
                LOCK();
                *(int *)pQVar12 = *(int *)pQVar12 + -1;
                UNLOCK();
                if (*(int *)pQVar12 == 0) {
                  pQVar12 = *(QArrayData **)(lVar6 + 0x18);
                  goto LAB_009026e5;
                }
              }
              piVar9 = *(int **)(lVar6 + 0x20);
              if (piVar9 != (int *)0x0) {
                LOCK();
                *piVar9 = *piVar9 + -1;
                UNLOCK();
                if ((*piVar9 == 0) && (*(void **)(lVar6 + 0x20) != (void *)0x0)) {
                  operator_delete(*(void **)(lVar6 + 0x20));
                }
              }
              lVar7 = *(long *)(lVar6 + 8);
              if (lVar7 != 0) {
                pQVar12 = *(QArrayData **)(lVar7 + 0x18);
                if (*(int *)pQVar12 == 0) {
LAB_009029b0:
                  QArrayData::deallocate(pQVar12,2,8);
                }
                else if (*(int *)pQVar12 != -1) {
                  LOCK();
                  *(int *)pQVar12 = *(int *)pQVar12 + -1;
                  UNLOCK();
                  if (*(int *)pQVar12 == 0) {
                    pQVar12 = *(QArrayData **)(lVar7 + 0x18);
                    goto LAB_009029b0;
                  }
                }
                piVar9 = *(int **)(lVar7 + 0x20);
                if (piVar9 != (int *)0x0) {
                  LOCK();
                  *piVar9 = *piVar9 + -1;
                  UNLOCK();
                  if ((*piVar9 == 0) && (*(void **)(lVar7 + 0x20) != (void *)0x0)) {
                    operator_delete(*(void **)(lVar7 + 0x20));
                  }
                }
                if (*(long *)(lVar7 + 8) != 0) {
                  FUN_0064e5d8();
                }
                if (*(long *)(lVar7 + 0x10) != 0) {
                  FUN_0064e5d8();
                }
              }
              lVar6 = *(long *)(lVar6 + 0x10);
              if (lVar6 != 0) {
                pQVar12 = *(QArrayData **)(lVar6 + 0x18);
                if (*(int *)pQVar12 == 0) {
LAB_00902998:
                  QArrayData::deallocate(pQVar12,2,8);
                }
                else if (*(int *)pQVar12 != -1) {
                  LOCK();
                  *(int *)pQVar12 = *(int *)pQVar12 + -1;
                  UNLOCK();
                  if (*(int *)pQVar12 == 0) {
                    pQVar12 = *(QArrayData **)(lVar6 + 0x18);
                    goto LAB_00902998;
                  }
                }
                piVar9 = *(int **)(lVar6 + 0x20);
                if (piVar9 != (int *)0x0) {
                  LOCK();
                  *piVar9 = *piVar9 + -1;
                  UNLOCK();
                  if ((*piVar9 == 0) && (*(void **)(lVar6 + 0x20) != (void *)0x0)) {
                    operator_delete(*(void **)(lVar6 + 0x20));
                  }
                }
                if (*(long *)(lVar6 + 8) != 0) {
                  FUN_0064e5d8();
                }
                if (*(long *)(lVar6 + 0x10) != 0) {
                  FUN_0064e5d8();
                }
              }
            }
            lVar5 = *(long *)(lVar5 + 0x10);
            if (lVar5 != 0) {
              pQVar12 = *(QArrayData **)(lVar5 + 0x18);
              if (*(int *)pQVar12 == 0) {
LAB_009026b5:
                QArrayData::deallocate(pQVar12,2,8);
              }
              else if (*(int *)pQVar12 != -1) {
                LOCK();
                *(int *)pQVar12 = *(int *)pQVar12 + -1;
                UNLOCK();
                if (*(int *)pQVar12 == 0) {
                  pQVar12 = *(QArrayData **)(lVar5 + 0x18);
                  goto LAB_009026b5;
                }
              }
              piVar9 = *(int **)(lVar5 + 0x20);
              if (piVar9 != (int *)0x0) {
                LOCK();
                *piVar9 = *piVar9 + -1;
                UNLOCK();
                if ((*piVar9 == 0) && (*(void **)(lVar5 + 0x20) != (void *)0x0)) {
                  operator_delete(*(void **)(lVar5 + 0x20));
                }
              }
              lVar6 = *(long *)(lVar5 + 8);
              if (lVar6 != 0) {
                pQVar12 = *(QArrayData **)(lVar6 + 0x18);
                if (*(int *)pQVar12 == 0) {
LAB_0090285f:
                  QArrayData::deallocate(pQVar12,2,8);
                }
                else if (*(int *)pQVar12 != -1) {
                  LOCK();
                  *(int *)pQVar12 = *(int *)pQVar12 + -1;
                  UNLOCK();
                  if (*(int *)pQVar12 == 0) {
                    pQVar12 = *(QArrayData **)(lVar6 + 0x18);
                    goto LAB_0090285f;
                  }
                }
                piVar9 = *(int **)(lVar6 + 0x20);
                if (piVar9 != (int *)0x0) {
                  LOCK();
                  *piVar9 = *piVar9 + -1;
                  UNLOCK();
                  if ((*piVar9 == 0) && (*(void **)(lVar6 + 0x20) != (void *)0x0)) {
                    operator_delete(*(void **)(lVar6 + 0x20));
                  }
                }
                if (*(long *)(lVar6 + 8) != 0) {
                  FUN_0064e5d8();
                }
                if (*(long *)(lVar6 + 0x10) != 0) {
                  FUN_0064e5d8();
                }
              }
              lVar5 = *(long *)(lVar5 + 0x10);
              if (lVar5 != 0) {
                pQVar12 = *(QArrayData **)(lVar5 + 0x18);
                if (*(int *)pQVar12 == 0) {
LAB_00902a00:
                  QArrayData::deallocate(pQVar12,2,8);
                }
                else if (*(int *)pQVar12 != -1) {
                  LOCK();
                  *(int *)pQVar12 = *(int *)pQVar12 + -1;
                  UNLOCK();
                  if (*(int *)pQVar12 == 0) {
                    pQVar12 = *(QArrayData **)(lVar5 + 0x18);
                    goto LAB_00902a00;
                  }
                }
                piVar9 = *(int **)(lVar5 + 0x20);
                if (piVar9 != (int *)0x0) {
                  LOCK();
                  *piVar9 = *piVar9 + -1;
                  UNLOCK();
                  if ((*piVar9 == 0) && (*(void **)(lVar5 + 0x20) != (void *)0x0)) {
                    operator_delete(*(void **)(lVar5 + 0x20));
                  }
                }
                if (*(long *)(lVar5 + 8) != 0) {
                  FUN_0064e5d8();
                }
                if (*(long *)(lVar5 + 0x10) != 0) {
                  FUN_0064e5d8();
                }
              }
            }
          }
          lVar4 = *(long *)(lVar4 + 0x10);
          if (lVar4 != 0) {
            pQVar12 = *(QArrayData **)(lVar4 + 0x18);
            if (*(int *)pQVar12 == 0) {
LAB_0090257c:
              QArrayData::deallocate(pQVar12,2,8);
            }
            else if (*(int *)pQVar12 != -1) {
              LOCK();
              *(int *)pQVar12 = *(int *)pQVar12 + -1;
              UNLOCK();
              if (*(int *)pQVar12 == 0) {
                pQVar12 = *(QArrayData **)(lVar4 + 0x18);
                goto LAB_0090257c;
              }
            }
            piVar9 = *(int **)(lVar4 + 0x20);
            if (piVar9 != (int *)0x0) {
              LOCK();
              *piVar9 = *piVar9 + -1;
              UNLOCK();
              if ((*piVar9 == 0) && (*(void **)(lVar4 + 0x20) != (void *)0x0)) {
                operator_delete(*(void **)(lVar4 + 0x20));
              }
            }
            lVar5 = *(long *)(lVar4 + 8);
            if (lVar5 != 0) {
              pQVar12 = *(QArrayData **)(lVar5 + 0x18);
              if (*(int *)pQVar12 == 0) {
LAB_00902624:
                QArrayData::deallocate(pQVar12,2,8);
              }
              else if (*(int *)pQVar12 != -1) {
                LOCK();
                *(int *)pQVar12 = *(int *)pQVar12 + -1;
                UNLOCK();
                if (*(int *)pQVar12 == 0) {
                  pQVar12 = *(QArrayData **)(lVar5 + 0x18);
                  goto LAB_00902624;
                }
              }
              piVar9 = *(int **)(lVar5 + 0x20);
              if (piVar9 != (int *)0x0) {
                LOCK();
                *piVar9 = *piVar9 + -1;
                UNLOCK();
                if ((*piVar9 == 0) && (*(void **)(lVar5 + 0x20) != (void *)0x0)) {
                  operator_delete(*(void **)(lVar5 + 0x20));
                }
              }
              lVar6 = *(long *)(lVar5 + 8);
              if (lVar6 != 0) {
                pQVar12 = *(QArrayData **)(lVar6 + 0x18);
                if (*(int *)pQVar12 == 0) {
LAB_00902980:
                  QArrayData::deallocate(pQVar12,2,8);
                }
                else if (*(int *)pQVar12 != -1) {
                  LOCK();
                  *(int *)pQVar12 = *(int *)pQVar12 + -1;
                  UNLOCK();
                  if (*(int *)pQVar12 == 0) {
                    pQVar12 = *(QArrayData **)(lVar6 + 0x18);
                    goto LAB_00902980;
                  }
                }
                piVar9 = *(int **)(lVar6 + 0x20);
                if (piVar9 != (int *)0x0) {
                  LOCK();
                  *piVar9 = *piVar9 + -1;
                  UNLOCK();
                  if ((*piVar9 == 0) && (*(void **)(lVar6 + 0x20) != (void *)0x0)) {
                    operator_delete(*(void **)(lVar6 + 0x20));
                  }
                }
                if (*(long *)(lVar6 + 8) != 0) {
                  FUN_0064e5d8();
                }
                if (*(long *)(lVar6 + 0x10) != 0) {
                  FUN_0064e5d8();
                }
              }
              lVar5 = *(long *)(lVar5 + 0x10);
              if (lVar5 != 0) {
                pQVar12 = *(QArrayData **)(lVar5 + 0x18);
                if (*(int *)pQVar12 == 0) {
LAB_00902950:
                  QArrayData::deallocate(pQVar12,2,8);
                }
                else if (*(int *)pQVar12 != -1) {
                  LOCK();
                  *(int *)pQVar12 = *(int *)pQVar12 + -1;
                  UNLOCK();
                  if (*(int *)pQVar12 == 0) {
                    pQVar12 = *(QArrayData **)(lVar5 + 0x18);
                    goto LAB_00902950;
                  }
                }
                piVar9 = *(int **)(lVar5 + 0x20);
                if (piVar9 != (int *)0x0) {
                  LOCK();
                  *piVar9 = *piVar9 + -1;
                  UNLOCK();
                  if ((*piVar9 == 0) && (*(void **)(lVar5 + 0x20) != (void *)0x0)) {
                    operator_delete(*(void **)(lVar5 + 0x20));
                  }
                }
                if (*(long *)(lVar5 + 8) != 0) {
                  FUN_0064e5d8();
                }
                if (*(long *)(lVar5 + 0x10) != 0) {
                  FUN_0064e5d8();
                }
              }
            }
            lVar4 = *(long *)(lVar4 + 0x10);
            if (lVar4 != 0) {
              pQVar12 = *(QArrayData **)(lVar4 + 0x18);
              if (*(int *)pQVar12 == 0) {
LAB_0090260c:
                QArrayData::deallocate(pQVar12,2,8);
              }
              else if (*(int *)pQVar12 != -1) {
                LOCK();
                *(int *)pQVar12 = *(int *)pQVar12 + -1;
                UNLOCK();
                if (*(int *)pQVar12 == 0) {
                  pQVar12 = *(QArrayData **)(lVar4 + 0x18);
                  goto LAB_0090260c;
                }
              }
              piVar9 = *(int **)(lVar4 + 0x20);
              if (piVar9 != (int *)0x0) {
                LOCK();
                *piVar9 = *piVar9 + -1;
                UNLOCK();
                if ((*piVar9 == 0) && (*(void **)(lVar4 + 0x20) != (void *)0x0)) {
                  operator_delete(*(void **)(lVar4 + 0x20));
                }
              }
              lVar5 = *(long *)(lVar4 + 8);
              if (lVar5 != 0) {
                pQVar12 = *(QArrayData **)(lVar5 + 0x18);
                if (*(int *)pQVar12 == 0) {
LAB_00902aa0:
                  QArrayData::deallocate(pQVar12,2,8);
                }
                else if (*(int *)pQVar12 != -1) {
                  LOCK();
                  *(int *)pQVar12 = *(int *)pQVar12 + -1;
                  UNLOCK();
                  if (*(int *)pQVar12 == 0) {
                    pQVar12 = *(QArrayData **)(lVar5 + 0x18);
                    goto LAB_00902aa0;
                  }
                }
                piVar9 = *(int **)(lVar5 + 0x20);
                if (piVar9 != (int *)0x0) {
                  LOCK();
                  *piVar9 = *piVar9 + -1;
                  UNLOCK();
                  if ((*piVar9 == 0) && (*(void **)(lVar5 + 0x20) != (void *)0x0)) {
                    operator_delete(*(void **)(lVar5 + 0x20));
                  }
                }
                if (*(long *)(lVar5 + 8) != 0) {
                  FUN_0064e5d8();
                }
                if (*(long *)(lVar5 + 0x10) != 0) {
                  FUN_0064e5d8();
                }
              }
              lVar4 = *(long *)(lVar4 + 0x10);
              if (lVar4 != 0) {
                pQVar12 = *(QArrayData **)(lVar4 + 0x18);
                if (*(int *)pQVar12 == 0) {
LAB_00902a88:
                  QArrayData::deallocate(pQVar12,2,8);
                }
                else if (*(int *)pQVar12 != -1) {
                  LOCK();
                  *(int *)pQVar12 = *(int *)pQVar12 + -1;
                  UNLOCK();
                  if (*(int *)pQVar12 == 0) {
                    pQVar12 = *(QArrayData **)(lVar4 + 0x18);
                    goto LAB_00902a88;
                  }
                }
                piVar9 = *(int **)(lVar4 + 0x20);
                if (piVar9 != (int *)0x0) {
                  LOCK();
                  *piVar9 = *piVar9 + -1;
                  UNLOCK();
                  if ((*piVar9 == 0) && (*(void **)(lVar4 + 0x20) != (void *)0x0)) {
                    operator_delete(*(void **)(lVar4 + 0x20));
                  }
                }
                if (*(long *)(lVar4 + 8) != 0) {
                  FUN_0064e5d8();
                }
                if (*(long *)(lVar4 + 0x10) != 0) {
                  FUN_0064e5d8();
                }
              }
            }
          }
        }
        lVar3 = *(long *)(lVar3 + 0x10);
        if (lVar3 != 0) {
          pQVar12 = *(QArrayData **)(lVar3 + 0x18);
          if (*(int *)pQVar12 == 0) {
LAB_00902503:
            QArrayData::deallocate(pQVar12,2,8);
          }
          else if (*(int *)pQVar12 != -1) {
            LOCK();
            *(int *)pQVar12 = *(int *)pQVar12 + -1;
            UNLOCK();
            if (*(int *)pQVar12 == 0) {
              pQVar12 = *(QArrayData **)(lVar3 + 0x18);
              goto LAB_00902503;
            }
          }
          piVar9 = *(int **)(lVar3 + 0x20);
          if (piVar9 != (int *)0x0) {
            LOCK();
            *piVar9 = *piVar9 + -1;
            UNLOCK();
            if ((*piVar9 == 0) && (*(void **)(lVar3 + 0x20) != (void *)0x0)) {
              operator_delete(*(void **)(lVar3 + 0x20));
            }
          }
          lVar4 = *(long *)(lVar3 + 8);
          if (lVar4 != 0) {
            pQVar12 = *(QArrayData **)(lVar4 + 0x18);
            if (*(int *)pQVar12 == 0) {
LAB_00902564:
              QArrayData::deallocate(pQVar12,2,8);
            }
            else if (*(int *)pQVar12 != -1) {
              LOCK();
              *(int *)pQVar12 = *(int *)pQVar12 + -1;
              UNLOCK();
              if (*(int *)pQVar12 == 0) {
                pQVar12 = *(QArrayData **)(lVar4 + 0x18);
                goto LAB_00902564;
              }
            }
            piVar9 = *(int **)(lVar4 + 0x20);
            if (piVar9 != (int *)0x0) {
              LOCK();
              *piVar9 = *piVar9 + -1;
              UNLOCK();
              if ((*piVar9 == 0) && (*(void **)(lVar4 + 0x20) != (void *)0x0)) {
                operator_delete(*(void **)(lVar4 + 0x20));
              }
            }
            lVar5 = *(long *)(lVar4 + 8);
            if (lVar5 != 0) {
              pQVar12 = *(QArrayData **)(lVar5 + 0x18);
              if (*(int *)pQVar12 == 0) {
LAB_0090266d:
                QArrayData::deallocate(pQVar12,2,8);
              }
              else if (*(int *)pQVar12 != -1) {
                LOCK();
                *(int *)pQVar12 = *(int *)pQVar12 + -1;
                UNLOCK();
                if (*(int *)pQVar12 == 0) {
                  pQVar12 = *(QArrayData **)(lVar5 + 0x18);
                  goto LAB_0090266d;
                }
              }
              piVar9 = *(int **)(lVar5 + 0x20);
              if (piVar9 != (int *)0x0) {
                LOCK();
                *piVar9 = *piVar9 + -1;
                UNLOCK();
                if ((*piVar9 == 0) && (*(void **)(lVar5 + 0x20) != (void *)0x0)) {
                  operator_delete(*(void **)(lVar5 + 0x20));
                }
              }
              lVar6 = *(long *)(lVar5 + 8);
              if (lVar6 != 0) {
                pQVar12 = *(QArrayData **)(lVar6 + 0x18);
                if (*(int *)pQVar12 == 0) {
LAB_009028ef:
                  QArrayData::deallocate(pQVar12,2,8);
                }
                else if (*(int *)pQVar12 != -1) {
                  LOCK();
                  *(int *)pQVar12 = *(int *)pQVar12 + -1;
                  UNLOCK();
                  if (*(int *)pQVar12 == 0) {
                    pQVar12 = *(QArrayData **)(lVar6 + 0x18);
                    goto LAB_009028ef;
                  }
                }
                piVar9 = *(int **)(lVar6 + 0x20);
                if (piVar9 != (int *)0x0) {
                  LOCK();
                  *piVar9 = *piVar9 + -1;
                  UNLOCK();
                  if ((*piVar9 == 0) && (*(void **)(lVar6 + 0x20) != (void *)0x0)) {
                    operator_delete(*(void **)(lVar6 + 0x20));
                  }
                }
                if (*(long *)(lVar6 + 8) != 0) {
                  FUN_0064e5d8();
                }
                if (*(long *)(lVar6 + 0x10) != 0) {
                  FUN_0064e5d8();
                }
              }
              lVar5 = *(long *)(lVar5 + 0x10);
              if (lVar5 != 0) {
                pQVar12 = *(QArrayData **)(lVar5 + 0x18);
                if (*(int *)pQVar12 == 0) {
LAB_009028d7:
                  QArrayData::deallocate(pQVar12,2,8);
                }
                else if (*(int *)pQVar12 != -1) {
                  LOCK();
                  *(int *)pQVar12 = *(int *)pQVar12 + -1;
                  UNLOCK();
                  if (*(int *)pQVar12 == 0) {
                    pQVar12 = *(QArrayData **)(lVar5 + 0x18);
                    goto LAB_009028d7;
                  }
                }
                piVar9 = *(int **)(lVar5 + 0x20);
                if (piVar9 != (int *)0x0) {
                  LOCK();
                  *piVar9 = *piVar9 + -1;
                  UNLOCK();
                  if ((*piVar9 == 0) && (*(void **)(lVar5 + 0x20) != (void *)0x0)) {
                    operator_delete(*(void **)(lVar5 + 0x20));
                  }
                }
                if (*(long *)(lVar5 + 8) != 0) {
                  FUN_0064e5d8();
                }
                if (*(long *)(lVar5 + 0x10) != 0) {
                  FUN_0064e5d8();
                }
              }
            }
            lVar4 = *(long *)(lVar4 + 0x10);
            if (lVar4 != 0) {
              pQVar12 = *(QArrayData **)(lVar4 + 0x18);
              if (*(int *)pQVar12 == 0) {
LAB_00902685:
                QArrayData::deallocate(pQVar12,2,8);
              }
              else if (*(int *)pQVar12 != -1) {
                LOCK();
                *(int *)pQVar12 = *(int *)pQVar12 + -1;
                UNLOCK();
                if (*(int *)pQVar12 == 0) {
                  pQVar12 = *(QArrayData **)(lVar4 + 0x18);
                  goto LAB_00902685;
                }
              }
              piVar9 = *(int **)(lVar4 + 0x20);
              if (piVar9 != (int *)0x0) {
                LOCK();
                *piVar9 = *piVar9 + -1;
                UNLOCK();
                if ((*piVar9 == 0) && (*(void **)(lVar4 + 0x20) != (void *)0x0)) {
                  operator_delete(*(void **)(lVar4 + 0x20));
                }
              }
              lVar5 = *(long *)(lVar4 + 8);
              if (lVar5 != 0) {
                pQVar12 = *(QArrayData **)(lVar5 + 0x18);
                if (*(int *)pQVar12 == 0) {
LAB_009028a7:
                  QArrayData::deallocate(pQVar12,2,8);
                }
                else if (*(int *)pQVar12 != -1) {
                  LOCK();
                  *(int *)pQVar12 = *(int *)pQVar12 + -1;
                  UNLOCK();
                  if (*(int *)pQVar12 == 0) {
                    pQVar12 = *(QArrayData **)(lVar5 + 0x18);
                    goto LAB_009028a7;
                  }
                }
                piVar9 = *(int **)(lVar5 + 0x20);
                if (piVar9 != (int *)0x0) {
                  LOCK();
                  *piVar9 = *piVar9 + -1;
                  UNLOCK();
                  if ((*piVar9 == 0) && (*(void **)(lVar5 + 0x20) != (void *)0x0)) {
                    operator_delete(*(void **)(lVar5 + 0x20));
                  }
                }
                if (*(long *)(lVar5 + 8) != 0) {
                  FUN_0064e5d8();
                }
                if (*(long *)(lVar5 + 0x10) != 0) {
                  FUN_0064e5d8();
                }
              }
              lVar4 = *(long *)(lVar4 + 0x10);
              if (lVar4 != 0) {
                pQVar12 = *(QArrayData **)(lVar4 + 0x18);
                if (*(int *)pQVar12 == 0) {
LAB_0090288f:
                  QArrayData::deallocate(pQVar12,2,8);
                }
                else if (*(int *)pQVar12 != -1) {
                  LOCK();
                  *(int *)pQVar12 = *(int *)pQVar12 + -1;
                  UNLOCK();
                  if (*(int *)pQVar12 == 0) {
                    pQVar12 = *(QArrayData **)(lVar4 + 0x18);
                    goto LAB_0090288f;
                  }
                }
                piVar9 = *(int **)(lVar4 + 0x20);
                if (piVar9 != (int *)0x0) {
                  LOCK();
                  *piVar9 = *piVar9 + -1;
                  UNLOCK();
                  if ((*piVar9 == 0) && (*(void **)(lVar4 + 0x20) != (void *)0x0)) {
                    operator_delete(*(void **)(lVar4 + 0x20));
                  }
                }
                if (*(long *)(lVar4 + 8) != 0) {
                  FUN_0064e5d8();
                }
                if (*(long *)(lVar4 + 0x10) != 0) {
                  FUN_0064e5d8();
                }
              }
            }
          }
          lVar3 = *(long *)(lVar3 + 0x10);
          if (lVar3 != 0) {
            pQVar12 = *(QArrayData **)(lVar3 + 0x18);
            if (*(int *)pQVar12 == 0) {
LAB_0090254c:
              QArrayData::deallocate(pQVar12,2,8);
            }
            else if (*(int *)pQVar12 != -1) {
              LOCK();
              *(int *)pQVar12 = *(int *)pQVar12 + -1;
              UNLOCK();
              if (*(int *)pQVar12 == 0) {
                pQVar12 = *(QArrayData **)(lVar3 + 0x18);
                goto LAB_0090254c;
              }
            }
            piVar9 = *(int **)(lVar3 + 0x20);
            if (piVar9 != (int *)0x0) {
              LOCK();
              *piVar9 = *piVar9 + -1;
              UNLOCK();
              if ((*piVar9 == 0) && (*(void **)(lVar3 + 0x20) != (void *)0x0)) {
                operator_delete(*(void **)(lVar3 + 0x20));
              }
            }
            lVar4 = *(long *)(lVar3 + 8);
            if (lVar4 != 0) {
              pQVar12 = *(QArrayData **)(lVar4 + 0x18);
              if (*(int *)pQVar12 == 0) {
LAB_0090263c:
                QArrayData::deallocate(pQVar12,2,8);
              }
              else if (*(int *)pQVar12 != -1) {
                LOCK();
                *(int *)pQVar12 = *(int *)pQVar12 + -1;
                UNLOCK();
                if (*(int *)pQVar12 == 0) {
                  pQVar12 = *(QArrayData **)(lVar4 + 0x18);
                  goto LAB_0090263c;
                }
              }
              piVar9 = *(int **)(lVar4 + 0x20);
              if (piVar9 != (int *)0x0) {
                LOCK();
                *piVar9 = *piVar9 + -1;
                UNLOCK();
                if ((*piVar9 == 0) && (*(void **)(lVar4 + 0x20) != (void *)0x0)) {
                  operator_delete(*(void **)(lVar4 + 0x20));
                }
              }
              lVar5 = *(long *)(lVar4 + 8);
              if (lVar5 != 0) {
                pQVar12 = *(QArrayData **)(lVar5 + 0x18);
                if (*(int *)pQVar12 == 0) {
LAB_009028bf:
                  QArrayData::deallocate(pQVar12,2,8);
                }
                else if (*(int *)pQVar12 != -1) {
                  LOCK();
                  *(int *)pQVar12 = *(int *)pQVar12 + -1;
                  UNLOCK();
                  if (*(int *)pQVar12 == 0) {
                    pQVar12 = *(QArrayData **)(lVar5 + 0x18);
                    goto LAB_009028bf;
                  }
                }
                piVar9 = *(int **)(lVar5 + 0x20);
                if (piVar9 != (int *)0x0) {
                  LOCK();
                  *piVar9 = *piVar9 + -1;
                  UNLOCK();
                  if ((*piVar9 == 0) && (*(void **)(lVar5 + 0x20) != (void *)0x0)) {
                    operator_delete(*(void **)(lVar5 + 0x20));
                  }
                }
                if (*(long *)(lVar5 + 8) != 0) {
                  FUN_0064e5d8();
                }
                if (*(long *)(lVar5 + 0x10) != 0) {
                  FUN_0064e5d8();
                }
              }
              lVar4 = *(long *)(lVar4 + 0x10);
              if (lVar4 != 0) {
                pQVar12 = *(QArrayData **)(lVar4 + 0x18);
                if (*(int *)pQVar12 == 0) {
LAB_009027f7:
                  QArrayData::deallocate(pQVar12,2,8);
                }
                else if (*(int *)pQVar12 != -1) {
                  LOCK();
                  *(int *)pQVar12 = *(int *)pQVar12 + -1;
                  UNLOCK();
                  if (*(int *)pQVar12 == 0) {
                    pQVar12 = *(QArrayData **)(lVar4 + 0x18);
                    goto LAB_009027f7;
                  }
                }
                piVar9 = *(int **)(lVar4 + 0x20);
                if (piVar9 != (int *)0x0) {
                  LOCK();
                  *piVar9 = *piVar9 + -1;
                  UNLOCK();
                  if ((*piVar9 == 0) && (*(void **)(lVar4 + 0x20) != (void *)0x0)) {
                    operator_delete(*(void **)(lVar4 + 0x20));
                  }
                }
                if (*(long *)(lVar4 + 8) != 0) {
                  FUN_0064e5d8();
                }
                if (*(long *)(lVar4 + 0x10) != 0) {
                  FUN_0064e5d8();
                }
              }
            }
            lVar3 = *(long *)(lVar3 + 0x10);
            if (lVar3 != 0) {
              pQVar12 = *(QArrayData **)(lVar3 + 0x18);
              if (*(int *)pQVar12 == 0) {
LAB_00902655:
                QArrayData::deallocate(pQVar12,2,8);
              }
              else if (*(int *)pQVar12 != -1) {
                LOCK();
                *(int *)pQVar12 = *(int *)pQVar12 + -1;
                UNLOCK();
                if (*(int *)pQVar12 == 0) {
                  pQVar12 = *(QArrayData **)(lVar3 + 0x18);
                  goto LAB_00902655;
                }
              }
              piVar9 = *(int **)(lVar3 + 0x20);
              if (piVar9 != (int *)0x0) {
                LOCK();
                *piVar9 = *piVar9 + -1;
                UNLOCK();
                if ((*piVar9 == 0) && (*(void **)(lVar3 + 0x20) != (void *)0x0)) {
                  operator_delete(*(void **)(lVar3 + 0x20));
                }
              }
              lVar4 = *(long *)(lVar3 + 8);
              if (lVar4 != 0) {
                pQVar12 = *(QArrayData **)(lVar4 + 0x18);
                if (*(int *)pQVar12 == 0) {
LAB_00902907:
                  QArrayData::deallocate(pQVar12,2,8);
                }
                else if (*(int *)pQVar12 != -1) {
                  LOCK();
                  *(int *)pQVar12 = *(int *)pQVar12 + -1;
                  UNLOCK();
                  if (*(int *)pQVar12 == 0) {
                    pQVar12 = *(QArrayData **)(lVar4 + 0x18);
                    goto LAB_00902907;
                  }
                }
                piVar9 = *(int **)(lVar4 + 0x20);
                if (piVar9 != (int *)0x0) {
                  LOCK();
                  *piVar9 = *piVar9 + -1;
                  UNLOCK();
                  if ((*piVar9 == 0) && (*(void **)(lVar4 + 0x20) != (void *)0x0)) {
                    operator_delete(*(void **)(lVar4 + 0x20));
                  }
                }
                if (*(long *)(lVar4 + 8) != 0) {
                  FUN_0064e5d8();
                }
                if (*(long *)(lVar4 + 0x10) != 0) {
                  FUN_0064e5d8();
                }
              }
              lVar3 = *(long *)(lVar3 + 0x10);
              if (lVar3 != 0) {
                pQVar12 = *(QArrayData **)(lVar3 + 0x18);
                if (*(int *)pQVar12 == 0) {
LAB_00902938:
                  QArrayData::deallocate(pQVar12,2,8);
                }
                else if (*(int *)pQVar12 != -1) {
                  LOCK();
                  *(int *)pQVar12 = *(int *)pQVar12 + -1;
                  UNLOCK();
                  if (*(int *)pQVar12 == 0) {
                    pQVar12 = *(QArrayData **)(lVar3 + 0x18);
                    goto LAB_00902938;
                  }
                }
                piVar9 = *(int **)(lVar3 + 0x20);
                if (piVar9 != (int *)0x0) {
                  LOCK();
                  *piVar9 = *piVar9 + -1;
                  UNLOCK();
                  if ((*piVar9 == 0) && (*(void **)(lVar3 + 0x20) != (void *)0x0)) {
                    operator_delete(*(void **)(lVar3 + 0x20));
                  }
                }
                if (*(long *)(lVar3 + 8) != 0) {
                  FUN_0064e5d8();
                }
                if (*(long *)(lVar3 + 0x10) != 0) {
                  FUN_0064e5d8();
                }
              }
            }
          }
        }
      }
      QMapDataBase::freeTree(pQVar10,(int)*(undefined8 *)(pQVar10 + 0x10));
    }
    QMapDataBase::freeData((QMapDataBase *)pQVar10);
    pDVar13 = *(Data **)(param_1 + 0x18);
    iVar2 = *(int *)pDVar13;
  }
  else {
    if (*(int *)pQVar10 != -1) {
      LOCK();
      *(int *)pQVar10 = *(int *)pQVar10 + -1;
      UNLOCK();
      if (*(int *)pQVar10 == 0) {
        pQVar10 = *(QMapNodeBase **)(param_1 + 0x20);
        goto LAB_00900f3f;
      }
    }
    pDVar13 = *(Data **)(param_1 + 0x18);
    iVar2 = *(int *)pDVar13;
  }
  if (iVar2 != 0) {
    if (iVar2 == -1) goto LAB_00900f25;
    LOCK();
    *(int *)pDVar13 = *(int *)pDVar13 + -1;
    UNLOCK();
    if (*(int *)pDVar13 != 0) goto LAB_00900f25;
    pDVar13 = *(Data **)(param_1 + 0x18);
  }
  pDVar11 = pDVar13 + (long)*(int *)(pDVar13 + 0xc) * 8 + 0x10;
  iVar2 = *(int *)(pDVar13 + 8);
joined_r0x0090245c:
  if (pDVar11 != pDVar13 + (long)iVar2 * 8 + 0x10) {
    do {
      pDVar11 = pDVar11 + -8;
      piVar9 = *(int **)pDVar11;
      if (*piVar9 != 0) {
        if (*piVar9 == -1) goto joined_r0x0090245c;
        LOCK();
        iVar1 = *piVar9;
        *piVar9 = *piVar9 + -1;
        UNLOCK();
        if (iVar1 != 1) goto joined_r0x0090245c;
      }
      QArrayData::deallocate(*(QArrayData **)pDVar11,2,8);
      if (pDVar13 + (long)iVar2 * 8 + 0x10 == pDVar11) break;
    } while( true );
  }
  QListData::dispose(pDVar13);
LAB_00900f25:
  QObject::~QObject(param_1);
  return;
}


// ==== entry=00902ac0 orig=FUN_00902ac0 size=24 name=FileWatcher_metaObject ====

undefined ** FileWatcher_metaObject(long param_1)

{
  undefined **ppuVar1;
  
  if (*(long *)(*(long *)(param_1 + 8) + 0x28) != 0) {
    ppuVar1 = (undefined **)QObjectData::dynamicMetaObject();
    return ppuVar1;
  }
  return &PTR_staticMetaObject_0119ffc0;
}


// ==== entry=00902ad8 name=FUN_00902ad8 size=39 ====

void FUN_00902ad8(QObject *param_1,undefined8 param_2)

{
  void *local_18;
  undefined8 local_10;
  
  local_18 = (void *)0x0;
  local_10 = param_2;
  QMetaObject::activate(param_1,(QMetaObject *)&PTR_staticMetaObject_0119ffc0,0,&local_18);
  return;
}


// ==== entry=00902b00 name=FUN_00902b00 size=42 ====

void FUN_00902b00(QObject *param_1,undefined8 param_2)

{
  void *local_18;
  undefined8 local_10;
  
  local_18 = (void *)0x0;
  local_10 = param_2;
  QMetaObject::activate(param_1,(QMetaObject *)&PTR_staticMetaObject_0119ffc0,1,&local_18);
  return;
}


// ==== entry=00902b2a name=FUN_00902b2a size=94 ====

void FUN_00902b2a(undefined8 param_1,int param_2,int param_3,undefined8 *param_4)

{
  long *plVar1;
  
  if (param_2 != 0) {
    if (param_2 == 10) {
      plVar1 = (long *)param_4[1];
      if ((code *)*plVar1 == FUN_00902ad8) {
        if (plVar1[1] == 0) {
          *(undefined4 *)*param_4 = 0;
          return;
        }
      }
      else if (((code *)*plVar1 == FUN_00902b00) && (plVar1[1] == 0)) {
        *(undefined4 *)*param_4 = 1;
        return;
      }
    }
    return;
  }
  if (param_3 == 0) {
    FUN_00902ad8(param_1,param_4[1]);
    return;
  }
  if (param_3 == 1) {
    FUN_00902b00(param_1,param_4[1]);
    return;
  }
  return;
}


// ==== entry=00902b88 orig=FUN_00902b88 size=66 name=FileWatcher_qt_metacast ====

char * FileWatcher_qt_metacast(char *param_1,char *param_2)

{
  int iVar1;
  char *pcVar2;
  
  if (param_2 == (char *)0x0) {
    return (char *)0x0;
  }
  iVar1 = strcmp(param_2,"FileWatcher");
  if (iVar1 == 0) {
    return param_1;
  }
  pcVar2 = (char *)QThread::qt_metacast(param_1);
  return pcVar2;
}


// ==== entry=00902bca orig=FUN_00902bca size=93 name=FileWatcher_qt_metacall ====

ulong FileWatcher_qt_metacall(undefined8 param_1,int param_2,undefined8 param_3,undefined8 *param_4)

{
  int iVar1;
  ulong uVar2;
  
  uVar2 = QThread::qt_metacall();
  iVar1 = (int)uVar2;
  if (-1 < iVar1) {
    if (param_2 == 0) {
      if (iVar1 < 2) {
        FUN_00902b2a(param_1,0,uVar2 & 0xffffffff,param_4);
        uVar2 = uVar2 & 0xffffffff;
      }
    }
    else {
      if (param_2 != 0xc) {
        return uVar2;
      }
      if (iVar1 < 2) {
        *(undefined4 *)*param_4 = 0xffffffff;
      }
    }
    uVar2 = (ulong)((int)uVar2 - 2);
  }
  return uVar2;
}


// ==== entry=00902c28 name=FUN_00902c28 size=1 ====

void FUN_00902c28(void)

{
  return;
}


// ==== entry=00902c2a orig=FUN_00902c2a size=24 name=SuperTranslator_metaObject ====

undefined ** SuperTranslator_metaObject(long param_1)

{
  undefined **ppuVar1;
  
  if (*(long *)(*(long *)(param_1 + 8) + 0x28) != 0) {
    ppuVar1 = (undefined **)QObjectData::dynamicMetaObject();
    return ppuVar1;
  }
  return &PTR_staticMetaObject_011a00a0;
}


// ==== entry=00902c42 orig=FUN_00902c42 size=66 name=SuperTranslator_qt_metacast ====

char * SuperTranslator_qt_metacast(char *param_1,char *param_2)

{
  int iVar1;
  char *pcVar2;
  
  if (param_2 == (char *)0x0) {
    return (char *)0x0;
  }
  iVar1 = strcmp(param_2,"SuperTranslator");
  if (iVar1 == 0) {
    return param_1;
  }
  pcVar2 = (char *)QTranslator::qt_metacast(param_1);
  return pcVar2;
}


// ==== entry=00902c84 orig=FUN_00902c84 size=5 name=SuperTranslator_qt_metacall ====

void QTranslator::SuperTranslator_qt_metacall(void)

{
  qt_metacall();
  return;
}


// ==== entry=00902c8a orig=FUN_00902c8a size=84 name=SuperTranslator_dtor_deleting ====

void SuperTranslator_dtor_deleting(QTranslator *param_1)

{
  code *pcVar1;
  _func_void_Node_ptr *p_Var2;
  
  *(undefined ***)param_1 = &SuperTranslator_vtable;
  p_Var2 = *(_func_void_Node_ptr **)(param_1 + 0x18);
  if (*(int *)(p_Var2 + 0x10) != 0) {
    if (*(int *)(p_Var2 + 0x10) == -1) goto LAB_00902cb6;
    pcVar1 = p_Var2 + 0x10;
    LOCK();
    *(int *)pcVar1 = *(int *)pcVar1 + -1;
    UNLOCK();
    if (*(int *)pcVar1 != 0) goto LAB_00902cb6;
    p_Var2 = *(_func_void_Node_ptr **)(param_1 + 0x18);
  }
  QHashData::free_helper(p_Var2);
LAB_00902cb6:
  QTranslator::~QTranslator(param_1);
  operator_delete(param_1,0x20);
  return;
}


// ==== entry=00902cde orig=FUN_00902cde size=78 name=SuperTranslator_dtor ====

void SuperTranslator_dtor(QTranslator *param_1)

{
  code *pcVar1;
  _func_void_Node_ptr *p_Var2;
  
  *(undefined ***)param_1 = &SuperTranslator_vtable;
  p_Var2 = *(_func_void_Node_ptr **)(param_1 + 0x18);
  if (*(int *)(p_Var2 + 0x10) == 0) {
LAB_00902d17:
    QHashData::free_helper(p_Var2);
    QTranslator::~QTranslator(param_1);
    return;
  }
  if (*(int *)(p_Var2 + 0x10) != -1) {
    pcVar1 = p_Var2 + 0x10;
    LOCK();
    *(int *)pcVar1 = *(int *)pcVar1 + -1;
    UNLOCK();
    if (*(int *)pcVar1 == 0) {
      p_Var2 = *(_func_void_Node_ptr **)(param_1 + 0x18);
      goto LAB_00902d17;
    }
  }
  QTranslator::~QTranslator(param_1);
  return;
}


// ==== entry=00902d30 name=FUN_00902d30 size=10 ====

void FUN_00902d30(undefined8 param_1,int param_2,int param_3)

{
  if (param_3 == 0 && param_2 == 0) {
    FUN_0063a2e0();
    return;
  }
  return;
}


// ==== entry=00902d3a orig=FUN_00902d3a size=24 name=CyclicMemoryPool_metaObject ====

undefined ** CyclicMemoryPool_metaObject(long param_1)

{
  undefined **ppuVar1;
  
  if (*(long *)(*(long *)(param_1 + 8) + 0x28) != 0) {
    ppuVar1 = (undefined **)QObjectData::dynamicMetaObject();
    return ppuVar1;
  }
  return &PTR_staticMetaObject_011a0160;
}


// ==== entry=00902d52 orig=FUN_00902d52 size=66 name=CyclicMemoryPool_qt_metacast ====

char * CyclicMemoryPool_qt_metacast(char *param_1,char *param_2)

{
  int iVar1;
  char *pcVar2;
  
  if (param_2 == (char *)0x0) {
    return (char *)0x0;
  }
  iVar1 = strcmp(param_2,"CyclicMemoryPool");
  if (iVar1 == 0) {
    return param_1;
  }
  pcVar2 = (char *)QObject::qt_metacast(param_1);
  return pcVar2;
}


// ==== entry=00902d94 orig=FUN_00902d94 size=84 name=CyclicMemoryPool_qt_metacall ====

ulong CyclicMemoryPool_qt_metacall
                (undefined8 param_1,int param_2,undefined8 param_3,undefined8 *param_4)

{
  int iVar1;
  ulong uVar2;
  
  uVar2 = QObject::qt_metacall();
  iVar1 = (int)uVar2;
  if (-1 < iVar1) {
    if (param_2 == 0) {
      if (iVar1 == 0) {
        FUN_0063a2e0(param_1);
        uVar2 = uVar2 & 0xffffffff;
      }
    }
    else {
      if (param_2 != 0xc) {
        return uVar2;
      }
      if (iVar1 == 0) {
        *(undefined4 *)*param_4 = 0xffffffff;
      }
    }
    uVar2 = (ulong)((int)uVar2 - 1);
  }
  return uVar2;
}


// ==== entry=00902de8 orig=FUN_00902de8 size=67 name=CyclicMemoryPool_dtor ====

void CyclicMemoryPool_dtor(QObject *param_1)

{
  void *pvVar1;
  
  *(undefined ***)param_1 = &CyclicMemoryPool_vtable;
  pvVar1 = *(void **)(param_1 + 0x20);
  if (pvVar1 != (void *)0x0) {
    FUN_00a80de0(pvVar1);
    operator_delete(pvVar1,0x20);
  }
  QObject::~QObject(param_1);
  return;
}


// ==== entry=00902e2c orig=FUN_00902e2c size=80 name=CyclicMemoryPool_dtor_deleting ====

void CyclicMemoryPool_dtor_deleting(QObject *param_1)

{
  void *pvVar1;
  
  *(undefined ***)param_1 = &CyclicMemoryPool_vtable;
  pvVar1 = *(void **)(param_1 + 0x20);
  if (pvVar1 != (void *)0x0) {
    FUN_00a80de0(pvVar1);
    operator_delete(pvVar1,0x20);
  }
  QObject::~QObject(param_1);
  operator_delete(param_1,0x28);
  return;
}


// ==== entry=00902e80 orig=FUN_00902e80 size=24 name=TransferTask_metaObject ====

undefined ** TransferTask_metaObject(long param_1)

{
  undefined **ppuVar1;
  
  if (*(long *)(*(long *)(param_1 + 8) + 0x28) != 0) {
    ppuVar1 = (undefined **)QObjectData::dynamicMetaObject();
    return ppuVar1;
  }
  return &PTR_staticMetaObject_011a0220;
}


// ==== entry=00902e98 name=FUN_00902e98 size=39 ====

void FUN_00902e98(QObject *param_1,undefined8 param_2)

{
  void *local_18;
  undefined8 local_10;
  
  local_18 = (void *)0x0;
  local_10 = param_2;
  QMetaObject::activate(param_1,(QMetaObject *)&PTR_staticMetaObject_011a0220,0,&local_18);
  return;
}


// ==== entry=00902ec0 name=FUN_00902ec0 size=42 ====

void FUN_00902ec0(QObject *param_1,undefined8 param_2)

{
  void *local_18;
  undefined8 local_10;
  
  local_18 = (void *)0x0;
  local_10 = param_2;
  QMetaObject::activate(param_1,(QMetaObject *)&PTR_staticMetaObject_011a0220,1,&local_18);
  return;
}


// ==== entry=00902eea name=FUN_00902eea size=94 ====

void FUN_00902eea(undefined8 param_1,int param_2,int param_3,undefined8 *param_4)

{
  long *plVar1;
  
  if (param_2 != 0) {
    if (param_2 == 10) {
      plVar1 = (long *)param_4[1];
      if ((code *)*plVar1 == FUN_00902e98) {
        if (plVar1[1] == 0) {
          *(undefined4 *)*param_4 = 0;
          return;
        }
      }
      else if (((code *)*plVar1 == FUN_00902ec0) && (plVar1[1] == 0)) {
        *(undefined4 *)*param_4 = 1;
        return;
      }
    }
    return;
  }
  if (param_3 == 0) {
    FUN_00902e98(param_1,param_4[1]);
    return;
  }
  if (param_3 == 1) {
    FUN_00902ec0(param_1,param_4[1]);
    return;
  }
  return;
}


// ==== entry=00902f48 orig=FUN_00902f48 size=66 name=TransferTask_qt_metacast ====

char * TransferTask_qt_metacast(char *param_1,char *param_2)

{
  int iVar1;
  char *pcVar2;
  
  if (param_2 == (char *)0x0) {
    return (char *)0x0;
  }
  iVar1 = strcmp(param_2,"TransferTask");
  if (iVar1 == 0) {
    return param_1;
  }
  pcVar2 = (char *)QObject::qt_metacast(param_1);
  return pcVar2;
}


// ==== entry=00902f8a orig=FUN_00902f8a size=93 name=TransferTask_qt_metacall ====

ulong TransferTask_qt_metacall
                (undefined8 param_1,int param_2,undefined8 param_3,undefined8 *param_4)

{
  int iVar1;
  ulong uVar2;
  
  uVar2 = QObject::qt_metacall();
  iVar1 = (int)uVar2;
  if (-1 < iVar1) {
    if (param_2 == 0) {
      if (iVar1 < 2) {
        FUN_00902eea(param_1,0,uVar2 & 0xffffffff,param_4);
        uVar2 = uVar2 & 0xffffffff;
      }
    }
    else {
      if (param_2 != 0xc) {
        return uVar2;
      }
      if (iVar1 < 2) {
        *(undefined4 *)*param_4 = 0xffffffff;
      }
    }
    uVar2 = (ulong)((int)uVar2 - 2);
  }
  return uVar2;
}


// ==== entry=00902fe8 name=FUN_00902fe8 size=1 ====

void FUN_00902fe8(void)

{
  return;
}


// ==== entry=00902fea name=FUN_00902fea size=24 ====

undefined ** FUN_00902fea(long param_1)

{
  undefined **ppuVar1;
  
  if (*(long *)(*(long *)(param_1 + 8) + 0x28) != 0) {
    ppuVar1 = (undefined **)QObjectData::dynamicMetaObject();
    return ppuVar1;
  }
  return &PTR_staticMetaObject_011a0400;
}


// ==== entry=00903002 orig=FUN_00903002 size=66 name=s_TreeModel_903002 ====

char * s_TreeModel_903002(char *param_1,char *param_2)

{
  int iVar1;
  char *pcVar2;
  
  if (param_2 == (char *)0x0) {
    return (char *)0x0;
  }
  iVar1 = strcmp(param_2,"TreeModel");
  if (iVar1 == 0) {
    return param_1;
  }
  pcVar2 = (char *)QAbstractItemModel::qt_metacast(param_1);
  return pcVar2;
}


// ==== entry=00903044 orig=FUN_00903044 size=5 name=qt_metacall ====

void QAbstractItemModel::qt_metacall(void)

{
  qt_metacall();
  return;
}


// ==== entry=0090304a name=FUN_0090304a size=1 ====

void FUN_0090304a(void)

{
  return;
}


// ==== entry=0090304c name=FUN_0090304c size=24 ====

undefined ** FUN_0090304c(long param_1)

{
  undefined **ppuVar1;
  
  if (*(long *)(*(long *)(param_1 + 8) + 0x28) != 0) {
    ppuVar1 = (undefined **)QObjectData::dynamicMetaObject();
    return ppuVar1;
  }
  return &PTR_staticMetaObject_011a05e0;
}


// ==== entry=00903064 orig=FUN_00903064 size=66 name=TreeListModel_dtor ====

char * TreeListModel_dtor(char *param_1,char *param_2)

{
  int iVar1;
  char *pcVar2;
  
  if (param_2 == (char *)0x0) {
    return (char *)0x0;
  }
  iVar1 = strcmp(param_2,"TreeListModel");
  if (iVar1 == 0) {
    return param_1;
  }
  pcVar2 = (char *)QAbstractItemModel::qt_metacast(param_1);
  return pcVar2;
}


// ==== entry=009030a6 orig=FUN_009030a6 size=5 name=TreeListModel_dtor_deleting ====

void QAbstractItemModel::TreeListModel_dtor_deleting(void)

{
  qt_metacall();
  return;
}


// ==== entry=009030b0 orig=FUN_009030b0 size=24 name=FileReader_metaObject ====

undefined ** FileReader_metaObject(long param_1)

{
  undefined **ppuVar1;
  
  if (*(long *)(*(long *)(param_1 + 8) + 0x28) != 0) {
    ppuVar1 = (undefined **)QObjectData::dynamicMetaObject();
    return ppuVar1;
  }
  return &PTR_staticMetaObject_011a06a0;
}


// ==== entry=009030c8 name=FUN_009030c8 size=39 ====

void FUN_009030c8(QObject *param_1,undefined8 param_2)

{
  void *local_18;
  undefined8 local_10;
  
  local_18 = (void *)0x0;
  local_10 = param_2;
  QMetaObject::activate(param_1,(QMetaObject *)&PTR_staticMetaObject_011a06a0,0,&local_18);
  return;
}


// ==== entry=009030f0 name=FUN_009030f0 size=80 ====

void FUN_009030f0(QObject *param_1,undefined8 param_2,undefined1 param_3,undefined1 param_4)

{
  undefined1 local_38 [4];
  undefined1 local_34 [4];
  undefined8 local_30;
  void *local_28;
  undefined8 *local_20;
  undefined1 *local_18;
  undefined1 *local_10;
  
  local_10 = local_38;
  local_28 = (void *)0x0;
  local_20 = &local_30;
  local_18 = local_34;
  local_38[0] = param_4;
  local_34[0] = param_3;
  local_30 = param_2;
  QMetaObject::activate(param_1,(QMetaObject *)&PTR_staticMetaObject_011a06a0,1,&local_28);
  return;
}


// ==== entry=00903140 name=FUN_00903140 size=54 ====

void FUN_00903140(QObject *param_1,undefined4 param_2)

{
  undefined4 local_1c;
  void *local_18;
  undefined4 *local_10;
  
  local_18 = (void *)0x0;
  local_10 = &local_1c;
  local_1c = param_2;
  QMetaObject::activate(param_1,(QMetaObject *)&PTR_staticMetaObject_011a06a0,2,&local_18);
  return;
}


// ==== entry=00903176 name=FUN_00903176 size=82 ====

void FUN_00903176(QObject *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  void *local_28;
  undefined4 *local_20;
  undefined4 *local_18;
  undefined4 *local_10;
  
  local_28 = (void *)0x0;
  local_20 = &local_2c;
  local_18 = &local_30;
  local_10 = &local_34;
  local_34 = param_4;
  local_30 = param_3;
  local_2c = param_2;
  QMetaObject::activate(param_1,(QMetaObject *)&PTR_staticMetaObject_011a06a0,3,&local_28);
  return;
}


// ==== entry=009031c8 name=FUN_009031c8 size=79 ====

void FUN_009031c8(QObject *param_1,undefined1 param_2,undefined1 param_3,undefined8 param_4,
                 undefined8 param_5)

{
  undefined1 local_40 [4];
  undefined1 local_3c [4];
  void *local_38;
  undefined1 *local_30;
  undefined1 *local_28;
  undefined8 local_20;
  undefined8 local_18;
  
  local_38 = (void *)0x0;
  local_30 = local_3c;
  local_28 = local_40;
  local_40[0] = param_3;
  local_3c[0] = param_2;
  local_20 = param_4;
  local_18 = param_5;
  QMetaObject::activate(param_1,(QMetaObject *)&PTR_staticMetaObject_011a06a0,4,&local_38);
  return;
}


// ==== entry=00903218 name=FUN_00903218 size=55 ====

void FUN_00903218(QObject *param_1,undefined8 param_2)

{
  undefined8 local_20;
  void *local_18;
  undefined8 *local_10;
  
  local_18 = (void *)0x0;
  local_10 = &local_20;
  local_20 = param_2;
  QMetaObject::activate(param_1,(QMetaObject *)&PTR_staticMetaObject_011a06a0,5,&local_18);
  return;
}


// ==== entry=00903250 name=FUN_00903250 size=67 ====

void FUN_00903250(QObject *param_1,undefined8 param_2,undefined8 param_3)

{
  undefined8 local_38;
  undefined8 local_30;
  void *local_28;
  undefined8 *local_20;
  undefined1 *local_18;
  
  local_18 = (undefined1 *)&local_38;
  local_28 = (void *)0x0;
  local_20 = &local_30;
  local_38 = param_3;
  local_30 = param_2;
  QMetaObject::activate(param_1,(QMetaObject *)&PTR_staticMetaObject_011a06a0,7,&local_28);
  return;
}


// ==== entry=00903294 name=FUN_00903294 size=90 ====

void FUN_00903294(QObject *param_1,undefined8 param_2,undefined1 param_3,undefined1 param_4,
                 undefined8 param_5,undefined8 param_6)

{
  undefined1 local_48 [4];
  undefined1 local_44 [4];
  undefined8 local_40;
  void *local_38;
  undefined8 *local_30;
  undefined1 *local_28;
  undefined1 *local_20;
  undefined8 local_18;
  undefined8 local_10;
  
  local_20 = local_48;
  local_38 = (void *)0x0;
  local_30 = &local_40;
  local_28 = local_44;
  local_48[0] = param_4;
  local_44[0] = param_3;
  local_40 = param_2;
  local_18 = param_5;
  local_10 = param_6;
  QMetaObject::activate(param_1,(QMetaObject *)&PTR_staticMetaObject_011a06a0,6,&local_38);
  return;
}


// ==== entry=009032ee name=FUN_009032ee size=454 ====

void FUN_009032ee(undefined8 param_1,int param_2,undefined4 param_3,undefined8 *param_4)

{
  undefined4 *puVar1;
  long *plVar2;
  code *pcVar3;
  
  if (param_2 == 0) {
    switch(param_3) {
    case 0:
      FUN_009030c8(param_1,param_4[1]);
      return;
    case 1:
      FUN_009030f0(param_1,*(undefined8 *)param_4[1],*(undefined1 *)param_4[2],
                   *(undefined1 *)param_4[3]);
      return;
    case 2:
      FUN_00903140(param_1,*(undefined4 *)param_4[1]);
      return;
    case 3:
      FUN_00903176(param_1,*(undefined4 *)param_4[1],*(undefined4 *)param_4[2],
                   *(undefined4 *)param_4[3]);
      return;
    case 4:
      FUN_009031c8(param_1,*(undefined1 *)param_4[1],*(undefined1 *)param_4[2],param_4[3],param_4[4]
                  );
      return;
    case 5:
      FUN_00903218(param_1,*(undefined8 *)param_4[1]);
      return;
    case 6:
      FUN_00903294(param_1,*(undefined8 *)param_4[1],(int)*(char *)param_4[2],
                   (int)*(char *)param_4[3],param_4[4],param_4[5]);
      return;
    case 7:
      FUN_00903250(param_1,*(undefined8 *)param_4[1],*(undefined8 *)param_4[2]);
      return;
    }
  }
  else if (param_2 == 10) {
    puVar1 = (undefined4 *)*param_4;
    plVar2 = (long *)param_4[1];
    pcVar3 = (code *)*plVar2;
    if ((pcVar3 == FUN_009030c8) && (plVar2[1] == 0)) {
      *puVar1 = 0;
      return;
    }
    if ((pcVar3 == FUN_009030f0) && (plVar2[1] == 0)) {
      *puVar1 = 1;
      return;
    }
    if ((pcVar3 == FUN_00903140) && (plVar2[1] == 0)) {
      *puVar1 = 2;
      return;
    }
    if ((pcVar3 == FUN_00903176) && (plVar2[1] == 0)) {
      *puVar1 = 3;
      return;
    }
    if ((pcVar3 == FUN_009031c8) && (plVar2[1] == 0)) {
      *puVar1 = 4;
      return;
    }
    if ((pcVar3 == FUN_00903218) && (plVar2[1] == 0)) {
      *puVar1 = 5;
      return;
    }
    if ((pcVar3 == FUN_00903294) && (plVar2[1] == 0)) {
      *puVar1 = 6;
      return;
    }
    if ((pcVar3 == FUN_00903250) && (plVar2[1] == 0)) {
      *puVar1 = 7;
    }
  }
  return;
}


// ==== entry=009034b4 orig=FUN_009034b4 size=66 name=FileReader_qt_metacast ====

char * FileReader_qt_metacast(char *param_1,char *param_2)

{
  int iVar1;
  char *pcVar2;
  
  if (param_2 == (char *)0x0) {
    return (char *)0x0;
  }
  iVar1 = strcmp(param_2,"FileReader");
  if (iVar1 == 0) {
    return param_1;
  }
  pcVar2 = (char *)QThread::qt_metacast(param_1);
  return pcVar2;
}


// ==== entry=009034f6 orig=FUN_009034f6 size=93 name=FileReader_qt_metacall ====

ulong FileReader_qt_metacall(undefined8 param_1,int param_2,undefined8 param_3,undefined8 *param_4)

{
  int iVar1;
  ulong uVar2;
  
  uVar2 = QThread::qt_metacall();
  iVar1 = (int)uVar2;
  if (-1 < iVar1) {
    if (param_2 == 0) {
      if (iVar1 < 8) {
        FUN_009032ee(param_1,0,uVar2 & 0xffffffff,param_4);
        uVar2 = uVar2 & 0xffffffff;
      }
    }
    else {
      if (param_2 != 0xc) {
        return uVar2;
      }
      if (iVar1 < 8) {
        *(undefined4 *)*param_4 = 0xffffffff;
      }
    }
    uVar2 = (ulong)((int)uVar2 - 8);
  }
  return uVar2;
}


// ==== entry=00903554 name=FUN_00903554 size=1 ====

void FUN_00903554(void)

{
  return;
}


// ==== entry=00903556 orig=FUN_00903556 size=24 name=SuperAction_metaObject ====

undefined ** SuperAction_metaObject(long param_1)

{
  undefined **ppuVar1;
  
  if (*(long *)(*(long *)(param_1 + 8) + 0x28) != 0) {
    ppuVar1 = (undefined **)QObjectData::dynamicMetaObject();
    return ppuVar1;
  }
  return &PTR_staticMetaObject_011a0760;
}


// ==== entry=0090356e orig=FUN_0090356e size=66 name=SuperAction_qt_metacast ====

char * SuperAction_qt_metacast(char *param_1,char *param_2)

{
  int iVar1;
  char *pcVar2;
  
  if (param_2 == (char *)0x0) {
    return (char *)0x0;
  }
  iVar1 = strcmp(param_2,"SuperAction");
  if (iVar1 == 0) {
    return param_1;
  }
  pcVar2 = (char *)QObject::qt_metacast(param_1);
  return pcVar2;
}


// ==== entry=009035b0 orig=FUN_009035b0 size=5 name=SuperAction_qt_metacall ====

void QObject::SuperAction_qt_metacall(void)

{
  qt_metacall();
  return;
}


// ==== entry=009035b6 orig=FUN_009035b6 size=87 name=SuperAction_dtor ====

void SuperAction_dtor(QObject *param_1)

{
  code *pcVar1;
  _func_void_Node_ptr *p_Var2;
  
  *(undefined ***)param_1 = &SuperAction_vtable;
  QJSValue::~QJSValue((QJSValue *)(param_1 + 0x18));
  p_Var2 = *(_func_void_Node_ptr **)(param_1 + 0x10);
  if (*(int *)(p_Var2 + 0x10) == 0) {
LAB_009035f8:
    QHashData::free_helper(p_Var2);
    QObject::~QObject(param_1);
    return;
  }
  if (*(int *)(p_Var2 + 0x10) != -1) {
    pcVar1 = p_Var2 + 0x10;
    LOCK();
    *(int *)pcVar1 = *(int *)pcVar1 + -1;
    UNLOCK();
    if (*(int *)pcVar1 == 0) {
      p_Var2 = *(_func_void_Node_ptr **)(param_1 + 0x10);
      goto LAB_009035f8;
    }
  }
  QObject::~QObject(param_1);
  return;
}


// ==== entry=0090360e orig=FUN_0090360e size=93 name=SuperAction_dtor_deleting ====

void SuperAction_dtor_deleting(QObject *param_1)

{
  code *pcVar1;
  _func_void_Node_ptr *p_Var2;
  
  *(undefined ***)param_1 = &SuperAction_vtable;
  QJSValue::~QJSValue((QJSValue *)(param_1 + 0x18));
  p_Var2 = *(_func_void_Node_ptr **)(param_1 + 0x10);
  if (*(int *)(p_Var2 + 0x10) != 0) {
    if (*(int *)(p_Var2 + 0x10) == -1) goto LAB_00903643;
    pcVar1 = p_Var2 + 0x10;
    LOCK();
    *(int *)pcVar1 = *(int *)pcVar1 + -1;
    UNLOCK();
    if (*(int *)pcVar1 != 0) goto LAB_00903643;
    p_Var2 = *(_func_void_Node_ptr **)(param_1 + 0x10);
  }
  QHashData::free_helper(p_Var2);
LAB_00903643:
  QObject::~QObject(param_1);
  operator_delete(param_1,0x20);
  return;
}


// ==== entry=0090366c name=FUN_0090366c size=1 ====

void FUN_0090366c(void)

{
  return;
}


// ==== entry=0090366e orig=FUN_0090366e size=24 name=SuperKeymap_metaObject ====

undefined ** SuperKeymap_metaObject(long param_1)

{
  undefined **ppuVar1;
  
  if (*(long *)(*(long *)(param_1 + 8) + 0x28) != 0) {
    ppuVar1 = (undefined **)QObjectData::dynamicMetaObject();
    return ppuVar1;
  }
  return &PTR_staticMetaObject_011a0820;
}


// ==== entry=00903686 orig=FUN_00903686 size=66 name=SuperKeymap_qt_metacast ====

char * SuperKeymap_qt_metacast(char *param_1,char *param_2)

{
  int iVar1;
  char *pcVar2;
  
  if (param_2 == (char *)0x0) {
    return (char *)0x0;
  }
  iVar1 = strcmp(param_2,"SuperKeymap");
  if (iVar1 == 0) {
    return param_1;
  }
  pcVar2 = (char *)QObject::qt_metacast(param_1);
  return pcVar2;
}


// ==== entry=009036c8 orig=FUN_009036c8 size=5 name=SuperKeymap_qt_metacall ====

void QObject::SuperKeymap_qt_metacall(void)

{
  qt_metacall();
  return;
}


// ==== entry=009036d0 orig=FUN_009036d0 size=24 name=SyncInputCenter_metaObject ====

undefined ** SyncInputCenter_metaObject(long param_1)

{
  undefined **ppuVar1;
  
  if (*(long *)(*(long *)(param_1 + 8) + 0x28) != 0) {
    ppuVar1 = (undefined **)QObjectData::dynamicMetaObject();
    return ppuVar1;
  }
  return &PTR_staticMetaObject_011a08e0;
}


// ==== entry=009036e8 name=FUN_009036e8 size=55 ====

void FUN_009036e8(QObject *param_1,undefined8 param_2)

{
  undefined8 local_20;
  void *local_18;
  undefined8 *local_10;
  
  local_18 = (void *)0x0;
  local_10 = &local_20;
  local_20 = param_2;
  QMetaObject::activate(param_1,(QMetaObject *)&PTR_staticMetaObject_011a08e0,1,&local_18);
  return;
}


// ==== entry=00903720 name=FUN_00903720 size=66 ====

void FUN_00903720(QObject *param_1,undefined8 param_2,undefined4 param_3)

{
  undefined4 local_34;
  undefined8 local_30;
  void *local_28;
  undefined8 *local_20;
  undefined4 *local_18;
  
  local_28 = (void *)0x0;
  local_20 = &local_30;
  local_18 = &local_34;
  local_34 = param_3;
  local_30 = param_2;
  QMetaObject::activate(param_1,(QMetaObject *)&PTR_staticMetaObject_011a08e0,0,&local_28);
  return;
}


// ==== entry=00903762 name=FUN_00903762 size=69 ====

void FUN_00903762(QObject *param_1,undefined8 param_2,undefined1 param_3)

{
  undefined1 local_34 [4];
  undefined8 local_30;
  void *local_28;
  undefined8 *local_20;
  undefined1 *local_18;
  
  local_28 = (void *)0x0;
  local_20 = &local_30;
  local_18 = local_34;
  local_34[0] = param_3;
  local_30 = param_2;
  QMetaObject::activate(param_1,(QMetaObject *)&PTR_staticMetaObject_011a08e0,2,&local_28);
  return;
}


// ==== entry=009037a8 name=FUN_009037a8 size=158 ====

void FUN_009037a8(undefined8 param_1,int param_2,int param_3,undefined8 *param_4)

{
  undefined4 *puVar1;
  long *plVar2;
  code *pcVar3;
  
  if (param_2 == 0) {
    if (param_3 == 1) {
      FUN_009036e8(param_1,*(undefined8 *)param_4[1]);
      return;
    }
    if (param_3 == 2) {
      FUN_00903762(param_1,*(undefined8 *)param_4[1],*(undefined1 *)param_4[2]);
      return;
    }
    if (param_3 == 0) {
      FUN_00903720(param_1,*(undefined8 *)param_4[1],*(undefined4 *)param_4[2]);
      return;
    }
  }
  else if (param_2 == 10) {
    puVar1 = (undefined4 *)*param_4;
    plVar2 = (long *)param_4[1];
    pcVar3 = (code *)*plVar2;
    if ((pcVar3 == FUN_00903720) && (plVar2[1] == 0)) {
      *puVar1 = 0;
      return;
    }
    if ((pcVar3 == FUN_009036e8) && (plVar2[1] == 0)) {
      *puVar1 = 1;
      return;
    }
    if ((pcVar3 == FUN_00903762) && (plVar2[1] == 0)) {
      *puVar1 = 2;
      return;
    }
  }
  return;
}


// ==== entry=00903846 orig=FUN_00903846 size=66 name=SyncInputCenter_qt_metacast ====

char * SyncInputCenter_qt_metacast(char *param_1,char *param_2)

{
  int iVar1;
  char *pcVar2;
  
  if (param_2 == (char *)0x0) {
    return (char *)0x0;
  }
  iVar1 = strcmp(param_2,"SyncInputCenter");
  if (iVar1 == 0) {
    return param_1;
  }
  pcVar2 = (char *)QObject::qt_metacast(param_1);
  return pcVar2;
}


// ==== entry=00903888 orig=FUN_00903888 size=93 name=SyncInputCenter_qt_metacall ====

ulong SyncInputCenter_qt_metacall
                (undefined8 param_1,int param_2,undefined8 param_3,undefined8 *param_4)

{
  int iVar1;
  ulong uVar2;
  
  uVar2 = QObject::qt_metacall();
  iVar1 = (int)uVar2;
  if (-1 < iVar1) {
    if (param_2 == 0) {
      if (iVar1 < 3) {
        FUN_009037a8(param_1,0,uVar2 & 0xffffffff,param_4);
        uVar2 = uVar2 & 0xffffffff;
      }
    }
    else {
      if (param_2 != 0xc) {
        return uVar2;
      }
      if (iVar1 < 3) {
        *(undefined4 *)*param_4 = 0xffffffff;
      }
    }
    uVar2 = (ulong)((int)uVar2 - 3);
  }
  return uVar2;
}


// ==== entry=009038e6 orig=FUN_009038e6 size=140 name=SyncInputCenter_dtor_deleting ====

void SyncInputCenter_dtor_deleting(QObject *param_1)

{
  int iVar1;
  void *pvVar2;
  int *piVar3;
  void *pvVar4;
  
  *(undefined ***)param_1 = &SyncInputCenter_vtable;
  pvVar2 = *(void **)(param_1 + 0x20);
  pvVar4 = *(void **)(param_1 + 0x18);
  if (pvVar2 != pvVar4) {
    do {
      piVar3 = *(int **)((long)pvVar4 + 8);
      if (piVar3 != (int *)0x0) {
        LOCK();
        iVar1 = *piVar3;
        *piVar3 = *piVar3 + -1;
        UNLOCK();
        if ((iVar1 == 1) && (*(void **)((long)pvVar4 + 8) != (void *)0x0)) {
          operator_delete(*(void **)((long)pvVar4 + 8));
        }
      }
      pvVar4 = (void *)((long)pvVar4 + 0x20);
    } while (pvVar2 != pvVar4);
    pvVar4 = *(void **)(param_1 + 0x18);
  }
  if (pvVar4 != (void *)0x0) {
    operator_delete(pvVar4);
  }
  QObject::~QObject(param_1);
  operator_delete(param_1,0x30);
  return;
}


// ==== entry=00903972 orig=FUN_00903972 size=127 name=SyncInputCenter_dtor ====

void SyncInputCenter_dtor(QObject *param_1)

{
  int iVar1;
  void *pvVar2;
  int *piVar3;
  void *pvVar4;
  
  *(undefined ***)param_1 = &SyncInputCenter_vtable;
  pvVar2 = *(void **)(param_1 + 0x20);
  pvVar4 = *(void **)(param_1 + 0x18);
  if (pvVar2 != pvVar4) {
    do {
      piVar3 = *(int **)((long)pvVar4 + 8);
      if (piVar3 != (int *)0x0) {
        LOCK();
        iVar1 = *piVar3;
        *piVar3 = *piVar3 + -1;
        UNLOCK();
        if ((iVar1 == 1) && (*(void **)((long)pvVar4 + 8) != (void *)0x0)) {
          operator_delete(*(void **)((long)pvVar4 + 8));
        }
      }
      pvVar4 = (void *)((long)pvVar4 + 0x20);
    } while (pvVar2 != pvVar4);
    pvVar4 = *(void **)(param_1 + 0x18);
  }
  if (pvVar4 != (void *)0x0) {
    operator_delete(pvVar4);
  }
  QObject::~QObject(param_1);
  return;
}


// ==== entry=00903a00 orig=FUN_00903a00 size=24 name=TriggerCenter_metaObject ====

undefined ** TriggerCenter_metaObject(long param_1)

{
  undefined **ppuVar1;
  
  if (*(long *)(*(long *)(param_1 + 8) + 0x28) != 0) {
    ppuVar1 = (undefined **)QObjectData::dynamicMetaObject();
    return ppuVar1;
  }
  return &PTR_staticMetaObject_011a09a0;
}


// ==== entry=00903a18 name=FUN_00903a18 size=16 ====

void FUN_00903a18(QObject *param_1)

{
  QMetaObject::activate(param_1,(QMetaObject *)&PTR_staticMetaObject_011a09a0,0,(void **)0x0);
  return;
}


// ==== entry=00903a28 name=FUN_00903a28 size=52 ====

void FUN_00903a28(undefined8 param_1,int param_2,int param_3,undefined8 *param_4)

{
  if (param_2 == 0) {
    if (param_3 == 0) {
      FUN_00903a18();
      return;
    }
  }
  else if (((param_2 == 10) && (*(code **)param_4[1] == FUN_00903a18)) &&
          (((long *)param_4[1])[1] == 0)) {
    *(undefined4 *)*param_4 = 0;
    return;
  }
  return;
}


// ==== entry=00903a5c name=FUN_00903a5c size=358 ====

void FUN_00903a5c(void)

{
  long lVar1;
  long *in_FS_OFFSET;
  
  if (*(char *)(*in_FS_OFFSET + -0xfe) == '\0') {
    *(undefined1 *)(*in_FS_OFFSET + -0xfe) = 1;
    if (*(char *)(*in_FS_OFFSET + -0x138) == '\0') {
      *(char *)(*in_FS_OFFSET + -0x138) = '\x01';
      lVar1 = *in_FS_OFFSET;
      *(undefined8 *)(lVar1 + -0x110) = &QMapDataBase::shared_null;
      __cxa_thread_atexit(FUN_00558fe0,(undefined8 *)(lVar1 + -0x110),&DAT_00c89008);
    }
    if (*(char *)(*in_FS_OFFSET + -0x140) == '\0') {
      *(char *)(*in_FS_OFFSET + -0x140) = '\x01';
      lVar1 = *in_FS_OFFSET;
      *(undefined8 *)(lVar1 + -0x120) = &QMapDataBase::shared_null;
      __cxa_thread_atexit(FUN_005594f0,(undefined8 *)(lVar1 + -0x120),&DAT_00c89008);
    }
    if (*(char *)(*in_FS_OFFSET + -0x148) == '\0') {
      *(char *)(*in_FS_OFFSET + -0x148) = '\x01';
      lVar1 = *in_FS_OFFSET;
      *(undefined8 *)(lVar1 + -0x118) = &QMapDataBase::shared_null;
      __cxa_thread_atexit(FUN_00559a00,(undefined8 *)(lVar1 + -0x118),&DAT_00c89008);
    }
    if (*(char *)(*in_FS_OFFSET + -0x150) == '\0') {
      *(char *)(*in_FS_OFFSET + -0x150) = '\x01';
      lVar1 = *in_FS_OFFSET;
      *(undefined8 *)(lVar1 + -0x128) = &QMapDataBase::shared_null;
      __cxa_thread_atexit(FUN_00559f10,(undefined8 *)(lVar1 + -0x128),&DAT_00c89008);
      return;
    }
  }
  return;
}


// ==== entry=00903bc2 orig=FUN_00903bc2 size=66 name=TriggerCenter_qt_metacast ====

char * TriggerCenter_qt_metacast(char *param_1,char *param_2)

{
  int iVar1;
  char *pcVar2;
  
  if (param_2 == (char *)0x0) {
    return (char *)0x0;
  }
  iVar1 = strcmp(param_2,"TriggerCenter");
  if (iVar1 == 0) {
    return param_1;
  }
  pcVar2 = (char *)QObject::qt_metacast(param_1);
  return pcVar2;
}


// ==== entry=00903c04 orig=FUN_00903c04 size=84 name=TriggerCenter_qt_metacall ====

ulong TriggerCenter_qt_metacall
                (undefined8 param_1,int param_2,undefined8 param_3,undefined8 *param_4)

{
  int iVar1;
  ulong uVar2;
  
  uVar2 = QObject::qt_metacall();
  iVar1 = (int)uVar2;
  if (-1 < iVar1) {
    if (param_2 == 0) {
      if (iVar1 == 0) {
        FUN_00903a18(param_1);
        uVar2 = uVar2 & 0xffffffff;
      }
    }
    else {
      if (param_2 != 0xc) {
        return uVar2;
      }
      if (iVar1 == 0) {
        *(undefined4 *)*param_4 = 0xffffffff;
      }
    }
    uVar2 = (ulong)((int)uVar2 - 1);
  }
  return uVar2;
}


// ==== entry=00903c60 orig=FUN_00903c60 size=24 name=TunnelCenter_metaObject ====

undefined ** TunnelCenter_metaObject(long param_1)

{
  undefined **ppuVar1;
  
  if (*(long *)(*(long *)(param_1 + 8) + 0x28) != 0) {
    ppuVar1 = (undefined **)QObjectData::dynamicMetaObject();
    return ppuVar1;
  }
  return &PTR_staticMetaObject_011a0a60;
}


// ==== entry=00903c78 name=FUN_00903c78 size=19 ====

void FUN_00903c78(QObject *param_1)

{
  QMetaObject::activate(param_1,(QMetaObject *)&PTR_staticMetaObject_011a0a60,1,(void **)0x0);
  return;
}


// ==== entry=00903c8c name=FUN_00903c8c size=47 ====

void FUN_00903c8c(QObject *param_1,undefined8 param_2,undefined8 param_3)

{
  void *local_28;
  undefined8 local_20;
  undefined8 local_18;
  
  local_28 = (void *)0x0;
  local_20 = param_2;
  local_18 = param_3;
  QMetaObject::activate(param_1,(QMetaObject *)&PTR_staticMetaObject_011a0a60,2,&local_28);
  return;
}


// ==== entry=00903cbc name=FUN_00903cbc size=42 ====

void FUN_00903cbc(QObject *param_1,undefined8 param_2)

{
  void *local_18;
  undefined8 local_10;
  
  local_18 = (void *)0x0;
  local_10 = param_2;
  QMetaObject::activate(param_1,(QMetaObject *)&PTR_staticMetaObject_011a0a60,5,&local_18);
  return;
}


// ==== entry=00903ce6 name=FUN_00903ce6 size=61 ====

void FUN_00903ce6(QObject *param_1,undefined8 param_2,undefined4 param_3,undefined8 param_4)

{
  undefined4 local_2c;
  void *local_28;
  undefined8 local_20;
  undefined4 *local_18;
  undefined8 local_10;
  
  local_28 = (void *)0x0;
  local_18 = &local_2c;
  local_2c = param_3;
  local_20 = param_2;
  local_10 = param_4;
  QMetaObject::activate(param_1,(QMetaObject *)&PTR_staticMetaObject_011a0a60,0,&local_28);
  return;
}


// ==== entry=00903d24 name=FUN_00903d24 size=60 ====

void FUN_00903d24(QObject *param_1,undefined8 param_2,undefined8 param_3)

{
  undefined8 local_30;
  void *local_28;
  undefined8 local_20;
  undefined8 *local_18;
  
  local_28 = (void *)0x0;
  local_18 = &local_30;
  local_30 = param_3;
  local_20 = param_2;
  QMetaObject::activate(param_1,(QMetaObject *)&PTR_staticMetaObject_011a0a60,3,&local_28);
  return;
}


// ==== entry=00903d60 name=FUN_00903d60 size=59 ====

void FUN_00903d60(QObject *param_1,undefined8 param_2,undefined1 param_3)

{
  undefined1 local_2c [4];
  void *local_28;
  undefined8 local_20;
  undefined1 *local_18;
  
  local_28 = (void *)0x0;
  local_18 = local_2c;
  local_2c[0] = param_3;
  local_20 = param_2;
  QMetaObject::activate(param_1,(QMetaObject *)&PTR_staticMetaObject_011a0a60,4,&local_28);
  return;
}


// ==== entry=00903d9c name=FUN_00903d9c size=301 ====

void FUN_00903d9c(undefined8 param_1,int param_2,undefined4 param_3,undefined8 *param_4)

{
  undefined4 *puVar1;
  long *plVar2;
  code *pcVar3;
  
  if (param_2 == 0) {
    switch(param_3) {
    case 0:
      FUN_00903ce6(param_1,param_4[1],*(undefined4 *)param_4[2],param_4[3]);
      return;
    case 1:
      FUN_00903c78();
      return;
    case 2:
      FUN_00903c8c(param_1,param_4[1],param_4[2]);
      return;
    case 3:
      FUN_00903d24(param_1,param_4[1],*(undefined8 *)param_4[2]);
      return;
    case 4:
      FUN_00903d60(param_1,param_4[1],*(undefined1 *)param_4[2]);
      return;
    case 5:
      FUN_00903cbc(param_1,param_4[1]);
      return;
    }
  }
  else if (param_2 == 10) {
    puVar1 = (undefined4 *)*param_4;
    plVar2 = (long *)param_4[1];
    pcVar3 = (code *)*plVar2;
    if ((pcVar3 == FUN_00903ce6) && (plVar2[1] == 0)) {
      *puVar1 = 0;
      return;
    }
    if ((pcVar3 == FUN_00903c78) && (plVar2[1] == 0)) {
      *puVar1 = 1;
      return;
    }
    if ((pcVar3 == FUN_00903c8c) && (plVar2[1] == 0)) {
      *puVar1 = 2;
      return;
    }
    if ((pcVar3 == FUN_00903d24) && (plVar2[1] == 0)) {
      *puVar1 = 3;
      return;
    }
    if ((pcVar3 == FUN_00903d60) && (plVar2[1] == 0)) {
      *puVar1 = 4;
      return;
    }
    if ((pcVar3 == FUN_00903cbc) && (plVar2[1] == 0)) {
      *puVar1 = 5;
    }
  }
  return;
}


// ==== entry=00903eca orig=FUN_00903eca size=66 name=TunnelCenter_qt_metacast ====

char * TunnelCenter_qt_metacast(char *param_1,char *param_2)

{
  int iVar1;
  char *pcVar2;
  
  if (param_2 == (char *)0x0) {
    return (char *)0x0;
  }
  iVar1 = strcmp(param_2,"TunnelCenter");
  if (iVar1 == 0) {
    return param_1;
  }
  pcVar2 = (char *)QObject::qt_metacast(param_1);
  return pcVar2;
}


// ==== entry=00903f0c orig=FUN_00903f0c size=97 name=TunnelCenter_qt_metacall ====

ulong TunnelCenter_qt_metacall
                (undefined8 param_1,int param_2,undefined8 param_3,undefined8 *param_4)

{
  int iVar1;
  ulong uVar2;
  
  uVar2 = QObject::qt_metacall();
  iVar1 = (int)uVar2;
  if (-1 < iVar1) {
    if (param_2 == 0) {
      if (iVar1 < 6) {
        FUN_00903d9c(param_1,0,uVar2 & 0xffffffff,param_4);
        uVar2 = uVar2 & 0xffffffff;
      }
    }
    else {
      if (param_2 != 0xc) {
        return uVar2;
      }
      if (iVar1 < 6) {
        *(undefined4 *)*param_4 = 0xffffffff;
      }
    }
    uVar2 = (ulong)((int)uVar2 - 6);
  }
  return uVar2;
}


// ==== entry=00903f6e name=FUN_00903f6e size=1 ====

void FUN_00903f6e(void)

{
  return;
}


// ==== entry=00903f70 orig=FUN_00903f70 size=24 name=UuidCenter_metaObject ====

undefined ** UuidCenter_metaObject(long param_1)

{
  undefined **ppuVar1;
  
  if (*(long *)(*(long *)(param_1 + 8) + 0x28) != 0) {
    ppuVar1 = (undefined **)QObjectData::dynamicMetaObject();
    return ppuVar1;
  }
  return &PTR_staticMetaObject_011a0b20;
}


// ==== entry=00903f88 orig=FUN_00903f88 size=66 name=UuidCenter_qt_metacast ====

char * UuidCenter_qt_metacast(char *param_1,char *param_2)

{
  int iVar1;
  char *pcVar2;
  
  if (param_2 == (char *)0x0) {
    return (char *)0x0;
  }
  iVar1 = strcmp(param_2,"UuidCenter");
  if (iVar1 == 0) {
    return param_1;
  }
  pcVar2 = (char *)QObject::qt_metacast(param_1);
  return pcVar2;
}


// ==== entry=00903fca orig=FUN_00903fca size=5 name=UuidCenter_qt_metacall ====

void QObject::UuidCenter_qt_metacall(void)

{
  qt_metacall();
  return;
}


// ==== entry=00903fd0 orig=FUN_00903fd0 size=118 name=UuidCenter_dtor_deleting ====

void UuidCenter_dtor_deleting(QObject *param_1)

{
  QMapNodeBase *pQVar1;
  
  *(undefined ***)param_1 = &UuidCenter_vtable;
  pQVar1 = *(QMapNodeBase **)(param_1 + 0x18);
  if (*(int *)pQVar1 != 0) {
    if (*(int *)pQVar1 == -1) goto LAB_00903ffe;
    LOCK();
    *(int *)pQVar1 = *(int *)pQVar1 + -1;
    UNLOCK();
    if (*(int *)pQVar1 != 0) goto LAB_00903ffe;
    pQVar1 = *(QMapNodeBase **)(param_1 + 0x18);
  }
  if (*(long *)(pQVar1 + 0x10) != 0) {
    FUN_0052ffc6();
    QMapDataBase::freeTree(pQVar1,(int)*(undefined8 *)(pQVar1 + 0x10));
  }
  QMapDataBase::freeData((QMapDataBase *)pQVar1);
LAB_00903ffe:
  QObject::~QObject(param_1);
  operator_delete(param_1,0x20);
  return;
}


// ==== entry=00904046 orig=FUN_00904046 size=115 name=UuidCenter_dtor ====

void UuidCenter_dtor(QObject *param_1)

{
  QMapNodeBase *pQVar1;
  
  *(undefined ***)param_1 = &UuidCenter_vtable;
  pQVar1 = *(QMapNodeBase **)(param_1 + 0x18);
  if (*(int *)pQVar1 == 0) {
LAB_00904084:
    if (*(long *)(pQVar1 + 0x10) != 0) {
      FUN_0052ffc6();
      QMapDataBase::freeTree(pQVar1,(int)*(undefined8 *)(pQVar1 + 0x10));
    }
    QMapDataBase::freeData((QMapDataBase *)pQVar1);
    QObject::~QObject(param_1);
    return;
  }
  if (*(int *)pQVar1 != -1) {
    LOCK();
    *(int *)pQVar1 = *(int *)pQVar1 + -1;
    UNLOCK();
    if (*(int *)pQVar1 == 0) {
      pQVar1 = *(QMapNodeBase **)(param_1 + 0x18);
      goto LAB_00904084;
    }
  }
  QObject::~QObject(param_1);
  return;
}


// ==== entry=009040c0 orig=FUN_009040c0 size=24 name=XServerCenter_metaObject ====

undefined ** XServerCenter_metaObject(long param_1)

{
  undefined **ppuVar1;
  
  if (*(long *)(*(long *)(param_1 + 8) + 0x28) != 0) {
    ppuVar1 = (undefined **)QObjectData::dynamicMetaObject();
    return ppuVar1;
  }
  return &PTR_staticMetaObject_011a0be0;
}


// ==== entry=009040d8 name=FUN_009040d8 size=39 ====

void FUN_009040d8(QObject *param_1,undefined8 param_2)

{
  void *local_18;
  undefined8 local_10;
  
  local_18 = (void *)0x0;
  local_10 = param_2;
  QMetaObject::activate(param_1,(QMetaObject *)&PTR_staticMetaObject_011a0be0,0,&local_18);
  return;
}


// ==== entry=00904100 name=FUN_00904100 size=54 ====

void FUN_00904100(QObject *param_1,undefined4 param_2)

{
  undefined4 local_1c;
  void *local_18;
  undefined4 *local_10;
  
  local_18 = (void *)0x0;
  local_10 = &local_1c;
  local_1c = param_2;
  QMetaObject::activate(param_1,(QMetaObject *)&PTR_staticMetaObject_011a0be0,1,&local_18);
  return;
}


// ==== entry=00904136 name=FUN_00904136 size=96 ====

void FUN_00904136(undefined8 param_1,int param_2,int param_3,undefined8 *param_4)

{
  long *plVar1;
  
  if (param_2 == 0) {
    if (param_3 == 0) {
      FUN_009040d8(param_1,param_4[1]);
      return;
    }
    if (param_3 == 1) {
      FUN_00904100(param_1,*(undefined4 *)param_4[1]);
      return;
    }
    return;
  }
  if (param_2 == 10) {
    plVar1 = (long *)param_4[1];
    if (((code *)*plVar1 == FUN_009040d8) && (plVar1[1] == 0)) {
      *(undefined4 *)*param_4 = 0;
      return;
    }
    if (((code *)*plVar1 == FUN_00904100) && (plVar1[1] == 0)) {
      *(undefined4 *)*param_4 = 1;
      return;
    }
  }
  return;
}


// ==== entry=00904196 orig=FUN_00904196 size=66 name=XServerCenter_qt_metacast ====

char * XServerCenter_qt_metacast(char *param_1,char *param_2)

{
  int iVar1;
  char *pcVar2;
  
  if (param_2 == (char *)0x0) {
    return (char *)0x0;
  }
  iVar1 = strcmp(param_2,"XServerCenter");
  if (iVar1 == 0) {
    return param_1;
  }
  pcVar2 = (char *)QObject::qt_metacast(param_1);
  return pcVar2;
}


// ==== entry=009041d8 orig=FUN_009041d8 size=93 name=XServerCenter_qt_metacall ====

ulong XServerCenter_qt_metacall
                (undefined8 param_1,int param_2,undefined8 param_3,undefined8 *param_4)

{
  int iVar1;
  ulong uVar2;
  
  uVar2 = QObject::qt_metacall();
  iVar1 = (int)uVar2;
  if (-1 < iVar1) {
    if (param_2 == 0) {
      if (iVar1 < 2) {
        FUN_00904136(param_1,0,uVar2 & 0xffffffff,param_4);
        uVar2 = uVar2 & 0xffffffff;
      }
    }
    else {
      if (param_2 != 0xc) {
        return uVar2;
      }
      if (iVar1 < 2) {
        *(undefined4 *)*param_4 = 0xffffffff;
      }
    }
    uVar2 = (ulong)((int)uVar2 - 2);
  }
  return uVar2;
}


// ==== entry=00904240 orig=FUN_00904240 size=165 name=XServerCenter_dtor ====

/* WARNING: Removing unreachable block (ram,0x00904285) */
/* WARNING: Removing unreachable block (ram,0x009042cf) */

void XServerCenter_dtor(QObject *param_1)

{
  long *plVar1;
  int *piVar2;
  int iVar3;
  long *plVar4;
  code *pcVar5;
  long lVar6;
  
  *(undefined ***)param_1 = &XServerCenter_vtable;
  plVar4 = *(long **)(param_1 + 0x18);
  if (plVar4 != (long *)0x0) {
    LOCK();
    plVar1 = plVar4 + 1;
    lVar6 = *plVar1;
    *(int *)plVar1 = (int)*plVar1 + -1;
    UNLOCK();
    if ((int)lVar6 == 1) {
      if (*(code **)(*plVar4 + 0x10) != FUN_00575d12) {
        (**(code **)(*plVar4 + 0x10))(plVar4);
      }
      LOCK();
      piVar2 = (int *)((long)plVar4 + 0xc);
      iVar3 = *piVar2;
      *piVar2 = *piVar2 + -1;
      UNLOCK();
      if (iVar3 == 1) {
        pcVar5 = *(code **)(*plVar4 + 0x18);
        if (pcVar5 == std::_Sp_counted_base<(__gnu_cxx::_Lock_policy)2>::_M_destroy) {
          (**(code **)(*plVar4 + 8))();
        }
        else {
          (*pcVar5)(plVar4);
        }
      }
    }
  }
  QObject::~QObject(param_1);
  return;
}


// ==== entry=009042f0 orig=FUN_009042f0 size=180 name=XServerCenter_dtor_deleting ====

/* WARNING: Removing unreachable block (ram,0x00904342) */
/* WARNING: Removing unreachable block (ram,0x0090438e) */

void XServerCenter_dtor_deleting(QObject *param_1)

{
  long *plVar1;
  int *piVar2;
  int iVar3;
  long *plVar4;
  code *pcVar5;
  long lVar6;
  
  *(undefined ***)param_1 = &XServerCenter_vtable;
  plVar4 = *(long **)(param_1 + 0x18);
  if (plVar4 != (long *)0x0) {
    LOCK();
    plVar1 = plVar4 + 1;
    lVar6 = *plVar1;
    *(int *)plVar1 = (int)*plVar1 + -1;
    UNLOCK();
    if ((int)lVar6 == 1) {
      if (*(code **)(*plVar4 + 0x10) != FUN_00575d12) {
        (**(code **)(*plVar4 + 0x10))(plVar4);
      }
      LOCK();
      piVar2 = (int *)((long)plVar4 + 0xc);
      iVar3 = *piVar2;
      *piVar2 = *piVar2 + -1;
      UNLOCK();
      if (iVar3 == 1) {
        pcVar5 = *(code **)(*plVar4 + 0x18);
        if (pcVar5 == std::_Sp_counted_base<(__gnu_cxx::_Lock_policy)2>::_M_destroy) {
          (**(code **)(*plVar4 + 8))();
        }
        else {
          (*pcVar5)(plVar4);
        }
      }
    }
  }
  QObject::~QObject(param_1);
  operator_delete(param_1,0x28);
  return;
}


// ==== entry=009043a4 name=FUN_009043a4 size=1 ====

void FUN_009043a4(void)

{
  return;
}


// ==== entry=009043a6 orig=FUN_009043a6 size=24 name=HighlightTextDialog_metaObject ====

undefined ** HighlightTextDialog_metaObject(long param_1)

{
  undefined **ppuVar1;
  
  if (*(long *)(*(long *)(param_1 + 8) + 0x28) != 0) {
    ppuVar1 = (undefined **)QObjectData::dynamicMetaObject();
    return ppuVar1;
  }
  return &PTR_staticMetaObject_011a0e60;
}


// ==== entry=009043be orig=FUN_009043be size=66 name=HighlightTextDialog_qt_metacast ====

char * HighlightTextDialog_qt_metacast(char *param_1,char *param_2)

{
  int iVar1;
  char *pcVar2;
  
  if (param_2 == (char *)0x0) {
    return (char *)0x0;
  }
  iVar1 = strcmp(param_2,"HighlightTextDialog");
  if (iVar1 == 0) {
    return param_1;
  }
  pcVar2 = (char *)QDialog::qt_metacast(param_1);
  return pcVar2;
}


// ==== entry=00904400 orig=FUN_00904400 size=5 name=HighlightTextDialog_qt_metacall ====

void QDialog::HighlightTextDialog_qt_metacall(void)

{
  qt_metacall();
  return;
}


// ==== entry=00904406 orig=FUN_00904406 size=29 name=HighlightTextDialog_dtor ====

void HighlightTextDialog_dtor(QDialog *param_1)

{
  *(undefined ***)param_1 = &HighlightTextDialog_vtable;
  *(undefined ***)(param_1 + 0x10) = &PTR_FUN_011a0e10;
  QDialog::~QDialog(param_1);
  return;
}


// ==== entry=00904423 name=FUN_00904423 size=33 ====

void FUN_00904423(undefined8 *param_1)

{
  param_1[-2] = &HighlightTextDialog_vtable;
  *param_1 = &PTR_FUN_011a0e10;
  QDialog::~QDialog((QDialog *)(param_1 + -2));
  return;
}


// ==== entry=00904444 orig=FUN_00904444 size=47 name=HighlightTextDialog_dtor_deleting ====

void HighlightTextDialog_dtor_deleting(QDialog *param_1)

{
  *(undefined ***)param_1 = &HighlightTextDialog_vtable;
  *(undefined ***)(param_1 + 0x10) = &PTR_FUN_011a0e10;
  QDialog::~QDialog(param_1);
  operator_delete(param_1,0x40);
  return;
}


// ==== entry=00904473 name=FUN_00904473 size=51 ====

void FUN_00904473(undefined8 *param_1)

{
  param_1[-2] = &HighlightTextDialog_vtable;
  *param_1 = &PTR_FUN_011a0e10;
  QDialog::~QDialog((QDialog *)(param_1 + -2));
  operator_delete((QDialog *)(param_1 + -2),0x40);
  return;
}


// ==== entry=009044a6 name=FUN_009044a6 size=1 ====

void FUN_009044a6(void)

{
  return;
}


// ==== entry=009044a8 orig=FUN_009044a8 size=24 name=MasterPasswordDialog_metaObject ====

undefined ** MasterPasswordDialog_metaObject(long param_1)

{
  undefined **ppuVar1;
  
  if (*(long *)(*(long *)(param_1 + 8) + 0x28) != 0) {
    ppuVar1 = (undefined **)QObjectData::dynamicMetaObject();
    return ppuVar1;
  }
  return &PTR_staticMetaObject_011a10e0;
}


// ==== entry=009044c0 orig=FUN_009044c0 size=66 name=MasterPasswordDialog_qt_metacast ====

char * MasterPasswordDialog_qt_metacast(char *param_1,char *param_2)

{
  int iVar1;
  char *pcVar2;
  
  if (param_2 == (char *)0x0) {
    return (char *)0x0;
  }
  iVar1 = strcmp(param_2,"MasterPasswordDialog");
  if (iVar1 == 0) {
    return param_1;
  }
  pcVar2 = (char *)QDialog::qt_metacast(param_1);
  return pcVar2;
}


// ==== entry=00904502 orig=FUN_00904502 size=5 name=MasterPasswordDialog_qt_metacall ====

void QDialog::MasterPasswordDialog_qt_metacall(void)

{
  qt_metacall();
  return;
}


// ==== entry=00904508 orig=FUN_00904508 size=29 name=MasterPasswordDialog_dtor ====

void MasterPasswordDialog_dtor(QDialog *param_1)

{
  *(undefined ***)param_1 = &MasterPasswordDialog_vtable;
  *(undefined ***)(param_1 + 0x10) = &PTR_FUN_011a1090;
  QDialog::~QDialog(param_1);
  return;
}


// ==== entry=00904525 name=FUN_00904525 size=33 ====

void FUN_00904525(undefined8 *param_1)

{
  param_1[-2] = &MasterPasswordDialog_vtable;
  *param_1 = &PTR_FUN_011a1090;
  QDialog::~QDialog((QDialog *)(param_1 + -2));
  return;
}


// ==== entry=00904546 orig=FUN_00904546 size=47 name=MasterPasswordDialog_dtor_deleting ====

void MasterPasswordDialog_dtor_deleting(QDialog *param_1)

{
  *(undefined ***)param_1 = &MasterPasswordDialog_vtable;
  *(undefined ***)(param_1 + 0x10) = &PTR_FUN_011a1090;
  QDialog::~QDialog(param_1);
  operator_delete(param_1,0x68);
  return;
}


// ==== entry=00904575 name=FUN_00904575 size=51 ====

void FUN_00904575(undefined8 *param_1)

{
  param_1[-2] = &MasterPasswordDialog_vtable;
  *param_1 = &PTR_FUN_011a1090;
  QDialog::~QDialog((QDialog *)(param_1 + -2));
  operator_delete((QDialog *)(param_1 + -2),0x68);
  return;
}


// ==== entry=009045a8 name=FUN_009045a8 size=1 ====

void FUN_009045a8(void)

{
  return;
}


// ==== entry=009045aa orig=FUN_009045aa size=24 name=ModemFileDialog_metaObject ====

undefined ** ModemFileDialog_metaObject(long param_1)

{
  undefined **ppuVar1;
  
  if (*(long *)(*(long *)(param_1 + 8) + 0x28) != 0) {
    ppuVar1 = (undefined **)QObjectData::dynamicMetaObject();
    return ppuVar1;
  }
  return &PTR_PTR_011a1360;
}


// ==== entry=009045c2 orig=FUN_009045c2 size=66 name=ModemFileDialog_qt_metacast ====

undefined8 ModemFileDialog_qt_metacast(undefined8 param_1,char *param_2)

{
  int iVar1;
  undefined8 uVar2;
  
  if (param_2 == (char *)0x0) {
    return 0;
  }
  iVar1 = strcmp(param_2,"ModemFileDialog");
  if (iVar1 == 0) {
    return param_1;
  }
  uVar2 = FileDialog_qt_metacast(param_1,param_2);
  return uVar2;
}


// ==== entry=00904604 orig=FUN_00904604 size=5 name=ModemFileDialog_qt_metacall ====

void QFileDialog::ModemFileDialog_qt_metacall(void)

{
  qt_metacall();
  return;
}


// ==== entry=0090460a name=FUN_0090460a size=88 ====

void FUN_0090460a(undefined8 *param_1)

{
  QArrayData *pQVar1;
  
  param_1[-2] = &FileDialog_vtable;
  *param_1 = &PTR_FUN_0119cc50;
  pQVar1 = (QArrayData *)param_1[4];
  if (*(int *)pQVar1 == 0) {
LAB_00904649:
    QArrayData::deallocate(pQVar1,1,8);
    QFileDialog::~QFileDialog((QFileDialog *)(param_1 + -2));
    return;
  }
  if (*(int *)pQVar1 != -1) {
    LOCK();
    *(int *)pQVar1 = *(int *)pQVar1 + -1;
    UNLOCK();
    if (*(int *)pQVar1 == 0) {
      pQVar1 = (QArrayData *)param_1[4];
      goto LAB_00904649;
    }
  }
  QFileDialog::~QFileDialog((QFileDialog *)(param_1 + -2));
  return;
}


// ==== entry=00904662 orig=FUN_00904662 size=86 name=ModemFileDialog_dtor ====

void ModemFileDialog_dtor(QFileDialog *param_1)

{
  QArrayData *pQVar1;
  
  *(undefined ***)param_1 = &FileDialog_vtable;
  *(undefined ***)(param_1 + 0x10) = &PTR_FUN_0119cc50;
  pQVar1 = *(QArrayData **)(param_1 + 0x30);
  if (*(int *)pQVar1 == 0) {
LAB_009046a0:
    QArrayData::deallocate(pQVar1,1,8);
    QFileDialog::~QFileDialog(param_1);
    return;
  }
  if (*(int *)pQVar1 != -1) {
    LOCK();
    *(int *)pQVar1 = *(int *)pQVar1 + -1;
    UNLOCK();
    if (*(int *)pQVar1 == 0) {
      pQVar1 = *(QArrayData **)(param_1 + 0x30);
      goto LAB_009046a0;
    }
  }
  QFileDialog::~QFileDialog(param_1);
  return;
}


// ==== entry=009046b8 name=FUN_009046b8 size=96 ====

void FUN_009046b8(undefined8 *param_1)

{
  QArrayData *pQVar1;
  
  param_1[-2] = &FileDialog_vtable;
  *param_1 = &PTR_FUN_0119cc50;
  pQVar1 = (QArrayData *)param_1[4];
  if (*(int *)pQVar1 != 0) {
    if (*(int *)pQVar1 == -1) goto LAB_009046ea;
    LOCK();
    *(int *)pQVar1 = *(int *)pQVar1 + -1;
    UNLOCK();
    if (*(int *)pQVar1 != 0) goto LAB_009046ea;
    pQVar1 = (QArrayData *)param_1[4];
  }
  QArrayData::deallocate(pQVar1,1,8);
LAB_009046ea:
  QFileDialog::~QFileDialog((QFileDialog *)(param_1 + -2));
  operator_delete((QFileDialog *)(param_1 + -2),0x68);
  return;
}


// ==== entry=00904718 orig=FUN_00904718 size=92 name=ModemFileDialog_dtor_deleting ====

void ModemFileDialog_dtor_deleting(QFileDialog *param_1)

{
  QArrayData *pQVar1;
  
  *(undefined ***)param_1 = &FileDialog_vtable;
  *(undefined ***)(param_1 + 0x10) = &PTR_FUN_0119cc50;
  pQVar1 = *(QArrayData **)(param_1 + 0x30);
  if (*(int *)pQVar1 != 0) {
    if (*(int *)pQVar1 == -1) goto LAB_00904749;
    LOCK();
    *(int *)pQVar1 = *(int *)pQVar1 + -1;
    UNLOCK();
    if (*(int *)pQVar1 != 0) goto LAB_00904749;
    pQVar1 = *(QArrayData **)(param_1 + 0x30);
  }
  QArrayData::deallocate(pQVar1,1,8);
LAB_00904749:
  QFileDialog::~QFileDialog(param_1);
  operator_delete(param_1,0x68);
  return;
}


// ==== entry=00904774 name=FUN_00904774 size=1 ====

void FUN_00904774(void)

{
  return;
}


// ==== entry=00904776 orig=FUN_00904776 size=24 name=NameDialog_metaObject ====

undefined ** NameDialog_metaObject(long param_1)

{
  undefined **ppuVar1;
  
  if (*(long *)(*(long *)(param_1 + 8) + 0x28) != 0) {
    ppuVar1 = (undefined **)QObjectData::dynamicMetaObject();
    return ppuVar1;
  }
  return &PTR_staticMetaObject_011a15e0;
}


// ==== entry=0090478e orig=FUN_0090478e size=66 name=NameDialog_qt_metacast ====

char * NameDialog_qt_metacast(char *param_1,char *param_2)

{
  int iVar1;
  char *pcVar2;
  
  if (param_2 == (char *)0x0) {
    return (char *)0x0;
  }
  iVar1 = strcmp(param_2,"NameDialog");
  if (iVar1 == 0) {
    return param_1;
  }
  pcVar2 = (char *)QDialog::qt_metacast(param_1);
  return pcVar2;
}


// ==== entry=009047d0 orig=FUN_009047d0 size=5 name=NameDialog_qt_metacall ====

void QDialog::NameDialog_qt_metacall(void)

{
  qt_metacall();
  return;
}


// ==== entry=009047d6 orig=FUN_009047d6 size=92 name=NameDialog_dtor_deleting ====

void NameDialog_dtor_deleting(QDialog *param_1)

{
  QArrayData *pQVar1;
  
  *(undefined ***)param_1 = &NameDialog_vtable;
  *(undefined ***)(param_1 + 0x10) = &PTR_FUN_011a1590;
  pQVar1 = *(QArrayData **)(param_1 + 0x38);
  if (*(int *)pQVar1 != 0) {
    if (*(int *)pQVar1 == -1) goto LAB_00904807;
    LOCK();
    *(int *)pQVar1 = *(int *)pQVar1 + -1;
    UNLOCK();
    if (*(int *)pQVar1 != 0) goto LAB_00904807;
    pQVar1 = *(QArrayData **)(param_1 + 0x38);
  }
  QArrayData::deallocate(pQVar1,2,8);
LAB_00904807:
  QDialog::~QDialog(param_1);
  operator_delete(param_1,0x58);
  return;
}


// ==== entry=00904832 name=FUN_00904832 size=96 ====

void FUN_00904832(undefined8 *param_1)

{
  QArrayData *pQVar1;
  
  param_1[-2] = &NameDialog_vtable;
  *param_1 = &PTR_FUN_011a1590;
  pQVar1 = (QArrayData *)param_1[5];
  if (*(int *)pQVar1 != 0) {
    if (*(int *)pQVar1 == -1) goto LAB_00904864;
    LOCK();
    *(int *)pQVar1 = *(int *)pQVar1 + -1;
    UNLOCK();
    if (*(int *)pQVar1 != 0) goto LAB_00904864;
    pQVar1 = (QArrayData *)param_1[5];
  }
  QArrayData::deallocate(pQVar1,2,8);
LAB_00904864:
  QDialog::~QDialog((QDialog *)(param_1 + -2));
  operator_delete((QDialog *)(param_1 + -2),0x58);
  return;
}


// ==== entry=00904892 name=FUN_00904892 size=88 ====

void FUN_00904892(undefined8 *param_1)

{
  QArrayData *pQVar1;
  
  param_1[-2] = &NameDialog_vtable;
  *param_1 = &PTR_FUN_011a1590;
  pQVar1 = (QArrayData *)param_1[5];
  if (*(int *)pQVar1 == 0) {
LAB_009048d1:
    QArrayData::deallocate(pQVar1,2,8);
    QDialog::~QDialog((QDialog *)(param_1 + -2));
    return;
  }
  if (*(int *)pQVar1 != -1) {
    LOCK();
    *(int *)pQVar1 = *(int *)pQVar1 + -1;
    UNLOCK();
    if (*(int *)pQVar1 == 0) {
      pQVar1 = (QArrayData *)param_1[5];
      goto LAB_009048d1;
    }
  }
  QDialog::~QDialog((QDialog *)(param_1 + -2));
  return;
}


// ==== entry=009048ea orig=FUN_009048ea size=86 name=NameDialog_dtor ====

void NameDialog_dtor(QDialog *param_1)

{
  QArrayData *pQVar1;
  
  *(undefined ***)param_1 = &NameDialog_vtable;
  *(undefined ***)(param_1 + 0x10) = &PTR_FUN_011a1590;
  pQVar1 = *(QArrayData **)(param_1 + 0x38);
  if (*(int *)pQVar1 == 0) {
LAB_00904928:
    QArrayData::deallocate(pQVar1,2,8);
    QDialog::~QDialog(param_1);
    return;
  }
  if (*(int *)pQVar1 != -1) {
    LOCK();
    *(int *)pQVar1 = *(int *)pQVar1 + -1;
    UNLOCK();
    if (*(int *)pQVar1 == 0) {
      pQVar1 = *(QArrayData **)(param_1 + 0x38);
      goto LAB_00904928;
    }
  }
  QDialog::~QDialog(param_1);
  return;
}


// ==== entry=00904940 name=FUN_00904940 size=1 ====

void FUN_00904940(void)

{
  return;
}


// ==== entry=00904942 orig=FUN_00904942 size=24 name=OneKeyDialog_metaObject ====

undefined ** OneKeyDialog_metaObject(long param_1)

{
  undefined **ppuVar1;
  
  if (*(long *)(*(long *)(param_1 + 8) + 0x28) != 0) {
    ppuVar1 = (undefined **)QObjectData::dynamicMetaObject();
    return ppuVar1;
  }
  return &PTR_staticMetaObject_011a1860;
}


// ==== entry=0090495a orig=FUN_0090495a size=66 name=OneKeyDialog_qt_metacast ====

char * OneKeyDialog_qt_metacast(char *param_1,char *param_2)

{
  int iVar1;
  char *pcVar2;
  
  if (param_2 == (char *)0x0) {
    return (char *)0x0;
  }
  iVar1 = strcmp(param_2,"OneKeyDialog");
  if (iVar1 == 0) {
    return param_1;
  }
  pcVar2 = (char *)QDialog::qt_metacast(param_1);
  return pcVar2;
}


// ==== entry=0090499c orig=FUN_0090499c size=5 name=OneKeyDialog_qt_metacall ====

void QDialog::OneKeyDialog_qt_metacall(void)

{
  qt_metacall();
  return;
}


// ==== entry=009049a2 orig=FUN_009049a2 size=49 name=OneKeyDialog_dtor ====

void OneKeyDialog_dtor(QDialog *param_1)

{
  *(undefined ***)param_1 = &OneKeyDialog_vtable;
  *(undefined ***)(param_1 + 0x10) = &PTR_FUN_011a1810;
  FUN_00659460(param_1 + 0xd0);
  QDialog::~QDialog(param_1);
  return;
}


// ==== entry=009049d3 name=FUN_009049d3 size=50 ====

void FUN_009049d3(undefined8 *param_1)

{
  param_1[-2] = &OneKeyDialog_vtable;
  *param_1 = &PTR_FUN_011a1810;
  FUN_00659460(param_1 + 0x18);
  QDialog::~QDialog((QDialog *)(param_1 + -2));
  return;
}


// ==== entry=00904a06 orig=FUN_00904a06 size=62 name=OneKeyDialog_dtor_deleting ====

void OneKeyDialog_dtor_deleting(QDialog *param_1)

{
  *(undefined ***)param_1 = &OneKeyDialog_vtable;
  *(undefined ***)(param_1 + 0x10) = &PTR_FUN_011a1810;
  FUN_00659460(param_1 + 0xd0);
  QDialog::~QDialog(param_1);
  operator_delete(param_1,0xd8);
  return;
}


// ==== entry=00904a44 name=FUN_00904a44 size=63 ====

void FUN_00904a44(undefined8 *param_1)

{
  param_1[-2] = &OneKeyDialog_vtable;
  *param_1 = &PTR_FUN_011a1810;
  FUN_00659460(param_1 + 0x18);
  QDialog::~QDialog((QDialog *)(param_1 + -2));
  operator_delete((QDialog *)(param_1 + -2),0xd8);
  return;
}


// ==== entry=00904a84 name=FUN_00904a84 size=1 ====

void FUN_00904a84(void)

{
  return;
}


// ==== entry=00904a86 orig=FUN_00904a86 size=24 name=PasswordDialog_metaObject ====

undefined ** PasswordDialog_metaObject(long param_1)

{
  undefined **ppuVar1;
  
  if (*(long *)(*(long *)(param_1 + 8) + 0x28) != 0) {
    ppuVar1 = (undefined **)QObjectData::dynamicMetaObject();
    return ppuVar1;
  }
  return &PTR_staticMetaObject_011a1ae0;
}


// ==== entry=00904a9e orig=FUN_00904a9e size=66 name=PasswordDialog_qt_metacast ====

char * PasswordDialog_qt_metacast(char *param_1,char *param_2)

{
  int iVar1;
  char *pcVar2;
  
  if (param_2 == (char *)0x0) {
    return (char *)0x0;
  }
  iVar1 = strcmp(param_2,"PasswordDialog");
  if (iVar1 == 0) {
    return param_1;
  }
  pcVar2 = (char *)QDialog::qt_metacast(param_1);
  return pcVar2;
}


// ==== entry=00904ae0 orig=FUN_00904ae0 size=5 name=PasswordDialog_qt_metacall ====

void QDialog::PasswordDialog_qt_metacall(void)

{
  qt_metacall();
  return;
}


// ==== entry=00904ae6 name=FUN_00904ae6 size=1 ====

void FUN_00904ae6(void)

{
  return;
}


// ==== entry=00904ae8 orig=FUN_00904ae8 size=24 name=PlaySoundWidget_metaObject ====

undefined ** PlaySoundWidget_metaObject(long param_1)

{
  undefined **ppuVar1;
  
  if (*(long *)(*(long *)(param_1 + 8) + 0x28) != 0) {
    ppuVar1 = (undefined **)QObjectData::dynamicMetaObject();
    return ppuVar1;
  }
  return &PTR_staticMetaObject_011a1fc0;
}


// ==== entry=00904b00 orig=FUN_00904b00 size=24 name=PlaySoundDialog_metaObject ====

undefined ** PlaySoundDialog_metaObject(long param_1)

{
  undefined **ppuVar1;
  
  if (*(long *)(*(long *)(param_1 + 8) + 0x28) != 0) {
    ppuVar1 = (undefined **)QObjectData::dynamicMetaObject();
    return ppuVar1;
  }
  return &PTR_staticMetaObject_011a1f80;
}


// ==== entry=00904b18 name=FUN_00904b18 size=1 ====

void FUN_00904b18(void)

{
  return;
}


// ==== entry=00904b1a orig=FUN_00904b1a size=66 name=PlaySoundWidget_qt_metacast ====

char * PlaySoundWidget_qt_metacast(char *param_1,char *param_2)

{
  int iVar1;
  char *pcVar2;
  
  if (param_2 == (char *)0x0) {
    return (char *)0x0;
  }
  iVar1 = strcmp(param_2,"PlaySoundWidget");
  if (iVar1 == 0) {
    return param_1;
  }
  pcVar2 = (char *)QWidget::qt_metacast(param_1);
  return pcVar2;
}


// ==== entry=00904b5c orig=FUN_00904b5c size=5 name=PlaySoundWidget_qt_metacall ====

void QWidget::PlaySoundWidget_qt_metacall(void)

{
  qt_metacall();
  return;
}


// ==== entry=00904b62 orig=FUN_00904b62 size=66 name=PlaySoundDialog_qt_metacast ====

char * PlaySoundDialog_qt_metacast(char *param_1,char *param_2)

{
  int iVar1;
  char *pcVar2;
  
  if (param_2 == (char *)0x0) {
    return (char *)0x0;
  }
  iVar1 = strcmp(param_2,"PlaySoundDialog");
  if (iVar1 == 0) {
    return param_1;
  }
  pcVar2 = (char *)QDialog::qt_metacast(param_1);
  return pcVar2;
}


// ==== entry=00904ba4 orig=FUN_00904ba4 size=5 name=PlaySoundDialog_qt_metacall ====

void QDialog::PlaySoundDialog_qt_metacall(void)

{
  qt_metacall();
  return;
}


// ==== entry=00904baa orig=FUN_00904baa size=29 name=PlaySoundDialog_dtor ====

void PlaySoundDialog_dtor(QDialog *param_1)

{
  *(undefined ***)param_1 = &PlaySoundDialog_vtable;
  *(undefined ***)(param_1 + 0x10) = &PTR_FUN_011a1f28;
  QDialog::~QDialog(param_1);
  return;
}


// ==== entry=00904bc7 name=FUN_00904bc7 size=33 ====

void FUN_00904bc7(undefined8 *param_1)

{
  param_1[-2] = &PlaySoundDialog_vtable;
  *param_1 = &PTR_FUN_011a1f28;
  QDialog::~QDialog((QDialog *)(param_1 + -2));
  return;
}


// ==== entry=00904be8 orig=FUN_00904be8 size=47 name=PlaySoundDialog_dtor_deleting ====

void PlaySoundDialog_dtor_deleting(QDialog *param_1)

{
  *(undefined ***)param_1 = &PlaySoundDialog_vtable;
  *(undefined ***)(param_1 + 0x10) = &PTR_FUN_011a1f28;
  QDialog::~QDialog(param_1);
  operator_delete(param_1,0x58);
  return;
}


// ==== entry=00904c17 name=FUN_00904c17 size=51 ====

void FUN_00904c17(undefined8 *param_1)

{
  param_1[-2] = &PlaySoundDialog_vtable;
  *param_1 = &PTR_FUN_011a1f28;
  QDialog::~QDialog((QDialog *)(param_1 + -2));
  operator_delete((QDialog *)(param_1 + -2),0x58);
  return;
}


// ==== entry=00904c4a orig=FUN_00904c4a size=29 name=PlaySoundWidget_dtor ====

void PlaySoundWidget_dtor(QWidget *param_1)

{
  *(undefined ***)param_1 = &PlaySoundWidget_vtable;
  *(undefined ***)(param_1 + 0x10) = &PTR_FUN_011a1d00;
  QWidget::~QWidget(param_1);
  return;
}


// ==== entry=00904c67 name=FUN_00904c67 size=33 ====

void FUN_00904c67(undefined8 *param_1)

{
  param_1[-2] = &PlaySoundWidget_vtable;
  *param_1 = &PTR_FUN_011a1d00;
  QWidget::~QWidget((QWidget *)(param_1 + -2));
  return;
}


// ==== entry=00904c88 orig=FUN_00904c88 size=47 name=PlaySoundWidget_dtor_deleting ====

void PlaySoundWidget_dtor_deleting(QWidget *param_1)

{
  *(undefined ***)param_1 = &PlaySoundWidget_vtable;
  *(undefined ***)(param_1 + 0x10) = &PTR_FUN_011a1d00;
  QWidget::~QWidget(param_1);
  operator_delete(param_1,0x50);
  return;
}


// ==== entry=00904cb7 name=FUN_00904cb7 size=51 ====

void FUN_00904cb7(undefined8 *param_1)

{
  param_1[-2] = &PlaySoundWidget_vtable;
  *param_1 = &PTR_FUN_011a1d00;
  QWidget::~QWidget((QWidget *)(param_1 + -2));
  operator_delete((QWidget *)(param_1 + -2),0x50);
  return;
}


// ==== entry=00904cf0 orig=FUN_00904cf0 size=24 name=SessionDialog_metaObject ====

undefined ** SessionDialog_metaObject(long param_1)

{
  undefined **ppuVar1;
  
  if (*(long *)(*(long *)(param_1 + 8) + 0x28) != 0) {
    ppuVar1 = (undefined **)QObjectData::dynamicMetaObject();
    return ppuVar1;
  }
  return &PTR_staticMetaObject_011a2240;
}


// ==== entry=00904d08 name=FUN_00904d08 size=42 ====

void FUN_00904d08(QObject *param_1,undefined8 param_2)

{
  void *local_18;
  undefined8 local_10;
  
  local_18 = (void *)0x0;
  local_10 = param_2;
  QMetaObject::activate(param_1,(QMetaObject *)&PTR_staticMetaObject_011a2240,1,&local_18);
  return;
}


// ==== entry=00904d32 name=FUN_00904d32 size=47 ====

void FUN_00904d32(QObject *param_1,undefined8 param_2,undefined8 param_3)

{
  void *local_28;
  undefined8 local_20;
  undefined8 local_18;
  
  local_28 = (void *)0x0;
  local_20 = param_2;
  local_18 = param_3;
  QMetaObject::activate(param_1,(QMetaObject *)&PTR_staticMetaObject_011a2240,2,&local_28);
  return;
}


// ==== entry=00904d62 name=FUN_00904d62 size=44 ====

void FUN_00904d62(QObject *param_1,undefined8 param_2,undefined8 param_3)

{
  void *local_28;
  undefined8 local_20;
  undefined8 local_18;
  
  local_28 = (void *)0x0;
  local_20 = param_2;
  local_18 = param_3;
  QMetaObject::activate(param_1,(QMetaObject *)&PTR_staticMetaObject_011a2240,0,&local_28);
  return;
}


// ==== entry=00904d8e name=FUN_00904d8e size=140 ====

void FUN_00904d8e(undefined8 param_1,int param_2,int param_3,undefined8 *param_4)

{
  undefined4 *puVar1;
  long *plVar2;
  code *pcVar3;
  
  if (param_2 == 0) {
    if (param_3 == 1) {
      FUN_00904d08(param_1,param_4[1]);
      return;
    }
    if (param_3 == 2) {
      FUN_00904d32(param_1,param_4[1],param_4[2]);
      return;
    }
    if (param_3 == 0) {
      FUN_00904d62(param_1,param_4[1],param_4[2]);
      return;
    }
  }
  else if (param_2 == 10) {
    puVar1 = (undefined4 *)*param_4;
    plVar2 = (long *)param_4[1];
    pcVar3 = (code *)*plVar2;
    if ((pcVar3 == FUN_00904d62) && (plVar2[1] == 0)) {
      *puVar1 = 0;
      return;
    }
    if ((pcVar3 == FUN_00904d08) && (plVar2[1] == 0)) {
      *puVar1 = 1;
      return;
    }
    if ((pcVar3 == FUN_00904d32) && (plVar2[1] == 0)) {
      *puVar1 = 2;
      return;
    }
  }
  return;
}


// ==== entry=00904e1a orig=FUN_00904e1a size=66 name=SessionDialog_qt_metacast ====

char * SessionDialog_qt_metacast(char *param_1,char *param_2)

{
  int iVar1;
  char *pcVar2;
  
  if (param_2 == (char *)0x0) {
    return (char *)0x0;
  }
  iVar1 = strcmp(param_2,"SessionDialog");
  if (iVar1 == 0) {
    return param_1;
  }
  pcVar2 = (char *)QDialog::qt_metacast(param_1);
  return pcVar2;
}


// ==== entry=00904e5c orig=FUN_00904e5c size=97 name=SessionDialog_qt_metacall ====

ulong SessionDialog_qt_metacall
                (undefined8 param_1,int param_2,undefined8 param_3,undefined8 *param_4)

{
  int iVar1;
  ulong uVar2;
  
  uVar2 = QDialog::qt_metacall();
  iVar1 = (int)uVar2;
  if (-1 < iVar1) {
    if (param_2 == 0) {
      if (iVar1 < 3) {
        FUN_00904d8e(param_1,0,uVar2 & 0xffffffff,param_4);
        uVar2 = uVar2 & 0xffffffff;
      }
    }
    else {
      if (param_2 != 0xc) {
        return uVar2;
      }
      if (iVar1 < 3) {
        *(undefined4 *)*param_4 = 0xffffffff;
      }
    }
    uVar2 = (ulong)((int)uVar2 - 3);
  }
  return uVar2;
}


// ==== entry=00904ebe name=FUN_00904ebe size=1 ====

void FUN_00904ebe(void)

{
  return;
}


// ==== entry=00904ec0 orig=FUN_00904ec0 size=24 name=RemoteFileDialog_metaObject ====

undefined ** RemoteFileDialog_metaObject(long param_1)

{
  undefined **ppuVar1;
  
  if (*(long *)(*(long *)(param_1 + 8) + 0x28) != 0) {
    ppuVar1 = (undefined **)QObjectData::dynamicMetaObject();
    return ppuVar1;
  }
  return &PTR_staticMetaObject_011a24c0;
}


// ==== entry=00904ed8 orig=FUN_00904ed8 size=66 name=RemoteFileDialog_qt_metacast ====

char * RemoteFileDialog_qt_metacast(char *param_1,char *param_2)

{
  int iVar1;
  char *pcVar2;
  
  if (param_2 == (char *)0x0) {
    return (char *)0x0;
  }
  iVar1 = strcmp(param_2,"RemoteFileDialog");
  if (iVar1 == 0) {
    return param_1;
  }
  pcVar2 = (char *)QDialog::qt_metacast(param_1);
  return pcVar2;
}


// ==== entry=00904f1a orig=FUN_00904f1a size=5 name=RemoteFileDialog_qt_metacall ====

void QDialog::RemoteFileDialog_qt_metacall(void)

{
  qt_metacall();
  return;
}


// ==== entry=00904f20 orig=FUN_00904f20 size=180 name=RemoteFileDialog_dtor ====

/* WARNING: Removing unreachable block (ram,0x00904f72) */
/* WARNING: Removing unreachable block (ram,0x00904fbe) */

void RemoteFileDialog_dtor(QDialog *param_1)

{
  long *plVar1;
  int *piVar2;
  int iVar3;
  long *plVar4;
  code *pcVar5;
  long lVar6;
  
  *(undefined ***)param_1 = &RemoteFileDialog_vtable;
  *(undefined ***)(param_1 + 0x10) = &PTR_FUN_011a2470;
  plVar4 = *(long **)(param_1 + 0x98);
  if (plVar4 != (long *)0x0) {
    LOCK();
    plVar1 = plVar4 + 1;
    lVar6 = *plVar1;
    *(int *)plVar1 = (int)*plVar1 + -1;
    UNLOCK();
    if ((int)lVar6 == 1) {
      if (*(code **)(*plVar4 + 0x10) != FUN_00575d12) {
        (**(code **)(*plVar4 + 0x10))(plVar4);
      }
      LOCK();
      piVar2 = (int *)((long)plVar4 + 0xc);
      iVar3 = *piVar2;
      *piVar2 = *piVar2 + -1;
      UNLOCK();
      if (iVar3 == 1) {
        pcVar5 = *(code **)(*plVar4 + 0x18);
        if (pcVar5 == std::_Sp_counted_base<(__gnu_cxx::_Lock_policy)2>::_M_destroy) {
          (**(code **)(*plVar4 + 8))();
        }
        else {
          (*pcVar5)(plVar4);
        }
      }
    }
  }
  QDialog::~QDialog(param_1);
  return;
}


// ==== entry=00904fd4 name=FUN_00904fd4 size=179 ====

/* WARNING: Removing unreachable block (ram,0x00905027) */
/* WARNING: Removing unreachable block (ram,0x00905077) */

void FUN_00904fd4(undefined8 *param_1)

{
  long *plVar1;
  int *piVar2;
  int iVar3;
  long *plVar4;
  code *pcVar5;
  long lVar6;
  
  param_1[-2] = &RemoteFileDialog_vtable;
  *param_1 = &PTR_FUN_011a2470;
  plVar4 = (long *)param_1[0x11];
  if (plVar4 != (long *)0x0) {
    LOCK();
    plVar1 = plVar4 + 1;
    lVar6 = *plVar1;
    *(int *)plVar1 = (int)*plVar1 + -1;
    UNLOCK();
    if ((int)lVar6 == 1) {
      if (*(code **)(*plVar4 + 0x10) != FUN_00575d12) {
        (**(code **)(*plVar4 + 0x10))(plVar4);
      }
      LOCK();
      piVar2 = (int *)((long)plVar4 + 0xc);
      iVar3 = *piVar2;
      *piVar2 = *piVar2 + -1;
      UNLOCK();
      if (iVar3 == 1) {
        pcVar5 = *(code **)(*plVar4 + 0x18);
        if (pcVar5 == std::_Sp_counted_base<(__gnu_cxx::_Lock_policy)2>::_M_destroy) {
          (**(code **)(*plVar4 + 8))(plVar4);
        }
        else {
          (*pcVar5)();
        }
      }
    }
  }
  QDialog::~QDialog((QDialog *)(param_1 + -2));
  return;
}


// ==== entry=00905090 name=FUN_00905090 size=190 ====

/* WARNING: Removing unreachable block (ram,0x009050f0) */
/* WARNING: Removing unreachable block (ram,0x0090513e) */

void FUN_00905090(undefined8 *param_1)

{
  long *plVar1;
  int *piVar2;
  int iVar3;
  long *plVar4;
  code *pcVar5;
  long lVar6;
  
  param_1[-2] = &RemoteFileDialog_vtable;
  *param_1 = &PTR_FUN_011a2470;
  plVar4 = (long *)param_1[0x11];
  if (plVar4 != (long *)0x0) {
    LOCK();
    plVar1 = plVar4 + 1;
    lVar6 = *plVar1;
    *(int *)plVar1 = (int)*plVar1 + -1;
    UNLOCK();
    if ((int)lVar6 == 1) {
      if (*(code **)(*plVar4 + 0x10) != FUN_00575d12) {
        (**(code **)(*plVar4 + 0x10))(plVar4);
      }
      LOCK();
      piVar2 = (int *)((long)plVar4 + 0xc);
      iVar3 = *piVar2;
      *piVar2 = *piVar2 + -1;
      UNLOCK();
      if (iVar3 == 1) {
        pcVar5 = *(code **)(*plVar4 + 0x18);
        if (pcVar5 == std::_Sp_counted_base<(__gnu_cxx::_Lock_policy)2>::_M_destroy) {
          (**(code **)(*plVar4 + 8))(plVar4);
        }
        else {
          (*pcVar5)();
        }
      }
    }
  }
  QDialog::~QDialog((QDialog *)(param_1 + -2));
  operator_delete((QDialog *)(param_1 + -2),0xa0);
  return;
}


// ==== entry=0090514e orig=FUN_0090514e size=198 name=RemoteFileDialog_dtor_deleting ====

/* WARNING: Removing unreachable block (ram,0x009051ad) */
/* WARNING: Removing unreachable block (ram,0x009051f9) */

void RemoteFileDialog_dtor_deleting(QDialog *param_1)

{
  long *plVar1;
  int *piVar2;
  int iVar3;
  long *plVar4;
  code *pcVar5;
  long lVar6;
  
  *(undefined ***)param_1 = &RemoteFileDialog_vtable;
  *(undefined ***)(param_1 + 0x10) = &PTR_FUN_011a2470;
  plVar4 = *(long **)(param_1 + 0x98);
  if (plVar4 != (long *)0x0) {
    LOCK();
    plVar1 = plVar4 + 1;
    lVar6 = *plVar1;
    *(int *)plVar1 = (int)*plVar1 + -1;
    UNLOCK();
    if ((int)lVar6 == 1) {
      if (*(code **)(*plVar4 + 0x10) != FUN_00575d12) {
        (**(code **)(*plVar4 + 0x10))(plVar4);
      }
      LOCK();
      piVar2 = (int *)((long)plVar4 + 0xc);
      iVar3 = *piVar2;
      *piVar2 = *piVar2 + -1;
      UNLOCK();
      if (iVar3 == 1) {
        pcVar5 = *(code **)(*plVar4 + 0x18);
        if (pcVar5 == std::_Sp_counted_base<(__gnu_cxx::_Lock_policy)2>::_M_destroy) {
          (**(code **)(*plVar4 + 8))();
        }
        else {
          (*pcVar5)(plVar4);
        }
      }
    }
  }
  QDialog::~QDialog(param_1);
  operator_delete(param_1,0xa0);
  return;
}


// ==== entry=00905214 name=FUN_00905214 size=1 ====

void FUN_00905214(void)

{
  return;
}


// ==== entry=00905216 orig=FUN_00905216 size=24 name=DefaultEditorDialog_metaObject ====

undefined ** DefaultEditorDialog_metaObject(long param_1)

{
  undefined **ppuVar1;
  
  if (*(long *)(*(long *)(param_1 + 8) + 0x28) != 0) {
    ppuVar1 = (undefined **)QObjectData::dynamicMetaObject();
    return ppuVar1;
  }
  return &PTR_staticMetaObject_011a2740;
}


// ==== entry=0090522e orig=FUN_0090522e size=66 name=DefaultEditorDialog_qt_metacast ====

char * DefaultEditorDialog_qt_metacast(char *param_1,char *param_2)

{
  int iVar1;
  char *pcVar2;
  
  if (param_2 == (char *)0x0) {
    return (char *)0x0;
  }
  iVar1 = strcmp(param_2,"DefaultEditorDialog");
  if (iVar1 == 0) {
    return param_1;
  }
  pcVar2 = (char *)QDialog::qt_metacast(param_1);
  return pcVar2;
}


// ==== entry=00905270 orig=FUN_00905270 size=5 name=DefaultEditorDialog_qt_metacall ====

void QDialog::DefaultEditorDialog_qt_metacall(void)

{
  qt_metacall();
  return;
}


// ==== entry=00905276 orig=FUN_00905276 size=29 name=DefaultEditorDialog_dtor ====

void DefaultEditorDialog_dtor(QDialog *param_1)

{
  *(undefined ***)param_1 = &DefaultEditorDialog_vtable;
  *(undefined ***)(param_1 + 0x10) = &PTR_FUN_011a26f0;
  QDialog::~QDialog(param_1);
  return;
}


// ==== entry=00905293 name=FUN_00905293 size=33 ====

void FUN_00905293(undefined8 *param_1)

{
  param_1[-2] = &DefaultEditorDialog_vtable;
  *param_1 = &PTR_FUN_011a26f0;
  QDialog::~QDialog((QDialog *)(param_1 + -2));
  return;
}


// ==== entry=009052b4 orig=FUN_009052b4 size=47 name=DefaultEditorDialog_dtor_deleting ====

void DefaultEditorDialog_dtor_deleting(QDialog *param_1)

{
  *(undefined ***)param_1 = &DefaultEditorDialog_vtable;
  *(undefined ***)(param_1 + 0x10) = &PTR_FUN_011a26f0;
  QDialog::~QDialog(param_1);
  operator_delete(param_1,0x40);
  return;
}


// ==== entry=009052e3 name=FUN_009052e3 size=51 ====

void FUN_009052e3(undefined8 *param_1)

{
  param_1[-2] = &DefaultEditorDialog_vtable;
  *param_1 = &PTR_FUN_011a26f0;
  QDialog::~QDialog((QDialog *)(param_1 + -2));
  operator_delete((QDialog *)(param_1 + -2),0x40);
  return;
}


// ==== entry=00905316 name=FUN_00905316 size=1 ====

void FUN_00905316(void)

{
  return;
}


// ==== entry=00905318 orig=FUN_00905318 size=24 name=EnvironmentDialog_metaObject ====

undefined ** EnvironmentDialog_metaObject(long param_1)

{
  undefined **ppuVar1;
  
  if (*(long *)(*(long *)(param_1 + 8) + 0x28) != 0) {
    ppuVar1 = (undefined **)QObjectData::dynamicMetaObject();
    return ppuVar1;
  }
  return &PTR_staticMetaObject_011a29c0;
}


// ==== entry=00905330 orig=FUN_00905330 size=66 name=EnvironmentDialog_qt_metacast ====

char * EnvironmentDialog_qt_metacast(char *param_1,char *param_2)

{
  int iVar1;
  char *pcVar2;
  
  if (param_2 == (char *)0x0) {
    return (char *)0x0;
  }
  iVar1 = strcmp(param_2,"EnvironmentDialog");
  if (iVar1 == 0) {
    return param_1;
  }
  pcVar2 = (char *)QDialog::qt_metacast(param_1);
  return pcVar2;
}


// ==== entry=00905372 orig=FUN_00905372 size=5 name=EnvironmentDialog_qt_metacall ====

void QDialog::EnvironmentDialog_qt_metacall(void)

{
  qt_metacall();
  return;
}


// ==== entry=00905378 orig=FUN_00905378 size=29 name=EnvironmentDialog_dtor ====

void EnvironmentDialog_dtor(QDialog *param_1)

{
  *(undefined ***)param_1 = &EnvironmentDialog_vtable;
  *(undefined ***)(param_1 + 0x10) = &PTR_FUN_011a2970;
  QDialog::~QDialog(param_1);
  return;
}


// ==== entry=00905395 name=FUN_00905395 size=33 ====

void FUN_00905395(undefined8 *param_1)

{
  param_1[-2] = &EnvironmentDialog_vtable;
  *param_1 = &PTR_FUN_011a2970;
  QDialog::~QDialog((QDialog *)(param_1 + -2));
  return;
}


// ==== entry=009053b6 orig=FUN_009053b6 size=47 name=EnvironmentDialog_dtor_deleting ====

void EnvironmentDialog_dtor_deleting(QDialog *param_1)

{
  *(undefined ***)param_1 = &EnvironmentDialog_vtable;
  *(undefined ***)(param_1 + 0x10) = &PTR_FUN_011a2970;
  QDialog::~QDialog(param_1);
  operator_delete(param_1,0x50);
  return;
}


// ==== entry=009053e5 name=FUN_009053e5 size=51 ====

void FUN_009053e5(undefined8 *param_1)

{
  param_1[-2] = &EnvironmentDialog_vtable;
  *param_1 = &PTR_FUN_011a2970;
  QDialog::~QDialog((QDialog *)(param_1 + -2));
  operator_delete((QDialog *)(param_1 + -2),0x50);
  return;
}


// ==== entry=00905418 name=FUN_00905418 size=1 ====

void FUN_00905418(void)

{
  return;
}


// ==== entry=0090541a orig=FUN_0090541a size=24 name=FocusModeController_metaObject ====

undefined ** FocusModeController_metaObject(long param_1)

{
  undefined **ppuVar1;
  
  if (*(long *)(*(long *)(param_1 + 8) + 0x28) != 0) {
    ppuVar1 = (undefined **)QObjectData::dynamicMetaObject();
    return ppuVar1;
  }
  return &PTR_staticMetaObject_011a2ea0;
}


// ==== entry=00905432 orig=FUN_00905432 size=24 name=FocusModeDialog_metaObject ====

undefined ** FocusModeDialog_metaObject(long param_1)

{
  undefined **ppuVar1;
  
  if (*(long *)(*(long *)(param_1 + 8) + 0x28) != 0) {
    ppuVar1 = (undefined **)QObjectData::dynamicMetaObject();
    return ppuVar1;
  }
  return &PTR_staticMetaObject_011a2e60;
}


// ==== entry=0090544a name=FUN_0090544a size=1 ====

void FUN_0090544a(void)

{
  return;
}


// ==== entry=0090544c orig=FUN_0090544c size=66 name=FocusModeController_qt_metacast ====

char * FocusModeController_qt_metacast(char *param_1,char *param_2)

{
  int iVar1;
  char *pcVar2;
  
  if (param_2 == (char *)0x0) {
    return (char *)0x0;
  }
  iVar1 = strcmp(param_2,"FocusModeController");
  if (iVar1 == 0) {
    return param_1;
  }
  pcVar2 = (char *)QWidget::qt_metacast(param_1);
  return pcVar2;
}


// ==== entry=0090548e orig=FUN_0090548e size=5 name=FocusModeController_qt_metacall ====

void QWidget::FocusModeController_qt_metacall(void)

{
  qt_metacall();
  return;
}


// ==== entry=00905494 orig=FUN_00905494 size=66 name=FocusModeDialog_qt_metacast ====

char * FocusModeDialog_qt_metacast(char *param_1,char *param_2)

{
  int iVar1;
  char *pcVar2;
  
  if (param_2 == (char *)0x0) {
    return (char *)0x0;
  }
  iVar1 = strcmp(param_2,"FocusModeDialog");
  if (iVar1 == 0) {
    return param_1;
  }
  pcVar2 = (char *)QDialog::qt_metacast(param_1);
  return pcVar2;
}


// ==== entry=009054d6 orig=FUN_009054d6 size=5 name=FocusModeDialog_qt_metacall ====

void QDialog::FocusModeDialog_qt_metacall(void)

{
  qt_metacall();
  return;
}


// ==== entry=009054dc orig=FUN_009054dc size=29 name=FocusModeDialog_dtor ====

void FocusModeDialog_dtor(QDialog *param_1)

{
  *(undefined ***)param_1 = &FocusModeDialog_vtable;
  *(undefined ***)(param_1 + 0x10) = &PTR_FUN_011a2e08;
  QDialog::~QDialog(param_1);
  return;
}


// ==== entry=009054f9 name=FUN_009054f9 size=33 ====

void FUN_009054f9(undefined8 *param_1)

{
  param_1[-2] = &FocusModeDialog_vtable;
  *param_1 = &PTR_FUN_011a2e08;
  QDialog::~QDialog((QDialog *)(param_1 + -2));
  return;
}


// ==== entry=0090551a orig=FUN_0090551a size=47 name=FocusModeDialog_dtor_deleting ====

void FocusModeDialog_dtor_deleting(QDialog *param_1)

{
  *(undefined ***)param_1 = &FocusModeDialog_vtable;
  *(undefined ***)(param_1 + 0x10) = &PTR_FUN_011a2e08;
  QDialog::~QDialog(param_1);
  operator_delete(param_1,0x50);
  return;
}


// ==== entry=00905549 name=FUN_00905549 size=51 ====

void FUN_00905549(undefined8 *param_1)

{
  param_1[-2] = &FocusModeDialog_vtable;
  *param_1 = &PTR_FUN_011a2e08;
  QDialog::~QDialog((QDialog *)(param_1 + -2));
  operator_delete((QDialog *)(param_1 + -2),0x50);
  return;
}


// ==== entry=0090557c orig=FUN_0090557c size=92 name=FocusModeController_dtor_deleting ====

void FocusModeController_dtor_deleting(QWidget *param_1)

{
  QArrayData *pQVar1;
  
  *(undefined ***)param_1 = &FocusModeController_vtable;
  *(undefined ***)(param_1 + 0x10) = &PTR_FUN_011a2be0;
  pQVar1 = *(QArrayData **)(param_1 + 0x30);
  if (*(int *)pQVar1 != 0) {
    if (*(int *)pQVar1 == -1) goto LAB_009055ad;
    LOCK();
    *(int *)pQVar1 = *(int *)pQVar1 + -1;
    UNLOCK();
    if (*(int *)pQVar1 != 0) goto LAB_009055ad;
    pQVar1 = *(QArrayData **)(param_1 + 0x30);
  }
  QArrayData::deallocate(pQVar1,2,8);
LAB_009055ad:
  QWidget::~QWidget(param_1);
  operator_delete(param_1,0x78);
  return;
}


// ==== entry=009055d8 name=FUN_009055d8 size=96 ====

void FUN_009055d8(undefined8 *param_1)

{
  QArrayData *pQVar1;
  
  param_1[-2] = &FocusModeController_vtable;
  *param_1 = &PTR_FUN_011a2be0;
  pQVar1 = (QArrayData *)param_1[4];
  if (*(int *)pQVar1 != 0) {
    if (*(int *)pQVar1 == -1) goto LAB_0090560a;
    LOCK();
    *(int *)pQVar1 = *(int *)pQVar1 + -1;
    UNLOCK();
    if (*(int *)pQVar1 != 0) goto LAB_0090560a;
    pQVar1 = (QArrayData *)param_1[4];
  }
  QArrayData::deallocate(pQVar1,2,8);
LAB_0090560a:
  QWidget::~QWidget((QWidget *)(param_1 + -2));
  operator_delete((QWidget *)(param_1 + -2),0x78);
  return;
}


// ==== entry=00905638 name=FUN_00905638 size=88 ====

void FUN_00905638(undefined8 *param_1)

{
  QArrayData *pQVar1;
  
  param_1[-2] = &FocusModeController_vtable;
  *param_1 = &PTR_FUN_011a2be0;
  pQVar1 = (QArrayData *)param_1[4];
  if (*(int *)pQVar1 == 0) {
LAB_00905677:
    QArrayData::deallocate(pQVar1,2,8);
    QWidget::~QWidget((QWidget *)(param_1 + -2));
    return;
  }
  if (*(int *)pQVar1 != -1) {
    LOCK();
    *(int *)pQVar1 = *(int *)pQVar1 + -1;
    UNLOCK();
    if (*(int *)pQVar1 == 0) {
      pQVar1 = (QArrayData *)param_1[4];
      goto LAB_00905677;
    }
  }
  QWidget::~QWidget((QWidget *)(param_1 + -2));
  return;
}


// ==== entry=00905690 orig=FUN_00905690 size=86 name=FocusModeController_dtor ====

void FocusModeController_dtor(QWidget *param_1)

{
  QArrayData *pQVar1;
  
  *(undefined ***)param_1 = &FocusModeController_vtable;
  *(undefined ***)(param_1 + 0x10) = &PTR_FUN_011a2be0;
  pQVar1 = *(QArrayData **)(param_1 + 0x30);
  if (*(int *)pQVar1 == 0) {
LAB_009056ce:
    QArrayData::deallocate(pQVar1,2,8);
    QWidget::~QWidget(param_1);
    return;
  }
  if (*(int *)pQVar1 != -1) {
    LOCK();
    *(int *)pQVar1 = *(int *)pQVar1 + -1;
    UNLOCK();
    if (*(int *)pQVar1 == 0) {
      pQVar1 = *(QArrayData **)(param_1 + 0x30);
      goto LAB_009056ce;
    }
  }
  QWidget::~QWidget(param_1);
  return;
}


// ==== entry=009056f0 orig=FUN_009056f0 size=24 name=QuickDialog_metaObject ====

undefined ** QuickDialog_metaObject(long param_1)

{
  undefined **ppuVar1;
  
  if (*(long *)(*(long *)(param_1 + 8) + 0x28) != 0) {
    ppuVar1 = (undefined **)QObjectData::dynamicMetaObject();
    return ppuVar1;
  }
  return &PTR_staticMetaObject_011a3120;
}


// ==== entry=00905708 name=FUN_00905708 size=44 ====

void FUN_00905708(QObject *param_1,undefined8 param_2,undefined8 param_3)

{
  void *local_28;
  undefined8 local_20;
  undefined8 local_18;
  
  local_28 = (void *)0x0;
  local_20 = param_2;
  local_18 = param_3;
  QMetaObject::activate(param_1,(QMetaObject *)&PTR_staticMetaObject_011a3120,0,&local_28);
  return;
}


// ==== entry=00905734 name=FUN_00905734 size=60 ====

void FUN_00905734(undefined8 param_1,int param_2,int param_3,undefined8 *param_4)

{
  if (param_2 == 0) {
    if (param_3 == 0) {
      FUN_00905708(param_1,param_4[1],param_4[2]);
      return;
    }
  }
  else if (((param_2 == 10) && (*(code **)param_4[1] == FUN_00905708)) &&
          (((long *)param_4[1])[1] == 0)) {
    *(undefined4 *)*param_4 = 0;
    return;
  }
  return;
}


// ==== entry=00905770 orig=FUN_00905770 size=66 name=QuickDialog_qt_metacast ====

char * QuickDialog_qt_metacast(char *param_1,char *param_2)

{
  int iVar1;
  char *pcVar2;
  
  if (param_2 == (char *)0x0) {
    return (char *)0x0;
  }
  iVar1 = strcmp(param_2,"QuickDialog");
  if (iVar1 == 0) {
    return param_1;
  }
  pcVar2 = (char *)QDialog::qt_metacast(param_1);
  return pcVar2;
}


// ==== entry=009057b2 orig=FUN_009057b2 size=92 name=QuickDialog_qt_metacall ====

ulong QuickDialog_qt_metacall(undefined8 param_1,int param_2,undefined8 param_3,undefined8 *param_4)

{
  int iVar1;
  ulong uVar2;
  
  uVar2 = QDialog::qt_metacall();
  iVar1 = (int)uVar2;
  if (-1 < iVar1) {
    if (param_2 == 0) {
      if (iVar1 == 0) {
        FUN_00905708(param_1,param_4[1],param_4[2]);
        uVar2 = uVar2 & 0xffffffff;
      }
    }
    else {
      if (param_2 != 0xc) {
        return uVar2;
      }
      if (iVar1 == 0) {
        *(undefined4 *)*param_4 = 0xffffffff;
      }
    }
    uVar2 = (ulong)((int)uVar2 - 1);
  }
  return uVar2;
}


// ==== entry=0090580e orig=FUN_0090580e size=88 name=QuickDialog_dtor ====

void QuickDialog_dtor(QDialog *param_1)

{
  QArrayData *pQVar1;
  
  *(undefined ***)param_1 = &QuickDialog_vtable;
  *(undefined ***)(param_1 + 0x10) = &PTR_FUN_011a30d0;
  pQVar1 = *(QArrayData **)(param_1 + 0x60);
  if (*(int *)pQVar1 != 0) {
    if (*(int *)pQVar1 == -1) goto LAB_0090583f;
    LOCK();
    *(int *)pQVar1 = *(int *)pQVar1 + -1;
    UNLOCK();
    if (*(int *)pQVar1 != 0) goto LAB_0090583f;
    pQVar1 = *(QArrayData **)(param_1 + 0x60);
  }
  QArrayData::deallocate(pQVar1,2,8);
LAB_0090583f:
  FUN_00af2c10(param_1 + 0x38);
  QDialog::~QDialog(param_1);
  return;
}


// ==== entry=00905866 name=FUN_00905866 size=102 ====

void FUN_00905866(undefined8 *param_1)

{
  QArrayData *pQVar1;
  
  param_1[-2] = &QuickDialog_vtable;
  *param_1 = &PTR_FUN_011a30d0;
  pQVar1 = (QArrayData *)param_1[10];
  if (*(int *)pQVar1 != 0) {
    if (*(int *)pQVar1 == -1) goto LAB_0090589c;
    LOCK();
    *(int *)pQVar1 = *(int *)pQVar1 + -1;
    UNLOCK();
    if (*(int *)pQVar1 != 0) goto LAB_0090589c;
    pQVar1 = (QArrayData *)param_1[10];
  }
  QArrayData::deallocate(pQVar1,2,8);
LAB_0090589c:
  FUN_00af2c10(param_1 + 5);
  QDialog::~QDialog((QDialog *)(param_1 + -2));
  return;
}


// ==== entry=009058cc name=FUN_009058cc size=115 ====

void FUN_009058cc(undefined8 *param_1)

{
  QArrayData *pQVar1;
  
  param_1[-2] = &QuickDialog_vtable;
  *param_1 = &PTR_FUN_011a30d0;
  pQVar1 = (QArrayData *)param_1[10];
  if (*(int *)pQVar1 != 0) {
    if (*(int *)pQVar1 == -1) goto LAB_00905906;
    LOCK();
    *(int *)pQVar1 = *(int *)pQVar1 + -1;
    UNLOCK();
    if (*(int *)pQVar1 != 0) goto LAB_00905906;
    pQVar1 = (QArrayData *)param_1[10];
  }
  QArrayData::deallocate(pQVar1,2,8);
LAB_00905906:
  FUN_00af2c10(param_1 + 5);
  QDialog::~QDialog((QDialog *)(param_1 + -2));
  operator_delete((QDialog *)(param_1 + -2),0xc0);
  return;
}


// ==== entry=00905940 orig=FUN_00905940 size=101 name=QuickDialog_dtor_deleting ====

void QuickDialog_dtor_deleting(QDialog *param_1)

{
  QArrayData *pQVar1;
  
  *(undefined ***)param_1 = &QuickDialog_vtable;
  *(undefined ***)(param_1 + 0x10) = &PTR_FUN_011a30d0;
  pQVar1 = *(QArrayData **)(param_1 + 0x60);
  if (*(int *)pQVar1 != 0) {
    if (*(int *)pQVar1 == -1) goto LAB_00905971;
    LOCK();
    *(int *)pQVar1 = *(int *)pQVar1 + -1;
    UNLOCK();
    if (*(int *)pQVar1 != 0) goto LAB_00905971;
    pQVar1 = *(QArrayData **)(param_1 + 0x60);
  }
  QArrayData::deallocate(pQVar1,2,8);
LAB_00905971:
  FUN_00af2c10(param_1 + 0x38);
  QDialog::~QDialog(param_1);
  operator_delete(param_1,0xc0);
  return;
}


// ==== entry=009059a6 name=FUN_009059a6 size=1 ====

void FUN_009059a6(void)

{
  return;
}


// ==== entry=009059a8 orig=FUN_009059a8 size=24 name=PasteDialog_metaObject ====

undefined ** PasteDialog_metaObject(long param_1)

{
  undefined **ppuVar1;
  
  if (*(long *)(*(long *)(param_1 + 8) + 0x28) != 0) {
    ppuVar1 = (undefined **)QObjectData::dynamicMetaObject();
    return ppuVar1;
  }
  return &PTR_staticMetaObject_011a33a0;
}


// ==== entry=009059c0 orig=FUN_009059c0 size=66 name=PasteDialog_qt_metacast ====

char * PasteDialog_qt_metacast(char *param_1,char *param_2)

{
  int iVar1;
  char *pcVar2;
  
  if (param_2 == (char *)0x0) {
    return (char *)0x0;
  }
  iVar1 = strcmp(param_2,"PasteDialog");
  if (iVar1 == 0) {
    return param_1;
  }
  pcVar2 = (char *)QDialog::qt_metacast(param_1);
  return pcVar2;
}


// ==== entry=00905a02 orig=FUN_00905a02 size=5 name=PasteDialog_qt_metacall ====

void QDialog::PasteDialog_qt_metacall(void)

{
  qt_metacall();
  return;
}


// ==== entry=00905a08 orig=FUN_00905a08 size=92 name=PasteDialog_dtor_deleting ====

void PasteDialog_dtor_deleting(QDialog *param_1)

{
  QArrayData *pQVar1;
  
  *(undefined ***)param_1 = &PasteDialog_vtable;
  *(undefined ***)(param_1 + 0x10) = &PTR_FUN_011a3350;
  pQVar1 = *(QArrayData **)(param_1 + 0x38);
  if (*(int *)pQVar1 != 0) {
    if (*(int *)pQVar1 == -1) goto LAB_00905a39;
    LOCK();
    *(int *)pQVar1 = *(int *)pQVar1 + -1;
    UNLOCK();
    if (*(int *)pQVar1 != 0) goto LAB_00905a39;
    pQVar1 = *(QArrayData **)(param_1 + 0x38);
  }
  QArrayData::deallocate(pQVar1,2,8);
LAB_00905a39:
  QDialog::~QDialog(param_1);
  operator_delete(param_1,0x80);
  return;
}


// ==== entry=00905a64 name=FUN_00905a64 size=96 ====

void FUN_00905a64(undefined8 *param_1)

{
  QArrayData *pQVar1;
  
  param_1[-2] = &PasteDialog_vtable;
  *param_1 = &PTR_FUN_011a3350;
  pQVar1 = (QArrayData *)param_1[5];
  if (*(int *)pQVar1 != 0) {
    if (*(int *)pQVar1 == -1) goto LAB_00905a96;
    LOCK();
    *(int *)pQVar1 = *(int *)pQVar1 + -1;
    UNLOCK();
    if (*(int *)pQVar1 != 0) goto LAB_00905a96;
    pQVar1 = (QArrayData *)param_1[5];
  }
  QArrayData::deallocate(pQVar1,2,8);
LAB_00905a96:
  QDialog::~QDialog((QDialog *)(param_1 + -2));
  operator_delete((QDialog *)(param_1 + -2),0x80);
  return;
}


// ==== entry=00905ac4 name=FUN_00905ac4 size=88 ====

void FUN_00905ac4(undefined8 *param_1)

{
  QArrayData *pQVar1;
  
  param_1[-2] = &PasteDialog_vtable;
  *param_1 = &PTR_FUN_011a3350;
  pQVar1 = (QArrayData *)param_1[5];
  if (*(int *)pQVar1 == 0) {
LAB_00905b03:
    QArrayData::deallocate(pQVar1,2,8);
    QDialog::~QDialog((QDialog *)(param_1 + -2));
    return;
  }
  if (*(int *)pQVar1 != -1) {
    LOCK();
    *(int *)pQVar1 = *(int *)pQVar1 + -1;
    UNLOCK();
    if (*(int *)pQVar1 == 0) {
      pQVar1 = (QArrayData *)param_1[5];
      goto LAB_00905b03;
    }
  }
  QDialog::~QDialog((QDialog *)(param_1 + -2));
  return;
}


// ==== entry=00905b1c orig=FUN_00905b1c size=86 name=PasteDialog_dtor ====

void PasteDialog_dtor(QDialog *param_1)

{
  QArrayData *pQVar1;
  
  *(undefined ***)param_1 = &PasteDialog_vtable;
  *(undefined ***)(param_1 + 0x10) = &PTR_FUN_011a3350;
  pQVar1 = *(QArrayData **)(param_1 + 0x38);
  if (*(int *)pQVar1 == 0) {
LAB_00905b5a:
    QArrayData::deallocate(pQVar1,2,8);
    QDialog::~QDialog(param_1);
    return;
  }
  if (*(int *)pQVar1 != -1) {
    LOCK();
    *(int *)pQVar1 = *(int *)pQVar1 + -1;
    UNLOCK();
    if (*(int *)pQVar1 == 0) {
      pQVar1 = *(QArrayData **)(param_1 + 0x38);
      goto LAB_00905b5a;
    }
  }
  QDialog::~QDialog(param_1);
  return;
}


// ==== entry=00905b72 name=FUN_00905b72 size=1 ====

void FUN_00905b72(void)

{
  return;
}


// ==== entry=00905b74 orig=FUN_00905b74 size=24 name=ProfileDialog_metaObject ====

undefined ** ProfileDialog_metaObject(long param_1)

{
  undefined **ppuVar1;
  
  if (*(long *)(*(long *)(param_1 + 8) + 0x28) != 0) {
    ppuVar1 = (undefined **)QObjectData::dynamicMetaObject();
    return ppuVar1;
  }
  return &PTR_staticMetaObject_011a3620;
}


// ==== entry=00905b8c orig=FUN_00905b8c size=66 name=ProfileDialog_qt_metacast ====

char * ProfileDialog_qt_metacast(char *param_1,char *param_2)

{
  int iVar1;
  char *pcVar2;
  
  if (param_2 == (char *)0x0) {
    return (char *)0x0;
  }
  iVar1 = strcmp(param_2,"ProfileDialog");
  if (iVar1 == 0) {
    return param_1;
  }
  pcVar2 = (char *)QDialog::qt_metacast(param_1);
  return pcVar2;
}


// ==== entry=00905bce orig=FUN_00905bce size=5 name=ProfileDialog_qt_metacall ====

void QDialog::ProfileDialog_qt_metacall(void)

{
  qt_metacall();
  return;
}


// ==== entry=00905bd4 name=FUN_00905bd4 size=1 ====

void FUN_00905bd4(void)

{
  return;
}


// ==== entry=00905bd6 orig=FUN_00905bd6 size=24 name=RunToolDialog_metaObject ====

undefined ** RunToolDialog_metaObject(long param_1)

{
  undefined **ppuVar1;
  
  if (*(long *)(*(long *)(param_1 + 8) + 0x28) != 0) {
    ppuVar1 = (undefined **)QObjectData::dynamicMetaObject();
    return ppuVar1;
  }
  return &PTR_staticMetaObject_011a38a0;
}


// ==== entry=00905bee orig=FUN_00905bee size=66 name=RunToolDialog_qt_metacast ====

char * RunToolDialog_qt_metacast(char *param_1,char *param_2)

{
  int iVar1;
  char *pcVar2;
  
  if (param_2 == (char *)0x0) {
    return (char *)0x0;
  }
  iVar1 = strcmp(param_2,"RunToolDialog");
  if (iVar1 == 0) {
    return param_1;
  }
  pcVar2 = (char *)QDialog::qt_metacast(param_1);
  return pcVar2;
}


// ==== entry=00905c30 orig=FUN_00905c30 size=5 name=RunToolDialog_qt_metacall ====

void QDialog::RunToolDialog_qt_metacall(void)

{
  qt_metacall();
  return;
}


// ==== entry=00905c36 name=FUN_00905c36 size=1 ====

void FUN_00905c36(void)

{
  return;
}


// ==== entry=00905c38 orig=FUN_00905c38 size=24 name=MaskDialog_metaObject ====

undefined ** MaskDialog_metaObject(long param_1)

{
  undefined **ppuVar1;
  
  if (*(long *)(*(long *)(param_1 + 8) + 0x28) != 0) {
    ppuVar1 = (undefined **)QObjectData::dynamicMetaObject();
    return ppuVar1;
  }
  return &PTR_staticMetaObject_011a3b00;
}


// ==== entry=00905c50 orig=FUN_00905c50 size=66 name=MaskDialog_qt_metacast ====

char * MaskDialog_qt_metacast(char *param_1,char *param_2)

{
  int iVar1;
  char *pcVar2;
  
  if (param_2 == (char *)0x0) {
    return (char *)0x0;
  }
  iVar1 = strcmp(param_2,"MaskDialog");
  if (iVar1 == 0) {
    return param_1;
  }
  pcVar2 = (char *)QWidget::qt_metacast(param_1);
  return pcVar2;
}


// ==== entry=00905c92 orig=FUN_00905c92 size=5 name=MaskDialog_qt_metacall ====

void QWidget::MaskDialog_qt_metacall(void)

{
  qt_metacall();
  return;
}


// ==== entry=00905c98 name=FUN_00905c98 size=1 ====

void FUN_00905c98(void)

{
  return;
}


// ==== entry=00905c9a orig=FUN_00905c9a size=24 name=InsertFileDialog_metaObject ====

undefined ** InsertFileDialog_metaObject(long param_1)

{
  undefined **ppuVar1;
  
  if (*(long *)(*(long *)(param_1 + 8) + 0x28) != 0) {
    ppuVar1 = (undefined **)QObjectData::dynamicMetaObject();
    return ppuVar1;
  }
  return &PTR_staticMetaObject_011a3d80;
}


// ==== entry=00905cb2 orig=FUN_00905cb2 size=66 name=InsertFileDialog_qt_metacast ====

char * InsertFileDialog_qt_metacast(char *param_1,char *param_2)

{
  int iVar1;
  char *pcVar2;
  
  if (param_2 == (char *)0x0) {
    return (char *)0x0;
  }
  iVar1 = strcmp(param_2,"InsertFileDialog");
  if (iVar1 == 0) {
    return param_1;
  }
  pcVar2 = (char *)QDialog::qt_metacast(param_1);
  return pcVar2;
}


// ==== entry=00905cf4 orig=FUN_00905cf4 size=5 name=InsertFileDialog_qt_metacall ====

void QDialog::InsertFileDialog_qt_metacall(void)

{
  qt_metacall();
  return;
}


// ==== entry=00905cfa name=FUN_00905cfa size=1 ====

void FUN_00905cfa(void)

{
  return;
}


// ==== entry=00905cfc orig=FUN_00905cfc size=24 name=SearchEngineDialog_metaObject ====

undefined ** SearchEngineDialog_metaObject(long param_1)

{
  undefined **ppuVar1;
  
  if (*(long *)(*(long *)(param_1 + 8) + 0x28) != 0) {
    ppuVar1 = (undefined **)QObjectData::dynamicMetaObject();
    return ppuVar1;
  }
  return &PTR_staticMetaObject_011a4000;
}


// ==== entry=00905d14 orig=FUN_00905d14 size=66 name=SearchEngineDialog_qt_metacast ====

char * SearchEngineDialog_qt_metacast(char *param_1,char *param_2)

{
  int iVar1;
  char *pcVar2;
  
  if (param_2 == (char *)0x0) {
    return (char *)0x0;
  }
  iVar1 = strcmp(param_2,"SearchEngineDialog");
  if (iVar1 == 0) {
    return param_1;
  }
  pcVar2 = (char *)QDialog::qt_metacast(param_1);
  return pcVar2;
}


// ==== entry=00905d56 orig=FUN_00905d56 size=5 name=SearchEngineDialog_qt_metacall ====

void QDialog::SearchEngineDialog_qt_metacall(void)

{
  qt_metacall();
  return;
}


// ==== entry=00905d5c orig=FUN_00905d5c size=29 name=SearchEngineDialog_dtor ====

void SearchEngineDialog_dtor(QDialog *param_1)

{
  *(undefined ***)param_1 = &SearchEngineDialog_vtable;
  *(undefined ***)(param_1 + 0x10) = &PTR_FUN_011a3fb0;
  QDialog::~QDialog(param_1);
  return;
}


// ==== entry=00905d79 name=FUN_00905d79 size=33 ====

void FUN_00905d79(undefined8 *param_1)

{
  param_1[-2] = &SearchEngineDialog_vtable;
  *param_1 = &PTR_FUN_011a3fb0;
  QDialog::~QDialog((QDialog *)(param_1 + -2));
  return;
}


// ==== entry=00905d9a orig=FUN_00905d9a size=47 name=SearchEngineDialog_dtor_deleting ====

void SearchEngineDialog_dtor_deleting(QDialog *param_1)

{
  *(undefined ***)param_1 = &SearchEngineDialog_vtable;
  *(undefined ***)(param_1 + 0x10) = &PTR_FUN_011a3fb0;
  QDialog::~QDialog(param_1);
  operator_delete(param_1,0x58);
  return;
}


// ==== entry=00905dc9 name=FUN_00905dc9 size=51 ====

void FUN_00905dc9(undefined8 *param_1)

{
  param_1[-2] = &SearchEngineDialog_vtable;
  *param_1 = &PTR_FUN_011a3fb0;
  QDialog::~QDialog((QDialog *)(param_1 + -2));
  operator_delete((QDialog *)(param_1 + -2),0x58);
  return;
}


// ==== entry=00905dfc name=FUN_00905dfc size=1 ====

void FUN_00905dfc(void)

{
  return;
}


// ==== entry=00905dfe orig=FUN_00905dfe size=24 name=SettingDialog_metaObject ====

undefined ** SettingDialog_metaObject(long param_1)

{
  undefined **ppuVar1;
  
  if (*(long *)(*(long *)(param_1 + 8) + 0x28) != 0) {
    ppuVar1 = (undefined **)QObjectData::dynamicMetaObject();
    return ppuVar1;
  }
  return &PTR_staticMetaObject_011a4280;
}


// ==== entry=00905e16 orig=FUN_00905e16 size=66 name=SettingDialog_qt_metacast ====

char * SettingDialog_qt_metacast(char *param_1,char *param_2)

{
  int iVar1;
  char *pcVar2;
  
  if (param_2 == (char *)0x0) {
    return (char *)0x0;
  }
  iVar1 = strcmp(param_2,"SettingDialog");
  if (iVar1 == 0) {
    return param_1;
  }
  pcVar2 = (char *)QDialog::qt_metacast(param_1);
  return pcVar2;
}


// ==== entry=00905e58 orig=FUN_00905e58 size=5 name=SettingDialog_qt_metacall ====

void QDialog::SettingDialog_qt_metacall(void)

{
  qt_metacall();
  return;
}


// ==== entry=00905e5e orig=FUN_00905e5e size=5813 name=SettingDialog_dtor ====

void SettingDialog_dtor(QDialog *param_1)

{
  long lVar1;
  long lVar2;
  long lVar3;
  long lVar4;
  long lVar5;
  long lVar6;
  QMapNodeBase *pQVar7;
  QArrayData *pQVar8;
  
  *(undefined ***)param_1 = &SettingDialog_vtable;
  *(undefined ***)(param_1 + 0x10) = &PTR_FUN_011a4230;
  if (*(long *)(param_1 + 0x68) != 0) {
    FUN_006ec54c(param_1 + 0x68);
  }
  pQVar7 = *(QMapNodeBase **)(param_1 + 0x40);
  if (*(int *)pQVar7 != 0) {
    if (*(int *)pQVar7 == -1) goto LAB_00905eb0;
    LOCK();
    *(int *)pQVar7 = *(int *)pQVar7 + -1;
    UNLOCK();
    if (*(int *)pQVar7 != 0) goto LAB_00905eb0;
    pQVar7 = *(QMapNodeBase **)(param_1 + 0x40);
  }
  lVar1 = *(long *)(pQVar7 + 0x10);
  if (lVar1 != 0) {
    pQVar8 = *(QArrayData **)(lVar1 + 0x18);
    if (*(int *)pQVar8 == 0) {
LAB_00906f19:
      QArrayData::deallocate(pQVar8,2,8);
    }
    else if (*(int *)pQVar8 != -1) {
      LOCK();
      *(int *)pQVar8 = *(int *)pQVar8 + -1;
      UNLOCK();
      if (*(int *)pQVar8 == 0) {
        pQVar8 = *(QArrayData **)(lVar1 + 0x18);
        goto LAB_00906f19;
      }
    }
    QVariant::~QVariant((QVariant *)(lVar1 + 0x20));
    lVar2 = *(long *)(lVar1 + 8);
    if (lVar2 != 0) {
      pQVar8 = *(QArrayData **)(lVar2 + 0x18);
      if (*(int *)pQVar8 == 0) {
LAB_00905f26:
        QArrayData::deallocate(pQVar8,2,8);
      }
      else if (*(int *)pQVar8 != -1) {
        LOCK();
        *(int *)pQVar8 = *(int *)pQVar8 + -1;
        UNLOCK();
        if (*(int *)pQVar8 == 0) {
          pQVar8 = *(QArrayData **)(lVar2 + 0x18);
          goto LAB_00905f26;
        }
      }
      QVariant::~QVariant((QVariant *)(lVar2 + 0x20));
      lVar3 = *(long *)(lVar2 + 8);
      if (lVar3 != 0) {
        pQVar8 = *(QArrayData **)(lVar3 + 0x18);
        if (*(int *)pQVar8 == 0) {
LAB_00906f61:
          QArrayData::deallocate(pQVar8,2,8);
        }
        else if (*(int *)pQVar8 != -1) {
          LOCK();
          *(int *)pQVar8 = *(int *)pQVar8 + -1;
          UNLOCK();
          if (*(int *)pQVar8 == 0) {
            pQVar8 = *(QArrayData **)(lVar3 + 0x18);
            goto LAB_00906f61;
          }
        }
        QVariant::~QVariant((QVariant *)(lVar3 + 0x20));
        lVar4 = *(long *)(lVar3 + 8);
        if (lVar4 != 0) {
          pQVar8 = *(QArrayData **)(lVar4 + 0x18);
          if (*(int *)pQVar8 == 0) {
LAB_0090700b:
            QArrayData::deallocate(pQVar8,2,8);
          }
          else if (*(int *)pQVar8 != -1) {
            LOCK();
            *(int *)pQVar8 = *(int *)pQVar8 + -1;
            UNLOCK();
            if (*(int *)pQVar8 == 0) {
              pQVar8 = *(QArrayData **)(lVar4 + 0x18);
              goto LAB_0090700b;
            }
          }
          QVariant::~QVariant((QVariant *)(lVar4 + 0x20));
          lVar5 = *(long *)(lVar4 + 8);
          if (lVar5 != 0) {
            pQVar8 = *(QArrayData **)(lVar5 + 0x18);
            if (*(int *)pQVar8 == 0) {
LAB_009070e4:
              QArrayData::deallocate(pQVar8,2,8);
            }
            else if (*(int *)pQVar8 != -1) {
              LOCK();
              *(int *)pQVar8 = *(int *)pQVar8 + -1;
              UNLOCK();
              if (*(int *)pQVar8 == 0) {
                pQVar8 = *(QArrayData **)(lVar5 + 0x18);
                goto LAB_009070e4;
              }
            }
            QVariant::~QVariant((QVariant *)(lVar5 + 0x20));
            lVar6 = *(long *)(lVar5 + 8);
            if (lVar6 != 0) {
              pQVar8 = *(QArrayData **)(lVar6 + 0x18);
              if (*(int *)pQVar8 == 0) {
LAB_009073a5:
                QArrayData::deallocate(pQVar8,2,8);
              }
              else if (*(int *)pQVar8 != -1) {
                LOCK();
                *(int *)pQVar8 = *(int *)pQVar8 + -1;
                UNLOCK();
                if (*(int *)pQVar8 == 0) {
                  pQVar8 = *(QArrayData **)(lVar6 + 0x18);
                  goto LAB_009073a5;
                }
              }
              QVariant::~QVariant((QVariant *)(lVar6 + 0x20));
              if (*(long *)(lVar6 + 8) != 0) {
                FUN_00528bb6();
              }
              if (*(long *)(lVar6 + 0x10) != 0) {
                FUN_00528bb6();
              }
            }
            lVar5 = *(long *)(lVar5 + 0x10);
            if (lVar5 != 0) {
              pQVar8 = *(QArrayData **)(lVar5 + 0x18);
              if (*(int *)pQVar8 == 0) {
LAB_009073e7:
                QArrayData::deallocate(pQVar8,2,8);
              }
              else if (*(int *)pQVar8 != -1) {
                LOCK();
                *(int *)pQVar8 = *(int *)pQVar8 + -1;
                UNLOCK();
                if (*(int *)pQVar8 == 0) {
                  pQVar8 = *(QArrayData **)(lVar5 + 0x18);
                  goto LAB_009073e7;
                }
              }
              QVariant::~QVariant((QVariant *)(lVar5 + 0x20));
              if (*(long *)(lVar5 + 8) != 0) {
                FUN_00528bb6();
              }
              if (*(long *)(lVar5 + 0x10) != 0) {
                FUN_00528bb6();
              }
            }
          }
          lVar4 = *(long *)(lVar4 + 0x10);
          if (lVar4 != 0) {
            pQVar8 = *(QArrayData **)(lVar4 + 0x18);
            if (*(int *)pQVar8 == 0) {
LAB_0090714c:
              QArrayData::deallocate(pQVar8,2,8);
            }
            else if (*(int *)pQVar8 != -1) {
              LOCK();
              *(int *)pQVar8 = *(int *)pQVar8 + -1;
              UNLOCK();
              if (*(int *)pQVar8 == 0) {
                pQVar8 = *(QArrayData **)(lVar4 + 0x18);
                goto LAB_0090714c;
              }
            }
            QVariant::~QVariant((QVariant *)(lVar4 + 0x20));
            lVar5 = *(long *)(lVar4 + 8);
            if (lVar5 != 0) {
              pQVar8 = *(QArrayData **)(lVar5 + 0x18);
              if (*(int *)pQVar8 == 0) {
LAB_009071f4:
                QArrayData::deallocate(pQVar8,2,8);
              }
              else if (*(int *)pQVar8 != -1) {
                LOCK();
                *(int *)pQVar8 = *(int *)pQVar8 + -1;
                UNLOCK();
                if (*(int *)pQVar8 == 0) {
                  pQVar8 = *(QArrayData **)(lVar5 + 0x18);
                  goto LAB_009071f4;
                }
              }
              QVariant::~QVariant((QVariant *)(lVar5 + 0x20));
              if (*(long *)(lVar5 + 8) != 0) {
                FUN_00528bb6();
              }
              if (*(long *)(lVar5 + 0x10) != 0) {
                FUN_00528bb6();
              }
            }
            lVar4 = *(long *)(lVar4 + 0x10);
            if (lVar4 != 0) {
              pQVar8 = *(QArrayData **)(lVar4 + 0x18);
              if (*(int *)pQVar8 == 0) {
LAB_009073cf:
                QArrayData::deallocate(pQVar8,2,8);
              }
              else if (*(int *)pQVar8 != -1) {
                LOCK();
                *(int *)pQVar8 = *(int *)pQVar8 + -1;
                UNLOCK();
                if (*(int *)pQVar8 == 0) {
                  pQVar8 = *(QArrayData **)(lVar4 + 0x18);
                  goto LAB_009073cf;
                }
              }
              QVariant::~QVariant((QVariant *)(lVar4 + 0x20));
              if (*(long *)(lVar4 + 8) != 0) {
                FUN_00528bb6();
              }
              if (*(long *)(lVar4 + 0x10) != 0) {
                FUN_00528bb6();
              }
            }
          }
        }
        lVar3 = *(long *)(lVar3 + 0x10);
        if (lVar3 != 0) {
          pQVar8 = *(QArrayData **)(lVar3 + 0x18);
          if (*(int *)pQVar8 == 0) {
LAB_00907023:
            QArrayData::deallocate(pQVar8,2,8);
          }
          else if (*(int *)pQVar8 != -1) {
            LOCK();
            *(int *)pQVar8 = *(int *)pQVar8 + -1;
            UNLOCK();
            if (*(int *)pQVar8 == 0) {
              pQVar8 = *(QArrayData **)(lVar3 + 0x18);
              goto LAB_00907023;
            }
          }
          QVariant::~QVariant((QVariant *)(lVar3 + 0x20));
          lVar4 = *(long *)(lVar3 + 8);
          if (lVar4 != 0) {
            pQVar8 = *(QArrayData **)(lVar4 + 0x18);
            if (*(int *)pQVar8 == 0) {
LAB_00907164:
              QArrayData::deallocate(pQVar8,2,8);
            }
            else if (*(int *)pQVar8 != -1) {
              LOCK();
              *(int *)pQVar8 = *(int *)pQVar8 + -1;
              UNLOCK();
              if (*(int *)pQVar8 == 0) {
                pQVar8 = *(QArrayData **)(lVar4 + 0x18);
                goto LAB_00907164;
              }
            }
            QVariant::~QVariant((QVariant *)(lVar4 + 0x20));
            lVar5 = *(long *)(lVar4 + 8);
            if (lVar5 != 0) {
              pQVar8 = *(QArrayData **)(lVar5 + 0x18);
              if (*(int *)pQVar8 == 0) {
LAB_0090722c:
                QArrayData::deallocate(pQVar8,2,8);
              }
              else if (*(int *)pQVar8 != -1) {
                LOCK();
                *(int *)pQVar8 = *(int *)pQVar8 + -1;
                UNLOCK();
                if (*(int *)pQVar8 == 0) {
                  pQVar8 = *(QArrayData **)(lVar5 + 0x18);
                  goto LAB_0090722c;
                }
              }
              QVariant::~QVariant((QVariant *)(lVar5 + 0x20));
              if (*(long *)(lVar5 + 8) != 0) {
                FUN_00528bb6();
              }
              if (*(long *)(lVar5 + 0x10) != 0) {
                FUN_00528bb6();
              }
            }
            lVar4 = *(long *)(lVar4 + 0x10);
            if (lVar4 != 0) {
              pQVar8 = *(QArrayData **)(lVar4 + 0x18);
              if (*(int *)pQVar8 == 0) {
LAB_00907214:
                QArrayData::deallocate(pQVar8,2,8);
              }
              else if (*(int *)pQVar8 != -1) {
                LOCK();
                *(int *)pQVar8 = *(int *)pQVar8 + -1;
                UNLOCK();
                if (*(int *)pQVar8 == 0) {
                  pQVar8 = *(QArrayData **)(lVar4 + 0x18);
                  goto LAB_00907214;
                }
              }
              QVariant::~QVariant((QVariant *)(lVar4 + 0x20));
              if (*(long *)(lVar4 + 8) != 0) {
                FUN_00528bb6();
              }
              if (*(long *)(lVar4 + 0x10) != 0) {
                FUN_00528bb6();
              }
            }
          }
          lVar3 = *(long *)(lVar3 + 0x10);
          if (lVar3 != 0) {
            pQVar8 = *(QArrayData **)(lVar3 + 0x18);
            if (*(int *)pQVar8 == 0) {
LAB_0090717c:
              QArrayData::deallocate(pQVar8,2,8);
            }
            else if (*(int *)pQVar8 != -1) {
              LOCK();
              *(int *)pQVar8 = *(int *)pQVar8 + -1;
              UNLOCK();
              if (*(int *)pQVar8 == 0) {
                pQVar8 = *(QArrayData **)(lVar3 + 0x18);
                goto LAB_0090717c;
              }
            }
            QVariant::~QVariant((QVariant *)(lVar3 + 0x20));
            lVar4 = *(long *)(lVar3 + 8);
            if (lVar4 != 0) {
              pQVar8 = *(QArrayData **)(lVar4 + 0x18);
              if (*(int *)pQVar8 == 0) {
LAB_009074cf:
                QArrayData::deallocate(pQVar8,2,8);
              }
              else if (*(int *)pQVar8 != -1) {
                LOCK();
                *(int *)pQVar8 = *(int *)pQVar8 + -1;
                UNLOCK();
                if (*(int *)pQVar8 == 0) {
                  pQVar8 = *(QArrayData **)(lVar4 + 0x18);
                  goto LAB_009074cf;
                }
              }
              QVariant::~QVariant((QVariant *)(lVar4 + 0x20));
              if (*(long *)(lVar4 + 8) != 0) {
                FUN_00528bb6();
              }
              if (*(long *)(lVar4 + 0x10) != 0) {
                FUN_00528bb6();
              }
            }
            lVar3 = *(long *)(lVar3 + 0x10);
            if (lVar3 != 0) {
              pQVar8 = *(QArrayData **)(lVar3 + 0x18);
              if (*(int *)pQVar8 == 0) {
LAB_00907344:
                QArrayData::deallocate(pQVar8,2,8);
              }
              else if (*(int *)pQVar8 != -1) {
                LOCK();
                *(int *)pQVar8 = *(int *)pQVar8 + -1;
                UNLOCK();
                if (*(int *)pQVar8 == 0) {
                  pQVar8 = *(QArrayData **)(lVar3 + 0x18);
                  goto LAB_00907344;
                }
              }
              QVariant::~QVariant((QVariant *)(lVar3 + 0x20));
              if (*(long *)(lVar3 + 8) != 0) {
                FUN_00528bb6();
              }
              if (*(long *)(lVar3 + 0x10) != 0) {
                FUN_00528bb6();
              }
            }
          }
        }
      }
      lVar2 = *(long *)(lVar2 + 0x10);
      if (lVar2 != 0) {
        pQVar8 = *(QArrayData **)(lVar2 + 0x18);
        if (*(int *)pQVar8 == 0) {
LAB_00906f49:
          QArrayData::deallocate(pQVar8,2,8);
        }
        else if (*(int *)pQVar8 != -1) {
          LOCK();
          *(int *)pQVar8 = *(int *)pQVar8 + -1;
          UNLOCK();
          if (*(int *)pQVar8 == 0) {
            pQVar8 = *(QArrayData **)(lVar2 + 0x18);
            goto LAB_00906f49;
          }
        }
        QVariant::~QVariant((QVariant *)(lVar2 + 0x20));
        lVar3 = *(long *)(lVar2 + 8);
        if (lVar3 != 0) {
          pQVar8 = *(QArrayData **)(lVar3 + 0x18);
          if (*(int *)pQVar8 == 0) {
LAB_00906fda:
            QArrayData::deallocate(pQVar8,2,8);
          }
          else if (*(int *)pQVar8 != -1) {
            LOCK();
            *(int *)pQVar8 = *(int *)pQVar8 + -1;
            UNLOCK();
            if (*(int *)pQVar8 == 0) {
              pQVar8 = *(QArrayData **)(lVar3 + 0x18);
              goto LAB_00906fda;
            }
          }
          QVariant::~QVariant((QVariant *)(lVar3 + 0x20));
          lVar4 = *(long *)(lVar3 + 8);
          if (lVar4 != 0) {
            pQVar8 = *(QArrayData **)(lVar4 + 0x18);
            if (*(int *)pQVar8 == 0) {
LAB_009071c4:
              QArrayData::deallocate(pQVar8,2,8);
            }
            else if (*(int *)pQVar8 != -1) {
              LOCK();
              *(int *)pQVar8 = *(int *)pQVar8 + -1;
              UNLOCK();
              if (*(int *)pQVar8 == 0) {
                pQVar8 = *(QArrayData **)(lVar4 + 0x18);
                goto LAB_009071c4;
              }
            }
            QVariant::~QVariant((QVariant *)(lVar4 + 0x20));
            lVar5 = *(long *)(lVar4 + 8);
            if (lVar5 != 0) {
              pQVar8 = *(QArrayData **)(lVar5 + 0x18);
              if (*(int *)pQVar8 == 0) {
LAB_0090744f:
                QArrayData::deallocate(pQVar8,2,8);
              }
              else if (*(int *)pQVar8 != -1) {
                LOCK();
                *(int *)pQVar8 = *(int *)pQVar8 + -1;
                UNLOCK();
                if (*(int *)pQVar8 == 0) {
                  pQVar8 = *(QArrayData **)(lVar5 + 0x18);
                  goto LAB_0090744f;
                }
              }
              QVariant::~QVariant((QVariant *)(lVar5 + 0x20));
              if (*(long *)(lVar5 + 8) != 0) {
                FUN_00528bb6();
              }
              if (*(long *)(lVar5 + 0x10) != 0) {
                FUN_00528bb6();
              }
            }
            lVar4 = *(long *)(lVar4 + 0x10);
            if (lVar4 != 0) {
              pQVar8 = *(QArrayData **)(lVar4 + 0x18);
              if (*(int *)pQVar8 == 0) {
LAB_00907437:
                QArrayData::deallocate(pQVar8,2,8);
              }
              else if (*(int *)pQVar8 != -1) {
                LOCK();
                *(int *)pQVar8 = *(int *)pQVar8 + -1;
                UNLOCK();
                if (*(int *)pQVar8 == 0) {
                  pQVar8 = *(QArrayData **)(lVar4 + 0x18);
                  goto LAB_00907437;
                }
              }
              QVariant::~QVariant((QVariant *)(lVar4 + 0x20));
              if (*(long *)(lVar4 + 8) != 0) {
                FUN_00528bb6();
              }
              if (*(long *)(lVar4 + 0x10) != 0) {
                FUN_00528bb6();
              }
            }
          }
          lVar3 = *(long *)(lVar3 + 0x10);
          if (lVar3 != 0) {
            pQVar8 = *(QArrayData **)(lVar3 + 0x18);
            if (*(int *)pQVar8 == 0) {
LAB_009071ac:
              QArrayData::deallocate(pQVar8,2,8);
            }
            else if (*(int *)pQVar8 != -1) {
              LOCK();
              *(int *)pQVar8 = *(int *)pQVar8 + -1;
              UNLOCK();
              if (*(int *)pQVar8 == 0) {
                pQVar8 = *(QArrayData **)(lVar3 + 0x18);
                goto LAB_009071ac;
              }
            }
            QVariant::~QVariant((QVariant *)(lVar3 + 0x20));
            lVar4 = *(long *)(lVar3 + 8);
            if (lVar4 != 0) {
              pQVar8 = *(QArrayData **)(lVar4 + 0x18);
              if (*(int *)pQVar8 == 0) {
LAB_0090732c:
                QArrayData::deallocate(pQVar8,2,8);
              }
              else if (*(int *)pQVar8 != -1) {
                LOCK();
                *(int *)pQVar8 = *(int *)pQVar8 + -1;
                UNLOCK();
                if (*(int *)pQVar8 == 0) {
                  pQVar8 = *(QArrayData **)(lVar4 + 0x18);
                  goto LAB_0090732c;
                }
              }
              QVariant::~QVariant((QVariant *)(lVar4 + 0x20));
              if (*(long *)(lVar4 + 8) != 0) {
                FUN_00528bb6();
              }
              if (*(long *)(lVar4 + 0x10) != 0) {
                FUN_00528bb6();
              }
            }
            lVar3 = *(long *)(lVar3 + 0x10);
            if (lVar3 != 0) {
              pQVar8 = *(QArrayData **)(lVar3 + 0x18);
              if (*(int *)pQVar8 == 0) {
LAB_00907314:
                QArrayData::deallocate(pQVar8,2,8);
              }
              else if (*(int *)pQVar8 != -1) {
                LOCK();
                *(int *)pQVar8 = *(int *)pQVar8 + -1;
                UNLOCK();
                if (*(int *)pQVar8 == 0) {
                  pQVar8 = *(QArrayData **)(lVar3 + 0x18);
                  goto LAB_00907314;
                }
              }
              QVariant::~QVariant((QVariant *)(lVar3 + 0x20));
              if (*(long *)(lVar3 + 8) != 0) {
                FUN_00528bb6();
              }
              if (*(long *)(lVar3 + 0x10) != 0) {
                FUN_00528bb6();
              }
            }
          }
        }
        lVar2 = *(long *)(lVar2 + 0x10);
        if (lVar2 != 0) {
          pQVar8 = *(QArrayData **)(lVar2 + 0x18);
          if (*(int *)pQVar8 == 0) {
LAB_00906fc2:
            QArrayData::deallocate(pQVar8,2,8);
          }
          else if (*(int *)pQVar8 != -1) {
            LOCK();
            *(int *)pQVar8 = *(int *)pQVar8 + -1;
            UNLOCK();
            if (*(int *)pQVar8 == 0) {
              pQVar8 = *(QArrayData **)(lVar2 + 0x18);
              goto LAB_00906fc2;
            }
          }
          QVariant::~QVariant((QVariant *)(lVar2 + 0x20));
          lVar3 = *(long *)(lVar2 + 8);
          if (lVar3 != 0) {
            pQVar8 = *(QArrayData **)(lVar3 + 0x18);
            if (*(int *)pQVar8 == 0) {
LAB_0090706c:
              QArrayData::deallocate(pQVar8,2,8);
            }
            else if (*(int *)pQVar8 != -1) {
              LOCK();
              *(int *)pQVar8 = *(int *)pQVar8 + -1;
              UNLOCK();
              if (*(int *)pQVar8 == 0) {
                pQVar8 = *(QArrayData **)(lVar3 + 0x18);
                goto LAB_0090706c;
              }
            }
            QVariant::~QVariant((QVariant *)(lVar3 + 0x20));
            lVar4 = *(long *)(lVar3 + 8);
            if (lVar4 != 0) {
              pQVar8 = *(QArrayData **)(lVar4 + 0x18);
              if (*(int *)pQVar8 == 0) {
LAB_0090741f:
                QArrayData::deallocate(pQVar8,2,8);
              }
              else if (*(int *)pQVar8 != -1) {
                LOCK();
                *(int *)pQVar8 = *(int *)pQVar8 + -1;
                UNLOCK();
                if (*(int *)pQVar8 == 0) {
                  pQVar8 = *(QArrayData **)(lVar4 + 0x18);
                  goto LAB_0090741f;
                }
              }
              QVariant::~QVariant((QVariant *)(lVar4 + 0x20));
              if (*(long *)(lVar4 + 8) != 0) {
                FUN_00528bb6();
              }
              if (*(long *)(lVar4 + 0x10) != 0) {
                FUN_00528bb6();
              }
            }
            lVar3 = *(long *)(lVar3 + 0x10);
            if (lVar3 != 0) {
              pQVar8 = *(QArrayData **)(lVar3 + 0x18);
              if (*(int *)pQVar8 == 0) {
LAB_00907407:
                QArrayData::deallocate(pQVar8,2,8);
              }
              else if (*(int *)pQVar8 != -1) {
                LOCK();
                *(int *)pQVar8 = *(int *)pQVar8 + -1;
                UNLOCK();
                if (*(int *)pQVar8 == 0) {
                  pQVar8 = *(QArrayData **)(lVar3 + 0x18);
                  goto LAB_00907407;
                }
              }
              QVariant::~QVariant((QVariant *)(lVar3 + 0x20));
              if (*(long *)(lVar3 + 8) != 0) {
                FUN_00528bb6();
              }
              if (*(long *)(lVar3 + 0x10) != 0) {
                FUN_00528bb6();
              }
            }
          }
          lVar2 = *(long *)(lVar2 + 0x10);
          if (lVar2 != 0) {
            pQVar8 = *(QArrayData **)(lVar2 + 0x18);
            if (*(int *)pQVar8 == 0) {
LAB_00907084:
              QArrayData::deallocate(pQVar8,2,8);
            }
            else if (*(int *)pQVar8 != -1) {
              LOCK();
              *(int *)pQVar8 = *(int *)pQVar8 + -1;
              UNLOCK();
              if (*(int *)pQVar8 == 0) {
                pQVar8 = *(QArrayData **)(lVar2 + 0x18);
                goto LAB_00907084;
              }
            }
            QVariant::~QVariant((QVariant *)(lVar2 + 0x20));
            lVar3 = *(long *)(lVar2 + 8);
            if (lVar3 != 0) {
              pQVar8 = *(QArrayData **)(lVar3 + 0x18);
              if (*(int *)pQVar8 == 0) {
LAB_009072cc:
                QArrayData::deallocate(pQVar8,2,8);
              }
              else if (*(int *)pQVar8 != -1) {
                LOCK();
                *(int *)pQVar8 = *(int *)pQVar8 + -1;
                UNLOCK();
                if (*(int *)pQVar8 == 0) {
                  pQVar8 = *(QArrayData **)(lVar3 + 0x18);
                  goto LAB_009072cc;
                }
              }
              QVariant::~QVariant((QVariant *)(lVar3 + 0x20));
              if (*(long *)(lVar3 + 8) != 0) {
                FUN_00528bb6();
              }
              if (*(long *)(lVar3 + 0x10) != 0) {
                FUN_00528bb6();
              }
            }
            lVar2 = *(long *)(lVar2 + 0x10);
            if (lVar2 != 0) {
              pQVar8 = *(QArrayData **)(lVar2 + 0x18);
              if (*(int *)pQVar8 == 0) {
LAB_009074b7:
                QArrayData::deallocate(pQVar8,2,8);
              }
              else if (*(int *)pQVar8 != -1) {
                LOCK();
                *(int *)pQVar8 = *(int *)pQVar8 + -1;
                UNLOCK();
                if (*(int *)pQVar8 == 0) {
                  pQVar8 = *(QArrayData **)(lVar2 + 0x18);
                  goto LAB_009074b7;
                }
              }
              QVariant::~QVariant((QVariant *)(lVar2 + 0x20));
              if (*(long *)(lVar2 + 8) != 0) {
                FUN_00528bb6();
              }
              if (*(long *)(lVar2 + 0x10) != 0) {
                FUN_00528bb6();
              }
            }
          }
        }
      }
    }
    lVar1 = *(long *)(lVar1 + 0x10);
    if (lVar1 != 0) {
      pQVar8 = *(QArrayData **)(lVar1 + 0x18);
      if (*(int *)pQVar8 == 0) {
LAB_00906745:
        QArrayData::deallocate(pQVar8,2,8);
      }
      else if (*(int *)pQVar8 != -1) {
        LOCK();
        *(int *)pQVar8 = *(int *)pQVar8 + -1;
        UNLOCK();
        if (*(int *)pQVar8 == 0) {
          pQVar8 = *(QArrayData **)(lVar1 + 0x18);
          goto LAB_00906745;
        }
      }
      QVariant::~QVariant((QVariant *)(lVar1 + 0x20));
      lVar2 = *(long *)(lVar1 + 8);
      if (lVar2 != 0) {
        pQVar8 = *(QArrayData **)(lVar2 + 0x18);
        if (*(int *)pQVar8 == 0) {
LAB_00906f31:
          QArrayData::deallocate(pQVar8,2,8);
        }
        else if (*(int *)pQVar8 != -1) {
          LOCK();
          *(int *)pQVar8 = *(int *)pQVar8 + -1;
          UNLOCK();
          if (*(int *)pQVar8 == 0) {
            pQVar8 = *(QArrayData **)(lVar2 + 0x18);
            goto LAB_00906f31;
          }
        }
        QVariant::~QVariant((QVariant *)(lVar2 + 0x20));
        lVar3 = *(long *)(lVar2 + 8);
        if (lVar3 != 0) {
          pQVar8 = *(QArrayData **)(lVar3 + 0x18);
          if (*(int *)pQVar8 == 0) {
LAB_00906f92:
            QArrayData::deallocate(pQVar8,2,8);
          }
          else if (*(int *)pQVar8 != -1) {
            LOCK();
            *(int *)pQVar8 = *(int *)pQVar8 + -1;
            UNLOCK();
            if (*(int *)pQVar8 == 0) {
              pQVar8 = *(QArrayData **)(lVar3 + 0x18);
              goto LAB_00906f92;
            }
          }
          QVariant::~QVariant((QVariant *)(lVar3 + 0x20));
          lVar4 = *(long *)(lVar3 + 8);
          if (lVar4 != 0) {
            pQVar8 = *(QArrayData **)(lVar4 + 0x18);
            if (*(int *)pQVar8 == 0) {
LAB_009070b4:
              QArrayData::deallocate(pQVar8,2,8);
            }
            else if (*(int *)pQVar8 != -1) {
              LOCK();
              *(int *)pQVar8 = *(int *)pQVar8 + -1;
              UNLOCK();
              if (*(int *)pQVar8 == 0) {
                pQVar8 = *(QArrayData **)(lVar4 + 0x18);
                goto LAB_009070b4;
              }
            }
            QVariant::~QVariant((QVariant *)(lVar4 + 0x20));
            lVar5 = *(long *)(lVar4 + 8);
            if (lVar5 != 0) {
              pQVar8 = *(QArrayData **)(lVar5 + 0x18);
              if (*(int *)pQVar8 == 0) {
LAB_0090727c:
                QArrayData::deallocate(pQVar8,2,8);
              }
              else if (*(int *)pQVar8 != -1) {
                LOCK();
                *(int *)pQVar8 = *(int *)pQVar8 + -1;
                UNLOCK();
                if (*(int *)pQVar8 == 0) {
                  pQVar8 = *(QArrayData **)(lVar5 + 0x18);
                  goto LAB_0090727c;
                }
              }
              QVariant::~QVariant((QVariant *)(lVar5 + 0x20));
              if (*(long *)(lVar5 + 8) != 0) {
                FUN_00528bb6();
              }
              if (*(long *)(lVar5 + 0x10) != 0) {
                FUN_00528bb6();
              }
            }
            lVar4 = *(long *)(lVar4 + 0x10);
            if (lVar4 != 0) {
              pQVar8 = *(QArrayData **)(lVar4 + 0x18);
              if (*(int *)pQVar8 == 0) {
LAB_0090738d:
                QArrayData::deallocate(pQVar8,2,8);
              }
              else if (*(int *)pQVar8 != -1) {
                LOCK();
                *(int *)pQVar8 = *(int *)pQVar8 + -1;
                UNLOCK();
                if (*(int *)pQVar8 == 0) {
                  pQVar8 = *(QArrayData **)(lVar4 + 0x18);
                  goto LAB_0090738d;
                }
              }
              QVariant::~QVariant((QVariant *)(lVar4 + 0x20));
              if (*(long *)(lVar4 + 8) != 0) {
                FUN_00528bb6();
              }
              if (*(long *)(lVar4 + 0x10) != 0) {
                FUN_00528bb6();
              }
            }
          }
          lVar3 = *(long *)(lVar3 + 0x10);
          if (lVar3 != 0) {
            pQVar8 = *(QArrayData **)(lVar3 + 0x18);
            if (*(int *)pQVar8 == 0) {
LAB_0090709c:
              QArrayData::deallocate(pQVar8,2,8);
            }
            else if (*(int *)pQVar8 != -1) {
              LOCK();
              *(int *)pQVar8 = *(int *)pQVar8 + -1;
              UNLOCK();
              if (*(int *)pQVar8 == 0) {
                pQVar8 = *(QArrayData **)(lVar3 + 0x18);
                goto LAB_0090709c;
              }
            }
            QVariant::~QVariant((QVariant *)(lVar3 + 0x20));
            lVar4 = *(long *)(lVar3 + 8);
            if (lVar4 != 0) {
              pQVar8 = *(QArrayData **)(lVar4 + 0x18);
              if (*(int *)pQVar8 == 0) {
LAB_009074ff:
                QArrayData::deallocate(pQVar8,2,8);
              }
              else if (*(int *)pQVar8 != -1) {
                LOCK();
                *(int *)pQVar8 = *(int *)pQVar8 + -1;
                UNLOCK();
                if (*(int *)pQVar8 == 0) {
                  pQVar8 = *(QArrayData **)(lVar4 + 0x18);
                  goto LAB_009074ff;
                }
              }
              QVariant::~QVariant((QVariant *)(lVar4 + 0x20));
              if (*(long *)(lVar4 + 8) != 0) {
                FUN_00528bb6();
              }
              if (*(long *)(lVar4 + 0x10) != 0) {
                FUN_00528bb6();
              }
            }
            lVar3 = *(long *)(lVar3 + 0x10);
            if (lVar3 != 0) {
              pQVar8 = *(QArrayData **)(lVar3 + 0x18);
              if (*(int *)pQVar8 == 0) {
LAB_009074e7:
                QArrayData::deallocate(pQVar8,2,8);
              }
              else if (*(int *)pQVar8 != -1) {
                LOCK();
                *(int *)pQVar8 = *(int *)pQVar8 + -1;
                UNLOCK();
                if (*(int *)pQVar8 == 0) {
                  pQVar8 = *(QArrayData **)(lVar3 + 0x18);
                  goto LAB_009074e7;
                }
              }
              QVariant::~QVariant((QVariant *)(lVar3 + 0x20));
              if (*(long *)(lVar3 + 8) != 0) {
                FUN_00528bb6();
              }
              if (*(long *)(lVar3 + 0x10) != 0) {
                FUN_00528bb6();
              }
            }
          }
        }
        lVar2 = *(long *)(lVar2 + 0x10);
        if (lVar2 != 0) {
          pQVar8 = *(QArrayData **)(lVar2 + 0x18);
          if (*(int *)pQVar8 == 0) {
LAB_00906faa:
            QArrayData::deallocate(pQVar8,2,8);
          }
          else if (*(int *)pQVar8 != -1) {
            LOCK();
            *(int *)pQVar8 = *(int *)pQVar8 + -1;
            UNLOCK();
            if (*(int *)pQVar8 == 0) {
              pQVar8 = *(QArrayData **)(lVar2 + 0x18);
              goto LAB_00906faa;
            }
          }
          QVariant::~QVariant((QVariant *)(lVar2 + 0x20));
          lVar3 = *(long *)(lVar2 + 8);
          if (lVar3 != 0) {
            pQVar8 = *(QArrayData **)(lVar3 + 0x18);
            if (*(int *)pQVar8 == 0) {
LAB_00907194:
              QArrayData::deallocate(pQVar8,2,8);
            }
            else if (*(int *)pQVar8 != -1) {
              LOCK();
              *(int *)pQVar8 = *(int *)pQVar8 + -1;
              UNLOCK();
              if (*(int *)pQVar8 == 0) {
                pQVar8 = *(QArrayData **)(lVar3 + 0x18);
                goto LAB_00907194;
              }
            }
            QVariant::~QVariant((QVariant *)(lVar3 + 0x20));
            lVar4 = *(long *)(lVar3 + 8);
            if (lVar4 != 0) {
              pQVar8 = *(QArrayData **)(lVar4 + 0x18);
              if (*(int *)pQVar8 == 0) {
LAB_00907487:
                QArrayData::deallocate(pQVar8,2,8);
              }
              else if (*(int *)pQVar8 != -1) {
                LOCK();
                *(int *)pQVar8 = *(int *)pQVar8 + -1;
                UNLOCK();
                if (*(int *)pQVar8 == 0) {
                  pQVar8 = *(QArrayData **)(lVar4 + 0x18);
                  goto LAB_00907487;
                }
              }
              QVariant::~QVariant((QVariant *)(lVar4 + 0x20));
              if (*(long *)(lVar4 + 8) != 0) {
                FUN_00528bb6();
              }
              if (*(long *)(lVar4 + 0x10) != 0) {
                FUN_00528bb6();
              }
            }
            lVar3 = *(long *)(lVar3 + 0x10);
            if (lVar3 != 0) {
              pQVar8 = *(QArrayData **)(lVar3 + 0x18);
              if (*(int *)pQVar8 == 0) {
LAB_0090746f:
                QArrayData::deallocate(pQVar8,2,8);
              }
              else if (*(int *)pQVar8 != -1) {
                LOCK();
                *(int *)pQVar8 = *(int *)pQVar8 + -1;
                UNLOCK();
                if (*(int *)pQVar8 == 0) {
                  pQVar8 = *(QArrayData **)(lVar3 + 0x18);
                  goto LAB_0090746f;
                }
              }
              QVariant::~QVariant((QVariant *)(lVar3 + 0x20));
              if (*(long *)(lVar3 + 8) != 0) {
                FUN_00528bb6();
              }
              if (*(long *)(lVar3 + 0x10) != 0) {
                FUN_00528bb6();
              }
            }
          }
          lVar2 = *(long *)(lVar2 + 0x10);
          if (lVar2 != 0) {
            pQVar8 = *(QArrayData **)(lVar2 + 0x18);
            if (*(int *)pQVar8 == 0) {
LAB_009070cc:
              QArrayData::deallocate(pQVar8,2,8);
            }
            else if (*(int *)pQVar8 != -1) {
              LOCK();
              *(int *)pQVar8 = *(int *)pQVar8 + -1;
              UNLOCK();
              if (*(int *)pQVar8 == 0) {
                pQVar8 = *(QArrayData **)(lVar2 + 0x18);
                goto LAB_009070cc;
              }
            }
            QVariant::~QVariant((QVariant *)(lVar2 + 0x20));
            lVar3 = *(long *)(lVar2 + 8);
            if (lVar3 != 0) {
              pQVar8 = *(QArrayData **)(lVar3 + 0x18);
              if (*(int *)pQVar8 == 0) {
LAB_00907375:
                QArrayData::deallocate(pQVar8,2,8);
              }
              else if (*(int *)pQVar8 != -1) {
                LOCK();
                *(int *)pQVar8 = *(int *)pQVar8 + -1;
                UNLOCK();
                if (*(int *)pQVar8 == 0) {
                  pQVar8 = *(QArrayData **)(lVar3 + 0x18);
                  goto LAB_00907375;
                }
              }
              QVariant::~QVariant((QVariant *)(lVar3 + 0x20));
              if (*(long *)(lVar3 + 8) != 0) {
                FUN_00528bb6();
              }
              if (*(long *)(lVar3 + 0x10) != 0) {
                FUN_00528bb6();
              }
            }
            lVar2 = *(long *)(lVar2 + 0x10);
            if (lVar2 != 0) {
              pQVar8 = *(QArrayData **)(lVar2 + 0x18);
              if (*(int *)pQVar8 == 0) {
LAB_0090749f:
                QArrayData::deallocate(pQVar8,2,8);
              }
              else if (*(int *)pQVar8 != -1) {
                LOCK();
                *(int *)pQVar8 = *(int *)pQVar8 + -1;
                UNLOCK();
                if (*(int *)pQVar8 == 0) {
                  pQVar8 = *(QArrayData **)(lVar2 + 0x18);
                  goto LAB_0090749f;
                }
              }
              QVariant::~QVariant((QVariant *)(lVar2 + 0x20));
              if (*(long *)(lVar2 + 8) != 0) {
                FUN_00528bb6();
              }
              if (*(long *)(lVar2 + 0x10) != 0) {
                FUN_00528bb6();
              }
            }
          }
        }
      }
      lVar1 = *(long *)(lVar1 + 0x10);
      if (lVar1 != 0) {
        pQVar8 = *(QArrayData **)(lVar1 + 0x18);
        if (*(int *)pQVar8 == 0) {
LAB_00906f7a:
          QArrayData::deallocate(pQVar8,2,8);
        }
        else if (*(int *)pQVar8 != -1) {
          LOCK();
          *(int *)pQVar8 = *(int *)pQVar8 + -1;
          UNLOCK();
          if (*(int *)pQVar8 == 0) {
            pQVar8 = *(QArrayData **)(lVar1 + 0x18);
            goto LAB_00906f7a;
          }
        }
        QVariant::~QVariant((QVariant *)(lVar1 + 0x20));
        lVar2 = *(long *)(lVar1 + 8);
        if (lVar2 != 0) {
          pQVar8 = *(QArrayData **)(lVar2 + 0x18);
          if (*(int *)pQVar8 == 0) {
LAB_0090703b:
            QArrayData::deallocate(pQVar8,2,8);
          }
          else if (*(int *)pQVar8 != -1) {
            LOCK();
            *(int *)pQVar8 = *(int *)pQVar8 + -1;
            UNLOCK();
            if (*(int *)pQVar8 == 0) {
              pQVar8 = *(QArrayData **)(lVar2 + 0x18);
              goto LAB_0090703b;
            }
          }
          QVariant::~QVariant((QVariant *)(lVar2 + 0x20));
          lVar3 = *(long *)(lVar2 + 8);
          if (lVar3 != 0) {
            pQVar8 = *(QArrayData **)(lVar3 + 0x18);
            if (*(int *)pQVar8 == 0) {
LAB_0090711c:
              QArrayData::deallocate(pQVar8,2,8);
            }
            else if (*(int *)pQVar8 != -1) {
              LOCK();
              *(int *)pQVar8 = *(int *)pQVar8 + -1;
              UNLOCK();
              if (*(int *)pQVar8 == 0) {
                pQVar8 = *(QArrayData **)(lVar3 + 0x18);
                goto LAB_0090711c;
              }
            }
            QVariant::~QVariant((QVariant *)(lVar3 + 0x20));
            lVar4 = *(long *)(lVar3 + 8);
            if (lVar4 != 0) {
              pQVar8 = *(QArrayData **)(lVar4 + 0x18);
              if (*(int *)pQVar8 == 0) {
LAB_0090729c:
                QArrayData::deallocate(pQVar8,2,8);
              }
              else if (*(int *)pQVar8 != -1) {
                LOCK();
                *(int *)pQVar8 = *(int *)pQVar8 + -1;
                UNLOCK();
                if (*(int *)pQVar8 == 0) {
                  pQVar8 = *(QArrayData **)(lVar4 + 0x18);
                  goto LAB_0090729c;
                }
              }
              QVariant::~QVariant((QVariant *)(lVar4 + 0x20));
              if (*(long *)(lVar4 + 8) != 0) {
                FUN_00528bb6();
              }
              if (*(long *)(lVar4 + 0x10) != 0) {
                FUN_00528bb6();
              }
            }
            lVar3 = *(long *)(lVar3 + 0x10);
            if (lVar3 != 0) {
              pQVar8 = *(QArrayData **)(lVar3 + 0x18);
              if (*(int *)pQVar8 == 0) {
LAB_009071dc:
                QArrayData::deallocate(pQVar8,2,8);
              }
              else if (*(int *)pQVar8 != -1) {
                LOCK();
                *(int *)pQVar8 = *(int *)pQVar8 + -1;
                UNLOCK();
                if (*(int *)pQVar8 == 0) {
                  pQVar8 = *(QArrayData **)(lVar3 + 0x18);
                  goto LAB_009071dc;
                }
              }
              QVariant::~QVariant((QVariant *)(lVar3 + 0x20));
              if (*(long *)(lVar3 + 8) != 0) {
                FUN_00528bb6();
              }
              if (*(long *)(lVar3 + 0x10) != 0) {
                FUN_00528bb6();
              }
            }
          }
          lVar2 = *(long *)(lVar2 + 0x10);
          if (lVar2 != 0) {
            pQVar8 = *(QArrayData **)(lVar2 + 0x18);
            if (*(int *)pQVar8 == 0) {
LAB_00907104:
              QArrayData::deallocate(pQVar8,2,8);
            }
            else if (*(int *)pQVar8 != -1) {
              LOCK();
              *(int *)pQVar8 = *(int *)pQVar8 + -1;
              UNLOCK();
              if (*(int *)pQVar8 == 0) {
                pQVar8 = *(QArrayData **)(lVar2 + 0x18);
                goto LAB_00907104;
              }
            }
            QVariant::~QVariant((QVariant *)(lVar2 + 0x20));
            lVar3 = *(long *)(lVar2 + 8);
            if (lVar3 != 0) {
              pQVar8 = *(QArrayData **)(lVar3 + 0x18);
              if (*(int *)pQVar8 == 0) {
LAB_00907264:
                QArrayData::deallocate(pQVar8,2,8);
              }
              else if (*(int *)pQVar8 != -1) {
                LOCK();
                *(int *)pQVar8 = *(int *)pQVar8 + -1;
                UNLOCK();
                if (*(int *)pQVar8 == 0) {
                  pQVar8 = *(QArrayData **)(lVar3 + 0x18);
                  goto LAB_00907264;
                }
              }
              QVariant::~QVariant((QVariant *)(lVar3 + 0x20));
              if (*(long *)(lVar3 + 8) != 0) {
                FUN_00528bb6();
              }
              if (*(long *)(lVar3 + 0x10) != 0) {
                FUN_00528bb6();
              }
            }
            lVar2 = *(long *)(lVar2 + 0x10);
            if (lVar2 != 0) {
              pQVar8 = *(QArrayData **)(lVar2 + 0x18);
              if (*(int *)pQVar8 == 0) {
LAB_0090724c:
                QArrayData::deallocate(pQVar8,2,8);
              }
              else if (*(int *)pQVar8 != -1) {
                LOCK();
                *(int *)pQVar8 = *(int *)pQVar8 + -1;
                UNLOCK();
                if (*(int *)pQVar8 == 0) {
                  pQVar8 = *(QArrayData **)(lVar2 + 0x18);
                  goto LAB_0090724c;
                }
              }
              QVariant::~QVariant((QVariant *)(lVar2 + 0x20));
              if (*(long *)(lVar2 + 8) != 0) {
                FUN_00528bb6();
              }
              if (*(long *)(lVar2 + 0x10) != 0) {
                FUN_00528bb6();
              }
            }
          }
        }
        lVar1 = *(long *)(lVar1 + 0x10);
        if (lVar1 != 0) {
          pQVar8 = *(QArrayData **)(lVar1 + 0x18);
          if (*(int *)pQVar8 == 0) {
LAB_00906ff3:
            QArrayData::deallocate(pQVar8,2,8);
          }
          else if (*(int *)pQVar8 != -1) {
            LOCK();
            *(int *)pQVar8 = *(int *)pQVar8 + -1;
            UNLOCK();
            if (*(int *)pQVar8 == 0) {
              pQVar8 = *(QArrayData **)(lVar1 + 0x18);
              goto LAB_00906ff3;
            }
          }
          QVariant::~QVariant((QVariant *)(lVar1 + 0x20));
          lVar2 = *(long *)(lVar1 + 8);
          if (lVar2 != 0) {
            pQVar8 = *(QArrayData **)(lVar2 + 0x18);
            if (*(int *)pQVar8 == 0) {
LAB_00907134:
              QArrayData::deallocate(pQVar8,2,8);
            }
            else if (*(int *)pQVar8 != -1) {
              LOCK();
              *(int *)pQVar8 = *(int *)pQVar8 + -1;
              UNLOCK();
              if (*(int *)pQVar8 == 0) {
                pQVar8 = *(QArrayData **)(lVar2 + 0x18);
                goto LAB_00907134;
              }
            }
            QVariant::~QVariant((QVariant *)(lVar2 + 0x20));
            lVar3 = *(long *)(lVar2 + 8);
            if (lVar3 != 0) {
              pQVar8 = *(QArrayData **)(lVar3 + 0x18);
              if (*(int *)pQVar8 == 0) {
LAB_009072fc:
                QArrayData::deallocate(pQVar8,2,8);
              }
              else if (*(int *)pQVar8 != -1) {
                LOCK();
                *(int *)pQVar8 = *(int *)pQVar8 + -1;
                UNLOCK();
                if (*(int *)pQVar8 == 0) {
                  pQVar8 = *(QArrayData **)(lVar3 + 0x18);
                  goto LAB_009072fc;
                }
              }
              QVariant::~QVariant((QVariant *)(lVar3 + 0x20));
              if (*(long *)(lVar3 + 8) != 0) {
                FUN_00528bb6();
              }
              if (*(long *)(lVar3 + 0x10) != 0) {
                FUN_00528bb6();
              }
            }
            lVar2 = *(long *)(lVar2 + 0x10);
            if (lVar2 != 0) {
              pQVar8 = *(QArrayData **)(lVar2 + 0x18);
              if (*(int *)pQVar8 == 0) {
LAB_009072e4:
                QArrayData::deallocate(pQVar8,2,8);
              }
              else if (*(int *)pQVar8 != -1) {
                LOCK();
                *(int *)pQVar8 = *(int *)pQVar8 + -1;
                UNLOCK();
                if (*(int *)pQVar8 == 0) {
                  pQVar8 = *(QArrayData **)(lVar2 + 0x18);
                  goto LAB_009072e4;
                }
              }
              QVariant::~QVariant((QVariant *)(lVar2 + 0x20));
              if (*(long *)(lVar2 + 8) != 0) {
                FUN_00528bb6();
              }
              if (*(long *)(lVar2 + 0x10) != 0) {
                FUN_00528bb6();
              }
            }
          }
          lVar1 = *(long *)(lVar1 + 0x10);
          if (lVar1 != 0) {
            pQVar8 = *(QArrayData **)(lVar1 + 0x18);
            if (*(int *)pQVar8 == 0) {
LAB_00907054:
              QArrayData::deallocate(pQVar8,2,8);
            }
            else if (*(int *)pQVar8 != -1) {
              LOCK();
              *(int *)pQVar8 = *(int *)pQVar8 + -1;
              UNLOCK();
              if (*(int *)pQVar8 == 0) {
                pQVar8 = *(QArrayData **)(lVar1 + 0x18);
                goto LAB_00907054;
              }
            }
            QVariant::~QVariant((QVariant *)(lVar1 + 0x20));
            lVar2 = *(long *)(lVar1 + 8);
            if (lVar2 != 0) {
              pQVar8 = *(QArrayData **)(lVar2 + 0x18);
              if (*(int *)pQVar8 == 0) {
LAB_009072b4:
                QArrayData::deallocate(pQVar8,2,8);
              }
              else if (*(int *)pQVar8 != -1) {
                LOCK();
                *(int *)pQVar8 = *(int *)pQVar8 + -1;
                UNLOCK();
                if (*(int *)pQVar8 == 0) {
                  pQVar8 = *(QArrayData **)(lVar2 + 0x18);
                  goto LAB_009072b4;
                }
              }
              QVariant::~QVariant((QVariant *)(lVar2 + 0x20));
              if (*(long *)(lVar2 + 8) != 0) {
                FUN_00528bb6();
              }
              if (*(long *)(lVar2 + 0x10) != 0) {
                FUN_00528bb6();
              }
            }
            lVar1 = *(long *)(lVar1 + 0x10);
            if (lVar1 != 0) {
              pQVar8 = *(QArrayData **)(lVar1 + 0x18);
              if (*(int *)pQVar8 == 0) {
LAB_0090735d:
                QArrayData::deallocate(pQVar8,2,8);
              }
              else if (*(int *)pQVar8 != -1) {
                LOCK();
                *(int *)pQVar8 = *(int *)pQVar8 + -1;
                UNLOCK();
                if (*(int *)pQVar8 == 0) {
                  pQVar8 = *(QArrayData **)(lVar1 + 0x18);
                  goto LAB_0090735d;
                }
              }
              QVariant::~QVariant((QVariant *)(lVar1 + 0x20));
              if (*(long *)(lVar1 + 8) != 0) {
                FUN_00528bb6();
              }
              if (*(long *)(lVar1 + 0x10) != 0) {
                FUN_00528bb6();
              }
            }
          }
        }
      }
    }
    QMapDataBase::freeTree(pQVar7,(int)*(undefined8 *)(pQVar7 + 0x10));
  }
  QMapDataBase::freeData((QMapDataBase *)pQVar7);
LAB_00905eb0:
  QDialog::~QDialog(param_1);
  return;
}


// ==== entry=00907513 name=FUN_00907513 size=220 ====

void FUN_00907513(undefined8 *param_1)

{
  long lVar1;
  QMapNodeBase *pQVar2;
  QArrayData *pQVar3;
  
  param_1[-2] = &SettingDialog_vtable;
  *param_1 = &PTR_FUN_011a4230;
  if (param_1[0xb] != 0) {
    FUN_006ec54c(param_1 + 0xb);
  }
  pQVar2 = (QMapNodeBase *)param_1[6];
  if (*(int *)pQVar2 != 0) {
    if (*(int *)pQVar2 == -1) {
LAB_0090755b:
      QDialog::~QDialog((QDialog *)(param_1 + -2));
      return;
    }
    LOCK();
    *(int *)pQVar2 = *(int *)pQVar2 + -1;
    UNLOCK();
    if (*(int *)pQVar2 != 0) goto LAB_0090755b;
    pQVar2 = (QMapNodeBase *)param_1[6];
  }
  lVar1 = *(long *)(pQVar2 + 0x10);
  if (lVar1 == 0) goto LAB_009075c4;
  pQVar3 = *(QArrayData **)(lVar1 + 0x18);
  if (*(int *)pQVar3 == 0) {
LAB_009075de:
    QArrayData::deallocate(pQVar3,2,8);
  }
  else if (*(int *)pQVar3 != -1) {
    LOCK();
    *(int *)pQVar3 = *(int *)pQVar3 + -1;
    UNLOCK();
    if (*(int *)pQVar3 == 0) {
      pQVar3 = *(QArrayData **)(lVar1 + 0x18);
      goto LAB_009075de;
    }
  }
  QVariant::~QVariant((QVariant *)(lVar1 + 0x20));
  if (*(long *)(lVar1 + 8) != 0) {
    FUN_00528bb6();
  }
  if (*(long *)(lVar1 + 0x10) != 0) {
    FUN_00528bb6();
  }
  QMapDataBase::freeTree(pQVar2,(int)*(undefined8 *)(pQVar2 + 0x10));
LAB_009075c4:
  QMapDataBase::freeData((QMapDataBase *)pQVar2);
  QDialog::~QDialog((QDialog *)(param_1 + -2));
  return;
}


// ==== entry=009075f0 name=FUN_009075f0 size=220 ====

void FUN_009075f0(undefined8 *param_1)

{
  long lVar1;
  QMapNodeBase *pQVar2;
  QArrayData *pQVar3;
  
  param_1[-2] = &SettingDialog_vtable;
  *param_1 = &PTR_FUN_011a4230;
  if (param_1[0xb] != 0) {
    FUN_006ec54c(param_1 + 0xb);
  }
  pQVar2 = (QMapNodeBase *)param_1[6];
  if (*(int *)pQVar2 != 0) {
    if (*(int *)pQVar2 == -1) goto LAB_0090763c;
    LOCK();
    *(int *)pQVar2 = *(int *)pQVar2 + -1;
    UNLOCK();
    if (*(int *)pQVar2 != 0) goto LAB_0090763c;
    pQVar2 = (QMapNodeBase *)param_1[6];
  }
  lVar1 = *(long *)(pQVar2 + 0x10);
  if (lVar1 != 0) {
    pQVar3 = *(QArrayData **)(lVar1 + 0x18);
    if (*(int *)pQVar3 == 0) {
LAB_009076bb:
      QArrayData::deallocate(pQVar3,2,8);
    }
    else if (*(int *)pQVar3 != -1) {
      LOCK();
      *(int *)pQVar3 = *(int *)pQVar3 + -1;
      UNLOCK();
      if (*(int *)pQVar3 == 0) {
        pQVar3 = *(QArrayData **)(lVar1 + 0x18);
        goto LAB_009076bb;
      }
    }
    QVariant::~QVariant((QVariant *)(lVar1 + 0x20));
    if (*(long *)(lVar1 + 8) != 0) {
      FUN_00528bb6();
    }
    if (*(long *)(lVar1 + 0x10) != 0) {
      FUN_00528bb6();
    }
    QMapDataBase::freeTree(pQVar2,(int)*(undefined8 *)(pQVar2 + 0x10));
  }
  QMapDataBase::freeData((QMapDataBase *)pQVar2);
LAB_0090763c:
  QDialog::~QDialog((QDialog *)(param_1 + -2));
  operator_delete((QDialog *)(param_1 + -2),0x70);
  return;
}


// ==== entry=009076cc orig=FUN_009076cc size=5826 name=SettingDialog_dtor_deleting ====

void SettingDialog_dtor_deleting(QDialog *param_1)

{
  long lVar1;
  long lVar2;
  long lVar3;
  long lVar4;
  long lVar5;
  long lVar6;
  QMapNodeBase *pQVar7;
  QArrayData *pQVar8;
  
  *(undefined ***)param_1 = &SettingDialog_vtable;
  *(undefined ***)(param_1 + 0x10) = &PTR_FUN_011a4230;
  if (*(long *)(param_1 + 0x68) != 0) {
    FUN_006ec54c(param_1 + 0x68);
  }
  pQVar7 = *(QMapNodeBase **)(param_1 + 0x40);
  if (*(int *)pQVar7 != 0) {
    if (*(int *)pQVar7 == -1) goto LAB_0090771e;
    LOCK();
    *(int *)pQVar7 = *(int *)pQVar7 + -1;
    UNLOCK();
    if (*(int *)pQVar7 != 0) goto LAB_0090771e;
    pQVar7 = *(QMapNodeBase **)(param_1 + 0x40);
  }
  lVar1 = *(long *)(pQVar7 + 0x10);
  if (lVar1 != 0) {
    pQVar8 = *(QArrayData **)(lVar1 + 0x18);
    if (*(int *)pQVar8 == 0) {
LAB_00908794:
      QArrayData::deallocate(pQVar8,2,8);
    }
    else if (*(int *)pQVar8 != -1) {
      LOCK();
      *(int *)pQVar8 = *(int *)pQVar8 + -1;
      UNLOCK();
      if (*(int *)pQVar8 == 0) {
        pQVar8 = *(QArrayData **)(lVar1 + 0x18);
        goto LAB_00908794;
      }
    }
    QVariant::~QVariant((QVariant *)(lVar1 + 0x20));
    lVar2 = *(long *)(lVar1 + 8);
    if (lVar2 != 0) {
      pQVar8 = *(QArrayData **)(lVar2 + 0x18);
      if (*(int *)pQVar8 == 0) {
LAB_009077a1:
        QArrayData::deallocate(pQVar8,2,8);
      }
      else if (*(int *)pQVar8 != -1) {
        LOCK();
        *(int *)pQVar8 = *(int *)pQVar8 + -1;
        UNLOCK();
        if (*(int *)pQVar8 == 0) {
          pQVar8 = *(QArrayData **)(lVar2 + 0x18);
          goto LAB_009077a1;
        }
      }
      QVariant::~QVariant((QVariant *)(lVar2 + 0x20));
      lVar3 = *(long *)(lVar2 + 8);
      if (lVar3 != 0) {
        pQVar8 = *(QArrayData **)(lVar3 + 0x18);
        if (*(int *)pQVar8 == 0) {
LAB_009087dc:
          QArrayData::deallocate(pQVar8,2,8);
        }
        else if (*(int *)pQVar8 != -1) {
          LOCK();
          *(int *)pQVar8 = *(int *)pQVar8 + -1;
          UNLOCK();
          if (*(int *)pQVar8 == 0) {
            pQVar8 = *(QArrayData **)(lVar3 + 0x18);
            goto LAB_009087dc;
          }
        }
        QVariant::~QVariant((QVariant *)(lVar3 + 0x20));
        lVar4 = *(long *)(lVar3 + 8);
        if (lVar4 != 0) {
          pQVar8 = *(QArrayData **)(lVar4 + 0x18);
          if (*(int *)pQVar8 == 0) {
LAB_00908886:
            QArrayData::deallocate(pQVar8,2,8);
          }
          else if (*(int *)pQVar8 != -1) {
            LOCK();
            *(int *)pQVar8 = *(int *)pQVar8 + -1;
            UNLOCK();
            if (*(int *)pQVar8 == 0) {
              pQVar8 = *(QArrayData **)(lVar4 + 0x18);
              goto LAB_00908886;
            }
          }
          QVariant::~QVariant((QVariant *)(lVar4 + 0x20));
          lVar5 = *(long *)(lVar4 + 8);
          if (lVar5 != 0) {
            pQVar8 = *(QArrayData **)(lVar5 + 0x18);
            if (*(int *)pQVar8 == 0) {
LAB_0090895f:
              QArrayData::deallocate(pQVar8,2,8);
            }
            else if (*(int *)pQVar8 != -1) {
              LOCK();
              *(int *)pQVar8 = *(int *)pQVar8 + -1;
              UNLOCK();
              if (*(int *)pQVar8 == 0) {
                pQVar8 = *(QArrayData **)(lVar5 + 0x18);
                goto LAB_0090895f;
              }
            }
            QVariant::~QVariant((QVariant *)(lVar5 + 0x20));
            lVar6 = *(long *)(lVar5 + 8);
            if (lVar6 != 0) {
              pQVar8 = *(QArrayData **)(lVar6 + 0x18);
              if (*(int *)pQVar8 == 0) {
LAB_00908c20:
                QArrayData::deallocate(pQVar8,2,8);
              }
              else if (*(int *)pQVar8 != -1) {
                LOCK();
                *(int *)pQVar8 = *(int *)pQVar8 + -1;
                UNLOCK();
                if (*(int *)pQVar8 == 0) {
                  pQVar8 = *(QArrayData **)(lVar6 + 0x18);
                  goto LAB_00908c20;
                }
              }
              QVariant::~QVariant((QVariant *)(lVar6 + 0x20));
              if (*(long *)(lVar6 + 8) != 0) {
                FUN_00528bb6();
              }
              if (*(long *)(lVar6 + 0x10) != 0) {
                FUN_00528bb6();
              }
            }
            lVar5 = *(long *)(lVar5 + 0x10);
            if (lVar5 != 0) {
              pQVar8 = *(QArrayData **)(lVar5 + 0x18);
              if (*(int *)pQVar8 == 0) {
LAB_00908c62:
                QArrayData::deallocate(pQVar8,2,8);
              }
              else if (*(int *)pQVar8 != -1) {
                LOCK();
                *(int *)pQVar8 = *(int *)pQVar8 + -1;
                UNLOCK();
                if (*(int *)pQVar8 == 0) {
                  pQVar8 = *(QArrayData **)(lVar5 + 0x18);
                  goto LAB_00908c62;
                }
              }
              QVariant::~QVariant((QVariant *)(lVar5 + 0x20));
              if (*(long *)(lVar5 + 8) != 0) {
                FUN_00528bb6();
              }
              if (*(long *)(lVar5 + 0x10) != 0) {
                FUN_00528bb6();
              }
            }
          }
          lVar4 = *(long *)(lVar4 + 0x10);
          if (lVar4 != 0) {
            pQVar8 = *(QArrayData **)(lVar4 + 0x18);
            if (*(int *)pQVar8 == 0) {
LAB_009089c7:
              QArrayData::deallocate(pQVar8,2,8);
            }
            else if (*(int *)pQVar8 != -1) {
              LOCK();
              *(int *)pQVar8 = *(int *)pQVar8 + -1;
              UNLOCK();
              if (*(int *)pQVar8 == 0) {
                pQVar8 = *(QArrayData **)(lVar4 + 0x18);
                goto LAB_009089c7;
              }
            }
            QVariant::~QVariant((QVariant *)(lVar4 + 0x20));
            lVar5 = *(long *)(lVar4 + 8);
            if (lVar5 != 0) {
              pQVar8 = *(QArrayData **)(lVar5 + 0x18);
              if (*(int *)pQVar8 == 0) {
LAB_00908a6f:
                QArrayData::deallocate(pQVar8,2,8);
              }
              else if (*(int *)pQVar8 != -1) {
                LOCK();
                *(int *)pQVar8 = *(int *)pQVar8 + -1;
                UNLOCK();
                if (*(int *)pQVar8 == 0) {
                  pQVar8 = *(QArrayData **)(lVar5 + 0x18);
                  goto LAB_00908a6f;
                }
              }
              QVariant::~QVariant((QVariant *)(lVar5 + 0x20));
              if (*(long *)(lVar5 + 8) != 0) {
                FUN_00528bb6();
              }
              if (*(long *)(lVar5 + 0x10) != 0) {
                FUN_00528bb6();
              }
            }
            lVar4 = *(long *)(lVar4 + 0x10);
            if (lVar4 != 0) {
              pQVar8 = *(QArrayData **)(lVar4 + 0x18);
              if (*(int *)pQVar8 == 0) {
LAB_00908c4a:
                QArrayData::deallocate(pQVar8,2,8);
              }
              else if (*(int *)pQVar8 != -1) {
                LOCK();
                *(int *)pQVar8 = *(int *)pQVar8 + -1;
                UNLOCK();
                if (*(int *)pQVar8 == 0) {
                  pQVar8 = *(QArrayData **)(lVar4 + 0x18);
                  goto LAB_00908c4a;
                }
              }
              QVariant::~QVariant((QVariant *)(lVar4 + 0x20));
              if (*(long *)(lVar4 + 8) != 0) {
                FUN_00528bb6();
              }
              if (*(long *)(lVar4 + 0x10) != 0) {
                FUN_00528bb6();
              }
            }
          }
        }
        lVar3 = *(long *)(lVar3 + 0x10);
        if (lVar3 != 0) {
          pQVar8 = *(QArrayData **)(lVar3 + 0x18);
          if (*(int *)pQVar8 == 0) {
LAB_0090889e:
            QArrayData::deallocate(pQVar8,2,8);
          }
          else if (*(int *)pQVar8 != -1) {
            LOCK();
            *(int *)pQVar8 = *(int *)pQVar8 + -1;
            UNLOCK();
            if (*(int *)pQVar8 == 0) {
              pQVar8 = *(QArrayData **)(lVar3 + 0x18);
              goto LAB_0090889e;
            }
          }
          QVariant::~QVariant((QVariant *)(lVar3 + 0x20));
          lVar4 = *(long *)(lVar3 + 8);
          if (lVar4 != 0) {
            pQVar8 = *(QArrayData **)(lVar4 + 0x18);
            if (*(int *)pQVar8 == 0) {
LAB_009089df:
              QArrayData::deallocate(pQVar8,2,8);
            }
            else if (*(int *)pQVar8 != -1) {
              LOCK();
              *(int *)pQVar8 = *(int *)pQVar8 + -1;
              UNLOCK();
              if (*(int *)pQVar8 == 0) {
                pQVar8 = *(QArrayData **)(lVar4 + 0x18);
                goto LAB_009089df;
              }
            }
            QVariant::~QVariant((QVariant *)(lVar4 + 0x20));
            lVar5 = *(long *)(lVar4 + 8);
            if (lVar5 != 0) {
              pQVar8 = *(QArrayData **)(lVar5 + 0x18);
              if (*(int *)pQVar8 == 0) {
LAB_00908aa7:
                QArrayData::deallocate(pQVar8,2,8);
              }
              else if (*(int *)pQVar8 != -1) {
                LOCK();
                *(int *)pQVar8 = *(int *)pQVar8 + -1;
                UNLOCK();
                if (*(int *)pQVar8 == 0) {
                  pQVar8 = *(QArrayData **)(lVar5 + 0x18);
                  goto LAB_00908aa7;
                }
              }
              QVariant::~QVariant((QVariant *)(lVar5 + 0x20));
              if (*(long *)(lVar5 + 8) != 0) {
                FUN_00528bb6();
              }
              if (*(long *)(lVar5 + 0x10) != 0) {
                FUN_00528bb6();
              }
            }
            lVar4 = *(long *)(lVar4 + 0x10);
            if (lVar4 != 0) {
              pQVar8 = *(QArrayData **)(lVar4 + 0x18);
              if (*(int *)pQVar8 == 0) {
LAB_00908a8f:
                QArrayData::deallocate(pQVar8,2,8);
              }
              else if (*(int *)pQVar8 != -1) {
                LOCK();
                *(int *)pQVar8 = *(int *)pQVar8 + -1;
                UNLOCK();
                if (*(int *)pQVar8 == 0) {
                  pQVar8 = *(QArrayData **)(lVar4 + 0x18);
                  goto LAB_00908a8f;
                }
              }
              QVariant::~QVariant((QVariant *)(lVar4 + 0x20));
              if (*(long *)(lVar4 + 8) != 0) {
                FUN_00528bb6();
              }
              if (*(long *)(lVar4 + 0x10) != 0) {
                FUN_00528bb6();
              }
            }
          }
          lVar3 = *(long *)(lVar3 + 0x10);
          if (lVar3 != 0) {
            pQVar8 = *(QArrayData **)(lVar3 + 0x18);
            if (*(int *)pQVar8 == 0) {
LAB_009089f7:
              QArrayData::deallocate(pQVar8,2,8);
            }
            else if (*(int *)pQVar8 != -1) {
              LOCK();
              *(int *)pQVar8 = *(int *)pQVar8 + -1;
              UNLOCK();
              if (*(int *)pQVar8 == 0) {
                pQVar8 = *(QArrayData **)(lVar3 + 0x18);
                goto LAB_009089f7;
              }
            }
            QVariant::~QVariant((QVariant *)(lVar3 + 0x20));
            lVar4 = *(long *)(lVar3 + 8);
            if (lVar4 != 0) {
              pQVar8 = *(QArrayData **)(lVar4 + 0x18);
              if (*(int *)pQVar8 == 0) {
LAB_00908d4a:
                QArrayData::deallocate(pQVar8,2,8);
              }
              else if (*(int *)pQVar8 != -1) {
                LOCK();
                *(int *)pQVar8 = *(int *)pQVar8 + -1;
                UNLOCK();
                if (*(int *)pQVar8 == 0) {
                  pQVar8 = *(QArrayData **)(lVar4 + 0x18);
                  goto LAB_00908d4a;
                }
              }
              QVariant::~QVariant((QVariant *)(lVar4 + 0x20));
              if (*(long *)(lVar4 + 8) != 0) {
                FUN_00528bb6();
              }
              if (*(long *)(lVar4 + 0x10) != 0) {
                FUN_00528bb6();
              }
            }
            lVar3 = *(long *)(lVar3 + 0x10);
            if (lVar3 != 0) {
              pQVar8 = *(QArrayData **)(lVar3 + 0x18);
              if (*(int *)pQVar8 == 0) {
LAB_00908bbf:
                QArrayData::deallocate(pQVar8,2,8);
              }
              else if (*(int *)pQVar8 != -1) {
                LOCK();
                *(int *)pQVar8 = *(int *)pQVar8 + -1;
                UNLOCK();
                if (*(int *)pQVar8 == 0) {
                  pQVar8 = *(QArrayData **)(lVar3 + 0x18);
                  goto LAB_00908bbf;
                }
              }
              QVariant::~QVariant((QVariant *)(lVar3 + 0x20));
              if (*(long *)(lVar3 + 8) != 0) {
                FUN_00528bb6();
              }
              if (*(long *)(lVar3 + 0x10) != 0) {
                FUN_00528bb6();
              }
            }
          }
        }
      }
      lVar2 = *(long *)(lVar2 + 0x10);
      if (lVar2 != 0) {
        pQVar8 = *(QArrayData **)(lVar2 + 0x18);
        if (*(int *)pQVar8 == 0) {
LAB_009087c4:
          QArrayData::deallocate(pQVar8,2,8);
        }
        else if (*(int *)pQVar8 != -1) {
          LOCK();
          *(int *)pQVar8 = *(int *)pQVar8 + -1;
          UNLOCK();
          if (*(int *)pQVar8 == 0) {
            pQVar8 = *(QArrayData **)(lVar2 + 0x18);
            goto LAB_009087c4;
          }
        }
        QVariant::~QVariant((QVariant *)(lVar2 + 0x20));
        lVar3 = *(long *)(lVar2 + 8);
        if (lVar3 != 0) {
          pQVar8 = *(QArrayData **)(lVar3 + 0x18);
          if (*(int *)pQVar8 == 0) {
LAB_00908855:
            QArrayData::deallocate(pQVar8,2,8);
          }
          else if (*(int *)pQVar8 != -1) {
            LOCK();
            *(int *)pQVar8 = *(int *)pQVar8 + -1;
            UNLOCK();
            if (*(int *)pQVar8 == 0) {
              pQVar8 = *(QArrayData **)(lVar3 + 0x18);
              goto LAB_00908855;
            }
          }
          QVariant::~QVariant((QVariant *)(lVar3 + 0x20));
          lVar4 = *(long *)(lVar3 + 8);
          if (lVar4 != 0) {
            pQVar8 = *(QArrayData **)(lVar4 + 0x18);
            if (*(int *)pQVar8 == 0) {
LAB_00908a3f:
              QArrayData::deallocate(pQVar8,2,8);
            }
            else if (*(int *)pQVar8 != -1) {
              LOCK();
              *(int *)pQVar8 = *(int *)pQVar8 + -1;
              UNLOCK();
              if (*(int *)pQVar8 == 0) {
                pQVar8 = *(QArrayData **)(lVar4 + 0x18);
                goto LAB_00908a3f;
              }
            }
            QVariant::~QVariant((QVariant *)(lVar4 + 0x20));
            lVar5 = *(long *)(lVar4 + 8);
            if (lVar5 != 0) {
              pQVar8 = *(QArrayData **)(lVar5 + 0x18);
              if (*(int *)pQVar8 == 0) {
LAB_00908cca:
                QArrayData::deallocate(pQVar8,2,8);
              }
              else if (*(int *)pQVar8 != -1) {
                LOCK();
                *(int *)pQVar8 = *(int *)pQVar8 + -1;
                UNLOCK();
                if (*(int *)pQVar8 == 0) {
                  pQVar8 = *(QArrayData **)(lVar5 + 0x18);
                  goto LAB_00908cca;
                }
              }
              QVariant::~QVariant((QVariant *)(lVar5 + 0x20));
              if (*(long *)(lVar5 + 8) != 0) {
                FUN_00528bb6();
              }
              if (*(long *)(lVar5 + 0x10) != 0) {
                FUN_00528bb6();
              }
            }
            lVar4 = *(long *)(lVar4 + 0x10);
            if (lVar4 != 0) {
              pQVar8 = *(QArrayData **)(lVar4 + 0x18);
              if (*(int *)pQVar8 == 0) {
LAB_00908cb2:
                QArrayData::deallocate(pQVar8,2,8);
              }
              else if (*(int *)pQVar8 != -1) {
                LOCK();
                *(int *)pQVar8 = *(int *)pQVar8 + -1;
                UNLOCK();
                if (*(int *)pQVar8 == 0) {
                  pQVar8 = *(QArrayData **)(lVar4 + 0x18);
                  goto LAB_00908cb2;
                }
              }
              QVariant::~QVariant((QVariant *)(lVar4 + 0x20));
              if (*(long *)(lVar4 + 8) != 0) {
                FUN_00528bb6();
              }
              if (*(long *)(lVar4 + 0x10) != 0) {
                FUN_00528bb6();
              }
            }
          }
          lVar3 = *(long *)(lVar3 + 0x10);
          if (lVar3 != 0) {
            pQVar8 = *(QArrayData **)(lVar3 + 0x18);
            if (*(int *)pQVar8 == 0) {
LAB_00908a27:
              QArrayData::deallocate(pQVar8,2,8);
            }
            else if (*(int *)pQVar8 != -1) {
              LOCK();
              *(int *)pQVar8 = *(int *)pQVar8 + -1;
              UNLOCK();
              if (*(int *)pQVar8 == 0) {
                pQVar8 = *(QArrayData **)(lVar3 + 0x18);
                goto LAB_00908a27;
              }
            }
            QVariant::~QVariant((QVariant *)(lVar3 + 0x20));
            lVar4 = *(long *)(lVar3 + 8);
            if (lVar4 != 0) {
              pQVar8 = *(QArrayData **)(lVar4 + 0x18);
              if (*(int *)pQVar8 == 0) {
LAB_00908ba7:
                QArrayData::deallocate(pQVar8,2,8);
              }
              else if (*(int *)pQVar8 != -1) {
                LOCK();
                *(int *)pQVar8 = *(int *)pQVar8 + -1;
                UNLOCK();
                if (*(int *)pQVar8 == 0) {
                  pQVar8 = *(QArrayData **)(lVar4 + 0x18);
                  goto LAB_00908ba7;
                }
              }
              QVariant::~QVariant((QVariant *)(lVar4 + 0x20));
              if (*(long *)(lVar4 + 8) != 0) {
                FUN_00528bb6();
              }
              if (*(long *)(lVar4 + 0x10) != 0) {
                FUN_00528bb6();
              }
            }
            lVar3 = *(long *)(lVar3 + 0x10);
            if (lVar3 != 0) {
              pQVar8 = *(QArrayData **)(lVar3 + 0x18);
              if (*(int *)pQVar8 == 0) {
LAB_00908b8f:
                QArrayData::deallocate(pQVar8,2,8);
              }
              else if (*(int *)pQVar8 != -1) {
                LOCK();
                *(int *)pQVar8 = *(int *)pQVar8 + -1;
                UNLOCK();
                if (*(int *)pQVar8 == 0) {
                  pQVar8 = *(QArrayData **)(lVar3 + 0x18);
                  goto LAB_00908b8f;
                }
              }
              QVariant::~QVariant((QVariant *)(lVar3 + 0x20));
              if (*(long *)(lVar3 + 8) != 0) {
                FUN_00528bb6();
              }
              if (*(long *)(lVar3 + 0x10) != 0) {
                FUN_00528bb6();
              }
            }
          }
        }
        lVar2 = *(long *)(lVar2 + 0x10);
        if (lVar2 != 0) {
          pQVar8 = *(QArrayData **)(lVar2 + 0x18);
          if (*(int *)pQVar8 == 0) {
LAB_0090883d:
            QArrayData::deallocate(pQVar8,2,8);
          }
          else if (*(int *)pQVar8 != -1) {
            LOCK();
            *(int *)pQVar8 = *(int *)pQVar8 + -1;
            UNLOCK();
            if (*(int *)pQVar8 == 0) {
              pQVar8 = *(QArrayData **)(lVar2 + 0x18);
              goto LAB_0090883d;
            }
          }
          QVariant::~QVariant((QVariant *)(lVar2 + 0x20));
          lVar3 = *(long *)(lVar2 + 8);
          if (lVar3 != 0) {
            pQVar8 = *(QArrayData **)(lVar3 + 0x18);
            if (*(int *)pQVar8 == 0) {
LAB_009088e7:
              QArrayData::deallocate(pQVar8,2,8);
            }
            else if (*(int *)pQVar8 != -1) {
              LOCK();
              *(int *)pQVar8 = *(int *)pQVar8 + -1;
              UNLOCK();
              if (*(int *)pQVar8 == 0) {
                pQVar8 = *(QArrayData **)(lVar3 + 0x18);
                goto LAB_009088e7;
              }
            }
            QVariant::~QVariant((QVariant *)(lVar3 + 0x20));
            lVar4 = *(long *)(lVar3 + 8);
            if (lVar4 != 0) {
              pQVar8 = *(QArrayData **)(lVar4 + 0x18);
              if (*(int *)pQVar8 == 0) {
LAB_00908c9a:
                QArrayData::deallocate(pQVar8,2,8);
              }
              else if (*(int *)pQVar8 != -1) {
                LOCK();
                *(int *)pQVar8 = *(int *)pQVar8 + -1;
                UNLOCK();
                if (*(int *)pQVar8 == 0) {
                  pQVar8 = *(QArrayData **)(lVar4 + 0x18);
                  goto LAB_00908c9a;
                }
              }
              QVariant::~QVariant((QVariant *)(lVar4 + 0x20));
              if (*(long *)(lVar4 + 8) != 0) {
                FUN_00528bb6();
              }
              if (*(long *)(lVar4 + 0x10) != 0) {
                FUN_00528bb6();
              }
            }
            lVar3 = *(long *)(lVar3 + 0x10);
            if (lVar3 != 0) {
              pQVar8 = *(QArrayData **)(lVar3 + 0x18);
              if (*(int *)pQVar8 == 0) {
LAB_00908c82:
                QArrayData::deallocate(pQVar8,2,8);
              }
              else if (*(int *)pQVar8 != -1) {
                LOCK();
                *(int *)pQVar8 = *(int *)pQVar8 + -1;
                UNLOCK();
                if (*(int *)pQVar8 == 0) {
                  pQVar8 = *(QArrayData **)(lVar3 + 0x18);
                  goto LAB_00908c82;
                }
              }
              QVariant::~QVariant((QVariant *)(lVar3 + 0x20));
              if (*(long *)(lVar3 + 8) != 0) {
                FUN_00528bb6();
              }
              if (*(long *)(lVar3 + 0x10) != 0) {
                FUN_00528bb6();
              }
            }
          }
          lVar2 = *(long *)(lVar2 + 0x10);
          if (lVar2 != 0) {
            pQVar8 = *(QArrayData **)(lVar2 + 0x18);
            if (*(int *)pQVar8 == 0) {
LAB_009088ff:
              QArrayData::deallocate(pQVar8,2,8);
            }
            else if (*(int *)pQVar8 != -1) {
              LOCK();
              *(int *)pQVar8 = *(int *)pQVar8 + -1;
              UNLOCK();
              if (*(int *)pQVar8 == 0) {
                pQVar8 = *(QArrayData **)(lVar2 + 0x18);
                goto LAB_009088ff;
              }
            }
            QVariant::~QVariant((QVariant *)(lVar2 + 0x20));
            lVar3 = *(long *)(lVar2 + 8);
            if (lVar3 != 0) {
              pQVar8 = *(QArrayData **)(lVar3 + 0x18);
              if (*(int *)pQVar8 == 0) {
LAB_00908b47:
                QArrayData::deallocate(pQVar8,2,8);
              }
              else if (*(int *)pQVar8 != -1) {
                LOCK();
                *(int *)pQVar8 = *(int *)pQVar8 + -1;
                UNLOCK();
                if (*(int *)pQVar8 == 0) {
                  pQVar8 = *(QArrayData **)(lVar3 + 0x18);
                  goto LAB_00908b47;
                }
              }
              QVariant::~QVariant((QVariant *)(lVar3 + 0x20));
              if (*(long *)(lVar3 + 8) != 0) {
                FUN_00528bb6();
              }
              if (*(long *)(lVar3 + 0x10) != 0) {
                FUN_00528bb6();
              }
            }
            lVar2 = *(long *)(lVar2 + 0x10);
            if (lVar2 != 0) {
              pQVar8 = *(QArrayData **)(lVar2 + 0x18);
              if (*(int *)pQVar8 == 0) {
LAB_00908d32:
                QArrayData::deallocate(pQVar8,2,8);
              }
              else if (*(int *)pQVar8 != -1) {
                LOCK();
                *(int *)pQVar8 = *(int *)pQVar8 + -1;
                UNLOCK();
                if (*(int *)pQVar8 == 0) {
                  pQVar8 = *(QArrayData **)(lVar2 + 0x18);
                  goto LAB_00908d32;
                }
              }
              QVariant::~QVariant((QVariant *)(lVar2 + 0x20));
              if (*(long *)(lVar2 + 8) != 0) {
                FUN_00528bb6();
              }
              if (*(long *)(lVar2 + 0x10) != 0) {
                FUN_00528bb6();
              }
            }
          }
        }
      }
    }
    lVar1 = *(long *)(lVar1 + 0x10);
    if (lVar1 != 0) {
      pQVar8 = *(QArrayData **)(lVar1 + 0x18);
      if (*(int *)pQVar8 == 0) {
LAB_00907fc0:
        QArrayData::deallocate(pQVar8,2,8);
      }
      else if (*(int *)pQVar8 != -1) {
        LOCK();
        *(int *)pQVar8 = *(int *)pQVar8 + -1;
        UNLOCK();
        if (*(int *)pQVar8 == 0) {
          pQVar8 = *(QArrayData **)(lVar1 + 0x18);
          goto LAB_00907fc0;
        }
      }
      QVariant::~QVariant((QVariant *)(lVar1 + 0x20));
      lVar2 = *(long *)(lVar1 + 8);
      if (lVar2 != 0) {
        pQVar8 = *(QArrayData **)(lVar2 + 0x18);
        if (*(int *)pQVar8 == 0) {
LAB_009087ac:
          QArrayData::deallocate(pQVar8,2,8);
        }
        else if (*(int *)pQVar8 != -1) {
          LOCK();
          *(int *)pQVar8 = *(int *)pQVar8 + -1;
          UNLOCK();
          if (*(int *)pQVar8 == 0) {
            pQVar8 = *(QArrayData **)(lVar2 + 0x18);
            goto LAB_009087ac;
          }
        }
        QVariant::~QVariant((QVariant *)(lVar2 + 0x20));
        lVar3 = *(long *)(lVar2 + 8);
        if (lVar3 != 0) {
          pQVar8 = *(QArrayData **)(lVar3 + 0x18);
          if (*(int *)pQVar8 == 0) {
LAB_0090880d:
            QArrayData::deallocate(pQVar8,2,8);
          }
          else if (*(int *)pQVar8 != -1) {
            LOCK();
            *(int *)pQVar8 = *(int *)pQVar8 + -1;
            UNLOCK();
            if (*(int *)pQVar8 == 0) {
              pQVar8 = *(QArrayData **)(lVar3 + 0x18);
              goto LAB_0090880d;
            }
          }
          QVariant::~QVariant((QVariant *)(lVar3 + 0x20));
          lVar4 = *(long *)(lVar3 + 8);
          if (lVar4 != 0) {
            pQVar8 = *(QArrayData **)(lVar4 + 0x18);
            if (*(int *)pQVar8 == 0) {
LAB_0090892f:
              QArrayData::deallocate(pQVar8,2,8);
            }
            else if (*(int *)pQVar8 != -1) {
              LOCK();
              *(int *)pQVar8 = *(int *)pQVar8 + -1;
              UNLOCK();
              if (*(int *)pQVar8 == 0) {
                pQVar8 = *(QArrayData **)(lVar4 + 0x18);
                goto LAB_0090892f;
              }
            }
            QVariant::~QVariant((QVariant *)(lVar4 + 0x20));
            lVar5 = *(long *)(lVar4 + 8);
            if (lVar5 != 0) {
              pQVar8 = *(QArrayData **)(lVar5 + 0x18);
              if (*(int *)pQVar8 == 0) {
LAB_00908af7:
                QArrayData::deallocate(pQVar8,2,8);
              }
              else if (*(int *)pQVar8 != -1) {
                LOCK();
                *(int *)pQVar8 = *(int *)pQVar8 + -1;
                UNLOCK();
                if (*(int *)pQVar8 == 0) {
                  pQVar8 = *(QArrayData **)(lVar5 + 0x18);
                  goto LAB_00908af7;
                }
              }
              QVariant::~QVariant((QVariant *)(lVar5 + 0x20));
              if (*(long *)(lVar5 + 8) != 0) {
                FUN_00528bb6();
              }
              if (*(long *)(lVar5 + 0x10) != 0) {
                FUN_00528bb6();
              }
            }
            lVar4 = *(long *)(lVar4 + 0x10);
            if (lVar4 != 0) {
              pQVar8 = *(QArrayData **)(lVar4 + 0x18);
              if (*(int *)pQVar8 == 0) {
LAB_00908c08:
                QArrayData::deallocate(pQVar8,2,8);
              }
              else if (*(int *)pQVar8 != -1) {
                LOCK();
                *(int *)pQVar8 = *(int *)pQVar8 + -1;
                UNLOCK();
                if (*(int *)pQVar8 == 0) {
                  pQVar8 = *(QArrayData **)(lVar4 + 0x18);
                  goto LAB_00908c08;
                }
              }
              QVariant::~QVariant((QVariant *)(lVar4 + 0x20));
              if (*(long *)(lVar4 + 8) != 0) {
                FUN_00528bb6();
              }
              if (*(long *)(lVar4 + 0x10) != 0) {
                FUN_00528bb6();
              }
            }
          }
          lVar3 = *(long *)(lVar3 + 0x10);
          if (lVar3 != 0) {
            pQVar8 = *(QArrayData **)(lVar3 + 0x18);
            if (*(int *)pQVar8 == 0) {
LAB_00908917:
              QArrayData::deallocate(pQVar8,2,8);
            }
            else if (*(int *)pQVar8 != -1) {
              LOCK();
              *(int *)pQVar8 = *(int *)pQVar8 + -1;
              UNLOCK();
              if (*(int *)pQVar8 == 0) {
                pQVar8 = *(QArrayData **)(lVar3 + 0x18);
                goto LAB_00908917;
              }
            }
            QVariant::~QVariant((QVariant *)(lVar3 + 0x20));
            lVar4 = *(long *)(lVar3 + 8);
            if (lVar4 != 0) {
              pQVar8 = *(QArrayData **)(lVar4 + 0x18);
              if (*(int *)pQVar8 == 0) {
LAB_00908d7a:
                QArrayData::deallocate(pQVar8,2,8);
              }
              else if (*(int *)pQVar8 != -1) {
                LOCK();
                *(int *)pQVar8 = *(int *)pQVar8 + -1;
                UNLOCK();
                if (*(int *)pQVar8 == 0) {
                  pQVar8 = *(QArrayData **)(lVar4 + 0x18);
                  goto LAB_00908d7a;
                }
              }
              QVariant::~QVariant((QVariant *)(lVar4 + 0x20));
              if (*(long *)(lVar4 + 8) != 0) {
                FUN_00528bb6();
              }
              if (*(long *)(lVar4 + 0x10) != 0) {
                FUN_00528bb6();
              }
            }
            lVar3 = *(long *)(lVar3 + 0x10);
            if (lVar3 != 0) {
              pQVar8 = *(QArrayData **)(lVar3 + 0x18);
              if (*(int *)pQVar8 == 0) {
LAB_00908d62:
                QArrayData::deallocate(pQVar8,2,8);
              }
              else if (*(int *)pQVar8 != -1) {
                LOCK();
                *(int *)pQVar8 = *(int *)pQVar8 + -1;
                UNLOCK();
                if (*(int *)pQVar8 == 0) {
                  pQVar8 = *(QArrayData **)(lVar3 + 0x18);
                  goto LAB_00908d62;
                }
              }
              QVariant::~QVariant((QVariant *)(lVar3 + 0x20));
              if (*(long *)(lVar3 + 8) != 0) {
                FUN_00528bb6();
              }
              if (*(long *)(lVar3 + 0x10) != 0) {
                FUN_00528bb6();
              }
            }
          }
        }
        lVar2 = *(long *)(lVar2 + 0x10);
        if (lVar2 != 0) {
          pQVar8 = *(QArrayData **)(lVar2 + 0x18);
          if (*(int *)pQVar8 == 0) {
LAB_00908825:
            QArrayData::deallocate(pQVar8,2,8);
          }
          else if (*(int *)pQVar8 != -1) {
            LOCK();
            *(int *)pQVar8 = *(int *)pQVar8 + -1;
            UNLOCK();
            if (*(int *)pQVar8 == 0) {
              pQVar8 = *(QArrayData **)(lVar2 + 0x18);
              goto LAB_00908825;
            }
          }
          QVariant::~QVariant((QVariant *)(lVar2 + 0x20));
          lVar3 = *(long *)(lVar2 + 8);
          if (lVar3 != 0) {
            pQVar8 = *(QArrayData **)(lVar3 + 0x18);
            if (*(int *)pQVar8 == 0) {
LAB_00908a0f:
              QArrayData::deallocate(pQVar8,2,8);
            }
            else if (*(int *)pQVar8 != -1) {
              LOCK();
              *(int *)pQVar8 = *(int *)pQVar8 + -1;
              UNLOCK();
              if (*(int *)pQVar8 == 0) {
                pQVar8 = *(QArrayData **)(lVar3 + 0x18);
                goto LAB_00908a0f;
              }
            }
            QVariant::~QVariant((QVariant *)(lVar3 + 0x20));
            lVar4 = *(long *)(lVar3 + 8);
            if (lVar4 != 0) {
              pQVar8 = *(QArrayData **)(lVar4 + 0x18);
              if (*(int *)pQVar8 == 0) {
LAB_00908d02:
                QArrayData::deallocate(pQVar8,2,8);
              }
              else if (*(int *)pQVar8 != -1) {
                LOCK();
                *(int *)pQVar8 = *(int *)pQVar8 + -1;
                UNLOCK();
                if (*(int *)pQVar8 == 0) {
                  pQVar8 = *(QArrayData **)(lVar4 + 0x18);
                  goto LAB_00908d02;
                }
              }
              QVariant::~QVariant((QVariant *)(lVar4 + 0x20));
              if (*(long *)(lVar4 + 8) != 0) {
                FUN_00528bb6();
              }
              if (*(long *)(lVar4 + 0x10) != 0) {
                FUN_00528bb6();
              }
            }
            lVar3 = *(long *)(lVar3 + 0x10);
            if (lVar3 != 0) {
              pQVar8 = *(QArrayData **)(lVar3 + 0x18);
              if (*(int *)pQVar8 == 0) {
LAB_00908cea:
                QArrayData::deallocate(pQVar8,2,8);
              }
              else if (*(int *)pQVar8 != -1) {
                LOCK();
                *(int *)pQVar8 = *(int *)pQVar8 + -1;
                UNLOCK();
                if (*(int *)pQVar8 == 0) {
                  pQVar8 = *(QArrayData **)(lVar3 + 0x18);
                  goto LAB_00908cea;
                }
              }
              QVariant::~QVariant((QVariant *)(lVar3 + 0x20));
              if (*(long *)(lVar3 + 8) != 0) {
                FUN_00528bb6();
              }
              if (*(long *)(lVar3 + 0x10) != 0) {
                FUN_00528bb6();
              }
            }
          }
          lVar2 = *(long *)(lVar2 + 0x10);
          if (lVar2 != 0) {
            pQVar8 = *(QArrayData **)(lVar2 + 0x18);
            if (*(int *)pQVar8 == 0) {
LAB_00908947:
              QArrayData::deallocate(pQVar8,2,8);
            }
            else if (*(int *)pQVar8 != -1) {
              LOCK();
              *(int *)pQVar8 = *(int *)pQVar8 + -1;
              UNLOCK();
              if (*(int *)pQVar8 == 0) {
                pQVar8 = *(QArrayData **)(lVar2 + 0x18);
                goto LAB_00908947;
              }
            }
            QVariant::~QVariant((QVariant *)(lVar2 + 0x20));
            lVar3 = *(long *)(lVar2 + 8);
            if (lVar3 != 0) {
              pQVar8 = *(QArrayData **)(lVar3 + 0x18);
              if (*(int *)pQVar8 == 0) {
LAB_00908bf0:
                QArrayData::deallocate(pQVar8,2,8);
              }
              else if (*(int *)pQVar8 != -1) {
                LOCK();
                *(int *)pQVar8 = *(int *)pQVar8 + -1;
                UNLOCK();
                if (*(int *)pQVar8 == 0) {
                  pQVar8 = *(QArrayData **)(lVar3 + 0x18);
                  goto LAB_00908bf0;
                }
              }
              QVariant::~QVariant((QVariant *)(lVar3 + 0x20));
              if (*(long *)(lVar3 + 8) != 0) {
                FUN_00528bb6();
              }
              if (*(long *)(lVar3 + 0x10) != 0) {
                FUN_00528bb6();
              }
            }
            lVar2 = *(long *)(lVar2 + 0x10);
            if (lVar2 != 0) {
              pQVar8 = *(QArrayData **)(lVar2 + 0x18);
              if (*(int *)pQVar8 == 0) {
LAB_00908d1a:
                QArrayData::deallocate(pQVar8,2,8);
              }
              else if (*(int *)pQVar8 != -1) {
                LOCK();
                *(int *)pQVar8 = *(int *)pQVar8 + -1;
                UNLOCK();
                if (*(int *)pQVar8 == 0) {
                  pQVar8 = *(QArrayData **)(lVar2 + 0x18);
                  goto LAB_00908d1a;
                }
              }
              QVariant::~QVariant((QVariant *)(lVar2 + 0x20));
              if (*(long *)(lVar2 + 8) != 0) {
                FUN_00528bb6();
              }
              if (*(long *)(lVar2 + 0x10) != 0) {
                FUN_00528bb6();
              }
            }
          }
        }
      }
      lVar1 = *(long *)(lVar1 + 0x10);
      if (lVar1 != 0) {
        pQVar8 = *(QArrayData **)(lVar1 + 0x18);
        if (*(int *)pQVar8 == 0) {
LAB_009087f5:
          QArrayData::deallocate(pQVar8,2,8);
        }
        else if (*(int *)pQVar8 != -1) {
          LOCK();
          *(int *)pQVar8 = *(int *)pQVar8 + -1;
          UNLOCK();
          if (*(int *)pQVar8 == 0) {
            pQVar8 = *(QArrayData **)(lVar1 + 0x18);
            goto LAB_009087f5;
          }
        }
        QVariant::~QVariant((QVariant *)(lVar1 + 0x20));
        lVar2 = *(long *)(lVar1 + 8);
        if (lVar2 != 0) {
          pQVar8 = *(QArrayData **)(lVar2 + 0x18);
          if (*(int *)pQVar8 == 0) {
LAB_009088b6:
            QArrayData::deallocate(pQVar8,2,8);
          }
          else if (*(int *)pQVar8 != -1) {
            LOCK();
            *(int *)pQVar8 = *(int *)pQVar8 + -1;
            UNLOCK();
            if (*(int *)pQVar8 == 0) {
              pQVar8 = *(QArrayData **)(lVar2 + 0x18);
              goto LAB_009088b6;
            }
          }
          QVariant::~QVariant((QVariant *)(lVar2 + 0x20));
          lVar3 = *(long *)(lVar2 + 8);
          if (lVar3 != 0) {
            pQVar8 = *(QArrayData **)(lVar3 + 0x18);
            if (*(int *)pQVar8 == 0) {
LAB_00908997:
              QArrayData::deallocate(pQVar8,2,8);
            }
            else if (*(int *)pQVar8 != -1) {
              LOCK();
              *(int *)pQVar8 = *(int *)pQVar8 + -1;
              UNLOCK();
              if (*(int *)pQVar8 == 0) {
                pQVar8 = *(QArrayData **)(lVar3 + 0x18);
                goto LAB_00908997;
              }
            }
            QVariant::~QVariant((QVariant *)(lVar3 + 0x20));
            lVar4 = *(long *)(lVar3 + 8);
            if (lVar4 != 0) {
              pQVar8 = *(QArrayData **)(lVar4 + 0x18);
              if (*(int *)pQVar8 == 0) {
LAB_00908b17:
                QArrayData::deallocate(pQVar8,2,8);
              }
              else if (*(int *)pQVar8 != -1) {
                LOCK();
                *(int *)pQVar8 = *(int *)pQVar8 + -1;
                UNLOCK();
                if (*(int *)pQVar8 == 0) {
                  pQVar8 = *(QArrayData **)(lVar4 + 0x18);
                  goto LAB_00908b17;
                }
              }
              QVariant::~QVariant((QVariant *)(lVar4 + 0x20));
              if (*(long *)(lVar4 + 8) != 0) {
                FUN_00528bb6();
              }
              if (*(long *)(lVar4 + 0x10) != 0) {
                FUN_00528bb6();
              }
            }
            lVar3 = *(long *)(lVar3 + 0x10);
            if (lVar3 != 0) {
              pQVar8 = *(QArrayData **)(lVar3 + 0x18);
              if (*(int *)pQVar8 == 0) {
LAB_00908a57:
                QArrayData::deallocate(pQVar8,2,8);
              }
              else if (*(int *)pQVar8 != -1) {
                LOCK();
                *(int *)pQVar8 = *(int *)pQVar8 + -1;
                UNLOCK();
                if (*(int *)pQVar8 == 0) {
                  pQVar8 = *(QArrayData **)(lVar3 + 0x18);
                  goto LAB_00908a57;
                }
              }
              QVariant::~QVariant((QVariant *)(lVar3 + 0x20));
              if (*(long *)(lVar3 + 8) != 0) {
                FUN_00528bb6();
              }
              if (*(long *)(lVar3 + 0x10) != 0) {
                FUN_00528bb6();
              }
            }
          }
          lVar2 = *(long *)(lVar2 + 0x10);
          if (lVar2 != 0) {
            pQVar8 = *(QArrayData **)(lVar2 + 0x18);
            if (*(int *)pQVar8 == 0) {
LAB_0090897f:
              QArrayData::deallocate(pQVar8,2,8);
            }
            else if (*(int *)pQVar8 != -1) {
              LOCK();
              *(int *)pQVar8 = *(int *)pQVar8 + -1;
              UNLOCK();
              if (*(int *)pQVar8 == 0) {
                pQVar8 = *(QArrayData **)(lVar2 + 0x18);
                goto LAB_0090897f;
              }
            }
            QVariant::~QVariant((QVariant *)(lVar2 + 0x20));
            lVar3 = *(long *)(lVar2 + 8);
            if (lVar3 != 0) {
              pQVar8 = *(QArrayData **)(lVar3 + 0x18);
              if (*(int *)pQVar8 == 0) {
LAB_00908adf:
                QArrayData::deallocate(pQVar8,2,8);
              }
              else if (*(int *)pQVar8 != -1) {
                LOCK();
                *(int *)pQVar8 = *(int *)pQVar8 + -1;
                UNLOCK();
                if (*(int *)pQVar8 == 0) {
                  pQVar8 = *(QArrayData **)(lVar3 + 0x18);
                  goto LAB_00908adf;
                }
              }
              QVariant::~QVariant((QVariant *)(lVar3 + 0x20));
              if (*(long *)(lVar3 + 8) != 0) {
                FUN_00528bb6();
              }
              if (*(long *)(lVar3 + 0x10) != 0) {
                FUN_00528bb6();
              }
            }
            lVar2 = *(long *)(lVar2 + 0x10);
            if (lVar2 != 0) {
              pQVar8 = *(QArrayData **)(lVar2 + 0x18);
              if (*(int *)pQVar8 == 0) {
LAB_00908ac7:
                QArrayData::deallocate(pQVar8,2,8);
              }
              else if (*(int *)pQVar8 != -1) {
                LOCK();
                *(int *)pQVar8 = *(int *)pQVar8 + -1;
                UNLOCK();
                if (*(int *)pQVar8 == 0) {
                  pQVar8 = *(QArrayData **)(lVar2 + 0x18);
                  goto LAB_00908ac7;
                }
              }
              QVariant::~QVariant((QVariant *)(lVar2 + 0x20));
              if (*(long *)(lVar2 + 8) != 0) {
                FUN_00528bb6();
              }
              if (*(long *)(lVar2 + 0x10) != 0) {
                FUN_00528bb6();
              }
            }
          }
        }
        lVar1 = *(long *)(lVar1 + 0x10);
        if (lVar1 != 0) {
          pQVar8 = *(QArrayData **)(lVar1 + 0x18);
          if (*(int *)pQVar8 == 0) {
LAB_0090886e:
            QArrayData::deallocate(pQVar8,2,8);
          }
          else if (*(int *)pQVar8 != -1) {
            LOCK();
            *(int *)pQVar8 = *(int *)pQVar8 + -1;
            UNLOCK();
            if (*(int *)pQVar8 == 0) {
              pQVar8 = *(QArrayData **)(lVar1 + 0x18);
              goto LAB_0090886e;
            }
          }
          QVariant::~QVariant((QVariant *)(lVar1 + 0x20));
          lVar2 = *(long *)(lVar1 + 8);
          if (lVar2 != 0) {
            pQVar8 = *(QArrayData **)(lVar2 + 0x18);
            if (*(int *)pQVar8 == 0) {
LAB_009089af:
              QArrayData::deallocate(pQVar8,2,8);
            }
            else if (*(int *)pQVar8 != -1) {
              LOCK();
              *(int *)pQVar8 = *(int *)pQVar8 + -1;
              UNLOCK();
              if (*(int *)pQVar8 == 0) {
                pQVar8 = *(QArrayData **)(lVar2 + 0x18);
                goto LAB_009089af;
              }
            }
            QVariant::~QVariant((QVariant *)(lVar2 + 0x20));
            lVar3 = *(long *)(lVar2 + 8);
            if (lVar3 != 0) {
              pQVar8 = *(QArrayData **)(lVar3 + 0x18);
              if (*(int *)pQVar8 == 0) {
LAB_00908b77:
                QArrayData::deallocate(pQVar8,2,8);
              }
              else if (*(int *)pQVar8 != -1) {
                LOCK();
                *(int *)pQVar8 = *(int *)pQVar8 + -1;
                UNLOCK();
                if (*(int *)pQVar8 == 0) {
                  pQVar8 = *(QArrayData **)(lVar3 + 0x18);
                  goto LAB_00908b77;
                }
              }
              QVariant::~QVariant((QVariant *)(lVar3 + 0x20));
              if (*(long *)(lVar3 + 8) != 0) {
                FUN_00528bb6();
              }
              if (*(long *)(lVar3 + 0x10) != 0) {
                FUN_00528bb6();
              }
            }
            lVar2 = *(long *)(lVar2 + 0x10);
            if (lVar2 != 0) {
              pQVar8 = *(QArrayData **)(lVar2 + 0x18);
              if (*(int *)pQVar8 == 0) {
LAB_00908b5f:
                QArrayData::deallocate(pQVar8,2,8);
              }
              else if (*(int *)pQVar8 != -1) {
                LOCK();
                *(int *)pQVar8 = *(int *)pQVar8 + -1;
                UNLOCK();
                if (*(int *)pQVar8 == 0) {
                  pQVar8 = *(QArrayData **)(lVar2 + 0x18);
                  goto LAB_00908b5f;
                }
              }
              QVariant::~QVariant((QVariant *)(lVar2 + 0x20));
              if (*(long *)(lVar2 + 8) != 0) {
                FUN_00528bb6();
              }
              if (*(long *)(lVar2 + 0x10) != 0) {
                FUN_00528bb6();
              }
            }
          }
          lVar1 = *(long *)(lVar1 + 0x10);
          if (lVar1 != 0) {
            pQVar8 = *(QArrayData **)(lVar1 + 0x18);
            if (*(int *)pQVar8 == 0) {
LAB_009088cf:
              QArrayData::deallocate(pQVar8,2,8);
            }
            else if (*(int *)pQVar8 != -1) {
              LOCK();
              *(int *)pQVar8 = *(int *)pQVar8 + -1;
              UNLOCK();
              if (*(int *)pQVar8 == 0) {
                pQVar8 = *(QArrayData **)(lVar1 + 0x18);
                goto LAB_009088cf;
              }
            }
            QVariant::~QVariant((QVariant *)(lVar1 + 0x20));
            lVar2 = *(long *)(lVar1 + 8);
            if (lVar2 != 0) {
              pQVar8 = *(QArrayData **)(lVar2 + 0x18);
              if (*(int *)pQVar8 == 0) {
LAB_00908b2f:
                QArrayData::deallocate(pQVar8,2,8);
              }
              else if (*(int *)pQVar8 != -1) {
                LOCK();
                *(int *)pQVar8 = *(int *)pQVar8 + -1;
                UNLOCK();
                if (*(int *)pQVar8 == 0) {
                  pQVar8 = *(QArrayData **)(lVar2 + 0x18);
                  goto LAB_00908b2f;
                }
              }
              QVariant::~QVariant((QVariant *)(lVar2 + 0x20));
              if (*(long *)(lVar2 + 8) != 0) {
                FUN_00528bb6();
              }
              if (*(long *)(lVar2 + 0x10) != 0) {
                FUN_00528bb6();
              }
            }
            lVar1 = *(long *)(lVar1 + 0x10);
            if (lVar1 != 0) {
              pQVar8 = *(QArrayData **)(lVar1 + 0x18);
              if (*(int *)pQVar8 == 0) {
LAB_00908bd8:
                QArrayData::deallocate(pQVar8,2,8);
              }
              else if (*(int *)pQVar8 != -1) {
                LOCK();
                *(int *)pQVar8 = *(int *)pQVar8 + -1;
                UNLOCK();
                if (*(int *)pQVar8 == 0) {
                  pQVar8 = *(QArrayData **)(lVar1 + 0x18);
                  goto LAB_00908bd8;
                }
              }
              QVariant::~QVariant((QVariant *)(lVar1 + 0x20));
              if (*(long *)(lVar1 + 8) != 0) {
                FUN_00528bb6();
              }
              if (*(long *)(lVar1 + 0x10) != 0) {
                FUN_00528bb6();
              }
            }
          }
        }
      }
    }
    QMapDataBase::freeTree(pQVar7,(int)*(undefined8 *)(pQVar7 + 0x10));
  }
  QMapDataBase::freeData((QMapDataBase *)pQVar7);
LAB_0090771e:
  QDialog::~QDialog(param_1);
  operator_delete(param_1,0x70);
  return;
}


// ==== entry=00908d8e name=FUN_00908d8e size=1 ====

void FUN_00908d8e(void)

{
  return;
}


// ==== entry=00908d90 orig=FUN_00908d90 size=24 name=SyncInputDialog_metaObject ====

undefined ** SyncInputDialog_metaObject(long param_1)

{
  undefined **ppuVar1;
  
  if (*(long *)(*(long *)(param_1 + 8) + 0x28) != 0) {
    ppuVar1 = (undefined **)QObjectData::dynamicMetaObject();
    return ppuVar1;
  }
  return &PTR_staticMetaObject_011a4500;
}


// ==== entry=00908da8 orig=FUN_00908da8 size=66 name=SyncInputDialog_qt_metacast ====

char * SyncInputDialog_qt_metacast(char *param_1,char *param_2)

{
  int iVar1;
  char *pcVar2;
  
  if (param_2 == (char *)0x0) {
    return (char *)0x0;
  }
  iVar1 = strcmp(param_2,"SyncInputDialog");
  if (iVar1 == 0) {
    return param_1;
  }
  pcVar2 = (char *)QDialog::qt_metacast(param_1);
  return pcVar2;
}


// ==== entry=00908dea orig=FUN_00908dea size=5 name=SyncInputDialog_qt_metacall ====

void QDialog::SyncInputDialog_qt_metacall(void)

{
  qt_metacall();
  return;
}


// ==== entry=00908df0 orig=FUN_00908df0 size=92 name=SyncInputDialog_dtor_deleting ====

void SyncInputDialog_dtor_deleting(QDialog *param_1)

{
  QArrayData *pQVar1;
  
  *(undefined ***)param_1 = &SyncInputDialog_vtable;
  *(undefined ***)(param_1 + 0x10) = &PTR_FUN_011a44b0;
  pQVar1 = *(QArrayData **)(param_1 + 0x68);
  if (*(int *)pQVar1 != 0) {
    if (*(int *)pQVar1 == -1) goto LAB_00908e21;
    LOCK();
    *(int *)pQVar1 = *(int *)pQVar1 + -1;
    UNLOCK();
    if (*(int *)pQVar1 != 0) goto LAB_00908e21;
    pQVar1 = *(QArrayData **)(param_1 + 0x68);
  }
  QArrayData::deallocate(pQVar1,2,8);
LAB_00908e21:
  QDialog::~QDialog(param_1);
  operator_delete(param_1,0x70);
  return;
}


// ==== entry=00908e4c name=FUN_00908e4c size=96 ====

void FUN_00908e4c(undefined8 *param_1)

{
  QArrayData *pQVar1;
  
  param_1[-2] = &SyncInputDialog_vtable;
  *param_1 = &PTR_FUN_011a44b0;
  pQVar1 = (QArrayData *)param_1[0xb];
  if (*(int *)pQVar1 != 0) {
    if (*(int *)pQVar1 == -1) goto LAB_00908e7e;
    LOCK();
    *(int *)pQVar1 = *(int *)pQVar1 + -1;
    UNLOCK();
    if (*(int *)pQVar1 != 0) goto LAB_00908e7e;
    pQVar1 = (QArrayData *)param_1[0xb];
  }
  QArrayData::deallocate(pQVar1,2,8);
LAB_00908e7e:
  QDialog::~QDialog((QDialog *)(param_1 + -2));
  operator_delete((QDialog *)(param_1 + -2),0x70);
  return;
}


// ==== entry=00908eac name=FUN_00908eac size=88 ====

void FUN_00908eac(undefined8 *param_1)

{
  QArrayData *pQVar1;
  
  param_1[-2] = &SyncInputDialog_vtable;
  *param_1 = &PTR_FUN_011a44b0;
  pQVar1 = (QArrayData *)param_1[0xb];
  if (*(int *)pQVar1 == 0) {
LAB_00908eeb:
    QArrayData::deallocate(pQVar1,2,8);
    QDialog::~QDialog((QDialog *)(param_1 + -2));
    return;
  }
  if (*(int *)pQVar1 != -1) {
    LOCK();
    *(int *)pQVar1 = *(int *)pQVar1 + -1;
    UNLOCK();
    if (*(int *)pQVar1 == 0) {
      pQVar1 = (QArrayData *)param_1[0xb];
      goto LAB_00908eeb;
    }
  }
  QDialog::~QDialog((QDialog *)(param_1 + -2));
  return;
}


// ==== entry=00908f04 orig=FUN_00908f04 size=86 name=SyncInputDialog_dtor ====

void SyncInputDialog_dtor(QDialog *param_1)

{
  QArrayData *pQVar1;
  
  *(undefined ***)param_1 = &SyncInputDialog_vtable;
  *(undefined ***)(param_1 + 0x10) = &PTR_FUN_011a44b0;
  pQVar1 = *(QArrayData **)(param_1 + 0x68);
  if (*(int *)pQVar1 == 0) {
LAB_00908f42:
    QArrayData::deallocate(pQVar1,2,8);
    QDialog::~QDialog(param_1);
    return;
  }
  if (*(int *)pQVar1 != -1) {
    LOCK();
    *(int *)pQVar1 = *(int *)pQVar1 + -1;
    UNLOCK();
    if (*(int *)pQVar1 == 0) {
      pQVar1 = *(QArrayData **)(param_1 + 0x68);
      goto LAB_00908f42;
    }
  }
  QDialog::~QDialog(param_1);
  return;
}


// ==== entry=00908f5a name=FUN_00908f5a size=1 ====

void FUN_00908f5a(void)

{
  return;
}


// ==== entry=00908f5c orig=FUN_00908f5c size=24 name=TextMarkDialog_metaObject ====

undefined ** TextMarkDialog_metaObject(long param_1)

{
  undefined **ppuVar1;
  
  if (*(long *)(*(long *)(param_1 + 8) + 0x28) != 0) {
    ppuVar1 = (undefined **)QObjectData::dynamicMetaObject();
    return ppuVar1;
  }
  return &PTR_staticMetaObject_011a4780;
}


// ==== entry=00908f74 orig=FUN_00908f74 size=66 name=TextMarkDialog_qt_metacast ====

char * TextMarkDialog_qt_metacast(char *param_1,char *param_2)

{
  int iVar1;
  char *pcVar2;
  
  if (param_2 == (char *)0x0) {
    return (char *)0x0;
  }
  iVar1 = strcmp(param_2,"TextMarkDialog");
  if (iVar1 == 0) {
    return param_1;
  }
  pcVar2 = (char *)QDialog::qt_metacast(param_1);
  return pcVar2;
}


// ==== entry=00908fb6 orig=FUN_00908fb6 size=5 name=TextMarkDialog_qt_metacall ====

void QDialog::TextMarkDialog_qt_metacall(void)

{
  qt_metacall();
  return;
}


// ==== entry=00908fbc orig=FUN_00908fbc size=29 name=TextMarkDialog_dtor ====

void TextMarkDialog_dtor(QDialog *param_1)

{
  *(undefined ***)param_1 = &TextMarkDialog_vtable;
  *(undefined ***)(param_1 + 0x10) = &PTR_FUN_011a4730;
  QDialog::~QDialog(param_1);
  return;
}


// ==== entry=00908fd9 name=FUN_00908fd9 size=33 ====

void FUN_00908fd9(undefined8 *param_1)

{
  param_1[-2] = &TextMarkDialog_vtable;
  *param_1 = &PTR_FUN_011a4730;
  QDialog::~QDialog((QDialog *)(param_1 + -2));
  return;
}


// ==== entry=00908ffa orig=FUN_00908ffa size=47 name=TextMarkDialog_dtor_deleting ====

void TextMarkDialog_dtor_deleting(QDialog *param_1)

{
  *(undefined ***)param_1 = &TextMarkDialog_vtable;
  *(undefined ***)(param_1 + 0x10) = &PTR_FUN_011a4730;
  QDialog::~QDialog(param_1);
  operator_delete(param_1,0x78);
  return;
}


// ==== entry=00909029 name=FUN_00909029 size=51 ====

void FUN_00909029(undefined8 *param_1)

{
  param_1[-2] = &TextMarkDialog_vtable;
  *param_1 = &PTR_FUN_011a4730;
  QDialog::~QDialog((QDialog *)(param_1 + -2));
  operator_delete((QDialog *)(param_1 + -2),0x78);
  return;
}


// ==== entry=00909060 name=FUN_00909060 size=1 ====

void FUN_00909060(void)

{
  return;
}


// ==== entry=00909062 name=FUN_00909062 size=24 ====

undefined ** FUN_00909062(long param_1)

{
  undefined **ppuVar1;
  
  if (*(long *)(*(long *)(param_1 + 8) + 0x28) != 0) {
    ppuVar1 = (undefined **)QObjectData::dynamicMetaObject();
    return ppuVar1;
  }
  return &PTR_staticMetaObject_011a4c60;
}


// ==== entry=0090907a orig=FUN_0090907a size=24 name=TriggerDialog_metaObject ====

undefined ** TriggerDialog_metaObject(long param_1)

{
  undefined **ppuVar1;
  
  if (*(long *)(*(long *)(param_1 + 8) + 0x28) != 0) {
    ppuVar1 = (undefined **)QObjectData::dynamicMetaObject();
    return ppuVar1;
  }
  return &PTR_staticMetaObject_011a4c20;
}


// ==== entry=00909092 name=FUN_00909092 size=52 ====

void FUN_00909092(QObject *param_1,undefined1 param_2)

{
  undefined1 local_1c [4];
  void *local_18;
  undefined1 *local_10;
  
  local_18 = (void *)0x0;
  local_10 = local_1c;
  local_1c[0] = param_2;
  QMetaObject::activate(param_1,(QMetaObject *)&PTR_staticMetaObject_011a4c60,0,&local_18);
  return;
}


// ==== entry=009090c6 name=FUN_009090c6 size=59 ====

void FUN_009090c6(undefined8 param_1,int param_2,int param_3,undefined8 *param_4)

{
  if (param_2 == 0) {
    if (param_3 == 0) {
      FUN_00909092(param_1,*(undefined1 *)param_4[1]);
      return;
    }
  }
  else if (((param_2 == 10) && (*(code **)param_4[1] == FUN_00909092)) &&
          (((long *)param_4[1])[1] == 0)) {
    *(undefined4 *)*param_4 = 0;
    return;
  }
  return;
}


// ==== entry=00909101 name=FUN_00909101 size=360 ====

void FUN_00909101(void)

{
  long lVar1;
  long *in_FS_OFFSET;
  
  if (*(char *)(*in_FS_OFFSET + -0xfd) == '\0') {
    *(undefined1 *)(*in_FS_OFFSET + -0xfd) = 1;
    if (*(char *)(*in_FS_OFFSET + -0x138) == '\0') {
      *(char *)(*in_FS_OFFSET + -0x138) = '\x01';
      lVar1 = *in_FS_OFFSET;
      *(undefined8 *)(lVar1 + -0x110) = &QMapDataBase::shared_null;
      __cxa_thread_atexit(FUN_00558fe0,(undefined8 *)(lVar1 + -0x110),&DAT_00c89008);
    }
    if (*(char *)(*in_FS_OFFSET + -0x140) == '\0') {
      *(char *)(*in_FS_OFFSET + -0x140) = '\x01';
      lVar1 = *in_FS_OFFSET;
      *(undefined8 *)(lVar1 + -0x120) = &QMapDataBase::shared_null;
      __cxa_thread_atexit(FUN_005594f0,(undefined8 *)(lVar1 + -0x120),&DAT_00c89008);
    }
    if (*(char *)(*in_FS_OFFSET + -0x148) == '\0') {
      *(char *)(*in_FS_OFFSET + -0x148) = '\x01';
      lVar1 = *in_FS_OFFSET;
      *(undefined8 *)(lVar1 + -0x118) = &QMapDataBase::shared_null;
      __cxa_thread_atexit(FUN_00559a00,(undefined8 *)(lVar1 + -0x118),&DAT_00c89008);
    }
    if (*(char *)(*in_FS_OFFSET + -0x150) == '\0') {
      *(char *)(*in_FS_OFFSET + -0x150) = '\x01';
      lVar1 = *in_FS_OFFSET;
      *(undefined8 *)(lVar1 + -0x128) = &QMapDataBase::shared_null;
      __cxa_thread_atexit(FUN_00559f10,(undefined8 *)(lVar1 + -0x128),&DAT_00c89008);
      return;
    }
  }
  return;
}


// ==== entry=0090926a orig=FUN_0090926a size=66 name=s_TriggerPage_90926a ====

char * s_TriggerPage_90926a(char *param_1,char *param_2)

{
  int iVar1;
  char *pcVar2;
  
  if (param_2 == (char *)0x0) {
    return (char *)0x0;
  }
  iVar1 = strcmp(param_2,"TriggerPage");
  if (iVar1 == 0) {
    return param_1;
  }
  pcVar2 = (char *)QWidget::qt_metacast(param_1);
  return pcVar2;
}


// ==== entry=009092ac name=FUN_009092ac size=96 ====

ulong FUN_009092ac(undefined8 param_1,int param_2,undefined8 param_3,undefined8 *param_4)

{
  int iVar1;
  ulong uVar2;
  
  uVar2 = QWidget::qt_metacall();
  iVar1 = (int)uVar2;
  if (-1 < iVar1) {
    if (param_2 == 0) {
      if (iVar1 == 0) {
        FUN_00909092(param_1,*(undefined1 *)param_4[1]);
        uVar2 = uVar2 & 0xffffffff;
      }
    }
    else {
      if (param_2 != 0xc) {
        return uVar2;
      }
      if (iVar1 == 0) {
        *(undefined4 *)*param_4 = 0xffffffff;
      }
    }
    uVar2 = (ulong)((int)uVar2 - 1);
  }
  return uVar2;
}


// ==== entry=0090930c orig=FUN_0090930c size=66 name=TriggerDialog_qt_metacast ====

char * TriggerDialog_qt_metacast(char *param_1,char *param_2)

{
  int iVar1;
  char *pcVar2;
  
  if (param_2 == (char *)0x0) {
    return (char *)0x0;
  }
  iVar1 = strcmp(param_2,"TriggerDialog");
  if (iVar1 == 0) {
    return param_1;
  }
  pcVar2 = (char *)QDialog::qt_metacast(param_1);
  return pcVar2;
}


// ==== entry=0090934e orig=FUN_0090934e size=5 name=TriggerDialog_qt_metacall ====

void QDialog::TriggerDialog_qt_metacall(void)

{
  qt_metacall();
  return;
}


// ==== entry=00909354 orig=FUN_00909354 size=250 name=TriggerDialog_dtor ====

void TriggerDialog_dtor(QDialog *param_1)

{
  int iVar1;
  long lVar2;
  QArrayData *pQVar3;
  QMapNodeBase *pQVar4;
  QArrayData *pQVar5;
  
  *(undefined ***)param_1 = &TriggerDialog_vtable;
  *(undefined ***)(param_1 + 0x10) = &PTR_FUN_011a4bd8;
  FUN_0069f90c(param_1 + 0x98);
  pQVar3 = *(QArrayData **)(param_1 + 0x90);
  if (*(int *)pQVar3 == 0) {
LAB_009093d6:
    lVar2 = *(long *)(pQVar3 + 0x10);
    iVar1 = *(int *)(pQVar3 + 4);
    for (pQVar5 = pQVar3 + lVar2; pQVar3 + lVar2 + (long)iVar1 * 0x48 != pQVar5;
        pQVar5 = pQVar5 + 0x48) {
      FUN_0069f90c();
    }
    QArrayData::deallocate(pQVar3,0x48,8);
    pQVar4 = *(QMapNodeBase **)(param_1 + 0x88);
    iVar1 = *(int *)pQVar4;
  }
  else {
    if (*(int *)pQVar3 != -1) {
      LOCK();
      *(int *)pQVar3 = *(int *)pQVar3 + -1;
      UNLOCK();
      if (*(int *)pQVar3 == 0) {
        pQVar3 = *(QArrayData **)(param_1 + 0x90);
        goto LAB_009093d6;
      }
    }
    pQVar4 = *(QMapNodeBase **)(param_1 + 0x88);
    iVar1 = *(int *)pQVar4;
  }
  if (iVar1 != 0) {
    if (iVar1 == -1) goto LAB_009093bd;
    LOCK();
    *(int *)pQVar4 = *(int *)pQVar4 + -1;
    UNLOCK();
    if (*(int *)pQVar4 != 0) goto LAB_009093bd;
    pQVar4 = *(QMapNodeBase **)(param_1 + 0x88);
  }
  if (*(long *)(pQVar4 + 0x10) != 0) {
    QMapDataBase::freeTree(pQVar4,(int)*(long *)(pQVar4 + 0x10));
  }
  QMapDataBase::freeData((QMapDataBase *)pQVar4);
LAB_009093bd:
  QDialog::~QDialog(param_1);
  return;
}


// ==== entry=0090944e name=FUN_0090944e size=242 ====

void FUN_0090944e(undefined8 *param_1)

{
  int iVar1;
  long lVar2;
  QArrayData *pQVar3;
  QMapNodeBase *pQVar4;
  QArrayData *pQVar5;
  
  param_1[-2] = &TriggerDialog_vtable;
  *param_1 = &PTR_FUN_011a4bd8;
  FUN_0069f90c(param_1 + 0x11);
  pQVar3 = (QArrayData *)param_1[0x10];
  if (*(int *)pQVar3 == 0) {
LAB_009094ce:
    lVar2 = *(long *)(pQVar3 + 0x10);
    iVar1 = *(int *)(pQVar3 + 4);
    for (pQVar5 = pQVar3 + lVar2; pQVar3 + lVar2 + (long)iVar1 * 0x48 != pQVar5;
        pQVar5 = pQVar5 + 0x48) {
      FUN_0069f90c();
    }
    QArrayData::deallocate(pQVar3,0x48,8);
    pQVar4 = (QMapNodeBase *)param_1[0xf];
    iVar1 = *(int *)pQVar4;
  }
  else {
    if (*(int *)pQVar3 != -1) {
      LOCK();
      *(int *)pQVar3 = *(int *)pQVar3 + -1;
      UNLOCK();
      if (*(int *)pQVar3 == 0) {
        pQVar3 = (QArrayData *)param_1[0x10];
        goto LAB_009094ce;
      }
    }
    pQVar4 = (QMapNodeBase *)param_1[0xf];
    iVar1 = *(int *)pQVar4;
  }
  if (iVar1 != 0) {
    if (iVar1 == -1) goto LAB_009094b4;
    LOCK();
    *(int *)pQVar4 = *(int *)pQVar4 + -1;
    UNLOCK();
    if (*(int *)pQVar4 != 0) goto LAB_009094b4;
    pQVar4 = (QMapNodeBase *)param_1[0xf];
  }
  if (*(long *)(pQVar4 + 0x10) != 0) {
    QMapDataBase::freeTree(pQVar4,(int)*(long *)(pQVar4 + 0x10));
  }
  QMapDataBase::freeData((QMapDataBase *)pQVar4);
LAB_009094b4:
  QDialog::~QDialog((QDialog *)(param_1 + -2));
  return;
}


// ==== entry=00909540 name=FUN_00909540 size=254 ====

void FUN_00909540(undefined8 *param_1)

{
  int iVar1;
  long lVar2;
  QArrayData *pQVar3;
  QMapNodeBase *pQVar4;
  QArrayData *pQVar5;
  
  param_1[-2] = &TriggerDialog_vtable;
  *param_1 = &PTR_FUN_011a4bd8;
  FUN_0069f90c(param_1 + 0x11);
  pQVar3 = (QArrayData *)param_1[0x10];
  if (*(int *)pQVar3 == 0) {
LAB_009095cc:
    lVar2 = *(long *)(pQVar3 + 0x10);
    iVar1 = *(int *)(pQVar3 + 4);
    for (pQVar5 = pQVar3 + lVar2; pQVar3 + lVar2 + (long)iVar1 * 0x48 != pQVar5;
        pQVar5 = pQVar5 + 0x48) {
      FUN_0069f90c();
    }
    QArrayData::deallocate(pQVar3,0x48,8);
    pQVar4 = (QMapNodeBase *)param_1[0xf];
    iVar1 = *(int *)pQVar4;
  }
  else {
    if (*(int *)pQVar3 != -1) {
      LOCK();
      *(int *)pQVar3 = *(int *)pQVar3 + -1;
      UNLOCK();
      if (*(int *)pQVar3 == 0) {
        pQVar3 = (QArrayData *)param_1[0x10];
        goto LAB_009095cc;
      }
    }
    pQVar4 = (QMapNodeBase *)param_1[0xf];
    iVar1 = *(int *)pQVar4;
  }
  if (iVar1 != 0) {
    if (iVar1 == -1) goto LAB_009095a8;
    LOCK();
    *(int *)pQVar4 = *(int *)pQVar4 + -1;
    UNLOCK();
    if (*(int *)pQVar4 != 0) goto LAB_009095a8;
    pQVar4 = (QMapNodeBase *)param_1[0xf];
  }
  if (*(long *)(pQVar4 + 0x10) != 0) {
    QMapDataBase::freeTree(pQVar4,(int)*(long *)(pQVar4 + 0x10));
  }
  QMapDataBase::freeData((QMapDataBase *)pQVar4);
LAB_009095a8:
  QDialog::~QDialog((QDialog *)(param_1 + -2));
  operator_delete((QDialog *)(param_1 + -2),0xe0);
  return;
}


// ==== entry=0090963e orig=FUN_0090963e size=271 name=TriggerDialog_dtor_deleting ====

void TriggerDialog_dtor_deleting(QDialog *param_1)

{
  int iVar1;
  long lVar2;
  QArrayData *pQVar3;
  QMapNodeBase *pQVar4;
  QArrayData *pQVar5;
  
  *(undefined ***)param_1 = &TriggerDialog_vtable;
  *(undefined ***)(param_1 + 0x10) = &PTR_FUN_011a4bd8;
  FUN_0069f90c(param_1 + 0x98);
  pQVar3 = *(QArrayData **)(param_1 + 0x90);
  if (*(int *)pQVar3 == 0) {
LAB_009096d1:
    lVar2 = *(long *)(pQVar3 + 0x10);
    iVar1 = *(int *)(pQVar3 + 4);
    for (pQVar5 = pQVar3 + lVar2; pQVar3 + lVar2 + (long)iVar1 * 0x48 != pQVar5;
        pQVar5 = pQVar5 + 0x48) {
      FUN_0069f90c();
    }
    QArrayData::deallocate(pQVar3,0x48,8);
    pQVar4 = *(QMapNodeBase **)(param_1 + 0x88);
    iVar1 = *(int *)pQVar4;
  }
  else {
    if (*(int *)pQVar3 != -1) {
      LOCK();
      *(int *)pQVar3 = *(int *)pQVar3 + -1;
      UNLOCK();
      if (*(int *)pQVar3 == 0) {
        pQVar3 = *(QArrayData **)(param_1 + 0x90);
        goto LAB_009096d1;
      }
    }
    pQVar4 = *(QMapNodeBase **)(param_1 + 0x88);
    iVar1 = *(int *)pQVar4;
  }
  if (iVar1 != 0) {
    if (iVar1 == -1) goto LAB_009096ab;
    LOCK();
    *(int *)pQVar4 = *(int *)pQVar4 + -1;
    UNLOCK();
    if (*(int *)pQVar4 != 0) goto LAB_009096ab;
    pQVar4 = *(QMapNodeBase **)(param_1 + 0x88);
  }
  if (*(long *)(pQVar4 + 0x10) != 0) {
    QMapDataBase::freeTree(pQVar4,(int)*(long *)(pQVar4 + 0x10));
  }
  QMapDataBase::freeData((QMapDataBase *)pQVar4);
LAB_009096ab:
  QDialog::~QDialog(param_1);
  operator_delete(param_1,0xe0);
  return;
}


// ==== entry=0090974e name=FUN_0090974e size=1 ====

void FUN_0090974e(void)

{
  return;
}


// ==== entry=00909750 orig=FUN_00909750 size=24 name=TunnelDialog_metaObject ====

undefined ** TunnelDialog_metaObject(long param_1)

{
  undefined **ppuVar1;
  
  if (*(long *)(*(long *)(param_1 + 8) + 0x28) != 0) {
    ppuVar1 = (undefined **)QObjectData::dynamicMetaObject();
    return ppuVar1;
  }
  return &PTR_staticMetaObject_011a4ee0;
}


// ==== entry=00909768 orig=FUN_00909768 size=66 name=TunnelDialog_qt_metacast ====

char * TunnelDialog_qt_metacast(char *param_1,char *param_2)

{
  int iVar1;
  char *pcVar2;
  
  if (param_2 == (char *)0x0) {
    return (char *)0x0;
  }
  iVar1 = strcmp(param_2,"TunnelDialog");
  if (iVar1 == 0) {
    return param_1;
  }
  pcVar2 = (char *)QDialog::qt_metacast(param_1);
  return pcVar2;
}


// ==== entry=009097aa orig=FUN_009097aa size=5 name=TunnelDialog_qt_metacall ====

void QDialog::TunnelDialog_qt_metacall(void)

{
  qt_metacall();
  return;
}


// ==== entry=009097b0 name=FUN_009097b0 size=535 ====

void FUN_009097b0(QArrayData *param_1)

{
  int iVar1;
  long lVar2;
  QArrayData *pQVar3;
  int iVar4;
  QArrayData *pQVar5;
  QArrayData *pQVar6;
  
  lVar2 = *(long *)(param_1 + 0x10);
  iVar1 = *(int *)(param_1 + 4);
  pQVar5 = param_1 + lVar2;
  do {
    while( true ) {
      pQVar3 = pQVar5;
      if (param_1 + lVar2 + (long)iVar1 * 0x48 == pQVar3) {
        QArrayData::deallocate(param_1,0x48,8);
        return;
      }
      pQVar5 = pQVar3 + 0x48;
      pQVar6 = *(QArrayData **)(pQVar3 + 0x38);
      if (*(int *)pQVar6 != 0) break;
      QArrayData::deallocate(pQVar6,2,8);
LAB_009098b6:
      pQVar6 = *(QArrayData **)(pQVar3 + 0x20);
      iVar4 = *(int *)pQVar6;
      if (iVar4 == 0) goto LAB_009098c4;
LAB_0090980a:
      if (iVar4 != -1) {
        LOCK();
        iVar4 = *(int *)pQVar6;
        *(int *)pQVar6 = *(int *)pQVar6 + -1;
        UNLOCK();
        if (iVar4 != 1) goto LAB_00909820;
        QArrayData::deallocate(*(QArrayData **)(pQVar3 + 0x20),2,8);
        goto LAB_009098d3;
      }
LAB_00909820:
      pQVar6 = *(QArrayData **)(pQVar3 + 0x10);
      iVar4 = *(int *)pQVar6;
      if (iVar4 != 0) goto LAB_0090982e;
LAB_009098e1:
      QArrayData::deallocate(pQVar6,2,8);
LAB_009098f0:
      pQVar6 = *(QArrayData **)(pQVar3 + 8);
      iVar4 = *(int *)pQVar6;
      if (iVar4 == 0) goto LAB_009098fe;
LAB_00909852:
      if (iVar4 != -1) {
        LOCK();
        iVar4 = *(int *)pQVar6;
        *(int *)pQVar6 = *(int *)pQVar6 + -1;
        UNLOCK();
        if (iVar4 != 1) goto LAB_00909868;
        QArrayData::deallocate(*(QArrayData **)(pQVar3 + 8),2,8);
        goto LAB_0090990d;
      }
LAB_00909868:
      pQVar6 = *(QArrayData **)pQVar3;
      iVar4 = *(int *)pQVar6;
      if (iVar4 != 0) goto LAB_00909876;
LAB_0090991b:
      QArrayData::deallocate(pQVar6,2,8);
    }
    if (*(int *)pQVar6 != -1) {
      LOCK();
      iVar4 = *(int *)pQVar6;
      *(int *)pQVar6 = *(int *)pQVar6 + -1;
      UNLOCK();
      if (iVar4 == 1) {
        QArrayData::deallocate(*(QArrayData **)(pQVar3 + 0x38),2,8);
        goto LAB_009098b6;
      }
    }
    pQVar6 = *(QArrayData **)(pQVar3 + 0x20);
    iVar4 = *(int *)pQVar6;
    if (iVar4 != 0) goto LAB_0090980a;
LAB_009098c4:
    QArrayData::deallocate(pQVar6,2,8);
LAB_009098d3:
    pQVar6 = *(QArrayData **)(pQVar3 + 0x10);
    iVar4 = *(int *)pQVar6;
    if (iVar4 == 0) goto LAB_009098e1;
LAB_0090982e:
    if (iVar4 != -1) {
      LOCK();
      iVar4 = *(int *)pQVar6;
      *(int *)pQVar6 = *(int *)pQVar6 + -1;
      UNLOCK();
      if (iVar4 != 1) goto LAB_00909844;
      QArrayData::deallocate(*(QArrayData **)(pQVar3 + 0x10),2,8);
      goto LAB_009098f0;
    }
LAB_00909844:
    pQVar6 = *(QArrayData **)(pQVar3 + 8);
    iVar4 = *(int *)pQVar6;
    if (iVar4 != 0) goto LAB_00909852;
LAB_009098fe:
    QArrayData::deallocate(pQVar6,2,8);
LAB_0090990d:
    pQVar6 = *(QArrayData **)pQVar3;
    iVar4 = *(int *)pQVar6;
    if (iVar4 == 0) goto LAB_0090991b;
LAB_00909876:
    if (iVar4 != -1) {
      LOCK();
      iVar4 = *(int *)pQVar6;
      *(int *)pQVar6 = *(int *)pQVar6 + -1;
      UNLOCK();
      if (iVar4 == 1) {
        QArrayData::deallocate(*(QArrayData **)pQVar3,2,8);
      }
    }
  } while( true );
}


// ==== entry=009099c8 orig=FUN_009099c8 size=88 name=TunnelDialog_dtor_deleting ====

void TunnelDialog_dtor_deleting(QDialog *param_1)

{
  int *piVar1;
  
  *(undefined ***)param_1 = &TunnelDialog_vtable;
  *(undefined ***)(param_1 + 0x10) = &PTR_FUN_011a4e90;
  piVar1 = *(int **)(param_1 + 0xb8);
  if (*piVar1 != 0) {
    if (*piVar1 == -1) goto LAB_009099fc;
    LOCK();
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if (*piVar1 != 0) goto LAB_009099fc;
    piVar1 = *(int **)(param_1 + 0xb8);
  }
  FUN_009097b0(piVar1);
LAB_009099fc:
  QDialog::~QDialog(param_1);
  operator_delete(param_1,0xc0);
  return;
}


// ==== entry=00909a20 name=FUN_00909a20 size=92 ====

void FUN_00909a20(undefined8 *param_1)

{
  int *piVar1;
  
  param_1[-2] = &TunnelDialog_vtable;
  *param_1 = &PTR_FUN_011a4e90;
  piVar1 = (int *)param_1[0x15];
  if (*piVar1 != 0) {
    if (*piVar1 == -1) goto LAB_00909a55;
    LOCK();
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if (*piVar1 != 0) goto LAB_00909a55;
    piVar1 = (int *)param_1[0x15];
  }
  FUN_009097b0(piVar1);
LAB_00909a55:
  QDialog::~QDialog((QDialog *)(param_1 + -2));
  operator_delete((QDialog *)(param_1 + -2),0xc0);
  return;
}


// ==== entry=00909a7c orig=FUN_00909a7c size=82 name=TunnelDialog_dtor ====

void TunnelDialog_dtor(QDialog *param_1)

{
  int *piVar1;
  
  *(undefined ***)param_1 = &TunnelDialog_vtable;
  *(undefined ***)(param_1 + 0x10) = &PTR_FUN_011a4e90;
  piVar1 = *(int **)(param_1 + 0xb8);
  if (*piVar1 == 0) {
LAB_00909ac0:
    FUN_009097b0(piVar1);
    QDialog::~QDialog(param_1);
    return;
  }
  if (*piVar1 != -1) {
    LOCK();
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if (*piVar1 == 0) {
      piVar1 = *(int **)(param_1 + 0xb8);
      goto LAB_00909ac0;
    }
  }
  QDialog::~QDialog(param_1);
  return;
}


// ==== entry=00909ace name=FUN_00909ace size=84 ====

void FUN_00909ace(undefined8 *param_1)

{
  int *piVar1;
  
  param_1[-2] = &TunnelDialog_vtable;
  *param_1 = &PTR_FUN_011a4e90;
  piVar1 = (int *)param_1[0x15];
  if (*piVar1 == 0) {
LAB_00909b13:
    FUN_009097b0(piVar1);
    QDialog::~QDialog((QDialog *)(param_1 + -2));
    return;
  }
  if (*piVar1 != -1) {
    LOCK();
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if (*piVar1 == 0) {
      piVar1 = (int *)param_1[0x15];
      goto LAB_00909b13;
    }
  }
  QDialog::~QDialog((QDialog *)(param_1 + -2));
  return;
}


// ==== entry=00909b22 name=FUN_00909b22 size=1 ====

void FUN_00909b22(void)

{
  return;
}


// ==== entry=00909b24 name=FUN_00909b24 size=24 ====

undefined ** FUN_00909b24(long param_1)

{
  undefined **ppuVar1;
  
  if (*(long *)(*(long *)(param_1 + 8) + 0x28) != 0) {
    ppuVar1 = (undefined **)QObjectData::dynamicMetaObject();
    return ppuVar1;
  }
  return &PTR_PTR_011a5180;
}


// ==== entry=00909b3c orig=FUN_00909b3c size=66 name=KitPane_dtor ====

undefined8 KitPane_dtor(undefined8 param_1,char *param_2)

{
  int iVar1;
  undefined8 uVar2;
  
  if (param_2 == (char *)0x0) {
    return 0;
  }
  iVar1 = strcmp(param_2,"ExplorerPane");
  if (iVar1 == 0) {
    return param_1;
  }
  uVar2 = s_KitPane_91d3e2(param_1,param_2);
  return uVar2;
}


// ==== entry=00909b7e orig=FUN_00909b7e size=5 name=KitPane_dtor_deleting ====

ulong KitPane_dtor_deleting(undefined8 param_1,int param_2,undefined8 param_3,undefined8 *param_4)

{
  int iVar1;
  ulong uVar2;
  
  uVar2 = QWidget::qt_metacall();
  iVar1 = (int)uVar2;
  if (-1 < iVar1) {
    if (param_2 == 0) {
      if (iVar1 < 2) {
        FUN_0091d38c(param_1,0,uVar2 & 0xffffffff,param_4);
        uVar2 = uVar2 & 0xffffffff;
      }
    }
    else {
      if (param_2 != 0xc) {
        return uVar2;
      }
      if (iVar1 < 2) {
        *(undefined4 *)*param_4 = 0xffffffff;
      }
    }
    uVar2 = (ulong)((int)uVar2 - 2);
  }
  return uVar2;
}


// ==== entry=00909b84 orig=FUN_00909b84 size=29 name=ExplorerPane_dtor ====

void ExplorerPane_dtor(QWidget *param_1)

{
  *(undefined ***)param_1 = &PTR_FUN_011ab6b8;
  *(undefined **)(param_1 + 0x10) = &DAT_011ab8b0;
  QWidget::~QWidget(param_1);
  return;
}


// ==== entry=00909ba1 name=FUN_00909ba1 size=33 ====

void FUN_00909ba1(undefined8 *param_1)

{
  param_1[-2] = &PTR_FUN_011ab6b8;
  *param_1 = &DAT_011ab8b0;
  QWidget::~QWidget((QWidget *)(param_1 + -2));
  return;
}


// ==== entry=00909bc2 orig=FUN_00909bc2 size=47 name=ExplorerPane_dtor_deleting ====

void ExplorerPane_dtor_deleting(QWidget *param_1)

{
  *(undefined ***)param_1 = &PTR_FUN_011ab6b8;
  *(undefined **)(param_1 + 0x10) = &DAT_011ab8b0;
  QWidget::~QWidget(param_1);
  operator_delete(param_1,0x58);
  return;
}


// ==== entry=00909bf1 name=FUN_00909bf1 size=51 ====

void FUN_00909bf1(undefined8 *param_1)

{
  param_1[-2] = &PTR_FUN_011ab6b8;
  *param_1 = &DAT_011ab8b0;
  QWidget::~QWidget((QWidget *)(param_1 + -2));
  operator_delete((QWidget *)(param_1 + -2),0x58);
  return;
}


// ==== entry=00909c30 orig=FUN_00909c30 size=24 name=TransferPane_metaObject ====

undefined ** TransferPane_metaObject(long param_1)

{
  undefined **ppuVar1;
  
  if (*(long *)(*(long *)(param_1 + 8) + 0x28) != 0) {
    ppuVar1 = (undefined **)QObjectData::dynamicMetaObject();
    return ppuVar1;
  }
  return &PTR_PTR_011a5420;
}


// ==== entry=00909c48 orig=FUN_00909c48 size=66 name=TransferPane_qt_metacast ====

undefined8 TransferPane_qt_metacast(undefined8 param_1,char *param_2)

{
  int iVar1;
  undefined8 uVar2;
  
  if (param_2 == (char *)0x0) {
    return 0;
  }
  iVar1 = strcmp(param_2,"TransferPane");
  if (iVar1 == 0) {
    return param_1;
  }
  uVar2 = s_KitPane_91d3e2(param_1,param_2);
  return uVar2;
}


// ==== entry=00909c8a name=FUN_00909c8a size=90 ====

void FUN_00909c8a(undefined8 param_1,int param_2,undefined4 param_3,long *param_4)

{
  undefined1 uVar1;
  
  if (param_2 != 0) {
switchD_00909ca7_default:
    return;
  }
  switch(param_3) {
  case 0:
    uVar1 = FUN_0073452e();
    if ((undefined1 *)*param_4 != (undefined1 *)0x0) {
      *(undefined1 *)*param_4 = uVar1;
    }
    break;
  case 1:
    uVar1 = FUN_007345a4();
    if ((undefined1 *)*param_4 != (undefined1 *)0x0) {
      *(undefined1 *)*param_4 = uVar1;
    }
    break;
  case 2:
    FUN_00734656();
    return;
  case 3:
    FUN_007346c4();
    return;
  case 4:
    FUN_00734764();
    return;
  case 5:
    FUN_00734804();
    return;
  default:
    goto switchD_00909ca7_default;
  }
  return;
}


// ==== entry=00909ce4 orig=FUN_00909ce4 size=93 name=TransferPane_qt_metacall ====

ulong TransferPane_qt_metacall
                (undefined8 param_1,int param_2,undefined8 param_3,undefined8 *param_4)

{
  int iVar1;
  ulong uVar2;
  
  uVar2 = FUN_0091d424();
  iVar1 = (int)uVar2;
  if (-1 < iVar1) {
    if (param_2 == 0) {
      if (iVar1 < 6) {
        FUN_00909c8a(param_1,0,uVar2 & 0xffffffff,param_4);
        uVar2 = uVar2 & 0xffffffff;
      }
    }
    else {
      if (param_2 != 0xc) {
        return uVar2;
      }
      if (iVar1 < 6) {
        *(undefined4 *)*param_4 = 0xffffffff;
      }
    }
    uVar2 = (ulong)((int)uVar2 - 6);
  }
  return uVar2;
}


// ==== entry=00909d42 orig=FUN_00909d42 size=29 name=TransferPane_dtor ====

void TransferPane_dtor(QWidget *param_1)

{
  *(undefined ***)param_1 = &PTR_FUN_011ab6b8;
  *(undefined **)(param_1 + 0x10) = &DAT_011ab8b0;
  QWidget::~QWidget(param_1);
  return;
}


// ==== entry=00909d5f name=FUN_00909d5f size=33 ====

void FUN_00909d5f(undefined8 *param_1)

{
  param_1[-2] = &PTR_FUN_011ab6b8;
  *param_1 = &DAT_011ab8b0;
  QWidget::~QWidget((QWidget *)(param_1 + -2));
  return;
}


// ==== entry=00909d80 orig=FUN_00909d80 size=47 name=TransferPane_dtor_deleting ====

void TransferPane_dtor_deleting(QWidget *param_1)

{
  *(undefined ***)param_1 = &PTR_FUN_011ab6b8;
  *(undefined **)(param_1 + 0x10) = &DAT_011ab8b0;
  QWidget::~QWidget(param_1);
  operator_delete(param_1,0x60);
  return;
}


// ==== entry=00909daf name=FUN_00909daf size=51 ====

void FUN_00909daf(undefined8 *param_1)

{
  param_1[-2] = &PTR_FUN_011ab6b8;
  *param_1 = &DAT_011ab8b0;
  QWidget::~QWidget((QWidget *)(param_1 + -2));
  operator_delete((QWidget *)(param_1 + -2),0x60);
  return;
}


// ==== entry=00909df0 orig=FUN_00909df0 size=24 name=OutputPane_metaObject ====

undefined ** OutputPane_metaObject(long param_1)

{
  undefined **ppuVar1;
  
  if (*(long *)(*(long *)(param_1 + 8) + 0x28) != 0) {
    ppuVar1 = (undefined **)QObjectData::dynamicMetaObject();
    return ppuVar1;
  }
  return &PTR_PTR_011a56c0;
}


// ==== entry=00909e08 name=FUN_00909e08 size=414 ====

void FUN_00909e08(undefined8 param_1,int param_2,uint param_3,long *param_4)

{
  QArrayData *pQVar1;
  undefined8 *puVar2;
  undefined4 uVar3;
  QArrayData *local_38;
  undefined4 local_30;
  QArrayData *local_28;
  undefined4 local_20;
  
  if ((param_2 != 0) || (8 < param_3)) {
    return;
  }
  switch(param_3) {
  case 0:
    FUN_00749422(param_1,param_4[1]);
    break;
  case 1:
    local_28 = (QArrayData *)0x0;
    local_20 = 0x80000000;
                    /* try { // try from 00909eed to 00909ef1 has its CatchHandler @ 00909fa6 */
    FUN_00749422(param_1,(QVariant *)&local_28);
    QVariant::~QVariant((QVariant *)&local_28);
    break;
  case 2:
    FUN_00749878(&local_28,param_1);
    puVar2 = (undefined8 *)*param_4;
    if (puVar2 != (undefined8 *)0x0) {
      pQVar1 = (QArrayData *)*puVar2;
      *puVar2 = local_28;
      local_28 = pQVar1;
    }
    if (*(int *)local_28 != 0) {
      if (*(int *)local_28 == -1) {
        return;
      }
      LOCK();
      *(int *)local_28 = *(int *)local_28 + -1;
      UNLOCK();
      if (*(int *)local_28 != 0) {
        return;
      }
    }
    QArrayData::deallocate(local_28,2,8);
    break;
  case 3:
    FUN_0074a1ea(param_1,*(undefined4 *)param_4[1]);
    break;
  case 4:
    FUN_0074a1ea(param_1,0xffffffff);
    break;
  case 5:
    uVar3 = FUN_0074a728(param_1,*(undefined1 *)param_4[1]);
    if ((undefined4 *)*param_4 != (undefined4 *)0x0) {
      *(undefined4 *)*param_4 = uVar3;
    }
    break;
  case 6:
    FUN_0074a8f6(param_1,param_4[1]);
    break;
  case 7:
    FUN_00749b3e(&local_38,param_1);
    pQVar1 = local_38;
    puVar2 = (undefined8 *)*param_4;
    if (puVar2 != (undefined8 *)0x0) {
      local_38 = (QArrayData *)&QListData::shared_null;
      local_28 = (QArrayData *)*puVar2;
      *puVar2 = pQVar1;
      FUN_00525060(&local_28);
    }
    FUN_00525060(&local_38);
    break;
  case 8:
    FUN_0074a946(&local_38,param_1,param_4[1]);
    puVar2 = (undefined8 *)*param_4;
    if (puVar2 != (undefined8 *)0x0) {
      local_28 = (QArrayData *)*puVar2;
      local_20 = *(undefined4 *)(puVar2 + 1);
      *puVar2 = local_38;
      *(undefined4 *)(puVar2 + 1) = local_30;
      local_38 = local_28;
      local_30 = local_20;
    }
    QVariant::~QVariant((QVariant *)&local_38);
  }
  return;
}


// ==== entry=00909fae orig=FUN_00909fae size=66 name=OutputPane_qt_metacast ====

undefined8 OutputPane_qt_metacast(undefined8 param_1,char *param_2)

{
  int iVar1;
  undefined8 uVar2;
  
  if (param_2 == (char *)0x0) {
    return 0;
  }
  iVar1 = strcmp(param_2,"OutputPane");
  if (iVar1 == 0) {
    return param_1;
  }
  uVar2 = s_KitPane_91d3e2(param_1,param_2);
  return uVar2;
}


// ==== entry=00909ff0 orig=FUN_00909ff0 size=93 name=OutputPane_qt_metacall ====

ulong OutputPane_qt_metacall(undefined8 param_1,int param_2,undefined8 param_3,undefined8 *param_4)

{
  int iVar1;
  ulong uVar2;
  
  uVar2 = FUN_0091d424();
  iVar1 = (int)uVar2;
  if (-1 < iVar1) {
    if (param_2 == 0) {
      if (iVar1 < 9) {
        FUN_00909e08(param_1,0,uVar2 & 0xffffffff,param_4);
        uVar2 = uVar2 & 0xffffffff;
      }
    }
    else {
      if (param_2 != 0xc) {
        return uVar2;
      }
      if (iVar1 < 9) {
        *(undefined4 *)*param_4 = 0xffffffff;
      }
    }
    uVar2 = (ulong)((int)uVar2 - 9);
  }
  return uVar2;
}


// ==== entry=0090a050 orig=FUN_0090a050 size=24 name=SessionPane_metaObject ====

undefined ** SessionPane_metaObject(long param_1)

{
  undefined **ppuVar1;
  
  if (*(long *)(*(long *)(param_1 + 8) + 0x28) != 0) {
    ppuVar1 = (undefined **)QObjectData::dynamicMetaObject();
    return ppuVar1;
  }
  return &PTR_PTR_011a5960;
}


// ==== entry=0090a068 orig=FUN_0090a068 size=66 name=SessionPane_qt_metacast ====

undefined8 SessionPane_qt_metacast(undefined8 param_1,char *param_2)

{
  int iVar1;
  undefined8 uVar2;
  
  if (param_2 == (char *)0x0) {
    return 0;
  }
  iVar1 = strcmp(param_2,"SessionPane");
  if (iVar1 == 0) {
    return param_1;
  }
  uVar2 = s_KitPane_91d3e2(param_1,param_2);
  return uVar2;
}


// ==== entry=0090a0aa name=FUN_0090a0aa size=413 ====

void FUN_0090a0aa(undefined8 param_1,int param_2,undefined4 param_3,long *param_4)

{
  long lVar1;
  undefined1 uVar2;
  QArrayData *local_28;
  QArrayData *local_20;
  
  if (param_2 != 0) {
switchD_0090a0cb_default:
    return;
  }
  switch(param_3) {
  case 0:
    FUN_00740472();
    break;
  case 1:
    FUN_0073e756();
    break;
  case 2:
    uVar2 = FUN_0073cdaa();
    if ((undefined1 *)*param_4 != (undefined1 *)0x0) {
      *(undefined1 *)*param_4 = uVar2;
    }
    break;
  case 3:
    FUN_007400aa(param_1,param_4[1]);
    break;
  case 4:
    FUN_0073eb92();
    break;
  case 5:
    FUN_0073cdc4();
    break;
  case 6:
    FUN_007415fc();
    break;
  case 7:
    lVar1 = param_4[2];
    local_20 = *(QArrayData **)param_4[1];
    if ((*(int *)local_20 != 0) && (*(int *)local_20 != -1)) {
      LOCK();
      *(int *)local_20 = *(int *)local_20 + 1;
      UNLOCK();
    }
                    /* try { // try from 0090a1c9 to 0090a1cd has its CatchHandler @ 0090a257 */
    FUN_0073d836(param_1,&local_20,lVar1);
    goto LAB_0090a128;
  case 8:
    local_20 = (QArrayData *)&QArrayData::shared_null;
    local_28 = *(QArrayData **)param_4[1];
    if ((*(int *)local_28 != 0) && (*(int *)local_28 != -1)) {
      LOCK();
      *(int *)local_28 = *(int *)local_28 + 1;
      UNLOCK();
    }
                    /* try { // try from 0090a105 to 0090a109 has its CatchHandler @ 0090a24f */
    FUN_0073d836(param_1,&local_28,&local_20);
    goto LAB_0090a10a;
  case 9:
    local_20 = (QArrayData *)&QArrayData::shared_null;
    local_28 = (QArrayData *)&QArrayData::shared_null;
                    /* try { // try from 0090a170 to 0090a174 has its CatchHandler @ 0090a247 */
    FUN_0073d836(param_1,&local_28,&local_20);
LAB_0090a10a:
    if (*(int *)local_28 == 0) {
LAB_0090a233:
      QArrayData::deallocate(local_28,2,8);
    }
    else if (*(int *)local_28 != -1) {
      LOCK();
      *(int *)local_28 = *(int *)local_28 + -1;
      UNLOCK();
      if (*(int *)local_28 == 0) goto LAB_0090a233;
    }
LAB_0090a128:
    if (*(int *)local_20 != 0) {
      if (*(int *)local_20 == -1) {
        return;
      }
      LOCK();
      *(int *)local_20 = *(int *)local_20 + -1;
      UNLOCK();
      if (*(int *)local_20 != 0) {
        return;
      }
    }
    QArrayData::deallocate(local_20,2,8);
    break;
  default:
    goto switchD_0090a0cb_default;
  }
  return;
}


// ==== entry=0090a260 orig=FUN_0090a260 size=93 name=SessionPane_qt_metacall ====

ulong SessionPane_qt_metacall(undefined8 param_1,int param_2,undefined8 param_3,undefined8 *param_4)

{
  int iVar1;
  ulong uVar2;
  
  uVar2 = FUN_0091d424();
  iVar1 = (int)uVar2;
  if (-1 < iVar1) {
    if (param_2 == 0) {
      if (iVar1 < 10) {
        FUN_0090a0aa(param_1,0,uVar2 & 0xffffffff,param_4);
        uVar2 = uVar2 & 0xffffffff;
      }
    }
    else {
      if (param_2 != 0xc) {
        return uVar2;
      }
      if (iVar1 < 10) {
        *(undefined4 *)*param_4 = 0xffffffff;
      }
    }
    uVar2 = (ulong)((int)uVar2 - 10);
  }
  return uVar2;
}


// ==== entry=0090a2be orig=FUN_0090a2be size=29 name=SessionPane_dtor ====

void SessionPane_dtor(QWidget *param_1)

{
  *(undefined ***)param_1 = &PTR_FUN_011ab6b8;
  *(undefined **)(param_1 + 0x10) = &DAT_011ab8b0;
  QWidget::~QWidget(param_1);
  return;
}


// ==== entry=0090a2db name=FUN_0090a2db size=33 ====

void FUN_0090a2db(undefined8 *param_1)

{
  param_1[-2] = &PTR_FUN_011ab6b8;
  *param_1 = &DAT_011ab8b0;
  QWidget::~QWidget((QWidget *)(param_1 + -2));
  return;
}


// ==== entry=0090a2fc orig=FUN_0090a2fc size=47 name=SessionPane_dtor_deleting ====

void SessionPane_dtor_deleting(QWidget *param_1)

{
  *(undefined ***)param_1 = &PTR_FUN_011ab6b8;
  *(undefined **)(param_1 + 0x10) = &DAT_011ab8b0;
  QWidget::~QWidget(param_1);
  operator_delete(param_1,0x68);
  return;
}


// ==== entry=0090a32b name=FUN_0090a32b size=51 ====

void FUN_0090a32b(undefined8 *param_1)

{
  param_1[-2] = &PTR_FUN_011ab6b8;
  *param_1 = &DAT_011ab8b0;
  QWidget::~QWidget((QWidget *)(param_1 + -2));
  operator_delete((QWidget *)(param_1 + -2),0x68);
  return;
}


// ==== entry=0090a360 orig=FUN_0090a360 size=24 name=SenderPane_metaObject ====

undefined ** SenderPane_metaObject(long param_1)

{
  undefined **ppuVar1;
  
  if (*(long *)(*(long *)(param_1 + 8) + 0x28) != 0) {
    ppuVar1 = (undefined **)QObjectData::dynamicMetaObject();
    return ppuVar1;
  }
  return &PTR_PTR_011a5c00;
}


// ==== entry=0090a378 name=FUN_0090a378 size=953 ====

void FUN_0090a378(undefined8 param_1,int param_2,undefined4 param_3,long *param_4)

{
  QArrayData *pQVar1;
  undefined8 *puVar2;
  undefined1 uVar3;
  undefined4 uVar4;
  long lVar5;
  QArrayData *local_30;
  QArrayData *local_28;
  undefined4 local_20;
  
  if (param_2 != 0) {
switchD_0090a39c_default:
    return;
  }
  switch(param_3) {
  case 0:
    lVar5 = param_4[1];
    uVar4 = *(undefined4 *)param_4[2];
    goto LAB_0090a405;
  case 1:
    lVar5 = param_4[1];
    uVar4 = 1;
LAB_0090a405:
    FUN_00736f9e(&local_28,param_1,lVar5,uVar4);
    puVar2 = (undefined8 *)*param_4;
    if (puVar2 != (undefined8 *)0x0) {
      pQVar1 = (QArrayData *)*puVar2;
      *puVar2 = local_28;
      local_28 = pQVar1;
    }
    if (*(int *)local_28 != 0) {
      if (*(int *)local_28 == -1) {
        return;
      }
      LOCK();
      *(int *)local_28 = *(int *)local_28 + -1;
      UNLOCK();
      if (*(int *)local_28 != 0) {
        return;
      }
    }
    QArrayData::deallocate(local_28,2,8);
    break;
  case 2:
    local_28 = (QArrayData *)&QArrayData::shared_null;
                    /* try { // try from 0090a492 to 0090a496 has its CatchHandler @ 0090a749 */
    FUN_00736f9e(&local_30,param_1,&local_28,1);
    if (*(int *)local_28 == 0) {
LAB_0090a715:
      QArrayData::deallocate(local_28,2,8);
    }
    else if (*(int *)local_28 != -1) {
      LOCK();
      *(int *)local_28 = *(int *)local_28 + -1;
      UNLOCK();
      if (*(int *)local_28 == 0) goto LAB_0090a715;
    }
    puVar2 = (undefined8 *)*param_4;
    if (puVar2 != (undefined8 *)0x0) {
      pQVar1 = (QArrayData *)*puVar2;
      *puVar2 = local_30;
      local_30 = pQVar1;
    }
    if (*(int *)local_30 != 0) {
      if (*(int *)local_30 == -1) {
        return;
      }
      LOCK();
      *(int *)local_30 = *(int *)local_30 + -1;
      UNLOCK();
      if (*(int *)local_30 != 0) {
        return;
      }
    }
    QArrayData::deallocate(local_30,2,8);
    break;
  case 3:
    FUN_007357ba(param_1,param_4[1]);
    break;
  case 4:
    local_28 = (QArrayData *)0x0;
    local_20 = 0x80000000;
                    /* try { // try from 0090a52e to 0090a532 has its CatchHandler @ 0090a761 */
    FUN_007357ba(param_1,(QVariant *)&local_28);
    QVariant::~QVariant((QVariant *)&local_28);
    break;
  case 5:
    uVar3 = FUN_007359e8(param_1,param_4[1]);
    if ((undefined1 *)*param_4 != (undefined1 *)0x0) {
      *(undefined1 *)*param_4 = uVar3;
    }
    break;
  case 6:
    local_28 = (QArrayData *)&QArrayData::shared_null;
                    /* try { // try from 0090a570 to 0090a574 has its CatchHandler @ 0090a731 */
    uVar3 = FUN_007359e8(param_1,&local_28);
    if (*(int *)local_28 == 0) {
LAB_0090a6fc:
      QArrayData::deallocate(local_28,2,8);
    }
    else if (*(int *)local_28 != -1) {
      LOCK();
      *(int *)local_28 = *(int *)local_28 + -1;
      UNLOCK();
      if (*(int *)local_28 == 0) goto LAB_0090a6fc;
    }
    if ((undefined1 *)*param_4 != (undefined1 *)0x0) {
      *(undefined1 *)*param_4 = uVar3;
    }
    break;
  case 7:
    FUN_0073720c(param_1,param_4[1]);
    break;
  case 8:
    local_28 = (QArrayData *)&QArrayData::shared_null;
                    /* try { // try from 0090a5cb to 0090a5cf has its CatchHandler @ 0090a759 */
    FUN_0073720c(param_1,&local_28);
    goto LAB_0090a3ca;
  case 9:
    FUN_0073604a(&local_30,param_1,param_4[1]);
    pQVar1 = local_30;
    puVar2 = (undefined8 *)*param_4;
    if (puVar2 != (undefined8 *)0x0) {
      local_30 = (QArrayData *)&QMapDataBase::shared_null;
      local_28 = (QArrayData *)*puVar2;
      *puVar2 = pQVar1;
      FUN_00528c1c(&local_28);
    }
    goto LAB_0090a617;
  case 10:
    local_28 = (QArrayData *)&QArrayData::shared_null;
                    /* try { // try from 0090a643 to 0090a647 has its CatchHandler @ 0090a751 */
    FUN_0073604a(&local_30,param_1,&local_28);
    if (*(int *)local_28 == 0) {
LAB_0090a6e3:
      QArrayData::deallocate(local_28,2,8);
    }
    else if (*(int *)local_28 != -1) {
      LOCK();
      *(int *)local_28 = *(int *)local_28 + -1;
      UNLOCK();
      if (*(int *)local_28 == 0) goto LAB_0090a6e3;
    }
    pQVar1 = local_30;
    puVar2 = (undefined8 *)*param_4;
    if (puVar2 != (undefined8 *)0x0) {
      local_30 = (QArrayData *)&QMapDataBase::shared_null;
      local_28 = (QArrayData *)*puVar2;
      *puVar2 = pQVar1;
      FUN_00528c1c(&local_28);
    }
LAB_0090a617:
    FUN_00528c1c(&local_30);
    break;
  case 0xb:
    uVar4 = FUN_00735788();
    if ((undefined4 *)*param_4 != (undefined4 *)0x0) {
      *(undefined4 *)*param_4 = uVar4;
    }
    break;
  case 0xc:
    s_TabTargetTitle_738346(param_1,param_4[1]);
    break;
  case 0xd:
    local_28 = (QArrayData *)&QArrayData::shared_null;
                    /* try { // try from 0090a6ca to 0090a6ce has its CatchHandler @ 0090a741 */
    s_TabTargetTitle_738346(param_1,&local_28);
    goto LAB_0090a3ca;
  case 0xe:
    FUN_007371c0(param_1,param_4[1]);
    break;
  case 0xf:
    local_28 = (QArrayData *)&QArrayData::shared_null;
                    /* try { // try from 0090a3c5 to 0090a3c9 has its CatchHandler @ 0090a739 */
    FUN_007371c0(param_1,&local_28);
LAB_0090a3ca:
    if (*(int *)local_28 != 0) {
      if (*(int *)local_28 == -1) {
        return;
      }
      LOCK();
      *(int *)local_28 = *(int *)local_28 + -1;
      UNLOCK();
      if (*(int *)local_28 != 0) {
        return;
      }
    }
    QArrayData::deallocate(local_28,2,8);
    break;
  default:
    goto switchD_0090a39c_default;
  }
  return;
}


// ==== entry=0090a76a orig=FUN_0090a76a size=66 name=SenderPane_qt_metacast ====

undefined8 SenderPane_qt_metacast(undefined8 param_1,char *param_2)

{
  int iVar1;
  undefined8 uVar2;
  
  if (param_2 == (char *)0x0) {
    return 0;
  }
  iVar1 = strcmp(param_2,"SenderPane");
  if (iVar1 == 0) {
    return param_1;
  }
  uVar2 = s_KitPane_91d3e2(param_1,param_2);
  return uVar2;
}


// ==== entry=0090a7ac orig=FUN_0090a7ac size=97 name=SenderPane_qt_metacall ====

ulong SenderPane_qt_metacall(undefined8 param_1,int param_2,undefined8 param_3,undefined8 *param_4)

{
  int iVar1;
  ulong uVar2;
  
  uVar2 = FUN_0091d424();
  iVar1 = (int)uVar2;
  if (-1 < iVar1) {
    if (param_2 == 0) {
      if (iVar1 < 0x10) {
        FUN_0090a378(param_1,0,uVar2 & 0xffffffff,param_4);
        uVar2 = uVar2 & 0xffffffff;
      }
    }
    else {
      if (param_2 != 0xc) {
        return uVar2;
      }
      if (iVar1 < 0x10) {
        *(undefined4 *)*param_4 = 0xffffffff;
      }
    }
    uVar2 = (ulong)((int)uVar2 - 0x10);
  }
  return uVar2;
}


// ==== entry=0090a810 orig=FUN_0090a810 size=24 name=FilerPane_metaObject ====

undefined ** FilerPane_metaObject(long param_1)

{
  undefined **ppuVar1;
  
  if (*(long *)(*(long *)(param_1 + 8) + 0x28) != 0) {
    ppuVar1 = (undefined **)QObjectData::dynamicMetaObject();
    return ppuVar1;
  }
  return &PTR_PTR_011a5ea0;
}


// ==== entry=0090a828 orig=FUN_0090a828 size=66 name=FilerPane_qt_metacast ====

undefined8 FilerPane_qt_metacast(undefined8 param_1,char *param_2)

{
  int iVar1;
  undefined8 uVar2;
  
  if (param_2 == (char *)0x0) {
    return 0;
  }
  iVar1 = strcmp(param_2,"FilerPane");
  if (iVar1 == 0) {
    return param_1;
  }
  uVar2 = s_KitPane_91d3e2(param_1,param_2);
  return uVar2;
}


// ==== entry=0090a86a name=FUN_0090a86a size=823 ====

void FUN_0090a86a(undefined8 param_1,uint param_2,long *param_3)

{
  undefined8 *puVar1;
  QArrayData *pQVar2;
  undefined8 *puVar3;
  undefined1 uVar4;
  undefined8 *local_28;
  QArrayData *local_20 [2];
  
  if (0x22 < param_2) {
    return;
  }
  switch(param_2) {
  case 0:
    uVar4 = FUN_00730cfc();
    if ((undefined1 *)*param_3 != (undefined1 *)0x0) {
      *(undefined1 *)*param_3 = uVar4;
    }
    break;
  case 1:
    uVar4 = FUN_00730d0e();
    if ((undefined1 *)*param_3 != (undefined1 *)0x0) {
      *(undefined1 *)*param_3 = uVar4;
    }
    break;
  case 2:
    FUN_00730d20(param_1,param_3[1],*(undefined1 *)param_3[2]);
    break;
  case 3:
    FUN_00730d20(param_1,param_3[1],1);
    break;
  case 4:
    FUN_00730d32();
    break;
  case 5:
    FUN_007324ca(local_20,param_1);
    puVar1 = (undefined8 *)*param_3;
    goto joined_r0x0090a8bf;
  case 6:
    FUN_00732d0e();
    break;
  case 7:
    FUN_007325c4(local_20,param_1);
    puVar1 = (undefined8 *)*param_3;
    goto joined_r0x0090a8bf;
  case 8:
    FUN_00732dfa();
    break;
  case 9:
    FUN_00731da6(local_20,param_1);
    puVar1 = (undefined8 *)*param_3;
    goto joined_r0x0090a8bf;
  case 10:
    FUN_00732ae6();
    break;
  case 0xb:
    FUN_007326be(local_20,param_1);
    puVar1 = (undefined8 *)*param_3;
    goto joined_r0x0090a8bf;
  case 0xc:
    FUN_00732b4a();
    break;
  case 0xd:
    FUN_0073138e();
    break;
  case 0xe:
    FUN_00731186();
    break;
  case 0xf:
    FUN_00731196();
    break;
  case 0x10:
    FUN_007311a6();
    break;
  case 0x11:
    uVar4 = FUN_007311ca();
    if ((undefined1 *)*param_3 != (undefined1 *)0x0) {
      *(undefined1 *)*param_3 = uVar4;
    }
    break;
  case 0x12:
    FUN_00731442();
    break;
  case 0x13:
    FUN_00731452();
    break;
  case 0x14:
    FUN_00731462();
    break;
  case 0x15:
    FUN_00731472();
    break;
  case 0x16:
    FUN_00731482();
    break;
  case 0x17:
    FUN_00731492();
    break;
  case 0x18:
    FUN_007314da();
    break;
  case 0x19:
    FUN_007314ea();
    break;
  case 0x1a:
    FUN_007314fa(&local_28,param_1);
    puVar3 = local_28;
    puVar1 = (undefined8 *)*param_3;
    if (puVar1 != (undefined8 *)0x0) {
      local_28 = &QListData::shared_null;
      local_20[0] = (QArrayData *)*puVar1;
      *puVar1 = puVar3;
      FUN_00525060(local_20);
    }
    FUN_00525060(&local_28);
    break;
  case 0x1b:
    FUN_00731520();
    break;
  case 0x1c:
    FUN_00731530();
    break;
  case 0x1d:
    FUN_00731540();
    break;
  case 0x1e:
    FUN_00731634(local_20,param_1);
    puVar1 = (undefined8 *)*param_3;
    goto joined_r0x0090a8bf;
  case 0x1f:
    FUN_00731550(local_20,param_1);
    puVar1 = (undefined8 *)*param_3;
joined_r0x0090a8bf:
    if (puVar1 != (undefined8 *)0x0) {
      pQVar2 = (QArrayData *)*puVar1;
      *puVar1 = local_20[0];
      local_20[0] = pQVar2;
    }
    if (*(int *)local_20[0] != 0) {
      if (*(int *)local_20[0] == -1) {
        return;
      }
      LOCK();
      *(int *)local_20[0] = *(int *)local_20[0] + -1;
      UNLOCK();
      if (*(int *)local_20[0] != 0) {
        return;
      }
    }
    QArrayData::deallocate(local_20[0],2,8);
    break;
  case 0x20:
    FUN_0073172c(param_1,*(undefined1 *)param_3[1]);
    break;
  case 0x21:
    FUN_007309ee();
    break;
  case 0x22:
    FUN_00731cc0();
  }
  return;
}


// ==== entry=0090aba2 name=FUN_0090aba2 size=79 ====

void FUN_0090aba2(undefined8 param_1,int param_2,int param_3,undefined8 *param_4)

{
  undefined1 *puVar1;
  undefined1 uVar2;
  
  if (param_2 == 0) {
    FUN_0090a86a(param_1,param_3,param_4);
    return;
  }
  if (param_2 != 1) {
    if ((param_2 == 2) && (param_3 == 0)) {
      FUN_0073113a(param_1,*(undefined1 *)*param_4);
      return;
    }
    return;
  }
  puVar1 = (undefined1 *)*param_4;
  if (param_3 != 0) {
    if (param_3 == 1) {
      uVar2 = FUN_007311dc();
      *puVar1 = uVar2;
    }
    return;
  }
  uVar2 = FUN_00731758();
  *puVar1 = uVar2;
  return;
}


// ==== entry=0090abf2 orig=FUN_0090abf2 size=174 name=FilerPane_qt_metacall ====

ulong FilerPane_qt_metacall(undefined8 param_1,int param_2,undefined8 param_3,undefined8 *param_4)

{
  int iVar1;
  ulong uVar2;
  
  uVar2 = FUN_0091d424();
  iVar1 = (int)uVar2;
  if (-1 < iVar1) {
    if (param_2 == 0) {
      if (iVar1 < 0x23) {
        FUN_0090a86a(param_1,uVar2 & 0xffffffff,param_4);
        uVar2 = uVar2 & 0xffffffff;
      }
    }
    else {
      if (param_2 != 0xc) {
        if ((param_2 - 1U < 3) || (param_2 == 0xb)) {
          FUN_0090aba2(param_1,param_2,uVar2 & 0xffffffff,param_4);
          return (ulong)(iVar1 - 2);
        }
        if ((((param_2 != 4) && (param_2 != 5)) && (param_2 != 6)) &&
           ((param_2 != 7 && (param_2 != 8)))) {
          return uVar2;
        }
        return (ulong)(iVar1 - 2);
      }
      if (iVar1 < 0x23) {
        *(undefined4 *)*param_4 = 0xffffffff;
      }
    }
    uVar2 = (ulong)((int)uVar2 - 0x23);
  }
  return uVar2;
}


// ==== entry=0090aca0 orig=FUN_0090aca0 size=103 name=FilerPane_dtor_deleting ====

void FilerPane_dtor_deleting(QWidget *param_1)

{
  int *piVar1;
  
  *(undefined ***)param_1 = &FilerPane_vtable;
  *(undefined ***)(param_1 + 0x10) = &PTR_FUN_011a5e50;
  piVar1 = *(int **)(param_1 + 0x48);
  if (piVar1 != (int *)0x0) {
    LOCK();
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if ((*piVar1 == 0) && (*(void **)(param_1 + 0x48) != (void *)0x0)) {
      operator_delete(*(void **)(param_1 + 0x48));
    }
  }
  *(undefined ***)param_1 = &PTR_FUN_011ab6b8;
  *(undefined **)(param_1 + 0x10) = &DAT_011ab8b0;
  QWidget::~QWidget(param_1);
  operator_delete(param_1,0x78);
  return;
}


// ==== entry=0090ad07 name=FUN_0090ad07 size=117 ====

void FUN_0090ad07(undefined8 *param_1)

{
  int *piVar1;
  
  param_1[-2] = &FilerPane_vtable;
  *param_1 = &PTR_FUN_011a5e50;
  piVar1 = (int *)param_1[7];
  if (piVar1 != (int *)0x0) {
    LOCK();
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if ((*piVar1 == 0) && ((void *)param_1[7] != (void *)0x0)) {
      operator_delete((void *)param_1[7]);
    }
  }
  param_1[-2] = &PTR_FUN_011ab6b8;
  *param_1 = &DAT_011ab8b0;
  QWidget::~QWidget((QWidget *)(param_1 + -2));
  operator_delete((QWidget *)(param_1 + -2),0x78);
  return;
}


// ==== entry=0090ad7c name=FUN_0090ad7c size=91 ====

void FUN_0090ad7c(undefined8 *param_1)

{
  int *piVar1;
  
  param_1[-2] = &FilerPane_vtable;
  *param_1 = &PTR_FUN_011a5e50;
  piVar1 = (int *)param_1[7];
  if (piVar1 != (int *)0x0) {
    LOCK();
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if ((*piVar1 == 0) && ((void *)param_1[7] != (void *)0x0)) {
      operator_delete((void *)param_1[7]);
    }
  }
  param_1[-2] = &PTR_FUN_011ab6b8;
  *param_1 = &DAT_011ab8b0;
  QWidget::~QWidget((QWidget *)(param_1 + -2));
  return;
}


// ==== entry=0090add8 orig=FUN_0090add8 size=90 name=FilerPane_dtor ====

void FilerPane_dtor(QWidget *param_1)

{
  int *piVar1;
  
  *(undefined ***)param_1 = &FilerPane_vtable;
  *(undefined ***)(param_1 + 0x10) = &PTR_FUN_011a5e50;
  piVar1 = *(int **)(param_1 + 0x48);
  if (piVar1 != (int *)0x0) {
    LOCK();
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if ((*piVar1 == 0) && (*(void **)(param_1 + 0x48) != (void *)0x0)) {
      operator_delete(*(void **)(param_1 + 0x48));
    }
  }
  *(undefined ***)param_1 = &PTR_FUN_011ab6b8;
  *(undefined **)(param_1 + 0x10) = &DAT_011ab8b0;
  QWidget::~QWidget(param_1);
  return;
}


// ==== entry=0090ae40 orig=FUN_0090ae40 size=24 name=OutlinePane_metaObject ====

undefined ** OutlinePane_metaObject(long param_1)

{
  undefined **ppuVar1;
  
  if (*(long *)(*(long *)(param_1 + 8) + 0x28) != 0) {
    ppuVar1 = (undefined **)QObjectData::dynamicMetaObject();
    return ppuVar1;
  }
  return &PTR_PTR_011a6140;
}


// ==== entry=0090ae58 orig=FUN_0090ae58 size=66 name=OutlinePane_qt_metacast ====

undefined8 OutlinePane_qt_metacast(undefined8 param_1,char *param_2)

{
  int iVar1;
  undefined8 uVar2;
  
  if (param_2 == (char *)0x0) {
    return 0;
  }
  iVar1 = strcmp(param_2,"OutlinePane");
  if (iVar1 == 0) {
    return param_1;
  }
  uVar2 = s_KitPane_91d3e2(param_1,param_2);
  return uVar2;
}


// ==== entry=0090ae9a name=FUN_0090ae9a size=279 ====

void FUN_0090ae9a(undefined8 param_1,undefined4 param_2,long *param_3)

{
  QArrayData *pQVar1;
  undefined8 *puVar2;
  undefined1 uVar3;
  QArrayData *local_10;
  
  switch(param_2) {
  case 0:
    FUN_00747d9e();
    break;
  case 1:
    FUN_0074644a();
    break;
  case 2:
    FUN_00746b00(&local_10,param_1);
    puVar2 = (undefined8 *)*param_3;
    goto joined_r0x0090af7a;
  case 3:
    FUN_00746ec6(&local_10,param_1);
    puVar2 = (undefined8 *)*param_3;
    goto joined_r0x0090af7a;
  case 4:
    FUN_00746b46(&local_10,param_1);
    puVar2 = (undefined8 *)*param_3;
joined_r0x0090af7a:
    if (puVar2 != (undefined8 *)0x0) {
      pQVar1 = (QArrayData *)*puVar2;
      *puVar2 = local_10;
      local_10 = pQVar1;
    }
    if (*(int *)local_10 == 0) {
LAB_0090af2b:
      QArrayData::deallocate(local_10,2,8);
      return;
    }
    if (*(int *)local_10 != -1) {
      LOCK();
      *(int *)local_10 = *(int *)local_10 + -1;
      UNLOCK();
      if (*(int *)local_10 == 0) goto LAB_0090af2b;
    }
    break;
  case 5:
    FUN_00746bfe();
    break;
  case 6:
    s_SenderPane_746ce4();
    break;
  case 7:
    FUN_00748510();
    break;
  case 8:
    uVar3 = FUN_00745ee2();
    if ((undefined1 *)*param_3 != (undefined1 *)0x0) {
      *(undefined1 *)*param_3 = uVar3;
    }
    break;
  case 9:
    FUN_007478c6();
    break;
  default:
    return;
  }
  return;
}


// ==== entry=0090afb2 name=FUN_0090afb2 size=17 ====

void FUN_0090afb2(undefined8 param_1,int param_2,undefined4 param_3,undefined8 param_4)

{
  if (param_2 == 0) {
    FUN_0090ae9a(param_1,param_3,param_4);
    return;
  }
  return;
}


// ==== entry=0090afc4 orig=FUN_0090afc4 size=91 name=OutlinePane_qt_metacall ====

ulong OutlinePane_qt_metacall(undefined8 param_1,int param_2,undefined8 param_3,undefined8 *param_4)

{
  int iVar1;
  ulong uVar2;
  
  uVar2 = FUN_0091d424();
  iVar1 = (int)uVar2;
  if (-1 < iVar1) {
    if (param_2 == 0) {
      if (iVar1 < 10) {
        FUN_0090ae9a(param_1,uVar2 & 0xffffffff,param_4);
        uVar2 = uVar2 & 0xffffffff;
      }
    }
    else {
      if (param_2 != 0xc) {
        return uVar2;
      }
      if (iVar1 < 10) {
        *(undefined4 *)*param_4 = 0xffffffff;
      }
    }
    uVar2 = (ulong)((int)uVar2 - 10);
  }
  return uVar2;
}


// ==== entry=0090b020 orig=FUN_0090b020 size=244 name=OutlinePane_dtor ====

/* WARNING: Removing unreachable block (ram,0x0090b0a4) */
/* WARNING: Removing unreachable block (ram,0x0090b0f3) */

void OutlinePane_dtor(QWidget *param_1)

{
  long *plVar1;
  int iVar2;
  long *plVar3;
  int *piVar4;
  code *pcVar5;
  long lVar6;
  
  *(undefined ***)param_1 = &OutlinePane_vtable;
  *(undefined ***)(param_1 + 0x10) = &PTR_FUN_011a60f0;
  plVar3 = *(long **)(param_1 + 0x70);
  if (plVar3 != (long *)0x0) {
    LOCK();
    plVar1 = plVar3 + 1;
    lVar6 = *plVar1;
    *(int *)plVar1 = (int)*plVar1 + -1;
    UNLOCK();
    if ((int)lVar6 == 1) {
      if (*(code **)(*plVar3 + 0x10) != FUN_00575d12) {
        (**(code **)(*plVar3 + 0x10))(plVar3);
      }
      LOCK();
      piVar4 = (int *)((long)plVar3 + 0xc);
      iVar2 = *piVar4;
      *piVar4 = *piVar4 + -1;
      UNLOCK();
      if (iVar2 == 1) {
        pcVar5 = *(code **)(*plVar3 + 0x18);
        if (pcVar5 == std::_Sp_counted_base<(__gnu_cxx::_Lock_policy)2>::_M_destroy) {
          (**(code **)(*plVar3 + 8))();
        }
        else {
          (*pcVar5)(plVar3);
        }
      }
    }
  }
  piVar4 = *(int **)(param_1 + 0x50);
  if (piVar4 != (int *)0x0) {
    LOCK();
    *piVar4 = *piVar4 + -1;
    UNLOCK();
    if ((*piVar4 == 0) && (*(void **)(param_1 + 0x50) != (void *)0x0)) {
      operator_delete(*(void **)(param_1 + 0x50));
    }
  }
  *(undefined ***)param_1 = &PTR_FUN_011ab6b8;
  *(undefined **)(param_1 + 0x10) = &DAT_011ab8b0;
  QWidget::~QWidget(param_1);
  return;
}


// ==== entry=0090b114 name=FUN_0090b114 size=235 ====

/* WARNING: Removing unreachable block (ram,0x0090b199) */
/* WARNING: Removing unreachable block (ram,0x0090b1ec) */

void FUN_0090b114(undefined8 *param_1)

{
  long *plVar1;
  int iVar2;
  long *plVar3;
  int *piVar4;
  code *pcVar5;
  long lVar6;
  
  param_1[-2] = &OutlinePane_vtable;
  *param_1 = &PTR_FUN_011a60f0;
  plVar3 = (long *)param_1[0xc];
  if (plVar3 != (long *)0x0) {
    LOCK();
    plVar1 = plVar3 + 1;
    lVar6 = *plVar1;
    *(int *)plVar1 = (int)*plVar1 + -1;
    UNLOCK();
    if ((int)lVar6 == 1) {
      if (*(code **)(*plVar3 + 0x10) != FUN_00575d12) {
        (**(code **)(*plVar3 + 0x10))(plVar3);
      }
      LOCK();
      piVar4 = (int *)((long)plVar3 + 0xc);
      iVar2 = *piVar4;
      *piVar4 = *piVar4 + -1;
      UNLOCK();
      if (iVar2 == 1) {
        pcVar5 = *(code **)(*plVar3 + 0x18);
        if (pcVar5 == std::_Sp_counted_base<(__gnu_cxx::_Lock_policy)2>::_M_destroy) {
          (**(code **)(*plVar3 + 8))(plVar3);
        }
        else {
          (*pcVar5)();
        }
      }
    }
  }
  piVar4 = (int *)param_1[8];
  if (piVar4 != (int *)0x0) {
    LOCK();
    *piVar4 = *piVar4 + -1;
    UNLOCK();
    if ((*piVar4 == 0) && ((void *)param_1[8] != (void *)0x0)) {
      operator_delete((void *)param_1[8]);
    }
  }
  param_1[-2] = &PTR_FUN_011ab6b8;
  *param_1 = &DAT_011ab8b0;
  QWidget::~QWidget((QWidget *)(param_1 + -2));
  return;
}


// ==== entry=0090b200 name=FUN_0090b200 size=267 ====

/* WARNING: Removing unreachable block (ram,0x0090b2a1) */
/* WARNING: Removing unreachable block (ram,0x0090b2f8) */

void FUN_0090b200(undefined8 *param_1)

{
  long *plVar1;
  int iVar2;
  long *plVar3;
  int *piVar4;
  code *pcVar5;
  long lVar6;
  
  param_1[-2] = &OutlinePane_vtable;
  *param_1 = &PTR_FUN_011a60f0;
  plVar3 = (long *)param_1[0xc];
  if (plVar3 != (long *)0x0) {
    LOCK();
    plVar1 = plVar3 + 1;
    lVar6 = *plVar1;
    *(int *)plVar1 = (int)*plVar1 + -1;
    UNLOCK();
    if ((int)lVar6 == 1) {
      if (*(code **)(*plVar3 + 0x10) != FUN_00575d12) {
        (**(code **)(*plVar3 + 0x10))(plVar3);
      }
      LOCK();
      piVar4 = (int *)((long)plVar3 + 0xc);
      iVar2 = *piVar4;
      *piVar4 = *piVar4 + -1;
      UNLOCK();
      if (iVar2 == 1) {
        pcVar5 = *(code **)(*plVar3 + 0x18);
        if (pcVar5 == std::_Sp_counted_base<(__gnu_cxx::_Lock_policy)2>::_M_destroy) {
          (**(code **)(*plVar3 + 8))(plVar3);
        }
        else {
          (*pcVar5)();
        }
      }
    }
  }
  piVar4 = (int *)param_1[8];
  if (piVar4 != (int *)0x0) {
    LOCK();
    *piVar4 = *piVar4 + -1;
    UNLOCK();
    if ((*piVar4 == 0) && ((void *)param_1[8] != (void *)0x0)) {
      operator_delete((void *)param_1[8]);
    }
  }
  param_1[-2] = &PTR_FUN_011ab6b8;
  *param_1 = &DAT_011ab8b0;
  QWidget::~QWidget((QWidget *)(param_1 + -2));
  operator_delete((QWidget *)(param_1 + -2),0x90);
  return;
}


// ==== entry=0090b30c orig=FUN_0090b30c size=253 name=OutlinePane_dtor_deleting ====

/* WARNING: Removing unreachable block (ram,0x0090b39d) */
/* WARNING: Removing unreachable block (ram,0x0090b3f0) */

void OutlinePane_dtor_deleting(QWidget *param_1)

{
  long *plVar1;
  int iVar2;
  long *plVar3;
  int *piVar4;
  code *pcVar5;
  long lVar6;
  
  *(undefined ***)param_1 = &OutlinePane_vtable;
  *(undefined ***)(param_1 + 0x10) = &PTR_FUN_011a60f0;
  plVar3 = *(long **)(param_1 + 0x70);
  if (plVar3 != (long *)0x0) {
    LOCK();
    plVar1 = plVar3 + 1;
    lVar6 = *plVar1;
    *(int *)plVar1 = (int)*plVar1 + -1;
    UNLOCK();
    if ((int)lVar6 == 1) {
      if (*(code **)(*plVar3 + 0x10) != FUN_00575d12) {
        (**(code **)(*plVar3 + 0x10))(plVar3);
      }
      LOCK();
      piVar4 = (int *)((long)plVar3 + 0xc);
      iVar2 = *piVar4;
      *piVar4 = *piVar4 + -1;
      UNLOCK();
      if (iVar2 == 1) {
        pcVar5 = *(code **)(*plVar3 + 0x18);
        if (pcVar5 == std::_Sp_counted_base<(__gnu_cxx::_Lock_policy)2>::_M_destroy) {
          (**(code **)(*plVar3 + 8))();
        }
        else {
          (*pcVar5)(plVar3);
        }
      }
    }
  }
  piVar4 = *(int **)(param_1 + 0x50);
  if (piVar4 != (int *)0x0) {
    LOCK();
    *piVar4 = *piVar4 + -1;
    UNLOCK();
    if ((*piVar4 == 0) && (*(void **)(param_1 + 0x50) != (void *)0x0)) {
      operator_delete(*(void **)(param_1 + 0x50));
    }
  }
  *(undefined ***)param_1 = &PTR_FUN_011ab6b8;
  *(undefined **)(param_1 + 0x10) = &DAT_011ab8b0;
  QWidget::~QWidget(param_1);
  operator_delete(param_1,0x90);
  return;
}


// ==== entry=0090b410 orig=FUN_0090b410 size=24 name=SearchPane_metaObject ====

undefined ** SearchPane_metaObject(long param_1)

{
  undefined **ppuVar1;
  
  if (*(long *)(*(long *)(param_1 + 8) + 0x28) != 0) {
    ppuVar1 = (undefined **)QObjectData::dynamicMetaObject();
    return ppuVar1;
  }
  return &PTR_PTR_011a63e0;
}


// ==== entry=0090b428 orig=FUN_0090b428 size=66 name=SearchPane_qt_metacast ====

undefined8 SearchPane_qt_metacast(undefined8 param_1,char *param_2)

{
  int iVar1;
  undefined8 uVar2;
  
  if (param_2 == (char *)0x0) {
    return 0;
  }
  iVar1 = strcmp(param_2,"SearchPane");
  if (iVar1 == 0) {
    return param_1;
  }
  uVar2 = s_KitPane_91d3e2(param_1,param_2);
  return uVar2;
}


// ==== entry=0090b46a name=FUN_0090b46a size=19 ====

void FUN_0090b46a(QObject *param_1)

{
  QMetaObject::activate(param_1,(QMetaObject *)&PTR_PTR_011a63e0,1,(void **)0x0);
  return;
}


// ==== entry=0090b47e name=FUN_0090b47e size=19 ====

void FUN_0090b47e(QObject *param_1)

{
  QMetaObject::activate(param_1,(QMetaObject *)&PTR_PTR_011a63e0,2,(void **)0x0);
  return;
}


// ==== entry=0090b492 name=FUN_0090b492 size=52 ====

void FUN_0090b492(QObject *param_1,undefined8 param_2)

{
  undefined8 local_20;
  void *local_18;
  undefined8 *local_10;
  
  local_18 = (void *)0x0;
  local_10 = &local_20;
  local_20 = param_2;
  QMetaObject::activate(param_1,(QMetaObject *)&PTR_PTR_011a63e0,0,&local_18);
  return;
}


// ==== entry=0090b4c6 name=FUN_0090b4c6 size=147 ====

void FUN_0090b4c6(undefined8 param_1,undefined4 param_2,long param_3)

{
  switch(param_2) {
  case 0:
    FUN_0090b492(param_1,**(undefined8 **)(param_3 + 8));
    return;
  case 1:
    FUN_0090b46a();
    return;
  case 2:
    FUN_0090b47e();
    return;
  case 3:
    FUN_0074eecc(param_1,**(undefined4 **)(param_3 + 8));
    return;
  case 4:
    FUN_0074e9cc(param_1,**(undefined4 **)(param_3 + 8),**(undefined1 **)(param_3 + 0x10),
                 **(undefined4 **)(param_3 + 0x18));
    return;
  case 5:
    FUN_0074e9cc(param_1,**(undefined4 **)(param_3 + 8),**(undefined1 **)(param_3 + 0x10),0);
    return;
  case 6:
    FUN_0074e58e(param_1,**(undefined1 **)(param_3 + 8),*(undefined8 *)(param_3 + 0x10));
    return;
  case 7:
    FUN_0074f5ac(param_1,**(undefined1 **)(param_3 + 8),*(undefined8 *)(param_3 + 0x10));
    return;
  default:
    return;
  }
}


// ==== entry=0090b55a name=FUN_0090b55a size=101 ====

void FUN_0090b55a(undefined8 param_1,int param_2,undefined4 param_3,undefined8 *param_4)

{
  undefined4 *puVar1;
  long *plVar2;
  code *pcVar3;
  
  if (param_2 == 0) {
    FUN_0090b4c6(param_1,param_3,param_4);
    return;
  }
  if (param_2 == 10) {
    puVar1 = (undefined4 *)*param_4;
    plVar2 = (long *)param_4[1];
    pcVar3 = (code *)*plVar2;
    if ((pcVar3 == FUN_0090b492) && (plVar2[1] == 0)) {
      *puVar1 = 0;
      return;
    }
    if (pcVar3 == FUN_0090b46a) {
      if (plVar2[1] == 0) {
        *puVar1 = 1;
        return;
      }
    }
    else if ((pcVar3 == FUN_0090b47e) && (plVar2[1] == 0)) {
      *puVar1 = 2;
      return;
    }
  }
  return;
}


// ==== entry=0090b5c0 orig=FUN_0090b5c0 size=91 name=SearchPane_qt_metacall ====

ulong SearchPane_qt_metacall(undefined8 param_1,int param_2,undefined8 param_3,undefined8 *param_4)

{
  int iVar1;
  ulong uVar2;
  
  uVar2 = FUN_0091d424();
  iVar1 = (int)uVar2;
  if (-1 < iVar1) {
    if (param_2 == 0) {
      if (iVar1 < 8) {
        FUN_0090b4c6(param_1,uVar2 & 0xffffffff,param_4);
        uVar2 = uVar2 & 0xffffffff;
      }
    }
    else {
      if (param_2 != 0xc) {
        return uVar2;
      }
      if (iVar1 < 8) {
        *(undefined4 *)*param_4 = 0xffffffff;
      }
    }
    uVar2 = (ulong)((int)uVar2 - 8);
  }
  return uVar2;
}


// ==== entry=0090b61c orig=FUN_0090b61c size=258 name=SearchPane_dtor ====

void SearchPane_dtor(QWidget *param_1)

{
  int iVar1;
  undefined8 *puVar2;
  int *piVar3;
  undefined8 *puVar4;
  QArrayData *pQVar5;
  
  *(undefined ***)param_1 = &SearchPane_vtable;
  *(undefined ***)(param_1 + 0x10) = &PTR_FUN_011a6390;
  puVar2 = *(undefined8 **)(param_1 + 0x138);
  puVar4 = *(undefined8 **)(param_1 + 0x130);
  if (puVar2 != puVar4) {
    do {
      while( true ) {
        piVar3 = (int *)*puVar4;
        if (*piVar3 != 0) break;
LAB_0090b682:
        QArrayData::deallocate((QArrayData *)*puVar4,2,8);
        puVar4 = puVar4 + 3;
        if (puVar2 == puVar4) goto LAB_0090b69e;
      }
      if (*piVar3 != -1) {
        LOCK();
        iVar1 = *piVar3;
        *piVar3 = *piVar3 + -1;
        UNLOCK();
        if (iVar1 == 1) goto LAB_0090b682;
      }
      puVar4 = puVar4 + 3;
    } while (puVar2 != puVar4);
LAB_0090b69e:
    puVar4 = *(undefined8 **)(param_1 + 0x130);
  }
  if (puVar4 != (undefined8 *)0x0) {
    operator_delete(puVar4);
  }
  pQVar5 = *(QArrayData **)(param_1 + 0x118);
  if (*(int *)pQVar5 != 0) {
    if (*(int *)pQVar5 == -1) goto LAB_0090b6ca;
    LOCK();
    *(int *)pQVar5 = *(int *)pQVar5 + -1;
    UNLOCK();
    if (*(int *)pQVar5 != 0) goto LAB_0090b6ca;
    pQVar5 = *(QArrayData **)(param_1 + 0x118);
  }
  QArrayData::deallocate(pQVar5,2,8);
LAB_0090b6ca:
  if (*(long **)(param_1 + 0x110) != (long *)0x0) {
    (**(code **)(**(long **)(param_1 + 0x110) + 8))();
  }
  *(undefined ***)param_1 = &PTR_FUN_011ab6b8;
  *(undefined **)(param_1 + 0x10) = &DAT_011ab8b0;
  QWidget::~QWidget(param_1);
  return;
}


// ==== entry=0090b71e name=FUN_0090b71e size=258 ====

void FUN_0090b71e(undefined8 *param_1)

{
  int iVar1;
  undefined8 *puVar2;
  int *piVar3;
  undefined8 *puVar4;
  QArrayData *pQVar5;
  
  param_1[-2] = &SearchPane_vtable;
  *param_1 = &PTR_FUN_011a6390;
  puVar2 = (undefined8 *)param_1[0x25];
  puVar4 = (undefined8 *)param_1[0x24];
  if (puVar2 != puVar4) {
    do {
      while( true ) {
        piVar3 = (int *)*puVar4;
        if (*piVar3 != 0) break;
LAB_0090b783:
        QArrayData::deallocate((QArrayData *)*puVar4,2,8);
        puVar4 = puVar4 + 3;
        if (puVar2 == puVar4) goto LAB_0090b79e;
      }
      if (*piVar3 != -1) {
        LOCK();
        iVar1 = *piVar3;
        *piVar3 = *piVar3 + -1;
        UNLOCK();
        if (iVar1 == 1) goto LAB_0090b783;
      }
      puVar4 = puVar4 + 3;
    } while (puVar2 != puVar4);
LAB_0090b79e:
    puVar4 = (undefined8 *)param_1[0x24];
  }
  if (puVar4 != (undefined8 *)0x0) {
    operator_delete(puVar4);
  }
  pQVar5 = (QArrayData *)param_1[0x21];
  if (*(int *)pQVar5 != 0) {
    if (*(int *)pQVar5 == -1) goto LAB_0090b7ca;
    LOCK();
    *(int *)pQVar5 = *(int *)pQVar5 + -1;
    UNLOCK();
    if (*(int *)pQVar5 != 0) goto LAB_0090b7ca;
    pQVar5 = (QArrayData *)param_1[0x21];
  }
  QArrayData::deallocate(pQVar5,2,8);
LAB_0090b7ca:
  if ((long *)param_1[0x20] != (long *)0x0) {
    (**(code **)(*(long *)param_1[0x20] + 8))();
  }
  param_1[-2] = &PTR_FUN_011ab6b8;
  *param_1 = &DAT_011ab8b0;
  QWidget::~QWidget((QWidget *)(param_1 + -2));
  return;
}


// ==== entry=0090b820 name=FUN_0090b820 size=270 ====

void FUN_0090b820(undefined8 *param_1)

{
  int iVar1;
  undefined8 *puVar2;
  int *piVar3;
  undefined8 *puVar4;
  QArrayData *pQVar5;
  
  param_1[-2] = &SearchPane_vtable;
  *param_1 = &PTR_FUN_011a6390;
  puVar2 = (undefined8 *)param_1[0x25];
  puVar4 = (undefined8 *)param_1[0x24];
  if (puVar2 != puVar4) {
    do {
      while( true ) {
        piVar3 = (int *)*puVar4;
        if (*piVar3 != 0) break;
LAB_0090b887:
        QArrayData::deallocate((QArrayData *)*puVar4,2,8);
        puVar4 = puVar4 + 3;
        if (puVar2 == puVar4) goto LAB_0090b8a2;
      }
      if (*piVar3 != -1) {
        LOCK();
        iVar1 = *piVar3;
        *piVar3 = *piVar3 + -1;
        UNLOCK();
        if (iVar1 == 1) goto LAB_0090b887;
      }
      puVar4 = puVar4 + 3;
    } while (puVar2 != puVar4);
LAB_0090b8a2:
    puVar4 = (undefined8 *)param_1[0x24];
  }
  if (puVar4 != (undefined8 *)0x0) {
    operator_delete(puVar4);
  }
  pQVar5 = (QArrayData *)param_1[0x21];
  if (*(int *)pQVar5 != 0) {
    if (*(int *)pQVar5 == -1) goto LAB_0090b8ce;
    LOCK();
    *(int *)pQVar5 = *(int *)pQVar5 + -1;
    UNLOCK();
    if (*(int *)pQVar5 != 0) goto LAB_0090b8ce;
    pQVar5 = (QArrayData *)param_1[0x21];
  }
  QArrayData::deallocate(pQVar5,2,8);
LAB_0090b8ce:
  if ((long *)param_1[0x20] != (long *)0x0) {
    (**(code **)(*(long *)param_1[0x20] + 8))();
  }
  param_1[-2] = &PTR_FUN_011ab6b8;
  *param_1 = &DAT_011ab8b0;
  QWidget::~QWidget((QWidget *)(param_1 + -2));
  operator_delete((QWidget *)(param_1 + -2),0x148);
  return;
}


// ==== entry=0090b92e orig=FUN_0090b92e size=271 name=SearchPane_dtor_deleting ====

void SearchPane_dtor_deleting(QWidget *param_1)

{
  int iVar1;
  undefined8 *puVar2;
  int *piVar3;
  undefined8 *puVar4;
  QArrayData *pQVar5;
  
  *(undefined ***)param_1 = &SearchPane_vtable;
  *(undefined ***)(param_1 + 0x10) = &PTR_FUN_011a6390;
  puVar2 = *(undefined8 **)(param_1 + 0x138);
  puVar4 = *(undefined8 **)(param_1 + 0x130);
  if (puVar2 != puVar4) {
    do {
      while( true ) {
        piVar3 = (int *)*puVar4;
        if (*piVar3 != 0) break;
LAB_0090b994:
        QArrayData::deallocate((QArrayData *)*puVar4,2,8);
        puVar4 = puVar4 + 3;
        if (puVar2 == puVar4) goto LAB_0090b9b0;
      }
      if (*piVar3 != -1) {
        LOCK();
        iVar1 = *piVar3;
        *piVar3 = *piVar3 + -1;
        UNLOCK();
        if (iVar1 == 1) goto LAB_0090b994;
      }
      puVar4 = puVar4 + 3;
    } while (puVar2 != puVar4);
LAB_0090b9b0:
    puVar4 = *(undefined8 **)(param_1 + 0x130);
  }
  if (puVar4 != (undefined8 *)0x0) {
    operator_delete(puVar4);
  }
  pQVar5 = *(QArrayData **)(param_1 + 0x118);
  if (*(int *)pQVar5 != 0) {
    if (*(int *)pQVar5 == -1) goto LAB_0090b9dc;
    LOCK();
    *(int *)pQVar5 = *(int *)pQVar5 + -1;
    UNLOCK();
    if (*(int *)pQVar5 != 0) goto LAB_0090b9dc;
    pQVar5 = *(QArrayData **)(param_1 + 0x118);
  }
  QArrayData::deallocate(pQVar5,2,8);
LAB_0090b9dc:
  if (*(long **)(param_1 + 0x110) != (long *)0x0) {
    (**(code **)(**(long **)(param_1 + 0x110) + 8))();
  }
  *(undefined ***)param_1 = &PTR_FUN_011ab6b8;
  *(undefined **)(param_1 + 0x10) = &DAT_011ab8b0;
  QWidget::~QWidget(param_1);
  operator_delete(param_1,0x148);
  return;
}


// ==== entry=0090ba40 orig=FUN_0090ba40 size=24 name=ShellPane_metaObject ====

undefined ** ShellPane_metaObject(long param_1)

{
  undefined **ppuVar1;
  
  if (*(long *)(*(long *)(param_1 + 8) + 0x28) != 0) {
    ppuVar1 = (undefined **)QObjectData::dynamicMetaObject();
    return ppuVar1;
  }
  return &PTR_PTR_011a6680;
}


// ==== entry=0090ba58 orig=FUN_0090ba58 size=66 name=ShellPane_qt_metacast ====

undefined8 ShellPane_qt_metacast(undefined8 param_1,char *param_2)

{
  int iVar1;
  undefined8 uVar2;
  
  if (param_2 == (char *)0x0) {
    return 0;
  }
  iVar1 = strcmp(param_2,"ShellPane");
  if (iVar1 == 0) {
    return param_1;
  }
  uVar2 = s_KitPane_91d3e2(param_1,param_2);
  return uVar2;
}


// ==== entry=0090ba9a name=FUN_0090ba9a size=56 ====

void FUN_0090ba9a(undefined8 param_1,int param_2,int param_3,long *param_4)

{
  undefined4 uVar1;
  
  if (param_2 == 0) {
    if (param_3 == 0) {
      uVar1 = s_session_color_7503a0(param_1,param_4[1]);
      if ((undefined4 *)*param_4 != (undefined4 *)0x0) {
        *(undefined4 *)*param_4 = uVar1;
      }
    }
    else if (param_3 == 1) {
      uVar1 = FUN_0074ffde();
      if ((undefined4 *)*param_4 != (undefined4 *)0x0) {
        *(undefined4 *)*param_4 = uVar1;
      }
    }
    return;
  }
  return;
}


// ==== entry=0090bad2 orig=FUN_0090bad2 size=93 name=ShellPane_qt_metacall ====

ulong ShellPane_qt_metacall(undefined8 param_1,int param_2,undefined8 param_3,undefined8 *param_4)

{
  int iVar1;
  ulong uVar2;
  
  uVar2 = FUN_0091d424();
  iVar1 = (int)uVar2;
  if (-1 < iVar1) {
    if (param_2 == 0) {
      if (iVar1 < 2) {
        FUN_0090ba9a(param_1,0,uVar2 & 0xffffffff,param_4);
        uVar2 = uVar2 & 0xffffffff;
      }
    }
    else {
      if (param_2 != 0xc) {
        return uVar2;
      }
      if (iVar1 < 2) {
        *(undefined4 *)*param_4 = 0xffffffff;
      }
    }
    uVar2 = (ulong)((int)uVar2 - 2);
  }
  return uVar2;
}


// ==== entry=0090bb30 orig=FUN_0090bb30 size=143 name=ShellPane_dtor_deleting ====

void ShellPane_dtor_deleting(QWidget *param_1)

{
  QMapNodeBase *pQVar1;
  
  *(undefined ***)param_1 = &ShellPane_vtable;
  *(undefined ***)(param_1 + 0x10) = &PTR_FUN_011a6630;
  pQVar1 = *(QMapNodeBase **)(param_1 + 0x58);
  if (*(int *)pQVar1 != 0) {
    if (*(int *)pQVar1 == -1) goto LAB_0090bb68;
    LOCK();
    *(int *)pQVar1 = *(int *)pQVar1 + -1;
    UNLOCK();
    if (*(int *)pQVar1 != 0) goto LAB_0090bb68;
    pQVar1 = *(QMapNodeBase **)(param_1 + 0x58);
  }
  if (*(long *)(pQVar1 + 0x10) != 0) {
    QMapDataBase::freeTree(pQVar1,(int)*(long *)(pQVar1 + 0x10));
  }
  QMapDataBase::freeData((QMapDataBase *)pQVar1);
LAB_0090bb68:
  *(undefined ***)param_1 = &PTR_FUN_011ab6b8;
  *(undefined **)(param_1 + 0x10) = &DAT_011ab8b0;
  QWidget::~QWidget(param_1);
  operator_delete(param_1,0x60);
  return;
}


// ==== entry=0090bbbf name=FUN_0090bbbf size=143 ====

void FUN_0090bbbf(undefined8 *param_1)

{
  QMapNodeBase *pQVar1;
  
  param_1[-2] = &ShellPane_vtable;
  *param_1 = &PTR_FUN_011a6630;
  pQVar1 = (QMapNodeBase *)param_1[9];
  if (*(int *)pQVar1 != 0) {
    if (*(int *)pQVar1 == -1) goto LAB_0090bbf9;
    LOCK();
    *(int *)pQVar1 = *(int *)pQVar1 + -1;
    UNLOCK();
    if (*(int *)pQVar1 != 0) goto LAB_0090bbf9;
    pQVar1 = (QMapNodeBase *)param_1[9];
  }
  if (*(long *)(pQVar1 + 0x10) != 0) {
    QMapDataBase::freeTree(pQVar1,(int)*(long *)(pQVar1 + 0x10));
  }
  QMapDataBase::freeData((QMapDataBase *)pQVar1);
LAB_0090bbf9:
  param_1[-2] = &PTR_FUN_011ab6b8;
  *param_1 = &DAT_011ab8b0;
  QWidget::~QWidget((QWidget *)(param_1 + -2));
  operator_delete((QWidget *)(param_1 + -2),0x60);
  return;
}


// ==== entry=0090bc4e name=FUN_0090bc4e size=131 ====

void FUN_0090bc4e(undefined8 *param_1)

{
  QMapNodeBase *pQVar1;
  
  param_1[-2] = &ShellPane_vtable;
  *param_1 = &PTR_FUN_011a6630;
  pQVar1 = (QMapNodeBase *)param_1[9];
  if (*(int *)pQVar1 != 0) {
    if (*(int *)pQVar1 == -1) goto LAB_0090bc86;
    LOCK();
    *(int *)pQVar1 = *(int *)pQVar1 + -1;
    UNLOCK();
    if (*(int *)pQVar1 != 0) goto LAB_0090bc86;
    pQVar1 = (QMapNodeBase *)param_1[9];
  }
  if (*(long *)(pQVar1 + 0x10) != 0) {
    QMapDataBase::freeTree(pQVar1,(int)*(long *)(pQVar1 + 0x10));
  }
  QMapDataBase::freeData((QMapDataBase *)pQVar1);
LAB_0090bc86:
  param_1[-2] = &PTR_FUN_011ab6b8;
  *param_1 = &DAT_011ab8b0;
  QWidget::~QWidget((QWidget *)(param_1 + -2));
  return;
}


// ==== entry=0090bcd2 orig=FUN_0090bcd2 size=130 name=ShellPane_dtor ====

void ShellPane_dtor(QWidget *param_1)

{
  QMapNodeBase *pQVar1;
  
  *(undefined ***)param_1 = &ShellPane_vtable;
  *(undefined ***)(param_1 + 0x10) = &PTR_FUN_011a6630;
  pQVar1 = *(QMapNodeBase **)(param_1 + 0x58);
  if (*(int *)pQVar1 != 0) {
    if (*(int *)pQVar1 == -1) goto LAB_0090bd0a;
    LOCK();
    *(int *)pQVar1 = *(int *)pQVar1 + -1;
    UNLOCK();
    if (*(int *)pQVar1 != 0) goto LAB_0090bd0a;
    pQVar1 = *(QMapNodeBase **)(param_1 + 0x58);
  }
  if (*(long *)(pQVar1 + 0x10) != 0) {
    QMapDataBase::freeTree(pQVar1,(int)*(long *)(pQVar1 + 0x10));
  }
  QMapDataBase::freeData((QMapDataBase *)pQVar1);
LAB_0090bd0a:
  *(undefined ***)param_1 = &PTR_FUN_011ab6b8;
  *(undefined **)(param_1 + 0x10) = &DAT_011ab8b0;
  QWidget::~QWidget(param_1);
  return;
}


// ==== entry=0090bd54 name=FUN_0090bd54 size=1 ====

void FUN_0090bd54(void)

{
  return;
}


// ==== entry=0090bd56 orig=FUN_0090bd56 size=24 name=ApplicationTheme_metaObject ====

undefined ** ApplicationTheme_metaObject(long param_1)

{
  undefined **ppuVar1;
  
  if (*(long *)(*(long *)(param_1 + 8) + 0x28) != 0) {
    ppuVar1 = (undefined **)QObjectData::dynamicMetaObject();
    return ppuVar1;
  }
  return &PTR_staticMetaObject_011a6740;
}


// ==== entry=0090bd6e orig=FUN_0090bd6e size=66 name=ApplicationTheme_qt_metacast ====

char * ApplicationTheme_qt_metacast(char *param_1,char *param_2)

{
  int iVar1;
  char *pcVar2;
  
  if (param_2 == (char *)0x0) {
    return (char *)0x0;
  }
  iVar1 = strcmp(param_2,"ApplicationTheme");
  if (iVar1 == 0) {
    return param_1;
  }
  pcVar2 = (char *)QObject::qt_metacast(param_1);
  return pcVar2;
}


// ==== entry=0090bdb0 orig=FUN_0090bdb0 size=5 name=ApplicationTheme_qt_metacall ====

void QObject::ApplicationTheme_qt_metacall(void)

{
  qt_metacall();
  return;
}


// ==== entry=0090bdc0 name=FUN_0090bdc0 size=5105 ====

void FUN_0090bdc0(long param_1,int param_2,uint param_3,undefined8 *param_4)

{
  undefined8 uVar1;
  undefined8 uVar2;
  QBrush *pQVar3;
  undefined8 local_20 [2];
  
  if (param_2 == 1) {
    param_4 = (undefined8 *)*param_4;
    if (param_3 < 0x3c) {
      uVar1 = *(undefined8 *)(param_1 + 0x38);
      switch(param_3) {
      case 0:
        pQVar3 = (QBrush *)QPalette::brush(uVar1,0,10);
        QBrush::QBrush((QBrush *)local_20,pQVar3);
        uVar1 = *param_4;
        *param_4 = local_20[0];
        local_20[0] = uVar1;
        QBrush::~QBrush((QBrush *)local_20);
        break;
      case 1:
        pQVar3 = (QBrush *)QPalette::brush(uVar1,1,10);
        QBrush::QBrush((QBrush *)local_20,pQVar3);
        uVar1 = *param_4;
        *param_4 = local_20[0];
        local_20[0] = uVar1;
        QBrush::~QBrush((QBrush *)local_20);
        break;
      case 2:
        pQVar3 = (QBrush *)QPalette::brush(uVar1,2,10);
        QBrush::QBrush((QBrush *)local_20,pQVar3);
        uVar1 = *param_4;
        *param_4 = local_20[0];
        local_20[0] = uVar1;
        QBrush::~QBrush((QBrush *)local_20);
        break;
      case 3:
        pQVar3 = (QBrush *)QPalette::brush(uVar1,0,0);
        QBrush::QBrush((QBrush *)local_20,pQVar3);
        uVar1 = *param_4;
        *param_4 = local_20[0];
        local_20[0] = uVar1;
        QBrush::~QBrush((QBrush *)local_20);
        break;
      case 4:
        pQVar3 = (QBrush *)QPalette::brush(uVar1,1,0);
        QBrush::QBrush((QBrush *)local_20,pQVar3);
        uVar1 = *param_4;
        *param_4 = local_20[0];
        local_20[0] = uVar1;
        QBrush::~QBrush((QBrush *)local_20);
        break;
      case 5:
        pQVar3 = (QBrush *)QPalette::brush(uVar1,2,0);
        QBrush::QBrush((QBrush *)local_20,pQVar3);
        uVar1 = *param_4;
        *param_4 = local_20[0];
        local_20[0] = uVar1;
        QBrush::~QBrush((QBrush *)local_20);
        break;
      case 6:
        pQVar3 = (QBrush *)QPalette::brush(uVar1,0,9);
        QBrush::QBrush((QBrush *)local_20,pQVar3);
        uVar1 = *param_4;
        *param_4 = local_20[0];
        local_20[0] = uVar1;
        QBrush::~QBrush((QBrush *)local_20);
        break;
      case 7:
        pQVar3 = (QBrush *)QPalette::brush(uVar1,1,9);
        QBrush::QBrush((QBrush *)local_20,pQVar3);
        uVar1 = *param_4;
        *param_4 = local_20[0];
        local_20[0] = uVar1;
        QBrush::~QBrush((QBrush *)local_20);
        break;
      case 8:
        pQVar3 = (QBrush *)QPalette::brush(uVar1,2,9);
        QBrush::QBrush((QBrush *)local_20,pQVar3);
        uVar1 = *param_4;
        *param_4 = local_20[0];
        local_20[0] = uVar1;
        QBrush::~QBrush((QBrush *)local_20);
        break;
      case 9:
        pQVar3 = (QBrush *)QPalette::brush(uVar1,0,0x10);
        QBrush::QBrush((QBrush *)local_20,pQVar3);
        uVar1 = *param_4;
        *param_4 = local_20[0];
        local_20[0] = uVar1;
        QBrush::~QBrush((QBrush *)local_20);
        break;
      case 10:
        pQVar3 = (QBrush *)QPalette::brush(uVar1,1,0x10);
        QBrush::QBrush((QBrush *)local_20,pQVar3);
        uVar1 = *param_4;
        *param_4 = local_20[0];
        local_20[0] = uVar1;
        QBrush::~QBrush((QBrush *)local_20);
        break;
      case 0xb:
        pQVar3 = (QBrush *)QPalette::brush(uVar1,2,0x10);
        QBrush::QBrush((QBrush *)local_20,pQVar3);
        uVar1 = *param_4;
        *param_4 = local_20[0];
        local_20[0] = uVar1;
        QBrush::~QBrush((QBrush *)local_20);
        break;
      case 0xc:
        pQVar3 = (QBrush *)QPalette::brush(uVar1,0,0x12);
        QBrush::QBrush((QBrush *)local_20,pQVar3);
        uVar1 = *param_4;
        *param_4 = local_20[0];
        local_20[0] = uVar1;
        QBrush::~QBrush((QBrush *)local_20);
        break;
      case 0xd:
        pQVar3 = (QBrush *)QPalette::brush(uVar1,1,0x12);
        QBrush::QBrush((QBrush *)local_20,pQVar3);
        uVar1 = *param_4;
        *param_4 = local_20[0];
        local_20[0] = uVar1;
        QBrush::~QBrush((QBrush *)local_20);
        break;
      case 0xe:
        pQVar3 = (QBrush *)QPalette::brush(uVar1,2,0x12);
        QBrush::QBrush((QBrush *)local_20,pQVar3);
        uVar1 = *param_4;
        *param_4 = local_20[0];
        local_20[0] = uVar1;
        QBrush::~QBrush((QBrush *)local_20);
        break;
      case 0xf:
        pQVar3 = (QBrush *)QPalette::brush(uVar1,0,0x13);
        QBrush::QBrush((QBrush *)local_20,pQVar3);
        uVar1 = *param_4;
        *param_4 = local_20[0];
        local_20[0] = uVar1;
        QBrush::~QBrush((QBrush *)local_20);
        break;
      case 0x10:
        pQVar3 = (QBrush *)QPalette::brush(uVar1,1,0x13);
        QBrush::QBrush((QBrush *)local_20,pQVar3);
        uVar1 = *param_4;
        *param_4 = local_20[0];
        local_20[0] = uVar1;
        QBrush::~QBrush((QBrush *)local_20);
        break;
      case 0x11:
        pQVar3 = (QBrush *)QPalette::brush(uVar1,2,0x13);
        QBrush::QBrush((QBrush *)local_20,pQVar3);
        uVar1 = *param_4;
        *param_4 = local_20[0];
        local_20[0] = uVar1;
        QBrush::~QBrush((QBrush *)local_20);
        break;
      case 0x12:
        pQVar3 = (QBrush *)QPalette::brush(uVar1,0,0x14);
        QBrush::QBrush((QBrush *)local_20,pQVar3);
        uVar1 = *param_4;
        *param_4 = local_20[0];
        local_20[0] = uVar1;
        QBrush::~QBrush((QBrush *)local_20);
        break;
      case 0x13:
        pQVar3 = (QBrush *)QPalette::brush(uVar1,1,0x14);
        QBrush::QBrush((QBrush *)local_20,pQVar3);
        uVar1 = *param_4;
        *param_4 = local_20[0];
        local_20[0] = uVar1;
        QBrush::~QBrush((QBrush *)local_20);
        break;
      case 0x14:
        pQVar3 = (QBrush *)QPalette::brush(uVar1,2,0x14);
        QBrush::QBrush((QBrush *)local_20,pQVar3);
        uVar1 = *param_4;
        *param_4 = local_20[0];
        local_20[0] = uVar1;
        QBrush::~QBrush((QBrush *)local_20);
        break;
      case 0x15:
        pQVar3 = (QBrush *)QPalette::brush(uVar1,0,6);
        QBrush::QBrush((QBrush *)local_20,pQVar3);
        uVar1 = *param_4;
        *param_4 = local_20[0];
        local_20[0] = uVar1;
        QBrush::~QBrush((QBrush *)local_20);
        break;
      case 0x16:
        pQVar3 = (QBrush *)QPalette::brush(uVar1,1,6);
        QBrush::QBrush((QBrush *)local_20,pQVar3);
        uVar1 = *param_4;
        *param_4 = local_20[0];
        local_20[0] = uVar1;
        QBrush::~QBrush((QBrush *)local_20);
        break;
      case 0x17:
        pQVar3 = (QBrush *)QPalette::brush(uVar1,2,6);
        QBrush::QBrush((QBrush *)local_20,pQVar3);
        uVar1 = *param_4;
        *param_4 = local_20[0];
        local_20[0] = uVar1;
        QBrush::~QBrush((QBrush *)local_20);
        break;
      case 0x18:
        pQVar3 = (QBrush *)QPalette::brush(uVar1,0,1);
        QBrush::QBrush((QBrush *)local_20,pQVar3);
        uVar1 = *param_4;
        *param_4 = local_20[0];
        local_20[0] = uVar1;
        QBrush::~QBrush((QBrush *)local_20);
        break;
      case 0x19:
        pQVar3 = (QBrush *)QPalette::brush(uVar1,1,1);
        QBrush::QBrush((QBrush *)local_20,pQVar3);
        uVar1 = *param_4;
        *param_4 = local_20[0];
        local_20[0] = uVar1;
        QBrush::~QBrush((QBrush *)local_20);
        break;
      case 0x1a:
        pQVar3 = (QBrush *)QPalette::brush(uVar1,2,1);
        QBrush::QBrush((QBrush *)local_20,pQVar3);
        uVar1 = *param_4;
        *param_4 = local_20[0];
        local_20[0] = uVar1;
        QBrush::~QBrush((QBrush *)local_20);
        break;
      case 0x1b:
        pQVar3 = (QBrush *)QPalette::brush(uVar1,0,8);
        QBrush::QBrush((QBrush *)local_20,pQVar3);
        uVar1 = *param_4;
        *param_4 = local_20[0];
        local_20[0] = uVar1;
        QBrush::~QBrush((QBrush *)local_20);
        break;
      case 0x1c:
        pQVar3 = (QBrush *)QPalette::brush(uVar1,1,8);
        QBrush::QBrush((QBrush *)local_20,pQVar3);
        uVar1 = *param_4;
        *param_4 = local_20[0];
        local_20[0] = uVar1;
        QBrush::~QBrush((QBrush *)local_20);
        break;
      case 0x1d:
        pQVar3 = (QBrush *)QPalette::brush(uVar1,2,8);
        QBrush::QBrush((QBrush *)local_20,pQVar3);
        uVar1 = *param_4;
        *param_4 = local_20[0];
        local_20[0] = uVar1;
        QBrush::~QBrush((QBrush *)local_20);
        break;
      case 0x1e:
        pQVar3 = (QBrush *)QPalette::brush(uVar1,0,7);
        QBrush::QBrush((QBrush *)local_20,pQVar3);
        uVar1 = *param_4;
        *param_4 = local_20[0];
        local_20[0] = uVar1;
        QBrush::~QBrush((QBrush *)local_20);
        break;
      case 0x1f:
        pQVar3 = (QBrush *)QPalette::brush(uVar1,1,7);
        QBrush::QBrush((QBrush *)local_20,pQVar3);
        uVar1 = *param_4;
        *param_4 = local_20[0];
        local_20[0] = uVar1;
        QBrush::~QBrush((QBrush *)local_20);
        break;
      case 0x20:
        pQVar3 = (QBrush *)QPalette::brush(uVar1,2,7);
        QBrush::QBrush((QBrush *)local_20,pQVar3);
        uVar1 = *param_4;
        *param_4 = local_20[0];
        local_20[0] = uVar1;
        QBrush::~QBrush((QBrush *)local_20);
        break;
      case 0x21:
        pQVar3 = (QBrush *)QPalette::brush(uVar1,0,2);
        QBrush::QBrush((QBrush *)local_20,pQVar3);
        uVar1 = *param_4;
        *param_4 = local_20[0];
        local_20[0] = uVar1;
        QBrush::~QBrush((QBrush *)local_20);
        break;
      case 0x22:
        pQVar3 = (QBrush *)QPalette::brush(uVar1,1,2);
        QBrush::QBrush((QBrush *)local_20,pQVar3);
        uVar1 = *param_4;
        *param_4 = local_20[0];
        local_20[0] = uVar1;
        QBrush::~QBrush((QBrush *)local_20);
        break;
      case 0x23:
        pQVar3 = (QBrush *)QPalette::brush(uVar1,2,2);
        QBrush::QBrush((QBrush *)local_20,pQVar3);
        uVar1 = *param_4;
        *param_4 = local_20[0];
        local_20[0] = uVar1;
        QBrush::~QBrush((QBrush *)local_20);
        break;
      case 0x24:
        pQVar3 = (QBrush *)QPalette::brush(uVar1,0,3);
        QBrush::QBrush((QBrush *)local_20,pQVar3);
        uVar1 = *param_4;
        *param_4 = local_20[0];
        local_20[0] = uVar1;
        QBrush::~QBrush((QBrush *)local_20);
        break;
      case 0x25:
        pQVar3 = (QBrush *)QPalette::brush(uVar1,1,3);
        QBrush::QBrush((QBrush *)local_20,pQVar3);
        uVar1 = *param_4;
        *param_4 = local_20[0];
        local_20[0] = uVar1;
        QBrush::~QBrush((QBrush *)local_20);
        break;
      case 0x26:
        pQVar3 = (QBrush *)QPalette::brush(uVar1,2,3);
        QBrush::QBrush((QBrush *)local_20,pQVar3);
        uVar1 = *param_4;
        *param_4 = local_20[0];
        local_20[0] = uVar1;
        QBrush::~QBrush((QBrush *)local_20);
        break;
      case 0x27:
        pQVar3 = (QBrush *)QPalette::brush(uVar1,0,4);
        QBrush::QBrush((QBrush *)local_20,pQVar3);
        uVar1 = *param_4;
        *param_4 = local_20[0];
        local_20[0] = uVar1;
        QBrush::~QBrush((QBrush *)local_20);
        break;
      case 0x28:
        pQVar3 = (QBrush *)QPalette::brush(uVar1,1,4);
        QBrush::QBrush((QBrush *)local_20,pQVar3);
        uVar1 = *param_4;
        *param_4 = local_20[0];
        local_20[0] = uVar1;
        QBrush::~QBrush((QBrush *)local_20);
        break;
      case 0x29:
        pQVar3 = (QBrush *)QPalette::brush(uVar1,2,4);
        QBrush::QBrush((QBrush *)local_20,pQVar3);
        uVar1 = *param_4;
        *param_4 = local_20[0];
        local_20[0] = uVar1;
        QBrush::~QBrush((QBrush *)local_20);
        break;
      case 0x2a:
        pQVar3 = (QBrush *)QPalette::brush(uVar1,0,5);
        QBrush::QBrush((QBrush *)local_20,pQVar3);
        uVar1 = *param_4;
        *param_4 = local_20[0];
        local_20[0] = uVar1;
        QBrush::~QBrush((QBrush *)local_20);
        break;
      case 0x2b:
        pQVar3 = (QBrush *)QPalette::brush(uVar1,1,5);
        QBrush::QBrush((QBrush *)local_20,pQVar3);
        uVar1 = *param_4;
        *param_4 = local_20[0];
        local_20[0] = uVar1;
        QBrush::~QBrush((QBrush *)local_20);
        break;
      case 0x2c:
        pQVar3 = (QBrush *)QPalette::brush(uVar1,2,5);
        QBrush::QBrush((QBrush *)local_20,pQVar3);
        uVar1 = *param_4;
        *param_4 = local_20[0];
        local_20[0] = uVar1;
        QBrush::~QBrush((QBrush *)local_20);
        break;
      case 0x2d:
        pQVar3 = (QBrush *)QPalette::brush(uVar1,0,0xb);
        QBrush::QBrush((QBrush *)local_20,pQVar3);
        uVar1 = *param_4;
        *param_4 = local_20[0];
        local_20[0] = uVar1;
        QBrush::~QBrush((QBrush *)local_20);
        break;
      case 0x2e:
        pQVar3 = (QBrush *)QPalette::brush(uVar1,1,0xb);
        QBrush::QBrush((QBrush *)local_20,pQVar3);
        uVar1 = *param_4;
        *param_4 = local_20[0];
        local_20[0] = uVar1;
        QBrush::~QBrush((QBrush *)local_20);
        break;
      case 0x2f:
        pQVar3 = (QBrush *)QPalette::brush(uVar1,2,0xb);
        QBrush::QBrush((QBrush *)local_20,pQVar3);
        uVar1 = *param_4;
        *param_4 = local_20[0];
        local_20[0] = uVar1;
        QBrush::~QBrush((QBrush *)local_20);
        break;
      case 0x30:
        pQVar3 = (QBrush *)QPalette::brush(uVar1,0,0xc);
        QBrush::QBrush((QBrush *)local_20,pQVar3);
        uVar1 = *param_4;
        *param_4 = local_20[0];
        local_20[0] = uVar1;
        QBrush::~QBrush((QBrush *)local_20);
        break;
      case 0x31:
        pQVar3 = (QBrush *)QPalette::brush(uVar1,1,0xc);
        QBrush::QBrush((QBrush *)local_20,pQVar3);
        uVar1 = *param_4;
        *param_4 = local_20[0];
        local_20[0] = uVar1;
        QBrush::~QBrush((QBrush *)local_20);
        break;
      case 0x32:
        pQVar3 = (QBrush *)QPalette::brush(uVar1,2,0xc);
        QBrush::QBrush((QBrush *)local_20,pQVar3);
        uVar1 = *param_4;
        *param_4 = local_20[0];
        local_20[0] = uVar1;
        QBrush::~QBrush((QBrush *)local_20);
        break;
      case 0x33:
        pQVar3 = (QBrush *)QPalette::brush(uVar1,0,0xd);
        QBrush::QBrush((QBrush *)local_20,pQVar3);
        uVar1 = *param_4;
        *param_4 = local_20[0];
        local_20[0] = uVar1;
        QBrush::~QBrush((QBrush *)local_20);
        break;
      case 0x34:
        pQVar3 = (QBrush *)QPalette::brush(uVar1,1,0xd);
        QBrush::QBrush((QBrush *)local_20,pQVar3);
        uVar1 = *param_4;
        *param_4 = local_20[0];
        local_20[0] = uVar1;
        QBrush::~QBrush((QBrush *)local_20);
        break;
      case 0x35:
        pQVar3 = (QBrush *)QPalette::brush(uVar1,2,0xd);
        QBrush::QBrush((QBrush *)local_20,pQVar3);
        uVar1 = *param_4;
        *param_4 = local_20[0];
        local_20[0] = uVar1;
        QBrush::~QBrush((QBrush *)local_20);
        break;
      case 0x36:
        pQVar3 = (QBrush *)QPalette::brush(uVar1,0,0xe);
        QBrush::QBrush((QBrush *)local_20,pQVar3);
        uVar1 = *param_4;
        *param_4 = local_20[0];
        local_20[0] = uVar1;
        QBrush::~QBrush((QBrush *)local_20);
        break;
      case 0x37:
        pQVar3 = (QBrush *)QPalette::brush(uVar1,1,0xe);
        QBrush::QBrush((QBrush *)local_20,pQVar3);
        uVar1 = *param_4;
        *param_4 = local_20[0];
        local_20[0] = uVar1;
        QBrush::~QBrush((QBrush *)local_20);
        break;
      case 0x38:
        pQVar3 = (QBrush *)QPalette::brush(uVar1,2,0xe);
        QBrush::QBrush((QBrush *)local_20,pQVar3);
        uVar1 = *param_4;
        *param_4 = local_20[0];
        local_20[0] = uVar1;
        QBrush::~QBrush((QBrush *)local_20);
        break;
      case 0x39:
        pQVar3 = (QBrush *)QPalette::brush(uVar1,0,0xf);
        QBrush::QBrush((QBrush *)local_20,pQVar3);
        uVar1 = *param_4;
        *param_4 = local_20[0];
        local_20[0] = uVar1;
        QBrush::~QBrush((QBrush *)local_20);
        break;
      case 0x3a:
        pQVar3 = (QBrush *)QPalette::brush(uVar1,1,0xf);
        QBrush::QBrush((QBrush *)local_20,pQVar3);
        uVar1 = *param_4;
        *param_4 = local_20[0];
        local_20[0] = uVar1;
        QBrush::~QBrush((QBrush *)local_20);
        break;
      case 0x3b:
        pQVar3 = (QBrush *)QPalette::brush(uVar1,2,0xf);
        QBrush::QBrush((QBrush *)local_20,pQVar3);
        uVar1 = *param_4;
        *param_4 = local_20[0];
        local_20[0] = uVar1;
        QBrush::~QBrush((QBrush *)local_20);
      }
    }
  }
  else if ((param_2 == 2) && (uVar1 = *param_4, param_3 < 0x3c)) {
    uVar2 = *(undefined8 *)(param_1 + 0x38);
    switch(param_3) {
    case 0:
      QPalette::setBrush(uVar2,0,10,uVar1);
      *(undefined1 *)(param_1 + 0x30) = 1;
      break;
    case 1:
      QPalette::setBrush(uVar2,1,10,uVar1);
      *(undefined1 *)(param_1 + 0x30) = 1;
      break;
    case 2:
      QPalette::setBrush(uVar2,2,10,uVar1);
      *(undefined1 *)(param_1 + 0x30) = 1;
      break;
    case 3:
      QPalette::setBrush(uVar2,0,0,uVar1);
      *(undefined1 *)(param_1 + 0x30) = 1;
      break;
    case 4:
      QPalette::setBrush(uVar2,1,0,uVar1);
      *(undefined1 *)(param_1 + 0x30) = 1;
      break;
    case 5:
      QPalette::setBrush(uVar2,2,0,uVar1);
      *(undefined1 *)(param_1 + 0x30) = 1;
      break;
    case 6:
      QPalette::setBrush(uVar2,0,9,uVar1);
      *(undefined1 *)(param_1 + 0x30) = 1;
      break;
    case 7:
      QPalette::setBrush(uVar2,1,9,uVar1);
      *(undefined1 *)(param_1 + 0x30) = 1;
      break;
    case 8:
      QPalette::setBrush(uVar2,2,9,uVar1);
      *(undefined1 *)(param_1 + 0x30) = 1;
      break;
    case 9:
      QPalette::setBrush(uVar2,0,0x10,uVar1);
      *(undefined1 *)(param_1 + 0x30) = 1;
      break;
    case 10:
      QPalette::setBrush(uVar2,1,0x10,uVar1);
      *(undefined1 *)(param_1 + 0x30) = 1;
      break;
    case 0xb:
      QPalette::setBrush(uVar2,2,0x10,uVar1);
      *(undefined1 *)(param_1 + 0x30) = 1;
      break;
    case 0xc:
      QPalette::setBrush(uVar2,0,0x12,uVar1);
      *(undefined1 *)(param_1 + 0x30) = 1;
      break;
    case 0xd:
      QPalette::setBrush(uVar2,1,0x12,uVar1);
      *(undefined1 *)(param_1 + 0x30) = 1;
      break;
    case 0xe:
      QPalette::setBrush(uVar2,2,0x12,uVar1);
      *(undefined1 *)(param_1 + 0x30) = 1;
      break;
    case 0xf:
      QPalette::setBrush(uVar2,0,0x13,uVar1);
      *(undefined1 *)(param_1 + 0x30) = 1;
      break;
    case 0x10:
      QPalette::setBrush(uVar2,1,0x13,uVar1);
      *(undefined1 *)(param_1 + 0x30) = 1;
      break;
    case 0x11:
      QPalette::setBrush(uVar2,2,0x13,uVar1);
      *(undefined1 *)(param_1 + 0x30) = 1;
      break;
    case 0x12:
      QPalette::setBrush(uVar2,0,0x14,uVar1);
      *(undefined1 *)(param_1 + 0x30) = 1;
      break;
    case 0x13:
      QPalette::setBrush(uVar2,1,0x14,uVar1);
      *(undefined1 *)(param_1 + 0x30) = 1;
      break;
    case 0x14:
      QPalette::setBrush(uVar2,2,0x14,uVar1);
      *(undefined1 *)(param_1 + 0x30) = 1;
      break;
    case 0x15:
      QPalette::setBrush(uVar2,0,6,uVar1);
      *(undefined1 *)(param_1 + 0x30) = 1;
      break;
    case 0x16:
      QPalette::setBrush(uVar2,1,6,uVar1);
      *(undefined1 *)(param_1 + 0x30) = 1;
      break;
    case 0x17:
      QPalette::setBrush(uVar2,2,6,uVar1);
      *(undefined1 *)(param_1 + 0x30) = 1;
      break;
    case 0x18:
      QPalette::setBrush(uVar2,0,1,uVar1);
      *(undefined1 *)(param_1 + 0x30) = 1;
      break;
    case 0x19:
      QPalette::setBrush(uVar2,1,1,uVar1);
      *(undefined1 *)(param_1 + 0x30) = 1;
      break;
    case 0x1a:
      QPalette::setBrush(uVar2,2,1,uVar1);
      *(undefined1 *)(param_1 + 0x30) = 1;
      break;
    case 0x1b:
      QPalette::setBrush(uVar2,0,8,uVar1);
      *(undefined1 *)(param_1 + 0x30) = 1;
      break;
    case 0x1c:
      QPalette::setBrush(uVar2,1,8,uVar1);
      *(undefined1 *)(param_1 + 0x30) = 1;
      break;
    case 0x1d:
      QPalette::setBrush(uVar2,2,8,uVar1);
      *(undefined1 *)(param_1 + 0x30) = 1;
      break;
    case 0x1e:
      QPalette::setBrush(uVar2,0,7,uVar1);
      *(undefined1 *)(param_1 + 0x30) = 1;
      break;
    case 0x1f:
      QPalette::setBrush(uVar2,1,7,uVar1);
      *(undefined1 *)(param_1 + 0x30) = 1;
      break;
    case 0x20:
      QPalette::setBrush(uVar2,2,7,uVar1);
      *(undefined1 *)(param_1 + 0x30) = 1;
      break;
    case 0x21:
      QPalette::setBrush(uVar2,0,2,uVar1);
      *(undefined1 *)(param_1 + 0x30) = 1;
      break;
    case 0x22:
      QPalette::setBrush(uVar2,1,2,uVar1);
      *(undefined1 *)(param_1 + 0x30) = 1;
      break;
    case 0x23:
      QPalette::setBrush(uVar2,2,2,uVar1);
      *(undefined1 *)(param_1 + 0x30) = 1;
      break;
    case 0x24:
      QPalette::setBrush(uVar2,0,3,uVar1);
      *(undefined1 *)(param_1 + 0x30) = 1;
      break;
    case 0x25:
      QPalette::setBrush(uVar2,1,3,uVar1);
      *(undefined1 *)(param_1 + 0x30) = 1;
      break;
    case 0x26:
      QPalette::setBrush(uVar2,2,3,uVar1);
      *(undefined1 *)(param_1 + 0x30) = 1;
      break;
    case 0x27:
      QPalette::setBrush(uVar2,0,4,uVar1);
      *(undefined1 *)(param_1 + 0x30) = 1;
      break;
    case 0x28:
      QPalette::setBrush(uVar2,1,4,uVar1);
      *(undefined1 *)(param_1 + 0x30) = 1;
      break;
    case 0x29:
      QPalette::setBrush(uVar2,2,4,uVar1);
      *(undefined1 *)(param_1 + 0x30) = 1;
      break;
    case 0x2a:
      QPalette::setBrush(uVar2,0,5,uVar1);
      *(undefined1 *)(param_1 + 0x30) = 1;
      break;
    case 0x2b:
      QPalette::setBrush(uVar2,1,5,uVar1);
      *(undefined1 *)(param_1 + 0x30) = 1;
      break;
    case 0x2c:
      QPalette::setBrush(uVar2,2,5,uVar1);
      *(undefined1 *)(param_1 + 0x30) = 1;
      break;
    case 0x2d:
      QPalette::setBrush(uVar2,0,0xb,uVar1);
      *(undefined1 *)(param_1 + 0x30) = 1;
      break;
    case 0x2e:
      QPalette::setBrush(uVar2,1,0xb,uVar1);
      *(undefined1 *)(param_1 + 0x30) = 1;
      break;
    case 0x2f:
      QPalette::setBrush(uVar2,2,0xb,uVar1);
      *(undefined1 *)(param_1 + 0x30) = 1;
      break;
    case 0x30:
      QPalette::setBrush(uVar2,0,0xc,uVar1);
      *(undefined1 *)(param_1 + 0x30) = 1;
      break;
    case 0x31:
      QPalette::setBrush(uVar2,1,0xc,uVar1);
      *(undefined1 *)(param_1 + 0x30) = 1;
      break;
    case 0x32:
      QPalette::setBrush(uVar2,2,0xc,uVar1);
      *(undefined1 *)(param_1 + 0x30) = 1;
      break;
    case 0x33:
      QPalette::setBrush(uVar2,0,0xd,uVar1);
      *(undefined1 *)(param_1 + 0x30) = 1;
      break;
    case 0x34:
      QPalette::setBrush(uVar2,1,0xd,uVar1);
      *(undefined1 *)(param_1 + 0x30) = 1;
      break;
    case 0x35:
      QPalette::setBrush(uVar2,2,0xd,uVar1);
      *(undefined1 *)(param_1 + 0x30) = 1;
      break;
    case 0x36:
      QPalette::setBrush(uVar2,0,0xe,uVar1);
      *(undefined1 *)(param_1 + 0x30) = 1;
      break;
    case 0x37:
      QPalette::setBrush(uVar2,1,0xe,uVar1);
      *(undefined1 *)(param_1 + 0x30) = 1;
      break;
    case 0x38:
      QPalette::setBrush(uVar2,2,0xe,uVar1);
      *(undefined1 *)(param_1 + 0x30) = 1;
      break;
    case 0x39:
      QPalette::setBrush(uVar2,0,0xf,uVar1);
      *(undefined1 *)(param_1 + 0x30) = 1;
      break;
    case 0x3a:
      QPalette::setBrush(uVar2,1,0xf,uVar1);
      *(undefined1 *)(param_1 + 0x30) = 1;
      break;
    case 0x3b:
      QPalette::setBrush(uVar2,2,0xf,uVar1);
      *(undefined1 *)(param_1 + 0x30) = 1;
    }
  }
  return;
}


// ==== entry=0090d1b2 orig=FUN_0090d1b2 size=24 name=ApplicationPalette_metaObject ====

undefined ** ApplicationPalette_metaObject(long param_1)

{
  undefined **ppuVar1;
  
  if (*(long *)(*(long *)(param_1 + 8) + 0x28) != 0) {
    ppuVar1 = (undefined **)QObjectData::dynamicMetaObject();
    return ppuVar1;
  }
  return &PTR_staticMetaObject_011a69a0;
}


// ==== entry=0090d1ca orig=FUN_0090d1ca size=66 name=ApplicationPalette_qt_metacast ====

char * ApplicationPalette_qt_metacast(char *param_1,char *param_2)

{
  int iVar1;
  char *pcVar2;
  
  if (param_2 == (char *)0x0) {
    return (char *)0x0;
  }
  iVar1 = strcmp(param_2,"ApplicationPalette");
  if (iVar1 == 0) {
    return param_1;
  }
  pcVar2 = (char *)QWidget::qt_metacast(param_1);
  return pcVar2;
}


// ==== entry=0090d20c orig=FUN_0090d20c size=120 name=ApplicationPalette_qt_metacall ====

ulong ApplicationPalette_qt_metacall
                (undefined8 param_1,int param_2,undefined8 param_3,undefined8 param_4)

{
  int iVar1;
  ulong uVar2;
  
  uVar2 = QWidget::qt_metacall();
  iVar1 = (int)uVar2;
  if (-1 < iVar1) {
    if ((param_2 - 1U < 3) || (param_2 == 0xb)) {
      FUN_0090bdc0(param_1,param_2,uVar2 & 0xffffffff,param_4);
      return (ulong)(iVar1 - 0x3c);
    }
    if ((((param_2 == 4) || (param_2 == 5)) || (param_2 == 6)) || ((param_2 == 7 || (param_2 == 8)))
       ) {
      return (ulong)(iVar1 - 0x3c);
    }
  }
  return uVar2;
}


// ==== entry=0090d284 orig=FUN_0090d284 size=77 name=ApplicationPalette_dtor ====

void ApplicationPalette_dtor(QWidget *param_1)

{
  QPalette *this;
  
  *(undefined ***)param_1 = &ApplicationPalette_vtable;
  *(undefined ***)(param_1 + 0x10) = &PTR_FUN_011a6948;
  this = *(QPalette **)(param_1 + 0x38);
  if (this != (QPalette *)0x0) {
    QPalette::~QPalette(this);
    operator_delete(this,0x10);
  }
  QWidget::~QWidget(param_1);
  return;
}


// ==== entry=0090d2d1 name=FUN_0090d2d1 size=78 ====

void FUN_0090d2d1(undefined8 *param_1)

{
  QPalette *this;
  
  param_1[-2] = &ApplicationPalette_vtable;
  *param_1 = &PTR_FUN_011a6948;
  this = (QPalette *)param_1[5];
  if (this != (QPalette *)0x0) {
    QPalette::~QPalette(this);
    operator_delete(this,0x10);
  }
  QWidget::~QWidget((QWidget *)(param_1 + -2));
  return;
}


// ==== entry=0090d320 name=FUN_0090d320 size=91 ====

void FUN_0090d320(undefined8 *param_1)

{
  QPalette *this;
  
  param_1[-2] = &ApplicationPalette_vtable;
  *param_1 = &PTR_FUN_011a6948;
  this = (QPalette *)param_1[5];
  if (this != (QPalette *)0x0) {
    QPalette::~QPalette(this);
    operator_delete(this,0x10);
  }
  QWidget::~QWidget((QWidget *)(param_1 + -2));
  operator_delete((QWidget *)(param_1 + -2),0x40);
  return;
}


// ==== entry=0090d37c orig=FUN_0090d37c size=90 name=ApplicationPalette_dtor_deleting ====

void ApplicationPalette_dtor_deleting(QWidget *param_1)

{
  QPalette *this;
  
  *(undefined ***)param_1 = &ApplicationPalette_vtable;
  *(undefined ***)(param_1 + 0x10) = &PTR_FUN_011a6948;
  this = *(QPalette **)(param_1 + 0x38);
  if (this != (QPalette *)0x0) {
    QPalette::~QPalette(this);
    operator_delete(this,0x10);
  }
  QWidget::~QWidget(param_1);
  operator_delete(param_1,0x40);
  return;
}


// ==== entry=0090d3e0 orig=FUN_0090d3e0 size=24 name=MainWindow_metaObject ====

undefined ** MainWindow_metaObject(long param_1)

{
  undefined **ppuVar1;
  
  if (*(long *)(*(long *)(param_1 + 8) + 0x28) != 0) {
    ppuVar1 = (undefined **)QObjectData::dynamicMetaObject();
    return ppuVar1;
  }
  return &PTR_staticMetaObject_011a6c00;
}


// ==== entry=0090d3f8 name=FUN_0090d3f8 size=52 ====

void FUN_0090d3f8(QObject *param_1,undefined1 param_2)

{
  undefined1 local_1c [4];
  void *local_18;
  undefined1 *local_10;
  
  local_18 = (void *)0x0;
  local_10 = local_1c;
  local_1c[0] = param_2;
  QMetaObject::activate(param_1,(QMetaObject *)&PTR_staticMetaObject_011a6c00,0,&local_18);
  return;
}


// ==== entry=0090d42c name=FUN_0090d42c size=2683 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0090d42c(long param_1,int param_2,int param_3,long *param_4)

{
  int *piVar1;
  QArrayData *pQVar2;
  undefined4 uVar3;
  char cVar4;
  undefined1 uVar5;
  int iVar6;
  int iVar7;
  char *pcVar8;
  size_t sVar9;
  undefined8 uVar10;
  undefined1 uVar11;
  uint uVar12;
  undefined8 *puVar13;
  QArrayData *local_48;
  undefined4 local_40;
  QArrayData *local_38;
  undefined4 local_30;
  
  if (param_2 != 0) {
    if (param_2 != 0xc) {
      if (param_2 == 10) {
        if (*(code **)param_4[1] != FUN_0090d3f8) {
          return;
        }
        if (((long *)param_4[1])[1] != 0) {
          return;
        }
        *(undefined4 *)*param_4 = 0;
        return;
      }
      if (param_2 == 1) {
        puVar13 = (undefined8 *)*param_4;
        switch(param_3) {
        case 0:
          uVar10 = FUN_0076712c();
          *puVar13 = uVar10;
          return;
        case 1:
          uVar10 = FUN_0076710a();
          *puVar13 = uVar10;
          return;
        case 2:
          uVar10 = FUN_007670b4();
          *puVar13 = uVar10;
          return;
        case 3:
          uVar10 = FUN_0076df66();
          *puVar13 = uVar10;
          return;
        case 4:
          uVar10 = FUN_0076dfb6();
          *puVar13 = uVar10;
          return;
        case 5:
          uVar10 = FUN_00767222();
          *puVar13 = uVar10;
          return;
        case 6:
          *(undefined1 *)puVar13 = *(undefined1 *)(param_1 + 0x30);
          return;
        case 7:
          uVar10 = FUN_007679ce();
          *puVar13 = uVar10;
          return;
        case 8:
          *(undefined1 *)puVar13 = *(undefined1 *)(param_1 + 0x31);
          return;
        case 9:
          uVar5 = QWidget::isFullScreen();
          *(undefined1 *)puVar13 = uVar5;
          return;
        case 10:
          uVar10 = FUN_007685b6();
          *puVar13 = uVar10;
          return;
        default:
          return;
        }
      }
      if (param_2 != 2) {
        return;
      }
      puVar13 = (undefined8 *)*param_4;
      if (param_3 == 6) {
        FUN_00766364(param_1,*(undefined1 *)puVar13);
        return;
      }
      if (param_3 < 7) {
        if (param_3 != 2) {
          return;
        }
        FUN_00768456(param_1,*puVar13);
        return;
      }
      if (param_3 == 8) {
        FUN_0076f4d6(param_1,*(undefined1 *)puVar13);
        return;
      }
      if (param_3 != 9) {
        return;
      }
      FUN_00766466(param_1,*(undefined1 *)puVar13);
      return;
    }
    piVar1 = (int *)*param_4;
    iVar7 = DAT_011c0b1c;
    iVar6 = DAT_011c18dc;
    switch(param_3) {
    case 7:
      if (*(int *)param_4[1] != 0) goto switchD_0090d5b1_caseD_9;
      if (DAT_011c0b1c != 0) goto LAB_0090d530;
      pcVar8 = (char *)QMetaObject::className();
      local_38 = (QArrayData *)&QArrayData::shared_null;
      sVar9 = strlen(pcVar8);
      uVar12 = (int)sVar9 + 1;
      if (((uint)QArrayData::shared_null < 2) && ((int)sVar9 + 2U <= (_files & 0x7fffffff))) {
        _files = _files | 0x80000000;
      }
      else {
        if (uVar12 <= *(uint *)(local_38 + 4)) {
          uVar12 = *(uint *)(local_38 + 4);
        }
                    /* try { // try from 0090d4cf to 0090d50f has its CatchHandler @ 0090ded7 */
        QByteArray::reallocData(&local_38,uVar12 + 1,1);
      }
      cVar4 = QByteArray::append((char *)&local_38);
      QByteArray::append(cVar4);
      iVar7 = QMetaType::registerNormalizedType
                        (&local_38,FUN_005441e4,FUN_005441e5,8,0x10c,&QWidget::staticMetaObject);
      goto LAB_0090d510;
    case 8:
      if (*(int *)param_4[1] != 0) goto switchD_0090d5b1_caseD_9;
      if (DAT_011c0b1c != 0) goto LAB_0090d530;
      pcVar8 = (char *)QMetaObject::className();
      local_38 = (QArrayData *)&QArrayData::shared_null;
      sVar9 = strlen(pcVar8);
      uVar12 = (int)sVar9 + 1;
      if (((uint)QArrayData::shared_null < 2) && ((int)sVar9 + 2U <= (_files & 0x7fffffff))) {
        _files = _files | 0x80000000;
      }
      else {
        if (uVar12 <= *(uint *)(local_38 + 4)) {
          uVar12 = *(uint *)(local_38 + 4);
        }
                    /* try { // try from 0090d794 to 0090d7d4 has its CatchHandler @ 0090deaf */
        QByteArray::reallocData(&local_38,uVar12 + 1,1);
      }
      cVar4 = QByteArray::append((char *)&local_38);
      QByteArray::append(cVar4);
      iVar7 = QMetaType::registerNormalizedType
                        (&local_38,FUN_005441e4,FUN_005441e5,8,0x10c,&QWidget::staticMetaObject);
LAB_0090d510:
      DAT_011c0b1c = iVar7;
      if (*(int *)local_38 != 0) {
        if (*(int *)local_38 == -1) goto LAB_0090d530;
        LOCK();
        *(int *)local_38 = *(int *)local_38 + -1;
        UNLOCK();
        if (*(int *)local_38 != 0) goto LAB_0090d530;
      }
      QArrayData::deallocate(local_38,1,8);
LAB_0090d530:
      *piVar1 = iVar7;
      return;
    default:
switchD_0090d5b1_caseD_9:
      *piVar1 = -1;
      return;
    case 0x18:
      if (*(int *)param_4[1] != 1) goto switchD_0090d5b1_caseD_9;
      if (DAT_011c18dc != 0) goto LAB_0090d668;
      QMetaObject::normalizedType((char *)&local_38);
                    /* try { // try from 0090d719 to 0090d71d has its CatchHandler @ 0090decf */
      iVar6 = QMetaType::registerNormalizedType
                        (&local_38,QJSValue::~QJSValue,FUN_0066b36f,8,0x103,0);
      break;
    case 0x1c:
      if (*(int *)param_4[1] != 1) goto switchD_0090d5b1_caseD_9;
      if (DAT_011c18dc != 0) goto LAB_0090d668;
      QMetaObject::normalizedType((char *)&local_38);
                    /* try { // try from 0090d6c0 to 0090d6c4 has its CatchHandler @ 0090dec7 */
      iVar6 = QMetaType::registerNormalizedType
                        (&local_38,QJSValue::~QJSValue,FUN_0066b36f,8,0x103,0);
      break;
    case 0x1d:
      if (*(int *)param_4[1] != 1) goto switchD_0090d5b1_caseD_9;
      if (DAT_011c18dc != 0) goto LAB_0090d668;
      QMetaObject::normalizedType((char *)&local_38);
                    /* try { // try from 0090d63f to 0090d643 has its CatchHandler @ 0090deb7 */
      iVar6 = QMetaType::registerNormalizedType
                        (&local_38,QJSValue::~QJSValue,FUN_0066b36f,8,0x103,0);
    }
    if (*(int *)local_38 != 0) {
      if (*(int *)local_38 == -1) goto LAB_0090d668;
      LOCK();
      *(int *)local_38 = *(int *)local_38 + -1;
      UNLOCK();
      if (*(int *)local_38 != 0) goto LAB_0090d668;
    }
    QArrayData::deallocate(local_38,1,8);
LAB_0090d668:
    DAT_011c18dc = iVar6;
    *piVar1 = DAT_011c18dc;
    return;
  }
  switch(param_3) {
  case 0:
    FUN_0090d3f8(param_1,*(undefined1 *)param_4[1]);
    break;
  case 1:
    uVar10 = FUN_0076ddbe(param_1,*(undefined4 *)param_4[1]);
    puVar13 = (undefined8 *)*param_4;
    goto joined_r0x0090da0d;
  case 2:
    uVar10 = FUN_0076ddbe(param_1,0);
    puVar13 = (undefined8 *)*param_4;
joined_r0x0090da0d:
    if (puVar13 != (undefined8 *)0x0) {
LAB_0090d8f0:
      *puVar13 = uVar10;
    }
    break;
  case 3:
    FUN_0076734a(&local_48,param_1);
    puVar13 = (undefined8 *)*param_4;
    pQVar2 = local_48;
    uVar3 = local_40;
    goto joined_r0x0090d7f4;
  case 4:
    FUN_007673fa(&local_38,param_1);
    puVar13 = (undefined8 *)*param_4;
    goto joined_r0x0090db3c;
  case 5:
    FUN_0076c1fa(param_1,param_4[1]);
    break;
  case 6:
    FUN_0076750e((QIcon *)&local_38,param_1,param_4[1]);
    puVar13 = (undefined8 *)*param_4;
    if (puVar13 != (undefined8 *)0x0) {
      pQVar2 = (QArrayData *)*puVar13;
      *puVar13 = local_38;
      local_38 = pQVar2;
    }
    QIcon::~QIcon((QIcon *)&local_38);
    break;
  case 7:
    uVar10 = FUN_00767580(param_1,*(undefined8 *)param_4[1],param_4[2]);
    puVar13 = (undefined8 *)*param_4;
    goto joined_r0x0090da56;
  case 8:
    local_38 = (QArrayData *)&QArrayData::shared_null;
                    /* try { // try from 0090d913 to 0090d917 has its CatchHandler @ 0090dea7 */
    uVar10 = FUN_00767580(param_1,*(undefined8 *)param_4[1],&local_38);
    goto LAB_0090d918;
  case 9:
    local_38 = (QArrayData *)&QArrayData::shared_null;
                    /* try { // try from 0090d963 to 0090d967 has its CatchHandler @ 0090deef */
    uVar10 = FUN_00767580(param_1,0,&local_38);
LAB_0090d918:
    if (*(int *)local_38 == 0) {
LAB_0090ddda:
      QArrayData::deallocate(local_38,2,8);
    }
    else if (*(int *)local_38 != -1) {
      LOCK();
      *(int *)local_38 = *(int *)local_38 + -1;
      UNLOCK();
      if (*(int *)local_38 == 0) goto LAB_0090ddda;
    }
    if ((undefined8 *)*param_4 != (undefined8 *)0x0) {
      *(undefined8 *)*param_4 = uVar10;
    }
    break;
  case 10:
    uVar5 = *(undefined1 *)param_4[2];
    uVar11 = *(undefined1 *)param_4[1];
    goto LAB_0090d97d;
  case 0xb:
    uVar11 = *(undefined1 *)param_4[1];
    uVar5 = 0;
    goto LAB_0090d97d;
  case 0xc:
    uVar5 = 0;
    uVar11 = 0;
LAB_0090d97d:
    FUN_00767a58(&local_48,param_1,uVar11,uVar5);
    pQVar2 = local_48;
    puVar13 = (undefined8 *)*param_4;
    if (puVar13 != (undefined8 *)0x0) {
      local_48 = (QArrayData *)&QListData::shared_null;
      local_38 = (QArrayData *)*puVar13;
      *puVar13 = pQVar2;
      FUN_00525060(&local_38);
    }
    FUN_00525060(&local_48);
    break;
  case 0xd:
    uVar10 = FUN_00767b36(param_1,param_4[1]);
    puVar13 = (undefined8 *)*param_4;
joined_r0x0090da56:
    if (puVar13 == (undefined8 *)0x0) {
      return;
    }
    goto LAB_0090d8f0;
  case 0xe:
    uVar5 = FUN_0076a986(param_1,*(undefined8 *)param_4[1]);
    if ((undefined1 *)*param_4 != (undefined1 *)0x0) {
      *(undefined1 *)*param_4 = uVar5;
    }
    break;
  case 0xf:
    local_38 = *(QArrayData **)param_4[1];
    if ((*(int *)local_38 != 0) && (*(int *)local_38 != -1)) {
      LOCK();
      *(int *)local_38 = *(int *)local_38 + 1;
      UNLOCK();
    }
                    /* try { // try from 0090daa3 to 0090daa7 has its CatchHandler @ 0090dedf */
    uVar5 = FUN_0076e6aa(param_1,&local_38);
    if (*(int *)local_38 == 0) {
LAB_0090de0d:
      QArrayData::deallocate(local_38,2,8);
    }
    else if (*(int *)local_38 != -1) {
      LOCK();
      *(int *)local_38 = *(int *)local_38 + -1;
      UNLOCK();
      if (*(int *)local_38 == 0) goto LAB_0090de0d;
    }
    if ((undefined1 *)*param_4 != (undefined1 *)0x0) {
      *(undefined1 *)*param_4 = uVar5;
    }
    break;
  case 0x10:
    uVar5 = FUN_00767c5e(param_1,param_4[1]);
    if ((undefined1 *)*param_4 != (undefined1 *)0x0) {
      *(undefined1 *)*param_4 = uVar5;
    }
    break;
  case 0x11:
    FUN_00768a48(param_1,*(undefined1 *)param_4[1]);
    break;
  case 0x12:
    FUN_00768a48(param_1,1);
    break;
  case 0x13:
    FUN_00768dfa(param_1,param_4[1]);
    break;
  case 0x14:
    local_38 = (QArrayData *)&QArrayData::shared_null;
                    /* try { // try from 0090dba2 to 0090dba6 has its CatchHandler @ 0090debf */
    FUN_00768dfa(param_1,&local_38);
    if (*(int *)local_38 != 0) {
      if (*(int *)local_38 == -1) {
        return;
      }
      LOCK();
      *(int *)local_38 = *(int *)local_38 + -1;
      UNLOCK();
      if (*(int *)local_38 != 0) {
        return;
      }
    }
    QArrayData::deallocate(local_38,2,8);
    break;
  case 0x15:
    FUN_007682a6();
    break;
  case 0x16:
    FUN_0076802e(&local_48,param_1,param_4[1],param_4[2]);
    puVar13 = (undefined8 *)*param_4;
    pQVar2 = local_48;
    uVar3 = local_40;
    goto joined_r0x0090d7f4;
  case 0x17:
    local_38 = (QArrayData *)0x0;
    local_30 = 0x80000000;
                    /* try { // try from 0090dc39 to 0090dc3d has its CatchHandler @ 0090dee7 */
    FUN_0076802e(&local_48,param_1,param_4[1],(QVariant *)&local_38);
    QVariant::~QVariant((QVariant *)&local_38);
    puVar13 = (undefined8 *)*param_4;
    pQVar2 = local_48;
    uVar3 = local_40;
    goto joined_r0x0090d7f4;
  case 0x18:
    FUN_007682c0(&local_48,param_1,param_4[1],param_4[2]);
    puVar13 = (undefined8 *)*param_4;
    pQVar2 = local_48;
    uVar3 = local_40;
    goto joined_r0x0090d7f4;
  case 0x19:
    FUN_00768350(&local_38,param_1);
    puVar13 = (undefined8 *)*param_4;
    goto joined_r0x0090db3c;
  case 0x1a:
    uVar5 = FUN_0076846e(param_1,param_4[1]);
    if ((undefined1 *)*param_4 != (undefined1 *)0x0) {
      *(undefined1 *)*param_4 = uVar5;
    }
    break;
  case 0x1b:
    uVar5 = FUN_00768488(param_1,param_4[1],param_4[2]);
    if ((undefined1 *)*param_4 != (undefined1 *)0x0) {
      *(undefined1 *)*param_4 = uVar5;
    }
    break;
  case 0x1c:
    FUN_007684f4(&local_38,param_1,*(undefined8 *)param_4[1],param_4[2],*(undefined4 *)param_4[3]);
    puVar13 = (undefined8 *)*param_4;
    goto joined_r0x0090db3c;
  case 0x1d:
    FUN_00768554(&local_38,param_1,*(undefined8 *)param_4[1],param_4[2],*(undefined4 *)param_4[3]);
    puVar13 = (undefined8 *)*param_4;
joined_r0x0090db3c:
    if (puVar13 != (undefined8 *)0x0) {
      pQVar2 = (QArrayData *)*puVar13;
      *puVar13 = local_38;
      local_38 = pQVar2;
    }
    if (*(int *)local_38 != 0) {
      if (*(int *)local_38 == -1) {
        return;
      }
      LOCK();
      *(int *)local_38 = *(int *)local_38 + -1;
      UNLOCK();
      if (*(int *)local_38 != 0) {
        return;
      }
    }
    QArrayData::deallocate(local_38,2,8);
    break;
  case 0x1e:
    uVar5 = FUN_00768640(param_1,param_4[1]);
    if ((undefined1 *)*param_4 != (undefined1 *)0x0) {
      *(undefined1 *)*param_4 = uVar5;
    }
    break;
  case 0x1f:
    uVar5 = FUN_0076ada4(param_1,param_4[1],param_4[2]);
    if ((undefined1 *)*param_4 != (undefined1 *)0x0) {
      *(undefined1 *)*param_4 = uVar5;
    }
    break;
  case 0x20:
    FUN_00768724(param_1,param_4[1]);
    break;
  case 0x21:
    FUN_0076b47c(&local_48,param_1,param_4[1]);
    puVar13 = (undefined8 *)*param_4;
    pQVar2 = local_48;
    uVar3 = local_40;
joined_r0x0090d7f4:
    local_48 = pQVar2;
    local_40 = uVar3;
    if (puVar13 != (undefined8 *)0x0) {
      local_48 = (QArrayData *)*puVar13;
      local_40 = *(undefined4 *)(puVar13 + 1);
      *puVar13 = pQVar2;
      *(undefined4 *)(puVar13 + 1) = uVar3;
      local_38 = local_48;
      local_30 = local_40;
    }
    QVariant::~QVariant((QVariant *)&local_48);
  }
  return;
}


// ==== entry=0090def8 orig=FUN_0090def8 size=66 name=MainWindow_qt_metacast ====

char * MainWindow_qt_metacast(char *param_1,char *param_2)

{
  int iVar1;
  char *pcVar2;
  
  if (param_2 == (char *)0x0) {
    return (char *)0x0;
  }
  iVar1 = strcmp(param_2,"MainWindow");
  if (iVar1 == 0) {
    return param_1;
  }
  pcVar2 = (char *)QMainWindow::qt_metacast(param_1);
  return pcVar2;
}


// ==== entry=0090df3a orig=FUN_0090df3a size=194 name=MainWindow_qt_metacall ====

ulong MainWindow_qt_metacall(undefined8 param_1,int param_2,undefined8 param_3,undefined8 param_4)

{
  int iVar1;
  ulong uVar2;
  
  uVar2 = QMainWindow::qt_metacall();
  iVar1 = (int)uVar2;
  if (-1 < iVar1) {
    if (param_2 == 0) {
      if (iVar1 < 0x22) {
        FUN_0090d42c(param_1,0,uVar2 & 0xffffffff,param_4);
        uVar2 = uVar2 & 0xffffffff;
      }
    }
    else {
      if (param_2 != 0xc) {
        if ((param_2 - 1U < 3) || (param_2 == 0xb)) {
          FUN_0090d42c(param_1,param_2,uVar2 & 0xffffffff,param_4);
          return (ulong)(iVar1 - 0xb);
        }
        if ((((param_2 != 4) && (param_2 != 5)) && (param_2 != 6)) &&
           ((param_2 != 7 && (param_2 != 8)))) {
          return uVar2;
        }
        return (ulong)(iVar1 - 0xb);
      }
      if (iVar1 < 0x22) {
        FUN_0090d42c(param_1,0xc,uVar2 & 0xffffffff,param_4);
        uVar2 = uVar2 & 0xffffffff;
      }
    }
    uVar2 = (ulong)((int)uVar2 - 0x22);
  }
  return uVar2;
}


// ==== entry=0090e000 orig=FUN_0090e000 size=24 name=SuperApplication_metaObject ====

undefined ** SuperApplication_metaObject(long param_1)

{
  undefined **ppuVar1;
  
  if (*(long *)(*(long *)(param_1 + 8) + 0x28) != 0) {
    ppuVar1 = (undefined **)QObjectData::dynamicMetaObject();
    return ppuVar1;
  }
  return &PTR_staticMetaObject_011a6ce0;
}


// ==== entry=0090e018 name=FUN_0090e018 size=52 ====

void FUN_0090e018(QObject *param_1,undefined8 param_2)

{
  undefined8 local_20;
  void *local_18;
  undefined8 *local_10;
  
  local_18 = (void *)0x0;
  local_10 = &local_20;
  local_20 = param_2;
  QMetaObject::activate(param_1,(QMetaObject *)&PTR_staticMetaObject_011a6ce0,0,&local_18);
  return;
}


// ==== entry=0090e04c name=FUN_0090e04c size=55 ====

void FUN_0090e04c(QObject *param_1,undefined8 param_2)

{
  undefined8 local_20;
  void *local_18;
  undefined8 *local_10;
  
  local_18 = (void *)0x0;
  local_10 = &local_20;
  local_20 = param_2;
  QMetaObject::activate(param_1,(QMetaObject *)&PTR_staticMetaObject_011a6ce0,1,&local_18);
  return;
}


// ==== entry=0090e084 name=FUN_0090e084 size=47 ====

void FUN_0090e084(QObject *param_1,undefined8 param_2,undefined8 param_3)

{
  void *local_28;
  undefined8 local_20;
  undefined8 local_18;
  
  local_28 = (void *)0x0;
  local_20 = param_2;
  local_18 = param_3;
  QMetaObject::activate(param_1,(QMetaObject *)&PTR_staticMetaObject_011a6ce0,2,&local_28);
  return;
}


// ==== entry=0090e0b4 name=FUN_0090e0b4 size=1425 ====

void FUN_0090e0b4(long param_1,int param_2,undefined4 param_3,long *param_4)

{
  undefined4 *puVar1;
  long *plVar2;
  code *pcVar3;
  long lVar4;
  long lVar5;
  undefined8 *puVar6;
  QMapNodeBase *pQVar7;
  undefined1 uVar8;
  undefined8 uVar9;
  QArrayData *pQVar10;
  QMapNodeBase *local_28;
  QArrayData *local_20;
  
  if (param_2 != 0) {
    if (param_2 == 10) {
      puVar1 = (undefined4 *)*param_4;
      plVar2 = (long *)param_4[1];
      pcVar3 = (code *)*plVar2;
      if (pcVar3 == FUN_0090e018) {
        if (plVar2[1] == 0) {
          *puVar1 = 0;
          return;
        }
      }
      else if ((pcVar3 == FUN_0090e04c) && (plVar2[1] == 0)) {
        *puVar1 = 1;
        return;
      }
      if ((pcVar3 == FUN_0090e084) && (plVar2[1] == 0)) {
        *puVar1 = 2;
        return;
      }
    }
switchD_0090e0d5_default:
    return;
  }
  switch(param_3) {
  case 0:
    FUN_0090e018(param_1,*(undefined8 *)param_4[1]);
    break;
  case 1:
    FUN_0090e04c(param_1,*(undefined8 *)param_4[1]);
    break;
  case 2:
    FUN_0090e084(param_1,param_4[1],param_4[2]);
    break;
  case 3:
    FUN_007609d2();
    break;
  case 4:
    uVar9 = FUN_0075c0be();
    puVar6 = (undefined8 *)*param_4;
    goto joined_r0x0090e19a;
  case 5:
    uVar9 = FUN_0075e3fe();
    puVar6 = (undefined8 *)*param_4;
joined_r0x0090e19a:
    if (puVar6 != (undefined8 *)0x0) {
      *puVar6 = uVar9;
    }
    break;
  case 6:
    FUN_0075dc3a(&local_28,param_1);
    pQVar7 = local_28;
    puVar6 = (undefined8 *)*param_4;
    if (puVar6 != (undefined8 *)0x0) {
      local_28 = (QMapNodeBase *)&QListData::shared_null;
      local_20 = (QArrayData *)*puVar6;
      *puVar6 = pQVar7;
      FUN_0069eab0(&local_20);
    }
    FUN_0069eab0(&local_28);
    break;
  case 7:
    FUN_00760ffe(param_1,param_4[1]);
    break;
  case 8:
    FUN_0075c6a0(&local_20,param_1);
    puVar6 = (undefined8 *)*param_4;
    if (puVar6 != (undefined8 *)0x0) {
      pQVar10 = (QArrayData *)*puVar6;
      *puVar6 = local_20;
      local_20 = pQVar10;
    }
    if (*(int *)local_20 != 0) {
      if (*(int *)local_20 == -1) {
        return;
      }
      LOCK();
      *(int *)local_20 = *(int *)local_20 + -1;
      UNLOCK();
      if (*(int *)local_20 != 0) {
        return;
      }
    }
    QArrayData::deallocate(local_20,2,8);
    break;
  case 9:
    FUN_0075db80(&local_28,param_1);
    puVar6 = (undefined8 *)*param_4;
    pQVar7 = local_28;
    goto joined_r0x0090e4e3;
  case 10:
    FUN_0075c278(param_1,param_4[1],*(undefined4 *)param_4[2]);
    break;
  case 0xb:
    FUN_0075c278(param_1,param_4[1],0);
    break;
  case 0xc:
    FUN_0075cfcc();
    break;
  case 0xd:
    if ((undefined1 *)*param_4 != (undefined1 *)0x0) {
      *(undefined1 *)*param_4 = *(undefined1 *)(param_1 + 0x10);
    }
    break;
  case 0xe:
    uVar8 = FUN_0075d0a4(param_1,*(undefined4 *)param_4[1]);
    if ((undefined1 *)*param_4 != (undefined1 *)0x0) {
      *(undefined1 *)*param_4 = uVar8;
    }
    break;
  case 0xf:
    FUN_0075d108();
    break;
  case 0x10:
    FUN_0075d3f8(param_1,param_4[1],param_4[2]);
    break;
  case 0x11:
    uVar8 = *(undefined1 *)param_4[2];
    local_20 = *(QArrayData **)param_4[1];
    if ((*(int *)local_20 != 0) && (*(int *)local_20 != -1)) {
      LOCK();
      *(int *)local_20 = *(int *)local_20 + 1;
      UNLOCK();
    }
                    /* try { // try from 0090e311 to 0090e315 has its CatchHandler @ 0090e645 */
    s_ShowFolders_75d22e(param_1,&local_20,uVar8);
    if (*(int *)local_20 != 0) {
      if (*(int *)local_20 == -1) {
        return;
      }
      LOCK();
      *(int *)local_20 = *(int *)local_20 + -1;
      UNLOCK();
      if (*(int *)local_20 != 0) {
        return;
      }
    }
    QArrayData::deallocate(local_20,2,8);
    break;
  case 0x12:
    FUN_0075d506(param_1,param_4[1]);
    break;
  case 0x13:
    FUN_0075d6c0(param_1,param_4[1]);
    break;
  case 0x14:
    FUN_0075d6d0(&local_28,param_1,param_4[1]);
    pQVar7 = local_28;
    puVar6 = (undefined8 *)*param_4;
    if (puVar6 != (undefined8 *)0x0) {
      local_28 = (QMapNodeBase *)&QMapDataBase::shared_null;
      local_20 = (QArrayData *)*puVar6;
      *puVar6 = pQVar7;
      FUN_00528c1c(&local_20);
    }
    pQVar7 = local_28;
    if (*(int *)local_28 != 0) {
      if (*(int *)local_28 == -1) {
        return;
      }
      LOCK();
      *(int *)local_28 = *(int *)local_28 + -1;
      UNLOCK();
      if (*(int *)local_28 != 0) {
        return;
      }
    }
    lVar4 = *(long *)(local_28 + 0x10);
    if (lVar4 != 0) {
      pQVar10 = *(QArrayData **)(lVar4 + 0x18);
      if (*(int *)pQVar10 == 0) {
LAB_0090e600:
        QArrayData::deallocate(pQVar10,2,8);
      }
      else if (*(int *)pQVar10 != -1) {
        LOCK();
        *(int *)pQVar10 = *(int *)pQVar10 + -1;
        UNLOCK();
        if (*(int *)pQVar10 == 0) {
          pQVar10 = *(QArrayData **)(lVar4 + 0x18);
          goto LAB_0090e600;
        }
      }
      QVariant::~QVariant((QVariant *)(lVar4 + 0x20));
      lVar5 = *(long *)(lVar4 + 8);
      if (lVar5 != 0) {
        pQVar10 = *(QArrayData **)(lVar5 + 0x18);
        if (*(int *)pQVar10 == 0) {
LAB_0090e631:
          QArrayData::deallocate(pQVar10,2,8);
        }
        else if (*(int *)pQVar10 != -1) {
          LOCK();
          *(int *)pQVar10 = *(int *)pQVar10 + -1;
          UNLOCK();
          if (*(int *)pQVar10 == 0) {
            pQVar10 = *(QArrayData **)(lVar5 + 0x18);
            goto LAB_0090e631;
          }
        }
        QVariant::~QVariant((QVariant *)(lVar5 + 0x20));
        if (*(long *)(lVar5 + 8) != 0) {
          FUN_00528bb6();
        }
        if (*(long *)(lVar5 + 0x10) != 0) {
          FUN_00528bb6();
        }
      }
      lVar4 = *(long *)(lVar4 + 0x10);
      if (lVar4 != 0) {
        pQVar10 = *(QArrayData **)(lVar4 + 0x18);
        if (*(int *)pQVar10 == 0) {
LAB_0090e618:
          QArrayData::deallocate(pQVar10,2,8);
        }
        else if (*(int *)pQVar10 != -1) {
          LOCK();
          *(int *)pQVar10 = *(int *)pQVar10 + -1;
          UNLOCK();
          if (*(int *)pQVar10 == 0) {
            pQVar10 = *(QArrayData **)(lVar4 + 0x18);
            goto LAB_0090e618;
          }
        }
        QVariant::~QVariant((QVariant *)(lVar4 + 0x20));
        if (*(long *)(lVar4 + 8) != 0) {
          FUN_00528bb6();
        }
        if (*(long *)(lVar4 + 0x10) != 0) {
          FUN_00528bb6();
        }
      }
      QMapDataBase::freeTree(pQVar7,(int)*(undefined8 *)(pQVar7 + 0x10));
    }
    QMapDataBase::freeData((QMapDataBase *)pQVar7);
    break;
  case 0x15:
    s_application_searchEngines_75dc4c(&local_28,param_1);
    puVar6 = (undefined8 *)*param_4;
    pQVar7 = local_28;
joined_r0x0090e4e3:
    local_28 = pQVar7;
    if (puVar6 != (undefined8 *)0x0) {
      local_28 = (QMapNodeBase *)&QListData::shared_null;
      local_20 = (QArrayData *)*puVar6;
      *puVar6 = pQVar7;
      FUN_00525060(&local_20);
    }
    FUN_00525060(&local_28);
    break;
  case 0x16:
    s_application_searchEngines_75e56a(param_1,param_4[1],param_4[2]);
    break;
  case 0x17:
    FUN_0075debe(param_1,param_4[1]);
    break;
  case 0x18:
    FUN_0075d732(param_1,*(undefined4 *)param_4[1],*(undefined1 *)param_4[2]);
    break;
  case 0x19:
    FUN_0075d73c(param_1,*(undefined8 *)param_4[1]);
    break;
  case 0x1a:
    FUN_0075d78c(param_1,param_4[1],param_4[2]);
    break;
  case 0x1b:
    s_application_windowOpacity_75d79c(*(undefined8 *)param_4[1],param_1,*(undefined1 *)param_4[2]);
    break;
  case 0x1c:
    s_application_windowOpacity_75d79c(*(undefined8 *)param_4[1],param_1,1);
    break;
  case 0x1d:
    s_application_windowOpacity_75d79c(0,param_1,1);
    break;
  case 0x1e:
    FUN_0075d956();
    break;
  default:
    goto switchD_0090e0d5_default;
  }
  return;
}


// ==== entry=0090e64e orig=FUN_0090e64e size=66 name=SuperApplication_qt_metacast ====

char * SuperApplication_qt_metacast(char *param_1,char *param_2)

{
  int iVar1;
  char *pcVar2;
  
  if (param_2 == (char *)0x0) {
    return (char *)0x0;
  }
  iVar1 = strcmp(param_2,"SuperApplication");
  if (iVar1 == 0) {
    return param_1;
  }
  pcVar2 = (char *)QApplication::qt_metacast(param_1);
  return pcVar2;
}


// ==== entry=0090e690 orig=FUN_0090e690 size=93 name=SuperApplication_qt_metacall ====

ulong SuperApplication_qt_metacall
                (undefined8 param_1,int param_2,undefined8 param_3,undefined8 *param_4)

{
  int iVar1;
  ulong uVar2;
  
  uVar2 = QApplication::qt_metacall();
  iVar1 = (int)uVar2;
  if (-1 < iVar1) {
    if (param_2 == 0) {
      if (iVar1 < 0x1f) {
        FUN_0090e0b4(param_1,0,uVar2 & 0xffffffff,param_4);
        uVar2 = uVar2 & 0xffffffff;
      }
    }
    else {
      if (param_2 != 0xc) {
        return uVar2;
      }
      if (iVar1 < 0x1f) {
        *(undefined4 *)*param_4 = 0xffffffff;
      }
    }
    uVar2 = (ulong)((int)uVar2 - 0x1f);
  }
  return uVar2;
}


// ==== entry=0090e6f0 orig=FUN_0090e6f0 size=24 name=CommanderRobot_metaObject ====

undefined ** CommanderRobot_metaObject(long param_1)

{
  undefined **ppuVar1;
  
  if (*(long *)(*(long *)(param_1 + 8) + 0x28) != 0) {
    ppuVar1 = (undefined **)QObjectData::dynamicMetaObject();
    return ppuVar1;
  }
  return &PTR_staticMetaObject_011a6da0;
}


// ==== entry=0090e708 name=FUN_0090e708 size=61 ====

void FUN_0090e708(QObject *param_1,undefined4 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined4 local_2c;
  void *local_28;
  undefined4 *local_20;
  undefined8 local_18;
  undefined8 local_10;
  
  local_28 = (void *)0x0;
  local_20 = &local_2c;
  local_2c = param_2;
  local_18 = param_3;
  local_10 = param_4;
  QMetaObject::activate(param_1,(QMetaObject *)&PTR_staticMetaObject_011a6da0,0,&local_28);
  return;
}


// ==== entry=0090e746 name=FUN_0090e746 size=69 ====

void FUN_0090e746(undefined8 param_1,int param_2,int param_3,undefined8 *param_4)

{
  if (param_2 == 0) {
    if (param_3 == 0) {
      FUN_0090e708(param_1,*(undefined4 *)param_4[1],param_4[2],param_4[3]);
      return;
    }
  }
  else if (((param_2 == 10) && (*(code **)param_4[1] == FUN_0090e708)) &&
          (((long *)param_4[1])[1] == 0)) {
    *(undefined4 *)*param_4 = 0;
    return;
  }
  return;
}


// ==== entry=0090e78c orig=FUN_0090e78c size=66 name=CommanderRobot_qt_metacast ====

char * CommanderRobot_qt_metacast(char *param_1,char *param_2)

{
  int iVar1;
  char *pcVar2;
  
  if (param_2 == (char *)0x0) {
    return (char *)0x0;
  }
  iVar1 = strcmp(param_2,"CommanderRobot");
  if (iVar1 == 0) {
    return param_1;
  }
  pcVar2 = (char *)QObject::qt_metacast(param_1);
  return pcVar2;
}


// ==== entry=0090e7ce orig=FUN_0090e7ce size=101 name=CommanderRobot_qt_metacall ====

ulong CommanderRobot_qt_metacall
                (undefined8 param_1,int param_2,undefined8 param_3,undefined8 *param_4)

{
  int iVar1;
  ulong uVar2;
  
  uVar2 = QObject::qt_metacall();
  iVar1 = (int)uVar2;
  if (-1 < iVar1) {
    if (param_2 == 0) {
      if (iVar1 == 0) {
        FUN_0090e708(param_1,*(undefined4 *)param_4[1],param_4[2],param_4[3]);
        uVar2 = uVar2 & 0xffffffff;
      }
    }
    else {
      if (param_2 != 0xc) {
        return uVar2;
      }
      if (iVar1 == 0) {
        *(undefined4 *)*param_4 = 0xffffffff;
      }
    }
    uVar2 = (ulong)((int)uVar2 - 1);
  }
  return uVar2;
}


// ==== entry=0090e834 orig=FUN_0090e834 size=19 name=CommanderRobot_dtor ====

void CommanderRobot_dtor(QObject *param_1)

{
  *(undefined ***)param_1 = &CommanderRobot_vtable;
  QObject::~QObject(param_1);
  return;
}


// ==== entry=0090e848 orig=FUN_0090e848 size=37 name=CommanderRobot_dtor_deleting ====

void CommanderRobot_dtor_deleting(QObject *param_1)

{
  *(undefined ***)param_1 = &CommanderRobot_vtable;
  QObject::~QObject(param_1);
  operator_delete(param_1,0x18);
  return;
}


// ==== entry=0090e870 name=FUN_0090e870 size=24 ====

undefined ** FUN_0090e870(long param_1)

{
  undefined **ppuVar1;
  
  if (*(long *)(*(long *)(param_1 + 8) + 0x28) != 0) {
    ppuVar1 = (undefined **)QObjectData::dynamicMetaObject();
    return ppuVar1;
  }
  return &PTR_staticMetaObject_011a6e80;
}


// ==== entry=0090e888 name=FUN_0090e888 size=52 ====

void FUN_0090e888(QObject *param_1,undefined1 param_2)

{
  undefined1 local_1c [4];
  void *local_18;
  undefined1 *local_10;
  
  local_18 = (void *)0x0;
  local_10 = local_1c;
  local_1c[0] = param_2;
  QMetaObject::activate(param_1,(QMetaObject *)&PTR_staticMetaObject_011a6e80,0,&local_18);
  return;
}


// ==== entry=0090e8bc name=FUN_0090e8bc size=42 ====

void FUN_0090e8bc(QObject *param_1,undefined8 param_2)

{
  void *local_18;
  undefined8 local_10;
  
  local_18 = (void *)0x0;
  local_10 = param_2;
  QMetaObject::activate(param_1,(QMetaObject *)&PTR_staticMetaObject_011a6e80,1,&local_18);
  return;
}


// ==== entry=0090e8e6 name=FUN_0090e8e6 size=42 ====

void FUN_0090e8e6(QObject *param_1,undefined8 param_2)

{
  void *local_18;
  undefined8 local_10;
  
  local_18 = (void *)0x0;
  local_10 = param_2;
  QMetaObject::activate(param_1,(QMetaObject *)&PTR_staticMetaObject_011a6e80,2,&local_18);
  return;
}


// ==== entry=0090e910 name=FUN_0090e910 size=133 ====

void FUN_0090e910(undefined8 param_1,int param_2,int param_3,undefined8 *param_4)

{
  undefined4 *puVar1;
  long *plVar2;
  code *pcVar3;
  
  if (param_2 == 0) {
    if (param_3 == 1) {
      FUN_0090e8bc(param_1,param_4[1]);
      return;
    }
    if (param_3 == 2) {
      FUN_0090e8e6(param_1,param_4[1]);
      return;
    }
    if (param_3 == 0) {
      FUN_0090e888(param_1,*(undefined1 *)param_4[1]);
      return;
    }
  }
  else if (param_2 == 10) {
    puVar1 = (undefined4 *)*param_4;
    plVar2 = (long *)param_4[1];
    pcVar3 = (code *)*plVar2;
    if ((pcVar3 == FUN_0090e888) && (plVar2[1] == 0)) {
      *puVar1 = 0;
      return;
    }
    if ((pcVar3 == FUN_0090e8bc) && (plVar2[1] == 0)) {
      *puVar1 = 1;
      return;
    }
    if ((pcVar3 == FUN_0090e8e6) && (plVar2[1] == 0)) {
      *puVar1 = 2;
      return;
    }
  }
  return;
}


// ==== entry=0090e996 orig=FUN_0090e996 size=66 name=Modem_dtor ====

char * Modem_dtor(char *param_1,char *param_2)

{
  int iVar1;
  char *pcVar2;
  
  if (param_2 == (char *)0x0) {
    return (char *)0x0;
  }
  iVar1 = strcmp(param_2,"Modem");
  if (iVar1 == 0) {
    return param_1;
  }
  pcVar2 = (char *)QObject::qt_metacast(param_1);
  return pcVar2;
}


// ==== entry=0090e9d8 orig=FUN_0090e9d8 size=93 name=Modem_dtor_deleting ====

ulong Modem_dtor_deleting(undefined8 param_1,int param_2,undefined8 param_3,undefined8 *param_4)

{
  int iVar1;
  ulong uVar2;
  
  uVar2 = QObject::qt_metacall();
  iVar1 = (int)uVar2;
  if (-1 < iVar1) {
    if (param_2 == 0) {
      if (iVar1 < 3) {
        FUN_0090e910(param_1,0,uVar2 & 0xffffffff,param_4);
        uVar2 = uVar2 & 0xffffffff;
      }
    }
    else {
      if (param_2 != 0xc) {
        return uVar2;
      }
      if (iVar1 < 3) {
        *(undefined4 *)*param_4 = 0xffffffff;
      }
    }
    uVar2 = (ulong)((int)uVar2 - 3);
  }
  return uVar2;
}


// ==== entry=0090ea40 orig=FUN_0090ea40 size=24 name=ZModem_metaObject ====

undefined ** ZModem_metaObject(long param_1)

{
  undefined **ppuVar1;
  
  if (*(long *)(*(long *)(param_1 + 8) + 0x28) != 0) {
    ppuVar1 = (undefined **)QObjectData::dynamicMetaObject();
    return ppuVar1;
  }
  return &PTR_PTR_011a6f60;
}


// ==== entry=0090ea58 name=FUN_0090ea58 size=39 ====

void FUN_0090ea58(QObject *param_1,undefined8 param_2)

{
  void *local_18;
  undefined8 local_10;
  
  local_18 = (void *)0x0;
  local_10 = param_2;
  QMetaObject::activate(param_1,(QMetaObject *)&PTR_PTR_011a6f60,0,&local_18);
  return;
}


// ==== entry=0090ea80 name=FUN_0090ea80 size=60 ====

void FUN_0090ea80(undefined8 param_1,int param_2,int param_3,undefined8 *param_4)

{
  if (param_2 == 0) {
    if (param_3 == 0) {
      FUN_0090ea58(param_1,param_4[1]);
      return;
    }
  }
  else if (((param_2 == 10) && (*(code **)param_4[1] == FUN_0090ea58)) &&
          (((long *)param_4[1])[1] == 0)) {
    *(undefined4 *)*param_4 = 0;
    return;
  }
  return;
}


// ==== entry=0090eabc orig=FUN_0090eabc size=66 name=ZModem_qt_metacast ====

undefined8 ZModem_qt_metacast(undefined8 param_1,char *param_2)

{
  int iVar1;
  undefined8 uVar2;
  
  if (param_2 == (char *)0x0) {
    return 0;
  }
  iVar1 = strcmp(param_2,"ZModem");
  if (iVar1 == 0) {
    return param_1;
  }
  uVar2 = Modem_dtor(param_1,param_2);
  return uVar2;
}


// ==== entry=0090eafe orig=FUN_0090eafe size=91 name=ZModem_qt_metacall ====

ulong ZModem_qt_metacall(undefined8 param_1,int param_2,undefined8 param_3,undefined8 *param_4)

{
  int iVar1;
  ulong uVar2;
  
  uVar2 = Modem_dtor_deleting();
  iVar1 = (int)uVar2;
  if (-1 < iVar1) {
    if (param_2 == 0) {
      if (iVar1 == 0) {
        FUN_0090ea58(param_1,param_4[1]);
        uVar2 = uVar2 & 0xffffffff;
      }
    }
    else {
      if (param_2 != 0xc) {
        return uVar2;
      }
      if (iVar1 == 0) {
        *(undefined4 *)*param_4 = 0xffffffff;
      }
    }
    uVar2 = (ulong)((int)uVar2 - 1);
  }
  return uVar2;
}


// ==== entry=0090eb60 orig=FUN_0090eb60 size=24 name=ModemProcess_metaObject ====

undefined ** ModemProcess_metaObject(long param_1)

{
  undefined **ppuVar1;
  
  if (*(long *)(*(long *)(param_1 + 8) + 0x28) != 0) {
    ppuVar1 = (undefined **)QObjectData::dynamicMetaObject();
    return ppuVar1;
  }
  return &PTR_staticMetaObject_011a70a0;
}


// ==== entry=0090eb78 name=FUN_0090eb78 size=51 ====

void FUN_0090eb78(QObject *param_1,undefined4 param_2)

{
  undefined4 local_1c;
  void *local_18;
  undefined4 *local_10;
  
  local_18 = (void *)0x0;
  local_10 = &local_1c;
  local_1c = param_2;
  QMetaObject::activate(param_1,(QMetaObject *)&PTR_staticMetaObject_011a70a0,0,&local_18);
  return;
}


// ==== entry=0090ebac name=FUN_0090ebac size=58 ====

void FUN_0090ebac(undefined8 param_1,int param_2,int param_3,undefined8 *param_4)

{
  if (param_2 == 0) {
    if (param_3 == 0) {
      FUN_0090eb78(param_1,*(undefined4 *)param_4[1]);
      return;
    }
  }
  else if (((param_2 == 10) && (*(code **)param_4[1] == FUN_0090eb78)) &&
          (((long *)param_4[1])[1] == 0)) {
    *(undefined4 *)*param_4 = 0;
    return;
  }
  return;
}


// ==== entry=0090ebe6 orig=FUN_0090ebe6 size=66 name=ModemProcess_qt_metacast ====

char * ModemProcess_qt_metacast(char *param_1,char *param_2)

{
  int iVar1;
  char *pcVar2;
  
  if (param_2 == (char *)0x0) {
    return (char *)0x0;
  }
  iVar1 = strcmp(param_2,"ModemProcess");
  if (iVar1 == 0) {
    return param_1;
  }
  pcVar2 = (char *)QProcess::qt_metacast(param_1);
  return pcVar2;
}


// ==== entry=0090ec28 orig=FUN_0090ec28 size=90 name=ModemProcess_qt_metacall ====

ulong ModemProcess_qt_metacall
                (undefined8 param_1,int param_2,undefined8 param_3,undefined8 *param_4)

{
  int iVar1;
  ulong uVar2;
  
  uVar2 = QProcess::qt_metacall();
  iVar1 = (int)uVar2;
  if (-1 < iVar1) {
    if (param_2 == 0) {
      if (iVar1 == 0) {
        FUN_0090eb78(param_1,*(undefined4 *)param_4[1]);
        uVar2 = uVar2 & 0xffffffff;
      }
    }
    else {
      if (param_2 != 0xc) {
        return uVar2;
      }
      if (iVar1 == 0) {
        *(undefined4 *)*param_4 = 0xffffffff;
      }
    }
    uVar2 = (ulong)((int)uVar2 - 1);
  }
  return uVar2;
}


// ==== entry=0090ec82 name=FUN_0090ec82 size=1 ====

void FUN_0090ec82(void)

{
  return;
}


// ==== entry=0090ec84 orig=FUN_0090ec84 size=24 name=TerminalKeyboard_metaObject ====

undefined ** TerminalKeyboard_metaObject(long param_1)

{
  undefined **ppuVar1;
  
  if (*(long *)(*(long *)(param_1 + 8) + 0x28) != 0) {
    ppuVar1 = (undefined **)QObjectData::dynamicMetaObject();
    return ppuVar1;
  }
  return &PTR_staticMetaObject_011a7160;
}


// ==== entry=0090ec9c orig=FUN_0090ec9c size=66 name=TerminalKeyboard_qt_metacast ====

char * TerminalKeyboard_qt_metacast(char *param_1,char *param_2)

{
  int iVar1;
  char *pcVar2;
  
  if (param_2 == (char *)0x0) {
    return (char *)0x0;
  }
  iVar1 = strcmp(param_2,"TerminalKeyboard");
  if (iVar1 == 0) {
    return param_1;
  }
  pcVar2 = (char *)QObject::qt_metacast(param_1);
  return pcVar2;
}


// ==== entry=0090ecde orig=FUN_0090ecde size=5 name=TerminalKeyboard_qt_metacall ====

void QObject::TerminalKeyboard_qt_metacall(void)

{
  qt_metacall();
  return;
}


// ==== entry=0090ece4 orig=FUN_0090ece4 size=19 name=TerminalKeyboard_dtor ====

void TerminalKeyboard_dtor(QObject *param_1)

{
  *(undefined ***)param_1 = &TerminalKeyboard_vtable;
  QObject::~QObject(param_1);
  return;
}


// ==== entry=0090ecf8 orig=FUN_0090ecf8 size=37 name=TerminalKeyboard_dtor_deleting ====

void TerminalKeyboard_dtor_deleting(QObject *param_1)

{
  *(undefined ***)param_1 = &TerminalKeyboard_vtable;
  QObject::~QObject(param_1);
  operator_delete(param_1,0x28);
  return;
}


// ==== entry=0090ed1e name=FUN_0090ed1e size=1 ====

void FUN_0090ed1e(void)

{
  return;
}


// ==== entry=0090ed20 orig=FUN_0090ed20 size=24 name=SessionConnector_metaObject ====

undefined ** SessionConnector_metaObject(long param_1)

{
  undefined **ppuVar1;
  
  if (*(long *)(*(long *)(param_1 + 8) + 0x28) != 0) {
    ppuVar1 = (undefined **)QObjectData::dynamicMetaObject();
    return ppuVar1;
  }
  return &PTR_staticMetaObject_011a7220;
}


// ==== entry=0090ed38 orig=FUN_0090ed38 size=66 name=SessionConnector_qt_metacast ====

char * SessionConnector_qt_metacast(char *param_1,char *param_2)

{
  int iVar1;
  char *pcVar2;
  
  if (param_2 == (char *)0x0) {
    return (char *)0x0;
  }
  iVar1 = strcmp(param_2,"SessionConnector");
  if (iVar1 == 0) {
    return param_1;
  }
  pcVar2 = (char *)QObject::qt_metacast(param_1);
  return pcVar2;
}


// ==== entry=0090ed7a orig=FUN_0090ed7a size=5 name=SessionConnector_qt_metacall ====

void QObject::SessionConnector_qt_metacall(void)

{
  qt_metacall();
  return;
}


// ==== entry=0090ed80 name=FUN_0090ed80 size=1 ====

void FUN_0090ed80(void)

{
  return;
}


// ==== entry=0090ed82 orig=FUN_0090ed82 size=24 name=SessionLogger_metaObject ====

undefined ** SessionLogger_metaObject(long param_1)

{
  undefined **ppuVar1;
  
  if (*(long *)(*(long *)(param_1 + 8) + 0x28) != 0) {
    ppuVar1 = (undefined **)QObjectData::dynamicMetaObject();
    return ppuVar1;
  }
  return &PTR_staticMetaObject_011a72e0;
}


// ==== entry=0090ed9a orig=FUN_0090ed9a size=66 name=SessionLogger_qt_metacast ====

char * SessionLogger_qt_metacast(char *param_1,char *param_2)

{
  int iVar1;
  char *pcVar2;
  
  if (param_2 == (char *)0x0) {
    return (char *)0x0;
  }
  iVar1 = strcmp(param_2,"SessionLogger");
  if (iVar1 == 0) {
    return param_1;
  }
  pcVar2 = (char *)QObject::qt_metacast(param_1);
  return pcVar2;
}


// ==== entry=0090eddc orig=FUN_0090eddc size=5 name=SessionLogger_qt_metacall ====

void QObject::SessionLogger_qt_metacall(void)

{
  qt_metacall();
  return;
}


// ==== entry=0090edf0 orig=FUN_0090edf0 size=24 name=SuperCommander_metaObject ====

undefined ** SuperCommander_metaObject(long param_1)

{
  undefined **ppuVar1;
  
  if (*(long *)(*(long *)(param_1 + 8) + 0x28) != 0) {
    ppuVar1 = (undefined **)QObjectData::dynamicMetaObject();
    return ppuVar1;
  }
  return &PTR_staticMetaObject_011a7440;
}


// ==== entry=0090ee08 name=FUN_0090ee08 size=61 ====

void FUN_0090ee08(QObject *param_1,undefined4 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined4 local_2c;
  void *local_28;
  undefined4 *local_20;
  undefined8 local_18;
  undefined8 local_10;
  
  local_28 = (void *)0x0;
  local_20 = &local_2c;
  local_2c = param_2;
  local_18 = param_3;
  local_10 = param_4;
  QMetaObject::activate(param_1,(QMetaObject *)&PTR_staticMetaObject_011a7440,0,&local_28);
  return;
}


// ==== entry=0090ee46 name=FUN_0090ee46 size=42 ====

void FUN_0090ee46(QObject *param_1,undefined8 param_2)

{
  void *local_18;
  undefined8 local_10;
  
  local_18 = (void *)0x0;
  local_10 = param_2;
  QMetaObject::activate(param_1,(QMetaObject *)&PTR_staticMetaObject_011a7440,1,&local_18);
  return;
}


// ==== entry=0090ee70 name=FUN_0090ee70 size=59 ====

void FUN_0090ee70(QObject *param_1,undefined4 param_2,undefined8 param_3)

{
  undefined4 local_2c;
  void *local_28;
  undefined4 *local_20;
  undefined8 local_18;
  
  local_28 = (void *)0x0;
  local_20 = &local_2c;
  local_2c = param_2;
  local_18 = param_3;
  QMetaObject::activate(param_1,(QMetaObject *)&PTR_staticMetaObject_011a7440,2,&local_28);
  return;
}


// ==== entry=0090eeac name=FUN_0090eeac size=42 ====

void FUN_0090eeac(QObject *param_1,undefined8 param_2)

{
  void *local_18;
  undefined8 local_10;
  
  local_18 = (void *)0x0;
  local_10 = param_2;
  QMetaObject::activate(param_1,(QMetaObject *)&PTR_staticMetaObject_011a7440,3,&local_18);
  return;
}


// ==== entry=0090eed6 name=FUN_0090eed6 size=69 ====

void FUN_0090eed6(QObject *param_1,undefined4 param_2,undefined8 param_3,undefined8 param_4,
                 undefined8 param_5)

{
  undefined4 local_3c;
  void *local_38;
  undefined4 *local_30;
  undefined8 local_28;
  undefined8 local_20;
  undefined8 local_18;
  
  local_38 = (void *)0x0;
  local_30 = &local_3c;
  local_3c = param_2;
  local_28 = param_3;
  local_20 = param_4;
  local_18 = param_5;
  QMetaObject::activate(param_1,(QMetaObject *)&PTR_staticMetaObject_011a7440,4,&local_38);
  return;
}


// ==== entry=0090ef1c name=FUN_0090ef1c size=5928 ====

void FUN_0090ef1c(long param_1,int param_2,undefined4 param_3,long *param_4)

{
  undefined4 *puVar1;
  long *plVar2;
  code *pcVar3;
  undefined8 *puVar4;
  QArrayData *pQVar5;
  undefined1 uVar6;
  undefined4 uVar7;
  QArrayData *local_38;
  undefined4 local_30;
  QArrayData *local_28;
  undefined4 local_20;
  
  if (param_2 != 0) {
    if (param_2 == 10) {
      puVar1 = (undefined4 *)*param_4;
      plVar2 = (long *)param_4[1];
      pcVar3 = (code *)*plVar2;
      if ((pcVar3 == FUN_0090ee08) && (plVar2[1] == 0)) {
        *puVar1 = 0;
        return;
      }
      if ((pcVar3 == FUN_0090ee46) && (plVar2[1] == 0)) {
        *puVar1 = 1;
        return;
      }
      if ((pcVar3 == FUN_0090ee70) && (plVar2[1] == 0)) {
        *puVar1 = 2;
        return;
      }
      if ((pcVar3 == FUN_0090eeac) && (plVar2[1] == 0)) {
        *puVar1 = 3;
        return;
      }
      if ((pcVar3 == FUN_0090eed6) && (plVar2[1] == 0)) {
        *puVar1 = 4;
        return;
      }
    }
switchD_0090ef41_default:
    return;
  }
  switch(param_3) {
  case 0:
    FUN_0090ee08(param_1,*(undefined4 *)param_4[1],param_4[2],param_4[3]);
    break;
  case 1:
    FUN_0090ee46(param_1,param_4[1]);
    break;
  case 2:
    local_28 = *(QArrayData **)param_4[2];
    if ((*(int *)local_28 != 0) && (*(int *)local_28 != -1)) {
      LOCK();
      *(int *)local_28 = *(int *)local_28 + 1;
      UNLOCK();
    }
                    /* try { // try from 0090f2ee to 0090f2f2 has its CatchHandler @ 0091064c */
    FUN_0090ee70(param_1,*(undefined4 *)param_4[1],&local_28);
    if (*(int *)local_28 != 0) {
      if (*(int *)local_28 == -1) {
        return;
      }
      LOCK();
      *(int *)local_28 = *(int *)local_28 + -1;
      UNLOCK();
      if (*(int *)local_28 != 0) {
        return;
      }
    }
    QArrayData::deallocate(local_28,2,8);
    break;
  case 3:
    FUN_0090eeac(param_1,param_4[1]);
    break;
  case 4:
    FUN_0090eed6(param_1,*(undefined4 *)param_4[1],param_4[2],param_4[3],param_4[4]);
    break;
  case 5:
    FUN_007ca8bc();
    break;
  case 6:
    uVar6 = FUN_007ca8c8();
    if ((undefined1 *)*param_4 != (undefined1 *)0x0) {
      *(undefined1 *)*param_4 = uVar6;
    }
    break;
  case 7:
    s_terminal_answerBack_7cbb60();
    break;
  case 8:
    FUN_007ca8d4(param_1,*(undefined4 *)param_4[1],param_4[2]);
    break;
  case 9:
    FUN_007cad68();
    break;
  case 10:
    FUN_007cad8a();
    break;
  case 0xb:
    s_terminal_bellInterval_7cbc46();
    break;
  case 0xc:
    uVar6 = FUN_007cad96();
    if ((undefined1 *)*param_4 != (undefined1 *)0x0) {
      *(undefined1 *)*param_4 = uVar6;
    }
    break;
  case 0xd:
    FUN_007cada2();
    break;
  case 0xe:
    FUN_007cadae(param_1,param_4[1],param_4[2]);
    break;
  case 0xf:
    FUN_007cadda();
    break;
  case 0x10:
    FUN_007c8c0c(param_1,*(undefined4 *)param_4[1]);
    break;
  case 0x11:
    FUN_007c8c0c(param_1,0);
    break;
  case 0x12:
    FUN_007caeb6(param_1,param_4[1],param_4[2]);
    break;
  case 0x13:
    if ((undefined4 *)*param_4 != (undefined4 *)0x0) {
      *(undefined4 *)*param_4 = *(undefined4 *)(param_1 + 0xfc);
    }
    break;
  case 0x14:
    FUN_007c8c18(param_1,*(undefined4 *)param_4[1]);
    break;
  case 0x15:
    FUN_007c8c18(param_1,1);
    break;
  case 0x16:
    FUN_007c8c24(param_1,*(undefined4 *)param_4[1]);
    break;
  case 0x17:
    FUN_007c8c24(param_1,1);
    break;
  case 0x18:
    FUN_007c8c30(param_1,*(undefined4 *)param_4[1]);
    break;
  case 0x19:
    FUN_007c8c30(param_1,1);
    break;
  case 0x1a:
    FUN_007cb768();
    break;
  case 0x1b:
    FUN_007cb77a();
    break;
  case 0x1c:
    FUN_007cb78c();
    break;
  case 0x1d:
    FUN_007cb79e(param_1,param_4[1]);
    break;
  case 0x1e:
    FUN_007cb7aa(param_1,*(undefined4 *)param_4[1],*(undefined4 *)param_4[2]);
    break;
  case 0x1f:
    FUN_007cb7aa(param_1,*(undefined4 *)param_4[1],0);
    break;
  case 0x20:
    FUN_007cb7be();
    break;
  case 0x21:
    FUN_007cb7ca();
    break;
  case 0x22:
    FUN_007cb7d6();
    break;
  case 0x23:
    FUN_007c8c3c(param_1,*(undefined4 *)param_4[1]);
    break;
  case 0x24:
    FUN_007c8c3c(param_1,1);
    break;
  case 0x25:
    FUN_007cb106(param_1,*(undefined4 *)param_4[1]);
    break;
  case 0x26:
    FUN_007cb106(param_1,0);
    break;
  case 0x27:
    FUN_007c8c48(param_1,param_4[1]);
    break;
  case 0x28:
    FUN_007c8c68(param_1,*(undefined4 *)param_4[1]);
    break;
  case 0x29:
    FUN_007c8c68(param_1,0);
    break;
  case 0x2a:
    FUN_007cb17c(param_1,*(undefined4 *)param_4[1]);
    break;
  case 0x2b:
    FUN_007cb17c(param_1,0);
    break;
  case 0x2c:
    FUN_007c8c76(param_1,*(undefined4 *)param_4[1]);
    break;
  case 0x2d:
    FUN_007c8c76(param_1,0);
    break;
  case 0x2e:
    FUN_007cb7e2();
    break;
  case 0x2f:
    FUN_007cb7ee();
    break;
  case 0x30:
    FUN_007cb7fa(param_1,param_4[1],*(undefined4 *)param_4[2]);
    break;
  case 0x31:
    FUN_007cb7fa(param_1,param_4[1],0x20);
    break;
  case 0x32:
    FUN_007cb806();
    break;
  case 0x33:
    FUN_007cb812();
    break;
  case 0x34:
    FUN_007cb834(&local_28,param_1,param_4[1]);
    puVar4 = (undefined8 *)*param_4;
    if (puVar4 != (undefined8 *)0x0) {
      pQVar5 = (QArrayData *)*puVar4;
      *puVar4 = local_28;
      local_28 = pQVar5;
    }
    if (*(int *)local_28 != 0) {
      if (*(int *)local_28 == -1) {
        return;
      }
      LOCK();
      *(int *)local_28 = *(int *)local_28 + -1;
      UNLOCK();
      if (*(int *)local_28 != 0) {
        return;
      }
    }
    QArrayData::deallocate(local_28,1,8);
    break;
  case 0x35:
    FUN_007cb992(param_1,*(undefined4 *)param_4[1],param_4[2]);
    break;
  case 0x36:
    FUN_007cb99e();
    break;
  case 0x37:
    FUN_007c8c88(param_1,*(undefined4 *)param_4[1]);
    break;
  case 0x38:
    FUN_007c8c88(param_1,1);
    break;
  case 0x39:
    FUN_007c8c94(param_1,*(undefined4 *)param_4[1]);
    break;
  case 0x3a:
    FUN_007c8c94(param_1,1);
    break;
  case 0x3b:
    FUN_007c8ca0(param_1,*(undefined4 *)param_4[1]);
    break;
  case 0x3c:
    FUN_007c8ca0(param_1,1);
    break;
  case 0x3d:
    FUN_007cbaca();
    break;
  case 0x3e:
    FUN_007cbad6(param_1,param_4[1]);
    break;
  case 0x3f:
    QByteArray::QByteArray((QByteArray *)&local_28,"0",-1);
                    /* try { // try from 009104b7 to 009104bb has its CatchHandler @ 00910644 */
    FUN_007cbad6(param_1,(QByteArray *)&local_28);
    if (*(int *)local_28 != 0) {
      if (*(int *)local_28 == -1) {
        return;
      }
      LOCK();
      *(int *)local_28 = *(int *)local_28 + -1;
      UNLOCK();
      if (*(int *)local_28 != 0) {
        return;
      }
    }
    QArrayData::deallocate(local_28,1,8);
    break;
  case 0x40:
    uVar7 = FUN_007cbaee();
    if ((undefined4 *)*param_4 != (undefined4 *)0x0) {
      *(undefined4 *)*param_4 = uVar7;
    }
    break;
  case 0x41:
    uVar7 = FUN_007cbafa();
    if ((undefined4 *)*param_4 != (undefined4 *)0x0) {
      *(undefined4 *)*param_4 = uVar7;
    }
    break;
  case 0x42:
    uVar7 = FUN_007cbb06();
    if ((undefined4 *)*param_4 != (undefined4 *)0x0) {
      *(undefined4 *)*param_4 = uVar7;
    }
    break;
  case 0x43:
    uVar7 = FUN_007cbb12();
    if ((undefined4 *)*param_4 != (undefined4 *)0x0) {
      *(undefined4 *)*param_4 = uVar7;
    }
    break;
  case 0x44:
    FUN_007cbb1e(param_1,*(undefined4 *)param_4[1]);
    break;
  case 0x45:
    FUN_007cbb1e(param_1,0);
    break;
  case 0x46:
    FUN_007cbb2a(param_1,*(undefined4 *)param_4[1]);
    break;
  case 0x47:
    FUN_007cbeda(param_1,*(undefined4 *)param_4[1],*(undefined4 *)param_4[2]);
    break;
  case 0x48:
    FUN_007cbeda(param_1,*(undefined4 *)param_4[1],1);
    break;
  case 0x49:
    FUN_007cbeda(param_1,1,1);
    break;
  case 0x4a:
    FUN_007c8cac(param_1,*(undefined4 *)param_4[1]);
    break;
  case 0x4b:
    FUN_007c8cac(param_1,1);
    break;
  case 0x4c:
    FUN_007cbe1e(param_1,*(undefined4 *)param_4[1]);
    break;
  case 0x4d:
    FUN_007cbe1e(param_1,1);
    break;
  case 0x4e:
    FUN_007cb1f6(param_1,*(undefined4 *)param_4[1]);
    break;
  case 0x4f:
    FUN_007cb1f6(param_1,1);
    break;
  case 0x50:
    FUN_007cb282(param_1,*(undefined4 *)param_4[1]);
    break;
  case 0x51:
    FUN_007cb282(param_1,1);
    break;
  case 0x52:
    FUN_007c8cc6(param_1,*(undefined4 *)param_4[1]);
    break;
  case 0x53:
    FUN_007c8cc6(param_1,1);
    break;
  case 0x54:
    FUN_007c8ce0(param_1,*(undefined4 *)param_4[1]);
    break;
  case 0x55:
    FUN_007c8ce0(param_1,1);
    break;
  case 0x56:
    FUN_007cbf28(param_1,*(undefined4 *)param_4[1]);
    break;
  case 0x57:
    FUN_007cbf28(param_1,1);
    break;
  case 0x58:
    FUN_007cb30c(param_1,*(undefined4 *)param_4[1]);
    break;
  case 0x59:
    FUN_007cb30c(param_1,1);
    break;
  case 0x5a:
    FUN_007cb3b0(param_1,*(undefined4 *)param_4[1]);
    break;
  case 0x5b:
    FUN_007cb3b0(param_1,1);
    break;
  case 0x5c:
    FUN_007cb454(param_1,*(undefined4 *)param_4[1]);
    break;
  case 0x5d:
    FUN_007cb454(param_1,1);
    break;
  case 0x5e:
    FUN_007cb4dc(param_1,*(undefined4 *)param_4[1]);
    break;
  case 0x5f:
    FUN_007cb4dc(param_1,1);
    break;
  case 0x60:
    FUN_007cb572(param_1,*(undefined4 *)param_4[1]);
    break;
  case 0x61:
    FUN_007cb572(param_1,1);
    break;
  case 0x62:
    FUN_007cb5fc(param_1,*(undefined4 *)param_4[1]);
    break;
  case 99:
    FUN_007cb5fc(param_1,1);
    break;
  case 100:
    FUN_007c8cfa(param_1,*(undefined4 *)param_4[1]);
    break;
  case 0x65:
    FUN_007c8cfa(param_1,1);
    break;
  case 0x66:
    FUN_007c8df2(param_1,*(undefined4 *)param_4[1]);
    break;
  case 0x67:
    FUN_007c8df2(param_1,1);
    break;
  case 0x68:
    FUN_007cbfd8(param_1,*(undefined4 *)param_4[1]);
    break;
  case 0x69:
    FUN_007cbfd8(param_1,1);
    break;
  case 0x6a:
    FUN_007cc054(param_1,*(undefined4 *)param_4[1]);
    break;
  case 0x6b:
    FUN_007cc054(param_1,1);
    break;
  case 0x6c:
    FUN_007cc0ce(param_1,*(undefined4 *)param_4[1]);
    break;
  case 0x6d:
    FUN_007cc0ce(param_1,0);
    break;
  case 0x6e:
    FUN_007c9e90(param_1,param_4[1]);
    break;
  case 0x6f:
    s_StartPrompt_7cf856(param_1,param_4[1]);
    break;
  case 0x70:
    FUN_007cf526(param_1,param_4[1]);
    break;
  case 0x71:
    s_CursorShape_7cf5d0(param_1,param_4[1]);
    break;
  case 0x72:
    local_28 = *(QArrayData **)param_4[2];
    if ((*(int *)local_28 != 0) && (*(int *)local_28 != -1)) {
      LOCK();
      *(int *)local_28 = *(int *)local_28 + 1;
      UNLOCK();
    }
                    /* try { // try from 0090f861 to 0090f865 has its CatchHandler @ 00910654 */
    FUN_007cf24e(param_1,*(undefined4 *)param_4[1],&local_28);
    if (*(int *)local_28 != 0) {
      if (*(int *)local_28 == -1) {
        return;
      }
      LOCK();
      *(int *)local_28 = *(int *)local_28 + -1;
      UNLOCK();
      if (*(int *)local_28 != 0) {
        return;
      }
    }
    QArrayData::deallocate(local_28,1,8);
    break;
  case 0x73:
    FUN_007cd50c(param_1,param_4[1]);
    break;
  case 0x74:
    FUN_007cbb36((QVariant *)&local_38,param_1,param_4[1]);
    puVar4 = (undefined8 *)*param_4;
    if (puVar4 != (undefined8 *)0x0) {
      local_28 = (QArrayData *)*puVar4;
      local_20 = *(undefined4 *)(puVar4 + 1);
      *puVar4 = local_38;
      *(undefined4 *)(puVar4 + 1) = local_30;
      local_38 = local_28;
      local_30 = local_20;
    }
    QVariant::~QVariant((QVariant *)&local_38);
    break;
  case 0x75:
    uVar7 = FUN_007cbe06();
    if ((undefined4 *)*param_4 != (undefined4 *)0x0) {
      *(undefined4 *)*param_4 = uVar7;
    }
    break;
  case 0x76:
    uVar7 = FUN_007cbe12();
    if ((undefined4 *)*param_4 != (undefined4 *)0x0) {
      *(undefined4 *)*param_4 = uVar7;
    }
    break;
  case 0x77:
    uVar7 = FUN_007cbec2();
    if ((undefined4 *)*param_4 != (undefined4 *)0x0) {
      *(undefined4 *)*param_4 = uVar7;
    }
    break;
  case 0x78:
    uVar7 = FUN_007cbece();
    if ((undefined4 *)*param_4 != (undefined4 *)0x0) {
      *(undefined4 *)*param_4 = uVar7;
    }
    break;
  case 0x79:
    uVar7 = FUN_007cbfcc();
    if ((undefined4 *)*param_4 != (undefined4 *)0x0) {
      *(undefined4 *)*param_4 = uVar7;
    }
    break;
  case 0x7a:
    uVar7 = FUN_007cc106();
    if ((undefined4 *)*param_4 != (undefined4 *)0x0) {
      *(undefined4 *)*param_4 = uVar7;
    }
    break;
  case 0x7b:
    FUN_007cc112(param_1,*(undefined4 *)param_4[1]);
    break;
  case 0x7c:
    FUN_007cc112(param_1,0);
    break;
  case 0x7d:
    FUN_007d0a2a();
    break;
  case 0x7e:
    FUN_007c8d14(param_1,*(undefined4 *)param_4[1]);
    break;
  case 0x7f:
    FUN_007c8d14(param_1,1);
    break;
  case 0x80:
    FUN_007cc25e();
    break;
  case 0x81:
    FUN_007cc26c();
    break;
  case 0x82:
    FUN_007cc27e();
    break;
  case 0x83:
    FUN_007cc290(param_1,param_4[1]);
    break;
  case 0x84:
    FUN_007cc29c(param_1,param_4[1]);
    break;
  case 0x85:
    FUN_007cc2a8(param_1,*(undefined4 *)param_4[1]);
    break;
  case 0x86:
    FUN_007cc2a8(param_1,0);
    break;
  case 0x87:
    FUN_007cc2b4(param_1,*(undefined4 *)param_4[1],param_4[2]);
    break;
  case 0x88:
    FUN_007c8d20(param_1,*(undefined4 *)param_4[1]);
    break;
  case 0x89:
    FUN_007cc2c0();
    break;
  case 0x8a:
    FUN_007cc2cc(param_1,*(undefined4 *)param_4[1]);
    break;
  case 0x8b:
    FUN_007cc2d8(param_1,*(undefined4 *)param_4[1]);
    break;
  case 0x8c:
    FUN_007cc2d8(param_1,0);
    break;
  case 0x8d:
    FUN_007c8d32(param_1,*(undefined4 *)param_4[1]);
    break;
  case 0x8e:
    FUN_007cc2e4(param_1,*(undefined4 *)param_4[1]);
    break;
  case 0x8f:
    FUN_007cc2f0(param_1,param_4[1]);
    break;
  case 0x90:
    FUN_007cc2fc(param_1,*(undefined4 *)param_4[1]);
    break;
  case 0x91:
    FUN_007cc2fc(param_1,0);
    break;
  case 0x92:
    FUN_007cc308();
    break;
  case 0x93:
    FUN_007cc314(param_1,param_4[1]);
    break;
  case 0x94:
    FUN_007cc3c2(param_1,param_4[1]);
    break;
  case 0x95:
    FUN_007c8d3e(param_1,param_4[1]);
    break;
  case 0x96:
    FUN_007cc3da();
    break;
  case 0x97:
    FUN_007cc3e6(param_1,*(undefined4 *)param_4[1]);
    break;
  case 0x98:
    FUN_007cc3e6(param_1,0xffffffff);
    break;
  case 0x99:
    FUN_007c8d5e(param_1,param_4[1]);
    break;
  case 0x9a:
    FUN_007cc3f2();
    break;
  case 0x9b:
    FUN_007cc3fe(param_1,*(undefined4 *)param_4[1],*(undefined4 *)param_4[2]);
    break;
  case 0x9c:
    FUN_007cc3fe(param_1,*(undefined4 *)param_4[1],0xffffffff);
    break;
  case 0x9d:
    FUN_007cc40a();
    break;
  case 0x9e:
    FUN_007c8d7e(param_1,param_4[1]);
    break;
  case 0x9f:
    FUN_007cc42c(param_1,*(undefined4 *)param_4[1],param_4[2]);
    break;
  case 0xa0:
    FUN_007cc438(param_1,*(undefined4 *)param_4[1],param_4[2]);
    break;
  case 0xa1:
    FUN_007cc444(param_1,param_4[1],param_4[2]);
    break;
  case 0xa2:
    uVar6 = FUN_007cc450();
    if ((undefined1 *)*param_4 != (undefined1 *)0x0) {
      *(undefined1 *)*param_4 = uVar6;
    }
    break;
  case 0xa3:
    FUN_007cc45c();
    break;
  case 0xa4:
    FUN_007c8d8a(param_1,param_4[1]);
    break;
  case 0xa5:
    FUN_007cc47e();
    break;
  case 0xa6:
    FUN_007cc4a0();
    break;
  case 0xa7:
    FUN_007c8d96(param_1,*(undefined4 *)param_4[1]);
    break;
  case 0xa8:
    FUN_007c8d96(param_1,1);
    break;
  case 0xa9:
    FUN_007c8e06(param_1,*(undefined4 *)param_4[1]);
    break;
  case 0xaa:
    FUN_007c8e06(param_1,1);
    break;
  case 0xab:
    FUN_007cc4c2();
    break;
  case 0xac:
    FUN_007c8dd4(param_1,*(undefined4 *)param_4[1]);
    break;
  case 0xad:
    FUN_007c8dd4(param_1,1);
    break;
  case 0xae:
    FUN_007c8db6(param_1,*(undefined4 *)param_4[1]);
    break;
  case 0xaf:
    FUN_007c8db6(param_1,1);
    break;
  case 0xb0:
    FUN_007cc4e4();
    break;
  case 0xb1:
    FUN_007cc4f2();
    break;
  case 0xb2:
    FUN_007cc504(param_1,*(undefined1 *)param_4[1],param_4[2]);
    break;
  case 0xb3:
    FUN_007cc514(param_1,*(undefined1 *)param_4[1],param_4[2]);
    break;
  case 0xb4:
    FUN_007cc524(param_1,*(undefined4 *)param_4[1]);
    break;
  case 0xb5:
    FUN_007cc524(param_1,0);
    break;
  case 0xb6:
    FUN_007cc530(param_1,*(undefined4 *)param_4[1]);
    break;
  case 0xb7:
    FUN_007cc530(param_1,0);
    break;
  case 0xb8:
    FUN_007cc53c(param_1,*(undefined4 *)param_4[1]);
    break;
  case 0xb9:
    FUN_007cc53c(param_1,0);
    break;
  case 0xba:
    FUN_007c8de6(param_1,param_4[1]);
    break;
  case 0xbb:
    local_28 = (QArrayData *)&QArrayData::shared_null;
                    /* try { // try from 0090fdf9 to 0090fdfd has its CatchHandler @ 0091068d */
    FUN_007c8de6(param_1,&local_28);
    if (*(int *)local_28 != 0) {
      if (*(int *)local_28 == -1) {
        return;
      }
      LOCK();
      *(int *)local_28 = *(int *)local_28 + -1;
      UNLOCK();
      if (*(int *)local_28 != 0) {
        return;
      }
    }
    QArrayData::deallocate(local_28,1,8);
    break;
  case 0xbc:
    FUN_007c8c56(param_1,param_4[1]);
    break;
  case 0xbd:
    FUN_007cc548(param_1,param_4[1]);
    break;
  case 0xbe:
    FUN_007cc554(param_1,*(undefined4 *)param_4[1]);
    break;
  case 0xbf:
    FUN_007cc560(param_1,*(undefined4 *)param_4[1]);
    break;
  case 0xc0:
    FUN_007cc560(param_1,0);
    break;
  case 0xc1:
    FUN_007cc59c(param_1,*(undefined1 *)param_4[1]);
    break;
  case 0xc2:
    FUN_007cc5ac();
    break;
  case 0xc3:
    FUN_007cc5be();
    break;
  case 0xc4:
    FUN_007cc5d0();
    break;
  case 0xc5:
    FUN_007cc7de(param_1,param_4[1]);
    break;
  case 0xc6:
    FUN_007cc810(param_1,*(undefined4 *)param_4[1]);
    break;
  case 199:
    FUN_007cc810(param_1,0);
    break;
  case 200:
    FUN_007cc81c(param_1,*(undefined4 *)param_4[1],*(undefined4 *)param_4[2]);
    break;
  case 0xc9:
    FUN_007cc81c(param_1,*(undefined4 *)param_4[1],0);
    break;
  case 0xca:
    FUN_007cc828(param_1,*(undefined4 *)param_4[1]);
    break;
  case 0xcb:
    FUN_007cc828(param_1,1);
    break;
  case 0xcc:
    FUN_007cc836(param_1,*(undefined4 *)param_4[1]);
    break;
  case 0xcd:
    FUN_007cc836(param_1,0);
    break;
  case 0xce:
    FUN_007c8d4c(param_1,param_4[1]);
    break;
  case 0xcf:
    local_28 = (QArrayData *)&QArrayData::shared_null;
                    /* try { // try from 0090ff7a to 0090ff7e has its CatchHandler @ 00910685 */
    FUN_007c8d4c(param_1,&local_28);
    if (*(int *)local_28 != 0) {
      if (*(int *)local_28 == -1) {
        return;
      }
      LOCK();
      *(int *)local_28 = *(int *)local_28 + -1;
      UNLOCK();
      if (*(int *)local_28 != 0) {
        return;
      }
    }
    QArrayData::deallocate(local_28,1,8);
    break;
  case 0xd0:
    FUN_007cc862(param_1,*(undefined4 *)param_4[1],*(undefined1 *)param_4[2]);
    break;
  case 0xd1:
    FUN_007cc862(param_1,*(undefined4 *)param_4[1],1);
    break;
  case 0xd2:
    FUN_007cc862(param_1,0xffffffff,1);
    break;
  case 0xd3:
    FUN_007cc872(param_1,*(undefined4 *)param_4[1],*(undefined4 *)param_4[2]);
    break;
  case 0xd4:
    FUN_007cc872(param_1,*(undefined4 *)param_4[1],0x7fffffff);
    break;
  case 0xd5:
    FUN_007cc87e(param_1,*(undefined4 *)param_4[1],*(undefined4 *)param_4[2]);
    break;
  case 0xd6:
    FUN_007cc87e(param_1,*(undefined4 *)param_4[1],0xffffffff);
    break;
  case 0xd7:
    FUN_007cc87e(param_1,0xffffffff);
    break;
  case 0xd8:
    FUN_007cc88a(param_1,*(undefined4 *)param_4[1]);
    break;
  case 0xd9:
    FUN_007cc88a(param_1,0x18);
    break;
  case 0xda:
    FUN_007cc896(param_1,*(undefined4 *)param_4[1]);
    break;
  case 0xdb:
    FUN_007cc896(param_1,0);
    break;
  case 0xdc:
    FUN_007c8d6c(param_1,param_4[1]);
    break;
  case 0xdd:
    local_28 = (QArrayData *)&QArrayData::shared_null;
                    /* try { // try from 009100ba to 009100be has its CatchHandler @ 0091067d */
    FUN_007c8d6c(param_1,&local_28);
    if (*(int *)local_28 != 0) {
      if (*(int *)local_28 == -1) {
        return;
      }
      LOCK();
      *(int *)local_28 = *(int *)local_28 + -1;
      UNLOCK();
      if (*(int *)local_28 != 0) {
        return;
      }
    }
    QArrayData::deallocate(local_28,1,8);
    break;
  case 0xde:
    FUN_007cce2a(param_1,*(undefined4 *)param_4[1],*(undefined4 *)param_4[2]);
    break;
  case 0xdf:
    FUN_007cce2a(param_1,*(undefined4 *)param_4[1],0xffffffff);
    break;
  case 0xe0:
    FUN_007cce2a(param_1,0xffffffff);
    break;
  case 0xe1:
    FUN_007cce36(param_1,*(undefined4 *)param_4[1],*(undefined4 *)param_4[2],
                 *(undefined4 *)param_4[3],param_4[4]);
    break;
  case 0xe2:
    local_28 = (QArrayData *)&QArrayData::shared_null;
                    /* try { // try from 00910178 to 0091017c has its CatchHandler @ 00910675 */
    FUN_007cce36(param_1,*(undefined4 *)param_4[1],*(undefined4 *)param_4[2],
                 *(undefined4 *)param_4[3],&local_28);
    if (*(int *)local_28 != 0) {
      if (*(int *)local_28 == -1) {
        return;
      }
      LOCK();
      *(int *)local_28 = *(int *)local_28 + -1;
      UNLOCK();
      if (*(int *)local_28 != 0) {
        return;
      }
    }
    QArrayData::deallocate(local_28,1,8);
    break;
  case 0xe3:
    local_28 = (QArrayData *)&QArrayData::shared_null;
                    /* try { // try from 009101d6 to 009101da has its CatchHandler @ 0091066d */
    FUN_007cce36(param_1,*(undefined4 *)param_4[1],*(undefined4 *)param_4[2],0,&local_28);
    if (*(int *)local_28 != 0) {
      if (*(int *)local_28 == -1) {
        return;
      }
      LOCK();
      *(int *)local_28 = *(int *)local_28 + -1;
      UNLOCK();
      if (*(int *)local_28 != 0) {
        return;
      }
    }
    QArrayData::deallocate(local_28,1,8);
    break;
  case 0xe4:
    local_28 = (QArrayData *)&QArrayData::shared_null;
                    /* try { // try from 00910230 to 00910234 has its CatchHandler @ 00910665 */
    FUN_007cce36(param_1,*(undefined4 *)param_4[1],0,0,&local_28);
    if (*(int *)local_28 != 0) {
      if (*(int *)local_28 == -1) {
        return;
      }
      LOCK();
      *(int *)local_28 = *(int *)local_28 + -1;
      UNLOCK();
      if (*(int *)local_28 != 0) {
        return;
      }
    }
    QArrayData::deallocate(local_28,1,8);
    break;
  case 0xe5:
    local_28 = (QArrayData *)&QArrayData::shared_null;
                    /* try { // try from 00910286 to 0091028a has its CatchHandler @ 0091065c */
    FUN_007cce36(param_1,0,0,0,&local_28);
    if (*(int *)local_28 != 0) {
      if (*(int *)local_28 == -1) {
        return;
      }
      LOCK();
      *(int *)local_28 = *(int *)local_28 + -1;
      UNLOCK();
      if (*(int *)local_28 != 0) {
        return;
      }
    }
    QArrayData::deallocate(local_28,1,8);
    break;
  case 0xe6:
    FUN_007cce4e(param_1,*(undefined4 *)param_4[1]);
    break;
  case 0xe7:
    FUN_007cce4e(param_1,0);
    break;
  case 0xe8:
    FUN_007cce5a(param_1,param_4[1]);
    break;
  case 0xe9:
    FUN_007cce66(param_1,*(undefined4 *)param_4[1],param_4[2]);
    break;
  case 0xea:
    FUN_007cce72(param_1,param_4[1]);
    break;
  case 0xeb:
    FUN_007cd958(param_1,param_4[1]);
    break;
  case 0xec:
    FUN_007cd816(param_1,param_4[1],param_4[2]);
    break;
  case 0xed:
    FUN_007cd902(param_1,param_4[1]);
    break;
  case 0xee:
    FUN_007ccf48(param_1,param_4[1]);
    break;
  case 0xef:
    FUN_007cd036();
    break;
  case 0xf0:
    FUN_007cd04c();
    break;
  case 0xf1:
    FUN_007cd08a();
    break;
  case 0xf2:
    FUN_007cd0a0();
    break;
  case 0xf3:
    FUN_007cd060();
    break;
  case 0xf4:
    FUN_007cd076();
    break;
  case 0xf5:
    FUN_007cd0b4();
    break;
  case 0xf6:
    FUN_007cd0c8();
    break;
  case 0xf7:
    FUN_007cd0da();
    break;
  case 0xf8:
    FUN_007cd0ec();
    break;
  case 0xf9:
    FUN_007cd0fa();
    break;
  case 0xfa:
    FUN_007cd35a(param_1,param_4[1]);
    break;
  case 0xfb:
    FUN_007cd366(&local_28,param_1,param_4[1]);
    puVar4 = (undefined8 *)*param_4;
    if (puVar4 != (undefined8 *)0x0) {
      pQVar5 = (QArrayData *)*puVar4;
      *puVar4 = local_28;
      local_28 = pQVar5;
    }
    if (*(int *)local_28 != 0) {
      if (*(int *)local_28 == -1) {
        return;
      }
      LOCK();
      *(int *)local_28 = *(int *)local_28 + -1;
      UNLOCK();
      if (*(int *)local_28 != 0) {
        return;
      }
    }
    QArrayData::deallocate(local_28,2,8);
    break;
  case 0xfc:
    FUN_007cd97a();
    break;
  case 0xfd:
    FUN_007cd986();
    break;
  case 0xfe:
    FUN_007cd992();
    break;
  case 0xff:
    FUN_007cd99e();
    break;
  case 0x100:
    uVar6 = FUN_007cd9aa();
    if ((undefined1 *)*param_4 != (undefined1 *)0x0) {
      *(undefined1 *)*param_4 = uVar6;
    }
    break;
  case 0x101:
    FUN_007cd9b6(param_1,*(undefined1 *)param_4[1],*(undefined1 *)param_4[2]);
    break;
  case 0x102:
    uVar7 = FUN_007cd9d0();
    if ((undefined4 *)*param_4 != (undefined4 *)0x0) {
      *(undefined4 *)*param_4 = uVar7;
    }
    break;
  case 0x103:
    FUN_007cd9dc(&local_28,param_1);
    puVar4 = (undefined8 *)*param_4;
    if (puVar4 != (undefined8 *)0x0) {
      pQVar5 = (QArrayData *)*puVar4;
      *puVar4 = local_28;
      local_28 = pQVar5;
    }
    if (*(int *)local_28 != 0) {
      if (*(int *)local_28 == -1) {
        return;
      }
      LOCK();
      *(int *)local_28 = *(int *)local_28 + -1;
      UNLOCK();
      if (*(int *)local_28 != 0) {
        return;
      }
    }
    QArrayData::deallocate(local_28,2,8);
    break;
  case 0x104:
    uVar7 = FUN_007cdb0c();
    if ((undefined4 *)*param_4 != (undefined4 *)0x0) {
      *(undefined4 *)*param_4 = uVar7;
    }
    break;
  case 0x105:
    FUN_007cdb18(&local_28,param_1);
    puVar4 = (undefined8 *)*param_4;
    if (puVar4 != (undefined8 *)0x0) {
      pQVar5 = (QArrayData *)*puVar4;
      *puVar4 = local_28;
      local_28 = pQVar5;
    }
    if (*(int *)local_28 != 0) {
      if (*(int *)local_28 == -1) {
        return;
      }
      LOCK();
      *(int *)local_28 = *(int *)local_28 + -1;
      UNLOCK();
      if (*(int *)local_28 != 0) {
        return;
      }
    }
    QArrayData::deallocate(local_28,2,8);
    break;
  case 0x106:
    FUN_007cdc9a();
    break;
  case 0x107:
    FUN_007cdca6();
    break;
  default:
    goto switchD_0090ef41_default;
  }
  return;
}


// ==== entry=00910696 orig=FUN_00910696 size=104 name=SuperCommander_qt_metacast ====

char * SuperCommander_qt_metacast(char *param_1,byte *param_2)

{
  int iVar1;
  char *pcVar2;
  long lVar3;
  byte *pbVar4;
  bool bVar5;
  bool bVar6;
  byte bVar7;
  
  bVar7 = 0;
  if (param_2 == (byte *)0x0) {
    return (char *)0x0;
  }
  iVar1 = strcmp((char *)param_2,"SuperCommander");
  bVar5 = false;
  if (iVar1 == 0) {
    return param_1;
  }
  lVar3 = 0xe;
  bVar6 = false;
  pbVar4 = (byte *)"ActionHandler";
  do {
    if (lVar3 == 0) break;
    lVar3 = lVar3 + -1;
    bVar5 = *param_2 < *pbVar4;
    bVar6 = *param_2 == *pbVar4;
    param_2 = param_2 + (ulong)bVar7 * -2 + 1;
    pbVar4 = pbVar4 + (ulong)bVar7 * -2 + 1;
  } while (bVar6);
  if ((!bVar5 && !bVar6) == bVar5) {
    return param_1 + 0x10;
  }
  pcVar2 = (char *)QObject::qt_metacast(param_1);
  return pcVar2;
}


// ==== entry=009106fe orig=FUN_009106fe size=99 name=SuperCommander_qt_metacall ====

ulong SuperCommander_qt_metacall
                (undefined8 param_1,int param_2,undefined8 param_3,undefined8 *param_4)

{
  int iVar1;
  ulong uVar2;
  
  uVar2 = QObject::qt_metacall();
  iVar1 = (int)uVar2;
  if (-1 < iVar1) {
    if (param_2 == 0) {
      if (iVar1 < 0x108) {
        FUN_0090ef1c(param_1,0,uVar2 & 0xffffffff,param_4);
        uVar2 = uVar2 & 0xffffffff;
      }
    }
    else {
      if (param_2 != 0xc) {
        return uVar2;
      }
      if (iVar1 < 0x108) {
        *(undefined4 *)*param_4 = 0xffffffff;
      }
    }
    uVar2 = (ulong)((int)uVar2 - 0x108);
  }
  return uVar2;
}


// ==== entry=00910762 name=FUN_00910762 size=1 ====

void FUN_00910762(void)

{
  return;
}


// ==== entry=00910764 name=FUN_00910764 size=3 ====

undefined8 FUN_00910764(void)

{
  return 0;
}


// ==== entry=00910768 name=FUN_00910768 size=1 ====

void FUN_00910768(void)

{
  return;
}


// ==== entry=00910770 orig=FUN_00910770 size=24 name=TerminalWidget_metaObject ====

undefined ** TerminalWidget_metaObject(long param_1)

{
  undefined **ppuVar1;
  
  if (*(long *)(*(long *)(param_1 + 8) + 0x28) != 0) {
    ppuVar1 = (undefined **)QObjectData::dynamicMetaObject();
    return ppuVar1;
  }
  return &PTR_PTR_011a7c00;
}


