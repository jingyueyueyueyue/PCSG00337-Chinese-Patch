
undefined4 * FUN_810839a4(undefined4 *param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  
  *param_1 = &UNK_81146320;
  puVar1 = (undefined4 *)func_0x81005a98(0x48);
  puVar2 = (undefined4 *)0x0;
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = 0;
    puVar1[5] = 0;
    *(undefined *)(puVar1 + 0xb) = 1;
    puVar1[6] = 0;
    puVar1[7] = 1;
    puVar1[8] = 1;
    puVar1[9] = 2;
    puVar1[10] = 2;
    puVar2 = puVar1;
  }
  param_1[1] = puVar2;
  param_1[2] = 0;
  param_1[3] = 0;
  if (puVar2 == (undefined4 *)0x0) {
    do {
      func_0x81118870(1000);
    } while( true );
  }
  return param_1;
}

