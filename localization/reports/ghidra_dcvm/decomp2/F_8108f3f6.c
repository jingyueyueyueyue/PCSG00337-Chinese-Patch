
void FUN_8108f3f6(uint param_1)

{
  int iVar1;
  
  if (cRam81191490 != '\0') {
    if (0x7f < param_1) {
      func_0x811184c0(&UNK_81138fa8);
    }
    if ((((uint)*(ushort *)((param_1 >> 4) * 2 + -0x7ee6eb6e) & 1 << (param_1 & 0xf)) == 0) &&
       (iVar1 = func_0x810a6a02(param_1,1), -1 < iVar1)) {
      iVar1 = (param_1 >> 4) * 2;
      if (0x7f < param_1) {
        func_0x811184c0(&UNK_81138fa8);
      }
      *(ushort *)(iVar1 + -0x7ee6eb6e) =
           *(ushort *)(iVar1 + -0x7ee6eb6e) | (ushort)(1 << (param_1 & 0xf));
    }
  }
  return;
}

