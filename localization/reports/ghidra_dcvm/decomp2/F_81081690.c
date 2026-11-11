
undefined4 * FUN_81081690(undefined4 *param_1)

{
  undefined4 uVar1;
  
  *param_1 = &UNK_81146280;
  param_1[1] = 0;
  func_0x8107dfb8(param_1 + 2);
  param_1[6] = 0;
  param_1[8] = 0;
  param_1[7] = 0xf;
  func_0x8108c77a(param_1 + 9,1,1);
  func_0x8108cb5c(param_1 + 0xb,0);
  FUN_8108cd88(param_1 + 0xc);
  param_1[0xf] = 0;
  param_1[0xe] = &UNK_811462a4;
  uVar1 = uRam8114a5d4;
  param_1[0x10] = uRam8114a5d0;
  param_1[0x11] = uVar1;
  *(undefined *)(param_1 + 0x12) = 0;
  *(undefined *)((int)param_1 + 0x49) = 0;
  *(undefined *)((int)param_1 + 0x4a) = 1;
  return param_1;
}

