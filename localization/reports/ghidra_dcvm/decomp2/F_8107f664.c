
bool FUN_8107f664(int param_1,int *param_2)

{
  int *piVar1;
  int iVar2;
  bool bVar3;
  
  piVar1 = *(int **)(param_1 + 0xc);
  (**(code **)(*piVar1 + 8))(piVar1);
  if ((((*param_2 == 0) || (*(uint *)(param_1 + 0x14) <= (uint)*(ushort *)((int)param_2 + 2))) ||
      (iVar2 = (uint)*(ushort *)((int)param_2 + 2) * 0x34 + *(int *)(param_1 + 0x10),
      *(short *)(iVar2 + 0x1e) != *(short *)param_2)) || (iVar2 == 0)) {
    (**(code **)(*piVar1 + 0xc))(piVar1);
    bVar3 = false;
  }
  else {
    bVar3 = (*(ushort *)(iVar2 + 0x18) & 0x20) != 0;
    (**(code **)(*piVar1 + 0xc))(piVar1);
  }
  return bVar3;
}

