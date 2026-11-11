
void FUN_810755f2(int *param_1)

{
  *(undefined *)(param_1 + 8) = 0;
  (**(code **)(*param_1 + 0x10))();
  *(undefined *)(param_1 + 4) = 0xff;
  param_1[5] = -1;
  param_1[6] = 0;
  param_1[7] = 0;
  (**(code **)(*param_1 + 0x14))(param_1);
  return;
}

