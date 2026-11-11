
undefined4 * FUN_81086cec(undefined4 *param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  
  func_0x81076976();
  *param_1 = &UNK_8114646c;
  puVar1 = (undefined4 *)func_0x81005a98(0x14);
  puVar2 = (undefined4 *)0x0;
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = 0;
    puVar1[1] = 0;
    if (puRam811ae7bc == (undefined4 *)0x0) {
      *puVar1 = 0;
      puVar1[1] = 0;
      puRam811ae7b8 = puVar1;
    }
    else {
      puVar1[1] = 0;
      *puVar1 = puRam811ae7bc;
      puRam811ae7bc[1] = puVar1;
    }
    puRam811ae7bc = puVar1;
    puVar1[2] = 0;
    puVar1[3] = 0;
    puVar1[4] = 0;
    puVar2 = puVar1;
  }
  param_1[1] = puVar2;
  return param_1;
}

