
undefined4 * FUN_810846e0(undefined4 *param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  
  *param_1 = &UNK_81146358;
  puVar1 = (undefined4 *)func_0x81005a98(0x10);
  puVar2 = (undefined4 *)0x0;
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = 0;
    puVar1[1] = 0;
    puVar1[2] = 0;
    puVar1[3] = 0;
    puVar2 = puVar1;
  }
  param_1[1] = puVar2;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[0x11] = 0;
  param_1[0x12] = 0;
  param_1[0x13] = 0;
  func_0x810761f2(param_1);
  return param_1;
}

