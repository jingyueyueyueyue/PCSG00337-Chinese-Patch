
void FUN_810711a4(int param_1)

{
  (**(code **)(**(int **)(param_1 + 4) + 0x14))();
  (**(code **)(**(int **)(param_1 + 4) + 8))();
  *(undefined4 *)(param_1 + 4) = 0;
  *(byte *)(param_1 + 2) = *(byte *)(param_1 + 2) & 0x9f;
  return;
}

