
undefined4 * FUN_81082e1c(undefined4 *param_1)

{
  *param_1 = &UNK_811462c8;
  func_0x8109d890(param_1);
  if ((int *)param_1[2] != (int *)0x0) {
    (**(code **)(*(int *)param_1[2] + 4))();
  }
  param_1[2] = 0;
  if (param_1[1] != 0) {
    func_0x810824f8();
    func_0x81005af0();
  }
  *param_1 = &UNK_811462b8;
  param_1[1] = 0;
  uRam811ae690 = 0;
  return param_1;
}

