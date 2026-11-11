
int FUN_8107d882(int param_1)

{
  int *piVar1;
  short *psVar2;
  short *psVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  
  piVar1 = (int *)func_0x8107d5fc();
  (**(code **)(*piVar1 + 8))();
  psVar2 = *(short **)(param_1 + 0x38);
  iVar4 = 0;
  uVar6 = 0;
  *(undefined4 *)(param_1 + 0x14) = 0;
  psVar3 = psVar2 + *(ushort *)(param_1 + 0x54);
  *(undefined4 *)(param_1 + 0x20) = 0;
  for (; psVar2 != psVar3; psVar2 = psVar2 + uVar7 + 1) {
    iVar4 = iVar4 + 1;
    *(int *)(param_1 + 0x20) = iVar4;
    uVar7 = (uint)((int)*psVar2 << 0x10) >> 0x11;
    if ((((int)*psVar2 & 1U) != 0) && (uVar5 = uVar7 + 1, uVar6 < uVar5)) {
      *(uint *)(param_1 + 0x14) = uVar5;
      uVar7 = (uint)((int)*psVar2 << 0x10) >> 0x11;
      uVar6 = uVar5;
    }
  }
  *(uint *)(param_1 + 0x14) = uVar6 * *(int *)(param_1 + 0x48);
  (**(code **)(*piVar1 + 0xc))(piVar1);
  return param_1 + 8;
}

