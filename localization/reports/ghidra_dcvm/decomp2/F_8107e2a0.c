
void FUN_8107e2a0(int param_1,undefined4 param_2,int *param_3)

{
  int *piVar1;
  
  piVar1 = *(int **)(param_1 + 0x10);
  *(int **)(param_1 + 0x1c) = param_3;
  *(undefined4 *)(param_1 + 0x20) = param_2;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
    (**(code **)(**(int **)(param_1 + 0x10) + 0xc))();
    param_3 = *(int **)(param_1 + 0x1c);
  }
  (**(code **)(*param_3 + 8))();
  return;
}

