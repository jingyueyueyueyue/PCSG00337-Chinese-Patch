
undefined4 FUN_8107f5b2(int param_1,int *param_2)

{
  ushort uVar1;
  code *pcVar2;
  int *piVar3;
  int iVar4;
  undefined4 uVar5;
  
  piVar3 = *(int **)(param_1 + 0xc);
  (**(code **)(*piVar3 + 8))(piVar3);
  pcVar2 = *(code **)(*piVar3 + 0xc);
  if (*param_2 == 0) {
    (*pcVar2)(piVar3);
  }
  else {
    if ((((uint)*(ushort *)((int)param_2 + 2) < *(uint *)(param_1 + 0x14)) &&
        (iVar4 = (uint)*(ushort *)((int)param_2 + 2) * 0x34 + *(int *)(param_1 + 0x10),
        *(short *)(iVar4 + 0x1e) == *(short *)param_2)) && (iVar4 != 0)) {
      uVar1 = *(ushort *)(iVar4 + 0x18);
      uVar5 = 0;
      if ((((uVar1 & 0x10) != 0) || ((uVar1 & 0x20) != 0)) || ((uVar1 & 2) != 0)) {
        uVar5 = 1;
      }
      (*pcVar2)(piVar3);
      return uVar5;
    }
    (*pcVar2)(piVar3);
  }
  return 0;
}

