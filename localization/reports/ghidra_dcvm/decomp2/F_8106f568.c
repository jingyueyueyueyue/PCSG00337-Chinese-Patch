
void FUN_8106f568(int param_1)

{
  int *piVar1;
  
  piVar1 = *(int **)(param_1 + 8);
  while (piVar1 != (int *)0x0) {
    *(int *)(param_1 + 8) = piVar1[1];
    piVar1[1] = 0;
    (**(code **)(*piVar1 + 4))(piVar1);
    piVar1 = *(int **)(param_1 + 8);
  }
  return;
}

