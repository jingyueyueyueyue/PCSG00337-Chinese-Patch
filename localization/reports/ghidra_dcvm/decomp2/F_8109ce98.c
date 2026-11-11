
void FUN_8109ce98(int param_1,uint param_2)

{
  if ((param_2 != 0) && (param_2 <= *(uint *)(param_1 + 0x4c))) {
    *(byte *)(*(int *)(param_1 + 0x50) + (param_2 >> 3)) =
         *(byte *)(*(int *)(param_1 + 0x50) + (param_2 >> 3)) & ~(byte)(1 << (param_2 & 7));
  }
  return;
}

