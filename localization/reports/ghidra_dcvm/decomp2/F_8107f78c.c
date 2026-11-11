
void FUN_8107f78c(int param_1,int *param_2)

{
  int iVar1;
  int *piVar2;
  
  piVar2 = *(int **)(param_1 + 0xc);
  (**(code **)(*piVar2 + 8))(piVar2);
  if ((((*param_2 != 0) && ((uint)*(ushort *)((int)param_2 + 2) < *(uint *)(param_1 + 0x14))) &&
      (iVar1 = (uint)*(ushort *)((int)param_2 + 2) * 0x34 + *(int *)(param_1 + 0x10),
      *(short *)(iVar1 + 0x1e) == *(short *)param_2)) && (iVar1 != 0)) {
    *(ushort *)(iVar1 + 0x18) = *(ushort *)(iVar1 + 0x18) | 2;
  }
  (**(code **)(*piVar2 + 0xc))(piVar2);
  return;
}

