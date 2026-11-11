
void FUN_8106b1e6(undefined4 *param_1)

{
  *param_1 = &UNK_81144d84;
  if ((int *)param_1[3] != (int *)0x0) {
    (**(code **)(*(int *)param_1[3] + 4))();
  }
  param_1[3] = 0;
  func_0x81005af0(param_1);
  return;
}

