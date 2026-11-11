
void FUN_8108b882(int param_1,int param_2)

{
  int *piVar1;
  
  if (-1 < param_2) {
    param_1 = param_1 + param_2 * 4;
    piVar1 = *(int **)(param_1 + 0x14);
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 4))();
      *(undefined4 *)(param_1 + 0x14) = 0;
    }
  }
  return;
}

