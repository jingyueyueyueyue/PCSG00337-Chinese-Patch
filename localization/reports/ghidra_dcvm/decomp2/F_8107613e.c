
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_8107613e(undefined4 *param_1,undefined4 param_2,char *param_3,undefined4 param_4,
                undefined4 param_5)

{
  int iVar1;
  undefined auStack_50 [4];
  undefined4 uStack_4c;
  undefined4 uStack_48;
  int iStack_44;
  undefined4 uStack_40;
  int iStack_3c;
  int iStack_18;
  
  iStack_18 = _UNK_8111a5b0;
  uStack_4c = 0;
  uStack_48 = 0;
  iStack_44 = 0;
  uStack_40 = 0;
  FUN_81075e4a(&uStack_4c,param_2,param_4,param_5);
  do {
    param_3 = (char *)func_0x81075f2e(&uStack_4c,0,auStack_50,param_3,0xffffffff,0x14);
  } while (*param_3 != '\0');
  *param_1 = uStack_40;
  param_1[1] = iStack_44 + iStack_3c;
  if (_UNK_8111a5b0 == iStack_18) {
    return _UNK_8111a5b0;
  }
  iVar1 = func_0x811185a0();
  return *(int *)(iVar1 + 0xc);
}

