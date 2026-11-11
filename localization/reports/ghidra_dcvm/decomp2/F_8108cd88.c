
undefined4 * FUN_8108cd88(undefined4 *param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  
  puVar1 = (undefined4 *)func_0x81005a98(8);
  puVar2 = (undefined4 *)0x0;
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = 0xffffffff;
    puVar1[1] = 0xffffffff;
    puVar2 = puVar1;
  }
  *param_1 = puVar2;
  func_0x8109db5c(param_1);
  return param_1;
}

