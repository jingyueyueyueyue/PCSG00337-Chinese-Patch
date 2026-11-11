
void FUN_81080a56(int param_1,undefined4 *param_2,int *param_3)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = (**(code **)(*param_3 + 8))(param_3);
  *(undefined4 *)(iVar1 + 4) = *param_2;
  piVar2 = (int *)0x0;
  if (param_3 != (int *)0x0) {
    piVar2 = param_3 + 1;
  }
  *piVar2 = *(int *)(param_1 + 8);
  *(int **)(param_1 + 8) = param_3;
  return;
}

