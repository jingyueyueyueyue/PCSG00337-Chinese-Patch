
undefined4 FUN_8106bbc4(int param_1,int *param_2)

{
  short sVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  
  iVar5 = param_2[1];
  uVar6 = *(uint *)(param_1 + 0xdc);
  uVar4 = uVar6 & 0x10;
  *(undefined *)(param_2 + 5) = 0;
  iVar3 = *(int *)(iVar5 + 8);
  if (uVar4 == 0) {
    *(short *)((int)param_2 + 10) = *(short *)((int)param_2 + 10) + *(short *)(iVar5 + 0xe);
  }
  else {
    *(short *)(param_2 + 2) = *(short *)(param_2 + 2) + *(short *)(iVar5 + 0xc);
  }
  param_2[1] = iVar3;
  if ((iVar3 == 0) && ((uVar6 & 1) == 0)) {
    iVar3 = *(int *)(param_1 + 0x60);
    iVar5 = 0;
    param_2[1] = iVar3;
  }
  else {
    iVar5 = *param_2 + 1;
  }
  *param_2 = iVar5;
  if (uVar4 == 0) {
    sVar1 = *(short *)(param_1 + 0x96);
    if ((iVar3 != 0) &&
       ((int)sVar1 < (int)((uint)*(ushort *)(iVar3 + 0xe) + (int)*(short *)((int)param_2 + 10)))) {
      *(undefined *)(param_2 + 5) = 1;
    }
    uVar2 = 0;
    if (((int)*(short *)((int)param_2 + 10) < (int)sVar1) && (uVar2 = 0, iVar3 != 0)) {
      uVar2 = 1;
    }
  }
  else {
    sVar1 = *(short *)(param_1 + 0x94);
    if ((iVar3 != 0) &&
       ((int)sVar1 < (int)((uint)*(ushort *)(iVar3 + 0xc) + (int)*(short *)(param_2 + 2)))) {
      *(undefined *)(param_2 + 5) = 1;
    }
    uVar2 = 0;
    if (((int)*(short *)(param_2 + 2) < (int)sVar1) && (uVar2 = 0, iVar3 != 0)) {
      uVar2 = 1;
    }
  }
  return uVar2;
}

