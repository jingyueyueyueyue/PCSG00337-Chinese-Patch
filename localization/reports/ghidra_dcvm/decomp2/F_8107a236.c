
undefined4 * FUN_8107a236(undefined4 *param_1)

{
  if (param_1[0x1f] != 0) {
    *param_1 = &UNK_81145ba0;
    func_0x81005af0();
    param_1[0x1f] = 0;
    param_1[0x20] = 0;
    param_1[0x21] = 0;
  }
  *param_1 = &UNK_81145b70;
  func_0x81079788(param_1);
  return param_1;
}

