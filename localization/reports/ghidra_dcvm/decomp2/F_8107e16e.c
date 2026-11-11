
int FUN_8107e16e(int param_1)

{
  int iVar1;
  uint uVar2;
  byte *pbVar3;
  
  iVar1 = 0;
  uVar2 = 0;
  for (pbVar3 = (byte *)(param_1 + 0x10); pbVar3 != (byte *)(param_1 + *(int *)(param_1 + 0xc));
      pbVar3 = pbVar3 + 1) {
    iVar1 = iVar1 + (uint)*pbVar3 + uVar2;
    uVar2 = uVar2 + 1 & 0xff;
  }
  return iVar1;
}

