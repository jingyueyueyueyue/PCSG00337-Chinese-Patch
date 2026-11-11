
void FUN_8107c66a(int param_1)

{
  if (*(int **)(param_1 + 0xc) != (int *)0x0) {
    (**(code **)(**(int **)(param_1 + 0xc) + 0x20))();
  }
  return;
}

