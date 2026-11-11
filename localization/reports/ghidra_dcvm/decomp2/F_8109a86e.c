
undefined4 * FUN_8109a86e(undefined4 *param_1,undefined4 param_2)

{
  int iVar1;
  
  FUN_8109a6f2();
  param_1[4] = param_2;
  *param_1 = &UNK_811471b0;
  param_1[6] = 0;
  param_1[7] = 0;
  iVar1 = func_0x81005a98(0x14);
  if (iVar1 != 0) {
    *(int *)iVar1 = iVar1;
  }
  if (iVar1 != -4) {
    *(int *)(iVar1 + 4) = iVar1;
  }
  if (iVar1 != -8) {
    *(int *)(iVar1 + 8) = iVar1;
  }
  *(undefined *)(iVar1 + 0x11) = 1;
  *(undefined *)(iVar1 + 0x10) = 1;
  param_1[6] = iVar1;
  return param_1;
}

