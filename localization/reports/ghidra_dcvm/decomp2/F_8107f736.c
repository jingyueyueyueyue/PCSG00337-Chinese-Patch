
void FUN_8107f736(int param_1)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  
  piVar3 = *(int **)(param_1 + 0xc);
  (**(code **)(*piVar3 + 8))(piVar3);
  iVar1 = *(int *)(param_1 + 0x20);
  if (iVar1 != 0) {
    iVar2 = *(int *)(param_1 + 0x1c);
    do {
      iVar1 = iVar1 + -1;
      *(undefined *)(iVar2 + 0x22) = 0;
      iVar2 = iVar2 + 0x24;
    } while (iVar1 != 0);
  }
  (**(code **)(*piVar3 + 0xc))(piVar3);
  return;
}

