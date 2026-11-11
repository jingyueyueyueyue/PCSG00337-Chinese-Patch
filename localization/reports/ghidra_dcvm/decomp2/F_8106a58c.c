
void FUN_8106a58c(int param_1,undefined param_2)

{
  int *piVar1;
  int *piVar2;
  
  piVar2 = *(int **)(param_1 + 0x50);
  piVar1 = piVar2;
  while (piVar2 != (int *)0x0) {
    if ((*(byte *)((int)piVar2 + 0x42) & 1) == 0) {
      (**(code **)(*piVar2 + 0x18))(piVar2,param_2);
      piVar2 = piVar1;
    }
    if (piVar2 != (int *)0x0) {
      piVar2 = (int *)piVar2[2];
      piVar1 = piVar2;
    }
  }
  piVar2 = *(int **)(param_1 + 0x48);
  piVar1 = piVar2;
  while (piVar2 != (int *)0x0) {
    if ((*(byte *)((int)piVar2 + 0x42) & 1) == 0) {
      (**(code **)(*piVar2 + 0x18))(piVar2,param_2);
      piVar2 = piVar1;
    }
    if (piVar2 != (int *)0x0) {
      piVar2 = (int *)piVar2[2];
      piVar1 = piVar2;
    }
  }
  return;
}

