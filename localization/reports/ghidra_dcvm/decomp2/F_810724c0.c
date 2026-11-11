
void FUN_810724c0(int param_1)

{
  int iVar1;
  int *piVar2;
  
  piVar2 = *(int **)(param_1 + 0xc);
  while (piVar2 != (int *)0x0) {
    iVar1 = piVar2[4];
    if (piVar2[3] == 0) {
      *(int *)(param_1 + 0xc) = iVar1;
    }
    else {
      *(int *)(piVar2[3] + 0x10) = iVar1;
      iVar1 = piVar2[4];
    }
    if (iVar1 == 0) {
      *(int *)(param_1 + 0x10) = piVar2[3];
    }
    else {
      *(int *)(iVar1 + 0xc) = piVar2[3];
    }
    piVar2[3] = 0;
    piVar2[4] = 0;
    (**(code **)(*piVar2 + 4))(piVar2);
    piVar2 = *(int **)(param_1 + 0xc);
  }
  return;
}

