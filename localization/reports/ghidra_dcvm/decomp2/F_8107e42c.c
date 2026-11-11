
void FUN_8107e42c(int *param_1,int param_2)

{
  *(undefined *)(param_1 + 4) = 1;
  param_1[2] = 0;
  *(undefined *)(param_1 + 1) = 1;
  param_1[3] = param_2;
  (**(code **)(*param_1 + 0x20))();
  return;
}

