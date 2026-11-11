
undefined4 * FUN_8106d14a(undefined4 *param_1)

{
  *(undefined *)(param_1 + 0xd) = 1;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  *param_1 = &UNK_81145128;
  func_0x8108d650(param_1 + 5,0,0x20);
  *(undefined *)(param_1 + 0xd) = 0;
  return param_1;
}

