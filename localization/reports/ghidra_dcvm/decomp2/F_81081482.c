
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_81081482(undefined4 param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  uint **ppuVar3;
  int iStack_20;
  int iStack_1c;
  
  iStack_1c = _UNK_8111a5b0;
  iVar1 = FUN_810812b0(param_2,param_4);
  if (iVar1 == 0) {
    *(undefined4 *)(param_2 + 8) = 1;
    uVar2 = 0;
  }
  else {
    iStack_20 = iVar1;
    uVar2 = FUN_8108140e(param_1,param_2,param_3,&iStack_20);
  }
  if (_UNK_8111a5b0 == iStack_1c) {
    return uVar2;
  }
  ppuVar3 = (uint **)func_0x811185a0(uVar2);
  if (*ppuVar3 == (uint *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = 0;
    if ((**ppuVar3 & 0xf) == 2) {
      uVar2 = 1;
    }
  }
  return uVar2;
}

