// entry=0076bf82 size=113  (decompiled by Ghidra package ghidra, Utility, version 12.1.4)

/* WARNING: Removing unreachable block (ram,0x0076bfe8) */

undefined8 FUN_0076bf82(undefined8 param_1,undefined8 param_2)

{
  int *piVar1;
  int iVar2;
  long local_20;
  
  FUN_0076707e(&local_20);
                    /* try { // try from 0076bfa6 to 0076bfaa has its CatchHandler @ 0076bff3 */
  FUN_0076bed4(param_1,param_2,&local_20);
  if ((undefined8 *)(local_20 + -0x18) != &std::wstring::_Rep::_S_empty_rep_storage) {
    LOCK();
    piVar1 = (int *)(local_20 + -8);
    iVar2 = *piVar1;
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if (iVar2 < 1) {
      operator_delete((undefined8 *)(local_20 + -0x18));
    }
  }
  return param_1;
}


