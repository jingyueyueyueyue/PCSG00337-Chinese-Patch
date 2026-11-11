
bool FUN_8107f55c(int param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  
  piVar2 = *(int **)(param_1 + 0xc);
  (**(code **)(*piVar2 + 8))(piVar2);
  iVar1 = *(int *)(*(int *)(param_1 + 0x1c) + param_2 * 0x24);
  (**(code **)(*piVar2 + 0xc))(piVar2);
  return iVar1 != 0;
}

