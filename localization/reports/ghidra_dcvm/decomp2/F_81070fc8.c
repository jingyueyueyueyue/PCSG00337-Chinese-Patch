
void FUN_81070fc8(int param_1)

{
  ushort uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  
  iVar3 = *(int *)(param_1 + 0xc);
  uVar1 = *(ushort *)(param_1 + 0x16);
  while (uVar2 = (uint)uVar1, uVar2 != 0xffff) {
    iVar4 = iVar3 + uVar2 * 8;
    *(byte *)(iVar4 + 2) = *(byte *)(iVar4 + 2) & 0x9f | 0x20;
    uVar1 = *(ushort *)(iVar3 + uVar2 * 8);
  }
  return;
}

