
bool FUN_81071c58(int param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint in_fpscr;
  undefined4 uVar4;
  undefined4 uVar5;
  
  uVar3 = *(int *)(param_1 + 0x10) + param_2;
  uVar2 = *(uint *)(param_1 + 0x14);
  *(uint *)(param_1 + 0x10) = uVar3;
  if (uVar2 <= uVar3) {
    *(uint *)(param_1 + 0x10) = uVar2;
    uVar3 = uVar2;
  }
  iVar1 = param_1 + 0x1c;
  if (0xf < *(uint *)(param_1 + 0x30)) {
    iVar1 = *(int *)(param_1 + 0x1c);
  }
  uVar4 = VectorUnsignedToFloat(uVar3,(byte)(in_fpscr >> 0x15) & 3);
  uVar5 = VectorUnsignedToFloat(uVar2,(byte)(in_fpscr >> 0x15) & 3);
  uVar4 = func_0x810dd248(uVar4,uVar5,iVar1,param_1 + 0x34,param_1 + 0x38);
  *(undefined4 *)(*(int *)(param_1 + 0xc) + 0x44) = uVar4;
  return uVar3 == uVar2;
}

