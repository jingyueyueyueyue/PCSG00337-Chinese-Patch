
int FUN_8108b46c(int param_1,uint param_2,int param_3)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  if (param_2 < *(byte *)(param_1 + (uint)*(byte *)(param_1 + 0x38f) + 0x38d)) {
    iVar2 = param_1 + (uint)*(byte *)(param_1 + 0x38f) * 0x1c0 + param_2 * 0x1c + 0xd;
  }
  iVar1 = 0;
  if (iVar2 != 0) {
    iVar1 = iVar2 + param_3 * 2 + 0x18;
  }
  return iVar1;
}

