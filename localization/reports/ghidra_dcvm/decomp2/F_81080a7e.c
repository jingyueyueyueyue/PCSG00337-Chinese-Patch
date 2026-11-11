
void FUN_81080a7e(undefined4 param_1,int *param_2,int **param_3)

{
  int iVar1;
  int *piVar2;
  
  piVar2 = *param_3;
  while (piVar2 != (int *)0x0) {
    iVar1 = (**(code **)(*piVar2 + 8))();
    if (*param_2 == *(int *)(iVar1 + 4)) {
      *(undefined4 *)(iVar1 + 4) = 0;
    }
    if (piVar2 != (int *)0x0) {
      piVar2 = (int *)piVar2[1];
    }
  }
  return;
}

