
int FUN_8107e554(int *param_1)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = (int *)param_1[1];
  if ((piVar1 != (int *)0x0) && (*(char *)(piVar1 + 6) != '\0')) {
    (**(code **)(*piVar1 + 0xc))();
    piVar1 = (int *)param_1[1];
  }
  param_1[1] = 0;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 4))();
  }
  iVar2 = (**(code **)(*param_1 + 0x18))(param_1);
  piVar1 = (int *)param_1[1];
  param_1[1] = iVar2;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 4))(piVar1);
    iVar2 = param_1[1];
  }
  return iVar2;
}

