
void FUN_8106f548(int param_1)

{
  int *piVar1;
  
  piVar1 = *(int **)(param_1 + 0xc);
  while (piVar1 != (int *)0x0) {
    *(int *)(param_1 + 0xc) = piVar1[1];
    piVar1[1] = 0;
    (**(code **)(*piVar1 + 4))(piVar1);
    piVar1 = *(int **)(param_1 + 0xc);
  }
  return;
}

