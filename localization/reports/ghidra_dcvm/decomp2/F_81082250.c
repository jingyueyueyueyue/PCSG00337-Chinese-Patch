
undefined4 * FUN_81082250(undefined4 *param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  
  puVar1 = (undefined4 *)func_0x81005a98(8);
  puVar2 = (undefined4 *)0x0;
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = 0;
    puVar1[1] = 0;
    puVar2 = puVar1;
  }
  *param_1 = puVar2;
  if (puVar2 == (undefined4 *)0x0) {
    do {
      func_0x81118870(1000);
    } while( true );
  }
  func_0x810752be(param_1);
  return param_1;
}

