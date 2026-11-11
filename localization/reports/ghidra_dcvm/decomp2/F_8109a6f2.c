
undefined4 * FUN_8109a6f2(undefined4 *param_1)

{
  int iVar1;
  
  *param_1 = &UNK_8114719c;
  param_1[2] = 0;
  param_1[3] = 0;
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
  param_1[2] = iVar1;
  return param_1;
}

