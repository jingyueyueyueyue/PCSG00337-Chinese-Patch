
undefined4 * FUN_8106e484(undefined4 *param_1)

{
  *param_1 = &UNK_811454ac;
  if ((int *)param_1[9] != (int *)0x0) {
    (**(code **)(*(int *)param_1[9] + 4))();
  }
  param_1[9] = 0;
  if ((int *)param_1[8] != (int *)0x0) {
    (**(code **)(*(int *)param_1[8] + 4))();
  }
  param_1[8] = 0;
  param_1[3] = &UNK_8114555c;
  func_0x81080930(param_1 + 3);
  return param_1;
}

