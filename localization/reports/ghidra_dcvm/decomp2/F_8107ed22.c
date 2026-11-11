
void FUN_8107ed22(int param_1,int *param_2)

{
  param_2[3] = 0;
  if (*param_2 != 0) {
    (**(code **)(**(int **)(param_1 + 0xc4) + 0x10))();
    *param_2 = 0;
  }
  return;
}

