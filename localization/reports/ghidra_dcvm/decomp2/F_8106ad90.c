
void FUN_8106ad90(int param_1)

{
  int *piVar1;
  int *piVar2;
  
  if (((*(byte *)(param_1 + 0x42) & 2) != 0) && ((*(byte *)(param_1 + 0x42) & 1) == 0)) {
    FUN_8106ee6e(param_1);
    piVar2 = *(int **)(param_1 + 0x48);
    piVar1 = piVar2;
    while (piVar2 != (int *)0x0) {
      if (((*(byte *)((int)piVar2 + 0x42) & 2) != 0) && ((*(byte *)((int)piVar2 + 0x42) & 1) == 0))
      {
        (**(code **)(*piVar2 + 0x80))(piVar2);
        piVar2 = piVar1;
      }
      if (piVar2 != (int *)0x0) {
        piVar2 = (int *)piVar2[2];
        piVar1 = piVar2;
      }
    }
  }
  return;
}

