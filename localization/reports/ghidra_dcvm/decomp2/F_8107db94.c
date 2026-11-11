
void FUN_8107db94(int **param_1)

{
  if ((*param_1 != (int *)0x0) && (param_1[1] != (int *)0x0)) {
    (**(code **)(**param_1 + 0x10))();
  }
  *param_1 = (int *)0x0;
  param_1[1] = (int *)0x0;
  return;
}

