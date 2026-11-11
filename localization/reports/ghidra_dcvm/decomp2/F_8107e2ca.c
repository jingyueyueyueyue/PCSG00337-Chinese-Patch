
void FUN_8107e2ca(int param_1)

{
  if (*(int **)(param_1 + 0x1c) != (int *)0x0) {
    (**(code **)(**(int **)(param_1 + 0x1c) + 0xc))();
  }
  *(undefined4 *)(param_1 + 0x1c) = 0;
  return;
}

