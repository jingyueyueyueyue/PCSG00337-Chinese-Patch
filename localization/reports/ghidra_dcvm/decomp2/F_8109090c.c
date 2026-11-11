
undefined4 * FUN_8109090c(undefined4 *param_1)

{
  int iVar1;
  int *piVar2;
  
  func_0x8107eec8();
  *param_1 = &UNK_81146c08;
  piVar2 = (int *)0x0;
  iVar1 = func_0x81005a98(4);
  if (iVar1 != 0) {
    piVar2 = (int *)func_0x810906e4();
  }
  param_1[0xb] = piVar2;
  param_1[0xc] = 0;
  param_1[4] = *(undefined4 *)(*piVar2 + 8);
  param_1[5] = *(undefined4 *)(*piVar2 + 0x20);
  param_1[7] = *(undefined4 *)*piVar2;
  param_1[8] = uRam8114a794;
  param_1[10] = &UNK_81137f98;
  func_0x8107e85e(param_1);
  return param_1;
}

