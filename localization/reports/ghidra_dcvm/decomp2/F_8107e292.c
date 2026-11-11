
void FUN_8107e292(int param_1)

{
  if (*(int **)(param_1 + 0x10) != (int *)0x0) {
    (**(code **)(**(int **)(param_1 + 0x10) + 0x10))();
  }
  return;
}

