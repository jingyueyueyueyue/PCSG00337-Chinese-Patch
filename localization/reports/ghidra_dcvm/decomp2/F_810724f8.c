
void FUN_810724f8(int param_1)

{
  int *piVar1;
  
  FUN_810724c0();
  FUN_81072488(param_1);
  FUN_81072450(param_1);
  piVar1 = *(int **)(param_1 + 4);
  *(undefined4 *)(param_1 + 4) = 0;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 4))();
  }
  *(undefined4 *)(param_1 + 8) = 0;
  return;
}

