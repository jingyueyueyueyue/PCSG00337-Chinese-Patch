
void FUN_81070896(int param_1)

{
  int *piVar1;
  
  piVar1 = *(int **)(param_1 + 8);
  *(undefined4 *)(param_1 + 8) = 0;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 4))();
  }
  *(undefined *)(param_1 + 0x12) = 0;
  *(undefined *)(param_1 + 0x10) = 0;
  *(undefined *)(param_1 + 0x11) = 0;
  return;
}

