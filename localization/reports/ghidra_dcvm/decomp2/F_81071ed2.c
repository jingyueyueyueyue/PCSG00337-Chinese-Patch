
bool FUN_81071ed2(int param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint in_fpscr;
  undefined4 uVar4;
  float fVar5;
  undefined4 uVar6;
  
  uVar2 = *(uint *)(param_1 + 0x14);
  uVar3 = *(int *)(param_1 + 0x10) + param_2;
  *(uint *)(param_1 + 0x10) = uVar3;
  uVar6 = VectorUnsignedToFloat(uVar2,(byte)(in_fpscr >> 0x15) & 3);
  if (uVar2 <= uVar3) {
    *(uint *)(param_1 + 0x10) = uVar2;
    uVar3 = uVar2;
  }
  uVar4 = VectorUnsignedToFloat(uVar3,(byte)(in_fpscr >> 0x15) & 3);
  iVar1 = param_1 + 0x1c;
  if (0xf < *(uint *)(param_1 + 0x30)) {
    iVar1 = *(int *)(param_1 + 0x1c);
  }
  fVar5 = (float)func_0x810dd248(uVar4,uVar6,iVar1,param_1 + 0x34,param_1 + 0x38);
  uVar6 = *(undefined4 *)(param_1 + 0x10);
  *(int *)(*(int *)(param_1 + 0xc) + 0x34) = (int)fVar5;
  uVar6 = VectorUnsignedToFloat(uVar6,(byte)(in_fpscr >> 0x15) & 3);
  iVar1 = param_1 + 0x40;
  uVar4 = VectorUnsignedToFloat(*(undefined4 *)(param_1 + 0x14),(byte)(in_fpscr >> 0x15) & 3);
  if (0xf < *(uint *)(param_1 + 0x54)) {
    iVar1 = *(int *)(param_1 + 0x40);
  }
  fVar5 = (float)func_0x810dd248(uVar6,uVar4,iVar1,param_1 + 0x58,param_1 + 0x5c);
  *(int *)(*(int *)(param_1 + 0xc) + 0x38) = (int)fVar5;
  return uVar3 == uVar2;
}

