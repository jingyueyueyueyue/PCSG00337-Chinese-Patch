
undefined4 FUN_8106f1de(int *param_1,char param_2)

{
  undefined4 uVar1;
  byte bVar2;
  uint uVar3;
  
  bVar2 = *(byte *)((int)param_1 + 0x42);
  uVar3 = (uint)(char)bVar2;
  uVar1 = 0;
  if ((uVar3 << 0x1d) >> 0x1f != (uint)(param_2 != '\0')) {
    if (param_2 == '\0') {
      if ((uVar3 & 8) != 0) {
        (**(code **)(*param_1 + 0x1c))(param_1,0);
        uVar3 = (uint)*(char *)((int)param_1 + 0x42);
      }
      bVar2 = (byte)uVar3;
      if ((uVar3 & 0x10) != 0) {
        (**(code **)(*param_1 + 0x20))(param_1,0);
        bVar2 = *(byte *)((int)param_1 + 0x42);
      }
    }
    *(byte *)((int)param_1 + 0x42) = bVar2 & 0xfb | (param_2 != '\0') << 2;
    *(byte *)(param_1 + 0x11) = *(byte *)(param_1 + 0x11) | 8;
    uVar1 = 1;
  }
  return uVar1;
}

