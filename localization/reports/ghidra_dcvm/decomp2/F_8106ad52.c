
void FUN_8106ad52(int param_1)

{
  int *piVar1;
  
  func_0x8106e77e();
  piVar1 = *(int **)(param_1 + 0x50);
  while (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 0x24))(piVar1);
    if (piVar1 != (int *)0x0) {
      piVar1 = (int *)piVar1[2];
    }
  }
  piVar1 = *(int **)(param_1 + 0x48);
  while (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 0x24))(piVar1);
    if (piVar1 != (int *)0x0) {
      piVar1 = (int *)piVar1[2];
    }
  }
  return;
}

