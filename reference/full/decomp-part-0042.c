// Ghidra 12.1.4 decompiled — WindTerm 2.7.0 (sha256 9491b87e…) part 42
// ==== entry=00c6bc20 name=FUN_00c6bc20 size=8 ====

void FUN_00c6bc20(ctype_byname<wchar_t> *param_1,undefined8 *param_2,ulong param_3)

{
  std::ctype_byname<wchar_t>::ctype_byname(param_1,(char *)*param_2,param_3);
  return;
}


// ==== entry=00c6bc30 name=FUN_00c6bc30 size=119 ====

void FUN_00c6bc30(codecvt<wchar_t,char,__mbstate_t> *param_1,undefined8 *param_2,ulong param_3)

{
  byte *pbVar1;
  long lVar2;
  byte *pbVar3;
  byte *pbVar4;
  bool bVar5;
  bool bVar6;
  bool bVar7;
  byte bVar8;
  
  bVar8 = 0;
  pbVar1 = (byte *)*param_2;
  std::codecvt<wchar_t,char,__mbstate_t>::codecvt(param_1,param_3);
  lVar2 = 2;
  bVar5 = false;
  bVar7 = false;
  *(undefined ***)param_1 = &PTR__codecvt_byname_011b6e58;
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
                    /* try { // try from 00c6bc97 to 00c6bca8 has its CatchHandler @ 00c6bcae */
      std::locale::facet::_S_destroy_c_locale((__locale_struct **)(param_1 + 0x10));
      std::locale::facet::_S_create_c_locale
                ((__locale_struct **)(param_1 + 0x10),(char *)pbVar1,(__locale_struct *)0x0);
      return;
    }
  }
  return;
}


// ==== entry=00c6bcd0 name=FUN_00c6bcd0 size=50 ====

void FUN_00c6bcd0(undefined8 *param_1,long param_2)

{
  undefined8 uVar1;
  
  *(uint *)(param_1 + 1) = (uint)(param_2 != 0);
  *param_1 = &PTR_FUN_011b75e8;
                    /* try { // try from 00c6bcf2 to 00c6bcf6 has its CatchHandler @ 00c6bd02 */
  uVar1 = std::locale::facet::_S_get_c_locale();
  param_1[2] = uVar1;
  return;
}


// ==== entry=00c6bd20 name=FUN_00c6bd20 size=58 ====

void FUN_00c6bd20(undefined8 *param_1,__locale_struct *param_2,long param_3)

{
  undefined8 uVar1;
  __locale_struct *local_10;
  
  *(uint *)(param_1 + 1) = (uint)(param_3 != 0);
  *param_1 = &PTR_FUN_011b75e8;
  local_10 = param_2;
  uVar1 = std::locale::facet::_S_clone_c_locale(&local_10);
  param_1[2] = uVar1;
  return;
}


// ==== entry=00c6bd60 name=FUN_00c6bd60 size=6 ====

void FUN_00c6bd60(long *param_1)

{
                    /* WARNING: Could not recover jumptable at 0x00c6bd63. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*param_1 + 0x10))();
  return;
}


// ==== entry=00c6bd70 name=FUN_00c6bd70 size=60 ====

undefined8 FUN_00c6bd70(undefined8 param_1,long *param_2)

{
  long lVar1;
  long in_FS_OFFSET;
  
  lVar1 = *(long *)(in_FS_OFFSET + 0x28);
  (**(code **)(*param_2 + 0x18))();
  if (lVar1 == *(long *)(in_FS_OFFSET + 0x28)) {
    return param_1;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ==== entry=00c6bdb0 name=FUN_00c6bdb0 size=6 ====

void FUN_00c6bdb0(long *param_1)

{
                    /* WARNING: Could not recover jumptable at 0x00c6bdb3. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*param_1 + 0x20))();
  return;
}


// ==== entry=00c6bdc0 name=FUN_00c6bdc0 size=163 ====

void FUN_00c6bdc0(undefined8 *param_1,byte *param_2,long param_3)

{
  undefined8 uVar1;
  long lVar2;
  byte *pbVar3;
  byte *pbVar4;
  bool bVar5;
  bool bVar6;
  bool bVar7;
  byte bVar8;
  
  bVar8 = 0;
  *(uint *)(param_1 + 1) = (uint)(param_3 != 0);
  *param_1 = &PTR_FUN_011b75e8;
                    /* try { // try from 00c6bde9 to 00c6bded has its CatchHandler @ 00c6be69 */
  uVar1 = std::locale::facet::_S_get_c_locale();
  param_1[2] = uVar1;
  lVar2 = 2;
  bVar5 = false;
  bVar7 = false;
  *param_1 = &PTR_FUN_011b7620;
  pbVar3 = param_2;
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
    pbVar3 = param_2;
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
                    /* try { // try from 00c6be47 to 00c6be58 has its CatchHandler @ 00c6be64 */
      std::locale::facet::_S_destroy_c_locale((__locale_struct **)(param_1 + 2));
      std::locale::facet::_S_create_c_locale
                ((__locale_struct **)(param_1 + 2),(char *)param_2,(__locale_struct *)0x0);
      return;
    }
  }
  return;
}


// ==== entry=00c6be90 name=FUN_00c6be90 size=163 ====

void FUN_00c6be90(undefined8 *param_1,undefined8 *param_2,long param_3)

{
  byte *pbVar1;
  undefined8 uVar2;
  long lVar3;
  byte *pbVar4;
  byte *pbVar5;
  bool bVar6;
  bool bVar7;
  bool bVar8;
  byte bVar9;
  
  bVar9 = 0;
  pbVar1 = (byte *)*param_2;
  *(uint *)(param_1 + 1) = (uint)(param_3 != 0);
  *param_1 = &PTR_FUN_011b75e8;
                    /* try { // try from 00c6beb9 to 00c6bebd has its CatchHandler @ 00c6bf39 */
  uVar2 = std::locale::facet::_S_get_c_locale();
  param_1[2] = uVar2;
  lVar3 = 2;
  bVar6 = false;
  bVar8 = false;
  *param_1 = &PTR_FUN_011b7620;
  pbVar4 = pbVar1;
  pbVar5 = &DAT_00ca9164;
  do {
    if (lVar3 == 0) break;
    lVar3 = lVar3 + -1;
    bVar6 = *pbVar4 < *pbVar5;
    bVar8 = *pbVar4 == *pbVar5;
    pbVar4 = pbVar4 + (ulong)bVar9 * -2 + 1;
    pbVar5 = pbVar5 + (ulong)bVar9 * -2 + 1;
  } while (bVar8);
  bVar7 = false;
  bVar6 = (!bVar6 && !bVar8) == bVar6;
  if (!bVar6) {
    lVar3 = 6;
    pbVar4 = pbVar1;
    pbVar5 = (byte *)"POSIX";
    do {
      if (lVar3 == 0) break;
      lVar3 = lVar3 + -1;
      bVar7 = *pbVar4 < *pbVar5;
      bVar6 = *pbVar4 == *pbVar5;
      pbVar4 = pbVar4 + (ulong)bVar9 * -2 + 1;
      pbVar5 = pbVar5 + (ulong)bVar9 * -2 + 1;
    } while (bVar6);
    if ((!bVar7 && !bVar6) != bVar7) {
                    /* try { // try from 00c6bf17 to 00c6bf28 has its CatchHandler @ 00c6bf34 */
      std::locale::facet::_S_destroy_c_locale((__locale_struct **)(param_1 + 2));
      std::locale::facet::_S_create_c_locale
                ((__locale_struct **)(param_1 + 2),(char *)pbVar1,(__locale_struct *)0x0);
      return;
    }
  }
  return;
}


// ==== entry=00c6bf60 name=FUN_00c6bf60 size=76 ====

void FUN_00c6bf60(long *param_1)

{
  ulong uVar1;
  long lVar2;
  
  uVar1 = std::locale::id::_M_id((id *)&DAT_011c5500);
  if ((uVar1 < *(ulong *)(*param_1 + 0x10)) &&
     (lVar2 = *(long *)(*(long *)(*param_1 + 8) + uVar1 * 8), lVar2 != 0)) {
    lVar2 = __dynamic_cast(lVar2,&std::locale::facet::typeinfo,&PTR_PTR_011b7408,0);
    if (lVar2 != 0) {
      return;
    }
                    /* WARNING: Subroutine does not return */
    __cxa_bad_cast();
  }
                    /* WARNING: Subroutine does not return */
  std::__throw_bad_cast();
}


// ==== entry=00c6bfb0 name=FUN_00c6bfb0 size=76 ====

void FUN_00c6bfb0(long *param_1)

{
  ulong uVar1;
  long lVar2;
  
  uVar1 = std::locale::id::_M_id((id *)&DAT_011c5518);
  if ((uVar1 < *(ulong *)(*param_1 + 0x10)) &&
     (lVar2 = *(long *)(*(long *)(*param_1 + 8) + uVar1 * 8), lVar2 != 0)) {
    lVar2 = __dynamic_cast(lVar2,&std::locale::facet::typeinfo,&PTR_PTR_011b7438,0);
    if (lVar2 != 0) {
      return;
    }
                    /* WARNING: Subroutine does not return */
    __cxa_bad_cast();
  }
                    /* WARNING: Subroutine does not return */
  std::__throw_bad_cast();
}


// ==== entry=00c6c000 name=FUN_00c6c000 size=76 ====

void FUN_00c6c000(long *param_1)

{
  ulong uVar1;
  long lVar2;
  
  uVar1 = std::locale::id::_M_id((id *)&DAT_011c5530);
  if ((uVar1 < *(ulong *)(*param_1 + 0x10)) &&
     (lVar2 = *(long *)(*(long *)(*param_1 + 8) + uVar1 * 8), lVar2 != 0)) {
    lVar2 = __dynamic_cast(lVar2,&std::locale::facet::typeinfo,&PTR_PTR_011b7468,0);
    if (lVar2 != 0) {
      return;
    }
                    /* WARNING: Subroutine does not return */
    __cxa_bad_cast();
  }
                    /* WARNING: Subroutine does not return */
  std::__throw_bad_cast();
}


// ==== entry=00c6c050 name=FUN_00c6c050 size=76 ====

void FUN_00c6c050(long *param_1)

{
  ulong uVar1;
  long lVar2;
  
  uVar1 = std::locale::id::_M_id((id *)&DAT_011c5538);
  if ((uVar1 < *(ulong *)(*param_1 + 0x10)) &&
     (lVar2 = *(long *)(*(long *)(*param_1 + 8) + uVar1 * 8), lVar2 != 0)) {
    lVar2 = __dynamic_cast(lVar2,&std::locale::facet::typeinfo,&PTR_PTR_011b74a0,0);
    if (lVar2 != 0) {
      return;
    }
                    /* WARNING: Subroutine does not return */
    __cxa_bad_cast();
  }
                    /* WARNING: Subroutine does not return */
  std::__throw_bad_cast();
}


// ==== entry=00c6c0a0 name=FUN_00c6c0a0 size=76 ====

void FUN_00c6c0a0(long *param_1)

{
  ulong uVar1;
  long lVar2;
  
  uVar1 = std::locale::id::_M_id((id *)&DAT_011c5520);
  if ((uVar1 < *(ulong *)(*param_1 + 0x10)) &&
     (lVar2 = *(long *)(*(long *)(*param_1 + 8) + uVar1 * 8), lVar2 != 0)) {
    lVar2 = __dynamic_cast(lVar2,&std::locale::facet::typeinfo,&PTR_PTR_011b7558,0);
    if (lVar2 != 0) {
      return;
    }
                    /* WARNING: Subroutine does not return */
    __cxa_bad_cast();
  }
                    /* WARNING: Subroutine does not return */
  std::__throw_bad_cast();
}


// ==== entry=00c6c0f0 name=FUN_00c6c0f0 size=76 ====

void FUN_00c6c0f0(long *param_1)

{
  ulong uVar1;
  long lVar2;
  
  uVar1 = std::locale::id::_M_id((id *)&DAT_011c5528);
  if ((uVar1 < *(ulong *)(*param_1 + 0x10)) &&
     (lVar2 = *(long *)(*(long *)(*param_1 + 8) + uVar1 * 8), lVar2 != 0)) {
    lVar2 = __dynamic_cast(lVar2,&std::locale::facet::typeinfo,&PTR_PTR_011b7540,0);
    if (lVar2 != 0) {
      return;
    }
                    /* WARNING: Subroutine does not return */
    __cxa_bad_cast();
  }
                    /* WARNING: Subroutine does not return */
  std::__throw_bad_cast();
}


// ==== entry=00c6c140 name=FUN_00c6c140 size=76 ====

void FUN_00c6c140(long *param_1)

{
  ulong uVar1;
  long lVar2;
  
  uVar1 = std::locale::id::_M_id((id *)&DAT_011c5510);
  if ((uVar1 < *(ulong *)(*param_1 + 0x10)) &&
     (lVar2 = *(long *)(*(long *)(*param_1 + 8) + uVar1 * 8), lVar2 != 0)) {
    lVar2 = __dynamic_cast(lVar2,&std::locale::facet::typeinfo,&PTR_PTR_011b7570,0);
    if (lVar2 != 0) {
      return;
    }
                    /* WARNING: Subroutine does not return */
    __cxa_bad_cast();
  }
                    /* WARNING: Subroutine does not return */
  std::__throw_bad_cast();
}


// ==== entry=00c6c190 name=FUN_00c6c190 size=76 ====

void FUN_00c6c190(long *param_1)

{
  ulong uVar1;
  long lVar2;
  
  uVar1 = std::locale::id::_M_id((id *)&DAT_011c5508);
  if ((uVar1 < *(ulong *)(*param_1 + 0x10)) &&
     (lVar2 = *(long *)(*(long *)(*param_1 + 8) + uVar1 * 8), lVar2 != 0)) {
    lVar2 = __dynamic_cast(lVar2,&std::locale::facet::typeinfo,&PTR_PTR_011b74d8,0);
    if (lVar2 != 0) {
      return;
    }
                    /* WARNING: Subroutine does not return */
    __cxa_bad_cast();
  }
                    /* WARNING: Subroutine does not return */
  std::__throw_bad_cast();
}


// ==== entry=00c6c1e0 name=FUN_00c6c1e0 size=72 ====

bool FUN_00c6c1e0(long *param_1)

{
  ulong uVar1;
  long lVar2;
  bool bVar3;
  
  uVar1 = std::locale::id::_M_id((id *)&DAT_011c5500);
  bVar3 = false;
  if ((uVar1 < *(ulong *)(*param_1 + 0x10)) &&
     (lVar2 = *(long *)(*(long *)(*param_1 + 8) + uVar1 * 8), lVar2 != 0)) {
    lVar2 = __dynamic_cast(lVar2,&std::locale::facet::typeinfo,&PTR_PTR_011b7408,0);
    bVar3 = lVar2 != 0;
  }
  return bVar3;
}


// ==== entry=00c6c230 name=FUN_00c6c230 size=72 ====

bool FUN_00c6c230(long *param_1)

{
  ulong uVar1;
  long lVar2;
  bool bVar3;
  
  uVar1 = std::locale::id::_M_id((id *)&DAT_011c5518);
  bVar3 = false;
  if ((uVar1 < *(ulong *)(*param_1 + 0x10)) &&
     (lVar2 = *(long *)(*(long *)(*param_1 + 8) + uVar1 * 8), lVar2 != 0)) {
    lVar2 = __dynamic_cast(lVar2,&std::locale::facet::typeinfo,&PTR_PTR_011b7438,0);
    bVar3 = lVar2 != 0;
  }
  return bVar3;
}


// ==== entry=00c6c280 name=FUN_00c6c280 size=72 ====

bool FUN_00c6c280(long *param_1)

{
  ulong uVar1;
  long lVar2;
  bool bVar3;
  
  uVar1 = std::locale::id::_M_id((id *)&DAT_011c5538);
  bVar3 = false;
  if ((uVar1 < *(ulong *)(*param_1 + 0x10)) &&
     (lVar2 = *(long *)(*(long *)(*param_1 + 8) + uVar1 * 8), lVar2 != 0)) {
    lVar2 = __dynamic_cast(lVar2,&std::locale::facet::typeinfo,&PTR_PTR_011b74a0,0);
    bVar3 = lVar2 != 0;
  }
  return bVar3;
}


// ==== entry=00c6c2d0 name=FUN_00c6c2d0 size=72 ====

bool FUN_00c6c2d0(long *param_1)

{
  ulong uVar1;
  long lVar2;
  bool bVar3;
  
  uVar1 = std::locale::id::_M_id((id *)&DAT_011c5520);
  bVar3 = false;
  if ((uVar1 < *(ulong *)(*param_1 + 0x10)) &&
     (lVar2 = *(long *)(*(long *)(*param_1 + 8) + uVar1 * 8), lVar2 != 0)) {
    lVar2 = __dynamic_cast(lVar2,&std::locale::facet::typeinfo,&PTR_PTR_011b7558,0);
    bVar3 = lVar2 != 0;
  }
  return bVar3;
}


// ==== entry=00c6c320 name=FUN_00c6c320 size=72 ====

bool FUN_00c6c320(long *param_1)

{
  ulong uVar1;
  long lVar2;
  bool bVar3;
  
  uVar1 = std::locale::id::_M_id((id *)&DAT_011c5528);
  bVar3 = false;
  if ((uVar1 < *(ulong *)(*param_1 + 0x10)) &&
     (lVar2 = *(long *)(*(long *)(*param_1 + 8) + uVar1 * 8), lVar2 != 0)) {
    lVar2 = __dynamic_cast(lVar2,&std::locale::facet::typeinfo,&PTR_PTR_011b7540,0);
    bVar3 = lVar2 != 0;
  }
  return bVar3;
}


// ==== entry=00c6c370 name=FUN_00c6c370 size=72 ====

bool FUN_00c6c370(long *param_1)

{
  ulong uVar1;
  long lVar2;
  bool bVar3;
  
  uVar1 = std::locale::id::_M_id((id *)&DAT_011c5510);
  bVar3 = false;
  if ((uVar1 < *(ulong *)(*param_1 + 0x10)) &&
     (lVar2 = *(long *)(*(long *)(*param_1 + 8) + uVar1 * 8), lVar2 != 0)) {
    lVar2 = __dynamic_cast(lVar2,&std::locale::facet::typeinfo,&PTR_PTR_011b7570,0);
    bVar3 = lVar2 != 0;
  }
  return bVar3;
}


// ==== entry=00c6c3c0 name=FUN_00c6c3c0 size=72 ====

bool FUN_00c6c3c0(long *param_1)

{
  ulong uVar1;
  long lVar2;
  bool bVar3;
  
  uVar1 = std::locale::id::_M_id((id *)&DAT_011c5508);
  bVar3 = false;
  if ((uVar1 < *(ulong *)(*param_1 + 0x10)) &&
     (lVar2 = *(long *)(*(long *)(*param_1 + 8) + uVar1 * 8), lVar2 != 0)) {
    lVar2 = __dynamic_cast(lVar2,&std::locale::facet::typeinfo,&PTR_PTR_011b74d8,0);
    bVar3 = lVar2 != 0;
  }
  return bVar3;
}


// ==== entry=00c6c410 orig=FUN_00c6c410 size=4776 name=money_get_parse_wpattern ====

wstreambuf *
money_get_parse_wpattern
          (undefined8 param_1,wstreambuf *param_2,ulong param_3,long *param_4,undefined8 param_5,
          long param_6,uint *param_7,int *param_8,wchar_t *param_9)

{
  wchar_t wVar1;
  long lVar2;
  char cVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  wchar_t wVar7;
  __timepunct *p_Var8;
  ctype *pcVar9;
  size_t sVar10;
  ulong uVar11;
  ulong uVar12;
  ulong uVar13;
  long in_FS_OFFSET;
  bool bVar14;
  bool bVar15;
  undefined1 auVar16 [16];
  undefined1 auVar17 [12];
  undefined4 local_230;
  undefined4 local_200;
  undefined4 local_1f0;
  undefined4 local_1e0;
  undefined4 local_1d0;
  undefined4 local_1c0;
  undefined4 local_1b0;
  undefined4 local_1a0;
  undefined4 local_190;
  undefined4 local_180;
  undefined4 local_170;
  undefined4 local_160;
  undefined4 local_130;
  undefined4 local_120;
  undefined4 local_110;
  undefined4 local_100;
  undefined4 local_f0;
  undefined4 local_e0;
  long *local_d8;
  undefined8 local_d0;
  wstreambuf *local_c8;
  ulong local_c0;
  uint local_b4;
  int local_b0;
  int local_ac;
  undefined8 local_a8;
  undefined8 local_a0;
  undefined8 local_98;
  undefined8 local_90;
  undefined8 local_88;
  undefined8 local_80;
  undefined8 local_78;
  undefined8 local_70;
  undefined8 local_68;
  undefined8 local_60;
  undefined8 local_58;
  undefined8 local_50;
  long local_40;
  
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  local_d8 = param_4;
  local_d0 = param_5;
  local_c8 = param_2;
  local_c0 = param_3;
  p_Var8 = std::use_facet<std::__timepunct<wchar_t>>((locale *)(param_6 + 0xd0));
  pcVar9 = std::use_facet<std::ctype<wchar_t>>((locale *)(param_6 + 0xd0));
  sVar10 = wcslen(param_9);
  uVar12 = local_c0 & 0xffffffff;
  local_b4 = 0;
  uVar13 = 0;
LAB_00c6c4f0:
  bVar14 = (int)uVar12 == -1;
  if (local_c8 != (wstreambuf *)0x0 && bVar14) {
    if (*(int **)(local_c8 + 0x10) < *(int **)(local_c8 + 0x18)) {
      iVar6 = **(int **)(local_c8 + 0x10);
    }
    else {
      iVar6 = (**(code **)(*(long *)local_c8 + 0x48))();
    }
    bVar14 = false;
    if (iVar6 == -1) {
      local_c8 = (wstreambuf *)0x0;
      bVar14 = true;
    }
  }
  bVar15 = (int)local_d0 == -1;
  if (local_d8 != (long *)0x0 && bVar15) {
    if ((int *)local_d8[2] < (int *)local_d8[3]) {
      iVar6 = *(int *)local_d8[2];
    }
    else {
      iVar6 = (**(code **)(*local_d8 + 0x48))();
    }
    bVar15 = false;
    if (iVar6 != -1) goto LAB_00c6c52d;
    local_d8 = (long *)0x0;
    if (bVar14 != true) goto LAB_00c6c53d;
LAB_00c6c648:
    if ((uVar13 == sVar10) && (local_b4 == 0)) goto LAB_00c6c65b;
LAB_00c6c653:
    *param_7 = *param_7 | 4;
LAB_00c6c65b:
    if (local_40 == *(long *)(in_FS_OFFSET + 0x28)) {
      return local_c8;
    }
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
LAB_00c6c52d:
  if (bVar14 == bVar15) goto LAB_00c6c648;
LAB_00c6c53d:
  if (sVar10 <= uVar13) goto LAB_00c6c648;
  if (local_b4 != 0) goto LAB_00c6c653;
  uVar11 = uVar13 + 1;
  cVar3 = (**(code **)(*(long *)pcVar9 + 0x60))(pcVar9,param_9[uVar13],0);
  if (cVar3 != '%') {
    wVar1 = param_9[uVar13];
    wVar7 = (wchar_t)local_c0;
    uVar13 = uVar11;
    if (((wchar_t)local_c0 == L'\xffffffff') && (local_c8 != (wstreambuf *)0x0)) {
      if (*(wchar_t **)(local_c8 + 0x10) < *(wchar_t **)(local_c8 + 0x18)) {
        wVar7 = **(wchar_t **)(local_c8 + 0x10);
      }
      else {
        wVar7 = (**(code **)(*(long *)local_c8 + 0x48))();
      }
      if (wVar7 == L'\xffffffff') {
        local_c8 = (wstreambuf *)0x0;
        wVar7 = L'\xffffffff';
        goto LAB_00c6c5e1;
      }
      if (wVar1 == wVar7) goto LAB_00c6c770;
LAB_00c6c5ea:
      local_b4 = local_b4 | 4;
      uVar12 = local_c0 & 0xffffffff;
    }
    else {
LAB_00c6c5e1:
      if (wVar1 != wVar7) goto LAB_00c6c5ea;
LAB_00c6c770:
      if (*(ulong *)(local_c8 + 0x10) < *(ulong *)(local_c8 + 0x18)) {
        *(ulong *)(local_c8 + 0x10) = *(ulong *)(local_c8 + 0x10) + 4;
      }
      else {
        (**(code **)(*(long *)local_c8 + 0x50))();
      }
      local_c0 = CONCAT44(local_c0._4_4_,0xffffffff);
      uVar12 = 0xffffffff;
    }
    goto LAB_00c6c4f0;
  }
  cVar3 = (**(code **)(*(long *)pcVar9 + 0x60))(pcVar9,param_9[uVar13 + 1],0);
  local_b0 = 0;
  if ((cVar3 == 'E') || (cVar3 == 'O')) {
    uVar11 = uVar13 + 2;
    cVar3 = (**(code **)(*(long *)pcVar9 + 0x60))(pcVar9,param_9[uVar13 + 2],0);
  }
  switch(cVar3) {
  case 'A':
    lVar2 = *(long *)(p_Var8 + 0x10);
    local_a8 = *(undefined8 *)(lVar2 + 0x58);
    local_a0 = *(undefined8 *)(lVar2 + 0x60);
    local_98 = *(undefined8 *)(lVar2 + 0x68);
    local_90 = *(undefined8 *)(lVar2 + 0x70);
    local_88 = *(undefined8 *)(lVar2 + 0x78);
    local_80 = *(undefined8 *)(lVar2 + 0x80);
    local_78 = *(undefined8 *)(lVar2 + 0x88);
    auVar16 = FUN_00c6a740(param_1,local_c8,local_c0,local_d8,local_d0,&local_b0,&local_a8,7,param_6
                           ,&local_b4);
    local_f0 = auVar16._8_4_;
    local_c0 = CONCAT44(local_c0._4_4_,local_f0);
    goto joined_r0x00c6d27a;
  case 'B':
    lVar2 = *(long *)(p_Var8 + 0x10);
    local_a8 = *(undefined8 *)(lVar2 + 200);
    local_a0 = *(undefined8 *)(lVar2 + 0xd0);
    local_98 = *(undefined8 *)(lVar2 + 0xd8);
    local_90 = *(undefined8 *)(lVar2 + 0xe0);
    local_88 = *(undefined8 *)(lVar2 + 0xe8);
    local_80 = *(undefined8 *)(lVar2 + 0xf0);
    local_78 = *(undefined8 *)(lVar2 + 0xf8);
    local_70 = *(undefined8 *)(lVar2 + 0x100);
    local_68 = *(undefined8 *)(lVar2 + 0x108);
    local_60 = *(undefined8 *)(lVar2 + 0x110);
    local_58 = *(undefined8 *)(lVar2 + 0x118);
    local_50 = *(undefined8 *)(lVar2 + 0x120);
    auVar16 = FUN_00c6a740(param_1,local_c8,local_c0,local_d8,local_d0,&local_b0,&local_a8,0xc,
                           param_6,&local_b4);
    local_110 = auVar16._8_4_;
    local_c0 = CONCAT44(local_c0._4_4_,local_110);
    goto joined_r0x00c6d3bf;
  case 'C':
  case 'Y':
  case 'y':
    auVar16 = time_get_do_get_fmt_wide
                        (param_1,local_c8,local_c0,local_d8,local_d0,&local_b0,0,9999,4,param_6,
                         &local_b4);
    local_c8 = auVar16._0_8_;
    local_200 = auVar16._8_4_;
    uVar12 = auVar16._8_8_ & 0xffffffff;
    local_c0 = CONCAT44(local_c0._4_4_,local_200);
    if (local_b4 == 0) {
      iVar6 = local_b0 + -0x76c;
      if (local_b0 < 0) {
        iVar6 = local_b0 + 100;
      }
      param_8[5] = iVar6;
    }
    break;
  case 'D':
    (**(code **)(*(long *)pcVar9 + 0x58))(pcVar9,"%m/%d/%y",&DAT_00d95893,&local_a8);
    auVar16 = money_get_parse_wpattern
                        (param_1,local_c8,local_c0,local_d8,local_d0,param_6,&local_b4,param_8,
                         &local_a8);
    local_c8 = auVar16._0_8_;
    local_160 = auVar16._8_4_;
    uVar12 = auVar16._8_8_ & 0xffffffff;
    local_c0 = CONCAT44(local_c0._4_4_,local_160);
    break;
  default:
    goto switchD_00c6c5ba_caseD_45;
  case 'H':
    auVar16 = time_get_do_get_fmt_wide
                        (param_1,local_c8,local_c0,local_d8,local_d0,&local_b0,0,0x17,2,param_6,
                         &local_b4);
    local_170 = auVar16._8_4_;
    local_c0 = CONCAT44(local_c0._4_4_,local_170);
    goto joined_r0x00c6ccc1;
  case 'I':
    auVar16 = time_get_do_get_fmt_wide
                        (param_1,local_c8,local_c0,local_d8,local_d0,&local_b0,1,0xc,2,param_6,
                         &local_b4);
    local_180 = auVar16._8_4_;
    local_c0 = CONCAT44(local_c0._4_4_,local_180);
joined_r0x00c6ccc1:
    local_c8 = auVar16._0_8_;
    uVar12 = auVar16._8_8_ & 0xffffffff;
    if (local_b4 == 0) {
      param_8[2] = local_b0;
    }
    break;
  case 'M':
    auVar16 = time_get_do_get_fmt_wide
                        (param_1,local_c8,local_c0,local_d8,local_d0,&local_b0,0,0x3b,2,param_6,
                         &local_b4);
    local_c8 = auVar16._0_8_;
    local_1a0 = auVar16._8_4_;
    uVar12 = auVar16._8_8_ & 0xffffffff;
    local_c0 = CONCAT44(local_c0._4_4_,local_1a0);
    if (local_b4 == 0) {
      param_8[1] = local_b0;
    }
    break;
  case 'R':
    (**(code **)(*(long *)pcVar9 + 0x58))(pcVar9,&DAT_00d95893,&DAT_00d95899,&local_a8);
    auVar16 = money_get_parse_wpattern
                        (param_1,local_c8,local_c0,local_d8,local_d0,param_6,&local_b4,param_8,
                         &local_a8);
    local_c8 = auVar16._0_8_;
    local_1b0 = auVar16._8_4_;
    uVar12 = auVar16._8_8_ & 0xffffffff;
    local_c0 = CONCAT44(local_c0._4_4_,local_1b0);
    break;
  case 'S':
    auVar16 = time_get_do_get_fmt_wide
                        (param_1,local_c8,local_c0,local_d8,local_d0,&local_b0,0,0x3c,2,param_6,
                         &local_b4);
    local_c8 = auVar16._0_8_;
    local_1c0 = auVar16._8_4_;
    uVar12 = auVar16._8_8_ & 0xffffffff;
    local_c0 = CONCAT44(local_c0._4_4_,local_1c0);
    if (local_b4 == 0) {
      *param_8 = local_b0;
    }
    break;
  case 'T':
    (**(code **)(*(long *)pcVar9 + 0x58))(pcVar9,&DAT_00c8ce9b,&DAT_00c8cea4,&local_a8);
    auVar16 = money_get_parse_wpattern
                        (param_1,local_c8,local_c0,local_d8,local_d0,param_6,&local_b4,param_8,
                         &local_a8);
    local_c8 = auVar16._0_8_;
    local_1d0 = auVar16._8_4_;
    uVar12 = auVar16._8_8_ & 0xffffffff;
    local_c0 = CONCAT44(local_c0._4_4_,local_1d0);
    break;
  case 'X':
    auVar16 = money_get_parse_wpattern
                        (param_1,local_c8,local_c0,local_d8,local_d0,param_6,&local_b4,param_8,
                         *(undefined8 *)(*(long *)(p_Var8 + 0x10) + 0x20));
    local_c8 = auVar16._0_8_;
    local_1f0 = auVar16._8_4_;
    uVar12 = auVar16._8_8_ & 0xffffffff;
    local_c0 = CONCAT44(local_c0._4_4_,local_1f0);
    break;
  case 'Z':
    uVar5 = FUN_00c61d10(&local_c8,local_c0 & 0xffffffff);
    cVar3 = (**(code **)(*(long *)pcVar9 + 0x10))(pcVar9,0x100,uVar5);
    if (cVar3 == '\0') goto switchD_00c6c5ba_caseD_45;
    auVar17 = FUN_00c6a740(param_1,local_c8,local_c0,local_d8,local_d0,&local_ac,
                           std::__timepunct_cache<wchar_t>::_S_timezones,0xe,param_6,&local_b4);
    local_c8 = auVar17._0_8_;
    local_c0 = CONCAT44(local_c0._4_4_,auVar17._8_4_);
    cVar3 = FUN_00c56c30(&local_c8,&local_d8);
    uVar12 = local_c0 & 0xffffffff;
    if ((cVar3 != '\0') || (local_b4 != 0 || local_ac != 0)) break;
    iVar6 = FUN_00c61d10(&local_c8);
    iVar4 = (**(code **)(*(long *)pcVar9 + 0x50))(pcVar9,0x2d);
    if (iVar6 == iVar4) {
LAB_00c6d0b3:
      auVar17 = time_get_do_get_fmt_wide
                          (param_1,local_c8,local_c0,local_d8,local_d0,&local_ac,0,0x17,2,param_6,
                           &local_b4);
      local_c8 = auVar17._0_8_;
      local_c0 = CONCAT44(local_c0._4_4_,auVar17._8_4_);
      auVar16 = time_get_do_get_fmt_wide
                          (param_1,local_c8,local_c0,local_d8,local_d0,&local_ac,0,0x3b,2,param_6,
                           &local_b4);
      local_c8 = auVar16._0_8_;
      local_230 = auVar16._8_4_;
      uVar12 = auVar16._8_8_ & 0xffffffff;
      local_c0 = CONCAT44(local_c0._4_4_,local_230);
      break;
    }
    iVar6 = FUN_00c61d10(&local_c8,local_c0 & 0xffffffff);
    iVar4 = (**(code **)(*(long *)pcVar9 + 0x50))(pcVar9,0x2b);
    if (iVar6 == iVar4) goto LAB_00c6d0b3;
    goto LAB_00c6c71e;
  case 'a':
    lVar2 = *(long *)(p_Var8 + 0x10);
    local_a8 = *(undefined8 *)(lVar2 + 0x90);
    local_a0 = *(undefined8 *)(lVar2 + 0x98);
    local_98 = *(undefined8 *)(lVar2 + 0xa0);
    local_90 = *(undefined8 *)(lVar2 + 0xa8);
    local_88 = *(undefined8 *)(lVar2 + 0xb0);
    local_80 = *(undefined8 *)(lVar2 + 0xb8);
    local_78 = *(undefined8 *)(lVar2 + 0xc0);
    auVar16 = FUN_00c6a740(param_1,local_c8,local_c0,local_d8,local_d0,&local_b0,&local_a8,7,param_6
                           ,&local_b4);
    local_e0 = auVar16._8_4_;
    local_c0 = CONCAT44(local_c0._4_4_,local_e0);
joined_r0x00c6d27a:
    local_c8 = auVar16._0_8_;
    uVar12 = auVar16._8_8_ & 0xffffffff;
    if (local_b4 == 0) {
      param_8[6] = local_b0;
    }
    break;
  case 'b':
  case 'h':
    lVar2 = *(long *)(p_Var8 + 0x10);
    local_a8 = *(undefined8 *)(lVar2 + 0x128);
    local_a0 = *(undefined8 *)(lVar2 + 0x130);
    local_98 = *(undefined8 *)(lVar2 + 0x138);
    local_90 = *(undefined8 *)(lVar2 + 0x140);
    local_88 = *(undefined8 *)(lVar2 + 0x148);
    local_80 = *(undefined8 *)(lVar2 + 0x150);
    local_78 = *(undefined8 *)(lVar2 + 0x158);
    local_70 = *(undefined8 *)(lVar2 + 0x160);
    local_68 = *(undefined8 *)(lVar2 + 0x168);
    local_60 = *(undefined8 *)(lVar2 + 0x170);
    local_58 = *(undefined8 *)(lVar2 + 0x178);
    local_50 = *(undefined8 *)(lVar2 + 0x180);
    auVar16 = FUN_00c6a740(param_1,local_c8,local_c0,local_d8,local_d0,&local_b0,&local_a8,0xc,
                           param_6,&local_b4);
    local_100 = auVar16._8_4_;
    local_c0 = CONCAT44(local_c0._4_4_,local_100);
joined_r0x00c6d3bf:
    local_c8 = auVar16._0_8_;
    uVar12 = auVar16._8_8_ & 0xffffffff;
    if (local_b4 == 0) {
      param_8[4] = local_b0;
    }
    break;
  case 'c':
    auVar16 = money_get_parse_wpattern
                        (param_1,local_c8,local_c0,local_d8,local_d0,param_6,&local_b4,param_8,
                         *(undefined8 *)(*(long *)(p_Var8 + 0x10) + 0x30));
    local_c8 = auVar16._0_8_;
    local_120 = auVar16._8_4_;
    uVar12 = auVar16._8_8_ & 0xffffffff;
    local_c0 = CONCAT44(local_c0._4_4_,local_120);
    break;
  case 'd':
    auVar16 = time_get_do_get_fmt_wide
                        (param_1,local_c8,local_c0,local_d8,local_d0,&local_b0,1,0x1f,2,param_6,
                         &local_b4);
    local_130 = auVar16._8_4_;
    local_c0 = CONCAT44(local_c0._4_4_,local_130);
    goto joined_r0x00c6d591;
  case 'e':
    uVar5 = FUN_00c61d10(&local_c8,local_c0 & 0xffffffff);
    cVar3 = (**(code **)(*(long *)pcVar9 + 0x10))(pcVar9,0x2000,uVar5);
    if (cVar3 == '\0') {
      auVar17 = time_get_do_get_fmt_wide
                          (param_1,local_c8,local_c0,local_d8,local_d0,&local_b0,10,0x1f,2,param_6,
                           &local_b4);
      local_c8 = auVar17._0_8_;
      local_c0 = CONCAT44(local_c0._4_4_,auVar17._8_4_);
    }
    else {
      std::wstreambuf::sbumpc(local_c8);
      local_c0 = CONCAT44(local_c0._4_4_,0xffffffff);
      auVar17 = time_get_do_get_fmt_wide
                          (param_1,local_c8,local_c0,local_d8,local_d0,&local_b0,1,9,1,param_6,
                           &local_b4);
      local_c8 = auVar17._0_8_;
      local_c0 = CONCAT44(local_c0._4_4_,auVar17._8_4_);
    }
    auVar16._8_8_ = local_c0;
    auVar16._0_8_ = local_c8;
joined_r0x00c6d591:
    local_c8 = auVar16._0_8_;
    uVar12 = auVar16._8_8_ & 0xffffffff;
    if (local_b4 == 0) {
      param_8[3] = local_b0;
    }
    break;
  case 'm':
    auVar16 = time_get_do_get_fmt_wide
                        (param_1,local_c8,local_c0,local_d8,local_d0,&local_b0,1,0xc,2,param_6,
                         &local_b4);
    local_c8 = auVar16._0_8_;
    local_190 = auVar16._8_4_;
    uVar12 = auVar16._8_8_ & 0xffffffff;
    local_c0 = CONCAT44(local_c0._4_4_,local_190);
    if (local_b4 == 0) {
      param_8[4] = local_b0 + -1;
    }
    break;
  case 'n':
    uVar5 = FUN_00c61d10(&local_c8,local_c0 & 0xffffffff);
    cVar3 = (**(code **)(*(long *)pcVar9 + 0x60))(pcVar9,uVar5,0);
    if (cVar3 != '\n') goto switchD_00c6c5ba_caseD_45;
LAB_00c6d5c6:
    std::wstreambuf::sbumpc(local_c8);
    uVar12 = 0xffffffff;
    local_c0 = CONCAT44(local_c0._4_4_,0xffffffff);
    break;
  case 't':
    uVar5 = FUN_00c61d10(&local_c8,local_c0 & 0xffffffff);
    cVar3 = (**(code **)(*(long *)pcVar9 + 0x60))(pcVar9,uVar5,0);
    if (cVar3 == '\t') goto LAB_00c6d5c6;
    goto switchD_00c6c5ba_caseD_45;
  case 'x':
    auVar16 = money_get_parse_wpattern
                        (param_1,local_c8,local_c0,local_d8,local_d0,param_6,&local_b4,param_8,
                         *(undefined8 *)(*(long *)(p_Var8 + 0x10) + 0x10));
    local_c8 = auVar16._0_8_;
    local_1e0 = auVar16._8_4_;
    uVar12 = auVar16._8_8_ & 0xffffffff;
    local_c0 = CONCAT44(local_c0._4_4_,local_1e0);
  }
LAB_00c6c728:
  uVar13 = uVar11 + 1;
  goto LAB_00c6c4f0;
switchD_00c6c5ba_caseD_45:
  local_b4 = local_b4 | 4;
LAB_00c6c71e:
  uVar12 = local_c0 & 0xffffffff;
  goto LAB_00c6c728;
}


// ==== entry=00c6d770 name=FUN_00c6d770 size=302 ====

undefined1  [16]
FUN_00c6d770(undefined8 param_1,undefined8 param_2,ulong param_3,long *param_4,undefined8 param_5,
            long param_6,uint *param_7,undefined8 param_8)

{
  int iVar1;
  __timepunct *p_Var2;
  long *plVar3;
  long *plVar4;
  bool bVar5;
  bool bVar6;
  undefined1 auVar7 [16];
  int local_40;
  
  p_Var2 = std::use_facet<std::__timepunct<wchar_t>>((locale *)(param_6 + 0xd0));
  auVar7 = money_get_parse_wpattern
                     (param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,
                      *(undefined8 *)(*(long *)(p_Var2 + 0x10) + 0x20));
  plVar3 = auVar7._0_8_;
  local_40 = auVar7._8_4_;
  auVar7._8_8_ = auVar7._8_8_ & 0xffffffff | param_3 & 0xffffffff00000000;
  bVar5 = local_40 == -1;
  plVar4 = plVar3;
  if (plVar3 != (long *)0x0 && bVar5) {
    if ((int *)plVar3[2] < (int *)plVar3[3]) {
      iVar1 = *(int *)plVar3[2];
    }
    else {
      iVar1 = (**(code **)(*plVar3 + 0x48))(plVar3);
    }
    bVar5 = iVar1 == -1;
    plVar4 = (long *)0x0;
    if (!bVar5) {
      plVar4 = plVar3;
    }
  }
  bVar6 = (int)param_5 == -1;
  if ((param_4 != (long *)0x0) && (bVar6)) {
    if ((int *)param_4[2] < (int *)param_4[3]) {
      iVar1 = *(int *)param_4[2];
    }
    else {
      iVar1 = (**(code **)(*param_4 + 0x48))(param_4);
    }
    bVar6 = iVar1 == -1;
  }
  if (bVar5 == bVar6) {
    *param_7 = *param_7 | 2;
  }
  auVar7._0_8_ = plVar4;
  return auVar7;
}


// ==== entry=00c6d8c0 name=FUN_00c6d8c0 size=302 ====

undefined1  [16]
FUN_00c6d8c0(undefined8 param_1,undefined8 param_2,ulong param_3,long *param_4,undefined8 param_5,
            long param_6,uint *param_7,undefined8 param_8)

{
  int iVar1;
  __timepunct *p_Var2;
  long *plVar3;
  long *plVar4;
  bool bVar5;
  bool bVar6;
  undefined1 auVar7 [16];
  int local_40;
  
  p_Var2 = std::use_facet<std::__timepunct<wchar_t>>((locale *)(param_6 + 0xd0));
  auVar7 = money_get_parse_wpattern
                     (param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,
                      *(undefined8 *)(*(long *)(p_Var2 + 0x10) + 0x10));
  plVar3 = auVar7._0_8_;
  local_40 = auVar7._8_4_;
  auVar7._8_8_ = auVar7._8_8_ & 0xffffffff | param_3 & 0xffffffff00000000;
  bVar5 = local_40 == -1;
  plVar4 = plVar3;
  if (plVar3 != (long *)0x0 && bVar5) {
    if ((int *)plVar3[2] < (int *)plVar3[3]) {
      iVar1 = *(int *)plVar3[2];
    }
    else {
      iVar1 = (**(code **)(*plVar3 + 0x48))(plVar3);
    }
    bVar5 = iVar1 == -1;
    plVar4 = (long *)0x0;
    if (!bVar5) {
      plVar4 = plVar3;
    }
  }
  bVar6 = (int)param_5 == -1;
  if ((param_4 != (long *)0x0) && (bVar6)) {
    if ((int *)param_4[2] < (int *)param_4[3]) {
      iVar1 = *(int *)param_4[2];
    }
    else {
      iVar1 = (**(code **)(*param_4 + 0x48))(param_4);
    }
    bVar6 = iVar1 == -1;
  }
  if (bVar5 == bVar6) {
    *param_7 = *param_7 | 2;
  }
  auVar7._0_8_ = plVar4;
  return auVar7;
}


// ==== entry=00c6da10 name=FUN_00c6da10 size=466 ====

long * FUN_00c6da10(undefined8 param_1,undefined8 param_2,undefined8 param_3,long *param_4,
                   undefined8 param_5,long param_6,uint *param_7,undefined8 param_8,char param_9,
                   char param_10)

{
  int iVar1;
  ctype *pcVar2;
  long *plVar3;
  long *plVar4;
  long in_FS_OFFSET;
  bool bVar5;
  bool bVar6;
  undefined1 auVar7 [12];
  undefined4 local_58;
  int local_54;
  int local_50;
  undefined4 local_4c;
  long local_40;
  
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  pcVar2 = std::use_facet<std::ctype<wchar_t>>((locale *)(param_6 + 0xd0));
  *param_7 = 0;
  local_58 = (**(code **)(*(long *)pcVar2 + 0x50))(pcVar2,0x25);
  if (param_10 == '\0') {
    local_50 = 0;
    local_54 = (int)param_9;
  }
  else {
    local_54 = (int)param_10;
    local_4c = 0;
    local_50 = (int)param_9;
  }
  auVar7 = money_get_parse_wpattern
                     (param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,&local_58);
  plVar3 = auVar7._0_8_;
  bVar5 = auVar7._8_4_ == -1;
  plVar4 = plVar3;
  if (plVar3 != (long *)0x0 && bVar5) {
    if ((int *)plVar3[2] < (int *)plVar3[3]) {
      iVar1 = *(int *)plVar3[2];
    }
    else {
      iVar1 = (**(code **)(*plVar3 + 0x48))(plVar3);
    }
    bVar5 = iVar1 == -1;
    plVar4 = (long *)0x0;
    if (!bVar5) {
      plVar4 = plVar3;
    }
  }
  bVar6 = (int)param_5 == -1;
  if ((param_4 != (long *)0x0) && (bVar6)) {
    if ((int *)param_4[2] < (int *)param_4[3]) {
      iVar1 = *(int *)param_4[2];
    }
    else {
      iVar1 = (**(code **)(*param_4 + 0x48))(param_4);
    }
    bVar6 = iVar1 == -1;
  }
  if (bVar6 == bVar5) {
    *param_7 = *param_7 | 2;
  }
  if (local_40 == *(long *)(in_FS_OFFSET + 0x28)) {
    return plVar4;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ==== entry=00c6dc00 name=FUN_00c6dc00 size=546 ====

long * FUN_00c6dc00(long *param_1,undefined8 param_2,undefined8 param_3,long *param_4,
                   undefined8 param_5,long param_6,uint *param_7,undefined8 param_8,char param_9,
                   char param_10)

{
  ctype *pcVar1;
  long *plVar2;
  long *plVar3;
  int iVar4;
  long in_FS_OFFSET;
  bool bVar5;
  bool bVar6;
  undefined1 auVar7 [12];
  undefined4 local_58;
  int local_54;
  int local_50;
  undefined4 local_4c;
  long local_40;
  
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  iVar4 = (int)param_9;
  if (*(code **)(*param_1 + 0x40) == FUN_00c6da10) {
    pcVar1 = std::use_facet<std::ctype<wchar_t>>((locale *)(param_6 + 0xd0));
    *param_7 = 0;
    local_58 = (**(code **)(*(long *)pcVar1 + 0x50))(pcVar1,0x25);
    if (param_10 == '\0') {
      local_50 = 0;
      local_54 = iVar4;
    }
    else {
      local_4c = 0;
      local_54 = (int)param_10;
      local_50 = iVar4;
    }
    auVar7 = money_get_parse_wpattern
                       (param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,&local_58);
    plVar2 = auVar7._0_8_;
    bVar5 = auVar7._8_4_ == -1;
    plVar3 = plVar2;
    if (plVar2 != (long *)0x0 && bVar5) {
      if ((int *)plVar2[2] < (int *)plVar2[3]) {
        iVar4 = *(int *)plVar2[2];
      }
      else {
        iVar4 = (**(code **)(*plVar2 + 0x48))(plVar2);
      }
      plVar3 = (long *)0x0;
      if (iVar4 != -1) {
        plVar3 = plVar2;
      }
      bVar5 = iVar4 == -1;
    }
    bVar6 = (int)param_5 == -1;
    if ((param_4 != (long *)0x0) && (bVar6)) {
      if ((int *)param_4[2] < (int *)param_4[3]) {
        iVar4 = *(int *)param_4[2];
      }
      else {
        iVar4 = (**(code **)(*param_4 + 0x48))(param_4);
      }
      bVar6 = iVar4 == -1;
    }
    if (bVar5 == bVar6) {
      *param_7 = *param_7 | 2;
    }
  }
  else {
    plVar3 = (long *)(**(code **)(*param_1 + 0x40))
                               (param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,
                                iVar4,(int)param_10);
  }
  if (local_40 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return plVar3;
}


// ==== entry=00c6de40 name=FUN_00c6de40 size=2027 ====

long * FUN_00c6de40(long *param_1,long *param_2,ulong param_3,long *param_4,ulong param_5,
                   long param_6,uint *param_7,undefined8 param_8,undefined4 *param_9,
                   undefined4 *param_10)

{
  long lVar1;
  undefined1 auVar2 [16];
  char cVar3;
  char cVar4;
  int iVar5;
  uint uVar6;
  ctype *pcVar7;
  ctype *pcVar8;
  int iVar9;
  ulong uVar10;
  long *plVar11;
  undefined4 *puVar12;
  long in_FS_OFFSET;
  bool bVar13;
  bool bVar14;
  bool bVar15;
  bool bVar16;
  undefined1 auVar17 [16];
  ulong local_d0;
  ulong local_c8;
  ulong local_b8;
  int local_60;
  undefined4 local_58;
  int local_54;
  int local_50;
  undefined4 local_4c;
  long local_40;
  
  local_c8 = param_3 & 0xffffffff;
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  pcVar7 = std::use_facet<std::ctype<wchar_t>>((locale *)(param_6 + 0xd0));
  *param_7 = 0;
  if (param_9 != param_10) {
    bVar13 = (int)param_5 == -1;
    local_d0 = param_3;
    local_b8 = param_5;
    while( true ) {
      bVar14 = (int)local_c8 == -1;
      bVar15 = bVar14;
      if (param_2 != (long *)0x0 && bVar14) {
        if ((int *)param_2[2] < (int *)param_2[3]) {
          iVar5 = *(int *)param_2[2];
        }
        else {
          iVar5 = (**(code **)(*param_2 + 0x48))(param_2);
        }
        bVar15 = iVar5 == -1;
        if (bVar15) {
          param_2 = (long *)0x0;
        }
      }
      bVar16 = bVar13;
      if (param_4 != (long *)0x0 && bVar13) {
        if ((int *)param_4[2] < (int *)param_4[3]) {
          iVar5 = *(int *)param_4[2];
        }
        else {
          iVar5 = (**(code **)(*param_4 + 0x48))(param_4);
        }
        bVar16 = iVar5 == -1;
        if (bVar16) {
          param_4 = (long *)0x0;
        }
      }
      if (bVar15 == bVar16) break;
      cVar3 = (**(code **)(*(long *)pcVar7 + 0x60))(pcVar7,*param_9,0);
      if (cVar3 == '%') {
        puVar12 = param_9 + 1;
        if (param_10 == puVar12) {
LAB_00c6e617:
          *param_7 = 4;
          goto LAB_00c6e1db;
        }
        cVar3 = (**(code **)(*(long *)pcVar7 + 0x60))(pcVar7,param_9[1],0);
        if ((cVar3 == 'E') || (iVar5 = 0, cVar4 = cVar3, cVar3 == 'O')) {
          puVar12 = param_9 + 2;
          if (param_10 == puVar12) goto LAB_00c6e617;
          cVar4 = (**(code **)(*(long *)pcVar7 + 0x60))(pcVar7,param_9[2],0);
          iVar5 = (int)cVar3;
        }
        iVar9 = (int)cVar4;
        if (*(code **)(*param_1 + 0x40) == FUN_00c6da10) {
          local_b8 = local_b8 & 0xffffffff00000000 | param_5 & 0xffffffff;
          local_d0 = local_d0 & 0xffffffff00000000 | local_c8;
          pcVar8 = std::use_facet<std::ctype<wchar_t>>((locale *)(param_6 + 0xd0));
          lVar1 = *(long *)pcVar8;
          *param_7 = 0;
          local_58 = (**(code **)(lVar1 + 0x50))(pcVar8,0x25);
          if ((char)iVar5 == '\0') {
            local_50 = 0;
            local_54 = iVar9;
          }
          else {
            local_4c = 0;
            local_54 = iVar5;
            local_50 = iVar9;
          }
          auVar17 = money_get_parse_wpattern
                              (param_1,param_2,local_d0,param_4,local_b8,param_6,param_7,param_8,
                               &local_58);
          plVar11 = auVar17._0_8_;
          local_60 = auVar17._8_4_;
          bVar15 = local_60 == -1;
          if (plVar11 != (long *)0x0 && bVar15) {
            if ((int *)plVar11[2] < (int *)plVar11[3]) {
              iVar5 = *(int *)plVar11[2];
            }
            else {
              iVar5 = (**(code **)(*plVar11 + 0x48))(plVar11);
            }
            bVar15 = iVar5 == -1;
            if (bVar15) {
              plVar11 = (long *)0x0;
            }
          }
          uVar10 = auVar17._8_8_ & 0xffffffff;
          auVar2._8_8_ = uVar10;
          auVar2._0_8_ = plVar11;
          auVar17._8_8_ = uVar10;
          auVar17._0_8_ = plVar11;
          bVar14 = bVar13;
          if ((param_4 != (long *)0x0) && (bVar13)) {
            if ((int *)param_4[2] < (int *)param_4[3]) {
              iVar5 = *(int *)param_4[2];
            }
            else {
              iVar5 = (**(code **)(*param_4 + 0x48))(param_4);
            }
            bVar14 = iVar5 == -1;
          }
          if (bVar14 == bVar15) {
            *param_7 = *param_7 | 2;
            auVar17 = auVar2;
          }
        }
        else {
          local_d0 = local_d0 & 0xffffffff00000000 | local_c8;
          local_b8 = local_b8 & 0xffffffff00000000 | param_5 & 0xffffffff;
          auVar17 = (**(code **)(*param_1 + 0x40))
                              (param_1,param_2,local_d0,param_4,local_b8,param_6,param_7,param_8,
                               iVar9,iVar5);
        }
        local_c8 = auVar17._8_8_;
        param_2 = auVar17._0_8_;
        param_9 = puVar12 + 1;
        local_d0 = local_d0 & 0xffffffff00000000;
        local_c8 = local_c8 & 0xffffffff;
      }
      else {
        cVar3 = (**(code **)(*(long *)pcVar7 + 0x10))(pcVar7,0x2000,*param_9);
        if (cVar3 != '\0') {
          do {
            param_9 = param_9 + 1;
            if (param_10 == param_9) break;
            cVar3 = (**(code **)(*(long *)pcVar7 + 0x10))(pcVar7,0x2000,*param_9);
          } while (cVar3 != '\0');
          do {
            bVar14 = (int)local_c8 == -1;
            bVar15 = bVar14;
            if (param_2 != (long *)0x0 && bVar14) {
              if ((int *)param_2[2] < (int *)param_2[3]) {
                iVar5 = *(int *)param_2[2];
              }
              else {
                iVar5 = (**(code **)(*param_2 + 0x48))(param_2);
              }
              bVar15 = iVar5 == -1;
              if (bVar15) {
                param_2 = (long *)0x0;
              }
            }
            bVar16 = bVar13;
            if (param_4 != (long *)0x0 && bVar13) {
              if ((int *)param_4[2] < (int *)param_4[3]) {
                iVar5 = *(int *)param_4[2];
              }
              else {
                iVar5 = (**(code **)(*param_4 + 0x48))(param_4);
              }
              bVar16 = iVar5 == -1;
              if (bVar16) {
                param_4 = (long *)0x0;
              }
            }
            if (bVar15 == bVar16) goto joined_r0x00c6df9d;
            uVar10 = local_c8;
            if ((param_2 != (long *)0x0) && (bVar14)) {
              if ((uint *)param_2[2] < (uint *)param_2[3]) {
                uVar6 = *(uint *)param_2[2];
              }
              else {
                uVar6 = (**(code **)(*param_2 + 0x48))(param_2);
              }
              uVar10 = (ulong)uVar6;
              if (uVar6 == 0xffffffff) {
                param_2 = (long *)0x0;
              }
            }
            cVar3 = (**(code **)(*(long *)pcVar7 + 0x10))(pcVar7,0x2000,uVar10);
            if (cVar3 == '\0') goto joined_r0x00c6df9d;
            if ((ulong)param_2[2] < (ulong)param_2[3]) {
              param_2[2] = param_2[2] + 4;
            }
            else {
              (**(code **)(*param_2 + 0x50))(param_2);
            }
            local_c8 = 0xffffffff;
          } while( true );
        }
        uVar10 = local_c8;
        if ((param_2 == (long *)0x0) || (!bVar14)) {
LAB_00c6df39:
          iVar5 = (**(code **)(*(long *)pcVar7 + 0x40))(pcVar7,uVar10);
          iVar9 = (**(code **)(*(long *)pcVar7 + 0x40))(pcVar7,*param_9);
          if (iVar9 != iVar5) {
LAB_00c6df58:
            iVar5 = (**(code **)(*(long *)pcVar7 + 0x30))(pcVar7,local_c8);
            iVar9 = (**(code **)(*(long *)pcVar7 + 0x30))(pcVar7,*param_9);
            if (iVar9 != iVar5) goto LAB_00c6e617;
          }
        }
        else {
          if ((int *)param_2[2] < (int *)param_2[3]) {
            iVar5 = *(int *)param_2[2];
          }
          else {
            iVar5 = (**(code **)(*param_2 + 0x48))(param_2);
          }
          if (iVar5 == -1) {
            param_2 = (long *)0x0;
            uVar10 = 0xffffffff;
            goto LAB_00c6df39;
          }
          iVar5 = (**(code **)(*(long *)pcVar7 + 0x40))(pcVar7,iVar5);
          iVar9 = (**(code **)(*(long *)pcVar7 + 0x40))(pcVar7,*param_9);
          if (iVar5 != iVar9) {
            if ((uint *)param_2[2] < (uint *)param_2[3]) {
              uVar6 = *(uint *)param_2[2];
            }
            else {
              uVar6 = (**(code **)(*param_2 + 0x48))(param_2);
            }
            local_c8 = (ulong)uVar6;
            if (uVar6 == 0xffffffff) {
              param_2 = (long *)0x0;
            }
            goto LAB_00c6df58;
          }
        }
        if ((ulong)param_2[2] < (ulong)param_2[3]) {
          param_2[2] = param_2[2] + 4;
        }
        else {
          (**(code **)(*param_2 + 0x50))(param_2);
        }
        param_9 = param_9 + 1;
        local_c8 = 0xffffffff;
      }
joined_r0x00c6df9d:
      if ((param_9 == param_10) || (*param_7 != 0)) goto LAB_00c6e1db;
    }
    *param_7 = 6;
  }
LAB_00c6e1db:
  if (local_40 == *(long *)(in_FS_OFFSET + 0x28)) {
    return param_2;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ==== entry=00c6e690 name=FUN_00c6e690 size=4590 ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Instruction at (ram,0x00c6fc89) overlaps instruction at (ram,0x00c6fc88)
    */
/* WARNING: Removing unreachable block (ram,0x00d987fb) */
/* WARNING: Removing unreachable block (ram,0x00d98881) */
/* WARNING: Removing unreachable block (ram,0x00d9883b) */
/* WARNING: Removing unreachable block (ram,0x00d98799) */
/* WARNING: Restarted to delay deadcode elimination for space: stack */

wstreambuf *
FUN_00c6e690(undefined8 param_1,wstreambuf *param_2,ulong param_3,char **param_4,int param_5,
            long param_6,uint *param_7,string *param_8)

{
  long *plVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  ulong uVar5;
  locale *plVar6;
  char cVar7;
  uint uVar8;
  int iVar9;
  wchar_t wVar10;
  int iVar11;
  ctype *pcVar12;
  ulong uVar13;
  char *pcVar14;
  __moneypunct_cache<wchar_t,true> *this;
  undefined4 *puVar15;
  long lVar16;
  uint *puVar17;
  wchar_t *pwVar18;
  wstreambuf *pwVar19;
  char **ppcVar20;
  undefined2 uVar21;
  locale *extraout_RDX;
  locale *extraout_RDX_00;
  locale *extraout_RDX_01;
  locale *extraout_RDX_02;
  locale *extraout_RDX_03;
  locale *extraout_RDX_04;
  locale *extraout_RDX_05;
  locale *extraout_RDX_06;
  locale *extraout_RDX_07;
  locale *extraout_RDX_08;
  locale *extraout_RDX_09;
  locale *extraout_RDX_10;
  locale *extraout_RDX_11;
  locale *extraout_RDX_12;
  locale *extraout_RDX_13;
  locale *extraout_RDX_14;
  locale *plVar22;
  locale *extraout_RDX_15;
  locale *extraout_RDX_16;
  locale *extraout_RDX_17;
  locale *extraout_RDX_18;
  locale *extraout_RDX_19;
  locale *extraout_RDX_20;
  locale *extraout_RDX_21;
  locale *plVar23;
  locale *extraout_RDX_22;
  locale *extraout_RDX_23;
  locale *extraout_RDX_24;
  locale *extraout_RDX_25;
  locale *extraout_RDX_26;
  locale *extraout_RDX_27;
  locale *extraout_RDX_28;
  locale *extraout_RDX_29;
  locale *extraout_RDX_30;
  locale *extraout_RDX_31;
  locale *extraout_RDX_32;
  locale *extraout_RDX_33;
  ulong uVar24;
  long lVar25;
  byte bVar26;
  undefined7 uVar28;
  locale *plVar27;
  ulong unaff_R14;
  long lVar29;
  long in_FS_OFFSET;
  bool bVar30;
  bool bVar31;
  bool bVar32;
  bool bVar33;
  char cVar34;
  byte bVar35;
  ulong local_100;
  undefined8 local_e8;
  int local_d0;
  byte local_cb;
  bool local_c9;
  char **local_b8;
  wstreambuf *local_a8;
  ulong local_a0;
  undefined4 local_8c;
  char *local_88;
  locale *local_80;
  char local_78;
  undefined7 uStack_77;
  char *local_68;
  locale *local_60;
  char local_58;
  undefined7 uStack_57;
  long local_40;
  
  bVar35 = 0;
  plVar27 = (locale *)(param_6 + 0xd0);
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  ppcVar20 = param_4;
  local_a8 = param_2;
  local_a0 = param_3;
  pcVar12 = std::use_facet<std::ctype<wchar_t>>(plVar27);
  uVar13 = std::locale::id::_M_id((id *)&DAT_011c5530);
  plVar1 = (long *)(*(long *)(*(long *)(param_6 + 0xd0) + 0x18) + uVar13 * 8);
  lVar25 = *plVar1;
  if (lVar25 == 0) {
                    /* try { // try from 00c6f6a5 to 00c6f6a9 has its CatchHandler @ 00c6f952 */
    this = operator_new(0xa0);
    *(undefined4 *)(this + 8) = 0;
    *(undefined8 *)(this + 0x10) = 0;
    *(undefined8 *)(this + 0x18) = 0;
    *(undefined ***)this = &PTR____moneypunct_cache_011b2858;
    this[0x20] = (__moneypunct_cache<wchar_t,true>)0x0;
    *(undefined8 *)(this + 0x24) = 0;
    *(undefined8 *)(this + 0x30) = 0;
    *(undefined8 *)(this + 0x38) = 0;
    *(undefined8 *)(this + 0x40) = 0;
    *(undefined8 *)(this + 0x48) = 0;
    *(undefined8 *)(this + 0x50) = 0;
    *(undefined8 *)(this + 0x58) = 0;
    *(undefined8 *)(this + 0x60) = 0;
    *(undefined4 *)(this + 0x68) = 0;
    this[0x98] = (__moneypunct_cache<wchar_t,true>)0x0;
                    /* try { // try from 00c6f72b to 00c6f72f has its CatchHandler @ 00c6f950 */
    std::__moneypunct_cache<wchar_t,true>::_M_cache(this,plVar27);
    std::locale::_Impl::_M_install_cache(*(_Impl **)(param_6 + 0xd0),(facet *)this,uVar13);
    lVar25 = *plVar1;
  }
  if (*(long *)(lVar25 + 0x48) == 0) {
    local_c9 = false;
  }
  else {
    local_c9 = *(long *)(lVar25 + 0x58) != 0;
  }
  local_80 = (locale *)0x0;
  local_88 = &local_78;
  local_78 = '\0';
  if (*(char *)(lVar25 + 0x20) != '\0') {
                    /* try { // try from 00c6e788 to 00c6e78c has its CatchHandler @ 00c6f97f */
    std::__cxx11::string::reserve((ulong)&local_88);
  }
  local_60 = (locale *)0x0;
  local_68 = &local_58;
  local_58 = '\0';
                    /* try { // try from 00c6e7bf to 00c6f623 has its CatchHandler @ 00c6f97a */
  std::__cxx11::string::reserve((ulong)&local_68);
  lVar29 = 0;
  uVar24 = 0;
  local_cb = 0;
  local_8c = *(undefined4 *)(lVar25 + 0x68);
  local_d0 = 0;
  local_100 = 0;
  bVar32 = false;
  cVar7 = (char)&local_68;
  plVar23 = extraout_RDX;
  local_b8 = param_4;
  if (4 < (byte)local_8c) goto LAB_00c6f059;
LAB_00c6e81d:
  bVar26 = *(byte *)((long)&local_8c + lVar29);
  pcVar14 = (char *)((long)&switchD_00c6e830::caseD_a +
                    (long)(int)(&switchD_00c6e830::caseD_a)[bVar26]);
  uVar28 = (undefined7)((ulong)plVar27 >> 8);
  cVar34 = (char)pcVar14;
                    /* WARNING (jumptable): Sanity check requires truncation of jumptable */
                    /* WARNING: Could not find normalized switch variable to match jumptable */
  switch(bVar26) {
  case 0:
    plVar27 = (locale *)0x1;
LAB_00c6e83e:
    if (lVar29 == 3) goto LAB_00c6e848;
LAB_00c6ecff:
    iVar9 = (wchar_t)local_a0;
    while( true ) {
      bVar30 = iVar9 == -1;
      bVar31 = local_a8 != (wstreambuf *)0x0;
      bVar33 = bVar30;
      if (bVar31 && bVar30) {
        if (*(int **)(local_a8 + 0x10) < *(int **)(local_a8 + 0x18)) {
          iVar9 = **(int **)(local_a8 + 0x10);
        }
        else {
          iVar9 = (**(code **)(*(long *)local_a8 + 0x48))();
          plVar23 = extraout_RDX_12;
        }
        bVar33 = false;
        if (iVar9 == -1) {
          local_a8 = (wstreambuf *)0x0;
          bVar33 = bVar31 && bVar30;
        }
      }
      plVar23 = (locale *)CONCAT71((int7)((ulong)plVar23 >> 8),param_5 == -1);
      bVar30 = local_b8 != (char **)0x0 && param_5 == -1;
      unaff_R14 = CONCAT71((int7)(unaff_R14 >> 8),bVar30);
      if (bVar30) {
        if (local_b8[2] < local_b8[3]) {
          iVar9 = *(int *)local_b8[2];
        }
        else {
                    /* try { // try from 00c6f7cf to 00c6f943 has its CatchHandler @ 00c6f97a */
          iVar9 = (**(code **)(*local_b8 + 0x48))();
        }
        plVar23 = (locale *)0x0;
        if (iVar9 == -1) {
          local_b8 = (char **)0x0;
          plVar23 = (locale *)(unaff_R14 & 0xffffffff);
        }
      }
      if (bVar33 == SUB81(plVar23,0)) break;
      uVar13 = local_a0 & 0xffffffff;
      if (((wchar_t)local_a0 == -1) && (local_a8 != (wstreambuf *)0x0)) {
        if (*(uint **)(local_a8 + 0x10) < *(uint **)(local_a8 + 0x18)) {
          uVar8 = **(uint **)(local_a8 + 0x10);
        }
        else {
          uVar8 = (**(code **)(*(long *)local_a8 + 0x48))();
        }
        uVar13 = (ulong)uVar8;
        if (uVar8 == 0xffffffff) {
          local_a8 = (wstreambuf *)0x0;
        }
      }
      cVar34 = (**(code **)(*(long *)pcVar12 + 0x10))(pcVar12,0x2000,uVar13);
      plVar23 = extraout_RDX_01;
      if (cVar34 == '\0') break;
      if (*(ulong *)(local_a8 + 0x10) < *(ulong *)(local_a8 + 0x18)) {
        *(ulong *)(local_a8 + 0x10) = *(ulong *)(local_a8 + 0x10) + 4;
      }
      else {
        (**(code **)(*(long *)local_a8 + 0x50))();
        plVar23 = extraout_RDX_07;
      }
      local_a0 = CONCAT44(local_a0._4_4_,0xffffffff);
      iVar9 = -1;
    }
    goto LAB_00c6f028;
  case 1:
    bVar33 = (wchar_t)local_a0 == -1;
    if (local_a8 != (wstreambuf *)0x0 && bVar33) {
      if (*(int **)(local_a8 + 0x10) < *(int **)(local_a8 + 0x18)) {
        iVar9 = **(int **)(local_a8 + 0x10);
      }
      else {
        iVar9 = (**(code **)(*(long *)local_a8 + 0x48))();
        plVar23 = extraout_RDX_15;
      }
      bVar33 = false;
      if (iVar9 == -1) {
        local_a8 = (wstreambuf *)0x0;
        bVar33 = true;
      }
    }
    plVar23 = (locale *)CONCAT71((int7)((ulong)plVar23 >> 8),param_5 == -1);
    bVar30 = local_b8 != (char **)0x0 && param_5 == -1;
    if (bVar30) {
      if (local_b8[2] < local_b8[3]) {
        iVar9 = *(int *)local_b8[2];
      }
      else {
        iVar9 = (**(code **)(*local_b8 + 0x48))();
      }
      plVar23 = (locale *)0x0;
      if (iVar9 == -1) {
        local_b8 = (char **)0x0;
        plVar23 = (locale *)(CONCAT71(uVar28,bVar30) & 0xffffffff);
      }
    }
    if (bVar33 != SUB81(plVar23,0)) {
      uVar13 = local_a0 & 0xffffffff;
      if (((wchar_t)local_a0 == -1) && (local_a8 != (wstreambuf *)0x0)) {
        if (*(uint **)(local_a8 + 0x10) < *(uint **)(local_a8 + 0x18)) {
          uVar8 = **(uint **)(local_a8 + 0x10);
        }
        else {
          uVar8 = (**(code **)(*(long *)local_a8 + 0x48))();
        }
        uVar13 = (ulong)uVar8;
        if (uVar8 == 0xffffffff) {
          local_a8 = (wstreambuf *)0x0;
        }
      }
      uVar8 = (**(code **)(*(long *)pcVar12 + 0x10))(pcVar12,0x2000,uVar13);
      plVar27 = (locale *)(ulong)uVar8;
      plVar23 = extraout_RDX_05;
      if ((char)uVar8 != '\0') {
        if (*(ulong *)(local_a8 + 0x10) < *(ulong *)(local_a8 + 0x18)) {
          *(ulong *)(local_a8 + 0x10) = *(ulong *)(local_a8 + 0x10) + 4;
        }
        else {
          (**(code **)(*(long *)local_a8 + 0x50))();
          plVar23 = extraout_RDX_16;
        }
        local_a0 = CONCAT44(local_a0._4_4_,0xffffffff);
        goto LAB_00c6e83e;
      }
    }
    plVar27 = (locale *)0x0;
    if (lVar29 != 3) goto LAB_00c6ecff;
LAB_00c6e848:
    if ((1 < local_100 & (byte)plVar27) == 0) {
      if ((byte)plVar27 != 0) goto joined_r0x00c6f762;
      goto LAB_00c6ee3d;
    }
    if (bVar32) {
      lVar29 = *(long *)(lVar25 + 0x50);
    }
    else {
      lVar29 = *(long *)(lVar25 + 0x40);
    }
    uVar13 = 1;
    iVar9 = (wchar_t)local_a0;
    goto LAB_00c6e90a;
  case 2:
    if ((*(byte *)(param_6 + 0x19) & 2) == 0) {
      iVar9 = (int)lVar29;
      bVar33 = iVar9 == 0;
      plVar23 = (locale *)CONCAT71((int7)((ulong)plVar23 >> 8),bVar33);
      uVar13 = CONCAT71((int7)(uVar13 >> 8),1 < local_100 || bVar33);
      if (1 >= local_100 && !bVar33) {
        if (iVar9 == 1) {
          uVar13 = (ulong)local_c9;
          if (((local_c9 == false) && ((byte)local_8c != '\x03')) && (local_8c._2_1_ != '\x01'))
          goto LAB_00c6f060;
        }
        else {
          plVar27 = (locale *)0x1;
          if (iVar9 != 2) break;
          if (local_8c._3_1_ != '\x04') {
            if (local_8c._3_1_ != '\x03') goto LAB_00c6f045;
            if (local_c9 == false) goto LAB_00c6f045;
          }
        }
      }
    }
    local_e8 = *(ulong *)(lVar25 + 0x38);
    unaff_R14 = 0;
    iVar9 = (wchar_t)local_a0;
LAB_00c6ec5e:
    bVar33 = iVar9 == -1;
    uVar8 = (uint)CONCAT71((int7)(uVar13 >> 8),bVar33);
    bVar30 = local_a8 != (wstreambuf *)0x0;
    uVar28 = (undefined7)((ulong)plVar27 >> 8);
    if (bVar30 && bVar33) {
      if (*(int **)(local_a8 + 0x10) < *(int **)(local_a8 + 0x18)) {
        iVar9 = **(int **)(local_a8 + 0x10);
      }
      else {
        iVar9 = (**(code **)(*(long *)local_a8 + 0x48))();
        plVar23 = extraout_RDX_13;
      }
      uVar8 = 0;
      if (iVar9 == -1) {
        local_a8 = (wstreambuf *)0x0;
        uVar8 = (uint)CONCAT71(uVar28,bVar30 && bVar33);
      }
    }
    plVar23 = (locale *)CONCAT71((int7)((ulong)plVar23 >> 8),param_5 == -1);
    bVar33 = local_b8 != (char **)0x0 && param_5 == -1;
    plVar27 = (locale *)CONCAT71(uVar28,bVar33);
    if (bVar33) {
      if (local_b8[2] < local_b8[3]) {
        iVar9 = *(int *)local_b8[2];
      }
      else {
        iVar9 = (**(code **)(*local_b8 + 0x48))();
      }
      plVar23 = (locale *)0x0;
      if (iVar9 != -1) goto LAB_00c6ebed;
      plVar23 = (locale *)((ulong)plVar27 & 0xffffffff);
      local_b8 = (char **)0x0;
      uVar8 = uVar8 ^ (uint)plVar27;
      bVar26 = (byte)uVar8 & unaff_R14 < local_e8;
      uVar13 = (ulong)CONCAT31((int3)(uVar8 >> 8),bVar26);
      if (bVar26 == 0) goto LAB_00c6f3e0;
LAB_00c6ec01:
      iVar9 = (wchar_t)local_a0;
      if ((local_a8 != (wstreambuf *)0x0) && ((wchar_t)local_a0 == -1)) {
        if (*(int **)(local_a8 + 0x10) < *(int **)(local_a8 + 0x18)) {
          iVar9 = **(int **)(local_a8 + 0x10);
        }
        else {
          iVar9 = (**(code **)(*(long *)local_a8 + 0x48))();
        }
        if (iVar9 == -1) {
          local_a8 = (wstreambuf *)0x0;
        }
      }
      plVar23 = *(locale **)(lVar25 + 0x30);
      if (*(int *)(plVar23 + unaff_R14 * 4) != iVar9) goto LAB_00c6f3eb;
      if (*(ulong *)(local_a8 + 0x10) < *(ulong *)(local_a8 + 0x18)) {
        *(ulong *)(local_a8 + 0x10) = *(ulong *)(local_a8 + 0x10) + 4;
      }
      else {
        (**(code **)(*(long *)local_a8 + 0x50))();
        plVar23 = extraout_RDX_08;
      }
      local_a0 = CONCAT44(local_a0._4_4_,0xffffffff);
      unaff_R14 = unaff_R14 + 1;
      iVar9 = -1;
      goto LAB_00c6ec5e;
    }
LAB_00c6ebed:
    uVar8 = uVar8 ^ (uint)plVar23;
    bVar26 = (byte)uVar8 & unaff_R14 < local_e8;
    uVar13 = (ulong)CONCAT31((int3)(uVar8 >> 8),bVar26);
    if (bVar26 != 0) goto LAB_00c6ec01;
LAB_00c6f3e0:
    if (unaff_R14 == local_e8) goto LAB_00c6f060;
LAB_00c6f3eb:
    if (unaff_R14 == 0) {
      uVar5 = local_e8 >> 0x20;
      local_e8 = CONCAT44((int)uVar5,*(uint *)(param_6 + 0x18));
      bVar33 = (*(uint *)(param_6 + 0x18) & 0x200) == 0;
      plVar27 = (locale *)CONCAT71(uVar28,bVar33);
      uVar13 = CONCAT71((int7)(uVar13 >> 8),!bVar33);
      break;
    }
    goto LAB_00c6ee3d;
  case 3:
    if (*(long *)(lVar25 + 0x48) == 0) {
      if (*(long *)(lVar25 + 0x58) != 0) {
LAB_00c6f1f8:
        uVar8 = FUN_00c56c30(&local_a8);
        uVar13 = (ulong)uVar8;
        plVar23 = extraout_RDX_06;
        if ((char)uVar8 == '\0') {
          iVar9 = FUN_00c61d10(&local_a8);
          plVar23 = *(locale **)(lVar25 + 0x50);
          if (*(int *)plVar23 == iVar9) {
            local_100 = *(ulong *)(lVar25 + 0x58);
            std::wstreambuf::sbumpc(local_a8);
            plVar27 = (locale *)0x1;
            bVar32 = true;
            local_a0 = CONCAT44(local_a0._4_4_,0xffffffff);
            plVar23 = extraout_RDX_11;
            break;
          }
        }
        if ((*(long *)(lVar25 + 0x48) != 0) && (*(long *)(lVar25 + 0x58) == 0)) goto LAB_00c6f150;
      }
LAB_00c6eb36:
      uVar13 = (ulong)local_c9;
      plVar27 = (locale *)(ulong)(local_c9 ^ 1);
    }
    else {
      bVar33 = (wchar_t)local_a0 == -1;
      if (local_a8 != (wstreambuf *)0x0 && bVar33) {
        if (*(int **)(local_a8 + 0x10) < *(int **)(local_a8 + 0x18)) {
          iVar9 = **(int **)(local_a8 + 0x10);
        }
        else {
          iVar9 = (**(code **)(*(long *)local_a8 + 0x48))();
          plVar23 = extraout_RDX_14;
        }
        bVar33 = false;
        if (iVar9 == -1) {
          local_a8 = (wstreambuf *)0x0;
          bVar33 = true;
        }
      }
      plVar23 = (locale *)CONCAT71((int7)((ulong)plVar23 >> 8),param_5 == -1);
      bVar30 = local_b8 != (char **)0x0 && param_5 == -1;
      if (bVar30) {
        if (local_b8[2] < local_b8[3]) {
          iVar9 = *(int *)local_b8[2];
        }
        else {
          iVar9 = (**(code **)(*local_b8 + 0x48))();
        }
        plVar23 = (locale *)0x0;
        if (iVar9 == -1) {
          local_b8 = (char **)0x0;
          plVar23 = (locale *)(CONCAT71(uVar28,bVar30) & 0xffffffff);
        }
      }
      if (bVar33 != SUB81(plVar23,0)) {
        iVar9 = (wchar_t)local_a0;
        if (((wchar_t)local_a0 == -1) && (local_a8 != (wstreambuf *)0x0)) {
          if (*(int **)(local_a8 + 0x10) < *(int **)(local_a8 + 0x18)) {
            iVar9 = **(int **)(local_a8 + 0x10);
          }
          else {
            iVar9 = (**(code **)(*(long *)local_a8 + 0x48))();
          }
          if (iVar9 == -1) {
            local_a8 = (wstreambuf *)0x0;
          }
        }
        plVar23 = *(locale **)(lVar25 + 0x40);
        if (*(int *)plVar23 == iVar9) {
          local_100 = *(ulong *)(lVar25 + 0x48);
          std::wstreambuf::sbumpc(local_a8);
          local_a0 = CONCAT44(local_a0._4_4_,0xffffffff);
          uVar13 = 0;
          plVar27 = (locale *)0x1;
          plVar23 = extraout_RDX_10;
          break;
        }
      }
      if (*(long *)(lVar25 + 0x58) != 0) goto LAB_00c6f1f8;
      if (*(long *)(lVar25 + 0x48) == 0) goto LAB_00c6eb36;
LAB_00c6f150:
      uVar13 = 0;
      plVar27 = (locale *)0x1;
      bVar32 = true;
    }
    break;
  case 4:
    iVar9 = (wchar_t)local_a0;
    do {
      bVar33 = iVar9 == -1;
      uVar28 = (undefined7)((ulong)plVar27 >> 8);
      if (local_a8 != (wstreambuf *)0x0 && bVar33) {
        if (*(int **)(local_a8 + 0x10) < *(int **)(local_a8 + 0x18)) {
          iVar9 = **(int **)(local_a8 + 0x10);
        }
        else {
          iVar9 = (**(code **)(*(long *)local_a8 + 0x48))();
          plVar23 = extraout_RDX_09;
        }
        bVar33 = false;
        if (iVar9 == -1) {
          local_a8 = (wstreambuf *)0x0;
          bVar33 = true;
        }
      }
      plVar23 = (locale *)CONCAT71((int7)((ulong)plVar23 >> 8),param_5 == -1);
      bVar30 = local_b8 != (char **)0x0 && param_5 == -1;
      if (bVar30) {
        if (local_b8[2] < local_b8[3]) {
          iVar9 = *(int *)local_b8[2];
        }
        else {
          iVar9 = (**(code **)(*local_b8 + 0x48))();
        }
        plVar23 = (locale *)0x0;
        if (iVar9 != -1) goto LAB_00c6ea3f;
        local_b8 = (char **)0x0;
        plVar23 = (locale *)(CONCAT71(uVar28,bVar30) & 0xffffffff);
        bVar30 = SUB81(plVar23,0);
      }
      else {
LAB_00c6ea3f:
        bVar30 = SUB81(plVar23,0);
      }
      if (bVar33 == bVar30) goto LAB_00c6ee20;
                    /* WARNING: Read-only address (ram,0x00d9875b) is written */
      wVar10 = (wchar_t)local_a0;
      if ((local_a8 != (wstreambuf *)0x0) && ((wchar_t)local_a0 == L'\xffffffff')) {
        if (*(wchar_t **)(local_a8 + 0x10) < *(wchar_t **)(local_a8 + 0x18)) {
          wVar10 = **(wchar_t **)(local_a8 + 0x10);
        }
        else {
          wVar10 = (**(code **)(*(long *)local_a8 + 0x48))();
        }
        if (wVar10 == L'\xffffffff') {
          local_a8 = (wstreambuf *)0x0;
        }
      }
      pwVar18 = wmemchr((wchar_t *)(lVar25 + 0x70),wVar10,10);
      plVar6 = local_60;
      plVar22 = local_80;
      iVar9 = (int)uVar24;
      if (pwVar18 == (wchar_t *)0x0) {
        bVar26 = *(wchar_t *)(lVar25 + 0x24) != wVar10 | local_cb;
        plVar27 = (locale *)CONCAT71(uVar28,bVar26);
        plVar23 = extraout_RDX_00;
        if (bVar26 == 0) {
          if (*(int *)(lVar25 + 0x60) < 1) goto LAB_00c6f913;
          uVar24 = 0;
          local_cb = 1;
          local_d0 = iVar9;
        }
        else {
          if (*(byte *)(lVar25 + 0x20) == 0) goto LAB_00c6ee26;
          if (*(wchar_t *)(lVar25 + 0x28) != wVar10) {
            plVar27 = (locale *)(ulong)*(byte *)(lVar25 + 0x20);
            goto LAB_00c6ee26;
          }
          if (local_cb != 0) {
            plVar27 = (locale *)(ulong)local_cb;
            goto LAB_00c6ee26;
          }
          if (iVar9 == 0) {
            plVar27 = (locale *)0x0;
            goto LAB_00c6ee26;
          }
          plVar27 = local_80 + 1;
          if (local_88 == &local_78) {
            plVar23 = (locale *)0xf;
          }
          else {
            plVar23 = (locale *)CONCAT71(uStack_77,local_78);
          }
          ppcVar20 = &local_88;
          if (plVar23 < plVar27) {
            ppcVar20 = (char **)0x0;
            std::__cxx11::string::_M_mutate((ulong)&local_88,(ulong)local_80,(char *)0x0,0);
            plVar23 = extraout_RDX_03;
          }
          local_88[(long)plVar22] = (char)uVar24;
          uVar24 = 0;
          (local_88 + 1)[(long)plVar22] = '\0';
          local_80 = plVar27;
        }
      }
      else {
        plVar27 = local_60 + 1;
        bVar26 = std::money_base::_S_atoms[(long)pwVar18 - (lVar25 + 0x6c) >> 2];
        unaff_R14 = (ulong)bVar26;
        if (local_68 == &local_58) {
          plVar23 = (locale *)0xf;
        }
        else {
          plVar23 = (locale *)CONCAT71(uStack_57,local_58);
        }
        ppcVar20 = &local_68;
        if (plVar23 < plVar27) {
          ppcVar20 = (char **)0x0;
          std::__cxx11::string::_M_mutate((ulong)&local_68,(ulong)local_60,(char *)0x0,0);
          plVar23 = extraout_RDX_02;
        }
        local_68[(long)plVar6] = bVar26;
        uVar24 = (ulong)(iVar9 + 1);
        (local_68 + 1)[(long)plVar6] = '\0';
        local_60 = plVar27;
      }
      if (*(ulong *)(local_a8 + 0x10) < *(ulong *)(local_a8 + 0x18)) {
        *(ulong *)(local_a8 + 0x10) = *(ulong *)(local_a8 + 0x10) + 4;
      }
      else {
        (**(code **)(*(long *)local_a8 + 0x50))();
        plVar23 = extraout_RDX_04;
      }
      local_a0 = CONCAT44(local_a0._4_4_,0xffffffff);
      iVar9 = -1;
    } while( true );
  case 5:
    goto switchD_00c6e830_caseD_5;
  case 6:
    pcVar14 = (char *)((ulong)pcVar14 & 0xffffffffffffff80);
    cVar34 = (char)pcVar14;
    *pcVar14 = *pcVar14 + cVar34;
    *pcVar14 = *pcVar14 + cVar34;
    *pcVar14 = *pcVar14 + cVar34;
    *(char *)(lVar25 + -0x77) = *(char *)(lVar25 + -0x77) + cVar34;
    in((short)plVar23);
    bVar26 = (byte)uVar13;
    goto LAB_00c6ff10;
  case 7:
    goto switchD_00c6e830_caseD_7;
  case 8:
    *(undefined1 *)
     ((long)&switchD_00c6e830::caseD_a + (long)(int)(&switchD_00c6e830::caseD_a)[bVar26] + 1) = 0;
    goto LAB_00c6fd1d;
  case 9:
    *pcVar14 = *pcVar14 + cVar34;
    *pcVar14 = *pcVar14 + cVar34;
    *(char *)(lVar25 + -0x77) = *(char *)(lVar25 + -0x77) + cVar34;
    in((short)plVar23);
    goto code_r0x00c6fc8c;
  case 10:
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
LAB_00c6f02f:
  while( true ) {
    if ((3 < (int)lVar29 + 1) || ((char)uVar13 != '\0')) goto LAB_00c6e848;
LAB_00c6f045:
    lVar29 = lVar29 + 1;
    if (*(byte *)((long)&local_8c + lVar29) < 5) break;
LAB_00c6f059:
    uVar13 = 0;
LAB_00c6f060:
    plVar27 = (locale *)0x1;
  }
  goto LAB_00c6e81d;
switchD_00c6e830_caseD_5:
  puVar15 = (undefined4 *)(ulong)((uint)pcVar14 ^ 0x128b9f);
LAB_00c6fb5d:
  uVar8 = 0xd98708;
  lVar16 = (long)(int)(&switchD_00c6fb70::caseD_5)[*(byte *)((long)puVar15 + lVar29)];
  puVar17 = (uint *)((long)&switchD_00c6fb70::caseD_5 + lVar16);
  uVar28 = (undefined7)((ulong)plVar27 >> 8);
                    /* WARNING (jumptable): Sanity check requires truncation of jumptable */
                    /* WARNING: Could not find normalized switch variable to match jumptable */
  switch(*(byte *)((long)puVar15 + lVar29)) {
  case 0:
    plVar27 = (locale *)0x1;
LAB_00c6fb7e:
    if (lVar29 == 3) goto LAB_00c6fb88;
LAB_00c7003f:
    iVar9 = (wchar_t)local_a0;
    while( true ) {
      bVar30 = iVar9 == -1;
      bVar31 = local_a8 != (wstreambuf *)0x0;
      bVar33 = bVar30;
      if (bVar31 && bVar30) {
        if (*(int **)(local_a8 + 0x10) < *(int **)(local_a8 + 0x18)) {
          iVar9 = **(int **)(local_a8 + 0x10);
        }
        else {
          iVar9 = (**(code **)(*(long *)local_a8 + 0x48))();
          plVar23 = extraout_RDX_29;
        }
        bVar33 = false;
        if (iVar9 == -1) {
          local_a8 = (wstreambuf *)0x0;
          bVar33 = bVar31 && bVar30;
        }
      }
      plVar23 = (locale *)CONCAT71((int7)((ulong)plVar23 >> 8),param_5 == -1);
      bVar30 = local_b8 != (char **)0x0 && param_5 == -1;
      unaff_R14 = CONCAT71((int7)(unaff_R14 >> 8),bVar30);
      if (bVar30) {
        if (local_b8[2] < local_b8[3]) {
          iVar9 = *(int *)local_b8[2];
        }
        else {
          iVar9 = (**(code **)(*local_b8 + 0x48))();
        }
        plVar23 = (locale *)0x0;
        if (iVar9 == -1) {
          local_b8 = (char **)0x0;
          plVar23 = (locale *)(unaff_R14 & 0xffffffff);
        }
      }
      if (bVar33 == SUB81(plVar23,0)) break;
      uVar13 = local_a0 & 0xffffffff;
      if (((wchar_t)local_a0 == -1) && (local_a8 != (wstreambuf *)0x0)) {
        if (*(uint **)(local_a8 + 0x10) < *(uint **)(local_a8 + 0x18)) {
          uVar8 = **(uint **)(local_a8 + 0x10);
        }
        else {
          uVar8 = (**(code **)(*(long *)local_a8 + 0x48))();
        }
        uVar13 = (ulong)uVar8;
        if (uVar8 == 0xffffffff) {
          local_a8 = (wstreambuf *)0x0;
        }
      }
      cVar34 = (**(code **)(*(long *)pcVar12 + 0x10))(pcVar12,0x2000,uVar13);
      plVar23 = extraout_RDX_18;
      if (cVar34 == '\0') break;
      if (*(ulong *)(local_a8 + 0x10) < *(ulong *)(local_a8 + 0x18)) {
        *(ulong *)(local_a8 + 0x10) = *(ulong *)(local_a8 + 0x10) + 4;
      }
      else {
        (**(code **)(*(long *)local_a8 + 0x50))();
        plVar23 = extraout_RDX_24;
      }
      local_a0 = CONCAT44(local_a0._4_4_,0xffffffff);
      iVar9 = -1;
    }
    goto LAB_00c70368;
  case 1:
    bVar33 = (wchar_t)local_a0 == -1;
    if (local_a8 != (wstreambuf *)0x0 && bVar33) {
      if (*(int **)(local_a8 + 0x10) < *(int **)(local_a8 + 0x18)) {
        iVar9 = **(int **)(local_a8 + 0x10);
      }
      else {
        iVar9 = (**(code **)(*(long *)local_a8 + 0x48))();
        plVar23 = extraout_RDX_32;
      }
      bVar33 = false;
      if (iVar9 == -1) {
        local_a8 = (wstreambuf *)0x0;
        bVar33 = true;
      }
    }
    plVar23 = (locale *)CONCAT71((int7)((ulong)plVar23 >> 8),param_5 == -1);
    bVar30 = local_b8 != (char **)0x0 && param_5 == -1;
    if (bVar30) {
      if (local_b8[2] < local_b8[3]) {
        iVar9 = *(int *)local_b8[2];
      }
      else {
        iVar9 = (**(code **)(*local_b8 + 0x48))();
      }
      plVar23 = (locale *)0x0;
      if (iVar9 == -1) {
        local_b8 = (char **)0x0;
        plVar23 = (locale *)(CONCAT71(uVar28,bVar30) & 0xffffffff);
      }
    }
    if (bVar33 != SUB81(plVar23,0)) {
      uVar13 = local_a0 & 0xffffffff;
      if (((wchar_t)local_a0 == -1) && (local_a8 != (wstreambuf *)0x0)) {
        if (*(uint **)(local_a8 + 0x10) < *(uint **)(local_a8 + 0x18)) {
          uVar8 = **(uint **)(local_a8 + 0x10);
        }
        else {
          uVar8 = (**(code **)(*(long *)local_a8 + 0x48))();
        }
        uVar13 = (ulong)uVar8;
        if (uVar8 == 0xffffffff) {
          local_a8 = (wstreambuf *)0x0;
        }
      }
      uVar8 = (**(code **)(*(long *)pcVar12 + 0x10))(pcVar12,0x2000,uVar13);
      plVar27 = (locale *)(ulong)uVar8;
      plVar23 = extraout_RDX_22;
      if ((char)uVar8 != '\0') {
        if (*(ulong *)(local_a8 + 0x10) < *(ulong *)(local_a8 + 0x18)) {
          *(ulong *)(local_a8 + 0x10) = *(ulong *)(local_a8 + 0x10) + 4;
        }
        else {
          (**(code **)(*(long *)local_a8 + 0x50))();
          plVar23 = extraout_RDX_33;
        }
        local_a0 = CONCAT44(local_a0._4_4_,0xffffffff);
        goto LAB_00c6fb7e;
      }
    }
    plVar27 = (locale *)0x0;
    if (lVar29 != 3) goto LAB_00c7003f;
LAB_00c6fb88:
    iVar9 = (int)uVar24;
    if ((1 < local_100 & (byte)plVar27) == 0) {
      if ((byte)plVar27 != 0) goto joined_r0x00c70aa2;
      goto LAB_00c7017d;
    }
    if (bVar32) {
      lVar29 = *(long *)(lVar25 + 0x50);
    }
    else {
      lVar29 = *(long *)(lVar25 + 0x40);
    }
    unaff_R14 = 1;
    iVar9 = (wchar_t)local_a0;
    goto LAB_00c6fc4a;
  case 2:
    if ((*(byte *)(param_6 + 0x19) & 2) == 0) {
      iVar9 = (int)lVar29;
      bVar33 = iVar9 == 0;
      plVar23 = (locale *)CONCAT71((int7)((ulong)plVar23 >> 8),bVar33);
      uVar13 = (ulong)(1 < local_100 || bVar33);
      if (1 >= local_100 && !bVar33) {
        if (iVar9 == 1) {
          if (((local_c9 == false) && ((byte)local_8c != '\x03')) && (local_8c._2_1_ != '\x01'))
          goto LAB_00c703a0;
        }
        else {
          plVar27 = (locale *)0x1;
          if (iVar9 != 2) break;
          if (local_8c._3_1_ != '\x04') {
            if (local_8c._3_1_ != '\x03') goto LAB_00c70385;
            if (local_c9 == false) goto LAB_00c70385;
          }
        }
      }
    }
    local_e8 = *(ulong *)(lVar25 + 0x38);
    unaff_R14 = 0;
    iVar9 = (wchar_t)local_a0;
LAB_00c6ff9e:
    bVar26 = iVar9 == -1;
    bVar33 = local_a8 != (wstreambuf *)0x0 && (bool)bVar26;
    plVar27 = (locale *)CONCAT71((int7)((ulong)plVar27 >> 8),bVar33);
    if (local_a8 != (wstreambuf *)0x0 && (bool)bVar26) {
      if (*(int **)(local_a8 + 0x10) < *(int **)(local_a8 + 0x18)) {
        iVar9 = **(int **)(local_a8 + 0x10);
      }
      else {
        iVar9 = (**(code **)(*(long *)local_a8 + 0x48))();
        plVar23 = extraout_RDX_30;
      }
      bVar26 = 0;
      if (iVar9 == -1) {
        local_a8 = (wstreambuf *)0x0;
        bVar26 = bVar33;
      }
    }
LAB_00c6ff10:
    plVar23 = (locale *)CONCAT71((int7)((ulong)plVar23 >> 8),param_5 == -1);
    uVar28 = (undefined7)((ulong)plVar27 >> 8);
    bVar33 = local_b8 != (char **)0x0 && param_5 == -1;
    plVar27 = (locale *)CONCAT71(uVar28,bVar33);
    if (bVar33) {
      if (local_b8[2] < local_b8[3]) {
        iVar9 = *(int *)local_b8[2];
      }
      else {
        iVar9 = (**(code **)(*local_b8 + 0x48))();
      }
      plVar23 = (locale *)0x0;
      if (iVar9 != -1) goto LAB_00c6ff2d;
      plVar23 = (locale *)((ulong)plVar27 & 0xffffffff);
      local_b8 = (char **)0x0;
      if (((bVar26 ^ 1) & unaff_R14 < local_e8) == 0) goto LAB_00c70720;
LAB_00c6ff41:
      iVar9 = (wchar_t)local_a0;
      if ((local_a8 != (wstreambuf *)0x0) && ((wchar_t)local_a0 == -1)) {
        if (*(int **)(local_a8 + 0x10) < *(int **)(local_a8 + 0x18)) {
          iVar9 = **(int **)(local_a8 + 0x10);
        }
        else {
          iVar9 = (**(code **)(*(long *)local_a8 + 0x48))();
        }
        if (iVar9 == -1) {
          local_a8 = (wstreambuf *)0x0;
        }
      }
      plVar23 = *(locale **)(lVar25 + 0x30);
      if (*(int *)(plVar23 + unaff_R14 * 4) != iVar9) goto LAB_00c7072b;
      if (*(ulong *)(local_a8 + 0x10) < *(ulong *)(local_a8 + 0x18)) {
        *(ulong *)(local_a8 + 0x10) = *(ulong *)(local_a8 + 0x10) + 4;
      }
      else {
        (**(code **)(*(long *)local_a8 + 0x50))();
        plVar23 = extraout_RDX_25;
      }
      local_a0 = CONCAT44(local_a0._4_4_,0xffffffff);
      unaff_R14 = unaff_R14 + 1;
      iVar9 = -1;
      goto LAB_00c6ff9e;
    }
LAB_00c6ff2d:
    if (((bVar26 ^ (byte)plVar23) & unaff_R14 < local_e8) != 0) goto LAB_00c6ff41;
LAB_00c70720:
    if (unaff_R14 == local_e8) goto LAB_00c703a0;
LAB_00c7072b:
    if (unaff_R14 == 0) {
      bVar33 = (*(uint *)(param_6 + 0x18) & 0x200) == 0;
      plVar27 = (locale *)CONCAT71(uVar28,bVar33);
      uVar13 = (ulong)!bVar33;
      break;
    }
    goto LAB_00c7017d;
  case 3:
    if (*(long *)(lVar25 + 0x48) == 0) {
      if (*(long *)(lVar25 + 0x58) != 0) {
LAB_00c70538:
        uVar8 = FUN_00c56c30(&local_a8);
        uVar13 = (ulong)uVar8;
        plVar23 = extraout_RDX_23;
        if ((char)uVar8 == '\0') {
          iVar9 = FUN_00c61d10(&local_a8);
          plVar23 = *(locale **)(lVar25 + 0x50);
          if (*(int *)plVar23 == iVar9) {
            local_100 = *(ulong *)(lVar25 + 0x58);
            std::wstreambuf::sbumpc(local_a8);
            plVar27 = (locale *)0x1;
            bVar32 = true;
            local_a0 = CONCAT44(local_a0._4_4_,0xffffffff);
            plVar23 = extraout_RDX_28;
            break;
          }
        }
        if ((*(long *)(lVar25 + 0x48) != 0) && (*(long *)(lVar25 + 0x58) == 0)) goto LAB_00c70490;
      }
LAB_00c6fe76:
      uVar13 = (ulong)local_c9;
switchD_00c6e830_caseD_7:
      plVar27 = (locale *)(ulong)((uint)uVar13 ^ 1);
    }
    else {
      bVar33 = (wchar_t)local_a0 == -1;
      if (local_a8 != (wstreambuf *)0x0 && bVar33) {
        if (*(int **)(local_a8 + 0x10) < *(int **)(local_a8 + 0x18)) {
          iVar9 = **(int **)(local_a8 + 0x10);
        }
        else {
          iVar9 = (**(code **)(*(long *)local_a8 + 0x48))();
          plVar23 = extraout_RDX_31;
        }
        bVar33 = false;
        if (iVar9 == -1) {
          local_a8 = (wstreambuf *)0x0;
          bVar33 = true;
        }
      }
      plVar23 = (locale *)CONCAT71((int7)((ulong)plVar23 >> 8),param_5 == -1);
      bVar30 = local_b8 != (char **)0x0 && param_5 == -1;
      if (bVar30) {
        if (local_b8[2] < local_b8[3]) {
          iVar9 = *(int *)local_b8[2];
        }
        else {
          iVar9 = (**(code **)(*local_b8 + 0x48))();
        }
        plVar23 = (locale *)0x0;
        if (iVar9 == -1) {
          local_b8 = (char **)0x0;
          plVar23 = (locale *)(CONCAT71(uVar28,bVar30) & 0xffffffff);
        }
      }
      if (bVar33 != SUB81(plVar23,0)) {
        iVar9 = (wchar_t)local_a0;
        if (((wchar_t)local_a0 == -1) && (local_a8 != (wstreambuf *)0x0)) {
          if (*(int **)(local_a8 + 0x10) < *(int **)(local_a8 + 0x18)) {
            iVar9 = **(int **)(local_a8 + 0x10);
          }
          else {
            iVar9 = (**(code **)(*(long *)local_a8 + 0x48))();
          }
          if (iVar9 == -1) {
            local_a8 = (wstreambuf *)0x0;
          }
        }
        plVar23 = *(locale **)(lVar25 + 0x40);
        if (*(int *)plVar23 == iVar9) {
          local_100 = *(ulong *)(lVar25 + 0x48);
          std::wstreambuf::sbumpc(local_a8);
          local_a0 = CONCAT44(local_a0._4_4_,0xffffffff);
          uVar13 = 0;
          plVar27 = (locale *)0x1;
          plVar23 = extraout_RDX_27;
          break;
        }
      }
      if (*(long *)(lVar25 + 0x58) != 0) goto LAB_00c70538;
      if (*(long *)(lVar25 + 0x48) == 0) goto LAB_00c6fe76;
LAB_00c70490:
      uVar13 = 0;
      plVar27 = (locale *)0x1;
      bVar32 = true;
    }
    break;
  case 4:
    iVar9 = (wchar_t)local_a0;
    do {
      bVar33 = iVar9 == -1;
      uVar28 = (undefined7)((ulong)plVar27 >> 8);
      if (local_a8 != (wstreambuf *)0x0 && bVar33) {
        if (*(int **)(local_a8 + 0x10) < *(int **)(local_a8 + 0x18)) {
          iVar9 = **(int **)(local_a8 + 0x10);
        }
        else {
          iVar9 = (**(code **)(*(long *)local_a8 + 0x48))();
          plVar23 = extraout_RDX_26;
        }
        bVar33 = false;
        if (iVar9 == -1) {
          local_a8 = (wstreambuf *)0x0;
          bVar33 = true;
        }
      }
      plVar23 = (locale *)CONCAT71((int7)((ulong)plVar23 >> 8),param_5 == -1);
      bVar30 = local_b8 != (char **)0x0 && param_5 == -1;
      if (bVar30) {
        if (local_b8[2] < local_b8[3]) {
          iVar9 = *(int *)local_b8[2];
        }
        else {
          iVar9 = (**(code **)(*local_b8 + 0x48))();
        }
        plVar23 = (locale *)0x0;
        if (iVar9 != -1) goto LAB_00c6fd7f;
        local_b8 = (char **)0x0;
        plVar23 = (locale *)(CONCAT71(uVar28,bVar30) & 0xffffffff);
        bVar30 = SUB81(plVar23,0);
      }
      else {
LAB_00c6fd7f:
        bVar30 = SUB81(plVar23,0);
      }
      if (bVar33 == bVar30) goto LAB_00c70160;
                    /* WARNING: Read-only address (ram,0x00d9875b) is written */
      wVar10 = (wchar_t)local_a0;
      if ((local_a8 != (wstreambuf *)0x0) && ((wchar_t)local_a0 == L'\xffffffff')) {
        if (*(wchar_t **)(local_a8 + 0x10) < *(wchar_t **)(local_a8 + 0x18)) {
          wVar10 = **(wchar_t **)(local_a8 + 0x10);
        }
        else {
          wVar10 = (**(code **)(*(long *)local_a8 + 0x48))();
        }
        if (wVar10 == L'\xffffffff') {
          local_a8 = (wstreambuf *)0x0;
        }
      }
      pwVar18 = wmemchr((wchar_t *)(lVar25 + 0x70),wVar10,10);
      plVar6 = local_60;
      plVar22 = local_80;
      iVar9 = (int)uVar24;
      if (pwVar18 == (wchar_t *)0x0) {
        bVar26 = *(wchar_t *)(lVar25 + 0x24) != wVar10 | local_cb;
        plVar27 = (locale *)CONCAT71(uVar28,bVar26);
        plVar23 = extraout_RDX_17;
        if (bVar26 == 0) {
          if (*(int *)(lVar25 + 0x60) < 1) goto LAB_00c70c53;
          uVar24 = 0;
          local_cb = 1;
          local_d0 = iVar9;
        }
        else {
          if (*(byte *)(lVar25 + 0x20) == 0) goto LAB_00c70166;
          if (*(wchar_t *)(lVar25 + 0x28) != wVar10) {
            plVar27 = (locale *)(ulong)*(byte *)(lVar25 + 0x20);
            goto LAB_00c70166;
          }
          if (local_cb != 0) {
            plVar27 = (locale *)(ulong)local_cb;
            goto LAB_00c70166;
          }
          if (iVar9 == 0) {
            plVar27 = (locale *)0x0;
            goto LAB_00c70166;
          }
          plVar27 = local_80 + 1;
          if (local_88 == &local_78) {
            plVar23 = (locale *)0xf;
          }
          else {
            plVar23 = (locale *)CONCAT71(uStack_77,local_78);
          }
          ppcVar20 = &local_88;
          if (plVar23 < plVar27) {
            ppcVar20 = (char **)0x0;
            std::__cxx11::string::_M_mutate((ulong)&local_88,(ulong)local_80,(char *)0x0,0);
            plVar23 = extraout_RDX_20;
          }
          local_88[(long)plVar22] = (char)uVar24;
          uVar24 = 0;
          (local_88 + 1)[(long)plVar22] = '\0';
          local_80 = plVar27;
        }
      }
      else {
        plVar27 = local_60 + 1;
        cVar34 = std::money_base::_S_atoms[(long)pwVar18 - (lVar25 + 0x6c) >> 2];
        unaff_R14 = 0;
        if (local_68 == &local_58) {
          plVar23 = (locale *)0xf;
        }
        else {
          plVar23 = (locale *)CONCAT71(uStack_57,local_58);
        }
        ppcVar20 = &local_68;
        if (plVar23 < plVar27) {
          ppcVar20 = (char **)0x0;
          std::__cxx11::string::_M_mutate((ulong)&local_68,(ulong)local_60,(char *)0x0,0);
          plVar23 = extraout_RDX_19;
        }
        local_68[(long)plVar6] = cVar34;
        uVar24 = (ulong)(iVar9 + 1);
        (local_68 + 1)[(long)plVar6] = '\0';
        local_60 = plVar27;
      }
LAB_00c6fd1d:
      if (*(ulong *)(local_a8 + 0x10) < *(ulong *)(local_a8 + 0x18)) {
        *(ulong *)(local_a8 + 0x10) = *(ulong *)(local_a8 + 0x10) + 4;
      }
      else {
        (**(code **)(*(long *)local_a8 + 0x50))();
        plVar23 = extraout_RDX_21;
      }
      local_a0 = CONCAT44(local_a0._4_4_,0xffffffff);
      iVar9 = -1;
    } while( true );
  case 5:
    uVar21 = SUB82(plVar23,0);
    if (!SCARRY8(lVar16,0xd98708)) {
      uVar8 = in(uVar21);
                    /* WARNING: Could not recover jumptable at 0x00d9870b. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      pwVar19 = (wstreambuf *)(*(code *)(ulong)uVar8)();
      return pwVar19;
    }
    cVar7 = (char)puVar17;
    *(char *)puVar17 = (char)*puVar17 + cVar7;
    if ((char)*puVar17 != '\0') {
      uVar3 = *(uint *)("NSt7__cxx1115numpunct_bynameIwEE" + lVar16);
      *(uint *)ppcVar20 = *(uint *)ppcVar20 ^ 0xd98708;
      uRam000000007146fcff = uRam000000007146fcff ^ 0xd98708;
      if (uRam000000007146fcff == 0) {
        uVar8 = *(uint *)((ulong)uVar3 + 0x62 + uVar24 * 2);
      }
      *(uint *)ppcVar20 = *(uint *)ppcVar20 ^ uVar8;
      if (*(byte *)(lVar25 + 0x65) < (byte)((ulong)ppcVar20 >> 8)) {
                    /* WARNING: Bad instruction - Truncating control flow here */
        halt_baddata();
      }
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    }
    *(char *)puVar17 = (char)*puVar17 + cVar7;
    *(char *)puVar17 = (char)*puVar17 + cVar7;
                    /* WARNING (jumptable): Read-only address (ram,0x00d9875b) is written */
                    /* WARNING: Read-only address (ram,0x00d9875b) is written */
    s_NSt7__cxx1114collate_bynameIwEE_00d98740[0x1b] = (char)ppcVar20 + 'I';
    uVar4 = *(uint *)("NSt7__cxx1115numpunct_bynameIwEE" + lVar16);
    *(uint *)ppcVar20 = *(uint *)ppcVar20 ^ 0xd98708;
    *puVar17 = *puVar17 ^ 0xd98708;
    uVar8 = *puVar17;
    uVar3 = *puVar17;
    uVar2 = in(uVar21);
    *(undefined4 *)(ulong)uVar4 = uVar2;
    out(0xffed7470,uVar21);
    out((char)(&UINT_00d9870c)[(ulong)bVar35 * -2],uVar21);
    if (((int)uVar8 < 0) && (uVar3 == 0)) {
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    }
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
LAB_00c7036f:
  while( true ) {
    if ((3 < (int)lVar29 + 1) || ((char)uVar13 != '\0')) goto LAB_00c6fb88;
LAB_00c70385:
    lVar29 = lVar29 + 1;
    puVar15 = &local_8c;
    if (*(byte *)((long)&local_8c + lVar29) < 5) break;
LAB_00c703a0:
    uVar13 = 0;
    plVar27 = (locale *)0x1;
  }
  goto LAB_00c6fb5d;
LAB_00c70c53:
  local_cb = 0;
LAB_00c70160:
  plVar27 = (locale *)0x1;
LAB_00c70166:
  if (local_60 == (locale *)0x0) goto LAB_00c7017d;
LAB_00c70368:
  uVar13 = (ulong)((uint)plVar27 ^ 1);
  goto LAB_00c7036f;
LAB_00c6fc4a:
  cVar34 = iVar9 == -1;
  uVar13 = (ulong)(local_a8 != (wstreambuf *)0x0 && (bool)cVar34);
  if (local_a8 != (wstreambuf *)0x0 && (bool)cVar34) {
    if (*(int **)(local_a8 + 0x10) < *(int **)(local_a8 + 0x18)) {
      iVar9 = **(int **)(local_a8 + 0x10);
    }
    else {
      iVar9 = (**(code **)(*(long *)local_a8 + 0x48))();
    }
    cVar34 = '\0';
    if (iVar9 == -1) {
      local_a8 = (wstreambuf *)0x0;
code_r0x00c6fc8c:
      cVar34 = (char)uVar13;
    }
  }
  iVar9 = (int)uVar24;
  bVar30 = param_5 == -1;
  bVar33 = local_b8 != (char **)0x0 && bVar30;
  if (local_b8 != (char **)0x0 && bVar30) {
    if (local_b8[2] < local_b8[3]) {
      iVar11 = *(int *)local_b8[2];
    }
    else {
      iVar11 = (**(code **)(*local_b8 + 0x48))();
    }
    bVar30 = false;
    if (iVar11 != -1) goto LAB_00c6fbe5;
    local_b8 = (char **)0x0;
    if (unaff_R14 < local_100) goto LAB_00c6fbf0;
LAB_00c705b0:
    if (unaff_R14 == local_100) goto joined_r0x00c70aa2;
    goto LAB_00c7017d;
  }
LAB_00c6fbe5:
  bVar33 = bVar30;
  if (local_100 <= unaff_R14) goto LAB_00c705b0;
LAB_00c6fbf0:
  if ((bool)cVar34 == bVar33) goto LAB_00c705b0;
  iVar9 = (wchar_t)local_a0;
  if ((local_a8 != (wstreambuf *)0x0) && ((wchar_t)local_a0 == -1)) {
    if (*(int **)(local_a8 + 0x10) < *(int **)(local_a8 + 0x18)) {
      iVar9 = **(int **)(local_a8 + 0x10);
    }
    else {
      iVar9 = (**(code **)(*(long *)local_a8 + 0x48))();
    }
    if (iVar9 == -1) {
      local_a8 = (wstreambuf *)0x0;
    }
  }
  if (*(int *)(lVar29 + unaff_R14 * 4) != iVar9) goto LAB_00c7017d;
  if (*(ulong *)(local_a8 + 0x10) < *(ulong *)(local_a8 + 0x18)) {
    *(ulong *)(local_a8 + 0x10) = *(ulong *)(local_a8 + 0x10) + 4;
  }
  else {
    (**(code **)(*(long *)local_a8 + 0x50))();
  }
  local_a0 = CONCAT44(local_a0._4_4_,0xffffffff);
  unaff_R14 = unaff_R14 + 1;
  iVar9 = -1;
  goto LAB_00c6fc4a;
LAB_00c6f913:
  local_cb = 0;
LAB_00c6ee20:
  plVar27 = (locale *)0x1;
LAB_00c6ee26:
  if (local_60 == (locale *)0x0) goto LAB_00c6ee3d;
LAB_00c6f028:
  uVar13 = (ulong)((uint)plVar27 ^ 1);
  goto LAB_00c6f02f;
LAB_00c6e90a:
  bVar30 = iVar9 == -1;
  bVar31 = local_a8 != (wstreambuf *)0x0;
  bVar33 = bVar30;
  if (bVar31 && bVar30) {
    if (*(int **)(local_a8 + 0x10) < *(int **)(local_a8 + 0x18)) {
      iVar9 = **(int **)(local_a8 + 0x10);
    }
    else {
      iVar9 = (**(code **)(*(long *)local_a8 + 0x48))();
    }
    bVar33 = false;
    if (iVar9 == -1) {
      local_a8 = (wstreambuf *)0x0;
      bVar33 = bVar31 && bVar30;
    }
  }
  bVar31 = param_5 == -1;
  bVar30 = local_b8 != (char **)0x0 && bVar31;
  if (local_b8 != (char **)0x0 && bVar31) {
    if (local_b8[2] < local_b8[3]) {
      iVar9 = *(int *)local_b8[2];
    }
    else {
      iVar9 = (**(code **)(*local_b8 + 0x48))();
    }
    bVar31 = false;
    if (iVar9 != -1) goto LAB_00c6e8a5;
    local_b8 = (char **)0x0;
    if (uVar13 < local_100) goto LAB_00c6e8b0;
LAB_00c6f270:
    if (uVar13 == local_100) goto joined_r0x00c6f762;
    goto LAB_00c6ee3d;
  }
LAB_00c6e8a5:
  bVar30 = bVar31;
  if (local_100 <= uVar13) goto LAB_00c6f270;
LAB_00c6e8b0:
  if (bVar33 == bVar30) goto LAB_00c6f270;
  iVar9 = (wchar_t)local_a0;
  if ((local_a8 != (wstreambuf *)0x0) && ((wchar_t)local_a0 == -1)) {
    if (*(int **)(local_a8 + 0x10) < *(int **)(local_a8 + 0x18)) {
      iVar9 = **(int **)(local_a8 + 0x10);
    }
    else {
      iVar9 = (**(code **)(*(long *)local_a8 + 0x48))();
    }
    if (iVar9 == -1) {
      local_a8 = (wstreambuf *)0x0;
    }
  }
  if (*(int *)(lVar29 + uVar13 * 4) != iVar9) goto LAB_00c6ee3d;
  if (*(ulong *)(local_a8 + 0x10) < *(ulong *)(local_a8 + 0x18)) {
    *(ulong *)(local_a8 + 0x10) = *(ulong *)(local_a8 + 0x10) + 4;
  }
  else {
    (**(code **)(*(long *)local_a8 + 0x50))();
  }
  local_a0 = CONCAT44(local_a0._4_4_,0xffffffff);
  uVar13 = uVar13 + 1;
  iVar9 = -1;
  goto LAB_00c6e90a;
joined_r0x00c70aa2:
  if ((local_60 < (locale *)0x2) ||
     (lVar29 = std::__cxx11::string::find_first_not_of(cVar7,0x30), lVar29 == 0)) goto LAB_00c705ca;
  if (lVar29 == -1) {
    if (local_60 + -1 == (locale *)0xffffffffffffffff) {
      *local_68 = '\0';
      goto LAB_00c705ca;
    }
    if (local_60 + -1 == (locale *)0x0) goto LAB_00c705ca;
  }
  std::__cxx11::string::_M_erase((ulong)&local_68,0);
LAB_00c705ca:
  if ((bVar32) && (*local_68 != '0')) {
    std::__cxx11::string::_M_replace_aux((ulong)&local_68,0,0,'\x01');
  }
  plVar27 = local_80;
  if (local_80 != (locale *)0x0) {
    plVar23 = local_80 + 1;
    if (local_cb == 0) {
      local_d0._0_1_ = (char)iVar9;
    }
    if (local_88 == &local_78) {
      plVar22 = (locale *)0xf;
    }
    else {
      plVar22 = (locale *)CONCAT71(uStack_77,local_78);
    }
    if (plVar22 < plVar23) {
      std::__cxx11::string::_M_mutate((ulong)&local_88,(ulong)local_80,(char *)0x0,0);
    }
    local_88[(long)plVar27] = (char)local_d0;
    (local_88 + 1)[(long)plVar27] = '\0';
    local_80 = plVar23;
    cVar7 = FUN_00c74830(*(undefined8 *)(lVar25 + 0x10),*(undefined8 *)(lVar25 + 0x18),&local_88);
    if (cVar7 == '\0') {
      *param_7 = *param_7 | 4;
    }
  }
  if ((local_cb == 0) || (*(int *)(lVar25 + 0x60) == iVar9)) {
    std::__cxx11::string::swap(param_8);
  }
  else {
LAB_00c7017d:
    *param_7 = *param_7 | 4;
  }
  bVar32 = (wchar_t)local_a0 == -1;
  if (local_a8 != (wstreambuf *)0x0 && bVar32) {
    if (*(int **)(local_a8 + 0x10) < *(int **)(local_a8 + 0x18)) {
      iVar9 = **(int **)(local_a8 + 0x10);
    }
    else {
      iVar9 = (**(code **)(*(long *)local_a8 + 0x48))();
    }
    bVar32 = false;
    if (iVar9 == -1) {
      local_a8 = (wstreambuf *)0x0;
      bVar32 = true;
    }
  }
  bVar33 = param_5 == -1;
  if (local_b8 != (char **)0x0 && bVar33) {
    if (local_b8[2] < local_b8[3]) {
      iVar9 = *(int *)local_b8[2];
    }
    else {
      iVar9 = (**(code **)(*local_b8 + 0x48))();
    }
    bVar33 = false;
    if (iVar9 == -1) {
      bVar33 = true;
    }
  }
  pwVar19 = local_a8;
  if (bVar32 == bVar33) {
    *param_7 = *param_7 | 2;
  }
  if (local_68 != &local_58) {
    operator_delete(local_68);
  }
  if (local_88 != &local_78) {
    operator_delete(local_88);
  }
  if (local_40 == *(long *)(in_FS_OFFSET + 0x28)) {
    return pwVar19;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
joined_r0x00c6f762:
  if ((local_60 < (locale *)0x2) ||
     (lVar29 = std::__cxx11::string::find_first_not_of(cVar7,0x30), lVar29 == 0)) goto LAB_00c6f28a;
  if (lVar29 == -1) {
    if (local_60 + -1 == (locale *)0xffffffffffffffff) {
      *local_68 = '\0';
      goto LAB_00c6f28a;
    }
    if (local_60 + -1 == (locale *)0x0) goto LAB_00c6f28a;
  }
  std::__cxx11::string::_M_erase((ulong)&local_68,0);
LAB_00c6f28a:
  if ((bVar32) && (*local_68 != '0')) {
    std::__cxx11::string::_M_replace_aux((ulong)&local_68,0,0,'\x01');
  }
  plVar27 = local_80;
  if (local_80 != (locale *)0x0) {
    plVar23 = local_80 + 1;
    if (local_cb == 0) {
      local_d0._0_1_ = (char)uVar24;
    }
    if (local_88 == &local_78) {
      plVar22 = (locale *)0xf;
    }
    else {
      plVar22 = (locale *)CONCAT71(uStack_77,local_78);
    }
    if (plVar22 < plVar23) {
      std::__cxx11::string::_M_mutate((ulong)&local_88,(ulong)local_80,(char *)0x0,0);
    }
    local_88[(long)plVar27] = (char)local_d0;
    (local_88 + 1)[(long)plVar27] = '\0';
    local_80 = plVar23;
    cVar7 = FUN_00c74830(*(undefined8 *)(lVar25 + 0x10),*(undefined8 *)(lVar25 + 0x18),&local_88);
    if (cVar7 == '\0') {
      *param_7 = *param_7 | 4;
    }
  }
  if ((local_cb == 0) || (*(int *)(lVar25 + 0x60) == (int)uVar24)) {
    std::__cxx11::string::swap(param_8);
  }
  else {
LAB_00c6ee3d:
    *param_7 = *param_7 | 4;
  }
  bVar32 = (wchar_t)local_a0 == -1;
  if (local_a8 != (wstreambuf *)0x0 && bVar32) {
    if (*(int **)(local_a8 + 0x10) < *(int **)(local_a8 + 0x18)) {
      iVar9 = **(int **)(local_a8 + 0x10);
    }
    else {
      iVar9 = (**(code **)(*(long *)local_a8 + 0x48))();
    }
    bVar32 = false;
    if (iVar9 == -1) {
      local_a8 = (wstreambuf *)0x0;
      bVar32 = true;
    }
  }
  bVar33 = param_5 == -1;
  if (local_b8 != (char **)0x0 && bVar33) {
    if (local_b8[2] < local_b8[3]) {
      iVar9 = *(int *)local_b8[2];
    }
    else {
      iVar9 = (**(code **)(*local_b8 + 0x48))();
    }
    bVar33 = false;
    if (iVar9 == -1) {
      bVar33 = true;
    }
  }
  pwVar19 = local_a8;
  if (bVar32 == bVar33) {
    *param_7 = *param_7 | 2;
  }
  if (local_68 != &local_58) {
    operator_delete(local_68);
  }
  if (local_88 != &local_78) {
    operator_delete(local_88);
  }
  if (local_40 == *(long *)(in_FS_OFFSET + 0x28)) {
    return pwVar19;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ==== entry=00c6f9d0 name=FUN_00c6f9d0 size=4559 ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Removing unreachable block (ram,0x00d987fb) */
/* WARNING: Removing unreachable block (ram,0x00d98881) */
/* WARNING: Removing unreachable block (ram,0x00d9883b) */
/* WARNING: Removing unreachable block (ram,0x00d98799) */
/* WARNING: Restarted to delay deadcode elimination for space: stack */

wstreambuf *
FUN_00c6f9d0(undefined8 param_1,wstreambuf *param_2,ulong param_3,char **param_4,int param_5,
            long param_6,uint *param_7,string *param_8)

{
  long *plVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  locale *plVar5;
  char cVar6;
  wchar_t __c;
  int iVar7;
  uint uVar8;
  ctype *pcVar9;
  ulong uVar10;
  long lVar11;
  uint *puVar12;
  wchar_t *pwVar13;
  __moneypunct_cache<wchar_t,false> *this;
  wstreambuf *pwVar14;
  char **ppcVar15;
  undefined2 uVar16;
  locale *extraout_RDX;
  locale *extraout_RDX_00;
  locale *extraout_RDX_01;
  locale *extraout_RDX_02;
  locale *extraout_RDX_03;
  locale *extraout_RDX_04;
  locale *plVar17;
  locale *extraout_RDX_05;
  locale *extraout_RDX_06;
  locale *extraout_RDX_07;
  locale *extraout_RDX_08;
  locale *extraout_RDX_09;
  locale *extraout_RDX_10;
  locale *extraout_RDX_11;
  locale *extraout_RDX_12;
  locale *extraout_RDX_13;
  locale *extraout_RDX_14;
  locale *plVar18;
  locale *extraout_RDX_15;
  locale *extraout_RDX_16;
  long lVar19;
  byte bVar20;
  undefined7 uVar22;
  locale *plVar21;
  ulong unaff_R14;
  ulong uVar23;
  long lVar24;
  long in_FS_OFFSET;
  bool bVar25;
  bool bVar26;
  bool bVar27;
  bool bVar28;
  byte bVar29;
  ulong local_100;
  int local_d0;
  byte local_cb;
  bool local_c9;
  char **local_b8;
  wstreambuf *local_a8;
  ulong local_a0;
  undefined4 local_8c;
  char *local_88;
  locale *local_80;
  char local_78;
  undefined7 uStack_77;
  char *local_68;
  locale *local_60;
  char local_58;
  undefined7 uStack_57;
  long local_40;
  
  bVar29 = 0;
  plVar21 = (locale *)(param_6 + 0xd0);
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  ppcVar15 = param_4;
  local_a8 = param_2;
  local_a0 = param_3;
  pcVar9 = std::use_facet<std::ctype<wchar_t>>(plVar21);
  uVar10 = std::locale::id::_M_id((id *)&DAT_011c5538);
  plVar1 = (long *)(*(long *)(*(long *)(param_6 + 0xd0) + 0x18) + uVar10 * 8);
  lVar19 = *plVar1;
  if (lVar19 == 0) {
                    /* try { // try from 00c709e5 to 00c709e9 has its CatchHandler @ 00c70c92 */
    this = operator_new(0xa0);
    *(undefined4 *)(this + 8) = 0;
    *(undefined8 *)(this + 0x10) = 0;
    *(undefined8 *)(this + 0x18) = 0;
    *(undefined ***)this = &PTR____moneypunct_cache_011b2878;
    this[0x20] = (__moneypunct_cache<wchar_t,false>)0x0;
    *(undefined8 *)(this + 0x24) = 0;
    *(undefined8 *)(this + 0x30) = 0;
    *(undefined8 *)(this + 0x38) = 0;
    *(undefined8 *)(this + 0x40) = 0;
    *(undefined8 *)(this + 0x48) = 0;
    *(undefined8 *)(this + 0x50) = 0;
    *(undefined8 *)(this + 0x58) = 0;
    *(undefined8 *)(this + 0x60) = 0;
    *(undefined4 *)(this + 0x68) = 0;
    this[0x98] = (__moneypunct_cache<wchar_t,false>)0x0;
                    /* try { // try from 00c70a6b to 00c70a6f has its CatchHandler @ 00c70c90 */
    std::__moneypunct_cache<wchar_t,false>::_M_cache(this,plVar21);
    std::locale::_Impl::_M_install_cache(*(_Impl **)(param_6 + 0xd0),(facet *)this,uVar10);
    lVar19 = *plVar1;
  }
  if (*(long *)(lVar19 + 0x48) == 0) {
    local_c9 = false;
  }
  else {
    local_c9 = *(long *)(lVar19 + 0x58) != 0;
  }
  local_80 = (locale *)0x0;
  local_88 = &local_78;
  local_78 = '\0';
  if (*(char *)(lVar19 + 0x20) != '\0') {
                    /* try { // try from 00c6fac8 to 00c6facc has its CatchHandler @ 00c70cbf */
    std::__cxx11::string::reserve((ulong)&local_88);
  }
  local_60 = (locale *)0x0;
  local_68 = &local_58;
  local_58 = '\0';
                    /* try { // try from 00c6faff to 00c70963 has its CatchHandler @ 00c70cba */
  std::__cxx11::string::reserve((ulong)&local_68);
  lVar24 = 0;
  uVar10 = 0;
  local_cb = 0;
  local_8c = *(undefined4 *)(lVar19 + 0x68);
  local_d0 = 0;
  local_100 = 0;
  bVar27 = false;
  plVar17 = extraout_RDX;
  local_b8 = param_4;
  if (4 < (byte)local_8c) goto LAB_00c703a0;
LAB_00c6fb5d:
  uVar8 = 0xd98708;
  lVar11 = (long)(int)(&switchD_00c6fb70::caseD_5)[*(byte *)((long)&local_8c + lVar24)];
  puVar12 = (uint *)((long)&switchD_00c6fb70::caseD_5 + lVar11);
  uVar22 = (undefined7)((ulong)plVar21 >> 8);
                    /* WARNING (jumptable): Sanity check requires truncation of jumptable */
                    /* WARNING: Could not find normalized switch variable to match jumptable */
  switch(*(byte *)((long)&local_8c + lVar24)) {
  case 0:
    plVar21 = (locale *)0x1;
LAB_00c6fb7e:
    if (lVar24 == 3) goto LAB_00c6fb88;
LAB_00c7003f:
    iVar7 = (wchar_t)local_a0;
    while( true ) {
      bVar25 = iVar7 == -1;
      bVar26 = local_a8 != (wstreambuf *)0x0;
      bVar28 = bVar25;
      if (bVar26 && bVar25) {
        if (*(int **)(local_a8 + 0x10) < *(int **)(local_a8 + 0x18)) {
          iVar7 = **(int **)(local_a8 + 0x10);
        }
        else {
          iVar7 = (**(code **)(*(long *)local_a8 + 0x48))();
          plVar17 = extraout_RDX_12;
        }
        bVar28 = false;
        if (iVar7 == -1) {
          local_a8 = (wstreambuf *)0x0;
          bVar28 = bVar26 && bVar25;
        }
      }
      plVar17 = (locale *)CONCAT71((int7)((ulong)plVar17 >> 8),param_5 == -1);
      bVar25 = local_b8 != (char **)0x0 && param_5 == -1;
      unaff_R14 = CONCAT71((int7)(unaff_R14 >> 8),bVar25);
      if (bVar25) {
        if (local_b8[2] < local_b8[3]) {
          iVar7 = *(int *)local_b8[2];
        }
        else {
                    /* try { // try from 00c70b0f to 00c70c83 has its CatchHandler @ 00c70cba */
          iVar7 = (**(code **)(*local_b8 + 0x48))();
        }
        plVar17 = (locale *)0x0;
        if (iVar7 == -1) {
          local_b8 = (char **)0x0;
          plVar17 = (locale *)(unaff_R14 & 0xffffffff);
        }
      }
      if (bVar28 == SUB81(plVar17,0)) break;
      uVar23 = local_a0 & 0xffffffff;
      if (((wchar_t)local_a0 == -1) && (local_a8 != (wstreambuf *)0x0)) {
        if (*(uint **)(local_a8 + 0x10) < *(uint **)(local_a8 + 0x18)) {
          uVar8 = **(uint **)(local_a8 + 0x10);
        }
        else {
          uVar8 = (**(code **)(*(long *)local_a8 + 0x48))();
        }
        uVar23 = (ulong)uVar8;
        if (uVar8 == 0xffffffff) {
          local_a8 = (wstreambuf *)0x0;
        }
      }
      cVar6 = (**(code **)(*(long *)pcVar9 + 0x10))(pcVar9,0x2000,uVar23);
      plVar17 = extraout_RDX_01;
      if (cVar6 == '\0') break;
      if (*(ulong *)(local_a8 + 0x10) < *(ulong *)(local_a8 + 0x18)) {
        *(ulong *)(local_a8 + 0x10) = *(ulong *)(local_a8 + 0x10) + 4;
      }
      else {
        (**(code **)(*(long *)local_a8 + 0x50))();
        plVar17 = extraout_RDX_07;
      }
      local_a0 = CONCAT44(local_a0._4_4_,0xffffffff);
      iVar7 = -1;
    }
    goto LAB_00c70368;
  case 1:
    bVar28 = (wchar_t)local_a0 == -1;
    if (local_a8 != (wstreambuf *)0x0 && bVar28) {
      if (*(int **)(local_a8 + 0x10) < *(int **)(local_a8 + 0x18)) {
        iVar7 = **(int **)(local_a8 + 0x10);
      }
      else {
        iVar7 = (**(code **)(*(long *)local_a8 + 0x48))();
        plVar17 = extraout_RDX_15;
      }
      bVar28 = false;
      if (iVar7 == -1) {
        local_a8 = (wstreambuf *)0x0;
        bVar28 = true;
      }
    }
    plVar17 = (locale *)CONCAT71((int7)((ulong)plVar17 >> 8),param_5 == -1);
    bVar25 = local_b8 != (char **)0x0 && param_5 == -1;
    if (bVar25) {
      if (local_b8[2] < local_b8[3]) {
        iVar7 = *(int *)local_b8[2];
      }
      else {
        iVar7 = (**(code **)(*local_b8 + 0x48))();
      }
      plVar17 = (locale *)0x0;
      if (iVar7 == -1) {
        local_b8 = (char **)0x0;
        plVar17 = (locale *)(CONCAT71(uVar22,bVar25) & 0xffffffff);
      }
    }
    if (bVar28 != SUB81(plVar17,0)) {
      uVar23 = local_a0 & 0xffffffff;
      if (((wchar_t)local_a0 == -1) && (local_a8 != (wstreambuf *)0x0)) {
        if (*(uint **)(local_a8 + 0x10) < *(uint **)(local_a8 + 0x18)) {
          uVar8 = **(uint **)(local_a8 + 0x10);
        }
        else {
          uVar8 = (**(code **)(*(long *)local_a8 + 0x48))();
        }
        uVar23 = (ulong)uVar8;
        if (uVar8 == 0xffffffff) {
          local_a8 = (wstreambuf *)0x0;
        }
      }
      uVar8 = (**(code **)(*(long *)pcVar9 + 0x10))(pcVar9,0x2000,uVar23);
      plVar21 = (locale *)(ulong)uVar8;
      plVar17 = extraout_RDX_05;
      if ((char)uVar8 != '\0') {
        if (*(ulong *)(local_a8 + 0x10) < *(ulong *)(local_a8 + 0x18)) {
          *(ulong *)(local_a8 + 0x10) = *(ulong *)(local_a8 + 0x10) + 4;
        }
        else {
          (**(code **)(*(long *)local_a8 + 0x50))();
          plVar17 = extraout_RDX_16;
        }
        local_a0 = CONCAT44(local_a0._4_4_,0xffffffff);
        goto LAB_00c6fb7e;
      }
    }
    plVar21 = (locale *)0x0;
    if (lVar24 != 3) goto LAB_00c7003f;
LAB_00c6fb88:
    if ((1 < local_100 & (byte)plVar21) == 0) {
      if ((byte)plVar21 != 0) goto joined_r0x00c70aa2;
      goto LAB_00c7017d;
    }
    if (bVar27) {
      lVar24 = *(long *)(lVar19 + 0x50);
    }
    else {
      lVar24 = *(long *)(lVar19 + 0x40);
    }
    uVar23 = 1;
    iVar7 = (wchar_t)local_a0;
    goto LAB_00c6fc4a;
  case 2:
    if ((*(byte *)(param_6 + 0x19) & 2) == 0) {
      iVar7 = (int)lVar24;
      bVar28 = iVar7 == 0;
      plVar17 = (locale *)CONCAT71((int7)((ulong)plVar17 >> 8),bVar28);
      uVar8 = (uint)(1 < local_100 || bVar28);
      if (1 >= local_100 && !bVar28) {
        if (iVar7 == 1) {
          if (((local_c9 == false) && ((byte)local_8c != '\x03')) && (local_8c._2_1_ != '\x01'))
          goto LAB_00c703a0;
        }
        else {
          plVar21 = (locale *)0x1;
          if (iVar7 != 2) break;
          if (local_8c._3_1_ != '\x04') {
            lVar11 = lVar24;
            if (local_8c._3_1_ != '\x03') goto LAB_00c70385;
            if (local_c9 == false) goto LAB_00c70385;
          }
        }
      }
    }
    uVar23 = *(ulong *)(lVar19 + 0x38);
    unaff_R14 = 0;
    iVar7 = (wchar_t)local_a0;
LAB_00c6ff9e:
    bVar25 = iVar7 == -1;
    bVar26 = local_a8 != (wstreambuf *)0x0;
    uVar22 = (undefined7)((ulong)plVar21 >> 8);
    bVar28 = bVar25;
    if (bVar26 && bVar25) {
      if (*(int **)(local_a8 + 0x10) < *(int **)(local_a8 + 0x18)) {
        iVar7 = **(int **)(local_a8 + 0x10);
      }
      else {
        iVar7 = (**(code **)(*(long *)local_a8 + 0x48))();
        plVar17 = extraout_RDX_13;
      }
      bVar28 = false;
      if (iVar7 == -1) {
        local_a8 = (wstreambuf *)0x0;
        bVar28 = bVar26 && bVar25;
      }
    }
    plVar17 = (locale *)CONCAT71((int7)((ulong)plVar17 >> 8),param_5 == -1);
    bVar25 = local_b8 != (char **)0x0 && param_5 == -1;
    plVar21 = (locale *)CONCAT71(uVar22,bVar25);
    if (bVar25) {
      if (local_b8[2] < local_b8[3]) {
        iVar7 = *(int *)local_b8[2];
      }
      else {
        iVar7 = (**(code **)(*local_b8 + 0x48))();
      }
      plVar17 = (locale *)0x0;
      if (iVar7 != -1) goto LAB_00c6ff2d;
      plVar17 = (locale *)((ulong)plVar21 & 0xffffffff);
      local_b8 = (char **)0x0;
      if (((bVar28 ^ 1U) & unaff_R14 < uVar23) == 0) goto LAB_00c70720;
LAB_00c6ff41:
      iVar7 = (wchar_t)local_a0;
      if ((local_a8 != (wstreambuf *)0x0) && ((wchar_t)local_a0 == -1)) {
        if (*(int **)(local_a8 + 0x10) < *(int **)(local_a8 + 0x18)) {
          iVar7 = **(int **)(local_a8 + 0x10);
        }
        else {
          iVar7 = (**(code **)(*(long *)local_a8 + 0x48))();
        }
        if (iVar7 == -1) {
          local_a8 = (wstreambuf *)0x0;
        }
      }
      plVar17 = *(locale **)(lVar19 + 0x30);
      if (*(int *)(plVar17 + unaff_R14 * 4) != iVar7) goto LAB_00c7072b;
      if (*(ulong *)(local_a8 + 0x10) < *(ulong *)(local_a8 + 0x18)) {
        *(ulong *)(local_a8 + 0x10) = *(ulong *)(local_a8 + 0x10) + 4;
      }
      else {
        (**(code **)(*(long *)local_a8 + 0x50))();
        plVar17 = extraout_RDX_08;
      }
      local_a0 = CONCAT44(local_a0._4_4_,0xffffffff);
      unaff_R14 = unaff_R14 + 1;
      iVar7 = -1;
      goto LAB_00c6ff9e;
    }
LAB_00c6ff2d:
    if (((bVar28 ^ (byte)plVar17) & unaff_R14 < uVar23) != 0) goto LAB_00c6ff41;
LAB_00c70720:
    if (unaff_R14 == uVar23) goto LAB_00c703a0;
LAB_00c7072b:
    if (unaff_R14 == 0) {
      bVar28 = (*(uint *)(param_6 + 0x18) & 0x200) == 0;
      plVar21 = (locale *)CONCAT71(uVar22,bVar28);
      uVar8 = (uint)!bVar28;
      break;
    }
    goto LAB_00c7017d;
  case 3:
    if (*(long *)(lVar19 + 0x48) == 0) {
      if (*(long *)(lVar19 + 0x58) != 0) {
LAB_00c70538:
        uVar8 = FUN_00c56c30(&local_a8);
        plVar17 = extraout_RDX_06;
        if ((char)uVar8 == '\0') {
          iVar7 = FUN_00c61d10(&local_a8);
          plVar17 = *(locale **)(lVar19 + 0x50);
          if (*(int *)plVar17 == iVar7) {
            local_100 = *(ulong *)(lVar19 + 0x58);
            std::wstreambuf::sbumpc(local_a8);
            plVar21 = (locale *)0x1;
            bVar27 = true;
            local_a0 = CONCAT44(local_a0._4_4_,0xffffffff);
            plVar17 = extraout_RDX_11;
            break;
          }
        }
        if ((*(long *)(lVar19 + 0x48) != 0) && (*(long *)(lVar19 + 0x58) == 0)) goto LAB_00c70490;
      }
LAB_00c6fe76:
      uVar8 = (uint)local_c9;
      plVar21 = (locale *)(ulong)(local_c9 ^ 1);
    }
    else {
      bVar28 = (wchar_t)local_a0 == -1;
      if (local_a8 != (wstreambuf *)0x0 && bVar28) {
        if (*(int **)(local_a8 + 0x10) < *(int **)(local_a8 + 0x18)) {
          iVar7 = **(int **)(local_a8 + 0x10);
        }
        else {
          iVar7 = (**(code **)(*(long *)local_a8 + 0x48))();
          plVar17 = extraout_RDX_14;
        }
        bVar28 = false;
        if (iVar7 == -1) {
          local_a8 = (wstreambuf *)0x0;
          bVar28 = true;
        }
      }
      plVar17 = (locale *)CONCAT71((int7)((ulong)plVar17 >> 8),param_5 == -1);
      bVar25 = local_b8 != (char **)0x0 && param_5 == -1;
      if (bVar25) {
        if (local_b8[2] < local_b8[3]) {
          iVar7 = *(int *)local_b8[2];
        }
        else {
          iVar7 = (**(code **)(*local_b8 + 0x48))();
        }
        plVar17 = (locale *)0x0;
        if (iVar7 == -1) {
          local_b8 = (char **)0x0;
          plVar17 = (locale *)(CONCAT71(uVar22,bVar25) & 0xffffffff);
        }
      }
      if (bVar28 != SUB81(plVar17,0)) {
        iVar7 = (wchar_t)local_a0;
        if (((wchar_t)local_a0 == -1) && (local_a8 != (wstreambuf *)0x0)) {
          if (*(int **)(local_a8 + 0x10) < *(int **)(local_a8 + 0x18)) {
            iVar7 = **(int **)(local_a8 + 0x10);
          }
          else {
            iVar7 = (**(code **)(*(long *)local_a8 + 0x48))();
          }
          if (iVar7 == -1) {
            local_a8 = (wstreambuf *)0x0;
          }
        }
        plVar17 = *(locale **)(lVar19 + 0x40);
        if (*(int *)plVar17 == iVar7) {
          local_100 = *(ulong *)(lVar19 + 0x48);
          std::wstreambuf::sbumpc(local_a8);
          local_a0 = CONCAT44(local_a0._4_4_,0xffffffff);
          uVar8 = 0;
          plVar21 = (locale *)0x1;
          plVar17 = extraout_RDX_10;
          break;
        }
      }
      if (*(long *)(lVar19 + 0x58) != 0) goto LAB_00c70538;
      if (*(long *)(lVar19 + 0x48) == 0) goto LAB_00c6fe76;
LAB_00c70490:
      uVar8 = 0;
      plVar21 = (locale *)0x1;
      bVar27 = true;
    }
    break;
  case 4:
    iVar7 = (wchar_t)local_a0;
    do {
      bVar28 = iVar7 == -1;
      uVar22 = (undefined7)((ulong)plVar21 >> 8);
      if (local_a8 != (wstreambuf *)0x0 && bVar28) {
        if (*(int **)(local_a8 + 0x10) < *(int **)(local_a8 + 0x18)) {
          iVar7 = **(int **)(local_a8 + 0x10);
        }
        else {
          iVar7 = (**(code **)(*(long *)local_a8 + 0x48))();
          plVar17 = extraout_RDX_09;
        }
        bVar28 = false;
        if (iVar7 == -1) {
          local_a8 = (wstreambuf *)0x0;
          bVar28 = true;
        }
      }
      plVar17 = (locale *)CONCAT71((int7)((ulong)plVar17 >> 8),param_5 == -1);
      bVar25 = local_b8 != (char **)0x0 && param_5 == -1;
      if (bVar25) {
        if (local_b8[2] < local_b8[3]) {
          iVar7 = *(int *)local_b8[2];
        }
        else {
          iVar7 = (**(code **)(*local_b8 + 0x48))();
        }
        plVar17 = (locale *)0x0;
        if (iVar7 != -1) goto LAB_00c6fd7f;
        local_b8 = (char **)0x0;
        plVar17 = (locale *)(CONCAT71(uVar22,bVar25) & 0xffffffff);
        bVar25 = SUB81(plVar17,0);
      }
      else {
LAB_00c6fd7f:
        bVar25 = SUB81(plVar17,0);
      }
      if (bVar28 == bVar25) goto LAB_00c70160;
                    /* WARNING: Read-only address (ram,0x00d9875b) is written */
      __c = (wchar_t)local_a0;
      if ((local_a8 != (wstreambuf *)0x0) && ((wchar_t)local_a0 == L'\xffffffff')) {
        if (*(wchar_t **)(local_a8 + 0x10) < *(wchar_t **)(local_a8 + 0x18)) {
          __c = **(wchar_t **)(local_a8 + 0x10);
        }
        else {
          __c = (**(code **)(*(long *)local_a8 + 0x48))();
        }
        if (__c == L'\xffffffff') {
          local_a8 = (wstreambuf *)0x0;
        }
      }
      pwVar13 = wmemchr((wchar_t *)(lVar19 + 0x70),__c,10);
      plVar5 = local_60;
      plVar18 = local_80;
      iVar7 = (int)uVar10;
      if (pwVar13 == (wchar_t *)0x0) {
        bVar20 = *(wchar_t *)(lVar19 + 0x24) != __c | local_cb;
        plVar21 = (locale *)CONCAT71(uVar22,bVar20);
        plVar17 = extraout_RDX_00;
        if (bVar20 == 0) {
          if (*(int *)(lVar19 + 0x60) < 1) goto LAB_00c70c53;
          uVar10 = 0;
          local_cb = 1;
          local_d0 = iVar7;
        }
        else {
          if (*(byte *)(lVar19 + 0x20) == 0) goto LAB_00c70166;
          if (*(wchar_t *)(lVar19 + 0x28) != __c) {
            plVar21 = (locale *)(ulong)*(byte *)(lVar19 + 0x20);
            goto LAB_00c70166;
          }
          if (local_cb != 0) {
            plVar21 = (locale *)(ulong)local_cb;
            goto LAB_00c70166;
          }
          if (iVar7 == 0) {
            plVar21 = (locale *)0x0;
            goto LAB_00c70166;
          }
          plVar21 = local_80 + 1;
          if (local_88 == &local_78) {
            plVar17 = (locale *)0xf;
          }
          else {
            plVar17 = (locale *)CONCAT71(uStack_77,local_78);
          }
          ppcVar15 = &local_88;
          if (plVar17 < plVar21) {
            ppcVar15 = (char **)0x0;
            std::__cxx11::string::_M_mutate((ulong)&local_88,(ulong)local_80,(char *)0x0,0);
            plVar17 = extraout_RDX_03;
          }
          local_88[(long)plVar18] = (char)uVar10;
          uVar10 = 0;
          (local_88 + 1)[(long)plVar18] = '\0';
          local_80 = plVar21;
        }
      }
      else {
        plVar21 = local_60 + 1;
        cVar6 = std::money_base::_S_atoms[(long)pwVar13 - (lVar19 + 0x6c) >> 2];
        unaff_R14 = 0;
        if (local_68 == &local_58) {
          plVar17 = (locale *)0xf;
        }
        else {
          plVar17 = (locale *)CONCAT71(uStack_57,local_58);
        }
        ppcVar15 = &local_68;
        if (plVar17 < plVar21) {
          ppcVar15 = (char **)0x0;
          std::__cxx11::string::_M_mutate((ulong)&local_68,(ulong)local_60,(char *)0x0,0);
          plVar17 = extraout_RDX_02;
        }
        local_68[(long)plVar5] = cVar6;
        uVar10 = (ulong)(iVar7 + 1);
        (local_68 + 1)[(long)plVar5] = '\0';
        local_60 = plVar21;
      }
      if (*(ulong *)(local_a8 + 0x10) < *(ulong *)(local_a8 + 0x18)) {
        *(ulong *)(local_a8 + 0x10) = *(ulong *)(local_a8 + 0x10) + 4;
      }
      else {
        (**(code **)(*(long *)local_a8 + 0x50))();
        plVar17 = extraout_RDX_04;
      }
      local_a0 = CONCAT44(local_a0._4_4_,0xffffffff);
      iVar7 = -1;
    } while( true );
  case 5:
    uVar16 = SUB82(plVar17,0);
    if (!SCARRY8(lVar11,0xd98708)) {
      uVar8 = in(uVar16);
                    /* WARNING: Could not recover jumptable at 0x00d9870b. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      pwVar14 = (wstreambuf *)(*(code *)(ulong)uVar8)();
      return pwVar14;
    }
    cVar6 = (char)puVar12;
    *(char *)puVar12 = (char)*puVar12 + cVar6;
    if ((char)*puVar12 != '\0') {
      uVar3 = *(uint *)("NSt7__cxx1115numpunct_bynameIwEE" + lVar11);
      *(uint *)ppcVar15 = *(uint *)ppcVar15 ^ 0xd98708;
      uRam000000007146fcff = uRam000000007146fcff ^ 0xd98708;
      if (uRam000000007146fcff == 0) {
        uVar8 = *(uint *)((ulong)uVar3 + 0x62 + uVar10 * 2);
      }
      *(uint *)ppcVar15 = *(uint *)ppcVar15 ^ uVar8;
      if (*(byte *)(lVar19 + 0x65) < (byte)((ulong)ppcVar15 >> 8)) {
                    /* WARNING: Bad instruction - Truncating control flow here */
        halt_baddata();
      }
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    }
    *(char *)puVar12 = (char)*puVar12 + cVar6;
    *(char *)puVar12 = (char)*puVar12 + cVar6;
                    /* WARNING (jumptable): Read-only address (ram,0x00d9875b) is written */
                    /* WARNING: Read-only address (ram,0x00d9875b) is written */
    s_NSt7__cxx1114collate_bynameIwEE_00d98740[0x1b] = (char)ppcVar15 + 'I';
    uVar4 = *(uint *)("NSt7__cxx1115numpunct_bynameIwEE" + lVar11);
    *(uint *)ppcVar15 = *(uint *)ppcVar15 ^ 0xd98708;
    *puVar12 = *puVar12 ^ 0xd98708;
    uVar8 = *puVar12;
    uVar3 = *puVar12;
    uVar2 = in(uVar16);
    *(undefined4 *)(ulong)uVar4 = uVar2;
    out(0xffed7470,uVar16);
    out((char)(&UINT_00d9870c)[(ulong)bVar29 * -2],uVar16);
    if (((int)uVar8 < 0) && (uVar3 == 0)) {
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    }
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
LAB_00c7036f:
  while( true ) {
    if ((3 < (int)lVar24 + 1) || (lVar11 = lVar24, (char)uVar8 != '\0')) goto LAB_00c6fb88;
LAB_00c70385:
    lVar24 = lVar11 + 1;
    if (*(byte *)((long)&local_8c + lVar11 + 1) < 5) break;
LAB_00c703a0:
    uVar8 = 0;
    plVar21 = (locale *)0x1;
  }
  goto LAB_00c6fb5d;
LAB_00c70c53:
  local_cb = 0;
LAB_00c70160:
  plVar21 = (locale *)0x1;
LAB_00c70166:
  if (local_60 == (locale *)0x0) goto LAB_00c7017d;
LAB_00c70368:
  uVar8 = (uint)plVar21 ^ 1;
  goto LAB_00c7036f;
LAB_00c6fc4a:
  bVar25 = iVar7 == -1;
  bVar26 = local_a8 != (wstreambuf *)0x0;
  bVar28 = bVar25;
  if (bVar26 && bVar25) {
    if (*(int **)(local_a8 + 0x10) < *(int **)(local_a8 + 0x18)) {
      iVar7 = **(int **)(local_a8 + 0x10);
    }
    else {
      iVar7 = (**(code **)(*(long *)local_a8 + 0x48))();
    }
    bVar28 = false;
    if (iVar7 == -1) {
      local_a8 = (wstreambuf *)0x0;
      bVar28 = bVar26 && bVar25;
    }
  }
  bVar26 = param_5 == -1;
  bVar25 = local_b8 != (char **)0x0 && bVar26;
  if (local_b8 != (char **)0x0 && bVar26) {
    if (local_b8[2] < local_b8[3]) {
      iVar7 = *(int *)local_b8[2];
    }
    else {
      iVar7 = (**(code **)(*local_b8 + 0x48))();
    }
    bVar26 = false;
    if (iVar7 != -1) goto LAB_00c6fbe5;
    local_b8 = (char **)0x0;
    if (uVar23 < local_100) goto LAB_00c6fbf0;
LAB_00c705b0:
    if (uVar23 == local_100) goto joined_r0x00c70aa2;
    goto LAB_00c7017d;
  }
LAB_00c6fbe5:
  bVar25 = bVar26;
  if (local_100 <= uVar23) goto LAB_00c705b0;
LAB_00c6fbf0:
  if (bVar28 == bVar25) goto LAB_00c705b0;
  iVar7 = (wchar_t)local_a0;
  if ((local_a8 != (wstreambuf *)0x0) && ((wchar_t)local_a0 == -1)) {
    if (*(int **)(local_a8 + 0x10) < *(int **)(local_a8 + 0x18)) {
      iVar7 = **(int **)(local_a8 + 0x10);
    }
    else {
      iVar7 = (**(code **)(*(long *)local_a8 + 0x48))();
    }
    if (iVar7 == -1) {
      local_a8 = (wstreambuf *)0x0;
    }
  }
  if (*(int *)(lVar24 + uVar23 * 4) != iVar7) goto LAB_00c7017d;
  if (*(ulong *)(local_a8 + 0x10) < *(ulong *)(local_a8 + 0x18)) {
    *(ulong *)(local_a8 + 0x10) = *(ulong *)(local_a8 + 0x10) + 4;
  }
  else {
    (**(code **)(*(long *)local_a8 + 0x50))();
  }
  local_a0 = CONCAT44(local_a0._4_4_,0xffffffff);
  uVar23 = uVar23 + 1;
  iVar7 = -1;
  goto LAB_00c6fc4a;
joined_r0x00c70aa2:
  if ((local_60 < (locale *)0x2) ||
     (lVar24 = std::__cxx11::string::find_first_not_of((char)&local_68,0x30), lVar24 == 0))
  goto LAB_00c705ca;
  if (lVar24 == -1) {
    if (local_60 + -1 == (locale *)0xffffffffffffffff) {
      *local_68 = '\0';
      goto LAB_00c705ca;
    }
    if (local_60 + -1 == (locale *)0x0) goto LAB_00c705ca;
  }
  std::__cxx11::string::_M_erase((ulong)&local_68,0);
LAB_00c705ca:
  if ((bVar27) && (*local_68 != '0')) {
    std::__cxx11::string::_M_replace_aux((ulong)&local_68,0,0,'\x01');
  }
  plVar21 = local_80;
  if (local_80 != (locale *)0x0) {
    plVar17 = local_80 + 1;
    if (local_cb == 0) {
      local_d0._0_1_ = (char)uVar10;
    }
    if (local_88 == &local_78) {
      plVar18 = (locale *)0xf;
    }
    else {
      plVar18 = (locale *)CONCAT71(uStack_77,local_78);
    }
    if (plVar18 < plVar17) {
      std::__cxx11::string::_M_mutate((ulong)&local_88,(ulong)local_80,(char *)0x0,0);
    }
    local_88[(long)plVar21] = (char)local_d0;
    (local_88 + 1)[(long)plVar21] = '\0';
    local_80 = plVar17;
    cVar6 = FUN_00c74830(*(undefined8 *)(lVar19 + 0x10),*(undefined8 *)(lVar19 + 0x18),&local_88);
    if (cVar6 == '\0') {
      *param_7 = *param_7 | 4;
    }
  }
  if ((local_cb == 0) || (*(int *)(lVar19 + 0x60) == (int)uVar10)) {
    std::__cxx11::string::swap(param_8);
  }
  else {
LAB_00c7017d:
    *param_7 = *param_7 | 4;
  }
  bVar27 = (wchar_t)local_a0 == -1;
  if (local_a8 != (wstreambuf *)0x0 && bVar27) {
    if (*(int **)(local_a8 + 0x10) < *(int **)(local_a8 + 0x18)) {
      iVar7 = **(int **)(local_a8 + 0x10);
    }
    else {
      iVar7 = (**(code **)(*(long *)local_a8 + 0x48))();
    }
    bVar27 = false;
    if (iVar7 == -1) {
      local_a8 = (wstreambuf *)0x0;
      bVar27 = true;
    }
  }
  bVar28 = param_5 == -1;
  if (local_b8 != (char **)0x0 && bVar28) {
    if (local_b8[2] < local_b8[3]) {
      iVar7 = *(int *)local_b8[2];
    }
    else {
      iVar7 = (**(code **)(*local_b8 + 0x48))();
    }
    bVar28 = false;
    if (iVar7 == -1) {
      bVar28 = true;
    }
  }
  pwVar14 = local_a8;
  if (bVar27 == bVar28) {
    *param_7 = *param_7 | 2;
  }
  if (local_68 != &local_58) {
    operator_delete(local_68);
  }
  if (local_88 != &local_78) {
    operator_delete(local_88);
  }
  if (local_40 == *(long *)(in_FS_OFFSET + 0x28)) {
    return pwVar14;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ==== entry=00c70d10 name=FUN_00c70d10 size=238 ====

undefined8
FUN_00c70d10(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
            undefined8 param_5,char param_6,undefined8 param_7,_Ios_Iostate *param_8,
            longdouble *param_9)

{
  undefined8 uVar1;
  long in_FS_OFFSET;
  __locale_struct *local_70;
  char *local_68;
  undefined8 local_60;
  char local_58 [24];
  long local_40;
  
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  local_58[0] = '\0';
  local_68 = local_58;
  local_60 = 0;
  if (param_6 == '\0') {
    uVar1 = FUN_00c6f9d0(param_1,param_2,param_3,param_4,param_5,param_7,param_8,&local_68);
  }
  else {
                    /* try { // try from 00c70d69 to 00c70dfd has its CatchHandler @ 00c70e08 */
    uVar1 = FUN_00c6e690(param_1,param_2,param_3,param_4,param_5,param_7,param_8,&local_68);
  }
  local_70 = (__locale_struct *)std::locale::facet::_S_get_c_locale();
  std::__convert_to_v<long_double>(local_68,param_9,param_8,&local_70);
  if (local_68 != local_58) {
    operator_delete(local_68);
  }
  if (local_40 == *(long *)(in_FS_OFFSET + 0x28)) {
    return uVar1;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ==== entry=00c70e30 name=FUN_00c70e30 size=347 ====

undefined8
FUN_00c70e30(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
            undefined8 param_5,char param_6,long param_7,undefined8 param_8,undefined8 *param_9)

{
  long lVar1;
  ctype *pcVar2;
  undefined8 uVar3;
  long in_FS_OFFSET;
  undefined1 *local_68;
  long local_60;
  undefined1 local_58 [24];
  long local_40;
  
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  pcVar2 = std::use_facet<std::ctype<wchar_t>>((locale *)(param_7 + 0xd0));
  local_58[0] = 0;
  local_68 = local_58;
  local_60 = 0;
  if (param_6 == '\0') {
    uVar3 = FUN_00c6f9d0(param_1,param_2,param_3,param_4,param_5,param_7,param_8,&local_68);
  }
  else {
                    /* try { // try from 00c70ed1 to 00c70f8b has its CatchHandler @ 00c70f96 */
    uVar3 = FUN_00c6e690(param_1,param_2,param_3,param_4,param_5,param_7,param_8,&local_68);
  }
  lVar1 = local_60;
  if (local_60 != 0) {
    FUN_00c22c40(param_9,local_60,0);
    (**(code **)(*(long *)pcVar2 + 0x58))(pcVar2,local_68,local_68 + lVar1,*param_9);
  }
  if (local_68 != local_58) {
    operator_delete(local_68);
  }
  if (local_40 == *(long *)(in_FS_OFFSET + 0x28)) {
    return uVar3;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ==== entry=00c70fc0 orig=FUN_00c70fc0 size=57 name=~ctype ====

/* std::ctype<char>::~ctype() */

void __thiscall std::ctype<char>::~ctype(ctype<char> *this)

{
  *(undefined ***)this = &PTR__ctype_011b7a70;
  locale::facet::_S_destroy_c_locale((__locale_struct **)(this + 0x10));
  if ((this[0x18] != (ctype<char>)0x0) && (*(void **)(this + 0x30) != (void *)0x0)) {
    operator_delete__(*(void **)(this + 0x30));
  }
  locale::facet::~facet((facet *)this);
  return;
}


// ==== entry=00c71000 orig=FUN_00c71000 size=51 name=~ctype ====

/* std::ctype<wchar_t>::~ctype() */

void __thiscall std::ctype<wchar_t>::~ctype(ctype<wchar_t> *this)

{
  *(undefined ***)this = &PTR__ctype_011b7ad0;
  locale::facet::_S_destroy_c_locale((__locale_struct **)(this + 0x10));
  *(undefined **)this = &DAT_011b6ad0;
  locale::facet::~facet((facet *)this);
  return;
}


// ==== entry=00c71040 orig=FUN_00c71040 size=19 name=~ctype_byname ====

/* std::ctype_byname<wchar_t>::~ctype_byname() */

void __thiscall std::ctype_byname<wchar_t>::~ctype_byname(ctype_byname<wchar_t> *this)

{
  *(undefined ***)this = &PTR__ctype_byname_011b7b50;
  ctype<wchar_t>::~ctype((ctype<wchar_t> *)this);
  return;
}


// ==== entry=00c71060 orig=FUN_00c71060 size=18 name=~ctype ====

/* std::ctype<char>::~ctype() */

void __thiscall std::ctype<char>::~ctype(ctype<char> *this)

{
  ~ctype(this);
  operator_delete(this);
  return;
}


// ==== entry=00c71080 orig=FUN_00c71080 size=18 name=~ctype ====

/* std::ctype<wchar_t>::~ctype() */

void __thiscall std::ctype<wchar_t>::~ctype(ctype<wchar_t> *this)

{
  ~ctype(this);
  operator_delete(this);
  return;
}


// ==== entry=00c710a0 orig=FUN_00c710a0 size=18 name=~ctype_byname ====

/* std::ctype_byname<wchar_t>::~ctype_byname() */

void __thiscall std::ctype_byname<wchar_t>::~ctype_byname(ctype_byname<wchar_t> *this)

{
  ~ctype_byname(this);
  operator_delete(this);
  return;
}


// ==== entry=00c710c0 orig=FUN_00c710c0 size=476 name=_M_narrow_init ====

/* std::ctype<char>::_M_narrow_init() const */

void __thiscall std::ctype<char>::_M_narrow_init(ctype<char> *this)

{
  int iVar1;
  long lVar2;
  long in_FS_OFFSET;
  char local_139;
  char local_138;
  undefined7 uStack_137;
  undefined8 uStack_130;
  undefined8 local_128;
  undefined8 uStack_120;
  undefined8 local_118;
  undefined8 uStack_110;
  undefined8 local_108;
  undefined8 uStack_100;
  undefined8 local_f8;
  undefined8 uStack_f0;
  undefined8 local_e8;
  undefined8 uStack_e0;
  undefined8 local_d8;
  undefined8 uStack_d0;
  undefined8 local_c8;
  undefined8 uStack_c0;
  undefined8 local_b8;
  undefined8 uStack_b0;
  undefined8 local_a8;
  undefined8 uStack_a0;
  undefined8 local_98;
  undefined8 uStack_90;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined1 local_38 [8];
  long local_30;
  
  local_30 = *(long *)(in_FS_OFFSET + 0x28);
  lVar2 = 0;
  do {
    (&local_138)[lVar2] = (char)lVar2;
    lVar2 = lVar2 + 1;
  } while (lVar2 != 0x100);
  if (*(code **)(*(long *)this + 0x48) == do_narrow) {
    *(ulong *)(this + 0x139) = CONCAT71(uStack_137,local_138);
    *(undefined8 *)(this + 0x141) = uStack_130;
    *(undefined8 *)(this + 0x149) = local_128;
    *(undefined8 *)(this + 0x151) = uStack_120;
    *(undefined8 *)(this + 0x159) = local_118;
    *(undefined8 *)(this + 0x161) = uStack_110;
    *(undefined8 *)(this + 0x169) = local_108;
    *(undefined8 *)(this + 0x171) = uStack_100;
    *(undefined8 *)(this + 0x179) = local_f8;
    *(undefined8 *)(this + 0x181) = uStack_f0;
    *(undefined8 *)(this + 0x189) = local_e8;
    *(undefined8 *)(this + 0x191) = uStack_e0;
    *(undefined8 *)(this + 0x199) = local_d8;
    *(undefined8 *)(this + 0x1a1) = uStack_d0;
    *(undefined8 *)(this + 0x1a9) = local_c8;
    *(undefined8 *)(this + 0x1b1) = uStack_c0;
    *(undefined8 *)(this + 0x1b9) = local_b8;
    *(undefined8 *)(this + 0x1c1) = uStack_b0;
    *(undefined8 *)(this + 0x1c9) = local_a8;
    *(undefined8 *)(this + 0x1d1) = uStack_a0;
    *(undefined8 *)(this + 0x1d9) = local_98;
    *(undefined8 *)(this + 0x1e1) = uStack_90;
    *(undefined8 *)(this + 0x1e9) = local_88;
    *(undefined8 *)(this + 0x1f1) = uStack_80;
    *(undefined8 *)(this + 0x1f9) = local_78;
    *(undefined8 *)(this + 0x201) = uStack_70;
    *(undefined8 *)(this + 0x209) = local_68;
    *(undefined8 *)(this + 0x211) = uStack_60;
    *(undefined8 *)(this + 0x219) = local_58;
    *(undefined8 *)(this + 0x221) = uStack_50;
    *(undefined8 *)(this + 0x229) = local_48;
    *(undefined8 *)(this + 0x231) = uStack_40;
  }
  else {
    (**(code **)(*(long *)this + 0x48))(this,&local_138,local_38,0,this + 0x139);
  }
  this[0x239] = (ctype<char>)0x1;
  iVar1 = memcmp(&local_138,this + 0x139,0x100);
  if (iVar1 == 0) {
    if (*(code **)(*(long *)this + 0x48) == do_narrow) {
      local_139 = local_138;
    }
    else {
      (**(code **)(*(long *)this + 0x48))(this,&local_138,&uStack_137,1,&local_139);
    }
    if (local_139 != '\x01') goto LAB_00c71248;
  }
  this[0x239] = (ctype<char>)0x2;
LAB_00c71248:
  if (local_30 == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ==== entry=00c712a0 orig=FUN_00c712a0 size=380 name=_M_widen_init ====

/* std::ctype<char>::_M_widen_init() const */

void __thiscall std::ctype<char>::_M_widen_init(ctype<char> *this)

{
  int iVar1;
  long lVar2;
  long in_FS_OFFSET;
  undefined8 local_128;
  undefined8 uStack_120;
  undefined8 local_118;
  undefined8 uStack_110;
  undefined8 local_108;
  undefined8 uStack_100;
  undefined8 local_f8;
  undefined8 uStack_f0;
  undefined8 local_e8;
  undefined8 uStack_e0;
  undefined8 local_d8;
  undefined8 uStack_d0;
  undefined8 local_c8;
  undefined8 uStack_c0;
  undefined8 local_b8;
  undefined8 uStack_b0;
  undefined8 local_a8;
  undefined8 uStack_a0;
  undefined8 local_98;
  undefined8 uStack_90;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined1 local_28 [8];
  long local_20;
  
  local_20 = *(long *)(in_FS_OFFSET + 0x28);
  lVar2 = 0;
  do {
    *(char *)((long)&local_128 + lVar2) = (char)lVar2;
    lVar2 = lVar2 + 1;
  } while (lVar2 != 0x100);
  if (*(code **)(*(long *)this + 0x38) == do_widen) {
    *(undefined8 *)(this + 0x39) = local_128;
    *(undefined8 *)(this + 0x41) = uStack_120;
    *(undefined8 *)(this + 0x49) = local_118;
    *(undefined8 *)(this + 0x51) = uStack_110;
    *(undefined8 *)(this + 0x59) = local_108;
    *(undefined8 *)(this + 0x61) = uStack_100;
    *(undefined8 *)(this + 0x69) = local_f8;
    *(undefined8 *)(this + 0x71) = uStack_f0;
    *(undefined8 *)(this + 0x79) = local_e8;
    *(undefined8 *)(this + 0x81) = uStack_e0;
    *(undefined8 *)(this + 0x89) = local_d8;
    *(undefined8 *)(this + 0x91) = uStack_d0;
    *(undefined8 *)(this + 0x99) = local_c8;
    *(undefined8 *)(this + 0xa1) = uStack_c0;
    *(undefined8 *)(this + 0xa9) = local_b8;
    *(undefined8 *)(this + 0xb1) = uStack_b0;
    *(undefined8 *)(this + 0xb9) = local_a8;
    *(undefined8 *)(this + 0xc1) = uStack_a0;
    *(undefined8 *)(this + 0xc9) = local_98;
    *(undefined8 *)(this + 0xd1) = uStack_90;
    *(undefined8 *)(this + 0xd9) = local_88;
    *(undefined8 *)(this + 0xe1) = uStack_80;
    *(undefined8 *)(this + 0xe9) = local_78;
    *(undefined8 *)(this + 0xf1) = uStack_70;
    *(undefined8 *)(this + 0xf9) = local_68;
    *(undefined8 *)(this + 0x101) = uStack_60;
    *(undefined8 *)(this + 0x109) = local_58;
    *(undefined8 *)(this + 0x111) = uStack_50;
    *(undefined8 *)(this + 0x119) = local_48;
    *(undefined8 *)(this + 0x121) = uStack_40;
    *(undefined8 *)(this + 0x129) = local_38;
    *(undefined8 *)(this + 0x131) = uStack_30;
  }
  else {
    (**(code **)(*(long *)this + 0x38))(this,&local_128,local_28,this + 0x39);
  }
  this[0x38] = (ctype<char>)0x1;
  iVar1 = memcmp(&local_128,this + 0x39,0x100);
  if (iVar1 != 0) {
    this[0x38] = (ctype<char>)0x2;
  }
  if (local_20 == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ==== entry=00c71420 orig=FUN_00c71420 size=61 name=ctype ====

/* std::ctype<wchar_t>::ctype(unsigned long) */

void __thiscall std::ctype<wchar_t>::ctype(ctype<wchar_t> *this,ulong param_1)

{
  undefined8 uVar1;
  
  *(uint *)(this + 8) = (uint)(param_1 != 0);
  *(undefined ***)this = &PTR__ctype_011b7ad0;
                    /* try { // try from 00c71442 to 00c71446 has its CatchHandler @ 00c7145d */
  uVar1 = locale::facet::_S_get_c_locale();
  *(undefined8 *)(this + 0x10) = uVar1;
  this[0x18] = (ctype<wchar_t>)0x0;
  _M_initialize_ctype(this);
  return;
}


// ==== entry=00c71470 orig=FUN_00c71470 size=70 name=ctype ====

/* std::ctype<wchar_t>::ctype(__locale_struct*, unsigned long) */

void __thiscall
std::ctype<wchar_t>::ctype(ctype<wchar_t> *this,__locale_struct *param_1,ulong param_2)

{
  undefined8 uVar1;
  __locale_struct *local_10;
  
  *(uint *)(this + 8) = (uint)(param_2 != 0);
  *(undefined ***)this = &PTR__ctype_011b7ad0;
  local_10 = param_1;
  uVar1 = locale::facet::_S_clone_c_locale(&local_10);
  this[0x18] = (ctype<wchar_t>)0x0;
  *(undefined8 *)(this + 0x10) = uVar1;
  _M_initialize_ctype(this);
  return;
}


// ==== entry=00c714c0 orig=FUN_00c714c0 size=126 name=ctype_byname ====

/* std::ctype_byname<wchar_t>::ctype_byname(char const*, unsigned long) */

void __thiscall
std::ctype_byname<wchar_t>::ctype_byname(ctype_byname<wchar_t> *this,char *param_1,ulong param_2)

{
  long lVar1;
  byte *pbVar2;
  byte *pbVar3;
  bool bVar4;
  bool bVar5;
  bool bVar6;
  byte bVar7;
  
  bVar7 = 0;
  ctype<wchar_t>::ctype((ctype<wchar_t> *)this,param_2);
  lVar1 = 2;
  bVar4 = false;
  bVar6 = false;
  *(undefined ***)this = &PTR__ctype_byname_011b7b50;
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
                    /* try { // try from 00c71527 to 00c71538 has its CatchHandler @ 00c71545 */
      locale::facet::_S_destroy_c_locale((__locale_struct **)(this + 0x10));
      locale::facet::_S_create_c_locale
                ((__locale_struct **)(this + 0x10),param_1,(__locale_struct *)0x0);
      ctype<wchar_t>::_M_initialize_ctype((ctype<wchar_t> *)this);
      return;
    }
  }
  return;
}


// ==== entry=00c71550 orig=FUN_00c71550 size=12 name=operator<< ====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* std::ostream& std::TEMPNAMEPLACEHOLDERVALUE(std::ostream&, std::string const&) */

ostream * std::operator<<(ostream *param_1,string *param_2)

{
  ostream *poVar1;
  
  poVar1 = __ostream_insert<char,std::char_traits<char>>
                     (param_1,*(char **)param_2,*(long *)(*(char **)param_2 + -0x18));
  return poVar1;
}


// ==== entry=00c71560 orig=FUN_00c71560 size=104 name=getline<char,std::char_traits<char>,std::allocator<char>> ====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* std::istream& std::getline<char, std::char_traits<char>, std::allocator<char> >(std::istream&,
   std::string&) */

istream * std::getline<char,std::char_traits<char>,std::allocator<char>>
                    (istream *param_1,string *param_2)

{
  ctype<char> *this;
  ctype<char> cVar1;
  istream *piVar2;
  
  this = *(ctype<char> **)(param_1 + *(long *)(*(long *)param_1 + -0x18) + 0xf0);
  if (this != (ctype<char> *)0x0) {
    if (this[0x38] == (ctype<char>)0x0) {
      ctype<char>::_M_widen_init(this);
      cVar1 = (ctype<char>)0xa;
      if (*(code **)(*(long *)this + 0x30) != ::BSim_QList_int___Node__t) {
        cVar1 = (ctype<char>)(**(code **)(*(long *)this + 0x30))(this,10);
      }
    }
    else {
      cVar1 = this[0x43];
    }
    piVar2 = getline<char,std::char_traits<char>,std::allocator<char>>(param_1,param_2,(char)cVar1);
    return piVar2;
  }
                    /* WARNING: Subroutine does not return */
  __throw_bad_cast();
}


// ==== entry=00c715e0 name=FUN_00c715e0 size=12 ====

void FUN_00c715e0(undefined8 param_1,undefined8 *param_2)

{
  FUN_00c27650(param_1,*param_2,param_2[1]);
  return;
}


// ==== entry=00c715f0 name=FUN_00c715f0 size=40 ====

void FUN_00c715f0(undefined8 *param_1)

{
  *param_1 = &PTR__logic_error_011b29e0;
                    /* try { // try from 00c7160c to 00c71610 has its CatchHandler @ 00c71618 */
  FUN_00c715e0();
  return;
}


// ==== entry=00c71620 name=FUN_00c71620 size=25 ====

void FUN_00c71620(undefined8 *param_1)

{
  FUN_00c715f0();
  *param_1 = &PTR__domain_error_011b2a08;
  return;
}


// ==== entry=00c71640 name=FUN_00c71640 size=25 ====

void FUN_00c71640(undefined8 *param_1)

{
  FUN_00c715f0();
  *param_1 = &PTR__invalid_argument_011b2a30;
  return;
}


// ==== entry=00c71660 name=FUN_00c71660 size=25 ====

void FUN_00c71660(undefined8 *param_1)

{
  FUN_00c715f0();
  *param_1 = &PTR__length_error_011b2a58;
  return;
}


// ==== entry=00c71680 name=FUN_00c71680 size=25 ====

void FUN_00c71680(undefined8 *param_1)

{
  FUN_00c715f0();
  *param_1 = &PTR__out_of_range_011b2a80;
  return;
}


// ==== entry=00c716a0 name=FUN_00c716a0 size=40 ====

void FUN_00c716a0(undefined8 *param_1)

{
  *param_1 = &PTR__runtime_error_011b2aa8;
                    /* try { // try from 00c716bc to 00c716c0 has its CatchHandler @ 00c716c8 */
  FUN_00c715e0();
  return;
}


// ==== entry=00c716d0 name=FUN_00c716d0 size=25 ====

void FUN_00c716d0(undefined8 *param_1)

{
  FUN_00c716a0();
  *param_1 = &PTR__range_error_011b2ad0;
  return;
}


// ==== entry=00c716f0 name=FUN_00c716f0 size=25 ====

void FUN_00c716f0(undefined8 *param_1)

{
  FUN_00c716a0();
  *param_1 = &PTR__overflow_error_011b2af8;
  return;
}


// ==== entry=00c71710 name=FUN_00c71710 size=25 ====

void FUN_00c71710(undefined8 *param_1)

{
  FUN_00c716a0();
  *param_1 = &PTR__underflow_error_011b2b20;
  return;
}


// ==== entry=00c71730 orig=FUN_00c71730 size=138 name=ios_base ====

/* std::ios_base::ios_base() */

void __thiscall std::ios_base::ios_base(ios_base *this)

{
  ios_base *piVar1;
  ios_base *piVar2;
  
  *(undefined8 *)(this + 8) = 0;
  *(undefined8 *)(this + 0x10) = 0;
  *(undefined8 *)(this + 0x18) = 0;
  *(undefined4 *)(this + 0x20) = 0;
  *(undefined8 *)(this + 0x28) = 0;
  *(undefined8 *)(this + 0x30) = 0;
  *(undefined8 *)(this + 0x38) = 0;
  *(undefined ***)this = &PTR__ios_base_011b7be0;
  piVar1 = this + 0x40;
  do {
    *(undefined8 *)piVar1 = 0;
    piVar2 = piVar1 + 0x10;
    *(undefined8 *)(piVar1 + 8) = 0;
    piVar1 = piVar2;
  } while (this + 0xc0 != piVar2);
  *(ios_base **)(this + 200) = this + 0x40;
  *(undefined4 *)(this + 0xc0) = 8;
  locale::locale((locale *)(this + 0xd0));
  return;
}


// ==== entry=00c717c0 orig=FUN_00c717c0 size=46 name=xalloc ====

/* WARNING: Removing unreachable block (ram,0x00c717e0) */
/* std::ios_base::xalloc() */

int std::ios_base::xalloc(void)

{
  int iVar1;
  
  iVar1 = DAT_011c5550;
  LOCK();
  DAT_011c5550 = DAT_011c5550 + 1;
  UNLOCK();
  return iVar1 + 4;
}


// ==== entry=00c71800 orig=FUN_00c71800 size=52 name=register_callback ====

/* std::ios_base::register_callback(void (*)(std::ios_base::event, std::ios_base&, int), int) */

void __thiscall
std::ios_base::register_callback
          (ios_base *this,_func_void_event_ios_base_ptr_int *param_1,int param_2)

{
  undefined8 uVar1;
  undefined8 *puVar2;
  
  puVar2 = operator_new(0x18);
  uVar1 = *(undefined8 *)(this + 0x28);
  puVar2[1] = param_1;
  *puVar2 = uVar1;
  *(int *)(puVar2 + 2) = param_2;
  *(undefined4 *)((long)puVar2 + 0x14) = 0;
  *(undefined8 **)(this + 0x28) = puVar2;
  return;
}


// ==== entry=00c71840 orig=FUN_00c71840 size=376 name=_M_grow_words ====

/* std::ios_base::_M_grow_words(int, bool) */

ios_base * __thiscall std::ios_base::_M_grow_words(ios_base *this,int param_1,bool param_2)

{
  uint uVar1;
  int iVar2;
  undefined8 uVar3;
  ios_base *piVar4;
  long lVar5;
  ios_base *piVar6;
  int iVar7;
  
  if (param_1 < 8) {
    iVar7 = 8;
    piVar4 = this + 0x40;
LAB_00c718a6:
    *(ios_base **)(this + 200) = piVar4;
    *(int *)(this + 0xc0) = iVar7;
    return piVar4 + (long)param_1 * 0x10;
  }
  if (param_1 == 0x7fffffff) {
    uVar1 = *(uint *)(this + 0x20);
    *(uint *)(this + 0x20) = uVar1 | 1;
    if ((*(uint *)(this + 0x1c) & (uVar1 | 1)) != 0) {
                    /* WARNING: Subroutine does not return */
      __throw_ios_failure("ios_base::_M_grow_words is not valid");
    }
  }
  else {
    iVar7 = param_1 + 1;
    piVar4 = operator_new__((long)iVar7 << 4,(nothrow_t *)&nothrow);
    if (piVar4 != (ios_base *)0x0) {
      lVar5 = (long)iVar7 + -1;
      piVar6 = piVar4;
      do {
        lVar5 = lVar5 + -1;
        *(undefined8 *)piVar6 = 0;
        *(undefined8 *)(piVar6 + 8) = 0;
        piVar6 = piVar6 + 0x10;
      } while (lVar5 != -1);
      iVar2 = *(int *)(this + 0xc0);
      if (iVar2 < 1) {
        piVar6 = *(ios_base **)(this + 200);
      }
      else {
        piVar6 = *(ios_base **)(this + 200);
        lVar5 = 0;
        do {
          uVar3 = *(undefined8 *)(piVar6 + lVar5 + 8);
          *(undefined8 *)(piVar4 + lVar5) = *(undefined8 *)(piVar6 + lVar5);
          *(undefined8 *)(piVar4 + lVar5 + 8) = uVar3;
          lVar5 = lVar5 + 0x10;
        } while (((ulong)(iVar2 - 1) + 1) * 0x10 != lVar5);
      }
      if ((piVar6 != (ios_base *)0x0) && (piVar6 != this + 0x40)) {
        operator_delete__(piVar6);
      }
      goto LAB_00c718a6;
    }
    uVar1 = *(uint *)(this + 0x20);
    *(uint *)(this + 0x20) = uVar1 | 1;
    if ((*(uint *)(this + 0x1c) & (uVar1 | 1)) != 0) {
                    /* WARNING: Subroutine does not return */
      __throw_ios_failure("ios_base::_M_grow_words allocation failed");
    }
  }
  if (param_2) {
    *(undefined8 *)(this + 0x38) = 0;
  }
  else {
    *(undefined8 *)(this + 0x30) = 0;
  }
  return this + 0x30;
}


// ==== entry=00c719e0 orig=FUN_00c719e0 size=49 name=_M_call_callbacks ====

/* std::ios_base::_M_call_callbacks(std::ios_base::event) */

void __thiscall std::ios_base::_M_call_callbacks(ios_base *this,undefined4 param_2)

{
  undefined8 *puVar1;
  
  for (puVar1 = *(undefined8 **)(this + 0x28); puVar1 != (undefined8 *)0x0;
      puVar1 = (undefined8 *)*puVar1) {
                    /* try { // try from 00c71a01 to 00c71a03 has its CatchHandler @ 00c71a11 */
    (*(code *)puVar1[1])(param_2,this,*(undefined4 *)(puVar1 + 2));
  }
  return;
}


// ==== entry=00c71a20 orig=FUN_00c71a20 size=87 name=_M_dispose_callbacks ====

/* WARNING: Removing unreachable block (ram,0x00c71a63) */
/* std::ios_base::_M_dispose_callbacks() */

void __thiscall std::ios_base::_M_dispose_callbacks(ios_base *this)

{
  int *piVar1;
  int iVar2;
  undefined8 *puVar3;
  undefined8 *puVar4;
  
  puVar4 = *(undefined8 **)(this + 0x28);
  while (puVar4 != (undefined8 *)0x0) {
    LOCK();
    piVar1 = (int *)((long)puVar4 + 0x14);
    iVar2 = *piVar1;
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if (iVar2 != 0) break;
    puVar3 = (undefined8 *)*puVar4;
    operator_delete(puVar4);
    puVar4 = puVar3;
  }
  *(undefined8 *)(this + 0x28) = 0;
  return;
}


// ==== entry=00c71a80 orig=FUN_00c71a80 size=83 name=~ios_base ====

/* std::ios_base::~ios_base() */

void __thiscall std::ios_base::~ios_base(ios_base *this)

{
  ios_base *piVar1;
  
  *(undefined ***)this = &PTR__ios_base_011b7be0;
  _M_call_callbacks(this,0);
  _M_dispose_callbacks(this);
  piVar1 = *(ios_base **)(this + 200);
  if (piVar1 != this + 0x40) {
    if (piVar1 != (ios_base *)0x0) {
      operator_delete__(piVar1);
    }
    *(undefined8 *)(this + 200) = 0;
  }
  locale::~locale((locale *)(this + 0xd0));
  return;
}


// ==== entry=00c71ae0 orig=FUN_00c71ae0 size=18 name=~ios_base ====

/* std::ios_base::~ios_base() */

void __thiscall std::ios_base::~ios_base(ios_base *this)

{
  ~ios_base(this);
  operator_delete(this);
  return;
}


// ==== entry=00c71b00 orig=FUN_00c71b00 size=247 name=locale_moveAssign ====

void locale_moveAssign(long param_1,long param_2)

{
  undefined8 *puVar1;
  undefined4 uVar2;
  undefined8 uVar3;
  void *pvVar4;
  undefined8 uVar5;
  undefined8 *puVar6;
  long lVar7;
  void *pvVar8;
  
  pvVar8 = (void *)(param_1 + 0x40);
  *(undefined8 *)(param_1 + 8) = *(undefined8 *)(param_2 + 8);
  *(undefined8 *)(param_1 + 0x10) = *(undefined8 *)(param_2 + 0x10);
  *(undefined4 *)(param_1 + 0x18) = *(undefined4 *)(param_2 + 0x18);
  *(undefined4 *)(param_1 + 0x1c) = *(undefined4 *)(param_2 + 0x1c);
  *(undefined4 *)(param_1 + 0x20) = *(undefined4 *)(param_2 + 0x20);
  uVar3 = *(undefined8 *)(param_2 + 0x28);
  *(undefined8 *)(param_2 + 0x28) = 0;
  *(undefined8 *)(param_1 + 0x28) = uVar3;
  pvVar4 = *(void **)(param_1 + 200);
  if ((pvVar4 != (void *)0x0) && (pvVar4 != pvVar8)) {
    operator_delete__(pvVar4);
  }
  lVar7 = *(long *)(param_2 + 200);
  if (lVar7 == param_2 + 0x40) {
    *(void **)(param_1 + 200) = pvVar8;
    lVar7 = 0;
    *(undefined4 *)(param_1 + 0xc0) = 8;
    while( true ) {
      puVar1 = (undefined8 *)((long)pvVar8 + lVar7);
      puVar6 = (undefined8 *)(*(long *)(param_2 + 200) + lVar7);
      lVar7 = lVar7 + 0x10;
      uVar3 = *puVar6;
      uVar5 = puVar6[1];
      *puVar6 = 0;
      puVar6[1] = 0;
      *puVar1 = uVar3;
      puVar1[1] = uVar5;
      if (lVar7 == 0x80) break;
      pvVar8 = *(void **)(param_1 + 200);
    }
  }
  else {
    *(long *)(param_2 + 200) = param_2 + 0x40;
    *(long *)(param_1 + 200) = lVar7;
    uVar2 = *(undefined4 *)(param_2 + 0xc0);
    *(undefined4 *)(param_2 + 0xc0) = 8;
    *(undefined4 *)(param_1 + 0xc0) = uVar2;
  }
  std::locale::operator=((locale *)(param_1 + 0xd0),(locale *)(param_2 + 0xd0));
  return;
}


// ==== entry=00c71c10 orig=FUN_00c71c10 size=419 name=locale_swap ====

void locale_swap(long param_1,long param_2)

{
  undefined4 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined8 *puVar5;
  undefined8 *puVar6;
  undefined8 *puVar7;
  undefined8 *puVar8;
  long lVar9;
  long lVar10;
  long lVar11;
  long in_FS_OFFSET;
  locale alStack_28 [8];
  long local_20;
  
  puVar6 = *(undefined8 **)(param_1 + 200);
  local_20 = *(long *)(in_FS_OFFSET + 0x28);
  uVar2 = *(undefined8 *)(param_1 + 8);
  puVar8 = *(undefined8 **)(param_2 + 200);
  *(undefined8 *)(param_1 + 8) = *(undefined8 *)(param_2 + 8);
  *(undefined8 *)(param_2 + 8) = uVar2;
  uVar2 = *(undefined8 *)(param_1 + 0x10);
  *(undefined8 *)(param_1 + 0x10) = *(undefined8 *)(param_2 + 0x10);
  *(undefined8 *)(param_2 + 0x10) = uVar2;
  uVar1 = *(undefined4 *)(param_1 + 0x18);
  *(undefined4 *)(param_1 + 0x18) = *(undefined4 *)(param_2 + 0x18);
  *(undefined4 *)(param_2 + 0x18) = uVar1;
  uVar1 = *(undefined4 *)(param_1 + 0x1c);
  *(undefined4 *)(param_1 + 0x1c) = *(undefined4 *)(param_2 + 0x1c);
  *(undefined4 *)(param_2 + 0x1c) = uVar1;
  uVar1 = *(undefined4 *)(param_1 + 0x20);
  *(undefined4 *)(param_1 + 0x20) = *(undefined4 *)(param_2 + 0x20);
  *(undefined4 *)(param_2 + 0x20) = uVar1;
  uVar2 = *(undefined8 *)(param_1 + 0x28);
  *(undefined8 *)(param_1 + 0x28) = *(undefined8 *)(param_2 + 0x28);
  puVar7 = (undefined8 *)(param_2 + 0x40);
  *(undefined8 *)(param_2 + 0x28) = uVar2;
  puVar5 = (undefined8 *)(param_1 + 0x40);
  if ((puVar6 == puVar5) && (puVar8 == puVar7)) {
    do {
      uVar4 = puVar7[1];
      uVar2 = *puVar5;
      puVar6 = puVar5 + 2;
      uVar3 = puVar5[1];
      *puVar5 = *puVar7;
      puVar5[1] = uVar4;
      *puVar7 = uVar2;
      puVar7[1] = uVar3;
      puVar5 = puVar6;
      puVar7 = puVar7 + 2;
    } while (puVar6 != (undefined8 *)(param_1 + 0xc0));
  }
  else {
    if ((puVar6 == puVar5) || (puVar8 == puVar7)) {
      lVar10 = param_2;
      lVar11 = param_1;
      if (puVar6 != puVar5) {
        puVar7 = puVar5;
        puVar8 = puVar6;
        lVar10 = param_1;
        lVar11 = param_2;
      }
      lVar9 = 0x40;
      do {
        uVar2 = ((undefined8 *)(lVar11 + lVar9))[1];
        *(undefined8 *)(lVar10 + lVar9) = *(undefined8 *)(lVar11 + lVar9);
        ((undefined8 *)(lVar10 + lVar9))[1] = uVar2;
        lVar9 = lVar9 + 0x10;
      } while (lVar9 != 0xc0);
      *(undefined8 **)(lVar11 + 200) = puVar8;
      *(undefined8 **)(lVar10 + 200) = puVar7;
    }
    else {
      *(undefined8 **)(param_1 + 200) = puVar8;
      *(undefined8 **)(param_2 + 200) = puVar6;
    }
    uVar1 = *(undefined4 *)(param_1 + 0xc0);
    *(undefined4 *)(param_1 + 0xc0) = *(undefined4 *)(param_2 + 0xc0);
    *(undefined4 *)(param_2 + 0xc0) = uVar1;
  }
  std::locale::locale(alStack_28,(locale *)(param_1 + 0xd0));
  std::locale::operator=((locale *)(param_1 + 0xd0),(locale *)(param_2 + 0xd0));
  std::locale::operator=((locale *)(param_2 + 0xd0),alStack_28);
  std::locale::~locale(alStack_28);
  if (local_20 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


// ==== entry=00c71dd0 orig=FUN_00c71dd0 size=18 name=classic_table ====

/* std::ctype<char>::classic_table() */

undefined8 std::ctype<char>::classic_table(void)

{
  long lVar1;
  
                    /* try { // try from 00c71dd4 to 00c71dd8 has its CatchHandler @ 00c71de2 */
  lVar1 = locale::facet::_S_get_c_locale();
  return *(undefined8 *)(lVar1 + 0x68);
}


// ==== entry=00c71df0 orig=FUN_00c71df0 size=219 name=ctype ====

/* std::ctype<char>::ctype(__locale_struct*, unsigned short const*, bool, unsigned long) */

void __thiscall
std::ctype<char>::ctype
          (ctype<char> *this,__locale_struct *param_1,ushort *param_2,bool param_3,ulong param_4)

{
  long lVar1;
  ulong uVar2;
  undefined8 *puVar3;
  byte bVar4;
  __locale_struct *local_20;
  
  bVar4 = 0;
  *(uint *)(this + 8) = (uint)(param_4 != 0);
  *(undefined ***)this = &PTR__ctype_011b7a70;
  local_20 = param_1;
  lVar1 = locale::facet::_S_clone_c_locale(&local_20);
  *(long *)(this + 0x10) = lVar1;
  this[0x18] = (ctype<char>)(param_2 != (ushort *)0x0 && param_3);
  *(undefined8 *)(this + 0x20) = *(undefined8 *)(lVar1 + 0x78);
  *(undefined8 *)(this + 0x28) = *(undefined8 *)(lVar1 + 0x70);
  if (param_2 == (ushort *)0x0) {
    param_2 = *(ushort **)(lVar1 + 0x68);
  }
  *(ushort **)(this + 0x30) = param_2;
  this[0x38] = (ctype<char>)0x0;
  this[0x239] = (ctype<char>)0x0;
  *(undefined8 *)(this + 0x39) = 0;
  *(undefined8 *)(this + 0x131) = 0;
  puVar3 = (undefined8 *)((ulong)(this + 0x41) & 0xfffffffffffffff8);
  for (uVar2 = (ulong)(((int)this - (int)(undefined8 *)((ulong)(this + 0x41) & 0xfffffffffffffff8))
                       + 0x139U >> 3); uVar2 != 0; uVar2 = uVar2 - 1) {
    *puVar3 = 0;
    puVar3 = puVar3 + (ulong)bVar4 * -2 + 1;
  }
  *(undefined8 *)(this + 0x139) = 0;
  *(undefined8 *)(this + 0x231) = 0;
  puVar3 = (undefined8 *)((ulong)(this + 0x141) & 0xfffffffffffffff8);
  for (uVar2 = (ulong)(((int)this - (int)(undefined8 *)((ulong)(this + 0x141) & 0xfffffffffffffff8))
                       + 0x239U >> 3); uVar2 != 0; uVar2 = uVar2 - 1) {
    *puVar3 = 0;
    puVar3 = puVar3 + (ulong)bVar4 * -2 + 1;
  }
  return;
}


// ==== entry=00c71ed0 orig=FUN_00c71ed0 size=201 name=ctype ====

/* std::ctype<char>::ctype(unsigned short const*, bool, unsigned long) */

void __thiscall
std::ctype<char>::ctype(ctype<char> *this,ushort *param_1,bool param_2,ulong param_3)

{
  long lVar1;
  ulong uVar2;
  undefined8 *puVar3;
  byte bVar4;
  
  bVar4 = 0;
  *(uint *)(this + 8) = (uint)(param_3 != 0);
  *(undefined ***)this = &PTR__ctype_011b7a70;
                    /* try { // try from 00c71ef6 to 00c71efa has its CatchHandler @ 00c71f9e */
  lVar1 = locale::facet::_S_get_c_locale();
  *(long *)(this + 0x10) = lVar1;
  this[0x18] = (ctype<char>)(param_1 != (ushort *)0x0 && param_2);
  *(undefined8 *)(this + 0x20) = *(undefined8 *)(lVar1 + 0x78);
  *(undefined8 *)(this + 0x28) = *(undefined8 *)(lVar1 + 0x70);
  if (param_1 == (ushort *)0x0) {
    param_1 = *(ushort **)(lVar1 + 0x68);
  }
  *(ushort **)(this + 0x30) = param_1;
  this[0x38] = (ctype<char>)0x0;
  this[0x239] = (ctype<char>)0x0;
  *(undefined8 *)(this + 0x39) = 0;
  *(undefined8 *)(this + 0x131) = 0;
  puVar3 = (undefined8 *)((ulong)(this + 0x41) & 0xfffffffffffffff8);
  for (uVar2 = (ulong)(((int)this - (int)(undefined8 *)((ulong)(this + 0x41) & 0xfffffffffffffff8))
                       + 0x139U >> 3); uVar2 != 0; uVar2 = uVar2 - 1) {
    *puVar3 = 0;
    puVar3 = puVar3 + (ulong)bVar4 * -2 + 1;
  }
  *(undefined8 *)(this + 0x139) = 0;
  *(undefined8 *)(this + 0x231) = 0;
  puVar3 = (undefined8 *)((ulong)(this + 0x141) & 0xfffffffffffffff8);
  for (uVar2 = (ulong)(((int)this - (int)(undefined8 *)((ulong)(this + 0x141) & 0xfffffffffffffff8))
                       + 0x239U >> 3); uVar2 != 0; uVar2 = uVar2 - 1) {
    *puVar3 = 0;
    puVar3 = puVar3 + (ulong)bVar4 * -2 + 1;
  }
  return;
}


// ==== entry=00c71fb0 orig=FUN_00c71fb0 size=12 name=do_toupper ====

/* std::ctype<char>::do_toupper(char) const */

undefined4 __thiscall std::ctype<char>::do_toupper(ctype<char> *this,char param_1)

{
  return *(undefined4 *)(*(long *)(this + 0x20) + (ulong)(byte)param_1 * 4);
}


// ==== entry=00c71fc0 orig=FUN_00c71fc0 size=41 name=do_toupper ====

/* std::ctype<char>::do_toupper(char*, char const*) const */

void __thiscall std::ctype<char>::do_toupper(ctype<char> *this,char *param_1,char *param_2)

{
  byte *pbVar1;
  
  if (param_1 < param_2) {
    do {
      pbVar1 = (byte *)(param_1 + 1);
      *param_1 = (byte)*(undefined4 *)(*(long *)(this + 0x20) + (ulong)(byte)*param_1 * 4);
      param_1 = (char *)pbVar1;
    } while ((byte *)param_2 != pbVar1);
  }
  return;
}


// ==== entry=00c71ff0 orig=FUN_00c71ff0 size=12 name=do_tolower ====

/* std::ctype<char>::do_tolower(char) const */

undefined4 __thiscall std::ctype<char>::do_tolower(ctype<char> *this,char param_1)

{
  return *(undefined4 *)(*(long *)(this + 0x28) + (ulong)(byte)param_1 * 4);
}


// ==== entry=00c72000 orig=FUN_00c72000 size=41 name=do_tolower ====

/* std::ctype<char>::do_tolower(char*, char const*) const */

void __thiscall std::ctype<char>::do_tolower(ctype<char> *this,char *param_1,char *param_2)

{
  byte *pbVar1;
  
  if (param_1 < param_2) {
    do {
      pbVar1 = (byte *)(param_1 + 1);
      *param_1 = (byte)*(undefined4 *)(*(long *)(this + 0x28) + (ulong)(byte)*param_1 * 4);
      param_1 = (char *)pbVar1;
    } while ((byte *)param_2 != pbVar1);
  }
  return;
}


// ==== entry=00c72030 orig=FUN_00c72030 size=5 name=operator.new[] ====

/* operator new[](unsigned long, std::nothrow_t const&) */

void * operator_new__(ulong param_1,nothrow_t *param_2)

{
  void *pvVar1;
  code *pcVar2;
  
  if (param_1 == 0) {
    param_1 = 1;
  }
  while( true ) {
    pvVar1 = malloc(param_1);
    if (pvVar1 != (void *)0x0) {
      return pvVar1;
    }
    pcVar2 = (code *)BSim_QCoreApplication__instance();
    if (pcVar2 == (code *)0x0) break;
    (*pcVar2)();
  }
  return (void *)0x0;
}


// ==== entry=00c72040 orig=FUN_00c72040 size=50 name=__cxa_bad_cast ====

void __cxa_bad_cast(void)

{
  undefined8 *puVar1;
  
  puVar1 = (undefined8 *)__cxa_allocate_exception(8);
  *puVar1 = &PTR__bad_cast_011b1928;
                    /* WARNING: Subroutine does not return */
  __cxa_throw(puVar1,&std::bad_cast::typeinfo,std::bad_cast::~bad_cast);
}


// ==== entry=00c72080 orig=FUN_00c72080 size=50 name=__cxa_bad_typeid ====

void __cxa_bad_typeid(void)

{
  undefined8 *puVar1;
  
  puVar1 = (undefined8 *)__cxa_allocate_exception(8);
  *puVar1 = &PTR__bad_typeid_011b7cd8;
                    /* WARNING: Subroutine does not return */
  __cxa_throw(puVar1,&std::bad_typeid::typeinfo,std::bad_typeid::~bad_typeid);
}


// ==== entry=00c720c0 orig=FUN_00c720c0 size=50 name=__cxa_throw_bad_array_new_length ====

void __cxa_throw_bad_array_new_length(void)

{
  undefined8 *puVar1;
  
  puVar1 = (undefined8 *)__cxa_allocate_exception(8);
  *puVar1 = QFileSystemModel::sort;
                    /* WARNING: Subroutine does not return */
  __cxa_throw(puVar1,&std::bad_array_new_length::typeinfo,
              std::bad_array_new_length::~bad_array_new_length);
}


// ==== entry=00c72100 orig=FUN_00c72100 size=6 name=__is_pointer_p ====

/* __cxxabiv1::__pointer_type_info::__is_pointer_p() const */

undefined8 __cxxabiv1::__pointer_type_info::__is_pointer_p(void)

{
  return 1;
}


// ==== entry=00c72110 orig=FUN_00c72110 size=19 name=~__pointer_type_info ====

/* __cxxabiv1::__pointer_type_info::~__pointer_type_info() */

void __thiscall __cxxabiv1::__pointer_type_info::~__pointer_type_info(__pointer_type_info *this)

{
  *(undefined ***)this = &PTR____pointer_type_info_011b7c18;
  __pbase_type_info::~__pbase_type_info((__pbase_type_info *)this);
  return;
}


// ==== entry=00c72130 orig=FUN_00c72130 size=23 name=~__pointer_type_info ====

/* __cxxabiv1::__pointer_type_info::~__pointer_type_info() */

void __thiscall __cxxabiv1::__pointer_type_info::~__pointer_type_info(__pointer_type_info *this)

{
  ~__pointer_type_info(this);
  operator_delete(this,0x20);
  return;
}


// ==== entry=00c72150 orig=FUN_00c72150 size=113 name=__pointer_catch ====

/* __cxxabiv1::__pointer_type_info::__pointer_catch(__cxxabiv1::__pbase_type_info const*, void**,
   unsigned int) const */

ulong __thiscall
__cxxabiv1::__pointer_type_info::__pointer_catch
          (__pointer_type_info *this,__pbase_type_info *param_1,void **param_2,uint param_3)

{
  long *plVar1;
  char *__s1;
  int iVar2;
  uint uVar3;
  ulong uVar4;
  
  plVar1 = *(long **)(this + 0x18);
  if (param_3 < 2) {
    __s1 = (char *)plVar1[1];
    if (__s1 == "v") {
LAB_00c721b2:
      uVar3 = (**(code **)(**(long **)(param_1 + 0x18) + 0x18))();
      return (ulong)(uVar3 ^ 1);
    }
    if (*__s1 != '*') {
      iVar2 = strcmp(__s1,"v");
      if (iVar2 == 0) goto LAB_00c721b2;
    }
  }
                    /* WARNING: Could not recover jumptable at 0x00c72179. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar4 = (**(code **)(*plVar1 + 0x20))(plVar1,*(undefined8 *)(param_1 + 0x18),param_2,param_3 + 2);
  return uVar4;
}


// ==== entry=00c721d0 orig=FUN_00c721d0 size=17 name=__pointer_catch ====

/* __cxxabiv1::__pbase_type_info::__pointer_catch(__cxxabiv1::__pbase_type_info const*, void**,
   unsigned int) const */

void __thiscall
__cxxabiv1::__pbase_type_info::__pointer_catch
          (__pbase_type_info *this,__pbase_type_info *param_1,void **param_2,uint param_3)

{
                    /* WARNING: Could not recover jumptable at 0x00c721de. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(long **)(this + 0x18) + 0x20))
            (*(long **)(this + 0x18),*(undefined8 *)(param_1 + 0x18),param_2,param_3 + 2);
  return;
}


// ==== entry=00c721f0 orig=FUN_00c721f0 size=19 name=~__pbase_type_info ====

/* __cxxabiv1::__pbase_type_info::~__pbase_type_info() */

void __thiscall __cxxabiv1::__pbase_type_info::~__pbase_type_info(__pbase_type_info *this)

{
  *(undefined ***)this = &PTR____pbase_type_info_011b7c78;
  std::type_info::~type_info((type_info *)this);
  return;
}


// ==== entry=00c72210 orig=FUN_00c72210 size=23 name=~__pbase_type_info ====

/* __cxxabiv1::__pbase_type_info::~__pbase_type_info() */

void __thiscall __cxxabiv1::__pbase_type_info::~__pbase_type_info(__pbase_type_info *this)

{
  ~__pbase_type_info(this);
  operator_delete(this,0x20);
  return;
}


// ==== entry=00c72230 orig=FUN_00c72230 size=574 name=__do_catch ====

/* __cxxabiv1::__pbase_type_info::__do_catch(std::type_info const*, void**, unsigned int) const */

undefined8 __thiscall
__cxxabiv1::__pbase_type_info::__do_catch
          (__pbase_type_info *this,type_info *param_1,void **param_2,uint param_3)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  undefined8 uVar5;
  code *UNRECOVERED_JUMPTABLE;
  uint uVar6;
  char *pcVar7;
  char *pcVar8;
  long lVar9;
  
  pcVar7 = *(char **)(this + 8);
  pcVar8 = *(char **)(param_1 + 8);
  if ((pcVar7 == pcVar8) || ((*pcVar7 != '*' && (iVar4 = strcmp(pcVar7,pcVar8), iVar4 == 0)))) {
    return 1;
  }
  if ((pcVar8 == "Dn") || ((*pcVar8 != '*' && (iVar4 = strcmp(pcVar8,"Dn"), iVar4 == 0)))) {
    lVar9 = *(long *)this;
    pcVar7 = *(char **)(*(long *)(lVar9 + -8) + 8);
    if (pcVar7 == "N10__cxxabiv119__pointer_type_infoE") {
LAB_00c723f0:
      *param_2 = (void *)0x0;
      return 1;
    }
    if (*pcVar7 == '*') {
      if (pcVar7 != "N10__cxxabiv129__pointer_to_member_type_infoE") {
        if (pcVar7 != *(char **)(*(long *)(*(long *)param_1 + -8) + 8)) {
          return 0;
        }
        goto LAB_00c72366;
      }
LAB_00c722f2:
      uVar5 = (**(code **)(**(long **)(this + 0x18) + 0x18))();
      if ((char)uVar5 == '\0') {
        *param_2 = &DAT_00d98c08;
        uVar5 = 1;
      }
      else {
        *param_2 = &DAT_00d98c10;
      }
      return uVar5;
    }
    iVar4 = strcmp(pcVar7,"N10__cxxabiv119__pointer_type_infoE");
    if (iVar4 == 0) goto LAB_00c723f0;
    if ((pcVar7 == "N10__cxxabiv129__pointer_to_member_type_infoE") ||
       (iVar4 = strcmp(pcVar7,"N10__cxxabiv129__pointer_to_member_type_infoE"), iVar4 == 0))
    goto LAB_00c722f2;
    pcVar8 = *(char **)(*(long *)(*(long *)param_1 + -8) + 8);
    if (pcVar7 == pcVar8) goto LAB_00c72366;
  }
  else {
    lVar9 = *(long *)this;
    pcVar7 = *(char **)(*(long *)(lVar9 + -8) + 8);
    pcVar8 = *(char **)(*(long *)(*(long *)param_1 + -8) + 8);
    if (pcVar7 == pcVar8) goto LAB_00c72366;
    if (*pcVar7 == '*') {
      return 0;
    }
  }
  iVar4 = strcmp(pcVar7,pcVar8);
  if (iVar4 != 0) {
    return 0;
  }
LAB_00c72366:
  if ((param_3 & 1) != 0) {
    uVar1 = *(uint *)(this + 0x10);
    uVar2 = *(uint *)(param_1 + 0x10);
    uVar6 = uVar1 & 0x60;
    uVar3 = uVar2;
    if ((~uVar6 & uVar2 & 0x60) != 0) {
      uVar3 = uVar2 & uVar6;
    }
    if ((~(uVar2 & 0x60) & uVar6) == 0 && (uVar3 & ~uVar1) == 0) {
      if ((uVar1 & 1) == 0) {
        param_3 = param_3 & 0xfffffffe;
      }
      UNRECOVERED_JUMPTABLE = *(code **)(lVar9 + 0x30);
      if (UNRECOVERED_JUMPTABLE == __pointer_catch) {
        this = *(__pbase_type_info **)(this + 0x18);
        param_1 = *(type_info **)(param_1 + 0x18);
        param_3 = param_3 + 2;
        UNRECOVERED_JUMPTABLE = *(code **)(*(long *)this + 0x20);
      }
                    /* WARNING: Could not recover jumptable at 0x00c723e7. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar5 = (*UNRECOVERED_JUMPTABLE)(this,param_1,param_2,param_3);
      return uVar5;
    }
  }
  return 0;
}


// ==== entry=00c724a0 orig=FUN_00c724a0 size=8 name=s_std__bad_typeid_c724a0 ====

/* std::bad_typeid::what() const */

char * std::bad_typeid::s_std__bad_typeid_c724a0(void)

{
  return "std::bad_typeid";
}


// ==== entry=00c724b0 orig=FUN_00c724b0 size=19 name=~bad_typeid ====

/* std::bad_typeid::~bad_typeid() */

void __thiscall std::bad_typeid::~bad_typeid(bad_typeid *this)

{
  *(undefined ***)this = &PTR__bad_typeid_011b7cd8;
  exception::~exception((exception *)this);
  return;
}


// ==== entry=00c724d0 orig=FUN_00c724d0 size=23 name=~bad_typeid ====

/* std::bad_typeid::~bad_typeid() */

void __thiscall std::bad_typeid::~bad_typeid(bad_typeid *this)

{
  ~bad_typeid(this);
  operator_delete(this,8);
  return;
}


// ==== entry=00c724f0 orig=FUN_00c724f0 size=422 name=_S_construct_pattern ====

/* std::money_base::_S_construct_pattern(char, char, char) */

undefined4 std::money_base::_S_construct_pattern(char param_1,char param_2,char param_3)

{
  char cVar1;
  char cVar2;
  char cVar3;
  long in_FS_OFFSET;
  
  cVar1 = param_3;
  cVar2 = param_3;
  switch(param_3) {
  case '\0':
  case '\x01':
    if (param_2 == '\0') {
      cVar3 = (-(param_1 == '\0') & 2U) + 2;
      cVar1 = '\x03';
      cVar2 = (-(param_1 == '\0') & 0xfeU) + 4;
    }
    else {
      param_2 = (-(param_1 == '\0') & 0xfeU) + 4;
      cVar3 = (-(param_1 == '\0') & 2U) + 2;
      cVar1 = '\x03';
      cVar2 = '\x01';
    }
    break;
  case '\x02':
    if (param_2 == '\0') {
      if (param_1 == '\0') {
        cVar1 = '\x04';
      }
      else {
        param_3 = '\x04';
      }
      cVar2 = '\x03';
      cVar3 = param_3;
    }
    else {
      param_2 = '\x03';
      if (param_1 == '\0') {
        cVar1 = '\x04';
      }
      else {
        param_3 = '\x04';
      }
      cVar2 = param_3;
      cVar3 = '\x01';
    }
    break;
  case '\x03':
    if (param_1 == '\0') {
      cVar3 = '\x01';
      if (param_2 == '\0') {
        cVar2 = '\x02';
        cVar3 = param_3;
      }
      cVar1 = '\x04';
      if (param_2 != '\0') {
        param_2 = '\x02';
      }
    }
    else {
      cVar3 = '\x02';
      cVar2 = (-(param_2 == '\0') & 3U) + 1;
      if (param_2 != '\0') {
        param_2 = '\x04';
      }
    }
    break;
  case '\x04':
    if (param_1 == '\0') {
      cVar2 = ~-(param_2 == '\0') + 3;
      cVar3 = ~-(param_2 == '\0') + 2;
      if (param_2 != '\0') {
        param_2 = '\x03';
      }
    }
    else {
      cVar3 = '\x03';
      cVar1 = '\x02';
      if (param_2 != '\0') {
        cVar2 = '\x01';
        param_2 = param_3;
      }
    }
    break;
  default:
    param_2 = '\0';
    cVar1 = '\0';
    cVar2 = '\0';
    cVar3 = '\0';
  }
  if (*(long *)(in_FS_OFFSET + 0x28) == *(long *)(in_FS_OFFSET + 0x28)) {
    return CONCAT13(param_2,CONCAT12(cVar2,CONCAT11(cVar3,cVar1)));
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ==== entry=00c726d0 orig=FUN_00c726d0 size=1254 name=_M_initialize_moneypunct ====

/* std::moneypunct<char, true>::_M_initialize_moneypunct(__locale_struct*, char const*) */

void std::moneypunct<char,true>::_M_initialize_moneypunct(__locale_struct *param_1,char *param_2)

{
  char cVar1;
  char cVar2;
  char cVar3;
  undefined *puVar4;
  undefined4 uVar5;
  __locale_data *p_Var6;
  char *pcVar7;
  char *__s;
  char *__s_00;
  char *__s_01;
  char *pcVar8;
  size_t sVar9;
  long lVar10;
  void *pvVar11;
  
  if (param_1->__locales[2] == (__locale_data *)0x0) {
    p_Var6 = operator_new(0x70);
    *(undefined4 *)(p_Var6 + 8) = 0;
    *(undefined8 *)(p_Var6 + 0x10) = 0;
    *(undefined ***)p_Var6 = &PTR____moneypunct_cache_011b2818;
    *(undefined8 *)(p_Var6 + 0x18) = 0;
    *(undefined2 *)(p_Var6 + 0x20) = 0;
    p_Var6[0x22] = (__locale_data)0x0;
    *(undefined8 *)(p_Var6 + 0x28) = 0;
    *(undefined8 *)(p_Var6 + 0x30) = 0;
    *(undefined8 *)(p_Var6 + 0x38) = 0;
    *(undefined8 *)(p_Var6 + 0x40) = 0;
    *(undefined8 *)(p_Var6 + 0x48) = 0;
    *(undefined8 *)(p_Var6 + 0x50) = 0;
    *(undefined8 *)(p_Var6 + 0x58) = 0;
    *(undefined4 *)(p_Var6 + 0x60) = 0;
    p_Var6[0x6f] = (__locale_data)0x0;
    param_1->__locales[2] = p_Var6;
  }
  if (param_2 != (char *)0x0) {
    p_Var6 = (__locale_data *)__nl_langinfo_l(0x40002,param_2);
    param_1->__locales[2][0x21] = *p_Var6;
    p_Var6 = (__locale_data *)__nl_langinfo_l(0x40003,param_2);
    param_1->__locales[2][0x22] = *p_Var6;
    if (param_1->__locales[2][0x21] == (__locale_data)0x0) {
      *(undefined4 *)(param_1->__locales[2] + 0x58) = 0;
      param_1->__locales[2][0x21] = (__locale_data)0x2e;
    }
    else {
      pcVar7 = (char *)__nl_langinfo_l(0x40007,param_2);
      *(int *)(param_1->__locales[2] + 0x58) = (int)*pcVar7;
    }
    pcVar7 = (char *)__nl_langinfo_l(0x40004,param_2);
    __s = (char *)__nl_langinfo_l(0x40005,param_2);
    __s_00 = (char *)__nl_langinfo_l(0x40006,param_2);
    __s_01 = (char *)__nl_langinfo_l(0x40000,param_2);
    pcVar8 = (char *)__nl_langinfo_l(0x40015,param_2);
    p_Var6 = param_1->__locales[2];
    cVar1 = *pcVar8;
    if (p_Var6[0x22] == (__locale_data)0x0) {
      *(undefined **)(p_Var6 + 0x10) = &DAT_00cb99b6;
      *(undefined8 *)(param_1->__locales[2] + 0x18) = 0;
      param_1->__locales[2][0x20] = (__locale_data)0x0;
      param_1->__locales[2][0x22] = (__locale_data)0x2c;
      sVar9 = strlen(__s);
    }
    else {
      sVar9 = strlen(pcVar7);
      if (sVar9 == 0) {
        *(undefined **)(p_Var6 + 0x10) = &DAT_00cb99b6;
        param_1->__locales[2][0x20] = (__locale_data)0x0;
      }
      else {
                    /* try { // try from 00c72ae4 to 00c72ae8 has its CatchHandler @ 00c72bcd */
        pvVar11 = operator_new__(sVar9 + 1);
        memcpy(pvVar11,pcVar7,sVar9 + 1);
        *(void **)(param_1->__locales[2] + 0x10) = pvVar11;
      }
      *(size_t *)(param_1->__locales[2] + 0x18) = sVar9;
      sVar9 = strlen(__s);
    }
    if (sVar9 == 0) {
      *(undefined **)(param_1->__locales[2] + 0x38) = &DAT_00cb99b6;
    }
    else {
                    /* try { // try from 00c72a8a to 00c72a8e has its CatchHandler @ 00c72bd2 */
      pvVar11 = operator_new__(sVar9 + 1);
      memcpy(pvVar11,__s,sVar9 + 1);
      *(void **)(param_1->__locales[2] + 0x38) = pvVar11;
    }
    *(size_t *)(param_1->__locales[2] + 0x40) = sVar9;
    if (cVar1 == '\0') {
      *(char **)(param_1->__locales[2] + 0x48) = "()";
      *(undefined8 *)(param_1->__locales[2] + 0x50) = 2;
      sVar9 = strlen(__s_01);
    }
    else {
      sVar9 = strlen(__s_00);
      if (sVar9 == 0) {
        *(undefined **)(param_1->__locales[2] + 0x48) = &DAT_00cb99b6;
      }
      else {
                    /* try { // try from 00c72b1c to 00c72b20 has its CatchHandler @ 00c72bdc */
        pvVar11 = operator_new__(sVar9 + 1);
        memcpy(pvVar11,__s_00,sVar9 + 1);
        *(void **)(param_1->__locales[2] + 0x48) = pvVar11;
      }
      *(size_t *)(param_1->__locales[2] + 0x50) = sVar9;
      sVar9 = strlen(__s_01);
    }
    if (sVar9 == 0) {
      *(undefined **)(param_1->__locales[2] + 0x28) = &DAT_00cb99b6;
    }
    else {
                    /* try { // try from 00c72a00 to 00c72a04 has its CatchHandler @ 00c72bd7 */
      pvVar11 = operator_new__(sVar9 + 1);
      pvVar11 = memcpy(pvVar11,__s_01,sVar9 + 1);
      *(void **)(param_1->__locales[2] + 0x28) = pvVar11;
    }
    *(size_t *)(param_1->__locales[2] + 0x30) = sVar9;
    pcVar7 = (char *)__nl_langinfo_l(0x40010,param_2);
    cVar2 = *pcVar7;
    pcVar7 = (char *)__nl_langinfo_l(0x40011,param_2);
    cVar3 = *pcVar7;
    pcVar7 = (char *)__nl_langinfo_l(0x40014,param_2);
    p_Var6 = param_1->__locales[2];
    uVar5 = money_base::_S_construct_pattern(cVar2,cVar3,*pcVar7);
    *(undefined4 *)(p_Var6 + 0x5c) = uVar5;
    pcVar7 = (char *)__nl_langinfo_l(0x40012,param_2);
    cVar2 = *pcVar7;
    pcVar7 = (char *)__nl_langinfo_l(0x40013,param_2);
    p_Var6 = param_1->__locales[2];
    uVar5 = money_base::_S_construct_pattern(cVar2,*pcVar7,cVar1);
    *(undefined4 *)(p_Var6 + 0x60) = uVar5;
    return;
  }
  param_1->__locales[2][0x21] = (__locale_data)0x2e;
  param_1->__locales[2][0x22] = (__locale_data)0x2c;
  *(undefined **)(param_1->__locales[2] + 0x10) = &DAT_00cb99b6;
  *(undefined8 *)(param_1->__locales[2] + 0x18) = 0;
  param_1->__locales[2][0x20] = (__locale_data)0x0;
  *(undefined **)(param_1->__locales[2] + 0x28) = &DAT_00cb99b6;
  *(undefined8 *)(param_1->__locales[2] + 0x30) = 0;
  *(undefined **)(param_1->__locales[2] + 0x38) = &DAT_00cb99b6;
  *(undefined8 *)(param_1->__locales[2] + 0x40) = 0;
  *(undefined **)(param_1->__locales[2] + 0x48) = &DAT_00cb99b6;
  *(undefined8 *)(param_1->__locales[2] + 0x50) = 0;
  *(undefined4 *)(param_1->__locales[2] + 0x58) = 0;
  *(undefined4 *)(param_1->__locales[2] + 0x5c) = 0x4000302;
  *(undefined4 *)(param_1->__locales[2] + 0x60) = 0x4000302;
  puVar4 = money_base::_S_atoms;
  lVar10 = 0;
  do {
    param_1->__locales[2][lVar10 + 100] = *(__locale_data *)(puVar4 + lVar10);
    lVar10 = lVar10 + 1;
  } while (lVar10 != 0xb);
  return;
}


// ==== entry=00c72bf0 orig=FUN_00c72bf0 size=1254 name=_M_initialize_moneypunct ====

/* std::moneypunct<char, false>::_M_initialize_moneypunct(__locale_struct*, char const*) */

void std::moneypunct<char,false>::_M_initialize_moneypunct(__locale_struct *param_1,char *param_2)

{
  char cVar1;
  char cVar2;
  char cVar3;
  undefined *puVar4;
  undefined4 uVar5;
  __locale_data *p_Var6;
  char *pcVar7;
  char *__s;
  char *__s_00;
  char *__s_01;
  char *pcVar8;
  size_t sVar9;
  long lVar10;
  void *pvVar11;
  
  if (param_1->__locales[2] == (__locale_data *)0x0) {
    p_Var6 = operator_new(0x70);
    *(undefined4 *)(p_Var6 + 8) = 0;
    *(undefined8 *)(p_Var6 + 0x10) = 0;
    *(undefined ***)p_Var6 = &PTR____moneypunct_cache_011b2838;
    *(undefined8 *)(p_Var6 + 0x18) = 0;
    *(undefined2 *)(p_Var6 + 0x20) = 0;
    p_Var6[0x22] = (__locale_data)0x0;
    *(undefined8 *)(p_Var6 + 0x28) = 0;
    *(undefined8 *)(p_Var6 + 0x30) = 0;
    *(undefined8 *)(p_Var6 + 0x38) = 0;
    *(undefined8 *)(p_Var6 + 0x40) = 0;
    *(undefined8 *)(p_Var6 + 0x48) = 0;
    *(undefined8 *)(p_Var6 + 0x50) = 0;
    *(undefined8 *)(p_Var6 + 0x58) = 0;
    *(undefined4 *)(p_Var6 + 0x60) = 0;
    p_Var6[0x6f] = (__locale_data)0x0;
    param_1->__locales[2] = p_Var6;
  }
  if (param_2 != (char *)0x0) {
    p_Var6 = (__locale_data *)__nl_langinfo_l(0x40002,param_2);
    param_1->__locales[2][0x21] = *p_Var6;
    p_Var6 = (__locale_data *)__nl_langinfo_l(0x40003,param_2);
    param_1->__locales[2][0x22] = *p_Var6;
    if (param_1->__locales[2][0x21] == (__locale_data)0x0) {
      *(undefined4 *)(param_1->__locales[2] + 0x58) = 0;
      param_1->__locales[2][0x21] = (__locale_data)0x2e;
    }
    else {
      pcVar7 = (char *)__nl_langinfo_l(0x40008,param_2);
      *(int *)(param_1->__locales[2] + 0x58) = (int)*pcVar7;
    }
    pcVar7 = (char *)__nl_langinfo_l(0x40004,param_2);
    __s = (char *)__nl_langinfo_l(0x40005,param_2);
    __s_00 = (char *)__nl_langinfo_l(0x40006,param_2);
    __s_01 = (char *)__nl_langinfo_l(0x40001,param_2);
    pcVar8 = (char *)__nl_langinfo_l(0x4000e,param_2);
    p_Var6 = param_1->__locales[2];
    cVar1 = *pcVar8;
    if (p_Var6[0x22] == (__locale_data)0x0) {
      *(undefined **)(p_Var6 + 0x10) = &DAT_00cb99b6;
      *(undefined8 *)(param_1->__locales[2] + 0x18) = 0;
      param_1->__locales[2][0x20] = (__locale_data)0x0;
      param_1->__locales[2][0x22] = (__locale_data)0x2c;
      sVar9 = strlen(__s);
    }
    else {
      sVar9 = strlen(pcVar7);
      if (sVar9 == 0) {
        *(undefined **)(p_Var6 + 0x10) = &DAT_00cb99b6;
        param_1->__locales[2][0x20] = (__locale_data)0x0;
      }
      else {
                    /* try { // try from 00c73004 to 00c73008 has its CatchHandler @ 00c730ed */
        pvVar11 = operator_new__(sVar9 + 1);
        memcpy(pvVar11,pcVar7,sVar9 + 1);
        *(void **)(param_1->__locales[2] + 0x10) = pvVar11;
      }
      *(size_t *)(param_1->__locales[2] + 0x18) = sVar9;
      sVar9 = strlen(__s);
    }
    if (sVar9 == 0) {
      *(undefined **)(param_1->__locales[2] + 0x38) = &DAT_00cb99b6;
    }
    else {
                    /* try { // try from 00c72faa to 00c72fae has its CatchHandler @ 00c730f2 */
      pvVar11 = operator_new__(sVar9 + 1);
      memcpy(pvVar11,__s,sVar9 + 1);
      *(void **)(param_1->__locales[2] + 0x38) = pvVar11;
    }
    *(size_t *)(param_1->__locales[2] + 0x40) = sVar9;
    if (cVar1 == '\0') {
      *(char **)(param_1->__locales[2] + 0x48) = "()";
      *(undefined8 *)(param_1->__locales[2] + 0x50) = 2;
      sVar9 = strlen(__s_01);
    }
    else {
      sVar9 = strlen(__s_00);
      if (sVar9 == 0) {
        *(undefined **)(param_1->__locales[2] + 0x48) = &DAT_00cb99b6;
      }
      else {
                    /* try { // try from 00c7303c to 00c73040 has its CatchHandler @ 00c730fc */
        pvVar11 = operator_new__(sVar9 + 1);
        memcpy(pvVar11,__s_00,sVar9 + 1);
        *(void **)(param_1->__locales[2] + 0x48) = pvVar11;
      }
      *(size_t *)(param_1->__locales[2] + 0x50) = sVar9;
      sVar9 = strlen(__s_01);
    }
    if (sVar9 == 0) {
      *(undefined **)(param_1->__locales[2] + 0x28) = &DAT_00cb99b6;
    }
    else {
                    /* try { // try from 00c72f20 to 00c72f24 has its CatchHandler @ 00c730f7 */
      pvVar11 = operator_new__(sVar9 + 1);
      pvVar11 = memcpy(pvVar11,__s_01,sVar9 + 1);
      *(void **)(param_1->__locales[2] + 0x28) = pvVar11;
    }
    *(size_t *)(param_1->__locales[2] + 0x30) = sVar9;
    pcVar7 = (char *)__nl_langinfo_l(0x40009,param_2);
    cVar2 = *pcVar7;
    pcVar7 = (char *)__nl_langinfo_l(0x4000a,param_2);
    cVar3 = *pcVar7;
    pcVar7 = (char *)__nl_langinfo_l(0x4000d,param_2);
    p_Var6 = param_1->__locales[2];
    uVar5 = money_base::_S_construct_pattern(cVar2,cVar3,*pcVar7);
    *(undefined4 *)(p_Var6 + 0x5c) = uVar5;
    pcVar7 = (char *)__nl_langinfo_l(0x4000b,param_2);
    cVar2 = *pcVar7;
    pcVar7 = (char *)__nl_langinfo_l(0x4000c,param_2);
    p_Var6 = param_1->__locales[2];
    uVar5 = money_base::_S_construct_pattern(cVar2,*pcVar7,cVar1);
    *(undefined4 *)(p_Var6 + 0x60) = uVar5;
    return;
  }
  param_1->__locales[2][0x21] = (__locale_data)0x2e;
  param_1->__locales[2][0x22] = (__locale_data)0x2c;
  *(undefined **)(param_1->__locales[2] + 0x10) = &DAT_00cb99b6;
  *(undefined8 *)(param_1->__locales[2] + 0x18) = 0;
  param_1->__locales[2][0x20] = (__locale_data)0x0;
  *(undefined **)(param_1->__locales[2] + 0x28) = &DAT_00cb99b6;
  *(undefined8 *)(param_1->__locales[2] + 0x30) = 0;
  *(undefined **)(param_1->__locales[2] + 0x38) = &DAT_00cb99b6;
  *(undefined8 *)(param_1->__locales[2] + 0x40) = 0;
  *(undefined **)(param_1->__locales[2] + 0x48) = &DAT_00cb99b6;
  *(undefined8 *)(param_1->__locales[2] + 0x50) = 0;
  *(undefined4 *)(param_1->__locales[2] + 0x58) = 0;
  *(undefined4 *)(param_1->__locales[2] + 0x5c) = 0x4000302;
  *(undefined4 *)(param_1->__locales[2] + 0x60) = 0x4000302;
  puVar4 = money_base::_S_atoms;
  lVar10 = 0;
  do {
    param_1->__locales[2][lVar10 + 100] = *(__locale_data *)(puVar4 + lVar10);
    lVar10 = lVar10 + 1;
  } while (lVar10 != 0xb);
  return;
}


// ==== entry=00c73110 orig=FUN_00c73110 size=189 name=~moneypunct ====

/* std::moneypunct<char, true>::~moneypunct() */

void __thiscall std::moneypunct<char,true>::~moneypunct(moneypunct<char,true> *this)

{
  long *plVar1;
  long lVar2;
  byte *pbVar3;
  byte *pbVar4;
  bool bVar5;
  bool bVar6;
  byte bVar7;
  
  bVar7 = 0;
  *(undefined ***)this = &PTR__moneypunct_011b56b8;
  plVar1 = *(long **)(this + 0x10);
  if ((plVar1[3] != 0) && ((void *)plVar1[2] != (void *)0x0)) {
    operator_delete__((void *)plVar1[2]);
    plVar1 = *(long **)(this + 0x10);
  }
  if ((plVar1[8] != 0) && ((void *)plVar1[7] != (void *)0x0)) {
    operator_delete__((void *)plVar1[7]);
    plVar1 = *(long **)(this + 0x10);
  }
  bVar5 = false;
  bVar6 = plVar1[10] == 0;
  if (!bVar6) {
    lVar2 = 3;
    pbVar3 = (byte *)plVar1[9];
    pbVar4 = (byte *)0xce8b48;
    do {
      if (lVar2 == 0) break;
      lVar2 = lVar2 + -1;
      bVar5 = *pbVar3 < *pbVar4;
      bVar6 = *pbVar3 == *pbVar4;
      pbVar3 = pbVar3 + (ulong)bVar7 * -2 + 1;
      pbVar4 = pbVar4 + (ulong)bVar7 * -2 + 1;
    } while (bVar6);
    if ((!bVar5 && !bVar6) != bVar5) {
      operator_delete__((byte *)plVar1[9]);
      plVar1 = *(long **)(this + 0x10);
    }
  }
  if ((plVar1[6] != 0) && ((void *)plVar1[5] != (void *)0x0)) {
    operator_delete__((void *)plVar1[5]);
    plVar1 = *(long **)(this + 0x10);
    if (plVar1 == (long *)0x0) goto LAB_00c731b1;
  }
                    /* try { // try from 00c731ae to 00c731b0 has its CatchHandler @ 00c731ce */
  (**(code **)(*plVar1 + 8))(plVar1);
LAB_00c731b1:
  locale::facet::~facet((facet *)this);
  return;
}


// ==== entry=00c731e0 orig=FUN_00c731e0 size=28 name=~moneypunct ====

/* std::moneypunct<char, true>::~moneypunct() */

void __thiscall std::moneypunct<char,true>::~moneypunct(moneypunct<char,true> *this)

{
                    /* try { // try from 00c731e9 to 00c731ed has its CatchHandler @ 00c731fc */
  ~moneypunct(this);
  operator_delete(this);
  return;
}


// ==== entry=00c73210 orig=FUN_00c73210 size=189 name=~moneypunct ====

/* std::moneypunct<char, false>::~moneypunct() */

void __thiscall std::moneypunct<char,false>::~moneypunct(moneypunct<char,false> *this)

{
  long *plVar1;
  long lVar2;
  byte *pbVar3;
  byte *pbVar4;
  bool bVar5;
  bool bVar6;
  byte bVar7;
  
  bVar7 = 0;
  *(undefined ***)this = &PTR__moneypunct_011b5720;
  plVar1 = *(long **)(this + 0x10);
  if ((plVar1[3] != 0) && ((void *)plVar1[2] != (void *)0x0)) {
    operator_delete__((void *)plVar1[2]);
    plVar1 = *(long **)(this + 0x10);
  }
  if ((plVar1[8] != 0) && ((void *)plVar1[7] != (void *)0x0)) {
    operator_delete__((void *)plVar1[7]);
    plVar1 = *(long **)(this + 0x10);
  }
  bVar5 = false;
  bVar6 = plVar1[10] == 0;
  if (!bVar6) {
    lVar2 = 3;
    pbVar3 = (byte *)plVar1[9];
    pbVar4 = (byte *)0xce8b48;
    do {
      if (lVar2 == 0) break;
      lVar2 = lVar2 + -1;
      bVar5 = *pbVar3 < *pbVar4;
      bVar6 = *pbVar3 == *pbVar4;
      pbVar3 = pbVar3 + (ulong)bVar7 * -2 + 1;
      pbVar4 = pbVar4 + (ulong)bVar7 * -2 + 1;
    } while (bVar6);
    if ((!bVar5 && !bVar6) != bVar5) {
      operator_delete__((byte *)plVar1[9]);
      plVar1 = *(long **)(this + 0x10);
    }
  }
  if ((plVar1[6] != 0) && ((void *)plVar1[5] != (void *)0x0)) {
    operator_delete__((void *)plVar1[5]);
    plVar1 = *(long **)(this + 0x10);
    if (plVar1 == (long *)0x0) goto LAB_00c732b1;
  }
                    /* try { // try from 00c732ae to 00c732b0 has its CatchHandler @ 00c732ce */
  (**(code **)(*plVar1 + 8))(plVar1);
LAB_00c732b1:
  locale::facet::~facet((facet *)this);
  return;
}


// ==== entry=00c732e0 orig=FUN_00c732e0 size=28 name=~moneypunct ====

/* std::moneypunct<char, false>::~moneypunct() */

void __thiscall std::moneypunct<char,false>::~moneypunct(moneypunct<char,false> *this)

{
                    /* try { // try from 00c732e9 to 00c732ed has its CatchHandler @ 00c732fc */
  ~moneypunct(this);
  operator_delete(this);
  return;
}


// ==== entry=00c73310 orig=FUN_00c73310 size=1437 name=_M_initialize_moneypunct ====

/* std::moneypunct<wchar_t, true>::_M_initialize_moneypunct(__locale_struct*, char const*) */

void std::moneypunct<wchar_t,true>::_M_initialize_moneypunct(__locale_struct *param_1,char *param_2)

{
  ulong uVar1;
  char cVar2;
  char cVar3;
  char cVar4;
  undefined *puVar5;
  undefined4 uVar6;
  undefined8 uVar7;
  char *pcVar8;
  char *pcVar9;
  size_t sVar10;
  long lVar11;
  void *__dest;
  wchar_t *pwVar12;
  __locale_data *p_Var13;
  ulong uVar14;
  long in_FS_OFFSET;
  char *local_60;
  char *local_58;
  char *local_50;
  mbstate_t local_48;
  long local_40;
  
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  if (param_1->__locales[2] == (__locale_data *)0x0) {
    p_Var13 = operator_new(0xa0);
    *(undefined4 *)(p_Var13 + 8) = 0;
    *(undefined8 *)(p_Var13 + 0x10) = 0;
    *(undefined ***)p_Var13 = &PTR____moneypunct_cache_011b2858;
    *(undefined8 *)(p_Var13 + 0x18) = 0;
    p_Var13[0x20] = (__locale_data)0x0;
    *(undefined8 *)(p_Var13 + 0x24) = 0;
    *(undefined8 *)(p_Var13 + 0x30) = 0;
    *(undefined8 *)(p_Var13 + 0x38) = 0;
    *(undefined8 *)(p_Var13 + 0x40) = 0;
    *(undefined8 *)(p_Var13 + 0x48) = 0;
    *(undefined8 *)(p_Var13 + 0x50) = 0;
    *(undefined8 *)(p_Var13 + 0x58) = 0;
    *(undefined8 *)(p_Var13 + 0x60) = 0;
    *(undefined4 *)(p_Var13 + 0x68) = 0;
    p_Var13[0x98] = (__locale_data)0x0;
    param_1->__locales[2] = p_Var13;
  }
  if (param_2 == (char *)0x0) {
    *(undefined4 *)(param_1->__locales[2] + 0x24) = 0x2e;
    *(undefined4 *)(param_1->__locales[2] + 0x28) = 0x2c;
    *(undefined **)(param_1->__locales[2] + 0x10) = &DAT_00cb99b6;
    *(undefined8 *)(param_1->__locales[2] + 0x18) = 0;
    param_1->__locales[2][0x20] = (__locale_data)0x0;
    *(undefined **)(param_1->__locales[2] + 0x30) = &DAT_00d94f28;
    *(undefined8 *)(param_1->__locales[2] + 0x38) = 0;
    *(undefined **)(param_1->__locales[2] + 0x40) = &DAT_00d94f28;
    *(undefined8 *)(param_1->__locales[2] + 0x48) = 0;
    *(undefined **)(param_1->__locales[2] + 0x50) = &DAT_00d94f28;
    *(undefined8 *)(param_1->__locales[2] + 0x58) = 0;
    *(undefined4 *)(param_1->__locales[2] + 0x60) = 0;
    *(undefined4 *)(param_1->__locales[2] + 100) = 0x4000302;
    *(undefined4 *)(param_1->__locales[2] + 0x68) = 0x4000302;
    puVar5 = money_base::_S_atoms;
    lVar11 = 0;
    do {
      *(int *)(param_1->__locales[2] + lVar11 * 4 + 0x6c) = (int)(char)puVar5[lVar11];
      lVar11 = lVar11 + 1;
    } while (lVar11 != 0xb);
    goto LAB_00c73555;
  }
  uVar7 = __uselocale(param_2);
  uVar6 = __nl_langinfo_l(0x4002b,param_2);
  *(undefined4 *)(param_1->__locales[2] + 0x24) = uVar6;
  uVar6 = __nl_langinfo_l(0x4002c,param_2);
  *(undefined4 *)(param_1->__locales[2] + 0x28) = uVar6;
  if (*(int *)(param_1->__locales[2] + 0x24) == 0) {
    *(undefined4 *)(param_1->__locales[2] + 0x60) = 0;
    *(undefined4 *)(param_1->__locales[2] + 0x24) = 0x2e;
  }
  else {
    pcVar8 = (char *)__nl_langinfo_l(0x40007,param_2);
    *(int *)(param_1->__locales[2] + 0x60) = (int)*pcVar8;
  }
  pcVar8 = (char *)__nl_langinfo_l(0x40004,param_2);
  local_60 = (char *)__nl_langinfo_l(0x40005,param_2);
  local_58 = (char *)__nl_langinfo_l(0x40006,param_2);
  local_50 = (char *)__nl_langinfo_l(0x40000,param_2);
  pcVar9 = (char *)__nl_langinfo_l(0x40015,param_2);
  p_Var13 = param_1->__locales[2];
  cVar2 = *pcVar9;
  if (*(int *)(p_Var13 + 0x28) == 0) {
    *(undefined **)(p_Var13 + 0x10) = &DAT_00cb99b6;
    *(undefined8 *)(param_1->__locales[2] + 0x18) = 0;
    param_1->__locales[2][0x20] = (__locale_data)0x0;
    *(undefined4 *)(param_1->__locales[2] + 0x28) = 0x2c;
    sVar10 = strlen(local_60);
    if (sVar10 != 0) goto LAB_00c736d3;
LAB_00c73448:
    *(undefined **)(param_1->__locales[2] + 0x40) = &DAT_00d94f28;
  }
  else {
    sVar10 = strlen(pcVar8);
    if (sVar10 == 0) {
      *(undefined **)(p_Var13 + 0x10) = &DAT_00cb99b6;
      param_1->__locales[2][0x20] = (__locale_data)0x0;
    }
    else {
                    /* try { // try from 00c7375b to 00c7375f has its CatchHandler @ 00c738de */
      __dest = operator_new__(sVar10 + 1);
      memcpy(__dest,pcVar8,sVar10 + 1);
      *(void **)(param_1->__locales[2] + 0x10) = __dest;
    }
    *(size_t *)(param_1->__locales[2] + 0x18) = sVar10;
    sVar10 = strlen(local_60);
    if (sVar10 == 0) goto LAB_00c73448;
LAB_00c736d3:
    local_48.__count = 0;
    local_48.__value = (_union_27)0x0;
    uVar1 = sVar10 + 1;
    uVar14 = uVar1 * 4;
    if (0x1ffffffffffffffe < uVar1) {
      uVar14 = 0xffffffffffffffff;
    }
                    /* try { // try from 00c73700 to 00c73704 has its CatchHandler @ 00c738cf */
    pwVar12 = operator_new__(uVar14);
    mbsrtowcs(pwVar12,&local_60,uVar1,&local_48);
    *(wchar_t **)(param_1->__locales[2] + 0x40) = pwVar12;
  }
  p_Var13 = param_1->__locales[2];
  sVar10 = wcslen(*(wchar_t **)(p_Var13 + 0x40));
  *(size_t *)(p_Var13 + 0x48) = sVar10;
  if (cVar2 == '\0') {
    *(undefined **)(param_1->__locales[2] + 0x50) = &DAT_00d94f20;
  }
  else {
    sVar10 = strlen(local_58);
    if (sVar10 == 0) {
      *(undefined **)(param_1->__locales[2] + 0x50) = &DAT_00d94f28;
    }
    else {
      local_48.__count = 0;
      local_48.__value = (_union_27)0x0;
      uVar1 = sVar10 + 1;
      uVar14 = uVar1 * 4;
      if (0x1ffffffffffffffe < uVar1) {
        uVar14 = 0xffffffffffffffff;
      }
                    /* try { // try from 00c737b5 to 00c737b9 has its CatchHandler @ 00c738d9 */
      pwVar12 = operator_new__(uVar14);
      mbsrtowcs(pwVar12,&local_58,uVar1,&local_48);
      *(wchar_t **)(param_1->__locales[2] + 0x50) = pwVar12;
    }
  }
  p_Var13 = param_1->__locales[2];
  sVar10 = wcslen(*(wchar_t **)(p_Var13 + 0x50));
  *(size_t *)(p_Var13 + 0x58) = sVar10;
  sVar10 = strlen(local_50);
  if (sVar10 == 0) {
    *(undefined **)(param_1->__locales[2] + 0x30) = &DAT_00d94f28;
  }
  else {
    local_48.__count = 0;
    local_48.__value = (_union_27)0x0;
    uVar1 = sVar10 + 1;
    uVar14 = uVar1 * 4;
    if (0x1ffffffffffffffe < uVar1) {
      uVar14 = 0xffffffffffffffff;
    }
                    /* try { // try from 00c73815 to 00c73819 has its CatchHandler @ 00c738d4 */
    pwVar12 = operator_new__(uVar14);
    mbsrtowcs(pwVar12,&local_50,uVar1,&local_48);
    *(wchar_t **)(param_1->__locales[2] + 0x30) = pwVar12;
  }
  p_Var13 = param_1->__locales[2];
  sVar10 = wcslen(*(wchar_t **)(p_Var13 + 0x30));
  *(size_t *)(p_Var13 + 0x38) = sVar10;
  pcVar8 = (char *)__nl_langinfo_l(0x40010,param_2);
  cVar3 = *pcVar8;
  pcVar8 = (char *)__nl_langinfo_l(0x40011,param_2);
  cVar4 = *pcVar8;
  pcVar8 = (char *)__nl_langinfo_l(0x40014,param_2);
  p_Var13 = param_1->__locales[2];
  uVar6 = money_base::_S_construct_pattern(cVar3,cVar4,*pcVar8);
  *(undefined4 *)(p_Var13 + 100) = uVar6;
  pcVar8 = (char *)__nl_langinfo_l(0x40012,param_2);
  cVar3 = *pcVar8;
  pcVar8 = (char *)__nl_langinfo_l(0x40013,param_2);
  p_Var13 = param_1->__locales[2];
  uVar6 = money_base::_S_construct_pattern(cVar3,*pcVar8,cVar2);
  *(undefined4 *)(p_Var13 + 0x68) = uVar6;
  __uselocale(uVar7);
LAB_00c73555:
  if (local_40 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


// ==== entry=00c738f0 orig=FUN_00c738f0 size=1437 name=_M_initialize_moneypunct ====

/* std::moneypunct<wchar_t, false>::_M_initialize_moneypunct(__locale_struct*, char const*) */

void std::moneypunct<wchar_t,false>::_M_initialize_moneypunct
               (__locale_struct *param_1,char *param_2)

{
  ulong uVar1;
  char cVar2;
  char cVar3;
  char cVar4;
  undefined *puVar5;
  undefined4 uVar6;
  undefined8 uVar7;
  char *pcVar8;
  char *pcVar9;
  size_t sVar10;
  long lVar11;
  void *__dest;
  wchar_t *pwVar12;
  __locale_data *p_Var13;
  ulong uVar14;
  long in_FS_OFFSET;
  char *local_60;
  char *local_58;
  char *local_50;
  mbstate_t local_48;
  long local_40;
  
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  if (param_1->__locales[2] == (__locale_data *)0x0) {
    p_Var13 = operator_new(0xa0);
    *(undefined4 *)(p_Var13 + 8) = 0;
    *(undefined8 *)(p_Var13 + 0x10) = 0;
    *(undefined ***)p_Var13 = &PTR____moneypunct_cache_011b2878;
    *(undefined8 *)(p_Var13 + 0x18) = 0;
    p_Var13[0x20] = (__locale_data)0x0;
    *(undefined8 *)(p_Var13 + 0x24) = 0;
    *(undefined8 *)(p_Var13 + 0x30) = 0;
    *(undefined8 *)(p_Var13 + 0x38) = 0;
    *(undefined8 *)(p_Var13 + 0x40) = 0;
    *(undefined8 *)(p_Var13 + 0x48) = 0;
    *(undefined8 *)(p_Var13 + 0x50) = 0;
    *(undefined8 *)(p_Var13 + 0x58) = 0;
    *(undefined8 *)(p_Var13 + 0x60) = 0;
    *(undefined4 *)(p_Var13 + 0x68) = 0;
    p_Var13[0x98] = (__locale_data)0x0;
    param_1->__locales[2] = p_Var13;
  }
  if (param_2 == (char *)0x0) {
    *(undefined4 *)(param_1->__locales[2] + 0x24) = 0x2e;
    *(undefined4 *)(param_1->__locales[2] + 0x28) = 0x2c;
    *(undefined **)(param_1->__locales[2] + 0x10) = &DAT_00cb99b6;
    *(undefined8 *)(param_1->__locales[2] + 0x18) = 0;
    param_1->__locales[2][0x20] = (__locale_data)0x0;
    *(undefined **)(param_1->__locales[2] + 0x30) = &DAT_00d94f28;
    *(undefined8 *)(param_1->__locales[2] + 0x38) = 0;
    *(undefined **)(param_1->__locales[2] + 0x40) = &DAT_00d94f28;
    *(undefined8 *)(param_1->__locales[2] + 0x48) = 0;
    *(undefined **)(param_1->__locales[2] + 0x50) = &DAT_00d94f28;
    *(undefined8 *)(param_1->__locales[2] + 0x58) = 0;
    *(undefined4 *)(param_1->__locales[2] + 0x60) = 0;
    *(undefined4 *)(param_1->__locales[2] + 100) = 0x4000302;
    *(undefined4 *)(param_1->__locales[2] + 0x68) = 0x4000302;
    puVar5 = money_base::_S_atoms;
    lVar11 = 0;
    do {
      *(int *)(param_1->__locales[2] + lVar11 * 4 + 0x6c) = (int)(char)puVar5[lVar11];
      lVar11 = lVar11 + 1;
    } while (lVar11 != 0xb);
    goto LAB_00c73b35;
  }
  uVar7 = __uselocale(param_2);
  uVar6 = __nl_langinfo_l(0x4002b,param_2);
  *(undefined4 *)(param_1->__locales[2] + 0x24) = uVar6;
  uVar6 = __nl_langinfo_l(0x4002c,param_2);
  *(undefined4 *)(param_1->__locales[2] + 0x28) = uVar6;
  if (*(int *)(param_1->__locales[2] + 0x24) == 0) {
    *(undefined4 *)(param_1->__locales[2] + 0x60) = 0;
    *(undefined4 *)(param_1->__locales[2] + 0x24) = 0x2e;
  }
  else {
    pcVar8 = (char *)__nl_langinfo_l(0x40008,param_2);
    *(int *)(param_1->__locales[2] + 0x60) = (int)*pcVar8;
  }
  pcVar8 = (char *)__nl_langinfo_l(0x40004,param_2);
  local_60 = (char *)__nl_langinfo_l(0x40005,param_2);
  local_58 = (char *)__nl_langinfo_l(0x40006,param_2);
  local_50 = (char *)__nl_langinfo_l(0x40001,param_2);
  pcVar9 = (char *)__nl_langinfo_l(0x4000e,param_2);
  p_Var13 = param_1->__locales[2];
  cVar2 = *pcVar9;
  if (*(int *)(p_Var13 + 0x28) == 0) {
    *(undefined **)(p_Var13 + 0x10) = &DAT_00cb99b6;
    *(undefined8 *)(param_1->__locales[2] + 0x18) = 0;
    param_1->__locales[2][0x20] = (__locale_data)0x0;
    *(undefined4 *)(param_1->__locales[2] + 0x28) = 0x2c;
    sVar10 = strlen(local_60);
    if (sVar10 != 0) goto LAB_00c73cb3;
LAB_00c73a28:
    *(undefined **)(param_1->__locales[2] + 0x40) = &DAT_00d94f28;
  }
  else {
    sVar10 = strlen(pcVar8);
    if (sVar10 == 0) {
      *(undefined **)(p_Var13 + 0x10) = &DAT_00cb99b6;
      param_1->__locales[2][0x20] = (__locale_data)0x0;
    }
    else {
                    /* try { // try from 00c73d3b to 00c73d3f has its CatchHandler @ 00c73ebe */
      __dest = operator_new__(sVar10 + 1);
      memcpy(__dest,pcVar8,sVar10 + 1);
      *(void **)(param_1->__locales[2] + 0x10) = __dest;
    }
    *(size_t *)(param_1->__locales[2] + 0x18) = sVar10;
    sVar10 = strlen(local_60);
    if (sVar10 == 0) goto LAB_00c73a28;
LAB_00c73cb3:
    local_48.__count = 0;
    local_48.__value = (_union_27)0x0;
    uVar1 = sVar10 + 1;
    uVar14 = uVar1 * 4;
    if (0x1ffffffffffffffe < uVar1) {
      uVar14 = 0xffffffffffffffff;
    }
                    /* try { // try from 00c73ce0 to 00c73ce4 has its CatchHandler @ 00c73eaf */
    pwVar12 = operator_new__(uVar14);
    mbsrtowcs(pwVar12,&local_60,uVar1,&local_48);
    *(wchar_t **)(param_1->__locales[2] + 0x40) = pwVar12;
  }
  p_Var13 = param_1->__locales[2];
  sVar10 = wcslen(*(wchar_t **)(p_Var13 + 0x40));
  *(size_t *)(p_Var13 + 0x48) = sVar10;
  if (cVar2 == '\0') {
    *(undefined **)(param_1->__locales[2] + 0x50) = &DAT_00d94f20;
  }
  else {
    sVar10 = strlen(local_58);
    if (sVar10 == 0) {
      *(undefined **)(param_1->__locales[2] + 0x50) = &DAT_00d94f28;
    }
    else {
      local_48.__count = 0;
      local_48.__value = (_union_27)0x0;
      uVar1 = sVar10 + 1;
      uVar14 = uVar1 * 4;
      if (0x1ffffffffffffffe < uVar1) {
        uVar14 = 0xffffffffffffffff;
      }
                    /* try { // try from 00c73d95 to 00c73d99 has its CatchHandler @ 00c73eb9 */
      pwVar12 = operator_new__(uVar14);
      mbsrtowcs(pwVar12,&local_58,uVar1,&local_48);
      *(wchar_t **)(param_1->__locales[2] + 0x50) = pwVar12;
    }
  }
  p_Var13 = param_1->__locales[2];
  sVar10 = wcslen(*(wchar_t **)(p_Var13 + 0x50));
  *(size_t *)(p_Var13 + 0x58) = sVar10;
  sVar10 = strlen(local_50);
  if (sVar10 == 0) {
    *(undefined **)(param_1->__locales[2] + 0x30) = &DAT_00d94f28;
  }
  else {
    local_48.__count = 0;
    local_48.__value = (_union_27)0x0;
    uVar1 = sVar10 + 1;
    uVar14 = uVar1 * 4;
    if (0x1ffffffffffffffe < uVar1) {
      uVar14 = 0xffffffffffffffff;
    }
                    /* try { // try from 00c73df5 to 00c73df9 has its CatchHandler @ 00c73eb4 */
    pwVar12 = operator_new__(uVar14);
    mbsrtowcs(pwVar12,&local_50,uVar1,&local_48);
    *(wchar_t **)(param_1->__locales[2] + 0x30) = pwVar12;
  }
  p_Var13 = param_1->__locales[2];
  sVar10 = wcslen(*(wchar_t **)(p_Var13 + 0x30));
  *(size_t *)(p_Var13 + 0x38) = sVar10;
  pcVar8 = (char *)__nl_langinfo_l(0x40009,param_2);
  cVar3 = *pcVar8;
  pcVar8 = (char *)__nl_langinfo_l(0x4000a,param_2);
  cVar4 = *pcVar8;
  pcVar8 = (char *)__nl_langinfo_l(0x4000d,param_2);
  p_Var13 = param_1->__locales[2];
  uVar6 = money_base::_S_construct_pattern(cVar3,cVar4,*pcVar8);
  *(undefined4 *)(p_Var13 + 100) = uVar6;
  pcVar8 = (char *)__nl_langinfo_l(0x4000b,param_2);
  cVar3 = *pcVar8;
  pcVar8 = (char *)__nl_langinfo_l(0x4000c,param_2);
  p_Var13 = param_1->__locales[2];
  uVar6 = money_base::_S_construct_pattern(cVar3,*pcVar8,cVar2);
  *(undefined4 *)(p_Var13 + 0x68) = uVar6;
  __uselocale(uVar7);
LAB_00c73b35:
  if (local_40 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


// ==== entry=00c73ed0 orig=FUN_00c73ed0 size=179 name=~moneypunct ====

/* std::moneypunct<wchar_t, true>::~moneypunct() */

void __thiscall std::moneypunct<wchar_t,true>::~moneypunct(moneypunct<wchar_t,true> *this)

{
  wchar_t *__s1;
  int iVar1;
  long *plVar2;
  
  plVar2 = *(long **)(this + 0x10);
  *(undefined ***)this = &PTR__moneypunct_011b6cf8;
  if ((plVar2[3] != 0) && ((void *)plVar2[2] != (void *)0x0)) {
    operator_delete__((void *)plVar2[2]);
    plVar2 = *(long **)(this + 0x10);
  }
  if ((plVar2[9] != 0) && ((void *)plVar2[8] != (void *)0x0)) {
    operator_delete__((void *)plVar2[8]);
    plVar2 = *(long **)(this + 0x10);
  }
  if (plVar2[0xb] != 0) {
    __s1 = (wchar_t *)plVar2[10];
    iVar1 = wcscmp(__s1,L"()");
    if ((iVar1 != 0) && (__s1 != (wchar_t *)0x0)) {
      operator_delete__(__s1);
      plVar2 = *(long **)(this + 0x10);
    }
  }
  if ((plVar2[7] != 0) && ((void *)plVar2[6] != (void *)0x0)) {
    operator_delete__((void *)plVar2[6]);
    plVar2 = *(long **)(this + 0x10);
    if (plVar2 == (long *)0x0) goto LAB_00c73f69;
  }
                    /* try { // try from 00c73f66 to 00c73f68 has its CatchHandler @ 00c73f86 */
  (**(code **)(*plVar2 + 8))(plVar2);
LAB_00c73f69:
  locale::facet::~facet((facet *)this);
  return;
}


// ==== entry=00c73f90 orig=FUN_00c73f90 size=28 name=~moneypunct ====

/* std::moneypunct<wchar_t, true>::~moneypunct() */

void __thiscall std::moneypunct<wchar_t,true>::~moneypunct(moneypunct<wchar_t,true> *this)

{
                    /* try { // try from 00c73f99 to 00c73f9d has its CatchHandler @ 00c73fac */
  ~moneypunct(this);
  operator_delete(this);
  return;
}


// ==== entry=00c73fc0 orig=FUN_00c73fc0 size=179 name=~moneypunct ====

/* std::moneypunct<wchar_t, false>::~moneypunct() */

void __thiscall std::moneypunct<wchar_t,false>::~moneypunct(moneypunct<wchar_t,false> *this)

{
  wchar_t *__s1;
  int iVar1;
  long *plVar2;
  
  plVar2 = *(long **)(this + 0x10);
  *(undefined ***)this = &PTR__moneypunct_011b6d60;
  if ((plVar2[3] != 0) && ((void *)plVar2[2] != (void *)0x0)) {
    operator_delete__((void *)plVar2[2]);
    plVar2 = *(long **)(this + 0x10);
  }
  if ((plVar2[9] != 0) && ((void *)plVar2[8] != (void *)0x0)) {
    operator_delete__((void *)plVar2[8]);
    plVar2 = *(long **)(this + 0x10);
  }
  if (plVar2[0xb] != 0) {
    __s1 = (wchar_t *)plVar2[10];
    iVar1 = wcscmp(__s1,L"()");
    if ((iVar1 != 0) && (__s1 != (wchar_t *)0x0)) {
      operator_delete__(__s1);
      plVar2 = *(long **)(this + 0x10);
    }
  }
  if ((plVar2[7] != 0) && ((void *)plVar2[6] != (void *)0x0)) {
    operator_delete__((void *)plVar2[6]);
    plVar2 = *(long **)(this + 0x10);
    if (plVar2 == (long *)0x0) goto LAB_00c74059;
  }
                    /* try { // try from 00c74056 to 00c74058 has its CatchHandler @ 00c74076 */
  (**(code **)(*plVar2 + 8))(plVar2);
LAB_00c74059:
  locale::facet::~facet((facet *)this);
  return;
}


// ==== entry=00c74080 orig=FUN_00c74080 size=28 name=~moneypunct ====

/* std::moneypunct<wchar_t, false>::~moneypunct() */

void __thiscall std::moneypunct<wchar_t,false>::~moneypunct(moneypunct<wchar_t,false> *this)

{
                    /* try { // try from 00c74089 to 00c7408d has its CatchHandler @ 00c7409c */
  ~moneypunct(this);
  operator_delete(this);
  return;
}


// ==== entry=00c740b0 name=FUN_00c740b0 size=42 ====

long FUN_00c740b0(long *param_1,long param_2)

{
  long lVar1;
  
  lVar1 = *param_1;
  std::__cxx11::string::_M_erase((ulong)param_1,param_2 - lVar1);
  return *param_1 + (param_2 - lVar1);
}


// ==== entry=00c740e0 name=FUN_00c740e0 size=73 ====

long FUN_00c740e0(long *param_1,undefined1 *param_2,long param_3)

{
  ulong uVar1;
  
  uVar1 = (long)param_2 - *param_1;
  if (param_3 != *param_1 + param_1[1]) {
    std::__cxx11::string::_M_erase((ulong)param_1,uVar1);
    return *param_1 + uVar1;
  }
  param_1[1] = uVar1;
  *param_2 = 0;
  return *param_1 + uVar1;
}


// ==== entry=00c74130 name=FUN_00c74130 size=17 ====

void FUN_00c74130(long *param_1,long param_2,char param_3)

{
  std::__cxx11::string::_M_replace_aux((ulong)param_1,param_2 - *param_1,0,param_3);
  return;
}


// ==== entry=00c74150 orig=FUN_00c74150 size=53 name=s_basic_string__replace_c74150 ====

void s_basic_string__replace_c74150(long *param_1,long param_2,ulong param_3,long param_4)

{
  ulong uVar1;
  
  uVar1 = param_2 - *param_1;
  if (uVar1 <= (ulong)param_1[1]) {
    std::__cxx11::string::_M_replace((ulong)param_1,uVar1,(char *)0x0,param_3);
    return;
  }
                    /* WARNING: Subroutine does not return */
  std::__throw_out_of_range_fmt
            ("%s: __pos (which is %zu) > this->size() (which is %zu)","basic_string::replace",uVar1,
             param_1[1],param_4 - param_3);
}


// ==== entry=00c74190 name=FUN_00c74190 size=48 ====

long FUN_00c74190(long *param_1,long param_2)

{
  long lVar1;
  
  lVar1 = *param_1;
  std::__cxx11::string::_M_replace_aux((ulong)param_1,param_2 - lVar1,0,'\x01');
  return *param_1 + (param_2 - lVar1);
}


// ==== entry=00c741c0 orig=FUN_00c741c0 size=74 name=s_basic_string__replace_c741c0 ====

void s_basic_string__replace_c741c0(long *param_1,long param_2,long param_3,ulong *param_4)

{
  ulong uVar1;
  ulong uVar2;
  char *pcVar3;
  
  uVar1 = param_1[1];
  uVar2 = param_2 - *param_1;
  pcVar3 = (char *)(param_3 - param_2);
  if ((char *)(uVar1 - uVar2) < (char *)(param_3 - param_2)) {
    pcVar3 = (char *)(uVar1 - uVar2);
  }
  if (uVar2 <= uVar1) {
    std::__cxx11::string::_M_replace((ulong)param_1,uVar2,pcVar3,*param_4);
    return;
  }
                    /* WARNING: Subroutine does not return */
  std::__throw_out_of_range_fmt
            ("%s: __pos (which is %zu) > this->size() (which is %zu)","basic_string::replace",uVar2,
             uVar1,param_4[1],uVar1,pcVar3);
}


// ==== entry=00c74210 orig=FUN_00c74210 size=67 name=s_basic_string__replace_c74210 ====

void s_basic_string__replace_c74210
               (long *param_1,long param_2,long param_3,ulong param_4,undefined8 param_5)

{
  ulong uVar1;
  ulong uVar2;
  char *pcVar3;
  
  uVar1 = param_1[1];
  uVar2 = param_2 - *param_1;
  pcVar3 = (char *)(param_3 - param_2);
  if ((char *)(uVar1 - uVar2) < (char *)(param_3 - param_2)) {
    pcVar3 = (char *)(uVar1 - uVar2);
  }
  if (uVar2 <= uVar1) {
    std::__cxx11::string::_M_replace((ulong)param_1,uVar2,pcVar3,param_4);
    return;
  }
                    /* WARNING: Subroutine does not return */
  std::__throw_out_of_range_fmt
            ("%s: __pos (which is %zu) > this->size() (which is %zu)","basic_string::replace",uVar2,
             uVar1,param_5,uVar1,pcVar3);
}


// ==== entry=00c74260 orig=FUN_00c74260 size=116 name=s_basic_string__replace_c74260 ====

void s_basic_string__replace_c74260(long *param_1,long param_2,long param_3,char *param_4)

{
  char *pcVar1;
  char *pcVar2;
  ulong uVar3;
  
  strlen(param_4);
  uVar3 = param_2 - *param_1;
  pcVar2 = (char *)(param_1[1] - uVar3);
  pcVar1 = (char *)(param_3 - param_2);
  if (pcVar2 < (char *)(param_3 - param_2)) {
    pcVar1 = pcVar2;
  }
  if (uVar3 <= (ulong)param_1[1]) {
    std::__cxx11::string::_M_replace((ulong)param_1,uVar3,pcVar1,(ulong)param_4);
    return;
  }
                    /* WARNING: Subroutine does not return */
  std::__throw_out_of_range_fmt
            ("%s: __pos (which is %zu) > this->size() (which is %zu)","basic_string::replace",uVar3)
  ;
}


// ==== entry=00c742e0 name=FUN_00c742e0 size=15 ====

void FUN_00c742e0(long *param_1,long param_2,long param_3,char param_4)

{
  std::__cxx11::string::_M_replace_aux((ulong)param_1,param_2 - *param_1,param_3 - param_2,param_4);
  return;
}


// ==== entry=00c742f0 orig=FUN_00c742f0 size=70 name=s_basic_string__replace_c742f0 ====

void s_basic_string__replace_c742f0
               (long *param_1,long param_2,long param_3,ulong param_4,long param_5)

{
  ulong uVar1;
  ulong uVar2;
  char *pcVar3;
  
  uVar1 = param_1[1];
  uVar2 = param_2 - *param_1;
  pcVar3 = (char *)(param_3 - param_2);
  if ((char *)(uVar1 - uVar2) < (char *)(param_3 - param_2)) {
    pcVar3 = (char *)(uVar1 - uVar2);
  }
  if (uVar2 <= uVar1) {
    std::__cxx11::string::_M_replace((ulong)param_1,uVar2,pcVar3,param_4);
    return;
  }
                    /* WARNING: Subroutine does not return */
  std::__throw_out_of_range_fmt
            ("%s: __pos (which is %zu) > this->size() (which is %zu)","basic_string::replace",uVar2,
             uVar1,param_5 - param_4,uVar1,pcVar3);
}


// ==== entry=00c74340 orig=FUN_00c74340 size=70 name=s_basic_string__replace_c74340 ====

void s_basic_string__replace_c74340
               (long *param_1,long param_2,long param_3,ulong param_4,long param_5)

{
  ulong uVar1;
  ulong uVar2;
  char *pcVar3;
  
  uVar1 = param_1[1];
  uVar2 = param_2 - *param_1;
  pcVar3 = (char *)(param_3 - param_2);
  if ((char *)(uVar1 - uVar2) < (char *)(param_3 - param_2)) {
    pcVar3 = (char *)(uVar1 - uVar2);
  }
  if (uVar2 <= uVar1) {
    std::__cxx11::string::_M_replace((ulong)param_1,uVar2,pcVar3,param_4);
    return;
  }
                    /* WARNING: Subroutine does not return */
  std::__throw_out_of_range_fmt
            ("%s: __pos (which is %zu) > this->size() (which is %zu)","basic_string::replace",uVar2,
             uVar1,param_5 - param_4,uVar1,pcVar3);
}


// ==== entry=00c74390 orig=FUN_00c74390 size=70 name=s_basic_string__replace_c74390 ====

void s_basic_string__replace_c74390
               (long *param_1,long param_2,long param_3,ulong param_4,long param_5)

{
  ulong uVar1;
  ulong uVar2;
  char *pcVar3;
  
  uVar1 = param_1[1];
  uVar2 = param_2 - *param_1;
  pcVar3 = (char *)(param_3 - param_2);
  if ((char *)(uVar1 - uVar2) < (char *)(param_3 - param_2)) {
    pcVar3 = (char *)(uVar1 - uVar2);
  }
  if (uVar2 <= uVar1) {
    std::__cxx11::string::_M_replace((ulong)param_1,uVar2,pcVar3,param_4);
    return;
  }
                    /* WARNING: Subroutine does not return */
  std::__throw_out_of_range_fmt
            ("%s: __pos (which is %zu) > this->size() (which is %zu)","basic_string::replace",uVar2,
             uVar1,param_5 - param_4,uVar1,pcVar3);
}


// ==== entry=00c743e0 orig=FUN_00c743e0 size=70 name=s_basic_string__replace_c743e0 ====

void s_basic_string__replace_c743e0
               (long *param_1,long param_2,long param_3,ulong param_4,long param_5)

{
  ulong uVar1;
  ulong uVar2;
  char *pcVar3;
  
  uVar1 = param_1[1];
  uVar2 = param_2 - *param_1;
  pcVar3 = (char *)(param_3 - param_2);
  if ((char *)(uVar1 - uVar2) < (char *)(param_3 - param_2)) {
    pcVar3 = (char *)(uVar1 - uVar2);
  }
  if (uVar2 <= uVar1) {
    std::__cxx11::string::_M_replace((ulong)param_1,uVar2,pcVar3,param_4);
    return;
  }
                    /* WARNING: Subroutine does not return */
  std::__throw_out_of_range_fmt
            ("%s: __pos (which is %zu) > this->size() (which is %zu)","basic_string::replace",uVar2,
             uVar1,param_5 - param_4,uVar1,pcVar3);
}


// ==== entry=00c74430 name=FUN_00c74430 size=46 ====

long FUN_00c74430(long *param_1,long param_2)

{
  long lVar1;
  
  lVar1 = *param_1;
  FUN_00c22240(param_1,param_2 - lVar1 >> 2,1);
  return *param_1 + (param_2 - lVar1);
}


// ==== entry=00c74460 name=FUN_00c74460 size=83 ====

undefined4 * FUN_00c74460(long *param_1,undefined4 *param_2,long param_3)

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


// ==== entry=00c744c0 name=FUN_00c744c0 size=20 ====

void FUN_00c744c0(long *param_1,long param_2,undefined8 param_3,undefined4 param_4)

{
  wstring_replace_fill(param_1,param_2 - *param_1 >> 2,0,param_3,param_4);
  return;
}


// ==== entry=00c744e0 orig=FUN_00c744e0 size=61 name=s_basic_string__replace_c744e0 ====

void s_basic_string__replace_c744e0(long *param_1,long param_2,long param_3,long param_4)

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
             param_1[1],param_4 - param_3 >> 2);
}


// ==== entry=00c74520 name=FUN_00c74520 size=51 ====

long FUN_00c74520(long *param_1,long param_2,undefined4 param_3)

{
  long lVar1;
  
  lVar1 = *param_1;
  wstring_replace_fill(param_1,param_2 - lVar1 >> 2,0,1,param_3);
  return *param_1 + (param_2 - lVar1);
}


// ==== entry=00c74560 orig=FUN_00c74560 size=82 name=s_basic_string__replace_c74560 ====

void s_basic_string__replace_c74560(long *param_1,long param_2,long param_3,undefined8 *param_4)

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


// ==== entry=00c745c0 orig=FUN_00c745c0 size=75 name=s_basic_string__replace_c745c0 ====

void s_basic_string__replace_c745c0
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


// ==== entry=00c74610 orig=FUN_00c74610 size=124 name=s_basic_string__replace_c74610 ====

void s_basic_string__replace_c74610(long *param_1,long param_2,long param_3,wchar_t *param_4)

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


// ==== entry=00c74690 name=FUN_00c74690 size=19 ====

void FUN_00c74690(long *param_1,long param_2,long param_3)

{
  wstring_replace_fill(param_1,param_2 - *param_1 >> 2,param_3 - param_2 >> 2);
  return;
}


// ==== entry=00c746b0 orig=FUN_00c746b0 size=82 name=s_basic_string__replace_c746b0 ====

void s_basic_string__replace_c746b0
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


// ==== entry=00c74710 orig=FUN_00c74710 size=82 name=s_basic_string__replace_c74710 ====

void s_basic_string__replace_c74710
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


// ==== entry=00c74770 orig=FUN_00c74770 size=82 name=s_basic_string__replace_c74770 ====

void s_basic_string__replace_c74770
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


// ==== entry=00c747d0 orig=FUN_00c747d0 size=82 name=s_basic_string__replace_c747d0 ====

void s_basic_string__replace_c747d0
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


// ==== entry=00c74830 name=FUN_00c74830 size=21 ====

void FUN_00c74830(undefined8 param_1,undefined8 param_2,undefined8 *param_3)

{
                    /* try { // try from 00c7483b to 00c7483f has its CatchHandler @ 00c74845 */
  FUN_00bf32d0(param_1,param_2,*param_3,param_3[1]);
  return;
}


// ==== entry=00c74850 orig=FUN_00c74850 size=550 name=_M_initialize_numpunct ====

/* std::numpunct<char>::_M_initialize_numpunct(__locale_struct*) */

void __thiscall
std::numpunct<char>::_M_initialize_numpunct(numpunct<char> *this,__locale_struct *param_1)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined1 *puVar3;
  long lVar4;
  char *__s;
  size_t sVar5;
  undefined8 *puVar6;
  void *pvVar7;
  
  if (*(long *)(this + 0x10) == 0) {
    puVar6 = operator_new(0x90);
    *(undefined4 *)(puVar6 + 1) = 0;
    puVar6[2] = 0;
    *puVar6 = &PTR____numpunct_cache_011b28c8;
    puVar6[3] = 0;
    *(undefined1 *)(puVar6 + 4) = 0;
    puVar6[5] = 0;
    puVar6[6] = 0;
    puVar6[7] = 0;
    puVar6[8] = 0;
    *(undefined2 *)(puVar6 + 9) = 0;
    *(undefined1 *)(puVar6 + 0x11) = 0;
    *(undefined8 **)(this + 0x10) = puVar6;
  }
  if (param_1 == (__locale_struct *)0x0) {
    *(undefined **)(*(long *)(this + 0x10) + 0x10) = &DAT_00cb99b6;
    *(undefined8 *)(*(long *)(this + 0x10) + 0x18) = 0;
    *(undefined1 *)(*(long *)(this + 0x10) + 0x20) = 0;
    *(undefined1 *)(*(long *)(this + 0x10) + 0x48) = 0x2e;
    *(undefined1 *)(*(long *)(this + 0x10) + 0x49) = 0x2c;
    puVar1 = __num_base::_S_atoms_out;
    lVar4 = 0;
    do {
      *(undefined *)(*(long *)(this + 0x10) + 0x4a + lVar4) = puVar1[lVar4];
      puVar2 = __num_base::_S_atoms_in;
      lVar4 = lVar4 + 1;
    } while (lVar4 != 0x24);
    lVar4 = 0;
    do {
      *(undefined *)(*(long *)(this + 0x10) + 0x6e + lVar4) = puVar2[lVar4];
      lVar4 = lVar4 + 1;
    } while (lVar4 != 0x1a);
  }
  else {
    puVar3 = (undefined1 *)__nl_langinfo_l(0x10000,param_1);
    *(undefined1 *)(*(long *)(this + 0x10) + 0x48) = *puVar3;
    puVar3 = (undefined1 *)__nl_langinfo_l(0x10001,param_1);
    *(undefined1 *)(*(long *)(this + 0x10) + 0x49) = *puVar3;
    if (*(char *)(*(long *)(this + 0x10) + 0x49) == '\0') {
      *(undefined **)(*(long *)(this + 0x10) + 0x10) = &DAT_00cb99b6;
      *(undefined8 *)(*(long *)(this + 0x10) + 0x18) = 0;
      *(undefined1 *)(*(long *)(this + 0x10) + 0x20) = 0;
      *(undefined1 *)(*(long *)(this + 0x10) + 0x49) = 0x2c;
    }
    else {
      __s = (char *)__nl_langinfo_l(0x10002,param_1);
      sVar5 = strlen(__s);
      if (sVar5 == 0) {
        *(undefined **)(*(long *)(this + 0x10) + 0x10) = &DAT_00cb99b6;
        *(undefined1 *)(*(long *)(this + 0x10) + 0x20) = 0;
      }
      else {
                    /* try { // try from 00c74a60 to 00c74a64 has its CatchHandler @ 00c74a83 */
        pvVar7 = operator_new__(sVar5 + 1);
        pvVar7 = memcpy(pvVar7,__s,sVar5 + 1);
        *(void **)(*(long *)(this + 0x10) + 0x10) = pvVar7;
      }
      *(size_t *)(*(long *)(this + 0x10) + 0x18) = sVar5;
    }
  }
  *(undefined **)(*(long *)(this + 0x10) + 0x28) = &DAT_00c8d38f;
  *(undefined8 *)(*(long *)(this + 0x10) + 0x30) = 4;
  *(char **)(*(long *)(this + 0x10) + 0x38) = "false";
  *(undefined8 *)(*(long *)(this + 0x10) + 0x40) = 5;
  return;
}


// ==== entry=00c74a90 orig=FUN_00c74a90 size=84 name=~numpunct ====

/* std::numpunct<char>::~numpunct() */

void __thiscall std::numpunct<char>::~numpunct(numpunct<char> *this)

{
  long *plVar1;
  
  *(undefined ***)this = &PTR__numpunct_011b5510;
  plVar1 = *(long **)(this + 0x10);
  if ((plVar1[3] != 0) && ((void *)plVar1[2] != (void *)0x0)) {
    operator_delete__((void *)plVar1[2]);
    plVar1 = *(long **)(this + 0x10);
    if (plVar1 == (long *)0x0) goto LAB_00c74ad6;
  }
                    /* try { // try from 00c74ad3 to 00c74ad5 has its CatchHandler @ 00c74ae4 */
  (**(code **)(*plVar1 + 8))();
LAB_00c74ad6:
  locale::facet::~facet((facet *)this);
  return;
}


// ==== entry=00c74af0 orig=FUN_00c74af0 size=28 name=~numpunct ====

/* std::numpunct<char>::~numpunct() */

void __thiscall std::numpunct<char>::~numpunct(numpunct<char> *this)

{
                    /* try { // try from 00c74af9 to 00c74afd has its CatchHandler @ 00c74b0c */
  ~numpunct(this);
  operator_delete(this);
  return;
}


// ==== entry=00c74b20 orig=FUN_00c74b20 size=487 name=_M_initialize_numpunct ====

/* std::numpunct<wchar_t>::_M_initialize_numpunct(__locale_struct*) */

void __thiscall
std::numpunct<wchar_t>::_M_initialize_numpunct(numpunct<wchar_t> *this,__locale_struct *param_1)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined4 uVar3;
  int iVar4;
  long lVar5;
  char *__s;
  size_t sVar6;
  undefined8 *puVar7;
  void *pvVar8;
  long lVar9;
  
  if (*(long *)(this + 0x10) == 0) {
    puVar7 = operator_new(0x150);
    *(undefined4 *)(puVar7 + 1) = 0;
    puVar7[2] = 0;
    *puVar7 = &PTR____numpunct_cache_011b28e8;
    puVar7[3] = 0;
    *(undefined1 *)(puVar7 + 4) = 0;
    puVar7[5] = 0;
    puVar7[6] = 0;
    puVar7[7] = 0;
    puVar7[8] = 0;
    puVar7[9] = 0;
    *(undefined1 *)(puVar7 + 0x29) = 0;
    *(undefined8 **)(this + 0x10) = puVar7;
  }
  if (param_1 == (__locale_struct *)0x0) {
    lVar9 = *(long *)(this + 0x10);
    *(undefined **)(lVar9 + 0x10) = &DAT_00cb99b6;
    *(undefined8 *)(lVar9 + 0x48) = 0x2c0000002e;
    *(undefined8 *)(lVar9 + 0x18) = 0;
    *(undefined1 *)(lVar9 + 0x20) = 0;
    puVar1 = __num_base::_S_atoms_out;
    lVar5 = 0;
    do {
      *(int *)(lVar9 + 0x50 + lVar5 * 4) = (int)(char)puVar1[lVar5];
      puVar2 = __num_base::_S_atoms_in;
      lVar5 = lVar5 + 1;
    } while (lVar5 != 0x24);
    lVar5 = 0;
    do {
      *(int *)(lVar9 + 0xe0 + lVar5 * 4) = (int)(char)puVar2[lVar5];
      lVar5 = lVar5 + 1;
    } while (lVar5 != 0x1a);
  }
  else {
    uVar3 = __nl_langinfo_l(0x10003,param_1);
    *(undefined4 *)(*(long *)(this + 0x10) + 0x48) = uVar3;
    iVar4 = __nl_langinfo_l(0x10004,param_1);
    lVar9 = *(long *)(this + 0x10);
    *(int *)(lVar9 + 0x4c) = iVar4;
    if (iVar4 == 0) {
      *(undefined8 *)(lVar9 + 0x18) = 0;
      *(undefined **)(lVar9 + 0x10) = &DAT_00cb99b6;
      *(undefined1 *)(lVar9 + 0x20) = 0;
      *(undefined4 *)(lVar9 + 0x4c) = 0x2c;
    }
    else {
      __s = (char *)__nl_langinfo_l(0x10002,param_1);
      sVar6 = strlen(__s);
      if (sVar6 == 0) {
        lVar9 = *(long *)(this + 0x10);
        *(undefined **)(lVar9 + 0x10) = &DAT_00cb99b6;
        *(undefined1 *)(lVar9 + 0x20) = 0;
      }
      else {
                    /* try { // try from 00c74cf2 to 00c74cf6 has its CatchHandler @ 00c74d12 */
        pvVar8 = operator_new__(sVar6 + 1);
        pvVar8 = memcpy(pvVar8,__s,sVar6 + 1);
        lVar9 = *(long *)(this + 0x10);
        *(void **)(lVar9 + 0x10) = pvVar8;
      }
      *(size_t *)(lVar9 + 0x18) = sVar6;
    }
  }
  *(undefined8 *)(lVar9 + 0x30) = 4;
  *(undefined **)(lVar9 + 0x28) = &DAT_00d94fb0;
  *(wchar_t **)(lVar9 + 0x38) = L"false";
  *(undefined8 *)(lVar9 + 0x40) = 5;
  return;
}


// ==== entry=00c74d20 orig=FUN_00c74d20 size=84 name=~numpunct ====

/* std::numpunct<wchar_t>::~numpunct() */

void __thiscall std::numpunct<wchar_t>::~numpunct(numpunct<wchar_t> *this)

{
  long *plVar1;
  
  *(undefined ***)this = &PTR__numpunct_011b6b50;
  plVar1 = *(long **)(this + 0x10);
  if ((plVar1[3] != 0) && ((void *)plVar1[2] != (void *)0x0)) {
    operator_delete__((void *)plVar1[2]);
    plVar1 = *(long **)(this + 0x10);
    if (plVar1 == (long *)0x0) goto LAB_00c74d66;
  }
                    /* try { // try from 00c74d63 to 00c74d65 has its CatchHandler @ 00c74d74 */
  (**(code **)(*plVar1 + 8))();
LAB_00c74d66:
  locale::facet::~facet((facet *)this);
  return;
}


// ==== entry=00c74d80 orig=FUN_00c74d80 size=28 name=~numpunct ====

/* std::numpunct<wchar_t>::~numpunct() */

void __thiscall std::numpunct<wchar_t>::~numpunct(numpunct<wchar_t> *this)

{
                    /* try { // try from 00c74d89 to 00c74d8d has its CatchHandler @ 00c74d9c */
  ~numpunct(this);
  operator_delete(this);
  return;
}


// ==== entry=00c74db0 name=FUN_00c74db0 size=147 ====

undefined4 FUN_00c74db0(undefined8 param_1,undefined8 *param_2,locale *param_3)

{
  undefined4 uVar1;
  codecvt *pcVar2;
  undefined8 uVar3;
  long in_FS_OFFSET;
  locale alStack_38 [8];
  long local_30;
  
  local_30 = *(long *)(in_FS_OFFSET + 0x28);
  pcVar2 = std::use_facet<std::codecvt<char,char,__mbstate_t>>(param_3);
  uVar3 = __nl_langinfo_l(0xe,*(undefined8 *)(pcVar2 + 0x10));
  bind_textdomain_codeset(*param_2,uVar3);
  uVar3 = FUN_00c76ec0();
  std::locale::locale(alStack_38,param_3);
                    /* try { // try from 00c74e12 to 00c74e16 has its CatchHandler @ 00c74e43 */
  uVar1 = FUN_00c770d0(uVar3,*param_2,alStack_38);
  std::locale::~locale(alStack_38);
  if (local_30 == *(long *)(in_FS_OFFSET + 0x28)) {
    return uVar1;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ==== entry=00c74e50 name=FUN_00c74e50 size=19 ====

void FUN_00c74e50(undefined8 param_1,undefined4 param_2)

{
  undefined8 uVar1;
  
  uVar1 = FUN_00c76ec0();
  FUN_00c76c50(uVar1,param_2);
  return;
}


// ==== entry=00c74e70 name=FUN_00c74e70 size=147 ====

undefined4 FUN_00c74e70(undefined8 param_1,undefined8 *param_2,locale *param_3)

{
  undefined4 uVar1;
  codecvt *pcVar2;
  undefined8 uVar3;
  long in_FS_OFFSET;
  locale alStack_38 [8];
  long local_30;
  
  local_30 = *(long *)(in_FS_OFFSET + 0x28);
  pcVar2 = std::use_facet<std::codecvt<wchar_t,char,__mbstate_t>>(param_3);
  uVar3 = __nl_langinfo_l(0xe,*(undefined8 *)(pcVar2 + 0x10));
  bind_textdomain_codeset(*param_2,uVar3);
  uVar3 = FUN_00c76ec0();
  std::locale::locale(alStack_38,param_3);
                    /* try { // try from 00c74ed2 to 00c74ed6 has its CatchHandler @ 00c74f03 */
  uVar1 = FUN_00c770d0(uVar3,*param_2,alStack_38);
  std::locale::~locale(alStack_38);
  if (local_30 == *(long *)(in_FS_OFFSET + 0x28)) {
    return uVar1;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ==== entry=00c74f10 orig=FUN_00c74f10 size=191 name=_M_construct<char*> ====

/* void std::__cxx11::string::_M_construct<char*>(char*, char*, std::forward_iterator_tag) */

void std::__cxx11::string::_M_construct<char*>(ulong *param_1,undefined1 *param_2,long param_3)

{
  undefined1 *__dest;
  ulong __n;
  long in_FS_OFFSET;
  ulong local_28;
  long local_20;
  
  local_20 = *(long *)(in_FS_OFFSET + 0x28);
  if ((param_2 == (undefined1 *)0x0) && (param_3 != 0)) {
                    /* WARNING: Subroutine does not return */
    __throw_logic_error("basic_string::_M_construct null not valid");
  }
  __n = param_3 - (long)param_2;
  local_28 = __n;
  if (__n < 0x10) {
    __dest = (undefined1 *)*param_1;
    if (__n == 1) {
      *__dest = *param_2;
      __dest = (undefined1 *)*param_1;
      goto LAB_00c74f65;
    }
    if (__n == 0) goto LAB_00c74f65;
  }
  else {
    __dest = (undefined1 *)std::__cxx11::string::_M_create(param_1,(ulong)&local_28);
    *param_1 = (ulong)__dest;
    param_1[2] = local_28;
  }
  memcpy(__dest,param_2,__n);
  __dest = (undefined1 *)*param_1;
LAB_00c74f65:
  param_1[1] = local_28;
  __dest[local_28] = 0;
  if (local_20 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


// ==== entry=00c74ff0 name=FUN_00c74ff0 size=326 ====

ulong * FUN_00c74ff0(ulong *param_1,long param_2,int param_3,undefined8 param_4,undefined8 param_5,
                    long *param_6)

{
  long lVar1;
  undefined8 uVar2;
  long lVar3;
  undefined8 uVar4;
  char *__s;
  size_t __n;
  ulong *__dest;
  long in_FS_OFFSET;
  size_t local_38;
  long local_30;
  
  __dest = param_1 + 2;
  local_30 = *(long *)(in_FS_OFFSET + 0x28);
  if ((-1 < param_3) && (param_6[1] != 0)) {
    uVar2 = FUN_00c76ec0();
    lVar3 = FUN_00c76de0(uVar2,param_3);
    if (lVar3 != 0) {
      lVar1 = *param_6;
      uVar2 = *(undefined8 *)(lVar3 + 8);
      uVar4 = __uselocale(*(undefined8 *)(param_2 + 0x10));
      __s = (char *)dgettext(uVar2,lVar1);
      __uselocale(uVar4);
      *param_1 = (ulong)__dest;
      if (__s == (char *)0x0) {
                    /* WARNING: Subroutine does not return */
        std::__throw_logic_error("basic_string::_M_construct null not valid");
      }
      __n = strlen(__s);
      local_38 = __n;
      if (__n < 0x10) {
        if (__n == 1) {
          *(char *)(param_1 + 2) = *__s;
        }
        else if (__n != 0) goto LAB_00c7511e;
      }
      else {
        __dest = (ulong *)std::__cxx11::string::_M_create(param_1,(ulong)&local_38);
        *param_1 = (ulong)__dest;
        param_1[2] = local_38;
LAB_00c7511e:
        memcpy(__dest,__s,__n);
        __dest = (ulong *)*param_1;
      }
      param_1[1] = local_38;
      *(undefined1 *)((long)__dest + local_38) = 0;
      goto LAB_00c75033;
    }
  }
  *param_1 = (ulong)__dest;
  std::__cxx11::string::_M_construct<char*>(param_1,*param_6,param_6[1] + *param_6);
LAB_00c75033:
  if (local_30 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_1;
}


// ==== entry=00c75160 name=FUN_00c75160 size=505 ====

long * FUN_00c75160(long *param_1,codecvt *param_2,int param_3,undefined8 param_4,undefined8 param_5
                   ,long *param_6)

{
  long *plVar1;
  long lVar2;
  long lVar3;
  long lVar4;
  long lVar5;
  code *pcVar6;
  long lVar7;
  undefined1 *puVar8;
  undefined8 *puVar9;
  codecvt *pcVar10;
  int iVar11;
  undefined8 uVar12;
  long lVar13;
  undefined8 uVar14;
  codecvt *pcVar15;
  size_t sVar16;
  undefined1 ***pppuVar17;
  ulong uVar18;
  long in_FS_OFFSET;
  long alStack_a0 [3];
  undefined1 **local_88;
  undefined8 local_80;
  codecvt *local_78;
  codecvt *local_70;
  undefined8 *local_68;
  codecvt *local_60;
  undefined1 local_58 [8];
  undefined1 *local_50;
  undefined8 local_48;
  long local_40;
  
  plVar1 = param_1 + 2;
  pppuVar17 = &local_88;
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  lVar13 = param_6[1];
  if ((param_3 < 0) || (lVar13 == 0)) {
    *param_1 = (long)plVar1;
    alStack_a0[2] = 0xc751aa;
    FUN_00c24870(param_1,*param_6,*param_6 + lVar13 * 4);
  }
  else {
    local_68 = (undefined8 *)CONCAT44(local_68._4_4_,param_3);
    alStack_a0[2] = 0xc751dc;
    local_60 = param_2;
    uVar12 = FUN_00c76ec0();
    alStack_a0[2] = 0xc751e9;
    lVar13 = FUN_00c76de0(uVar12,(ulong)local_68 & 0xffffffff);
    pppuVar17 = &local_88;
    if (lVar13 != 0) {
      local_78 = local_60;
      alStack_a0[2] = 0xc75206;
      local_60 = std::use_facet<std::codecvt<wchar_t,char,__mbstate_t>>((locale *)(lVar13 + 0x10));
      local_48 = 0;
      lVar2 = param_6[1];
      local_68 = &local_48;
      alStack_a0[2] = 0xc7522b;
      iVar11 = (**(code **)(*(long *)local_60 + 0x40))(local_60);
      pcVar10 = local_60;
      puVar9 = local_68;
      lVar3 = *param_6;
      local_88 = &local_50;
      local_70 = local_60;
      lVar7 = -(lVar2 * iVar11 + 0x18U & 0xfffffffffffffff0);
      pcVar15 = (codecvt *)((long)&local_80 + lVar7);
      lVar4 = param_6[1];
      lVar5 = *(long *)local_60;
      local_80 = local_58;
      local_60 = pcVar15;
      *(undefined1 ***)((long)alStack_a0 + lVar7 + 0x10) = local_88;
      *(codecvt **)((long)alStack_a0 + lVar7 + 8) = pcVar15 + lVar2 * iVar11;
      pcVar6 = *(code **)(lVar5 + 0x10);
      *(undefined8 *)((long)alStack_a0 + lVar7) = 0xc75288;
      (*pcVar6)(pcVar10,puVar9,lVar3,lVar3 + lVar4 * 4,local_58,pcVar15);
      *local_50 = 0;
      lVar2 = *(long *)(local_78 + 0x10);
      uVar12 = *(undefined8 *)(lVar13 + 8);
      *(undefined8 *)((long)alStack_a0 + lVar7) = 0xc752a0;
      uVar14 = __uselocale(lVar2);
      pcVar15 = local_60;
      *(undefined8 *)((long)alStack_a0 + lVar7) = 0xc752af;
      pcVar15 = (codecvt *)dgettext(uVar12,pcVar15);
      *(undefined8 *)((long)alStack_a0 + lVar7) = 0xc752ba;
      __uselocale(uVar14);
      pppuVar17 = (undefined1 ***)((long)&local_88 + lVar7);
      if (local_60 != pcVar15) {
        local_60 = local_70;
        local_48 = 0;
        *(undefined8 *)((long)alStack_a0 + lVar7 + 0x10) = 0xc752da;
        sVar16 = strlen((char *)pcVar15);
        pcVar10 = local_60;
        puVar8 = local_80;
        lVar13 = *(long *)local_60;
        lVar2 = -(sVar16 * 4 + 0x1b & 0xfffffffffffffff0);
        pppuVar17 = (undefined1 ***)((long)&local_88 + lVar2 + lVar7);
        *(undefined1 ***)((long)alStack_a0 + lVar2 + lVar7 + 0x10) = local_88;
        puVar9 = local_68;
        uVar18 = (long)&local_80 + lVar2 + lVar7 + 7 & 0xfffffffffffffff0;
        *(ulong *)((long)alStack_a0 + lVar2 + lVar7 + 8) = uVar18 + sVar16 * 4;
        pcVar6 = *(code **)(lVar13 + 0x20);
        *(undefined8 *)((long)alStack_a0 + lVar2 + lVar7) = 0xc7531f;
        (*pcVar6)(pcVar10,puVar9,pcVar15,pcVar15 + sVar16,puVar8,uVar18);
        *param_1 = (long)plVar1;
        *(undefined8 *)((long)alStack_a0 + lVar2 + lVar7 + 0x10) = 0xc75333;
        FUN_00c24870(param_1,uVar18,local_50);
        goto LAB_00c751aa;
      }
    }
    *param_1 = (long)plVar1;
    lVar13 = param_6[1];
    lVar2 = *param_6;
    *(undefined8 *)((long)pppuVar17 + -8) = 0xc75358;
    FUN_00c24870(param_1,lVar2,lVar2 + lVar13 * 4);
  }
LAB_00c751aa:
  if (local_40 == *(long *)(in_FS_OFFSET + 0x28)) {
    return param_1;
  }
                    /* WARNING: Subroutine does not return */
  *(undefined **)((long)pppuVar17 + -8) = &UNK_00c75362;
  __stack_chk_fail();
}


// ==== entry=00c75370 orig=FUN_00c75370 size=35 name=_M_put ====

/* std::__timepunct<char>::_M_put(char*, unsigned long, char const*, tm const*) const */

void __thiscall
std::__timepunct<char>::_M_put
          (__timepunct<char> *this,char *param_1,ulong param_2,char *param_3,tm *param_4)

{
  long lVar1;
  
  lVar1 = __strftime_l(param_1,param_2,param_3,param_4,*(undefined8 *)(this + 0x18));
  if (lVar1 == 0) {
    *param_1 = '\0';
  }
  return;
}


// ==== entry=00c753a0 orig=FUN_00c753a0 size=2361 name=_M_initialize_timepunct ====

/* std::__timepunct<char>::_M_initialize_timepunct(__locale_struct*) */

void __thiscall
std::__timepunct<char>::_M_initialize_timepunct(__timepunct<char> *this,__locale_struct *param_1)

{
  long lVar1;
  long lVar2;
  undefined8 uVar3;
  undefined8 *puVar4;
  __locale_struct *local_20 [2];
  
  local_20[0] = param_1;
  if (*(long *)(this + 0x10) == 0) {
    puVar4 = operator_new(400);
    *(undefined4 *)(puVar4 + 1) = 0;
    puVar4[2] = 0;
    *puVar4 = &PTR____timepunct_cache_011b5678;
    puVar4[3] = 0;
    puVar4[4] = 0;
    puVar4[5] = 0;
    puVar4[6] = 0;
    puVar4[7] = 0;
    puVar4[8] = 0;
    puVar4[9] = 0;
    puVar4[10] = 0;
    puVar4[0xb] = 0;
    puVar4[0xc] = 0;
    puVar4[0xd] = 0;
    puVar4[0xe] = 0;
    puVar4[0xf] = 0;
    puVar4[0x10] = 0;
    puVar4[0x11] = 0;
    puVar4[0x12] = 0;
    puVar4[0x13] = 0;
    puVar4[0x14] = 0;
    puVar4[0x15] = 0;
    puVar4[0x16] = 0;
    puVar4[0x17] = 0;
    puVar4[0x18] = 0;
    puVar4[0x19] = 0;
    puVar4[0x1a] = 0;
    puVar4[0x1b] = 0;
    puVar4[0x1c] = 0;
    puVar4[0x1d] = 0;
    puVar4[0x1e] = 0;
    puVar4[0x1f] = 0;
    puVar4[0x20] = 0;
    puVar4[0x21] = 0;
    puVar4[0x22] = 0;
    puVar4[0x23] = 0;
    puVar4[0x24] = 0;
    puVar4[0x25] = 0;
    puVar4[0x26] = 0;
    puVar4[0x27] = 0;
    puVar4[0x28] = 0;
    puVar4[0x29] = 0;
    puVar4[0x2a] = 0;
    puVar4[0x2b] = 0;
    puVar4[0x2c] = 0;
    puVar4[0x2d] = 0;
    puVar4[0x2e] = 0;
    puVar4[0x2f] = 0;
    puVar4[0x30] = 0;
    *(undefined1 *)(puVar4 + 0x31) = 0;
    *(undefined8 **)(this + 0x10) = puVar4;
  }
  if (local_20[0] != (__locale_struct *)0x0) {
    uVar3 = locale::facet::_S_clone_c_locale(local_20);
    lVar1 = *(long *)(this + 0x10);
    *(undefined8 *)(this + 0x18) = uVar3;
    uVar3 = __nl_langinfo_l(0x20029,local_20[0]);
    *(undefined8 *)(lVar1 + 0x10) = uVar3;
    lVar1 = *(long *)(this + 0x10);
    uVar3 = __nl_langinfo_l(0x2002e,local_20[0]);
    *(undefined8 *)(lVar1 + 0x18) = uVar3;
    lVar1 = *(long *)(this + 0x10);
    uVar3 = __nl_langinfo_l(0x2002a,local_20[0]);
    *(undefined8 *)(lVar1 + 0x20) = uVar3;
    lVar1 = *(long *)(this + 0x10);
    uVar3 = __nl_langinfo_l(0x20031,local_20[0]);
    *(undefined8 *)(lVar1 + 0x28) = uVar3;
    lVar1 = *(long *)(this + 0x10);
    uVar3 = __nl_langinfo_l(0x20028,local_20[0]);
    *(undefined8 *)(lVar1 + 0x30) = uVar3;
    lVar1 = *(long *)(this + 0x10);
    uVar3 = __nl_langinfo_l(0x20030,local_20[0]);
    *(undefined8 *)(lVar1 + 0x38) = uVar3;
    lVar1 = *(long *)(this + 0x10);
    uVar3 = __nl_langinfo_l(0x20026,local_20[0]);
    *(undefined8 *)(lVar1 + 0x40) = uVar3;
    lVar1 = *(long *)(this + 0x10);
    uVar3 = __nl_langinfo_l(0x20027,local_20[0]);
    *(undefined8 *)(lVar1 + 0x48) = uVar3;
    lVar1 = *(long *)(this + 0x10);
    uVar3 = __nl_langinfo_l(0x2002b,local_20[0]);
    *(undefined8 *)(lVar1 + 0x50) = uVar3;
    lVar1 = *(long *)(this + 0x10);
    uVar3 = __nl_langinfo_l(0x20007,local_20[0]);
    *(undefined8 *)(lVar1 + 0x58) = uVar3;
    lVar1 = *(long *)(this + 0x10);
    uVar3 = __nl_langinfo_l(0x20008,local_20[0]);
    *(undefined8 *)(lVar1 + 0x60) = uVar3;
    lVar1 = *(long *)(this + 0x10);
    uVar3 = __nl_langinfo_l(0x20009,local_20[0]);
    *(undefined8 *)(lVar1 + 0x68) = uVar3;
    lVar1 = *(long *)(this + 0x10);
    uVar3 = __nl_langinfo_l(0x2000a,local_20[0]);
    *(undefined8 *)(lVar1 + 0x70) = uVar3;
    lVar1 = *(long *)(this + 0x10);
    uVar3 = __nl_langinfo_l(0x2000b,local_20[0]);
    *(undefined8 *)(lVar1 + 0x78) = uVar3;
    lVar1 = *(long *)(this + 0x10);
    uVar3 = __nl_langinfo_l(0x2000c,local_20[0]);
    *(undefined8 *)(lVar1 + 0x80) = uVar3;
    lVar1 = *(long *)(this + 0x10);
    uVar3 = __nl_langinfo_l(0x2000d,local_20[0]);
    *(undefined8 *)(lVar1 + 0x88) = uVar3;
    lVar1 = *(long *)(this + 0x10);
    uVar3 = __nl_langinfo_l(0x20000,local_20[0]);
    *(undefined8 *)(lVar1 + 0x90) = uVar3;
    lVar1 = *(long *)(this + 0x10);
    uVar3 = __nl_langinfo_l(0x20001,local_20[0]);
    *(undefined8 *)(lVar1 + 0x98) = uVar3;
    lVar1 = *(long *)(this + 0x10);
    uVar3 = __nl_langinfo_l(0x20002,local_20[0]);
    *(undefined8 *)(lVar1 + 0xa0) = uVar3;
    lVar1 = *(long *)(this + 0x10);
    uVar3 = __nl_langinfo_l(0x20003,local_20[0]);
    *(undefined8 *)(lVar1 + 0xa8) = uVar3;
    lVar1 = *(long *)(this + 0x10);
    uVar3 = __nl_langinfo_l(0x20004,local_20[0]);
    *(undefined8 *)(lVar1 + 0xb0) = uVar3;
    lVar1 = *(long *)(this + 0x10);
    uVar3 = __nl_langinfo_l(0x20005,local_20[0]);
    *(undefined8 *)(lVar1 + 0xb8) = uVar3;
    lVar1 = *(long *)(this + 0x10);
    uVar3 = __nl_langinfo_l(0x20006,local_20[0]);
    *(undefined8 *)(lVar1 + 0xc0) = uVar3;
    lVar1 = *(long *)(this + 0x10);
    uVar3 = __nl_langinfo_l(0x2001a,local_20[0]);
    *(undefined8 *)(lVar1 + 200) = uVar3;
    lVar1 = *(long *)(this + 0x10);
    uVar3 = __nl_langinfo_l(0x2001b,local_20[0]);
    *(undefined8 *)(lVar1 + 0xd0) = uVar3;
    lVar1 = *(long *)(this + 0x10);
    uVar3 = __nl_langinfo_l(0x2001c,local_20[0]);
    *(undefined8 *)(lVar1 + 0xd8) = uVar3;
    lVar1 = *(long *)(this + 0x10);
    uVar3 = __nl_langinfo_l(0x2001d,local_20[0]);
    *(undefined8 *)(lVar1 + 0xe0) = uVar3;
    lVar1 = *(long *)(this + 0x10);
    uVar3 = __nl_langinfo_l(0x2001e,local_20[0]);
    *(undefined8 *)(lVar1 + 0xe8) = uVar3;
    lVar1 = *(long *)(this + 0x10);
    uVar3 = __nl_langinfo_l(0x2001f,local_20[0]);
    *(undefined8 *)(lVar1 + 0xf0) = uVar3;
    lVar1 = *(long *)(this + 0x10);
    uVar3 = __nl_langinfo_l(0x20020,local_20[0]);
    *(undefined8 *)(lVar1 + 0xf8) = uVar3;
    lVar1 = *(long *)(this + 0x10);
    uVar3 = __nl_langinfo_l(0x20021,local_20[0]);
    *(undefined8 *)(lVar1 + 0x100) = uVar3;
    lVar1 = *(long *)(this + 0x10);
    uVar3 = __nl_langinfo_l(0x20022,local_20[0]);
    *(undefined8 *)(lVar1 + 0x108) = uVar3;
    lVar1 = *(long *)(this + 0x10);
    uVar3 = __nl_langinfo_l(0x20023,local_20[0]);
    *(undefined8 *)(lVar1 + 0x110) = uVar3;
    lVar1 = *(long *)(this + 0x10);
    uVar3 = __nl_langinfo_l(0x20024,local_20[0]);
    *(undefined8 *)(lVar1 + 0x118) = uVar3;
    lVar1 = *(long *)(this + 0x10);
    uVar3 = __nl_langinfo_l(0x20025,local_20[0]);
    *(undefined8 *)(lVar1 + 0x120) = uVar3;
    lVar1 = *(long *)(this + 0x10);
    uVar3 = __nl_langinfo_l(0x2000e,local_20[0]);
    *(undefined8 *)(lVar1 + 0x128) = uVar3;
    lVar1 = *(long *)(this + 0x10);
    uVar3 = __nl_langinfo_l(0x2000f,local_20[0]);
    *(undefined8 *)(lVar1 + 0x130) = uVar3;
    lVar1 = *(long *)(this + 0x10);
    uVar3 = __nl_langinfo_l(0x20010,local_20[0]);
    *(undefined8 *)(lVar1 + 0x138) = uVar3;
    lVar1 = *(long *)(this + 0x10);
    uVar3 = __nl_langinfo_l(0x20011,local_20[0]);
    *(undefined8 *)(lVar1 + 0x140) = uVar3;
    lVar1 = *(long *)(this + 0x10);
    uVar3 = __nl_langinfo_l(0x20012,local_20[0]);
    *(undefined8 *)(lVar1 + 0x148) = uVar3;
    lVar1 = *(long *)(this + 0x10);
    uVar3 = __nl_langinfo_l(0x20013,local_20[0]);
    *(undefined8 *)(lVar1 + 0x150) = uVar3;
    lVar1 = *(long *)(this + 0x10);
    uVar3 = __nl_langinfo_l(0x20014,local_20[0]);
    *(undefined8 *)(lVar1 + 0x158) = uVar3;
    lVar1 = *(long *)(this + 0x10);
    uVar3 = __nl_langinfo_l(0x20015,local_20[0]);
    *(undefined8 *)(lVar1 + 0x160) = uVar3;
    lVar1 = *(long *)(this + 0x10);
    uVar3 = __nl_langinfo_l(0x20016,local_20[0]);
    *(undefined8 *)(lVar1 + 0x168) = uVar3;
    lVar1 = *(long *)(this + 0x10);
    uVar3 = __nl_langinfo_l(0x20017,local_20[0]);
    *(undefined8 *)(lVar1 + 0x170) = uVar3;
    lVar1 = *(long *)(this + 0x10);
    uVar3 = __nl_langinfo_l(0x20018,local_20[0]);
    lVar2 = *(long *)(this + 0x10);
    *(undefined8 *)(lVar1 + 0x178) = uVar3;
    uVar3 = __nl_langinfo_l(0x20019,local_20[0]);
    *(undefined8 *)(lVar2 + 0x180) = uVar3;
    return;
  }
  uVar3 = locale::facet::_S_get_c_locale();
  *(undefined8 *)(this + 0x18) = uVar3;
  lVar1 = *(long *)(this + 0x10);
  *(undefined **)(lVar1 + 0x40) = &DAT_00c8cf88;
  *(undefined **)(lVar1 + 0x48) = &DAT_00ca0a3c;
  *(char **)(lVar1 + 0x58) = "Sunday";
  *(char **)(lVar1 + 0x60) = "Monday";
  *(char **)(lVar1 + 0x68) = "Tuesday";
  *(char **)(lVar1 + 0x70) = "Wednesday";
  *(char **)(lVar1 + 0x78) = "Thursday";
  *(char **)(lVar1 + 0x10) = "%m/%d/%y";
  *(char **)(lVar1 + 0x18) = "%m/%d/%y";
  *(char **)(lVar1 + 0x80) = "Friday";
  *(undefined **)(lVar1 + 0x20) = &DAT_00c8ce9b;
  *(undefined **)(lVar1 + 0x28) = &DAT_00c8ce9b;
  *(undefined **)(lVar1 + 0x90) = &DAT_00c8cb0b;
  *(undefined **)(lVar1 + 0x30) = &DAT_00cb99b6;
  *(undefined **)(lVar1 + 0x38) = &DAT_00cb99b6;
  *(undefined **)(lVar1 + 0x50) = &DAT_00cb99b6;
  *(undefined **)(lVar1 + 0xa0) = &DAT_00c8cb13;
  *(char **)(lVar1 + 0x88) = "Saturday";
  *(undefined **)(lVar1 + 0xb0) = &DAT_00c8cb1b;
  *(undefined **)(lVar1 + 0x98) = &DAT_00c8cb0f;
  *(undefined **)(lVar1 + 0xc0) = &DAT_00c8cb23;
  *(undefined **)(lVar1 + 0xa8) = &DAT_00c8cb17;
  *(char **)(lVar1 + 0xd0) = "February";
  *(undefined **)(lVar1 + 0xb8) = &DAT_00c8cb1f;
  *(char **)(lVar1 + 0xe0) = "April";
  *(char **)(lVar1 + 200) = "January";
  *(undefined **)(lVar1 + 0xf0) = &DAT_00c8ca70;
  *(char **)(lVar1 + 0xd8) = "March";
  *(undefined **)(lVar1 + 0xf8) = &DAT_00c8ca75;
  *(undefined **)(lVar1 + 0xe8) = &DAT_00c8ca6c;
  *(char **)(lVar1 + 0x100) = "August";
  *(char **)(lVar1 + 0x108) = "September";
  *(undefined **)(lVar1 + 0x148) = &DAT_00c8ca6c;
  *(char **)(lVar1 + 0x110) = "October";
  *(undefined **)(lVar1 + 0x150) = &DAT_00c8cab5;
  *(char **)(lVar1 + 0x118) = "November";
  *(undefined **)(lVar1 + 0x158) = &DAT_00c8cab9;
  *(char **)(lVar1 + 0x120) = "December";
  *(undefined **)(lVar1 + 0x160) = &DAT_00c8cabd;
  *(undefined **)(lVar1 + 0x128) = &DAT_00c8caa5;
  *(undefined **)(lVar1 + 0x168) = &DAT_00d98c54;
  *(undefined **)(lVar1 + 0x130) = &DAT_00c8caa9;
  *(undefined **)(lVar1 + 0x170) = &DAT_00c8cac6;
  *(undefined **)(lVar1 + 0x138) = &DAT_00c8caad;
  *(undefined **)(lVar1 + 0x178) = &DAT_00c8caca;
  *(undefined **)(lVar1 + 0x140) = &DAT_00c8cab1;
  *(undefined **)(lVar1 + 0x180) = &DAT_00c8cace;
  return;
}


// ==== entry=00c75cf0 orig=FUN_00c75cf0 size=38 name=_M_put ====

/* std::__timepunct<wchar_t>::_M_put(wchar_t*, unsigned long, wchar_t const*, tm const*) const */

void __thiscall
std::__timepunct<wchar_t>::_M_put
          (__timepunct<wchar_t> *this,wchar_t *param_1,ulong param_2,wchar_t *param_3,tm *param_4)

{
  long lVar1;
  
  lVar1 = __wcsftime_l(param_1,param_2,param_3,param_4,*(undefined8 *)(this + 0x18));
  if (lVar1 == 0) {
    *param_1 = L'\0';
  }
  return;
}


// ==== entry=00c75d20 orig=FUN_00c75d20 size=2358 name=_M_initialize_timepunct ====

/* std::__timepunct<wchar_t>::_M_initialize_timepunct(__locale_struct*) */

void __thiscall
std::__timepunct<wchar_t>::_M_initialize_timepunct
          (__timepunct<wchar_t> *this,__locale_struct *param_1)

{
  long lVar1;
  undefined8 uVar2;
  undefined8 *puVar3;
  __locale_struct *local_10;
  
  local_10 = param_1;
  if (*(long *)(this + 0x10) == 0) {
    puVar3 = operator_new(400);
    *(undefined4 *)(puVar3 + 1) = 0;
    puVar3[2] = 0;
    *puVar3 = &PTR____timepunct_cache_011b6cb8;
    puVar3[3] = 0;
    puVar3[4] = 0;
    puVar3[5] = 0;
    puVar3[6] = 0;
    puVar3[7] = 0;
    puVar3[8] = 0;
    puVar3[9] = 0;
    puVar3[10] = 0;
    puVar3[0xb] = 0;
    puVar3[0xc] = 0;
    puVar3[0xd] = 0;
    puVar3[0xe] = 0;
    puVar3[0xf] = 0;
    puVar3[0x10] = 0;
    puVar3[0x11] = 0;
    puVar3[0x12] = 0;
    puVar3[0x13] = 0;
    puVar3[0x14] = 0;
    puVar3[0x15] = 0;
    puVar3[0x16] = 0;
    puVar3[0x17] = 0;
    puVar3[0x18] = 0;
    puVar3[0x19] = 0;
    puVar3[0x1a] = 0;
    puVar3[0x1b] = 0;
    puVar3[0x1c] = 0;
    puVar3[0x1d] = 0;
    puVar3[0x1e] = 0;
    puVar3[0x1f] = 0;
    puVar3[0x20] = 0;
    puVar3[0x21] = 0;
    puVar3[0x22] = 0;
    puVar3[0x23] = 0;
    puVar3[0x24] = 0;
    puVar3[0x25] = 0;
    puVar3[0x26] = 0;
    puVar3[0x27] = 0;
    puVar3[0x28] = 0;
    puVar3[0x29] = 0;
    puVar3[0x2a] = 0;
    puVar3[0x2b] = 0;
    puVar3[0x2c] = 0;
    puVar3[0x2d] = 0;
    puVar3[0x2e] = 0;
    puVar3[0x2f] = 0;
    puVar3[0x30] = 0;
    *(undefined1 *)(puVar3 + 0x31) = 0;
    *(undefined8 **)(this + 0x10) = puVar3;
  }
  if (local_10 != (__locale_struct *)0x0) {
    uVar2 = locale::facet::_S_clone_c_locale(&local_10);
    *(undefined8 *)(this + 0x18) = uVar2;
    uVar2 = __nl_langinfo_l(0x2005d,local_10);
    *(undefined8 *)(*(long *)(this + 0x10) + 0x10) = uVar2;
    uVar2 = __nl_langinfo_l(0x20061,local_10);
    *(undefined8 *)(*(long *)(this + 0x10) + 0x18) = uVar2;
    uVar2 = __nl_langinfo_l(0x2005e,local_10);
    *(undefined8 *)(*(long *)(this + 0x10) + 0x20) = uVar2;
    uVar2 = __nl_langinfo_l(0x20064,local_10);
    *(undefined8 *)(*(long *)(this + 0x10) + 0x28) = uVar2;
    uVar2 = __nl_langinfo_l(0x2005c,local_10);
    *(undefined8 *)(*(long *)(this + 0x10) + 0x30) = uVar2;
    uVar2 = __nl_langinfo_l(0x20063,local_10);
    *(undefined8 *)(*(long *)(this + 0x10) + 0x38) = uVar2;
    uVar2 = __nl_langinfo_l(0x2005a,local_10);
    *(undefined8 *)(*(long *)(this + 0x10) + 0x40) = uVar2;
    uVar2 = __nl_langinfo_l(0x2005b,local_10);
    *(undefined8 *)(*(long *)(this + 0x10) + 0x48) = uVar2;
    uVar2 = __nl_langinfo_l(0x2005f,local_10);
    *(undefined8 *)(*(long *)(this + 0x10) + 0x50) = uVar2;
    uVar2 = __nl_langinfo_l(0x2003b,local_10);
    *(undefined8 *)(*(long *)(this + 0x10) + 0x58) = uVar2;
    uVar2 = __nl_langinfo_l(0x2003c,local_10);
    *(undefined8 *)(*(long *)(this + 0x10) + 0x60) = uVar2;
    uVar2 = __nl_langinfo_l(0x2003d,local_10);
    *(undefined8 *)(*(long *)(this + 0x10) + 0x68) = uVar2;
    uVar2 = __nl_langinfo_l(0x2003e,local_10);
    *(undefined8 *)(*(long *)(this + 0x10) + 0x70) = uVar2;
    uVar2 = __nl_langinfo_l(0x2003f,local_10);
    *(undefined8 *)(*(long *)(this + 0x10) + 0x78) = uVar2;
    uVar2 = __nl_langinfo_l(0x20040,local_10);
    *(undefined8 *)(*(long *)(this + 0x10) + 0x80) = uVar2;
    uVar2 = __nl_langinfo_l(0x20041,local_10);
    *(undefined8 *)(*(long *)(this + 0x10) + 0x88) = uVar2;
    uVar2 = __nl_langinfo_l(0x20034,local_10);
    *(undefined8 *)(*(long *)(this + 0x10) + 0x90) = uVar2;
    uVar2 = __nl_langinfo_l(0x20035,local_10);
    *(undefined8 *)(*(long *)(this + 0x10) + 0x98) = uVar2;
    uVar2 = __nl_langinfo_l(0x20036,local_10);
    *(undefined8 *)(*(long *)(this + 0x10) + 0xa0) = uVar2;
    uVar2 = __nl_langinfo_l(0x20037,local_10);
    *(undefined8 *)(*(long *)(this + 0x10) + 0xa8) = uVar2;
    uVar2 = __nl_langinfo_l(0x20038,local_10);
    *(undefined8 *)(*(long *)(this + 0x10) + 0xb0) = uVar2;
    uVar2 = __nl_langinfo_l(0x20039,local_10);
    *(undefined8 *)(*(long *)(this + 0x10) + 0xb8) = uVar2;
    uVar2 = __nl_langinfo_l(0x2003a,local_10);
    *(undefined8 *)(*(long *)(this + 0x10) + 0xc0) = uVar2;
    uVar2 = __nl_langinfo_l(0x2004e,local_10);
    *(undefined8 *)(*(long *)(this + 0x10) + 200) = uVar2;
    uVar2 = __nl_langinfo_l(0x2004f,local_10);
    *(undefined8 *)(*(long *)(this + 0x10) + 0xd0) = uVar2;
    uVar2 = __nl_langinfo_l(0x20050,local_10);
    *(undefined8 *)(*(long *)(this + 0x10) + 0xd8) = uVar2;
    uVar2 = __nl_langinfo_l(0x20051,local_10);
    *(undefined8 *)(*(long *)(this + 0x10) + 0xe0) = uVar2;
    uVar2 = __nl_langinfo_l(0x20052,local_10);
    *(undefined8 *)(*(long *)(this + 0x10) + 0xe8) = uVar2;
    uVar2 = __nl_langinfo_l(0x20053,local_10);
    *(undefined8 *)(*(long *)(this + 0x10) + 0xf0) = uVar2;
    uVar2 = __nl_langinfo_l(0x20054,local_10);
    *(undefined8 *)(*(long *)(this + 0x10) + 0xf8) = uVar2;
    uVar2 = __nl_langinfo_l(0x20055,local_10);
    *(undefined8 *)(*(long *)(this + 0x10) + 0x100) = uVar2;
    uVar2 = __nl_langinfo_l(0x20056,local_10);
    *(undefined8 *)(*(long *)(this + 0x10) + 0x108) = uVar2;
    uVar2 = __nl_langinfo_l(0x20057,local_10);
    *(undefined8 *)(*(long *)(this + 0x10) + 0x110) = uVar2;
    uVar2 = __nl_langinfo_l(0x20058,local_10);
    *(undefined8 *)(*(long *)(this + 0x10) + 0x118) = uVar2;
    uVar2 = __nl_langinfo_l(0x20059,local_10);
    *(undefined8 *)(*(long *)(this + 0x10) + 0x120) = uVar2;
    uVar2 = __nl_langinfo_l(0x20042,local_10);
    *(undefined8 *)(*(long *)(this + 0x10) + 0x128) = uVar2;
    uVar2 = __nl_langinfo_l(0x20043,local_10);
    *(undefined8 *)(*(long *)(this + 0x10) + 0x130) = uVar2;
    uVar2 = __nl_langinfo_l(0x20044,local_10);
    *(undefined8 *)(*(long *)(this + 0x10) + 0x138) = uVar2;
    uVar2 = __nl_langinfo_l(0x20045,local_10);
    *(undefined8 *)(*(long *)(this + 0x10) + 0x140) = uVar2;
    uVar2 = __nl_langinfo_l(0x20046,local_10);
    *(undefined8 *)(*(long *)(this + 0x10) + 0x148) = uVar2;
    uVar2 = __nl_langinfo_l(0x20047,local_10);
    *(undefined8 *)(*(long *)(this + 0x10) + 0x150) = uVar2;
    uVar2 = __nl_langinfo_l(0x20048,local_10);
    *(undefined8 *)(*(long *)(this + 0x10) + 0x158) = uVar2;
    uVar2 = __nl_langinfo_l(0x20049,local_10);
    *(undefined8 *)(*(long *)(this + 0x10) + 0x160) = uVar2;
    uVar2 = __nl_langinfo_l(0x2004a,local_10);
    *(undefined8 *)(*(long *)(this + 0x10) + 0x168) = uVar2;
    uVar2 = __nl_langinfo_l(0x2004b,local_10);
    *(undefined8 *)(*(long *)(this + 0x10) + 0x170) = uVar2;
    uVar2 = __nl_langinfo_l(0x2004c,local_10);
    *(undefined8 *)(*(long *)(this + 0x10) + 0x178) = uVar2;
    uVar2 = __nl_langinfo_l(0x2004d,local_10);
    *(undefined8 *)(*(long *)(this + 0x10) + 0x180) = uVar2;
    return;
  }
  uVar2 = locale::facet::_S_get_c_locale();
  *(undefined8 *)(this + 0x18) = uVar2;
  lVar1 = *(long *)(this + 0x10);
  *(undefined **)(lVar1 + 0x40) = &DAT_00d98e20;
  *(undefined **)(lVar1 + 0x48) = &DAT_00d98e2c;
  *(wchar_t **)(lVar1 + 0x58) = L"Sunday";
  *(wchar_t **)(lVar1 + 0x60) = L"Monday";
  *(wchar_t **)(lVar1 + 0x68) = L"Tuesday";
  *(wchar_t **)(lVar1 + 0x70) = L"Wednesday";
  *(wchar_t **)(lVar1 + 0x78) = L"Thursday";
  *(wchar_t **)(lVar1 + 0x80) = L"Friday";
  *(wchar_t **)(lVar1 + 0x88) = L"Saturday";
  *(undefined **)(lVar1 + 0x90) = &DAT_00d98e8c;
  *(undefined **)(lVar1 + 0x98) = &DAT_00d98e9c;
  *(undefined **)(lVar1 + 0xa0) = &DAT_00d98eac;
  *(undefined **)(lVar1 + 0xa8) = &DAT_00d98ebc;
  *(undefined **)(lVar1 + 0xb0) = &DAT_00d98ecc;
  *(undefined **)(lVar1 + 0xb8) = &DAT_00d98edc;
  *(undefined **)(lVar1 + 0xc0) = &DAT_00d98eec;
  *(wchar_t **)(lVar1 + 200) = L"January";
  *(wchar_t **)(lVar1 + 0xd0) = L"February";
  *(wchar_t **)(lVar1 + 0xd8) = L"March";
  *(undefined **)(lVar1 + 0x10) = &DAT_00d98c58;
  *(undefined **)(lVar1 + 0x18) = &DAT_00d98c58;
  *(wchar_t **)(lVar1 + 0xe0) = L"April";
  *(undefined **)(lVar1 + 0x20) = &DAT_00d98c80;
  *(undefined **)(lVar1 + 0x28) = &DAT_00d98c80;
  *(undefined **)(lVar1 + 0xf0) = &DAT_00d98f3c;
  *(undefined **)(lVar1 + 0x30) = &DAT_00d94f28;
  *(undefined **)(lVar1 + 0x38) = &DAT_00d94f28;
  *(undefined **)(lVar1 + 0x50) = &DAT_00d94f28;
  *(undefined **)(lVar1 + 0xf8) = &DAT_00d98f50;
  *(undefined **)(lVar1 + 0xe8) = &DAT_00d98f2c;
  *(wchar_t **)(lVar1 + 0x100) = L"August";
  *(wchar_t **)(lVar1 + 0x108) = L"September";
  *(wchar_t **)(lVar1 + 0x110) = L"October";
  *(wchar_t **)(lVar1 + 0x118) = L"November";
  *(wchar_t **)(lVar1 + 0x120) = L"December";
  *(undefined **)(lVar1 + 0x128) = &DAT_00d98f80;
  *(undefined **)(lVar1 + 0x130) = &DAT_00d98f90;
  *(undefined **)(lVar1 + 0x138) = &DAT_00d98fa0;
  *(undefined **)(lVar1 + 0x140) = &DAT_00d98fb0;
  *(undefined **)(lVar1 + 0x150) = &DAT_00d98fc0;
  *(undefined **)(lVar1 + 0x158) = &DAT_00d98fd0;
  *(undefined **)(lVar1 + 0x160) = &DAT_00d98fe0;
  *(undefined **)(lVar1 + 0x168) = &DAT_00d98ff0;
  *(undefined **)(lVar1 + 0x170) = &DAT_00d99000;
  *(undefined **)(lVar1 + 0x178) = &DAT_00d99010;
  *(undefined **)(lVar1 + 0x148) = &DAT_00d98f2c;
  *(undefined **)(lVar1 + 0x180) = &DAT_00d99020;
  return;
}


// ==== entry=00c76660 orig=FUN_00c76660 size=17 name=do_in ====

/* std::codecvt<char, char, __mbstate_t>::do_in(__mbstate_t&, char const*, char const*, char
   const*&, char*, char*, char*&) const */

undefined8 __thiscall
std::codecvt<char,char,__mbstate_t>::do_in
          (codecvt<char,char,__mbstate_t> *this,__mbstate_t *param_1,char *param_2,char *param_3,
          char **param_4,char *param_5,char *param_6,char **param_7)

{
  *param_4 = param_2;
  *param_7 = param_5;
  return 3;
}


// ==== entry=00c76680 orig=FUN_00c76680 size=9 name=do_unshift ====

/* std::codecvt<char, char, __mbstate_t>::do_unshift(__mbstate_t&, char*, char*, char*&) const */

undefined8 __thiscall
std::codecvt<char,char,__mbstate_t>::do_unshift
          (codecvt<char,char,__mbstate_t> *this,__mbstate_t *param_1,char *param_2,char *param_3,
          char **param_4)

{
  *param_4 = param_2;
  return 3;
}


// ==== entry=00c76690 orig=FUN_00c76690 size=6 name=do_max_length ====

/* std::codecvt<char, char, __mbstate_t>::do_max_length() const */

undefined8 std::codecvt<char,char,__mbstate_t>::do_max_length(void)

{
  return 1;
}


// ==== entry=00c766a0 orig=FUN_00c766a0 size=6 name=do_always_noconv ====

/* std::codecvt<char, char, __mbstate_t>::do_always_noconv() const */

undefined8 std::codecvt<char,char,__mbstate_t>::do_always_noconv(void)

{
  return 1;
}


// ==== entry=00c766b0 orig=FUN_00c766b0 size=14 name=do_length ====

/* std::codecvt<char, char, __mbstate_t>::do_length(__mbstate_t&, char const*, char const*, unsigned
   long) const */

ulong __thiscall
std::codecvt<char,char,__mbstate_t>::do_length
          (codecvt<char,char,__mbstate_t> *this,__mbstate_t *param_1,char *param_2,char *param_3,
          ulong param_4)

{
  if ((ulong)((long)param_3 - (long)param_2) <= param_4) {
    param_4 = (long)param_3 - (long)param_2;
  }
  return param_4;
}


// ==== entry=00c766c0 orig=FUN_00c766c0 size=3 name=do_always_noconv ====

/* std::codecvt<wchar_t, char, __mbstate_t>::do_always_noconv() const */

undefined8 std::codecvt<wchar_t,char,__mbstate_t>::do_always_noconv(void)

{
  return 0;
}


// ==== entry=00c766d0 orig=FUN_00c766d0 size=61 name=~codecvt ====

/* std::codecvt<char, char, __mbstate_t>::~codecvt() */

void __thiscall std::codecvt<char,char,__mbstate_t>::~codecvt(codecvt<char,char,__mbstate_t> *this)

{
  *(undefined ***)this = &PTR__codecvt_011b7d30;
                    /* try { // try from 00c766ec to 00c766f0 has its CatchHandler @ 00c7670d */
  locale::facet::_S_destroy_c_locale((__locale_struct **)(this + 0x10));
  *(undefined **)this = &DAT_011b57c0;
  locale::facet::~facet((facet *)this);
  return;
}


// ==== entry=00c76720 orig=FUN_00c76720 size=28 name=~codecvt ====

/* std::codecvt<char, char, __mbstate_t>::~codecvt() */

void __thiscall std::codecvt<char,char,__mbstate_t>::~codecvt(codecvt<char,char,__mbstate_t> *this)

{
                    /* try { // try from 00c76729 to 00c7672d has its CatchHandler @ 00c7673c */
  ~codecvt(this);
  operator_delete(this);
  return;
}


// ==== entry=00c76750 orig=FUN_00c76750 size=61 name=~codecvt ====

/* std::codecvt<wchar_t, char, __mbstate_t>::~codecvt() */

void __thiscall
std::codecvt<wchar_t,char,__mbstate_t>::~codecvt(codecvt<wchar_t,char,__mbstate_t> *this)

{
  *(undefined ***)this = &PTR__codecvt_011b7d88;
                    /* try { // try from 00c7676c to 00c76770 has its CatchHandler @ 00c7678d */
  locale::facet::_S_destroy_c_locale((__locale_struct **)(this + 0x10));
  *(undefined **)this = &DAT_011b6e00;
  locale::facet::~facet((facet *)this);
  return;
}


// ==== entry=00c767a0 orig=FUN_00c767a0 size=28 name=~codecvt ====

/* std::codecvt<wchar_t, char, __mbstate_t>::~codecvt() */

void __thiscall
std::codecvt<wchar_t,char,__mbstate_t>::~codecvt(codecvt<wchar_t,char,__mbstate_t> *this)

{
                    /* try { // try from 00c767a9 to 00c767ad has its CatchHandler @ 00c767bc */
  ~codecvt(this);
  operator_delete(this);
  return;
}


// ==== entry=00c767d0 orig=FUN_00c767d0 size=50 name=codecvt ====

/* std::codecvt<char, char, __mbstate_t>::codecvt(unsigned long) */

void __thiscall
std::codecvt<char,char,__mbstate_t>::codecvt(codecvt<char,char,__mbstate_t> *this,ulong param_1)

{
  undefined8 uVar1;
  
  *(uint *)(this + 8) = (uint)(param_1 != 0);
  *(undefined ***)this = &PTR__codecvt_011b7d30;
                    /* try { // try from 00c767f2 to 00c767f6 has its CatchHandler @ 00c76802 */
  uVar1 = locale::facet::_S_get_c_locale();
  *(undefined8 *)(this + 0x10) = uVar1;
  return;
}


// ==== entry=00c76810 orig=FUN_00c76810 size=58 name=codecvt ====

/* std::codecvt<char, char, __mbstate_t>::codecvt(__locale_struct*, unsigned long) */

void __thiscall
std::codecvt<char,char,__mbstate_t>::codecvt
          (codecvt<char,char,__mbstate_t> *this,__locale_struct *param_1,ulong param_2)

{
  undefined8 uVar1;
  __locale_struct *local_10;
  
  *(uint *)(this + 8) = (uint)(param_2 != 0);
  *(undefined ***)this = &PTR__codecvt_011b7d30;
  local_10 = param_1;
  uVar1 = locale::facet::_S_clone_c_locale(&local_10);
  *(undefined8 *)(this + 0x10) = uVar1;
  return;
}


// ==== entry=00c76850 orig=FUN_00c76850 size=50 name=codecvt ====

/* std::codecvt<wchar_t, char, __mbstate_t>::codecvt(unsigned long) */

void __thiscall
std::codecvt<wchar_t,char,__mbstate_t>::codecvt
          (codecvt<wchar_t,char,__mbstate_t> *this,ulong param_1)

{
  undefined8 uVar1;
  
  *(uint *)(this + 8) = (uint)(param_1 != 0);
  *(undefined ***)this = &PTR__codecvt_011b7d88;
                    /* try { // try from 00c76872 to 00c76876 has its CatchHandler @ 00c76882 */
  uVar1 = locale::facet::_S_get_c_locale();
  *(undefined8 *)(this + 0x10) = uVar1;
  return;
}


// ==== entry=00c76890 orig=FUN_00c76890 size=58 name=codecvt ====

/* std::codecvt<wchar_t, char, __mbstate_t>::codecvt(__locale_struct*, unsigned long) */

void __thiscall
std::codecvt<wchar_t,char,__mbstate_t>::codecvt
          (codecvt<wchar_t,char,__mbstate_t> *this,__locale_struct *param_1,ulong param_2)

{
  undefined8 uVar1;
  __locale_struct *local_10;
  
  *(uint *)(this + 8) = (uint)(param_2 != 0);
  *(undefined ***)this = &PTR__codecvt_011b7d88;
  local_10 = param_1;
  uVar1 = locale::facet::_S_clone_c_locale(&local_10);
  *(undefined8 *)(this + 0x10) = uVar1;
  return;
}


// ==== entry=00c768d0 name=FUN_00c768d0 size=93 ====

void FUN_00c768d0(long param_1)

{
  void *pvVar1;
  undefined8 *puVar2;
  undefined8 *puVar3;
  
  puVar2 = *(undefined8 **)(param_1 + 0x30);
  puVar3 = *(undefined8 **)(param_1 + 0x38);
  if (puVar2 != puVar3) {
    do {
      pvVar1 = (void *)*puVar2;
      if (pvVar1 != (void *)0x0) {
        free(*(void **)((long)pvVar1 + 8));
        std::locale::~locale((locale *)((long)pvVar1 + 0x10));
        operator_delete(pvVar1);
      }
      puVar2 = puVar2 + 1;
    } while (*(undefined8 **)(param_1 + 0x38) != puVar2);
    puVar3 = *(undefined8 **)(param_1 + 0x30);
  }
  if (puVar3 != (undefined8 *)0x0) {
    operator_delete(puVar3);
    return;
  }
  return;
}


// ==== entry=00c76940 orig=FUN_00c76940 size=164 name=__convert_to_v<float> ====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* void std::__convert_to_v<float>(char const*, float&, std::_Ios_Iostate&, __locale_struct* const&)
    */

void std::__convert_to_v<float>
               (char *param_1,float *param_2,_Ios_Iostate *param_3,__locale_struct **param_4)

{
  long in_FS_OFFSET;
  float fVar1;
  char *local_28;
  long local_20;
  
  local_20 = *(long *)(in_FS_OFFSET + 0x28);
  fVar1 = (float)__strtof_l(param_1,&local_28,*param_4);
  *param_2 = fVar1;
  if ((local_28 == param_1) || (*local_28 != '\0')) {
    *param_2 = 0.0;
    *(undefined4 *)param_3 = 4;
  }
  else if (fVar1 == INFINITY) {
    *param_2 = 3.4028235e+38;
    *(undefined4 *)param_3 = 4;
  }
  else if (fVar1 == -INFINITY) {
    *param_2 = -3.4028235e+38;
    *(undefined4 *)param_3 = 4;
  }
  if (local_20 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


// ==== entry=00c76a00 orig=FUN_00c76a00 size=175 name=__convert_to_v<double> ====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* void std::__convert_to_v<double>(char const*, double&, std::_Ios_Iostate&, __locale_struct*
   const&) */

void std::__convert_to_v<double>
               (char *param_1,double *param_2,_Ios_Iostate *param_3,__locale_struct **param_4)

{
  long in_FS_OFFSET;
  double dVar1;
  char *local_28;
  long local_20;
  
  local_20 = *(long *)(in_FS_OFFSET + 0x28);
  dVar1 = (double)__strtod_l(param_1,&local_28,*param_4);
  *param_2 = dVar1;
  if ((local_28 == param_1) || (*local_28 != '\0')) {
    *param_2 = 0.0;
    *(undefined4 *)param_3 = 4;
  }
  else if (dVar1 == INFINITY) {
    *param_2 = 1.79769313486232e+308;
    *(undefined4 *)param_3 = 4;
  }
  else if (dVar1 == -INFINITY) {
    *param_2 = -1.79769313486232e+308;
    *(undefined4 *)param_3 = 4;
  }
  if (local_20 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


// ==== entry=00c76ac0 orig=FUN_00c76ac0 size=184 name=__convert_to_v<long_double> ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* void std::__convert_to_v<long double>(char const*, long double&, std::_Ios_Iostate&,
   __locale_struct* const&) */

void std::__convert_to_v<long_double>
               (char *param_1,longdouble *param_2,_Ios_Iostate *param_3,__locale_struct **param_4)

{
  long in_FS_OFFSET;
  longdouble in_ST0;
  char *local_28;
  long local_20;
  
  local_20 = *(long *)(in_FS_OFFSET + 0x28);
  strtold_l(param_1,&local_28,*param_4);
  *param_2 = in_ST0;
  if ((local_28 == param_1) || (*local_28 != '\0')) {
    *param_2 = (longdouble)0;
    *(undefined4 *)param_3 = 4;
  }
  else if (in_ST0 == (longdouble)INFINITY) {
    *param_2 = _DAT_00c8fe10;
    *(undefined4 *)param_3 = 4;
  }
  else if (in_ST0 == (longdouble)-INFINITY) {
    *param_2 = _DAT_00d991c0;
    *(undefined4 *)param_3 = 4;
  }
  if (local_20 == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ==== entry=00c76b80 orig=FUN_00c76b80 size=36 name=_S_create_c_locale ====

/* std::locale::facet::_S_create_c_locale(__locale_struct*&, char const*, __locale_struct*) */

void std::locale::facet::_S_create_c_locale
               (__locale_struct **param_1,char *param_2,__locale_struct *param_3)

{
  __locale_struct *p_Var1;
  
  p_Var1 = (__locale_struct *)__newlocale(0x40);
  *param_1 = p_Var1;
  if (p_Var1 != (__locale_struct *)0x0) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __throw_runtime_error("locale::facet::_S_create_c_locale name not valid");
}


// ==== entry=00c76bb0 orig=FUN_00c76bb0 size=32 name=_S_destroy_c_locale ====

/* std::locale::facet::_S_destroy_c_locale(__locale_struct*&) */

void std::locale::facet::_S_destroy_c_locale(__locale_struct **param_1)

{
  __locale_struct *p_Var1;
  
  if (*param_1 == (__locale_struct *)0x0) {
    return;
  }
  p_Var1 = (__locale_struct *)_S_get_c_locale();
  if (*param_1 != p_Var1) {
    __freelocale();
    return;
  }
  return;
}


// ==== entry=00c76be0 orig=FUN_00c76be0 size=8 name=_S_clone_c_locale ====

/* std::locale::facet::_S_clone_c_locale(__locale_struct*&) */

void std::locale::facet::_S_clone_c_locale(__locale_struct **param_1)

{
  __duplocale(*param_1);
  return;
}


// ==== entry=00c76bf0 name=FUN_00c76bf0 size=82 ====

void FUN_00c76bf0(undefined8 param_1,undefined8 param_2)

{
  long lVar1;
  long lVar2;
  
  lVar1 = __duplocale();
  if (lVar1 == 0) {
                    /* WARNING: Subroutine does not return */
    std::__throw_runtime_error("locale::facet::_S_lc_ctype_c_locale duplocale error");
  }
  lVar2 = __newlocale(1,param_2,lVar1);
  if (lVar2 != 0) {
    return;
  }
  __freelocale(lVar1);
                    /* WARNING: Subroutine does not return */
  std::__throw_runtime_error("locale::facet::_S_lc_ctype_c_locale newlocale error");
}


// ==== entry=00c76c50 name=FUN_00c76c50 size=348 ====

/* WARNING: Removing unreachable block (ram,0x00c76d89) */

void FUN_00c76c50(pthread_mutex_t *param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  long lVar3;
  undefined8 *puVar4;
  long lVar5;
  undefined8 *__src;
  
  iVar2 = pthread_mutex_lock(param_1);
  if (iVar2 != 0) {
    FUN_00bea4a0();
LAB_00c76d93:
    puVar4 = (undefined8 *)__cxa_allocate_exception(8);
    *puVar4 = &PTR_FUN_011b18e8;
                    /* WARNING: Subroutine does not return */
                    /* try { // try from 00c76dbc to 00c76dc0 has its CatchHandler @ 00c76dc9 */
    __cxa_throw(puVar4,&PTR_PTR_011b1898,FUN_00bea420);
  }
  puVar4 = *(undefined8 **)((long)param_1 + 0x30);
  for (lVar3 = (long)*(undefined8 **)((long)param_1 + 0x38) - (long)puVar4 >> 3; 0 < lVar3;
      lVar3 = (lVar3 - lVar5) + -1) {
    while( true ) {
      lVar5 = lVar3 >> 1;
      if (*(int *)puVar4[lVar5] < param_2) break;
      lVar3 = lVar5;
      if (lVar5 == 0) goto LAB_00c76cbb;
    }
    puVar4 = puVar4 + lVar5 + 1;
  }
LAB_00c76cbb:
  if ((puVar4 == *(undefined8 **)((long)param_1 + 0x38)) ||
     (piVar1 = (int *)*puVar4, *piVar1 != param_2)) {
    iVar2 = pthread_mutex_unlock(param_1);
    if (iVar2 != 0) goto LAB_00c76d93;
  }
  else {
    free(*(void **)(piVar1 + 2));
    std::locale::~locale((locale *)(piVar1 + 4));
    operator_delete(piVar1);
    __src = puVar4 + 1;
    if (*(undefined8 **)((long)param_1 + 0x38) != __src) {
      memmove(puVar4,__src,(long)*(undefined8 **)((long)param_1 + 0x38) - (long)__src);
      __src = *(undefined8 **)((long)param_1 + 0x38);
    }
    iVar2 = param_1[1].__data.__lock;
    *(undefined8 **)((long)param_1 + 0x38) = __src + -1;
    if (iVar2 + -1 == param_2) {
      param_1[1].__data.__lock = param_2;
    }
    iVar2 = pthread_mutex_unlock(param_1);
    if (iVar2 != 0) {
      puVar4 = (undefined8 *)__cxa_allocate_exception(8);
      *puVar4 = &PTR_FUN_011b18e8;
                    /* WARNING: Subroutine does not return */
                    /* try { // try from 00c76d74 to 00c76d78 has its CatchHandler @ 00c76dc1 */
      __cxa_throw(puVar4,&PTR_PTR_011b1898,FUN_00bea420);
    }
  }
  return;
}


// ==== entry=00c76de0 name=FUN_00c76de0 size=217 ====

int * FUN_00c76de0(pthread_mutex_t *param_1,int param_2)

{
  int iVar1;
  long lVar2;
  undefined8 *puVar3;
  undefined8 uVar4;
  long lVar5;
  int *piVar6;
  
  iVar1 = pthread_mutex_lock(param_1);
  if (iVar1 != 0) {
    uVar4 = FUN_00bea4a0();
                    /* catch() { ... } // from try @ 00c76eae with catch @ 00c76eb8 */
    piVar6 = (int *)FUN_0051e310(uVar4);
    return piVar6;
  }
  puVar3 = *(undefined8 **)((long)param_1 + 0x30);
  for (lVar2 = (long)*(undefined8 **)((long)param_1 + 0x38) - (long)puVar3 >> 3; 0 < lVar2;
      lVar2 = (lVar2 - lVar5) + -1) {
    while( true ) {
      lVar5 = lVar2 >> 1;
      if (*(int *)puVar3[lVar5] < param_2) break;
      lVar2 = lVar5;
      if (lVar5 == 0) goto LAB_00c76e49;
    }
    puVar3 = puVar3 + lVar5 + 1;
  }
LAB_00c76e49:
  if (*(undefined8 **)((long)param_1 + 0x38) == puVar3) {
    piVar6 = (int *)0x0;
  }
  else {
    piVar6 = (int *)*puVar3;
    if (*piVar6 != param_2) {
      piVar6 = (int *)0x0;
    }
  }
  iVar1 = pthread_mutex_unlock(param_1);
  if (iVar1 == 0) {
    return piVar6;
  }
  puVar3 = (undefined8 *)__cxa_allocate_exception(8);
  *puVar3 = &PTR_FUN_011b18e8;
                    /* WARNING: Subroutine does not return */
                    /* try { // try from 00c76eae to 00c76eb2 has its CatchHandler @ 00c76eb8 */
  __cxa_throw(puVar3,&PTR_PTR_011b1898,FUN_00bea420);
}


// ==== entry=00c76ec0 name=FUN_00c76ec0 size=173 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined * FUN_00c76ec0(void)

{
  int iVar1;
  
  if (DAT_011c66a8 != '\0') {
    return &DAT_011c66c0;
  }
  iVar1 = __cxa_guard_acquire(&DAT_011c66a8);
  if (iVar1 == 0) {
    return &DAT_011c66c0;
  }
  _DAT_011c66e0 = 0;
  _DAT_011c66c0 = (undefined1  [16])0x0;
  _DAT_011c66d0 = (undefined1  [16])0x0;
  _DAT_011c66e8 = 0;
  _DAT_011c66f0 = 0;
  _DAT_011c66f8 = 0;
  _DAT_011c6700 = 0;
  __cxa_guard_release(&DAT_011c66a8);
  __cxa_atexit(FUN_00c768d0,&DAT_011c66c0,&DAT_00c89008);
  return &DAT_011c66c0;
}


// ==== entry=00c76f80 name=FUN_00c76f80 size=300 ====

void FUN_00c76f80(undefined8 *param_1,void *param_2,undefined8 *param_3)

{
  void *__dest;
  void *pvVar1;
  void *__src;
  ulong uVar2;
  void *__dest_00;
  size_t __n;
  ulong uVar3;
  ulong uVar4;
  long lVar5;
  
  pvVar1 = (void *)param_1[1];
  __src = (void *)*param_1;
  __n = (long)param_2 - (long)__src;
  uVar2 = (long)pvVar1 - (long)__src >> 3;
  if (uVar2 == 0) {
    uVar3 = 1;
LAB_00c770b5:
    uVar4 = uVar3 * 8;
LAB_00c76fc8:
    __dest_00 = operator_new(uVar4);
    lVar5 = uVar4 + (long)__dest_00;
  }
  else {
    uVar3 = uVar2 * 2;
    uVar4 = 0xfffffffffffffff8;
    if ((uVar3 < uVar2) || (0x1fffffffffffffff < uVar3)) goto LAB_00c76fc8;
    lVar5 = 0;
    __dest_00 = (void *)0x0;
    if (uVar3 != 0) goto LAB_00c770b5;
  }
  __dest = (void *)((long)__dest_00 + __n + 8);
  *(undefined8 *)((long)__dest_00 + __n) = *param_3;
  if (param_2 == __src) {
    if (param_2 != pvVar1) goto LAB_00c77038;
LAB_00c77046:
    if (__src == (void *)0x0) goto LAB_00c7704b;
  }
  else {
    memmove(__dest_00,__src,__n);
    if (param_2 != pvVar1) {
LAB_00c77038:
      memcpy(__dest,param_2,(long)pvVar1 - (long)param_2);
      goto LAB_00c77046;
    }
  }
  operator_delete(__src);
LAB_00c7704b:
  *param_1 = __dest_00;
  param_1[1] = (long)__dest + ((long)pvVar1 - (long)param_2);
  param_1[2] = lVar5;
  return;
}


// ==== entry=00c770d0 name=FUN_00c770d0 size=347 ====

int FUN_00c770d0(pthread_mutex_t *param_1,char *param_2,locale *param_3)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  char *pcVar4;
  undefined8 *puVar5;
  long in_FS_OFFSET;
  int *local_48;
  long local_40;
  
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  iVar1 = pthread_mutex_lock(param_1);
  if (iVar1 == 0) {
    iVar1 = param_1[1].__data.__lock;
    if (iVar1 == 0x7fffffff) {
      iVar1 = -1;
    }
    else {
      param_1[1].__data.__lock = iVar1 + 1;
      std::locale::locale((locale *)&local_48,param_3);
                    /* try { // try from 00c77142 to 00c77146 has its CatchHandler @ 00c77247 */
      piVar3 = operator_new(0x18);
      *piVar3 = iVar1;
      pcVar4 = strdup(param_2);
      *(char **)(piVar3 + 2) = pcVar4;
      std::locale::locale((locale *)(piVar3 + 4),(locale *)&local_48);
      std::locale::~locale((locale *)&local_48);
      if (*(long *)(piVar3 + 2) == 0) {
        std::locale::~locale((locale *)(piVar3 + 4));
        iVar1 = -1;
        operator_delete(piVar3);
      }
      else {
        puVar5 = *(undefined8 **)((long)param_1 + 0x38);
        local_48 = piVar3;
        if (puVar5 == *(undefined8 **)((long)param_1 + 0x40)) {
                    /* try { // try from 00c771f7 to 00c771fb has its CatchHandler @ 00c7723f */
          FUN_00c76f80((long)param_1 + 0x30,puVar5,(locale *)&local_48);
        }
        else {
          *puVar5 = piVar3;
          *(undefined8 **)((long)param_1 + 0x38) = puVar5 + 1;
        }
        iVar1 = *piVar3;
      }
    }
    iVar2 = pthread_mutex_unlock(param_1);
    if (iVar2 == 0) {
      if (local_40 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
        __stack_chk_fail();
      }
      return iVar1;
    }
  }
  else {
    FUN_00bea4a0();
  }
  puVar5 = (undefined8 *)__cxa_allocate_exception(8);
  *puVar5 = &PTR_FUN_011b18e8;
                    /* WARNING: Subroutine does not return */
                    /* try { // try from 00c7723a to 00c7723e has its CatchHandler @ 00c7724f */
  __cxa_throw(puVar5,&PTR_PTR_011b1898,FUN_00bea420);
}


// ==== entry=00c77260 orig=FUN_00c77260 size=42 name=_M_compare ====

/* std::collate<char>::_M_compare(char const*, char const*) const */

uint __thiscall std::collate<char>::_M_compare(collate<char> *this,char *param_1,char *param_2)

{
  int iVar1;
  
  iVar1 = __strcoll_l(param_1,param_2,*(undefined8 *)(this + 0x10));
  return (uint)(iVar1 != 0) | iVar1 >> 0x1e;
}


// ==== entry=00c77290 orig=FUN_00c77290 size=21 name=_M_transform ====

/* std::collate<char>::_M_transform(char*, char const*, unsigned long) const */

void __thiscall
std::collate<char>::_M_transform(collate<char> *this,char *param_1,char *param_2,ulong param_3)

{
  __strxfrm_l(param_1,param_2,param_3,*(undefined8 *)(this + 0x10));
  return;
}


// ==== entry=00c772b0 orig=FUN_00c772b0 size=42 name=_M_compare ====

/* std::collate<wchar_t>::_M_compare(wchar_t const*, wchar_t const*) const */

uint __thiscall
std::collate<wchar_t>::_M_compare(collate<wchar_t> *this,wchar_t *param_1,wchar_t *param_2)

{
  int iVar1;
  
  iVar1 = __wcscoll_l(param_1,param_2,*(undefined8 *)(this + 0x10));
  return (uint)(iVar1 != 0) | iVar1 >> 0x1e;
}


// ==== entry=00c772e0 orig=FUN_00c772e0 size=21 name=_M_transform ====

/* std::collate<wchar_t>::_M_transform(wchar_t*, wchar_t const*, unsigned long) const */

void __thiscall
std::collate<wchar_t>::_M_transform
          (collate<wchar_t> *this,wchar_t *param_1,wchar_t *param_2,ulong param_3)

{
  __wcsxfrm_l(param_1,param_2,param_3,*(undefined8 *)(this + 0x10));
  return;
}


// ==== entry=00c77300 name=FUN_00c77300 size=42 ====

uint FUN_00c77300(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  
  iVar1 = __strcoll_l(param_2,param_3,*(undefined8 *)(param_1 + 0x10));
  return (uint)(iVar1 != 0) | iVar1 >> 0x1e;
}


// ==== entry=00c77330 name=FUN_00c77330 size=21 ====

void FUN_00c77330(long param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __strxfrm_l(param_2,param_3,param_4,*(undefined8 *)(param_1 + 0x10));
  return;
}


// ==== entry=00c77350 name=FUN_00c77350 size=42 ====

uint FUN_00c77350(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  
  iVar1 = __wcscoll_l(param_2,param_3,*(undefined8 *)(param_1 + 0x10));
  return (uint)(iVar1 != 0) | iVar1 >> 0x1e;
}


// ==== entry=00c77380 name=FUN_00c77380 size=21 ====

void FUN_00c77380(long param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __wcsxfrm_l(param_2,param_3,param_4,*(undefined8 *)(param_1 + 0x10));
  return;
}


// ==== entry=00c773a0 orig=FUN_00c773a0 size=110 name=_M_init ====

/* std::ios_base::_M_init() */

void __thiscall std::ios_base::_M_init(ios_base *this)

{
  long in_FS_OFFSET;
  locale alStack_28 [8];
  long local_20;
  
  local_20 = *(long *)(in_FS_OFFSET + 0x28);
  *(undefined8 *)(this + 8) = 6;
  *(undefined8 *)(this + 0x10) = 0;
  *(undefined4 *)(this + 0x18) = 0x1002;
  locale::locale(alStack_28);
  locale::operator=((locale *)(this + 0xd0),alStack_28);
  locale::~locale(alStack_28);
  if (local_20 == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ==== entry=00c77410 orig=FUN_00c77410 size=72 name=imbue ====

/* std::ios_base::imbue(std::locale const&) */

locale * std::ios_base::imbue(locale *param_1)

{
  locale *in_RDX;
  long in_RSI;
  
  locale::locale(param_1,(locale *)(in_RSI + 0xd0));
  locale::operator=((locale *)(in_RSI + 0xd0),in_RDX);
  _M_call_callbacks();
  return param_1;
}


// ==== entry=00c77460 orig=FUN_00c77460 size=14 name=operator.cast.to.void* ====

/* std::ios::operator void*() const */

void * __thiscall std::ios::operator_cast_to_void_(ios *this)

{
  ios *piVar1;
  
  piVar1 = (ios *)0x0;
  if (((byte)this[0x20] & 5) == 0) {
    piVar1 = this;
  }
  return piVar1;
}


// ==== entry=00c77470 orig=FUN_00c77470 size=14 name=operator.cast.to.void* ====

/* std::wios::operator void*() const */

void * __thiscall std::wios::operator_cast_to_void_(wios *this)

{
  wios *pwVar1;
  
  pwVar1 = (wios *)0x0;
  if (((byte)this[0x20] & 5) == 0) {
    pwVar1 = this;
  }
  return pwVar1;
}


// ==== entry=00c77480 orig=FUN_00c77480 size=822 name=getline ====

/* std::istream::getline(char*, long, char) */

istream * __thiscall std::istream::getline(istream *this,char *param_1,long param_2,char param_3)

{
  long *plVar1;
  uint uVar2;
  int iVar3;
  byte *pbVar4;
  byte *pbVar5;
  size_t __n;
  long lVar6;
  byte *pbVar7;
  uint uVar8;
  long lVar9;
  long in_FS_OFFSET;
  sentry local_41;
  long local_40;
  
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  *(undefined8 *)(this + 8) = 0;
  sentry::sentry(&local_41,this,true);
  if (local_41 == (sentry)0x0) {
    if (param_2 < 1) {
      lVar6 = *(long *)(this + 8);
    }
    else {
      *param_1 = '\0';
      lVar6 = *(long *)(this + 8);
    }
joined_r0x00c77617:
    if (lVar6 == 0) {
LAB_00c774e7:
      uVar8 = 4;
LAB_00c774ec:
      ios::s_basic_ios__clear_c1bf70
                ((ios *)(this + *(long *)(*(long *)this + -0x18)),
                 uVar8 | *(uint *)((ios *)(this + *(long *)(*(long *)this + -0x18)) + 0x20));
    }
LAB_00c7761d:
    if (local_40 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
      __stack_chk_fail();
    }
    return this;
  }
  plVar1 = *(long **)(this + *(long *)(*(long *)this + -0x18) + 0xe8);
  if ((byte *)plVar1[2] < (byte *)plVar1[3]) {
    uVar8 = (uint)*(byte *)plVar1[2];
  }
  else {
                    /* try { // try from 00c776d6 to 00c776d8 has its CatchHandler @ 00c777e5 */
    uVar8 = (**(code **)(*plVar1 + 0x48))(plVar1);
  }
  lVar9 = *(long *)(this + 8);
LAB_00c7753d:
  lVar6 = lVar9 + 1;
  uVar2 = uVar8;
  if (lVar6 < param_2) {
    do {
      if (uVar2 == 0xffffffff) {
LAB_00c776f2:
        if (0 < param_2) {
          *param_1 = '\0';
        }
        lVar9 = *(long *)(this + 8);
        goto LAB_00c776ff;
      }
      pbVar7 = (byte *)plVar1[3];
      pbVar5 = (byte *)plVar1[2];
      if ((byte)param_3 == uVar2) goto LAB_00c77740;
      __n = (param_2 - lVar9) - 1;
      if ((long)pbVar7 - (long)pbVar5 < (long)__n) {
        __n = (long)pbVar7 - (long)pbVar5;
      }
      if ((long)__n < 2) {
        *param_1 = (char)uVar2;
        pbVar5 = (byte *)plVar1[2];
        param_1 = param_1 + 1;
        pbVar7 = (byte *)plVar1[3];
        *(long *)(this + 8) = *(long *)(this + 8) + 1;
        if (pbVar5 < pbVar7) {
          pbVar5 = pbVar5 + 1;
          plVar1[2] = (long)pbVar5;
        }
        else {
                    /* try { // try from 00c776e6 to 00c77728 has its CatchHandler @ 00c777e0 */
          iVar3 = (**(code **)(*plVar1 + 0x50))(plVar1);
          if (iVar3 == -1) goto LAB_00c776f2;
          pbVar5 = (byte *)plVar1[2];
          pbVar7 = (byte *)plVar1[3];
        }
        if (pbVar5 < pbVar7) {
          uVar8 = (uint)*pbVar5;
          lVar9 = *(long *)(this + 8);
        }
        else {
          uVar8 = (**(code **)(*plVar1 + 0x48))(plVar1);
          lVar9 = *(long *)(this + 8);
        }
        goto LAB_00c7753d;
      }
      pbVar4 = memchr(pbVar5,(int)param_3,__n);
      if ((pbVar4 == (byte *)0x0) || (__n = (long)pbVar4 - (long)pbVar5, __n != 0)) {
        memcpy(param_1,pbVar5,__n);
        lVar9 = *(long *)(this + 8);
        pbVar7 = (byte *)plVar1[3];
        pbVar4 = (byte *)(plVar1[2] + __n);
      }
      lVar9 = lVar9 + __n;
      plVar1[2] = (long)pbVar4;
      param_1 = param_1 + __n;
      *(long *)(this + 8) = lVar9;
      if (pbVar7 <= pbVar4) goto LAB_00c776b8;
      lVar6 = lVar9 + 1;
      uVar2 = (uint)*pbVar4;
      uVar8 = (uint)*pbVar4;
      if (param_2 <= lVar6) break;
    } while( true );
  }
  if (uVar8 != 0xffffffff) {
    if ((byte)param_3 != uVar8) {
      if (param_2 < 1) {
        uVar8 = 4;
        goto LAB_00c77704;
      }
      *param_1 = '\0';
      uVar8 = 4;
      goto LAB_00c774ec;
    }
    pbVar7 = (byte *)plVar1[3];
    pbVar5 = (byte *)plVar1[2];
LAB_00c77740:
    *(long *)(this + 8) = lVar6;
    if (pbVar7 <= pbVar5) {
                    /* try { // try from 00c7777e to 00c77780 has its CatchHandler @ 00c777db */
      (**(code **)(*plVar1 + 0x50))(plVar1);
      if (0 < param_2) {
        *param_1 = '\0';
        lVar6 = *(long *)(this + 8);
        goto joined_r0x00c77790;
      }
      lVar6 = *(long *)(this + 8);
      goto joined_r0x00c77617;
    }
    plVar1[2] = (long)(pbVar5 + 1);
    if (param_2 < 1) goto joined_r0x00c77617;
    *param_1 = '\0';
    lVar6 = *(long *)(this + 8);
joined_r0x00c77790:
    if (lVar6 != 0) goto LAB_00c7761d;
    goto LAB_00c774e7;
  }
  if (param_2 < 1) {
LAB_00c776ff:
    uVar8 = 2;
LAB_00c77704:
    if (lVar9 == 0) {
      uVar8 = uVar8 | 4;
    }
  }
  else {
    *param_1 = '\0';
    uVar8 = (-(uint)(*(long *)(this + 8) == 0) & 4) + 2;
  }
  goto LAB_00c774ec;
LAB_00c776b8:
                    /* try { // try from 00c776be to 00c776c0 has its CatchHandler @ 00c777d6 */
  uVar8 = (**(code **)(*plVar1 + 0x48))(plVar1);
  lVar9 = *(long *)(this + 8);
  goto LAB_00c7753d;
}


// ==== entry=00c777f0 orig=FUN_00c777f0 size=810 name=ignore ====

/* std::istream::ignore(long, int) */

istream * __thiscall std::istream::ignore(istream *this,long param_1,int param_2)

{
  long *plVar1;
  uint uVar2;
  int iVar3;
  void *pvVar4;
  long lVar5;
  size_t __n;
  byte *pbVar6;
  byte *pbVar7;
  sentry sVar8;
  long in_FS_OFFSET;
  sentry local_41;
  long local_40;
  
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  if (param_2 == -1) {
    this = (istream *)ignore(this,param_1);
  }
  else {
    *(undefined8 *)(this + 8) = 0;
    sentry::sentry(&local_41,this,true);
    if ((0 < param_1) && (local_41 != (sentry)0x0)) {
      plVar1 = *(long **)(this + *(long *)(*(long *)this + -0x18) + 0xe8);
      if ((byte *)plVar1[2] < (byte *)plVar1[3]) {
        uVar2 = (uint)*(byte *)plVar1[2];
      }
      else {
        uVar2 = (**(code **)(*plVar1 + 0x48))(plVar1);
      }
      lVar5 = *(long *)(this + 8);
      sVar8 = (sentry)0x0;
joined_r0x00c77893:
      while (lVar5 < param_1) {
        if (uVar2 == 0xffffffff) {
LAB_00c779d0:
          if (param_1 == 0x7fffffffffffffff) goto LAB_00c77ac0;
          if (sVar8 != (sentry)0x0) {
            *(undefined8 *)(this + 8) = 0x7fffffffffffffff;
          }
          goto LAB_00c779ec;
        }
        if (uVar2 == param_2) {
          if (param_1 != 0x7fffffffffffffff) {
            if (sVar8 == (sentry)0x0) goto LAB_00c77a44;
            goto LAB_00c77a28;
          }
          if (sVar8 == (sentry)0x0) goto LAB_00c77a60;
          goto LAB_00c77a28;
        }
        pbVar7 = (byte *)plVar1[3];
        pbVar6 = (byte *)plVar1[2];
        __n = param_1 - lVar5;
        if ((long)pbVar7 - (long)pbVar6 < param_1 - lVar5) {
          __n = (long)pbVar7 - (long)pbVar6;
        }
        if ((long)__n < 2) {
          *(long *)(this + 8) = lVar5 + 1;
          if (pbVar6 < pbVar7) {
            pbVar6 = pbVar6 + 1;
            plVar1[2] = (long)pbVar6;
          }
          else {
            iVar3 = (**(code **)(*plVar1 + 0x50))(plVar1);
            if (iVar3 == -1) goto LAB_00c779d0;
            pbVar6 = (byte *)plVar1[2];
            pbVar7 = (byte *)plVar1[3];
          }
          if (pbVar7 <= pbVar6) goto LAB_00c77ae0;
          uVar2 = (uint)*pbVar6;
          lVar5 = *(long *)(this + 8);
        }
        else {
          pvVar4 = memchr(pbVar6,(int)(char)param_2,__n);
          if (pvVar4 != (void *)0x0) {
            __n = (long)pvVar4 - (long)pbVar6;
          }
          pbVar6 = pbVar6 + __n;
          lVar5 = lVar5 + __n;
          plVar1[2] = (long)pbVar6;
          *(long *)(this + 8) = lVar5;
          if (pbVar6 < pbVar7) {
            uVar2 = (uint)*pbVar6;
          }
          else {
LAB_00c77ae0:
                    /* try { // try from 00c77ae7 to 00c77b0b has its CatchHandler @ 00c77b4e */
            uVar2 = (**(code **)(*plVar1 + 0x48))(plVar1);
            lVar5 = *(long *)(this + 8);
          }
        }
      }
      if (param_1 != 0x7fffffffffffffff) {
        if (sVar8 == (sentry)0x0) goto LAB_00c77a36;
        goto LAB_00c77a28;
      }
      if (uVar2 == 0xffffffff) {
LAB_00c77ac0:
        if (sVar8 != (sentry)0x0) {
          *(undefined8 *)(this + 8) = 0x7fffffffffffffff;
        }
        goto LAB_00c779ec;
      }
      if (uVar2 != param_2) {
        *(undefined8 *)(this + 8) = 0x8000000000000000;
        lVar5 = -0x8000000000000000;
        sVar8 = local_41;
        goto joined_r0x00c77893;
      }
      if (sVar8 != (sentry)0x0) {
LAB_00c77a28:
        *(undefined8 *)(this + 8) = 0x7fffffffffffffff;
LAB_00c77a36:
        if (uVar2 == 0xffffffff) {
LAB_00c779ec:
          ios::s_basic_ios__clear_c1bf70
                    ((ios *)(this + *(long *)(*(long *)this + -0x18)),
                     *(uint *)((ios *)(this + *(long *)(*(long *)this + -0x18)) + 0x20) | 2);
          goto LAB_00c77993;
        }
        if (param_2 != uVar2) goto LAB_00c77993;
LAB_00c77a44:
        lVar5 = *(long *)(this + 8);
      }
      if (lVar5 != 0x7fffffffffffffff) {
LAB_00c77a60:
        *(long *)(this + 8) = lVar5 + 1;
      }
      if ((ulong)plVar1[2] < (ulong)plVar1[3]) {
        plVar1[2] = plVar1[2] + 1;
      }
      else {
                    /* try { // try from 00c77985 to 00c77987 has its CatchHandler @ 00c77b4e */
        (**(code **)(*plVar1 + 0x50))(plVar1);
      }
    }
  }
LAB_00c77993:
  if (local_40 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return this;
}


// ==== entry=00c77b60 orig=FUN_00c77b60 size=724 name=operator>> ====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* std::istream& std::TEMPNAMEPLACEHOLDERVALUE(std::istream&, char*) */

istream * std::operator>>(istream *param_1,char *param_2)

{
  long *plVar1;
  void *__src;
  int iVar2;
  ctype *pcVar3;
  long lVar4;
  byte *pbVar5;
  byte *pbVar6;
  ulong uVar7;
  long lVar8;
  long lVar9;
  long lVar10;
  uint uVar11;
  size_t __n;
  long lVar12;
  long in_FS_OFFSET;
  char *local_68;
  sentry local_49;
  locale local_48 [8];
  long local_40;
  
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  istream::sentry::sentry(&local_49,param_1,false);
  lVar4 = *(long *)param_1;
  if (local_49 == (sentry)0x0) {
    uVar11 = 4;
  }
  else {
    lVar12 = *(long *)(param_1 + *(long *)(lVar4 + -0x18) + 0x10);
    if (lVar12 < 1) {
      lVar12 = 0x7fffffffffffffff;
    }
    locale::locale(local_48,(locale *)(param_1 + *(long *)(lVar4 + -0x18) + 0xd0));
                    /* try { // try from 00c77bd5 to 00c77bd9 has its CatchHandler @ 00c77e52 */
    pcVar3 = use_facet<std::ctype<char>>(local_48);
    locale::~locale(local_48);
    plVar1 = *(long **)(param_1 + *(long *)(*(long *)param_1 + -0x18) + 0xe8);
    if ((byte *)plVar1[2] < (byte *)plVar1[3]) {
      uVar7 = (ulong)*(byte *)plVar1[2];
    }
    else {
                    /* try { // try from 00c77e14 to 00c77e16 has its CatchHandler @ 00c77e48 */
      uVar7 = (**(code **)(*plVar1 + 0x48))(plVar1);
    }
    lVar10 = 0;
LAB_00c77c18:
    uVar11 = (uint)uVar7;
    if (lVar10 < lVar12 + -1) {
      do {
        local_68 = param_2;
        if ((int)uVar7 == -1) goto LAB_00c77de4;
        lVar4 = *(long *)(pcVar3 + 0x30);
        if ((*(byte *)(lVar4 + 1 + (uVar7 & 0xff) * 2) & 0x20) != 0) goto LAB_00c77cdc;
        __src = (void *)plVar1[2];
        lVar9 = (lVar12 - lVar10) + -1;
        lVar8 = plVar1[3] - (long)__src;
        if (lVar8 < lVar9) {
          lVar9 = lVar8;
        }
        if (lVar9 < 2) {
          *param_2 = (char)uVar7;
          param_2 = param_2 + 1;
          lVar10 = lVar10 + 1;
          pbVar6 = (byte *)plVar1[3];
          if ((byte *)plVar1[2] < pbVar6) {
            pbVar5 = (byte *)plVar1[2] + 1;
            plVar1[2] = (long)pbVar5;
          }
          else {
            iVar2 = (**(code **)(*plVar1 + 0x50))(plVar1);
            local_68 = param_2;
            if (iVar2 == -1) goto LAB_00c77de4;
            pbVar5 = (byte *)plVar1[2];
            pbVar6 = (byte *)plVar1[3];
          }
          if (pbVar5 < pbVar6) {
            uVar7 = (ulong)*pbVar5;
          }
          else {
                    /* try { // try from 00c77e22 to 00c77e24 has its CatchHandler @ 00c77e4d */
            uVar7 = (**(code **)(*plVar1 + 0x48))(plVar1);
          }
          goto LAB_00c77c18;
        }
        pbVar6 = (byte *)((long)__src + 1);
        if ((pbVar6 < (byte *)(lVar9 + (long)__src)) &&
           ((*(byte *)(lVar4 + 1 + (ulong)*(byte *)((long)__src + 1) * 2) & 0x20) == 0)) {
          do {
            pbVar6 = pbVar6 + 1;
            if ((byte *)(lVar9 + (long)__src) <= pbVar6) break;
          } while ((*(byte *)(lVar4 + 1 + (ulong)*pbVar6 * 2) & 0x20) == 0);
          __n = (long)pbVar6 - (long)__src;
          if (__n != 0) goto LAB_00c77d8b;
          plVar1[2] = (long)pbVar6;
          if ((byte *)plVar1[3] <= pbVar6) goto LAB_00c77dc8;
        }
        else {
          __n = 1;
LAB_00c77d8b:
          memcpy(param_2,__src,__n);
          pbVar6 = (byte *)(plVar1[2] + __n);
          param_2 = param_2 + __n;
          plVar1[2] = (long)pbVar6;
          lVar10 = lVar10 + __n;
          if ((byte *)plVar1[3] <= pbVar6) goto LAB_00c77dc8;
        }
        uVar7 = (ulong)*pbVar6;
        uVar11 = (uint)*pbVar6;
        if (lVar12 + -1 <= lVar10) break;
      } while( true );
    }
    local_68 = param_2;
    if (uVar11 == 0xffffffff) goto LAB_00c77de4;
LAB_00c77cdc:
    *param_2 = '\0';
    lVar4 = *(long *)param_1;
    *(undefined8 *)(param_1 + *(long *)(lVar4 + -0x18) + 0x10) = 0;
    if (lVar10 != 0) goto LAB_00c77d14;
    uVar11 = 4;
  }
  goto LAB_00c77d05;
LAB_00c77dc8:
                    /* try { // try from 00c77dce to 00c77dde has its CatchHandler @ 00c77e4d */
  uVar7 = (**(code **)(*plVar1 + 0x48))(plVar1);
  goto LAB_00c77c18;
LAB_00c77de4:
  *local_68 = '\0';
  lVar4 = *(long *)param_1;
  uVar11 = (-(uint)(lVar10 == 0) & 4) + 2;
  *(undefined8 *)(param_1 + *(long *)(lVar4 + -0x18) + 0x10) = 0;
LAB_00c77d05:
  ios::s_basic_ios__clear_c1bf70
            ((ios *)(param_1 + *(long *)(lVar4 + -0x18)),
             uVar11 | *(uint *)((ios *)(param_1 + *(long *)(lVar4 + -0x18)) + 0x20));
LAB_00c77d14:
  if (local_40 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_1;
}


// ==== entry=00c77e60 orig=FUN_00c77e60 size=842 name=getline ====

/* std::wistream::getline(wchar_t*, long, wchar_t) */

wistream * __thiscall
std::wistream::getline(wistream *this,wchar_t *param_1,long param_2,wchar_t param_3)

{
  size_t sVar1;
  long lVar2;
  long *plVar3;
  wchar_t wVar4;
  wchar_t *pwVar5;
  size_t __n;
  uint uVar6;
  long lVar7;
  wchar_t *pwVar8;
  wchar_t *pwVar9;
  long in_FS_OFFSET;
  sentry local_41;
  long local_40;
  
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  *(undefined8 *)(this + 8) = 0;
  sentry::sentry(&local_41,this,true);
  if (local_41 == (sentry)0x0) {
    lVar2 = *(long *)(this + 8);
    if (0 < param_2) {
      *param_1 = L'\0';
    }
joined_r0x00c78043:
    if (lVar2 == 0) {
      uVar6 = 4;
LAB_00c77ed0:
      wios::s_basic_ios__clear_c1c9b0
                ((wios *)(this + *(long *)(*(long *)this + -0x18)),
                 uVar6 | *(uint *)((wios *)(this + *(long *)(*(long *)this + -0x18)) + 0x20));
    }
    if (local_40 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
      __stack_chk_fail();
    }
    return this;
  }
  plVar3 = *(long **)(this + *(long *)(*(long *)this + -0x18) + 0xe8);
  if ((wchar_t *)plVar3[2] < (wchar_t *)plVar3[3]) {
    wVar4 = *(wchar_t *)plVar3[2];
  }
  else {
                    /* try { // try from 00c780e7 to 00c780e9 has its CatchHandler @ 00c781d7 */
    wVar4 = (**(code **)(*plVar3 + 0x48))(plVar3);
  }
  do {
    lVar7 = *(long *)(this + 8);
joined_r0x00c77f1c:
    lVar2 = lVar7 + 1;
    if (param_2 <= lVar2) {
      if (wVar4 == L'\xffffffff') {
        if (0 < param_2) {
          *param_1 = L'\0';
          uVar6 = (-(uint)(lVar7 == 0) & 4) + 2;
          goto LAB_00c77ed0;
        }
        uVar6 = 2;
      }
      else {
        if (param_3 == wVar4) {
          pwVar8 = (wchar_t *)plVar3[3];
          pwVar9 = (wchar_t *)plVar3[2];
          goto LAB_00c78018;
        }
        if (0 < param_2) {
          *param_1 = L'\0';
          uVar6 = 4;
          goto LAB_00c77ed0;
        }
        uVar6 = 4;
      }
LAB_00c7810a:
      if (lVar7 == 0) {
        uVar6 = uVar6 | 4;
      }
      goto LAB_00c77ed0;
    }
    if (wVar4 == L'\xffffffff') {
LAB_00c780f8:
      uVar6 = 2;
      if (0 < param_2) {
        *param_1 = L'\0';
      }
      goto LAB_00c7810a;
    }
    pwVar8 = (wchar_t *)plVar3[3];
    pwVar9 = (wchar_t *)plVar3[2];
    if (param_3 == wVar4) {
LAB_00c78018:
      *(long *)(this + 8) = lVar2;
      if (pwVar9 < pwVar8) {
        plVar3[2] = (long)(pwVar9 + 1);
        if (0 < param_2) {
          *param_1 = L'\0';
        }
      }
      else {
                    /* try { // try from 00c78174 to 00c78176 has its CatchHandler @ 00c781cd */
        (**(code **)(*plVar3 + 0x50))(plVar3);
        lVar2 = *(long *)(this + 8);
        if (0 < param_2) {
          *param_1 = L'\0';
        }
      }
      goto joined_r0x00c78043;
    }
    sVar1 = (param_2 - lVar7) - 1;
    __n = (long)pwVar8 - (long)pwVar9 >> 2;
    if ((long)sVar1 <= (long)__n) {
      __n = sVar1;
    }
    if ((long)__n < 2) {
      *param_1 = wVar4;
      param_1 = param_1 + 1;
      *(long *)(this + 8) = lVar2;
      if (pwVar9 < pwVar8) {
        wVar4 = *pwVar9;
        plVar3[2] = (long)(pwVar9 + 1);
      }
      else {
                    /* try { // try from 00c78127 to 00c78149 has its CatchHandler @ 00c781d2 */
        wVar4 = (**(code **)(*plVar3 + 0x50))(plVar3);
      }
      if (wVar4 == L'\xffffffff') {
        lVar7 = *(long *)(this + 8);
        goto LAB_00c780f8;
      }
      if ((wchar_t *)plVar3[2] < (wchar_t *)plVar3[3]) {
        wVar4 = *(wchar_t *)plVar3[2];
        lVar7 = *(long *)(this + 8);
      }
      else {
        wVar4 = (**(code **)(*plVar3 + 0x48))(plVar3);
        lVar7 = *(long *)(this + 8);
      }
      goto joined_r0x00c77f1c;
    }
    pwVar5 = wmemchr(pwVar9,param_3,__n);
    if ((pwVar5 == (wchar_t *)0x0) || (__n = (long)pwVar5 - (long)pwVar9 >> 2, __n != 0)) {
      wmemcpy(param_1,pwVar9,__n);
      lVar7 = *(long *)(this + 8);
      pwVar8 = (wchar_t *)plVar3[3];
      pwVar9 = (wchar_t *)plVar3[2];
    }
    lVar7 = lVar7 + __n;
    param_1 = param_1 + __n;
    pwVar9 = pwVar9 + __n;
    plVar3[2] = (long)pwVar9;
    *(long *)(this + 8) = lVar7;
    if (pwVar9 < pwVar8) {
      wVar4 = *pwVar9;
      goto joined_r0x00c77f1c;
    }
                    /* try { // try from 00c780d7 to 00c780d9 has its CatchHandler @ 00c781c8 */
    wVar4 = (**(code **)(*plVar3 + 0x48))(plVar3);
  } while( true );
}


// ==== entry=00c781e0 orig=FUN_00c781e0 size=808 name=ignore ====

/* std::wistream::ignore(long, unsigned int) */

wistream * __thiscall std::wistream::ignore(wistream *this,long param_1,uint param_2)

{
  long *plVar1;
  wchar_t *pwVar2;
  wchar_t *pwVar3;
  wchar_t wVar4;
  wchar_t *pwVar5;
  long lVar6;
  size_t __n;
  sentry sVar7;
  long in_FS_OFFSET;
  sentry local_41;
  long local_40;
  
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  if (param_2 == 0xffffffff) {
    this = (wistream *)ignore(this,param_1);
  }
  else {
    *(undefined8 *)(this + 8) = 0;
    sentry::sentry(&local_41,this,true);
    if ((0 < param_1) && (local_41 != (sentry)0x0)) {
      plVar1 = *(long **)(this + *(long *)(*(long *)this + -0x18) + 0xe8);
      if ((wchar_t *)plVar1[2] < (wchar_t *)plVar1[3]) {
        wVar4 = *(wchar_t *)plVar1[2];
      }
      else {
        wVar4 = (**(code **)(*plVar1 + 0x48))(plVar1);
      }
      lVar6 = *(long *)(this + 8);
      sVar7 = (sentry)0x0;
joined_r0x00c78273:
      while (lVar6 < param_1) {
        if (wVar4 == L'\xffffffff') {
LAB_00c783c0:
          if (param_1 == 0x7fffffffffffffff) goto LAB_00c784c0;
          if (sVar7 != (sentry)0x0) {
            *(undefined8 *)(this + 8) = 0x7fffffffffffffff;
          }
          goto LAB_00c783dc;
        }
        if (wVar4 == param_2) {
          if (param_1 != 0x7fffffffffffffff) {
            if (sVar7 == (sentry)0x0) goto LAB_00c78434;
            goto LAB_00c78418;
          }
          if (sVar7 != (sentry)0x0) goto LAB_00c78418;
          goto LAB_00c78450;
        }
        pwVar2 = (wchar_t *)plVar1[3];
        pwVar3 = (wchar_t *)plVar1[2];
        __n = (long)pwVar2 - (long)pwVar3 >> 2;
        if (param_1 - lVar6 < (long)__n) {
          __n = param_1 - lVar6;
        }
        if ((long)__n < 2) {
          *(long *)(this + 8) = lVar6 + 1;
          if (pwVar3 < pwVar2) {
            wVar4 = *pwVar3;
            plVar1[2] = (long)(pwVar3 + 1);
          }
          else {
            wVar4 = (**(code **)(*plVar1 + 0x50))(plVar1);
          }
          if (wVar4 == L'\xffffffff') goto LAB_00c783c0;
          if ((wchar_t *)plVar1[3] <= (wchar_t *)plVar1[2]) goto LAB_00c784e0;
          wVar4 = *(wchar_t *)plVar1[2];
          lVar6 = *(long *)(this + 8);
        }
        else {
          pwVar5 = wmemchr(pwVar3,param_2,__n);
          if (pwVar5 != (wchar_t *)0x0) {
            __n = (long)pwVar5 - (long)pwVar3 >> 2;
          }
          pwVar3 = pwVar3 + __n;
          lVar6 = lVar6 + __n;
          plVar1[2] = (long)pwVar3;
          *(long *)(this + 8) = lVar6;
          if (pwVar3 < pwVar2) {
            wVar4 = *pwVar3;
          }
          else {
LAB_00c784e0:
                    /* try { // try from 00c784e7 to 00c7850b has its CatchHandler @ 00c7853d */
            wVar4 = (**(code **)(*plVar1 + 0x48))(plVar1);
            lVar6 = *(long *)(this + 8);
          }
        }
      }
      if (param_1 != 0x7fffffffffffffff) {
        if (sVar7 == (sentry)0x0) goto LAB_00c78426;
        goto LAB_00c78418;
      }
      if (wVar4 == L'\xffffffff') {
LAB_00c784c0:
        if (sVar7 != (sentry)0x0) {
          *(undefined8 *)(this + 8) = 0x7fffffffffffffff;
        }
        goto LAB_00c783dc;
      }
      if (wVar4 != param_2) {
        *(undefined8 *)(this + 8) = 0x8000000000000000;
        lVar6 = -0x8000000000000000;
        sVar7 = local_41;
        goto joined_r0x00c78273;
      }
      if (sVar7 != (sentry)0x0) {
LAB_00c78418:
        *(undefined8 *)(this + 8) = 0x7fffffffffffffff;
LAB_00c78426:
        if (wVar4 == L'\xffffffff') {
LAB_00c783dc:
          wios::s_basic_ios__clear_c1c9b0
                    ((wios *)(this + *(long *)(*(long *)this + -0x18)),
                     *(uint *)((wios *)(this + *(long *)(*(long *)this + -0x18)) + 0x20) | 2);
          goto LAB_00c78383;
        }
        if (param_2 != wVar4) goto LAB_00c78383;
LAB_00c78434:
        lVar6 = *(long *)(this + 8);
      }
      if (lVar6 != 0x7fffffffffffffff) {
LAB_00c78450:
        *(long *)(this + 8) = lVar6 + 1;
      }
      if ((ulong)plVar1[2] < (ulong)plVar1[3]) {
        plVar1[2] = plVar1[2] + 4;
      }
      else {
                    /* try { // try from 00c78375 to 00c78377 has its CatchHandler @ 00c7853d */
        (**(code **)(*plVar1 + 0x50))(plVar1);
      }
    }
  }
LAB_00c78383:
  if (local_40 == *(long *)(in_FS_OFFSET + 0x28)) {
    return this;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ==== entry=00c78550 orig=FUN_00c78550 size=578 name=do_out ====

/* std::codecvt<wchar_t, char, __mbstate_t>::do_out(__mbstate_t&, wchar_t const*, wchar_t const*,
   wchar_t const*&, char*, char*, char*&) const */

int __thiscall
std::codecvt<wchar_t,char,__mbstate_t>::do_out
          (codecvt<wchar_t,char,__mbstate_t> *this,__mbstate_t *param_1,wchar_t *param_2,
          wchar_t *param_3,wchar_t **param_4,char *param_5,char *param_6,char **param_7)

{
  wchar_t __wc;
  undefined8 uVar1;
  wchar_t *pwVar2;
  int iVar3;
  size_t sVar4;
  wchar_t *pwVar5;
  char *pcVar6;
  long in_FS_OFFSET;
  __mbstate_t local_60;
  char local_58 [24];
  long local_40;
  
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  local_60 = *param_1;
  uVar1 = __uselocale(*(undefined8 *)(this + 0x10));
  *param_4 = param_2;
  iVar3 = 0;
  *param_7 = param_5;
joined_r0x00c785d1:
  do {
    if (((param_3 <= param_2) || (pcVar6 = *param_7, param_6 <= pcVar6)) || (iVar3 != 0)) {
LAB_00c78670:
      __uselocale(uVar1);
      if (local_40 == *(long *)(in_FS_OFFSET + 0x28)) {
        return iVar3;
      }
                    /* WARNING: Subroutine does not return */
      __stack_chk_fail();
    }
    while( true ) {
      sVar4 = (long)param_3 - (long)param_2 >> 2;
      pwVar2 = wmemchr(param_2,L'\0',sVar4);
      pwVar5 = param_3;
      if (pwVar2 != (wchar_t *)0x0) {
        sVar4 = (long)pwVar2 - (long)param_2 >> 2;
        pwVar5 = pwVar2;
      }
      sVar4 = wcsnrtombs(pcVar6,param_4,sVar4,(long)param_6 - (long)pcVar6,param_1);
      if (sVar4 == 0xffffffffffffffff) break;
      param_2 = *param_4;
      pcVar6 = *param_7;
      if ((param_2 != (wchar_t *)0x0) && (param_2 < pwVar5)) {
        *param_7 = pcVar6 + sVar4;
        iVar3 = 1;
        goto joined_r0x00c785d1;
      }
      *param_4 = pwVar5;
      *param_7 = pcVar6 + sVar4;
      if (param_3 <= pwVar5) goto LAB_00c78700;
      local_60 = *param_1;
      sVar4 = wcrtomb(local_58,*pwVar5,&local_60);
      if ((ulong)((long)param_6 - (long)*param_7) < sVar4) {
        iVar3 = 1;
        goto LAB_00c78670;
      }
      memcpy(*param_7,local_58,sVar4);
      *param_1 = local_60;
      pcVar6 = *param_7 + sVar4;
      param_2 = *param_4 + 1;
      *param_7 = pcVar6;
      *param_4 = param_2;
      if ((param_3 <= param_2) || (param_6 <= pcVar6)) {
        iVar3 = 0;
        goto LAB_00c78670;
      }
    }
    if (param_2 < *param_4) {
      pcVar6 = *param_7;
      do {
        __wc = *param_2;
        param_2 = param_2 + 1;
        sVar4 = wcrtomb(pcVar6,__wc,&local_60);
        pcVar6 = *param_7 + sVar4;
        *param_7 = pcVar6;
      } while (param_2 < *param_4);
    }
    iVar3 = 2;
    *param_1 = local_60;
    param_2 = *param_4;
  } while( true );
LAB_00c78700:
  iVar3 = 0;
  param_2 = pwVar5;
  goto joined_r0x00c785d1;
}


// ==== entry=00c787b0 orig=FUN_00c787b0 size=531 name=do_in ====

/* std::codecvt<wchar_t, char, __mbstate_t>::do_in(__mbstate_t&, char const*, char const*, char
   const*&, wchar_t*, wchar_t*, wchar_t*&) const */

int __thiscall
std::codecvt<wchar_t,char,__mbstate_t>::do_in
          (codecvt<wchar_t,char,__mbstate_t> *this,__mbstate_t *param_1,char *param_2,char *param_3,
          char **param_4,wchar_t *param_5,wchar_t *param_6,wchar_t **param_7)

{
  wchar_t *pwVar1;
  undefined8 uVar2;
  char *pcVar3;
  int iVar4;
  wchar_t *pwVar5;
  size_t sVar6;
  char *pcVar7;
  long in_FS_OFFSET;
  __mbstate_t local_48;
  long local_40;
  
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  local_48 = *param_1;
  uVar2 = __uselocale(*(undefined8 *)(this + 0x10));
  *param_4 = param_2;
  iVar4 = 0;
  *param_7 = param_5;
joined_r0x00c78828:
  do {
    if (((param_3 <= param_2) || (pwVar5 = *param_7, param_6 <= pwVar5)) || (iVar4 != 0)) {
LAB_00c788c8:
      __uselocale(uVar2);
      if (local_40 == *(long *)(in_FS_OFFSET + 0x28)) {
        return iVar4;
      }
                    /* WARNING: Subroutine does not return */
      __stack_chk_fail();
    }
    while( true ) {
      sVar6 = (long)param_3 - (long)param_2;
      pcVar3 = memchr(param_2,0,sVar6);
      pcVar7 = param_3;
      if (pcVar3 != (char *)0x0) {
        sVar6 = (long)pcVar3 - (long)param_2;
        pcVar7 = pcVar3;
      }
      sVar6 = mbsnrtowcs(pwVar5,param_4,sVar6,(long)param_6 - (long)pwVar5 >> 2,param_1);
      if (sVar6 == 0xffffffffffffffff) break;
      param_2 = *param_4;
      pwVar1 = *param_7 + sVar6;
      if ((param_2 < pcVar7) && (param_2 != (char *)0x0)) {
        *param_7 = pwVar1;
        iVar4 = 1;
        goto joined_r0x00c78828;
      }
      *param_4 = pcVar7;
      *param_7 = pwVar1;
      if (param_3 <= pcVar7) goto LAB_00c78960;
      if (param_6 <= pwVar1) {
        iVar4 = 1;
        goto LAB_00c788c8;
      }
      param_2 = pcVar7 + 1;
      pwVar5 = pwVar1 + 1;
      local_48 = *param_1;
      *param_4 = param_2;
      *param_7 = pwVar5;
      *pwVar1 = L'\0';
      if ((param_3 <= param_2) || (param_6 <= pwVar5)) {
        iVar4 = 0;
        goto LAB_00c788c8;
      }
    }
    pwVar5 = *param_7;
    while (sVar6 = mbrtowc(pwVar5,param_2,(long)param_3 - (long)param_2,&local_48), 1 < sVar6 + 2) {
      param_2 = param_2 + sVar6;
      pwVar5 = *param_7 + 1;
      *param_7 = pwVar5;
    }
    *param_4 = param_2;
    iVar4 = 2;
    *param_1 = local_48;
    param_2 = *param_4;
  } while( true );
LAB_00c78960:
  iVar4 = 0;
  param_2 = pcVar7;
  goto joined_r0x00c78828;
}


// ==== entry=00c789e0 orig=FUN_00c789e0 size=50 name=do_encoding ====

/* std::codecvt<wchar_t, char, __mbstate_t>::do_encoding() const */

bool __thiscall
std::codecvt<wchar_t,char,__mbstate_t>::do_encoding(codecvt<wchar_t,char,__mbstate_t> *this)

{
  undefined8 uVar1;
  size_t sVar2;
  
  uVar1 = __uselocale(*(undefined8 *)(this + 0x10));
  sVar2 = __ctype_get_mb_cur_max();
  __uselocale(uVar1);
  return sVar2 == 1;
}


// ==== entry=00c78a20 orig=FUN_00c78a20 size=43 name=do_max_length ====

/* std::codecvt<wchar_t, char, __mbstate_t>::do_max_length() const */

ulong __thiscall
std::codecvt<wchar_t,char,__mbstate_t>::do_max_length(codecvt<wchar_t,char,__mbstate_t> *this)

{
  undefined8 uVar1;
  size_t sVar2;
  
  uVar1 = __uselocale(*(undefined8 *)(this + 0x10));
  sVar2 = __ctype_get_mb_cur_max();
  __uselocale(uVar1);
  return sVar2 & 0xffffffff;
}


// ==== entry=00c78a50 orig=FUN_00c78a50 size=436 name=do_length ====

/* std::codecvt<wchar_t, char, __mbstate_t>::do_length(__mbstate_t&, char const*, char const*,
   unsigned long) const */

int __thiscall
std::codecvt<wchar_t,char,__mbstate_t>::do_length
          (codecvt<wchar_t,char,__mbstate_t> *this,__mbstate_t *param_1,char *param_2,char *param_3,
          ulong param_4)

{
  long lVar1;
  undefined8 uVar2;
  char **__src;
  wchar_t *__dst;
  __mbstate_t *__ps;
  char *__s;
  char *pcVar3;
  size_t sVar4;
  int iVar5;
  size_t sVar6;
  long in_FS_OFFSET;
  undefined8 auStack_80 [2];
  char **local_70;
  wchar_t *local_68;
  __mbstate_t *local_60;
  char *local_58;
  char *local_50;
  __mbstate_t local_48;
  long local_40;
  
  iVar5 = 0;
  local_48 = *param_1;
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  auStack_80[0] = 0xc78a91;
  local_60 = param_1;
  local_50 = param_2;
  auStack_80[1] = __uselocale(*(undefined8 *)(this + 0x10),param_1,param_2,0);
  lVar1 = -(param_4 * 4 + 0x17 & 0xfffffffffffffff0);
  local_68 = (wchar_t *)((long)&local_70 + lVar1);
  local_70 = &local_50;
  while (local_50 < param_3) {
    while( true ) {
      __s = local_50;
      if (param_4 == 0) goto LAB_00c78b78;
      sVar6 = (long)param_3 - (long)local_50;
      *(undefined8 *)((long)auStack_80 + lVar1) = 0xc78ae5;
      pcVar3 = memchr(__s,0,sVar6);
      __ps = local_60;
      __dst = local_68;
      __src = local_70;
      local_58 = param_3;
      if (pcVar3 != (char *)0x0) {
        sVar6 = (long)pcVar3 - (long)__s;
        local_58 = pcVar3;
      }
      *(undefined8 *)((long)auStack_80 + lVar1) = 0xc78b12;
      sVar4 = mbsnrtowcs(__dst,__src,sVar6,param_4,__ps);
      if (sVar4 == 0xffffffffffffffff) {
        pcVar3 = __s;
        while( true ) {
          local_50 = pcVar3;
          *(undefined8 *)((long)auStack_80 + lVar1) = 0xc78beb;
          sVar6 = mbrtowc((wchar_t *)0x0,pcVar3,(long)param_3 - (long)pcVar3,&local_48);
          if (sVar6 + 2 < 2) break;
          pcVar3 = local_50 + sVar6;
        }
        *local_60 = local_48;
        iVar5 = (iVar5 + (int)local_50) - (int)__s;
        goto LAB_00c78b78;
      }
      pcVar3 = local_58;
      if (local_50 != (char *)0x0) {
        sVar6 = (long)local_50 - (long)__s;
        pcVar3 = local_50;
      }
      local_50 = pcVar3;
      iVar5 = iVar5 + (int)sVar6;
      param_4 = param_4 - sVar4;
      if ((param_3 <= local_50) || (param_4 == 0)) break;
      local_50 = local_50 + 1;
      iVar5 = iVar5 + 1;
      param_4 = param_4 - 1;
      local_48 = *local_60;
      if (param_3 <= local_50) goto LAB_00c78b78;
    }
  }
LAB_00c78b78:
  uVar2 = auStack_80[1];
  *(undefined8 *)((long)auStack_80 + lVar1) = 0xc78b81;
  __uselocale(uVar2);
  if (local_40 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    *(undefined **)((long)auStack_80 + lVar1) = &UNK_00c78c11;
    __stack_chk_fail();
  }
  return iVar5;
}


// ==== entry=00c78c20 orig=FUN_00c78c20 size=147 name=do_open ====

/* std::messages<char>::do_open(std::string const&, std::locale const&) const */

undefined4 __thiscall
std::messages<char>::do_open(messages<char> *this,string *param_1,locale *param_2)

{
  undefined4 uVar1;
  codecvt *pcVar2;
  undefined8 uVar3;
  long in_FS_OFFSET;
  locale alStack_38 [8];
  long local_30;
  
  local_30 = *(long *)(in_FS_OFFSET + 0x28);
  pcVar2 = use_facet<std::codecvt<char,char,__mbstate_t>>(param_2);
  uVar3 = __nl_langinfo_l(0xe,*(undefined8 *)(pcVar2 + 0x10));
  bind_textdomain_codeset(*(undefined8 *)param_1,uVar3);
  uVar3 = FUN_00c76ec0();
  locale::locale(alStack_38,param_2);
                    /* try { // try from 00c78c82 to 00c78c86 has its CatchHandler @ 00c78cb3 */
  uVar1 = FUN_00c770d0(uVar3,*(undefined8 *)param_1,alStack_38);
  locale::~locale(alStack_38);
  if (local_30 == *(long *)(in_FS_OFFSET + 0x28)) {
    return uVar1;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ==== entry=00c78cc0 orig=FUN_00c78cc0 size=19 name=do_close ====

/* std::messages<wchar_t>::do_close(int) const */

void __thiscall std::messages<wchar_t>::do_close(messages<wchar_t> *this,int param_1)

{
  undefined8 uVar1;
  
  uVar1 = FUN_00c76ec0();
  FUN_00c76c50(uVar1,param_1);
  return;
}


// ==== entry=00c78ce0 orig=FUN_00c78ce0 size=196 name=do_get ====

/* std::messages<char>::do_get(int, int, int, std::string const&) const */

string * std::messages<char>::do_get(int param_1,int param_2,int param_3,string *param_4)

{
  undefined8 uVar1;
  undefined8 uVar2;
  long lVar3;
  undefined8 uVar4;
  char *pcVar5;
  undefined4 in_register_00000034;
  undefined4 in_register_0000003c;
  string *this;
  string *in_R9;
  long in_FS_OFFSET;
  allocator local_31;
  long local_30;
  
  this = (string *)CONCAT44(in_register_0000003c,param_1);
  local_30 = *(long *)(in_FS_OFFSET + 0x28);
  if ((-1 < param_3) && (*(long *)(*(long *)in_R9 + -0x18) != 0)) {
    uVar2 = FUN_00c76ec0();
    lVar3 = FUN_00c76de0(uVar2,param_3);
    if (lVar3 != 0) {
      uVar2 = *(undefined8 *)in_R9;
      uVar1 = *(undefined8 *)(lVar3 + 8);
      uVar4 = __uselocale(*(undefined8 *)(CONCAT44(in_register_00000034,param_2) + 0x10));
      pcVar5 = (char *)dgettext(uVar1,uVar2);
      __uselocale(uVar4);
      string::string(this,pcVar5,&local_31);
      goto LAB_00c78d18;
    }
  }
  string::string(this,in_R9);
LAB_00c78d18:
  if (local_30 == *(long *)(in_FS_OFFSET + 0x28)) {
    return this;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ==== entry=00c78db0 orig=FUN_00c78db0 size=147 name=do_open ====

/* std::messages<wchar_t>::do_open(std::string const&, std::locale const&) const */

undefined4 __thiscall
std::messages<wchar_t>::do_open(messages<wchar_t> *this,string *param_1,locale *param_2)

{
  undefined4 uVar1;
  codecvt *pcVar2;
  undefined8 uVar3;
  long in_FS_OFFSET;
  locale alStack_38 [8];
  long local_30;
  
  local_30 = *(long *)(in_FS_OFFSET + 0x28);
  pcVar2 = use_facet<std::codecvt<wchar_t,char,__mbstate_t>>(param_2);
  uVar3 = __nl_langinfo_l(0xe,*(undefined8 *)(pcVar2 + 0x10));
  bind_textdomain_codeset(*(undefined8 *)param_1,uVar3);
  uVar3 = FUN_00c76ec0();
  locale::locale(alStack_38,param_2);
                    /* try { // try from 00c78e12 to 00c78e16 has its CatchHandler @ 00c78e43 */
  uVar1 = FUN_00c770d0(uVar3,*(undefined8 *)param_1,alStack_38);
  locale::~locale(alStack_38);
  if (local_30 == *(long *)(in_FS_OFFSET + 0x28)) {
    return uVar1;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ==== entry=00c78e50 orig=FUN_00c78e50 size=441 name=do_get ====

/* std::messages<wchar_t>::do_get(int, int, int, std::wstring const&) const */

wstring * std::messages<wchar_t>::do_get(int param_1,int param_2,int param_3,wstring *param_4)

{
  char *pcVar1;
  long lVar2;
  long lVar3;
  long lVar4;
  code *pcVar5;
  long lVar6;
  undefined1 *puVar7;
  codecvt *pcVar8;
  undefined8 *puVar9;
  int iVar10;
  undefined8 uVar11;
  long lVar12;
  long lVar13;
  undefined8 uVar14;
  char *__s;
  size_t sVar15;
  wchar_t *pwVar16;
  undefined1 ***pppuVar17;
  undefined4 in_register_00000034;
  undefined4 in_register_0000003c;
  wstring *this;
  wstring *in_R9;
  ulong uVar18;
  long in_FS_OFFSET;
  long alStack_a0 [3];
  undefined1 **local_88;
  undefined8 local_80;
  codecvt *local_78;
  undefined8 *local_70;
  undefined1 local_59;
  undefined1 local_58 [8];
  undefined1 *local_50;
  undefined8 local_48;
  long local_40;
  
  this = (wstring *)CONCAT44(in_register_0000003c,param_1);
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  pppuVar17 = &local_88;
  if ((-1 < param_3) && (pppuVar17 = &local_88, *(long *)(*(long *)in_R9 + -0x18) != 0)) {
    local_70 = (undefined8 *)CONCAT44(local_70._4_4_,param_3);
    alStack_a0[2] = 0xc78ec3;
    uVar11 = FUN_00c76ec0();
    alStack_a0[2] = 0xc78ed0;
    lVar12 = FUN_00c76de0(uVar11,(ulong)local_70 & 0xffffffff);
    pppuVar17 = &local_88;
    if (lVar12 != 0) {
      alStack_a0[2] = 0xc78ee1;
      local_78 = use_facet<std::codecvt<wchar_t,char,__mbstate_t>>((locale *)(lVar12 + 0x10));
      local_48 = 0;
      local_70 = &local_48;
      lVar13 = *(long *)(*(long *)in_R9 + -0x18);
      alStack_a0[2] = 0xc78f09;
      iVar10 = (**(code **)(*(long *)local_78 + 0x40))(local_78);
      puVar9 = local_70;
      pcVar8 = local_78;
      local_88 = &local_50;
      lVar13 = iVar10 * lVar13;
      lVar2 = *(long *)local_78;
      lVar6 = -(lVar13 + 0x18U & 0xfffffffffffffff0);
      lVar3 = *(long *)in_R9;
      pcVar1 = (char *)((long)&local_80 + lVar6);
      lVar4 = *(long *)(lVar3 + -0x18);
      local_80 = local_58;
      *(undefined1 ***)((long)alStack_a0 + lVar6 + 0x10) = local_88;
      *(char **)((long)alStack_a0 + lVar6 + 8) = pcVar1 + lVar13;
      pcVar5 = *(code **)(lVar2 + 0x10);
      *(undefined8 *)((long)alStack_a0 + lVar6) = 0xc78f59;
      (*pcVar5)(pcVar8,puVar9,lVar3,lVar3 + lVar4 * 4,local_58,pcVar1);
      *local_50 = 0;
      uVar11 = *(undefined8 *)(lVar12 + 8);
      uVar14 = *(undefined8 *)(CONCAT44(in_register_00000034,param_2) + 0x10);
      *(undefined8 *)((long)alStack_a0 + lVar6) = 0xc78f6d;
      uVar14 = __uselocale(uVar14);
      *(undefined8 *)((long)alStack_a0 + lVar6) = 0xc78f7b;
      __s = (char *)dgettext(uVar11,pcVar1);
      *(undefined8 *)((long)alStack_a0 + lVar6) = 0xc78f86;
      __uselocale(uVar14);
      pppuVar17 = (undefined1 ***)((long)&local_88 + lVar6);
      if (pcVar1 != __s) {
        local_48 = 0;
        *(undefined8 *)((long)alStack_a0 + lVar6 + 0x10) = 0xc78fa9;
        sVar15 = strlen(__s);
        pcVar8 = local_78;
        puVar7 = local_80;
        lVar12 = *(long *)local_78;
        lVar13 = -(sVar15 * 4 + 0x1b & 0xfffffffffffffff0);
        pppuVar17 = (undefined1 ***)((long)&local_88 + lVar13 + lVar6);
        *(undefined1 ***)((long)alStack_a0 + lVar13 + lVar6 + 0x10) = local_88;
        puVar9 = local_70;
        uVar18 = (long)&local_80 + lVar13 + lVar6 + 7 & 0xfffffffffffffff0;
        *(ulong *)((long)alStack_a0 + lVar13 + lVar6 + 8) = uVar18 + sVar15 * 4;
        pcVar5 = *(code **)(lVar12 + 0x20);
        *(undefined8 *)((long)alStack_a0 + lVar13 + lVar6) = 0xc78fee;
        (*pcVar5)(pcVar8,puVar9,__s,__s + sVar15,puVar7,uVar18);
        *(undefined8 *)((long)alStack_a0 + lVar13 + lVar6 + 0x10) = 0xc79000;
        pwVar16 = wstring::_S_construct<wchar_t*>(uVar18,local_50,&local_59);
        *(wchar_t **)this = pwVar16;
        goto LAB_00c78e8f;
      }
    }
  }
  *(undefined8 *)((long)pppuVar17 + -8) = 0xc78e8f;
  wstring::wstring(this,in_R9);
LAB_00c78e8f:
  if (local_40 == *(long *)(in_FS_OFFSET + 0x28)) {
    return this;
  }
                    /* WARNING: Subroutine does not return */
  *(undefined **)((long)pppuVar17 + -8) = &UNK_00c7900d;
  __stack_chk_fail();
}


// ==== entry=00c79010 orig=FUN_00c79010 size=267 name=__copy_streambufs_eof<char,std::char_traits<char>> ====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* long std::__copy_streambufs_eof<char, std::char_traits<char> >(std::streambuf*, std::streambuf*,
   bool&) */

long std::__copy_streambufs_eof<char,std::char_traits<char>>
               (streambuf *param_1,streambuf *param_2,bool *param_3)

{
  uint uVar1;
  int iVar2;
  long lVar3;
  long lVar4;
  byte *pbVar5;
  byte *pbVar6;
  long lVar7;
  
  pbVar6 = *(byte **)(param_1 + 0x10);
  pbVar5 = *(byte **)(param_1 + 0x18);
  *param_3 = true;
  if (pbVar6 < pbVar5) {
    uVar1 = (uint)*pbVar6;
  }
  else {
    uVar1 = (**(code **)(*(long *)param_1 + 0x48))();
    if (uVar1 == 0xffffffff) {
      return 0;
    }
    pbVar5 = *(byte **)(param_1 + 0x18);
    pbVar6 = *(byte **)(param_1 + 0x10);
  }
  lVar7 = 0;
LAB_00c79040:
  lVar4 = (long)pbVar5 - (long)pbVar6;
  if (lVar4 < 2) goto LAB_00c79085;
  do {
    lVar3 = (**(code **)(*(long *)param_2 + 0x60))(param_2,pbVar6,lVar4);
    *(long *)(param_1 + 0x10) = *(long *)(param_1 + 0x10) + lVar3;
    lVar7 = lVar7 + lVar3;
    if (lVar3 < lVar4) {
LAB_00c790f1:
      *param_3 = false;
      return lVar7;
    }
    while( true ) {
      uVar1 = (**(code **)(*(long *)param_1 + 0x48))(param_1);
      if (uVar1 == 0xffffffff) {
        return lVar7;
      }
      pbVar6 = *(byte **)(param_1 + 0x10);
      lVar4 = *(long *)(param_1 + 0x18) - (long)pbVar6;
      if (1 < lVar4) break;
LAB_00c79085:
      if (*(undefined1 **)(param_2 + 0x28) < *(undefined1 **)(param_2 + 0x30)) {
        **(undefined1 **)(param_2 + 0x28) = (char)uVar1;
        *(long *)(param_2 + 0x28) = *(long *)(param_2 + 0x28) + 1;
      }
      else {
        iVar2 = (**(code **)(*(long *)param_2 + 0x68))(param_2,uVar1 & 0xff);
        if (iVar2 == -1) goto LAB_00c790f1;
      }
      pbVar5 = *(byte **)(param_1 + 0x18);
      lVar7 = lVar7 + 1;
      if (*(byte **)(param_1 + 0x10) < pbVar5) {
        pbVar6 = *(byte **)(param_1 + 0x10) + 1;
        *(byte **)(param_1 + 0x10) = pbVar6;
      }
      else {
        iVar2 = (**(code **)(*(long *)param_1 + 0x50))(param_1);
        if (iVar2 == -1) {
          return lVar7;
        }
        pbVar6 = *(byte **)(param_1 + 0x10);
        pbVar5 = *(byte **)(param_1 + 0x18);
      }
      if (pbVar6 < pbVar5) {
        uVar1 = (uint)*pbVar6;
        goto LAB_00c79040;
      }
    }
  } while( true );
}


// ==== entry=00c79130 orig=FUN_00c79130 size=253 name=__copy_streambufs_eof<wchar_t,std::char_traits<wchar_t>> ====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* long std::__copy_streambufs_eof<wchar_t, std::char_traits<wchar_t> >(std::wstreambuf*,
   std::wstreambuf*, bool&) */

long std::__copy_streambufs_eof<wchar_t,std::char_traits<wchar_t>>
               (wstreambuf *param_1,wstreambuf *param_2,bool *param_3)

{
  int *piVar1;
  long lVar2;
  long lVar3;
  int iVar4;
  long lVar5;
  long lVar6;
  
  piVar1 = *(int **)(param_1 + 0x10);
  *param_3 = true;
  if (piVar1 < *(int **)(param_1 + 0x18)) {
    iVar4 = *piVar1;
  }
  else {
    iVar4 = (**(code **)(*(long *)param_1 + 0x48))();
  }
  lVar6 = 0;
joined_r0x00c7915a:
  do {
    if (iVar4 == -1) {
      return lVar6;
    }
    lVar2 = *(long *)(param_1 + 0x10);
    lVar3 = *(long *)(param_1 + 0x18);
    if (lVar3 - lVar2 < 5) {
      piVar1 = *(int **)(param_2 + 0x28);
      if (piVar1 < *(int **)(param_2 + 0x30)) {
        *piVar1 = iVar4;
        *(int **)(param_2 + 0x28) = piVar1 + 1;
      }
      else {
        iVar4 = (**(code **)(*(long *)param_2 + 0x68))(param_2,iVar4);
        if (iVar4 == -1) goto LAB_00c79210;
      }
      lVar6 = lVar6 + 1;
      piVar1 = *(int **)(param_1 + 0x10);
      if (piVar1 < *(int **)(param_1 + 0x18)) {
        iVar4 = *piVar1;
        *(int **)(param_1 + 0x10) = piVar1 + 1;
      }
      else {
        iVar4 = (**(code **)(*(long *)param_1 + 0x50))(param_1);
      }
      if (iVar4 == -1) {
        return lVar6;
      }
      if (*(int **)(param_1 + 0x10) < *(int **)(param_1 + 0x18)) {
        iVar4 = **(int **)(param_1 + 0x10);
        goto joined_r0x00c7915a;
      }
    }
    else {
      lVar5 = (**(code **)(*(long *)param_2 + 0x60))(param_2);
      lVar6 = lVar6 + lVar5;
      *(long *)(param_1 + 0x10) = *(long *)(param_1 + 0x10) + lVar5 * 4;
      if (lVar5 < lVar3 - lVar2 >> 2) {
LAB_00c79210:
        *param_3 = false;
        return lVar6;
      }
    }
    iVar4 = (**(code **)(*(long *)param_1 + 0x48))(param_1);
  } while( true );
}


// ==== entry=00c79240 name=FUN_00c79240 size=20 ====

void FUN_00c79240(long *param_1)

{
  param_1[1] = 0;
  *param_1 = (long)(param_1 + 2);
  *(undefined1 *)(param_1 + 2) = 0;
  return;
}


// ==== entry=00c79260 name=FUN_00c79260 size=25 ====

void FUN_00c79260(long *param_1,long *param_2)

{
  *param_1 = (long)(param_1 + 2);
  std::__cxx11::string::_M_construct<char*>(param_1,*param_2,param_2[1] + *param_2);
  return;
}


// ==== entry=00c79280 name=FUN_00c79280 size=15 ====

void FUN_00c79280(long *param_1,long param_2,long param_3)

{
  *param_1 = (long)(param_1 + 2);
  std::__cxx11::string::_M_construct<char_const*>(param_1,param_2,param_3 + param_2);
  return;
}


// ==== entry=00c79290 name=FUN_00c79290 size=25 ====

void FUN_00c79290(long *param_1,long *param_2)

{
  *param_1 = (long)(param_1 + 2);
  std::__cxx11::string::_M_construct<char*>(param_1,*param_2,param_2[1] + *param_2);
  return;
}


// ==== entry=00c792b0 name=FUN_00c792b0 size=14 ====

string * FUN_00c792b0(string *param_1)

{
  std::__cxx11::string::_M_assign(param_1);
  return param_1;
}


// ==== entry=00c792c0 name=FUN_00c792c0 size=21 ====

void FUN_00c792c0(undefined8 *param_1)

{
  if ((undefined8 *)*param_1 != param_1 + 2) {
    operator_delete((undefined8 *)*param_1);
    return;
  }
  return;
}


// ==== entry=00c792e0 name=FUN_00c792e0 size=65 ====

void FUN_00c792e0(long *param_1,long *param_2)

{
  long lVar1;
  
  *param_1 = (long)(param_1 + 2);
  if ((long *)*param_2 == param_2 + 2) {
    lVar1 = param_2[3];
    param_1[2] = param_2[2];
    param_1[3] = lVar1;
  }
  else {
    *param_1 = *param_2;
    param_1[2] = param_2[2];
  }
  param_1[1] = param_2[1];
  *param_2 = (long)(param_2 + 2);
  param_2[1] = 0;
  *(undefined1 *)(param_2 + 2) = 0;
  return;
}


// ==== entry=00c79330 name=FUN_00c79330 size=182 ====

undefined8 * FUN_00c79330(undefined8 *param_1,undefined8 *param_2)

{
  undefined8 *__src;
  undefined8 uVar1;
  size_t __n;
  long lVar2;
  undefined8 *puVar3;
  undefined8 *__dest;
  
  puVar3 = param_2 + 2;
  __src = (undefined8 *)*param_2;
  __dest = (undefined8 *)*param_1;
  if (__src == puVar3) {
    __n = param_2[1];
    lVar2 = 0;
    if (__n != 0) {
      if (__n == 1) {
        *(undefined1 *)__dest = *(undefined1 *)(param_2 + 2);
        lVar2 = param_2[1];
        __dest = (undefined8 *)*param_1;
      }
      else {
        memcpy(__dest,__src,__n);
        lVar2 = param_2[1];
        __dest = (undefined8 *)*param_1;
      }
    }
    param_1[1] = lVar2;
    *(undefined1 *)((long)__dest + lVar2) = 0;
    puVar3 = (undefined8 *)*param_2;
  }
  else {
    if (__dest == param_1 + 2) {
      *param_1 = __src;
      param_1[1] = param_2[1];
      param_1[2] = param_2[2];
    }
    else {
      *param_1 = __src;
      uVar1 = param_1[2];
      param_1[1] = param_2[1];
      param_1[2] = param_2[2];
      if (__dest != (undefined8 *)0x0) {
        *param_2 = __dest;
        param_2[2] = uVar1;
        puVar3 = __dest;
        goto LAB_00c79378;
      }
    }
    *param_2 = puVar3;
  }
LAB_00c79378:
  param_2[1] = 0;
  *(undefined1 *)puVar3 = 0;
  return param_1;
}


// ==== entry=00c793f0 orig=FUN_00c793f0 size=8 name=BSim_std::__is_constant_evaluated ====

/* BSim sim=0.9999999999999998 sig=8.22891889426856
   ref=libsplitter.so.1.0.0::std::__is_constant_evaluated */

char * BSim_std____is_constant_evaluated(void)

{
  return "iostream";
}


// ==== entry=00c79400 name=FUN_00c79400 size=15 ====

void FUN_00c79400(error_category *param_1)

{
  *(undefined ***)param_1 = &PTR_FUN_011b7e50;
  std::_V2::error_category::~error_category(param_1);
  return;
}


// ==== entry=00c79410 name=FUN_00c79410 size=28 ====

void FUN_00c79410(error_category *param_1)

{
  *(undefined ***)param_1 = &PTR_FUN_011b7e50;
  std::_V2::error_category::~error_category(param_1);
  operator_delete(param_1);
  return;
}


// ==== entry=00c79430 name=FUN_00c79430 size=19 ====

void FUN_00c79430(system_error *param_1)

{
  *(undefined ***)param_1 = &PTR_FUN_011b7ea0;
  std::system_error::~system_error(param_1);
  return;
}


// ==== entry=00c79450 name=FUN_00c79450 size=18 ====

void FUN_00c79450(void *param_1)

{
  FUN_00c79430();
  operator_delete(param_1);
  return;
}


// ==== entry=00c79470 orig=FUN_00c79470 size=5 name=what ====

undefined8 __thiscall std::runtime_error::what(runtime_error *this)

{
  return *(undefined8 *)(this + 8);
}


// ==== entry=00c79480 name=FUN_00c79480 size=19 ====

void FUN_00c79480(__si_class_type_info *param_1)

{
  *(undefined ***)param_1 = &PTR_FUN_011b7ef0;
  __cxxabiv1::__si_class_type_info::~__si_class_type_info(param_1);
  return;
}


// ==== entry=00c794a0 name=FUN_00c794a0 size=18 ====

void FUN_00c794a0(void *param_1)

{
  FUN_00c79480();
  operator_delete(param_1);
  return;
}


// ==== entry=00c794c0 name=FUN_00c794c0 size=52 ====

void FUN_00c794c0(__class_type_info *param_1,__class_type_info *param_2,void **param_3)

{
  char cVar1;
  
  cVar1 = FUN_00c7a660(param_2);
  if (cVar1 != '\0') {
    *param_3 = (void *)((long)*param_3 + 0x20);
    return;
  }
  __cxxabiv1::__class_type_info::__do_upcast(param_1,param_2,param_3);
  return;
}


// ==== entry=00c79500 name=FUN_00c79500 size=37 ====

void FUN_00c79500(undefined8 *param_1)

{
  *param_1 = &PTR_FUN_011b7ec8;
  FUN_00c7a650();
  FUN_00c79430(param_1);
  return;
}


// ==== entry=00c79530 name=FUN_00c79530 size=45 ====

void FUN_00c79530(undefined8 *param_1)

{
  *param_1 = &PTR_FUN_011b7ec8;
  FUN_00c7a650();
  FUN_00c79430(param_1);
  operator_delete(param_1);
  return;
}


// ==== entry=00c79560 name=FUN_00c79560 size=91 ====

long * FUN_00c79560(long *param_1,undefined8 param_2,int param_3)

{
  *param_1 = (long)(param_1 + 2);
  param_1[1] = 0;
  *(undefined1 *)(param_1 + 2) = 0;
  if (param_3 != 1) {
                    /* try { // try from 00c79590 to 00c795b5 has its CatchHandler @ 00c795be */
    std::__cxx11::string::_M_replace((ulong)param_1,0,(char *)0x0,0xd991df);
    return param_1;
  }
  std::__cxx11::string::_M_replace((ulong)param_1,0,(char *)0x0,0xd991d0);
  return param_1;
}


// ==== entry=00c795d0 name=FUN_00c795d0 size=101 ====

undefined ** FUN_00c795d0(void)

{
  int iVar1;
  
  if (DAT_011c6708 != '\0') {
    return &PTR_PTR_011c0ab8;
  }
  iVar1 = __cxa_guard_acquire(&DAT_011c6708);
  if (iVar1 == 0) {
    return &PTR_PTR_011c0ab8;
  }
  __cxa_guard_release(&DAT_011c6708);
  __cxa_atexit(FUN_00c79400,&PTR_PTR_011c0ab8,&DAT_00c89008);
  return &PTR_PTR_011c0ab8;
}


// ==== entry=00c79650 orig=FUN_00c79650 size=554 name=s_basic_string__append_c79650 ====

void s_basic_string__append_c79650(undefined8 *param_1,long *param_2)

{
  long *plVar1;
  long *plVar2;
  ulong uVar3;
  long in_FS_OFFSET;
  ulong *local_98;
  long local_90;
  ulong local_88 [2];
  undefined1 *local_78;
  long local_70;
  undefined1 local_68;
  undefined7 uStack_67;
  long *local_58;
  long local_50;
  long local_48;
  long lStack_40;
  long local_30;
  
  local_30 = *(long *)(in_FS_OFFSET + 0x28);
  plVar1 = (long *)FUN_00c795d0();
  if (*(code **)(*plVar1 + 0x20) == FUN_00c79560) {
    local_78 = &local_68;
    local_70 = 0;
    local_68 = 0;
                    /* try { // try from 00c796c1 to 00c796c5 has its CatchHandler @ 00c798a3 */
    std::__cxx11::string::_M_replace((ulong)&local_78,0,(char *)0x0,0xd991d0);
  }
  else {
    (**(code **)(*plVar1 + 0x20))(&local_78,plVar1,1);
  }
  local_98 = local_88;
                    /* try { // try from 00c796e0 to 00c796e4 has its CatchHandler @ 00c79893 */
  std::__cxx11::string::_M_construct<char*>(&local_98,*param_2,param_2[1] + *param_2);
  if (0x7fffffffffffffffU - local_90 < 2) {
                    /* WARNING: Subroutine does not return */
                    /* try { // try from 00c7988e to 00c79892 has its CatchHandler @ 00c798b3 */
    std::__throw_length_error("basic_string::append");
  }
                    /* try { // try from 00c7970d to 00c79711 has its CatchHandler @ 00c798b3 */
  std::__cxx11::string::_M_append((char *)&local_98,0xc8ae07);
  if (local_98 == local_88) {
    local_88[0] = 0xf;
  }
  if (local_88[0] < (ulong)(local_90 + local_70)) {
    if (local_78 == &local_68) {
      uVar3 = 0xf;
    }
    else {
      uVar3 = CONCAT71(uStack_67,local_68);
    }
    if ((ulong)(local_90 + local_70) <= uVar3) {
                    /* try { // try from 00c7982f to 00c79833 has its CatchHandler @ 00c7989b */
      plVar2 = (long *)std::__cxx11::string::_M_replace
                                 ((ulong)&local_78,0,(char *)0x0,(ulong)local_98);
      goto LAB_00c79763;
    }
  }
                    /* try { // try from 00c7975e to 00c79762 has its CatchHandler @ 00c7989b */
  plVar2 = (long *)std::__cxx11::string::_M_append((char *)&local_98,(ulong)local_78);
LAB_00c79763:
  local_58 = &local_48;
  if ((long *)*plVar2 == plVar2 + 2) {
    local_48 = plVar2[2];
    lStack_40 = plVar2[3];
  }
  else {
    local_48 = plVar2[2];
    local_58 = (long *)*plVar2;
  }
  local_50 = plVar2[1];
  *(undefined1 *)(plVar2 + 2) = 0;
  *plVar2 = (long)(plVar2 + 2);
  plVar2[1] = 0;
                    /* try { // try from 00c797ae to 00c797b2 has its CatchHandler @ 00c798ab */
  FUN_00c716a0(param_1,&local_58);
  if (local_58 != &local_48) {
    operator_delete(local_58);
  }
  if (local_98 != local_88) {
    operator_delete(local_98);
  }
  if (local_78 != &local_68) {
    operator_delete(local_78);
  }
  *(undefined4 *)(param_1 + 2) = 1;
  param_1[3] = plVar1;
  *param_1 = &PTR_FUN_011b7ea0;
  if (local_30 == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ==== entry=00c798c0 orig=FUN_00c798c0 size=595 name=s_basic_string__append_c798c0 ====

void s_basic_string__append_c798c0(undefined8 *param_1,long *param_2,int *param_3)

{
  int iVar1;
  long *plVar2;
  long *plVar3;
  ulong uVar4;
  long in_FS_OFFSET;
  ulong *local_a8;
  long local_a0;
  ulong local_98 [2];
  undefined1 *local_88;
  long local_80;
  undefined1 local_78;
  undefined7 uStack_77;
  long *local_68;
  long local_60;
  long local_58;
  long lStack_50;
  long local_40;
  
  plVar2 = *(long **)(param_3 + 2);
  iVar1 = *param_3;
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  if (*(code **)(*plVar2 + 0x20) == FUN_00c79560) {
    local_88 = &local_78;
    local_78 = 0;
    local_80 = 0;
    if (iVar1 == 1) {
                    /* try { // try from 00c79ae4 to 00c79ae8 has its CatchHandler @ 00c79b4b */
      std::__cxx11::string::_M_replace((ulong)&local_88,0,(char *)0x0,0xd991d0);
    }
    else {
                    /* try { // try from 00c7993c to 00c79940 has its CatchHandler @ 00c79b4b */
      std::__cxx11::string::_M_replace((ulong)&local_88,0,(char *)0x0,0xd991df);
    }
  }
  else {
    (**(code **)(*plVar2 + 0x20))(&local_88,plVar2,iVar1);
  }
  local_a8 = local_98;
                    /* try { // try from 00c7995b to 00c7995f has its CatchHandler @ 00c79b3b */
  std::__cxx11::string::_M_construct<char*>(&local_a8,*param_2,param_2[1] + *param_2);
  if (0x7fffffffffffffffU - local_a0 < 2) {
                    /* WARNING: Subroutine does not return */
                    /* try { // try from 00c79b21 to 00c79b25 has its CatchHandler @ 00c79b43 */
    std::__throw_length_error("basic_string::append");
  }
                    /* try { // try from 00c79988 to 00c7998c has its CatchHandler @ 00c79b43 */
  std::__cxx11::string::_M_append((char *)&local_a8,0xc8ae07);
  if (local_a8 == local_98) {
    local_98[0] = 0xf;
  }
  if (local_98[0] < (ulong)(local_a0 + local_80)) {
    if (local_88 == &local_78) {
      uVar4 = 0xf;
    }
    else {
      uVar4 = CONCAT71(uStack_77,local_78);
    }
    if ((ulong)(local_a0 + local_80) <= uVar4) {
                    /* try { // try from 00c79aa7 to 00c79aab has its CatchHandler @ 00c79b33 */
      plVar3 = (long *)std::__cxx11::string::_M_replace
                                 ((ulong)&local_88,0,(char *)0x0,(ulong)local_a8);
      goto LAB_00c799de;
    }
  }
                    /* try { // try from 00c799d9 to 00c799dd has its CatchHandler @ 00c79b33 */
  plVar3 = (long *)std::__cxx11::string::_M_append((char *)&local_a8,(ulong)local_88);
LAB_00c799de:
  local_68 = &local_58;
  if ((long *)*plVar3 == plVar3 + 2) {
    local_58 = plVar3[2];
    lStack_50 = plVar3[3];
  }
  else {
    local_58 = plVar3[2];
    local_68 = (long *)*plVar3;
  }
  local_60 = plVar3[1];
  *(undefined1 *)(plVar3 + 2) = 0;
  *plVar3 = (long)(plVar3 + 2);
  plVar3[1] = 0;
                    /* try { // try from 00c79a29 to 00c79a2d has its CatchHandler @ 00c79b2b */
  FUN_00c716a0(param_1,&local_68);
  if (local_68 != &local_58) {
    operator_delete(local_68);
  }
  if (local_a8 != local_98) {
    operator_delete(local_a8);
  }
  if (local_88 != &local_78) {
    operator_delete(local_88);
  }
  *(int *)(param_1 + 2) = iVar1;
  param_1[3] = plVar2;
  *param_1 = &PTR_FUN_011b7ea0;
  if (local_40 == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ==== entry=00c79b60 name=FUN_00c79b60 size=516 ====

void FUN_00c79b60(undefined8 *param_1,char *param_2,int *param_3)

{
  int iVar1;
  long *plVar2;
  long *plVar3;
  long in_FS_OFFSET;
  undefined1 *local_a8;
  undefined8 local_a0;
  undefined1 local_98 [16];
  long *local_88;
  long local_80;
  long local_78;
  long lStack_70;
  long *local_68;
  long local_60;
  long local_58;
  long lStack_50;
  long local_40;
  
  plVar2 = *(long **)(param_3 + 2);
  iVar1 = *param_3;
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  if (*(code **)(*plVar2 + 0x20) == FUN_00c79560) {
    local_a8 = local_98;
    local_98[0] = 0;
    local_a0 = 0;
    if (iVar1 == 1) {
                    /* try { // try from 00c79d54 to 00c79d58 has its CatchHandler @ 00c79d8d */
      std::__cxx11::string::_M_replace((ulong)&local_a8,0,(char *)0x0,0xd991d0);
    }
    else {
                    /* try { // try from 00c79bd9 to 00c79bdd has its CatchHandler @ 00c79d8d */
      std::__cxx11::string::_M_replace((ulong)&local_a8,0,(char *)0x0,0xd991df);
    }
  }
  else {
    (**(code **)(*plVar2 + 0x20))(&local_a8,plVar2,iVar1);
  }
                    /* try { // try from 00c79bf2 to 00c79bf6 has its CatchHandler @ 00c79d85 */
  plVar3 = (long *)std::__cxx11::string::_M_replace((ulong)&local_a8,0,(char *)0x0,0xc8ae07);
  local_88 = &local_78;
  if ((long *)*plVar3 == plVar3 + 2) {
    local_78 = plVar3[2];
    lStack_70 = plVar3[3];
  }
  else {
    local_78 = plVar3[2];
    local_88 = (long *)*plVar3;
  }
  local_80 = plVar3[1];
  *(undefined1 *)(plVar3 + 2) = 0;
  *plVar3 = (long)(plVar3 + 2);
  plVar3[1] = 0;
  strlen(param_2);
                    /* try { // try from 00c79c50 to 00c79c54 has its CatchHandler @ 00c79d75 */
  plVar3 = (long *)std::__cxx11::string::_M_replace((ulong)&local_88,0,(char *)0x0,(ulong)param_2);
  local_68 = &local_58;
  if ((long *)*plVar3 == plVar3 + 2) {
    local_58 = plVar3[2];
    lStack_50 = plVar3[3];
  }
  else {
    local_58 = plVar3[2];
    local_68 = (long *)*plVar3;
  }
  local_60 = plVar3[1];
  *(undefined1 *)(plVar3 + 2) = 0;
  *plVar3 = (long)(plVar3 + 2);
  plVar3[1] = 0;
                    /* try { // try from 00c79ca0 to 00c79ca4 has its CatchHandler @ 00c79d7d */
  FUN_00c716a0(param_1,&local_68);
  if (local_68 != &local_58) {
    operator_delete(local_68);
  }
  if (local_88 != &local_78) {
    operator_delete(local_88);
  }
  if (local_a8 != local_98) {
    operator_delete(local_a8);
  }
  *(int *)(param_1 + 2) = iVar1;
  param_1[3] = plVar2;
  *param_1 = &PTR_FUN_011b7ea0;
  if (local_40 == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ==== entry=00c79da0 orig=FUN_00c79da0 size=136 name=__throw_ios_failure ====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* std::__throw_ios_failure(char const*) */

void std::__throw_ios_failure(char *param_1)

{
  runtime_error *this;
  undefined8 uVar1;
  long in_FS_OFFSET;
  undefined4 local_38 [2];
  undefined8 local_30;
  undefined8 local_20;
  
  local_20 = *(undefined8 *)(in_FS_OFFSET + 0x28);
  this = (runtime_error *)__cxa_allocate_exception(0x30);
  uVar1 = gettext(param_1);
  local_30 = FUN_00c795d0();
  local_38[0] = 1;
                    /* try { // try from 00c79deb to 00c79def has its CatchHandler @ 00c79e28 */
  FUN_00c79b60(this,uVar1,local_38);
  *(undefined ***)this = &PTR_FUN_011b7ec8;
  uVar1 = runtime_error::what(this);
                    /* try { // try from 00c79e0d to 00c79e11 has its CatchHandler @ 00c79e30 */
  FUN_00c7a5b0(this + 0x20,uVar1);
                    /* WARNING: Subroutine does not return */
  __cxa_throw(this,&PTR_PTR_011b7e00,FUN_00c79500);
}


// ==== entry=00c79e40 orig=FUN_00c79e40 size=540 name=ignore ====

/* std::istream::ignore(long) */

istream * __thiscall std::istream::ignore(istream *this,long param_1)

{
  long *plVar1;
  uint uVar2;
  int iVar3;
  byte *pbVar4;
  long lVar5;
  long lVar6;
  byte *pbVar7;
  sentry sVar8;
  long in_FS_OFFSET;
  sentry local_41;
  long local_40;
  
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  if (param_1 == 1) {
    this = (istream *)ignore(this);
  }
  else {
    *(undefined8 *)(this + 8) = 0;
    sentry::sentry(&local_41,this,true);
    if ((0 < param_1) && (local_41 != (sentry)0x0)) {
      plVar1 = *(long **)(this + *(long *)(*(long *)this + -0x18) + 0xe8);
      if ((byte *)plVar1[2] < (byte *)plVar1[3]) {
        uVar2 = (uint)*(byte *)plVar1[2];
      }
      else {
        uVar2 = (**(code **)(*plVar1 + 0x48))(plVar1);
      }
      lVar6 = *(long *)(this + 8);
      sVar8 = (sentry)0x0;
      do {
        while (lVar6 < param_1) {
          if (uVar2 == 0xffffffff) {
LAB_00c79fb0:
            if (param_1 != 0x7fffffffffffffff) {
              if (sVar8 != (sentry)0x0) {
                *(undefined8 *)(this + 8) = 0x7fffffffffffffff;
              }
              goto LAB_00c7a013;
            }
            goto LAB_00c7a000;
          }
          pbVar7 = (byte *)plVar1[3];
          pbVar4 = (byte *)plVar1[2];
          lVar5 = param_1 - lVar6;
          if ((long)pbVar7 - (long)pbVar4 < param_1 - lVar6) {
            lVar5 = (long)pbVar7 - (long)pbVar4;
          }
          if (lVar5 < 2) {
            *(long *)(this + 8) = lVar6 + 1;
            if (pbVar4 < pbVar7) {
              pbVar4 = pbVar4 + 1;
              plVar1[2] = (long)pbVar4;
            }
            else {
              iVar3 = (**(code **)(*plVar1 + 0x50))(plVar1);
              if (iVar3 == -1) goto LAB_00c79fb0;
              pbVar4 = (byte *)plVar1[2];
              pbVar7 = (byte *)plVar1[3];
            }
            if (pbVar7 <= pbVar4) goto LAB_00c7a030;
            uVar2 = (uint)*pbVar4;
            lVar6 = *(long *)(this + 8);
          }
          else {
            pbVar4 = pbVar4 + lVar5;
            lVar6 = lVar6 + lVar5;
            plVar1[2] = (long)pbVar4;
            *(long *)(this + 8) = lVar6;
            if (pbVar4 < pbVar7) {
              uVar2 = (uint)*pbVar4;
            }
            else {
LAB_00c7a030:
                    /* try { // try from 00c7a037 to 00c7a071 has its CatchHandler @ 00c7a07c */
              uVar2 = (**(code **)(*plVar1 + 0x48))(plVar1);
              lVar6 = *(long *)(this + 8);
            }
          }
        }
        if (param_1 != 0x7fffffffffffffff) {
          if (sVar8 != (sentry)0x0) {
            *(undefined8 *)(this + 8) = 0x7fffffffffffffff;
          }
          if (uVar2 != 0xffffffff) break;
          goto LAB_00c7a013;
        }
        if (uVar2 == 0xffffffff) goto LAB_00c7a000;
        *(undefined8 *)(this + 8) = 0x8000000000000000;
        lVar6 = -0x8000000000000000;
        sVar8 = local_41;
      } while( true );
    }
  }
LAB_00c79f7b:
  if (local_40 == *(long *)(in_FS_OFFSET + 0x28)) {
    return this;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
LAB_00c7a000:
  if (sVar8 != (sentry)0x0) {
    *(undefined8 *)(this + 8) = 0x7fffffffffffffff;
  }
LAB_00c7a013:
  ios::s_basic_ios__clear_c1bf70
            ((ios *)(this + *(long *)(*(long *)this + -0x18)),
             *(uint *)((ios *)(this + *(long *)(*(long *)this + -0x18)) + 0x20) | 2);
  goto LAB_00c79f7b;
}


// ==== entry=00c7a090 orig=FUN_00c7a090 size=542 name=ignore ====

/* std::wistream::ignore(long) */

wistream * __thiscall std::wistream::ignore(wistream *this,long param_1)

{
  long *plVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  long lVar5;
  long lVar6;
  sentry sVar7;
  long in_FS_OFFSET;
  sentry local_41;
  long local_40;
  
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  if (param_1 == 1) {
    this = (wistream *)ignore(this);
  }
  else {
    *(undefined8 *)(this + 8) = 0;
    sentry::sentry(&local_41,this,true);
    if ((0 < param_1) && (local_41 != (sentry)0x0)) {
      plVar1 = *(long **)(this + *(long *)(*(long *)this + -0x18) + 0xe8);
      if ((int *)plVar1[2] < (int *)plVar1[3]) {
        iVar4 = *(int *)plVar1[2];
      }
      else {
        iVar4 = (**(code **)(*plVar1 + 0x48))(plVar1);
      }
      lVar6 = *(long *)(this + 8);
      sVar7 = (sentry)0x0;
      do {
        while (lVar6 < param_1) {
          if (iVar4 == -1) {
LAB_00c7a210:
            if (param_1 != 0x7fffffffffffffff) {
              if (sVar7 != (sentry)0x0) {
                *(undefined8 *)(this + 8) = 0x7fffffffffffffff;
              }
              goto LAB_00c7a27b;
            }
            goto LAB_00c7a268;
          }
          piVar2 = (int *)plVar1[3];
          piVar3 = (int *)plVar1[2];
          lVar5 = (long)piVar2 - (long)piVar3 >> 2;
          if (param_1 - lVar6 < lVar5) {
            lVar5 = param_1 - lVar6;
          }
          if (lVar5 < 2) {
            *(long *)(this + 8) = lVar6 + 1;
            if (piVar3 < piVar2) {
              iVar4 = *piVar3;
              plVar1[2] = (long)(piVar3 + 1);
            }
            else {
              iVar4 = (**(code **)(*plVar1 + 0x50))(plVar1);
            }
            if (iVar4 == -1) goto LAB_00c7a210;
            if ((int *)plVar1[3] <= (int *)plVar1[2]) goto LAB_00c7a2a0;
            iVar4 = *(int *)plVar1[2];
            lVar6 = *(long *)(this + 8);
          }
          else {
            piVar3 = piVar3 + lVar5;
            lVar6 = lVar6 + lVar5;
            plVar1[2] = (long)piVar3;
            *(long *)(this + 8) = lVar6;
            if (piVar3 < piVar2) {
              iVar4 = *piVar3;
            }
            else {
LAB_00c7a2a0:
                    /* try { // try from 00c7a2a7 to 00c7a2c8 has its CatchHandler @ 00c7a2d3 */
              iVar4 = (**(code **)(*plVar1 + 0x48))(plVar1);
              lVar6 = *(long *)(this + 8);
            }
          }
        }
        if (param_1 != 0x7fffffffffffffff) {
          if (sVar7 != (sentry)0x0) {
            *(undefined8 *)(this + 8) = 0x7fffffffffffffff;
          }
          if (iVar4 != -1) break;
          goto LAB_00c7a27b;
        }
        if (iVar4 == -1) goto LAB_00c7a268;
        *(undefined8 *)(this + 8) = 0x8000000000000000;
        lVar6 = -0x8000000000000000;
        sVar7 = local_41;
      } while( true );
    }
  }
LAB_00c7a1d3:
  if (local_40 == *(long *)(in_FS_OFFSET + 0x28)) {
    return this;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
LAB_00c7a268:
  if (sVar7 != (sentry)0x0) {
    *(undefined8 *)(this + 8) = 0x7fffffffffffffff;
  }
LAB_00c7a27b:
  wios::s_basic_ios__clear_c1c9b0
            ((wios *)(this + *(long *)(*(long *)this + -0x18)),
             *(uint *)((wios *)(this + *(long *)(*(long *)this + -0x18)) + 0x20) | 2);
  goto LAB_00c7a1d3;
}


// ==== entry=00c7a2e0 orig=FUN_00c7a2e0 size=19 name=~__pointer_to_member_type_info ====

/* __cxxabiv1::__pointer_to_member_type_info::~__pointer_to_member_type_info() */

void __thiscall
__cxxabiv1::__pointer_to_member_type_info::~__pointer_to_member_type_info
          (__pointer_to_member_type_info *this)

{
  *(undefined ***)this = &PTR____pointer_to_member_type_info_011b7f60;
  __pbase_type_info::~__pbase_type_info((__pbase_type_info *)this);
  return;
}


// ==== entry=00c7a300 orig=FUN_00c7a300 size=23 name=~__pointer_to_member_type_info ====

/* __cxxabiv1::__pointer_to_member_type_info::~__pointer_to_member_type_info() */

void __thiscall
__cxxabiv1::__pointer_to_member_type_info::~__pointer_to_member_type_info
          (__pointer_to_member_type_info *this)

{
  ~__pointer_to_member_type_info(this);
  operator_delete(this,0x28);
  return;
}


// ==== entry=00c7a320 orig=FUN_00c7a320 size=103 name=__pointer_catch ====

/* __cxxabiv1::__pointer_to_member_type_info::__pointer_catch(__cxxabiv1::__pbase_type_info const*,
   void**, unsigned int) const */

undefined8 __thiscall
__cxxabiv1::__pointer_to_member_type_info::__pointer_catch
          (__pointer_to_member_type_info *this,__pbase_type_info *param_1,void **param_2,
          uint param_3)

{
  char *__s1;
  int iVar1;
  undefined8 uVar2;
  
  __s1 = *(char **)(*(long *)(this + 0x20) + 8);
  if (__s1 != *(char **)(*(long *)(param_1 + 0x20) + 8)) {
    if (*__s1 != '*') {
      iVar1 = strcmp(__s1,*(char **)(*(long *)(param_1 + 0x20) + 8));
      if (iVar1 == 0) goto LAB_00c7a368;
    }
    return 0;
  }
LAB_00c7a368:
                    /* WARNING: Could not recover jumptable at 0x00c7a388. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar2 = (**(code **)(**(long **)(this + 0x18) + 0x20))
                    (*(long **)(this + 0x18),*(undefined8 *)(param_1 + 0x18),param_2,param_3 + 2);
  return uVar2;
}


// ==== entry=00c7a390 orig=FUN_00c7a390 size=281 name=__verbose_terminate_handler ====

/* __gnu_cxx::__verbose_terminate_handler() */

void __gnu_cxx::__verbose_terminate_handler(void)

{
  long lVar1;
  char *__s;
  char *__s_00;
  long in_FS_OFFSET;
  int local_24;
  undefined8 local_20;
  
  local_20 = *(undefined8 *)(in_FS_OFFSET + 0x28);
  if (DAT_011c6710 != '\0') {
    fwrite("terminate called recursively\n",1,0x1d,stderr);
                    /* WARNING: Subroutine does not return */
    abort();
  }
  DAT_011c6710 = 1;
  lVar1 = __cxa_current_exception_type();
  if (lVar1 != 0) {
    local_24 = -1;
    __s_00 = *(char **)(lVar1 + 8) + (**(char **)(lVar1 + 8) == '*');
    __s = (char *)__cxa_demangle(__s_00,0,0,&local_24);
    fwrite("terminate called after throwing an instance of \'",1,0x30,stderr);
    if (local_24 == 0) {
      fputs(__s,stderr);
    }
    else {
      fputs(__s_00,stderr);
    }
    fwrite(&DAT_00d992ec,1,2,stderr);
    if (local_24 == 0) {
      FUN_0051e8de();
      return;
    }
                    /* WARNING: Subroutine does not return */
    __cxa_rethrow();
  }
  fwrite("terminate called without an active exception\n",1,0x2d,stderr);
                    /* WARNING: Subroutine does not return */
  abort();
}


// ==== entry=00c7a4c0 orig=FUN_00c7a4c0 size=5 name=what ====

/* std::ios_base::failure::what() const */

undefined8 __thiscall std::ios_base::failure::what(failure *this)

{
  return *(undefined8 *)(this + 8);
}


// ==== entry=00c7a4d0 orig=FUN_00c7a4d0 size=137 name=~failure ====

/* WARNING: Removing unreachable block (ram,0x00c7a550) */
/* std::ios_base::failure::~failure() */

void __thiscall std::ios_base::failure::~failure(failure *this)

{
  allocator *paVar1;
  int *piVar2;
  int iVar3;
  long lVar4;
  long in_FS_OFFSET;
  
  lVar4 = *(long *)(in_FS_OFFSET + 0x28);
  *(undefined ***)this = &PTR__failure_011b7fc0;
  paVar1 = (allocator *)(*(long *)(this + 8) + -0x18);
  if (paVar1 != (allocator *)&string::_Rep::_S_empty_rep_storage) {
    LOCK();
    piVar2 = (int *)(*(long *)(this + 8) + -8);
    iVar3 = *piVar2;
    *piVar2 = *piVar2 + -1;
    UNLOCK();
    if (iVar3 < 1) {
      string::_Rep::_M_destroy(paVar1);
    }
  }
  exception::~exception((exception *)this);
  if (lVar4 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


// ==== entry=00c7a560 orig=FUN_00c7a560 size=18 name=~failure ====

/* std::ios_base::failure::~failure() */

void __thiscall std::ios_base::failure::~failure(failure *this)

{
  ~failure(this);
  operator_delete(this);
  return;
}


// ==== entry=00c7a580 orig=FUN_00c7a580 size=36 name=failure ====

/* std::ios_base::failure::failure(std::string const&) */

void __thiscall std::ios_base::failure::failure(failure *this,string *param_1)

{
  *(undefined ***)this = &PTR__failure_011b7fc0;
                    /* try { // try from 00c7a59a to 00c7a59e has its CatchHandler @ 00c7a5a4 */
  string::string((string *)(this + 8),param_1);
  return;
}


// ==== entry=00c7a5b0 name=FUN_00c7a5b0 size=147 ====

/* WARNING: Removing unreachable block (ram,0x00c7a638) */

void FUN_00c7a5b0(failure *param_1,char *param_2)

{
  int *piVar1;
  int iVar2;
  long in_FS_OFFSET;
  allocator local_2a [2];
  long local_28;
  long local_20;
  
  local_20 = *(long *)(in_FS_OFFSET + 0x28);
  std::string::string((string *)&local_28,param_2,local_2a);
  std::ios_base::failure::failure(param_1,(string *)&local_28);
  if ((allocator *)(local_28 + -0x18) != (allocator *)&std::string::_Rep::_S_empty_rep_storage) {
    LOCK();
    piVar1 = (int *)(local_28 + -8);
    iVar2 = *piVar1;
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if (iVar2 < 1) {
      std::string::_Rep::_M_destroy((allocator *)(local_28 + -0x18));
    }
  }
  if (local_20 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


// ==== entry=00c7a650 name=FUN_00c7a650 size=5 ====

void FUN_00c7a650(undefined8 *param_1)

{
                    /* WARNING: Could not recover jumptable at 0x00c7a653. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)*param_1)();
  return;
}


// ==== entry=00c7a660 name=FUN_00c7a660 size=48 ====

undefined8 FUN_00c7a660(long param_1)

{
  char *__s1;
  int iVar1;
  undefined8 uVar2;
  undefined4 extraout_var;
  
  __s1 = *(char **)(param_1 + 8);
  uVar2 = 1;
  if ((__s1 != "NSt8ios_base7failureE") && (uVar2 = 0, *__s1 != '*')) {
    iVar1 = strcmp(__s1,"NSt8ios_base7failureE");
    return CONCAT71((int7)(CONCAT44(extraout_var,iVar1) >> 8),iVar1 == 0);
  }
  return uVar2;
}


// ==== entry=00c7a6a0 name=FUN_00c7a6a0 size=93 ====

undefined4 * FUN_00c7a6a0(long param_1,undefined4 param_2,long param_3,long param_4)

{
  undefined4 *puVar1;
  int iVar2;
  long lVar3;
  
  switch(param_2) {
  default:
    goto switchD_00c7a6b6_caseD_0;
  case 1:
  case 2:
  case 3:
  case 4:
  case 0xb:
  case 0x21:
  case 0x2b:
  case 0x2d:
  case 0x36:
  case 0x37:
  case 0x38:
  case 0x39:
  case 0x3a:
  case 0x3c:
  case 0x3d:
  case 0x3f:
  case 0x4b:
  case 0x4d:
    if (param_3 == 0) {
      return (undefined4 *)0x0;
    }
  case 0x2a:
  case 0x30:
    lVar3 = param_4;
    break;
  case 9:
  case 10:
  case 0xc:
  case 0xd:
  case 0xe:
  case 0xf:
  case 0x10:
  case 0x11:
  case 0x12:
  case 0x13:
  case 0x14:
  case 0x15:
  case 0x16:
  case 0x17:
  case 0x22:
  case 0x23:
  case 0x24:
  case 0x25:
  case 0x26:
  case 0x28:
  case 0x33:
  case 0x34:
  case 0x35:
  case 0x3b:
  case 0x3e:
  case 0x42:
  case 0x43:
  case 0x44:
  case 0x48:
  case 0x49:
  case 0x4a:
    lVar3 = param_3;
    break;
  case 0x19:
  case 0x1a:
  case 0x1b:
  case 0x1c:
  case 0x1d:
  case 0x1e:
  case 0x1f:
  case 0x20:
  case 0x29:
  case 0x2e:
  case 0x2f:
  case 0x4c:
  case 0x4e:
  case 0x4f:
    goto switchD_00c7a6b6_caseD_19;
  }
  if (lVar3 != 0) {
switchD_00c7a6b6_caseD_19:
    iVar2 = *(int *)(param_1 + 0x28);
    if (iVar2 < *(int *)(param_1 + 0x2c)) {
      puVar1 = (undefined4 *)(*(long *)(param_1 + 0x20) + (long)iVar2 * 0x18);
      puVar1[1] = 0;
      *(int *)(param_1 + 0x28) = iVar2 + 1;
      *puVar1 = param_2;
      *(long *)(puVar1 + 2) = param_3;
      *(long *)(puVar1 + 4) = param_4;
      return puVar1;
    }
  }
switchD_00c7a6b6_caseD_0:
  return (undefined4 *)0x0;
}


// ==== entry=00c7a710 name=FUN_00c7a710 size=73 ====

void FUN_00c7a710(long param_1,undefined8 param_2)

{
  char cVar1;
  int iVar2;
  undefined8 uVar3;
  
  cVar1 = **(char **)(param_1 + 0x18);
  if ((cVar1 != 'R') && (cVar1 != 'O')) {
    return;
  }
  uVar3 = 0x20;
  iVar2 = *(int *)(param_1 + 0x48) + 3;
  if (cVar1 == 'R') {
    iVar2 = *(int *)(param_1 + 0x48) + 2;
    uVar3 = 0x1f;
  }
  *(int *)(param_1 + 0x48) = iVar2;
  *(char **)(param_1 + 0x18) = *(char **)(param_1 + 0x18) + 1;
  FUN_00c7a6a0(param_1,uVar3,param_2,0);
  return;
}


// ==== entry=00c7a770 name=FUN_00c7a770 size=130 ====

void FUN_00c7a770(int *param_1,int *param_2,undefined4 *param_3)

{
  int *piVar1;
  
  if (param_3 == (undefined4 *)0x0) {
    return;
  }
  do {
    switch(*param_3) {
    default:
      goto switchD_00c7a7a7_caseD_0;
    case 1:
    case 2:
    case 3:
    case 9:
    case 10:
    case 0xb:
    case 0xc:
    case 0xd:
    case 0xe:
    case 0xf:
    case 0x10:
    case 0x11:
    case 0x12:
    case 0x13:
    case 0x14:
    case 0x15:
    case 0x16:
    case 0x17:
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
    case 0x25:
    case 0x26:
    case 0x28:
    case 0x29:
    case 0x2a:
    case 0x2b:
    case 0x2d:
    case 0x2e:
    case 0x2f:
    case 0x30:
    case 0x33:
    case 0x34:
    case 0x35:
    case 0x36:
    case 0x37:
    case 0x38:
    case 0x39:
    case 0x3a:
    case 0x3b:
    case 0x3c:
    case 0x3d:
    case 0x3e:
    case 0x3f:
    case 0x42:
    case 0x48:
    case 0x49:
    case 0x4a:
    case 0x4b:
    case 0x4c:
    case 0x4d:
    case 0x4e:
    case 0x4f:
switchD_00c7a7a7_caseD_1:
      piVar1 = *(int **)(param_3 + 2);
      break;
    case 4:
      *param_1 = *param_1 + 1;
      piVar1 = *(int **)(param_3 + 2);
      break;
    case 7:
    case 8:
    case 0x32:
      param_3 = *(undefined4 **)(param_3 + 4);
      goto LAB_00c7a7b4;
    case 0x23:
    case 0x24:
      piVar1 = *(int **)(param_3 + 2);
      if (*piVar1 == 5) {
        *param_2 = *param_2 + 1;
        goto switchD_00c7a7a7_caseD_1;
      }
      break;
    case 0x2c:
    case 0x43:
    case 0x44:
    case 0x45:
    case 0x46:
      param_3 = *(undefined4 **)(param_3 + 2);
      goto LAB_00c7a7b4;
    }
    FUN_00c7a770(param_1,param_2,piVar1);
    param_3 = *(undefined4 **)(param_3 + 4);
LAB_00c7a7b4:
  } while (param_3 != (undefined4 *)0x0);
switchD_00c7a7a7_caseD_0:
  return;
}


// ==== entry=00c7a810 name=FUN_00c7a810 size=142 ====

void FUN_00c7a810(long param_1,undefined1 *param_2,long param_3)

{
  undefined1 *puVar1;
  undefined1 uVar2;
  long lVar3;
  long lVar4;
  
  if (param_3 != 0) {
    puVar1 = param_2 + param_3;
    lVar3 = *(long *)(param_1 + 0x100);
    do {
      uVar2 = *param_2;
      if (lVar3 == 0xff) {
        *(undefined1 *)(param_1 + 0xff) = 0;
        (**(code **)(param_1 + 0x110))(param_1,0xff,*(undefined8 *)(param_1 + 0x118));
        *(long *)(param_1 + 0x140) = *(long *)(param_1 + 0x140) + 1;
        lVar4 = 1;
        lVar3 = 0;
      }
      else {
        lVar4 = lVar3 + 1;
      }
      param_2 = param_2 + 1;
      *(long *)(param_1 + 0x100) = lVar4;
      *(undefined1 *)(param_1 + lVar3) = uVar2;
      *(undefined1 *)(param_1 + 0x108) = uVar2;
      lVar3 = lVar4;
    } while (param_2 != puVar1);
    return;
  }
  return;
}


// ==== entry=00c7a8c0 name=FUN_00c7a8c0 size=162 ====

int FUN_00c7a8c0(long *param_1)

{
  int iVar1;
  char cVar2;
  char *pcVar3;
  bool bVar4;
  int iVar5;
  char *pcVar6;
  int iVar7;
  
  pcVar3 = (char *)*param_1;
  cVar2 = *pcVar3;
  if (cVar2 == 'n') {
    pcVar6 = pcVar3 + 1;
    *param_1 = (long)pcVar6;
    cVar2 = pcVar3[1];
    if (9 < (byte)(cVar2 - 0x30U)) {
      return 0;
    }
    bVar4 = true;
  }
  else {
    if (9 < (byte)(cVar2 - 0x30U)) {
      return 0;
    }
    bVar4 = false;
    pcVar6 = pcVar3;
  }
  iVar5 = (int)cVar2;
  iVar7 = 0;
  do {
    pcVar6 = pcVar6 + 1;
    *param_1 = (long)pcVar6;
    iVar1 = iVar5 + iVar7 * 10;
    iVar5 = (int)*pcVar6;
    iVar7 = iVar1 + -0x30;
    if (9 < (byte)(*pcVar6 - 0x30U)) {
      if (bVar4) {
        iVar7 = 0x30 - iVar1;
      }
      return iVar7;
    }
  } while (iVar7 <= (int)((0x7fffffffU - (iVar5 + -0x30)) / 10));
  return -1;
}


// ==== entry=00c7a970 name=FUN_00c7a970 size=70 ====

undefined4 * FUN_00c7a970(long param_1)

{
  undefined4 *puVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0x28);
  if (iVar2 < *(int *)(param_1 + 0x2c)) {
    puVar1 = (undefined4 *)(*(long *)(param_1 + 0x20) + (long)iVar2 * 0x18);
    puVar1[1] = 0;
    *(int *)(param_1 + 0x28) = iVar2 + 1;
    *puVar1 = 0x41;
    iVar2 = FUN_00c7a8c0();
    *(long *)(puVar1 + 2) = (long)iVar2;
    return puVar1;
  }
  return (undefined4 *)0x0;
}


// ==== entry=00c7a9c0 name=FUN_00c7a9c0 size=63 ====

int FUN_00c7a9c0(long param_1)

{
  int iVar1;
  char *pcVar2;
  
  pcVar2 = *(char **)(param_1 + 0x18);
  if (*pcVar2 != '_') {
    if (*pcVar2 != 'n') {
      iVar1 = FUN_00c7a8c0(param_1 + 0x18);
      iVar1 = iVar1 + 1;
      if ((-1 < iVar1) && (pcVar2 = *(char **)(param_1 + 0x18), *pcVar2 == '_')) goto LAB_00c7a9ea;
    }
    return -1;
  }
  iVar1 = 0;
LAB_00c7a9ea:
  *(char **)(param_1 + 0x18) = pcVar2 + 1;
  return iVar1;
}


// ==== entry=00c7aa10 name=FUN_00c7aa10 size=88 ====

undefined4 * FUN_00c7aa10(long param_1)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  
  if (**(char **)(param_1 + 0x18) != 'T') {
    return (undefined4 *)0x0;
  }
  *(char **)(param_1 + 0x18) = *(char **)(param_1 + 0x18) + 1;
  iVar3 = FUN_00c7a9c0();
  if ((-1 < iVar3) && (iVar2 = *(int *)(param_1 + 0x28), iVar2 < *(int *)(param_1 + 0x2c))) {
    puVar1 = (undefined4 *)(*(long *)(param_1 + 0x20) + (long)iVar2 * 0x18);
    puVar1[1] = 0;
    *(int *)(param_1 + 0x28) = iVar2 + 1;
    *puVar1 = 5;
    *(long *)(puVar1 + 2) = (long)iVar3;
    return puVar1;
  }
  return (undefined4 *)0x0;
}


// ==== entry=00c7aa80 name=FUN_00c7aa80 size=318 ====

undefined8 * FUN_00c7aa80(long param_1)

{
  long *plVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  char *pcVar5;
  undefined8 *puVar6;
  
  iVar2 = FUN_00c7a8c0(param_1 + 0x18);
  if (iVar2 < 1) {
    return (undefined8 *)0x0;
  }
  plVar1 = *(long **)(param_1 + 0x18);
  if (*(long *)(param_1 + 8) - (long)plVar1 < (long)iVar2) goto LAB_00c7ab68;
  pcVar5 = (char *)((long)iVar2 + (long)plVar1);
  *(char **)(param_1 + 0x18) = pcVar5;
  if (((*(byte *)(param_1 + 0x10) & 4) == 0) || (*pcVar5 != '$')) {
    iVar3 = *(int *)(param_1 + 0x28);
    iVar4 = *(int *)(param_1 + 0x2c);
    if (iVar2 < 10) goto LAB_00c7aacb;
LAB_00c7ab10:
    if ((((*plVar1 == 0x5f4c41424f4c475f) && ((byte)(*(byte *)(plVar1 + 1) - 0x24) < 0x3c)) &&
        ((0x800000000000401U >> ((ulong)(*(byte *)(plVar1 + 1) - 0x24) & 0x3f) & 1) != 0)) &&
       (*(char *)((long)plVar1 + 9) == 'N')) {
      *(int *)(param_1 + 0x48) = (*(int *)(param_1 + 0x48) + 0x16) - iVar2;
      if (iVar3 < iVar4) {
        *(int *)(param_1 + 0x28) = iVar3 + 1;
        puVar6 = (undefined8 *)(*(long *)(param_1 + 0x20) + (long)iVar3 * 0x18);
        *puVar6 = 0;
        puVar6[1] = "(anonymous namespace)";
        *(undefined4 *)(puVar6 + 2) = 0x15;
        goto LAB_00c7ab02;
      }
    }
    else if (iVar3 < iVar4) {
      puVar6 = (undefined8 *)(*(long *)(param_1 + 0x20) + (long)iVar3 * 0x18);
      *(undefined4 *)((long)puVar6 + 4) = 0;
      *(int *)(param_1 + 0x28) = iVar3 + 1;
LAB_00c7aaf4:
      *puVar6 = 0;
      puVar6[1] = plVar1;
      *(int *)(puVar6 + 2) = iVar2;
      goto LAB_00c7ab02;
    }
  }
  else {
    iVar3 = *(int *)(param_1 + 0x28);
    *(char **)(param_1 + 0x18) = pcVar5 + 1;
    iVar4 = *(int *)(param_1 + 0x2c);
    if (9 < iVar2) goto LAB_00c7ab10;
LAB_00c7aacb:
    if (iVar3 < iVar4) {
      puVar6 = (undefined8 *)(*(long *)(param_1 + 0x20) + (long)iVar3 * 0x18);
      *(undefined4 *)((long)puVar6 + 4) = 0;
      *(int *)(param_1 + 0x28) = iVar3 + 1;
      if (plVar1 == (long *)0x0) goto LAB_00c7ab68;
      goto LAB_00c7aaf4;
    }
  }
LAB_00c7ab68:
  puVar6 = (undefined8 *)0x0;
LAB_00c7ab02:
  *(undefined8 **)(param_1 + 0x40) = puVar6;
  return puVar6;
}


// ==== entry=00c7abe0 name=FUN_00c7abe0 size=91 ====

undefined8 FUN_00c7abe0(long param_1,undefined8 param_2)

{
  char cVar1;
  char *pcVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  
  pcVar2 = *(char **)(param_1 + 0x18);
  uVar3 = *(undefined8 *)(param_1 + 0x40);
  cVar1 = *pcVar2;
  while (cVar1 == 'B') {
    *(char **)(param_1 + 0x18) = pcVar2 + 1;
    uVar4 = FUN_00c7aa80(param_1);
    param_2 = FUN_00c7a6a0(param_1,0x4b,param_2,uVar4);
    pcVar2 = *(char **)(param_1 + 0x18);
    cVar1 = *pcVar2;
  }
  *(undefined8 *)(param_1 + 0x40) = uVar3;
  return param_2;
}


// ==== entry=00c7ac40 name=FUN_00c7ac40 size=470 ====

undefined4 * FUN_00c7ac40(long param_1,uint param_2)

{
  int iVar1;
  undefined4 uVar2;
  long lVar3;
  char cVar4;
  long lVar5;
  undefined4 *puVar6;
  char cVar7;
  int iVar8;
  ulong uVar9;
  uint uVar10;
  uint uVar11;
  int iVar12;
  char *pcVar13;
  undefined8 uVar14;
  bool bVar15;
  
  pcVar13 = *(char **)(param_1 + 0x18);
  if (*pcVar13 == 'S') {
    *(char **)(param_1 + 0x18) = pcVar13 + 1;
    cVar4 = '\0';
    if (pcVar13[1] != '\0') {
      *(char **)(param_1 + 0x18) = pcVar13 + 2;
      cVar4 = pcVar13[1];
      iVar8 = (int)cVar4;
      if (((byte)(cVar4 - 0x30U) < 10) || (cVar4 == '_')) {
        uVar9 = 0;
        if (cVar4 == '_') {
LAB_00c7acda:
          if (*(uint *)(param_1 + 0x38) <= (uint)uVar9) {
            return (undefined4 *)0x0;
          }
          return *(undefined4 **)(*(long *)(param_1 + 0x30) + uVar9 * 8);
        }
LAB_00c7ad00:
        uVar10 = 0;
        if (9 < (byte)(cVar4 - 0x30U)) goto LAB_00c7ad3f;
        do {
          uVar11 = uVar10;
          uVar10 = iVar8 + -0x30 + uVar10 * 0x24;
          while( true ) {
            if (uVar10 < uVar11) {
              return (undefined4 *)0x0;
            }
            pcVar13 = *(char **)(param_1 + 0x18);
            cVar4 = '\0';
            if (*pcVar13 != '\0') {
              *(char **)(param_1 + 0x18) = pcVar13 + 1;
              cVar4 = *pcVar13;
              if (cVar4 == '_') {
                uVar9 = (ulong)(uVar10 + 1);
                goto LAB_00c7acda;
              }
            }
            iVar8 = (int)cVar4;
            if ((byte)(cVar4 - 0x30U) < 10) break;
LAB_00c7ad3f:
            if (0x19 < (byte)((char)iVar8 + 0xbfU)) {
              return (undefined4 *)0x0;
            }
            uVar11 = uVar10;
            uVar10 = iVar8 + -0x37 + uVar10 * 0x24;
          }
        } while( true );
      }
      if ((byte)(cVar4 + 0xbfU) < 0x1a) goto LAB_00c7ad00;
    }
    bVar15 = (*(uint *)(param_1 + 0x10) & 8) != 0;
    if (((!bVar15) && ((param_2 & 1) != 0)) && ((byte)(**(char **)(param_1 + 0x18) + 0xbdU) < 2)) {
      bVar15 = true;
    }
    pcVar13 = "t";
    cVar7 = 't';
    while( true ) {
      if (cVar4 == cVar7) {
        lVar3 = *(long *)(pcVar13 + 0x28);
        iVar8 = *(int *)(param_1 + 0x28);
        iVar1 = *(int *)(param_1 + 0x2c);
        if (lVar3 != 0) {
          uVar2 = *(undefined4 *)(pcVar13 + 0x30);
          if (iVar8 < iVar1) {
            lVar5 = (long)iVar8;
            iVar8 = iVar8 + 1;
            puVar6 = (undefined4 *)(*(long *)(param_1 + 0x20) + lVar5 * 0x18);
            puVar6[1] = 0;
            *(int *)(param_1 + 0x28) = iVar8;
            *puVar6 = 0x18;
            *(long *)(puVar6 + 2) = lVar3;
            puVar6[4] = uVar2;
          }
          else {
            puVar6 = (undefined4 *)0x0;
          }
          *(undefined4 **)(param_1 + 0x40) = puVar6;
        }
        if (bVar15) {
          uVar14 = *(undefined8 *)(pcVar13 + 0x18);
          iVar12 = *(int *)(pcVar13 + 0x20);
        }
        else {
          uVar14 = *(undefined8 *)(pcVar13 + 8);
          iVar12 = *(int *)(pcVar13 + 0x10);
        }
        *(int *)(param_1 + 0x48) = *(int *)(param_1 + 0x48) + iVar12;
        if (iVar8 < iVar1) {
          puVar6 = (undefined4 *)(*(long *)(param_1 + 0x20) + (long)iVar8 * 0x18);
          puVar6[1] = 0;
          *(int *)(param_1 + 0x28) = iVar8 + 1;
          *puVar6 = 0x18;
          *(undefined8 *)(puVar6 + 2) = uVar14;
          puVar6[4] = iVar12;
        }
        else {
          puVar6 = (undefined4 *)0x0;
        }
        if (**(char **)(param_1 + 0x18) != 'B') {
          return puVar6;
        }
        puVar6 = (undefined4 *)FUN_00c7abe0(param_1,puVar6);
        if ((puVar6 != (undefined4 *)0x0) &&
           (iVar8 = *(int *)(param_1 + 0x38), iVar8 < *(int *)(param_1 + 0x3c))) {
          *(undefined4 **)(*(long *)(param_1 + 0x30) + (long)iVar8 * 8) = puVar6;
          *(int *)(param_1 + 0x38) = iVar8 + 1;
          return puVar6;
        }
        return (undefined4 *)0x0;
      }
      pcVar13 = pcVar13 + 0x38;
      if (pcVar13 == "") break;
      cVar7 = *pcVar13;
    }
  }
  return (undefined4 *)0x0;
}


// ==== entry=00c7ae40 name=FUN_00c7ae40 size=114 ====

undefined8 FUN_00c7ae40(long param_1,int param_2)

{
  char *pcVar1;
  
  if (param_2 == 0) {
    pcVar1 = *(char **)(param_1 + 0x18);
    if (*pcVar1 == '\0') {
      return 0;
    }
    *(char **)(param_1 + 0x18) = pcVar1 + 1;
    param_2 = (int)*pcVar1;
  }
  if (param_2 == 0x68) {
    FUN_00c7a8c0(param_1 + 0x18);
  }
  else {
    if (param_2 != 0x76) {
      return 0;
    }
    FUN_00c7a8c0(param_1 + 0x18);
    if (**(char **)(param_1 + 0x18) != '_') {
      return 0;
    }
    *(char **)(param_1 + 0x18) = *(char **)(param_1 + 0x18) + 1;
    FUN_00c7a8c0();
  }
  if (**(char **)(param_1 + 0x18) != '_') {
    return 0;
  }
  *(char **)(param_1 + 0x18) = *(char **)(param_1 + 0x18) + 1;
  return 1;
}


// ==== entry=00c7aec0 name=FUN_00c7aec0 size=62 ====

uint FUN_00c7aec0(char *param_1)

{
  byte bVar1;
  
  bVar1 = *param_1 + 0xb5;
  if (bVar1 < 0x28) {
    return (uint)(0x8000000801 >> (bVar1 & 0x3f)) & 1;
  }
  if (*param_1 != 'D') {
    return 0;
  }
  return (uint)((byte)(param_1[1] + 0x89U) < 2 || (param_1[1] & 0xdfU) == 0x4f);
}


// ==== entry=00c7af10 name=FUN_00c7af10 size=107 ====

undefined8 FUN_00c7af10(long param_1)

{
  char *pcVar1;
  int iVar2;
  
  pcVar1 = *(char **)(param_1 + 0x18);
  if (*pcVar1 != '_') {
    return 1;
  }
  *(char **)(param_1 + 0x18) = pcVar1 + 1;
  if (pcVar1[1] == '_') {
    *(char **)(param_1 + 0x18) = pcVar1 + 2;
    iVar2 = FUN_00c7a8c0();
    if (iVar2 < 0) {
      return 0;
    }
    if (9 < iVar2) {
      if (**(char **)(param_1 + 0x18) != '_') {
        return 0;
      }
      *(char **)(param_1 + 0x18) = *(char **)(param_1 + 0x18) + 1;
    }
  }
  else {
    iVar2 = FUN_00c7a8c0(param_1 + 0x18);
    if (iVar2 < 0) {
      return 0;
    }
  }
  return 1;
}


// ==== entry=00c7af90 name=FUN_00c7af90 size=47 ====

undefined8 FUN_00c7af90(int *param_1,int param_2)

{
  if ((param_1 == (int *)0x0) || (*param_1 != 0x2f)) {
    return 0;
  }
  if (param_2 < 1) {
    if (param_2 != 0) {
      return 0;
    }
  }
  else {
    do {
      param_1 = *(int **)(param_1 + 4);
      param_2 = param_2 + -1;
      if (param_1 == (int *)0x0) {
        return 0;
      }
      if (*param_1 != 0x2f) {
        return 0;
      }
    } while (param_2 != 0);
  }
  return *(undefined8 *)(param_1 + 2);
}


// ==== entry=00c7afc0 name=FUN_00c7afc0 size=44 ====

void FUN_00c7afc0(long param_1,undefined8 *param_2)

{
  if (*(long *)(param_1 + 0x120) == 0) {
    *(undefined4 *)(param_1 + 0x130) = 1;
    return;
  }
  if (-1 < (int)*param_2) {
    FUN_00c7af90(*(undefined8 *)(*(long *)(*(long *)(param_1 + 0x120) + 8) + 0x10));
    return;
  }
  return;
}


// ==== entry=00c7b000 name=FUN_00c7b000 size=108 ====

int * FUN_00c7b000(undefined8 param_1,undefined4 *param_2)

{
  int *piVar1;
  
  if (param_2 == (undefined4 *)0x0) {
    return (int *)0x0;
  }
  do {
    switch(*param_2) {
    case 0:
    case 6:
    case 0x18:
    case 0x27:
    case 0x2c:
    case 0x31:
    case 0x40:
    case 0x41:
    case 0x45:
    case 0x46:
    case 0x47:
    case 0x4a:
    case 0x4b:
      goto LAB_00c7b052;
    case 5:
      piVar1 = (int *)FUN_00c7afc0(param_1,param_2 + 2);
      if ((piVar1 != (int *)0x0) && (*piVar1 == 0x2f)) {
        return piVar1;
      }
      goto LAB_00c7b052;
    case 7:
    case 8:
    case 0x32:
      goto switchD_00c7b025_caseD_7;
    }
    piVar1 = (int *)FUN_00c7b000(param_1,*(undefined8 *)(param_2 + 2));
    if (piVar1 != (int *)0x0) {
      return piVar1;
    }
switchD_00c7b025_caseD_7:
    param_2 = *(undefined4 **)(param_2 + 4);
  } while (param_2 != (undefined4 *)0x0);
LAB_00c7b052:
  return (int *)0x0;
}


// ==== entry=00c7b090 name=FUN_00c7b090 size=198 ====

void FUN_00c7b090(void *param_1,size_t param_2,long *param_3)

{
  ulong uVar1;
  void *pvVar2;
  int iVar3;
  ulong __size;
  
  __size = param_3[2];
  iVar3 = (int)param_3[3];
  uVar1 = param_2 + 1 + param_3[1];
  if (__size < uVar1) {
    if (iVar3 != 0) {
      return;
    }
    if ((__size != 0) || (__size = 2, 2 < uVar1)) {
      do {
        __size = __size * 2;
      } while (__size < uVar1);
    }
    pvVar2 = realloc((void *)*param_3,__size);
    if (pvVar2 == (void *)0x0) {
      free((void *)*param_3);
      *param_3 = 0;
      param_3[1] = 0;
      param_3[2] = 0;
      *(undefined4 *)(param_3 + 3) = 1;
      return;
    }
    *param_3 = (long)pvVar2;
    iVar3 = (int)param_3[3];
    param_3[2] = __size;
  }
  if (iVar3 == 0) {
    memcpy((void *)(param_3[1] + *param_3),param_1,param_2);
    *(undefined1 *)(*param_3 + param_2 + param_3[1]) = 0;
    param_3[1] = param_3[1] + param_2;
  }
  return;
}


// ==== entry=00c7b170 name=FUN_00c7b170 size=374 ====

undefined8 FUN_00c7b170(long param_1)

{
  int iVar1;
  int *piVar2;
  char cVar3;
  char *pcVar4;
  undefined8 *puVar5;
  undefined8 uVar6;
  int iVar7;
  char *pcVar8;
  
  pcVar8 = *(char **)(param_1 + 0x18);
  if (*pcVar8 != 'L') {
    return 0;
  }
  pcVar4 = pcVar8 + 1;
  *(char **)(param_1 + 0x18) = pcVar4;
  cVar3 = pcVar8[1];
  if ((cVar3 == '_') || (cVar3 == 'Z')) {
    if (cVar3 == '_') {
      pcVar4 = pcVar8 + 2;
      *(char **)(param_1 + 0x18) = pcVar4;
      cVar3 = pcVar8[2];
      if (cVar3 != 'Z') {
        uVar6 = 0;
        goto joined_r0x00c7b2a9;
      }
    }
    *(char **)(param_1 + 0x18) = pcVar4 + 1;
    uVar6 = FUN_00c7d680(param_1,0);
    pcVar4 = *(char **)(param_1 + 0x18);
    cVar3 = *pcVar4;
    goto joined_r0x00c7b2a9;
  }
  piVar2 = (int *)demangle_parse_type();
  if (piVar2 == (int *)0x0) {
    return 0;
  }
  if ((*piVar2 == 0x27) && (*(int *)(*(long *)(piVar2 + 2) + 0x1c) != 0)) {
    *(int *)(param_1 + 0x48) = *(int *)(param_1 + 0x48) - *(int *)(*(long *)(piVar2 + 2) + 8);
  }
  pcVar4 = *(char **)(param_1 + 0x18);
  uVar6 = 0x3c;
  cVar3 = *pcVar4;
  pcVar8 = pcVar4;
  if (cVar3 == 'n') {
    pcVar8 = pcVar4 + 1;
    uVar6 = 0x3d;
    *(char **)(param_1 + 0x18) = pcVar8;
    cVar3 = pcVar4[1];
  }
  pcVar4 = pcVar8;
  if (cVar3 == 'E') {
    iVar7 = 0;
  }
  else {
    do {
      if (cVar3 == '\0') {
        return 0;
      }
      pcVar4 = pcVar4 + 1;
      *(char **)(param_1 + 0x18) = pcVar4;
      cVar3 = *pcVar4;
    } while (cVar3 != 'E');
    iVar7 = (int)pcVar4 - (int)pcVar8;
  }
  iVar1 = *(int *)(param_1 + 0x28);
  if (iVar1 < *(int *)(param_1 + 0x2c)) {
    puVar5 = (undefined8 *)(*(long *)(param_1 + 0x20) + (long)iVar1 * 0x18);
    *(undefined4 *)((long)puVar5 + 4) = 0;
    *(int *)(param_1 + 0x28) = iVar1 + 1;
    if ((pcVar8 == (char *)0x0) || (iVar7 == 0)) goto LAB_00c7b2f0;
    *puVar5 = 0;
    puVar5[1] = pcVar8;
    *(int *)(puVar5 + 2) = iVar7;
  }
  else {
LAB_00c7b2f0:
    puVar5 = (undefined8 *)0x0;
  }
  uVar6 = FUN_00c7a6a0(param_1,uVar6,piVar2,puVar5);
  pcVar4 = *(char **)(param_1 + 0x18);
  cVar3 = *pcVar4;
joined_r0x00c7b2a9:
  if (cVar3 != 'E') {
    return 0;
  }
  *(char **)(param_1 + 0x18) = pcVar4 + 1;
  return uVar6;
}


// ==== entry=00c7b300 orig=FUN_00c7b300 size=1638 name=demangle_parseType ====

int * demangle_parseType(long param_1)

{
  char cVar1;
  int iVar2;
  undefined8 *puVar3;
  bool bVar4;
  uint uVar5;
  int iVar6;
  int *piVar7;
  long lVar8;
  undefined8 uVar9;
  undefined8 uVar10;
  char *pcVar11;
  undefined8 uVar12;
  
  pcVar11 = *(char **)(param_1 + 0x18);
  cVar1 = *pcVar11;
  if (cVar1 == 'L') {
    piVar7 = (int *)FUN_00c7b170();
    return piVar7;
  }
  if (cVar1 == 'T') {
    piVar7 = (int *)FUN_00c7aa10();
    return piVar7;
  }
  if (cVar1 == 's') {
    if (pcVar11[1] == 'r') {
      *(char **)(param_1 + 0x18) = pcVar11 + 2;
      piVar7 = (int *)demangle_parse_type();
      uVar9 = yaml_scan_directive(param_1);
      if (**(char **)(param_1 + 0x18) == 'I') {
        *(char **)(param_1 + 0x18) = *(char **)(param_1 + 0x18) + 1;
        uVar12 = FUN_00c7baa0(param_1);
        uVar9 = FUN_00c7a6a0(param_1,4,uVar9,uVar12);
        uVar12 = 1;
      }
      else {
        uVar12 = 1;
      }
      goto LAB_00c7b5db;
    }
    if (pcVar11[1] == 'p') {
      *(char **)(param_1 + 0x18) = pcVar11 + 2;
      piVar7 = (int *)demangle_parseType();
      uVar9 = 0;
      uVar12 = 0x4a;
      goto LAB_00c7b5db;
    }
  }
  else if (cVar1 == 'f') {
    if (pcVar11[1] == 'p') {
      *(char **)(param_1 + 0x18) = pcVar11 + 2;
      if (pcVar11[2] == 'T') {
        iVar6 = 0;
        *(char **)(param_1 + 0x18) = pcVar11 + 3;
      }
      else {
        uVar5 = FUN_00c7a9c0();
        iVar6 = uVar5 + 1;
        if ((uVar5 & 0x7fffffff) == 0x7fffffff) {
          return (int *)0x0;
        }
      }
      iVar2 = *(int *)(param_1 + 0x28);
      if (*(int *)(param_1 + 0x2c) <= iVar2) {
        return (int *)0x0;
      }
      piVar7 = (int *)(*(long *)(param_1 + 0x20) + (long)iVar2 * 0x18);
      piVar7[1] = 0;
      *(int *)(param_1 + 0x28) = iVar2 + 1;
      *piVar7 = 6;
      *(long *)(piVar7 + 2) = (long)iVar6;
      return piVar7;
    }
  }
  else {
    if ((byte)(cVar1 - 0x30U) < 10) {
LAB_00c7b33c:
      piVar7 = (int *)yaml_scan_directive(param_1);
      if (piVar7 == (int *)0x0) {
        return (int *)0x0;
      }
      if (**(char **)(param_1 + 0x18) != 'I') {
        return piVar7;
      }
      *(char **)(param_1 + 0x18) = *(char **)(param_1 + 0x18) + 1;
      uVar9 = FUN_00c7baa0(param_1);
      uVar12 = 4;
      goto LAB_00c7b5db;
    }
    if (cVar1 == 'o') {
      if (pcVar11[1] == 'n') {
        *(char **)(param_1 + 0x18) = pcVar11 + 2;
        goto LAB_00c7b33c;
      }
    }
    else if (((cVar1 == 'i') || (cVar1 == 't')) && (pcVar11[1] == 'l')) {
      piVar7 = (int *)0x0;
      if (cVar1 == 't') {
        piVar7 = (int *)demangle_parse_type(param_1);
        pcVar11 = *(char **)(param_1 + 0x18);
        if (pcVar11[1] == '\0') {
          return (int *)0x0;
        }
      }
      *(char **)(param_1 + 0x18) = pcVar11 + 2;
      uVar9 = FUN_00c7b9a0(param_1,0x45);
      uVar12 = 0x30;
      goto LAB_00c7b5db;
    }
  }
  piVar7 = (int *)FUN_00c7cc40(param_1);
  if (piVar7 == (int *)0x0) {
    return (int *)0x0;
  }
  iVar6 = *piVar7;
  if (iVar6 == 0x31) {
    puVar3 = *(undefined8 **)(piVar7 + 2);
    pcVar11 = (char *)*puVar3;
    *(int *)(param_1 + 0x48) = *(int *)(param_1 + 0x48) + *(int *)(puVar3 + 2) + -2;
    if (*pcVar11 == 's') {
      if ((pcVar11[1] == 't') && (pcVar11[2] == '\0')) {
        uVar9 = demangle_parse_type(param_1);
        uVar12 = 0x36;
        goto LAB_00c7b5db;
      }
      iVar6 = *(int *)((long)puVar3 + 0x14);
      if (iVar6 != 1) {
        if (1 < iVar6) {
          if (iVar6 == 2) goto LAB_00c7b7a0;
          if (iVar6 != 3) {
            return (int *)0x0;
          }
          if (pcVar11 == (char *)0x0) {
            return (int *)0x0;
          }
          goto LAB_00c7b53b;
        }
        goto LAB_00c7b6e2;
      }
    }
    else {
      iVar6 = *(int *)((long)puVar3 + 0x14);
      if (iVar6 != 1) {
        if (iVar6 < 2) {
LAB_00c7b6e2:
          if (iVar6 != 0) {
            return (int *)0x0;
          }
          uVar9 = 0;
          uVar12 = 0x35;
          goto LAB_00c7b5db;
        }
        if (iVar6 == 2) {
LAB_00c7b7a0:
          if ((((char *)**(undefined8 **)(piVar7 + 2))[1] == 'c') &&
             ((cVar1 = *(char *)**(undefined8 **)(piVar7 + 2), (byte)(cVar1 + 0x8eU) < 2 ||
              ((byte)(cVar1 + 0x9dU) < 2)))) {
            uVar9 = demangle_parse_type(param_1);
          }
          else if (*pcVar11 == 'f') {
            uVar9 = FUN_00c7cc40(param_1);
          }
          else {
            uVar9 = demangle_parseType(param_1);
          }
          cVar1 = *pcVar11;
          if (cVar1 == 'c') {
            if ((pcVar11[1] != 'l') || (pcVar11[2] != '\0')) goto LAB_00c7b7ea;
            uVar12 = FUN_00c7b9a0(param_1,0x45);
          }
          else if ((((cVar1 == 'd') || (cVar1 == 'p')) && (pcVar11[1] == 't')) &&
                  (pcVar11[2] == '\0')) {
            uVar12 = yaml_scan_directive(param_1);
            if (**(char **)(param_1 + 0x18) == 'I') {
              *(char **)(param_1 + 0x18) = *(char **)(param_1 + 0x18) + 1;
              uVar10 = FUN_00c7baa0(param_1);
              uVar12 = FUN_00c7a6a0(param_1,4,uVar12,uVar10);
            }
          }
          else {
LAB_00c7b7ea:
            uVar12 = demangle_parseType(param_1);
          }
          uVar9 = FUN_00c7a6a0(param_1,0x38,uVar9,uVar12);
          uVar12 = 0x37;
          goto LAB_00c7b5db;
        }
        if (iVar6 != 3) {
          return (int *)0x0;
        }
LAB_00c7b53b:
        cVar1 = *pcVar11;
        if (cVar1 == 'q') {
          if (pcVar11[1] != 'u') {
            return (int *)0x0;
          }
          if (pcVar11[2] != '\0') {
            return (int *)0x0;
          }
          demangle_parseType(param_1);
LAB_00c7b568:
          uVar9 = demangle_parseType(param_1);
          lVar8 = demangle_parseType(param_1);
          if (lVar8 == 0) {
            return (int *)0x0;
          }
        }
        else {
          if (cVar1 == 'f') {
            FUN_00c7cc40(param_1);
            goto LAB_00c7b568;
          }
          if (cVar1 != 'n') {
            return (int *)0x0;
          }
          if ((pcVar11[1] != 'w') && (pcVar11[1] != 'a')) {
            return (int *)0x0;
          }
          FUN_00c7b9a0(param_1,0x5f);
          uVar9 = demangle_parse_type(param_1);
          pcVar11 = *(char **)(param_1 + 0x18);
          cVar1 = *pcVar11;
          if (cVar1 == 'E') {
            *(char **)(param_1 + 0x18) = pcVar11 + 1;
            lVar8 = 0;
          }
          else if (cVar1 == 'p') {
            if (pcVar11[1] != 'i') {
              return (int *)0x0;
            }
            *(char **)(param_1 + 0x18) = pcVar11 + 2;
            lVar8 = FUN_00c7b9a0(param_1,0x45);
          }
          else {
            if (cVar1 != 'i') {
              return (int *)0x0;
            }
            if (pcVar11[1] != 'l') {
              return (int *)0x0;
            }
            lVar8 = demangle_parseType(param_1);
          }
        }
        FUN_00c7a6a0(param_1,0x3b,uVar9,lVar8);
        uVar9 = FUN_00c7a6a0();
        uVar12 = 0x39;
        goto LAB_00c7b5db;
      }
    }
    cVar1 = *pcVar11;
    if (((cVar1 == 'p') || (cVar1 == 'm')) && (cVar1 == pcVar11[1])) {
      bVar4 = true;
      if (**(char **)(param_1 + 0x18) == '_') {
        *(char **)(param_1 + 0x18) = *(char **)(param_1 + 0x18) + 1;
        goto LAB_00c7b70d;
      }
    }
    else {
LAB_00c7b70d:
      bVar4 = false;
    }
    if (((*pcVar11 == 's') && (pcVar11[1] == 'P')) && (pcVar11[2] == '\0')) {
      uVar9 = FUN_00c7baa0(param_1);
    }
    else {
LAB_00c7b3c0:
      uVar9 = demangle_parseType(param_1);
    }
    if (bVar4) {
      uVar9 = FUN_00c7a6a0(param_1,0x38,uVar9,uVar9);
    }
  }
  else if (iVar6 == 0x32) {
    iVar6 = piVar7[2];
    if (iVar6 != 1) {
      if (1 < iVar6) {
        return (int *)0x0;
      }
      goto LAB_00c7b6e2;
    }
    uVar9 = demangle_parseType(param_1);
  }
  else {
    if (iVar6 != 0x33) {
      return (int *)0x0;
    }
    if (**(char **)(param_1 + 0x18) != '_') {
      bVar4 = false;
      goto LAB_00c7b3c0;
    }
    *(char **)(param_1 + 0x18) = *(char **)(param_1 + 0x18) + 1;
    uVar9 = FUN_00c7b9a0(param_1,0x45);
  }
  uVar12 = 0x36;
LAB_00c7b5db:
  piVar7 = (int *)FUN_00c7a6a0(param_1,uVar12,piVar7,uVar9);
  return piVar7;
}


// ==== entry=00c7b9a0 name=FUN_00c7b9a0 size=221 ====

undefined8 FUN_00c7b9a0(long param_1,char param_2)

{
  undefined4 uVar1;
  long lVar2;
  undefined8 uVar3;
  long *plVar4;
  long in_FS_OFFSET;
  long local_38;
  long local_30;
  
  plVar4 = &local_38;
  local_30 = *(long *)(in_FS_OFFSET + 0x28);
  local_38 = 0;
  if (**(char **)(param_1 + 0x18) == param_2) {
    *(char **)(param_1 + 0x18) = *(char **)(param_1 + 0x18) + 1;
    if (local_30 == *(long *)(in_FS_OFFSET + 0x28)) {
      uVar3 = FUN_00c7a6a0(param_1,0x2e,0,0);
      return uVar3;
    }
  }
  else {
    do {
      uVar1 = *(undefined4 *)(param_1 + 0x4c);
      *(undefined4 *)(param_1 + 0x4c) = 1;
      lVar2 = demangle_parseType(param_1);
      *(undefined4 *)(param_1 + 0x4c) = uVar1;
      if (lVar2 == 0) {
LAB_00c7ba24:
        lVar2 = 0;
        goto LAB_00c7ba26;
      }
      lVar2 = FUN_00c7a6a0(param_1,0x2e,lVar2,0);
      *plVar4 = lVar2;
      if (lVar2 == 0) goto LAB_00c7ba24;
      plVar4 = (long *)(lVar2 + 0x10);
    } while (**(char **)(param_1 + 0x18) != param_2);
    *(char **)(param_1 + 0x18) = *(char **)(param_1 + 0x18) + 1;
    lVar2 = local_38;
LAB_00c7ba26:
    if (local_30 == *(long *)(in_FS_OFFSET + 0x28)) {
      return lVar2;
    }
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ==== entry=00c7baa0 name=FUN_00c7baa0 size=321 ====

long FUN_00c7baa0(long param_1)

{
  char cVar1;
  undefined4 uVar2;
  long lVar3;
  undefined8 uVar4;
  char *pcVar5;
  long *plVar6;
  long in_FS_OFFSET;
  long local_38;
  long local_30;
  
  plVar6 = &local_38;
  pcVar5 = *(char **)(param_1 + 0x18);
  uVar4 = *(undefined8 *)(param_1 + 0x40);
  local_30 = *(long *)(in_FS_OFFSET + 0x28);
  cVar1 = *pcVar5;
  if (cVar1 == 'E') {
    *(char **)(param_1 + 0x18) = pcVar5 + 1;
    if (local_30 == *(long *)(in_FS_OFFSET + 0x28)) {
      uVar4 = FUN_00c7a6a0(param_1,0x2f,0,0);
      return uVar4;
    }
  }
  else {
    local_38 = 0;
    do {
      if (cVar1 != 'L') {
        if (cVar1 < 'M') {
          if (1 < (byte)(cVar1 + 0xb7U)) goto LAB_00c7bb80;
          lVar3 = FUN_00c7bc00(param_1);
          goto LAB_00c7baf3;
        }
        if (cVar1 != 'X') {
LAB_00c7bb80:
          lVar3 = demangle_parse_type(param_1);
          goto LAB_00c7baf3;
        }
        uVar2 = *(undefined4 *)(param_1 + 0x4c);
        *(undefined4 *)(param_1 + 0x4c) = 1;
        *(char **)(param_1 + 0x18) = pcVar5 + 1;
        lVar3 = demangle_parseType(param_1);
        *(undefined4 *)(param_1 + 0x4c) = uVar2;
        if (**(char **)(param_1 + 0x18) == 'E') {
          *(char **)(param_1 + 0x18) = *(char **)(param_1 + 0x18) + 1;
          goto LAB_00c7baf3;
        }
LAB_00c7bb90:
        lVar3 = 0;
        goto LAB_00c7bb92;
      }
      lVar3 = FUN_00c7b170(param_1);
LAB_00c7baf3:
      if (lVar3 == 0) goto LAB_00c7bb90;
      lVar3 = FUN_00c7a6a0(param_1,0x2f,lVar3,0);
      *plVar6 = lVar3;
      if (lVar3 == 0) goto LAB_00c7bb90;
      pcVar5 = *(char **)(param_1 + 0x18);
      plVar6 = (long *)(lVar3 + 0x10);
      cVar1 = *pcVar5;
    } while (cVar1 != 'E');
    *(undefined8 *)(param_1 + 0x40) = uVar4;
    *(char **)(param_1 + 0x18) = pcVar5 + 1;
    lVar3 = local_38;
LAB_00c7bb92:
    if (local_30 == *(long *)(in_FS_OFFSET + 0x28)) {
      return lVar3;
    }
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ==== entry=00c7bc00 name=FUN_00c7bc00 size=30 ====

undefined8 FUN_00c7bc00(long param_1)

{
  undefined8 uVar1;
  
  if ((byte)(**(char **)(param_1 + 0x18) + 0xb7U) < 2) {
    *(char **)(param_1 + 0x18) = *(char **)(param_1 + 0x18) + 1;
    uVar1 = FUN_00c7baa0();
    return uVar1;
  }
  return 0;
}


// ==== entry=00c7bc30 name=FUN_00c7bc30 size=1339 ====

long FUN_00c7bc30(long param_1)

{
  int *piVar1;
  byte bVar2;
  uint uVar3;
  int iVar4;
  int *piVar5;
  uint *puVar6;
  long lVar7;
  long *plVar8;
  long lVar9;
  undefined8 uVar10;
  uint *puVar11;
  long lVar12;
  undefined8 *puVar13;
  char cVar14;
  char cVar15;
  char *pcVar16;
  char *pcVar17;
  long in_FS_OFFSET;
  long local_48;
  long local_40;
  
  pcVar16 = *(char **)(param_1 + 0x18);
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  cVar14 = *pcVar16;
  if (cVar14 == 'S') {
    if (pcVar16[1] == 't') {
      *(char **)(param_1 + 0x18) = pcVar16 + 2;
      uVar10 = yaml_scan_directive();
      iVar4 = *(int *)(param_1 + 0x28);
      if (iVar4 < *(int *)(param_1 + 0x2c)) {
        *(int *)(param_1 + 0x28) = iVar4 + 1;
        puVar13 = (undefined8 *)(*(long *)(param_1 + 0x20) + (long)iVar4 * 0x18);
        *puVar13 = 0;
        puVar13[1] = &DAT_00d99da9;
        *(undefined4 *)(puVar13 + 2) = 3;
      }
      else {
        puVar13 = (undefined8 *)0x0;
      }
      lVar7 = FUN_00c7a6a0(param_1,1,puVar13,uVar10);
      *(int *)(param_1 + 0x48) = *(int *)(param_1 + 0x48) + 3;
      cVar14 = **(char **)(param_1 + 0x18);
joined_r0x00c7befd:
      if (cVar14 != 'I') goto LAB_00c7bdea;
      if ((lVar7 == 0) || (iVar4 = *(int *)(param_1 + 0x38), *(int *)(param_1 + 0x3c) <= iVar4))
      goto LAB_00c7bde8;
      *(long *)(*(long *)(param_1 + 0x30) + (long)iVar4 * 8) = lVar7;
      *(int *)(param_1 + 0x38) = iVar4 + 1;
    }
    else {
      lVar7 = FUN_00c7ac40(param_1,0);
      if (**(char **)(param_1 + 0x18) != 'I') goto LAB_00c7bdea;
    }
    uVar10 = FUN_00c7bc00(param_1);
    lVar7 = FUN_00c7a6a0(param_1,4,lVar7,uVar10);
    goto LAB_00c7bdea;
  }
  if (cVar14 < 'T') {
    if (cVar14 != 'N') {
LAB_00c7be30:
      lVar7 = yaml_scan_directive(param_1);
      cVar14 = **(char **)(param_1 + 0x18);
      goto joined_r0x00c7befd;
    }
    *(char **)(param_1 + 0x18) = pcVar16 + 1;
    plVar8 = (long *)FUN_00c7ced0(param_1,&local_48,1);
    if (plVar8 != (long *)0x0) {
      lVar9 = FUN_00c7a710(param_1,0);
      pcVar16 = *(char **)(param_1 + 0x18);
      cVar14 = *pcVar16;
      lVar7 = 0;
LAB_00c7bd4c:
      if (cVar14 != '\0') {
        pcVar17 = pcVar16;
        if (cVar14 == 'D') {
          if ((pcVar16[1] & 0xdfU) == 0x54) {
            lVar12 = demangle_parse_type();
            goto LAB_00c7bf87;
          }
          lVar12 = yaml_scan_directive(param_1);
          goto LAB_00c7bf87;
        }
        do {
          bVar2 = (byte)(0x20100803ff >> (cVar14 - 0x30U & 0x3f)) & 1;
          if (0x25 < (byte)(cVar14 - 0x30U)) {
            bVar2 = 0;
          }
          if (((byte)(cVar14 + 0x9fU) < 0x1a) || (bVar2 != 0)) {
            lVar12 = yaml_scan_directive(param_1);
            cVar15 = cVar14;
            if (lVar7 != 0) goto LAB_00c7bfe0;
LAB_00c7bf24:
            lVar7 = lVar12;
            pcVar16 = *(char **)(param_1 + 0x18);
            cVar14 = *pcVar16;
            if (cVar15 == 'S') goto LAB_00c7bd4c;
          }
          else {
            if (cVar14 == 'S') {
              lVar12 = FUN_00c7ac40(param_1,1);
              if (lVar7 != 0) {
LAB_00c7bfe0:
                uVar10 = 1;
LAB_00c7bfc0:
                lVar12 = FUN_00c7a6a0(param_1,uVar10,lVar7,lVar12);
                cVar15 = cVar14;
                goto LAB_00c7bf24;
              }
              pcVar16 = *(char **)(param_1 + 0x18);
              cVar14 = *pcVar16;
              lVar7 = lVar12;
              goto LAB_00c7bd4c;
            }
            if (cVar14 == 'I') {
              if (lVar7 != 0) {
                *(char **)(param_1 + 0x18) = pcVar17 + 1;
                lVar12 = FUN_00c7baa0(param_1);
                uVar10 = 4;
                goto LAB_00c7bfc0;
              }
              break;
            }
            if (cVar14 != 'T') {
              if (cVar14 != 'E') {
                if ((lVar7 == 0) || (cVar14 != 'M')) break;
                pcVar16 = pcVar17 + 1;
                *(char **)(param_1 + 0x18) = pcVar16;
                cVar14 = pcVar17[1];
                goto LAB_00c7bd4c;
              }
              *plVar8 = lVar7;
              if (lVar7 == 0) goto LAB_00c7bde8;
              if (lVar9 != 0) {
                *(long *)(lVar9 + 8) = local_48;
                local_48 = lVar9;
              }
              if (*pcVar17 != 'E') goto LAB_00c7bde8;
              *(char **)(param_1 + 0x18) = pcVar17 + 1;
              lVar7 = local_48;
              goto LAB_00c7bdea;
            }
            lVar12 = FUN_00c7aa10(param_1);
LAB_00c7bf87:
            uVar10 = 1;
            if (lVar7 != 0) goto LAB_00c7bfc0;
            pcVar16 = *(char **)(param_1 + 0x18);
            cVar14 = *pcVar16;
            lVar7 = lVar12;
          }
          if (cVar14 != 'E') goto code_r0x00c7bf3e;
          cVar14 = 'E';
          pcVar17 = pcVar16;
        } while( true );
      }
      goto LAB_00c7bde0;
    }
  }
  else {
    if (cVar14 == 'U') {
      lVar7 = yaml_scan_directive();
      goto LAB_00c7bdea;
    }
    if (cVar14 != 'Z') goto LAB_00c7be30;
    *(char **)(param_1 + 0x18) = pcVar16 + 1;
    piVar5 = (int *)FUN_00c7d680(param_1,0);
    if ((piVar5 != (int *)0x0) && (pcVar16 = *(char **)(param_1 + 0x18), *pcVar16 == 'E')) {
      *(char **)(param_1 + 0x18) = pcVar16 + 1;
      if (pcVar16[1] == 's') {
        *(char **)(param_1 + 0x18) = pcVar16 + 2;
        iVar4 = FUN_00c7af10(param_1);
        if (iVar4 != 0) {
          iVar4 = *(int *)(param_1 + 0x28);
          if (iVar4 < *(int *)(param_1 + 0x2c)) {
            *(int *)(param_1 + 0x28) = iVar4 + 1;
            puVar6 = (uint *)(*(long *)(param_1 + 0x20) + (long)iVar4 * 0x18);
            puVar6[0] = 0;
            puVar6[1] = 0;
            *(char **)(puVar6 + 2) = "string literal";
            puVar6[4] = 0xe;
          }
          else {
LAB_00c7c196:
            puVar6 = (uint *)0x0;
          }
          goto LAB_00c7bcda;
        }
      }
      else if (pcVar16[1] == 'd') {
        *(char **)(param_1 + 0x18) = pcVar16 + 2;
        uVar3 = FUN_00c7a9c0(param_1);
        if ((-1 < (int)uVar3) &&
           (((puVar11 = (uint *)FUN_00c7bc30(param_1), puVar11 == (uint *)0x0 ||
             ((*puVar11 & 0xfffffffd) == 0x45)) || (iVar4 = FUN_00c7af10(param_1), iVar4 != 0)))) {
          iVar4 = *(int *)(param_1 + 0x28);
          if (*(int *)(param_1 + 0x2c) <= iVar4) goto LAB_00c7c196;
          puVar6 = (uint *)(*(long *)(param_1 + 0x20) + (long)iVar4 * 0x18);
          puVar6[1] = 0;
          *(int *)(param_1 + 0x28) = iVar4 + 1;
          *puVar6 = 0x46;
          puVar6[4] = uVar3;
          *(uint **)(puVar6 + 2) = puVar11;
          goto LAB_00c7bcda;
        }
      }
      else {
        puVar6 = (uint *)FUN_00c7bc30(param_1);
        if (((puVar6 == (uint *)0x0) || ((*puVar6 & 0xfffffffd) == 0x45)) ||
           (iVar4 = FUN_00c7af10(param_1), iVar4 != 0)) {
LAB_00c7bcda:
          if ((*piVar5 == 3) && (piVar1 = *(int **)(piVar5 + 4), *piVar1 == 0x29)) {
            piVar1[2] = 0;
            piVar1[3] = 0;
          }
          lVar7 = FUN_00c7a6a0(param_1,2,piVar5,puVar6);
          goto LAB_00c7bdea;
        }
      }
    }
  }
  goto LAB_00c7bde8;
code_r0x00c7bf3e:
  if ((lVar7 == 0) || (iVar4 = *(int *)(param_1 + 0x38), *(int *)(param_1 + 0x3c) <= iVar4))
  goto LAB_00c7bde0;
  *(long *)(*(long *)(param_1 + 0x30) + (long)iVar4 * 8) = lVar7;
  *(int *)(param_1 + 0x38) = iVar4 + 1;
  cVar14 = *pcVar16;
  goto LAB_00c7bd4c;
LAB_00c7bde0:
  *plVar8 = 0;
LAB_00c7bde8:
  lVar7 = 0;
LAB_00c7bdea:
  if (local_40 == *(long *)(in_FS_OFFSET + 0x28)) {
    return lVar7;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ==== entry=00c7c1d0 orig=FUN_00c7c1d0 size=2692 name=demangle_parse_type ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int * demangle_parse_type(long param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  code *pcVar4;
  int iVar5;
  undefined8 *puVar6;
  int *piVar7;
  undefined8 uVar8;
  long lVar9;
  char *pcVar10;
  char cVar11;
  long lVar12;
  char *pcVar13;
  char *pcVar14;
  int iVar15;
  long in_FS_OFFSET;
  int *local_38;
  long local_30;
  
  pcVar13 = *(char **)(param_1 + 0x18);
  local_30 = *(long *)(in_FS_OFFSET + 0x28);
  iVar5 = FUN_00c7aec0(pcVar13);
  if (iVar5 != 0) {
    puVar6 = (undefined8 *)FUN_00c7ced0(param_1,&local_38,0);
    if (puVar6 != (undefined8 *)0x0) {
      if (**(char **)(param_1 + 0x18) == 'F') {
        piVar7 = (int *)FUN_00c7d190(param_1);
        *puVar6 = piVar7;
      }
      else {
        piVar7 = (int *)demangle_parse_type();
        *puVar6 = piVar7;
      }
      if (piVar7 != (int *)0x0) {
        if (*piVar7 - 0x1fU < 2) {
          uVar8 = *(undefined8 *)(piVar7 + 2);
          *(int **)(piVar7 + 2) = local_38;
          local_38 = (int *)*puVar6;
          *puVar6 = uVar8;
        }
        if ((local_38 != (int *)0x0) &&
           (iVar5 = *(int *)(param_1 + 0x38), iVar5 < *(int *)(param_1 + 0x3c))) {
          *(int **)(*(long *)(param_1 + 0x30) + (long)iVar5 * 8) = local_38;
          *(int *)(param_1 + 0x38) = iVar5 + 1;
          piVar7 = local_38;
          goto LAB_00c7c272;
        }
      }
    }
    goto switchD_00c7c21e_caseD_3a;
  }
  switch(*pcVar13) {
  case '0':
  case '1':
  case '2':
  case '3':
  case '4':
  case '5':
  case '6':
  case '7':
  case '8':
  case '9':
  case 'N':
  case 'Z':
    local_38 = (int *)FUN_00c7bc30(param_1);
    break;
  default:
    goto switchD_00c7c21e_caseD_3a;
  case 'A':
    pcVar14 = pcVar13 + 1;
    *(char **)(param_1 + 0x18) = pcVar14;
    if (pcVar13[1] == '_') {
      puVar6 = (undefined8 *)0x0;
LAB_00c7c710:
      *(char **)(param_1 + 0x18) = pcVar14 + 1;
      uVar8 = demangle_parse_type(param_1);
      local_38 = (int *)FUN_00c7a6a0(param_1,0x2a,puVar6,uVar8);
      break;
    }
    pcVar10 = pcVar14;
    if ((byte)(pcVar13[1] - 0x30U) < 10) {
      do {
        pcVar13 = pcVar10;
        pcVar10 = pcVar13 + 1;
        *(char **)(param_1 + 0x18) = pcVar10;
      } while ((byte)(pcVar13[1] - 0x30U) < 10);
      iVar5 = *(int *)(param_1 + 0x28);
      iVar15 = (int)pcVar10 - (int)pcVar14;
      if (iVar5 < *(int *)(param_1 + 0x2c)) {
        puVar6 = (undefined8 *)(*(long *)(param_1 + 0x20) + (long)iVar5 * 0x18);
        *(undefined4 *)((long)puVar6 + 4) = 0;
        *(int *)(param_1 + 0x28) = iVar5 + 1;
        if (iVar15 != 0) {
          *puVar6 = 0;
          puVar6[1] = pcVar14;
          *(int *)(puVar6 + 2) = iVar15;
          cVar11 = pcVar13[1];
          goto LAB_00c7c701;
        }
      }
    }
    else {
      uVar1 = *(undefined4 *)(param_1 + 0x4c);
      *(undefined4 *)(param_1 + 0x4c) = 1;
      puVar6 = (undefined8 *)demangle_parseType(param_1);
      *(undefined4 *)(param_1 + 0x4c) = uVar1;
      if (puVar6 != (undefined8 *)0x0) {
        pcVar10 = *(char **)(param_1 + 0x18);
        cVar11 = *pcVar10;
LAB_00c7c701:
        pcVar14 = pcVar10;
        if (cVar11 == '_') goto LAB_00c7c710;
      }
    }
    goto switchD_00c7c21e_caseD_3a;
  case 'C':
    *(char **)(param_1 + 0x18) = pcVar13 + 1;
    uVar8 = demangle_parse_type(param_1);
    local_38 = (int *)FUN_00c7a6a0(param_1,0x25,uVar8,0);
    break;
  case 'D':
    *(char **)(param_1 + 0x18) = pcVar13 + 1;
    if (pcVar13[1] == '\0') goto switchD_00c7c21e_caseD_3a;
    *(char **)(param_1 + 0x18) = pcVar13 + 2;
    switch(pcVar13[1]) {
    case 'F':
      iVar5 = *(int *)(param_1 + 0x28);
      if (*(int *)(param_1 + 0x2c) <= iVar5) {
        _DAT_00000000 = 0;
                    /* WARNING: Does not return */
        pcVar4 = (code *)invalidInstructionException();
        (*pcVar4)();
      }
      local_38 = (int *)(*(long *)(param_1 + 0x20) + (long)iVar5 * 0x18);
      local_38[1] = 0;
      *(int *)(param_1 + 0x28) = iVar5 + 1;
      *local_38 = 0x2c;
      cVar11 = pcVar13[2];
      *(ushort *)(local_38 + 4) = (ushort)((byte)(cVar11 - 0x30U) < 10);
      if ((byte)(cVar11 - 0x30U) < 10) {
        FUN_00c7a8c0(param_1 + 0x18);
      }
      piVar7 = local_38;
      uVar8 = demangle_parse_type(param_1);
      *(undefined8 *)(piVar7 + 2) = uVar8;
      if (*(long *)(local_38 + 2) != 0) {
        FUN_00c7a8c0(param_1 + 0x18);
        pcVar13 = *(char **)(param_1 + 0x18);
        cVar11 = '\0';
        if (*pcVar13 != '\0') {
          *(char **)(param_1 + 0x18) = pcVar13 + 1;
          cVar11 = *pcVar13;
        }
        *(ushort *)((long)local_38 + 0x12) = (ushort)(cVar11 == 's');
        piVar7 = local_38;
        break;
      }
    default:
      goto switchD_00c7c21e_caseD_3a;
    case 'T':
    case 't':
      uVar1 = *(undefined4 *)(param_1 + 0x4c);
      *(undefined4 *)(param_1 + 0x4c) = 1;
      uVar8 = demangle_parseType(param_1);
      *(undefined4 *)(param_1 + 0x4c) = uVar1;
      local_38 = (int *)FUN_00c7a6a0(param_1,0x42,uVar8,0);
      if (((local_38 != (int *)0x0) && (pcVar13 = *(char **)(param_1 + 0x18), *pcVar13 != '\0')) &&
         (*(char **)(param_1 + 0x18) = pcVar13 + 1, *pcVar13 == 'E')) goto LAB_00c7c349;
      goto switchD_00c7c21e_caseD_3a;
    case 'a':
      iVar5 = *(int *)(param_1 + 0x28);
      if (iVar5 < *(int *)(param_1 + 0x2c)) {
        *(int *)(param_1 + 0x28) = iVar5 + 1;
        piVar7 = (int *)(*(long *)(param_1 + 0x20) + (long)iVar5 * 0x18);
        piVar7[0] = 0;
        piVar7[1] = 0;
        *(undefined **)(piVar7 + 2) = &DAT_00c90a4d;
        piVar7[4] = 4;
        break;
      }
      goto switchD_00c7c21e_caseD_3a;
    case 'c':
      iVar5 = *(int *)(param_1 + 0x28);
      if (iVar5 < *(int *)(param_1 + 0x2c)) {
        *(int *)(param_1 + 0x28) = iVar5 + 1;
        piVar7 = (int *)(*(long *)(param_1 + 0x20) + (long)iVar5 * 0x18);
        piVar7[0] = 0;
        piVar7[1] = 0;
        *(char **)(piVar7 + 2) = "decltype(auto)";
        piVar7[4] = 0xe;
        break;
      }
      goto switchD_00c7c21e_caseD_3a;
    case 'd':
      iVar5 = *(int *)(param_1 + 0x28);
      if (*(int *)(param_1 + 0x2c) <= iVar5) {
        local_38 = (int *)0x0;
                    /* WARNING: Does not return */
        pcVar4 = (code *)invalidInstructionException();
        (*pcVar4)();
      }
      piVar7 = (int *)(*(long *)(param_1 + 0x20) + (long)iVar5 * 0x18);
      piVar7[1] = 0;
      *(int *)(param_1 + 0x28) = iVar5 + 1;
      *piVar7 = 0x27;
      *(undefined ***)(piVar7 + 2) = &PTR_s_decimal64_01183bc0;
      *(int *)(param_1 + 0x48) = *(int *)(param_1 + 0x48) + 9;
      break;
    case 'e':
      iVar5 = *(int *)(param_1 + 0x28);
      if (*(int *)(param_1 + 0x2c) <= iVar5) {
        local_38 = (int *)0x0;
                    /* WARNING: Does not return */
        pcVar4 = (code *)invalidInstructionException();
        (*pcVar4)();
      }
      piVar7 = (int *)(*(long *)(param_1 + 0x20) + (long)iVar5 * 0x18);
      piVar7[1] = 0;
      *(int *)(param_1 + 0x28) = iVar5 + 1;
      *piVar7 = 0x27;
      *(undefined ***)(piVar7 + 2) = &PTR_s_decimal128_01183be0;
      *(int *)(param_1 + 0x48) = *(int *)(param_1 + 0x48) + 10;
      break;
    case 'f':
      iVar5 = *(int *)(param_1 + 0x28);
      if (*(int *)(param_1 + 0x2c) <= iVar5) {
        local_38 = (int *)0x0;
                    /* WARNING: Does not return */
        pcVar4 = (code *)invalidInstructionException();
        (*pcVar4)();
      }
      piVar7 = (int *)(*(long *)(param_1 + 0x20) + (long)iVar5 * 0x18);
      piVar7[1] = 0;
      *(int *)(param_1 + 0x28) = iVar5 + 1;
      *piVar7 = 0x27;
      *(undefined ***)(piVar7 + 2) = &PTR_s_decimal32_01183ba0;
      *(int *)(param_1 + 0x48) = *(int *)(param_1 + 0x48) + 9;
      break;
    case 'h':
      iVar5 = *(int *)(param_1 + 0x28);
      if (*(int *)(param_1 + 0x2c) <= iVar5) {
        local_38 = (int *)0x0;
                    /* WARNING: Does not return */
        pcVar4 = (code *)invalidInstructionException();
        (*pcVar4)();
      }
      piVar7 = (int *)(*(long *)(param_1 + 0x20) + (long)iVar5 * 0x18);
      piVar7[1] = 0;
      *(int *)(param_1 + 0x28) = iVar5 + 1;
      *piVar7 = 0x27;
      *(undefined ***)(piVar7 + 2) = &PTR_DAT_01183c00;
      *(int *)(param_1 + 0x48) = *(int *)(param_1 + 0x48) + 4;
      break;
    case 'i':
      iVar5 = *(int *)(param_1 + 0x28);
      if (*(int *)(param_1 + 0x2c) <= iVar5) {
        local_38 = (int *)0x0;
                    /* WARNING: Does not return */
        pcVar4 = (code *)invalidInstructionException();
        (*pcVar4)();
      }
      piVar7 = (int *)(*(long *)(param_1 + 0x20) + (long)iVar5 * 0x18);
      piVar7[1] = 0;
      *(int *)(param_1 + 0x28) = iVar5 + 1;
      *piVar7 = 0x27;
      *(undefined ***)(piVar7 + 2) = &PTR_s_char32_t_01183c40;
      *(int *)(param_1 + 0x48) = *(int *)(param_1 + 0x48) + 8;
      break;
    case 'n':
      iVar5 = *(int *)(param_1 + 0x28);
      if (*(int *)(param_1 + 0x2c) <= iVar5) {
        local_38 = (int *)0x0;
                    /* WARNING: Does not return */
        pcVar4 = (code *)invalidInstructionException();
        (*pcVar4)();
      }
      piVar7 = (int *)(*(long *)(param_1 + 0x20) + (long)iVar5 * 0x18);
      piVar7[1] = 0;
      *(int *)(param_1 + 0x28) = iVar5 + 1;
      *piVar7 = 0x27;
      *(undefined ***)(piVar7 + 2) = &PTR_s_decltype_nullptr__01183c60;
      *(int *)(param_1 + 0x48) = *(int *)(param_1 + 0x48) + 0x11;
      break;
    case 'p':
      uVar8 = demangle_parse_type(param_1);
      local_38 = (int *)FUN_00c7a6a0(param_1,0x4a,uVar8,0);
      goto LAB_00c7c340;
    case 's':
      iVar5 = *(int *)(param_1 + 0x28);
      if (*(int *)(param_1 + 0x2c) <= iVar5) {
        local_38 = (int *)0x0;
                    /* WARNING: Does not return */
        pcVar4 = (code *)invalidInstructionException();
        (*pcVar4)();
      }
      piVar7 = (int *)(*(long *)(param_1 + 0x20) + (long)iVar5 * 0x18);
      piVar7[1] = 0;
      *(int *)(param_1 + 0x28) = iVar5 + 1;
      *piVar7 = 0x27;
      *(undefined ***)(piVar7 + 2) = &PTR_s_char16_t_01183c20;
      *(int *)(param_1 + 0x48) = *(int *)(param_1 + 0x48) + 8;
      break;
    case 'v':
      if (pcVar13[2] == '_') {
        uVar1 = *(undefined4 *)(param_1 + 0x4c);
        *(undefined4 *)(param_1 + 0x4c) = 1;
        *(char **)(param_1 + 0x18) = pcVar13 + 3;
        lVar12 = demangle_parseType(param_1);
        *(undefined4 *)(param_1 + 0x4c) = uVar1;
      }
      else {
        lVar12 = FUN_00c7a970(param_1);
      }
      if ((lVar12 != 0) && (**(char **)(param_1 + 0x18) == '_')) {
        *(char **)(param_1 + 0x18) = *(char **)(param_1 + 0x18) + 1;
        uVar8 = demangle_parse_type(param_1);
        local_38 = (int *)FUN_00c7a6a0(param_1,0x2d,lVar12,uVar8);
        goto LAB_00c7c340;
      }
      goto switchD_00c7c21e_caseD_3a;
    }
    goto LAB_00c7c272;
  case 'F':
    local_38 = (int *)FUN_00c7d190(param_1);
    break;
  case 'G':
    *(char **)(param_1 + 0x18) = pcVar13 + 1;
    uVar8 = demangle_parse_type(param_1);
    local_38 = (int *)FUN_00c7a6a0(param_1,0x26,uVar8,0);
    break;
  case 'M':
    *(char **)(param_1 + 0x18) = pcVar13 + 1;
    lVar12 = demangle_parse_type(param_1);
    if ((lVar12 != 0) && (lVar9 = demangle_parse_type(param_1), lVar9 != 0)) {
      local_38 = (int *)FUN_00c7a6a0(param_1,0x2b,lVar12,lVar9);
      break;
    }
    goto switchD_00c7c21e_caseD_3a;
  case 'O':
    *(char **)(param_1 + 0x18) = pcVar13 + 1;
    uVar8 = demangle_parse_type(param_1);
    local_38 = (int *)FUN_00c7a6a0(param_1,0x24,uVar8,0);
    break;
  case 'P':
    *(char **)(param_1 + 0x18) = pcVar13 + 1;
    uVar8 = demangle_parse_type(param_1);
    local_38 = (int *)FUN_00c7a6a0(param_1,0x22,uVar8,0);
    break;
  case 'R':
    *(char **)(param_1 + 0x18) = pcVar13 + 1;
    uVar8 = demangle_parse_type(param_1);
    local_38 = (int *)FUN_00c7a6a0(param_1,0x23,uVar8,0);
    break;
  case 'S':
    if (((byte)((byte)pcVar13[1] - 0x30) < 0x30) &&
       ((0x87fffffe03ffU >> ((ulong)((byte)pcVar13[1] - 0x30) & 0x3f) & 1) != 0)) {
      local_38 = (int *)FUN_00c7ac40(param_1,0);
      piVar7 = local_38;
      if (**(char **)(param_1 + 0x18) != 'I') goto LAB_00c7c272;
      *(char **)(param_1 + 0x18) = *(char **)(param_1 + 0x18) + 1;
LAB_00c7c4b1:
      uVar8 = FUN_00c7baa0(param_1);
LAB_00c7c4bc:
      local_38 = (int *)FUN_00c7a6a0(param_1,4,local_38,uVar8);
      break;
    }
    piVar7 = (int *)FUN_00c7bc30(param_1);
    local_38 = piVar7;
    if (piVar7 == (int *)0x0) goto switchD_00c7c21e_caseD_3a;
    if (*piVar7 == 0x18) goto LAB_00c7c272;
    goto LAB_00c7c349;
  case 'T':
    local_38 = (int *)FUN_00c7aa10(param_1);
    pcVar13 = *(char **)(param_1 + 0x18);
    if (*pcVar13 == 'I') {
      if (*(int *)(param_1 + 0x50) == 0) {
        if ((local_38 != (int *)0x0) &&
           (iVar5 = *(int *)(param_1 + 0x38), iVar5 < *(int *)(param_1 + 0x3c))) {
          *(int **)(*(long *)(param_1 + 0x30) + (long)iVar5 * 8) = local_38;
          uVar8 = 0;
          *(int *)(param_1 + 0x38) = iVar5 + 1;
          if ((byte)(*pcVar13 + 0xb7U) < 2) {
            *(char **)(param_1 + 0x18) = pcVar13 + 1;
            goto LAB_00c7c4b1;
          }
          goto LAB_00c7c4bc;
        }
        goto switchD_00c7c21e_caseD_3a;
      }
      uVar1 = *(undefined4 *)(param_1 + 0x28);
      uVar2 = *(undefined4 *)(param_1 + 0x38);
      *(char **)(param_1 + 0x18) = pcVar13 + 1;
      uVar3 = *(undefined4 *)(param_1 + 0x48);
      uVar8 = FUN_00c7baa0(param_1);
      if (**(char **)(param_1 + 0x18) == 'I') {
        if ((local_38 == (int *)0x0) ||
           (iVar5 = *(int *)(param_1 + 0x38), *(int *)(param_1 + 0x3c) <= iVar5))
        goto switchD_00c7c21e_caseD_3a;
        *(int **)(*(long *)(param_1 + 0x30) + (long)iVar5 * 8) = local_38;
        *(int *)(param_1 + 0x38) = iVar5 + 1;
        local_38 = (int *)FUN_00c7a6a0(param_1,4,local_38,uVar8);
      }
      else {
        *(char **)(param_1 + 0x18) = pcVar13;
        *(undefined4 *)(param_1 + 0x28) = uVar1;
        *(undefined4 *)(param_1 + 0x38) = uVar2;
        *(undefined4 *)(param_1 + 0x48) = uVar3;
      }
    }
    break;
  case 'U':
    *(char **)(param_1 + 0x18) = pcVar13 + 1;
    piVar7 = (int *)FUN_00c7aa80(param_1);
    if (**(char **)(param_1 + 0x18) == 'I') {
      *(char **)(param_1 + 0x18) = *(char **)(param_1 + 0x18) + 1;
      local_38 = piVar7;
      uVar8 = FUN_00c7baa0(param_1);
      piVar7 = (int *)FUN_00c7a6a0(param_1,4,local_38,uVar8);
    }
    local_38 = piVar7;
    uVar8 = demangle_parse_type(param_1);
    local_38 = (int *)FUN_00c7a6a0(param_1,0x21,uVar8,piVar7);
    break;
  case 'a':
  case 'b':
  case 'c':
  case 'd':
  case 'e':
  case 'f':
  case 'g':
  case 'h':
  case 'i':
  case 'j':
  case 'l':
  case 'm':
  case 'n':
  case 'o':
  case 's':
  case 't':
  case 'v':
  case 'w':
  case 'x':
  case 'y':
  case 'z':
    iVar5 = *(int *)(param_1 + 0x28);
    lVar12 = (long)(*pcVar13 + -0x61);
    if (*(int *)(param_1 + 0x2c) <= iVar5) {
      local_38 = (int *)0x0;
                    /* WARNING: Does not return */
      pcVar4 = (code *)invalidInstructionException();
      (*pcVar4)();
    }
    piVar7 = (int *)(*(long *)(param_1 + 0x20) + (long)iVar5 * 0x18);
    piVar7[1] = 0;
    *(int *)(param_1 + 0x28) = iVar5 + 1;
    *(undefined ***)(piVar7 + 2) = &PTR_s_signed_char_00d9a1d7_2_01183860 + lVar12 * 4;
    iVar5 = *(int *)(&DAT_01183868 + lVar12 * 0x20);
    *piVar7 = 0x27;
    *(int *)(param_1 + 0x48) = *(int *)(param_1 + 0x48) + iVar5;
    *(char **)(param_1 + 0x18) = pcVar13 + 1;
    goto LAB_00c7c272;
  case 'u':
    *(char **)(param_1 + 0x18) = pcVar13 + 1;
    uVar8 = FUN_00c7aa80(param_1);
    local_38 = (int *)FUN_00c7a6a0(param_1,0x28,uVar8,0);
  }
LAB_00c7c340:
  if (local_38 != (int *)0x0) {
LAB_00c7c349:
    iVar5 = *(int *)(param_1 + 0x38);
    if (iVar5 < *(int *)(param_1 + 0x3c)) {
      *(int **)(*(long *)(param_1 + 0x30) + (long)iVar5 * 8) = local_38;
      *(int *)(param_1 + 0x38) = iVar5 + 1;
      piVar7 = local_38;
      goto LAB_00c7c272;
    }
  }
switchD_00c7c21e_caseD_3a:
  piVar7 = (int *)0x0;
LAB_00c7c272:
  if (local_30 == *(long *)(in_FS_OFFSET + 0x28)) {
    return piVar7;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ==== entry=00c7cc40 name=FUN_00c7cc40 size=382 ====

undefined8 * FUN_00c7cc40(long param_1)

{
  char cVar1;
  undefined4 uVar2;
  char *pcVar3;
  char cVar4;
  int iVar5;
  long lVar6;
  undefined8 uVar7;
  undefined8 *puVar8;
  int iVar9;
  char cVar10;
  int iVar11;
  char cVar12;
  bool bVar13;
  
  pcVar3 = *(char **)(param_1 + 0x18);
  cVar12 = '\0';
  if (*pcVar3 != '\0') {
    *(char **)(param_1 + 0x18) = pcVar3 + 1;
    cVar12 = *pcVar3;
    if (pcVar3[1] != '\0') {
      *(char **)(param_1 + 0x18) = pcVar3 + 2;
      cVar10 = pcVar3[1];
      if (cVar12 == 'v') {
        if ((byte)(cVar10 - 0x30U) < 10) {
          lVar6 = FUN_00c7aa80();
          iVar9 = *(int *)(param_1 + 0x28);
          if (*(int *)(param_1 + 0x2c) <= iVar9) {
            return (undefined8 *)0x0;
          }
          puVar8 = (undefined8 *)(*(long *)(param_1 + 0x20) + (long)iVar9 * 0x18);
          *(undefined4 *)((long)puVar8 + 4) = 0;
          *(int *)(param_1 + 0x28) = iVar9 + 1;
          if (lVar6 == 0) {
            return (undefined8 *)0x0;
          }
          *puVar8 = 0x32;
          puVar8[2] = lVar6;
          *(int *)(puVar8 + 1) = cVar10 + -0x30;
          return puVar8;
        }
      }
      else if ((cVar12 == 'c') && (cVar10 == 'v')) {
        uVar2 = *(undefined4 *)(param_1 + 0x50);
        *(uint *)(param_1 + 0x50) = (uint)(*(int *)(param_1 + 0x4c) == 0);
        uVar7 = demangle_parse_type();
        if (*(int *)(param_1 + 0x50) == 0) {
          puVar8 = (undefined8 *)FUN_00c7a6a0(param_1,0x33,uVar7,0);
        }
        else {
          puVar8 = (undefined8 *)FUN_00c7a6a0(param_1,0x34,uVar7,0);
        }
        *(undefined4 *)(param_1 + 0x50) = uVar2;
        return puVar8;
      }
      goto LAB_00c7cc6b;
    }
  }
  cVar10 = '\0';
LAB_00c7cc6b:
  iVar11 = 0x43;
  iVar9 = 0;
  do {
    iVar5 = (iVar11 - iVar9) / 2 + iVar9;
    pcVar3 = (&PTR_DAT_01183200)[(long)iVar5 * 3];
    cVar1 = *pcVar3;
    bVar13 = SBORROW1(cVar1,cVar12);
    cVar4 = cVar1 - cVar12;
    if (cVar1 == cVar12) {
      cVar4 = pcVar3[1];
      bVar13 = SBORROW1(cVar4,cVar10);
      cVar4 = cVar4 - cVar10;
      if (cVar4 == '\0') {
        iVar9 = *(int *)(param_1 + 0x28);
        if (*(int *)(param_1 + 0x2c) <= iVar9) {
          return (undefined8 *)0x0;
        }
        puVar8 = (undefined8 *)(*(long *)(param_1 + 0x20) + (long)iVar9 * 0x18);
        *(undefined4 *)((long)puVar8 + 4) = 0;
        *(int *)(param_1 + 0x28) = iVar9 + 1;
        *(undefined4 *)puVar8 = 0x31;
        puVar8[1] = &PTR_DAT_01183200 + (long)iVar5 * 3;
        return puVar8;
      }
    }
    if (bVar13 != cVar4 < '\0') {
      iVar9 = iVar5 + 1;
      iVar5 = iVar11;
    }
    iVar11 = iVar5;
  } while (iVar9 != iVar11);
  return (undefined8 *)0x0;
}


// ==== entry=00c7cdd0 name=FUN_00c7cdd0 size=236 ====

long FUN_00c7cdd0(long param_1)

{
  char cVar1;
  long lVar2;
  long lVar3;
  char *pcVar4;
  long *plVar5;
  long in_FS_OFFSET;
  long local_28;
  long local_20;
  
  plVar5 = &local_28;
  pcVar4 = *(char **)(param_1 + 0x18);
  local_20 = *(long *)(in_FS_OFFSET + 0x28);
  local_28 = 0;
  cVar1 = *pcVar4;
  if ((cVar1 != 'E' && cVar1 != '\0') && (cVar1 != '.')) {
    while (((cVar1 != 'R' && (cVar1 != 'O')) || (pcVar4[1] != 'E'))) {
      lVar3 = demangle_parse_type(param_1);
      if (lVar3 == 0) goto LAB_00c7ce75;
      lVar3 = FUN_00c7a6a0(param_1,0x2e,lVar3,0);
      *plVar5 = lVar3;
      if (lVar3 == 0) goto LAB_00c7ce75;
      pcVar4 = *(char **)(param_1 + 0x18);
      plVar5 = (long *)(lVar3 + 0x10);
      cVar1 = *pcVar4;
      if ((cVar1 == '\0' || cVar1 == 'E') || (cVar1 == '.')) break;
    }
    if (local_28 != 0) {
      lVar3 = local_28;
      if (((*(long *)(local_28 + 0x10) == 0) && (**(int **)(local_28 + 8) == 0x27)) &&
         (lVar2 = *(long *)(*(int **)(local_28 + 8) + 2), *(int *)(lVar2 + 0x1c) == 9)) {
        *(int *)(param_1 + 0x48) = *(int *)(param_1 + 0x48) - *(int *)(lVar2 + 8);
        *(undefined8 *)(local_28 + 8) = 0;
      }
      goto LAB_00c7ce77;
    }
  }
LAB_00c7ce75:
  lVar3 = 0;
LAB_00c7ce77:
  if (local_20 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return lVar3;
}


// ==== entry=00c7ced0 name=FUN_00c7ced0 size=537 ====

long * FUN_00c7ced0(long param_1,long *param_2,uint param_3)

{
  long *plVar1;
  byte bVar2;
  undefined4 uVar3;
  int *piVar4;
  int iVar5;
  long lVar6;
  byte *pbVar7;
  char cVar8;
  ulong uVar9;
  
  pbVar7 = *(byte **)(param_1 + 0x18);
  uVar9 = (ulong)*pbVar7;
  iVar5 = FUN_00c7aec0(pbVar7);
  cVar8 = (char)uVar9;
  plVar1 = param_2;
  do {
    if (iVar5 == 0) {
      if (((param_3 & 1) == 0) && (cVar8 == 'F')) {
        while (plVar1 != param_2) {
          piVar4 = (int *)*param_2;
          iVar5 = *piVar4;
          if (iVar5 == 0x1a) {
            *piVar4 = 0x1d;
          }
          else if (iVar5 == 0x1b) {
            *piVar4 = 0x1e;
          }
          else if (iVar5 == 0x19) {
            *piVar4 = 0x1c;
          }
          param_2 = (long *)(piVar4 + 2);
        }
      }
      return plVar1;
    }
    *(byte **)(param_1 + 0x18) = pbVar7 + 1;
    cVar8 = (char)uVar9;
    if (cVar8 == 'r') {
      *(int *)(param_1 + 0x48) = *(int *)(param_1 + 0x48) + 9;
      lVar6 = 0;
      iVar5 = (-(uint)(param_3 == 0) & 0xfffffffd) + 0x1c;
    }
    else if (cVar8 == 'V') {
      *(int *)(param_1 + 0x48) = *(int *)(param_1 + 0x48) + 9;
      lVar6 = 0;
      iVar5 = (-(uint)(param_3 == 0) & 0xfffffffd) + 0x1d;
    }
    else if (cVar8 == 'K') {
      *(int *)(param_1 + 0x48) = *(int *)(param_1 + 0x48) + 6;
      lVar6 = 0;
      iVar5 = (-(uint)(param_3 == 0) & 0xfffffffd) + 0x1e;
    }
    else {
      if (pbVar7[1] == 0) {
        return (long *)0x0;
      }
      *(byte **)(param_1 + 0x18) = pbVar7 + 2;
      bVar2 = pbVar7[1];
      if (bVar2 == 0x78) {
        *(int *)(param_1 + 0x48) = *(int *)(param_1 + 0x48) + 0x11;
        lVar6 = 0;
        iVar5 = 0x4c;
      }
      else if ((bVar2 & 0xdf) == 0x4f) {
        *(int *)(param_1 + 0x48) = *(int *)(param_1 + 0x48) + 9;
        if (bVar2 == 0x4f) {
          uVar3 = *(undefined4 *)(param_1 + 0x4c);
          *(undefined4 *)(param_1 + 0x4c) = 1;
          lVar6 = demangle_parseType(param_1);
          *(undefined4 *)(param_1 + 0x4c) = uVar3;
          if (lVar6 == 0) {
            return (long *)0x0;
          }
          if (**(char **)(param_1 + 0x18) != 'E') {
            return (long *)0x0;
          }
          *(char **)(param_1 + 0x18) = *(char **)(param_1 + 0x18) + 1;
          iVar5 = 0x4e;
        }
        else {
          lVar6 = 0;
          iVar5 = 0x4e;
        }
      }
      else {
        if (bVar2 != 0x77) {
          return (long *)0x0;
        }
        *(int *)(param_1 + 0x48) = *(int *)(param_1 + 0x48) + 6;
        lVar6 = FUN_00c7cdd0(param_1);
        if (lVar6 == 0) {
          return (long *)0x0;
        }
        if (**(char **)(param_1 + 0x18) != 'E') {
          return (long *)0x0;
        }
        *(char **)(param_1 + 0x18) = *(char **)(param_1 + 0x18) + 1;
        iVar5 = 0x4f;
      }
    }
    lVar6 = FUN_00c7a6a0(param_1,iVar5,0,lVar6);
    *plVar1 = lVar6;
    if (lVar6 == 0) {
      return (long *)0x0;
    }
    pbVar7 = *(byte **)(param_1 + 0x18);
    plVar1 = (long *)(lVar6 + 8);
    uVar9 = (ulong)*pbVar7;
    iVar5 = FUN_00c7aec0(pbVar7);
    cVar8 = (char)uVar9;
  } while( true );
}


// ==== entry=00c7d110 name=FUN_00c7d110 size=110 ====

undefined8 FUN_00c7d110(long param_1,int param_2)

{
  long lVar1;
  long lVar2;
  undefined8 uVar3;
  
  if (**(char **)(param_1 + 0x18) == 'J') {
    *(char **)(param_1 + 0x18) = *(char **)(param_1 + 0x18) + 1;
  }
  else if (param_2 == 0) {
    lVar1 = 0;
    lVar2 = FUN_00c7cdd0(param_1);
    if (lVar2 == 0) {
      return 0;
    }
    goto LAB_00c7d143;
  }
  lVar1 = demangle_parse_type(param_1);
  if ((lVar1 == 0) || (lVar2 = FUN_00c7cdd0(param_1), lVar2 == 0)) {
    return 0;
  }
LAB_00c7d143:
  uVar3 = FUN_00c7a6a0(param_1,0x29,lVar1,lVar2);
  return uVar3;
}


// ==== entry=00c7d190 name=FUN_00c7d190 size=84 ====

undefined8 FUN_00c7d190(long param_1)

{
  char *pcVar1;
  undefined8 uVar2;
  
  pcVar1 = *(char **)(param_1 + 0x18);
  if (*pcVar1 != 'F') {
    return 0;
  }
  *(char **)(param_1 + 0x18) = pcVar1 + 1;
  if (pcVar1[1] == 'Y') {
    *(char **)(param_1 + 0x18) = pcVar1 + 2;
  }
  uVar2 = FUN_00c7d110(param_1,1);
  uVar2 = FUN_00c7a710(param_1,uVar2);
  if (**(char **)(param_1 + 0x18) == 'E') {
    *(char **)(param_1 + 0x18) = *(char **)(param_1 + 0x18) + 1;
    return uVar2;
  }
  return 0;
}


// ==== entry=00c7d200 orig=FUN_00c7d200 size=1086 name=yaml_scan_directive ====

int * yaml_scan_directive(long param_1)

{
  int iVar1;
  char *pcVar2;
  byte bVar3;
  char cVar4;
  int iVar5;
  int *piVar6;
  int *piVar7;
  undefined8 uVar8;
  long lVar9;
  int *piVar10;
  
  pcVar2 = *(char **)(param_1 + 0x18);
  cVar4 = *pcVar2;
  if ((byte)(cVar4 - 0x30U) < 10) {
    piVar7 = (int *)FUN_00c7aa80();
    cVar4 = **(char **)(param_1 + 0x18);
    goto joined_r0x00c7d329;
  }
  if ((byte)(cVar4 + 0x9fU) < 0x1a) {
    if ((cVar4 == 'o') && (pcVar2[1] == 'n')) {
      *(char **)(param_1 + 0x18) = pcVar2 + 2;
    }
    piVar6 = (int *)FUN_00c7cc40(param_1);
    if ((piVar6 != (int *)0x0) && (*piVar6 == 0x31)) {
      pcVar2 = (char *)**(undefined8 **)(piVar6 + 2);
      *(int *)(param_1 + 0x48) =
           *(int *)(param_1 + 0x48) + 7 + *(int *)(*(undefined8 **)(piVar6 + 2) + 2);
      if ((*pcVar2 == 'l') && ((pcVar2[1] == 'i' && (pcVar2[2] == '\0')))) {
        uVar8 = FUN_00c7aa80(param_1);
        piVar6 = (int *)FUN_00c7a6a0(param_1,0x36,piVar6,uVar8);
      }
    }
  }
  else {
    if ((byte)(cVar4 + 0xbdU) < 2) {
      piVar10 = *(int **)(param_1 + 0x40);
      if ((piVar10 == (int *)0x0) || ((*piVar10 != 0 && (*piVar10 != 0x18)))) {
        if (cVar4 == 'D') {
LAB_00c7d4b1:
          switch(pcVar2[1]) {
          case '0':
            iVar5 = 1;
            break;
          case '1':
            iVar5 = 2;
            break;
          case '2':
            iVar5 = 3;
            break;
          default:
            goto switchD_00c7d4d1_caseD_33;
          case '4':
            iVar5 = 4;
            break;
          case '5':
            iVar5 = 5;
          }
          *(char **)(param_1 + 0x18) = pcVar2 + 2;
          iVar1 = *(int *)(param_1 + 0x28);
          if (iVar1 < *(int *)(param_1 + 0x2c)) {
            piVar7 = (int *)(*(long *)(param_1 + 0x20) + (long)iVar1 * 0x18);
            piVar7[1] = 0;
            *(int *)(param_1 + 0x28) = iVar1 + 1;
            if (piVar10 != (int *)0x0) {
              piVar7[0] = 8;
              piVar7[1] = 0;
              piVar7[2] = iVar5;
              *(int **)(piVar7 + 4) = piVar10;
              cVar4 = pcVar2[2];
              goto joined_r0x00c7d329;
            }
          }
          cVar4 = pcVar2[2];
          goto LAB_00c7d604;
        }
      }
      else {
        *(int *)(param_1 + 0x48) = *(int *)(param_1 + 0x48) + piVar10[4];
        cVar4 = *pcVar2;
        if (cVar4 != 'C') {
          if (cVar4 == 'D') goto LAB_00c7d4b1;
LAB_00c7d604:
          piVar7 = (int *)0x0;
          goto joined_r0x00c7d329;
        }
      }
      if (pcVar2[1] == 'I') {
        *(char **)(param_1 + 0x18) = pcVar2 + 1;
        cVar4 = pcVar2[2];
        if (4 < (byte)(cVar4 - 0x31U)) {
          cVar4 = pcVar2[1];
          piVar7 = (int *)0x0;
          goto joined_r0x00c7d329;
        }
        *(char **)(param_1 + 0x18) = pcVar2 + 3;
        iVar5 = *(int *)(&DAT_00d99d70 + (ulong)(byte)(cVar4 - 0x31U) * 4);
        demangle_parse_type(param_1);
        piVar10 = *(int **)(param_1 + 0x40);
      }
      else {
        bVar3 = pcVar2[1] - 0x31;
        if (4 < bVar3) {
switchD_00c7d4d1_caseD_33:
          return (int *)0x0;
        }
        *(char **)(param_1 + 0x18) = pcVar2 + 2;
        iVar5 = *(int *)(&DAT_00d99d70 + (ulong)bVar3 * 4);
      }
      iVar1 = *(int *)(param_1 + 0x28);
      if (iVar1 < *(int *)(param_1 + 0x2c)) {
        piVar6 = (int *)(*(long *)(param_1 + 0x20) + (long)iVar1 * 0x18);
        piVar6[1] = 0;
        *(int *)(param_1 + 0x28) = iVar1 + 1;
        if ((piVar10 != (int *)0x0) && (iVar5 - 1U < 5)) {
          piVar6[0] = 7;
          piVar6[1] = 0;
          piVar6[2] = iVar5;
          *(int **)(piVar6 + 4) = piVar10;
          goto LAB_00c7d243;
        }
      }
LAB_00c7d610:
      cVar4 = **(char **)(param_1 + 0x18);
      piVar7 = (int *)0x0;
      goto joined_r0x00c7d329;
    }
    if (cVar4 == 'L') {
      *(char **)(param_1 + 0x18) = pcVar2 + 1;
      piVar6 = (int *)FUN_00c7aa80();
      if (piVar6 == (int *)0x0) {
        return (int *)0x0;
      }
      iVar5 = FUN_00c7af10(param_1);
      if (iVar5 == 0) {
        return (int *)0x0;
      }
    }
    else {
      if (cVar4 != 'U') {
        return (int *)0x0;
      }
      if (pcVar2[1] == 'l') {
        piVar6 = (int *)0x0;
        *(char **)(param_1 + 0x18) = pcVar2 + 1;
        cVar4 = pcVar2[1];
        piVar7 = piVar6;
        if (cVar4 != 'l') goto joined_r0x00c7d329;
        *(char **)(param_1 + 0x18) = pcVar2 + 2;
        lVar9 = FUN_00c7cdd0();
        if (lVar9 == 0) goto LAB_00c7d243;
        cVar4 = **(char **)(param_1 + 0x18);
        if (cVar4 != 'E') goto joined_r0x00c7d329;
        *(char **)(param_1 + 0x18) = *(char **)(param_1 + 0x18) + 1;
        iVar5 = FUN_00c7a9c0(param_1);
        if (-1 < iVar5) {
          iVar1 = *(int *)(param_1 + 0x28);
          pcVar2 = *(char **)(param_1 + 0x18);
          if (iVar1 < *(int *)(param_1 + 0x2c)) {
            piVar7 = (int *)(*(long *)(param_1 + 0x20) + (long)iVar1 * 0x18);
            piVar7[1] = 0;
            *(int *)(param_1 + 0x28) = iVar1 + 1;
            piVar7[4] = iVar5;
            iVar5 = *(int *)(param_1 + 0x38);
            *piVar7 = 0x45;
            *(long *)(piVar7 + 2) = lVar9;
            if (iVar5 < *(int *)(param_1 + 0x3c)) {
              *(int **)(*(long *)(param_1 + 0x30) + (long)iVar5 * 8) = piVar7;
              *(int *)(param_1 + 0x38) = iVar5 + 1;
              cVar4 = *pcVar2;
              goto joined_r0x00c7d329;
            }
          }
          cVar4 = *pcVar2;
          piVar7 = (int *)0x0;
          goto joined_r0x00c7d329;
        }
        goto LAB_00c7d610;
      }
      if (pcVar2[1] != 't') {
        return (int *)0x0;
      }
      piVar6 = (int *)0x0;
      *(char **)(param_1 + 0x18) = pcVar2 + 1;
      cVar4 = pcVar2[1];
      piVar7 = (int *)0x0;
      if (cVar4 != 't') goto joined_r0x00c7d329;
      *(char **)(param_1 + 0x18) = pcVar2 + 2;
      iVar5 = FUN_00c7a9c0();
      if (-1 < iVar5) {
        iVar1 = *(int *)(param_1 + 0x28);
        if (iVar1 < *(int *)(param_1 + 0x2c)) {
          piVar7 = (int *)(*(long *)(param_1 + 0x20) + (long)iVar1 * 0x18);
          piVar7[1] = 0;
          *(int *)(param_1 + 0x28) = iVar1 + 1;
          pcVar2 = *(char **)(param_1 + 0x18);
          *(long *)(piVar7 + 2) = (long)iVar5;
          iVar5 = *(int *)(param_1 + 0x38);
          *piVar7 = 0x47;
          if (iVar5 < *(int *)(param_1 + 0x3c)) {
            *(int **)(*(long *)(param_1 + 0x30) + (long)iVar5 * 8) = piVar7;
            *(int *)(param_1 + 0x38) = iVar5 + 1;
            cVar4 = *pcVar2;
          }
          else {
            cVar4 = *pcVar2;
            piVar7 = (int *)0x0;
          }
          goto joined_r0x00c7d329;
        }
        goto LAB_00c7d610;
      }
    }
  }
LAB_00c7d243:
  cVar4 = **(char **)(param_1 + 0x18);
  piVar7 = piVar6;
joined_r0x00c7d329:
  if (cVar4 == 'B') {
    piVar7 = (int *)FUN_00c7abe0(param_1,piVar7);
    return piVar7;
  }
  return piVar7;
}


// ==== entry=00c7d680 name=FUN_00c7d680 size=1611 ====

/* WARNING: Type propagation algorithm not settling */

uint * FUN_00c7d680(long param_1,int param_2)

{
  char cVar1;
  int iVar2;
  long lVar3;
  int iVar4;
  uint *puVar5;
  int *piVar6;
  byte bVar7;
  uint *puVar8;
  uint uVar9;
  undefined8 uVar10;
  char *pcVar12;
  char *pcVar13;
  uint uVar14;
  ulong uVar15;
  long lVar11;
  
  pcVar13 = *(char **)(param_1 + 0x18);
  if ((*pcVar13 == 'G') || (*pcVar13 == 'T')) {
    iVar4 = *(int *)(param_1 + 0x48);
    *(int *)(param_1 + 0x48) = iVar4 + 0x14;
    if (*pcVar13 == 'T') {
      *(char **)(param_1 + 0x18) = pcVar13 + 1;
      if (pcVar13[1] == '\0') {
        return (uint *)0x0;
      }
      *(char **)(param_1 + 0x18) = pcVar13 + 2;
      switch(pcVar13[1]) {
      case 'C':
        piVar6 = (int *)demangle_parse_type(param_1);
        iVar4 = FUN_00c7a8c0(param_1 + 0x18);
        if (iVar4 < 0) {
          return (uint *)0x0;
        }
        if (**(char **)(param_1 + 0x18) != '_') {
          return (uint *)0x0;
        }
        *(char **)(param_1 + 0x18) = *(char **)(param_1 + 0x18) + 1;
        puVar5 = (uint *)demangle_parse_type(param_1);
        *(int *)(param_1 + 0x48) = *(int *)(param_1 + 0x48) + 5;
        uVar10 = 0xb;
        break;
      default:
        return (uint *)0x0;
      case 'F':
        puVar5 = (uint *)demangle_parse_type(param_1);
        piVar6 = (int *)0x0;
        uVar10 = 0xe;
        break;
      case 'H':
        puVar5 = (uint *)FUN_00c7bc30(param_1);
        piVar6 = (int *)0x0;
        uVar10 = 0x14;
        break;
      case 'I':
        puVar5 = (uint *)demangle_parse_type(param_1);
        piVar6 = (int *)0x0;
        uVar10 = 0xc;
        break;
      case 'J':
        puVar5 = (uint *)demangle_parse_type(param_1);
        piVar6 = (int *)0x0;
        uVar10 = 0x12;
        break;
      case 'S':
        puVar5 = (uint *)demangle_parse_type(param_1);
        piVar6 = (int *)0x0;
        uVar10 = 0xd;
        break;
      case 'T':
        *(int *)(param_1 + 0x48) = iVar4 + 10;
        puVar5 = (uint *)demangle_parse_type(param_1);
        piVar6 = (int *)0x0;
        uVar10 = 10;
        break;
      case 'V':
        *(int *)(param_1 + 0x48) = iVar4 + 0xf;
        puVar5 = (uint *)demangle_parse_type(param_1);
        piVar6 = (int *)0x0;
        uVar10 = 9;
        break;
      case 'W':
        puVar5 = (uint *)FUN_00c7bc30(param_1);
        piVar6 = (int *)0x0;
        uVar10 = 0x15;
        break;
      case 'c':
        iVar4 = FUN_00c7ae40(param_1,0);
        if (iVar4 == 0) {
          return (uint *)0x0;
        }
        iVar4 = FUN_00c7ae40(param_1,0);
        if (iVar4 == 0) {
          return (uint *)0x0;
        }
        puVar5 = (uint *)FUN_00c7d680(param_1,0);
        piVar6 = (int *)0x0;
        uVar10 = 0x11;
        break;
      case 'h':
        iVar4 = FUN_00c7ae40(param_1,0x68);
        if (iVar4 == 0) {
          return (uint *)0x0;
        }
        puVar5 = (uint *)FUN_00c7d680(param_1,0);
        piVar6 = (int *)0x0;
        uVar10 = 0xf;
        break;
      case 'v':
        iVar4 = FUN_00c7ae40(param_1,0x76);
        if (iVar4 == 0) {
          return (uint *)0x0;
        }
        puVar5 = (uint *)FUN_00c7d680(param_1,0);
        piVar6 = (int *)0x0;
        uVar10 = 0x10;
      }
    }
    else {
      if (*pcVar13 != 'G') {
        return (uint *)0x0;
      }
      *(char **)(param_1 + 0x18) = pcVar13 + 1;
      if (pcVar13[1] == '\0') {
        return (uint *)0x0;
      }
      *(char **)(param_1 + 0x18) = pcVar13 + 2;
      switch(pcVar13[1]) {
      case 'A':
        puVar5 = (uint *)FUN_00c7d680(param_1,0);
        piVar6 = (int *)0x0;
        uVar10 = 0x17;
        break;
      default:
        return (uint *)0x0;
      case 'R':
        puVar5 = (uint *)FUN_00c7bc30(param_1);
        piVar6 = (int *)FUN_00c7a970(param_1);
        uVar10 = 0x16;
        break;
      case 'T':
        if ((pcVar13[2] == '\0') || (*(char **)(param_1 + 0x18) = pcVar13 + 3, pcVar13[2] != 'n')) {
          puVar5 = (uint *)FUN_00c7d680(param_1,0);
          piVar6 = (int *)0x0;
          uVar10 = 0x48;
        }
        else {
          puVar5 = (uint *)FUN_00c7d680(param_1,0);
          piVar6 = (int *)0x0;
          uVar10 = 0x49;
        }
        break;
      case 'V':
        puVar5 = (uint *)FUN_00c7bc30(param_1);
        piVar6 = (int *)0x0;
        uVar10 = 0x13;
        break;
      case 'r':
        iVar4 = FUN_00c7a8c0(param_1 + 0x18);
        if (iVar4 < 2) {
          return (uint *)0x0;
        }
        pcVar13 = *(char **)(param_1 + 0x18);
        if (*pcVar13 == '\0') {
          return (uint *)0x0;
        }
        *(char **)(param_1 + 0x18) = pcVar13 + 1;
        if (*pcVar13 != '_') {
          return (uint *)0x0;
        }
        uVar15 = (ulong)(iVar4 - 1);
        puVar8 = (uint *)0x0;
        pcVar13 = pcVar13 + 1;
        do {
          if (*pcVar13 == '\0') {
            return (uint *)0x0;
          }
          iVar4 = (int)uVar15;
          if (*pcVar13 == '$') {
            cVar1 = pcVar13[1];
            if (cVar1 == 'S') {
              uVar9 = 0x2f;
            }
            else if (cVar1 == '_') {
              uVar9 = 0x2e;
            }
            else {
              if (cVar1 != '$') {
                return (uint *)0x0;
              }
              uVar9 = 0x24;
            }
            iVar2 = *(int *)(param_1 + 0x28);
            pcVar12 = (char *)(*(long *)(param_1 + 0x18) + 2);
            if (*(int *)(param_1 + 0x2c) <= iVar2) {
              *(char **)(param_1 + 0x18) = pcVar12;
              return (uint *)0x0;
            }
            uVar14 = iVar4 - 2;
            puVar5 = (uint *)(*(long *)(param_1 + 0x20) + (long)iVar2 * 0x18);
            puVar5[1] = 0;
            *(int *)(param_1 + 0x28) = iVar2 + 1;
            *puVar5 = 0x40;
            puVar5[2] = uVar9;
            *(char **)(param_1 + 0x18) = pcVar12;
          }
          else {
            lVar3 = 1;
            while (lVar11 = lVar3, uVar9 = (uint)lVar11, (int)uVar9 < iVar4) {
              if ((pcVar13[lVar11] == '$') || (lVar3 = lVar11 + 1, pcVar13[lVar11] == '\0')) break;
            }
            iVar2 = *(int *)(param_1 + 0x28);
            if (*(int *)(param_1 + 0x2c) <= iVar2) {
              *(long *)(param_1 + 0x18) = *(long *)(param_1 + 0x18) + lVar11;
              return (uint *)0x0;
            }
            uVar14 = iVar4 - uVar9;
            puVar5 = (uint *)(*(long *)(param_1 + 0x20) + (long)iVar2 * 0x18);
            puVar5[1] = 0;
            *(int *)(param_1 + 0x28) = iVar2 + 1;
            puVar5[0] = 0;
            puVar5[1] = 0;
            pcVar12 = (char *)(lVar11 + *(long *)(param_1 + 0x18));
            *(char **)(puVar5 + 2) = pcVar13;
            puVar5[4] = uVar9;
            *(char **)(param_1 + 0x18) = pcVar12;
          }
          uVar15 = (ulong)uVar14;
          if ((puVar8 != (uint *)0x0) &&
             (puVar5 = (uint *)FUN_00c7a6a0(param_1,0x3f), puVar5 == (uint *)0x0)) {
            return (uint *)0x0;
          }
          puVar8 = puVar5;
          pcVar13 = pcVar12;
        } while (0 < (int)uVar15);
        piVar6 = (int *)0x0;
        uVar10 = 0x3e;
      }
    }
    goto LAB_00c7d8db;
  }
  puVar5 = (uint *)FUN_00c7bc30();
  if (puVar5 == (uint *)0x0) {
    return (uint *)0x0;
  }
  if ((param_2 != 0) && ((*(byte *)(param_1 + 0x10) & 1) == 0)) {
    uVar9 = *puVar5;
    if (uVar9 - 0x1c < 0x34) {
      uVar15 = 0xd00000000001fU >> ((ulong)(uVar9 - 0x1c) & 0x3f) & 1;
      while (uVar15 != 0) {
        puVar5 = *(uint **)(puVar5 + 2);
        uVar9 = *puVar5;
        if (0x33 < uVar9 - 0x1c) goto LAB_00c7d820;
        uVar15 = 1L << ((byte)(uVar9 - 0x1c) & 0x3f) & 0xd00000000001f;
      }
    }
    else {
LAB_00c7d820:
      if (uVar9 == 2) {
        piVar6 = *(int **)(puVar5 + 4);
        if ((*piVar6 - 0x1cU < 0x34) &&
           ((0xd00000000001fU >> ((ulong)(*piVar6 - 0x1cU) & 0x3f) & 1) != 0)) {
          do {
            piVar6 = *(int **)(piVar6 + 2);
            if (0x33 < *piVar6 - 0x1cU) break;
          } while ((1L << ((byte)(*piVar6 - 0x1cU) & 0x3f) & 0xd00000000001fU) != 0);
          *(int **)(puVar5 + 4) = piVar6;
        }
      }
    }
    return puVar5;
  }
  if (**(char **)(param_1 + 0x18) == '\0') {
    return puVar5;
  }
  puVar8 = puVar5;
  if (**(char **)(param_1 + 0x18) == 'E') {
    return puVar5;
  }
  do {
    uVar9 = *puVar8;
    if (uVar9 < 0x21) {
      if (0x1b < uVar9) goto LAB_00c7d88f;
      if (uVar9 != 2) {
        if (uVar9 == 4) {
          puVar8 = *(uint **)(puVar8 + 2);
          if ((puVar8 == (uint *)0x0) || (0x34 < *puVar8)) goto LAB_00c7d804;
          bVar7 = (byte)*puVar8;
          goto joined_r0x00c7d7cd;
        }
        break;
      }
      puVar8 = *(uint **)(puVar8 + 4);
    }
    else {
      if ((uVar9 != 0x4c) && ((uVar9 < 0x4c || (1 < uVar9 - 0x4e)))) break;
LAB_00c7d88f:
      puVar8 = *(uint **)(puVar8 + 2);
    }
  } while (puVar8 != (uint *)0x0);
LAB_00c7d8a0:
  uVar10 = 0;
LAB_00c7d8a2:
  piVar6 = (int *)FUN_00c7d110(param_1,uVar10);
  if (piVar6 == (int *)0x0) {
    return (uint *)0x0;
  }
  if (((param_2 == 0) && (*puVar5 == 2)) && (*piVar6 == 0x29)) {
    piVar6[2] = 0;
    piVar6[3] = 0;
  }
  uVar10 = 3;
LAB_00c7d8db:
  puVar5 = (uint *)FUN_00c7a6a0(param_1,uVar10,puVar5,piVar6);
  return puVar5;
joined_r0x00c7d7cd:
  uVar15 = 1L << (bVar7 & 0x3f);
  if ((uVar15 & 0x10000000000180) != 0) goto LAB_00c7d8a0;
  if ((((uVar15 & 6) == 0) || (puVar8 = *(uint **)(puVar8 + 4), puVar8 == (uint *)0x0)) ||
     (0x34 < *puVar8)) goto LAB_00c7d804;
  bVar7 = (byte)*puVar8;
  goto joined_r0x00c7d7cd;
LAB_00c7d804:
  uVar10 = 1;
  goto LAB_00c7d8a2;
}


// ==== entry=00c7dd70 orig=FUN_00c7dd70 size=16996 name=demangle_special_name ====

void demangle_special_name(undefined1 *param_1,uint param_2,long *param_3)

{
  long **pplVar1;
  char cVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  long *plVar5;
  long *plVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  int *piVar10;
  long lVar11;
  long *plVar12;
  long lVar13;
  long *plVar14;
  long **pplVar15;
  ulong uVar16;
  long lVar17;
  undefined8 *puVar18;
  undefined8 *puVar19;
  uint *puVar20;
  uint *puVar21;
  undefined1 uVar22;
  undefined1 *puVar23;
  uint *puVar24;
  int *piVar25;
  byte *pbVar26;
  byte *pbVar27;
  undefined8 *puVar28;
  char *pcVar29;
  undefined8 unaff_R13;
  char *pcVar30;
  ulong uVar31;
  undefined *puVar32;
  undefined1 *puVar33;
  char cVar34;
  char *pcVar35;
  int iVar36;
  long in_FS_OFFSET;
  bool bVar37;
  bool bVar38;
  byte bVar39;
  undefined1 auVar40 [12];
  long local_118;
  int local_10c;
  long *local_108;
  long *local_100;
  int local_f8;
  undefined8 local_f0;
  long *local_e8 [2];
  long local_d8;
  long *local_d0 [3];
  long local_b8;
  long *local_b0 [8];
  undefined1 auStack_6b [43];
  long local_40;
  
  bVar39 = 0;
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  if (param_3 == (long *)0x0) goto LAB_00c7df70;
  if (*(int *)(param_1 + 0x130) != 0) goto switchD_00c81be2_default;
  iVar7 = (int)*param_3;
  uVar9 = 0;
  switch(iVar7) {
  case 0:
    lVar17 = (long)(int)param_3[2];
    pcVar30 = (char *)param_3[1];
    if ((param_2 & 4) == 0) {
      if (lVar17 != 0) {
        pcVar29 = pcVar30 + lVar17;
        lVar17 = *(long *)(param_1 + 0x100);
        do {
          cVar34 = *pcVar30;
          if (lVar17 == 0xff) {
            param_1[0xff] = 0;
            (**(code **)(param_1 + 0x110))(param_1,0xff,*(undefined8 *)(param_1 + 0x118));
            *(long *)(param_1 + 0x140) = *(long *)(param_1 + 0x140) + 1;
            lVar11 = 1;
            lVar17 = 0;
          }
          else {
            lVar11 = lVar17 + 1;
          }
          pcVar30 = pcVar30 + 1;
          *(long *)(param_1 + 0x100) = lVar11;
          param_1[lVar17] = cVar34;
          param_1[0x108] = cVar34;
          lVar17 = lVar11;
        } while (pcVar29 != pcVar30);
      }
    }
    else {
      pcVar29 = pcVar30 + lVar17;
      while (pcVar30 < pcVar29) {
        cVar34 = *pcVar30;
        if ((((3 < (long)pcVar29 - (long)pcVar30) && (cVar34 == '_')) && (pcVar30[1] == '_')) &&
           ((pcVar30[2] == 'U' && (pcVar35 = pcVar30 + 3, pcVar35 < pcVar29)))) {
          uVar16 = 0;
          do {
            cVar2 = *pcVar35;
            iVar7 = (int)cVar2;
            if ((byte)(cVar2 - 0x30U) < 10) {
              iVar7 = iVar7 + -0x30;
            }
            else if ((byte)(cVar2 + 0xbfU) < 6) {
              iVar7 = iVar7 + -0x37;
            }
            else {
              if (5 < (byte)(cVar2 + 0x9fU)) {
                if (((pcVar35 < pcVar29) && (uVar16 < 0x100)) && (cVar2 == '_')) {
                  if (*(long *)(param_1 + 0x100) == 0xff) {
                    param_1[0xff] = 0;
                    (**(code **)(param_1 + 0x110))(param_1,0xff,*(undefined8 *)(param_1 + 0x118));
                    *(long *)(param_1 + 0x140) = *(long *)(param_1 + 0x140) + 1;
                    *(undefined8 *)(param_1 + 0x100) = 0;
                  }
                  lVar17 = *(long *)(param_1 + 0x100);
                  *(long *)(param_1 + 0x100) = lVar17 + 1;
                  param_1[lVar17] = (char)uVar16;
                  param_1[0x108] = (char)uVar16;
                  goto LAB_00c80aa0;
                }
                break;
              }
              iVar7 = iVar7 + -0x57;
            }
            pcVar35 = pcVar35 + 1;
            uVar16 = uVar16 * 0x10 + (long)iVar7;
          } while (pcVar29 != pcVar35);
        }
        lVar11 = *(long *)(param_1 + 0x100);
        lVar17 = lVar11 + 1;
        if (lVar11 == 0xff) {
          param_1[0xff] = 0;
          (**(code **)(param_1 + 0x110))(param_1,0xff,*(undefined8 *)(param_1 + 0x118));
          *(long *)(param_1 + 0x140) = *(long *)(param_1 + 0x140) + 1;
          lVar17 = 1;
          lVar11 = 0;
        }
        *(long *)(param_1 + 0x100) = lVar17;
        param_1[lVar11] = cVar34;
        param_1[0x108] = cVar34;
        pcVar35 = pcVar30;
LAB_00c80aa0:
        pcVar30 = pcVar35 + 1;
      }
    }
    break;
  case 1:
  case 2:
    demangle_recurse_guard(param_1,param_2,param_3[1]);
    lVar17 = *(long *)(param_1 + 0x100);
    if ((param_2 & 4) == 0) {
      puVar23 = &DAT_00d99dd1;
      uVar22 = 0x3a;
      while( true ) {
        if (lVar17 == 0xff) {
          param_1[0xff] = 0;
          (**(code **)(param_1 + 0x110))(param_1,0xff,*(undefined8 *)(param_1 + 0x118));
          *(long *)(param_1 + 0x140) = *(long *)(param_1 + 0x140) + 1;
          lVar11 = 1;
          lVar17 = 0;
        }
        else {
          lVar11 = lVar17 + 1;
        }
        puVar23 = puVar23 + 1;
        *(long *)(param_1 + 0x100) = lVar11;
        param_1[lVar17] = uVar22;
        param_1[0x108] = uVar22;
        if (puVar23 == &DAT_00d99dd3) break;
        uVar22 = *puVar23;
        lVar17 = lVar11;
      }
    }
    else {
      lVar11 = lVar17 + 1;
      if (lVar17 == 0xff) {
        param_1[0xff] = 0;
        (**(code **)(param_1 + 0x110))(param_1,0xff,*(undefined8 *)(param_1 + 0x118));
        *(long *)(param_1 + 0x140) = *(long *)(param_1 + 0x140) + 1;
        lVar11 = 1;
        lVar17 = 0;
      }
      *(long *)(param_1 + 0x100) = lVar11;
      param_1[lVar17] = 0x2e;
      param_1[0x108] = 0x2e;
    }
    piVar10 = (int *)param_3[2];
    if (*piVar10 == 0x46) {
      pcVar30 = "{default arg#";
      cVar34 = '{';
      lVar17 = *(long *)(param_1 + 0x100);
      while( true ) {
        pcVar30 = pcVar30 + 1;
        if (lVar17 == 0xff) {
          param_1[0xff] = 0;
          (**(code **)(param_1 + 0x110))(param_1,0xff,*(undefined8 *)(param_1 + 0x118));
          *(long *)(param_1 + 0x140) = *(long *)(param_1 + 0x140) + 1;
          lVar11 = 1;
          lVar17 = 0;
        }
        else {
          lVar11 = lVar17 + 1;
        }
        *(long *)(param_1 + 0x100) = lVar11;
        param_1[lVar17] = cVar34;
        param_1[0x108] = cVar34;
        if (pcVar30 == "") break;
        cVar34 = *pcVar30;
        lVar17 = lVar11;
      }
      puVar24 = (uint *)(auStack_6b + 3);
      sprintf((char *)puVar24,"%d",(ulong)(piVar10[4] + 1));
      puVar21 = puVar24;
      do {
        puVar20 = puVar21;
        uVar8 = *puVar20 + 0xfefefeff & ~*puVar20;
        uVar9 = uVar8 & 0x80808080;
        puVar21 = puVar20 + 1;
      } while (uVar9 == 0);
      if ((uVar8 & 0x8080) == 0) {
        puVar21 = (uint *)((long)puVar20 + 6);
        uVar9 = uVar9 >> 0x10;
      }
      lVar17 = *(long *)(param_1 + 0x100);
      pcVar30 = (char *)((long)puVar21 +
                        ((-3 - (ulong)CARRY1((byte)uVar9,(byte)uVar9)) - (long)puVar24));
      if (pcVar30 != (char *)0x0) {
        puVar21 = (uint *)(pcVar30 + (long)puVar24);
        lVar11 = lVar17;
        do {
          uVar9 = *puVar24;
          if (lVar11 == 0xff) {
            param_1[0xff] = 0;
            (**(code **)(param_1 + 0x110))(param_1,0xff,*(undefined8 *)(param_1 + 0x118));
            *(long *)(param_1 + 0x140) = *(long *)(param_1 + 0x140) + 1;
            lVar17 = 1;
            lVar11 = 0;
          }
          else {
            lVar17 = lVar11 + 1;
          }
          puVar24 = (uint *)((long)puVar24 + 1);
          *(long *)(param_1 + 0x100) = lVar17;
          param_1[lVar11] = (char)uVar9;
          param_1[0x108] = (char)uVar9;
          lVar11 = lVar17;
        } while (puVar21 != puVar24);
      }
      puVar32 = &DAT_00d99dd0;
      uVar22 = 0x7d;
      while( true ) {
        if (lVar17 == 0xff) {
          param_1[0xff] = 0;
          (**(code **)(param_1 + 0x110))(param_1,0xff,*(undefined8 *)(param_1 + 0x118));
          *(long *)(param_1 + 0x140) = *(long *)(param_1 + 0x140) + 1;
          lVar11 = 1;
          lVar17 = 0;
        }
        else {
          lVar11 = lVar17 + 1;
        }
        puVar32 = puVar32 + 1;
        *(long *)(param_1 + 0x100) = lVar11;
        param_1[lVar17] = uVar22;
        param_1[0x108] = uVar22;
        if (puVar32 == &DAT_00d99dd3) break;
        uVar22 = *puVar32;
        lVar17 = lVar11;
      }
      piVar10 = *(int **)(piVar10 + 2);
    }
    demangle_recurse_guard(param_1,param_2,piVar10);
    break;
  case 3:
    plVar14 = (long *)param_3[1];
    uVar3 = *(undefined8 *)(param_1 + 0x128);
    *(undefined8 *)(param_1 + 0x128) = 0;
    if (plVar14 == (long *)0x0) {
LAB_00c80c5d:
      *(undefined4 *)(param_1 + 0x130) = 1;
      break;
    }
    iVar7 = (int)*plVar14;
    plVar12 = *(long **)(param_1 + 0x120);
    local_e8[0] = (long *)0x0;
    *(long ***)(param_1 + 0x128) = local_e8;
    local_e8[1] = plVar14;
    local_d8._0_4_ = 0;
    local_d0[0] = plVar12;
    if (iVar7 - 0x1cU < 0x34) {
      if ((0xd00000000001fU >> ((ulong)(iVar7 - 0x1cU) & 0x3f) & 1) == 0) {
        uVar9 = 1;
      }
      else {
        pplVar15 = local_d0 + 1;
        uVar9 = 1;
        do {
          plVar14 = (long *)plVar14[1];
          if ((plVar14 == (long *)0x0) || (uVar9 == 4)) goto LAB_00c80c5d;
          plVar5 = *(long **)(param_1 + 0x128);
          pplVar15[1] = plVar14;
          uVar9 = uVar9 + 1;
          *(long ***)(param_1 + 0x128) = pplVar15;
          *pplVar15 = plVar5;
          iVar7 = (int)*plVar14;
          *(undefined4 *)(pplVar15 + 2) = 0;
          pplVar15[3] = plVar12;
          if (0x33 < iVar7 - 0x1cU) goto LAB_00c80ba2;
          pplVar15 = pplVar15 + 4;
        } while ((1L << ((byte)(iVar7 - 0x1cU) & 0x3f) & 0xd00000000001fU) != 0);
      }
    }
    else {
      uVar9 = 1;
LAB_00c80ba2:
      if (iVar7 == 2) {
        plVar14 = (long *)plVar14[2];
        iVar7 = (int)*plVar14;
        if (iVar7 == 0x46) {
          plVar14 = (long *)plVar14[1];
          if (plVar14 == (long *)0x0) goto LAB_00c80c5d;
          iVar7 = (int)*plVar14;
        }
        if (iVar7 - 0x1cU < 0x34) {
          if ((0xd00000000001fU >> ((ulong)(iVar7 - 0x1cU) & 0x3f) & 1) != 0) {
            if (uVar9 != 4) {
              pplVar15 = local_e8 + (ulong)uVar9 * 4;
              do {
                uVar16 = (ulong)(uVar9 - 1);
                *(long ***)(param_1 + 0x128) = pplVar15;
                uVar9 = uVar9 + 1;
                plVar5 = local_e8[uVar16 * 4 + 1];
                *pplVar15 = local_e8[uVar16 * 4];
                pplVar15[1] = plVar5;
                plVar5 = (long *)(&local_d8)[uVar16 * 4];
                plVar6 = local_d0[uVar16 * 4];
                *pplVar15 = (long *)(local_e8 + uVar16 * 4);
                pplVar15[2] = plVar5;
                pplVar15[3] = plVar6;
                local_e8[uVar16 * 4 + 1] = plVar14;
                plVar14 = (long *)plVar14[1];
                *(undefined4 *)(&local_d8 + uVar16 * 4) = 0;
                local_d0[uVar16 * 4] = plVar12;
                iVar7 = (int)*plVar14;
                if (0x33 < iVar7 - 0x1cU) goto LAB_00c812d4;
                if ((1L << ((byte)(iVar7 - 0x1cU) & 0x3f) & 0xd00000000001fU) == 0)
                goto LAB_00c7f796;
                pplVar15 = pplVar15 + 4;
              } while (uVar9 != 4);
            }
            goto LAB_00c80c5d;
          }
          goto LAB_00c7f796;
        }
      }
LAB_00c812d4:
      if (iVar7 == 4) {
        *(long ***)(param_1 + 0x120) = &local_108;
        local_108 = plVar12;
        local_100 = plVar14;
      }
    }
LAB_00c7f796:
    demangle_recurse_guard(param_1,param_2,param_3[2]);
    if ((int)*plVar14 == 4) {
      *(long **)(param_1 + 0x120) = local_108;
    }
    pplVar15 = local_e8 + (ulong)uVar9 * 4;
    do {
      if (*(int *)(pplVar15 + -2) == 0) {
        lVar11 = *(long *)(param_1 + 0x100);
        lVar17 = lVar11 + 1;
        if (lVar11 == 0xff) {
          param_1[0xff] = 0;
          (**(code **)(param_1 + 0x110))(param_1,0xff,*(undefined8 *)(param_1 + 0x118));
          *(long *)(param_1 + 0x140) = *(long *)(param_1 + 0x140) + 1;
          lVar17 = 1;
          lVar11 = 0;
        }
        *(long *)(param_1 + 0x100) = lVar17;
        plVar14 = pplVar15[-3];
        param_1[lVar11] = 0x20;
        param_1[0x108] = 0x20;
        FUN_00c82200(param_1,param_2,plVar14);
      }
      pplVar15 = pplVar15 + -4;
    } while (local_e8 != pplVar15);
    *(undefined8 *)(param_1 + 0x128) = uVar3;
    break;
  case 4:
    uVar3 = *(undefined8 *)(param_1 + 0x170);
    piVar10 = (int *)param_3[1];
    *(long **)(param_1 + 0x170) = param_3;
    uVar4 = *(undefined8 *)(param_1 + 0x128);
    *(undefined8 *)(param_1 + 0x128) = 0;
    if ((((param_2 & 4) == 0) || (*piVar10 != 0)) || (piVar10[4] != 6)) {
LAB_00c7f622:
      demangle_recurse_guard(param_1,param_2);
      if (param_1[0x108] == '<') {
        lVar17 = *(long *)(param_1 + 0x100);
        if (lVar17 != 0xff) {
          lVar11 = lVar17 + 1;
          *(long *)(param_1 + 0x100) = lVar11;
          param_1[lVar17] = 0x20;
          param_1[0x108] = 0x20;
          goto LAB_00c7f641;
        }
        param_1[0xff] = 0;
        (**(code **)(param_1 + 0x110))(param_1,0xff,*(undefined8 *)(param_1 + 0x118));
        *param_1 = 0x20;
        lVar11 = 1;
        *(long *)(param_1 + 0x140) = *(long *)(param_1 + 0x140) + 1;
LAB_00c7f64d:
        lVar17 = lVar11 + 1;
      }
      else {
        lVar11 = *(long *)(param_1 + 0x100);
LAB_00c7f641:
        if (lVar11 != 0xff) goto LAB_00c7f64d;
        param_1[0xff] = 0;
        (**(code **)(param_1 + 0x110))(param_1,0xff,*(undefined8 *)(param_1 + 0x118));
        *(long *)(param_1 + 0x140) = *(long *)(param_1 + 0x140) + 1;
        lVar17 = 1;
        lVar11 = 0;
      }
      *(long *)(param_1 + 0x100) = lVar17;
      param_1[lVar11] = 0x3c;
      param_1[0x108] = 0x3c;
      demangle_recurse_guard(param_1,param_2,param_3[2]);
      if (param_1[0x108] == '>') {
        lVar17 = *(long *)(param_1 + 0x100);
        if (lVar17 != 0xff) {
          lVar11 = lVar17 + 1;
          *(long *)(param_1 + 0x100) = lVar11;
          param_1[lVar17] = 0x20;
          param_1[0x108] = 0x20;
          goto LAB_00c7f686;
        }
        param_1[0xff] = 0;
        (**(code **)(param_1 + 0x110))(param_1,0xff,*(undefined8 *)(param_1 + 0x118));
        *param_1 = 0x20;
        lVar11 = 1;
        *(long *)(param_1 + 0x140) = *(long *)(param_1 + 0x140) + 1;
LAB_00c7f692:
        lVar17 = lVar11 + 1;
      }
      else {
        lVar11 = *(long *)(param_1 + 0x100);
LAB_00c7f686:
        if (lVar11 != 0xff) goto LAB_00c7f692;
        param_1[0xff] = 0;
        (**(code **)(param_1 + 0x110))(param_1,0xff,*(undefined8 *)(param_1 + 0x118));
        *(long *)(param_1 + 0x140) = *(long *)(param_1 + 0x140) + 1;
        lVar17 = 1;
        lVar11 = 0;
      }
      *(long *)(param_1 + 0x100) = lVar17;
      param_1[lVar11] = 0x3e;
      param_1[0x108] = 0x3e;
    }
    else {
      lVar17 = 6;
      bVar37 = false;
      bVar38 = true;
      pbVar26 = *(byte **)(piVar10 + 2);
      pbVar27 = (byte *)"JArray";
      do {
        if (lVar17 == 0) break;
        lVar17 = lVar17 + -1;
        bVar37 = *pbVar26 < *pbVar27;
        bVar38 = *pbVar26 == *pbVar27;
        pbVar26 = pbVar26 + 1;
        pbVar27 = pbVar27 + 1;
      } while (bVar38);
      if ((!bVar37 && !bVar38) != bVar37) goto LAB_00c7f622;
      demangle_recurse_guard(param_1,param_2,param_3[2]);
      FUN_00c7a810(param_1,&DAT_00d9a12e,2);
    }
    *(undefined8 *)(param_1 + 0x128) = uVar4;
    *(undefined8 *)(param_1 + 0x170) = uVar3;
    break;
  case 5:
    if (*(int *)(param_1 + 0x138) != 0) {
      puVar32 = &DAT_00d99ddb;
      uVar22 = 0x61;
      lVar17 = *(long *)(param_1 + 0x100);
      while( true ) {
        if (lVar17 == 0xff) {
          param_1[0xff] = 0;
          (**(code **)(param_1 + 0x110))(param_1,0xff,*(undefined8 *)(param_1 + 0x118));
          *(long *)(param_1 + 0x140) = *(long *)(param_1 + 0x140) + 1;
          lVar11 = 1;
          lVar17 = 0;
        }
        else {
          lVar11 = lVar17 + 1;
        }
        puVar32 = puVar32 + 1;
        *(long *)(param_1 + 0x100) = lVar11;
        param_1[lVar17] = uVar22;
        param_1[0x108] = uVar22;
        if (puVar32 == &DAT_00d99de0) break;
        uVar22 = *puVar32;
        lVar17 = lVar11;
      }
      puVar24 = (uint *)(auStack_6b + 3);
      sprintf((char *)puVar24,"%d",(ulong)((int)param_3[1] + 1));
      puVar21 = puVar24;
      do {
        puVar20 = puVar21;
        uVar8 = *puVar20 + 0xfefefeff & ~*puVar20;
        uVar9 = uVar8 & 0x80808080;
        puVar21 = puVar20 + 1;
      } while (uVar9 == 0);
      if ((uVar8 & 0x8080) == 0) {
        puVar21 = (uint *)((long)puVar20 + 6);
        uVar9 = uVar9 >> 0x10;
      }
      pcVar30 = (char *)((long)puVar21 +
                        ((-3 - (ulong)CARRY1((byte)uVar9,(byte)uVar9)) - (long)puVar24));
      if (pcVar30 != (char *)0x0) {
        puVar21 = (uint *)(pcVar30 + (long)puVar24);
        lVar17 = *(long *)(param_1 + 0x100);
        do {
          uVar9 = *puVar24;
          if (lVar17 == 0xff) {
            param_1[0xff] = 0;
            (**(code **)(param_1 + 0x110))(param_1,0xff,*(undefined8 *)(param_1 + 0x118));
            *(long *)(param_1 + 0x140) = *(long *)(param_1 + 0x140) + 1;
            lVar11 = 1;
            lVar17 = 0;
          }
          else {
            lVar11 = lVar17 + 1;
          }
          puVar24 = (uint *)((long)puVar24 + 1);
          *(long *)(param_1 + 0x100) = lVar11;
          param_1[lVar17] = (char)uVar9;
          param_1[0x108] = (char)uVar9;
          lVar17 = lVar11;
        } while (puVar21 != puVar24);
      }
      break;
    }
    piVar10 = (int *)FUN_00c7afc0(param_1,param_3 + 1);
    if ((piVar10 != (int *)0x0) &&
       (((*piVar10 != 0x2f || (*(int *)(param_1 + 0x13c) < 0)) ||
        (piVar10 = (int *)FUN_00c7af90(piVar10), piVar10 != (int *)0x0)))) {
      puVar28 = *(undefined8 **)(param_1 + 0x120);
      *(undefined8 *)(param_1 + 0x120) = *puVar28;
      demangle_recurse_guard(param_1,param_2,piVar10);
      *(undefined8 **)(param_1 + 0x120) = puVar28;
      break;
    }
    goto LAB_00c7df70;
  case 6:
    uVar16 = param_3[1];
    if (uVar16 == 0) {
      puVar32 = &DAT_00ceed2e;
      uVar22 = 0x74;
      lVar17 = *(long *)(param_1 + 0x100);
      while( true ) {
        if (lVar17 == 0xff) {
          param_1[0xff] = 0;
          (**(code **)(param_1 + 0x110))(param_1,0xff,*(undefined8 *)(param_1 + 0x118));
          *(long *)(param_1 + 0x140) = *(long *)(param_1 + 0x140) + 1;
          lVar11 = 1;
          lVar17 = 0;
        }
        else {
          lVar11 = lVar17 + 1;
        }
        puVar32 = puVar32 + 1;
        *(long *)(param_1 + 0x100) = lVar11;
        param_1[lVar17] = uVar22;
        param_1[0x108] = uVar22;
        if (puVar32 == &DAT_00ceed32) break;
        uVar22 = *puVar32;
        lVar17 = lVar11;
      }
    }
    else {
      puVar32 = &DAT_00d99f43;
      uVar22 = 0x7b;
      lVar17 = *(long *)(param_1 + 0x100);
      while( true ) {
        if (lVar17 == 0xff) {
          param_1[0xff] = 0;
          (**(code **)(param_1 + 0x110))(param_1,0xff,*(undefined8 *)(param_1 + 0x118));
          *(long *)(param_1 + 0x140) = *(long *)(param_1 + 0x140) + 1;
          lVar11 = 1;
          lVar17 = 0;
        }
        else {
          lVar11 = lVar17 + 1;
        }
        puVar32 = puVar32 + 1;
        *(long *)(param_1 + 0x100) = lVar11;
        param_1[lVar17] = uVar22;
        param_1[0x108] = uVar22;
        if (puVar32 == &DAT_00d99f49) break;
        uVar22 = *puVar32;
        lVar17 = lVar11;
      }
      puVar24 = (uint *)(auStack_6b + 3);
      sprintf((char *)puVar24,"%d",uVar16 & 0xffffffff);
      puVar21 = puVar24;
      do {
        puVar20 = puVar21;
        uVar8 = *puVar20 + 0xfefefeff & ~*puVar20;
        uVar9 = uVar8 & 0x80808080;
        puVar21 = puVar20 + 1;
      } while (uVar9 == 0);
      if ((uVar8 & 0x8080) == 0) {
        puVar21 = (uint *)((long)puVar20 + 6);
        uVar9 = uVar9 >> 0x10;
      }
      lVar17 = *(long *)(param_1 + 0x100);
      pcVar30 = (char *)((long)puVar21 +
                        ((-3 - (ulong)CARRY1((byte)uVar9,(byte)uVar9)) - (long)puVar24));
      if (pcVar30 != (char *)0x0) {
        puVar21 = (uint *)((long)puVar24 + (long)pcVar30);
        lVar11 = lVar17;
        do {
          uVar9 = *puVar24;
          if (lVar11 == 0xff) {
            param_1[0xff] = 0;
            (**(code **)(param_1 + 0x110))(param_1,0xff,*(undefined8 *)(param_1 + 0x118));
            *(long *)(param_1 + 0x140) = *(long *)(param_1 + 0x140) + 1;
            lVar17 = 1;
            lVar11 = 0;
          }
          else {
            lVar17 = lVar11 + 1;
          }
          puVar24 = (uint *)((long)puVar24 + 1);
          *(long *)(param_1 + 0x100) = lVar17;
          param_1[lVar11] = (char)uVar9;
          param_1[0x108] = (char)uVar9;
          lVar11 = lVar17;
        } while (puVar21 != puVar24);
      }
      lVar11 = lVar17 + 1;
      if (lVar17 == 0xff) {
        param_1[0xff] = 0;
        (**(code **)(param_1 + 0x110))(param_1,0xff,*(undefined8 *)(param_1 + 0x118));
        *(long *)(param_1 + 0x140) = *(long *)(param_1 + 0x140) + 1;
        lVar11 = 1;
        lVar17 = 0;
      }
      *(long *)(param_1 + 0x100) = lVar11;
      param_1[lVar17] = 0x7d;
      param_1[0x108] = 0x7d;
    }
    break;
  case 7:
    demangle_recurse_guard(param_1,param_2,param_3[2]);
    break;
  case 8:
    if (*(long *)(param_1 + 0x100) == 0xff) {
      param_1[0xff] = 0;
      (**(code **)(param_1 + 0x110))(param_1,0xff,*(undefined8 *)(param_1 + 0x118));
      *(long *)(param_1 + 0x140) = *(long *)(param_1 + 0x140) + 1;
      *(undefined8 *)(param_1 + 0x100) = 0;
    }
    lVar17 = *(long *)(param_1 + 0x100);
    *(long *)(param_1 + 0x100) = lVar17 + 1;
    param_1[lVar17] = 0x7e;
    param_1[0x108] = 0x7e;
    demangle_recurse_guard(param_1,param_2,param_3[2]);
    break;
  case 9:
    pcVar30 = "table for ";
    cVar34 = 'v';
    lVar17 = *(long *)(param_1 + 0x100);
    while( true ) {
      if (lVar17 == 0xff) {
        param_1[0xff] = 0;
        (**(code **)(param_1 + 0x110))(param_1,0xff,*(undefined8 *)(param_1 + 0x118));
        *(long *)(param_1 + 0x140) = *(long *)(param_1 + 0x140) + 1;
        lVar11 = 1;
        lVar17 = 0;
      }
      else {
        lVar11 = lVar17 + 1;
      }
      *(long *)(param_1 + 0x100) = lVar11;
      param_1[lVar17] = cVar34;
      param_1[0x108] = cVar34;
      if (pcVar30 == "") break;
      cVar34 = *pcVar30;
      pcVar30 = pcVar30 + 1;
      lVar17 = lVar11;
    }
    demangle_recurse_guard(param_1,param_2,param_3[1]);
    break;
  case 10:
    pcVar30 = "VTT for ";
    cVar34 = 'V';
    lVar17 = *(long *)(param_1 + 0x100);
    while( true ) {
      if (lVar17 == 0xff) {
        param_1[0xff] = 0;
        (**(code **)(param_1 + 0x110))(param_1,0xff,*(undefined8 *)(param_1 + 0x118));
        *(long *)(param_1 + 0x140) = *(long *)(param_1 + 0x140) + 1;
        lVar11 = 1;
        lVar17 = 0;
      }
      else {
        lVar11 = lVar17 + 1;
      }
      pcVar30 = pcVar30 + 1;
      *(long *)(param_1 + 0x100) = lVar11;
      param_1[lVar17] = cVar34;
      param_1[0x108] = cVar34;
      if (pcVar30 == "") break;
      cVar34 = *pcVar30;
      lVar17 = lVar11;
    }
    demangle_recurse_guard(param_1,param_2,param_3[1]);
    break;
  case 0xb:
    pcVar30 = "construction vtable for ";
    cVar34 = 'c';
    lVar17 = *(long *)(param_1 + 0x100);
    while( true ) {
      pcVar30 = pcVar30 + 1;
      if (lVar17 == 0xff) {
        param_1[0xff] = 0;
        (**(code **)(param_1 + 0x110))(param_1,0xff,*(undefined8 *)(param_1 + 0x118));
        *(long *)(param_1 + 0x140) = *(long *)(param_1 + 0x140) + 1;
        lVar11 = 1;
        lVar17 = 0;
      }
      else {
        lVar11 = lVar17 + 1;
      }
      *(long *)(param_1 + 0x100) = lVar11;
      param_1[lVar17] = cVar34;
      param_1[0x108] = cVar34;
      if (pcVar30 == "") break;
      cVar34 = *pcVar30;
      lVar17 = lVar11;
    }
    uVar22 = 0x2d;
    puVar32 = &DAT_00d99e03;
    demangle_recurse_guard(param_1,param_2,param_3[1]);
    lVar17 = *(long *)(param_1 + 0x100);
    while( true ) {
      if (lVar17 == 0xff) {
        param_1[0xff] = 0;
        (**(code **)(param_1 + 0x110))(param_1,0xff,*(undefined8 *)(param_1 + 0x118));
        *(long *)(param_1 + 0x140) = *(long *)(param_1 + 0x140) + 1;
        lVar11 = 1;
        lVar17 = 0;
      }
      else {
        lVar11 = lVar17 + 1;
      }
      puVar32 = puVar32 + 1;
      *(long *)(param_1 + 0x100) = lVar11;
      param_1[lVar17] = uVar22;
      param_1[0x108] = uVar22;
      if (puVar32 == &DAT_00d99e07) break;
      uVar22 = *puVar32;
      lVar17 = lVar11;
    }
    demangle_recurse_guard(param_1,param_2,param_3[2]);
    break;
  case 0xc:
    pcVar30 = "typeinfo for ";
    cVar34 = 't';
    lVar17 = *(long *)(param_1 + 0x100);
    while( true ) {
      pcVar30 = pcVar30 + 1;
      if (lVar17 == 0xff) {
        param_1[0xff] = 0;
        (**(code **)(param_1 + 0x110))(param_1,0xff,*(undefined8 *)(param_1 + 0x118));
        *(long *)(param_1 + 0x140) = *(long *)(param_1 + 0x140) + 1;
        lVar11 = 1;
        lVar17 = 0;
      }
      else {
        lVar11 = lVar17 + 1;
      }
      *(long *)(param_1 + 0x100) = lVar11;
      param_1[lVar17] = cVar34;
      param_1[0x108] = cVar34;
      if (pcVar30 == "") break;
      cVar34 = *pcVar30;
      lVar17 = lVar11;
    }
    demangle_recurse_guard(param_1,param_2,param_3[1]);
    break;
  case 0xd:
    pcVar30 = "typeinfo name for ";
    cVar34 = 't';
    lVar17 = *(long *)(param_1 + 0x100);
    while( true ) {
      pcVar30 = pcVar30 + 1;
      if (lVar17 == 0xff) {
        param_1[0xff] = 0;
        (**(code **)(param_1 + 0x110))(param_1,0xff,*(undefined8 *)(param_1 + 0x118));
        *(long *)(param_1 + 0x140) = *(long *)(param_1 + 0x140) + 1;
        lVar11 = 1;
        lVar17 = 0;
      }
      else {
        lVar11 = lVar17 + 1;
      }
      *(long *)(param_1 + 0x100) = lVar11;
      param_1[lVar17] = cVar34;
      param_1[0x108] = cVar34;
      if (pcVar30 == "") break;
      cVar34 = *pcVar30;
      lVar17 = lVar11;
    }
    demangle_recurse_guard(param_1,param_2,param_3[1]);
    break;
  case 0xe:
    pcVar30 = "typeinfo fn for ";
    cVar34 = 't';
    lVar17 = *(long *)(param_1 + 0x100);
    while( true ) {
      pcVar30 = pcVar30 + 1;
      if (lVar17 == 0xff) {
        param_1[0xff] = 0;
        (**(code **)(param_1 + 0x110))(param_1,0xff,*(undefined8 *)(param_1 + 0x118));
        *(long *)(param_1 + 0x140) = *(long *)(param_1 + 0x140) + 1;
        lVar11 = 1;
        lVar17 = 0;
      }
      else {
        lVar11 = lVar17 + 1;
      }
      *(long *)(param_1 + 0x100) = lVar11;
      param_1[lVar17] = cVar34;
      param_1[0x108] = cVar34;
      if (pcVar30 == "") break;
      cVar34 = *pcVar30;
      lVar17 = lVar11;
    }
    demangle_recurse_guard(param_1,param_2,param_3[1]);
    break;
  case 0xf:
    pcVar30 = "non-virtual thunk to ";
    cVar34 = 'n';
    lVar17 = *(long *)(param_1 + 0x100);
    while( true ) {
      pcVar30 = pcVar30 + 1;
      if (lVar17 == 0xff) {
        param_1[0xff] = 0;
        (**(code **)(param_1 + 0x110))(param_1,0xff,*(undefined8 *)(param_1 + 0x118));
        *(long *)(param_1 + 0x140) = *(long *)(param_1 + 0x140) + 1;
        lVar11 = 1;
        lVar17 = 0;
      }
      else {
        lVar11 = lVar17 + 1;
      }
      *(long *)(param_1 + 0x100) = lVar11;
      param_1[lVar17] = cVar34;
      param_1[0x108] = cVar34;
      if (pcVar30 == "") break;
      cVar34 = *pcVar30;
      lVar17 = lVar11;
    }
    demangle_recurse_guard(param_1,param_2,param_3[1]);
    break;
  case 0x10:
    pcVar30 = "irtual thunk to ";
    cVar34 = 'v';
    lVar17 = *(long *)(param_1 + 0x100);
    while( true ) {
      if (lVar17 == 0xff) {
        param_1[0xff] = 0;
        (**(code **)(param_1 + 0x110))(param_1,0xff,*(undefined8 *)(param_1 + 0x118));
        *(long *)(param_1 + 0x140) = *(long *)(param_1 + 0x140) + 1;
        lVar11 = 1;
        lVar17 = 0;
      }
      else {
        lVar11 = lVar17 + 1;
      }
      *(long *)(param_1 + 0x100) = lVar11;
      param_1[lVar17] = cVar34;
      param_1[0x108] = cVar34;
      if (pcVar30 == "") break;
      cVar34 = *pcVar30;
      pcVar30 = pcVar30 + 1;
      lVar17 = lVar11;
    }
    demangle_recurse_guard(param_1,param_2,param_3[1]);
    break;
  case 0x11:
    pcVar30 = "covariant return thunk to ";
    cVar34 = 'c';
    lVar17 = *(long *)(param_1 + 0x100);
    while( true ) {
      pcVar30 = pcVar30 + 1;
      if (lVar17 == 0xff) {
        param_1[0xff] = 0;
        (**(code **)(param_1 + 0x110))(param_1,0xff,*(undefined8 *)(param_1 + 0x118));
        *(long *)(param_1 + 0x140) = *(long *)(param_1 + 0x140) + 1;
        lVar11 = 1;
        lVar17 = 0;
      }
      else {
        lVar11 = lVar17 + 1;
      }
      *(long *)(param_1 + 0x100) = lVar11;
      param_1[lVar17] = cVar34;
      param_1[0x108] = cVar34;
      if (pcVar30 == "") break;
      cVar34 = *pcVar30;
      lVar17 = lVar11;
    }
    demangle_recurse_guard(param_1,param_2,param_3[1]);
    break;
  case 0x12:
    pcVar30 = "java Class for ";
    cVar34 = 'j';
    lVar17 = *(long *)(param_1 + 0x100);
    while( true ) {
      pcVar30 = pcVar30 + 1;
      if (lVar17 == 0xff) {
        param_1[0xff] = 0;
        (**(code **)(param_1 + 0x110))(param_1,0xff,*(undefined8 *)(param_1 + 0x118));
        *(long *)(param_1 + 0x140) = *(long *)(param_1 + 0x140) + 1;
        lVar11 = 1;
        lVar17 = 0;
      }
      else {
        lVar11 = lVar17 + 1;
      }
      *(long *)(param_1 + 0x100) = lVar11;
      param_1[lVar17] = cVar34;
      param_1[0x108] = cVar34;
      if (pcVar30 == "") break;
      cVar34 = *pcVar30;
      lVar17 = lVar11;
    }
    demangle_recurse_guard(param_1,param_2,param_3[1]);
    break;
  case 0x13:
    pcVar30 = "guard variable for ";
    cVar34 = 'g';
    lVar17 = *(long *)(param_1 + 0x100);
    while( true ) {
      pcVar30 = pcVar30 + 1;
      if (lVar17 == 0xff) {
        param_1[0xff] = 0;
        (**(code **)(param_1 + 0x110))(param_1,0xff,*(undefined8 *)(param_1 + 0x118));
        *(long *)(param_1 + 0x140) = *(long *)(param_1 + 0x140) + 1;
        lVar11 = 1;
        lVar17 = 0;
      }
      else {
        lVar11 = lVar17 + 1;
      }
      *(long *)(param_1 + 0x100) = lVar11;
      param_1[lVar17] = cVar34;
      param_1[0x108] = cVar34;
      if (pcVar30 == "") break;
      cVar34 = *pcVar30;
      lVar17 = lVar11;
    }
    demangle_recurse_guard(param_1,param_2,param_3[1]);
    break;
  case 0x14:
    pcVar30 = "TLS init function for ";
    cVar34 = 'T';
    lVar17 = *(long *)(param_1 + 0x100);
    while( true ) {
      pcVar30 = pcVar30 + 1;
      if (lVar17 == 0xff) {
        param_1[0xff] = 0;
        (**(code **)(param_1 + 0x110))(param_1,0xff,*(undefined8 *)(param_1 + 0x118));
        *(long *)(param_1 + 0x140) = *(long *)(param_1 + 0x140) + 1;
        lVar11 = 1;
        lVar17 = 0;
      }
      else {
        lVar11 = lVar17 + 1;
      }
      *(long *)(param_1 + 0x100) = lVar11;
      param_1[lVar17] = cVar34;
      param_1[0x108] = cVar34;
      if (pcVar30 == "") break;
      cVar34 = *pcVar30;
      lVar17 = lVar11;
    }
    demangle_recurse_guard(param_1,param_2,param_3[1]);
    break;
  case 0x15:
    pcVar30 = "TLS wrapper function for ";
    cVar34 = 'T';
    lVar17 = *(long *)(param_1 + 0x100);
    while( true ) {
      pcVar30 = pcVar30 + 1;
      if (lVar17 == 0xff) {
        param_1[0xff] = 0;
        (**(code **)(param_1 + 0x110))(param_1,0xff,*(undefined8 *)(param_1 + 0x118));
        *(long *)(param_1 + 0x140) = *(long *)(param_1 + 0x140) + 1;
        lVar11 = 1;
        lVar17 = 0;
      }
      else {
        lVar11 = lVar17 + 1;
      }
      *(long *)(param_1 + 0x100) = lVar11;
      param_1[lVar17] = cVar34;
      param_1[0x108] = cVar34;
      if (pcVar30 == "") break;
      cVar34 = *pcVar30;
      lVar17 = lVar11;
    }
    demangle_recurse_guard(param_1,param_2,param_3[1]);
    break;
  case 0x16:
    pcVar30 = "reference temporary #";
    cVar34 = 'r';
    lVar17 = *(long *)(param_1 + 0x100);
    while( true ) {
      pcVar30 = pcVar30 + 1;
      if (lVar17 == 0xff) {
        param_1[0xff] = 0;
        (**(code **)(param_1 + 0x110))(param_1,0xff,*(undefined8 *)(param_1 + 0x118));
        *(long *)(param_1 + 0x140) = *(long *)(param_1 + 0x140) + 1;
        lVar11 = 1;
        lVar17 = 0;
      }
      else {
        lVar11 = lVar17 + 1;
      }
      *(long *)(param_1 + 0x100) = lVar11;
      param_1[lVar17] = cVar34;
      param_1[0x108] = cVar34;
      if (pcVar30 == "") break;
      cVar34 = *pcVar30;
      lVar17 = lVar11;
    }
    cVar34 = ' ';
    pcVar30 = " for ";
    demangle_recurse_guard(param_1,param_2,param_3[2]);
    lVar17 = *(long *)(param_1 + 0x100);
    while( true ) {
      if (lVar17 == 0xff) {
        param_1[0xff] = 0;
        (**(code **)(param_1 + 0x110))(param_1,0xff,*(undefined8 *)(param_1 + 0x118));
        *(long *)(param_1 + 0x140) = *(long *)(param_1 + 0x140) + 1;
        lVar11 = 1;
        lVar17 = 0;
      }
      else {
        lVar11 = lVar17 + 1;
      }
      pcVar30 = pcVar30 + 1;
      *(long *)(param_1 + 0x100) = lVar11;
      param_1[lVar17] = cVar34;
      param_1[0x108] = cVar34;
      if (pcVar30 == "") break;
      cVar34 = *pcVar30;
      lVar17 = lVar11;
    }
    demangle_recurse_guard(param_1,param_2,param_3[1]);
    break;
  case 0x17:
    pcVar30 = "hidden alias for ";
    cVar34 = 'h';
    lVar17 = *(long *)(param_1 + 0x100);
    while( true ) {
      pcVar30 = pcVar30 + 1;
      if (lVar17 == 0xff) {
        param_1[0xff] = 0;
        (**(code **)(param_1 + 0x110))(param_1,0xff,*(undefined8 *)(param_1 + 0x118));
        *(long *)(param_1 + 0x140) = *(long *)(param_1 + 0x140) + 1;
        lVar11 = 1;
        lVar17 = 0;
      }
      else {
        lVar11 = lVar17 + 1;
      }
      *(long *)(param_1 + 0x100) = lVar11;
      param_1[lVar17] = cVar34;
      param_1[0x108] = cVar34;
      if (pcVar30 == "") break;
      cVar34 = *pcVar30;
      lVar17 = lVar11;
    }
    demangle_recurse_guard(param_1,param_2,param_3[1]);
    break;
  case 0x18:
    puVar23 = (undefined1 *)param_3[1];
    if ((long)(int)param_3[2] != 0) {
      puVar33 = puVar23 + (int)param_3[2];
      lVar17 = *(long *)(param_1 + 0x100);
      do {
        uVar22 = *puVar23;
        if (lVar17 == 0xff) {
          param_1[0xff] = 0;
          (**(code **)(param_1 + 0x110))(param_1,0xff,*(undefined8 *)(param_1 + 0x118));
          *(long *)(param_1 + 0x140) = *(long *)(param_1 + 0x140) + 1;
          lVar11 = 1;
          lVar17 = 0;
        }
        else {
          lVar11 = lVar17 + 1;
        }
        puVar23 = puVar23 + 1;
        *(long *)(param_1 + 0x100) = lVar11;
        param_1[lVar17] = uVar22;
        param_1[0x108] = uVar22;
        lVar17 = lVar11;
      } while (puVar33 != puVar23);
    }
    break;
  case 0x19:
  case 0x1a:
  case 0x1b:
    plVar12 = *(long **)(param_1 + 0x128);
    for (plVar14 = plVar12; plVar14 != (long *)0x0; plVar14 = (long *)*plVar14) {
      if ((int)plVar14[2] == 0) {
        if (2 < *(int *)plVar14[1] - 0x19U) {
          uVar9 = 0;
          break;
        }
        if (iVar7 == *(int *)plVar14[1]) {
          demangle_recurse_guard(param_1,param_2,param_3[1]);
          goto switchD_00c81be2_default;
        }
      }
    }
    goto LAB_00c7f2f5;
  case 0x1c:
  case 0x1d:
  case 0x1e:
  case 0x1f:
  case 0x20:
  case 0x21:
  case 0x22:
  case 0x25:
  case 0x26:
  case 0x4c:
  case 0x4e:
  case 0x4f:
    plVar12 = *(long **)(param_1 + 0x128);
LAB_00c7f2f5:
    local_108 = plVar12;
    *(long ***)(param_1 + 0x128) = &local_108;
    local_f0 = *(undefined8 *)(param_1 + 0x120);
LAB_00c7f31a:
    lVar17 = param_3[1];
    local_100 = param_3;
LAB_00c7f31e:
    plVar14 = local_100;
    local_f8 = 0;
    demangle_recurse_guard(param_1,param_2,lVar17);
    if (local_f8 == 0) {
      FUN_00c82200(param_1,param_2,plVar14);
    }
    *(long **)(param_1 + 0x128) = local_108;
    if (uVar9 != 0) {
      *(undefined8 *)(param_1 + 0x120) = unaff_R13;
    }
    break;
  case 0x23:
  case 0x24:
    plVar14 = (long *)param_3[1];
    iVar7 = (int)*plVar14;
    if ((*(int *)(param_1 + 0x138) != 0) || (uVar9 = 0, iVar7 != 5)) goto LAB_00c7f2ce;
    iVar7 = *(int *)(param_1 + 0x158);
    puVar28 = *(undefined8 **)(param_1 + 0x150);
    if (iVar7 < 1) {
LAB_00c81836:
      if (iVar7 < *(int *)(param_1 + 0x15c)) {
        plVar12 = *(long **)(param_1 + 0x120);
        *(int *)(param_1 + 0x158) = iVar7 + 1;
        puVar28[(long)iVar7 * 2] = plVar14;
        puVar28 = puVar28 + (long)iVar7 * 2 + 1;
        if (plVar12 == (long *)0x0) {
LAB_00c818c5:
          *puVar28 = 0;
          goto LAB_00c818cc;
        }
        iVar7 = *(int *)(param_1 + 0x168);
        iVar36 = *(int *)(param_1 + 0x16c);
        if (iVar7 < iVar36) {
          lVar17 = (long)iVar7 << 4;
          puVar18 = puVar28;
          do {
            iVar7 = iVar7 + 1;
            puVar28 = (undefined8 *)(*(long *)(param_1 + 0x160) + lVar17);
            puVar28[1] = plVar12[1];
            *puVar18 = puVar28;
            plVar12 = (long *)*plVar12;
            if (plVar12 == (long *)0x0) {
              *(int *)(param_1 + 0x168) = iVar7;
              goto LAB_00c818c5;
            }
            lVar17 = lVar17 + 0x10;
            puVar18 = puVar28;
          } while (iVar36 != iVar7);
          *(int *)(param_1 + 0x168) = iVar36;
        }
      }
      *(undefined4 *)(param_1 + 0x130) = 1;
      break;
    }
    puVar18 = puVar28;
    if (plVar14 != (long *)*puVar28) {
      puVar19 = puVar28 + 2;
      do {
        puVar18 = puVar19;
        if (puVar28 + 2 + (ulong)(iVar7 - 1) * 2 == puVar18) goto LAB_00c81836;
        puVar19 = puVar18 + 2;
      } while (plVar14 != (long *)*puVar18);
    }
    puVar28 = *(undefined8 **)(param_1 + 0x148);
    if (puVar28 == (undefined8 *)0x0) {
LAB_00c7df39:
      unaff_R13 = *(undefined8 *)(param_1 + 0x120);
      uVar9 = 1;
      *(undefined8 *)(param_1 + 0x120) = puVar18[1];
      plVar14 = (long *)FUN_00c7afc0(param_1,plVar14 + 1);
      if (plVar14 != (long *)0x0) goto LAB_00c818e4;
LAB_00c7df66:
      *(undefined8 *)(param_1 + 0x120) = unaff_R13;
      goto LAB_00c7df70;
    }
    puVar19 = puVar28;
    if (plVar14 != (long *)*puVar28) {
      do {
        puVar19 = (undefined8 *)puVar19[1];
        if (puVar19 == (undefined8 *)0x0) goto LAB_00c7df39;
      } while (((long *)*puVar19 != plVar14) &&
              (((long *)*puVar19 != param_3 || (puVar28 == puVar19))));
    }
LAB_00c818cc:
    uVar9 = 0;
    plVar14 = (long *)FUN_00c7afc0(param_1,plVar14 + 1);
    if (plVar14 == (long *)0x0) goto LAB_00c7df70;
LAB_00c818e4:
    iVar7 = (int)*plVar14;
    if (iVar7 == 0x2f) {
      if (-1 < *(int *)(param_1 + 0x13c)) {
        plVar14 = (long *)FUN_00c7af90(plVar14);
        if (plVar14 == (long *)0x0) {
          if (uVar9 == 0) goto LAB_00c7df70;
          goto LAB_00c7df66;
        }
        iVar7 = (int)*plVar14;
        goto LAB_00c7f2ce;
      }
      local_108 = *(long **)(param_1 + 0x128);
      plVar12 = local_108;
      if ((int)*param_3 != 0x2f) goto LAB_00c7f2f5;
LAB_00c80701:
      param_3 = plVar14;
      plVar12 = local_108;
      goto LAB_00c7f2f5;
    }
LAB_00c7f2ce:
    local_108 = *(long **)(param_1 + 0x128);
    if ((iVar7 == 0x23) || ((int)*param_3 == iVar7)) goto LAB_00c80701;
    plVar12 = local_108;
    if (iVar7 != 0x24) goto LAB_00c7f2f5;
    lVar17 = plVar14[1];
    *(long ***)(param_1 + 0x128) = &local_108;
    local_f0 = *(undefined8 *)(param_1 + 0x120);
    local_100 = param_3;
    if (lVar17 == 0) goto LAB_00c7f31a;
    goto LAB_00c7f31e;
  case 0x27:
    puVar28 = (undefined8 *)param_3[1];
    if ((param_2 & 4) == 0) {
      puVar23 = (undefined1 *)*puVar28;
      if ((long)*(int *)(puVar28 + 1) != 0) {
        puVar33 = puVar23 + *(int *)(puVar28 + 1);
        lVar17 = *(long *)(param_1 + 0x100);
        do {
          uVar22 = *puVar23;
          if (lVar17 == 0xff) {
            param_1[0xff] = 0;
            (**(code **)(param_1 + 0x110))(param_1,0xff,*(undefined8 *)(param_1 + 0x118));
            *(long *)(param_1 + 0x140) = *(long *)(param_1 + 0x140) + 1;
            lVar11 = 1;
            lVar17 = 0;
          }
          else {
            lVar11 = lVar17 + 1;
          }
          puVar23 = puVar23 + 1;
          *(long *)(param_1 + 0x100) = lVar11;
          param_1[lVar17] = uVar22;
          param_1[0x108] = uVar22;
          lVar17 = lVar11;
        } while (puVar23 != puVar33);
      }
    }
    else {
      puVar23 = (undefined1 *)puVar28[2];
      if ((long)*(int *)(puVar28 + 3) != 0) {
        puVar33 = puVar23 + *(int *)(puVar28 + 3);
        lVar17 = *(long *)(param_1 + 0x100);
        do {
          uVar22 = *puVar23;
          if (lVar17 == 0xff) {
            param_1[0xff] = 0;
            (**(code **)(param_1 + 0x110))(param_1,0xff,*(undefined8 *)(param_1 + 0x118));
            *(long *)(param_1 + 0x140) = *(long *)(param_1 + 0x140) + 1;
            lVar11 = 1;
            lVar17 = 0;
          }
          else {
            lVar11 = lVar17 + 1;
          }
          puVar23 = puVar23 + 1;
          *(long *)(param_1 + 0x100) = lVar11;
          param_1[lVar17] = uVar22;
          param_1[0x108] = uVar22;
          lVar17 = lVar11;
        } while (puVar23 != puVar33);
      }
    }
    break;
  case 0x28:
    demangle_recurse_guard(param_1,param_2,param_3[1]);
    break;
  case 0x29:
    plVar14 = *(long **)(param_1 + 0x128);
    uVar9 = param_2 & 0xffffff9f;
    if ((param_2 & 0x20) == 0) {
      if ((param_3[1] != 0) && ((param_2 & 0x40) == 0)) {
        *(long ***)(param_1 + 0x128) = &local_108;
        local_f0 = *(undefined8 *)(param_1 + 0x120);
        local_f8 = 0;
        local_108 = plVar14;
        local_100 = param_3;
        demangle_recurse_guard(param_1,uVar9);
        *(long **)(param_1 + 0x128) = local_108;
        if (local_f8 != 0) break;
        if (*(long *)(param_1 + 0x100) == 0xff) {
          param_1[0xff] = 0;
          (**(code **)(param_1 + 0x110))(param_1,0xff,*(undefined8 *)(param_1 + 0x118));
          *(long *)(param_1 + 0x140) = *(long *)(param_1 + 0x140) + 1;
          *(undefined8 *)(param_1 + 0x100) = 0;
        }
        lVar17 = *(long *)(param_1 + 0x100);
        *(long *)(param_1 + 0x100) = lVar17 + 1;
        param_1[lVar17] = 0x20;
        plVar14 = *(long **)(param_1 + 0x128);
        param_1[0x108] = 0x20;
      }
      FUN_00c82b40(param_1,uVar9,param_3 + 2,plVar14);
    }
    else {
      FUN_00c82b40(param_1,uVar9,param_3 + 2);
      if (param_3[1] != 0) {
        demangle_recurse_guard(param_1,uVar9);
      }
    }
    break;
  case 0x2a:
    plVar14 = *(long **)(param_1 + 0x128);
    local_d0[0] = *(long **)(param_1 + 0x120);
    *(long ***)(param_1 + 0x128) = local_e8;
    local_d8._0_4_ = 0;
    local_e8[0] = plVar14;
    local_e8[1] = param_3;
    if ((plVar14 == (long *)0x0) || (2 < *(int *)plVar14[1] - 0x19U)) {
      demangle_recurse_guard(param_1,param_2,param_3[2]);
      *(long **)(param_1 + 0x128) = plVar14;
      if ((int)local_d8 != 0) break;
    }
    else {
      uVar9 = 1;
      plVar12 = plVar14;
      pplVar15 = local_e8;
      do {
        if ((int)plVar12[2] == 0) {
          if (3 < uVar9) {
            *(undefined4 *)(param_1 + 0x130) = 1;
            goto switchD_00c81be2_default;
          }
          plVar5 = (long *)plVar12[1];
          uVar16 = (ulong)uVar9;
          uVar9 = uVar9 + 1;
          local_e8[uVar16 * 4] = (long *)*plVar12;
          local_e8[uVar16 * 4 + 1] = plVar5;
          lVar17 = plVar12[2];
          plVar5 = (long *)plVar12[3];
          local_e8[uVar16 * 4] = (long *)pplVar15;
          pplVar15 = local_e8 + uVar16 * 4;
          (&local_d8)[uVar16 * 4] = lVar17;
          local_d0[uVar16 * 4] = plVar5;
          *(long ***)(param_1 + 0x128) = pplVar15;
          *(undefined4 *)(plVar12 + 2) = 1;
        }
        plVar12 = (long *)*plVar12;
      } while ((plVar12 != (long *)0x0) && (*(int *)plVar12[1] - 0x19U < 3));
      demangle_recurse_guard(param_1,param_2,param_3[2]);
      *(long **)(param_1 + 0x128) = plVar14;
      if ((int)local_d8 != 0) break;
      pplVar15 = local_e8 + (ulong)uVar9 * 4;
      for (; uVar9 != 1; uVar9 = uVar9 - 1) {
        pplVar1 = pplVar15 + -3;
        pplVar15 = pplVar15 + -4;
        FUN_00c82200(param_1,param_2,*pplVar1);
      }
    }
    FUN_00c832c0(param_1,param_2,param_3 + 1,*(undefined8 *)(param_1 + 0x128));
    break;
  case 0x2b:
  case 0x2d:
    lVar17 = param_3[2];
    local_108 = *(long **)(param_1 + 0x128);
    local_f8 = 0;
    *(long ***)(param_1 + 0x128) = &local_108;
    local_f0 = *(undefined8 *)(param_1 + 0x120);
    local_100 = param_3;
    demangle_recurse_guard(param_1,param_2,lVar17);
    if (local_f8 == 0) {
      FUN_00c82200(param_1,param_2,param_3);
    }
    *(long **)(param_1 + 0x128) = local_108;
    break;
  case 0x2c:
    if (*(short *)((long)param_3 + 0x12) != 0) {
      puVar32 = &DAT_00d99f03;
      uVar22 = 0x5f;
      lVar17 = *(long *)(param_1 + 0x100);
      while( true ) {
        if (lVar17 == 0xff) {
          param_1[0xff] = 0;
          (**(code **)(param_1 + 0x110))(param_1,0xff,*(undefined8 *)(param_1 + 0x118));
          *(long *)(param_1 + 0x140) = *(long *)(param_1 + 0x140) + 1;
          lVar11 = 1;
          lVar17 = 0;
        }
        else {
          lVar11 = lVar17 + 1;
        }
        puVar32 = puVar32 + 1;
        *(long *)(param_1 + 0x100) = lVar11;
        param_1[lVar17] = uVar22;
        param_1[0x108] = uVar22;
        if (puVar32 == &DAT_00d99f08) break;
        uVar22 = *puVar32;
        lVar17 = lVar11;
      }
    }
    if (*(undefined ***)(param_3[1] + 8) == &PTR_s_int_00d9a1e5_9_01183960) {
      lVar17 = *(long *)(param_1 + 0x100);
    }
    else {
      demangle_recurse_guard(param_1,param_2);
      lVar11 = *(long *)(param_1 + 0x100);
      lVar17 = lVar11 + 1;
      if (lVar11 == 0xff) {
        param_1[0xff] = 0;
        (**(code **)(param_1 + 0x110))(param_1,0xff,*(undefined8 *)(param_1 + 0x118));
        *(long *)(param_1 + 0x140) = *(long *)(param_1 + 0x140) + 1;
        lVar17 = 1;
        lVar11 = 0;
      }
      *(long *)(param_1 + 0x100) = lVar17;
      param_1[lVar11] = 0x20;
      param_1[0x108] = 0x20;
    }
    if ((short)param_3[2] == 0) {
      pcVar30 = "_Fract";
      cVar34 = '_';
      while( true ) {
        if (lVar17 == 0xff) {
          param_1[0xff] = 0;
          (**(code **)(param_1 + 0x110))(param_1,0xff,*(undefined8 *)(param_1 + 0x118));
          *(long *)(param_1 + 0x140) = *(long *)(param_1 + 0x140) + 1;
          lVar11 = 1;
          lVar17 = 0;
        }
        else {
          lVar11 = lVar17 + 1;
        }
        pcVar30 = pcVar30 + 1;
        *(long *)(param_1 + 0x100) = lVar11;
        param_1[lVar17] = cVar34;
        param_1[0x108] = cVar34;
        if (pcVar30 == "") break;
        cVar34 = *pcVar30;
        lVar17 = lVar11;
      }
    }
    else {
      pcVar30 = "_Accum";
      cVar34 = '_';
      while( true ) {
        if (lVar17 == 0xff) {
          param_1[0xff] = 0;
          (**(code **)(param_1 + 0x110))(param_1,0xff,*(undefined8 *)(param_1 + 0x118));
          *(long *)(param_1 + 0x140) = *(long *)(param_1 + 0x140) + 1;
          lVar11 = 1;
          lVar17 = 0;
        }
        else {
          lVar11 = lVar17 + 1;
        }
        pcVar30 = pcVar30 + 1;
        *(long *)(param_1 + 0x100) = lVar11;
        param_1[lVar17] = cVar34;
        param_1[0x108] = cVar34;
        if (pcVar30 == "") break;
        cVar34 = *pcVar30;
        lVar17 = lVar11;
      }
    }
    break;
  case 0x2e:
  case 0x2f:
    if (param_3[1] != 0) {
      demangle_recurse_guard(param_1,param_2);
    }
    if (param_3[2] != 0) {
      uVar16 = *(ulong *)(param_1 + 0x100);
      if (0xfd < uVar16) {
        param_1[uVar16] = 0;
        (**(code **)(param_1 + 0x110))(param_1,uVar16,*(undefined8 *)(param_1 + 0x118));
        *(long *)(param_1 + 0x140) = *(long *)(param_1 + 0x140) + 1;
        uVar16 = 0;
        *(undefined8 *)(param_1 + 0x100) = 0;
      }
      puVar32 = &DAT_00c89801;
      uVar22 = 0x2c;
      while( true ) {
        if (uVar16 == 0xff) {
          param_1[0xff] = 0;
          (**(code **)(param_1 + 0x110))(param_1,0xff,*(undefined8 *)(param_1 + 0x118));
          uVar31 = 1;
          uVar16 = 0;
          *(long *)(param_1 + 0x140) = *(long *)(param_1 + 0x140) + 1;
        }
        else {
          uVar31 = uVar16 + 1;
        }
        puVar32 = puVar32 + 1;
        *(ulong *)(param_1 + 0x100) = uVar31;
        param_1[uVar16] = uVar22;
        param_1[0x108] = uVar22;
        if (puVar32 == &DAT_00c89803) break;
        uVar22 = *puVar32;
        uVar16 = uVar31;
      }
      lVar17 = *(long *)(param_1 + 0x140);
      demangle_recurse_guard(param_1,param_2,param_3[2]);
      if ((*(long *)(param_1 + 0x140) == lVar17) && (*(ulong *)(param_1 + 0x100) == uVar31)) {
        *(ulong *)(param_1 + 0x100) = uVar31 - 2;
      }
    }
    break;
  case 0x30:
    lVar17 = param_3[2];
    if (param_3[1] != 0) {
      demangle_recurse_guard(param_1,param_2);
    }
    lVar13 = *(long *)(param_1 + 0x100);
    lVar11 = lVar13 + 1;
    if (lVar13 == 0xff) {
      param_1[0xff] = 0;
      (**(code **)(param_1 + 0x110))(param_1,0xff,*(undefined8 *)(param_1 + 0x118));
      *(long *)(param_1 + 0x140) = *(long *)(param_1 + 0x140) + 1;
      lVar11 = 1;
      lVar13 = 0;
    }
    *(long *)(param_1 + 0x100) = lVar11;
    param_1[lVar13] = 0x7b;
    param_1[0x108] = 0x7b;
    demangle_recurse_guard(param_1,param_2,lVar17);
    lVar11 = *(long *)(param_1 + 0x100);
    lVar17 = lVar11 + 1;
    if (lVar11 == 0xff) {
      param_1[0xff] = 0;
      (**(code **)(param_1 + 0x110))(param_1,0xff,*(undefined8 *)(param_1 + 0x118));
      *(long *)(param_1 + 0x140) = *(long *)(param_1 + 0x140) + 1;
      lVar17 = 1;
      lVar11 = 0;
    }
    *(long *)(param_1 + 0x100) = lVar17;
    param_1[lVar11] = 0x7d;
    param_1[0x108] = 0x7d;
    break;
  case 0x31:
    lVar17 = param_3[1];
    pcVar30 = "operator";
    cVar34 = 'o';
    iVar7 = *(int *)(lVar17 + 0x10);
    lVar11 = *(long *)(param_1 + 0x100);
    while( true ) {
      if (lVar11 == 0xff) {
        param_1[0xff] = 0;
        (**(code **)(param_1 + 0x110))(param_1,0xff,*(undefined8 *)(param_1 + 0x118));
        *(long *)(param_1 + 0x140) = *(long *)(param_1 + 0x140) + 1;
        lVar13 = 1;
        lVar11 = 0;
      }
      else {
        lVar13 = lVar11 + 1;
      }
      pcVar30 = pcVar30 + 1;
      *(long *)(param_1 + 0x100) = lVar13;
      param_1[lVar11] = cVar34;
      param_1[0x108] = cVar34;
      if (pcVar30 == "") break;
      cVar34 = *pcVar30;
      lVar11 = lVar13;
    }
    pcVar30 = *(char **)(lVar17 + 8);
    if ((byte)(*pcVar30 + 0x9fU) < 0x1a) {
      lVar11 = lVar13 + 1;
      if (lVar13 == 0xff) {
        param_1[0xff] = 0;
        (**(code **)(param_1 + 0x110))(param_1,0xff,*(undefined8 *)(param_1 + 0x118));
        *(long *)(param_1 + 0x140) = *(long *)(param_1 + 0x140) + 1;
        pcVar30 = *(char **)(lVar17 + 8);
        lVar13 = 0;
        lVar11 = 1;
      }
      *(long *)(param_1 + 0x100) = lVar11;
      param_1[lVar13] = 0x20;
      param_1[0x108] = 0x20;
    }
    lVar17 = (long)iVar7;
    if (pcVar30[lVar17 + -1] == ' ') {
      lVar17 = (long)(iVar7 + -1);
    }
    if (lVar17 != 0) {
      pcVar29 = pcVar30 + lVar17;
      lVar17 = *(long *)(param_1 + 0x100);
      do {
        cVar34 = *pcVar30;
        if (lVar17 == 0xff) {
          param_1[0xff] = 0;
          (**(code **)(param_1 + 0x110))(param_1,0xff,*(undefined8 *)(param_1 + 0x118));
          *(long *)(param_1 + 0x140) = *(long *)(param_1 + 0x140) + 1;
          lVar11 = 1;
          lVar17 = 0;
        }
        else {
          lVar11 = lVar17 + 1;
        }
        pcVar30 = pcVar30 + 1;
        *(long *)(param_1 + 0x100) = lVar11;
        param_1[lVar17] = cVar34;
        param_1[0x108] = cVar34;
        lVar17 = lVar11;
      } while (pcVar29 != pcVar30);
    }
    break;
  case 0x32:
    pcVar30 = "operator ";
    cVar34 = 'o';
    lVar17 = *(long *)(param_1 + 0x100);
    while( true ) {
      pcVar30 = pcVar30 + 1;
      if (lVar17 == 0xff) {
        param_1[0xff] = 0;
        (**(code **)(param_1 + 0x110))(param_1,0xff,*(undefined8 *)(param_1 + 0x118));
        *(long *)(param_1 + 0x140) = *(long *)(param_1 + 0x140) + 1;
        lVar11 = 1;
        lVar17 = 0;
      }
      else {
        lVar11 = lVar17 + 1;
      }
      *(long *)(param_1 + 0x100) = lVar11;
      param_1[lVar17] = cVar34;
      param_1[0x108] = cVar34;
      if (pcVar30 == "") break;
      cVar34 = *pcVar30;
      lVar17 = lVar11;
    }
    demangle_recurse_guard(param_1,param_2,param_3[2]);
    break;
  default:
    *(undefined4 *)(param_1 + 0x130) = 1;
    break;
  case 0x34:
    pcVar30 = "operator ";
    cVar34 = 'o';
    lVar17 = *(long *)(param_1 + 0x100);
    while( true ) {
      pcVar30 = pcVar30 + 1;
      if (lVar17 == 0xff) {
        param_1[0xff] = 0;
        (**(code **)(param_1 + 0x110))(param_1,0xff,*(undefined8 *)(param_1 + 0x118));
        *(long *)(param_1 + 0x140) = *(long *)(param_1 + 0x140) + 1;
        lVar11 = 1;
        lVar17 = 0;
      }
      else {
        lVar11 = lVar17 + 1;
      }
      *(long *)(param_1 + 0x100) = lVar11;
      param_1[lVar17] = cVar34;
      param_1[0x108] = cVar34;
      if (pcVar30 == "") break;
      cVar34 = *pcVar30;
      lVar17 = lVar11;
    }
    if (*(long **)(param_1 + 0x170) != (long *)0x0) {
      local_108 = *(long **)(param_1 + 0x120);
      *(long ***)(param_1 + 0x120) = &local_108;
      local_100 = *(long **)(param_1 + 0x170);
    }
    if (*(int *)param_3[1] == 4) {
      demangle_recurse_guard(param_1,param_2,*(undefined8 *)((int *)param_3[1] + 2));
      if (*(long *)(param_1 + 0x170) != 0) {
        *(long **)(param_1 + 0x120) = local_108;
      }
      lVar17 = *(long *)(param_1 + 0x100);
      if (param_1[0x108] == '<') {
        lVar11 = lVar17;
        if (lVar17 == 0xff) {
          param_1[0xff] = 0;
          (**(code **)(param_1 + 0x110))(param_1,0xff,*(undefined8 *)(param_1 + 0x118));
          *(long *)(param_1 + 0x140) = *(long *)(param_1 + 0x140) + 1;
          lVar11 = 0;
          *(undefined8 *)(param_1 + 0x100) = 0;
        }
        lVar17 = lVar11 + 1;
        *(long *)(param_1 + 0x100) = lVar17;
        param_1[lVar11] = 0x20;
        param_1[0x108] = 0x20;
      }
      lVar11 = lVar17 + 1;
      if (lVar17 == 0xff) {
        param_1[0xff] = 0;
        (**(code **)(param_1 + 0x110))(param_1,0xff,*(undefined8 *)(param_1 + 0x118));
        *(long *)(param_1 + 0x140) = *(long *)(param_1 + 0x140) + 1;
        lVar11 = 1;
        lVar17 = 0;
      }
      *(long *)(param_1 + 0x100) = lVar11;
      param_1[lVar17] = 0x3c;
      param_1[0x108] = 0x3c;
      demangle_recurse_guard(param_1,param_2,*(undefined8 *)(param_3[1] + 0x10));
      if (param_1[0x108] == '>') {
        if (*(long *)(param_1 + 0x100) == 0xff) {
          param_1[0xff] = 0;
          (**(code **)(param_1 + 0x110))(param_1,0xff,*(undefined8 *)(param_1 + 0x118));
          *(long *)(param_1 + 0x140) = *(long *)(param_1 + 0x140) + 1;
          *(undefined8 *)(param_1 + 0x100) = 0;
        }
        lVar11 = *(long *)(param_1 + 0x100);
        lVar17 = lVar11 + 1;
        *(long *)(param_1 + 0x100) = lVar17;
        param_1[lVar11] = 0x20;
        param_1[0x108] = 0x20;
      }
      else {
        lVar17 = *(long *)(param_1 + 0x100);
      }
      lVar11 = lVar17 + 1;
      if (lVar17 == 0xff) {
        param_1[0xff] = 0;
        (**(code **)(param_1 + 0x110))(param_1,0xff,*(undefined8 *)(param_1 + 0x118));
        *(long *)(param_1 + 0x140) = *(long *)(param_1 + 0x140) + 1;
        lVar11 = 1;
        lVar17 = 0;
      }
      *(long *)(param_1 + 0x100) = lVar11;
      param_1[lVar17] = 0x3e;
      param_1[0x108] = 0x3e;
    }
    else {
      demangle_recurse_guard(param_1,param_2);
      if (*(long *)(param_1 + 0x170) != 0) {
        *(long **)(param_1 + 0x120) = local_108;
      }
    }
    break;
  case 0x35:
    FUN_00c83580(param_1,param_2,param_3[1]);
    break;
  case 0x36:
    piVar10 = (int *)param_3[1];
    piVar25 = (int *)param_3[2];
    if (*piVar10 == 0x31) {
      iVar7 = *piVar25;
      pcVar30 = (char *)**(undefined8 **)(piVar10 + 2);
      if (*pcVar30 == 'a') {
        if (((pcVar30[1] == 'd') && (pcVar30[2] == '\0')) && (iVar7 == 3)) {
          if ((**(int **)(piVar25 + 2) == 1) && (**(int **)(piVar25 + 4) == 0x29)) {
            piVar25 = *(int **)(piVar25 + 2);
          }
        }
        else if (iVar7 == 0x38) goto LAB_00c817cb;
      }
      else {
        if (iVar7 == 0x38) {
LAB_00c817cb:
          FUN_00c83630(param_1,param_2,*(undefined8 *)(piVar25 + 2));
          FUN_00c83580(param_1,param_2,piVar10);
          break;
        }
        if (*pcVar30 == 's') {
          if (pcVar30[1] == 'Z') {
            if (pcVar30[2] == '\0') {
              for (piVar10 = (int *)FUN_00c7b000(param_1,piVar25);
                  ((piVar10 != (int *)0x0 && (*piVar10 == 0x2f)) && (*(long *)(piVar10 + 2) != 0));
                  piVar10 = *(int **)(piVar10 + 4)) {
                uVar9 = uVar9 + 1;
              }
              pcVar30 = auStack_6b + 3;
              sprintf(pcVar30,"%d",(ulong)uVar9);
              uVar16 = 0xffffffffffffffff;
              pcVar29 = pcVar30;
              do {
                if (uVar16 == 0) break;
                uVar16 = uVar16 - 1;
                cVar34 = *pcVar29;
                pcVar29 = pcVar29 + (ulong)bVar39 * -2 + 1;
              } while (cVar34 != '\0');
              if (~uVar16 - 1 != 0) {
                pcVar29 = pcVar30 + (~uVar16 - 1);
                lVar17 = *(long *)(param_1 + 0x100);
                do {
                  cVar34 = *pcVar30;
                  if (lVar17 == 0xff) {
                    param_1[0xff] = 0;
                    (**(code **)(param_1 + 0x110))(param_1,0xff,*(undefined8 *)(param_1 + 0x118));
                    *(long *)(param_1 + 0x140) = *(long *)(param_1 + 0x140) + 1;
                    lVar11 = 1;
                    lVar17 = 0;
                  }
                  else {
                    lVar11 = lVar17 + 1;
                  }
                  pcVar30 = pcVar30 + 1;
                  *(long *)(param_1 + 0x100) = lVar11;
                  param_1[lVar17] = cVar34;
                  param_1[0x108] = cVar34;
                  lVar17 = lVar11;
                } while (pcVar30 != pcVar29);
              }
              break;
            }
          }
          else if ((pcVar30[1] == 'P') && (iVar7 = 0, pcVar30[2] == '\0')) {
            do {
              if ((*piVar25 != 0x2f) || (piVar10 = *(int **)(piVar25 + 2), piVar10 == (int *)0x0))
              break;
              if (*piVar10 == 0x4a) {
                auVar40 = FUN_00c7b000(param_1,*(undefined8 *)(piVar10 + 2),iVar7);
                iVar7 = 0;
                for (piVar10 = auVar40._0_8_;
                    ((piVar10 != (int *)0x0 && (*piVar10 == 0x2f)) && (*(long *)(piVar10 + 2) != 0))
                    ; piVar10 = *(int **)(piVar10 + 4)) {
                  iVar7 = iVar7 + 1;
                }
                iVar7 = auVar40._8_4_ + iVar7;
              }
              else {
                iVar7 = iVar7 + 1;
              }
              piVar25 = *(int **)(piVar25 + 4);
            } while (piVar25 != (int *)0x0);
            puVar24 = (uint *)(auStack_6b + 3);
            sprintf((char *)puVar24,"%d");
            puVar21 = puVar24;
            do {
              puVar20 = puVar21;
              uVar8 = *puVar20 + 0xfefefeff & ~*puVar20;
              uVar9 = uVar8 & 0x80808080;
              puVar21 = puVar20 + 1;
            } while (uVar9 == 0);
            if ((uVar8 & 0x8080) == 0) {
              puVar21 = (uint *)((long)puVar20 + 6);
              uVar9 = uVar9 >> 0x10;
            }
            pcVar30 = (char *)((long)puVar21 +
                              ((-3 - (ulong)CARRY1((byte)uVar9,(byte)uVar9)) - (long)puVar24));
            if (pcVar30 != (char *)0x0) {
              puVar21 = (uint *)(pcVar30 + (long)puVar24);
              lVar17 = *(long *)(param_1 + 0x100);
              do {
                uVar9 = *puVar24;
                if (lVar17 == 0xff) {
                  param_1[0xff] = 0;
                  (**(code **)(param_1 + 0x110))(param_1,0xff,*(undefined8 *)(param_1 + 0x118));
                  *(long *)(param_1 + 0x140) = *(long *)(param_1 + 0x140) + 1;
                  lVar11 = 1;
                  lVar17 = 0;
                }
                else {
                  lVar11 = lVar17 + 1;
                }
                puVar24 = (uint *)((long)puVar24 + 1);
                *(long *)(param_1 + 0x100) = lVar11;
                param_1[lVar17] = (char)uVar9;
                param_1[0x108] = (char)uVar9;
                lVar17 = lVar11;
              } while (puVar24 != puVar21);
            }
            break;
          }
        }
      }
      FUN_00c83580(param_1,param_2,piVar10);
      if (*pcVar30 == 'g') {
        if ((pcVar30[1] == 's') && (pcVar30[2] == '\0')) {
          demangle_recurse_guard(param_1,param_2,piVar25);
          break;
        }
      }
      else if (((*pcVar30 == 's') && (pcVar30[1] == 't')) && (pcVar30[2] == '\0')) {
        if (*(long *)(param_1 + 0x100) == 0xff) {
          param_1[0xff] = 0;
          (**(code **)(param_1 + 0x110))(param_1,0xff,*(undefined8 *)(param_1 + 0x118));
          *(long *)(param_1 + 0x140) = *(long *)(param_1 + 0x140) + 1;
          *(undefined8 *)(param_1 + 0x100) = 0;
        }
        lVar17 = *(long *)(param_1 + 0x100);
        *(long *)(param_1 + 0x100) = lVar17 + 1;
        param_1[lVar17] = 0x28;
        param_1[0x108] = 0x28;
        demangle_recurse_guard(param_1,param_2,piVar25);
        lVar17 = *(long *)(param_1 + 0x100);
        if (lVar17 == 0xff) {
          param_1[0xff] = 0;
          (**(code **)(param_1 + 0x110))(param_1,0xff,*(undefined8 *)(param_1 + 0x118));
          *(long *)(param_1 + 0x140) = *(long *)(param_1 + 0x140) + 1;
          lVar17 = 0;
        }
        *(long *)(param_1 + 0x100) = lVar17 + 1;
        param_1[lVar17] = 0x29;
        param_1[0x108] = 0x29;
        break;
      }
    }
    else if (*piVar10 == 0x33) {
      if (*(long *)(param_1 + 0x100) == 0xff) {
        param_1[0xff] = 0;
        (**(code **)(param_1 + 0x110))(param_1,0xff,*(undefined8 *)(param_1 + 0x118));
        *(long *)(param_1 + 0x140) = *(long *)(param_1 + 0x140) + 1;
        *(undefined8 *)(param_1 + 0x100) = 0;
      }
      lVar17 = *(long *)(param_1 + 0x100);
      *(long *)(param_1 + 0x100) = lVar17 + 1;
      param_1[lVar17] = 0x28;
      param_1[0x108] = 0x28;
      demangle_recurse_guard(param_1,param_2,*(undefined8 *)(piVar10 + 2));
      lVar11 = *(long *)(param_1 + 0x100);
      lVar17 = lVar11 + 1;
      if (lVar11 == 0xff) {
        param_1[0xff] = 0;
        (**(code **)(param_1 + 0x110))(param_1,0xff,*(undefined8 *)(param_1 + 0x118));
        *(long *)(param_1 + 0x140) = *(long *)(param_1 + 0x140) + 1;
        lVar17 = 1;
        lVar11 = 0;
      }
      *(long *)(param_1 + 0x100) = lVar17;
      param_1[lVar11] = 0x29;
      param_1[0x108] = 0x29;
    }
    else {
      FUN_00c83580(param_1,param_2,piVar10);
    }
    FUN_00c83630(param_1,param_2,piVar25);
    break;
  case 0x37:
    if (*(int *)param_3[2] == 0x38) {
      pcVar30 = (char *)**(undefined8 **)(param_3[1] + 8);
      if ((pcVar30[1] == 'c') &&
         ((cVar34 = *pcVar30, (byte)(cVar34 + 0x8eU) < 2 || ((byte)(cVar34 + 0x9dU) < 2)))) {
        FUN_00c83580(param_1,param_2);
        if (*(long *)(param_1 + 0x100) == 0xff) {
          param_1[0xff] = 0;
          (**(code **)(param_1 + 0x110))(param_1,0xff,*(undefined8 *)(param_1 + 0x118));
          *(long *)(param_1 + 0x140) = *(long *)(param_1 + 0x140) + 1;
          *(undefined8 *)(param_1 + 0x100) = 0;
        }
        lVar17 = *(long *)(param_1 + 0x100);
        puVar32 = &DAT_00d99f21;
        uVar22 = 0x3e;
        *(long *)(param_1 + 0x100) = lVar17 + 1;
        param_1[lVar17] = 0x3c;
        param_1[0x108] = 0x3c;
        demangle_recurse_guard(param_1,param_2,*(undefined8 *)(param_3[2] + 8));
        lVar17 = *(long *)(param_1 + 0x100);
        while( true ) {
          if (lVar17 == 0xff) {
            param_1[0xff] = 0;
            (**(code **)(param_1 + 0x110))(param_1,0xff,*(undefined8 *)(param_1 + 0x118));
            *(long *)(param_1 + 0x140) = *(long *)(param_1 + 0x140) + 1;
            lVar11 = 1;
            lVar17 = 0;
          }
          else {
            lVar11 = lVar17 + 1;
          }
          puVar32 = puVar32 + 1;
          *(long *)(param_1 + 0x100) = lVar11;
          param_1[lVar17] = uVar22;
          param_1[0x108] = uVar22;
          if (puVar32 == &DAT_00d99f23) break;
          uVar22 = *puVar32;
          lVar17 = lVar11;
        }
        demangle_recurse_guard(param_1,param_2,*(undefined8 *)(param_3[2] + 0x10));
        if (*(long *)(param_1 + 0x100) == 0xff) {
          param_1[0xff] = 0;
          (**(code **)(param_1 + 0x110))(param_1,0xff,*(undefined8 *)(param_1 + 0x118));
          *(long *)(param_1 + 0x140) = *(long *)(param_1 + 0x140) + 1;
          *(undefined8 *)(param_1 + 0x100) = 0;
        }
        lVar17 = *(long *)(param_1 + 0x100);
        *(long *)(param_1 + 0x100) = lVar17 + 1;
        param_1[lVar17] = 0x29;
        param_1[0x108] = 0x29;
        break;
      }
      iVar7 = FUN_00c83730(param_1,param_2,param_3[1],param_3 + 2);
      if (iVar7 != 0) break;
      piVar10 = (int *)param_3[1];
      if (((*piVar10 == 0x31) && (*(int *)(*(long *)(piVar10 + 2) + 0x10) == 1)) &&
         (**(char **)(*(long *)(piVar10 + 2) + 8) == '>')) {
        if (*(long *)(param_1 + 0x100) == 0xff) {
          param_1[0xff] = 0;
          (**(code **)(param_1 + 0x110))(param_1,0xff,*(undefined8 *)(param_1 + 0x118));
          *(long *)(param_1 + 0x140) = *(long *)(param_1 + 0x140) + 1;
          *(undefined8 *)(param_1 + 0x100) = 0;
        }
        lVar17 = *(long *)(param_1 + 0x100);
        *(long *)(param_1 + 0x100) = lVar17 + 1;
        param_1[lVar17] = 0x28;
        param_1[0x108] = 0x28;
        piVar10 = (int *)param_3[1];
      }
      pcVar30 = (char *)**(undefined8 **)(piVar10 + 2);
      piVar10 = *(int **)(param_3[2] + 8);
      if (((*pcVar30 == 'c') && (pcVar30[1] == 'l')) && ((pcVar30[2] == '\0' && (*piVar10 == 3)))) {
        if (**(int **)(piVar10 + 4) != 0x29) {
          *(undefined4 *)(param_1 + 0x130) = 1;
        }
        FUN_00c83630(param_1,param_2,*(undefined8 *)(piVar10 + 2));
      }
      else {
        FUN_00c83630(param_1,param_2);
      }
      pcVar30 = (char *)**(undefined8 **)(param_3[1] + 8);
      if (*pcVar30 == 'i') {
        if ((pcVar30[1] != 'x') || (pcVar30[2] != '\0')) goto LAB_00c7de73;
        if (*(long *)(param_1 + 0x100) == 0xff) {
          param_1[0xff] = 0;
          (**(code **)(param_1 + 0x110))(param_1,0xff,*(undefined8 *)(param_1 + 0x118));
          *(long *)(param_1 + 0x140) = *(long *)(param_1 + 0x140) + 1;
          *(undefined8 *)(param_1 + 0x100) = 0;
        }
        lVar17 = *(long *)(param_1 + 0x100);
        *(long *)(param_1 + 0x100) = lVar17 + 1;
        param_1[lVar17] = 0x5b;
        param_1[0x108] = 0x5b;
        demangle_recurse_guard(param_1,param_2,*(undefined8 *)(param_3[2] + 0x10));
        if (*(long *)(param_1 + 0x100) == 0xff) {
          param_1[0xff] = 0;
          (**(code **)(param_1 + 0x110))(param_1,0xff,*(undefined8 *)(param_1 + 0x118));
          *(long *)(param_1 + 0x140) = *(long *)(param_1 + 0x140) + 1;
          *(undefined8 *)(param_1 + 0x100) = 0;
        }
        lVar17 = *(long *)(param_1 + 0x100);
        *(long *)(param_1 + 0x100) = lVar17 + 1;
        param_1[lVar17] = 0x5d;
        param_1[0x108] = 0x5d;
      }
      else {
        if (((*pcVar30 != 'c') || (pcVar30[1] != 'l')) || (pcVar30[2] != '\0')) {
LAB_00c7de73:
          FUN_00c83580(param_1,param_2);
        }
        FUN_00c83630(param_1,param_2,*(undefined8 *)(param_3[2] + 0x10));
      }
      if (((*(int *)param_3[1] == 0x31) &&
          (lVar17 = *(long *)((int *)param_3[1] + 2), *(int *)(lVar17 + 0x10) == 1)) &&
         (**(char **)(lVar17 + 8) == '>')) {
        if (*(long *)(param_1 + 0x100) == 0xff) {
          param_1[0xff] = 0;
          (**(code **)(param_1 + 0x110))(param_1,0xff,*(undefined8 *)(param_1 + 0x118));
          *(long *)(param_1 + 0x140) = *(long *)(param_1 + 0x140) + 1;
          *(undefined8 *)(param_1 + 0x100) = 0;
        }
        lVar17 = *(long *)(param_1 + 0x100);
        *(long *)(param_1 + 0x100) = lVar17 + 1;
        param_1[lVar17] = 0x29;
        param_1[0x108] = 0x29;
      }
      break;
    }
    goto LAB_00c7df70;
  case 0x39:
    if ((*(int *)param_3[2] == 0x3a) && (**(int **)((int *)param_3[2] + 4) == 0x3b)) {
      iVar7 = FUN_00c83730(param_1,param_2,param_3[1],param_3 + 2);
      if (iVar7 == 0) {
        lVar17 = param_3[1];
        lVar11 = *(long *)(param_3[2] + 8);
        lVar13 = *(long *)(param_3[2] + 0x10);
        uVar3 = *(undefined8 *)(lVar13 + 8);
        lVar13 = *(long *)(lVar13 + 0x10);
        pcVar30 = (char *)**(undefined8 **)(lVar17 + 8);
        if (((*pcVar30 == 'q') && (pcVar30[1] == 'u')) && (pcVar30[2] == '\0')) {
          FUN_00c83630(param_1,param_2,lVar11);
          FUN_00c83580(param_1,param_2,lVar17);
          FUN_00c83630(param_1,param_2,uVar3);
          FUN_00c7a810(param_1,&DAT_00c8ae06,3);
          FUN_00c83630(param_1,param_2,lVar13);
        }
        else {
          FUN_00c7a810(param_1,&DAT_00d99f24,4);
          if (*(long *)(lVar11 + 8) != 0) {
            FUN_00c83630(param_1,param_2,lVar11);
            if (*(long *)(param_1 + 0x100) == 0xff) {
              param_1[0xff] = 0;
              (**(code **)(param_1 + 0x110))(param_1,0xff,*(undefined8 *)(param_1 + 0x118));
              *(long *)(param_1 + 0x140) = *(long *)(param_1 + 0x140) + 1;
              *(undefined8 *)(param_1 + 0x100) = 0;
            }
            lVar17 = *(long *)(param_1 + 0x100);
            *(long *)(param_1 + 0x100) = lVar17 + 1;
            param_1[lVar17] = 0x20;
            param_1[0x108] = 0x20;
          }
          demangle_recurse_guard(param_1,param_2,uVar3);
          if (lVar13 != 0) {
            FUN_00c83630(param_1,param_2,lVar13);
          }
        }
      }
      break;
    }
LAB_00c7df70:
    *(undefined4 *)(param_1 + 0x130) = 1;
    break;
  case 0x3c:
  case 0x3d:
    uVar9 = 0;
    if ((*(int *)param_3[1] == 0x27) &&
       (uVar9 = *(uint *)(*(long *)((int *)param_3[1] + 2) + 0x1c), uVar9 != 0)) {
      if (uVar9 < 7) {
        piVar10 = (int *)param_3[2];
        if (*piVar10 == 0) {
          if (iVar7 == 0x3d) {
            if (*(long *)(param_1 + 0x100) == 0xff) {
              param_1[0xff] = 0;
              (**(code **)(param_1 + 0x110))(param_1,0xff,*(undefined8 *)(param_1 + 0x118));
              *(long *)(param_1 + 0x140) = *(long *)(param_1 + 0x140) + 1;
              *(undefined8 *)(param_1 + 0x100) = 0;
            }
            lVar17 = *(long *)(param_1 + 0x100);
            *(long *)(param_1 + 0x100) = lVar17 + 1;
            param_1[lVar17] = 0x2d;
            param_1[0x108] = 0x2d;
            piVar10 = (int *)param_3[2];
          }
          demangle_recurse_guard(param_1,param_2,piVar10);
          switch(uVar9) {
          case 2:
            if (*(long *)(param_1 + 0x100) == 0xff) {
              param_1[0xff] = 0;
              (**(code **)(param_1 + 0x110))(param_1,0xff,*(undefined8 *)(param_1 + 0x118));
              *(long *)(param_1 + 0x140) = *(long *)(param_1 + 0x140) + 1;
              *(undefined8 *)(param_1 + 0x100) = 0;
            }
            lVar17 = *(long *)(param_1 + 0x100);
            *(long *)(param_1 + 0x100) = lVar17 + 1;
            param_1[lVar17] = 0x75;
            param_1[0x108] = 0x75;
            break;
          case 3:
            if (*(long *)(param_1 + 0x100) == 0xff) {
              param_1[0xff] = 0;
              (**(code **)(param_1 + 0x110))(param_1,0xff,*(undefined8 *)(param_1 + 0x118));
              *(long *)(param_1 + 0x140) = *(long *)(param_1 + 0x140) + 1;
              *(undefined8 *)(param_1 + 0x100) = 0;
            }
            lVar17 = *(long *)(param_1 + 0x100);
            *(long *)(param_1 + 0x100) = lVar17 + 1;
            param_1[lVar17] = 0x6c;
            param_1[0x108] = 0x6c;
            break;
          case 4:
            FUN_00c7a810(param_1,&DAT_00c8caba,2);
            break;
          case 5:
            FUN_00c7a810(param_1,"ll",2);
            break;
          case 6:
            FUN_00c7a810(param_1,"ull",3);
          }
          break;
        }
      }
      else if ((((uVar9 == 7) && (piVar10 = (int *)param_3[2], *piVar10 == 0)) && (piVar10[4] == 1))
              && (iVar7 == 0x3c)) {
        if (**(char **)(piVar10 + 2) == '0') {
          FUN_00c7a810(param_1,"false",5);
          break;
        }
        if (**(char **)(piVar10 + 2) == '1') {
          FUN_00c7a810(param_1,&DAT_00c8d38f,4);
          break;
        }
      }
    }
    if (*(long *)(param_1 + 0x100) == 0xff) {
      param_1[0xff] = 0;
      (**(code **)(param_1 + 0x110))(param_1,0xff,*(undefined8 *)(param_1 + 0x118));
      *(long *)(param_1 + 0x140) = *(long *)(param_1 + 0x140) + 1;
      *(undefined8 *)(param_1 + 0x100) = 0;
    }
    lVar17 = *(long *)(param_1 + 0x100);
    *(long *)(param_1 + 0x100) = lVar17 + 1;
    param_1[lVar17] = 0x28;
    param_1[0x108] = 0x28;
    demangle_recurse_guard(param_1,param_2,param_3[1]);
    lVar17 = *(long *)(param_1 + 0x100);
    if (lVar17 == 0xff) {
      param_1[0xff] = 0;
      (**(code **)(param_1 + 0x110))(param_1,0xff,*(undefined8 *)(param_1 + 0x118));
      *(long *)(param_1 + 0x140) = *(long *)(param_1 + 0x140) + 1;
      *param_1 = 0x29;
      param_1[0x108] = 0x29;
      lVar17 = *param_3;
      *(undefined8 *)(param_1 + 0x100) = 1;
      if ((int)lVar17 == 0x3d) goto LAB_00c8118a;
    }
    else {
      *(long *)(param_1 + 0x100) = lVar17 + 1;
      param_1[lVar17] = 0x29;
      param_1[0x108] = 0x29;
      if ((int)*param_3 == 0x3d) {
        if (lVar17 + 1 == 0xff) {
          param_1[0xff] = 0;
          (**(code **)(param_1 + 0x110))(param_1,0xff,*(undefined8 *)(param_1 + 0x118));
          *(long *)(param_1 + 0x140) = *(long *)(param_1 + 0x140) + 1;
          *(undefined8 *)(param_1 + 0x100) = 0;
        }
LAB_00c8118a:
        lVar17 = *(long *)(param_1 + 0x100);
        *(long *)(param_1 + 0x100) = lVar17 + 1;
        param_1[lVar17] = 0x2d;
        param_1[0x108] = 0x2d;
      }
    }
    if (uVar9 == 8) {
      lVar17 = *(long *)(param_1 + 0x100);
      if (lVar17 == 0xff) {
        param_1[0xff] = 0;
        (**(code **)(param_1 + 0x110))(param_1,0xff,*(undefined8 *)(param_1 + 0x118));
        *(long *)(param_1 + 0x140) = *(long *)(param_1 + 0x140) + 1;
        lVar17 = 0;
      }
      *(long *)(param_1 + 0x100) = lVar17 + 1;
      param_1[lVar17] = 0x5b;
      param_1[0x108] = 0x5b;
      demangle_recurse_guard(param_1,param_2,param_3[2]);
      lVar17 = *(long *)(param_1 + 0x100);
      if (lVar17 == 0xff) {
        param_1[0xff] = 0;
        (**(code **)(param_1 + 0x110))(param_1,0xff,*(undefined8 *)(param_1 + 0x118));
        *(long *)(param_1 + 0x140) = *(long *)(param_1 + 0x140) + 1;
        lVar17 = 0;
      }
      *(long *)(param_1 + 0x100) = lVar17 + 1;
      param_1[lVar17] = 0x5d;
      param_1[0x108] = 0x5d;
    }
    else {
      demangle_recurse_guard(param_1,param_2,param_3[2]);
    }
    break;
  case 0x3e:
    pcVar30 = "java resource ";
    cVar34 = 'j';
    lVar17 = *(long *)(param_1 + 0x100);
    while( true ) {
      pcVar30 = pcVar30 + 1;
      if (lVar17 == 0xff) {
        param_1[0xff] = 0;
        (**(code **)(param_1 + 0x110))(param_1,0xff,*(undefined8 *)(param_1 + 0x118));
        *(long *)(param_1 + 0x140) = *(long *)(param_1 + 0x140) + 1;
        lVar11 = 1;
        lVar17 = 0;
      }
      else {
        lVar11 = lVar17 + 1;
      }
      *(long *)(param_1 + 0x100) = lVar11;
      param_1[lVar17] = cVar34;
      param_1[0x108] = cVar34;
      if (pcVar30 == "") break;
      cVar34 = *pcVar30;
      lVar17 = lVar11;
    }
    demangle_recurse_guard(param_1,param_2,param_3[1]);
    break;
  case 0x3f:
    demangle_recurse_guard(param_1,param_2,param_3[1]);
    demangle_recurse_guard(param_1,param_2,param_3[2]);
    break;
  case 0x40:
    lVar11 = *(long *)(param_1 + 0x100);
    lVar13 = param_3[1];
    lVar17 = lVar11 + 1;
    if (lVar11 == 0xff) {
      param_1[0xff] = 0;
      (**(code **)(param_1 + 0x110))(param_1,0xff,*(undefined8 *)(param_1 + 0x118));
      *(long *)(param_1 + 0x140) = *(long *)(param_1 + 0x140) + 1;
      lVar17 = 1;
      lVar11 = 0;
    }
    *(long *)(param_1 + 0x100) = lVar17;
    uVar22 = (undefined1)(int)lVar13;
    param_1[lVar11] = uVar22;
    param_1[0x108] = uVar22;
    break;
  case 0x41:
    puVar24 = (uint *)(auStack_6b + 3);
    sprintf((char *)puVar24,"%d",param_3[1]);
    puVar21 = puVar24;
    do {
      puVar20 = puVar21;
      uVar8 = *puVar20 + 0xfefefeff & ~*puVar20;
      uVar9 = uVar8 & 0x80808080;
      puVar21 = puVar20 + 1;
    } while (uVar9 == 0);
    if ((uVar8 & 0x8080) == 0) {
      puVar21 = (uint *)((long)puVar20 + 6);
      uVar9 = uVar9 >> 0x10;
    }
    pcVar30 = (char *)((long)puVar21 +
                      ((-3 - (ulong)CARRY1((byte)uVar9,(byte)uVar9)) - (long)puVar24));
    if (pcVar30 != (char *)0x0) {
      puVar21 = (uint *)((long)puVar24 + (long)pcVar30);
      lVar17 = *(long *)(param_1 + 0x100);
      do {
        uVar9 = *puVar24;
        if (lVar17 == 0xff) {
          param_1[0xff] = 0;
          (**(code **)(param_1 + 0x110))(param_1,0xff,*(undefined8 *)(param_1 + 0x118));
          *(long *)(param_1 + 0x140) = *(long *)(param_1 + 0x140) + 1;
          lVar11 = 1;
          lVar17 = 0;
        }
        else {
          lVar11 = lVar17 + 1;
        }
        puVar24 = (uint *)((long)puVar24 + 1);
        *(long *)(param_1 + 0x100) = lVar11;
        param_1[lVar17] = (char)uVar9;
        param_1[0x108] = (char)uVar9;
        lVar17 = lVar11;
      } while (puVar21 != puVar24);
    }
    break;
  case 0x42:
    pcVar30 = "decltype (";
    cVar34 = 'd';
    lVar17 = *(long *)(param_1 + 0x100);
    while( true ) {
      pcVar30 = pcVar30 + 1;
      if (lVar17 == 0xff) {
        param_1[0xff] = 0;
        (**(code **)(param_1 + 0x110))(param_1,0xff,*(undefined8 *)(param_1 + 0x118));
        *(long *)(param_1 + 0x140) = *(long *)(param_1 + 0x140) + 1;
        lVar11 = 1;
        lVar17 = 0;
      }
      else {
        lVar11 = lVar17 + 1;
      }
      *(long *)(param_1 + 0x100) = lVar11;
      param_1[lVar17] = cVar34;
      param_1[0x108] = cVar34;
      if (pcVar30 == "") break;
      cVar34 = *pcVar30;
      lVar17 = lVar11;
    }
    demangle_recurse_guard(param_1,param_2,param_3[1]);
    lVar11 = *(long *)(param_1 + 0x100);
    lVar17 = lVar11 + 1;
    if (lVar11 == 0xff) {
      param_1[0xff] = 0;
      (**(code **)(param_1 + 0x110))(param_1,0xff,*(undefined8 *)(param_1 + 0x118));
      *(long *)(param_1 + 0x140) = *(long *)(param_1 + 0x140) + 1;
      lVar17 = 1;
      lVar11 = 0;
    }
    *(long *)(param_1 + 0x100) = lVar17;
    param_1[lVar11] = 0x29;
    param_1[0x108] = 0x29;
    break;
  case 0x43:
    pcVar30 = "global constructors keyed to ";
    cVar34 = 'g';
    lVar17 = *(long *)(param_1 + 0x100);
    while( true ) {
      pcVar30 = pcVar30 + 1;
      if (lVar17 == 0xff) {
        param_1[0xff] = 0;
        (**(code **)(param_1 + 0x110))(param_1,0xff,*(undefined8 *)(param_1 + 0x118));
        *(long *)(param_1 + 0x140) = *(long *)(param_1 + 0x140) + 1;
        lVar11 = 1;
        lVar17 = 0;
      }
      else {
        lVar11 = lVar17 + 1;
      }
      *(long *)(param_1 + 0x100) = lVar11;
      param_1[lVar17] = cVar34;
      param_1[0x108] = cVar34;
      if (pcVar30 == "") break;
      cVar34 = *pcVar30;
      lVar17 = lVar11;
    }
    demangle_recurse_guard(param_1,param_2,param_3[1]);
    break;
  case 0x44:
    pcVar30 = "global destructors keyed to ";
    cVar34 = 'g';
    lVar17 = *(long *)(param_1 + 0x100);
    while( true ) {
      pcVar30 = pcVar30 + 1;
      if (lVar17 == 0xff) {
        param_1[0xff] = 0;
        (**(code **)(param_1 + 0x110))(param_1,0xff,*(undefined8 *)(param_1 + 0x118));
        *(long *)(param_1 + 0x140) = *(long *)(param_1 + 0x140) + 1;
        lVar11 = 1;
        lVar17 = 0;
      }
      else {
        lVar11 = lVar17 + 1;
      }
      *(long *)(param_1 + 0x100) = lVar11;
      param_1[lVar17] = cVar34;
      param_1[0x108] = cVar34;
      if (pcVar30 == "") break;
      cVar34 = *pcVar30;
      lVar17 = lVar11;
    }
    demangle_recurse_guard(param_1,param_2,param_3[1]);
    break;
  case 0x45:
    puVar32 = &DAT_00d99f85;
    uVar22 = 0x7b;
    lVar17 = *(long *)(param_1 + 0x100);
    while( true ) {
      if (lVar17 == 0xff) {
        param_1[0xff] = 0;
        (**(code **)(param_1 + 0x110))(param_1,0xff,*(undefined8 *)(param_1 + 0x118));
        *(long *)(param_1 + 0x140) = *(long *)(param_1 + 0x140) + 1;
        lVar11 = 1;
        lVar17 = 0;
      }
      else {
        lVar11 = lVar17 + 1;
      }
      puVar32 = puVar32 + 1;
      *(long *)(param_1 + 0x100) = lVar11;
      param_1[lVar17] = uVar22;
      param_1[0x108] = uVar22;
      if (puVar32 == &DAT_00d99f8d) break;
      uVar22 = *puVar32;
      lVar17 = lVar11;
    }
    lVar17 = param_3[1];
    uVar22 = 0x29;
    *(int *)(param_1 + 0x138) = *(int *)(param_1 + 0x138) + 1;
    puVar32 = &DAT_00d99f8e;
    demangle_recurse_guard(param_1,param_2,lVar17);
    *(int *)(param_1 + 0x138) = *(int *)(param_1 + 0x138) + -1;
    lVar17 = *(long *)(param_1 + 0x100);
    while( true ) {
      if (lVar17 == 0xff) {
        param_1[0xff] = 0;
        (**(code **)(param_1 + 0x110))(param_1,0xff,*(undefined8 *)(param_1 + 0x118));
        *(long *)(param_1 + 0x140) = *(long *)(param_1 + 0x140) + 1;
        lVar11 = 1;
        lVar17 = 0;
      }
      else {
        lVar11 = lVar17 + 1;
      }
      puVar32 = puVar32 + 1;
      *(long *)(param_1 + 0x100) = lVar11;
      param_1[lVar17] = uVar22;
      param_1[0x108] = uVar22;
      if (puVar32 == &DAT_00d99f90) break;
      uVar22 = *puVar32;
      lVar17 = lVar11;
    }
    puVar24 = (uint *)(auStack_6b + 3);
    sprintf((char *)puVar24,"%d",(ulong)((int)param_3[2] + 1));
    puVar21 = puVar24;
    do {
      puVar20 = puVar21;
      uVar8 = *puVar20 + 0xfefefeff & ~*puVar20;
      uVar9 = uVar8 & 0x80808080;
      puVar21 = puVar20 + 1;
    } while (uVar9 == 0);
    if ((uVar8 & 0x8080) == 0) {
      puVar21 = (uint *)((long)puVar20 + 6);
      uVar9 = uVar9 >> 0x10;
    }
    lVar17 = *(long *)(param_1 + 0x100);
    pcVar30 = (char *)((long)puVar21 +
                      ((-3 - (ulong)CARRY1((byte)uVar9,(byte)uVar9)) - (long)puVar24));
    if (pcVar30 != (char *)0x0) {
      puVar21 = (uint *)((long)puVar24 + (long)pcVar30);
      lVar11 = lVar17;
      do {
        uVar9 = *puVar24;
        if (lVar11 == 0xff) {
          param_1[0xff] = 0;
          (**(code **)(param_1 + 0x110))(param_1,0xff,*(undefined8 *)(param_1 + 0x118));
          *(long *)(param_1 + 0x140) = *(long *)(param_1 + 0x140) + 1;
          lVar17 = 1;
          lVar11 = 0;
        }
        else {
          lVar17 = lVar11 + 1;
        }
        puVar24 = (uint *)((long)puVar24 + 1);
        *(long *)(param_1 + 0x100) = lVar17;
        param_1[lVar11] = (char)uVar9;
        param_1[0x108] = (char)uVar9;
        lVar11 = lVar17;
      } while (puVar21 != puVar24);
    }
    lVar11 = lVar17 + 1;
    if (lVar17 == 0xff) {
      param_1[0xff] = 0;
      (**(code **)(param_1 + 0x110))(param_1,0xff,*(undefined8 *)(param_1 + 0x118));
      *(long *)(param_1 + 0x140) = *(long *)(param_1 + 0x140) + 1;
      lVar11 = 1;
      lVar17 = 0;
    }
    *(long *)(param_1 + 0x100) = lVar11;
    param_1[lVar17] = 0x7d;
    param_1[0x108] = 0x7d;
    break;
  case 0x47:
    pcVar30 = "{unnamed type#";
    cVar34 = '{';
    lVar17 = *(long *)(param_1 + 0x100);
    while( true ) {
      pcVar30 = pcVar30 + 1;
      if (lVar17 == 0xff) {
        param_1[0xff] = 0;
        (**(code **)(param_1 + 0x110))(param_1,0xff,*(undefined8 *)(param_1 + 0x118));
        *(long *)(param_1 + 0x140) = *(long *)(param_1 + 0x140) + 1;
        lVar11 = 1;
        lVar17 = 0;
      }
      else {
        lVar11 = lVar17 + 1;
      }
      *(long *)(param_1 + 0x100) = lVar11;
      param_1[lVar17] = cVar34;
      param_1[0x108] = cVar34;
      if (pcVar30 == "") break;
      cVar34 = *pcVar30;
      lVar17 = lVar11;
    }
    puVar24 = (uint *)(auStack_6b + 3);
    sprintf((char *)puVar24,"%d",(ulong)((int)param_3[1] + 1));
    puVar21 = puVar24;
    do {
      puVar20 = puVar21;
      uVar8 = *puVar20 + 0xfefefeff & ~*puVar20;
      uVar9 = uVar8 & 0x80808080;
      puVar21 = puVar20 + 1;
    } while (uVar9 == 0);
    if ((uVar8 & 0x8080) == 0) {
      puVar21 = (uint *)((long)puVar20 + 6);
      uVar9 = uVar9 >> 0x10;
    }
    lVar17 = *(long *)(param_1 + 0x100);
    pcVar30 = (char *)((long)puVar21 +
                      ((-3 - (ulong)CARRY1((byte)uVar9,(byte)uVar9)) - (long)puVar24));
    if (pcVar30 != (char *)0x0) {
      puVar21 = (uint *)((long)puVar24 + (long)pcVar30);
      lVar11 = lVar17;
      do {
        uVar9 = *puVar24;
        if (lVar11 == 0xff) {
          param_1[0xff] = 0;
          (**(code **)(param_1 + 0x110))(param_1,0xff,*(undefined8 *)(param_1 + 0x118));
          *(long *)(param_1 + 0x140) = *(long *)(param_1 + 0x140) + 1;
          lVar17 = 1;
          lVar11 = 0;
        }
        else {
          lVar17 = lVar11 + 1;
        }
        puVar24 = (uint *)((long)puVar24 + 1);
        *(long *)(param_1 + 0x100) = lVar17;
        param_1[lVar11] = (char)uVar9;
        param_1[0x108] = (char)uVar9;
        lVar11 = lVar17;
      } while (puVar21 != puVar24);
    }
    lVar11 = lVar17 + 1;
    if (lVar17 == 0xff) {
      param_1[0xff] = 0;
      (**(code **)(param_1 + 0x110))(param_1,0xff,*(undefined8 *)(param_1 + 0x118));
      *(long *)(param_1 + 0x140) = *(long *)(param_1 + 0x140) + 1;
      lVar11 = 1;
      lVar17 = 0;
    }
    *(long *)(param_1 + 0x100) = lVar11;
    param_1[lVar17] = 0x7d;
    param_1[0x108] = 0x7d;
    break;
  case 0x48:
    pcVar30 = "ransaction clone for ";
    cVar34 = 't';
    lVar17 = *(long *)(param_1 + 0x100);
    while( true ) {
      if (lVar17 == 0xff) {
        param_1[0xff] = 0;
        (**(code **)(param_1 + 0x110))(param_1,0xff,*(undefined8 *)(param_1 + 0x118));
        *(long *)(param_1 + 0x140) = *(long *)(param_1 + 0x140) + 1;
        lVar11 = 1;
        lVar17 = 0;
      }
      else {
        lVar11 = lVar17 + 1;
      }
      *(long *)(param_1 + 0x100) = lVar11;
      param_1[lVar17] = cVar34;
      param_1[0x108] = cVar34;
      if (pcVar30 == "") break;
      cVar34 = *pcVar30;
      pcVar30 = pcVar30 + 1;
      lVar17 = lVar11;
    }
    demangle_recurse_guard(param_1,param_2,param_3[1]);
    break;
  case 0x49:
    pcVar30 = "non-transaction clone for ";
    cVar34 = 'n';
    lVar17 = *(long *)(param_1 + 0x100);
    while( true ) {
      pcVar30 = pcVar30 + 1;
      if (lVar17 == 0xff) {
        param_1[0xff] = 0;
        (**(code **)(param_1 + 0x110))(param_1,0xff,*(undefined8 *)(param_1 + 0x118));
        *(long *)(param_1 + 0x140) = *(long *)(param_1 + 0x140) + 1;
        lVar11 = 1;
        lVar17 = 0;
      }
      else {
        lVar11 = lVar17 + 1;
      }
      *(long *)(param_1 + 0x100) = lVar11;
      param_1[lVar17] = cVar34;
      param_1[0x108] = cVar34;
      if (pcVar30 == "") break;
      cVar34 = *pcVar30;
      lVar17 = lVar11;
    }
    demangle_recurse_guard(param_1,param_2,param_3[1]);
    break;
  case 0x4a:
    piVar10 = (int *)FUN_00c7b000(param_1,param_3[1]);
    iVar7 = 0;
    if (piVar10 == (int *)0x0) {
      FUN_00c83630(param_1,param_2,param_3[1]);
      FUN_00c7a810(param_1,&DAT_00cba0c8,3);
    }
    else {
      do {
        iVar36 = iVar7;
        if ((*piVar10 != 0x2f) || (*(long *)(piVar10 + 2) == 0)) {
          local_118 = param_3[1];
          if (iVar36 == 0) goto switchD_00c81be2_default;
          local_10c = iVar36 + -1;
          iVar7 = iVar36;
          goto LAB_00c7dfdd;
        }
        piVar10 = *(int **)(piVar10 + 4);
        iVar7 = iVar36 + 1;
      } while (piVar10 != (int *)0x0);
      local_118 = param_3[1];
      local_10c = iVar36;
LAB_00c7dfdd:
      iVar36 = 0;
      do {
        *(int *)(param_1 + 0x13c) = iVar36;
        demangle_recurse_guard(param_1,param_2,local_118);
        if (iVar36 < local_10c) {
          puVar32 = &DAT_00c89801;
          uVar22 = 0x2c;
          lVar17 = *(long *)(param_1 + 0x100);
          while( true ) {
            if (lVar17 == 0xff) {
              param_1[0xff] = 0;
              (**(code **)(param_1 + 0x110))(param_1,0xff,*(undefined8 *)(param_1 + 0x118));
              *(long *)(param_1 + 0x140) = *(long *)(param_1 + 0x140) + 1;
              lVar11 = 1;
              lVar17 = 0;
            }
            else {
              lVar11 = lVar17 + 1;
            }
            puVar32 = puVar32 + 1;
            *(long *)(param_1 + 0x100) = lVar11;
            param_1[lVar17] = uVar22;
            param_1[0x108] = uVar22;
            if (puVar32 == &DAT_00c89803) break;
            uVar22 = *puVar32;
            lVar17 = lVar11;
          }
        }
        iVar36 = iVar36 + 1;
      } while (iVar36 < iVar7);
    }
    break;
  case 0x4b:
    uVar22 = 0x5b;
    puVar32 = &DAT_00d99dbc;
    demangle_recurse_guard(param_1,param_2,param_3[1]);
    lVar17 = *(long *)(param_1 + 0x100);
    while( true ) {
      if (lVar17 == 0xff) {
        param_1[0xff] = 0;
        (**(code **)(param_1 + 0x110))(param_1,0xff,*(undefined8 *)(param_1 + 0x118));
        *(long *)(param_1 + 0x140) = *(long *)(param_1 + 0x140) + 1;
        lVar11 = 1;
        lVar17 = 0;
      }
      else {
        lVar11 = lVar17 + 1;
      }
      puVar32 = puVar32 + 1;
      *(long *)(param_1 + 0x100) = lVar11;
      param_1[lVar17] = uVar22;
      param_1[0x108] = uVar22;
      if (puVar32 == &DAT_00d99dc1) break;
      uVar22 = *puVar32;
      lVar17 = lVar11;
    }
    demangle_recurse_guard(param_1,param_2,param_3[2]);
    lVar11 = *(long *)(param_1 + 0x100);
    lVar17 = lVar11 + 1;
    if (lVar11 == 0xff) {
      param_1[0xff] = 0;
      (**(code **)(param_1 + 0x110))(param_1,0xff,*(undefined8 *)(param_1 + 0x118));
      *(long *)(param_1 + 0x140) = *(long *)(param_1 + 0x140) + 1;
      lVar11 = 0;
      lVar17 = 1;
    }
    *(long *)(param_1 + 0x100) = lVar17;
    param_1[lVar11] = 0x5d;
    param_1[0x108] = 0x5d;
    break;
  case 0x4d:
    cVar34 = ' ';
    pcVar30 = " [clone ";
    demangle_recurse_guard(param_1,param_2,param_3[1]);
    lVar17 = *(long *)(param_1 + 0x100);
    while( true ) {
      if (lVar17 == 0xff) {
        param_1[0xff] = 0;
        (**(code **)(param_1 + 0x110))(param_1,0xff,*(undefined8 *)(param_1 + 0x118));
        *(long *)(param_1 + 0x140) = *(long *)(param_1 + 0x140) + 1;
        lVar11 = 1;
        lVar17 = 0;
      }
      else {
        lVar11 = lVar17 + 1;
      }
      pcVar30 = pcVar30 + 1;
      *(long *)(param_1 + 0x100) = lVar11;
      param_1[lVar17] = cVar34;
      param_1[0x108] = cVar34;
      if (pcVar30 == "") break;
      cVar34 = *pcVar30;
      lVar17 = lVar11;
    }
    demangle_recurse_guard(param_1,param_2,param_3[2]);
    lVar11 = *(long *)(param_1 + 0x100);
    lVar17 = lVar11 + 1;
    if (lVar11 == 0xff) {
      param_1[0xff] = 0;
      (**(code **)(param_1 + 0x110))(param_1,0xff,*(undefined8 *)(param_1 + 0x118));
      *(long *)(param_1 + 0x140) = *(long *)(param_1 + 0x140) + 1;
      lVar17 = 1;
      lVar11 = 0;
    }
    *(long *)(param_1 + 0x100) = lVar17;
    param_1[lVar11] = 0x5d;
    param_1[0x108] = 0x5d;
  }
switchD_00c81be2_default:
  if (local_40 == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ==== entry=00c82150 orig=FUN_00c82150 size=167 name=demangle_recurse_guard ====

void demangle_recurse_guard(long param_1,undefined8 param_2,long param_3)

{
  int iVar1;
  long in_FS_OFFSET;
  long local_38;
  undefined8 local_30;
  long local_20;
  
  local_20 = *(long *)(in_FS_OFFSET + 0x28);
  if ((param_3 != 0) && (*(int *)(param_3 + 4) < 2)) {
    iVar1 = *(int *)(param_1 + 0x134);
    if (iVar1 < 0x401) {
      *(int *)(param_3 + 4) = *(int *)(param_3 + 4) + 1;
      local_30 = *(undefined8 *)(param_1 + 0x148);
      *(int *)(param_1 + 0x134) = iVar1 + 1;
      *(long **)(param_1 + 0x148) = &local_38;
      local_38 = param_3;
      demangle_special_name(param_1,param_2,param_3);
      *(undefined8 *)(param_1 + 0x148) = local_30;
      *(int *)(param_3 + 4) = *(int *)(param_3 + 4) + -1;
      *(int *)(param_1 + 0x134) = *(int *)(param_1 + 0x134) + -1;
      goto LAB_00c821e2;
    }
  }
  *(undefined4 *)(param_1 + 0x130) = 1;
LAB_00c821e2:
  if (local_20 == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


// ==== entry=00c82200 name=FUN_00c82200 size=2228 ====

void FUN_00c82200(long param_1,ulong param_2,int *param_3)

{
  long lVar1;
  long lVar2;
  long lVar3;
  undefined *puVar4;
  undefined1 uVar5;
  ulong uVar6;
  char *pcVar7;
  char cVar8;
  
  if (0x4c < *param_3 - 3U) {
    demangle_recurse_guard();
    return;
  }
  uVar6 = param_2 & 0xffffffff;
  switch(*param_3) {
  case 3:
    param_3 = *(int **)(param_3 + 2);
  default:
switchD_00c82233_caseD_4:
    demangle_recurse_guard(param_1,param_2,param_3);
    return;
  case 0x19:
  case 0x1c:
    pcVar7 = " restrict";
    cVar8 = ' ';
    lVar3 = *(long *)(param_1 + 0x100);
    while( true ) {
      pcVar7 = pcVar7 + 1;
      if (lVar3 == 0xff) {
        *(undefined1 *)(param_1 + 0xff) = 0;
        (**(code **)(param_1 + 0x110))(param_1,0xff,*(undefined8 *)(param_1 + 0x118));
        *(long *)(param_1 + 0x140) = *(long *)(param_1 + 0x140) + 1;
        lVar1 = 1;
        lVar3 = 0;
      }
      else {
        lVar1 = lVar3 + 1;
      }
      *(long *)(param_1 + 0x100) = lVar1;
      *(char *)(param_1 + lVar3) = cVar8;
      *(char *)(param_1 + 0x108) = cVar8;
      if (pcVar7 == "") break;
      cVar8 = *pcVar7;
      lVar3 = lVar1;
    }
    break;
  case 0x1a:
  case 0x1d:
    pcVar7 = " volatile";
    cVar8 = ' ';
    lVar3 = *(long *)(param_1 + 0x100);
    while( true ) {
      pcVar7 = pcVar7 + 1;
      if (lVar3 == 0xff) {
        *(undefined1 *)(param_1 + 0xff) = 0;
        (**(code **)(param_1 + 0x110))(param_1,0xff,*(undefined8 *)(param_1 + 0x118));
        *(long *)(param_1 + 0x140) = *(long *)(param_1 + 0x140) + 1;
        lVar1 = 1;
        lVar3 = 0;
      }
      else {
        lVar1 = lVar3 + 1;
      }
      *(long *)(param_1 + 0x100) = lVar1;
      *(char *)(param_1 + lVar3) = cVar8;
      *(char *)(param_1 + 0x108) = cVar8;
      if (pcVar7 == "") break;
      cVar8 = *pcVar7;
      lVar3 = lVar1;
    }
    break;
  case 0x1b:
  case 0x1e:
    pcVar7 = " const";
    cVar8 = ' ';
    lVar3 = *(long *)(param_1 + 0x100);
    while( true ) {
      if (lVar3 == 0xff) {
        *(undefined1 *)(param_1 + 0xff) = 0;
        (**(code **)(param_1 + 0x110))(param_1,0xff,*(undefined8 *)(param_1 + 0x118));
        *(long *)(param_1 + 0x140) = *(long *)(param_1 + 0x140) + 1;
        lVar1 = 1;
        lVar3 = 0;
      }
      else {
        lVar1 = lVar3 + 1;
      }
      pcVar7 = pcVar7 + 1;
      *(long *)(param_1 + 0x100) = lVar1;
      *(char *)(param_1 + lVar3) = cVar8;
      *(char *)(param_1 + 0x108) = cVar8;
      if (pcVar7 == "") break;
      cVar8 = *pcVar7;
      lVar3 = lVar1;
    }
    break;
  case 0x1f:
    if (*(long *)(param_1 + 0x100) == 0xff) {
      *(undefined1 *)(param_1 + 0xff) = 0;
      (**(code **)(param_1 + 0x110))(param_1,0xff,*(undefined8 *)(param_1 + 0x118));
      *(long *)(param_1 + 0x140) = *(long *)(param_1 + 0x140) + 1;
      *(undefined8 *)(param_1 + 0x100) = 0;
    }
    lVar1 = *(long *)(param_1 + 0x100);
    lVar3 = lVar1 + 1;
    *(long *)(param_1 + 0x100) = lVar3;
    *(undefined1 *)(param_1 + lVar1) = 0x20;
    *(undefined1 *)(param_1 + 0x108) = 0x20;
    goto LAB_00c82767;
  case 0x20:
    if (*(long *)(param_1 + 0x100) == 0xff) {
      *(undefined1 *)(param_1 + 0xff) = 0;
      (**(code **)(param_1 + 0x110))(param_1,0xff,*(undefined8 *)(param_1 + 0x118));
      *(long *)(param_1 + 0x140) = *(long *)(param_1 + 0x140) + 1;
      *(undefined8 *)(param_1 + 0x100) = 0;
    }
    lVar1 = *(long *)(param_1 + 0x100);
    lVar3 = lVar1 + 1;
    *(long *)(param_1 + 0x100) = lVar3;
    *(undefined1 *)(param_1 + lVar1) = 0x20;
    *(undefined1 *)(param_1 + 0x108) = 0x20;
    goto LAB_00c827c7;
  case 0x21:
    if (*(long *)(param_1 + 0x100) == 0xff) {
      *(undefined1 *)(param_1 + 0xff) = 0;
      (**(code **)(param_1 + 0x110))(param_1,0xff,*(undefined8 *)(param_1 + 0x118));
      *(long *)(param_1 + 0x140) = *(long *)(param_1 + 0x140) + 1;
      *(undefined8 *)(param_1 + 0x100) = 0;
    }
    lVar3 = *(long *)(param_1 + 0x100);
    *(long *)(param_1 + 0x100) = lVar3 + 1;
    *(undefined1 *)(param_1 + lVar3) = 0x20;
    *(undefined1 *)(param_1 + 0x108) = 0x20;
    param_3 = *(int **)(param_3 + 4);
    param_2 = uVar6;
    goto switchD_00c82233_caseD_4;
  case 0x22:
    if ((param_2 & 4) == 0) {
      if (*(long *)(param_1 + 0x100) == 0xff) {
        *(undefined1 *)(param_1 + 0xff) = 0;
        (**(code **)(param_1 + 0x110))(param_1,0xff,*(undefined8 *)(param_1 + 0x118));
        *(long *)(param_1 + 0x140) = *(long *)(param_1 + 0x140) + 1;
        *(undefined8 *)(param_1 + 0x100) = 0;
      }
      lVar3 = *(long *)(param_1 + 0x100);
      *(long *)(param_1 + 0x100) = lVar3 + 1;
      *(undefined1 *)(param_1 + lVar3) = 0x2a;
      *(undefined1 *)(param_1 + 0x108) = 0x2a;
    }
    break;
  case 0x23:
    lVar3 = *(long *)(param_1 + 0x100);
LAB_00c82767:
    lVar1 = lVar3 + 1;
    if (lVar3 == 0xff) {
      *(undefined1 *)(param_1 + 0xff) = 0;
      (**(code **)(param_1 + 0x110))(param_1,0xff,*(undefined8 *)(param_1 + 0x118));
      *(long *)(param_1 + 0x140) = *(long *)(param_1 + 0x140) + 1;
      lVar1 = 1;
      lVar3 = 0;
    }
    *(long *)(param_1 + 0x100) = lVar1;
    *(undefined1 *)(param_1 + lVar3) = 0x26;
    *(undefined1 *)(param_1 + 0x108) = 0x26;
    break;
  case 0x24:
    lVar3 = *(long *)(param_1 + 0x100);
LAB_00c827c7:
    puVar4 = &DAT_00d99fe7;
    uVar5 = 0x26;
    while( true ) {
      if (lVar3 == 0xff) {
        *(undefined1 *)(param_1 + 0xff) = 0;
        (**(code **)(param_1 + 0x110))(param_1,0xff,*(undefined8 *)(param_1 + 0x118));
        *(long *)(param_1 + 0x140) = *(long *)(param_1 + 0x140) + 1;
        lVar1 = 1;
        lVar3 = 0;
      }
      else {
        lVar1 = lVar3 + 1;
      }
      puVar4 = puVar4 + 1;
      *(long *)(param_1 + 0x100) = lVar1;
      *(undefined1 *)(param_1 + lVar3) = uVar5;
      *(undefined1 *)(param_1 + 0x108) = uVar5;
      if (puVar4 == &DAT_00d99fe9) break;
      uVar5 = *puVar4;
      lVar3 = lVar1;
    }
    break;
  case 0x25:
    pcVar7 = "complex ";
    cVar8 = 'c';
    lVar3 = *(long *)(param_1 + 0x100);
    while( true ) {
      if (lVar3 == 0xff) {
        *(undefined1 *)(param_1 + 0xff) = 0;
        (**(code **)(param_1 + 0x110))(param_1,0xff,*(undefined8 *)(param_1 + 0x118));
        *(long *)(param_1 + 0x140) = *(long *)(param_1 + 0x140) + 1;
        lVar1 = 1;
        lVar3 = 0;
      }
      else {
        lVar1 = lVar3 + 1;
      }
      pcVar7 = pcVar7 + 1;
      *(long *)(param_1 + 0x100) = lVar1;
      *(char *)(param_1 + lVar3) = cVar8;
      *(char *)(param_1 + 0x108) = cVar8;
      if (pcVar7 == "") break;
      cVar8 = *pcVar7;
      lVar3 = lVar1;
    }
    break;
  case 0x26:
    pcVar7 = "imaginary ";
    cVar8 = 'i';
    lVar3 = *(long *)(param_1 + 0x100);
    while( true ) {
      pcVar7 = pcVar7 + 1;
      if (lVar3 == 0xff) {
        *(undefined1 *)(param_1 + 0xff) = 0;
        (**(code **)(param_1 + 0x110))(param_1,0xff,*(undefined8 *)(param_1 + 0x118));
        *(long *)(param_1 + 0x140) = *(long *)(param_1 + 0x140) + 1;
        lVar1 = 1;
        lVar3 = 0;
      }
      else {
        lVar1 = lVar3 + 1;
      }
      *(long *)(param_1 + 0x100) = lVar1;
      *(char *)(param_1 + lVar3) = cVar8;
      *(char *)(param_1 + 0x108) = cVar8;
      if (pcVar7 == "") break;
      cVar8 = *pcVar7;
      lVar3 = lVar1;
    }
    break;
  case 0x2b:
    if (*(char *)(param_1 + 0x108) != '(') {
      lVar1 = *(long *)(param_1 + 0x100);
      lVar3 = lVar1 + 1;
      if (lVar1 == 0xff) {
        *(undefined1 *)(param_1 + 0xff) = 0;
        (**(code **)(param_1 + 0x110))(param_1,0xff,*(undefined8 *)(param_1 + 0x118));
        *(long *)(param_1 + 0x140) = *(long *)(param_1 + 0x140) + 1;
        lVar3 = 1;
        lVar1 = 0;
      }
      *(long *)(param_1 + 0x100) = lVar3;
      *(undefined1 *)(param_1 + lVar1) = 0x20;
      *(undefined1 *)(param_1 + 0x108) = 0x20;
    }
    puVar4 = &DAT_00d99ffe;
    uVar5 = 0x3a;
    demangle_recurse_guard(param_1,uVar6,*(undefined8 *)(param_3 + 2));
    lVar3 = *(long *)(param_1 + 0x100);
    while( true ) {
      if (lVar3 == 0xff) {
        *(undefined1 *)(param_1 + 0xff) = 0;
        (**(code **)(param_1 + 0x110))(param_1,0xff,*(undefined8 *)(param_1 + 0x118));
        *(long *)(param_1 + 0x140) = *(long *)(param_1 + 0x140) + 1;
        lVar1 = 1;
        lVar3 = 0;
      }
      else {
        lVar1 = lVar3 + 1;
      }
      puVar4 = puVar4 + 1;
      *(long *)(param_1 + 0x100) = lVar1;
      *(undefined1 *)(param_1 + lVar3) = uVar5;
      *(undefined1 *)(param_1 + 0x108) = uVar5;
      if (puVar4 == &DAT_00d9a001) break;
      uVar5 = *puVar4;
      lVar3 = lVar1;
    }
    break;
  case 0x2d:
    pcVar7 = " __vector(";
    cVar8 = ' ';
    lVar3 = *(long *)(param_1 + 0x100);
    while( true ) {
      pcVar7 = pcVar7 + 1;
      if (lVar3 == 0xff) {
        *(undefined1 *)(param_1 + 0xff) = 0;
        (**(code **)(param_1 + 0x110))(param_1,0xff,*(undefined8 *)(param_1 + 0x118));
        *(long *)(param_1 + 0x140) = *(long *)(param_1 + 0x140) + 1;
        lVar1 = 1;
        lVar3 = 0;
      }
      else {
        lVar1 = lVar3 + 1;
      }
      *(long *)(param_1 + 0x100) = lVar1;
      *(char *)(param_1 + lVar3) = cVar8;
      *(char *)(param_1 + 0x108) = cVar8;
      if (pcVar7 == "") break;
      cVar8 = *pcVar7;
      lVar3 = lVar1;
    }
    lVar3 = *(long *)(param_3 + 2);
    goto LAB_00c82a1a;
  case 0x4c:
    pcVar7 = " transaction_safe";
    cVar8 = ' ';
    lVar3 = *(long *)(param_1 + 0x100);
    while( true ) {
      pcVar7 = pcVar7 + 1;
      if (lVar3 == 0xff) {
        *(undefined1 *)(param_1 + 0xff) = 0;
        (**(code **)(param_1 + 0x110))(param_1,0xff,*(undefined8 *)(param_1 + 0x118));
        *(long *)(param_1 + 0x140) = *(long *)(param_1 + 0x140) + 1;
        lVar1 = 1;
        lVar3 = 0;
      }
      else {
        lVar1 = lVar3 + 1;
      }
      *(long *)(param_1 + 0x100) = lVar1;
      *(char *)(param_1 + lVar3) = cVar8;
      *(char *)(param_1 + 0x108) = cVar8;
      if (pcVar7 == "") break;
      cVar8 = *pcVar7;
      lVar3 = lVar1;
    }
    break;
  case 0x4e:
    pcVar7 = " noexcept";
    cVar8 = ' ';
    lVar3 = *(long *)(param_1 + 0x100);
    while( true ) {
      pcVar7 = pcVar7 + 1;
      if (lVar3 == 0xff) {
        *(undefined1 *)(param_1 + 0xff) = 0;
        (**(code **)(param_1 + 0x110))(param_1,0xff,*(undefined8 *)(param_1 + 0x118));
        *(long *)(param_1 + 0x140) = *(long *)(param_1 + 0x140) + 1;
        lVar1 = 1;
        lVar3 = 0;
      }
      else {
        lVar1 = lVar3 + 1;
      }
      *(long *)(param_1 + 0x100) = lVar1;
      *(char *)(param_1 + lVar3) = cVar8;
      *(char *)(param_1 + 0x108) = cVar8;
      if (pcVar7 == "") break;
      cVar8 = *pcVar7;
      lVar3 = lVar1;
    }
    goto LAB_00c829c0;
  case 0x4f:
    pcVar7 = " throw";
    cVar8 = ' ';
    lVar3 = *(long *)(param_1 + 0x100);
    while( true ) {
      if (lVar3 == 0xff) {
        *(undefined1 *)(param_1 + 0xff) = 0;
        (**(code **)(param_1 + 0x110))(param_1,0xff,*(undefined8 *)(param_1 + 0x118));
        *(long *)(param_1 + 0x140) = *(long *)(param_1 + 0x140) + 1;
        lVar1 = 1;
        lVar3 = 0;
      }
      else {
        lVar1 = lVar3 + 1;
      }
      pcVar7 = pcVar7 + 1;
      *(long *)(param_1 + 0x100) = lVar1;
      *(char *)(param_1 + lVar3) = cVar8;
      *(char *)(param_1 + 0x108) = cVar8;
      if (pcVar7 == "") break;
      cVar8 = *pcVar7;
      lVar3 = lVar1;
    }
LAB_00c829c0:
    lVar3 = *(long *)(param_3 + 4);
    if (lVar3 != 0) {
      lVar2 = lVar1 + 1;
      if (lVar1 == 0xff) {
        *(undefined1 *)(param_1 + 0xff) = 0;
        (**(code **)(param_1 + 0x110))(param_1,0xff,*(undefined8 *)(param_1 + 0x118));
        *(long *)(param_1 + 0x140) = *(long *)(param_1 + 0x140) + 1;
        lVar3 = *(long *)(param_3 + 4);
        lVar1 = 0;
        lVar2 = 1;
      }
      *(long *)(param_1 + 0x100) = lVar2;
      *(undefined1 *)(param_1 + lVar1) = 0x28;
      *(undefined1 *)(param_1 + 0x108) = 0x28;
LAB_00c82a1a:
      demangle_recurse_guard(param_1,uVar6,lVar3);
      lVar1 = *(long *)(param_1 + 0x100);
      lVar3 = lVar1 + 1;
      if (lVar1 == 0xff) {
        *(undefined1 *)(param_1 + 0xff) = 0;
        (**(code **)(param_1 + 0x110))(param_1,0xff,*(undefined8 *)(param_1 + 0x118));
        *(long *)(param_1 + 0x140) = *(long *)(param_1 + 0x140) + 1;
        lVar3 = 1;
        lVar1 = 0;
      }
      *(long *)(param_1 + 0x100) = lVar3;
      *(undefined1 *)(param_1 + lVar1) = 0x29;
      *(undefined1 *)(param_1 + 0x108) = 0x29;
      return;
    }
  }
  return;
}


// ==== entry=00c82b40 name=FUN_00c82b40 size=745 ====

void FUN_00c82b40(undefined1 *param_1,undefined4 param_2,long *param_3,long *param_4)

{
  int iVar1;
  long *plVar2;
  long lVar3;
  byte bVar4;
  ulong uVar5;
  long lVar6;
  undefined8 uVar7;
  
  if (param_4 != (long *)0x0) {
    iVar1 = (int)param_4[2];
    plVar2 = param_4;
    while (iVar1 == 0) {
      if (*(int *)plVar2[1] - 0x19U < 0x13) {
        uVar5 = 1L << ((byte)(*(int *)plVar2[1] - 0x19U) & 0x3f);
        if ((uVar5 & 0x43107) != 0) {
          bVar4 = param_1[0x108];
          lVar3 = *(long *)(param_1 + 0x100);
LAB_00c82d6e:
          lVar6 = lVar3;
          if (bVar4 == 0x20) {
LAB_00c82cec:
            if (lVar6 != 0xff) goto LAB_00c82cf8;
LAB_00c82da4:
            param_1[0xff] = 0;
            (**(code **)(param_1 + 0x110))(param_1,0xff,*(undefined8 *)(param_1 + 0x118));
            *(long *)(param_1 + 0x140) = *(long *)(param_1 + 0x140) + 1;
            lVar3 = 1;
            lVar6 = 0;
          }
          else {
            if (lVar3 == 0xff) {
              param_1[0xff] = 0;
              (**(code **)(param_1 + 0x110))(param_1,0xff,*(undefined8 *)(param_1 + 0x118));
              *param_1 = 0x20;
              lVar6 = 1;
              *(long *)(param_1 + 0x140) = *(long *)(param_1 + 0x140) + 1;
            }
            else {
              lVar6 = lVar3 + 1;
              *(long *)(param_1 + 0x100) = lVar6;
              param_1[lVar3] = 0x20;
              param_1[0x108] = 0x20;
              if (lVar6 == 0xff) goto LAB_00c82da4;
            }
LAB_00c82cf8:
            lVar3 = lVar6 + 1;
          }
          *(long *)(param_1 + 0x100) = lVar3;
          param_1[lVar6] = 0x28;
          uVar7 = *(undefined8 *)(param_1 + 0x128);
          param_1[0x108] = 0x28;
          *(undefined8 *)(param_1 + 0x128) = 0;
          demangle_default_arg(param_1,param_2,param_4,0);
          lVar3 = *(long *)(param_1 + 0x100);
          if (lVar3 != 0xff) {
            lVar6 = lVar3 + 1;
            *(long *)(param_1 + 0x100) = lVar6;
            param_1[lVar3] = 0x29;
            param_1[0x108] = 0x29;
            goto LAB_00c82bd0;
          }
          param_1[0xff] = 0;
          (**(code **)(param_1 + 0x110))(param_1,0xff,*(undefined8 *)(param_1 + 0x118));
          *param_1 = 0x29;
          lVar6 = 1;
          *(long *)(param_1 + 0x140) = *(long *)(param_1 + 0x140) + 1;
          goto LAB_00c82bd9;
        }
        if ((uVar5 & 0xe00) != 0) {
          bVar4 = param_1[0x108];
          lVar3 = *(long *)(param_1 + 0x100);
          lVar6 = lVar3;
          if ((bVar4 & 0xfd) != 0x28) goto LAB_00c82d6e;
          goto LAB_00c82cec;
        }
      }
      plVar2 = (long *)*plVar2;
      if (plVar2 == (long *)0x0) break;
      iVar1 = *(int *)(plVar2 + 2);
    }
  }
  uVar7 = *(undefined8 *)(param_1 + 0x128);
  *(undefined8 *)(param_1 + 0x128) = 0;
  demangle_default_arg(param_1,param_2,param_4,0);
  lVar6 = *(long *)(param_1 + 0x100);
LAB_00c82bd0:
  if (lVar6 == 0xff) {
    param_1[0xff] = 0;
    (**(code **)(param_1 + 0x110))(param_1,0xff,*(undefined8 *)(param_1 + 0x118));
    *param_1 = 0x28;
    param_1[0x108] = 0x28;
    lVar3 = *param_3;
    *(long *)(param_1 + 0x140) = *(long *)(param_1 + 0x140) + 1;
    *(undefined8 *)(param_1 + 0x100) = 1;
    if (lVar3 != 0) goto LAB_00c82bf8;
    lVar3 = 1;
  }
  else {
LAB_00c82bd9:
    lVar3 = lVar6 + 1;
    *(long *)(param_1 + 0x100) = lVar3;
    param_1[lVar6] = 0x28;
    param_1[0x108] = 0x28;
    if (*param_3 != 0) {
LAB_00c82bf8:
      demangle_recurse_guard(param_1,param_2);
      lVar3 = *(long *)(param_1 + 0x100);
    }
    if (lVar3 == 0xff) {
      param_1[0xff] = 0;
      (**(code **)(param_1 + 0x110))(param_1,0xff,*(undefined8 *)(param_1 + 0x118));
      *(long *)(param_1 + 0x140) = *(long *)(param_1 + 0x140) + 1;
      lVar6 = 1;
      lVar3 = 0;
      goto LAB_00c82c19;
    }
  }
  lVar6 = lVar3 + 1;
LAB_00c82c19:
  *(long *)(param_1 + 0x100) = lVar6;
  param_1[lVar3] = 0x29;
  param_1[0x108] = 0x29;
  demangle_default_arg(param_1,param_2,param_4,1);
  *(undefined8 *)(param_1 + 0x128) = uVar7;
  return;
}


// ==== entry=00c82e40 orig=FUN_00c82e40 size=1134 name=demangle_default_arg ====

void demangle_default_arg(long param_1,uint param_2,long *param_3,int param_4)

{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  ulong uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  long lVar8;
  long lVar9;
  uint *puVar10;
  uint *puVar11;
  char *pcVar12;
  uint *__s;
  undefined *puVar13;
  int *piVar14;
  undefined1 *puVar15;
  undefined1 uVar16;
  char cVar17;
  long in_FS_OFFSET;
  undefined1 auStack_6b [43];
  long local_40;
  
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  if (param_3 == (long *)0x0) {
LAB_00c82f40:
    if (local_40 == *(long *)(in_FS_OFFSET + 0x28)) {
      return;
    }
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  iVar5 = *(int *)(param_1 + 0x130);
joined_r0x00c82e72:
  if (iVar5 != 0) goto LAB_00c82f40;
  if ((int)param_3[2] == 0) {
    piVar14 = (int *)param_3[1];
    iVar5 = *piVar14;
    if (param_4 == 0) {
      if (iVar5 - 0x1cU < 0x34) {
        if ((0xd00000000001fU >> ((ulong)(iVar5 - 0x1cU) & 0x3f) & 1) != 0) goto LAB_00c82ed8;
        goto LAB_00c82e96;
      }
      *(undefined4 *)(param_3 + 2) = 1;
      uVar1 = *(undefined8 *)(param_1 + 0x120);
      *(long *)(param_1 + 0x120) = param_3[3];
    }
    else {
LAB_00c82e96:
      *(undefined4 *)(param_3 + 2) = 1;
      uVar1 = *(undefined8 *)(param_1 + 0x120);
      *(long *)(param_1 + 0x120) = param_3[3];
      if (iVar5 == 0x29) {
        FUN_00c82b40(param_1,param_2,piVar14 + 4,*param_3);
        *(undefined8 *)(param_1 + 0x120) = uVar1;
        goto LAB_00c82f40;
      }
    }
    if (iVar5 == 0x2a) {
      FUN_00c832c0(param_1,param_2,piVar14 + 2,*param_3);
      *(undefined8 *)(param_1 + 0x120) = uVar1;
      goto LAB_00c82f40;
    }
    if (iVar5 == 2) {
      uVar2 = *(undefined8 *)(param_1 + 0x128);
      uVar3 = *(undefined8 *)(piVar14 + 2);
      *(undefined8 *)(param_1 + 0x128) = 0;
      demangle_recurse_guard(param_1,param_2,uVar3);
      *(undefined8 *)(param_1 + 0x128) = uVar2;
      lVar8 = *(long *)(param_1 + 0x100);
      if ((param_2 & 4) == 0) {
        puVar15 = &DAT_00d99dd1;
        uVar16 = 0x3a;
        while( true ) {
          if (lVar8 == 0xff) {
            *(undefined1 *)(param_1 + 0xff) = 0;
            (**(code **)(param_1 + 0x110))(param_1,0xff,*(undefined8 *)(param_1 + 0x118));
            *(long *)(param_1 + 0x140) = *(long *)(param_1 + 0x140) + 1;
            lVar8 = 0;
            lVar9 = 1;
          }
          else {
            lVar9 = lVar8 + 1;
          }
          puVar15 = puVar15 + 1;
          *(long *)(param_1 + 0x100) = lVar9;
          *(undefined1 *)(param_1 + lVar8) = uVar16;
          *(undefined1 *)(param_1 + 0x108) = uVar16;
          if (puVar15 == &DAT_00d99dd3) break;
          uVar16 = *puVar15;
          lVar8 = lVar9;
        }
      }
      else {
        lVar9 = lVar8 + 1;
        if (lVar8 == 0xff) {
          *(undefined1 *)(param_1 + 0xff) = 0;
          (**(code **)(param_1 + 0x110))(param_1,0xff,*(undefined8 *)(param_1 + 0x118));
          *(long *)(param_1 + 0x140) = *(long *)(param_1 + 0x140) + 1;
          lVar9 = 1;
          lVar8 = 0;
        }
        *(long *)(param_1 + 0x100) = lVar9;
        *(undefined1 *)(param_1 + lVar8) = 0x2e;
        *(undefined1 *)(param_1 + 0x108) = 0x2e;
      }
      piVar14 = *(int **)(param_3[1] + 0x10);
      iVar5 = *piVar14;
      if (iVar5 == 0x46) {
        pcVar12 = "{default arg#";
        cVar17 = '{';
        lVar8 = *(long *)(param_1 + 0x100);
        while( true ) {
          pcVar12 = pcVar12 + 1;
          if (lVar8 == 0xff) {
            *(undefined1 *)(param_1 + 0xff) = 0;
            (**(code **)(param_1 + 0x110))(param_1,0xff,*(undefined8 *)(param_1 + 0x118));
            *(long *)(param_1 + 0x140) = *(long *)(param_1 + 0x140) + 1;
            lVar8 = 0;
            lVar9 = 1;
          }
          else {
            lVar9 = lVar8 + 1;
          }
          *(long *)(param_1 + 0x100) = lVar9;
          *(char *)(param_1 + lVar8) = cVar17;
          *(char *)(param_1 + 0x108) = cVar17;
          if (pcVar12 == "") break;
          cVar17 = *pcVar12;
          lVar8 = lVar9;
        }
        __s = (uint *)(auStack_6b + 3);
        sprintf((char *)__s,"%d",(ulong)(piVar14[4] + 1));
        puVar11 = __s;
        do {
          puVar10 = puVar11;
          uVar6 = *puVar10 + 0xfefefeff & ~*puVar10;
          uVar7 = uVar6 & 0x80808080;
          puVar11 = puVar10 + 1;
        } while (uVar7 == 0);
        if ((uVar6 & 0x8080) == 0) {
          puVar11 = (uint *)((long)puVar10 + 6);
          uVar7 = uVar7 >> 0x10;
        }
        lVar8 = *(long *)(param_1 + 0x100);
        pcVar12 = (char *)((long)puVar11 +
                          ((-3 - (ulong)CARRY1((byte)uVar7,(byte)uVar7)) - (long)__s));
        if (pcVar12 != (char *)0x0) {
          puVar11 = (uint *)((long)__s + (long)pcVar12);
          lVar9 = lVar8;
          do {
            cVar17 = (char)*__s;
            if (lVar9 == 0xff) {
              *(undefined1 *)(param_1 + 0xff) = 0;
              auStack_6b[2] = cVar17;
              (**(code **)(param_1 + 0x110))(param_1,0xff,*(undefined8 *)(param_1 + 0x118));
              *(long *)(param_1 + 0x140) = *(long *)(param_1 + 0x140) + 1;
              lVar8 = 1;
              lVar9 = 0;
              cVar17 = auStack_6b[2];
            }
            else {
              lVar8 = lVar9 + 1;
            }
            __s = (uint *)((long)__s + 1);
            *(long *)(param_1 + 0x100) = lVar8;
            *(char *)(param_1 + lVar9) = cVar17;
            *(char *)(param_1 + 0x108) = cVar17;
            lVar9 = lVar8;
          } while (puVar11 != __s);
        }
        puVar13 = &DAT_00d99dd0;
        uVar16 = 0x7d;
        while( true ) {
          if (lVar8 == 0xff) {
            *(undefined1 *)(param_1 + 0xff) = 0;
            (**(code **)(param_1 + 0x110))(param_1,0xff,*(undefined8 *)(param_1 + 0x118));
            *(long *)(param_1 + 0x140) = *(long *)(param_1 + 0x140) + 1;
            lVar8 = 0;
            lVar9 = 1;
          }
          else {
            lVar9 = lVar8 + 1;
          }
          puVar13 = puVar13 + 1;
          *(long *)(param_1 + 0x100) = lVar9;
          *(undefined1 *)(param_1 + lVar8) = uVar16;
          *(undefined1 *)(param_1 + 0x108) = uVar16;
          if (puVar13 == &DAT_00d99dd3) break;
          uVar16 = *puVar13;
          lVar8 = lVar9;
        }
        piVar14 = *(int **)(piVar14 + 2);
        iVar5 = *piVar14;
      }
      if (iVar5 - 0x1cU < 0x34) {
        uVar4 = 0xd00000000001fU >> ((ulong)(iVar5 - 0x1cU) & 0x3f) & 1;
        while (uVar4 != 0) {
          piVar14 = *(int **)(piVar14 + 2);
          if (0x33 < *piVar14 - 0x1cU) break;
          uVar4 = 1L << ((byte)(*piVar14 - 0x1cU) & 0x3f) & 0xd00000000001f;
        }
      }
      demangle_recurse_guard(param_1,param_2,piVar14);
      *(undefined8 *)(param_1 + 0x120) = uVar1;
      goto LAB_00c82f40;
    }
    FUN_00c82200(param_1,param_2);
    *(undefined8 *)(param_1 + 0x120) = uVar1;
  }
LAB_00c82ed8:
  param_3 = (long *)*param_3;
  if (param_3 == (long *)0x0) goto LAB_00c82f40;
  iVar5 = *(int *)(param_1 + 0x130);
  goto joined_r0x00c82e72;
}


// ==== entry=00c832c0 name=FUN_00c832c0 size=663 ====

void FUN_00c832c0(undefined1 *param_1,undefined4 param_2,long *param_3,long *param_4)

{
  long *plVar1;
  long lVar2;
  long lVar3;
  char *pcVar4;
  char cVar5;
  
  plVar1 = param_4;
  if (param_4 != (long *)0x0) {
LAB_00c832e8:
    if ((int)plVar1[2] != 0) goto code_r0x00c832f3;
    if (*(int *)plVar1[1] != 0x2a) {
      pcVar4 = " (";
      cVar5 = ' ';
      lVar3 = *(long *)(param_1 + 0x100);
      while( true ) {
        if (lVar3 == 0xff) {
          param_1[0xff] = 0;
          (**(code **)(param_1 + 0x110))(param_1,0xff,*(undefined8 *)(param_1 + 0x118));
          *(long *)(param_1 + 0x140) = *(long *)(param_1 + 0x140) + 1;
          lVar3 = 0;
          lVar2 = 1;
        }
        else {
          lVar2 = lVar3 + 1;
        }
        pcVar4 = pcVar4 + 1;
        *(long *)(param_1 + 0x100) = lVar2;
        param_1[lVar3] = cVar5;
        param_1[0x108] = cVar5;
        if (pcVar4 == "") break;
        cVar5 = *pcVar4;
        lVar3 = lVar2;
      }
      demangle_default_arg(param_1,param_2,param_4,0);
      lVar3 = *(long *)(param_1 + 0x100);
      if (lVar3 != 0xff) {
        lVar2 = lVar3 + 1;
        *(long *)(param_1 + 0x100) = lVar2;
        param_1[lVar3] = 0x29;
        param_1[0x108] = 0x29;
        goto LAB_00c83312;
      }
      param_1[0xff] = 0;
      (**(code **)(param_1 + 0x110))(param_1,0xff,*(undefined8 *)(param_1 + 0x118));
      *param_1 = 0x29;
      lVar2 = 1;
      *(long *)(param_1 + 0x140) = *(long *)(param_1 + 0x140) + 1;
      goto LAB_00c8331e;
    }
    demangle_default_arg(param_1,param_2,param_4,0);
    lVar3 = *(long *)(param_1 + 0x100);
    goto LAB_00c83334;
  }
LAB_00c8330b:
  lVar2 = *(long *)(param_1 + 0x100);
LAB_00c83312:
  if (lVar2 == 0xff) {
    param_1[0xff] = 0;
    (**(code **)(param_1 + 0x110))(param_1,0xff,*(undefined8 *)(param_1 + 0x118));
    *param_1 = 0x20;
    lVar3 = 1;
    *(long *)(param_1 + 0x140) = *(long *)(param_1 + 0x140) + 1;
LAB_00c8333d:
    lVar2 = lVar3 + 1;
    *(long *)(param_1 + 0x100) = lVar2;
    param_1[lVar3] = 0x5b;
    param_1[0x108] = 0x5b;
    if (*param_3 != 0) {
LAB_00c8335c:
      demangle_recurse_guard(param_1,param_2);
      lVar2 = *(long *)(param_1 + 0x100);
    }
    if (lVar2 == 0xff) {
      param_1[0xff] = 0;
      (**(code **)(param_1 + 0x110))(param_1,0xff,*(undefined8 *)(param_1 + 0x118));
      *(long *)(param_1 + 0x140) = *(long *)(param_1 + 0x140) + 1;
      lVar3 = 1;
      lVar2 = 0;
      goto LAB_00c8337a;
    }
  }
  else {
LAB_00c8331e:
    lVar3 = lVar2 + 1;
    *(long *)(param_1 + 0x100) = lVar3;
    param_1[lVar2] = 0x20;
    param_1[0x108] = 0x20;
LAB_00c83334:
    if (lVar3 != 0xff) goto LAB_00c8333d;
    param_1[0xff] = 0;
    (**(code **)(param_1 + 0x110))(param_1,0xff,*(undefined8 *)(param_1 + 0x118));
    *param_1 = 0x5b;
    param_1[0x108] = 0x5b;
    lVar3 = *param_3;
    *(long *)(param_1 + 0x140) = *(long *)(param_1 + 0x140) + 1;
    *(undefined8 *)(param_1 + 0x100) = 1;
    if (lVar3 != 0) goto LAB_00c8335c;
    lVar2 = 1;
  }
  lVar3 = lVar2 + 1;
LAB_00c8337a:
  *(long *)(param_1 + 0x100) = lVar3;
  param_1[lVar2] = 0x5d;
  param_1[0x108] = 0x5d;
  return;
code_r0x00c832f3:
  plVar1 = (long *)*plVar1;
  if (plVar1 == (long *)0x0) goto code_r0x00c832fb;
  goto LAB_00c832e8;
code_r0x00c832fb:
  demangle_default_arg(param_1,param_2,param_4,0);
  goto LAB_00c8330b;
}


// ==== entry=00c83580 name=FUN_00c83580 size=155 ====

void FUN_00c83580(long param_1,undefined8 param_2,int *param_3)

{
  undefined1 uVar1;
  long lVar2;
  undefined1 *puVar3;
  long lVar4;
  undefined1 *puVar5;
  
  if (*param_3 != 0x31) {
    demangle_recurse_guard();
    return;
  }
  lVar4 = (long)*(int *)(*(long *)(param_3 + 2) + 0x10);
  puVar3 = *(undefined1 **)(*(long *)(param_3 + 2) + 8);
  if (lVar4 != 0) {
    puVar5 = puVar3 + lVar4;
    lVar4 = *(long *)(param_1 + 0x100);
    do {
      uVar1 = *puVar3;
      if (lVar4 == 0xff) {
        *(undefined1 *)(param_1 + 0xff) = 0;
        (**(code **)(param_1 + 0x110))(param_1,0xff,*(undefined8 *)(param_1 + 0x118));
        *(long *)(param_1 + 0x140) = *(long *)(param_1 + 0x140) + 1;
        lVar2 = 1;
        lVar4 = 0;
      }
      else {
        lVar2 = lVar4 + 1;
      }
      puVar3 = puVar3 + 1;
      *(long *)(param_1 + 0x100) = lVar2;
      *(undefined1 *)(param_1 + lVar4) = uVar1;
      *(undefined1 *)(param_1 + 0x108) = uVar1;
      lVar4 = lVar2;
    } while (puVar3 != puVar5);
  }
  return;
}


// ==== entry=00c83630 name=FUN_00c83630 size=234 ====

void FUN_00c83630(long param_1,undefined4 param_2,uint *param_3)

{
  long lVar1;
  long lVar2;
  
  if ((*param_3 < 0x31) && ((0x1000000000043U >> ((ulong)*param_3 & 0x3f) & 1) != 0)) {
    demangle_recurse_guard();
    return;
  }
  lVar1 = *(long *)(param_1 + 0x100);
  lVar2 = lVar1 + 1;
  if (lVar1 == 0xff) {
    *(undefined1 *)(param_1 + 0xff) = 0;
    (**(code **)(param_1 + 0x110))(param_1,0xff,*(undefined8 *)(param_1 + 0x118));
    *(long *)(param_1 + 0x140) = *(long *)(param_1 + 0x140) + 1;
    lVar2 = 1;
    lVar1 = 0;
  }
  *(long *)(param_1 + 0x100) = lVar2;
  *(undefined1 *)(param_1 + lVar1) = 0x28;
  *(undefined1 *)(param_1 + 0x108) = 0x28;
  demangle_recurse_guard(param_1,param_2,param_3);
  lVar1 = *(long *)(param_1 + 0x100);
  lVar2 = lVar1 + 1;
  if (lVar1 == 0xff) {
    *(undefined1 *)(param_1 + 0xff) = 0;
    (**(code **)(param_1 + 0x110))(param_1,0xff,*(undefined8 *)(param_1 + 0x118));
    *(long *)(param_1 + 0x140) = *(long *)(param_1 + 0x140) + 1;
    lVar2 = 1;
    lVar1 = 0;
  }
  *(long *)(param_1 + 0x100) = lVar2;
  *(undefined1 *)(param_1 + lVar1) = 0x29;
  *(undefined1 *)(param_1 + 0x108) = 0x29;
  return;
}


// ==== entry=00c83730 name=FUN_00c83730 size=909 ====

undefined8 FUN_00c83730(long param_1,undefined4 param_2,long param_3,long *param_4)

{
  char cVar1;
  undefined4 uVar2;
  char *pcVar3;
  undefined8 uVar4;
  long lVar5;
  int *piVar6;
  long lVar7;
  undefined *puVar8;
  undefined1 uVar9;
  int *piVar10;
  
  pcVar3 = (char *)**(undefined8 **)(param_3 + 8);
  if (*pcVar3 != 'f') {
    return 0;
  }
  piVar6 = (int *)0x0;
  piVar10 = *(int **)(*param_4 + 0x10);
  uVar4 = *(undefined8 *)(*param_4 + 8);
  if (*piVar10 == 0x3b) {
    piVar6 = *(int **)(piVar10 + 4);
    piVar10 = *(int **)(piVar10 + 2);
  }
  uVar2 = *(undefined4 *)(param_1 + 0x13c);
  *(undefined4 *)(param_1 + 0x13c) = 0xffffffff;
  cVar1 = pcVar3[1];
  if (cVar1 == 'R') {
LAB_00c83904:
    if (*(long *)(param_1 + 0x100) == 0xff) {
      *(undefined1 *)(param_1 + 0xff) = 0;
      (**(code **)(param_1 + 0x110))(param_1,0xff,*(undefined8 *)(param_1 + 0x118));
      *(long *)(param_1 + 0x140) = *(long *)(param_1 + 0x140) + 1;
      *(undefined8 *)(param_1 + 0x100) = 0;
    }
    lVar7 = *(long *)(param_1 + 0x100);
    puVar8 = &DAT_00cba0c8;
    *(long *)(param_1 + 0x100) = lVar7 + 1;
    *(undefined1 *)(param_1 + lVar7) = 0x28;
    *(undefined1 *)(param_1 + 0x108) = 0x28;
    FUN_00c83630(param_1,param_2,piVar10);
    FUN_00c83580(param_1,param_2,uVar4);
    uVar9 = 0x2e;
    lVar7 = *(long *)(param_1 + 0x100);
    while( true ) {
      if (lVar7 == 0xff) {
        *(undefined1 *)(param_1 + 0xff) = 0;
        (**(code **)(param_1 + 0x110))(param_1,0xff,*(undefined8 *)(param_1 + 0x118));
        *(long *)(param_1 + 0x140) = *(long *)(param_1 + 0x140) + 1;
        lVar5 = 1;
        lVar7 = 0;
      }
      else {
        lVar5 = lVar7 + 1;
      }
      puVar8 = puVar8 + 1;
      *(long *)(param_1 + 0x100) = lVar5;
      *(undefined1 *)(param_1 + lVar7) = uVar9;
      *(undefined1 *)(param_1 + 0x108) = uVar9;
      if (puVar8 == &DAT_00cba0cb) break;
      uVar9 = *puVar8;
      lVar7 = lVar5;
    }
    FUN_00c83580(param_1,param_2,uVar4);
  }
  else {
    if (cVar1 < 'S') {
      if (cVar1 != 'L') goto LAB_00c838e3;
      goto LAB_00c83904;
    }
    if (cVar1 != 'l') {
      if (cVar1 == 'r') {
        lVar5 = *(long *)(param_1 + 0x100);
        lVar7 = lVar5 + 1;
        if (lVar5 == 0xff) {
          *(undefined1 *)(param_1 + 0xff) = 0;
          (**(code **)(param_1 + 0x110))(param_1,0xff,*(undefined8 *)(param_1 + 0x118));
          *(long *)(param_1 + 0x140) = *(long *)(param_1 + 0x140) + 1;
          lVar7 = 1;
          lVar5 = 0;
        }
        *(long *)(param_1 + 0x100) = lVar7;
        *(undefined1 *)(param_1 + lVar5) = 0x28;
        uVar9 = 0x2e;
        *(undefined1 *)(param_1 + 0x108) = 0x28;
        FUN_00c83630(param_1,param_2,piVar10);
        puVar8 = &DAT_00d9a012;
        FUN_00c83580(param_1,param_2,uVar4);
        lVar7 = *(long *)(param_1 + 0x100);
        while( true ) {
          if (lVar7 == 0xff) {
            *(undefined1 *)(param_1 + 0xff) = 0;
            (**(code **)(param_1 + 0x110))(param_1,0xff,*(undefined8 *)(param_1 + 0x118));
            *(long *)(param_1 + 0x140) = *(long *)(param_1 + 0x140) + 1;
            lVar5 = 1;
            lVar7 = 0;
          }
          else {
            lVar5 = lVar7 + 1;
          }
          puVar8 = puVar8 + 1;
          *(long *)(param_1 + 0x100) = lVar5;
          *(undefined1 *)(param_1 + lVar7) = uVar9;
          *(undefined1 *)(param_1 + 0x108) = uVar9;
          if (puVar8 == &DAT_00d9a016) break;
          uVar9 = *puVar8;
          lVar7 = lVar5;
        }
      }
      goto LAB_00c838e3;
    }
    puVar8 = &DAT_00d9a00d;
    uVar9 = 0x28;
    lVar7 = *(long *)(param_1 + 0x100);
    while( true ) {
      if (lVar7 == 0xff) {
        *(undefined1 *)(param_1 + 0xff) = 0;
        (**(code **)(param_1 + 0x110))(param_1,0xff,*(undefined8 *)(param_1 + 0x118));
        *(long *)(param_1 + 0x140) = *(long *)(param_1 + 0x140) + 1;
        lVar7 = 0;
        lVar5 = 1;
      }
      else {
        lVar5 = lVar7 + 1;
      }
      puVar8 = puVar8 + 1;
      *(long *)(param_1 + 0x100) = lVar5;
      *(undefined1 *)(param_1 + lVar7) = uVar9;
      *(undefined1 *)(param_1 + 0x108) = uVar9;
      if (puVar8 == &DAT_00d9a011) break;
      uVar9 = *puVar8;
      lVar7 = lVar5;
    }
    FUN_00c83580(param_1,param_2,uVar4);
    piVar6 = piVar10;
  }
  FUN_00c83630(param_1,param_2,piVar6);
  lVar5 = *(long *)(param_1 + 0x100);
  lVar7 = lVar5 + 1;
  if (lVar5 == 0xff) {
    *(undefined1 *)(param_1 + 0xff) = 0;
    (**(code **)(param_1 + 0x110))(param_1,0xff,*(undefined8 *)(param_1 + 0x118));
    *(long *)(param_1 + 0x140) = *(long *)(param_1 + 0x140) + 1;
    lVar7 = 1;
    lVar5 = 0;
  }
  *(long *)(param_1 + 0x100) = lVar7;
  *(undefined1 *)(param_1 + lVar5) = 0x29;
  *(undefined1 *)(param_1 + 0x108) = 0x29;
LAB_00c838e3:
  *(undefined4 *)(param_1 + 0x13c) = uVar2;
  return 1;
}


// ==== entry=00c83b00 orig=FUN_00c83b00 size=1400 name=demangle_global_prefix ====

bool demangle_global_prefix(byte *param_1,code *param_2,undefined8 param_3)

{
  byte bVar1;
  long lVar2;
  code *pcVar3;
  undefined8 uVar4;
  int iVar5;
  size_t sVar6;
  long lVar7;
  long lVar8;
  byte *pbVar9;
  undefined8 *puVar10;
  byte bVar11;
  long lVar12;
  byte *pbVar13;
  byte bVar14;
  ulong uVar15;
  long in_FS_OFFSET;
  bool bVar16;
  bool bVar17;
  undefined8 uStack_240;
  undefined8 local_238;
  int local_22c;
  byte *local_228;
  undefined8 local_220;
  byte *local_218;
  byte *local_210;
  uint local_208;
  byte *local_200;
  long local_1f8;
  int local_1f0;
  int local_1ec;
  undefined1 *local_1e8;
  undefined4 local_1e0;
  int local_1dc;
  undefined8 local_1d8;
  undefined8 local_1d0;
  undefined4 local_1c8;
  undefined1 local_1b8 [256];
  long local_b8;
  undefined1 local_b0;
  code *local_a8;
  undefined8 local_a0;
  undefined8 local_98;
  undefined8 local_90;
  undefined8 local_88;
  undefined8 local_80;
  undefined8 local_78;
  undefined8 local_70;
  undefined1 *local_68;
  undefined8 local_60;
  undefined1 *local_58;
  undefined8 local_50;
  undefined8 local_48;
  long local_40;
  
  bVar11 = *param_1;
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  bVar16 = bVar11 < 0x5f;
  bVar17 = false;
  if (bVar11 == 0x5f) {
    bVar16 = param_1[1] < 0x5a;
    bVar17 = param_1[1] == 0x5a;
    bVar14 = 1;
    if (!bVar17) goto LAB_00c83b3e;
  }
  else {
LAB_00c83b3e:
    lVar8 = 8;
    pbVar9 = param_1;
    pbVar13 = (byte *)"_GLOBAL_";
    do {
      if (lVar8 == 0) break;
      lVar8 = lVar8 + -1;
      bVar16 = *pbVar9 < *pbVar13;
      bVar17 = *pbVar9 == *pbVar13;
      pbVar9 = pbVar9 + 1;
      pbVar13 = pbVar13 + 1;
    } while (bVar17);
    bVar14 = 0;
    if ((((((!bVar16 && !bVar17) == bVar16) && (bVar14 = 0, (byte)(param_1[8] - 0x24) < 0x3c)) &&
         (bVar14 = 0, (0x800000000000401U >> ((ulong)(param_1[8] - 0x24) & 0x3f) & 1) != 0)) &&
        ((bVar1 = param_1[9], bVar1 == 0x44 || (bVar1 == 0x49)))) &&
       (bVar14 = 0, param_1[10] == 0x5f)) {
      bVar14 = (bVar1 != 0x49) + 2;
    }
  }
  uStack_240 = 0xc83b98;
  local_220 = param_3;
  sVar6 = strlen((char *)param_1);
  local_210 = param_1 + sVar6;
  local_1dc = (int)sVar6;
  local_1ec = local_1dc * 2;
  local_208 = 0x11;
  lVar8 = (long)local_1ec * -0x18;
  local_1f0 = 0;
  lVar2 = -((long)local_1dc * 8 + 0xfU & 0xfffffffffffffff0);
  local_1e8 = (undefined1 *)((long)&local_238 + lVar2 + lVar8);
  uVar15 = (ulong)((long)&local_238 + lVar8 + 7) >> 3;
  local_1e0 = 0;
  local_1f8 = uVar15 * 8;
  local_1d8 = 0;
  local_1d0 = 0;
  local_1c8 = 0;
  local_218 = param_1;
  local_200 = param_1;
  if (bVar14 == 1) {
    local_1e8 = (undefined1 *)((long)&local_238 + lVar2 + lVar8);
    if ((bVar11 == 0x5f) &&
       (local_200 = param_1 + 1, local_1e8 = (undefined1 *)((long)&local_238 + lVar2 + lVar8),
       param_1[1] == 0x5a)) {
      local_200 = param_1 + 2;
      local_1e8 = (undefined1 *)((long)&local_238 + lVar2 + lVar8);
      *(undefined8 *)((long)&uStack_240 + lVar2 + lVar8) = 0xc83ece;
      lVar7 = FUN_00c7d680(&local_218,1);
      if ((local_208 & 1) == 0) {
        bVar11 = *local_200;
      }
      else {
        while (bVar11 = *local_200, bVar11 == 0x2e) {
          bVar11 = local_200[1];
          if (((byte)(bVar11 + 0x9f) < 0x1a) || (bVar11 == 0x5f)) {
            bVar11 = local_200[2];
            pbVar9 = local_200 + 2;
            if (0x19 < (byte)(bVar11 + 0x9f)) goto LAB_00c8407f;
            do {
              do {
                pbVar9 = pbVar9 + 1;
                bVar11 = *pbVar9;
              } while ((byte)(bVar11 + 0x9f) < 0x1a);
LAB_00c8407f:
            } while (bVar11 == 0x5f);
          }
          else {
            if (9 < (byte)(bVar11 - 0x30)) {
              bVar11 = *local_200;
              break;
            }
            bVar11 = *local_200;
            pbVar9 = local_200;
          }
          while ((bVar11 == 0x2e && ((byte)(pbVar9[1] - 0x30) < 10))) {
            pbVar13 = pbVar9 + 2;
            pbVar9 = pbVar9 + 2;
            bVar11 = *pbVar13;
            while ((byte)(bVar11 - 0x30) < 10) {
              pbVar9 = pbVar9 + 1;
              bVar11 = *pbVar9;
            }
          }
          iVar5 = (int)pbVar9 - (int)local_200;
          if (local_1f0 < local_1ec) {
            lVar12 = (long)local_1f0;
            local_1f0 = local_1f0 + 1;
            puVar10 = (undefined8 *)(local_1f8 + lVar12 * 0x18);
            *(undefined4 *)((long)puVar10 + 4) = 0;
            if (iVar5 == 0) goto LAB_00c84058;
            *puVar10 = 0;
            puVar10[1] = local_200;
            *(int *)(puVar10 + 2) = iVar5;
          }
          else {
LAB_00c84058:
            puVar10 = (undefined8 *)0x0;
          }
          local_200 = pbVar9;
          *(undefined8 *)((long)&uStack_240 + lVar2 + lVar8) = 0xc83fd4;
          lVar7 = FUN_00c7a6a0(&local_218,0x4d,lVar7,puVar10);
        }
      }
      goto joined_r0x00c83d4c;
    }
  }
  else {
    if ((bVar14 == 0) || (3 < bVar14)) {
      local_1e8 = (undefined1 *)((long)&local_238 + lVar2 + lVar8);
      *(undefined8 *)((long)&uStack_240 + lVar2 + lVar8) = 0xc83d3c;
      lVar7 = demangle_parse_type(&local_218);
      bVar11 = *local_200;
    }
    else {
      pbVar9 = param_1 + 0xb;
      if ((param_1[0xb] == 0x5f) && (param_1[0xc] == 0x5a)) {
        local_200 = param_1 + 0xd;
        local_1e8 = (undefined1 *)((long)&local_238 + lVar2 + lVar8);
        *(undefined8 *)((long)&uStack_240 + lVar2 + lVar8) = 0xc83f2e;
        lVar7 = FUN_00c7d680(&local_218,0);
      }
      else {
        local_238 = local_1f8;
        local_22c = local_1ec;
        local_228 = pbVar9;
        local_200 = pbVar9;
        *(undefined8 *)((long)&uStack_240 + lVar2 + lVar8) = 0xc83c8a;
        sVar6 = strlen((char *)pbVar9);
        if (0 < local_22c) {
          *(undefined4 *)(uVar15 * 8 + 4) = 0;
          local_1f0 = 1;
          if ((int)sVar6 != 0) {
            *(byte **)(uVar15 * 8 + 8) = local_228;
            *(undefined4 *)(uVar15 * 8) = 0;
            *(int *)(uVar15 * 8 + 0x10) = (int)sVar6;
            lVar7 = local_238;
            goto LAB_00c83ce7;
          }
        }
        lVar7 = 0;
      }
LAB_00c83ce7:
      *(undefined8 *)((long)&uStack_240 + lVar2 + lVar8) = 0xc83cfe;
      lVar7 = FUN_00c7a6a0(&local_218,(bVar14 != 2) + 'C',lVar7,0);
      pbVar9 = local_200;
      *(undefined8 *)((long)&uStack_240 + lVar2 + lVar8) = 0xc83d10;
      sVar6 = strlen((char *)pbVar9);
      local_200 = pbVar9 + sVar6;
      bVar11 = *local_200;
    }
joined_r0x00c83d4c:
    if ((lVar7 != 0) && (bVar11 == 0)) {
      local_b8 = 0;
      local_b0 = 0;
      local_98 = 0;
      local_90 = 0;
      local_88 = 0;
      local_80 = 0;
      local_78 = 0;
      local_70 = 0;
      local_68 = (undefined1 *)0x0;
      local_60 = 0;
      local_58 = (undefined1 *)0x0;
      local_50 = 0;
      local_a8 = param_2;
      local_a0 = local_220;
      *(undefined8 *)((long)&uStack_240 + lVar2 + lVar8) = 0xc83df1;
      FUN_00c7a770((long)&local_50 + 4,(long)&local_60 + 4,lVar7);
      lVar12 = (long)local_60._4_4_;
      local_48 = 0;
      iVar5 = local_50._4_4_ * local_60._4_4_;
      if (local_60._4_4_ < 1) {
        lVar12 = 1;
      }
      local_50 = CONCAT44(iVar5,(undefined4)local_50);
      lVar12 = lVar12 * -0x10;
      local_68 = (undefined1 *)((long)&local_238 + lVar12 + lVar2 + lVar8);
      if (iVar5 < 1) {
        iVar5 = 1;
      }
      local_58 = (undefined1 *)((long)&local_238 + (long)iVar5 * -0x10 + lVar12 + lVar2 + lVar8);
      *(undefined8 *)((long)&uStack_240 + (long)iVar5 * -0x10 + lVar12 + lVar2 + lVar8) = 0xc83e41;
      demangle_recurse_guard(local_1b8,0x11,lVar7);
      uVar4 = local_a0;
      lVar7 = local_b8;
      local_1b8[local_b8] = 0;
      pcVar3 = local_a8;
      *(undefined8 *)((long)&uStack_240 + lVar2 + lVar8) = 0xc83e63;
      (*pcVar3)(local_1b8,lVar7,uVar4);
      bVar17 = (int)local_88 == 0;
      goto LAB_00c83e6d;
    }
  }
  bVar17 = false;
LAB_00c83e6d:
  if (local_40 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    *(undefined **)((long)&uStack_240 + lVar2 + lVar8) = &UNK_00c84093;
    __stack_chk_fail();
  }
  return bVar17;
}


// ==== entry=00c840a0 orig=FUN_00c840a0 size=369 name=__cxa_demangle ====

char * __cxa_demangle(long param_1,char *param_2,ulong *param_3,undefined4 *param_4)

{
  int iVar1;
  size_t sVar2;
  char *__src;
  ulong uVar3;
  long in_FS_OFFSET;
  char *local_58;
  undefined8 local_50;
  ulong local_48;
  int local_40;
  long local_30;
  
  local_30 = *(long *)(in_FS_OFFSET + 0x28);
  if ((param_1 == 0) || ((param_2 != (char *)0x0 && (param_3 == (ulong *)0x0)))) {
    if (param_4 != (undefined4 *)0x0) {
      *param_4 = 0xfffffffd;
    }
  }
  else {
    local_58 = (char *)0x0;
    local_50 = 0;
    local_48 = 0;
    local_40 = 0;
    iVar1 = demangle_global_prefix(param_1,FUN_00c7b090,&local_58);
    __src = local_58;
    if (iVar1 != 0) {
      if (local_40 == 0) {
        uVar3 = local_48;
        if (local_58 == (char *)0x0) {
          if (param_4 != (undefined4 *)0x0) {
            if (local_48 != 1) goto LAB_00c84216;
            goto LAB_00c841b5;
          }
          goto LAB_00c841d5;
        }
      }
      else {
        uVar3 = 1;
        if (local_58 == (char *)0x0) {
          if (param_4 == (undefined4 *)0x0) {
            __src = (char *)0x0;
            goto LAB_00c84172;
          }
LAB_00c841b5:
          *param_4 = 0xffffffff;
          __src = (char *)0x0;
          goto LAB_00c84172;
        }
      }
      if (param_2 == (char *)0x0) {
        if (param_3 != (ulong *)0x0) goto LAB_00c841e8;
      }
      else {
        sVar2 = strlen(local_58);
        if (sVar2 < *param_3) {
          memcpy(param_2,__src,sVar2 + 1);
          free(__src);
          __src = param_2;
        }
        else {
          free(param_2);
LAB_00c841e8:
          *param_3 = uVar3;
        }
      }
      if (param_4 != (undefined4 *)0x0) {
        *param_4 = 0;
      }
      goto LAB_00c84172;
    }
    free(local_58);
    if (param_4 != (undefined4 *)0x0) {
LAB_00c84216:
      *param_4 = 0xfffffffe;
      __src = (char *)0x0;
      goto LAB_00c84172;
    }
  }
LAB_00c841d5:
  __src = (char *)0x0;
LAB_00c84172:
  if (local_30 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return __src;
}


// ==== entry=00c84240 name=FUN_00c84240 size=38 ====

uint FUN_00c84240(long param_1,long param_2)

{
  int iVar1;
  
  if ((param_1 != 0) && (param_2 != 0)) {
    iVar1 = demangle_global_prefix();
    return -(uint)(iVar1 == 0) & 0xfffffffe;
  }
  return 0xfffffffd;
}


// ==== entry=00c84270 orig=FUN_00c84270 size=38 name=__cxa_current_exception_type ====

long __cxa_current_exception_type(void)

{
  long *plVar1;
  long lVar2;
  
  plVar1 = (long *)__cxa_get_globals();
  plVar1 = (long *)*plVar1;
  lVar2 = 0;
  if ((plVar1 != (long *)0x0) && (lVar2 = *plVar1, (plVar1[10] & 1U) != 0)) {
    lVar2 = *(long *)(lVar2 + -0x70);
  }
  return lVar2;
}


// ==== entry=00c842a0 name=FUN_00c842a0 size=90 ====

ulong FUN_00c842a0(ulong param_1)

{
  ulong uVar1;
  
  param_1 = param_1 - (param_1 >> 1 & 0x5555555555555555);
  uVar1 = (param_1 >> 2 & 0x3333333333333333) + (param_1 & 0x3333333333333333);
  return ((uVar1 >> 4) + uVar1 & 0xf0f0f0f0f0f0f0f) * 0x101010101010101 >> 0x38;
}


// ==== entry=00c84300 name=FUN_00c84300 size=225 ====

undefined1  [16] FUN_00c84300(ulong param_1,ulong param_2,ulong param_3,ulong param_4)

{
  undefined1 auVar1 [16];
  undefined1 auVar2 [16];
  undefined1 auVar3 [16];
  undefined1 auVar4 [16];
  undefined1 auVar5 [16];
  undefined1 auVar6 [16];
  undefined1 auVar7 [16];
  undefined1 auVar8 [16];
  byte bVar9;
  byte bVar10;
  ulong uVar11;
  ulong uVar12;
  undefined1 auVar13 [16];
  undefined1 auVar14 [16];
  undefined1 auVar15 [16];
  undefined1 auVar16 [16];
  
  if (param_4 == 0) {
    if (param_3 <= param_2) {
      if (param_3 == 0) {
        param_3 = SUB168((ZEXT816(0) << 0x40 | ZEXT816(1)) / ZEXT816(0),0);
      }
      auVar2._8_8_ = 0;
      auVar2._0_8_ = param_3;
      auVar5._8_8_ = param_2 % param_3;
      auVar5._0_8_ = param_1;
      auVar14._0_8_ = SUB168(auVar5 / auVar2,0);
      auVar14._8_8_ = param_2 / param_3;
      return auVar14;
    }
    auVar1._8_8_ = 0;
    auVar1._0_8_ = param_3;
    auVar4._8_8_ = param_2;
    auVar4._0_8_ = param_1;
    uVar11 = SUB168(auVar4 / auVar1,0);
  }
  else {
    if (param_2 < param_4) {
      return ZEXT816(0);
    }
    uVar11 = 0x3f;
    if (param_4 != 0) {
      for (; param_4 >> uVar11 == 0; uVar11 = uVar11 - 1) {
      }
    }
    bVar10 = (byte)(uVar11 ^ 0x3f);
    if ((int)(uVar11 ^ 0x3f) != 0) {
      bVar9 = 0x40 - bVar10;
      auVar3._8_8_ = 0;
      auVar3._0_8_ = param_3 >> (bVar9 & 0x3f) | param_4 << (bVar10 & 0x3f);
      auVar6._8_8_ = param_2 >> (bVar9 & 0x3f);
      auVar6._0_8_ = param_1 >> (bVar9 & 0x3f) | param_2 << (bVar10 & 0x3f);
      auVar15._0_8_ = SUB168(auVar6 / auVar3,0);
      uVar11 = SUB168(auVar6 % auVar3,0);
      auVar7._8_8_ = 0;
      auVar7._0_8_ = auVar15._0_8_;
      auVar8._8_8_ = 0;
      auVar8._0_8_ = param_3 << (bVar10 & 0x3f);
      uVar12 = SUB168(auVar7 * auVar8,8);
      if ((uVar12 <= uVar11) &&
         ((SUB168(auVar7 * auVar8,0) <= param_1 << (bVar10 & 0x3f) || (uVar11 != uVar12)))) {
        auVar15._8_8_ = 0;
        return auVar15;
      }
      auVar16._8_8_ = 0;
      auVar16._0_8_ = auVar15._0_8_ - 1;
      return auVar16;
    }
    if ((param_4 < param_2) || (uVar11 = 0, param_3 <= param_1)) {
      return ZEXT816(1);
    }
  }
  auVar13._8_8_ = 0;
  auVar13._0_8_ = uVar11;
  return auVar13;
}


// ==== entry=00c84400 name=FUN_00c84400 size=264 ====

/* WARNING: Removing unreachable block (ram,0x00c844d7) */

undefined1  [16] FUN_00c84400(ulong param_1,ulong param_2,ulong param_3,ulong param_4)

{
  undefined1 auVar1 [16];
  undefined1 auVar2 [16];
  undefined1 auVar3 [16];
  undefined1 auVar4 [16];
  undefined1 auVar5 [16];
  undefined1 auVar6 [16];
  undefined1 auVar7 [16];
  undefined1 auVar8 [16];
  byte bVar9;
  byte bVar10;
  undefined1 auVar11 [16];
  undefined1 auVar12 [16];
  long lVar13;
  ulong uVar14;
  ulong uVar15;
  ulong uVar16;
  undefined1 auVar17 [16];
  undefined1 auVar18 [16];
  undefined1 auVar19 [16];
  undefined1 auVar20 [16];
  
  if (param_4 == 0) {
    if (param_2 < param_3) {
      auVar1._8_8_ = 0;
      auVar1._0_8_ = param_3;
      auVar4._8_8_ = param_2;
      auVar4._0_8_ = param_1;
      param_1 = SUB168(auVar4 % auVar1,0);
      param_2 = 0;
    }
    else {
      if (param_3 == 0) {
        param_3 = SUB168((ZEXT816(0) << 0x40 | ZEXT816(1)) / ZEXT816(0),0);
      }
      auVar2._8_8_ = 0;
      auVar2._0_8_ = param_3;
      auVar5._8_8_ = param_2 % param_3;
      auVar5._0_8_ = param_1;
      param_1 = SUB168(auVar5 % auVar2,0);
      param_2 = 0;
    }
  }
  else if (param_4 <= param_2) {
    uVar14 = 0x3f;
    if (param_4 != 0) {
      for (; param_4 >> uVar14 == 0; uVar14 = uVar14 - 1) {
      }
    }
    if ((int)(uVar14 ^ 0x3f) == 0) {
      if ((param_2 <= param_4) && (param_1 < param_3)) {
        auVar18._8_8_ = param_2;
        auVar18._0_8_ = param_1;
        return auVar18;
      }
      auVar20._0_8_ = param_1 - param_3;
      auVar20._8_8_ = (param_2 - param_4) - (ulong)(param_1 < param_3);
      return auVar20;
    }
    bVar9 = (byte)(uVar14 ^ 0x3f);
    bVar10 = 0x40 - bVar9;
    uVar15 = param_3 << (bVar9 & 0x3f);
    uVar16 = param_4 << (bVar9 & 0x3f) | param_3 >> (bVar10 & 0x3f);
    auVar11._8_8_ = uVar16;
    auVar11._0_8_ = uVar15;
    uVar14 = param_1 << (bVar9 & 0x3f);
    auVar3._8_8_ = 0;
    auVar3._0_8_ = uVar16;
    auVar6._8_8_ = param_2 >> (bVar10 & 0x3f);
    auVar6._0_8_ = param_1 >> (bVar10 & 0x3f) | param_2 << (bVar9 & 0x3f);
    lVar13 = SUB168(auVar6 % auVar3,0);
    auVar12._8_8_ = lVar13;
    auVar12._0_8_ = uVar14;
    auVar7._8_8_ = 0;
    auVar7._0_8_ = SUB168(auVar6 / auVar3,0);
    auVar8._8_8_ = 0;
    auVar8._0_8_ = uVar15;
    auVar7 = auVar7 * auVar8;
    if (auVar12 < auVar7) {
      auVar7 = auVar7 - auVar11;
    }
    uVar15 = (lVar13 - auVar7._8_8_) - (ulong)(uVar14 < auVar7._0_8_);
    auVar19._0_8_ = uVar15 << (bVar10 & 0x3f) | uVar14 - auVar7._0_8_ >> (bVar9 & 0x3f);
    auVar19._8_8_ = uVar15 >> (bVar9 & 0x3f);
    return auVar19;
  }
  auVar17._8_8_ = param_2;
  auVar17._0_8_ = param_1;
  return auVar17;
}


// ==== entry=00c84520 name=FUN_00c84520 size=289 ====

ulong * FUN_00c84520(byte param_1,ulong *param_2,ulong *param_3,undefined8 *param_4)

{
  ulong uVar1;
  undefined8 *puVar2;
  ulong *puVar3;
  byte bVar5;
  byte bVar6;
  uint uVar7;
  byte *pbVar8;
  ulong uVar9;
  ulong *puVar4;
  
  if (param_1 == 0x50) {
    puVar2 = (undefined8 *)((ulong)((long)param_3 + 7U) & 0xfffffffffffffff8);
    *param_4 = *puVar2;
    return puVar2 + 1;
  }
  switch(param_1 & 0xf) {
  case 0:
  case 4:
  case 0xc:
    uVar9 = *param_3;
    puVar3 = param_3 + 1;
    break;
  case 1:
    uVar9 = 0;
    bVar5 = 0;
    puVar4 = param_3;
    do {
      puVar3 = (ulong *)((long)puVar4 + 1);
      uVar1 = *puVar4;
      bVar6 = bVar5 & 0x3f;
      bVar5 = bVar5 + 7;
      uVar9 = uVar9 | (ulong)((byte)uVar1 & 0x7f) << bVar6;
      puVar4 = puVar3;
    } while ((char)(byte)uVar1 < '\0');
    break;
  case 2:
    uVar9 = (ulong)(ushort)*param_3;
    puVar3 = (ulong *)((long)param_3 + 2);
    break;
  case 3:
    uVar9 = (ulong)(uint)*param_3;
    puVar3 = (ulong *)((long)param_3 + 4);
    break;
  default:
                    /* WARNING: Subroutine does not return */
    abort();
  case 9:
    uVar9 = 0;
    uVar7 = 0;
    puVar4 = param_3;
    do {
      puVar3 = (ulong *)((long)puVar4 + 1);
      bVar5 = (byte)*puVar4;
      bVar6 = (byte)uVar7;
      uVar7 = uVar7 + 7;
      uVar9 = uVar9 | (ulong)(bVar5 & 0x7f) << (bVar6 & 0x3f);
      puVar4 = puVar3;
    } while ((char)bVar5 < '\0');
    if ((0x3f < uVar7) || ((bVar5 & 0x40) == 0)) break;
    uVar9 = uVar9 | -1L << ((byte)uVar7 & 0x3f);
    goto LAB_00c8455c;
  case 10:
    uVar9 = (ulong)(short)(ushort)*param_3;
    puVar3 = (ulong *)((long)param_3 + 2);
    break;
  case 0xb:
    uVar9 = (ulong)(int)(uint)*param_3;
    puVar3 = (ulong *)((long)param_3 + 4);
  }
  pbVar8 = (byte *)0x0;
  if (uVar9 != 0) {
LAB_00c8455c:
    if ((param_1 & 0x70) == 0x10) {
      param_2 = param_3;
    }
    pbVar8 = (byte *)(uVar9 + (long)param_2);
    if ((char)param_1 < '\0') {
      *param_4 = *(undefined8 *)pbVar8;
      return puVar3;
    }
  }
  *param_4 = pbVar8;
  return puVar3;
}


// ==== entry=00c84670 name=FUN_00c84670 size=79 ====

undefined8 FUN_00c84670(byte param_1,long param_2)

{
  if (param_1 == 0xff) {
    return 0;
  }
  param_1 = param_1 & 0x70;
  if (param_1 == 0x20) {
    return *(undefined8 *)(param_2 + 0xa8);
  }
  if (param_1 < 0x21) {
    if (param_1 == 0) {
      return 0;
    }
    if (param_1 == 0x10) {
      return 0;
    }
  }
  else {
    if (param_1 == 0x40) {
      return *(undefined8 *)(param_2 + 0xb8);
    }
    if (param_1 == 0x50) {
      return 0;
    }
    if (param_1 == 0x30) {
      return *(undefined8 *)(param_2 + 0xb0);
    }
  }
                    /* WARNING: Subroutine does not return */
  abort();
}


// ==== entry=00c846d0 name=FUN_00c846d0 size=2240 ====

void FUN_00c846d0(byte *param_1,byte *param_2,long param_3,undefined8 *param_4)

{
  byte bVar1;
  uint uVar2;
  undefined8 uVar3;
  undefined8 *puVar4;
  byte bVar5;
  byte bVar6;
  long lVar7;
  ulong uVar8;
  byte *pbVar9;
  undefined1 *puVar10;
  undefined1 *puVar11;
  undefined8 *puVar12;
  byte *pbVar13;
  undefined8 *puVar14;
  ulong uVar15;
  undefined8 *puVar16;
  byte bVar17;
  undefined1 auStack_68 [8];
  undefined8 *local_60;
  uint local_54;
  undefined8 *local_50;
  undefined8 local_40 [2];
  
  bVar17 = 0;
  param_4[0x24] = 0;
  if (param_2 <= param_1) {
    return;
  }
  puVar10 = auStack_68;
  uVar8 = param_4[0x29];
  if (uVar8 < (ulong)(*(long *)(param_3 + 0x98) - (*(long *)(param_3 + 0xc0) >> 0x3f))) {
    local_50 = local_40;
    puVar16 = (undefined8 *)0x0;
    do {
      bVar6 = *param_1;
      pbVar13 = param_1 + 1;
      bVar5 = bVar6 & 0xc0;
      if (bVar5 == 0x40) {
        param_4[0x29] = (ulong)(bVar6 & 0x3f) * param_4[0x2c] + uVar8;
        goto LAB_00c84778;
      }
      if (bVar5 == 0x80) {
        uVar2 = bVar6 & 0x3f;
        bVar6 = 0;
        uVar8 = 0;
        pbVar9 = pbVar13;
        do {
          pbVar13 = pbVar9 + 1;
          bVar5 = *pbVar9;
          bVar1 = bVar6 & 0x3f;
          bVar6 = bVar6 + 7;
          uVar8 = uVar8 | (ulong)(bVar5 & 0x7f) << bVar1;
          pbVar9 = pbVar13;
        } while ((char)bVar5 < '\0');
        lVar7 = param_4[0x2b];
        if ((byte)uVar2 < 0x12) {
          *(undefined4 *)(param_4 + (ulong)uVar2 * 2 + 1) = 1;
          param_4[(ulong)uVar2 * 2] = uVar8 * lVar7;
        }
        goto LAB_00c84778;
      }
      if (bVar5 == 0xc0) {
        uVar2 = bVar6 & 0x3f;
        if (0x11 < (byte)uVar2) goto switchD_00c8476e_caseD_0;
        *(undefined4 *)(param_4 + (ulong)uVar2 * 2 + 1) = 0;
        goto LAB_00c84778;
      }
      switch(bVar6) {
      case 0:
      case 0x2d:
        goto switchD_00c8476e_caseD_0;
      case 1:
        bVar6 = *(byte *)(param_4 + 0x2e);
        local_54 = (uint)bVar6;
        *(undefined8 *)(puVar10 + -8) = 0xc8489c;
        local_60 = puVar16;
        uVar3 = FUN_00c84670(bVar6,param_3);
        *(undefined8 *)(puVar10 + -8) = 0xc848b2;
        pbVar13 = (byte *)FUN_00c84520(local_54,uVar3,pbVar13,local_50);
        param_4[0x29] = local_40[0];
        puVar16 = local_60;
        break;
      case 2:
        pbVar13 = param_1 + 2;
        param_4[0x29] = (ulong)param_1[1] * param_4[0x2c] + uVar8;
        break;
      case 3:
        pbVar13 = param_1 + 3;
        param_4[0x29] = (ulong)*(ushort *)(param_1 + 1) * param_4[0x2c] + uVar8;
        break;
      case 4:
        pbVar13 = param_1 + 5;
        param_4[0x29] = (ulong)*(uint *)(param_1 + 1) * param_4[0x2c] + uVar8;
        break;
      case 5:
        uVar8 = 0;
        bVar6 = 0;
        do {
          pbVar9 = pbVar13 + 1;
          bVar5 = *pbVar13;
          bVar1 = bVar6 & 0x3f;
          bVar6 = bVar6 + 7;
          uVar8 = uVar8 | (ulong)(bVar5 & 0x7f) << bVar1;
          pbVar13 = pbVar9;
        } while ((char)bVar5 < '\0');
        uVar15 = 0;
        bVar6 = 0;
        do {
          pbVar13 = pbVar9 + 1;
          bVar5 = *pbVar9;
          bVar1 = bVar6 & 0x3f;
          bVar6 = bVar6 + 7;
          uVar15 = uVar15 | (ulong)(bVar5 & 0x7f) << bVar1;
          pbVar9 = pbVar13;
        } while ((char)bVar5 < '\0');
        goto LAB_00c8499b;
      case 6:
        uVar8 = 0;
        bVar6 = 0;
        pbVar9 = pbVar13;
        do {
          pbVar13 = pbVar9 + 1;
          bVar5 = *pbVar9;
          bVar1 = bVar6 & 0x3f;
          bVar6 = bVar6 + 7;
          uVar8 = uVar8 | (ulong)(bVar5 & 0x7f) << bVar1;
          pbVar9 = pbVar13;
        } while ((char)bVar5 < '\0');
        goto LAB_00c849f3;
      case 7:
        uVar8 = 0;
        bVar6 = 0;
        pbVar9 = pbVar13;
        do {
          pbVar13 = pbVar9 + 1;
          bVar5 = *pbVar9;
          bVar1 = bVar6 & 0x3f;
          bVar6 = bVar6 + 7;
          uVar8 = uVar8 | (ulong)(bVar5 & 0x7f) << bVar1;
          pbVar9 = pbVar13;
        } while ((char)bVar5 < '\0');
        if (0x11 < uVar8) goto switchD_00c8476e_caseD_0;
        *(undefined4 *)(param_4 + uVar8 * 2 + 1) = 6;
        break;
      case 8:
        uVar8 = 0;
        bVar6 = 0;
        pbVar9 = pbVar13;
        do {
          pbVar13 = pbVar9 + 1;
          bVar5 = *pbVar9;
          bVar1 = bVar6 & 0x3f;
          bVar6 = bVar6 + 7;
          uVar8 = uVar8 | (ulong)(bVar5 & 0x7f) << bVar1;
          pbVar9 = pbVar13;
        } while ((char)bVar5 < '\0');
LAB_00c849f3:
        if (uVar8 < 0x12) {
          *(undefined4 *)(param_4 + uVar8 * 2 + 1) = 0;
          break;
        }
        goto switchD_00c8476e_caseD_0;
      case 9:
        uVar8 = 0;
        bVar6 = 0;
        do {
          pbVar9 = pbVar13 + 1;
          bVar5 = *pbVar13;
          bVar1 = bVar6 & 0x3f;
          bVar6 = bVar6 + 7;
          uVar8 = uVar8 | (ulong)(bVar5 & 0x7f) << bVar1;
          pbVar13 = pbVar9;
        } while ((char)bVar5 < '\0');
        uVar15 = 0;
        bVar6 = 0;
        do {
          pbVar13 = pbVar9 + 1;
          bVar5 = *pbVar9;
          bVar1 = bVar6 & 0x3f;
          bVar6 = bVar6 + 7;
          uVar15 = uVar15 | (ulong)(bVar5 & 0x7f) << bVar1;
          pbVar9 = pbVar13;
        } while ((char)bVar5 < '\0');
        if (0x11 < uVar8) goto switchD_00c8476e_caseD_0;
        param_4[uVar8 * 2] = uVar15;
        *(undefined4 *)(param_4 + uVar8 * 2 + 1) = 2;
        break;
      case 10:
        if (puVar16 == (undefined8 *)0x0) {
          puVar11 = puVar10 + -0x150;
          puVar4 = (undefined8 *)((ulong)(puVar10 + -0x141) & 0xfffffffffffffff0);
        }
        else {
          puVar4 = puVar16;
          puVar11 = puVar10;
          puVar16 = (undefined8 *)puVar16[0x24];
        }
        puVar12 = param_4;
        puVar14 = puVar4;
        for (lVar7 = 0x29; lVar7 != 0; lVar7 = lVar7 + -1) {
          *puVar14 = *puVar12;
          puVar12 = puVar12 + (ulong)bVar17 * -2 + 1;
          puVar14 = puVar14 + (ulong)bVar17 * -2 + 1;
        }
        param_4[0x24] = puVar4;
        puVar10 = puVar11;
        break;
      case 0xb:
        puVar4 = (undefined8 *)param_4[0x24];
        puVar12 = puVar4;
        puVar14 = param_4;
        for (lVar7 = 0x29; lVar7 != 0; lVar7 = lVar7 + -1) {
          *puVar14 = *puVar12;
          puVar12 = puVar12 + (ulong)bVar17 * -2 + 1;
          puVar14 = puVar14 + (ulong)bVar17 * -2 + 1;
        }
        puVar4[0x24] = puVar16;
        puVar16 = puVar4;
        break;
      case 0xc:
        uVar8 = 0;
        bVar6 = 0;
        do {
          pbVar9 = pbVar13 + 1;
          bVar5 = *pbVar13;
          bVar1 = bVar6 & 0x3f;
          bVar6 = bVar6 + 7;
          uVar8 = uVar8 | (ulong)(bVar5 & 0x7f) << bVar1;
          pbVar13 = pbVar9;
        } while ((char)bVar5 < '\0');
        param_4[0x26] = uVar8;
        bVar6 = 0;
        uVar8 = 0;
        do {
          pbVar13 = pbVar9 + 1;
          bVar5 = *pbVar9;
          bVar1 = bVar6 & 0x3f;
          bVar6 = bVar6 + 7;
          uVar8 = uVar8 | (ulong)(bVar5 & 0x7f) << bVar1;
          pbVar9 = pbVar13;
        } while ((char)bVar5 < '\0');
        param_4[0x25] = uVar8;
        *(undefined4 *)(param_4 + 0x28) = 1;
        break;
      case 0xd:
        uVar8 = 0;
        bVar6 = 0;
        pbVar9 = pbVar13;
        do {
          pbVar13 = pbVar9 + 1;
          bVar5 = *pbVar9;
          bVar1 = bVar6 & 0x3f;
          bVar6 = bVar6 + 7;
          uVar8 = uVar8 | (ulong)(bVar5 & 0x7f) << bVar1;
          pbVar9 = pbVar13;
        } while ((char)bVar5 < '\0');
        param_4[0x26] = uVar8;
        *(undefined4 *)(param_4 + 0x28) = 1;
        break;
      case 0xe:
        uVar8 = 0;
        bVar6 = 0;
        pbVar9 = pbVar13;
        do {
          pbVar13 = pbVar9 + 1;
          bVar5 = *pbVar9;
          bVar1 = bVar6 & 0x3f;
          bVar6 = bVar6 + 7;
          uVar8 = uVar8 | (ulong)(bVar5 & 0x7f) << bVar1;
          pbVar9 = pbVar13;
        } while ((char)bVar5 < '\0');
        param_4[0x25] = uVar8;
        break;
      case 0xf:
        param_4[0x27] = pbVar13;
        uVar8 = 0;
        bVar6 = 0;
        *(undefined4 *)(param_4 + 0x28) = 2;
        do {
          pbVar9 = pbVar13 + 1;
          bVar5 = *pbVar13;
          bVar1 = bVar6 & 0x3f;
          bVar6 = bVar6 + 7;
          uVar8 = uVar8 | (ulong)(bVar5 & 0x7f) << bVar1;
          pbVar13 = pbVar9;
        } while ((char)bVar5 < '\0');
        pbVar13 = pbVar9 + uVar8;
        break;
      case 0x10:
        uVar8 = 0;
        bVar6 = 0;
        do {
          pbVar9 = pbVar13 + 1;
          bVar5 = *pbVar13;
          bVar1 = bVar6 & 0x3f;
          bVar6 = bVar6 + 7;
          uVar8 = uVar8 | (ulong)(bVar5 & 0x7f) << bVar1;
          pbVar13 = pbVar9;
        } while ((char)bVar5 < '\0');
        if (uVar8 < 0x12) {
          *(undefined4 *)(param_4 + uVar8 * 2 + 1) = 3;
          param_4[uVar8 * 2] = pbVar9;
        }
        uVar8 = 0;
        bVar6 = 0;
        do {
          pbVar13 = pbVar9 + 1;
          bVar5 = *pbVar9;
          bVar1 = bVar6 & 0x3f;
          bVar6 = bVar6 + 7;
          uVar8 = uVar8 | (ulong)(bVar5 & 0x7f) << bVar1;
          pbVar9 = pbVar13;
        } while ((char)bVar5 < '\0');
        pbVar13 = pbVar13 + uVar8;
        break;
      case 0x11:
        uVar8 = 0;
        bVar6 = 0;
        do {
          pbVar9 = pbVar13 + 1;
          bVar5 = *pbVar13;
          bVar1 = bVar6 & 0x3f;
          bVar6 = bVar6 + 7;
          uVar8 = uVar8 | (ulong)(bVar5 & 0x7f) << bVar1;
          pbVar13 = pbVar9;
        } while ((char)bVar5 < '\0');
        uVar15 = 0;
        uVar2 = 0;
        do {
          pbVar13 = pbVar9 + 1;
          bVar6 = *pbVar9;
          bVar5 = (byte)uVar2;
          uVar2 = uVar2 + 7;
          uVar15 = uVar15 | (ulong)(bVar6 & 0x7f) << (bVar5 & 0x3f);
          pbVar9 = pbVar13;
        } while ((char)bVar6 < '\0');
        if ((uVar2 < 0x40) && ((bVar6 & 0x40) != 0)) {
          uVar15 = uVar15 | -(1L << ((byte)uVar2 & 0x3f));
        }
LAB_00c8499b:
        if (uVar8 < 0x12) {
          param_4[uVar8 * 2] = uVar15 * param_4[0x2b];
          *(undefined4 *)(param_4 + uVar8 * 2 + 1) = 1;
        }
        else {
switchD_00c8476e_caseD_0:
        }
        break;
      case 0x12:
        uVar8 = 0;
        bVar6 = 0;
        do {
          pbVar9 = pbVar13 + 1;
          bVar5 = *pbVar13;
          bVar1 = bVar6 & 0x3f;
          bVar6 = bVar6 + 7;
          uVar8 = uVar8 | (ulong)(bVar5 & 0x7f) << bVar1;
          pbVar13 = pbVar9;
        } while ((char)bVar5 < '\0');
        param_4[0x26] = uVar8;
        uVar2 = 0;
        uVar8 = 0;
        do {
          pbVar13 = pbVar9 + 1;
          bVar6 = *pbVar9;
          bVar5 = (byte)uVar2;
          uVar2 = uVar2 + 7;
          uVar8 = uVar8 | (ulong)(bVar6 & 0x7f) << (bVar5 & 0x3f);
          pbVar9 = pbVar13;
        } while ((char)bVar6 < '\0');
        if ((uVar2 < 0x40) && ((bVar6 & 0x40) != 0)) {
          uVar8 = uVar8 | -(1L << ((byte)uVar2 & 0x3f));
        }
        *(undefined4 *)(param_4 + 0x28) = 1;
        param_4[0x25] = uVar8 * param_4[0x2b];
        break;
      case 0x13:
        uVar8 = 0;
        uVar2 = 0;
        pbVar9 = pbVar13;
        do {
          pbVar13 = pbVar9 + 1;
          bVar6 = *pbVar9;
          bVar5 = (byte)uVar2;
          uVar2 = uVar2 + 7;
          uVar8 = uVar8 | (ulong)(bVar6 & 0x7f) << (bVar5 & 0x3f);
          pbVar9 = pbVar13;
        } while ((char)bVar6 < '\0');
        if ((uVar2 < 0x40) && ((bVar6 & 0x40) != 0)) {
          uVar8 = uVar8 | -(1L << ((byte)uVar2 & 0x3f));
        }
        param_4[0x25] = uVar8 * param_4[0x2b];
        break;
      case 0x14:
        uVar8 = 0;
        bVar6 = 0;
        do {
          pbVar9 = pbVar13 + 1;
          bVar5 = *pbVar13;
          bVar1 = bVar6 & 0x3f;
          bVar6 = bVar6 + 7;
          uVar8 = uVar8 | (ulong)(bVar5 & 0x7f) << bVar1;
          pbVar13 = pbVar9;
        } while ((char)bVar5 < '\0');
        uVar15 = 0;
        bVar6 = 0;
        do {
          pbVar13 = pbVar9 + 1;
          bVar5 = *pbVar9;
          bVar1 = bVar6 & 0x3f;
          bVar6 = bVar6 + 7;
          uVar15 = uVar15 | (ulong)(bVar5 & 0x7f) << bVar1;
          pbVar9 = pbVar13;
        } while ((char)bVar5 < '\0');
        goto LAB_00c84e8b;
      case 0x15:
        uVar8 = 0;
        bVar6 = 0;
        do {
          pbVar9 = pbVar13 + 1;
          bVar5 = *pbVar13;
          bVar1 = bVar6 & 0x3f;
          bVar6 = bVar6 + 7;
          uVar8 = uVar8 | (ulong)(bVar5 & 0x7f) << bVar1;
          pbVar13 = pbVar9;
        } while ((char)bVar5 < '\0');
        uVar15 = 0;
        uVar2 = 0;
        do {
          pbVar13 = pbVar9 + 1;
          bVar6 = *pbVar9;
          bVar5 = (byte)uVar2;
          uVar2 = uVar2 + 7;
          uVar15 = uVar15 | (ulong)(bVar6 & 0x7f) << (bVar5 & 0x3f);
          pbVar9 = pbVar13;
        } while ((char)bVar6 < '\0');
        if ((uVar2 < 0x40) && ((bVar6 & 0x40) != 0)) {
          uVar15 = uVar15 | -(1L << ((byte)uVar2 & 0x3f));
        }
LAB_00c84e8b:
        if (uVar8 < 0x12) {
          param_4[uVar8 * 2] = uVar15 * param_4[0x2b];
          *(undefined4 *)(param_4 + uVar8 * 2 + 1) = 4;
          break;
        }
        goto switchD_00c8476e_caseD_0;
      case 0x16:
        uVar8 = 0;
        bVar6 = 0;
        do {
          pbVar9 = pbVar13 + 1;
          bVar5 = *pbVar13;
          bVar1 = bVar6 & 0x3f;
          bVar6 = bVar6 + 7;
          uVar8 = uVar8 | (ulong)(bVar5 & 0x7f) << bVar1;
          pbVar13 = pbVar9;
        } while ((char)bVar5 < '\0');
        if (uVar8 < 0x12) {
          *(undefined4 *)(param_4 + uVar8 * 2 + 1) = 5;
          param_4[uVar8 * 2] = pbVar9;
        }
        uVar8 = 0;
        bVar6 = 0;
        do {
          pbVar13 = pbVar9 + 1;
          bVar5 = *pbVar9;
          bVar1 = bVar6 & 0x3f;
          bVar6 = bVar6 + 7;
          uVar8 = uVar8 | (ulong)(bVar5 & 0x7f) << bVar1;
          pbVar9 = pbVar13;
        } while ((char)bVar5 < '\0');
        pbVar13 = pbVar13 + uVar8;
        break;
      default:
                    /* WARNING: Subroutine does not return */
        *(code **)(puVar10 + -8) = abort;
        abort();
      case 0x2e:
        uVar8 = 0;
        bVar6 = 0;
        pbVar9 = pbVar13;
        do {
          pbVar13 = pbVar9 + 1;
          bVar5 = *pbVar9;
          bVar1 = bVar6 & 0x3f;
          bVar6 = bVar6 + 7;
          uVar8 = uVar8 | (ulong)(bVar5 & 0x7f) << bVar1;
          pbVar9 = pbVar13;
        } while ((char)bVar5 < '\0');
        *(ulong *)(param_3 + 0xd0) = uVar8;
        break;
      case 0x2f:
        uVar8 = 0;
        bVar6 = 0;
        do {
          pbVar9 = pbVar13 + 1;
          bVar5 = *pbVar13;
          bVar1 = bVar6 & 0x3f;
          bVar6 = bVar6 + 7;
          uVar8 = uVar8 | (ulong)(bVar5 & 0x7f) << bVar1;
          pbVar13 = pbVar9;
        } while ((char)bVar5 < '\0');
        uVar15 = 0;
        bVar6 = 0;
        do {
          pbVar13 = pbVar9 + 1;
          bVar5 = *pbVar9;
          bVar1 = bVar6 & 0x3f;
          bVar6 = bVar6 + 7;
          uVar15 = uVar15 | (ulong)(bVar5 & 0x7f) << bVar1;
          pbVar9 = pbVar13;
        } while ((char)bVar5 < '\0');
        if (0x11 < uVar8) goto switchD_00c8476e_caseD_0;
        param_4[uVar8 * 2] = -(uVar15 * param_4[0x2b]);
        *(undefined4 *)(param_4 + uVar8 * 2 + 1) = 1;
      }
LAB_00c84778:
    } while ((pbVar13 < param_2) &&
            (uVar8 = param_4[0x29], param_1 = pbVar13,
            uVar8 < (ulong)(*(long *)(param_3 + 0x98) - (*(long *)(param_3 + 0xc0) >> 0x3f))));
  }
  return;
}


// ==== entry=00c85020 name=FUN_00c85020 size=120 ====

void FUN_00c85020(void)

{
  DAT_011c6730 = 8;
  DAT_011c6731 = 8;
  DAT_011c6732 = 8;
  DAT_011c6733 = 8;
  DAT_011c6734 = 8;
  DAT_011c6735 = 8;
  DAT_011c6736 = 8;
  DAT_011c6737 = 8;
  DAT_011c6738 = 8;
  DAT_011c6739 = 8;
  DAT_011c673a = 8;
  DAT_011c673b = 8;
  DAT_011c673c = 8;
  DAT_011c673d = 8;
  DAT_011c673e = 8;
  DAT_011c673f = 8;
  DAT_011c6740 = 8;
  return;
}


// ==== entry=00c850a0 name=FUN_00c850a0 size=1488 ====

undefined8 FUN_00c850a0(long param_1,long *param_2)

{
  long lVar1;
  byte bVar2;
  uint uVar3;
  char cVar4;
  byte bVar5;
  uint *puVar6;
  size_t sVar7;
  byte *pbVar8;
  undefined8 uVar9;
  byte bVar10;
  uint uVar11;
  long lVar12;
  byte *pbVar13;
  long *plVar14;
  byte *pbVar15;
  ulong uVar16;
  char *__s;
  uint *puVar17;
  long local_40 [2];
  
  plVar14 = param_2;
  for (lVar12 = 0x30; lVar12 != 0; lVar12 = lVar12 + -1) {
    *plVar14 = 0;
    plVar14 = plVar14 + 1;
  }
  *(undefined8 *)(param_1 + 0xd0) = 0;
  *(undefined8 *)(param_1 + 0xa0) = 0;
  if (*(long *)(param_1 + 0x98) == 0) {
    return 5;
  }
  puVar6 = (uint *)FUN_00c88cf0((*(long *)(param_1 + 0x98) + -1) -
                                (*(long *)(param_1 + 0xc0) >> 0x3f),param_1 + 0xa8);
  if (puVar6 == (uint *)0x0) {
    if (**(char **)(param_1 + 0x98) != 'H') {
      return 5;
    }
    if (*(long *)(*(char **)(param_1 + 0x98) + 1) == 0x50f0000000fc0c7) {
      lVar12 = *(long *)(param_1 + 0x90);
      lVar1 = *(long *)(lVar12 + 0xa0);
      *(undefined4 *)(param_2 + 0x28) = 1;
      param_2[0x26] = 7;
      *(undefined4 *)(param_2 + 1) = 1;
      *param_2 = (lVar12 + 0x90) - lVar1;
      param_2[0x25] = lVar1 - lVar12;
      param_2[2] = (lVar12 + 0x88) - lVar1;
      param_2[0x10] = (lVar12 + 0x28) - lVar1;
      param_2[4] = (lVar12 + 0x98) - lVar1;
      param_2[0x12] = (lVar12 + 0x30) - lVar1;
      param_2[6] = (lVar12 + 0x80) - lVar1;
      param_2[0x14] = (lVar12 + 0x38) - lVar1;
      param_2[8] = (lVar12 + 0x70) - lVar1;
      param_2[0x16] = (lVar12 + 0x40) - lVar1;
      param_2[10] = (lVar12 + 0x68) - lVar1;
      param_2[0x18] = (lVar12 + 0x48) - lVar1;
      *(undefined4 *)(param_2 + 3) = 1;
      param_2[0x1a] = (lVar12 + 0x50) - lVar1;
      *(undefined4 *)(param_2 + 5) = 1;
      *(undefined4 *)(param_2 + 7) = 1;
      *(undefined4 *)(param_2 + 9) = 1;
      *(undefined4 *)(param_2 + 0xb) = 1;
      *(undefined4 *)(param_2 + 0xd) = 1;
      param_2[0xc] = (lVar12 + 0x78) - lVar1;
      *(undefined4 *)(param_2 + 0x11) = 1;
      *(undefined4 *)(param_2 + 0x13) = 1;
      *(undefined4 *)(param_2 + 0x15) = 1;
      *(undefined4 *)(param_2 + 0x17) = 1;
      *(undefined4 *)(param_2 + 0x19) = 1;
      *(undefined4 *)(param_2 + 0x1b) = 1;
      *(undefined4 *)(param_2 + 0x1d) = 1;
      param_2[0x1c] = (lVar12 + 0x58) - lVar1;
      *(undefined4 *)(param_2 + 0x1f) = 1;
      param_2[0x20] = (lVar12 + 0xa8) - lVar1;
      param_2[0x1e] = (lVar12 + 0x60) - lVar1;
      *(undefined4 *)(param_2 + 0x21) = 1;
      param_2[0x2d] = 0x10;
      *(undefined1 *)((long)param_2 + 0x173) = 1;
      return 0;
    }
    return 5;
  }
  param_2[0x29] = *(long *)(param_1 + 0xb8);
  puVar17 = (uint *)((long)puVar6 + (4 - (long)(int)puVar6[1]));
  __s = (char *)((long)puVar17 + 9);
  sVar7 = strlen(__s);
  pbVar8 = (byte *)((long)puVar17 + sVar7 + 10);
  if ((*(char *)((long)puVar17 + 9) == 'e') && (*(char *)((long)puVar17 + 10) == 'h')) {
    lVar12 = *(long *)pbVar8;
    __s = (char *)((long)puVar17 + 0xb);
    pbVar8 = pbVar8 + 8;
    param_2[0x2f] = lVar12;
  }
  uVar3 = puVar17[2];
  bVar5 = *pbVar8;
  if (3 < (byte)uVar3) {
    if (bVar5 != 8) {
      return 3;
    }
    if (pbVar8[1] != 0) {
      return 3;
    }
    bVar5 = pbVar8[2];
    pbVar8 = pbVar8 + 2;
  }
  uVar16 = 0;
  bVar10 = 0;
  while( true ) {
    pbVar8 = pbVar8 + 1;
    bVar2 = bVar10 & 0x3f;
    bVar10 = bVar10 + 7;
    uVar16 = uVar16 | (ulong)(bVar5 & 0x7f) << bVar2;
    if (-1 < (char)bVar5) break;
    bVar5 = *pbVar8;
  }
  param_2[0x2c] = uVar16;
  uVar11 = 0;
  uVar16 = 0;
  do {
    pbVar13 = pbVar8;
    pbVar8 = pbVar13 + 1;
    bVar5 = *pbVar13;
    bVar10 = (byte)uVar11;
    uVar11 = uVar11 + 7;
    uVar16 = uVar16 | (ulong)(bVar5 & 0x7f) << (bVar10 & 0x3f);
  } while ((char)bVar5 < '\0');
  if ((uVar11 < 0x40) && ((bVar5 & 0x40) != 0)) {
    uVar16 = uVar16 | -1L << ((byte)uVar11 & 0x3f);
  }
  param_2[0x2b] = uVar16;
  uVar16 = 0;
  bVar5 = 0;
  if ((byte)uVar3 == 1) {
    pbVar13 = pbVar13 + 2;
    param_2[0x2d] = (ulong)*pbVar8;
  }
  else {
    do {
      pbVar13 = pbVar8 + 1;
      bVar10 = *pbVar8;
      bVar2 = bVar5 & 0x3f;
      bVar5 = bVar5 + 7;
      uVar16 = uVar16 | (ulong)(bVar10 & 0x7f) << bVar2;
      pbVar8 = pbVar13;
    } while ((char)bVar10 < '\0');
    param_2[0x2d] = uVar16;
  }
  *(undefined1 *)((long)param_2 + 0x171) = 0xff;
  cVar4 = *__s;
  pbVar8 = (byte *)0x0;
  if (cVar4 == 'z') {
    uVar16 = 0;
    bVar5 = 0;
    pbVar8 = pbVar13;
    do {
      pbVar13 = pbVar8 + 1;
      bVar10 = *pbVar8;
      bVar2 = bVar5 & 0x3f;
      bVar5 = bVar5 + 7;
      uVar16 = uVar16 | (ulong)(bVar10 & 0x7f) << bVar2;
      pbVar8 = pbVar13;
    } while ((char)bVar10 < '\0');
    *(undefined1 *)((long)param_2 + 0x172) = 1;
    pbVar8 = pbVar13 + uVar16;
    cVar4 = __s[1];
    __s = __s + 1;
  }
  while (__s = __s + 1, cVar4 != '\0') {
    if (cVar4 == 'L') {
      bVar5 = *pbVar13;
      pbVar13 = pbVar13 + 1;
      *(byte *)((long)param_2 + 0x171) = bVar5;
    }
    else if (cVar4 == 'R') {
      bVar5 = *pbVar13;
      pbVar13 = pbVar13 + 1;
      *(byte *)(param_2 + 0x2e) = bVar5;
    }
    else if (cVar4 == 'P') {
      bVar5 = *pbVar13;
      uVar9 = FUN_00c84670(bVar5,param_1);
      pbVar13 = (byte *)FUN_00c84520(bVar5,uVar9,pbVar13 + 1,local_40);
      param_2[0x2a] = local_40[0];
    }
    else {
      pbVar15 = pbVar8;
      if (cVar4 != 'S') goto LAB_00c85443;
      *(undefined1 *)((long)param_2 + 0x173) = 1;
    }
    cVar4 = *__s;
  }
  pbVar15 = pbVar13;
  if (pbVar8 == (byte *)0x0) {
LAB_00c85443:
    pbVar8 = pbVar15;
    if (pbVar15 == (byte *)0x0) {
      return 3;
    }
  }
  FUN_00c846d0(pbVar8,(long)puVar17 + (ulong)*puVar17 + 4,param_1);
  if (*(byte *)(param_2 + 0x2e) == 0xff) {
    lVar12 = 8;
  }
  else {
    bVar5 = *(byte *)(param_2 + 0x2e) & 7;
    if (bVar5 == 2) {
      lVar12 = 0xc;
    }
    else {
      if (bVar5 < 3) {
        if (bVar5 != 0) {
LAB_00c85434:
                    /* WARNING: Subroutine does not return */
          abort();
        }
      }
      else {
        lVar12 = 0x10;
        if (bVar5 == 3) goto LAB_00c8535c;
        if (bVar5 != 4) goto LAB_00c85434;
      }
      lVar12 = 0x18;
    }
  }
LAB_00c8535c:
  pbVar8 = (byte *)(lVar12 + (long)puVar6);
  cVar4 = *(char *)((long)param_2 + 0x171);
  if (*(char *)((long)param_2 + 0x172) == '\0') {
    if (cVar4 == -1) goto LAB_00c853aa;
    pbVar13 = (byte *)0x0;
LAB_00c853e1:
    uVar9 = FUN_00c84670(cVar4,param_1);
    pbVar8 = (byte *)FUN_00c84520(cVar4,uVar9,pbVar8,local_40);
    *(long *)(param_1 + 0xa0) = local_40[0];
  }
  else {
    uVar16 = 0;
    bVar5 = 0;
    pbVar13 = pbVar8;
    do {
      pbVar8 = pbVar13 + 1;
      bVar10 = *pbVar13;
      bVar2 = bVar5 & 0x3f;
      bVar5 = bVar5 + 7;
      uVar16 = uVar16 | (ulong)(bVar10 & 0x7f) << bVar2;
      pbVar13 = pbVar8;
    } while ((char)bVar10 < '\0');
    pbVar13 = pbVar8 + uVar16;
    if (cVar4 != -1) goto LAB_00c853e1;
  }
  if (pbVar13 != (byte *)0x0) {
    pbVar8 = pbVar13;
  }
LAB_00c853aa:
  FUN_00c846d0(pbVar8,(long)puVar6 + (ulong)*puVar6 + 4,param_1,param_2);
  return 0;
}


// ==== entry=00c856d0 name=FUN_00c856d0 size=1831 ====

ulong FUN_00c856d0(byte *param_1,byte *param_2,long param_3,ulong param_4)

{
  char cVar1;
  uint *puVar2;
  char cVar3;
  undefined8 uVar4;
  byte *pbVar5;
  undefined8 *puVar6;
  byte bVar7;
  byte bVar8;
  byte bVar9;
  uint uVar10;
  int iVar11;
  byte *pbVar12;
  int iVar13;
  long lVar14;
  ulong uVar15;
  byte *pbVar16;
  ulong uVar17;
  byte *local_240;
  ulong local_238 [65];
  
  local_238[0] = param_4;
  if (param_1 < param_2) {
    iVar13 = 1;
    do {
      bVar7 = *param_1;
      pbVar5 = param_1 + 1;
      if (0xee < (byte)(bVar7 - 3)) {
switchD_00c8573f_caseD_4:
                    /* WARNING: Subroutine does not return */
        abort();
      }
      switch(bVar7) {
      case 3:
      case 0xe:
      case 0xf:
        pbVar16 = *(byte **)(param_1 + 1);
        pbVar5 = param_1 + 9;
        break;
      default:
        goto switchD_00c8573f_caseD_4;
      case 6:
      case 0x19:
      case 0x1f:
      case 0x20:
      case 0x23:
      case 0x94:
        if (iVar13 == 0) goto code_r0x0051e9ca;
        iVar13 = iVar13 + -1;
        puVar2 = (uint *)local_238[iVar13];
        if (bVar7 == 0x1f) {
          pbVar16 = (byte *)-(long)puVar2;
        }
        else if (bVar7 < 0x20) {
          if (bVar7 == 6) {
            pbVar16 = *(byte **)puVar2;
          }
          else {
            if (bVar7 != 0x19) goto switchD_00c8573f_caseD_4;
            pbVar16 = (byte *)(((ulong)puVar2 ^ (long)puVar2 >> 0x3f) - ((long)puVar2 >> 0x3f));
          }
        }
        else if (bVar7 == 0x23) {
          uVar17 = 0;
          bVar7 = 0;
          pbVar16 = pbVar5;
          do {
            pbVar5 = pbVar16 + 1;
            bVar8 = *pbVar16;
            bVar9 = bVar7 & 0x3f;
            bVar7 = bVar7 + 7;
            uVar17 = uVar17 | (ulong)(bVar8 & 0x7f) << bVar9;
            pbVar16 = pbVar5;
          } while ((char)bVar8 < '\0');
          pbVar16 = (byte *)((long)puVar2 + uVar17);
        }
        else if (bVar7 == 0x94) {
          bVar7 = param_1[1];
          pbVar5 = param_1 + 2;
          if (bVar7 == 2) {
            pbVar16 = (byte *)(ulong)(ushort)*puVar2;
          }
          else if (bVar7 < 3) {
            if (bVar7 != 1) goto switchD_00c8573f_caseD_4;
            pbVar16 = (byte *)(ulong)(byte)*puVar2;
          }
          else if (bVar7 == 4) {
            pbVar16 = (byte *)(ulong)*puVar2;
          }
          else {
            if (bVar7 != 8) goto switchD_00c8573f_caseD_4;
            pbVar16 = *(byte **)puVar2;
          }
        }
        else {
          if (bVar7 != 0x20) goto switchD_00c8573f_caseD_4;
          pbVar16 = (byte *)~(ulong)puVar2;
        }
        break;
      case 8:
        pbVar16 = (byte *)(ulong)param_1[1];
        pbVar5 = param_1 + 2;
        break;
      case 9:
        pbVar16 = (byte *)(long)(char)param_1[1];
        pbVar5 = param_1 + 2;
        break;
      case 10:
        pbVar16 = (byte *)(ulong)*(ushort *)(param_1 + 1);
        pbVar5 = param_1 + 3;
        break;
      case 0xb:
        pbVar16 = (byte *)(long)*(short *)(param_1 + 1);
        pbVar5 = param_1 + 3;
        break;
      case 0xc:
        pbVar16 = (byte *)(ulong)*(uint *)(param_1 + 1);
        pbVar5 = param_1 + 5;
        break;
      case 0xd:
        pbVar16 = (byte *)(long)*(int *)(param_1 + 1);
        pbVar5 = param_1 + 5;
        break;
      case 0x10:
        pbVar16 = (byte *)0x0;
        bVar7 = 0;
        pbVar12 = pbVar5;
        do {
          pbVar5 = pbVar12 + 1;
          bVar8 = *pbVar12;
          bVar9 = bVar7 & 0x3f;
          bVar7 = bVar7 + 7;
          pbVar16 = (byte *)((ulong)pbVar16 | (ulong)(bVar8 & 0x7f) << bVar9);
          pbVar12 = pbVar5;
        } while ((char)bVar8 < '\0');
        break;
      case 0x11:
        pbVar16 = (byte *)0x0;
        uVar10 = 0;
        pbVar12 = pbVar5;
        do {
          pbVar5 = pbVar12 + 1;
          bVar7 = *pbVar12;
          bVar8 = (byte)uVar10;
          uVar10 = uVar10 + 7;
          pbVar16 = (byte *)((ulong)pbVar16 | (ulong)(bVar7 & 0x7f) << (bVar8 & 0x3f));
          pbVar12 = pbVar5;
        } while ((char)bVar7 < '\0');
        if ((uVar10 < 0x40) && ((bVar7 & 0x40) != 0)) {
          pbVar16 = (byte *)((ulong)pbVar16 | -1L << ((byte)uVar10 & 0x3f));
        }
        break;
      case 0x12:
        if (iVar13 == 0) goto code_r0x0051e9ca;
        pbVar16 = (byte *)local_238[iVar13 + -1];
        break;
      case 0x13:
        if (iVar13 != 0) {
          iVar13 = iVar13 + -1;
          goto LAB_00c8576c;
        }
        goto code_r0x0051e9ca;
      case 0x14:
        if (iVar13 < 2) goto code_r0x0051e9ca;
        pbVar16 = (byte *)local_238[iVar13 + -2];
        break;
      case 0x15:
        pbVar5 = param_1 + 2;
        if ((long)(iVar13 + -1) <= (long)(ulong)param_1[1]) goto code_r0x0051e9ca;
        pbVar16 = (byte *)local_238[(long)(iVar13 + -1) - (ulong)param_1[1]];
        break;
      case 0x16:
        if (1 < iVar13) {
          uVar17 = local_238[iVar13 + -1];
          local_238[iVar13 + -1] = local_238[iVar13 + -2];
          local_238[iVar13 + -2] = uVar17;
          goto LAB_00c8576c;
        }
        goto code_r0x0051e9ca;
      case 0x17:
        if (2 < iVar13) {
          uVar17 = local_238[iVar13 + -1];
          uVar15 = local_238[iVar13 + -3];
          local_238[iVar13 + -1] = local_238[iVar13 + -2];
          local_238[iVar13 + -2] = uVar15;
          local_238[iVar13 + -3] = uVar17;
          goto LAB_00c8576c;
        }
        goto code_r0x0051e9ca;
      case 0x1a:
      case 0x1b:
      case 0x1c:
      case 0x1d:
      case 0x1e:
      case 0x21:
      case 0x22:
      case 0x24:
      case 0x25:
      case 0x26:
      case 0x27:
      case 0x29:
      case 0x2a:
      case 0x2b:
      case 0x2c:
      case 0x2d:
      case 0x2e:
        if (iVar13 < 2) goto code_r0x0051e9ca;
        iVar11 = iVar13 + -2;
        uVar17 = local_238[iVar11];
        uVar15 = local_238[iVar13 + -1];
        bVar8 = (byte)uVar15;
        iVar13 = iVar11;
        switch(bVar7 - 0x1a & 0xff) {
        case 0:
          pbVar16 = (byte *)(uVar17 & uVar15);
          break;
        case 1:
          pbVar16 = (byte *)((long)uVar17 / (long)uVar15);
          break;
        case 2:
          pbVar16 = (byte *)(uVar17 - uVar15);
          break;
        case 3:
          pbVar16 = (byte *)(uVar17 % uVar15);
          break;
        case 4:
          pbVar16 = (byte *)(uVar17 * uVar15);
          break;
        default:
          goto switchD_00c8573f_caseD_4;
        case 7:
          pbVar16 = (byte *)(uVar17 | uVar15);
          break;
        case 8:
          pbVar16 = (byte *)(uVar17 + uVar15);
          break;
        case 10:
          pbVar16 = (byte *)(uVar17 << (bVar8 & 0x3f));
          break;
        case 0xb:
          pbVar16 = (byte *)(uVar17 >> (bVar8 & 0x3f));
          break;
        case 0xc:
          pbVar16 = (byte *)((long)uVar17 >> (bVar8 & 0x3f));
          break;
        case 0xd:
          pbVar16 = (byte *)(uVar17 ^ uVar15);
          break;
        case 0xf:
          pbVar16 = (byte *)(ulong)(uVar17 == uVar15);
          break;
        case 0x10:
          pbVar16 = (byte *)(ulong)((long)uVar15 <= (long)uVar17);
          break;
        case 0x11:
          pbVar16 = (byte *)(ulong)((long)uVar15 < (long)uVar17);
          break;
        case 0x12:
          pbVar16 = (byte *)(ulong)((long)uVar17 <= (long)uVar15);
          break;
        case 0x13:
          pbVar16 = (byte *)(ulong)((long)uVar17 < (long)uVar15);
          break;
        case 0x14:
          pbVar16 = (byte *)(ulong)(uVar17 != uVar15);
        }
        break;
      case 0x28:
        if (iVar13 != 0) {
          iVar13 = iVar13 + -1;
          pbVar5 = param_1 + 3;
          if (local_238[iVar13] != 0) {
            pbVar5 = pbVar5 + *(short *)(param_1 + 1);
          }
          goto LAB_00c8576c;
        }
        goto code_r0x0051e9ca;
      case 0x2f:
        pbVar5 = param_1 + (long)*(short *)(param_1 + 1) + 3;
        goto LAB_00c8576c;
      case 0x30:
      case 0x31:
      case 0x32:
      case 0x33:
      case 0x34:
      case 0x35:
      case 0x36:
      case 0x37:
      case 0x38:
      case 0x39:
      case 0x3a:
      case 0x3b:
      case 0x3c:
      case 0x3d:
      case 0x3e:
      case 0x3f:
      case 0x40:
      case 0x41:
      case 0x42:
      case 0x43:
      case 0x44:
      case 0x45:
      case 0x46:
      case 0x47:
      case 0x48:
      case 0x49:
      case 0x4a:
      case 0x4b:
      case 0x4c:
      case 0x4d:
      case 0x4e:
      case 0x4f:
        pbVar16 = (byte *)(ulong)(bVar7 - 0x30);
        break;
      case 0x50:
      case 0x51:
      case 0x52:
      case 0x53:
      case 0x54:
      case 0x55:
      case 0x56:
      case 0x57:
      case 0x58:
      case 0x59:
      case 0x5a:
      case 0x5b:
      case 0x5c:
      case 0x5d:
      case 0x5e:
      case 0x5f:
      case 0x60:
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
      case 0x6c:
      case 0x6d:
      case 0x6e:
      case 0x6f:
        if ((int)(bVar7 - 0x50) < 0x12) {
          lVar14 = (long)(int)(bVar7 - 0x50);
          cVar3 = (&DAT_011c6730)[lVar14];
          pbVar16 = *(byte **)(param_3 + lVar14 * 8);
          if ((*(ulong *)(param_3 + 0xc0) & 0x4000000000000000) != 0) {
            cVar1 = *(char *)(param_3 + 0xd8 + lVar14);
joined_r0x00c859aa:
            if (cVar1 != '\0') break;
          }
          goto LAB_00c859b0;
        }
        goto code_r0x0051e9ca;
      case 0x70:
      case 0x71:
      case 0x72:
      case 0x73:
      case 0x74:
      case 0x75:
      case 0x76:
      case 0x77:
      case 0x78:
      case 0x79:
      case 0x7a:
      case 0x7b:
      case 0x7c:
      case 0x7d:
      case 0x7e:
      case 0x7f:
      case 0x80:
      case 0x81:
      case 0x82:
      case 0x83:
      case 0x84:
      case 0x85:
      case 0x86:
      case 0x87:
      case 0x88:
      case 0x89:
      case 0x8a:
      case 0x8b:
      case 0x8c:
      case 0x8d:
      case 0x8e:
      case 0x8f:
        uVar15 = 0;
        uVar10 = 0;
        pbVar16 = pbVar5;
        do {
          pbVar5 = pbVar16 + 1;
          bVar8 = *pbVar16;
          bVar9 = (byte)uVar10;
          uVar10 = uVar10 + 7;
          uVar15 = uVar15 | (ulong)(bVar8 & 0x7f) << (bVar9 & 0x3f);
          pbVar16 = pbVar5;
        } while ((char)bVar8 < '\0');
        if ((uVar10 < 0x40) && ((bVar8 & 0x40) != 0)) {
          uVar15 = uVar15 | -1L << ((byte)uVar10 & 0x3f);
        }
        iVar11 = bVar7 - 0x70;
        if (iVar11 < 0x12) {
          lVar14 = (long)iVar11;
          puVar6 = *(undefined8 **)(param_3 + lVar14 * 8);
          if (((*(ulong *)(param_3 + 0xc0) & 0x4000000000000000) == 0) ||
             (*(char *)(param_3 + 0xd8 + lVar14) == '\0')) {
            if ((&DAT_011c6730)[lVar14] != '\b') {
                    /* WARNING: Subroutine does not return */
              abort();
            }
LAB_00c8594e:
            puVar6 = (undefined8 *)*puVar6;
          }
          goto LAB_00c85951;
        }
        goto code_r0x0051e9ca;
      case 0x90:
        uVar17 = 0;
        bVar7 = 0;
        pbVar16 = pbVar5;
        do {
          pbVar5 = pbVar16 + 1;
          bVar8 = *pbVar16;
          bVar9 = bVar7 & 0x3f;
          bVar7 = bVar7 + 7;
          uVar17 = uVar17 | (ulong)(bVar8 & 0x7f) << bVar9;
          pbVar16 = pbVar5;
        } while ((char)bVar8 < '\0');
        if (0x11 < (int)uVar17) goto code_r0x0051e9ca;
        lVar14 = (long)(int)uVar17;
        cVar3 = (&DAT_011c6730)[lVar14];
        pbVar16 = *(byte **)(param_3 + lVar14 * 8);
        if ((*(ulong *)(param_3 + 0xc0) & 0x4000000000000000) != 0) {
          cVar1 = *(char *)(param_3 + 0xd8 + lVar14);
          goto joined_r0x00c859aa;
        }
LAB_00c859b0:
        if (cVar3 != '\b') goto code_r0x0051e9ca;
        pbVar16 = *(byte **)pbVar16;
        break;
      case 0x92:
        uVar17 = 0;
        bVar7 = 0;
        do {
          pbVar16 = pbVar5 + 1;
          bVar8 = *pbVar5;
          bVar9 = bVar7 & 0x3f;
          bVar7 = bVar7 + 7;
          uVar17 = uVar17 | (ulong)(bVar8 & 0x7f) << bVar9;
          pbVar5 = pbVar16;
        } while ((char)bVar8 < '\0');
        uVar15 = 0;
        uVar10 = 0;
        do {
          pbVar5 = pbVar16 + 1;
          bVar7 = *pbVar16;
          bVar8 = (byte)uVar10;
          uVar10 = uVar10 + 7;
          uVar15 = uVar15 | (ulong)(bVar7 & 0x7f) << (bVar8 & 0x3f);
          pbVar16 = pbVar5;
        } while ((char)bVar7 < '\0');
        if ((uVar10 < 0x40) && ((bVar7 & 0x40) != 0)) {
          uVar15 = uVar15 | -1L << ((byte)uVar10 & 0x3f);
        }
        if (0x11 < (int)uVar17) goto code_r0x0051e9ca;
        lVar14 = (long)(int)uVar17;
        puVar6 = *(undefined8 **)(param_3 + lVar14 * 8);
        if (((*(ulong *)(param_3 + 0xc0) & 0x4000000000000000) == 0) ||
           (*(char *)(param_3 + 0xd8 + lVar14) == '\0')) {
          if ((&DAT_011c6730)[lVar14] == '\b') goto LAB_00c8594e;
          goto code_r0x0051e9ca;
        }
LAB_00c85951:
        pbVar16 = (byte *)(uVar15 + (long)puVar6);
        break;
      case 0x96:
        goto LAB_00c8576c;
      case 0xf1:
        bVar7 = param_1[1];
        uVar4 = FUN_00c84670(bVar7,param_3);
        pbVar5 = (byte *)FUN_00c84520(bVar7,uVar4,param_1 + 2);
        pbVar16 = local_240;
      }
      if (0x3f < iVar13) goto code_r0x0051e9ca;
      local_238[iVar13] = (ulong)pbVar16;
      iVar13 = iVar13 + 1;
LAB_00c8576c:
      param_1 = pbVar5;
    } while (pbVar5 < param_2);
    if (iVar13 == 0) {
code_r0x0051e9ca:
                    /* WARNING: Subroutine does not return */
      abort();
    }
    param_4 = local_238[iVar13 + -1];
  }
  return param_4;
}


// ==== entry=00c85ea0 orig=FUN_00c85ea0 size=982 name=bigstruct_copy ====

void bigstruct_copy(undefined8 *param_1,long *param_2)

{
  byte bVar1;
  byte bVar2;
  long lVar3;
  ulong uVar4;
  long lVar5;
  undefined8 *puVar6;
  byte bVar7;
  long lVar8;
  byte *pbVar9;
  byte *pbVar10;
  long *plVar11;
  bool bVar12;
  undefined8 local_130;
  undefined8 local_128 [4];
  undefined8 local_108;
  undefined8 uStack_100;
  undefined8 local_f8;
  undefined8 *puStack_f0;
  undefined8 local_e8;
  undefined8 uStack_e0;
  undefined8 local_d8;
  undefined8 uStack_d0;
  undefined8 local_c8;
  undefined8 uStack_c0;
  undefined8 local_b8;
  undefined8 uStack_b0;
  undefined8 local_a8;
  undefined8 uStack_a0;
  undefined8 local_98;
  undefined8 uStack_90;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  undefined8 uStack_70;
  ulong local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  
  local_128[0] = *param_1;
  local_128[1] = param_1[1];
  local_128[2] = param_1[2];
  local_128[3] = param_1[3];
  local_108 = param_1[4];
  uStack_100 = param_1[5];
  local_f8 = param_1[6];
  puStack_f0 = (undefined8 *)param_1[7];
  local_e8 = param_1[8];
  uStack_e0 = param_1[9];
  local_d8 = param_1[10];
  uStack_d0 = param_1[0xb];
  local_c8 = param_1[0xc];
  uStack_c0 = param_1[0xd];
  local_b8 = param_1[0xe];
  uStack_b0 = param_1[0xf];
  local_a8 = param_1[0x10];
  uStack_a0 = param_1[0x11];
  local_98 = param_1[0x12];
  uStack_90 = param_1[0x13];
  local_88 = param_1[0x14];
  uStack_80 = param_1[0x15];
  local_78 = param_1[0x16];
  uStack_70 = param_1[0x17];
  local_68 = param_1[0x18];
  uVar4 = param_1[0x1b];
  uStack_60 = param_1[0x19];
  local_58 = param_1[0x1a];
  uStack_50 = uVar4;
  local_48 = param_1[0x1c];
  uStack_40 = param_1[0x1d];
  if (((((ulong)param_1[0x18] >> 0x3e & 1) == 0) ||
      (uStack_50._7_1_ = (char)(uVar4 >> 0x38), bVar12 = uStack_50._7_1_ == '\0', bVar12)) &&
     ((undefined8 *)param_1[7] == (undefined8 *)0x0)) {
    if (DAT_011c6737 != '\b') goto code_r0x0051e9cf;
    if ((local_68 & 0x4000000000000000) != 0) {
      uStack_50 = uVar4 & 0xffffffffffffff;
    }
    puStack_f0 = &local_130;
    local_130 = param_1[0x12];
  }
  if ((*(byte *)((long)param_1 + 199) & 0x40) != 0) {
    *(undefined1 *)((long)param_1 + 0xdf) = 0;
  }
  param_1[7] = 0;
  if ((int)param_2[0x28] == 1) {
    if (0x11 < (int)param_2[0x26]) {
code_r0x0051e9cf:
                    /* WARNING: Subroutine does not return */
      abort();
    }
    lVar3 = (long)(int)param_2[0x26];
    puVar6 = (undefined8 *)local_128[lVar3];
    if (((local_68 & 0x4000000000000000) == 0) || (*(char *)((long)&uStack_50 + lVar3) == '\0')) {
      if ((&DAT_011c6730)[lVar3] != '\b') goto code_r0x0051e9cf;
      puVar6 = (undefined8 *)*puVar6;
    }
    lVar3 = (long)puVar6 + param_2[0x25];
  }
  else {
    if ((int)param_2[0x28] != 2) {
                    /* WARNING: Subroutine does not return */
      abort();
    }
    uVar4 = 0;
    bVar7 = 0;
    pbVar10 = (byte *)param_2[0x27];
    do {
      pbVar9 = pbVar10 + 1;
      bVar1 = *pbVar10;
      bVar2 = bVar7 & 0x3f;
      bVar7 = bVar7 + 7;
      uVar4 = uVar4 | (ulong)(bVar1 & 0x7f) << bVar2;
      pbVar10 = pbVar9;
    } while ((char)bVar1 < '\0');
    lVar3 = FUN_00c856d0(pbVar9,pbVar9 + uVar4,local_128,0);
  }
  param_1[0x12] = lVar3;
  lVar8 = 0;
  plVar11 = param_2;
LAB_00c860a0:
  switch((int)plVar11[1]) {
  default:
    goto switchD_00c860b3_caseD_0;
  case 1:
    puVar6 = (undefined8 *)(*plVar11 + lVar3);
    uVar4 = param_1[0x18];
    break;
  case 2:
    lVar5 = (long)(int)*plVar11;
    if (*(char *)((long)&uStack_50 + lVar5) != '\0') {
      if (0x11 < (int)*plVar11) goto code_r0x0051e9cf;
      puVar6 = (undefined8 *)local_128[lVar5];
      if ((local_68 & 0x4000000000000000) == 0) {
        if ((&DAT_011c6730)[lVar5] == '\b') {
          puVar6 = (undefined8 *)*puVar6;
          goto LAB_00c861ea;
        }
        goto code_r0x0051e9cf;
      }
      goto LAB_00c861ea;
    }
    puVar6 = (undefined8 *)local_128[lVar5];
    uVar4 = param_1[0x18];
    break;
  case 3:
    uVar4 = 0;
    bVar7 = 0;
    pbVar10 = (byte *)*plVar11;
    do {
      pbVar9 = pbVar10 + 1;
      bVar1 = *pbVar10;
      bVar2 = bVar7 & 0x3f;
      bVar7 = bVar7 + 7;
      uVar4 = uVar4 | (ulong)(bVar1 & 0x7f) << bVar2;
      pbVar10 = pbVar9;
    } while ((char)bVar1 < '\0');
    puVar6 = (undefined8 *)FUN_00c856d0(pbVar9,pbVar9 + uVar4,local_128);
    uVar4 = param_1[0x18];
    break;
  case 4:
    puVar6 = (undefined8 *)(*plVar11 + lVar3);
    if ((byte)(&DAT_011c6730)[lVar8] < 9) goto LAB_00c860cf;
    goto code_r0x0051e9cf;
  case 5:
    uVar4 = 0;
    bVar7 = 0;
    pbVar10 = (byte *)*plVar11;
    do {
      pbVar9 = pbVar10 + 1;
      bVar1 = *pbVar10;
      bVar2 = bVar7 & 0x3f;
      bVar7 = bVar7 + 7;
      uVar4 = uVar4 | (ulong)(bVar1 & 0x7f) << bVar2;
      pbVar10 = pbVar9;
    } while ((char)bVar1 < '\0');
    puVar6 = (undefined8 *)FUN_00c856d0(pbVar9,pbVar9 + uVar4,local_128,lVar3);
LAB_00c861ea:
    if (8 < (byte)(&DAT_011c6730)[lVar8]) {
                    /* WARNING: Subroutine does not return */
      abort();
    }
LAB_00c860cf:
    *(undefined1 *)((long)param_1 + lVar8 + 0xd8) = 1;
    goto LAB_00c860d8;
  }
  if ((uVar4 & 0x4000000000000000) != 0) {
    *(undefined1 *)((long)param_1 + lVar8 + 0xd8) = 0;
  }
LAB_00c860d8:
  param_1[lVar8] = puVar6;
switchD_00c860b3_caseD_0:
  lVar8 = lVar8 + 1;
  plVar11 = plVar11 + 2;
  if (lVar8 == 0x12) {
    uVar4 = param_1[0x18] & 0x7fffffffffffffff;
    if (*(char *)((long)param_2 + 0x173) != '\0') {
      uVar4 = param_1[0x18] | 0x8000000000000000;
    }
    param_1[0x18] = uVar4;
    return;
  }
  goto LAB_00c860a0;
}


// ==== entry=00c86290 name=FUN_00c86290 size=368 ====

void FUN_00c86290(undefined8 *param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  long lVar2;
  undefined8 *puVar3;
  undefined8 unaff_retaddr;
  undefined8 local_1b0;
  undefined1 local_1a8 [296];
  undefined8 local_80;
  undefined8 local_78;
  undefined4 local_68;
  
  puVar3 = param_1;
  for (lVar2 = 0x1e; lVar2 != 0; lVar2 = lVar2 + -1) {
    *puVar3 = 0;
    puVar3 = puVar3 + 1;
  }
  param_1[0x13] = unaff_retaddr;
  param_1[0x18] = 0x4000000000000000;
  iVar1 = FUN_00c850a0(param_1,local_1a8);
  if (iVar1 == 0) {
    iVar1 = pthread_once((pthread_once_t *)&DAT_011c6720,FUN_00c85020);
    if ((iVar1 != 0) && (DAT_011c6730 == '\0')) {
      DAT_011c6730 = '\b';
      DAT_011c6731 = 8;
      DAT_011c6732 = 8;
      DAT_011c6733 = 8;
      DAT_011c6734 = 8;
      DAT_011c6735 = 8;
      DAT_011c6736 = 8;
      DAT_011c6737 = '\b';
      DAT_011c6738 = 8;
      DAT_011c6739 = 8;
      DAT_011c673a = 8;
      DAT_011c673b = 8;
      DAT_011c673c = 8;
      DAT_011c673d = 8;
      DAT_011c673e = 8;
      DAT_011c673f = 8;
      DAT_011c6740 = 8;
    }
    if (DAT_011c6737 == '\b') {
      if ((*(byte *)((long)param_1 + 199) & 0x40) != 0) {
        *(undefined1 *)((long)param_1 + 0xdf) = 0;
      }
      local_68 = 1;
      param_1[7] = &local_1b0;
      local_78 = 7;
      local_80 = 0;
      local_1b0 = param_2;
      bigstruct_copy(param_1,local_1a8);
      param_1[0x13] = param_3;
      return;
    }
  }
                    /* WARNING: Subroutine does not return */
  abort();
}


// ==== entry=00c86410 name=FUN_00c86410 size=127 ====

void FUN_00c86410(long param_1,long param_2)

{
  int iVar1;
  long lVar2;
  undefined8 *puVar3;
  
  bigstruct_copy();
  if (*(int *)(param_2 + 8 + *(long *)(param_2 + 0x168) * 0x10) == 6) {
    *(undefined8 *)(param_1 + 0x98) = 0;
    return;
  }
  iVar1 = (int)*(long *)(param_2 + 0x168);
  if (iVar1 < 0x12) {
    lVar2 = (long)iVar1;
    puVar3 = *(undefined8 **)(param_1 + lVar2 * 8);
    if (((*(byte *)(param_1 + 199) & 0x40) == 0) || (*(char *)(param_1 + 0xd8 + lVar2) == '\0')) {
      if ((&DAT_011c6730)[lVar2] != '\b') goto <EXTERNAL>_abort;
      puVar3 = (undefined8 *)*puVar3;
    }
    *(undefined8 **)(param_1 + 0x98) = puVar3;
    return;
  }
<EXTERNAL>_abort:
                    /* WARNING: Subroutine does not return */
  abort();
}


// ==== entry=00c864a0 name=FUN_00c864a0 size=184 ====

undefined8 FUN_00c864a0(undefined8 *param_1,long param_2,long *param_3)

{
  int iVar1;
  undefined8 uVar2;
  uint uVar3;
  long lVar4;
  undefined1 auStack_1b8 [336];
  code *local_68;
  
  lVar4 = 1;
  do {
    iVar1 = FUN_00c850a0(param_2,auStack_1b8);
    uVar3 = (uint)(param_1[3] == *(long *)(param_2 + 0x90) + (*(long *)(param_2 + 0xc0) >> 0x3f));
    if (iVar1 != 0) {
      return 2;
    }
    if (local_68 != (code *)0x0) {
      uVar2 = (*local_68)(1,uVar3 << 2 | 2,*param_1,param_1,param_2);
      if ((int)uVar2 == 7) {
        *param_3 = lVar4;
        return uVar2;
      }
      if ((int)uVar2 != 8) {
        return 2;
      }
    }
    if (uVar3 != 0) {
                    /* WARNING: Subroutine does not return */
      abort();
    }
    lVar4 = lVar4 + 1;
    FUN_00c86410(param_2,auStack_1b8);
  } while( true );
}


// ==== entry=00c86570 name=FUN_00c86570 size=246 ====

int FUN_00c86570(undefined8 *param_1,undefined8 param_2,long *param_3)

{
  code *pcVar1;
  undefined8 uVar2;
  int iVar3;
  int iVar4;
  long lVar5;
  undefined1 local_1b8 [336];
  code *local_68;
  
  lVar5 = 1;
  pcVar1 = (code *)param_1[2];
  uVar2 = param_1[3];
  while( true ) {
    iVar3 = FUN_00c850a0(param_2,local_1b8);
    if ((iVar3 != 0) && (iVar3 != 5)) {
      return 2;
    }
    if (iVar3 == 5) break;
    iVar3 = (*pcVar1)(1,10,*param_1,param_1,param_2,uVar2);
    if (iVar3 != 0) {
      return 2;
    }
    if (local_68 != (code *)0x0) {
      iVar3 = (*local_68)(1,10,*param_1,param_1,param_2);
      if (iVar3 == 7) goto LAB_00c86668;
      if (iVar3 != 8) {
        return 2;
      }
    }
    lVar5 = lVar5 + 1;
    FUN_00c86410(param_2,local_1b8);
  }
  iVar4 = (*pcVar1)(1,0x1a,*param_1,param_1,param_2,uVar2);
  iVar3 = 5;
  if (iVar4 != 0) {
    return 2;
  }
LAB_00c86668:
  *param_3 = lVar5;
  return iVar3;
}


// ==== entry=00c86680 name=FUN_00c86680 size=423 ====

long FUN_00c86680(long param_1,long param_2)

{
  byte bVar1;
  long lVar2;
  undefined8 *puVar3;
  uint uVar4;
  uint uVar5;
  ulong uVar6;
  long lVar7;
  undefined8 *puVar8;
  undefined8 local_10 [2];
  
  if ((((*(byte *)(param_2 + 199) & 0x40) == 0) || (*(char *)(param_2 + 0xdf) == '\0')) &&
     (*(long *)(param_2 + 0x38) == 0)) {
    if (DAT_011c6737 != '\b') goto <EXTERNAL>_abort;
    if ((*(byte *)(param_2 + 199) & 0x40) != 0) {
      *(undefined1 *)(param_2 + 0xdf) = 0;
    }
    *(undefined8 **)(param_2 + 0x38) = local_10;
    local_10[0] = *(undefined8 *)(param_2 + 0x90);
  }
  lVar2 = 0;
  do {
    while( true ) {
      puVar3 = *(undefined8 **)(param_1 + lVar2 * 8);
      puVar8 = *(undefined8 **)(param_2 + lVar2 * 8);
      if (*(char *)(param_1 + 0xd8 + lVar2) != '\0') goto <EXTERNAL>_abort;
      if (*(char *)(param_2 + 0xd8 + lVar2) == '\0') break;
      if (puVar3 != (undefined8 *)0x0) {
        if ((&DAT_011c6730)[lVar2] != '\b') goto <EXTERNAL>_abort;
        *puVar3 = puVar8;
      }
LAB_00c866cb:
      lVar2 = lVar2 + 1;
      if (lVar2 == 0x11) goto LAB_00c86780;
    }
    if ((puVar8 == (undefined8 *)0x0 || puVar3 == (undefined8 *)0x0) || (puVar3 == puVar8))
    goto LAB_00c866cb;
    bVar1 = (&DAT_011c6730)[lVar2];
    uVar4 = (uint)bVar1;
    uVar5 = (uint)bVar1;
    if (uVar4 < 8) {
      if ((bVar1 & 4) == 0) {
        uVar4 = (uint)bVar1;
        if ((uVar4 != 0) && (*(undefined1 *)puVar3 = *(undefined1 *)puVar8, (bVar1 & 2) != 0)) {
          *(undefined2 *)((long)puVar3 + ((ulong)uVar4 - 2)) =
               *(undefined2 *)((long)puVar8 + ((ulong)uVar4 - 2));
        }
      }
      else {
        *(undefined4 *)puVar3 = *(undefined4 *)puVar8;
        *(undefined4 *)((long)puVar3 + ((ulong)uVar5 - 4)) =
             *(undefined4 *)((long)puVar8 + ((ulong)uVar5 - 4));
      }
      goto LAB_00c866cb;
    }
    lVar2 = lVar2 + 1;
    *puVar3 = *puVar8;
    *(undefined8 *)((long)puVar3 + ((ulong)uVar4 - 8)) =
         *(undefined8 *)((long)puVar8 + ((ulong)uVar4 - 8));
    lVar7 = (long)puVar3 - (long)((ulong)(puVar3 + 1) & 0xfffffffffffffff8);
    puVar8 = (undefined8 *)((long)puVar8 - lVar7);
    puVar3 = (undefined8 *)((ulong)(puVar3 + 1) & 0xfffffffffffffff8);
    for (uVar6 = (ulong)(uVar5 + (int)lVar7 >> 3); uVar6 != 0; uVar6 = uVar6 - 1) {
      *puVar3 = *puVar8;
      puVar8 = puVar8 + 1;
      puVar3 = puVar3 + 1;
    }
  } while (lVar2 != 0x11);
LAB_00c86780:
  lVar2 = 0;
  if (((*(byte *)(param_1 + 199) & 0x40) != 0) && (*(char *)(param_1 + 0xdf) != '\0')) {
    return 0;
  }
  if (*(long *)(param_1 + 0x38) == 0) {
    puVar3 = *(undefined8 **)(param_2 + 0x38);
    if (((*(byte *)(param_2 + 199) & 0x40) == 0) || (*(char *)(param_2 + 0xdf) == '\0')) {
      if (DAT_011c6737 != '\b') {
<EXTERNAL>_abort:
                    /* WARNING: Subroutine does not return */
        abort();
      }
      puVar3 = (undefined8 *)*puVar3;
    }
    lVar2 = (long)puVar3 + (*(long *)(param_2 + 0xd0) - *(long *)(param_1 + 0x90));
  }
  return lVar2;
}


// ==== entry=00c86840 name=FUN_00c86840 size=72 ====

undefined8 * FUN_00c86840(long param_1,int param_2)

{
  undefined8 *puVar1;
  long lVar2;
  
  if (param_2 < 0x12) {
    lVar2 = (long)param_2;
    puVar1 = *(undefined8 **)(param_1 + lVar2 * 8);
    if (((*(byte *)(param_1 + 199) & 0x40) != 0) && (*(char *)(param_1 + 0xd8 + lVar2) != '\0')) {
      return puVar1;
    }
    if ((&DAT_011c6730)[lVar2] == '\b') {
      return (undefined8 *)*puVar1;
    }
  }
                    /* WARNING: Subroutine does not return */
  abort();
}


// ==== entry=00c86890 orig=FUN_00c86890 size=8 name=BSim_QPoint::y ====

/* BSim sim=0.9999999999999999 sig=9.999999956618833 ref=libwindtermopen2.so.1.0.0::QPoint::y */

undefined8 BSim_QPoint__y(long param_1)

{
  return *(undefined8 *)(param_1 + 0x90);
}


// ==== entry=00c868a0 name=FUN_00c868a0 size=75 ====

void FUN_00c868a0(long param_1,int param_2,undefined8 param_3)

{
  long lVar1;
  
  if (param_2 < 0x12) {
    lVar1 = (long)param_2;
    if (((*(byte *)(param_1 + 199) & 0x40) != 0) && (*(char *)(param_1 + 0xd8 + lVar1) != '\0')) {
      *(undefined8 *)(param_1 + lVar1 * 8) = param_3;
      return;
    }
    if ((&DAT_011c6730)[lVar1] == '\b') {
      **(undefined8 **)(param_1 + lVar1 * 8) = param_3;
      return;
    }
  }
                    /* WARNING: Subroutine does not return */
  abort();
}


// ==== entry=00c86900 orig=FUN_00c86900 size=8 name=BSim_QPoint::y ====

/* BSim sim=0.9999999999999999 sig=9.999999956618833 ref=libwindtermopen2.so.1.0.0::QPoint::y */

undefined8 BSim_QPoint__y(long param_1)

{
  return *(undefined8 *)(param_1 + 0x98);
}


// ==== entry=00c86910 name=FUN_00c86910 size=24 ====

undefined8 FUN_00c86910(long param_1,uint *param_2)

{
  *param_2 = (uint)((long)*(undefined8 *)(param_1 + 0xc0) >> 0x3f) & 1;
  return *(undefined8 *)(param_1 + 0x98);
}


// ==== entry=00c86930 orig=FUN_00c86930 size=8 name=BSim_Splitter::setMainIndex ====

/* BSim sim=1.0 sig=10.822893238850593 ref=libsplitter.so.1.0.0::Splitter::setMainIndex */

void BSim_Splitter__setMainIndex(long param_1,undefined8 param_2)

{
  *(undefined8 *)(param_1 + 0x98) = param_2;
  return;
}


// ==== entry=00c86940 orig=FUN_00c86940 size=8 name=BSim_QPoint::y ====

/* BSim sim=0.9999999999999999 sig=9.999999956618833 ref=libwindtermopen2.so.1.0.0::QPoint::y */

undefined8 BSim_QPoint__y(long param_1)

{
  return *(undefined8 *)(param_1 + 0xa0);
}


// ==== entry=00c86950 orig=FUN_00c86950 size=8 name=BSim_QPoint::y ====

/* BSim sim=0.9999999999999999 sig=9.999999956618833 ref=libwindtermopen2.so.1.0.0::QPoint::y */

undefined8 BSim_QPoint__y(long param_1)

{
  return *(undefined8 *)(param_1 + 0xb8);
}


// ==== entry=00c86960 name=FUN_00c86960 size=31 ====

undefined8 FUN_00c86960(long param_1)

{
  long lVar1;
  undefined8 uVar2;
  undefined1 auStack_28 [16];
  undefined8 local_18;
  
  lVar1 = FUN_00c88cf0(param_1 + -1,auStack_28);
  uVar2 = 0;
  if (lVar1 != 0) {
    uVar2 = local_18;
  }
  return uVar2;
}


// ==== entry=00c86980 orig=FUN_00c86980 size=8 name=BSim_QPoint::y ====

/* BSim sim=0.9999999999999999 sig=9.999999956618833 ref=libwindtermopen2.so.1.0.0::QPoint::y */

undefined8 BSim_QPoint__y(long param_1)

{
  return *(undefined8 *)(param_1 + 0xb0);
}


// ==== entry=00c86990 orig=FUN_00c86990 size=8 name=BSim_QPoint::y ====

/* BSim sim=0.9999999999999999 sig=9.999999956618833 ref=libwindtermopen2.so.1.0.0::QPoint::y */

undefined8 BSim_QPoint__y(long param_1)

{
  return *(undefined8 *)(param_1 + 0xa8);
}


// ==== entry=00c869a0 name=FUN_00c869a0 size=265 ====

long FUN_00c869a0(long param_1,long param_2)

{
  undefined8 uVar1;
  int iVar2;
  char cVar3;
  long lVar4;
  undefined8 *puVar5;
  undefined8 *puVar6;
  undefined8 auStack_288 [19];
  long local_1f0;
  undefined8 local_1c8;
  undefined8 local_1b8;
  undefined8 local_198;
  undefined4 local_190 [72];
  undefined8 local_70;
  undefined2 local_68;
  int local_58;
  undefined2 local_30;
  undefined8 local_20;
  
  local_1f0 = param_1 + 1;
  puVar5 = &local_198;
  puVar6 = auStack_288;
  for (lVar4 = 0x1e; lVar4 != 0; lVar4 = lVar4 + -1) {
    *puVar6 = 0;
    puVar6 = puVar6 + 1;
  }
  local_1c8 = 0x4000000000000000;
  iVar2 = FUN_00c850a0(auStack_288,puVar5);
  if ((iVar2 != 0) || (local_58 == 2)) {
    return 0;
  }
  lVar4 = 0;
  do {
    while( true ) {
      cVar3 = (char)*(undefined4 *)(puVar5 + 1);
      *(char *)(param_2 + 0xb4 + lVar4) = cVar3;
      if ((cVar3 != '\x01') && (cVar3 != '\x02')) break;
      uVar1 = *puVar5;
      puVar5 = puVar5 + 2;
      *(undefined8 *)(param_2 + 0x20 + lVar4 * 8) = uVar1;
      lVar4 = lVar4 + 1;
      if (lVar4 == 0x12) goto LAB_00c86a51;
    }
    *(undefined8 *)(param_2 + 0x20 + lVar4 * 8) = 0;
    lVar4 = lVar4 + 1;
    puVar5 = puVar5 + 2;
  } while (lVar4 != 0x12);
LAB_00c86a51:
  *(undefined8 *)(param_2 + 0x10) = local_70;
  *(undefined2 *)(param_2 + 0xb0) = local_68;
  *(undefined2 *)(param_2 + 0xb2) = local_30;
  *(undefined8 *)(param_2 + 0x18) = local_1b8;
  *(undefined8 *)(param_2 + 8) = local_20;
  return param_2;
}


// ==== entry=00c86ab0 orig=FUN_00c86ab0 size=1 name=BSim_QList_int_::node_destruct ====

/* BSim sim=1.0 sig=8.379975367083091 ref=libsplitter.so.1.0.0::QList<int>::node_destruct */

void BSim_QList_int___node_destruct(void)

{
  return;
}


// ==== entry=00c86ac0 name=FUN_00c86ac0 size=753 ====

undefined8 FUN_00c86ac0(undefined8 *param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  undefined8 in_RAX;
  undefined8 uVar2;
  long lVar3;
  undefined8 unaff_retaddr;
  undefined8 local_3a8;
  undefined8 uStack_3a0;
  undefined8 local_398;
  undefined8 uStack_390;
  undefined8 local_388;
  undefined8 uStack_380;
  undefined8 local_378;
  undefined8 uStack_370;
  undefined8 local_368;
  undefined8 uStack_360;
  undefined8 local_358;
  undefined8 uStack_350;
  undefined8 local_348;
  undefined8 uStack_340;
  undefined8 local_338;
  undefined8 uStack_330;
  undefined8 local_328;
  undefined8 uStack_320;
  long local_318;
  undefined8 uStack_310;
  undefined8 local_308;
  undefined8 uStack_300;
  undefined8 local_2f8;
  undefined8 uStack_2f0;
  long local_2e8;
  undefined8 uStack_2e0;
  undefined8 local_2d8;
  undefined8 uStack_2d0;
  undefined8 local_2c8;
  undefined8 uStack_2c0;
  undefined8 local_2b8;
  undefined8 uStack_2b0;
  undefined8 local_2a8;
  undefined8 uStack_2a0;
  undefined8 local_298;
  undefined8 uStack_290;
  undefined8 local_288;
  undefined8 uStack_280;
  undefined8 local_278;
  undefined8 uStack_270;
  undefined8 local_268;
  undefined8 uStack_260;
  undefined8 local_258;
  undefined8 uStack_250;
  undefined8 local_248;
  undefined8 uStack_240;
  undefined8 local_238;
  undefined8 uStack_230;
  long local_228;
  undefined8 uStack_220;
  undefined8 local_218;
  undefined8 uStack_210;
  undefined8 local_208;
  undefined8 uStack_200;
  long local_1f8;
  undefined8 uStack_1f0;
  undefined8 local_1e8;
  undefined8 uStack_1e0;
  undefined8 local_1d8;
  undefined8 uStack_1d0;
  undefined1 local_1c8 [336];
  code *local_78;
  undefined8 local_40;
  undefined8 local_38;
  
  local_40 = in_RAX;
  local_38 = param_3;
  FUN_00c86290(&local_3a8,&stack0x00000008,unaff_retaddr);
  local_2b8 = local_3a8;
  uStack_2b0 = uStack_3a0;
  local_2a8 = local_398;
  uStack_2a0 = uStack_390;
  local_298 = local_388;
  uStack_290 = uStack_380;
  local_288 = local_378;
  uStack_280 = uStack_370;
  local_278 = local_368;
  uStack_270 = uStack_360;
  local_268 = local_358;
  uStack_260 = uStack_350;
  local_258 = local_348;
  uStack_250 = uStack_340;
  local_248 = local_338;
  uStack_240 = uStack_330;
  local_238 = local_328;
  uStack_230 = uStack_320;
  local_228 = local_318;
  uStack_220 = uStack_310;
  local_218 = local_308;
  uStack_210 = uStack_300;
  local_208 = local_2f8;
  uStack_200 = uStack_2f0;
  local_1f8 = local_2e8;
  uStack_1f0 = uStack_2e0;
  local_1e8 = local_2d8;
  uStack_1e0 = uStack_2d0;
  local_1d8 = local_2c8;
  uStack_1d0 = uStack_2c0;
  do {
    uVar2 = FUN_00c850a0(&local_2b8,local_1c8);
    if ((int)uVar2 == 5) {
      return uVar2;
    }
    if ((int)uVar2 != 0) {
      return 3;
    }
    if (local_78 != (code *)0x0) {
      iVar1 = (*local_78)(1,1,*param_1,param_1,&local_2b8);
      if (iVar1 == 6) {
        param_1[2] = 0;
        local_2b8 = local_3a8;
        uStack_2b0 = uStack_3a0;
        local_268 = local_358;
        uStack_260 = uStack_350;
        local_2a8 = local_398;
        uStack_2a0 = uStack_390;
        param_1[3] = local_228 + (local_1f8 >> 0x3f);
        local_298 = local_388;
        uStack_290 = uStack_380;
        local_258 = local_348;
        uStack_250 = uStack_340;
        local_288 = local_378;
        uStack_280 = uStack_370;
        local_248 = local_338;
        uStack_240 = uStack_330;
        local_278 = local_368;
        uStack_270 = uStack_360;
        local_238 = local_328;
        uStack_230 = uStack_320;
        local_228 = local_318;
        uStack_220 = uStack_310;
        local_218 = local_308;
        uStack_210 = uStack_300;
        local_208 = local_2f8;
        uStack_200 = uStack_2f0;
        local_1f8 = local_2e8;
        uStack_1f0 = uStack_2e0;
        local_1e8 = local_2d8;
        uStack_1e0 = uStack_2d0;
        local_1d8 = local_2c8;
        uStack_1d0 = uStack_2c0;
        uVar2 = FUN_00c864a0(param_1,&local_2b8,local_1c8);
        if ((int)uVar2 == 7) {
          FUN_00c86680(&local_3a8,&local_2b8);
          lVar3 = BSim_QList_int___node_destruct(local_228,uStack_220);
          *(undefined8 *)(&stack0x00000000 + lVar3) = uStack_220;
          return local_40;
        }
        return uVar2;
      }
      if (iVar1 != 8) {
        return 3;
      }
    }
    FUN_00c86410(&local_2b8,local_1c8);
  } while( true );
}


// ==== entry=00c86dd0 name=FUN_00c86dd0 size=409 ====

undefined8 FUN_00c86dd0(long param_1,undefined8 param_2,undefined8 param_3)

{
  undefined8 in_RAX;
  undefined8 uVar1;
  long lVar2;
  undefined8 unaff_retaddr;
  undefined1 local_230 [8];
  undefined8 local_228;
  undefined8 uStack_220;
  undefined8 local_218;
  undefined8 uStack_210;
  undefined8 local_208;
  undefined8 uStack_200;
  undefined8 local_1f8;
  undefined8 uStack_1f0;
  undefined8 local_1e8;
  undefined8 uStack_1e0;
  undefined8 local_1d8;
  undefined8 uStack_1d0;
  undefined8 local_1c8;
  undefined8 uStack_1c0;
  undefined8 local_1b8;
  undefined8 uStack_1b0;
  undefined8 local_1a8;
  undefined8 uStack_1a0;
  undefined8 local_198;
  undefined8 uStack_190;
  undefined8 local_188;
  undefined8 uStack_180;
  undefined8 local_178;
  undefined8 uStack_170;
  undefined8 local_168;
  undefined8 uStack_160;
  undefined8 local_158;
  undefined8 uStack_150;
  undefined8 local_148;
  undefined8 uStack_140;
  undefined8 local_138;
  undefined8 uStack_130;
  undefined8 local_128;
  undefined8 uStack_120;
  undefined8 local_118;
  undefined8 uStack_110;
  undefined8 local_108;
  undefined8 uStack_100;
  undefined8 local_f8;
  undefined8 uStack_f0;
  undefined8 local_e8;
  undefined8 uStack_e0;
  undefined8 local_d8;
  undefined8 uStack_d0;
  undefined8 local_c8;
  undefined8 uStack_c0;
  undefined8 local_b8;
  undefined8 uStack_b0;
  undefined8 local_a8;
  undefined8 uStack_a0;
  undefined8 local_98;
  undefined8 uStack_90;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_40;
  undefined8 local_38;
  
  local_40 = in_RAX;
  local_38 = param_3;
  FUN_00c86290(&local_228,&stack0x00000008,unaff_retaddr);
  *(undefined8 *)(param_1 + 0x18) = param_3;
  *(undefined8 *)(param_1 + 0x10) = param_2;
  local_138 = local_228;
  uStack_130 = uStack_220;
  local_128 = local_218;
  uStack_120 = uStack_210;
  local_118 = local_208;
  uStack_110 = uStack_200;
  local_108 = local_1f8;
  uStack_100 = uStack_1f0;
  local_f8 = local_1e8;
  uStack_f0 = uStack_1e0;
  local_e8 = local_1d8;
  uStack_e0 = uStack_1d0;
  local_d8 = local_1c8;
  uStack_d0 = uStack_1c0;
  local_c8 = local_1b8;
  uStack_c0 = uStack_1b0;
  local_b8 = local_1a8;
  uStack_b0 = uStack_1a0;
  local_a8 = local_198;
  uStack_a0 = uStack_190;
  local_98 = local_188;
  uStack_90 = uStack_180;
  local_88 = local_178;
  uStack_80 = uStack_170;
  local_78 = local_168;
  uStack_70 = uStack_160;
  local_68 = local_158;
  uStack_60 = uStack_150;
  local_58 = local_148;
  uStack_50 = uStack_140;
  uVar1 = FUN_00c86570(param_1,&local_138,local_230);
  if ((int)uVar1 != 7) {
    return uVar1;
  }
  FUN_00c86680(&local_228,&local_138);
  lVar2 = BSim_QList_int___node_destruct(local_a8,uStack_a0);
  *(undefined8 *)(&stack0x00000000 + lVar2) = uStack_a0;
  return local_40;
}


// ==== entry=00c86f70 orig=FUN_00c86f70 size=391 name=cxa_throw_exception ====

undefined1  [16] cxa_throw_exception(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  undefined8 in_RAX;
  undefined1 auVar2 [16];
  undefined8 unaff_retaddr;
  undefined1 local_230 [8];
  undefined8 local_228;
  undefined8 uStack_220;
  undefined8 local_218;
  undefined8 uStack_210;
  undefined8 local_208;
  undefined8 uStack_200;
  undefined8 local_1f8;
  undefined8 uStack_1f0;
  undefined8 local_1e8;
  undefined8 uStack_1e0;
  undefined8 local_1d8;
  undefined8 uStack_1d0;
  undefined8 local_1c8;
  undefined8 uStack_1c0;
  undefined8 local_1b8;
  undefined8 uStack_1b0;
  undefined8 local_1a8;
  undefined8 uStack_1a0;
  undefined8 local_198;
  undefined8 uStack_190;
  undefined8 local_188;
  undefined8 uStack_180;
  undefined8 local_178;
  undefined8 uStack_170;
  undefined8 local_168;
  undefined8 uStack_160;
  undefined8 local_158;
  undefined8 uStack_150;
  undefined8 local_148;
  undefined8 uStack_140;
  undefined8 local_138;
  undefined8 uStack_130;
  undefined8 local_128;
  undefined8 uStack_120;
  undefined8 local_118;
  undefined8 uStack_110;
  undefined8 local_108;
  undefined8 uStack_100;
  undefined8 local_f8;
  undefined8 uStack_f0;
  undefined8 local_e8;
  undefined8 uStack_e0;
  undefined8 local_d8;
  undefined8 uStack_d0;
  undefined8 local_c8;
  undefined8 uStack_c0;
  undefined8 local_b8;
  undefined8 uStack_b0;
  undefined8 local_a8;
  undefined8 uStack_a0;
  undefined8 local_98;
  undefined8 uStack_90;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_40;
  undefined8 local_38;
  
  local_40 = in_RAX;
  local_38 = param_3;
  FUN_00c86290(&local_228,&stack0x00000008,unaff_retaddr);
  local_138 = local_228;
  uStack_130 = uStack_220;
  local_128 = local_218;
  uStack_120 = uStack_210;
  local_118 = local_208;
  uStack_110 = uStack_200;
  local_108 = local_1f8;
  uStack_100 = uStack_1f0;
  local_f8 = local_1e8;
  uStack_f0 = uStack_1e0;
  local_e8 = local_1d8;
  uStack_e0 = uStack_1d0;
  local_d8 = local_1c8;
  uStack_d0 = uStack_1c0;
  local_c8 = local_1b8;
  uStack_c0 = uStack_1b0;
  local_b8 = local_1a8;
  uStack_b0 = uStack_1a0;
  local_a8 = local_198;
  uStack_a0 = uStack_190;
  local_98 = local_188;
  uStack_90 = uStack_180;
  local_88 = local_178;
  uStack_80 = uStack_170;
  local_78 = local_168;
  uStack_70 = uStack_160;
  local_68 = local_158;
  uStack_60 = uStack_150;
  local_58 = local_148;
  uStack_50 = uStack_140;
  if (*(long *)(param_1 + 0x10) == 0) {
    iVar1 = FUN_00c864a0();
  }
  else {
    iVar1 = FUN_00c86570(param_1,&local_138,local_230);
  }
  if (iVar1 == 7) {
    FUN_00c86680(&local_228,&local_138);
    auVar2 = BSim_QList_int___node_destruct(local_a8,uStack_a0);
    *(long *)(&stack0x00000000 + auVar2._0_8_) = auVar2._8_8_;
    auVar2._8_8_ = local_38;
    auVar2._0_8_ = local_40;
    return auVar2;
  }
                    /* WARNING: Subroutine does not return */
  abort();
}


// ==== entry=00c87100 name=FUN_00c87100 size=415 ====

undefined1  [16] FUN_00c87100(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  undefined8 in_RAX;
  long lVar2;
  undefined1 auVar3 [16];
  undefined8 unaff_retaddr;
  undefined1 local_230 [8];
  undefined8 local_228;
  undefined8 uStack_220;
  undefined8 local_218;
  undefined8 uStack_210;
  undefined8 local_208;
  undefined8 uStack_200;
  undefined8 local_1f8;
  undefined8 uStack_1f0;
  undefined8 local_1e8;
  undefined8 uStack_1e0;
  undefined8 local_1d8;
  undefined8 uStack_1d0;
  undefined8 local_1c8;
  undefined8 uStack_1c0;
  undefined8 local_1b8;
  undefined8 uStack_1b0;
  undefined8 local_1a8;
  undefined8 uStack_1a0;
  undefined8 local_198;
  undefined8 uStack_190;
  undefined8 local_188;
  undefined8 uStack_180;
  undefined8 local_178;
  undefined8 uStack_170;
  undefined8 local_168;
  undefined8 uStack_160;
  undefined8 local_158;
  undefined8 uStack_150;
  undefined8 local_148;
  undefined8 uStack_140;
  undefined8 local_138;
  undefined8 uStack_130;
  undefined8 local_128;
  undefined8 uStack_120;
  undefined8 local_118;
  undefined8 uStack_110;
  undefined8 local_108;
  undefined8 uStack_100;
  undefined8 local_f8;
  undefined8 uStack_f0;
  undefined8 local_e8;
  undefined8 uStack_e0;
  undefined8 local_d8;
  undefined8 uStack_d0;
  undefined8 local_c8;
  undefined8 uStack_c0;
  undefined8 local_b8;
  undefined8 uStack_b0;
  undefined8 local_a8;
  undefined8 uStack_a0;
  undefined8 local_98;
  undefined8 uStack_90;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_40;
  undefined8 local_38;
  
  local_38 = param_3;
  if (*(long *)(param_1 + 0x10) == 0) {
    auVar3 = FUN_00c86ac0();
    return auVar3;
  }
  local_40 = in_RAX;
  FUN_00c86290(&local_228,&stack0x00000008,unaff_retaddr);
  local_138 = local_228;
  uStack_130 = uStack_220;
  local_128 = local_218;
  uStack_120 = uStack_210;
  local_118 = local_208;
  uStack_110 = uStack_200;
  local_108 = local_1f8;
  uStack_100 = uStack_1f0;
  local_f8 = local_1e8;
  uStack_f0 = uStack_1e0;
  local_e8 = local_1d8;
  uStack_e0 = uStack_1d0;
  local_d8 = local_1c8;
  uStack_d0 = uStack_1c0;
  local_c8 = local_1b8;
  uStack_c0 = uStack_1b0;
  local_b8 = local_1a8;
  uStack_b0 = uStack_1a0;
  local_a8 = local_198;
  uStack_a0 = uStack_190;
  local_98 = local_188;
  uStack_90 = uStack_180;
  local_88 = local_178;
  uStack_80 = uStack_170;
  local_78 = local_168;
  uStack_70 = uStack_160;
  local_68 = local_158;
  uStack_60 = uStack_150;
  local_58 = local_148;
  uStack_50 = uStack_140;
  iVar1 = FUN_00c86570(param_1,&local_138,local_230);
  if (iVar1 == 7) {
    FUN_00c86680(&local_228,&local_138);
    lVar2 = BSim_QList_int___node_destruct(local_a8,uStack_a0);
    *(undefined8 *)(&stack0x00000000 + lVar2) = uStack_a0;
    auVar3._8_8_ = local_38;
    auVar3._0_8_ = local_40;
    return auVar3;
  }
                    /* WARNING: Subroutine does not return */
  abort();
}


// ==== entry=00c872b0 name=FUN_00c872b0 size=20 ====

void FUN_00c872b0(long param_1)

{
  if (*(code **)(param_1 + 8) != (code *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x00c872c1. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(param_1 + 8))(1,param_1);
    return;
  }
  return;
}


// ==== entry=00c872d0 name=FUN_00c872d0 size=134 ====

undefined4 FUN_00c872d0(code *param_1,undefined8 param_2)

{
  int iVar1;
  int iVar2;
  undefined8 unaff_retaddr;
  undefined1 local_2a8 [240];
  undefined1 local_1b8 [392];
  
  FUN_00c86290(local_2a8,&stack0x00000008,unaff_retaddr);
  while (((iVar2 = FUN_00c850a0(local_2a8,local_1b8), iVar2 == 0 || (iVar2 == 5)) &&
         (iVar1 = (*param_1)(local_2a8,param_2), iVar1 == 0))) {
    if (iVar2 == 5) {
      return 5;
    }
    FUN_00c86410(local_2a8,local_1b8);
  }
  return 3;
}


// ==== entry=00c87360 name=FUN_00c87360 size=18 ====

int FUN_00c87360(undefined8 param_1,long param_2,long param_3)

{
  int iVar1;
  
  iVar1 = 1;
  if (*(ulong *)(param_2 + 8) <= *(ulong *)(param_3 + 8)) {
    iVar1 = -(uint)(*(ulong *)(param_2 + 8) < *(ulong *)(param_3 + 8));
  }
  return iVar1;
}


// ==== entry=00c87380 name=FUN_00c87380 size=183 ====

void FUN_00c87380(undefined8 param_1,code *param_2,long param_3,int param_4,int param_5)

{
  undefined8 *puVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined8 uVar5;
  undefined8 *puVar6;
  
  while( true ) {
    iVar4 = param_4 * 2 + 1;
    if (param_5 <= iVar4) {
      return;
    }
    iVar3 = param_4 * 2 + 2;
    puVar6 = (undefined8 *)(param_3 + (long)iVar4 * 8);
    uVar5 = *puVar6;
    if (iVar3 < param_5) {
      puVar1 = (undefined8 *)(param_3 + 8 + (long)iVar4 * 8);
      iVar2 = (*param_2)(param_1,uVar5,*puVar1);
      if (iVar2 < 0) {
        uVar5 = *puVar1;
        puVar6 = puVar1;
        iVar4 = iVar3;
      }
      else {
        uVar5 = *puVar6;
      }
    }
    puVar1 = (undefined8 *)(param_3 + (long)param_4 * 8);
    iVar3 = (*param_2)(param_1,*puVar1,uVar5);
    if (-1 < iVar3) break;
    uVar5 = *puVar1;
    *puVar1 = *puVar6;
    *puVar6 = uVar5;
    param_4 = iVar4;
  }
  return;
}


// ==== entry=00c87440 name=FUN_00c87440 size=164 ====

void FUN_00c87440(undefined8 param_1,undefined8 param_2,long param_3)

{
  undefined8 uVar1;
  int iVar2;
  int iVar3;
  ulong uVar4;
  ulong uVar5;
  undefined4 local_40;
  
  uVar4 = *(ulong *)(param_3 + 8);
  iVar2 = (int)(uVar4 >> 1) + -1;
  if (-1 < iVar2) {
    do {
      iVar3 = iVar2 + -1;
      FUN_00c87380(param_1,param_2,param_3 + 0x10,iVar2,uVar4 & 0xffffffff);
      iVar2 = iVar3;
    } while (iVar3 != -1);
  }
  local_40 = (int)uVar4;
  local_40 = local_40 + -1;
  uVar4 = (ulong)local_40;
  while (0 < local_40) {
    uVar1 = *(undefined8 *)(param_3 + 0x10);
    uVar5 = uVar4 & 0xffffffff;
    *(undefined8 *)(param_3 + 0x10) = *(undefined8 *)(param_3 + 0x10 + uVar4 * 8);
    *(undefined8 *)(param_3 + 0x10 + uVar4 * 8) = uVar1;
    uVar4 = uVar4 - 1;
    FUN_00c87380(param_1,param_2,param_3 + 0x10,0,uVar5);
    local_40 = (int)uVar4;
  }
  return;
}


// ==== entry=00c874f0 name=FUN_00c874f0 size=61 ====

undefined8 FUN_00c874f0(byte param_1)

{
  if (param_1 == 0xff) {
    return 0;
  }
  param_1 = param_1 & 7;
  if (param_1 == 2) {
    return 2;
  }
  if (param_1 < 3) {
    if (param_1 != 0) goto LAB_00c87525;
  }
  else {
    if (param_1 == 3) {
      return 4;
    }
    if (param_1 != 4) {
LAB_00c87525:
                    /* WARNING: Subroutine does not return */
      abort();
    }
  }
  return 8;
}


// ==== entry=00c87550 name=FUN_00c87550 size=59 ====

undefined8 FUN_00c87550(byte param_1,long param_2)

{
  if (param_1 != 0xff) {
    param_1 = param_1 & 0x70;
    if (param_1 == 0x20) {
      return *(undefined8 *)(param_2 + 8);
    }
    if (param_1 < 0x21) {
      if ((param_1 != 0) && (param_1 != 0x10)) goto LAB_00c8758b;
    }
    else {
      if (param_1 == 0x30) {
        return *(undefined8 *)(param_2 + 0x10);
      }
      if (param_1 != 0x50) {
LAB_00c8758b:
                    /* WARNING: Subroutine does not return */
        abort();
      }
    }
  }
  return 0;
}


// ==== entry=00c875a0 name=FUN_00c875a0 size=59 ====

undefined8 FUN_00c875a0(byte param_1,long param_2)

{
  if (param_1 != 0xff) {
    param_1 = param_1 & 0x70;
    if (param_1 == 0x20) {
      return *(undefined8 *)(param_2 + 8);
    }
    if (param_1 < 0x21) {
      if ((param_1 != 0) && (param_1 != 0x10)) goto LAB_00c875db;
    }
    else {
      if (param_1 == 0x30) {
        return *(undefined8 *)(param_2 + 0x10);
      }
      if (param_1 != 0x50) {
LAB_00c875db:
                    /* WARNING: Subroutine does not return */
        abort();
      }
    }
  }
  return 0;
}


// ==== entry=00c875f0 orig=FUN_00c875f0 size=289 name=dwarf_read_encoded_pointer ====

ulong * dwarf_read_encoded_pointer(byte param_1,ulong *param_2,ulong *param_3,undefined8 *param_4)

{
  ulong uVar1;
  undefined8 *puVar2;
  ulong *puVar3;
  byte bVar5;
  byte bVar6;
  uint uVar7;
  byte *pbVar8;
  ulong uVar9;
  ulong *puVar4;
  
  if (param_1 == 0x50) {
    puVar2 = (undefined8 *)((ulong)((long)param_3 + 7U) & 0xfffffffffffffff8);
    *param_4 = *puVar2;
    return puVar2 + 1;
  }
  switch(param_1 & 0xf) {
  case 0:
  case 4:
  case 0xc:
    uVar9 = *param_3;
    puVar3 = param_3 + 1;
    break;
  case 1:
    uVar9 = 0;
    bVar5 = 0;
    puVar4 = param_3;
    do {
      puVar3 = (ulong *)((long)puVar4 + 1);
      uVar1 = *puVar4;
      bVar6 = bVar5 & 0x3f;
      bVar5 = bVar5 + 7;
      uVar9 = uVar9 | (ulong)((byte)uVar1 & 0x7f) << bVar6;
      puVar4 = puVar3;
    } while ((char)(byte)uVar1 < '\0');
    break;
  case 2:
    uVar9 = (ulong)(ushort)*param_3;
    puVar3 = (ulong *)((long)param_3 + 2);
    break;
  case 3:
    uVar9 = (ulong)(uint)*param_3;
    puVar3 = (ulong *)((long)param_3 + 4);
    break;
  default:
                    /* WARNING: Subroutine does not return */
    abort();
  case 9:
    uVar9 = 0;
    uVar7 = 0;
    puVar4 = param_3;
    do {
      puVar3 = (ulong *)((long)puVar4 + 1);
      bVar5 = (byte)*puVar4;
      bVar6 = (byte)uVar7;
      uVar7 = uVar7 + 7;
      uVar9 = uVar9 | (ulong)(bVar5 & 0x7f) << (bVar6 & 0x3f);
      puVar4 = puVar3;
    } while ((char)bVar5 < '\0');
    if ((0x3f < uVar7) || ((bVar5 & 0x40) == 0)) break;
    uVar9 = uVar9 | -1L << ((byte)uVar7 & 0x3f);
    goto LAB_00c8762c;
  case 10:
    uVar9 = (ulong)(short)(ushort)*param_3;
    puVar3 = (ulong *)((long)param_3 + 2);
    break;
  case 0xb:
    uVar9 = (ulong)(int)(uint)*param_3;
    puVar3 = (ulong *)((long)param_3 + 4);
  }
  pbVar8 = (byte *)0x0;
  if (uVar9 != 0) {
LAB_00c8762c:
    if ((param_1 & 0x70) == 0x10) {
      param_2 = param_3;
    }
    pbVar8 = (byte *)(uVar9 + (long)param_2);
    if ((char)param_1 < '\0') {
      *param_4 = *(undefined8 *)pbVar8;
      return puVar3;
    }
  }
  *param_4 = pbVar8;
  return puVar3;
}


// ==== entry=00c87740 name=FUN_00c87740 size=124 ====

int FUN_00c87740(long param_1,long param_2,long param_3)

{
  int iVar1;
  undefined8 uVar2;
  undefined1 uVar3;
  ulong local_38;
  ulong local_30;
  
  uVar3 = (undefined1)(*(ushort *)(param_1 + 0x20) >> 3);
  uVar2 = FUN_00c87550(uVar3,param_1);
  dwarf_read_encoded_pointer(uVar3,uVar2,param_2 + 8,&local_38);
  dwarf_read_encoded_pointer((char)(*(ushort *)(param_1 + 0x20) >> 3),uVar2,param_3 + 8,&local_30);
  iVar1 = 1;
  if (local_38 <= local_30) {
    iVar1 = -(uint)(local_38 < local_30);
  }
  return iVar1;
}


// ==== entry=00c877c0 name=FUN_00c877c0 size=264 ====

byte FUN_00c877c0(long param_1)

{
  byte *pbVar1;
  byte bVar2;
  size_t sVar3;
  byte *pbVar4;
  byte *pbVar5;
  char cVar6;
  char *pcVar7;
  undefined1 local_20 [16];
  
  sVar3 = strlen((char *)(param_1 + 9));
  pbVar4 = (byte *)(param_1 + 10 + sVar3);
  if (3 < *(byte *)(param_1 + 8)) {
    if (*pbVar4 != 8) {
      return 0xff;
    }
    if (pbVar4[1] != 0) {
      return 0xff;
    }
    pbVar4 = pbVar4 + 2;
  }
  if (*(char *)(param_1 + 9) != 'z') {
    return 0;
  }
  do {
    pbVar5 = pbVar4 + 1;
    if (-1 < (char)*pbVar4) break;
    pbVar1 = pbVar4 + 1;
    pbVar5 = pbVar4 + 2;
    pbVar4 = pbVar4 + 2;
  } while ((char)*pbVar1 < '\0');
  do {
    pbVar4 = pbVar5;
    pbVar5 = pbVar4 + 1;
  } while ((char)*pbVar4 < '\0');
  if (*(byte *)(param_1 + 8) == 1) {
    pbVar4 = pbVar4 + 2;
  }
  else {
    do {
      pbVar4 = pbVar5 + 1;
      bVar2 = *pbVar5;
      pbVar5 = pbVar4;
    } while ((char)bVar2 < '\0');
  }
  pcVar7 = (char *)(param_1 + 10);
  do {
    pbVar5 = pbVar4 + 1;
    bVar2 = *pbVar4;
    pbVar4 = pbVar5;
  } while ((char)bVar2 < '\0');
  cVar6 = *(char *)(param_1 + 10);
  while (cVar6 != 'R') {
    while (cVar6 != 'P') {
      if (cVar6 != 'L') {
        return 0;
      }
      pcVar7 = pcVar7 + 1;
      cVar6 = *pcVar7;
      pbVar5 = pbVar5 + 1;
      if (cVar6 == 'R') goto LAB_00c878ae;
    }
    pcVar7 = pcVar7 + 1;
    pbVar5 = (byte *)dwarf_read_encoded_pointer(*pbVar5 & 0x7f,0,pbVar5 + 1,local_20);
    cVar6 = *pcVar7;
  }
LAB_00c878ae:
  return *pbVar5;
}


// ==== entry=00c87900 name=FUN_00c87900 size=373 ====

uint * FUN_00c87900(long param_1,uint *param_2,long param_3)

{
  uint uVar1;
  uint uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  long lVar5;
  ulong uVar6;
  long lVar7;
  ulong local_48;
  ulong local_40 [2];
  
  uVar1 = (uint)(byte)(*(ushort *)(param_1 + 0x20) >> 3);
  uVar3 = FUN_00c87550(uVar1,param_1);
  if (*param_2 != 0) {
    lVar7 = 0;
    do {
      if (param_2[1] != 0) {
        if (((*(byte *)(param_1 + 0x20) & 4) != 0) &&
           (lVar5 = (long)param_2 + (4 - (long)(int)param_2[1]), lVar5 != lVar7)) {
          uVar1 = FUN_00c877c0(lVar5);
          uVar3 = FUN_00c87550((char)uVar1,param_1);
          lVar7 = lVar5;
        }
        if (uVar1 == 0) {
          local_48 = *(ulong *)(param_2 + 2);
          local_40[0] = *(ulong *)(param_2 + 4);
          if ((local_48 != 0) && (param_3 - local_48 < local_40[0])) {
            return param_2;
          }
        }
        else {
          uVar4 = dwarf_read_encoded_pointer(uVar1 & 0xff,uVar3,param_2 + 2,&local_48);
          dwarf_read_encoded_pointer(uVar1 & 0xf,0,uVar4,local_40);
          uVar2 = FUN_00c874f0(uVar1 & 0xff);
          uVar6 = 0xffffffffffffffff;
          if (uVar2 < 8) {
            uVar6 = (1L << ((char)uVar2 * '\b' & 0x3fU)) - 1;
          }
          if (((local_48 & uVar6) != 0) && (param_3 - local_48 < local_40[0])) {
            return param_2;
          }
        }
      }
      param_2 = (uint *)((long)param_2 + (ulong)*param_2 + 4);
    } while (*param_2 != 0);
  }
  return (uint *)0x0;
}


// ==== entry=00c87a90 name=FUN_00c87a90 size=1155 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_00c87a90(ulong *param_1,ulong param_2,ulong *param_3)

{
  int *piVar1;
  char cVar2;
  int iVar3;
  ulong *puVar4;
  bool bVar5;
  int *piVar6;
  undefined1 uVar7;
  byte bVar8;
  uint uVar9;
  ulong *puVar10;
  undefined8 uVar11;
  ulong uVar12;
  undefined8 uVar13;
  int *piVar14;
  undefined8 *puVar15;
  char *pcVar16;
  int *piVar17;
  ulong uVar18;
  ulong uVar19;
  int *piVar20;
  ulong uVar21;
  ulong *puVar22;
  char *pcVar23;
  ulong *local_80;
  undefined8 local_78;
  ulong local_70;
  long local_68;
  ulong local_60;
  ulong local_58;
  undefined8 local_50;
  undefined8 local_48;
  
  puVar10 = DAT_011c6770;
  piVar14 = (int *)param_1[2];
  uVar12 = *param_1;
  if (((int)param_3[5] == 0) || (param_2 < 0x30)) {
    if (param_2 < 0x1a) {
      return 0xffffffff;
    }
  }
  else {
    if ((param_1[4] != DAT_011c0ac0) || (DAT_011c6768 != param_1[5])) {
      puVar15 = &DAT_011c67b0;
      DAT_011c0ac0 = param_1[4];
      DAT_011c6768 = param_1[5];
      do {
        puVar15[-6] = 0;
        puVar15[-5] = 0;
        puVar15[-1] = puVar15;
        puVar15 = puVar15 + 6;
      } while (puVar15 != &DAT_011c6930);
      puVar22 = (ulong *)0x0;
      _DAT_011c68f8 = 0;
      DAT_011c6770 = &DAT_011c6780;
      *(undefined4 *)(param_3 + 5) = 0;
      local_80 = (ulong *)0x0;
      goto LAB_00c87acc;
    }
    if (DAT_011c6770 != (ulong *)0x0) {
      uVar18 = *DAT_011c6770;
      uVar19 = DAT_011c6770[1];
      local_80 = (ulong *)0x0;
      puVar22 = DAT_011c6770;
      while( true ) {
        if ((uVar18 <= *param_3) && (*param_3 < uVar19)) {
          uVar12 = puVar22[2];
          piVar17 = (int *)puVar22[3];
          if (DAT_011c6770 != puVar22) {
            DAT_011c6770 = puVar22;
            local_80[5] = puVar22[5];
            puVar22[5] = (ulong)puVar10;
          }
          goto LAB_00c87ba8;
        }
        if ((uVar18 == 0 && uVar19 == 0) || (puVar4 = (ulong *)puVar22[5], puVar4 == (ulong *)0x0))
        break;
        uVar18 = *puVar4;
        uVar19 = puVar4[1];
        local_80 = puVar22;
        puVar22 = puVar4;
      }
      goto LAB_00c87acc;
    }
  }
  local_80 = (ulong *)0x0;
  puVar22 = (ulong *)0x0;
LAB_00c87acc:
  puVar10 = DAT_011c6770;
  if ((ushort)param_1[3] == 0) {
    return 0;
  }
  uVar18 = 0;
  uVar19 = 0;
  bVar5 = false;
  piVar20 = (int *)0x0;
  piVar17 = (int *)0x0;
  piVar1 = piVar14 + (ulong)(ushort)param_1[3] * 0xe;
  do {
    iVar3 = *piVar14;
    piVar6 = piVar17;
    if (iVar3 == 1) {
      uVar21 = *(long *)(piVar14 + 4) + uVar12;
      if ((uVar21 <= *param_3) && (*param_3 < *(long *)(piVar14 + 10) + uVar21)) {
        bVar5 = true;
        uVar18 = *(long *)(piVar14 + 10) + uVar21;
        uVar19 = uVar21;
      }
    }
    else {
      piVar6 = piVar14;
      if ((iVar3 != 0x6474e550) && (piVar6 = piVar17, iVar3 == 2)) {
        piVar20 = piVar14;
      }
    }
    piVar17 = piVar6;
    piVar14 = piVar14 + 0xe;
  } while (piVar14 != piVar1);
  if (!bVar5) {
    return 0;
  }
  if (0x2f < param_2) {
    if ((puVar22 != (ulong *)0x0) && (local_80 != (ulong *)0x0)) {
      DAT_011c6770 = puVar22;
      local_80[5] = puVar22[5];
      puVar22[5] = (ulong)puVar10;
      puVar10 = puVar22;
    }
    puVar10[2] = uVar12;
    puVar10[3] = (ulong)piVar17;
    puVar10[4] = (ulong)piVar20;
    *puVar10 = uVar19;
    puVar10[1] = uVar18;
  }
LAB_00c87ba8:
  if (piVar17 == (int *)0x0) {
    return 0;
  }
  pcVar16 = (char *)(*(long *)(piVar17 + 4) + uVar12);
  if (*pcVar16 != '\x01') {
    return 1;
  }
  cVar2 = pcVar16[1];
  uVar11 = FUN_00c875a0(cVar2,param_3);
  uVar11 = dwarf_read_encoded_pointer(cVar2,uVar11,pcVar16 + 4,&local_78);
  cVar2 = pcVar16[2];
  if ((cVar2 == -1) || (pcVar16[3] != ';')) {
    pcVar23 = (char *)*param_3;
  }
  else {
    uVar13 = FUN_00c875a0(cVar2,param_3);
    piVar14 = (int *)dwarf_read_encoded_pointer(cVar2,uVar13,uVar11,&local_70);
    if (local_70 == 0) {
      return 1;
    }
    pcVar23 = (char *)*param_3;
    uVar12 = (ulong)((uint)piVar14 & 3);
    if (((ulong)piVar14 & 3) == 0) {
      if (pcVar23 < pcVar16 + *piVar14) {
        return 1;
      }
      uVar18 = local_70 - 1;
      uVar19 = uVar18;
      if (pcVar23 < pcVar16 + piVar14[uVar18 * 2]) {
        do {
          if (uVar19 <= uVar12) {
LAB_00c87e95:
                    /* WARNING: Subroutine does not return */
            abort();
          }
          uVar21 = uVar12 + uVar19 >> 1;
          iVar3 = piVar14[uVar21 * 2];
          while (uVar18 = uVar21, pcVar23 < pcVar16 + iVar3) {
            if (uVar18 <= uVar12) goto LAB_00c87e95;
            uVar21 = uVar12 + uVar18 >> 1;
            iVar3 = piVar14[uVar21 * 2];
            uVar19 = uVar18;
          }
          uVar12 = uVar18 + 1;
        } while (pcVar16 + piVar14[uVar12 * 2] <= pcVar23);
      }
      pcVar23 = pcVar16 + (piVar14 + uVar18 * 2)[1];
      bVar8 = FUN_00c877c0(pcVar23 + (4 - (long)*(int *)(pcVar23 + 4)));
      uVar9 = FUN_00c874f0(bVar8);
      dwarf_read_encoded_pointer(bVar8 & 0xf,0,pcVar23 + (ulong)uVar9 + 8,&local_68);
      iVar3 = piVar14[uVar18 * 2];
      if ((char *)*param_3 < pcVar16 + iVar3 + local_68) {
        param_3[4] = (ulong)pcVar23;
      }
      param_3[3] = (ulong)(pcVar16 + iVar3);
      return 1;
    }
  }
  local_60 = param_3[1];
  local_68 = 0;
  local_48 = 4;
  local_58 = param_3[2];
  local_50 = local_78;
  uVar12 = FUN_00c87900(&local_68,local_78,pcVar23);
  param_3[4] = uVar12;
  if (uVar12 != 0) {
    uVar7 = FUN_00c877c0((uVar12 + 4) - (long)*(int *)(uVar12 + 4));
    uVar11 = FUN_00c875a0(uVar7,param_3);
    dwarf_read_encoded_pointer(uVar7,uVar11,param_3[4] + 8,&local_70);
    param_3[3] = local_70;
  }
  return 1;
}


// ==== entry=00c87f50 name=FUN_00c87f50 size=145 ====

int FUN_00c87f50(undefined8 param_1,long param_2,long param_3)

{
  undefined1 uVar1;
  int iVar2;
  undefined8 uVar3;
  ulong local_38;
  ulong local_30 [2];
  
  uVar1 = FUN_00c877c0((param_2 + 4) - (long)*(int *)(param_2 + 4));
  uVar3 = FUN_00c87550(uVar1,param_1);
  dwarf_read_encoded_pointer(uVar1,uVar3,param_2 + 8,&local_38);
  uVar1 = FUN_00c877c0((param_3 + 4) - (long)*(int *)(param_3 + 4));
  uVar3 = FUN_00c87550(uVar1,param_1);
  dwarf_read_encoded_pointer(uVar1,uVar3,param_3 + 8,local_30);
  iVar2 = 1;
  if (local_38 <= local_30[0]) {
    iVar2 = -(uint)(local_38 < local_30[0]);
  }
  return iVar2;
}


// ==== entry=00c87ff0 name=FUN_00c87ff0 size=325 ====

long FUN_00c87ff0(ulong *param_1,uint *param_2)

{
  ushort uVar1;
  uint uVar2;
  undefined8 uVar3;
  long lVar4;
  ulong uVar5;
  long lVar6;
  uint uVar7;
  long local_50;
  ulong local_40 [2];
  
  if (*param_2 == 0) {
    local_50 = 0;
  }
  else {
    uVar3 = 0;
    uVar2 = 0;
    local_50 = 0;
    lVar4 = 0;
    do {
      lVar6 = lVar4;
      if (param_2[1] != 0) {
        uVar7 = uVar2 & 0xff;
        lVar6 = (long)param_2 + (4 - (long)(int)param_2[1]);
        if (lVar6 != lVar4) {
          uVar2 = FUN_00c877c0(lVar6);
          if (uVar2 == 0xff) {
            return -1;
          }
          uVar7 = uVar2 & 0xff;
          uVar3 = FUN_00c87550(uVar7,param_1);
          uVar1 = (ushort)param_1[4];
          if ((uVar1 & 0x7f8) == 0x7f8) {
            *(ushort *)(param_1 + 4) = uVar1 & 0xf807 | (ushort)((uVar2 & 0xff) << 3);
          }
          else if ((byte)(uVar1 >> 3) != uVar2) {
            *(byte *)(param_1 + 4) = (byte)param_1[4] | 4;
          }
        }
        dwarf_read_encoded_pointer(uVar7,uVar3,param_2 + 2,local_40);
        uVar7 = FUN_00c874f0(uVar7);
        uVar5 = 0xffffffffffffffff;
        if (uVar7 < 8) {
          uVar5 = (1L << ((char)uVar7 * '\b' & 0x3fU)) - 1;
        }
        if (((local_40[0] & uVar5) != 0) && (local_50 = local_50 + 1, local_40[0] < *param_1)) {
          *param_1 = local_40[0];
        }
      }
      param_2 = (uint *)((long)param_2 + (ulong)*param_2 + 4);
      lVar4 = lVar6;
    } while (*param_2 != 0);
  }
  return local_50;
}


// ==== entry=00c88140 name=FUN_00c88140 size=307 ====

void FUN_00c88140(long param_1,long *param_2,uint *param_3)

{
  long lVar1;
  uint uVar2;
  uint uVar3;
  undefined8 uVar4;
  long lVar5;
  ulong uVar6;
  long lVar7;
  ulong local_40 [2];
  
  uVar2 = (uint)(byte)(*(ushort *)(param_1 + 0x20) >> 3);
  uVar4 = FUN_00c87550(uVar2,param_1);
  if (*param_3 != 0) {
    lVar7 = 0;
    do {
      while (param_3[1] != 0) {
        if (((*(byte *)(param_1 + 0x20) & 4) != 0) &&
           (lVar5 = (long)param_3 + (4 - (long)(int)param_3[1]), lVar5 != lVar7)) {
          uVar2 = FUN_00c877c0(lVar5);
          uVar4 = FUN_00c87550((char)uVar2,param_1);
          lVar7 = lVar5;
        }
        if (uVar2 == 0) {
          if (*(long *)(param_3 + 2) != 0) goto LAB_00c88197;
          break;
        }
        dwarf_read_encoded_pointer(uVar2 & 0xff,uVar4,param_3 + 2,local_40);
        uVar3 = FUN_00c874f0(uVar2 & 0xff);
        uVar6 = 0xffffffffffffffff;
        if (uVar3 < 8) {
          uVar6 = (1L << ((char)uVar3 * '\b' & 0x3fU)) - 1;
        }
        if ((local_40[0] & uVar6) != 0) {
LAB_00c88197:
          lVar5 = *param_2;
          if (lVar5 != 0) {
            lVar1 = *(long *)(lVar5 + 8);
            *(long *)(lVar5 + 8) = lVar1 + 1;
            *(uint **)(lVar5 + 0x10 + lVar1 * 8) = param_3;
          }
          break;
        }
        param_3 = (uint *)((long)param_3 + (ulong)*param_3 + 4);
        if (*param_3 == 0) {
          return;
        }
      }
      param_3 = (uint *)((long)param_3 + (ulong)*param_3 + 4);
    } while (*param_3 != 0);
  }
  return;
}


// ==== entry=00c88280 name=FUN_00c88280 size=1723 ====

long FUN_00c88280(ulong *param_1,ulong param_2)

{
  ulong *puVar1;
  size_t __size;
  undefined8 *puVar2;
  ulong uVar3;
  ulong *puVar4;
  void *pvVar5;
  byte bVar6;
  undefined1 uVar7;
  ushort uVar8;
  int iVar9;
  long lVar10;
  undefined8 uVar11;
  undefined8 uVar12;
  ulong uVar13;
  ulong uVar14;
  ulong uVar15;
  long *plVar16;
  code *pcVar17;
  ulong uVar18;
  long lVar19;
  long lVar20;
  ulong uVar21;
  undefined8 *puVar22;
  ulong local_88;
  ulong local_50;
  ulong *local_48;
  void *local_40;
  
  bVar6 = (byte)param_1[4];
  if ((bVar6 & 1) != 0) goto LAB_00c882a0;
  local_88 = (ulong)((uint)param_1[4] >> 0xb);
  if (local_88 == 0) {
    plVar16 = (long *)param_1[3];
    if ((bVar6 & 2) == 0) {
      local_88 = FUN_00c87ff0(param_1,plVar16);
      if (local_88 != 0xffffffffffffffff) goto LAB_00c884a7;
LAB_00c88381:
      param_1[4] = 0x7f8;
      param_1[3] = (ulong)&DAT_00d9a8e0;
    }
    else {
      local_88 = 0;
      if (*plVar16 != 0) {
        do {
          lVar10 = FUN_00c87ff0(param_1);
          if (lVar10 == -1) goto LAB_00c88381;
          plVar16 = plVar16 + 1;
          local_88 = local_88 + lVar10;
        } while (*plVar16 != 0);
LAB_00c884a7:
        if ((local_88 & 0xffffffffffe00000) == 0) {
          *(uint *)(param_1 + 4) = (uint)param_1[4] & 0x7ff | (int)local_88 << 0xb;
        }
        else {
          *(uint *)(param_1 + 4) = (uint)param_1[4] & 0x7ff;
        }
        if (local_88 != 0) goto LAB_00c885e8;
      }
    }
  }
  else {
LAB_00c885e8:
    __size = local_88 * 8 + 0x10;
    local_48 = malloc(__size);
    if (local_48 != (ulong *)0x0) {
      local_48[1] = 0;
      local_40 = malloc(__size);
      if (local_40 != (void *)0x0) {
        *(undefined8 *)((long)local_40 + 8) = 0;
      }
      plVar16 = (long *)param_1[3];
      if ((param_1[4] & 2) == 0) {
        FUN_00c88140(param_1,&local_48,plVar16);
      }
      else {
        if (*plVar16 == 0) goto LAB_00c889bc;
        do {
          plVar16 = plVar16 + 1;
          FUN_00c88140(param_1);
        } while (*plVar16 != 0);
      }
      pvVar5 = local_40;
      puVar4 = local_48;
      if ((local_48 != (ulong *)0x0) && (local_48[1] != local_88)) {
LAB_00c889bc:
                    /* WARNING: Subroutine does not return */
        abort();
      }
      pcVar17 = FUN_00c87f50;
      if (((param_1[4] & 4) == 0) && (pcVar17 = FUN_00c87360, (param_1[4] & 0x7f8) != 0)) {
        pcVar17 = FUN_00c87740;
      }
      if (local_40 == (void *)0x0) {
        FUN_00c87440(param_1,pcVar17,local_48);
      }
      else {
        uVar21 = local_48[1];
        if (uVar21 == 0) {
          lVar10 = 0;
          uVar14 = 0;
        }
        else {
          puVar1 = local_48 + 2;
          lVar10 = 0x10;
          puVar22 = &DAT_011c6760;
LAB_00c88710:
          *(undefined8 **)((long)pvVar5 + lVar10) = puVar22;
          puVar22 = (undefined8 *)((long)puVar4 + lVar10);
          if (uVar21 * 8 + 8 != lVar10) {
            while (puVar22 != &DAT_011c6760) {
              iVar9 = (*pcVar17)(param_1,*(undefined8 *)((long)puVar4 + lVar10 + 8),*puVar22);
              if (-1 < iVar9) {
                lVar10 = lVar10 + 8;
                goto LAB_00c88710;
              }
              puVar2 = *(undefined8 **)((long)pvVar5 + (long)puVar22 + (0x10 - (long)puVar1));
              *(undefined8 *)((long)pvVar5 + (long)puVar22 + (0x10 - (long)puVar1)) = 0;
              puVar22 = puVar2;
            }
            puVar22 = &DAT_011c6760;
            lVar10 = lVar10 + 8;
            goto LAB_00c88710;
          }
          lVar10 = 0;
          uVar14 = 0;
          uVar13 = 0;
          do {
            if (*(long *)((long)pvVar5 + uVar13 * 8 + 0x10) == 0) {
              *(ulong *)((long)pvVar5 + lVar10 * 8 + 0x10) = puVar4[uVar13 + 2];
              lVar10 = lVar10 + 1;
            }
            else {
              puVar4[uVar14 + 2] = puVar4[uVar13 + 2];
              uVar14 = uVar14 + 1;
            }
            uVar13 = uVar13 + 1;
          } while (uVar21 != uVar13);
        }
        puVar4[1] = uVar14;
        *(long *)((long)pvVar5 + 8) = lVar10;
        if (*(long *)((long)local_40 + 8) + local_48[1] != local_88) goto LAB_00c889bc;
        FUN_00c87440(param_1,pcVar17);
        pvVar5 = local_40;
        puVar4 = local_48;
        local_88 = *(long *)((long)local_40 + 8);
        if (local_88 != 0) {
          uVar21 = local_48[1];
          do {
            lVar10 = local_88 + -1;
            puVar1 = (ulong *)((long)pvVar5 + local_88 * 8);
            uVar14 = puVar1[1];
            if (uVar21 == 0) {
              puVar4[local_88 + 1] = uVar14;
              if (lVar10 == 0) break;
              uVar14 = *puVar1;
              lVar20 = local_88 + -2;
              local_88 = local_88 + -2;
            }
            else {
              lVar19 = local_88 + -1 + uVar21;
              do {
                uVar13 = uVar21 - 1;
                iVar9 = (*pcVar17)(param_1,puVar4[uVar21 + 1],uVar14);
                lVar20 = lVar19;
                local_88 = lVar10;
                if (iVar9 < 1) break;
                puVar4[lVar19 + 2] = puVar4[uVar21 + 1];
                lVar19 = lVar19 + -1;
                lVar20 = lVar10;
                uVar21 = uVar13;
              } while (uVar13 != 0);
            }
            puVar4[lVar20 + 2] = uVar14;
          } while (local_88 != 0);
          puVar4[1] = puVar4[1] + *(long *)((long)pvVar5 + 8);
        }
        free(local_40);
      }
      *local_48 = param_1[3];
      param_1[3] = (ulong)local_48;
      *(byte *)(param_1 + 4) = (byte)param_1[4] | 1;
    }
  }
  if (param_2 < *param_1) {
    return 0;
  }
  bVar6 = (byte)param_1[4];
  plVar16 = (long *)param_1[3];
  if ((bVar6 & 1) == 0) {
    if ((bVar6 & 2) == 0) {
      lVar10 = FUN_00c87900(param_1,plVar16,param_2);
      return lVar10;
    }
    lVar10 = *plVar16;
    while( true ) {
      if (lVar10 == 0) {
        return 0;
      }
      lVar10 = FUN_00c87900(param_1,lVar10,param_2);
      if (lVar10 != 0) break;
      plVar16 = plVar16 + 1;
      lVar10 = *plVar16;
    }
    return lVar10;
  }
LAB_00c882a0:
  uVar21 = param_1[3];
  uVar14 = *(ulong *)(uVar21 + 8);
  if ((bVar6 & 4) == 0) {
    uVar13 = 0;
    if (((ushort)param_1[4] & 0x7f8) == 0) {
      while (uVar13 < uVar14) {
        uVar15 = uVar13 + uVar14 >> 1;
        lVar10 = *(long *)(uVar21 + 0x10 + uVar15 * 8);
        lVar20 = *(long *)(lVar10 + 0x10);
        uVar18 = *(ulong *)(lVar10 + 8);
        while (uVar3 = uVar15, param_2 < uVar18) {
          if (uVar3 <= uVar13) {
            return 0;
          }
          uVar15 = uVar3 + uVar13 >> 1;
          lVar10 = *(long *)(uVar21 + 0x10 + uVar15 * 8);
          lVar20 = *(long *)(lVar10 + 0x10);
          uVar14 = uVar3;
          uVar18 = *(ulong *)(lVar10 + 8);
        }
        if (param_2 < uVar18 + lVar20) {
          return lVar10;
        }
        uVar13 = uVar3 + 1;
      }
    }
    else {
      uVar8 = (ushort)param_1[4] >> 3;
      uVar7 = (undefined1)uVar8;
      uVar11 = FUN_00c87550(uVar7,param_1);
      if (uVar14 != 0) {
        uVar13 = 0;
        do {
          uVar18 = uVar14 + uVar13 >> 1;
          lVar10 = *(long *)(uVar21 + 0x10 + uVar18 * 8);
          uVar12 = dwarf_read_encoded_pointer(uVar7,uVar11,lVar10 + 8,&local_50);
          dwarf_read_encoded_pointer(uVar8 & 0xf,0,uVar12,&local_48);
          if (local_50 <= param_2) {
            if (param_2 < local_50 + (long)local_48) {
              return lVar10;
            }
            uVar13 = uVar18 + 1;
            uVar18 = uVar14;
          }
          uVar14 = uVar18;
        } while (uVar13 < uVar18);
      }
    }
  }
  else if (uVar14 != 0) {
    uVar13 = 0;
    do {
      uVar18 = uVar14 + uVar13 >> 1;
      lVar10 = *(long *)(uVar21 + 0x10 + uVar18 * 8);
      bVar6 = FUN_00c877c0((lVar10 + 4) - (long)*(int *)(lVar10 + 4));
      uVar11 = FUN_00c87550(bVar6,param_1);
      uVar11 = dwarf_read_encoded_pointer(bVar6,uVar11,lVar10 + 8,&local_50);
      dwarf_read_encoded_pointer(bVar6 & 0xf,0,uVar11,&local_48);
      if (local_50 <= param_2) {
        if (param_2 < local_50 + (long)local_48) {
          return lVar10;
        }
        uVar13 = uVar18 + 1;
        uVar18 = uVar14;
      }
      uVar14 = uVar18;
    } while (uVar13 < uVar18);
  }
  return 0;
}


// ==== entry=00c889d0 name=FUN_00c889d0 size=130 ====

/* WARNING: Removing unreachable block (ram,0x00c88a40) */

void FUN_00c889d0(undefined8 param_1,undefined8 *param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 *puVar1;
  
  *param_2 = 0xffffffffffffffff;
  param_2[1] = param_3;
  param_2[2] = param_4;
  param_2[3] = param_1;
  param_2[4] = 0x7f8;
  pthread_mutex_lock((pthread_mutex_t *)&DAT_011c6900);
  puVar1 = param_2;
  param_2[5] = DAT_011c6938;
  DAT_011c6938 = puVar1;
  if (DAT_011c6928 == 0) {
    DAT_011c6928 = 1;
  }
  pthread_mutex_unlock((pthread_mutex_t *)&DAT_011c6900);
  return;
}


// ==== entry=00c88a60 name=FUN_00c88a60 size=17 ====

void FUN_00c88a60(int *param_1)

{
  if ((param_1 != (int *)0x0) && (*param_1 != 0)) {
    FUN_00c889d0();
    return;
  }
  return;
}


// ==== entry=00c88a80 name=FUN_00c88a80 size=21 ====

void FUN_00c88a80(int *param_1,undefined8 param_2)

{
  if ((param_1 != (int *)0x0) && (*param_1 != 0)) {
    FUN_00c889d0(param_1,param_2,0,0);
    return;
  }
  return;
}


// ==== entry=00c88aa0 name=FUN_00c88aa0 size=37 ====

void FUN_00c88aa0(int *param_1)

{
  void *pvVar1;
  
  if (*param_1 == 0) {
    return;
  }
  pvVar1 = malloc(0x30);
  FUN_00c889d0(param_1,pvVar1,0,0);
  return;
}


// ==== entry=00c88ad0 name=FUN_00c88ad0 size=130 ====

/* WARNING: Removing unreachable block (ram,0x00c88b40) */

void FUN_00c88ad0(undefined8 param_1,undefined8 *param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 *puVar1;
  
  *param_2 = 0xffffffffffffffff;
  param_2[1] = param_3;
  param_2[2] = param_4;
  param_2[3] = param_1;
  param_2[4] = 0x7fa;
  pthread_mutex_lock((pthread_mutex_t *)&DAT_011c6900);
  puVar1 = param_2;
  param_2[5] = DAT_011c6938;
  DAT_011c6938 = puVar1;
  if (DAT_011c6928 == 0) {
    DAT_011c6928 = 1;
  }
  pthread_mutex_unlock((pthread_mutex_t *)&DAT_011c6900);
  return;
}


// ==== entry=00c88b60 name=FUN_00c88b60 size=9 ====

void FUN_00c88b60(undefined8 param_1,undefined8 param_2)

{
  FUN_00c88ad0(param_1,param_2,0,0);
  return;
}


// ==== entry=00c88b70 name=FUN_00c88b70 size=30 ====

void FUN_00c88b70(undefined8 param_1)

{
  void *pvVar1;
  
  pvVar1 = malloc(0x30);
  FUN_00c88ad0(param_1,pvVar1,0,0);
  return;
}


// ==== entry=00c88b90 name=FUN_00c88b90 size=241 ====

long FUN_00c88b90(int *param_1)

{
  int *__ptr;
  long lVar1;
  undefined8 *puVar2;
  long lVar3;
  
  if ((param_1 == (int *)0x0) || (*param_1 == 0)) {
    return 0;
  }
  pthread_mutex_lock((pthread_mutex_t *)&DAT_011c6900);
  if (DAT_011c6938 == 0) {
LAB_00c88bf2:
    if (DAT_011c6930 != 0) {
      puVar2 = &DAT_011c6930;
      lVar3 = DAT_011c6930;
      do {
        __ptr = *(int **)(lVar3 + 0x18);
        if ((*(byte *)(lVar3 + 0x20) & 1) == 0) {
          if (param_1 == __ptr) goto LAB_00c88c31;
        }
        else if (param_1 == *(int **)__ptr) {
          *puVar2 = *(undefined8 *)(lVar3 + 0x28);
          free(__ptr);
          goto LAB_00c88c38;
        }
        puVar2 = (undefined8 *)(lVar3 + 0x28);
        lVar3 = *(long *)(lVar3 + 0x28);
      } while (lVar3 != 0);
    }
    pthread_mutex_unlock((pthread_mutex_t *)&DAT_011c6900);
                    /* WARNING: Subroutine does not return */
    abort();
  }
  lVar3 = DAT_011c6938;
  if (param_1 == *(int **)(DAT_011c6938 + 0x18)) {
    puVar2 = &DAT_011c6938;
  }
  else {
    do {
      lVar1 = lVar3;
      lVar3 = *(long *)(lVar1 + 0x28);
      if (lVar3 == 0) goto LAB_00c88bf2;
    } while (param_1 != *(int **)(lVar3 + 0x18));
    puVar2 = (undefined8 *)(lVar1 + 0x28);
  }
LAB_00c88c31:
  *puVar2 = *(undefined8 *)(lVar3 + 0x28);
LAB_00c88c38:
  pthread_mutex_unlock((pthread_mutex_t *)&DAT_011c6900);
  return lVar3;
}


// ==== entry=00c88cb0 orig=FUN_00c88cb0 size=5 name=thunk_FUN_00c88b90 ====

long thunk_FUN_00c88b90(int *param_1)

{
  int *__ptr;
  long lVar1;
  undefined8 *puVar2;
  long lVar3;
  
  if ((param_1 == (int *)0x0) || (*param_1 == 0)) {
    return 0;
  }
  pthread_mutex_lock((pthread_mutex_t *)&DAT_011c6900);
  if (DAT_011c6938 == 0) {
LAB_00c88bf2:
    if (DAT_011c6930 != 0) {
      puVar2 = &DAT_011c6930;
      lVar3 = DAT_011c6930;
      do {
        __ptr = *(int **)(lVar3 + 0x18);
        if ((*(byte *)(lVar3 + 0x20) & 1) == 0) {
          if (param_1 == __ptr) goto LAB_00c88c31;
        }
        else if (param_1 == *(int **)__ptr) {
          *puVar2 = *(undefined8 *)(lVar3 + 0x28);
          free(__ptr);
          goto LAB_00c88c38;
        }
        puVar2 = (undefined8 *)(lVar3 + 0x28);
        lVar3 = *(long *)(lVar3 + 0x28);
      } while (lVar3 != 0);
    }
    pthread_mutex_unlock((pthread_mutex_t *)&DAT_011c6900);
                    /* WARNING: Subroutine does not return */
    abort();
  }
  lVar3 = DAT_011c6938;
  if (param_1 == *(int **)(DAT_011c6938 + 0x18)) {
    puVar2 = &DAT_011c6938;
  }
  else {
    do {
      lVar1 = lVar3;
      lVar3 = *(long *)(lVar1 + 0x28);
      if (lVar3 == 0) goto LAB_00c88bf2;
    } while (param_1 != *(int **)(lVar3 + 0x18));
    puVar2 = (undefined8 *)(lVar1 + 0x28);
  }
LAB_00c88c31:
  *puVar2 = *(undefined8 *)(lVar3 + 0x28);
LAB_00c88c38:
  pthread_mutex_unlock((pthread_mutex_t *)&DAT_011c6900);
  return lVar3;
}


// ==== entry=00c88cc0 name=FUN_00c88cc0 size=28 ====

void FUN_00c88cc0(int *param_1)

{
  void *__ptr;
  
  if (*param_1 == 0) {
    return;
  }
  __ptr = (void *)FUN_00c88b90();
  free(__ptr);
  return;
}


// ==== entry=00c88cf0 name=FUN_00c88cf0 size=523 ====

long FUN_00c88cf0(ulong param_1,ulong *param_2)

{
  ulong uVar1;
  undefined1 uVar2;
  int iVar3;
  undefined8 uVar4;
  long lVar5;
  ulong *puVar6;
  ulong *puVar7;
  ulong *puVar8;
  ulong local_68;
  ulong local_60;
  ulong local_58;
  ulong local_50;
  long local_48;
  undefined4 local_40;
  
  if (DAT_011c6928 == 0) {
LAB_00c88d12:
    local_60 = 0;
    local_58 = 0;
    local_50 = 0;
    local_48 = 0;
    local_40 = 1;
    local_68 = param_1;
    iVar3 = dl_iterate_phdr(FUN_00c87a90,&local_68);
    if (iVar3 < 0) {
      lVar5 = 0;
    }
    else {
      lVar5 = local_48;
      if (local_48 != 0) {
        *param_2 = local_60;
        param_2[1] = local_58;
        param_2[2] = local_50;
      }
    }
  }
  else {
    pthread_mutex_lock((pthread_mutex_t *)&DAT_011c6900);
    for (puVar8 = DAT_011c6930; puVar8 != (ulong *)0x0; puVar8 = (ulong *)puVar8[5]) {
      if (*puVar8 <= param_1) {
        lVar5 = FUN_00c88280(puVar8,param_1);
        if (lVar5 != 0) goto LAB_00c88de9;
        break;
      }
    }
    do {
      puVar8 = DAT_011c6938;
      if (DAT_011c6938 == (ulong *)0x0) {
        pthread_mutex_unlock((pthread_mutex_t *)&DAT_011c6900);
        goto LAB_00c88d12;
      }
      DAT_011c6938 = (ulong *)DAT_011c6938[5];
      lVar5 = FUN_00c88280(puVar8,param_1);
      puVar6 = DAT_011c6930;
      puVar7 = (ulong *)&DAT_011c6930;
      if (DAT_011c6930 != (ulong *)0x0) {
        uVar1 = *DAT_011c6930;
        while (*puVar8 <= uVar1) {
          puVar7 = puVar6 + 5;
          puVar6 = (ulong *)puVar6[5];
          if (puVar6 == (ulong *)0x0) break;
          uVar1 = *puVar6;
        }
      }
      puVar8[5] = (ulong)puVar6;
      *puVar7 = (ulong)puVar8;
    } while (lVar5 == 0);
LAB_00c88de9:
    pthread_mutex_unlock((pthread_mutex_t *)&DAT_011c6900);
    *param_2 = puVar8[1];
    param_2[1] = puVar8[2];
    if ((puVar8[4] & 4) == 0) {
      uVar2 = (undefined1)((ushort)puVar8[4] >> 3);
    }
    else {
      uVar2 = FUN_00c877c0((lVar5 + 4) - (long)*(int *)(lVar5 + 4));
    }
    uVar4 = FUN_00c87550(uVar2,puVar8);
    dwarf_read_encoded_pointer(uVar2,uVar4,lVar5 + 8,&local_68);
    param_2[2] = local_68;
  }
  return lVar5;
}


// ==== entry=00c88f40 name=FUN_00c88f40 size=101 ====

void FUN_00c88f40(EVP_PKEY_CTX *param_1,undefined8 param_2,undefined8 param_3)

{
  long lVar1;
  
  lVar1 = 0;
  _init(param_1);
  do {
    (*(code *)(&__DT_INIT_ARRAY)[lVar1])((ulong)param_1 & 0xffffffff,param_2,param_3);
    lVar1 = lVar1 + 1;
  } while (lVar1 != 0xbc);
  return;
}


// ==== entry=00c88fb0 orig=FUN_00c88fb0 size=2 name=BSim_QList_int_::node_destruct ====

/* BSim sim=1.0 sig=8.379975367083091 ref=libsplitter.so.1.0.0::QList<int>::node_destruct */

void BSim_QList_int___node_destruct(void)

{
  return;
}


// ==== entry=00c88fc0 orig=FUN_00c88fc0 size=26 name=BSim_QTypedArrayData_char_::deallocate ====

/* WARNING: Removing unreachable block (ram,0x00c88fd6) */
/* BSim sim=1.0 sig=10.055904525706838
   ref=libwindtermopen.so.1.0.0::QTypedArrayData<char>::deallocate */

void BSim_QTypedArrayData_char___deallocate(undefined8 param_1)

{
  __cxa_atexit(param_1,0,0);
  return;
}


// ==== entry=00c88fdc orig=FUN_00c88fdc size=9 name=_fini ====

void _fini(void)

{
  return;
}


// ==== entry=011c7000 orig=FUN_011c7000 size=1 name=pthread_join ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int pthread_join(pthread_t __th,void **__thread_return)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7010 orig=FUN_011c7010 size=1 name=ssh_string_free_char ====

/* WARNING: Control flow encountered bad instruction data */

void ssh_string_free_char(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7018 orig=FUN_011c7018 size=1 name=setSectionResizeMode ====

/* WARNING: Control flow encountered bad instruction data */

void QHeaderView::setSectionResizeMode(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7020 orig=FUN_011c7020 size=1 name=sortByColumn ====

/* WARNING: Control flow encountered bad instruction data */

void QTreeView::sortByColumn(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7028 orig=FUN_011c7028 size=1 name=contentsMargins ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QWidget::contentsMargins(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7030 orig=FUN_011c7030 size=1 name=resetIndentation ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QTreeView::resetIndentation(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7038 orig=FUN_011c7038 size=1 name=QRegion ====

/* WARNING: Control flow encountered bad instruction data */

void __thiscall QRegion::QRegion(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7040 orig=FUN_011c7040 size=1 name=changeEvent ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QLabel::changeEvent(QEvent *param_1)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7048 orig=FUN_011c7048 size=1 name=brush ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QPainter::brush(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7050 orig=FUN_011c7050 size=1 name=argToQString ====

/* WARNING: Control flow encountered bad instruction data */

void QtPrivate::argToQString(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7058 orig=FUN_011c7058 size=1 name=setObjectOwnership ====

/* WARNING: Control flow encountered bad instruction data */

void QQmlEngine::setObjectOwnership(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7060 orig=FUN_011c7060 size=1 name=setSelected ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QListWidgetItem::setSelected(bool param_1)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7068 orig=FUN_011c7068 size=1 name=hasNext ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QRegularExpressionMatchIterator::hasNext(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7070 orig=FUN_011c7070 size=1 name=setIndexWidget ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QAbstractItemView::setIndexWidget(QModelIndex *param_1,QWidget *param_2)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7078 orig=FUN_011c7078 size=1 name=entryList ====

/* WARNING: Control flow encountered bad instruction data */

void QDir::entryList(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7080 orig=FUN_011c7080 size=1 name=setContextMenuPolicy ====

/* WARNING: Control flow encountered bad instruction data */

void QWidget::setContextMenuPolicy(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7088 orig=FUN_011c7088 size=1 name=~QVBoxLayout ====

/* WARNING: Control flow encountered bad instruction data */

void __thiscall QVBoxLayout::~QVBoxLayout(QVBoxLayout *this)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7090 orig=FUN_011c7090 size=1 name=completeSuffix ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QFileInfo::completeSuffix(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7098 orig=FUN_011c7098 size=1 name=QLineEdit ====

/* WARNING: Control flow encountered bad instruction data */

void __thiscall QLineEdit::QLineEdit(QLineEdit *this,QWidget *param_1)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c70a0 orig=FUN_011c70a0 size=1 name=removeRecursively ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QDir::removeRecursively(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c70a8 orig=FUN_011c70a8 size=1 name=sftp_async_mkdir ====

/* WARNING: Control flow encountered bad instruction data */

void sftp_async_mkdir(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c70b0 orig=FUN_011c70b0 size=1 name=sendEvent ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QCoreApplication::sendEvent(QObject *param_1,QEvent *param_2)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c70b8 orig=FUN_011c70b8 size=1 name=updateGeometries ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QListView::updateGeometries(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c70c0 orig=FUN_011c70c0 size=1 name=insertPermanentWidget ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QStatusBar::insertPermanentWidget(int param_1,QWidget *param_2,int param_3)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c70c8 orig=FUN_011c70c8 size=1 name=qt_metacast ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QListWidget::qt_metacast(char *param_1)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c70d0 orig=FUN_011c70d0 size=1 name=QHostAddress ====

/* WARNING: Control flow encountered bad instruction data */

void __thiscall QHostAddress::QHostAddress(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c70d8 orig=FUN_011c70d8 size=1 name=remove ====

/* WARNING: Control flow encountered bad instruction data */

void QString::remove(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c70e0 orig=FUN_011c70e0 size=1 name=ftello64 ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

__off64_t ftello64(FILE *__stream)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c70e8 orig=FUN_011c70e8 size=1 name=QMetaType ====

/* WARNING: Control flow encountered bad instruction data */

void __thiscall QMetaType::QMetaType(QMetaType *this,int param_1)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c70f0 orig=FUN_011c70f0 size=1 name=QAbstractListModel ====

/* WARNING: Control flow encountered bad instruction data */

void __thiscall QAbstractListModel::QAbstractListModel(QAbstractListModel *this,QObject *param_1)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c70f8 orig=FUN_011c70f8 size=1 name=finished ====

/* WARNING: Control flow encountered bad instruction data */

void QThread::finished(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7100 orig=FUN_011c7100 size=1 name=QStringList_removeDuplicates ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QtPrivate::QStringList_removeDuplicates(QStringList *param_1)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7108 orig=FUN_011c7108 size=1 name=averageCharWidth ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QFontMetrics::averageCharWidth(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7110 orig=FUN_011c7110 size=1 name=operator!= ====

/* WARNING: Control flow encountered bad instruction data */

void __thiscall QFont::operator!=(QFont *this,QFont *param_1)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7118 orig=FUN_011c7118 size=1 name=setUniformRowHeights ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QTreeView::setUniformRowHeights(bool param_1)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7120 orig=FUN_011c7120 size=1 name=metaObject ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QToolButton::metaObject(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7128 orig=FUN_011c7128 size=1 name=setBackground ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QPainter::setBackground(QBrush *param_1)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7130 orig=FUN_011c7130 size=1 name=newObject ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QJSEngine::newObject(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7138 orig=FUN_011c7138 size=1 name=hasText ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QMimeData::hasText(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7140 orig=FUN_011c7140 size=1 name=start ====

/* WARNING: Control flow encountered bad instruction data */

void QAbstractAnimation::start(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7148 orig=FUN_011c7148 size=1 name=globalStrut ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QApplication::globalStrut(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7150 orig=FUN_011c7150 size=1 name=ssh_userauth_password ====

/* WARNING: Control flow encountered bad instruction data */

void ssh_userauth_password(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7158 orig=FUN_011c7158 size=1 name=sftp_closedir ====

/* WARNING: Control flow encountered bad instruction data */

void sftp_closedir(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7160 orig=FUN_011c7160 size=1 name=QFileDialog ====

/* WARNING: Control flow encountered bad instruction data */

void __thiscall
QFileDialog::QFileDialog
          (QFileDialog *this,QWidget *param_1,QString *param_2,QString *param_3,QString *param_4)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7168 orig=FUN_011c7168 size=1 name=weight ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QFont::weight(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7170 orig=FUN_011c7170 size=1 name=itemEntered ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QListWidget::itemEntered(QListWidgetItem *param_1)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7178 orig=FUN_011c7178 size=1 name=show ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QWidget::show(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7180 orig=FUN_011c7180 size=1 name=toIPv6Address ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QHostAddress::toIPv6Address(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7188 orig=FUN_011c7188 size=1 name=viewportEvent ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QTreeView::viewportEvent(QEvent *param_1)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7190 orig=FUN_011c7190 size=1 name=moveCursor ====

/* WARNING: Control flow encountered bad instruction data */

void QTableView::moveCursor(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7198 orig=FUN_011c7198 size=1 name=mouseReleaseEvent ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QPlainTextEdit::mouseReleaseEvent(QMouseEvent *param_1)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c71a8 orig=FUN_011c71a8 size=1 name=disconnect ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QObject::disconnect(QObject *param_1,char *param_2,QObject *param_3,char *param_4)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c71b0 orig=FUN_011c71b0 size=1 name=mimeTypeForFile ====

/* WARNING: Control flow encountered bad instruction data */

void QMimeDatabase::mimeTypeForFile(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c71b8 orig=FUN_011c71b8 size=1 name=qt_metacall ====

/* WARNING: Control flow encountered bad instruction data */

void QMenu::qt_metacall(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c71c0 orig=FUN_011c71c0 size=1 name=getColor ====

/* WARNING: Control flow encountered bad instruction data */

void QColorDialog::getColor(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c71c8 orig=FUN_011c71c8 size=1 name=keyPressEvent ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QMenu::keyPressEvent(QKeyEvent *param_1)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c71d0 orig=FUN_011c71d0 size=1 name=indexAt ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QListView::indexAt(QPoint *param_1)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c71d8 orig=FUN_011c71d8 size=1 name=insertRow ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QFormLayout::insertRow(int param_1,QString *param_2,QWidget *param_3)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c71e0 orig=FUN_011c71e0 size=1 name=strdup ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * strdup(char *__s)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c71e8 orig=FUN_011c71e8 size=1 name=keyCount ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QMetaEnum::keyCount(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c71f0 orig=FUN_011c71f0 size=1 name=released ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QAbstractButton::released(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c71f8 orig=FUN_011c71f8 size=1 name=~QPixmap ====

/* WARNING: Control flow encountered bad instruction data */

void __thiscall QPixmap::~QPixmap(QPixmap *this)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7200 orig=FUN_011c7200 size=1 name=program ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QProcess::program(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7208 orig=FUN_011c7208 size=1 name=QThread ====

/* WARNING: Control flow encountered bad instruction data */

void __thiscall QThread::QThread(QThread *this,QObject *param_1)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7210 orig=FUN_011c7210 size=1 name=verticalScrollbarValueChanged ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QTreeView::verticalScrollbarValueChanged(int param_1)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7218 orig=FUN_011c7218 size=1 name=keys ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QJsonObject::keys(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7220 orig=FUN_011c7220 size=1 name=isFullScreen ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QWidget::isFullScreen(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7228 orig=FUN_011c7228 size=1 name=supportedDropActions ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QTableWidget::supportedDropActions(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7230 orig=FUN_011c7230 size=1 name=setProperty ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QObject::setProperty(char *param_1,QVariant *param_2)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7238 orig=FUN_011c7238 size=1 name=setModel ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QComboBox::setModel(QAbstractItemModel *param_1)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7240 orig=FUN_011c7240 size=1 name=reset ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QListView::reset(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7248 orig=FUN_011c7248 size=1 name=setCentralWidget ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QMainWindow::setCentralWidget(QWidget *param_1)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7250 orig=FUN_011c7250 size=1 name=trimmed_helper ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QString::trimmed_helper(QString *param_1)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7258 orig=FUN_011c7258 size=1 name=geometry ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QScreen::geometry(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7260 orig=FUN_011c7260 size=1 name=errorOccurred ====

/* WARNING: Control flow encountered bad instruction data */

void QAbstractSocket::errorOccurred(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7268 orig=FUN_011c7268 size=1 name=itemText ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QComboBox::itemText(int param_1)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7270 orig=FUN_011c7270 size=1 name=operator!= ====

/* WARNING: Control flow encountered bad instruction data */

void __thiscall QColor::operator!=(QColor *this,QColor *param_1)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7278 orig=FUN_011c7278 size=1 name=sftp_dir_eof ====

/* WARNING: Control flow encountered bad instruction data */

void sftp_dir_eof(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7280 orig=FUN_011c7280 size=1 name=setProxy ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QAbstractSocket::setProxy(QNetworkProxy *param_1)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7288 orig=FUN_011c7288 size=1 name=fdopen ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

FILE * fdopen(int __fd,char *__modes)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7290 orig=FUN_011c7290 size=1 name=replace ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QByteArray::replace(int param_1,int param_2,QByteArray *param_3)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7298 orig=FUN_011c7298 size=1 name=~QStyledItemDelegate ====

/* WARNING: Control flow encountered bad instruction data */

void __thiscall QStyledItemDelegate::~QStyledItemDelegate(QStyledItemDelegate *this)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c72a0 orig=FUN_011c72a0 size=1 name=start ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QTimeLine::start(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c72a8 orig=FUN_011c72a8 size=1 name=QDir ====

/* WARNING: Control flow encountered bad instruction data */

void __thiscall QDir::QDir(QDir *this,QString *param_1)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c72b0 orig=FUN_011c72b0 size=1 name=~QFontMetrics ====

/* WARNING: Control flow encountered bad instruction data */

void __thiscall QFontMetrics::~QFontMetrics(QFontMetrics *this)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c72b8 orig=FUN_011c72b8 size=1 name=ssh_userauth_gssapi ====

/* WARNING: Control flow encountered bad instruction data */

void ssh_userauth_gssapi(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c72c0 orig=FUN_011c72c0 size=1 name=paintEvent ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QStatusBar::paintEvent(QPaintEvent *param_1)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c72c8 orig=FUN_011c72c8 size=1 name=iconName ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QIconEngine::iconName(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c72d0 orig=FUN_011c72d0 size=1 name=setEditorData ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QStyledItemDelegate::setEditorData(QWidget *param_1,QModelIndex *param_2)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c72d8 orig=FUN_011c72d8 size=1 name=setDefault ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QPushButton::setDefault(bool param_1)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c72e0 orig=FUN_011c72e0 size=1 name=arg ====

/* WARNING: Control flow encountered bad instruction data */

void QString::arg(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c72f0 orig=FUN_011c72f0 size=1 name=~bad_array_new_length ====

/* WARNING: Control flow encountered bad instruction data */

void __thiscall std::bad_array_new_length::~bad_array_new_length(bad_array_new_length *this)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c72f8 orig=FUN_011c72f8 size=1 name=mimeData ====

/* WARNING: Control flow encountered bad instruction data */

void QTableWidget::mimeData(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7308 orig=FUN_011c7308 size=1 name=size ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QFile::size(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7310 orig=FUN_011c7310 size=1 name=wcrtomb ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

size_t wcrtomb(char *__s,wchar_t __wc,mbstate_t *__ps)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7318 orig=FUN_011c7318 size=1 name=hasSelection ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QItemSelectionModel::hasSelection(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7320 orig=FUN_011c7320 size=1 name=setUpdateInterval ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QTimeLine::setUpdateInterval(int param_1)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7328 orig=FUN_011c7328 size=1 name=isSliderDown ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QAbstractSlider::isSliderDown(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7330 orig=FUN_011c7330 size=1 name=processEvents ====

/* WARNING: Control flow encountered bad instruction data */

void QCoreApplication::processEvents(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7338 orig=FUN_011c7338 size=1 name=setMimeData ====

/* WARNING: Control flow encountered bad instruction data */

void QClipboard::setMimeData(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7340 orig=FUN_011c7340 size=1 name=ssh_channel_request_pty_size ====

/* WARNING: Control flow encountered bad instruction data */

void ssh_channel_request_pty_size(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7348 orig=FUN_011c7348 size=1 name=setPen ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QPainter::setPen(QColor *param_1)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7358 orig=FUN_011c7358 size=1 name=showMaximized ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QWidget::showMaximized(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7360 orig=FUN_011c7360 size=1 name=display ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QX11Info::display(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7368 orig=FUN_011c7368 size=1 name=qstrcmp ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void qstrcmp(char *param_1,char *param_2)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7370 orig=FUN_011c7370 size=1 name=setHeaderData ====

/* WARNING: Control flow encountered bad instruction data */

void QAbstractItemModel::setHeaderData(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7378 orig=FUN_011c7378 size=1 name=value ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QAssociativeIterable::const_iterator::value(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7380 orig=FUN_011c7380 size=1 name=completer ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QComboBox::completer(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7390 orig=FUN_011c7390 size=1 name=qt_metacast ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QThread::qt_metacast(char *param_1)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7398 orig=FUN_011c7398 size=1 name=setReadBufferSize ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QAbstractSocket::setReadBufferSize(longlong param_1)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c73a0 orig=FUN_011c73a0 size=1 name=wcscmp ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int wcscmp(wchar_t *__s1,wchar_t *__s2)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c73a8 orig=FUN_011c73a8 size=1 name=createMaskFromColor ====

/* WARNING: Control flow encountered bad instruction data */

void QPixmap::createMaskFromColor(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c73b8 orig=FUN_011c73b8 size=1 name=changeEvent ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QMenu::changeEvent(QEvent *param_1)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c73c0 orig=FUN_011c73c0 size=1 name=reallocData ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QString::reallocData(uint param_1,bool param_2)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c73d0 orig=FUN_011c73d0 size=1 name=~QTextCursor ====

/* WARNING: Control flow encountered bad instruction data */

void __thiscall QTextCursor::~QTextCursor(QTextCursor *this)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c73d8 orig=FUN_011c73d8 size=1 name=setCapabilities ====

/* WARNING: Control flow encountered bad instruction data */

void QNetworkProxy::setCapabilities(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c73e8 orig=FUN_011c73e8 size=1 name=currentIndex ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QAbstractItemView::currentIndex(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c73f0 orig=FUN_011c73f0 size=1 name=~QTreeView ====

/* WARNING: Control flow encountered bad instruction data */

void __thiscall QTreeView::~QTreeView(QTreeView *this)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c73f8 orig=FUN_011c73f8 size=1 name=data ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QStandardItemModel::data(QModelIndex *param_1,int param_2)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7400 orig=FUN_011c7400 size=1 name=flags ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QFileSystemModel::flags(QModelIndex *param_1)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7408 orig=FUN_011c7408 size=1 name=read ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QIODevice::read(char *param_1,longlong param_2)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7410 orig=FUN_011c7410 size=1 name=stretch ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QFont::stretch(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7418 orig=FUN_011c7418 size=1 name=QShortcut ====

/* WARNING: Control flow encountered bad instruction data */

void __thiscall QShortcut::QShortcut(QShortcut *this,QWidget *param_1)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7420 orig=FUN_011c7420 size=1 name=captured ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QRegularExpressionMatch::captured(int param_1)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7428 orig=FUN_011c7428 size=1 name=selectionChanged ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QTreeView::selectionChanged(QItemSelection *param_1,QItemSelection *param_2)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7430 orig=FUN_011c7430 size=1 name=setColumnStretch ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QGridLayout::setColumnStretch(int param_1,int param_2)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7438 orig=FUN_011c7438 size=1 name=_M_construct ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void std::__cxx11::string::_M_construct(ulong param_1,char param_2)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7440 orig=FUN_011c7440 size=1 name=setEndValue ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QVariantAnimation::setEndValue(QVariant *param_1)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7448 orig=FUN_011c7448 size=1 name=setPortName ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QSerialPort::setPortName(QString *param_1)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7450 orig=FUN_011c7450 size=1 name=clicked ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QAbstractButton::clicked(bool param_1)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7458 orig=FUN_011c7458 size=1 name=realloc ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * realloc(void *__ptr,size_t __size)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7460 orig=FUN_011c7460 size=1 name=setItem ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QStandardItemModel::setItem(int param_1,int param_2,QStandardItem *param_3)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7468 orig=FUN_011c7468 size=1 name=getOpenFileName ====

/* WARNING: Control flow encountered bad instruction data */

void QFileDialog::getOpenFileName(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7470 orig=FUN_011c7470 size=1 name=~QSettings ====

/* WARNING: Control flow encountered bad instruction data */

void __thiscall QSettings::~QSettings(QSettings *this)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7478 orig=FUN_011c7478 size=1 name=underline ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QFont::underline(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7480 orig=FUN_011c7480 size=1 name=polish ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QProxyStyle::polish(QApplication *param_1)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7488 orig=FUN_011c7488 size=1 name=terminate ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QProcess::terminate(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7490 orig=FUN_011c7490 size=1 name=setCheckable ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QAction::setCheckable(bool param_1)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7498 orig=FUN_011c7498 size=1 name=hitTestComplexControl ====

/* WARNING: Control flow encountered bad instruction data */

void QProxyStyle::hitTestComplexControl(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c74a0 orig=FUN_011c74a0 size=1 name=writeData ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QAbstractSocket::writeData(char *param_1,longlong param_2)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c74a8 orig=FUN_011c74a8 size=1 name=setWordWrapMode ====

/* WARNING: Control flow encountered bad instruction data */

void QPlainTextEdit::setWordWrapMode(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c74b0 orig=FUN_011c74b0 size=1 name=pututxline ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

utmpx * pututxline(utmpx *__utmpx)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c74b8 orig=FUN_011c74b8 size=1 name=hasChildren ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QStandardItem::hasChildren(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c74c0 orig=FUN_011c74c0 size=1 name=toInt ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QByteArray::toInt(bool *param_1,int param_2)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c74c8 orig=FUN_011c74c8 size=1 name=rowsInserted ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QAbstractItemView::rowsInserted(QModelIndex *param_1,int param_2,int param_3)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c74d0 orig=FUN_011c74d0 size=1 name=text ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QLineEdit::text(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c74d8 orig=FUN_011c74d8 size=1 name=QKeySequence ====

/* WARNING: Control flow encountered bad instruction data */

void __thiscall
QKeySequence::QKeySequence(QKeySequence *this,int param_1,int param_2,int param_3,int param_4)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c74e0 orig=FUN_011c74e0 size=1 name=QTextCursor ====

/* WARNING: Control flow encountered bad instruction data */

void __thiscall QTextCursor::QTextCursor(QTextCursor *this,QTextDocument *param_1)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c74e8 orig=FUN_011c74e8 size=1 name=addWidget ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QStackedLayout::addWidget(QWidget *param_1)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c74f0 orig=FUN_011c74f0 size=1 name=ZSTD_trace_compress_end ====

/* WARNING: Control flow encountered bad instruction data */

void ZSTD_trace_compress_end(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c74f8 orig=FUN_011c74f8 size=1 name=toString ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QHostAddress::toString(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7500 orig=FUN_011c7500 size=1 name=isPersistentEditorOpen ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QAbstractItemView::isPersistentEditorOpen(QModelIndex *param_1)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7510 orig=FUN_011c7510 size=1 name=setOverrideCursor ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QGuiApplication::setOverrideCursor(QCursor *param_1)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7518 orig=FUN_011c7518 size=1 name=newQObject ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QJSEngine::newQObject(QObject *param_1)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7520 orig=FUN_011c7520 size=1 name=__nl_langinfo_l ====

/* WARNING: Control flow encountered bad instruction data */

void __nl_langinfo_l(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7530 orig=FUN_011c7530 size=1 name=canDropMimeData ====

/* WARNING: Control flow encountered bad instruction data */

void QAbstractProxyModel::canDropMimeData(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7538 orig=FUN_011c7538 size=1 name=valueChanged ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QSpinBox::valueChanged(int param_1)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7540 orig=FUN_011c7540 size=1 name=toUnicode ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QTextDecoder::toUnicode(QByteArray *param_1)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7548 orig=FUN_011c7548 size=1 name=permissions ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QFileInfo::permissions(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7550 orig=FUN_011c7550 size=1 name=layoutDirection ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QWidget::layoutDirection(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7558 orig=FUN_011c7558 size=1 name=setContentsMargins ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QLayout::setContentsMargins(int param_1,int param_2,int param_3,int param_4)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7560 orig=FUN_011c7560 size=1 name=activate ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QLayout::activate(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7568 orig=FUN_011c7568 size=1 name=text ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QAbstractButton::text(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7570 orig=FUN_011c7570 size=1 name=dispose ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QListData::dispose(Data *param_1)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7578 orig=FUN_011c7578 size=1 name=selectionCommand ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QAbstractItemView::selectionCommand(QModelIndex *param_1,QEvent *param_2)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7580 orig=FUN_011c7580 size=1 name=ioctl ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int ioctl(int __fd,ulong __request,...)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7590 orig=FUN_011c7590 size=1 name=isalpha ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int isalpha(int param_1)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7598 orig=FUN_011c7598 size=1 name=QThreadPool ====

/* WARNING: Control flow encountered bad instruction data */

void __thiscall QThreadPool::QThreadPool(QThreadPool *this,QObject *param_1)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c75a0 orig=FUN_011c75a0 size=1 name=QPersistentModelIndex ====

/* WARNING: Control flow encountered bad instruction data */

void __thiscall
QPersistentModelIndex::QPersistentModelIndex(QPersistentModelIndex *this,QModelIndex *param_1)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c75a8 orig=FUN_011c75a8 size=1 name=setSelectionBehavior ====

/* WARNING: Control flow encountered bad instruction data */

void QAbstractItemView::setSelectionBehavior(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c75b0 orig=FUN_011c75b0 size=1 name=reset ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QIODevice::reset(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c75b8 orig=FUN_011c75b8 size=1 name=indexOf ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QStackedWidget::indexOf(QWidget *param_1)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c75c0 orig=FUN_011c75c0 size=1 name=grabShortcut ====

/* WARNING: Control flow encountered bad instruction data */

void QWidget::grabShortcut(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c75c8 orig=FUN_011c75c8 size=1 name=fillRect ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QPainter::fillRect(QRectF *param_1,QColor *param_2)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c75d0 orig=FUN_011c75d0 size=1 name=key ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QIconEngine::key(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c75d8 orig=FUN_011c75d8 size=1 name=indexOf ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QByteArray::indexOf(char *param_1,int param_2)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c75e0 orig=FUN_011c75e0 size=1 name=setValue ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QProgressDialog::setValue(int param_1)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c75e8 orig=FUN_011c75e8 size=1 name=paintEvent ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QPlainTextEdit::paintEvent(QPaintEvent *param_1)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c75f0 orig=FUN_011c75f0 size=1 name=registerNormalizedType ====

/* WARNING: Control flow encountered bad instruction data */

void QMetaType::registerNormalizedType(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c75f8 orig=FUN_011c75f8 size=1 name=QSettings ====

/* WARNING: Control flow encountered bad instruction data */

void __thiscall QSettings::QSettings(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7600 orig=FUN_011c7600 size=1 name=trimmed_helper ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QByteArray::trimmed_helper(QByteArray *param_1)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7608 orig=FUN_011c7608 size=1 name=setSingleStep ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QDoubleSpinBox::setSingleStep(double param_1)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7610 orig=FUN_011c7610 size=1 name=setTitle ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QGroupBox::setTitle(QString *param_1)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7618 orig=FUN_011c7618 size=1 name=memmove ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memmove(void *__dest,void *__src,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7620 orig=FUN_011c7620 size=1 name=hideEvent ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QMenu::hideEvent(QHideEvent *param_1)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7628 orig=FUN_011c7628 size=1 name=setSizeConstraint ====

/* WARNING: Control flow encountered bad instruction data */

void QLayout::setSizeConstraint(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7630 orig=FUN_011c7630 size=1 name=contains ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QRect::contains(QPoint *param_1,bool param_2)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7638 orig=FUN_011c7638 size=1 name=toVariant ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QJsonValueRef::toVariant(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7640 orig=FUN_011c7640 size=1 name=drawLines ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QPainter::drawLines(QLine *param_1,int param_2)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7648 orig=FUN_011c7648 size=1 name=~QMenu ====

/* WARNING: Control flow encountered bad instruction data */

void __thiscall QMenu::~QMenu(QMenu *this)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7650 orig=FUN_011c7650 size=1 name=setWindowFlags ====

/* WARNING: Control flow encountered bad instruction data */

void QWidget::setWindowFlags(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7658 orig=FUN_011c7658 size=1 name=keyReleaseEvent ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QComboBox::keyReleaseEvent(QKeyEvent *param_1)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7660 orig=FUN_011c7660 size=1 name=ssh_get_error_code ====

/* WARNING: Control flow encountered bad instruction data */

void ssh_get_error_code(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7668 orig=FUN_011c7668 size=1 name=QVariant ====

/* WARNING: Control flow encountered bad instruction data */

void __thiscall QVariant::QVariant(QVariant *this,QString *param_1)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7670 orig=FUN_011c7670 size=1 name=isValid ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QSvgRenderer::isValid(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7678 orig=FUN_011c7678 size=1 name=supportedDropActions ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QSortFilterProxyModel::supportedDropActions(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7680 orig=FUN_011c7680 size=1 name=QTreeView ====

/* WARNING: Control flow encountered bad instruction data */

void __thiscall QTreeView::QTreeView(QTreeView *this,QWidget *param_1)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7688 orig=FUN_011c7688 size=1 name=currentWidget ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QStackedWidget::currentWidget(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7690 orig=FUN_011c7690 size=1 name=__ctype_b_loc ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

ushort ** __ctype_b_loc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7698 orig=FUN_011c7698 size=1 name=addAction ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QMenu::addAction(QString *param_1)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c76a0 orig=FUN_011c76a0 size=1 name=leaveEvent ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QToolButton::leaveEvent(QEvent *param_1)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c76a8 orig=FUN_011c76a8 size=1 name=setCurrentIndex ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QStackedWidget::setCurrentIndex(int param_1)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c76b8 orig=FUN_011c76b8 size=1 name=strncpy ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * strncpy(char *__dest,char *__src,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c76c0 orig=FUN_011c76c0 size=1 name=QVariant ====

/* WARNING: Control flow encountered bad instruction data */

void __thiscall QVariant::QVariant(QVariant *this,QRectF *param_1)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c76c8 orig=FUN_011c76c8 size=1 name=toupper ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int toupper(int __c)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c76d0 orig=FUN_011c76d0 size=1 name=localtime_r ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

tm * localtime_r(time_t *__timer,tm *__tp)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c76d8 orig=FUN_011c76d8 size=1 name=autoHide ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QTabBar::autoHide(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c76e0 orig=FUN_011c76e0 size=1 name=~QWidgetAction ====

/* WARNING: Control flow encountered bad instruction data */

void __thiscall QWidgetAction::~QWidgetAction(QWidgetAction *this)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c76e8 orig=FUN_011c76e8 size=1 name=__assert_fail ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void __assert_fail(char *__assertion,char *__file,uint __line,char *__function)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c76f0 orig=FUN_011c76f0 size=1 name=minimumTabSizeHint ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QTabBar::minimumTabSizeHint(int param_1)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c76f8 orig=FUN_011c76f8 size=1 name=metric ====

/* WARNING: Control flow encountered bad instruction data */

void QWidget::metric(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7700 orig=FUN_011c7700 size=1 name=columnCount ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QGridLayout::columnCount(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7708 orig=FUN_011c7708 size=1 name=pthread_mutex_destroy ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int pthread_mutex_destroy(pthread_mutex_t *__mutex)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7710 orig=FUN_011c7710 size=1 name=insert ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QProcessEnvironment::insert(QString *param_1,QString *param_2)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7720 orig=FUN_011c7720 size=1 name=QBuffer ====

/* WARNING: Control flow encountered bad instruction data */

void __thiscall QBuffer::QBuffer(QBuffer *this,QByteArray *param_1,QObject *param_2)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7728 orig=FUN_011c7728 size=1 name=setTabStopDistance ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QPlainTextEdit::setTabStopDistance(double param_1)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7730 orig=FUN_011c7730 size=1 name=sizeHint ====

/* WARNING: Control flow encountered bad instruction data */

void QBoxLayout::sizeHint(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7738 orig=FUN_011c7738 size=1 name=selectionMode ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QAbstractItemView::selectionMode(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7748 orig=FUN_011c7748 size=1 name=buddy ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QAbstractItemModel::buddy(QModelIndex *param_1)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7750 orig=FUN_011c7750 size=1 name=isVisibleTo ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QWidget::isVisibleTo(QWidget *param_1)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7758 orig=FUN_011c7758 size=1 name=qt_metacall ====

/* WARNING: Control flow encountered bad instruction data */

void QComboBox::qt_metacall(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7760 orig=FUN_011c7760 size=1 name=operator>> ====

/* WARNING: Control flow encountered bad instruction data */

void __thiscall QDataStream::operator>>(QDataStream *this,bool *param_1)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7768 orig=FUN_011c7768 size=1 name=absolutePath ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QFileInfo::absolutePath(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7770 orig=FUN_011c7770 size=1 name=QSaveFile ====

/* WARNING: Control flow encountered bad instruction data */

void __thiscall QSaveFile::QSaveFile(QSaveFile *this,QObject *param_1)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7778 orig=FUN_011c7778 size=1 name=~QBitmap ====

/* WARNING: Control flow encountered bad instruction data */

void __thiscall QBitmap::~QBitmap(QBitmap *this)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7780 orig=FUN_011c7780 size=1 name=spacerItem ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QLayoutItem::spacerItem(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7788 orig=FUN_011c7788 size=1 name=isExpanded ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QTreeView::isExpanded(QModelIndex *param_1)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7790 orig=FUN_011c7790 size=1 name=currentThreadId ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QThread::currentThreadId(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7798 orig=FUN_011c7798 size=1 name=QTranslator ====

/* WARNING: Control flow encountered bad instruction data */

void __thiscall QTranslator::QTranslator(QTranslator *this,QObject *param_1)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c77a0 orig=FUN_011c77a0 size=1 name=layoutDirection ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QGuiApplication::layoutDirection(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c77a8 orig=FUN_011c77a8 size=1 name=itemPixmapRect ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QProxyStyle::itemPixmapRect(QRect *param_1,int param_2,QPixmap *param_3)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c77b0 orig=FUN_011c77b0 size=1 name=keys ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QProcessEnvironment::keys(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c77b8 orig=FUN_011c77b8 size=1 name=startsWith ====

/* WARNING: Control flow encountered bad instruction data */

void QString::startsWith(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c77c0 orig=FUN_011c77c0 size=1 name=supportsSelection ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QClipboard::supportsSelection(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c77c8 orig=FUN_011c77c8 size=1 name=QIcon ====

/* WARNING: Control flow encountered bad instruction data */

void __thiscall QIcon::QIcon(QIcon *this,QIcon *param_1)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c77d0 orig=FUN_011c77d0 size=1 name=setHorizontalScrollMode ====

/* WARNING: Control flow encountered bad instruction data */

void QAbstractItemView::setHorizontalScrollMode(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c77d8 orig=FUN_011c77d8 size=1 name=qt_metacall ====

/* WARNING: Control flow encountered bad instruction data */

void QLabel::qt_metacall(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c77e8 orig=FUN_011c77e8 size=1 name=~QPushButton ====

/* WARNING: Control flow encountered bad instruction data */

void __thiscall QPushButton::~QPushButton(QPushButton *this)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c77f8 orig=FUN_011c77f8 size=1 name=isActiveWindow ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QWidget::isActiveWindow(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7800 orig=FUN_011c7800 size=1 name=qt_metacast ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QLabel::qt_metacast(char *param_1)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7808 orig=FUN_011c7808 size=1 name=dropEvent ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QTableWidget::dropEvent(QDropEvent *param_1)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7810 orig=FUN_011c7810 size=1 name=cacheKey ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QIcon::cacheKey(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7818 orig=FUN_011c7818 size=1 name=focusOutEvent ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QPushButton::focusOutEvent(QFocusEvent *param_1)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7820 orig=FUN_011c7820 size=1 name=minimumSizeHint ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QComboBox::minimumSizeHint(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7828 orig=FUN_011c7828 size=1 name=setToolTipsVisible ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QMenu::setToolTipsVisible(bool param_1)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7830 orig=FUN_011c7830 size=1 name=installExtensions ====

/* WARNING: Control flow encountered bad instruction data */

void QJSEngine::installExtensions(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7838 orig=FUN_011c7838 size=1 name=singleShot ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QTimer::singleShot(int param_1,QObject *param_2,char *param_3)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7840 orig=FUN_011c7840 size=1 name=remove ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int remove(char *__filename)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7848 orig=FUN_011c7848 size=1 name=syscall ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

long syscall(long __sysno,...)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7850 orig=FUN_011c7850 size=1 name=replaceWidget ====

/* WARNING: Control flow encountered bad instruction data */

void QLayout::replaceWidget(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7858 orig=FUN_011c7858 size=1 name=addLayout ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QBoxLayout::addLayout(QLayout *param_1,int param_2)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7860 orig=FUN_011c7860 size=1 name=~QMimeDatabase ====

/* WARNING: Control flow encountered bad instruction data */

void __thiscall QMimeDatabase::~QMimeDatabase(QMimeDatabase *this)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7868 orig=FUN_011c7868 size=1 name=tabToolTip ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QTabBar::tabToolTip(int param_1)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7870 orig=FUN_011c7870 size=1 name=keyPressEvent ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QTreeView::keyPressEvent(QKeyEvent *param_1)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7878 orig=FUN_011c7878 size=1 name=expanded ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QTreeView::expanded(QModelIndex *param_1)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7880 orig=FUN_011c7880 size=1 name=insertItems ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QListWidget::insertItems(int param_1,QStringList *param_2)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7888 orig=FUN_011c7888 size=1 name=mid ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QByteArray::mid(int param_1,int param_2)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7898 orig=FUN_011c7898 size=1 name=setDefaultAlignment ====

/* WARNING: Control flow encountered bad instruction data */

void QHeaderView::setDefaultAlignment(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c78a0 orig=FUN_011c78a0 size=1 name=ssh_channel_new ====

/* WARNING: Control flow encountered bad instruction data */

void ssh_channel_new(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c78a8 orig=FUN_011c78a8 size=1 name=QString ====

/* WARNING: Control flow encountered bad instruction data */

void __thiscall QString::QString(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c78b0 orig=FUN_011c78b0 size=1 name=QVariant ====

/* WARNING: Control flow encountered bad instruction data */

void __thiscall QVariant::QVariant(QVariant *this,QJsonObject *param_1)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c78b8 orig=FUN_011c78b8 size=1 name=currentItem ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QTableWidget::currentItem(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c78c0 orig=FUN_011c78c0 size=1 name=strikeOut ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QFont::strikeOut(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c78c8 orig=FUN_011c78c8 size=1 name=event ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QFrame::event(QEvent *param_1)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c78d0 orig=FUN_011c78d0 size=1 name=horizontalAdvance ====

/* WARNING: Control flow encountered bad instruction data */

void QFontMetricsF::horizontalAdvance(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c78d8 orig=FUN_011c78d8 size=1 name=~QInputDialog ====

/* WARNING: Control flow encountered bad instruction data */

void __thiscall QInputDialog::~QInputDialog(QInputDialog *this)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c78e0 orig=FUN_011c78e0 size=1 name=operator>> ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void operator>>(QDataStream *param_1,QVariant *param_2)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c78e8 orig=FUN_011c78e8 size=1 name=QIcon ====

/* WARNING: Control flow encountered bad instruction data */

void __thiscall QIcon::QIcon(QIcon *this,QPixmap *param_1)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c78f0 orig=FUN_011c78f0 size=1 name=wheelEvent ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QTabBar::wheelEvent(QWheelEvent *param_1)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c78f8 orig=FUN_011c78f8 size=1 name=operator>> ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void operator>>(QDataStream *param_1,QString *param_2)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7900 orig=FUN_011c7900 size=1 name=init ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QStyleOption::init(QWidget *param_1)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7908 orig=FUN_011c7908 size=1 name=maximumSize ====

/* WARNING: Control flow encountered bad instruction data */

void QBoxLayout::maximumSize(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7910 orig=FUN_011c7910 size=1 name=pos ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QIODevice::pos(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7918 orig=FUN_011c7918 size=1 name=setFileTime ====

/* WARNING: Control flow encountered bad instruction data */

void QFileDevice::setFileTime(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7920 orig=FUN_011c7920 size=1 name=pthread_setspecific ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int pthread_setspecific(pthread_key_t __key,void *__pointer)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7928 orig=FUN_011c7928 size=1 name=QPainterPath ====

/* WARNING: Control flow encountered bad instruction data */

void __thiscall QPainterPath::QPainterPath(QPainterPath *this)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7930 orig=FUN_011c7930 size=1 name=y ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QWidget::y(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7938 orig=FUN_011c7938 size=1 name=setProcessChannelMode ====

/* WARNING: Control flow encountered bad instruction data */

void QProcess::setProcessChannelMode(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7940 orig=FUN_011c7940 size=1 name=QListView ====

/* WARNING: Control flow encountered bad instruction data */

void __thiscall QListView::QListView(QListView *this,QWidget *param_1)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7948 orig=FUN_011c7948 size=1 name=isTransactionStarted ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QIODevice::isTransactionStarted(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7950 orig=FUN_011c7950 size=1 name=hour ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QTime::hour(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7958 orig=FUN_011c7958 size=1 name=child ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QStandardItem::child(int param_1,int param_2)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7960 orig=FUN_011c7960 size=1 name=~QPersistentModelIndex ====

/* WARNING: Control flow encountered bad instruction data */

void __thiscall QPersistentModelIndex::~QPersistentModelIndex(QPersistentModelIndex *this)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7968 orig=FUN_011c7968 size=1 name=addButton ====

/* WARNING: Control flow encountered bad instruction data */

void QDialogButtonBox::addButton(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7970 orig=FUN_011c7970 size=1 name=QStandardItem ====

/* WARNING: Control flow encountered bad instruction data */

void __thiscall QStandardItem::QStandardItem(QStandardItem *this,QIcon *param_1,QString *param_2)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7978 orig=FUN_011c7978 size=1 name=roleNames ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QAbstractItemModel::roleNames(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7980 orig=FUN_011c7980 size=1 name=hasMatch ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QRegularExpressionMatch::hasMatch(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7988 orig=FUN_011c7988 size=1 name=QFileInfo ====

/* WARNING: Control flow encountered bad instruction data */

void __thiscall QFileInfo::QFileInfo(QFileInfo *this,QFile *param_1)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7990 orig=FUN_011c7990 size=1 name=ssh_key_free ====

/* WARNING: Control flow encountered bad instruction data */

void ssh_key_free(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7998 orig=FUN_011c7998 size=1 name=paintEvent ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QPushButton::paintEvent(QPaintEvent *param_1)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c79a0 orig=FUN_011c79a0 size=1 name=addPixmap ====

/* WARNING: Control flow encountered bad instruction data */

void QIcon::addPixmap(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c79a8 orig=FUN_011c79a8 size=1 name=setUpdatesEnabled ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QWidget::setUpdatesEnabled(bool param_1)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c79b0 orig=FUN_011c79b0 size=1 name=begin ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QPainter::begin(QPaintDevice *param_1)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c79b8 orig=FUN_011c79b8 size=1 name=__lxstat ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int __lxstat(int __ver,char *__filename,stat *__stat_buf)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c79c0 orig=FUN_011c79c0 size=1 name=inputMethodQuery ====

/* WARNING: Control flow encountered bad instruction data */

void QComboBox::inputMethodQuery(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c79c8 orig=FUN_011c79c8 size=1 name=operator[] ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QJsonObject::operator[](QString *param_1)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c79d0 orig=FUN_011c79d0 size=1 name=setShortcutEnabled ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QWidget::setShortcutEnabled(int param_1,bool param_2)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c79d8 orig=FUN_011c79d8 size=1 name=errorOccurred ====

/* WARNING: Control flow encountered bad instruction data */

void QLocalSocket::errorOccurred(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c79e0 orig=FUN_011c79e0 size=1 name=aboutToClose ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QIODevice::aboutToClose(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c79e8 orig=FUN_011c79e8 size=1 name=data ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QFileSystemModel::data(QModelIndex *param_1,int param_2)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c79f0 orig=FUN_011c79f0 size=1 name=disconnectNotify ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QObject::disconnectNotify(QMetaMethod *param_1)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c79f8 orig=FUN_011c79f8 size=1 name=setData ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QMimeData::setData(QString *param_1,QByteArray *param_2)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7a00 orig=FUN_011c7a00 size=1 name=addWidget ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QSplitter::addWidget(QWidget *param_1)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7a08 orig=FUN_011c7a08 size=1 name=flags ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QStandardItem::flags(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7a10 orig=FUN_011c7a10 size=1 name=inputMethodEvent ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QPlainTextEdit::inputMethodEvent(QInputMethodEvent *param_1)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7a18 orig=FUN_011c7a18 size=1 name=objectName ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QObject::objectName(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7a20 orig=FUN_011c7a20 size=1 name=setRawData ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QString::setRawData(QChar *param_1,int param_2)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7a28 orig=FUN_011c7a28 size=1 name=__strtof_l ====

/* WARNING: Control flow encountered bad instruction data */

void __strtof_l(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7a30 orig=FUN_011c7a30 size=1 name=activated ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QCompleter::activated(QString *param_1)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7a38 orig=FUN_011c7a38 size=1 name=toolButtonStyle ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QToolButton::toolButtonStyle(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7a48 orig=FUN_011c7a48 size=1 name=ssh_get_publickey_hash ====

/* WARNING: Control flow encountered bad instruction data */

void ssh_get_publickey_hash(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7a50 orig=FUN_011c7a50 size=1 name=setPen ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QPainter::setPen(QPen *param_1)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7a58 orig=FUN_011c7a58 size=1 name=keyPressEvent ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QPlainTextEdit::keyPressEvent(QKeyEvent *param_1)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7a60 orig=FUN_011c7a60 size=1 name=enterEvent ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QMenu::enterEvent(QEvent *param_1)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7a68 orig=FUN_011c7a68 size=1 name=addMSecs ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QDateTime::addMSecs(longlong param_1)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7a70 orig=FUN_011c7a70 size=1 name=mousePressEvent ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QLabel::mousePressEvent(QMouseEvent *param_1)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7a80 orig=FUN_011c7a80 size=1 name=~QUrl ====

/* WARNING: Control flow encountered bad instruction data */

void __thiscall QUrl::~QUrl(QUrl *this)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7a88 orig=FUN_011c7a88 size=1 name=setFlags ====

/* WARNING: Control flow encountered bad instruction data */

void QStandardItem::setFlags(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7a90 orig=FUN_011c7a90 size=1 name=mouseReleaseEvent ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QAbstractButton::mouseReleaseEvent(QMouseEvent *param_1)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7a98 orig=FUN_011c7a98 size=1 name=mouseReleaseEvent ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QScrollBar::mouseReleaseEvent(QMouseEvent *param_1)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7aa0 orig=FUN_011c7aa0 size=1 name=QTcpServer ====

/* WARNING: Control flow encountered bad instruction data */

void __thiscall QTcpServer::QTcpServer(QTcpServer *this,QObject *param_1)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7aa8 orig=FUN_011c7aa8 size=1 name=stateChanged ====

/* WARNING: Control flow encountered bad instruction data */

void QProcess::stateChanged(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7ab0 orig=FUN_011c7ab0 size=1 name=XOpenDisplay ====

/* WARNING: Control flow encountered bad instruction data */

void XOpenDisplay(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7ab8 orig=FUN_011c7ab8 size=1 name=setSectionResizeMode ====

/* WARNING: Control flow encountered bad instruction data */

void QHeaderView::setSectionResizeMode(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7ac0 orig=FUN_011c7ac0 size=1 name=rejected ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QDialogButtonBox::rejected(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7ac8 orig=FUN_011c7ac8 size=1 name=setWindowTitle ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QWidget::setWindowTitle(QString *param_1)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7ad0 orig=FUN_011c7ad0 size=1 name=removeRow ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QTableWidget::removeRow(int param_1)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7ad8 orig=FUN_011c7ad8 size=1 name=sftp_async_setstat ====

/* WARNING: Control flow encountered bad instruction data */

void sftp_async_setstat(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7ae0 orig=FUN_011c7ae0 size=1 name=indexIn ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QByteArrayMatcher::indexIn(QByteArray *param_1,int param_2)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7ae8 orig=FUN_011c7ae8 size=1 name=~QAbstractListModel ====

/* WARNING: Control flow encountered bad instruction data */

void __thiscall QAbstractListModel::~QAbstractListModel(QAbstractListModel *this)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7af0 orig=FUN_011c7af0 size=1 name=rgba ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QColor::rgba(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7af8 orig=FUN_011c7af8 size=1 name=mouseReleaseEvent ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QMenu::mouseReleaseEvent(QMouseEvent *param_1)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7b00 orig=FUN_011c7b00 size=1 name=owner ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QFileInfo::owner(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7b08 orig=FUN_011c7b08 size=1 name=qt_metacast ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QFileSystemModel::qt_metacast(char *param_1)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7b10 orig=FUN_011c7b10 size=1 name=isCallable ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QJSValue::isCallable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7b18 orig=FUN_011c7b18 size=1 name=operator= ====

/* WARNING: Control flow encountered bad instruction data */

void __thiscall QFont::operator=(QFont *this,QFont *param_1)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7b20 orig=FUN_011c7b20 size=1 name=~QProxyStyle ====

/* WARNING: Control flow encountered bad instruction data */

void __thiscall QProxyStyle::~QProxyStyle(QProxyStyle *this)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7b28 orig=FUN_011c7b28 size=1 name=handleWidth ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QSplitter::handleWidth(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7b30 orig=FUN_011c7b30 size=1 name=separator ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QDir::separator(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7b38 orig=FUN_011c7b38 size=1 name=chop ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QString::chop(int param_1)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7b40 orig=FUN_011c7b40 size=1 name=append ====

/* WARNING: Control flow encountered bad instruction data */

void QString::append(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7b48 orig=FUN_011c7b48 size=1 name=hasHeightForWidth ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QWidget::hasHeightForWidth(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7b50 orig=FUN_011c7b50 size=1 name=hasIndex ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QAbstractItemModel::hasIndex(int param_1,int param_2,QModelIndex *param_3)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7b58 orig=FUN_011c7b58 size=1 name=QVariant ====

/* WARNING: Control flow encountered bad instruction data */

void __thiscall QVariant::QVariant(QVariant *this,QByteArray *param_1)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7b60 orig=FUN_011c7b60 size=1 name=sizeHintForColumn ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QTableView::sizeHintForColumn(int param_1)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7b68 orig=FUN_011c7b68 size=1 name=qt_metacast ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QTableWidget::qt_metacast(char *param_1)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7b70 orig=FUN_011c7b70 size=1 name=setPen ====

/* WARNING: Control flow encountered bad instruction data */

void QPainter::setPen(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7b78 orig=FUN_011c7b78 size=1 name=isTabEnabled ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QTabBar::isTabEnabled(int param_1)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7b80 orig=FUN_011c7b80 size=1 name=QPushButton ====

/* WARNING: Control flow encountered bad instruction data */

void __thiscall QPushButton::QPushButton(QPushButton *this,QString *param_1,QWidget *param_2)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7b88 orig=FUN_011c7b88 size=1 name=toStringList ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QProcessEnvironment::toStringList(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7b90 orig=FUN_011c7b90 size=1 name=mkdir ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int mkdir(char *__path,__mode_t __mode)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7b98 orig=FUN_011c7b98 size=1 name=QTextEncoder ====

/* WARNING: Control flow encountered bad instruction data */

void __thiscall QTextEncoder::QTextEncoder(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7ba0 orig=FUN_011c7ba0 size=1 name=waitForReadyRead ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QAbstractSocket::waitForReadyRead(int param_1)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7ba8 orig=FUN_011c7ba8 size=1 name=setHeaderData ====

/* WARNING: Control flow encountered bad instruction data */

void QSortFilterProxyModel::setHeaderData(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7bb0 orig=FUN_011c7bb0 size=1 name=endInsertRows ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QAbstractItemModel::endInsertRows(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7bb8 orig=FUN_011c7bb8 size=1 name=XFlush ====

/* WARNING: Control flow encountered bad instruction data */

void XFlush(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7bc0 orig=FUN_011c7bc0 size=1 name=contains ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QJsonObject::contains(QString *param_1)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7bc8 orig=FUN_011c7bc8 size=1 name=resizeEvent ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QTabBar::resizeEvent(QResizeEvent *param_1)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7bd0 orig=FUN_011c7bd0 size=1 name=event ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QAbstractItemView::event(QEvent *param_1)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7bd8 orig=FUN_011c7bd8 size=1 name=QApplication ====

/* WARNING: Control flow encountered bad instruction data */

void __thiscall
QApplication::QApplication(QApplication *this,int *param_1,char **param_2,int param_3)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7be0 orig=FUN_011c7be0 size=1 name=nextCheckState ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QAbstractButton::nextCheckState(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7be8 orig=FUN_011c7be8 size=1 name=~QStorageInfo ====

/* WARNING: Control flow encountered bad instruction data */

void __thiscall QStorageInfo::~QStorageInfo(QStorageInfo *this)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7bf0 orig=FUN_011c7bf0 size=1 name=currentChanged ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QTableView::currentChanged(QModelIndex *param_1,QModelIndex *param_2)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7bf8 orig=FUN_011c7bf8 size=1 name=open ====

/* WARNING: Control flow encountered bad instruction data */

void QProcess::open(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7c00 orig=FUN_011c7c00 size=1 name=move ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QListData::move(int param_1,int param_2)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7c08 orig=FUN_011c7c08 size=1 name=~QFont ====

/* WARNING: Control flow encountered bad instruction data */

void __thiscall QFont::~QFont(QFont *this)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7c10 orig=FUN_011c7c10 size=1 name=removeRow ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QFormLayout::removeRow(QWidget *param_1)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7c18 orig=FUN_011c7c18 size=1 name=pen ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QPainter::pen(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7c20 orig=FUN_011c7c20 size=1 name=QVariant ====

/* WARNING: Control flow encountered bad instruction data */

void __thiscall QVariant::QVariant(QVariant *this,bool param_1)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7c28 orig=FUN_011c7c28 size=1 name=completeBaseName ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QFileInfo::completeBaseName(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7c30 orig=FUN_011c7c30 size=1 name=minimumSize ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QBoxLayout::minimumSize(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7c38 orig=FUN_011c7c38 size=1 name=paintingRoles ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QAbstractItemDelegate::paintingRoles(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7c40 orig=FUN_011c7c40 size=1 name=readData ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QProcess::readData(char *param_1,longlong param_2)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7c48 orig=FUN_011c7c48 size=1 name=setWindowIcon ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QApplication::setWindowIcon(QIcon *param_1)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7c58 orig=FUN_011c7c58 size=1 name=changeEvent ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QToolBar::changeEvent(QEvent *param_1)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7c60 orig=FUN_011c7c60 size=1 name=addRow ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QFormLayout::addRow(QLayout *param_1)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7c68 orig=FUN_011c7c68 size=1 name=prepend ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QByteArray::prepend(char param_1)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7c70 orig=FUN_011c7c70 size=1 name=setUniformItemSizes ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QListView::setUniformItemSizes(bool param_1)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7c80 orig=FUN_011c7c80 size=1 name=setCollapsible ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QSplitter::setCollapsible(int param_1,bool param_2)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7c88 orig=FUN_011c7c88 size=1 name=setFrame ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QLineEdit::setFrame(bool param_1)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7c90 orig=FUN_011c7c90 size=1 name=mousePressEvent ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QTabBar::mousePressEvent(QMouseEvent *param_1)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7c98 orig=FUN_011c7c98 size=1 name=newConnection ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QTcpServer::newConnection(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7ca0 orig=FUN_011c7ca0 size=1 name=itemSelectionChanged ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QTableWidget::itemSelectionChanged(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7ca8 orig=FUN_011c7ca8 size=1 name=methodOffset ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QMetaObject::methodOffset(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7cb0 orig=FUN_011c7cb0 size=1 name=toSizeF ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QVariant::toSizeF(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7cb8 orig=FUN_011c7cb8 size=1 name=setTabChangesFocus ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QPlainTextEdit::setTabChangesFocus(bool param_1)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7cc0 orig=FUN_011c7cc0 size=1 name=checkState ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QCheckBox::checkState(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7cc8 orig=FUN_011c7cc8 size=1 name=QFileInfo ====

/* WARNING: Control flow encountered bad instruction data */

void __thiscall QFileInfo::QFileInfo(QFileInfo *this)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7cd0 orig=FUN_011c7cd0 size=1 name=move ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QWidget::move(QPoint *param_1)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7cd8 orig=FUN_011c7cd8 size=1 name=readlink ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

ssize_t readlink(char *__path,char *__buf,size_t __len)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7ce0 orig=FUN_011c7ce0 size=1 name=__stack_chk_fail ====

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7ce8 orig=FUN_011c7ce8 size=1 name=className ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QMetaObject::className(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7cf0 orig=FUN_011c7cf0 size=1 name=heightForWidth ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QBoxLayout::heightForWidth(int param_1)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7cf8 orig=FUN_011c7cf8 size=1 name=reset ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QAbstractItemView::reset(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7d00 orig=FUN_011c7d00 size=1 name=setText ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QLabel::setText(QString *param_1)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7d08 orig=FUN_011c7d08 size=1 name=operator= ====

/* WARNING: Control flow encountered bad instruction data */

void __thiscall QString::operator=(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7d10 orig=FUN_011c7d10 size=1 name=QFileDialog ====

/* WARNING: Control flow encountered bad instruction data */

void __thiscall
QFileDialog::QFileDialog
          (QFileDialog *this,QWidget *param_1,QString *param_2,QString *param_3,QString *param_4)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7d18 orig=FUN_011c7d18 size=1 name=qt_metacall ====

/* WARNING: Control flow encountered bad instruction data */

void QThread::qt_metacall(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7d20 orig=FUN_011c7d20 size=1 name=~QTranslator ====

/* WARNING: Control flow encountered bad instruction data */

void __thiscall QTranslator::~QTranslator(QTranslator *this)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7d28 orig=FUN_011c7d28 size=1 name=drawControl ====

/* WARNING: Control flow encountered bad instruction data */

void QProxyStyle::drawControl(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7d30 orig=FUN_011c7d30 size=1 name=mapToSource ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QSortFilterProxyModel::mapToSource(QModelIndex *param_1)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7d38 orig=FUN_011c7d38 size=1 name=maximumSize ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QBoxLayout::maximumSize(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7d40 orig=FUN_011c7d40 size=1 name=setEnabled ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QWidget::setEnabled(bool param_1)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7d48 orig=FUN_011c7d48 size=1 name=memset ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memset(void *__s,int __c,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7d50 orig=FUN_011c7d50 size=1 name=mouseReleaseEvent ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QListView::mouseReleaseEvent(QMouseEvent *param_1)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7d58 orig=FUN_011c7d58 size=1 name=isIndexHidden ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QListView::isIndexHidden(QModelIndex *param_1)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7d60 orig=FUN_011c7d60 size=1 name=visualRect ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QTableView::visualRect(QModelIndex *param_1)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7d68 orig=FUN_011c7d68 size=1 name=focusWidget ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QWidget::focusWidget(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7d70 orig=FUN_011c7d70 size=1 name=canReadLine ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QProcess::canReadLine(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7d78 orig=FUN_011c7d78 size=1 name=createData ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QMapDataBase::createData(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7d80 orig=FUN_011c7d80 size=1 name=EVP_CipherUpdate ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int EVP_CipherUpdate(EVP_CIPHER_CTX *ctx,uchar *out,int *outl,uchar *in,int inl)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7d88 orig=FUN_011c7d88 size=1 name=number ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QString::number(uint param_1,int param_2)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7d90 orig=FUN_011c7d90 size=1 name=QJsonValue ====

/* WARNING: Control flow encountered bad instruction data */

void __thiscall QJsonValue::QJsonValue(QJsonValue *this,QJsonObject *param_1)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7d98 orig=FUN_011c7d98 size=1 name=getSaveFileName ====

/* WARNING: Control flow encountered bad instruction data */

void QFileDialog::getSaveFileName(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7da0 orig=FUN_011c7da0 size=1 name=systemEnvironment ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QProcessEnvironment::systemEnvironment(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7da8 orig=FUN_011c7da8 size=1 name=setColor ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QBrush::setColor(QColor *param_1)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7db0 orig=FUN_011c7db0 size=1 name=sscanf ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int sscanf(char *__s,char *__format,...)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7db8 orig=FUN_011c7db8 size=1 name=mid ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QtPrivate::QContainerImplHelper::mid(int param_1,int *param_2,int *param_3)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7dc0 orig=FUN_011c7dc0 size=1 name=addAction ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QMenu::addAction(QIcon *param_1,QString *param_2)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7dc8 orig=FUN_011c7dc8 size=1 name=toLower_helper ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QByteArray::toLower_helper(QByteArray *param_1)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7dd0 orig=FUN_011c7dd0 size=1 name=alignment ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QLabel::alignment(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7dd8 orig=FUN_011c7dd8 size=1 name=showMinimized ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QWidget::showMinimized(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7de0 orig=FUN_011c7de0 size=1 name=mid ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QString::mid(int param_1,int param_2)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7de8 orig=FUN_011c7de8 size=1 name=QSocketNotifier ====

/* WARNING: Control flow encountered bad instruction data */

void __thiscall QSocketNotifier::QSocketNotifier(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7df0 orig=FUN_011c7df0 size=1 name=escape ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QRegularExpression::escape(QString *param_1)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7df8 orig=FUN_011c7df8 size=1 name=contextMenuEvent ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QLineEdit::contextMenuEvent(QContextMenuEvent *param_1)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7e00 orig=FUN_011c7e00 size=1 name=create ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QJSEngine::create(int param_1,void *param_2)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7e08 orig=FUN_011c7e08 size=1 name=disconnectImpl ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QObject::disconnectImpl
               (QObject *param_1,void **param_2,QObject *param_3,void **param_4,QMetaObject *param_5
               )

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7e10 orig=FUN_011c7e10 size=1 name=fputs ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int fputs(char *__s,FILE *__stream)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7e18 orig=FUN_011c7e18 size=1 name=comment ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QMimeType::comment(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7e20 orig=FUN_011c7e20 size=1 name=ssh_userauth_none ====

/* WARNING: Control flow encountered bad instruction data */

void ssh_userauth_none(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7e28 orig=FUN_011c7e28 size=1 name=sin ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

double sin(double __x)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7e30 orig=FUN_011c7e30 size=1 name=QFontDatabase ====

/* WARNING: Control flow encountered bad instruction data */

void __thiscall QFontDatabase::QFontDatabase(QFontDatabase *this)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7e38 orig=FUN_011c7e38 size=1 name=mimeData ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QFileSystemModel::mimeData(QList *param_1)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7e40 orig=FUN_011c7e40 size=1 name=urls ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QMimeData::urls(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7e50 orig=FUN_011c7e50 size=1 name=QNetworkProxy ====

/* WARNING: Control flow encountered bad instruction data */

void __thiscall QNetworkProxy::QNetworkProxy(QNetworkProxy *this,QNetworkProxy *param_1)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7e58 orig=FUN_011c7e58 size=1 name=append ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QString::append(QChar *param_1,int param_2)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7e60 orig=FUN_011c7e60 size=1 name=cmp ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QVariant::cmp(QVariant *param_1)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7e68 orig=FUN_011c7e68 size=1 name=drawPolygon ====

/* WARNING: Control flow encountered bad instruction data */

void QPainter::drawPolygon(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7e70 orig=FUN_011c7e70 size=1 name=QComboBox ====

/* WARNING: Control flow encountered bad instruction data */

void __thiscall QComboBox::QComboBox(QComboBox *this,QWidget *param_1)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7e78 orig=FUN_011c7e78 size=1 name=toHex ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QByteArray::toHex(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7e80 orig=FUN_011c7e80 size=1 name=setErrorString ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QIODevice::setErrorString(QString *param_1)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7e88 orig=FUN_011c7e88 size=1 name=createEditor ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QStyledItemDelegate::createEditor
               (QWidget *param_1,QStyleOptionViewItem *param_2,QModelIndex *param_3)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7e90 orig=FUN_011c7e90 size=1 name=QImage ====

/* WARNING: Control flow encountered bad instruction data */

void __thiscall QImage::QImage(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7e98 orig=FUN_011c7e98 size=1 name=id ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QButtonGroup::id(QAbstractButton *param_1)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7ea0 orig=FUN_011c7ea0 size=1 name=isColumnHidden ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QTableView::isColumnHidden(int param_1)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7ea8 orig=FUN_011c7ea8 size=1 name=pthread_cond_destroy ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int pthread_cond_destroy(pthread_cond_t *__cond)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7eb0 orig=FUN_011c7eb0 size=1 name=lastIndexOf ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QString::lastIndexOf(QRegularExpression *param_1,int param_2)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7eb8 orig=FUN_011c7eb8 size=1 name=QMenu ====

/* WARNING: Control flow encountered bad instruction data */

void __thiscall QMenu::QMenu(QMenu *this,QString *param_1,QWidget *param_2)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7ec0 orig=FUN_011c7ec0 size=1 name=protocol ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QHostAddress::protocol(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7ec8 orig=FUN_011c7ec8 size=1 name=setCaseSensitivity ====

/* WARNING: Control flow encountered bad instruction data */

void QRegExp::setCaseSensitivity(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7ed0 orig=FUN_011c7ed0 size=1 name=setTextMargins ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QLineEdit::setTextMargins(int param_1,int param_2,int param_3,int param_4)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7ed8 orig=FUN_011c7ed8 size=1 name=contextMenuEvent ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QWidget::contextMenuEvent(QContextMenuEvent *param_1)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7ee0 orig=FUN_011c7ee0 size=1 name=ssh_channel_read_nonblocking ====

/* WARNING: Control flow encountered bad instruction data */

void ssh_channel_read_nonblocking(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7ee8 orig=FUN_011c7ee8 size=1 name=setFocusPolicy ====

/* WARNING: Control flow encountered bad instruction data */

void QWidget::setFocusPolicy(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7ef0 orig=FUN_011c7ef0 size=1 name=paintEvent ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QMenu::paintEvent(QPaintEvent *param_1)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7ef8 orig=FUN_011c7ef8 size=1 name=loadResource ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QPlainTextEdit::loadResource(int param_1,QUrl *param_2)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7f00 orig=FUN_011c7f00 size=1 name=QLabel ====

/* WARNING: Control flow encountered bad instruction data */

void __thiscall QLabel::QLabel(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7f08 orig=FUN_011c7f08 size=1 name=utf16 ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QString::utf16(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7f10 orig=FUN_011c7f10 size=1 name=ssh_channel_free ====

/* WARNING: Control flow encountered bad instruction data */

void ssh_channel_free(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7f18 orig=FUN_011c7f18 size=1 name=setLineWrapMode ====

/* WARNING: Control flow encountered bad instruction data */

void QPlainTextEdit::setLineWrapMode(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7f20 orig=FUN_011c7f20 size=1 name=setChecked ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QAbstractButton::setChecked(bool param_1)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7f28 orig=FUN_011c7f28 size=1 name=setTabText ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QTabBar::setTabText(int param_1,QString *param_2)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7f30 orig=FUN_011c7f30 size=1 name=windowState ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QWidget::windowState(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7f38 orig=FUN_011c7f38 size=1 name=contextMenuEvent ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QAbstractSpinBox::contextMenuEvent(QContextMenuEvent *param_1)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7f40 orig=FUN_011c7f40 size=1 name=itemTextRect ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QProxyStyle::itemTextRect
               (QFontMetrics *param_1,QRect *param_2,int param_3,bool param_4,QString *param_5)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7f48 orig=FUN_011c7f48 size=1 name=setFrameShadow ====

/* WARNING: Control flow encountered bad instruction data */

void QFrame::setFrameShadow(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7f50 orig=FUN_011c7f50 size=1 name=link ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QFile::link(QString *param_1,QString *param_2)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7f58 orig=FUN_011c7f58 size=1 name=dropIndicatorPosition ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QAbstractItemView::dropIndicatorPosition(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7f60 orig=FUN_011c7f60 size=1 name=pthread_once ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int pthread_once(pthread_once_t *__once_control,__init_routine *__init_routine)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7f68 orig=FUN_011c7f68 size=1 name=ssh_channel_request_x11 ====

/* WARNING: Control flow encountered bad instruction data */

void ssh_channel_request_x11(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7f70 orig=FUN_011c7f70 size=1 name=insertColumns ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QSortFilterProxyModel::insertColumns(int param_1,int param_2,QModelIndex *param_3)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7f78 orig=FUN_011c7f78 size=1 name=textFromValue ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QSpinBox::textFromValue(int param_1)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7f80 orig=FUN_011c7f80 size=1 name=QTableWidget ====

/* WARNING: Control flow encountered bad instruction data */

void __thiscall QTableWidget::QTableWidget(QTableWidget *this,QWidget *param_1)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7f88 orig=FUN_011c7f88 size=1 name=widgetAt ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QApplication::widgetAt(QPoint *param_1)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7f90 orig=FUN_011c7f90 size=1 name=singleStep ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QAbstractSlider::singleStep(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7f98 orig=FUN_011c7f98 size=1 name=currentIndex ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QItemSelectionModel::currentIndex(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7fa0 orig=FUN_011c7fa0 size=1 name=globalObject ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QJSEngine::globalObject(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7fa8 orig=FUN_011c7fa8 size=1 name=append ====

/* WARNING: Control flow encountered bad instruction data */

void QString::append(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7fb0 orig=FUN_011c7fb0 size=1 name=strlen ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

size_t strlen(char *__s)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7fb8 orig=FUN_011c7fb8 size=1 name=waitForReadyRead ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QProcess::waitForReadyRead(int param_1)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7fc0 orig=FUN_011c7fc0 size=1 name=name ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QLocale::name(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7fc8 orig=FUN_011c7fc8 size=1 name=wcsnrtombs ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

size_t wcsnrtombs(char *__dst,wchar_t **__src,size_t __nwc,size_t __len,mbstate_t *__ps)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7fd0 orig=FUN_011c7fd0 size=1 name=rootPath ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QStorageInfo::rootPath(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7fd8 orig=FUN_011c7fd8 size=1 name=localHostName ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QHostInfo::localHostName(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7fe0 orig=FUN_011c7fe0 size=1 name=pthread_mutex_init ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int pthread_mutex_init(pthread_mutex_t *__mutex,pthread_mutexattr_t *__mutexattr)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7fe8 orig=FUN_011c7fe8 size=1 name=toVariant ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QJSValue::toVariant(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7ff0 orig=FUN_011c7ff0 size=1 name=insertRows ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QSortFilterProxyModel::insertRows(int param_1,int param_2,QModelIndex *param_3)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c7ff8 orig=FUN_011c7ff8 size=1 name=clipboard ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QGuiApplication::clipboard(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c8000 orig=FUN_011c8000 size=1 name=setModelData ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QStyledItemDelegate::setModelData
               (QWidget *param_1,QAbstractItemModel *param_2,QModelIndex *param_3)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c8008 orig=FUN_011c8008 size=1 name=setArguments ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QProcess::setArguments(QStringList *param_1)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c8010 orig=FUN_011c8010 size=1 name=QPlainTextEdit ====

/* WARNING: Control flow encountered bad instruction data */

void __thiscall QPlainTextEdit::QPlainTextEdit(QPlainTextEdit *this,QWidget *param_1)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c8018 orig=FUN_011c8018 size=1 name=verticalScrollbarAction ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QAbstractItemView::verticalScrollbarAction(int param_1)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c8020 orig=FUN_011c8020 size=1 name=drawLines ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QPainter::drawLines(QLineF *param_1,int param_2)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c8028 orig=FUN_011c8028 size=1 name=qt_metacast ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QLineEdit::qt_metacast(char *param_1)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c8030 orig=FUN_011c8030 size=1 name=sftp_async_opendir ====

/* WARNING: Control flow encountered bad instruction data */

void sftp_async_opendir(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c8038 orig=FUN_011c8038 size=1 name=QListWidgetItem ====

/* WARNING: Control flow encountered bad instruction data */

void __thiscall
QListWidgetItem::QListWidgetItem
          (QListWidgetItem *this,QIcon *param_1,QString *param_2,QListWidget *param_3,int param_4)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c8040 orig=FUN_011c8040 size=1 name=~QDoubleSpinBox ====

/* WARNING: Control flow encountered bad instruction data */

void __thiscall QDoubleSpinBox::~QDoubleSpinBox(QDoubleSpinBox *this)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c8048 orig=FUN_011c8048 size=1 name=isChecked ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QAbstractButton::isChecked(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c8050 orig=FUN_011c8050 size=1 name=toNativeSeparators ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QDir::toNativeSeparators(QString *param_1)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c8058 orig=FUN_011c8058 size=1 name=families ====

/* WARNING: Control flow encountered bad instruction data */

void QFontDatabase::families(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c8060 orig=FUN_011c8060 size=1 name=QTimer ====

/* WARNING: Control flow encountered bad instruction data */

void __thiscall QTimer::QTimer(QTimer *this,QObject *param_1)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c8068 orig=FUN_011c8068 size=1 name=isEmpty ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QTranslator::isEmpty(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c8070 orig=FUN_011c8070 size=1 name=headerData ====

/* WARNING: Control flow encountered bad instruction data */

void QSortFilterProxyModel::headerData(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c8078 orig=FUN_011c8078 size=1 name=remove ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QListData::remove(int param_1)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c8080 orig=FUN_011c8080 size=1 name=information ====

/* WARNING: Control flow encountered bad instruction data */

void QMessageBox::information(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c8088 orig=FUN_011c8088 size=1 name=geometry ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QLayout::geometry(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c8090 orig=FUN_011c8090 size=1 name=childEvent ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QSplitter::childEvent(QChildEvent *param_1)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c8098 orig=FUN_011c8098 size=1 name=activeWindow ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QApplication::activeWindow(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c80a0 orig=FUN_011c80a0 size=1 name=setCheckState ====

/* WARNING: Control flow encountered bad instruction data */

void QCheckBox::setCheckState(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c80a8 orig=FUN_011c80a8 size=1 name=toPlainText ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QTextDocument::toPlainText(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c80b0 orig=FUN_011c80b0 size=1 name=getgrgid ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

group * getgrgid(__gid_t __gid)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c80b8 orig=FUN_011c80b8 size=1 name=allocate ====

/* WARNING: Control flow encountered bad instruction data */

void QArrayData::allocate(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c80c0 orig=FUN_011c80c0 size=1 name=codecForName ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QTextCodec::codecForName(QByteArray *param_1)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c80c8 orig=FUN_011c80c8 size=1 name=minimumSize ====

/* WARNING: Control flow encountered bad instruction data */

void QBoxLayout::minimumSize(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c80d0 orig=FUN_011c80d0 size=1 name=QFontMetricsF ====

/* WARNING: Control flow encountered bad instruction data */

void __thiscall
QFontMetricsF::QFontMetricsF(QFontMetricsF *this,QFont *param_1,QPaintDevice *param_2)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c80d8 orig=FUN_011c80d8 size=1 name=timerEvent ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QAbstractSpinBox::timerEvent(QTimerEvent *param_1)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c80e0 orig=FUN_011c80e0 size=1 name=QSpinBox ====

/* WARNING: Control flow encountered bad instruction data */

void __thiscall QSpinBox::QSpinBox(QSpinBox *this,QWidget *param_1)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c80e8 orig=FUN_011c80e8 size=1 name=QSignalMapper ====

/* WARNING: Control flow encountered bad instruction data */

void __thiscall QSignalMapper::QSignalMapper(QSignalMapper *this,QObject *param_1)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c80f0 orig=FUN_011c80f0 size=1 name=QStringList_contains ====

/* WARNING: Control flow encountered bad instruction data */

void QtPrivate::QStringList_contains(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c80f8 orig=FUN_011c80f8 size=1 name=fromRgba ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QColor::fromRgba(uint param_1)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c8108 orig=FUN_011c8108 size=1 name=~QEvent ====

/* WARNING: Control flow encountered bad instruction data */

void __thiscall QEvent::~QEvent(QEvent *this)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c8110 orig=FUN_011c8110 size=1 name=restoreGeometry ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QWidget::restoreGeometry(QByteArray *param_1)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c8120 orig=FUN_011c8120 size=1 name=fclose ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int fclose(FILE *__stream)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c8128 orig=FUN_011c8128 size=1 name=QTreeView ====

/* WARNING: Control flow encountered bad instruction data */

void __thiscall QTreeView::QTreeView(QTreeView *this,QWidget *param_1)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c8130 orig=FUN_011c8130 size=1 name=setsid ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

__pid_t setsid(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c8138 orig=FUN_011c8138 size=1 name=start ====

/* WARNING: Control flow encountered bad instruction data */

void QProcess::start(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c8140 orig=FUN_011c8140 size=1 name=waitForBytesWritten ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QProcess::waitForBytesWritten(int param_1)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c8148 orig=FUN_011c8148 size=1 name=~QTcpServer ====

/* WARNING: Control flow encountered bad instruction data */

void __thiscall QTcpServer::~QTcpServer(QTcpServer *this)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c8150 orig=FUN_011c8150 size=1 name=error ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QSerialPort::error(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c8158 orig=FUN_011c8158 size=1 name=simplified_helper ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QString::simplified_helper(QString *param_1)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c8160 orig=FUN_011c8160 size=1 name=ssh_channel_request_send_signal ====

/* WARNING: Control flow encountered bad instruction data */

void ssh_channel_request_send_signal(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c8168 orig=FUN_011c8168 size=1 name=QDialogButtonBox ====

/* WARNING: Control flow encountered bad instruction data */

void __thiscall QDialogButtonBox::QDialogButtonBox(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c8170 orig=FUN_011c8170 size=1 name=hasExpired ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QDeadlineTimer::hasExpired(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c8178 orig=FUN_011c8178 size=1 name=addWidget ====

/* WARNING: Control flow encountered bad instruction data */

void QGridLayout::addWidget(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c8180 orig=FUN_011c8180 size=1 name=setFilter ====

/* WARNING: Control flow encountered bad instruction data */

void QDir::setFilter(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c8188 orig=FUN_011c8188 size=1 name=setWindowModified ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QWidget::setWindowModified(bool param_1)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c8190 orig=FUN_011c8190 size=1 name=activateWindow ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QWidget::activateWindow(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c8198 orig=FUN_011c8198 size=1 name=QPen ====

/* WARNING: Control flow encountered bad instruction data */

void __thiscall QPen::QPen(QPen *this)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c81a0 orig=FUN_011c81a0 size=1 name=event ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QTabBar::event(QEvent *param_1)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c81a8 orig=FUN_011c81a8 size=1 name=qt_metacall ====

/* WARNING: Control flow encountered bad instruction data */

void QStatusBar::qt_metacall(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c81b0 orig=FUN_011c81b0 size=1 name=insert ====

/* WARNING: Control flow encountered bad instruction data */

void QString::insert(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c81b8 orig=FUN_011c81b8 size=1 name=setNumericMode ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QCollator::setNumericMode(bool param_1)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c81c0 orig=FUN_011c81c0 size=1 name=setStandardButtons ====

/* WARNING: Control flow encountered bad instruction data */

void QMessageBox::setStandardButtons(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c81c8 orig=FUN_011c81c8 size=1 name=setEnabled ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QStandardItem::setEnabled(bool param_1)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c81d0 orig=FUN_011c81d0 size=1 name=wmemset ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

wchar_t * wmemset(wchar_t *__s,wchar_t __c,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c81d8 orig=FUN_011c81d8 size=1 name=addWidget ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QLayout::addWidget(QWidget *param_1)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c81e0 orig=FUN_011c81e0 size=1 name=currentSecsSinceEpoch ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QDateTime::currentSecsSinceEpoch(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c81e8 orig=FUN_011c81e8 size=1 name=focusInEvent ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QPushButton::focusInEvent(QFocusEvent *param_1)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c81f0 orig=FUN_011c81f0 size=1 name=prepend ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QByteArray::prepend(QByteArray *param_1)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c81f8 orig=FUN_011c81f8 size=1 name=sftp_new2 ====

/* WARNING: Control flow encountered bad instruction data */

void sftp_new2(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c8200 orig=FUN_011c8200 size=1 name=clear ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QPlainTextEdit::clear(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c8208 orig=FUN_011c8208 size=1 name=insertWidget ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QStackedWidget::insertWidget(int param_1,QWidget *param_2)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c8210 orig=FUN_011c8210 size=1 name=addItem ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QBoxLayout::addItem(QLayoutItem *param_1)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c8218 orig=FUN_011c8218 size=1 name=isalnum ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int isalnum(int param_1)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c8220 orig=FUN_011c8220 size=1 name=typeName ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QMetaType::typeName(int param_1)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c8228 orig=FUN_011c8228 size=1 name=setValue ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QProgressBar::setValue(int param_1)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c8230 orig=FUN_011c8230 size=1 name=unlock ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QReadWriteLock::unlock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c8238 orig=FUN_011c8238 size=1 name=setAutoDefault ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QPushButton::setAutoDefault(bool param_1)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c8240 orig=FUN_011c8240 size=1 name=listen ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QTcpServer::listen(QHostAddress *param_1,ushort param_2)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c8248 orig=FUN_011c8248 size=1 name=freeNode ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QHashData::freeNode(void *param_1)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c8250 orig=FUN_011c8250 size=1 name=absoluteFilePath ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QDir::absoluteFilePath(QString *param_1)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c8258 orig=FUN_011c8258 size=1 name=drawBranches ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QTreeView::drawBranches(QPainter *param_1,QRect *param_2,QModelIndex *param_3)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c8268 orig=FUN_011c8268 size=1 name=operator>> ====

/* WARNING: Control flow encountered bad instruction data */

void __thiscall QDataStream::operator>>(QDataStream *this,double *param_1)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c8270 orig=FUN_011c8270 size=1 name=pthread_attr_getdetachstate ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int pthread_attr_getdetachstate(pthread_attr_t *__attr,int *__detachstate)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c8278 orig=FUN_011c8278 size=1 name=setAttribute ====

/* WARNING: Control flow encountered bad instruction data */

void QWidget::setAttribute(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c8280 orig=FUN_011c8280 size=1 name=strstr ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * strstr(char *__haystack,char *__needle)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c8288 orig=FUN_011c8288 size=1 name=QSortFilterProxyModel ====

/* WARNING: Control flow encountered bad instruction data */

void __thiscall
QSortFilterProxyModel::QSortFilterProxyModel(QSortFilterProxyModel *this,QObject *param_1)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c8290 orig=FUN_011c8290 size=1 name=~QFile ====

/* WARNING: Control flow encountered bad instruction data */

void __thiscall QFile::~QFile(QFile *this)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c8298 orig=FUN_011c8298 size=1 name=_M_append ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void std::__cxx11::string::_M_append(char *param_1,ulong param_2)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c82a0 orig=FUN_011c82a0 size=1 name=QVariant ====

/* WARNING: Control flow encountered bad instruction data */

void __thiscall QVariant::QVariant(QVariant *this,QList *param_1)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c82a8 orig=FUN_011c82a8 size=1 name=sftp_limits ====

/* WARNING: Control flow encountered bad instruction data */

void sftp_limits(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c82b0 orig=FUN_011c82b0 size=1 name=actualSize ====

/* WARNING: Control flow encountered bad instruction data */

void QIconEngine::actualSize(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c82b8 orig=FUN_011c82b8 size=1 name=EVP_CipherInit_ex ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int EVP_CipherInit_ex(EVP_CIPHER_CTX *ctx,EVP_CIPHER *cipher,ENGINE *impl,uchar *key,uchar *iv,
                     int enc)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c82c0 orig=FUN_011c82c0 size=1 name=placeholderText ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QComboBox::placeholderText(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c82c8 orig=FUN_011c82c8 size=1 name=paintEvent ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QTableView::paintEvent(QPaintEvent *param_1)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c82d0 orig=FUN_011c82d0 size=1 name=qt_metacall ====

/* WARNING: Control flow encountered bad instruction data */

void QStandardItemModel::qt_metacall(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c82d8 orig=FUN_011c82d8 size=1 name=aio_return ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

__ssize_t aio_return(aiocb *__aiocbp)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c82e0 orig=FUN_011c82e0 size=1 name=scrollTo ====

/* WARNING: Control flow encountered bad instruction data */

void QTableView::scrollTo(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c82e8 orig=FUN_011c82e8 size=1 name=indexOf ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QLayout::indexOf(QWidget *param_1)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c82f0 orig=FUN_011c82f0 size=1 name=rightJustified ====

/* WARNING: Control flow encountered bad instruction data */

void QString::rightJustified(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c82f8 orig=FUN_011c82f8 size=1 name=bind_textdomain_codeset ====

/* WARNING: Control flow encountered bad instruction data */

void bind_textdomain_codeset(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c8300 orig=FUN_011c8300 size=1 name=selectAll ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QTreeView::selectAll(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c8308 orig=FUN_011c8308 size=1 name=addLayout ====

/* WARNING: Control flow encountered bad instruction data */

void QGridLayout::addLayout(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c8310 orig=FUN_011c8310 size=1 name=readAllStandardError ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QProcess::readAllStandardError(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c8318 orig=FUN_011c8318 size=1 name=operator<< ====

/* WARNING: Control flow encountered bad instruction data */

void __thiscall QDataStream::operator<<(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c8320 orig=FUN_011c8320 size=1 name=mimeTypeForUrl ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QMimeDatabase::mimeTypeForUrl(QUrl *param_1)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c8328 orig=FUN_011c8328 size=1 name=painter ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QPaintEngine::painter(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c8330 orig=FUN_011c8330 size=1 name=sortKey ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QCollator::sortKey(QString *param_1)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c8338 orig=FUN_011c8338 size=1 name=uniformItemSizes ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QListView::uniformItemSizes(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c8340 orig=FUN_011c8340 size=1 name=sftp_file_set_nonblocking ====

/* WARNING: Control flow encountered bad instruction data */

void sftp_file_set_nonblocking(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c8348 orig=FUN_011c8348 size=1 name=~QDateTime ====

/* WARNING: Control flow encountered bad instruction data */

void __thiscall QDateTime::~QDateTime(QDateTime *this)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c8350 orig=FUN_011c8350 size=1 name=bytesToWrite ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QAbstractSocket::bytesToWrite(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c8358 orig=FUN_011c8358 size=1 name=appendHtml ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QPlainTextEdit::appendHtml(QString *param_1)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c8360 orig=FUN_011c8360 size=1 name=find_first_not_of ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void std::__cxx11::string::find_first_not_of(char param_1,ulong param_2)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c8368 orig=FUN_011c8368 size=1 name=sqrt ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

double sqrt(double __x)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c8370 orig=FUN_011c8370 size=1 name=tabAt ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QTabBar::tabAt(QPoint *param_1)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c8378 orig=FUN_011c8378 size=1 name=ssh_pki_import_privkey_file ====

/* WARNING: Control flow encountered bad instruction data */

void ssh_pki_import_privkey_file(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c8380 orig=FUN_011c8380 size=1 name=operator[] ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QKeySequence::operator[](uint param_1)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c8388 orig=FUN_011c8388 size=1 name=dynamicSortFilter ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QSortFilterProxyModel::dynamicSortFilter(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c8390 orig=FUN_011c8390 size=1 name=append ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QString::append(QStringRef *param_1)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c8398 orig=FUN_011c8398 size=1 name=update ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QWidget::update(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c83a0 orig=FUN_011c83a0 size=1 name=qt_metacast ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QComboBox::qt_metacast(char *param_1)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c83a8 orig=FUN_011c83a8 size=1 name=itemAtPosition ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QGridLayout::itemAtPosition(int param_1,int param_2)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c83b0 orig=FUN_011c83b0 size=1 name=metaObject ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QStandardItemModel::metaObject(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c83b8 orig=FUN_011c83b8 size=1 name=readLineInto ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QTextStream::readLineInto(QString *param_1,longlong param_2)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c83c0 orig=FUN_011c83c0 size=1 name=deallocate ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QArrayData::deallocate(QArrayData *param_1,ulong param_2,ulong param_3)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c83d0 orig=FUN_011c83d0 size=1 name=QProcess ====

/* WARNING: Control flow encountered bad instruction data */

void __thiscall QProcess::QProcess(QProcess *this,QObject *param_1)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c83d8 orig=FUN_011c83d8 size=1 name=setCompleter ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QComboBox::setCompleter(QCompleter *param_1)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c83e0 orig=FUN_011c83e0 size=1 name=QDialog ====

/* WARNING: Control flow encountered bad instruction data */

void __thiscall QDialog::QDialog(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c83e8 orig=FUN_011c83e8 size=1 name=~QKeyEvent ====

/* WARNING: Control flow encountered bad instruction data */

void __thiscall QKeyEvent::~QKeyEvent(QKeyEvent *this)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c83f0 orig=FUN_011c83f0 size=1 name=setData ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QAction::setData(QVariant *param_1)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c83f8 orig=FUN_011c83f8 size=1 name=qt_metacall ====

/* WARNING: Control flow encountered bad instruction data */

void QPushButton::qt_metacall(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c8400 orig=FUN_011c8400 size=1 name=index ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QSortFilterProxyModel::index(int param_1,int param_2,QModelIndex *param_3)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c8408 orig=FUN_011c8408 size=1 name=fflush ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int fflush(FILE *__stream)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c8410 orig=FUN_011c8410 size=1 name=setModel ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QCompleter::setModel(QAbstractItemModel *param_1)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c8418 orig=FUN_011c8418 size=1 name=menu ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QPushButton::menu(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c8420 orig=FUN_011c8420 size=1 name=event ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QSplitter::event(QEvent *param_1)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c8428 orig=FUN_011c8428 size=1 name=sourceModelChanged ====

/* WARNING: Control flow encountered bad instruction data */

void QAbstractProxyModel::sourceModelChanged(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c8430 orig=FUN_011c8430 size=1 name=showPopup ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QComboBox::showPopup(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c8440 orig=FUN_011c8440 size=1 name=strtold_l ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

double strtold_l(char *__nptr,char **__endptr,__locale_t __loc)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c8448 orig=FUN_011c8448 size=1 name=addMenu ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QMenu::addMenu(QString *param_1)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c8450 orig=FUN_011c8450 size=1 name=XQueryPointer ====

/* WARNING: Control flow encountered bad instruction data */

void XQueryPointer(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c8458 orig=FUN_011c8458 size=1 name=compare ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void std::__cxx11::string::compare(char *param_1)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c8460 orig=FUN_011c8460 size=1 name=changeEvent ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QAbstractSpinBox::changeEvent(QEvent *param_1)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c8470 orig=FUN_011c8470 size=1 name=pthread_key_delete ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int pthread_key_delete(pthread_key_t __key)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c8478 orig=FUN_011c8478 size=1 name=setNameFilters ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QFileDialog::setNameFilters(QStringList *param_1)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c8480 orig=FUN_011c8480 size=1 name=activePopupWidget ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QApplication::activePopupWidget(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c8488 orig=FUN_011c8488 size=1 name=ssh_options_get ====

/* WARNING: Control flow encountered bad instruction data */

void ssh_options_get(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c8498 orig=FUN_011c8498 size=1 name=changeEvent ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QAbstractSlider::changeEvent(QEvent *param_1)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c84a0 orig=FUN_011c84a0 size=1 name=appendLatin1To ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QAbstractConcatenable::appendLatin1To(char *param_1,int param_2,QChar *param_3)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c84a8 orig=FUN_011c84a8 size=1 name=dropMimeData ====

/* WARNING: Control flow encountered bad instruction data */

void QListWidget::dropMimeData(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c84b0 orig=FUN_011c84b0 size=1 name=QCollator ====

/* WARNING: Control flow encountered bad instruction data */

void __thiscall QCollator::QCollator(QCollator *this)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c84b8 orig=FUN_011c84b8 size=1 name=columnCount ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QSortFilterProxyModel::columnCount(QModelIndex *param_1)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c84c0 orig=FUN_011c84c0 size=1 name=widget ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QLayoutItem::widget(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c84c8 orig=FUN_011c84c8 size=1 name=sftp_async_readdir_begin ====

/* WARNING: Control flow encountered bad instruction data */

void sftp_async_readdir_begin(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c84d0 orig=FUN_011c84d0 size=1 name=readAll ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QTextStream::readAll(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c84d8 orig=FUN_011c84d8 size=1 name=open ====

/* WARNING: Control flow encountered bad instruction data */

void QSaveFile::open(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c84e0 orig=FUN_011c84e0 size=1 name=count ====

/* WARNING: Control flow encountered bad instruction data */

void QStringRef::count(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c84f0 orig=FUN_011c84f0 size=1 name=operator<< ====

/* WARNING: Control flow encountered bad instruction data */

void __thiscall QDataStream::operator<<(QDataStream *this,bool param_1)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c84f8 orig=FUN_011c84f8 size=1 name=sort ====

/* WARNING: Control flow encountered bad instruction data */

void QFileSystemModel::sort(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c8500 orig=FUN_011c8500 size=1 name=isIndexHidden ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QTreeView::isIndexHidden(QModelIndex *param_1)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c8508 orig=FUN_011c8508 size=1 name=QJSValue ====

/* WARNING: Control flow encountered bad instruction data */

void __thiscall QJSValue::QJSValue(QJSValue *this,QJSValue *param_1)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c8510 orig=FUN_011c8510 size=1 name=insert ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QJsonObject::insert(QString *param_1,QJsonValue *param_2)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c8518 orig=FUN_011c8518 size=1 name=dropEvent ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QListWidget::dropEvent(QDropEvent *param_1)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c8520 orig=FUN_011c8520 size=1 name=ssh_silent_disconnect ====

/* WARNING: Control flow encountered bad instruction data */

void ssh_silent_disconnect(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c8528 orig=FUN_011c8528 size=1 name=isSymLink ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QFileInfo::isSymLink(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c8530 orig=FUN_011c8530 size=1 name=toJsonObject ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QVariant::toJsonObject(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c8538 orig=FUN_011c8538 size=1 name=__iswctype_l ====

/* WARNING: Control flow encountered bad instruction data */

void __iswctype_l(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c8540 orig=FUN_011c8540 size=1 name=warning ====

/* WARNING: Control flow encountered bad instruction data */

void QMessageBox::warning(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c8548 orig=FUN_011c8548 size=1 name=setIconSize ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void QAbstractButton::setIconSize(QSize *param_1)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ==== entry=011c8550 orig=FUN_011c8550 size=1 name=qHash ====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void qHash(QString *param_1,uint param_2)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


