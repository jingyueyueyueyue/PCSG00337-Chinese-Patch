
void FUN_8106df46(undefined2 *param_1,undefined2 *param_2,short param_3)

{
  if (param_3 == 0) {
    param_3 = 1;
  }
  param_1[7] = param_3;
  param_1[6] = 0;
  param_1[2] = *param_1;
  param_1[3] = param_1[1];
  param_1[4] = *param_2;
  param_1[5] = param_2[1];
  return;
}

