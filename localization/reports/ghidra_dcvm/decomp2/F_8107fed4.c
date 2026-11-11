
int FUN_8107fed4(int param_1)

{
  if (*(int **)(param_1 + 4) != (int *)0x0) {
    (**(code **)(**(int **)(param_1 + 4) + 4))();
  }
  *(undefined4 *)(param_1 + 4) = 0;
  return param_1;
}

