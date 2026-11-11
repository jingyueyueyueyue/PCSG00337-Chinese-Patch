
void FUN_81071150(int param_1,undefined4 param_2)

{
  if ((*(byte *)(param_1 + 2) & 0x60) == 0x60) {
    *(byte *)(param_1 + 2) = *(byte *)(param_1 + 2) & 0x9f | 0x40;
    (**(code **)(**(int **)(param_1 + 4) + 0xc))(*(int **)(param_1 + 4),param_2);
    (**(code **)(**(int **)(param_1 + 4) + 0x18))(*(int **)(param_1 + 4),param_2);
  }
  else {
    (**(code **)(**(int **)(param_1 + 4) + 0xc))(*(int **)(param_1 + 4),param_2);
  }
  return;
}

