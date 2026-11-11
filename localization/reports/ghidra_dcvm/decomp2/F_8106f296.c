
bool FUN_8106f296(int param_1,char param_2)

{
  bool bVar1;
  
  bVar1 = (uint)((int)(char)*(byte *)(param_1 + 0x42) << 0x1c) >> 0x1f != (uint)(param_2 != '\0');
  if (bVar1) {
    *(byte *)(param_1 + 0x42) = *(byte *)(param_1 + 0x42) & 0xf7 | (param_2 != '\0') << 3;
    *(byte *)(param_1 + 0x44) = *(byte *)(param_1 + 0x44) | 8;
  }
  return bVar1;
}

