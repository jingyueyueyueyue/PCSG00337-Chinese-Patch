
void FUN_8107513a(int param_1,uint param_2,int param_3)

{
  undefined uVar1;
  undefined uVar2;
  undefined uVar3;
  byte bVar4;
  undefined uVar5;
  int iVar6;
  byte *pbVar7;
  int iVar8;
  uint uVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  
  iVar8 = *(int *)(param_1 + 4);
  iVar12 = *(int *)(param_1 + 8);
  if ((param_3 == 0) && (param_3 = 0x10, (*(byte *)(param_1 + 0xc) & 1) != 0)) {
    param_3 = 0x100;
  }
  uVar9 = (param_2 + param_3) - 1;
  iVar6 = (uint)*(byte *)(iVar8 + uVar9) * 4;
  uVar5 = *(undefined *)(iVar12 + iVar6);
  iVar6 = iVar6 + iVar12;
  uVar1 = *(undefined *)(iVar6 + 1);
  uVar2 = *(undefined *)(iVar6 + 2);
  uVar3 = *(undefined *)(iVar6 + 3);
  if (param_2 < uVar9) {
    iVar6 = uVar9 - param_2;
    pbVar7 = (byte *)(uVar9 + iVar8);
    do {
      iVar11 = iVar12 + (uint)pbVar7[-1] * 4;
      bVar4 = *pbVar7;
      *(undefined *)((uint)bVar4 * 4 + iVar12) = *(undefined *)(iVar12 + (uint)pbVar7[-1] * 4);
      iVar10 = iVar12 + (uint)bVar4 * 4;
      iVar6 = iVar6 + -1;
      *(undefined *)(iVar10 + 1) = *(undefined *)(iVar11 + 1);
      *(undefined *)(iVar10 + 2) = *(undefined *)(iVar11 + 2);
      *(undefined *)(iVar10 + 3) = *(undefined *)(iVar11 + 3);
      pbVar7 = pbVar7 + -1;
    } while (iVar6 != 0);
  }
  iVar8 = (uint)*(byte *)(param_2 + iVar8) * 4;
  iVar6 = iVar12 + iVar8;
  *(undefined *)(iVar8 + iVar12) = uVar5;
  *(undefined *)(iVar6 + 1) = uVar1;
  *(undefined *)(iVar6 + 2) = uVar2;
  *(undefined *)(iVar6 + 3) = uVar3;
  *(byte *)(param_1 + 0xc) = *(byte *)(param_1 + 0xc) | 2;
  return;
}

