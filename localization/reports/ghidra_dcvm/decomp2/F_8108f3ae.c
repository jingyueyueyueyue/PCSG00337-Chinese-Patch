
undefined4 FUN_8108f3ae(uint param_1)

{
  undefined4 uVar1;
  
  if (cRam81191490 == '\0') {
    uVar1 = 0;
  }
  else {
    if (0x7f < param_1) {
      func_0x811184c0(&UNK_81138fa8);
    }
    uVar1 = 0;
    if (((uint)*(ushort *)((param_1 >> 4) * 2 + -0x7ee6eb6e) & 1 << (param_1 & 0xf)) != 0) {
      uVar1 = 1;
    }
  }
  return uVar1;
}

