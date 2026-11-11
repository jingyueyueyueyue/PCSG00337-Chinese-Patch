
void FUN_81076290(int param_1)

{
  int iVar1;
  uint uVar2;
  
  func_0x81084da4();
  func_0x81084d28(param_1);
  uVar2 = *(uint *)(param_1 + 0x50);
  if (0x1f < uVar2) {
    func_0x811184c0(&UNK_8113ad00);
  }
  iVar1 = (uVar2 >> 4) * 2;
  *(ushort *)(iVar1 + -0x7ee6ede8) =
       *(ushort *)(iVar1 + -0x7ee6ede8) & ~(ushort)(1 << (uVar2 & 0xf));
  return;
}

