
undefined4 * FUN_810873b4(undefined4 *param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  
  func_0x81076976();
  *param_1 = &UNK_81146494;
  puVar1 = (undefined4 *)func_0x81005a98(8);
  puVar2 = (undefined4 *)0x0;
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = 0;
    puVar1[1] = 0;
    puVar2 = puVar1;
  }
  param_1[1] = puVar2;
  return param_1;
}

