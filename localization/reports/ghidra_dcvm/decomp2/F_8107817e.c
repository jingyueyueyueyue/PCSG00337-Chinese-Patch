
undefined4 * FUN_8107817e(undefined4 *param_1,undefined4 param_2)

{
  int iVar1;
  
  *param_1 = &UNK_81145a28;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[6] = 0;
  param_1[7] = 0;
  iVar1 = func_0x81005a98(0x20);
  if (iVar1 != 0) {
    *(int *)iVar1 = iVar1;
  }
  if (iVar1 != -4) {
    *(int *)(iVar1 + 4) = iVar1;
  }
  if (iVar1 != -8) {
    *(int *)(iVar1 + 8) = iVar1;
  }
  *(undefined *)(iVar1 + 0x1d) = 1;
  *(undefined *)(iVar1 + 0x1c) = 1;
  param_1[6] = iVar1;
  param_1[10] = param_2;
  param_1[0xb] = 0;
  param_1[0x10] = 0;
  param_1[0x11] = &UNK_8113726c;
  param_1[8] = 0;
  param_1[0xd] = 0;
  param_1[0xe] = 0;
  param_1[0xf] = 0;
  param_1[0xc] = 0;
  return param_1;
}

