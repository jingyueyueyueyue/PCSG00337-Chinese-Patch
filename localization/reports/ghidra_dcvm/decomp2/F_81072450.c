
void FUN_81072450(int param_1)

{
  int iVar1;
  int *piVar2;
  
  piVar2 = *(int **)(param_1 + 0x14);
  while (piVar2 != (int *)0x0) {
    iVar1 = piVar2[2];
    if (piVar2[1] == 0) {
      *(int *)(param_1 + 0x14) = iVar1;
    }
    else {
      *(int *)(piVar2[1] + 8) = iVar1;
      iVar1 = piVar2[2];
    }
    if (iVar1 == 0) {
      *(int *)(param_1 + 0x18) = piVar2[1];
    }
    else {
      *(int *)(iVar1 + 4) = piVar2[1];
    }
    piVar2[1] = 0;
    piVar2[2] = 0;
    (**(code **)(*piVar2 + 4))(piVar2);
    piVar2 = *(int **)(param_1 + 0x14);
  }
  return;
}

