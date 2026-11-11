
undefined4 FUN_8108afde(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  param_1 = param_1 + param_2 * 4;
  if (*(int *)(param_1 + 0x14) == 0) {
    uVar2 = 0;
    iVar1 = func_0x81005a98(0x390);
    if (iVar1 != 0) {
      uVar2 = FUN_8108af70();
    }
    *(undefined4 *)(param_1 + 0x14) = uVar2;
  }
  return 1;
}

