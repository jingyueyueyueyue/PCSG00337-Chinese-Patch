
void FUN_8107f6b6(int param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  
  piVar2 = *(int **)(param_1 + 0xc);
  (**(code **)(*piVar2 + 8))(piVar2);
  iVar1 = *piVar2;
  *(undefined *)(*(int *)(param_1 + 0x1c) + param_2 * 0x24 + 0x22) = 1;
  (**(code **)(iVar1 + 0xc))(piVar2);
  return;
}

