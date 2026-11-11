
void FUN_81072908(int param_1,int *param_2,int *param_3)

{
  *param_2 = (*(int *)(param_1 + 0x24) - *(int *)(param_1 + 0x3c) / 2) + *(int *)(param_1 + 0x34);
  *param_3 = (*(int *)(param_1 + 0x28) - *(int *)(param_1 + 0x40) / 2) + *(int *)(param_1 + 0x38);
  return;
}

