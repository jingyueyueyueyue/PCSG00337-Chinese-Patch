
undefined4 FUN_8107f61c(int param_1,int *param_2)

{
  undefined4 uVar1;
  int iVar2;
  int *piVar3;
  
  piVar3 = *(int **)(param_1 + 0xc);
  (**(code **)(*piVar3 + 8))(piVar3);
  if (*param_2 == 0) {
    (**(code **)(*piVar3 + 0xc))(piVar3);
    uVar1 = 0;
  }
  else {
    uVar1 = 0;
    if ((uint)*(ushort *)((int)param_2 + 2) < *(uint *)(param_1 + 0x14)) {
      iVar2 = (uint)*(ushort *)((int)param_2 + 2) * 0x34 + *(int *)(param_1 + 0x10);
      if ((*(short *)(iVar2 + 0x1e) == *(short *)param_2) && (iVar2 != 0)) {
        uVar1 = 1;
      }
    }
    (**(code **)(*piVar3 + 0xc))(piVar3);
  }
  return uVar1;
}

