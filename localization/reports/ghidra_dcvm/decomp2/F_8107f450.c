
int FUN_8107f450(int param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  
  piVar3 = *(int **)(param_1 + 0xc);
  (**(code **)(*piVar3 + 8))(piVar3);
  iVar2 = 0;
  for (piVar1 = *(int **)(*(int *)(param_1 + 0x1c) + param_2 * 0x24); piVar1 != (int *)0x0;
      piVar1 = (int *)*piVar1) {
    iVar2 = iVar2 + 1;
  }
  (**(code **)(*piVar3 + 0xc))(piVar3);
  return iVar2;
}

