
undefined4 FUN_81092484(int *param_1)

{
  *(undefined *)(param_1 + 10) = 0;
  (**(code **)(*param_1 + 8))();
  *(undefined *)(param_1 + 10) = 1;
  return 0;
}

