
bool FUN_8106f2cc(int param_1,char param_2)

{
  bool bVar1;
  
  bVar1 = (uint)((int)(char)*(byte *)(param_1 + 0x42) << 0x1b) >> 0x1f != (uint)(param_2 != '\0');
  if (bVar1) {
    *(byte *)(param_1 + 0x42) = *(byte *)(param_1 + 0x42) & 0xef | (param_2 != '\0') << 4;
    *(byte *)(param_1 + 0x44) = *(byte *)(param_1 + 0x44) | 8;
  }
  return bVar1;
}

