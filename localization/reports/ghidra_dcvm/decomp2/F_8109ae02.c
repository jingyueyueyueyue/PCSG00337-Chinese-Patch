
undefined4 * FUN_8109ae02(undefined4 *param_1)

{
  undefined4 *puVar1;
  
  *param_1 = &UNK_81147248;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[5] = 0;
  param_1[0x1a] = 0xf;
  puVar1 = param_1 + 0x15;
  param_1[0x1b] = 0;
  param_1[0x1c] = 0;
  param_1[0x1d] = 0xffffffff;
  if ((&UNK_81138840 < puVar1) || (puVar1 < &UNK_81138841)) {
    param_1[0x19] = 0;
    *(undefined *)(param_1 + 0x15) = 0;
  }
  else {
    *(undefined *)(param_1 + 0x15) = 0;
    param_1[0x19] = 0;
    func_0x810c8628(param_1 + 0x14,param_1 + 0x14,(int)&UNK_81138840 - (int)puVar1,0);
  }
  param_1[6] = 0;
  param_1[9] = 0xffffffff;
  param_1[10] = 0;
  param_1[0xb] = 0;
  param_1[0xc] = 0;
  param_1[0xd] = 0;
  param_1[0xe] = 0;
  param_1[0xf] = 0;
  param_1[0x10] = 0;
  param_1[0x11] = 0;
  param_1[0x12] = 0;
  param_1[0x13] = 0;
  param_1[8] = 0xffffffff;
  return param_1;
}

