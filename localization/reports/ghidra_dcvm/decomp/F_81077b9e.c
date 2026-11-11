
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_81077b9e(int *param_1,undefined4 param_2,undefined4 param_3)

{
  int *piVar1;
  undefined4 uVar2;
  undefined4 extraout_r1;
  int iVar3;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined auStack_28 [8];
  undefined4 uStack_20;
  int iStack_1c;
  
  iStack_1c = _UNK_8111a5b0;
  piVar1 = (int *)(**(code **)(*param_1 + 0x20))();
  iVar3 = *piVar1;
  uStack_20 = 0;
  func_0x81080bb2(auStack_28,param_2);
  if (iVar3 != 0) {
    iVar3 = FUN_81078eaa(iVar3,&uStack_30,&uStack_2c,auStack_28,param_3);
    if (iVar3 != 0) {
      uVar2 = func_0x810783d6(uStack_30,uStack_2c);
      uVar2 = func_0x810789b2(uStack_30,uVar2);
      func_0x81005af0(uStack_20);
      goto LAB_81077c04;
    }
  }
  func_0x81005af0(uStack_20);
  uVar2 = 0;
LAB_81077c04:
  if (_UNK_8111a5b0 == iStack_1c) {
    return;
  }
  iVar3 = iStack_1c;
  func_0x811185a0(uVar2);
  func_0x810789b2(extraout_r1,iVar3);
  return;
}

