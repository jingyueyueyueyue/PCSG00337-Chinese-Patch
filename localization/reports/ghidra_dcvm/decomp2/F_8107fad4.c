
ushort FUN_8107fad4(int param_1,int *param_2)

{
  ushort uVar1;
  int iVar2;
  int *piVar3;
  
  piVar3 = *(int **)(param_1 + 0xc);
  (**(code **)(*piVar3 + 8))(piVar3);
  if ((((*param_2 != 0) && ((uint)*(ushort *)((int)param_2 + 2) < *(uint *)(param_1 + 0x14))) &&
      (iVar2 = (uint)*(ushort *)((int)param_2 + 2) * 0x34 + *(int *)(param_1 + 0x10),
      *(short *)(iVar2 + 0x1e) == *(short *)param_2)) && (iVar2 != 0)) {
    uVar1 = *(ushort *)(iVar2 + 0x18);
    (**(code **)(*piVar3 + 0xc))(piVar3);
    return uVar1 & 1;
  }
  (**(code **)(*piVar3 + 0xc))(piVar3);
  return 0;
}

