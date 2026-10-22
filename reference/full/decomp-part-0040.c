// Ghidra 12.1.4 decompiled — WindTerm 2.7.0 (sha256 9491b87e…) part 40
// ==== entry=00c10850 name=FUN_00c10850 size=19 ====

void FUN_00c10850(undefined8 *param_1)

{
  *param_1 = &PTR_FUN_011b4408;
  FUN_00c10810();
  return;
}


// ==== entry=00c10870 name=FUN_00c10870 size=19 ====

void FUN_00c10870(undefined8 *param_1)

{
  *param_1 = &PTR_FUN_011b4510;
  FUN_00c10810();
  return;
}


// ==== entry=00c10890 name=FUN_00c10890 size=18 ====

void FUN_00c10890(void *param_1)

{
  FUN_00c10790();
  operator_delete(param_1);
  return;
}


// ==== entry=00c108b0 name=FUN_00c108b0 size=18 ====

void FUN_00c108b0(void *param_1)

{
  FUN_00c107b0();
  operator_delete(param_1);
  return;
}


// ==== entry=00c108d0 name=FUN_00c108d0 size=18 ====

void FUN_00c108d0(void *param_1)

{
  FUN_00c107d0();
  operator_delete(param_1);
  return;
}


// ==== entry=00c108f0 name=FUN_00c108f0 size=18 ====

void FUN_00c108f0(void *param_1)

{
  FUN_00c107f0();
  operator_delete(param_1);
  return;
}


// ==== entry=00c10910 name=FUN_00c10910 size=18 ====

void FUN_00c10910(void *param_1)

{
  FUN_00c10810();
  operator_delete(param_1);
  return;
}


// ==== entry=00c10930 name=FUN_00c10930 size=18 ====

void FUN_00c10930(void *param_1)

{
  FUN_00c10830();
  operator_delete(param_1);
  return;
}


// ==== entry=00c10950 name=FUN_00c10950 size=18 ====

void FUN_00c10950(void *param_1)

{
  FUN_00c10850();
  operator_delete(param_1);
  return;
}


// ==== entry=00c10970 name=FUN_00c10970 size=18 ====

void FUN_00c10970(void *param_1)

{
  FUN_00c10870();
  operator_delete(param_1);
  return;
}


// ==== entry=00c10990 name=FUN_00c10990 size=40 ====

undefined8 FUN_00c10990(undefined8 *param_1,short *param_2)

{
  short *psVar1;
  
  psVar1 = (short *)*param_1;
  if ((1 < (ulong)(param_1[1] - (long)psVar1)) && (*param_2 == *psVar1)) {
    *param_1 = psVar1 + 1;
    return 1;
  }
  return 0;
}


// ==== entry=00c109c0 name=FUN_00c109c0 size=164 ====

ulong FUN_00c109c0(long *param_1,ulong param_2,uint param_3)

{
  ushort *puVar1;
  ushort uVar2;
  ushort uVar4;
  long lVar5;
  ulong uVar3;
  
  puVar1 = (ushort *)*param_1;
  if ((ulong)(param_1[1] - (long)puVar1) < 2) {
    return 0xfffffffe;
  }
  uVar2 = *puVar1;
  if ((param_3 & 1) == 0) {
    uVar2 = uVar2 << 8 | uVar2 >> 8;
  }
  uVar3 = (ulong)uVar2;
  if (uVar2 - 0xd800 < 0x400) {
    if ((ulong)(param_1[1] - (long)puVar1) < 4) {
      return 0xfffffffe;
    }
    uVar4 = puVar1[1];
    if ((param_3 & 1) == 0) {
      uVar4 = uVar4 << 8 | uVar4 >> 8;
    }
    if (0x3ff < uVar4 - 0xdc00) {
      return 0xffffffff;
    }
    lVar5 = 2;
    uVar3 = (ulong)(uVar4 + 0xfca02400 + (uint)uVar2 * 0x400);
  }
  else {
    if (uVar2 - 0xdc00 < 0x400) {
      return 0xffffffff;
    }
    lVar5 = 1;
  }
  if (uVar3 <= param_2) {
    *param_1 = (long)(puVar1 + lVar5);
    return uVar3;
  }
  return uVar3;
}


// ==== entry=00c10a80 name=FUN_00c10a80 size=19 ====

void FUN_00c10a80(codecvt<wchar_t,char,__mbstate_t> *param_1)

{
  *(undefined ***)param_1 = &PTR_FUN_011b4358;
  std::codecvt<wchar_t,char,__mbstate_t>::~codecvt(param_1);
  return;
}


// ==== entry=00c10aa0 name=FUN_00c10aa0 size=18 ====

void FUN_00c10aa0(void *param_1)

{
  FUN_00c10a80();
  operator_delete(param_1);
  return;
}


// ==== entry=00c10ac0 name=FUN_00c10ac0 size=19 ====

void FUN_00c10ac0(codecvt<wchar_t,char,__mbstate_t> *param_1)

{
  *(undefined ***)param_1 = &PTR_FUN_011b4460;
  std::codecvt<wchar_t,char,__mbstate_t>::~codecvt(param_1);
  return;
}


// ==== entry=00c10ae0 name=FUN_00c10ae0 size=18 ====

void FUN_00c10ae0(void *param_1)

{
  FUN_00c10ac0();
  operator_delete(param_1);
  return;
}


// ==== entry=00c10b00 name=FUN_00c10b00 size=19 ====

void FUN_00c10b00(codecvt<wchar_t,char,__mbstate_t> *param_1)

{
  *(undefined ***)param_1 = &PTR_FUN_011b4568;
  std::codecvt<wchar_t,char,__mbstate_t>::~codecvt(param_1);
  return;
}


// ==== entry=00c10b20 name=FUN_00c10b20 size=18 ====

void FUN_00c10b20(void *param_1)

{
  FUN_00c10b00();
  operator_delete(param_1);
  return;
}


// ==== entry=00c10b40 name=FUN_00c10b40 size=244 ====

undefined8 FUN_00c10b40(long *param_1,uint param_2)

{
  byte *pbVar1;
  char *pcVar2;
  
  if (param_2 < 0x80) {
    pbVar1 = (byte *)*param_1;
    if (pbVar1 == (byte *)param_1[1]) {
      return 0;
    }
    *param_1 = (long)(pbVar1 + 1);
    *pbVar1 = (byte)param_2;
    return 1;
  }
  if (param_2 < 0x800) {
    pcVar2 = (char *)*param_1;
    if ((ulong)(param_1[1] - (long)pcVar2) < 2) {
      return 0;
    }
    *param_1 = (long)(pcVar2 + 1);
    *pcVar2 = (char)(param_2 >> 6) + -0x40;
  }
  else {
    if (param_2 < 0x10000) {
      pcVar2 = (char *)*param_1;
      if ((ulong)(param_1[1] - (long)pcVar2) < 3) {
        return 0;
      }
      *param_1 = (long)(pcVar2 + 1);
      *pcVar2 = (char)(param_2 >> 0xc) + -0x20;
    }
    else {
      if (0x10ffff < param_2) {
        return 0;
      }
      pcVar2 = (char *)*param_1;
      if ((ulong)(param_1[1] - (long)pcVar2) < 4) {
        return 0;
      }
      *param_1 = (long)(pcVar2 + 1);
      *pcVar2 = (char)(param_2 >> 0x12) + -0x10;
      pcVar2 = (char *)*param_1;
      *param_1 = (long)(pcVar2 + 1);
      *pcVar2 = ((byte)(param_2 >> 0xc) & 0x3f) + 0x80;
    }
    pcVar2 = (char *)*param_1;
    *param_1 = (long)(pcVar2 + 1);
    *pcVar2 = ((byte)(param_2 >> 6) & 0x3f) + 0x80;
  }
  pcVar2 = (char *)*param_1;
  *param_1 = (long)(pcVar2 + 1);
  *pcVar2 = ((byte)param_2 & 0x3f) + 0x80;
  return 1;
}


// ==== entry=00c10c50 name=FUN_00c10c50 size=80 ====

undefined8 FUN_00c10c50(long *param_1,ulong param_2)

{
  undefined2 *puVar1;
  undefined8 uVar2;
  
  uVar2 = 1;
  if ((param_2 & 2) != 0) {
    puVar1 = (undefined2 *)*param_1;
    uVar2 = 0;
    if ((param_2 & 1) == 0) {
      if (1 < (ulong)(param_1[1] - (long)puVar1)) {
        *puVar1 = 0xfffe;
        uVar2 = 1;
        *param_1 = *param_1 + 2;
      }
    }
    else if (1 < (ulong)(param_1[1] - (long)puVar1)) {
      *puVar1 = 0xfeff;
      *param_1 = *param_1 + 2;
      return 1;
    }
  }
  return uVar2;
}


// ==== entry=00c10cb0 name=FUN_00c10cb0 size=281 ====

undefined8
FUN_00c10cb0(long param_1,undefined8 param_2,ushort *param_3,ushort *param_4,undefined8 *param_5,
            ushort *param_6,long param_7,long *param_8)

{
  char cVar1;
  ushort uVar2;
  undefined8 uVar3;
  uint uVar4;
  uint uVar5;
  long in_FS_OFFSET;
  ushort *local_38;
  long local_30;
  long local_20;
  
  uVar3 = *(undefined8 *)(param_1 + 0x10);
  local_20 = *(long *)(in_FS_OFFSET + 0x28);
  uVar5 = *(uint *)(param_1 + 0x18);
  local_30 = param_7;
  local_38 = param_6;
  cVar1 = FUN_00c10c50(&local_38,uVar5);
  if (cVar1 != '\0') {
    if (param_3 == param_4) {
LAB_00c10d9d:
      uVar3 = 0;
      goto LAB_00c10dad;
    }
    if (1 < (ulong)(local_30 - (long)local_38)) {
      uVar2 = *param_3;
      uVar4 = (uint)uVar3;
      if ((0x3ff < uVar2 - 0xd800) && (uVar2 <= uVar4)) {
        do {
          param_3 = param_3 + 1;
          if ((uVar5 & 1) == 0) {
            uVar2 = uVar2 << 8 | uVar2 >> 8;
          }
          *local_38 = uVar2;
          local_38 = local_38 + 1;
          if (param_4 == param_3) goto LAB_00c10d9d;
          if ((ulong)(local_30 - (long)local_38) < 2) goto LAB_00c10da8;
          uVar2 = *param_3;
        } while ((0x3ff < uVar2 - 0xd800) && (uVar2 <= uVar4));
      }
      uVar3 = 2;
      goto LAB_00c10dad;
    }
  }
LAB_00c10da8:
  uVar3 = 1;
LAB_00c10dad:
  *param_5 = param_3;
  *param_8 = (long)local_38;
  if (local_20 == *(long *)(in_FS_OFFSET + 0x28)) {
    return uVar3;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ==== entry=00c10de0 name=FUN_00c10de0 size=49 ====

undefined8 FUN_00c10de0(long *param_1)

{
  undefined2 *puVar1;
  
  puVar1 = (undefined2 *)*param_1;
  if ((ulong)(param_1[1] - (long)puVar1) < 3) {
    return 0;
  }
  *puVar1 = 0xbbef;
  *(undefined1 *)(puVar1 + 1) = 0xbf;
  *param_1 = *param_1 + 3;
  return 1;
}


// ==== entry=00c10e20 name=FUN_00c10e20 size=200 ====

undefined8 FUN_00c10e20(long *param_1,undefined8 param_2,ulong param_3,int param_4)

{
  ushort uVar1;
  char cVar2;
  ushort *puVar3;
  long lVar4;
  uint uVar5;
  
  puVar3 = (ushort *)*param_1;
  lVar4 = param_1[1] - (long)puVar3;
  if (puVar3 != (ushort *)param_1[1]) {
    do {
      uVar1 = *puVar3;
      uVar5 = (uint)uVar1;
      if (uVar1 - 0xd800 < 0x400) {
        if (param_4 == 1) {
          return 2;
        }
        if ((ulong)(lVar4 >> 1) < 2) {
          return 0;
        }
        if (0x3ff < puVar3[1] - 0xdc00) {
          return 2;
        }
        lVar4 = 2;
        uVar5 = puVar3[1] + 0xfca02400 + uVar5 * 0x400;
      }
      else {
        if (uVar1 - 0xdc00 < 0x400) {
          return 2;
        }
        lVar4 = 1;
      }
      if (param_3 < uVar5) {
        return 2;
      }
      cVar2 = FUN_00c10b40(param_2);
      if (cVar2 == '\0') {
        return 1;
      }
      puVar3 = (ushort *)(*param_1 + lVar4 * 2);
      lVar4 = param_1[1] - (long)puVar3;
      *param_1 = (long)puVar3;
    } while ((ushort *)param_1[1] != puVar3);
  }
  return 0;
}


// ==== entry=00c10f00 name=FUN_00c10f00 size=165 ====

undefined8
FUN_00c10f00(long param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
            undefined8 *param_5,undefined8 param_6,undefined8 param_7,undefined8 *param_8)

{
  char cVar1;
  undefined8 uVar2;
  long in_FS_OFFSET;
  undefined8 local_48;
  undefined8 local_40;
  undefined8 local_38;
  undefined8 local_30;
  long local_20;
  
  local_20 = *(long *)(in_FS_OFFSET + 0x28);
  local_30 = param_7;
  local_48 = param_3;
  local_40 = param_4;
  local_38 = param_6;
  if (((*(byte *)(param_1 + 0x18) & 2) == 0) || (cVar1 = FUN_00c10de0(&local_38), cVar1 != '\0')) {
    uVar2 = FUN_00c10e20(&local_48);
  }
  else {
    uVar2 = 1;
  }
  *param_5 = local_48;
  *param_8 = local_38;
  if (local_20 == *(long *)(in_FS_OFFSET + 0x28)) {
    return uVar2;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ==== entry=00c10fb0 name=FUN_00c10fb0 size=118 ====

void FUN_00c10fb0(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                 undefined8 *param_5,undefined8 param_6,undefined8 param_7,undefined8 *param_8)

{
  long in_FS_OFFSET;
  undefined8 local_48;
  undefined8 local_40;
  undefined8 local_38;
  undefined8 local_30;
  long local_20;
  
  local_20 = *(long *)(in_FS_OFFSET + 0x28);
  local_30 = param_7;
  local_48 = param_3;
  local_40 = param_4;
  local_38 = param_6;
  FUN_00c10e20(&local_48,&local_38,0x10ffff,0);
  *param_5 = local_48;
  *param_8 = local_38;
  if (local_20 == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ==== entry=00c11030 name=FUN_00c11030 size=84 ====

undefined8 FUN_00c11030(long *param_1,undefined8 param_2,ulong param_3)

{
  long lVar1;
  long lVar2;
  char cVar3;
  ulong uVar4;
  
  if ((uint *)*param_1 == (uint *)param_1[1]) {
    return 0;
  }
  uVar4 = (ulong)*(uint *)*param_1;
  if (uVar4 <= param_3) {
    do {
      cVar3 = FUN_00c10b40(param_2,uVar4);
      if (cVar3 == '\0') {
        return 1;
      }
      lVar2 = *param_1;
      lVar1 = lVar2 + 4;
      *param_1 = lVar1;
      if (param_1[1] == lVar1) {
        return 0;
      }
      uVar4 = (ulong)*(uint *)(lVar2 + 4);
    } while (uVar4 <= param_3);
  }
  return 2;
}


// ==== entry=00c11090 name=FUN_00c11090 size=140 ====

undefined8
FUN_00c11090(long param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
            undefined8 *param_5,undefined8 param_6,undefined8 param_7,undefined8 *param_8)

{
  char cVar1;
  undefined8 uVar2;
  long in_FS_OFFSET;
  undefined8 local_38;
  undefined8 local_30;
  undefined8 local_28;
  undefined8 local_20;
  long local_10;
  
  local_10 = *(long *)(in_FS_OFFSET + 0x28);
  local_30 = param_7;
  local_38 = param_6;
  local_28 = param_3;
  local_20 = param_4;
  if ((*(byte *)(param_1 + 0x20) & 2) != 0) {
    cVar1 = FUN_00c10de0(&local_38);
    if (cVar1 == '\0') {
      uVar2 = 1;
      goto LAB_00c110eb;
    }
  }
  uVar2 = FUN_00c11030(&local_28);
LAB_00c110eb:
  *param_5 = local_28;
  *param_8 = local_38;
  if (local_10 == *(long *)(in_FS_OFFSET + 0x28)) {
    return uVar2;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ==== entry=00c11120 name=FUN_00c11120 size=113 ====

void FUN_00c11120(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                 undefined8 *param_5,undefined8 param_6,undefined8 param_7,undefined8 *param_8)

{
  long in_FS_OFFSET;
  undefined8 local_38;
  undefined8 local_30;
  undefined8 local_28;
  undefined8 local_20;
  long local_10;
  
  local_10 = *(long *)(in_FS_OFFSET + 0x28);
  local_20 = param_7;
  local_38 = param_3;
  local_30 = param_4;
  local_28 = param_6;
  FUN_00c11030(&local_38,&local_28,0x10ffff);
  *param_5 = local_38;
  *param_8 = local_28;
  if (local_10 == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ==== entry=00c111a0 name=FUN_00c111a0 size=51 ====

void FUN_00c111a0(undefined8 param_1,uint *param_2)

{
  char cVar1;
  
  if ((*param_2 & 4) != 0) {
    cVar1 = FUN_00c10990(param_1,&DAT_00d96e03);
    if (cVar1 != '\0') {
      *param_2 = *param_2 & 0xfffffffe;
      return;
    }
    cVar1 = FUN_00c10990(param_1,&DAT_00d96e01);
    if (cVar1 != '\0') {
      *param_2 = *param_2 | 1;
      return;
    }
  }
  return;
}


// ==== entry=00c111f0 name=FUN_00c111f0 size=140 ====

undefined8 FUN_00c111f0(long *param_1,long *param_2,ulong param_3,undefined4 param_4)

{
  uint *puVar1;
  uint *puVar2;
  uint uVar3;
  undefined4 local_c;
  
  local_c = param_4;
  FUN_00c111a0(param_1,&local_c);
  if ((ulong)(param_1[1] - *param_1) < 2) {
    return 0;
  }
  if (*param_2 != param_2[1]) {
    do {
      uVar3 = FUN_00c109c0(param_1,param_3,local_c);
      if (uVar3 == 0xfffffffe) {
        return 1;
      }
      if (param_3 < uVar3) {
        return 2;
      }
      puVar2 = (uint *)*param_2;
      puVar1 = puVar2 + 1;
      *param_2 = (long)puVar1;
      *puVar2 = uVar3;
      if ((ulong)(param_1[1] - *param_1) < 2) {
        return 0;
      }
    } while ((uint *)param_2[1] != puVar1);
  }
  return 1;
}


// ==== entry=00c11290 name=FUN_00c11290 size=141 ====

ulong FUN_00c11290(long param_1,undefined8 param_2,long param_3,long param_4,long *param_5,
                  undefined8 param_6,undefined8 param_7,undefined8 *param_8)

{
  ulong uVar1;
  long in_FS_OFFSET;
  long local_48;
  long local_40;
  undefined8 local_38;
  undefined8 local_30;
  long local_20;
  
  local_20 = *(long *)(in_FS_OFFSET + 0x28);
  local_30 = param_7;
  local_48 = param_3;
  local_40 = param_4;
  local_38 = param_6;
  uVar1 = FUN_00c111f0(&local_48,&local_38,*(undefined8 *)(param_1 + 0x10),
                       *(undefined4 *)(param_1 + 0x18));
  *param_5 = local_48;
  *param_8 = local_38;
  if ((int)uVar1 == 0) {
    uVar1 = uVar1 & 0xffffffff;
    if (local_48 != param_4) {
      uVar1 = 2;
    }
  }
  if (local_20 == *(long *)(in_FS_OFFSET + 0x28)) {
    return uVar1;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ==== entry=00c11320 name=FUN_00c11320 size=141 ====

ulong FUN_00c11320(long param_1,undefined8 param_2,long param_3,long param_4,long *param_5,
                  undefined8 param_6,undefined8 param_7,undefined8 *param_8)

{
  ulong uVar1;
  long in_FS_OFFSET;
  long local_48;
  long local_40;
  undefined8 local_38;
  undefined8 local_30;
  long local_20;
  
  local_20 = *(long *)(in_FS_OFFSET + 0x28);
  local_30 = param_7;
  local_48 = param_3;
  local_40 = param_4;
  local_38 = param_6;
  uVar1 = FUN_00c111f0(&local_48,&local_38,*(undefined8 *)(param_1 + 0x18),
                       *(undefined4 *)(param_1 + 0x20));
  *param_5 = local_48;
  *param_8 = local_38;
  if ((int)uVar1 == 0) {
    uVar1 = uVar1 & 0xffffffff;
    if (local_48 != param_4) {
      uVar1 = 2;
    }
  }
  if (local_20 == *(long *)(in_FS_OFFSET + 0x28)) {
    return uVar1;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ==== entry=00c113b0 name=FUN_00c113b0 size=161 ====

long FUN_00c113b0(long param_1,undefined8 param_2,long param_3,undefined8 param_4,long param_5)

{
  uint uVar1;
  uint uVar2;
  ulong uVar3;
  long in_FS_OFFSET;
  undefined4 local_3c;
  long local_38;
  undefined8 local_30;
  long local_20;
  
  uVar2 = (uint)*(undefined8 *)(param_1 + 0x18);
  local_20 = *(long *)(in_FS_OFFSET + 0x28);
  local_3c = *(undefined4 *)(param_1 + 0x20);
  local_38 = param_3;
  local_30 = param_4;
  FUN_00c111a0(&local_38,&local_3c);
  uVar3 = (ulong)uVar2;
  if (param_5 != 0) {
    do {
      param_5 = param_5 + -1;
      uVar1 = FUN_00c109c0(&local_38,uVar3,local_3c);
    } while (uVar1 <= uVar2 && param_5 != 0);
  }
  if (local_20 == *(long *)(in_FS_OFFSET + 0x28)) {
    return local_38 - param_3;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ==== entry=00c11460 name=FUN_00c11460 size=278 ====

char FUN_00c11460(long param_1,undefined8 param_2,long param_3,long param_4,long *param_5,
                 undefined2 *param_6,undefined2 *param_7,long *param_8)

{
  char cVar1;
  uint uVar2;
  ulong uVar3;
  undefined2 *puVar4;
  uint uVar5;
  ulong uVar6;
  long in_FS_OFFSET;
  undefined4 local_5c;
  long local_58;
  long local_50;
  long local_40;
  
  uVar5 = (uint)*(undefined8 *)(param_1 + 0x10);
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  local_5c = *(undefined4 *)(param_1 + 0x18);
  puVar4 = param_6;
  local_58 = param_3;
  local_50 = param_4;
  FUN_00c111a0(&local_58,&local_5c);
  if (0xfffe < uVar5) {
    uVar5 = 0xffff;
  }
  uVar6 = (ulong)uVar5;
  uVar3 = local_50 - local_58;
  do {
    if (uVar3 < 2) {
      *param_5 = local_58;
      *param_8 = (long)puVar4;
      cVar1 = (param_4 != local_58) * '\x02';
LAB_00c11551:
      if (local_40 == *(long *)(in_FS_OFFSET + 0x28)) {
        return cVar1;
      }
                    /* WARNING: Subroutine does not return */
      __stack_chk_fail();
    }
    if (param_6 == param_7) {
      *param_5 = local_58;
      cVar1 = '\x01';
      *param_8 = (long)puVar4;
      goto LAB_00c11551;
    }
    uVar2 = FUN_00c109c0(&local_58,uVar5,local_5c);
    if ((uVar2 == 0xfffffffe) || ((uint)uVar6 < uVar2)) {
      *param_5 = local_58;
      cVar1 = '\x02';
      *param_8 = (long)puVar4;
      goto LAB_00c11551;
    }
    param_6 = puVar4 + 1;
    *puVar4 = (short)uVar2;
    uVar3 = local_50 - local_58;
    puVar4 = param_6;
  } while( true );
}


// ==== entry=00c11590 name=FUN_00c11590 size=177 ====

long FUN_00c11590(long param_1,undefined8 param_2,long param_3,undefined8 param_4,long param_5)

{
  uint uVar1;
  uint uVar2;
  ulong uVar3;
  long in_FS_OFFSET;
  undefined4 local_3c;
  long local_38;
  undefined8 local_30;
  long local_20;
  
  uVar2 = (uint)*(undefined8 *)(param_1 + 0x10);
  local_20 = *(long *)(in_FS_OFFSET + 0x28);
  local_3c = *(undefined4 *)(param_1 + 0x18);
  local_38 = param_3;
  local_30 = param_4;
  FUN_00c111a0(&local_38,&local_3c);
  if (0xfffe < uVar2) {
    uVar2 = 0xffff;
  }
  uVar3 = (ulong)uVar2;
  if (param_5 != 0) {
    do {
      param_5 = param_5 + -1;
      uVar1 = FUN_00c109c0(&local_38,(ulong)uVar2,local_3c);
    } while (param_5 != 0 && uVar1 <= (uint)uVar3);
  }
  if (local_20 == *(long *)(in_FS_OFFSET + 0x28)) {
    return local_38 - param_3;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ==== entry=00c11650 name=FUN_00c11650 size=215 ====

undefined8 FUN_00c11650(long *param_1,long *param_2,ulong param_3,uint param_4)

{
  uint uVar1;
  ushort *puVar2;
  ushort uVar3;
  ushort uVar4;
  ushort uVar5;
  long lVar6;
  
  if ((uint *)*param_1 == (uint *)param_1[1]) {
    return 0;
  }
  uVar1 = *(uint *)*param_1;
  do {
    if (param_3 < uVar1) {
      return 2;
    }
    puVar2 = (ushort *)*param_2;
    uVar4 = (ushort)uVar1;
    if (uVar1 < 0x10000) {
      if ((ulong)(param_2[1] - (long)puVar2) < 2) {
        return 1;
      }
      if ((param_4 & 1) == 0) {
        uVar4 = uVar4 << 8 | uVar4 >> 8;
      }
      *puVar2 = uVar4;
      lVar6 = *param_1;
      *param_2 = *param_2 + 2;
      *param_1 = lVar6 + 4;
      if (param_1[1] == lVar6 + 4) {
        return 0;
      }
    }
    else {
      if ((ulong)(param_2[1] - (long)puVar2) < 4) {
        return 1;
      }
      uVar3 = (uVar4 & 0x3ff) + 0xdc00;
      uVar5 = (short)(uVar1 >> 10) + 0xd7c0;
      if ((param_4 & 1) == 0) {
        uVar3 = uVar4 << 8 | uVar3 >> 8;
        *puVar2 = uVar5 * 0x100 | uVar5 >> 8;
        lVar6 = *param_2;
        *param_2 = lVar6 + 2;
      }
      else {
        *puVar2 = uVar5;
        lVar6 = *param_2;
        *param_2 = lVar6 + 2;
      }
      *(ushort *)(lVar6 + 2) = uVar3;
      lVar6 = *param_1;
      *param_2 = *param_2 + 2;
      *param_1 = lVar6 + 4;
      if (param_1[1] == lVar6 + 4) {
        return 0;
      }
    }
    uVar1 = *(uint *)(lVar6 + 4);
  } while( true );
}


// ==== entry=00c11740 name=FUN_00c11740 size=149 ====

undefined4
FUN_00c11740(long param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
            undefined8 *param_5,undefined8 param_6,undefined8 param_7,undefined8 *param_8)

{
  undefined8 uVar1;
  char cVar2;
  undefined4 uVar3;
  undefined8 *puVar4;
  ulong uVar5;
  long in_FS_OFFSET;
  undefined8 local_38;
  undefined8 local_30;
  undefined8 local_28;
  undefined8 local_20;
  long local_10;
  
  puVar4 = &local_38;
  uVar1 = *(undefined8 *)(param_1 + 0x18);
  local_10 = *(long *)(in_FS_OFFSET + 0x28);
  uVar5 = (ulong)*(uint *)(param_1 + 0x20);
  local_30 = param_7;
  local_38 = param_6;
  local_28 = param_3;
  local_20 = param_4;
  cVar2 = FUN_00c10c50(&local_38,uVar5);
  uVar3 = 1;
  if (cVar2 != '\0') {
    uVar3 = FUN_00c11650(&local_28,puVar4,uVar1,uVar5 & 0xffffffff);
  }
  *param_5 = local_28;
  *param_8 = local_38;
  if (local_10 == *(long *)(in_FS_OFFSET + 0x28)) {
    return uVar3;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ==== entry=00c117e0 name=FUN_00c117e0 size=280 ====

undefined8
FUN_00c117e0(long param_1,undefined8 param_2,uint *param_3,uint *param_4,long *param_5,
            undefined8 param_6,undefined8 param_7,undefined8 *param_8)

{
  uint uVar1;
  char cVar2;
  long lVar3;
  undefined8 uVar4;
  ulong uVar5;
  long in_FS_OFFSET;
  undefined8 local_38;
  undefined8 local_30;
  long local_20;
  
  local_20 = *(long *)(in_FS_OFFSET + 0x28);
  uVar5 = *(ulong *)(param_1 + 0x18);
  local_30 = param_7;
  local_38 = param_6;
  if (((*(byte *)(param_1 + 0x20) & 2) == 0) || (cVar2 = FUN_00c10de0(&local_38), cVar2 != '\0')) {
    lVar3 = (long)param_4 - (long)param_3;
    if (param_3 != param_4) {
      do {
        uVar1 = *param_3;
        if (uVar1 - 0xd800 < 0x400) {
          if (1 < (ulong)(lVar3 >> 2)) {
            if (param_3[1] - 0xdc00 < 0x400) {
              lVar3 = 2;
              uVar1 = param_3[1] + 0xfca02400 + uVar1 * 0x400;
              goto joined_r0x00c11879;
            }
LAB_00c118c5:
            uVar4 = 2;
            goto LAB_00c118d5;
          }
          break;
        }
        if (uVar1 - 0xdc00 < 0x400) goto LAB_00c118c5;
        lVar3 = 1;
joined_r0x00c11879:
        if (uVar5 < uVar1) goto LAB_00c118c5;
        cVar2 = FUN_00c10b40(&local_38);
        if (cVar2 == '\0') goto LAB_00c118d0;
        param_3 = param_3 + lVar3;
        lVar3 = (long)param_4 - (long)param_3;
      } while (param_4 != param_3);
    }
    uVar4 = 0;
  }
  else {
LAB_00c118d0:
    uVar4 = 1;
  }
LAB_00c118d5:
  *param_5 = (long)param_3;
  *param_8 = local_38;
  if (local_20 == *(long *)(in_FS_OFFSET + 0x28)) {
    return uVar4;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ==== entry=00c11910 name=FUN_00c11910 size=280 ====

undefined8
FUN_00c11910(long param_1,undefined8 param_2,uint *param_3,uint *param_4,long *param_5,
            undefined8 param_6,undefined8 param_7,undefined8 *param_8)

{
  uint uVar1;
  char cVar2;
  long lVar3;
  undefined8 uVar4;
  ulong uVar5;
  long in_FS_OFFSET;
  undefined8 local_38;
  undefined8 local_30;
  long local_20;
  
  local_20 = *(long *)(in_FS_OFFSET + 0x28);
  uVar5 = *(ulong *)(param_1 + 0x10);
  local_30 = param_7;
  local_38 = param_6;
  if (((*(byte *)(param_1 + 0x18) & 2) == 0) || (cVar2 = FUN_00c10de0(&local_38), cVar2 != '\0')) {
    lVar3 = (long)param_4 - (long)param_3;
    if (param_3 != param_4) {
      do {
        uVar1 = *param_3;
        if (uVar1 - 0xd800 < 0x400) {
          if (1 < (ulong)(lVar3 >> 2)) {
            if (param_3[1] - 0xdc00 < 0x400) {
              lVar3 = 2;
              uVar1 = param_3[1] + 0xfca02400 + uVar1 * 0x400;
              goto joined_r0x00c119a9;
            }
LAB_00c119f5:
            uVar4 = 2;
            goto LAB_00c11a05;
          }
          break;
        }
        if (uVar1 - 0xdc00 < 0x400) goto LAB_00c119f5;
        lVar3 = 1;
joined_r0x00c119a9:
        if (uVar5 < uVar1) goto LAB_00c119f5;
        cVar2 = FUN_00c10b40(&local_38);
        if (cVar2 == '\0') goto LAB_00c11a00;
        param_3 = param_3 + lVar3;
        lVar3 = (long)param_4 - (long)param_3;
      } while (param_4 != param_3);
    }
    uVar4 = 0;
  }
  else {
LAB_00c11a00:
    uVar4 = 1;
  }
LAB_00c11a05:
  *param_5 = (long)param_3;
  *param_8 = local_38;
  if (local_20 == *(long *)(in_FS_OFFSET + 0x28)) {
    return uVar4;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ==== entry=00c11a40 name=FUN_00c11a40 size=58 ====

undefined8 FUN_00c11a40(long *param_1)

{
  short *psVar1;
  
  psVar1 = (short *)*param_1;
  if (((2 < (ulong)(param_1[1] - (long)psVar1)) && (*psVar1 == -0x4411)) &&
     ((char)psVar1[1] == -0x41)) {
    *param_1 = (long)psVar1 + 3;
    return 1;
  }
  return 0;
}


// ==== entry=00c11a90 name=FUN_00c11a90 size=316 ====

undefined8
FUN_00c11a90(long param_1,undefined8 param_2,long param_3,long param_4,long *param_5,uint *param_6,
            uint *param_7,long *param_8)

{
  ulong uVar1;
  uint uVar2;
  ulong uVar3;
  undefined8 uVar4;
  long lVar5;
  uint *puVar6;
  long in_FS_OFFSET;
  long local_58;
  long local_50;
  long local_40;
  
  uVar1 = *(ulong *)(param_1 + 0x10);
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  local_58 = param_3;
  local_50 = param_4;
  if ((*(byte *)(param_1 + 0x18) & 4) != 0) {
    FUN_00c11a40(&local_58);
  }
  puVar6 = param_6;
  if (local_50 != local_58) {
    do {
      lVar5 = local_58;
      puVar6 = param_6;
      if (param_7 == param_6) break;
      uVar3 = FUN_00c10480(&local_58,uVar1);
      uVar2 = (uint)uVar3;
      if (uVar2 == 0xfffffffe) {
        uVar4 = 1;
        lVar5 = local_58;
        goto LAB_00c11b49;
      }
      if (uVar1 < (uVar3 & 0xffffffff)) {
        uVar4 = 2;
        lVar5 = local_58;
        goto LAB_00c11b49;
      }
      if (uVar2 < 0x10000) {
        *param_6 = uVar2;
        puVar6 = param_6 + 1;
      }
      else {
        if ((long)param_7 - (long)param_6 == 4) {
          uVar4 = 1;
          goto LAB_00c11b49;
        }
        puVar6 = param_6 + 2;
        param_6[1] = (uint)(ushort)(((ushort)uVar3 & 0x3ff) + 0xdc00);
        *param_6 = (uint)(ushort)((short)(uVar3 >> 10) + 0xd7c0);
      }
      param_6 = puVar6;
    } while (local_50 != local_58);
  }
  uVar4 = 0;
  lVar5 = local_58;
  param_6 = puVar6;
LAB_00c11b49:
  *param_5 = lVar5;
  *param_8 = (long)param_6;
  if (local_40 == *(long *)(in_FS_OFFSET + 0x28)) {
    return uVar4;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ==== entry=00c11bf0 name=FUN_00c11bf0 size=316 ====

undefined8
FUN_00c11bf0(long param_1,undefined8 param_2,long param_3,long param_4,long *param_5,uint *param_6,
            uint *param_7,long *param_8)

{
  ulong uVar1;
  uint uVar2;
  ulong uVar3;
  undefined8 uVar4;
  long lVar5;
  uint *puVar6;
  long in_FS_OFFSET;
  long local_58;
  long local_50;
  long local_40;
  
  uVar1 = *(ulong *)(param_1 + 0x18);
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  local_58 = param_3;
  local_50 = param_4;
  if ((*(byte *)(param_1 + 0x20) & 4) != 0) {
    FUN_00c11a40(&local_58);
  }
  puVar6 = param_6;
  if (local_50 != local_58) {
    do {
      lVar5 = local_58;
      puVar6 = param_6;
      if (param_7 == param_6) break;
      uVar3 = FUN_00c10480(&local_58,uVar1);
      uVar2 = (uint)uVar3;
      if (uVar2 == 0xfffffffe) {
        uVar4 = 1;
        lVar5 = local_58;
        goto LAB_00c11ca9;
      }
      if (uVar1 < (uVar3 & 0xffffffff)) {
        uVar4 = 2;
        lVar5 = local_58;
        goto LAB_00c11ca9;
      }
      if (uVar2 < 0x10000) {
        *param_6 = uVar2;
        puVar6 = param_6 + 1;
      }
      else {
        if ((long)param_7 - (long)param_6 == 4) {
          uVar4 = 1;
          goto LAB_00c11ca9;
        }
        puVar6 = param_6 + 2;
        param_6[1] = (uint)(ushort)(((ushort)uVar3 & 0x3ff) + 0xdc00);
        *param_6 = (uint)(ushort)((short)(uVar3 >> 10) + 0xd7c0);
      }
      param_6 = puVar6;
    } while (local_50 != local_58);
  }
  uVar4 = 0;
  lVar5 = local_58;
  param_6 = puVar6;
LAB_00c11ca9:
  *param_5 = lVar5;
  *param_8 = (long)param_6;
  if (local_40 == *(long *)(in_FS_OFFSET + 0x28)) {
    return uVar4;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ==== entry=00c11d50 name=FUN_00c11d50 size=172 ====

long FUN_00c11d50(long param_1,undefined8 param_2,long param_3,undefined8 param_4,long param_5)

{
  uint uVar1;
  uint uVar2;
  long in_FS_OFFSET;
  long local_48;
  undefined8 local_40;
  long local_30;
  
  uVar2 = (uint)*(undefined8 *)(param_1 + 0x10);
  local_30 = *(long *)(in_FS_OFFSET + 0x28);
  local_48 = param_3;
  local_40 = param_4;
  uVar1 = uVar2;
  if ((*(byte *)(param_1 + 0x18) & 4) != 0) {
    FUN_00c11a40(&local_48);
  }
  if (0xfffe < uVar1) {
    uVar2 = 0xffff;
  }
  if (param_5 != 0) {
    do {
      param_5 = param_5 + -1;
      uVar1 = FUN_00c10480(&local_48,uVar2);
    } while (param_5 != 0 && uVar1 <= uVar2);
  }
  if (local_30 == *(long *)(in_FS_OFFSET + 0x28)) {
    return local_48 - param_3;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ==== entry=00c11e10 name=FUN_00c11e10 size=211 ====

undefined8
FUN_00c11e10(undefined8 param_1,undefined8 param_2,ulong param_3,uint param_4,uint param_5)

{
  uint uVar1;
  ulong uVar2;
  ulong uVar3;
  long in_FS_OFFSET;
  undefined8 local_58;
  undefined8 local_50;
  long local_40;
  
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  local_58 = param_1;
  local_50 = param_2;
  if ((param_5 & 4) != 0) {
    FUN_00c11a40(&local_58);
  }
  if (param_3 < 2) {
    uVar2 = 1;
  }
  else {
    uVar3 = 0;
    uVar2 = 1;
    do {
      uVar1 = FUN_00c10480(&local_58,param_4);
      if (param_4 < uVar1) goto LAB_00c11e86;
      if (uVar1 < 0x10000) {
        uVar2 = uVar3;
      }
      uVar3 = uVar2 + 1;
      uVar2 = uVar2 + 2;
    } while (uVar2 < param_3);
  }
  if (param_3 == uVar2) {
    if (0xfffe < param_4) {
      param_4 = 0xffff;
    }
    FUN_00c10480(&local_58,param_4);
  }
LAB_00c11e86:
  if (local_40 == *(long *)(in_FS_OFFSET + 0x28)) {
    return local_58;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ==== entry=00c11ef0 name=FUN_00c11ef0 size=31 ====

long FUN_00c11ef0(undefined8 param_1,undefined8 param_2,long param_3,undefined8 param_4,
                 undefined8 param_5)

{
  long lVar1;
  
  lVar1 = FUN_00c11e10(param_3,param_4,param_5,0x10ffff,0);
  return lVar1 - param_3;
}


// ==== entry=00c11f10 name=FUN_00c11f10 size=31 ====

long FUN_00c11f10(long param_1,undefined8 param_2,long param_3,undefined8 param_4,undefined8 param_5
                 )

{
  long lVar1;
  
  lVar1 = FUN_00c11e10(param_3,param_4,param_5,*(undefined8 *)(param_1 + 0x10),
                       *(undefined4 *)(param_1 + 0x18));
  return lVar1 - param_3;
}


// ==== entry=00c11f30 name=FUN_00c11f30 size=31 ====

long FUN_00c11f30(long param_1,undefined8 param_2,long param_3,undefined8 param_4,undefined8 param_5
                 )

{
  long lVar1;
  
  lVar1 = FUN_00c11e10(param_3,param_4,param_5,*(undefined8 *)(param_1 + 0x10),
                       *(undefined4 *)(param_1 + 0x18));
  return lVar1 - param_3;
}


// ==== entry=00c11f50 name=FUN_00c11f50 size=31 ====

long FUN_00c11f50(long param_1,undefined8 param_2,long param_3,undefined8 param_4,undefined8 param_5
                 )

{
  long lVar1;
  
  lVar1 = FUN_00c11e10(param_3,param_4,param_5,*(undefined8 *)(param_1 + 0x18),
                       *(undefined4 *)(param_1 + 0x20));
  return lVar1 - param_3;
}


// ==== entry=00c11f70 name=FUN_00c11f70 size=314 ====

char FUN_00c11f70(long *param_1,long *param_2,ulong param_3,uint param_4,int param_5)

{
  ushort *puVar1;
  ushort uVar2;
  ushort uVar3;
  ulong uVar4;
  ushort uVar5;
  long lVar6;
  long lVar7;
  
  if ((param_4 & 4) != 0) {
    FUN_00c11a40();
  }
  while( true ) {
    lVar7 = *param_1;
    lVar6 = param_1[1];
    if (lVar7 == lVar6) {
      return '\0';
    }
    while( true ) {
      if (*param_2 == param_2[1]) {
        return '\0';
      }
      uVar4 = FUN_00c10480(param_1,param_3);
      if ((uint)uVar4 == 0xfffffffe) {
        return (param_5 != 0) + '\x01';
      }
      if (param_3 < (uVar4 & 0xffffffff)) {
        return '\x02';
      }
      puVar1 = (ushort *)*param_2;
      uVar2 = (ushort)uVar4;
      if (0xffff < (uint)uVar4) break;
      if ((ushort *)param_2[1] == puVar1) goto LAB_00c12029;
      lVar7 = *param_1;
      lVar6 = param_1[1];
      if ((param_4 & 1) == 0) {
        uVar2 = uVar2 << 8 | uVar2 >> 8;
      }
      *param_2 = (long)(puVar1 + 1);
      *puVar1 = uVar2;
      if (lVar7 == lVar6) {
        return '\0';
      }
    }
    if ((ulong)(param_2[1] - (long)puVar1) < 4) break;
    uVar3 = (uVar2 & 0x3ff) + 0xdc00;
    uVar5 = (short)(uVar4 >> 10) + 0xd7c0;
    if ((param_4 & 1) == 0) {
      uVar5 = uVar5 * 0x100 | uVar5 >> 8;
      uVar3 = uVar2 << 8 | uVar3 >> 8;
    }
    *puVar1 = uVar5;
    *param_2 = (long)(puVar1 + 2);
    puVar1[1] = uVar3;
  }
LAB_00c12029:
  *param_1 = lVar7;
  param_1[1] = lVar6;
  return '\x01';
}


// ==== entry=00c120d0 name=FUN_00c120d0 size=124 ====

void FUN_00c120d0(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                 undefined8 *param_5,undefined8 param_6,undefined8 param_7,undefined8 *param_8)

{
  long in_FS_OFFSET;
  undefined8 local_48;
  undefined8 local_40;
  undefined8 local_38;
  undefined8 local_30;
  long local_20;
  
  local_20 = *(long *)(in_FS_OFFSET + 0x28);
  local_30 = param_7;
  local_48 = param_3;
  local_40 = param_4;
  local_38 = param_6;
  FUN_00c11f70(&local_48,&local_38,0x10ffff,1,0);
  *param_5 = local_48;
  *param_8 = local_38;
  if (local_20 == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ==== entry=00c12150 name=FUN_00c12150 size=127 ====

void FUN_00c12150(long param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                 undefined8 *param_5,undefined8 param_6,undefined8 param_7,undefined8 *param_8)

{
  long in_FS_OFFSET;
  undefined8 local_48;
  undefined8 local_40;
  undefined8 local_38;
  undefined8 local_30;
  long local_20;
  
  local_20 = *(long *)(in_FS_OFFSET + 0x28);
  local_30 = param_7;
  local_48 = param_3;
  local_40 = param_4;
  local_38 = param_6;
  FUN_00c11f70(&local_48,&local_38,*(undefined8 *)(param_1 + 0x10),*(uint *)(param_1 + 0x18) & 6 | 1
               ,0);
  *param_5 = local_48;
  *param_8 = local_38;
  if (local_20 == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ==== entry=00c121d0 name=FUN_00c121d0 size=146 ====

void FUN_00c121d0(long param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                 undefined8 *param_5,undefined8 param_6,undefined8 param_7,undefined8 *param_8)

{
  ulong uVar1;
  long in_FS_OFFSET;
  undefined8 local_48;
  undefined8 local_40;
  undefined8 local_38;
  undefined8 local_30;
  long local_20;
  
  local_20 = *(long *)(in_FS_OFFSET + 0x28);
  local_30 = param_7;
  uVar1 = *(ulong *)(param_1 + 0x10) & 0xffffffff;
  if (0xfffe < (uint)*(ulong *)(param_1 + 0x10)) {
    uVar1 = 0xffff;
  }
  local_48 = param_3;
  local_40 = param_4;
  local_38 = param_6;
  FUN_00c11f70(&local_48,&local_38,uVar1,*(uint *)(param_1 + 0x18) & 6 | 1,1);
  *param_5 = local_48;
  *param_8 = local_38;
  if (local_20 == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ==== entry=00c12270 name=FUN_00c12270 size=143 ====

undefined8
FUN_00c12270(undefined8 param_1,undefined8 param_2,long param_3,uint param_4,uint param_5)

{
  uint uVar1;
  long in_FS_OFFSET;
  undefined8 local_48;
  undefined8 local_40;
  long local_30;
  
  local_30 = *(long *)(in_FS_OFFSET + 0x28);
  local_48 = param_1;
  local_40 = param_2;
  if ((param_5 & 4) != 0) {
    FUN_00c11a40(&local_48);
  }
  if (param_3 != 0) {
    do {
      param_3 = param_3 + -1;
      uVar1 = FUN_00c10480(&local_48,param_4);
    } while (uVar1 <= param_4 && param_3 != 0);
  }
  if (local_30 == *(long *)(in_FS_OFFSET + 0x28)) {
    return local_48;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ==== entry=00c12310 name=FUN_00c12310 size=31 ====

long FUN_00c12310(undefined8 param_1,undefined8 param_2,long param_3,undefined8 param_4,
                 undefined8 param_5)

{
  long lVar1;
  
  lVar1 = FUN_00c12270(param_3,param_4,param_5,0x10ffff,0);
  return lVar1 - param_3;
}


// ==== entry=00c12330 name=FUN_00c12330 size=31 ====

long FUN_00c12330(long param_1,undefined8 param_2,long param_3,undefined8 param_4,undefined8 param_5
                 )

{
  long lVar1;
  
  lVar1 = FUN_00c12270(param_3,param_4,param_5,*(undefined8 *)(param_1 + 0x10),
                       *(undefined4 *)(param_1 + 0x18));
  return lVar1 - param_3;
}


// ==== entry=00c12350 name=FUN_00c12350 size=31 ====

long FUN_00c12350(long param_1,undefined8 param_2,long param_3,undefined8 param_4,undefined8 param_5
                 )

{
  long lVar1;
  
  lVar1 = FUN_00c12270(param_3,param_4,param_5,*(undefined8 *)(param_1 + 0x18),
                       *(undefined4 *)(param_1 + 0x20));
  return lVar1 - param_3;
}


// ==== entry=00c12370 name=FUN_00c12370 size=125 ====

undefined8 FUN_00c12370(long *param_1,long *param_2,ulong param_3,uint param_4)

{
  uint *puVar1;
  uint *puVar2;
  uint uVar3;
  
  if ((param_4 & 4) != 0) {
    FUN_00c11a40();
  }
  if (param_1[1] == *param_1) {
    return 0;
  }
  if (param_2[1] != *param_2) {
    do {
      uVar3 = FUN_00c10480(param_1,param_3);
      if (uVar3 == 0xfffffffe) {
        return 1;
      }
      if (param_3 < uVar3) {
        return 2;
      }
      puVar2 = (uint *)*param_2;
      puVar1 = puVar2 + 1;
      *param_2 = (long)puVar1;
      *puVar2 = uVar3;
      if (*param_1 == param_1[1]) {
        return 0;
      }
    } while ((uint *)param_2[1] != puVar1);
  }
  return 1;
}


// ==== entry=00c12410 name=FUN_00c12410 size=118 ====

void FUN_00c12410(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                 undefined8 *param_5,undefined8 param_6,undefined8 param_7,undefined8 *param_8)

{
  long in_FS_OFFSET;
  undefined8 local_48;
  undefined8 local_40;
  undefined8 local_38;
  undefined8 local_30;
  long local_20;
  
  local_20 = *(long *)(in_FS_OFFSET + 0x28);
  local_30 = param_7;
  local_48 = param_3;
  local_40 = param_4;
  local_38 = param_6;
  FUN_00c12370(&local_48,&local_38,0x10ffff,0);
  *param_5 = local_48;
  *param_8 = local_38;
  if (local_20 == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ==== entry=00c12490 name=FUN_00c12490 size=118 ====

void FUN_00c12490(long param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                 undefined8 *param_5,undefined8 param_6,undefined8 param_7,undefined8 *param_8)

{
  long in_FS_OFFSET;
  undefined8 local_48;
  undefined8 local_40;
  undefined8 local_38;
  undefined8 local_30;
  long local_20;
  
  local_20 = *(long *)(in_FS_OFFSET + 0x28);
  local_30 = param_7;
  local_48 = param_3;
  local_40 = param_4;
  local_38 = param_6;
  FUN_00c12370(&local_48,&local_38,*(undefined8 *)(param_1 + 0x10),*(undefined4 *)(param_1 + 0x18));
  *param_5 = local_48;
  *param_8 = local_38;
  if (local_20 == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ==== entry=00c12510 name=FUN_00c12510 size=118 ====

void FUN_00c12510(long param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                 undefined8 *param_5,undefined8 param_6,undefined8 param_7,undefined8 *param_8)

{
  long in_FS_OFFSET;
  undefined8 local_48;
  undefined8 local_40;
  undefined8 local_38;
  undefined8 local_30;
  long local_20;
  
  local_20 = *(long *)(in_FS_OFFSET + 0x28);
  local_30 = param_7;
  local_48 = param_3;
  local_40 = param_4;
  local_38 = param_6;
  FUN_00c12370(&local_48,&local_38,*(undefined8 *)(param_1 + 0x18),*(undefined4 *)(param_1 + 0x20));
  *param_5 = local_48;
  *param_8 = local_38;
  if (local_20 == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ==== entry=00c12590 name=FUN_00c12590 size=149 ====

undefined4
FUN_00c12590(long param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
            undefined8 *param_5,undefined8 param_6,undefined8 param_7,undefined8 *param_8)

{
  undefined8 uVar1;
  char cVar2;
  undefined4 uVar3;
  undefined8 *puVar4;
  ulong uVar5;
  long in_FS_OFFSET;
  undefined8 local_38;
  undefined8 local_30;
  undefined8 local_28;
  undefined8 local_20;
  long local_10;
  
  uVar1 = *(undefined8 *)(param_1 + 0x10);
  local_10 = *(long *)(in_FS_OFFSET + 0x28);
  puVar4 = &local_28;
  uVar5 = (ulong)*(uint *)(param_1 + 0x18);
  local_20 = param_7;
  local_38 = param_3;
  local_30 = param_4;
  local_28 = param_6;
  cVar2 = FUN_00c10c50(puVar4,uVar5);
  uVar3 = 1;
  if (cVar2 != '\0') {
    uVar3 = FUN_00c11650(&local_38,puVar4,uVar1,uVar5 & 0xffffffff);
  }
  *param_5 = local_38;
  *param_8 = local_28;
  if (local_10 == *(long *)(in_FS_OFFSET + 0x28)) {
    return uVar3;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ==== entry=00c12630 name=FUN_00c12630 size=145 ====

undefined8
FUN_00c12630(long param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
            undefined8 *param_5,undefined8 param_6,undefined8 param_7,undefined8 *param_8)

{
  char cVar1;
  undefined8 uVar2;
  long in_FS_OFFSET;
  undefined8 local_48;
  undefined8 local_40;
  undefined8 local_38;
  undefined8 local_30;
  long local_20;
  
  local_20 = *(long *)(in_FS_OFFSET + 0x28);
  local_30 = param_7;
  local_48 = param_3;
  local_40 = param_4;
  local_38 = param_6;
  if ((*(byte *)(param_1 + 0x18) & 2) != 0) {
    cVar1 = FUN_00c10de0(&local_38);
    if (cVar1 == '\0') {
      uVar2 = 1;
      goto LAB_00c1268e;
    }
  }
  uVar2 = FUN_00c10e20(&local_48);
LAB_00c1268e:
  *param_5 = local_48;
  *param_8 = local_38;
  if (local_20 == *(long *)(in_FS_OFFSET + 0x28)) {
    return uVar2;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ==== entry=00c126d0 name=FUN_00c126d0 size=140 ====

undefined8
FUN_00c126d0(long param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
            undefined8 *param_5,undefined8 param_6,undefined8 param_7,undefined8 *param_8)

{
  char cVar1;
  undefined8 uVar2;
  long in_FS_OFFSET;
  undefined8 local_38;
  undefined8 local_30;
  undefined8 local_28;
  undefined8 local_20;
  long local_10;
  
  local_10 = *(long *)(in_FS_OFFSET + 0x28);
  local_20 = param_7;
  local_38 = param_3;
  local_30 = param_4;
  local_28 = param_6;
  if ((*(byte *)(param_1 + 0x18) & 2) != 0) {
    cVar1 = FUN_00c10de0(&local_28);
    if (cVar1 == '\0') {
      uVar2 = 1;
      goto LAB_00c1272b;
    }
  }
  uVar2 = FUN_00c11030(&local_38);
LAB_00c1272b:
  *param_5 = local_38;
  *param_8 = local_28;
  if (local_10 == *(long *)(in_FS_OFFSET + 0x28)) {
    return uVar2;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ==== entry=00c12760 name=FUN_00c12760 size=161 ====

long FUN_00c12760(long param_1,undefined8 param_2,long param_3,undefined8 param_4,long param_5)

{
  uint uVar1;
  uint uVar2;
  ulong uVar3;
  long in_FS_OFFSET;
  undefined4 local_3c;
  long local_38;
  undefined8 local_30;
  long local_20;
  
  uVar2 = (uint)*(undefined8 *)(param_1 + 0x10);
  local_20 = *(long *)(in_FS_OFFSET + 0x28);
  local_3c = *(undefined4 *)(param_1 + 0x18);
  local_38 = param_3;
  local_30 = param_4;
  FUN_00c111a0(&local_38,&local_3c);
  uVar3 = (ulong)uVar2;
  if (param_5 != 0) {
    do {
      param_5 = param_5 + -1;
      uVar1 = FUN_00c109c0(&local_38,uVar3,local_3c);
    } while (uVar1 <= uVar2 && param_5 != 0);
  }
  if (local_20 == *(long *)(in_FS_OFFSET + 0x28)) {
    return local_38 - param_3;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ==== entry=00c12810 orig=FUN_00c12810 size=44 name=showmanyc ====

/* std::stringbuf::showmanyc() */

long __thiscall std::stringbuf::showmanyc(stringbuf *this)

{
  ulong uVar1;
  ulong uVar2;
  
  if (((byte)this[0x40] & 8) != 0) {
    uVar1 = *(ulong *)(this + 0x28);
    uVar2 = *(ulong *)(this + 0x18);
    if ((uVar1 != 0) && (uVar2 < uVar1)) {
      *(ulong *)(this + 0x18) = uVar1;
      uVar2 = uVar1;
    }
    return uVar2 - *(long *)(this + 0x10);
  }
  return -1;
}


// ==== entry=00c12840 orig=FUN_00c12840 size=52 name=underflow ====

/* std::stringbuf::underflow() */

ulong __thiscall std::stringbuf::underflow(stringbuf *this)

{
  byte *pbVar1;
  byte *pbVar2;
  
  if (((byte)this[0x40] & 8) != 0) {
    pbVar1 = *(byte **)(this + 0x28);
    pbVar2 = *(byte **)(this + 0x18);
    if ((pbVar1 != (byte *)0x0) && (pbVar2 < pbVar1)) {
      *(byte **)(this + 0x18) = pbVar1;
      pbVar2 = pbVar1;
    }
    if (*(byte **)(this + 0x10) < pbVar2) {
      return (ulong)**(byte **)(this + 0x10);
    }
  }
  return 0xffffffff;
}


// ==== entry=00c12880 orig=FUN_00c12880 size=67 name=pbackfail ====

/* std::stringbuf::pbackfail(int) */

int __thiscall std::stringbuf::pbackfail(stringbuf *this,int param_1)

{
  char cVar1;
  ulong uVar2;
  char cVar3;
  
  uVar2 = *(ulong *)(this + 0x10);
  if (*(ulong *)(this + 8) < uVar2) {
    if (param_1 == -1) {
      *(ulong *)(this + 0x10) = uVar2 - 1;
      return 0;
    }
    cVar1 = *(char *)(uVar2 - 1);
    cVar3 = (char)param_1;
    if ((((byte)this[0x40] & 0x10) != 0) || (cVar1 == cVar3)) {
      *(ulong *)(this + 0x10) = uVar2 - 1;
      if (cVar1 == cVar3) {
        return param_1;
      }
      *(char *)(uVar2 - 1) = cVar3;
      return param_1;
    }
  }
  return -1;
}


// ==== entry=00c128d0 orig=FUN_00c128d0 size=48 name=showmanyc ====

/* std::wstringbuf::showmanyc() */

long __thiscall std::wstringbuf::showmanyc(wstringbuf *this)

{
  ulong uVar1;
  ulong uVar2;
  
  if (((byte)this[0x40] & 8) != 0) {
    uVar1 = *(ulong *)(this + 0x28);
    uVar2 = *(ulong *)(this + 0x18);
    if ((uVar1 != 0) && (uVar2 < uVar1)) {
      *(ulong *)(this + 0x18) = uVar1;
      uVar2 = uVar1;
    }
    return (long)(uVar2 - *(long *)(this + 0x10)) >> 2;
  }
  return -1;
}


// ==== entry=00c12910 orig=FUN_00c12910 size=62 name=pbackfail ====

/* std::wstringbuf::pbackfail(unsigned int) */

uint __thiscall std::wstringbuf::pbackfail(wstringbuf *this,uint param_1)

{
  uint uVar1;
  ulong uVar2;
  uint uVar3;
  
  uVar2 = *(ulong *)(this + 0x10);
  uVar3 = 0xffffffff;
  if (*(ulong *)(this + 8) < uVar2) {
    if (param_1 == 0xffffffff) {
      *(ulong *)(this + 0x10) = uVar2 - 4;
      return 0;
    }
    uVar1 = *(uint *)(uVar2 - 4);
    if ((((byte)this[0x40] & 0x10) != 0) || (uVar1 == param_1)) {
      *(ulong *)(this + 0x10) = uVar2 - 4;
      uVar3 = param_1;
      if (uVar1 != param_1) {
        *(uint *)(uVar2 - 4) = param_1;
        return param_1;
      }
    }
  }
  return uVar3;
}


// ==== entry=00c12960 orig=FUN_00c12960 size=49 name=underflow ====

/* std::wstringbuf::underflow() */

undefined4 __thiscall std::wstringbuf::underflow(wstringbuf *this)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  
  if (((byte)this[0x40] & 8) != 0) {
    puVar1 = *(undefined4 **)(this + 0x28);
    puVar2 = *(undefined4 **)(this + 0x18);
    if ((puVar1 != (undefined4 *)0x0) && (puVar2 < puVar1)) {
      *(undefined4 **)(this + 0x18) = puVar1;
      puVar2 = puVar1;
    }
    if (*(undefined4 **)(this + 0x10) < puVar2) {
      return **(undefined4 **)(this + 0x10);
    }
  }
  return 0xffffffff;
}


// ==== entry=00c129a0 orig=FUN_00c129a0 size=152 name=~wstringbuf ====

/* WARNING: Removing unreachable block (ram,0x00c12a30) */
/* std::wstringbuf::~wstringbuf() */

void __thiscall std::wstringbuf::~wstringbuf(wstringbuf *this)

{
  allocator *paVar1;
  int *piVar2;
  int iVar3;
  long lVar4;
  long in_FS_OFFSET;
  
  lVar4 = *(long *)(in_FS_OFFSET + 0x28);
  *(undefined ***)this = &PTR__wstringbuf_011b4a60;
  paVar1 = (allocator *)(*(long *)(this + 0x48) + -0x18);
  if (paVar1 != (allocator *)&wstring::_Rep::_S_empty_rep_storage) {
    LOCK();
    piVar2 = (int *)(*(long *)(this + 0x48) + -8);
    iVar3 = *piVar2;
    *piVar2 = *piVar2 + -1;
    UNLOCK();
    if (iVar3 < 1) {
      wstring::_Rep::_M_destroy(paVar1);
    }
  }
  *(undefined ***)this = &PTR__wstreambuf_011b2be8;
  locale::~locale((locale *)(this + 0x38));
  if (lVar4 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


// ==== entry=00c12a40 orig=FUN_00c12a40 size=258 name=~stringstream ====

/* WARNING: Removing unreachable block (ram,0x00c12b40) */
/* non-virtual thunk to std::stringstream::~stringstream() */

void __thiscall std::stringstream::~stringstream(stringstream *this)

{
  allocator *paVar1;
  int *piVar2;
  int iVar3;
  long lVar4;
  long in_FS_OFFSET;
  
  lVar4 = *(long *)(in_FS_OFFSET + 0x28);
  *(undefined8 *)(this + -0x10) = 0x11b49f0;
  *(undefined8 *)this = 0x11b4a18;
  *(undefined8 *)(this + 0x58) = 0x11b4a40;
  *(undefined ***)(this + 8) = &PTR__stringbuf_011b4680;
  paVar1 = (allocator *)(*(long *)(this + 0x50) + -0x18);
  if (paVar1 != (allocator *)&string::_Rep::_S_empty_rep_storage) {
    LOCK();
    piVar2 = (int *)(*(long *)(this + 0x50) + -8);
    iVar3 = *piVar2;
    *piVar2 = *piVar2 + -1;
    UNLOCK();
    if (iVar3 < 1) {
      string::_Rep::_M_destroy(paVar1);
    }
  }
  *(undefined ***)(this + 8) = &PTR__streambuf_011b2b68;
  locale::~locale((locale *)(this + 0x40));
  *(undefined8 *)(this + -8) = 0;
  *(undefined **)this = &DAT_011b4888;
  *(undefined **)(this + -0x10) = &DAT_011b48d8;
  *(undefined ***)(this + 0x58) = &PTR__ios_011b4e70;
  ios_base::~ios_base((ios_base *)(this + 0x58));
  operator_delete(this + -0x10);
  if (lVar4 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


// ==== entry=00c12b50 orig=FUN_00c12b50 size=259 name=~stringstream ====

/* WARNING: Removing unreachable block (ram,0x00c12c50) */
/* virtual thunk to std::stringstream::~stringstream() */

void __thiscall std::stringstream::~stringstream(stringstream *this)

{
  allocator *paVar1;
  int *piVar2;
  int iVar3;
  long lVar4;
  stringstream *psVar5;
  long in_FS_OFFSET;
  
  lVar4 = *(long *)(in_FS_OFFSET + 0x28);
  psVar5 = this + *(long *)(*(long *)this + -0x18);
  *(undefined8 *)psVar5 = 0x11b49f0;
  *(undefined8 *)(psVar5 + 0x10) = 0x11b4a18;
  *(undefined8 *)(psVar5 + 0x68) = 0x11b4a40;
  *(undefined ***)(psVar5 + 0x18) = &PTR__stringbuf_011b4680;
  paVar1 = (allocator *)(*(long *)(psVar5 + 0x60) + -0x18);
  if (paVar1 != (allocator *)&string::_Rep::_S_empty_rep_storage) {
    LOCK();
    piVar2 = (int *)(*(long *)(psVar5 + 0x60) + -8);
    iVar3 = *piVar2;
    *piVar2 = *piVar2 + -1;
    UNLOCK();
    if (iVar3 < 1) {
      string::_Rep::_M_destroy(paVar1);
    }
  }
  *(undefined ***)(psVar5 + 0x18) = &PTR__streambuf_011b2b68;
  locale::~locale((locale *)(psVar5 + 0x50));
  *(undefined8 *)(psVar5 + 8) = 0;
  *(undefined **)(psVar5 + 0x10) = &DAT_011b4888;
  *(undefined **)psVar5 = &DAT_011b48d8;
  *(undefined ***)(psVar5 + 0x68) = &PTR__ios_011b4e70;
  ios_base::~ios_base((ios_base *)(psVar5 + 0x68));
  operator_delete(psVar5);
  if (lVar4 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


// ==== entry=00c12c60 orig=FUN_00c12c60 size=252 name=~stringstream ====

/* WARNING: Removing unreachable block (ram,0x00c12d58) */
/* std::stringstream::~stringstream() */

void __thiscall std::stringstream::~stringstream(stringstream *this)

{
  allocator *paVar1;
  int *piVar2;
  int iVar3;
  long lVar4;
  long in_FS_OFFSET;
  
  lVar4 = *(long *)(in_FS_OFFSET + 0x28);
  *(undefined8 *)this = 0x11b49f0;
  *(undefined8 *)(this + 0x10) = 0x11b4a18;
  *(undefined8 *)(this + 0x68) = 0x11b4a40;
  *(undefined ***)(this + 0x18) = &PTR__stringbuf_011b4680;
  paVar1 = (allocator *)(*(long *)(this + 0x60) + -0x18);
  if (paVar1 != (allocator *)&string::_Rep::_S_empty_rep_storage) {
    LOCK();
    piVar2 = (int *)(*(long *)(this + 0x60) + -8);
    iVar3 = *piVar2;
    *piVar2 = *piVar2 + -1;
    UNLOCK();
    if (iVar3 < 1) {
      string::_Rep::_M_destroy(paVar1);
    }
  }
  *(undefined ***)(this + 0x18) = &PTR__streambuf_011b2b68;
  locale::~locale((locale *)(this + 0x50));
  *(undefined8 *)(this + 8) = 0;
  *(undefined **)(this + 0x10) = &DAT_011b4888;
  *(undefined **)this = &DAT_011b48d8;
  *(undefined ***)(this + 0x68) = &PTR__ios_011b4e70;
  ios_base::~ios_base((ios_base *)(this + 0x68));
  operator_delete(this);
  if (lVar4 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


// ==== entry=00c12d70 orig=FUN_00c12d70 size=225 name=~ostringstream ====

/* WARNING: Removing unreachable block (ram,0x00c12e48) */
/* virtual thunk to std::ostringstream::~ostringstream() */

void __thiscall std::ostringstream::~ostringstream(ostringstream *this)

{
  allocator *paVar1;
  int *piVar2;
  int iVar3;
  long lVar4;
  ostringstream *poVar5;
  long in_FS_OFFSET;
  
  lVar4 = *(long *)(in_FS_OFFSET + 0x28);
  poVar5 = this + *(long *)(*(long *)this + -0x18);
  *(undefined ***)(poVar5 + 0x58) = &PTR__ostringstream_011b4860;
  *(undefined ***)poVar5 = &PTR__ostringstream_011b4838;
  *(undefined ***)(poVar5 + 8) = &PTR__stringbuf_011b4680;
  paVar1 = (allocator *)(*(long *)(poVar5 + 0x50) + -0x18);
  if (paVar1 != (allocator *)&string::_Rep::_S_empty_rep_storage) {
    LOCK();
    piVar2 = (int *)(*(long *)(poVar5 + 0x50) + -8);
    iVar3 = *piVar2;
    *piVar2 = *piVar2 + -1;
    UNLOCK();
    if (iVar3 < 1) {
      string::_Rep::_M_destroy(paVar1);
    }
  }
  *(undefined ***)(poVar5 + 8) = &PTR__streambuf_011b2b68;
  locale::~locale((locale *)(poVar5 + 0x40));
  *(undefined **)poVar5 = &DAT_011b47c8;
  *(undefined ***)(poVar5 + 0x58) = &PTR__ios_011b4e70;
  ios_base::~ios_base((ios_base *)(poVar5 + 0x58));
  operator_delete(poVar5);
  if (lVar4 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


// ==== entry=00c12e60 orig=FUN_00c12e60 size=221 name=~ostringstream ====

/* WARNING: Removing unreachable block (ram,0x00c12f40) */
/* std::ostringstream::~ostringstream() */

void __thiscall std::ostringstream::~ostringstream(ostringstream *this)

{
  allocator *paVar1;
  int *piVar2;
  int iVar3;
  long lVar4;
  long in_FS_OFFSET;
  
  lVar4 = *(long *)(in_FS_OFFSET + 0x28);
  *(undefined ***)(this + 0x58) = &PTR__ostringstream_011b4860;
  *(undefined ***)this = &PTR__ostringstream_011b4838;
  *(undefined ***)(this + 8) = &PTR__stringbuf_011b4680;
  paVar1 = (allocator *)(*(long *)(this + 0x50) + -0x18);
  if (paVar1 != (allocator *)&string::_Rep::_S_empty_rep_storage) {
    LOCK();
    piVar2 = (int *)(*(long *)(this + 0x50) + -8);
    iVar3 = *piVar2;
    *piVar2 = *piVar2 + -1;
    UNLOCK();
    if (iVar3 < 1) {
      string::_Rep::_M_destroy(paVar1);
    }
  }
  *(undefined ***)(this + 8) = &PTR__streambuf_011b2b68;
  locale::~locale((locale *)(this + 0x40));
  *(undefined **)this = &DAT_011b47c8;
  *(undefined ***)(this + 0x58) = &PTR__ios_011b4e70;
  ios_base::~ios_base((ios_base *)(this + 0x58));
  operator_delete(this);
  if (lVar4 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


// ==== entry=00c12f50 orig=FUN_00c12f50 size=217 name=~ostringstream ====

/* WARNING: Removing unreachable block (ram,0x00c13020) */
/* virtual thunk to std::ostringstream::~ostringstream() */

void __thiscall std::ostringstream::~ostringstream(ostringstream *this)

{
  allocator *paVar1;
  int *piVar2;
  int iVar3;
  long lVar4;
  ostringstream *poVar5;
  long in_FS_OFFSET;
  
  lVar4 = *(long *)(in_FS_OFFSET + 0x28);
  poVar5 = this + *(long *)(*(long *)this + -0x18);
  *(undefined ***)(poVar5 + 0x58) = &PTR__ostringstream_011b4860;
  *(undefined ***)poVar5 = &PTR__ostringstream_011b4838;
  *(undefined ***)(poVar5 + 8) = &PTR__stringbuf_011b4680;
  paVar1 = (allocator *)(*(long *)(poVar5 + 0x50) + -0x18);
  if (paVar1 != (allocator *)&string::_Rep::_S_empty_rep_storage) {
    LOCK();
    piVar2 = (int *)(*(long *)(poVar5 + 0x50) + -8);
    iVar3 = *piVar2;
    *piVar2 = *piVar2 + -1;
    UNLOCK();
    if (iVar3 < 1) {
      string::_Rep::_M_destroy(paVar1);
    }
  }
  *(undefined ***)(poVar5 + 8) = &PTR__streambuf_011b2b68;
  locale::~locale((locale *)(poVar5 + 0x40));
  *(undefined **)poVar5 = &DAT_011b47c8;
  *(undefined ***)(poVar5 + 0x58) = &PTR__ios_011b4e70;
  ios_base::~ios_base((ios_base *)(poVar5 + 0x58));
  if (lVar4 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


// ==== entry=00c13030 orig=FUN_00c13030 size=210 name=~ostringstream ====

/* WARNING: Removing unreachable block (ram,0x00c130f8) */
/* std::ostringstream::~ostringstream() */

void __thiscall std::ostringstream::~ostringstream(ostringstream *this)

{
  allocator *paVar1;
  int *piVar2;
  int iVar3;
  long lVar4;
  long in_FS_OFFSET;
  
  lVar4 = *(long *)(in_FS_OFFSET + 0x28);
  *(undefined ***)(this + 0x58) = &PTR__ostringstream_011b4860;
  *(undefined ***)this = &PTR__ostringstream_011b4838;
  *(undefined ***)(this + 8) = &PTR__stringbuf_011b4680;
  paVar1 = (allocator *)(*(long *)(this + 0x50) + -0x18);
  if (paVar1 != (allocator *)&string::_Rep::_S_empty_rep_storage) {
    LOCK();
    piVar2 = (int *)(*(long *)(this + 0x50) + -8);
    iVar3 = *piVar2;
    *piVar2 = *piVar2 + -1;
    UNLOCK();
    if (iVar3 < 1) {
      string::_Rep::_M_destroy(paVar1);
    }
  }
  *(undefined ***)(this + 8) = &PTR__streambuf_011b2b68;
  locale::~locale((locale *)(this + 0x40));
  *(undefined **)this = &DAT_011b47c8;
  *(undefined ***)(this + 0x58) = &PTR__ios_011b4e70;
  ios_base::~ios_base((ios_base *)(this + 0x58));
  if (lVar4 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


// ==== entry=00c13110 orig=FUN_00c13110 size=258 name=~wstringstream ====

/* WARNING: Removing unreachable block (ram,0x00c13210) */
/* non-virtual thunk to std::wstringstream::~wstringstream() */

void __thiscall std::wstringstream::~wstringstream(wstringstream *this)

{
  allocator *paVar1;
  int *piVar2;
  int iVar3;
  long lVar4;
  long in_FS_OFFSET;
  
  lVar4 = *(long *)(in_FS_OFFSET + 0x28);
  *(undefined8 *)(this + -0x10) = 0x11b4dd0;
  *(undefined8 *)this = 0x11b4df8;
  *(undefined8 *)(this + 0x58) = 0x11b4e20;
  *(undefined ***)(this + 8) = &PTR__wstringbuf_011b4a60;
  paVar1 = (allocator *)(*(long *)(this + 0x50) + -0x18);
  if (paVar1 != (allocator *)&wstring::_Rep::_S_empty_rep_storage) {
    LOCK();
    piVar2 = (int *)(*(long *)(this + 0x50) + -8);
    iVar3 = *piVar2;
    *piVar2 = *piVar2 + -1;
    UNLOCK();
    if (iVar3 < 1) {
      wstring::_Rep::_M_destroy(paVar1);
    }
  }
  *(undefined ***)(this + 8) = &PTR__wstreambuf_011b2be8;
  locale::~locale((locale *)(this + 0x40));
  *(undefined8 *)(this + -8) = 0;
  *(undefined **)this = &DAT_011b4c68;
  *(undefined **)(this + -0x10) = &DAT_011b4cb8;
  *(undefined ***)(this + 0x58) = &PTR__wios_011b4e90;
  ios_base::~ios_base((ios_base *)(this + 0x58));
  operator_delete(this + -0x10);
  if (lVar4 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


// ==== entry=00c13220 orig=FUN_00c13220 size=259 name=~wstringstream ====

/* WARNING: Removing unreachable block (ram,0x00c13320) */
/* virtual thunk to std::wstringstream::~wstringstream() */

void __thiscall std::wstringstream::~wstringstream(wstringstream *this)

{
  allocator *paVar1;
  int *piVar2;
  int iVar3;
  long lVar4;
  wstringstream *pwVar5;
  long in_FS_OFFSET;
  
  lVar4 = *(long *)(in_FS_OFFSET + 0x28);
  pwVar5 = this + *(long *)(*(long *)this + -0x18);
  *(undefined8 *)pwVar5 = 0x11b4dd0;
  *(undefined8 *)(pwVar5 + 0x10) = 0x11b4df8;
  *(undefined8 *)(pwVar5 + 0x68) = 0x11b4e20;
  *(undefined ***)(pwVar5 + 0x18) = &PTR__wstringbuf_011b4a60;
  paVar1 = (allocator *)(*(long *)(pwVar5 + 0x60) + -0x18);
  if (paVar1 != (allocator *)&wstring::_Rep::_S_empty_rep_storage) {
    LOCK();
    piVar2 = (int *)(*(long *)(pwVar5 + 0x60) + -8);
    iVar3 = *piVar2;
    *piVar2 = *piVar2 + -1;
    UNLOCK();
    if (iVar3 < 1) {
      wstring::_Rep::_M_destroy(paVar1);
    }
  }
  *(undefined ***)(pwVar5 + 0x18) = &PTR__wstreambuf_011b2be8;
  locale::~locale((locale *)(pwVar5 + 0x50));
  *(undefined8 *)(pwVar5 + 8) = 0;
  *(undefined **)(pwVar5 + 0x10) = &DAT_011b4c68;
  *(undefined **)pwVar5 = &DAT_011b4cb8;
  *(undefined ***)(pwVar5 + 0x68) = &PTR__wios_011b4e90;
  ios_base::~ios_base((ios_base *)(pwVar5 + 0x68));
  operator_delete(pwVar5);
  if (lVar4 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


// ==== entry=00c13330 orig=FUN_00c13330 size=252 name=~wstringstream ====

/* WARNING: Removing unreachable block (ram,0x00c13428) */
/* std::wstringstream::~wstringstream() */

void __thiscall std::wstringstream::~wstringstream(wstringstream *this)

{
  allocator *paVar1;
  int *piVar2;
  int iVar3;
  long lVar4;
  long in_FS_OFFSET;
  
  lVar4 = *(long *)(in_FS_OFFSET + 0x28);
  *(undefined8 *)this = 0x11b4dd0;
  *(undefined8 *)(this + 0x10) = 0x11b4df8;
  *(undefined8 *)(this + 0x68) = 0x11b4e20;
  *(undefined ***)(this + 0x18) = &PTR__wstringbuf_011b4a60;
  paVar1 = (allocator *)(*(long *)(this + 0x60) + -0x18);
  if (paVar1 != (allocator *)&wstring::_Rep::_S_empty_rep_storage) {
    LOCK();
    piVar2 = (int *)(*(long *)(this + 0x60) + -8);
    iVar3 = *piVar2;
    *piVar2 = *piVar2 + -1;
    UNLOCK();
    if (iVar3 < 1) {
      wstring::_Rep::_M_destroy(paVar1);
    }
  }
  *(undefined ***)(this + 0x18) = &PTR__wstreambuf_011b2be8;
  locale::~locale((locale *)(this + 0x50));
  *(undefined8 *)(this + 8) = 0;
  *(undefined **)(this + 0x10) = &DAT_011b4c68;
  *(undefined **)this = &DAT_011b4cb8;
  *(undefined ***)(this + 0x68) = &PTR__wios_011b4e90;
  ios_base::~ios_base((ios_base *)(this + 0x68));
  operator_delete(this);
  if (lVar4 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


// ==== entry=00c13440 orig=FUN_00c13440 size=225 name=~istringstream ====

/* WARNING: Removing unreachable block (ram,0x00c13518) */
/* virtual thunk to std::istringstream::~istringstream() */

void __thiscall std::istringstream::~istringstream(istringstream *this)

{
  allocator *paVar1;
  int *piVar2;
  int iVar3;
  long lVar4;
  istringstream *piVar5;
  long in_FS_OFFSET;
  
  lVar4 = *(long *)(in_FS_OFFSET + 0x28);
  piVar5 = this + *(long *)(*(long *)this + -0x18);
  *(undefined8 *)(piVar5 + 0x60) = 0x11b47a0;
  *(undefined8 *)piVar5 = 0x11b4778;
  *(undefined ***)(piVar5 + 0x10) = &PTR__stringbuf_011b4680;
  paVar1 = (allocator *)(*(long *)(piVar5 + 0x58) + -0x18);
  if (paVar1 != (allocator *)&string::_Rep::_S_empty_rep_storage) {
    LOCK();
    piVar2 = (int *)(*(long *)(piVar5 + 0x58) + -8);
    iVar3 = *piVar2;
    *piVar2 = *piVar2 + -1;
    UNLOCK();
    if (iVar3 < 1) {
      string::_Rep::_M_destroy(paVar1);
    }
  }
  *(undefined ***)(piVar5 + 0x10) = &PTR__streambuf_011b2b68;
  locale::~locale((locale *)(piVar5 + 0x48));
  *(undefined8 *)(piVar5 + 8) = 0;
  *(undefined **)piVar5 = &DAT_011b4708;
  *(undefined ***)(piVar5 + 0x60) = &PTR__ios_011b4e70;
  ios_base::~ios_base((ios_base *)(piVar5 + 0x60));
  if (lVar4 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


// ==== entry=00c13530 orig=FUN_00c13530 size=221 name=~istringstream ====

/* WARNING: Removing unreachable block (ram,0x00c13610) */
/* std::istringstream::~istringstream() */

void __thiscall std::istringstream::~istringstream(istringstream *this)

{
  allocator *paVar1;
  int *piVar2;
  int iVar3;
  long lVar4;
  long in_FS_OFFSET;
  
  lVar4 = *(long *)(in_FS_OFFSET + 0x28);
  *(undefined8 *)(this + 0x60) = 0x11b47a0;
  *(undefined8 *)this = 0x11b4778;
  *(undefined ***)(this + 0x10) = &PTR__stringbuf_011b4680;
  paVar1 = (allocator *)(*(long *)(this + 0x58) + -0x18);
  if (paVar1 != (allocator *)&string::_Rep::_S_empty_rep_storage) {
    LOCK();
    piVar2 = (int *)(*(long *)(this + 0x58) + -8);
    iVar3 = *piVar2;
    *piVar2 = *piVar2 + -1;
    UNLOCK();
    if (iVar3 < 1) {
      string::_Rep::_M_destroy(paVar1);
    }
  }
  *(undefined ***)(this + 0x10) = &PTR__streambuf_011b2b68;
  locale::~locale((locale *)(this + 0x48));
  *(undefined8 *)(this + 8) = 0;
  *(undefined **)this = &DAT_011b4708;
  *(undefined ***)(this + 0x60) = &PTR__ios_011b4e70;
  ios_base::~ios_base((ios_base *)(this + 0x60));
  if (lVar4 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


// ==== entry=00c13620 orig=FUN_00c13620 size=236 name=~wistringstream ====

/* WARNING: Removing unreachable block (ram,0x00c13700) */
/* virtual thunk to std::wistringstream::~wistringstream() */

void __thiscall std::wistringstream::~wistringstream(wistringstream *this)

{
  allocator *paVar1;
  int *piVar2;
  int iVar3;
  long lVar4;
  wistringstream *pwVar5;
  long in_FS_OFFSET;
  
  lVar4 = *(long *)(in_FS_OFFSET + 0x28);
  pwVar5 = this + *(long *)(*(long *)this + -0x18);
  *(undefined8 *)(pwVar5 + 0x60) = 0x11b4b80;
  *(undefined8 *)pwVar5 = 0x11b4b58;
  *(undefined ***)(pwVar5 + 0x10) = &PTR__wstringbuf_011b4a60;
  paVar1 = (allocator *)(*(long *)(pwVar5 + 0x58) + -0x18);
  if (paVar1 != (allocator *)&wstring::_Rep::_S_empty_rep_storage) {
    LOCK();
    piVar2 = (int *)(*(long *)(pwVar5 + 0x58) + -8);
    iVar3 = *piVar2;
    *piVar2 = *piVar2 + -1;
    UNLOCK();
    if (iVar3 < 1) {
      wstring::_Rep::_M_destroy(paVar1);
    }
  }
  *(undefined ***)(pwVar5 + 0x10) = &PTR__wstreambuf_011b2be8;
  locale::~locale((locale *)(pwVar5 + 0x48));
  *(undefined8 *)(pwVar5 + 8) = 0;
  *(undefined **)pwVar5 = &DAT_011b4ae8;
  *(undefined ***)(pwVar5 + 0x60) = &PTR__wios_011b4e90;
  ios_base::~ios_base((ios_base *)(pwVar5 + 0x60));
  operator_delete(pwVar5);
  if (lVar4 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


// ==== entry=00c13710 orig=FUN_00c13710 size=229 name=~wistringstream ====

/* WARNING: Removing unreachable block (ram,0x00c137f0) */
/* std::wistringstream::~wistringstream() */

void __thiscall std::wistringstream::~wistringstream(wistringstream *this)

{
  allocator *paVar1;
  int *piVar2;
  int iVar3;
  long lVar4;
  long in_FS_OFFSET;
  
  lVar4 = *(long *)(in_FS_OFFSET + 0x28);
  *(undefined8 *)(this + 0x60) = 0x11b4b80;
  *(undefined8 *)this = 0x11b4b58;
  *(undefined ***)(this + 0x10) = &PTR__wstringbuf_011b4a60;
  paVar1 = (allocator *)(*(long *)(this + 0x58) + -0x18);
  if (paVar1 != (allocator *)&wstring::_Rep::_S_empty_rep_storage) {
    LOCK();
    piVar2 = (int *)(*(long *)(this + 0x58) + -8);
    iVar3 = *piVar2;
    *piVar2 = *piVar2 + -1;
    UNLOCK();
    if (iVar3 < 1) {
      wstring::_Rep::_M_destroy(paVar1);
    }
  }
  *(undefined ***)(this + 0x10) = &PTR__wstreambuf_011b2be8;
  locale::~locale((locale *)(this + 0x48));
  *(undefined8 *)(this + 8) = 0;
  *(undefined **)this = &DAT_011b4ae8;
  *(undefined ***)(this + 0x60) = &PTR__wios_011b4e90;
  ios_base::~ios_base((ios_base *)(this + 0x60));
  operator_delete(this);
  if (lVar4 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


// ==== entry=00c13800 orig=FUN_00c13800 size=244 name=~stringstream ====

/* WARNING: Removing unreachable block (ram,0x00c138f0) */
/* non-virtual thunk to std::stringstream::~stringstream() */

void __thiscall std::stringstream::~stringstream(stringstream *this)

{
  allocator *paVar1;
  int *piVar2;
  int iVar3;
  long lVar4;
  long in_FS_OFFSET;
  
  lVar4 = *(long *)(in_FS_OFFSET + 0x28);
  *(undefined8 *)(this + -0x10) = 0x11b49f0;
  *(undefined8 *)this = 0x11b4a18;
  *(undefined8 *)(this + 0x58) = 0x11b4a40;
  *(undefined ***)(this + 8) = &PTR__stringbuf_011b4680;
  paVar1 = (allocator *)(*(long *)(this + 0x50) + -0x18);
  if (paVar1 != (allocator *)&string::_Rep::_S_empty_rep_storage) {
    LOCK();
    piVar2 = (int *)(*(long *)(this + 0x50) + -8);
    iVar3 = *piVar2;
    *piVar2 = *piVar2 + -1;
    UNLOCK();
    if (iVar3 < 1) {
      string::_Rep::_M_destroy(paVar1);
    }
  }
  *(undefined ***)(this + 8) = &PTR__streambuf_011b2b68;
  locale::~locale((locale *)(this + 0x40));
  *(undefined8 *)(this + -8) = 0;
  *(undefined **)this = &DAT_011b4888;
  *(undefined **)(this + -0x10) = &DAT_011b48d8;
  *(undefined ***)(this + 0x58) = &PTR__ios_011b4e70;
  ios_base::~ios_base((ios_base *)(this + 0x58));
  if (lVar4 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


// ==== entry=00c13900 orig=FUN_00c13900 size=247 name=~stringstream ====

/* WARNING: Removing unreachable block (ram,0x00c139f0) */
/* virtual thunk to std::stringstream::~stringstream() */

void __thiscall std::stringstream::~stringstream(stringstream *this)

{
  allocator *paVar1;
  int *piVar2;
  int iVar3;
  long lVar4;
  stringstream *psVar5;
  long in_FS_OFFSET;
  
  lVar4 = *(long *)(in_FS_OFFSET + 0x28);
  psVar5 = this + *(long *)(*(long *)this + -0x18);
  *(undefined8 *)psVar5 = 0x11b49f0;
  *(undefined8 *)(psVar5 + 0x10) = 0x11b4a18;
  *(undefined8 *)(psVar5 + 0x68) = 0x11b4a40;
  *(undefined ***)(psVar5 + 0x18) = &PTR__stringbuf_011b4680;
  paVar1 = (allocator *)(*(long *)(psVar5 + 0x60) + -0x18);
  if (paVar1 != (allocator *)&string::_Rep::_S_empty_rep_storage) {
    LOCK();
    piVar2 = (int *)(*(long *)(psVar5 + 0x60) + -8);
    iVar3 = *piVar2;
    *piVar2 = *piVar2 + -1;
    UNLOCK();
    if (iVar3 < 1) {
      string::_Rep::_M_destroy(paVar1);
    }
  }
  *(undefined ***)(psVar5 + 0x18) = &PTR__streambuf_011b2b68;
  locale::~locale((locale *)(psVar5 + 0x50));
  *(undefined8 *)(psVar5 + 8) = 0;
  *(undefined **)(psVar5 + 0x10) = &DAT_011b4888;
  *(undefined **)psVar5 = &DAT_011b48d8;
  *(undefined ***)(psVar5 + 0x68) = &PTR__ios_011b4e70;
  ios_base::~ios_base((ios_base *)(psVar5 + 0x68));
  if (lVar4 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


// ==== entry=00c13a00 orig=FUN_00c13a00 size=244 name=~stringstream ====

/* WARNING: Removing unreachable block (ram,0x00c13af0) */
/* std::stringstream::~stringstream() */

void __thiscall std::stringstream::~stringstream(stringstream *this)

{
  allocator *paVar1;
  int *piVar2;
  int iVar3;
  long lVar4;
  long in_FS_OFFSET;
  
  lVar4 = *(long *)(in_FS_OFFSET + 0x28);
  *(undefined8 *)this = 0x11b49f0;
  *(undefined8 *)(this + 0x10) = 0x11b4a18;
  *(undefined8 *)(this + 0x68) = 0x11b4a40;
  *(undefined ***)(this + 0x18) = &PTR__stringbuf_011b4680;
  paVar1 = (allocator *)(*(long *)(this + 0x60) + -0x18);
  if (paVar1 != (allocator *)&string::_Rep::_S_empty_rep_storage) {
    LOCK();
    piVar2 = (int *)(*(long *)(this + 0x60) + -8);
    iVar3 = *piVar2;
    *piVar2 = *piVar2 + -1;
    UNLOCK();
    if (iVar3 < 1) {
      string::_Rep::_M_destroy(paVar1);
    }
  }
  *(undefined ***)(this + 0x18) = &PTR__streambuf_011b2b68;
  locale::~locale((locale *)(this + 0x50));
  *(undefined8 *)(this + 8) = 0;
  *(undefined **)(this + 0x10) = &DAT_011b4888;
  *(undefined **)this = &DAT_011b48d8;
  *(undefined ***)(this + 0x68) = &PTR__ios_011b4e70;
  ios_base::~ios_base((ios_base *)(this + 0x68));
  if (lVar4 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


// ==== entry=00c13b00 orig=FUN_00c13b00 size=236 name=~istringstream ====

/* WARNING: Removing unreachable block (ram,0x00c13be0) */
/* virtual thunk to std::istringstream::~istringstream() */

void __thiscall std::istringstream::~istringstream(istringstream *this)

{
  allocator *paVar1;
  int *piVar2;
  int iVar3;
  long lVar4;
  istringstream *piVar5;
  long in_FS_OFFSET;
  
  lVar4 = *(long *)(in_FS_OFFSET + 0x28);
  piVar5 = this + *(long *)(*(long *)this + -0x18);
  *(undefined8 *)(piVar5 + 0x60) = 0x11b47a0;
  *(undefined8 *)piVar5 = 0x11b4778;
  *(undefined ***)(piVar5 + 0x10) = &PTR__stringbuf_011b4680;
  paVar1 = (allocator *)(*(long *)(piVar5 + 0x58) + -0x18);
  if (paVar1 != (allocator *)&string::_Rep::_S_empty_rep_storage) {
    LOCK();
    piVar2 = (int *)(*(long *)(piVar5 + 0x58) + -8);
    iVar3 = *piVar2;
    *piVar2 = *piVar2 + -1;
    UNLOCK();
    if (iVar3 < 1) {
      string::_Rep::_M_destroy(paVar1);
    }
  }
  *(undefined ***)(piVar5 + 0x10) = &PTR__streambuf_011b2b68;
  locale::~locale((locale *)(piVar5 + 0x48));
  *(undefined8 *)(piVar5 + 8) = 0;
  *(undefined **)piVar5 = &DAT_011b4708;
  *(undefined ***)(piVar5 + 0x60) = &PTR__ios_011b4e70;
  ios_base::~ios_base((ios_base *)(piVar5 + 0x60));
  operator_delete(piVar5);
  if (lVar4 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


// ==== entry=00c13bf0 orig=FUN_00c13bf0 size=229 name=~istringstream ====

/* WARNING: Removing unreachable block (ram,0x00c13cd0) */
/* std::istringstream::~istringstream() */

void __thiscall std::istringstream::~istringstream(istringstream *this)

{
  allocator *paVar1;
  int *piVar2;
  int iVar3;
  long lVar4;
  long in_FS_OFFSET;
  
  lVar4 = *(long *)(in_FS_OFFSET + 0x28);
  *(undefined8 *)(this + 0x60) = 0x11b47a0;
  *(undefined8 *)this = 0x11b4778;
  *(undefined ***)(this + 0x10) = &PTR__stringbuf_011b4680;
  paVar1 = (allocator *)(*(long *)(this + 0x58) + -0x18);
  if (paVar1 != (allocator *)&string::_Rep::_S_empty_rep_storage) {
    LOCK();
    piVar2 = (int *)(*(long *)(this + 0x58) + -8);
    iVar3 = *piVar2;
    *piVar2 = *piVar2 + -1;
    UNLOCK();
    if (iVar3 < 1) {
      string::_Rep::_M_destroy(paVar1);
    }
  }
  *(undefined ***)(this + 0x10) = &PTR__streambuf_011b2b68;
  locale::~locale((locale *)(this + 0x48));
  *(undefined8 *)(this + 8) = 0;
  *(undefined **)this = &DAT_011b4708;
  *(undefined ***)(this + 0x60) = &PTR__ios_011b4e70;
  ios_base::~ios_base((ios_base *)(this + 0x60));
  operator_delete(this);
  if (lVar4 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


// ==== entry=00c13ce0 orig=FUN_00c13ce0 size=225 name=~wostringstream ====

/* WARNING: Removing unreachable block (ram,0x00c13db8) */
/* virtual thunk to std::wostringstream::~wostringstream() */

void __thiscall std::wostringstream::~wostringstream(wostringstream *this)

{
  allocator *paVar1;
  int *piVar2;
  int iVar3;
  long lVar4;
  wostringstream *pwVar5;
  long in_FS_OFFSET;
  
  lVar4 = *(long *)(in_FS_OFFSET + 0x28);
  pwVar5 = this + *(long *)(*(long *)this + -0x18);
  *(undefined8 *)(pwVar5 + 0x58) = 0x11b4c40;
  *(undefined8 *)pwVar5 = 0x11b4c18;
  *(undefined ***)(pwVar5 + 8) = &PTR__wstringbuf_011b4a60;
  paVar1 = (allocator *)(*(long *)(pwVar5 + 0x50) + -0x18);
  if (paVar1 != (allocator *)&wstring::_Rep::_S_empty_rep_storage) {
    LOCK();
    piVar2 = (int *)(*(long *)(pwVar5 + 0x50) + -8);
    iVar3 = *piVar2;
    *piVar2 = *piVar2 + -1;
    UNLOCK();
    if (iVar3 < 1) {
      wstring::_Rep::_M_destroy(paVar1);
    }
  }
  *(undefined ***)(pwVar5 + 8) = &PTR__wstreambuf_011b2be8;
  locale::~locale((locale *)(pwVar5 + 0x40));
  *(undefined **)pwVar5 = &DAT_011b4ba8;
  *(undefined ***)(pwVar5 + 0x58) = &PTR__wios_011b4e90;
  ios_base::~ios_base((ios_base *)(pwVar5 + 0x58));
  operator_delete(pwVar5);
  if (lVar4 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


// ==== entry=00c13dd0 orig=FUN_00c13dd0 size=221 name=~wostringstream ====

/* WARNING: Removing unreachable block (ram,0x00c13eb0) */
/* std::wostringstream::~wostringstream() */

void __thiscall std::wostringstream::~wostringstream(wostringstream *this)

{
  allocator *paVar1;
  int *piVar2;
  int iVar3;
  long lVar4;
  long in_FS_OFFSET;
  
  lVar4 = *(long *)(in_FS_OFFSET + 0x28);
  *(undefined8 *)(this + 0x58) = 0x11b4c40;
  *(undefined8 *)this = 0x11b4c18;
  *(undefined ***)(this + 8) = &PTR__wstringbuf_011b4a60;
  paVar1 = (allocator *)(*(long *)(this + 0x50) + -0x18);
  if (paVar1 != (allocator *)&wstring::_Rep::_S_empty_rep_storage) {
    LOCK();
    piVar2 = (int *)(*(long *)(this + 0x50) + -8);
    iVar3 = *piVar2;
    *piVar2 = *piVar2 + -1;
    UNLOCK();
    if (iVar3 < 1) {
      wstring::_Rep::_M_destroy(paVar1);
    }
  }
  *(undefined ***)(this + 8) = &PTR__wstreambuf_011b2be8;
  locale::~locale((locale *)(this + 0x40));
  *(undefined **)this = &DAT_011b4ba8;
  *(undefined ***)(this + 0x58) = &PTR__wios_011b4e90;
  ios_base::~ios_base((ios_base *)(this + 0x58));
  operator_delete(this);
  if (lVar4 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


// ==== entry=00c13ec0 orig=FUN_00c13ec0 size=217 name=~wostringstream ====

/* WARNING: Removing unreachable block (ram,0x00c13f90) */
/* virtual thunk to std::wostringstream::~wostringstream() */

void __thiscall std::wostringstream::~wostringstream(wostringstream *this)

{
  allocator *paVar1;
  int *piVar2;
  int iVar3;
  long lVar4;
  wostringstream *pwVar5;
  long in_FS_OFFSET;
  
  lVar4 = *(long *)(in_FS_OFFSET + 0x28);
  pwVar5 = this + *(long *)(*(long *)this + -0x18);
  *(undefined8 *)(pwVar5 + 0x58) = 0x11b4c40;
  *(undefined8 *)pwVar5 = 0x11b4c18;
  *(undefined ***)(pwVar5 + 8) = &PTR__wstringbuf_011b4a60;
  paVar1 = (allocator *)(*(long *)(pwVar5 + 0x50) + -0x18);
  if (paVar1 != (allocator *)&wstring::_Rep::_S_empty_rep_storage) {
    LOCK();
    piVar2 = (int *)(*(long *)(pwVar5 + 0x50) + -8);
    iVar3 = *piVar2;
    *piVar2 = *piVar2 + -1;
    UNLOCK();
    if (iVar3 < 1) {
      wstring::_Rep::_M_destroy(paVar1);
    }
  }
  *(undefined ***)(pwVar5 + 8) = &PTR__wstreambuf_011b2be8;
  locale::~locale((locale *)(pwVar5 + 0x40));
  *(undefined **)pwVar5 = &DAT_011b4ba8;
  *(undefined ***)(pwVar5 + 0x58) = &PTR__wios_011b4e90;
  ios_base::~ios_base((ios_base *)(pwVar5 + 0x58));
  if (lVar4 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


// ==== entry=00c13fa0 orig=FUN_00c13fa0 size=210 name=~wostringstream ====

/* WARNING: Removing unreachable block (ram,0x00c14068) */
/* std::wostringstream::~wostringstream() */

void __thiscall std::wostringstream::~wostringstream(wostringstream *this)

{
  allocator *paVar1;
  int *piVar2;
  int iVar3;
  long lVar4;
  long in_FS_OFFSET;
  
  lVar4 = *(long *)(in_FS_OFFSET + 0x28);
  *(undefined8 *)(this + 0x58) = 0x11b4c40;
  *(undefined8 *)this = 0x11b4c18;
  *(undefined ***)(this + 8) = &PTR__wstringbuf_011b4a60;
  paVar1 = (allocator *)(*(long *)(this + 0x50) + -0x18);
  if (paVar1 != (allocator *)&wstring::_Rep::_S_empty_rep_storage) {
    LOCK();
    piVar2 = (int *)(*(long *)(this + 0x50) + -8);
    iVar3 = *piVar2;
    *piVar2 = *piVar2 + -1;
    UNLOCK();
    if (iVar3 < 1) {
      wstring::_Rep::_M_destroy(paVar1);
    }
  }
  *(undefined ***)(this + 8) = &PTR__wstreambuf_011b2be8;
  locale::~locale((locale *)(this + 0x40));
  *(undefined **)this = &DAT_011b4ba8;
  *(undefined ***)(this + 0x58) = &PTR__wios_011b4e90;
  ios_base::~ios_base((ios_base *)(this + 0x58));
  if (lVar4 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


// ==== entry=00c14080 orig=FUN_00c14080 size=225 name=~wistringstream ====

/* WARNING: Removing unreachable block (ram,0x00c14158) */
/* virtual thunk to std::wistringstream::~wistringstream() */

void __thiscall std::wistringstream::~wistringstream(wistringstream *this)

{
  allocator *paVar1;
  int *piVar2;
  int iVar3;
  long lVar4;
  wistringstream *pwVar5;
  long in_FS_OFFSET;
  
  lVar4 = *(long *)(in_FS_OFFSET + 0x28);
  pwVar5 = this + *(long *)(*(long *)this + -0x18);
  *(undefined8 *)(pwVar5 + 0x60) = 0x11b4b80;
  *(undefined8 *)pwVar5 = 0x11b4b58;
  *(undefined ***)(pwVar5 + 0x10) = &PTR__wstringbuf_011b4a60;
  paVar1 = (allocator *)(*(long *)(pwVar5 + 0x58) + -0x18);
  if (paVar1 != (allocator *)&wstring::_Rep::_S_empty_rep_storage) {
    LOCK();
    piVar2 = (int *)(*(long *)(pwVar5 + 0x58) + -8);
    iVar3 = *piVar2;
    *piVar2 = *piVar2 + -1;
    UNLOCK();
    if (iVar3 < 1) {
      wstring::_Rep::_M_destroy(paVar1);
    }
  }
  *(undefined ***)(pwVar5 + 0x10) = &PTR__wstreambuf_011b2be8;
  locale::~locale((locale *)(pwVar5 + 0x48));
  *(undefined8 *)(pwVar5 + 8) = 0;
  *(undefined **)pwVar5 = &DAT_011b4ae8;
  *(undefined ***)(pwVar5 + 0x60) = &PTR__wios_011b4e90;
  ios_base::~ios_base((ios_base *)(pwVar5 + 0x60));
  if (lVar4 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


// ==== entry=00c14170 orig=FUN_00c14170 size=221 name=~wistringstream ====

/* WARNING: Removing unreachable block (ram,0x00c14250) */
/* std::wistringstream::~wistringstream() */

void __thiscall std::wistringstream::~wistringstream(wistringstream *this)

{
  allocator *paVar1;
  int *piVar2;
  int iVar3;
  long lVar4;
  long in_FS_OFFSET;
  
  lVar4 = *(long *)(in_FS_OFFSET + 0x28);
  *(undefined8 *)(this + 0x60) = 0x11b4b80;
  *(undefined8 *)this = 0x11b4b58;
  *(undefined ***)(this + 0x10) = &PTR__wstringbuf_011b4a60;
  paVar1 = (allocator *)(*(long *)(this + 0x58) + -0x18);
  if (paVar1 != (allocator *)&wstring::_Rep::_S_empty_rep_storage) {
    LOCK();
    piVar2 = (int *)(*(long *)(this + 0x58) + -8);
    iVar3 = *piVar2;
    *piVar2 = *piVar2 + -1;
    UNLOCK();
    if (iVar3 < 1) {
      wstring::_Rep::_M_destroy(paVar1);
    }
  }
  *(undefined ***)(this + 0x10) = &PTR__wstreambuf_011b2be8;
  locale::~locale((locale *)(this + 0x48));
  *(undefined8 *)(this + 8) = 0;
  *(undefined **)this = &DAT_011b4ae8;
  *(undefined ***)(this + 0x60) = &PTR__wios_011b4e90;
  ios_base::~ios_base((ios_base *)(this + 0x60));
  if (lVar4 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


// ==== entry=00c14260 orig=FUN_00c14260 size=244 name=~wstringstream ====

/* WARNING: Removing unreachable block (ram,0x00c14350) */
/* non-virtual thunk to std::wstringstream::~wstringstream() */

void __thiscall std::wstringstream::~wstringstream(wstringstream *this)

{
  allocator *paVar1;
  int *piVar2;
  int iVar3;
  long lVar4;
  long in_FS_OFFSET;
  
  lVar4 = *(long *)(in_FS_OFFSET + 0x28);
  *(undefined8 *)(this + -0x10) = 0x11b4dd0;
  *(undefined8 *)this = 0x11b4df8;
  *(undefined8 *)(this + 0x58) = 0x11b4e20;
  *(undefined ***)(this + 8) = &PTR__wstringbuf_011b4a60;
  paVar1 = (allocator *)(*(long *)(this + 0x50) + -0x18);
  if (paVar1 != (allocator *)&wstring::_Rep::_S_empty_rep_storage) {
    LOCK();
    piVar2 = (int *)(*(long *)(this + 0x50) + -8);
    iVar3 = *piVar2;
    *piVar2 = *piVar2 + -1;
    UNLOCK();
    if (iVar3 < 1) {
      wstring::_Rep::_M_destroy(paVar1);
    }
  }
  *(undefined ***)(this + 8) = &PTR__wstreambuf_011b2be8;
  locale::~locale((locale *)(this + 0x40));
  *(undefined8 *)(this + -8) = 0;
  *(undefined **)this = &DAT_011b4c68;
  *(undefined **)(this + -0x10) = &DAT_011b4cb8;
  *(undefined ***)(this + 0x58) = &PTR__wios_011b4e90;
  ios_base::~ios_base((ios_base *)(this + 0x58));
  if (lVar4 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


// ==== entry=00c14360 orig=FUN_00c14360 size=247 name=~wstringstream ====

/* WARNING: Removing unreachable block (ram,0x00c14450) */
/* virtual thunk to std::wstringstream::~wstringstream() */

void __thiscall std::wstringstream::~wstringstream(wstringstream *this)

{
  allocator *paVar1;
  int *piVar2;
  int iVar3;
  long lVar4;
  wstringstream *pwVar5;
  long in_FS_OFFSET;
  
  lVar4 = *(long *)(in_FS_OFFSET + 0x28);
  pwVar5 = this + *(long *)(*(long *)this + -0x18);
  *(undefined8 *)pwVar5 = 0x11b4dd0;
  *(undefined8 *)(pwVar5 + 0x10) = 0x11b4df8;
  *(undefined8 *)(pwVar5 + 0x68) = 0x11b4e20;
  *(undefined ***)(pwVar5 + 0x18) = &PTR__wstringbuf_011b4a60;
  paVar1 = (allocator *)(*(long *)(pwVar5 + 0x60) + -0x18);
  if (paVar1 != (allocator *)&wstring::_Rep::_S_empty_rep_storage) {
    LOCK();
    piVar2 = (int *)(*(long *)(pwVar5 + 0x60) + -8);
    iVar3 = *piVar2;
    *piVar2 = *piVar2 + -1;
    UNLOCK();
    if (iVar3 < 1) {
      wstring::_Rep::_M_destroy(paVar1);
    }
  }
  *(undefined ***)(pwVar5 + 0x18) = &PTR__wstreambuf_011b2be8;
  locale::~locale((locale *)(pwVar5 + 0x50));
  *(undefined8 *)(pwVar5 + 8) = 0;
  *(undefined **)(pwVar5 + 0x10) = &DAT_011b4c68;
  *(undefined **)pwVar5 = &DAT_011b4cb8;
  *(undefined ***)(pwVar5 + 0x68) = &PTR__wios_011b4e90;
  ios_base::~ios_base((ios_base *)(pwVar5 + 0x68));
  if (lVar4 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


// ==== entry=00c14460 orig=FUN_00c14460 size=244 name=~wstringstream ====

/* WARNING: Removing unreachable block (ram,0x00c14550) */
/* std::wstringstream::~wstringstream() */

void __thiscall std::wstringstream::~wstringstream(wstringstream *this)

{
  allocator *paVar1;
  int *piVar2;
  int iVar3;
  long lVar4;
  long in_FS_OFFSET;
  
  lVar4 = *(long *)(in_FS_OFFSET + 0x28);
  *(undefined8 *)this = 0x11b4dd0;
  *(undefined8 *)(this + 0x10) = 0x11b4df8;
  *(undefined8 *)(this + 0x68) = 0x11b4e20;
  *(undefined ***)(this + 0x18) = &PTR__wstringbuf_011b4a60;
  paVar1 = (allocator *)(*(long *)(this + 0x60) + -0x18);
  if (paVar1 != (allocator *)&wstring::_Rep::_S_empty_rep_storage) {
    LOCK();
    piVar2 = (int *)(*(long *)(this + 0x60) + -8);
    iVar3 = *piVar2;
    *piVar2 = *piVar2 + -1;
    UNLOCK();
    if (iVar3 < 1) {
      wstring::_Rep::_M_destroy(paVar1);
    }
  }
  *(undefined ***)(this + 0x18) = &PTR__wstreambuf_011b2be8;
  locale::~locale((locale *)(this + 0x50));
  *(undefined8 *)(this + 8) = 0;
  *(undefined **)(this + 0x10) = &DAT_011b4c68;
  *(undefined **)this = &DAT_011b4cb8;
  *(undefined ***)(this + 0x68) = &PTR__wios_011b4e90;
  ios_base::~ios_base((ios_base *)(this + 0x68));
  if (lVar4 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


// ==== entry=00c14560 orig=FUN_00c14560 size=160 name=~wstringbuf ====

/* WARNING: Removing unreachable block (ram,0x00c145f8) */
/* std::wstringbuf::~wstringbuf() */

void __thiscall std::wstringbuf::~wstringbuf(wstringbuf *this)

{
  allocator *paVar1;
  int *piVar2;
  int iVar3;
  long lVar4;
  long in_FS_OFFSET;
  
  lVar4 = *(long *)(in_FS_OFFSET + 0x28);
  *(undefined ***)this = &PTR__wstringbuf_011b4a60;
  paVar1 = (allocator *)(*(long *)(this + 0x48) + -0x18);
  if (paVar1 != (allocator *)&wstring::_Rep::_S_empty_rep_storage) {
    LOCK();
    piVar2 = (int *)(*(long *)(this + 0x48) + -8);
    iVar3 = *piVar2;
    *piVar2 = *piVar2 + -1;
    UNLOCK();
    if (iVar3 < 1) {
      wstring::_Rep::_M_destroy(paVar1);
    }
  }
  *(undefined ***)this = &PTR__wstreambuf_011b2be8;
  locale::~locale((locale *)(this + 0x38));
  operator_delete(this);
  if (lVar4 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


// ==== entry=00c14610 orig=FUN_00c14610 size=122 name=stringbuf ====

/* std::stringbuf::stringbuf(std::_Ios_Openmode) */

void __thiscall std::stringbuf::stringbuf(stringbuf *this,undefined4 param_2)

{
  *(undefined8 *)(this + 8) = 0;
  *(undefined8 *)(this + 0x10) = 0;
  *(undefined8 *)(this + 0x18) = 0;
  *(undefined ***)this = &PTR__streambuf_011b2b68;
  *(undefined8 *)(this + 0x20) = 0;
  *(undefined8 *)(this + 0x28) = 0;
  *(undefined8 *)(this + 0x30) = 0;
  locale::locale((locale *)(this + 0x38));
  *(undefined4 *)(this + 0x40) = param_2;
  *(undefined ***)this = &PTR__stringbuf_011b4680;
  *(undefined1 **)(this + 0x48) = &DAT_011c5338;
  return;
}


// ==== entry=00c14690 name=FUN_00c14690 size=373 ====

void FUN_00c14690(long *param_1,long *param_2)

{
  locale *this;
  locale *this_00;
  long lVar1;
  long in_FS_OFFSET;
  locale local_58 [8];
  locale local_50 [8];
  locale local_48 [8];
  long local_40;
  
  this = (locale *)(param_2 + 7);
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  lVar1 = param_1[1];
  param_1[1] = param_2[1];
  param_2[1] = lVar1;
  lVar1 = param_1[2];
  param_1[2] = param_2[2];
  param_2[2] = lVar1;
  lVar1 = param_1[3];
  param_1[3] = param_2[3];
  param_2[3] = lVar1;
  lVar1 = param_1[4];
  param_1[4] = param_2[4];
  param_2[4] = lVar1;
  lVar1 = param_1[5];
  param_1[5] = param_2[5];
  param_2[5] = lVar1;
  lVar1 = param_1[6];
  param_1[6] = param_2[6];
  param_2[6] = lVar1;
  this_00 = (locale *)(param_1 + 7);
  std::locale::locale(local_48,this_00);
  std::locale::operator=(this_00,this);
  std::locale::operator=(this,local_48);
  std::locale::~locale(local_48);
  std::locale::locale(local_58,this);
  std::locale::locale(local_50,this_00);
                    /* try { // try from 00c1477d to 00c1477f has its CatchHandler @ 00c1480a */
  (**(code **)(*param_1 + 0x10))(param_1,local_58);
  std::locale::operator=(this_00,local_58);
  std::locale::locale(local_48,this);
                    /* try { // try from 00c147a2 to 00c147a4 has its CatchHandler @ 00c14805 */
  (**(code **)(*param_2 + 0x10))(param_2,local_50);
  std::locale::operator=(this,local_50);
  std::locale::~locale(local_48);
  std::locale::~locale(local_50);
  std::locale::~locale(local_58);
  lVar1 = param_1[8];
  *(int *)(param_1 + 8) = (int)param_2[8];
  *(int *)(param_2 + 8) = (int)lVar1;
  std::string::swap((string *)(param_1 + 9),(string *)(param_2 + 9));
  if (local_40 == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ==== entry=00c14840 orig=FUN_00c14840 size=150 name=str ====

/* std::stringbuf::str() const */

void std::stringbuf::str(void)

{
  ulong uVar1;
  char *pcVar2;
  long in_RSI;
  string *in_RDI;
  long in_FS_OFFSET;
  allocator local_21;
  long local_20;
  
  local_20 = *(long *)(in_FS_OFFSET + 0x28);
  string::string(in_RDI,&local_21);
  uVar1 = *(ulong *)(in_RSI + 0x28);
  if (uVar1 == 0) {
    string::assign(in_RDI,(string *)(in_RSI + 0x48));
  }
  else {
    pcVar2 = *(char **)(in_RSI + 0x20);
    if (*(ulong *)(in_RSI + 0x18) < uVar1) {
      string::s_basic_string__replace_52baa6
                (in_RDI,0,*(ulong *)(*(long *)in_RDI + -0x18),pcVar2,uVar1 - (long)pcVar2);
    }
    else {
                    /* try { // try from 00c14890 to 00c148db has its CatchHandler @ 00c148e3 */
      string::s_basic_string__replace_52baa6
                (in_RDI,0,*(ulong *)(*(long *)in_RDI + -0x18),pcVar2,
                 *(ulong *)(in_RSI + 0x18) - (long)pcVar2);
    }
  }
  if (local_20 == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ==== entry=00c14910 orig=FUN_00c14910 size=40 name=_M_update_egptr ====

/* std::stringbuf::_M_update_egptr() */

void __thiscall std::stringbuf::_M_update_egptr(stringbuf *this)

{
  ulong uVar1;
  
  uVar1 = *(ulong *)(this + 0x28);
  if ((uVar1 != 0) && (*(ulong *)(this + 0x18) < uVar1)) {
    if (((byte)this[0x40] & 8) == 0) {
      *(ulong *)(this + 8) = uVar1;
      *(ulong *)(this + 0x10) = uVar1;
      *(ulong *)(this + 0x18) = uVar1;
    }
    else {
      *(ulong *)(this + 0x18) = uVar1;
    }
  }
  return;
}


// ==== entry=00c14940 orig=FUN_00c14940 size=65 name=_M_pbump ====

/* std::stringbuf::_M_pbump(char*, char*, long) */

void __thiscall std::stringbuf::_M_pbump(stringbuf *this,char *param_1,char *param_2,long param_3)

{
  long lVar1;
  char *pcVar2;
  
  *(char **)(this + 0x28) = param_1;
  *(char **)(this + 0x20) = param_1;
  *(char **)(this + 0x30) = param_2;
  pcVar2 = param_1;
  if (0x7fffffff < param_3) {
    lVar1 = param_3 + 0x7fffffff;
    do {
      pcVar2 = param_1 + (lVar1 - param_3);
      param_3 = param_3 + -0x7fffffff;
    } while (0x7fffffff < param_3);
  }
  *(char **)(this + 0x28) = pcVar2 + (int)param_3;
  return;
}


// ==== entry=00c14990 orig=FUN_00c14990 size=136 name=_M_sync ====

/* std::stringbuf::_M_sync(char*, unsigned long, unsigned long) */

void __thiscall std::stringbuf::_M_sync(stringbuf *this,char *param_1,ulong param_2,ulong param_3)

{
  char *pcVar1;
  uint uVar2;
  char *pcVar3;
  char *pcVar4;
  
  pcVar1 = *(char **)(this + 0x48);
  uVar2 = *(uint *)(this + 0x40) & 0x10;
  pcVar3 = param_1 + *(long *)(pcVar1 + -0x18);
  pcVar4 = param_1 + *(long *)(pcVar1 + -0x10);
  if (pcVar1 != param_1) {
    pcVar3 = pcVar3 + param_2;
    param_2 = 0;
    pcVar4 = pcVar3;
  }
  if ((*(uint *)(this + 0x40) & 8) == 0) {
    if (uVar2 != 0) {
      _M_pbump(this,param_1,pcVar4,param_3);
      *(char **)(this + 8) = pcVar3;
      *(char **)(this + 0x10) = pcVar3;
      *(char **)(this + 0x18) = pcVar3;
      return;
    }
  }
  else {
    *(char **)(this + 8) = param_1;
    *(char **)(this + 0x10) = param_1 + param_2;
    *(char **)(this + 0x18) = pcVar3;
    if (uVar2 != 0) {
      _M_pbump(this,param_1,pcVar4,param_3);
      return;
    }
  }
  return;
}


// ==== entry=00c14a30 orig=FUN_00c14a30 size=26 name=_M_stringbuf_init ====

/* std::stringbuf::_M_stringbuf_init(std::_Ios_Openmode) */

void __thiscall std::stringbuf::_M_stringbuf_init(stringbuf *this,uint param_2)

{
  ulong uVar1;
  
  *(uint *)(this + 0x40) = param_2;
  uVar1 = 0;
  if ((param_2 & 3) != 0) {
    uVar1 = *(ulong *)(*(char **)(this + 0x48) + -0x18);
  }
  _M_sync(this,*(char **)(this + 0x48),0,uVar1);
  return;
}


// ==== entry=00c14a50 name=FUN_00c14a50 size=187 ====

streambuf * FUN_00c14a50(streambuf *param_1,streambuf *param_2)

{
  long in_FS_OFFSET;
  locale local_40 [8];
  locale local_38 [8];
  long local_30;
  
  local_30 = *(long *)(in_FS_OFFSET + 0x28);
  std::streambuf::operator=(param_1,param_2);
  std::locale::locale(local_40,(locale *)(param_2 + 0x38));
  std::locale::locale(local_38,(locale *)(param_1 + 0x38));
                    /* try { // try from 00c14aa5 to 00c14aa7 has its CatchHandler @ 00c14b0b */
  (**(code **)(*(long *)param_1 + 0x10))(param_1,local_40);
  std::locale::operator=((locale *)(param_1 + 0x38),local_40);
  std::locale::~locale(local_38);
  std::locale::~locale(local_40);
  *(undefined4 *)(param_1 + 0x40) = *(undefined4 *)(param_2 + 0x40);
  std::string::swap((string *)(param_1 + 0x48),(string *)(param_2 + 0x48));
  std::stringbuf::_M_sync((stringbuf *)param_2,*(char **)(param_2 + 0x48),0,0);
  if (local_30 == *(long *)(in_FS_OFFSET + 0x28)) {
    return param_1;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ==== entry=00c14b30 orig=FUN_00c14b30 size=448 name=overflow ====

/* WARNING: Removing unreachable block (ram,0x00c14cf0) */
/* std::stringbuf::overflow(int) */

int __thiscall std::stringbuf::overflow(stringbuf *this,int param_1)

{
  int *piVar1;
  int iVar2;
  long lVar3;
  char *pcVar4;
  ulong uVar5;
  long in_FS_OFFSET;
  allocator local_49;
  undefined1 *local_48;
  long local_40;
  
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  if (((byte)this[0x40] & 0x10) == 0) {
LAB_00c14b98:
    param_1 = -1;
  }
  else {
    if (param_1 == -1) {
      param_1 = 0;
      goto LAB_00c14b72;
    }
    if (*(undefined1 **)(this + 0x28) < *(undefined1 **)(this + 0x30)) {
      **(undefined1 **)(this + 0x28) = (char)param_1;
    }
    else {
      lVar3 = *(long *)(*(long *)(this + 0x48) + -0x10);
      if (lVar3 == 0x3ffffffffffffff9) goto LAB_00c14b98;
      string::string((string *)&local_48,&local_49);
      uVar5 = lVar3 * 2;
      if (0x3ffffffffffffff9 < uVar5) {
        uVar5 = 0x3ffffffffffffff9;
      }
      if (uVar5 < 0x200) {
        uVar5 = 0x200;
      }
                    /* try { // try from 00c14bfe to 00c14c97 has its CatchHandler @ 00c14d00 */
      string::reserve((string *)&local_48,uVar5);
      pcVar4 = *(char **)(this + 0x20);
      if (pcVar4 != (char *)0x0) {
        string::s_basic_string__assign_65a9ea
                  ((string *)&local_48,pcVar4,*(long *)(this + 0x30) - (long)pcVar4);
      }
      lVar3 = *(long *)(local_48 + -0x18);
      uVar5 = lVar3 + 1;
      if ((*(ulong *)(local_48 + -0x10) < uVar5) || (0 < *(int *)(local_48 + -8))) {
        string::reserve((string *)&local_48,uVar5);
      }
      local_48[*(long *)(local_48 + -0x18)] = (char)param_1;
      if (local_48 != &DAT_011c5338) {
        *(undefined4 *)(local_48 + -8) = 0;
        *(ulong *)(local_48 + -0x18) = uVar5;
        local_48[lVar3 + 1] = 0;
      }
      string::swap((string *)(this + 0x48),(string *)&local_48);
      _M_sync(this,*(char **)(this + 0x48),*(long *)(this + 0x10) - *(long *)(this + 8),
              *(long *)(this + 0x28) - *(long *)(this + 0x20));
      if ((allocator *)(local_48 + -0x18) != (allocator *)&string::_Rep::_S_empty_rep_storage) {
        LOCK();
        piVar1 = (int *)(local_48 + -8);
        iVar2 = *piVar1;
        *piVar1 = *piVar1 + -1;
        UNLOCK();
        if (iVar2 < 1) {
          string::_Rep::_M_destroy((allocator *)(local_48 + -0x18));
        }
      }
    }
    *(long *)(this + 0x28) = *(long *)(this + 0x28) + 1;
  }
LAB_00c14b72:
  if (local_40 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_1;
}


// ==== entry=00c14d30 orig=FUN_00c14d30 size=222 name=setbuf ====

/* WARNING: Removing unreachable block (ram,0x00c14e0e) */
/* std::stringbuf::setbuf(char*, long) */

stringbuf * __thiscall std::stringbuf::setbuf(stringbuf *this,char *param_1,long param_2)

{
  int *piVar1;
  int iVar2;
  long lVar3;
  undefined1 *puVar4;
  long in_FS_OFFSET;
  
  lVar3 = *(long *)(in_FS_OFFSET + 0x28);
  if ((param_1 != (char *)0x0) && (-1 < param_2)) {
    puVar4 = *(undefined1 **)(this + 0x48);
    if (*(int *)(*(long *)(this + 0x48) + -8) < 1) {
      if (puVar4 != &DAT_011c5338) {
        *(undefined4 *)(puVar4 + -8) = 0;
        *(undefined8 *)(puVar4 + -0x18) = 0;
        *puVar4 = 0;
      }
    }
    else {
      if ((allocator *)(puVar4 + -0x18) != (allocator *)&string::_Rep::_S_empty_rep_storage) {
        LOCK();
        piVar1 = (int *)(puVar4 + -8);
        iVar2 = *piVar1;
        *piVar1 = *piVar1 + -1;
        UNLOCK();
        if (iVar2 < 1) {
          string::_Rep::_M_destroy((allocator *)(puVar4 + -0x18));
        }
      }
      *(undefined1 **)(this + 0x48) = &DAT_011c5338;
    }
    _M_sync(this,param_1,param_2,0);
  }
  if (lVar3 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return this;
}


// ==== entry=00c14e20 name=FUN_00c14e20 size=80 ====

void FUN_00c14e20(streambuf *param_1,streambuf *param_2)

{
  std::streambuf::streambuf(param_1,param_2);
  *(undefined ***)param_1 = &PTR__stringbuf_011b4680;
  *(undefined4 *)(param_1 + 0x40) = *(undefined4 *)(param_2 + 0x40);
  *(undefined8 *)(param_1 + 0x48) = *(undefined8 *)(param_2 + 0x48);
  *(undefined1 **)(param_2 + 0x48) = &DAT_011c5338;
                    /* try { // try from 00c14e64 to 00c14e68 has its CatchHandler @ 00c14e70 */
  std::stringbuf::_M_sync((stringbuf *)param_2,&DAT_011c5338,0,0);
  return;
}


// ==== entry=00c14e90 orig=FUN_00c14e90 size=47 name=str ====

/* std::stringbuf::str(std::string const&) */

void __thiscall std::stringbuf::str(stringbuf *this,string *param_1)

{
  ulong uVar1;
  
  string::s_basic_string__assign_65a9ea
            ((string *)(this + 0x48),*(char **)param_1,*(ulong *)(*(char **)param_1 + -0x18));
  uVar1 = 0;
  if (((byte)this[0x40] & 3) != 0) {
    uVar1 = *(ulong *)(*(char **)(this + 0x48) + -0x18);
  }
  _M_sync(this,*(char **)(this + 0x48),0,uVar1);
  return;
}


// ==== entry=00c14ec0 orig=FUN_00c14ec0 size=218 name=stringbuf ====

/* std::stringbuf::stringbuf(std::string const&, std::_Ios_Openmode) */

void __thiscall std::stringbuf::stringbuf(stringbuf *this,undefined8 *param_1,uint param_3)

{
  char *pcVar1;
  ulong uVar2;
  long in_FS_OFFSET;
  allocator local_31;
  long local_30;
  
  local_30 = *(long *)(in_FS_OFFSET + 0x28);
  *(undefined8 *)(this + 8) = 0;
  *(undefined8 *)(this + 0x10) = 0;
  *(undefined ***)this = &PTR__streambuf_011b2b68;
  *(undefined8 *)(this + 0x18) = 0;
  *(undefined8 *)(this + 0x20) = 0;
  *(undefined8 *)(this + 0x28) = 0;
  *(undefined8 *)(this + 0x30) = 0;
  locale::locale((locale *)(this + 0x38));
  pcVar1 = (char *)*param_1;
  *(undefined4 *)(this + 0x40) = 0;
  uVar2 = *(ulong *)(pcVar1 + -0x18);
  *(undefined ***)this = &PTR__stringbuf_011b4680;
                    /* try { // try from 00c14f57 to 00c14f5b has its CatchHandler @ 00c14f9f */
  string::string((string *)(this + 0x48),pcVar1,uVar2,&local_31);
  *(uint *)(this + 0x40) = param_3;
  uVar2 = 0;
  if ((param_3 & 3) != 0) {
    uVar2 = *(ulong *)(*(char **)(this + 0x48) + -0x18);
  }
                    /* try { // try from 00c14f73 to 00c14f77 has its CatchHandler @ 00c14f9a */
  _M_sync(this,*(char **)(this + 0x48),0,uVar2);
  if (local_30 == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ==== entry=00c14fe0 orig=FUN_00c14fe0 size=365 name=seekoff ====

/* std::stringbuf::seekoff(long, std::_Ios_Seekdir, std::_Ios_Openmode) */

long __thiscall std::stringbuf::seekoff(stringbuf *this,long param_1,int param_3,uint param_4)

{
  long lVar1;
  ulong uVar2;
  long lVar3;
  uint uVar4;
  byte bVar5;
  byte bVar6;
  long lVar7;
  byte bVar8;
  long in_FS_OFFSET;
  bool bVar9;
  
  lVar1 = *(long *)(in_FS_OFFSET + 0x28);
  uVar4 = *(uint *)(this + 0x40) & 8;
  bVar9 = (param_4 & uVar4) != 0;
  bVar5 = (byte)((*(uint *)(this + 0x40) & param_4) >> 4) & 1;
  bVar8 = bVar9 & bVar5 & param_3 != 1;
  bVar5 = bVar5 & ((byte)(param_4 >> 3) ^ 1);
  bVar6 = bVar9 & ((byte)(param_4 >> 4) ^ 1);
  if (bVar6 == 0) {
    lVar7 = *(long *)(this + 0x20);
    if (((lVar7 == 0) && (param_1 != 0)) || (bVar5 == 0 && bVar8 == 0)) goto LAB_00c150dd;
  }
  else {
    lVar7 = *(long *)(this + 8);
    if ((lVar7 == 0) && (param_1 != 0)) {
LAB_00c150dd:
      param_1 = -1;
      goto LAB_00c150e4;
    }
  }
  uVar2 = *(ulong *)(this + 0x28);
  if ((uVar2 != 0) && (*(ulong *)(this + 0x18) < uVar2)) {
    if (uVar4 == 0) {
      *(ulong *)(this + 8) = uVar2;
      *(ulong *)(this + 0x10) = uVar2;
    }
    *(ulong *)(this + 0x18) = uVar2;
  }
  if (param_3 == 1) {
    lVar3 = (uVar2 - lVar7) + param_1;
    param_1 = param_1 + (*(long *)(this + 0x10) - lVar7);
  }
  else {
    lVar3 = param_1;
    if (param_3 == 2) {
      param_1 = param_1 + (*(long *)(this + 0x18) - lVar7);
      lVar3 = param_1;
    }
  }
  if (((bVar6 == 0 && bVar8 == 0) || (param_1 < 0)) || (*(long *)(this + 0x18) - lVar7 < param_1)) {
    param_1 = -1;
  }
  else {
    *(long *)(this + 0x10) = *(long *)(this + 8) + param_1;
  }
  if (((-1 < lVar3) && (bVar5 != 0 || bVar8 != 0)) && (lVar3 <= *(long *)(this + 0x18) - lVar7)) {
    _M_pbump(this,*(char **)(this + 0x20),*(char **)(this + 0x30),lVar3);
    param_1 = lVar3;
  }
LAB_00c150e4:
  if (lVar1 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_1;
}


// ==== entry=00c15170 orig=FUN_00c15170 size=238 name=seekpos ====

/* std::stringbuf::seekpos(std::fpos<__mbstate_t>, std::_Ios_Openmode) */

long std::stringbuf::seekpos(stringbuf *param_1,long param_2,undefined8 param_3,uint param_4)

{
  long lVar1;
  ulong uVar2;
  uint uVar3;
  uint uVar4;
  long lVar5;
  long in_FS_OFFSET;
  
  lVar1 = *(long *)(in_FS_OFFSET + 0x28);
  uVar3 = *(uint *)(param_1 + 0x40) & param_4;
  uVar4 = *(uint *)(param_1 + 0x40) & 8;
  param_4 = param_4 & uVar4;
  if (param_4 == 0) {
    lVar5 = *(long *)(param_1 + 0x20);
  }
  else {
    lVar5 = *(long *)(param_1 + 8);
  }
  if (((lVar5 != 0) || (param_2 == 0)) && ((uVar3 & 0x18) != 0)) {
    uVar2 = *(ulong *)(param_1 + 0x28);
    if ((uVar2 != 0) && (*(ulong *)(param_1 + 0x18) < uVar2)) {
      if (uVar4 == 0) {
        *(ulong *)(param_1 + 8) = uVar2;
        *(ulong *)(param_1 + 0x10) = uVar2;
      }
      *(ulong *)(param_1 + 0x18) = uVar2;
    }
    if ((-1 < param_2) && (param_2 <= *(long *)(param_1 + 0x18) - lVar5)) {
      if (param_4 != 0) {
        *(long *)(param_1 + 0x10) = *(long *)(param_1 + 8) + param_2;
      }
      if ((uVar3 & 0x10) != 0) {
        _M_pbump(param_1,*(char **)(param_1 + 0x20),*(char **)(param_1 + 0x30),param_2);
      }
      goto LAB_00c151be;
    }
  }
  param_2 = -1;
LAB_00c151be:
  if (lVar1 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_2;
}


// ==== entry=00c15280 name=FUN_00c15280 size=68 ====

void FUN_00c15280(streambuf *param_1,streambuf *param_2)

{
  std::streambuf::streambuf(param_1,param_2);
  *(undefined ***)param_1 = &PTR__stringbuf_011b4680;
  *(undefined4 *)(param_1 + 0x40) = *(undefined4 *)(param_2 + 0x40);
  *(undefined8 *)(param_1 + 0x48) = *(undefined8 *)(param_2 + 0x48);
  *(undefined1 **)(param_2 + 0x48) = &DAT_011c5338;
  return;
}


// ==== entry=00c152d0 name=FUN_00c152d0 size=1 ====

void FUN_00c152d0(void)

{
  return;
}


// ==== entry=00c152e0 orig=FUN_00c152e0 size=222 name=istringstream ====

/* std::istringstream::istringstream(std::_Ios_Openmode) */

void __thiscall std::istringstream::istringstream(istringstream *this,long *param_2,uint param_3)

{
  long lVar1;
  
  lVar1 = param_2[1];
  *(long *)this = lVar1;
  *(long *)(this + *(long *)(lVar1 + -0x18)) = param_2[2];
  *(undefined8 *)(this + 8) = 0;
  ios::init((ios *)(this + *(long *)(lVar1 + -0x18)),(streambuf *)0x0);
  lVar1 = *param_2;
  *(long *)this = lVar1;
  *(long *)(this + *(long *)(lVar1 + -0x18)) = param_2[3];
  *(undefined8 *)(this + 0x18) = 0;
  *(undefined8 *)(this + 0x20) = 0;
  *(undefined ***)(this + 0x10) = &PTR__streambuf_011b2b68;
  *(undefined8 *)(this + 0x28) = 0;
  *(undefined8 *)(this + 0x30) = 0;
  *(undefined8 *)(this + 0x38) = 0;
  *(undefined8 *)(this + 0x40) = 0;
  locale::locale((locale *)(this + 0x48));
  *(uint *)(this + 0x50) = param_3 | 8;
  *(undefined ***)(this + 0x10) = &PTR__stringbuf_011b4680;
  *(undefined1 **)(this + 0x58) = &DAT_011c5338;
                    /* try { // try from 00c153ae to 00c153b2 has its CatchHandler @ 00c153be */
  ios::init((ios *)(this + *(long *)(*(long *)this + -0x18)),(streambuf *)(this + 0x10));
  return;
}


// ==== entry=00c153f0 orig=FUN_00c153f0 size=282 name=istringstream ====

/* std::istringstream::istringstream(std::_Ios_Openmode) */

void __thiscall std::istringstream::istringstream(istringstream *this,uint param_2)

{
  ios_base *this_00;
  
  this_00 = (ios_base *)(this + 0x60);
  ios_base::ios_base(this_00);
  *(undefined **)this = &DAT_011b4708;
  *(undefined2 *)(this + 0x140) = 0;
  *(undefined8 *)(this + 0x138) = 0;
  *(undefined8 *)(this + 0x148) = 0;
  *(undefined8 *)(this + 0x150) = 0;
  *(undefined8 *)(this + 0x158) = 0;
  *(undefined8 *)(this + 0x160) = 0;
  *(undefined **)(this + 0x60) = &DAT_011b4730;
  *(undefined8 *)(this + 8) = 0;
                    /* try { // try from 00c15469 to 00c1546d has its CatchHandler @ 00c1550a */
  ios::init((ios *)this_00,(streambuf *)0x0);
  *(undefined8 *)(this + 0x18) = 0;
  *(undefined8 *)(this + 0x20) = 0;
  *(undefined8 *)(this + 0x28) = 0;
  *(undefined8 *)(this + 0x60) = 0x11b47a0;
  *(undefined8 *)this = 0x11b4778;
  *(undefined8 *)(this + 0x30) = 0;
  *(undefined ***)(this + 0x10) = &PTR__streambuf_011b2b68;
  *(undefined8 *)(this + 0x38) = 0;
  *(undefined8 *)(this + 0x40) = 0;
  locale::locale((locale *)(this + 0x48));
  *(uint *)(this + 0x50) = param_2 | 8;
  *(undefined ***)(this + 0x10) = &PTR__stringbuf_011b4680;
  *(undefined1 **)(this + 0x58) = &DAT_011c5338;
                    /* try { // try from 00c154fc to 00c15500 has its CatchHandler @ 00c1550f */
  ios::init((ios *)this_00,(streambuf *)(this + 0x10));
  return;
}


// ==== entry=00c15550 orig=FUN_00c15550 size=324 name=istringstream ====

/* std::istringstream::istringstream(std::string const&, std::_Ios_Openmode) */

void __thiscall
std::istringstream::istringstream
          (istringstream *this,long *param_1,undefined8 *param_3,uint param_4)

{
  long lVar1;
  char *pcVar2;
  ulong uVar3;
  long in_FS_OFFSET;
  allocator local_41;
  long local_40;
  
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  lVar1 = param_1[1];
  *(long *)this = lVar1;
  *(long *)(this + *(long *)(lVar1 + -0x18)) = param_1[2];
  *(undefined8 *)(this + 8) = 0;
  ios::init((ios *)(this + *(long *)(lVar1 + -0x18)),(streambuf *)0x0);
  lVar1 = *param_1;
  *(long *)this = lVar1;
  *(long *)(this + *(long *)(lVar1 + -0x18)) = param_1[3];
  *(undefined8 *)(this + 0x18) = 0;
  *(undefined ***)(this + 0x10) = &PTR__streambuf_011b2b68;
  *(undefined8 *)(this + 0x20) = 0;
  *(undefined8 *)(this + 0x28) = 0;
  *(undefined8 *)(this + 0x30) = 0;
  *(undefined8 *)(this + 0x38) = 0;
  *(undefined8 *)(this + 0x40) = 0;
  locale::locale((locale *)(this + 0x48));
  pcVar2 = (char *)*param_3;
  *(undefined4 *)(this + 0x50) = 0;
  uVar3 = *(ulong *)(pcVar2 + -0x18);
  *(undefined ***)(this + 0x10) = &PTR__stringbuf_011b4680;
                    /* try { // try from 00c15634 to 00c15638 has its CatchHandler @ 00c1569e */
  string::string((string *)(this + 0x58),pcVar2,uVar3,&local_41);
  uVar3 = 0;
  *(uint *)(this + 0x50) = param_4 | 8;
  if ((param_4 & 3) != 0) {
    uVar3 = *(ulong *)(*(char **)(this + 0x58) + -0x18);
  }
                    /* try { // try from 00c15659 to 00c1565d has its CatchHandler @ 00c15699 */
  stringbuf::_M_sync((stringbuf *)(this + 0x10),*(char **)(this + 0x58),0,uVar3);
                    /* try { // try from 00c1566b to 00c1566f has its CatchHandler @ 00c15694 */
  ios::init((ios *)(this + *(long *)(*(long *)this + -0x18)),(streambuf *)(this + 0x10));
  if (local_40 == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ==== entry=00c15710 orig=FUN_00c15710 size=393 name=istringstream ====

/* std::istringstream::istringstream(std::string const&, std::_Ios_Openmode) */

void __thiscall
std::istringstream::istringstream(istringstream *this,undefined8 *param_1,uint param_3)

{
  ios_base *this_00;
  char *pcVar1;
  ulong uVar2;
  long in_FS_OFFSET;
  allocator local_41;
  long local_40;
  
  this_00 = (ios_base *)(this + 0x60);
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  ios_base::ios_base(this_00);
  *(undefined **)this = &DAT_011b4708;
  *(undefined2 *)(this + 0x140) = 0;
  *(undefined8 *)(this + 0x138) = 0;
  *(undefined8 *)(this + 0x148) = 0;
  *(undefined8 *)(this + 0x150) = 0;
  *(undefined8 *)(this + 0x158) = 0;
  *(undefined8 *)(this + 0x160) = 0;
  *(undefined **)(this + 0x60) = &DAT_011b4730;
  *(undefined8 *)(this + 8) = 0;
                    /* try { // try from 00c157a2 to 00c157a6 has its CatchHandler @ 00c15911 */
  ios::init((ios *)this_00,(streambuf *)0x0);
  *(undefined8 *)(this + 0x18) = 0;
  *(undefined8 *)(this + 0x20) = 0;
  *(undefined8 *)(this + 0x28) = 0;
  *(undefined8 *)this = 0x11b4778;
  *(undefined8 *)(this + 0x60) = 0x11b47a0;
  *(undefined8 *)(this + 0x30) = 0;
  *(undefined ***)(this + 0x10) = &PTR__streambuf_011b2b68;
  *(undefined8 *)(this + 0x38) = 0;
  *(undefined8 *)(this + 0x40) = 0;
  locale::locale((locale *)(this + 0x48));
  pcVar1 = (char *)*param_1;
  *(undefined4 *)(this + 0x50) = 0;
  uVar2 = *(ulong *)(pcVar1 + -0x18);
  *(undefined ***)(this + 0x10) = &PTR__stringbuf_011b4680;
                    /* try { // try from 00c15844 to 00c15848 has its CatchHandler @ 00c1590c */
  string::string((string *)(this + 0x58),pcVar1,uVar2,&local_41);
  uVar2 = 0;
  *(uint *)(this + 0x50) = param_3 | 8;
  if ((param_3 & 3) != 0) {
    uVar2 = *(ulong *)(*(char **)(this + 0x58) + -0x18);
  }
                    /* try { // try from 00c15865 to 00c15869 has its CatchHandler @ 00c1589e */
  stringbuf::_M_sync((stringbuf *)(this + 0x10),*(char **)(this + 0x58),0,uVar2);
                    /* try { // try from 00c15870 to 00c15874 has its CatchHandler @ 00c15899 */
  ios::init((ios *)this_00,(streambuf *)(this + 0x10));
  if (local_40 == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ==== entry=00c15920 orig=FUN_00c15920 size=204 name=~istringstream ====

/* WARNING: Removing unreachable block (ram,0x00c159e8) */
/* std::istringstream::~istringstream() */

void __thiscall std::istringstream::~istringstream(istringstream *this)

{
  allocator *paVar1;
  int *piVar2;
  int iVar3;
  long lVar4;
  long lVar5;
  long *in_RSI;
  long in_FS_OFFSET;
  
  lVar4 = *(long *)(in_FS_OFFSET + 0x28);
  lVar5 = *in_RSI;
  *(long *)this = lVar5;
  *(long *)(this + *(long *)(lVar5 + -0x18)) = in_RSI[3];
  *(undefined ***)(this + 0x10) = &PTR__stringbuf_011b4680;
  paVar1 = (allocator *)(*(long *)(this + 0x58) + -0x18);
  if (paVar1 != (allocator *)&string::_Rep::_S_empty_rep_storage) {
    LOCK();
    piVar2 = (int *)(*(long *)(this + 0x58) + -8);
    iVar3 = *piVar2;
    *piVar2 = *piVar2 + -1;
    UNLOCK();
    if (iVar3 < 1) {
      string::_Rep::_M_destroy(paVar1);
    }
  }
  *(undefined ***)(this + 0x10) = &PTR__streambuf_011b2b68;
  locale::~locale((locale *)(this + 0x48));
  lVar5 = in_RSI[1];
  *(long *)this = lVar5;
  *(long *)(this + *(long *)(lVar5 + -0x18)) = in_RSI[2];
  *(undefined8 *)(this + 8) = 0;
  if (lVar4 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


// ==== entry=00c15a00 name=FUN_00c15a00 size=284 ====

void FUN_00c15a00(long *param_1,long *param_2,long *param_3)

{
  ios iVar1;
  undefined8 uVar2;
  ios *this;
  long lVar3;
  
  lVar3 = param_2[1];
  *param_1 = lVar3;
  *(long *)((long)param_1 + *(long *)(lVar3 + -0x18)) = param_2[2];
  param_1[1] = param_3[1];
  this = (ios *)(*(long *)(lVar3 + -0x18) + (long)param_1);
  lVar3 = *(long *)(*param_3 + -0x18) + (long)param_3;
  FUN_00c71b00(this,lVar3);
  std::ios::_M_cache_locale(this,(locale *)(this + 0xd0));
  uVar2 = *(undefined8 *)(lVar3 + 0xd8);
  *(undefined8 *)(lVar3 + 0xd8) = 0;
  *(undefined8 *)(this + 0xd8) = uVar2;
  this[0xe0] = *(ios *)(lVar3 + 0xe0);
  iVar1 = *(ios *)(lVar3 + 0xe1);
  *(undefined8 *)(this + 0xe8) = 0;
  this[0xe1] = iVar1;
  lVar3 = *param_2;
  param_3[1] = 0;
  *param_1 = lVar3;
  *(long *)((long)param_1 + *(long *)(lVar3 + -0x18)) = param_2[3];
                    /* try { // try from 00c15ac7 to 00c15acb has its CatchHandler @ 00c15b1c */
  std::streambuf::streambuf((streambuf *)(param_1 + 2),(streambuf *)(param_3 + 2));
  param_1[2] = (long)&PTR__stringbuf_011b4680;
  *(int *)(param_1 + 10) = (int)param_3[10];
  param_1[0xb] = param_3[0xb];
  param_3[0xb] = (long)&DAT_011c5338;
                    /* try { // try from 00c15aff to 00c15b03 has its CatchHandler @ 00c15b1e */
  std::stringbuf::_M_sync((stringbuf *)(param_3 + 2),&DAT_011c5338,0,0);
  *(streambuf **)((long)param_1 + *(long *)(*param_1 + -0x18) + 0xe8) = (streambuf *)(param_1 + 2);
  return;
}


// ==== entry=00c15b50 name=FUN_00c15b50 size=354 ====

void FUN_00c15b50(undefined8 *param_1,long *param_2)

{
  ios_base *this;
  undefined1 uVar1;
  undefined8 uVar2;
  long lVar3;
  
  this = (ios_base *)(param_1 + 0xc);
  std::ios_base::ios_base(this);
  *param_1 = &DAT_011b4708;
  *(undefined2 *)(param_1 + 0x28) = 0;
  param_1[0xc] = &DAT_011b4730;
  lVar3 = param_2[1];
  param_1[0x27] = 0;
  param_1[1] = lVar3;
  lVar3 = *param_2;
  param_1[0x29] = 0;
  param_1[0x2a] = 0;
  lVar3 = *(long *)(lVar3 + -0x18);
  param_1[0x2b] = 0;
  param_1[0x2c] = 0;
  lVar3 = lVar3 + (long)param_2;
  FUN_00c71b00(this,lVar3);
                    /* try { // try from 00c15bea to 00c15bee has its CatchHandler @ 00c15cb2 */
  std::ios::_M_cache_locale((ios *)this,(locale *)(param_1 + 0x26));
  uVar2 = *(undefined8 *)(lVar3 + 0xd8);
  *(undefined8 *)(lVar3 + 0xd8) = 0;
  param_1[0x27] = uVar2;
  *(undefined1 *)(param_1 + 0x28) = *(undefined1 *)(lVar3 + 0xe0);
  uVar1 = *(undefined1 *)(lVar3 + 0xe1);
  param_1[0x29] = 0;
  *(undefined1 *)((long)param_1 + 0x141) = uVar1;
  param_2[1] = 0;
  *param_1 = 0x11b4778;
  param_1[0xc] = 0x11b47a0;
                    /* try { // try from 00c15c5f to 00c15c63 has its CatchHandler @ 00c15cbc */
  std::streambuf::streambuf((streambuf *)(param_1 + 2),(streambuf *)(param_2 + 2));
  param_1[2] = &PTR__stringbuf_011b4680;
  *(int *)(param_1 + 10) = (int)param_2[10];
  param_1[0xb] = param_2[0xb];
  param_2[0xb] = (long)&DAT_011c5338;
                    /* try { // try from 00c15c97 to 00c15c9b has its CatchHandler @ 00c15cb7 */
  std::stringbuf::_M_sync((stringbuf *)(param_2 + 2),&DAT_011c5338,0,0);
  param_1[0x29] = (streambuf *)(param_1 + 2);
  return;
}


// ==== entry=00c15d00 name=FUN_00c15d00 size=362 ====

long * FUN_00c15d00(long *param_1,long *param_2)

{
  ios iVar1;
  undefined8 uVar2;
  long lVar3;
  long lVar4;
  ios *this;
  ios *this_00;
  long in_FS_OFFSET;
  locale local_50 [8];
  locale local_48 [8];
  long local_40;
  
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  this_00 = (ios *)(*(long *)(*param_1 + -0x18) + (long)param_1);
  this = (ios *)(*(long *)(*param_2 + -0x18) + (long)param_2);
  FUN_00c71c10(this_00,this);
  std::ios::_M_cache_locale(this_00,(locale *)(this_00 + 0xd0));
  std::ios::_M_cache_locale(this,(locale *)(this + 0xd0));
  uVar2 = *(undefined8 *)(this_00 + 0xd8);
  *(undefined8 *)(this_00 + 0xd8) = *(undefined8 *)(this + 0xd8);
  *(undefined8 *)(this + 0xd8) = uVar2;
  iVar1 = this_00[0xe0];
  this_00[0xe0] = this[0xe0];
  this[0xe0] = iVar1;
  iVar1 = this_00[0xe1];
  this_00[0xe1] = this[0xe1];
  lVar3 = param_2[1];
  this[0xe1] = iVar1;
  lVar4 = param_1[1];
  param_1[1] = lVar3;
  param_2[1] = lVar4;
  std::streambuf::operator=((streambuf *)(param_1 + 2),(streambuf *)(param_2 + 2));
  std::locale::locale(local_48,(locale *)(param_2 + 9));
  std::locale::locale(local_50,(locale *)(param_1 + 9));
  std::locale::operator=((locale *)(param_1 + 9),local_48);
  std::locale::~locale(local_50);
  std::locale::~locale(local_48);
  *(int *)(param_1 + 10) = (int)param_2[10];
  std::string::swap((string *)(param_1 + 0xb),(string *)(param_2 + 0xb));
  std::stringbuf::_M_sync((stringbuf *)(param_2 + 2),(char *)param_2[0xb],0,0);
  if (local_40 == *(long *)(in_FS_OFFSET + 0x28)) {
    return param_1;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ==== entry=00c15e70 name=FUN_00c15e70 size=520 ====

void FUN_00c15e70(long *param_1,long *param_2)

{
  locale *this;
  locale *this_00;
  ios iVar1;
  undefined8 uVar2;
  long lVar3;
  long lVar4;
  ios *this_01;
  ios *this_02;
  long in_FS_OFFSET;
  locale alStack_58 [8];
  locale local_50 [8];
  locale local_48 [8];
  long local_40;
  
  this = (locale *)(param_1 + 9);
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  this_02 = (ios *)(*(long *)(*param_1 + -0x18) + (long)param_1);
  this_01 = (ios *)(*(long *)(*param_2 + -0x18) + (long)param_2);
  FUN_00c71c10(this_02,this_01);
  std::ios::_M_cache_locale(this_02,(locale *)(this_02 + 0xd0));
  std::ios::_M_cache_locale(this_01,(locale *)(this_01 + 0xd0));
  uVar2 = *(undefined8 *)(this_02 + 0xd8);
  *(undefined8 *)(this_02 + 0xd8) = *(undefined8 *)(this_01 + 0xd8);
  *(undefined8 *)(this_01 + 0xd8) = uVar2;
  iVar1 = this_02[0xe0];
  this_02[0xe0] = this_01[0xe0];
  this_01[0xe0] = iVar1;
  iVar1 = this_02[0xe1];
  this_02[0xe1] = this_01[0xe1];
  lVar3 = param_2[1];
  this_00 = (locale *)(param_2 + 9);
  this_01[0xe1] = iVar1;
  lVar4 = param_1[1];
  param_1[1] = lVar3;
  param_2[1] = lVar4;
  lVar3 = param_1[3];
  param_1[3] = param_2[3];
  param_2[3] = lVar3;
  lVar3 = param_1[4];
  param_1[4] = param_2[4];
  param_2[4] = lVar3;
  lVar3 = param_1[5];
  param_1[5] = param_2[5];
  param_2[5] = lVar3;
  lVar3 = param_1[6];
  param_1[6] = param_2[6];
  param_2[6] = lVar3;
  lVar3 = param_1[7];
  param_1[7] = param_2[7];
  param_2[7] = lVar3;
  lVar3 = param_1[8];
  param_1[8] = param_2[8];
  param_2[8] = lVar3;
  std::locale::locale(local_48,this);
  std::locale::operator=(this,this_00);
  std::locale::operator=(this_00,local_48);
  std::locale::~locale(local_48);
  std::locale::locale(local_48,this_00);
  std::locale::locale(local_50,this);
  std::locale::operator=(this,local_48);
  std::locale::locale(alStack_58,this_00);
                    /* try { // try from 00c16015 to 00c16017 has its CatchHandler @ 00c16078 */
  (**(code **)(param_2[2] + 0x10))(param_2 + 2,local_50);
  std::locale::operator=(this_00,local_50);
  std::locale::~locale(alStack_58);
  std::locale::~locale(local_50);
  std::locale::~locale(local_48);
  lVar3 = param_1[10];
  *(int *)(param_1 + 10) = (int)param_2[10];
  *(int *)(param_2 + 10) = (int)lVar3;
  std::string::swap((string *)(param_1 + 0xb),(string *)(param_2 + 0xb));
  if (local_40 == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ==== entry=00c160a0 orig=FUN_00c160a0 size=5 name=rdbuf ====

/* std::istringstream::rdbuf() const */

istringstream * __thiscall std::istringstream::rdbuf(istringstream *this)

{
  return this + 0x10;
}


// ==== entry=00c160b0 orig=FUN_00c160b0 size=150 name=str ====

/* std::istringstream::str() const */

void std::istringstream::str(void)

{
  ulong uVar1;
  char *pcVar2;
  long in_RSI;
  string *in_RDI;
  long in_FS_OFFSET;
  allocator local_21;
  long local_20;
  
  local_20 = *(long *)(in_FS_OFFSET + 0x28);
  string::string(in_RDI,&local_21);
  uVar1 = *(ulong *)(in_RSI + 0x38);
  if (uVar1 == 0) {
    string::assign(in_RDI,(string *)(in_RSI + 0x58));
  }
  else {
    pcVar2 = *(char **)(in_RSI + 0x30);
    if (*(ulong *)(in_RSI + 0x28) < uVar1) {
      string::s_basic_string__replace_52baa6
                (in_RDI,0,*(ulong *)(*(long *)in_RDI + -0x18),pcVar2,uVar1 - (long)pcVar2);
    }
    else {
                    /* try { // try from 00c16100 to 00c1614b has its CatchHandler @ 00c16153 */
      string::s_basic_string__replace_52baa6
                (in_RDI,0,*(ulong *)(*(long *)in_RDI + -0x18),pcVar2,
                 *(ulong *)(in_RSI + 0x28) - (long)pcVar2);
    }
  }
  if (local_20 == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ==== entry=00c16180 orig=FUN_00c16180 size=61 name=str ====

/* std::istringstream::str(std::string const&) */

void __thiscall std::istringstream::str(istringstream *this,string *param_1)

{
  ulong uVar1;
  
  string::s_basic_string__assign_65a9ea
            ((string *)(this + 0x58),*(char **)param_1,*(ulong *)(*(char **)param_1 + -0x18));
  uVar1 = 0;
  if (((byte)this[0x50] & 3) != 0) {
    uVar1 = *(ulong *)(*(char **)(this + 0x58) + -0x18);
  }
  stringbuf::_M_sync((stringbuf *)(this + 0x10),*(char **)(this + 0x58),0,uVar1);
  return;
}


// ==== entry=00c161c0 orig=FUN_00c161c0 size=209 name=ostringstream ====

/* std::ostringstream::ostringstream(std::_Ios_Openmode) */

void __thiscall std::ostringstream::ostringstream(ostringstream *this,long *param_2,uint param_3)

{
  long lVar1;
  
  lVar1 = param_2[1];
  *(long *)this = lVar1;
  lVar1 = *(long *)(lVar1 + -0x18);
  *(long *)(this + lVar1) = param_2[2];
  ios::init((ios *)(this + lVar1),(streambuf *)0x0);
  lVar1 = *param_2;
  *(long *)this = lVar1;
  *(long *)(this + *(long *)(lVar1 + -0x18)) = param_2[3];
  *(undefined8 *)(this + 0x10) = 0;
  *(undefined8 *)(this + 0x18) = 0;
  *(undefined ***)(this + 8) = &PTR__streambuf_011b2b68;
  *(undefined8 *)(this + 0x20) = 0;
  *(undefined8 *)(this + 0x28) = 0;
  *(undefined8 *)(this + 0x30) = 0;
  *(undefined8 *)(this + 0x38) = 0;
  locale::locale((locale *)(this + 0x40));
  *(uint *)(this + 0x48) = param_3 | 0x10;
  *(undefined ***)(this + 8) = &PTR__stringbuf_011b4680;
  *(undefined1 **)(this + 0x50) = &DAT_011c5338;
                    /* try { // try from 00c16281 to 00c16285 has its CatchHandler @ 00c16291 */
  ios::init((ios *)(this + *(long *)(*(long *)this + -0x18)),(streambuf *)(this + 8));
  return;
}


// ==== entry=00c162c0 orig=FUN_00c162c0 size=274 name=ostringstream ====

/* std::ostringstream::ostringstream(std::_Ios_Openmode) */

void __thiscall std::ostringstream::ostringstream(ostringstream *this,uint param_2)

{
  ios_base *this_00;
  
  this_00 = (ios_base *)(this + 0x58);
  ios_base::ios_base(this_00);
  *(undefined **)this = &DAT_011b47c8;
  *(undefined2 *)(this + 0x138) = 0;
  *(undefined8 *)(this + 0x130) = 0;
  *(undefined8 *)(this + 0x140) = 0;
  *(undefined8 *)(this + 0x148) = 0;
  *(undefined8 *)(this + 0x150) = 0;
  *(undefined8 *)(this + 0x158) = 0;
  *(undefined **)(this + 0x58) = &DAT_011b47f0;
                    /* try { // try from 00c16331 to 00c16335 has its CatchHandler @ 00c163d2 */
  ios::init((ios *)this_00,(streambuf *)0x0);
  *(undefined8 *)(this + 0x10) = 0;
  *(undefined8 *)(this + 0x18) = 0;
  *(undefined8 *)(this + 0x20) = 0;
  *(undefined ***)(this + 0x58) = &PTR__ostringstream_011b4860;
  *(undefined ***)this = &PTR__ostringstream_011b4838;
  *(undefined8 *)(this + 0x28) = 0;
  *(undefined ***)(this + 8) = &PTR__streambuf_011b2b68;
  *(undefined8 *)(this + 0x30) = 0;
  *(undefined8 *)(this + 0x38) = 0;
  locale::locale((locale *)(this + 0x40));
  *(uint *)(this + 0x48) = param_2 | 0x10;
  *(undefined ***)(this + 8) = &PTR__stringbuf_011b4680;
  *(undefined1 **)(this + 0x50) = &DAT_011c5338;
                    /* try { // try from 00c163c4 to 00c163c8 has its CatchHandler @ 00c163d7 */
  ios::init((ios *)this_00,(streambuf *)(this + 8));
  return;
}


// ==== entry=00c16410 orig=FUN_00c16410 size=311 name=ostringstream ====

/* std::ostringstream::ostringstream(std::string const&, std::_Ios_Openmode) */

void __thiscall
std::ostringstream::ostringstream
          (ostringstream *this,long *param_1,undefined8 *param_3,uint param_4)

{
  long lVar1;
  char *pcVar2;
  ulong uVar3;
  long in_FS_OFFSET;
  allocator local_41;
  long local_40;
  
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  lVar1 = param_1[1];
  *(long *)this = lVar1;
  lVar1 = *(long *)(lVar1 + -0x18);
  *(long *)(this + lVar1) = param_1[2];
  ios::init((ios *)(this + lVar1),(streambuf *)0x0);
  lVar1 = *param_1;
  *(long *)this = lVar1;
  *(long *)(this + *(long *)(lVar1 + -0x18)) = param_1[3];
  *(undefined8 *)(this + 0x10) = 0;
  *(undefined ***)(this + 8) = &PTR__streambuf_011b2b68;
  *(undefined8 *)(this + 0x18) = 0;
  *(undefined8 *)(this + 0x20) = 0;
  *(undefined8 *)(this + 0x28) = 0;
  *(undefined8 *)(this + 0x30) = 0;
  *(undefined8 *)(this + 0x38) = 0;
  locale::locale((locale *)(this + 0x40));
  pcVar2 = (char *)*param_3;
  *(undefined4 *)(this + 0x48) = 0;
  uVar3 = *(ulong *)(pcVar2 + -0x18);
  *(undefined ***)(this + 8) = &PTR__stringbuf_011b4680;
                    /* try { // try from 00c164e7 to 00c164eb has its CatchHandler @ 00c16551 */
  string::string((string *)(this + 0x50),pcVar2,uVar3,&local_41);
  uVar3 = 0;
  *(uint *)(this + 0x48) = param_4 | 0x10;
  if ((param_4 & 3) != 0) {
    uVar3 = *(ulong *)(*(char **)(this + 0x50) + -0x18);
  }
                    /* try { // try from 00c1650c to 00c16510 has its CatchHandler @ 00c1654c */
  stringbuf::_M_sync((stringbuf *)(this + 8),*(char **)(this + 0x50),0,uVar3);
                    /* try { // try from 00c1651e to 00c16522 has its CatchHandler @ 00c16547 */
  ios::init((ios *)(this + *(long *)(*(long *)this + -0x18)),(streambuf *)(this + 8));
  if (local_40 == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ==== entry=00c165b0 orig=FUN_00c165b0 size=385 name=ostringstream ====

/* std::ostringstream::ostringstream(std::string const&, std::_Ios_Openmode) */

void __thiscall
std::ostringstream::ostringstream(ostringstream *this,undefined8 *param_1,uint param_3)

{
  ios_base *this_00;
  char *pcVar1;
  ulong uVar2;
  long in_FS_OFFSET;
  allocator local_41;
  long local_40;
  
  this_00 = (ios_base *)(this + 0x58);
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  ios_base::ios_base(this_00);
  *(undefined **)this = &DAT_011b47c8;
  *(undefined2 *)(this + 0x138) = 0;
  *(undefined8 *)(this + 0x130) = 0;
  *(undefined8 *)(this + 0x140) = 0;
  *(undefined8 *)(this + 0x148) = 0;
  *(undefined8 *)(this + 0x150) = 0;
  *(undefined8 *)(this + 0x158) = 0;
  *(undefined **)(this + 0x58) = &DAT_011b47f0;
                    /* try { // try from 00c1663a to 00c1663e has its CatchHandler @ 00c167a1 */
  ios::init((ios *)this_00,(streambuf *)0x0);
  *(undefined8 *)(this + 0x10) = 0;
  *(undefined8 *)(this + 0x18) = 0;
  *(undefined8 *)(this + 0x20) = 0;
  *(undefined ***)this = &PTR__ostringstream_011b4838;
  *(undefined ***)(this + 0x58) = &PTR__ostringstream_011b4860;
  *(undefined8 *)(this + 0x28) = 0;
  *(undefined ***)(this + 8) = &PTR__streambuf_011b2b68;
  *(undefined8 *)(this + 0x30) = 0;
  *(undefined8 *)(this + 0x38) = 0;
  locale::locale((locale *)(this + 0x40));
  pcVar1 = (char *)*param_1;
  *(undefined4 *)(this + 0x48) = 0;
  uVar2 = *(ulong *)(pcVar1 + -0x18);
  *(undefined ***)(this + 8) = &PTR__stringbuf_011b4680;
                    /* try { // try from 00c166dc to 00c166e0 has its CatchHandler @ 00c1679c */
  string::string((string *)(this + 0x50),pcVar1,uVar2,&local_41);
  uVar2 = 0;
  *(uint *)(this + 0x48) = param_3 | 0x10;
  if ((param_3 & 3) != 0) {
    uVar2 = *(ulong *)(*(char **)(this + 0x50) + -0x18);
  }
                    /* try { // try from 00c166fd to 00c16701 has its CatchHandler @ 00c16736 */
  stringbuf::_M_sync((stringbuf *)(this + 8),*(char **)(this + 0x50),0,uVar2);
                    /* try { // try from 00c16708 to 00c1670c has its CatchHandler @ 00c16731 */
  ios::init((ios *)this_00,(streambuf *)(this + 8));
  if (local_40 == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ==== entry=00c167b0 orig=FUN_00c167b0 size=196 name=~ostringstream ====

/* WARNING: Removing unreachable block (ram,0x00c16868) */
/* std::ostringstream::~ostringstream() */

void __thiscall std::ostringstream::~ostringstream(ostringstream *this)

{
  allocator *paVar1;
  int *piVar2;
  int iVar3;
  long lVar4;
  long lVar5;
  long *in_RSI;
  long in_FS_OFFSET;
  
  lVar4 = *(long *)(in_FS_OFFSET + 0x28);
  lVar5 = *in_RSI;
  *(long *)this = lVar5;
  *(long *)(this + *(long *)(lVar5 + -0x18)) = in_RSI[3];
  *(undefined ***)(this + 8) = &PTR__stringbuf_011b4680;
  paVar1 = (allocator *)(*(long *)(this + 0x50) + -0x18);
  if (paVar1 != (allocator *)&string::_Rep::_S_empty_rep_storage) {
    LOCK();
    piVar2 = (int *)(*(long *)(this + 0x50) + -8);
    iVar3 = *piVar2;
    *piVar2 = *piVar2 + -1;
    UNLOCK();
    if (iVar3 < 1) {
      string::_Rep::_M_destroy(paVar1);
    }
  }
  *(undefined ***)(this + 8) = &PTR__streambuf_011b2b68;
  locale::~locale((locale *)(this + 0x40));
  lVar5 = in_RSI[1];
  *(long *)this = lVar5;
  *(long *)(this + *(long *)(lVar5 + -0x18)) = in_RSI[2];
  if (lVar4 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


// ==== entry=00c16880 name=FUN_00c16880 size=261 ====

void FUN_00c16880(long *param_1,long *param_2,long *param_3)

{
  ios iVar1;
  undefined8 uVar2;
  ios *this;
  long lVar3;
  
  lVar3 = *(long *)(param_2[1] + -0x18);
  *param_1 = param_2[1];
  this = (ios *)(lVar3 + (long)param_1);
  *(long *)this = param_2[2];
  lVar3 = *(long *)(*param_3 + -0x18) + (long)param_3;
  FUN_00c71b00(this,lVar3);
  std::ios::_M_cache_locale(this,(locale *)(this + 0xd0));
  uVar2 = *(undefined8 *)(lVar3 + 0xd8);
  *(undefined8 *)(lVar3 + 0xd8) = 0;
  *(undefined8 *)(this + 0xd8) = uVar2;
  this[0xe0] = *(ios *)(lVar3 + 0xe0);
  iVar1 = *(ios *)(lVar3 + 0xe1);
  *(undefined8 *)(this + 0xe8) = 0;
  this[0xe1] = iVar1;
  lVar3 = *param_2;
  *param_1 = lVar3;
  *(long *)((long)param_1 + *(long *)(lVar3 + -0x18)) = param_2[3];
                    /* try { // try from 00c1692c to 00c16930 has its CatchHandler @ 00c16985 */
  std::streambuf::streambuf((streambuf *)(param_1 + 1),(streambuf *)(param_3 + 1));
  param_1[1] = (long)&PTR__stringbuf_011b4680;
  *(int *)(param_1 + 9) = (int)param_3[9];
  param_1[10] = param_3[10];
  param_3[10] = (long)&DAT_011c5338;
                    /* try { // try from 00c16968 to 00c1696c has its CatchHandler @ 00c16987 */
  std::stringbuf::_M_sync((stringbuf *)(param_3 + 1),&DAT_011c5338,0,0);
  *(streambuf **)((long)param_1 + *(long *)(*param_1 + -0x18) + 0xe8) = (streambuf *)(param_1 + 1);
  return;
}


// ==== entry=00c169b0 name=FUN_00c169b0 size=338 ====

void FUN_00c169b0(undefined8 *param_1,long *param_2)

{
  ios_base *this;
  undefined1 uVar1;
  undefined8 uVar2;
  long lVar3;
  
  this = (ios_base *)(param_1 + 0xb);
  std::ios_base::ios_base(this);
  *param_1 = &DAT_011b47c8;
  *(undefined2 *)(param_1 + 0x27) = 0;
  param_1[0xb] = &DAT_011b47f0;
  lVar3 = *param_2;
  param_1[0x26] = 0;
  param_1[0x28] = 0;
  lVar3 = *(long *)(lVar3 + -0x18);
  param_1[0x29] = 0;
  param_1[0x2a] = 0;
  lVar3 = lVar3 + (long)param_2;
  param_1[0x2b] = 0;
  FUN_00c71b00(this,lVar3);
                    /* try { // try from 00c16a42 to 00c16a46 has its CatchHandler @ 00c16b02 */
  std::ios::_M_cache_locale((ios *)this,(locale *)(param_1 + 0x25));
  uVar2 = *(undefined8 *)(lVar3 + 0xd8);
  *(undefined8 *)(lVar3 + 0xd8) = 0;
  param_1[0x26] = uVar2;
  *(undefined1 *)(param_1 + 0x27) = *(undefined1 *)(lVar3 + 0xe0);
  uVar1 = *(undefined1 *)(lVar3 + 0xe1);
  param_1[0x28] = 0;
  *(undefined1 *)((long)param_1 + 0x139) = uVar1;
  *param_1 = &PTR__ostringstream_011b4838;
  param_1[0xb] = &PTR__ostringstream_011b4860;
                    /* try { // try from 00c16aaf to 00c16ab3 has its CatchHandler @ 00c16b0c */
  std::streambuf::streambuf((streambuf *)(param_1 + 1),(streambuf *)(param_2 + 1));
  param_1[1] = &PTR__stringbuf_011b4680;
  *(int *)(param_1 + 9) = (int)param_2[9];
  param_1[10] = param_2[10];
  param_2[10] = (long)&DAT_011c5338;
                    /* try { // try from 00c16ae7 to 00c16aeb has its CatchHandler @ 00c16b07 */
  std::stringbuf::_M_sync((stringbuf *)(param_2 + 1),&DAT_011c5338,0,0);
  param_1[0x28] = (streambuf *)(param_1 + 1);
  return;
}


// ==== entry=00c16b40 name=FUN_00c16b40 size=337 ====

long * FUN_00c16b40(long *param_1,long *param_2)

{
  ios iVar1;
  undefined8 uVar2;
  ios *this;
  ios *this_00;
  long in_FS_OFFSET;
  locale local_50 [8];
  locale local_48 [8];
  long local_40;
  
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  this_00 = (ios *)(*(long *)(*param_1 + -0x18) + (long)param_1);
  this = (ios *)(*(long *)(*param_2 + -0x18) + (long)param_2);
  FUN_00c71c10(this_00,this);
  std::ios::_M_cache_locale(this_00,(locale *)(this_00 + 0xd0));
  std::ios::_M_cache_locale(this,(locale *)(this + 0xd0));
  uVar2 = *(undefined8 *)(this_00 + 0xd8);
  *(undefined8 *)(this_00 + 0xd8) = *(undefined8 *)(this + 0xd8);
  *(undefined8 *)(this + 0xd8) = uVar2;
  iVar1 = this_00[0xe0];
  this_00[0xe0] = this[0xe0];
  this[0xe0] = iVar1;
  iVar1 = this_00[0xe1];
  this_00[0xe1] = this[0xe1];
  this[0xe1] = iVar1;
  std::streambuf::operator=((streambuf *)(param_1 + 1),(streambuf *)(param_2 + 1));
  std::locale::locale(local_48,(locale *)(param_2 + 8));
  std::locale::locale(local_50,(locale *)(param_1 + 8));
  std::locale::operator=((locale *)(param_1 + 8),local_48);
  std::locale::~locale(local_50);
  std::locale::~locale(local_48);
  *(int *)(param_1 + 9) = (int)param_2[9];
  std::string::swap((string *)(param_1 + 10),(string *)(param_2 + 10));
  std::stringbuf::_M_sync((stringbuf *)(param_2 + 1),(char *)param_2[10],0,0);
  if (local_40 == *(long *)(in_FS_OFFSET + 0x28)) {
    return param_1;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ==== entry=00c16ca0 name=FUN_00c16ca0 size=504 ====

void FUN_00c16ca0(long *param_1,long *param_2)

{
  locale *this;
  locale *this_00;
  ios iVar1;
  undefined8 uVar2;
  long lVar3;
  long lVar4;
  ios *this_01;
  ios *this_02;
  long in_FS_OFFSET;
  locale alStack_58 [8];
  locale local_50 [8];
  locale local_48 [8];
  long local_40;
  
  this = (locale *)(param_1 + 8);
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  this_02 = (ios *)(*(long *)(*param_1 + -0x18) + (long)param_1);
  this_01 = (ios *)(*(long *)(*param_2 + -0x18) + (long)param_2);
  FUN_00c71c10(this_02,this_01);
  std::ios::_M_cache_locale(this_02,(locale *)(this_02 + 0xd0));
  std::ios::_M_cache_locale(this_01,(locale *)(this_01 + 0xd0));
  uVar2 = *(undefined8 *)(this_02 + 0xd8);
  *(undefined8 *)(this_02 + 0xd8) = *(undefined8 *)(this_01 + 0xd8);
  *(undefined8 *)(this_01 + 0xd8) = uVar2;
  iVar1 = this_02[0xe0];
  this_02[0xe0] = this_01[0xe0];
  this_01[0xe0] = iVar1;
  iVar1 = this_02[0xe1];
  this_02[0xe1] = this_01[0xe1];
  lVar3 = param_2[2];
  this_00 = (locale *)(param_2 + 8);
  this_01[0xe1] = iVar1;
  lVar4 = param_1[2];
  param_1[2] = lVar3;
  param_2[2] = lVar4;
  lVar3 = param_1[3];
  param_1[3] = param_2[3];
  param_2[3] = lVar3;
  lVar3 = param_1[4];
  param_1[4] = param_2[4];
  param_2[4] = lVar3;
  lVar3 = param_1[5];
  param_1[5] = param_2[5];
  param_2[5] = lVar3;
  lVar3 = param_1[6];
  param_1[6] = param_2[6];
  param_2[6] = lVar3;
  lVar3 = param_1[7];
  param_1[7] = param_2[7];
  param_2[7] = lVar3;
  std::locale::locale(local_48,this);
  std::locale::operator=(this,this_00);
  std::locale::operator=(this_00,local_48);
  std::locale::~locale(local_48);
  std::locale::locale(local_48,this_00);
  std::locale::locale(local_50,this);
  std::locale::operator=(this,local_48);
  std::locale::locale(alStack_58,this_00);
                    /* try { // try from 00c16e35 to 00c16e37 has its CatchHandler @ 00c16e98 */
  (**(code **)(param_2[1] + 0x10))(param_2 + 1,local_50);
  std::locale::operator=(this_00,local_50);
  std::locale::~locale(alStack_58);
  std::locale::~locale(local_50);
  std::locale::~locale(local_48);
  lVar3 = param_1[9];
  *(int *)(param_1 + 9) = (int)param_2[9];
  *(int *)(param_2 + 9) = (int)lVar3;
  std::string::swap((string *)(param_1 + 10),(string *)(param_2 + 10));
  if (local_40 == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ==== entry=00c16ec0 orig=FUN_00c16ec0 size=5 name=rdbuf ====

/* std::ostringstream::rdbuf() const */

ostringstream * __thiscall std::ostringstream::rdbuf(ostringstream *this)

{
  return this + 8;
}


// ==== entry=00c16ed0 orig=FUN_00c16ed0 size=150 name=str ====

/* std::ostringstream::str() const */

void std::ostringstream::str(void)

{
  ulong uVar1;
  char *pcVar2;
  long in_RSI;
  string *in_RDI;
  long in_FS_OFFSET;
  allocator local_21;
  long local_20;
  
  local_20 = *(long *)(in_FS_OFFSET + 0x28);
  string::string(in_RDI,&local_21);
  uVar1 = *(ulong *)(in_RSI + 0x30);
  if (uVar1 == 0) {
    string::assign(in_RDI,(string *)(in_RSI + 0x50));
  }
  else {
    pcVar2 = *(char **)(in_RSI + 0x28);
    if (*(ulong *)(in_RSI + 0x20) < uVar1) {
      string::s_basic_string__replace_52baa6
                (in_RDI,0,*(ulong *)(*(long *)in_RDI + -0x18),pcVar2,uVar1 - (long)pcVar2);
    }
    else {
                    /* try { // try from 00c16f20 to 00c16f6b has its CatchHandler @ 00c16f73 */
      string::s_basic_string__replace_52baa6
                (in_RDI,0,*(ulong *)(*(long *)in_RDI + -0x18),pcVar2,
                 *(ulong *)(in_RSI + 0x20) - (long)pcVar2);
    }
  }
  if (local_20 == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ==== entry=00c16fa0 orig=FUN_00c16fa0 size=61 name=str ====

/* std::ostringstream::str(std::string const&) */

void __thiscall std::ostringstream::str(ostringstream *this,string *param_1)

{
  ulong uVar1;
  
  string::s_basic_string__assign_65a9ea
            ((string *)(this + 0x50),*(char **)param_1,*(ulong *)(*(char **)param_1 + -0x18));
  uVar1 = 0;
  if (((byte)this[0x48] & 3) != 0) {
    uVar1 = *(ulong *)(*(char **)(this + 0x50) + -0x18);
  }
  stringbuf::_M_sync((stringbuf *)(this + 8),*(char **)(this + 0x50),0,uVar1);
  return;
}


// ==== entry=00c16fe0 orig=FUN_00c16fe0 size=284 name=stringstream ====

/* std::stringstream::stringstream(std::_Ios_Openmode) */

void __thiscall std::stringstream::stringstream(stringstream *this,long *param_2,undefined4 param_3)

{
  long lVar1;
  
  lVar1 = param_2[2];
  *(long *)this = lVar1;
  *(long *)(this + *(long *)(lVar1 + -0x18)) = param_2[3];
  *(undefined8 *)(this + 8) = 0;
  ios::init((ios *)(this + *(long *)(lVar1 + -0x18)),(streambuf *)0x0);
  lVar1 = param_2[4];
  *(long *)(this + 0x10) = lVar1;
  lVar1 = *(long *)(lVar1 + -0x18);
  *(long *)(this + lVar1 + 0x10) = param_2[5];
                    /* try { // try from 00c17036 to 00c1703a has its CatchHandler @ 00c170fc */
  ios::init((ios *)(this + lVar1 + 0x10),(streambuf *)0x0);
  lVar1 = param_2[1];
  *(long *)this = lVar1;
  *(long *)(this + *(long *)(lVar1 + -0x18)) = param_2[6];
  *(long *)(this + 0x10) = param_2[7];
  lVar1 = *param_2;
  *(long *)this = lVar1;
  *(long *)(this + *(long *)(lVar1 + -0x18)) = param_2[8];
  lVar1 = param_2[9];
  *(undefined8 *)(this + 0x20) = 0;
  *(long *)(this + 0x10) = lVar1;
  *(undefined8 *)(this + 0x28) = 0;
  *(undefined8 *)(this + 0x30) = 0;
  *(undefined ***)(this + 0x18) = &PTR__streambuf_011b2b68;
  *(undefined8 *)(this + 0x38) = 0;
  *(undefined8 *)(this + 0x40) = 0;
  *(undefined8 *)(this + 0x48) = 0;
  locale::locale((locale *)(this + 0x50));
  *(undefined4 *)(this + 0x58) = param_3;
  *(undefined ***)(this + 0x18) = &PTR__stringbuf_011b4680;
  *(undefined1 **)(this + 0x60) = &DAT_011c5338;
                    /* try { // try from 00c170ec to 00c170f0 has its CatchHandler @ 00c170fe */
  ios::init((ios *)(this + *(long *)(*(long *)this + -0x18)),(streambuf *)(this + 0x18));
  return;
}


// ==== entry=00c17190 orig=FUN_00c17190 size=328 name=stringstream ====

/* std::stringstream::stringstream(std::_Ios_Openmode) */

void __thiscall std::stringstream::stringstream(stringstream *this,undefined4 param_2)

{
  ios_base *this_00;
  
  this_00 = (ios_base *)(this + 0x68);
  ios_base::ios_base(this_00);
  *(undefined **)this = &DAT_011b48d8;
  *(undefined2 *)(this + 0x148) = 0;
  *(undefined8 *)(this + 0x140) = 0;
  *(undefined8 *)(this + 0x150) = 0;
  *(undefined8 *)(this + 0x158) = 0;
  *(undefined8 *)(this + 0x160) = 0;
  *(undefined8 *)(this + 0x168) = 0;
  *(undefined **)(this + 0x68) = &DAT_011b4900;
  *(undefined8 *)(this + 8) = 0;
                    /* try { // try from 00c17210 to 00c17214 has its CatchHandler @ 00c172d8 */
  ios::init((ios *)this_00,(streambuf *)0x0);
  *(undefined **)(this + 0x10) = &DAT_011b4888;
  *(undefined **)(this + 0x68) = &DAT_011b48b0;
                    /* try { // try from 00c1722d to 00c17231 has its CatchHandler @ 00c172e2 */
  ios::init((ios *)this_00,(streambuf *)0x0);
  *(undefined8 *)(this + 0x20) = 0;
  *(undefined8 *)(this + 0x28) = 0;
  *(undefined8 *)(this + 0x30) = 0;
  *(undefined8 *)this = 0x11b49f0;
  *(undefined8 *)(this + 0x10) = 0x11b4a18;
  *(undefined8 *)(this + 0x68) = 0x11b4a40;
  *(undefined8 *)(this + 0x38) = 0;
  *(undefined ***)(this + 0x18) = &PTR__streambuf_011b2b68;
  *(undefined8 *)(this + 0x40) = 0;
  *(undefined8 *)(this + 0x48) = 0;
  locale::locale((locale *)(this + 0x50));
  *(undefined4 *)(this + 0x58) = param_2;
  *(undefined ***)(this + 0x18) = &PTR__stringbuf_011b4680;
  *(undefined1 **)(this + 0x60) = &DAT_011c5338;
                    /* try { // try from 00c172c4 to 00c172c8 has its CatchHandler @ 00c172dd */
  ios::init((ios *)this_00,(streambuf *)(this + 0x18));
  return;
}


// ==== entry=00c17330 orig=FUN_00c17330 size=377 name=stringstream ====

/* std::stringstream::stringstream(std::string const&, std::_Ios_Openmode) */

void __thiscall
std::stringstream::stringstream(stringstream *this,long *param_1,undefined8 *param_3,uint param_4)

{
  long lVar1;
  char *pcVar2;
  ulong uVar3;
  long in_FS_OFFSET;
  allocator local_41;
  long local_40;
  
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  lVar1 = param_1[2];
  *(long *)this = lVar1;
  *(long *)(this + *(long *)(lVar1 + -0x18)) = param_1[3];
  *(undefined8 *)(this + 8) = 0;
  ios::init((ios *)(this + *(long *)(lVar1 + -0x18)),(streambuf *)0x0);
  lVar1 = param_1[4];
  *(long *)(this + 0x10) = lVar1;
  lVar1 = *(long *)(lVar1 + -0x18);
  *(long *)(this + lVar1 + 0x10) = param_1[5];
                    /* try { // try from 00c1739d to 00c173a1 has its CatchHandler @ 00c1754b */
  ios::init((ios *)(this + lVar1 + 0x10),(streambuf *)0x0);
  lVar1 = param_1[1];
  *(long *)this = lVar1;
  *(long *)(this + *(long *)(lVar1 + -0x18)) = param_1[6];
  *(long *)(this + 0x10) = param_1[7];
  lVar1 = *param_1;
  *(long *)this = lVar1;
  *(long *)(this + *(long *)(lVar1 + -0x18)) = param_1[8];
  lVar1 = param_1[9];
  *(undefined8 *)(this + 0x20) = 0;
  *(long *)(this + 0x10) = lVar1;
  *(undefined8 *)(this + 0x28) = 0;
  *(undefined8 *)(this + 0x30) = 0;
  *(undefined ***)(this + 0x18) = &PTR__streambuf_011b2b68;
  *(undefined8 *)(this + 0x38) = 0;
  *(undefined8 *)(this + 0x40) = 0;
  *(undefined8 *)(this + 0x48) = 0;
  locale::locale((locale *)(this + 0x50));
  pcVar2 = (char *)*param_3;
  *(undefined4 *)(this + 0x58) = 0;
  uVar3 = *(ulong *)(pcVar2 + -0x18);
  *(undefined ***)(this + 0x18) = &PTR__stringbuf_011b4680;
                    /* try { // try from 00c17450 to 00c17454 has its CatchHandler @ 00c17546 */
  string::string((string *)(this + 0x60),pcVar2,uVar3,&local_41);
  *(uint *)(this + 0x58) = param_4;
  uVar3 = 0;
  if ((param_4 & 3) != 0) {
    uVar3 = *(ulong *)(*(char **)(this + 0x60) + -0x18);
  }
                    /* try { // try from 00c1746e to 00c17472 has its CatchHandler @ 00c174ae */
  stringbuf::_M_sync((stringbuf *)(this + 0x18),*(char **)(this + 0x60),0,uVar3);
                    /* try { // try from 00c17480 to 00c17484 has its CatchHandler @ 00c174a9 */
  ios::init((ios *)(this + *(long *)(*(long *)this + -0x18)),(streambuf *)(this + 0x18));
  if (local_40 == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ==== entry=00c17570 orig=FUN_00c17570 size=426 name=stringstream ====

/* std::stringstream::stringstream(std::string const&, std::_Ios_Openmode) */

void __thiscall std::stringstream::stringstream(stringstream *this,undefined8 *param_1,uint param_3)

{
  ios_base *this_00;
  ulong uVar1;
  long in_FS_OFFSET;
  allocator local_41;
  long local_40;
  
  this_00 = (ios_base *)(this + 0x68);
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  ios_base::ios_base(this_00);
  *(undefined **)this = &DAT_011b48d8;
  *(undefined2 *)(this + 0x148) = 0;
  *(undefined8 *)(this + 0x140) = 0;
  *(undefined8 *)(this + 0x150) = 0;
  *(undefined8 *)(this + 0x158) = 0;
  *(undefined8 *)(this + 0x160) = 0;
  *(undefined8 *)(this + 0x168) = 0;
  *(undefined **)(this + 0x68) = &DAT_011b4900;
  *(undefined8 *)(this + 8) = 0;
                    /* try { // try from 00c17603 to 00c17607 has its CatchHandler @ 00c1772b */
  ios::init((ios *)this_00,(streambuf *)0x0);
  *(undefined **)(this + 0x10) = &DAT_011b4888;
  *(undefined **)(this + 0x68) = &DAT_011b48b0;
                    /* try { // try from 00c17620 to 00c17624 has its CatchHandler @ 00c17724 */
  ios::init((ios *)this_00,(streambuf *)0x0);
  *(undefined8 *)(this + 0x20) = 0;
  *(undefined8 *)(this + 0x28) = 0;
  *(undefined8 *)(this + 0x30) = 0;
  *(undefined8 *)this = 0x11b49f0;
  *(undefined8 *)(this + 0x10) = 0x11b4a18;
  *(undefined8 *)(this + 0x68) = 0x11b4a40;
  *(undefined8 *)(this + 0x38) = 0;
  *(undefined ***)(this + 0x18) = &PTR__streambuf_011b2b68;
  *(undefined8 *)(this + 0x40) = 0;
  *(undefined8 *)(this + 0x48) = 0;
  locale::locale((locale *)(this + 0x50));
  *(undefined4 *)(this + 0x58) = 0;
  *(undefined ***)(this + 0x18) = &PTR__stringbuf_011b4680;
                    /* try { // try from 00c176c8 to 00c176cc has its CatchHandler @ 00c17726 */
  string::string((string *)(this + 0x60),(char *)*param_1,*(ulong *)((char *)*param_1 + -0x18),
                 &local_41);
  *(uint *)(this + 0x58) = param_3;
  uVar1 = 0;
  if ((param_3 & 3) != 0) {
    uVar1 = *(ulong *)(*(char **)(this + 0x60) + -0x18);
  }
                    /* try { // try from 00c176e6 to 00c176ea has its CatchHandler @ 00c1771f */
  stringbuf::_M_sync((stringbuf *)(this + 0x18),*(char **)(this + 0x60),0,uVar1);
                    /* try { // try from 00c176f1 to 00c176f5 has its CatchHandler @ 00c1771a */
  ios::init((ios *)this_00,(streambuf *)(this + 0x18));
  if (local_40 == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ==== entry=00c177b0 orig=FUN_00c177b0 size=267 name=~stringstream ====

/* WARNING: Removing unreachable block (ram,0x00c178b0) */
/* std::stringstream::~stringstream() */

void __thiscall std::stringstream::~stringstream(stringstream *this)

{
  allocator *paVar1;
  int *piVar2;
  int iVar3;
  long lVar4;
  long lVar5;
  long *in_RSI;
  long in_FS_OFFSET;
  
  lVar4 = *(long *)(in_FS_OFFSET + 0x28);
  lVar5 = *in_RSI;
  *(long *)this = lVar5;
  *(long *)(this + *(long *)(lVar5 + -0x18)) = in_RSI[8];
  *(long *)(this + 0x10) = in_RSI[9];
  *(undefined ***)(this + 0x18) = &PTR__stringbuf_011b4680;
  paVar1 = (allocator *)(*(long *)(this + 0x60) + -0x18);
  if (paVar1 != (allocator *)&string::_Rep::_S_empty_rep_storage) {
    LOCK();
    piVar2 = (int *)(*(long *)(this + 0x60) + -8);
    iVar3 = *piVar2;
    *piVar2 = *piVar2 + -1;
    UNLOCK();
    if (iVar3 < 1) {
      string::_Rep::_M_destroy(paVar1);
    }
  }
  *(undefined ***)(this + 0x18) = &PTR__streambuf_011b2b68;
  locale::~locale((locale *)(this + 0x50));
  lVar5 = in_RSI[1];
  *(long *)this = lVar5;
  *(long *)(this + *(long *)(lVar5 + -0x18)) = in_RSI[6];
  *(long *)(this + 0x10) = in_RSI[7];
  lVar5 = in_RSI[4];
  *(long *)(this + 0x10) = lVar5;
  *(long *)(this + *(long *)(lVar5 + -0x18) + 0x10) = in_RSI[5];
  lVar5 = in_RSI[2];
  *(long *)this = lVar5;
  *(long *)(this + *(long *)(lVar5 + -0x18)) = in_RSI[3];
  *(undefined8 *)(this + 8) = 0;
  if (lVar4 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


// ==== entry=00c178c0 name=FUN_00c178c0 size=343 ====

void FUN_00c178c0(long *param_1,long *param_2,long *param_3)

{
  ios iVar1;
  undefined8 uVar2;
  ios *this;
  long lVar3;
  
  lVar3 = param_2[2];
  *param_1 = lVar3;
  *(long *)((long)param_1 + *(long *)(lVar3 + -0x18)) = param_2[3];
  param_1[1] = param_3[1];
  this = (ios *)(*(long *)(lVar3 + -0x18) + (long)param_1);
  lVar3 = *(long *)(*param_3 + -0x18) + (long)param_3;
  FUN_00c71b00(this,lVar3);
  std::ios::_M_cache_locale(this,(locale *)(this + 0xd0));
  uVar2 = *(undefined8 *)(lVar3 + 0xd8);
  *(undefined8 *)(lVar3 + 0xd8) = 0;
  *(undefined8 *)(this + 0xd8) = uVar2;
  this[0xe0] = *(ios *)(lVar3 + 0xe0);
  iVar1 = *(ios *)(lVar3 + 0xe1);
  *(undefined8 *)(this + 0xe8) = 0;
  this[0xe1] = iVar1;
  lVar3 = param_2[4];
  param_3[1] = 0;
  param_1[2] = lVar3;
  *(long *)((long)param_1 + *(long *)(lVar3 + -0x18) + 0x10) = param_2[5];
  lVar3 = param_2[1];
  *param_1 = lVar3;
  *(long *)((long)param_1 + *(long *)(lVar3 + -0x18)) = param_2[6];
  param_1[2] = param_2[7];
  lVar3 = *param_2;
  *param_1 = lVar3;
  *(long *)((long)param_1 + *(long *)(lVar3 + -0x18)) = param_2[8];
  param_1[2] = param_2[9];
                    /* try { // try from 00c179be to 00c179c2 has its CatchHandler @ 00c17a17 */
  std::streambuf::streambuf((streambuf *)(param_1 + 3),(streambuf *)(param_3 + 3));
  param_1[3] = (long)&PTR__stringbuf_011b4680;
  *(int *)(param_1 + 0xb) = (int)param_3[0xb];
  param_1[0xc] = param_3[0xc];
  param_3[0xc] = (long)&DAT_011c5338;
                    /* try { // try from 00c179fa to 00c179fe has its CatchHandler @ 00c17a19 */
  std::stringbuf::_M_sync((stringbuf *)(param_3 + 3),&DAT_011c5338,0,0);
  *(streambuf **)((long)param_1 + *(long *)(*param_1 + -0x18) + 0xe8) = (streambuf *)(param_1 + 3);
  return;
}


// ==== entry=00c17a80 name=FUN_00c17a80 size=362 ====

void FUN_00c17a80(undefined8 *param_1,long *param_2)

{
  ios_base *this;
  undefined1 uVar1;
  undefined8 uVar2;
  long lVar3;
  
  this = (ios_base *)(param_1 + 0xd);
  std::ios_base::ios_base(this);
  *param_1 = &DAT_011b48d8;
  *(undefined2 *)(param_1 + 0x29) = 0;
  param_1[0xd] = &DAT_011b4900;
  lVar3 = param_2[1];
  param_1[0x28] = 0;
  param_1[1] = lVar3;
  lVar3 = *param_2;
  param_1[0x2a] = 0;
  param_1[0x2b] = 0;
  lVar3 = *(long *)(lVar3 + -0x18);
  param_1[0x2c] = 0;
  param_1[0x2d] = 0;
  lVar3 = lVar3 + (long)param_2;
  FUN_00c71b00(this,lVar3);
                    /* try { // try from 00c17b1a to 00c17b1e has its CatchHandler @ 00c17bea */
  std::ios::_M_cache_locale((ios *)this,(locale *)(param_1 + 0x27));
  uVar2 = *(undefined8 *)(lVar3 + 0xd8);
  *(undefined8 *)(lVar3 + 0xd8) = 0;
  param_1[0x28] = uVar2;
  *(undefined1 *)(param_1 + 0x29) = *(undefined1 *)(lVar3 + 0xe0);
  uVar1 = *(undefined1 *)(lVar3 + 0xe1);
  param_1[0x2a] = 0;
  *(undefined1 *)((long)param_1 + 0x149) = uVar1;
  param_2[1] = 0;
  *param_1 = 0x11b49f0;
  param_1[0xd] = 0x11b4a40;
  param_1[2] = 0x11b4a18;
                    /* try { // try from 00c17b97 to 00c17b9b has its CatchHandler @ 00c17bf4 */
  std::streambuf::streambuf((streambuf *)(param_1 + 3),(streambuf *)(param_2 + 3));
  param_1[3] = &PTR__stringbuf_011b4680;
  *(int *)(param_1 + 0xb) = (int)param_2[0xb];
  param_1[0xc] = param_2[0xc];
  param_2[0xc] = (long)&DAT_011c5338;
                    /* try { // try from 00c17bcf to 00c17bd3 has its CatchHandler @ 00c17bef */
  std::stringbuf::_M_sync((stringbuf *)(param_2 + 3),&DAT_011c5338,0,0);
  param_1[0x2a] = (streambuf *)(param_1 + 3);
  return;
}


// ==== entry=00c17c40 name=FUN_00c17c40 size=362 ====

long * FUN_00c17c40(long *param_1,long *param_2)

{
  ios iVar1;
  undefined8 uVar2;
  long lVar3;
  long lVar4;
  ios *this;
  ios *this_00;
  long in_FS_OFFSET;
  locale local_50 [8];
  locale local_48 [8];
  long local_40;
  
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  this_00 = (ios *)(*(long *)(*param_1 + -0x18) + (long)param_1);
  this = (ios *)(*(long *)(*param_2 + -0x18) + (long)param_2);
  FUN_00c71c10(this_00,this);
  std::ios::_M_cache_locale(this_00,(locale *)(this_00 + 0xd0));
  std::ios::_M_cache_locale(this,(locale *)(this + 0xd0));
  uVar2 = *(undefined8 *)(this_00 + 0xd8);
  *(undefined8 *)(this_00 + 0xd8) = *(undefined8 *)(this + 0xd8);
  *(undefined8 *)(this + 0xd8) = uVar2;
  iVar1 = this_00[0xe0];
  this_00[0xe0] = this[0xe0];
  this[0xe0] = iVar1;
  iVar1 = this_00[0xe1];
  this_00[0xe1] = this[0xe1];
  lVar3 = param_2[1];
  this[0xe1] = iVar1;
  lVar4 = param_1[1];
  param_1[1] = lVar3;
  param_2[1] = lVar4;
  std::streambuf::operator=((streambuf *)(param_1 + 3),(streambuf *)(param_2 + 3));
  std::locale::locale(local_48,(locale *)(param_2 + 10));
  std::locale::locale(local_50,(locale *)(param_1 + 10));
  std::locale::operator=((locale *)(param_1 + 10),local_48);
  std::locale::~locale(local_50);
  std::locale::~locale(local_48);
  *(int *)(param_1 + 0xb) = (int)param_2[0xb];
  std::string::swap((string *)(param_1 + 0xc),(string *)(param_2 + 0xc));
  std::stringbuf::_M_sync((stringbuf *)(param_2 + 3),(char *)param_2[0xc],0,0);
  if (local_40 == *(long *)(in_FS_OFFSET + 0x28)) {
    return param_1;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ==== entry=00c17db0 name=FUN_00c17db0 size=520 ====

void FUN_00c17db0(long *param_1,long *param_2)

{
  locale *this;
  locale *this_00;
  ios iVar1;
  undefined8 uVar2;
  long lVar3;
  long lVar4;
  ios *this_01;
  ios *this_02;
  long in_FS_OFFSET;
  locale alStack_58 [8];
  locale local_50 [8];
  locale local_48 [8];
  long local_40;
  
  this = (locale *)(param_1 + 10);
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  this_02 = (ios *)(*(long *)(*param_1 + -0x18) + (long)param_1);
  this_01 = (ios *)(*(long *)(*param_2 + -0x18) + (long)param_2);
  FUN_00c71c10(this_02,this_01);
  std::ios::_M_cache_locale(this_02,(locale *)(this_02 + 0xd0));
  std::ios::_M_cache_locale(this_01,(locale *)(this_01 + 0xd0));
  uVar2 = *(undefined8 *)(this_02 + 0xd8);
  *(undefined8 *)(this_02 + 0xd8) = *(undefined8 *)(this_01 + 0xd8);
  *(undefined8 *)(this_01 + 0xd8) = uVar2;
  iVar1 = this_02[0xe0];
  this_02[0xe0] = this_01[0xe0];
  this_01[0xe0] = iVar1;
  iVar1 = this_02[0xe1];
  this_02[0xe1] = this_01[0xe1];
  lVar3 = param_2[1];
  this_00 = (locale *)(param_2 + 10);
  this_01[0xe1] = iVar1;
  lVar4 = param_1[1];
  param_1[1] = lVar3;
  param_2[1] = lVar4;
  lVar3 = param_1[4];
  param_1[4] = param_2[4];
  param_2[4] = lVar3;
  lVar3 = param_1[5];
  param_1[5] = param_2[5];
  param_2[5] = lVar3;
  lVar3 = param_1[6];
  param_1[6] = param_2[6];
  param_2[6] = lVar3;
  lVar3 = param_1[7];
  param_1[7] = param_2[7];
  param_2[7] = lVar3;
  lVar3 = param_1[8];
  param_1[8] = param_2[8];
  param_2[8] = lVar3;
  lVar3 = param_1[9];
  param_1[9] = param_2[9];
  param_2[9] = lVar3;
  std::locale::locale(local_48,this);
  std::locale::operator=(this,this_00);
  std::locale::operator=(this_00,local_48);
  std::locale::~locale(local_48);
  std::locale::locale(local_48,this_00);
  std::locale::locale(local_50,this);
  std::locale::operator=(this,local_48);
  std::locale::locale(alStack_58,this_00);
                    /* try { // try from 00c17f55 to 00c17f57 has its CatchHandler @ 00c17fb8 */
  (**(code **)(param_2[3] + 0x10))(param_2 + 3,local_50);
  std::locale::operator=(this_00,local_50);
  std::locale::~locale(alStack_58);
  std::locale::~locale(local_50);
  std::locale::~locale(local_48);
  lVar3 = param_1[0xb];
  *(int *)(param_1 + 0xb) = (int)param_2[0xb];
  *(int *)(param_2 + 0xb) = (int)lVar3;
  std::string::swap((string *)(param_1 + 0xc),(string *)(param_2 + 0xc));
  if (local_40 == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ==== entry=00c17fe0 orig=FUN_00c17fe0 size=5 name=rdbuf ====

/* std::stringstream::rdbuf() const */

stringstream * __thiscall std::stringstream::rdbuf(stringstream *this)

{
  return this + 0x18;
}


// ==== entry=00c17ff0 orig=FUN_00c17ff0 size=150 name=str ====

/* std::stringstream::str() const */

void std::stringstream::str(void)

{
  ulong uVar1;
  char *pcVar2;
  long in_RSI;
  string *in_RDI;
  long in_FS_OFFSET;
  allocator local_21;
  long local_20;
  
  local_20 = *(long *)(in_FS_OFFSET + 0x28);
  string::string(in_RDI,&local_21);
  uVar1 = *(ulong *)(in_RSI + 0x40);
  if (uVar1 == 0) {
    string::assign(in_RDI,(string *)(in_RSI + 0x60));
  }
  else {
    pcVar2 = *(char **)(in_RSI + 0x38);
    if (*(ulong *)(in_RSI + 0x30) < uVar1) {
      string::s_basic_string__replace_52baa6
                (in_RDI,0,*(ulong *)(*(long *)in_RDI + -0x18),pcVar2,uVar1 - (long)pcVar2);
    }
    else {
                    /* try { // try from 00c18040 to 00c1808b has its CatchHandler @ 00c18093 */
      string::s_basic_string__replace_52baa6
                (in_RDI,0,*(ulong *)(*(long *)in_RDI + -0x18),pcVar2,
                 *(ulong *)(in_RSI + 0x30) - (long)pcVar2);
    }
  }
  if (local_20 == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ==== entry=00c180c0 orig=FUN_00c180c0 size=61 name=str ====

/* std::stringstream::str(std::string const&) */

void __thiscall std::stringstream::str(stringstream *this,string *param_1)

{
  ulong uVar1;
  
  string::s_basic_string__assign_65a9ea
            ((string *)(this + 0x60),*(char **)param_1,*(ulong *)(*(char **)param_1 + -0x18));
  uVar1 = 0;
  if (((byte)this[0x58] & 3) != 0) {
    uVar1 = *(ulong *)(*(char **)(this + 0x60) + -0x18);
  }
  stringbuf::_M_sync((stringbuf *)(this + 0x18),*(char **)(this + 0x60),0,uVar1);
  return;
}


// ==== entry=00c18100 orig=FUN_00c18100 size=122 name=wstringbuf ====

/* std::wstringbuf::wstringbuf(std::_Ios_Openmode) */

void __thiscall std::wstringbuf::wstringbuf(wstringbuf *this,undefined4 param_2)

{
  *(undefined8 *)(this + 8) = 0;
  *(undefined8 *)(this + 0x10) = 0;
  *(undefined8 *)(this + 0x18) = 0;
  *(undefined ***)this = &PTR__wstreambuf_011b2be8;
  *(undefined8 *)(this + 0x20) = 0;
  *(undefined8 *)(this + 0x28) = 0;
  *(undefined8 *)(this + 0x30) = 0;
  locale::locale((locale *)(this + 0x38));
  *(undefined4 *)(this + 0x40) = param_2;
  *(undefined ***)this = &PTR__wstringbuf_011b4a60;
  *(undefined **)(this + 0x48) = &DAT_011c5118;
  return;
}


// ==== entry=00c18180 name=FUN_00c18180 size=373 ====

void FUN_00c18180(long *param_1,long *param_2)

{
  locale *this;
  locale *this_00;
  long lVar1;
  long in_FS_OFFSET;
  locale local_58 [8];
  locale local_50 [8];
  locale local_48 [8];
  long local_40;
  
  this = (locale *)(param_2 + 7);
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  lVar1 = param_1[1];
  param_1[1] = param_2[1];
  param_2[1] = lVar1;
  lVar1 = param_1[2];
  param_1[2] = param_2[2];
  param_2[2] = lVar1;
  lVar1 = param_1[3];
  param_1[3] = param_2[3];
  param_2[3] = lVar1;
  lVar1 = param_1[4];
  param_1[4] = param_2[4];
  param_2[4] = lVar1;
  lVar1 = param_1[5];
  param_1[5] = param_2[5];
  param_2[5] = lVar1;
  lVar1 = param_1[6];
  param_1[6] = param_2[6];
  param_2[6] = lVar1;
  this_00 = (locale *)(param_1 + 7);
  std::locale::locale(local_48,this_00);
  std::locale::operator=(this_00,this);
  std::locale::operator=(this,local_48);
  std::locale::~locale(local_48);
  std::locale::locale(local_58,this);
  std::locale::locale(local_50,this_00);
                    /* try { // try from 00c1826d to 00c1826f has its CatchHandler @ 00c182fa */
  (**(code **)(*param_1 + 0x10))(param_1,local_58);
  std::locale::operator=(this_00,local_58);
  std::locale::locale(local_48,this);
                    /* try { // try from 00c18292 to 00c18294 has its CatchHandler @ 00c182f5 */
  (**(code **)(*param_2 + 0x10))(param_2,local_50);
  std::locale::operator=(this,local_50);
  std::locale::~locale(local_48);
  std::locale::~locale(local_50);
  std::locale::~locale(local_58);
  lVar1 = param_1[8];
  *(int *)(param_1 + 8) = (int)param_2[8];
  *(int *)(param_2 + 8) = (int)lVar1;
  std::wstring::swap((wstring *)(param_1 + 9),(wstring *)(param_2 + 9));
  if (local_40 == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ==== entry=00c18330 orig=FUN_00c18330 size=166 name=str ====

/* std::wstringbuf::str() const */

void std::wstringbuf::str(void)

{
  ulong uVar1;
  wchar_t *pwVar2;
  ulong uVar3;
  long in_RSI;
  wstring *in_RDI;
  long in_FS_OFFSET;
  allocator local_21;
  long local_20;
  
  local_20 = *(long *)(in_FS_OFFSET + 0x28);
  wstring::wstring(in_RDI,&local_21);
  uVar1 = *(ulong *)(in_RSI + 0x28);
  if (uVar1 == 0) {
    wstring::assign(in_RDI,(wstring *)(in_RSI + 0x48));
  }
  else {
    pwVar2 = *(wchar_t **)(in_RSI + 0x20);
    uVar3 = (*(long *)(*(long *)in_RDI + -0x18) << 2) >> 2;
    if (*(ulong *)(in_RSI + 0x18) < uVar1) {
      wstring::s_basic_string__replace_67ed76
                (in_RDI,0,uVar3,pwVar2,(long)(uVar1 - (long)pwVar2) >> 2);
    }
    else {
                    /* try { // try from 00c1838f to 00c183d3 has its CatchHandler @ 00c183db */
      wstring::s_basic_string__replace_67ed76
                (in_RDI,0,uVar3,pwVar2,(long)(*(ulong *)(in_RSI + 0x18) - (long)pwVar2) >> 2);
    }
  }
  if (local_20 == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ==== entry=00c18400 orig=FUN_00c18400 size=40 name=_M_update_egptr ====

/* std::wstringbuf::_M_update_egptr() */

void __thiscall std::wstringbuf::_M_update_egptr(wstringbuf *this)

{
  ulong uVar1;
  
  uVar1 = *(ulong *)(this + 0x28);
  if ((uVar1 != 0) && (*(ulong *)(this + 0x18) < uVar1)) {
    if (((byte)this[0x40] & 8) == 0) {
      *(ulong *)(this + 8) = uVar1;
      *(ulong *)(this + 0x10) = uVar1;
      *(ulong *)(this + 0x18) = uVar1;
    }
    else {
      *(ulong *)(this + 0x18) = uVar1;
    }
  }
  return;
}


// ==== entry=00c18430 orig=FUN_00c18430 size=63 name=_M_pbump ====

/* std::wstringbuf::_M_pbump(wchar_t*, wchar_t*, long) */

void __thiscall
std::wstringbuf::_M_pbump(wstringbuf *this,wchar_t *param_1,wchar_t *param_2,long param_3)

{
  *(wchar_t **)(this + 0x28) = param_1;
  *(wchar_t **)(this + 0x20) = param_1;
  *(wchar_t **)(this + 0x30) = param_2;
  for (; 0x7fffffff < param_3; param_3 = param_3 + -0x7fffffff) {
    param_1 = param_1 + 0x7fffffff;
  }
  *(wchar_t **)(this + 0x28) = param_1 + (int)param_3;
  return;
}


// ==== entry=00c18470 orig=FUN_00c18470 size=142 name=_M_sync ====

/* std::wstringbuf::_M_sync(wchar_t*, unsigned long, unsigned long) */

void __thiscall
std::wstringbuf::_M_sync(wstringbuf *this,wchar_t *param_1,ulong param_2,ulong param_3)

{
  uint uVar1;
  wchar_t *pwVar2;
  wchar_t *pwVar3;
  
  pwVar3 = *(wchar_t **)(this + 0x48);
  uVar1 = *(uint *)(this + 0x40) & 0x10;
  pwVar2 = param_1 + *(long *)(pwVar3 + -6);
  if (pwVar3 == param_1) {
    pwVar3 = param_1 + *(long *)(pwVar3 + -4);
  }
  else {
    pwVar2 = pwVar2 + param_2;
    param_2 = 0;
    pwVar3 = pwVar2;
  }
  if ((*(uint *)(this + 0x40) & 8) == 0) {
    if (uVar1 != 0) {
      _M_pbump(this,param_1,pwVar3,param_3);
      *(wchar_t **)(this + 8) = pwVar2;
      *(wchar_t **)(this + 0x10) = pwVar2;
      *(wchar_t **)(this + 0x18) = pwVar2;
      return;
    }
  }
  else {
    *(wchar_t **)(this + 8) = param_1;
    *(wchar_t **)(this + 0x10) = param_1 + param_2;
    *(wchar_t **)(this + 0x18) = pwVar2;
    if (uVar1 != 0) {
      _M_pbump(this,param_1,pwVar3,param_3);
      return;
    }
  }
  return;
}


// ==== entry=00c18520 orig=FUN_00c18520 size=26 name=_M_stringbuf_init ====

/* std::wstringbuf::_M_stringbuf_init(std::_Ios_Openmode) */

void __thiscall std::wstringbuf::_M_stringbuf_init(wstringbuf *this,uint param_2)

{
  ulong uVar1;
  
  *(uint *)(this + 0x40) = param_2;
  uVar1 = 0;
  if ((param_2 & 3) != 0) {
    uVar1 = *(ulong *)(*(wchar_t **)(this + 0x48) + -6);
  }
  _M_sync(this,*(wchar_t **)(this + 0x48),0,uVar1);
  return;
}


// ==== entry=00c18540 name=FUN_00c18540 size=187 ====

wstreambuf * FUN_00c18540(wstreambuf *param_1,wstreambuf *param_2)

{
  long in_FS_OFFSET;
  locale local_40 [8];
  locale local_38 [8];
  long local_30;
  
  local_30 = *(long *)(in_FS_OFFSET + 0x28);
  std::wstreambuf::operator=(param_1,param_2);
  std::locale::locale(local_40,(locale *)(param_2 + 0x38));
  std::locale::locale(local_38,(locale *)(param_1 + 0x38));
                    /* try { // try from 00c18595 to 00c18597 has its CatchHandler @ 00c185fb */
  (**(code **)(*(long *)param_1 + 0x10))(param_1,local_40);
  std::locale::operator=((locale *)(param_1 + 0x38),local_40);
  std::locale::~locale(local_38);
  std::locale::~locale(local_40);
  *(undefined4 *)(param_1 + 0x40) = *(undefined4 *)(param_2 + 0x40);
  std::wstring::swap((wstring *)(param_1 + 0x48),(wstring *)(param_2 + 0x48));
  std::wstringbuf::_M_sync((wstringbuf *)param_2,*(wchar_t **)(param_2 + 0x48),0,0);
  if (local_30 == *(long *)(in_FS_OFFSET + 0x28)) {
    return param_1;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ==== entry=00c18620 orig=FUN_00c18620 size=449 name=overflow ====

/* WARNING: Removing unreachable block (ram,0x00c187f0) */
/* std::wstringbuf::overflow(unsigned int) */

uint __thiscall std::wstringbuf::overflow(wstringbuf *this,uint param_1)

{
  int *piVar1;
  int iVar2;
  long lVar3;
  wchar_t *pwVar4;
  uint *puVar5;
  ulong uVar6;
  long in_FS_OFFSET;
  allocator local_49;
  undefined *local_48;
  long local_40;
  
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  if (((byte)this[0x40] & 0x10) == 0) {
LAB_00c18690:
    param_1 = 0xffffffff;
  }
  else {
    if (param_1 == 0xffffffff) {
      param_1 = 0;
      goto LAB_00c18664;
    }
    puVar5 = *(uint **)(this + 0x28);
    if (puVar5 < *(uint **)(this + 0x30)) {
      *puVar5 = param_1;
    }
    else {
      lVar3 = *(long *)(*(long *)(this + 0x48) + -0x10);
      if (lVar3 == 0xffffffffffffffe) goto LAB_00c18690;
      wstring::wstring((wstring *)&local_48,&local_49);
      uVar6 = lVar3 * 2;
      if (0xffffffffffffffe < uVar6) {
        uVar6 = 0xffffffffffffffe;
      }
      if (uVar6 < 0x200) {
        uVar6 = 0x200;
      }
                    /* try { // try from 00c186f9 to 00c18798 has its CatchHandler @ 00c18800 */
      wstring::reserve((wstring *)&local_48,uVar6);
      pwVar4 = *(wchar_t **)(this + 0x20);
      if (pwVar4 != (wchar_t *)0x0) {
        wstring::s_basic_string__assign_c0f410
                  ((wstring *)&local_48,pwVar4,*(long *)(this + 0x30) - (long)pwVar4 >> 2);
      }
      uVar6 = *(long *)(local_48 + -0x18) + 1;
      if ((*(ulong *)(local_48 + -0x10) < uVar6) || (0 < *(int *)(local_48 + -8))) {
        wstring::reserve((wstring *)&local_48,uVar6);
      }
      *(uint *)(local_48 + *(long *)(local_48 + -0x18) * 4) = param_1;
      if (local_48 != &DAT_011c5118) {
        *(undefined4 *)(local_48 + -8) = 0;
        *(ulong *)(local_48 + -0x18) = uVar6;
        *(undefined4 *)(local_48 + uVar6 * 4) = 0;
      }
      wstring::swap((wstring *)(this + 0x48),(wstring *)&local_48);
      _M_sync(this,*(wchar_t **)(this + 0x48),*(long *)(this + 0x10) - *(long *)(this + 8) >> 2,
              *(long *)(this + 0x28) - *(long *)(this + 0x20) >> 2);
      if ((allocator *)(local_48 + -0x18) != (allocator *)&wstring::_Rep::_S_empty_rep_storage) {
        LOCK();
        piVar1 = (int *)(local_48 + -8);
        iVar2 = *piVar1;
        *piVar1 = *piVar1 + -1;
        UNLOCK();
        if (iVar2 < 1) {
          wstring::_Rep::_M_destroy((allocator *)(local_48 + -0x18));
        }
      }
      puVar5 = *(uint **)(this + 0x28);
    }
    *(uint **)(this + 0x28) = puVar5 + 1;
  }
LAB_00c18664:
  if (local_40 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_1;
}


// ==== entry=00c18830 orig=FUN_00c18830 size=225 name=setbuf ====

/* WARNING: Removing unreachable block (ram,0x00c1890e) */
/* std::wstringbuf::setbuf(wchar_t*, long) */

wstringbuf * __thiscall std::wstringbuf::setbuf(wstringbuf *this,wchar_t *param_1,long param_2)

{
  int *piVar1;
  int iVar2;
  long lVar3;
  undefined4 *puVar4;
  long in_FS_OFFSET;
  
  lVar3 = *(long *)(in_FS_OFFSET + 0x28);
  if ((param_1 != (wchar_t *)0x0) && (-1 < param_2)) {
    puVar4 = *(undefined4 **)(this + 0x48);
    if (*(int *)(*(long *)(this + 0x48) + -8) < 1) {
      if (puVar4 != (undefined4 *)&DAT_011c5118) {
        puVar4[-2] = 0;
        *(undefined8 *)(puVar4 + -6) = 0;
        *puVar4 = 0;
      }
    }
    else {
      if ((allocator *)(puVar4 + -6) != (allocator *)&wstring::_Rep::_S_empty_rep_storage) {
        LOCK();
        piVar1 = puVar4 + -2;
        iVar2 = *piVar1;
        *piVar1 = *piVar1 + -1;
        UNLOCK();
        if (iVar2 < 1) {
          wstring::_Rep::_M_destroy((allocator *)(puVar4 + -6));
        }
      }
      *(undefined **)(this + 0x48) = &DAT_011c5118;
    }
    _M_sync(this,param_1,param_2,0);
  }
  if (lVar3 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return this;
}


// ==== entry=00c18920 name=FUN_00c18920 size=80 ====

void FUN_00c18920(wstreambuf *param_1,wstreambuf *param_2)

{
  std::wstreambuf::wstreambuf(param_1,param_2);
  *(undefined ***)param_1 = &PTR__wstringbuf_011b4a60;
  *(undefined4 *)(param_1 + 0x40) = *(undefined4 *)(param_2 + 0x40);
  *(undefined8 *)(param_1 + 0x48) = *(undefined8 *)(param_2 + 0x48);
  *(undefined **)(param_2 + 0x48) = &DAT_011c5118;
                    /* try { // try from 00c18964 to 00c18968 has its CatchHandler @ 00c18970 */
  std::wstringbuf::_M_sync((wstringbuf *)param_2,(wchar_t *)&DAT_011c5118,0,0);
  return;
}


// ==== entry=00c18990 orig=FUN_00c18990 size=47 name=str ====

/* std::wstringbuf::str(std::wstring const&) */

void __thiscall std::wstringbuf::str(wstringbuf *this,wstring *param_1)

{
  ulong uVar1;
  
  wstring::s_basic_string__assign_c0f410
            ((wstring *)(this + 0x48),*(wchar_t **)param_1,*(ulong *)(*(wchar_t **)param_1 + -6));
  uVar1 = 0;
  if (((byte)this[0x40] & 3) != 0) {
    uVar1 = *(ulong *)(*(wchar_t **)(this + 0x48) + -6);
  }
  _M_sync(this,*(wchar_t **)(this + 0x48),0,uVar1);
  return;
}


// ==== entry=00c189c0 orig=FUN_00c189c0 size=218 name=wstringbuf ====

/* std::wstringbuf::wstringbuf(std::wstring const&, std::_Ios_Openmode) */

void __thiscall std::wstringbuf::wstringbuf(wstringbuf *this,undefined8 *param_1,uint param_3)

{
  wchar_t *pwVar1;
  ulong uVar2;
  long in_FS_OFFSET;
  allocator local_31;
  long local_30;
  
  local_30 = *(long *)(in_FS_OFFSET + 0x28);
  *(undefined8 *)(this + 8) = 0;
  *(undefined8 *)(this + 0x10) = 0;
  *(undefined ***)this = &PTR__wstreambuf_011b2be8;
  *(undefined8 *)(this + 0x18) = 0;
  *(undefined8 *)(this + 0x20) = 0;
  *(undefined8 *)(this + 0x28) = 0;
  *(undefined8 *)(this + 0x30) = 0;
  locale::locale((locale *)(this + 0x38));
  pwVar1 = (wchar_t *)*param_1;
  *(undefined4 *)(this + 0x40) = 0;
  uVar2 = *(ulong *)(pwVar1 + -6);
  *(undefined ***)this = &PTR__wstringbuf_011b4a60;
                    /* try { // try from 00c18a57 to 00c18a5b has its CatchHandler @ 00c18a9f */
  wstring::wstring((wstring *)(this + 0x48),pwVar1,uVar2,&local_31);
  *(uint *)(this + 0x40) = param_3;
  uVar2 = 0;
  if ((param_3 & 3) != 0) {
    uVar2 = *(ulong *)(*(wchar_t **)(this + 0x48) + -6);
  }
                    /* try { // try from 00c18a73 to 00c18a77 has its CatchHandler @ 00c18a9a */
  _M_sync(this,*(wchar_t **)(this + 0x48),0,uVar2);
  if (local_30 == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ==== entry=00c18ae0 orig=FUN_00c18ae0 size=386 name=seekoff ====

/* std::wstringbuf::seekoff(long, std::_Ios_Seekdir, std::_Ios_Openmode) */

long __thiscall std::wstringbuf::seekoff(wstringbuf *this,long param_1,int param_3,uint param_4)

{
  long lVar1;
  ulong uVar2;
  long lVar3;
  uint uVar4;
  byte bVar5;
  byte bVar6;
  long lVar7;
  byte bVar8;
  long in_FS_OFFSET;
  bool bVar9;
  
  lVar1 = *(long *)(in_FS_OFFSET + 0x28);
  uVar4 = *(uint *)(this + 0x40) & 8;
  bVar9 = (param_4 & uVar4) != 0;
  bVar5 = (byte)((*(uint *)(this + 0x40) & param_4) >> 4) & 1;
  bVar8 = bVar9 & bVar5 & param_3 != 1;
  bVar5 = bVar5 & ((byte)(param_4 >> 3) ^ 1);
  bVar6 = ((byte)(param_4 >> 4) ^ 1) & bVar9;
  if (bVar6 == 0) {
    lVar7 = *(long *)(this + 0x20);
    if (((lVar7 == 0) && (param_1 != 0)) || (bVar5 == 0 && bVar8 == 0)) goto LAB_00c18bdd;
  }
  else {
    lVar7 = *(long *)(this + 8);
    if ((lVar7 == 0) && (param_1 != 0)) {
LAB_00c18bdd:
      param_1 = -1;
      goto LAB_00c18be4;
    }
  }
  uVar2 = *(ulong *)(this + 0x28);
  if ((uVar2 != 0) && (*(ulong *)(this + 0x18) < uVar2)) {
    if (uVar4 == 0) {
      *(ulong *)(this + 8) = uVar2;
      *(ulong *)(this + 0x10) = uVar2;
    }
    *(ulong *)(this + 0x18) = uVar2;
  }
  if (param_3 == 1) {
    lVar3 = ((long)(uVar2 - lVar7) >> 2) + param_1;
    param_1 = param_1 + (*(long *)(this + 0x10) - lVar7 >> 2);
  }
  else {
    lVar3 = param_1;
    if (param_3 == 2) {
      param_1 = param_1 + (*(long *)(this + 0x18) - lVar7 >> 2);
      lVar3 = param_1;
    }
  }
  if (((bVar6 == 0 && bVar8 == 0) || (param_1 < 0)) ||
     (*(long *)(this + 0x18) - lVar7 >> 2 < param_1)) {
    param_1 = -1;
  }
  else {
    *(long *)(this + 0x10) = *(long *)(this + 8) + param_1 * 4;
  }
  if (((-1 < lVar3) && (bVar5 != 0 || bVar8 != 0)) && (lVar3 <= *(long *)(this + 0x18) - lVar7 >> 2)
     ) {
    _M_pbump(this,*(wchar_t **)(this + 0x20),*(wchar_t **)(this + 0x30),lVar3);
    param_1 = lVar3;
  }
LAB_00c18be4:
  if (lVar1 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_1;
}


// ==== entry=00c18c80 orig=FUN_00c18c80 size=243 name=seekpos ====

/* std::wstringbuf::seekpos(std::fpos<__mbstate_t>, std::_Ios_Openmode) */

long std::wstringbuf::seekpos(wstringbuf *param_1,long param_2,undefined8 param_3,uint param_4)

{
  long lVar1;
  ulong uVar2;
  uint uVar3;
  uint uVar4;
  long lVar5;
  long in_FS_OFFSET;
  
  lVar1 = *(long *)(in_FS_OFFSET + 0x28);
  uVar3 = *(uint *)(param_1 + 0x40) & param_4;
  uVar4 = *(uint *)(param_1 + 0x40) & 8;
  param_4 = param_4 & uVar4;
  if (param_4 == 0) {
    lVar5 = *(long *)(param_1 + 0x20);
  }
  else {
    lVar5 = *(long *)(param_1 + 8);
  }
  if (((lVar5 != 0) || (param_2 == 0)) && ((uVar3 & 0x18) != 0)) {
    uVar2 = *(ulong *)(param_1 + 0x28);
    if ((uVar2 != 0) && (*(ulong *)(param_1 + 0x18) < uVar2)) {
      if (uVar4 == 0) {
        *(ulong *)(param_1 + 8) = uVar2;
        *(ulong *)(param_1 + 0x10) = uVar2;
      }
      *(ulong *)(param_1 + 0x18) = uVar2;
    }
    if ((-1 < param_2) && (param_2 <= *(long *)(param_1 + 0x18) - lVar5 >> 2)) {
      if (param_4 != 0) {
        *(long *)(param_1 + 0x10) = *(long *)(param_1 + 8) + param_2 * 4;
      }
      if ((uVar3 & 0x10) != 0) {
        _M_pbump(param_1,*(wchar_t **)(param_1 + 0x20),*(wchar_t **)(param_1 + 0x30),param_2);
      }
      goto LAB_00c18cce;
    }
  }
  param_2 = -1;
LAB_00c18cce:
  if (lVar1 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_2;
}


// ==== entry=00c18d90 name=FUN_00c18d90 size=68 ====

void FUN_00c18d90(wstreambuf *param_1,wstreambuf *param_2)

{
  std::wstreambuf::wstreambuf(param_1,param_2);
  *(undefined ***)param_1 = &PTR__wstringbuf_011b4a60;
  *(undefined4 *)(param_1 + 0x40) = *(undefined4 *)(param_2 + 0x40);
  *(undefined8 *)(param_1 + 0x48) = *(undefined8 *)(param_2 + 0x48);
  *(undefined **)(param_2 + 0x48) = &DAT_011c5118;
  return;
}


// ==== entry=00c18de0 name=FUN_00c18de0 size=1 ====

void FUN_00c18de0(void)

{
  return;
}


// ==== entry=00c18df0 orig=FUN_00c18df0 size=222 name=wistringstream ====

/* std::wistringstream::wistringstream(std::_Ios_Openmode) */

void __thiscall std::wistringstream::wistringstream(wistringstream *this,long *param_2,uint param_3)

{
  long lVar1;
  
  lVar1 = param_2[1];
  *(long *)this = lVar1;
  *(long *)(this + *(long *)(lVar1 + -0x18)) = param_2[2];
  *(undefined8 *)(this + 8) = 0;
  wios::init((wios *)(this + *(long *)(lVar1 + -0x18)),(wstreambuf *)0x0);
  lVar1 = *param_2;
  *(long *)this = lVar1;
  *(long *)(this + *(long *)(lVar1 + -0x18)) = param_2[3];
  *(undefined8 *)(this + 0x18) = 0;
  *(undefined8 *)(this + 0x20) = 0;
  *(undefined ***)(this + 0x10) = &PTR__wstreambuf_011b2be8;
  *(undefined8 *)(this + 0x28) = 0;
  *(undefined8 *)(this + 0x30) = 0;
  *(undefined8 *)(this + 0x38) = 0;
  *(undefined8 *)(this + 0x40) = 0;
  locale::locale((locale *)(this + 0x48));
  *(uint *)(this + 0x50) = param_3 | 8;
  *(undefined ***)(this + 0x10) = &PTR__wstringbuf_011b4a60;
  *(undefined **)(this + 0x58) = &DAT_011c5118;
                    /* try { // try from 00c18ebe to 00c18ec2 has its CatchHandler @ 00c18ece */
  wios::init((wios *)(this + *(long *)(*(long *)this + -0x18)),(wstreambuf *)(this + 0x10));
  return;
}


// ==== entry=00c18f00 orig=FUN_00c18f00 size=290 name=wistringstream ====

/* std::wistringstream::wistringstream(std::_Ios_Openmode) */

void __thiscall std::wistringstream::wistringstream(wistringstream *this,uint param_2)

{
  ios_base *this_00;
  
  this_00 = (ios_base *)(this + 0x60);
  ios_base::ios_base(this_00);
  *(undefined **)this = &DAT_011b4ae8;
  *(undefined8 *)(this + 0x138) = 0;
  *(undefined4 *)(this + 0x140) = 0;
  this[0x144] = (wistringstream)0x0;
  *(undefined8 *)(this + 0x148) = 0;
  *(undefined8 *)(this + 0x150) = 0;
  *(undefined8 *)(this + 0x158) = 0;
  *(undefined8 *)(this + 0x160) = 0;
  *(undefined **)(this + 0x60) = &DAT_011b4b10;
  *(undefined8 *)(this + 8) = 0;
                    /* try { // try from 00c18f81 to 00c18f85 has its CatchHandler @ 00c19022 */
  wios::init((wios *)this_00,(wstreambuf *)0x0);
  *(undefined8 *)(this + 0x18) = 0;
  *(undefined8 *)(this + 0x20) = 0;
  *(undefined8 *)(this + 0x28) = 0;
  *(undefined8 *)(this + 0x60) = 0x11b4b80;
  *(undefined8 *)this = 0x11b4b58;
  *(undefined8 *)(this + 0x30) = 0;
  *(undefined ***)(this + 0x10) = &PTR__wstreambuf_011b2be8;
  *(undefined8 *)(this + 0x38) = 0;
  *(undefined8 *)(this + 0x40) = 0;
  locale::locale((locale *)(this + 0x48));
  *(uint *)(this + 0x50) = param_2 | 8;
  *(undefined ***)(this + 0x10) = &PTR__wstringbuf_011b4a60;
  *(undefined **)(this + 0x58) = &DAT_011c5118;
                    /* try { // try from 00c19014 to 00c19018 has its CatchHandler @ 00c19027 */
  wios::init((wios *)this_00,(wstreambuf *)(this + 0x10));
  return;
}


// ==== entry=00c19060 orig=FUN_00c19060 size=324 name=wistringstream ====

/* std::wistringstream::wistringstream(std::wstring const&, std::_Ios_Openmode) */

void __thiscall
std::wistringstream::wistringstream
          (wistringstream *this,long *param_1,undefined8 *param_3,uint param_4)

{
  long lVar1;
  wchar_t *pwVar2;
  ulong uVar3;
  long in_FS_OFFSET;
  allocator local_41;
  long local_40;
  
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  lVar1 = param_1[1];
  *(long *)this = lVar1;
  *(long *)(this + *(long *)(lVar1 + -0x18)) = param_1[2];
  *(undefined8 *)(this + 8) = 0;
  wios::init((wios *)(this + *(long *)(lVar1 + -0x18)),(wstreambuf *)0x0);
  lVar1 = *param_1;
  *(long *)this = lVar1;
  *(long *)(this + *(long *)(lVar1 + -0x18)) = param_1[3];
  *(undefined8 *)(this + 0x18) = 0;
  *(undefined ***)(this + 0x10) = &PTR__wstreambuf_011b2be8;
  *(undefined8 *)(this + 0x20) = 0;
  *(undefined8 *)(this + 0x28) = 0;
  *(undefined8 *)(this + 0x30) = 0;
  *(undefined8 *)(this + 0x38) = 0;
  *(undefined8 *)(this + 0x40) = 0;
  locale::locale((locale *)(this + 0x48));
  pwVar2 = (wchar_t *)*param_3;
  *(undefined4 *)(this + 0x50) = 0;
  uVar3 = *(ulong *)(pwVar2 + -6);
  *(undefined ***)(this + 0x10) = &PTR__wstringbuf_011b4a60;
                    /* try { // try from 00c19144 to 00c19148 has its CatchHandler @ 00c191ae */
  wstring::wstring((wstring *)(this + 0x58),pwVar2,uVar3,&local_41);
  uVar3 = 0;
  *(uint *)(this + 0x50) = param_4 | 8;
  if ((param_4 & 3) != 0) {
    uVar3 = *(ulong *)(*(wchar_t **)(this + 0x58) + -6);
  }
                    /* try { // try from 00c19169 to 00c1916d has its CatchHandler @ 00c191a9 */
  wstringbuf::_M_sync((wstringbuf *)(this + 0x10),*(wchar_t **)(this + 0x58),0,uVar3);
                    /* try { // try from 00c1917b to 00c1917f has its CatchHandler @ 00c191a4 */
  wios::init((wios *)(this + *(long *)(*(long *)this + -0x18)),(wstreambuf *)(this + 0x10));
  if (local_40 == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ==== entry=00c19220 orig=FUN_00c19220 size=401 name=wistringstream ====

/* std::wistringstream::wistringstream(std::wstring const&, std::_Ios_Openmode) */

void __thiscall
std::wistringstream::wistringstream(wistringstream *this,undefined8 *param_1,uint param_3)

{
  ios_base *this_00;
  wchar_t *pwVar1;
  ulong uVar2;
  long in_FS_OFFSET;
  allocator local_41;
  long local_40;
  
  this_00 = (ios_base *)(this + 0x60);
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  ios_base::ios_base(this_00);
  *(undefined **)this = &DAT_011b4ae8;
  *(undefined8 *)(this + 0x138) = 0;
  *(undefined4 *)(this + 0x140) = 0;
  this[0x144] = (wistringstream)0x0;
  *(undefined8 *)(this + 0x148) = 0;
  *(undefined8 *)(this + 0x150) = 0;
  *(undefined8 *)(this + 0x158) = 0;
  *(undefined8 *)(this + 0x160) = 0;
  *(undefined **)(this + 0x60) = &DAT_011b4b10;
  *(undefined8 *)(this + 8) = 0;
                    /* try { // try from 00c192ba to 00c192be has its CatchHandler @ 00c19429 */
  wios::init((wios *)this_00,(wstreambuf *)0x0);
  *(undefined8 *)(this + 0x18) = 0;
  *(undefined8 *)(this + 0x20) = 0;
  *(undefined8 *)(this + 0x28) = 0;
  *(undefined8 *)this = 0x11b4b58;
  *(undefined8 *)(this + 0x60) = 0x11b4b80;
  *(undefined8 *)(this + 0x30) = 0;
  *(undefined ***)(this + 0x10) = &PTR__wstreambuf_011b2be8;
  *(undefined8 *)(this + 0x38) = 0;
  *(undefined8 *)(this + 0x40) = 0;
  locale::locale((locale *)(this + 0x48));
  pwVar1 = (wchar_t *)*param_1;
  *(undefined4 *)(this + 0x50) = 0;
  uVar2 = *(ulong *)(pwVar1 + -6);
  *(undefined ***)(this + 0x10) = &PTR__wstringbuf_011b4a60;
                    /* try { // try from 00c1935c to 00c19360 has its CatchHandler @ 00c19424 */
  wstring::wstring((wstring *)(this + 0x58),pwVar1,uVar2,&local_41);
  uVar2 = 0;
  *(uint *)(this + 0x50) = param_3 | 8;
  if ((param_3 & 3) != 0) {
    uVar2 = *(ulong *)(*(wchar_t **)(this + 0x58) + -6);
  }
                    /* try { // try from 00c1937d to 00c19381 has its CatchHandler @ 00c193b6 */
  wstringbuf::_M_sync((wstringbuf *)(this + 0x10),*(wchar_t **)(this + 0x58),0,uVar2);
                    /* try { // try from 00c19388 to 00c1938c has its CatchHandler @ 00c193b1 */
  wios::init((wios *)this_00,(wstreambuf *)(this + 0x10));
  if (local_40 == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ==== entry=00c19430 orig=FUN_00c19430 size=204 name=~wistringstream ====

/* WARNING: Removing unreachable block (ram,0x00c194f8) */
/* std::wistringstream::~wistringstream() */

void __thiscall std::wistringstream::~wistringstream(wistringstream *this)

{
  allocator *paVar1;
  int *piVar2;
  int iVar3;
  long lVar4;
  long lVar5;
  long *in_RSI;
  long in_FS_OFFSET;
  
  lVar4 = *(long *)(in_FS_OFFSET + 0x28);
  lVar5 = *in_RSI;
  *(long *)this = lVar5;
  *(long *)(this + *(long *)(lVar5 + -0x18)) = in_RSI[3];
  *(undefined ***)(this + 0x10) = &PTR__wstringbuf_011b4a60;
  paVar1 = (allocator *)(*(long *)(this + 0x58) + -0x18);
  if (paVar1 != (allocator *)&wstring::_Rep::_S_empty_rep_storage) {
    LOCK();
    piVar2 = (int *)(*(long *)(this + 0x58) + -8);
    iVar3 = *piVar2;
    *piVar2 = *piVar2 + -1;
    UNLOCK();
    if (iVar3 < 1) {
      wstring::_Rep::_M_destroy(paVar1);
    }
  }
  *(undefined ***)(this + 0x10) = &PTR__wstreambuf_011b2be8;
  locale::~locale((locale *)(this + 0x48));
  lVar5 = in_RSI[1];
  *(long *)this = lVar5;
  *(long *)(this + *(long *)(lVar5 + -0x18)) = in_RSI[2];
  *(undefined8 *)(this + 8) = 0;
  if (lVar4 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


// ==== entry=00c19510 name=FUN_00c19510 size=283 ====

void FUN_00c19510(long *param_1,long *param_2,long *param_3)

{
  wios wVar1;
  undefined8 uVar2;
  wios *this;
  long lVar3;
  
  lVar3 = param_2[1];
  *param_1 = lVar3;
  *(long *)((long)param_1 + *(long *)(lVar3 + -0x18)) = param_2[2];
  param_1[1] = param_3[1];
  this = (wios *)(*(long *)(lVar3 + -0x18) + (long)param_1);
  lVar3 = *(long *)(*param_3 + -0x18) + (long)param_3;
  FUN_00c71b00(this,lVar3);
  std::wios::_M_cache_locale(this,(locale *)(this + 0xd0));
  uVar2 = *(undefined8 *)(lVar3 + 0xd8);
  *(undefined8 *)(lVar3 + 0xd8) = 0;
  *(undefined8 *)(this + 0xd8) = uVar2;
  *(undefined4 *)(this + 0xe0) = *(undefined4 *)(lVar3 + 0xe0);
  wVar1 = *(wios *)(lVar3 + 0xe4);
  *(undefined8 *)(this + 0xe8) = 0;
  this[0xe4] = wVar1;
  lVar3 = *param_2;
  param_3[1] = 0;
  *param_1 = lVar3;
  *(long *)((long)param_1 + *(long *)(lVar3 + -0x18)) = param_2[3];
                    /* try { // try from 00c195d6 to 00c195da has its CatchHandler @ 00c1962b */
  std::wstreambuf::wstreambuf((wstreambuf *)(param_1 + 2),(wstreambuf *)(param_3 + 2));
  param_1[2] = (long)&PTR__wstringbuf_011b4a60;
  *(int *)(param_1 + 10) = (int)param_3[10];
  param_1[0xb] = param_3[0xb];
  param_3[0xb] = (long)&DAT_011c5118;
                    /* try { // try from 00c1960e to 00c19612 has its CatchHandler @ 00c1962d */
  std::wstringbuf::_M_sync((wstringbuf *)(param_3 + 2),(wchar_t *)&DAT_011c5118,0,0);
  *(wstreambuf **)((long)param_1 + *(long *)(*param_1 + -0x18) + 0xe8) = (wstreambuf *)(param_1 + 2)
  ;
  return;
}


// ==== entry=00c19660 name=FUN_00c19660 size=361 ====

void FUN_00c19660(undefined8 *param_1,long *param_2)

{
  ios_base *this;
  undefined1 uVar1;
  undefined8 uVar2;
  long lVar3;
  
  this = (ios_base *)(param_1 + 0xc);
  std::ios_base::ios_base(this);
  *param_1 = &DAT_011b4ae8;
  param_1[0xc] = &DAT_011b4b10;
  lVar3 = param_2[1];
  param_1[0x27] = 0;
  param_1[1] = lVar3;
  lVar3 = *param_2;
  *(undefined4 *)(param_1 + 0x28) = 0;
  lVar3 = *(long *)(lVar3 + -0x18);
  *(undefined1 *)((long)param_1 + 0x144) = 0;
  param_1[0x29] = 0;
  param_1[0x2a] = 0;
  lVar3 = lVar3 + (long)param_2;
  param_1[0x2b] = 0;
  param_1[0x2c] = 0;
  FUN_00c71b00(this,lVar3);
                    /* try { // try from 00c19702 to 00c19706 has its CatchHandler @ 00c197c9 */
  std::wios::_M_cache_locale((wios *)this,(locale *)(param_1 + 0x26));
  uVar2 = *(undefined8 *)(lVar3 + 0xd8);
  *(undefined8 *)(lVar3 + 0xd8) = 0;
  param_1[0x27] = uVar2;
  *(undefined4 *)(param_1 + 0x28) = *(undefined4 *)(lVar3 + 0xe0);
  uVar1 = *(undefined1 *)(lVar3 + 0xe4);
  param_1[0x29] = 0;
  *(undefined1 *)((long)param_1 + 0x144) = uVar1;
  param_2[1] = 0;
  *param_1 = 0x11b4b58;
  param_1[0xc] = 0x11b4b80;
                    /* try { // try from 00c19776 to 00c1977a has its CatchHandler @ 00c197d3 */
  std::wstreambuf::wstreambuf((wstreambuf *)(param_1 + 2),(wstreambuf *)(param_2 + 2));
  param_1[2] = &PTR__wstringbuf_011b4a60;
  *(int *)(param_1 + 10) = (int)param_2[10];
  param_1[0xb] = param_2[0xb];
  param_2[0xb] = (long)&DAT_011c5118;
                    /* try { // try from 00c197ae to 00c197b2 has its CatchHandler @ 00c197ce */
  std::wstringbuf::_M_sync((wstringbuf *)(param_2 + 2),(wchar_t *)&DAT_011c5118,0,0);
  param_1[0x29] = (wstreambuf *)(param_1 + 2);
  return;
}


// ==== entry=00c19810 name=FUN_00c19810 size=360 ====

long * FUN_00c19810(long *param_1,long *param_2)

{
  wios wVar1;
  undefined4 uVar2;
  undefined8 uVar3;
  long lVar4;
  long lVar5;
  wios *this;
  wios *this_00;
  long in_FS_OFFSET;
  locale local_50 [8];
  locale local_48 [8];
  long local_40;
  
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  this_00 = (wios *)(*(long *)(*param_1 + -0x18) + (long)param_1);
  this = (wios *)(*(long *)(*param_2 + -0x18) + (long)param_2);
  FUN_00c71c10(this_00,this);
  std::wios::_M_cache_locale(this_00,(locale *)(this_00 + 0xd0));
  std::wios::_M_cache_locale(this,(locale *)(this + 0xd0));
  uVar3 = *(undefined8 *)(this_00 + 0xd8);
  *(undefined8 *)(this_00 + 0xd8) = *(undefined8 *)(this + 0xd8);
  *(undefined8 *)(this + 0xd8) = uVar3;
  uVar2 = *(undefined4 *)(this_00 + 0xe0);
  *(undefined4 *)(this_00 + 0xe0) = *(undefined4 *)(this + 0xe0);
  *(undefined4 *)(this + 0xe0) = uVar2;
  wVar1 = this_00[0xe4];
  this_00[0xe4] = this[0xe4];
  lVar4 = param_2[1];
  this[0xe4] = wVar1;
  lVar5 = param_1[1];
  param_1[1] = lVar4;
  param_2[1] = lVar5;
  std::wstreambuf::operator=((wstreambuf *)(param_1 + 2),(wstreambuf *)(param_2 + 2));
  std::locale::locale(local_48,(locale *)(param_2 + 9));
  std::locale::locale(local_50,(locale *)(param_1 + 9));
  std::locale::operator=((locale *)(param_1 + 9),local_48);
  std::locale::~locale(local_50);
  std::locale::~locale(local_48);
  *(int *)(param_1 + 10) = (int)param_2[10];
  std::wstring::swap((wstring *)(param_1 + 0xb),(wstring *)(param_2 + 0xb));
  std::wstringbuf::_M_sync((wstringbuf *)(param_2 + 2),(wchar_t *)param_2[0xb],0,0);
  if (local_40 == *(long *)(in_FS_OFFSET + 0x28)) {
    return param_1;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ==== entry=00c19980 name=FUN_00c19980 size=518 ====

void FUN_00c19980(long *param_1,long *param_2)

{
  locale *this;
  locale *this_00;
  wios wVar1;
  undefined4 uVar2;
  undefined8 uVar3;
  long lVar4;
  long lVar5;
  wios *this_01;
  wios *this_02;
  long in_FS_OFFSET;
  locale alStack_58 [8];
  locale local_50 [8];
  locale local_48 [8];
  long local_40;
  
  this = (locale *)(param_1 + 9);
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  this_02 = (wios *)(*(long *)(*param_1 + -0x18) + (long)param_1);
  this_01 = (wios *)(*(long *)(*param_2 + -0x18) + (long)param_2);
  FUN_00c71c10(this_02,this_01);
  std::wios::_M_cache_locale(this_02,(locale *)(this_02 + 0xd0));
  std::wios::_M_cache_locale(this_01,(locale *)(this_01 + 0xd0));
  uVar3 = *(undefined8 *)(this_02 + 0xd8);
  *(undefined8 *)(this_02 + 0xd8) = *(undefined8 *)(this_01 + 0xd8);
  *(undefined8 *)(this_01 + 0xd8) = uVar3;
  uVar2 = *(undefined4 *)(this_02 + 0xe0);
  *(undefined4 *)(this_02 + 0xe0) = *(undefined4 *)(this_01 + 0xe0);
  *(undefined4 *)(this_01 + 0xe0) = uVar2;
  wVar1 = this_02[0xe4];
  this_02[0xe4] = this_01[0xe4];
  lVar4 = param_2[1];
  this_00 = (locale *)(param_2 + 9);
  this_01[0xe4] = wVar1;
  lVar5 = param_1[1];
  param_1[1] = lVar4;
  param_2[1] = lVar5;
  lVar4 = param_1[3];
  param_1[3] = param_2[3];
  param_2[3] = lVar4;
  lVar4 = param_1[4];
  param_1[4] = param_2[4];
  param_2[4] = lVar4;
  lVar4 = param_1[5];
  param_1[5] = param_2[5];
  param_2[5] = lVar4;
  lVar4 = param_1[6];
  param_1[6] = param_2[6];
  param_2[6] = lVar4;
  lVar4 = param_1[7];
  param_1[7] = param_2[7];
  param_2[7] = lVar4;
  lVar4 = param_1[8];
  param_1[8] = param_2[8];
  param_2[8] = lVar4;
  std::locale::locale(local_48,this);
  std::locale::operator=(this,this_00);
  std::locale::operator=(this_00,local_48);
  std::locale::~locale(local_48);
  std::locale::locale(local_48,this_00);
  std::locale::locale(local_50,this);
  std::locale::operator=(this,local_48);
  std::locale::locale(alStack_58,this_00);
                    /* try { // try from 00c19b23 to 00c19b25 has its CatchHandler @ 00c19b86 */
  (**(code **)(param_2[2] + 0x10))(param_2 + 2,local_50);
  std::locale::operator=(this_00,local_50);
  std::locale::~locale(alStack_58);
  std::locale::~locale(local_50);
  std::locale::~locale(local_48);
  lVar4 = param_1[10];
  *(int *)(param_1 + 10) = (int)param_2[10];
  *(int *)(param_2 + 10) = (int)lVar4;
  std::wstring::swap((wstring *)(param_1 + 0xb),(wstring *)(param_2 + 0xb));
  if (local_40 == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ==== entry=00c19bb0 orig=FUN_00c19bb0 size=5 name=rdbuf ====

/* std::wistringstream::rdbuf() const */

wistringstream * __thiscall std::wistringstream::rdbuf(wistringstream *this)

{
  return this + 0x10;
}


// ==== entry=00c19bc0 orig=FUN_00c19bc0 size=166 name=str ====

/* std::wistringstream::str() const */

void std::wistringstream::str(void)

{
  ulong uVar1;
  wchar_t *pwVar2;
  ulong uVar3;
  long in_RSI;
  wstring *in_RDI;
  long in_FS_OFFSET;
  allocator local_21;
  long local_20;
  
  local_20 = *(long *)(in_FS_OFFSET + 0x28);
  wstring::wstring(in_RDI,&local_21);
  uVar1 = *(ulong *)(in_RSI + 0x38);
  if (uVar1 == 0) {
    wstring::assign(in_RDI,(wstring *)(in_RSI + 0x58));
  }
  else {
    pwVar2 = *(wchar_t **)(in_RSI + 0x30);
    uVar3 = (*(long *)(*(long *)in_RDI + -0x18) << 2) >> 2;
    if (*(ulong *)(in_RSI + 0x28) < uVar1) {
      wstring::s_basic_string__replace_67ed76
                (in_RDI,0,uVar3,pwVar2,(long)(uVar1 - (long)pwVar2) >> 2);
    }
    else {
                    /* try { // try from 00c19c1f to 00c19c63 has its CatchHandler @ 00c19c6b */
      wstring::s_basic_string__replace_67ed76
                (in_RDI,0,uVar3,pwVar2,(long)(*(ulong *)(in_RSI + 0x28) - (long)pwVar2) >> 2);
    }
  }
  if (local_20 == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ==== entry=00c19c90 orig=FUN_00c19c90 size=61 name=str ====

/* std::wistringstream::str(std::wstring const&) */

void __thiscall std::wistringstream::str(wistringstream *this,wstring *param_1)

{
  ulong uVar1;
  
  wstring::s_basic_string__assign_c0f410
            ((wstring *)(this + 0x58),*(wchar_t **)param_1,*(ulong *)(*(wchar_t **)param_1 + -6));
  uVar1 = 0;
  if (((byte)this[0x50] & 3) != 0) {
    uVar1 = *(ulong *)(*(wchar_t **)(this + 0x58) + -6);
  }
  wstringbuf::_M_sync((wstringbuf *)(this + 0x10),*(wchar_t **)(this + 0x58),0,uVar1);
  return;
}


// ==== entry=00c19cd0 orig=FUN_00c19cd0 size=209 name=wostringstream ====

/* std::wostringstream::wostringstream(std::_Ios_Openmode) */

void __thiscall std::wostringstream::wostringstream(wostringstream *this,long *param_2,uint param_3)

{
  long lVar1;
  
  lVar1 = param_2[1];
  *(long *)this = lVar1;
  lVar1 = *(long *)(lVar1 + -0x18);
  *(long *)(this + lVar1) = param_2[2];
  wios::init((wios *)(this + lVar1),(wstreambuf *)0x0);
  lVar1 = *param_2;
  *(long *)this = lVar1;
  *(long *)(this + *(long *)(lVar1 + -0x18)) = param_2[3];
  *(undefined8 *)(this + 0x10) = 0;
  *(undefined8 *)(this + 0x18) = 0;
  *(undefined ***)(this + 8) = &PTR__wstreambuf_011b2be8;
  *(undefined8 *)(this + 0x20) = 0;
  *(undefined8 *)(this + 0x28) = 0;
  *(undefined8 *)(this + 0x30) = 0;
  *(undefined8 *)(this + 0x38) = 0;
  locale::locale((locale *)(this + 0x40));
  *(uint *)(this + 0x48) = param_3 | 0x10;
  *(undefined ***)(this + 8) = &PTR__wstringbuf_011b4a60;
  *(undefined **)(this + 0x50) = &DAT_011c5118;
                    /* try { // try from 00c19d91 to 00c19d95 has its CatchHandler @ 00c19da1 */
  wios::init((wios *)(this + *(long *)(*(long *)this + -0x18)),(wstreambuf *)(this + 8));
  return;
}


// ==== entry=00c19dd0 orig=FUN_00c19dd0 size=282 name=wostringstream ====

/* std::wostringstream::wostringstream(std::_Ios_Openmode) */

void __thiscall std::wostringstream::wostringstream(wostringstream *this,uint param_2)

{
  ios_base *this_00;
  
  this_00 = (ios_base *)(this + 0x58);
  ios_base::ios_base(this_00);
  *(undefined **)this = &DAT_011b4ba8;
  *(undefined8 *)(this + 0x130) = 0;
  *(undefined4 *)(this + 0x138) = 0;
  this[0x13c] = (wostringstream)0x0;
  *(undefined8 *)(this + 0x140) = 0;
  *(undefined8 *)(this + 0x148) = 0;
  *(undefined8 *)(this + 0x150) = 0;
  *(undefined8 *)(this + 0x158) = 0;
  *(undefined **)(this + 0x58) = &DAT_011b4bd0;
                    /* try { // try from 00c19e49 to 00c19e4d has its CatchHandler @ 00c19eea */
  wios::init((wios *)this_00,(wstreambuf *)0x0);
  *(undefined8 *)(this + 0x10) = 0;
  *(undefined8 *)(this + 0x18) = 0;
  *(undefined8 *)(this + 0x20) = 0;
  *(undefined8 *)(this + 0x58) = 0x11b4c40;
  *(undefined8 *)this = 0x11b4c18;
  *(undefined8 *)(this + 0x28) = 0;
  *(undefined ***)(this + 8) = &PTR__wstreambuf_011b2be8;
  *(undefined8 *)(this + 0x30) = 0;
  *(undefined8 *)(this + 0x38) = 0;
  locale::locale((locale *)(this + 0x40));
  *(uint *)(this + 0x48) = param_2 | 0x10;
  *(undefined ***)(this + 8) = &PTR__wstringbuf_011b4a60;
  *(undefined **)(this + 0x50) = &DAT_011c5118;
                    /* try { // try from 00c19edc to 00c19ee0 has its CatchHandler @ 00c19eef */
  wios::init((wios *)this_00,(wstreambuf *)(this + 8));
  return;
}


// ==== entry=00c19f20 orig=FUN_00c19f20 size=311 name=wostringstream ====

/* std::wostringstream::wostringstream(std::wstring const&, std::_Ios_Openmode) */

void __thiscall
std::wostringstream::wostringstream
          (wostringstream *this,long *param_1,undefined8 *param_3,uint param_4)

{
  long lVar1;
  wchar_t *pwVar2;
  ulong uVar3;
  long in_FS_OFFSET;
  allocator local_41;
  long local_40;
  
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  lVar1 = param_1[1];
  *(long *)this = lVar1;
  lVar1 = *(long *)(lVar1 + -0x18);
  *(long *)(this + lVar1) = param_1[2];
  wios::init((wios *)(this + lVar1),(wstreambuf *)0x0);
  lVar1 = *param_1;
  *(long *)this = lVar1;
  *(long *)(this + *(long *)(lVar1 + -0x18)) = param_1[3];
  *(undefined8 *)(this + 0x10) = 0;
  *(undefined ***)(this + 8) = &PTR__wstreambuf_011b2be8;
  *(undefined8 *)(this + 0x18) = 0;
  *(undefined8 *)(this + 0x20) = 0;
  *(undefined8 *)(this + 0x28) = 0;
  *(undefined8 *)(this + 0x30) = 0;
  *(undefined8 *)(this + 0x38) = 0;
  locale::locale((locale *)(this + 0x40));
  pwVar2 = (wchar_t *)*param_3;
  *(undefined4 *)(this + 0x48) = 0;
  uVar3 = *(ulong *)(pwVar2 + -6);
  *(undefined ***)(this + 8) = &PTR__wstringbuf_011b4a60;
                    /* try { // try from 00c19ff7 to 00c19ffb has its CatchHandler @ 00c1a061 */
  wstring::wstring((wstring *)(this + 0x50),pwVar2,uVar3,&local_41);
  uVar3 = 0;
  *(uint *)(this + 0x48) = param_4 | 0x10;
  if ((param_4 & 3) != 0) {
    uVar3 = *(ulong *)(*(wchar_t **)(this + 0x50) + -6);
  }
                    /* try { // try from 00c1a01c to 00c1a020 has its CatchHandler @ 00c1a05c */
  wstringbuf::_M_sync((wstringbuf *)(this + 8),*(wchar_t **)(this + 0x50),0,uVar3);
                    /* try { // try from 00c1a02e to 00c1a032 has its CatchHandler @ 00c1a057 */
  wios::init((wios *)(this + *(long *)(*(long *)this + -0x18)),(wstreambuf *)(this + 8));
  if (local_40 == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ==== entry=00c1a0c0 orig=FUN_00c1a0c0 size=393 name=wostringstream ====

/* std::wostringstream::wostringstream(std::wstring const&, std::_Ios_Openmode) */

void __thiscall
std::wostringstream::wostringstream(wostringstream *this,undefined8 *param_1,uint param_3)

{
  ios_base *this_00;
  wchar_t *pwVar1;
  ulong uVar2;
  long in_FS_OFFSET;
  allocator local_41;
  long local_40;
  
  this_00 = (ios_base *)(this + 0x58);
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  ios_base::ios_base(this_00);
  *(undefined **)this = &DAT_011b4ba8;
  *(undefined8 *)(this + 0x130) = 0;
  *(undefined4 *)(this + 0x138) = 0;
  this[0x13c] = (wostringstream)0x0;
  *(undefined8 *)(this + 0x140) = 0;
  *(undefined8 *)(this + 0x148) = 0;
  *(undefined8 *)(this + 0x150) = 0;
  *(undefined8 *)(this + 0x158) = 0;
  *(undefined **)(this + 0x58) = &DAT_011b4bd0;
                    /* try { // try from 00c1a152 to 00c1a156 has its CatchHandler @ 00c1a2b9 */
  wios::init((wios *)this_00,(wstreambuf *)0x0);
  *(undefined8 *)(this + 0x10) = 0;
  *(undefined8 *)(this + 0x18) = 0;
  *(undefined8 *)(this + 0x20) = 0;
  *(undefined8 *)this = 0x11b4c18;
  *(undefined8 *)(this + 0x58) = 0x11b4c40;
  *(undefined8 *)(this + 0x28) = 0;
  *(undefined ***)(this + 8) = &PTR__wstreambuf_011b2be8;
  *(undefined8 *)(this + 0x30) = 0;
  *(undefined8 *)(this + 0x38) = 0;
  locale::locale((locale *)(this + 0x40));
  pwVar1 = (wchar_t *)*param_1;
  *(undefined4 *)(this + 0x48) = 0;
  uVar2 = *(ulong *)(pwVar1 + -6);
  *(undefined ***)(this + 8) = &PTR__wstringbuf_011b4a60;
                    /* try { // try from 00c1a1f4 to 00c1a1f8 has its CatchHandler @ 00c1a2b4 */
  wstring::wstring((wstring *)(this + 0x50),pwVar1,uVar2,&local_41);
  uVar2 = 0;
  *(uint *)(this + 0x48) = param_3 | 0x10;
  if ((param_3 & 3) != 0) {
    uVar2 = *(ulong *)(*(wchar_t **)(this + 0x50) + -6);
  }
                    /* try { // try from 00c1a215 to 00c1a219 has its CatchHandler @ 00c1a24e */
  wstringbuf::_M_sync((wstringbuf *)(this + 8),*(wchar_t **)(this + 0x50),0,uVar2);
                    /* try { // try from 00c1a220 to 00c1a224 has its CatchHandler @ 00c1a249 */
  wios::init((wios *)this_00,(wstreambuf *)(this + 8));
  if (local_40 == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ==== entry=00c1a2c0 orig=FUN_00c1a2c0 size=196 name=~wostringstream ====

/* WARNING: Removing unreachable block (ram,0x00c1a378) */
/* std::wostringstream::~wostringstream() */

void __thiscall std::wostringstream::~wostringstream(wostringstream *this)

{
  allocator *paVar1;
  int *piVar2;
  int iVar3;
  long lVar4;
  long lVar5;
  long *in_RSI;
  long in_FS_OFFSET;
  
  lVar4 = *(long *)(in_FS_OFFSET + 0x28);
  lVar5 = *in_RSI;
  *(long *)this = lVar5;
  *(long *)(this + *(long *)(lVar5 + -0x18)) = in_RSI[3];
  *(undefined ***)(this + 8) = &PTR__wstringbuf_011b4a60;
  paVar1 = (allocator *)(*(long *)(this + 0x50) + -0x18);
  if (paVar1 != (allocator *)&wstring::_Rep::_S_empty_rep_storage) {
    LOCK();
    piVar2 = (int *)(*(long *)(this + 0x50) + -8);
    iVar3 = *piVar2;
    *piVar2 = *piVar2 + -1;
    UNLOCK();
    if (iVar3 < 1) {
      wstring::_Rep::_M_destroy(paVar1);
    }
  }
  *(undefined ***)(this + 8) = &PTR__wstreambuf_011b2be8;
  locale::~locale((locale *)(this + 0x40));
  lVar5 = in_RSI[1];
  *(long *)this = lVar5;
  *(long *)(this + *(long *)(lVar5 + -0x18)) = in_RSI[2];
  if (lVar4 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


// ==== entry=00c1a390 name=FUN_00c1a390 size=260 ====

void FUN_00c1a390(long *param_1,long *param_2,long *param_3)

{
  wios wVar1;
  undefined8 uVar2;
  wios *this;
  long lVar3;
  
  lVar3 = *(long *)(param_2[1] + -0x18);
  *param_1 = param_2[1];
  this = (wios *)(lVar3 + (long)param_1);
  *(long *)this = param_2[2];
  lVar3 = *(long *)(*param_3 + -0x18) + (long)param_3;
  FUN_00c71b00(this,lVar3);
  std::wios::_M_cache_locale(this,(locale *)(this + 0xd0));
  uVar2 = *(undefined8 *)(lVar3 + 0xd8);
  *(undefined8 *)(lVar3 + 0xd8) = 0;
  *(undefined8 *)(this + 0xd8) = uVar2;
  *(undefined4 *)(this + 0xe0) = *(undefined4 *)(lVar3 + 0xe0);
  wVar1 = *(wios *)(lVar3 + 0xe4);
  *(undefined8 *)(this + 0xe8) = 0;
  this[0xe4] = wVar1;
  lVar3 = *param_2;
  *param_1 = lVar3;
  *(long *)((long)param_1 + *(long *)(lVar3 + -0x18)) = param_2[3];
                    /* try { // try from 00c1a43b to 00c1a43f has its CatchHandler @ 00c1a494 */
  std::wstreambuf::wstreambuf((wstreambuf *)(param_1 + 1),(wstreambuf *)(param_3 + 1));
  param_1[1] = (long)&PTR__wstringbuf_011b4a60;
  *(int *)(param_1 + 9) = (int)param_3[9];
  param_1[10] = param_3[10];
  param_3[10] = (long)&DAT_011c5118;
                    /* try { // try from 00c1a477 to 00c1a47b has its CatchHandler @ 00c1a496 */
  std::wstringbuf::_M_sync((wstringbuf *)(param_3 + 1),(wchar_t *)&DAT_011c5118,0,0);
  *(wstreambuf **)((long)param_1 + *(long *)(*param_1 + -0x18) + 0xe8) = (wstreambuf *)(param_1 + 1)
  ;
  return;
}


// ==== entry=00c1a4c0 name=FUN_00c1a4c0 size=345 ====

void FUN_00c1a4c0(undefined8 *param_1,long *param_2)

{
  ios_base *this;
  undefined1 uVar1;
  undefined8 uVar2;
  long lVar3;
  
  this = (ios_base *)(param_1 + 0xb);
  std::ios_base::ios_base(this);
  *param_1 = &DAT_011b4ba8;
  param_1[0xb] = &DAT_011b4bd0;
  lVar3 = *param_2;
  param_1[0x26] = 0;
  lVar3 = *(long *)(lVar3 + -0x18);
  *(undefined4 *)(param_1 + 0x27) = 0;
  *(undefined1 *)((long)param_1 + 0x13c) = 0;
  param_1[0x28] = 0;
  lVar3 = lVar3 + (long)param_2;
  param_1[0x29] = 0;
  param_1[0x2a] = 0;
  param_1[0x2b] = 0;
  FUN_00c71b00(this,lVar3);
                    /* try { // try from 00c1a55a to 00c1a55e has its CatchHandler @ 00c1a619 */
  std::wios::_M_cache_locale((wios *)this,(locale *)(param_1 + 0x25));
  uVar2 = *(undefined8 *)(lVar3 + 0xd8);
  *(undefined8 *)(lVar3 + 0xd8) = 0;
  param_1[0x26] = uVar2;
  *(undefined4 *)(param_1 + 0x27) = *(undefined4 *)(lVar3 + 0xe0);
  uVar1 = *(undefined1 *)(lVar3 + 0xe4);
  param_1[0x28] = 0;
  *(undefined1 *)((long)param_1 + 0x13c) = uVar1;
  *param_1 = 0x11b4c18;
  param_1[0xb] = 0x11b4c40;
                    /* try { // try from 00c1a5c6 to 00c1a5ca has its CatchHandler @ 00c1a623 */
  std::wstreambuf::wstreambuf((wstreambuf *)(param_1 + 1),(wstreambuf *)(param_2 + 1));
  param_1[1] = &PTR__wstringbuf_011b4a60;
  *(int *)(param_1 + 9) = (int)param_2[9];
  param_1[10] = param_2[10];
  param_2[10] = (long)&DAT_011c5118;
                    /* try { // try from 00c1a5fe to 00c1a602 has its CatchHandler @ 00c1a61e */
  std::wstringbuf::_M_sync((wstringbuf *)(param_2 + 1),(wchar_t *)&DAT_011c5118,0,0);
  param_1[0x28] = (wstreambuf *)(param_1 + 1);
  return;
}


// ==== entry=00c1a660 name=FUN_00c1a660 size=335 ====

long * FUN_00c1a660(long *param_1,long *param_2)

{
  wios wVar1;
  undefined4 uVar2;
  undefined8 uVar3;
  wios *this;
  wios *this_00;
  long in_FS_OFFSET;
  locale local_50 [8];
  locale local_48 [8];
  long local_40;
  
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  this_00 = (wios *)(*(long *)(*param_1 + -0x18) + (long)param_1);
  this = (wios *)(*(long *)(*param_2 + -0x18) + (long)param_2);
  FUN_00c71c10(this_00,this);
  std::wios::_M_cache_locale(this_00,(locale *)(this_00 + 0xd0));
  std::wios::_M_cache_locale(this,(locale *)(this + 0xd0));
  uVar3 = *(undefined8 *)(this_00 + 0xd8);
  *(undefined8 *)(this_00 + 0xd8) = *(undefined8 *)(this + 0xd8);
  *(undefined8 *)(this + 0xd8) = uVar3;
  uVar2 = *(undefined4 *)(this_00 + 0xe0);
  *(undefined4 *)(this_00 + 0xe0) = *(undefined4 *)(this + 0xe0);
  *(undefined4 *)(this + 0xe0) = uVar2;
  wVar1 = this_00[0xe4];
  this_00[0xe4] = this[0xe4];
  this[0xe4] = wVar1;
  std::wstreambuf::operator=((wstreambuf *)(param_1 + 1),(wstreambuf *)(param_2 + 1));
  std::locale::locale(local_48,(locale *)(param_2 + 8));
  std::locale::locale(local_50,(locale *)(param_1 + 8));
  std::locale::operator=((locale *)(param_1 + 8),local_48);
  std::locale::~locale(local_50);
  std::locale::~locale(local_48);
  *(int *)(param_1 + 9) = (int)param_2[9];
  std::wstring::swap((wstring *)(param_1 + 10),(wstring *)(param_2 + 10));
  std::wstringbuf::_M_sync((wstringbuf *)(param_2 + 1),(wchar_t *)param_2[10],0,0);
  if (local_40 == *(long *)(in_FS_OFFSET + 0x28)) {
    return param_1;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ==== entry=00c1a7b0 name=FUN_00c1a7b0 size=502 ====

void FUN_00c1a7b0(long *param_1,long *param_2)

{
  locale *this;
  locale *this_00;
  wios wVar1;
  undefined4 uVar2;
  undefined8 uVar3;
  long lVar4;
  long lVar5;
  wios *this_01;
  wios *this_02;
  long in_FS_OFFSET;
  locale alStack_58 [8];
  locale local_50 [8];
  locale local_48 [8];
  long local_40;
  
  this = (locale *)(param_1 + 8);
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  this_02 = (wios *)(*(long *)(*param_1 + -0x18) + (long)param_1);
  this_01 = (wios *)(*(long *)(*param_2 + -0x18) + (long)param_2);
  FUN_00c71c10(this_02,this_01);
  std::wios::_M_cache_locale(this_02,(locale *)(this_02 + 0xd0));
  std::wios::_M_cache_locale(this_01,(locale *)(this_01 + 0xd0));
  uVar3 = *(undefined8 *)(this_02 + 0xd8);
  *(undefined8 *)(this_02 + 0xd8) = *(undefined8 *)(this_01 + 0xd8);
  *(undefined8 *)(this_01 + 0xd8) = uVar3;
  uVar2 = *(undefined4 *)(this_02 + 0xe0);
  *(undefined4 *)(this_02 + 0xe0) = *(undefined4 *)(this_01 + 0xe0);
  *(undefined4 *)(this_01 + 0xe0) = uVar2;
  wVar1 = this_02[0xe4];
  this_02[0xe4] = this_01[0xe4];
  lVar4 = param_2[2];
  this_00 = (locale *)(param_2 + 8);
  this_01[0xe4] = wVar1;
  lVar5 = param_1[2];
  param_1[2] = lVar4;
  param_2[2] = lVar5;
  lVar4 = param_1[3];
  param_1[3] = param_2[3];
  param_2[3] = lVar4;
  lVar4 = param_1[4];
  param_1[4] = param_2[4];
  param_2[4] = lVar4;
  lVar4 = param_1[5];
  param_1[5] = param_2[5];
  param_2[5] = lVar4;
  lVar4 = param_1[6];
  param_1[6] = param_2[6];
  param_2[6] = lVar4;
  lVar4 = param_1[7];
  param_1[7] = param_2[7];
  param_2[7] = lVar4;
  std::locale::locale(local_48,this);
  std::locale::operator=(this,this_00);
  std::locale::operator=(this_00,local_48);
  std::locale::~locale(local_48);
  std::locale::locale(local_48,this_00);
  std::locale::locale(local_50,this);
  std::locale::operator=(this,local_48);
  std::locale::locale(alStack_58,this_00);
                    /* try { // try from 00c1a943 to 00c1a945 has its CatchHandler @ 00c1a9a6 */
  (**(code **)(param_2[1] + 0x10))(param_2 + 1,local_50);
  std::locale::operator=(this_00,local_50);
  std::locale::~locale(alStack_58);
  std::locale::~locale(local_50);
  std::locale::~locale(local_48);
  lVar4 = param_1[9];
  *(int *)(param_1 + 9) = (int)param_2[9];
  *(int *)(param_2 + 9) = (int)lVar4;
  std::wstring::swap((wstring *)(param_1 + 10),(wstring *)(param_2 + 10));
  if (local_40 == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ==== entry=00c1a9d0 orig=FUN_00c1a9d0 size=5 name=rdbuf ====

/* std::wostringstream::rdbuf() const */

wostringstream * __thiscall std::wostringstream::rdbuf(wostringstream *this)

{
  return this + 8;
}


// ==== entry=00c1a9e0 orig=FUN_00c1a9e0 size=166 name=str ====

/* std::wostringstream::str() const */

void std::wostringstream::str(void)

{
  ulong uVar1;
  wchar_t *pwVar2;
  ulong uVar3;
  long in_RSI;
  wstring *in_RDI;
  long in_FS_OFFSET;
  allocator local_21;
  long local_20;
  
  local_20 = *(long *)(in_FS_OFFSET + 0x28);
  wstring::wstring(in_RDI,&local_21);
  uVar1 = *(ulong *)(in_RSI + 0x30);
  if (uVar1 == 0) {
    wstring::assign(in_RDI,(wstring *)(in_RSI + 0x50));
  }
  else {
    pwVar2 = *(wchar_t **)(in_RSI + 0x28);
    uVar3 = (*(long *)(*(long *)in_RDI + -0x18) << 2) >> 2;
    if (*(ulong *)(in_RSI + 0x20) < uVar1) {
      wstring::s_basic_string__replace_67ed76
                (in_RDI,0,uVar3,pwVar2,(long)(uVar1 - (long)pwVar2) >> 2);
    }
    else {
                    /* try { // try from 00c1aa3f to 00c1aa83 has its CatchHandler @ 00c1aa8b */
      wstring::s_basic_string__replace_67ed76
                (in_RDI,0,uVar3,pwVar2,(long)(*(ulong *)(in_RSI + 0x20) - (long)pwVar2) >> 2);
    }
  }
  if (local_20 == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ==== entry=00c1aab0 orig=FUN_00c1aab0 size=61 name=str ====

/* std::wostringstream::str(std::wstring const&) */

void __thiscall std::wostringstream::str(wostringstream *this,wstring *param_1)

{
  ulong uVar1;
  
  wstring::s_basic_string__assign_c0f410
            ((wstring *)(this + 0x50),*(wchar_t **)param_1,*(ulong *)(*(wchar_t **)param_1 + -6));
  uVar1 = 0;
  if (((byte)this[0x48] & 3) != 0) {
    uVar1 = *(ulong *)(*(wchar_t **)(this + 0x50) + -6);
  }
  wstringbuf::_M_sync((wstringbuf *)(this + 8),*(wchar_t **)(this + 0x50),0,uVar1);
  return;
}


// ==== entry=00c1aaf0 orig=FUN_00c1aaf0 size=284 name=wstringstream ====

/* std::wstringstream::wstringstream(std::_Ios_Openmode) */

void __thiscall
std::wstringstream::wstringstream(wstringstream *this,long *param_2,undefined4 param_3)

{
  long lVar1;
  
  lVar1 = param_2[2];
  *(long *)this = lVar1;
  *(long *)(this + *(long *)(lVar1 + -0x18)) = param_2[3];
  *(undefined8 *)(this + 8) = 0;
  wios::init((wios *)(this + *(long *)(lVar1 + -0x18)),(wstreambuf *)0x0);
  lVar1 = param_2[4];
  *(long *)(this + 0x10) = lVar1;
  lVar1 = *(long *)(lVar1 + -0x18);
  *(long *)(this + lVar1 + 0x10) = param_2[5];
                    /* try { // try from 00c1ab46 to 00c1ab4a has its CatchHandler @ 00c1ac0c */
  wios::init((wios *)(this + lVar1 + 0x10),(wstreambuf *)0x0);
  lVar1 = param_2[1];
  *(long *)this = lVar1;
  *(long *)(this + *(long *)(lVar1 + -0x18)) = param_2[6];
  *(long *)(this + 0x10) = param_2[7];
  lVar1 = *param_2;
  *(long *)this = lVar1;
  *(long *)(this + *(long *)(lVar1 + -0x18)) = param_2[8];
  lVar1 = param_2[9];
  *(undefined8 *)(this + 0x20) = 0;
  *(long *)(this + 0x10) = lVar1;
  *(undefined8 *)(this + 0x28) = 0;
  *(undefined8 *)(this + 0x30) = 0;
  *(undefined ***)(this + 0x18) = &PTR__wstreambuf_011b2be8;
  *(undefined8 *)(this + 0x38) = 0;
  *(undefined8 *)(this + 0x40) = 0;
  *(undefined8 *)(this + 0x48) = 0;
  locale::locale((locale *)(this + 0x50));
  *(undefined4 *)(this + 0x58) = param_3;
  *(undefined ***)(this + 0x18) = &PTR__wstringbuf_011b4a60;
  *(undefined **)(this + 0x60) = &DAT_011c5118;
                    /* try { // try from 00c1abfc to 00c1ac00 has its CatchHandler @ 00c1ac0e */
  wios::init((wios *)(this + *(long *)(*(long *)this + -0x18)),(wstreambuf *)(this + 0x18));
  return;
}


// ==== entry=00c1aca0 orig=FUN_00c1aca0 size=336 name=wstringstream ====

/* std::wstringstream::wstringstream(std::_Ios_Openmode) */

void __thiscall std::wstringstream::wstringstream(wstringstream *this,undefined4 param_2)

{
  ios_base *this_00;
  
  this_00 = (ios_base *)(this + 0x68);
  ios_base::ios_base(this_00);
  *(undefined **)this = &DAT_011b4cb8;
  *(undefined8 *)(this + 0x140) = 0;
  *(undefined4 *)(this + 0x148) = 0;
  this[0x14c] = (wstringstream)0x0;
  *(undefined8 *)(this + 0x150) = 0;
  *(undefined8 *)(this + 0x158) = 0;
  *(undefined8 *)(this + 0x160) = 0;
  *(undefined8 *)(this + 0x168) = 0;
  *(undefined **)(this + 0x68) = &DAT_011b4ce0;
  *(undefined8 *)(this + 8) = 0;
                    /* try { // try from 00c1ad28 to 00c1ad2c has its CatchHandler @ 00c1adf0 */
  wios::init((wios *)this_00,(wstreambuf *)0x0);
  *(undefined **)(this + 0x10) = &DAT_011b4c68;
  *(undefined **)(this + 0x68) = &DAT_011b4c90;
                    /* try { // try from 00c1ad45 to 00c1ad49 has its CatchHandler @ 00c1adfa */
  wios::init((wios *)this_00,(wstreambuf *)0x0);
  *(undefined8 *)(this + 0x20) = 0;
  *(undefined8 *)(this + 0x28) = 0;
  *(undefined8 *)(this + 0x30) = 0;
  *(undefined8 *)this = 0x11b4dd0;
  *(undefined8 *)(this + 0x10) = 0x11b4df8;
  *(undefined8 *)(this + 0x68) = 0x11b4e20;
  *(undefined8 *)(this + 0x38) = 0;
  *(undefined ***)(this + 0x18) = &PTR__wstreambuf_011b2be8;
  *(undefined8 *)(this + 0x40) = 0;
  *(undefined8 *)(this + 0x48) = 0;
  locale::locale((locale *)(this + 0x50));
  *(undefined4 *)(this + 0x58) = param_2;
  *(undefined ***)(this + 0x18) = &PTR__wstringbuf_011b4a60;
  *(undefined **)(this + 0x60) = &DAT_011c5118;
                    /* try { // try from 00c1addc to 00c1ade0 has its CatchHandler @ 00c1adf5 */
  wios::init((wios *)this_00,(wstreambuf *)(this + 0x18));
  return;
}


// ==== entry=00c1ae40 orig=FUN_00c1ae40 size=377 name=wstringstream ====

/* std::wstringstream::wstringstream(std::wstring const&, std::_Ios_Openmode) */

void __thiscall
std::wstringstream::wstringstream
          (wstringstream *this,long *param_1,undefined8 *param_3,uint param_4)

{
  long lVar1;
  wchar_t *pwVar2;
  ulong uVar3;
  long in_FS_OFFSET;
  allocator local_41;
  long local_40;
  
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  lVar1 = param_1[2];
  *(long *)this = lVar1;
  *(long *)(this + *(long *)(lVar1 + -0x18)) = param_1[3];
  *(undefined8 *)(this + 8) = 0;
  wios::init((wios *)(this + *(long *)(lVar1 + -0x18)),(wstreambuf *)0x0);
  lVar1 = param_1[4];
  *(long *)(this + 0x10) = lVar1;
  lVar1 = *(long *)(lVar1 + -0x18);
  *(long *)(this + lVar1 + 0x10) = param_1[5];
                    /* try { // try from 00c1aead to 00c1aeb1 has its CatchHandler @ 00c1b05b */
  wios::init((wios *)(this + lVar1 + 0x10),(wstreambuf *)0x0);
  lVar1 = param_1[1];
  *(long *)this = lVar1;
  *(long *)(this + *(long *)(lVar1 + -0x18)) = param_1[6];
  *(long *)(this + 0x10) = param_1[7];
  lVar1 = *param_1;
  *(long *)this = lVar1;
  *(long *)(this + *(long *)(lVar1 + -0x18)) = param_1[8];
  lVar1 = param_1[9];
  *(undefined8 *)(this + 0x20) = 0;
  *(long *)(this + 0x10) = lVar1;
  *(undefined8 *)(this + 0x28) = 0;
  *(undefined8 *)(this + 0x30) = 0;
  *(undefined ***)(this + 0x18) = &PTR__wstreambuf_011b2be8;
  *(undefined8 *)(this + 0x38) = 0;
  *(undefined8 *)(this + 0x40) = 0;
  *(undefined8 *)(this + 0x48) = 0;
  locale::locale((locale *)(this + 0x50));
  pwVar2 = (wchar_t *)*param_3;
  *(undefined4 *)(this + 0x58) = 0;
  uVar3 = *(ulong *)(pwVar2 + -6);
  *(undefined ***)(this + 0x18) = &PTR__wstringbuf_011b4a60;
                    /* try { // try from 00c1af60 to 00c1af64 has its CatchHandler @ 00c1b056 */
  wstring::wstring((wstring *)(this + 0x60),pwVar2,uVar3,&local_41);
  *(uint *)(this + 0x58) = param_4;
  uVar3 = 0;
  if ((param_4 & 3) != 0) {
    uVar3 = *(ulong *)(*(wchar_t **)(this + 0x60) + -6);
  }
                    /* try { // try from 00c1af7e to 00c1af82 has its CatchHandler @ 00c1afbe */
  wstringbuf::_M_sync((wstringbuf *)(this + 0x18),*(wchar_t **)(this + 0x60),0,uVar3);
                    /* try { // try from 00c1af90 to 00c1af94 has its CatchHandler @ 00c1afb9 */
  wios::init((wios *)(this + *(long *)(*(long *)this + -0x18)),(wstreambuf *)(this + 0x18));
  if (local_40 == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ==== entry=00c1b080 orig=FUN_00c1b080 size=434 name=wstringstream ====

/* std::wstringstream::wstringstream(std::wstring const&, std::_Ios_Openmode) */

void __thiscall
std::wstringstream::wstringstream(wstringstream *this,undefined8 *param_1,uint param_3)

{
  ios_base *this_00;
  ulong uVar1;
  long in_FS_OFFSET;
  allocator local_41;
  long local_40;
  
  this_00 = (ios_base *)(this + 0x68);
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  ios_base::ios_base(this_00);
  *(undefined **)this = &DAT_011b4cb8;
  *(undefined8 *)(this + 0x140) = 0;
  *(undefined4 *)(this + 0x148) = 0;
  this[0x14c] = (wstringstream)0x0;
  *(undefined8 *)(this + 0x150) = 0;
  *(undefined8 *)(this + 0x158) = 0;
  *(undefined8 *)(this + 0x160) = 0;
  *(undefined8 *)(this + 0x168) = 0;
  *(undefined **)(this + 0x68) = &DAT_011b4ce0;
  *(undefined8 *)(this + 8) = 0;
                    /* try { // try from 00c1b11b to 00c1b11f has its CatchHandler @ 00c1b243 */
  wios::init((wios *)this_00,(wstreambuf *)0x0);
  *(undefined **)(this + 0x10) = &DAT_011b4c68;
  *(undefined **)(this + 0x68) = &DAT_011b4c90;
                    /* try { // try from 00c1b138 to 00c1b13c has its CatchHandler @ 00c1b23c */
  wios::init((wios *)this_00,(wstreambuf *)0x0);
  *(undefined8 *)(this + 0x20) = 0;
  *(undefined8 *)(this + 0x28) = 0;
  *(undefined8 *)(this + 0x30) = 0;
  *(undefined8 *)this = 0x11b4dd0;
  *(undefined8 *)(this + 0x10) = 0x11b4df8;
  *(undefined8 *)(this + 0x68) = 0x11b4e20;
  *(undefined8 *)(this + 0x38) = 0;
  *(undefined ***)(this + 0x18) = &PTR__wstreambuf_011b2be8;
  *(undefined8 *)(this + 0x40) = 0;
  *(undefined8 *)(this + 0x48) = 0;
  locale::locale((locale *)(this + 0x50));
  *(undefined4 *)(this + 0x58) = 0;
  *(undefined ***)(this + 0x18) = &PTR__wstringbuf_011b4a60;
                    /* try { // try from 00c1b1e0 to 00c1b1e4 has its CatchHandler @ 00c1b23e */
  wstring::wstring((wstring *)(this + 0x60),(wchar_t *)*param_1,*(ulong *)((wchar_t *)*param_1 + -6)
                   ,&local_41);
  *(uint *)(this + 0x58) = param_3;
  uVar1 = 0;
  if ((param_3 & 3) != 0) {
    uVar1 = *(ulong *)(*(wchar_t **)(this + 0x60) + -6);
  }
                    /* try { // try from 00c1b1fe to 00c1b202 has its CatchHandler @ 00c1b237 */
  wstringbuf::_M_sync((wstringbuf *)(this + 0x18),*(wchar_t **)(this + 0x60),0,uVar1);
                    /* try { // try from 00c1b209 to 00c1b20d has its CatchHandler @ 00c1b232 */
  wios::init((wios *)this_00,(wstreambuf *)(this + 0x18));
  if (local_40 == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ==== entry=00c1b2d0 orig=FUN_00c1b2d0 size=267 name=~wstringstream ====

/* WARNING: Removing unreachable block (ram,0x00c1b3d0) */
/* std::wstringstream::~wstringstream() */

void __thiscall std::wstringstream::~wstringstream(wstringstream *this)

{
  allocator *paVar1;
  int *piVar2;
  int iVar3;
  long lVar4;
  long lVar5;
  long *in_RSI;
  long in_FS_OFFSET;
  
  lVar4 = *(long *)(in_FS_OFFSET + 0x28);
  lVar5 = *in_RSI;
  *(long *)this = lVar5;
  *(long *)(this + *(long *)(lVar5 + -0x18)) = in_RSI[8];
  *(long *)(this + 0x10) = in_RSI[9];
  *(undefined ***)(this + 0x18) = &PTR__wstringbuf_011b4a60;
  paVar1 = (allocator *)(*(long *)(this + 0x60) + -0x18);
  if (paVar1 != (allocator *)&wstring::_Rep::_S_empty_rep_storage) {
    LOCK();
    piVar2 = (int *)(*(long *)(this + 0x60) + -8);
    iVar3 = *piVar2;
    *piVar2 = *piVar2 + -1;
    UNLOCK();
    if (iVar3 < 1) {
      wstring::_Rep::_M_destroy(paVar1);
    }
  }
  *(undefined ***)(this + 0x18) = &PTR__wstreambuf_011b2be8;
  locale::~locale((locale *)(this + 0x50));
  lVar5 = in_RSI[1];
  *(long *)this = lVar5;
  *(long *)(this + *(long *)(lVar5 + -0x18)) = in_RSI[6];
  *(long *)(this + 0x10) = in_RSI[7];
  lVar5 = in_RSI[4];
  *(long *)(this + 0x10) = lVar5;
  *(long *)(this + *(long *)(lVar5 + -0x18) + 0x10) = in_RSI[5];
  lVar5 = in_RSI[2];
  *(long *)this = lVar5;
  *(long *)(this + *(long *)(lVar5 + -0x18)) = in_RSI[3];
  *(undefined8 *)(this + 8) = 0;
  if (lVar4 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


// ==== entry=00c1b3e0 name=FUN_00c1b3e0 size=342 ====

void FUN_00c1b3e0(long *param_1,long *param_2,long *param_3)

{
  wios wVar1;
  undefined8 uVar2;
  wios *this;
  long lVar3;
  
  lVar3 = param_2[2];
  *param_1 = lVar3;
  *(long *)((long)param_1 + *(long *)(lVar3 + -0x18)) = param_2[3];
  param_1[1] = param_3[1];
  this = (wios *)(*(long *)(lVar3 + -0x18) + (long)param_1);
  lVar3 = *(long *)(*param_3 + -0x18) + (long)param_3;
  FUN_00c71b00(this,lVar3);
  std::wios::_M_cache_locale(this,(locale *)(this + 0xd0));
  uVar2 = *(undefined8 *)(lVar3 + 0xd8);
  *(undefined8 *)(lVar3 + 0xd8) = 0;
  *(undefined8 *)(this + 0xd8) = uVar2;
  *(undefined4 *)(this + 0xe0) = *(undefined4 *)(lVar3 + 0xe0);
  wVar1 = *(wios *)(lVar3 + 0xe4);
  *(undefined8 *)(this + 0xe8) = 0;
  this[0xe4] = wVar1;
  lVar3 = param_2[4];
  param_3[1] = 0;
  param_1[2] = lVar3;
  *(long *)((long)param_1 + *(long *)(lVar3 + -0x18) + 0x10) = param_2[5];
  lVar3 = param_2[1];
  *param_1 = lVar3;
  *(long *)((long)param_1 + *(long *)(lVar3 + -0x18)) = param_2[6];
  param_1[2] = param_2[7];
  lVar3 = *param_2;
  *param_1 = lVar3;
  *(long *)((long)param_1 + *(long *)(lVar3 + -0x18)) = param_2[8];
  param_1[2] = param_2[9];
                    /* try { // try from 00c1b4dd to 00c1b4e1 has its CatchHandler @ 00c1b536 */
  std::wstreambuf::wstreambuf((wstreambuf *)(param_1 + 3),(wstreambuf *)(param_3 + 3));
  param_1[3] = (long)&PTR__wstringbuf_011b4a60;
  *(int *)(param_1 + 0xb) = (int)param_3[0xb];
  param_1[0xc] = param_3[0xc];
  param_3[0xc] = (long)&DAT_011c5118;
                    /* try { // try from 00c1b519 to 00c1b51d has its CatchHandler @ 00c1b538 */
  std::wstringbuf::_M_sync((wstringbuf *)(param_3 + 3),(wchar_t *)&DAT_011c5118,0,0);
  *(wstreambuf **)((long)param_1 + *(long *)(*param_1 + -0x18) + 0xe8) = (wstreambuf *)(param_1 + 3)
  ;
  return;
}


// ==== entry=00c1b5a0 name=FUN_00c1b5a0 size=369 ====

void FUN_00c1b5a0(undefined8 *param_1,long *param_2)

{
  ios_base *this;
  undefined1 uVar1;
  undefined8 uVar2;
  long lVar3;
  
  this = (ios_base *)(param_1 + 0xd);
  std::ios_base::ios_base(this);
  *param_1 = &DAT_011b4cb8;
  param_1[0xd] = &DAT_011b4ce0;
  lVar3 = param_2[1];
  param_1[0x28] = 0;
  param_1[1] = lVar3;
  lVar3 = *param_2;
  *(undefined4 *)(param_1 + 0x29) = 0;
  lVar3 = *(long *)(lVar3 + -0x18);
  *(undefined1 *)((long)param_1 + 0x14c) = 0;
  param_1[0x2a] = 0;
  param_1[0x2b] = 0;
  lVar3 = lVar3 + (long)param_2;
  param_1[0x2c] = 0;
  param_1[0x2d] = 0;
  FUN_00c71b00(this,lVar3);
                    /* try { // try from 00c1b642 to 00c1b646 has its CatchHandler @ 00c1b711 */
  std::wios::_M_cache_locale((wios *)this,(locale *)(param_1 + 0x27));
  uVar2 = *(undefined8 *)(lVar3 + 0xd8);
  *(undefined8 *)(lVar3 + 0xd8) = 0;
  param_1[0x28] = uVar2;
  *(undefined4 *)(param_1 + 0x29) = *(undefined4 *)(lVar3 + 0xe0);
  uVar1 = *(undefined1 *)(lVar3 + 0xe4);
  param_1[0x2a] = 0;
  *(undefined1 *)((long)param_1 + 0x14c) = uVar1;
  param_2[1] = 0;
  *param_1 = 0x11b4dd0;
  param_1[0xd] = 0x11b4e20;
  param_1[2] = 0x11b4df8;
                    /* try { // try from 00c1b6be to 00c1b6c2 has its CatchHandler @ 00c1b71b */
  std::wstreambuf::wstreambuf((wstreambuf *)(param_1 + 3),(wstreambuf *)(param_2 + 3));
  param_1[3] = &PTR__wstringbuf_011b4a60;
  *(int *)(param_1 + 0xb) = (int)param_2[0xb];
  param_1[0xc] = param_2[0xc];
  param_2[0xc] = (long)&DAT_011c5118;
                    /* try { // try from 00c1b6f6 to 00c1b6fa has its CatchHandler @ 00c1b716 */
  std::wstringbuf::_M_sync((wstringbuf *)(param_2 + 3),(wchar_t *)&DAT_011c5118,0,0);
  param_1[0x2a] = (wstreambuf *)(param_1 + 3);
  return;
}


// ==== entry=00c1b760 name=FUN_00c1b760 size=360 ====

long * FUN_00c1b760(long *param_1,long *param_2)

{
  wios wVar1;
  undefined4 uVar2;
  undefined8 uVar3;
  long lVar4;
  long lVar5;
  wios *this;
  wios *this_00;
  long in_FS_OFFSET;
  locale local_50 [8];
  locale local_48 [8];
  long local_40;
  
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  this_00 = (wios *)(*(long *)(*param_1 + -0x18) + (long)param_1);
  this = (wios *)(*(long *)(*param_2 + -0x18) + (long)param_2);
  FUN_00c71c10(this_00,this);
  std::wios::_M_cache_locale(this_00,(locale *)(this_00 + 0xd0));
  std::wios::_M_cache_locale(this,(locale *)(this + 0xd0));
  uVar3 = *(undefined8 *)(this_00 + 0xd8);
  *(undefined8 *)(this_00 + 0xd8) = *(undefined8 *)(this + 0xd8);
  *(undefined8 *)(this + 0xd8) = uVar3;
  uVar2 = *(undefined4 *)(this_00 + 0xe0);
  *(undefined4 *)(this_00 + 0xe0) = *(undefined4 *)(this + 0xe0);
  *(undefined4 *)(this + 0xe0) = uVar2;
  wVar1 = this_00[0xe4];
  this_00[0xe4] = this[0xe4];
  lVar4 = param_2[1];
  this[0xe4] = wVar1;
  lVar5 = param_1[1];
  param_1[1] = lVar4;
  param_2[1] = lVar5;
  std::wstreambuf::operator=((wstreambuf *)(param_1 + 3),(wstreambuf *)(param_2 + 3));
  std::locale::locale(local_48,(locale *)(param_2 + 10));
  std::locale::locale(local_50,(locale *)(param_1 + 10));
  std::locale::operator=((locale *)(param_1 + 10),local_48);
  std::locale::~locale(local_50);
  std::locale::~locale(local_48);
  *(int *)(param_1 + 0xb) = (int)param_2[0xb];
  std::wstring::swap((wstring *)(param_1 + 0xc),(wstring *)(param_2 + 0xc));
  std::wstringbuf::_M_sync((wstringbuf *)(param_2 + 3),(wchar_t *)param_2[0xc],0,0);
  if (local_40 == *(long *)(in_FS_OFFSET + 0x28)) {
    return param_1;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ==== entry=00c1b8d0 name=FUN_00c1b8d0 size=518 ====

void FUN_00c1b8d0(long *param_1,long *param_2)

{
  locale *this;
  locale *this_00;
  wios wVar1;
  undefined4 uVar2;
  undefined8 uVar3;
  long lVar4;
  long lVar5;
  wios *this_01;
  wios *this_02;
  long in_FS_OFFSET;
  locale alStack_58 [8];
  locale local_50 [8];
  locale local_48 [8];
  long local_40;
  
  this = (locale *)(param_1 + 10);
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  this_02 = (wios *)(*(long *)(*param_1 + -0x18) + (long)param_1);
  this_01 = (wios *)(*(long *)(*param_2 + -0x18) + (long)param_2);
  FUN_00c71c10(this_02,this_01);
  std::wios::_M_cache_locale(this_02,(locale *)(this_02 + 0xd0));
  std::wios::_M_cache_locale(this_01,(locale *)(this_01 + 0xd0));
  uVar3 = *(undefined8 *)(this_02 + 0xd8);
  *(undefined8 *)(this_02 + 0xd8) = *(undefined8 *)(this_01 + 0xd8);
  *(undefined8 *)(this_01 + 0xd8) = uVar3;
  uVar2 = *(undefined4 *)(this_02 + 0xe0);
  *(undefined4 *)(this_02 + 0xe0) = *(undefined4 *)(this_01 + 0xe0);
  *(undefined4 *)(this_01 + 0xe0) = uVar2;
  wVar1 = this_02[0xe4];
  this_02[0xe4] = this_01[0xe4];
  lVar4 = param_2[1];
  this_00 = (locale *)(param_2 + 10);
  this_01[0xe4] = wVar1;
  lVar5 = param_1[1];
  param_1[1] = lVar4;
  param_2[1] = lVar5;
  lVar4 = param_1[4];
  param_1[4] = param_2[4];
  param_2[4] = lVar4;
  lVar4 = param_1[5];
  param_1[5] = param_2[5];
  param_2[5] = lVar4;
  lVar4 = param_1[6];
  param_1[6] = param_2[6];
  param_2[6] = lVar4;
  lVar4 = param_1[7];
  param_1[7] = param_2[7];
  param_2[7] = lVar4;
  lVar4 = param_1[8];
  param_1[8] = param_2[8];
  param_2[8] = lVar4;
  lVar4 = param_1[9];
  param_1[9] = param_2[9];
  param_2[9] = lVar4;
  std::locale::locale(local_48,this);
  std::locale::operator=(this,this_00);
  std::locale::operator=(this_00,local_48);
  std::locale::~locale(local_48);
  std::locale::locale(local_48,this_00);
  std::locale::locale(local_50,this);
  std::locale::operator=(this,local_48);
  std::locale::locale(alStack_58,this_00);
                    /* try { // try from 00c1ba73 to 00c1ba75 has its CatchHandler @ 00c1bad6 */
  (**(code **)(param_2[3] + 0x10))(param_2 + 3,local_50);
  std::locale::operator=(this_00,local_50);
  std::locale::~locale(alStack_58);
  std::locale::~locale(local_50);
  std::locale::~locale(local_48);
  lVar4 = param_1[0xb];
  *(int *)(param_1 + 0xb) = (int)param_2[0xb];
  *(int *)(param_2 + 0xb) = (int)lVar4;
  std::wstring::swap((wstring *)(param_1 + 0xc),(wstring *)(param_2 + 0xc));
  if (local_40 == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ==== entry=00c1bb00 orig=FUN_00c1bb00 size=5 name=rdbuf ====

/* std::wstringstream::rdbuf() const */

wstringstream * __thiscall std::wstringstream::rdbuf(wstringstream *this)

{
  return this + 0x18;
}


// ==== entry=00c1bb10 orig=FUN_00c1bb10 size=166 name=str ====

/* std::wstringstream::str() const */

void std::wstringstream::str(void)

{
  ulong uVar1;
  wchar_t *pwVar2;
  ulong uVar3;
  long in_RSI;
  wstring *in_RDI;
  long in_FS_OFFSET;
  allocator local_21;
  long local_20;
  
  local_20 = *(long *)(in_FS_OFFSET + 0x28);
  wstring::wstring(in_RDI,&local_21);
  uVar1 = *(ulong *)(in_RSI + 0x40);
  if (uVar1 == 0) {
    wstring::assign(in_RDI,(wstring *)(in_RSI + 0x60));
  }
  else {
    pwVar2 = *(wchar_t **)(in_RSI + 0x38);
    uVar3 = (*(long *)(*(long *)in_RDI + -0x18) << 2) >> 2;
    if (*(ulong *)(in_RSI + 0x30) < uVar1) {
      wstring::s_basic_string__replace_67ed76
                (in_RDI,0,uVar3,pwVar2,(long)(uVar1 - (long)pwVar2) >> 2);
    }
    else {
                    /* try { // try from 00c1bb6f to 00c1bbb3 has its CatchHandler @ 00c1bbbb */
      wstring::s_basic_string__replace_67ed76
                (in_RDI,0,uVar3,pwVar2,(long)(*(ulong *)(in_RSI + 0x30) - (long)pwVar2) >> 2);
    }
  }
  if (local_20 == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ==== entry=00c1bbe0 orig=FUN_00c1bbe0 size=61 name=str ====

/* std::wstringstream::str(std::wstring const&) */

void __thiscall std::wstringstream::str(wstringstream *this,wstring *param_1)

{
  ulong uVar1;
  
  wstring::s_basic_string__assign_c0f410
            ((wstring *)(this + 0x60),*(wchar_t **)param_1,*(ulong *)(*(wchar_t **)param_1 + -6));
  uVar1 = 0;
  if (((byte)this[0x58] & 3) != 0) {
    uVar1 = *(ulong *)(*(wchar_t **)(this + 0x60) + -6);
  }
  wstringbuf::_M_sync((wstringbuf *)(this + 0x18),*(wchar_t **)(this + 0x60),0,uVar1);
  return;
}


// ==== entry=00c1bc20 orig=FUN_00c1bc20 size=29 name=__once_proxy ====

void __once_proxy(void)

{
  undefined8 *in_FS_OFFSET;
  
                    /* WARNING: Could not recover jumptable at 0x00c1bc3b. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)*in_FS_OFFSET)();
  return;
}


// ==== entry=00c1bc40 name=FUN_00c1bc40 size=36 ====

void FUN_00c1bc40(long *param_1)

{
  long *plVar1;
  
  if (param_1 == (long *)0x0) {
    return;
  }
  do {
    plVar1 = (long *)*param_1;
    (*(code *)param_1[1])(param_1);
    param_1 = plVar1;
  } while (plVar1 != (long *)0x0);
  return;
}


// ==== entry=00c1bc70 name=FUN_00c1bc70 size=72 ====

void FUN_00c1bc70(void)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  
  puVar2 = pthread_getspecific(DAT_011c5144);
  pthread_setspecific(DAT_011c5144,(void *)0x0);
  while (puVar2 != (undefined8 *)0x0) {
    puVar1 = (undefined8 *)*puVar2;
    (*(code *)puVar2[1])(puVar2);
    puVar2 = puVar1;
  }
  return;
}


// ==== entry=00c1bcc0 name=FUN_00c1bcc0 size=11 ====

void FUN_00c1bcc0(void)

{
  pthread_key_delete(DAT_011c5144);
  return;
}


// ==== entry=00c1bcd0 name=FUN_00c1bcd0 size=132 ====

void FUN_00c1bcd0(void)

{
  int iVar1;
  
  if (DAT_011c5138 != '\0') {
    FUN_00c88fc0(FUN_00c1bc70);
    return;
  }
  iVar1 = __cxa_guard_acquire(&DAT_011c5138);
  if (iVar1 == 0) {
    FUN_00c88fc0(FUN_00c1bc70);
    return;
  }
  pthread_key_create(&DAT_011c5144,FUN_00c1bc40);
  __cxa_guard_release(&DAT_011c5138);
  __cxa_atexit(FUN_00c1bcc0,&DAT_011c5140,&DAT_00c89008);
  FUN_00c88fc0(FUN_00c1bc70);
  return;
}


// ==== entry=00c1bd70 orig=FUN_00c1bd70 size=16 name=condition_variable ====

/* std::condition_variable::condition_variable() */

void __thiscall std::condition_variable::condition_variable(condition_variable *this)

{
  *(undefined1 (*) [16])this = (undefined1  [16])0x0;
  *(undefined1 (*) [16])(this + 0x10) = (undefined1  [16])0x0;
  *(undefined1 (*) [16])(this + 0x20) = (undefined1  [16])0x0;
  return;
}


// ==== entry=00c1bd80 orig=FUN_00c1bd80 size=5 name=~condition_variable ====

/* std::condition_variable::~condition_variable() */

void __thiscall std::condition_variable::~condition_variable(condition_variable *this)

{
  pthread_cond_destroy((pthread_cond_t *)this);
  return;
}


// ==== entry=00c1bd90 orig=FUN_00c1bd90 size=26 name=wait ====

/* std::condition_variable::wait(std::unique_lock<std::mutex>&) */

void __thiscall std::condition_variable::wait(condition_variable *this,unique_lock *param_1)

{
  int iVar1;
  
  iVar1 = pthread_cond_wait((pthread_cond_t *)this,*(pthread_mutex_t **)param_1);
  if (iVar1 == 0) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  terminate();
}


// ==== entry=00c1bdb0 orig=FUN_00c1bdb0 size=25 name=notify_one ====

/* std::condition_variable::notify_one() */

void __thiscall std::condition_variable::notify_one(condition_variable *this)

{
  int iVar1;
  
  iVar1 = pthread_cond_signal((pthread_cond_t *)this);
  if (iVar1 == 0) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __throw_system_error(iVar1);
}


// ==== entry=00c1bdd0 orig=FUN_00c1bdd0 size=25 name=notify_all ====

/* std::condition_variable::notify_all() */

void __thiscall std::condition_variable::notify_all(condition_variable *this)

{
  int iVar1;
  
  iVar1 = pthread_cond_broadcast((pthread_cond_t *)this);
  if (iVar1 == 0) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __throw_system_error(iVar1);
}


// ==== entry=00c1bdf0 name=FUN_00c1bdf0 size=47 ====

void FUN_00c1bdf0(void *param_1)

{
  if (param_1 == (void *)0x0) {
    return;
  }
  pthread_mutex_unlock(*(pthread_mutex_t **)((long)param_1 + 0x18));
  std::condition_variable::notify_all(*(condition_variable **)((long)param_1 + 0x10));
  operator_delete(param_1);
  return;
}


// ==== entry=00c1be30 name=FUN_00c1be30 size=62 ====

void FUN_00c1be30(undefined8 *param_1)

{
  pthread_key_t __key;
  void *pvVar1;
  
  pthread_once((pthread_once_t *)&DAT_011c5130,FUN_00c1bcd0);
  pvVar1 = pthread_getspecific(DAT_011c5144);
  __key = DAT_011c5144;
  *param_1 = pvVar1;
  pthread_setspecific(__key,param_1);
  return;
}


// ==== entry=00c1be70 name=FUN_00c1be70 size=71 ====

void FUN_00c1be70(undefined8 param_1,undefined8 *param_2)

{
  undefined8 uVar1;
  void *pvVar2;
  
  pvVar2 = operator_new(0x20);
  *(undefined1 *)(param_2 + 1) = 0;
  *(undefined8 *)((long)pvVar2 + 0x10) = param_1;
  uVar1 = *param_2;
  *param_2 = 0;
  *(undefined8 *)((long)pvVar2 + 0x18) = uVar1;
  *(code **)((long)pvVar2 + 8) = FUN_00c1bdf0;
                    /* try { // try from 00c1bead to 00c1beb1 has its CatchHandler @ 00c1beb7 */
  FUN_00c1be30(pvVar2);
  return;
}


// ==== entry=00c1bec0 orig=FUN_00c1bec0 size=19 name=~ios ====

/* std::ios::~ios() */

void __thiscall std::ios::~ios(ios *this)

{
  *(undefined ***)this = &PTR__ios_011b4e70;
  ios_base::~ios_base((ios_base *)this);
  return;
}


// ==== entry=00c1bee0 orig=FUN_00c1bee0 size=19 name=~wios ====

/* std::wios::~wios() */

void __thiscall std::wios::~wios(wios *this)

{
  *(undefined ***)this = &PTR__wios_011b4e90;
  ios_base::~ios_base((ios_base *)this);
  return;
}


// ==== entry=00c1bf00 orig=FUN_00c1bf00 size=32 name=~ios ====

/* std::ios::~ios() */

void __thiscall std::ios::~ios(ios *this)

{
  *(undefined ***)this = &PTR__ios_011b4e70;
  ios_base::~ios_base((ios_base *)this);
  operator_delete(this);
  return;
}


// ==== entry=00c1bf20 orig=FUN_00c1bf20 size=32 name=~wios ====

/* std::wios::~wios() */

void __thiscall std::wios::~wios(wios *this)

{
  *(undefined ***)this = &PTR__wios_011b4e90;
  ios_base::~ios_base((ios_base *)this);
  operator_delete(this);
  return;
}


// ==== entry=00c1bf40 name=FUN_00c1bf40 size=8 ====

bool FUN_00c1bf40(long param_1)

{
  return (*(byte *)(param_1 + 0x20) & 5) == 0;
}


// ==== entry=00c1bf50 orig=FUN_00c1bf50 size=8 name=operator! ====

/* std::ios::TEMPNAMEPLACEHOLDERVALUE() const */

bool __thiscall std::ios::operator!(ios *this)

{
  return ((byte)this[0x20] & 5) != 0;
}


// ==== entry=00c1bf60 orig=FUN_00c1bf60 size=4 name=rdstate ====

/* std::ios::rdstate() const */

undefined4 __thiscall std::ios::rdstate(ios *this)

{
  return *(undefined4 *)(this + 0x20);
}


// ==== entry=00c1bf70 orig=FUN_00c1bf70 size=37 name=s_basic_ios__clear_c1bf70 ====

/* std::ios::clear(std::_Ios_Iostate) */

void __thiscall std::ios::s_basic_ios__clear_c1bf70(ios *this,uint param_2)

{
  if (*(long *)(this + 0xe8) == 0) {
    param_2 = param_2 | 1;
  }
  *(uint *)(this + 0x20) = param_2;
  if ((*(uint *)(this + 0x1c) & param_2) == 0) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __throw_ios_failure("basic_ios::clear");
}


// ==== entry=00c1bfa0 orig=FUN_00c1bfa0 size=8 name=setstate ====

/* std::ios::setstate(std::_Ios_Iostate) */

void __thiscall std::ios::setstate(ios *this,uint param_2)

{
  s_basic_ios__clear_c1bf70(this,param_2 | *(uint *)(this + 0x20));
  return;
}


// ==== entry=00c1bfb0 orig=FUN_00c1bfb0 size=15 name=_M_setstate ====

/* std::ios::_M_setstate(std::_Ios_Iostate) */

void __thiscall std::ios::_M_setstate(ios *this,uint param_2)

{
  *(uint *)(this + 0x20) = *(uint *)(this + 0x20) | param_2;
  if ((*(uint *)(this + 0x1c) & param_2) == 0) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __cxa_rethrow();
}


// ==== entry=00c1bfc0 orig=FUN_00c1bfc0 size=9 name=good ====

/* std::ios::good() const */

undefined4 __thiscall std::ios::good(ios *this)

{
  return CONCAT31((int3)((uint)*(int *)(this + 0x20) >> 8),*(int *)(this + 0x20) == 0);
}


// ==== entry=00c1bfd0 orig=FUN_00c1bfd0 size=9 name=eof ====

/* std::ios::eof() const */

uint __thiscall std::ios::eof(ios *this)

{
  return *(uint *)(this + 0x20) >> 1 & 1;
}


// ==== entry=00c1bfe0 orig=FUN_00c1bfe0 size=8 name=fail ====

/* std::ios::fail() const */

bool __thiscall std::ios::fail(ios *this)

{
  return ((byte)this[0x20] & 5) != 0;
}


// ==== entry=00c1bff0 orig=FUN_00c1bff0 size=7 name=bad ====

/* std::ios::bad() const */

uint __thiscall std::ios::bad(ios *this)

{
  return *(uint *)(this + 0x20) & 1;
}


// ==== entry=00c1c000 orig=FUN_00c1c000 size=4 name=exceptions ====

/* std::ios::exceptions() const */

undefined4 __thiscall std::ios::exceptions(ios *this)

{
  return *(undefined4 *)(this + 0x1c);
}


// ==== entry=00c1c010 orig=FUN_00c1c010 size=11 name=exceptions ====

/* std::ios::exceptions(std::_Ios_Iostate) */

void __thiscall std::ios::exceptions(ios *this,undefined4 param_2)

{
  *(undefined4 *)(this + 0x1c) = param_2;
  s_basic_ios__clear_c1bf70(this,*(undefined4 *)(this + 0x20));
  return;
}


// ==== entry=00c1c020 orig=FUN_00c1c020 size=8 name=tie ====

/* std::ios::tie() const */

undefined8 __thiscall std::ios::tie(ios *this)

{
  return *(undefined8 *)(this + 0xd8);
}


// ==== entry=00c1c030 orig=FUN_00c1c030 size=15 name=tie ====

/* std::ios::tie(std::ostream*) */

undefined8 __thiscall std::ios::tie(ios *this,ostream *param_1)

{
  undefined8 uVar1;
  
  uVar1 = *(undefined8 *)(this + 0xd8);
  *(ostream **)(this + 0xd8) = param_1;
  return uVar1;
}


// ==== entry=00c1c040 orig=FUN_00c1c040 size=8 name=rdbuf ====

/* std::ios::rdbuf() const */

undefined8 __thiscall std::ios::rdbuf(ios *this)

{
  return *(undefined8 *)(this + 0xe8);
}


// ==== entry=00c1c050 orig=FUN_00c1c050 size=27 name=rdbuf ====

/* std::ios::rdbuf(std::streambuf*) */

undefined8 __thiscall std::ios::rdbuf(ios *this,streambuf *param_1)

{
  undefined8 uVar1;
  
  uVar1 = *(undefined8 *)(this + 0xe8);
  *(streambuf **)(this + 0xe8) = param_1;
  s_basic_ios__clear_c1bf70(this,0);
  return uVar1;
}


// ==== entry=00c1c070 orig=FUN_00c1c070 size=115 name=fill ====

/* std::ios::fill() const */

ulong __thiscall std::ios::fill(ios *this)

{
  ctype<char> *this_00;
  ulong uVar1;
  
  if (this[0xe1] != (ios)0x0) {
    return (ulong)(byte)this[0xe0];
  }
  this_00 = *(ctype<char> **)(this + 0xf0);
  if (this_00 != (ctype<char> *)0x0) {
    if (this_00[0x38] == (ctype<char>)0x0) {
      ctype<char>::_M_widen_init(this_00);
      uVar1 = 0x20;
      if (*(code **)(*(long *)this_00 + 0x30) != FUN_00816ea8) {
        uVar1 = (**(code **)(*(long *)this_00 + 0x30))(this_00,0x20);
      }
    }
    else {
      uVar1 = (ulong)(byte)this_00[0x59];
    }
    this[0xe0] = SUB81(uVar1,0);
    this[0xe1] = (ios)0x1;
    return uVar1;
  }
                    /* WARNING: Subroutine does not return */
  __throw_bad_cast();
}


// ==== entry=00c1c0f0 orig=FUN_00c1c0f0 size=129 name=fill ====

/* std::ios::fill(char) */

ulong __thiscall std::ios::fill(ios *this,char param_1)

{
  ios iVar1;
  ctype<char> *this_00;
  ulong uVar2;
  
  if (this[0xe1] != (ios)0x0) {
    iVar1 = this[0xe0];
    this[0xe0] = (ios)param_1;
    return (ulong)(byte)iVar1;
  }
  this_00 = *(ctype<char> **)(this + 0xf0);
  if (this_00 != (ctype<char> *)0x0) {
    if (this_00[0x38] == (ctype<char>)0x0) {
      ctype<char>::_M_widen_init(this_00);
      uVar2 = 0x20;
      if (*(code **)(*(long *)this_00 + 0x30) != FUN_00816ea8) {
        uVar2 = (**(code **)(*(long *)this_00 + 0x30))(this_00,0x20);
      }
    }
    else {
      uVar2 = (ulong)(byte)this_00[0x59];
    }
    this[0xe0] = (ios)param_1;
    this[0xe1] = (ios)0x1;
    return uVar2;
  }
                    /* WARNING: Subroutine does not return */
  __throw_bad_cast();
}


// ==== entry=00c1c180 orig=FUN_00c1c180 size=97 name=narrow ====

/* std::ios::narrow(char, char) const */

ulong __thiscall std::ios::narrow(ios *this,char param_1,char param_2)

{
  byte bVar1;
  long *plVar2;
  uint uVar3;
  ulong uVar4;
  undefined7 in_register_00000011;
  undefined7 in_register_00000031;
  
  plVar2 = *(long **)(this + 0xf0);
  if (plVar2 != (long *)0x0) {
    bVar1 = *(byte *)((long)plVar2 + (ulong)(byte)param_1 + 0x139);
    uVar4 = (ulong)bVar1;
    if (bVar1 == 0) {
      uVar4 = CONCAT71(in_register_00000011,param_2) & 0xffffffff;
      uVar3 = (uint)CONCAT71(in_register_00000031,param_1);
      if (*(code **)(*plVar2 + 0x40) != ctype<char>::do_narrow) {
        uVar3 = (**(code **)(*plVar2 + 0x40))(plVar2,(int)param_1,(int)(char)uVar4);
      }
      if ((char)uVar4 != (char)uVar3) {
        *(char *)((long)plVar2 + (ulong)(byte)param_1 + 0x139) = (char)uVar3;
        uVar4 = (ulong)uVar3;
      }
    }
    return uVar4;
  }
                    /* WARNING: Subroutine does not return */
  __throw_bad_cast();
}


// ==== entry=00c1c1f0 orig=FUN_00c1c1f0 size=88 name=widen ====

/* std::ios::widen(char) const */

ulong __thiscall std::ios::widen(ios *this,char param_1)

{
  ctype<char> *this_00;
  ulong uVar1;
  undefined7 in_register_00000031;
  
  this_00 = *(ctype<char> **)(this + 0xf0);
  if (this_00 == (ctype<char> *)0x0) {
                    /* WARNING: Subroutine does not return */
    __throw_bad_cast();
  }
  uVar1 = CONCAT71(in_register_00000031,param_1) & 0xffffffff;
  if (this_00[0x38] == (ctype<char>)0x0) {
    ctype<char>::_M_widen_init(this_00);
    if (*(code **)(*(long *)this_00 + 0x30) != FUN_00816ea8) {
                    /* WARNING: Could not recover jumptable at 0x00c1c247. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar1 = (**(code **)(*(long *)this_00 + 0x30))(this_00,(int)(char)uVar1);
      return uVar1;
    }
  }
  else {
    uVar1 = (ulong)(byte)this_00[(ulong)(byte)param_1 + 0x39];
  }
  return uVar1;
}


// ==== entry=00c1c250 orig=FUN_00c1c250 size=89 name=ios ====

/* std::ios::ios() */

void __thiscall std::ios::ios(ios *this)

{
  ios_base::ios_base((ios_base *)this);
  *(undefined8 *)(this + 0xd8) = 0;
  *(undefined8 *)(this + 0xe8) = 0;
  *(undefined8 *)(this + 0xf0) = 0;
  *(undefined ***)this = &PTR__ios_011b4e70;
  *(undefined2 *)(this + 0xe0) = 0;
  *(undefined8 *)(this + 0xf8) = 0;
  *(undefined8 *)(this + 0x100) = 0;
  return;
}


// ==== entry=00c1c2b0 name=FUN_00c1c2b0 size=8 ====

void FUN_00c1c2b0(long param_1,undefined8 param_2)

{
  *(undefined8 *)(param_1 + 0xe8) = param_2;
  return;
}


// ==== entry=00c1c2c0 orig=FUN_00c1c2c0 size=139 name=_M_cache_locale ====

/* std::ios::_M_cache_locale(std::locale const&) */

void __thiscall std::ios::_M_cache_locale(ios *this,locale *param_1)

{
  bool bVar1;
  ctype *pcVar2;
  num_put *pnVar3;
  num_get *pnVar4;
  
  bVar1 = has_facet<std::ctype<char>>(param_1);
  if (bVar1) {
    pcVar2 = use_facet<std::ctype<char>>(param_1);
    *(ctype **)(this + 0xf0) = pcVar2;
  }
  else {
    *(undefined8 *)(this + 0xf0) = 0;
  }
  bVar1 = has_facet<std::num_put<char,std::ostreambuf_iterator<char,std::char_traits<char>>>>
                    (param_1);
  if (bVar1) {
    pnVar3 = use_facet<std::num_put<char,std::ostreambuf_iterator<char,std::char_traits<char>>>>
                       (param_1);
    *(num_put **)(this + 0xf8) = pnVar3;
  }
  else {
    *(undefined8 *)(this + 0xf8) = 0;
  }
  bVar1 = has_facet<std::num_get<char,std::istreambuf_iterator<char,std::char_traits<char>>>>
                    (param_1);
  if (bVar1) {
    pnVar4 = use_facet<std::num_get<char,std::istreambuf_iterator<char,std::char_traits<char>>>>
                       (param_1);
    *(num_get **)(this + 0x100) = pnVar4;
  }
  else {
    *(undefined8 *)(this + 0x100) = 0;
  }
  return;
}


// ==== entry=00c1c360 orig=FUN_00c1c360 size=705 name=copyfmt ====

/* WARNING: Removing unreachable block (ram,0x00c1c5c0) */
/* std::ios::copyfmt(std::ios const&) */

ios * __thiscall std::ios::copyfmt(ios *this,ios *param_1)

{
  ios iVar1;
  int iVar2;
  undefined4 uVar3;
  ctype<char> *pcVar4;
  undefined8 uVar5;
  ctype<char> cVar6;
  ios *piVar7;
  long lVar8;
  long lVar9;
  ios *piVar10;
  long in_FS_OFFSET;
  locale alStack_38 [8];
  long local_30;
  
  local_30 = *(long *)(in_FS_OFFSET + 0x28);
  if (this == param_1) goto LAB_00c1c4da;
  piVar7 = this + 0x40;
  if (*(int *)(param_1 + 0xc0) < 9) {
LAB_00c1c3a1:
    lVar8 = *(long *)(param_1 + 0x28);
  }
  else {
    piVar7 = operator_new__((long)*(int *)(param_1 + 0xc0) << 4);
    lVar8 = (long)*(int *)(param_1 + 0xc0) + -1;
    piVar10 = piVar7;
    if (lVar8 < 0) goto LAB_00c1c3a1;
    do {
      lVar8 = lVar8 + -1;
      *(undefined8 *)piVar10 = 0;
      *(undefined8 *)(piVar10 + 8) = 0;
      piVar10 = piVar10 + 0x10;
    } while (lVar8 != -1);
    lVar8 = *(long *)(param_1 + 0x28);
  }
  if (lVar8 != 0) {
    LOCK();
    *(int *)(lVar8 + 0x14) = *(int *)(lVar8 + 0x14) + 1;
    UNLOCK();
  }
  ios_base::_M_call_callbacks((ios_base *)this,0);
  piVar10 = *(ios **)(this + 200);
  if (piVar10 != this + 0x40) {
    if (piVar10 != (ios *)0x0) {
      operator_delete__(piVar10);
    }
    *(undefined8 *)(this + 200) = 0;
  }
  ios_base::_M_dispose_callbacks((ios_base *)this);
  iVar2 = *(int *)(param_1 + 0xc0);
  *(long *)(this + 0x28) = lVar8;
  if (0 < iVar2) {
    lVar8 = *(long *)(param_1 + 200);
    lVar9 = 0;
    do {
      uVar5 = ((undefined8 *)(lVar8 + lVar9))[1];
      *(undefined8 *)(piVar7 + lVar9) = *(undefined8 *)(lVar8 + lVar9);
      *(undefined8 *)(piVar7 + lVar9 + 8) = uVar5;
      lVar9 = lVar9 + 0x10;
    } while (((ulong)(iVar2 - 1) + 1) * 0x10 != lVar9);
  }
  uVar3 = *(undefined4 *)(param_1 + 0x18);
  iVar1 = param_1[0xe1];
  *(ios **)(this + 200) = piVar7;
  *(int *)(this + 0xc0) = iVar2;
  *(undefined4 *)(this + 0x18) = uVar3;
  *(undefined8 *)(this + 0x10) = *(undefined8 *)(param_1 + 0x10);
  *(undefined8 *)(this + 8) = *(undefined8 *)(param_1 + 8);
  *(undefined8 *)(this + 0xd8) = *(undefined8 *)(param_1 + 0xd8);
  if (iVar1 == (ios)0x0) {
    pcVar4 = *(ctype<char> **)(param_1 + 0xf0);
    if (pcVar4 == (ctype<char> *)0x0) goto LAB_00c1c632;
    if (pcVar4[0x38] == (ctype<char>)0x0) {
      cVar6 = (ctype<char>)0x20;
      ctype<char>::_M_widen_init(pcVar4);
      if (*(code **)(*(long *)pcVar4 + 0x30) != FUN_00816ea8) {
        cVar6 = (ctype<char>)(**(code **)(*(long *)pcVar4 + 0x30))(pcVar4,0x20);
      }
    }
    else {
      cVar6 = pcVar4[0x59];
    }
    *(ctype<char> *)(param_1 + 0xe0) = cVar6;
    param_1[0xe1] = (ios)0x1;
    iVar1 = this[0xe1];
  }
  else {
    iVar1 = this[0xe1];
    cVar6 = *(ctype<char> *)(param_1 + 0xe0);
  }
  if (iVar1 == (ios)0x0) {
    pcVar4 = *(ctype<char> **)(this + 0xf0);
    if (pcVar4 == (ctype<char> *)0x0) {
LAB_00c1c632:
                    /* WARNING: Subroutine does not return */
      __throw_bad_cast();
    }
    if (pcVar4[0x38] == (ctype<char>)0x0) {
      ctype<char>::_M_widen_init(pcVar4);
      if (*(code **)(*(long *)pcVar4 + 0x30) != FUN_00816ea8) {
        (**(code **)(*(long *)pcVar4 + 0x30))(pcVar4,0x20);
      }
    }
    this[0xe1] = (ios)0x1;
  }
  *(ctype<char> *)(this + 0xe0) = cVar6;
  locale::locale(alStack_38,(locale *)(param_1 + 0xd0));
  locale::operator=((locale *)(this + 0xd0),alStack_38);
  locale::~locale(alStack_38);
  _M_cache_locale(this,(locale *)(this + 0xd0));
  ios_base::_M_call_callbacks((ios_base *)this,2);
  *(undefined4 *)(this + 0x1c) = *(undefined4 *)(param_1 + 0x1c);
  s_basic_ios__clear_c1bf70(this,*(undefined4 *)(this + 0x20));
LAB_00c1c4da:
  if (local_30 == *(long *)(in_FS_OFFSET + 0x28)) {
    return this;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ==== entry=00c1c640 orig=FUN_00c1c640 size=180 name=imbue ====

/* std::ios::imbue(std::locale const&) */

locale * std::ios::imbue(locale *param_1)

{
  long *plVar1;
  locale *in_RDX;
  ios *in_RSI;
  long in_FS_OFFSET;
  locale alStack_38 [8];
  long local_30;
  
  local_30 = *(long *)(in_FS_OFFSET + 0x28);
  locale::locale(param_1,(locale *)(in_RSI + 0xd0));
  ios_base::imbue(alStack_38);
  locale::~locale(alStack_38);
                    /* try { // try from 00c1c690 to 00c1c694 has its CatchHandler @ 00c1c6f9 */
  _M_cache_locale(in_RSI,in_RDX);
  plVar1 = *(long **)(in_RSI + 0xe8);
  if (plVar1 != (long *)0x0) {
    locale::locale(alStack_38,(locale *)(plVar1 + 7));
                    /* try { // try from 00c1c6b9 to 00c1c6bb has its CatchHandler @ 00c1c6f4 */
    (**(code **)(*plVar1 + 0x10))(plVar1);
    locale::operator=((locale *)(plVar1 + 7),in_RDX);
    locale::~locale(alStack_38);
  }
  if (local_30 == *(long *)(in_FS_OFFSET + 0x28)) {
    return param_1;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ==== entry=00c1c720 orig=FUN_00c1c720 size=84 name=init ====

/* std::ios::init(std::streambuf*) */

void __thiscall std::ios::init(ios *this,streambuf *param_1)

{
  ios_base::_M_init((ios_base *)this);
  _M_cache_locale(this,(locale *)(this + 0xd0));
  *(streambuf **)(this + 0xe8) = param_1;
  *(undefined2 *)(this + 0xe0) = 0;
  *(undefined4 *)(this + 0x1c) = 0;
  *(undefined8 *)(this + 0xd8) = 0;
  *(uint *)(this + 0x20) = (uint)(param_1 == (streambuf *)0x0);
  return;
}


// ==== entry=00c1c780 orig=FUN_00c1c780 size=113 name=ios ====

/* std::ios::ios(std::streambuf*) */

void __thiscall std::ios::ios(ios *this,streambuf *param_1)

{
  ios_base::ios_base((ios_base *)this);
  *(undefined8 *)(this + 0xd8) = 0;
  *(undefined8 *)(this + 0xe8) = 0;
  *(undefined ***)this = &PTR__ios_011b4e70;
  *(undefined2 *)(this + 0xe0) = 0;
  *(undefined8 *)(this + 0xf0) = 0;
  *(undefined8 *)(this + 0xf8) = 0;
  *(undefined8 *)(this + 0x100) = 0;
                    /* try { // try from 00c1c7e5 to 00c1c7e9 has its CatchHandler @ 00c1c7f1 */
  init(this,param_1);
  return;
}


// ==== entry=00c1c810 name=FUN_00c1c810 size=101 ====

void FUN_00c1c810(ios *param_1,long param_2)

{
  ios iVar1;
  undefined8 uVar2;
  
  FUN_00c71b00();
  std::ios::_M_cache_locale(param_1,(locale *)(param_1 + 0xd0));
  uVar2 = *(undefined8 *)(param_2 + 0xd8);
  *(undefined8 *)(param_2 + 0xd8) = 0;
  *(undefined8 *)(param_1 + 0xd8) = uVar2;
  param_1[0xe0] = *(ios *)(param_2 + 0xe0);
  iVar1 = *(ios *)(param_2 + 0xe1);
  *(undefined8 *)(param_1 + 0xe8) = 0;
  param_1[0xe1] = iVar1;
  return;
}


// ==== entry=00c1c880 name=FUN_00c1c880 size=134 ====

void FUN_00c1c880(ios *param_1,ios *param_2)

{
  ios iVar1;
  undefined8 uVar2;
  
  FUN_00c71c10();
  std::ios::_M_cache_locale(param_1,(locale *)(param_1 + 0xd0));
  std::ios::_M_cache_locale(param_2,(locale *)(param_2 + 0xd0));
  uVar2 = *(undefined8 *)(param_1 + 0xd8);
  *(undefined8 *)(param_1 + 0xd8) = *(undefined8 *)(param_2 + 0xd8);
  *(undefined8 *)(param_2 + 0xd8) = uVar2;
  iVar1 = param_1[0xe0];
  param_1[0xe0] = param_2[0xe0];
  param_2[0xe0] = iVar1;
  iVar1 = param_1[0xe1];
  param_1[0xe1] = param_2[0xe1];
  param_2[0xe1] = iVar1;
  return;
}


// ==== entry=00c1c910 name=FUN_00c1c910 size=101 ====

void FUN_00c1c910(ios *param_1,long param_2)

{
  ios iVar1;
  undefined8 uVar2;
  
  FUN_00c71b00();
  std::ios::_M_cache_locale(param_1,(locale *)(param_1 + 0xd0));
  uVar2 = *(undefined8 *)(param_2 + 0xd8);
  *(undefined8 *)(param_2 + 0xd8) = 0;
  *(undefined8 *)(param_1 + 0xd8) = uVar2;
  param_1[0xe0] = *(ios *)(param_2 + 0xe0);
  iVar1 = *(ios *)(param_2 + 0xe1);
  *(undefined8 *)(param_1 + 0xe8) = 0;
  param_1[0xe1] = iVar1;
  return;
}


// ==== entry=00c1c980 name=FUN_00c1c980 size=8 ====

bool FUN_00c1c980(long param_1)

{
  return (*(byte *)(param_1 + 0x20) & 5) == 0;
}


// ==== entry=00c1c990 orig=FUN_00c1c990 size=8 name=operator! ====

/* std::wios::TEMPNAMEPLACEHOLDERVALUE() const */

bool __thiscall std::wios::operator!(wios *this)

{
  return ((byte)this[0x20] & 5) != 0;
}


// ==== entry=00c1c9a0 orig=FUN_00c1c9a0 size=4 name=rdstate ====

/* std::wios::rdstate() const */

undefined4 __thiscall std::wios::rdstate(wios *this)

{
  return *(undefined4 *)(this + 0x20);
}


// ==== entry=00c1c9b0 orig=FUN_00c1c9b0 size=37 name=s_basic_ios__clear_c1c9b0 ====

/* std::wios::clear(std::_Ios_Iostate) */

void __thiscall std::wios::s_basic_ios__clear_c1c9b0(wios *this,uint param_2)

{
  if (*(long *)(this + 0xe8) == 0) {
    param_2 = param_2 | 1;
  }
  *(uint *)(this + 0x20) = param_2;
  if ((*(uint *)(this + 0x1c) & param_2) == 0) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __throw_ios_failure("basic_ios::clear");
}


// ==== entry=00c1c9e0 orig=FUN_00c1c9e0 size=8 name=setstate ====

/* std::wios::setstate(std::_Ios_Iostate) */

void __thiscall std::wios::setstate(wios *this,uint param_2)

{
  s_basic_ios__clear_c1c9b0(this,param_2 | *(uint *)(this + 0x20));
  return;
}


// ==== entry=00c1c9f0 orig=FUN_00c1c9f0 size=15 name=_M_setstate ====

/* std::wios::_M_setstate(std::_Ios_Iostate) */

void __thiscall std::wios::_M_setstate(wios *this,uint param_2)

{
  *(uint *)(this + 0x20) = *(uint *)(this + 0x20) | param_2;
  if ((*(uint *)(this + 0x1c) & param_2) == 0) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __cxa_rethrow();
}


// ==== entry=00c1ca00 orig=FUN_00c1ca00 size=9 name=good ====

/* std::wios::good() const */

undefined4 __thiscall std::wios::good(wios *this)

{
  return CONCAT31((int3)((uint)*(int *)(this + 0x20) >> 8),*(int *)(this + 0x20) == 0);
}


// ==== entry=00c1ca10 orig=FUN_00c1ca10 size=9 name=eof ====

/* std::wios::eof() const */

uint __thiscall std::wios::eof(wios *this)

{
  return *(uint *)(this + 0x20) >> 1 & 1;
}


// ==== entry=00c1ca20 orig=FUN_00c1ca20 size=8 name=fail ====

/* std::wios::fail() const */

bool __thiscall std::wios::fail(wios *this)

{
  return ((byte)this[0x20] & 5) != 0;
}


// ==== entry=00c1ca30 orig=FUN_00c1ca30 size=7 name=bad ====

/* std::wios::bad() const */

uint __thiscall std::wios::bad(wios *this)

{
  return *(uint *)(this + 0x20) & 1;
}


// ==== entry=00c1ca40 orig=FUN_00c1ca40 size=4 name=exceptions ====

/* std::wios::exceptions() const */

undefined4 __thiscall std::wios::exceptions(wios *this)

{
  return *(undefined4 *)(this + 0x1c);
}


// ==== entry=00c1ca50 orig=FUN_00c1ca50 size=11 name=exceptions ====

/* std::wios::exceptions(std::_Ios_Iostate) */

void __thiscall std::wios::exceptions(wios *this,undefined4 param_2)

{
  *(undefined4 *)(this + 0x1c) = param_2;
  s_basic_ios__clear_c1c9b0(this,*(undefined4 *)(this + 0x20));
  return;
}


// ==== entry=00c1ca60 orig=FUN_00c1ca60 size=8 name=tie ====

/* std::wios::tie() const */

undefined8 __thiscall std::wios::tie(wios *this)

{
  return *(undefined8 *)(this + 0xd8);
}


// ==== entry=00c1ca70 orig=FUN_00c1ca70 size=15 name=tie ====

/* std::wios::tie(std::wostream*) */

undefined8 __thiscall std::wios::tie(wios *this,wostream *param_1)

{
  undefined8 uVar1;
  
  uVar1 = *(undefined8 *)(this + 0xd8);
  *(wostream **)(this + 0xd8) = param_1;
  return uVar1;
}


// ==== entry=00c1ca80 orig=FUN_00c1ca80 size=8 name=rdbuf ====

/* std::wios::rdbuf() const */

undefined8 __thiscall std::wios::rdbuf(wios *this)

{
  return *(undefined8 *)(this + 0xe8);
}


// ==== entry=00c1ca90 orig=FUN_00c1ca90 size=27 name=rdbuf ====

/* std::wios::rdbuf(std::wstreambuf*) */

undefined8 __thiscall std::wios::rdbuf(wios *this,wstreambuf *param_1)

{
  undefined8 uVar1;
  
  uVar1 = *(undefined8 *)(this + 0xe8);
  *(wstreambuf **)(this + 0xe8) = param_1;
  s_basic_ios__clear_c1c9b0(this,0);
  return uVar1;
}


// ==== entry=00c1cab0 orig=FUN_00c1cab0 size=63 name=fill ====

/* std::wios::fill() const */

ulong __thiscall std::wios::fill(wios *this)

{
  long *plVar1;
  ulong uVar2;
  
  if (this[0xe4] != (wios)0x0) {
    return (ulong)*(uint *)(this + 0xe0);
  }
  plVar1 = *(long **)(this + 0xf0);
  if (plVar1 != (long *)0x0) {
    uVar2 = (**(code **)(*plVar1 + 0x50))(plVar1,0x20);
    this[0xe4] = (wios)0x1;
    *(int *)(this + 0xe0) = (int)uVar2;
    return uVar2;
  }
                    /* WARNING: Subroutine does not return */
  __throw_bad_cast();
}


// ==== entry=00c1caf0 orig=FUN_00c1caf0 size=87 name=fill ====

/* std::wios::fill(wchar_t) */

ulong __thiscall std::wios::fill(wios *this,wchar_t param_1)

{
  uint uVar1;
  long *plVar2;
  ulong uVar3;
  
  if (this[0xe4] != (wios)0x0) {
    uVar1 = *(uint *)(this + 0xe0);
    *(wchar_t *)(this + 0xe0) = param_1;
    return (ulong)uVar1;
  }
  plVar2 = *(long **)(this + 0xf0);
  if (plVar2 != (long *)0x0) {
    uVar3 = (**(code **)(*plVar2 + 0x50))(plVar2,0x20);
    *(wchar_t *)(this + 0xe0) = param_1;
    this[0xe4] = (wios)0x1;
    return uVar3;
  }
                    /* WARNING: Subroutine does not return */
  __throw_bad_cast();
}


// ==== entry=00c1cb50 orig=FUN_00c1cb50 size=27 name=narrow ====

/* std::wios::narrow(wchar_t, char) const */

void __thiscall std::wios::narrow(wios *this,wchar_t param_1,char param_2)

{
  long *plVar1;
  
  plVar1 = *(long **)(this + 0xf0);
  if (plVar1 != (long *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x00c1cb62. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(*plVar1 + 0x60))(plVar1,param_1,(int)param_2);
    return;
  }
                    /* WARNING: Subroutine does not return */
  __throw_bad_cast();
}


// ==== entry=00c1cb70 orig=FUN_00c1cb70 size=28 name=widen ====

/* std::wios::widen(char) const */

void __thiscall std::wios::widen(wios *this,char param_1)

{
  long *plVar1;
  
  plVar1 = *(long **)(this + 0xf0);
  if (plVar1 != (long *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x00c1cb83. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(*plVar1 + 0x50))(plVar1,(int)param_1);
    return;
  }
                    /* WARNING: Subroutine does not return */
  __throw_bad_cast();
}


// ==== entry=00c1cb90 orig=FUN_00c1cb90 size=97 name=wios ====

/* std::wios::wios() */

void __thiscall std::wios::wios(wios *this)

{
  ios_base::ios_base((ios_base *)this);
  *(undefined8 *)(this + 0xd8) = 0;
  *(undefined4 *)(this + 0xe0) = 0;
  this[0xe4] = (wios)0x0;
  *(undefined ***)this = &PTR__wios_011b4e90;
  *(undefined8 *)(this + 0xe8) = 0;
  *(undefined8 *)(this + 0xf0) = 0;
  *(undefined8 *)(this + 0xf8) = 0;
  *(undefined8 *)(this + 0x100) = 0;
  return;
}


// ==== entry=00c1cc00 name=FUN_00c1cc00 size=8 ====

void FUN_00c1cc00(long param_1,undefined8 param_2)

{
  *(undefined8 *)(param_1 + 0xe8) = param_2;
  return;
}


// ==== entry=00c1cc10 orig=FUN_00c1cc10 size=139 name=_M_cache_locale ====

/* std::wios::_M_cache_locale(std::locale const&) */

void __thiscall std::wios::_M_cache_locale(wios *this,locale *param_1)

{
  bool bVar1;
  ctype *pcVar2;
  num_put *pnVar3;
  num_get *pnVar4;
  
  bVar1 = has_facet<std::ctype<wchar_t>>(param_1);
  if (bVar1) {
    pcVar2 = use_facet<std::ctype<wchar_t>>(param_1);
    *(ctype **)(this + 0xf0) = pcVar2;
  }
  else {
    *(undefined8 *)(this + 0xf0) = 0;
  }
  bVar1 = has_facet<std::num_put<wchar_t,std::ostreambuf_iterator<wchar_t,std::char_traits<wchar_t>>>>
                    (param_1);
  if (bVar1) {
    pnVar3 = use_facet<std::num_put<wchar_t,std::ostreambuf_iterator<wchar_t,std::char_traits<wchar_t>>>>
                       (param_1);
    *(num_put **)(this + 0xf8) = pnVar3;
  }
  else {
    *(undefined8 *)(this + 0xf8) = 0;
  }
  bVar1 = has_facet<std::num_get<wchar_t,std::istreambuf_iterator<wchar_t,std::char_traits<wchar_t>>>>
                    (param_1);
  if (bVar1) {
    pnVar4 = use_facet<std::num_get<wchar_t,std::istreambuf_iterator<wchar_t,std::char_traits<wchar_t>>>>
                       (param_1);
    *(num_get **)(this + 0x100) = pnVar4;
  }
  else {
    *(undefined8 *)(this + 0x100) = 0;
  }
  return;
}


// ==== entry=00c1ccb0 orig=FUN_00c1ccb0 size=607 name=copyfmt ====

/* WARNING: Removing unreachable block (ram,0x00c1cf10) */
/* std::wios::copyfmt(std::wios const&) */

wios * __thiscall std::wios::copyfmt(wios *this,wios *param_1)

{
  wios wVar1;
  int iVar2;
  long *plVar3;
  undefined8 uVar4;
  undefined4 uVar5;
  wios *pwVar6;
  long lVar7;
  long lVar8;
  wios *pwVar9;
  long in_FS_OFFSET;
  locale alStack_38 [8];
  long local_30;
  
  local_30 = *(long *)(in_FS_OFFSET + 0x28);
  if (this == param_1) goto LAB_00c1ce29;
  pwVar6 = this + 0x40;
  if (*(int *)(param_1 + 0xc0) < 9) {
LAB_00c1ccf1:
    lVar7 = *(long *)(param_1 + 0x28);
  }
  else {
    pwVar6 = operator_new__((long)*(int *)(param_1 + 0xc0) << 4);
    lVar7 = (long)*(int *)(param_1 + 0xc0) + -1;
    pwVar9 = pwVar6;
    if (lVar7 < 0) goto LAB_00c1ccf1;
    do {
      lVar7 = lVar7 + -1;
      *(undefined8 *)pwVar9 = 0;
      *(undefined8 *)(pwVar9 + 8) = 0;
      pwVar9 = pwVar9 + 0x10;
    } while (lVar7 != -1);
    lVar7 = *(long *)(param_1 + 0x28);
  }
  if (lVar7 != 0) {
    LOCK();
    *(int *)(lVar7 + 0x14) = *(int *)(lVar7 + 0x14) + 1;
    UNLOCK();
  }
  ios_base::_M_call_callbacks((ios_base *)this,0);
  pwVar9 = *(wios **)(this + 200);
  if (pwVar9 != this + 0x40) {
    if (pwVar9 != (wios *)0x0) {
      operator_delete__(pwVar9);
    }
    *(undefined8 *)(this + 200) = 0;
  }
  ios_base::_M_dispose_callbacks((ios_base *)this);
  iVar2 = *(int *)(param_1 + 0xc0);
  *(long *)(this + 0x28) = lVar7;
  if (0 < iVar2) {
    lVar7 = *(long *)(param_1 + 200);
    lVar8 = 0;
    do {
      uVar4 = ((undefined8 *)(lVar7 + lVar8))[1];
      *(undefined8 *)(pwVar6 + lVar8) = *(undefined8 *)(lVar7 + lVar8);
      *(undefined8 *)(pwVar6 + lVar8 + 8) = uVar4;
      lVar8 = lVar8 + 0x10;
    } while (((ulong)(iVar2 - 1) + 1) * 0x10 != lVar8);
  }
  uVar5 = *(undefined4 *)(param_1 + 0x18);
  wVar1 = param_1[0xe4];
  *(wios **)(this + 200) = pwVar6;
  *(int *)(this + 0xc0) = iVar2;
  *(undefined4 *)(this + 0x18) = uVar5;
  *(undefined8 *)(this + 0x10) = *(undefined8 *)(param_1 + 0x10);
  *(undefined8 *)(this + 8) = *(undefined8 *)(param_1 + 8);
  *(undefined8 *)(this + 0xd8) = *(undefined8 *)(param_1 + 0xd8);
  if (wVar1 == (wios)0x0) {
    plVar3 = *(long **)(param_1 + 0xf0);
    if (plVar3 == (long *)0x0) goto LAB_00c1cf1f;
    uVar5 = (**(code **)(*plVar3 + 0x50))(plVar3,0x20);
    param_1[0xe4] = (wios)0x1;
    wVar1 = this[0xe4];
    *(undefined4 *)(param_1 + 0xe0) = uVar5;
  }
  else {
    wVar1 = this[0xe4];
    uVar5 = *(undefined4 *)(param_1 + 0xe0);
  }
  if (wVar1 == (wios)0x0) {
    plVar3 = *(long **)(this + 0xf0);
    if (plVar3 == (long *)0x0) {
LAB_00c1cf1f:
                    /* WARNING: Subroutine does not return */
      __throw_bad_cast();
    }
    (**(code **)(*plVar3 + 0x50))(plVar3,0x20);
    this[0xe4] = (wios)0x1;
  }
  *(undefined4 *)(this + 0xe0) = uVar5;
  locale::locale(alStack_38,(locale *)(param_1 + 0xd0));
  locale::operator=((locale *)(this + 0xd0),alStack_38);
  locale::~locale(alStack_38);
  _M_cache_locale(this,(locale *)(this + 0xd0));
  ios_base::_M_call_callbacks((ios_base *)this,2);
  *(undefined4 *)(this + 0x1c) = *(undefined4 *)(param_1 + 0x1c);
  s_basic_ios__clear_c1c9b0(this,*(undefined4 *)(this + 0x20));
LAB_00c1ce29:
  if (local_30 == *(long *)(in_FS_OFFSET + 0x28)) {
    return this;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ==== entry=00c1cf30 orig=FUN_00c1cf30 size=180 name=imbue ====

/* std::wios::imbue(std::locale const&) */

locale * std::wios::imbue(locale *param_1)

{
  long *plVar1;
  locale *in_RDX;
  wios *in_RSI;
  long in_FS_OFFSET;
  locale alStack_38 [8];
  long local_30;
  
  local_30 = *(long *)(in_FS_OFFSET + 0x28);
  locale::locale(param_1,(locale *)(in_RSI + 0xd0));
  ios_base::imbue(alStack_38);
  locale::~locale(alStack_38);
                    /* try { // try from 00c1cf80 to 00c1cf84 has its CatchHandler @ 00c1cfe9 */
  _M_cache_locale(in_RSI,in_RDX);
  plVar1 = *(long **)(in_RSI + 0xe8);
  if (plVar1 != (long *)0x0) {
    locale::locale(alStack_38,(locale *)(plVar1 + 7));
                    /* try { // try from 00c1cfa9 to 00c1cfab has its CatchHandler @ 00c1cfe4 */
    (**(code **)(*plVar1 + 0x10))(plVar1);
    locale::operator=((locale *)(plVar1 + 7),in_RDX);
    locale::~locale(alStack_38);
  }
  if (local_30 == *(long *)(in_FS_OFFSET + 0x28)) {
    return param_1;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ==== entry=00c1d010 orig=FUN_00c1d010 size=92 name=init ====

/* std::wios::init(std::wstreambuf*) */

void __thiscall std::wios::init(wios *this,wstreambuf *param_1)

{
  ios_base::_M_init((ios_base *)this);
  _M_cache_locale(this,(locale *)(this + 0xd0));
  *(wstreambuf **)(this + 0xe8) = param_1;
  *(undefined4 *)(this + 0xe0) = 0;
  this[0xe4] = (wios)0x0;
  *(undefined8 *)(this + 0xd8) = 0;
  *(undefined4 *)(this + 0x1c) = 0;
  *(uint *)(this + 0x20) = (uint)(param_1 == (wstreambuf *)0x0);
  return;
}


// ==== entry=00c1d070 orig=FUN_00c1d070 size=121 name=wios ====

/* std::wios::wios(std::wstreambuf*) */

void __thiscall std::wios::wios(wios *this,wstreambuf *param_1)

{
  ios_base::ios_base((ios_base *)this);
  *(undefined8 *)(this + 0xd8) = 0;
  *(undefined4 *)(this + 0xe0) = 0;
  *(undefined ***)this = &PTR__wios_011b4e90;
  this[0xe4] = (wios)0x0;
  *(undefined8 *)(this + 0xe8) = 0;
  *(undefined8 *)(this + 0xf0) = 0;
  *(undefined8 *)(this + 0xf8) = 0;
  *(undefined8 *)(this + 0x100) = 0;
                    /* try { // try from 00c1d0dd to 00c1d0e1 has its CatchHandler @ 00c1d0e9 */
  init(this,param_1);
  return;
}


// ==== entry=00c1d100 name=FUN_00c1d100 size=100 ====

void FUN_00c1d100(wios *param_1,long param_2)

{
  wios wVar1;
  undefined8 uVar2;
  
  FUN_00c71b00();
  std::wios::_M_cache_locale(param_1,(locale *)(param_1 + 0xd0));
  uVar2 = *(undefined8 *)(param_2 + 0xd8);
  *(undefined8 *)(param_2 + 0xd8) = 0;
  *(undefined8 *)(param_1 + 0xd8) = uVar2;
  *(undefined4 *)(param_1 + 0xe0) = *(undefined4 *)(param_2 + 0xe0);
  wVar1 = *(wios *)(param_2 + 0xe4);
  *(undefined8 *)(param_1 + 0xe8) = 0;
  param_1[0xe4] = wVar1;
  return;
}


// ==== entry=00c1d170 name=FUN_00c1d170 size=132 ====

void FUN_00c1d170(wios *param_1,wios *param_2)

{
  wios wVar1;
  undefined4 uVar2;
  undefined8 uVar3;
  
  FUN_00c71c10();
  std::wios::_M_cache_locale(param_1,(locale *)(param_1 + 0xd0));
  std::wios::_M_cache_locale(param_2,(locale *)(param_2 + 0xd0));
  uVar3 = *(undefined8 *)(param_1 + 0xd8);
  *(undefined8 *)(param_1 + 0xd8) = *(undefined8 *)(param_2 + 0xd8);
  *(undefined8 *)(param_2 + 0xd8) = uVar3;
  uVar2 = *(undefined4 *)(param_1 + 0xe0);
  *(undefined4 *)(param_1 + 0xe0) = *(undefined4 *)(param_2 + 0xe0);
  *(undefined4 *)(param_2 + 0xe0) = uVar2;
  wVar1 = param_1[0xe4];
  param_1[0xe4] = param_2[0xe4];
  param_2[0xe4] = wVar1;
  return;
}


// ==== entry=00c1d200 name=FUN_00c1d200 size=100 ====

void FUN_00c1d200(wios *param_1,long param_2)

{
  wios wVar1;
  undefined8 uVar2;
  
  FUN_00c71b00();
  std::wios::_M_cache_locale(param_1,(locale *)(param_1 + 0xd0));
  uVar2 = *(undefined8 *)(param_2 + 0xd8);
  *(undefined8 *)(param_2 + 0xd8) = 0;
  *(undefined8 *)(param_1 + 0xd8) = uVar2;
  *(undefined4 *)(param_1 + 0xe0) = *(undefined4 *)(param_2 + 0xe0);
  wVar1 = *(wios *)(param_2 + 0xe4);
  *(undefined8 *)(param_1 + 0xe8) = 0;
  param_1[0xe4] = wVar1;
  return;
}


// ==== entry=00c1d270 orig=FUN_00c1d270 size=38 name=~ostream ====

/* std::ostream::~ostream() */

void __thiscall std::ostream::~ostream(ostream *this)

{
  *(undefined8 *)this = 0x11b4f18;
  *(undefined ***)(this + 8) = &PTR__ios_011b4e70;
  ios_base::~ios_base((ios_base *)(this + 8));
  return;
}


// ==== entry=00c1d2a0 orig=FUN_00c1d2a0 size=45 name=~ostream ====

/* virtual thunk to std::ostream::~ostream() */

void __thiscall std::ostream::~ostream(ostream *this)

{
  ostream *poVar1;
  
  poVar1 = this + *(long *)(*(long *)this + -0x18);
  *(undefined8 *)poVar1 = 0x11b4f18;
  *(undefined ***)(poVar1 + 8) = &PTR__ios_011b4e70;
  ios_base::~ios_base((ios_base *)(poVar1 + 8));
  return;
}


// ==== entry=00c1d2d0 orig=FUN_00c1d2d0 size=51 name=~ostream ====

/* std::ostream::~ostream() */

void __thiscall std::ostream::~ostream(ostream *this)

{
  *(undefined8 *)this = 0x11b4f18;
  *(undefined ***)(this + 8) = &PTR__ios_011b4e70;
  ios_base::~ios_base((ios_base *)(this + 8));
  operator_delete(this);
  return;
}


// ==== entry=00c1d310 orig=FUN_00c1d310 size=58 name=~ostream ====

/* virtual thunk to std::ostream::~ostream() */

void __thiscall std::ostream::~ostream(ostream *this)

{
  ostream *poVar1;
  
  poVar1 = this + *(long *)(*(long *)this + -0x18);
  *(undefined8 *)poVar1 = 0x11b4f18;
  *(undefined ***)(poVar1 + 8) = &PTR__ios_011b4e70;
  ios_base::~ios_base((ios_base *)(poVar1 + 8));
  operator_delete(poVar1);
  return;
}


// ==== entry=00c1d350 orig=FUN_00c1d350 size=38 name=~wostream ====

/* std::wostream::~wostream() */

void __thiscall std::wostream::~wostream(wostream *this)

{
  *(undefined8 *)this = 0x11b4f78;
  *(undefined ***)(this + 8) = &PTR__wios_011b4e90;
  ios_base::~ios_base((ios_base *)(this + 8));
  return;
}


// ==== entry=00c1d380 orig=FUN_00c1d380 size=45 name=~wostream ====

/* virtual thunk to std::wostream::~wostream() */

void __thiscall std::wostream::~wostream(wostream *this)

{
  wostream *pwVar1;
  
  pwVar1 = this + *(long *)(*(long *)this + -0x18);
  *(undefined8 *)pwVar1 = 0x11b4f78;
  *(undefined ***)(pwVar1 + 8) = &PTR__wios_011b4e90;
  ios_base::~ios_base((ios_base *)(pwVar1 + 8));
  return;
}


// ==== entry=00c1d3b0 orig=FUN_00c1d3b0 size=51 name=~wostream ====

/* std::wostream::~wostream() */

void __thiscall std::wostream::~wostream(wostream *this)

{
  *(undefined8 *)this = 0x11b4f78;
  *(undefined ***)(this + 8) = &PTR__wios_011b4e90;
  ios_base::~ios_base((ios_base *)(this + 8));
  operator_delete(this);
  return;
}


// ==== entry=00c1d3f0 orig=FUN_00c1d3f0 size=58 name=~wostream ====

/* virtual thunk to std::wostream::~wostream() */

void __thiscall std::wostream::~wostream(wostream *this)

{
  wostream *pwVar1;
  
  pwVar1 = this + *(long *)(*(long *)this + -0x18);
  *(undefined8 *)pwVar1 = 0x11b4f78;
  *(undefined ***)(pwVar1 + 8) = &PTR__wios_011b4e90;
  ios_base::~ios_base((ios_base *)(pwVar1 + 8));
  operator_delete(pwVar1);
  return;
}


// ==== entry=00c1d430 orig=FUN_00c1d430 size=25 name=ostream ====

/* std::ostream::ostream(std::streambuf*) */

void __thiscall std::ostream::ostream(ostream *this,streambuf *param_1)

{
  long lVar1;
  streambuf *in_RDX;
  
  lVar1 = *(long *)param_1;
  *(long *)this = lVar1;
  lVar1 = *(long *)(lVar1 + -0x18);
  *(undefined8 *)(this + lVar1) = *(undefined8 *)(param_1 + 8);
  ios::init((ios *)(this + lVar1),in_RDX);
  return;
}


// ==== entry=00c1d450 orig=FUN_00c1d450 size=124 name=ostream ====

/* std::ostream::ostream(std::streambuf*) */

void __thiscall std::ostream::ostream(ostream *this,streambuf *param_1)

{
  ios_base::ios_base((ios_base *)(this + 8));
  *(undefined2 *)(this + 0xe8) = 0;
  *(undefined8 *)(this + 0xe0) = 0;
  *(undefined8 *)(this + 0xf0) = 0;
  *(undefined8 *)(this + 0xf8) = 0;
  *(undefined8 *)(this + 0x100) = 0;
  *(undefined8 *)(this + 0x108) = 0;
  *(undefined8 *)this = 0x11b4f18;
  *(undefined8 *)(this + 8) = 0x11b4f40;
                    /* try { // try from 00c1d4c2 to 00c1d4c6 has its CatchHandler @ 00c1d4cc */
  ios::init((ios *)(this + 8),param_1);
  return;
}


// ==== entry=00c1d4f0 orig=FUN_00c1d4f0 size=19 name=~ostream ====

/* std::ostream::~ostream() */

void __thiscall std::ostream::~ostream(ostream *this)

{
  long lVar1;
  long *in_RSI;
  
  lVar1 = *in_RSI;
  *(long *)this = lVar1;
  *(long *)(this + *(long *)(lVar1 + -0x18)) = in_RSI[1];
  return;
}


// ==== entry=00c1d510 orig=FUN_00c1d510 size=2 name=operator<< ====

/* std::ostream::TEMPNAMEPLACEHOLDERVALUE(std::ostream& (*)(std::ostream&)) */

void __thiscall std::ostream::operator<<(ostream *this,_func_ostream_ptr_ostream_ptr *param_1)

{
                    /* WARNING: Could not recover jumptable at 0x00c1d510. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*param_1)(this);
  return;
}


// ==== entry=00c1d520 orig=FUN_00c1d520 size=21 name=operator<< ====

/* std::ostream::TEMPNAMEPLACEHOLDERVALUE(std::ios& (*)(std::ios&)) */

ostream * __thiscall std::ostream::operator<<(ostream *this,_func_ios_ptr_ios_ptr *param_1)

{
  (*param_1)((ios *)(this + *(long *)(*(long *)this + -0x18)));
  return this;
}


// ==== entry=00c1d540 orig=FUN_00c1d540 size=21 name=operator<< ====

/* std::ostream::TEMPNAMEPLACEHOLDERVALUE(std::ios_base& (*)(std::ios_base&)) */

ostream * __thiscall
std::ostream::operator<<(ostream *this,_func_ios_base_ptr_ios_base_ptr *param_1)

{
  (*param_1)((ios_base *)(this + *(long *)(*(long *)this + -0x18)));
  return this;
}


// ==== entry=00c1d560 orig=FUN_00c1d560 size=72 name=_M_write ====

/* std::ostream::_M_write(char const*, long) */

void __thiscall std::ostream::_M_write(ostream *this,char *param_1,long param_2)

{
  long lVar1;
  
  lVar1 = (**(code **)(**(long **)(this + *(long *)(*(long *)this + -0x18) + 0xe8) + 0x60))();
  if (param_2 == lVar1) {
    return;
  }
  ios::s_basic_ios__clear_c1bf70
            ((ios *)(this + *(long *)(*(long *)this + -0x18)),
             *(uint *)((ios *)(this + *(long *)(*(long *)this + -0x18)) + 0x20) | 1);
  return;
}


// ==== entry=00c1d5b0 orig=FUN_00c1d5b0 size=66 name=flush ====

/* std::ostream::flush() */

ostream * __thiscall std::ostream::flush(ostream *this)

{
  int iVar1;
  
  if (*(long **)(this + *(long *)(*(long *)this + -0x18) + 0xe8) != (long *)0x0) {
                    /* try { // try from 00c1d5cb to 00c1d5cd has its CatchHandler @ 00c1d5fa */
    iVar1 = (**(code **)(**(long **)(this + *(long *)(*(long *)this + -0x18) + 0xe8) + 0x30))();
    if (iVar1 == -1) {
      ios::s_basic_ios__clear_c1bf70
                ((ios *)(this + *(long *)(*(long *)this + -0x18)),
                 *(uint *)((ios *)(this + *(long *)(*(long *)this + -0x18)) + 0x20) | 1);
      return this;
    }
  }
  return this;
}


// ==== entry=00c1d670 orig=FUN_00c1d670 size=123 name=tellp ====

/* std::ostream::tellp() */

undefined8 __thiscall std::ostream::tellp(ostream *this)

{
  long lVar1;
  undefined8 uVar2;
  long in_FS_OFFSET;
  
  lVar1 = *(long *)(in_FS_OFFSET + 0x28);
  if (((byte)this[*(long *)(*(long *)this + -0x18) + 0x20] & 5) == 0) {
                    /* try { // try from 00c1d6ae to 00c1d6b0 has its CatchHandler @ 00c1d6f2 */
    uVar2 = (**(code **)(**(long **)(this + *(long *)(*(long *)this + -0x18) + 0xe8) + 0x20))
                      (*(long **)(this + *(long *)(*(long *)this + -0x18) + 0xe8),0,1,0x10);
  }
  else {
    uVar2 = 0xffffffffffffffff;
  }
  if (lVar1 == *(long *)(in_FS_OFFSET + 0x28)) {
    return uVar2;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ==== entry=00c1d770 orig=FUN_00c1d770 size=117 name=seekp ====

/* std::ostream::seekp(std::fpos<__mbstate_t>) */

long * std::ostream::seekp(long *param_1)

{
  long lVar1;
  long lVar2;
  ios *piVar3;
  long in_FS_OFFSET;
  
  lVar1 = *(long *)(in_FS_OFFSET + 0x28);
  if ((*(byte *)((long)param_1 + *(long *)(*param_1 + -0x18) + 0x20) & 5) == 0) {
                    /* try { // try from 00c1d7a7 to 00c1d7a9 has its CatchHandler @ 00c1d7ec */
    lVar2 = (**(code **)(**(long **)((long)param_1 + *(long *)(*param_1 + -0x18) + 0xe8) + 0x28))();
    if (lVar2 == -1) {
      piVar3 = (ios *)(*(long *)(*param_1 + -0x18) + (long)param_1);
      ios::s_basic_ios__clear_c1bf70(piVar3,*(uint *)(piVar3 + 0x20) | 4);
    }
  }
  if (lVar1 == *(long *)(in_FS_OFFSET + 0x28)) {
    return param_1;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ==== entry=00c1d860 orig=FUN_00c1d860 size=117 name=seekp ====

/* std::ostream::seekp(long, std::_Ios_Seekdir) */

long * std::ostream::seekp(long *param_1)

{
  long lVar1;
  long lVar2;
  ios *piVar3;
  long in_FS_OFFSET;
  
  lVar1 = *(long *)(in_FS_OFFSET + 0x28);
  if ((*(byte *)((long)param_1 + *(long *)(*param_1 + -0x18) + 0x20) & 5) == 0) {
                    /* try { // try from 00c1d897 to 00c1d899 has its CatchHandler @ 00c1d8dc */
    lVar2 = (**(code **)(**(long **)((long)param_1 + *(long *)(*param_1 + -0x18) + 0xe8) + 0x20))();
    if (lVar2 == -1) {
      piVar3 = (ios *)(*(long *)(*param_1 + -0x18) + (long)param_1);
      ios::s_basic_ios__clear_c1bf70(piVar3,*(uint *)(piVar3 + 0x20) | 4);
    }
  }
  if (lVar1 == *(long *)(in_FS_OFFSET + 0x28)) {
    return param_1;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ==== entry=00c1d950 orig=FUN_00c1d950 size=24 name=ostream ====

/* std::ostream::ostream() */

void __thiscall std::ostream::ostream(ostream *this)

{
  long lVar1;
  long *in_RSI;
  
  lVar1 = *in_RSI;
  *(long *)this = lVar1;
  lVar1 = *(long *)(lVar1 + -0x18);
  *(long *)(this + lVar1) = in_RSI[1];
  ios::init((ios *)(this + lVar1),(streambuf *)0x0);
  return;
}


// ==== entry=00c1d970 orig=FUN_00c1d970 size=120 name=ostream ====

/* std::ostream::ostream() */

void __thiscall std::ostream::ostream(ostream *this)

{
  ios_base::ios_base((ios_base *)(this + 8));
  *(undefined2 *)(this + 0xe8) = 0;
  *(undefined8 *)(this + 0xe0) = 0;
  *(undefined8 *)(this + 0xf0) = 0;
  *(undefined8 *)(this + 0xf8) = 0;
  *(undefined8 *)(this + 0x100) = 0;
  *(undefined8 *)(this + 0x108) = 0;
  *(undefined8 *)this = 0x11b4f18;
  *(undefined8 *)(this + 8) = 0x11b4f40;
                    /* try { // try from 00c1d9de to 00c1d9e2 has its CatchHandler @ 00c1d9e8 */
  ios::init((ios *)(this + 8),(streambuf *)0x0);
  return;
}


// ==== entry=00c1da10 name=FUN_00c1da10 size=19 ====

void FUN_00c1da10(long *param_1,long *param_2)

{
  long lVar1;
  
  lVar1 = *param_2;
  *param_1 = lVar1;
  *(long *)((long)param_1 + *(long *)(lVar1 + -0x18)) = param_2[1];
  return;
}


// ==== entry=00c1da30 name=FUN_00c1da30 size=101 ====

void FUN_00c1da30(undefined8 *param_1)

{
  std::ios_base::ios_base((ios_base *)(param_1 + 1));
  param_1[0x1c] = 0;
  *(undefined2 *)(param_1 + 0x1d) = 0;
  param_1[0x1e] = 0;
  param_1[0x1f] = 0;
  param_1[0x20] = 0;
  param_1[0x21] = 0;
  *param_1 = 0x11b4f18;
  param_1[1] = 0x11b4f40;
  return;
}


// ==== entry=00c1daa0 name=FUN_00c1daa0 size=128 ====

void FUN_00c1daa0(long *param_1,long *param_2,long *param_3)

{
  ios iVar1;
  undefined8 uVar2;
  long lVar3;
  ios *this;
  
  lVar3 = *param_2;
  *param_1 = lVar3;
  this = (ios *)((long)param_1 + *(long *)(lVar3 + -0x18));
  *(long *)this = param_2[1];
  lVar3 = (long)param_3 + *(long *)(*param_3 + -0x18);
  FUN_00c71b00(this,lVar3);
  std::ios::_M_cache_locale(this,(locale *)(this + 0xd0));
  uVar2 = *(undefined8 *)(lVar3 + 0xd8);
  *(undefined8 *)(lVar3 + 0xd8) = 0;
  *(undefined8 *)(this + 0xd8) = uVar2;
  this[0xe0] = *(ios *)(lVar3 + 0xe0);
  iVar1 = *(ios *)(lVar3 + 0xe1);
  *(undefined8 *)(this + 0xe8) = 0;
  this[0xe1] = iVar1;
  return;
}


// ==== entry=00c1db20 name=FUN_00c1db20 size=209 ====

void FUN_00c1db20(undefined8 *param_1,long *param_2)

{
  ios_base *this;
  undefined1 uVar1;
  undefined8 uVar2;
  long lVar3;
  
  this = (ios_base *)(param_1 + 1);
  std::ios_base::ios_base(this);
  param_1[0x1c] = 0;
  *(undefined2 *)(param_1 + 0x1d) = 0;
  param_1[0x1e] = 0;
  param_1[0x1f] = 0;
  *param_1 = 0x11b4f18;
  param_1[1] = 0x11b4f40;
  lVar3 = *param_2;
  param_1[0x20] = 0;
  param_1[0x21] = 0;
  lVar3 = (long)param_2 + *(long *)(lVar3 + -0x18);
  FUN_00c71b00(this,lVar3);
                    /* try { // try from 00c1dba9 to 00c1dbad has its CatchHandler @ 00c1dbf1 */
  std::ios::_M_cache_locale((ios *)this,(locale *)(param_1 + 0x1b));
  uVar2 = *(undefined8 *)(lVar3 + 0xd8);
  *(undefined8 *)(lVar3 + 0xd8) = 0;
  param_1[0x1c] = uVar2;
  *(undefined1 *)(param_1 + 0x1d) = *(undefined1 *)(lVar3 + 0xe0);
  uVar1 = *(undefined1 *)(lVar3 + 0xe1);
  param_1[0x1e] = 0;
  *(undefined1 *)((long)param_1 + 0xe9) = uVar1;
  return;
}


// ==== entry=00c1dc20 name=FUN_00c1dc20 size=156 ====

long * FUN_00c1dc20(long *param_1,long *param_2)

{
  ios iVar1;
  undefined8 uVar2;
  ios *this;
  ios *this_00;
  
  this_00 = (ios *)(*(long *)(*param_1 + -0x18) + (long)param_1);
  this = (ios *)(*(long *)(*param_2 + -0x18) + (long)param_2);
  FUN_00c71c10(this_00,this);
  std::ios::_M_cache_locale(this_00,(locale *)(this_00 + 0xd0));
  std::ios::_M_cache_locale(this,(locale *)(this + 0xd0));
  uVar2 = *(undefined8 *)(this_00 + 0xd8);
  *(undefined8 *)(this_00 + 0xd8) = *(undefined8 *)(this + 0xd8);
  *(undefined8 *)(this + 0xd8) = uVar2;
  iVar1 = this_00[0xe0];
  this_00[0xe0] = this[0xe0];
  this[0xe0] = iVar1;
  iVar1 = this_00[0xe1];
  this_00[0xe1] = this[0xe1];
  this[0xe1] = iVar1;
  return param_1;
}


// ==== entry=00c1dcc0 name=FUN_00c1dcc0 size=151 ====

void FUN_00c1dcc0(long *param_1,long *param_2)

{
  ios iVar1;
  undefined8 uVar2;
  ios *this;
  ios *this_00;
  
  this_00 = (ios *)((long)param_1 + *(long *)(*param_1 + -0x18));
  this = (ios *)(*(long *)(*param_2 + -0x18) + (long)param_2);
  FUN_00c71c10(this_00,this);
  std::ios::_M_cache_locale(this_00,(locale *)(this_00 + 0xd0));
  std::ios::_M_cache_locale(this,(locale *)(this + 0xd0));
  uVar2 = *(undefined8 *)(this_00 + 0xd8);
  *(undefined8 *)(this_00 + 0xd8) = *(undefined8 *)(this + 0xd8);
  *(undefined8 *)(this + 0xd8) = uVar2;
  iVar1 = this_00[0xe0];
  this_00[0xe0] = this[0xe0];
  this[0xe0] = iVar1;
  iVar1 = this_00[0xe1];
  this_00[0xe1] = this[0xe1];
  this[0xe1] = iVar1;
  return;
}


// ==== entry=00c1dd60 orig=FUN_00c1dd60 size=101 name=sentry ====

/* std::ostream::sentry::sentry(std::ostream&) */

void __thiscall std::ostream::sentry::sentry(sentry *this,ostream *param_1)

{
  long lVar1;
  ios *piVar2;
  uint uVar3;
  
  lVar1 = *(long *)param_1;
  *(ostream **)(this + 8) = param_1;
  *this = (sentry)0x0;
  piVar2 = (ios *)(param_1 + *(long *)(lVar1 + -0x18));
  uVar3 = *(uint *)(piVar2 + 0x20);
  if (*(ostream **)(piVar2 + 0xd8) != (ostream *)0x0) {
    if (uVar3 != 0) goto LAB_00c1dd93;
    flush(*(ostream **)(piVar2 + 0xd8));
    piVar2 = (ios *)(param_1 + *(long *)(*(long *)param_1 + -0x18));
    uVar3 = *(uint *)(piVar2 + 0x20);
  }
  if (uVar3 == 0) {
    *this = (sentry)0x1;
    return;
  }
LAB_00c1dd93:
  ios::s_basic_ios__clear_c1bf70(piVar2,uVar3 | 4);
  return;
}


// ==== entry=00c1ddd0 orig=FUN_00c1ddd0 size=97 name=~sentry ====

/* std::ostream::sentry::~sentry() */

void __thiscall std::ostream::sentry::~sentry(sentry *this)

{
  long *plVar1;
  long lVar2;
  char cVar3;
  int iVar4;
  ios *piVar5;
  
  plVar1 = *(long **)(this + 8);
  lVar2 = *(long *)(*plVar1 + -0x18);
  if ((*(byte *)((long)plVar1 + lVar2 + 0x19) & 0x20) == 0) {
    return;
  }
  cVar3 = uncaught_exception();
  if ((cVar3 == '\0') && (plVar1 = *(long **)((long)plVar1 + lVar2 + 0xe8), plVar1 != (long *)0x0))
  {
    iVar4 = (**(code **)(*plVar1 + 0x30))();
    if (iVar4 == -1) {
      piVar5 = (ios *)((long)*(long **)(this + 8) + *(long *)(**(long **)(this + 8) + -0x18));
      ios::s_basic_ios__clear_c1bf70(piVar5,*(uint *)(piVar5 + 0x20) | 1);
      return;
    }
  }
  return;
}


// ==== entry=00c1de40 orig=FUN_00c1de40 size=188 name=operator<< ====

/* std::ostream::TEMPNAMEPLACEHOLDERVALUE(std::streambuf*) */

ostream * __thiscall std::ostream::operator<<(ostream *this,streambuf *param_1)

{
  long lVar1;
  uint uVar2;
  ios *piVar3;
  long in_FS_OFFSET;
  bool local_39;
  sentry local_38 [24];
  long local_20;
  
  local_20 = *(long *)(in_FS_OFFSET + 0x28);
  sentry::sentry(local_38,this);
  if (local_38[0] == (sentry)0x0) {
    if (param_1 != (streambuf *)0x0) goto LAB_00c1deb5;
    uVar2 = 1;
    piVar3 = (ios *)(this + *(long *)(*(long *)this + -0x18));
  }
  else {
    piVar3 = (ios *)(this + *(long *)(*(long *)this + -0x18));
    if (param_1 == (streambuf *)0x0) {
      uVar2 = 1;
    }
    else {
                    /* try { // try from 00c1de93 to 00c1de97 has its CatchHandler @ 00c1df05 */
      lVar1 = __copy_streambufs_eof<char,std::char_traits<char>>
                        (param_1,*(streambuf **)(piVar3 + 0xe8),&local_39);
      if (lVar1 != 0) goto LAB_00c1deb5;
      uVar2 = 4;
      piVar3 = (ios *)(this + *(long *)(*(long *)this + -0x18));
    }
  }
                    /* try { // try from 00c1dee8 to 00c1df32 has its CatchHandler @ 00c1df0a */
  ios::s_basic_ios__clear_c1bf70(piVar3,uVar2 | *(uint *)(piVar3 + 0x20));
LAB_00c1deb5:
  sentry::~sentry(local_38);
  if (local_20 == *(long *)(in_FS_OFFSET + 0x28)) {
    return this;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ==== entry=00c1df80 orig=FUN_00c1df80 size=162 name=put ====

/* std::ostream::put(char) */

ostream * __thiscall std::ostream::put(ostream *this,char param_1)

{
  long *plVar1;
  int iVar2;
  long in_FS_OFFSET;
  sentry local_38 [24];
  long local_20;
  
  local_20 = *(long *)(in_FS_OFFSET + 0x28);
  sentry::sentry(local_38,this);
  if (local_38[0] != (sentry)0x0) {
    plVar1 = *(long **)(this + *(long *)(*(long *)this + -0x18) + 0xe8);
    if ((char *)plVar1[5] < (char *)plVar1[6]) {
      *(char *)plVar1[5] = param_1;
      plVar1[5] = plVar1[5] + 1;
    }
    else {
                    /* try { // try from 00c1e007 to 00c1e009 has its CatchHandler @ 00c1e030 */
      iVar2 = (**(code **)(*plVar1 + 0x68))(plVar1,param_1);
      if (iVar2 == -1) {
                    /* try { // try from 00c1e01f to 00c1e023 has its CatchHandler @ 00c1e02b */
        ios::s_basic_ios__clear_c1bf70
                  ((ios *)(this + *(long *)(*(long *)this + -0x18)),
                   *(uint *)((ios *)(this + *(long *)(*(long *)this + -0x18)) + 0x20) | 1);
      }
    }
  }
  sentry::~sentry(local_38);
  if (local_20 == *(long *)(in_FS_OFFSET + 0x28)) {
    return this;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ==== entry=00c1e0b0 orig=FUN_00c1e0b0 size=153 name=write ====

/* std::ostream::write(char const*, long) */

ostream * __thiscall std::ostream::write(ostream *this,char *param_1,long param_2)

{
  long lVar1;
  long in_FS_OFFSET;
  sentry local_48 [24];
  long local_30;
  
  local_30 = *(long *)(in_FS_OFFSET + 0x28);
  sentry::sentry(local_48,this);
  if (local_48[0] != (sentry)0x0) {
                    /* try { // try from 00c1e0ff to 00c1e144 has its CatchHandler @ 00c1e14c */
    lVar1 = (**(code **)(**(long **)(this + *(long *)(*(long *)this + -0x18) + 0xe8) + 0x60))
                      (*(long **)(this + *(long *)(*(long *)this + -0x18) + 0xe8),param_1,param_2);
    if (param_2 != lVar1) {
      ios::s_basic_ios__clear_c1bf70
                ((ios *)(this + *(long *)(*(long *)this + -0x18)),
                 *(uint *)((ios *)(this + *(long *)(*(long *)this + -0x18)) + 0x20) | 1);
    }
  }
  sentry::~sentry(local_48);
  if (local_30 == *(long *)(in_FS_OFFSET + 0x28)) {
    return this;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ==== entry=00c1e1d0 orig=FUN_00c1e1d0 size=4 name=operator.cast.to.bool ====

/* std::ostream::sentry::operator bool() const */

bool __thiscall std::ostream::sentry::operator_cast_to_bool(sentry *this)

{
  return (bool)*this;
}


// ==== entry=00c1e1e0 orig=FUN_00c1e1e0 size=105 name=endl<char,std::char_traits<char>> ====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* std::ostream& std::endl<char, std::char_traits<char> >(std::ostream&) */

ostream * std::endl<char,std::char_traits<char>>(ostream *param_1)

{
  ctype<char> *this;
  ctype<char> cVar1;
  ostream *poVar2;
  
  this = *(ctype<char> **)(param_1 + *(long *)(*(long *)param_1 + -0x18) + 0xf0);
  if (this != (ctype<char> *)0x0) {
    if (this[0x38] == (ctype<char>)0x0) {
      ctype<char>::_M_widen_init(this);
      cVar1 = (ctype<char>)0xa;
      if (*(code **)(*(long *)this + 0x30) != FUN_00816ea8) {
        cVar1 = (ctype<char>)(**(code **)(*(long *)this + 0x30))(this);
      }
    }
    else {
      cVar1 = this[0x43];
    }
    poVar2 = (ostream *)ostream::put(param_1,(char)cVar1);
    poVar2 = (ostream *)ostream::flush(poVar2);
    return poVar2;
  }
                    /* WARNING: Subroutine does not return */
  __throw_bad_cast();
}


// ==== entry=00c1e250 orig=FUN_00c1e250 size=7 name=ends<char,std::char_traits<char>> ====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* std::ostream& std::ends<char, std::char_traits<char> >(std::ostream&) */

ostream * std::ends<char,std::char_traits<char>>(ostream *param_1)

{
  ostream *poVar1;
  
  poVar1 = (ostream *)ostream::put(param_1,'\0');
  return poVar1;
}


// ==== entry=00c1e260 orig=FUN_00c1e260 size=5 name=flush<char,std::char_traits<char>> ====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* std::ostream& std::flush<char, std::char_traits<char> >(std::ostream&) */

ostream * std::flush<char,std::char_traits<char>>(ostream *param_1)

{
  int iVar1;
  
  if (*(long **)(param_1 + *(long *)(*(long *)param_1 + -0x18) + 0xe8) != (long *)0x0) {
    iVar1 = (**(code **)(**(long **)(param_1 + *(long *)(*(long *)param_1 + -0x18) + 0xe8) + 0x30))
                      ();
    if (iVar1 == -1) {
      ios::s_basic_ios__clear_c1bf70
                ((ios *)(param_1 + *(long *)(*(long *)param_1 + -0x18)),
                 *(uint *)((ios *)(param_1 + *(long *)(*(long *)param_1 + -0x18)) + 0x20) | 1);
      return param_1;
    }
  }
  return param_1;
}


// ==== entry=00c1e270 orig=FUN_00c1e270 size=126 name=operator<< ====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* std::ostream& std::TEMPNAMEPLACEHOLDERVALUE(std::ostream&, std::_Setfill<char>) */

ostream * std::operator<<(ostream *param_1,ostream param_2)

{
  long lVar1;
  ctype<char> *this;
  
  lVar1 = *(long *)(*(long *)param_1 + -0x18);
  if (param_1[lVar1 + 0xe1] == (ostream)0x0) {
    this = *(ctype<char> **)(param_1 + lVar1 + 0xf0);
    if (this == (ctype<char> *)0x0) {
                    /* WARNING: Subroutine does not return */
      __throw_bad_cast();
    }
    if (this[0x38] == (ctype<char>)0x0) {
      ctype<char>::_M_widen_init(this);
      if (*(code **)(*(long *)this + 0x30) != FUN_00816ea8) {
        (**(code **)(*(long *)this + 0x30))(this,0x20);
      }
    }
    param_1[lVar1 + 0xe1] = (ostream)0x1;
  }
  param_1[lVar1 + 0xe0] = param_2;
  return param_1;
}


// ==== entry=00c1e300 orig=FUN_00c1e300 size=17 name=operator<< ====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* std::ostream& std::TEMPNAMEPLACEHOLDERVALUE(std::ostream&, std::_Setiosflags) */

ostream * std::operator<<(ostream *param_1,uint param_2)

{
  *(uint *)(param_1 + *(long *)(*(long *)param_1 + -0x18) + 0x18) =
       *(uint *)(param_1 + *(long *)(*(long *)param_1 + -0x18) + 0x18) | param_2;
  return param_1;
}


// ==== entry=00c1e320 orig=FUN_00c1e320 size=19 name=operator<< ====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* std::ostream& std::TEMPNAMEPLACEHOLDERVALUE(std::ostream&, std::_Resetiosflags) */

ostream * std::operator<<(ostream *param_1,uint param_2)

{
  *(uint *)(param_1 + *(long *)(*(long *)param_1 + -0x18) + 0x18) =
       *(uint *)(param_1 + *(long *)(*(long *)param_1 + -0x18) + 0x18) & ~param_2;
  return param_1;
}


// ==== entry=00c1e340 orig=FUN_00c1e340 size=56 name=operator<< ====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* std::ostream& std::TEMPNAMEPLACEHOLDERVALUE(std::ostream&, std::_Setbase) */

ostream * std::operator<<(ostream *param_1,int param_2)

{
  uint uVar1;
  
  uVar1 = 0x40;
  if ((param_2 != 8) && (uVar1 = 2, param_2 != 10)) {
    uVar1 = (uint)(param_2 == 0x10) << 3;
  }
  *(uint *)(param_1 + *(long *)(*(long *)param_1 + -0x18) + 0x18) =
       *(uint *)(param_1 + *(long *)(*(long *)param_1 + -0x18) + 0x18) & 0xffffffb5 | uVar1;
  return param_1;
}


// ==== entry=00c1e380 orig=FUN_00c1e380 size=19 name=operator<< ====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* std::ostream& std::TEMPNAMEPLACEHOLDERVALUE(std::ostream&, std::_Setprecision) */

ostream * std::operator<<(ostream *param_1,int param_2)

{
  *(long *)(param_1 + *(long *)(*(long *)param_1 + -0x18) + 8) = (long)param_2;
  return param_1;
}


// ==== entry=00c1e3a0 orig=FUN_00c1e3a0 size=19 name=operator<< ====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* std::ostream& std::TEMPNAMEPLACEHOLDERVALUE(std::ostream&, std::_Setw) */

ostream * std::operator<<(ostream *param_1,int param_2)

{
  *(long *)(param_1 + *(long *)(*(long *)param_1 + -0x18) + 0x10) = (long)param_2;
  return param_1;
}


// ==== entry=00c1e3c0 orig=FUN_00c1e3c0 size=817 name=__ostream_insert<char,std::char_traits<char>> ====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* std::ostream& std::__ostream_insert<char, std::char_traits<char> >(std::ostream&, char const*,
   long) */

ostream * std::__ostream_insert<char,std::char_traits<char>>
                    (ostream *param_1,char *param_2,long param_3)

{
  uint uVar1;
  long *plVar2;
  ctype<char> *pcVar3;
  ios iVar4;
  int iVar5;
  long lVar6;
  long lVar7;
  ios *piVar8;
  long lVar9;
  long in_FS_OFFSET;
  sentry local_58 [24];
  long local_40;
  
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  ostream::sentry::sentry(local_58,param_1);
  if (local_58[0] != (sentry)0x0) {
    lVar6 = *(long *)(*(long *)param_1 + -0x18);
    piVar8 = (ios *)(param_1 + lVar6);
    lVar9 = *(long *)(piVar8 + 0x10);
    if (param_3 < lVar9) {
      uVar1 = *(uint *)(piVar8 + 0x18);
      if ((uVar1 & 0xb0) == 0x20) {
LAB_00c1e4af:
        iVar5 = *(int *)(piVar8 + 0x20);
      }
      else {
        lVar7 = lVar9 - param_3;
        if (piVar8[0xe1] == (ios)0x0) {
          pcVar3 = *(ctype<char> **)(piVar8 + 0xf0);
          if (pcVar3 == (ctype<char> *)0x0) {
                    /* WARNING: Subroutine does not return */
            __throw_bad_cast();
          }
          if (pcVar3[0x38] == (ctype<char>)0x0) {
            ctype<char>::_M_widen_init(pcVar3);
            iVar4 = (ios)0x20;
            if (*(code **)(*(long *)pcVar3 + 0x30) != FUN_00816ea8) {
              iVar4 = (ios)(**(code **)(*(long *)pcVar3 + 0x30))(pcVar3,0x20);
            }
          }
          else {
            iVar4 = *(ios *)(pcVar3 + 0x59);
          }
          piVar8[0xe0] = iVar4;
          lVar6 = *(long *)param_1;
          piVar8[0xe1] = (ios)0x1;
          lVar6 = *(long *)(lVar6 + -0x18);
        }
        else {
          iVar4 = piVar8[0xe0];
        }
        do {
          plVar2 = *(long **)(param_1 + lVar6 + 0xe8);
          if ((ios *)plVar2[5] < (ios *)plVar2[6]) {
            *(ios *)plVar2[5] = iVar4;
            plVar2[5] = plVar2[5] + 1;
          }
          else {
                    /* try { // try from 00c1e488 to 00c1e714 has its CatchHandler @ 00c1e715 */
            iVar5 = (**(code **)(*plVar2 + 0x68))(plVar2,iVar4);
            if (iVar5 == -1) {
              ios::s_basic_ios__clear_c1bf70
                        ((ios *)(param_1 + *(long *)(*(long *)param_1 + -0x18)),
                         *(uint *)((ios *)(param_1 + *(long *)(*(long *)param_1 + -0x18)) + 0x20) |
                         1);
              piVar8 = (ios *)(param_1 + *(long *)(*(long *)param_1 + -0x18));
              goto LAB_00c1e4af;
            }
          }
          lVar6 = *(long *)(*(long *)param_1 + -0x18);
          lVar7 = lVar7 + -1;
        } while (lVar7 != 0);
        piVar8 = (ios *)(param_1 + lVar6);
        iVar5 = *(int *)(piVar8 + 0x20);
      }
      if (iVar5 == 0) {
        lVar7 = (**(code **)(**(long **)(piVar8 + 0xe8) + 0x60))
                          (*(long **)(piVar8 + 0xe8),param_2,param_3);
        lVar6 = *(long *)(*(long *)param_1 + -0x18);
        piVar8 = (ios *)(param_1 + lVar6);
        if (param_3 != lVar7) {
          ios::s_basic_ios__clear_c1bf70(piVar8,*(uint *)(piVar8 + 0x20) | 1);
          lVar6 = *(long *)(*(long *)param_1 + -0x18);
          piVar8 = (ios *)(param_1 + lVar6);
        }
        if (((uVar1 & 0xb0) == 0x20) && (*(int *)(piVar8 + 0x20) == 0)) {
          lVar9 = lVar9 - param_3;
          if (piVar8[0xe1] == (ios)0x0) {
            pcVar3 = *(ctype<char> **)(piVar8 + 0xf0);
            if (pcVar3 == (ctype<char> *)0x0) {
                    /* WARNING: Subroutine does not return */
              __throw_bad_cast();
            }
            if (pcVar3[0x38] == (ctype<char>)0x0) {
              ctype<char>::_M_widen_init(pcVar3);
              iVar4 = (ios)0x20;
              if (*(code **)(*(long *)pcVar3 + 0x30) != FUN_00816ea8) {
                iVar4 = (ios)(**(code **)(*(long *)pcVar3 + 0x30))(pcVar3,0x20);
              }
            }
            else {
              iVar4 = *(ios *)(pcVar3 + 0x59);
            }
            piVar8[0xe0] = iVar4;
            lVar6 = *(long *)param_1;
            piVar8[0xe1] = (ios)0x1;
            lVar6 = *(long *)(lVar6 + -0x18);
          }
          else {
            iVar4 = piVar8[0xe0];
          }
          do {
            plVar2 = *(long **)(param_1 + lVar6 + 0xe8);
            if ((ios *)plVar2[5] < (ios *)plVar2[6]) {
              *(ios *)plVar2[5] = iVar4;
              plVar2[5] = plVar2[5] + 1;
            }
            else {
              iVar5 = (**(code **)(*plVar2 + 0x68))(plVar2,iVar4);
              if (iVar5 == -1) {
                ios::s_basic_ios__clear_c1bf70
                          ((ios *)(param_1 + *(long *)(*(long *)param_1 + -0x18)),
                           *(uint *)((ios *)(param_1 + *(long *)(*(long *)param_1 + -0x18)) + 0x20)
                           | 1);
                goto LAB_00c1e521;
              }
            }
            lVar6 = *(long *)(*(long *)param_1 + -0x18);
            lVar9 = lVar9 + -1;
          } while (lVar9 != 0);
          piVar8 = (ios *)(param_1 + lVar6);
        }
      }
    }
    else {
      lVar9 = (**(code **)(**(long **)(piVar8 + 0xe8) + 0x60))
                        (*(long **)(piVar8 + 0xe8),param_2,param_3);
      piVar8 = (ios *)(param_1 + *(long *)(*(long *)param_1 + -0x18));
      if (param_3 != lVar9) {
        ios::s_basic_ios__clear_c1bf70(piVar8,*(uint *)(piVar8 + 0x20) | 1);
LAB_00c1e521:
        *(undefined8 *)(param_1 + *(long *)(*(long *)param_1 + -0x18) + 0x10) = 0;
        goto LAB_00c1e4c2;
      }
    }
    *(undefined8 *)(piVar8 + 0x10) = 0;
  }
LAB_00c1e4c2:
  ostream::sentry::~sentry(local_58);
  if (local_40 == *(long *)(in_FS_OFFSET + 0x28)) {
    return param_1;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ==== entry=00c1e790 orig=FUN_00c1e790 size=29 name=operator<< ====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* std::ostream& std::TEMPNAMEPLACEHOLDERVALUE(std::ostream&, char) */

ostream * std::operator<<(ostream *param_1,char param_2)

{
  ostream *poVar1;
  char local_c [12];
  
  local_c[0] = param_2;
  poVar1 = __ostream_insert<char,std::char_traits<char>>(param_1,local_c,1);
  return poVar1;
}


// ==== entry=00c1e7b0 orig=FUN_00c1e7b0 size=66 name=operator<< ====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* std::ostream& std::TEMPNAMEPLACEHOLDERVALUE(std::ostream&, unsigned char) */

ostream * std::operator<<(ostream *param_1,uchar param_2)

{
  ostream *poVar1;
  long in_FS_OFFSET;
  uchar local_11;
  long local_10;
  
  local_10 = *(long *)(in_FS_OFFSET + 0x28);
  local_11 = param_2;
  poVar1 = __ostream_insert<char,std::char_traits<char>>(param_1,(char *)&local_11,1);
  if (local_10 == *(long *)(in_FS_OFFSET + 0x28)) {
    return poVar1;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ==== entry=00c1e800 orig=FUN_00c1e800 size=66 name=operator<< ====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* std::ostream& std::TEMPNAMEPLACEHOLDERVALUE(std::ostream&, signed char) */

ostream * std::operator<<(ostream *param_1,char param_2)

{
  ostream *poVar1;
  long in_FS_OFFSET;
  char local_11;
  long local_10;
  
  local_10 = *(long *)(in_FS_OFFSET + 0x28);
  local_11 = param_2;
  poVar1 = __ostream_insert<char,std::char_traits<char>>(param_1,&local_11,1);
  if (local_10 == *(long *)(in_FS_OFFSET + 0x28)) {
    return poVar1;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ==== entry=00c1e850 orig=FUN_00c1e850 size=80 name=operator<< ====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* std::ostream& std::TEMPNAMEPLACEHOLDERVALUE(std::ostream&, char const*) */

ostream * std::operator<<(ostream *param_1,char *param_2)

{
  size_t sVar1;
  
  if (param_2 != (char *)0x0) {
    sVar1 = strlen(param_2);
    __ostream_insert<char,std::char_traits<char>>(param_1,param_2,sVar1);
    return param_1;
  }
  ios::s_basic_ios__clear_c1bf70
            ((ios *)(param_1 + *(long *)(*(long *)param_1 + -0x18)),
             *(uint *)((ios *)(param_1 + *(long *)(*(long *)param_1 + -0x18)) + 0x20) | 1);
  return param_1;
}


// ==== entry=00c1e8b0 orig=FUN_00c1e8b0 size=80 name=operator<< ====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* std::ostream& std::TEMPNAMEPLACEHOLDERVALUE(std::ostream&, unsigned char const*) */

ostream * std::operator<<(ostream *param_1,uchar *param_2)

{
  size_t sVar1;
  
  if (param_2 != (uchar *)0x0) {
    sVar1 = strlen((char *)param_2);
    __ostream_insert<char,std::char_traits<char>>(param_1,(char *)param_2,sVar1);
    return param_1;
  }
  ios::s_basic_ios__clear_c1bf70
            ((ios *)(param_1 + *(long *)(*(long *)param_1 + -0x18)),
             *(uint *)((ios *)(param_1 + *(long *)(*(long *)param_1 + -0x18)) + 0x20) | 1);
  return param_1;
}


// ==== entry=00c1e910 orig=FUN_00c1e910 size=80 name=operator<< ====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* std::ostream& std::TEMPNAMEPLACEHOLDERVALUE(std::ostream&, signed char const*) */

ostream * std::operator<<(ostream *param_1,signed *param_2)

{
  size_t sVar1;
  
  if (param_2 != (signed *)0x0) {
    sVar1 = strlen(param_2);
    __ostream_insert<char,std::char_traits<char>>(param_1,param_2,sVar1);
    return param_1;
  }
  ios::s_basic_ios__clear_c1bf70
            ((ios *)(param_1 + *(long *)(*(long *)param_1 + -0x18)),
             *(uint *)((ios *)(param_1 + *(long *)(*(long *)param_1 + -0x18)) + 0x20) | 1);
  return param_1;
}


// ==== entry=00c1e970 orig=FUN_00c1e970 size=325 name=_M_insert<long> ====

/* std::ostream& std::ostream::_M_insert<long>(long) */

ostream * __thiscall std::ostream::_M_insert<long>(ostream *this,long param_1)

{
  long *plVar1;
  ctype<char> *this_00;
  long lVar2;
  ctype<char> cVar3;
  char extraout_DL;
  ostream *poVar4;
  int iVar5;
  long in_FS_OFFSET;
  sentry local_58 [24];
  long local_40;
  
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  sentry::sentry(local_58,this);
  if (local_58[0] != (sentry)0x0) {
    poVar4 = this + *(long *)(*(long *)this + -0x18);
    plVar1 = *(long **)(poVar4 + 0xf8);
    if (plVar1 == (long *)0x0) {
                    /* WARNING: Subroutine does not return */
      __throw_bad_cast();
    }
    if (poVar4[0xe1] == (ostream)0x0) {
      this_00 = *(ctype<char> **)(poVar4 + 0xf0);
      if (this_00 == (ctype<char> *)0x0) {
                    /* WARNING: Subroutine does not return */
        __throw_bad_cast();
      }
      if (this_00[0x38] == (ctype<char>)0x0) {
                    /* try { // try from 00c1ea83 to 00c1eac1 has its CatchHandler @ 00c1eac7 */
        ctype<char>::_M_widen_init(this_00);
        iVar5 = 0x20;
        cVar3 = (ctype<char>)0x20;
        if (*(code **)(*(long *)this_00 + 0x30) != FUN_00816ea8) {
          cVar3 = (ctype<char>)(**(code **)(*(long *)this_00 + 0x30))(this_00,0x20);
          iVar5 = (int)(char)cVar3;
        }
      }
      else {
        cVar3 = this_00[0x59];
        iVar5 = (int)(char)cVar3;
      }
      *(ctype<char> *)(poVar4 + 0xe0) = cVar3;
      lVar2 = *(long *)this;
      poVar4[0xe1] = (ostream)0x1;
      poVar4 = this + *(long *)(lVar2 + -0x18);
    }
    else {
      iVar5 = (int)(char)poVar4[0xe0];
    }
                    /* try { // try from 00c1e9f2 to 00c1e9f4 has its CatchHandler @ 00c1eac7 */
    (**(code **)(*plVar1 + 0x18))
              (plVar1,*(long *)(poVar4 + 0xe8),*(long *)(poVar4 + 0xe8) == 0,poVar4,iVar5,param_1);
    if (extraout_DL != '\0') {
                    /* try { // try from 00c1ea09 to 00c1ea0d has its CatchHandler @ 00c1eac2 */
      ios::s_basic_ios__clear_c1bf70
                ((ios *)(this + *(long *)(*(long *)this + -0x18)),
                 *(uint *)((ios *)(this + *(long *)(*(long *)this + -0x18)) + 0x20) | 1);
    }
  }
  sentry::~sentry(local_58);
  if (local_40 == *(long *)(in_FS_OFFSET + 0x28)) {
    return this;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ==== entry=00c1eb40 orig=FUN_00c1eb40 size=5 name=operator<< ====

/* std::ostream::TEMPNAMEPLACEHOLDERVALUE(long) */

ostream * __thiscall std::ostream::operator<<(ostream *this,long param_1)

{
  long *plVar1;
  ctype<char> *this_00;
  long lVar2;
  ctype<char> cVar3;
  char extraout_DL;
  ostream *poVar4;
  int iVar5;
  long in_FS_OFFSET;
  sentry asStack_58 [24];
  long lStack_40;
  
  lStack_40 = *(long *)(in_FS_OFFSET + 0x28);
  sentry::sentry(asStack_58,this);
  if (asStack_58[0] != (sentry)0x0) {
    poVar4 = this + *(long *)(*(long *)this + -0x18);
    plVar1 = *(long **)(poVar4 + 0xf8);
    if (plVar1 == (long *)0x0) {
                    /* WARNING: Subroutine does not return */
      __throw_bad_cast();
    }
    if (poVar4[0xe1] == (ostream)0x0) {
      this_00 = *(ctype<char> **)(poVar4 + 0xf0);
      if (this_00 == (ctype<char> *)0x0) {
                    /* WARNING: Subroutine does not return */
        __throw_bad_cast();
      }
      if (this_00[0x38] == (ctype<char>)0x0) {
        ctype<char>::_M_widen_init(this_00);
        iVar5 = 0x20;
        cVar3 = (ctype<char>)0x20;
        if (*(code **)(*(long *)this_00 + 0x30) != FUN_00816ea8) {
          cVar3 = (ctype<char>)(**(code **)(*(long *)this_00 + 0x30))(this_00,0x20);
          iVar5 = (int)(char)cVar3;
        }
      }
      else {
        cVar3 = this_00[0x59];
        iVar5 = (int)(char)cVar3;
      }
      *(ctype<char> *)(poVar4 + 0xe0) = cVar3;
      lVar2 = *(long *)this;
      poVar4[0xe1] = (ostream)0x1;
      poVar4 = this + *(long *)(lVar2 + -0x18);
    }
    else {
      iVar5 = (int)(char)poVar4[0xe0];
    }
    (**(code **)(*plVar1 + 0x18))
              (plVar1,*(long *)(poVar4 + 0xe8),*(long *)(poVar4 + 0xe8) == 0,poVar4,iVar5,param_1);
    if (extraout_DL != '\0') {
      ios::s_basic_ios__clear_c1bf70
                ((ios *)(this + *(long *)(*(long *)this + -0x18)),
                 *(uint *)((ios *)(this + *(long *)(*(long *)this + -0x18)) + 0x20) | 1);
    }
  }
  sentry::~sentry(asStack_58);
  if (lStack_40 == *(long *)(in_FS_OFFSET + 0x28)) {
    return this;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ==== entry=00c1eb50 orig=FUN_00c1eb50 size=41 name=operator<< ====

/* std::ostream::TEMPNAMEPLACEHOLDERVALUE(short) */

void __thiscall std::ostream::operator<<(ostream *this,short param_1)

{
  if (((*(uint *)(this + *(long *)(*(long *)this + -0x18) + 0x18) & 0x4a) != 0x40) &&
     ((*(uint *)(this + *(long *)(*(long *)this + -0x18) + 0x18) & 0x4a) != 8)) {
    _M_insert<long>(this,(long)param_1);
    return;
  }
  _M_insert<long>(this,(ulong)(ushort)param_1);
  return;
}


// ==== entry=00c1eb80 orig=FUN_00c1eb80 size=39 name=operator<< ====

/* std::ostream::TEMPNAMEPLACEHOLDERVALUE(int) */

void __thiscall std::ostream::operator<<(ostream *this,int param_1)

{
  if (((*(uint *)(this + *(long *)(*(long *)this + -0x18) + 0x18) & 0x4a) != 0x40) &&
     ((*(uint *)(this + *(long *)(*(long *)this + -0x18) + 0x18) & 0x4a) != 8)) {
    _M_insert<long>(this,(long)param_1);
    return;
  }
  _M_insert<long>(this,(ulong)(uint)param_1);
  return;
}


// ==== entry=00c1ebb0 orig=FUN_00c1ebb0 size=325 name=_M_insert<unsigned_long> ====

/* std::ostream& std::ostream::_M_insert<unsigned long>(unsigned long) */

ostream * __thiscall std::ostream::_M_insert<unsigned_long>(ostream *this,ulong param_1)

{
  long *plVar1;
  ctype<char> *this_00;
  long lVar2;
  ctype<char> cVar3;
  char extraout_DL;
  ostream *poVar4;
  int iVar5;
  long in_FS_OFFSET;
  sentry local_58 [24];
  long local_40;
  
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  sentry::sentry(local_58,this);
  if (local_58[0] != (sentry)0x0) {
    poVar4 = this + *(long *)(*(long *)this + -0x18);
    plVar1 = *(long **)(poVar4 + 0xf8);
    if (plVar1 == (long *)0x0) {
                    /* WARNING: Subroutine does not return */
      __throw_bad_cast();
    }
    if (poVar4[0xe1] == (ostream)0x0) {
      this_00 = *(ctype<char> **)(poVar4 + 0xf0);
      if (this_00 == (ctype<char> *)0x0) {
                    /* WARNING: Subroutine does not return */
        __throw_bad_cast();
      }
      if (this_00[0x38] == (ctype<char>)0x0) {
                    /* try { // try from 00c1ecc3 to 00c1ed01 has its CatchHandler @ 00c1ed07 */
        ctype<char>::_M_widen_init(this_00);
        iVar5 = 0x20;
        cVar3 = (ctype<char>)0x20;
        if (*(code **)(*(long *)this_00 + 0x30) != FUN_00816ea8) {
          cVar3 = (ctype<char>)(**(code **)(*(long *)this_00 + 0x30))(this_00,0x20);
          iVar5 = (int)(char)cVar3;
        }
      }
      else {
        cVar3 = this_00[0x59];
        iVar5 = (int)(char)cVar3;
      }
      *(ctype<char> *)(poVar4 + 0xe0) = cVar3;
      lVar2 = *(long *)this;
      poVar4[0xe1] = (ostream)0x1;
      poVar4 = this + *(long *)(lVar2 + -0x18);
    }
    else {
      iVar5 = (int)(char)poVar4[0xe0];
    }
                    /* try { // try from 00c1ec32 to 00c1ec34 has its CatchHandler @ 00c1ed07 */
    (**(code **)(*plVar1 + 0x20))
              (plVar1,*(long *)(poVar4 + 0xe8),*(long *)(poVar4 + 0xe8) == 0,poVar4,iVar5,param_1);
    if (extraout_DL != '\0') {
                    /* try { // try from 00c1ec49 to 00c1ec4d has its CatchHandler @ 00c1ed02 */
      ios::s_basic_ios__clear_c1bf70
                ((ios *)(this + *(long *)(*(long *)this + -0x18)),
                 *(uint *)((ios *)(this + *(long *)(*(long *)this + -0x18)) + 0x20) | 1);
    }
  }
  sentry::~sentry(local_58);
  if (local_40 == *(long *)(in_FS_OFFSET + 0x28)) {
    return this;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ==== entry=00c1ed80 orig=FUN_00c1ed80 size=5 name=operator<< ====

/* std::ostream::TEMPNAMEPLACEHOLDERVALUE(unsigned long) */

ostream * __thiscall std::ostream::operator<<(ostream *this,ulong param_1)

{
  long *plVar1;
  ctype<char> *this_00;
  long lVar2;
  ctype<char> cVar3;
  char extraout_DL;
  ostream *poVar4;
  int iVar5;
  long in_FS_OFFSET;
  sentry asStack_58 [24];
  long lStack_40;
  
  lStack_40 = *(long *)(in_FS_OFFSET + 0x28);
  sentry::sentry(asStack_58,this);
  if (asStack_58[0] != (sentry)0x0) {
    poVar4 = this + *(long *)(*(long *)this + -0x18);
    plVar1 = *(long **)(poVar4 + 0xf8);
    if (plVar1 == (long *)0x0) {
                    /* WARNING: Subroutine does not return */
      __throw_bad_cast();
    }
    if (poVar4[0xe1] == (ostream)0x0) {
      this_00 = *(ctype<char> **)(poVar4 + 0xf0);
      if (this_00 == (ctype<char> *)0x0) {
                    /* WARNING: Subroutine does not return */
        __throw_bad_cast();
      }
      if (this_00[0x38] == (ctype<char>)0x0) {
        ctype<char>::_M_widen_init(this_00);
        iVar5 = 0x20;
        cVar3 = (ctype<char>)0x20;
        if (*(code **)(*(long *)this_00 + 0x30) != FUN_00816ea8) {
          cVar3 = (ctype<char>)(**(code **)(*(long *)this_00 + 0x30))(this_00,0x20);
          iVar5 = (int)(char)cVar3;
        }
      }
      else {
        cVar3 = this_00[0x59];
        iVar5 = (int)(char)cVar3;
      }
      *(ctype<char> *)(poVar4 + 0xe0) = cVar3;
      lVar2 = *(long *)this;
      poVar4[0xe1] = (ostream)0x1;
      poVar4 = this + *(long *)(lVar2 + -0x18);
    }
    else {
      iVar5 = (int)(char)poVar4[0xe0];
    }
    (**(code **)(*plVar1 + 0x20))
              (plVar1,*(long *)(poVar4 + 0xe8),*(long *)(poVar4 + 0xe8) == 0,poVar4,iVar5,param_1);
    if (extraout_DL != '\0') {
      ios::s_basic_ios__clear_c1bf70
                ((ios *)(this + *(long *)(*(long *)this + -0x18)),
                 *(uint *)((ios *)(this + *(long *)(*(long *)this + -0x18)) + 0x20) | 1);
    }
  }
  sentry::~sentry(asStack_58);
  if (lStack_40 == *(long *)(in_FS_OFFSET + 0x28)) {
    return this;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ==== entry=00c1ed90 orig=FUN_00c1ed90 size=8 name=operator<< ====

/* std::ostream::TEMPNAMEPLACEHOLDERVALUE(unsigned short) */

void __thiscall std::ostream::operator<<(ostream *this,ushort param_1)

{
  _M_insert<unsigned_long>(this,(ulong)param_1);
  return;
}


// ==== entry=00c1eda0 orig=FUN_00c1eda0 size=7 name=operator<< ====

/* std::ostream::TEMPNAMEPLACEHOLDERVALUE(unsigned int) */

void __thiscall std::ostream::operator<<(ostream *this,uint param_1)

{
  _M_insert<unsigned_long>(this,(ulong)param_1);
  return;
}


// ==== entry=00c1edb0 orig=FUN_00c1edb0 size=328 name=_M_insert<bool> ====

/* std::ostream& std::ostream::_M_insert<bool>(bool) */

ostream * __thiscall std::ostream::_M_insert<bool>(ostream *this,bool param_1)

{
  long *plVar1;
  ctype<char> *this_00;
  long lVar2;
  ctype<char> cVar3;
  char extraout_DL;
  ostream *poVar4;
  int iVar5;
  long in_FS_OFFSET;
  sentry local_58 [24];
  long local_40;
  
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  sentry::sentry(local_58,this);
  if (local_58[0] != (sentry)0x0) {
    poVar4 = this + *(long *)(*(long *)this + -0x18);
    plVar1 = *(long **)(poVar4 + 0xf8);
    if (plVar1 == (long *)0x0) {
                    /* WARNING: Subroutine does not return */
      __throw_bad_cast();
    }
    if (poVar4[0xe1] == (ostream)0x0) {
      this_00 = *(ctype<char> **)(poVar4 + 0xf0);
      if (this_00 == (ctype<char> *)0x0) {
                    /* WARNING: Subroutine does not return */
        __throw_bad_cast();
      }
      if (this_00[0x38] == (ctype<char>)0x0) {
                    /* try { // try from 00c1eec3 to 00c1ef01 has its CatchHandler @ 00c1ef07 */
        ctype<char>::_M_widen_init(this_00);
        iVar5 = 0x20;
        cVar3 = (ctype<char>)0x20;
        if (*(code **)(*(long *)this_00 + 0x30) != FUN_00816ea8) {
          cVar3 = (ctype<char>)(**(code **)(*(long *)this_00 + 0x30))(this_00,0x20);
          iVar5 = (int)(char)cVar3;
        }
      }
      else {
        cVar3 = this_00[0x59];
        iVar5 = (int)(char)cVar3;
      }
      *(ctype<char> *)(poVar4 + 0xe0) = cVar3;
      lVar2 = *(long *)this;
      poVar4[0xe1] = (ostream)0x1;
      poVar4 = this + *(long *)(lVar2 + -0x18);
    }
    else {
      iVar5 = (int)(char)poVar4[0xe0];
    }
                    /* try { // try from 00c1ee35 to 00c1ee37 has its CatchHandler @ 00c1ef07 */
    (**(code **)(*plVar1 + 0x10))
              (plVar1,*(long *)(poVar4 + 0xe8),*(long *)(poVar4 + 0xe8) == 0,poVar4,iVar5,param_1);
    if (extraout_DL != '\0') {
                    /* try { // try from 00c1ee4c to 00c1ee50 has its CatchHandler @ 00c1ef02 */
      ios::s_basic_ios__clear_c1bf70
                ((ios *)(this + *(long *)(*(long *)this + -0x18)),
                 *(uint *)((ios *)(this + *(long *)(*(long *)this + -0x18)) + 0x20) | 1);
    }
  }
  sentry::~sentry(local_58);
  if (local_40 == *(long *)(in_FS_OFFSET + 0x28)) {
    return this;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ==== entry=00c1ef80 orig=FUN_00c1ef80 size=9 name=operator<< ====

/* std::ostream::TEMPNAMEPLACEHOLDERVALUE(bool) */

void __thiscall std::ostream::operator<<(ostream *this,bool param_1)

{
  _M_insert<bool>(this,param_1);
  return;
}


// ==== entry=00c1ef90 orig=FUN_00c1ef90 size=325 name=_M_insert<long_long> ====

/* std::ostream& std::ostream::_M_insert<long long>(long long) */

ostream * __thiscall std::ostream::_M_insert<long_long>(ostream *this,longlong param_1)

{
  long *plVar1;
  ctype<char> *this_00;
  long lVar2;
  ctype<char> cVar3;
  char extraout_DL;
  ostream *poVar4;
  int iVar5;
  long in_FS_OFFSET;
  sentry local_58 [24];
  long local_40;
  
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  sentry::sentry(local_58,this);
  if (local_58[0] != (sentry)0x0) {
    poVar4 = this + *(long *)(*(long *)this + -0x18);
    plVar1 = *(long **)(poVar4 + 0xf8);
    if (plVar1 == (long *)0x0) {
                    /* WARNING: Subroutine does not return */
      __throw_bad_cast();
    }
    if (poVar4[0xe1] == (ostream)0x0) {
      this_00 = *(ctype<char> **)(poVar4 + 0xf0);
      if (this_00 == (ctype<char> *)0x0) {
                    /* WARNING: Subroutine does not return */
        __throw_bad_cast();
      }
      if (this_00[0x38] == (ctype<char>)0x0) {
                    /* try { // try from 00c1f0a3 to 00c1f0e1 has its CatchHandler @ 00c1f0e7 */
        ctype<char>::_M_widen_init(this_00);
        iVar5 = 0x20;
        cVar3 = (ctype<char>)0x20;
        if (*(code **)(*(long *)this_00 + 0x30) != FUN_00816ea8) {
          cVar3 = (ctype<char>)(**(code **)(*(long *)this_00 + 0x30))(this_00,0x20);
          iVar5 = (int)(char)cVar3;
        }
      }
      else {
        cVar3 = this_00[0x59];
        iVar5 = (int)(char)cVar3;
      }
      *(ctype<char> *)(poVar4 + 0xe0) = cVar3;
      lVar2 = *(long *)this;
      poVar4[0xe1] = (ostream)0x1;
      poVar4 = this + *(long *)(lVar2 + -0x18);
    }
    else {
      iVar5 = (int)(char)poVar4[0xe0];
    }
                    /* try { // try from 00c1f012 to 00c1f014 has its CatchHandler @ 00c1f0e7 */
    (**(code **)(*plVar1 + 0x28))
              (plVar1,*(long *)(poVar4 + 0xe8),*(long *)(poVar4 + 0xe8) == 0,poVar4,iVar5,param_1);
    if (extraout_DL != '\0') {
                    /* try { // try from 00c1f029 to 00c1f02d has its CatchHandler @ 00c1f0e2 */
      ios::s_basic_ios__clear_c1bf70
                ((ios *)(this + *(long *)(*(long *)this + -0x18)),
                 *(uint *)((ios *)(this + *(long *)(*(long *)this + -0x18)) + 0x20) | 1);
    }
  }
  sentry::~sentry(local_58);
  if (local_40 == *(long *)(in_FS_OFFSET + 0x28)) {
    return this;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ==== entry=00c1f160 orig=FUN_00c1f160 size=5 name=operator<< ====

/* std::ostream::TEMPNAMEPLACEHOLDERVALUE(long long) */

ostream * __thiscall std::ostream::operator<<(ostream *this,longlong param_1)

{
  long *plVar1;
  ctype<char> *this_00;
  long lVar2;
  ctype<char> cVar3;
  char extraout_DL;
  ostream *poVar4;
  int iVar5;
  long in_FS_OFFSET;
  sentry asStack_58 [24];
  long lStack_40;
  
  lStack_40 = *(long *)(in_FS_OFFSET + 0x28);
  sentry::sentry(asStack_58,this);
  if (asStack_58[0] != (sentry)0x0) {
    poVar4 = this + *(long *)(*(long *)this + -0x18);
    plVar1 = *(long **)(poVar4 + 0xf8);
    if (plVar1 == (long *)0x0) {
                    /* WARNING: Subroutine does not return */
      __throw_bad_cast();
    }
    if (poVar4[0xe1] == (ostream)0x0) {
      this_00 = *(ctype<char> **)(poVar4 + 0xf0);
      if (this_00 == (ctype<char> *)0x0) {
                    /* WARNING: Subroutine does not return */
        __throw_bad_cast();
      }
      if (this_00[0x38] == (ctype<char>)0x0) {
        ctype<char>::_M_widen_init(this_00);
        iVar5 = 0x20;
        cVar3 = (ctype<char>)0x20;
        if (*(code **)(*(long *)this_00 + 0x30) != FUN_00816ea8) {
          cVar3 = (ctype<char>)(**(code **)(*(long *)this_00 + 0x30))(this_00,0x20);
          iVar5 = (int)(char)cVar3;
        }
      }
      else {
        cVar3 = this_00[0x59];
        iVar5 = (int)(char)cVar3;
      }
      *(ctype<char> *)(poVar4 + 0xe0) = cVar3;
      lVar2 = *(long *)this;
      poVar4[0xe1] = (ostream)0x1;
      poVar4 = this + *(long *)(lVar2 + -0x18);
    }
    else {
      iVar5 = (int)(char)poVar4[0xe0];
    }
    (**(code **)(*plVar1 + 0x28))
              (plVar1,*(long *)(poVar4 + 0xe8),*(long *)(poVar4 + 0xe8) == 0,poVar4,iVar5,param_1);
    if (extraout_DL != '\0') {
      ios::s_basic_ios__clear_c1bf70
                ((ios *)(this + *(long *)(*(long *)this + -0x18)),
                 *(uint *)((ios *)(this + *(long *)(*(long *)this + -0x18)) + 0x20) | 1);
    }
  }
  sentry::~sentry(asStack_58);
  if (lStack_40 == *(long *)(in_FS_OFFSET + 0x28)) {
    return this;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ==== entry=00c1f170 orig=FUN_00c1f170 size=325 name=_M_insert<unsigned_long_long> ====

/* std::ostream& std::ostream::_M_insert<unsigned long long>(unsigned long long) */

ostream * __thiscall std::ostream::_M_insert<unsigned_long_long>(ostream *this,ulonglong param_1)

{
  long *plVar1;
  ctype<char> *this_00;
  long lVar2;
  ctype<char> cVar3;
  char extraout_DL;
  ostream *poVar4;
  int iVar5;
  long in_FS_OFFSET;
  sentry local_58 [24];
  long local_40;
  
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  sentry::sentry(local_58,this);
  if (local_58[0] != (sentry)0x0) {
    poVar4 = this + *(long *)(*(long *)this + -0x18);
    plVar1 = *(long **)(poVar4 + 0xf8);
    if (plVar1 == (long *)0x0) {
                    /* WARNING: Subroutine does not return */
      __throw_bad_cast();
    }
    if (poVar4[0xe1] == (ostream)0x0) {
      this_00 = *(ctype<char> **)(poVar4 + 0xf0);
      if (this_00 == (ctype<char> *)0x0) {
                    /* WARNING: Subroutine does not return */
        __throw_bad_cast();
      }
      if (this_00[0x38] == (ctype<char>)0x0) {
                    /* try { // try from 00c1f283 to 00c1f2c1 has its CatchHandler @ 00c1f2c7 */
        ctype<char>::_M_widen_init(this_00);
        iVar5 = 0x20;
        cVar3 = (ctype<char>)0x20;
        if (*(code **)(*(long *)this_00 + 0x30) != FUN_00816ea8) {
          cVar3 = (ctype<char>)(**(code **)(*(long *)this_00 + 0x30))(this_00,0x20);
          iVar5 = (int)(char)cVar3;
        }
      }
      else {
        cVar3 = this_00[0x59];
        iVar5 = (int)(char)cVar3;
      }
      *(ctype<char> *)(poVar4 + 0xe0) = cVar3;
      lVar2 = *(long *)this;
      poVar4[0xe1] = (ostream)0x1;
      poVar4 = this + *(long *)(lVar2 + -0x18);
    }
    else {
      iVar5 = (int)(char)poVar4[0xe0];
    }
                    /* try { // try from 00c1f1f2 to 00c1f1f4 has its CatchHandler @ 00c1f2c7 */
    (**(code **)(*plVar1 + 0x30))
              (plVar1,*(long *)(poVar4 + 0xe8),*(long *)(poVar4 + 0xe8) == 0,poVar4,iVar5,param_1);
    if (extraout_DL != '\0') {
                    /* try { // try from 00c1f209 to 00c1f20d has its CatchHandler @ 00c1f2c2 */
      ios::s_basic_ios__clear_c1bf70
                ((ios *)(this + *(long *)(*(long *)this + -0x18)),
                 *(uint *)((ios *)(this + *(long *)(*(long *)this + -0x18)) + 0x20) | 1);
    }
  }
  sentry::~sentry(local_58);
  if (local_40 == *(long *)(in_FS_OFFSET + 0x28)) {
    return this;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ==== entry=00c1f340 orig=FUN_00c1f340 size=5 name=operator<< ====

/* std::ostream::TEMPNAMEPLACEHOLDERVALUE(unsigned long long) */

ostream * __thiscall std::ostream::operator<<(ostream *this,ulonglong param_1)

{
  long *plVar1;
  ctype<char> *this_00;
  long lVar2;
  ctype<char> cVar3;
  char extraout_DL;
  ostream *poVar4;
  int iVar5;
  long in_FS_OFFSET;
  sentry asStack_58 [24];
  long lStack_40;
  
  lStack_40 = *(long *)(in_FS_OFFSET + 0x28);
  sentry::sentry(asStack_58,this);
  if (asStack_58[0] != (sentry)0x0) {
    poVar4 = this + *(long *)(*(long *)this + -0x18);
    plVar1 = *(long **)(poVar4 + 0xf8);
    if (plVar1 == (long *)0x0) {
                    /* WARNING: Subroutine does not return */
      __throw_bad_cast();
    }
    if (poVar4[0xe1] == (ostream)0x0) {
      this_00 = *(ctype<char> **)(poVar4 + 0xf0);
      if (this_00 == (ctype<char> *)0x0) {
                    /* WARNING: Subroutine does not return */
        __throw_bad_cast();
      }
      if (this_00[0x38] == (ctype<char>)0x0) {
        ctype<char>::_M_widen_init(this_00);
        iVar5 = 0x20;
        cVar3 = (ctype<char>)0x20;
        if (*(code **)(*(long *)this_00 + 0x30) != FUN_00816ea8) {
          cVar3 = (ctype<char>)(**(code **)(*(long *)this_00 + 0x30))(this_00,0x20);
          iVar5 = (int)(char)cVar3;
        }
      }
      else {
        cVar3 = this_00[0x59];
        iVar5 = (int)(char)cVar3;
      }
      *(ctype<char> *)(poVar4 + 0xe0) = cVar3;
      lVar2 = *(long *)this;
      poVar4[0xe1] = (ostream)0x1;
      poVar4 = this + *(long *)(lVar2 + -0x18);
    }
    else {
      iVar5 = (int)(char)poVar4[0xe0];
    }
    (**(code **)(*plVar1 + 0x30))
              (plVar1,*(long *)(poVar4 + 0xe8),*(long *)(poVar4 + 0xe8) == 0,poVar4,iVar5,param_1);
    if (extraout_DL != '\0') {
      ios::s_basic_ios__clear_c1bf70
                ((ios *)(this + *(long *)(*(long *)this + -0x18)),
                 *(uint *)((ios *)(this + *(long *)(*(long *)this + -0x18)) + 0x20) | 1);
    }
  }
  sentry::~sentry(asStack_58);
  if (lStack_40 == *(long *)(in_FS_OFFSET + 0x28)) {
    return this;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ==== entry=00c1f350 orig=FUN_00c1f350 size=330 name=_M_insert<double> ====

/* std::ostream& std::ostream::_M_insert<double>(double) */

ostream * __thiscall std::ostream::_M_insert<double>(ostream *this,double param_1)

{
  long *plVar1;
  ctype<char> *this_00;
  long lVar2;
  ctype<char> cVar3;
  char extraout_DL;
  ostream *poVar4;
  int iVar5;
  long in_FS_OFFSET;
  sentry local_48 [24];
  long local_30;
  
  local_30 = *(long *)(in_FS_OFFSET + 0x28);
  sentry::sentry(local_48,this);
  if (local_48[0] != (sentry)0x0) {
    poVar4 = this + *(long *)(*(long *)this + -0x18);
    plVar1 = *(long **)(poVar4 + 0xf8);
    if (plVar1 == (long *)0x0) {
                    /* WARNING: Subroutine does not return */
      __throw_bad_cast();
    }
    if (poVar4[0xe1] == (ostream)0x0) {
      this_00 = *(ctype<char> **)(poVar4 + 0xf0);
      if (this_00 == (ctype<char> *)0x0) {
                    /* WARNING: Subroutine does not return */
        __throw_bad_cast();
      }
      if (this_00[0x38] == (ctype<char>)0x0) {
                    /* try { // try from 00c1f463 to 00c1f4a1 has its CatchHandler @ 00c1f4a7 */
        ctype<char>::_M_widen_init(this_00);
        iVar5 = 0x20;
        cVar3 = (ctype<char>)0x20;
        if (*(code **)(*(long *)this_00 + 0x30) != FUN_00816ea8) {
          cVar3 = (ctype<char>)(**(code **)(*(long *)this_00 + 0x30))(this_00,0x20);
          iVar5 = (int)(char)cVar3;
        }
      }
      else {
        cVar3 = this_00[0x59];
        iVar5 = (int)(char)cVar3;
      }
      *(ctype<char> *)(poVar4 + 0xe0) = cVar3;
      lVar2 = *(long *)this;
      poVar4[0xe1] = (ostream)0x1;
      poVar4 = this + *(long *)(lVar2 + -0x18);
    }
    else {
      iVar5 = (int)(char)poVar4[0xe0];
    }
                    /* try { // try from 00c1f3d9 to 00c1f3db has its CatchHandler @ 00c1f4a7 */
    (**(code **)(*plVar1 + 0x38))
              (param_1,plVar1,*(long *)(poVar4 + 0xe8),*(long *)(poVar4 + 0xe8) == 0,poVar4,iVar5);
    if (extraout_DL != '\0') {
                    /* try { // try from 00c1f3f0 to 00c1f3f4 has its CatchHandler @ 00c1f4a2 */
      ios::s_basic_ios__clear_c1bf70
                ((ios *)(this + *(long *)(*(long *)this + -0x18)),
                 *(uint *)((ios *)(this + *(long *)(*(long *)this + -0x18)) + 0x20) | 1);
    }
  }
  sentry::~sentry(local_48);
  if (local_30 == *(long *)(in_FS_OFFSET + 0x28)) {
    return this;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ==== entry=00c1f520 orig=FUN_00c1f520 size=5 name=operator<< ====

/* std::ostream::TEMPNAMEPLACEHOLDERVALUE(double) */

ostream * __thiscall std::ostream::operator<<(ostream *this,double param_1)

{
  long *plVar1;
  ctype<char> *this_00;
  long lVar2;
  ctype<char> cVar3;
  char extraout_DL;
  ostream *poVar4;
  int iVar5;
  long in_FS_OFFSET;
  sentry asStack_48 [24];
  long lStack_30;
  
  lStack_30 = *(long *)(in_FS_OFFSET + 0x28);
  sentry::sentry(asStack_48,this);
  if (asStack_48[0] != (sentry)0x0) {
    poVar4 = this + *(long *)(*(long *)this + -0x18);
    plVar1 = *(long **)(poVar4 + 0xf8);
    if (plVar1 == (long *)0x0) {
                    /* WARNING: Subroutine does not return */
      __throw_bad_cast();
    }
    if (poVar4[0xe1] == (ostream)0x0) {
      this_00 = *(ctype<char> **)(poVar4 + 0xf0);
      if (this_00 == (ctype<char> *)0x0) {
                    /* WARNING: Subroutine does not return */
        __throw_bad_cast();
      }
      if (this_00[0x38] == (ctype<char>)0x0) {
        ctype<char>::_M_widen_init(this_00);
        iVar5 = 0x20;
        cVar3 = (ctype<char>)0x20;
        if (*(code **)(*(long *)this_00 + 0x30) != FUN_00816ea8) {
          cVar3 = (ctype<char>)(**(code **)(*(long *)this_00 + 0x30))(this_00,0x20);
          iVar5 = (int)(char)cVar3;
        }
      }
      else {
        cVar3 = this_00[0x59];
        iVar5 = (int)(char)cVar3;
      }
      *(ctype<char> *)(poVar4 + 0xe0) = cVar3;
      lVar2 = *(long *)this;
      poVar4[0xe1] = (ostream)0x1;
      poVar4 = this + *(long *)(lVar2 + -0x18);
    }
    else {
      iVar5 = (int)(char)poVar4[0xe0];
    }
    (**(code **)(*plVar1 + 0x38))
              (param_1,plVar1,*(long *)(poVar4 + 0xe8),*(long *)(poVar4 + 0xe8) == 0,poVar4,iVar5);
    if (extraout_DL != '\0') {
      ios::s_basic_ios__clear_c1bf70
                ((ios *)(this + *(long *)(*(long *)this + -0x18)),
                 *(uint *)((ios *)(this + *(long *)(*(long *)this + -0x18)) + 0x20) | 1);
    }
  }
  sentry::~sentry(asStack_48);
  if (lStack_30 == *(long *)(in_FS_OFFSET + 0x28)) {
    return this;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ==== entry=00c1f530 orig=FUN_00c1f530 size=9 name=operator<< ====

/* std::ostream::TEMPNAMEPLACEHOLDERVALUE(float) */

void __thiscall std::ostream::operator<<(ostream *this,float param_1)

{
  _M_insert<double>(this,(double)param_1);
  return;
}


// ==== entry=00c1f540 orig=FUN_00c1f540 size=337 name=_M_insert<long_double> ====

/* std::ostream& std::ostream::_M_insert<long double>(long double) */

ostream * std::ostream::_M_insert<long_double>(longdouble param_1)

{
  long *plVar1;
  ctype<char> *this;
  long lVar2;
  ctype<char> cVar3;
  ostream *poVar4;
  undefined8 extraout_RDX;
  ostream *in_RDI;
  int iVar5;
  undefined8 in_R9;
  long in_FS_OFFSET;
  undefined6 in_stack_00000012;
  sentry local_58 [24];
  long local_40;
  
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  sentry::sentry(local_58,in_RDI);
  if (local_58[0] != (sentry)0x0) {
    poVar4 = in_RDI + *(long *)(*(long *)in_RDI + -0x18);
    plVar1 = *(long **)(poVar4 + 0xf8);
    if (plVar1 == (long *)0x0) {
                    /* WARNING: Subroutine does not return */
      __throw_bad_cast();
    }
    if (poVar4[0xe1] == (ostream)0x0) {
      this = *(ctype<char> **)(poVar4 + 0xf0);
      if (this == (ctype<char> *)0x0) {
                    /* WARNING: Subroutine does not return */
        __throw_bad_cast();
      }
      if (this[0x38] == (ctype<char>)0x0) {
                    /* try { // try from 00c1f65b to 00c1f699 has its CatchHandler @ 00c1f69f */
        ctype<char>::_M_widen_init(this);
        iVar5 = 0x20;
        cVar3 = (ctype<char>)0x20;
        if (*(code **)(*(long *)this + 0x30) != FUN_00816ea8) {
          cVar3 = (ctype<char>)(**(code **)(*(long *)this + 0x30))(this,0x20);
          iVar5 = (int)(char)cVar3;
        }
      }
      else {
        cVar3 = this[0x59];
        iVar5 = (int)(char)cVar3;
      }
      *(ctype<char> *)(poVar4 + 0xe0) = cVar3;
      lVar2 = *(long *)in_RDI;
      poVar4[0xe1] = (ostream)0x1;
      poVar4 = in_RDI + *(long *)(lVar2 + -0x18);
    }
    else {
      iVar5 = (int)(char)poVar4[0xe0];
    }
                    /* try { // try from 00c1f5c8 to 00c1f5ca has its CatchHandler @ 00c1f69f */
    (**(code **)(*plVar1 + 0x40))
              (plVar1,*(long *)(poVar4 + 0xe8),*(long *)(poVar4 + 0xe8) == 0,poVar4,iVar5,in_R9,
               param_1._0_8_);
    if ((char)extraout_RDX != '\0') {
                    /* try { // try from 00c1f5e1 to 00c1f5e5 has its CatchHandler @ 00c1f69a */
      ios::s_basic_ios__clear_c1bf70
                ((ios *)(in_RDI + *(long *)(*(long *)in_RDI + -0x18)),
                 *(uint *)((ios *)(in_RDI + *(long *)(*(long *)in_RDI + -0x18)) + 0x20) | 1,
                 extraout_RDX,CONCAT62(in_stack_00000012,param_1._8_2_));
    }
  }
  sentry::~sentry(local_58);
  if (local_40 == *(long *)(in_FS_OFFSET + 0x28)) {
    return in_RDI;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ==== entry=00c1f720 orig=FUN_00c1f720 size=5 name=operator<< ====

/* std::ostream::TEMPNAMEPLACEHOLDERVALUE(long double) */

ostream * __thiscall std::ostream::operator<<(ostream *this,longdouble param_1)

{
  long *plVar1;
  ctype<char> *this_00;
  long lVar2;
  ctype<char> cVar3;
  ostream *poVar4;
  undefined8 extraout_RDX;
  int iVar5;
  undefined8 in_R9;
  long in_FS_OFFSET;
  undefined6 in_stack_00000012;
  sentry asStack_58 [24];
  long lStack_40;
  
  lStack_40 = *(long *)(in_FS_OFFSET + 0x28);
  sentry::sentry(asStack_58,this);
  if (asStack_58[0] != (sentry)0x0) {
    poVar4 = this + *(long *)(*(long *)this + -0x18);
    plVar1 = *(long **)(poVar4 + 0xf8);
    if (plVar1 == (long *)0x0) {
                    /* WARNING: Subroutine does not return */
      __throw_bad_cast();
    }
    if (poVar4[0xe1] == (ostream)0x0) {
      this_00 = *(ctype<char> **)(poVar4 + 0xf0);
      if (this_00 == (ctype<char> *)0x0) {
                    /* WARNING: Subroutine does not return */
        __throw_bad_cast();
      }
      if (this_00[0x38] == (ctype<char>)0x0) {
        ctype<char>::_M_widen_init(this_00);
        iVar5 = 0x20;
        cVar3 = (ctype<char>)0x20;
        if (*(code **)(*(long *)this_00 + 0x30) != FUN_00816ea8) {
          cVar3 = (ctype<char>)(**(code **)(*(long *)this_00 + 0x30))(this_00,0x20);
          iVar5 = (int)(char)cVar3;
        }
      }
      else {
        cVar3 = this_00[0x59];
        iVar5 = (int)(char)cVar3;
      }
      *(ctype<char> *)(poVar4 + 0xe0) = cVar3;
      lVar2 = *(long *)this;
      poVar4[0xe1] = (ostream)0x1;
      poVar4 = this + *(long *)(lVar2 + -0x18);
    }
    else {
      iVar5 = (int)(char)poVar4[0xe0];
    }
    (**(code **)(*plVar1 + 0x40))
              (plVar1,*(long *)(poVar4 + 0xe8),*(long *)(poVar4 + 0xe8) == 0,poVar4,iVar5,in_R9,
               param_1._0_8_);
    if ((char)extraout_RDX != '\0') {
      ios::s_basic_ios__clear_c1bf70
                ((ios *)(this + *(long *)(*(long *)this + -0x18)),
                 *(uint *)((ios *)(this + *(long *)(*(long *)this + -0x18)) + 0x20) | 1,extraout_RDX
                 ,CONCAT62(in_stack_00000012,param_1._8_2_));
    }
  }
  sentry::~sentry(asStack_58);
  if (lStack_40 == *(long *)(in_FS_OFFSET + 0x28)) {
    return this;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ==== entry=00c1f730 orig=FUN_00c1f730 size=325 name=_M_insert<void_const*> ====

/* std::ostream& std::ostream::_M_insert<void const*>(void const*) */

ostream * __thiscall std::ostream::_M_insert<void_const*>(ostream *this,void *param_1)

{
  long *plVar1;
  ctype<char> *this_00;
  long lVar2;
  ctype<char> cVar3;
  char extraout_DL;
  ostream *poVar4;
  int iVar5;
  long in_FS_OFFSET;
  sentry local_58 [24];
  long local_40;
  
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  sentry::sentry(local_58,this);
  if (local_58[0] != (sentry)0x0) {
    poVar4 = this + *(long *)(*(long *)this + -0x18);
    plVar1 = *(long **)(poVar4 + 0xf8);
    if (plVar1 == (long *)0x0) {
                    /* WARNING: Subroutine does not return */
      __throw_bad_cast();
    }
    if (poVar4[0xe1] == (ostream)0x0) {
      this_00 = *(ctype<char> **)(poVar4 + 0xf0);
      if (this_00 == (ctype<char> *)0x0) {
                    /* WARNING: Subroutine does not return */
        __throw_bad_cast();
      }
      if (this_00[0x38] == (ctype<char>)0x0) {
                    /* try { // try from 00c1f843 to 00c1f881 has its CatchHandler @ 00c1f887 */
        ctype<char>::_M_widen_init(this_00);
        iVar5 = 0x20;
        cVar3 = (ctype<char>)0x20;
        if (*(code **)(*(long *)this_00 + 0x30) != FUN_00816ea8) {
          cVar3 = (ctype<char>)(**(code **)(*(long *)this_00 + 0x30))(this_00,0x20);
          iVar5 = (int)(char)cVar3;
        }
      }
      else {
        cVar3 = this_00[0x59];
        iVar5 = (int)(char)cVar3;
      }
      *(ctype<char> *)(poVar4 + 0xe0) = cVar3;
      lVar2 = *(long *)this;
      poVar4[0xe1] = (ostream)0x1;
      poVar4 = this + *(long *)(lVar2 + -0x18);
    }
    else {
      iVar5 = (int)(char)poVar4[0xe0];
    }
                    /* try { // try from 00c1f7b2 to 00c1f7b4 has its CatchHandler @ 00c1f887 */
    (**(code **)(*plVar1 + 0x48))
              (plVar1,*(long *)(poVar4 + 0xe8),*(long *)(poVar4 + 0xe8) == 0,poVar4,iVar5,param_1);
    if (extraout_DL != '\0') {
                    /* try { // try from 00c1f7c9 to 00c1f7cd has its CatchHandler @ 00c1f882 */
      ios::s_basic_ios__clear_c1bf70
                ((ios *)(this + *(long *)(*(long *)this + -0x18)),
                 *(uint *)((ios *)(this + *(long *)(*(long *)this + -0x18)) + 0x20) | 1);
    }
  }
  sentry::~sentry(local_58);
  if (local_40 == *(long *)(in_FS_OFFSET + 0x28)) {
    return this;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ==== entry=00c1f900 orig=FUN_00c1f900 size=5 name=operator<< ====

/* std::ostream::TEMPNAMEPLACEHOLDERVALUE(void const*) */

ostream * __thiscall std::ostream::operator<<(ostream *this,void *param_1)

{
  long *plVar1;
  ctype<char> *this_00;
  long lVar2;
  ctype<char> cVar3;
  char extraout_DL;
  ostream *poVar4;
  int iVar5;
  long in_FS_OFFSET;
  sentry asStack_58 [24];
  long lStack_40;
  
  lStack_40 = *(long *)(in_FS_OFFSET + 0x28);
  sentry::sentry(asStack_58,this);
  if (asStack_58[0] != (sentry)0x0) {
    poVar4 = this + *(long *)(*(long *)this + -0x18);
    plVar1 = *(long **)(poVar4 + 0xf8);
    if (plVar1 == (long *)0x0) {
                    /* WARNING: Subroutine does not return */
      __throw_bad_cast();
    }
    if (poVar4[0xe1] == (ostream)0x0) {
      this_00 = *(ctype<char> **)(poVar4 + 0xf0);
      if (this_00 == (ctype<char> *)0x0) {
                    /* WARNING: Subroutine does not return */
        __throw_bad_cast();
      }
      if (this_00[0x38] == (ctype<char>)0x0) {
        ctype<char>::_M_widen_init(this_00);
        iVar5 = 0x20;
        cVar3 = (ctype<char>)0x20;
        if (*(code **)(*(long *)this_00 + 0x30) != FUN_00816ea8) {
          cVar3 = (ctype<char>)(**(code **)(*(long *)this_00 + 0x30))(this_00,0x20);
          iVar5 = (int)(char)cVar3;
        }
      }
      else {
        cVar3 = this_00[0x59];
        iVar5 = (int)(char)cVar3;
      }
      *(ctype<char> *)(poVar4 + 0xe0) = cVar3;
      lVar2 = *(long *)this;
      poVar4[0xe1] = (ostream)0x1;
      poVar4 = this + *(long *)(lVar2 + -0x18);
    }
    else {
      iVar5 = (int)(char)poVar4[0xe0];
    }
    (**(code **)(*plVar1 + 0x48))
              (plVar1,*(long *)(poVar4 + 0xe8),*(long *)(poVar4 + 0xe8) == 0,poVar4,iVar5,param_1);
    if (extraout_DL != '\0') {
      ios::s_basic_ios__clear_c1bf70
                ((ios *)(this + *(long *)(*(long *)this + -0x18)),
                 *(uint *)((ios *)(this + *(long *)(*(long *)this + -0x18)) + 0x20) | 1);
    }
  }
  sentry::~sentry(asStack_58);
  if (lStack_40 == *(long *)(in_FS_OFFSET + 0x28)) {
    return this;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ==== entry=00c1f910 orig=FUN_00c1f910 size=25 name=wostream ====

/* std::wostream::wostream(std::wstreambuf*) */

void __thiscall std::wostream::wostream(wostream *this,wstreambuf *param_1)

{
  long lVar1;
  wstreambuf *in_RDX;
  
  lVar1 = *(long *)param_1;
  *(long *)this = lVar1;
  lVar1 = *(long *)(lVar1 + -0x18);
  *(undefined8 *)(this + lVar1) = *(undefined8 *)(param_1 + 8);
  wios::init((wios *)(this + lVar1),in_RDX);
  return;
}


// ==== entry=00c1f930 orig=FUN_00c1f930 size=132 name=wostream ====

/* std::wostream::wostream(std::wstreambuf*) */

void __thiscall std::wostream::wostream(wostream *this,wstreambuf *param_1)

{
  ios_base::ios_base((ios_base *)(this + 8));
  *(undefined8 *)(this + 0xe0) = 0;
  *(undefined4 *)(this + 0xe8) = 0;
  this[0xec] = (wostream)0x0;
  *(undefined8 *)(this + 0xf0) = 0;
  *(undefined8 *)(this + 0xf8) = 0;
  *(undefined8 *)(this + 0x100) = 0;
  *(undefined8 *)(this + 0x108) = 0;
  *(undefined8 *)this = 0x11b4f78;
  *(undefined8 *)(this + 8) = 0x11b4fa0;
                    /* try { // try from 00c1f9aa to 00c1f9ae has its CatchHandler @ 00c1f9b4 */
  wios::init((wios *)(this + 8),param_1);
  return;
}


// ==== entry=00c1f9e0 orig=FUN_00c1f9e0 size=19 name=~wostream ====

/* std::wostream::~wostream() */

void __thiscall std::wostream::~wostream(wostream *this)

{
  long lVar1;
  long *in_RSI;
  
  lVar1 = *in_RSI;
  *(long *)this = lVar1;
  *(long *)(this + *(long *)(lVar1 + -0x18)) = in_RSI[1];
  return;
}


// ==== entry=00c1fa00 orig=FUN_00c1fa00 size=2 name=operator<< ====

/* std::wostream::TEMPNAMEPLACEHOLDERVALUE(std::wostream& (*)(std::wostream&)) */

void __thiscall std::wostream::operator<<(wostream *this,_func_wostream_ptr_wostream_ptr *param_1)

{
                    /* WARNING: Could not recover jumptable at 0x00c1fa00. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*param_1)(this);
  return;
}


// ==== entry=00c1fa10 orig=FUN_00c1fa10 size=21 name=operator<< ====

/* std::wostream::TEMPNAMEPLACEHOLDERVALUE(std::wios& (*)(std::wios&)) */

wostream * __thiscall std::wostream::operator<<(wostream *this,_func_wios_ptr_wios_ptr *param_1)

{
  (*param_1)((wios *)(this + *(long *)(*(long *)this + -0x18)));
  return this;
}


// ==== entry=00c1fa30 orig=FUN_00c1fa30 size=21 name=operator<< ====

/* std::wostream::TEMPNAMEPLACEHOLDERVALUE(std::ios_base& (*)(std::ios_base&)) */

wostream * __thiscall
std::wostream::operator<<(wostream *this,_func_ios_base_ptr_ios_base_ptr *param_1)

{
  (*param_1)((ios_base *)(this + *(long *)(*(long *)this + -0x18)));
  return this;
}


// ==== entry=00c1fa50 orig=FUN_00c1fa50 size=72 name=_M_write ====

/* std::wostream::_M_write(wchar_t const*, long) */

void __thiscall std::wostream::_M_write(wostream *this,wchar_t *param_1,long param_2)

{
  long lVar1;
  
  lVar1 = (**(code **)(**(long **)(this + *(long *)(*(long *)this + -0x18) + 0xe8) + 0x60))();
  if (param_2 == lVar1) {
    return;
  }
  wios::s_basic_ios__clear_c1c9b0
            ((wios *)(this + *(long *)(*(long *)this + -0x18)),
             *(uint *)((wios *)(this + *(long *)(*(long *)this + -0x18)) + 0x20) | 1);
  return;
}


// ==== entry=00c1faa0 orig=FUN_00c1faa0 size=66 name=flush ====

/* std::wostream::flush() */

wostream * __thiscall std::wostream::flush(wostream *this)

{
  int iVar1;
  
  if (*(long **)(this + *(long *)(*(long *)this + -0x18) + 0xe8) != (long *)0x0) {
                    /* try { // try from 00c1fabb to 00c1fabd has its CatchHandler @ 00c1faea */
    iVar1 = (**(code **)(**(long **)(this + *(long *)(*(long *)this + -0x18) + 0xe8) + 0x30))();
    if (iVar1 == -1) {
      wios::s_basic_ios__clear_c1c9b0
                ((wios *)(this + *(long *)(*(long *)this + -0x18)),
                 *(uint *)((wios *)(this + *(long *)(*(long *)this + -0x18)) + 0x20) | 1);
      return this;
    }
  }
  return this;
}


// ==== entry=00c1fb60 orig=FUN_00c1fb60 size=123 name=tellp ====

/* std::wostream::tellp() */

undefined8 __thiscall std::wostream::tellp(wostream *this)

{
  long lVar1;
  undefined8 uVar2;
  long in_FS_OFFSET;
  
  lVar1 = *(long *)(in_FS_OFFSET + 0x28);
  if (((byte)this[*(long *)(*(long *)this + -0x18) + 0x20] & 5) == 0) {
                    /* try { // try from 00c1fb9e to 00c1fba0 has its CatchHandler @ 00c1fbe2 */
    uVar2 = (**(code **)(**(long **)(this + *(long *)(*(long *)this + -0x18) + 0xe8) + 0x20))
                      (*(long **)(this + *(long *)(*(long *)this + -0x18) + 0xe8),0,1,0x10);
  }
  else {
    uVar2 = 0xffffffffffffffff;
  }
  if (lVar1 == *(long *)(in_FS_OFFSET + 0x28)) {
    return uVar2;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ==== entry=00c1fc60 orig=FUN_00c1fc60 size=117 name=seekp ====

/* std::wostream::seekp(std::fpos<__mbstate_t>) */

long * std::wostream::seekp(long *param_1)

{
  long lVar1;
  long lVar2;
  wios *pwVar3;
  long in_FS_OFFSET;
  
  lVar1 = *(long *)(in_FS_OFFSET + 0x28);
  if ((*(byte *)((long)param_1 + *(long *)(*param_1 + -0x18) + 0x20) & 5) == 0) {
                    /* try { // try from 00c1fc97 to 00c1fc99 has its CatchHandler @ 00c1fcdc */
    lVar2 = (**(code **)(**(long **)((long)param_1 + *(long *)(*param_1 + -0x18) + 0xe8) + 0x28))();
    if (lVar2 == -1) {
      pwVar3 = (wios *)(*(long *)(*param_1 + -0x18) + (long)param_1);
      wios::s_basic_ios__clear_c1c9b0(pwVar3,*(uint *)(pwVar3 + 0x20) | 4);
    }
  }
  if (lVar1 == *(long *)(in_FS_OFFSET + 0x28)) {
    return param_1;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ==== entry=00c1fd50 orig=FUN_00c1fd50 size=117 name=seekp ====

/* std::wostream::seekp(long, std::_Ios_Seekdir) */

long * std::wostream::seekp(long *param_1)

{
  long lVar1;
  long lVar2;
  wios *pwVar3;
  long in_FS_OFFSET;
  
  lVar1 = *(long *)(in_FS_OFFSET + 0x28);
  if ((*(byte *)((long)param_1 + *(long *)(*param_1 + -0x18) + 0x20) & 5) == 0) {
                    /* try { // try from 00c1fd87 to 00c1fd89 has its CatchHandler @ 00c1fdcc */
    lVar2 = (**(code **)(**(long **)((long)param_1 + *(long *)(*param_1 + -0x18) + 0xe8) + 0x20))();
    if (lVar2 == -1) {
      pwVar3 = (wios *)(*(long *)(*param_1 + -0x18) + (long)param_1);
      wios::s_basic_ios__clear_c1c9b0(pwVar3,*(uint *)(pwVar3 + 0x20) | 4);
    }
  }
  if (lVar1 == *(long *)(in_FS_OFFSET + 0x28)) {
    return param_1;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ==== entry=00c1fe40 orig=FUN_00c1fe40 size=24 name=wostream ====

/* std::wostream::wostream() */

void __thiscall std::wostream::wostream(wostream *this)

{
  long lVar1;
  long *in_RSI;
  
  lVar1 = *in_RSI;
  *(long *)this = lVar1;
  lVar1 = *(long *)(lVar1 + -0x18);
  *(long *)(this + lVar1) = in_RSI[1];
  wios::init((wios *)(this + lVar1),(wstreambuf *)0x0);
  return;
}


// ==== entry=00c1fe60 orig=FUN_00c1fe60 size=128 name=wostream ====

/* std::wostream::wostream() */

void __thiscall std::wostream::wostream(wostream *this)

{
  ios_base::ios_base((ios_base *)(this + 8));
  *(undefined8 *)(this + 0xe0) = 0;
  *(undefined4 *)(this + 0xe8) = 0;
  this[0xec] = (wostream)0x0;
  *(undefined8 *)(this + 0xf0) = 0;
  *(undefined8 *)(this + 0xf8) = 0;
  *(undefined8 *)(this + 0x100) = 0;
  *(undefined8 *)(this + 0x108) = 0;
  *(undefined8 *)this = 0x11b4f78;
  *(undefined8 *)(this + 8) = 0x11b4fa0;
                    /* try { // try from 00c1fed6 to 00c1feda has its CatchHandler @ 00c1fee0 */
  wios::init((wios *)(this + 8),(wstreambuf *)0x0);
  return;
}


// ==== entry=00c1ff10 name=FUN_00c1ff10 size=19 ====

void FUN_00c1ff10(long *param_1,long *param_2)

{
  long lVar1;
  
  lVar1 = *param_2;
  *param_1 = lVar1;
  *(long *)((long)param_1 + *(long *)(lVar1 + -0x18)) = param_2[1];
  return;
}


// ==== entry=00c1ff30 name=FUN_00c1ff30 size=109 ====

void FUN_00c1ff30(undefined8 *param_1)

{
  std::ios_base::ios_base((ios_base *)(param_1 + 1));
  param_1[0x1c] = 0;
  *(undefined4 *)(param_1 + 0x1d) = 0;
  *(undefined1 *)((long)param_1 + 0xec) = 0;
  param_1[0x1e] = 0;
  param_1[0x1f] = 0;
  param_1[0x20] = 0;
  param_1[0x21] = 0;
  *param_1 = 0x11b4f78;
  param_1[1] = 0x11b4fa0;
  return;
}


// ==== entry=00c1ffa0 name=FUN_00c1ffa0 size=127 ====

void FUN_00c1ffa0(long *param_1,long *param_2,long *param_3)

{
  wios wVar1;
  undefined8 uVar2;
  long lVar3;
  wios *this;
  
  lVar3 = *param_2;
  *param_1 = lVar3;
  this = (wios *)((long)param_1 + *(long *)(lVar3 + -0x18));
  *(long *)this = param_2[1];
  lVar3 = (long)param_3 + *(long *)(*param_3 + -0x18);
  FUN_00c71b00(this,lVar3);
  std::wios::_M_cache_locale(this,(locale *)(this + 0xd0));
  uVar2 = *(undefined8 *)(lVar3 + 0xd8);
  *(undefined8 *)(lVar3 + 0xd8) = 0;
  *(undefined8 *)(this + 0xd8) = uVar2;
  *(undefined4 *)(this + 0xe0) = *(undefined4 *)(lVar3 + 0xe0);
  wVar1 = *(wios *)(lVar3 + 0xe4);
  *(undefined8 *)(this + 0xe8) = 0;
  this[0xe4] = wVar1;
  return;
}


// ==== entry=00c20020 name=FUN_00c20020 size=216 ====

void FUN_00c20020(undefined8 *param_1,long *param_2)

{
  ios_base *this;
  undefined1 uVar1;
  undefined8 uVar2;
  long lVar3;
  
  this = (ios_base *)(param_1 + 1);
  std::ios_base::ios_base(this);
  *(undefined1 *)((long)param_1 + 0xec) = 0;
  param_1[0x1c] = 0;
  *(undefined4 *)(param_1 + 0x1d) = 0;
  *param_1 = 0x11b4f78;
  param_1[1] = 0x11b4fa0;
  lVar3 = *param_2;
  param_1[0x1e] = 0;
  param_1[0x1f] = 0;
  lVar3 = (long)param_2 + *(long *)(lVar3 + -0x18);
  param_1[0x20] = 0;
  param_1[0x21] = 0;
  FUN_00c71b00(this,lVar3);
                    /* try { // try from 00c200b1 to 00c200b5 has its CatchHandler @ 00c200f8 */
  std::wios::_M_cache_locale((wios *)this,(locale *)(param_1 + 0x1b));
  uVar2 = *(undefined8 *)(lVar3 + 0xd8);
  *(undefined8 *)(lVar3 + 0xd8) = 0;
  param_1[0x1c] = uVar2;
  *(undefined4 *)(param_1 + 0x1d) = *(undefined4 *)(lVar3 + 0xe0);
  uVar1 = *(undefined1 *)(lVar3 + 0xe4);
  param_1[0x1e] = 0;
  *(undefined1 *)((long)param_1 + 0xec) = uVar1;
  return;
}


// ==== entry=00c20120 name=FUN_00c20120 size=154 ====

long * FUN_00c20120(long *param_1,long *param_2)

{
  wios wVar1;
  undefined4 uVar2;
  undefined8 uVar3;
  wios *this;
  wios *this_00;
  
  this_00 = (wios *)(*(long *)(*param_1 + -0x18) + (long)param_1);
  this = (wios *)(*(long *)(*param_2 + -0x18) + (long)param_2);
  FUN_00c71c10(this_00,this);
  std::wios::_M_cache_locale(this_00,(locale *)(this_00 + 0xd0));
  std::wios::_M_cache_locale(this,(locale *)(this + 0xd0));
  uVar3 = *(undefined8 *)(this_00 + 0xd8);
  *(undefined8 *)(this_00 + 0xd8) = *(undefined8 *)(this + 0xd8);
  *(undefined8 *)(this + 0xd8) = uVar3;
  uVar2 = *(undefined4 *)(this_00 + 0xe0);
  *(undefined4 *)(this_00 + 0xe0) = *(undefined4 *)(this + 0xe0);
  *(undefined4 *)(this + 0xe0) = uVar2;
  wVar1 = this_00[0xe4];
  this_00[0xe4] = this[0xe4];
  this[0xe4] = wVar1;
  return param_1;
}


// ==== entry=00c201c0 name=FUN_00c201c0 size=149 ====

void FUN_00c201c0(long *param_1,long *param_2)

{
  wios wVar1;
  undefined4 uVar2;
  undefined8 uVar3;
  wios *this;
  wios *this_00;
  
  this_00 = (wios *)((long)param_1 + *(long *)(*param_1 + -0x18));
  this = (wios *)(*(long *)(*param_2 + -0x18) + (long)param_2);
  FUN_00c71c10(this_00,this);
  std::wios::_M_cache_locale(this_00,(locale *)(this_00 + 0xd0));
  std::wios::_M_cache_locale(this,(locale *)(this + 0xd0));
  uVar3 = *(undefined8 *)(this_00 + 0xd8);
  *(undefined8 *)(this_00 + 0xd8) = *(undefined8 *)(this + 0xd8);
  *(undefined8 *)(this + 0xd8) = uVar3;
  uVar2 = *(undefined4 *)(this_00 + 0xe0);
  *(undefined4 *)(this_00 + 0xe0) = *(undefined4 *)(this + 0xe0);
  *(undefined4 *)(this + 0xe0) = uVar2;
  wVar1 = this_00[0xe4];
  this_00[0xe4] = this[0xe4];
  this[0xe4] = wVar1;
  return;
}


// ==== entry=00c20260 orig=FUN_00c20260 size=101 name=sentry ====

/* std::wostream::sentry::sentry(std::wostream&) */

void __thiscall std::wostream::sentry::sentry(sentry *this,wostream *param_1)

{
  long lVar1;
  wios *pwVar2;
  uint uVar3;
  
  lVar1 = *(long *)param_1;
  *(wostream **)(this + 8) = param_1;
  *this = (sentry)0x0;
  pwVar2 = (wios *)(param_1 + *(long *)(lVar1 + -0x18));
  uVar3 = *(uint *)(pwVar2 + 0x20);
  if (*(wostream **)(pwVar2 + 0xd8) != (wostream *)0x0) {
    if (uVar3 != 0) goto LAB_00c20293;
    flush(*(wostream **)(pwVar2 + 0xd8));
    pwVar2 = (wios *)(param_1 + *(long *)(*(long *)param_1 + -0x18));
    uVar3 = *(uint *)(pwVar2 + 0x20);
  }
  if (uVar3 == 0) {
    *this = (sentry)0x1;
    return;
  }
LAB_00c20293:
  wios::s_basic_ios__clear_c1c9b0(pwVar2,uVar3 | 4);
  return;
}


// ==== entry=00c202d0 orig=FUN_00c202d0 size=97 name=~sentry ====

/* std::wostream::sentry::~sentry() */

void __thiscall std::wostream::sentry::~sentry(sentry *this)

{
  long *plVar1;
  long lVar2;
  char cVar3;
  int iVar4;
  wios *pwVar5;
  
  plVar1 = *(long **)(this + 8);
  lVar2 = *(long *)(*plVar1 + -0x18);
  if ((*(byte *)((long)plVar1 + lVar2 + 0x19) & 0x20) == 0) {
    return;
  }
  cVar3 = uncaught_exception();
  if ((cVar3 == '\0') && (plVar1 = *(long **)((long)plVar1 + lVar2 + 0xe8), plVar1 != (long *)0x0))
  {
    iVar4 = (**(code **)(*plVar1 + 0x30))();
    if (iVar4 == -1) {
      pwVar5 = (wios *)((long)*(long **)(this + 8) + *(long *)(**(long **)(this + 8) + -0x18));
      wios::s_basic_ios__clear_c1c9b0(pwVar5,*(uint *)(pwVar5 + 0x20) | 1);
      return;
    }
  }
  return;
}


// ==== entry=00c20340 orig=FUN_00c20340 size=188 name=operator<< ====

/* std::wostream::TEMPNAMEPLACEHOLDERVALUE(std::wstreambuf*) */

wostream * __thiscall std::wostream::operator<<(wostream *this,wstreambuf *param_1)

{
  long lVar1;
  uint uVar2;
  wios *pwVar3;
  long in_FS_OFFSET;
  bool local_39;
  sentry local_38 [24];
  long local_20;
  
  local_20 = *(long *)(in_FS_OFFSET + 0x28);
  sentry::sentry(local_38,this);
  if (local_38[0] == (sentry)0x0) {
    if (param_1 != (wstreambuf *)0x0) goto LAB_00c203b5;
    uVar2 = 1;
    pwVar3 = (wios *)(this + *(long *)(*(long *)this + -0x18));
  }
  else {
    pwVar3 = (wios *)(this + *(long *)(*(long *)this + -0x18));
    if (param_1 == (wstreambuf *)0x0) {
      uVar2 = 1;
    }
    else {
                    /* try { // try from 00c20393 to 00c20397 has its CatchHandler @ 00c20405 */
      lVar1 = __copy_streambufs_eof<wchar_t,std::char_traits<wchar_t>>
                        (param_1,*(wstreambuf **)(pwVar3 + 0xe8),&local_39);
      if (lVar1 != 0) goto LAB_00c203b5;
      uVar2 = 4;
      pwVar3 = (wios *)(this + *(long *)(*(long *)this + -0x18));
    }
  }
                    /* try { // try from 00c203e8 to 00c20432 has its CatchHandler @ 00c2040a */
  wios::s_basic_ios__clear_c1c9b0(pwVar3,uVar2 | *(uint *)(pwVar3 + 0x20));
LAB_00c203b5:
  sentry::~sentry(local_38);
  if (local_20 == *(long *)(in_FS_OFFSET + 0x28)) {
    return this;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ==== entry=00c20480 orig=FUN_00c20480 size=169 name=put ====

/* std::wostream::put(wchar_t) */

wostream * __thiscall std::wostream::put(wostream *this,wchar_t param_1)

{
  long *plVar1;
  wchar_t *pwVar2;
  long in_FS_OFFSET;
  sentry local_38 [24];
  long local_20;
  
  local_20 = *(long *)(in_FS_OFFSET + 0x28);
  sentry::sentry(local_38,this);
  if (local_38[0] != (sentry)0x0) {
    plVar1 = *(long **)(this + *(long *)(*(long *)this + -0x18) + 0xe8);
    pwVar2 = (wchar_t *)plVar1[5];
    if (pwVar2 < (wchar_t *)plVar1[6]) {
      *pwVar2 = param_1;
      plVar1[5] = (long)(pwVar2 + 1);
    }
    else {
                    /* try { // try from 00c20526 to 00c20528 has its CatchHandler @ 00c20530 */
      param_1 = (**(code **)(*plVar1 + 0x68))(plVar1,param_1);
    }
    if (param_1 == L'\xffffffff') {
                    /* try { // try from 00c20518 to 00c2051c has its CatchHandler @ 00c20535 */
      wios::s_basic_ios__clear_c1c9b0
                ((wios *)(this + *(long *)(*(long *)this + -0x18)),
                 *(uint *)((wios *)(this + *(long *)(*(long *)this + -0x18)) + 0x20) | 1);
    }
  }
  sentry::~sentry(local_38);
  if (local_20 == *(long *)(in_FS_OFFSET + 0x28)) {
    return this;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ==== entry=00c205b0 orig=FUN_00c205b0 size=153 name=write ====

/* std::wostream::write(wchar_t const*, long) */

wostream * __thiscall std::wostream::write(wostream *this,wchar_t *param_1,long param_2)

{
  long lVar1;
  long in_FS_OFFSET;
  sentry local_48 [24];
  long local_30;
  
  local_30 = *(long *)(in_FS_OFFSET + 0x28);
  sentry::sentry(local_48,this);
  if (local_48[0] != (sentry)0x0) {
                    /* try { // try from 00c205ff to 00c20644 has its CatchHandler @ 00c2064c */
    lVar1 = (**(code **)(**(long **)(this + *(long *)(*(long *)this + -0x18) + 0xe8) + 0x60))
                      (*(long **)(this + *(long *)(*(long *)this + -0x18) + 0xe8),param_1,param_2);
    if (param_2 != lVar1) {
      wios::s_basic_ios__clear_c1c9b0
                ((wios *)(this + *(long *)(*(long *)this + -0x18)),
                 *(uint *)((wios *)(this + *(long *)(*(long *)this + -0x18)) + 0x20) | 1);
    }
  }
  sentry::~sentry(local_48);
  if (local_30 == *(long *)(in_FS_OFFSET + 0x28)) {
    return this;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ==== entry=00c206d0 orig=FUN_00c206d0 size=4 name=operator.cast.to.bool ====

/* std::wostream::sentry::operator bool() const */

bool __thiscall std::wostream::sentry::operator_cast_to_bool(sentry *this)

{
  return (bool)*this;
}


// ==== entry=00c206e0 orig=FUN_00c206e0 size=59 name=endl<wchar_t,std::char_traits<wchar_t>> ====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* std::wostream& std::endl<wchar_t, std::char_traits<wchar_t> >(std::wostream&) */

wostream * std::endl<wchar_t,std::char_traits<wchar_t>>(wostream *param_1)

{
  long *plVar1;
  wchar_t wVar2;
  wostream *pwVar3;
  
  plVar1 = *(long **)(param_1 + *(long *)(*(long *)param_1 + -0x18) + 0xf0);
  if (plVar1 != (long *)0x0) {
    wVar2 = (**(code **)(*plVar1 + 0x50))(plVar1,10);
    pwVar3 = (wostream *)wostream::put(param_1,wVar2);
    pwVar3 = (wostream *)wostream::flush(pwVar3);
    return pwVar3;
  }
                    /* WARNING: Subroutine does not return */
  __throw_bad_cast();
}


// ==== entry=00c20720 orig=FUN_00c20720 size=7 name=ends<wchar_t,std::char_traits<wchar_t>> ====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* std::wostream& std::ends<wchar_t, std::char_traits<wchar_t> >(std::wostream&) */

wostream * std::ends<wchar_t,std::char_traits<wchar_t>>(wostream *param_1)

{
  wostream *pwVar1;
  
  pwVar1 = (wostream *)wostream::put(param_1,L'\0');
  return pwVar1;
}


// ==== entry=00c20730 orig=FUN_00c20730 size=5 name=flush<wchar_t,std::char_traits<wchar_t>> ====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* std::wostream& std::flush<wchar_t, std::char_traits<wchar_t> >(std::wostream&) */

wostream * std::flush<wchar_t,std::char_traits<wchar_t>>(wostream *param_1)

{
  int iVar1;
  
  if (*(long **)(param_1 + *(long *)(*(long *)param_1 + -0x18) + 0xe8) != (long *)0x0) {
    iVar1 = (**(code **)(**(long **)(param_1 + *(long *)(*(long *)param_1 + -0x18) + 0xe8) + 0x30))
                      ();
    if (iVar1 == -1) {
      wios::s_basic_ios__clear_c1c9b0
                ((wios *)(param_1 + *(long *)(*(long *)param_1 + -0x18)),
                 *(uint *)((wios *)(param_1 + *(long *)(*(long *)param_1 + -0x18)) + 0x20) | 1);
      return param_1;
    }
  }
  return param_1;
}


// ==== entry=00c20740 orig=FUN_00c20740 size=94 name=operator<< ====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* std::wostream& std::TEMPNAMEPLACEHOLDERVALUE(std::wostream&, std::_Setfill<wchar_t>) */

wostream * std::operator<<(wostream *param_1,undefined4 param_2)

{
  long lVar1;
  long *plVar2;
  
  lVar1 = *(long *)(*(long *)param_1 + -0x18);
  if (param_1[lVar1 + 0xe4] != (wostream)0x0) {
    *(undefined4 *)(param_1 + lVar1 + 0xe0) = param_2;
    return param_1;
  }
  plVar2 = *(long **)(param_1 + lVar1 + 0xf0);
  if (plVar2 != (long *)0x0) {
    (**(code **)(*plVar2 + 0x50))(plVar2,0x20);
    param_1[lVar1 + 0xe4] = (wostream)0x1;
    *(undefined4 *)(param_1 + lVar1 + 0xe0) = param_2;
    return param_1;
  }
                    /* WARNING: Subroutine does not return */
  __throw_bad_cast();
}


// ==== entry=00c207b0 orig=FUN_00c207b0 size=17 name=operator<< ====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* std::wostream& std::TEMPNAMEPLACEHOLDERVALUE(std::wostream&, std::_Setiosflags) */

wostream * std::operator<<(wostream *param_1,uint param_2)

{
  *(uint *)(param_1 + *(long *)(*(long *)param_1 + -0x18) + 0x18) =
       *(uint *)(param_1 + *(long *)(*(long *)param_1 + -0x18) + 0x18) | param_2;
  return param_1;
}


// ==== entry=00c207d0 orig=FUN_00c207d0 size=19 name=operator<< ====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* std::wostream& std::TEMPNAMEPLACEHOLDERVALUE(std::wostream&, std::_Resetiosflags) */

wostream * std::operator<<(wostream *param_1,uint param_2)

{
  *(uint *)(param_1 + *(long *)(*(long *)param_1 + -0x18) + 0x18) =
       *(uint *)(param_1 + *(long *)(*(long *)param_1 + -0x18) + 0x18) & ~param_2;
  return param_1;
}


// ==== entry=00c207f0 orig=FUN_00c207f0 size=56 name=operator<< ====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* std::wostream& std::TEMPNAMEPLACEHOLDERVALUE(std::wostream&, std::_Setbase) */

wostream * std::operator<<(wostream *param_1,int param_2)

{
  uint uVar1;
  
  uVar1 = 0x40;
  if ((param_2 != 8) && (uVar1 = 2, param_2 != 10)) {
    uVar1 = (uint)(param_2 == 0x10) << 3;
  }
  *(uint *)(param_1 + *(long *)(*(long *)param_1 + -0x18) + 0x18) =
       *(uint *)(param_1 + *(long *)(*(long *)param_1 + -0x18) + 0x18) & 0xffffffb5 | uVar1;
  return param_1;
}


// ==== entry=00c20830 orig=FUN_00c20830 size=19 name=operator<< ====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* std::wostream& std::TEMPNAMEPLACEHOLDERVALUE(std::wostream&, std::_Setprecision) */

wostream * std::operator<<(wostream *param_1,int param_2)

{
  *(long *)(param_1 + *(long *)(*(long *)param_1 + -0x18) + 8) = (long)param_2;
  return param_1;
}


// ==== entry=00c20850 orig=FUN_00c20850 size=19 name=operator<< ====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* std::wostream& std::TEMPNAMEPLACEHOLDERVALUE(std::wostream&, std::_Setw) */

wostream * std::operator<<(wostream *param_1,int param_2)

{
  *(long *)(param_1 + *(long *)(*(long *)param_1 + -0x18) + 0x10) = (long)param_2;
  return param_1;
}


// ==== entry=00c20870 orig=FUN_00c20870 size=743 name=__ostream_insert<wchar_t,std::char_traits<wchar_t>> ====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* std::wostream& std::__ostream_insert<wchar_t, std::char_traits<wchar_t> >(std::wostream&, wchar_t
   const*, long) */

wostream *
std::__ostream_insert<wchar_t,std::char_traits<wchar_t>>
          (wostream *param_1,wchar_t *param_2,long param_3)

{
  uint uVar1;
  long *plVar2;
  int *piVar3;
  long lVar4;
  int iVar5;
  int iVar6;
  long lVar7;
  wios *pwVar8;
  long lVar9;
  long in_FS_OFFSET;
  sentry local_58 [24];
  long local_40;
  
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  wostream::sentry::sentry(local_58,param_1);
  if (local_58[0] != (sentry)0x0) {
    pwVar8 = (wios *)(param_1 + *(long *)(*(long *)param_1 + -0x18));
    lVar9 = *(long *)(pwVar8 + 0x10);
    if (param_3 < lVar9) {
      uVar1 = *(uint *)(pwVar8 + 0x18);
      if ((uVar1 & 0xb0) == 0x20) {
LAB_00c20970:
        iVar6 = *(int *)(pwVar8 + 0x20);
      }
      else {
        lVar7 = lVar9 - param_3;
        if (pwVar8[0xe4] == (wios)0x0) {
          plVar2 = *(long **)(pwVar8 + 0xf0);
          if (plVar2 == (long *)0x0) {
                    /* WARNING: Subroutine does not return */
            __throw_bad_cast();
          }
          iVar6 = (**(code **)(*plVar2 + 0x50))(plVar2,0x20);
          *(int *)(pwVar8 + 0xe0) = iVar6;
          lVar4 = *(long *)param_1;
          pwVar8[0xe4] = (wios)0x1;
          pwVar8 = (wios *)(param_1 + *(long *)(lVar4 + -0x18));
        }
        else {
          iVar6 = *(int *)(pwVar8 + 0xe0);
        }
        do {
          plVar2 = *(long **)(pwVar8 + 0xe8);
          piVar3 = (int *)plVar2[5];
          if (piVar3 < (int *)plVar2[6]) {
            *piVar3 = iVar6;
            plVar2[5] = (long)(piVar3 + 1);
            iVar5 = iVar6;
          }
          else {
                    /* try { // try from 00c2093f to 00c20b81 has its CatchHandler @ 00c20b82 */
            iVar5 = (**(code **)(*plVar2 + 0x68))(plVar2,iVar6);
            pwVar8 = (wios *)(param_1 + *(long *)(*(long *)param_1 + -0x18));
          }
          if (iVar5 == -1) {
            wios::s_basic_ios__clear_c1c9b0(pwVar8,*(uint *)(pwVar8 + 0x20) | 1);
            pwVar8 = (wios *)(param_1 + *(long *)(*(long *)param_1 + -0x18));
            goto LAB_00c20970;
          }
          lVar7 = lVar7 + -1;
        } while (lVar7 != 0);
        iVar6 = *(int *)(pwVar8 + 0x20);
      }
      if (iVar6 == 0) {
        lVar7 = (**(code **)(**(long **)(pwVar8 + 0xe8) + 0x60))
                          (*(long **)(pwVar8 + 0xe8),param_2,param_3);
        pwVar8 = (wios *)(param_1 + *(long *)(*(long *)param_1 + -0x18));
        if (param_3 != lVar7) {
          wios::s_basic_ios__clear_c1c9b0(pwVar8,*(uint *)(pwVar8 + 0x20) | 1);
          pwVar8 = (wios *)(param_1 + *(long *)(*(long *)param_1 + -0x18));
        }
        if (((uVar1 & 0xb0) == 0x20) && (*(int *)(pwVar8 + 0x20) == 0)) {
          lVar9 = lVar9 - param_3;
          if (pwVar8[0xe4] == (wios)0x0) {
            plVar2 = *(long **)(pwVar8 + 0xf0);
            if (plVar2 == (long *)0x0) {
                    /* WARNING: Subroutine does not return */
              __throw_bad_cast();
            }
            iVar6 = (**(code **)(*plVar2 + 0x50))(plVar2,0x20);
            *(int *)(pwVar8 + 0xe0) = iVar6;
            lVar7 = *(long *)param_1;
            pwVar8[0xe4] = (wios)0x1;
            pwVar8 = (wios *)(param_1 + *(long *)(lVar7 + -0x18));
          }
          else {
            iVar6 = *(int *)(pwVar8 + 0xe0);
          }
          do {
            plVar2 = *(long **)(pwVar8 + 0xe8);
            piVar3 = (int *)plVar2[5];
            if (piVar3 < (int *)plVar2[6]) {
              *piVar3 = iVar6;
              plVar2[5] = (long)(piVar3 + 1);
              iVar5 = iVar6;
            }
            else {
              iVar5 = (**(code **)(*plVar2 + 0x68))(plVar2,iVar6);
              pwVar8 = (wios *)(param_1 + *(long *)(*(long *)param_1 + -0x18));
            }
            if (iVar5 == -1) {
              wios::s_basic_ios__clear_c1c9b0(pwVar8,*(uint *)(pwVar8 + 0x20) | 1);
              goto LAB_00c209ed;
            }
            lVar9 = lVar9 + -1;
          } while (lVar9 != 0);
        }
      }
    }
    else {
      lVar9 = (**(code **)(**(long **)(pwVar8 + 0xe8) + 0x60))
                        (*(long **)(pwVar8 + 0xe8),param_2,param_3);
      pwVar8 = (wios *)(param_1 + *(long *)(*(long *)param_1 + -0x18));
      if (param_3 != lVar9) {
        wios::s_basic_ios__clear_c1c9b0(pwVar8,*(uint *)(pwVar8 + 0x20) | 1);
LAB_00c209ed:
        *(undefined8 *)(param_1 + *(long *)(*(long *)param_1 + -0x18) + 0x10) = 0;
        goto LAB_00c20983;
      }
    }
    *(undefined8 *)(pwVar8 + 0x10) = 0;
  }
LAB_00c20983:
  wostream::sentry::~sentry(local_58);
  if (local_40 == *(long *)(in_FS_OFFSET + 0x28)) {
    return param_1;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ==== entry=00c20c00 orig=FUN_00c20c00 size=28 name=operator<< ====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* std::wostream& std::TEMPNAMEPLACEHOLDERVALUE(std::wostream&, wchar_t) */

wostream * std::operator<<(wostream *param_1,wchar_t param_2)

{
  wostream *pwVar1;
  wchar_t local_c [3];
  
  local_c[0] = param_2;
  pwVar1 = __ostream_insert<wchar_t,std::char_traits<wchar_t>>(param_1,local_c,1);
  return pwVar1;
}


// ==== entry=00c20c20 orig=FUN_00c20c20 size=80 name=operator<< ====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* std::wostream& std::TEMPNAMEPLACEHOLDERVALUE(std::wostream&, wchar_t const*) */

wostream * std::operator<<(wostream *param_1,wchar_t *param_2)

{
  size_t sVar1;
  
  if (param_2 != (wchar_t *)0x0) {
    sVar1 = wcslen(param_2);
    __ostream_insert<wchar_t,std::char_traits<wchar_t>>(param_1,param_2,sVar1);
    return param_1;
  }
  wios::s_basic_ios__clear_c1c9b0
            ((wios *)(param_1 + *(long *)(*(long *)param_1 + -0x18)),
             *(uint *)((wios *)(param_1 + *(long *)(*(long *)param_1 + -0x18)) + 0x20) | 1);
  return param_1;
}


// ==== entry=00c20c80 orig=FUN_00c20c80 size=108 name=operator<< ====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* std::wostream& std::TEMPNAMEPLACEHOLDERVALUE(std::wostream&, char) */

wostream * std::operator<<(wostream *param_1,char param_2)

{
  long *plVar1;
  wostream *pwVar2;
  long in_FS_OFFSET;
  wchar_t local_14;
  long local_10;
  
  local_10 = *(long *)(in_FS_OFFSET + 0x28);
  plVar1 = *(long **)(param_1 + *(long *)(*(long *)param_1 + -0x18) + 0xf0);
  if (plVar1 == (long *)0x0) {
                    /* WARNING: Subroutine does not return */
    __throw_bad_cast();
  }
  local_14 = (**(code **)(*plVar1 + 0x50))(plVar1,(int)param_2);
  pwVar2 = __ostream_insert<wchar_t,std::char_traits<wchar_t>>(param_1,&local_14,1);
  if (local_10 == *(long *)(in_FS_OFFSET + 0x28)) {
    return pwVar2;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ==== entry=00c20cf0 orig=FUN_00c20cf0 size=245 name=operator<< ====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* std::wostream& std::TEMPNAMEPLACEHOLDERVALUE(std::wostream&, char const*) */

wostream * std::operator<<(wostream *param_1,char *param_2)

{
  char cVar1;
  wchar_t wVar2;
  size_t sVar3;
  wchar_t *pwVar4;
  wchar_t *pwVar5;
  long *plVar6;
  
  if (param_2 == (char *)0x0) {
    wios::s_basic_ios__clear_c1c9b0
              ((wios *)(param_1 + *(long *)(*(long *)param_1 + -0x18)),
               *(uint *)((wios *)(param_1 + *(long *)(*(long *)param_1 + -0x18)) + 0x20) | 1);
  }
  else {
    sVar3 = strlen(param_2);
    if (0x1ffffffffffffffe < sVar3) {
                    /* WARNING: Subroutine does not return */
                    /* try { // try from 00c20df1 to 00c20df5 has its CatchHandler @ 00c20dec */
      __cxa_throw_bad_array_new_length();
    }
                    /* try { // try from 00c20d36 to 00c20d3a has its CatchHandler @ 00c20dec */
    pwVar4 = operator_new__(sVar3 * 4);
    if (sVar3 != 0) {
      cVar1 = *param_2;
      plVar6 = *(long **)(param_1 + *(long *)(*(long *)param_1 + -0x18) + 0xf0);
      if (plVar6 != (long *)0x0) {
        pwVar5 = pwVar4;
        do {
          param_2 = param_2 + 1;
                    /* try { // try from 00c20d94 to 00c20dab has its CatchHandler @ 00c20df6 */
          wVar2 = (**(code **)(*plVar6 + 0x50))(plVar6,(int)cVar1);
          *pwVar5 = wVar2;
          if (pwVar5 == pwVar4 + (sVar3 - 1)) goto LAB_00c20d9e;
          cVar1 = *param_2;
          pwVar5 = pwVar5 + 1;
          plVar6 = *(long **)(param_1 + *(long *)(*(long *)param_1 + -0x18) + 0xf0);
        } while (plVar6 != (long *)0x0);
      }
                    /* WARNING: Subroutine does not return */
                    /* try { // try from 00c20de7 to 00c20deb has its CatchHandler @ 00c20df6 */
      __throw_bad_cast();
    }
LAB_00c20d9e:
    __ostream_insert<wchar_t,std::char_traits<wchar_t>>(param_1,pwVar4,sVar3);
    operator_delete__(pwVar4);
  }
  return param_1;
}


// ==== entry=00c20e90 orig=FUN_00c20e90 size=264 name=_M_insert<long> ====

/* std::wostream& std::wostream::_M_insert<long>(long) */

wostream * __thiscall std::wostream::_M_insert<long>(wostream *this,long param_1)

{
  long *plVar1;
  long *plVar2;
  long lVar3;
  undefined4 uVar4;
  char extraout_DL;
  wostream *pwVar5;
  long in_FS_OFFSET;
  sentry local_48 [24];
  long local_30;
  
  local_30 = *(long *)(in_FS_OFFSET + 0x28);
  sentry::sentry(local_48,this);
  if (local_48[0] != (sentry)0x0) {
    pwVar5 = this + *(long *)(*(long *)this + -0x18);
    plVar1 = *(long **)(pwVar5 + 0xf8);
    if (plVar1 == (long *)0x0) {
                    /* WARNING: Subroutine does not return */
      __throw_bad_cast();
    }
    if (pwVar5[0xe4] == (wostream)0x0) {
      plVar2 = *(long **)(pwVar5 + 0xf0);
      if (plVar2 == (long *)0x0) {
                    /* WARNING: Subroutine does not return */
        __throw_bad_cast();
      }
                    /* try { // try from 00c20f6c to 00c20f9c has its CatchHandler @ 00c20fa2 */
      uVar4 = (**(code **)(*plVar2 + 0x50))(plVar2,0x20);
      *(undefined4 *)(pwVar5 + 0xe0) = uVar4;
      lVar3 = *(long *)this;
      pwVar5[0xe4] = (wostream)0x1;
      pwVar5 = this + *(long *)(lVar3 + -0x18);
    }
    else {
      uVar4 = *(undefined4 *)(pwVar5 + 0xe0);
    }
                    /* try { // try from 00c20f0f to 00c20f11 has its CatchHandler @ 00c20fa2 */
    (**(code **)(*plVar1 + 0x18))
              (plVar1,*(long *)(pwVar5 + 0xe8),*(long *)(pwVar5 + 0xe8) == 0,pwVar5,uVar4,param_1);
    if (extraout_DL != '\0') {
                    /* try { // try from 00c20f26 to 00c20f2a has its CatchHandler @ 00c20f9d */
      wios::s_basic_ios__clear_c1c9b0
                ((wios *)(this + *(long *)(*(long *)this + -0x18)),
                 *(uint *)((wios *)(this + *(long *)(*(long *)this + -0x18)) + 0x20) | 1);
    }
  }
  sentry::~sentry(local_48);
  if (local_30 == *(long *)(in_FS_OFFSET + 0x28)) {
    return this;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ==== entry=00c21020 orig=FUN_00c21020 size=5 name=operator<< ====

/* std::wostream::TEMPNAMEPLACEHOLDERVALUE(long) */

wostream * __thiscall std::wostream::operator<<(wostream *this,long param_1)

{
  long *plVar1;
  long *plVar2;
  long lVar3;
  undefined4 uVar4;
  char extraout_DL;
  wostream *pwVar5;
  long in_FS_OFFSET;
  sentry asStack_48 [24];
  long lStack_30;
  
  lStack_30 = *(long *)(in_FS_OFFSET + 0x28);
  sentry::sentry(asStack_48,this);
  if (asStack_48[0] != (sentry)0x0) {
    pwVar5 = this + *(long *)(*(long *)this + -0x18);
    plVar1 = *(long **)(pwVar5 + 0xf8);
    if (plVar1 == (long *)0x0) {
                    /* WARNING: Subroutine does not return */
      __throw_bad_cast();
    }
    if (pwVar5[0xe4] == (wostream)0x0) {
      plVar2 = *(long **)(pwVar5 + 0xf0);
      if (plVar2 == (long *)0x0) {
                    /* WARNING: Subroutine does not return */
        __throw_bad_cast();
      }
      uVar4 = (**(code **)(*plVar2 + 0x50))(plVar2,0x20);
      *(undefined4 *)(pwVar5 + 0xe0) = uVar4;
      lVar3 = *(long *)this;
      pwVar5[0xe4] = (wostream)0x1;
      pwVar5 = this + *(long *)(lVar3 + -0x18);
    }
    else {
      uVar4 = *(undefined4 *)(pwVar5 + 0xe0);
    }
    (**(code **)(*plVar1 + 0x18))
              (plVar1,*(long *)(pwVar5 + 0xe8),*(long *)(pwVar5 + 0xe8) == 0,pwVar5,uVar4,param_1);
    if (extraout_DL != '\0') {
      wios::s_basic_ios__clear_c1c9b0
                ((wios *)(this + *(long *)(*(long *)this + -0x18)),
                 *(uint *)((wios *)(this + *(long *)(*(long *)this + -0x18)) + 0x20) | 1);
    }
  }
  sentry::~sentry(asStack_48);
  if (lStack_30 == *(long *)(in_FS_OFFSET + 0x28)) {
    return this;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ==== entry=00c21030 orig=FUN_00c21030 size=41 name=operator<< ====

/* std::wostream::TEMPNAMEPLACEHOLDERVALUE(short) */

void __thiscall std::wostream::operator<<(wostream *this,short param_1)

{
  if (((*(uint *)(this + *(long *)(*(long *)this + -0x18) + 0x18) & 0x4a) != 0x40) &&
     ((*(uint *)(this + *(long *)(*(long *)this + -0x18) + 0x18) & 0x4a) != 8)) {
    _M_insert<long>(this,(long)param_1);
    return;
  }
  _M_insert<long>(this,(ulong)(ushort)param_1);
  return;
}


// ==== entry=00c21060 orig=FUN_00c21060 size=39 name=operator<< ====

/* std::wostream::TEMPNAMEPLACEHOLDERVALUE(int) */

void __thiscall std::wostream::operator<<(wostream *this,int param_1)

{
  if (((*(uint *)(this + *(long *)(*(long *)this + -0x18) + 0x18) & 0x4a) != 0x40) &&
     ((*(uint *)(this + *(long *)(*(long *)this + -0x18) + 0x18) & 0x4a) != 8)) {
    _M_insert<long>(this,(long)param_1);
    return;
  }
  _M_insert<long>(this,(ulong)(uint)param_1);
  return;
}


// ==== entry=00c21090 orig=FUN_00c21090 size=264 name=_M_insert<unsigned_long> ====

/* std::wostream& std::wostream::_M_insert<unsigned long>(unsigned long) */

wostream * __thiscall std::wostream::_M_insert<unsigned_long>(wostream *this,ulong param_1)

{
  long *plVar1;
  long *plVar2;
  long lVar3;
  undefined4 uVar4;
  char extraout_DL;
  wostream *pwVar5;
  long in_FS_OFFSET;
  sentry local_48 [24];
  long local_30;
  
  local_30 = *(long *)(in_FS_OFFSET + 0x28);
  sentry::sentry(local_48,this);
  if (local_48[0] != (sentry)0x0) {
    pwVar5 = this + *(long *)(*(long *)this + -0x18);
    plVar1 = *(long **)(pwVar5 + 0xf8);
    if (plVar1 == (long *)0x0) {
                    /* WARNING: Subroutine does not return */
      __throw_bad_cast();
    }
    if (pwVar5[0xe4] == (wostream)0x0) {
      plVar2 = *(long **)(pwVar5 + 0xf0);
      if (plVar2 == (long *)0x0) {
                    /* WARNING: Subroutine does not return */
        __throw_bad_cast();
      }
                    /* try { // try from 00c2116c to 00c2119c has its CatchHandler @ 00c211a2 */
      uVar4 = (**(code **)(*plVar2 + 0x50))(plVar2,0x20);
      *(undefined4 *)(pwVar5 + 0xe0) = uVar4;
      lVar3 = *(long *)this;
      pwVar5[0xe4] = (wostream)0x1;
      pwVar5 = this + *(long *)(lVar3 + -0x18);
    }
    else {
      uVar4 = *(undefined4 *)(pwVar5 + 0xe0);
    }
                    /* try { // try from 00c2110f to 00c21111 has its CatchHandler @ 00c211a2 */
    (**(code **)(*plVar1 + 0x20))
              (plVar1,*(long *)(pwVar5 + 0xe8),*(long *)(pwVar5 + 0xe8) == 0,pwVar5,uVar4,param_1);
    if (extraout_DL != '\0') {
                    /* try { // try from 00c21126 to 00c2112a has its CatchHandler @ 00c2119d */
      wios::s_basic_ios__clear_c1c9b0
                ((wios *)(this + *(long *)(*(long *)this + -0x18)),
                 *(uint *)((wios *)(this + *(long *)(*(long *)this + -0x18)) + 0x20) | 1);
    }
  }
  sentry::~sentry(local_48);
  if (local_30 == *(long *)(in_FS_OFFSET + 0x28)) {
    return this;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ==== entry=00c21220 orig=FUN_00c21220 size=5 name=operator<< ====

/* std::wostream::TEMPNAMEPLACEHOLDERVALUE(unsigned long) */

wostream * __thiscall std::wostream::operator<<(wostream *this,ulong param_1)

{
  long *plVar1;
  long *plVar2;
  long lVar3;
  undefined4 uVar4;
  char extraout_DL;
  wostream *pwVar5;
  long in_FS_OFFSET;
  sentry asStack_48 [24];
  long lStack_30;
  
  lStack_30 = *(long *)(in_FS_OFFSET + 0x28);
  sentry::sentry(asStack_48,this);
  if (asStack_48[0] != (sentry)0x0) {
    pwVar5 = this + *(long *)(*(long *)this + -0x18);
    plVar1 = *(long **)(pwVar5 + 0xf8);
    if (plVar1 == (long *)0x0) {
                    /* WARNING: Subroutine does not return */
      __throw_bad_cast();
    }
    if (pwVar5[0xe4] == (wostream)0x0) {
      plVar2 = *(long **)(pwVar5 + 0xf0);
      if (plVar2 == (long *)0x0) {
                    /* WARNING: Subroutine does not return */
        __throw_bad_cast();
      }
      uVar4 = (**(code **)(*plVar2 + 0x50))(plVar2,0x20);
      *(undefined4 *)(pwVar5 + 0xe0) = uVar4;
      lVar3 = *(long *)this;
      pwVar5[0xe4] = (wostream)0x1;
      pwVar5 = this + *(long *)(lVar3 + -0x18);
    }
    else {
      uVar4 = *(undefined4 *)(pwVar5 + 0xe0);
    }
    (**(code **)(*plVar1 + 0x20))
              (plVar1,*(long *)(pwVar5 + 0xe8),*(long *)(pwVar5 + 0xe8) == 0,pwVar5,uVar4,param_1);
    if (extraout_DL != '\0') {
      wios::s_basic_ios__clear_c1c9b0
                ((wios *)(this + *(long *)(*(long *)this + -0x18)),
                 *(uint *)((wios *)(this + *(long *)(*(long *)this + -0x18)) + 0x20) | 1);
    }
  }
  sentry::~sentry(asStack_48);
  if (lStack_30 == *(long *)(in_FS_OFFSET + 0x28)) {
    return this;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ==== entry=00c21230 orig=FUN_00c21230 size=8 name=operator<< ====

/* std::wostream::TEMPNAMEPLACEHOLDERVALUE(unsigned short) */

void __thiscall std::wostream::operator<<(wostream *this,ushort param_1)

{
  _M_insert<unsigned_long>(this,(ulong)param_1);
  return;
}


// ==== entry=00c21240 orig=FUN_00c21240 size=7 name=operator<< ====

/* std::wostream::TEMPNAMEPLACEHOLDERVALUE(unsigned int) */

void __thiscall std::wostream::operator<<(wostream *this,uint param_1)

{
  _M_insert<unsigned_long>(this,(ulong)param_1);
  return;
}


// ==== entry=00c21250 orig=FUN_00c21250 size=267 name=_M_insert<bool> ====

/* std::wostream& std::wostream::_M_insert<bool>(bool) */

wostream * __thiscall std::wostream::_M_insert<bool>(wostream *this,bool param_1)

{
  long *plVar1;
  long *plVar2;
  long lVar3;
  undefined4 uVar4;
  char extraout_DL;
  wostream *pwVar5;
  long in_FS_OFFSET;
  sentry local_48 [24];
  long local_30;
  
  local_30 = *(long *)(in_FS_OFFSET + 0x28);
  sentry::sentry(local_48,this);
  if (local_48[0] != (sentry)0x0) {
    pwVar5 = this + *(long *)(*(long *)this + -0x18);
    plVar1 = *(long **)(pwVar5 + 0xf8);
    if (plVar1 == (long *)0x0) {
                    /* WARNING: Subroutine does not return */
      __throw_bad_cast();
    }
    if (pwVar5[0xe4] == (wostream)0x0) {
      plVar2 = *(long **)(pwVar5 + 0xf0);
      if (plVar2 == (long *)0x0) {
                    /* WARNING: Subroutine does not return */
        __throw_bad_cast();
      }
                    /* try { // try from 00c21334 to 00c21364 has its CatchHandler @ 00c2136a */
      uVar4 = (**(code **)(*plVar2 + 0x50))(plVar2,0x20);
      *(undefined4 *)(pwVar5 + 0xe0) = uVar4;
      lVar3 = *(long *)this;
      pwVar5[0xe4] = (wostream)0x1;
      pwVar5 = this + *(long *)(lVar3 + -0x18);
    }
    else {
      uVar4 = *(undefined4 *)(pwVar5 + 0xe0);
    }
                    /* try { // try from 00c212d2 to 00c212d4 has its CatchHandler @ 00c2136a */
    (**(code **)(*plVar1 + 0x10))
              (plVar1,*(long *)(pwVar5 + 0xe8),*(long *)(pwVar5 + 0xe8) == 0,pwVar5,uVar4,param_1);
    if (extraout_DL != '\0') {
                    /* try { // try from 00c212e9 to 00c212ed has its CatchHandler @ 00c21365 */
      wios::s_basic_ios__clear_c1c9b0
                ((wios *)(this + *(long *)(*(long *)this + -0x18)),
                 *(uint *)((wios *)(this + *(long *)(*(long *)this + -0x18)) + 0x20) | 1);
    }
  }
  sentry::~sentry(local_48);
  if (local_30 == *(long *)(in_FS_OFFSET + 0x28)) {
    return this;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ==== entry=00c213f0 orig=FUN_00c213f0 size=9 name=operator<< ====

/* std::wostream::TEMPNAMEPLACEHOLDERVALUE(bool) */

void __thiscall std::wostream::operator<<(wostream *this,bool param_1)

{
  _M_insert<bool>(this,param_1);
  return;
}


// ==== entry=00c21400 orig=FUN_00c21400 size=264 name=_M_insert<long_long> ====

/* std::wostream& std::wostream::_M_insert<long long>(long long) */

wostream * __thiscall std::wostream::_M_insert<long_long>(wostream *this,longlong param_1)

{
  long *plVar1;
  long *plVar2;
  long lVar3;
  undefined4 uVar4;
  char extraout_DL;
  wostream *pwVar5;
  long in_FS_OFFSET;
  sentry local_48 [24];
  long local_30;
  
  local_30 = *(long *)(in_FS_OFFSET + 0x28);
  sentry::sentry(local_48,this);
  if (local_48[0] != (sentry)0x0) {
    pwVar5 = this + *(long *)(*(long *)this + -0x18);
    plVar1 = *(long **)(pwVar5 + 0xf8);
    if (plVar1 == (long *)0x0) {
                    /* WARNING: Subroutine does not return */
      __throw_bad_cast();
    }
    if (pwVar5[0xe4] == (wostream)0x0) {
      plVar2 = *(long **)(pwVar5 + 0xf0);
      if (plVar2 == (long *)0x0) {
                    /* WARNING: Subroutine does not return */
        __throw_bad_cast();
      }
                    /* try { // try from 00c214dc to 00c2150c has its CatchHandler @ 00c21512 */
      uVar4 = (**(code **)(*plVar2 + 0x50))(plVar2,0x20);
      *(undefined4 *)(pwVar5 + 0xe0) = uVar4;
      lVar3 = *(long *)this;
      pwVar5[0xe4] = (wostream)0x1;
      pwVar5 = this + *(long *)(lVar3 + -0x18);
    }
    else {
      uVar4 = *(undefined4 *)(pwVar5 + 0xe0);
    }
                    /* try { // try from 00c2147f to 00c21481 has its CatchHandler @ 00c21512 */
    (**(code **)(*plVar1 + 0x28))
              (plVar1,*(long *)(pwVar5 + 0xe8),*(long *)(pwVar5 + 0xe8) == 0,pwVar5,uVar4,param_1);
    if (extraout_DL != '\0') {
                    /* try { // try from 00c21496 to 00c2149a has its CatchHandler @ 00c2150d */
      wios::s_basic_ios__clear_c1c9b0
                ((wios *)(this + *(long *)(*(long *)this + -0x18)),
                 *(uint *)((wios *)(this + *(long *)(*(long *)this + -0x18)) + 0x20) | 1);
    }
  }
  sentry::~sentry(local_48);
  if (local_30 == *(long *)(in_FS_OFFSET + 0x28)) {
    return this;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ==== entry=00c21590 orig=FUN_00c21590 size=5 name=operator<< ====

/* std::wostream::TEMPNAMEPLACEHOLDERVALUE(long long) */

wostream * __thiscall std::wostream::operator<<(wostream *this,longlong param_1)

{
  long *plVar1;
  long *plVar2;
  long lVar3;
  undefined4 uVar4;
  char extraout_DL;
  wostream *pwVar5;
  long in_FS_OFFSET;
  sentry asStack_48 [24];
  long lStack_30;
  
  lStack_30 = *(long *)(in_FS_OFFSET + 0x28);
  sentry::sentry(asStack_48,this);
  if (asStack_48[0] != (sentry)0x0) {
    pwVar5 = this + *(long *)(*(long *)this + -0x18);
    plVar1 = *(long **)(pwVar5 + 0xf8);
    if (plVar1 == (long *)0x0) {
                    /* WARNING: Subroutine does not return */
      __throw_bad_cast();
    }
    if (pwVar5[0xe4] == (wostream)0x0) {
      plVar2 = *(long **)(pwVar5 + 0xf0);
      if (plVar2 == (long *)0x0) {
                    /* WARNING: Subroutine does not return */
        __throw_bad_cast();
      }
      uVar4 = (**(code **)(*plVar2 + 0x50))(plVar2,0x20);
      *(undefined4 *)(pwVar5 + 0xe0) = uVar4;
      lVar3 = *(long *)this;
      pwVar5[0xe4] = (wostream)0x1;
      pwVar5 = this + *(long *)(lVar3 + -0x18);
    }
    else {
      uVar4 = *(undefined4 *)(pwVar5 + 0xe0);
    }
    (**(code **)(*plVar1 + 0x28))
              (plVar1,*(long *)(pwVar5 + 0xe8),*(long *)(pwVar5 + 0xe8) == 0,pwVar5,uVar4,param_1);
    if (extraout_DL != '\0') {
      wios::s_basic_ios__clear_c1c9b0
                ((wios *)(this + *(long *)(*(long *)this + -0x18)),
                 *(uint *)((wios *)(this + *(long *)(*(long *)this + -0x18)) + 0x20) | 1);
    }
  }
  sentry::~sentry(asStack_48);
  if (lStack_30 == *(long *)(in_FS_OFFSET + 0x28)) {
    return this;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ==== entry=00c215a0 orig=FUN_00c215a0 size=264 name=_M_insert<unsigned_long_long> ====

/* std::wostream& std::wostream::_M_insert<unsigned long long>(unsigned long long) */

wostream * __thiscall std::wostream::_M_insert<unsigned_long_long>(wostream *this,ulonglong param_1)

{
  long *plVar1;
  long *plVar2;
  long lVar3;
  undefined4 uVar4;
  char extraout_DL;
  wostream *pwVar5;
  long in_FS_OFFSET;
  sentry local_48 [24];
  long local_30;
  
  local_30 = *(long *)(in_FS_OFFSET + 0x28);
  sentry::sentry(local_48,this);
  if (local_48[0] != (sentry)0x0) {
    pwVar5 = this + *(long *)(*(long *)this + -0x18);
    plVar1 = *(long **)(pwVar5 + 0xf8);
    if (plVar1 == (long *)0x0) {
                    /* WARNING: Subroutine does not return */
      __throw_bad_cast();
    }
    if (pwVar5[0xe4] == (wostream)0x0) {
      plVar2 = *(long **)(pwVar5 + 0xf0);
      if (plVar2 == (long *)0x0) {
                    /* WARNING: Subroutine does not return */
        __throw_bad_cast();
      }
                    /* try { // try from 00c2167c to 00c216ac has its CatchHandler @ 00c216b2 */
      uVar4 = (**(code **)(*plVar2 + 0x50))(plVar2,0x20);
      *(undefined4 *)(pwVar5 + 0xe0) = uVar4;
      lVar3 = *(long *)this;
      pwVar5[0xe4] = (wostream)0x1;
      pwVar5 = this + *(long *)(lVar3 + -0x18);
    }
    else {
      uVar4 = *(undefined4 *)(pwVar5 + 0xe0);
    }
                    /* try { // try from 00c2161f to 00c21621 has its CatchHandler @ 00c216b2 */
    (**(code **)(*plVar1 + 0x30))
              (plVar1,*(long *)(pwVar5 + 0xe8),*(long *)(pwVar5 + 0xe8) == 0,pwVar5,uVar4,param_1);
    if (extraout_DL != '\0') {
                    /* try { // try from 00c21636 to 00c2163a has its CatchHandler @ 00c216ad */
      wios::s_basic_ios__clear_c1c9b0
                ((wios *)(this + *(long *)(*(long *)this + -0x18)),
                 *(uint *)((wios *)(this + *(long *)(*(long *)this + -0x18)) + 0x20) | 1);
    }
  }
  sentry::~sentry(local_48);
  if (local_30 == *(long *)(in_FS_OFFSET + 0x28)) {
    return this;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ==== entry=00c21730 orig=FUN_00c21730 size=5 name=operator<< ====

/* std::wostream::TEMPNAMEPLACEHOLDERVALUE(unsigned long long) */

wostream * __thiscall std::wostream::operator<<(wostream *this,ulonglong param_1)

{
  long *plVar1;
  long *plVar2;
  long lVar3;
  undefined4 uVar4;
  char extraout_DL;
  wostream *pwVar5;
  long in_FS_OFFSET;
  sentry asStack_48 [24];
  long lStack_30;
  
  lStack_30 = *(long *)(in_FS_OFFSET + 0x28);
  sentry::sentry(asStack_48,this);
  if (asStack_48[0] != (sentry)0x0) {
    pwVar5 = this + *(long *)(*(long *)this + -0x18);
    plVar1 = *(long **)(pwVar5 + 0xf8);
    if (plVar1 == (long *)0x0) {
                    /* WARNING: Subroutine does not return */
      __throw_bad_cast();
    }
    if (pwVar5[0xe4] == (wostream)0x0) {
      plVar2 = *(long **)(pwVar5 + 0xf0);
      if (plVar2 == (long *)0x0) {
                    /* WARNING: Subroutine does not return */
        __throw_bad_cast();
      }
      uVar4 = (**(code **)(*plVar2 + 0x50))(plVar2,0x20);
      *(undefined4 *)(pwVar5 + 0xe0) = uVar4;
      lVar3 = *(long *)this;
      pwVar5[0xe4] = (wostream)0x1;
      pwVar5 = this + *(long *)(lVar3 + -0x18);
    }
    else {
      uVar4 = *(undefined4 *)(pwVar5 + 0xe0);
    }
    (**(code **)(*plVar1 + 0x30))
              (plVar1,*(long *)(pwVar5 + 0xe8),*(long *)(pwVar5 + 0xe8) == 0,pwVar5,uVar4,param_1);
    if (extraout_DL != '\0') {
      wios::s_basic_ios__clear_c1c9b0
                ((wios *)(this + *(long *)(*(long *)this + -0x18)),
                 *(uint *)((wios *)(this + *(long *)(*(long *)this + -0x18)) + 0x20) | 1);
    }
  }
  sentry::~sentry(asStack_48);
  if (lStack_30 == *(long *)(in_FS_OFFSET + 0x28)) {
    return this;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ==== entry=00c21740 orig=FUN_00c21740 size=269 name=_M_insert<double> ====

/* std::wostream& std::wostream::_M_insert<double>(double) */

wostream * __thiscall std::wostream::_M_insert<double>(wostream *this,double param_1)

{
  long *plVar1;
  long *plVar2;
  long lVar3;
  undefined4 uVar4;
  char extraout_DL;
  wostream *pwVar5;
  long in_FS_OFFSET;
  sentry local_48 [24];
  long local_30;
  
  local_30 = *(long *)(in_FS_OFFSET + 0x28);
  sentry::sentry(local_48,this);
  if (local_48[0] != (sentry)0x0) {
    pwVar5 = this + *(long *)(*(long *)this + -0x18);
    plVar1 = *(long **)(pwVar5 + 0xf8);
    if (plVar1 == (long *)0x0) {
                    /* WARNING: Subroutine does not return */
      __throw_bad_cast();
    }
    if (pwVar5[0xe4] == (wostream)0x0) {
      plVar2 = *(long **)(pwVar5 + 0xf0);
      if (plVar2 == (long *)0x0) {
                    /* WARNING: Subroutine does not return */
        __throw_bad_cast();
      }
                    /* try { // try from 00c21824 to 00c21854 has its CatchHandler @ 00c2185a */
      uVar4 = (**(code **)(*plVar2 + 0x50))(plVar2,0x20);
      *(undefined4 *)(pwVar5 + 0xe0) = uVar4;
      lVar3 = *(long *)this;
      pwVar5[0xe4] = (wostream)0x1;
      pwVar5 = this + *(long *)(lVar3 + -0x18);
    }
    else {
      uVar4 = *(undefined4 *)(pwVar5 + 0xe0);
    }
                    /* try { // try from 00c217c6 to 00c217c8 has its CatchHandler @ 00c2185a */
    (**(code **)(*plVar1 + 0x38))
              (param_1,plVar1,*(long *)(pwVar5 + 0xe8),*(long *)(pwVar5 + 0xe8) == 0,pwVar5,uVar4);
    if (extraout_DL != '\0') {
                    /* try { // try from 00c217dd to 00c217e1 has its CatchHandler @ 00c21855 */
      wios::s_basic_ios__clear_c1c9b0
                ((wios *)(this + *(long *)(*(long *)this + -0x18)),
                 *(uint *)((wios *)(this + *(long *)(*(long *)this + -0x18)) + 0x20) | 1);
    }
  }
  sentry::~sentry(local_48);
  if (local_30 == *(long *)(in_FS_OFFSET + 0x28)) {
    return this;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ==== entry=00c218e0 orig=FUN_00c218e0 size=5 name=operator<< ====

/* std::wostream::TEMPNAMEPLACEHOLDERVALUE(double) */

wostream * __thiscall std::wostream::operator<<(wostream *this,double param_1)

{
  long *plVar1;
  long *plVar2;
  long lVar3;
  undefined4 uVar4;
  char extraout_DL;
  wostream *pwVar5;
  long in_FS_OFFSET;
  sentry asStack_48 [24];
  long lStack_30;
  
  lStack_30 = *(long *)(in_FS_OFFSET + 0x28);
  sentry::sentry(asStack_48,this);
  if (asStack_48[0] != (sentry)0x0) {
    pwVar5 = this + *(long *)(*(long *)this + -0x18);
    plVar1 = *(long **)(pwVar5 + 0xf8);
    if (plVar1 == (long *)0x0) {
                    /* WARNING: Subroutine does not return */
      __throw_bad_cast();
    }
    if (pwVar5[0xe4] == (wostream)0x0) {
      plVar2 = *(long **)(pwVar5 + 0xf0);
      if (plVar2 == (long *)0x0) {
                    /* WARNING: Subroutine does not return */
        __throw_bad_cast();
      }
      uVar4 = (**(code **)(*plVar2 + 0x50))(plVar2,0x20);
      *(undefined4 *)(pwVar5 + 0xe0) = uVar4;
      lVar3 = *(long *)this;
      pwVar5[0xe4] = (wostream)0x1;
      pwVar5 = this + *(long *)(lVar3 + -0x18);
    }
    else {
      uVar4 = *(undefined4 *)(pwVar5 + 0xe0);
    }
    (**(code **)(*plVar1 + 0x38))
              (param_1,plVar1,*(long *)(pwVar5 + 0xe8),*(long *)(pwVar5 + 0xe8) == 0,pwVar5,uVar4);
    if (extraout_DL != '\0') {
      wios::s_basic_ios__clear_c1c9b0
                ((wios *)(this + *(long *)(*(long *)this + -0x18)),
                 *(uint *)((wios *)(this + *(long *)(*(long *)this + -0x18)) + 0x20) | 1);
    }
  }
  sentry::~sentry(asStack_48);
  if (lStack_30 == *(long *)(in_FS_OFFSET + 0x28)) {
    return this;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ==== entry=00c218f0 orig=FUN_00c218f0 size=9 name=operator<< ====

/* std::wostream::TEMPNAMEPLACEHOLDERVALUE(float) */

void __thiscall std::wostream::operator<<(wostream *this,float param_1)

{
  _M_insert<double>(this,(double)param_1);
  return;
}


// ==== entry=00c21900 orig=FUN_00c21900 size=276 name=_M_insert<long_double> ====

/* std::wostream& std::wostream::_M_insert<long double>(long double) */

wostream * std::wostream::_M_insert<long_double>(longdouble param_1)

{
  long *plVar1;
  long *plVar2;
  long lVar3;
  undefined4 uVar4;
  wostream *pwVar5;
  undefined8 extraout_RDX;
  wostream *in_RDI;
  undefined8 in_R9;
  long in_FS_OFFSET;
  undefined6 in_stack_00000012;
  sentry local_48 [24];
  long local_30;
  
  local_30 = *(long *)(in_FS_OFFSET + 0x28);
  sentry::sentry(local_48,in_RDI);
  if (local_48[0] != (sentry)0x0) {
    pwVar5 = in_RDI + *(long *)(*(long *)in_RDI + -0x18);
    plVar1 = *(long **)(pwVar5 + 0xf8);
    if (plVar1 == (long *)0x0) {
                    /* WARNING: Subroutine does not return */
      __throw_bad_cast();
    }
    if (pwVar5[0xe4] == (wostream)0x0) {
      plVar2 = *(long **)(pwVar5 + 0xf0);
      if (plVar2 == (long *)0x0) {
                    /* WARNING: Subroutine does not return */
        __throw_bad_cast();
      }
                    /* try { // try from 00c219e4 to 00c21a19 has its CatchHandler @ 00c21a1f */
      uVar4 = (**(code **)(*plVar2 + 0x50))(plVar2,0x20);
      lVar3 = *(long *)in_RDI;
      pwVar5[0xe4] = (wostream)0x1;
      *(undefined4 *)(pwVar5 + 0xe0) = uVar4;
      pwVar5 = in_RDI + *(long *)(lVar3 + -0x18);
    }
    else {
      uVar4 = *(undefined4 *)(pwVar5 + 0xe0);
    }
                    /* try { // try from 00c21985 to 00c21987 has its CatchHandler @ 00c21a1f */
    (**(code **)(*plVar1 + 0x40))
              (plVar1,*(long *)(pwVar5 + 0xe8),*(long *)(pwVar5 + 0xe8) == 0,pwVar5,uVar4,in_R9,
               param_1._0_8_);
    if ((char)extraout_RDX != '\0') {
                    /* try { // try from 00c2199e to 00c219a2 has its CatchHandler @ 00c21a1a */
      wios::s_basic_ios__clear_c1c9b0
                ((wios *)(in_RDI + *(long *)(*(long *)in_RDI + -0x18)),
                 *(uint *)((wios *)(in_RDI + *(long *)(*(long *)in_RDI + -0x18)) + 0x20) | 1,
                 extraout_RDX,CONCAT62(in_stack_00000012,param_1._8_2_));
    }
  }
  sentry::~sentry(local_48);
  if (local_30 == *(long *)(in_FS_OFFSET + 0x28)) {
    return in_RDI;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ==== entry=00c21aa0 orig=FUN_00c21aa0 size=5 name=operator<< ====

/* std::wostream::TEMPNAMEPLACEHOLDERVALUE(long double) */

wostream * __thiscall std::wostream::operator<<(wostream *this,longdouble param_1)

{
  long *plVar1;
  long *plVar2;
  long lVar3;
  undefined4 uVar4;
  wostream *pwVar5;
  undefined8 extraout_RDX;
  undefined8 in_R9;
  long in_FS_OFFSET;
  undefined6 in_stack_00000012;
  sentry asStack_48 [24];
  long lStack_30;
  
  lStack_30 = *(long *)(in_FS_OFFSET + 0x28);
  sentry::sentry(asStack_48,this);
  if (asStack_48[0] != (sentry)0x0) {
    pwVar5 = this + *(long *)(*(long *)this + -0x18);
    plVar1 = *(long **)(pwVar5 + 0xf8);
    if (plVar1 == (long *)0x0) {
                    /* WARNING: Subroutine does not return */
      __throw_bad_cast();
    }
    if (pwVar5[0xe4] == (wostream)0x0) {
      plVar2 = *(long **)(pwVar5 + 0xf0);
      if (plVar2 == (long *)0x0) {
                    /* WARNING: Subroutine does not return */
        __throw_bad_cast();
      }
      uVar4 = (**(code **)(*plVar2 + 0x50))(plVar2,0x20);
      lVar3 = *(long *)this;
      pwVar5[0xe4] = (wostream)0x1;
      *(undefined4 *)(pwVar5 + 0xe0) = uVar4;
      pwVar5 = this + *(long *)(lVar3 + -0x18);
    }
    else {
      uVar4 = *(undefined4 *)(pwVar5 + 0xe0);
    }
    (**(code **)(*plVar1 + 0x40))
              (plVar1,*(long *)(pwVar5 + 0xe8),*(long *)(pwVar5 + 0xe8) == 0,pwVar5,uVar4,in_R9,
               param_1._0_8_);
    if ((char)extraout_RDX != '\0') {
      wios::s_basic_ios__clear_c1c9b0
                ((wios *)(this + *(long *)(*(long *)this + -0x18)),
                 *(uint *)((wios *)(this + *(long *)(*(long *)this + -0x18)) + 0x20) | 1,
                 extraout_RDX,CONCAT62(in_stack_00000012,param_1._8_2_));
    }
  }
  sentry::~sentry(asStack_48);
  if (lStack_30 == *(long *)(in_FS_OFFSET + 0x28)) {
    return this;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ==== entry=00c21ab0 orig=FUN_00c21ab0 size=264 name=_M_insert<void_const*> ====

/* std::wostream& std::wostream::_M_insert<void const*>(void const*) */

wostream * __thiscall std::wostream::_M_insert<void_const*>(wostream *this,void *param_1)

{
  long *plVar1;
  long *plVar2;
  long lVar3;
  undefined4 uVar4;
  char extraout_DL;
  wostream *pwVar5;
  long in_FS_OFFSET;
  sentry local_48 [24];
  long local_30;
  
  local_30 = *(long *)(in_FS_OFFSET + 0x28);
  sentry::sentry(local_48,this);
  if (local_48[0] != (sentry)0x0) {
    pwVar5 = this + *(long *)(*(long *)this + -0x18);
    plVar1 = *(long **)(pwVar5 + 0xf8);
    if (plVar1 == (long *)0x0) {
                    /* WARNING: Subroutine does not return */
      __throw_bad_cast();
    }
    if (pwVar5[0xe4] == (wostream)0x0) {
      plVar2 = *(long **)(pwVar5 + 0xf0);
      if (plVar2 == (long *)0x0) {
                    /* WARNING: Subroutine does not return */
        __throw_bad_cast();
      }
                    /* try { // try from 00c21b8c to 00c21bbc has its CatchHandler @ 00c21bc2 */
      uVar4 = (**(code **)(*plVar2 + 0x50))(plVar2,0x20);
      *(undefined4 *)(pwVar5 + 0xe0) = uVar4;
      lVar3 = *(long *)this;
      pwVar5[0xe4] = (wostream)0x1;
      pwVar5 = this + *(long *)(lVar3 + -0x18);
    }
    else {
      uVar4 = *(undefined4 *)(pwVar5 + 0xe0);
    }
                    /* try { // try from 00c21b2f to 00c21b31 has its CatchHandler @ 00c21bc2 */
    (**(code **)(*plVar1 + 0x48))
              (plVar1,*(long *)(pwVar5 + 0xe8),*(long *)(pwVar5 + 0xe8) == 0,pwVar5,uVar4,param_1);
    if (extraout_DL != '\0') {
                    /* try { // try from 00c21b46 to 00c21b4a has its CatchHandler @ 00c21bbd */
      wios::s_basic_ios__clear_c1c9b0
                ((wios *)(this + *(long *)(*(long *)this + -0x18)),
                 *(uint *)((wios *)(this + *(long *)(*(long *)this + -0x18)) + 0x20) | 1);
    }
  }
  sentry::~sentry(local_48);
  if (local_30 == *(long *)(in_FS_OFFSET + 0x28)) {
    return this;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ==== entry=00c21c40 orig=FUN_00c21c40 size=5 name=operator<< ====

/* std::wostream::TEMPNAMEPLACEHOLDERVALUE(void const*) */

wostream * __thiscall std::wostream::operator<<(wostream *this,void *param_1)

{
  long *plVar1;
  long *plVar2;
  long lVar3;
  undefined4 uVar4;
  char extraout_DL;
  wostream *pwVar5;
  long in_FS_OFFSET;
  sentry asStack_48 [24];
  long lStack_30;
  
  lStack_30 = *(long *)(in_FS_OFFSET + 0x28);
  sentry::sentry(asStack_48,this);
  if (asStack_48[0] != (sentry)0x0) {
    pwVar5 = this + *(long *)(*(long *)this + -0x18);
    plVar1 = *(long **)(pwVar5 + 0xf8);
    if (plVar1 == (long *)0x0) {
                    /* WARNING: Subroutine does not return */
      __throw_bad_cast();
    }
    if (pwVar5[0xe4] == (wostream)0x0) {
      plVar2 = *(long **)(pwVar5 + 0xf0);
      if (plVar2 == (long *)0x0) {
                    /* WARNING: Subroutine does not return */
        __throw_bad_cast();
      }
      uVar4 = (**(code **)(*plVar2 + 0x50))(plVar2,0x20);
      *(undefined4 *)(pwVar5 + 0xe0) = uVar4;
      lVar3 = *(long *)this;
      pwVar5[0xe4] = (wostream)0x1;
      pwVar5 = this + *(long *)(lVar3 + -0x18);
    }
    else {
      uVar4 = *(undefined4 *)(pwVar5 + 0xe0);
    }
    (**(code **)(*plVar1 + 0x48))
              (plVar1,*(long *)(pwVar5 + 0xe8),*(long *)(pwVar5 + 0xe8) == 0,pwVar5,uVar4,param_1);
    if (extraout_DL != '\0') {
      wios::s_basic_ios__clear_c1c9b0
                ((wios *)(this + *(long *)(*(long *)this + -0x18)),
                 *(uint *)((wios *)(this + *(long *)(*(long *)this + -0x18)) + 0x20) | 1);
    }
  }
  sentry::~sentry(asStack_48);
  if (lStack_30 == *(long *)(in_FS_OFFSET + 0x28)) {
    return this;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ==== entry=00c21c50 name=FUN_00c21c50 size=4 ====

void FUN_00c21c50(undefined8 *param_1,undefined8 param_2)

{
  *param_1 = param_2;
  return;
}


// ==== entry=00c21c60 name=FUN_00c21c60 size=5 ====

void FUN_00c21c60(long param_1,undefined8 param_2)

{
  *(undefined8 *)(param_1 + 8) = param_2;
  return;
}


// ==== entry=00c21c70 name=FUN_00c21c70 size=4 ====

undefined8 FUN_00c21c70(undefined8 *param_1)

{
  return *param_1;
}


// ==== entry=00c21c80 name=FUN_00c21c80 size=5 ====

long FUN_00c21c80(long param_1)

{
  return param_1 + 0x10;
}


// ==== entry=00c21c90 name=FUN_00c21c90 size=5 ====

long FUN_00c21c90(long param_1)

{
  return param_1 + 0x10;
}


// ==== entry=00c21ca0 name=FUN_00c21ca0 size=5 ====

void FUN_00c21ca0(long param_1,undefined8 param_2)

{
  *(undefined8 *)(param_1 + 0x10) = param_2;
  return;
}


// ==== entry=00c21cb0 name=FUN_00c21cb0 size=15 ====

void FUN_00c21cb0(long *param_1,long param_2)

{
  param_1[1] = param_2;
  *(undefined4 *)(*param_1 + param_2 * 4) = 0;
  return;
}


// ==== entry=00c21cc0 name=FUN_00c21cc0 size=11 ====

undefined8 FUN_00c21cc0(long *param_1)

{
  return CONCAT71((int7)((ulong)(param_1 + 2) >> 8),(long *)*param_1 == param_1 + 2);
}


// ==== entry=00c21cd0 name=FUN_00c21cd0 size=86 ====

void FUN_00c21cd0(undefined8 param_1,ulong *param_2,ulong param_3)

{
  ulong uVar1;
  
  uVar1 = *param_2;
  if (0x1fffffffffffffff < uVar1) {
                    /* WARNING: Subroutine does not return */
    std::__throw_length_error("basic_string::_M_create");
  }
  if ((param_3 < uVar1) && (param_3 = param_3 * 2, uVar1 < param_3)) {
    if (0x1fffffffffffffff < param_3) {
      *param_2 = 0x1fffffffffffffff;
      operator_new(0x8000000000000000);
      return;
    }
    *param_2 = param_3;
    uVar1 = param_3;
  }
  operator_new(uVar1 * 4 + 4);
  return;
}


// ==== entry=00c21d30 name=FUN_00c21d30 size=21 ====

void FUN_00c21d30(undefined8 *param_1)

{
  if ((undefined8 *)*param_1 != param_1 + 2) {
    operator_delete((undefined8 *)*param_1);
    return;
  }
  return;
}


// ==== entry=00c21d50 name=FUN_00c21d50 size=8 ====

void FUN_00c21d50(undefined8 *param_1)

{
  operator_delete((void *)*param_1);
  return;
}


// ==== entry=00c21d60 name=FUN_00c21d60 size=105 ====

void FUN_00c21d60(undefined8 *param_1,ulong param_2,wchar_t param_3)

{
  wchar_t *__s;
  size_t local_20 [2];
  
  local_20[0] = param_2;
  if (param_2 < 4) {
    __s = (wchar_t *)*param_1;
  }
  else {
    __s = (wchar_t *)FUN_00c21cd0(param_1,local_20,0);
    *param_1 = __s;
    param_1[2] = local_20[0];
  }
  if (local_20[0] != 0) {
    if (local_20[0] == 1) {
      *__s = param_3;
    }
    else {
      wmemset(__s,param_3,local_20[0]);
      __s = (wchar_t *)*param_1;
    }
  }
  param_1[1] = local_20[0];
  __s[local_20[0]] = L'\0';
  return;
}


// ==== entry=00c21de0 orig=FUN_00c21de0 size=5 name=thunk_FUN_00c21d60 ====

void thunk_FUN_00c21d60(undefined8 *param_1,ulong param_2,wchar_t param_3)

{
  wchar_t *__s;
  size_t asStack_20 [2];
  
  asStack_20[0] = param_2;
  if (param_2 < 4) {
    __s = (wchar_t *)*param_1;
  }
  else {
    __s = (wchar_t *)FUN_00c21cd0(param_1,asStack_20,0);
    *param_1 = __s;
    param_1[2] = asStack_20[0];
  }
  if (asStack_20[0] != 0) {
    if (asStack_20[0] == 1) {
      *__s = param_3;
    }
    else {
      wmemset(__s,param_3,asStack_20[0]);
      __s = (wchar_t *)*param_1;
    }
  }
  param_1[1] = asStack_20[0];
  __s[asStack_20[0]] = L'\0';
  return;
}


// ==== entry=00c21df0 name=FUN_00c21df0 size=4 ====

undefined8 FUN_00c21df0(undefined8 param_1)

{
  return param_1;
}


// ==== entry=00c21e00 name=FUN_00c21e00 size=4 ====

undefined8 FUN_00c21e00(undefined8 param_1)

{
  return param_1;
}


// ==== entry=00c21e10 name=FUN_00c21e10 size=34 ====

void FUN_00c21e10(long param_1,ulong param_2,undefined8 param_3)

{
  if (param_2 <= *(ulong *)(param_1 + 8)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  std::__throw_out_of_range_fmt
            ("%s: __pos (which is %zu) > this->size() (which is %zu)",param_3,param_2);
}


// ==== entry=00c21e40 name=FUN_00c21e40 size=32 ====

void FUN_00c21e40(long param_1,long param_2,ulong param_3,char *param_4)

{
  if (param_3 <= (ulong)((param_2 + 0x1fffffffffffffff) - *(long *)(param_1 + 8))) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  std::__throw_length_error(param_4);
}


// ==== entry=00c21e60 name=FUN_00c21e60 size=15 ====

ulong FUN_00c21e60(long param_1,long param_2,ulong param_3)

{
  ulong uVar1;
  
  uVar1 = *(long *)(param_1 + 8) - param_2;
  if (param_3 < uVar1) {
    uVar1 = param_3;
  }
  return uVar1;
}


// ==== entry=00c21e70 name=FUN_00c21e70 size=28 ====

undefined8 FUN_00c21e70(ulong *param_1,ulong param_2)

{
  ulong uVar1;
  undefined8 uVar2;
  
  uVar2 = 1;
  if (*param_1 <= param_2) {
    uVar1 = *param_1 + param_1[1] * 4;
    uVar2 = CONCAT71((int7)(uVar1 >> 8),uVar1 < param_2);
  }
  return uVar2;
}


// ==== entry=00c21e90 name=FUN_00c21e90 size=22 ====

void FUN_00c21e90(wchar_t *param_1,wchar_t *param_2,size_t param_3)

{
  if (param_3 == 1) {
    *param_1 = *param_2;
    return;
  }
  if (param_3 == 0) {
    return;
  }
  wmemcpy(param_1,param_2,param_3);
  return;
}


// ==== entry=00c21eb0 name=FUN_00c21eb0 size=22 ====

void FUN_00c21eb0(wchar_t *param_1,wchar_t *param_2,size_t param_3)

{
  if (param_3 == 1) {
    *param_1 = *param_2;
    return;
  }
  if (param_3 == 0) {
    return;
  }
  wmemmove(param_1,param_2,param_3);
  return;
}


// ==== entry=00c21ed0 name=FUN_00c21ed0 size=27 ====

void FUN_00c21ed0(wchar_t *param_1,size_t param_2,wchar_t param_3)

{
  if (param_2 == 1) {
    *param_1 = param_3;
    return;
  }
  if (param_2 == 0) {
    return;
  }
  wmemset(param_1,param_3,param_2);
  return;
}


// ==== entry=00c21f00 name=FUN_00c21f00 size=29 ====

void FUN_00c21f00(wchar_t *param_1,wchar_t *param_2,long param_3)

{
  size_t __n;
  
  __n = param_3 - (long)param_2 >> 2;
  if (__n == 1) {
    *param_1 = *param_2;
    return;
  }
  if (__n == 0) {
    return;
  }
  wmemcpy(param_1,param_2,__n);
  return;
}


// ==== entry=00c21f30 name=FUN_00c21f30 size=29 ====

void FUN_00c21f30(wchar_t *param_1,wchar_t *param_2,long param_3)

{
  size_t __n;
  
  __n = param_3 - (long)param_2 >> 2;
  if (__n == 1) {
    *param_1 = *param_2;
    return;
  }
  if (__n == 0) {
    return;
  }
  wmemcpy(param_1,param_2,__n);
  return;
}


// ==== entry=00c21f60 name=FUN_00c21f60 size=29 ====

void FUN_00c21f60(wchar_t *param_1,wchar_t *param_2,long param_3)

{
  size_t __n;
  
  __n = param_3 - (long)param_2 >> 2;
  if (__n == 1) {
    *param_1 = *param_2;
    return;
  }
  if (__n == 0) {
    return;
  }
  wmemcpy(param_1,param_2,__n);
  return;
}


// ==== entry=00c21f90 name=FUN_00c21f90 size=29 ====

void FUN_00c21f90(wchar_t *param_1,wchar_t *param_2,long param_3)

{
  size_t __n;
  
  __n = param_3 - (long)param_2 >> 2;
  if (__n == 1) {
    *param_1 = *param_2;
    return;
  }
  if (__n == 0) {
    return;
  }
  wmemcpy(param_1,param_2,__n);
  return;
}


// ==== entry=00c21fc0 name=FUN_00c21fc0 size=31 ====

ulong FUN_00c21fc0(long param_1,long param_2)

{
  ulong uVar1;
  ulong uVar2;
  
  uVar2 = param_1 - param_2;
  uVar1 = 0x7fffffff;
  if (((long)uVar2 < 0x80000000) && (uVar1 = 0x80000000, -0x80000001 < (long)uVar2)) {
    uVar1 = uVar2 & 0xffffffff;
  }
  return uVar1;
}


// ==== entry=00c21fe0 name=FUN_00c21fe0 size=223 ====

void FUN_00c21fe0(long *param_1,long *param_2)

{
  ulong __n;
  wchar_t *__s1;
  ulong uVar1;
  long in_FS_OFFSET;
  ulong local_38;
  long local_30;
  
  local_30 = *(long *)(in_FS_OFFSET + 0x28);
  if (param_1 != param_2) {
    __s1 = (wchar_t *)*param_1;
    __n = param_2[1];
    if ((wchar_t *)(param_1 + 2) == __s1) {
      uVar1 = 3;
    }
    else {
      uVar1 = param_1[2];
    }
    if (uVar1 < __n) {
      local_38 = __n;
      __s1 = (wchar_t *)FUN_00c21cd0(param_1,&local_38);
      if ((wchar_t *)(param_1 + 2) != (wchar_t *)*param_1) {
        operator_delete((wchar_t *)*param_1);
      }
      *param_1 = (long)__s1;
      param_1[2] = local_38;
    }
    if (__n != 0) {
      if (__n == 1) {
        *__s1 = *(wchar_t *)*param_2;
      }
      else {
        wmemcpy(__s1,(wchar_t *)*param_2,__n);
        __s1 = (wchar_t *)*param_1;
      }
    }
    param_1[1] = __n;
    __s1[__n] = L'\0';
  }
  if (local_30 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


// ==== entry=00c220e0 name=FUN_00c220e0 size=323 ====

void FUN_00c220e0(long *param_1,size_t param_2,long param_3,wchar_t *param_4,size_t param_5)

{
  wchar_t *__s2;
  wchar_t *__s1;
  long *plVar1;
  long lVar2;
  size_t __n;
  long in_FS_OFFSET;
  long local_48;
  long local_40;
  
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  __n = param_1[1] - (param_2 + param_3);
  local_48 = (param_5 - param_3) + param_1[1];
  if (param_1 + 2 == (long *)*param_1) {
    lVar2 = 3;
  }
  else {
    lVar2 = param_1[2];
  }
  __s1 = (wchar_t *)FUN_00c21cd0(param_1,&local_48,lVar2);
  if (param_2 != 0) {
    if (param_2 == 1) {
      *__s1 = *(wchar_t *)*param_1;
    }
    else {
      wmemcpy(__s1,(wchar_t *)*param_1,param_2);
    }
  }
  if ((param_4 != (wchar_t *)0x0) && (param_5 != 0)) {
    if (param_5 == 1) {
      __s1[param_2] = *param_4;
    }
    else {
      wmemcpy(__s1 + param_2,param_4,param_5);
    }
  }
  plVar1 = (long *)*param_1;
  if (__n != 0) {
    __s2 = (wchar_t *)((long)plVar1 + (param_2 + param_3) * 4);
    if (__n == 1) {
      __s1[param_2 + param_5] = *__s2;
    }
    else {
      wmemcpy(__s1 + param_2 + param_5,__s2,__n);
      plVar1 = (long *)*param_1;
    }
  }
  if (param_1 + 2 != plVar1) {
    operator_delete(plVar1);
  }
  *param_1 = (long)__s1;
  param_1[2] = local_48;
  if (local_40 == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ==== entry=00c22240 name=FUN_00c22240 size=93 ====

void FUN_00c22240(long *param_1,long param_2,long param_3)

{
  wchar_t *__s2;
  wchar_t *__s1;
  long lVar1;
  size_t __n;
  long lVar2;
  
  lVar1 = param_1[1];
  lVar2 = *param_1;
  __n = lVar1 - (param_2 + param_3);
  if ((__n != 0) && (param_3 != 0)) {
    __s2 = (wchar_t *)(lVar2 + (param_2 + param_3) * 4);
    __s1 = (wchar_t *)(lVar2 + param_2 * 4);
    if (__n == 1) {
      *__s1 = *__s2;
    }
    else {
      wmemmove(__s1,__s2,__n);
      lVar2 = *param_1;
      lVar1 = param_1[1];
    }
  }
  param_1[1] = lVar1 - param_3;
  *(undefined4 *)(lVar2 + (lVar1 - param_3) * 4) = 0;
  return;
}


// ==== entry=00c222b0 name=FUN_00c222b0 size=23 ====

void FUN_00c222b0(long *param_1)

{
  param_1[1] = 0;
  *param_1 = (long)(param_1 + 2);
  *(undefined4 *)(param_1 + 2) = 0;
  return;
}


// ==== entry=00c222d0 name=FUN_00c222d0 size=23 ====

void FUN_00c222d0(long *param_1)

{
  param_1[1] = 0;
  *param_1 = (long)(param_1 + 2);
  *(undefined4 *)(param_1 + 2) = 0;
  return;
}


// ==== entry=00c222f0 name=FUN_00c222f0 size=12 ====

void FUN_00c222f0(long *param_1)

{
  *param_1 = (long)(param_1 + 2);
  FUN_00c21d60();
  return;
}


// ==== entry=00c22300 name=FUN_00c22300 size=88 ====

void FUN_00c22300(undefined8 *param_1,undefined8 *param_2)

{
  wchar_t *__s2;
  
  __s2 = (wchar_t *)(param_2 + 2);
  *param_1 = param_1 + 2;
  if (__s2 == (wchar_t *)*param_2) {
    wmemcpy((wchar_t *)(param_1 + 2),__s2,4);
  }
  else {
    *param_1 = (wchar_t *)*param_2;
    param_1[2] = param_2[2];
  }
  param_1[1] = param_2[1];
  *param_2 = __s2;
  param_2[1] = 0;
  *(undefined4 *)(param_2 + 2) = 0;
  return;
}


// ==== entry=00c22360 name=FUN_00c22360 size=117 ====

void FUN_00c22360(undefined8 *param_1,undefined8 *param_2)

{
  wchar_t *__s2;
  
  __s2 = (wchar_t *)(param_2 + 2);
  *param_1 = param_1 + 2;
  if (__s2 != (wchar_t *)*param_2) {
    *param_1 = (wchar_t *)*param_2;
    param_1[1] = param_2[1];
    param_1[2] = param_2[2];
    *param_2 = __s2;
    param_2[1] = 0;
    *(undefined4 *)(param_2 + 2) = 0;
    return;
  }
  wmemcpy((wchar_t *)(param_1 + 2),__s2,4);
  param_1[1] = param_2[1];
  param_2[1] = 0;
  *(undefined4 *)*param_2 = 0;
  return;
}


// ==== entry=00c223e0 name=FUN_00c223e0 size=21 ====

void FUN_00c223e0(undefined8 *param_1)

{
  if ((undefined8 *)*param_1 != param_1 + 2) {
    operator_delete((undefined8 *)*param_1);
    return;
  }
  return;
}


// ==== entry=00c22400 name=FUN_00c22400 size=14 ====

undefined8 FUN_00c22400(undefined8 param_1)

{
  FUN_00c21fe0();
  return param_1;
}


// ==== entry=00c22410 name=FUN_00c22410 size=165 ====

undefined8 * FUN_00c22410(undefined8 *param_1,undefined8 *param_2)

{
  wchar_t *pwVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  size_t __n;
  wchar_t *__s2;
  wchar_t *__s1;
  
  pwVar1 = (wchar_t *)(param_2 + 2);
  __s2 = (wchar_t *)*param_2;
  __s1 = (wchar_t *)*param_1;
  __n = param_2[1];
  if (pwVar1 == __s2) {
    if (__n != 0) {
      if (__n == 1) {
        *__s1 = *__s2;
      }
      else {
        wmemcpy(__s1,__s2,__n);
        __s1 = (wchar_t *)*param_1;
        __n = param_2[1];
        __s2 = (wchar_t *)*param_2;
      }
    }
    param_1[1] = __n;
    __s1[__n] = L'\0';
  }
  else {
    uVar2 = param_2[2];
    if (__s1 == (wchar_t *)(param_1 + 2)) {
      *param_1 = __s2;
      param_1[1] = __n;
      param_1[2] = uVar2;
    }
    else {
      uVar3 = param_1[2];
      *param_1 = __s2;
      param_1[1] = __n;
      param_1[2] = uVar2;
      if (__s1 != (wchar_t *)0x0) {
        *param_2 = __s1;
        param_2[2] = uVar3;
        __s2 = __s1;
        goto LAB_00c22458;
      }
    }
    *param_2 = pwVar1;
    __s2 = pwVar1;
  }
LAB_00c22458:
  param_2[1] = 0;
  *__s2 = L'\0';
  return param_1;
}


// ==== entry=00c224c0 name=FUN_00c224c0 size=4 ====

undefined8 FUN_00c224c0(undefined8 *param_1)

{
  return *param_1;
}


// ==== entry=00c224d0 name=FUN_00c224d0 size=4 ====

undefined8 FUN_00c224d0(undefined8 *param_1)

{
  return *param_1;
}


// ==== entry=00c224e0 name=FUN_00c224e0 size=12 ====

long FUN_00c224e0(long *param_1)

{
  return *param_1 + param_1[1] * 4;
}


// ==== entry=00c224f0 name=FUN_00c224f0 size=12 ====

long FUN_00c224f0(long *param_1)

{
  return *param_1 + param_1[1] * 4;
}


// ==== entry=00c22500 name=FUN_00c22500 size=18 ====

long * FUN_00c22500(long *param_1,long *param_2)

{
  *param_1 = *param_2 + param_2[1] * 4;
  return param_1;
}


// ==== entry=00c22520 name=FUN_00c22520 size=18 ====

long * FUN_00c22520(long *param_1,long *param_2)

{
  *param_1 = *param_2 + param_2[1] * 4;
  return param_1;
}


// ==== entry=00c22540 name=FUN_00c22540 size=10 ====

undefined8 * FUN_00c22540(undefined8 *param_1,undefined8 *param_2)

{
  *param_1 = *param_2;
  return param_1;
}


// ==== entry=00c22550 name=FUN_00c22550 size=10 ====

undefined8 * FUN_00c22550(undefined8 *param_1,undefined8 *param_2)

{
  *param_1 = *param_2;
  return param_1;
}


// ==== entry=00c22560 name=FUN_00c22560 size=4 ====

undefined8 FUN_00c22560(undefined8 *param_1)

{
  return *param_1;
}


// ==== entry=00c22570 name=FUN_00c22570 size=12 ====

long FUN_00c22570(long *param_1)

{
  return *param_1 + param_1[1] * 4;
}


// ==== entry=00c22580 name=FUN_00c22580 size=18 ====

long * FUN_00c22580(long *param_1,long *param_2)

{
  *param_1 = *param_2 + param_2[1] * 4;
  return param_1;
}


// ==== entry=00c225a0 name=FUN_00c225a0 size=10 ====

undefined8 * FUN_00c225a0(undefined8 *param_1,undefined8 *param_2)

{
  *param_1 = *param_2;
  return param_1;
}


// ==== entry=00c225b0 name=FUN_00c225b0 size=5 ====

undefined8 FUN_00c225b0(long param_1)

{
  return *(undefined8 *)(param_1 + 8);
}


// ==== entry=00c225c0 name=FUN_00c225c0 size=5 ====

undefined8 FUN_00c225c0(long param_1)

{
  return *(undefined8 *)(param_1 + 8);
}


// ==== entry=00c225d0 name=FUN_00c225d0 size=11 ====

undefined8 FUN_00c225d0(void)

{
  return 0x1fffffffffffffff;
}


// ==== entry=00c225e0 name=FUN_00c225e0 size=20 ====

long FUN_00c225e0(long *param_1)

{
  if ((long *)*param_1 != param_1 + 2) {
    return param_1[2];
  }
  return 3;
}


// ==== entry=00c22600 name=FUN_00c22600 size=237 ====

void FUN_00c22600(undefined8 *param_1,ulong param_2)

{
  wchar_t *__s1;
  size_t sVar1;
  ulong uVar2;
  wchar_t *pwVar3;
  wchar_t *__s1_00;
  ulong uVar4;
  ulong local_20;
  
  uVar2 = param_1[1];
  local_20 = param_2;
  if (param_2 < uVar2) {
    local_20 = uVar2;
  }
  pwVar3 = (wchar_t *)*param_1;
  __s1 = (wchar_t *)(param_1 + 2);
  if (__s1 == pwVar3) {
    uVar4 = 3;
  }
  else {
    uVar4 = param_1[2];
  }
  if (uVar4 != local_20) {
    if ((uVar4 < local_20) || (3 < local_20)) {
      __s1_00 = (wchar_t *)FUN_00c21cd0(param_1,&local_20);
      pwVar3 = (wchar_t *)*param_1;
      sVar1 = param_1[1] + 1;
      if (sVar1 == 1) {
        *__s1_00 = *pwVar3;
      }
      else if (sVar1 != 0) {
        wmemcpy(__s1_00,pwVar3,sVar1);
        pwVar3 = (wchar_t *)*param_1;
      }
      if (__s1 != pwVar3) {
        operator_delete(pwVar3);
      }
      *param_1 = __s1_00;
      param_1[2] = local_20;
      return;
    }
    if (__s1 != pwVar3) {
      sVar1 = uVar2 + 1;
      if (sVar1 == 1) {
        *(wchar_t *)(param_1 + 2) = *pwVar3;
      }
      else if (sVar1 != 0) {
        wmemcpy(__s1,pwVar3,sVar1);
        pwVar3 = (wchar_t *)*param_1;
      }
      operator_delete(pwVar3);
      *param_1 = __s1;
    }
  }
  return;
}


// ==== entry=00c22710 name=FUN_00c22710 size=43 ====

void FUN_00c22710(long *param_1)

{
  ulong uVar1;
  
  if ((long *)*param_1 == param_1 + 2) {
    uVar1 = 3;
  }
  else {
    uVar1 = param_1[2];
  }
  if (uVar1 <= (ulong)param_1[1]) {
    return;
  }
                    /* try { // try from 00c2272e to 00c22732 has its CatchHandler @ 00c22747 */
  FUN_00c22600(param_1,0);
  return;
}


// ==== entry=00c22760 name=FUN_00c22760 size=18 ====

void FUN_00c22760(undefined8 *param_1)

{
  param_1[1] = 0;
  *(undefined4 *)*param_1 = 0;
  return;
}


// ==== entry=00c22780 name=FUN_00c22780 size=9 ====

bool FUN_00c22780(long param_1)

{
  return *(long *)(param_1 + 8) == 0;
}


// ==== entry=00c22790 name=FUN_00c22790 size=8 ====

long FUN_00c22790(long *param_1,long param_2)

{
  return *param_1 + param_2 * 4;
}


// ==== entry=00c227a0 name=FUN_00c227a0 size=8 ====

long FUN_00c227a0(long *param_1,long param_2)

{
  return *param_1 + param_2 * 4;
}


// ==== entry=00c227b0 name=FUN_00c227b0 size=32 ====

long FUN_00c227b0(long *param_1,ulong param_2)

{
  if (param_2 < (ulong)param_1[1]) {
    return *param_1 + param_2 * 4;
  }
                    /* WARNING: Subroutine does not return */
  std::__throw_out_of_range_fmt
            ("basic_string::at: __n (which is %zu) >= this->size() (which is %zu)");
}


// ==== entry=00c227d0 name=FUN_00c227d0 size=32 ====

long FUN_00c227d0(long *param_1,ulong param_2)

{
  if (param_2 < (ulong)param_1[1]) {
    return *param_1 + param_2 * 4;
  }
                    /* WARNING: Subroutine does not return */
  std::__throw_out_of_range_fmt
            ("basic_string::at: __n (which is %zu) >= this->size() (which is %zu)");
}


// ==== entry=00c227f0 name=FUN_00c227f0 size=4 ====

undefined8 FUN_00c227f0(undefined8 *param_1)

{
  return *param_1;
}


// ==== entry=00c22800 name=FUN_00c22800 size=4 ====

undefined8 FUN_00c22800(undefined8 *param_1)

{
  return *param_1;
}


// ==== entry=00c22810 name=FUN_00c22810 size=13 ====

long FUN_00c22810(long *param_1)

{
  return *param_1 + -4 + param_1[1] * 4;
}


// ==== entry=00c22820 name=FUN_00c22820 size=13 ====

long FUN_00c22820(long *param_1)

{
  return *param_1 + -4 + param_1[1] * 4;
}


// ==== entry=00c22830 name=FUN_00c22830 size=108 ====

long * FUN_00c22830(long *param_1,undefined4 param_2)

{
  long lVar1;
  long *plVar2;
  ulong uVar3;
  
  lVar1 = param_1[1];
  plVar2 = (long *)*param_1;
  if (plVar2 == param_1 + 2) {
    uVar3 = 3;
  }
  else {
    uVar3 = param_1[2];
  }
  if (uVar3 < lVar1 + 1U) {
    FUN_00c220e0(param_1,lVar1,0,0,1);
    plVar2 = (long *)*param_1;
  }
  *(undefined4 *)((long)plVar2 + lVar1 * 4) = param_2;
  param_1[1] = lVar1 + 1U;
  *(undefined4 *)((long)plVar2 + 4 + lVar1 * 4) = 0;
  return param_1;
}


// ==== entry=00c228b0 name=FUN_00c228b0 size=105 ====

void FUN_00c228b0(long *param_1,undefined4 param_2)

{
  long lVar1;
  long *plVar2;
  ulong uVar3;
  
  lVar1 = param_1[1];
  plVar2 = (long *)*param_1;
  if (plVar2 == param_1 + 2) {
    uVar3 = 3;
  }
  else {
    uVar3 = param_1[2];
  }
  if (uVar3 < lVar1 + 1U) {
    FUN_00c220e0(param_1,lVar1,0,0,1);
    plVar2 = (long *)*param_1;
  }
  *(undefined4 *)((long)plVar2 + lVar1 * 4) = param_2;
  param_1[1] = lVar1 + 1U;
  *(undefined4 *)((long)plVar2 + 4 + lVar1 * 4) = 0;
  return;
}


// ==== entry=00c22930 name=FUN_00c22930 size=14 ====

undefined8 FUN_00c22930(undefined8 param_1)

{
  FUN_00c21fe0();
  return param_1;
}


// ==== entry=00c22940 name=FUN_00c22940 size=167 ====

long * FUN_00c22940(long *param_1,long *param_2)

{
  wchar_t *pwVar1;
  long lVar2;
  long lVar3;
  size_t __n;
  wchar_t *__s2;
  wchar_t *__s1;
  
  __s2 = (wchar_t *)(param_2 + 2);
  pwVar1 = (wchar_t *)*param_2;
  __s1 = (wchar_t *)*param_1;
  __n = param_2[1];
  if (pwVar1 == __s2) {
    if (__n != 0) {
      if (__n == 1) {
        *__s1 = *(wchar_t *)(param_2 + 2);
      }
      else {
        wmemcpy(__s1,__s2,__n);
        __n = param_2[1];
        __s1 = (wchar_t *)*param_1;
        __s2 = (wchar_t *)*param_2;
      }
    }
    param_1[1] = __n;
    __s1[__n] = L'\0';
  }
  else {
    lVar2 = param_2[2];
    if (__s1 == (wchar_t *)(param_1 + 2)) {
      *param_1 = (long)pwVar1;
      param_1[1] = __n;
      param_1[2] = lVar2;
    }
    else {
      lVar3 = param_1[2];
      *param_1 = (long)pwVar1;
      param_1[1] = __n;
      param_1[2] = lVar2;
      if (__s1 != (wchar_t *)0x0) {
        *param_2 = (long)__s1;
        param_2[2] = lVar3;
        __s2 = __s1;
        goto LAB_00c22989;
      }
    }
    *param_2 = (long)__s2;
  }
LAB_00c22989:
  param_2[1] = 0;
  *__s2 = L'\0';
  return param_1;
}


// ==== entry=00c22a00 orig=FUN_00c22a00 size=87 name=s_basic_string__erase_c22a00 ====

long * s_basic_string__erase_c22a00(long *param_1,ulong param_2,ulong param_3)

{
  ulong uVar1;
  
  if ((ulong)param_1[1] < param_2) {
                    /* WARNING: Subroutine does not return */
    std::__throw_out_of_range_fmt
              ("%s: __pos (which is %zu) > this->size() (which is %zu)","basic_string::erase",
               param_2);
  }
  if (param_3 != 0xffffffffffffffff) {
    if (param_3 != 0) {
      uVar1 = param_1[1] - param_2;
      if (uVar1 <= param_3) {
        param_3 = uVar1;
      }
      FUN_00c22240(param_1,param_2,param_3);
    }
    return param_1;
  }
  param_1[1] = param_2;
  *(undefined4 *)(*param_1 + param_2 * 4) = 0;
  return param_1;
}


// ==== entry=00c22a60 name=FUN_00c22a60 size=46 ====

long FUN_00c22a60(long *param_1,long param_2)

{
  long lVar1;
  
  lVar1 = *param_1;
  FUN_00c22240(param_1,param_2 - lVar1 >> 2,1);
  return *param_1 + (param_2 - lVar1);
}


// ==== entry=00c22a90 name=FUN_00c22a90 size=83 ====

undefined4 * FUN_00c22a90(long *param_1,undefined4 *param_2,long param_3)

{
  long lVar1;
  long lVar2;
  
  lVar1 = (long)param_2 - *param_1;
  lVar2 = lVar1 >> 2;
  if (param_3 != *param_1 + param_1[1] * 4) {
    FUN_00c22240(param_1,lVar2,param_3 - (long)param_2 >> 2);
    return (undefined4 *)(*param_1 + lVar1);
  }
  param_1[1] = lVar2;
  *param_2 = 0;
  return param_2;
}


// ==== entry=00c22af0 name=FUN_00c22af0 size=18 ====

void FUN_00c22af0(long param_1)

{
  FUN_00c22240(param_1,*(long *)(param_1 + 8) + -1,1);
  return;
}


// ==== entry=00c22b10 name=FUN_00c22b10 size=242 ====

long * FUN_00c22b10(long *param_1,long param_2,ulong param_3,ulong param_4,wchar_t param_5)

{
  wchar_t *pwVar1;
  wchar_t *__s1;
  long lVar2;
  long *plVar3;
  size_t __n;
  ulong uVar4;
  ulong uVar5;
  
  lVar2 = param_1[1];
  if (param_4 <= (param_3 + 0x1fffffffffffffff) - lVar2) {
    plVar3 = (long *)*param_1;
    uVar4 = (param_4 - param_3) + lVar2;
    if (plVar3 == param_1 + 2) {
      uVar5 = 3;
    }
    else {
      uVar5 = param_1[2];
    }
    if (uVar5 < uVar4) {
      FUN_00c220e0(param_1,param_2,param_3,0,param_4);
      plVar3 = (long *)*param_1;
    }
    else {
      __n = lVar2 - (param_3 + param_2);
      if ((__n != 0) && (param_3 != param_4)) {
        pwVar1 = (wchar_t *)((long)plVar3 + param_3 * 4 + param_2 * 4);
        __s1 = (wchar_t *)((long)plVar3 + param_4 * 4 + param_2 * 4);
        if (__n == 1) {
          *__s1 = *pwVar1;
        }
        else {
          wmemmove(__s1,pwVar1,__n);
          plVar3 = (long *)*param_1;
        }
      }
    }
    if (param_4 != 0) {
      pwVar1 = (wchar_t *)((long)plVar3 + param_2 * 4);
      if (param_4 == 1) {
        *pwVar1 = param_5;
      }
      else {
        wmemset(pwVar1,param_5,param_4);
        plVar3 = (long *)*param_1;
      }
    }
    param_1[1] = uVar4;
    *(undefined4 *)((long)plVar3 + uVar4 * 4) = 0;
    return param_1;
  }
                    /* WARNING: Subroutine does not return */
  std::__throw_length_error("basic_string::_M_replace_aux");
}


// ==== entry=00c22c20 name=FUN_00c22c20 size=17 ====

void FUN_00c22c20(long param_1,undefined8 param_2,undefined4 param_3)

{
  FUN_00c22b10(param_1,*(undefined8 *)(param_1 + 8),0,param_2,param_3);
  return;
}


// ==== entry=00c22c40 name=FUN_00c22c40 size=45 ====

void FUN_00c22c40(long *param_1,ulong param_2,undefined4 param_3)

{
  ulong uVar1;
  
  uVar1 = param_1[1];
  if (param_2 <= uVar1) {
    if (param_2 < uVar1) {
      param_1[1] = param_2;
      *(undefined4 *)(*param_1 + param_2 * 4) = 0;
    }
    return;
  }
  FUN_00c22b10(param_1,uVar1,0,param_2 - uVar1,param_3);
  return;
}


// ==== entry=00c22c80 name=FUN_00c22c80 size=7 ====

void FUN_00c22c80(undefined8 param_1,undefined8 param_2)

{
  FUN_00c22c40(param_1,param_2,0);
  return;
}


// ==== entry=00c22c90 name=FUN_00c22c90 size=17 ====

void FUN_00c22c90(long param_1,undefined8 param_2,undefined4 param_3)

{
  FUN_00c22b10(param_1,0,*(undefined8 *)(param_1 + 8),param_2,param_3);
  return;
}


// ==== entry=00c22cb0 name=FUN_00c22cb0 size=28 ====

long FUN_00c22cb0(long param_1,undefined4 param_2)

{
  FUN_00c22b10(param_1,0,*(undefined8 *)(param_1 + 8),1,param_2);
  return param_1;
}


// ==== entry=00c22cd0 orig=FUN_00c22cd0 size=47 name=s_basic_string__insert_c22cd0 ====

void s_basic_string__insert_c22cd0(long param_1,ulong param_2,undefined8 param_3,uint param_4)

{
  if (param_2 <= *(ulong *)(param_1 + 8)) {
    FUN_00c22b10(param_1,param_2,0,param_3);
    return;
  }
                    /* WARNING: Subroutine does not return */
  std::__throw_out_of_range_fmt
            ("%s: __pos (which is %zu) > this->size() (which is %zu)","basic_string::insert",param_2
             ,*(ulong *)(param_1 + 8),(ulong)param_4);
}


// ==== entry=00c22d00 name=FUN_00c22d00 size=51 ====

long FUN_00c22d00(long *param_1,long param_2,undefined4 param_3)

{
  long lVar1;
  
  lVar1 = *param_1;
  FUN_00c22b10(param_1,param_2 - lVar1 >> 2,0,1,param_3);
  return *param_1 + (param_2 - lVar1);
}


// ==== entry=00c22d40 orig=FUN_00c22d40 size=55 name=s_basic_string__replace_c22d40 ====

void s_basic_string__replace_c22d40
               (long param_1,ulong param_2,ulong param_3,undefined8 param_4,undefined8 param_5)

{
  ulong uVar1;
  ulong uVar2;
  
  uVar1 = *(ulong *)(param_1 + 8);
  uVar2 = uVar1 - param_2;
  if (uVar2 <= param_3) {
    param_3 = uVar2;
  }
  if (param_2 <= uVar1) {
    FUN_00c22b10(param_1,param_2,param_3);
    return;
  }
                    /* WARNING: Subroutine does not return */
  std::__throw_out_of_range_fmt
            ("%s: __pos (which is %zu) > this->size() (which is %zu)","basic_string::replace",
             param_2,uVar1,param_5,uVar1,uVar2);
}


// ==== entry=00c22d80 name=FUN_00c22d80 size=19 ====

void FUN_00c22d80(long *param_1,long param_2,long param_3)

{
  FUN_00c22b10(param_1,param_2 - *param_1 >> 2,param_3 - param_2 >> 2);
  return;
}


// ==== entry=00c22da0 name=FUN_00c22da0 size=49 ====

long FUN_00c22da0(long *param_1,long param_2,undefined8 param_3,undefined4 param_4)

{
  long lVar1;
  
  lVar1 = *param_1;
  FUN_00c22b10(param_1,param_2 - lVar1 >> 2,0,param_3,param_4);
  return *param_1 + (param_2 - lVar1);
}


// ==== entry=00c22de0 name=FUN_00c22de0 size=671 ====

ulong * FUN_00c22de0(ulong *param_1,long param_2,ulong param_3,wchar_t *param_4,ulong param_5)

{
  ulong uVar1;
  wchar_t *__s1;
  ulong uVar2;
  wchar_t *pwVar3;
  ulong uVar4;
  size_t sVar5;
  bool bVar6;
  bool bVar7;
  
  uVar2 = param_1[1];
  if ((param_3 + 0x1fffffffffffffff) - uVar2 < param_5) {
                    /* WARNING: Subroutine does not return */
    std::__throw_length_error("basic_string::_M_replace");
  }
  pwVar3 = (wchar_t *)*param_1;
  uVar1 = uVar2 + (param_5 - param_3);
  if (pwVar3 == (wchar_t *)(param_1 + 2)) {
    uVar4 = 3;
  }
  else {
    uVar4 = param_1[2];
  }
  if (uVar4 < uVar1) {
    FUN_00c220e0(param_1,param_2,param_3);
    goto LAB_00c22ea8;
  }
  __s1 = pwVar3 + param_2;
  sVar5 = uVar2 - (param_2 + param_3);
  bVar6 = sVar5 == 0;
  bVar7 = param_3 == param_5;
  if ((param_4 < pwVar3) || (pwVar3 + uVar2 < param_4)) {
    if (!bVar6 && !bVar7) {
      if (sVar5 == 1) {
        __s1[param_5] = __s1[param_3];
      }
      else {
        wmemmove(__s1 + param_5,__s1 + param_3,sVar5);
      }
    }
    if (param_5 == 0) goto LAB_00c22ea8;
    if (param_5 != 1) {
      wmemcpy(__s1,param_4,param_5);
      goto LAB_00c22ea8;
    }
  }
  else {
    if ((param_5 == 0) || (param_3 < param_5)) {
LAB_00c22ff5:
      if (!bVar6 && !bVar7) goto LAB_00c22f30;
    }
    else {
      if (param_5 == 1) {
        *__s1 = *param_4;
        goto LAB_00c22ff5;
      }
      wmemmove(__s1,param_4,param_5);
      if (bVar6 || bVar7) goto LAB_00c22ea8;
LAB_00c22f30:
      if (sVar5 == 1) {
        __s1[param_5] = __s1[param_3];
      }
      else {
        wmemmove(__s1 + param_5,__s1 + param_3,sVar5);
      }
    }
    if (param_5 <= param_3) goto LAB_00c22ea8;
    pwVar3 = __s1 + param_3;
    if (pwVar3 < param_4 + param_5) {
      if (param_4 < pwVar3) {
        sVar5 = (long)pwVar3 - (long)param_4 >> 2;
        if (sVar5 == 1) {
          *__s1 = *param_4;
        }
        else if (sVar5 != 0) {
          wmemmove(__s1,param_4,sVar5);
        }
        sVar5 = param_5 - sVar5;
        pwVar3 = (wchar_t *)((long)__s1 + ((long)pwVar3 - (long)param_4));
        if (sVar5 == 1) {
          *pwVar3 = __s1[param_5];
        }
        else if (sVar5 != 0) {
          wmemcpy(pwVar3,__s1 + param_5,sVar5);
        }
      }
      else if (param_5 == 1) {
        *__s1 = param_4[param_5 - param_3];
      }
      else {
        wmemcpy(__s1,param_4 + (param_5 - param_3),param_5);
      }
      goto LAB_00c22ea8;
    }
    if (param_5 != 1) {
      wmemmove(__s1,param_4,param_5);
      goto LAB_00c22ea8;
    }
  }
  *__s1 = *param_4;
LAB_00c22ea8:
  param_1[1] = uVar1;
  *(undefined4 *)(*param_1 + uVar1 * 4) = 0;
  return param_1;
}


// ==== entry=00c230c0 orig=FUN_00c230c0 size=65 name=s_basic_string__assign_c230c0 ====

void s_basic_string__assign_c230c0
               (long param_1,long *param_2,ulong param_3,ulong param_4,undefined8 param_5,
               undefined8 param_6)

{
  ulong uVar1;
  ulong uVar2;
  
  uVar1 = param_2[1];
  uVar2 = uVar1 - param_3;
  if (param_4 < uVar1 - param_3) {
    uVar2 = param_4;
  }
  if (param_3 <= uVar1) {
    FUN_00c22de0(param_1,0,*(undefined8 *)(param_1 + 8),*param_2 + param_3 * 4);
    return;
  }
                    /* WARNING: Subroutine does not return */
  std::__throw_out_of_range_fmt
            ("%s: __pos (which is %zu) > this->size() (which is %zu)","basic_string::assign",param_3
             ,uVar1,uVar2,param_6,*param_2);
}


// ==== entry=00c23110 name=FUN_00c23110 size=17 ====

void FUN_00c23110(long param_1,undefined8 param_2,undefined8 param_3)

{
  FUN_00c22de0(param_1,0,*(undefined8 *)(param_1 + 8),param_2,param_3);
  return;
}


// ==== entry=00c23130 name=FUN_00c23130 size=26 ====

long FUN_00c23130(long param_1,undefined8 param_2,undefined8 param_3)

{
  FUN_00c22de0(param_1,0,*(undefined8 *)(param_1 + 8),param_2,param_3);
  return param_1;
}


// ==== entry=00c23150 name=FUN_00c23150 size=17 ====

void FUN_00c23150(long param_1,undefined8 param_2,undefined8 param_3)

{
  FUN_00c22de0(param_1,0,*(undefined8 *)(param_1 + 8),param_2,param_3);
  return;
}


// ==== entry=00c23170 name=FUN_00c23170 size=46 ====

void FUN_00c23170(long param_1,wchar_t *param_2)

{
  size_t sVar1;
  
  sVar1 = wcslen(param_2);
  FUN_00c22de0(param_1,0,*(undefined8 *)(param_1 + 8),param_2,sVar1);
  return;
}


// ==== entry=00c231a0 orig=FUN_00c231a0 size=55 name=s_basic_string__replace_c231a0 ====

void s_basic_string__replace_c231a0
               (long param_1,ulong param_2,ulong param_3,undefined8 param_4,undefined8 param_5)

{
  ulong uVar1;
  ulong uVar2;
  
  uVar1 = *(ulong *)(param_1 + 8);
  uVar2 = uVar1 - param_2;
  if (uVar2 <= param_3) {
    param_3 = uVar2;
  }
  if (param_2 <= uVar1) {
    FUN_00c22de0(param_1,param_2,param_3);
    return;
  }
                    /* WARNING: Subroutine does not return */
  std::__throw_out_of_range_fmt
            ("%s: __pos (which is %zu) > this->size() (which is %zu)","basic_string::replace",
             param_2,uVar1,param_5,uVar1,uVar2);
}


// ==== entry=00c231e0 name=FUN_00c231e0 size=46 ====

void FUN_00c231e0(long param_1,wchar_t *param_2)

{
  size_t sVar1;
  
  sVar1 = wcslen(param_2);
  FUN_00c22de0(param_1,0,*(undefined8 *)(param_1 + 8),param_2,sVar1);
  return;
}


// ==== entry=00c23210 orig=FUN_00c23210 size=47 name=s_basic_string__replace_c23210 ====

void s_basic_string__replace_c23210
               (long param_1,ulong param_2,undefined8 param_3,undefined8 param_4)

{
  if (param_2 <= *(ulong *)(param_1 + 8)) {
    FUN_00c22de0(param_1,param_2,0,param_3);
    return;
  }
                    /* WARNING: Subroutine does not return */
  std::__throw_out_of_range_fmt
            ("%s: __pos (which is %zu) > this->size() (which is %zu)","basic_string::replace",
             param_2,*(ulong *)(param_1 + 8),param_4);
}


// ==== entry=00c23240 orig=FUN_00c23240 size=51 name=s_basic_string__replace_c23240 ====

void s_basic_string__replace_c23240
               (long param_1,ulong param_2,undefined8 *param_3,undefined8 param_4,undefined8 param_5
               ,undefined8 param_6)

{
  if (param_2 <= *(ulong *)(param_1 + 8)) {
    FUN_00c22de0(param_1,param_2,0,*param_3);
    return;
  }
                    /* WARNING: Subroutine does not return */
  std::__throw_out_of_range_fmt
            ("%s: __pos (which is %zu) > this->size() (which is %zu)","basic_string::replace",
             param_2,*(ulong *)(param_1 + 8),param_3[1],param_6,param_3);
}


// ==== entry=00c23280 orig=FUN_00c23280 size=62 name=s_basic_string__replace_c23280 ====

void s_basic_string__replace_c23280(long param_1,ulong param_2,ulong param_3,undefined8 *param_4)

{
  ulong uVar1;
  ulong uVar2;
  
  uVar1 = *(ulong *)(param_1 + 8);
  uVar2 = uVar1 - param_2;
  if (uVar2 <= param_3) {
    param_3 = uVar2;
  }
  if (param_2 <= uVar1) {
    FUN_00c22de0(param_1,param_2,param_3,*param_4);
    return;
  }
                    /* WARNING: Subroutine does not return */
  std::__throw_out_of_range_fmt
            ("%s: __pos (which is %zu) > this->size() (which is %zu)","basic_string::replace",
             param_2,uVar1,param_4[1],uVar1,uVar2);
}


// ==== entry=00c232c0 orig=FUN_00c232c0 size=77 name=s_basic_string__replace_c232c0 ====

void s_basic_string__replace_c232c0(long param_1,ulong param_2,wchar_t *param_3)

{
  size_t sVar1;
  
  sVar1 = wcslen(param_3);
  if (param_2 <= *(ulong *)(param_1 + 8)) {
    FUN_00c22de0(param_1,param_2,0,param_3,sVar1);
    return;
  }
                    /* WARNING: Subroutine does not return */
  std::__throw_out_of_range_fmt
            ("%s: __pos (which is %zu) > this->size() (which is %zu)","basic_string::replace",
             param_2);
}


// ==== entry=00c23310 orig=FUN_00c23310 size=107 name=s_basic_string__replace_c23310 ====

void s_basic_string__replace_c23310(long param_1,ulong param_2,ulong param_3,wchar_t *param_4)

{
  size_t sVar1;
  ulong uVar2;
  
  sVar1 = wcslen(param_4);
  uVar2 = *(ulong *)(param_1 + 8) - param_2;
  if (uVar2 <= param_3) {
    param_3 = uVar2;
  }
  if (param_2 <= *(ulong *)(param_1 + 8)) {
    FUN_00c22de0(param_1,param_2,param_3,param_4,sVar1);
    return;
  }
                    /* WARNING: Subroutine does not return */
  std::__throw_out_of_range_fmt
            ("%s: __pos (which is %zu) > this->size() (which is %zu)","basic_string::replace",
             param_2);
}


// ==== entry=00c23380 orig=FUN_00c23380 size=75 name=s_basic_string__replace_c23380 ====

void s_basic_string__replace_c23380
               (long *param_1,long param_2,long param_3,undefined8 param_4,undefined8 param_5)

{
  ulong uVar1;
  ulong uVar2;
  ulong uVar3;
  
  uVar1 = param_1[1];
  uVar2 = param_2 - *param_1 >> 2;
  uVar3 = param_3 - param_2 >> 2;
  if (uVar1 - uVar2 < uVar3) {
    uVar3 = uVar1 - uVar2;
  }
  if (uVar2 <= uVar1) {
    FUN_00c22de0(param_1,uVar2);
    return;
  }
                    /* WARNING: Subroutine does not return */
  std::__throw_out_of_range_fmt
            ("%s: __pos (which is %zu) > this->size() (which is %zu)","basic_string::replace",uVar2,
             uVar1,param_5,uVar1,uVar3);
}


// ==== entry=00c233d0 orig=FUN_00c233d0 size=82 name=s_basic_string__replace_c233d0 ====

void s_basic_string__replace_c233d0(long *param_1,long param_2,long param_3,undefined8 *param_4)

{
  ulong uVar1;
  ulong uVar2;
  ulong uVar3;
  
  uVar1 = param_1[1];
  uVar2 = param_2 - *param_1 >> 2;
  uVar3 = param_3 - param_2 >> 2;
  if (uVar1 - uVar2 < uVar3) {
    uVar3 = uVar1 - uVar2;
  }
  if (uVar2 <= uVar1) {
    FUN_00c22de0(param_1,uVar2,uVar3,*param_4);
    return;
  }
                    /* WARNING: Subroutine does not return */
  std::__throw_out_of_range_fmt
            ("%s: __pos (which is %zu) > this->size() (which is %zu)","basic_string::replace",uVar2,
             uVar1,param_4[1],uVar1,uVar3);
}


// ==== entry=00c23430 orig=FUN_00c23430 size=82 name=s_basic_string__replace_c23430 ====

void s_basic_string__replace_c23430
               (long *param_1,long param_2,long param_3,long param_4,long param_5)

{
  ulong uVar1;
  ulong uVar2;
  ulong uVar3;
  
  uVar1 = param_1[1];
  uVar2 = param_2 - *param_1 >> 2;
  uVar3 = param_3 - param_2 >> 2;
  if (uVar1 - uVar2 < uVar3) {
    uVar3 = uVar1 - uVar2;
  }
  if (uVar2 <= uVar1) {
    FUN_00c22de0(param_1,uVar2);
    return;
  }
                    /* WARNING: Subroutine does not return */
  std::__throw_out_of_range_fmt
            ("%s: __pos (which is %zu) > this->size() (which is %zu)","basic_string::replace",uVar2,
             uVar1,param_5 - param_4 >> 2,uVar1,uVar3);
}


// ==== entry=00c23490 orig=FUN_00c23490 size=82 name=s_basic_string__replace_c23490 ====

void s_basic_string__replace_c23490
               (long *param_1,long param_2,long param_3,long param_4,long param_5)

{
  ulong uVar1;
  ulong uVar2;
  ulong uVar3;
  
  uVar1 = param_1[1];
  uVar2 = param_2 - *param_1 >> 2;
  uVar3 = param_3 - param_2 >> 2;
  if (uVar1 - uVar2 < uVar3) {
    uVar3 = uVar1 - uVar2;
  }
  if (uVar2 <= uVar1) {
    FUN_00c22de0(param_1,uVar2);
    return;
  }
                    /* WARNING: Subroutine does not return */
  std::__throw_out_of_range_fmt
            ("%s: __pos (which is %zu) > this->size() (which is %zu)","basic_string::replace",uVar2,
             uVar1,param_5 - param_4 >> 2,uVar1,uVar3);
}


// ==== entry=00c234f0 orig=FUN_00c234f0 size=75 name=s_basic_string__replace_c234f0 ====

void s_basic_string__replace_c234f0
               (long *param_1,long param_2,long param_3,undefined8 param_4,undefined8 param_5)

{
  ulong uVar1;
  ulong uVar2;
  ulong uVar3;
  
  uVar1 = param_1[1];
  uVar2 = param_2 - *param_1 >> 2;
  uVar3 = param_3 - param_2 >> 2;
  if (uVar1 - uVar2 < uVar3) {
    uVar3 = uVar1 - uVar2;
  }
  if (uVar2 <= uVar1) {
    FUN_00c22de0(param_1,uVar2);
    return;
  }
                    /* WARNING: Subroutine does not return */
  std::__throw_out_of_range_fmt
            ("%s: __pos (which is %zu) > this->size() (which is %zu)","basic_string::replace",uVar2,
             uVar1,param_5,uVar1,uVar3);
}


// ==== entry=00c23540 orig=FUN_00c23540 size=124 name=s_basic_string__replace_c23540 ====

void s_basic_string__replace_c23540(long *param_1,long param_2,long param_3,wchar_t *param_4)

{
  size_t sVar1;
  ulong uVar2;
  ulong uVar3;
  ulong uVar4;
  
  sVar1 = wcslen(param_4);
  uVar4 = param_2 - *param_1 >> 2;
  uVar2 = param_3 - param_2 >> 2;
  uVar3 = param_1[1] - uVar4;
  if (uVar3 < uVar2) {
    uVar2 = uVar3;
  }
  if (uVar4 <= (ulong)param_1[1]) {
    FUN_00c22de0(param_1,uVar4,uVar2,param_4,sVar1);
    return;
  }
                    /* WARNING: Subroutine does not return */
  std::__throw_out_of_range_fmt
            ("%s: __pos (which is %zu) > this->size() (which is %zu)","basic_string::replace",uVar4)
  ;
}


// ==== entry=00c235c0 orig=FUN_00c235c0 size=54 name=s_basic_string__replace_c235c0 ====

void s_basic_string__replace_c235c0
               (long *param_1,long param_2,undefined8 param_3,undefined8 param_4)

{
  ulong uVar1;
  
  uVar1 = param_2 - *param_1 >> 2;
  if (uVar1 <= (ulong)param_1[1]) {
    FUN_00c22de0(param_1,uVar1,0,param_3);
    return;
  }
                    /* WARNING: Subroutine does not return */
  std::__throw_out_of_range_fmt
            ("%s: __pos (which is %zu) > this->size() (which is %zu)","basic_string::replace",uVar1,
             param_1[1],param_4);
}


// ==== entry=00c23600 orig=FUN_00c23600 size=82 name=s_basic_string__replace_c23600 ====

void s_basic_string__replace_c23600
               (long *param_1,long param_2,long param_3,long param_4,long param_5)

{
  ulong uVar1;
  ulong uVar2;
  ulong uVar3;
  
  uVar1 = param_1[1];
  uVar2 = param_2 - *param_1 >> 2;
  uVar3 = param_3 - param_2 >> 2;
  if (uVar1 - uVar2 < uVar3) {
    uVar3 = uVar1 - uVar2;
  }
  if (uVar2 <= uVar1) {
    FUN_00c22de0(param_1,uVar2);
    return;
  }
                    /* WARNING: Subroutine does not return */
  std::__throw_out_of_range_fmt
            ("%s: __pos (which is %zu) > this->size() (which is %zu)","basic_string::replace",uVar2,
             uVar1,param_5 - param_4 >> 2,uVar1,uVar3);
}


// ==== entry=00c23660 orig=FUN_00c23660 size=82 name=s_basic_string__replace_c23660 ====

void s_basic_string__replace_c23660
               (long *param_1,long param_2,long param_3,long param_4,long param_5)

{
  ulong uVar1;
  ulong uVar2;
  ulong uVar3;
  
  uVar1 = param_1[1];
  uVar2 = param_2 - *param_1 >> 2;
  uVar3 = param_3 - param_2 >> 2;
  if (uVar1 - uVar2 < uVar3) {
    uVar3 = uVar1 - uVar2;
  }
  if (uVar2 <= uVar1) {
    FUN_00c22de0(param_1,uVar2);
    return;
  }
                    /* WARNING: Subroutine does not return */
  std::__throw_out_of_range_fmt
            ("%s: __pos (which is %zu) > this->size() (which is %zu)","basic_string::replace",uVar2,
             uVar1,param_5 - param_4 >> 2,uVar1,uVar3);
}


// ==== entry=00c236c0 orig=FUN_00c236c0 size=121 name=s_basic_string__replace_c236c0 ====

void s_basic_string__replace_c236c0
               (long param_1,ulong param_2,ulong param_3,long *param_4,ulong param_5,ulong param_6)

{
  ulong uVar1;
  ulong uVar2;
  
  uVar1 = param_4[1];
  uVar2 = uVar1 - param_5;
  if (param_6 < uVar1 - param_5) {
    uVar2 = param_6;
  }
  if (uVar1 < param_5) {
                    /* WARNING: Subroutine does not return */
    std::__throw_out_of_range_fmt
              ("%s: __pos (which is %zu) > this->size() (which is %zu)","basic_string::replace",
               param_5,uVar1);
  }
  uVar1 = *(ulong *)(param_1 + 8);
  if (uVar1 - param_2 <= param_3) {
    param_3 = uVar1 - param_2;
  }
  if (param_2 <= uVar1) {
    FUN_00c22de0(param_1,param_2,param_3,*param_4 + param_5 * 4,uVar2);
    return;
  }
                    /* WARNING: Subroutine does not return */
  std::__throw_out_of_range_fmt
            ("%s: __pos (which is %zu) > this->size() (which is %zu)","basic_string::replace",
             param_2,uVar1);
}


// ==== entry=00c23740 orig=FUN_00c23740 size=107 name=s_basic_string__replace_c23740 ====

void s_basic_string__replace_c23740
               (long param_1,ulong param_2,long *param_3,ulong param_4,ulong param_5)

{
  ulong uVar1;
  
  uVar1 = param_3[1];
  if (uVar1 - param_4 <= param_5) {
    param_5 = uVar1 - param_4;
  }
  if (param_4 <= uVar1) {
    if (param_2 <= *(ulong *)(param_1 + 8)) {
      FUN_00c22de0(param_1,param_2,0,*param_3 + param_4 * 4);
      return;
    }
                    /* WARNING: Subroutine does not return */
    std::__throw_out_of_range_fmt
              ("%s: __pos (which is %zu) > this->size() (which is %zu)","basic_string::replace",
               param_2,*(ulong *)(param_1 + 8),param_5);
  }
                    /* WARNING: Subroutine does not return */
  std::__throw_out_of_range_fmt
            ("%s: __pos (which is %zu) > this->size() (which is %zu)","basic_string::insert",param_4
             ,uVar1,param_5);
}


// ==== entry=00c237b0 name=FUN_00c237b0 size=120 ====

long * FUN_00c237b0(long *param_1,wchar_t *param_2,size_t param_3)

{
  ulong uVar1;
  wchar_t *__s1;
  long lVar2;
  long *plVar3;
  ulong uVar4;
  
  lVar2 = param_1[1];
  plVar3 = (long *)*param_1;
  uVar1 = lVar2 + param_3;
  if (plVar3 == param_1 + 2) {
    uVar4 = 3;
  }
  else {
    uVar4 = param_1[2];
  }
  if (uVar4 < uVar1) {
    FUN_00c220e0(param_1,lVar2,0,param_2,param_3);
    plVar3 = (long *)*param_1;
  }
  else if (param_3 != 0) {
    __s1 = (wchar_t *)((long)plVar3 + lVar2 * 4);
    if (param_3 == 1) {
      *__s1 = *param_2;
    }
    else {
      wmemcpy(__s1,param_2,param_3);
      plVar3 = (long *)*param_1;
    }
  }
  param_1[1] = uVar1;
  *(undefined4 *)((long)plVar3 + uVar1 * 4) = 0;
  return param_1;
}


// ==== entry=00c23840 name=FUN_00c23840 size=12 ====

void FUN_00c23840(undefined8 param_1,undefined8 *param_2)

{
  FUN_00c237b0(param_1,*param_2,param_2[1]);
  return;
}


// ==== entry=00c23850 name=FUN_00c23850 size=12 ====

void FUN_00c23850(undefined8 param_1,undefined8 *param_2)

{
  FUN_00c237b0(param_1,*param_2,param_2[1]);
  return;
}


// ==== entry=00c23860 orig=FUN_00c23860 size=62 name=s_basic_string__append_c23860 ====

void s_basic_string__append_c23860
               (undefined8 param_1,long *param_2,ulong param_3,ulong param_4,undefined8 param_5,
               undefined8 param_6)

{
  ulong uVar1;
  ulong uVar2;
  
  uVar1 = param_2[1];
  uVar2 = uVar1 - param_3;
  if (param_4 < uVar1 - param_3) {
    uVar2 = param_4;
  }
  if (param_3 <= uVar1) {
    FUN_00c237b0(param_1,*param_2 + param_3 * 4,uVar2);
    return;
  }
                    /* WARNING: Subroutine does not return */
  std::__throw_out_of_range_fmt
            ("%s: __pos (which is %zu) > this->size() (which is %zu)","basic_string::append",param_3
             ,uVar1,uVar1,param_6,uVar2);
}


// ==== entry=00c238a0 orig=FUN_00c238a0 size=37 name=s_basic_string__append_c238a0 ====

void s_basic_string__append_c238a0(long param_1,undefined8 param_2,ulong param_3)

{
  if (param_3 <= 0x1fffffffffffffffU - *(long *)(param_1 + 8)) {
    FUN_00c237b0();
    return;
  }
                    /* WARNING: Subroutine does not return */
  std::__throw_length_error("basic_string::append");
}


// ==== entry=00c238d0 orig=FUN_00c238d0 size=71 name=s_basic_string__append_c238d0 ====

void s_basic_string__append_c238d0(long param_1,wchar_t *param_2)

{
  size_t sVar1;
  
  sVar1 = wcslen(param_2);
  if (sVar1 <= 0x1fffffffffffffffU - *(long *)(param_1 + 8)) {
    FUN_00c237b0(param_1,param_2,sVar1);
    return;
  }
                    /* WARNING: Subroutine does not return */
  std::__throw_length_error("basic_string::append");
}


// ==== entry=00c23920 orig=FUN_00c23920 size=71 name=s_basic_string__append_c23920 ====

void s_basic_string__append_c23920(long param_1,wchar_t *param_2)

{
  size_t sVar1;
  
  sVar1 = wcslen(param_2);
  if (sVar1 <= 0x1fffffffffffffffU - *(long *)(param_1 + 8)) {
    FUN_00c237b0(param_1,param_2,sVar1);
    return;
  }
                    /* WARNING: Subroutine does not return */
  std::__throw_length_error("basic_string::append");
}


// ==== entry=00c23970 orig=FUN_00c23970 size=37 name=s_basic_string__append_c23970 ====

void s_basic_string__append_c23970(long param_1,undefined8 param_2,ulong param_3)

{
  if (param_3 <= 0x1fffffffffffffffU - *(long *)(param_1 + 8)) {
    FUN_00c237b0();
    return;
  }
                    /* WARNING: Subroutine does not return */
  std::__throw_length_error("basic_string::append");
}


// ==== entry=00c239a0 orig=FUN_00c239a0 size=37 name=s_basic_string__append_c239a0 ====

void s_basic_string__append_c239a0(long param_1,undefined8 param_2,ulong param_3)

{
  if (param_3 <= 0x1fffffffffffffffU - *(long *)(param_1 + 8)) {
    FUN_00c237b0();
    return;
  }
                    /* WARNING: Subroutine does not return */
  std::__throw_length_error("basic_string::append");
}


// ==== entry=00c239d0 orig=FUN_00c239d0 size=97 name=s_basic_string__copy_c239d0 ====

size_t s_basic_string__copy_c239d0(long *param_1,wchar_t *param_2,ulong param_3,ulong param_4)

{
  wchar_t *__s2;
  ulong uVar1;
  ulong __n;
  
  uVar1 = param_1[1];
  if (uVar1 < param_4) {
                    /* WARNING: Subroutine does not return */
    std::__throw_out_of_range_fmt
              ("%s: __pos (which is %zu) > this->size() (which is %zu)","basic_string::copy",param_4
               ,uVar1);
  }
  __n = uVar1 - param_4;
  if (param_3 < uVar1 - param_4) {
    __n = param_3;
  }
  if (__n != 0) {
    __s2 = (wchar_t *)(*param_1 + param_4 * 4);
    if (__n == 1) {
      *param_2 = *__s2;
      return 1;
    }
    wmemcpy(param_2,__s2,__n);
  }
  return __n;
}


// ==== entry=00c23a40 name=FUN_00c23a40 size=409 ====

void FUN_00c23a40(undefined8 *param_1,undefined8 *param_2)

{
  wchar_t *__s1;
  wchar_t *__s2;
  wchar_t *pwVar1;
  wchar_t *pwVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  long in_FS_OFFSET;
  wchar_t awStack_48 [6];
  long local_30;
  
  local_30 = *(long *)(in_FS_OFFSET + 0x28);
  if (param_1 == param_2) goto LAB_00c23aa9;
  pwVar1 = (wchar_t *)*param_1;
  __s1 = (wchar_t *)(param_1 + 2);
  pwVar2 = (wchar_t *)*param_2;
  __s2 = (wchar_t *)(param_2 + 2);
  if (__s1 == pwVar1) {
    if (__s2 == pwVar2) {
      if (param_1[1] == 0) {
        if (param_2[1] != 0) {
          wmemcpy(__s1,__s2,4);
          param_1[1] = param_2[1];
          param_2[1] = 0;
          *(undefined4 *)*param_2 = 0;
          goto LAB_00c23aa9;
        }
        uVar5 = 0;
        uVar4 = 0;
      }
      else {
        if (param_2[1] == 0) {
          wmemcpy(__s2,__s1,4);
          param_2[1] = param_1[1];
          param_1[1] = 0;
          *(undefined4 *)*param_1 = 0;
          goto LAB_00c23aa9;
        }
        wmemcpy(awStack_48,__s2,4);
        wmemcpy(__s2,__s1,4);
        wmemcpy(__s1,awStack_48,4);
        uVar4 = param_2[1];
        uVar5 = param_1[1];
      }
    }
    else {
      uVar3 = param_2[2];
      wmemcpy(__s2,__s1,4);
      uVar5 = param_1[1];
      *param_1 = *param_2;
      uVar4 = param_2[1];
      *param_2 = __s2;
      param_1[2] = uVar3;
    }
  }
  else {
    uVar3 = param_1[2];
    if (__s2 == pwVar2) {
      wmemcpy(__s1,__s2,4);
      *param_2 = *param_1;
      *param_1 = __s1;
    }
    else {
      *param_1 = pwVar2;
      *param_2 = pwVar1;
      param_1[2] = param_2[2];
    }
    uVar4 = param_2[1];
    uVar5 = param_1[1];
    param_2[2] = uVar3;
  }
  param_1[1] = uVar4;
  param_2[1] = uVar5;
LAB_00c23aa9:
  if (local_30 == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ==== entry=00c23c00 name=FUN_00c23c00 size=4 ====

undefined8 FUN_00c23c00(undefined8 *param_1)

{
  return *param_1;
}


// ==== entry=00c23c10 name=FUN_00c23c10 size=4 ====

undefined8 FUN_00c23c10(undefined8 *param_1)

{
  return *param_1;
}


// ==== entry=00c23c20 name=FUN_00c23c20 size=4 ====

undefined8 FUN_00c23c20(undefined8 param_1)

{
  return param_1;
}


// ==== entry=00c23c30 name=FUN_00c23c30 size=212 ====

ulong FUN_00c23c30(long *param_1,wchar_t *param_2,ulong param_3,ulong param_4)

{
  wchar_t __c;
  ulong uVar1;
  long lVar2;
  int iVar3;
  wchar_t *pwVar4;
  ulong uVar5;
  size_t __n;
  
  uVar1 = param_1[1];
  if (param_4 == 0) {
    uVar5 = 0xffffffffffffffff;
    if (param_3 <= uVar1) {
      uVar5 = param_3;
    }
    return uVar5;
  }
  if ((uVar1 <= param_3) || (uVar1 - param_3 < param_4)) {
    return 0xffffffffffffffff;
  }
  __n = (uVar1 - param_3) + (1 - param_4);
  if (__n != 0) {
    lVar2 = *param_1;
    __c = *param_2;
    pwVar4 = (wchar_t *)(lVar2 + param_3 * 4);
    while (pwVar4 = wmemchr(pwVar4,__c,__n), pwVar4 != (wchar_t *)0x0) {
      iVar3 = wmemcmp(pwVar4,param_2,param_4);
      if (iVar3 == 0) {
        return (long)pwVar4 - lVar2 >> 2;
      }
      pwVar4 = pwVar4 + 1;
      uVar5 = (long)((lVar2 + uVar1 * 4) - (long)pwVar4) >> 2;
      if (uVar5 < param_4) {
        return 0xffffffffffffffff;
      }
      __n = uVar5 + (1 - param_4);
      if (__n == 0) {
        return 0xffffffffffffffff;
      }
    }
  }
  return 0xffffffffffffffff;
}


// ==== entry=00c23d20 name=FUN_00c23d20 size=12 ====

void FUN_00c23d20(undefined8 param_1,undefined8 *param_2,undefined8 param_3)

{
  FUN_00c23c30(param_1,*param_2,param_3,param_2[1]);
  return;
}


// ==== entry=00c23d30 name=FUN_00c23d30 size=42 ====

void FUN_00c23d30(undefined8 param_1,wchar_t *param_2,undefined8 param_3)

{
  size_t sVar1;
  
  sVar1 = wcslen(param_2);
  FUN_00c23c30(param_1,param_2,param_3,sVar1);
  return;
}


// ==== entry=00c23d60 name=FUN_00c23d60 size=71 ====

long FUN_00c23d60(long *param_1,wchar_t param_2,ulong param_3)

{
  long lVar1;
  wchar_t *pwVar2;
  long lVar3;
  
  lVar3 = -1;
  if (param_3 < (ulong)param_1[1]) {
    lVar1 = *param_1;
    pwVar2 = wmemchr((wchar_t *)(lVar1 + param_3 * 4),param_2,param_1[1] - param_3);
    if (pwVar2 != (wchar_t *)0x0) {
      lVar3 = (long)pwVar2 - lVar1 >> 2;
    }
  }
  return lVar3;
}


// ==== entry=00c23db0 name=FUN_00c23db0 size=113 ====

ulong FUN_00c23db0(long *param_1,wchar_t *param_2,ulong param_3,size_t param_4)

{
  long lVar1;
  int iVar2;
  ulong uVar3;
  bool bVar4;
  
  if (param_4 <= (ulong)param_1[1]) {
    uVar3 = param_1[1] - param_4;
    lVar1 = *param_1;
    if (uVar3 <= param_3) {
      param_3 = uVar3;
    }
    do {
      if (param_4 == 0) {
        return param_3;
      }
      iVar2 = wmemcmp((wchar_t *)(lVar1 + param_3 * 4),param_2,param_4);
      if (iVar2 == 0) {
        return param_3;
      }
      bVar4 = param_3 != 0;
      param_3 = param_3 - 1;
    } while (bVar4);
  }
  return 0xffffffffffffffff;
}


// ==== entry=00c23e30 name=FUN_00c23e30 size=12 ====

void FUN_00c23e30(undefined8 param_1,undefined8 *param_2,undefined8 param_3)

{
  FUN_00c23db0(param_1,*param_2,param_3,param_2[1]);
  return;
}


// ==== entry=00c23e40 name=FUN_00c23e40 size=42 ====

void FUN_00c23e40(undefined8 param_1,wchar_t *param_2,undefined8 param_3)

{
  size_t sVar1;
  
  sVar1 = wcslen(param_2);
  FUN_00c23db0(param_1,param_2,param_3,sVar1);
  return;
}


// ==== entry=00c23e70 name=FUN_00c23e70 size=48 ====

void FUN_00c23e70(long *param_1,int param_2,ulong param_3)

{
  ulong uVar1;
  
  if (param_1[1] != 0) {
    uVar1 = param_1[1] - 1;
    if (param_3 < uVar1) {
      uVar1 = param_3;
    }
    do {
      if (*(int *)(*param_1 + uVar1 * 4) == param_2) {
        return;
      }
      uVar1 = uVar1 - 1;
    } while (uVar1 != 0xffffffffffffffff);
  }
  return;
}


// ==== entry=00c23ea0 name=FUN_00c23ea0 size=101 ====

ulong FUN_00c23ea0(long *param_1,wchar_t *param_2,ulong param_3,size_t param_4)

{
  ulong uVar1;
  long lVar2;
  wchar_t *pwVar3;
  
  if (param_4 == 0) {
    return 0xffffffffffffffff;
  }
  uVar1 = param_1[1];
  if (param_3 < uVar1) {
    lVar2 = *param_1;
    do {
      pwVar3 = wmemchr(param_2,*(wchar_t *)(lVar2 + param_3 * 4),param_4);
      if (pwVar3 != (wchar_t *)0x0) {
        return param_3;
      }
      param_3 = param_3 + 1;
    } while (param_3 != uVar1);
  }
  return 0xffffffffffffffff;
}


// ==== entry=00c23f10 name=FUN_00c23f10 size=12 ====

void FUN_00c23f10(undefined8 param_1,undefined8 *param_2,undefined8 param_3)

{
  FUN_00c23ea0(param_1,*param_2,param_3,param_2[1]);
  return;
}


// ==== entry=00c23f20 name=FUN_00c23f20 size=42 ====

void FUN_00c23f20(undefined8 param_1,wchar_t *param_2,undefined8 param_3)

{
  size_t sVar1;
  
  sVar1 = wcslen(param_2);
  FUN_00c23ea0(param_1,param_2,param_3,sVar1);
  return;
}


// ==== entry=00c23f50 orig=FUN_00c23f50 size=5 name=thunk_FUN_00c23d60 ====

long thunk_FUN_00c23d60(long *param_1,wchar_t param_2,ulong param_3)

{
  long lVar1;
  wchar_t *pwVar2;
  long lVar3;
  
  lVar3 = -1;
  if (param_3 < (ulong)param_1[1]) {
    lVar1 = *param_1;
    pwVar2 = wmemchr((wchar_t *)(lVar1 + param_3 * 4),param_2,param_1[1] - param_3);
    if (pwVar2 != (wchar_t *)0x0) {
      lVar3 = (long)pwVar2 - lVar1 >> 2;
    }
  }
  return lVar3;
}


// ==== entry=00c23f60 name=FUN_00c23f60 size=115 ====

ulong FUN_00c23f60(long *param_1,wchar_t *param_2,ulong param_3,size_t param_4)

{
  long lVar1;
  ulong uVar2;
  wchar_t *pwVar3;
  
  if ((param_1[1] != 0) && (param_4 != 0)) {
    uVar2 = param_1[1] - 1;
    lVar1 = *param_1;
    if (uVar2 <= param_3) {
      param_3 = uVar2;
    }
    do {
      pwVar3 = wmemchr(param_2,*(wchar_t *)(lVar1 + param_3 * 4),param_4);
      if (pwVar3 != (wchar_t *)0x0) {
        return param_3;
      }
      param_3 = param_3 - 1;
    } while (param_3 != 0xffffffffffffffff);
    return 0xffffffffffffffff;
  }
  return 0xffffffffffffffff;
}


// ==== entry=00c23fe0 name=FUN_00c23fe0 size=12 ====

void FUN_00c23fe0(undefined8 param_1,undefined8 *param_2,undefined8 param_3)

{
  FUN_00c23f60(param_1,*param_2,param_3,param_2[1]);
  return;
}


// ==== entry=00c23ff0 name=FUN_00c23ff0 size=42 ====

void FUN_00c23ff0(undefined8 param_1,wchar_t *param_2,undefined8 param_3)

{
  size_t sVar1;
  
  sVar1 = wcslen(param_2);
  FUN_00c23f60(param_1,param_2,param_3,sVar1);
  return;
}


// ==== entry=00c24020 orig=FUN_00c24020 size=5 name=thunk_FUN_00c23e70 ====

void thunk_FUN_00c23e70(long *param_1,int param_2,ulong param_3)

{
  ulong uVar1;
  
  if (param_1[1] != 0) {
    uVar1 = param_1[1] - 1;
    if (param_3 < uVar1) {
      uVar1 = param_3;
    }
    do {
      if (*(int *)(*param_1 + uVar1 * 4) == param_2) {
        return;
      }
      uVar1 = uVar1 - 1;
    } while (uVar1 != 0xffffffffffffffff);
  }
  return;
}


// ==== entry=00c24030 name=FUN_00c24030 size=96 ====

ulong FUN_00c24030(long *param_1,wchar_t *param_2,ulong param_3,size_t param_4)

{
  ulong uVar1;
  long lVar2;
  wchar_t *pwVar3;
  
  uVar1 = param_1[1];
  if (param_3 < uVar1) {
    if (param_4 == 0) {
      return param_3;
    }
    lVar2 = *param_1;
    do {
      pwVar3 = wmemchr(param_2,*(wchar_t *)(lVar2 + param_3 * 4),param_4);
      if (pwVar3 == (wchar_t *)0x0) {
        return param_3;
      }
      param_3 = param_3 + 1;
    } while (param_3 != uVar1);
  }
  return 0xffffffffffffffff;
}


// ==== entry=00c240a0 name=FUN_00c240a0 size=12 ====

void FUN_00c240a0(undefined8 param_1,undefined8 *param_2,undefined8 param_3)

{
  FUN_00c24030(param_1,*param_2,param_3,param_2[1]);
  return;
}


// ==== entry=00c240b0 name=FUN_00c240b0 size=42 ====

void FUN_00c240b0(undefined8 param_1,wchar_t *param_2,undefined8 param_3)

{
  size_t sVar1;
  
  sVar1 = wcslen(param_2);
  FUN_00c24030(param_1,param_2,param_3,sVar1);
  return;
}


// ==== entry=00c240e0 name=FUN_00c240e0 size=52 ====

ulong FUN_00c240e0(long *param_1,int param_2,ulong param_3)

{
  int iVar1;
  ulong uVar2;
  
  uVar2 = 0xffffffffffffffff;
  if (param_3 < (ulong)param_1[1]) {
    iVar1 = *(int *)(*param_1 + param_3 * 4);
    uVar2 = param_3;
    while (param_2 == iVar1) {
      uVar2 = uVar2 + 1;
      if (uVar2 == param_1[1]) {
        return 0xffffffffffffffff;
      }
      iVar1 = *(int *)(*param_1 + uVar2 * 4);
    }
  }
  return uVar2;
}


// ==== entry=00c24130 name=FUN_00c24130 size=98 ====

ulong FUN_00c24130(long *param_1,wchar_t *param_2,ulong param_3,size_t param_4)

{
  long lVar1;
  wchar_t *pwVar2;
  ulong uVar3;
  
  uVar3 = 0xffffffffffffffff;
  if (param_1[1] != 0) {
    uVar3 = param_1[1] - 1;
    lVar1 = *param_1;
    if (uVar3 <= param_3) {
      param_3 = uVar3;
    }
    do {
      if (param_4 == 0) {
        return param_3;
      }
      pwVar2 = wmemchr(param_2,*(wchar_t *)(lVar1 + param_3 * 4),param_4);
      if (pwVar2 == (wchar_t *)0x0) {
        return param_3;
      }
      uVar3 = param_3 - 1;
      param_3 = uVar3;
    } while (uVar3 != 0xffffffffffffffff);
  }
  return uVar3;
}


// ==== entry=00c241a0 name=FUN_00c241a0 size=12 ====

void FUN_00c241a0(undefined8 param_1,undefined8 *param_2,undefined8 param_3)

{
  FUN_00c24130(param_1,*param_2,param_3,param_2[1]);
  return;
}


// ==== entry=00c241b0 name=FUN_00c241b0 size=42 ====

void FUN_00c241b0(undefined8 param_1,wchar_t *param_2,undefined8 param_3)

{
  size_t sVar1;
  
  sVar1 = wcslen(param_2);
  FUN_00c24130(param_1,param_2,param_3,sVar1);
  return;
}


// ==== entry=00c241e0 name=FUN_00c241e0 size=47 ====

void FUN_00c241e0(long *param_1,int param_2,ulong param_3)

{
  ulong uVar1;
  
  if (param_1[1] != 0) {
    uVar1 = param_1[1] - 1;
    if (param_3 < uVar1) {
      uVar1 = param_3;
    }
    do {
      if (*(int *)(*param_1 + uVar1 * 4) != param_2) {
        return;
      }
      uVar1 = uVar1 - 1;
    } while (uVar1 != 0xffffffffffffffff);
  }
  return;
}


// ==== entry=00c24210 name=FUN_00c24210 size=81 ====

ulong FUN_00c24210(undefined8 *param_1,undefined8 *param_2)

{
  uint uVar1;
  ulong uVar2;
  ulong __n;
  ulong uVar3;
  
  uVar3 = param_1[1];
  uVar2 = param_2[1];
  __n = uVar3;
  if (uVar2 <= uVar3) {
    __n = uVar2;
  }
  if (__n != 0) {
    uVar1 = wmemcmp((wchar_t *)*param_1,(wchar_t *)*param_2,__n);
    if (uVar1 != 0) {
      return (ulong)uVar1;
    }
  }
  uVar3 = uVar3 - uVar2;
  uVar2 = 0x7fffffff;
  if (((long)uVar3 < 0x80000000) && (uVar2 = 0x80000000, -0x80000001 < (long)uVar3)) {
    uVar2 = uVar3 & 0xffffffff;
  }
  return uVar2;
}


// ==== entry=00c24270 orig=FUN_00c24270 size=134 name=s_basic_string__compare_c24270 ====

ulong s_basic_string__compare_c24270(long *param_1,ulong param_2,ulong param_3,undefined8 *param_4)

{
  ulong uVar1;
  uint uVar2;
  ulong uVar3;
  ulong uVar4;
  
  uVar3 = param_1[1];
  if (uVar3 < param_2) {
                    /* WARNING: Subroutine does not return */
    std::__throw_out_of_range_fmt
              ("%s: __pos (which is %zu) > this->size() (which is %zu)","basic_string::compare",
               param_2,uVar3);
  }
  uVar1 = param_4[1];
  uVar4 = uVar3 - param_2;
  if (param_3 < uVar3 - param_2) {
    uVar4 = param_3;
  }
  uVar3 = uVar4;
  if (uVar1 <= uVar4) {
    uVar3 = uVar1;
  }
  if (uVar3 != 0) {
    uVar2 = wmemcmp((wchar_t *)(*param_1 + param_2 * 4),(wchar_t *)*param_4,uVar3);
    if (uVar2 != 0) {
      return (ulong)uVar2;
    }
  }
  uVar4 = uVar4 - uVar1;
  uVar3 = 0x7fffffff;
  if (((long)uVar4 < 0x80000000) && (uVar3 = 0x80000000, -0x80000001 < (long)uVar4)) {
    uVar3 = uVar4 & 0xffffffff;
  }
  return uVar3;
}


// ==== entry=00c24300 orig=FUN_00c24300 size=187 name=s_basic_string__compare_c24300 ====

ulong s_basic_string__compare_c24300
                (long *param_1,ulong param_2,ulong param_3,long *param_4,ulong param_5,ulong param_6
                )

{
  uint uVar1;
  ulong uVar2;
  ulong uVar3;
  ulong uVar4;
  
  uVar2 = param_1[1];
  if (uVar2 < param_2) {
                    /* WARNING: Subroutine does not return */
    std::__throw_out_of_range_fmt
              ("%s: __pos (which is %zu) > this->size() (which is %zu)","basic_string::compare",
               param_2,uVar2);
  }
  uVar3 = param_4[1];
  if (param_5 <= uVar3) {
    uVar4 = uVar2 - param_2;
    if (param_3 < uVar2 - param_2) {
      uVar4 = param_3;
    }
    uVar2 = uVar3 - param_5;
    if (param_6 < uVar3 - param_5) {
      uVar2 = param_6;
    }
    uVar3 = uVar4;
    if (uVar2 <= uVar4) {
      uVar3 = uVar2;
    }
    if (uVar3 != 0) {
      uVar1 = wmemcmp((wchar_t *)(*param_1 + param_2 * 4),(wchar_t *)(*param_4 + param_5 * 4),uVar3)
      ;
      if (uVar1 != 0) {
        return (ulong)uVar1;
      }
    }
    uVar4 = uVar4 - uVar2;
    uVar2 = 0x7fffffff;
    if (((long)uVar4 < 0x80000000) && (uVar2 = 0x80000000, -0x80000001 < (long)uVar4)) {
      uVar2 = uVar4 & 0xffffffff;
    }
    return uVar2;
  }
                    /* WARNING: Subroutine does not return */
  std::__throw_out_of_range_fmt
            ("%s: __pos (which is %zu) > this->size() (which is %zu)","basic_string::compare",
             param_5,uVar3);
}


// ==== entry=00c243c0 name=FUN_00c243c0 size=103 ====

ulong FUN_00c243c0(undefined8 *param_1,wchar_t *param_2)

{
  uint uVar1;
  size_t sVar2;
  ulong uVar3;
  ulong uVar4;
  
  uVar4 = param_1[1];
  sVar2 = wcslen(param_2);
  uVar3 = uVar4;
  if (sVar2 <= uVar4) {
    uVar3 = sVar2;
  }
  if (uVar3 != 0) {
    uVar1 = wmemcmp((wchar_t *)*param_1,param_2,uVar3);
    if (uVar1 != 0) {
      return (ulong)uVar1;
    }
  }
  uVar4 = uVar4 - sVar2;
  uVar3 = 0x7fffffff;
  if (((long)uVar4 < 0x80000000) && (uVar3 = 0x80000000, -0x80000001 < (long)uVar4)) {
    uVar3 = uVar4 & 0xffffffff;
  }
  return uVar3;
}


// ==== entry=00c24430 orig=FUN_00c24430 size=157 name=s_basic_string__compare_c24430 ====

ulong s_basic_string__compare_c24430(long *param_1,ulong param_2,ulong param_3,wchar_t *param_4)

{
  uint uVar1;
  size_t sVar2;
  ulong uVar3;
  ulong uVar4;
  
  uVar3 = param_1[1];
  if (uVar3 < param_2) {
                    /* WARNING: Subroutine does not return */
    std::__throw_out_of_range_fmt
              ("%s: __pos (which is %zu) > this->size() (which is %zu)","basic_string::compare",
               param_2,uVar3);
  }
  uVar4 = uVar3 - param_2;
  if (param_3 < uVar3 - param_2) {
    uVar4 = param_3;
  }
  sVar2 = wcslen(param_4);
  uVar3 = uVar4;
  if (sVar2 <= uVar4) {
    uVar3 = sVar2;
  }
  if (uVar3 != 0) {
    uVar1 = wmemcmp((wchar_t *)(*param_1 + param_2 * 4),param_4,uVar3);
    if (uVar1 != 0) {
      return (ulong)uVar1;
    }
  }
  uVar4 = uVar4 - sVar2;
  uVar3 = 0x7fffffff;
  if (((long)uVar4 < 0x80000000) && (uVar3 = 0x80000000, -0x80000001 < (long)uVar4)) {
    uVar3 = uVar4 & 0xffffffff;
  }
  return uVar3;
}


// ==== entry=00c244d0 orig=FUN_00c244d0 size=133 name=s_basic_string__compare_c244d0 ====

ulong s_basic_string__compare_c244d0
                (long *param_1,ulong param_2,ulong param_3,wchar_t *param_4,ulong param_5)

{
  uint uVar1;
  ulong uVar2;
  ulong uVar3;
  
  uVar2 = param_1[1];
  if (uVar2 < param_2) {
                    /* WARNING: Subroutine does not return */
    std::__throw_out_of_range_fmt
              ("%s: __pos (which is %zu) > this->size() (which is %zu)","basic_string::compare",
               param_2,uVar2);
  }
  uVar3 = uVar2 - param_2;
  if (param_3 < uVar2 - param_2) {
    uVar3 = param_3;
  }
  uVar2 = param_5;
  if (uVar3 <= param_5) {
    uVar2 = uVar3;
  }
  if (uVar2 != 0) {
    uVar1 = wmemcmp((wchar_t *)(*param_1 + param_2 * 4),param_4,uVar2);
    if (uVar1 != 0) {
      return (ulong)uVar1;
    }
  }
  uVar3 = uVar3 - param_5;
  uVar2 = 0x7fffffff;
  if (((long)uVar3 < 0x80000000) && (uVar2 = 0x80000000, -0x80000001 < (long)uVar3)) {
    uVar2 = uVar3 & 0xffffffff;
  }
  return uVar2;
}


// ==== entry=00c24560 name=FUN_00c24560 size=4 ====

void FUN_00c24560(undefined8 *param_1,undefined8 param_2)

{
  *param_1 = param_2;
  return;
}


// ==== entry=00c24570 name=FUN_00c24570 size=4 ====

void FUN_00c24570(undefined8 *param_1,undefined8 param_2)

{
  *param_1 = param_2;
  return;
}


// ==== entry=00c24580 orig=FUN_00c24580 size=140 name=s_basic_string__append_c24580 ====

long * s_basic_string__append_c24580(long *param_1,wchar_t *param_2,undefined8 *param_3)

{
  long lVar1;
  size_t sVar2;
  
  sVar2 = wcslen(param_2);
  param_1[1] = 0;
  lVar1 = param_3[1];
  *param_1 = (long)(param_1 + 2);
  *(undefined4 *)(param_1 + 2) = 0;
                    /* try { // try from 00c245bd to 00c2460b has its CatchHandler @ 00c2460c */
  FUN_00c22600(param_1,lVar1 + sVar2);
  if (sVar2 <= 0x1fffffffffffffffU - param_1[1]) {
    FUN_00c237b0(param_1,param_2,sVar2);
    FUN_00c237b0(param_1,*param_3,param_3[1]);
    return param_1;
  }
                    /* WARNING: Subroutine does not return */
  std::__throw_length_error("basic_string::append");
}


// ==== entry=00c24630 name=FUN_00c24630 size=106 ====

long * FUN_00c24630(long *param_1,undefined4 param_2,undefined8 *param_3)

{
  long lVar1;
  
  param_1[1] = 0;
  lVar1 = param_3[1];
  *param_1 = (long)(param_1 + 2);
  *(undefined4 *)(param_1 + 2) = 0;
                    /* try { // try from 00c24661 to 00c2468b has its CatchHandler @ 00c2469a */
  FUN_00c22600(param_1,lVar1 + 1);
  FUN_00c22b10(param_1,param_1[1],0,1,param_2);
  FUN_00c237b0(param_1,*param_3,param_3[1]);
  return param_1;
}


// ==== entry=00c246c0 name=FUN_00c246c0 size=160 ====

void FUN_00c246c0(undefined8 *param_1,wchar_t *param_2,long param_3)

{
  wchar_t *__s1;
  ulong __n;
  long in_FS_OFFSET;
  ulong local_28;
  long local_20;
  
  __n = param_3 - (long)param_2 >> 2;
  local_20 = *(long *)(in_FS_OFFSET + 0x28);
  local_28 = __n;
  if (__n < 4) {
    __s1 = (wchar_t *)*param_1;
    if (__n == 1) {
      *__s1 = *param_2;
      goto LAB_00c24702;
    }
    if (__n == 0) goto LAB_00c24702;
  }
  else {
    __s1 = (wchar_t *)FUN_00c21cd0(param_1,&local_28,0);
    *param_1 = __s1;
    param_1[2] = local_28;
  }
  wmemcpy(__s1,param_2,__n);
  __s1 = (wchar_t *)*param_1;
LAB_00c24702:
  param_1[1] = local_28;
  __s1[local_28] = L'\0';
  if (local_20 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


// ==== entry=00c24780 name=FUN_00c24780 size=12 ====

void FUN_00c24780(long *param_1)

{
  *param_1 = (long)(param_1 + 2);
  FUN_00c246c0();
  return;
}


// ==== entry=00c24790 name=FUN_00c24790 size=160 ====

void FUN_00c24790(undefined8 *param_1,wchar_t *param_2,long param_3)

{
  wchar_t *__s1;
  ulong __n;
  long in_FS_OFFSET;
  ulong local_28;
  long local_20;
  
  __n = param_3 - (long)param_2 >> 2;
  local_20 = *(long *)(in_FS_OFFSET + 0x28);
  local_28 = __n;
  if (__n < 4) {
    __s1 = (wchar_t *)*param_1;
    if (__n == 1) {
      *__s1 = *param_2;
      goto LAB_00c247d2;
    }
    if (__n == 0) goto LAB_00c247d2;
  }
  else {
    __s1 = (wchar_t *)FUN_00c21cd0(param_1,&local_28,0);
    *param_1 = __s1;
    param_1[2] = local_28;
  }
  wmemcpy(__s1,param_2,__n);
  __s1 = (wchar_t *)*param_1;
LAB_00c247d2:
  param_1[1] = local_28;
  __s1[local_28] = L'\0';
  if (local_20 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


// ==== entry=00c24850 name=FUN_00c24850 size=26 ====

void FUN_00c24850(long *param_1,long *param_2)

{
  long lVar1;
  
  lVar1 = param_2[1];
  *param_1 = (long)(param_1 + 2);
  FUN_00c24790(param_1,*param_2,*param_2 + lVar1 * 4);
  return;
}


// ==== entry=00c24870 name=FUN_00c24870 size=192 ====

void FUN_00c24870(undefined8 *param_1,wchar_t *param_2,long param_3)

{
  wchar_t *__s1;
  ulong __n;
  long in_FS_OFFSET;
  ulong local_28;
  long local_20;
  
  local_20 = *(long *)(in_FS_OFFSET + 0x28);
  if ((param_2 == (wchar_t *)0x0) && (param_3 != 0)) {
                    /* WARNING: Subroutine does not return */
    std::__throw_logic_error("basic_string::_M_construct null not valid");
  }
  __n = param_3 - (long)param_2 >> 2;
  local_28 = __n;
  if (__n < 4) {
    __s1 = (wchar_t *)*param_1;
    if (__n == 1) {
      *__s1 = *param_2;
      goto LAB_00c248c3;
    }
    if (__n == 0) goto LAB_00c248c3;
  }
  else {
    __s1 = (wchar_t *)FUN_00c21cd0(param_1,&local_28,0);
    *param_1 = __s1;
    param_1[2] = local_28;
  }
  wmemcpy(__s1,param_2,__n);
  __s1 = (wchar_t *)*param_1;
LAB_00c248c3:
  param_1[1] = local_28;
  __s1[local_28] = L'\0';
  if (local_20 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


// ==== entry=00c24950 name=FUN_00c24950 size=26 ====

void FUN_00c24950(long *param_1,long *param_2)

{
  long lVar1;
  
  lVar1 = param_2[1];
  *param_1 = (long)(param_1 + 2);
  FUN_00c24870(param_1,*param_2,*param_2 + lVar1 * 4);
  return;
}


// ==== entry=00c24970 name=FUN_00c24970 size=60 ====

long * FUN_00c24970(long *param_1,long *param_2,undefined8 *param_3)

{
  long lVar1;
  
  lVar1 = param_2[1];
  *param_1 = (long)(param_1 + 2);
  FUN_00c24870(param_1,*param_2,*param_2 + lVar1 * 4);
                    /* try { // try from 00c2499f to 00c249a3 has its CatchHandler @ 00c249ac */
  FUN_00c237b0(param_1,*param_3,param_3[1]);
  return param_1;
}


// ==== entry=00c249d0 name=FUN_00c249d0 size=12 ====

void FUN_00c249d0(long *param_1)

{
  *param_1 = (long)(param_1 + 2);
  FUN_00c24870();
  return;
}


// ==== entry=00c249e0 name=FUN_00c249e0 size=192 ====

void FUN_00c249e0(undefined8 *param_1,wchar_t *param_2,long param_3)

{
  wchar_t *__s1;
  ulong __n;
  long in_FS_OFFSET;
  ulong local_28;
  long local_20;
  
  local_20 = *(long *)(in_FS_OFFSET + 0x28);
  if ((param_2 == (wchar_t *)0x0) && (param_3 != 0)) {
                    /* WARNING: Subroutine does not return */
    std::__throw_logic_error("basic_string::_M_construct null not valid");
  }
  __n = param_3 - (long)param_2 >> 2;
  local_28 = __n;
  if (__n < 4) {
    __s1 = (wchar_t *)*param_1;
    if (__n == 1) {
      *__s1 = *param_2;
      goto LAB_00c24a33;
    }
    if (__n == 0) goto LAB_00c24a33;
  }
  else {
    __s1 = (wchar_t *)FUN_00c21cd0(param_1,&local_28,0);
    *param_1 = __s1;
    param_1[2] = local_28;
  }
  wmemcpy(__s1,param_2,__n);
  __s1 = (wchar_t *)*param_1;
LAB_00c24a33:
  param_1[1] = local_28;
  __s1[local_28] = L'\0';
  if (local_20 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


// ==== entry=00c24ac0 orig=FUN_00c24ac0 size=57 name=s_basic_string__basic_string_c24ac0 ====

void s_basic_string__basic_string_c24ac0(long *param_1,long *param_2,ulong param_3)

{
  long lVar1;
  ulong uVar2;
  
  uVar2 = param_2[1];
  *param_1 = (long)(param_1 + 2);
  if (param_3 <= uVar2) {
    lVar1 = *param_2 + param_3 * 4;
    FUN_00c249e0(param_1,lVar1,lVar1 + (uVar2 - param_3) * 4);
    return;
  }
                    /* WARNING: Subroutine does not return */
  std::__throw_out_of_range_fmt
            ("%s: __pos (which is %zu) > this->size() (which is %zu)","basic_string::basic_string");
}


// ==== entry=00c24b00 orig=FUN_00c24b00 size=67 name=s_basic_string__basic_string_c24b00 ====

void s_basic_string__basic_string_c24b00
               (long *param_1,long *param_2,ulong param_3,ulong param_4,undefined8 param_5,
               undefined8 param_6)

{
  long lVar1;
  ulong uVar2;
  ulong uVar3;
  
  *param_1 = (long)(param_1 + 2);
  uVar2 = param_2[1];
  if (param_3 <= uVar2) {
    lVar1 = *param_2 + param_3 * 4;
    uVar3 = uVar2 - param_3;
    if (param_4 < uVar2 - param_3) {
      uVar3 = param_4;
    }
    FUN_00c249e0(param_1,lVar1,lVar1 + uVar3 * 4);
    return;
  }
                    /* WARNING: Subroutine does not return */
  std::__throw_out_of_range_fmt
            ("%s: __pos (which is %zu) > this->size() (which is %zu)","basic_string::basic_string",
             param_3,uVar2,*param_2,param_6,param_4);
}


// ==== entry=00c24b50 orig=FUN_00c24b50 size=67 name=s_string__string_c24b50 ====

void s_string__string_c24b50
               (long *param_1,long *param_2,ulong param_3,ulong param_4,undefined8 param_5,
               undefined8 param_6)

{
  long lVar1;
  ulong uVar2;
  ulong uVar3;
  
  *param_1 = (long)(param_1 + 2);
  uVar2 = param_2[1];
  if (param_3 <= uVar2) {
    lVar1 = *param_2 + param_3 * 4;
    uVar3 = uVar2 - param_3;
    if (param_4 < uVar2 - param_3) {
      uVar3 = param_4;
    }
    FUN_00c249e0(param_1,lVar1,lVar1 + uVar3 * 4);
    return;
  }
                    /* WARNING: Subroutine does not return */
  std::__throw_out_of_range_fmt
            ("%s: __pos (which is %zu) > this->size() (which is %zu)","string::string",param_3,uVar2
             ,*param_2,param_6,param_4);
}


// ==== entry=00c24ba0 name=FUN_00c24ba0 size=16 ====

void FUN_00c24ba0(long *param_1,long param_2,long param_3)

{
  *param_1 = (long)(param_1 + 2);
  FUN_00c249e0(param_1,param_2,param_2 + param_3 * 4);
  return;
}


// ==== entry=00c24bb0 name=FUN_00c24bb0 size=60 ====

void FUN_00c24bb0(long *param_1,wchar_t *param_2)

{
  size_t sVar1;
  wchar_t *pwVar2;
  
  pwVar2 = (wchar_t *)0xfffffffffffffffc;
  *param_1 = (long)(param_1 + 2);
  if (param_2 != (wchar_t *)0x0) {
    sVar1 = wcslen(param_2);
    pwVar2 = param_2 + sVar1;
  }
  FUN_00c249e0(param_1,param_2,pwVar2);
  return;
}


// ==== entry=00c24bf0 name=FUN_00c24bf0 size=16 ====

void FUN_00c24bf0(long *param_1,long param_2,long param_3)

{
  *param_1 = (long)(param_1 + 2);
  FUN_00c249e0(param_1,param_2,param_2 + param_3 * 4);
  return;
}


// ==== entry=00c24c00 name=FUN_00c24c00 size=12 ====

void FUN_00c24c00(long *param_1)

{
  *param_1 = (long)(param_1 + 2);
  FUN_00c249e0();
  return;
}


// ==== entry=00c24c10 orig=FUN_00c24c10 size=78 name=s_basic_string__substr_c24c10 ====

long * s_basic_string__substr_c24c10(long *param_1,long *param_2,ulong param_3,ulong param_4)

{
  long lVar1;
  ulong uVar2;
  ulong uVar3;
  
  uVar2 = param_2[1];
  if (param_3 <= uVar2) {
    *param_1 = (long)(param_1 + 2);
    uVar3 = uVar2 - param_3;
    if (param_4 < uVar2 - param_3) {
      uVar3 = param_4;
    }
    lVar1 = *param_2 + param_3 * 4;
    FUN_00c249e0(param_1,lVar1,lVar1 + uVar3 * 4);
    return param_1;
  }
                    /* WARNING: Subroutine does not return */
  std::__throw_out_of_range_fmt
            ("%s: __pos (which is %zu) > this->size() (which is %zu)","basic_string::substr",param_3
             ,uVar2);
}


// ==== entry=00c24c60 name=FUN_00c24c60 size=10 ====

undefined8 FUN_00c24c60(long *param_1,long *param_2)

{
  return CONCAT71((int7)((ulong)*param_2 >> 8),*param_1 == *param_2);
}


// ==== entry=00c24c70 name=FUN_00c24c70 size=10 ====

undefined8 FUN_00c24c70(long *param_1,long *param_2)

{
  return CONCAT71((int7)((ulong)*param_2 >> 8),*param_1 == *param_2);
}


// ==== entry=00c24c80 name=FUN_00c24c80 size=1867 ====

/* WARNING: Removing unreachable block (ram,0x00c25320) */
/* WARNING: Removing unreachable block (ram,0x00c25340) */
/* WARNING: Removing unreachable block (ram,0x00c25360) */
/* WARNING: Removing unreachable block (ram,0x00c25380) */
/* WARNING: Removing unreachable block (ram,0x00c253a0) */
/* WARNING: Removing unreachable block (ram,0x00c253c0) */
/* WARNING: Removing unreachable block (ram,0x00c253e0) */
/* WARNING: Removing unreachable block (ram,0x00c25300) */
/* WARNING: Removing unreachable block (ram,0x00c253f0) */
/* WARNING: Removing unreachable block (ram,0x00c253d0) */
/* WARNING: Removing unreachable block (ram,0x00c253b0) */
/* WARNING: Removing unreachable block (ram,0x00c25390) */
/* WARNING: Removing unreachable block (ram,0x00c25370) */
/* WARNING: Removing unreachable block (ram,0x00c25350) */
/* WARNING: Removing unreachable block (ram,0x00c25330) */
/* WARNING: Removing unreachable block (ram,0x00c25310) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00c24c80(long param_1,undefined8 *param_2)

{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  long lVar7;
  long lVar8;
  long lVar9;
  
  uVar1 = *param_2;
  uVar2 = param_2[1];
  uVar3 = param_2[2];
  _DAT_011c52d8 = 1;
  _DAT_011c52d0 = &PTR__numpunct_011b5510;
  _DAT_011c52e0 = uVar1;
                    /* try { // try from 00c24ccb to 00c24ccf has its CatchHandler @ 00c2542c */
  std::numpunct<char>::_M_initialize_numpunct
            ((numpunct<char> *)&DAT_011c52d0,(__locale_struct *)0x0);
  LOCK();
  _DAT_011c52d8 = _DAT_011c52d8 + 1;
  UNLOCK();
  lVar9 = *(long *)(param_1 + 8);
  lVar7 = std::locale::id::_M_id((id *)&std::numpunct<char>::id);
  *(undefined **)(lVar9 + lVar7 * 8) = &DAT_011c52d0;
  _DAT_011c52f8 = 1;
  _DAT_011c52f0 = &PTR__collate_011b54a0;
                    /* try { // try from 00c24d29 to 00c24d2d has its CatchHandler @ 00c25404 */
  _DAT_011c5300 = std::locale::facet::_S_get_c_locale();
  LOCK();
  _DAT_011c52f8 = _DAT_011c52f8 + 1;
  UNLOCK();
  lVar9 = *(long *)(param_1 + 8);
  lVar7 = std::locale::id::_M_id((id *)&std::collate<char>::id);
  *(undefined **)(lVar9 + lVar7 * 8) = &DAT_011c52f0;
  _DAT_011c5298 = 1;
  _DAT_011c5290 = &PTR__moneypunct_011b5720;
  _DAT_011c52a0 = uVar2;
                    /* try { // try from 00c24d99 to 00c24d9d has its CatchHandler @ 00c253fc */
  std::moneypunct<char,false>::_M_initialize_moneypunct
            ((__locale_struct *)&DAT_011c5290,(char *)0x0);
  LOCK();
  _DAT_011c5298 = _DAT_011c5298 + 1;
  UNLOCK();
  lVar9 = *(long *)(param_1 + 8);
  lVar7 = std::locale::id::_M_id((id *)&std::moneypunct<char,false>::id);
  *(undefined **)(lVar9 + lVar7 * 8) = &DAT_011c5290;
  _DAT_011c52b8 = 1;
  _DAT_011c52b0 = &PTR__moneypunct_011b56b8;
  _DAT_011c52c0 = uVar3;
                    /* try { // try from 00c24e02 to 00c24e06 has its CatchHandler @ 00c25414 */
  std::moneypunct<char,true>::_M_initialize_moneypunct((__locale_struct *)&DAT_011c52b0,(char *)0x0)
  ;
  LOCK();
  _DAT_011c52b8 = _DAT_011c52b8 + 1;
  UNLOCK();
  lVar9 = *(long *)(param_1 + 8);
  lVar7 = std::locale::id::_M_id((id *)&std::moneypunct<char,true>::id);
  *(undefined **)(lVar9 + lVar7 * 8) = &DAT_011c52b0;
  _DAT_011c5280 = &PTR__money_get_011b5940;
  LOCK();
  _DAT_011c5288 = 2;
  UNLOCK();
  lVar9 = *(long *)(param_1 + 8);
  lVar7 = std::locale::id::_M_id
                    ((id *)&std::
                            money_get<char,std::istreambuf_iterator<char,std::char_traits<char>>>::
                            id);
  *(undefined **)(lVar9 + lVar7 * 8) = &DAT_011c5280;
  _DAT_011c5270 = &PTR__money_put_011b5970;
  LOCK();
  _DAT_011c5278 = 2;
  UNLOCK();
  lVar9 = *(long *)(param_1 + 8);
  lVar7 = std::locale::id::_M_id
                    ((id *)&std::
                            money_put<char,std::ostreambuf_iterator<char,std::char_traits<char>>>::
                            id);
  *(undefined **)(lVar9 + lVar7 * 8) = &DAT_011c5270;
  _DAT_011c5260 = &PTR__time_get_011b59f0;
  LOCK();
  _DAT_011c5268 = 2;
  UNLOCK();
  lVar9 = *(long *)(param_1 + 8);
  lVar7 = std::locale::id::_M_id
                    ((id *)&std::
                            time_get<char,std::istreambuf_iterator<char,std::char_traits<char>>>::id
                    );
  *(undefined **)(lVar9 + lVar7 * 8) = &DAT_011c5260;
  std::messages<char>::messages((messages<char> *)&DAT_011c5240,1);
  LOCK();
  _DAT_011c5248 = _DAT_011c5248 + 1;
  UNLOCK();
  lVar9 = *(long *)(param_1 + 8);
  lVar7 = std::locale::id::_M_id((id *)&std::messages<char>::id);
  *(undefined **)(lVar9 + lVar7 * 8) = &DAT_011c5240;
  uVar4 = param_2[4];
  _DAT_011c51f8 = 1;
  uVar5 = param_2[3];
  uVar6 = param_2[5];
  _DAT_011c51f0 = &PTR__numpunct_011b6b50;
  _DAT_011c5200 = uVar5;
                    /* try { // try from 00c24fbf to 00c24fc3 has its CatchHandler @ 00c2540c */
  std::numpunct<wchar_t>::_M_initialize_numpunct
            ((numpunct<wchar_t> *)&DAT_011c51f0,(__locale_struct *)0x0);
  LOCK();
  _DAT_011c51f8 = _DAT_011c51f8 + 1;
  UNLOCK();
  lVar9 = *(long *)(param_1 + 8);
  lVar7 = std::locale::id::_M_id((id *)&std::numpunct<wchar_t>::id);
  *(undefined **)(lVar9 + lVar7 * 8) = &DAT_011c51f0;
  _DAT_011c5218 = 1;
  _DAT_011c5210 = &PTR__collate_011b6a60;
                    /* try { // try from 00c25016 to 00c2501a has its CatchHandler @ 00c25424 */
  _DAT_011c5220 = std::locale::facet::_S_get_c_locale();
  LOCK();
  _DAT_011c5218 = _DAT_011c5218 + 1;
  UNLOCK();
  lVar9 = *(long *)(param_1 + 8);
  lVar7 = std::locale::id::_M_id((id *)&std::collate<wchar_t>::id);
  *(undefined **)(lVar9 + lVar7 * 8) = &DAT_011c5210;
  _DAT_011c51b8 = 1;
  _DAT_011c51b0 = &PTR__moneypunct_011b6d60;
  _DAT_011c51c0 = uVar4;
                    /* try { // try from 00c2508b to 00c2508f has its CatchHandler @ 00c2541c */
  std::moneypunct<wchar_t,false>::_M_initialize_moneypunct
            ((__locale_struct *)&DAT_011c51b0,(char *)0x0);
  LOCK();
  _DAT_011c51b8 = _DAT_011c51b8 + 1;
  UNLOCK();
  lVar9 = *(long *)(param_1 + 8);
  lVar7 = std::locale::id::_M_id((id *)&std::moneypunct<wchar_t,false>::id);
  *(undefined **)(lVar9 + lVar7 * 8) = &DAT_011c51b0;
  _DAT_011c51d8 = 1;
  _DAT_011c51d0 = &PTR__moneypunct_011b6cf8;
  _DAT_011c51e0 = uVar6;
                    /* try { // try from 00c250f4 to 00c250f8 has its CatchHandler @ 00c25434 */
  std::moneypunct<wchar_t,true>::_M_initialize_moneypunct
            ((__locale_struct *)&DAT_011c51d0,(char *)0x0);
  LOCK();
  _DAT_011c51d8 = _DAT_011c51d8 + 1;
  UNLOCK();
  lVar9 = *(long *)(param_1 + 8);
  lVar7 = std::locale::id::_M_id((id *)&std::moneypunct<wchar_t,true>::id);
  *(undefined **)(lVar9 + lVar7 * 8) = &DAT_011c51d0;
  _DAT_011c51a0 = &PTR__money_get_011b6f80;
  LOCK();
  _DAT_011c51a8 = 2;
  UNLOCK();
  lVar9 = *(long *)(param_1 + 8);
  lVar7 = std::locale::id::_M_id
                    ((id *)&std::
                            money_get<wchar_t,std::istreambuf_iterator<wchar_t,std::char_traits<wchar_t>>>
                            ::id);
  *(undefined **)(lVar9 + lVar7 * 8) = &DAT_011c51a0;
  _DAT_011c5190 = &PTR__money_put_011b6fb0;
  LOCK();
  _DAT_011c5198 = 2;
  UNLOCK();
  lVar9 = *(long *)(param_1 + 8);
  lVar7 = std::locale::id::_M_id
                    ((id *)&std::
                            money_put<wchar_t,std::ostreambuf_iterator<wchar_t,std::char_traits<wchar_t>>>
                            ::id);
  *(undefined **)(lVar9 + lVar7 * 8) = &DAT_011c5190;
  _DAT_011c5180 = &PTR__time_get_011b7030;
  LOCK();
  _DAT_011c5188 = 2;
  UNLOCK();
  lVar9 = *(long *)(param_1 + 8);
  lVar7 = std::locale::id::_M_id
                    ((id *)&std::
                            time_get<wchar_t,std::istreambuf_iterator<wchar_t,std::char_traits<wchar_t>>>
                            ::id);
  *(undefined **)(lVar9 + lVar7 * 8) = &DAT_011c5180;
  std::messages<wchar_t>::messages((messages<wchar_t> *)&DAT_011c5160,1);
  LOCK();
  _DAT_011c5168 = _DAT_011c5168 + 1;
  UNLOCK();
  lVar9 = *(long *)(param_1 + 8);
  lVar7 = std::locale::id::_M_id((id *)&std::messages<wchar_t>::id);
  *(undefined **)(lVar9 + lVar7 * 8) = &DAT_011c5160;
  lVar9 = *(long *)(param_1 + 0x18);
  lVar7 = std::locale::id::_M_id((id *)&std::numpunct<char>::id);
  *(undefined8 *)(lVar9 + lVar7 * 8) = uVar1;
  lVar9 = *(long *)(param_1 + 0x18);
  lVar7 = std::locale::id::_M_id((id *)&std::moneypunct<char,false>::id);
  *(undefined8 *)(lVar9 + lVar7 * 8) = uVar2;
  lVar9 = *(long *)(param_1 + 0x18);
  lVar7 = std::locale::id::_M_id((id *)&std::moneypunct<char,true>::id);
  *(undefined8 *)(lVar9 + lVar7 * 8) = uVar3;
  lVar9 = *(long *)(param_1 + 0x18);
  lVar7 = std::locale::id::_M_id((id *)&std::numpunct<wchar_t>::id);
  *(undefined8 *)(lVar9 + lVar7 * 8) = uVar5;
  lVar9 = *(long *)(param_1 + 0x18);
  lVar8 = std::locale::id::_M_id((id *)&std::moneypunct<wchar_t,false>::id);
  lVar7 = *(long *)(param_1 + 0x18);
  *(undefined8 *)(lVar9 + lVar8 * 8) = uVar4;
  lVar9 = std::locale::id::_M_id((id *)&std::moneypunct<wchar_t,true>::id);
  *(undefined8 *)(lVar7 + lVar9 * 8) = uVar6;
  return;
}


// ==== entry=00c25440 name=FUN_00c25440 size=1670 ====

/* WARNING: Removing unreachable block (ram,0x00c25a30) */
/* WARNING: Removing unreachable block (ram,0x00c25a50) */
/* WARNING: Removing unreachable block (ram,0x00c25a70) */
/* WARNING: Removing unreachable block (ram,0x00c25a90) */
/* WARNING: Removing unreachable block (ram,0x00c25ab0) */
/* WARNING: Removing unreachable block (ram,0x00c25ad0) */
/* WARNING: Removing unreachable block (ram,0x00c25af0) */
/* WARNING: Removing unreachable block (ram,0x00c25a18) */
/* WARNING: Removing unreachable block (ram,0x00c25b00) */
/* WARNING: Removing unreachable block (ram,0x00c25ae0) */
/* WARNING: Removing unreachable block (ram,0x00c25ac0) */
/* WARNING: Removing unreachable block (ram,0x00c25aa0) */
/* WARNING: Removing unreachable block (ram,0x00c25a80) */
/* WARNING: Removing unreachable block (ram,0x00c25a60) */
/* WARNING: Removing unreachable block (ram,0x00c25a40) */
/* WARNING: Removing unreachable block (ram,0x00c25a28) */

void FUN_00c25440(long param_1,undefined8 *param_2,undefined8 *param_3,char *param_4)

{
  long lVar1;
  char *pcVar2;
  numpunct<char> *this;
  long lVar3;
  undefined8 *puVar4;
  undefined8 uVar5;
  __locale_struct *p_Var6;
  messages<char> *this_00;
  numpunct<wchar_t> *this_01;
  messages<wchar_t> *this_02;
  long in_FS_OFFSET;
  __locale_struct *local_48;
  long local_40;
  
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  this = operator_new(0x18);
  p_Var6 = (__locale_struct *)*param_2;
  *(undefined4 *)(this + 8) = 0;
  *(undefined8 *)(this + 0x10) = 0;
  *(undefined ***)this = &PTR__numpunct_011b5510;
                    /* try { // try from 00c254a1 to 00c254a5 has its CatchHandler @ 00c25b17 */
  std::numpunct<char>::_M_initialize_numpunct(this,p_Var6);
  LOCK();
  *(int *)(this + 8) = *(int *)(this + 8) + 1;
  UNLOCK();
  lVar1 = *(long *)(param_1 + 8);
  lVar3 = std::locale::id::_M_id((id *)&std::numpunct<char>::id);
  *(numpunct<char> **)(lVar1 + lVar3 * 8) = this;
  puVar4 = operator_new(0x18);
  local_48 = (__locale_struct *)*param_2;
  *(undefined4 *)(puVar4 + 1) = 0;
  *puVar4 = &PTR__collate_011b54a0;
  uVar5 = std::locale::facet::_S_clone_c_locale(&local_48);
  puVar4[2] = uVar5;
  LOCK();
  *(int *)(puVar4 + 1) = *(int *)(puVar4 + 1) + 1;
  UNLOCK();
  lVar1 = *(long *)(param_1 + 8);
  lVar3 = std::locale::id::_M_id((id *)&std::collate<char>::id);
  *(undefined8 **)(lVar1 + lVar3 * 8) = puVar4;
  p_Var6 = operator_new(0x18);
  pcVar2 = (char *)*param_2;
  *(undefined4 *)(p_Var6->__locales + 1) = 0;
  p_Var6->__locales[2] = (__locale_data *)0x0;
  p_Var6->__locales[0] = (__locale_data *)&PTR__moneypunct_011b5720;
                    /* try { // try from 00c2557b to 00c2557f has its CatchHandler @ 00c25b0f */
  std::moneypunct<char,false>::_M_initialize_moneypunct(p_Var6,pcVar2);
  LOCK();
  *(int *)(p_Var6->__locales + 1) = *(int *)(p_Var6->__locales + 1) + 1;
  UNLOCK();
  lVar1 = *(long *)(param_1 + 8);
  lVar3 = std::locale::id::_M_id((id *)&std::moneypunct<char,false>::id);
  *(__locale_struct **)(lVar1 + lVar3 * 8) = p_Var6;
  p_Var6 = operator_new(0x18);
  pcVar2 = (char *)*param_2;
  *(undefined4 *)(p_Var6->__locales + 1) = 0;
  p_Var6->__locales[2] = (__locale_data *)0x0;
  p_Var6->__locales[0] = (__locale_data *)&PTR__moneypunct_011b56b8;
                    /* try { // try from 00c255e1 to 00c255e5 has its CatchHandler @ 00c25b47 */
  std::moneypunct<char,true>::_M_initialize_moneypunct(p_Var6,pcVar2);
  LOCK();
  *(int *)(p_Var6->__locales + 1) = *(int *)(p_Var6->__locales + 1) + 1;
  UNLOCK();
  lVar1 = *(long *)(param_1 + 8);
  lVar3 = std::locale::id::_M_id((id *)&std::moneypunct<char,true>::id);
  *(__locale_struct **)(lVar1 + lVar3 * 8) = p_Var6;
  puVar4 = operator_new(0x10);
  *(undefined4 *)(puVar4 + 1) = 0;
  *puVar4 = &PTR__money_get_011b5940;
  LOCK();
  *(int *)(puVar4 + 1) = *(int *)(puVar4 + 1) + 1;
  UNLOCK();
  lVar1 = *(long *)(param_1 + 8);
  lVar3 = std::locale::id::_M_id
                    ((id *)&std::
                            money_get<char,std::istreambuf_iterator<char,std::char_traits<char>>>::
                            id);
  *(undefined8 **)(lVar1 + lVar3 * 8) = puVar4;
  puVar4 = operator_new(0x10);
  *(undefined4 *)(puVar4 + 1) = 0;
  *puVar4 = &PTR__money_put_011b5970;
  LOCK();
  *(int *)(puVar4 + 1) = *(int *)(puVar4 + 1) + 1;
  UNLOCK();
  lVar1 = *(long *)(param_1 + 8);
  lVar3 = std::locale::id::_M_id
                    ((id *)&std::
                            money_put<char,std::ostreambuf_iterator<char,std::char_traits<char>>>::
                            id);
  *(undefined8 **)(lVar1 + lVar3 * 8) = puVar4;
  puVar4 = operator_new(0x10);
  *(undefined4 *)(puVar4 + 1) = 0;
  *puVar4 = &PTR__time_get_011b59f0;
  LOCK();
  *(int *)(puVar4 + 1) = *(int *)(puVar4 + 1) + 1;
  UNLOCK();
  lVar1 = *(long *)(param_1 + 8);
  lVar3 = std::locale::id::_M_id
                    ((id *)&std::
                            time_get<char,std::istreambuf_iterator<char,std::char_traits<char>>>::id
                    );
  *(undefined8 **)(lVar1 + lVar3 * 8) = puVar4;
  this_00 = operator_new(0x20);
                    /* try { // try from 00c2571e to 00c25722 has its CatchHandler @ 00c25b3f */
  std::messages<char>::messages(this_00,(__locale_struct *)*param_2,param_4,0);
  LOCK();
  *(int *)(this_00 + 8) = *(int *)(this_00 + 8) + 1;
  UNLOCK();
  lVar1 = *(long *)(param_1 + 8);
  lVar3 = std::locale::id::_M_id((id *)&std::messages<char>::id);
  *(messages<char> **)(lVar1 + lVar3 * 8) = this_00;
  this_01 = operator_new(0x18);
  p_Var6 = (__locale_struct *)*param_2;
  *(undefined4 *)(this_01 + 8) = 0;
  *(undefined8 *)(this_01 + 0x10) = 0;
  *(undefined ***)this_01 = &PTR__numpunct_011b6b50;
                    /* try { // try from 00c25782 to 00c25786 has its CatchHandler @ 00c25b37 */
  std::numpunct<wchar_t>::_M_initialize_numpunct(this_01,p_Var6);
  LOCK();
  *(int *)(this_01 + 8) = *(int *)(this_01 + 8) + 1;
  UNLOCK();
  lVar1 = *(long *)(param_1 + 8);
  lVar3 = std::locale::id::_M_id((id *)&std::numpunct<wchar_t>::id);
  *(numpunct<wchar_t> **)(lVar1 + lVar3 * 8) = this_01;
  puVar4 = operator_new(0x18);
  local_48 = (__locale_struct *)*param_2;
  *(undefined4 *)(puVar4 + 1) = 0;
  *puVar4 = &PTR__collate_011b6a60;
  uVar5 = std::locale::facet::_S_clone_c_locale(&local_48);
  puVar4[2] = uVar5;
  LOCK();
  *(int *)(puVar4 + 1) = *(int *)(puVar4 + 1) + 1;
  UNLOCK();
  lVar1 = *(long *)(param_1 + 8);
  lVar3 = std::locale::id::_M_id((id *)&std::collate<wchar_t>::id);
  *(undefined8 **)(lVar1 + lVar3 * 8) = puVar4;
  p_Var6 = operator_new(0x18);
  pcVar2 = (char *)*param_3;
  *(undefined4 *)(p_Var6->__locales + 1) = 0;
  p_Var6->__locales[2] = (__locale_data *)0x0;
  p_Var6->__locales[0] = (__locale_data *)&PTR__moneypunct_011b6d60;
                    /* try { // try from 00c25850 to 00c25854 has its CatchHandler @ 00c25b2f */
  std::moneypunct<wchar_t,false>::_M_initialize_moneypunct(p_Var6,pcVar2);
  LOCK();
  *(int *)(p_Var6->__locales + 1) = *(int *)(p_Var6->__locales + 1) + 1;
  UNLOCK();
  lVar1 = *(long *)(param_1 + 8);
  lVar3 = std::locale::id::_M_id((id *)&std::moneypunct<wchar_t,false>::id);
  *(__locale_struct **)(lVar1 + lVar3 * 8) = p_Var6;
  p_Var6 = operator_new(0x18);
  pcVar2 = (char *)*param_3;
  *(undefined4 *)(p_Var6->__locales + 1) = 0;
  p_Var6->__locales[2] = (__locale_data *)0x0;
  p_Var6->__locales[0] = (__locale_data *)&PTR__moneypunct_011b6cf8;
                    /* try { // try from 00c258b6 to 00c258ba has its CatchHandler @ 00c25b27 */
  std::moneypunct<wchar_t,true>::_M_initialize_moneypunct(p_Var6,pcVar2);
  LOCK();
  *(int *)(p_Var6->__locales + 1) = *(int *)(p_Var6->__locales + 1) + 1;
  UNLOCK();
  lVar1 = *(long *)(param_1 + 8);
  lVar3 = std::locale::id::_M_id((id *)&std::moneypunct<wchar_t,true>::id);
  *(__locale_struct **)(lVar1 + lVar3 * 8) = p_Var6;
  puVar4 = operator_new(0x10);
  *(undefined4 *)(puVar4 + 1) = 0;
  *puVar4 = &PTR__money_get_011b6f80;
  LOCK();
  *(int *)(puVar4 + 1) = *(int *)(puVar4 + 1) + 1;
  UNLOCK();
  lVar1 = *(long *)(param_1 + 8);
  lVar3 = std::locale::id::_M_id
                    ((id *)&std::
                            money_get<wchar_t,std::istreambuf_iterator<wchar_t,std::char_traits<wchar_t>>>
                            ::id);
  *(undefined8 **)(lVar1 + lVar3 * 8) = puVar4;
  puVar4 = operator_new(0x10);
  *(undefined4 *)(puVar4 + 1) = 0;
  *puVar4 = &PTR__money_put_011b6fb0;
  LOCK();
  *(int *)(puVar4 + 1) = *(int *)(puVar4 + 1) + 1;
  UNLOCK();
  lVar1 = *(long *)(param_1 + 8);
  lVar3 = std::locale::id::_M_id
                    ((id *)&std::
                            money_put<wchar_t,std::ostreambuf_iterator<wchar_t,std::char_traits<wchar_t>>>
                            ::id);
  *(undefined8 **)(lVar1 + lVar3 * 8) = puVar4;
  puVar4 = operator_new(0x10);
  *(undefined4 *)(puVar4 + 1) = 0;
  *puVar4 = &PTR__time_get_011b7030;
  LOCK();
  *(int *)(puVar4 + 1) = *(int *)(puVar4 + 1) + 1;
  UNLOCK();
  lVar1 = *(long *)(param_1 + 8);
  lVar3 = std::locale::id::_M_id
                    ((id *)&std::
                            time_get<wchar_t,std::istreambuf_iterator<wchar_t,std::char_traits<wchar_t>>>
                            ::id);
  *(undefined8 **)(lVar1 + lVar3 * 8) = puVar4;
  this_02 = operator_new(0x20);
                    /* try { // try from 00c259cb to 00c259cf has its CatchHandler @ 00c25b1f */
  std::messages<wchar_t>::messages(this_02,(__locale_struct *)*param_2,param_4,0);
  LOCK();
  *(int *)(this_02 + 8) = *(int *)(this_02 + 8) + 1;
  UNLOCK();
  lVar1 = *(long *)(param_1 + 8);
  lVar3 = std::locale::id::_M_id((id *)&std::messages<wchar_t>::id);
  *(messages<wchar_t> **)(lVar1 + lVar3 * 8) = this_02;
  if (local_40 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


// ==== entry=00c25b50 orig=FUN_00c25b50 size=670 name=name ====

/* std::locale::name() const */

void std::locale::name(void)

{
  long lVar1;
  undefined8 *puVar2;
  char *pcVar3;
  char *__s2;
  long lVar4;
  undefined1 *puVar5;
  long lVar6;
  int iVar7;
  size_t sVar8;
  ulong uVar9;
  long lVar10;
  long *in_RSI;
  string *in_RDI;
  char *__s1;
  long in_FS_OFFSET;
  
  lVar1 = *(long *)(in_FS_OFFSET + 0x28);
  *(undefined1 **)in_RDI = &DAT_011c5338;
  puVar2 = *(undefined8 **)(*in_RSI + 0x20);
  pcVar3 = (char *)*puVar2;
  if (pcVar3 == (char *)0x0) {
    string::_M_replace_aux(in_RDI,0,string::_Rep::_S_empty_rep_storage,1,'*');
  }
  else {
    if (puVar2[1] != 0) {
      uVar9 = 0;
      __s1 = pcVar3;
      do {
        uVar9 = uVar9 + 1;
        __s2 = (char *)puVar2[uVar9];
        iVar7 = strcmp(__s1,__s2);
        __s1 = __s2;
      } while (uVar9 < 0xb && iVar7 == 0);
      if (iVar7 != 0) {
                    /* try { // try from 00c25be5 to 00c25de5 has its CatchHandler @ 00c25e03 */
        string::reserve(in_RDI,0x80);
        sVar8 = strlen("LC_CTYPE");
        string::s_basic_string__append_5fd166(in_RDI,"LC_CTYPE",sVar8);
        lVar10 = *(long *)in_RDI;
        lVar4 = *(long *)(lVar10 + -0x18);
        uVar9 = lVar4 + 1;
        if ((*(ulong *)(lVar10 + -0x10) < uVar9) || (0 < *(int *)(lVar10 + -8))) {
          string::reserve(in_RDI,uVar9);
        }
        *(undefined1 *)(*(long *)in_RDI + *(long *)(*(long *)in_RDI + -0x18)) = 0x3d;
        puVar5 = *(undefined1 **)in_RDI;
        if (puVar5 != &DAT_011c5338) {
          *(undefined4 *)(puVar5 + -8) = 0;
          *(ulong *)(puVar5 + -0x18) = uVar9;
          puVar5[lVar4 + 1] = 0;
        }
        pcVar3 = (char *)**(undefined8 **)(*in_RSI + 0x20);
        sVar8 = strlen(pcVar3);
        string::s_basic_string__append_5fd166(in_RDI,pcVar3,sVar8);
        lVar10 = 8;
        do {
          lVar4 = *(long *)in_RDI;
          lVar6 = *(long *)(lVar4 + -0x18);
          uVar9 = lVar6 + 1;
          if ((*(ulong *)(lVar4 + -0x10) < uVar9) || (0 < *(int *)(lVar4 + -8))) {
            string::reserve(in_RDI,uVar9);
          }
          *(undefined1 *)(*(long *)in_RDI + *(long *)(*(long *)in_RDI + -0x18)) = 0x3b;
          puVar5 = *(undefined1 **)in_RDI;
          if (puVar5 != &DAT_011c5338) {
            *(undefined4 *)(puVar5 + -8) = 0;
            *(ulong *)(puVar5 + -0x18) = uVar9;
            puVar5[lVar6 + 1] = 0;
          }
          pcVar3 = *(char **)((long)&PTR_s_LC_CTYPE_01183000 + lVar10);
          sVar8 = strlen(pcVar3);
          string::s_basic_string__append_5fd166(in_RDI,pcVar3,sVar8);
          lVar4 = *(long *)in_RDI;
          lVar6 = *(long *)(lVar4 + -0x18);
          uVar9 = lVar6 + 1;
          if ((*(ulong *)(lVar4 + -0x10) < uVar9) || (0 < *(int *)(lVar4 + -8))) {
            string::reserve(in_RDI,uVar9);
          }
          *(undefined1 *)(*(long *)in_RDI + *(long *)(*(long *)in_RDI + -0x18)) = 0x3d;
          puVar5 = *(undefined1 **)in_RDI;
          if (puVar5 != &DAT_011c5338) {
            *(undefined4 *)(puVar5 + -8) = 0;
            *(ulong *)(puVar5 + -0x18) = uVar9;
            puVar5[lVar6 + 1] = 0;
          }
          pcVar3 = *(char **)(*(long *)(*in_RSI + 0x20) + lVar10);
          sVar8 = strlen(pcVar3);
          string::s_basic_string__append_5fd166(in_RDI,pcVar3,sVar8);
          lVar10 = lVar10 + 8;
        } while (lVar10 != 0x60);
        goto LAB_00c25d8b;
      }
    }
    sVar8 = strlen(pcVar3);
    string::s_basic_string__assign_65a9ea(in_RDI,pcVar3,sVar8);
  }
LAB_00c25d8b:
  if (lVar1 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


// ==== entry=00c25e10 name=FUN_00c25e10 size=8 ====

char * FUN_00c25e10(void)

{
  return "generic";
}


// ==== entry=00c25e20 name=FUN_00c25e20 size=8 ====

char * FUN_00c25e20(void)

{
  return "system";
}


// ==== entry=00c25e30 orig=FUN_00c25e30 size=6 name=default_error_condition ====

/* std::_V2::error_category::default_error_condition(int) const */

int __thiscall std::_V2::error_category::default_error_condition(error_category *this,int param_1)

{
  return param_1;
}


// ==== entry=00c25e40 orig=FUN_00c25e40 size=31 name=equivalent ====

/* std::_V2::error_category::equivalent(int, std::error_condition const&) const */

bool __thiscall
std::_V2::error_category::equivalent(error_category *this,int param_1,error_condition *param_2)

{
  int iVar1;
  long extraout_RDX;
  
  iVar1 = (**(code **)(*(long *)this + 0x28))();
  if (*(long *)(param_2 + 8) != extraout_RDX) {
    return false;
  }
  return *(int *)param_2 == iVar1;
}


// ==== entry=00c25e70 orig=FUN_00c25e70 size=15 name=equivalent ====

/* std::_V2::error_category::equivalent(std::error_code const&, int) const */

bool __thiscall
std::_V2::error_category::equivalent(error_category *this,error_code *param_1,int param_2)

{
  if (this != *(error_category **)(param_1 + 8)) {
    return false;
  }
  return *(int *)param_1 == param_2;
}


// ==== entry=00c25e90 orig=FUN_00c25e90 size=19 name=~system_error ====

/* std::system_error::~system_error() */

void __thiscall std::system_error::~system_error(system_error *this)

{
  *(undefined ***)this = &PTR__system_error_011b5108;
  runtime_error::~runtime_error((runtime_error *)this);
  return;
}


// ==== entry=00c25eb0 orig=FUN_00c25eb0 size=18 name=~system_error ====

/* std::system_error::~system_error() */

void __thiscall std::system_error::~system_error(system_error *this)

{
  ~system_error(this);
  operator_delete(this);
  return;
}


// ==== entry=00c25ed0 orig=FUN_00c25ed0 size=103 name=_M_message[abi:cxx11] ====

/* std::_V2::error_category::_M_message[abi:cxx11](int) const */

error_category * __thiscall
std::_V2::error_category::_M_message_abi_cxx11_(error_category *this,int param_1)

{
  undefined4 in_register_00000034;
  long in_FS_OFFSET;
  undefined1 *local_48;
  undefined8 local_40;
  undefined1 auStack_38 [24];
  long local_20;
  
  local_20 = *(long *)(in_FS_OFFSET + 0x28);
  (**(code **)(*(long *)CONCAT44(in_register_00000034,param_1) + 0x20))(&local_48);
                    /* try { // try from 00c25f01 to 00c25f05 has its CatchHandler @ 00c25f37 */
  FUN_00c27650(this,local_48,local_40);
  if (local_48 != auStack_38) {
    operator_delete(local_48);
  }
  if (local_20 == *(long *)(in_FS_OFFSET + 0x28)) {
    return this;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ==== entry=00c25f40 name=FUN_00c25f40 size=72 ====

long * FUN_00c25f40(long *param_1,undefined8 param_2,int param_3)

{
  char *__s;
  size_t sVar1;
  char *pcVar2;
  
  __s = strerror(param_3);
  pcVar2 = (char *)0xffffffffffffffff;
  *param_1 = (long)(param_1 + 2);
  if (__s != (char *)0x0) {
    sVar1 = strlen(__s);
    pcVar2 = __s + sVar1;
  }
  std::__cxx11::string::_M_construct<char_const*>(param_1,__s,pcVar2);
  return param_1;
}


// ==== entry=00c25f90 orig=FUN_00c25f90 size=1 name=~error_category ====

/* std::_V2::error_category::~error_category() */

void __thiscall std::_V2::error_category::~error_category(error_category *this)

{
  return;
}


// ==== entry=00c25fa0 name=FUN_00c25fa0 size=15 ====

void FUN_00c25fa0(error_category *param_1)

{
  *(undefined ***)param_1 = &PTR_FUN_011b5068;
  std::_V2::error_category::~error_category(param_1);
  return;
}


// ==== entry=00c25fb0 name=FUN_00c25fb0 size=28 ====

void FUN_00c25fb0(error_category *param_1)

{
  *(undefined ***)param_1 = &PTR_FUN_011b5068;
  std::_V2::error_category::~error_category(param_1);
  operator_delete(param_1);
  return;
}


// ==== entry=00c25fd0 name=FUN_00c25fd0 size=15 ====

void FUN_00c25fd0(error_category *param_1)

{
  *(undefined ***)param_1 = &PTR_FUN_011b5018;
  std::_V2::error_category::~error_category(param_1);
  return;
}


// ==== entry=00c25fe0 name=FUN_00c25fe0 size=28 ====

void FUN_00c25fe0(error_category *param_1)

{
  *(undefined ***)param_1 = &PTR_FUN_011b5018;
  std::_V2::error_category::~error_category(param_1);
  operator_delete(param_1);
  return;
}


// ==== entry=00c26000 orig=FUN_00c26000 size=18 name=~error_category ====

/* std::_V2::error_category::~error_category() */

void __thiscall std::_V2::error_category::~error_category(error_category *this)

{
  ~error_category(this);
  operator_delete(this);
  return;
}


// ==== entry=00c26020 orig=FUN_00c26020 size=8 name=system_category ====

/* std::_V2::system_category() */

undefined ** std::_V2::system_category(void)

{
  return &PTR_PTR_011c0a90;
}


// ==== entry=00c26030 orig=FUN_00c26030 size=8 name=generic_category ====

/* std::_V2::generic_category() */

undefined ** std::_V2::generic_category(void)

{
  return &PTR_PTR_011c0a98;
}


// ==== entry=00c26040 name=FUN_00c26040 size=51 ====

undefined4 FUN_00c26040(undefined8 param_1,undefined4 param_2)

{
  switch(param_2) {
  default:
    std::_V2::system_category();
    return param_2;
  case 1:
  case 2:
  case 3:
  case 4:
  case 5:
  case 6:
  case 7:
  case 8:
  case 9:
  case 10:
  case 0xb:
  case 0xc:
  case 0xd:
  case 0xe:
  case 0x10:
  case 0x11:
  case 0x12:
  case 0x13:
  case 0x14:
  case 0x15:
  case 0x16:
  case 0x17:
  case 0x18:
  case 0x19:
  case 0x1a:
  case 0x1b:
  case 0x1c:
  case 0x1d:
  case 0x1e:
  case 0x1f:
  case 0x20:
  case 0x21:
  case 0x22:
  case 0x23:
  case 0x24:
  case 0x25:
  case 0x26:
  case 0x27:
  case 0x28:
  case 0x2a:
  case 0x2b:
  case 0x3c:
  case 0x3d:
  case 0x3e:
  case 0x3f:
  case 0x43:
  case 0x47:
  case 0x4a:
  case 0x4b:
  case 0x54:
  case 0x58:
  case 0x59:
  case 0x5a:
  case 0x5b:
  case 0x5c:
  case 0x5d:
  case 0x5f:
  case 0x61:
  case 0x62:
  case 99:
  case 100:
  case 0x65:
  case 0x66:
  case 0x67:
  case 0x68:
  case 0x69:
  case 0x6a:
  case 0x6b:
  case 0x6e:
  case 0x6f:
  case 0x71:
  case 0x72:
  case 0x73:
  case 0x7d:
  case 0x82:
  case 0x83:
    std::_V2::generic_category();
    return param_2;
  }
}


// ==== entry=00c26080 orig=FUN_00c26080 size=106 name=__throw_system_error ====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* std::__throw_system_error(int) */

void std::__throw_system_error(int param_1)

{
  undefined8 *puVar1;
  long *plVar2;
  long in_FS_OFFSET;
  undefined1 *local_58 [2];
  undefined1 auStack_48 [24];
  undefined8 local_30;
  
  local_30 = *(undefined8 *)(in_FS_OFFSET + 0x28);
  puVar1 = (undefined8 *)__cxa_allocate_exception(0x20);
  plVar2 = (long *)_V2::generic_category();
                    /* try { // try from 00c260c1 to 00c260c3 has its CatchHandler @ 00c260ea */
  (**(code **)(*plVar2 + 0x20))(local_58,plVar2,param_1);
                    /* try { // try from 00c260ca to 00c260ce has its CatchHandler @ 00c260f2 */
  FUN_00c716a0(puVar1,local_58);
  if (local_58[0] != auStack_48) {
    operator_delete(local_58[0]);
    FUN_0051da24();
    return;
  }
  *(int *)(puVar1 + 2) = param_1;
  puVar1[3] = plVar2;
  *puVar1 = &PTR__system_error_011b5108;
                    /* WARNING: Subroutine does not return */
  __cxa_throw(puVar1,&system_error::typeinfo,system_error::~system_error);
}


// ==== entry=00c26100 orig=FUN_00c26100 size=18 name=default_error_condition ====

/* std::error_code::default_error_condition() const */

void __thiscall std::error_code::default_error_condition(error_code *this)

{
  code *UNRECOVERED_JUMPTABLE;
  
  UNRECOVERED_JUMPTABLE = *(code **)(**(long **)(this + 8) + 0x28);
                    /* WARNING: Could not recover jumptable at 0x00c26110. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)(*(long **)(this + 8),*(undefined4 *)this,UNRECOVERED_JUMPTABLE);
  return;
}


// ==== entry=00c26120 orig=FUN_00c26120 size=8 name=open ====

/* std::filebuf::open(std::string const&, std::_Ios_Openmode) */

void std::filebuf::open(filebuf *param_1,undefined8 *param_2)

{
  open(param_1,*param_2);
  return;
}


// ==== entry=00c26130 orig=FUN_00c26130 size=178 name=ifstream ====

/* std::ifstream::ifstream(std::string const&, std::_Ios_Openmode) */

void __thiscall
std::ifstream::ifstream(ifstream *this,long *param_1,undefined8 *param_3,uint param_4)

{
  filebuf *this_00;
  long lVar1;
  ios *piVar2;
  
  lVar1 = param_1[1];
  this_00 = (filebuf *)(this + 0x10);
  *(long *)this = lVar1;
  *(long *)(this + *(long *)(lVar1 + -0x18)) = param_1[2];
  *(undefined8 *)(this + 8) = 0;
  ios::init((ios *)(this + *(long *)(lVar1 + -0x18)),(streambuf *)0x0);
  lVar1 = *param_1;
  *(long *)this = lVar1;
  *(long *)(this + *(long *)(lVar1 + -0x18)) = param_1[3];
                    /* try { // try from 00c26187 to 00c2618b has its CatchHandler @ 00c261e9 */
  filebuf::filebuf(this_00);
                    /* try { // try from 00c26199 to 00c261da has its CatchHandler @ 00c261e4 */
  ios::init((ios *)(this + *(long *)(*(long *)this + -0x18)),(streambuf *)this_00);
  lVar1 = filebuf::open(this_00,*param_3,param_4 | 8);
  piVar2 = (ios *)(this + *(long *)(*(long *)this + -0x18));
  if (lVar1 != 0) {
    ios::s_basic_ios__clear_c1bf70(piVar2,0);
    return;
  }
  ios::s_basic_ios__clear_c1bf70(piVar2,*(uint *)(piVar2 + 0x20) | 4);
  return;
}


// ==== entry=00c26220 orig=FUN_00c26220 size=298 name=ifstream ====

/* std::ifstream::ifstream(std::string const&, std::_Ios_Openmode) */

void __thiscall std::ifstream::ifstream(ifstream *this,undefined8 *param_1,uint param_3)

{
  filebuf *this_00;
  long lVar1;
  ios *piVar2;
  
  ios_base::ios_base((ios_base *)(this + 0x100));
  *(undefined8 *)(this + 0x1d8) = 0;
  *(undefined8 *)(this + 0x1e8) = 0;
  *(undefined8 *)(this + 0x1f0) = 0;
  *(undefined ***)(this + 0x100) = &PTR__ios_011b4e70;
  *(undefined2 *)(this + 0x1e0) = 0;
  *(undefined8 *)(this + 0x1f8) = 0;
  *(undefined8 *)(this + 0x200) = 0;
  *(undefined **)this = &DAT_011b6000;
  *(undefined **)(this + 0x100) = &DAT_011b6028;
  *(undefined8 *)(this + 8) = 0;
                    /* try { // try from 00c262c4 to 00c262c8 has its CatchHandler @ 00c26351 */
  ios::init((ios *)(this + 0x100),(streambuf *)0x0);
  this_00 = (filebuf *)(this + 0x10);
  *(undefined ***)this = &PTR__ifstream_011b6070;
  *(undefined ***)(this + 0x100) = &PTR__ifstream_011b6098;
                    /* try { // try from 00c262e9 to 00c262ed has its CatchHandler @ 00c2634f */
  filebuf::filebuf(this_00);
                    /* try { // try from 00c262f4 to 00c2633a has its CatchHandler @ 00c2634a */
  ios::init((ios *)(this + 0x100),(streambuf *)this_00);
  lVar1 = filebuf::open(this_00,*param_1,param_3 | 8);
  piVar2 = (ios *)(this + *(long *)(*(long *)this + -0x18));
  if (lVar1 != 0) {
    ios::s_basic_ios__clear_c1bf70(piVar2,0);
    return;
  }
  ios::s_basic_ios__clear_c1bf70(piVar2,*(uint *)(piVar2 + 0x20) | 4);
  return;
}


// ==== entry=00c263a0 orig=FUN_00c263a0 size=61 name=open ====

/* std::ifstream::open(std::string const&, std::_Ios_Openmode) */

void __thiscall std::ifstream::open(ifstream *this,undefined8 *param_1,uint param_3)

{
  long lVar1;
  
  lVar1 = filebuf::open((filebuf *)(this + 0x10),*param_1,param_3 | 8);
  if (lVar1 != 0) {
    ios::s_basic_ios__clear_c1bf70((ios *)(this + *(long *)(*(long *)this + -0x18)),0);
    return;
  }
  ios::s_basic_ios__clear_c1bf70
            ((ios *)(this + *(long *)(*(long *)this + -0x18)),
             *(uint *)((ios *)(this + *(long *)(*(long *)this + -0x18)) + 0x20) | 4);
  return;
}


// ==== entry=00c263f0 orig=FUN_00c263f0 size=165 name=ofstream ====

/* std::ofstream::ofstream(std::string const&, std::_Ios_Openmode) */

void __thiscall
std::ofstream::ofstream(ofstream *this,long *param_1,undefined8 *param_3,uint param_4)

{
  filebuf *this_00;
  long lVar1;
  ios *piVar2;
  
  lVar1 = param_1[1];
  this_00 = (filebuf *)(this + 8);
  *(long *)this = lVar1;
  lVar1 = *(long *)(lVar1 + -0x18);
  *(long *)(this + lVar1) = param_1[2];
  ios::init((ios *)(this + lVar1),(streambuf *)0x0);
  lVar1 = *param_1;
  *(long *)this = lVar1;
  *(long *)(this + *(long *)(lVar1 + -0x18)) = param_1[3];
                    /* try { // try from 00c2643a to 00c2643e has its CatchHandler @ 00c264a1 */
  filebuf::filebuf(this_00);
                    /* try { // try from 00c2644c to 00c26492 has its CatchHandler @ 00c2649c */
  ios::init((ios *)(this + *(long *)(*(long *)this + -0x18)),(streambuf *)this_00);
  lVar1 = filebuf::open(this_00,*param_3,param_4 | 0x10);
  piVar2 = (ios *)(this + *(long *)(*(long *)this + -0x18));
  if (lVar1 != 0) {
    ios::s_basic_ios__clear_c1bf70(piVar2,0);
    return;
  }
  ios::s_basic_ios__clear_c1bf70(piVar2,*(uint *)(piVar2 + 0x20) | 4);
  return;
}


// ==== entry=00c264d0 orig=FUN_00c264d0 size=286 name=ofstream ====

/* std::ofstream::ofstream(std::string const&, std::_Ios_Openmode) */

void __thiscall std::ofstream::ofstream(ofstream *this,undefined8 *param_1,uint param_3)

{
  filebuf *this_00;
  long lVar1;
  ios *piVar2;
  
  ios_base::ios_base((ios_base *)(this + 0xf8));
  *(undefined8 *)(this + 0x1d0) = 0;
  *(undefined8 *)(this + 0x1e0) = 0;
  *(undefined8 *)(this + 0x1e8) = 0;
  *(undefined ***)(this + 0xf8) = &PTR__ios_011b4e70;
  *(undefined2 *)(this + 0x1d8) = 0;
  *(undefined8 *)(this + 0x1f0) = 0;
  *(undefined8 *)(this + 0x1f8) = 0;
  *(undefined **)this = &DAT_011b60c0;
  *(undefined **)(this + 0xf8) = &DAT_011b60e8;
                    /* try { // try from 00c26568 to 00c2656c has its CatchHandler @ 00c265f9 */
  ios::init((ios *)(this + 0xf8),(streambuf *)0x0);
  this_00 = (filebuf *)(this + 8);
  *(undefined ***)this = &PTR__ofstream_011b6130;
  *(undefined ***)(this + 0xf8) = &PTR__ofstream_011b6158;
                    /* try { // try from 00c2658d to 00c26591 has its CatchHandler @ 00c265f7 */
  filebuf::filebuf(this_00);
                    /* try { // try from 00c26598 to 00c265e2 has its CatchHandler @ 00c265f2 */
  ios::init((ios *)(this + 0xf8),(streambuf *)this_00);
  lVar1 = filebuf::open(this_00,*param_1,param_3 | 0x10);
  piVar2 = (ios *)(this + *(long *)(*(long *)this + -0x18));
  if (lVar1 != 0) {
    ios::s_basic_ios__clear_c1bf70(piVar2,0);
    return;
  }
  ios::s_basic_ios__clear_c1bf70(piVar2,*(uint *)(piVar2 + 0x20) | 4);
  return;
}


// ==== entry=00c26640 orig=FUN_00c26640 size=61 name=open ====

/* std::ofstream::open(std::string const&, std::_Ios_Openmode) */

void __thiscall std::ofstream::open(ofstream *this,undefined8 *param_1,uint param_3)

{
  long lVar1;
  
  lVar1 = filebuf::open((filebuf *)(this + 8),*param_1,param_3 | 0x10);
  if (lVar1 != 0) {
    ios::s_basic_ios__clear_c1bf70((ios *)(this + *(long *)(*(long *)this + -0x18)),0);
    return;
  }
  ios::s_basic_ios__clear_c1bf70
            ((ios *)(this + *(long *)(*(long *)this + -0x18)),
             *(uint *)((ios *)(this + *(long *)(*(long *)this + -0x18)) + 0x20) | 4);
  return;
}


// ==== entry=00c26690 orig=FUN_00c26690 size=242 name=fstream ====

/* std::fstream::fstream(std::string const&, std::_Ios_Openmode) */

void __thiscall
std::fstream::fstream(fstream *this,long *param_1,undefined8 *param_3,undefined4 param_4)

{
  filebuf *this_00;
  long lVar1;
  ios *piVar2;
  
  lVar1 = param_1[2];
  *(long *)this = lVar1;
  *(long *)(this + *(long *)(lVar1 + -0x18)) = param_1[3];
  *(undefined8 *)(this + 8) = 0;
  ios::init((ios *)(this + *(long *)(lVar1 + -0x18)),(streambuf *)0x0);
  lVar1 = param_1[4];
  *(long *)(this + 0x10) = lVar1;
  lVar1 = *(long *)(lVar1 + -0x18);
  *(long *)(this + lVar1 + 0x10) = param_1[5];
                    /* try { // try from 00c266e7 to 00c266eb has its CatchHandler @ 00c2678b */
  ios::init((ios *)(this + lVar1 + 0x10),(streambuf *)0x0);
  lVar1 = param_1[1];
  this_00 = (filebuf *)(this + 0x18);
  *(long *)this = lVar1;
  *(long *)(this + *(long *)(lVar1 + -0x18)) = param_1[6];
  *(long *)(this + 0x10) = param_1[7];
  lVar1 = *param_1;
  *(long *)this = lVar1;
  *(long *)(this + *(long *)(lVar1 + -0x18)) = param_1[8];
  *(long *)(this + 0x10) = param_1[9];
                    /* try { // try from 00c26729 to 00c2672d has its CatchHandler @ 00c26789 */
  filebuf::filebuf(this_00);
                    /* try { // try from 00c2673b to 00c2677a has its CatchHandler @ 00c26784 */
  ios::init((ios *)(this + *(long *)(*(long *)this + -0x18)),(streambuf *)this_00);
  lVar1 = filebuf::open(this_00,*param_3,param_4);
  piVar2 = (ios *)(this + *(long *)(*(long *)this + -0x18));
  if (lVar1 != 0) {
    ios::s_basic_ios__clear_c1bf70(piVar2,0);
    return;
  }
  ios::s_basic_ios__clear_c1bf70(piVar2,*(uint *)(piVar2 + 0x20) | 4);
  return;
}


// ==== entry=00c267f0 orig=FUN_00c267f0 size=380 name=fstream ====

/* std::fstream::fstream(std::string const&, std::_Ios_Openmode) */

void __thiscall std::fstream::fstream(fstream *this,undefined8 *param_1,undefined4 param_3)

{
  filebuf *this_00;
  long lVar1;
  ios *piVar2;
  
  ios_base::ios_base((ios_base *)(this + 0x108));
  *(undefined8 *)(this + 0x1e0) = 0;
  *(undefined8 *)(this + 0x1f0) = 0;
  *(undefined ***)(this + 0x108) = &PTR__ios_011b4e70;
  *(undefined2 *)(this + 0x1e8) = 0;
  *(undefined8 *)(this + 0x1f8) = 0;
  *(undefined8 *)(this + 0x200) = 0;
  *(undefined8 *)(this + 0x208) = 0;
  *(undefined **)this = &DAT_011b61d0;
  *(undefined **)(this + 0x108) = &DAT_011b61f8;
  *(undefined8 *)(this + 8) = 0;
                    /* try { // try from 00c268a0 to 00c268a4 has its CatchHandler @ 00c269e7 */
  ios::init((ios *)(this + 0x108),(streambuf *)0x0);
  *(undefined **)(this + 0x10) = &DAT_011b6180;
  *(undefined **)(this + 0x108) = &DAT_011b61a8;
                    /* try { // try from 00c268c4 to 00c268c8 has its CatchHandler @ 00c269e5 */
  ios::init((ios *)(this + 0x108),(streambuf *)0x0);
  this_00 = (filebuf *)(this + 0x18);
  *(undefined **)(this + 0x108) = &DAT_011b6270;
  *(undefined ***)this = &PTR__fstream_011b62e8;
  *(undefined ***)(this + 0x108) = &PTR__fstream_011b6338;
  *(undefined ***)(this + 0x10) = &PTR__fstream_011b6310;
                    /* try { // try from 00c26909 to 00c2690d has its CatchHandler @ 00c26974 */
  filebuf::filebuf(this_00);
                    /* try { // try from 00c26914 to 00c26962 has its CatchHandler @ 00c26972 */
  ios::init((ios *)(this + 0x108),(streambuf *)this_00);
  lVar1 = filebuf::open(this_00,*param_1,param_3);
  piVar2 = (ios *)(this + *(long *)(*(long *)this + -0x18));
  if (lVar1 != 0) {
    ios::s_basic_ios__clear_c1bf70(piVar2,0);
    return;
  }
  ios::s_basic_ios__clear_c1bf70(piVar2,*(uint *)(piVar2 + 0x20) | 4);
  return;
}


// ==== entry=00c269f0 orig=FUN_00c269f0 size=58 name=open ====

/* std::fstream::open(std::string const&, std::_Ios_Openmode) */

void std::fstream::open(long *param_1,undefined8 *param_2)

{
  long lVar1;
  ios *piVar2;
  
  lVar1 = filebuf::open((filebuf *)(param_1 + 3),*param_2);
  if (lVar1 != 0) {
    ios::s_basic_ios__clear_c1bf70((ios *)((long)param_1 + *(long *)(*param_1 + -0x18)),0);
    return;
  }
  piVar2 = (ios *)((long)param_1 + *(long *)(*param_1 + -0x18));
  ios::s_basic_ios__clear_c1bf70(piVar2,*(uint *)(piVar2 + 0x20) | 4);
  return;
}


// ==== entry=00c26a40 orig=FUN_00c26a40 size=8 name=open ====

/* std::wfilebuf::open(std::string const&, std::_Ios_Openmode) */

void std::wfilebuf::open(wfilebuf *param_1,undefined8 *param_2)

{
  open(param_1,*param_2);
  return;
}


// ==== entry=00c26a50 orig=FUN_00c26a50 size=178 name=wifstream ====

/* std::wifstream::wifstream(std::string const&, std::_Ios_Openmode) */

void __thiscall
std::wifstream::wifstream(wifstream *this,long *param_1,undefined8 *param_3,uint param_4)

{
  wfilebuf *this_00;
  long lVar1;
  wios *pwVar2;
  
  lVar1 = param_1[1];
  this_00 = (wfilebuf *)(this + 0x10);
  *(long *)this = lVar1;
  *(long *)(this + *(long *)(lVar1 + -0x18)) = param_1[2];
  *(undefined8 *)(this + 8) = 0;
  wios::init((wios *)(this + *(long *)(lVar1 + -0x18)),(wstreambuf *)0x0);
  lVar1 = *param_1;
  *(long *)this = lVar1;
  *(long *)(this + *(long *)(lVar1 + -0x18)) = param_1[3];
                    /* try { // try from 00c26aa7 to 00c26aab has its CatchHandler @ 00c26b09 */
  wfilebuf::wfilebuf(this_00);
                    /* try { // try from 00c26ab9 to 00c26afa has its CatchHandler @ 00c26b04 */
  wios::init((wios *)(this + *(long *)(*(long *)this + -0x18)),(wstreambuf *)this_00);
  lVar1 = wfilebuf::open(this_00,*param_3,param_4 | 8);
  pwVar2 = (wios *)(this + *(long *)(*(long *)this + -0x18));
  if (lVar1 != 0) {
    wios::s_basic_ios__clear_c1c9b0(pwVar2,0);
    return;
  }
  wios::s_basic_ios__clear_c1c9b0(pwVar2,*(uint *)(pwVar2 + 0x20) | 4);
  return;
}


// ==== entry=00c26b40 orig=FUN_00c26b40 size=306 name=wifstream ====

/* std::wifstream::wifstream(std::string const&, std::_Ios_Openmode) */

void __thiscall std::wifstream::wifstream(wifstream *this,undefined8 *param_1,uint param_3)

{
  wfilebuf *this_00;
  long lVar1;
  wios *pwVar2;
  
  ios_base::ios_base((ios_base *)(this + 0x100));
  this[0x1e4] = (wifstream)0x0;
  *(undefined8 *)(this + 0x1d8) = 0;
  *(undefined4 *)(this + 0x1e0) = 0;
  *(undefined ***)(this + 0x100) = &PTR__wios_011b4e90;
  *(undefined8 *)(this + 0x1e8) = 0;
  *(undefined8 *)(this + 0x1f0) = 0;
  *(undefined8 *)(this + 0x1f8) = 0;
  *(undefined **)this = &DAT_011b63e0;
  *(undefined8 *)(this + 0x200) = 0;
  *(undefined **)(this + 0x100) = &DAT_011b6408;
  *(undefined8 *)(this + 8) = 0;
                    /* try { // try from 00c26bec to 00c26bf0 has its CatchHandler @ 00c26c81 */
  wios::init((wios *)(this + 0x100),(wstreambuf *)0x0);
  this_00 = (wfilebuf *)(this + 0x10);
  *(undefined ***)this = &PTR__wifstream_011b6450;
  *(undefined ***)(this + 0x100) = &PTR__wifstream_011b6478;
                    /* try { // try from 00c26c11 to 00c26c15 has its CatchHandler @ 00c26c7f */
  wfilebuf::wfilebuf(this_00);
                    /* try { // try from 00c26c1c to 00c26c6a has its CatchHandler @ 00c26c7a */
  wios::init((wios *)(this + 0x100),(wstreambuf *)this_00);
  lVar1 = wfilebuf::open(this_00,*param_1,param_3 | 8);
  pwVar2 = (wios *)(this + *(long *)(*(long *)this + -0x18));
  if (lVar1 != 0) {
    wios::s_basic_ios__clear_c1c9b0(pwVar2,0);
    return;
  }
  wios::s_basic_ios__clear_c1c9b0(pwVar2,*(uint *)(pwVar2 + 0x20) | 4);
  return;
}


// ==== entry=00c26cd0 orig=FUN_00c26cd0 size=61 name=open ====

/* std::wifstream::open(std::string const&, std::_Ios_Openmode) */

void __thiscall std::wifstream::open(wifstream *this,undefined8 *param_1,uint param_3)

{
  long lVar1;
  
  lVar1 = wfilebuf::open((wfilebuf *)(this + 0x10),*param_1,param_3 | 8);
  if (lVar1 != 0) {
    wios::s_basic_ios__clear_c1c9b0((wios *)(this + *(long *)(*(long *)this + -0x18)),0);
    return;
  }
  wios::s_basic_ios__clear_c1c9b0
            ((wios *)(this + *(long *)(*(long *)this + -0x18)),
             *(uint *)((wios *)(this + *(long *)(*(long *)this + -0x18)) + 0x20) | 4);
  return;
}


// ==== entry=00c26d20 orig=FUN_00c26d20 size=165 name=wofstream ====

/* std::wofstream::wofstream(std::string const&, std::_Ios_Openmode) */

void __thiscall
std::wofstream::wofstream(wofstream *this,long *param_1,undefined8 *param_3,uint param_4)

{
  wfilebuf *this_00;
  long lVar1;
  wios *pwVar2;
  
  lVar1 = param_1[1];
  this_00 = (wfilebuf *)(this + 8);
  *(long *)this = lVar1;
  lVar1 = *(long *)(lVar1 + -0x18);
  *(long *)(this + lVar1) = param_1[2];
  wios::init((wios *)(this + lVar1),(wstreambuf *)0x0);
  lVar1 = *param_1;
  *(long *)this = lVar1;
  *(long *)(this + *(long *)(lVar1 + -0x18)) = param_1[3];
                    /* try { // try from 00c26d6a to 00c26d6e has its CatchHandler @ 00c26dd1 */
  wfilebuf::wfilebuf(this_00);
                    /* try { // try from 00c26d7c to 00c26dc2 has its CatchHandler @ 00c26dcc */
  wios::init((wios *)(this + *(long *)(*(long *)this + -0x18)),(wstreambuf *)this_00);
  lVar1 = wfilebuf::open(this_00,*param_3,param_4 | 0x10);
  pwVar2 = (wios *)(this + *(long *)(*(long *)this + -0x18));
  if (lVar1 != 0) {
    wios::s_basic_ios__clear_c1c9b0(pwVar2,0);
    return;
  }
  wios::s_basic_ios__clear_c1c9b0(pwVar2,*(uint *)(pwVar2 + 0x20) | 4);
  return;
}


// ==== entry=00c26e00 orig=FUN_00c26e00 size=294 name=wofstream ====

/* std::wofstream::wofstream(std::string const&, std::_Ios_Openmode) */

void __thiscall std::wofstream::wofstream(wofstream *this,undefined8 *param_1,uint param_3)

{
  wfilebuf *this_00;
  long lVar1;
  wios *pwVar2;
  
  ios_base::ios_base((ios_base *)(this + 0xf8));
  this[0x1dc] = (wofstream)0x0;
  *(undefined8 *)(this + 0x1d0) = 0;
  *(undefined4 *)(this + 0x1d8) = 0;
  *(undefined ***)(this + 0xf8) = &PTR__wios_011b4e90;
  *(undefined8 *)(this + 0x1e0) = 0;
  *(undefined8 *)(this + 0x1e8) = 0;
  *(undefined8 *)(this + 0x1f0) = 0;
  *(undefined **)this = &DAT_011b64a0;
  *(undefined8 *)(this + 0x1f8) = 0;
  *(undefined **)(this + 0xf8) = &DAT_011b64c8;
                    /* try { // try from 00c26ea0 to 00c26ea4 has its CatchHandler @ 00c26f31 */
  wios::init((wios *)(this + 0xf8),(wstreambuf *)0x0);
  this_00 = (wfilebuf *)(this + 8);
  *(undefined ***)this = &PTR__wofstream_011b6510;
  *(undefined ***)(this + 0xf8) = &PTR__wofstream_011b6538;
                    /* try { // try from 00c26ec5 to 00c26ec9 has its CatchHandler @ 00c26f2f */
  wfilebuf::wfilebuf(this_00);
                    /* try { // try from 00c26ed0 to 00c26f1a has its CatchHandler @ 00c26f2a */
  wios::init((wios *)(this + 0xf8),(wstreambuf *)this_00);
  lVar1 = wfilebuf::open(this_00,*param_1,param_3 | 0x10);
  pwVar2 = (wios *)(this + *(long *)(*(long *)this + -0x18));
  if (lVar1 != 0) {
    wios::s_basic_ios__clear_c1c9b0(pwVar2,0);
    return;
  }
  wios::s_basic_ios__clear_c1c9b0(pwVar2,*(uint *)(pwVar2 + 0x20) | 4);
  return;
}


// ==== entry=00c26f80 orig=FUN_00c26f80 size=61 name=open ====

/* std::wofstream::open(std::string const&, std::_Ios_Openmode) */

void __thiscall std::wofstream::open(wofstream *this,undefined8 *param_1,uint param_3)

{
  long lVar1;
  
  lVar1 = wfilebuf::open((wfilebuf *)(this + 8),*param_1,param_3 | 0x10);
  if (lVar1 != 0) {
    wios::s_basic_ios__clear_c1c9b0((wios *)(this + *(long *)(*(long *)this + -0x18)),0);
    return;
  }
  wios::s_basic_ios__clear_c1c9b0
            ((wios *)(this + *(long *)(*(long *)this + -0x18)),
             *(uint *)((wios *)(this + *(long *)(*(long *)this + -0x18)) + 0x20) | 4);
  return;
}


// ==== entry=00c26fd0 orig=FUN_00c26fd0 size=242 name=wfstream ====

/* std::wfstream::wfstream(std::string const&, std::_Ios_Openmode) */

void __thiscall
std::wfstream::wfstream(wfstream *this,long *param_1,undefined8 *param_3,undefined4 param_4)

{
  wfilebuf *this_00;
  long lVar1;
  wios *pwVar2;
  
  lVar1 = param_1[2];
  *(long *)this = lVar1;
  *(long *)(this + *(long *)(lVar1 + -0x18)) = param_1[3];
  *(undefined8 *)(this + 8) = 0;
  wios::init((wios *)(this + *(long *)(lVar1 + -0x18)),(wstreambuf *)0x0);
  lVar1 = param_1[4];
  *(long *)(this + 0x10) = lVar1;
  lVar1 = *(long *)(lVar1 + -0x18);
  *(long *)(this + lVar1 + 0x10) = param_1[5];
                    /* try { // try from 00c27027 to 00c2702b has its CatchHandler @ 00c270cb */
  wios::init((wios *)(this + lVar1 + 0x10),(wstreambuf *)0x0);
  lVar1 = param_1[1];
  this_00 = (wfilebuf *)(this + 0x18);
  *(long *)this = lVar1;
  *(long *)(this + *(long *)(lVar1 + -0x18)) = param_1[6];
  *(long *)(this + 0x10) = param_1[7];
  lVar1 = *param_1;
  *(long *)this = lVar1;
  *(long *)(this + *(long *)(lVar1 + -0x18)) = param_1[8];
  *(long *)(this + 0x10) = param_1[9];
                    /* try { // try from 00c27069 to 00c2706d has its CatchHandler @ 00c270c9 */
  wfilebuf::wfilebuf(this_00);
                    /* try { // try from 00c2707b to 00c270ba has its CatchHandler @ 00c270c4 */
  wios::init((wios *)(this + *(long *)(*(long *)this + -0x18)),(wstreambuf *)this_00);
  lVar1 = wfilebuf::open(this_00,*param_3,param_4);
  pwVar2 = (wios *)(this + *(long *)(*(long *)this + -0x18));
  if (lVar1 != 0) {
    wios::s_basic_ios__clear_c1c9b0(pwVar2,0);
    return;
  }
  wios::s_basic_ios__clear_c1c9b0(pwVar2,*(uint *)(pwVar2 + 0x20) | 4);
  return;
}


// ==== entry=00c27130 orig=FUN_00c27130 size=388 name=wfstream ====

/* std::wfstream::wfstream(std::string const&, std::_Ios_Openmode) */

void __thiscall std::wfstream::wfstream(wfstream *this,undefined8 *param_1,undefined4 param_3)

{
  wfilebuf *this_00;
  long lVar1;
  wios *pwVar2;
  
  ios_base::ios_base((ios_base *)(this + 0x108));
  *(undefined8 *)(this + 0x1e0) = 0;
  *(undefined4 *)(this + 0x1e8) = 0;
  *(undefined ***)(this + 0x108) = &PTR__wios_011b4e90;
  this[0x1ec] = (wfstream)0x0;
  *(undefined8 *)(this + 0x1f0) = 0;
  *(undefined8 *)(this + 0x1f8) = 0;
  *(undefined8 *)(this + 0x200) = 0;
  *(undefined8 *)(this + 0x208) = 0;
  *(undefined **)this = &DAT_011b65b0;
  *(undefined **)(this + 0x108) = &DAT_011b65d8;
  *(undefined8 *)(this + 8) = 0;
                    /* try { // try from 00c271e8 to 00c271ec has its CatchHandler @ 00c2732f */
  wios::init((wios *)(this + 0x108),(wstreambuf *)0x0);
  *(undefined **)(this + 0x10) = &DAT_011b6560;
  *(undefined **)(this + 0x108) = &DAT_011b6588;
                    /* try { // try from 00c2720c to 00c27210 has its CatchHandler @ 00c2732d */
  wios::init((wios *)(this + 0x108),(wstreambuf *)0x0);
  this_00 = (wfilebuf *)(this + 0x18);
  *(undefined **)(this + 0x108) = &DAT_011b6650;
  *(undefined ***)this = &PTR__wfstream_011b66c8;
  *(undefined ***)(this + 0x108) = &PTR__wfstream_011b6718;
  *(undefined ***)(this + 0x10) = &PTR__wfstream_011b66f0;
                    /* try { // try from 00c27251 to 00c27255 has its CatchHandler @ 00c272bc */
  wfilebuf::wfilebuf(this_00);
                    /* try { // try from 00c2725c to 00c272aa has its CatchHandler @ 00c272ba */
  wios::init((wios *)(this + 0x108),(wstreambuf *)this_00);
  lVar1 = wfilebuf::open(this_00,*param_1,param_3);
  pwVar2 = (wios *)(this + *(long *)(*(long *)this + -0x18));
  if (lVar1 != 0) {
    wios::s_basic_ios__clear_c1c9b0(pwVar2,0);
    return;
  }
  wios::s_basic_ios__clear_c1c9b0(pwVar2,*(uint *)(pwVar2 + 0x20) | 4);
  return;
}


// ==== entry=00c27340 orig=FUN_00c27340 size=58 name=open ====

/* std::wfstream::open(std::string const&, std::_Ios_Openmode) */

void std::wfstream::open(long *param_1,undefined8 *param_2)

{
  long lVar1;
  wios *pwVar2;
  
  lVar1 = wfilebuf::open((wfilebuf *)(param_1 + 3),*param_2);
  if (lVar1 != 0) {
    wios::s_basic_ios__clear_c1c9b0((wios *)((long)param_1 + *(long *)(*param_1 + -0x18)),0);
    return;
  }
  pwVar2 = (wios *)((long)param_1 + *(long *)(*param_1 + -0x18));
  wios::s_basic_ios__clear_c1c9b0(pwVar2,*(uint *)(pwVar2 + 0x20) | 4);
  return;
}


// ==== entry=00c27390 name=FUN_00c27390 size=102 ====

/* WARNING: Removing unreachable block (ram,0x00c273f0) */

void FUN_00c27390(allocator *param_1)

{
  allocator *paVar1;
  int iVar2;
  long lVar3;
  long in_FS_OFFSET;
  
  lVar3 = *(long *)(in_FS_OFFSET + 0x28);
  if (param_1 != (allocator *)&std::string::_Rep::_S_empty_rep_storage) {
    LOCK();
    paVar1 = param_1 + 0x10;
    iVar2 = *(int *)paVar1;
    *(int *)paVar1 = *(int *)paVar1 + -1;
    UNLOCK();
    if (iVar2 < 1) {
      std::string::_Rep::_M_destroy(param_1);
    }
  }
  if (lVar3 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


// ==== entry=00c27400 orig=FUN_00c27400 size=28 name=logic_error ====

/* std::logic_error::logic_error(std::logic_error const&) */

void __thiscall std::logic_error::logic_error(logic_error *this,logic_error *param_1)

{
  *(undefined ***)this = &PTR__logic_error_011b29e0;
  string::string((string *)(this + 8),(string *)(param_1 + 8));
  return;
}


// ==== entry=00c27420 orig=FUN_00c27420 size=22 name=operator= ====

/* std::logic_error::TEMPNAMEPLACEHOLDERVALUE(std::logic_error const&) */

logic_error * __thiscall std::logic_error::operator=(logic_error *this,logic_error *param_1)

{
  string::assign((string *)(this + 8),(string *)(param_1 + 8));
  return this;
}


// ==== entry=00c27440 name=FUN_00c27440 size=28 ====

void FUN_00c27440(undefined8 *param_1,long param_2)

{
  *param_1 = &PTR__runtime_error_011b2aa8;
  std::string::string((string *)(param_1 + 1),(string *)(param_2 + 8));
  return;
}


// ==== entry=00c27460 orig=FUN_00c27460 size=22 name=operator= ====

/* std::runtime_error::TEMPNAMEPLACEHOLDERVALUE(std::runtime_error const&) */

runtime_error * __thiscall std::runtime_error::operator=(runtime_error *this,runtime_error *param_1)

{
  string::assign((string *)(this + 8),(string *)(param_1 + 8));
  return this;
}


// ==== entry=00c27480 orig=FUN_00c27480 size=82 name=logic_error ====

/* std::logic_error::logic_error(char const*) */

void __thiscall std::logic_error::logic_error(logic_error *this,char *param_1)

{
  long in_FS_OFFSET;
  allocator local_21;
  long local_20;
  
  local_20 = *(long *)(in_FS_OFFSET + 0x28);
  *(undefined ***)this = &PTR__logic_error_011b29e0;
                    /* try { // try from 00c274b1 to 00c274b5 has its CatchHandler @ 00c274d2 */
  string::string((string *)(this + 8),param_1,&local_21);
  if (local_20 == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ==== entry=00c274e0 orig=FUN_00c274e0 size=25 name=domain_error ====

/* std::domain_error::domain_error(char const*) */

void __thiscall std::domain_error::domain_error(domain_error *this,char *param_1)

{
  logic_error::logic_error((logic_error *)this,param_1);
  *(undefined ***)this = &PTR__domain_error_011b2a08;
  return;
}


// ==== entry=00c27500 orig=FUN_00c27500 size=25 name=invalid_argument ====

/* std::invalid_argument::invalid_argument(char const*) */

void __thiscall std::invalid_argument::invalid_argument(invalid_argument *this,char *param_1)

{
  logic_error::logic_error((logic_error *)this,param_1);
  *(undefined ***)this = &PTR__invalid_argument_011b2a30;
  return;
}


// ==== entry=00c27520 orig=FUN_00c27520 size=25 name=length_error ====

/* std::length_error::length_error(char const*) */

void __thiscall std::length_error::length_error(length_error *this,char *param_1)

{
  logic_error::logic_error((logic_error *)this,param_1);
  *(undefined ***)this = &PTR__length_error_011b2a58;
  return;
}


// ==== entry=00c27540 orig=FUN_00c27540 size=25 name=out_of_range ====

/* std::out_of_range::out_of_range(char const*) */

void __thiscall std::out_of_range::out_of_range(out_of_range *this,char *param_1)

{
  logic_error::logic_error((logic_error *)this,param_1);
  *(undefined ***)this = &PTR__out_of_range_011b2a80;
  return;
}


// ==== entry=00c27560 orig=FUN_00c27560 size=82 name=runtime_error ====

/* std::runtime_error::runtime_error(char const*) */

void __thiscall std::runtime_error::runtime_error(runtime_error *this,char *param_1)

{
  long in_FS_OFFSET;
  allocator local_21;
  long local_20;
  
  local_20 = *(long *)(in_FS_OFFSET + 0x28);
  *(undefined ***)this = &PTR__runtime_error_011b2aa8;
                    /* try { // try from 00c27591 to 00c27595 has its CatchHandler @ 00c275b2 */
  string::string((string *)(this + 8),param_1,&local_21);
  if (local_20 == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ==== entry=00c275c0 orig=FUN_00c275c0 size=25 name=range_error ====

/* std::range_error::range_error(char const*) */

void __thiscall std::range_error::range_error(range_error *this,char *param_1)

{
  runtime_error::runtime_error((runtime_error *)this,param_1);
  *(undefined ***)this = &PTR__range_error_011b2ad0;
  return;
}


// ==== entry=00c275e0 orig=FUN_00c275e0 size=25 name=overflow_error ====

/* std::overflow_error::overflow_error(char const*) */

void __thiscall std::overflow_error::overflow_error(overflow_error *this,char *param_1)

{
  runtime_error::runtime_error((runtime_error *)this,param_1);
  *(undefined ***)this = &PTR__overflow_error_011b2af8;
  return;
}


// ==== entry=00c27600 orig=FUN_00c27600 size=25 name=underflow_error ====

/* std::underflow_error::underflow_error(char const*) */

void __thiscall std::underflow_error::underflow_error(underflow_error *this,char *param_1)

{
  runtime_error::runtime_error((runtime_error *)this,param_1);
  *(undefined ***)this = &PTR__underflow_error_011b2b20;
  return;
}


// ==== entry=00c27620 name=FUN_00c27620 size=12 ====

void FUN_00c27620(undefined8 param_1,long *param_2)

{
  FUN_00c79280(param_1,*param_2,*(undefined8 *)(*param_2 + -0x18));
  return;
}


// ==== entry=00c27630 name=FUN_00c27630 size=15 ====

void FUN_00c27630(undefined8 *param_1)

{
  *param_1 = &DAT_011c5338;
  return;
}


// ==== entry=00c27640 orig=FUN_00c27640 size=5 name=string ====

/* WARNING: Removing unreachable block (ram,0x00c2a118) */

void __thiscall std::string::string(string *this,string *param_1)

{
  long lVar1;
  long in_FS_OFFSET;
  allocator aStack_11;
  long lStack_10;
  
  lStack_10 = *(long *)(in_FS_OFFSET + 0x28);
  lVar1 = *(long *)param_1;
  if (*(int *)(lVar1 + -8) < 0) {
    lVar1 = _Rep::_M_clone((_Rep *)(lVar1 + -0x18),&aStack_11,0);
  }
  else if ((_Rep *)(lVar1 + -0x18) != (_Rep *)&_Rep::_S_empty_rep_storage) {
    LOCK();
    *(int *)(lVar1 + -8) = *(int *)(lVar1 + -8) + 1;
    UNLOCK();
  }
  *(long *)this = lVar1;
  if (lStack_10 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


// ==== entry=00c27650 name=FUN_00c27650 size=56 ====

void FUN_00c27650(string *param_1,char *param_2,ulong param_3)

{
  long in_FS_OFFSET;
  allocator local_11;
  long local_10;
  
  local_10 = *(long *)(in_FS_OFFSET + 0x28);
  std::string::string(param_1,param_2,param_3,&local_11);
  if (local_10 == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ==== entry=00c27690 orig=FUN_00c27690 size=5 name=string ====

/* WARNING: Removing unreachable block (ram,0x00c2a118) */

void __thiscall std::string::string(string *this,string *param_1)

{
  long lVar1;
  long in_FS_OFFSET;
  allocator aStack_11;
  long lStack_10;
  
  lStack_10 = *(long *)(in_FS_OFFSET + 0x28);
  lVar1 = *(long *)param_1;
  if (*(int *)(lVar1 + -8) < 0) {
    lVar1 = _Rep::_M_clone((_Rep *)(lVar1 + -0x18),&aStack_11,0);
  }
  else if ((_Rep *)(lVar1 + -0x18) != (_Rep *)&_Rep::_S_empty_rep_storage) {
    LOCK();
    *(int *)(lVar1 + -8) = *(int *)(lVar1 + -8) + 1;
    UNLOCK();
  }
  *(long *)this = lVar1;
  if (lStack_10 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


// ==== entry=00c276a0 name=FUN_00c276a0 size=14 ====

string * FUN_00c276a0(string *param_1,string *param_2)

{
  std::string::assign(param_1,param_2);
  return param_1;
}


// ==== entry=00c276b0 name=FUN_00c276b0 size=109 ====

/* WARNING: Removing unreachable block (ram,0x00c27718) */

void FUN_00c276b0(long *param_1)

{
  allocator *paVar1;
  int *piVar2;
  int iVar3;
  long lVar4;
  long in_FS_OFFSET;
  
  lVar4 = *(long *)(in_FS_OFFSET + 0x28);
  paVar1 = (allocator *)(*param_1 + -0x18);
  if (paVar1 != (allocator *)&std::string::_Rep::_S_empty_rep_storage) {
    LOCK();
    piVar2 = (int *)(*param_1 + -8);
    iVar3 = *piVar2;
    *piVar2 = *piVar2 + -1;
    UNLOCK();
    if (iVar3 < 1) {
      std::string::_Rep::_M_destroy(paVar1);
    }
  }
  if (lVar4 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


// ==== entry=00c27730 name=FUN_00c27730 size=21 ====

void FUN_00c27730(undefined8 *param_1,undefined8 *param_2)

{
  *param_1 = *param_2;
  *param_2 = &DAT_011c5338;
  return;
}


// ==== entry=00c27750 name=FUN_00c27750 size=14 ====

string * FUN_00c27750(string *param_1,string *param_2)

{
  std::string::swap(param_1,param_2);
  return param_1;
}


// ==== entry=00c27760 orig=FUN_00c27760 size=147 name=_M_message ====

/* WARNING: Removing unreachable block (ram,0x00c277e8) */
/* std::_V2::error_category::_M_message(int) const */

error_category * __thiscall std::_V2::error_category::_M_message(error_category *this,int param_1)

{
  int *piVar1;
  int iVar2;
  undefined4 in_register_00000034;
  long in_FS_OFFSET;
  long local_18;
  long local_10;
  
  local_10 = *(long *)(in_FS_OFFSET + 0x28);
  (**(code **)(*(long *)CONCAT44(in_register_00000034,param_1) + 0x18))(&local_18);
                    /* try { // try from 00c2778f to 00c27793 has its CatchHandler @ 00c277f8 */
  FUN_00c79280(this,local_18,*(undefined8 *)(local_18 + -0x18));
  if ((allocator *)(local_18 + -0x18) != (allocator *)&string::_Rep::_S_empty_rep_storage) {
    LOCK();
    piVar1 = (int *)(local_18 + -8);
    iVar2 = *piVar1;
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if (iVar2 < 1) {
      string::_Rep::_M_destroy((allocator *)(local_18 + -0x18));
    }
  }
  if (local_10 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return this;
}


// ==== entry=00c27800 name=FUN_00c27800 size=105 ====

void FUN_00c27800(undefined8 *param_1,long param_2)

{
  char cVar1;
  long *plVar2;
  long lVar3;
  
  lVar3 = 1;
  while( true ) {
    cVar1 = _ITM_RU1(param_2 + -1 + lVar3);
    if (cVar1 == '\0') break;
    lVar3 = lVar3 + 1;
  }
                    /* try { // try from 00c27836 to 00c2783a has its CatchHandler @ 00c2786e */
  plVar2 = (long *)new__(lVar3 + 0x18);
  *(undefined4 *)(plVar2 + 2) = 0;
  plVar2[1] = lVar3 + -1;
  *plVar2 = lVar3 + -1;
  _ITM_memcpyRtWn(plVar2 + 3,param_2,lVar3);
  *param_1 = plVar2 + 3;
  return;
}


// ==== entry=00c27880 orig=FUN_00c27880 size=5 name=_ITM_RU8 ====

void _ITM_RU8(void)

{
  _ITM_RU8();
  return;
}


// ==== entry=00c27890 orig=FUN_00c27890 size=5 name=_ITM_RU8 ====

void _ITM_RU8(void)

{
  _ITM_RU8();
  return;
}


// ==== entry=00c278a0 name=FUN_00c278a0 size=34 ====

void FUN_00c278a0(void)

{
  long lVar1;
  
  lVar1 = _ITM_RU8();
  _ITM_addUserCommitAction(FUN_00c27390,1,lVar1 + -0x18);
  return;
}


// ==== entry=00c278d0 name=FUN_00c278d0 size=5 ====

long FUN_00c278d0(long param_1)

{
  return param_1 + 8;
}


// ==== entry=00c278e0 name=FUN_00c278e0 size=5 ====

long FUN_00c278e0(long param_1)

{
  return param_1 + 8;
}


// ==== entry=00c278f0 name=FUN_00c278f0 size=124 ====

void FUN_00c278f0(undefined8 param_1,undefined8 param_2)

{
  undefined8 uVar1;
  long in_FS_OFFSET;
  logic_error alStack_38 [24];
  long local_20;
  
  local_20 = *(long *)(in_FS_OFFSET + 0x28);
  std::logic_error::logic_error(alStack_38,"");
                    /* try { // try from 00c2792b to 00c27945 has its CatchHandler @ 00c2796c */
  _ITM_memcpyRnWt(param_1,alStack_38,0x10);
  uVar1 = FUN_00c278d0(param_1);
  FUN_00c27800(uVar1,param_2,param_1);
  std::logic_error::~logic_error(alStack_38);
  if (local_20 == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ==== entry=00c27980 name=FUN_00c27980 size=135 ====

void FUN_00c27980(undefined8 param_1,undefined8 param_2)

{
  undefined8 uVar1;
  undefined8 uVar2;
  long in_FS_OFFSET;
  logic_error alStack_38 [24];
  long local_20;
  
  local_20 = *(long *)(in_FS_OFFSET + 0x28);
  std::logic_error::logic_error(alStack_38,"");
                    /* try { // try from 00c279bb to 00c279e0 has its CatchHandler @ 00c27a07 */
  _ITM_memcpyRnWt(param_1,alStack_38,0x10);
  uVar1 = _ITM_RU8(param_2);
  uVar2 = FUN_00c278d0(param_1);
  FUN_00c27800(uVar2,uVar1,param_1);
  std::logic_error::~logic_error(alStack_38);
  if (local_20 == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ==== entry=00c27a10 name=FUN_00c27a10 size=21 ====

void FUN_00c27a10(void)

{
  undefined8 uVar1;
  
  uVar1 = FUN_00c278d0();
  FUN_00c278a0(uVar1);
  return;
}


// ==== entry=00c27a30 name=FUN_00c27a30 size=18 ====

void FUN_00c27a30(void *param_1)

{
  FUN_00c27a10();
  delete(param_1);
  return;
}


// ==== entry=00c27a50 name=FUN_00c27a50 size=21 ====

void FUN_00c27a50(void)

{
  undefined8 uVar1;
  
  uVar1 = FUN_00c278d0();
  _ITM_RU8(uVar1);
  return;
}


// ==== entry=00c27a70 name=FUN_00c27a70 size=124 ====

void FUN_00c27a70(undefined8 param_1,undefined8 param_2)

{
  undefined8 uVar1;
  long in_FS_OFFSET;
  domain_error adStack_38 [24];
  long local_20;
  
  local_20 = *(long *)(in_FS_OFFSET + 0x28);
  std::domain_error::domain_error(adStack_38,"");
                    /* try { // try from 00c27aab to 00c27ac5 has its CatchHandler @ 00c27aec */
  _ITM_memcpyRnWt(param_1,adStack_38,0x10);
  uVar1 = FUN_00c278d0(param_1);
  FUN_00c27800(uVar1,param_2,param_1);
  std::domain_error::~domain_error(adStack_38);
  if (local_20 == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ==== entry=00c27b00 name=FUN_00c27b00 size=135 ====

void FUN_00c27b00(undefined8 param_1,undefined8 param_2)

{
  undefined8 uVar1;
  undefined8 uVar2;
  long in_FS_OFFSET;
  domain_error adStack_38 [24];
  long local_20;
  
  local_20 = *(long *)(in_FS_OFFSET + 0x28);
  std::domain_error::domain_error(adStack_38,"");
                    /* try { // try from 00c27b3b to 00c27b60 has its CatchHandler @ 00c27b87 */
  _ITM_memcpyRnWt(param_1,adStack_38,0x10);
  uVar1 = _ITM_RU8(param_2);
  uVar2 = FUN_00c278d0(param_1);
  FUN_00c27800(uVar2,uVar1,param_1);
  std::domain_error::~domain_error(adStack_38);
  if (local_20 == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ==== entry=00c27b90 name=FUN_00c27b90 size=21 ====

void FUN_00c27b90(void)

{
  undefined8 uVar1;
  
  uVar1 = FUN_00c278d0();
  FUN_00c278a0(uVar1);
  return;
}


// ==== entry=00c27bb0 name=FUN_00c27bb0 size=18 ====

void FUN_00c27bb0(void *param_1)

{
  FUN_00c27b90();
  delete(param_1);
  return;
}


// ==== entry=00c27bd0 name=FUN_00c27bd0 size=124 ====

void FUN_00c27bd0(undefined8 param_1,undefined8 param_2)

{
  undefined8 uVar1;
  long in_FS_OFFSET;
  invalid_argument aiStack_38 [24];
  long local_20;
  
  local_20 = *(long *)(in_FS_OFFSET + 0x28);
  std::invalid_argument::invalid_argument(aiStack_38,"");
                    /* try { // try from 00c27c0b to 00c27c25 has its CatchHandler @ 00c27c4c */
  _ITM_memcpyRnWt(param_1,aiStack_38,0x10);
  uVar1 = FUN_00c278d0(param_1);
  FUN_00c27800(uVar1,param_2,param_1);
  std::invalid_argument::~invalid_argument(aiStack_38);
  if (local_20 == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ==== entry=00c27c60 name=FUN_00c27c60 size=135 ====

void FUN_00c27c60(undefined8 param_1,undefined8 param_2)

{
  undefined8 uVar1;
  undefined8 uVar2;
  long in_FS_OFFSET;
  invalid_argument aiStack_38 [24];
  long local_20;
  
  local_20 = *(long *)(in_FS_OFFSET + 0x28);
  std::invalid_argument::invalid_argument(aiStack_38,"");
                    /* try { // try from 00c27c9b to 00c27cc0 has its CatchHandler @ 00c27ce7 */
  _ITM_memcpyRnWt(param_1,aiStack_38,0x10);
  uVar1 = _ITM_RU8(param_2);
  uVar2 = FUN_00c278d0(param_1);
  FUN_00c27800(uVar2,uVar1,param_1);
  std::invalid_argument::~invalid_argument(aiStack_38);
  if (local_20 == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ==== entry=00c27cf0 name=FUN_00c27cf0 size=21 ====

void FUN_00c27cf0(void)

{
  undefined8 uVar1;
  
  uVar1 = FUN_00c278d0();
  FUN_00c278a0(uVar1);
  return;
}


// ==== entry=00c27d10 name=FUN_00c27d10 size=18 ====

void FUN_00c27d10(void *param_1)

{
  FUN_00c27cf0();
  delete(param_1);
  return;
}


// ==== entry=00c27d30 name=FUN_00c27d30 size=124 ====

void FUN_00c27d30(undefined8 param_1,undefined8 param_2)

{
  undefined8 uVar1;
  long in_FS_OFFSET;
  length_error alStack_38 [24];
  long local_20;
  
  local_20 = *(long *)(in_FS_OFFSET + 0x28);
  std::length_error::length_error(alStack_38,"");
                    /* try { // try from 00c27d6b to 00c27d85 has its CatchHandler @ 00c27dac */
  _ITM_memcpyRnWt(param_1,alStack_38,0x10);
  uVar1 = FUN_00c278d0(param_1);
  FUN_00c27800(uVar1,param_2,param_1);
  std::length_error::~length_error(alStack_38);
  if (local_20 == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ==== entry=00c27dc0 name=FUN_00c27dc0 size=135 ====

void FUN_00c27dc0(undefined8 param_1,undefined8 param_2)

{
  undefined8 uVar1;
  undefined8 uVar2;
  long in_FS_OFFSET;
  length_error alStack_38 [24];
  long local_20;
  
  local_20 = *(long *)(in_FS_OFFSET + 0x28);
  std::length_error::length_error(alStack_38,"");
                    /* try { // try from 00c27dfb to 00c27e20 has its CatchHandler @ 00c27e47 */
  _ITM_memcpyRnWt(param_1,alStack_38,0x10);
  uVar1 = _ITM_RU8(param_2);
  uVar2 = FUN_00c278d0(param_1);
  FUN_00c27800(uVar2,uVar1,param_1);
  std::length_error::~length_error(alStack_38);
  if (local_20 == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ==== entry=00c27e50 name=FUN_00c27e50 size=21 ====

void FUN_00c27e50(void)

{
  undefined8 uVar1;
  
  uVar1 = FUN_00c278d0();
  FUN_00c278a0(uVar1);
  return;
}


// ==== entry=00c27e70 name=FUN_00c27e70 size=18 ====

void FUN_00c27e70(void *param_1)

{
  FUN_00c27e50();
  delete(param_1);
  return;
}


// ==== entry=00c27e90 name=FUN_00c27e90 size=124 ====

void FUN_00c27e90(undefined8 param_1,undefined8 param_2)

{
  undefined8 uVar1;
  long in_FS_OFFSET;
  out_of_range aoStack_38 [24];
  long local_20;
  
  local_20 = *(long *)(in_FS_OFFSET + 0x28);
  std::out_of_range::out_of_range(aoStack_38,"");
                    /* try { // try from 00c27ecb to 00c27ee5 has its CatchHandler @ 00c27f0c */
  _ITM_memcpyRnWt(param_1,aoStack_38,0x10);
  uVar1 = FUN_00c278d0(param_1);
  FUN_00c27800(uVar1,param_2,param_1);
  std::out_of_range::~out_of_range(aoStack_38);
  if (local_20 == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ==== entry=00c27f20 name=FUN_00c27f20 size=135 ====

void FUN_00c27f20(undefined8 param_1,undefined8 param_2)

{
  undefined8 uVar1;
  undefined8 uVar2;
  long in_FS_OFFSET;
  out_of_range aoStack_38 [24];
  long local_20;
  
  local_20 = *(long *)(in_FS_OFFSET + 0x28);
  std::out_of_range::out_of_range(aoStack_38,"");
                    /* try { // try from 00c27f5b to 00c27f80 has its CatchHandler @ 00c27fa7 */
  _ITM_memcpyRnWt(param_1,aoStack_38,0x10);
  uVar1 = _ITM_RU8(param_2);
  uVar2 = FUN_00c278d0(param_1);
  FUN_00c27800(uVar2,uVar1,param_1);
  std::out_of_range::~out_of_range(aoStack_38);
  if (local_20 == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ==== entry=00c27fb0 name=FUN_00c27fb0 size=21 ====

void FUN_00c27fb0(void)

{
  undefined8 uVar1;
  
  uVar1 = FUN_00c278d0();
  FUN_00c278a0(uVar1);
  return;
}


// ==== entry=00c27fd0 name=FUN_00c27fd0 size=18 ====

void FUN_00c27fd0(void *param_1)

{
  FUN_00c27fb0();
  delete(param_1);
  return;
}


// ==== entry=00c27ff0 name=FUN_00c27ff0 size=124 ====

void FUN_00c27ff0(undefined8 param_1,undefined8 param_2)

{
  undefined8 uVar1;
  long in_FS_OFFSET;
  runtime_error arStack_38 [24];
  long local_20;
  
  local_20 = *(long *)(in_FS_OFFSET + 0x28);
  std::runtime_error::runtime_error(arStack_38,"");
                    /* try { // try from 00c2802b to 00c28045 has its CatchHandler @ 00c2806c */
  _ITM_memcpyRnWt(param_1,arStack_38,0x10);
  uVar1 = FUN_00c278e0(param_1);
  FUN_00c27800(uVar1,param_2,param_1);
  std::runtime_error::~runtime_error(arStack_38);
  if (local_20 == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ==== entry=00c28080 name=FUN_00c28080 size=135 ====

void FUN_00c28080(undefined8 param_1,undefined8 param_2)

{
  undefined8 uVar1;
  undefined8 uVar2;
  long in_FS_OFFSET;
  runtime_error arStack_38 [24];
  long local_20;
  
  local_20 = *(long *)(in_FS_OFFSET + 0x28);
  std::runtime_error::runtime_error(arStack_38,"");
                    /* try { // try from 00c280bb to 00c280e0 has its CatchHandler @ 00c28107 */
  _ITM_memcpyRnWt(param_1,arStack_38,0x10);
  uVar1 = _ITM_RU8(param_2);
  uVar2 = FUN_00c278e0(param_1);
  FUN_00c27800(uVar2,uVar1,param_1);
  std::runtime_error::~runtime_error(arStack_38);
  if (local_20 == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ==== entry=00c28110 name=FUN_00c28110 size=21 ====

void FUN_00c28110(void)

{
  undefined8 uVar1;
  
  uVar1 = FUN_00c278e0();
  FUN_00c278a0(uVar1);
  return;
}


// ==== entry=00c28130 name=FUN_00c28130 size=18 ====

void FUN_00c28130(void *param_1)

{
  FUN_00c28110();
  delete(param_1);
  return;
}


// ==== entry=00c28150 name=FUN_00c28150 size=21 ====

void FUN_00c28150(void)

{
  undefined8 uVar1;
  
  uVar1 = FUN_00c278e0();
  _ITM_RU8(uVar1);
  return;
}


// ==== entry=00c28170 name=FUN_00c28170 size=124 ====

void FUN_00c28170(undefined8 param_1,undefined8 param_2)

{
  undefined8 uVar1;
  long in_FS_OFFSET;
  range_error arStack_38 [24];
  long local_20;
  
  local_20 = *(long *)(in_FS_OFFSET + 0x28);
  std::range_error::range_error(arStack_38,"");
                    /* try { // try from 00c281ab to 00c281c5 has its CatchHandler @ 00c281ec */
  _ITM_memcpyRnWt(param_1,arStack_38,0x10);
  uVar1 = FUN_00c278e0(param_1);
  FUN_00c27800(uVar1,param_2,param_1);
  std::range_error::~range_error(arStack_38);
  if (local_20 == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ==== entry=00c28200 name=FUN_00c28200 size=135 ====

void FUN_00c28200(undefined8 param_1,undefined8 param_2)

{
  undefined8 uVar1;
  undefined8 uVar2;
  long in_FS_OFFSET;
  range_error arStack_38 [24];
  long local_20;
  
  local_20 = *(long *)(in_FS_OFFSET + 0x28);
  std::range_error::range_error(arStack_38,"");
                    /* try { // try from 00c2823b to 00c28260 has its CatchHandler @ 00c28287 */
  _ITM_memcpyRnWt(param_1,arStack_38,0x10);
  uVar1 = _ITM_RU8(param_2);
  uVar2 = FUN_00c278e0(param_1);
  FUN_00c27800(uVar2,uVar1,param_1);
  std::range_error::~range_error(arStack_38);
  if (local_20 == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ==== entry=00c28290 name=FUN_00c28290 size=21 ====

void FUN_00c28290(void)

{
  undefined8 uVar1;
  
  uVar1 = FUN_00c278e0();
  FUN_00c278a0(uVar1);
  return;
}


// ==== entry=00c282b0 name=FUN_00c282b0 size=18 ====

void FUN_00c282b0(void *param_1)

{
  FUN_00c28290();
  delete(param_1);
  return;
}


// ==== entry=00c282d0 name=FUN_00c282d0 size=124 ====

void FUN_00c282d0(undefined8 param_1,undefined8 param_2)

{
  undefined8 uVar1;
  long in_FS_OFFSET;
  overflow_error aoStack_38 [24];
  long local_20;
  
  local_20 = *(long *)(in_FS_OFFSET + 0x28);
  std::overflow_error::overflow_error(aoStack_38,"");
                    /* try { // try from 00c2830b to 00c28325 has its CatchHandler @ 00c2834c */
  _ITM_memcpyRnWt(param_1,aoStack_38,0x10);
  uVar1 = FUN_00c278e0(param_1);
  FUN_00c27800(uVar1,param_2,param_1);
  std::overflow_error::~overflow_error(aoStack_38);
  if (local_20 == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ==== entry=00c28360 name=FUN_00c28360 size=135 ====

void FUN_00c28360(undefined8 param_1,undefined8 param_2)

{
  undefined8 uVar1;
  undefined8 uVar2;
  long in_FS_OFFSET;
  overflow_error aoStack_38 [24];
  long local_20;
  
  local_20 = *(long *)(in_FS_OFFSET + 0x28);
  std::overflow_error::overflow_error(aoStack_38,"");
                    /* try { // try from 00c2839b to 00c283c0 has its CatchHandler @ 00c283e7 */
  _ITM_memcpyRnWt(param_1,aoStack_38,0x10);
  uVar1 = _ITM_RU8(param_2);
  uVar2 = FUN_00c278e0(param_1);
  FUN_00c27800(uVar2,uVar1,param_1);
  std::overflow_error::~overflow_error(aoStack_38);
  if (local_20 == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ==== entry=00c283f0 name=FUN_00c283f0 size=21 ====

void FUN_00c283f0(void)

{
  undefined8 uVar1;
  
  uVar1 = FUN_00c278e0();
  FUN_00c278a0(uVar1);
  return;
}


// ==== entry=00c28410 name=FUN_00c28410 size=18 ====

void FUN_00c28410(void *param_1)

{
  FUN_00c283f0();
  delete(param_1);
  return;
}


// ==== entry=00c28430 name=FUN_00c28430 size=124 ====

void FUN_00c28430(undefined8 param_1,undefined8 param_2)

{
  undefined8 uVar1;
  long in_FS_OFFSET;
  underflow_error auStack_38 [24];
  long local_20;
  
  local_20 = *(long *)(in_FS_OFFSET + 0x28);
  std::underflow_error::underflow_error(auStack_38,"");
                    /* try { // try from 00c2846b to 00c28485 has its CatchHandler @ 00c284ac */
  _ITM_memcpyRnWt(param_1,auStack_38,0x10);
  uVar1 = FUN_00c278e0(param_1);
  FUN_00c27800(uVar1,param_2,param_1);
  std::underflow_error::~underflow_error(auStack_38);
  if (local_20 == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ==== entry=00c284c0 name=FUN_00c284c0 size=135 ====

void FUN_00c284c0(undefined8 param_1,undefined8 param_2)

{
  undefined8 uVar1;
  undefined8 uVar2;
  long in_FS_OFFSET;
  underflow_error auStack_38 [24];
  long local_20;
  
  local_20 = *(long *)(in_FS_OFFSET + 0x28);
  std::underflow_error::underflow_error(auStack_38,"");
                    /* try { // try from 00c284fb to 00c28520 has its CatchHandler @ 00c28547 */
  _ITM_memcpyRnWt(param_1,auStack_38,0x10);
  uVar1 = _ITM_RU8(param_2);
  uVar2 = FUN_00c278e0(param_1);
  FUN_00c27800(uVar2,uVar1,param_1);
  std::underflow_error::~underflow_error(auStack_38);
  if (local_20 == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ==== entry=00c28550 name=FUN_00c28550 size=21 ====

void FUN_00c28550(void)

{
  undefined8 uVar1;
  
  uVar1 = FUN_00c278e0();
  FUN_00c278a0(uVar1);
  return;
}


// ==== entry=00c28570 name=FUN_00c28570 size=18 ====

void FUN_00c28570(void *param_1)

{
  FUN_00c28550();
  delete(param_1);
  return;
}


// ==== entry=00c28590 orig=FUN_00c28590 size=50 name=__throw_bad_exception ====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* std::__throw_bad_exception() */

void std::__throw_bad_exception(void)

{
  undefined8 *puVar1;
  
  puVar1 = (undefined8 *)__cxa_allocate_exception(8);
  *puVar1 = &PTR__bad_exception_011b19c0;
                    /* WARNING: Subroutine does not return */
  __cxa_throw(puVar1,&bad_exception::typeinfo,bad_exception::~bad_exception);
}


// ==== entry=00c285d0 orig=FUN_00c285d0 size=50 name=__throw_bad_alloc ====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* std::__throw_bad_alloc() */

void std::__throw_bad_alloc(void)

{
  undefined8 *puVar1;
  
  puVar1 = (undefined8 *)__cxa_allocate_exception(8);
  *puVar1 = &PTR__bad_alloc_011b1a50;
                    /* WARNING: Subroutine does not return */
  __cxa_throw(puVar1,&bad_alloc::typeinfo,bad_alloc::~bad_alloc);
}


// ==== entry=00c28610 orig=FUN_00c28610 size=50 name=__throw_bad_cast ====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* std::__throw_bad_cast() */

void std::__throw_bad_cast(void)

{
  undefined8 *puVar1;
  
  puVar1 = (undefined8 *)__cxa_allocate_exception(8);
  *puVar1 = &PTR__bad_cast_011b1928;
                    /* WARNING: Subroutine does not return */
  __cxa_throw(puVar1,&bad_cast::typeinfo,bad_cast::~bad_cast);
}


// ==== entry=00c28650 orig=FUN_00c28650 size=50 name=__throw_bad_typeid ====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* std::__throw_bad_typeid() */

void std::__throw_bad_typeid(void)

{
  undefined8 *puVar1;
  
  puVar1 = (undefined8 *)__cxa_allocate_exception(8);
  *puVar1 = &PTR__bad_typeid_011b7cd8;
                    /* WARNING: Subroutine does not return */
  __cxa_throw(puVar1,&bad_typeid::typeinfo,bad_typeid::~bad_typeid);
}


// ==== entry=00c28690 orig=FUN_00c28690 size=46 name=__throw_logic_error ====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* std::__throw_logic_error(char const*) */

void std::__throw_logic_error(char *param_1)

{
  logic_error *this;
  char *pcVar1;
  
  this = (logic_error *)__cxa_allocate_exception(0x10);
  pcVar1 = (char *)gettext(param_1);
                    /* try { // try from 00c286b4 to 00c286b8 has its CatchHandler @ 00c286be */
  logic_error::logic_error(this,pcVar1);
  FUN_0051dc18();
  return;
}


// ==== entry=00c286d0 orig=FUN_00c286d0 size=46 name=__throw_domain_error ====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* std::__throw_domain_error(char const*) */

void std::__throw_domain_error(char *param_1)

{
  domain_error *this;
  char *pcVar1;
  
  this = (domain_error *)__cxa_allocate_exception(0x10);
  pcVar1 = (char *)gettext(param_1);
                    /* try { // try from 00c286f4 to 00c286f8 has its CatchHandler @ 00c286fe */
  domain_error::domain_error(this,pcVar1);
  FUN_0051dc3e();
  return;
}


// ==== entry=00c28710 orig=FUN_00c28710 size=46 name=__throw_invalid_argument ====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* std::__throw_invalid_argument(char const*) */

void std::__throw_invalid_argument(char *param_1)

{
  invalid_argument *this;
  char *pcVar1;
  
  this = (invalid_argument *)__cxa_allocate_exception(0x10);
  pcVar1 = (char *)gettext(param_1);
                    /* try { // try from 00c28734 to 00c28738 has its CatchHandler @ 00c2873e */
  invalid_argument::invalid_argument(this,pcVar1);
  FUN_0051dc64();
  return;
}


// ==== entry=00c28750 orig=FUN_00c28750 size=46 name=__throw_length_error ====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* std::__throw_length_error(char const*) */

void std::__throw_length_error(char *param_1)

{
  length_error *this;
  char *pcVar1;
  
  this = (length_error *)__cxa_allocate_exception(0x10);
  pcVar1 = (char *)gettext(param_1);
                    /* try { // try from 00c28774 to 00c28778 has its CatchHandler @ 00c2877e */
  length_error::length_error(this,pcVar1);
  FUN_0051dc8a();
  return;
}


// ==== entry=00c28790 orig=FUN_00c28790 size=46 name=__throw_out_of_range ====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* std::__throw_out_of_range(char const*) */

void std::__throw_out_of_range(char *param_1)

{
  out_of_range *this;
  char *pcVar1;
  
  this = (out_of_range *)__cxa_allocate_exception(0x10);
  pcVar1 = (char *)gettext(param_1);
                    /* try { // try from 00c287b4 to 00c287b8 has its CatchHandler @ 00c287be */
  out_of_range::out_of_range(this,pcVar1);
  FUN_0051dcb0();
  return;
}


// ==== entry=00c287d0 orig=FUN_00c287d0 size=246 name=__throw_out_of_range_fmt ====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* std::__throw_out_of_range_fmt(char const*, ...) */

void std::__throw_out_of_range_fmt(char *param_1,...)

{
  long lVar1;
  char in_AL;
  size_t sVar2;
  out_of_range *this;
  char *pcVar3;
  undefined8 in_RCX;
  undefined8 in_RDX;
  undefined8 in_RSI;
  undefined8 in_R8;
  undefined8 in_R9;
  long in_FS_OFFSET;
  undefined8 in_XMM0_Qa;
  undefined8 in_XMM1_Qa;
  undefined8 in_XMM2_Qa;
  undefined8 in_XMM3_Qa;
  undefined8 in_XMM4_Qa;
  undefined8 in_XMM5_Qa;
  undefined8 in_XMM6_Qa;
  undefined8 in_XMM7_Qa;
  undefined8 uStack_f0;
  undefined4 local_e8;
  undefined4 local_e4;
  undefined1 *local_e0;
  undefined1 *local_d8;
  undefined8 local_d0;
  undefined1 local_c8 [8];
  undefined8 local_c0;
  undefined8 local_b8;
  undefined8 local_b0;
  undefined8 local_a8;
  undefined8 local_a0;
  undefined8 local_98;
  undefined8 local_88;
  undefined8 local_78;
  undefined8 local_68;
  undefined8 local_58;
  undefined8 local_48;
  undefined8 local_38;
  undefined8 local_28;
  
  if (in_AL != '\0') {
    local_98 = in_XMM0_Qa;
    local_88 = in_XMM1_Qa;
    local_78 = in_XMM2_Qa;
    local_68 = in_XMM3_Qa;
    local_58 = in_XMM4_Qa;
    local_48 = in_XMM5_Qa;
    local_38 = in_XMM6_Qa;
    local_28 = in_XMM7_Qa;
  }
  local_d0 = *(undefined8 *)(in_FS_OFFSET + 0x28);
  uStack_f0 = 0xc28845;
  local_c0 = in_RSI;
  local_b8 = in_RDX;
  local_b0 = in_RCX;
  local_a8 = in_R8;
  local_a0 = in_R9;
  sVar2 = strlen(param_1);
  local_e8 = 8;
  local_e4 = 0x30;
  lVar1 = -(sVar2 + 0x217 & 0xfffffffffffffff0);
  local_e0 = &stack0x00000008;
  local_d8 = local_c8;
  *(undefined8 *)((long)&uStack_f0 + lVar1) = 0xc288a1;
  FUN_00c445d0((long)&local_e0 + lVar1,sVar2 + 0x200,param_1,&local_e8);
  *(undefined8 *)((long)&uStack_f0 + lVar1) = 0xc288ab;
  this = (out_of_range *)__cxa_allocate_exception(0x10);
  *(undefined8 *)((long)&uStack_f0 + lVar1) = 0xc288b6;
  pcVar3 = (char *)gettext((long)&local_e0 + lVar1);
                    /* try { // try from 00c288bc to 00c288c0 has its CatchHandler @ 00c288c6 */
  *(undefined8 *)((long)&uStack_f0 + lVar1) = 0xc288c1;
  out_of_range::out_of_range(this,pcVar3);
  FUN_0051dcd6();
  return;
}


// ==== entry=00c288d0 orig=FUN_00c288d0 size=46 name=__throw_runtime_error ====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* std::__throw_runtime_error(char const*) */

void std::__throw_runtime_error(char *param_1)

{
  runtime_error *this;
  char *pcVar1;
  
  this = (runtime_error *)__cxa_allocate_exception(0x10);
  pcVar1 = (char *)gettext(param_1);
                    /* try { // try from 00c288f4 to 00c288f8 has its CatchHandler @ 00c288fe */
  runtime_error::runtime_error(this,pcVar1);
  FUN_0051dcfc();
  return;
}


// ==== entry=00c28910 orig=FUN_00c28910 size=46 name=__throw_range_error ====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* std::__throw_range_error(char const*) */

void std::__throw_range_error(char *param_1)

{
  range_error *this;
  char *pcVar1;
  
  this = (range_error *)__cxa_allocate_exception(0x10);
  pcVar1 = (char *)gettext(param_1);
                    /* try { // try from 00c28934 to 00c28938 has its CatchHandler @ 00c2893e */
  range_error::range_error(this,pcVar1);
  FUN_0051dd22();
  return;
}


// ==== entry=00c28950 orig=FUN_00c28950 size=46 name=__throw_overflow_error ====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* std::__throw_overflow_error(char const*) */

void std::__throw_overflow_error(char *param_1)

{
  overflow_error *this;
  char *pcVar1;
  
  this = (overflow_error *)__cxa_allocate_exception(0x10);
  pcVar1 = (char *)gettext(param_1);
                    /* try { // try from 00c28974 to 00c28978 has its CatchHandler @ 00c2897e */
  overflow_error::overflow_error(this,pcVar1);
  FUN_0051dd48();
  return;
}


// ==== entry=00c28990 orig=FUN_00c28990 size=46 name=__throw_underflow_error ====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* std::__throw_underflow_error(char const*) */

void std::__throw_underflow_error(char *param_1)

{
  underflow_error *this;
  char *pcVar1;
  
  this = (underflow_error *)__cxa_allocate_exception(0x10);
  pcVar1 = (char *)gettext(param_1);
                    /* try { // try from 00c289b4 to 00c289b8 has its CatchHandler @ 00c289be */
  underflow_error::underflow_error(this,pcVar1);
  FUN_0051dd6e();
  return;
}


// ==== entry=00c289d0 orig=FUN_00c289d0 size=4 name=_M_data ====

/* std::string::_M_data() const */

undefined8 __thiscall std::string::_M_data(string *this)

{
  return *(undefined8 *)this;
}


// ==== entry=00c289e0 orig=FUN_00c289e0 size=7 name=_M_data ====

/* std::string::_M_data(char*) */

char * __thiscall std::string::_M_data(string *this,char *param_1)

{
  *(char **)this = param_1;
  return param_1;
}


// ==== entry=00c289f0 orig=FUN_00c289f0 size=8 name=_M_rep ====

/* std::string::_M_rep() const */

long __thiscall std::string::_M_rep(string *this)

{
  return *(long *)this + -0x18;
}


// ==== entry=00c28a00 orig=FUN_00c28a00 size=4 name=_M_ibegin ====

/* std::string::_M_ibegin() const */

undefined8 __thiscall std::string::_M_ibegin(string *this)

{
  return *(undefined8 *)this;
}


// ==== entry=00c28a10 orig=FUN_00c28a10 size=8 name=_M_iend ====

/* std::string::_M_iend() const */

long __thiscall std::string::_M_iend(string *this)

{
  return *(long *)this + *(long *)(*(long *)this + -0x18);
}


// ==== entry=00c28a20 orig=FUN_00c28a20 size=37 name=_M_check ====

/* std::string::_M_check(unsigned long, char const*) const */

void __thiscall std::string::_M_check(string *this,ulong param_1,char *param_2)

{
  if (param_1 <= *(ulong *)(*(long *)this + -0x18)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __throw_out_of_range_fmt("%s: __pos (which is %zu) > this->size() (which is %zu)",param_2,param_1)
  ;
}


// ==== entry=00c28a50 orig=FUN_00c28a50 size=35 name=_M_check_length ====

/* std::string::_M_check_length(unsigned long, unsigned long, char const*) const */

void __thiscall std::string::_M_check_length(string *this,ulong param_1,ulong param_2,char *param_3)

{
  if (param_2 <= (param_1 + 0x3ffffffffffffff9) - *(long *)(*(long *)this + -0x18)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __throw_length_error(param_3);
}


// ==== entry=00c28a80 orig=FUN_00c28a80 size=18 name=_M_limit ====

/* std::string::_M_limit(unsigned long, unsigned long) const */

ulong __thiscall std::string::_M_limit(string *this,ulong param_1,ulong param_2)

{
  ulong uVar1;
  
  uVar1 = *(long *)(*(long *)this + -0x18) - param_1;
  if (param_2 < uVar1) {
    uVar1 = param_2;
  }
  return uVar1;
}


// ==== entry=00c28aa0 orig=FUN_00c28aa0 size=24 name=_M_disjunct ====

/* std::string::_M_disjunct(char const*) const */

bool __thiscall std::string::_M_disjunct(string *this,char *param_1)

{
  char *pcVar1;
  bool bVar2;
  
  pcVar1 = *(char **)this;
  bVar2 = true;
  if (pcVar1 <= param_1) {
    bVar2 = pcVar1 + *(long *)(pcVar1 + -0x18) < param_1;
  }
  return bVar2;
}


// ==== entry=00c28ac0 orig=FUN_00c28ac0 size=23 name=_M_copy ====

/* std::string::_M_copy(char*, char const*, unsigned long) */

void std::string::_M_copy(char *param_1,char *param_2,ulong param_3)

{
  if (param_3 == 1) {
    *param_1 = *param_2;
    return;
  }
  if (param_3 == 0) {
    return;
  }
  memcpy(param_1,param_2,param_3);
  return;
}


// ==== entry=00c28ae0 orig=FUN_00c28ae0 size=23 name=_M_move ====

/* std::string::_M_move(char*, char const*, unsigned long) */

void std::string::_M_move(char *param_1,char *param_2,ulong param_3)

{
  if (param_3 == 1) {
    *param_1 = *param_2;
    return;
  }
  if (param_3 == 0) {
    return;
  }
  memmove(param_1,param_2,param_3);
  return;
}


// ==== entry=00c28b00 orig=FUN_00c28b00 size=28 name=_M_assign ====

/* std::string::_M_assign(char*, unsigned long, char) */

void std::string::_M_assign(char *param_1,ulong param_2,char param_3)

{
  if (param_2 == 1) {
    *param_1 = param_3;
    return;
  }
  if (param_2 == 0) {
    return;
  }
  memset(param_1,(int)param_3,param_2);
  return;
}


// ==== entry=00c28b30 orig=FUN_00c28b30 size=26 name=_S_copy_chars ====

/* std::string::_S_copy_chars(char*, __gnu_cxx::__normal_iterator<char*, std::string >,
   __gnu_cxx::__normal_iterator<char*, std::string >) */

void std::string::_S_copy_chars(undefined1 *param_1,undefined1 *param_2,long param_3)

{
  size_t __n;
  
  __n = param_3 - (long)param_2;
  if (__n == 1) {
    *param_1 = *param_2;
    return;
  }
  if (__n == 0) {
    return;
  }
  memcpy(param_1,param_2,__n);
  return;
}


// ==== entry=00c28b50 orig=FUN_00c28b50 size=26 name=_S_copy_chars ====

/* std::string::_S_copy_chars(char*, __gnu_cxx::__normal_iterator<char const*, std::string >,
   __gnu_cxx::__normal_iterator<char const*, std::string >) */

void std::string::_S_copy_chars(undefined1 *param_1,undefined1 *param_2,long param_3)

{
  size_t __n;
  
  __n = param_3 - (long)param_2;
  if (__n == 1) {
    *param_1 = *param_2;
    return;
  }
  if (__n == 0) {
    return;
  }
  memcpy(param_1,param_2,__n);
  return;
}


// ==== entry=00c28b70 orig=FUN_00c28b70 size=26 name=_S_copy_chars ====

/* std::string::_S_copy_chars(char*, char*, char*) */

void std::string::_S_copy_chars(char *param_1,char *param_2,char *param_3)

{
  size_t __n;
  
  __n = (long)param_3 - (long)param_2;
  if (__n == 1) {
    *param_1 = *param_2;
    return;
  }
  if (__n == 0) {
    return;
  }
  memcpy(param_1,param_2,__n);
  return;
}


// ==== entry=00c28b90 orig=FUN_00c28b90 size=26 name=_S_copy_chars ====

/* std::string::_S_copy_chars(char*, char const*, char const*) */

void std::string::_S_copy_chars(char *param_1,char *param_2,char *param_3)

{
  size_t __n;
  
  __n = (long)param_3 - (long)param_2;
  if (__n == 1) {
    *param_1 = *param_2;
    return;
  }
  if (__n == 0) {
    return;
  }
  memcpy(param_1,param_2,__n);
  return;
}


// ==== entry=00c28bb0 orig=FUN_00c28bb0 size=31 name=_S_compare ====

/* std::string::_S_compare(unsigned long, unsigned long) */

ulong std::string::_S_compare(ulong param_1,ulong param_2)

{
  ulong uVar1;
  ulong uVar2;
  
  uVar2 = param_1 - param_2;
  uVar1 = 0x7fffffff;
  if (((long)uVar2 < 0x80000000) && (uVar1 = 0x80000000, -0x80000001 < (long)uVar2)) {
    uVar1 = uVar2 & 0xffffffff;
  }
  return uVar1;
}


// ==== entry=00c28bd0 orig=FUN_00c28bd0 size=8 name=_S_empty_rep ====

/* std::string::_S_empty_rep() */

undefined8 * std::string::_S_empty_rep(void)

{
  return &_Rep::_S_empty_rep_storage;
}


// ==== entry=00c28be0 orig=FUN_00c28be0 size=15 name=string ====

/* std::string::string() */

void __thiscall std::string::string(string *this)

{
  *(undefined1 **)this = &DAT_011c5338;
  return;
}


// ==== entry=00c28bf0 orig=FUN_00c28bf0 size=21 name=string ====

/* std::string::string(std::string&&) */

void __thiscall std::string::string(string *this,string *param_1)

{
  *(undefined8 *)this = *(undefined8 *)param_1;
  *(undefined1 **)param_1 = &DAT_011c5338;
  return;
}


// ==== entry=00c28c10 orig=FUN_00c28c10 size=4 name=begin ====

/* std::string::begin() const */

undefined8 __thiscall std::string::begin(string *this)

{
  return *(undefined8 *)this;
}


// ==== entry=00c28c20 orig=FUN_00c28c20 size=8 name=end ====

/* std::string::end() const */

long __thiscall std::string::end(string *this)

{
  return *(long *)this + *(long *)(*(long *)this + -0x18);
}


// ==== entry=00c28c30 orig=FUN_00c28c30 size=14 name=rbegin ====

/* std::string::rbegin() const */

void std::string::rbegin(void)

{
  long *in_RSI;
  long *in_RDI;
  
  *in_RDI = *in_RSI + *(long *)(*in_RSI + -0x18);
  return;
}


// ==== entry=00c28c40 orig=FUN_00c28c40 size=10 name=rend ====

/* std::string::rend() const */

void std::string::rend(void)

{
  undefined8 *in_RSI;
  undefined8 *in_RDI;
  
  *in_RDI = *in_RSI;
  return;
}


// ==== entry=00c28c50 orig=FUN_00c28c50 size=4 name=cbegin ====

/* std::string::cbegin() const */

undefined8 __thiscall std::string::cbegin(string *this)

{
  return *(undefined8 *)this;
}


// ==== entry=00c28c60 orig=FUN_00c28c60 size=8 name=cend ====

/* std::string::cend() const */

long __thiscall std::string::cend(string *this)

{
  return *(long *)this + *(long *)(*(long *)this + -0x18);
}


// ==== entry=00c28c70 orig=FUN_00c28c70 size=14 name=crbegin ====

/* std::string::crbegin() const */

void std::string::crbegin(void)

{
  long *in_RSI;
  long *in_RDI;
  
  *in_RDI = *in_RSI + *(long *)(*in_RSI + -0x18);
  return;
}


// ==== entry=00c28c80 orig=FUN_00c28c80 size=10 name=crend ====

/* std::string::crend() const */

void std::string::crend(void)

{
  undefined8 *in_RSI;
  undefined8 *in_RDI;
  
  *in_RDI = *in_RSI;
  return;
}


// ==== entry=00c28c90 orig=FUN_00c28c90 size=8 name=size ====

/* std::string::size() const */

undefined8 __thiscall std::string::size(string *this)

{
  return *(undefined8 *)(*(long *)this + -0x18);
}


// ==== entry=00c28ca0 orig=FUN_00c28ca0 size=8 name=length ====

/* std::string::length() const */

undefined8 __thiscall std::string::length(string *this)

{
  return *(undefined8 *)(*(long *)this + -0x18);
}


// ==== entry=00c28cb0 orig=FUN_00c28cb0 size=11 name=max_size ====

/* std::string::max_size() const */

undefined8 std::string::max_size(void)

{
  return 0x3ffffffffffffff9;
}


// ==== entry=00c28cc0 orig=FUN_00c28cc0 size=8 name=capacity ====

/* std::string::capacity() const */

undefined8 __thiscall std::string::capacity(string *this)

{
  return *(undefined8 *)(*(long *)this + -0x10);
}


// ==== entry=00c28cd0 orig=FUN_00c28cd0 size=12 name=empty ====

/* std::string::empty() const */

undefined8 __thiscall std::string::empty(string *this)

{
  return CONCAT71((int7)((ulong)*(long *)this >> 8),*(long *)(*(long *)this + -0x18) == 0);
}


// ==== entry=00c28ce0 orig=FUN_00c28ce0 size=7 name=operator[] ====

/* std::string::operator[](unsigned long) const */

long __thiscall std::string::operator[](string *this,ulong param_1)

{
  return *(long *)this + param_1;
}


// ==== entry=00c28cf0 orig=FUN_00c28cf0 size=31 name=at ====

/* std::string::at(unsigned long) const */

long __thiscall std::string::at(string *this,ulong param_1)

{
  if (param_1 < *(ulong *)(*(long *)this + -0x18)) {
    return *(long *)this + param_1;
  }
                    /* WARNING: Subroutine does not return */
  __throw_out_of_range_fmt("basic_string::at: __n (which is %zu) >= this->size() (which is %zu)");
}


// ==== entry=00c28d10 orig=FUN_00c28d10 size=4 name=front ====

/* std::string::front() const */

undefined8 __thiscall std::string::front(string *this)

{
  return *(undefined8 *)this;
}


// ==== entry=00c28d20 orig=FUN_00c28d20 size=13 name=back ====

/* std::string::back() const */

long __thiscall std::string::back(string *this)

{
  return *(long *)this + -1 + *(long *)(*(long *)this + -0x18);
}


// ==== entry=00c28d30 orig=FUN_00c28d30 size=97 name=s_basic_string__copy_c28d30 ====

/* std::string::copy(char*, unsigned long, unsigned long) const */

size_t __thiscall
std::string::s_basic_string__copy_c28d30(string *this,char *param_1,ulong param_2,ulong param_3)

{
  ulong uVar1;
  ulong __n;
  char *__src;
  
  uVar1 = *(ulong *)(*(long *)this + -0x18);
  if (uVar1 < param_3) {
                    /* WARNING: Subroutine does not return */
    __throw_out_of_range_fmt
              ("%s: __pos (which is %zu) > this->size() (which is %zu)","basic_string::copy",param_3
               ,uVar1);
  }
  __n = uVar1 - param_3;
  if (param_2 < uVar1 - param_3) {
    __n = param_2;
  }
  if (__n != 0) {
    __src = (char *)(param_3 + *(long *)this);
    if (__n == 1) {
      *param_1 = *__src;
      return 1;
    }
    memcpy(param_1,__src,__n);
  }
  return __n;
}


// ==== entry=00c28da0 orig=FUN_00c28da0 size=14 name=operator= ====

/* std::string::TEMPNAMEPLACEHOLDERVALUE(std::string&&) */

string * __thiscall std::string::operator=(string *this,string *param_1)

{
  swap(this,param_1);
  return this;
}


// ==== entry=00c28db0 orig=FUN_00c28db0 size=14 name=assign ====

/* std::string::assign(std::string&&) */

string * __thiscall std::string::assign(string *this,string *param_1)

{
  swap(this,param_1);
  return this;
}


// ==== entry=00c28dc0 orig=FUN_00c28dc0 size=4 name=c_str ====

/* std::string::c_str() const */

undefined8 __thiscall std::string::c_str(string *this)

{
  return *(undefined8 *)this;
}


// ==== entry=00c28dd0 orig=FUN_00c28dd0 size=4 name=data ====

/* std::string::data() const */

undefined8 __thiscall std::string::data(string *this)

{
  return *(undefined8 *)this;
}


// ==== entry=00c28de0 orig=FUN_00c28de0 size=4 name=get_allocator ====

/* std::string::get_allocator() const */

string * __thiscall std::string::get_allocator(string *this)

{
  return this;
}


// ==== entry=00c28df0 orig=FUN_00c28df0 size=12 name=find ====

/* std::string::find(std::string const&, unsigned long) const */

void __thiscall std::string::find(string *this,string *param_1,ulong param_2)

{
  find(this,*(char **)param_1,param_2,*(ulong *)(*(char **)param_1 + -0x18));
  return;
}


// ==== entry=00c28e00 orig=FUN_00c28e00 size=42 name=find ====

/* std::string::find(char const*, unsigned long) const */

void __thiscall std::string::find(string *this,char *param_1,ulong param_2)

{
  size_t sVar1;
  
  sVar1 = strlen(param_1);
  find(this,param_1,param_2,sVar1);
  return;
}


// ==== entry=00c28e30 orig=FUN_00c28e30 size=113 name=rfind ====

/* std::string::rfind(char const*, unsigned long, unsigned long) const */

ulong __thiscall std::string::rfind(string *this,char *param_1,ulong param_2,ulong param_3)

{
  long lVar1;
  int iVar2;
  ulong uVar3;
  bool bVar4;
  
  lVar1 = *(long *)this;
  uVar3 = *(ulong *)(lVar1 + -0x18);
  if (param_3 <= uVar3) {
    uVar3 = uVar3 - param_3;
    if (uVar3 <= param_2) {
      param_2 = uVar3;
    }
    do {
      if (param_3 == 0) {
        return param_2;
      }
      iVar2 = memcmp((void *)(lVar1 + param_2),param_1,param_3);
      if (iVar2 == 0) {
        return param_2;
      }
      bVar4 = param_2 != 0;
      param_2 = param_2 - 1;
    } while (bVar4);
  }
  return 0xffffffffffffffff;
}


// ==== entry=00c28eb0 orig=FUN_00c28eb0 size=12 name=rfind ====

/* std::string::rfind(std::string const&, unsigned long) const */

void __thiscall std::string::rfind(string *this,string *param_1,ulong param_2)

{
  rfind(this,*(char **)param_1,param_2,*(ulong *)(*(char **)param_1 + -0x18));
  return;
}


// ==== entry=00c28ec0 orig=FUN_00c28ec0 size=42 name=rfind ====

/* std::string::rfind(char const*, unsigned long) const */

void __thiscall std::string::rfind(string *this,char *param_1,ulong param_2)

{
  size_t sVar1;
  
  sVar1 = strlen(param_1);
  rfind(this,param_1,param_2,sVar1);
  return;
}


// ==== entry=00c28ef0 orig=FUN_00c28ef0 size=49 name=rfind ====

/* std::string::rfind(char, unsigned long) const */

void __thiscall std::string::rfind(string *this,char param_1,ulong param_2)

{
  long lVar1;
  ulong uVar2;
  
  lVar1 = *(long *)(*(long *)this + -0x18);
  if (lVar1 != 0) {
    uVar2 = lVar1 - 1;
    if (param_2 < uVar2) {
      uVar2 = param_2;
    }
    do {
      if (*(char *)(*(long *)this + uVar2) == param_1) {
        return;
      }
      uVar2 = uVar2 - 1;
    } while (uVar2 != 0xffffffffffffffff);
  }
  return;
}


// ==== entry=00c28f30 orig=FUN_00c28f30 size=103 name=find_first_of ====

/* std::string::find_first_of(char const*, unsigned long, unsigned long) const */

ulong __thiscall std::string::find_first_of(string *this,char *param_1,ulong param_2,ulong param_3)

{
  long lVar1;
  ulong uVar2;
  void *pvVar3;
  
  if (param_3 == 0) {
    return 0xffffffffffffffff;
  }
  lVar1 = *(long *)this;
  uVar2 = *(ulong *)(lVar1 + -0x18);
  if (param_2 < uVar2) {
    do {
      pvVar3 = memchr(param_1,(int)*(char *)(lVar1 + param_2),param_3);
      if (pvVar3 != (void *)0x0) {
        return param_2;
      }
      param_2 = param_2 + 1;
    } while (param_2 != uVar2);
  }
  return 0xffffffffffffffff;
}


// ==== entry=00c28fa0 orig=FUN_00c28fa0 size=12 name=find_first_of ====

/* std::string::find_first_of(std::string const&, unsigned long) const */

void __thiscall std::string::find_first_of(string *this,string *param_1,ulong param_2)

{
  find_first_of(this,*(char **)param_1,param_2,*(ulong *)(*(char **)param_1 + -0x18));
  return;
}


// ==== entry=00c28fb0 orig=FUN_00c28fb0 size=42 name=find_first_of ====

/* std::string::find_first_of(char const*, unsigned long) const */

void __thiscall std::string::find_first_of(string *this,char *param_1,ulong param_2)

{
  size_t sVar1;
  
  sVar1 = strlen(param_1);
  find_first_of(this,param_1,param_2,sVar1);
  return;
}


// ==== entry=00c28fe0 orig=FUN_00c28fe0 size=9 name=find_first_of ====

/* std::string::find_first_of(char, unsigned long) const */

void __thiscall std::string::find_first_of(string *this,char param_1,ulong param_2)

{
  find(this,param_1,param_2);
  return;
}


// ==== entry=00c28ff0 orig=FUN_00c28ff0 size=12 name=find_last_of ====

/* std::string::find_last_of(std::string const&, unsigned long) const */

void __thiscall std::string::find_last_of(string *this,string *param_1,ulong param_2)

{
  find_last_of(this,*(char **)param_1,param_2,*(ulong *)(*(char **)param_1 + -0x18));
  return;
}


// ==== entry=00c29000 orig=FUN_00c29000 size=42 name=find_last_of ====

/* std::string::find_last_of(char const*, unsigned long) const */

void __thiscall std::string::find_last_of(string *this,char *param_1,ulong param_2)

{
  size_t sVar1;
  
  sVar1 = strlen(param_1);
  find_last_of(this,param_1,param_2,sVar1);
  return;
}


// ==== entry=00c29030 orig=FUN_00c29030 size=9 name=find_last_of ====

/* std::string::find_last_of(char, unsigned long) const */

void __thiscall std::string::find_last_of(string *this,char param_1,ulong param_2)

{
  rfind(this,param_1,param_2);
  return;
}


// ==== entry=00c29040 orig=FUN_00c29040 size=94 name=find_first_not_of ====

/* std::string::find_first_not_of(char const*, unsigned long, unsigned long) const */

ulong __thiscall
std::string::find_first_not_of(string *this,char *param_1,ulong param_2,ulong param_3)

{
  long lVar1;
  ulong uVar2;
  void *pvVar3;
  
  lVar1 = *(long *)this;
  uVar2 = *(ulong *)(lVar1 + -0x18);
  if (param_2 < uVar2) {
    if (param_3 == 0) {
      return param_2;
    }
    do {
      pvVar3 = memchr(param_1,(int)*(char *)(lVar1 + param_2),param_3);
      if (pvVar3 == (void *)0x0) {
        return param_2;
      }
      param_2 = param_2 + 1;
    } while (param_2 != uVar2);
  }
  return 0xffffffffffffffff;
}


// ==== entry=00c290b0 orig=FUN_00c290b0 size=12 name=find_first_not_of ====

/* std::string::find_first_not_of(std::string const&, unsigned long) const */

void __thiscall std::string::find_first_not_of(string *this,string *param_1,ulong param_2)

{
  find_first_not_of(this,*(char **)param_1,param_2,*(ulong *)(*(char **)param_1 + -0x18));
  return;
}


// ==== entry=00c290c0 orig=FUN_00c290c0 size=42 name=find_first_not_of ====

/* std::string::find_first_not_of(char const*, unsigned long) const */

void __thiscall std::string::find_first_not_of(string *this,char *param_1,ulong param_2)

{
  size_t sVar1;
  
  sVar1 = strlen(param_1);
  find_first_not_of(this,param_1,param_2,sVar1);
  return;
}


// ==== entry=00c290f0 orig=FUN_00c290f0 size=57 name=find_first_not_of ====

/* std::string::find_first_not_of(char, unsigned long) const */

ulong __thiscall std::string::find_first_not_of(string *this,char param_1,ulong param_2)

{
  char cVar1;
  long lVar2;
  ulong uVar3;
  
  lVar2 = *(long *)this;
  uVar3 = 0xffffffffffffffff;
  if (param_2 < *(ulong *)(lVar2 + -0x18)) {
    cVar1 = *(char *)(lVar2 + param_2);
    uVar3 = param_2;
    while (param_1 == cVar1) {
      uVar3 = uVar3 + 1;
      if (uVar3 == *(ulong *)(lVar2 + -0x18)) {
        return 0xffffffffffffffff;
      }
      cVar1 = *(char *)(lVar2 + uVar3);
    }
  }
  return uVar3;
}


// ==== entry=00c29140 orig=FUN_00c29140 size=99 name=find_last_not_of ====

/* std::string::find_last_not_of(char const*, unsigned long, unsigned long) const */

ulong __thiscall
std::string::find_last_not_of(string *this,char *param_1,ulong param_2,ulong param_3)

{
  long lVar1;
  long lVar2;
  void *pvVar3;
  ulong uVar4;
  
  uVar4 = 0xffffffffffffffff;
  lVar1 = *(long *)this;
  lVar2 = *(long *)(lVar1 + -0x18);
  if (lVar2 != 0) {
    uVar4 = lVar2 - 1;
    if (uVar4 <= param_2) {
      param_2 = uVar4;
    }
    do {
      if (param_3 == 0) {
        return param_2;
      }
      pvVar3 = memchr(param_1,(int)*(char *)(lVar1 + param_2),param_3);
      if (pvVar3 == (void *)0x0) {
        return param_2;
      }
      uVar4 = param_2 - 1;
      param_2 = uVar4;
    } while (uVar4 != 0xffffffffffffffff);
  }
  return uVar4;
}


// ==== entry=00c291b0 orig=FUN_00c291b0 size=12 name=find_last_not_of ====

/* std::string::find_last_not_of(std::string const&, unsigned long) const */

void __thiscall std::string::find_last_not_of(string *this,string *param_1,ulong param_2)

{
  find_last_not_of(this,*(char **)param_1,param_2,*(ulong *)(*(char **)param_1 + -0x18));
  return;
}


// ==== entry=00c291c0 orig=FUN_00c291c0 size=42 name=find_last_not_of ====

/* std::string::find_last_not_of(char const*, unsigned long) const */

void __thiscall std::string::find_last_not_of(string *this,char *param_1,ulong param_2)

{
  size_t sVar1;
  
  sVar1 = strlen(param_1);
  find_last_not_of(this,param_1,param_2,sVar1);
  return;
}


// ==== entry=00c291f0 orig=FUN_00c291f0 size=48 name=find_last_not_of ====

/* std::string::find_last_not_of(char, unsigned long) const */

void __thiscall std::string::find_last_not_of(string *this,char param_1,ulong param_2)

{
  long lVar1;
  ulong uVar2;
  
  lVar1 = *(long *)(*(long *)this + -0x18);
  if (lVar1 != 0) {
    uVar2 = lVar1 - 1;
    if (param_2 < uVar2) {
      uVar2 = param_2;
    }
    do {
      if (*(char *)(*(long *)this + uVar2) != param_1) {
        return;
      }
      uVar2 = uVar2 - 1;
    } while (uVar2 != 0xffffffffffffffff);
  }
  return;
}


// ==== entry=00c29230 orig=FUN_00c29230 size=129 name=s_basic_string__compare_c29230 ====

/* std::string::compare(unsigned long, unsigned long, std::string const&) const */

ulong __thiscall
std::string::s_basic_string__compare_c29230
          (string *this,ulong param_1,ulong param_2,string *param_3)

{
  uint uVar1;
  ulong uVar2;
  ulong __n;
  ulong uVar3;
  
  uVar2 = *(ulong *)(*(long *)this + -0x18);
  if (uVar2 < param_1) {
                    /* WARNING: Subroutine does not return */
    __throw_out_of_range_fmt
              ("%s: __pos (which is %zu) > this->size() (which is %zu)","basic_string::compare",
               param_1,uVar2);
  }
  uVar3 = uVar2 - param_1;
  if (param_2 < uVar2 - param_1) {
    uVar3 = param_2;
  }
  uVar2 = *(ulong *)((long)*(void **)param_3 + -0x18);
  __n = uVar3;
  if (uVar2 <= uVar3) {
    __n = uVar2;
  }
  if (__n != 0) {
    uVar1 = memcmp((void *)(*(long *)this + param_1),*(void **)param_3,__n);
    if (uVar1 != 0) {
      return (ulong)uVar1;
    }
  }
  uVar3 = uVar3 - uVar2;
  uVar2 = 0x7fffffff;
  if (((long)uVar3 < 0x80000000) && (uVar2 = 0x80000000, -0x80000001 < (long)uVar3)) {
    uVar2 = uVar3 & 0xffffffff;
  }
  return uVar2;
}


// ==== entry=00c292c0 orig=FUN_00c292c0 size=174 name=s_basic_string__compare_c292c0 ====

/* std::string::compare(unsigned long, unsigned long, std::string const&, unsigned long, unsigned
   long) const */

ulong __thiscall
std::string::s_basic_string__compare_c292c0
          (string *this,ulong param_1,ulong param_2,string *param_3,ulong param_4,ulong param_5)

{
  uint uVar1;
  ulong uVar2;
  ulong uVar3;
  ulong uVar4;
  
  uVar2 = *(ulong *)(*(long *)this + -0x18);
  if (uVar2 < param_1) {
                    /* WARNING: Subroutine does not return */
    __throw_out_of_range_fmt
              ("%s: __pos (which is %zu) > this->size() (which is %zu)","basic_string::compare",
               param_1,uVar2);
  }
  uVar3 = *(ulong *)(*(long *)param_3 + -0x18);
  if (param_4 <= uVar3) {
    uVar4 = uVar2 - param_1;
    if (param_2 < uVar2 - param_1) {
      uVar4 = param_2;
    }
    uVar2 = uVar3 - param_4;
    if (param_5 < uVar3 - param_4) {
      uVar2 = param_5;
    }
    uVar3 = uVar4;
    if (uVar2 <= uVar4) {
      uVar3 = uVar2;
    }
    if (uVar3 != 0) {
      uVar1 = memcmp((void *)(*(long *)this + param_1),(void *)(*(long *)param_3 + param_4),uVar3);
      if (uVar1 != 0) {
        return (ulong)uVar1;
      }
    }
    uVar4 = uVar4 - uVar2;
    uVar2 = 0x7fffffff;
    if (((long)uVar4 < 0x80000000) && (uVar2 = 0x80000000, -0x80000001 < (long)uVar4)) {
      uVar2 = uVar4 & 0xffffffff;
    }
    return uVar2;
  }
                    /* WARNING: Subroutine does not return */
  __throw_out_of_range_fmt
            ("%s: __pos (which is %zu) > this->size() (which is %zu)","basic_string::compare",
             param_4,uVar3);
}


// ==== entry=00c29370 orig=FUN_00c29370 size=145 name=s_basic_string__compare_c29370 ====

/* std::string::compare(unsigned long, unsigned long, char const*) const */

ulong __thiscall
std::string::s_basic_string__compare_c29370(string *this,ulong param_1,ulong param_2,char *param_3)

{
  long lVar1;
  uint uVar2;
  size_t sVar3;
  ulong uVar4;
  ulong uVar5;
  
  lVar1 = *(long *)this;
  uVar4 = *(ulong *)(lVar1 + -0x18);
  if (uVar4 < param_1) {
                    /* WARNING: Subroutine does not return */
    __throw_out_of_range_fmt
              ("%s: __pos (which is %zu) > this->size() (which is %zu)","basic_string::compare",
               param_1,uVar4);
  }
  uVar5 = uVar4 - param_1;
  if (param_2 < uVar4 - param_1) {
    uVar5 = param_2;
  }
  sVar3 = strlen(param_3);
  uVar4 = uVar5;
  if (sVar3 <= uVar5) {
    uVar4 = sVar3;
  }
  if (uVar4 != 0) {
    uVar2 = memcmp((void *)(lVar1 + param_1),param_3,uVar4);
    if (uVar2 != 0) {
      return (ulong)uVar2;
    }
  }
  uVar5 = uVar5 - sVar3;
  uVar4 = 0x7fffffff;
  if (((long)uVar5 < 0x80000000) && (uVar4 = 0x80000000, -0x80000001 < (long)uVar5)) {
    uVar4 = uVar5 & 0xffffffff;
  }
  return uVar4;
}


// ==== entry=00c29410 orig=FUN_00c29410 size=125 name=s_basic_string__compare_c29410 ====

/* std::string::compare(unsigned long, unsigned long, char const*, unsigned long) const */

ulong __thiscall
std::string::s_basic_string__compare_c29410
          (string *this,ulong param_1,ulong param_2,char *param_3,ulong param_4)

{
  uint uVar1;
  ulong uVar2;
  ulong uVar3;
  
  uVar2 = *(ulong *)(*(long *)this + -0x18);
  if (uVar2 < param_1) {
                    /* WARNING: Subroutine does not return */
    __throw_out_of_range_fmt
              ("%s: __pos (which is %zu) > this->size() (which is %zu)","basic_string::compare",
               param_1,uVar2);
  }
  uVar3 = uVar2 - param_1;
  if (param_2 < uVar2 - param_1) {
    uVar3 = param_2;
  }
  uVar2 = param_4;
  if (uVar3 <= param_4) {
    uVar2 = uVar3;
  }
  if (uVar2 != 0) {
    uVar1 = memcmp((void *)(*(long *)this + param_1),param_3,uVar2);
    if (uVar1 != 0) {
      return (ulong)uVar1;
    }
  }
  uVar3 = uVar3 - param_4;
  uVar2 = 0x7fffffff;
  if (((long)uVar3 < 0x80000000) && (uVar2 = 0x80000000, -0x80000001 < (long)uVar3)) {
    uVar2 = uVar3 & 0xffffffff;
  }
  return uVar2;
}


// ==== entry=00c29490 orig=FUN_00c29490 size=4 name=_Alloc_hider ====

/* std::string::_Alloc_hider::_Alloc_hider(char*, std::allocator<char> const&) */

void __thiscall
std::string::_Alloc_hider::_Alloc_hider(_Alloc_hider *this,char *param_1,allocator *param_2)

{
  *(char **)this = param_1;
  return;
}


// ==== entry=00c294a0 orig=FUN_00c294a0 size=8 name=_S_empty_rep ====

/* std::string::_Rep::_S_empty_rep() */

undefined8 * std::string::_Rep::_S_empty_rep(void)

{
  return &_S_empty_rep_storage;
}


// ==== entry=00c294b0 orig=FUN_00c294b0 size=7 name=_M_is_leaked ====

/* std::string::_Rep::_M_is_leaked() const */

uint __thiscall std::string::_Rep::_M_is_leaked(_Rep *this)

{
  return *(uint *)(this + 0x10) >> 0x1f;
}


// ==== entry=00c294c0 orig=FUN_00c294c0 size=9 name=_M_is_shared ====

/* std::string::_Rep::_M_is_shared() const */

undefined4 __thiscall std::string::_Rep::_M_is_shared(_Rep *this)

{
  return CONCAT31((int3)((uint)*(int *)(this + 0x10) >> 8),0 < *(int *)(this + 0x10));
}


// ==== entry=00c294d0 orig=FUN_00c294d0 size=8 name=_M_set_leaked ====

/* std::string::_Rep::_M_set_leaked() */

void __thiscall std::string::_Rep::_M_set_leaked(_Rep *this)

{
  *(undefined4 *)(this + 0x10) = 0xffffffff;
  return;
}


// ==== entry=00c294e0 orig=FUN_00c294e0 size=8 name=_M_set_sharable ====

/* std::string::_Rep::_M_set_sharable() */

void __thiscall std::string::_Rep::_M_set_sharable(_Rep *this)

{
  *(undefined4 *)(this + 0x10) = 0;
  return;
}


// ==== entry=00c294f0 orig=FUN_00c294f0 size=26 name=_M_set_length_and_sharable ====

/* std::string::_Rep::_M_set_length_and_sharable(unsigned long) */

void __thiscall std::string::_Rep::_M_set_length_and_sharable(_Rep *this,ulong param_1)

{
  if (this == (_Rep *)&_S_empty_rep_storage) {
    return;
  }
  *(undefined4 *)(this + 0x10) = 0;
  *(ulong *)this = param_1;
  this[param_1 + 0x18] = (_Rep)0x0;
  return;
}


// ==== entry=00c29510 orig=FUN_00c29510 size=5 name=_M_refdata ====

/* std::string::_Rep::_M_refdata() */

_Rep * __thiscall std::string::_Rep::_M_refdata(_Rep *this)

{
  return this + 0x18;
}


// ==== entry=00c29520 orig=FUN_00c29520 size=111 name=_S_construct ====

/* std::string::_S_construct(unsigned long, char, std::allocator<char> const&) */

ulong * std::string::_S_construct(ulong param_1,char param_2,allocator *param_3)

{
  ulong *puVar1;
  ulong *__s;
  
  if (param_1 == 0) {
    return (ulong *)&DAT_011c5338;
  }
  puVar1 = (ulong *)_Rep::_S_create(param_1,0,param_3);
  __s = puVar1 + 3;
  if (param_1 == 1) {
    *(char *)(puVar1 + 3) = param_2;
  }
  else {
    __s = memset(__s,(int)param_2,param_1);
  }
  if (puVar1 != &_Rep::_S_empty_rep_storage) {
    *(undefined4 *)(puVar1 + 2) = 0;
    *puVar1 = param_1;
    *(undefined1 *)((long)puVar1 + param_1 + 0x18) = 0;
  }
  return __s;
}


// ==== entry=00c295b0 orig=FUN_00c295b0 size=21 name=string ====

/* std::string::string(std::allocator<char> const&) */

void __thiscall std::string::string(string *this,allocator *param_1)

{
  undefined8 uVar1;
  
  uVar1 = _S_construct(0,'\0',param_1);
  *(undefined8 *)this = uVar1;
  return;
}


// ==== entry=00c295d0 orig=FUN_00c295d0 size=26 name=string ====

/* std::string::string(unsigned long, char, std::allocator<char> const&) */

void __thiscall std::string::string(string *this,ulong param_1,char param_2,allocator *param_3)

{
  undefined8 uVar1;
  
  uVar1 = _S_construct(param_1,param_2,param_3);
  *(undefined8 *)this = uVar1;
  return;
}


// ==== entry=00c295f0 orig=FUN_00c295f0 size=9 name=_S_construct_aux_2 ====

/* std::string::_S_construct_aux_2(unsigned long, char, std::allocator<char> const&) */

void std::string::_S_construct_aux_2(ulong param_1,char param_2,allocator *param_3)

{
  _S_construct(param_1,param_2,param_3);
  return;
}


// ==== entry=00c29600 name=FUN_00c29600 size=105 ====

ulong * FUN_00c29600(undefined1 *param_1,long param_2,allocator *param_3)

{
  ulong *puVar1;
  ulong *__dest;
  ulong __n;
  
  __n = param_2 - (long)param_1;
  puVar1 = (ulong *)std::string::_Rep::_S_create(__n,0,param_3);
  __dest = puVar1 + 3;
  if (__n == 1) {
    *(undefined1 *)(puVar1 + 3) = *param_1;
  }
  else {
    __dest = memcpy(__dest,param_1,__n);
  }
  if (puVar1 != &std::string::_Rep::_S_empty_rep_storage) {
    *(undefined4 *)(puVar1 + 2) = 0;
    *puVar1 = __n;
    *(undefined1 *)((long)puVar1 + __n + 0x18) = 0;
  }
  return __dest;
}


// ==== entry=00c29680 orig=FUN_00c29680 size=5 name=_M_destroy ====

/* std::string::_Rep::_M_destroy(std::allocator<char> const&) */

void std::string::_Rep::_M_destroy(allocator *param_1)

{
  free(param_1);
  return;
}


// ==== entry=00c29690 name=FUN_00c29690 size=43 ====

/* WARNING: Removing unreachable block (ram,0x00c296b0) */

void FUN_00c29690(allocator *param_1)

{
  allocator *paVar1;
  int iVar2;
  
  LOCK();
  paVar1 = param_1 + 0x10;
  iVar2 = *(int *)paVar1;
  *(int *)paVar1 = *(int *)paVar1 + -1;
  UNLOCK();
  if (0 < iVar2) {
    return;
  }
  std::string::_Rep::_M_destroy(param_1);
  return;
}


// ==== entry=00c296d0 orig=FUN_00c296d0 size=50 name=_M_dispose ====

/* WARNING: Removing unreachable block (ram,0x00c29700) */
/* std::string::_Rep::_M_dispose(std::allocator<char> const&) */

void std::string::_Rep::_M_dispose(allocator *param_1)

{
  allocator *paVar1;
  int iVar2;
  
  if (param_1 != (allocator *)&_S_empty_rep_storage) {
    LOCK();
    paVar1 = param_1 + 0x10;
    iVar2 = *(int *)paVar1;
    *(int *)paVar1 = *(int *)paVar1 + -1;
    UNLOCK();
    if (iVar2 < 1) {
      _M_destroy(param_1);
      return;
    }
  }
  return;
}


// ==== entry=00c29710 orig=FUN_00c29710 size=169 name=clear ====

/* WARNING: Removing unreachable block (ram,0x00c297b8) */
/* std::string::clear() */

void __thiscall std::string::clear(string *this)

{
  int *piVar1;
  int iVar2;
  long lVar3;
  undefined1 *puVar4;
  long in_FS_OFFSET;
  
  lVar3 = *(long *)(in_FS_OFFSET + 0x28);
  puVar4 = *(undefined1 **)this;
  if (*(int *)(*(long *)this + -8) < 1) {
    if (puVar4 != &DAT_011c5338) {
      *(undefined4 *)(puVar4 + -8) = 0;
      *(undefined8 *)(puVar4 + -0x18) = 0;
      *puVar4 = 0;
    }
  }
  else {
    if ((allocator *)(puVar4 + -0x18) != (allocator *)&_Rep::_S_empty_rep_storage) {
      LOCK();
      piVar1 = (int *)(puVar4 + -8);
      iVar2 = *piVar1;
      *piVar1 = *piVar1 + -1;
      UNLOCK();
      if (iVar2 < 1) {
        _Rep::_M_destroy((allocator *)(puVar4 + -0x18));
      }
    }
    *(undefined1 **)this = &DAT_011c5338;
  }
  if (lVar3 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


// ==== entry=00c297d0 orig=FUN_00c297d0 size=25 name=front ====

/* std::string::front() */

long __thiscall std::string::front(string *this)

{
  if (*(int *)(*(long *)this + -8) < 0) {
    return *(long *)this;
  }
  _M_leak_hard(this);
  return *(long *)this;
}


// ==== entry=00c297f0 orig=FUN_00c297f0 size=40 name=operator[] ====

/* std::string::operator[](unsigned long) */

long __thiscall std::string::operator[](string *this,ulong param_1)

{
  long lVar1;
  
  lVar1 = *(long *)this;
  if (-1 < *(int *)(lVar1 + -8)) {
    _M_leak_hard(this);
    lVar1 = *(long *)this;
  }
  return lVar1 + param_1;
}


// ==== entry=00c29820 orig=FUN_00c29820 size=25 name=begin ====

/* std::string::begin() */

long __thiscall std::string::begin(string *this)

{
  if (*(int *)(*(long *)this + -8) < 0) {
    return *(long *)this;
  }
  _M_leak_hard(this);
  return *(long *)this;
}


// ==== entry=00c29840 orig=FUN_00c29840 size=47 name=rend ====

/* std::string::rend() */

void std::string::rend(void)

{
  long lVar1;
  string *in_RSI;
  long *in_RDI;
  
  lVar1 = *(long *)in_RSI;
  if (-1 < *(int *)(lVar1 + -8)) {
    _M_leak_hard(in_RSI);
    lVar1 = *(long *)in_RSI;
  }
  *in_RDI = lVar1;
  return;
}


// ==== entry=00c29870 orig=FUN_00c29870 size=51 name=rbegin ====

/* std::string::rbegin() */

void std::string::rbegin(void)

{
  long lVar1;
  string *in_RSI;
  long *in_RDI;
  
  lVar1 = *(long *)in_RSI;
  if (-1 < *(int *)(lVar1 + -8)) {
    _M_leak_hard(in_RSI);
    lVar1 = *(long *)in_RSI;
  }
  *in_RDI = lVar1 + *(long *)(lVar1 + -0x18);
  return;
}


// ==== entry=00c298b0 orig=FUN_00c298b0 size=33 name=end ====

/* std::string::end() */

long __thiscall std::string::end(string *this)

{
  long lVar1;
  
  lVar1 = *(long *)this;
  if (*(int *)(lVar1 + -8) < 0) {
    return lVar1 + *(long *)(lVar1 + -0x18);
  }
  _M_leak_hard(this);
  return *(long *)this + *(long *)(*(long *)this + -0x18);
}


// ==== entry=00c298e0 orig=FUN_00c298e0 size=46 name=back ====

/* std::string::back() */

long __thiscall std::string::back(string *this)

{
  long lVar1;
  long lVar2;
  
  lVar2 = *(long *)this;
  lVar1 = *(long *)(lVar2 + -0x18);
  if (-1 < *(int *)(lVar2 + -8)) {
    _M_leak_hard(this);
    lVar2 = *(long *)this;
  }
  return lVar2 + lVar1 + -1;
}


// ==== entry=00c29910 orig=FUN_00c29910 size=64 name=at ====

/* std::string::at(unsigned long) */

long __thiscall std::string::at(string *this,ulong param_1)

{
  long lVar1;
  
  lVar1 = *(long *)this;
  if (param_1 < *(ulong *)(lVar1 + -0x18)) {
    if (-1 < *(int *)(lVar1 + -8)) {
      _M_leak_hard(this);
      lVar1 = *(long *)this;
    }
    return lVar1 + param_1;
  }
                    /* WARNING: Subroutine does not return */
  __throw_out_of_range_fmt("basic_string::at: __n (which is %zu) >= this->size() (which is %zu)");
}


// ==== entry=00c29950 orig=FUN_00c29950 size=68 name=s_basic_string__erase_c29950 ====

/* std::string::erase(unsigned long, unsigned long) */

string * __thiscall
std::string::s_basic_string__erase_c29950(string *this,ulong param_1,ulong param_2)

{
  ulong uVar1;
  
  uVar1 = *(ulong *)(*(long *)this + -0x18) - param_1;
  if (uVar1 <= param_2) {
    param_2 = uVar1;
  }
  if (param_1 <= *(ulong *)(*(long *)this + -0x18)) {
    _M_mutate(this,param_1,param_2,0);
    return this;
  }
                    /* WARNING: Subroutine does not return */
  __throw_out_of_range_fmt
            ("%s: __pos (which is %zu) > this->size() (which is %zu)","basic_string::erase",param_1)
  ;
}


// ==== entry=00c299a0 orig=FUN_00c299a0 size=51 name=erase ====

/* std::string::erase(__gnu_cxx::__normal_iterator<char*, std::string >) */

long __thiscall std::string::erase(string *this,long param_2)

{
  long lVar1;
  long lVar2;
  
  lVar1 = *(long *)this;
  _M_mutate(this,param_2 - lVar1,1,0);
  lVar2 = *(long *)this;
  *(undefined4 *)(lVar2 + -8) = 0xffffffff;
  return lVar2 + (param_2 - lVar1);
}


// ==== entry=00c299e0 orig=FUN_00c299e0 size=128 name=_M_replace_aux ====

/* std::string::_M_replace_aux(unsigned long, unsigned long, unsigned long, char) */

string * __thiscall
std::string::_M_replace_aux(string *this,ulong param_1,ulong param_2,ulong param_3,char param_4)

{
  if ((param_2 + 0x3ffffffffffffff9) - *(long *)(*(long *)this + -0x18) < param_3) {
                    /* WARNING: Subroutine does not return */
    __throw_length_error("basic_string::_M_replace_aux");
  }
  _M_mutate(this,param_1,param_2,param_3);
  if (param_3 != 0) {
    if (param_3 == 1) {
      *(char *)(*(long *)this + param_1) = param_4;
      return this;
    }
    memset((char *)(*(long *)this + param_1),(int)param_4,param_3);
  }
  return this;
}


// ==== entry=00c29a70 orig=FUN_00c29a70 size=24 name=assign ====

/* std::string::assign(unsigned long, char) */

void __thiscall std::string::assign(string *this,ulong param_1,char param_2)

{
  _M_replace_aux(this,0,*(ulong *)(*(long *)this + -0x18),param_1,param_2);
  return;
}


// ==== entry=00c29a90 orig=FUN_00c29a90 size=32 name=operator= ====

/* std::string::TEMPNAMEPLACEHOLDERVALUE(char) */

string * __thiscall std::string::operator=(string *this,char param_1)

{
  _M_replace_aux(this,0,*(ulong *)(*(long *)this + -0x18),1,param_1);
  return this;
}


// ==== entry=00c29ab0 orig=FUN_00c29ab0 size=51 name=s_basic_string__insert_c29ab0 ====

/* std::string::insert(unsigned long, unsigned long, char) */

void __thiscall
std::string::s_basic_string__insert_c29ab0(string *this,ulong param_1,ulong param_2,char param_3)

{
  if (param_1 <= *(ulong *)(*(long *)this + -0x18)) {
    _M_replace_aux(this,param_1,0,param_2,param_3);
    return;
  }
                    /* WARNING: Subroutine does not return */
  __throw_out_of_range_fmt
            ("%s: __pos (which is %zu) > this->size() (which is %zu)","basic_string::insert",param_1
            );
}


// ==== entry=00c29af0 orig=FUN_00c29af0 size=55 name=insert ====

/* std::string::insert(__gnu_cxx::__normal_iterator<char*, std::string >, char) */

long __thiscall std::string::insert(string *this,long param_2,char param_3)

{
  long lVar1;
  long lVar2;
  
  lVar1 = *(long *)this;
  _M_replace_aux(this,param_2 - lVar1,0,1,param_3);
  lVar2 = *(long *)this;
  *(undefined4 *)(lVar2 + -8) = 0xffffffff;
  return lVar2 + (param_2 - lVar1);
}


// ==== entry=00c29b30 orig=FUN_00c29b30 size=62 name=s_basic_string__replace_c29b30 ====

/* std::string::replace(unsigned long, unsigned long, unsigned long, char) */

void __thiscall
std::string::s_basic_string__replace_c29b30
          (string *this,ulong param_1,ulong param_2,ulong param_3,char param_4)

{
  ulong uVar1;
  ulong uVar2;
  undefined7 in_register_00000081;
  
  uVar1 = *(ulong *)(*(long *)this + -0x18);
  uVar2 = uVar1 - param_1;
  if (uVar2 <= param_2) {
    param_2 = uVar2;
  }
  if (param_1 <= uVar1) {
    _M_replace_aux(this,param_1,param_2,param_3,param_4);
    return;
  }
                    /* WARNING: Subroutine does not return */
  __throw_out_of_range_fmt
            ("%s: __pos (which is %zu) > this->size() (which is %zu)","basic_string::replace",
             param_1,uVar1,CONCAT71(in_register_00000081,param_4),uVar1,uVar2);
}


// ==== entry=00c29b70 orig=FUN_00c29b70 size=15 name=replace ====

/* std::string::replace(__gnu_cxx::__normal_iterator<char*, std::string >,
   __gnu_cxx::__normal_iterator<char*, std::string >, unsigned long, char) */

void __thiscall
std::string::replace(string *this,long param_2,long param_3,ulong param_4,char param_5)

{
  _M_replace_aux(this,param_2 - *(long *)this,param_3 - param_2,param_4,param_5);
  return;
}


// ==== entry=00c29b80 orig=FUN_00c29b80 size=17 name=insert ====

/* std::string::insert(__gnu_cxx::__normal_iterator<char*, std::string >, unsigned long, char) */

void __thiscall std::string::insert(string *this,long param_2,ulong param_3,char param_4)

{
  _M_replace_aux(this,param_2 - *(long *)this,0,param_3,param_4);
  return;
}


// ==== entry=00c29ba0 orig=FUN_00c29ba0 size=14 name=operator= ====

/* std::string::TEMPNAMEPLACEHOLDERVALUE(std::initializer_list<char>) */

string * __thiscall std::string::operator=(string *this,char *param_2,ulong param_3)

{
  s_basic_string__assign_65a9ea(this,param_2,param_3);
  return this;
}


// ==== entry=00c29bb0 orig=FUN_00c29bb0 size=61 name=s_basic_string__assign_c29bb0 ====

/* std::string::assign(std::string const&, unsigned long, unsigned long) */

void std::string::s_basic_string__assign_c29bb0(string *param_1,ulong param_2,ulong param_3)

{
  ulong uVar1;
  ulong uVar2;
  ulong in_RCX;
  undefined8 in_R9;
  
  uVar1 = *(ulong *)(*(long *)param_2 + -0x18);
  uVar2 = uVar1 - param_3;
  if (in_RCX < uVar1 - param_3) {
    uVar2 = in_RCX;
  }
  if (param_3 <= uVar1) {
    s_basic_string__assign_65a9ea(param_1,(char *)(*(long *)param_2 + param_3),uVar2);
    return;
  }
                    /* WARNING: Subroutine does not return */
  __throw_out_of_range_fmt
            ("%s: __pos (which is %zu) > this->size() (which is %zu)","basic_string::assign",param_3
             ,uVar1,uVar1,in_R9,uVar2);
}


// ==== entry=00c29bf0 orig=FUN_00c29bf0 size=40 name=assign ====

/* std::string::assign(char const*) */

void __thiscall std::string::assign(string *this,char *param_1)

{
  size_t sVar1;
  
  sVar1 = strlen(param_1);
  s_basic_string__assign_65a9ea(this,param_1,sVar1);
  return;
}


// ==== entry=00c29c20 orig=FUN_00c29c20 size=5 name=s_basic_string__assign_c29c20 ====

/* std::string::assign(std::initializer_list<char>) */

long * std::string::s_basic_string__assign_c29c20(long *param_1,undefined1 *param_2,ulong param_3)

{
  undefined1 *puVar1;
  undefined8 *puVar2;
  undefined8 *puVar3;
  ulong uVar4;
  allocator aaStack_29 [9];
  
  puVar1 = (undefined1 *)*param_1;
  if (0x3ffffffffffffff9 < param_3) {
                    /* WARNING: Subroutine does not return */
    __throw_length_error("basic_string::assign");
  }
  if ((puVar1 <= param_2) && (param_2 <= puVar1 + *(long *)(puVar1 + -0x18))) {
    if (*(int *)(puVar1 + -8) < 1) {
      puVar1 = (undefined1 *)*param_1;
      if ((ulong)((long)param_2 - (long)puVar1) < param_3) {
        if (param_2 == puVar1) goto LAB_0065aad7;
        if (param_3 != 1) {
          memmove(puVar1,param_2,param_3);
          puVar1 = (undefined1 *)*param_1;
          goto LAB_0065aad7;
        }
      }
      else if (param_3 != 1) {
        if (param_3 != 0) {
          memcpy(puVar1,param_2,param_3);
          puVar1 = (undefined1 *)*param_1;
        }
        goto LAB_0065aad7;
      }
      *puVar1 = *param_2;
      puVar1 = (undefined1 *)*param_1;
LAB_0065aad7:
      if (puVar1 == &DAT_011c5338) {
        return param_1;
      }
      *(undefined4 *)(puVar1 + -8) = 0;
      *(ulong *)(puVar1 + -0x18) = param_3;
      puVar1[param_3] = 0;
      return param_1;
    }
    puVar1 = (undefined1 *)*param_1;
  }
  uVar4 = *(ulong *)(puVar1 + -0x10);
  if (param_3 <= uVar4) {
    if (*(int *)(puVar1 + -8) < 1) {
      puVar3 = (undefined8 *)*param_1;
      puVar2 = puVar3 + -3;
      goto LAB_0065aa64;
    }
    uVar4 = *(ulong *)(*param_1 + -0x10);
  }
  puVar2 = (undefined8 *)_Rep::_S_create(param_3,uVar4,aaStack_29);
  if ((undefined1 *)*param_1 != &DAT_011c5338) {
    FUN_006505de();
  }
  puVar3 = puVar2 + 3;
  *param_1 = (long)puVar3;
LAB_0065aa64:
  if (puVar2 != &_Rep::_S_empty_rep_storage) {
    *(undefined4 *)(puVar3 + -1) = 0;
    puVar3[-3] = param_3;
    *(undefined1 *)((long)puVar3 + param_3) = 0;
  }
  if (param_3 != 0) {
    if (param_3 == 1) {
      *(undefined1 *)*param_1 = *param_2;
      return param_1;
    }
    memcpy((undefined1 *)*param_1,param_2,param_3);
  }
  return param_1;
}


// ==== entry=00c29c30 orig=FUN_00c29c30 size=8 name=insert ====

/* std::string::insert(__gnu_cxx::__normal_iterator<char*, std::string >,
   std::initializer_list<char>) */

void std::string::insert(string *param_1,long param_2,char *param_3,ulong param_4)

{
  s_basic_string__insert_5fdc00(param_1,param_2 - *(long *)param_1,param_3,param_4);
  return;
}


// ==== entry=00c29c40 orig=FUN_00c29c40 size=64 name=s_basic_string__insert_c29c40 ====

/* std::string::insert(unsigned long, std::string const&, unsigned long, unsigned long) */

void __thiscall
std::string::s_basic_string__insert_c29c40
          (string *this,ulong param_1,string *param_2,ulong param_3,ulong param_4)

{
  ulong uVar1;
  ulong uVar2;
  
  uVar1 = *(ulong *)(*(long *)param_2 + -0x18);
  uVar2 = uVar1 - param_3;
  if (param_4 < uVar1 - param_3) {
    uVar2 = param_4;
  }
  if (param_3 <= uVar1) {
    s_basic_string__insert_5fdc00(this,param_1,(char *)(*(long *)param_2 + param_3),uVar2);
    return;
  }
                    /* WARNING: Subroutine does not return */
  __throw_out_of_range_fmt
            ("%s: __pos (which is %zu) > this->size() (which is %zu)","basic_string::insert",param_3
             ,uVar1,param_4,uVar1,uVar2);
}


// ==== entry=00c29c80 orig=FUN_00c29c80 size=42 name=insert ====

/* std::string::insert(unsigned long, char const*) */

void __thiscall std::string::insert(string *this,ulong param_1,char *param_2)

{
  size_t sVar1;
  
  sVar1 = strlen(param_2);
  s_basic_string__insert_5fdc00(this,param_1,param_2,sVar1);
  return;
}


// ==== entry=00c29cb0 orig=FUN_00c29cb0 size=12 name=insert ====

/* std::string::insert(unsigned long, std::string const&) */

void __thiscall std::string::insert(string *this,ulong param_1,string *param_2)

{
  s_basic_string__insert_5fdc00
            (this,param_1,*(char **)param_2,*(ulong *)(*(char **)param_2 + -0x18));
  return;
}


// ==== entry=00c29cc0 orig=FUN_00c29cc0 size=56 name=s_basic_string__erase_c29cc0 ====

/* std::string::pop_back() */

void __thiscall std::string::s_basic_string__erase_c29cc0(string *this)

{
  ulong uVar1;
  undefined8 in_R8;
  undefined8 in_R9;
  
  uVar1 = *(ulong *)(*(long *)this + -0x18);
  if (uVar1 - 1 <= uVar1) {
    _M_mutate(this,uVar1 - 1,1,0);
    return;
  }
                    /* WARNING: Subroutine does not return */
  __throw_out_of_range_fmt
            ("%s: __pos (which is %zu) > this->size() (which is %zu)","basic_string::erase",
             0xffffffffffffffff,0,in_R8,in_R9,uVar1);
}


// ==== entry=00c29d00 orig=FUN_00c29d00 size=37 name=_M_refcopy ====

/* WARNING: Removing unreachable block (ram,0x00c29d28) */
/* std::string::_Rep::_M_refcopy() */

_Rep * __thiscall std::string::_Rep::_M_refcopy(_Rep *this)

{
  if (this != (_Rep *)&_S_empty_rep_storage) {
    LOCK();
    *(int *)(this + 0x10) = *(int *)(this + 0x10) + 1;
    UNLOCK();
  }
  return this + 0x18;
}


// ==== entry=00c29d30 orig=FUN_00c29d30 size=30 name=shrink_to_fit ====

/* std::string::shrink_to_fit() */

void __thiscall std::string::shrink_to_fit(string *this)

{
  if (*(ulong *)(*(long *)this + -0x10) <= *(ulong *)(*(long *)this + -0x18)) {
    return;
  }
                    /* try { // try from 00c29d46 to 00c29d4a has its CatchHandler @ 00c29d50 */
  reserve(this,0);
  return;
}


// ==== entry=00c29d60 orig=FUN_00c29d60 size=5 name=operator+= ====

/* std::string::TEMPNAMEPLACEHOLDERVALUE(std::string const&) */

string * __thiscall std::string::operator+=(string *this,string *param_1)

{
  size_t __n;
  long lVar1;
  undefined1 *puVar2;
  ulong uVar3;
  
  __n = *(size_t *)(*(long *)param_1 + -0x18);
  if (__n != 0) {
    lVar1 = *(long *)this;
    uVar3 = *(long *)(lVar1 + -0x18) + __n;
    if ((*(ulong *)(lVar1 + -0x10) < uVar3) || (0 < *(int *)(lVar1 + -8))) {
      reserve(this,uVar3);
    }
    puVar2 = (undefined1 *)(*(long *)this + *(long *)(*(long *)this + -0x18));
    if (__n == 1) {
      *puVar2 = **(undefined1 **)param_1;
    }
    else {
      memcpy(puVar2,*(undefined1 **)param_1,__n);
    }
    puVar2 = *(undefined1 **)this;
    if (puVar2 != &DAT_011c5338) {
      *(undefined4 *)(puVar2 + -8) = 0;
      *(ulong *)(puVar2 + -0x18) = uVar3;
      puVar2[uVar3] = 0;
    }
  }
  return this;
}


// ==== entry=00c29d70 orig=FUN_00c29d70 size=189 name=s_basic_string__append_c29d70 ====

/* std::string::append(std::string const&, unsigned long, unsigned long) */

string * __thiscall
std::string::s_basic_string__append_c29d70(string *this,string *param_1,ulong param_2,ulong param_3)

{
  long lVar1;
  ulong __n;
  undefined1 *puVar2;
  ulong uVar3;
  
  uVar3 = *(ulong *)(*(long *)param_1 + -0x18);
  if (param_2 <= uVar3) {
    __n = uVar3 - param_2;
    if (param_3 < uVar3 - param_2) {
      __n = param_3;
    }
    if (__n != 0) {
      lVar1 = *(long *)this;
      uVar3 = *(long *)(lVar1 + -0x18) + __n;
      if ((*(ulong *)(lVar1 + -0x10) < uVar3) || (0 < *(int *)(lVar1 + -8))) {
        reserve(this,uVar3);
      }
      puVar2 = (undefined1 *)(*(long *)this + *(long *)(*(long *)this + -0x18));
      if (__n == 1) {
        *puVar2 = *(undefined1 *)(*(long *)param_1 + param_2);
      }
      else {
        memcpy(puVar2,(undefined1 *)(*(long *)param_1 + param_2),__n);
      }
      puVar2 = *(undefined1 **)this;
      if (puVar2 != &DAT_011c5338) {
        *(undefined4 *)(puVar2 + -8) = 0;
        *(ulong *)(puVar2 + -0x18) = uVar3;
        puVar2[uVar3] = 0;
      }
    }
    return this;
  }
                    /* WARNING: Subroutine does not return */
  __throw_out_of_range_fmt
            ("%s: __pos (which is %zu) > this->size() (which is %zu)","basic_string::append",param_2
             ,uVar3);
}


// ==== entry=00c29e40 orig=FUN_00c29e40 size=5 name=s_basic_string__append_c29e40 ====

/* std::string::TEMPNAMEPLACEHOLDERVALUE(std::initializer_list<char>) */

string * __thiscall
std::string::s_basic_string__append_c29e40(string *this,undefined1 *param_2,ulong param_3)

{
  ulong uVar1;
  undefined1 *puVar2;
  long lVar3;
  
  if (param_3 == 0) {
    return this;
  }
  puVar2 = *(undefined1 **)this;
  if (0x3ffffffffffffff9U - *(long *)(puVar2 + -0x18) < param_3) {
                    /* WARNING: Subroutine does not return */
    __throw_length_error("basic_string::append");
  }
  uVar1 = *(long *)(puVar2 + -0x18) + param_3;
  if (*(ulong *)(puVar2 + -0x10) < uVar1) {
LAB_005fd1a3:
    if ((puVar2 <= param_2) && (param_2 <= puVar2 + *(long *)(puVar2 + -0x18))) {
      reserve(this,uVar1);
      lVar3 = *(long *)this;
      param_2 = param_2 + (lVar3 - (long)puVar2);
      puVar2 = (undefined1 *)(lVar3 + *(long *)(lVar3 + -0x18));
      goto joined_r0x005fd1d4;
    }
    reserve(this,uVar1);
    lVar3 = *(long *)this;
  }
  else {
    if (0 < *(int *)(puVar2 + -8)) {
      puVar2 = *(undefined1 **)this;
      goto LAB_005fd1a3;
    }
    lVar3 = *(long *)this;
  }
  puVar2 = (undefined1 *)(lVar3 + *(long *)(lVar3 + -0x18));
joined_r0x005fd1d4:
  if (param_3 == 1) {
    *puVar2 = *param_2;
  }
  else {
    memcpy(puVar2,param_2,param_3);
  }
  puVar2 = *(undefined1 **)this;
  if (puVar2 != &DAT_011c5338) {
    *(undefined4 *)(puVar2 + -8) = 0;
    *(ulong *)(puVar2 + -0x18) = uVar1;
    puVar2[uVar1] = 0;
  }
  return this;
}


// ==== entry=00c29e50 orig=FUN_00c29e50 size=40 name=append ====

/* std::string::append(char const*) */

void __thiscall std::string::append(string *this,char *param_1)

{
  size_t sVar1;
  
  sVar1 = strlen(param_1);
  s_basic_string__append_5fd166(this,param_1,sVar1);
  return;
}


// ==== entry=00c29e80 orig=FUN_00c29e80 size=40 name=operator+= ====

/* std::string::TEMPNAMEPLACEHOLDERVALUE(char const*) */

void __thiscall std::string::operator+=(string *this,char *param_1)

{
  size_t sVar1;
  
  sVar1 = strlen(param_1);
  s_basic_string__append_5fd166(this,param_1,sVar1);
  return;
}


// ==== entry=00c29eb0 orig=FUN_00c29eb0 size=5 name=s_basic_string__append_c29eb0 ====

/* std::string::append(std::initializer_list<char>) */

string * std::string::s_basic_string__append_c29eb0
                   (string *param_1,undefined1 *param_2,ulong param_3)

{
  ulong uVar1;
  undefined1 *puVar2;
  long lVar3;
  
  if (param_3 == 0) {
    return param_1;
  }
  puVar2 = *(undefined1 **)param_1;
  if (0x3ffffffffffffff9U - *(long *)(puVar2 + -0x18) < param_3) {
                    /* WARNING: Subroutine does not return */
    __throw_length_error("basic_string::append");
  }
  uVar1 = *(long *)(puVar2 + -0x18) + param_3;
  if (*(ulong *)(puVar2 + -0x10) < uVar1) {
LAB_005fd1a3:
    if ((puVar2 <= param_2) && (param_2 <= puVar2 + *(long *)(puVar2 + -0x18))) {
      reserve(param_1,uVar1);
      lVar3 = *(long *)param_1;
      param_2 = param_2 + (lVar3 - (long)puVar2);
      puVar2 = (undefined1 *)(lVar3 + *(long *)(lVar3 + -0x18));
      goto joined_r0x005fd1d4;
    }
    reserve(param_1,uVar1);
    lVar3 = *(long *)param_1;
  }
  else {
    if (0 < *(int *)(puVar2 + -8)) {
      puVar2 = *(undefined1 **)param_1;
      goto LAB_005fd1a3;
    }
    lVar3 = *(long *)param_1;
  }
  puVar2 = (undefined1 *)(lVar3 + *(long *)(lVar3 + -0x18));
joined_r0x005fd1d4:
  if (param_3 == 1) {
    *puVar2 = *param_2;
  }
  else {
    memcpy(puVar2,param_2,param_3);
  }
  puVar2 = *(undefined1 **)param_1;
  if (puVar2 != &DAT_011c5338) {
    *(undefined4 *)(puVar2 + -8) = 0;
    *(ulong *)(puVar2 + -0x18) = uVar1;
    puVar2[uVar1] = 0;
  }
  return param_1;
}


// ==== entry=00c29ec0 orig=FUN_00c29ec0 size=166 name=s_basic_string__append_c29ec0 ====

/* std::string::append(unsigned long, char) */

string * __thiscall
std::string::s_basic_string__append_c29ec0(string *this,ulong param_1,char param_2)

{
  long lVar1;
  undefined1 *puVar2;
  char *__s;
  ulong uVar3;
  
  if (param_1 != 0) {
    lVar1 = *(long *)this;
    if (0x3ffffffffffffff9U - *(long *)(lVar1 + -0x18) < param_1) {
                    /* WARNING: Subroutine does not return */
      __throw_length_error("basic_string::append");
    }
    uVar3 = *(long *)(lVar1 + -0x18) + param_1;
    if ((*(ulong *)(lVar1 + -0x10) < uVar3) || (0 < *(int *)(lVar1 + -8))) {
      reserve(this,uVar3);
    }
    __s = (char *)(*(long *)this + *(long *)(*(long *)this + -0x18));
    if (param_1 == 1) {
      *__s = param_2;
    }
    else {
      memset(__s,(int)param_2,param_1);
    }
    puVar2 = *(undefined1 **)this;
    if (puVar2 != &DAT_011c5338) {
      *(undefined4 *)(puVar2 + -8) = 0;
      *(ulong *)(puVar2 + -0x18) = uVar3;
      puVar2[uVar3] = 0;
    }
  }
  return this;
}


// ==== entry=00c29f70 orig=FUN_00c29f70 size=67 name=s_basic_string__resize_c29f70 ====

/* std::string::resize(unsigned long, char) */

void __thiscall std::string::s_basic_string__resize_c29f70(string *this,ulong param_1,char param_2)

{
  ulong uVar1;
  
  uVar1 = *(ulong *)(*(long *)this + -0x18);
  if (0x3ffffffffffffff9 < param_1) {
                    /* WARNING: Subroutine does not return */
    __throw_length_error("basic_string::resize");
  }
  if (uVar1 > param_1 || param_1 == uVar1) {
    if (uVar1 <= param_1) {
      return;
    }
    _M_mutate(this,param_1,uVar1 - param_1,0);
    return;
  }
  s_basic_string__append_c29ec0(this,param_1 - uVar1,param_2);
  return;
}


// ==== entry=00c29fc0 orig=FUN_00c29fc0 size=7 name=resize ====

/* std::string::resize(unsigned long) */

void __thiscall std::string::resize(string *this,ulong param_1)

{
  s_basic_string__resize_c29f70(this,param_1,'\0');
  return;
}


// ==== entry=00c29fd0 orig=FUN_00c29fd0 size=112 name=operator+= ====

/* std::string::TEMPNAMEPLACEHOLDERVALUE(char) */

string * __thiscall std::string::operator+=(string *this,char param_1)

{
  ulong uVar1;
  long lVar2;
  long lVar3;
  undefined1 *puVar4;
  
  lVar2 = *(long *)this;
  lVar3 = *(long *)(lVar2 + -0x18);
  uVar1 = lVar3 + 1;
  if ((*(ulong *)(lVar2 + -0x10) < uVar1) || (0 < *(int *)(lVar2 + -8))) {
    reserve(this,uVar1);
  }
  *(char *)(*(long *)this + *(long *)(*(long *)this + -0x18)) = param_1;
  puVar4 = *(undefined1 **)this;
  if (puVar4 != &DAT_011c5338) {
    *(undefined4 *)(puVar4 + -8) = 0;
    *(ulong *)(puVar4 + -0x18) = uVar1;
    puVar4[lVar3 + 1] = 0;
  }
  return this;
}


// ==== entry=00c2a050 orig=FUN_00c2a050 size=54 name=_M_grab ====

/* WARNING: Removing unreachable block (ram,0x00c2a090) */
/* std::string::_Rep::_M_grab(std::allocator<char> const&, std::allocator<char> const&) */

allocator * std::string::_Rep::_M_grab(allocator *param_1,allocator *param_2)

{
  allocator *paVar1;
  
  if (*(int *)(param_1 + 0x10) < 0) {
    paVar1 = (allocator *)_M_clone((_Rep *)param_1,param_2,0);
    return paVar1;
  }
  if (param_1 != (allocator *)&_S_empty_rep_storage) {
    LOCK();
    *(int *)(param_1 + 0x10) = *(int *)(param_1 + 0x10) + 1;
    UNLOCK();
  }
  return param_1 + 0x18;
}


// ==== entry=00c2a0a0 orig=FUN_00c2a0a0 size=117 name=string ====

/* WARNING: Removing unreachable block (ram,0x00c2a118) */
/* std::string::string(std::string const&) */

void __thiscall std::string::string(string *this,string *param_1)

{
  long lVar1;
  long in_FS_OFFSET;
  allocator local_11;
  long local_10;
  
  local_10 = *(long *)(in_FS_OFFSET + 0x28);
  lVar1 = *(long *)param_1;
  if (*(int *)(lVar1 + -8) < 0) {
    lVar1 = _Rep::_M_clone((_Rep *)(lVar1 + -0x18),&local_11,0);
  }
  else if ((_Rep *)(lVar1 + -0x18) != (_Rep *)&_Rep::_S_empty_rep_storage) {
    LOCK();
    *(int *)(lVar1 + -8) = *(int *)(lVar1 + -8) + 1;
    UNLOCK();
  }
  *(long *)this = lVar1;
  if (local_10 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


// ==== entry=00c2a130 orig=FUN_00c2a130 size=5 name=operator= ====

/* WARNING: Removing unreachable block (ram,0x0052ba9c) */
/* WARNING: Removing unreachable block (ram,0x0052ba6a) */
/* std::string::TEMPNAMEPLACEHOLDERVALUE(std::string const&) */

string * __thiscall std::string::operator=(string *this,string *param_1)

{
  undefined8 *puVar1;
  int *piVar2;
  int iVar3;
  long *__src;
  size_t __n;
  long *plVar4;
  long *__dest;
  long lVar5;
  allocator aStack_19;
  
  __src = *(long **)param_1;
  if (*(long **)this != __src) {
    if ((int)__src[-1] < 0) {
      plVar4 = (long *)_Rep::_S_create(__src[-3],__src[-2],&aStack_19);
      __n = __src[-3];
      if (__n == 0) {
        __dest = plVar4 + 3;
        lVar5 = 0;
      }
      else {
        __dest = plVar4 + 3;
        if (__n == 1) {
          *(char *)(plVar4 + 3) = (char)*__src;
          lVar5 = __src[-3];
        }
        else {
          __dest = memcpy(__dest,__src,__n);
          lVar5 = __src[-3];
        }
      }
      if (plVar4 != &_Rep::_S_empty_rep_storage) {
        *(undefined4 *)(plVar4 + 2) = 0;
        *plVar4 = lVar5;
        *(undefined1 *)((long)plVar4 + lVar5 + 0x18) = 0;
      }
    }
    else {
      __dest = __src;
      if (__src != (long *)&DAT_011c5338) {
        LOCK();
        *(int *)(__src + -1) = (int)__src[-1] + 1;
        UNLOCK();
      }
    }
    puVar1 = (undefined8 *)(*(long *)this + -0x18);
    if (puVar1 != &_Rep::_S_empty_rep_storage) {
      LOCK();
      piVar2 = (int *)(*(long *)this + -8);
      iVar3 = *piVar2;
      *piVar2 = *piVar2 + -1;
      UNLOCK();
      if (iVar3 < 1) {
        operator_delete(puVar1);
      }
    }
    *(long **)this = __dest;
  }
  return this;
}


// ==== entry=00c2a140 orig=FUN_00c2a140 size=127 name=operator+ ====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* std::string std::TEMPNAMEPLACEHOLDERVALUE(char, std::string const&) */

string * std::operator+(char param_1,string *param_2)

{
  long lVar1;
  string *in_RDX;
  undefined7 in_register_00000039;
  string *this;
  long in_FS_OFFSET;
  
  this = (string *)CONCAT71(in_register_00000039,param_1);
  lVar1 = *(long *)(in_FS_OFFSET + 0x28);
  *(undefined1 **)this = &DAT_011c5338;
                    /* try { // try from 00c2a17b to 00c2a19b has its CatchHandler @ 00c2a1bf */
  string::reserve(this,*(long *)(*(long *)in_RDX + -0x18) + 1);
  string::s_basic_string__append_c29ec0(this,1,(char)param_2);
  string::append(this,in_RDX);
  if (lVar1 == *(long *)(in_FS_OFFSET + 0x28)) {
    return this;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ==== entry=00c2a1e0 orig=FUN_00c2a1e0 size=122 name=_S_construct<__gnu_cxx::__normal_iterator<char*,std::string>> ====

/* char* std::string::_S_construct<__gnu_cxx::__normal_iterator<char*, std::string >
   >(__gnu_cxx::__normal_iterator<char*, std::string >, __gnu_cxx::__normal_iterator<char*,
   std::string >, std::allocator<char> const&, std::forward_iterator_tag) */

char * std::string::_S_construct<__gnu_cxx::__normal_iterator<char*,std::string>>
                 (undefined1 *param_1,undefined1 *param_2,allocator *param_3)

{
  ulong *puVar1;
  ulong *__dest;
  ulong __n;
  
  if (param_2 != param_1) {
    __n = (long)param_2 - (long)param_1;
    puVar1 = (ulong *)_Rep::_S_create(__n,0,param_3);
    __dest = puVar1 + 3;
    if (__n == 1) {
      *(undefined1 *)(puVar1 + 3) = *param_1;
    }
    else {
      __dest = memcpy(__dest,param_1,__n);
    }
    if (puVar1 != &_Rep::_S_empty_rep_storage) {
      *(undefined4 *)(puVar1 + 2) = 0;
      *puVar1 = __n;
      *(undefined1 *)((long)puVar1 + __n + 0x18) = 0;
    }
    return (char *)__dest;
  }
  return &DAT_011c5338;
}


// ==== entry=00c2a270 orig=FUN_00c2a270 size=23 name=string<__gnu_cxx::__normal_iterator<char*,std::string>> ====

/* std::string::string<__gnu_cxx::__normal_iterator<char*, std::string >
   >(__gnu_cxx::__normal_iterator<char*, std::string >, __gnu_cxx::__normal_iterator<char*,
   std::string >, std::allocator<char> const&) */

void __thiscall
std::string::string<__gnu_cxx::__normal_iterator<char*,std::string>>
          (string *this,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  char *pcVar1;
  
  pcVar1 = _S_construct<__gnu_cxx::__normal_iterator<char*,std::string>>(param_2,param_3,param_4);
  *(char **)this = pcVar1;
  return;
}


// ==== entry=00c2a290 orig=FUN_00c2a290 size=60 name=s_basic_string__basic_string_c2a290 ====

void s_basic_string__basic_string_c2a290
               (undefined8 *param_1,long *param_2,ulong param_3,undefined8 param_4)

{
  long lVar1;
  ulong uVar2;
  char *pcVar3;
  
  lVar1 = *param_2;
  uVar2 = *(ulong *)(lVar1 + -0x18);
  if (param_3 <= uVar2) {
    pcVar3 = std::string::_S_construct<char*>(lVar1 + param_3,lVar1 + uVar2,param_4);
    *param_1 = pcVar3;
    return;
  }
                    /* WARNING: Subroutine does not return */
  std::__throw_out_of_range_fmt
            ("%s: __pos (which is %zu) > this->size() (which is %zu)","basic_string::basic_string",
             param_3,uVar2);
}


// ==== entry=00c2a2d0 orig=FUN_00c2a2d0 size=50 name=s_basic_string__substr_c2a2d0 ====

/* std::string::substr(unsigned long, unsigned long) const */

ulong std::string::s_basic_string__substr_c2a2d0(ulong param_1,ulong param_2)

{
  ulong in_RCX;
  ulong in_RDX;
  
  if (in_RDX <= *(ulong *)(*(long *)param_2 + -0x18)) {
    s_basic_string__basic_string_5fac8a((string *)param_1,(string *)param_2,in_RDX,in_RCX);
    return param_1;
  }
                    /* WARNING: Subroutine does not return */
  __throw_out_of_range_fmt
            ("%s: __pos (which is %zu) > this->size() (which is %zu)","basic_string::substr",in_RDX,
             *(ulong *)(*(long *)param_2 + -0x18));
}


// ==== entry=00c2a310 orig=FUN_00c2a310 size=75 name=s_basic_string__basic_string_c2a310 ====

/* std::string::string(std::string const&, unsigned long, unsigned long, std::allocator<char>
   const&) */

void __thiscall
std::string::s_basic_string__basic_string_c2a310
          (string *this,string *param_1,ulong param_2,ulong param_3,allocator *param_4)

{
  long lVar1;
  ulong uVar2;
  char *pcVar3;
  ulong uVar4;
  
  lVar1 = *(long *)param_1;
  uVar2 = *(ulong *)(lVar1 + -0x18);
  uVar4 = uVar2 - param_2;
  if (param_3 < uVar2 - param_2) {
    uVar4 = param_3;
  }
  if (param_2 <= uVar2) {
    pcVar3 = _S_construct<char*>(lVar1 + param_2,uVar4 + param_2 + lVar1,param_4);
    *(char **)this = pcVar3;
    return;
  }
                    /* WARNING: Subroutine does not return */
  __throw_out_of_range_fmt
            ("%s: __pos (which is %zu) > this->size() (which is %zu)","basic_string::basic_string",
             param_2,uVar2);
}


// ==== entry=00c2a360 orig=FUN_00c2a360 size=23 name=string<char*> ====

/* std::string::string<char*>(char*, char*, std::allocator<char> const&) */

void __thiscall
std::string::string<char*>(string *this,char *param_1,char *param_2,allocator *param_3)

{
  char *pcVar1;
  
  pcVar1 = _S_construct<char*>(param_1,param_2,param_3);
  *(char **)this = pcVar1;
  return;
}


// ==== entry=00c2a380 orig=FUN_00c2a380 size=26 name=string ====

/* std::string::string(char const*, unsigned long, std::allocator<char> const&) */

void __thiscall std::string::string(string *this,char *param_1,ulong param_2,allocator *param_3)

{
  char *pcVar1;
  
  pcVar1 = _S_construct<char_const*>(param_1,param_1 + param_2,param_3);
  *(char **)this = pcVar1;
  return;
}


// ==== entry=00c2a3a0 orig=FUN_00c2a3a0 size=12 name=replace ====

/* std::string::replace(unsigned long, unsigned long, std::string const&) */

void __thiscall std::string::replace(string *this,ulong param_1,ulong param_2,string *param_3)

{
  s_basic_string__replace_52baa6
            (this,param_1,param_2,*(char **)param_3,*(ulong *)(*(char **)param_3 + -0x18));
  return;
}


// ==== entry=00c2a3b0 orig=FUN_00c2a3b0 size=64 name=s_basic_string__replace_c2a3b0 ====

/* std::string::replace(unsigned long, unsigned long, std::string const&, unsigned long, unsigned
   long) */

void __thiscall
std::string::s_basic_string__replace_c2a3b0
          (string *this,ulong param_1,ulong param_2,string *param_3,ulong param_4,ulong param_5)

{
  ulong uVar1;
  ulong uVar2;
  
  uVar1 = *(ulong *)(*(long *)param_3 + -0x18);
  uVar2 = uVar1 - param_4;
  if (param_5 < uVar1 - param_4) {
    uVar2 = param_5;
  }
  if (param_4 <= uVar1) {
    s_basic_string__replace_52baa6(this,param_1,param_2,(char *)(*(long *)param_3 + param_4),uVar2);
    return;
  }
                    /* WARNING: Subroutine does not return */
  __throw_out_of_range_fmt
            ("%s: __pos (which is %zu) > this->size() (which is %zu)","basic_string::replace",
             param_4,uVar1,param_4,param_5,uVar2);
}


// ==== entry=00c2a3f0 orig=FUN_00c2a3f0 size=60 name=replace ====

/* std::string::replace(unsigned long, unsigned long, char const*) */

void __thiscall std::string::replace(string *this,ulong param_1,ulong param_2,char *param_3)

{
  size_t sVar1;
  
  sVar1 = strlen(param_3);
  s_basic_string__replace_52baa6(this,param_1,param_2,param_3,sVar1);
  return;
}


// ==== entry=00c2a430 orig=FUN_00c2a430 size=11 name=replace ====

/* std::string::replace(__gnu_cxx::__normal_iterator<char*, std::string >,
   __gnu_cxx::__normal_iterator<char*, std::string >, char const*, unsigned long) */

void __thiscall
std::string::replace(string *this,long param_2,long param_3,char *param_4,ulong param_5)

{
  s_basic_string__replace_52baa6(this,param_2 - *(long *)this,param_3 - param_2,param_4,param_5);
  return;
}


// ==== entry=00c2a440 orig=FUN_00c2a440 size=18 name=replace ====

/* std::string::replace(__gnu_cxx::__normal_iterator<char*, std::string >,
   __gnu_cxx::__normal_iterator<char*, std::string >, std::string const&) */

void __thiscall std::string::replace(string *this,long param_2,long param_3,undefined8 *param_4)

{
  s_basic_string__replace_52baa6
            (this,param_2 - *(long *)this,param_3 - param_2,(char *)*param_4,
             *(ulong *)((char *)*param_4 + -0x18));
  return;
}


// ==== entry=00c2a460 orig=FUN_00c2a460 size=67 name=replace ====

/* std::string::replace(__gnu_cxx::__normal_iterator<char*, std::string >,
   __gnu_cxx::__normal_iterator<char*, std::string >, char const*) */

void __thiscall std::string::replace(string *this,long param_2,long param_3,char *param_4)

{
  size_t sVar1;
  
  sVar1 = strlen(param_4);
  s_basic_string__replace_52baa6(this,param_2 - *(long *)this,param_3 - param_2,param_4,sVar1);
  return;
}


// ==== entry=00c2a4b0 orig=FUN_00c2a4b0 size=14 name=replace ====

/* std::string::replace(__gnu_cxx::__normal_iterator<char*, std::string >,
   __gnu_cxx::__normal_iterator<char*, std::string >, char*, char*) */

void __thiscall
std::string::replace(string *this,long param_2,long param_3,char *param_4,long param_5)

{
  s_basic_string__replace_52baa6
            (this,param_2 - *(long *)this,param_3 - param_2,param_4,param_5 - (long)param_4);
  return;
}


// ==== entry=00c2a4c0 orig=FUN_00c2a4c0 size=14 name=replace ====

/* std::string::replace(__gnu_cxx::__normal_iterator<char*, std::string >,
   __gnu_cxx::__normal_iterator<char*, std::string >, char const*, char const*) */

void __thiscall
std::string::replace(string *this,long param_2,long param_3,char *param_4,long param_5)

{
  s_basic_string__replace_52baa6
            (this,param_2 - *(long *)this,param_3 - param_2,param_4,param_5 - (long)param_4);
  return;
}


// ==== entry=00c2a4d0 orig=FUN_00c2a4d0 size=11 name=replace ====

/* std::string::replace(__gnu_cxx::__normal_iterator<char*, std::string >,
   __gnu_cxx::__normal_iterator<char*, std::string >, std::initializer_list<char>) */

void std::string::replace(string *param_1,long param_2,long param_3,char *param_4,ulong param_5)

{
  s_basic_string__replace_52baa6
            (param_1,param_2 - *(long *)param_1,param_3 - param_2,param_4,param_5);
  return;
}


// ==== entry=00c2a4e0 orig=FUN_00c2a4e0 size=14 name=replace ====

/* std::string::replace(__gnu_cxx::__normal_iterator<char*, std::string >,
   __gnu_cxx::__normal_iterator<char*, std::string >, __gnu_cxx::__normal_iterator<char*,
   std::string >, __gnu_cxx::__normal_iterator<char*, std::string >) */

void __thiscall
std::string::replace(string *this,long param_2,long param_3,char *param_4,long param_5)

{
  s_basic_string__replace_52baa6
            (this,param_2 - *(long *)this,param_3 - param_2,param_4,param_5 - (long)param_4);
  return;
}


// ==== entry=00c2a4f0 orig=FUN_00c2a4f0 size=14 name=replace ====

/* std::string::replace(__gnu_cxx::__normal_iterator<char*, std::string >,
   __gnu_cxx::__normal_iterator<char*, std::string >, __gnu_cxx::__normal_iterator<char const*,
   std::string >, __gnu_cxx::__normal_iterator<char const*, std::string >) */

void __thiscall
std::string::replace(string *this,long param_2,long param_3,char *param_4,long param_5)

{
  s_basic_string__replace_52baa6
            (this,param_2 - *(long *)this,param_3 - param_2,param_4,param_5 - (long)param_4);
  return;
}


// ==== entry=00c2a500 orig=FUN_00c2a500 size=26 name=string ====

/* std::string::string(std::initializer_list<char>, std::allocator<char> const&) */

void __thiscall std::string::string(string *this,long param_2,long param_3,undefined8 param_4)

{
  char *pcVar1;
  
  pcVar1 = _S_construct<char_const*>(param_2,param_3 + param_2,param_4);
  *(char **)this = pcVar1;
  return;
}


// ==== entry=00c2a520 orig=FUN_00c2a520 size=23 name=string<char_const*> ====

/* std::string::string<char const*>(char const*, char const*, std::allocator<char> const&) */

void __thiscall
std::string::string<char_const*>(string *this,char *param_1,char *param_2,allocator *param_3)

{
  char *pcVar1;
  
  pcVar1 = _S_construct<char_const*>(param_1,param_2,param_3);
  *(char **)this = pcVar1;
  return;
}


// ==== entry=00c2a540 name=FUN_00c2a540 size=10 ====

undefined8 FUN_00c2a540(long *param_1,long *param_2)

{
  return CONCAT71((int7)((ulong)*param_2 >> 8),*param_1 == *param_2);
}


// ==== entry=00c2a550 orig=FUN_00c2a550 size=164 name=_M_init ====

/* WARNING: Removing unreachable block (ram,0x00c2a5ec) */
/* WARNING: Removing unreachable block (ram,0x00c2a570) */
/* std::random_device::_M_init(std::string const&) */

FILE * __thiscall std::random_device::_M_init(random_device *this,string *param_1)

{
  int *piVar1;
  uint *puVar2;
  uint uVar3;
  int iVar4;
  FILE *pFVar5;
  char *__filename;
  
  __filename = *(char **)param_1;
  iVar4 = string::compare(param_1,"default");
  if (iVar4 == 0) {
    piVar1 = (int *)cpuid_basic_info(0);
    if ((piVar1[1] == 0x756e6547) && (*piVar1 != 0)) {
      __filename = "/dev/urandom";
      puVar2 = (uint *)cpuid_Version_info(1);
      uVar3 = *puVar2;
      if ((puVar2[3] & 0x40000000) != 0) {
        *(undefined8 *)this = 0;
        return (FILE *)(ulong)uVar3;
      }
    }
    else {
      __filename = "/dev/urandom";
    }
  }
  else {
    iVar4 = string::compare(param_1,"/dev/urandom");
    if ((iVar4 != 0) && (iVar4 = string::compare(param_1,"/dev/random"), iVar4 != 0))
    goto LAB_00c2a5ce;
  }
  pFVar5 = fopen(__filename,"rb");
  *(FILE **)this = pFVar5;
  if (pFVar5 != (FILE *)0x0) {
    return pFVar5;
  }
LAB_00c2a5ce:
                    /* WARNING: Subroutine does not return */
  __throw_runtime_error("random_device::random_device(const std::string&)");
}


// ==== entry=00c2a600 orig=FUN_00c2a600 size=190 name=_M_init_pretr1 ====

/* std::random_device::_M_init_pretr1(std::string const&) */

void __thiscall std::random_device::_M_init_pretr1(random_device *this,string *param_1)

{
  char *__nptr;
  int iVar1;
  ulong uVar2;
  long lVar3;
  long in_FS_OFFSET;
  char *local_28;
  long local_20;
  
  local_20 = *(long *)(in_FS_OFFSET + 0x28);
  iVar1 = string::compare(param_1,"mt19937");
  uVar2 = 0x1571;
  if (iVar1 != 0) {
    __nptr = *(char **)param_1;
    uVar2 = strtoul(__nptr,&local_28,0);
    if ((*__nptr == '\0') || (*local_28 != '\0')) {
                    /* WARNING: Subroutine does not return */
      __throw_runtime_error("random_device::random_device(const std::string&)");
    }
    uVar2 = uVar2 & 0xffffffff;
  }
  *(ulong *)this = uVar2;
  lVar3 = 1;
  while( true ) {
    *(ulong *)(this + lVar3 * 8) =
         (ulong)(((uint)(uVar2 >> 0x1e) ^ (uint)uVar2) * 0x6c078965 + (int)lVar3);
    lVar3 = lVar3 + 1;
    if (lVar3 == 0x270) break;
    uVar2 = *(ulong *)(this + lVar3 * 8 + -8);
  }
  *(undefined8 *)(this + 0x1380) = 0x270;
  if (local_20 == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ==== entry=00c2a6c0 orig=FUN_00c2a6c0 size=19 name=~ctype_byname ====

/* std::ctype_byname<char>::~ctype_byname() */

void __thiscall std::ctype_byname<char>::~ctype_byname(ctype_byname<char> *this)

{
  *(undefined ***)this = &PTR__ctype_byname_011b5148;
  ctype<char>::~ctype((ctype<char> *)this);
  return;
}


// ==== entry=00c2a6e0 orig=FUN_00c2a6e0 size=18 name=~ctype_byname ====

/* std::ctype_byname<char>::~ctype_byname() */

void __thiscall std::ctype_byname<char>::~ctype_byname(ctype_byname<char> *this)

{
  ~ctype_byname(this);
  operator_delete(this);
  return;
}


// ==== entry=00c2a700 orig=FUN_00c2a700 size=25 name=do_narrow ====

/* std::ctype<char>::do_narrow(char const*, char const*, char, char*) const */

char * __thiscall
std::ctype<char>::do_narrow
          (ctype<char> *this,char *param_1,char *param_2,char param_3,char *param_4)

{
  if (param_2 != param_1) {
    memcpy(param_4,param_1,(long)param_2 - (long)param_1);
  }
  return param_2;
}


// ==== entry=00c2a720 orig=FUN_00c2a720 size=151 name=ctype_byname ====

/* std::ctype_byname<char>::ctype_byname(char const*, unsigned long) */

void __thiscall
std::ctype_byname<char>::ctype_byname(ctype_byname<char> *this,char *param_1,ulong param_2)

{
  long lVar1;
  byte *pbVar2;
  byte *pbVar3;
  bool bVar4;
  bool bVar5;
  bool bVar6;
  byte bVar7;
  
  bVar7 = 0;
  ctype<char>::ctype((ctype<char> *)this,(ushort *)0x0,false,param_2);
  lVar1 = 2;
  bVar4 = false;
  bVar6 = false;
  *(undefined ***)this = &PTR__ctype_byname_011b5148;
  pbVar2 = (byte *)param_1;
  pbVar3 = &DAT_00ca9164;
  do {
    if (lVar1 == 0) break;
    lVar1 = lVar1 + -1;
    bVar4 = *pbVar2 < *pbVar3;
    bVar6 = *pbVar2 == *pbVar3;
    pbVar2 = pbVar2 + (ulong)bVar7 * -2 + 1;
    pbVar3 = pbVar3 + (ulong)bVar7 * -2 + 1;
  } while (bVar6);
  bVar5 = false;
  bVar4 = (!bVar4 && !bVar6) == bVar4;
  if (!bVar4) {
    lVar1 = 6;
    pbVar2 = (byte *)param_1;
    pbVar3 = (byte *)"POSIX";
    do {
      if (lVar1 == 0) break;
      lVar1 = lVar1 + -1;
      bVar5 = *pbVar2 < *pbVar3;
      bVar4 = *pbVar2 == *pbVar3;
      pbVar2 = pbVar2 + (ulong)bVar7 * -2 + 1;
      pbVar3 = pbVar3 + (ulong)bVar7 * -2 + 1;
    } while (bVar4);
    if ((!bVar5 && !bVar4) != bVar5) {
                    /* try { // try from 00c2a787 to 00c2a798 has its CatchHandler @ 00c2a7ba */
      locale::facet::_S_destroy_c_locale((__locale_struct **)(this + 0x10));
      locale::facet::_S_create_c_locale
                ((__locale_struct **)(this + 0x10),param_1,(__locale_struct *)0x0);
      lVar1 = *(long *)(this + 0x10);
      *(undefined8 *)(this + 0x20) = *(undefined8 *)(lVar1 + 0x78);
      *(undefined8 *)(this + 0x28) = *(undefined8 *)(lVar1 + 0x70);
      *(undefined8 *)(this + 0x30) = *(undefined8 *)(lVar1 + 0x68);
      return;
    }
  }
  return;
}


// ==== entry=00c2a7d0 orig=FUN_00c2a7d0 size=318 name=_M_convert_to_wmask ====

/* std::ctype<wchar_t>::_M_convert_to_wmask(unsigned short) const */

undefined8 __thiscall std::ctype<wchar_t>::_M_convert_to_wmask(ctype<wchar_t> *this,ushort param_1)

{
  undefined8 uVar1;
  
  if (param_1 == 0x400) {
    uVar1 = __wctype_l("alpha",*(undefined8 *)(this + 0x10));
    return uVar1;
  }
  if (param_1 < 0x401) {
    if (param_1 == 4) {
      uVar1 = __wctype_l("punct",*(undefined8 *)(this + 0x10));
      return uVar1;
    }
    if (param_1 < 5) {
      if (param_1 == 1) {
        uVar1 = __wctype_l("blank",*(undefined8 *)(this + 0x10));
        return uVar1;
      }
      if (param_1 == 2) {
        uVar1 = __wctype_l("cntrl",*(undefined8 *)(this + 0x10));
        return uVar1;
      }
    }
    else {
      if (param_1 == 0x100) {
        uVar1 = __wctype_l("upper",*(undefined8 *)(this + 0x10));
        return uVar1;
      }
      if (param_1 == 0x200) {
        uVar1 = __wctype_l("lower",*(undefined8 *)(this + 0x10));
        return uVar1;
      }
    }
  }
  else {
    if (param_1 == 0xc04) {
      uVar1 = __wctype_l("graph",*(undefined8 *)(this + 0x10));
      return uVar1;
    }
    if (param_1 < 0xc05) {
      if (param_1 == 0x800) {
        uVar1 = __wctype_l("digit",*(undefined8 *)(this + 0x10));
        return uVar1;
      }
      if (param_1 == 0xc00) {
        uVar1 = __wctype_l("alnum",*(undefined8 *)(this + 0x10));
        return uVar1;
      }
    }
    else {
      if (param_1 == 0x2000) {
        uVar1 = __wctype_l("space",*(undefined8 *)(this + 0x10));
        return uVar1;
      }
      if (param_1 == 0x4000) {
        uVar1 = __wctype_l("print",*(undefined8 *)(this + 0x10));
        return uVar1;
      }
      if (param_1 == 0x1000) {
        uVar1 = __wctype_l(&DAT_00cabb96,*(undefined8 *)(this + 0x10));
        return uVar1;
      }
    }
  }
  return 0;
}


// ==== entry=00c2a920 orig=FUN_00c2a920 size=13 name=do_toupper ====

/* std::ctype<wchar_t>::do_toupper(wchar_t) const */

void __thiscall std::ctype<wchar_t>::do_toupper(ctype<wchar_t> *this,wchar_t param_1)

{
  __towupper_l(param_1,*(undefined8 *)(this + 0x10));
  return;
}


// ==== entry=00c2a930 orig=FUN_00c2a930 size=85 name=do_toupper ====

/* std::ctype<wchar_t>::do_toupper(wchar_t*, wchar_t const*) const */

wchar_t * __thiscall
std::ctype<wchar_t>::do_toupper(ctype<wchar_t> *this,wchar_t *param_1,wchar_t *param_2)

{
  wchar_t wVar1;
  wchar_t *pwVar2;
  wchar_t *pwVar3;
  
  if (param_1 < param_2) {
    pwVar2 = param_1;
    do {
      pwVar3 = pwVar2 + 1;
      wVar1 = __towupper_l(*pwVar2,*(undefined8 *)(this + 0x10));
      *pwVar2 = wVar1;
      pwVar2 = pwVar3;
    } while (pwVar3 != (wchar_t *)
                       ((long)param_1 +
                       ((long)param_2 + (-1 - (long)param_1) & 0xfffffffffffffffcU) + 4));
  }
  return param_2;
}


// ==== entry=00c2a990 orig=FUN_00c2a990 size=13 name=do_tolower ====

/* std::ctype<wchar_t>::do_tolower(wchar_t) const */

void __thiscall std::ctype<wchar_t>::do_tolower(ctype<wchar_t> *this,wchar_t param_1)

{
  __towlower_l(param_1,*(undefined8 *)(this + 0x10));
  return;
}


// ==== entry=00c2a9a0 orig=FUN_00c2a9a0 size=85 name=do_tolower ====

/* std::ctype<wchar_t>::do_tolower(wchar_t*, wchar_t const*) const */

wchar_t * __thiscall
std::ctype<wchar_t>::do_tolower(ctype<wchar_t> *this,wchar_t *param_1,wchar_t *param_2)

{
  wchar_t wVar1;
  wchar_t *pwVar2;
  wchar_t *pwVar3;
  
  if (param_1 < param_2) {
    pwVar2 = param_1;
    do {
      pwVar3 = pwVar2 + 1;
      wVar1 = __towlower_l(*pwVar2,*(undefined8 *)(this + 0x10));
      *pwVar2 = wVar1;
      pwVar2 = pwVar3;
    } while (pwVar3 != (wchar_t *)
                       ((long)param_1 +
                       ((long)param_2 + (-1 - (long)param_1) & 0xfffffffffffffffcU) + 4));
  }
  return param_2;
}


// ==== entry=00c2aa00 orig=FUN_00c2aa00 size=151 name=do_is ====

/* std::ctype<wchar_t>::do_is(unsigned short, wchar_t) const */

bool __thiscall std::ctype<wchar_t>::do_is(ctype<wchar_t> *this,ushort param_1,wchar_t param_2)

{
  int iVar1;
  long lVar2;
  
  lVar2 = 0;
  if (*(ushort *)(this + 0x4a6) == param_1) {
    iVar1 = __iswctype_l(param_2,*(undefined8 *)(this + 0x4e8),*(undefined8 *)(this + 0x10));
    return iVar1 != 0;
  }
  do {
    if ((*(ushort *)(this + lVar2 * 2 + 0x49c) & param_1) != 0) {
      iVar1 = __iswctype_l(param_2,*(undefined8 *)(this + lVar2 * 8 + 0x4c0),
                           *(undefined8 *)(this + 0x10));
      if (iVar1 != 0) {
        return true;
      }
      if (*(ushort *)(this + lVar2 * 2 + 0x49c) == param_1) {
        return false;
      }
    }
    lVar2 = lVar2 + 1;
    if (lVar2 == 0xc) {
      return false;
    }
  } while( true );
}


// ==== entry=00c2aaa0 orig=FUN_00c2aaa0 size=145 name=do_is ====

/* std::ctype<wchar_t>::do_is(wchar_t const*, wchar_t const*, unsigned short*) const */

wchar_t * __thiscall
std::ctype<wchar_t>::do_is(ctype<wchar_t> *this,wchar_t *param_1,wchar_t *param_2,ushort *param_3)

{
  ushort *puVar1;
  int iVar2;
  long lVar3;
  ushort uVar4;
  
  if (param_1 < param_2) {
    puVar1 = param_3 + ((ulong)((long)param_2 + (-1 - (long)param_1)) >> 2) + 1;
    do {
      lVar3 = 0;
      uVar4 = 0;
      do {
        iVar2 = __iswctype_l(*param_1,*(undefined8 *)(this + lVar3 * 8 + 0x4c0),
                             *(undefined8 *)(this + 0x10));
        if (iVar2 != 0) {
          uVar4 = uVar4 | *(ushort *)(this + lVar3 * 2 + 0x49c);
        }
        lVar3 = lVar3 + 1;
      } while (lVar3 != 0xc);
      *param_3 = uVar4;
      param_3 = param_3 + 1;
      param_1 = param_1 + 1;
    } while (param_3 != puVar1);
  }
  return param_2;
}


// ==== entry=00c2ab40 orig=FUN_00c2ab40 size=77 name=do_scan_is ====

/* std::ctype<wchar_t>::do_scan_is(unsigned short, wchar_t const*, wchar_t const*) const */

wchar_t * __thiscall
std::ctype<wchar_t>::do_scan_is
          (ctype<wchar_t> *this,ushort param_1,wchar_t *param_2,wchar_t *param_3)

{
  char cVar1;
  
  while ((param_2 < param_3 &&
         (cVar1 = (**(code **)(*(long *)this + 0x10))(this,param_1,*param_2), cVar1 == '\0'))) {
    param_2 = param_2 + 1;
  }
  return param_2;
}


// ==== entry=00c2ab90 orig=FUN_00c2ab90 size=77 name=do_scan_not ====

/* std::ctype<wchar_t>::do_scan_not(unsigned short, wchar_t const*, wchar_t const*) const */

wchar_t * __thiscall
std::ctype<wchar_t>::do_scan_not
          (ctype<wchar_t> *this,ushort param_1,wchar_t *param_2,wchar_t *param_3)

{
  char cVar1;
  
  while ((param_2 < param_3 &&
         (cVar1 = (**(code **)(*(long *)this + 0x10))(this,param_1,*param_2), cVar1 != '\0'))) {
    param_2 = param_2 + 1;
  }
  return param_2;
}


// ==== entry=00c2abe0 orig=FUN_00c2abe0 size=12 name=do_widen ====

/* std::ctype<wchar_t>::do_widen(char) const */

undefined4 __thiscall std::ctype<wchar_t>::do_widen(ctype<wchar_t> *this,char param_1)

{
  return *(undefined4 *)(this + (ulong)(byte)param_1 * 4 + 0x9c);
}


// ==== entry=00c2abf0 orig=FUN_00c2abf0 size=51 name=do_widen ====

/* std::ctype<wchar_t>::do_widen(char const*, char const*, wchar_t*) const */

char * __thiscall
std::ctype<wchar_t>::do_widen(ctype<wchar_t> *this,char *param_1,char *param_2,wchar_t *param_3)

{
  long lVar1;
  
  if (param_1 < param_2) {
    lVar1 = 0;
    do {
      param_3[lVar1] = *(wchar_t *)(this + (ulong)(byte)param_1[lVar1] * 4 + 0x9c);
      lVar1 = lVar1 + 1;
    } while ((long)param_2 - (long)param_1 != lVar1);
  }
  return param_2;
}


// ==== entry=00c2ac30 orig=FUN_00c2ac30 size=70 name=do_narrow ====

/* std::ctype<wchar_t>::do_narrow(wchar_t, char) const */

uint __thiscall std::ctype<wchar_t>::do_narrow(ctype<wchar_t> *this,wchar_t param_1,char param_2)

{
  uint uVar1;
  uint uVar2;
  undefined8 uVar3;
  undefined3 in_register_00000011;
  
  if (((uint)param_1 < 0x80) && (this[0x18] != (ctype<wchar_t>)0x0)) {
    return (uint)(byte)this[(long)param_1 + 0x19];
  }
  uVar3 = __uselocale(*(undefined8 *)(this + 0x10));
                    /* try { // try from 00c2ac51 to 00c2ac55 has its CatchHandler @ 00c2ac79 */
  uVar2 = wctob(param_1);
  __uselocale(uVar3);
  uVar1 = CONCAT31(in_register_00000011,param_2);
  if (uVar2 != 0xffffffff) {
    uVar1 = uVar2;
  }
  return uVar1;
}


// ==== entry=00c2ac90 orig=FUN_00c2ac90 size=217 name=do_narrow ====

/* std::ctype<wchar_t>::do_narrow(wchar_t const*, wchar_t const*, char, char*) const */

wchar_t * __thiscall
std::ctype<wchar_t>::do_narrow
          (ctype<wchar_t> *this,wchar_t *param_1,wchar_t *param_2,char param_3,char *param_4)

{
  wchar_t __c;
  long lVar1;
  uint uVar2;
  undefined8 uVar3;
  ctype<wchar_t> *pcVar4;
  ctype<wchar_t> *pcVar5;
  char *pcVar6;
  char *pcVar7;
  
  uVar3 = __uselocale(*(undefined8 *)(this + 0x10));
  if (this[0x18] == (ctype<wchar_t>)0x0) {
    if (param_1 < param_2) {
      lVar1 = -1 - (long)param_1;
      pcVar6 = param_4;
      do {
                    /* try { // try from 00c2ad5b to 00c2ad5f has its CatchHandler @ 00c2ad79 */
        uVar2 = wctob(*param_1);
        if (uVar2 == 0xffffffff) {
          uVar2 = (uint)(byte)param_3;
        }
        pcVar7 = pcVar6 + 1;
        param_1 = param_1 + 1;
        *pcVar6 = (char)uVar2;
        pcVar6 = pcVar7;
      } while (param_4 + ((ulong)((long)param_2 + lVar1) >> 2) + 1 != pcVar7);
    }
  }
  else if (param_1 < param_2) {
    lVar1 = -1 - (long)param_1;
    pcVar4 = (ctype<wchar_t> *)param_4;
    do {
      while( true ) {
        __c = *param_1;
        if ((uint)__c < 0x80) break;
                    /* try { // try from 00c2acff to 00c2ad03 has its CatchHandler @ 00c2ad81 */
        uVar2 = wctob(__c);
        if (uVar2 == 0xffffffff) {
          uVar2 = (uint)(byte)param_3;
        }
        pcVar5 = pcVar4 + 1;
        param_1 = param_1 + 1;
        *pcVar4 = SUB41(uVar2,0);
        pcVar4 = pcVar5;
        if (pcVar5 == (ctype<wchar_t> *)(param_4 + ((ulong)((long)param_2 + lVar1) >> 2) + 1))
        goto LAB_00c2ad1b;
      }
      pcVar5 = pcVar4 + 1;
      param_1 = param_1 + 1;
      *pcVar4 = this[(long)__c + 0x19];
      pcVar4 = pcVar5;
    } while (pcVar5 != (ctype<wchar_t> *)(param_4 + ((ulong)((long)param_2 + lVar1) >> 2) + 1));
  }
LAB_00c2ad1b:
  __uselocale(uVar3);
  return param_2;
}


// ==== entry=00c2ad90 orig=FUN_00c2ad90 size=223 name=_M_initialize_ctype ====

/* std::ctype<wchar_t>::_M_initialize_ctype() */

void __thiscall std::ctype<wchar_t>::_M_initialize_ctype(ctype<wchar_t> *this)

{
  undefined8 uVar1;
  undefined8 uVar2;
  int iVar3;
  wint_t wVar4;
  long lVar5;
  ushort uVar6;
  ulong uVar7;
  
  lVar5 = 0;
  uVar1 = __uselocale(*(undefined8 *)(this + 0x10));
  do {
                    /* try { // try from 00c2adc7 to 00c2adcb has its CatchHandler @ 00c2ae75 */
    iVar3 = wctob((wint_t)lVar5);
    if (iVar3 == -1) {
      this[0x18] = (ctype<wchar_t>)0x0;
      goto LAB_00c2add5;
    }
    this[lVar5 + 0x19] = SUB41(iVar3,0);
    lVar5 = lVar5 + 1;
  } while (lVar5 != 0x80);
  this[0x18] = (ctype<wchar_t>)0x1;
LAB_00c2add5:
  lVar5 = 0;
  do {
                    /* try { // try from 00c2ade2 to 00c2ade6 has its CatchHandler @ 00c2ae7d */
    wVar4 = btowc((int)lVar5);
    *(wint_t *)(this + lVar5 * 4 + 0x9c) = wVar4;
    lVar5 = lVar5 + 1;
  } while (lVar5 != 0x100);
  uVar7 = 0;
  do {
    iVar3 = 1 << ((byte)uVar7 & 0x1f);
    if (uVar7 < 8) {
      uVar6 = (ushort)(iVar3 << 8);
      *(ushort *)(this + uVar7 * 2 + 0x49c) = uVar6;
      uVar2 = _M_convert_to_wmask(this,uVar6);
      *(undefined8 *)(this + uVar7 * 8 + 0x4c0) = uVar2;
    }
    else {
      uVar6 = (ushort)((uint)iVar3 >> 8);
      *(ushort *)(this + uVar7 * 2 + 0x49c) = uVar6;
      uVar2 = _M_convert_to_wmask(this,uVar6);
      *(undefined8 *)(this + uVar7 * 8 + 0x4c0) = uVar2;
      if (uVar7 == 0xb) {
        __uselocale(uVar1);
        return;
      }
    }
    uVar7 = uVar7 + 1;
  } while( true );
}


// ==== entry=00c2ae90 orig=FUN_00c2ae90 size=9 name=do_decimal_point ====

/* std::moneypunct<char, false>::do_decimal_point() const */

undefined1 __thiscall std::moneypunct<char,false>::do_decimal_point(moneypunct<char,false> *this)

{
  return *(undefined1 *)(*(long *)(this + 0x10) + 0x21);
}


// ==== entry=00c2aea0 orig=FUN_00c2aea0 size=9 name=do_thousands_sep ====

/* std::moneypunct<char, false>::do_thousands_sep() const */

undefined1 __thiscall std::moneypunct<char,false>::do_thousands_sep(moneypunct<char,false> *this)

{
  return *(undefined1 *)(*(long *)(this + 0x10) + 0x22);
}


// ==== entry=00c2aeb0 orig=FUN_00c2aeb0 size=8 name=do_frac_digits ====

/* std::moneypunct<char, false>::do_frac_digits() const */

undefined4 __thiscall std::moneypunct<char,false>::do_frac_digits(moneypunct<char,false> *this)

{
  return *(undefined4 *)(*(long *)(this + 0x10) + 0x58);
}


// ==== entry=00c2aec0 orig=FUN_00c2aec0 size=53 name=do_pos_format ====

/* std::moneypunct<char, false>::do_pos_format() const */

undefined4 __thiscall std::moneypunct<char,false>::do_pos_format(moneypunct<char,false> *this)

{
  long in_FS_OFFSET;
  
  if (*(long *)(in_FS_OFFSET + 0x28) == *(long *)(in_FS_OFFSET + 0x28)) {
    return *(undefined4 *)(*(long *)(this + 0x10) + 0x5c);
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ==== entry=00c2af00 orig=FUN_00c2af00 size=53 name=do_neg_format ====

/* std::moneypunct<char, false>::do_neg_format() const */

undefined4 __thiscall std::moneypunct<char,false>::do_neg_format(moneypunct<char,false> *this)

{
  long in_FS_OFFSET;
  
  if (*(long *)(in_FS_OFFSET + 0x28) == *(long *)(in_FS_OFFSET + 0x28)) {
    return *(undefined4 *)(*(long *)(this + 0x10) + 0x60);
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ==== entry=00c2af40 orig=FUN_00c2af40 size=9 name=do_decimal_point ====

/* std::moneypunct<char, true>::do_decimal_point() const */

undefined1 __thiscall std::moneypunct<char,true>::do_decimal_point(moneypunct<char,true> *this)

{
  return *(undefined1 *)(*(long *)(this + 0x10) + 0x21);
}


// ==== entry=00c2af50 orig=FUN_00c2af50 size=9 name=do_thousands_sep ====

/* std::moneypunct<char, true>::do_thousands_sep() const */

undefined1 __thiscall std::moneypunct<char,true>::do_thousands_sep(moneypunct<char,true> *this)

{
  return *(undefined1 *)(*(long *)(this + 0x10) + 0x22);
}


// ==== entry=00c2af60 orig=FUN_00c2af60 size=8 name=do_frac_digits ====

/* std::moneypunct<char, true>::do_frac_digits() const */

undefined4 __thiscall std::moneypunct<char,true>::do_frac_digits(moneypunct<char,true> *this)

{
  return *(undefined4 *)(*(long *)(this + 0x10) + 0x58);
}


// ==== entry=00c2af70 orig=FUN_00c2af70 size=53 name=do_pos_format ====

/* std::moneypunct<char, true>::do_pos_format() const */

undefined4 __thiscall std::moneypunct<char,true>::do_pos_format(moneypunct<char,true> *this)

{
  long in_FS_OFFSET;
  
  if (*(long *)(in_FS_OFFSET + 0x28) == *(long *)(in_FS_OFFSET + 0x28)) {
    return *(undefined4 *)(*(long *)(this + 0x10) + 0x5c);
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ==== entry=00c2afb0 orig=FUN_00c2afb0 size=53 name=do_neg_format ====

/* std::moneypunct<char, true>::do_neg_format() const */

undefined4 __thiscall std::moneypunct<char,true>::do_neg_format(moneypunct<char,true> *this)

{
  long in_FS_OFFSET;
  
  if (*(long *)(in_FS_OFFSET + 0x28) == *(long *)(in_FS_OFFSET + 0x28)) {
    return *(undefined4 *)(*(long *)(this + 0x10) + 0x60);
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ==== entry=00c2aff0 orig=FUN_00c2aff0 size=19 name=~moneypunct_byname ====

/* std::moneypunct_byname<char, false>::~moneypunct_byname() */

void __thiscall
std::moneypunct_byname<char,false>::~moneypunct_byname(moneypunct_byname<char,false> *this)

{
  *(undefined ***)this = &PTR__moneypunct_byname_011b5870;
  moneypunct<char,false>::~moneypunct((moneypunct<char,false> *)this);
  return;
}


// ==== entry=00c2b010 orig=FUN_00c2b010 size=19 name=~moneypunct_byname ====

/* std::moneypunct_byname<char, true>::~moneypunct_byname() */

void __thiscall
std::moneypunct_byname<char,true>::~moneypunct_byname(moneypunct_byname<char,true> *this)

{
  *(undefined ***)this = &PTR__moneypunct_byname_011b58d8;
  moneypunct<char,true>::~moneypunct((moneypunct<char,true> *)this);
  return;
}


// ==== entry=00c2b030 orig=FUN_00c2b030 size=9 name=do_decimal_point ====

/* std::numpunct<char>::do_decimal_point() const */

undefined1 __thiscall std::numpunct<char>::do_decimal_point(numpunct<char> *this)

{
  return *(undefined1 *)(*(long *)(this + 0x10) + 0x48);
}


// ==== entry=00c2b040 orig=FUN_00c2b040 size=9 name=do_thousands_sep ====

/* std::numpunct<char>::do_thousands_sep() const */

undefined1 __thiscall std::numpunct<char>::do_thousands_sep(numpunct<char> *this)

{
  return *(undefined1 *)(*(long *)(this + 0x10) + 0x49);
}


// ==== entry=00c2b050 orig=FUN_00c2b050 size=19 name=~numpunct_byname ====

/* std::numpunct_byname<char>::~numpunct_byname() */

void __thiscall std::numpunct_byname<char>::~numpunct_byname(numpunct_byname<char> *this)

{
  *(undefined ***)this = &PTR__numpunct_byname_011b5558;
  numpunct<char>::~numpunct((numpunct<char> *)this);
  return;
}


// ==== entry=00c2b070 orig=FUN_00c2b070 size=3 name=do_date_order ====

/* std::time_get<char, std::istreambuf_iterator<char, std::char_traits<char> > >::do_date_order()
   const */

undefined8
std::time_get<char,std::istreambuf_iterator<char,std::char_traits<char>>>::do_date_order(void)

{
  return 0;
}


// ==== entry=00c2b080 orig=FUN_00c2b080 size=38 name=do_hash ====

/* std::collate<char>::do_hash(char const*, char const*) const */

ulong __thiscall std::collate<char>::do_hash(collate<char> *this,char *param_1,char *param_2)

{
  char cVar1;
  ulong uVar2;
  
  uVar2 = 0;
  if (param_2 <= param_1) {
    return 0;
  }
  do {
    cVar1 = *param_1;
    param_1 = param_1 + 1;
    uVar2 = (uVar2 << 7 | uVar2 >> 0x39) + (long)cVar1;
  } while (param_2 != param_1);
  return uVar2;
}


// ==== entry=00c2b0b0 orig=FUN_00c2b0b0 size=19 name=~money_get ====

/* std::money_get<char, std::istreambuf_iterator<char, std::char_traits<char> > >::~money_get() */

void __thiscall
std::money_get<char,std::istreambuf_iterator<char,std::char_traits<char>>>::~money_get
          (money_get<char,std::istreambuf_iterator<char,std::char_traits<char>>> *this)

{
  *(undefined ***)this = &PTR__money_get_011b5940;
  locale::facet::~facet((facet *)this);
  return;
}


// ==== entry=00c2b0d0 orig=FUN_00c2b0d0 size=19 name=~money_put ====

/* std::money_put<char, std::ostreambuf_iterator<char, std::char_traits<char> > >::~money_put() */

void __thiscall
std::money_put<char,std::ostreambuf_iterator<char,std::char_traits<char>>>::~money_put
          (money_put<char,std::ostreambuf_iterator<char,std::char_traits<char>>> *this)

{
  *(undefined ***)this = &PTR__money_put_011b5970;
  locale::facet::~facet((facet *)this);
  return;
}


// ==== entry=00c2b0f0 orig=FUN_00c2b0f0 size=19 name=~num_get ====

/* std::num_get<char, std::istreambuf_iterator<char, std::char_traits<char> > >::~num_get() */

void __thiscall
std::num_get<char,std::istreambuf_iterator<char,std::char_traits<char>>>::~num_get
          (num_get<char,std::istreambuf_iterator<char,std::char_traits<char>>> *this)

{
  *(undefined ***)this = &PTR__num_get_011b55a0;
  locale::facet::~facet((facet *)this);
  return;
}


// ==== entry=00c2b110 orig=FUN_00c2b110 size=19 name=~num_put ====

/* std::num_put<char, std::ostreambuf_iterator<char, std::char_traits<char> > >::~num_put() */

void __thiscall
std::num_put<char,std::ostreambuf_iterator<char,std::char_traits<char>>>::~num_put
          (num_put<char,std::ostreambuf_iterator<char,std::char_traits<char>>> *this)

{
  *(undefined ***)this = &PTR__num_put_011b5618;
  locale::facet::~facet((facet *)this);
  return;
}


// ==== entry=00c2b130 orig=FUN_00c2b130 size=19 name=~__timepunct_cache ====

/* std::__timepunct_cache<char>::~__timepunct_cache() */

void __thiscall std::__timepunct_cache<char>::~__timepunct_cache(__timepunct_cache<char> *this)

{
  *(undefined ***)this = &PTR____timepunct_cache_011b5678;
  locale::facet::~facet((facet *)this);
  return;
}


// ==== entry=00c2b150 orig=FUN_00c2b150 size=19 name=~time_put ====

/* std::time_put<char, std::ostreambuf_iterator<char, std::char_traits<char> > >::~time_put() */

void __thiscall
std::time_put<char,std::ostreambuf_iterator<char,std::char_traits<char>>>::~time_put
          (time_put<char,std::ostreambuf_iterator<char,std::char_traits<char>>> *this)

{
  *(undefined ***)this = &PTR__time_put_011b59a0;
  locale::facet::~facet((facet *)this);
  return;
}


// ==== entry=00c2b170 orig=FUN_00c2b170 size=19 name=~time_put_byname ====

/* std::time_put_byname<char, std::ostreambuf_iterator<char, std::char_traits<char> >
   >::~time_put_byname() */

void __thiscall
std::time_put_byname<char,std::ostreambuf_iterator<char,std::char_traits<char>>>::~time_put_byname
          (time_put_byname<char,std::ostreambuf_iterator<char,std::char_traits<char>>> *this)

{
  *(undefined ***)this = &PTR__time_put_011b59a0;
  locale::facet::~facet((facet *)this);
  return;
}


// ==== entry=00c2b190 orig=FUN_00c2b190 size=19 name=~time_get ====

/* std::time_get<char, std::istreambuf_iterator<char, std::char_traits<char> > >::~time_get() */

void __thiscall
std::time_get<char,std::istreambuf_iterator<char,std::char_traits<char>>>::~time_get
          (time_get<char,std::istreambuf_iterator<char,std::char_traits<char>>> *this)

{
  *(undefined ***)this = &PTR__time_get_011b59f0;
  locale::facet::~facet((facet *)this);
  return;
}


// ==== entry=00c2b1b0 orig=FUN_00c2b1b0 size=19 name=~time_get_byname ====

/* std::time_get_byname<char, std::istreambuf_iterator<char, std::char_traits<char> >
   >::~time_get_byname() */

void __thiscall
std::time_get_byname<char,std::istreambuf_iterator<char,std::char_traits<char>>>::~time_get_byname
          (time_get_byname<char,std::istreambuf_iterator<char,std::char_traits<char>>> *this)

{
  *(undefined ***)this = &PTR__time_get_011b59f0;
  locale::facet::~facet((facet *)this);
  return;
}


// ==== entry=00c2b1d0 orig=FUN_00c2b1d0 size=32 name=~moneypunct_byname ====

/* std::moneypunct_byname<char, false>::~moneypunct_byname() */

void __thiscall
std::moneypunct_byname<char,false>::~moneypunct_byname(moneypunct_byname<char,false> *this)

{
  *(undefined ***)this = &PTR__moneypunct_byname_011b5870;
  moneypunct<char,false>::~moneypunct((moneypunct<char,false> *)this);
  operator_delete(this);
  return;
}


// ==== entry=00c2b1f0 orig=FUN_00c2b1f0 size=32 name=~moneypunct_byname ====

/* std::moneypunct_byname<char, true>::~moneypunct_byname() */

void __thiscall
std::moneypunct_byname<char,true>::~moneypunct_byname(moneypunct_byname<char,true> *this)

{
  *(undefined ***)this = &PTR__moneypunct_byname_011b58d8;
  moneypunct<char,true>::~moneypunct((moneypunct<char,true> *)this);
  operator_delete(this);
  return;
}


// ==== entry=00c2b210 orig=FUN_00c2b210 size=32 name=~money_get ====

/* std::money_get<char, std::istreambuf_iterator<char, std::char_traits<char> > >::~money_get() */

void __thiscall
std::money_get<char,std::istreambuf_iterator<char,std::char_traits<char>>>::~money_get
          (money_get<char,std::istreambuf_iterator<char,std::char_traits<char>>> *this)

{
  *(undefined ***)this = &PTR__money_get_011b5940;
  locale::facet::~facet((facet *)this);
  operator_delete(this);
  return;
}


// ==== entry=00c2b230 orig=FUN_00c2b230 size=32 name=~money_put ====

/* std::money_put<char, std::ostreambuf_iterator<char, std::char_traits<char> > >::~money_put() */

void __thiscall
std::money_put<char,std::ostreambuf_iterator<char,std::char_traits<char>>>::~money_put
          (money_put<char,std::ostreambuf_iterator<char,std::char_traits<char>>> *this)

{
  *(undefined ***)this = &PTR__money_put_011b5970;
  locale::facet::~facet((facet *)this);
  operator_delete(this);
  return;
}


// ==== entry=00c2b250 orig=FUN_00c2b250 size=32 name=~numpunct_byname ====

/* std::numpunct_byname<char>::~numpunct_byname() */

void __thiscall std::numpunct_byname<char>::~numpunct_byname(numpunct_byname<char> *this)

{
  *(undefined ***)this = &PTR__numpunct_byname_011b5558;
  numpunct<char>::~numpunct((numpunct<char> *)this);
  operator_delete(this);
  return;
}


// ==== entry=00c2b270 orig=FUN_00c2b270 size=32 name=~num_get ====

/* std::num_get<char, std::istreambuf_iterator<char, std::char_traits<char> > >::~num_get() */

void __thiscall
std::num_get<char,std::istreambuf_iterator<char,std::char_traits<char>>>::~num_get
          (num_get<char,std::istreambuf_iterator<char,std::char_traits<char>>> *this)

{
  *(undefined ***)this = &PTR__num_get_011b55a0;
  locale::facet::~facet((facet *)this);
  operator_delete(this);
  return;
}


// ==== entry=00c2b290 orig=FUN_00c2b290 size=32 name=~num_put ====

/* std::num_put<char, std::ostreambuf_iterator<char, std::char_traits<char> > >::~num_put() */

void __thiscall
std::num_put<char,std::ostreambuf_iterator<char,std::char_traits<char>>>::~num_put
          (num_put<char,std::ostreambuf_iterator<char,std::char_traits<char>>> *this)

{
  *(undefined ***)this = &PTR__num_put_011b5618;
  locale::facet::~facet((facet *)this);
  operator_delete(this);
  return;
}


// ==== entry=00c2b2b0 orig=FUN_00c2b2b0 size=18 name=~__timepunct_cache ====

/* std::__timepunct_cache<char>::~__timepunct_cache() */

void __thiscall std::__timepunct_cache<char>::~__timepunct_cache(__timepunct_cache<char> *this)

{
  ~__timepunct_cache(this);
  operator_delete(this);
  return;
}


// ==== entry=00c2b2d0 orig=FUN_00c2b2d0 size=32 name=~time_put ====

/* std::time_put<char, std::ostreambuf_iterator<char, std::char_traits<char> > >::~time_put() */

void __thiscall
std::time_put<char,std::ostreambuf_iterator<char,std::char_traits<char>>>::~time_put
          (time_put<char,std::ostreambuf_iterator<char,std::char_traits<char>>> *this)

{
  *(undefined ***)this = &PTR__time_put_011b59a0;
  locale::facet::~facet((facet *)this);
  operator_delete(this);
  return;
}


// ==== entry=00c2b2f0 orig=FUN_00c2b2f0 size=32 name=~time_put_byname ====

/* std::time_put_byname<char, std::ostreambuf_iterator<char, std::char_traits<char> >
   >::~time_put_byname() */

void __thiscall
std::time_put_byname<char,std::ostreambuf_iterator<char,std::char_traits<char>>>::~time_put_byname
          (time_put_byname<char,std::ostreambuf_iterator<char,std::char_traits<char>>> *this)

{
  *(undefined ***)this = &PTR__time_put_011b59a0;
  locale::facet::~facet((facet *)this);
  operator_delete(this);
  return;
}


// ==== entry=00c2b310 orig=FUN_00c2b310 size=32 name=~time_get ====

/* std::time_get<char, std::istreambuf_iterator<char, std::char_traits<char> > >::~time_get() */

void __thiscall
std::time_get<char,std::istreambuf_iterator<char,std::char_traits<char>>>::~time_get
          (time_get<char,std::istreambuf_iterator<char,std::char_traits<char>>> *this)

{
  *(undefined ***)this = &PTR__time_get_011b59f0;
  locale::facet::~facet((facet *)this);
  operator_delete(this);
  return;
}


// ==== entry=00c2b330 orig=FUN_00c2b330 size=32 name=~time_get_byname ====

/* std::time_get_byname<char, std::istreambuf_iterator<char, std::char_traits<char> >
   >::~time_get_byname() */

void __thiscall
std::time_get_byname<char,std::istreambuf_iterator<char,std::char_traits<char>>>::~time_get_byname
          (time_get_byname<char,std::istreambuf_iterator<char,std::char_traits<char>>> *this)

{
  *(undefined ***)this = &PTR__time_get_011b59f0;
  locale::facet::~facet((facet *)this);
  operator_delete(this);
  return;
}


// ==== entry=00c2b350 orig=FUN_00c2b350 size=72 name=do_grouping ====

/* std::moneypunct<char, false>::do_grouping() const */

void std::moneypunct<char,false>::do_grouping(void)

{
  long in_RSI;
  string *in_RDI;
  long in_FS_OFFSET;
  allocator local_11;
  long local_10;
  
  local_10 = *(long *)(in_FS_OFFSET + 0x28);
  string::string(in_RDI,*(char **)(*(long *)(in_RSI + 0x10) + 0x10),&local_11);
  if (local_10 == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ==== entry=00c2b3a0 orig=FUN_00c2b3a0 size=72 name=do_curr_symbol ====

/* std::moneypunct<char, false>::do_curr_symbol() const */

void std::moneypunct<char,false>::do_curr_symbol(void)

{
  long in_RSI;
  string *in_RDI;
  long in_FS_OFFSET;
  allocator local_11;
  long local_10;
  
  local_10 = *(long *)(in_FS_OFFSET + 0x28);
  string::string(in_RDI,*(char **)(*(long *)(in_RSI + 0x10) + 0x28),&local_11);
  if (local_10 == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ==== entry=00c2b3f0 orig=FUN_00c2b3f0 size=72 name=do_positive_sign ====

/* std::moneypunct<char, false>::do_positive_sign() const */

void std::moneypunct<char,false>::do_positive_sign(void)

{
  long in_RSI;
  string *in_RDI;
  long in_FS_OFFSET;
  allocator local_11;
  long local_10;
  
  local_10 = *(long *)(in_FS_OFFSET + 0x28);
  string::string(in_RDI,*(char **)(*(long *)(in_RSI + 0x10) + 0x38),&local_11);
  if (local_10 == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ==== entry=00c2b440 orig=FUN_00c2b440 size=72 name=do_negative_sign ====

/* std::moneypunct<char, false>::do_negative_sign() const */

void std::moneypunct<char,false>::do_negative_sign(void)

{
  long in_RSI;
  string *in_RDI;
  long in_FS_OFFSET;
  allocator local_11;
  long local_10;
  
  local_10 = *(long *)(in_FS_OFFSET + 0x28);
  string::string(in_RDI,*(char **)(*(long *)(in_RSI + 0x10) + 0x48),&local_11);
  if (local_10 == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ==== entry=00c2b490 orig=FUN_00c2b490 size=72 name=do_grouping ====

/* std::moneypunct<char, true>::do_grouping() const */

void std::moneypunct<char,true>::do_grouping(void)

{
  long in_RSI;
  string *in_RDI;
  long in_FS_OFFSET;
  allocator local_11;
  long local_10;
  
  local_10 = *(long *)(in_FS_OFFSET + 0x28);
  string::string(in_RDI,*(char **)(*(long *)(in_RSI + 0x10) + 0x10),&local_11);
  if (local_10 == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ==== entry=00c2b4e0 orig=FUN_00c2b4e0 size=72 name=do_curr_symbol ====

/* std::moneypunct<char, true>::do_curr_symbol() const */

void std::moneypunct<char,true>::do_curr_symbol(void)

{
  long in_RSI;
  string *in_RDI;
  long in_FS_OFFSET;
  allocator local_11;
  long local_10;
  
  local_10 = *(long *)(in_FS_OFFSET + 0x28);
  string::string(in_RDI,*(char **)(*(long *)(in_RSI + 0x10) + 0x28),&local_11);
  if (local_10 == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ==== entry=00c2b530 orig=FUN_00c2b530 size=72 name=do_positive_sign ====

/* std::moneypunct<char, true>::do_positive_sign() const */

void std::moneypunct<char,true>::do_positive_sign(void)

{
  long in_RSI;
  string *in_RDI;
  long in_FS_OFFSET;
  allocator local_11;
  long local_10;
  
  local_10 = *(long *)(in_FS_OFFSET + 0x28);
  string::string(in_RDI,*(char **)(*(long *)(in_RSI + 0x10) + 0x38),&local_11);
  if (local_10 == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ==== entry=00c2b580 orig=FUN_00c2b580 size=72 name=do_negative_sign ====

/* std::moneypunct<char, true>::do_negative_sign() const */

void std::moneypunct<char,true>::do_negative_sign(void)

{
  long in_RSI;
  string *in_RDI;
  long in_FS_OFFSET;
  allocator local_11;
  long local_10;
  
  local_10 = *(long *)(in_FS_OFFSET + 0x28);
  string::string(in_RDI,*(char **)(*(long *)(in_RSI + 0x10) + 0x48),&local_11);
  if (local_10 == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ==== entry=00c2b5d0 orig=FUN_00c2b5d0 size=72 name=do_grouping ====

/* std::numpunct<char>::do_grouping() const */

void std::numpunct<char>::do_grouping(void)

{
  long in_RSI;
  string *in_RDI;
  long in_FS_OFFSET;
  allocator local_11;
  long local_10;
  
  local_10 = *(long *)(in_FS_OFFSET + 0x28);
  string::string(in_RDI,*(char **)(*(long *)(in_RSI + 0x10) + 0x10),&local_11);
  if (local_10 == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ==== entry=00c2b620 orig=FUN_00c2b620 size=72 name=do_truename ====

/* std::numpunct<char>::do_truename() const */

void std::numpunct<char>::do_truename(void)

{
  long in_RSI;
  string *in_RDI;
  long in_FS_OFFSET;
  allocator local_11;
  long local_10;
  
  local_10 = *(long *)(in_FS_OFFSET + 0x28);
  string::string(in_RDI,*(char **)(*(long *)(in_RSI + 0x10) + 0x28),&local_11);
  if (local_10 == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ==== entry=00c2b670 orig=FUN_00c2b670 size=72 name=do_falsename ====

/* std::numpunct<char>::do_falsename() const */

void std::numpunct<char>::do_falsename(void)

{
  long in_RSI;
  string *in_RDI;
  long in_FS_OFFSET;
  allocator local_11;
  long local_10;
  
  local_10 = *(long *)(in_FS_OFFSET + 0x28);
  string::string(in_RDI,*(char **)(*(long *)(in_RSI + 0x10) + 0x38),&local_11);
  if (local_10 == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ==== entry=00c2b6c0 orig=FUN_00c2b6c0 size=37 name=~collate ====

/* std::collate<char>::~collate() */

void __thiscall std::collate<char>::~collate(collate<char> *this)

{
  *(undefined ***)this = &PTR__collate_011b54a0;
  locale::facet::_S_destroy_c_locale((__locale_struct **)(this + 0x10));
  locale::facet::~facet((facet *)this);
  return;
}


// ==== entry=00c2b6f0 orig=FUN_00c2b6f0 size=45 name=~collate ====

/* std::collate<char>::~collate() */

void __thiscall std::collate<char>::~collate(collate<char> *this)

{
  *(undefined ***)this = &PTR__collate_011b54a0;
  locale::facet::_S_destroy_c_locale((__locale_struct **)(this + 0x10));
  locale::facet::~facet((facet *)this);
  operator_delete(this);
  return;
}


// ==== entry=00c2b720 orig=FUN_00c2b720 size=37 name=~collate_byname ====

/* std::collate_byname<char>::~collate_byname() */

void __thiscall std::collate_byname<char>::~collate_byname(collate_byname<char> *this)

{
  *(undefined ***)this = &PTR__collate_011b54a0;
  locale::facet::_S_destroy_c_locale((__locale_struct **)(this + 0x10));
  locale::facet::~facet((facet *)this);
  return;
}


// ==== entry=00c2b750 orig=FUN_00c2b750 size=45 name=~collate_byname ====

/* std::collate_byname<char>::~collate_byname() */

void __thiscall std::collate_byname<char>::~collate_byname(collate_byname<char> *this)

{
  *(undefined ***)this = &PTR__collate_011b54a0;
  locale::facet::_S_destroy_c_locale((__locale_struct **)(this + 0x10));
  locale::facet::~facet((facet *)this);
  operator_delete(this);
  return;
}


// ==== entry=00c2b780 orig=FUN_00c2b780 size=88 name=~__timepunct ====

/* std::__timepunct<char>::~__timepunct() */

void __thiscall std::__timepunct<char>::~__timepunct(__timepunct<char> *this)

{
  void *pvVar1;
  void *pvVar2;
  
  pvVar1 = *(void **)(this + 0x20);
  *(undefined ***)this = &PTR____timepunct_011b5698;
  pvVar2 = (void *)locale::facet::_S_get_c_name();
  if ((pvVar1 != pvVar2) && (pvVar1 != (void *)0x0)) {
    operator_delete__(pvVar1);
  }
  if (*(long **)(this + 0x10) != (long *)0x0) {
    (**(code **)(**(long **)(this + 0x10) + 8))();
  }
  locale::facet::_S_destroy_c_locale((__locale_struct **)(this + 0x18));
  locale::facet::~facet((facet *)this);
  return;
}


// ==== entry=00c2b7e0 orig=FUN_00c2b7e0 size=18 name=~__timepunct ====

/* std::__timepunct<char>::~__timepunct() */

void __thiscall std::__timepunct<char>::~__timepunct(__timepunct<char> *this)

{
  ~__timepunct(this);
  operator_delete(this);
  return;
}


// ==== entry=00c2b800 orig=FUN_00c2b800 size=73 name=~messages ====

/* std::messages<char>::~messages() */

void __thiscall std::messages<char>::~messages(messages<char> *this)

{
  void *pvVar1;
  void *pvVar2;
  
  pvVar1 = *(void **)(this + 0x18);
  *(undefined ***)this = &PTR__messages_011b5788;
  pvVar2 = (void *)locale::facet::_S_get_c_name();
  if ((pvVar1 != pvVar2) && (pvVar1 != (void *)0x0)) {
    operator_delete__(pvVar1);
  }
  locale::facet::_S_destroy_c_locale((__locale_struct **)(this + 0x10));
  locale::facet::~facet((facet *)this);
  return;
}


// ==== entry=00c2b850 orig=FUN_00c2b850 size=18 name=~messages ====

/* std::messages<char>::~messages() */

void __thiscall std::messages<char>::~messages(messages<char> *this)

{
  ~messages(this);
  operator_delete(this);
  return;
}


// ==== entry=00c2b870 orig=FUN_00c2b870 size=19 name=~messages_byname ====

/* std::messages_byname<char>::~messages_byname() */

void __thiscall std::messages_byname<char>::~messages_byname(messages_byname<char> *this)

{
  *(undefined ***)this = &PTR__messages_byname_011b5a90;
  messages<char>::~messages((messages<char> *)this);
  return;
}


// ==== entry=00c2b890 orig=FUN_00c2b890 size=32 name=~messages_byname ====

/* std::messages_byname<char>::~messages_byname() */

void __thiscall std::messages_byname<char>::~messages_byname(messages_byname<char> *this)

{
  *(undefined ***)this = &PTR__messages_byname_011b5a90;
  messages<char>::~messages((messages<char> *)this);
  operator_delete(this);
  return;
}


// ==== entry=00c2b8b0 orig=FUN_00c2b8b0 size=19 name=~codecvt_byname ====

/* std::codecvt_byname<char, char, __mbstate_t>::~codecvt_byname() */

void __thiscall
std::codecvt_byname<char,char,__mbstate_t>::~codecvt_byname
          (codecvt_byname<char,char,__mbstate_t> *this)

{
  *(undefined ***)this = &PTR__codecvt_byname_011b5818;
  codecvt<char,char,__mbstate_t>::~codecvt((codecvt<char,char,__mbstate_t> *)this);
  return;
}


// ==== entry=00c2b8d0 orig=FUN_00c2b8d0 size=32 name=~codecvt_byname ====

/* std::codecvt_byname<char, char, __mbstate_t>::~codecvt_byname() */

void __thiscall
std::codecvt_byname<char,char,__mbstate_t>::~codecvt_byname
          (codecvt_byname<char,char,__mbstate_t> *this)

{
  *(undefined ***)this = &PTR__codecvt_byname_011b5818;
  codecvt<char,char,__mbstate_t>::~codecvt((codecvt<char,char,__mbstate_t> *)this);
  operator_delete(this);
  return;
}


// ==== entry=00c2b8f0 name=FUN_00c2b8f0 size=43 ====

/* WARNING: Removing unreachable block (ram,0x00c2b910) */

void FUN_00c2b8f0(allocator *param_1)

{
  allocator *paVar1;
  int iVar2;
  
  LOCK();
  paVar1 = param_1 + 0x10;
  iVar2 = *(int *)paVar1;
  *(int *)paVar1 = *(int *)paVar1 + -1;
  UNLOCK();
  if (0 < iVar2) {
    return;
  }
  std::string::_Rep::_M_destroy(param_1);
  return;
}


// ==== entry=00c2b930 orig=FUN_00c2b930 size=297 name=do_compare ====

/* std::collate<char>::do_compare(char const*, char const*, char const*, char const*) const */

int __thiscall
std::collate<char>::do_compare
          (collate<char> *this,char *param_1,char *param_2,char *param_3,char *param_4)

{
  long lVar1;
  long lVar2;
  int iVar3;
  char *pcVar4;
  char *pcVar5;
  size_t sVar6;
  char *pcVar7;
  char *pcVar8;
  long in_FS_OFFSET;
  undefined1 local_41;
  long local_40;
  
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  pcVar4 = string::_S_construct<char_const*>(param_1,param_2,&local_41);
                    /* try { // try from 00c2b980 to 00c2b984 has its CatchHandler @ 00c2ba71 */
  pcVar5 = string::_S_construct<char_const*>(param_3,param_4,&local_41);
  lVar1 = *(long *)(pcVar4 + -0x18);
  lVar2 = *(long *)(pcVar5 + -0x18);
  pcVar7 = pcVar4;
  pcVar8 = pcVar5;
  do {
    iVar3 = _M_compare(this,pcVar7,pcVar8);
    if (iVar3 != 0) {
LAB_00c2b9e7:
      if (pcVar5 + -0x18 != (char *)&string::_Rep::_S_empty_rep_storage) {
        FUN_00c2b8f0(pcVar5 + -0x18,&local_41);
      }
      if (pcVar4 + -0x18 != (char *)&string::_Rep::_S_empty_rep_storage) {
        FUN_00c2b8f0(pcVar4 + -0x18,&local_41);
      }
      if (local_40 == *(long *)(in_FS_OFFSET + 0x28)) {
        return iVar3;
      }
                    /* WARNING: Subroutine does not return */
      __stack_chk_fail();
    }
    sVar6 = strlen(pcVar7);
    pcVar7 = pcVar7 + sVar6;
    sVar6 = strlen(pcVar8);
    pcVar8 = pcVar8 + sVar6;
    if ((pcVar4 + lVar1 == pcVar7) && (pcVar5 + lVar2 == pcVar8)) goto LAB_00c2b9e7;
    if (pcVar4 + lVar1 == pcVar7) {
      iVar3 = -1;
      goto LAB_00c2b9e7;
    }
    if (pcVar5 + lVar2 == pcVar8) {
      iVar3 = 1;
      goto LAB_00c2b9e7;
    }
    pcVar7 = pcVar7 + 1;
    pcVar8 = pcVar8 + 1;
  } while( true );
}


// ==== entry=00c2baa0 name=FUN_00c2baa0 size=56 ====

ulong FUN_00c2baa0(long *param_1,uint param_2)

{
  long *plVar1;
  ulong uVar2;
  
  uVar2 = (ulong)param_2;
  plVar1 = (long *)*param_1;
  if ((param_2 == 0xffffffff) && (plVar1 != (long *)0x0)) {
    if ((byte *)plVar1[2] < (byte *)plVar1[3]) {
      return (ulong)*(byte *)plVar1[2];
    }
    uVar2 = (**(code **)(*plVar1 + 0x48))();
    if ((int)uVar2 == -1) {
      *param_1 = 0;
      return uVar2;
    }
  }
  return uVar2;
}


// ==== entry=00c2baf0 name=FUN_00c2baf0 size=56 ====

ulong FUN_00c2baf0(ctype<char> *param_1,uint param_2)

{
  ulong uVar1;
  
  std::ctype<char>::_M_widen_init(param_1);
  if (*(code **)(*(long *)param_1 + 0x30) == FUN_00816ea8) {
    return (ulong)param_2;
  }
                    /* WARNING: Could not recover jumptable at 0x00c2bb2d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar1 = (**(code **)(*(long *)param_1 + 0x30))(param_1,(int)(char)param_2);
  return uVar1;
}


// ==== entry=00c2bb30 orig=FUN_00c2bb30 size=397 name=do_transform ====

/* std::collate<char>::do_transform(char const*, char const*) const */

char * std::collate<char>::do_transform(char *param_1,char *param_2)

{
  long lVar1;
  long lVar2;
  long lVar3;
  undefined1 *puVar4;
  char *pcVar5;
  char *pcVar6;
  ulong uVar7;
  size_t sVar8;
  long in_RCX;
  long in_RDX;
  ulong uVar9;
  char *__s;
  long in_FS_OFFSET;
  undefined1 local_41;
  long local_40;
  
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  *(undefined1 **)param_1 = &DAT_011c5338;
                    /* try { // try from 00c2bb7d to 00c2bb81 has its CatchHandler @ 00c2bcd1 */
  pcVar5 = string::_S_construct<char_const*>();
  lVar1 = *(long *)(pcVar5 + -0x18);
  uVar9 = (in_RCX - in_RDX) * 2;
                    /* try { // try from 00c2bb9e to 00c2bba2 has its CatchHandler @ 00c2bd2b */
  pcVar6 = operator_new__(uVar9);
  __s = pcVar5;
  while( true ) {
    uVar7 = _M_transform((collate<char> *)param_2,pcVar6,__s,uVar9);
    if (uVar9 <= uVar7) {
      uVar9 = uVar7 + 1;
      operator_delete__(pcVar6);
                    /* try { // try from 00c2bc23 to 00c2bc27 has its CatchHandler @ 00c2bcd6 */
      pcVar6 = operator_new__(uVar9);
      uVar7 = _M_transform((collate<char> *)param_2,pcVar6,__s,uVar9);
    }
                    /* try { // try from 00c2bc45 to 00c2bc49 has its CatchHandler @ 00c2bd29 */
    string::s_basic_string__append_5fd166((string *)param_1,pcVar6,uVar7);
    sVar8 = strlen(__s);
    if (pcVar5 + lVar1 == __s + sVar8) break;
    lVar2 = *(long *)param_1;
    __s = __s + sVar8 + 1;
    lVar3 = *(long *)(lVar2 + -0x18);
    uVar7 = lVar3 + 1;
    if ((*(ulong *)(lVar2 + -0x10) < uVar7) || (0 < *(int *)(lVar2 + -8))) {
                    /* try { // try from 00c2bbd3 to 00c2bbd7 has its CatchHandler @ 00c2bd29 */
      string::reserve((string *)param_1,uVar7);
    }
    *(undefined1 *)(*(long *)param_1 + *(long *)(*(long *)param_1 + -0x18)) = 0;
    puVar4 = *(undefined1 **)param_1;
    if (puVar4 != &DAT_011c5338) {
      *(undefined4 *)(puVar4 + -8) = 0;
      *(ulong *)(puVar4 + -0x18) = uVar7;
      puVar4[lVar3 + 1] = 0;
    }
  }
  operator_delete__(pcVar6);
  if (pcVar5 + -0x18 != (char *)&string::_Rep::_S_empty_rep_storage) {
    FUN_00c2b8f0(pcVar5 + -0x18,&local_41);
  }
  if (local_40 == *(long *)(in_FS_OFFSET + 0x28)) {
    return param_1;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ==== entry=00c2bd50 name=FUN_00c2bd50 size=109 ====

void * FUN_00c2bd50(ctype<char> *param_1,void *param_2,void *param_3,void *param_4)

{
  void *pvVar1;
  
  if (param_1[0x38] != (ctype<char>)0x1) {
    if (param_1[0x38] == (ctype<char>)0x0) {
      std::ctype<char>::_M_widen_init(param_1);
    }
    if (*(code **)(*(long *)param_1 + 0x38) != std::ctype<char>::do_widen) {
                    /* WARNING: Could not recover jumptable at 0x00c2bdcc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      pvVar1 = (void *)(**(code **)(*(long *)param_1 + 0x38))(param_1,param_2,param_3);
      return pvVar1;
    }
  }
  if (param_3 != param_2) {
    memcpy(param_4,param_2,(long)param_3 - (long)param_2);
  }
  return param_3;
}


// ==== entry=00c2bdd0 orig=FUN_00c2bdd0 size=119 name=__moneypunct_cache ====

/* std::__moneypunct_cache<char, false>::__moneypunct_cache(unsigned long) */

void __thiscall
std::__moneypunct_cache<char,false>::__moneypunct_cache
          (__moneypunct_cache<char,false> *this,ulong param_1)

{
  *(undefined8 *)(this + 0x10) = 0;
  *(undefined8 *)(this + 0x18) = 0;
  *(uint *)(this + 8) = (uint)(param_1 != 0);
  this[0x22] = (__moneypunct_cache<char,false>)0x0;
  *(undefined8 *)(this + 0x28) = 0;
  *(undefined ***)this = &PTR____moneypunct_cache_011b2838;
  *(undefined2 *)(this + 0x20) = 0;
  *(undefined8 *)(this + 0x30) = 0;
  *(undefined8 *)(this + 0x38) = 0;
  *(undefined8 *)(this + 0x40) = 0;
  *(undefined8 *)(this + 0x48) = 0;
  *(undefined8 *)(this + 0x50) = 0;
  *(undefined8 *)(this + 0x58) = 0;
  *(undefined4 *)(this + 0x60) = 0;
  this[0x6f] = (__moneypunct_cache<char,false>)0x0;
  return;
}


// ==== entry=00c2be50 orig=FUN_00c2be50 size=119 name=__moneypunct_cache ====

/* std::__moneypunct_cache<char, true>::__moneypunct_cache(unsigned long) */

void __thiscall
std::__moneypunct_cache<char,true>::__moneypunct_cache
          (__moneypunct_cache<char,true> *this,ulong param_1)

{
  *(undefined8 *)(this + 0x10) = 0;
  *(undefined8 *)(this + 0x18) = 0;
  *(uint *)(this + 8) = (uint)(param_1 != 0);
  this[0x22] = (__moneypunct_cache<char,true>)0x0;
  *(undefined8 *)(this + 0x28) = 0;
  *(undefined ***)this = &PTR____moneypunct_cache_011b2818;
  *(undefined2 *)(this + 0x20) = 0;
  *(undefined8 *)(this + 0x30) = 0;
  *(undefined8 *)(this + 0x38) = 0;
  *(undefined8 *)(this + 0x40) = 0;
  *(undefined8 *)(this + 0x48) = 0;
  *(undefined8 *)(this + 0x50) = 0;
  *(undefined8 *)(this + 0x58) = 0;
  *(undefined4 *)(this + 0x60) = 0;
  this[0x6f] = (__moneypunct_cache<char,true>)0x0;
  return;
}


// ==== entry=00c2bed0 orig=FUN_00c2bed0 size=58 name=moneypunct ====

/* std::moneypunct<char, false>::moneypunct(unsigned long) */

void __thiscall std::moneypunct<char,false>::moneypunct(moneypunct<char,false> *this,ulong param_1)

{
  *(undefined8 *)(this + 0x10) = 0;
  *(uint *)(this + 8) = (uint)(param_1 != 0);
  *(undefined ***)this = &PTR__moneypunct_011b5720;
                    /* try { // try from 00c2befe to 00c2bf02 has its CatchHandler @ 00c2bf0a */
  _M_initialize_moneypunct((__locale_struct *)this,(char *)0x0);
  return;
}


// ==== entry=00c2bf20 orig=FUN_00c2bf20 size=54 name=moneypunct ====

/* std::moneypunct<char, false>::moneypunct(std::__moneypunct_cache<char, false>*, unsigned long) */

void __thiscall
std::moneypunct<char,false>::moneypunct
          (moneypunct<char,false> *this,__moneypunct_cache *param_1,ulong param_2)

{
  *(__moneypunct_cache **)(this + 0x10) = param_1;
  *(uint *)(this + 8) = (uint)(param_2 != 0);
  *(undefined ***)this = &PTR__moneypunct_011b5720;
                    /* try { // try from 00c2bf4a to 00c2bf4e has its CatchHandler @ 00c2bf56 */
  _M_initialize_moneypunct((__locale_struct *)this,(char *)0x0);
  return;
}


// ==== entry=00c2bf70 orig=FUN_00c2bf70 size=54 name=moneypunct ====

/* std::moneypunct<char, false>::moneypunct(__locale_struct*, char const*, unsigned long) */

void __thiscall
std::moneypunct<char,false>::moneypunct
          (moneypunct<char,false> *this,__locale_struct *param_1,char *param_2,ulong param_3)

{
  *(undefined8 *)(this + 0x10) = 0;
  *(uint *)(this + 8) = (uint)(param_3 != 0);
  *(undefined ***)this = &PTR__moneypunct_011b5720;
                    /* try { // try from 00c2bf9a to 00c2bf9e has its CatchHandler @ 00c2bfa6 */
  _M_initialize_moneypunct((__locale_struct *)this,(char *)param_1);
  return;
}


// ==== entry=00c2bfc0 orig=FUN_00c2bfc0 size=27 name=decimal_point ====

/* std::moneypunct<char, false>::decimal_point() const */

ulong __thiscall std::moneypunct<char,false>::decimal_point(moneypunct<char,false> *this)

{
  ulong uVar1;
  
  if (*(code **)(*(long *)this + 0x10) == do_decimal_point) {
    return (ulong)*(byte *)(*(long *)(this + 0x10) + 0x21);
  }
                    /* WARNING: Could not recover jumptable at 0x00c2bfe0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar1 = (**(code **)(*(long *)this + 0x10))();
  return uVar1;
}


// ==== entry=00c2bff0 orig=FUN_00c2bff0 size=27 name=thousands_sep ====

/* std::moneypunct<char, false>::thousands_sep() const */

ulong __thiscall std::moneypunct<char,false>::thousands_sep(moneypunct<char,false> *this)

{
  ulong uVar1;
  
  if (*(code **)(*(long *)this + 0x18) == do_thousands_sep) {
    return (ulong)*(byte *)(*(long *)(this + 0x10) + 0x22);
  }
                    /* WARNING: Could not recover jumptable at 0x00c2c010. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar1 = (**(code **)(*(long *)this + 0x18))();
  return uVar1;
}


// ==== entry=00c2c020 orig=FUN_00c2c020 size=92 name=grouping ====

/* std::moneypunct<char, false>::grouping() const */

void std::moneypunct<char,false>::grouping(void)

{
  long *in_RSI;
  string *in_RDI;
  long in_FS_OFFSET;
  allocator local_11;
  long local_10;
  
  local_10 = *(long *)(in_FS_OFFSET + 0x28);
  if (*(code **)(*in_RSI + 0x20) == do_grouping) {
    string::string(in_RDI,*(char **)(in_RSI[2] + 0x10),&local_11);
  }
  else {
    (**(code **)(*in_RSI + 0x20))();
  }
  if (local_10 == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ==== entry=00c2c090 orig=FUN_00c2c090 size=92 name=curr_symbol ====

/* std::moneypunct<char, false>::curr_symbol() const */

void std::moneypunct<char,false>::curr_symbol(void)

{
  long *in_RSI;
  string *in_RDI;
  long in_FS_OFFSET;
  allocator local_11;
  long local_10;
  
  local_10 = *(long *)(in_FS_OFFSET + 0x28);
  if (*(code **)(*in_RSI + 0x28) == do_curr_symbol) {
    string::string(in_RDI,*(char **)(in_RSI[2] + 0x28),&local_11);
  }
  else {
    (**(code **)(*in_RSI + 0x28))();
  }
  if (local_10 == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ==== entry=00c2c100 orig=FUN_00c2c100 size=92 name=positive_sign ====

/* std::moneypunct<char, false>::positive_sign() const */

void std::moneypunct<char,false>::positive_sign(void)

{
  long *in_RSI;
  string *in_RDI;
  long in_FS_OFFSET;
  allocator local_11;
  long local_10;
  
  local_10 = *(long *)(in_FS_OFFSET + 0x28);
  if (*(code **)(*in_RSI + 0x30) == do_positive_sign) {
    string::string(in_RDI,*(char **)(in_RSI[2] + 0x38),&local_11);
  }
  else {
    (**(code **)(*in_RSI + 0x30))();
  }
  if (local_10 == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ==== entry=00c2c170 orig=FUN_00c2c170 size=92 name=negative_sign ====

/* std::moneypunct<char, false>::negative_sign() const */

void std::moneypunct<char,false>::negative_sign(void)

{
  long *in_RSI;
  string *in_RDI;
  long in_FS_OFFSET;
  allocator local_11;
  long local_10;
  
  local_10 = *(long *)(in_FS_OFFSET + 0x28);
  if (*(code **)(*in_RSI + 0x38) == do_negative_sign) {
    string::string(in_RDI,*(char **)(in_RSI[2] + 0x48),&local_11);
  }
  else {
    (**(code **)(*in_RSI + 0x38))();
  }
  if (local_10 == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ==== entry=00c2c1e0 orig=FUN_00c2c1e0 size=26 name=frac_digits ====

/* std::moneypunct<char, false>::frac_digits() const */

ulong __thiscall std::moneypunct<char,false>::frac_digits(moneypunct<char,false> *this)

{
  ulong uVar1;
  
  if (*(code **)(*(long *)this + 0x40) == do_frac_digits) {
    return (ulong)*(uint *)(*(long *)(this + 0x10) + 0x58);
  }
                    /* WARNING: Could not recover jumptable at 0x00c2c200. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar1 = (**(code **)(*(long *)this + 0x40))();
  return uVar1;
}


// ==== entry=00c2c210 orig=FUN_00c2c210 size=91 name=pos_format ====

/* std::moneypunct<char, false>::pos_format() const */

ulong __thiscall std::moneypunct<char,false>::pos_format(moneypunct<char,false> *this)

{
  ulong uVar1;
  long in_FS_OFFSET;
  
  if (*(code **)(*(long *)this + 0x48) == do_pos_format) {
    if (*(long *)(in_FS_OFFSET + 0x28) == *(long *)(in_FS_OFFSET + 0x28)) {
      return (ulong)*(uint *)(*(long *)(this + 0x10) + 0x5c);
    }
  }
  else if (*(long *)(in_FS_OFFSET + 0x28) == *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Could not recover jumptable at 0x00c2c264. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar1 = (**(code **)(*(long *)this + 0x48))();
    return uVar1;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ==== entry=00c2c270 orig=FUN_00c2c270 size=91 name=neg_format ====

/* std::moneypunct<char, false>::neg_format() const */

ulong __thiscall std::moneypunct<char,false>::neg_format(moneypunct<char,false> *this)

{
  ulong uVar1;
  long in_FS_OFFSET;
  
  if (*(code **)(*(long *)this + 0x50) == do_neg_format) {
    if (*(long *)(in_FS_OFFSET + 0x28) == *(long *)(in_FS_OFFSET + 0x28)) {
      return (ulong)*(uint *)(*(long *)(this + 0x10) + 0x60);
    }
  }
  else if (*(long *)(in_FS_OFFSET + 0x28) == *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Could not recover jumptable at 0x00c2c2c4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar1 = (**(code **)(*(long *)this + 0x50))();
    return uVar1;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ==== entry=00c2c2d0 orig=FUN_00c2c2d0 size=58 name=moneypunct ====

/* std::moneypunct<char, true>::moneypunct(unsigned long) */

void __thiscall std::moneypunct<char,true>::moneypunct(moneypunct<char,true> *this,ulong param_1)

{
  *(undefined8 *)(this + 0x10) = 0;
  *(uint *)(this + 8) = (uint)(param_1 != 0);
  *(undefined ***)this = &PTR__moneypunct_011b56b8;
                    /* try { // try from 00c2c2fe to 00c2c302 has its CatchHandler @ 00c2c30a */
  _M_initialize_moneypunct((__locale_struct *)this,(char *)0x0);
  return;
}


// ==== entry=00c2c320 orig=FUN_00c2c320 size=54 name=moneypunct ====

/* std::moneypunct<char, true>::moneypunct(std::__moneypunct_cache<char, true>*, unsigned long) */

void __thiscall
std::moneypunct<char,true>::moneypunct
          (moneypunct<char,true> *this,__moneypunct_cache *param_1,ulong param_2)

{
  *(__moneypunct_cache **)(this + 0x10) = param_1;
  *(uint *)(this + 8) = (uint)(param_2 != 0);
  *(undefined ***)this = &PTR__moneypunct_011b56b8;
                    /* try { // try from 00c2c34a to 00c2c34e has its CatchHandler @ 00c2c356 */
  _M_initialize_moneypunct((__locale_struct *)this,(char *)0x0);
  return;
}


// ==== entry=00c2c370 orig=FUN_00c2c370 size=54 name=moneypunct ====

/* std::moneypunct<char, true>::moneypunct(__locale_struct*, char const*, unsigned long) */

void __thiscall
std::moneypunct<char,true>::moneypunct
          (moneypunct<char,true> *this,__locale_struct *param_1,char *param_2,ulong param_3)

{
  *(undefined8 *)(this + 0x10) = 0;
  *(uint *)(this + 8) = (uint)(param_3 != 0);
  *(undefined ***)this = &PTR__moneypunct_011b56b8;
                    /* try { // try from 00c2c39a to 00c2c39e has its CatchHandler @ 00c2c3a6 */
  _M_initialize_moneypunct((__locale_struct *)this,(char *)param_1);
  return;
}


// ==== entry=00c2c3c0 orig=FUN_00c2c3c0 size=27 name=decimal_point ====

/* std::moneypunct<char, true>::decimal_point() const */

ulong __thiscall std::moneypunct<char,true>::decimal_point(moneypunct<char,true> *this)

{
  ulong uVar1;
  
  if (*(code **)(*(long *)this + 0x10) == do_decimal_point) {
    return (ulong)*(byte *)(*(long *)(this + 0x10) + 0x21);
  }
                    /* WARNING: Could not recover jumptable at 0x00c2c3e0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar1 = (**(code **)(*(long *)this + 0x10))();
  return uVar1;
}


// ==== entry=00c2c3f0 orig=FUN_00c2c3f0 size=27 name=thousands_sep ====

/* std::moneypunct<char, true>::thousands_sep() const */

ulong __thiscall std::moneypunct<char,true>::thousands_sep(moneypunct<char,true> *this)

{
  ulong uVar1;
  
  if (*(code **)(*(long *)this + 0x18) == do_thousands_sep) {
    return (ulong)*(byte *)(*(long *)(this + 0x10) + 0x22);
  }
                    /* WARNING: Could not recover jumptable at 0x00c2c410. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar1 = (**(code **)(*(long *)this + 0x18))();
  return uVar1;
}


// ==== entry=00c2c420 orig=FUN_00c2c420 size=92 name=grouping ====

/* std::moneypunct<char, true>::grouping() const */

void std::moneypunct<char,true>::grouping(void)

{
  long *in_RSI;
  string *in_RDI;
  long in_FS_OFFSET;
  allocator local_11;
  long local_10;
  
  local_10 = *(long *)(in_FS_OFFSET + 0x28);
  if (*(code **)(*in_RSI + 0x20) == do_grouping) {
    string::string(in_RDI,*(char **)(in_RSI[2] + 0x10),&local_11);
  }
  else {
    (**(code **)(*in_RSI + 0x20))();
  }
  if (local_10 == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ==== entry=00c2c490 orig=FUN_00c2c490 size=92 name=curr_symbol ====

/* std::moneypunct<char, true>::curr_symbol() const */

void std::moneypunct<char,true>::curr_symbol(void)

{
  long *in_RSI;
  string *in_RDI;
  long in_FS_OFFSET;
  allocator local_11;
  long local_10;
  
  local_10 = *(long *)(in_FS_OFFSET + 0x28);
  if (*(code **)(*in_RSI + 0x28) == do_curr_symbol) {
    string::string(in_RDI,*(char **)(in_RSI[2] + 0x28),&local_11);
  }
  else {
    (**(code **)(*in_RSI + 0x28))();
  }
  if (local_10 == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ==== entry=00c2c500 orig=FUN_00c2c500 size=92 name=positive_sign ====

/* std::moneypunct<char, true>::positive_sign() const */

void std::moneypunct<char,true>::positive_sign(void)

{
  long *in_RSI;
  string *in_RDI;
  long in_FS_OFFSET;
  allocator local_11;
  long local_10;
  
  local_10 = *(long *)(in_FS_OFFSET + 0x28);
  if (*(code **)(*in_RSI + 0x30) == do_positive_sign) {
    string::string(in_RDI,*(char **)(in_RSI[2] + 0x38),&local_11);
  }
  else {
    (**(code **)(*in_RSI + 0x30))();
  }
  if (local_10 == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ==== entry=00c2c570 orig=FUN_00c2c570 size=92 name=negative_sign ====

/* std::moneypunct<char, true>::negative_sign() const */

void std::moneypunct<char,true>::negative_sign(void)

{
  long *in_RSI;
  string *in_RDI;
  long in_FS_OFFSET;
  allocator local_11;
  long local_10;
  
  local_10 = *(long *)(in_FS_OFFSET + 0x28);
  if (*(code **)(*in_RSI + 0x38) == do_negative_sign) {
    string::string(in_RDI,*(char **)(in_RSI[2] + 0x48),&local_11);
  }
  else {
    (**(code **)(*in_RSI + 0x38))();
  }
  if (local_10 == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ==== entry=00c2c5e0 orig=FUN_00c2c5e0 size=26 name=frac_digits ====

/* std::moneypunct<char, true>::frac_digits() const */

ulong __thiscall std::moneypunct<char,true>::frac_digits(moneypunct<char,true> *this)

{
  ulong uVar1;
  
  if (*(code **)(*(long *)this + 0x40) == do_frac_digits) {
    return (ulong)*(uint *)(*(long *)(this + 0x10) + 0x58);
  }
                    /* WARNING: Could not recover jumptable at 0x00c2c600. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar1 = (**(code **)(*(long *)this + 0x40))();
  return uVar1;
}


// ==== entry=00c2c610 orig=FUN_00c2c610 size=91 name=pos_format ====

/* std::moneypunct<char, true>::pos_format() const */

ulong __thiscall std::moneypunct<char,true>::pos_format(moneypunct<char,true> *this)

{
  ulong uVar1;
  long in_FS_OFFSET;
  
  if (*(code **)(*(long *)this + 0x48) == do_pos_format) {
    if (*(long *)(in_FS_OFFSET + 0x28) == *(long *)(in_FS_OFFSET + 0x28)) {
      return (ulong)*(uint *)(*(long *)(this + 0x10) + 0x5c);
    }
  }
  else if (*(long *)(in_FS_OFFSET + 0x28) == *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Could not recover jumptable at 0x00c2c664. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar1 = (**(code **)(*(long *)this + 0x48))();
    return uVar1;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ==== entry=00c2c670 orig=FUN_00c2c670 size=91 name=neg_format ====

/* std::moneypunct<char, true>::neg_format() const */

ulong __thiscall std::moneypunct<char,true>::neg_format(moneypunct<char,true> *this)

{
  ulong uVar1;
  long in_FS_OFFSET;
  
  if (*(code **)(*(long *)this + 0x50) == do_neg_format) {
    if (*(long *)(in_FS_OFFSET + 0x28) == *(long *)(in_FS_OFFSET + 0x28)) {
      return (ulong)*(uint *)(*(long *)(this + 0x10) + 0x60);
    }
  }
  else if (*(long *)(in_FS_OFFSET + 0x28) == *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Could not recover jumptable at 0x00c2c6c4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar1 = (**(code **)(*(long *)this + 0x50))();
    return uVar1;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ==== entry=00c2c6d0 orig=FUN_00c2c6d0 size=208 name=moneypunct_byname ====

/* std::moneypunct_byname<char, false>::moneypunct_byname(char const*, unsigned long) */

void __thiscall
std::moneypunct_byname<char,false>::moneypunct_byname
          (moneypunct_byname<char,false> *this,char *param_1,ulong param_2)

{
  long lVar1;
  byte *pbVar2;
  byte *pbVar3;
  long in_FS_OFFSET;
  bool bVar4;
  bool bVar5;
  bool bVar6;
  byte bVar7;
  __locale_struct *local_28;
  long local_20;
  
  bVar7 = 0;
  local_20 = *(long *)(in_FS_OFFSET + 0x28);
  *(undefined8 *)(this + 0x10) = 0;
  *(uint *)(this + 8) = (uint)(param_2 != 0);
  *(undefined ***)this = &PTR__moneypunct_011b5720;
                    /* try { // try from 00c2c713 to 00c2c717 has its CatchHandler @ 00c2c7aa */
  moneypunct<char,false>::_M_initialize_moneypunct((__locale_struct *)this,(char *)0x0);
  lVar1 = 2;
  bVar4 = false;
  bVar6 = false;
  *(undefined ***)this = &PTR__moneypunct_byname_011b5870;
  pbVar2 = (byte *)param_1;
  pbVar3 = &DAT_00ca9164;
  do {
    if (lVar1 == 0) break;
    lVar1 = lVar1 + -1;
    bVar4 = *pbVar2 < *pbVar3;
    bVar6 = *pbVar2 == *pbVar3;
    pbVar2 = pbVar2 + (ulong)bVar7 * -2 + 1;
    pbVar3 = pbVar3 + (ulong)bVar7 * -2 + 1;
  } while (bVar6);
  bVar5 = false;
  bVar4 = (!bVar4 && !bVar6) == bVar4;
  if (!bVar4) {
    lVar1 = 6;
    pbVar2 = (byte *)param_1;
    pbVar3 = (byte *)"POSIX";
    do {
      if (lVar1 == 0) break;
      lVar1 = lVar1 + -1;
      bVar5 = *pbVar2 < *pbVar3;
      bVar4 = *pbVar2 == *pbVar3;
      pbVar2 = pbVar2 + (ulong)bVar7 * -2 + 1;
      pbVar3 = pbVar3 + (ulong)bVar7 * -2 + 1;
    } while (bVar4);
    if ((!bVar5 && !bVar4) != bVar5) {
                    /* try { // try from 00c2c783 to 00c2c79d has its CatchHandler @ 00c2c7a5 */
      locale::facet::_S_create_c_locale(&local_28,param_1,(__locale_struct *)0x0);
      moneypunct<char,false>::_M_initialize_moneypunct((__locale_struct *)this,(char *)local_28);
      locale::facet::_S_destroy_c_locale(&local_28);
    }
  }
  if (local_20 == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ==== entry=00c2c7d0 name=FUN_00c2c7d0 size=208 ====

void FUN_00c2c7d0(__locale_struct *param_1,undefined8 *param_2,long param_3)

{
  byte *pbVar1;
  long lVar2;
  byte *pbVar3;
  byte *pbVar4;
  long in_FS_OFFSET;
  bool bVar5;
  bool bVar6;
  bool bVar7;
  byte bVar8;
  __locale_struct *local_28;
  long local_20;
  
  bVar8 = 0;
  pbVar1 = (byte *)*param_2;
  local_20 = *(long *)(in_FS_OFFSET + 0x28);
  param_1->__locales[2] = (__locale_data *)0x0;
  *(uint *)(param_1->__locales + 1) = (uint)(param_3 != 0);
  param_1->__locales[0] = (__locale_data *)&PTR__moneypunct_011b5720;
                    /* try { // try from 00c2c813 to 00c2c817 has its CatchHandler @ 00c2c8aa */
  std::moneypunct<char,false>::_M_initialize_moneypunct(param_1,(char *)0x0);
  lVar2 = 2;
  bVar5 = false;
  bVar7 = false;
  param_1->__locales[0] = (__locale_data *)&PTR__moneypunct_byname_011b5870;
  pbVar3 = pbVar1;
  pbVar4 = &DAT_00ca9164;
  do {
    if (lVar2 == 0) break;
    lVar2 = lVar2 + -1;
    bVar5 = *pbVar3 < *pbVar4;
    bVar7 = *pbVar3 == *pbVar4;
    pbVar3 = pbVar3 + (ulong)bVar8 * -2 + 1;
    pbVar4 = pbVar4 + (ulong)bVar8 * -2 + 1;
  } while (bVar7);
  bVar6 = false;
  bVar5 = (!bVar5 && !bVar7) == bVar5;
  if (!bVar5) {
    lVar2 = 6;
    pbVar3 = pbVar1;
    pbVar4 = (byte *)"POSIX";
    do {
      if (lVar2 == 0) break;
      lVar2 = lVar2 + -1;
      bVar6 = *pbVar3 < *pbVar4;
      bVar5 = *pbVar3 == *pbVar4;
      pbVar3 = pbVar3 + (ulong)bVar8 * -2 + 1;
      pbVar4 = pbVar4 + (ulong)bVar8 * -2 + 1;
    } while (bVar5);
    if ((!bVar6 && !bVar5) != bVar6) {
                    /* try { // try from 00c2c883 to 00c2c89d has its CatchHandler @ 00c2c8a5 */
      std::locale::facet::_S_create_c_locale(&local_28,(char *)pbVar1,(__locale_struct *)0x0);
      std::moneypunct<char,false>::_M_initialize_moneypunct(param_1,(char *)local_28);
      std::locale::facet::_S_destroy_c_locale(&local_28);
    }
  }
  if (local_20 == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ==== entry=00c2c8d0 orig=FUN_00c2c8d0 size=208 name=moneypunct_byname ====

/* std::moneypunct_byname<char, true>::moneypunct_byname(char const*, unsigned long) */

void __thiscall
std::moneypunct_byname<char,true>::moneypunct_byname
          (moneypunct_byname<char,true> *this,char *param_1,ulong param_2)

{
  long lVar1;
  byte *pbVar2;
  byte *pbVar3;
  long in_FS_OFFSET;
  bool bVar4;
  bool bVar5;
  bool bVar6;
  byte bVar7;
  __locale_struct *local_28;
  long local_20;
  
  bVar7 = 0;
  local_20 = *(long *)(in_FS_OFFSET + 0x28);
  *(undefined8 *)(this + 0x10) = 0;
  *(uint *)(this + 8) = (uint)(param_2 != 0);
  *(undefined ***)this = &PTR__moneypunct_011b56b8;
                    /* try { // try from 00c2c913 to 00c2c917 has its CatchHandler @ 00c2c9aa */
  moneypunct<char,true>::_M_initialize_moneypunct((__locale_struct *)this,(char *)0x0);
  lVar1 = 2;
  bVar4 = false;
  bVar6 = false;
  *(undefined ***)this = &PTR__moneypunct_byname_011b58d8;
  pbVar2 = (byte *)param_1;
  pbVar3 = &DAT_00ca9164;
  do {
    if (lVar1 == 0) break;
    lVar1 = lVar1 + -1;
    bVar4 = *pbVar2 < *pbVar3;
    bVar6 = *pbVar2 == *pbVar3;
    pbVar2 = pbVar2 + (ulong)bVar7 * -2 + 1;
    pbVar3 = pbVar3 + (ulong)bVar7 * -2 + 1;
  } while (bVar6);
  bVar5 = false;
  bVar4 = (!bVar4 && !bVar6) == bVar4;
  if (!bVar4) {
    lVar1 = 6;
    pbVar2 = (byte *)param_1;
    pbVar3 = (byte *)"POSIX";
    do {
      if (lVar1 == 0) break;
      lVar1 = lVar1 + -1;
      bVar5 = *pbVar2 < *pbVar3;
      bVar4 = *pbVar2 == *pbVar3;
      pbVar2 = pbVar2 + (ulong)bVar7 * -2 + 1;
      pbVar3 = pbVar3 + (ulong)bVar7 * -2 + 1;
    } while (bVar4);
    if ((!bVar5 && !bVar4) != bVar5) {
                    /* try { // try from 00c2c983 to 00c2c99d has its CatchHandler @ 00c2c9a5 */
      locale::facet::_S_create_c_locale(&local_28,param_1,(__locale_struct *)0x0);
      moneypunct<char,true>::_M_initialize_moneypunct((__locale_struct *)this,(char *)local_28);
      locale::facet::_S_destroy_c_locale(&local_28);
    }
  }
  if (local_20 == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ==== entry=00c2c9d0 name=FUN_00c2c9d0 size=208 ====

void FUN_00c2c9d0(__locale_struct *param_1,undefined8 *param_2,long param_3)

{
  byte *pbVar1;
  long lVar2;
  byte *pbVar3;
  byte *pbVar4;
  long in_FS_OFFSET;
  bool bVar5;
  bool bVar6;
  bool bVar7;
  byte bVar8;
  __locale_struct *local_28;
  long local_20;
  
  bVar8 = 0;
  pbVar1 = (byte *)*param_2;
  local_20 = *(long *)(in_FS_OFFSET + 0x28);
  param_1->__locales[2] = (__locale_data *)0x0;
  *(uint *)(param_1->__locales + 1) = (uint)(param_3 != 0);
  param_1->__locales[0] = (__locale_data *)&PTR__moneypunct_011b56b8;
                    /* try { // try from 00c2ca13 to 00c2ca17 has its CatchHandler @ 00c2caaa */
  std::moneypunct<char,true>::_M_initialize_moneypunct(param_1,(char *)0x0);
  lVar2 = 2;
  bVar5 = false;
  bVar7 = false;
  param_1->__locales[0] = (__locale_data *)&PTR__moneypunct_byname_011b58d8;
  pbVar3 = pbVar1;
  pbVar4 = &DAT_00ca9164;
  do {
    if (lVar2 == 0) break;
    lVar2 = lVar2 + -1;
    bVar5 = *pbVar3 < *pbVar4;
    bVar7 = *pbVar3 == *pbVar4;
    pbVar3 = pbVar3 + (ulong)bVar8 * -2 + 1;
    pbVar4 = pbVar4 + (ulong)bVar8 * -2 + 1;
  } while (bVar7);
  bVar6 = false;
  bVar5 = (!bVar5 && !bVar7) == bVar5;
  if (!bVar5) {
    lVar2 = 6;
    pbVar3 = pbVar1;
    pbVar4 = (byte *)"POSIX";
    do {
      if (lVar2 == 0) break;
      lVar2 = lVar2 + -1;
      bVar6 = *pbVar3 < *pbVar4;
      bVar5 = *pbVar3 == *pbVar4;
      pbVar3 = pbVar3 + (ulong)bVar8 * -2 + 1;
      pbVar4 = pbVar4 + (ulong)bVar8 * -2 + 1;
    } while (bVar5);
    if ((!bVar6 && !bVar5) != bVar6) {
                    /* try { // try from 00c2ca83 to 00c2ca9d has its CatchHandler @ 00c2caa5 */
      std::locale::facet::_S_create_c_locale(&local_28,(char *)pbVar1,(__locale_struct *)0x0);
      std::moneypunct<char,true>::_M_initialize_moneypunct(param_1,(char *)local_28);
      std::locale::facet::_S_destroy_c_locale(&local_28);
    }
  }
  if (local_20 == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ==== entry=00c2cad0 orig=FUN_00c2cad0 size=26 name=money_get ====

/* std::money_get<char, std::istreambuf_iterator<char, std::char_traits<char> >
   >::money_get(unsigned long) */

void __thiscall
std::money_get<char,std::istreambuf_iterator<char,std::char_traits<char>>>::money_get
          (money_get<char,std::istreambuf_iterator<char,std::char_traits<char>>> *this,ulong param_1
          )

{
  *(uint *)(this + 8) = (uint)(param_1 != 0);
  *(undefined ***)this = &PTR__money_get_011b5940;
  return;
}


// ==== entry=00c2caf0 orig=FUN_00c2caf0 size=13 name=get ====

/* std::money_get<char, std::istreambuf_iterator<char, std::char_traits<char> >
   >::get(std::istreambuf_iterator<char, std::char_traits<char> >, std::istreambuf_iterator<char,
   std::char_traits<char> >, bool, std::ios_base&, std::_Ios_Iostate&, long double&) const */

void std::money_get<char,std::istreambuf_iterator<char,std::char_traits<char>>>::get(long *param_1)

{
                    /* WARNING: Could not recover jumptable at 0x00c2cafb. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*param_1 + 0x10))();
  return;
}


// ==== entry=00c2cb00 orig=FUN_00c2cb00 size=13 name=get ====

/* std::money_get<char, std::istreambuf_iterator<char, std::char_traits<char> >
   >::get(std::istreambuf_iterator<char, std::char_traits<char> >, std::istreambuf_iterator<char,
   std::char_traits<char> >, bool, std::ios_base&, std::_Ios_Iostate&, std::string&) const */

void std::money_get<char,std::istreambuf_iterator<char,std::char_traits<char>>>::get(long *param_1)

{
                    /* WARNING: Could not recover jumptable at 0x00c2cb0b. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*param_1 + 0x18))();
  return;
}


// ==== entry=00c2cb10 orig=FUN_00c2cb10 size=26 name=money_put ====

/* std::money_put<char, std::ostreambuf_iterator<char, std::char_traits<char> >
   >::money_put(unsigned long) */

void __thiscall
std::money_put<char,std::ostreambuf_iterator<char,std::char_traits<char>>>::money_put
          (money_put<char,std::ostreambuf_iterator<char,std::char_traits<char>>> *this,ulong param_1
          )

{
  *(uint *)(this + 8) = (uint)(param_1 != 0);
  *(undefined ***)this = &PTR__money_put_011b5970;
  return;
}


// ==== entry=00c2cb30 orig=FUN_00c2cb30 size=16 name=put ====

/* std::money_put<char, std::ostreambuf_iterator<char, std::char_traits<char> >
   >::put(std::ostreambuf_iterator<char, std::char_traits<char> >, bool, std::ios_base&, char, long
   double) const */

void std::money_put<char,std::ostreambuf_iterator<char,std::char_traits<char>>>::put(long *param_1)

{
                    /* WARNING: Could not recover jumptable at 0x00c2cb3e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*param_1 + 0x10))();
  return;
}


// ==== entry=00c2cb40 orig=FUN_00c2cb40 size=16 name=put ====

/* std::money_put<char, std::ostreambuf_iterator<char, std::char_traits<char> >
   >::put(std::ostreambuf_iterator<char, std::char_traits<char> >, bool, std::ios_base&, char,
   std::string const&) const */

void std::money_put<char,std::ostreambuf_iterator<char,std::char_traits<char>>>::put(long *param_1)

{
                    /* WARNING: Could not recover jumptable at 0x00c2cb4e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*param_1 + 0x18))();
  return;
}


// ==== entry=00c2cb50 orig=FUN_00c2cb50 size=91 name=__numpunct_cache ====

/* std::__numpunct_cache<char>::__numpunct_cache(unsigned long) */

void __thiscall
std::__numpunct_cache<char>::__numpunct_cache(__numpunct_cache<char> *this,ulong param_1)

{
  *(undefined8 *)(this + 0x10) = 0;
  *(undefined8 *)(this + 0x18) = 0;
  *(uint *)(this + 8) = (uint)(param_1 != 0);
  this[0x20] = (__numpunct_cache<char>)0x0;
  *(undefined8 *)(this + 0x28) = 0;
  *(undefined ***)this = &PTR____numpunct_cache_011b28c8;
  *(undefined8 *)(this + 0x30) = 0;
  *(undefined8 *)(this + 0x38) = 0;
  *(undefined8 *)(this + 0x40) = 0;
  *(undefined2 *)(this + 0x48) = 0;
  this[0x88] = (__numpunct_cache<char>)0x0;
  return;
}


// ==== entry=00c2cbb0 orig=FUN_00c2cbb0 size=56 name=numpunct ====

/* std::numpunct<char>::numpunct(unsigned long) */

void __thiscall std::numpunct<char>::numpunct(numpunct<char> *this,ulong param_1)

{
  *(undefined8 *)(this + 0x10) = 0;
  *(uint *)(this + 8) = (uint)(param_1 != 0);
  *(undefined ***)this = &PTR__numpunct_011b5510;
                    /* try { // try from 00c2cbdc to 00c2cbe0 has its CatchHandler @ 00c2cbe8 */
  _M_initialize_numpunct(this,(__locale_struct *)0x0);
  return;
}


// ==== entry=00c2cc00 orig=FUN_00c2cc00 size=52 name=numpunct ====

/* std::numpunct<char>::numpunct(std::__numpunct_cache<char>*, unsigned long) */

void __thiscall
std::numpunct<char>::numpunct(numpunct<char> *this,__numpunct_cache *param_1,ulong param_2)

{
  *(__numpunct_cache **)(this + 0x10) = param_1;
  *(uint *)(this + 8) = (uint)(param_2 != 0);
  *(undefined ***)this = &PTR__numpunct_011b5510;
                    /* try { // try from 00c2cc28 to 00c2cc2c has its CatchHandler @ 00c2cc34 */
  _M_initialize_numpunct(this,(__locale_struct *)0x0);
  return;
}


// ==== entry=00c2cc50 orig=FUN_00c2cc50 size=54 name=numpunct ====

/* std::numpunct<char>::numpunct(__locale_struct*, unsigned long) */

void __thiscall
std::numpunct<char>::numpunct(numpunct<char> *this,__locale_struct *param_1,ulong param_2)

{
  *(undefined8 *)(this + 0x10) = 0;
  *(uint *)(this + 8) = (uint)(param_2 != 0);
  *(undefined ***)this = &PTR__numpunct_011b5510;
                    /* try { // try from 00c2cc7a to 00c2cc7e has its CatchHandler @ 00c2cc86 */
  _M_initialize_numpunct(this,param_1);
  return;
}


// ==== entry=00c2cca0 orig=FUN_00c2cca0 size=27 name=decimal_point ====

/* std::numpunct<char>::decimal_point() const */

ulong __thiscall std::numpunct<char>::decimal_point(numpunct<char> *this)

{
  ulong uVar1;
  
  if (*(code **)(*(long *)this + 0x10) == do_decimal_point) {
    return (ulong)*(byte *)(*(long *)(this + 0x10) + 0x48);
  }
                    /* WARNING: Could not recover jumptable at 0x00c2ccc0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar1 = (**(code **)(*(long *)this + 0x10))();
  return uVar1;
}


// ==== entry=00c2ccd0 orig=FUN_00c2ccd0 size=27 name=thousands_sep ====

/* std::numpunct<char>::thousands_sep() const */

ulong __thiscall std::numpunct<char>::thousands_sep(numpunct<char> *this)

{
  ulong uVar1;
  
  if (*(code **)(*(long *)this + 0x18) == do_thousands_sep) {
    return (ulong)*(byte *)(*(long *)(this + 0x10) + 0x49);
  }
                    /* WARNING: Could not recover jumptable at 0x00c2ccf0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar1 = (**(code **)(*(long *)this + 0x18))();
  return uVar1;
}


// ==== entry=00c2cd00 orig=FUN_00c2cd00 size=92 name=grouping ====

/* std::numpunct<char>::grouping() const */

void std::numpunct<char>::grouping(void)

{
  long *in_RSI;
  string *in_RDI;
  long in_FS_OFFSET;
  allocator local_11;
  long local_10;
  
  local_10 = *(long *)(in_FS_OFFSET + 0x28);
  if (*(code **)(*in_RSI + 0x20) == do_grouping) {
    string::string(in_RDI,*(char **)(in_RSI[2] + 0x10),&local_11);
  }
  else {
    (**(code **)(*in_RSI + 0x20))();
  }
  if (local_10 == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ==== entry=00c2cd70 orig=FUN_00c2cd70 size=92 name=truename ====

/* std::numpunct<char>::truename() const */

void std::numpunct<char>::truename(void)

{
  long *in_RSI;
  string *in_RDI;
  long in_FS_OFFSET;
  allocator local_11;
  long local_10;
  
  local_10 = *(long *)(in_FS_OFFSET + 0x28);
  if (*(code **)(*in_RSI + 0x28) == do_truename) {
    string::string(in_RDI,*(char **)(in_RSI[2] + 0x28),&local_11);
  }
  else {
    (**(code **)(*in_RSI + 0x28))();
  }
  if (local_10 == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ==== entry=00c2cde0 orig=FUN_00c2cde0 size=92 name=falsename ====

/* std::numpunct<char>::falsename() const */

void std::numpunct<char>::falsename(void)

{
  long *in_RSI;
  string *in_RDI;
  long in_FS_OFFSET;
  allocator local_11;
  long local_10;
  
  local_10 = *(long *)(in_FS_OFFSET + 0x28);
  if (*(code **)(*in_RSI + 0x30) == do_falsename) {
    string::string(in_RDI,*(char **)(in_RSI[2] + 0x38),&local_11);
  }
  else {
    (**(code **)(*in_RSI + 0x30))();
  }
  if (local_10 == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ==== entry=00c2ce50 orig=FUN_00c2ce50 size=204 name=numpunct_byname ====

/* std::numpunct_byname<char>::numpunct_byname(char const*, unsigned long) */

void __thiscall
std::numpunct_byname<char>::numpunct_byname(numpunct_byname<char> *this,char *param_1,ulong param_2)

{
  long lVar1;
  byte *pbVar2;
  byte *pbVar3;
  long in_FS_OFFSET;
  bool bVar4;
  bool bVar5;
  bool bVar6;
  byte bVar7;
  __locale_struct *local_28;
  long local_20;
  
  bVar7 = 0;
  local_20 = *(long *)(in_FS_OFFSET + 0x28);
  *(undefined8 *)(this + 0x10) = 0;
  *(uint *)(this + 8) = (uint)(param_2 != 0);
  *(undefined ***)this = &PTR__numpunct_011b5510;
                    /* try { // try from 00c2ce91 to 00c2ce95 has its CatchHandler @ 00c2cf28 */
  numpunct<char>::_M_initialize_numpunct((numpunct<char> *)this,(__locale_struct *)0x0);
  lVar1 = 2;
  bVar4 = false;
  bVar6 = false;
  *(undefined ***)this = &PTR__numpunct_byname_011b5558;
  pbVar2 = (byte *)param_1;
  pbVar3 = &DAT_00ca9164;
  do {
    if (lVar1 == 0) break;
    lVar1 = lVar1 + -1;
    bVar4 = *pbVar2 < *pbVar3;
    bVar6 = *pbVar2 == *pbVar3;
    pbVar2 = pbVar2 + (ulong)bVar7 * -2 + 1;
    pbVar3 = pbVar3 + (ulong)bVar7 * -2 + 1;
  } while (bVar6);
  bVar5 = false;
  bVar4 = (!bVar4 && !bVar6) == bVar4;
  if (!bVar4) {
    lVar1 = 6;
    pbVar2 = (byte *)param_1;
    pbVar3 = (byte *)"POSIX";
    do {
      if (lVar1 == 0) break;
      lVar1 = lVar1 + -1;
      bVar5 = *pbVar2 < *pbVar3;
      bVar4 = *pbVar2 == *pbVar3;
      pbVar2 = pbVar2 + (ulong)bVar7 * -2 + 1;
      pbVar3 = pbVar3 + (ulong)bVar7 * -2 + 1;
    } while (bVar4);
    if ((!bVar5 && !bVar4) != bVar5) {
                    /* try { // try from 00c2cf03 to 00c2cf1b has its CatchHandler @ 00c2cf23 */
      locale::facet::_S_create_c_locale(&local_28,param_1,(__locale_struct *)0x0);
      numpunct<char>::_M_initialize_numpunct((numpunct<char> *)this,local_28);
      locale::facet::_S_destroy_c_locale(&local_28);
    }
  }
  if (local_20 == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ==== entry=00c2cf50 name=FUN_00c2cf50 size=204 ====

void FUN_00c2cf50(numpunct<char> *param_1,undefined8 *param_2,long param_3)

{
  byte *pbVar1;
  long lVar2;
  byte *pbVar3;
  byte *pbVar4;
  long in_FS_OFFSET;
  bool bVar5;
  bool bVar6;
  bool bVar7;
  byte bVar8;
  __locale_struct *local_28;
  long local_20;
  
  bVar8 = 0;
  pbVar1 = (byte *)*param_2;
  local_20 = *(long *)(in_FS_OFFSET + 0x28);
  *(undefined8 *)(param_1 + 0x10) = 0;
  *(uint *)(param_1 + 8) = (uint)(param_3 != 0);
  *(undefined ***)param_1 = &PTR__numpunct_011b5510;
                    /* try { // try from 00c2cf91 to 00c2cf95 has its CatchHandler @ 00c2d028 */
  std::numpunct<char>::_M_initialize_numpunct(param_1,(__locale_struct *)0x0);
  lVar2 = 2;
  bVar5 = false;
  bVar7 = false;
  *(undefined ***)param_1 = &PTR__numpunct_byname_011b5558;
  pbVar3 = pbVar1;
  pbVar4 = &DAT_00ca9164;
  do {
    if (lVar2 == 0) break;
    lVar2 = lVar2 + -1;
    bVar5 = *pbVar3 < *pbVar4;
    bVar7 = *pbVar3 == *pbVar4;
    pbVar3 = pbVar3 + (ulong)bVar8 * -2 + 1;
    pbVar4 = pbVar4 + (ulong)bVar8 * -2 + 1;
  } while (bVar7);
  bVar6 = false;
  bVar5 = (!bVar5 && !bVar7) == bVar5;
  if (!bVar5) {
    lVar2 = 6;
    pbVar3 = pbVar1;
    pbVar4 = (byte *)"POSIX";
    do {
      if (lVar2 == 0) break;
      lVar2 = lVar2 + -1;
      bVar6 = *pbVar3 < *pbVar4;
      bVar5 = *pbVar3 == *pbVar4;
      pbVar3 = pbVar3 + (ulong)bVar8 * -2 + 1;
      pbVar4 = pbVar4 + (ulong)bVar8 * -2 + 1;
    } while (bVar5);
    if ((!bVar6 && !bVar5) != bVar6) {
                    /* try { // try from 00c2d003 to 00c2d01b has its CatchHandler @ 00c2d023 */
      std::locale::facet::_S_create_c_locale(&local_28,(char *)pbVar1,(__locale_struct *)0x0);
      std::numpunct<char>::_M_initialize_numpunct(param_1,local_28);
      std::locale::facet::_S_destroy_c_locale(&local_28);
    }
  }
  if (local_20 == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ==== entry=00c2d050 orig=FUN_00c2d050 size=26 name=num_get ====

/* std::num_get<char, std::istreambuf_iterator<char, std::char_traits<char> > >::num_get(unsigned
   long) */

void __thiscall
std::num_get<char,std::istreambuf_iterator<char,std::char_traits<char>>>::num_get
          (num_get<char,std::istreambuf_iterator<char,std::char_traits<char>>> *this,ulong param_1)

{
  *(uint *)(this + 8) = (uint)(param_1 != 0);
  *(undefined ***)this = &PTR__num_get_011b55a0;
  return;
}


// ==== entry=00c2d070 orig=FUN_00c2d070 size=6 name=get ====

/* std::num_get<char, std::istreambuf_iterator<char, std::char_traits<char> >
   >::get(std::istreambuf_iterator<char, std::char_traits<char> >, std::istreambuf_iterator<char,
   std::char_traits<char> >, std::ios_base&, std::_Ios_Iostate&, bool&) const */

void std::num_get<char,std::istreambuf_iterator<char,std::char_traits<char>>>::get(long *param_1)

{
                    /* WARNING: Could not recover jumptable at 0x00c2d073. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*param_1 + 0x10))();
  return;
}


// ==== entry=00c2d080 orig=FUN_00c2d080 size=6 name=get ====

/* std::num_get<char, std::istreambuf_iterator<char, std::char_traits<char> >
   >::get(std::istreambuf_iterator<char, std::char_traits<char> >, std::istreambuf_iterator<char,
   std::char_traits<char> >, std::ios_base&, std::_Ios_Iostate&, float&) const */

void std::num_get<char,std::istreambuf_iterator<char,std::char_traits<char>>>::get(long *param_1)

{
                    /* WARNING: Could not recover jumptable at 0x00c2d083. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*param_1 + 0x48))();
  return;
}


