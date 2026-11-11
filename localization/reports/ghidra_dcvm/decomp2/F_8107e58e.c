
int FUN_8107e58e(int *param_1)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = (int *)param_1[2];
  if ((piVar1 != (int *)0x0) && (*(char *)(piVar1 + 1) != '\0')) {
    (**(code **)(*piVar1 + 8))();
    piVar1 = (int *)param_1[2];
  }
  param_1[2] = 0;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 4))();
  }
  iVar2 = (**(code **)(*param_1 + 0x1c))(param_1);
  piVar1 = (int *)param_1[2];
  param_1[2] = iVar2;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 4))(piVar1);
    iVar2 = param_1[2];
  }
  return iVar2;
}

